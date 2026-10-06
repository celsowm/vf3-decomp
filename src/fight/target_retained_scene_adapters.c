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
int vf3_target_retained_scene_adapter(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c042fa0u: goto P_0c042fa0;
case 0x0c042fa2u: goto P_0c042fa2;
case 0x0c042fa4u: goto P_0c042fa4;
case 0x0c042fa6u: goto P_0c042fa6;
case 0x0c042fa8u: goto P_0c042fa8;
case 0x0c042faau: goto P_0c042faa;
case 0x0c042facu: goto P_0c042fac;
case 0x0c042faeu: goto P_0c042fae;
case 0x0c042fb0u: goto P_0c042fb0;
case 0x0c042fb2u: goto P_0c042fb2;
case 0x0c042fb4u: goto P_0c042fb4;
case 0x0c042fb6u: goto P_0c042fb6;
case 0x0c042fb8u: goto P_0c042fb8;
case 0x0c042fbau: goto P_0c042fba;
case 0x0c042fbcu: goto P_0c042fbc;
case 0x0c042fbeu: goto P_0c042fbe;
case 0x0c042fc0u: goto P_0c042fc0;
case 0x0c042fc2u: goto P_0c042fc2;
case 0x0c042fc4u: goto P_0c042fc4;
case 0x0c042fc6u: goto P_0c042fc6;
case 0x0c042fc8u: goto P_0c042fc8;
case 0x0c042fcau: goto P_0c042fca;
case 0x0c042fccu: goto P_0c042fcc;
case 0x0c042fceu: goto P_0c042fce;
case 0x0c042fd0u: goto P_0c042fd0;
case 0x0c042fd2u: goto P_0c042fd2;
case 0x0c042fd4u: goto P_0c042fd4;
case 0x0c042fd6u: goto P_0c042fd6;
case 0x0c042fd8u: goto P_0c042fd8;
case 0x0c06233eu: goto P_0c06233e;
case 0x0c062340u: goto P_0c062340;
case 0x0c062342u: goto P_0c062342;
case 0x0c062344u: goto P_0c062344;
case 0x0c062346u: goto P_0c062346;
case 0x0c062348u: goto P_0c062348;
case 0x0c06234au: goto P_0c06234a;
case 0x0c06234cu: goto P_0c06234c;
case 0x0c06234eu: goto P_0c06234e;
case 0x0c062350u: goto P_0c062350;
case 0x0c062352u: goto P_0c062352;
case 0x0c062354u: goto P_0c062354;
case 0x0c062356u: goto P_0c062356;
case 0x0c062358u: goto P_0c062358;
case 0x0c06235au: goto P_0c06235a;
case 0x0c06235cu: goto P_0c06235c;
case 0x0c06235eu: goto P_0c06235e;
case 0x0c062360u: goto P_0c062360;
case 0x0c062362u: goto P_0c062362;
case 0x0c062364u: goto P_0c062364;
case 0x0c062366u: goto P_0c062366;
case 0x0c062368u: goto P_0c062368;
case 0x0c06236au: goto P_0c06236a;
case 0x0c06236cu: goto P_0c06236c;
case 0x0c06236eu: goto P_0c06236e;
case 0x0c062370u: goto P_0c062370;
case 0x0c062372u: goto P_0c062372;
case 0x0c062374u: goto P_0c062374;
case 0x0c062376u: goto P_0c062376;
case 0x0c062378u: goto P_0c062378;
case 0x0c06237au: goto P_0c06237a;
case 0x0c07ac28u: goto P_0c07ac28;
case 0x0c07ac2au: goto P_0c07ac2a;
case 0x0c07ac2cu: goto P_0c07ac2c;
case 0x0c07ac2eu: goto P_0c07ac2e;
case 0x0c07ac30u: goto P_0c07ac30;
case 0x0c07ac32u: goto P_0c07ac32;
case 0x0c07ac34u: goto P_0c07ac34;
case 0x0c07ac36u: goto P_0c07ac36;
case 0x0c07ac38u: goto P_0c07ac38;
case 0x0c07ac3au: goto P_0c07ac3a;
case 0x0c07ac3cu: goto P_0c07ac3c;
case 0x0c07ac3eu: goto P_0c07ac3e;
case 0x0c07ac40u: goto P_0c07ac40;
case 0x0c07ac42u: goto P_0c07ac42;
case 0x0c07ac44u: goto P_0c07ac44;
case 0x0c07ac46u: goto P_0c07ac46;
case 0x0c07ac48u: goto P_0c07ac48;
case 0x0c07ac4au: goto P_0c07ac4a;
case 0x0c07ac4cu: goto P_0c07ac4c;
case 0x0c07ac4eu: goto P_0c07ac4e;
case 0x0c07ac50u: goto P_0c07ac50;
case 0x0c07ac52u: goto P_0c07ac52;
case 0x0c07ac54u: goto P_0c07ac54;
case 0x0c07ac56u: goto P_0c07ac56;
case 0x0c07ac58u: goto P_0c07ac58;
case 0x0c07ac5au: goto P_0c07ac5a;
case 0x0c07ac5cu: goto P_0c07ac5c;
case 0x0c07ac5eu: goto P_0c07ac5e;
case 0x0c07ac60u: goto P_0c07ac60;
case 0x0c07ac62u: goto P_0c07ac62;
case 0x0c07ac64u: goto P_0c07ac64;
case 0x0c07ac66u: goto P_0c07ac66;
case 0x0c07ac68u: goto P_0c07ac68;
case 0x0c07ac6eu: goto P_0c07ac6e;
case 0x0c07ac70u: goto P_0c07ac70;
case 0x0c07ac72u: goto P_0c07ac72;
case 0x0c07ac74u: goto P_0c07ac74;
case 0x0c07ac76u: goto P_0c07ac76;
case 0x0c07ac78u: goto P_0c07ac78;
case 0x0c07ac7au: goto P_0c07ac7a;
case 0x0c07ac7cu: goto P_0c07ac7c;
case 0x0c07ac7eu: goto P_0c07ac7e;
case 0x0c07ac80u: goto P_0c07ac80;
case 0x0c07ac82u: goto P_0c07ac82;
case 0x0c07ac84u: goto P_0c07ac84;
case 0x0c07ac86u: goto P_0c07ac86;
case 0x0c07ac88u: goto P_0c07ac88;
case 0x0c07ac8au: goto P_0c07ac8a;
case 0x0c07ac8cu: goto P_0c07ac8c;
case 0x0c07ac8eu: goto P_0c07ac8e;
case 0x0c07ac90u: goto P_0c07ac90;
case 0x0c07ac92u: goto P_0c07ac92;
case 0x0c07ad12u: goto P_0c07ad12;
case 0x0c07ad14u: goto P_0c07ad14;
case 0x0c07ad16u: goto P_0c07ad16;
case 0x0c07ad18u: goto P_0c07ad18;
case 0x0c07ad1au: goto P_0c07ad1a;
case 0x0c07ad1cu: goto P_0c07ad1c;
case 0x0c07ad1eu: goto P_0c07ad1e;
case 0x0c07ad20u: goto P_0c07ad20;
case 0x0c07ad22u: goto P_0c07ad22;
case 0x0c07ad24u: goto P_0c07ad24;
case 0x0c07ad26u: goto P_0c07ad26;
case 0x0c07ad28u: goto P_0c07ad28;
case 0x0c07ad2au: goto P_0c07ad2a;
case 0x0c07ad2cu: goto P_0c07ad2c;
case 0x0c07ad2eu: goto P_0c07ad2e;
case 0x0c07ad30u: goto P_0c07ad30;
case 0x0c07ad32u: goto P_0c07ad32;
case 0x0c07ad34u: goto P_0c07ad34;
case 0x0c07ad36u: goto P_0c07ad36;
case 0x0c07ad38u: goto P_0c07ad38;
case 0x0c07ad3au: goto P_0c07ad3a;
case 0x0c07ad3cu: goto P_0c07ad3c;
case 0x0c07ad3eu: goto P_0c07ad3e;
case 0x0c07ad40u: goto P_0c07ad40;
case 0x0c07ad42u: goto P_0c07ad42;
case 0x0c07ad44u: goto P_0c07ad44;
case 0x0c07ad46u: goto P_0c07ad46;
case 0x0c07ad48u: goto P_0c07ad48;
case 0x0c07ad4au: goto P_0c07ad4a;
case 0x0c07ad4cu: goto P_0c07ad4c;
case 0x0c07ad4eu: goto P_0c07ad4e;
case 0x0c07ad50u: goto P_0c07ad50;
case 0x0c07ad52u: goto P_0c07ad52;
case 0x0c07ad54u: goto P_0c07ad54;
case 0x0c07ad56u: goto P_0c07ad56;
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
case 0x0c07c874u: goto P_0c07c874;
case 0x0c07c876u: goto P_0c07c876;
case 0x0c07c878u: goto P_0c07c878;
case 0x0c07c87au: goto P_0c07c87a;
case 0x0c07c87cu: goto P_0c07c87c;
case 0x0c07c96au: goto P_0c07c96a;
case 0x0c07c96cu: goto P_0c07c96c;
case 0x0c07c96eu: goto P_0c07c96e;
case 0x0c07c970u: goto P_0c07c970;
case 0x0c07c972u: goto P_0c07c972;
case 0x0c07c974u: goto P_0c07c974;
case 0x0c07c976u: goto P_0c07c976;
case 0x0c07c978u: goto P_0c07c978;
case 0x0c07c97au: goto P_0c07c97a;
case 0x0c07c97cu: goto P_0c07c97c;
case 0x0c07c97eu: goto P_0c07c97e;
case 0x0c07c980u: goto P_0c07c980;
case 0x0c07c982u: goto P_0c07c982;
case 0x0c07c984u: goto P_0c07c984;
case 0x0c07c986u: goto P_0c07c986;
case 0x0c07c988u: goto P_0c07c988;
case 0x0c07c98au: goto P_0c07c98a;
case 0x0c07c98cu: goto P_0c07c98c;
case 0x0c07c98eu: goto P_0c07c98e;
case 0x0c07c990u: goto P_0c07c990;
case 0x0c07c992u: goto P_0c07c992;
case 0x0c07c994u: goto P_0c07c994;
case 0x0c07c996u: goto P_0c07c996;
case 0x0c07c998u: goto P_0c07c998;
case 0x0c07c9d4u: goto P_0c07c9d4;
case 0x0c07c9d6u: goto P_0c07c9d6;
case 0x0c07c9d8u: goto P_0c07c9d8;
case 0x0c07c9dau: goto P_0c07c9da;
case 0x0c07c9dcu: goto P_0c07c9dc;
case 0x0c07c9deu: goto P_0c07c9de;
case 0x0c07c9e0u: goto P_0c07c9e0;
case 0x0c07c9e2u: goto P_0c07c9e2;
case 0x0c07c9e4u: goto P_0c07c9e4;
case 0x0c07e866u: goto P_0c07e866;
case 0x0c07e868u: goto P_0c07e868;
case 0x0c07e86au: goto P_0c07e86a;
case 0x0c07e86cu: goto P_0c07e86c;
case 0x0c07e86eu: goto P_0c07e86e;
case 0x0c07e870u: goto P_0c07e870;
case 0x0c07e872u: goto P_0c07e872;
case 0x0c07e874u: goto P_0c07e874;
case 0x0c07e876u: goto P_0c07e876;
case 0x0c07e878u: goto P_0c07e878;
case 0x0c07e87au: goto P_0c07e87a;
case 0x0c07e87cu: goto P_0c07e87c;
case 0x0c07e87eu: goto P_0c07e87e;
case 0x0c07e880u: goto P_0c07e880;
case 0x0c07e882u: goto P_0c07e882;
case 0x0c07e884u: goto P_0c07e884;
case 0x0c07e886u: goto P_0c07e886;
case 0x0c07e888u: goto P_0c07e888;
case 0x0c07e88au: goto P_0c07e88a;
case 0x0c07e88cu: goto P_0c07e88c;
case 0x0c07e88eu: goto P_0c07e88e;
case 0x0c07e890u: goto P_0c07e890;
case 0x0c07e892u: goto P_0c07e892;
case 0x0c07e894u: goto P_0c07e894;
case 0x0c07e896u: goto P_0c07e896;
case 0x0c07e898u: goto P_0c07e898;
case 0x0c07e89au: goto P_0c07e89a;
case 0x0c07e89cu: goto P_0c07e89c;
case 0x0c07e89eu: goto P_0c07e89e;
case 0x0c07e8a0u: goto P_0c07e8a0;
case 0x0c07e8a2u: goto P_0c07e8a2;
case 0x0c07e8a4u: goto P_0c07e8a4;
case 0x0c07e8e6u: goto P_0c07e8e6;
case 0x0c07e8e8u: goto P_0c07e8e8;
case 0x0c07e8eau: goto P_0c07e8ea;
case 0x0c07e8ecu: goto P_0c07e8ec;
case 0x0c07e8eeu: goto P_0c07e8ee;
case 0x0c07e8f0u: goto P_0c07e8f0;
case 0x0c07e8f2u: goto P_0c07e8f2;
case 0x0c07e8f4u: goto P_0c07e8f4;
case 0x0c07e8f6u: goto P_0c07e8f6;
case 0x0c07e8f8u: goto P_0c07e8f8;
case 0x0c07e8fau: goto P_0c07e8fa;
case 0x0c07e8fcu: goto P_0c07e8fc;
case 0x0c07e8feu: goto P_0c07e8fe;
case 0x0c07e900u: goto P_0c07e900;
case 0x0c07e902u: goto P_0c07e902;
case 0x0c07e904u: goto P_0c07e904;
case 0x0c07e906u: goto P_0c07e906;
case 0x0c07e908u: goto P_0c07e908;
case 0x0c07e90au: goto P_0c07e90a;
case 0x0c07e90cu: goto P_0c07e90c;
case 0x0c07e90eu: goto P_0c07e90e;
case 0x0c07f722u: goto P_0c07f722;
case 0x0c07f724u: goto P_0c07f724;
case 0x0c07f726u: goto P_0c07f726;
case 0x0c07f728u: goto P_0c07f728;
case 0x0c07f72au: goto P_0c07f72a;
case 0x0c07f72cu: goto P_0c07f72c;
case 0x0c07f72eu: goto P_0c07f72e;
case 0x0c07f730u: goto P_0c07f730;
case 0x0c07f732u: goto P_0c07f732;
case 0x0c07f734u: goto P_0c07f734;
case 0x0c07f736u: goto P_0c07f736;
case 0x0c07f738u: goto P_0c07f738;
case 0x0c07f73au: goto P_0c07f73a;
case 0x0c07f73cu: goto P_0c07f73c;
case 0x0c07f73eu: goto P_0c07f73e;
case 0x0c07f740u: goto P_0c07f740;
case 0x0c07f742u: goto P_0c07f742;
case 0x0c07f744u: goto P_0c07f744;
case 0x0c07f746u: goto P_0c07f746;
case 0x0c07f748u: goto P_0c07f748;
case 0x0c07f74au: goto P_0c07f74a;
case 0x0c07f74cu: goto P_0c07f74c;
case 0x0c07f74eu: goto P_0c07f74e;
case 0x0c07f750u: goto P_0c07f750;
case 0x0c07f752u: goto P_0c07f752;
case 0x0c07f754u: goto P_0c07f754;
case 0x0c07f756u: goto P_0c07f756;
case 0x0c07f758u: goto P_0c07f758;
case 0x0c07f75au: goto P_0c07f75a;
case 0x0c07f75cu: goto P_0c07f75c;
case 0x0c07f75eu: goto P_0c07f75e;
case 0x0c07f760u: goto P_0c07f760;
case 0x0c07f762u: goto P_0c07f762;
case 0x0c07f764u: goto P_0c07f764;
case 0x0c07f766u: goto P_0c07f766;
case 0x0c07f768u: goto P_0c07f768;
case 0x0c07f76au: goto P_0c07f76a;
case 0x0c07f76cu: goto P_0c07f76c;
case 0x0c07f76eu: goto P_0c07f76e;
case 0x0c07f770u: goto P_0c07f770;
case 0x0c07f772u: goto P_0c07f772;
case 0x0c07f774u: goto P_0c07f774;
case 0x0c07f776u: goto P_0c07f776;
case 0x0c07f778u: goto P_0c07f778;
case 0x0c07f77au: goto P_0c07f77a;
case 0x0c07f77cu: goto P_0c07f77c;
case 0x0c07f77eu: goto P_0c07f77e;
case 0x0c07f780u: goto P_0c07f780;
case 0x0c07f782u: goto P_0c07f782;
case 0x0c07f784u: goto P_0c07f784;
case 0x0c07f786u: goto P_0c07f786;
case 0x0c07f788u: goto P_0c07f788;
case 0x0c07f78au: goto P_0c07f78a;
case 0x0c07f78cu: goto P_0c07f78c;
case 0x0c07f78eu: goto P_0c07f78e;
case 0x0c07f790u: goto P_0c07f790;
case 0x0c07f792u: goto P_0c07f792;
case 0x0c07f794u: goto P_0c07f794;
case 0x0c07f796u: goto P_0c07f796;
case 0x0c07f798u: goto P_0c07f798;
case 0x0c07f79au: goto P_0c07f79a;
case 0x0c07f79cu: goto P_0c07f79c;
case 0x0c07f79eu: goto P_0c07f79e;
case 0x0c07f7a0u: goto P_0c07f7a0;
case 0x0c07f7a2u: goto P_0c07f7a2;
case 0x0c07f7a4u: goto P_0c07f7a4;
case 0x0c07f7a6u: goto P_0c07f7a6;
case 0x0c07f7a8u: goto P_0c07f7a8;
case 0x0c07f7aau: goto P_0c07f7aa;
case 0x0c07f7acu: goto P_0c07f7ac;
case 0x0c07f7aeu: goto P_0c07f7ae;
case 0x0c07f7b0u: goto P_0c07f7b0;
case 0x0c07f7b2u: goto P_0c07f7b2;
case 0x0c07f7b4u: goto P_0c07f7b4;
case 0x0c07f7b6u: goto P_0c07f7b6;
case 0x0c07f7b8u: goto P_0c07f7b8;
case 0x0c07f7bau: goto P_0c07f7ba;
case 0x0c07f7bcu: goto P_0c07f7bc;
case 0x0c07f7beu: goto P_0c07f7be;
case 0x0c07f7c0u: goto P_0c07f7c0;
case 0x0c07f7c2u: goto P_0c07f7c2;
case 0x0c07f7c4u: goto P_0c07f7c4;
case 0x0c07f7c6u: goto P_0c07f7c6;
case 0x0c07f7c8u: goto P_0c07f7c8;
case 0x0c07f7cau: goto P_0c07f7ca;
case 0x0c07f7ccu: goto P_0c07f7cc;
case 0x0c07f7ceu: goto P_0c07f7ce;
case 0x0c07f7d0u: goto P_0c07f7d0;
case 0x0c07f7d2u: goto P_0c07f7d2;
case 0x0c07f7d4u: goto P_0c07f7d4;
case 0x0c07f7d6u: goto P_0c07f7d6;
case 0x0c07f7d8u: goto P_0c07f7d8;
case 0x0c07f7dau: goto P_0c07f7da;
case 0x0c07f7dcu: goto P_0c07f7dc;
case 0x0c07f7deu: goto P_0c07f7de;
case 0x0c07f7e0u: goto P_0c07f7e0;
case 0x0c07f7e2u: goto P_0c07f7e2;
case 0x0c07f7e4u: goto P_0c07f7e4;
case 0x0c07f7e6u: goto P_0c07f7e6;
case 0x0c07f7e8u: goto P_0c07f7e8;
case 0x0c07f7eau: goto P_0c07f7ea;
case 0x0c07f7ecu: goto P_0c07f7ec;
case 0x0c07f7eeu: goto P_0c07f7ee;
case 0x0c07f7f0u: goto P_0c07f7f0;
case 0x0c07f7f2u: goto P_0c07f7f2;
case 0x0c07f7f4u: goto P_0c07f7f4;
case 0x0c07f7f6u: goto P_0c07f7f6;
case 0x0c07f7f8u: goto P_0c07f7f8;
case 0x0c07f7fau: goto P_0c07f7fa;
case 0x0c07f7fcu: goto P_0c07f7fc;
case 0x0c07f7feu: goto P_0c07f7fe;
case 0x0c07f800u: goto P_0c07f800;
case 0x0c07f802u: goto P_0c07f802;
case 0x0c07f804u: goto P_0c07f804;
case 0x0c07f806u: goto P_0c07f806;
case 0x0c07f808u: goto P_0c07f808;
case 0x0c07f80au: goto P_0c07f80a;
case 0x0c07f80cu: goto P_0c07f80c;
case 0x0c07f80eu: goto P_0c07f80e;
case 0x0c07f810u: goto P_0c07f810;
case 0x0c07f812u: goto P_0c07f812;
case 0x0c07f814u: goto P_0c07f814;
case 0x0c07f816u: goto P_0c07f816;
case 0x0c07f818u: goto P_0c07f818;
case 0x0c07f81au: goto P_0c07f81a;
case 0x0c07f81cu: goto P_0c07f81c;
case 0x0c07f81eu: goto P_0c07f81e;
case 0x0c07f820u: goto P_0c07f820;
case 0x0c07f822u: goto P_0c07f822;
case 0x0c07f824u: goto P_0c07f824;
case 0x0c07f826u: goto P_0c07f826;
case 0x0c07f828u: goto P_0c07f828;
case 0x0c07f82au: goto P_0c07f82a;
case 0x0c07f82cu: goto P_0c07f82c;
case 0x0c07f82eu: goto P_0c07f82e;
case 0x0c07f830u: goto P_0c07f830;
case 0x0c07f832u: goto P_0c07f832;
case 0x0c07f834u: goto P_0c07f834;
case 0x0c07f836u: goto P_0c07f836;
case 0x0c07f864u: goto P_0c07f864;
case 0x0c07f866u: goto P_0c07f866;
case 0x0c07f868u: goto P_0c07f868;
case 0x0c07f86au: goto P_0c07f86a;
case 0x0c07f86cu: goto P_0c07f86c;
case 0x0c07f86eu: goto P_0c07f86e;
case 0x0c07f870u: goto P_0c07f870;
case 0x0c07f872u: goto P_0c07f872;
case 0x0c07f874u: goto P_0c07f874;
case 0x0c07f876u: goto P_0c07f876;
case 0x0c07f878u: goto P_0c07f878;
case 0x0c07f87au: goto P_0c07f87a;
case 0x0c07f87cu: goto P_0c07f87c;
case 0x0c07f87eu: goto P_0c07f87e;
case 0x0c07f880u: goto P_0c07f880;
case 0x0c07f882u: goto P_0c07f882;
case 0x0c07f884u: goto P_0c07f884;
case 0x0c07f886u: goto P_0c07f886;
case 0x0c07f888u: goto P_0c07f888;
case 0x0c07f88au: goto P_0c07f88a;
case 0x0c07f88cu: goto P_0c07f88c;
case 0x0c07f88eu: goto P_0c07f88e;
case 0x0c07f890u: goto P_0c07f890;
case 0x0c07f892u: goto P_0c07f892;
case 0x0c07f894u: goto P_0c07f894;
case 0x0c07f896u: goto P_0c07f896;
case 0x0c07f898u: goto P_0c07f898;
case 0x0c07f89au: goto P_0c07f89a;
case 0x0c07f89cu: goto P_0c07f89c;
case 0x0c07f89eu: goto P_0c07f89e;
case 0x0c07f8a0u: goto P_0c07f8a0;
case 0x0c07f8a2u: goto P_0c07f8a2;
case 0x0c07f8a4u: goto P_0c07f8a4;
case 0x0c07f8a6u: goto P_0c07f8a6;
case 0x0c07f8a8u: goto P_0c07f8a8;
case 0x0c07f8aau: goto P_0c07f8aa;
case 0x0c07f8acu: goto P_0c07f8ac;
case 0x0c07f8aeu: goto P_0c07f8ae;
case 0x0c07f8b0u: goto P_0c07f8b0;
case 0x0c07f8b2u: goto P_0c07f8b2;
case 0x0c07f8b4u: goto P_0c07f8b4;
case 0x0c07f8b6u: goto P_0c07f8b6;
case 0x0c07f8b8u: goto P_0c07f8b8;
case 0x0c07f8bau: goto P_0c07f8ba;
case 0x0c07f8bcu: goto P_0c07f8bc;
case 0x0c07f8beu: goto P_0c07f8be;
case 0x0c07f8c0u: goto P_0c07f8c0;
case 0x0c07f8c2u: goto P_0c07f8c2;
case 0x0c07f8c4u: goto P_0c07f8c4;
case 0x0c07f8c6u: goto P_0c07f8c6;
case 0x0c07f8c8u: goto P_0c07f8c8;
case 0x0c07f8cau: goto P_0c07f8ca;
case 0x0c07f8ccu: goto P_0c07f8cc;
case 0x0c07f8ceu: goto P_0c07f8ce;
case 0x0c07f8d0u: goto P_0c07f8d0;
case 0x0c07f8d2u: goto P_0c07f8d2;
case 0x0c07f8d4u: goto P_0c07f8d4;
case 0x0c07f8d6u: goto P_0c07f8d6;
case 0x0c07f8d8u: goto P_0c07f8d8;
case 0x0c07f8dau: goto P_0c07f8da;
case 0x0c07f8dcu: goto P_0c07f8dc;
case 0x0c07f8deu: goto P_0c07f8de;
case 0x0c07f8e0u: goto P_0c07f8e0;
case 0x0c07f8e2u: goto P_0c07f8e2;
case 0x0c07f8e4u: goto P_0c07f8e4;
case 0x0c07f8e6u: goto P_0c07f8e6;
case 0x0c07f8e8u: goto P_0c07f8e8;
case 0x0c07f8eau: goto P_0c07f8ea;
case 0x0c07f8ecu: goto P_0c07f8ec;
case 0x0c07f8eeu: goto P_0c07f8ee;
case 0x0c07f8f0u: goto P_0c07f8f0;
case 0x0c07f8f2u: goto P_0c07f8f2;
case 0x0c07f8f4u: goto P_0c07f8f4;
case 0x0c07f8f6u: goto P_0c07f8f6;
case 0x0c07f8f8u: goto P_0c07f8f8;
case 0x0c07f8fau: goto P_0c07f8fa;
case 0x0c07f8fcu: goto P_0c07f8fc;
case 0x0c07f8feu: goto P_0c07f8fe;
case 0x0c07f900u: goto P_0c07f900;
case 0x0c07f902u: goto P_0c07f902;
case 0x0c07f904u: goto P_0c07f904;
case 0x0c07f906u: goto P_0c07f906;
case 0x0c07f908u: goto P_0c07f908;
case 0x0c07f90au: goto P_0c07f90a;
case 0x0c07f90cu: goto P_0c07f90c;
case 0x0c07f90eu: goto P_0c07f90e;
case 0x0c07f910u: goto P_0c07f910;
case 0x0c07f912u: goto P_0c07f912;
case 0x0c07f914u: goto P_0c07f914;
case 0x0c07f916u: goto P_0c07f916;
case 0x0c07f918u: goto P_0c07f918;
case 0x0c07f91au: goto P_0c07f91a;
case 0x0c07f91cu: goto P_0c07f91c;
case 0x0c07f91eu: goto P_0c07f91e;
case 0x0c07f920u: goto P_0c07f920;
case 0x0c07f922u: goto P_0c07f922;
case 0x0c07f924u: goto P_0c07f924;
case 0x0c07f926u: goto P_0c07f926;
case 0x0c07f928u: goto P_0c07f928;
case 0x0c07f92au: goto P_0c07f92a;
case 0x0c07f92cu: goto P_0c07f92c;
case 0x0c07f92eu: goto P_0c07f92e;
case 0x0c07f930u: goto P_0c07f930;
case 0x0c07f932u: goto P_0c07f932;
case 0x0c07f934u: goto P_0c07f934;
case 0x0c07f936u: goto P_0c07f936;
case 0x0c07f938u: goto P_0c07f938;
case 0x0c07f93au: goto P_0c07f93a;
case 0x0c07f93cu: goto P_0c07f93c;
case 0x0c07f93eu: goto P_0c07f93e;
case 0x0c07f940u: goto P_0c07f940;
case 0x0c07f942u: goto P_0c07f942;
case 0x0c07f944u: goto P_0c07f944;
case 0x0c07f946u: goto P_0c07f946;
case 0x0c07f948u: goto P_0c07f948;
case 0x0c07f94au: goto P_0c07f94a;
case 0x0c07f94cu: goto P_0c07f94c;
case 0x0c07f94eu: goto P_0c07f94e;
case 0x0c07f950u: goto P_0c07f950;
case 0x0c07f952u: goto P_0c07f952;
case 0x0c07f954u: goto P_0c07f954;
case 0x0c07f956u: goto P_0c07f956;
case 0x0c07f958u: goto P_0c07f958;
case 0x0c07f95au: goto P_0c07f95a;
case 0x0c07f95cu: goto P_0c07f95c;
case 0x0c07f95eu: goto P_0c07f95e;
case 0x0c07f960u: goto P_0c07f960;
case 0x0c07f962u: goto P_0c07f962;
case 0x0c07f964u: goto P_0c07f964;
case 0x0c07f966u: goto P_0c07f966;
case 0x0c07f968u: goto P_0c07f968;
case 0x0c07f96au: goto P_0c07f96a;
case 0x0c07f96cu: goto P_0c07f96c;
case 0x0c07f96eu: goto P_0c07f96e;
case 0x0c07f970u: goto P_0c07f970;
case 0x0c07f972u: goto P_0c07f972;
case 0x0c07f974u: goto P_0c07f974;
case 0x0c07f976u: goto P_0c07f976;
case 0x0c07f9c4u: goto P_0c07f9c4;
case 0x0c07f9c6u: goto P_0c07f9c6;
case 0x0c07f9c8u: goto P_0c07f9c8;
case 0x0c07f9cau: goto P_0c07f9ca;
case 0x0c07f9ccu: goto P_0c07f9cc;
case 0x0c07f9ceu: goto P_0c07f9ce;
case 0x0c07f9d0u: goto P_0c07f9d0;
case 0x0c07f9d2u: goto P_0c07f9d2;
case 0x0c07f9d4u: goto P_0c07f9d4;
case 0x0c07f9d6u: goto P_0c07f9d6;
case 0x0c07f9d8u: goto P_0c07f9d8;
case 0x0c07f9dau: goto P_0c07f9da;
case 0x0c07f9dcu: goto P_0c07f9dc;
case 0x0c07f9deu: goto P_0c07f9de;
case 0x0c07f9e0u: goto P_0c07f9e0;
case 0x0c07f9e2u: goto P_0c07f9e2;
case 0x0c07f9e4u: goto P_0c07f9e4;
case 0x0c07f9e6u: goto P_0c07f9e6;
case 0x0c07f9e8u: goto P_0c07f9e8;
case 0x0c07f9eau: goto P_0c07f9ea;
case 0x0c07f9ecu: goto P_0c07f9ec;
case 0x0c07f9eeu: goto P_0c07f9ee;
case 0x0c07f9f0u: goto P_0c07f9f0;
case 0x0c07f9f2u: goto P_0c07f9f2;
case 0x0c07f9f4u: goto P_0c07f9f4;
case 0x0c07f9f6u: goto P_0c07f9f6;
case 0x0c07f9f8u: goto P_0c07f9f8;
case 0x0c07f9fau: goto P_0c07f9fa;
case 0x0c07f9fcu: goto P_0c07f9fc;
case 0x0c07f9feu: goto P_0c07f9fe;
case 0x0c07fa00u: goto P_0c07fa00;
case 0x0c07fa02u: goto P_0c07fa02;
case 0x0c07fa04u: goto P_0c07fa04;
case 0x0c07fa06u: goto P_0c07fa06;
case 0x0c07fa08u: goto P_0c07fa08;
case 0x0c07fa0au: goto P_0c07fa0a;
case 0x0c07fa0cu: goto P_0c07fa0c;
case 0x0c07fa0eu: goto P_0c07fa0e;
case 0x0c07fa10u: goto P_0c07fa10;
case 0x0c07fa12u: goto P_0c07fa12;
case 0x0c07fa14u: goto P_0c07fa14;
case 0x0c07fa16u: goto P_0c07fa16;
case 0x0c07fa18u: goto P_0c07fa18;
case 0x0c07fa1au: goto P_0c07fa1a;
case 0x0c07fa1cu: goto P_0c07fa1c;
case 0x0c07fa1eu: goto P_0c07fa1e;
case 0x0c07fa20u: goto P_0c07fa20;
case 0x0c07fa22u: goto P_0c07fa22;
case 0x0c07fa24u: goto P_0c07fa24;
case 0x0c07fa26u: goto P_0c07fa26;
case 0x0c07fa28u: goto P_0c07fa28;
case 0x0c07fa2au: goto P_0c07fa2a;
case 0x0c07fa2cu: goto P_0c07fa2c;
case 0x0c07fa2eu: goto P_0c07fa2e;
case 0x0c07fa30u: goto P_0c07fa30;
case 0x0c07fa32u: goto P_0c07fa32;
case 0x0c07fa34u: goto P_0c07fa34;
case 0x0c07fa36u: goto P_0c07fa36;
case 0x0c07fa38u: goto P_0c07fa38;
case 0x0c07fa3au: goto P_0c07fa3a;
case 0x0c07fa3cu: goto P_0c07fa3c;
case 0x0c07fa3eu: goto P_0c07fa3e;
case 0x0c07fa40u: goto P_0c07fa40;
case 0x0c07fa42u: goto P_0c07fa42;
case 0x0c07fa44u: goto P_0c07fa44;
case 0x0c07fa46u: goto P_0c07fa46;
case 0x0c07fa48u: goto P_0c07fa48;
case 0x0c07fa4au: goto P_0c07fa4a;
case 0x0c07fa4cu: goto P_0c07fa4c;
case 0x0c07fa4eu: goto P_0c07fa4e;
case 0x0c07fa50u: goto P_0c07fa50;
case 0x0c07fa52u: goto P_0c07fa52;
case 0x0c07fa54u: goto P_0c07fa54;
case 0x0c07fa56u: goto P_0c07fa56;
case 0x0c07fa58u: goto P_0c07fa58;
case 0x0c07fa5au: goto P_0c07fa5a;
case 0x0c07fa5cu: goto P_0c07fa5c;
case 0x0c07fa5eu: goto P_0c07fa5e;
case 0x0c07fa60u: goto P_0c07fa60;
case 0x0c07fa62u: goto P_0c07fa62;
case 0x0c07fa64u: goto P_0c07fa64;
case 0x0c07fa66u: goto P_0c07fa66;
case 0x0c07fa68u: goto P_0c07fa68;
case 0x0c07fa6au: goto P_0c07fa6a;
case 0x0c07fa6cu: goto P_0c07fa6c;
case 0x0c07fa6eu: goto P_0c07fa6e;
case 0x0c07fa70u: goto P_0c07fa70;
case 0x0c07fa72u: goto P_0c07fa72;
case 0x0c07fa74u: goto P_0c07fa74;
case 0x0c07fa76u: goto P_0c07fa76;
case 0x0c07fa78u: goto P_0c07fa78;
case 0x0c07fa7au: goto P_0c07fa7a;
case 0x0c07fa7cu: goto P_0c07fa7c;
case 0x0c07fa7eu: goto P_0c07fa7e;
case 0x0c07fa80u: goto P_0c07fa80;
case 0x0c07fa82u: goto P_0c07fa82;
case 0x0c07fa84u: goto P_0c07fa84;
case 0x0c07fa86u: goto P_0c07fa86;
case 0x0c07fa88u: goto P_0c07fa88;
case 0x0c07fa8au: goto P_0c07fa8a;
case 0x0c07fa8cu: goto P_0c07fa8c;
case 0x0c07fa8eu: goto P_0c07fa8e;
case 0x0c07fa90u: goto P_0c07fa90;
case 0x0c07fa92u: goto P_0c07fa92;
case 0x0c07fa94u: goto P_0c07fa94;
case 0x0c07fa96u: goto P_0c07fa96;
case 0x0c07fa98u: goto P_0c07fa98;
case 0x0c07fa9au: goto P_0c07fa9a;
case 0x0c07fa9cu: goto P_0c07fa9c;
case 0x0c07fa9eu: goto P_0c07fa9e;
case 0x0c07faa0u: goto P_0c07faa0;
case 0x0c07faa2u: goto P_0c07faa2;
case 0x0c07faa4u: goto P_0c07faa4;
case 0x0c07faa6u: goto P_0c07faa6;
case 0x0c07faa8u: goto P_0c07faa8;
case 0x0c07faaau: goto P_0c07faaa;
case 0x0c07faacu: goto P_0c07faac;
case 0x0c07faaeu: goto P_0c07faae;
case 0x0c07fab0u: goto P_0c07fab0;
case 0x0c07fab2u: goto P_0c07fab2;
case 0x0c07fab4u: goto P_0c07fab4;
case 0x0c07fab6u: goto P_0c07fab6;
case 0x0c07fab8u: goto P_0c07fab8;
case 0x0c07fabau: goto P_0c07faba;
case 0x0c07fabcu: goto P_0c07fabc;
case 0x0c07fabeu: goto P_0c07fabe;
case 0x0c07fac0u: goto P_0c07fac0;
case 0x0c07fac2u: goto P_0c07fac2;
case 0x0c07fac4u: goto P_0c07fac4;
case 0x0c07fac6u: goto P_0c07fac6;
case 0x0c07fac8u: goto P_0c07fac8;
case 0x0c07facau: goto P_0c07faca;
case 0x0c07faccu: goto P_0c07facc;
case 0x0c07faceu: goto P_0c07face;
case 0x0c07fad0u: goto P_0c07fad0;
case 0x0c07fad2u: goto P_0c07fad2;
case 0x0c07fad4u: goto P_0c07fad4;
case 0x0c07fad6u: goto P_0c07fad6;
case 0x0c07fad8u: goto P_0c07fad8;
case 0x0c07fadau: goto P_0c07fada;
case 0x0c07fadcu: goto P_0c07fadc;
case 0x0c07fadeu: goto P_0c07fade;
case 0x0c07fb24u: goto P_0c07fb24;
case 0x0c07fb26u: goto P_0c07fb26;
case 0x0c07fb28u: goto P_0c07fb28;
case 0x0c07fb2au: goto P_0c07fb2a;
case 0x0c07fb2cu: goto P_0c07fb2c;
case 0x0c07fb2eu: goto P_0c07fb2e;
case 0x0c07fb30u: goto P_0c07fb30;
case 0x0c07fb32u: goto P_0c07fb32;
case 0x0c07fb34u: goto P_0c07fb34;
case 0x0c07fb36u: goto P_0c07fb36;
case 0x0c07fb38u: goto P_0c07fb38;
case 0x0c07fb3au: goto P_0c07fb3a;
case 0x0c07fb3cu: goto P_0c07fb3c;
case 0x0c07fb3eu: goto P_0c07fb3e;
case 0x0c07fb40u: goto P_0c07fb40;
case 0x0c07fb42u: goto P_0c07fb42;
case 0x0c07fb44u: goto P_0c07fb44;
case 0x0c07fb46u: goto P_0c07fb46;
case 0x0c07fb48u: goto P_0c07fb48;
case 0x0c07fb4au: goto P_0c07fb4a;
case 0x0c07fb4cu: goto P_0c07fb4c;
case 0x0c07fb4eu: goto P_0c07fb4e;
case 0x0c07fb50u: goto P_0c07fb50;
case 0x0c07fb52u: goto P_0c07fb52;
case 0x0c07fb54u: goto P_0c07fb54;
case 0x0c07fb56u: goto P_0c07fb56;
case 0x0c07fb58u: goto P_0c07fb58;
case 0x0c07fb5au: goto P_0c07fb5a;
case 0x0c07fb5cu: goto P_0c07fb5c;
case 0x0c07fb5eu: goto P_0c07fb5e;
case 0x0c07fb60u: goto P_0c07fb60;
case 0x0c07fb62u: goto P_0c07fb62;
case 0x0c07fb64u: goto P_0c07fb64;
case 0x0c07fb66u: goto P_0c07fb66;
case 0x0c07fb68u: goto P_0c07fb68;
case 0x0c07fb6au: goto P_0c07fb6a;
case 0x0c07fb6cu: goto P_0c07fb6c;
case 0x0c07fb6eu: goto P_0c07fb6e;
case 0x0c07fb70u: goto P_0c07fb70;
case 0x0c07fb72u: goto P_0c07fb72;
case 0x0c07fb74u: goto P_0c07fb74;
case 0x0c07fb76u: goto P_0c07fb76;
case 0x0c07fb78u: goto P_0c07fb78;
case 0x0c07fb7au: goto P_0c07fb7a;
case 0x0c07fb7cu: goto P_0c07fb7c;
case 0x0c07fb7eu: goto P_0c07fb7e;
case 0x0c07fb80u: goto P_0c07fb80;
case 0x0c07fb82u: goto P_0c07fb82;
case 0x0c07fb84u: goto P_0c07fb84;
case 0x0c07fb86u: goto P_0c07fb86;
case 0x0c07fb88u: goto P_0c07fb88;
case 0x0c07fb8au: goto P_0c07fb8a;
case 0x0c07fb8cu: goto P_0c07fb8c;
case 0x0c07fb8eu: goto P_0c07fb8e;
case 0x0c07fb90u: goto P_0c07fb90;
case 0x0c07fb92u: goto P_0c07fb92;
case 0x0c07fb94u: goto P_0c07fb94;
case 0x0c07fb96u: goto P_0c07fb96;
case 0x0c07fb98u: goto P_0c07fb98;
case 0x0c07fb9au: goto P_0c07fb9a;
case 0x0c07fb9cu: goto P_0c07fb9c;
case 0x0c07fb9eu: goto P_0c07fb9e;
case 0x0c07fba0u: goto P_0c07fba0;
case 0x0c07fba2u: goto P_0c07fba2;
case 0x0c07fba4u: goto P_0c07fba4;
case 0x0c07fba6u: goto P_0c07fba6;
case 0x0c07fba8u: goto P_0c07fba8;
case 0x0c07fbaau: goto P_0c07fbaa;
case 0x0c07fbacu: goto P_0c07fbac;
case 0x0c07fbaeu: goto P_0c07fbae;
case 0x0c07fbb0u: goto P_0c07fbb0;
case 0x0c07fbb2u: goto P_0c07fbb2;
case 0x0c07fbb4u: goto P_0c07fbb4;
case 0x0c07fbb6u: goto P_0c07fbb6;
case 0x0c07fbb8u: goto P_0c07fbb8;
case 0x0c07fbbau: goto P_0c07fbba;
case 0x0c07fbbcu: goto P_0c07fbbc;
case 0x0c07fbbeu: goto P_0c07fbbe;
case 0x0c07fbc0u: goto P_0c07fbc0;
case 0x0c07fbc2u: goto P_0c07fbc2;
case 0x0c07fbc4u: goto P_0c07fbc4;
case 0x0c07fbc6u: goto P_0c07fbc6;
case 0x0c07fbc8u: goto P_0c07fbc8;
case 0x0c07fbcau: goto P_0c07fbca;
case 0x0c07fbccu: goto P_0c07fbcc;
case 0x0c07fbceu: goto P_0c07fbce;
case 0x0c07fbd0u: goto P_0c07fbd0;
case 0x0c07fbd2u: goto P_0c07fbd2;
case 0x0c07fbd4u: goto P_0c07fbd4;
case 0x0c07fbd6u: goto P_0c07fbd6;
case 0x0c07fbd8u: goto P_0c07fbd8;
case 0x0c07fbdau: goto P_0c07fbda;
case 0x0c07fbdcu: goto P_0c07fbdc;
case 0x0c07fbdeu: goto P_0c07fbde;
case 0x0c07fbe0u: goto P_0c07fbe0;
case 0x0c07fbe2u: goto P_0c07fbe2;
case 0x0c080006u: goto P_0c080006;
case 0x0c080008u: goto P_0c080008;
case 0x0c08000au: goto P_0c08000a;
case 0x0c08000cu: goto P_0c08000c;
case 0x0c08000eu: goto P_0c08000e;
case 0x0c080010u: goto P_0c080010;
case 0x0c080012u: goto P_0c080012;
case 0x0c080014u: goto P_0c080014;
case 0x0c080016u: goto P_0c080016;
case 0x0c080018u: goto P_0c080018;
case 0x0c08001au: goto P_0c08001a;
case 0x0c08001cu: goto P_0c08001c;
case 0x0c08001eu: goto P_0c08001e;
case 0x0c080020u: goto P_0c080020;
case 0x0c080022u: goto P_0c080022;
case 0x0c080024u: goto P_0c080024;
case 0x0c080026u: goto P_0c080026;
case 0x0c080028u: goto P_0c080028;
case 0x0c08002au: goto P_0c08002a;
case 0x0c08002cu: goto P_0c08002c;
case 0x0c08002eu: goto P_0c08002e;
case 0x0c080030u: goto P_0c080030;
case 0x0c080032u: goto P_0c080032;
case 0x0c080034u: goto P_0c080034;
case 0x0c080036u: goto P_0c080036;
case 0x0c080038u: goto P_0c080038;
case 0x0c08003au: goto P_0c08003a;
case 0x0c08003cu: goto P_0c08003c;
case 0x0c08003eu: goto P_0c08003e;
case 0x0c080040u: goto P_0c080040;
case 0x0c080042u: goto P_0c080042;
case 0x0c080044u: goto P_0c080044;
case 0x0c080046u: goto P_0c080046;
case 0x0c080048u: goto P_0c080048;
case 0x0c08004au: goto P_0c08004a;
case 0x0c08004cu: goto P_0c08004c;
case 0x0c08004eu: goto P_0c08004e;
case 0x0c080050u: goto P_0c080050;
case 0x0c080052u: goto P_0c080052;
case 0x0c080054u: goto P_0c080054;
case 0x0c080056u: goto P_0c080056;
case 0x0c080058u: goto P_0c080058;
case 0x0c08005au: goto P_0c08005a;
case 0x0c08005cu: goto P_0c08005c;
case 0x0c08005eu: goto P_0c08005e;
case 0x0c080060u: goto P_0c080060;
case 0x0c080062u: goto P_0c080062;
case 0x0c080064u: goto P_0c080064;
case 0x0c080066u: goto P_0c080066;
case 0x0c080068u: goto P_0c080068;
case 0x0c08006au: goto P_0c08006a;
case 0x0c08006cu: goto P_0c08006c;
case 0x0c08006eu: goto P_0c08006e;
case 0x0c080070u: goto P_0c080070;
case 0x0c080072u: goto P_0c080072;
case 0x0c080074u: goto P_0c080074;
case 0x0c080076u: goto P_0c080076;
case 0x0c080078u: goto P_0c080078;
case 0x0c08007au: goto P_0c08007a;
case 0x0c08007cu: goto P_0c08007c;
case 0x0c08007eu: goto P_0c08007e;
case 0x0c080080u: goto P_0c080080;
case 0x0c080082u: goto P_0c080082;
case 0x0c0800d8u: goto P_0c0800d8;
case 0x0c0800dau: goto P_0c0800da;
case 0x0c0800dcu: goto P_0c0800dc;
case 0x0c0800deu: goto P_0c0800de;
case 0x0c0800e0u: goto P_0c0800e0;
case 0x0c0800e2u: goto P_0c0800e2;
case 0x0c0800e4u: goto P_0c0800e4;
case 0x0c0800e6u: goto P_0c0800e6;
case 0x0c0800e8u: goto P_0c0800e8;
case 0x0c0800eau: goto P_0c0800ea;
case 0x0c0800ecu: goto P_0c0800ec;
case 0x0c0800eeu: goto P_0c0800ee;
case 0x0c0800f0u: goto P_0c0800f0;
case 0x0c0800f2u: goto P_0c0800f2;
case 0x0c0800f4u: goto P_0c0800f4;
case 0x0c0800f6u: goto P_0c0800f6;
case 0x0c0800f8u: goto P_0c0800f8;
case 0x0c0800fau: goto P_0c0800fa;
case 0x0c0800fcu: goto P_0c0800fc;
case 0x0c0800feu: goto P_0c0800fe;
case 0x0c080100u: goto P_0c080100;
case 0x0c080102u: goto P_0c080102;
case 0x0c080104u: goto P_0c080104;
case 0x0c080106u: goto P_0c080106;
case 0x0c080108u: goto P_0c080108;
case 0x0c08010au: goto P_0c08010a;
case 0x0c08010cu: goto P_0c08010c;
case 0x0c08010eu: goto P_0c08010e;
case 0x0c080110u: goto P_0c080110;
case 0x0c08019eu: goto P_0c08019e;
case 0x0c0801a0u: goto P_0c0801a0;
case 0x0c0801a2u: goto P_0c0801a2;
case 0x0c0801a4u: goto P_0c0801a4;
case 0x0c0801a6u: goto P_0c0801a6;
case 0x0c0801a8u: goto P_0c0801a8;
case 0x0c0801aau: goto P_0c0801aa;
case 0x0c0801acu: goto P_0c0801ac;
case 0x0c0801aeu: goto P_0c0801ae;
case 0x0c0801b0u: goto P_0c0801b0;
case 0x0c0801b2u: goto P_0c0801b2;
case 0x0c0801b4u: goto P_0c0801b4;
case 0x0c0801b6u: goto P_0c0801b6;
case 0x0c0801b8u: goto P_0c0801b8;
case 0x0c0801bau: goto P_0c0801ba;
case 0x0c0801bcu: goto P_0c0801bc;
case 0x0c0801beu: goto P_0c0801be;
case 0x0c0801c0u: goto P_0c0801c0;
case 0x0c0801c2u: goto P_0c0801c2;
case 0x0c0801c4u: goto P_0c0801c4;
case 0x0c0801c6u: goto P_0c0801c6;
case 0x0c0801c8u: goto P_0c0801c8;
case 0x0c0801cau: goto P_0c0801ca;
case 0x0c0801ccu: goto P_0c0801cc;
case 0x0c0801ceu: goto P_0c0801ce;
case 0x0c0801d0u: goto P_0c0801d0;
case 0x0c0801d2u: goto P_0c0801d2;
case 0x0c0801d4u: goto P_0c0801d4;
case 0x0c0801d6u: goto P_0c0801d6;
case 0x0c0801d8u: goto P_0c0801d8;
case 0x0c0801dau: goto P_0c0801da;
case 0x0c0801dcu: goto P_0c0801dc;
case 0x0c080238u: goto P_0c080238;
case 0x0c08023au: goto P_0c08023a;
case 0x0c08023cu: goto P_0c08023c;
case 0x0c08023eu: goto P_0c08023e;
case 0x0c080240u: goto P_0c080240;
case 0x0c080242u: goto P_0c080242;
case 0x0c080244u: goto P_0c080244;
case 0x0c080246u: goto P_0c080246;
case 0x0c080248u: goto P_0c080248;
case 0x0c08024au: goto P_0c08024a;
case 0x0c08024cu: goto P_0c08024c;
case 0x0c08024eu: goto P_0c08024e;
case 0x0c080250u: goto P_0c080250;
case 0x0c080252u: goto P_0c080252;
case 0x0c080254u: goto P_0c080254;
case 0x0c080256u: goto P_0c080256;
case 0x0c080258u: goto P_0c080258;
case 0x0c08025au: goto P_0c08025a;
case 0x0c08025cu: goto P_0c08025c;
case 0x0c08025eu: goto P_0c08025e;
case 0x0c080260u: goto P_0c080260;
case 0x0c0803feu: goto P_0c0803fe;
case 0x0c080400u: goto P_0c080400;
case 0x0c080402u: goto P_0c080402;
case 0x0c080404u: goto P_0c080404;
case 0x0c080406u: goto P_0c080406;
case 0x0c080408u: goto P_0c080408;
case 0x0c08040au: goto P_0c08040a;
case 0x0c08040cu: goto P_0c08040c;
case 0x0c08040eu: goto P_0c08040e;
case 0x0c080410u: goto P_0c080410;
case 0x0c080412u: goto P_0c080412;
case 0x0c080414u: goto P_0c080414;
case 0x0c080416u: goto P_0c080416;
case 0x0c080418u: goto P_0c080418;
case 0x0c08041au: goto P_0c08041a;
case 0x0c08041cu: goto P_0c08041c;
case 0x0c08041eu: goto P_0c08041e;
case 0x0c080420u: goto P_0c080420;
case 0x0c080422u: goto P_0c080422;
case 0x0c080424u: goto P_0c080424;
case 0x0c080426u: goto P_0c080426;
case 0x0c080428u: goto P_0c080428;
case 0x0c08042au: goto P_0c08042a;
case 0x0c08042cu: goto P_0c08042c;
case 0x0c08042eu: goto P_0c08042e;
case 0x0c080430u: goto P_0c080430;
case 0x0c080432u: goto P_0c080432;
case 0x0c080434u: goto P_0c080434;
case 0x0c080436u: goto P_0c080436;
case 0x0c080438u: goto P_0c080438;
case 0x0c08043au: goto P_0c08043a;
case 0x0c08043cu: goto P_0c08043c;
case 0x0c08043eu: goto P_0c08043e;
case 0x0c080440u: goto P_0c080440;
case 0x0c080442u: goto P_0c080442;
case 0x0c080444u: goto P_0c080444;
case 0x0c080446u: goto P_0c080446;
case 0x0c080448u: goto P_0c080448;
case 0x0c08044au: goto P_0c08044a;
case 0x0c08044cu: goto P_0c08044c;
case 0x0c08044eu: goto P_0c08044e;
case 0x0c080450u: goto P_0c080450;
case 0x0c080452u: goto P_0c080452;
case 0x0c080454u: goto P_0c080454;
case 0x0c080456u: goto P_0c080456;
case 0x0c080458u: goto P_0c080458;
case 0x0c08045au: goto P_0c08045a;
case 0x0c08045cu: goto P_0c08045c;
case 0x0c08045eu: goto P_0c08045e;
case 0x0c080460u: goto P_0c080460;
case 0x0c080462u: goto P_0c080462;
case 0x0c081a9eu: goto P_0c081a9e;
case 0x0c081aa0u: goto P_0c081aa0;
case 0x0c081aa2u: goto P_0c081aa2;
case 0x0c081aa4u: goto P_0c081aa4;
case 0x0c081aa6u: goto P_0c081aa6;
case 0x0c081aa8u: goto P_0c081aa8;
case 0x0c081aaau: goto P_0c081aaa;
case 0x0c081aacu: goto P_0c081aac;
case 0x0c081aaeu: goto P_0c081aae;
case 0x0c081ab0u: goto P_0c081ab0;
case 0x0c081ab2u: goto P_0c081ab2;
case 0x0c081ab4u: goto P_0c081ab4;
case 0x0c081ab6u: goto P_0c081ab6;
case 0x0c081ab8u: goto P_0c081ab8;
case 0x0c081abau: goto P_0c081aba;
case 0x0c081abcu: goto P_0c081abc;
case 0x0c081abeu: goto P_0c081abe;
case 0x0c081ac0u: goto P_0c081ac0;
case 0x0c081ac2u: goto P_0c081ac2;
case 0x0c081ac4u: goto P_0c081ac4;
case 0x0c081ac6u: goto P_0c081ac6;
case 0x0c081ac8u: goto P_0c081ac8;
case 0x0c081acau: goto P_0c081aca;
case 0x0c081accu: goto P_0c081acc;
case 0x0c081aceu: goto P_0c081ace;
case 0x0c081ad0u: goto P_0c081ad0;
case 0x0c081ad2u: goto P_0c081ad2;
case 0x0c081ad4u: goto P_0c081ad4;
case 0x0c081ad6u: goto P_0c081ad6;
case 0x0c081ad8u: goto P_0c081ad8;
case 0x0c081adau: goto P_0c081ada;
case 0x0c081adcu: goto P_0c081adc;
case 0x0c081adeu: goto P_0c081ade;
case 0x0c081ae0u: goto P_0c081ae0;
case 0x0c081ae2u: goto P_0c081ae2;
case 0x0c081ae4u: goto P_0c081ae4;
case 0x0c081ae6u: goto P_0c081ae6;
case 0x0c081ae8u: goto P_0c081ae8;
case 0x0c081aeau: goto P_0c081aea;
case 0x0c081aecu: goto P_0c081aec;
case 0x0c081aeeu: goto P_0c081aee;
case 0x0c081af0u: goto P_0c081af0;
case 0x0c081af2u: goto P_0c081af2;
case 0x0c081af4u: goto P_0c081af4;
case 0x0c081af6u: goto P_0c081af6;
case 0x0c081af8u: goto P_0c081af8;
case 0x0c081afau: goto P_0c081afa;
case 0x0c081afcu: goto P_0c081afc;
case 0x0c081afeu: goto P_0c081afe;
case 0x0c081b00u: goto P_0c081b00;
case 0x0c081b02u: goto P_0c081b02;
case 0x0c081b04u: goto P_0c081b04;
case 0x0c081b06u: goto P_0c081b06;
case 0x0c081b08u: goto P_0c081b08;
case 0x0c081b0au: goto P_0c081b0a;
case 0x0c081b0cu: goto P_0c081b0c;
case 0x0c081b0eu: goto P_0c081b0e;
case 0x0c081b10u: goto P_0c081b10;
case 0x0c081b12u: goto P_0c081b12;
case 0x0c081b14u: goto P_0c081b14;
case 0x0c081b16u: goto P_0c081b16;
case 0x0c081b18u: goto P_0c081b18;
case 0x0c081b1au: goto P_0c081b1a;
case 0x0c081b1cu: goto P_0c081b1c;
case 0x0c081b1eu: goto P_0c081b1e;
case 0x0c081b20u: goto P_0c081b20;
case 0x0c081b22u: goto P_0c081b22;
case 0x0c081b24u: goto P_0c081b24;
case 0x0c081b60u: goto P_0c081b60;
case 0x0c081b62u: goto P_0c081b62;
case 0x0c081b64u: goto P_0c081b64;
case 0x0c081b66u: goto P_0c081b66;
case 0x0c081b68u: goto P_0c081b68;
case 0x0c081b6au: goto P_0c081b6a;
case 0x0c081b6cu: goto P_0c081b6c;
case 0x0c081b6eu: goto P_0c081b6e;
case 0x0c081b70u: goto P_0c081b70;
case 0x0c081b72u: goto P_0c081b72;
case 0x0c081b74u: goto P_0c081b74;
case 0x0c081b76u: goto P_0c081b76;
case 0x0c081b78u: goto P_0c081b78;
case 0x0c081b7au: goto P_0c081b7a;
case 0x0c081b7cu: goto P_0c081b7c;
case 0x0c081b7eu: goto P_0c081b7e;
case 0x0c081b80u: goto P_0c081b80;
case 0x0c081b82u: goto P_0c081b82;
case 0x0c081b84u: goto P_0c081b84;
case 0x0c081b86u: goto P_0c081b86;
case 0x0c081b88u: goto P_0c081b88;
case 0x0c081b8au: goto P_0c081b8a;
case 0x0c081b8cu: goto P_0c081b8c;
case 0x0c081b8eu: goto P_0c081b8e;
case 0x0c081b90u: goto P_0c081b90;
case 0x0c081b92u: goto P_0c081b92;
case 0x0c081b94u: goto P_0c081b94;
case 0x0c081b96u: goto P_0c081b96;
case 0x0c081b98u: goto P_0c081b98;
case 0x0c081b9au: goto P_0c081b9a;
case 0x0c081b9cu: goto P_0c081b9c;
case 0x0c081b9eu: goto P_0c081b9e;
case 0x0c081ba0u: goto P_0c081ba0;
case 0x0c081ba2u: goto P_0c081ba2;
case 0x0c081ba4u: goto P_0c081ba4;
case 0x0c081ba6u: goto P_0c081ba6;
case 0x0c081ba8u: goto P_0c081ba8;
case 0x0c081baau: goto P_0c081baa;
case 0x0c081bacu: goto P_0c081bac;
case 0x0c081baeu: goto P_0c081bae;
case 0x0c081bb0u: goto P_0c081bb0;
case 0x0c081bb2u: goto P_0c081bb2;
case 0x0c081bb4u: goto P_0c081bb4;
case 0x0c081bb6u: goto P_0c081bb6;
case 0x0c081bb8u: goto P_0c081bb8;
case 0x0c081bbau: goto P_0c081bba;
case 0x0c081bbcu: goto P_0c081bbc;
case 0x0c081bbeu: goto P_0c081bbe;
case 0x0c081bc0u: goto P_0c081bc0;
case 0x0c081bc2u: goto P_0c081bc2;
case 0x0c081bc4u: goto P_0c081bc4;
case 0x0c081bc6u: goto P_0c081bc6;
case 0x0c081bc8u: goto P_0c081bc8;
case 0x0c081bcau: goto P_0c081bca;
case 0x0c081bccu: goto P_0c081bcc;
case 0x0c081bceu: goto P_0c081bce;
case 0x0c081bd0u: goto P_0c081bd0;
case 0x0c081bd2u: goto P_0c081bd2;
case 0x0c081bd4u: goto P_0c081bd4;
case 0x0c081bd6u: goto P_0c081bd6;
case 0x0c081bd8u: goto P_0c081bd8;
case 0x0c081bf0u: goto P_0c081bf0;
case 0x0c081bf2u: goto P_0c081bf2;
case 0x0c081bf4u: goto P_0c081bf4;
case 0x0c081bf6u: goto P_0c081bf6;
case 0x0c081bf8u: goto P_0c081bf8;
case 0x0c081bfau: goto P_0c081bfa;
case 0x0c081bfcu: goto P_0c081bfc;
case 0x0c081bfeu: goto P_0c081bfe;
case 0x0c081c00u: goto P_0c081c00;
case 0x0c081c02u: goto P_0c081c02;
case 0x0c081c04u: goto P_0c081c04;
case 0x0c081c06u: goto P_0c081c06;
case 0x0c081c08u: goto P_0c081c08;
case 0x0c081c0au: goto P_0c081c0a;
case 0x0c081c0cu: goto P_0c081c0c;
case 0x0c081c0eu: goto P_0c081c0e;
case 0x0c081c10u: goto P_0c081c10;
case 0x0c081c12u: goto P_0c081c12;
case 0x0c081c14u: goto P_0c081c14;
case 0x0c081c16u: goto P_0c081c16;
case 0x0c081c18u: goto P_0c081c18;
case 0x0c081c1au: goto P_0c081c1a;
case 0x0c081c1cu: goto P_0c081c1c;
case 0x0c081c1eu: goto P_0c081c1e;
case 0x0c081c20u: goto P_0c081c20;
case 0x0c081c22u: goto P_0c081c22;
case 0x0c081c24u: goto P_0c081c24;
case 0x0c081c26u: goto P_0c081c26;
case 0x0c081c28u: goto P_0c081c28;
case 0x0c081c2au: goto P_0c081c2a;
case 0x0c081c2cu: goto P_0c081c2c;
case 0x0c081c2eu: goto P_0c081c2e;
case 0x0c081c30u: goto P_0c081c30;
case 0x0c081c32u: goto P_0c081c32;
case 0x0c081c34u: goto P_0c081c34;
case 0x0c081c36u: goto P_0c081c36;
case 0x0c081c38u: goto P_0c081c38;
case 0x0c081c3au: goto P_0c081c3a;
case 0x0c081c3cu: goto P_0c081c3c;
case 0x0c081c3eu: goto P_0c081c3e;
case 0x0c081c40u: goto P_0c081c40;
case 0x0c081c42u: goto P_0c081c42;
case 0x0c081c44u: goto P_0c081c44;
case 0x0c081c46u: goto P_0c081c46;
case 0x0c081c48u: goto P_0c081c48;
case 0x0c081c4au: goto P_0c081c4a;
case 0x0c081c4cu: goto P_0c081c4c;
case 0x0c081c4eu: goto P_0c081c4e;
case 0x0c081c50u: goto P_0c081c50;
case 0x0c081c52u: goto P_0c081c52;
case 0x0c081c54u: goto P_0c081c54;
case 0x0c081c56u: goto P_0c081c56;
case 0x0c081c58u: goto P_0c081c58;
case 0x0c081c5au: goto P_0c081c5a;
case 0x0c081c5cu: goto P_0c081c5c;
case 0x0c081c5eu: goto P_0c081c5e;
case 0x0c081c60u: goto P_0c081c60;
case 0x0c081c62u: goto P_0c081c62;
case 0x0c081c64u: goto P_0c081c64;
case 0x0c081c66u: goto P_0c081c66;
case 0x0c081c68u: goto P_0c081c68;
case 0x0c081c6au: goto P_0c081c6a;
case 0x0c081c6cu: goto P_0c081c6c;
case 0x0c081c6eu: goto P_0c081c6e;
case 0x0c081c70u: goto P_0c081c70;
case 0x0c081c72u: goto P_0c081c72;
case 0x0c081c74u: goto P_0c081c74;
case 0x0c081c76u: goto P_0c081c76;
case 0x0c081c78u: goto P_0c081c78;
case 0x0c081c7au: goto P_0c081c7a;
case 0x0c081c7cu: goto P_0c081c7c;
case 0x0c081c7eu: goto P_0c081c7e;
case 0x0c081c80u: goto P_0c081c80;
case 0x0c081c82u: goto P_0c081c82;
case 0x0c081c84u: goto P_0c081c84;
case 0x0c081c86u: goto P_0c081c86;
case 0x0c081c88u: goto P_0c081c88;
case 0x0c081c8au: goto P_0c081c8a;
case 0x0c081c8cu: goto P_0c081c8c;
case 0x0c081c8eu: goto P_0c081c8e;
case 0x0c081c90u: goto P_0c081c90;
case 0x0c081c92u: goto P_0c081c92;
case 0x0c081c94u: goto P_0c081c94;
case 0x0c081c96u: goto P_0c081c96;
case 0x0c081c98u: goto P_0c081c98;
case 0x0c081c9au: goto P_0c081c9a;
case 0x0c081c9cu: goto P_0c081c9c;
case 0x0c081c9eu: goto P_0c081c9e;
case 0x0c081ca0u: goto P_0c081ca0;
case 0x0c081ca2u: goto P_0c081ca2;
case 0x0c081ca4u: goto P_0c081ca4;
case 0x0c081ca6u: goto P_0c081ca6;
case 0x0c081ca8u: goto P_0c081ca8;
case 0x0c081caau: goto P_0c081caa;
case 0x0c081cacu: goto P_0c081cac;
case 0x0c081caeu: goto P_0c081cae;
case 0x0c081cb0u: goto P_0c081cb0;
case 0x0c081cb2u: goto P_0c081cb2;
case 0x0c081cb4u: goto P_0c081cb4;
case 0x0c081cb6u: goto P_0c081cb6;
case 0x0c081cb8u: goto P_0c081cb8;
case 0x0c081cbau: goto P_0c081cba;
case 0x0c081cbcu: goto P_0c081cbc;
case 0x0c081cbeu: goto P_0c081cbe;
case 0x0c081cc0u: goto P_0c081cc0;
case 0x0c081cc2u: goto P_0c081cc2;
case 0x0c081cc4u: goto P_0c081cc4;
case 0x0c081cc6u: goto P_0c081cc6;
case 0x0c081cc8u: goto P_0c081cc8;
case 0x0c081ccau: goto P_0c081cca;
case 0x0c081cccu: goto P_0c081ccc;
case 0x0c081cceu: goto P_0c081cce;
case 0x0c081cd0u: goto P_0c081cd0;
case 0x0c081cd2u: goto P_0c081cd2;
case 0x0c081cd4u: goto P_0c081cd4;
case 0x0c081cd6u: goto P_0c081cd6;
case 0x0c081cd8u: goto P_0c081cd8;
case 0x0c081cdau: goto P_0c081cda;
case 0x0c081cdcu: goto P_0c081cdc;
case 0x0c081cdeu: goto P_0c081cde;
case 0x0c081ce0u: goto P_0c081ce0;
case 0x0c081ce2u: goto P_0c081ce2;
case 0x0c081ce4u: goto P_0c081ce4;
case 0x0c081ce6u: goto P_0c081ce6;
case 0x0c083c86u: goto P_0c083c86;
case 0x0c083c88u: goto P_0c083c88;
case 0x0c083c8au: goto P_0c083c8a;
case 0x0c083c8cu: goto P_0c083c8c;
case 0x0c083c8eu: goto P_0c083c8e;
case 0x0c083c90u: goto P_0c083c90;
case 0x0c083c92u: goto P_0c083c92;
case 0x0c083c94u: goto P_0c083c94;
case 0x0c083c96u: goto P_0c083c96;
case 0x0c083c98u: goto P_0c083c98;
case 0x0c083c9au: goto P_0c083c9a;
case 0x0c083c9cu: goto P_0c083c9c;
case 0x0c083c9eu: goto P_0c083c9e;
case 0x0c083ca0u: goto P_0c083ca0;
case 0x0c083ca2u: goto P_0c083ca2;
case 0x0c083ca4u: goto P_0c083ca4;
case 0x0c083ca6u: goto P_0c083ca6;
case 0x0c083ca8u: goto P_0c083ca8;
case 0x0c083caau: goto P_0c083caa;
case 0x0c083cacu: goto P_0c083cac;
case 0x0c083caeu: goto P_0c083cae;
case 0x0c083cb0u: goto P_0c083cb0;
case 0x0c083cb2u: goto P_0c083cb2;
case 0x0c083cb4u: goto P_0c083cb4;
case 0x0c083cb6u: goto P_0c083cb6;
case 0x0c083cb8u: goto P_0c083cb8;
case 0x0c083cbau: goto P_0c083cba;
case 0x0c083cbcu: goto P_0c083cbc;
case 0x0c083cbeu: goto P_0c083cbe;
case 0x0c083cc0u: goto P_0c083cc0;
case 0x0c083cc2u: goto P_0c083cc2;
case 0x0c083cc4u: goto P_0c083cc4;
case 0x0c083cc6u: goto P_0c083cc6;
case 0x0c083cc8u: goto P_0c083cc8;
case 0x0c083ccau: goto P_0c083cca;
case 0x0c083cceu: goto P_0c083cce;
case 0x0c083cd0u: goto P_0c083cd0;
case 0x0c083cd2u: goto P_0c083cd2;
case 0x0c083cd4u: goto P_0c083cd4;
case 0x0c083cd6u: goto P_0c083cd6;
case 0x0c083cd8u: goto P_0c083cd8;
case 0x0c083cdau: goto P_0c083cda;
case 0x0c083cdcu: goto P_0c083cdc;
case 0x0c083cdeu: goto P_0c083cde;
case 0x0c083ce0u: goto P_0c083ce0;
case 0x0c083ce2u: goto P_0c083ce2;
case 0x0c083ce4u: goto P_0c083ce4;
case 0x0c083ce6u: goto P_0c083ce6;
case 0x0c083ce8u: goto P_0c083ce8;
case 0x0c083ceau: goto P_0c083cea;
case 0x0c083cecu: goto P_0c083cec;
case 0x0c083ceeu: goto P_0c083cee;
case 0x0c083cf0u: goto P_0c083cf0;
case 0x0c083cf2u: goto P_0c083cf2;
case 0x0c083cf4u: goto P_0c083cf4;
case 0x0c083cf6u: goto P_0c083cf6;
case 0x0c083cf8u: goto P_0c083cf8;
case 0x0c083cfau: goto P_0c083cfa;
case 0x0c083cfcu: goto P_0c083cfc;
case 0x0c083cfeu: goto P_0c083cfe;
case 0x0c083d00u: goto P_0c083d00;
case 0x0c083d02u: goto P_0c083d02;
case 0x0c083d04u: goto P_0c083d04;
case 0x0c083d06u: goto P_0c083d06;
case 0x0c083d08u: goto P_0c083d08;
case 0x0c083d0au: goto P_0c083d0a;
case 0x0c083d0cu: goto P_0c083d0c;
case 0x0c083d0eu: goto P_0c083d0e;
case 0x0c083d10u: goto P_0c083d10;
case 0x0c083d12u: goto P_0c083d12;
case 0x0c085cdcu: goto P_0c085cdc;
case 0x0c085cdeu: goto P_0c085cde;
case 0x0c085ce0u: goto P_0c085ce0;
case 0x0c085ce2u: goto P_0c085ce2;
case 0x0c085ce4u: goto P_0c085ce4;
case 0x0c085ce6u: goto P_0c085ce6;
case 0x0c085ce8u: goto P_0c085ce8;
case 0x0c085ceau: goto P_0c085cea;
case 0x0c085cecu: goto P_0c085cec;
case 0x0c085ceeu: goto P_0c085cee;
case 0x0c085cf0u: goto P_0c085cf0;
case 0x0c085cf2u: goto P_0c085cf2;
case 0x0c085cf4u: goto P_0c085cf4;
case 0x0c085cf6u: goto P_0c085cf6;
case 0x0c085cf8u: goto P_0c085cf8;
case 0x0c085cfau: goto P_0c085cfa;
case 0x0c085cfcu: goto P_0c085cfc;
case 0x0c085cfeu: goto P_0c085cfe;
case 0x0c085d00u: goto P_0c085d00;
case 0x0c085d02u: goto P_0c085d02;
case 0x0c085d04u: goto P_0c085d04;
case 0x0c085d06u: goto P_0c085d06;
case 0x0c085d08u: goto P_0c085d08;
case 0x0c085d0au: goto P_0c085d0a;
case 0x0c085d0cu: goto P_0c085d0c;
case 0x0c085d0eu: goto P_0c085d0e;
case 0x0c085d10u: goto P_0c085d10;
case 0x0c085d12u: goto P_0c085d12;
case 0x0c085d14u: goto P_0c085d14;
case 0x0c085d16u: goto P_0c085d16;
case 0x0c085d18u: goto P_0c085d18;
case 0x0c085d1au: goto P_0c085d1a;
case 0x0c085d1cu: goto P_0c085d1c;
case 0x0c085d1eu: goto P_0c085d1e;
case 0x0c085d20u: goto P_0c085d20;
case 0x0c085d22u: goto P_0c085d22;
case 0x0c085d24u: goto P_0c085d24;
case 0x0c085d26u: goto P_0c085d26;
case 0x0c085d28u: goto P_0c085d28;
case 0x0c085d2au: goto P_0c085d2a;
case 0x0c085d2cu: goto P_0c085d2c;
case 0x0c085d2eu: goto P_0c085d2e;
case 0x0c085d30u: goto P_0c085d30;
case 0x0c085d32u: goto P_0c085d32;
case 0x0c085d34u: goto P_0c085d34;
case 0x0c085d36u: goto P_0c085d36;
case 0x0c085d38u: goto P_0c085d38;
case 0x0c085d3au: goto P_0c085d3a;
case 0x0c085d3cu: goto P_0c085d3c;
case 0x0c085d3eu: goto P_0c085d3e;
case 0x0c085d40u: goto P_0c085d40;
case 0x0c085d42u: goto P_0c085d42;
case 0x0c085d44u: goto P_0c085d44;
case 0x0c085d46u: goto P_0c085d46;
case 0x0c085d48u: goto P_0c085d48;
case 0x0c085d4au: goto P_0c085d4a;
case 0x0c085d4cu: goto P_0c085d4c;
case 0x0c085d4eu: goto P_0c085d4e;
case 0x0c085d50u: goto P_0c085d50;
case 0x0c085d52u: goto P_0c085d52;
case 0x0c085d54u: goto P_0c085d54;
case 0x0c085d56u: goto P_0c085d56;
case 0x0c085d58u: goto P_0c085d58;
case 0x0c085d5au: goto P_0c085d5a;
case 0x0c085d5cu: goto P_0c085d5c;
case 0x0c085d7cu: goto P_0c085d7c;
case 0x0c085d7eu: goto P_0c085d7e;
case 0x0c085d80u: goto P_0c085d80;
case 0x0c085d82u: goto P_0c085d82;
case 0x0c085d84u: goto P_0c085d84;
case 0x0c085d86u: goto P_0c085d86;
case 0x0c085d88u: goto P_0c085d88;
case 0x0c085d8au: goto P_0c085d8a;
case 0x0c085d8cu: goto P_0c085d8c;
case 0x0c085d8eu: goto P_0c085d8e;
case 0x0c085d90u: goto P_0c085d90;
case 0x0c085d92u: goto P_0c085d92;
case 0x0c085d94u: goto P_0c085d94;
case 0x0c085d96u: goto P_0c085d96;
case 0x0c085d98u: goto P_0c085d98;
case 0x0c085d9au: goto P_0c085d9a;
case 0x0c085d9cu: goto P_0c085d9c;
case 0x0c085d9eu: goto P_0c085d9e;
case 0x0c085da0u: goto P_0c085da0;
case 0x0c085da2u: goto P_0c085da2;
case 0x0c085da4u: goto P_0c085da4;
case 0x0c085da6u: goto P_0c085da6;
case 0x0c085da8u: goto P_0c085da8;
case 0x0c085daau: goto P_0c085daa;
case 0x0c085dacu: goto P_0c085dac;
case 0x0c085daeu: goto P_0c085dae;
case 0x0c085db0u: goto P_0c085db0;
case 0x0c085db2u: goto P_0c085db2;
case 0x0c085db4u: goto P_0c085db4;
case 0x0c085db6u: goto P_0c085db6;
case 0x0c085db8u: goto P_0c085db8;
case 0x0c085dbau: goto P_0c085dba;
case 0x0c085dbcu: goto P_0c085dbc;
case 0x0c085dbeu: goto P_0c085dbe;
case 0x0c085dc0u: goto P_0c085dc0;
case 0x0c085dc2u: goto P_0c085dc2;
case 0x0c085dc4u: goto P_0c085dc4;
case 0x0c085dc6u: goto P_0c085dc6;
case 0x0c085dc8u: goto P_0c085dc8;
case 0x0c085dcau: goto P_0c085dca;
case 0x0c085dccu: goto P_0c085dcc;
case 0x0c085dceu: goto P_0c085dce;
case 0x0c085dd0u: goto P_0c085dd0;
case 0x0c085dd2u: goto P_0c085dd2;
case 0x0c085dd4u: goto P_0c085dd4;
case 0x0c085dd6u: goto P_0c085dd6;
case 0x0c085dd8u: goto P_0c085dd8;
case 0x0c085ddau: goto P_0c085dda;
case 0x0c085ddcu: goto P_0c085ddc;
case 0x0c085ddeu: goto P_0c085dde;
case 0x0c085de0u: goto P_0c085de0;
case 0x0c085de2u: goto P_0c085de2;
case 0x0c085de4u: goto P_0c085de4;
case 0x0c085de6u: goto P_0c085de6;
case 0x0c085de8u: goto P_0c085de8;
case 0x0c085deau: goto P_0c085dea;
case 0x0c085decu: goto P_0c085dec;
case 0x0c085deeu: goto P_0c085dee;
case 0x0c085df0u: goto P_0c085df0;
case 0x0c085df2u: goto P_0c085df2;
case 0x0c085df4u: goto P_0c085df4;
case 0x0c085df6u: goto P_0c085df6;
case 0x0c085df8u: goto P_0c085df8;
case 0x0c085dfau: goto P_0c085dfa;
case 0x0c085dfcu: goto P_0c085dfc;
case 0x0c085dfeu: goto P_0c085dfe;
case 0x0c085e00u: goto P_0c085e00;
case 0x0c085e02u: goto P_0c085e02;
case 0x0c085e04u: goto P_0c085e04;
case 0x0c085e06u: goto P_0c085e06;
case 0x0c085e08u: goto P_0c085e08;
case 0x0c085e0au: goto P_0c085e0a;
case 0x0c085e0cu: goto P_0c085e0c;
case 0x0c085e0eu: goto P_0c085e0e;
case 0x0c085e10u: goto P_0c085e10;
case 0x0c085e12u: goto P_0c085e12;
case 0x0c085e14u: goto P_0c085e14;
case 0x0c085e16u: goto P_0c085e16;
case 0x0c085e18u: goto P_0c085e18;
case 0x0c085e1au: goto P_0c085e1a;
case 0x0c085e1cu: goto P_0c085e1c;
case 0x0c085e1eu: goto P_0c085e1e;
case 0x0c085e20u: goto P_0c085e20;
case 0x0c085e22u: goto P_0c085e22;
case 0x0c085e24u: goto P_0c085e24;
case 0x0c085e26u: goto P_0c085e26;
case 0x0c085e28u: goto P_0c085e28;
case 0x0c085e2au: goto P_0c085e2a;
case 0x0c085e2cu: goto P_0c085e2c;
case 0x0c085e2eu: goto P_0c085e2e;
case 0x0c085e30u: goto P_0c085e30;
case 0x0c085f96u: goto P_0c085f96;
case 0x0c085f98u: goto P_0c085f98;
case 0x0c085f9au: goto P_0c085f9a;
case 0x0c085f9cu: goto P_0c085f9c;
case 0x0c085f9eu: goto P_0c085f9e;
case 0x0c085fa0u: goto P_0c085fa0;
case 0x0c085fa2u: goto P_0c085fa2;
case 0x0c085fa4u: goto P_0c085fa4;
case 0x0c085fa6u: goto P_0c085fa6;
case 0x0c085fa8u: goto P_0c085fa8;
case 0x0c085faau: goto P_0c085faa;
case 0x0c085facu: goto P_0c085fac;
case 0x0c085faeu: goto P_0c085fae;
case 0x0c085fb0u: goto P_0c085fb0;
case 0x0c085fb2u: goto P_0c085fb2;
case 0x0c085fb4u: goto P_0c085fb4;
case 0x0c085fb6u: goto P_0c085fb6;
case 0x0c085fb8u: goto P_0c085fb8;
case 0x0c085fbau: goto P_0c085fba;
case 0x0c085fbcu: goto P_0c085fbc;
case 0x0c085fbeu: goto P_0c085fbe;
case 0x0c085fc0u: goto P_0c085fc0;
case 0x0c085fc2u: goto P_0c085fc2;
case 0x0c085fc4u: goto P_0c085fc4;
case 0x0c085fc6u: goto P_0c085fc6;
case 0x0c085fc8u: goto P_0c085fc8;
case 0x0c085fcau: goto P_0c085fca;
case 0x0c085fccu: goto P_0c085fcc;
case 0x0c085fceu: goto P_0c085fce;
case 0x0c085fd0u: goto P_0c085fd0;
case 0x0c085fd2u: goto P_0c085fd2;
case 0x0c085fd4u: goto P_0c085fd4;
case 0x0c085fd6u: goto P_0c085fd6;
case 0x0c085fd8u: goto P_0c085fd8;
case 0x0c085fdau: goto P_0c085fda;
case 0x0c085fdcu: goto P_0c085fdc;
case 0x0c085fdeu: goto P_0c085fde;
case 0x0c085fe0u: goto P_0c085fe0;
case 0x0c085fe2u: goto P_0c085fe2;
case 0x0c085fe4u: goto P_0c085fe4;
case 0x0c085fe6u: goto P_0c085fe6;
case 0x0c085fe8u: goto P_0c085fe8;
case 0x0c085feau: goto P_0c085fea;
case 0x0c085fecu: goto P_0c085fec;
case 0x0c085feeu: goto P_0c085fee;
case 0x0c085ff0u: goto P_0c085ff0;
case 0x0c085ff2u: goto P_0c085ff2;
case 0x0c085ff4u: goto P_0c085ff4;
case 0x0c085ff6u: goto P_0c085ff6;
case 0x0c085ff8u: goto P_0c085ff8;
case 0x0c085ffau: goto P_0c085ffa;
case 0x0c085ffcu: goto P_0c085ffc;
case 0x0c085ffeu: goto P_0c085ffe;
case 0x0c086000u: goto P_0c086000;
case 0x0c086002u: goto P_0c086002;
case 0x0c086004u: goto P_0c086004;
case 0x0c086006u: goto P_0c086006;
case 0x0c086008u: goto P_0c086008;
case 0x0c08600au: goto P_0c08600a;
case 0x0c08600cu: goto P_0c08600c;
case 0x0c08600eu: goto P_0c08600e;
case 0x0c086010u: goto P_0c086010;
case 0x0c086012u: goto P_0c086012;
case 0x0c086014u: goto P_0c086014;
case 0x0c086016u: goto P_0c086016;
case 0x0c086018u: goto P_0c086018;
case 0x0c08601au: goto P_0c08601a;
case 0x0c08601cu: goto P_0c08601c;
case 0x0c08601eu: goto P_0c08601e;
case 0x0c086020u: goto P_0c086020;
case 0x0c086022u: goto P_0c086022;
case 0x0c086024u: goto P_0c086024;
case 0x0c086026u: goto P_0c086026;
case 0x0c086028u: goto P_0c086028;
case 0x0c08602au: goto P_0c08602a;
case 0x0c08602cu: goto P_0c08602c;
case 0x0c08602eu: goto P_0c08602e;
case 0x0c086030u: goto P_0c086030;
case 0x0c08605au: goto P_0c08605a;
case 0x0c08605cu: goto P_0c08605c;
case 0x0c08605eu: goto P_0c08605e;
case 0x0c086060u: goto P_0c086060;
case 0x0c086062u: goto P_0c086062;
case 0x0c086064u: goto P_0c086064;
case 0x0c086066u: goto P_0c086066;
case 0x0c086068u: goto P_0c086068;
case 0x0c08606au: goto P_0c08606a;
case 0x0c08606cu: goto P_0c08606c;
case 0x0c08606eu: goto P_0c08606e;
case 0x0c086070u: goto P_0c086070;
case 0x0c086072u: goto P_0c086072;
case 0x0c086074u: goto P_0c086074;
case 0x0c086076u: goto P_0c086076;
case 0x0c086078u: goto P_0c086078;
case 0x0c08607au: goto P_0c08607a;
case 0x0c08607cu: goto P_0c08607c;
case 0x0c08607eu: goto P_0c08607e;
case 0x0c086080u: goto P_0c086080;
case 0x0c086082u: goto P_0c086082;
case 0x0c086084u: goto P_0c086084;
case 0x0c08b648u: goto P_0c08b648;
case 0x0c08b64au: goto P_0c08b64a;
case 0x0c08b64cu: goto P_0c08b64c;
case 0x0c08b64eu: goto P_0c08b64e;
case 0x0c08b650u: goto P_0c08b650;
case 0x0c08b652u: goto P_0c08b652;
case 0x0c08b654u: goto P_0c08b654;
case 0x0c08b656u: goto P_0c08b656;
case 0x0c08b658u: goto P_0c08b658;
case 0x0c08b65au: goto P_0c08b65a;
case 0x0c08b65cu: goto P_0c08b65c;
case 0x0c08b65eu: goto P_0c08b65e;
case 0x0c08b660u: goto P_0c08b660;
case 0x0c08b662u: goto P_0c08b662;
case 0x0c08b668u: goto P_0c08b668;
case 0x0c08b66au: goto P_0c08b66a;
case 0x0c08b66cu: goto P_0c08b66c;
case 0x0c08b66eu: goto P_0c08b66e;
case 0x0c08b670u: goto P_0c08b670;
case 0x0c08b672u: goto P_0c08b672;
case 0x0c08b674u: goto P_0c08b674;
case 0x0c08b676u: goto P_0c08b676;
case 0x0c08b678u: goto P_0c08b678;
case 0x0c08b67au: goto P_0c08b67a;
case 0x0c08b67cu: goto P_0c08b67c;
case 0x0c08b67eu: goto P_0c08b67e;
case 0x0c08b680u: goto P_0c08b680;
case 0x0c08b682u: goto P_0c08b682;
case 0x0c090c8cu: goto P_0c090c8c;
case 0x0c090c8eu: goto P_0c090c8e;
case 0x0c090c90u: goto P_0c090c90;
case 0x0c090c92u: goto P_0c090c92;
case 0x0c09102au: goto P_0c09102a;
case 0x0c09102cu: goto P_0c09102c;
case 0x0c09102eu: goto P_0c09102e;
case 0x0c091030u: goto P_0c091030;
case 0x0c091032u: goto P_0c091032;
case 0x0c091034u: goto P_0c091034;
case 0x0c091036u: goto P_0c091036;
case 0x0c091038u: goto P_0c091038;
case 0x0c09103au: goto P_0c09103a;
case 0x0c09103cu: goto P_0c09103c;
case 0x0c09103eu: goto P_0c09103e;
case 0x0c091040u: goto P_0c091040;
case 0x0c091042u: goto P_0c091042;
case 0x0c091044u: goto P_0c091044;
case 0x0c091046u: goto P_0c091046;
case 0x0c091048u: goto P_0c091048;
case 0x0c09104au: goto P_0c09104a;
case 0x0c09104cu: goto P_0c09104c;
case 0x0c09104eu: goto P_0c09104e;
case 0x0c091050u: goto P_0c091050;
case 0x0c091052u: goto P_0c091052;
case 0x0c091054u: goto P_0c091054;
case 0x0c091056u: goto P_0c091056;
case 0x0c091058u: goto P_0c091058;
case 0x0c09105au: goto P_0c09105a;
case 0x0c09105cu: goto P_0c09105c;
case 0x0c09105eu: goto P_0c09105e;
case 0x0c091060u: goto P_0c091060;
case 0x0c091062u: goto P_0c091062;
case 0x0c091064u: goto P_0c091064;
case 0x0c091066u: goto P_0c091066;
case 0x0c091068u: goto P_0c091068;
case 0x0c09106au: goto P_0c09106a;
case 0x0c09106cu: goto P_0c09106c;
case 0x0c09106eu: goto P_0c09106e;
case 0x0c091070u: goto P_0c091070;
case 0x0c091072u: goto P_0c091072;
case 0x0c091074u: goto P_0c091074;
case 0x0c091076u: goto P_0c091076;
case 0x0c091078u: goto P_0c091078;
case 0x0c09107au: goto P_0c09107a;
case 0x0c09107cu: goto P_0c09107c;
case 0x0c09107eu: goto P_0c09107e;
case 0x0c091080u: goto P_0c091080;
case 0x0c09493cu: goto P_0c09493c;
case 0x0c09493eu: goto P_0c09493e;
case 0x0c094940u: goto P_0c094940;
case 0x0c094942u: goto P_0c094942;
case 0x0c094944u: goto P_0c094944;
case 0x0c094946u: goto P_0c094946;
case 0x0c094948u: goto P_0c094948;
case 0x0c09494au: goto P_0c09494a;
case 0x0c09494cu: goto P_0c09494c;
case 0x0c09494eu: goto P_0c09494e;
case 0x0c094950u: goto P_0c094950;
case 0x0c094952u: goto P_0c094952;
case 0x0c094954u: goto P_0c094954;
case 0x0c094956u: goto P_0c094956;
case 0x0c094958u: goto P_0c094958;
case 0x0c09495au: goto P_0c09495a;
case 0x0c09495cu: goto P_0c09495c;
case 0x0c09495eu: goto P_0c09495e;
case 0x0c094960u: goto P_0c094960;
case 0x0c094962u: goto P_0c094962;
case 0x0c094964u: goto P_0c094964;
case 0x0c094966u: goto P_0c094966;
case 0x0c094968u: goto P_0c094968;
case 0x0c09496au: goto P_0c09496a;
case 0x0c09496cu: goto P_0c09496c;
case 0x0c09496eu: goto P_0c09496e;
case 0x0c094970u: goto P_0c094970;
case 0x0c094972u: goto P_0c094972;
case 0x0c094974u: goto P_0c094974;
case 0x0c094976u: goto P_0c094976;
case 0x0c094978u: goto P_0c094978;
case 0x0c09497au: goto P_0c09497a;
case 0x0c09497cu: goto P_0c09497c;
case 0x0c09497eu: goto P_0c09497e;
case 0x0c094980u: goto P_0c094980;
case 0x0c094982u: goto P_0c094982;
case 0x0c094984u: goto P_0c094984;
case 0x0c094986u: goto P_0c094986;
case 0x0c094988u: goto P_0c094988;
case 0x0c09498au: goto P_0c09498a;
case 0x0c09498cu: goto P_0c09498c;
case 0x0c09498eu: goto P_0c09498e;
case 0x0c094990u: goto P_0c094990;
case 0x0c094992u: goto P_0c094992;
case 0x0c094994u: goto P_0c094994;
case 0x0c094996u: goto P_0c094996;
case 0x0c094998u: goto P_0c094998;
case 0x0c09499au: goto P_0c09499a;
case 0x0c09499cu: goto P_0c09499c;
case 0x0c09499eu: goto P_0c09499e;
case 0x0c0949a0u: goto P_0c0949a0;
case 0x0c0949a2u: goto P_0c0949a2;
case 0x0c0949a4u: goto P_0c0949a4;
case 0x0c0949a6u: goto P_0c0949a6;
case 0x0c0949a8u: goto P_0c0949a8;
case 0x0c0949aau: goto P_0c0949aa;
case 0x0c0949acu: goto P_0c0949ac;
case 0x0c0949aeu: goto P_0c0949ae;
case 0x0c0949b0u: goto P_0c0949b0;
case 0x0c0949b2u: goto P_0c0949b2;
case 0x0c0949b4u: goto P_0c0949b4;
case 0x0c0949b6u: goto P_0c0949b6;
case 0x0c0949b8u: goto P_0c0949b8;
case 0x0c0949bau: goto P_0c0949ba;
case 0x0c0949bcu: goto P_0c0949bc;
case 0x0c0949beu: goto P_0c0949be;
case 0x0c0949c0u: goto P_0c0949c0;
case 0x0c0949c2u: goto P_0c0949c2;
case 0x0c0949c4u: goto P_0c0949c4;
case 0x0c0949c6u: goto P_0c0949c6;
case 0x0c0949c8u: goto P_0c0949c8;
case 0x0c0949cau: goto P_0c0949ca;
case 0x0c0949ccu: goto P_0c0949cc;
case 0x0c0949ceu: goto P_0c0949ce;
case 0x0c0949d0u: goto P_0c0949d0;
case 0x0c0949d2u: goto P_0c0949d2;
case 0x0c0949d4u: goto P_0c0949d4;
case 0x0c0949d6u: goto P_0c0949d6;
case 0x0c0949d8u: goto P_0c0949d8;
case 0x0c0949dau: goto P_0c0949da;
case 0x0c0949dcu: goto P_0c0949dc;
case 0x0c0949deu: goto P_0c0949de;
case 0x0c0949e0u: goto P_0c0949e0;
case 0x0c0949e2u: goto P_0c0949e2;
case 0x0c0949e4u: goto P_0c0949e4;
case 0x0c0949e6u: goto P_0c0949e6;
case 0x0c0949e8u: goto P_0c0949e8;
case 0x0c0949eau: goto P_0c0949ea;
case 0x0c0949ecu: goto P_0c0949ec;
case 0x0c0949eeu: goto P_0c0949ee;
case 0x0c0949f0u: goto P_0c0949f0;
case 0x0c0949f2u: goto P_0c0949f2;
case 0x0c0949f4u: goto P_0c0949f4;
case 0x0c0949f6u: goto P_0c0949f6;
case 0x0c0949f8u: goto P_0c0949f8;
case 0x0c0949fau: goto P_0c0949fa;
case 0x0c0949fcu: goto P_0c0949fc;
case 0x0c0949feu: goto P_0c0949fe;
case 0x0c094a00u: goto P_0c094a00;
case 0x0c094a02u: goto P_0c094a02;
case 0x0c094a04u: goto P_0c094a04;
case 0x0c094a06u: goto P_0c094a06;
case 0x0c094a08u: goto P_0c094a08;
case 0x0c094a0au: goto P_0c094a0a;
case 0x0c094a0cu: goto P_0c094a0c;
case 0x0c094a0eu: goto P_0c094a0e;
case 0x0c094a10u: goto P_0c094a10;
case 0x0c094a12u: goto P_0c094a12;
case 0x0c094a14u: goto P_0c094a14;
case 0x0c094a16u: goto P_0c094a16;
case 0x0c094a18u: goto P_0c094a18;
case 0x0c094a1au: goto P_0c094a1a;
case 0x0c094a1cu: goto P_0c094a1c;
case 0x0c094a1eu: goto P_0c094a1e;
case 0x0c094a20u: goto P_0c094a20;
case 0x0c094a22u: goto P_0c094a22;
case 0x0c094a24u: goto P_0c094a24;
case 0x0c094a26u: goto P_0c094a26;
case 0x0c094a28u: goto P_0c094a28;
case 0x0c094a2au: goto P_0c094a2a;
case 0x0c094a2cu: goto P_0c094a2c;
case 0x0c094a2eu: goto P_0c094a2e;
case 0x0c094a30u: goto P_0c094a30;
case 0x0c094a32u: goto P_0c094a32;
case 0x0c094cccu: goto P_0c094ccc;
case 0x0c094cceu: goto P_0c094cce;
case 0x0c094cd0u: goto P_0c094cd0;
case 0x0c094cd2u: goto P_0c094cd2;
case 0x0c094cd4u: goto P_0c094cd4;
case 0x0c094cd6u: goto P_0c094cd6;
case 0x0c094cd8u: goto P_0c094cd8;
case 0x0c094cdau: goto P_0c094cda;
case 0x0c094cdcu: goto P_0c094cdc;
case 0x0c094cdeu: goto P_0c094cde;
case 0x0c094ce0u: goto P_0c094ce0;
case 0x0c094ce2u: goto P_0c094ce2;
case 0x0c094ce4u: goto P_0c094ce4;
case 0x0c094ce6u: goto P_0c094ce6;
case 0x0c094ce8u: goto P_0c094ce8;
case 0x0c094ceau: goto P_0c094cea;
case 0x0c094cecu: goto P_0c094cec;
case 0x0c094ceeu: goto P_0c094cee;
case 0x0c094cf0u: goto P_0c094cf0;
case 0x0c094cf2u: goto P_0c094cf2;
case 0x0c094cf4u: goto P_0c094cf4;
case 0x0c094cf6u: goto P_0c094cf6;
case 0x0c094cf8u: goto P_0c094cf8;
case 0x0c094cfau: goto P_0c094cfa;
case 0x0c094cfcu: goto P_0c094cfc;
case 0x0c094cfeu: goto P_0c094cfe;
case 0x0c094d00u: goto P_0c094d00;
case 0x0c094d02u: goto P_0c094d02;
case 0x0c094d04u: goto P_0c094d04;
case 0x0c094d06u: goto P_0c094d06;
case 0x0c094d08u: goto P_0c094d08;
case 0x0c094d0au: goto P_0c094d0a;
case 0x0c094d0cu: goto P_0c094d0c;
case 0x0c094d0eu: goto P_0c094d0e;
case 0x0c094d10u: goto P_0c094d10;
case 0x0c094d12u: goto P_0c094d12;
case 0x0c094d14u: goto P_0c094d14;
case 0x0c094d16u: goto P_0c094d16;
case 0x0c094d18u: goto P_0c094d18;
case 0x0c094d1au: goto P_0c094d1a;
case 0x0c094d1cu: goto P_0c094d1c;
case 0x0c094d1eu: goto P_0c094d1e;
case 0x0c094d20u: goto P_0c094d20;
case 0x0c094d22u: goto P_0c094d22;
case 0x0c094d24u: goto P_0c094d24;
case 0x0c094d26u: goto P_0c094d26;
case 0x0c094d28u: goto P_0c094d28;
case 0x0c094d2au: goto P_0c094d2a;
case 0x0c094d2cu: goto P_0c094d2c;
case 0x0c094d2eu: goto P_0c094d2e;
case 0x0c094d30u: goto P_0c094d30;
case 0x0c094d32u: goto P_0c094d32;
case 0x0c094d34u: goto P_0c094d34;
case 0x0c094d36u: goto P_0c094d36;
case 0x0c094d38u: goto P_0c094d38;
case 0x0c094d3au: goto P_0c094d3a;
case 0x0c094d3cu: goto P_0c094d3c;
case 0x0c094d3eu: goto P_0c094d3e;
case 0x0c094d40u: goto P_0c094d40;
case 0x0c094d42u: goto P_0c094d42;
case 0x0c094d44u: goto P_0c094d44;
case 0x0c094d46u: goto P_0c094d46;
case 0x0c094d48u: goto P_0c094d48;
case 0x0c094d4au: goto P_0c094d4a;
case 0x0c094d4cu: goto P_0c094d4c;
case 0x0c094d4eu: goto P_0c094d4e;
case 0x0c094d50u: goto P_0c094d50;
case 0x0c094d52u: goto P_0c094d52;
case 0x0c094d54u: goto P_0c094d54;
case 0x0c094d56u: goto P_0c094d56;
case 0x0c094d58u: goto P_0c094d58;
case 0x0c094d5au: goto P_0c094d5a;
case 0x0c094d5cu: goto P_0c094d5c;
case 0x0c094d5eu: goto P_0c094d5e;
case 0x0c094d60u: goto P_0c094d60;
case 0x0c094d62u: goto P_0c094d62;
case 0x0c094d64u: goto P_0c094d64;
case 0x0c094d66u: goto P_0c094d66;
case 0x0c094d68u: goto P_0c094d68;
case 0x0c094d6au: goto P_0c094d6a;
case 0x0c094d6cu: goto P_0c094d6c;
case 0x0c094d6eu: goto P_0c094d6e;
case 0x0c094d70u: goto P_0c094d70;
case 0x0c094d72u: goto P_0c094d72;
case 0x0c094d74u: goto P_0c094d74;
case 0x0c094d76u: goto P_0c094d76;
case 0x0c094d78u: goto P_0c094d78;
case 0x0c094d7au: goto P_0c094d7a;
case 0x0c094d7cu: goto P_0c094d7c;
case 0x0c094d7eu: goto P_0c094d7e;
case 0x0c094d80u: goto P_0c094d80;
case 0x0c094d82u: goto P_0c094d82;
case 0x0c094d84u: goto P_0c094d84;
case 0x0c094d86u: goto P_0c094d86;
case 0x0c094d88u: goto P_0c094d88;
case 0x0c094d8au: goto P_0c094d8a;
case 0x0c094d8cu: goto P_0c094d8c;
case 0x0c094d8eu: goto P_0c094d8e;
case 0x0c094d90u: goto P_0c094d90;
case 0x0c094d92u: goto P_0c094d92;
case 0x0c094d94u: goto P_0c094d94;
case 0x0c094d96u: goto P_0c094d96;
case 0x0c094d98u: goto P_0c094d98;
case 0x0c094d9au: goto P_0c094d9a;
case 0x0c094d9cu: goto P_0c094d9c;
case 0x0c09514au: goto P_0c09514a;
case 0x0c09514cu: goto P_0c09514c;
case 0x0c09514eu: goto P_0c09514e;
case 0x0c095150u: goto P_0c095150;
case 0x0c095152u: goto P_0c095152;
case 0x0c095154u: goto P_0c095154;
case 0x0c095156u: goto P_0c095156;
case 0x0c095158u: goto P_0c095158;
case 0x0c09515au: goto P_0c09515a;
case 0x0c09515cu: goto P_0c09515c;
case 0x0c09515eu: goto P_0c09515e;
case 0x0c095160u: goto P_0c095160;
case 0x0c095162u: goto P_0c095162;
case 0x0c095164u: goto P_0c095164;
case 0x0c095166u: goto P_0c095166;
case 0x0c095168u: goto P_0c095168;
case 0x0c09516au: goto P_0c09516a;
case 0x0c09516cu: goto P_0c09516c;
case 0x0c09516eu: goto P_0c09516e;
case 0x0c095170u: goto P_0c095170;
case 0x0c095172u: goto P_0c095172;
case 0x0c095174u: goto P_0c095174;
case 0x0c095176u: goto P_0c095176;
case 0x0c0a028au: goto P_0c0a028a;
case 0x0c0a028cu: goto P_0c0a028c;
case 0x0c0a028eu: goto P_0c0a028e;
case 0x0c0a0290u: goto P_0c0a0290;
case 0x0c0a0292u: goto P_0c0a0292;
case 0x0c0a0294u: goto P_0c0a0294;
case 0x0c0a0296u: goto P_0c0a0296;
case 0x0c0a0298u: goto P_0c0a0298;
case 0x0c0a029au: goto P_0c0a029a;
case 0x0c0a029cu: goto P_0c0a029c;
case 0x0c0a029eu: goto P_0c0a029e;
case 0x0c0a02a0u: goto P_0c0a02a0;
case 0x0c0a02a2u: goto P_0c0a02a2;
case 0x0c0a02a4u: goto P_0c0a02a4;
case 0x0c0a02a6u: goto P_0c0a02a6;
case 0x0c0a02a8u: goto P_0c0a02a8;
case 0x0c0a02aau: goto P_0c0a02aa;
case 0x0c0a02acu: goto P_0c0a02ac;
case 0x0c0a02aeu: goto P_0c0a02ae;
case 0x0c0a02b0u: goto P_0c0a02b0;
case 0x0c0a02b2u: goto P_0c0a02b2;
case 0x0c0a02b4u: goto P_0c0a02b4;
case 0x0c0a02b6u: goto P_0c0a02b6;
case 0x0c0a02b8u: goto P_0c0a02b8;
case 0x0c0a02bau: goto P_0c0a02ba;
case 0x0c0a02bcu: goto P_0c0a02bc;
case 0x0c0a02beu: goto P_0c0a02be;
case 0x0c0a02c0u: goto P_0c0a02c0;
case 0x0c0a02c2u: goto P_0c0a02c2;
case 0x0c0a02c4u: goto P_0c0a02c4;
case 0x0c0a02c6u: goto P_0c0a02c6;
case 0x0c0a02c8u: goto P_0c0a02c8;
case 0x0c0a02cau: goto P_0c0a02ca;
case 0x0c0a02ccu: goto P_0c0a02cc;
case 0x0c0a02ceu: goto P_0c0a02ce;
case 0x0c0a02d0u: goto P_0c0a02d0;
case 0x0c0a02d2u: goto P_0c0a02d2;
case 0x0c0a02d4u: goto P_0c0a02d4;
case 0x0c0a02d6u: goto P_0c0a02d6;
case 0x0c0a02d8u: goto P_0c0a02d8;
case 0x0c0a02dau: goto P_0c0a02da;
case 0x0c0a02dcu: goto P_0c0a02dc;
case 0x0c0a02deu: goto P_0c0a02de;
case 0x0c0a02e0u: goto P_0c0a02e0;
case 0x0c0a02e2u: goto P_0c0a02e2;
case 0x0c0a02e4u: goto P_0c0a02e4;
case 0x0c0a02e6u: goto P_0c0a02e6;
case 0x0c0a02e8u: goto P_0c0a02e8;
case 0x0c0a02eau: goto P_0c0a02ea;
case 0x0c0a02ecu: goto P_0c0a02ec;
case 0x0c0a02eeu: goto P_0c0a02ee;
case 0x0c0a02f0u: goto P_0c0a02f0;
case 0x0c0a02f2u: goto P_0c0a02f2;
case 0x0c0a02f4u: goto P_0c0a02f4;
case 0x0c0a02f6u: goto P_0c0a02f6;
case 0x0c0a02f8u: goto P_0c0a02f8;
case 0x0c0a02fau: goto P_0c0a02fa;
case 0x0c0a02fcu: goto P_0c0a02fc;
case 0x0c0a02feu: goto P_0c0a02fe;
case 0x0c0a0300u: goto P_0c0a0300;
case 0x0c0a0302u: goto P_0c0a0302;
case 0x0c0a0304u: goto P_0c0a0304;
case 0x0c0a0306u: goto P_0c0a0306;
case 0x0c0a0308u: goto P_0c0a0308;
case 0x0c0a030au: goto P_0c0a030a;
case 0x0c0a030cu: goto P_0c0a030c;
case 0x0c0a030eu: goto P_0c0a030e;
case 0x0c0a0310u: goto P_0c0a0310;
case 0x0c0a0312u: goto P_0c0a0312;
case 0x0c0a0314u: goto P_0c0a0314;
case 0x0c0a0316u: goto P_0c0a0316;
case 0x0c0a0318u: goto P_0c0a0318;
case 0x0c0a031au: goto P_0c0a031a;
case 0x0c0a031cu: goto P_0c0a031c;
case 0x0c0a031eu: goto P_0c0a031e;
case 0x0c0a0320u: goto P_0c0a0320;
case 0x0c0a0322u: goto P_0c0a0322;
case 0x0c0a0324u: goto P_0c0a0324;
case 0x0c0a0326u: goto P_0c0a0326;
case 0x0c0a0328u: goto P_0c0a0328;
case 0x0c0a032au: goto P_0c0a032a;
case 0x0c0a032cu: goto P_0c0a032c;
case 0x0c0a032eu: goto P_0c0a032e;
case 0x0c0a036cu: goto P_0c0a036c;
case 0x0c0a036eu: goto P_0c0a036e;
case 0x0c0a0370u: goto P_0c0a0370;
case 0x0c0a0372u: goto P_0c0a0372;
case 0x0c0a0374u: goto P_0c0a0374;
case 0x0c0a0376u: goto P_0c0a0376;
case 0x0c0a0378u: goto P_0c0a0378;
case 0x0c0a037au: goto P_0c0a037a;
case 0x0c0a037cu: goto P_0c0a037c;
case 0x0c0a037eu: goto P_0c0a037e;
case 0x0c0a0380u: goto P_0c0a0380;
case 0x0c0a0382u: goto P_0c0a0382;
case 0x0c0a0384u: goto P_0c0a0384;
case 0x0c0a0386u: goto P_0c0a0386;
case 0x0c0a0388u: goto P_0c0a0388;
case 0x0c0a038au: goto P_0c0a038a;
case 0x0c0a038cu: goto P_0c0a038c;
case 0x0c0a038eu: goto P_0c0a038e;
case 0x0c0a0390u: goto P_0c0a0390;
case 0x0c0a0392u: goto P_0c0a0392;
case 0x0c0a0394u: goto P_0c0a0394;
case 0x0c0a0396u: goto P_0c0a0396;
case 0x0c0a0398u: goto P_0c0a0398;
case 0x0c0a039au: goto P_0c0a039a;
case 0x0c0a039cu: goto P_0c0a039c;
case 0x0c0a039eu: goto P_0c0a039e;
case 0x0c0a03a0u: goto P_0c0a03a0;
case 0x0c0a03a2u: goto P_0c0a03a2;
case 0x0c0a03a4u: goto P_0c0a03a4;
case 0x0c0a03a6u: goto P_0c0a03a6;
case 0x0c0a03a8u: goto P_0c0a03a8;
case 0x0c0a03aau: goto P_0c0a03aa;
case 0x0c0a03acu: goto P_0c0a03ac;
case 0x0c0a03aeu: goto P_0c0a03ae;
case 0x0c0a03b0u: goto P_0c0a03b0;
case 0x0c0a03b2u: goto P_0c0a03b2;
case 0x0c0a03b4u: goto P_0c0a03b4;
case 0x0c0a03b6u: goto P_0c0a03b6;
case 0x0c0a03b8u: goto P_0c0a03b8;
case 0x0c0a03bau: goto P_0c0a03ba;
case 0x0c0a03bcu: goto P_0c0a03bc;
case 0x0c0a03beu: goto P_0c0a03be;
case 0x0c0a03c0u: goto P_0c0a03c0;
case 0x0c0a03c2u: goto P_0c0a03c2;
case 0x0c0a03c4u: goto P_0c0a03c4;
case 0x0c0a03c6u: goto P_0c0a03c6;
case 0x0c0a03c8u: goto P_0c0a03c8;
case 0x0c0a03cau: goto P_0c0a03ca;
case 0x0c0a03ccu: goto P_0c0a03cc;
case 0x0c0a03ceu: goto P_0c0a03ce;
case 0x0c0a03d0u: goto P_0c0a03d0;
case 0x0c0a03d2u: goto P_0c0a03d2;
case 0x0c0a03d4u: goto P_0c0a03d4;
case 0x0c0a03d6u: goto P_0c0a03d6;
case 0x0c0a03d8u: goto P_0c0a03d8;
case 0x0c0a03dau: goto P_0c0a03da;
case 0x0c0a03dcu: goto P_0c0a03dc;
case 0x0c0a03f0u: goto P_0c0a03f0;
case 0x0c0a03f2u: goto P_0c0a03f2;
case 0x0c0a03f4u: goto P_0c0a03f4;
case 0x0c0a03f6u: goto P_0c0a03f6;
case 0x0c0a03f8u: goto P_0c0a03f8;
case 0x0c0a03fau: goto P_0c0a03fa;
case 0x0c0a03fcu: goto P_0c0a03fc;
case 0x0c0a03feu: goto P_0c0a03fe;
case 0x0c0a0400u: goto P_0c0a0400;
case 0x0c0a0402u: goto P_0c0a0402;
case 0x0c0a0404u: goto P_0c0a0404;
case 0x0c0a0406u: goto P_0c0a0406;
case 0x0c0a0408u: goto P_0c0a0408;
case 0x0c0a040au: goto P_0c0a040a;
case 0x0c0a040cu: goto P_0c0a040c;
case 0x0c0a040eu: goto P_0c0a040e;
case 0x0c0a0410u: goto P_0c0a0410;
case 0x0c0a0412u: goto P_0c0a0412;
case 0x0c0a0414u: goto P_0c0a0414;
case 0x0c0a0416u: goto P_0c0a0416;
case 0x0c0a0418u: goto P_0c0a0418;
case 0x0c0a041au: goto P_0c0a041a;
case 0x0c0a041cu: goto P_0c0a041c;
case 0x0c0a058cu: goto P_0c0a058c;
case 0x0c0a058eu: goto P_0c0a058e;
case 0x0c0a0590u: goto P_0c0a0590;
case 0x0c0a0592u: goto P_0c0a0592;
case 0x0c0a0594u: goto P_0c0a0594;
case 0x0c0a0596u: goto P_0c0a0596;
case 0x0c0a0598u: goto P_0c0a0598;
case 0x0c0a059au: goto P_0c0a059a;
case 0x0c0a059cu: goto P_0c0a059c;
case 0x0c0a059eu: goto P_0c0a059e;
case 0x0c0a05a0u: goto P_0c0a05a0;
case 0x0c0a05a2u: goto P_0c0a05a2;
case 0x0c0a05a4u: goto P_0c0a05a4;
case 0x0c0a05a6u: goto P_0c0a05a6;
case 0x0c0a05a8u: goto P_0c0a05a8;
case 0x0c0a05aau: goto P_0c0a05aa;
case 0x0c0a05acu: goto P_0c0a05ac;
case 0x0c0a05aeu: goto P_0c0a05ae;
case 0x0c0a05b0u: goto P_0c0a05b0;
case 0x0c0a05b2u: goto P_0c0a05b2;
case 0x0c0a05b4u: goto P_0c0a05b4;
case 0x0c0a05b6u: goto P_0c0a05b6;
case 0x0c0a05b8u: goto P_0c0a05b8;
case 0x0c0a05bau: goto P_0c0a05ba;
case 0x0c0a05bcu: goto P_0c0a05bc;
case 0x0c0a05beu: goto P_0c0a05be;
case 0x0c0a05c0u: goto P_0c0a05c0;
case 0x0c0a05c2u: goto P_0c0a05c2;
case 0x0c0a05c4u: goto P_0c0a05c4;
case 0x0c0a05c6u: goto P_0c0a05c6;
case 0x0c0a05c8u: goto P_0c0a05c8;
case 0x0c0a05cau: goto P_0c0a05ca;
case 0x0c0a05ccu: goto P_0c0a05cc;
case 0x0c0a05fcu: goto P_0c0a05fc;
case 0x0c0a05feu: goto P_0c0a05fe;
case 0x0c0a0600u: goto P_0c0a0600;
case 0x0c0a0602u: goto P_0c0a0602;
case 0x0c0a0604u: goto P_0c0a0604;
case 0x0c0a0606u: goto P_0c0a0606;
case 0x0c0a0608u: goto P_0c0a0608;
case 0x0c0a060au: goto P_0c0a060a;
case 0x0c0a060cu: goto P_0c0a060c;
case 0x0c0a060eu: goto P_0c0a060e;
case 0x0c0a0610u: goto P_0c0a0610;
case 0x0c0a0612u: goto P_0c0a0612;
case 0x0c0a7784u: goto P_0c0a7784;
case 0x0c0a7786u: goto P_0c0a7786;
case 0x0c0a7788u: goto P_0c0a7788;
case 0x0c0a778au: goto P_0c0a778a;
case 0x0c0a778cu: goto P_0c0a778c;
case 0x0c0a778eu: goto P_0c0a778e;
case 0x0c0a7790u: goto P_0c0a7790;
case 0x0c0a7792u: goto P_0c0a7792;
case 0x0c0ad578u: goto P_0c0ad578;
case 0x0c0ad57au: goto P_0c0ad57a;
case 0x0c0ad57cu: goto P_0c0ad57c;
case 0x0c0ad57eu: goto P_0c0ad57e;
case 0x0c0ad580u: goto P_0c0ad580;
case 0x0c0ad582u: goto P_0c0ad582;
case 0x0c0ad584u: goto P_0c0ad584;
case 0x0c0ad586u: goto P_0c0ad586;
case 0x0c0ad588u: goto P_0c0ad588;
case 0x0c0adb86u: goto P_0c0adb86;
case 0x0c0adb88u: goto P_0c0adb88;
case 0x0c0adb8au: goto P_0c0adb8a;
case 0x0c0adb8cu: goto P_0c0adb8c;
case 0x0c0adb8eu: goto P_0c0adb8e;
case 0x0c0adb90u: goto P_0c0adb90;
case 0x0c0adb92u: goto P_0c0adb92;
case 0x0c0adb94u: goto P_0c0adb94;
case 0x0c0adb96u: goto P_0c0adb96;
case 0x0c0adb98u: goto P_0c0adb98;
case 0x0c0adb9au: goto P_0c0adb9a;
case 0x0c0adb9cu: goto P_0c0adb9c;
case 0x0c0adb9eu: goto P_0c0adb9e;
case 0x0c0adba0u: goto P_0c0adba0;
case 0x0c0adba2u: goto P_0c0adba2;
case 0x0c0adba4u: goto P_0c0adba4;
case 0x0c0adba6u: goto P_0c0adba6;
case 0x0c0adba8u: goto P_0c0adba8;
case 0x0c0adbaau: goto P_0c0adbaa;
case 0x0c0adbacu: goto P_0c0adbac;
case 0x0c0adbaeu: goto P_0c0adbae;
case 0x0c0adbb0u: goto P_0c0adbb0;
case 0x0c0adbb2u: goto P_0c0adbb2;
case 0x0c0adbb4u: goto P_0c0adbb4;
case 0x0c0adbb6u: goto P_0c0adbb6;
case 0x0c0adbb8u: goto P_0c0adbb8;
case 0x0c0adbbau: goto P_0c0adbba;
case 0x0c0adbbcu: goto P_0c0adbbc;
case 0x0c0adbbeu: goto P_0c0adbbe;
case 0x0c0adbc0u: goto P_0c0adbc0;
case 0x0c0adbc2u: goto P_0c0adbc2;
case 0x0c0adbc4u: goto P_0c0adbc4;
case 0x0c0adbc6u: goto P_0c0adbc6;
case 0x0c0adbc8u: goto P_0c0adbc8;
case 0x0c0adbcau: goto P_0c0adbca;
case 0x0c0adbccu: goto P_0c0adbcc;
case 0x0c0adbceu: goto P_0c0adbce;
case 0x0c0adbd0u: goto P_0c0adbd0;
case 0x0c0adbd2u: goto P_0c0adbd2;
case 0x0c0adbd4u: goto P_0c0adbd4;
case 0x0c0adc72u: goto P_0c0adc72;
case 0x0c0adc74u: goto P_0c0adc74;
case 0x0c0adc76u: goto P_0c0adc76;
case 0x0c0adc78u: goto P_0c0adc78;
case 0x0c0adc7au: goto P_0c0adc7a;
case 0x0c0adc7cu: goto P_0c0adc7c;
case 0x0c0adc7eu: goto P_0c0adc7e;
case 0x0c0adc80u: goto P_0c0adc80;
case 0x0c0adc82u: goto P_0c0adc82;
case 0x0c0adc84u: goto P_0c0adc84;
case 0x0c0adc86u: goto P_0c0adc86;
case 0x0c0adc88u: goto P_0c0adc88;
case 0x0c0adc8au: goto P_0c0adc8a;
case 0x0c0adc8cu: goto P_0c0adc8c;
case 0x0c0adc8eu: goto P_0c0adc8e;
case 0x0c0adc90u: goto P_0c0adc90;
case 0x0c0adc92u: goto P_0c0adc92;
case 0x0c0adc94u: goto P_0c0adc94;
case 0x0c0adc96u: goto P_0c0adc96;
case 0x0c0adc98u: goto P_0c0adc98;
case 0x0c0adc9au: goto P_0c0adc9a;
case 0x0c0adc9cu: goto P_0c0adc9c;
case 0x0c0adc9eu: goto P_0c0adc9e;
case 0x0c0adca0u: goto P_0c0adca0;
case 0x0c0adca2u: goto P_0c0adca2;
case 0x0c0adca4u: goto P_0c0adca4;
case 0x0c0adca6u: goto P_0c0adca6;
case 0x0c0adca8u: goto P_0c0adca8;
case 0x0c0adcaau: goto P_0c0adcaa;
case 0x0c0adcacu: goto P_0c0adcac;
case 0x0c0adcaeu: goto P_0c0adcae;
case 0x0c0adcb0u: goto P_0c0adcb0;
case 0x0c0adcb2u: goto P_0c0adcb2;
case 0x0c0adcb4u: goto P_0c0adcb4;
case 0x0c0adcb6u: goto P_0c0adcb6;
case 0x0c0adcb8u: goto P_0c0adcb8;
case 0x0c0adcbau: goto P_0c0adcba;
case 0x0c0adcbcu: goto P_0c0adcbc;
case 0x0c0adcbeu: goto P_0c0adcbe;
case 0x0c0adcc0u: goto P_0c0adcc0;
case 0x0c0adcc2u: goto P_0c0adcc2;
case 0x0c0adcc4u: goto P_0c0adcc4;
case 0x0c0adcc6u: goto P_0c0adcc6;
case 0x0c0adcc8u: goto P_0c0adcc8;
case 0x0c0adccau: goto P_0c0adcca;
case 0x0c0adcccu: goto P_0c0adccc;
case 0x0c0adcceu: goto P_0c0adcce;
case 0x0c0adcd0u: goto P_0c0adcd0;
case 0x0c0adcd2u: goto P_0c0adcd2;
case 0x0c0adcd4u: goto P_0c0adcd4;
case 0x0c0adcd6u: goto P_0c0adcd6;
case 0x0c0adcd8u: goto P_0c0adcd8;
case 0x0c0adcdau: goto P_0c0adcda;
case 0x0c0adcdcu: goto P_0c0adcdc;
case 0x0c0adcdeu: goto P_0c0adcde;
case 0x0c0adce0u: goto P_0c0adce0;
case 0x0c0adce2u: goto P_0c0adce2;
case 0x0c0adce4u: goto P_0c0adce4;
case 0x0c0adce6u: goto P_0c0adce6;
case 0x0c0adce8u: goto P_0c0adce8;
case 0x0c0adceau: goto P_0c0adcea;
case 0x0c0adcecu: goto P_0c0adcec;
case 0x0c0adceeu: goto P_0c0adcee;
case 0x0c0adcf0u: goto P_0c0adcf0;
case 0x0c0adcf2u: goto P_0c0adcf2;
case 0x0c0adcf4u: goto P_0c0adcf4;
case 0x0c0adcf6u: goto P_0c0adcf6;
case 0x0c0adcf8u: goto P_0c0adcf8;
case 0x0c0adcfau: goto P_0c0adcfa;
case 0x0c0adcfcu: goto P_0c0adcfc;
case 0x0c0adcfeu: goto P_0c0adcfe;
case 0x0c0add00u: goto P_0c0add00;
case 0x0c0add02u: goto P_0c0add02;
case 0x0c0add04u: goto P_0c0add04;
case 0x0c0add06u: goto P_0c0add06;
case 0x0c0add08u: goto P_0c0add08;
case 0x0c0add0au: goto P_0c0add0a;
case 0x0c0add0cu: goto P_0c0add0c;
case 0x0c0add0eu: goto P_0c0add0e;
case 0x0c0add10u: goto P_0c0add10;
case 0x0c0add12u: goto P_0c0add12;
case 0x0c0add14u: goto P_0c0add14;
case 0x0c0add16u: goto P_0c0add16;
case 0x0c0add18u: goto P_0c0add18;
case 0x0c0add1au: goto P_0c0add1a;
case 0x0c0add1cu: goto P_0c0add1c;
case 0x0c0add1eu: goto P_0c0add1e;
case 0x0c0add20u: goto P_0c0add20;
case 0x0c0add22u: goto P_0c0add22;
case 0x0c0add24u: goto P_0c0add24;
case 0x0c0adf70u: goto P_0c0adf70;
case 0x0c0adf72u: goto P_0c0adf72;
case 0x0c0adf74u: goto P_0c0adf74;
case 0x0c0adf76u: goto P_0c0adf76;
case 0x0c0adf78u: goto P_0c0adf78;
case 0x0c0adf7au: goto P_0c0adf7a;
case 0x0c0adf7cu: goto P_0c0adf7c;
case 0x0c0adf7eu: goto P_0c0adf7e;
case 0x0c0adf80u: goto P_0c0adf80;
case 0x0c0adf82u: goto P_0c0adf82;
case 0x0c0adf84u: goto P_0c0adf84;
case 0x0c0adf86u: goto P_0c0adf86;
case 0x0c0adf88u: goto P_0c0adf88;
case 0x0c0adf8au: goto P_0c0adf8a;
case 0x0c0adf8cu: goto P_0c0adf8c;
case 0x0c0adf8eu: goto P_0c0adf8e;
case 0x0c0adf90u: goto P_0c0adf90;
case 0x0c0adf92u: goto P_0c0adf92;
case 0x0c0adf94u: goto P_0c0adf94;
case 0x0c0adf96u: goto P_0c0adf96;
case 0x0c0adf98u: goto P_0c0adf98;
case 0x0c0adf9au: goto P_0c0adf9a;
case 0x0c0adf9cu: goto P_0c0adf9c;
case 0x0c0adf9eu: goto P_0c0adf9e;
case 0x0c0adfa0u: goto P_0c0adfa0;
case 0x0c0adfa2u: goto P_0c0adfa2;
case 0x0c0adfa4u: goto P_0c0adfa4;
case 0x0c0adfa6u: goto P_0c0adfa6;
case 0x0c0adfa8u: goto P_0c0adfa8;
case 0x0c0adfaau: goto P_0c0adfaa;
case 0x0c0adfacu: goto P_0c0adfac;
case 0x0c0adfaeu: goto P_0c0adfae;
case 0x0c0adfb0u: goto P_0c0adfb0;
case 0x0c0adfb2u: goto P_0c0adfb2;
case 0x0c0adfb4u: goto P_0c0adfb4;
case 0x0c0adfb6u: goto P_0c0adfb6;
case 0x0c0adfb8u: goto P_0c0adfb8;
case 0x0c0adfbau: goto P_0c0adfba;
case 0x0c0adfbcu: goto P_0c0adfbc;
case 0x0c0adfbeu: goto P_0c0adfbe;
case 0x0c0c18feu: goto P_0c0c18fe;
case 0x0c0c1900u: goto P_0c0c1900;
case 0x0c0c1902u: goto P_0c0c1902;
case 0x0c0c1904u: goto P_0c0c1904;
case 0x0c0c1906u: goto P_0c0c1906;
case 0x0c0c1908u: goto P_0c0c1908;
case 0x0c0c190au: goto P_0c0c190a;
case 0x0c0c190cu: goto P_0c0c190c;
case 0x0c0c190eu: goto P_0c0c190e;
case 0x0c0c1910u: goto P_0c0c1910;
case 0x0c0c1912u: goto P_0c0c1912;
case 0x0c0c1914u: goto P_0c0c1914;
case 0x0c0c1916u: goto P_0c0c1916;
case 0x0c0c1918u: goto P_0c0c1918;
case 0x0c0c191au: goto P_0c0c191a;
case 0x0c0c191cu: goto P_0c0c191c;
case 0x0c0c191eu: goto P_0c0c191e;
case 0x0c0c1920u: goto P_0c0c1920;
case 0x0c0c1922u: goto P_0c0c1922;
case 0x0c0c1924u: goto P_0c0c1924;
case 0x0c0c1926u: goto P_0c0c1926;
case 0x0c0c1928u: goto P_0c0c1928;
case 0x0c0c192au: goto P_0c0c192a;
case 0x0c0c192cu: goto P_0c0c192c;
case 0x0c0c192eu: goto P_0c0c192e;
case 0x0c0c1930u: goto P_0c0c1930;
case 0x0c0c1932u: goto P_0c0c1932;
case 0x0c0c1934u: goto P_0c0c1934;
case 0x0c0c1936u: goto P_0c0c1936;
case 0x0c0c1938u: goto P_0c0c1938;
case 0x0c0c193au: goto P_0c0c193a;
case 0x0c0c193cu: goto P_0c0c193c;
case 0x0c0c193eu: goto P_0c0c193e;
case 0x0c0c1940u: goto P_0c0c1940;
case 0x0c0c1942u: goto P_0c0c1942;
case 0x0c0c1944u: goto P_0c0c1944;
case 0x0c0c1946u: goto P_0c0c1946;
case 0x0c0c1948u: goto P_0c0c1948;
case 0x0c0c194au: goto P_0c0c194a;
case 0x0c0c194cu: goto P_0c0c194c;
case 0x0c0c194eu: goto P_0c0c194e;
case 0x0c0c1950u: goto P_0c0c1950;
case 0x0c0c1952u: goto P_0c0c1952;
case 0x0c0c1954u: goto P_0c0c1954;
case 0x0c0c1956u: goto P_0c0c1956;
case 0x0c0c1958u: goto P_0c0c1958;
case 0x0c0c195au: goto P_0c0c195a;
case 0x0c0c195cu: goto P_0c0c195c;
case 0x0c0c195eu: goto P_0c0c195e;
case 0x0c0c1960u: goto P_0c0c1960;
case 0x0c0c1962u: goto P_0c0c1962;
case 0x0c0c1964u: goto P_0c0c1964;
case 0x0c0c1966u: goto P_0c0c1966;
case 0x0c0c1968u: goto P_0c0c1968;
case 0x0c0c196au: goto P_0c0c196a;
case 0x0c0c196cu: goto P_0c0c196c;
case 0x0c0c196eu: goto P_0c0c196e;
case 0x0c0c1970u: goto P_0c0c1970;
case 0x0c0c1972u: goto P_0c0c1972;
case 0x0c0c1974u: goto P_0c0c1974;
case 0x0c0c1976u: goto P_0c0c1976;
case 0x0c0c1978u: goto P_0c0c1978;
case 0x0c0c197au: goto P_0c0c197a;
case 0x0c0c197cu: goto P_0c0c197c;
case 0x0c0c197eu: goto P_0c0c197e;
case 0x0c0c1980u: goto P_0c0c1980;
case 0x0c0c1982u: goto P_0c0c1982;
case 0x0c0c1984u: goto P_0c0c1984;
case 0x0c0c1986u: goto P_0c0c1986;
case 0x0c0c1988u: goto P_0c0c1988;
case 0x0c0c198au: goto P_0c0c198a;
case 0x0c0c198cu: goto P_0c0c198c;
case 0x0c0c198eu: goto P_0c0c198e;
case 0x0c0c1990u: goto P_0c0c1990;
case 0x0c0c1992u: goto P_0c0c1992;
case 0x0c0c1994u: goto P_0c0c1994;
case 0x0c0c1996u: goto P_0c0c1996;
case 0x0c0c1998u: goto P_0c0c1998;
case 0x0c0c199au: goto P_0c0c199a;
case 0x0c0c199cu: goto P_0c0c199c;
case 0x0c0c199eu: goto P_0c0c199e;
case 0x0c0c19a0u: goto P_0c0c19a0;
case 0x0c0c19a2u: goto P_0c0c19a2;
case 0x0c0c19a4u: goto P_0c0c19a4;
case 0x0c0c19a6u: goto P_0c0c19a6;
case 0x0c0c19a8u: goto P_0c0c19a8;
case 0x0c0c19aau: goto P_0c0c19aa;
case 0x0c0c19acu: goto P_0c0c19ac;
case 0x0c0c19aeu: goto P_0c0c19ae;
case 0x0c0c19b0u: goto P_0c0c19b0;
case 0x0c0c19b2u: goto P_0c0c19b2;
case 0x0c0c19b4u: goto P_0c0c19b4;
case 0x0c0c19b6u: goto P_0c0c19b6;
case 0x0c0c19b8u: goto P_0c0c19b8;
case 0x0c0c8d64u: goto P_0c0c8d64;
case 0x0c0c8d66u: goto P_0c0c8d66;
case 0x0c0c8d68u: goto P_0c0c8d68;
case 0x0c0c8d6au: goto P_0c0c8d6a;
case 0x0c0c8d6cu: goto P_0c0c8d6c;
case 0x0c0c8d6eu: goto P_0c0c8d6e;
case 0x0c0c8d70u: goto P_0c0c8d70;
case 0x0c0c8d72u: goto P_0c0c8d72;
case 0x0c0c8d74u: goto P_0c0c8d74;
case 0x0c0c8d76u: goto P_0c0c8d76;
case 0x0c0c8d78u: goto P_0c0c8d78;
case 0x0c0c8d7au: goto P_0c0c8d7a;
case 0x0c0c8d7cu: goto P_0c0c8d7c;
case 0x0c0c8d7eu: goto P_0c0c8d7e;
case 0x0c0c8d80u: goto P_0c0c8d80;
case 0x0c0c8d82u: goto P_0c0c8d82;
case 0x0c0c8d84u: goto P_0c0c8d84;
case 0x0c0c8d86u: goto P_0c0c8d86;
case 0x0c0c8d88u: goto P_0c0c8d88;
case 0x0c0c8d8au: goto P_0c0c8d8a;
case 0x0c0c8d8cu: goto P_0c0c8d8c;
case 0x0c0c9b94u: goto P_0c0c9b94;
case 0x0c0c9b96u: goto P_0c0c9b96;
case 0x0c0c9b98u: goto P_0c0c9b98;
case 0x0c0c9b9au: goto P_0c0c9b9a;
case 0x0c0c9b9cu: goto P_0c0c9b9c;
case 0x0c0c9b9eu: goto P_0c0c9b9e;
default: return vf3_matrix_family(target,s,ram);
}
P_0c042fa0: /* original 2f26, guest PC 0x0c042fa0 */
if(!s->budget--) { s->failed_pc=0x0c042fa0u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c042fa2;
P_0c042fa2: /* original 2f36, guest PC 0x0c042fa2 */
if(!s->budget--) { s->failed_pc=0x0c042fa2u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c042fa4;
P_0c042fa4: /* original 2f46, guest PC 0x0c042fa4 */
if(!s->budget--) { s->failed_pc=0x0c042fa4u; return 0; }
tmp=r[4]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c042fa6;
P_0c042fa6: /* original 8800, guest PC 0x0c042fa6 */
if(!s->budget--) { s->failed_pc=0x0c042fa6u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000000u)!=0);
goto P_0c042fa8;
P_0c042fa8: /* original 8d13, guest PC 0x0c042fa8 */
if(!s->budget--) { s->failed_pc=0x0c042fa8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c042fd2; }
goto P_0c042fac;
P_0c042faa: /* original 0009, guest PC 0x0c042faa */
if(!s->budget--) { s->failed_pc=0x0c042faau; return 0; }
goto P_0c042fac;
P_0c042fac: /* original 6423, guest PC 0x0c042fac */
if(!s->budget--) { s->failed_pc=0x0c042facu; return 0; }
r[4]=r[2];
goto P_0c042fae;
P_0c042fae: /* original 340c, guest PC 0x0c042fae */
if(!s->budget--) { s->failed_pc=0x0c042faeu; return 0; }
r[4]+=r[0];
goto P_0c042fb0;
P_0c042fb0: /* original 6024, guest PC 0x0c042fb0 */
if(!s->budget--) { s->failed_pc=0x0c042fb0u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[2],1);
r[2]+=1;
r[0]=tmp;
goto P_0c042fb2;
P_0c042fb2: /* original 2100, guest PC 0x0c042fb2 */
if(!s->budget--) { s->failed_pc=0x0c042fb2u; return 0; }
write(ram,r[1],r[0],1);
goto P_0c042fb4;
P_0c042fb4: /* original 3426, guest PC 0x0c042fb4 */
if(!s->budget--) { s->failed_pc=0x0c042fb4u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>r[2])!=0);
goto P_0c042fb6;
P_0c042fb6: /* original 8b0c, guest PC 0x0c042fb6 */
if(!s->budget--) { s->failed_pc=0x0c042fb6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c042fd2; }
goto P_0c042fb8;
P_0c042fb8: /* original 6024, guest PC 0x0c042fb8 */
if(!s->budget--) { s->failed_pc=0x0c042fb8u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[2],1);
r[2]+=1;
r[0]=tmp;
goto P_0c042fba;
P_0c042fba: /* original 8011, guest PC 0x0c042fba */
if(!s->budget--) { s->failed_pc=0x0c042fbau; return 0; }
write(ram,r[1]+1,r[0],1);
goto P_0c042fbc;
P_0c042fbc: /* original 3426, guest PC 0x0c042fbc */
if(!s->budget--) { s->failed_pc=0x0c042fbcu; return 0; }
r[17]=(r[17]&~1u)|((r[4]>r[2])!=0);
goto P_0c042fbe;
P_0c042fbe: /* original 8b08, guest PC 0x0c042fbe */
if(!s->budget--) { s->failed_pc=0x0c042fbeu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c042fd2; }
goto P_0c042fc0;
P_0c042fc0: /* original 6024, guest PC 0x0c042fc0 */
if(!s->budget--) { s->failed_pc=0x0c042fc0u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[2],1);
r[2]+=1;
r[0]=tmp;
goto P_0c042fc2;
P_0c042fc2: /* original 8012, guest PC 0x0c042fc2 */
if(!s->budget--) { s->failed_pc=0x0c042fc2u; return 0; }
write(ram,r[1]+2,r[0],1);
goto P_0c042fc4;
P_0c042fc4: /* original 3426, guest PC 0x0c042fc4 */
if(!s->budget--) { s->failed_pc=0x0c042fc4u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>r[2])!=0);
goto P_0c042fc6;
P_0c042fc6: /* original 8b04, guest PC 0x0c042fc6 */
if(!s->budget--) { s->failed_pc=0x0c042fc6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c042fd2; }
goto P_0c042fc8;
P_0c042fc8: /* original 6024, guest PC 0x0c042fc8 */
if(!s->budget--) { s->failed_pc=0x0c042fc8u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[2],1);
r[2]+=1;
r[0]=tmp;
goto P_0c042fca;
P_0c042fca: /* original 8013, guest PC 0x0c042fca */
if(!s->budget--) { s->failed_pc=0x0c042fcau; return 0; }
write(ram,r[1]+3,r[0],1);
goto P_0c042fcc;
P_0c042fcc: /* original 3426, guest PC 0x0c042fcc */
if(!s->budget--) { s->failed_pc=0x0c042fccu; return 0; }
r[17]=(r[17]&~1u)|((r[4]>r[2])!=0);
goto P_0c042fce;
P_0c042fce: /* original 7104, guest PC 0x0c042fce */
if(!s->budget--) { s->failed_pc=0x0c042fceu; return 0; }
r[1]+=0x00000004u;
goto P_0c042fd0;
P_0c042fd0: /* original 89ee, guest PC 0x0c042fd0 */
if(!s->budget--) { s->failed_pc=0x0c042fd0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c042fb0; }
goto P_0c042fd2;
P_0c042fd2: /* original 64f6, guest PC 0x0c042fd2 */
if(!s->budget--) { s->failed_pc=0x0c042fd2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[4]=tmp;
goto P_0c042fd4;
P_0c042fd4: /* original 63f6, guest PC 0x0c042fd4 */
if(!s->budget--) { s->failed_pc=0x0c042fd4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[3]=tmp;
goto P_0c042fd6;
P_0c042fd6: /* original 000b, guest PC 0x0c042fd6 */
if(!s->budget--) { s->failed_pc=0x0c042fd6u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[2]=tmp;
s->pc=target; return ram->oob==0;
P_0c042fd8: /* original 62f6, guest PC 0x0c042fd8 */
if(!s->budget--) { s->failed_pc=0x0c042fd8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[2]=tmp;
return vf3_matrix_family(0x0c042fdau,s,ram);
P_0c06233e: /* original d213, guest PC 0x0c06233e */
if(!s->budget--) { s->failed_pc=0x0c06233eu; return 0; }
r[2]=read(ram,0x0c06238cu,4);
goto P_0c062340;
P_0c062340: /* original 6322, guest PC 0x0c062340 */
if(!s->budget--) { s->failed_pc=0x0c062340u; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c062342;
P_0c062342: /* original 3433, guest PC 0x0c062342 */
if(!s->budget--) { s->failed_pc=0x0c062342u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[3])!=0);
goto P_0c062344;
P_0c062344: /* original 8d03, guest PC 0x0c062344 */
if(!s->budget--) { s->failed_pc=0x0c062344u; return 0; }
cond=r[17]&1u;
r[6]=0x00000000u;
if(cond) { goto P_0c06234e; }
goto P_0c062348;
P_0c062346: /* original e600, guest PC 0x0c062346 */
if(!s->budget--) { s->failed_pc=0x0c062346u; return 0; }
r[6]=0x00000000u;
goto P_0c062348;
P_0c062348: /* original e000, guest PC 0x0c062348 */
if(!s->budget--) { s->failed_pc=0x0c062348u; return 0; }
r[0]=0x00000000u;
goto P_0c06234a;
P_0c06234a: /* original a002, guest PC 0x0c06234a */
if(!s->budget--) { s->failed_pc=0x0c06234au; return 0; }
write(ram,r[5],r[0],2);
goto P_0c062352;
P_0c06234c: /* original 2501, guest PC 0x0c06234c */
if(!s->budget--) { s->failed_pc=0x0c06234cu; return 0; }
write(ram,r[5],r[0],2);
goto P_0c06234e;
P_0c06234e: /* original e101, guest PC 0x0c06234e */
if(!s->budget--) { s->failed_pc=0x0c06234eu; return 0; }
r[1]=0x00000001u;
goto P_0c062350;
P_0c062350: /* original 2511, guest PC 0x0c062350 */
if(!s->budget--) { s->failed_pc=0x0c062350u; return 0; }
write(ram,r[5],r[1],2);
goto P_0c062352;
P_0c062352: /* original 6350, guest PC 0x0c062352 */
if(!s->budget--) { s->failed_pc=0x0c062352u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[5],1);
r[3]=tmp;
goto P_0c062354;
P_0c062354: /* original d00b, guest PC 0x0c062354 */
if(!s->budget--) { s->failed_pc=0x0c062354u; return 0; }
r[0]=read(ram,0x0c062384u,4);
goto P_0c062356;
P_0c062356: /* original 6233, guest PC 0x0c062356 */
if(!s->budget--) { s->failed_pc=0x0c062356u; return 0; }
r[2]=r[3];
goto P_0c062358;
P_0c062358: /* original 4308, guest PC 0x0c062358 */
if(!s->budget--) { s->failed_pc=0x0c062358u; return 0; }
r[3]<<=2;
goto P_0c06235a;
P_0c06235a: /* original 332c, guest PC 0x0c06235a */
if(!s->budget--) { s->failed_pc=0x0c06235au; return 0; }
r[3]+=r[2];
goto P_0c06235c;
P_0c06235c: /* original 4308, guest PC 0x0c06235c */
if(!s->budget--) { s->failed_pc=0x0c06235cu; return 0; }
r[3]<<=2;
goto P_0c06235e;
P_0c06235e: /* original 633e, guest PC 0x0c06235e */
if(!s->budget--) { s->failed_pc=0x0c06235eu; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)r[3];
goto P_0c062360;
P_0c062360: /* original 053e, guest PC 0x0c062360 */
if(!s->budget--) { s->failed_pc=0x0c062360u; return 0; }
r[5]=read(ram,r[3]+r[0],4);
goto P_0c062362;
P_0c062362: /* original 2558, guest PC 0x0c062362 */
if(!s->budget--) { s->failed_pc=0x0c062362u; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[5])==0)!=0);
goto P_0c062364;
P_0c062364: /* original 8908, guest PC 0x0c062364 */
if(!s->budget--) { s->failed_pc=0x0c062364u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c062378; }
goto P_0c062366;
P_0c062366: /* original 5153, guest PC 0x0c062366 */
if(!s->budget--) { s->failed_pc=0x0c062366u; return 0; }
r[1]=read(ram,r[5]+12,4);
goto P_0c062368;
P_0c062368: /* original 3140, guest PC 0x0c062368 */
if(!s->budget--) { s->failed_pc=0x0c062368u; return 0; }
r[17]=(r[17]&~1u)|((r[1]==r[4])!=0);
goto P_0c06236a;
P_0c06236a: /* original 8b02, guest PC 0x0c06236a */
if(!s->budget--) { s->failed_pc=0x0c06236au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c062372; }
goto P_0c06236c;
P_0c06236c: /* original 6653, guest PC 0x0c06236c */
if(!s->budget--) { s->failed_pc=0x0c06236cu; return 0; }
r[6]=r[5];
goto P_0c06236e;
P_0c06236e: /* original a001, guest PC 0x0c06236e */
if(!s->budget--) { s->failed_pc=0x0c06236eu; return 0; }
r[5]=0x00000000u;
goto P_0c062374;
P_0c062370: /* original e500, guest PC 0x0c062370 */
if(!s->budget--) { s->failed_pc=0x0c062370u; return 0; }
r[5]=0x00000000u;
goto P_0c062372;
P_0c062372: /* original 5552, guest PC 0x0c062372 */
if(!s->budget--) { s->failed_pc=0x0c062372u; return 0; }
r[5]=read(ram,r[5]+8,4);
goto P_0c062374;
P_0c062374: /* original 2558, guest PC 0x0c062374 */
if(!s->budget--) { s->failed_pc=0x0c062374u; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[5])==0)!=0);
goto P_0c062376;
P_0c062376: /* original 8bf6, guest PC 0x0c062376 */
if(!s->budget--) { s->failed_pc=0x0c062376u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c062366; }
goto P_0c062378;
P_0c062378: /* original 000b, guest PC 0x0c062378 */
if(!s->budget--) { s->failed_pc=0x0c062378u; return 0; }
target=r[16];
r[0]=r[6];
s->pc=target; return ram->oob==0;
P_0c06237a: /* original 6063, guest PC 0x0c06237a */
if(!s->budget--) { s->failed_pc=0x0c06237au; return 0; }
r[0]=r[6];
return vf3_matrix_family(0x0c06237cu,s,ram);
P_0c07ac28: /* original 2fe6, guest PC 0x0c07ac28 */
if(!s->budget--) { s->failed_pc=0x0c07ac28u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07ac2a;
P_0c07ac2a: /* original 2fd6, guest PC 0x0c07ac2a */
if(!s->budget--) { s->failed_pc=0x0c07ac2au; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07ac2c;
P_0c07ac2c: /* original 6d53, guest PC 0x0c07ac2c */
if(!s->budget--) { s->failed_pc=0x0c07ac2cu; return 0; }
r[13]=r[5];
goto P_0c07ac2e;
P_0c07ac2e: /* original 4f22, guest PC 0x0c07ac2e */
if(!s->budget--) { s->failed_pc=0x0c07ac2eu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c07ac30;
P_0c07ac30: /* original 7ffc, guest PC 0x0c07ac30 */
if(!s->budget--) { s->failed_pc=0x0c07ac30u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c07ac32;
P_0c07ac32: /* original 2f41, guest PC 0x0c07ac32 */
if(!s->budget--) { s->failed_pc=0x0c07ac32u; return 0; }
write(ram,r[15],r[4],2);
goto P_0c07ac34;
P_0c07ac34: /* original 6ef1, guest PC 0x0c07ac34 */
if(!s->budget--) { s->failed_pc=0x0c07ac34u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[15],2);
r[14]=tmp;
goto P_0c07ac36;
P_0c07ac36: /* original d32e, guest PC 0x0c07ac36 */
if(!s->budget--) { s->failed_pc=0x0c07ac36u; return 0; }
r[3]=read(ram,0x0c07acf0u,4);
goto P_0c07ac38;
P_0c07ac38: /* original 6eed, guest PC 0x0c07ac38 */
if(!s->budget--) { s->failed_pc=0x0c07ac38u; return 0; }
r[14]=r[14]&65535u;
goto P_0c07ac3a;
P_0c07ac3a: /* original 430b, guest PC 0x0c07ac3a */
if(!s->budget--) { s->failed_pc=0x0c07ac3au; return 0; }
target=r[3];
r[16]=0x0c07ac3eu;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07ac3eu) { target=s->pc; goto dispatch; }
goto P_0c07ac3e;
P_0c07ac3c: /* original 64e3, guest PC 0x0c07ac3c */
if(!s->budget--) { s->failed_pc=0x0c07ac3cu; return 0; }
r[4]=r[14];
goto P_0c07ac3e;
P_0c07ac3e: /* original 60e3, guest PC 0x0c07ac3e */
if(!s->budget--) { s->failed_pc=0x0c07ac3eu; return 0; }
r[0]=r[14];
goto P_0c07ac40;
P_0c07ac40: /* original 8838, guest PC 0x0c07ac40 */
if(!s->budget--) { s->failed_pc=0x0c07ac40u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000038u)!=0);
goto P_0c07ac42;
P_0c07ac42: /* original 8b02, guest PC 0x0c07ac42 */
if(!s->budget--) { s->failed_pc=0x0c07ac42u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07ac4a; }
goto P_0c07ac44;
P_0c07ac44: /* original d42b, guest PC 0x0c07ac44 */
if(!s->budget--) { s->failed_pc=0x0c07ac44u; return 0; }
r[4]=read(ram,0x0c07acf4u,4);
goto P_0c07ac46;
P_0c07ac46: /* original a002, guest PC 0x0c07ac46 */
if(!s->budget--) { s->failed_pc=0x0c07ac46u; return 0; }
r[5]=r[13];
goto P_0c07ac4e;
P_0c07ac48: /* original 65d3, guest PC 0x0c07ac48 */
if(!s->budget--) { s->failed_pc=0x0c07ac48u; return 0; }
r[5]=r[13];
goto P_0c07ac4a;
P_0c07ac4a: /* original d42b, guest PC 0x0c07ac4a */
if(!s->budget--) { s->failed_pc=0x0c07ac4au; return 0; }
r[4]=read(ram,0x0c07acf8u,4);
goto P_0c07ac4c;
P_0c07ac4c: /* original 65d3, guest PC 0x0c07ac4c */
if(!s->budget--) { s->failed_pc=0x0c07ac4cu; return 0; }
r[5]=r[13];
goto P_0c07ac4e;
P_0c07ac4e: /* original bdda, guest PC 0x0c07ac4e */
if(!s->budget--) { s->failed_pc=0x0c07ac4eu; return 0; }
target=0x0c07a806u; r[16]=0x0c07ac52u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07ac52u) { target=s->pc; goto dispatch; }
goto P_0c07ac52;
P_0c07ac50: /* original 0009, guest PC 0x0c07ac50 */
if(!s->budget--) { s->failed_pc=0x0c07ac50u; return 0; }
goto P_0c07ac52;
P_0c07ac52: /* original 60f1, guest PC 0x0c07ac52 */
if(!s->budget--) { s->failed_pc=0x0c07ac52u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[15],2);
r[0]=tmp;
goto P_0c07ac54;
P_0c07ac54: /* original 7f04, guest PC 0x0c07ac54 */
if(!s->budget--) { s->failed_pc=0x0c07ac54u; return 0; }
r[15]+=0x00000004u;
goto P_0c07ac56;
P_0c07ac56: /* original 4f26, guest PC 0x0c07ac56 */
if(!s->budget--) { s->failed_pc=0x0c07ac56u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c07ac58;
P_0c07ac58: /* original d423, guest PC 0x0c07ac58 */
if(!s->budget--) { s->failed_pc=0x0c07ac58u; return 0; }
r[4]=read(ram,0x0c07ace8u,4);
goto P_0c07ac5a;
P_0c07ac5a: /* original 600d, guest PC 0x0c07ac5a */
if(!s->budget--) { s->failed_pc=0x0c07ac5au; return 0; }
r[0]=r[0]&65535u;
goto P_0c07ac5c;
P_0c07ac5c: /* original 4000, guest PC 0x0c07ac5c */
if(!s->budget--) { s->failed_pc=0x0c07ac5cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c07ac5e;
P_0c07ac5e: /* original 04e5, guest PC 0x0c07ac5e */
if(!s->budget--) { s->failed_pc=0x0c07ac5eu; return 0; }
write(ram,r[4]+r[0],r[14],2);
goto P_0c07ac60;
P_0c07ac60: /* original 60e3, guest PC 0x0c07ac60 */
if(!s->budget--) { s->failed_pc=0x0c07ac60u; return 0; }
r[0]=r[14];
goto P_0c07ac62;
P_0c07ac62: /* original 8147, guest PC 0x0c07ac62 */
if(!s->budget--) { s->failed_pc=0x0c07ac62u; return 0; }
write(ram,r[4]+14,r[0],2);
goto P_0c07ac64;
P_0c07ac64: /* original 6df6, guest PC 0x0c07ac64 */
if(!s->budget--) { s->failed_pc=0x0c07ac64u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c07ac66;
P_0c07ac66: /* original 000b, guest PC 0x0c07ac66 */
if(!s->budget--) { s->failed_pc=0x0c07ac66u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c07ac68: /* original 6ef6, guest PC 0x0c07ac68 */
if(!s->budget--) { s->failed_pc=0x0c07ac68u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c07ac6au,s,ram);
P_0c07ac6e: /* original 4f22, guest PC 0x0c07ac6e */
if(!s->budget--) { s->failed_pc=0x0c07ac6eu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c07ac70;
P_0c07ac70: /* original 5341, guest PC 0x0c07ac70 */
if(!s->budget--) { s->failed_pc=0x0c07ac70u; return 0; }
r[3]=read(ram,r[4]+4,4);
goto P_0c07ac72;
P_0c07ac72: /* original 7ffc, guest PC 0x0c07ac72 */
if(!s->budget--) { s->failed_pc=0x0c07ac72u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c07ac74;
P_0c07ac74: /* original 2f32, guest PC 0x0c07ac74 */
if(!s->budget--) { s->failed_pc=0x0c07ac74u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c07ac76;
P_0c07ac76: /* original 8d05, guest PC 0x0c07ac76 */
if(!s->budget--) { s->failed_pc=0x0c07ac76u; return 0; }
cond=r[17]&1u;
r[14]=read(ram,r[4]+24,4);
if(cond) { goto P_0c07ac84; }
goto P_0c07ac7a;
P_0c07ac78: /* original 5e46, guest PC 0x0c07ac78 */
if(!s->budget--) { s->failed_pc=0x0c07ac78u; return 0; }
r[14]=read(ram,r[4]+24,4);
goto P_0c07ac7a;
P_0c07ac7a: /* original d01b, guest PC 0x0c07ac7a */
if(!s->budget--) { s->failed_pc=0x0c07ac7au; return 0; }
r[0]=read(ram,0x0c07ace8u,4);
goto P_0c07ac7c;
P_0c07ac7c: /* original e200, guest PC 0x0c07ac7c */
if(!s->budget--) { s->failed_pc=0x0c07ac7cu; return 0; }
r[2]=0x00000000u;
goto P_0c07ac7e;
P_0c07ac7e: /* original 4e00, guest PC 0x0c07ac7e */
if(!s->budget--) { s->failed_pc=0x0c07ac7eu; return 0; }
r[17]=(r[17]&~1u)|((r[14]>>31)!=0);
r[14]<<=1;
goto P_0c07ac80;
P_0c07ac80: /* original a003, guest PC 0x0c07ac80 */
if(!s->budget--) { s->failed_pc=0x0c07ac80u; return 0; }
write(ram,r[14]+r[0],r[2],2);
goto P_0c07ac8a;
P_0c07ac82: /* original 0e25, guest PC 0x0c07ac82 */
if(!s->budget--) { s->failed_pc=0x0c07ac82u; return 0; }
write(ram,r[14]+r[0],r[2],2);
goto P_0c07ac84;
P_0c07ac84: /* original 65f2, guest PC 0x0c07ac84 */
if(!s->budget--) { s->failed_pc=0x0c07ac84u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c07ac86;
P_0c07ac86: /* original bfcf, guest PC 0x0c07ac86 */
if(!s->budget--) { s->failed_pc=0x0c07ac86u; return 0; }
target=0x0c07ac28u; r[16]=0x0c07ac8au;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07ac8au) { target=s->pc; goto dispatch; }
goto P_0c07ac8a;
P_0c07ac88: /* original 64e3, guest PC 0x0c07ac88 */
if(!s->budget--) { s->failed_pc=0x0c07ac88u; return 0; }
r[4]=r[14];
goto P_0c07ac8a;
P_0c07ac8a: /* original 7f04, guest PC 0x0c07ac8a */
if(!s->budget--) { s->failed_pc=0x0c07ac8au; return 0; }
r[15]+=0x00000004u;
goto P_0c07ac8c;
P_0c07ac8c: /* original 4f26, guest PC 0x0c07ac8c */
if(!s->budget--) { s->failed_pc=0x0c07ac8cu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c07ac8e;
P_0c07ac8e: /* original e000, guest PC 0x0c07ac8e */
if(!s->budget--) { s->failed_pc=0x0c07ac8eu; return 0; }
r[0]=0x00000000u;
goto P_0c07ac90;
P_0c07ac90: /* original 000b, guest PC 0x0c07ac90 */
if(!s->budget--) { s->failed_pc=0x0c07ac90u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c07ac92: /* original 6ef6, guest PC 0x0c07ac92 */
if(!s->budget--) { s->failed_pc=0x0c07ac92u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c07ac94u,s,ram);
P_0c07ad12: /* original 4f22, guest PC 0x0c07ad12 */
if(!s->budget--) { s->failed_pc=0x0c07ad12u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c07ad14;
P_0c07ad14: /* original 7ff8, guest PC 0x0c07ad14 */
if(!s->budget--) { s->failed_pc=0x0c07ad14u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c07ad16;
P_0c07ad16: /* original 2f51, guest PC 0x0c07ad16 */
if(!s->budget--) { s->failed_pc=0x0c07ad16u; return 0; }
write(ram,r[15],r[5],2);
goto P_0c07ad18;
P_0c07ad18: /* original d23d, guest PC 0x0c07ad18 */
if(!s->budget--) { s->failed_pc=0x0c07ad18u; return 0; }
r[2]=read(ram,0x0c07ae10u,4);
goto P_0c07ad1a;
P_0c07ad1a: /* original 6322, guest PC 0x0c07ad1a */
if(!s->budget--) { s->failed_pc=0x0c07ad1au; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c07ad1c;
P_0c07ad1c: /* original 1f31, guest PC 0x0c07ad1c */
if(!s->budget--) { s->failed_pc=0x0c07ad1cu; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c07ad1e;
P_0c07ad1e: /* original b447, guest PC 0x0c07ad1e */
if(!s->budget--) { s->failed_pc=0x0c07ad1eu; return 0; }
target=0x0c07b5b0u; r[16]=0x0c07ad22u;
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[15],2);
r[4]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07ad22u) { target=s->pc; goto dispatch; }
goto P_0c07ad22;
P_0c07ad20: /* original 64f1, guest PC 0x0c07ad20 */
if(!s->budget--) { s->failed_pc=0x0c07ad20u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[15],2);
r[4]=tmp;
goto P_0c07ad22;
P_0c07ad22: /* original 6e03, guest PC 0x0c07ad22 */
if(!s->budget--) { s->failed_pc=0x0c07ad22u; return 0; }
r[14]=r[0];
goto P_0c07ad24;
P_0c07ad24: /* original d03b, guest PC 0x0c07ad24 */
if(!s->budget--) { s->failed_pc=0x0c07ad24u; return 0; }
r[0]=read(ram,0x0c07ae14u,4);
goto P_0c07ad26;
P_0c07ad26: /* original 62ed, guest PC 0x0c07ad26 */
if(!s->budget--) { s->failed_pc=0x0c07ad26u; return 0; }
r[2]=r[14]&65535u;
goto P_0c07ad28;
P_0c07ad28: /* original 4200, guest PC 0x0c07ad28 */
if(!s->budget--) { s->failed_pc=0x0c07ad28u; return 0; }
r[17]=(r[17]&~1u)|((r[2]>>31)!=0);
r[2]<<=1;
goto P_0c07ad2a;
P_0c07ad2a: /* original 032d, guest PC 0x0c07ad2a */
if(!s->budget--) { s->failed_pc=0x0c07ad2au; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[2]+r[0],2);
goto P_0c07ad2c;
P_0c07ad2c: /* original 633d, guest PC 0x0c07ad2c */
if(!s->budget--) { s->failed_pc=0x0c07ad2cu; return 0; }
r[3]=r[3]&65535u;
goto P_0c07ad2e;
P_0c07ad2e: /* original 2338, guest PC 0x0c07ad2e */
if(!s->budget--) { s->failed_pc=0x0c07ad2eu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c07ad30;
P_0c07ad30: /* original 8b0e, guest PC 0x0c07ad30 */
if(!s->budget--) { s->failed_pc=0x0c07ad30u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07ad50; }
goto P_0c07ad32;
P_0c07ad32: /* original d137, guest PC 0x0c07ad32 */
if(!s->budget--) { s->failed_pc=0x0c07ad32u; return 0; }
r[1]=read(ram,0x0c07ae10u,4);
goto P_0c07ad34;
P_0c07ad34: /* original 64ed, guest PC 0x0c07ad34 */
if(!s->budget--) { s->failed_pc=0x0c07ad34u; return 0; }
r[4]=r[14]&65535u;
goto P_0c07ad36;
P_0c07ad36: /* original d038, guest PC 0x0c07ad36 */
if(!s->budget--) { s->failed_pc=0x0c07ad36u; return 0; }
r[0]=read(ram,0x0c07ae18u,4);
goto P_0c07ad38;
P_0c07ad38: /* original 74c8, guest PC 0x0c07ad38 */
if(!s->budget--) { s->failed_pc=0x0c07ad38u; return 0; }
r[4]+=0xffffffc8u;
goto P_0c07ad3a;
P_0c07ad3a: /* original d338, guest PC 0x0c07ad3a */
if(!s->budget--) { s->failed_pc=0x0c07ad3au; return 0; }
r[3]=read(ram,0x0c07ae1cu,4);
goto P_0c07ad3c;
P_0c07ad3c: /* original 4408, guest PC 0x0c07ad3c */
if(!s->budget--) { s->failed_pc=0x0c07ad3cu; return 0; }
r[4]<<=2;
goto P_0c07ad3e;
P_0c07ad3e: /* original 6512, guest PC 0x0c07ad3e */
if(!s->budget--) { s->failed_pc=0x0c07ad3eu; return 0; }
tmp=read(ram,r[1],4);
r[5]=tmp;
goto P_0c07ad40;
P_0c07ad40: /* original 430b, guest PC 0x0c07ad40 */
if(!s->budget--) { s->failed_pc=0x0c07ad40u; return 0; }
target=r[3];
r[16]=0x0c07ad44u;
r[4]=read(ram,r[4]+r[0],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07ad44u) { target=s->pc; goto dispatch; }
goto P_0c07ad44;
P_0c07ad42: /* original 044e, guest PC 0x0c07ad42 */
if(!s->budget--) { s->failed_pc=0x0c07ad42u; return 0; }
r[4]=read(ram,r[4]+r[0],4);
goto P_0c07ad44;
P_0c07ad44: /* original 55f1, guest PC 0x0c07ad44 */
if(!s->budget--) { s->failed_pc=0x0c07ad44u; return 0; }
r[5]=read(ram,r[15]+4,4);
goto P_0c07ad46;
P_0c07ad46: /* original 7f08, guest PC 0x0c07ad46 */
if(!s->budget--) { s->failed_pc=0x0c07ad46u; return 0; }
r[15]+=0x00000008u;
goto P_0c07ad48;
P_0c07ad48: /* original 4f26, guest PC 0x0c07ad48 */
if(!s->budget--) { s->failed_pc=0x0c07ad48u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c07ad4a;
P_0c07ad4a: /* original 64e3, guest PC 0x0c07ad4a */
if(!s->budget--) { s->failed_pc=0x0c07ad4au; return 0; }
r[4]=r[14];
goto P_0c07ad4c;
P_0c07ad4c: /* original af6c, guest PC 0x0c07ad4c */
if(!s->budget--) { s->failed_pc=0x0c07ad4cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c07ac28;
P_0c07ad4e: /* original 6ef6, guest PC 0x0c07ad4e */
if(!s->budget--) { s->failed_pc=0x0c07ad4eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c07ad50;
P_0c07ad50: /* original 7f08, guest PC 0x0c07ad50 */
if(!s->budget--) { s->failed_pc=0x0c07ad50u; return 0; }
r[15]+=0x00000008u;
goto P_0c07ad52;
P_0c07ad52: /* original 4f26, guest PC 0x0c07ad52 */
if(!s->budget--) { s->failed_pc=0x0c07ad52u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c07ad54;
P_0c07ad54: /* original 000b, guest PC 0x0c07ad54 */
if(!s->budget--) { s->failed_pc=0x0c07ad54u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c07ad56: /* original 6ef6, guest PC 0x0c07ad56 */
if(!s->budget--) { s->failed_pc=0x0c07ad56u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c07ad58u,s,ram);
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
r[16]=0x0c07ba66u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07ba66u) { target=s->pc; goto dispatch; }
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
r[16]=0x0c07ba72u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07ba72u) { target=s->pc; goto dispatch; }
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
r[16]=0x0c07ba80u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07ba80u) { target=s->pc; goto dispatch; }
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
r[16]=0x0c07ba8eu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07ba8eu) { target=s->pc; goto dispatch; }
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
r[16]=0x0c07ba9au;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07ba9au) { target=s->pc; goto dispatch; }
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
r[16]=0x0c07bae8u;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07bae8u) { target=s->pc; goto dispatch; }
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
return vf3_matrix_family(0x0c07bb48u,s,ram);
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
r[16]=0x0c07bbb0u;
r[5]=r[12];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07bbb0u) { target=s->pc; goto dispatch; }
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
r[16]=0x0c07bbd6u;
r[5]=read(ram,r[9]+r[0],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07bbd6u) { target=s->pc; goto dispatch; }
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
r[16]=0x0c07bbeeu;
r[5]=r[12];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07bbeeu) { target=s->pc; goto dispatch; }
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
r[16]=0x0c07bbfcu;
r[5]=read(ram,r[9]+40,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07bbfcu) { target=s->pc; goto dispatch; }
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
r[16]=0x0c07bc14u;
r[5]=read(ram,r[5]+4,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07bc14u) { target=s->pc; goto dispatch; }
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
r[16]=0x0c07bc26u;
r[5]=r[12];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07bc26u) { target=s->pc; goto dispatch; }
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
r[16]=0x0c07bc34u;
r[5]=read(ram,r[9]+40,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07bc34u) { target=s->pc; goto dispatch; }
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
r[16]=0x0c07bc4cu;
r[5]=read(ram,r[5]+4,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07bc4cu) { target=s->pc; goto dispatch; }
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
r[16]=0x0c07bc5au;
r[5]=r[12];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07bc5au) { target=s->pc; goto dispatch; }
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
r[16]=0x0c07bc80u;
r[5]=read(ram,r[9]+r[0],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07bc80u) { target=s->pc; goto dispatch; }
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
r[16]=0x0c07bca0u;
r[4]=r[10];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07bca0u) { target=s->pc; goto dispatch; }
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
return vf3_matrix_family(0x0c07bcfau,s,ram);
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
r[16]=0x0c07bd7cu;
r[0]=r[10];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07bd7cu) { target=s->pc; goto dispatch; }
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
r[16]=0x0c07bda6u;
r[5]=read(ram,r[9]+r[0],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07bda6u) { target=s->pc; goto dispatch; }
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
r[16]=0x0c07bdd8u;
tmp=read(ram,r[5],4);
r[5]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07bdd8u) { target=s->pc; goto dispatch; }
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
r[16]=0x0c07be0au;
r[0]=0x0000000au;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07be0au) { target=s->pc; goto dispatch; }
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
r[16]=0x0c07be24u;
r[5]=read(ram,r[9]+r[0],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07be24u) { target=s->pc; goto dispatch; }
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
r[16]=0x0c07be66u;
r[5]=read(ram,r[9]+r[0],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07be66u) { target=s->pc; goto dispatch; }
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
return vf3_matrix_family(0x0c07be9cu,s,ram);
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
r[16]=0x0c07bec8u;
r[0]=r[10];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07bec8u) { target=s->pc; goto dispatch; }
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
r[16]=0x0c07bef4u;
r[4]=r[2];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07bef4u) { target=s->pc; goto dispatch; }
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
r[16]=0x0c07bf2eu;
r[4]=read(ram,r[15]+20,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07bf2eu) { target=s->pc; goto dispatch; }
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
r[16]=0x0c07bf6au;
r[0]=0x0000000au;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07bf6au) { target=s->pc; goto dispatch; }
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
r[16]=0x0c07bf8au;
r[4]=r[1];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07bf8au) { target=s->pc; goto dispatch; }
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
r[16]=0x0c07bfc2u;
r[4]=r[2];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07bfc2u) { target=s->pc; goto dispatch; }
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
r[16]=0x0c07c008u;
r[6]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07c008u) { target=s->pc; goto dispatch; }
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
r[16]=0x0c07c01cu;
r[6]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07c01cu) { target=s->pc; goto dispatch; }
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
r[16]=0x0c07c030u;
r[6]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07c030u) { target=s->pc; goto dispatch; }
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
return vf3_matrix_family(0x0c07c044u,s,ram);
P_0c07c05c: /* original 480b, guest PC 0x0c07c05c */
if(!s->budget--) { s->failed_pc=0x0c07c05cu; return 0; }
target=r[8];
r[16]=0x0c07c060u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07c060u) { target=s->pc; goto dispatch; }
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
r[16]=0x0c07c06eu;
r[15]+=0x00000020u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07c06eu) { target=s->pc; goto dispatch; }
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
r[0]=0x0c07c110u;
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
r[0]=0x0c07c114u;
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
r[0]=0x0c07c118u;
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
r[16]=0x0c07c09au;
r[4]+=0x00000040u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07c09au) { target=s->pc; goto dispatch; }
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
r[16]=0x0c07c0b8u;
r[4]+=0x00000040u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07c0b8u) { target=s->pc; goto dispatch; }
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
r[0]=0x0c07c124u;
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
r[16]=0x0c07c0d2u;
r[4]+=0x00000040u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07c0d2u) { target=s->pc; goto dispatch; }
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
return vf3_matrix_family(0x0c07c104u,s,ram);
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
r[16]=0x0c07c158u;
r[0]=r[10];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07c158u) { target=s->pc; goto dispatch; }
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
r[16]=0x0c07c184u;
r[4]=r[2];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07c184u) { target=s->pc; goto dispatch; }
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
r[16]=0x0c07c1c8u;
r[0]=0x0000000au;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07c1c8u) { target=s->pc; goto dispatch; }
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
r[16]=0x0c07c1e6u;
r[4]=r[12];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07c1e6u) { target=s->pc; goto dispatch; }
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
r[16]=0x0c07c21cu;
r[4]=r[12];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07c21cu) { target=s->pc; goto dispatch; }
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
r[16]=0x0c07c268u;
r[6]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07c268u) { target=s->pc; goto dispatch; }
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
r[16]=0x0c07c27cu;
r[6]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07c27cu) { target=s->pc; goto dispatch; }
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
r[16]=0x0c07c290u;
r[6]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07c290u) { target=s->pc; goto dispatch; }
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
r[16]=0x0c07c2a4u;
r[6]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07c2a4u) { target=s->pc; goto dispatch; }
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
r[16]=0x0c07c2b2u;
r[4]=0x00000000u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07c2b2u) { target=s->pc; goto dispatch; }
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
return vf3_matrix_family(0x0c07c2b6u,s,ram);
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
r[16]=0x0c07c2dcu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07c2dcu) { target=s->pc; goto dispatch; }
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
r[16]=0x0c07c2e6u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07c2e6u) { target=s->pc; goto dispatch; }
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
r[16]=0x0c07c2f2u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07c2f2u) { target=s->pc; goto dispatch; }
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
r[16]=0x0c07c300u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07c300u) { target=s->pc; goto dispatch; }
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
P_0c07c874: /* original 2fe6, guest PC 0x0c07c874 */
if(!s->budget--) { s->failed_pc=0x0c07c874u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07c876;
P_0c07c876: /* original 2fd6, guest PC 0x0c07c876 */
if(!s->budget--) { s->failed_pc=0x0c07c876u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07c878;
P_0c07c878: /* original ed00, guest PC 0x0c07c878 */
if(!s->budget--) { s->failed_pc=0x0c07c878u; return 0; }
r[13]=0x00000000u;
goto P_0c07c87a;
P_0c07c87a: /* original 2fc6, guest PC 0x0c07c87a */
if(!s->budget--) { s->failed_pc=0x0c07c87au; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07c87c;
P_0c07c87c: /* original 67d3, guest PC 0x0c07c87c */
if(!s->budget--) { s->failed_pc=0x0c07c87cu; return 0; }
r[7]=r[13];
return vf3_matrix_family(0x0c07c87eu,s,ram);
P_0c07c96a: /* original 4f22, guest PC 0x0c07c96a */
if(!s->budget--) { s->failed_pc=0x0c07c96au; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c07c96c;
P_0c07c96c: /* original 7ffc, guest PC 0x0c07c96c */
if(!s->budget--) { s->failed_pc=0x0c07c96cu; return 0; }
r[15]+=0xfffffffcu;
goto P_0c07c96e;
P_0c07c96e: /* original bf81, guest PC 0x0c07c96e */
if(!s->budget--) { s->failed_pc=0x0c07c96eu; return 0; }
target=0x0c07c874u; r[16]=0x0c07c972u;
write(ram,r[15],r[4],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07c972u) { target=s->pc; goto dispatch; }
goto P_0c07c972;
P_0c07c970: /* original 2f42, guest PC 0x0c07c970 */
if(!s->budget--) { s->failed_pc=0x0c07c970u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c07c972;
P_0c07c972: /* original d342, guest PC 0x0c07c972 */
if(!s->budget--) { s->failed_pc=0x0c07c972u; return 0; }
r[3]=read(ram,0x0c07ca7cu,4);
goto P_0c07c974;
P_0c07c974: /* original e20c, guest PC 0x0c07c974 */
if(!s->budget--) { s->failed_pc=0x0c07c974u; return 0; }
r[2]=0x0000000cu;
goto P_0c07c976;
P_0c07c976: /* original de40, guest PC 0x0c07c976 */
if(!s->budget--) { s->failed_pc=0x0c07c976u; return 0; }
r[14]=read(ram,0x0c07ca78u,4);
goto P_0c07c978;
P_0c07c978: /* original 2320, guest PC 0x0c07c978 */
if(!s->budget--) { s->failed_pc=0x0c07c978u; return 0; }
write(ram,r[3],r[2],1);
goto P_0c07c97a;
P_0c07c97a: /* original d241, guest PC 0x0c07c97a */
if(!s->budget--) { s->failed_pc=0x0c07c97au; return 0; }
r[2]=read(ram,0x0c07ca80u,4);
goto P_0c07c97c;
P_0c07c97c: /* original 9570, guest PC 0x0c07c97c */
if(!s->budget--) { s->failed_pc=0x0c07c97cu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07ca60u,2);
goto P_0c07c97e;
P_0c07c97e: /* original 420b, guest PC 0x0c07c97e */
if(!s->budget--) { s->failed_pc=0x0c07c97eu; return 0; }
target=r[2];
r[16]=0x0c07c982u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07c982u) { target=s->pc; goto dispatch; }
goto P_0c07c982;
P_0c07c980: /* original 64e3, guest PC 0x0c07c980 */
if(!s->budget--) { s->failed_pc=0x0c07c980u; return 0; }
r[4]=r[14];
goto P_0c07c982;
P_0c07c982: /* original d340, guest PC 0x0c07c982 */
if(!s->budget--) { s->failed_pc=0x0c07c982u; return 0; }
r[3]=read(ram,0x0c07ca84u,4);
goto P_0c07c984;
P_0c07c984: /* original 430b, guest PC 0x0c07c984 */
if(!s->budget--) { s->failed_pc=0x0c07c984u; return 0; }
target=r[3];
r[16]=0x0c07c988u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07c988u) { target=s->pc; goto dispatch; }
goto P_0c07c988;
P_0c07c986: /* original 0009, guest PC 0x0c07c986 */
if(!s->budget--) { s->failed_pc=0x0c07c986u; return 0; }
goto P_0c07c988;
P_0c07c988: /* original d23d, guest PC 0x0c07c988 */
if(!s->budget--) { s->failed_pc=0x0c07c988u; return 0; }
r[2]=read(ram,0x0c07ca80u,4);
goto P_0c07c98a;
P_0c07c98a: /* original 956a, guest PC 0x0c07c98a */
if(!s->budget--) { s->failed_pc=0x0c07c98au; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07ca62u,2);
goto P_0c07c98c;
P_0c07c98c: /* original 420b, guest PC 0x0c07c98c */
if(!s->budget--) { s->failed_pc=0x0c07c98cu; return 0; }
target=r[2];
r[16]=0x0c07c990u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07c990u) { target=s->pc; goto dispatch; }
goto P_0c07c990;
P_0c07c98e: /* original 64e3, guest PC 0x0c07c98e */
if(!s->budget--) { s->failed_pc=0x0c07c98eu; return 0; }
r[4]=r[14];
goto P_0c07c990;
P_0c07c990: /* original 64f2, guest PC 0x0c07c990 */
if(!s->budget--) { s->failed_pc=0x0c07c990u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c07c992;
P_0c07c992: /* original 7f04, guest PC 0x0c07c992 */
if(!s->budget--) { s->failed_pc=0x0c07c992u; return 0; }
r[15]+=0x00000004u;
goto P_0c07c994;
P_0c07c994: /* original 4f26, guest PC 0x0c07c994 */
if(!s->budget--) { s->failed_pc=0x0c07c994u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c07c996;
P_0c07c996: /* original a01d, guest PC 0x0c07c996 */
if(!s->budget--) { s->failed_pc=0x0c07c996u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c07c9d4;
P_0c07c998: /* original 6ef6, guest PC 0x0c07c998 */
if(!s->budget--) { s->failed_pc=0x0c07c998u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c07c99au,s,ram);
P_0c07c9d4: /* original 4f22, guest PC 0x0c07c9d4 */
if(!s->budget--) { s->failed_pc=0x0c07c9d4u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c07c9d6;
P_0c07c9d6: /* original 7ffc, guest PC 0x0c07c9d6 */
if(!s->budget--) { s->failed_pc=0x0c07c9d6u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c07c9d8;
P_0c07c9d8: /* original b005, guest PC 0x0c07c9d8 */
if(!s->budget--) { s->failed_pc=0x0c07c9d8u; return 0; }
target=0x0c07c9e6u; r[16]=0x0c07c9dcu;
write(ram,r[15],r[4],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07c9dcu) { target=s->pc; goto dispatch; }
goto P_0c07c9dc;
P_0c07c9da: /* original 2f42, guest PC 0x0c07c9da */
if(!s->budget--) { s->failed_pc=0x0c07c9dau; return 0; }
write(ram,r[15],r[4],4);
goto P_0c07c9dc;
P_0c07c9dc: /* original 64f2, guest PC 0x0c07c9dc */
if(!s->budget--) { s->failed_pc=0x0c07c9dcu; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c07c9de;
P_0c07c9de: /* original 7f04, guest PC 0x0c07c9de */
if(!s->budget--) { s->failed_pc=0x0c07c9deu; return 0; }
r[15]+=0x00000004u;
goto P_0c07c9e0;
P_0c07c9e0: /* original 6503, guest PC 0x0c07c9e0 */
if(!s->budget--) { s->failed_pc=0x0c07c9e0u; return 0; }
r[5]=r[0];
goto P_0c07c9e2;
P_0c07c9e2: /* original a821, guest PC 0x0c07c9e2 */
if(!s->budget--) { s->failed_pc=0x0c07c9e2u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c07ba28;
P_0c07c9e4: /* original 4f26, guest PC 0x0c07c9e4 */
if(!s->budget--) { s->failed_pc=0x0c07c9e4u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
return vf3_matrix_family(0x0c07c9e6u,s,ram);
P_0c07e866: /* original 4f22, guest PC 0x0c07e866 */
if(!s->budget--) { s->failed_pc=0x0c07e866u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c07e868;
P_0c07e868: /* original 7ff8, guest PC 0x0c07e868 */
if(!s->budget--) { s->failed_pc=0x0c07e868u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c07e86a;
P_0c07e86a: /* original 2f42, guest PC 0x0c07e86a */
if(!s->budget--) { s->failed_pc=0x0c07e86au; return 0; }
write(ram,r[15],r[4],4);
goto P_0c07e86c;
P_0c07e86c: /* original d34c, guest PC 0x0c07e86c */
if(!s->budget--) { s->failed_pc=0x0c07e86cu; return 0; }
r[3]=read(ram,0x0c07e9a0u,4);
goto P_0c07e86e;
P_0c07e86e: /* original 430b, guest PC 0x0c07e86e */
if(!s->budget--) { s->failed_pc=0x0c07e86eu; return 0; }
target=r[3];
r[16]=0x0c07e872u;
write(ram,r[15]+4,r[5],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07e872u) { target=s->pc; goto dispatch; }
goto P_0c07e872;
P_0c07e870: /* original 1f51, guest PC 0x0c07e870 */
if(!s->budget--) { s->failed_pc=0x0c07e870u; return 0; }
write(ram,r[15]+4,r[5],4);
goto P_0c07e872;
P_0c07e872: /* original d34c, guest PC 0x0c07e872 */
if(!s->budget--) { s->failed_pc=0x0c07e872u; return 0; }
r[3]=read(ram,0x0c07e9a4u,4);
goto P_0c07e874;
P_0c07e874: /* original 948a, guest PC 0x0c07e874 */
if(!s->budget--) { s->failed_pc=0x0c07e874u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07e98cu,2);
goto P_0c07e876;
P_0c07e876: /* original 430b, guest PC 0x0c07e876 */
if(!s->budget--) { s->failed_pc=0x0c07e876u; return 0; }
target=r[3];
r[16]=0x0c07e87au;
tmp=read(ram,r[15],4);
r[14]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07e87au) { target=s->pc; goto dispatch; }
goto P_0c07e87a;
P_0c07e878: /* original 6ef2, guest PC 0x0c07e878 */
if(!s->budget--) { s->failed_pc=0x0c07e878u; return 0; }
tmp=read(ram,r[15],4);
r[14]=tmp;
goto P_0c07e87a;
P_0c07e87a: /* original d44b, guest PC 0x0c07e87a */
if(!s->budget--) { s->failed_pc=0x0c07e87au; return 0; }
r[4]=read(ram,0x0c07e9a8u,4);
goto P_0c07e87c;
P_0c07e87c: /* original e203, guest PC 0x0c07e87c */
if(!s->budget--) { s->failed_pc=0x0c07e87cu; return 0; }
r[2]=0x00000003u;
goto P_0c07e87e;
P_0c07e87e: /* original d34b, guest PC 0x0c07e87e */
if(!s->budget--) { s->failed_pc=0x0c07e87eu; return 0; }
r[3]=read(ram,0x0c07e9acu,4);
goto P_0c07e880;
P_0c07e880: /* original 9085, guest PC 0x0c07e880 */
if(!s->budget--) { s->failed_pc=0x0c07e880u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07e98eu,2);
goto P_0c07e882;
P_0c07e882: /* original 430b, guest PC 0x0c07e882 */
if(!s->budget--) { s->failed_pc=0x0c07e882u; return 0; }
target=r[3];
r[16]=0x0c07e886u;
write(ram,r[14]+r[0],r[2],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07e886u) { target=s->pc; goto dispatch; }
goto P_0c07e886;
P_0c07e884: /* original 0e26, guest PC 0x0c07e884 */
if(!s->budget--) { s->failed_pc=0x0c07e884u; return 0; }
write(ram,r[14]+r[0],r[2],4);
goto P_0c07e886;
P_0c07e886: /* original d44a, guest PC 0x0c07e886 */
if(!s->budget--) { s->failed_pc=0x0c07e886u; return 0; }
r[4]=read(ram,0x0c07e9b0u,4);
goto P_0c07e888;
P_0c07e888: /* original e010, guest PC 0x0c07e888 */
if(!s->budget--) { s->failed_pc=0x0c07e888u; return 0; }
r[0]=0x00000010u;
goto P_0c07e88a;
P_0c07e88a: /* original 9281, guest PC 0x0c07e88a */
if(!s->budget--) { s->failed_pc=0x0c07e88au; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07e990u,2);
goto P_0c07e88c;
P_0c07e88c: /* original 1425, guest PC 0x0c07e88c */
if(!s->budget--) { s->failed_pc=0x0c07e88cu; return 0; }
write(ram,r[4]+20,r[2],4);
goto P_0c07e88e;
P_0c07e88e: /* original 034c, guest PC 0x0c07e88e */
if(!s->budget--) { s->failed_pc=0x0c07e88eu; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c07e890;
P_0c07e890: /* original 7301, guest PC 0x0c07e890 */
if(!s->budget--) { s->failed_pc=0x0c07e890u; return 0; }
r[3]+=0x00000001u;
goto P_0c07e892;
P_0c07e892: /* original 0434, guest PC 0x0c07e892 */
if(!s->budget--) { s->failed_pc=0x0c07e892u; return 0; }
write(ram,r[4]+r[0],r[3],1);
goto P_0c07e894;
P_0c07e894: /* original d247, guest PC 0x0c07e894 */
if(!s->budget--) { s->failed_pc=0x0c07e894u; return 0; }
r[2]=read(ram,0x0c07e9b4u,4);
goto P_0c07e896;
P_0c07e896: /* original 1e24, guest PC 0x0c07e896 */
if(!s->budget--) { s->failed_pc=0x0c07e896u; return 0; }
write(ram,r[14]+16,r[2],4);
goto P_0c07e898;
P_0c07e898: /* original 55f1, guest PC 0x0c07e898 */
if(!s->budget--) { s->failed_pc=0x0c07e898u; return 0; }
r[5]=read(ram,r[15]+4,4);
goto P_0c07e89a;
P_0c07e89a: /* original 64f2, guest PC 0x0c07e89a */
if(!s->budget--) { s->failed_pc=0x0c07e89au; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c07e89c;
P_0c07e89c: /* original 7f08, guest PC 0x0c07e89c */
if(!s->budget--) { s->failed_pc=0x0c07e89cu; return 0; }
r[15]+=0x00000008u;
goto P_0c07e89e;
P_0c07e89e: /* original 4f26, guest PC 0x0c07e89e */
if(!s->budget--) { s->failed_pc=0x0c07e89eu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c07e8a0;
P_0c07e8a0: /* original d345, guest PC 0x0c07e8a0 */
if(!s->budget--) { s->failed_pc=0x0c07e8a0u; return 0; }
r[3]=read(ram,0x0c07e9b8u,4);
goto P_0c07e8a2;
P_0c07e8a2: /* original 432b, guest PC 0x0c07e8a2 */
if(!s->budget--) { s->failed_pc=0x0c07e8a2u; return 0; }
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
P_0c07e8a4: /* original 6ef6, guest PC 0x0c07e8a4 */
if(!s->budget--) { s->failed_pc=0x0c07e8a4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c07e8a6u,s,ram);
P_0c07e8e6: /* original 4f22, guest PC 0x0c07e8e6 */
if(!s->budget--) { s->failed_pc=0x0c07e8e6u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c07e8e8;
P_0c07e8e8: /* original 6733, guest PC 0x0c07e8e8 */
if(!s->budget--) { s->failed_pc=0x0c07e8e8u; return 0; }
r[7]=r[3];
goto P_0c07e8ea;
P_0c07e8ea: /* original 7ffc, guest PC 0x0c07e8ea */
if(!s->budget--) { s->failed_pc=0x0c07e8eau; return 0; }
r[15]+=0xfffffffcu;
goto P_0c07e8ec;
P_0c07e8ec: /* original 2f42, guest PC 0x0c07e8ec */
if(!s->budget--) { s->failed_pc=0x0c07e8ecu; return 0; }
write(ram,r[15],r[4],4);
goto P_0c07e8ee;
P_0c07e8ee: /* original 9e52, guest PC 0x0c07e8ee */
if(!s->budget--) { s->failed_pc=0x0c07e8eeu; return 0; }
r[14]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07e996u,2);
goto P_0c07e8f0;
P_0c07e8f0: /* original 2f36, guest PC 0x0c07e8f0 */
if(!s->budget--) { s->failed_pc=0x0c07e8f0u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07e8f2;
P_0c07e8f2: /* original d62d, guest PC 0x0c07e8f2 */
if(!s->budget--) { s->failed_pc=0x0c07e8f2u; return 0; }
r[6]=read(ram,0x0c07e9a8u,4);
goto P_0c07e8f4;
P_0c07e8f4: /* original 9550, guest PC 0x0c07e8f4 */
if(!s->budget--) { s->failed_pc=0x0c07e8f4u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07e998u,2);
goto P_0c07e8f6;
P_0c07e8f6: /* original d234, guest PC 0x0c07e8f6 */
if(!s->budget--) { s->failed_pc=0x0c07e8f6u; return 0; }
r[2]=read(ram,0x0c07e9c8u,4);
goto P_0c07e8f8;
P_0c07e8f8: /* original 420b, guest PC 0x0c07e8f8 */
if(!s->budget--) { s->failed_pc=0x0c07e8f8u; return 0; }
target=r[2];
r[16]=0x0c07e8fcu;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07e8fcu) { target=s->pc; goto dispatch; }
goto P_0c07e8fc;
P_0c07e8fa: /* original 64e3, guest PC 0x0c07e8fa */
if(!s->budget--) { s->failed_pc=0x0c07e8fau; return 0; }
r[4]=r[14];
goto P_0c07e8fc;
P_0c07e8fc: /* original d22f, guest PC 0x0c07e8fc */
if(!s->budget--) { s->failed_pc=0x0c07e8fcu; return 0; }
r[2]=read(ram,0x0c07e9bcu,4);
goto P_0c07e8fe;
P_0c07e8fe: /* original 65e3, guest PC 0x0c07e8fe */
if(!s->budget--) { s->failed_pc=0x0c07e8feu; return 0; }
r[5]=r[14];
goto P_0c07e900;
P_0c07e900: /* original 9348, guest PC 0x0c07e900 */
if(!s->budget--) { s->failed_pc=0x0c07e900u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07e994u,2);
goto P_0c07e902;
P_0c07e902: /* original 2232, guest PC 0x0c07e902 */
if(!s->budget--) { s->failed_pc=0x0c07e902u; return 0; }
write(ram,r[2],r[3],4);
goto P_0c07e904;
P_0c07e904: /* original 54f1, guest PC 0x0c07e904 */
if(!s->budget--) { s->failed_pc=0x0c07e904u; return 0; }
r[4]=read(ram,r[15]+4,4);
goto P_0c07e906;
P_0c07e906: /* original 7f08, guest PC 0x0c07e906 */
if(!s->budget--) { s->failed_pc=0x0c07e906u; return 0; }
r[15]+=0x00000008u;
goto P_0c07e908;
P_0c07e908: /* original 4f26, guest PC 0x0c07e908 */
if(!s->budget--) { s->failed_pc=0x0c07e908u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c07e90a;
P_0c07e90a: /* original d32b, guest PC 0x0c07e90a */
if(!s->budget--) { s->failed_pc=0x0c07e90au; return 0; }
r[3]=read(ram,0x0c07e9b8u,4);
goto P_0c07e90c;
P_0c07e90c: /* original 432b, guest PC 0x0c07e90c */
if(!s->budget--) { s->failed_pc=0x0c07e90cu; return 0; }
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
P_0c07e90e: /* original 6ef6, guest PC 0x0c07e90e */
if(!s->budget--) { s->failed_pc=0x0c07e90eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c07e910u,s,ram);
P_0c07f722: /* original 4f22, guest PC 0x0c07f722 */
if(!s->budget--) { s->failed_pc=0x0c07f722u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c07f724;
P_0c07f724: /* original 7fe8, guest PC 0x0c07f724 */
if(!s->budget--) { s->failed_pc=0x0c07f724u; return 0; }
r[15]+=0xffffffe8u;
goto P_0c07f726;
P_0c07f726: /* original 1f42, guest PC 0x0c07f726 */
if(!s->budget--) { s->failed_pc=0x0c07f726u; return 0; }
write(ram,r[15]+8,r[4],4);
goto P_0c07f728;
P_0c07f728: /* original d348, guest PC 0x0c07f728 */
if(!s->budget--) { s->failed_pc=0x0c07f728u; return 0; }
r[3]=read(ram,0x0c07f84cu,4);
goto P_0c07f72a;
P_0c07f72a: /* original 1f31, guest PC 0x0c07f72a */
if(!s->budget--) { s->failed_pc=0x0c07f72au; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c07f72c;
P_0c07f72c: /* original de48, guest PC 0x0c07f72c */
if(!s->budget--) { s->failed_pc=0x0c07f72cu; return 0; }
r[14]=read(ram,0x0c07f850u,4);
goto P_0c07f72e;
P_0c07f72e: /* original 9083, guest PC 0x0c07f72e */
if(!s->budget--) { s->failed_pc=0x0c07f72eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07f838u,2);
goto P_0c07f730;
P_0c07f730: /* original 03ec, guest PC 0x0c07f730 */
if(!s->budget--) { s->failed_pc=0x0c07f730u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c07f732;
P_0c07f732: /* original 6633, guest PC 0x0c07f732 */
if(!s->budget--) { s->failed_pc=0x0c07f732u; return 0; }
r[6]=r[3];
goto P_0c07f734;
P_0c07f734: /* original 2f32, guest PC 0x0c07f734 */
if(!s->budget--) { s->failed_pc=0x0c07f734u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c07f736;
P_0c07f736: /* original 9580, guest PC 0x0c07f736 */
if(!s->budget--) { s->failed_pc=0x0c07f736u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07f83au,2);
goto P_0c07f738;
P_0c07f738: /* original d846, guest PC 0x0c07f738 */
if(!s->budget--) { s->failed_pc=0x0c07f738u; return 0; }
r[8]=read(ram,0x0c07f854u,4);
goto P_0c07f73a;
P_0c07f73a: /* original 977f, guest PC 0x0c07f73a */
if(!s->budget--) { s->failed_pc=0x0c07f73au; return 0; }
r[7]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07f83cu,2);
goto P_0c07f73c;
P_0c07f73c: /* original 480b, guest PC 0x0c07f73c */
if(!s->budget--) { s->failed_pc=0x0c07f73cu; return 0; }
target=r[8];
r[16]=0x0c07f740u;
r[4]=read(ram,r[15]+4,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07f740u) { target=s->pc; goto dispatch; }
goto P_0c07f740;
P_0c07f73e: /* original 54f1, guest PC 0x0c07f73e */
if(!s->budget--) { s->failed_pc=0x0c07f73eu; return 0; }
r[4]=read(ram,r[15]+4,4);
goto P_0c07f740;
P_0c07f740: /* original 907d, guest PC 0x0c07f740 */
if(!s->budget--) { s->failed_pc=0x0c07f740u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07f83eu,2);
goto P_0c07f742;
P_0c07f742: /* original 04ec, guest PC 0x0c07f742 */
if(!s->budget--) { s->failed_pc=0x0c07f742u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c07f744;
P_0c07f744: /* original 2448, guest PC 0x0c07f744 */
if(!s->budget--) { s->failed_pc=0x0c07f744u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c07f746;
P_0c07f746: /* original 8973, guest PC 0x0c07f746 */
if(!s->budget--) { s->failed_pc=0x0c07f746u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07f830; }
goto P_0c07f748;
P_0c07f748: /* original 907a, guest PC 0x0c07f748 */
if(!s->budget--) { s->failed_pc=0x0c07f748u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07f840u,2);
goto P_0c07f74a;
P_0c07f74a: /* original e92b, guest PC 0x0c07f74a */
if(!s->budget--) { s->failed_pc=0x0c07f74au; return 0; }
r[9]=0x0000002bu;
goto P_0c07f74c;
P_0c07f74c: /* original 9379, guest PC 0x0c07f74c */
if(!s->budget--) { s->failed_pc=0x0c07f74cu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07f842u,2);
goto P_0c07f74e;
P_0c07f74e: /* original 6493, guest PC 0x0c07f74e */
if(!s->budget--) { s->failed_pc=0x0c07f74eu; return 0; }
r[4]=r[9];
goto P_0c07f750;
P_0c07f750: /* original 0cec, guest PC 0x0c07f750 */
if(!s->budget--) { s->failed_pc=0x0c07f750u; return 0; }
r[12]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c07f752;
P_0c07f752: /* original 7001, guest PC 0x0c07f752 */
if(!s->budget--) { s->failed_pc=0x0c07f752u; return 0; }
r[0]+=0x00000001u;
goto P_0c07f754;
P_0c07f754: /* original 33ec, guest PC 0x0c07f754 */
if(!s->budget--) { s->failed_pc=0x0c07f754u; return 0; }
r[3]+=r[14];
goto P_0c07f756;
P_0c07f756: /* original 0bec, guest PC 0x0c07f756 */
if(!s->budget--) { s->failed_pc=0x0c07f756u; return 0; }
r[11]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c07f758;
P_0c07f758: /* original 65ce, guest PC 0x0c07f758 */
if(!s->budget--) { s->failed_pc=0x0c07f758u; return 0; }
r[5]=(uint32_t)(int32_t)(int8_t)r[12];
goto P_0c07f75a;
P_0c07f75a: /* original 353c, guest PC 0x0c07f75a */
if(!s->budget--) { s->failed_pc=0x0c07f75au; return 0; }
r[5]+=r[3];
goto P_0c07f75c;
P_0c07f75c: /* original 9372, guest PC 0x0c07f75c */
if(!s->budget--) { s->failed_pc=0x0c07f75cu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07f844u,2);
goto P_0c07f75e;
P_0c07f75e: /* original 6550, guest PC 0x0c07f75e */
if(!s->budget--) { s->failed_pc=0x0c07f75eu; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[5],1);
r[5]=tmp;
goto P_0c07f760;
P_0c07f760: /* original 655c, guest PC 0x0c07f760 */
if(!s->budget--) { s->failed_pc=0x0c07f760u; return 0; }
r[5]=r[5]&255u;
goto P_0c07f762;
P_0c07f762: /* original 6253, guest PC 0x0c07f762 */
if(!s->budget--) { s->failed_pc=0x0c07f762u; return 0; }
r[2]=r[5];
goto P_0c07f764;
P_0c07f764: /* original 3230, guest PC 0x0c07f764 */
if(!s->budget--) { s->failed_pc=0x0c07f764u; return 0; }
r[17]=(r[17]&~1u)|((r[2]==r[3])!=0);
goto P_0c07f766;
P_0c07f766: /* original 8d63, guest PC 0x0c07f766 */
if(!s->budget--) { s->failed_pc=0x0c07f766u; return 0; }
cond=r[17]&1u;
write(ram,r[15]+16,r[5],4);
if(cond) { goto P_0c07f830; }
goto P_0c07f76a;
P_0c07f768: /* original 1f54, guest PC 0x0c07f768 */
if(!s->budget--) { s->failed_pc=0x0c07f768u; return 0; }
write(ram,r[15]+16,r[5],4);
goto P_0c07f76a;
P_0c07f76a: /* original 63c3, guest PC 0x0c07f76a */
if(!s->budget--) { s->failed_pc=0x0c07f76au; return 0; }
r[3]=r[12];
goto P_0c07f76c;
P_0c07f76c: /* original 60c3, guest PC 0x0c07f76c */
if(!s->budget--) { s->failed_pc=0x0c07f76cu; return 0; }
r[0]=r[12];
goto P_0c07f76e;
P_0c07f76e: /* original 4308, guest PC 0x0c07f76e */
if(!s->budget--) { s->failed_pc=0x0c07f76eu; return 0; }
r[3]<<=2;
goto P_0c07f770;
P_0c07f770: /* original 4000, guest PC 0x0c07f770 */
if(!s->budget--) { s->failed_pc=0x0c07f770u; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c07f772;
P_0c07f772: /* original 303c, guest PC 0x0c07f772 */
if(!s->budget--) { s->failed_pc=0x0c07f772u; return 0; }
r[0]+=r[3];
goto P_0c07f774;
P_0c07f774: /* original 3408, guest PC 0x0c07f774 */
if(!s->budget--) { s->failed_pc=0x0c07f774u; return 0; }
r[4]-=r[0];
goto P_0c07f776;
P_0c07f776: /* original 80fc, guest PC 0x0c07f776 */
if(!s->budget--) { s->failed_pc=0x0c07f776u; return 0; }
write(ram,r[15]+12,r[0],1);
goto P_0c07f778;
P_0c07f778: /* original 654e, guest PC 0x0c07f778 */
if(!s->budget--) { s->failed_pc=0x0c07f778u; return 0; }
r[5]=(uint32_t)(int32_t)(int8_t)r[4];
goto P_0c07f77a;
P_0c07f77a: /* original 9a64, guest PC 0x0c07f77a */
if(!s->budget--) { s->failed_pc=0x0c07f77au; return 0; }
r[10]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07f846u,2);
goto P_0c07f77c;
P_0c07f77c: /* original 63ce, guest PC 0x0c07f77c */
if(!s->budget--) { s->failed_pc=0x0c07f77cu; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)r[12];
goto P_0c07f77e;
P_0c07f77e: /* original 4500, guest PC 0x0c07f77e */
if(!s->budget--) { s->failed_pc=0x0c07f77eu; return 0; }
r[17]=(r[17]&~1u)|((r[5]>>31)!=0);
r[5]<<=1;
goto P_0c07f780;
P_0c07f780: /* original 4315, guest PC 0x0c07f780 */
if(!s->budget--) { s->failed_pc=0x0c07f780u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>0)!=0);
goto P_0c07f782;
P_0c07f782: /* original 25ab, guest PC 0x0c07f782 */
if(!s->budget--) { s->failed_pc=0x0c07f782u; return 0; }
r[5]|=r[10];
goto P_0c07f784;
P_0c07f784: /* original ed00, guest PC 0x0c07f784 */
if(!s->budget--) { s->failed_pc=0x0c07f784u; return 0; }
r[13]=0x00000000u;
goto P_0c07f786;
P_0c07f786: /* original 8f1f, guest PC 0x0c07f786 */
if(!s->budget--) { s->failed_pc=0x0c07f786u; return 0; }
cond=r[17]&1u;
write(ram,r[15],r[3],4);
if(!cond) { goto P_0c07f7c8; }
goto P_0c07f78a;
P_0c07f788: /* original 2f32, guest PC 0x0c07f788 */
if(!s->budget--) { s->failed_pc=0x0c07f788u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c07f78a;
P_0c07f78a: /* original 935a, guest PC 0x0c07f78a */
if(!s->budget--) { s->failed_pc=0x0c07f78au; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07f842u,2);
goto P_0c07f78c;
P_0c07f78c: /* original 33ec, guest PC 0x0c07f78c */
if(!s->budget--) { s->failed_pc=0x0c07f78cu; return 0; }
r[3]+=r[14];
goto P_0c07f78e;
P_0c07f78e: /* original 33dc, guest PC 0x0c07f78e */
if(!s->budget--) { s->failed_pc=0x0c07f78eu; return 0; }
r[3]+=r[13];
goto P_0c07f790;
P_0c07f790: /* original 6230, guest PC 0x0c07f790 */
if(!s->budget--) { s->failed_pc=0x0c07f790u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[3],1);
r[2]=tmp;
goto P_0c07f792;
P_0c07f792: /* original 9357, guest PC 0x0c07f792 */
if(!s->budget--) { s->failed_pc=0x0c07f792u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07f844u,2);
goto P_0c07f794;
P_0c07f794: /* original 622c, guest PC 0x0c07f794 */
if(!s->budget--) { s->failed_pc=0x0c07f794u; return 0; }
r[2]=r[2]&255u;
goto P_0c07f796;
P_0c07f796: /* original 3230, guest PC 0x0c07f796 */
if(!s->budget--) { s->failed_pc=0x0c07f796u; return 0; }
r[17]=(r[17]&~1u)|((r[2]==r[3])!=0);
goto P_0c07f798;
P_0c07f798: /* original 8916, guest PC 0x0c07f798 */
if(!s->budget--) { s->failed_pc=0x0c07f798u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07f7c8; }
goto P_0c07f79a;
P_0c07f79a: /* original 9652, guest PC 0x0c07f79a */
if(!s->budget--) { s->failed_pc=0x0c07f79au; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07f842u,2);
goto P_0c07f79c;
P_0c07f79c: /* original 63d3, guest PC 0x0c07f79c */
if(!s->budget--) { s->failed_pc=0x0c07f79cu; return 0; }
r[3]=r[13];
goto P_0c07f79e;
P_0c07f79e: /* original 62d3, guest PC 0x0c07f79e */
if(!s->budget--) { s->failed_pc=0x0c07f79eu; return 0; }
r[2]=r[13];
goto P_0c07f7a0;
P_0c07f7a0: /* original 4308, guest PC 0x0c07f7a0 */
if(!s->budget--) { s->failed_pc=0x0c07f7a0u; return 0; }
r[3]<<=2;
goto P_0c07f7a2;
P_0c07f7a2: /* original 4200, guest PC 0x0c07f7a2 */
if(!s->budget--) { s->failed_pc=0x0c07f7a2u; return 0; }
r[17]=(r[17]&~1u)|((r[2]>>31)!=0);
r[2]<<=1;
goto P_0c07f7a4;
P_0c07f7a4: /* original 6493, guest PC 0x0c07f7a4 */
if(!s->budget--) { s->failed_pc=0x0c07f7a4u; return 0; }
r[4]=r[9];
goto P_0c07f7a6;
P_0c07f7a6: /* original 36ec, guest PC 0x0c07f7a6 */
if(!s->budget--) { s->failed_pc=0x0c07f7a6u; return 0; }
r[6]+=r[14];
goto P_0c07f7a8;
P_0c07f7a8: /* original 974e, guest PC 0x0c07f7a8 */
if(!s->budget--) { s->failed_pc=0x0c07f7a8u; return 0; }
r[7]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07f848u,2);
goto P_0c07f7aa;
P_0c07f7aa: /* original 323c, guest PC 0x0c07f7aa */
if(!s->budget--) { s->failed_pc=0x0c07f7aau; return 0; }
r[2]+=r[3];
goto P_0c07f7ac;
P_0c07f7ac: /* original 36dc, guest PC 0x0c07f7ac */
if(!s->budget--) { s->failed_pc=0x0c07f7acu; return 0; }
r[6]+=r[13];
goto P_0c07f7ae;
P_0c07f7ae: /* original 3428, guest PC 0x0c07f7ae */
if(!s->budget--) { s->failed_pc=0x0c07f7aeu; return 0; }
r[4]-=r[2];
goto P_0c07f7b0;
P_0c07f7b0: /* original 6660, guest PC 0x0c07f7b0 */
if(!s->budget--) { s->failed_pc=0x0c07f7b0u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[6],1);
r[6]=tmp;
goto P_0c07f7b2;
P_0c07f7b2: /* original 4400, guest PC 0x0c07f7b2 */
if(!s->budget--) { s->failed_pc=0x0c07f7b2u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c07f7b4;
P_0c07f7b4: /* original 6543, guest PC 0x0c07f7b4 */
if(!s->budget--) { s->failed_pc=0x0c07f7b4u; return 0; }
r[5]=r[4];
goto P_0c07f7b6;
P_0c07f7b6: /* original 666c, guest PC 0x0c07f7b6 */
if(!s->budget--) { s->failed_pc=0x0c07f7b6u; return 0; }
r[6]=r[6]&255u;
goto P_0c07f7b8;
P_0c07f7b8: /* original 25ab, guest PC 0x0c07f7b8 */
if(!s->budget--) { s->failed_pc=0x0c07f7b8u; return 0; }
r[5]|=r[10];
goto P_0c07f7ba;
P_0c07f7ba: /* original 480b, guest PC 0x0c07f7ba */
if(!s->budget--) { s->failed_pc=0x0c07f7bau; return 0; }
target=r[8];
r[16]=0x0c07f7beu;
r[4]=read(ram,r[15]+4,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07f7beu) { target=s->pc; goto dispatch; }
goto P_0c07f7be;
P_0c07f7bc: /* original 54f1, guest PC 0x0c07f7bc */
if(!s->budget--) { s->failed_pc=0x0c07f7bcu; return 0; }
r[4]=read(ram,r[15]+4,4);
goto P_0c07f7be;
P_0c07f7be: /* original 63f2, guest PC 0x0c07f7be */
if(!s->budget--) { s->failed_pc=0x0c07f7beu; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c07f7c0;
P_0c07f7c0: /* original 7d01, guest PC 0x0c07f7c0 */
if(!s->budget--) { s->failed_pc=0x0c07f7c0u; return 0; }
r[13]+=0x00000001u;
goto P_0c07f7c2;
P_0c07f7c2: /* original 6503, guest PC 0x0c07f7c2 */
if(!s->budget--) { s->failed_pc=0x0c07f7c2u; return 0; }
r[5]=r[0];
goto P_0c07f7c4;
P_0c07f7c4: /* original 3d33, guest PC 0x0c07f7c4 */
if(!s->budget--) { s->failed_pc=0x0c07f7c4u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[13]>=(int32_t)r[3])!=0);
goto P_0c07f7c6;
P_0c07f7c6: /* original 8be0, guest PC 0x0c07f7c6 */
if(!s->budget--) { s->failed_pc=0x0c07f7c6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07f78a; }
goto P_0c07f7c8;
P_0c07f7c8: /* original d123, guest PC 0x0c07f7c8 */
if(!s->budget--) { s->failed_pc=0x0c07f7c8u; return 0; }
r[1]=read(ram,0x0c07f858u,4);
goto P_0c07f7ca;
P_0c07f7ca: /* original e301, guest PC 0x0c07f7ca */
if(!s->budget--) { s->failed_pc=0x0c07f7cau; return 0; }
r[3]=0x00000001u;
goto P_0c07f7cc;
P_0c07f7cc: /* original 6412, guest PC 0x0c07f7cc */
if(!s->budget--) { s->failed_pc=0x0c07f7ccu; return 0; }
tmp=read(ram,r[1],4);
r[4]=tmp;
goto P_0c07f7ce;
P_0c07f7ce: /* original 2438, guest PC 0x0c07f7ce */
if(!s->budget--) { s->failed_pc=0x0c07f7ceu; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[3])==0)!=0);
goto P_0c07f7d0;
P_0c07f7d0: /* original 890b, guest PC 0x0c07f7d0 */
if(!s->budget--) { s->failed_pc=0x0c07f7d0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07f7ea; }
goto P_0c07f7d2;
P_0c07f7d2: /* original 54f2, guest PC 0x0c07f7d2 */
if(!s->budget--) { s->failed_pc=0x0c07f7d2u; return 0; }
r[4]=read(ram,r[15]+8,4);
goto P_0c07f7d4;
P_0c07f7d4: /* original 7f18, guest PC 0x0c07f7d4 */
if(!s->budget--) { s->failed_pc=0x0c07f7d4u; return 0; }
r[15]+=0x00000018u;
goto P_0c07f7d6;
P_0c07f7d6: /* original 4f26, guest PC 0x0c07f7d6 */
if(!s->budget--) { s->failed_pc=0x0c07f7d6u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c07f7d8;
P_0c07f7d8: /* original d220, guest PC 0x0c07f7d8 */
if(!s->budget--) { s->failed_pc=0x0c07f7d8u; return 0; }
r[2]=read(ram,0x0c07f85cu,4);
goto P_0c07f7da;
P_0c07f7da: /* original 68f6, guest PC 0x0c07f7da */
if(!s->budget--) { s->failed_pc=0x0c07f7dau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c07f7dc;
P_0c07f7dc: /* original 69f6, guest PC 0x0c07f7dc */
if(!s->budget--) { s->failed_pc=0x0c07f7dcu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c07f7de;
P_0c07f7de: /* original 6af6, guest PC 0x0c07f7de */
if(!s->budget--) { s->failed_pc=0x0c07f7deu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c07f7e0;
P_0c07f7e0: /* original 6bf6, guest PC 0x0c07f7e0 */
if(!s->budget--) { s->failed_pc=0x0c07f7e0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c07f7e2;
P_0c07f7e2: /* original 6cf6, guest PC 0x0c07f7e2 */
if(!s->budget--) { s->failed_pc=0x0c07f7e2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c07f7e4;
P_0c07f7e4: /* original 6df6, guest PC 0x0c07f7e4 */
if(!s->budget--) { s->failed_pc=0x0c07f7e4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c07f7e6;
P_0c07f7e6: /* original 422b, guest PC 0x0c07f7e6 */
if(!s->budget--) { s->failed_pc=0x0c07f7e6u; return 0; }
target=r[2];
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
P_0c07f7e8: /* original 6ef6, guest PC 0x0c07f7e8 */
if(!s->budget--) { s->failed_pc=0x0c07f7e8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c07f7ea;
P_0c07f7ea: /* original d31d, guest PC 0x0c07f7ea */
if(!s->budget--) { s->failed_pc=0x0c07f7eau; return 0; }
r[3]=read(ram,0x0c07f860u,4);
goto P_0c07f7ec;
P_0c07f7ec: /* original 64be, guest PC 0x0c07f7ec */
if(!s->budget--) { s->failed_pc=0x0c07f7ecu; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)r[11];
goto P_0c07f7ee;
P_0c07f7ee: /* original 4408, guest PC 0x0c07f7ee */
if(!s->budget--) { s->failed_pc=0x0c07f7eeu; return 0; }
r[4]<<=2;
goto P_0c07f7f0;
P_0c07f7f0: /* original 61f3, guest PC 0x0c07f7f0 */
if(!s->budget--) { s->failed_pc=0x0c07f7f0u; return 0; }
r[1]=r[15];
goto P_0c07f7f2;
P_0c07f7f2: /* original 343c, guest PC 0x0c07f7f2 */
if(!s->budget--) { s->failed_pc=0x0c07f7f2u; return 0; }
r[4]+=r[3];
goto P_0c07f7f4;
P_0c07f7f4: /* original 7114, guest PC 0x0c07f7f4 */
if(!s->budget--) { s->failed_pc=0x0c07f7f4u; return 0; }
r[1]+=0x00000014u;
goto P_0c07f7f6;
P_0c07f7f6: /* original 6241, guest PC 0x0c07f7f6 */
if(!s->budget--) { s->failed_pc=0x0c07f7f6u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[4],2);
r[2]=tmp;
goto P_0c07f7f8;
P_0c07f7f8: /* original 2f21, guest PC 0x0c07f7f8 */
if(!s->budget--) { s->failed_pc=0x0c07f7f8u; return 0; }
write(ram,r[15],r[2],2);
goto P_0c07f7fa;
P_0c07f7fa: /* original 8442, guest PC 0x0c07f7fa */
if(!s->budget--) { s->failed_pc=0x0c07f7fau; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+2,1);
goto P_0c07f7fc;
P_0c07f7fc: /* original 6493, guest PC 0x0c07f7fc */
if(!s->budget--) { s->failed_pc=0x0c07f7fcu; return 0; }
r[4]=r[9];
goto P_0c07f7fe;
P_0c07f7fe: /* original 2100, guest PC 0x0c07f7fe */
if(!s->budget--) { s->failed_pc=0x0c07f7feu; return 0; }
write(ram,r[1],r[0],1);
goto P_0c07f800;
P_0c07f800: /* original 84fc, guest PC 0x0c07f800 */
if(!s->budget--) { s->failed_pc=0x0c07f800u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[15]+12,1);
goto P_0c07f802;
P_0c07f802: /* original 67f1, guest PC 0x0c07f802 */
if(!s->budget--) { s->failed_pc=0x0c07f802u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[15],2);
r[7]=tmp;
goto P_0c07f804;
P_0c07f804: /* original 3408, guest PC 0x0c07f804 */
if(!s->budget--) { s->failed_pc=0x0c07f804u; return 0; }
r[4]-=r[0];
goto P_0c07f806;
P_0c07f806: /* original e014, guest PC 0x0c07f806 */
if(!s->budget--) { s->failed_pc=0x0c07f806u; return 0; }
r[0]=0x00000014u;
goto P_0c07f808;
P_0c07f808: /* original 654e, guest PC 0x0c07f808 */
if(!s->budget--) { s->failed_pc=0x0c07f808u; return 0; }
r[5]=(uint32_t)(int32_t)(int8_t)r[4];
goto P_0c07f80a;
P_0c07f80a: /* original 06fc, guest PC 0x0c07f80a */
if(!s->budget--) { s->failed_pc=0x0c07f80au; return 0; }
r[6]=(uint32_t)(int32_t)(int8_t)read(ram,r[15]+r[0],1);
goto P_0c07f80c;
P_0c07f80c: /* original 4500, guest PC 0x0c07f80c */
if(!s->budget--) { s->failed_pc=0x0c07f80cu; return 0; }
r[17]=(r[17]&~1u)|((r[5]>>31)!=0);
r[5]<<=1;
goto P_0c07f80e;
P_0c07f80e: /* original 25ab, guest PC 0x0c07f80e */
if(!s->budget--) { s->failed_pc=0x0c07f80eu; return 0; }
r[5]|=r[10];
goto P_0c07f810;
P_0c07f810: /* original 480b, guest PC 0x0c07f810 */
if(!s->budget--) { s->failed_pc=0x0c07f810u; return 0; }
target=r[8];
r[16]=0x0c07f814u;
r[4]=read(ram,r[15]+4,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07f814u) { target=s->pc; goto dispatch; }
goto P_0c07f814;
P_0c07f812: /* original 54f1, guest PC 0x0c07f812 */
if(!s->budget--) { s->failed_pc=0x0c07f812u; return 0; }
r[4]=read(ram,r[15]+4,4);
goto P_0c07f814;
P_0c07f814: /* original 54f4, guest PC 0x0c07f814 */
if(!s->budget--) { s->failed_pc=0x0c07f814u; return 0; }
r[4]=read(ram,r[15]+16,4);
goto P_0c07f816;
P_0c07f816: /* original 7b01, guest PC 0x0c07f816 */
if(!s->budget--) { s->failed_pc=0x0c07f816u; return 0; }
r[11]+=0x00000001u;
goto P_0c07f818;
P_0c07f818: /* original 63be, guest PC 0x0c07f818 */
if(!s->budget--) { s->failed_pc=0x0c07f818u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)r[11];
goto P_0c07f81a;
P_0c07f81a: /* original 6503, guest PC 0x0c07f81a */
if(!s->budget--) { s->failed_pc=0x0c07f81au; return 0; }
r[5]=r[0];
goto P_0c07f81c;
P_0c07f81c: /* original 4400, guest PC 0x0c07f81c */
if(!s->budget--) { s->failed_pc=0x0c07f81cu; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c07f81e;
P_0c07f81e: /* original 644c, guest PC 0x0c07f81e */
if(!s->budget--) { s->failed_pc=0x0c07f81eu; return 0; }
r[4]=r[4]&255u;
goto P_0c07f820;
P_0c07f820: /* original 3347, guest PC 0x0c07f820 */
if(!s->budget--) { s->failed_pc=0x0c07f820u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>(int32_t)r[4])!=0);
goto P_0c07f822;
P_0c07f822: /* original 8b21, guest PC 0x0c07f822 */
if(!s->budget--) { s->failed_pc=0x0c07f822u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07f868; }
goto P_0c07f824;
P_0c07f824: /* original 7c01, guest PC 0x0c07f824 */
if(!s->budget--) { s->failed_pc=0x0c07f824u; return 0; }
r[12]+=0x00000001u;
goto P_0c07f826;
P_0c07f826: /* original e205, guest PC 0x0c07f826 */
if(!s->budget--) { s->failed_pc=0x0c07f826u; return 0; }
r[2]=0x00000005u;
goto P_0c07f828;
P_0c07f828: /* original 63ce, guest PC 0x0c07f828 */
if(!s->budget--) { s->failed_pc=0x0c07f828u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)r[12];
goto P_0c07f82a;
P_0c07f82a: /* original 3327, guest PC 0x0c07f82a */
if(!s->budget--) { s->failed_pc=0x0c07f82au; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>(int32_t)r[2])!=0);
goto P_0c07f82c;
P_0c07f82c: /* original 8f1a, guest PC 0x0c07f82c */
if(!s->budget--) { s->failed_pc=0x0c07f82cu; return 0; }
cond=r[17]&1u;
r[11]=0x00000000u;
if(!cond) { goto P_0c07f864; }
goto P_0c07f830;
P_0c07f82e: /* original eb00, guest PC 0x0c07f82e */
if(!s->budget--) { s->failed_pc=0x0c07f82eu; return 0; }
r[11]=0x00000000u;
goto P_0c07f830;
P_0c07f830: /* original b029, guest PC 0x0c07f830 */
if(!s->budget--) { s->failed_pc=0x0c07f830u; return 0; }
target=0x0c07f886u; r[16]=0x0c07f834u;
r[4]=read(ram,r[15]+8,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07f834u) { target=s->pc; goto dispatch; }
goto P_0c07f834;
P_0c07f832: /* original 54f2, guest PC 0x0c07f832 */
if(!s->budget--) { s->failed_pc=0x0c07f832u; return 0; }
r[4]=read(ram,r[15]+8,4);
goto P_0c07f834;
P_0c07f834: /* original a01d, guest PC 0x0c07f834 */
if(!s->budget--) { s->failed_pc=0x0c07f834u; return 0; }
goto P_0c07f872;
P_0c07f836: /* original 0009, guest PC 0x0c07f836 */
if(!s->budget--) { s->failed_pc=0x0c07f836u; return 0; }
return vf3_matrix_family(0x0c07f838u,s,ram);
P_0c07f864: /* original 9088, guest PC 0x0c07f864 */
if(!s->budget--) { s->failed_pc=0x0c07f864u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07f978u,2);
goto P_0c07f866;
P_0c07f866: /* original 0ec4, guest PC 0x0c07f866 */
if(!s->budget--) { s->failed_pc=0x0c07f866u; return 0; }
write(ram,r[14]+r[0],r[12],1);
goto P_0c07f868;
P_0c07f868: /* original 9087, guest PC 0x0c07f868 */
if(!s->budget--) { s->failed_pc=0x0c07f868u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07f97au,2);
goto P_0c07f86a;
P_0c07f86a: /* original 0eb4, guest PC 0x0c07f86a */
if(!s->budget--) { s->failed_pc=0x0c07f86au; return 0; }
write(ram,r[14]+r[0],r[11],1);
goto P_0c07f86c;
P_0c07f86c: /* original d349, guest PC 0x0c07f86c */
if(!s->budget--) { s->failed_pc=0x0c07f86cu; return 0; }
r[3]=read(ram,0x0c07f994u,4);
goto P_0c07f86e;
P_0c07f86e: /* original 430b, guest PC 0x0c07f86e */
if(!s->budget--) { s->failed_pc=0x0c07f86eu; return 0; }
target=r[3];
r[16]=0x0c07f872u;
r[4]=read(ram,r[15]+8,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07f872u) { target=s->pc; goto dispatch; }
goto P_0c07f872;
P_0c07f870: /* original 54f2, guest PC 0x0c07f870 */
if(!s->budget--) { s->failed_pc=0x0c07f870u; return 0; }
r[4]=read(ram,r[15]+8,4);
goto P_0c07f872;
P_0c07f872: /* original 7f18, guest PC 0x0c07f872 */
if(!s->budget--) { s->failed_pc=0x0c07f872u; return 0; }
r[15]+=0x00000018u;
goto P_0c07f874;
P_0c07f874: /* original 4f26, guest PC 0x0c07f874 */
if(!s->budget--) { s->failed_pc=0x0c07f874u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c07f876;
P_0c07f876: /* original 68f6, guest PC 0x0c07f876 */
if(!s->budget--) { s->failed_pc=0x0c07f876u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c07f878;
P_0c07f878: /* original 69f6, guest PC 0x0c07f878 */
if(!s->budget--) { s->failed_pc=0x0c07f878u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c07f87a;
P_0c07f87a: /* original 6af6, guest PC 0x0c07f87a */
if(!s->budget--) { s->failed_pc=0x0c07f87au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c07f87c;
P_0c07f87c: /* original 6bf6, guest PC 0x0c07f87c */
if(!s->budget--) { s->failed_pc=0x0c07f87cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c07f87e;
P_0c07f87e: /* original 6cf6, guest PC 0x0c07f87e */
if(!s->budget--) { s->failed_pc=0x0c07f87eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c07f880;
P_0c07f880: /* original 6df6, guest PC 0x0c07f880 */
if(!s->budget--) { s->failed_pc=0x0c07f880u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c07f882;
P_0c07f882: /* original 000b, guest PC 0x0c07f882 */
if(!s->budget--) { s->failed_pc=0x0c07f882u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c07f884: /* original 6ef6, guest PC 0x0c07f884 */
if(!s->budget--) { s->failed_pc=0x0c07f884u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c07f886;
P_0c07f886: /* original 2fe6, guest PC 0x0c07f886 */
if(!s->budget--) { s->failed_pc=0x0c07f886u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07f888;
P_0c07f888: /* original 2fd6, guest PC 0x0c07f888 */
if(!s->budget--) { s->failed_pc=0x0c07f888u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07f88a;
P_0c07f88a: /* original 2fc6, guest PC 0x0c07f88a */
if(!s->budget--) { s->failed_pc=0x0c07f88au; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07f88c;
P_0c07f88c: /* original 2fb6, guest PC 0x0c07f88c */
if(!s->budget--) { s->failed_pc=0x0c07f88cu; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07f88e;
P_0c07f88e: /* original 2fa6, guest PC 0x0c07f88e */
if(!s->budget--) { s->failed_pc=0x0c07f88eu; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07f890;
P_0c07f890: /* original 2f96, guest PC 0x0c07f890 */
if(!s->budget--) { s->failed_pc=0x0c07f890u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07f892;
P_0c07f892: /* original 2f86, guest PC 0x0c07f892 */
if(!s->budget--) { s->failed_pc=0x0c07f892u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07f894;
P_0c07f894: /* original 4f22, guest PC 0x0c07f894 */
if(!s->budget--) { s->failed_pc=0x0c07f894u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c07f896;
P_0c07f896: /* original 4f12, guest PC 0x0c07f896 */
if(!s->budget--) { s->failed_pc=0x0c07f896u; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c07f898;
P_0c07f898: /* original 7fe8, guest PC 0x0c07f898 */
if(!s->budget--) { s->failed_pc=0x0c07f898u; return 0; }
r[15]+=0xffffffe8u;
goto P_0c07f89a;
P_0c07f89a: /* original 1f44, guest PC 0x0c07f89a */
if(!s->budget--) { s->failed_pc=0x0c07f89au; return 0; }
write(ram,r[15]+16,r[4],4);
goto P_0c07f89c;
P_0c07f89c: /* original 61f3, guest PC 0x0c07f89c */
if(!s->budget--) { s->failed_pc=0x0c07f89cu; return 0; }
r[1]=r[15];
goto P_0c07f89e;
P_0c07f89e: /* original 936d, guest PC 0x0c07f89e */
if(!s->budget--) { s->failed_pc=0x0c07f89eu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07f97cu,2);
goto P_0c07f8a0;
P_0c07f8a0: /* original 7114, guest PC 0x0c07f8a0 */
if(!s->budget--) { s->failed_pc=0x0c07f8a0u; return 0; }
r[1]+=0x00000014u;
goto P_0c07f8a2;
P_0c07f8a2: /* original d43d, guest PC 0x0c07f8a2 */
if(!s->budget--) { s->failed_pc=0x0c07f8a2u; return 0; }
r[4]=read(ram,0x0c07f998u,4);
goto P_0c07f8a4;
P_0c07f8a4: /* original 334c, guest PC 0x0c07f8a4 */
if(!s->budget--) { s->failed_pc=0x0c07f8a4u; return 0; }
r[3]+=r[4];
goto P_0c07f8a6;
P_0c07f8a6: /* original 1f31, guest PC 0x0c07f8a6 */
if(!s->budget--) { s->failed_pc=0x0c07f8a6u; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c07f8a8;
P_0c07f8a8: /* original 1f43, guest PC 0x0c07f8a8 */
if(!s->budget--) { s->failed_pc=0x0c07f8a8u; return 0; }
write(ram,r[15]+12,r[4],4);
goto P_0c07f8aa;
P_0c07f8aa: /* original d23c, guest PC 0x0c07f8aa */
if(!s->budget--) { s->failed_pc=0x0c07f8aau; return 0; }
r[2]=read(ram,0x0c07f99cu,4);
goto P_0c07f8ac;
P_0c07f8ac: /* original d33c, guest PC 0x0c07f8ac */
if(!s->budget--) { s->failed_pc=0x0c07f8acu; return 0; }
r[3]=read(ram,0x0c07f9a0u,4);
goto P_0c07f8ae;
P_0c07f8ae: /* original 430b, guest PC 0x0c07f8ae */
if(!s->budget--) { s->failed_pc=0x0c07f8aeu; return 0; }
target=r[3];
r[16]=0x0c07f8b2u;
r[0]=0x00000004u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07f8b2u) { target=s->pc; goto dispatch; }
goto P_0c07f8b2;
P_0c07f8b0: /* original e004, guest PC 0x0c07f8b0 */
if(!s->budget--) { s->failed_pc=0x0c07f8b0u; return 0; }
r[0]=0x00000004u;
goto P_0c07f8b2;
P_0c07f8b2: /* original 9864, guest PC 0x0c07f8b2 */
if(!s->budget--) { s->failed_pc=0x0c07f8b2u; return 0; }
r[8]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07f97eu,2);
goto P_0c07f8b4;
P_0c07f8b4: /* original ec00, guest PC 0x0c07f8b4 */
if(!s->budget--) { s->failed_pc=0x0c07f8b4u; return 0; }
r[12]=0x00000000u;
goto P_0c07f8b6;
P_0c07f8b6: /* original da3c, guest PC 0x0c07f8b6 */
if(!s->budget--) { s->failed_pc=0x0c07f8b6u; return 0; }
r[10]=read(ram,0x0c07f9a8u,4);
goto P_0c07f8b8;
P_0c07f8b8: /* original 6bc3, guest PC 0x0c07f8b8 */
if(!s->budget--) { s->failed_pc=0x0c07f8b8u; return 0; }
r[11]=r[12];
goto P_0c07f8ba;
P_0c07f8ba: /* original dd3c, guest PC 0x0c07f8ba */
if(!s->budget--) { s->failed_pc=0x0c07f8bau; return 0; }
r[13]=read(ram,0x0c07f9acu,4);
goto P_0c07f8bc;
P_0c07f8bc: /* original e92b, guest PC 0x0c07f8bc */
if(!s->budget--) { s->failed_pc=0x0c07f8bcu; return 0; }
r[9]=0x0000002bu;
goto P_0c07f8be;
P_0c07f8be: /* original de39, guest PC 0x0c07f8be */
if(!s->budget--) { s->failed_pc=0x0c07f8beu; return 0; }
r[14]=read(ram,0x0c07f9a4u,4);
goto P_0c07f8c0;
P_0c07f8c0: /* original 925e, guest PC 0x0c07f8c0 */
if(!s->budget--) { s->failed_pc=0x0c07f8c0u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07f980u,2);
goto P_0c07f8c2;
P_0c07f8c2: /* original 32dc, guest PC 0x0c07f8c2 */
if(!s->budget--) { s->failed_pc=0x0c07f8c2u; return 0; }
r[2]+=r[13];
goto P_0c07f8c4;
P_0c07f8c4: /* original 32bc, guest PC 0x0c07f8c4 */
if(!s->budget--) { s->failed_pc=0x0c07f8c4u; return 0; }
r[2]+=r[11];
goto P_0c07f8c6;
P_0c07f8c6: /* original 6320, guest PC 0x0c07f8c6 */
if(!s->budget--) { s->failed_pc=0x0c07f8c6u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[2],1);
r[3]=tmp;
goto P_0c07f8c8;
P_0c07f8c8: /* original 633c, guest PC 0x0c07f8c8 */
if(!s->budget--) { s->failed_pc=0x0c07f8c8u; return 0; }
r[3]=r[3]&255u;
goto P_0c07f8ca;
P_0c07f8ca: /* original 3380, guest PC 0x0c07f8ca */
if(!s->budget--) { s->failed_pc=0x0c07f8cau; return 0; }
r[17]=(r[17]&~1u)|((r[3]==r[8])!=0);
goto P_0c07f8cc;
P_0c07f8cc: /* original 8917, guest PC 0x0c07f8cc */
if(!s->budget--) { s->failed_pc=0x0c07f8ccu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07f8fe; }
goto P_0c07f8ce;
P_0c07f8ce: /* original 63b3, guest PC 0x0c07f8ce */
if(!s->budget--) { s->failed_pc=0x0c07f8ceu; return 0; }
r[3]=r[11];
goto P_0c07f8d0;
P_0c07f8d0: /* original 62b3, guest PC 0x0c07f8d0 */
if(!s->budget--) { s->failed_pc=0x0c07f8d0u; return 0; }
r[2]=r[11];
goto P_0c07f8d2;
P_0c07f8d2: /* original 4308, guest PC 0x0c07f8d2 */
if(!s->budget--) { s->failed_pc=0x0c07f8d2u; return 0; }
r[3]<<=2;
goto P_0c07f8d4;
P_0c07f8d4: /* original 6493, guest PC 0x0c07f8d4 */
if(!s->budget--) { s->failed_pc=0x0c07f8d4u; return 0; }
r[4]=r[9];
goto P_0c07f8d6;
P_0c07f8d6: /* original 4200, guest PC 0x0c07f8d6 */
if(!s->budget--) { s->failed_pc=0x0c07f8d6u; return 0; }
r[17]=(r[17]&~1u)|((r[2]>>31)!=0);
r[2]<<=1;
goto P_0c07f8d8;
P_0c07f8d8: /* original 323c, guest PC 0x0c07f8d8 */
if(!s->budget--) { s->failed_pc=0x0c07f8d8u; return 0; }
r[2]+=r[3];
goto P_0c07f8da;
P_0c07f8da: /* original 3428, guest PC 0x0c07f8da */
if(!s->budget--) { s->failed_pc=0x0c07f8dau; return 0; }
r[4]-=r[2];
goto P_0c07f8dc;
P_0c07f8dc: /* original 9251, guest PC 0x0c07f8dc */
if(!s->budget--) { s->failed_pc=0x0c07f8dcu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07f982u,2);
goto P_0c07f8de;
P_0c07f8de: /* original 4400, guest PC 0x0c07f8de */
if(!s->budget--) { s->failed_pc=0x0c07f8deu; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c07f8e0;
P_0c07f8e0: /* original 242b, guest PC 0x0c07f8e0 */
if(!s->budget--) { s->failed_pc=0x0c07f8e0u; return 0; }
r[4]|=r[2];
goto P_0c07f8e2;
P_0c07f8e2: /* original 6543, guest PC 0x0c07f8e2 */
if(!s->budget--) { s->failed_pc=0x0c07f8e2u; return 0; }
r[5]=r[4];
goto P_0c07f8e4;
P_0c07f8e4: /* original 2f42, guest PC 0x0c07f8e4 */
if(!s->budget--) { s->failed_pc=0x0c07f8e4u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c07f8e6;
P_0c07f8e6: /* original 964b, guest PC 0x0c07f8e6 */
if(!s->budget--) { s->failed_pc=0x0c07f8e6u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07f980u,2);
goto P_0c07f8e8;
P_0c07f8e8: /* original 974c, guest PC 0x0c07f8e8 */
if(!s->budget--) { s->failed_pc=0x0c07f8e8u; return 0; }
r[7]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07f984u,2);
goto P_0c07f8ea;
P_0c07f8ea: /* original 36dc, guest PC 0x0c07f8ea */
if(!s->budget--) { s->failed_pc=0x0c07f8eau; return 0; }
r[6]+=r[13];
goto P_0c07f8ec;
P_0c07f8ec: /* original 36bc, guest PC 0x0c07f8ec */
if(!s->budget--) { s->failed_pc=0x0c07f8ecu; return 0; }
r[6]+=r[11];
goto P_0c07f8ee;
P_0c07f8ee: /* original 6660, guest PC 0x0c07f8ee */
if(!s->budget--) { s->failed_pc=0x0c07f8eeu; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[6],1);
r[6]=tmp;
goto P_0c07f8f0;
P_0c07f8f0: /* original 666c, guest PC 0x0c07f8f0 */
if(!s->budget--) { s->failed_pc=0x0c07f8f0u; return 0; }
r[6]=r[6]&255u;
goto P_0c07f8f2;
P_0c07f8f2: /* original 4a0b, guest PC 0x0c07f8f2 */
if(!s->budget--) { s->failed_pc=0x0c07f8f2u; return 0; }
target=r[10];
r[16]=0x0c07f8f6u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07f8f6u) { target=s->pc; goto dispatch; }
goto P_0c07f8f6;
P_0c07f8f4: /* original 64e3, guest PC 0x0c07f8f4 */
if(!s->budget--) { s->failed_pc=0x0c07f8f4u; return 0; }
r[4]=r[14];
goto P_0c07f8f6;
P_0c07f8f6: /* original e306, guest PC 0x0c07f8f6 */
if(!s->budget--) { s->failed_pc=0x0c07f8f6u; return 0; }
r[3]=0x00000006u;
goto P_0c07f8f8;
P_0c07f8f8: /* original 7b01, guest PC 0x0c07f8f8 */
if(!s->budget--) { s->failed_pc=0x0c07f8f8u; return 0; }
r[11]+=0x00000001u;
goto P_0c07f8fa;
P_0c07f8fa: /* original 3b33, guest PC 0x0c07f8fa */
if(!s->budget--) { s->failed_pc=0x0c07f8fau; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[11]>=(int32_t)r[3])!=0);
goto P_0c07f8fc;
P_0c07f8fc: /* original 8be0, guest PC 0x0c07f8fc */
if(!s->budget--) { s->failed_pc=0x0c07f8fcu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07f8c0; }
goto P_0c07f8fe;
P_0c07f8fe: /* original 54f1, guest PC 0x0c07f8fe */
if(!s->budget--) { s->failed_pc=0x0c07f8feu; return 0; }
r[4]=read(ram,r[15]+4,4);
goto P_0c07f900;
P_0c07f900: /* original d82b, guest PC 0x0c07f900 */
if(!s->budget--) { s->failed_pc=0x0c07f900u; return 0; }
r[8]=read(ram,0x0c07f9b0u,4);
goto P_0c07f902;
P_0c07f902: /* original 480b, guest PC 0x0c07f902 */
if(!s->budget--) { s->failed_pc=0x0c07f902u; return 0; }
target=r[8];
r[16]=0x0c07f906u;
r[4]+=0x00000012u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07f906u) { target=s->pc; goto dispatch; }
goto P_0c07f906;
P_0c07f904: /* original 7412, guest PC 0x0c07f904 */
if(!s->budget--) { s->failed_pc=0x0c07f904u; return 0; }
r[4]+=0x00000012u;
goto P_0c07f906;
P_0c07f906: /* original 640c, guest PC 0x0c07f906 */
if(!s->budget--) { s->failed_pc=0x0c07f906u; return 0; }
r[4]=r[0]&255u;
goto P_0c07f908;
P_0c07f908: /* original 6043, guest PC 0x0c07f908 */
if(!s->budget--) { s->failed_pc=0x0c07f908u; return 0; }
r[0]=r[4];
goto P_0c07f90a;
P_0c07f90a: /* original 8803, guest PC 0x0c07f90a */
if(!s->budget--) { s->failed_pc=0x0c07f90au; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000003u)!=0);
goto P_0c07f90c;
P_0c07f90c: /* original 890a, guest PC 0x0c07f90c */
if(!s->budget--) { s->failed_pc=0x0c07f90cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07f924; }
goto P_0c07f90e;
P_0c07f90e: /* original 903a, guest PC 0x0c07f90e */
if(!s->budget--) { s->failed_pc=0x0c07f90eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07f986u,2);
goto P_0c07f910;
P_0c07f910: /* original 02dc, guest PC 0x0c07f910 */
if(!s->budget--) { s->failed_pc=0x0c07f910u; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+r[0],1);
goto P_0c07f912;
P_0c07f912: /* original 2228, guest PC 0x0c07f912 */
if(!s->budget--) { s->failed_pc=0x0c07f912u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c07f914;
P_0c07f914: /* original 8906, guest PC 0x0c07f914 */
if(!s->budget--) { s->failed_pc=0x0c07f914u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07f924; }
goto P_0c07f916;
P_0c07f916: /* original 9037, guest PC 0x0c07f916 */
if(!s->budget--) { s->failed_pc=0x0c07f916u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07f988u,2);
goto P_0c07f918;
P_0c07f918: /* original d327, guest PC 0x0c07f918 */
if(!s->budget--) { s->failed_pc=0x0c07f918u; return 0; }
r[3]=read(ram,0x0c07f9b8u,4);
goto P_0c07f91a;
P_0c07f91a: /* original 04dc, guest PC 0x0c07f91a */
if(!s->budget--) { s->failed_pc=0x0c07f91au; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+r[0],1);
goto P_0c07f91c;
P_0c07f91c: /* original d025, guest PC 0x0c07f91c */
if(!s->budget--) { s->failed_pc=0x0c07f91cu; return 0; }
r[0]=read(ram,0x0c07f9b4u,4);
goto P_0c07f91e;
P_0c07f91e: /* original 4408, guest PC 0x0c07f91e */
if(!s->budget--) { s->failed_pc=0x0c07f91eu; return 0; }
r[4]<<=2;
goto P_0c07f920;
P_0c07f920: /* original 430b, guest PC 0x0c07f920 */
if(!s->budget--) { s->failed_pc=0x0c07f920u; return 0; }
target=r[3];
r[16]=0x0c07f924u;
r[4]=read(ram,r[4]+r[0],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07f924u) { target=s->pc; goto dispatch; }
goto P_0c07f924;
P_0c07f922: /* original 044e, guest PC 0x0c07f922 */
if(!s->budget--) { s->failed_pc=0x0c07f922u; return 0; }
r[4]=read(ram,r[4]+r[0],4);
goto P_0c07f924;
P_0c07f924: /* original 54f1, guest PC 0x0c07f924 */
if(!s->budget--) { s->failed_pc=0x0c07f924u; return 0; }
r[4]=read(ram,r[15]+4,4);
goto P_0c07f926;
P_0c07f926: /* original 480b, guest PC 0x0c07f926 */
if(!s->budget--) { s->failed_pc=0x0c07f926u; return 0; }
target=r[8];
r[16]=0x0c07f92au;
r[4]+=0x00000012u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07f92au) { target=s->pc; goto dispatch; }
goto P_0c07f92a;
P_0c07f928: /* original 7412, guest PC 0x0c07f928 */
if(!s->budget--) { s->failed_pc=0x0c07f928u; return 0; }
r[4]+=0x00000012u;
goto P_0c07f92a;
P_0c07f92a: /* original 650c, guest PC 0x0c07f92a */
if(!s->budget--) { s->failed_pc=0x0c07f92au; return 0; }
r[5]=r[0]&255u;
goto P_0c07f92c;
P_0c07f92c: /* original 902c, guest PC 0x0c07f92c */
if(!s->budget--) { s->failed_pc=0x0c07f92cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07f988u,2);
goto P_0c07f92e;
P_0c07f92e: /* original 2558, guest PC 0x0c07f92e */
if(!s->budget--) { s->failed_pc=0x0c07f92eu; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[5])==0)!=0);
goto P_0c07f930;
P_0c07f930: /* original 04dc, guest PC 0x0c07f930 */
if(!s->budget--) { s->failed_pc=0x0c07f930u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+r[0],1);
goto P_0c07f932;
P_0c07f932: /* original 6b4e, guest PC 0x0c07f932 */
if(!s->budget--) { s->failed_pc=0x0c07f932u; return 0; }
r[11]=(uint32_t)(int32_t)(int8_t)r[4];
goto P_0c07f934;
P_0c07f934: /* original 8f13, guest PC 0x0c07f934 */
if(!s->budget--) { s->failed_pc=0x0c07f934u; return 0; }
cond=r[17]&1u;
r[11]<<=2;
if(!cond) { goto P_0c07f95e; }
goto P_0c07f938;
P_0c07f936: /* original 4b08, guest PC 0x0c07f936 */
if(!s->budget--) { s->failed_pc=0x0c07f936u; return 0; }
r[11]<<=2;
goto P_0c07f938;
P_0c07f938: /* original d720, guest PC 0x0c07f938 */
if(!s->budget--) { s->failed_pc=0x0c07f938u; return 0; }
r[7]=read(ram,0x0c07f9bcu,4);
goto P_0c07f93a;
P_0c07f93a: /* original 37bc, guest PC 0x0c07f93a */
if(!s->budget--) { s->failed_pc=0x0c07f93au; return 0; }
r[7]+=r[11];
goto P_0c07f93c;
P_0c07f93c: /* original 2f72, guest PC 0x0c07f93c */
if(!s->budget--) { s->failed_pc=0x0c07f93cu; return 0; }
write(ram,r[15],r[7],4);
goto P_0c07f93e;
P_0c07f93e: /* original 66f2, guest PC 0x0c07f93e */
if(!s->budget--) { s->failed_pc=0x0c07f93eu; return 0; }
tmp=read(ram,r[15],4);
r[6]=tmp;
goto P_0c07f940;
P_0c07f940: /* original 9523, guest PC 0x0c07f940 */
if(!s->budget--) { s->failed_pc=0x0c07f940u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07f98au,2);
goto P_0c07f942;
P_0c07f942: /* original 8462, guest PC 0x0c07f942 */
if(!s->budget--) { s->failed_pc=0x0c07f942u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[6]+2,1);
goto P_0c07f944;
P_0c07f944: /* original 6771, guest PC 0x0c07f944 */
if(!s->budget--) { s->failed_pc=0x0c07f944u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[7],2);
r[7]=tmp;
goto P_0c07f946;
P_0c07f946: /* original 6603, guest PC 0x0c07f946 */
if(!s->budget--) { s->failed_pc=0x0c07f946u; return 0; }
r[6]=r[0];
goto P_0c07f948;
P_0c07f948: /* original 4a0b, guest PC 0x0c07f948 */
if(!s->budget--) { s->failed_pc=0x0c07f948u; return 0; }
target=r[10];
r[16]=0x0c07f94cu;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07f94cu) { target=s->pc; goto dispatch; }
goto P_0c07f94c;
P_0c07f94a: /* original 64e3, guest PC 0x0c07f94a */
if(!s->budget--) { s->failed_pc=0x0c07f94au; return 0; }
r[4]=r[14];
goto P_0c07f94c;
P_0c07f94c: /* original 66f2, guest PC 0x0c07f94c */
if(!s->budget--) { s->failed_pc=0x0c07f94cu; return 0; }
tmp=read(ram,r[15],4);
r[6]=tmp;
goto P_0c07f94e;
P_0c07f94e: /* original 951e, guest PC 0x0c07f94e */
if(!s->budget--) { s->failed_pc=0x0c07f94eu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07f98eu,2);
goto P_0c07f950;
P_0c07f950: /* original 8463, guest PC 0x0c07f950 */
if(!s->budget--) { s->failed_pc=0x0c07f950u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[6]+3,1);
goto P_0c07f952;
P_0c07f952: /* original 971b, guest PC 0x0c07f952 */
if(!s->budget--) { s->failed_pc=0x0c07f952u; return 0; }
r[7]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07f98cu,2);
goto P_0c07f954;
P_0c07f954: /* original 6603, guest PC 0x0c07f954 */
if(!s->budget--) { s->failed_pc=0x0c07f954u; return 0; }
r[6]=r[0];
goto P_0c07f956;
P_0c07f956: /* original 4a0b, guest PC 0x0c07f956 */
if(!s->budget--) { s->failed_pc=0x0c07f956u; return 0; }
target=r[10];
r[16]=0x0c07f95au;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07f95au) { target=s->pc; goto dispatch; }
goto P_0c07f95a;
P_0c07f958: /* original 64e3, guest PC 0x0c07f958 */
if(!s->budget--) { s->failed_pc=0x0c07f958u; return 0; }
r[4]=r[14];
goto P_0c07f95a;
P_0c07f95a: /* original a046, guest PC 0x0c07f95a */
if(!s->budget--) { s->failed_pc=0x0c07f95au; return 0; }
r[9]=r[0];
goto P_0c07f9ea;
P_0c07f95c: /* original 6903, guest PC 0x0c07f95c */
if(!s->budget--) { s->failed_pc=0x0c07f95cu; return 0; }
r[9]=r[0];
goto P_0c07f95e;
P_0c07f95e: /* original e20e, guest PC 0x0c07f95e */
if(!s->budget--) { s->failed_pc=0x0c07f95eu; return 0; }
r[2]=0x0000000eu;
goto P_0c07f960;
P_0c07f960: /* original 644e, guest PC 0x0c07f960 */
if(!s->budget--) { s->failed_pc=0x0c07f960u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)r[4];
goto P_0c07f962;
P_0c07f962: /* original 3423, guest PC 0x0c07f962 */
if(!s->budget--) { s->failed_pc=0x0c07f962u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[2])!=0);
goto P_0c07f964;
P_0c07f964: /* original 892e, guest PC 0x0c07f964 */
if(!s->budget--) { s->failed_pc=0x0c07f964u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07f9c4; }
goto P_0c07f966;
P_0c07f966: /* original d716, guest PC 0x0c07f966 */
if(!s->budget--) { s->failed_pc=0x0c07f966u; return 0; }
r[7]=read(ram,0x0c07f9c0u,4);
goto P_0c07f968;
P_0c07f968: /* original 37bc, guest PC 0x0c07f968 */
if(!s->budget--) { s->failed_pc=0x0c07f968u; return 0; }
r[7]+=r[11];
goto P_0c07f96a;
P_0c07f96a: /* original 2f72, guest PC 0x0c07f96a */
if(!s->budget--) { s->failed_pc=0x0c07f96au; return 0; }
write(ram,r[15],r[7],4);
goto P_0c07f96c;
P_0c07f96c: /* original 66f2, guest PC 0x0c07f96c */
if(!s->budget--) { s->failed_pc=0x0c07f96cu; return 0; }
tmp=read(ram,r[15],4);
r[6]=tmp;
goto P_0c07f96e;
P_0c07f96e: /* original 950f, guest PC 0x0c07f96e */
if(!s->budget--) { s->failed_pc=0x0c07f96eu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07f990u,2);
goto P_0c07f970;
P_0c07f970: /* original 8462, guest PC 0x0c07f970 */
if(!s->budget--) { s->failed_pc=0x0c07f970u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[6]+2,1);
goto P_0c07f972;
P_0c07f972: /* original 6771, guest PC 0x0c07f972 */
if(!s->budget--) { s->failed_pc=0x0c07f972u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[7],2);
r[7]=tmp;
goto P_0c07f974;
P_0c07f974: /* original a036, guest PC 0x0c07f974 */
if(!s->budget--) { s->failed_pc=0x0c07f974u; return 0; }
r[6]=r[0];
goto P_0c07f9e4;
P_0c07f976: /* original 6603, guest PC 0x0c07f976 */
if(!s->budget--) { s->failed_pc=0x0c07f976u; return 0; }
r[6]=r[0];
return vf3_matrix_family(0x0c07f978u,s,ram);
P_0c07f9c4: /* original d750, guest PC 0x0c07f9c4 */
if(!s->budget--) { s->failed_pc=0x0c07f9c4u; return 0; }
r[7]=read(ram,0x0c07fb08u,4);
goto P_0c07f9c6;
P_0c07f9c6: /* original 37bc, guest PC 0x0c07f9c6 */
if(!s->budget--) { s->failed_pc=0x0c07f9c6u; return 0; }
r[7]+=r[11];
goto P_0c07f9c8;
P_0c07f9c8: /* original 2f72, guest PC 0x0c07f9c8 */
if(!s->budget--) { s->failed_pc=0x0c07f9c8u; return 0; }
write(ram,r[15],r[7],4);
goto P_0c07f9ca;
P_0c07f9ca: /* original 66f2, guest PC 0x0c07f9ca */
if(!s->budget--) { s->failed_pc=0x0c07f9cau; return 0; }
tmp=read(ram,r[15],4);
r[6]=tmp;
goto P_0c07f9cc;
P_0c07f9cc: /* original 9588, guest PC 0x0c07f9cc */
if(!s->budget--) { s->failed_pc=0x0c07f9ccu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07fae0u,2);
goto P_0c07f9ce;
P_0c07f9ce: /* original 8462, guest PC 0x0c07f9ce */
if(!s->budget--) { s->failed_pc=0x0c07f9ceu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[6]+2,1);
goto P_0c07f9d0;
P_0c07f9d0: /* original 6771, guest PC 0x0c07f9d0 */
if(!s->budget--) { s->failed_pc=0x0c07f9d0u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[7],2);
r[7]=tmp;
goto P_0c07f9d2;
P_0c07f9d2: /* original 6603, guest PC 0x0c07f9d2 */
if(!s->budget--) { s->failed_pc=0x0c07f9d2u; return 0; }
r[6]=r[0];
goto P_0c07f9d4;
P_0c07f9d4: /* original 4a0b, guest PC 0x0c07f9d4 */
if(!s->budget--) { s->failed_pc=0x0c07f9d4u; return 0; }
target=r[10];
r[16]=0x0c07f9d8u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07f9d8u) { target=s->pc; goto dispatch; }
goto P_0c07f9d8;
P_0c07f9d6: /* original 64e3, guest PC 0x0c07f9d6 */
if(!s->budget--) { s->failed_pc=0x0c07f9d6u; return 0; }
r[4]=r[14];
goto P_0c07f9d8;
P_0c07f9d8: /* original 66f2, guest PC 0x0c07f9d8 */
if(!s->budget--) { s->failed_pc=0x0c07f9d8u; return 0; }
tmp=read(ram,r[15],4);
r[6]=tmp;
goto P_0c07f9da;
P_0c07f9da: /* original 67f2, guest PC 0x0c07f9da */
if(!s->budget--) { s->failed_pc=0x0c07f9dau; return 0; }
tmp=read(ram,r[15],4);
r[7]=tmp;
goto P_0c07f9dc;
P_0c07f9dc: /* original 8463, guest PC 0x0c07f9dc */
if(!s->budget--) { s->failed_pc=0x0c07f9dcu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[6]+3,1);
goto P_0c07f9de;
P_0c07f9de: /* original 9580, guest PC 0x0c07f9de */
if(!s->budget--) { s->failed_pc=0x0c07f9deu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07fae2u,2);
goto P_0c07f9e0;
P_0c07f9e0: /* original 6771, guest PC 0x0c07f9e0 */
if(!s->budget--) { s->failed_pc=0x0c07f9e0u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[7],2);
r[7]=tmp;
goto P_0c07f9e2;
P_0c07f9e2: /* original 6603, guest PC 0x0c07f9e2 */
if(!s->budget--) { s->failed_pc=0x0c07f9e2u; return 0; }
r[6]=r[0];
goto P_0c07f9e4;
P_0c07f9e4: /* original 4a0b, guest PC 0x0c07f9e4 */
if(!s->budget--) { s->failed_pc=0x0c07f9e4u; return 0; }
target=r[10];
r[16]=0x0c07f9e8u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07f9e8u) { target=s->pc; goto dispatch; }
goto P_0c07f9e8;
P_0c07f9e6: /* original 64e3, guest PC 0x0c07f9e6 */
if(!s->budget--) { s->failed_pc=0x0c07f9e6u; return 0; }
r[4]=r[14];
goto P_0c07f9e8;
P_0c07f9e8: /* original 6903, guest PC 0x0c07f9e8 */
if(!s->budget--) { s->failed_pc=0x0c07f9e8u; return 0; }
r[9]=r[0];
goto P_0c07f9ea;
P_0c07f9ea: /* original 907b, guest PC 0x0c07f9ea */
if(!s->budget--) { s->failed_pc=0x0c07f9eau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07fae4u,2);
goto P_0c07f9ec;
P_0c07f9ec: /* original 03dc, guest PC 0x0c07f9ec */
if(!s->budget--) { s->failed_pc=0x0c07f9ecu; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+r[0],1);
goto P_0c07f9ee;
P_0c07f9ee: /* original 2338, guest PC 0x0c07f9ee */
if(!s->budget--) { s->failed_pc=0x0c07f9eeu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c07f9f0;
P_0c07f9f0: /* original 8b01, guest PC 0x0c07f9f0 */
if(!s->budget--) { s->failed_pc=0x0c07f9f0u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07f9f6; }
goto P_0c07f9f2;
P_0c07f9f2: /* original a0e8, guest PC 0x0c07f9f2 */
if(!s->budget--) { s->failed_pc=0x0c07f9f2u; return 0; }
goto P_0c07fbc6;
P_0c07f9f4: /* original 0009, guest PC 0x0c07f9f4 */
if(!s->budget--) { s->failed_pc=0x0c07f9f4u; return 0; }
goto P_0c07f9f6;
P_0c07f9f6: /* original 0dc4, guest PC 0x0c07f9f6 */
if(!s->budget--) { s->failed_pc=0x0c07f9f6u; return 0; }
write(ram,r[13]+r[0],r[12],1);
goto P_0c07f9f8;
P_0c07f9f8: /* original 54f1, guest PC 0x0c07f9f8 */
if(!s->budget--) { s->failed_pc=0x0c07f9f8u; return 0; }
r[4]=read(ram,r[15]+4,4);
goto P_0c07f9fa;
P_0c07f9fa: /* original 480b, guest PC 0x0c07f9fa */
if(!s->budget--) { s->failed_pc=0x0c07f9fau; return 0; }
target=r[8];
r[16]=0x0c07f9feu;
r[4]+=0x00000012u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07f9feu) { target=s->pc; goto dispatch; }
goto P_0c07f9fe;
P_0c07f9fc: /* original 7412, guest PC 0x0c07f9fc */
if(!s->budget--) { s->failed_pc=0x0c07f9fcu; return 0; }
r[4]+=0x00000012u;
goto P_0c07f9fe;
P_0c07f9fe: /* original 600c, guest PC 0x0c07f9fe */
if(!s->budget--) { s->failed_pc=0x0c07f9feu; return 0; }
r[0]=r[0]&255u;
goto P_0c07fa00;
P_0c07fa00: /* original 1f01, guest PC 0x0c07fa00 */
if(!s->budget--) { s->failed_pc=0x0c07fa00u; return 0; }
write(ram,r[15]+4,r[0],4);
goto P_0c07fa02;
P_0c07fa02: /* original 9070, guest PC 0x0c07fa02 */
if(!s->budget--) { s->failed_pc=0x0c07fa02u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07fae6u,2);
goto P_0c07fa04;
P_0c07fa04: /* original db41, guest PC 0x0c07fa04 */
if(!s->budget--) { s->failed_pc=0x0c07fa04u; return 0; }
r[11]=read(ram,0x0c07fb0cu,4);
goto P_0c07fa06;
P_0c07fa06: /* original 09dc, guest PC 0x0c07fa06 */
if(!s->budget--) { s->failed_pc=0x0c07fa06u; return 0; }
r[9]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+r[0],1);
goto P_0c07fa08;
P_0c07fa08: /* original 639e, guest PC 0x0c07fa08 */
if(!s->budget--) { s->failed_pc=0x0c07fa08u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)r[9];
goto P_0c07fa0a;
P_0c07fa0a: /* original 2f32, guest PC 0x0c07fa0a */
if(!s->budget--) { s->failed_pc=0x0c07fa0au; return 0; }
write(ram,r[15],r[3],4);
goto P_0c07fa0c;
P_0c07fa0c: /* original 52f1, guest PC 0x0c07fa0c */
if(!s->budget--) { s->failed_pc=0x0c07fa0cu; return 0; }
r[2]=read(ram,r[15]+4,4);
goto P_0c07fa0e;
P_0c07fa0e: /* original 2228, guest PC 0x0c07fa0e */
if(!s->budget--) { s->failed_pc=0x0c07fa0eu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c07fa10;
P_0c07fa10: /* original 8b13, guest PC 0x0c07fa10 */
if(!s->budget--) { s->failed_pc=0x0c07fa10u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07fa3a; }
goto P_0c07fa12;
P_0c07fa12: /* original 2fc6, guest PC 0x0c07fa12 */
if(!s->budget--) { s->failed_pc=0x0c07fa12u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07fa14;
P_0c07fa14: /* original e700, guest PC 0x0c07fa14 */
if(!s->budget--) { s->failed_pc=0x0c07fa14u; return 0; }
r[7]=0x00000000u;
goto P_0c07fa16;
P_0c07fa16: /* original 9567, guest PC 0x0c07fa16 */
if(!s->budget--) { s->failed_pc=0x0c07fa16u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07fae8u,2);
goto P_0c07fa18;
P_0c07fa18: /* original 9467, guest PC 0x0c07fa18 */
if(!s->budget--) { s->failed_pc=0x0c07fa18u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07faeau,2);
goto P_0c07fa1a;
P_0c07fa1a: /* original 4b0b, guest PC 0x0c07fa1a */
if(!s->budget--) { s->failed_pc=0x0c07fa1au; return 0; }
target=r[11];
r[16]=0x0c07fa1eu;
r[6]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07fa1eu) { target=s->pc; goto dispatch; }
goto P_0c07fa1e;
P_0c07fa1c: /* original 66e3, guest PC 0x0c07fa1c */
if(!s->budget--) { s->failed_pc=0x0c07fa1cu; return 0; }
r[6]=r[14];
goto P_0c07fa1e;
P_0c07fa1e: /* original 2fc6, guest PC 0x0c07fa1e */
if(!s->budget--) { s->failed_pc=0x0c07fa1eu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07fa20;
P_0c07fa20: /* original e700, guest PC 0x0c07fa20 */
if(!s->budget--) { s->failed_pc=0x0c07fa20u; return 0; }
r[7]=0x00000000u;
goto P_0c07fa22;
P_0c07fa22: /* original 9563, guest PC 0x0c07fa22 */
if(!s->budget--) { s->failed_pc=0x0c07fa22u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07faecu,2);
goto P_0c07fa24;
P_0c07fa24: /* original 9463, guest PC 0x0c07fa24 */
if(!s->budget--) { s->failed_pc=0x0c07fa24u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07faeeu,2);
goto P_0c07fa26;
P_0c07fa26: /* original 4b0b, guest PC 0x0c07fa26 */
if(!s->budget--) { s->failed_pc=0x0c07fa26u; return 0; }
target=r[11];
r[16]=0x0c07fa2au;
r[6]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07fa2au) { target=s->pc; goto dispatch; }
goto P_0c07fa2a;
P_0c07fa28: /* original 66e3, guest PC 0x0c07fa28 */
if(!s->budget--) { s->failed_pc=0x0c07fa28u; return 0; }
r[6]=r[14];
goto P_0c07fa2a;
P_0c07fa2a: /* original 2fc6, guest PC 0x0c07fa2a */
if(!s->budget--) { s->failed_pc=0x0c07fa2au; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07fa2c;
P_0c07fa2c: /* original e700, guest PC 0x0c07fa2c */
if(!s->budget--) { s->failed_pc=0x0c07fa2cu; return 0; }
r[7]=0x00000000u;
goto P_0c07fa2e;
P_0c07fa2e: /* original 955f, guest PC 0x0c07fa2e */
if(!s->budget--) { s->failed_pc=0x0c07fa2eu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07faf0u,2);
goto P_0c07fa30;
P_0c07fa30: /* original 945f, guest PC 0x0c07fa30 */
if(!s->budget--) { s->failed_pc=0x0c07fa30u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07faf2u,2);
goto P_0c07fa32;
P_0c07fa32: /* original 4b0b, guest PC 0x0c07fa32 */
if(!s->budget--) { s->failed_pc=0x0c07fa32u; return 0; }
target=r[11];
r[16]=0x0c07fa36u;
r[6]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07fa36u) { target=s->pc; goto dispatch; }
goto P_0c07fa36;
P_0c07fa34: /* original 66e3, guest PC 0x0c07fa34 */
if(!s->budget--) { s->failed_pc=0x0c07fa34u; return 0; }
r[6]=r[14];
goto P_0c07fa36;
P_0c07fa36: /* original a01e, guest PC 0x0c07fa36 */
if(!s->budget--) { s->failed_pc=0x0c07fa36u; return 0; }
r[15]+=0x0000000cu;
goto P_0c07fa76;
P_0c07fa38: /* original 7f0c, guest PC 0x0c07fa38 */
if(!s->budget--) { s->failed_pc=0x0c07fa38u; return 0; }
r[15]+=0x0000000cu;
goto P_0c07fa3a;
P_0c07fa3a: /* original 2fc6, guest PC 0x0c07fa3a */
if(!s->budget--) { s->failed_pc=0x0c07fa3au; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07fa3c;
P_0c07fa3c: /* original e700, guest PC 0x0c07fa3c */
if(!s->budget--) { s->failed_pc=0x0c07fa3cu; return 0; }
r[7]=0x00000000u;
goto P_0c07fa3e;
P_0c07fa3e: /* original 9559, guest PC 0x0c07fa3e */
if(!s->budget--) { s->failed_pc=0x0c07fa3eu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07faf4u,2);
goto P_0c07fa40;
P_0c07fa40: /* original 9459, guest PC 0x0c07fa40 */
if(!s->budget--) { s->failed_pc=0x0c07fa40u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07faf6u,2);
goto P_0c07fa42;
P_0c07fa42: /* original 4b0b, guest PC 0x0c07fa42 */
if(!s->budget--) { s->failed_pc=0x0c07fa42u; return 0; }
target=r[11];
r[16]=0x0c07fa46u;
r[6]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07fa46u) { target=s->pc; goto dispatch; }
goto P_0c07fa46;
P_0c07fa44: /* original 66e3, guest PC 0x0c07fa44 */
if(!s->budget--) { s->failed_pc=0x0c07fa44u; return 0; }
r[6]=r[14];
goto P_0c07fa46;
P_0c07fa46: /* original 7f04, guest PC 0x0c07fa46 */
if(!s->budget--) { s->failed_pc=0x0c07fa46u; return 0; }
r[15]+=0x00000004u;
goto P_0c07fa48;
P_0c07fa48: /* original 63f2, guest PC 0x0c07fa48 */
if(!s->budget--) { s->failed_pc=0x0c07fa48u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c07fa4a;
P_0c07fa4a: /* original e20e, guest PC 0x0c07fa4a */
if(!s->budget--) { s->failed_pc=0x0c07fa4au; return 0; }
r[2]=0x0000000eu;
goto P_0c07fa4c;
P_0c07fa4c: /* original 3323, guest PC 0x0c07fa4c */
if(!s->budget--) { s->failed_pc=0x0c07fa4cu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>=(int32_t)r[2])!=0);
goto P_0c07fa4e;
P_0c07fa4e: /* original 8912, guest PC 0x0c07fa4e */
if(!s->budget--) { s->failed_pc=0x0c07fa4eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07fa76; }
goto P_0c07fa50;
P_0c07fa50: /* original 2fc6, guest PC 0x0c07fa50 */
if(!s->budget--) { s->failed_pc=0x0c07fa50u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07fa52;
P_0c07fa52: /* original e700, guest PC 0x0c07fa52 */
if(!s->budget--) { s->failed_pc=0x0c07fa52u; return 0; }
r[7]=0x00000000u;
goto P_0c07fa54;
P_0c07fa54: /* original 9550, guest PC 0x0c07fa54 */
if(!s->budget--) { s->failed_pc=0x0c07fa54u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07faf8u,2);
goto P_0c07fa56;
P_0c07fa56: /* original 9450, guest PC 0x0c07fa56 */
if(!s->budget--) { s->failed_pc=0x0c07fa56u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07fafau,2);
goto P_0c07fa58;
P_0c07fa58: /* original 4b0b, guest PC 0x0c07fa58 */
if(!s->budget--) { s->failed_pc=0x0c07fa58u; return 0; }
target=r[11];
r[16]=0x0c07fa5cu;
r[6]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07fa5cu) { target=s->pc; goto dispatch; }
goto P_0c07fa5c;
P_0c07fa5a: /* original 66e3, guest PC 0x0c07fa5a */
if(!s->budget--) { s->failed_pc=0x0c07fa5au; return 0; }
r[6]=r[14];
goto P_0c07fa5c;
P_0c07fa5c: /* original 659e, guest PC 0x0c07fa5c */
if(!s->budget--) { s->failed_pc=0x0c07fa5cu; return 0; }
r[5]=(uint32_t)(int32_t)(int8_t)r[9];
goto P_0c07fa5e;
P_0c07fa5e: /* original 2fc6, guest PC 0x0c07fa5e */
if(!s->budget--) { s->failed_pc=0x0c07fa5eu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07fa60;
P_0c07fa60: /* original d02b, guest PC 0x0c07fa60 */
if(!s->budget--) { s->failed_pc=0x0c07fa60u; return 0; }
r[0]=read(ram,0x0c07fb10u,4);
goto P_0c07fa62;
P_0c07fa62: /* original 4508, guest PC 0x0c07fa62 */
if(!s->budget--) { s->failed_pc=0x0c07fa62u; return 0; }
r[5]<<=2;
goto P_0c07fa64;
P_0c07fa64: /* original 944a, guest PC 0x0c07fa64 */
if(!s->budget--) { s->failed_pc=0x0c07fa64u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07fafcu,2);
goto P_0c07fa66;
P_0c07fa66: /* original e700, guest PC 0x0c07fa66 */
if(!s->budget--) { s->failed_pc=0x0c07fa66u; return 0; }
r[7]=0x00000000u;
goto P_0c07fa68;
P_0c07fa68: /* original 055c, guest PC 0x0c07fa68 */
if(!s->budget--) { s->failed_pc=0x0c07fa68u; return 0; }
r[5]=(uint32_t)(int32_t)(int8_t)read(ram,r[5]+r[0],1);
goto P_0c07fa6a;
P_0c07fa6a: /* original 66e3, guest PC 0x0c07fa6a */
if(!s->budget--) { s->failed_pc=0x0c07fa6au; return 0; }
r[6]=r[14];
goto P_0c07fa6c;
P_0c07fa6c: /* original d029, guest PC 0x0c07fa6c */
if(!s->budget--) { s->failed_pc=0x0c07fa6cu; return 0; }
r[0]=read(ram,0x0c07fb14u,4);
goto P_0c07fa6e;
P_0c07fa6e: /* original 4500, guest PC 0x0c07fa6e */
if(!s->budget--) { s->failed_pc=0x0c07fa6eu; return 0; }
r[17]=(r[17]&~1u)|((r[5]>>31)!=0);
r[5]<<=1;
goto P_0c07fa70;
P_0c07fa70: /* original 4b0b, guest PC 0x0c07fa70 */
if(!s->budget--) { s->failed_pc=0x0c07fa70u; return 0; }
target=r[11];
r[16]=0x0c07fa74u;
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,r[5]+r[0],2);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07fa74u) { target=s->pc; goto dispatch; }
goto P_0c07fa74;
P_0c07fa72: /* original 055d, guest PC 0x0c07fa72 */
if(!s->budget--) { s->failed_pc=0x0c07fa72u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,r[5]+r[0],2);
goto P_0c07fa74;
P_0c07fa74: /* original 7f08, guest PC 0x0c07fa74 */
if(!s->budget--) { s->failed_pc=0x0c07fa74u; return 0; }
r[15]+=0x00000008u;
goto P_0c07fa76;
P_0c07fa76: /* original 63f2, guest PC 0x0c07fa76 */
if(!s->budget--) { s->failed_pc=0x0c07fa76u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c07fa78;
P_0c07fa78: /* original e20e, guest PC 0x0c07fa78 */
if(!s->budget--) { s->failed_pc=0x0c07fa78u; return 0; }
r[2]=0x0000000eu;
goto P_0c07fa7a;
P_0c07fa7a: /* original 9940, guest PC 0x0c07fa7a */
if(!s->budget--) { s->failed_pc=0x0c07fa7au; return 0; }
r[9]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07fafeu,2);
goto P_0c07fa7c;
P_0c07fa7c: /* original 3323, guest PC 0x0c07fa7c */
if(!s->budget--) { s->failed_pc=0x0c07fa7cu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>=(int32_t)r[2])!=0);
goto P_0c07fa7e;
P_0c07fa7e: /* original 8920, guest PC 0x0c07fa7e */
if(!s->budget--) { s->failed_pc=0x0c07fa7eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07fac2; }
goto P_0c07fa80;
P_0c07fa80: /* original 55d2, guest PC 0x0c07fa80 */
if(!s->budget--) { s->failed_pc=0x0c07fa80u; return 0; }
r[5]=read(ram,r[13]+8,4);
goto P_0c07fa82;
P_0c07fa82: /* original e310, guest PC 0x0c07fa82 */
if(!s->budget--) { s->failed_pc=0x0c07fa82u; return 0; }
r[3]=0x00000010u;
goto P_0c07fa84;
P_0c07fa84: /* original 2538, guest PC 0x0c07fa84 */
if(!s->budget--) { s->failed_pc=0x0c07fa84u; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[3])==0)!=0);
goto P_0c07fa86;
P_0c07fa86: /* original 8d01, guest PC 0x0c07fa86 */
if(!s->budget--) { s->failed_pc=0x0c07fa86u; return 0; }
cond=r[17]&1u;
r[4]=0x00000006u;
if(cond) { goto P_0c07fa8c; }
goto P_0c07fa8a;
P_0c07fa88: /* original e406, guest PC 0x0c07fa88 */
if(!s->budget--) { s->failed_pc=0x0c07fa88u; return 0; }
r[4]=0x00000006u;
goto P_0c07fa8a;
P_0c07fa8a: /* original e405, guest PC 0x0c07fa8a */
if(!s->budget--) { s->failed_pc=0x0c07fa8au; return 0; }
r[4]=0x00000005u;
goto P_0c07fa8c;
P_0c07fa8c: /* original 9038, guest PC 0x0c07fa8c */
if(!s->budget--) { s->failed_pc=0x0c07fa8cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07fb00u,2);
goto P_0c07fa8e;
P_0c07fa8e: /* original d322, guest PC 0x0c07fa8e */
if(!s->budget--) { s->failed_pc=0x0c07fa8eu; return 0; }
r[3]=read(ram,0x0c07fb18u,4);
goto P_0c07fa90;
P_0c07fa90: /* original 06dd, guest PC 0x0c07fa90 */
if(!s->budget--) { s->failed_pc=0x0c07fa90u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,r[13]+r[0],2);
goto P_0c07fa92;
P_0c07fa92: /* original 656f, guest PC 0x0c07fa92 */
if(!s->budget--) { s->failed_pc=0x0c07fa92u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)r[6];
goto P_0c07fa94;
P_0c07fa94: /* original 6153, guest PC 0x0c07fa94 */
if(!s->budget--) { s->failed_pc=0x0c07fa94u; return 0; }
r[1]=r[5];
goto P_0c07fa96;
P_0c07fa96: /* original 430b, guest PC 0x0c07fa96 */
if(!s->budget--) { s->failed_pc=0x0c07fa96u; return 0; }
target=r[3];
r[16]=0x0c07fa9au;
r[0]=r[4];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07fa9au) { target=s->pc; goto dispatch; }
goto P_0c07fa9a;
P_0c07fa98: /* original 6043, guest PC 0x0c07fa98 */
if(!s->budget--) { s->failed_pc=0x0c07fa98u; return 0; }
r[0]=r[4];
goto P_0c07fa9a;
P_0c07fa9a: /* original 0047, guest PC 0x0c07fa9a */
if(!s->budget--) { s->failed_pc=0x0c07fa9au; return 0; }
r[19]=r[0]*r[4];
goto P_0c07fa9c;
P_0c07fa9c: /* original 52f1, guest PC 0x0c07fa9c */
if(!s->budget--) { s->failed_pc=0x0c07fa9cu; return 0; }
r[2]=read(ram,r[15]+4,4);
goto P_0c07fa9e;
P_0c07fa9e: /* original 2228, guest PC 0x0c07fa9e */
if(!s->budget--) { s->failed_pc=0x0c07fa9eu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c07faa0;
P_0c07faa0: /* original 041a, guest PC 0x0c07faa0 */
if(!s->budget--) { s->failed_pc=0x0c07faa0u; return 0; }
r[4]=r[19];
goto P_0c07faa2;
P_0c07faa2: /* original 3548, guest PC 0x0c07faa2 */
if(!s->budget--) { s->failed_pc=0x0c07faa2u; return 0; }
r[5]-=r[4];
goto P_0c07faa4;
P_0c07faa4: /* original d41d, guest PC 0x0c07faa4 */
if(!s->budget--) { s->failed_pc=0x0c07faa4u; return 0; }
r[4]=read(ram,0x0c07fb1cu,4);
goto P_0c07faa6;
P_0c07faa6: /* original 8d01, guest PC 0x0c07faa6 */
if(!s->budget--) { s->failed_pc=0x0c07faa6u; return 0; }
cond=r[17]&1u;
r[0]=r[5];
if(cond) { goto P_0c07faac; }
goto P_0c07faaa;
P_0c07faa8: /* original 6053, guest PC 0x0c07faa8 */
if(!s->budget--) { s->failed_pc=0x0c07faa8u; return 0; }
r[0]=r[5];
goto P_0c07faaa;
P_0c07faaa: /* original d41d, guest PC 0x0c07faaa */
if(!s->budget--) { s->failed_pc=0x0c07faaau; return 0; }
r[4]=read(ram,0x0c07fb20u,4);
goto P_0c07faac;
P_0c07faac: /* original 4000, guest PC 0x0c07faac */
if(!s->budget--) { s->failed_pc=0x0c07faacu; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c07faae;
P_0c07faae: /* original 66e3, guest PC 0x0c07faae */
if(!s->budget--) { s->failed_pc=0x0c07faaeu; return 0; }
r[6]=r[14];
goto P_0c07fab0;
P_0c07fab0: /* original 034d, guest PC 0x0c07fab0 */
if(!s->budget--) { s->failed_pc=0x0c07fab0u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c07fab2;
P_0c07fab2: /* original e700, guest PC 0x0c07fab2 */
if(!s->budget--) { s->failed_pc=0x0c07fab2u; return 0; }
r[7]=0x00000000u;
goto P_0c07fab4;
P_0c07fab4: /* original 2f31, guest PC 0x0c07fab4 */
if(!s->budget--) { s->failed_pc=0x0c07fab4u; return 0; }
write(ram,r[15],r[3],2);
goto P_0c07fab6;
P_0c07fab6: /* original 2fc6, guest PC 0x0c07fab6 */
if(!s->budget--) { s->failed_pc=0x0c07fab6u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07fab8;
P_0c07fab8: /* original 9421, guest PC 0x0c07fab8 */
if(!s->budget--) { s->failed_pc=0x0c07fab8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07fafeu,2);
goto P_0c07faba;
P_0c07faba: /* original 4b0b, guest PC 0x0c07faba */
if(!s->budget--) { s->failed_pc=0x0c07fabau; return 0; }
target=r[11];
r[16]=0x0c07fabeu;
r[5]=(uint32_t)(int32_t)(int16_t)r[3];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07fabeu) { target=s->pc; goto dispatch; }
goto P_0c07fabe;
P_0c07fabc: /* original 653f, guest PC 0x0c07fabc */
if(!s->budget--) { s->failed_pc=0x0c07fabcu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)r[3];
goto P_0c07fabe;
P_0c07fabe: /* original a03f, guest PC 0x0c07fabe */
if(!s->budget--) { s->failed_pc=0x0c07fabeu; return 0; }
r[15]+=0x00000004u;
goto P_0c07fb40;
P_0c07fac0: /* original 7f04, guest PC 0x0c07fac0 */
if(!s->budget--) { s->failed_pc=0x0c07fac0u; return 0; }
r[15]+=0x00000004u;
goto P_0c07fac2;
P_0c07fac2: /* original 51f1, guest PC 0x0c07fac2 */
if(!s->budget--) { s->failed_pc=0x0c07fac2u; return 0; }
r[1]=read(ram,r[15]+4,4);
goto P_0c07fac4;
P_0c07fac4: /* original 2118, guest PC 0x0c07fac4 */
if(!s->budget--) { s->failed_pc=0x0c07fac4u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[1])==0)!=0);
goto P_0c07fac6;
P_0c07fac6: /* original 8b2d, guest PC 0x0c07fac6 */
if(!s->budget--) { s->failed_pc=0x0c07fac6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07fb24; }
goto P_0c07fac8;
P_0c07fac8: /* original 2fc6, guest PC 0x0c07fac8 */
if(!s->budget--) { s->failed_pc=0x0c07fac8u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07faca;
P_0c07faca: /* original e700, guest PC 0x0c07faca */
if(!s->budget--) { s->failed_pc=0x0c07facau; return 0; }
r[7]=0x00000000u;
goto P_0c07facc;
P_0c07facc: /* original 9519, guest PC 0x0c07facc */
if(!s->budget--) { s->failed_pc=0x0c07faccu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07fb02u,2);
goto P_0c07face;
P_0c07face: /* original 9416, guest PC 0x0c07face */
if(!s->budget--) { s->failed_pc=0x0c07faceu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07fafeu,2);
goto P_0c07fad0;
P_0c07fad0: /* original 4b0b, guest PC 0x0c07fad0 */
if(!s->budget--) { s->failed_pc=0x0c07fad0u; return 0; }
target=r[11];
r[16]=0x0c07fad4u;
r[6]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07fad4u) { target=s->pc; goto dispatch; }
goto P_0c07fad4;
P_0c07fad2: /* original 66e3, guest PC 0x0c07fad2 */
if(!s->budget--) { s->failed_pc=0x0c07fad2u; return 0; }
r[6]=r[14];
goto P_0c07fad4;
P_0c07fad4: /* original 9916, guest PC 0x0c07fad4 */
if(!s->budget--) { s->failed_pc=0x0c07fad4u; return 0; }
r[9]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07fb04u,2);
goto P_0c07fad6;
P_0c07fad6: /* original e700, guest PC 0x0c07fad6 */
if(!s->budget--) { s->failed_pc=0x0c07fad6u; return 0; }
r[7]=0x00000000u;
goto P_0c07fad8;
P_0c07fad8: /* original 2fc6, guest PC 0x0c07fad8 */
if(!s->budget--) { s->failed_pc=0x0c07fad8u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07fada;
P_0c07fada: /* original 9514, guest PC 0x0c07fada */
if(!s->budget--) { s->failed_pc=0x0c07fadau; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07fb06u,2);
goto P_0c07fadc;
P_0c07fadc: /* original a02d, guest PC 0x0c07fadc */
if(!s->budget--) { s->failed_pc=0x0c07fadcu; return 0; }
r[6]=r[14];
goto P_0c07fb3a;
P_0c07fade: /* original 66e3, guest PC 0x0c07fade */
if(!s->budget--) { s->failed_pc=0x0c07fadeu; return 0; }
r[6]=r[14];
return vf3_matrix_family(0x0c07fae0u,s,ram);
P_0c07fb24: /* original 2fc6, guest PC 0x0c07fb24 */
if(!s->budget--) { s->failed_pc=0x0c07fb24u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07fb26;
P_0c07fb26: /* original e700, guest PC 0x0c07fb26 */
if(!s->budget--) { s->failed_pc=0x0c07fb26u; return 0; }
r[7]=0x00000000u;
goto P_0c07fb28;
P_0c07fb28: /* original 9594, guest PC 0x0c07fb28 */
if(!s->budget--) { s->failed_pc=0x0c07fb28u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07fc54u,2);
goto P_0c07fb2a;
P_0c07fb2a: /* original 9494, guest PC 0x0c07fb2a */
if(!s->budget--) { s->failed_pc=0x0c07fb2au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07fc56u,2);
goto P_0c07fb2c;
P_0c07fb2c: /* original 4b0b, guest PC 0x0c07fb2c */
if(!s->budget--) { s->failed_pc=0x0c07fb2cu; return 0; }
target=r[11];
r[16]=0x0c07fb30u;
r[6]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07fb30u) { target=s->pc; goto dispatch; }
goto P_0c07fb30;
P_0c07fb2e: /* original 66e3, guest PC 0x0c07fb2e */
if(!s->budget--) { s->failed_pc=0x0c07fb2eu; return 0; }
r[6]=r[14];
goto P_0c07fb30;
P_0c07fb30: /* original 9992, guest PC 0x0c07fb30 */
if(!s->budget--) { s->failed_pc=0x0c07fb30u; return 0; }
r[9]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07fc58u,2);
goto P_0c07fb32;
P_0c07fb32: /* original 66e3, guest PC 0x0c07fb32 */
if(!s->budget--) { s->failed_pc=0x0c07fb32u; return 0; }
r[6]=r[14];
goto P_0c07fb34;
P_0c07fb34: /* original 2fc6, guest PC 0x0c07fb34 */
if(!s->budget--) { s->failed_pc=0x0c07fb34u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07fb36;
P_0c07fb36: /* original e700, guest PC 0x0c07fb36 */
if(!s->budget--) { s->failed_pc=0x0c07fb36u; return 0; }
r[7]=0x00000000u;
goto P_0c07fb38;
P_0c07fb38: /* original 958f, guest PC 0x0c07fb38 */
if(!s->budget--) { s->failed_pc=0x0c07fb38u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07fc5au,2);
goto P_0c07fb3a;
P_0c07fb3a: /* original 4b0b, guest PC 0x0c07fb3a */
if(!s->budget--) { s->failed_pc=0x0c07fb3au; return 0; }
target=r[11];
r[16]=0x0c07fb3eu;
r[4]=r[9];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07fb3eu) { target=s->pc; goto dispatch; }
goto P_0c07fb3e;
P_0c07fb3c: /* original 6493, guest PC 0x0c07fb3c */
if(!s->budget--) { s->failed_pc=0x0c07fb3cu; return 0; }
r[4]=r[9];
goto P_0c07fb3e;
P_0c07fb3e: /* original 7f08, guest PC 0x0c07fb3e */
if(!s->budget--) { s->failed_pc=0x0c07fb3eu; return 0; }
r[15]+=0x00000008u;
goto P_0c07fb40;
P_0c07fb40: /* original 908c, guest PC 0x0c07fb40 */
if(!s->budget--) { s->failed_pc=0x0c07fb40u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07fc5cu,2);
goto P_0c07fb42;
P_0c07fb42: /* original 938c, guest PC 0x0c07fb42 */
if(!s->budget--) { s->failed_pc=0x0c07fb42u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07fc5eu,2);
goto P_0c07fb44;
P_0c07fb44: /* original 04dd, guest PC 0x0c07fb44 */
if(!s->budget--) { s->failed_pc=0x0c07fb44u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[13]+r[0],2);
goto P_0c07fb46;
P_0c07fb46: /* original 3430, guest PC 0x0c07fb46 */
if(!s->budget--) { s->failed_pc=0x0c07fb46u; return 0; }
r[17]=(r[17]&~1u)|((r[4]==r[3])!=0);
goto P_0c07fb48;
P_0c07fb48: /* original 8b3d, guest PC 0x0c07fb48 */
if(!s->budget--) { s->failed_pc=0x0c07fb48u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07fbc6; }
goto P_0c07fb4a;
P_0c07fb4a: /* original e029, guest PC 0x0c07fb4a */
if(!s->budget--) { s->failed_pc=0x0c07fb4au; return 0; }
r[0]=0x00000029u;
goto P_0c07fb4c;
P_0c07fb4c: /* original d24a, guest PC 0x0c07fb4c */
if(!s->budget--) { s->failed_pc=0x0c07fb4cu; return 0; }
r[2]=read(ram,0x0c07fc78u,4);
goto P_0c07fb4e;
P_0c07fb4e: /* original 05dc, guest PC 0x0c07fb4e */
if(!s->budget--) { s->failed_pc=0x0c07fb4eu; return 0; }
r[5]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+r[0],1);
goto P_0c07fb50;
P_0c07fb50: /* original 605e, guest PC 0x0c07fb50 */
if(!s->budget--) { s->failed_pc=0x0c07fb50u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)r[5];
goto P_0c07fb52;
P_0c07fb52: /* original 8801, guest PC 0x0c07fb52 */
if(!s->budget--) { s->failed_pc=0x0c07fb52u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c07fb54;
P_0c07fb54: /* original 8d01, guest PC 0x0c07fb54 */
if(!s->budget--) { s->failed_pc=0x0c07fb54u; return 0; }
cond=r[17]&1u;
tmp=read(ram,r[2],4);
r[4]=tmp;
if(cond) { goto P_0c07fb5a; }
goto P_0c07fb58;
P_0c07fb56: /* original 6422, guest PC 0x0c07fb56 */
if(!s->budget--) { s->failed_pc=0x0c07fb56u; return 0; }
tmp=read(ram,r[2],4);
r[4]=tmp;
goto P_0c07fb58;
P_0c07fb58: /* original 4419, guest PC 0x0c07fb58 */
if(!s->budget--) { s->failed_pc=0x0c07fb58u; return 0; }
r[4]>>=8;
goto P_0c07fb5a;
P_0c07fb5a: /* original 9281, guest PC 0x0c07fb5a */
if(!s->budget--) { s->failed_pc=0x0c07fb5au; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07fc60u,2);
goto P_0c07fb5c;
P_0c07fb5c: /* original 9381, guest PC 0x0c07fb5c */
if(!s->budget--) { s->failed_pc=0x0c07fb5cu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07fc62u,2);
goto P_0c07fb5e;
P_0c07fb5e: /* original 2429, guest PC 0x0c07fb5e */
if(!s->budget--) { s->failed_pc=0x0c07fb5eu; return 0; }
r[4]&=r[2];
goto P_0c07fb60;
P_0c07fb60: /* original 9180, guest PC 0x0c07fb60 */
if(!s->budget--) { s->failed_pc=0x0c07fb60u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07fc64u,2);
goto P_0c07fb62;
P_0c07fb62: /* original 3430, guest PC 0x0c07fb62 */
if(!s->budget--) { s->failed_pc=0x0c07fb62u; return 0; }
r[17]=(r[17]&~1u)|((r[4]==r[3])!=0);
goto P_0c07fb64;
P_0c07fb64: /* original 0029, guest PC 0x0c07fb64 */
if(!s->budget--) { s->failed_pc=0x0c07fb64u; return 0; }
r[0]=r[17]&1u;
goto P_0c07fb66;
P_0c07fb66: /* original 201b, guest PC 0x0c07fb66 */
if(!s->budget--) { s->failed_pc=0x0c07fb66u; return 0; }
r[0]|=r[1];
goto P_0c07fb68;
P_0c07fb68: /* original 2008, guest PC 0x0c07fb68 */
if(!s->budget--) { s->failed_pc=0x0c07fb68u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c07fb6a;
P_0c07fb6a: /* original 892c, guest PC 0x0c07fb6a */
if(!s->budget--) { s->failed_pc=0x0c07fb6au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07fbc6; }
goto P_0c07fb6c;
P_0c07fb6c: /* original 907b, guest PC 0x0c07fb6c */
if(!s->budget--) { s->failed_pc=0x0c07fb6cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07fc66u,2);
goto P_0c07fb6e;
P_0c07fb6e: /* original 63f3, guest PC 0x0c07fb6e */
if(!s->budget--) { s->failed_pc=0x0c07fb6eu; return 0; }
r[3]=r[15];
goto P_0c07fb70;
P_0c07fb70: /* original 7314, guest PC 0x0c07fb70 */
if(!s->budget--) { s->failed_pc=0x0c07fb70u; return 0; }
r[3]+=0x00000014u;
goto P_0c07fb72;
P_0c07fb72: /* original 04dc, guest PC 0x0c07fb72 */
if(!s->budget--) { s->failed_pc=0x0c07fb72u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+r[0],1);
goto P_0c07fb74;
P_0c07fb74: /* original 2fc2, guest PC 0x0c07fb74 */
if(!s->budget--) { s->failed_pc=0x0c07fb74u; return 0; }
write(ram,r[15],r[12],4);
goto P_0c07fb76;
P_0c07fb76: /* original 4408, guest PC 0x0c07fb76 */
if(!s->budget--) { s->failed_pc=0x0c07fb76u; return 0; }
r[4]<<=2;
goto P_0c07fb78;
P_0c07fb78: /* original 1f32, guest PC 0x0c07fb78 */
if(!s->budget--) { s->failed_pc=0x0c07fb78u; return 0; }
write(ram,r[15]+8,r[3],4);
goto P_0c07fb7a;
P_0c07fb7a: /* original 5df3, guest PC 0x0c07fb7a */
if(!s->budget--) { s->failed_pc=0x0c07fb7au; return 0; }
r[13]=read(ram,r[15]+12,4);
goto P_0c07fb7c;
P_0c07fb7c: /* original 644e, guest PC 0x0c07fb7c */
if(!s->budget--) { s->failed_pc=0x0c07fb7cu; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)r[4];
goto P_0c07fb7e;
P_0c07fb7e: /* original 3d4c, guest PC 0x0c07fb7e */
if(!s->budget--) { s->failed_pc=0x0c07fb7eu; return 0; }
r[13]+=r[4];
goto P_0c07fb80;
P_0c07fb80: /* original 480b, guest PC 0x0c07fb80 */
if(!s->budget--) { s->failed_pc=0x0c07fb80u; return 0; }
target=r[8];
r[16]=0x0c07fb84u;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07fb84u) { target=s->pc; goto dispatch; }
goto P_0c07fb84;
P_0c07fb82: /* original 64d3, guest PC 0x0c07fb82 */
if(!s->budget--) { s->failed_pc=0x0c07fb82u; return 0; }
r[4]=r[13];
goto P_0c07fb84;
P_0c07fb84: /* original 55f2, guest PC 0x0c07fb84 */
if(!s->budget--) { s->failed_pc=0x0c07fb84u; return 0; }
r[5]=read(ram,r[15]+8,4);
goto P_0c07fb86;
P_0c07fb86: /* original 640c, guest PC 0x0c07fb86 */
if(!s->budget--) { s->failed_pc=0x0c07fb86u; return 0; }
r[4]=r[0]&255u;
goto P_0c07fb88;
P_0c07fb88: /* original 7501, guest PC 0x0c07fb88 */
if(!s->budget--) { s->failed_pc=0x0c07fb88u; return 0; }
r[5]+=0x00000001u;
goto P_0c07fb8a;
P_0c07fb8a: /* original 1f52, guest PC 0x0c07fb8a */
if(!s->budget--) { s->failed_pc=0x0c07fb8au; return 0; }
write(ram,r[15]+8,r[5],4);
goto P_0c07fb8c;
P_0c07fb8c: /* original 75ff, guest PC 0x0c07fb8c */
if(!s->budget--) { s->failed_pc=0x0c07fb8cu; return 0; }
r[5]+=0xffffffffu;
goto P_0c07fb8e;
P_0c07fb8e: /* original 6550, guest PC 0x0c07fb8e */
if(!s->budget--) { s->failed_pc=0x0c07fb8eu; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[5],1);
r[5]=tmp;
goto P_0c07fb90;
P_0c07fb90: /* original 3450, guest PC 0x0c07fb90 */
if(!s->budget--) { s->failed_pc=0x0c07fb90u; return 0; }
r[17]=(r[17]&~1u)|((r[4]==r[5])!=0);
goto P_0c07fb92;
P_0c07fb92: /* original 8b18, guest PC 0x0c07fb92 */
if(!s->budget--) { s->failed_pc=0x0c07fb92u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07fbc6; }
goto P_0c07fb94;
P_0c07fb94: /* original 63f2, guest PC 0x0c07fb94 */
if(!s->budget--) { s->failed_pc=0x0c07fb94u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c07fb96;
P_0c07fb96: /* original e203, guest PC 0x0c07fb96 */
if(!s->budget--) { s->failed_pc=0x0c07fb96u; return 0; }
r[2]=0x00000003u;
goto P_0c07fb98;
P_0c07fb98: /* original 7301, guest PC 0x0c07fb98 */
if(!s->budget--) { s->failed_pc=0x0c07fb98u; return 0; }
r[3]+=0x00000001u;
goto P_0c07fb9a;
P_0c07fb9a: /* original 3323, guest PC 0x0c07fb9a */
if(!s->budget--) { s->failed_pc=0x0c07fb9au; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>=(int32_t)r[2])!=0);
goto P_0c07fb9c;
P_0c07fb9c: /* original 2f32, guest PC 0x0c07fb9c */
if(!s->budget--) { s->failed_pc=0x0c07fb9cu; return 0; }
write(ram,r[15],r[3],4);
goto P_0c07fb9e;
P_0c07fb9e: /* original 8fef, guest PC 0x0c07fb9e */
if(!s->budget--) { s->failed_pc=0x0c07fb9eu; return 0; }
cond=r[17]&1u;
r[13]+=0x00000001u;
if(!cond) { goto P_0c07fb80; }
goto P_0c07fba2;
P_0c07fba0: /* original 7d01, guest PC 0x0c07fba0 */
if(!s->budget--) { s->failed_pc=0x0c07fba0u; return 0; }
r[13]+=0x00000001u;
goto P_0c07fba2;
P_0c07fba2: /* original 2fc6, guest PC 0x0c07fba2 */
if(!s->budget--) { s->failed_pc=0x0c07fba2u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07fba4;
P_0c07fba4: /* original e700, guest PC 0x0c07fba4 */
if(!s->budget--) { s->failed_pc=0x0c07fba4u; return 0; }
r[7]=0x00000000u;
goto P_0c07fba6;
P_0c07fba6: /* original 955f, guest PC 0x0c07fba6 */
if(!s->budget--) { s->failed_pc=0x0c07fba6u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07fc68u,2);
goto P_0c07fba8;
P_0c07fba8: /* original 945f, guest PC 0x0c07fba8 */
if(!s->budget--) { s->failed_pc=0x0c07fba8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07fc6au,2);
goto P_0c07fbaa;
P_0c07fbaa: /* original 4b0b, guest PC 0x0c07fbaa */
if(!s->budget--) { s->failed_pc=0x0c07fbaau; return 0; }
target=r[11];
r[16]=0x0c07fbaeu;
r[6]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07fbaeu) { target=s->pc; goto dispatch; }
goto P_0c07fbae;
P_0c07fbac: /* original 66e3, guest PC 0x0c07fbac */
if(!s->budget--) { s->failed_pc=0x0c07fbacu; return 0; }
r[6]=r[14];
goto P_0c07fbae;
P_0c07fbae: /* original 7f04, guest PC 0x0c07fbae */
if(!s->budget--) { s->failed_pc=0x0c07fbaeu; return 0; }
r[15]+=0x00000004u;
goto P_0c07fbb0;
P_0c07fbb0: /* original 9d5c, guest PC 0x0c07fbb0 */
if(!s->budget--) { s->failed_pc=0x0c07fbb0u; return 0; }
r[13]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07fc6cu,2);
goto P_0c07fbb2;
P_0c07fbb2: /* original 53f1, guest PC 0x0c07fbb2 */
if(!s->budget--) { s->failed_pc=0x0c07fbb2u; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c07fbb4;
P_0c07fbb4: /* original 2338, guest PC 0x0c07fbb4 */
if(!s->budget--) { s->failed_pc=0x0c07fbb4u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c07fbb6;
P_0c07fbb6: /* original 8900, guest PC 0x0c07fbb6 */
if(!s->budget--) { s->failed_pc=0x0c07fbb6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07fbba; }
goto P_0c07fbb8;
P_0c07fbb8: /* original 9d59, guest PC 0x0c07fbb8 */
if(!s->budget--) { s->failed_pc=0x0c07fbb8u; return 0; }
r[13]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07fc6eu,2);
goto P_0c07fbba;
P_0c07fbba: /* original 9759, guest PC 0x0c07fbba */
if(!s->budget--) { s->failed_pc=0x0c07fbbau; return 0; }
r[7]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07fc70u,2);
goto P_0c07fbbc;
P_0c07fbbc: /* original 65d3, guest PC 0x0c07fbbc */
if(!s->budget--) { s->failed_pc=0x0c07fbbcu; return 0; }
r[5]=r[13];
goto P_0c07fbbe;
P_0c07fbbe: /* original e600, guest PC 0x0c07fbbe */
if(!s->budget--) { s->failed_pc=0x0c07fbbeu; return 0; }
r[6]=0x00000000u;
goto P_0c07fbc0;
P_0c07fbc0: /* original 4a0b, guest PC 0x0c07fbc0 */
if(!s->budget--) { s->failed_pc=0x0c07fbc0u; return 0; }
target=r[10];
r[16]=0x0c07fbc4u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07fbc4u) { target=s->pc; goto dispatch; }
goto P_0c07fbc4;
P_0c07fbc2: /* original 64e3, guest PC 0x0c07fbc2 */
if(!s->budget--) { s->failed_pc=0x0c07fbc2u; return 0; }
r[4]=r[14];
goto P_0c07fbc4;
P_0c07fbc4: /* original 6903, guest PC 0x0c07fbc4 */
if(!s->budget--) { s->failed_pc=0x0c07fbc4u; return 0; }
r[9]=r[0];
goto P_0c07fbc6;
P_0c07fbc6: /* original d32d, guest PC 0x0c07fbc6 */
if(!s->budget--) { s->failed_pc=0x0c07fbc6u; return 0; }
r[3]=read(ram,0x0c07fc7cu,4);
goto P_0c07fbc8;
P_0c07fbc8: /* original 6593, guest PC 0x0c07fbc8 */
if(!s->budget--) { s->failed_pc=0x0c07fbc8u; return 0; }
r[5]=r[9];
goto P_0c07fbca;
P_0c07fbca: /* original 430b, guest PC 0x0c07fbca */
if(!s->budget--) { s->failed_pc=0x0c07fbcau; return 0; }
target=r[3];
r[16]=0x0c07fbceu;
r[4]=read(ram,r[15]+16,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07fbceu) { target=s->pc; goto dispatch; }
goto P_0c07fbce;
P_0c07fbcc: /* original 54f4, guest PC 0x0c07fbcc */
if(!s->budget--) { s->failed_pc=0x0c07fbccu; return 0; }
r[4]=read(ram,r[15]+16,4);
goto P_0c07fbce;
P_0c07fbce: /* original 7f18, guest PC 0x0c07fbce */
if(!s->budget--) { s->failed_pc=0x0c07fbceu; return 0; }
r[15]+=0x00000018u;
goto P_0c07fbd0;
P_0c07fbd0: /* original 4f16, guest PC 0x0c07fbd0 */
if(!s->budget--) { s->failed_pc=0x0c07fbd0u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c07fbd2;
P_0c07fbd2: /* original 4f26, guest PC 0x0c07fbd2 */
if(!s->budget--) { s->failed_pc=0x0c07fbd2u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c07fbd4;
P_0c07fbd4: /* original 68f6, guest PC 0x0c07fbd4 */
if(!s->budget--) { s->failed_pc=0x0c07fbd4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c07fbd6;
P_0c07fbd6: /* original 69f6, guest PC 0x0c07fbd6 */
if(!s->budget--) { s->failed_pc=0x0c07fbd6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c07fbd8;
P_0c07fbd8: /* original 6af6, guest PC 0x0c07fbd8 */
if(!s->budget--) { s->failed_pc=0x0c07fbd8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c07fbda;
P_0c07fbda: /* original 6bf6, guest PC 0x0c07fbda */
if(!s->budget--) { s->failed_pc=0x0c07fbdau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c07fbdc;
P_0c07fbdc: /* original 6cf6, guest PC 0x0c07fbdc */
if(!s->budget--) { s->failed_pc=0x0c07fbdcu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c07fbde;
P_0c07fbde: /* original 6df6, guest PC 0x0c07fbde */
if(!s->budget--) { s->failed_pc=0x0c07fbdeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c07fbe0;
P_0c07fbe0: /* original 000b, guest PC 0x0c07fbe0 */
if(!s->budget--) { s->failed_pc=0x0c07fbe0u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c07fbe2: /* original 6ef6, guest PC 0x0c07fbe2 */
if(!s->budget--) { s->failed_pc=0x0c07fbe2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c07fbe4u,s,ram);
P_0c080006: /* original 4f22, guest PC 0x0c080006 */
if(!s->budget--) { s->failed_pc=0x0c080006u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c080008;
P_0c080008: /* original d324, guest PC 0x0c080008 */
if(!s->budget--) { s->failed_pc=0x0c080008u; return 0; }
r[3]=read(ram,0x0c08009cu,4);
goto P_0c08000a;
P_0c08000a: /* original d52e, guest PC 0x0c08000a */
if(!s->budget--) { s->failed_pc=0x0c08000au; return 0; }
r[5]=read(ram,0x0c0800c4u,4);
goto P_0c08000c;
P_0c08000c: /* original 943a, guest PC 0x0c08000c */
if(!s->budget--) { s->failed_pc=0x0c08000cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c080084u,2);
goto P_0c08000e;
P_0c08000e: /* original 430b, guest PC 0x0c08000e */
if(!s->budget--) { s->failed_pc=0x0c08000eu; return 0; }
target=r[3];
r[16]=0x0c080012u;
r[6]=0x00000001u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c080012u) { target=s->pc; goto dispatch; }
goto P_0c080012;
P_0c080010: /* original e601, guest PC 0x0c080010 */
if(!s->budget--) { s->failed_pc=0x0c080010u; return 0; }
r[6]=0x00000001u;
goto P_0c080012;
P_0c080012: /* original 4f26, guest PC 0x0c080012 */
if(!s->budget--) { s->failed_pc=0x0c080012u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c080014;
P_0c080014: /* original 000b, guest PC 0x0c080014 */
if(!s->budget--) { s->failed_pc=0x0c080014u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c080016: /* original 0009, guest PC 0x0c080016 */
if(!s->budget--) { s->failed_pc=0x0c080016u; return 0; }
goto P_0c080018;
P_0c080018: /* original 4f22, guest PC 0x0c080018 */
if(!s->budget--) { s->failed_pc=0x0c080018u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c08001a;
P_0c08001a: /* original bff4, guest PC 0x0c08001a */
if(!s->budget--) { s->failed_pc=0x0c08001au; return 0; }
target=0x0c080006u; r[16]=0x0c08001eu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08001eu) { target=s->pc; goto dispatch; }
goto P_0c08001e;
P_0c08001c: /* original 0009, guest PC 0x0c08001c */
if(!s->budget--) { s->failed_pc=0x0c08001cu; return 0; }
goto P_0c08001e;
P_0c08001e: /* original d21f, guest PC 0x0c08001e */
if(!s->budget--) { s->failed_pc=0x0c08001eu; return 0; }
r[2]=read(ram,0x0c08009cu,4);
goto P_0c080020;
P_0c080020: /* original d529, guest PC 0x0c080020 */
if(!s->budget--) { s->failed_pc=0x0c080020u; return 0; }
r[5]=read(ram,0x0c0800c8u,4);
goto P_0c080022;
P_0c080022: /* original 9434, guest PC 0x0c080022 */
if(!s->budget--) { s->failed_pc=0x0c080022u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08008eu,2);
goto P_0c080024;
P_0c080024: /* original 420b, guest PC 0x0c080024 */
if(!s->budget--) { s->failed_pc=0x0c080024u; return 0; }
target=r[2];
r[16]=0x0c080028u;
r[6]=0x00000001u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c080028u) { target=s->pc; goto dispatch; }
goto P_0c080028;
P_0c080026: /* original e601, guest PC 0x0c080026 */
if(!s->budget--) { s->failed_pc=0x0c080026u; return 0; }
r[6]=0x00000001u;
goto P_0c080028;
P_0c080028: /* original d31c, guest PC 0x0c080028 */
if(!s->budget--) { s->failed_pc=0x0c080028u; return 0; }
r[3]=read(ram,0x0c08009cu,4);
goto P_0c08002a;
P_0c08002a: /* original d528, guest PC 0x0c08002a */
if(!s->budget--) { s->failed_pc=0x0c08002au; return 0; }
r[5]=read(ram,0x0c0800ccu,4);
goto P_0c08002c;
P_0c08002c: /* original 9430, guest PC 0x0c08002c */
if(!s->budget--) { s->failed_pc=0x0c08002cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c080090u,2);
goto P_0c08002e;
P_0c08002e: /* original 430b, guest PC 0x0c08002e */
if(!s->budget--) { s->failed_pc=0x0c08002eu; return 0; }
target=r[3];
r[16]=0x0c080032u;
r[6]=0x00000001u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c080032u) { target=s->pc; goto dispatch; }
goto P_0c080032;
P_0c080030: /* original e601, guest PC 0x0c080030 */
if(!s->budget--) { s->failed_pc=0x0c080030u; return 0; }
r[6]=0x00000001u;
goto P_0c080032;
P_0c080032: /* original 4f26, guest PC 0x0c080032 */
if(!s->budget--) { s->failed_pc=0x0c080032u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c080034;
P_0c080034: /* original 000b, guest PC 0x0c080034 */
if(!s->budget--) { s->failed_pc=0x0c080034u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c080036: /* original 0009, guest PC 0x0c080036 */
if(!s->budget--) { s->failed_pc=0x0c080036u; return 0; }
goto P_0c080038;
P_0c080038: /* original 4f22, guest PC 0x0c080038 */
if(!s->budget--) { s->failed_pc=0x0c080038u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c08003a;
P_0c08003a: /* original 7ff8, guest PC 0x0c08003a */
if(!s->budget--) { s->failed_pc=0x0c08003au; return 0; }
r[15]+=0xfffffff8u;
goto P_0c08003c;
P_0c08003c: /* original 2f42, guest PC 0x0c08003c */
if(!s->budget--) { s->failed_pc=0x0c08003cu; return 0; }
write(ram,r[15],r[4],4);
goto P_0c08003e;
P_0c08003e: /* original 1f51, guest PC 0x0c08003e */
if(!s->budget--) { s->failed_pc=0x0c08003eu; return 0; }
write(ram,r[15]+4,r[5],4);
goto P_0c080040;
P_0c080040: /* original d314, guest PC 0x0c080040 */
if(!s->budget--) { s->failed_pc=0x0c080040u; return 0; }
r[3]=read(ram,0x0c080094u,4);
goto P_0c080042;
P_0c080042: /* original 64f2, guest PC 0x0c080042 */
if(!s->budget--) { s->failed_pc=0x0c080042u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c080044;
P_0c080044: /* original bfe8, guest PC 0x0c080044 */
if(!s->budget--) { s->failed_pc=0x0c080044u; return 0; }
target=0x0c080018u; r[16]=0x0c080048u;
write(ram,r[4]+16,r[3],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c080048u) { target=s->pc; goto dispatch; }
goto P_0c080048;
P_0c080046: /* original 1434, guest PC 0x0c080046 */
if(!s->budget--) { s->failed_pc=0x0c080046u; return 0; }
write(ram,r[4]+16,r[3],4);
goto P_0c080048;
P_0c080048: /* original d116, guest PC 0x0c080048 */
if(!s->budget--) { s->failed_pc=0x0c080048u; return 0; }
r[1]=read(ram,0x0c0800a4u,4);
goto P_0c08004a;
P_0c08004a: /* original 6210, guest PC 0x0c08004a */
if(!s->budget--) { s->failed_pc=0x0c08004au; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[1],1);
r[2]=tmp;
goto P_0c08004c;
P_0c08004c: /* original 7201, guest PC 0x0c08004c */
if(!s->budget--) { s->failed_pc=0x0c08004cu; return 0; }
r[2]+=0x00000001u;
goto P_0c08004e;
P_0c08004e: /* original 2120, guest PC 0x0c08004e */
if(!s->budget--) { s->failed_pc=0x0c08004eu; return 0; }
write(ram,r[1],r[2],1);
goto P_0c080050;
P_0c080050: /* original 55f1, guest PC 0x0c080050 */
if(!s->budget--) { s->failed_pc=0x0c080050u; return 0; }
r[5]=read(ram,r[15]+4,4);
goto P_0c080052;
P_0c080052: /* original 64f2, guest PC 0x0c080052 */
if(!s->budget--) { s->failed_pc=0x0c080052u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c080054;
P_0c080054: /* original 7f08, guest PC 0x0c080054 */
if(!s->budget--) { s->failed_pc=0x0c080054u; return 0; }
r[15]+=0x00000008u;
goto P_0c080056;
P_0c080056: /* original d31a, guest PC 0x0c080056 */
if(!s->budget--) { s->failed_pc=0x0c080056u; return 0; }
r[3]=read(ram,0x0c0800c0u,4);
goto P_0c080058;
P_0c080058: /* original 432b, guest PC 0x0c080058 */
if(!s->budget--) { s->failed_pc=0x0c080058u; return 0; }
target=r[3];
r[16]=read(ram,r[15],4); r[15]+=4;
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
P_0c08005a: /* original 4f26, guest PC 0x0c08005a */
if(!s->budget--) { s->failed_pc=0x0c08005au; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c08005c;
P_0c08005c: /* original 4f22, guest PC 0x0c08005c */
if(!s->budget--) { s->failed_pc=0x0c08005cu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c08005e;
P_0c08005e: /* original 7ff8, guest PC 0x0c08005e */
if(!s->budget--) { s->failed_pc=0x0c08005eu; return 0; }
r[15]+=0xfffffff8u;
goto P_0c080060;
P_0c080060: /* original 2f42, guest PC 0x0c080060 */
if(!s->budget--) { s->failed_pc=0x0c080060u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c080062;
P_0c080062: /* original bfd9, guest PC 0x0c080062 */
if(!s->budget--) { s->failed_pc=0x0c080062u; return 0; }
target=0x0c080018u; r[16]=0x0c080066u;
write(ram,r[15]+4,r[5],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c080066u) { target=s->pc; goto dispatch; }
goto P_0c080066;
P_0c080064: /* original 1f51, guest PC 0x0c080064 */
if(!s->budget--) { s->failed_pc=0x0c080064u; return 0; }
write(ram,r[15]+4,r[5],4);
goto P_0c080066;
P_0c080066: /* original d21a, guest PC 0x0c080066 */
if(!s->budget--) { s->failed_pc=0x0c080066u; return 0; }
r[2]=read(ram,0x0c0800d0u,4);
goto P_0c080068;
P_0c080068: /* original e50a, guest PC 0x0c080068 */
if(!s->budget--) { s->failed_pc=0x0c080068u; return 0; }
r[5]=0x0000000au;
goto P_0c08006a;
P_0c08006a: /* original 420b, guest PC 0x0c08006a */
if(!s->budget--) { s->failed_pc=0x0c08006au; return 0; }
target=r[2];
r[16]=0x0c08006eu;
r[4]=0x00000014u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08006eu) { target=s->pc; goto dispatch; }
goto P_0c08006e;
P_0c08006c: /* original e414, guest PC 0x0c08006c */
if(!s->budget--) { s->failed_pc=0x0c08006cu; return 0; }
r[4]=0x00000014u;
goto P_0c08006e;
P_0c08006e: /* original d319, guest PC 0x0c08006e */
if(!s->budget--) { s->failed_pc=0x0c08006eu; return 0; }
r[3]=read(ram,0x0c0800d4u,4);
goto P_0c080070;
P_0c080070: /* original e510, guest PC 0x0c080070 */
if(!s->budget--) { s->failed_pc=0x0c080070u; return 0; }
r[5]=0x00000010u;
goto P_0c080072;
P_0c080072: /* original e603, guest PC 0x0c080072 */
if(!s->budget--) { s->failed_pc=0x0c080072u; return 0; }
r[6]=0x00000003u;
goto P_0c080074;
P_0c080074: /* original 430b, guest PC 0x0c080074 */
if(!s->budget--) { s->failed_pc=0x0c080074u; return 0; }
target=r[3];
r[16]=0x0c080078u;
r[4]=0x00000014u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c080078u) { target=s->pc; goto dispatch; }
goto P_0c080078;
P_0c080076: /* original e414, guest PC 0x0c080076 */
if(!s->budget--) { s->failed_pc=0x0c080076u; return 0; }
r[4]=0x00000014u;
goto P_0c080078;
P_0c080078: /* original d311, guest PC 0x0c080078 */
if(!s->budget--) { s->failed_pc=0x0c080078u; return 0; }
r[3]=read(ram,0x0c0800c0u,4);
goto P_0c08007a;
P_0c08007a: /* original 64f2, guest PC 0x0c08007a */
if(!s->budget--) { s->failed_pc=0x0c08007au; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c08007c;
P_0c08007c: /* original 55f1, guest PC 0x0c08007c */
if(!s->budget--) { s->failed_pc=0x0c08007cu; return 0; }
r[5]=read(ram,r[15]+4,4);
goto P_0c08007e;
P_0c08007e: /* original 7f08, guest PC 0x0c08007e */
if(!s->budget--) { s->failed_pc=0x0c08007eu; return 0; }
r[15]+=0x00000008u;
goto P_0c080080;
P_0c080080: /* original 432b, guest PC 0x0c080080 */
if(!s->budget--) { s->failed_pc=0x0c080080u; return 0; }
target=r[3];
r[16]=read(ram,r[15],4); r[15]+=4;
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
P_0c080082: /* original 4f26, guest PC 0x0c080082 */
if(!s->budget--) { s->failed_pc=0x0c080082u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
return vf3_matrix_family(0x0c080084u,s,ram);
P_0c0800d8: /* original 4f22, guest PC 0x0c0800d8 */
if(!s->budget--) { s->failed_pc=0x0c0800d8u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0800da;
P_0c0800da: /* original bf94, guest PC 0x0c0800da */
if(!s->budget--) { s->failed_pc=0x0c0800dau; return 0; }
target=0x0c080006u; r[16]=0x0c0800deu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0800deu) { target=s->pc; goto dispatch; }
goto P_0c0800de;
P_0c0800dc: /* original 0009, guest PC 0x0c0800dc */
if(!s->budget--) { s->failed_pc=0x0c0800dcu; return 0; }
goto P_0c0800de;
P_0c0800de: /* original d24b, guest PC 0x0c0800de */
if(!s->budget--) { s->failed_pc=0x0c0800deu; return 0; }
r[2]=read(ram,0x0c08020cu,4);
goto P_0c0800e0;
P_0c0800e0: /* original d549, guest PC 0x0c0800e0 */
if(!s->budget--) { s->failed_pc=0x0c0800e0u; return 0; }
r[5]=read(ram,0x0c080208u,4);
goto P_0c0800e2;
P_0c0800e2: /* original 9487, guest PC 0x0c0800e2 */
if(!s->budget--) { s->failed_pc=0x0c0800e2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0801f4u,2);
goto P_0c0800e4;
P_0c0800e4: /* original 420b, guest PC 0x0c0800e4 */
if(!s->budget--) { s->failed_pc=0x0c0800e4u; return 0; }
target=r[2];
r[16]=0x0c0800e8u;
r[6]=0x00000001u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0800e8u) { target=s->pc; goto dispatch; }
goto P_0c0800e8;
P_0c0800e6: /* original e601, guest PC 0x0c0800e6 */
if(!s->budget--) { s->failed_pc=0x0c0800e6u; return 0; }
r[6]=0x00000001u;
goto P_0c0800e8;
P_0c0800e8: /* original 4f26, guest PC 0x0c0800e8 */
if(!s->budget--) { s->failed_pc=0x0c0800e8u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0800ea;
P_0c0800ea: /* original 000b, guest PC 0x0c0800ea */
if(!s->budget--) { s->failed_pc=0x0c0800eau; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c0800ec: /* original 0009, guest PC 0x0c0800ec */
if(!s->budget--) { s->failed_pc=0x0c0800ecu; return 0; }
goto P_0c0800ee;
P_0c0800ee: /* original 4f22, guest PC 0x0c0800ee */
if(!s->budget--) { s->failed_pc=0x0c0800eeu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0800f0;
P_0c0800f0: /* original 7ff8, guest PC 0x0c0800f0 */
if(!s->budget--) { s->failed_pc=0x0c0800f0u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c0800f2;
P_0c0800f2: /* original 2f42, guest PC 0x0c0800f2 */
if(!s->budget--) { s->failed_pc=0x0c0800f2u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c0800f4;
P_0c0800f4: /* original 1f51, guest PC 0x0c0800f4 */
if(!s->budget--) { s->failed_pc=0x0c0800f4u; return 0; }
write(ram,r[15]+4,r[5],4);
goto P_0c0800f6;
P_0c0800f6: /* original d346, guest PC 0x0c0800f6 */
if(!s->budget--) { s->failed_pc=0x0c0800f6u; return 0; }
r[3]=read(ram,0x0c080210u,4);
goto P_0c0800f8;
P_0c0800f8: /* original 64f2, guest PC 0x0c0800f8 */
if(!s->budget--) { s->failed_pc=0x0c0800f8u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c0800fa;
P_0c0800fa: /* original bfed, guest PC 0x0c0800fa */
if(!s->budget--) { s->failed_pc=0x0c0800fau; return 0; }
target=0x0c0800d8u; r[16]=0x0c0800feu;
write(ram,r[4]+16,r[3],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0800feu) { target=s->pc; goto dispatch; }
goto P_0c0800fe;
P_0c0800fc: /* original 1434, guest PC 0x0c0800fc */
if(!s->budget--) { s->failed_pc=0x0c0800fcu; return 0; }
write(ram,r[4]+16,r[3],4);
goto P_0c0800fe;
P_0c0800fe: /* original d145, guest PC 0x0c0800fe */
if(!s->budget--) { s->failed_pc=0x0c0800feu; return 0; }
r[1]=read(ram,0x0c080214u,4);
goto P_0c080100;
P_0c080100: /* original 6210, guest PC 0x0c080100 */
if(!s->budget--) { s->failed_pc=0x0c080100u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[1],1);
r[2]=tmp;
goto P_0c080102;
P_0c080102: /* original 7201, guest PC 0x0c080102 */
if(!s->budget--) { s->failed_pc=0x0c080102u; return 0; }
r[2]+=0x00000001u;
goto P_0c080104;
P_0c080104: /* original 2120, guest PC 0x0c080104 */
if(!s->budget--) { s->failed_pc=0x0c080104u; return 0; }
write(ram,r[1],r[2],1);
goto P_0c080106;
P_0c080106: /* original 55f1, guest PC 0x0c080106 */
if(!s->budget--) { s->failed_pc=0x0c080106u; return 0; }
r[5]=read(ram,r[15]+4,4);
goto P_0c080108;
P_0c080108: /* original 64f2, guest PC 0x0c080108 */
if(!s->budget--) { s->failed_pc=0x0c080108u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c08010a;
P_0c08010a: /* original 7f08, guest PC 0x0c08010a */
if(!s->budget--) { s->failed_pc=0x0c08010au; return 0; }
r[15]+=0x00000008u;
goto P_0c08010c;
P_0c08010c: /* original d342, guest PC 0x0c08010c */
if(!s->budget--) { s->failed_pc=0x0c08010cu; return 0; }
r[3]=read(ram,0x0c080218u,4);
goto P_0c08010e;
P_0c08010e: /* original 432b, guest PC 0x0c08010e */
if(!s->budget--) { s->failed_pc=0x0c08010eu; return 0; }
target=r[3];
r[16]=read(ram,r[15],4); r[15]+=4;
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
P_0c080110: /* original 4f26, guest PC 0x0c080110 */
if(!s->budget--) { s->failed_pc=0x0c080110u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
return vf3_matrix_family(0x0c080112u,s,ram);
P_0c08019e: /* original 4f22, guest PC 0x0c08019e */
if(!s->budget--) { s->failed_pc=0x0c08019eu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0801a0;
P_0c0801a0: /* original bf31, guest PC 0x0c0801a0 */
if(!s->budget--) { s->failed_pc=0x0c0801a0u; return 0; }
target=0x0c080006u; r[16]=0x0c0801a4u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0801a4u) { target=s->pc; goto dispatch; }
goto P_0c0801a4;
P_0c0801a2: /* original 0009, guest PC 0x0c0801a2 */
if(!s->budget--) { s->failed_pc=0x0c0801a2u; return 0; }
goto P_0c0801a4;
P_0c0801a4: /* original d219, guest PC 0x0c0801a4 */
if(!s->budget--) { s->failed_pc=0x0c0801a4u; return 0; }
r[2]=read(ram,0x0c08020cu,4);
goto P_0c0801a6;
P_0c0801a6: /* original d522, guest PC 0x0c0801a6 */
if(!s->budget--) { s->failed_pc=0x0c0801a6u; return 0; }
r[5]=read(ram,0x0c080230u,4);
goto P_0c0801a8;
P_0c0801a8: /* original 942c, guest PC 0x0c0801a8 */
if(!s->budget--) { s->failed_pc=0x0c0801a8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c080204u,2);
goto P_0c0801aa;
P_0c0801aa: /* original 420b, guest PC 0x0c0801aa */
if(!s->budget--) { s->failed_pc=0x0c0801aau; return 0; }
target=r[2];
r[16]=0x0c0801aeu;
r[6]=0x00000001u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0801aeu) { target=s->pc; goto dispatch; }
goto P_0c0801ae;
P_0c0801ac: /* original e601, guest PC 0x0c0801ac */
if(!s->budget--) { s->failed_pc=0x0c0801acu; return 0; }
r[6]=0x00000001u;
goto P_0c0801ae;
P_0c0801ae: /* original 4f26, guest PC 0x0c0801ae */
if(!s->budget--) { s->failed_pc=0x0c0801aeu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0801b0;
P_0c0801b0: /* original 000b, guest PC 0x0c0801b0 */
if(!s->budget--) { s->failed_pc=0x0c0801b0u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c0801b2: /* original 0009, guest PC 0x0c0801b2 */
if(!s->budget--) { s->failed_pc=0x0c0801b2u; return 0; }
goto P_0c0801b4;
P_0c0801b4: /* original 4f22, guest PC 0x0c0801b4 */
if(!s->budget--) { s->failed_pc=0x0c0801b4u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0801b6;
P_0c0801b6: /* original 7ff8, guest PC 0x0c0801b6 */
if(!s->budget--) { s->failed_pc=0x0c0801b6u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c0801b8;
P_0c0801b8: /* original 2f42, guest PC 0x0c0801b8 */
if(!s->budget--) { s->failed_pc=0x0c0801b8u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c0801ba;
P_0c0801ba: /* original 1f51, guest PC 0x0c0801ba */
if(!s->budget--) { s->failed_pc=0x0c0801bau; return 0; }
write(ram,r[15]+4,r[5],4);
goto P_0c0801bc;
P_0c0801bc: /* original d314, guest PC 0x0c0801bc */
if(!s->budget--) { s->failed_pc=0x0c0801bcu; return 0; }
r[3]=read(ram,0x0c080210u,4);
goto P_0c0801be;
P_0c0801be: /* original 64f2, guest PC 0x0c0801be */
if(!s->budget--) { s->failed_pc=0x0c0801beu; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c0801c0;
P_0c0801c0: /* original bfed, guest PC 0x0c0801c0 */
if(!s->budget--) { s->failed_pc=0x0c0801c0u; return 0; }
target=0x0c08019eu; r[16]=0x0c0801c4u;
write(ram,r[4]+16,r[3],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0801c4u) { target=s->pc; goto dispatch; }
goto P_0c0801c4;
P_0c0801c2: /* original 1434, guest PC 0x0c0801c2 */
if(!s->budget--) { s->failed_pc=0x0c0801c2u; return 0; }
write(ram,r[4]+16,r[3],4);
goto P_0c0801c4;
P_0c0801c4: /* original d11b, guest PC 0x0c0801c4 */
if(!s->budget--) { s->failed_pc=0x0c0801c4u; return 0; }
r[1]=read(ram,0x0c080234u,4);
goto P_0c0801c6;
P_0c0801c6: /* original 410b, guest PC 0x0c0801c6 */
if(!s->budget--) { s->failed_pc=0x0c0801c6u; return 0; }
target=r[1];
r[16]=0x0c0801cau;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0801cau) { target=s->pc; goto dispatch; }
goto P_0c0801ca;
P_0c0801c8: /* original 0009, guest PC 0x0c0801c8 */
if(!s->budget--) { s->failed_pc=0x0c0801c8u; return 0; }
goto P_0c0801ca;
P_0c0801ca: /* original d212, guest PC 0x0c0801ca */
if(!s->budget--) { s->failed_pc=0x0c0801cau; return 0; }
r[2]=read(ram,0x0c080214u,4);
goto P_0c0801cc;
P_0c0801cc: /* original 6120, guest PC 0x0c0801cc */
if(!s->budget--) { s->failed_pc=0x0c0801ccu; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[2],1);
r[1]=tmp;
goto P_0c0801ce;
P_0c0801ce: /* original 7101, guest PC 0x0c0801ce */
if(!s->budget--) { s->failed_pc=0x0c0801ceu; return 0; }
r[1]+=0x00000001u;
goto P_0c0801d0;
P_0c0801d0: /* original 2210, guest PC 0x0c0801d0 */
if(!s->budget--) { s->failed_pc=0x0c0801d0u; return 0; }
write(ram,r[2],r[1],1);
goto P_0c0801d2;
P_0c0801d2: /* original 55f1, guest PC 0x0c0801d2 */
if(!s->budget--) { s->failed_pc=0x0c0801d2u; return 0; }
r[5]=read(ram,r[15]+4,4);
goto P_0c0801d4;
P_0c0801d4: /* original 64f2, guest PC 0x0c0801d4 */
if(!s->budget--) { s->failed_pc=0x0c0801d4u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c0801d6;
P_0c0801d6: /* original 7f08, guest PC 0x0c0801d6 */
if(!s->budget--) { s->failed_pc=0x0c0801d6u; return 0; }
r[15]+=0x00000008u;
goto P_0c0801d8;
P_0c0801d8: /* original d30f, guest PC 0x0c0801d8 */
if(!s->budget--) { s->failed_pc=0x0c0801d8u; return 0; }
r[3]=read(ram,0x0c080218u,4);
goto P_0c0801da;
P_0c0801da: /* original 432b, guest PC 0x0c0801da */
if(!s->budget--) { s->failed_pc=0x0c0801dau; return 0; }
target=r[3];
r[16]=read(ram,r[15],4); r[15]+=4;
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
P_0c0801dc: /* original 4f26, guest PC 0x0c0801dc */
if(!s->budget--) { s->failed_pc=0x0c0801dcu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
return vf3_matrix_family(0x0c0801deu,s,ram);
P_0c080238: /* original 4f22, guest PC 0x0c080238 */
if(!s->budget--) { s->failed_pc=0x0c080238u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c08023a;
P_0c08023a: /* original 7ff8, guest PC 0x0c08023a */
if(!s->budget--) { s->failed_pc=0x0c08023au; return 0; }
r[15]+=0xfffffff8u;
goto P_0c08023c;
P_0c08023c: /* original 2f42, guest PC 0x0c08023c */
if(!s->budget--) { s->failed_pc=0x0c08023cu; return 0; }
write(ram,r[15],r[4],4);
goto P_0c08023e;
P_0c08023e: /* original 1f51, guest PC 0x0c08023e */
if(!s->budget--) { s->failed_pc=0x0c08023eu; return 0; }
write(ram,r[15]+4,r[5],4);
goto P_0c080240;
P_0c080240: /* original d349, guest PC 0x0c080240 */
if(!s->budget--) { s->failed_pc=0x0c080240u; return 0; }
r[3]=read(ram,0x0c080368u,4);
goto P_0c080242;
P_0c080242: /* original 64f2, guest PC 0x0c080242 */
if(!s->budget--) { s->failed_pc=0x0c080242u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c080244;
P_0c080244: /* original bedf, guest PC 0x0c080244 */
if(!s->budget--) { s->failed_pc=0x0c080244u; return 0; }
target=0x0c080006u; r[16]=0x0c080248u;
write(ram,r[4]+16,r[3],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c080248u) { target=s->pc; goto dispatch; }
goto P_0c080248;
P_0c080246: /* original 1434, guest PC 0x0c080246 */
if(!s->budget--) { s->failed_pc=0x0c080246u; return 0; }
write(ram,r[4]+16,r[3],4);
goto P_0c080248;
P_0c080248: /* original d148, guest PC 0x0c080248 */
if(!s->budget--) { s->failed_pc=0x0c080248u; return 0; }
r[1]=read(ram,0x0c08036cu,4);
goto P_0c08024a;
P_0c08024a: /* original 410b, guest PC 0x0c08024a */
if(!s->budget--) { s->failed_pc=0x0c08024au; return 0; }
target=r[1];
r[16]=0x0c08024eu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08024eu) { target=s->pc; goto dispatch; }
goto P_0c08024e;
P_0c08024c: /* original 0009, guest PC 0x0c08024c */
if(!s->budget--) { s->failed_pc=0x0c08024cu; return 0; }
goto P_0c08024e;
P_0c08024e: /* original d248, guest PC 0x0c08024e */
if(!s->budget--) { s->failed_pc=0x0c08024eu; return 0; }
r[2]=read(ram,0x0c080370u,4);
goto P_0c080250;
P_0c080250: /* original 6120, guest PC 0x0c080250 */
if(!s->budget--) { s->failed_pc=0x0c080250u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[2],1);
r[1]=tmp;
goto P_0c080252;
P_0c080252: /* original 7101, guest PC 0x0c080252 */
if(!s->budget--) { s->failed_pc=0x0c080252u; return 0; }
r[1]+=0x00000001u;
goto P_0c080254;
P_0c080254: /* original 2210, guest PC 0x0c080254 */
if(!s->budget--) { s->failed_pc=0x0c080254u; return 0; }
write(ram,r[2],r[1],1);
goto P_0c080256;
P_0c080256: /* original 55f1, guest PC 0x0c080256 */
if(!s->budget--) { s->failed_pc=0x0c080256u; return 0; }
r[5]=read(ram,r[15]+4,4);
goto P_0c080258;
P_0c080258: /* original 64f2, guest PC 0x0c080258 */
if(!s->budget--) { s->failed_pc=0x0c080258u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c08025a;
P_0c08025a: /* original 7f08, guest PC 0x0c08025a */
if(!s->budget--) { s->failed_pc=0x0c08025au; return 0; }
r[15]+=0x00000008u;
goto P_0c08025c;
P_0c08025c: /* original d345, guest PC 0x0c08025c */
if(!s->budget--) { s->failed_pc=0x0c08025cu; return 0; }
r[3]=read(ram,0x0c080374u,4);
goto P_0c08025e;
P_0c08025e: /* original 432b, guest PC 0x0c08025e */
if(!s->budget--) { s->failed_pc=0x0c08025eu; return 0; }
target=r[3];
r[16]=read(ram,r[15],4); r[15]+=4;
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
P_0c080260: /* original 4f26, guest PC 0x0c080260 */
if(!s->budget--) { s->failed_pc=0x0c080260u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
return vf3_matrix_family(0x0c080262u,s,ram);
P_0c0803fe: /* original 2fe6, guest PC 0x0c0803fe */
if(!s->budget--) { s->failed_pc=0x0c0803feu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c080400;
P_0c080400: /* original 4f22, guest PC 0x0c080400 */
if(!s->budget--) { s->failed_pc=0x0c080400u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c080402;
P_0c080402: /* original d534, guest PC 0x0c080402 */
if(!s->budget--) { s->failed_pc=0x0c080402u; return 0; }
r[5]=read(ram,0x0c0804d4u,4);
goto P_0c080404;
P_0c080404: /* original de2d, guest PC 0x0c080404 */
if(!s->budget--) { s->failed_pc=0x0c080404u; return 0; }
r[14]=read(ram,0x0c0804bcu,4);
goto P_0c080406;
P_0c080406: /* original 944f, guest PC 0x0c080406 */
if(!s->budget--) { s->failed_pc=0x0c080406u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0804a8u,2);
goto P_0c080408;
P_0c080408: /* original 4e0b, guest PC 0x0c080408 */
if(!s->budget--) { s->failed_pc=0x0c080408u; return 0; }
target=r[14];
r[16]=0x0c08040cu;
r[6]=0x00000001u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08040cu) { target=s->pc; goto dispatch; }
goto P_0c08040c;
P_0c08040a: /* original e601, guest PC 0x0c08040a */
if(!s->budget--) { s->failed_pc=0x0c08040au; return 0; }
r[6]=0x00000001u;
goto P_0c08040c;
P_0c08040c: /* original d532, guest PC 0x0c08040c */
if(!s->budget--) { s->failed_pc=0x0c08040cu; return 0; }
r[5]=read(ram,0x0c0804d8u,4);
goto P_0c08040e;
P_0c08040e: /* original 944c, guest PC 0x0c08040e */
if(!s->budget--) { s->failed_pc=0x0c08040eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0804aau,2);
goto P_0c080410;
P_0c080410: /* original 4e0b, guest PC 0x0c080410 */
if(!s->budget--) { s->failed_pc=0x0c080410u; return 0; }
target=r[14];
r[16]=0x0c080414u;
r[6]=0x00000001u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c080414u) { target=s->pc; goto dispatch; }
goto P_0c080414;
P_0c080412: /* original e601, guest PC 0x0c080412 */
if(!s->budget--) { s->failed_pc=0x0c080412u; return 0; }
r[6]=0x00000001u;
goto P_0c080414;
P_0c080414: /* original d531, guest PC 0x0c080414 */
if(!s->budget--) { s->failed_pc=0x0c080414u; return 0; }
r[5]=read(ram,0x0c0804dcu,4);
goto P_0c080416;
P_0c080416: /* original 9449, guest PC 0x0c080416 */
if(!s->budget--) { s->failed_pc=0x0c080416u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0804acu,2);
goto P_0c080418;
P_0c080418: /* original 4e0b, guest PC 0x0c080418 */
if(!s->budget--) { s->failed_pc=0x0c080418u; return 0; }
target=r[14];
r[16]=0x0c08041cu;
r[6]=0x00000001u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08041cu) { target=s->pc; goto dispatch; }
goto P_0c08041c;
P_0c08041a: /* original e601, guest PC 0x0c08041a */
if(!s->budget--) { s->failed_pc=0x0c08041au; return 0; }
r[6]=0x00000001u;
goto P_0c08041c;
P_0c08041c: /* original 4f26, guest PC 0x0c08041c */
if(!s->budget--) { s->failed_pc=0x0c08041cu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c08041e;
P_0c08041e: /* original 000b, guest PC 0x0c08041e */
if(!s->budget--) { s->failed_pc=0x0c08041eu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c080420: /* original 6ef6, guest PC 0x0c080420 */
if(!s->budget--) { s->failed_pc=0x0c080420u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c080422;
P_0c080422: /* original 4f22, guest PC 0x0c080422 */
if(!s->budget--) { s->failed_pc=0x0c080422u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c080424;
P_0c080424: /* original 7ff8, guest PC 0x0c080424 */
if(!s->budget--) { s->failed_pc=0x0c080424u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c080426;
P_0c080426: /* original 2f42, guest PC 0x0c080426 */
if(!s->budget--) { s->failed_pc=0x0c080426u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c080428;
P_0c080428: /* original 1f51, guest PC 0x0c080428 */
if(!s->budget--) { s->failed_pc=0x0c080428u; return 0; }
write(ram,r[15]+4,r[5],4);
goto P_0c08042a;
P_0c08042a: /* original d32d, guest PC 0x0c08042a */
if(!s->budget--) { s->failed_pc=0x0c08042au; return 0; }
r[3]=read(ram,0x0c0804e0u,4);
goto P_0c08042c;
P_0c08042c: /* original 64f2, guest PC 0x0c08042c */
if(!s->budget--) { s->failed_pc=0x0c08042cu; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c08042e;
P_0c08042e: /* original bfe6, guest PC 0x0c08042e */
if(!s->budget--) { s->failed_pc=0x0c08042eu; return 0; }
target=0x0c0803feu; r[16]=0x0c080432u;
write(ram,r[4]+16,r[3],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c080432u) { target=s->pc; goto dispatch; }
goto P_0c080432;
P_0c080430: /* original 1434, guest PC 0x0c080430 */
if(!s->budget--) { s->failed_pc=0x0c080430u; return 0; }
write(ram,r[4]+16,r[3],4);
goto P_0c080432;
P_0c080432: /* original d12c, guest PC 0x0c080432 */
if(!s->budget--) { s->failed_pc=0x0c080432u; return 0; }
r[1]=read(ram,0x0c0804e4u,4);
goto P_0c080434;
P_0c080434: /* original 6210, guest PC 0x0c080434 */
if(!s->budget--) { s->failed_pc=0x0c080434u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[1],1);
r[2]=tmp;
goto P_0c080436;
P_0c080436: /* original 7201, guest PC 0x0c080436 */
if(!s->budget--) { s->failed_pc=0x0c080436u; return 0; }
r[2]+=0x00000001u;
goto P_0c080438;
P_0c080438: /* original 2120, guest PC 0x0c080438 */
if(!s->budget--) { s->failed_pc=0x0c080438u; return 0; }
write(ram,r[1],r[2],1);
goto P_0c08043a;
P_0c08043a: /* original 55f1, guest PC 0x0c08043a */
if(!s->budget--) { s->failed_pc=0x0c08043au; return 0; }
r[5]=read(ram,r[15]+4,4);
goto P_0c08043c;
P_0c08043c: /* original 64f2, guest PC 0x0c08043c */
if(!s->budget--) { s->failed_pc=0x0c08043cu; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c08043e;
P_0c08043e: /* original 7f08, guest PC 0x0c08043e */
if(!s->budget--) { s->failed_pc=0x0c08043eu; return 0; }
r[15]+=0x00000008u;
goto P_0c080440;
P_0c080440: /* original a000, guest PC 0x0c080440 */
if(!s->budget--) { s->failed_pc=0x0c080440u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c080444;
P_0c080442: /* original 4f26, guest PC 0x0c080442 */
if(!s->budget--) { s->failed_pc=0x0c080442u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c080444;
P_0c080444: /* original 4f22, guest PC 0x0c080444 */
if(!s->budget--) { s->failed_pc=0x0c080444u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c080446;
P_0c080446: /* original 7ff8, guest PC 0x0c080446 */
if(!s->budget--) { s->failed_pc=0x0c080446u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c080448;
P_0c080448: /* original 2f42, guest PC 0x0c080448 */
if(!s->budget--) { s->failed_pc=0x0c080448u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c08044a;
P_0c08044a: /* original bfd8, guest PC 0x0c08044a */
if(!s->budget--) { s->failed_pc=0x0c08044au; return 0; }
target=0x0c0803feu; r[16]=0x0c08044eu;
write(ram,r[15]+4,r[5],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08044eu) { target=s->pc; goto dispatch; }
goto P_0c08044e;
P_0c08044c: /* original 1f51, guest PC 0x0c08044c */
if(!s->budget--) { s->failed_pc=0x0c08044cu; return 0; }
write(ram,r[15]+4,r[5],4);
goto P_0c08044e;
P_0c08044e: /* original d21c, guest PC 0x0c08044e */
if(!s->budget--) { s->failed_pc=0x0c08044eu; return 0; }
r[2]=read(ram,0x0c0804c0u,4);
goto P_0c080450;
P_0c080450: /* original e510, guest PC 0x0c080450 */
if(!s->budget--) { s->failed_pc=0x0c080450u; return 0; }
r[5]=0x00000010u;
goto P_0c080452;
P_0c080452: /* original e603, guest PC 0x0c080452 */
if(!s->budget--) { s->failed_pc=0x0c080452u; return 0; }
r[6]=0x00000003u;
goto P_0c080454;
P_0c080454: /* original 420b, guest PC 0x0c080454 */
if(!s->budget--) { s->failed_pc=0x0c080454u; return 0; }
target=r[2];
r[16]=0x0c080458u;
r[4]=0x00000014u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c080458u) { target=s->pc; goto dispatch; }
goto P_0c080458;
P_0c080456: /* original e414, guest PC 0x0c080456 */
if(!s->budget--) { s->failed_pc=0x0c080456u; return 0; }
r[4]=0x00000014u;
goto P_0c080458;
P_0c080458: /* original d31d, guest PC 0x0c080458 */
if(!s->budget--) { s->failed_pc=0x0c080458u; return 0; }
r[3]=read(ram,0x0c0804d0u,4);
goto P_0c08045a;
P_0c08045a: /* original 64f2, guest PC 0x0c08045a */
if(!s->budget--) { s->failed_pc=0x0c08045au; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c08045c;
P_0c08045c: /* original 55f1, guest PC 0x0c08045c */
if(!s->budget--) { s->failed_pc=0x0c08045cu; return 0; }
r[5]=read(ram,r[15]+4,4);
goto P_0c08045e;
P_0c08045e: /* original 7f08, guest PC 0x0c08045e */
if(!s->budget--) { s->failed_pc=0x0c08045eu; return 0; }
r[15]+=0x00000008u;
goto P_0c080460;
P_0c080460: /* original 432b, guest PC 0x0c080460 */
if(!s->budget--) { s->failed_pc=0x0c080460u; return 0; }
target=r[3];
r[16]=read(ram,r[15],4); r[15]+=4;
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
P_0c080462: /* original 4f26, guest PC 0x0c080462 */
if(!s->budget--) { s->failed_pc=0x0c080462u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
return vf3_matrix_family(0x0c080464u,s,ram);
P_0c081a9e: /* original 4f22, guest PC 0x0c081a9e */
if(!s->budget--) { s->failed_pc=0x0c081a9eu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c081aa0;
P_0c081aa0: /* original 6263, guest PC 0x0c081aa0 */
if(!s->budget--) { s->failed_pc=0x0c081aa0u; return 0; }
r[2]=r[6];
goto P_0c081aa2;
P_0c081aa2: /* original 4400, guest PC 0x0c081aa2 */
if(!s->budget--) { s->failed_pc=0x0c081aa2u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c081aa4;
P_0c081aa4: /* original 4f12, guest PC 0x0c081aa4 */
if(!s->budget--) { s->failed_pc=0x0c081aa4u; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c081aa6;
P_0c081aa6: /* original 7ff0, guest PC 0x0c081aa6 */
if(!s->budget--) { s->failed_pc=0x0c081aa6u; return 0; }
r[15]+=0xfffffff0u;
goto P_0c081aa8;
P_0c081aa8: /* original 1f51, guest PC 0x0c081aa8 */
if(!s->budget--) { s->failed_pc=0x0c081aa8u; return 0; }
write(ram,r[15]+4,r[5],4);
goto P_0c081aaa;
P_0c081aaa: /* original 2f62, guest PC 0x0c081aaa */
if(!s->budget--) { s->failed_pc=0x0c081aaau; return 0; }
write(ram,r[15],r[6],4);
goto P_0c081aac;
P_0c081aac: /* original e601, guest PC 0x0c081aac */
if(!s->budget--) { s->failed_pc=0x0c081aacu; return 0; }
r[6]=0x00000001u;
goto P_0c081aae;
P_0c081aae: /* original d322, guest PC 0x0c081aae */
if(!s->budget--) { s->failed_pc=0x0c081aaeu; return 0; }
r[3]=read(ram,0x0c081b38u,4);
goto P_0c081ab0;
P_0c081ab0: /* original 6530, guest PC 0x0c081ab0 */
if(!s->budget--) { s->failed_pc=0x0c081ab0u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[3],1);
r[5]=tmp;
goto P_0c081ab2;
P_0c081ab2: /* original 225f, guest PC 0x0c081ab2 */
if(!s->budget--) { s->failed_pc=0x0c081ab2u; return 0; }
r[19]=(uint32_t)((int32_t)(int16_t)r[2]*(int32_t)(int16_t)r[5]);
goto P_0c081ab4;
P_0c081ab4: /* original 52f1, guest PC 0x0c081ab4 */
if(!s->budget--) { s->failed_pc=0x0c081ab4u; return 0; }
r[2]=read(ram,r[15]+4,4);
goto P_0c081ab6;
P_0c081ab6: /* original 1f42, guest PC 0x0c081ab6 */
if(!s->budget--) { s->failed_pc=0x0c081ab6u; return 0; }
write(ram,r[15]+8,r[4],4);
goto P_0c081ab8;
P_0c081ab8: /* original 051a, guest PC 0x0c081ab8 */
if(!s->budget--) { s->failed_pc=0x0c081ab8u; return 0; }
r[5]=r[19];
goto P_0c081aba;
P_0c081aba: /* original 352c, guest PC 0x0c081aba */
if(!s->budget--) { s->failed_pc=0x0c081abau; return 0; }
r[5]+=r[2];
goto P_0c081abc;
P_0c081abc: /* original e207, guest PC 0x0c081abc */
if(!s->budget--) { s->failed_pc=0x0c081abcu; return 0; }
r[2]=0x00000007u;
goto P_0c081abe;
P_0c081abe: /* original 655e, guest PC 0x0c081abe */
if(!s->budget--) { s->failed_pc=0x0c081abeu; return 0; }
r[5]=(uint32_t)(int32_t)(int8_t)r[5];
goto P_0c081ac0;
P_0c081ac0: /* original 452c, guest PC 0x0c081ac0 */
if(!s->budget--) { s->failed_pc=0x0c081ac0u; return 0; }
r[5]=(r[2]&0x80000000u)?((r[2]&31u)?(uint32_t)((int32_t)r[5]>>((-r[2])&31u)):((int32_t)r[5]<0?0xffffffffu:0)):r[5]<<(r[2]&31u);
goto P_0c081ac2;
P_0c081ac2: /* original 254b, guest PC 0x0c081ac2 */
if(!s->budget--) { s->failed_pc=0x0c081ac2u; return 0; }
r[5]|=r[4];
goto P_0c081ac4;
P_0c081ac4: /* original 1f53, guest PC 0x0c081ac4 */
if(!s->budget--) { s->failed_pc=0x0c081ac4u; return 0; }
write(ram,r[15]+12,r[5],4);
goto P_0c081ac6;
P_0c081ac6: /* original d51d, guest PC 0x0c081ac6 */
if(!s->budget--) { s->failed_pc=0x0c081ac6u; return 0; }
r[5]=read(ram,0x0c081b3cu,4);
goto P_0c081ac8;
P_0c081ac8: /* original d11d, guest PC 0x0c081ac8 */
if(!s->budget--) { s->failed_pc=0x0c081ac8u; return 0; }
r[1]=read(ram,0x0c081b40u,4);
goto P_0c081aca;
P_0c081aca: /* original 410b, guest PC 0x0c081aca */
if(!s->budget--) { s->failed_pc=0x0c081acau; return 0; }
target=r[1];
r[16]=0x0c081aceu;
r[4]=read(ram,r[15]+12,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c081aceu) { target=s->pc; goto dispatch; }
goto P_0c081ace;
P_0c081acc: /* original 54f3, guest PC 0x0c081acc */
if(!s->budget--) { s->failed_pc=0x0c081accu; return 0; }
r[4]=read(ram,r[15]+12,4);
goto P_0c081ace;
P_0c081ace: /* original d31d, guest PC 0x0c081ace */
if(!s->budget--) { s->failed_pc=0x0c081aceu; return 0; }
r[3]=read(ram,0x0c081b44u,4);
goto P_0c081ad0;
P_0c081ad0: /* original 62f2, guest PC 0x0c081ad0 */
if(!s->budget--) { s->failed_pc=0x0c081ad0u; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c081ad2;
P_0c081ad2: /* original 6430, guest PC 0x0c081ad2 */
if(!s->budget--) { s->failed_pc=0x0c081ad2u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[3],1);
r[4]=tmp;
goto P_0c081ad4;
P_0c081ad4: /* original 51f2, guest PC 0x0c081ad4 */
if(!s->budget--) { s->failed_pc=0x0c081ad4u; return 0; }
r[1]=read(ram,r[15]+8,4);
goto P_0c081ad6;
P_0c081ad6: /* original 224f, guest PC 0x0c081ad6 */
if(!s->budget--) { s->failed_pc=0x0c081ad6u; return 0; }
r[19]=(uint32_t)((int32_t)(int16_t)r[2]*(int32_t)(int16_t)r[4]);
goto P_0c081ad8;
P_0c081ad8: /* original 52f1, guest PC 0x0c081ad8 */
if(!s->budget--) { s->failed_pc=0x0c081ad8u; return 0; }
r[2]=read(ram,r[15]+4,4);
goto P_0c081ada;
P_0c081ada: /* original 041a, guest PC 0x0c081ada */
if(!s->budget--) { s->failed_pc=0x0c081adau; return 0; }
r[4]=r[19];
goto P_0c081adc;
P_0c081adc: /* original 342c, guest PC 0x0c081adc */
if(!s->budget--) { s->failed_pc=0x0c081adcu; return 0; }
r[4]+=r[2];
goto P_0c081ade;
P_0c081ade: /* original e207, guest PC 0x0c081ade */
if(!s->budget--) { s->failed_pc=0x0c081adeu; return 0; }
r[2]=0x00000007u;
goto P_0c081ae0;
P_0c081ae0: /* original 644e, guest PC 0x0c081ae0 */
if(!s->budget--) { s->failed_pc=0x0c081ae0u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)r[4];
goto P_0c081ae2;
P_0c081ae2: /* original 442c, guest PC 0x0c081ae2 */
if(!s->budget--) { s->failed_pc=0x0c081ae2u; return 0; }
r[4]=(r[2]&0x80000000u)?((r[2]&31u)?(uint32_t)((int32_t)r[4]>>((-r[2])&31u)):((int32_t)r[4]<0?0xffffffffu:0)):r[4]<<(r[2]&31u);
goto P_0c081ae4;
P_0c081ae4: /* original 241b, guest PC 0x0c081ae4 */
if(!s->budget--) { s->failed_pc=0x0c081ae4u; return 0; }
r[4]|=r[1];
goto P_0c081ae6;
P_0c081ae6: /* original 2f42, guest PC 0x0c081ae6 */
if(!s->budget--) { s->failed_pc=0x0c081ae6u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c081ae8;
P_0c081ae8: /* original d518, guest PC 0x0c081ae8 */
if(!s->budget--) { s->failed_pc=0x0c081ae8u; return 0; }
r[5]=read(ram,0x0c081b4cu,4);
goto P_0c081aea;
P_0c081aea: /* original d315, guest PC 0x0c081aea */
if(!s->budget--) { s->failed_pc=0x0c081aeau; return 0; }
r[3]=read(ram,0x0c081b40u,4);
goto P_0c081aec;
P_0c081aec: /* original 430b, guest PC 0x0c081aec */
if(!s->budget--) { s->failed_pc=0x0c081aecu; return 0; }
target=r[3];
r[16]=0x0c081af0u;
r[6]=0x00000001u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c081af0u) { target=s->pc; goto dispatch; }
goto P_0c081af0;
P_0c081aee: /* original e601, guest PC 0x0c081aee */
if(!s->budget--) { s->failed_pc=0x0c081aeeu; return 0; }
r[6]=0x00000001u;
goto P_0c081af0;
P_0c081af0: /* original 7f10, guest PC 0x0c081af0 */
if(!s->budget--) { s->failed_pc=0x0c081af0u; return 0; }
r[15]+=0x00000010u;
goto P_0c081af2;
P_0c081af2: /* original 4f16, guest PC 0x0c081af2 */
if(!s->budget--) { s->failed_pc=0x0c081af2u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c081af4;
P_0c081af4: /* original 4f26, guest PC 0x0c081af4 */
if(!s->budget--) { s->failed_pc=0x0c081af4u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c081af6;
P_0c081af6: /* original 000b, guest PC 0x0c081af6 */
if(!s->budget--) { s->failed_pc=0x0c081af6u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c081af8: /* original 0009, guest PC 0x0c081af8 */
if(!s->budget--) { s->failed_pc=0x0c081af8u; return 0; }
goto P_0c081afa;
P_0c081afa: /* original 2fe6, guest PC 0x0c081afa */
if(!s->budget--) { s->failed_pc=0x0c081afau; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c081afc;
P_0c081afc: /* original d115, guest PC 0x0c081afc */
if(!s->budget--) { s->failed_pc=0x0c081afcu; return 0; }
r[1]=read(ram,0x0c081b54u,4);
goto P_0c081afe;
P_0c081afe: /* original 4f22, guest PC 0x0c081afe */
if(!s->budget--) { s->failed_pc=0x0c081afeu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c081b00;
P_0c081b00: /* original 6212, guest PC 0x0c081b00 */
if(!s->budget--) { s->failed_pc=0x0c081b00u; return 0; }
tmp=read(ram,r[1],4);
r[2]=tmp;
goto P_0c081b02;
P_0c081b02: /* original d313, guest PC 0x0c081b02 */
if(!s->budget--) { s->failed_pc=0x0c081b02u; return 0; }
r[3]=read(ram,0x0c081b50u,4);
goto P_0c081b04;
P_0c081b04: /* original 2238, guest PC 0x0c081b04 */
if(!s->budget--) { s->failed_pc=0x0c081b04u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c081b06;
P_0c081b06: /* original 8b0b, guest PC 0x0c081b06 */
if(!s->budget--) { s->failed_pc=0x0c081b06u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c081b20; }
goto P_0c081b08;
P_0c081b08: /* original d313, guest PC 0x0c081b08 */
if(!s->budget--) { s->failed_pc=0x0c081b08u; return 0; }
r[3]=read(ram,0x0c081b58u,4);
goto P_0c081b0a;
P_0c081b0a: /* original 9e0f, guest PC 0x0c081b0a */
if(!s->budget--) { s->failed_pc=0x0c081b0au; return 0; }
r[14]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c081b2cu,2);
goto P_0c081b0c;
P_0c081b0c: /* original 6432, guest PC 0x0c081b0c */
if(!s->budget--) { s->failed_pc=0x0c081b0cu; return 0; }
tmp=read(ram,r[3],4);
r[4]=tmp;
goto P_0c081b0e;
P_0c081b0e: /* original 66e3, guest PC 0x0c081b0e */
if(!s->budget--) { s->failed_pc=0x0c081b0eu; return 0; }
r[6]=r[14];
goto P_0c081b10;
P_0c081b10: /* original b026, guest PC 0x0c081b10 */
if(!s->budget--) { s->failed_pc=0x0c081b10u; return 0; }
target=0x0c081b60u; r[16]=0x0c081b14u;
r[5]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c081b14u) { target=s->pc; goto dispatch; }
goto P_0c081b14;
P_0c081b12: /* original 65e3, guest PC 0x0c081b12 */
if(!s->budget--) { s->failed_pc=0x0c081b12u; return 0; }
r[5]=r[14];
goto P_0c081b14;
P_0c081b14: /* original d311, guest PC 0x0c081b14 */
if(!s->budget--) { s->failed_pc=0x0c081b14u; return 0; }
r[3]=read(ram,0x0c081b5cu,4);
goto P_0c081b16;
P_0c081b16: /* original 7e58, guest PC 0x0c081b16 */
if(!s->budget--) { s->failed_pc=0x0c081b16u; return 0; }
r[14]+=0x00000058u;
goto P_0c081b18;
P_0c081b18: /* original 66e3, guest PC 0x0c081b18 */
if(!s->budget--) { s->failed_pc=0x0c081b18u; return 0; }
r[6]=r[14];
goto P_0c081b1a;
P_0c081b1a: /* original 6432, guest PC 0x0c081b1a */
if(!s->budget--) { s->failed_pc=0x0c081b1au; return 0; }
tmp=read(ram,r[3],4);
r[4]=tmp;
goto P_0c081b1c;
P_0c081b1c: /* original b020, guest PC 0x0c081b1c */
if(!s->budget--) { s->failed_pc=0x0c081b1cu; return 0; }
target=0x0c081b60u; r[16]=0x0c081b20u;
r[5]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c081b20u) { target=s->pc; goto dispatch; }
goto P_0c081b20;
P_0c081b1e: /* original 65e3, guest PC 0x0c081b1e */
if(!s->budget--) { s->failed_pc=0x0c081b1eu; return 0; }
r[5]=r[14];
goto P_0c081b20;
P_0c081b20: /* original 4f26, guest PC 0x0c081b20 */
if(!s->budget--) { s->failed_pc=0x0c081b20u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c081b22;
P_0c081b22: /* original 000b, guest PC 0x0c081b22 */
if(!s->budget--) { s->failed_pc=0x0c081b22u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c081b24: /* original 6ef6, guest PC 0x0c081b24 */
if(!s->budget--) { s->failed_pc=0x0c081b24u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c081b26u,s,ram);
P_0c081b60: /* original 2fe6, guest PC 0x0c081b60 */
if(!s->budget--) { s->failed_pc=0x0c081b60u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c081b62;
P_0c081b62: /* original ee09, guest PC 0x0c081b62 */
if(!s->budget--) { s->failed_pc=0x0c081b62u; return 0; }
r[14]=0x00000009u;
goto P_0c081b64;
P_0c081b64: /* original 2fd6, guest PC 0x0c081b64 */
if(!s->budget--) { s->failed_pc=0x0c081b64u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c081b66;
P_0c081b66: /* original 2fc6, guest PC 0x0c081b66 */
if(!s->budget--) { s->failed_pc=0x0c081b66u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c081b68;
P_0c081b68: /* original 6c53, guest PC 0x0c081b68 */
if(!s->budget--) { s->failed_pc=0x0c081b68u; return 0; }
r[12]=r[5];
goto P_0c081b6a;
P_0c081b6a: /* original 2fb6, guest PC 0x0c081b6a */
if(!s->budget--) { s->failed_pc=0x0c081b6au; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c081b6c;
P_0c081b6c: /* original 2fa6, guest PC 0x0c081b6c */
if(!s->budget--) { s->failed_pc=0x0c081b6cu; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c081b6e;
P_0c081b6e: /* original 2f96, guest PC 0x0c081b6e */
if(!s->budget--) { s->failed_pc=0x0c081b6eu; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c081b70;
P_0c081b70: /* original 2f86, guest PC 0x0c081b70 */
if(!s->budget--) { s->failed_pc=0x0c081b70u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c081b72;
P_0c081b72: /* original 4f22, guest PC 0x0c081b72 */
if(!s->budget--) { s->failed_pc=0x0c081b72u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c081b74;
P_0c081b74: /* original 7ff8, guest PC 0x0c081b74 */
if(!s->budget--) { s->failed_pc=0x0c081b74u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c081b76;
P_0c081b76: /* original 1f61, guest PC 0x0c081b76 */
if(!s->budget--) { s->failed_pc=0x0c081b76u; return 0; }
write(ram,r[15]+4,r[6],4);
goto P_0c081b78;
P_0c081b78: /* original 902f, guest PC 0x0c081b78 */
if(!s->budget--) { s->failed_pc=0x0c081b78u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c081bdau,2);
goto P_0c081b7a;
P_0c081b7a: /* original 992f, guest PC 0x0c081b7a */
if(!s->budget--) { s->failed_pc=0x0c081b7au; return 0; }
r[9]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c081bdcu,2);
goto P_0c081b7c;
P_0c081b7c: /* original 054c, guest PC 0x0c081b7c */
if(!s->budget--) { s->failed_pc=0x0c081b7cu; return 0; }
r[5]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c081b7e;
P_0c081b7e: /* original e410, guest PC 0x0c081b7e */
if(!s->budget--) { s->failed_pc=0x0c081b7eu; return 0; }
r[4]=0x00000010u;
goto P_0c081b80;
P_0c081b80: /* original 6343, guest PC 0x0c081b80 */
if(!s->budget--) { s->failed_pc=0x0c081b80u; return 0; }
r[3]=r[4];
goto P_0c081b82;
P_0c081b82: /* original 7370, guest PC 0x0c081b82 */
if(!s->budget--) { s->failed_pc=0x0c081b82u; return 0; }
r[3]+=0x00000070u;
goto P_0c081b84;
P_0c081b84: /* original 6d5e, guest PC 0x0c081b84 */
if(!s->budget--) { s->failed_pc=0x0c081b84u; return 0; }
r[13]=(uint32_t)(int32_t)(int8_t)r[5];
goto P_0c081b86;
P_0c081b86: /* original db16, guest PC 0x0c081b86 */
if(!s->budget--) { s->failed_pc=0x0c081b86u; return 0; }
r[11]=read(ram,0x0c081be0u,4);
goto P_0c081b88;
P_0c081b88: /* original 2f92, guest PC 0x0c081b88 */
if(!s->budget--) { s->failed_pc=0x0c081b88u; return 0; }
write(ram,r[15],r[9],4);
goto P_0c081b8a;
P_0c081b8a: /* original 23d8, guest PC 0x0c081b8a */
if(!s->budget--) { s->failed_pc=0x0c081b8au; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[13])==0)!=0);
goto P_0c081b8c;
P_0c081b8c: /* original d815, guest PC 0x0c081b8c */
if(!s->budget--) { s->failed_pc=0x0c081b8cu; return 0; }
r[8]=read(ram,0x0c081be4u,4);
goto P_0c081b8e;
P_0c081b8e: /* original 8d0f, guest PC 0x0c081b8e */
if(!s->budget--) { s->failed_pc=0x0c081b8eu; return 0; }
cond=r[17]&1u;
r[10]=0x00000000u;
if(cond) { goto P_0c081bb0; }
goto P_0c081b92;
P_0c081b90: /* original ea00, guest PC 0x0c081b90 */
if(!s->budget--) { s->failed_pc=0x0c081b90u; return 0; }
r[10]=0x00000000u;
goto P_0c081b92;
P_0c081b92: /* original e240, guest PC 0x0c081b92 */
if(!s->budget--) { s->failed_pc=0x0c081b92u; return 0; }
r[2]=0x00000040u;
goto P_0c081b94;
P_0c081b94: /* original 22d8, guest PC 0x0c081b94 */
if(!s->budget--) { s->failed_pc=0x0c081b94u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[13])==0)!=0);
goto P_0c081b96;
P_0c081b96: /* original 8912, guest PC 0x0c081b96 */
if(!s->budget--) { s->failed_pc=0x0c081b96u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c081bbe; }
goto P_0c081b98;
P_0c081b98: /* original e320, guest PC 0x0c081b98 */
if(!s->budget--) { s->failed_pc=0x0c081b98u; return 0; }
r[3]=0x00000020u;
goto P_0c081b9a;
P_0c081b9a: /* original 23d8, guest PC 0x0c081b9a */
if(!s->budget--) { s->failed_pc=0x0c081b9au; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[13])==0)!=0);
goto P_0c081b9c;
P_0c081b9c: /* original 8917, guest PC 0x0c081b9c */
if(!s->budget--) { s->failed_pc=0x0c081b9cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c081bce; }
goto P_0c081b9e;
P_0c081b9e: /* original 24d8, guest PC 0x0c081b9e */
if(!s->budget--) { s->failed_pc=0x0c081b9eu; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[13])==0)!=0);
goto P_0c081ba0;
P_0c081ba0: /* original 8917, guest PC 0x0c081ba0 */
if(!s->budget--) { s->failed_pc=0x0c081ba0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c081bd2; }
goto P_0c081ba2;
P_0c081ba2: /* original d312, guest PC 0x0c081ba2 */
if(!s->budget--) { s->failed_pc=0x0c081ba2u; return 0; }
r[3]=read(ram,0x0c081becu,4);
goto P_0c081ba4;
P_0c081ba4: /* original e601, guest PC 0x0c081ba4 */
if(!s->budget--) { s->failed_pc=0x0c081ba4u; return 0; }
r[6]=0x00000001u;
goto P_0c081ba6;
P_0c081ba6: /* original d510, guest PC 0x0c081ba6 */
if(!s->budget--) { s->failed_pc=0x0c081ba6u; return 0; }
r[5]=read(ram,0x0c081be8u,4);
goto P_0c081ba8;
P_0c081ba8: /* original 430b, guest PC 0x0c081ba8 */
if(!s->budget--) { s->failed_pc=0x0c081ba8u; return 0; }
target=r[3];
r[16]=0x0c081bacu;
r[4]=r[12];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c081bacu) { target=s->pc; goto dispatch; }
goto P_0c081bac;
P_0c081baa: /* original 64c3, guest PC 0x0c081baa */
if(!s->budget--) { s->failed_pc=0x0c081baau; return 0; }
r[4]=r[12];
goto P_0c081bac;
P_0c081bac: /* original a02c, guest PC 0x0c081bac */
if(!s->budget--) { s->failed_pc=0x0c081bacu; return 0; }
r[12]=read(ram,r[15]+4,4);
goto P_0c081c08;
P_0c081bae: /* original 5cf1, guest PC 0x0c081bae */
if(!s->budget--) { s->failed_pc=0x0c081baeu; return 0; }
r[12]=read(ram,r[15]+4,4);
goto P_0c081bb0;
P_0c081bb0: /* original e220, guest PC 0x0c081bb0 */
if(!s->budget--) { s->failed_pc=0x0c081bb0u; return 0; }
r[2]=0x00000020u;
goto P_0c081bb2;
P_0c081bb2: /* original 22d8, guest PC 0x0c081bb2 */
if(!s->budget--) { s->failed_pc=0x0c081bb2u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[13])==0)!=0);
goto P_0c081bb4;
P_0c081bb4: /* original 890f, guest PC 0x0c081bb4 */
if(!s->budget--) { s->failed_pc=0x0c081bb4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c081bd6; }
goto P_0c081bb6;
P_0c081bb6: /* original 24d8, guest PC 0x0c081bb6 */
if(!s->budget--) { s->failed_pc=0x0c081bb6u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[13])==0)!=0);
goto P_0c081bb8;
P_0c081bb8: /* original 891a, guest PC 0x0c081bb8 */
if(!s->budget--) { s->failed_pc=0x0c081bb8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c081bf0; }
goto P_0c081bba;
P_0c081bba: /* original a01a, guest PC 0x0c081bba */
if(!s->budget--) { s->failed_pc=0x0c081bbau; return 0; }
goto P_0c081bf2;
P_0c081bbc: /* original 0009, guest PC 0x0c081bbc */
if(!s->budget--) { s->failed_pc=0x0c081bbcu; return 0; }
goto P_0c081bbe;
P_0c081bbe: /* original e220, guest PC 0x0c081bbe */
if(!s->budget--) { s->failed_pc=0x0c081bbeu; return 0; }
r[2]=0x00000020u;
goto P_0c081bc0;
P_0c081bc0: /* original 22d8, guest PC 0x0c081bc0 */
if(!s->budget--) { s->failed_pc=0x0c081bc0u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[13])==0)!=0);
goto P_0c081bc2;
P_0c081bc2: /* original 8d08, guest PC 0x0c081bc2 */
if(!s->budget--) { s->failed_pc=0x0c081bc2u; return 0; }
cond=r[17]&1u;
r[14]=0x0000000bu;
if(cond) { goto P_0c081bd6; }
goto P_0c081bc6;
P_0c081bc4: /* original ee0b, guest PC 0x0c081bc4 */
if(!s->budget--) { s->failed_pc=0x0c081bc4u; return 0; }
r[14]=0x0000000bu;
goto P_0c081bc6;
P_0c081bc6: /* original 24d8, guest PC 0x0c081bc6 */
if(!s->budget--) { s->failed_pc=0x0c081bc6u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[13])==0)!=0);
goto P_0c081bc8;
P_0c081bc8: /* original 8912, guest PC 0x0c081bc8 */
if(!s->budget--) { s->failed_pc=0x0c081bc8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c081bf0; }
goto P_0c081bca;
P_0c081bca: /* original a012, guest PC 0x0c081bca */
if(!s->budget--) { s->failed_pc=0x0c081bcau; return 0; }
goto P_0c081bf2;
P_0c081bcc: /* original 0009, guest PC 0x0c081bcc */
if(!s->budget--) { s->failed_pc=0x0c081bccu; return 0; }
goto P_0c081bce;
P_0c081bce: /* original a010, guest PC 0x0c081bce */
if(!s->budget--) { s->failed_pc=0x0c081bceu; return 0; }
r[14]=0x0000000fu;
goto P_0c081bf2;
P_0c081bd0: /* original ee0f, guest PC 0x0c081bd0 */
if(!s->budget--) { s->failed_pc=0x0c081bd0u; return 0; }
r[14]=0x0000000fu;
goto P_0c081bd2;
P_0c081bd2: /* original a00e, guest PC 0x0c081bd2 */
if(!s->budget--) { s->failed_pc=0x0c081bd2u; return 0; }
r[14]=0x0000000du;
goto P_0c081bf2;
P_0c081bd4: /* original ee0d, guest PC 0x0c081bd4 */
if(!s->budget--) { s->failed_pc=0x0c081bd4u; return 0; }
r[14]=0x0000000du;
goto P_0c081bd6;
P_0c081bd6: /* original a00c, guest PC 0x0c081bd6 */
if(!s->budget--) { s->failed_pc=0x0c081bd6u; return 0; }
r[14]+=0x00000008u;
goto P_0c081bf2;
P_0c081bd8: /* original 7e08, guest PC 0x0c081bd8 */
if(!s->budget--) { s->failed_pc=0x0c081bd8u; return 0; }
r[14]+=0x00000008u;
return vf3_matrix_family(0x0c081bdau,s,ram);
P_0c081bf0: /* original 7e0c, guest PC 0x0c081bf0 */
if(!s->budget--) { s->failed_pc=0x0c081bf0u; return 0; }
r[14]+=0x0000000cu;
goto P_0c081bf2;
P_0c081bf2: /* original 938d, guest PC 0x0c081bf2 */
if(!s->budget--) { s->failed_pc=0x0c081bf2u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c081d10u,2);
goto P_0c081bf4;
P_0c081bf4: /* original 4e28, guest PC 0x0c081bf4 */
if(!s->budget--) { s->failed_pc=0x0c081bf4u; return 0; }
r[14]<<=16;
goto P_0c081bf6;
P_0c081bf6: /* original 4e18, guest PC 0x0c081bf6 */
if(!s->budget--) { s->failed_pc=0x0c081bf6u; return 0; }
r[14]<<=8;
goto P_0c081bf8;
P_0c081bf8: /* original 66b3, guest PC 0x0c081bf8 */
if(!s->budget--) { s->failed_pc=0x0c081bf8u; return 0; }
r[6]=r[11];
goto P_0c081bfa;
P_0c081bfa: /* original 3e3c, guest PC 0x0c081bfa */
if(!s->budget--) { s->failed_pc=0x0c081bfau; return 0; }
r[14]+=r[3];
goto P_0c081bfc;
P_0c081bfc: /* original 6593, guest PC 0x0c081bfc */
if(!s->budget--) { s->failed_pc=0x0c081bfcu; return 0; }
r[5]=r[9];
goto P_0c081bfe;
P_0c081bfe: /* original 2fa6, guest PC 0x0c081bfe */
if(!s->budget--) { s->failed_pc=0x0c081bfeu; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c081c00;
P_0c081c00: /* original 67e3, guest PC 0x0c081c00 */
if(!s->budget--) { s->failed_pc=0x0c081c00u; return 0; }
r[7]=r[14];
goto P_0c081c02;
P_0c081c02: /* original 480b, guest PC 0x0c081c02 */
if(!s->budget--) { s->failed_pc=0x0c081c02u; return 0; }
target=r[8];
r[16]=0x0c081c06u;
r[4]=r[12];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c081c06u) { target=s->pc; goto dispatch; }
goto P_0c081c06;
P_0c081c04: /* original 64c3, guest PC 0x0c081c04 */
if(!s->budget--) { s->failed_pc=0x0c081c04u; return 0; }
r[4]=r[12];
goto P_0c081c06;
P_0c081c06: /* original 7f04, guest PC 0x0c081c06 */
if(!s->budget--) { s->failed_pc=0x0c081c06u; return 0; }
r[15]+=0x00000004u;
goto P_0c081c08;
P_0c081c08: /* original 7c04, guest PC 0x0c081c08 */
if(!s->budget--) { s->failed_pc=0x0c081c08u; return 0; }
r[12]+=0x00000004u;
goto P_0c081c0a;
P_0c081c0a: /* original e320, guest PC 0x0c081c0a */
if(!s->budget--) { s->failed_pc=0x0c081c0au; return 0; }
r[3]=0x00000020u;
goto P_0c081c0c;
P_0c081c0c: /* original 1fc1, guest PC 0x0c081c0c */
if(!s->budget--) { s->failed_pc=0x0c081c0cu; return 0; }
write(ram,r[15]+4,r[12],4);
goto P_0c081c0e;
P_0c081c0e: /* original 65c3, guest PC 0x0c081c0e */
if(!s->budget--) { s->failed_pc=0x0c081c0eu; return 0; }
r[5]=r[12];
goto P_0c081c10;
P_0c081c10: /* original e615, guest PC 0x0c081c10 */
if(!s->budget--) { s->failed_pc=0x0c081c10u; return 0; }
r[6]=0x00000015u;
goto P_0c081c12;
P_0c081c12: /* original 2f36, guest PC 0x0c081c12 */
if(!s->budget--) { s->failed_pc=0x0c081c12u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c081c14;
P_0c081c14: /* original e701, guest PC 0x0c081c14 */
if(!s->budget--) { s->failed_pc=0x0c081c14u; return 0; }
r[7]=0x00000001u;
goto P_0c081c16;
P_0c081c16: /* original d240, guest PC 0x0c081c16 */
if(!s->budget--) { s->failed_pc=0x0c081c16u; return 0; }
r[2]=read(ram,0x0c081d18u,4);
goto P_0c081c18;
P_0c081c18: /* original 420b, guest PC 0x0c081c18 */
if(!s->budget--) { s->failed_pc=0x0c081c18u; return 0; }
target=r[2];
r[16]=0x0c081c1cu;
r[4]=r[11];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c081c1cu) { target=s->pc; goto dispatch; }
goto P_0c081c1c;
P_0c081c1a: /* original 64b3, guest PC 0x0c081c1a */
if(!s->budget--) { s->failed_pc=0x0c081c1au; return 0; }
r[4]=r[11];
goto P_0c081c1c;
P_0c081c1c: /* original 7f04, guest PC 0x0c081c1c */
if(!s->budget--) { s->failed_pc=0x0c081c1cu; return 0; }
r[15]+=0x00000004u;
goto P_0c081c1e;
P_0c081c1e: /* original 9c77, guest PC 0x0c081c1e */
if(!s->budget--) { s->failed_pc=0x0c081c1eu; return 0; }
r[12]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c081d10u,2);
goto P_0c081c20;
P_0c081c20: /* original e301, guest PC 0x0c081c20 */
if(!s->budget--) { s->failed_pc=0x0c081c20u; return 0; }
r[3]=0x00000001u;
goto P_0c081c22;
P_0c081c22: /* original 5ef1, guest PC 0x0c081c22 */
if(!s->budget--) { s->failed_pc=0x0c081c22u; return 0; }
r[14]=read(ram,r[15]+4,4);
goto P_0c081c24;
P_0c081c24: /* original 23d8, guest PC 0x0c081c24 */
if(!s->budget--) { s->failed_pc=0x0c081c24u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[13])==0)!=0);
goto P_0c081c26;
P_0c081c26: /* original 8d09, guest PC 0x0c081c26 */
if(!s->budget--) { s->failed_pc=0x0c081c26u; return 0; }
cond=r[17]&1u;
r[4]=r[10];
if(cond) { goto P_0c081c3c; }
goto P_0c081c2a;
P_0c081c28: /* original 64a3, guest PC 0x0c081c28 */
if(!s->budget--) { s->failed_pc=0x0c081c28u; return 0; }
r[4]=r[10];
goto P_0c081c2a;
P_0c081c2a: /* original 6593, guest PC 0x0c081c2a */
if(!s->budget--) { s->failed_pc=0x0c081c2au; return 0; }
r[5]=r[9];
goto P_0c081c2c;
P_0c081c2c: /* original 66b3, guest PC 0x0c081c2c */
if(!s->budget--) { s->failed_pc=0x0c081c2cu; return 0; }
r[6]=r[11];
goto P_0c081c2e;
P_0c081c2e: /* original 2fa6, guest PC 0x0c081c2e */
if(!s->budget--) { s->failed_pc=0x0c081c2eu; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c081c30;
P_0c081c30: /* original 976f, guest PC 0x0c081c30 */
if(!s->budget--) { s->failed_pc=0x0c081c30u; return 0; }
r[7]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c081d12u,2);
goto P_0c081c32;
P_0c081c32: /* original 480b, guest PC 0x0c081c32 */
if(!s->budget--) { s->failed_pc=0x0c081c32u; return 0; }
target=r[8];
r[16]=0x0c081c36u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c081c36u) { target=s->pc; goto dispatch; }
goto P_0c081c36;
P_0c081c34: /* original 64e3, guest PC 0x0c081c34 */
if(!s->budget--) { s->failed_pc=0x0c081c34u; return 0; }
r[4]=r[14];
goto P_0c081c36;
P_0c081c36: /* original 7e04, guest PC 0x0c081c36 */
if(!s->budget--) { s->failed_pc=0x0c081c36u; return 0; }
r[14]+=0x00000004u;
goto P_0c081c38;
P_0c081c38: /* original e401, guest PC 0x0c081c38 */
if(!s->budget--) { s->failed_pc=0x0c081c38u; return 0; }
r[4]=0x00000001u;
goto P_0c081c3a;
P_0c081c3a: /* original 7f04, guest PC 0x0c081c3a */
if(!s->budget--) { s->failed_pc=0x0c081c3au; return 0; }
r[15]+=0x00000004u;
goto P_0c081c3c;
P_0c081c3c: /* original e302, guest PC 0x0c081c3c */
if(!s->budget--) { s->failed_pc=0x0c081c3cu; return 0; }
r[3]=0x00000002u;
goto P_0c081c3e;
P_0c081c3e: /* original 23d8, guest PC 0x0c081c3e */
if(!s->budget--) { s->failed_pc=0x0c081c3eu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[13])==0)!=0);
goto P_0c081c40;
P_0c081c40: /* original 890d, guest PC 0x0c081c40 */
if(!s->budget--) { s->failed_pc=0x0c081c40u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c081c5e; }
goto P_0c081c42;
P_0c081c42: /* original 66e3, guest PC 0x0c081c42 */
if(!s->budget--) { s->failed_pc=0x0c081c42u; return 0; }
r[6]=r[14];
goto P_0c081c44;
P_0c081c44: /* original 67c3, guest PC 0x0c081c44 */
if(!s->budget--) { s->failed_pc=0x0c081c44u; return 0; }
r[7]=r[12];
goto P_0c081c46;
P_0c081c46: /* original b034, guest PC 0x0c081c46 */
if(!s->budget--) { s->failed_pc=0x0c081c46u; return 0; }
target=0x0c081cb2u; r[16]=0x0c081c4au;
tmp=read(ram,r[15],4);
r[5]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c081c4au) { target=s->pc; goto dispatch; }
goto P_0c081c4a;
P_0c081c48: /* original 65f2, guest PC 0x0c081c48 */
if(!s->budget--) { s->failed_pc=0x0c081c48u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c081c4a;
P_0c081c4a: /* original 66b3, guest PC 0x0c081c4a */
if(!s->budget--) { s->failed_pc=0x0c081c4au; return 0; }
r[6]=r[11];
goto P_0c081c4c;
P_0c081c4c: /* original 6593, guest PC 0x0c081c4c */
if(!s->budget--) { s->failed_pc=0x0c081c4cu; return 0; }
r[5]=r[9];
goto P_0c081c4e;
P_0c081c4e: /* original 2fa6, guest PC 0x0c081c4e */
if(!s->budget--) { s->failed_pc=0x0c081c4eu; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c081c50;
P_0c081c50: /* original 6e03, guest PC 0x0c081c50 */
if(!s->budget--) { s->failed_pc=0x0c081c50u; return 0; }
r[14]=r[0];
goto P_0c081c52;
P_0c081c52: /* original 975f, guest PC 0x0c081c52 */
if(!s->budget--) { s->failed_pc=0x0c081c52u; return 0; }
r[7]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c081d14u,2);
goto P_0c081c54;
P_0c081c54: /* original 480b, guest PC 0x0c081c54 */
if(!s->budget--) { s->failed_pc=0x0c081c54u; return 0; }
target=r[8];
r[16]=0x0c081c58u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c081c58u) { target=s->pc; goto dispatch; }
goto P_0c081c58;
P_0c081c56: /* original 64e3, guest PC 0x0c081c56 */
if(!s->budget--) { s->failed_pc=0x0c081c56u; return 0; }
r[4]=r[14];
goto P_0c081c58;
P_0c081c58: /* original 7e04, guest PC 0x0c081c58 */
if(!s->budget--) { s->failed_pc=0x0c081c58u; return 0; }
r[14]+=0x00000004u;
goto P_0c081c5a;
P_0c081c5a: /* original e401, guest PC 0x0c081c5a */
if(!s->budget--) { s->failed_pc=0x0c081c5au; return 0; }
r[4]=0x00000001u;
goto P_0c081c5c;
P_0c081c5c: /* original 7f04, guest PC 0x0c081c5c */
if(!s->budget--) { s->failed_pc=0x0c081c5cu; return 0; }
r[15]+=0x00000004u;
goto P_0c081c5e;
P_0c081c5e: /* original e204, guest PC 0x0c081c5e */
if(!s->budget--) { s->failed_pc=0x0c081c5eu; return 0; }
r[2]=0x00000004u;
goto P_0c081c60;
P_0c081c60: /* original 22d8, guest PC 0x0c081c60 */
if(!s->budget--) { s->failed_pc=0x0c081c60u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[13])==0)!=0);
goto P_0c081c62;
P_0c081c62: /* original 890d, guest PC 0x0c081c62 */
if(!s->budget--) { s->failed_pc=0x0c081c62u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c081c80; }
goto P_0c081c64;
P_0c081c64: /* original 66e3, guest PC 0x0c081c64 */
if(!s->budget--) { s->failed_pc=0x0c081c64u; return 0; }
r[6]=r[14];
goto P_0c081c66;
P_0c081c66: /* original 67c3, guest PC 0x0c081c66 */
if(!s->budget--) { s->failed_pc=0x0c081c66u; return 0; }
r[7]=r[12];
goto P_0c081c68;
P_0c081c68: /* original b023, guest PC 0x0c081c68 */
if(!s->budget--) { s->failed_pc=0x0c081c68u; return 0; }
target=0x0c081cb2u; r[16]=0x0c081c6cu;
tmp=read(ram,r[15],4);
r[5]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c081c6cu) { target=s->pc; goto dispatch; }
goto P_0c081c6c;
P_0c081c6a: /* original 65f2, guest PC 0x0c081c6a */
if(!s->budget--) { s->failed_pc=0x0c081c6au; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c081c6c;
P_0c081c6c: /* original 66b3, guest PC 0x0c081c6c */
if(!s->budget--) { s->failed_pc=0x0c081c6cu; return 0; }
r[6]=r[11];
goto P_0c081c6e;
P_0c081c6e: /* original 6593, guest PC 0x0c081c6e */
if(!s->budget--) { s->failed_pc=0x0c081c6eu; return 0; }
r[5]=r[9];
goto P_0c081c70;
P_0c081c70: /* original 2fa6, guest PC 0x0c081c70 */
if(!s->budget--) { s->failed_pc=0x0c081c70u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c081c72;
P_0c081c72: /* original 6e03, guest PC 0x0c081c72 */
if(!s->budget--) { s->failed_pc=0x0c081c72u; return 0; }
r[14]=r[0];
goto P_0c081c74;
P_0c081c74: /* original 974d, guest PC 0x0c081c74 */
if(!s->budget--) { s->failed_pc=0x0c081c74u; return 0; }
r[7]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c081d12u,2);
goto P_0c081c76;
P_0c081c76: /* original 480b, guest PC 0x0c081c76 */
if(!s->budget--) { s->failed_pc=0x0c081c76u; return 0; }
target=r[8];
r[16]=0x0c081c7au;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c081c7au) { target=s->pc; goto dispatch; }
goto P_0c081c7a;
P_0c081c78: /* original 64e3, guest PC 0x0c081c78 */
if(!s->budget--) { s->failed_pc=0x0c081c78u; return 0; }
r[4]=r[14];
goto P_0c081c7a;
P_0c081c7a: /* original 7e04, guest PC 0x0c081c7a */
if(!s->budget--) { s->failed_pc=0x0c081c7au; return 0; }
r[14]+=0x00000004u;
goto P_0c081c7c;
P_0c081c7c: /* original e401, guest PC 0x0c081c7c */
if(!s->budget--) { s->failed_pc=0x0c081c7cu; return 0; }
r[4]=0x00000001u;
goto P_0c081c7e;
P_0c081c7e: /* original 7f04, guest PC 0x0c081c7e */
if(!s->budget--) { s->failed_pc=0x0c081c7eu; return 0; }
r[15]+=0x00000004u;
goto P_0c081c80;
P_0c081c80: /* original e208, guest PC 0x0c081c80 */
if(!s->budget--) { s->failed_pc=0x0c081c80u; return 0; }
r[2]=0x00000008u;
goto P_0c081c82;
P_0c081c82: /* original 2d28, guest PC 0x0c081c82 */
if(!s->budget--) { s->failed_pc=0x0c081c82u; return 0; }
r[17]=(r[17]&~1u)|(((r[13]&r[2])==0)!=0);
goto P_0c081c84;
P_0c081c84: /* original 890b, guest PC 0x0c081c84 */
if(!s->budget--) { s->failed_pc=0x0c081c84u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c081c9e; }
goto P_0c081c86;
P_0c081c86: /* original 66e3, guest PC 0x0c081c86 */
if(!s->budget--) { s->failed_pc=0x0c081c86u; return 0; }
r[6]=r[14];
goto P_0c081c88;
P_0c081c88: /* original 67c3, guest PC 0x0c081c88 */
if(!s->budget--) { s->failed_pc=0x0c081c88u; return 0; }
r[7]=r[12];
goto P_0c081c8a;
P_0c081c8a: /* original b012, guest PC 0x0c081c8a */
if(!s->budget--) { s->failed_pc=0x0c081c8au; return 0; }
target=0x0c081cb2u; r[16]=0x0c081c8eu;
tmp=read(ram,r[15],4);
r[5]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c081c8eu) { target=s->pc; goto dispatch; }
goto P_0c081c8e;
P_0c081c8c: /* original 65f2, guest PC 0x0c081c8c */
if(!s->budget--) { s->failed_pc=0x0c081c8cu; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c081c8e;
P_0c081c8e: /* original 2f02, guest PC 0x0c081c8e */
if(!s->budget--) { s->failed_pc=0x0c081c8eu; return 0; }
write(ram,r[15],r[0],4);
goto P_0c081c90;
P_0c081c90: /* original 6593, guest PC 0x0c081c90 */
if(!s->budget--) { s->failed_pc=0x0c081c90u; return 0; }
r[5]=r[9];
goto P_0c081c92;
P_0c081c92: /* original 66b3, guest PC 0x0c081c92 */
if(!s->budget--) { s->failed_pc=0x0c081c92u; return 0; }
r[6]=r[11];
goto P_0c081c94;
P_0c081c94: /* original 2fa6, guest PC 0x0c081c94 */
if(!s->budget--) { s->failed_pc=0x0c081c94u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c081c96;
P_0c081c96: /* original 973d, guest PC 0x0c081c96 */
if(!s->budget--) { s->failed_pc=0x0c081c96u; return 0; }
r[7]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c081d14u,2);
goto P_0c081c98;
P_0c081c98: /* original 480b, guest PC 0x0c081c98 */
if(!s->budget--) { s->failed_pc=0x0c081c98u; return 0; }
target=r[8];
r[16]=0x0c081c9cu;
r[4]=r[0];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c081c9cu) { target=s->pc; goto dispatch; }
goto P_0c081c9c;
P_0c081c9a: /* original 6403, guest PC 0x0c081c9a */
if(!s->budget--) { s->failed_pc=0x0c081c9au; return 0; }
r[4]=r[0];
goto P_0c081c9c;
P_0c081c9c: /* original 7f04, guest PC 0x0c081c9c */
if(!s->budget--) { s->failed_pc=0x0c081c9cu; return 0; }
r[15]+=0x00000004u;
goto P_0c081c9e;
P_0c081c9e: /* original 7f08, guest PC 0x0c081c9e */
if(!s->budget--) { s->failed_pc=0x0c081c9eu; return 0; }
r[15]+=0x00000008u;
goto P_0c081ca0;
P_0c081ca0: /* original 4f26, guest PC 0x0c081ca0 */
if(!s->budget--) { s->failed_pc=0x0c081ca0u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c081ca2;
P_0c081ca2: /* original 68f6, guest PC 0x0c081ca2 */
if(!s->budget--) { s->failed_pc=0x0c081ca2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c081ca4;
P_0c081ca4: /* original 69f6, guest PC 0x0c081ca4 */
if(!s->budget--) { s->failed_pc=0x0c081ca4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c081ca6;
P_0c081ca6: /* original 6af6, guest PC 0x0c081ca6 */
if(!s->budget--) { s->failed_pc=0x0c081ca6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c081ca8;
P_0c081ca8: /* original 6bf6, guest PC 0x0c081ca8 */
if(!s->budget--) { s->failed_pc=0x0c081ca8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c081caa;
P_0c081caa: /* original 6cf6, guest PC 0x0c081caa */
if(!s->budget--) { s->failed_pc=0x0c081caau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c081cac;
P_0c081cac: /* original 6df6, guest PC 0x0c081cac */
if(!s->budget--) { s->failed_pc=0x0c081cacu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c081cae;
P_0c081cae: /* original 000b, guest PC 0x0c081cae */
if(!s->budget--) { s->failed_pc=0x0c081caeu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c081cb0: /* original 6ef6, guest PC 0x0c081cb0 */
if(!s->budget--) { s->failed_pc=0x0c081cb0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c081cb2;
P_0c081cb2: /* original 2fe6, guest PC 0x0c081cb2 */
if(!s->budget--) { s->failed_pc=0x0c081cb2u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c081cb4;
P_0c081cb4: /* original 2448, guest PC 0x0c081cb4 */
if(!s->budget--) { s->failed_pc=0x0c081cb4u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c081cb6;
P_0c081cb6: /* original 4f22, guest PC 0x0c081cb6 */
if(!s->budget--) { s->failed_pc=0x0c081cb6u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c081cb8;
P_0c081cb8: /* original 6e63, guest PC 0x0c081cb8 */
if(!s->budget--) { s->failed_pc=0x0c081cb8u; return 0; }
r[14]=r[6];
goto P_0c081cba;
P_0c081cba: /* original 7ff4, guest PC 0x0c081cba */
if(!s->budget--) { s->failed_pc=0x0c081cbau; return 0; }
r[15]+=0xfffffff4u;
goto P_0c081cbc;
P_0c081cbc: /* original 2f52, guest PC 0x0c081cbc */
if(!s->budget--) { s->failed_pc=0x0c081cbcu; return 0; }
write(ram,r[15],r[5],4);
goto P_0c081cbe;
P_0c081cbe: /* original d317, guest PC 0x0c081cbe */
if(!s->budget--) { s->failed_pc=0x0c081cbeu; return 0; }
r[3]=read(ram,0x0c081d1cu,4);
goto P_0c081cc0;
P_0c081cc0: /* original 8d0d, guest PC 0x0c081cc0 */
if(!s->budget--) { s->failed_pc=0x0c081cc0u; return 0; }
cond=r[17]&1u;
write(ram,r[15]+8,r[3],4);
if(cond) { goto P_0c081cde; }
goto P_0c081cc4;
P_0c081cc2: /* original 1f32, guest PC 0x0c081cc2 */
if(!s->budget--) { s->failed_pc=0x0c081cc2u; return 0; }
write(ram,r[15]+8,r[3],4);
goto P_0c081cc4;
P_0c081cc4: /* original 9326, guest PC 0x0c081cc4 */
if(!s->budget--) { s->failed_pc=0x0c081cc4u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c081d14u,2);
goto P_0c081cc6;
P_0c081cc6: /* original e200, guest PC 0x0c081cc6 */
if(!s->budget--) { s->failed_pc=0x0c081cc6u; return 0; }
r[2]=0x00000000u;
goto P_0c081cc8;
P_0c081cc8: /* original 273b, guest PC 0x0c081cc8 */
if(!s->budget--) { s->failed_pc=0x0c081cc8u; return 0; }
r[7]|=r[3];
goto P_0c081cca;
P_0c081cca: /* original 1f71, guest PC 0x0c081cca */
if(!s->budget--) { s->failed_pc=0x0c081ccau; return 0; }
write(ram,r[15]+4,r[7],4);
goto P_0c081ccc;
P_0c081ccc: /* original 2f26, guest PC 0x0c081ccc */
if(!s->budget--) { s->failed_pc=0x0c081cccu; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c081cce;
P_0c081cce: /* original 55f1, guest PC 0x0c081cce */
if(!s->budget--) { s->failed_pc=0x0c081cceu; return 0; }
r[5]=read(ram,r[15]+4,4);
goto P_0c081cd0;
P_0c081cd0: /* original d113, guest PC 0x0c081cd0 */
if(!s->budget--) { s->failed_pc=0x0c081cd0u; return 0; }
r[1]=read(ram,0x0c081d20u,4);
goto P_0c081cd2;
P_0c081cd2: /* original 57f2, guest PC 0x0c081cd2 */
if(!s->budget--) { s->failed_pc=0x0c081cd2u; return 0; }
r[7]=read(ram,r[15]+8,4);
goto P_0c081cd4;
P_0c081cd4: /* original 56f3, guest PC 0x0c081cd4 */
if(!s->budget--) { s->failed_pc=0x0c081cd4u; return 0; }
r[6]=read(ram,r[15]+12,4);
goto P_0c081cd6;
P_0c081cd6: /* original 410b, guest PC 0x0c081cd6 */
if(!s->budget--) { s->failed_pc=0x0c081cd6u; return 0; }
target=r[1];
r[16]=0x0c081cdau;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c081cdau) { target=s->pc; goto dispatch; }
goto P_0c081cda;
P_0c081cd8: /* original 64e3, guest PC 0x0c081cd8 */
if(!s->budget--) { s->failed_pc=0x0c081cd8u; return 0; }
r[4]=r[14];
goto P_0c081cda;
P_0c081cda: /* original 7e04, guest PC 0x0c081cda */
if(!s->budget--) { s->failed_pc=0x0c081cdau; return 0; }
r[14]+=0x00000004u;
goto P_0c081cdc;
P_0c081cdc: /* original 7f04, guest PC 0x0c081cdc */
if(!s->budget--) { s->failed_pc=0x0c081cdcu; return 0; }
r[15]+=0x00000004u;
goto P_0c081cde;
P_0c081cde: /* original 7f0c, guest PC 0x0c081cde */
if(!s->budget--) { s->failed_pc=0x0c081cdeu; return 0; }
r[15]+=0x0000000cu;
goto P_0c081ce0;
P_0c081ce0: /* original 60e3, guest PC 0x0c081ce0 */
if(!s->budget--) { s->failed_pc=0x0c081ce0u; return 0; }
r[0]=r[14];
goto P_0c081ce2;
P_0c081ce2: /* original 4f26, guest PC 0x0c081ce2 */
if(!s->budget--) { s->failed_pc=0x0c081ce2u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c081ce4;
P_0c081ce4: /* original 000b, guest PC 0x0c081ce4 */
if(!s->budget--) { s->failed_pc=0x0c081ce4u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c081ce6: /* original 6ef6, guest PC 0x0c081ce6 */
if(!s->budget--) { s->failed_pc=0x0c081ce6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c081ce8u,s,ram);
P_0c083c86: /* original 4f22, guest PC 0x0c083c86 */
if(!s->budget--) { s->failed_pc=0x0c083c86u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c083c88;
P_0c083c88: /* original 7ff4, guest PC 0x0c083c88 */
if(!s->budget--) { s->failed_pc=0x0c083c88u; return 0; }
r[15]+=0xfffffff4u;
goto P_0c083c8a;
P_0c083c8a: /* original 2f42, guest PC 0x0c083c8a */
if(!s->budget--) { s->failed_pc=0x0c083c8au; return 0; }
write(ram,r[15],r[4],4);
goto P_0c083c8c;
P_0c083c8c: /* original d348, guest PC 0x0c083c8c */
if(!s->budget--) { s->failed_pc=0x0c083c8cu; return 0; }
r[3]=read(ram,0x0c083db0u,4);
goto P_0c083c8e;
P_0c083c8e: /* original 1f31, guest PC 0x0c083c8e */
if(!s->budget--) { s->failed_pc=0x0c083c8eu; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c083c90;
P_0c083c90: /* original de48, guest PC 0x0c083c90 */
if(!s->budget--) { s->failed_pc=0x0c083c90u; return 0; }
r[14]=read(ram,0x0c083db4u,4);
goto P_0c083c92;
P_0c083c92: /* original 1fe2, guest PC 0x0c083c92 */
if(!s->budget--) { s->failed_pc=0x0c083c92u; return 0; }
write(ram,r[15]+8,r[14],4);
goto P_0c083c94;
P_0c083c94: /* original d348, guest PC 0x0c083c94 */
if(!s->budget--) { s->failed_pc=0x0c083c94u; return 0; }
r[3]=read(ram,0x0c083db8u,4);
goto P_0c083c96;
P_0c083c96: /* original 430b, guest PC 0x0c083c96 */
if(!s->budget--) { s->failed_pc=0x0c083c96u; return 0; }
target=r[3];
r[16]=0x0c083c9au;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c083c9au) { target=s->pc; goto dispatch; }
goto P_0c083c9a;
P_0c083c98: /* original 64e3, guest PC 0x0c083c98 */
if(!s->budget--) { s->failed_pc=0x0c083c98u; return 0; }
r[4]=r[14];
goto P_0c083c9a;
P_0c083c9a: /* original d348, guest PC 0x0c083c9a */
if(!s->budget--) { s->failed_pc=0x0c083c9au; return 0; }
r[3]=read(ram,0x0c083dbcu,4);
goto P_0c083c9c;
P_0c083c9c: /* original 9584, guest PC 0x0c083c9c */
if(!s->budget--) { s->failed_pc=0x0c083c9cu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c083da8u,2);
goto P_0c083c9e;
P_0c083c9e: /* original 430b, guest PC 0x0c083c9e */
if(!s->budget--) { s->failed_pc=0x0c083c9eu; return 0; }
target=r[3];
r[16]=0x0c083ca2u;
r[4]=read(ram,r[15]+8,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c083ca2u) { target=s->pc; goto dispatch; }
goto P_0c083ca2;
P_0c083ca0: /* original 54f2, guest PC 0x0c083ca0 */
if(!s->budget--) { s->failed_pc=0x0c083ca0u; return 0; }
r[4]=read(ram,r[15]+8,4);
goto P_0c083ca2;
P_0c083ca2: /* original 9e82, guest PC 0x0c083ca2 */
if(!s->budget--) { s->failed_pc=0x0c083ca2u; return 0; }
r[14]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c083daau,2);
goto P_0c083ca4;
P_0c083ca4: /* original 52f1, guest PC 0x0c083ca4 */
if(!s->budget--) { s->failed_pc=0x0c083ca4u; return 0; }
r[2]=read(ram,r[15]+4,4);
goto P_0c083ca6;
P_0c083ca6: /* original 60e3, guest PC 0x0c083ca6 */
if(!s->budget--) { s->failed_pc=0x0c083ca6u; return 0; }
r[0]=r[14];
goto P_0c083ca8;
P_0c083ca8: /* original 70e0, guest PC 0x0c083ca8 */
if(!s->budget--) { s->failed_pc=0x0c083ca8u; return 0; }
r[0]+=0xffffffe0u;
goto P_0c083caa;
P_0c083caa: /* original 032e, guest PC 0x0c083caa */
if(!s->budget--) { s->failed_pc=0x0c083caau; return 0; }
r[3]=read(ram,r[2]+r[0],4);
goto P_0c083cac;
P_0c083cac: /* original d044, guest PC 0x0c083cac */
if(!s->budget--) { s->failed_pc=0x0c083cacu; return 0; }
r[0]=read(ram,0x0c083dc0u,4);
goto P_0c083cae;
P_0c083cae: /* original 4308, guest PC 0x0c083cae */
if(!s->budget--) { s->failed_pc=0x0c083caeu; return 0; }
r[3]<<=2;
goto P_0c083cb0;
P_0c083cb0: /* original 023e, guest PC 0x0c083cb0 */
if(!s->budget--) { s->failed_pc=0x0c083cb0u; return 0; }
r[2]=read(ram,r[3]+r[0],4);
goto P_0c083cb2;
P_0c083cb2: /* original 2f26, guest PC 0x0c083cb2 */
if(!s->budget--) { s->failed_pc=0x0c083cb2u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c083cb4;
P_0c083cb4: /* original d143, guest PC 0x0c083cb4 */
if(!s->budget--) { s->failed_pc=0x0c083cb4u; return 0; }
r[1]=read(ram,0x0c083dc4u,4);
goto P_0c083cb6;
P_0c083cb6: /* original 2f16, guest PC 0x0c083cb6 */
if(!s->budget--) { s->failed_pc=0x0c083cb6u; return 0; }
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c083cb8;
P_0c083cb8: /* original d343, guest PC 0x0c083cb8 */
if(!s->budget--) { s->failed_pc=0x0c083cb8u; return 0; }
r[3]=read(ram,0x0c083dc8u,4);
goto P_0c083cba;
P_0c083cba: /* original 430b, guest PC 0x0c083cba */
if(!s->budget--) { s->failed_pc=0x0c083cbau; return 0; }
target=r[3];
r[16]=0x0c083cbeu;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c083cbeu) { target=s->pc; goto dispatch; }
goto P_0c083cbe;
P_0c083cbc: /* original 64e3, guest PC 0x0c083cbc */
if(!s->budget--) { s->failed_pc=0x0c083cbcu; return 0; }
r[4]=r[14];
goto P_0c083cbe;
P_0c083cbe: /* original 54f2, guest PC 0x0c083cbe */
if(!s->budget--) { s->failed_pc=0x0c083cbeu; return 0; }
r[4]=read(ram,r[15]+8,4);
goto P_0c083cc0;
P_0c083cc0: /* original 7f14, guest PC 0x0c083cc0 */
if(!s->budget--) { s->failed_pc=0x0c083cc0u; return 0; }
r[15]+=0x00000014u;
goto P_0c083cc2;
P_0c083cc2: /* original 4f26, guest PC 0x0c083cc2 */
if(!s->budget--) { s->failed_pc=0x0c083cc2u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c083cc4;
P_0c083cc4: /* original d341, guest PC 0x0c083cc4 */
if(!s->budget--) { s->failed_pc=0x0c083cc4u; return 0; }
r[3]=read(ram,0x0c083dccu,4);
goto P_0c083cc6;
P_0c083cc6: /* original 65e3, guest PC 0x0c083cc6 */
if(!s->budget--) { s->failed_pc=0x0c083cc6u; return 0; }
r[5]=r[14];
goto P_0c083cc8;
P_0c083cc8: /* original 432b, guest PC 0x0c083cc8 */
if(!s->budget--) { s->failed_pc=0x0c083cc8u; return 0; }
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
P_0c083cca: /* original 6ef6, guest PC 0x0c083cca */
if(!s->budget--) { s->failed_pc=0x0c083ccau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c083cccu,s,ram);
P_0c083cce: /* original 4f22, guest PC 0x0c083cce */
if(!s->budget--) { s->failed_pc=0x0c083cceu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c083cd0;
P_0c083cd0: /* original 7ff4, guest PC 0x0c083cd0 */
if(!s->budget--) { s->failed_pc=0x0c083cd0u; return 0; }
r[15]+=0xfffffff4u;
goto P_0c083cd2;
P_0c083cd2: /* original 2f42, guest PC 0x0c083cd2 */
if(!s->budget--) { s->failed_pc=0x0c083cd2u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c083cd4;
P_0c083cd4: /* original d336, guest PC 0x0c083cd4 */
if(!s->budget--) { s->failed_pc=0x0c083cd4u; return 0; }
r[3]=read(ram,0x0c083db0u,4);
goto P_0c083cd6;
P_0c083cd6: /* original 1f31, guest PC 0x0c083cd6 */
if(!s->budget--) { s->failed_pc=0x0c083cd6u; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c083cd8;
P_0c083cd8: /* original de36, guest PC 0x0c083cd8 */
if(!s->budget--) { s->failed_pc=0x0c083cd8u; return 0; }
r[14]=read(ram,0x0c083db4u,4);
goto P_0c083cda;
P_0c083cda: /* original 1fe2, guest PC 0x0c083cda */
if(!s->budget--) { s->failed_pc=0x0c083cdau; return 0; }
write(ram,r[15]+8,r[14],4);
goto P_0c083cdc;
P_0c083cdc: /* original d336, guest PC 0x0c083cdc */
if(!s->budget--) { s->failed_pc=0x0c083cdcu; return 0; }
r[3]=read(ram,0x0c083db8u,4);
goto P_0c083cde;
P_0c083cde: /* original 430b, guest PC 0x0c083cde */
if(!s->budget--) { s->failed_pc=0x0c083cdeu; return 0; }
target=r[3];
r[16]=0x0c083ce2u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c083ce2u) { target=s->pc; goto dispatch; }
goto P_0c083ce2;
P_0c083ce0: /* original 64e3, guest PC 0x0c083ce0 */
if(!s->budget--) { s->failed_pc=0x0c083ce0u; return 0; }
r[4]=r[14];
goto P_0c083ce2;
P_0c083ce2: /* original d336, guest PC 0x0c083ce2 */
if(!s->budget--) { s->failed_pc=0x0c083ce2u; return 0; }
r[3]=read(ram,0x0c083dbcu,4);
goto P_0c083ce4;
P_0c083ce4: /* original 9560, guest PC 0x0c083ce4 */
if(!s->budget--) { s->failed_pc=0x0c083ce4u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c083da8u,2);
goto P_0c083ce6;
P_0c083ce6: /* original 430b, guest PC 0x0c083ce6 */
if(!s->budget--) { s->failed_pc=0x0c083ce6u; return 0; }
target=r[3];
r[16]=0x0c083ceau;
r[4]=read(ram,r[15]+8,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c083ceau) { target=s->pc; goto dispatch; }
goto P_0c083cea;
P_0c083ce8: /* original 54f2, guest PC 0x0c083ce8 */
if(!s->budget--) { s->failed_pc=0x0c083ce8u; return 0; }
r[4]=read(ram,r[15]+8,4);
goto P_0c083cea;
P_0c083cea: /* original 9e5e, guest PC 0x0c083cea */
if(!s->budget--) { s->failed_pc=0x0c083ceau; return 0; }
r[14]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c083daau,2);
goto P_0c083cec;
P_0c083cec: /* original 52f1, guest PC 0x0c083cec */
if(!s->budget--) { s->failed_pc=0x0c083cecu; return 0; }
r[2]=read(ram,r[15]+4,4);
goto P_0c083cee;
P_0c083cee: /* original 60e3, guest PC 0x0c083cee */
if(!s->budget--) { s->failed_pc=0x0c083ceeu; return 0; }
r[0]=r[14];
goto P_0c083cf0;
P_0c083cf0: /* original 70e0, guest PC 0x0c083cf0 */
if(!s->budget--) { s->failed_pc=0x0c083cf0u; return 0; }
r[0]+=0xffffffe0u;
goto P_0c083cf2;
P_0c083cf2: /* original 032e, guest PC 0x0c083cf2 */
if(!s->budget--) { s->failed_pc=0x0c083cf2u; return 0; }
r[3]=read(ram,r[2]+r[0],4);
goto P_0c083cf4;
P_0c083cf4: /* original d032, guest PC 0x0c083cf4 */
if(!s->budget--) { s->failed_pc=0x0c083cf4u; return 0; }
r[0]=read(ram,0x0c083dc0u,4);
goto P_0c083cf6;
P_0c083cf6: /* original 4308, guest PC 0x0c083cf6 */
if(!s->budget--) { s->failed_pc=0x0c083cf6u; return 0; }
r[3]<<=2;
goto P_0c083cf8;
P_0c083cf8: /* original 023e, guest PC 0x0c083cf8 */
if(!s->budget--) { s->failed_pc=0x0c083cf8u; return 0; }
r[2]=read(ram,r[3]+r[0],4);
goto P_0c083cfa;
P_0c083cfa: /* original 2f26, guest PC 0x0c083cfa */
if(!s->budget--) { s->failed_pc=0x0c083cfau; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c083cfc;
P_0c083cfc: /* original d131, guest PC 0x0c083cfc */
if(!s->budget--) { s->failed_pc=0x0c083cfcu; return 0; }
r[1]=read(ram,0x0c083dc4u,4);
goto P_0c083cfe;
P_0c083cfe: /* original 2f16, guest PC 0x0c083cfe */
if(!s->budget--) { s->failed_pc=0x0c083cfeu; return 0; }
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c083d00;
P_0c083d00: /* original d331, guest PC 0x0c083d00 */
if(!s->budget--) { s->failed_pc=0x0c083d00u; return 0; }
r[3]=read(ram,0x0c083dc8u,4);
goto P_0c083d02;
P_0c083d02: /* original 430b, guest PC 0x0c083d02 */
if(!s->budget--) { s->failed_pc=0x0c083d02u; return 0; }
target=r[3];
r[16]=0x0c083d06u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c083d06u) { target=s->pc; goto dispatch; }
goto P_0c083d06;
P_0c083d04: /* original 64e3, guest PC 0x0c083d04 */
if(!s->budget--) { s->failed_pc=0x0c083d04u; return 0; }
r[4]=r[14];
goto P_0c083d06;
P_0c083d06: /* original 54f2, guest PC 0x0c083d06 */
if(!s->budget--) { s->failed_pc=0x0c083d06u; return 0; }
r[4]=read(ram,r[15]+8,4);
goto P_0c083d08;
P_0c083d08: /* original 7f14, guest PC 0x0c083d08 */
if(!s->budget--) { s->failed_pc=0x0c083d08u; return 0; }
r[15]+=0x00000014u;
goto P_0c083d0a;
P_0c083d0a: /* original 4f26, guest PC 0x0c083d0a */
if(!s->budget--) { s->failed_pc=0x0c083d0au; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c083d0c;
P_0c083d0c: /* original d32f, guest PC 0x0c083d0c */
if(!s->budget--) { s->failed_pc=0x0c083d0cu; return 0; }
r[3]=read(ram,0x0c083dccu,4);
goto P_0c083d0e;
P_0c083d0e: /* original 65e3, guest PC 0x0c083d0e */
if(!s->budget--) { s->failed_pc=0x0c083d0eu; return 0; }
r[5]=r[14];
goto P_0c083d10;
P_0c083d10: /* original 432b, guest PC 0x0c083d10 */
if(!s->budget--) { s->failed_pc=0x0c083d10u; return 0; }
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
P_0c083d12: /* original 6ef6, guest PC 0x0c083d12 */
if(!s->budget--) { s->failed_pc=0x0c083d12u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c083d14u,s,ram);
P_0c085cdc: /* original 2fe6, guest PC 0x0c085cdc */
if(!s->budget--) { s->failed_pc=0x0c085cdcu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c085cde;
P_0c085cde: /* original e014, guest PC 0x0c085cde */
if(!s->budget--) { s->failed_pc=0x0c085cdeu; return 0; }
r[0]=0x00000014u;
goto P_0c085ce0;
P_0c085ce0: /* original 2fd6, guest PC 0x0c085ce0 */
if(!s->budget--) { s->failed_pc=0x0c085ce0u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c085ce2;
P_0c085ce2: /* original 6e53, guest PC 0x0c085ce2 */
if(!s->budget--) { s->failed_pc=0x0c085ce2u; return 0; }
r[14]=r[5];
goto P_0c085ce4;
P_0c085ce4: /* original 2fc6, guest PC 0x0c085ce4 */
if(!s->budget--) { s->failed_pc=0x0c085ce4u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c085ce6;
P_0c085ce6: /* original 2fb6, guest PC 0x0c085ce6 */
if(!s->budget--) { s->failed_pc=0x0c085ce6u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c085ce8;
P_0c085ce8: /* original 2fa6, guest PC 0x0c085ce8 */
if(!s->budget--) { s->failed_pc=0x0c085ce8u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c085cea;
P_0c085cea: /* original 2f96, guest PC 0x0c085cea */
if(!s->budget--) { s->failed_pc=0x0c085ceau; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c085cec;
P_0c085cec: /* original 2f86, guest PC 0x0c085cec */
if(!s->budget--) { s->failed_pc=0x0c085cecu; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c085cee;
P_0c085cee: /* original fffb, guest PC 0x0c085cee */
if(!s->budget--) { s->failed_pc=0x0c085ceeu; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c085cf0;
P_0c085cf0: /* original ffeb, guest PC 0x0c085cf0 */
if(!s->budget--) { s->failed_pc=0x0c085cf0u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,14,r[15]);
goto P_0c085cf2;
P_0c085cf2: /* original ffdb, guest PC 0x0c085cf2 */
if(!s->budget--) { s->failed_pc=0x0c085cf2u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,13,r[15]);
goto P_0c085cf4;
P_0c085cf4: /* original ffcb, guest PC 0x0c085cf4 */
if(!s->budget--) { s->failed_pc=0x0c085cf4u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,12,r[15]);
goto P_0c085cf6;
P_0c085cf6: /* original 4f22, guest PC 0x0c085cf6 */
if(!s->budget--) { s->failed_pc=0x0c085cf6u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c085cf8;
P_0c085cf8: /* original 7fd8, guest PC 0x0c085cf8 */
if(!s->budget--) { s->failed_pc=0x0c085cf8u; return 0; }
r[15]+=0xffffffd8u;
goto P_0c085cfa;
P_0c085cfa: /* original 1f42, guest PC 0x0c085cfa */
if(!s->budget--) { s->failed_pc=0x0c085cfau; return 0; }
write(ram,r[15]+8,r[4],4);
goto P_0c085cfc;
P_0c085cfc: /* original 1f63, guest PC 0x0c085cfc */
if(!s->budget--) { s->failed_pc=0x0c085cfcu; return 0; }
write(ram,r[15]+12,r[6],4);
goto P_0c085cfe;
P_0c085cfe: /* original fc4c, guest PC 0x0c085cfe */
if(!s->budget--) { s->failed_pc=0x0c085cfeu; return 0; }
vf3_matrix_move(s,12,4);
goto P_0c085d00;
P_0c085d00: /* original ff57, guest PC 0x0c085d00 */
if(!s->budget--) { s->failed_pc=0x0c085d00u; return 0; }
vf3_matrix_store(s,ram,5,r[15]+r[0]);
goto P_0c085d02;
P_0c085d02: /* original e004, guest PC 0x0c085d02 */
if(!s->budget--) { s->failed_pc=0x0c085d02u; return 0; }
r[0]=0x00000004u;
goto P_0c085d04;
P_0c085d04: /* original ff67, guest PC 0x0c085d04 */
if(!s->budget--) { s->failed_pc=0x0c085d04u; return 0; }
vf3_matrix_store(s,ram,6,r[15]+r[0]);
goto P_0c085d06;
P_0c085d06: /* original c719, guest PC 0x0c085d06 */
if(!s->budget--) { s->failed_pc=0x0c085d06u; return 0; }
r[0]=0x0c085d6cu;
goto P_0c085d08;
P_0c085d08: /* original f308, guest PC 0x0c085d08 */
if(!s->budget--) { s->failed_pc=0x0c085d08u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c085d0a;
P_0c085d0a: /* original e010, guest PC 0x0c085d0a */
if(!s->budget--) { s->failed_pc=0x0c085d0au; return 0; }
r[0]=0x00000010u;
goto P_0c085d0c;
P_0c085d0c: /* original ff37, guest PC 0x0c085d0c */
if(!s->budget--) { s->failed_pc=0x0c085d0cu; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c085d0e;
P_0c085d0e: /* original e004, guest PC 0x0c085d0e */
if(!s->budget--) { s->failed_pc=0x0c085d0eu; return 0; }
r[0]=0x00000004u;
goto P_0c085d10;
P_0c085d10: /* original 59f3, guest PC 0x0c085d10 */
if(!s->budget--) { s->failed_pc=0x0c085d10u; return 0; }
r[9]=read(ram,r[15]+12,4);
goto P_0c085d12;
P_0c085d12: /* original 6991, guest PC 0x0c085d12 */
if(!s->budget--) { s->failed_pc=0x0c085d12u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[9],2);
r[9]=tmp;
goto P_0c085d14;
P_0c085d14: /* original 1f96, guest PC 0x0c085d14 */
if(!s->budget--) { s->failed_pc=0x0c085d14u; return 0; }
write(ram,r[15]+24,r[9],4);
goto P_0c085d16;
P_0c085d16: /* original d816, guest PC 0x0c085d16 */
if(!s->budget--) { s->failed_pc=0x0c085d16u; return 0; }
r[8]=read(ram,0x0c085d70u,4);
goto P_0c085d18;
P_0c085d18: /* original f5f6, guest PC 0x0c085d18 */
if(!s->budget--) { s->failed_pc=0x0c085d18u; return 0; }
vf3_matrix_load(s,ram,5,r[15]+r[0]);
goto P_0c085d1a;
P_0c085d1a: /* original f4cc, guest PC 0x0c085d1a */
if(!s->budget--) { s->failed_pc=0x0c085d1au; return 0; }
vf3_matrix_move(s,4,12);
goto P_0c085d1c;
P_0c085d1c: /* original 65f3, guest PC 0x0c085d1c */
if(!s->budget--) { s->failed_pc=0x0c085d1cu; return 0; }
r[5]=r[15];
goto P_0c085d1e;
P_0c085d1e: /* original 751c, guest PC 0x0c085d1e */
if(!s->budget--) { s->failed_pc=0x0c085d1eu; return 0; }
r[5]+=0x0000001cu;
goto P_0c085d20;
P_0c085d20: /* original 480b, guest PC 0x0c085d20 */
if(!s->budget--) { s->failed_pc=0x0c085d20u; return 0; }
target=r[8];
r[16]=0x0c085d24u;
r[4]=r[15];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c085d24u) { target=s->pc; goto dispatch; }
goto P_0c085d24;
P_0c085d22: /* original 64f3, guest PC 0x0c085d22 */
if(!s->budget--) { s->failed_pc=0x0c085d22u; return 0; }
r[4]=r[15];
goto P_0c085d24;
P_0c085d24: /* original e014, guest PC 0x0c085d24 */
if(!s->budget--) { s->failed_pc=0x0c085d24u; return 0; }
r[0]=0x00000014u;
goto P_0c085d26;
P_0c085d26: /* original f2f8, guest PC 0x0c085d26 */
if(!s->budget--) { s->failed_pc=0x0c085d26u; return 0; }
vf3_matrix_load(s,ram,2,r[15]);
goto P_0c085d28;
P_0c085d28: /* original f3f6, guest PC 0x0c085d28 */
if(!s->budget--) { s->failed_pc=0x0c085d28u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c085d2a;
P_0c085d2a: /* original f325, guest PC 0x0c085d2a */
if(!s->budget--) { s->failed_pc=0x0c085d2au; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[2]))!=0);
goto P_0c085d2c;
P_0c085d2c: /* original 8f02, guest PC 0x0c085d2c */
if(!s->budget--) { s->failed_pc=0x0c085d2cu; return 0; }
cond=r[17]&1u;
r[12]=0x00000001u;
if(!cond) { goto P_0c085d34; }
goto P_0c085d30;
P_0c085d2e: /* original ec01, guest PC 0x0c085d2e */
if(!s->budget--) { s->failed_pc=0x0c085d2eu; return 0; }
r[12]=0x00000001u;
goto P_0c085d30;
P_0c085d30: /* original a06f, guest PC 0x0c085d30 */
if(!s->budget--) { s->failed_pc=0x0c085d30u; return 0; }
r[9]|=r[12];
goto P_0c085e12;
P_0c085d32: /* original 29cb, guest PC 0x0c085d32 */
if(!s->budget--) { s->failed_pc=0x0c085d32u; return 0; }
r[9]|=r[12];
goto P_0c085d34;
P_0c085d34: /* original 53f6, guest PC 0x0c085d34 */
if(!s->budget--) { s->failed_pc=0x0c085d34u; return 0; }
r[3]=read(ram,r[15]+24,4);
goto P_0c085d36;
P_0c085d36: /* original e2fe, guest PC 0x0c085d36 */
if(!s->budget--) { s->failed_pc=0x0c085d36u; return 0; }
r[2]=0xfffffffeu;
goto P_0c085d38;
P_0c085d38: /* original 23c8, guest PC 0x0c085d38 */
if(!s->budget--) { s->failed_pc=0x0c085d38u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[12])==0)!=0);
goto P_0c085d3a;
P_0c085d3a: /* original 8d6a, guest PC 0x0c085d3a */
if(!s->budget--) { s->failed_pc=0x0c085d3au; return 0; }
cond=r[17]&1u;
r[9]&=r[2];
if(cond) { goto P_0c085e12; }
goto P_0c085d3e;
P_0c085d3c: /* original 2929, guest PC 0x0c085d3c */
if(!s->budget--) { s->failed_pc=0x0c085d3cu; return 0; }
r[9]&=r[2];
goto P_0c085d3e;
P_0c085d3e: /* original c70d, guest PC 0x0c085d3e */
if(!s->budget--) { s->failed_pc=0x0c085d3eu; return 0; }
r[0]=0x0c085d74u;
goto P_0c085d40;
P_0c085d40: /* original fe08, guest PC 0x0c085d40 */
if(!s->budget--) { s->failed_pc=0x0c085d40u; return 0; }
vf3_matrix_load(s,ram,14,r[0]);
goto P_0c085d42;
P_0c085d42: /* original ea07, guest PC 0x0c085d42 */
if(!s->budget--) { s->failed_pc=0x0c085d42u; return 0; }
r[10]=0x00000007u;
goto P_0c085d44;
P_0c085d44: /* original a063, guest PC 0x0c085d44 */
if(!s->budget--) { s->failed_pc=0x0c085d44u; return 0; }
r[13]=0x0000001fu;
goto P_0c085e0e;
P_0c085d46: /* original ed1f, guest PC 0x0c085d46 */
if(!s->budget--) { s->failed_pc=0x0c085d46u; return 0; }
r[13]=0x0000001fu;
goto P_0c085d48;
P_0c085d48: /* original d20b, guest PC 0x0c085d48 */
if(!s->budget--) { s->failed_pc=0x0c085d48u; return 0; }
r[2]=read(ram,0x0c085d78u,4);
goto P_0c085d4a;
P_0c085d4a: /* original 6322, guest PC 0x0c085d4a */
if(!s->budget--) { s->failed_pc=0x0c085d4au; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c085d4c;
P_0c085d4c: /* original 3e32, guest PC 0x0c085d4c */
if(!s->budget--) { s->failed_pc=0x0c085d4cu; return 0; }
r[17]=(r[17]&~1u)|((r[14]>=r[3])!=0);
goto P_0c085d4e;
P_0c085d4e: /* original 8960, guest PC 0x0c085d4e */
if(!s->budget--) { s->failed_pc=0x0c085d4eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c085e12; }
goto P_0c085d50;
P_0c085d50: /* original 54e4, guest PC 0x0c085d50 */
if(!s->budget--) { s->failed_pc=0x0c085d50u; return 0; }
r[4]=read(ram,r[14]+16,4);
goto P_0c085d52;
P_0c085d52: /* original 2448, guest PC 0x0c085d52 */
if(!s->budget--) { s->failed_pc=0x0c085d52u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c085d54;
P_0c085d54: /* original 8b01, guest PC 0x0c085d54 */
if(!s->budget--) { s->failed_pc=0x0c085d54u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c085d5a; }
goto P_0c085d56;
P_0c085d56: /* original a011, guest PC 0x0c085d56 */
if(!s->budget--) { s->failed_pc=0x0c085d56u; return 0; }
write(ram,r[14]+16,r[12],4);
goto P_0c085d7c;
P_0c085d58: /* original 1ec4, guest PC 0x0c085d58 */
if(!s->budget--) { s->failed_pc=0x0c085d58u; return 0; }
write(ram,r[14]+16,r[12],4);
goto P_0c085d5a;
P_0c085d5a: /* original aff5, guest PC 0x0c085d5a */
if(!s->budget--) { s->failed_pc=0x0c085d5au; return 0; }
r[14]+=0x00000014u;
goto P_0c085d48;
P_0c085d5c: /* original 7e14, guest PC 0x0c085d5c */
if(!s->budget--) { s->failed_pc=0x0c085d5cu; return 0; }
r[14]+=0x00000014u;
return vf3_matrix_family(0x0c085d5eu,s,ram);
P_0c085d7c: /* original bf9a, guest PC 0x0c085d7c */
if(!s->budget--) { s->failed_pc=0x0c085d7cu; return 0; }
target=0x0c085cb4u; r[16]=0x0c085d80u;
r[4]=read(ram,r[15]+8,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c085d80u) { target=s->pc; goto dispatch; }
goto P_0c085d80;
P_0c085d7e: /* original 54f2, guest PC 0x0c085d7e */
if(!s->budget--) { s->failed_pc=0x0c085d7eu; return 0; }
r[4]=read(ram,r[15]+8,4);
goto P_0c085d80;
P_0c085d80: /* original 6503, guest PC 0x0c085d80 */
if(!s->budget--) { s->failed_pc=0x0c085d80u; return 0; }
r[5]=r[0];
goto P_0c085d82;
P_0c085d82: /* original 25d9, guest PC 0x0c085d82 */
if(!s->budget--) { s->failed_pc=0x0c085d82u; return 0; }
r[5]&=r[13];
goto P_0c085d84;
P_0c085d84: /* original 75f1, guest PC 0x0c085d84 */
if(!s->budget--) { s->failed_pc=0x0c085d84u; return 0; }
r[5]+=0xfffffff1u;
goto P_0c085d86;
P_0c085d86: /* original 6303, guest PC 0x0c085d86 */
if(!s->budget--) { s->failed_pc=0x0c085d86u; return 0; }
r[3]=r[0];
goto P_0c085d88;
P_0c085d88: /* original 455a, guest PC 0x0c085d88 */
if(!s->budget--) { s->failed_pc=0x0c085d88u; return 0; }
r[53]=r[5];
goto P_0c085d8a;
P_0c085d8a: /* original 6503, guest PC 0x0c085d8a */
if(!s->budget--) { s->failed_pc=0x0c085d8au; return 0; }
r[5]=r[0];
goto P_0c085d8c;
P_0c085d8c: /* original 4528, guest PC 0x0c085d8c */
if(!s->budget--) { s->failed_pc=0x0c085d8cu; return 0; }
r[5]<<=16;
goto P_0c085d8e;
P_0c085d8e: /* original 6403, guest PC 0x0c085d8e */
if(!s->budget--) { s->failed_pc=0x0c085d8eu; return 0; }
r[4]=r[0];
goto P_0c085d90;
P_0c085d90: /* original 4518, guest PC 0x0c085d90 */
if(!s->budget--) { s->failed_pc=0x0c085d90u; return 0; }
r[5]<<=8;
goto P_0c085d92;
P_0c085d92: /* original ffcc, guest PC 0x0c085d92 */
if(!s->budget--) { s->failed_pc=0x0c085d92u; return 0; }
vf3_matrix_move(s,15,12);
goto P_0c085d94;
P_0c085d94: /* original e2fa, guest PC 0x0c085d94 */
if(!s->budget--) { s->failed_pc=0x0c085d94u; return 0; }
r[2]=0xfffffffau;
goto P_0c085d96;
P_0c085d96: /* original f32d, guest PC 0x0c085d96 */
if(!s->budget--) { s->failed_pc=0x0c085d96u; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c085d98;
P_0c085d98: /* original 4508, guest PC 0x0c085d98 */
if(!s->budget--) { s->failed_pc=0x0c085d98u; return 0; }
r[5]<<=2;
goto P_0c085d9a;
P_0c085d9a: /* original f0ec, guest PC 0x0c085d9a */
if(!s->budget--) { s->failed_pc=0x0c085d9au; return 0; }
vf3_matrix_move(s,0,14);
goto P_0c085d9c;
P_0c085d9c: /* original 432c, guest PC 0x0c085d9c */
if(!s->budget--) { s->failed_pc=0x0c085d9cu; return 0; }
r[3]=(r[2]&0x80000000u)?((r[2]&31u)?(uint32_t)((int32_t)r[3]>>((-r[2])&31u)):((int32_t)r[3]<0?0xffffffffu:0)):r[3]<<(r[2]&31u);
goto P_0c085d9e;
P_0c085d9e: /* original 6243, guest PC 0x0c085d9e */
if(!s->budget--) { s->failed_pc=0x0c085d9eu; return 0; }
r[2]=r[4];
goto P_0c085da0;
P_0c085da0: /* original 253b, guest PC 0x0c085da0 */
if(!s->budget--) { s->failed_pc=0x0c085da0u; return 0; }
r[5]|=r[3];
goto P_0c085da2;
P_0c085da2: /* original 6343, guest PC 0x0c085da2 */
if(!s->budget--) { s->failed_pc=0x0c085da2u; return 0; }
r[3]=r[4];
goto P_0c085da4;
P_0c085da4: /* original 25d9, guest PC 0x0c085da4 */
if(!s->budget--) { s->failed_pc=0x0c085da4u; return 0; }
r[5]&=r[13];
goto P_0c085da6;
P_0c085da6: /* original 75f1, guest PC 0x0c085da6 */
if(!s->budget--) { s->failed_pc=0x0c085da6u; return 0; }
r[5]+=0xfffffff1u;
goto P_0c085da8;
P_0c085da8: /* original f43c, guest PC 0x0c085da8 */
if(!s->budget--) { s->failed_pc=0x0c085da8u; return 0; }
vf3_matrix_move(s,4,3);
goto P_0c085daa;
P_0c085daa: /* original 455a, guest PC 0x0c085daa */
if(!s->budget--) { s->failed_pc=0x0c085daau; return 0; }
r[53]=r[5];
goto P_0c085dac;
P_0c085dac: /* original e004, guest PC 0x0c085dac */
if(!s->budget--) { s->failed_pc=0x0c085dacu; return 0; }
r[0]=0x00000004u;
goto P_0c085dae;
P_0c085dae: /* original ff4e, guest PC 0x0c085dae */
if(!s->budget--) { s->failed_pc=0x0c085daeu; return 0; }
fr[15]=vf3_fpu_mac(fr[0],fr[4],fr[15],r[18]);
goto P_0c085db0;
P_0c085db0: /* original fdf6, guest PC 0x0c085db0 */
if(!s->budget--) { s->failed_pc=0x0c085db0u; return 0; }
vf3_matrix_load(s,ram,13,r[15]+r[0]);
goto P_0c085db2;
P_0c085db2: /* original e1f8, guest PC 0x0c085db2 */
if(!s->budget--) { s->failed_pc=0x0c085db2u; return 0; }
r[1]=0xfffffff8u;
goto P_0c085db4;
P_0c085db4: /* original f32d, guest PC 0x0c085db4 */
if(!s->budget--) { s->failed_pc=0x0c085db4u; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c085db6;
P_0c085db6: /* original 4328, guest PC 0x0c085db6 */
if(!s->budget--) { s->failed_pc=0x0c085db6u; return 0; }
r[3]<<=16;
goto P_0c085db8;
P_0c085db8: /* original 421c, guest PC 0x0c085db8 */
if(!s->budget--) { s->failed_pc=0x0c085db8u; return 0; }
r[2]=(r[1]&0x80000000u)?((r[1]&31u)?(uint32_t)((int32_t)r[2]>>((-r[1])&31u)):((int32_t)r[2]<0?0xffffffffu:0)):r[2]<<(r[1]&31u);
goto P_0c085dba;
P_0c085dba: /* original 4318, guest PC 0x0c085dba */
if(!s->budget--) { s->failed_pc=0x0c085dbau; return 0; }
r[3]<<=8;
goto P_0c085dbc;
P_0c085dbc: /* original f43c, guest PC 0x0c085dbc */
if(!s->budget--) { s->failed_pc=0x0c085dbcu; return 0; }
vf3_matrix_move(s,4,3);
goto P_0c085dbe;
P_0c085dbe: /* original fd4e, guest PC 0x0c085dbe */
if(!s->budget--) { s->failed_pc=0x0c085dbeu; return 0; }
fr[13]=vf3_fpu_mac(fr[0],fr[4],fr[13],r[18]);
goto P_0c085dc0;
P_0c085dc0: /* original 232b, guest PC 0x0c085dc0 */
if(!s->budget--) { s->failed_pc=0x0c085dc0u; return 0; }
r[3]|=r[2];
goto P_0c085dc2;
P_0c085dc2: /* original 65f3, guest PC 0x0c085dc2 */
if(!s->budget--) { s->failed_pc=0x0c085dc2u; return 0; }
r[5]=r[15];
goto P_0c085dc4;
P_0c085dc4: /* original 6433, guest PC 0x0c085dc4 */
if(!s->budget--) { s->failed_pc=0x0c085dc4u; return 0; }
r[4]=r[3];
goto P_0c085dc6;
P_0c085dc6: /* original 24d9, guest PC 0x0c085dc6 */
if(!s->budget--) { s->failed_pc=0x0c085dc6u; return 0; }
r[4]&=r[13];
goto P_0c085dc8;
P_0c085dc8: /* original 445a, guest PC 0x0c085dc8 */
if(!s->budget--) { s->failed_pc=0x0c085dc8u; return 0; }
r[53]=r[4];
goto P_0c085dca;
P_0c085dca: /* original e010, guest PC 0x0c085dca */
if(!s->budget--) { s->failed_pc=0x0c085dcau; return 0; }
r[0]=0x00000010u;
goto P_0c085dcc;
P_0c085dcc: /* original f2f6, guest PC 0x0c085dcc */
if(!s->budget--) { s->failed_pc=0x0c085dccu; return 0; }
vf3_matrix_load(s,ram,2,r[15]+r[0]);
goto P_0c085dce;
P_0c085dce: /* original c73f, guest PC 0x0c085dce */
if(!s->budget--) { s->failed_pc=0x0c085dceu; return 0; }
r[0]=0x0c085eccu;
goto P_0c085dd0;
P_0c085dd0: /* original f008, guest PC 0x0c085dd0 */
if(!s->budget--) { s->failed_pc=0x0c085dd0u; return 0; }
vf3_matrix_load(s,ram,0,r[0]);
goto P_0c085dd2;
P_0c085dd2: /* original e008, guest PC 0x0c085dd2 */
if(!s->budget--) { s->failed_pc=0x0c085dd2u; return 0; }
r[0]=0x00000008u;
goto P_0c085dd4;
P_0c085dd4: /* original f32d, guest PC 0x0c085dd4 */
if(!s->budget--) { s->failed_pc=0x0c085dd4u; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c085dd6;
P_0c085dd6: /* original 64f3, guest PC 0x0c085dd6 */
if(!s->budget--) { s->failed_pc=0x0c085dd6u; return 0; }
r[4]=r[15];
goto P_0c085dd8;
P_0c085dd8: /* original 751c, guest PC 0x0c085dd8 */
if(!s->budget--) { s->failed_pc=0x0c085dd8u; return 0; }
r[5]+=0x0000001cu;
goto P_0c085dda;
P_0c085dda: /* original f43c, guest PC 0x0c085dda */
if(!s->budget--) { s->failed_pc=0x0c085ddau; return 0; }
vf3_matrix_move(s,4,3);
goto P_0c085ddc;
P_0c085ddc: /* original f24e, guest PC 0x0c085ddc */
if(!s->budget--) { s->failed_pc=0x0c085ddcu; return 0; }
fr[2]=vf3_fpu_mac(fr[0],fr[4],fr[2],r[18]);
goto P_0c085dde;
P_0c085dde: /* original f42c, guest PC 0x0c085dde */
if(!s->budget--) { s->failed_pc=0x0c085ddeu; return 0; }
vf3_matrix_move(s,4,2);
goto P_0c085de0;
P_0c085de0: /* original fefa, guest PC 0x0c085de0 */
if(!s->budget--) { s->failed_pc=0x0c085de0u; return 0; }
vf3_matrix_store(s,ram,15,r[14]);
goto P_0c085de2;
P_0c085de2: /* original f3dc, guest PC 0x0c085de2 */
if(!s->budget--) { s->failed_pc=0x0c085de2u; return 0; }
vf3_matrix_move(s,3,13);
goto P_0c085de4;
P_0c085de4: /* original f34d, guest PC 0x0c085de4 */
if(!s->budget--) { s->failed_pc=0x0c085de4u; return 0; }
fr[3]^=0x80000000u;
goto P_0c085de6;
P_0c085de6: /* original fe37, guest PC 0x0c085de6 */
if(!s->budget--) { s->failed_pc=0x0c085de6u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c085de8;
P_0c085de8: /* original e00c, guest PC 0x0c085de8 */
if(!s->budget--) { s->failed_pc=0x0c085de8u; return 0; }
r[0]=0x0000000cu;
goto P_0c085dea;
P_0c085dea: /* original fe47, guest PC 0x0c085dea */
if(!s->budget--) { s->failed_pc=0x0c085deau; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c085dec;
P_0c085dec: /* original f5dc, guest PC 0x0c085dec */
if(!s->budget--) { s->failed_pc=0x0c085decu; return 0; }
vf3_matrix_move(s,5,13);
goto P_0c085dee;
P_0c085dee: /* original 480b, guest PC 0x0c085dee */
if(!s->budget--) { s->failed_pc=0x0c085deeu; return 0; }
target=r[8];
r[16]=0x0c085df2u;
vf3_matrix_move(s,4,15);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c085df2u) { target=s->pc; goto dispatch; }
goto P_0c085df2;
P_0c085df0: /* original f4fc, guest PC 0x0c085df0 */
if(!s->budget--) { s->failed_pc=0x0c085df0u; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c085df2;
P_0c085df2: /* original f3f8, guest PC 0x0c085df2 */
if(!s->budget--) { s->failed_pc=0x0c085df2u; return 0; }
vf3_matrix_load(s,ram,3,r[15]);
goto P_0c085df4;
P_0c085df4: /* original 6b03, guest PC 0x0c085df4 */
if(!s->budget--) { s->failed_pc=0x0c085df4u; return 0; }
r[11]=r[0];
goto P_0c085df6;
P_0c085df6: /* original e004, guest PC 0x0c085df6 */
if(!s->budget--) { s->failed_pc=0x0c085df6u; return 0; }
r[0]=0x00000004u;
goto P_0c085df8;
P_0c085df8: /* original fe37, guest PC 0x0c085df8 */
if(!s->budget--) { s->failed_pc=0x0c085df8u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c085dfa;
P_0c085dfa: /* original e3fd, guest PC 0x0c085dfa */
if(!s->budget--) { s->failed_pc=0x0c085dfau; return 0; }
r[3]=0xfffffffdu;
goto P_0c085dfc;
P_0c085dfc: /* original 9265, guest PC 0x0c085dfc */
if(!s->budget--) { s->failed_pc=0x0c085dfcu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c085ecau,2);
goto P_0c085dfe;
P_0c085dfe: /* original 54e4, guest PC 0x0c085dfe */
if(!s->budget--) { s->failed_pc=0x0c085dfeu; return 0; }
r[4]=read(ram,r[14]+16,4);
goto P_0c085e00;
P_0c085e00: /* original 22b8, guest PC 0x0c085e00 */
if(!s->budget--) { s->failed_pc=0x0c085e00u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[11])==0)!=0);
goto P_0c085e02;
P_0c085e02: /* original 8d02, guest PC 0x0c085e02 */
if(!s->budget--) { s->failed_pc=0x0c085e02u; return 0; }
cond=r[17]&1u;
r[4]&=r[3];
if(cond) { goto P_0c085e0a; }
goto P_0c085e06;
P_0c085e04: /* original 2439, guest PC 0x0c085e04 */
if(!s->budget--) { s->failed_pc=0x0c085e04u; return 0; }
r[4]&=r[3];
goto P_0c085e06;
P_0c085e06: /* original e002, guest PC 0x0c085e06 */
if(!s->budget--) { s->failed_pc=0x0c085e06u; return 0; }
r[0]=0x00000002u;
goto P_0c085e08;
P_0c085e08: /* original 240b, guest PC 0x0c085e08 */
if(!s->budget--) { s->failed_pc=0x0c085e08u; return 0; }
r[4]|=r[0];
goto P_0c085e0a;
P_0c085e0a: /* original 7aff, guest PC 0x0c085e0a */
if(!s->budget--) { s->failed_pc=0x0c085e0au; return 0; }
r[10]+=0xffffffffu;
goto P_0c085e0c;
P_0c085e0c: /* original 1e44, guest PC 0x0c085e0c */
if(!s->budget--) { s->failed_pc=0x0c085e0cu; return 0; }
write(ram,r[14]+16,r[4],4);
goto P_0c085e0e;
P_0c085e0e: /* original 4a15, guest PC 0x0c085e0e */
if(!s->budget--) { s->failed_pc=0x0c085e0eu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[10]>0)!=0);
goto P_0c085e10;
P_0c085e10: /* original 899a, guest PC 0x0c085e10 */
if(!s->budget--) { s->failed_pc=0x0c085e10u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c085d48; }
goto P_0c085e12;
P_0c085e12: /* original 52f3, guest PC 0x0c085e12 */
if(!s->budget--) { s->failed_pc=0x0c085e12u; return 0; }
r[2]=read(ram,r[15]+12,4);
goto P_0c085e14;
P_0c085e14: /* original 7f28, guest PC 0x0c085e14 */
if(!s->budget--) { s->failed_pc=0x0c085e14u; return 0; }
r[15]+=0x00000028u;
goto P_0c085e16;
P_0c085e16: /* original 4f26, guest PC 0x0c085e16 */
if(!s->budget--) { s->failed_pc=0x0c085e16u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c085e18;
P_0c085e18: /* original 2291, guest PC 0x0c085e18 */
if(!s->budget--) { s->failed_pc=0x0c085e18u; return 0; }
write(ram,r[2],r[9],2);
goto P_0c085e1a;
P_0c085e1a: /* original fcf9, guest PC 0x0c085e1a */
if(!s->budget--) { s->failed_pc=0x0c085e1au; return 0; }
vf3_matrix_load(s,ram,12,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c085e1c;
P_0c085e1c: /* original fdf9, guest PC 0x0c085e1c */
if(!s->budget--) { s->failed_pc=0x0c085e1cu; return 0; }
vf3_matrix_load(s,ram,13,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c085e1e;
P_0c085e1e: /* original fef9, guest PC 0x0c085e1e */
if(!s->budget--) { s->failed_pc=0x0c085e1eu; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c085e20;
P_0c085e20: /* original fff9, guest PC 0x0c085e20 */
if(!s->budget--) { s->failed_pc=0x0c085e20u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c085e22;
P_0c085e22: /* original 68f6, guest PC 0x0c085e22 */
if(!s->budget--) { s->failed_pc=0x0c085e22u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c085e24;
P_0c085e24: /* original 69f6, guest PC 0x0c085e24 */
if(!s->budget--) { s->failed_pc=0x0c085e24u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c085e26;
P_0c085e26: /* original 6af6, guest PC 0x0c085e26 */
if(!s->budget--) { s->failed_pc=0x0c085e26u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c085e28;
P_0c085e28: /* original 6bf6, guest PC 0x0c085e28 */
if(!s->budget--) { s->failed_pc=0x0c085e28u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c085e2a;
P_0c085e2a: /* original 6cf6, guest PC 0x0c085e2a */
if(!s->budget--) { s->failed_pc=0x0c085e2au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c085e2c;
P_0c085e2c: /* original 6df6, guest PC 0x0c085e2c */
if(!s->budget--) { s->failed_pc=0x0c085e2cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c085e2e;
P_0c085e2e: /* original 000b, guest PC 0x0c085e2e */
if(!s->budget--) { s->failed_pc=0x0c085e2eu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c085e30: /* original 6ef6, guest PC 0x0c085e30 */
if(!s->budget--) { s->failed_pc=0x0c085e30u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c085e32u,s,ram);
P_0c085f96: /* original 2fe6, guest PC 0x0c085f96 */
if(!s->budget--) { s->failed_pc=0x0c085f96u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c085f98;
P_0c085f98: /* original 6e53, guest PC 0x0c085f98 */
if(!s->budget--) { s->failed_pc=0x0c085f98u; return 0; }
r[14]=r[5];
goto P_0c085f9a;
P_0c085f9a: /* original 2fd6, guest PC 0x0c085f9a */
if(!s->budget--) { s->failed_pc=0x0c085f9au; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c085f9c;
P_0c085f9c: /* original 6d43, guest PC 0x0c085f9c */
if(!s->budget--) { s->failed_pc=0x0c085f9cu; return 0; }
r[13]=r[4];
goto P_0c085f9e;
P_0c085f9e: /* original 2fc6, guest PC 0x0c085f9e */
if(!s->budget--) { s->failed_pc=0x0c085f9eu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c085fa0;
P_0c085fa0: /* original 6c63, guest PC 0x0c085fa0 */
if(!s->budget--) { s->failed_pc=0x0c085fa0u; return 0; }
r[12]=r[6];
goto P_0c085fa2;
P_0c085fa2: /* original 2fb6, guest PC 0x0c085fa2 */
if(!s->budget--) { s->failed_pc=0x0c085fa2u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c085fa4;
P_0c085fa4: /* original 6b73, guest PC 0x0c085fa4 */
if(!s->budget--) { s->failed_pc=0x0c085fa4u; return 0; }
r[11]=r[7];
goto P_0c085fa6;
P_0c085fa6: /* original fffb, guest PC 0x0c085fa6 */
if(!s->budget--) { s->failed_pc=0x0c085fa6u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c085fa8;
P_0c085fa8: /* original 9044, guest PC 0x0c085fa8 */
if(!s->budget--) { s->failed_pc=0x0c085fa8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c086034u,2);
goto P_0c085faa;
P_0c085faa: /* original 4f22, guest PC 0x0c085faa */
if(!s->budget--) { s->failed_pc=0x0c085faau; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c085fac;
P_0c085fac: /* original f7d6, guest PC 0x0c085fac */
if(!s->budget--) { s->failed_pc=0x0c085facu; return 0; }
vf3_matrix_load(s,ram,7,r[13]+r[0]);
goto P_0c085fae;
P_0c085fae: /* original 7004, guest PC 0x0c085fae */
if(!s->budget--) { s->failed_pc=0x0c085faeu; return 0; }
r[0]+=0x00000004u;
goto P_0c085fb0;
P_0c085fb0: /* original f8d6, guest PC 0x0c085fb0 */
if(!s->budget--) { s->failed_pc=0x0c085fb0u; return 0; }
vf3_matrix_load(s,ram,8,r[13]+r[0]);
goto P_0c085fb2;
P_0c085fb2: /* original 7004, guest PC 0x0c085fb2 */
if(!s->budget--) { s->failed_pc=0x0c085fb2u; return 0; }
r[0]+=0x00000004u;
goto P_0c085fb4;
P_0c085fb4: /* original f9d6, guest PC 0x0c085fb4 */
if(!s->budget--) { s->failed_pc=0x0c085fb4u; return 0; }
vf3_matrix_load(s,ram,9,r[13]+r[0]);
goto P_0c085fb6;
P_0c085fb6: /* original c724, guest PC 0x0c085fb6 */
if(!s->budget--) { s->failed_pc=0x0c085fb6u; return 0; }
r[0]=0x0c086048u;
goto P_0c085fb8;
P_0c085fb8: /* original ff08, guest PC 0x0c085fb8 */
if(!s->budget--) { s->failed_pc=0x0c085fb8u; return 0; }
vf3_matrix_load(s,ram,15,r[0]);
goto P_0c085fba;
P_0c085fba: /* original e004, guest PC 0x0c085fba */
if(!s->budget--) { s->failed_pc=0x0c085fbau; return 0; }
r[0]=0x00000004u;
goto P_0c085fbc;
P_0c085fbc: /* original f4e6, guest PC 0x0c085fbc */
if(!s->budget--) { s->failed_pc=0x0c085fbcu; return 0; }
vf3_matrix_load(s,ram,4,r[14]+r[0]);
goto P_0c085fbe;
P_0c085fbe: /* original e008, guest PC 0x0c085fbe */
if(!s->budget--) { s->failed_pc=0x0c085fbeu; return 0; }
r[0]=0x00000008u;
goto P_0c085fc0;
P_0c085fc0: /* original f5e6, guest PC 0x0c085fc0 */
if(!s->budget--) { s->failed_pc=0x0c085fc0u; return 0; }
vf3_matrix_load(s,ram,5,r[14]+r[0]);
goto P_0c085fc2;
P_0c085fc2: /* original e00c, guest PC 0x0c085fc2 */
if(!s->budget--) { s->failed_pc=0x0c085fc2u; return 0; }
r[0]=0x0000000cu;
goto P_0c085fc4;
P_0c085fc4: /* original f6e6, guest PC 0x0c085fc4 */
if(!s->budget--) { s->failed_pc=0x0c085fc4u; return 0; }
vf3_matrix_load(s,ram,6,r[14]+r[0]);
goto P_0c085fc6;
P_0c085fc6: /* original f8f0, guest PC 0x0c085fc6 */
if(!s->budget--) { s->failed_pc=0x0c085fc6u; return 0; }
fr[8]=vf3_fpu_binary(fr[8],fr[15],r[18],'+');
goto P_0c085fc8;
P_0c085fc8: /* original e004, guest PC 0x0c085fc8 */
if(!s->budget--) { s->failed_pc=0x0c085fc8u; return 0; }
r[0]=0x00000004u;
goto P_0c085fca;
P_0c085fca: /* original f94d, guest PC 0x0c085fca */
if(!s->budget--) { s->failed_pc=0x0c085fcau; return 0; }
fr[9]^=0x80000000u;
goto P_0c085fcc;
P_0c085fcc: /* original fe77, guest PC 0x0c085fcc */
if(!s->budget--) { s->failed_pc=0x0c085fccu; return 0; }
vf3_matrix_store(s,ram,7,r[14]+r[0]);
goto P_0c085fce;
P_0c085fce: /* original e008, guest PC 0x0c085fce */
if(!s->budget--) { s->failed_pc=0x0c085fceu; return 0; }
r[0]=0x00000008u;
goto P_0c085fd0;
P_0c085fd0: /* original fe87, guest PC 0x0c085fd0 */
if(!s->budget--) { s->failed_pc=0x0c085fd0u; return 0; }
vf3_matrix_store(s,ram,8,r[14]+r[0]);
goto P_0c085fd2;
P_0c085fd2: /* original e00c, guest PC 0x0c085fd2 */
if(!s->budget--) { s->failed_pc=0x0c085fd2u; return 0; }
r[0]=0x0000000cu;
goto P_0c085fd4;
P_0c085fd4: /* original fe97, guest PC 0x0c085fd4 */
if(!s->budget--) { s->failed_pc=0x0c085fd4u; return 0; }
vf3_matrix_store(s,ram,9,r[14]+r[0]);
goto P_0c085fd6;
P_0c085fd6: /* original 65c3, guest PC 0x0c085fd6 */
if(!s->budget--) { s->failed_pc=0x0c085fd6u; return 0; }
r[5]=r[12];
goto P_0c085fd8;
P_0c085fd8: /* original bf2b, guest PC 0x0c085fd8 */
if(!s->budget--) { s->failed_pc=0x0c085fd8u; return 0; }
target=0x0c085e32u; r[16]=0x0c085fdcu;
r[4]=r[11];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c085fdcu) { target=s->pc; goto dispatch; }
goto P_0c085fdc;
P_0c085fda: /* original 64b3, guest PC 0x0c085fda */
if(!s->budget--) { s->failed_pc=0x0c085fdau; return 0; }
r[4]=r[11];
goto P_0c085fdc;
P_0c085fdc: /* original 902b, guest PC 0x0c085fdc */
if(!s->budget--) { s->failed_pc=0x0c085fdcu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c086036u,2);
goto P_0c085fde;
P_0c085fde: /* original 7e10, guest PC 0x0c085fde */
if(!s->budget--) { s->failed_pc=0x0c085fdeu; return 0; }
r[14]+=0x00000010u;
goto P_0c085fe0;
P_0c085fe0: /* original 65c3, guest PC 0x0c085fe0 */
if(!s->budget--) { s->failed_pc=0x0c085fe0u; return 0; }
r[5]=r[12];
goto P_0c085fe2;
P_0c085fe2: /* original f7d6, guest PC 0x0c085fe2 */
if(!s->budget--) { s->failed_pc=0x0c085fe2u; return 0; }
vf3_matrix_load(s,ram,7,r[13]+r[0]);
goto P_0c085fe4;
P_0c085fe4: /* original 7004, guest PC 0x0c085fe4 */
if(!s->budget--) { s->failed_pc=0x0c085fe4u; return 0; }
r[0]+=0x00000004u;
goto P_0c085fe6;
P_0c085fe6: /* original f8d6, guest PC 0x0c085fe6 */
if(!s->budget--) { s->failed_pc=0x0c085fe6u; return 0; }
vf3_matrix_load(s,ram,8,r[13]+r[0]);
goto P_0c085fe8;
P_0c085fe8: /* original 7004, guest PC 0x0c085fe8 */
if(!s->budget--) { s->failed_pc=0x0c085fe8u; return 0; }
r[0]+=0x00000004u;
goto P_0c085fea;
P_0c085fea: /* original f9d6, guest PC 0x0c085fea */
if(!s->budget--) { s->failed_pc=0x0c085feau; return 0; }
vf3_matrix_load(s,ram,9,r[13]+r[0]);
goto P_0c085fec;
P_0c085fec: /* original e004, guest PC 0x0c085fec */
if(!s->budget--) { s->failed_pc=0x0c085fecu; return 0; }
r[0]=0x00000004u;
goto P_0c085fee;
P_0c085fee: /* original f4e6, guest PC 0x0c085fee */
if(!s->budget--) { s->failed_pc=0x0c085feeu; return 0; }
vf3_matrix_load(s,ram,4,r[14]+r[0]);
goto P_0c085ff0;
P_0c085ff0: /* original e008, guest PC 0x0c085ff0 */
if(!s->budget--) { s->failed_pc=0x0c085ff0u; return 0; }
r[0]=0x00000008u;
goto P_0c085ff2;
P_0c085ff2: /* original f5e6, guest PC 0x0c085ff2 */
if(!s->budget--) { s->failed_pc=0x0c085ff2u; return 0; }
vf3_matrix_load(s,ram,5,r[14]+r[0]);
goto P_0c085ff4;
P_0c085ff4: /* original e00c, guest PC 0x0c085ff4 */
if(!s->budget--) { s->failed_pc=0x0c085ff4u; return 0; }
r[0]=0x0000000cu;
goto P_0c085ff6;
P_0c085ff6: /* original f6e6, guest PC 0x0c085ff6 */
if(!s->budget--) { s->failed_pc=0x0c085ff6u; return 0; }
vf3_matrix_load(s,ram,6,r[14]+r[0]);
goto P_0c085ff8;
P_0c085ff8: /* original f8f0, guest PC 0x0c085ff8 */
if(!s->budget--) { s->failed_pc=0x0c085ff8u; return 0; }
fr[8]=vf3_fpu_binary(fr[8],fr[15],r[18],'+');
goto P_0c085ffa;
P_0c085ffa: /* original e004, guest PC 0x0c085ffa */
if(!s->budget--) { s->failed_pc=0x0c085ffau; return 0; }
r[0]=0x00000004u;
goto P_0c085ffc;
P_0c085ffc: /* original f94d, guest PC 0x0c085ffc */
if(!s->budget--) { s->failed_pc=0x0c085ffcu; return 0; }
fr[9]^=0x80000000u;
goto P_0c085ffe;
P_0c085ffe: /* original fe77, guest PC 0x0c085ffe */
if(!s->budget--) { s->failed_pc=0x0c085ffeu; return 0; }
vf3_matrix_store(s,ram,7,r[14]+r[0]);
goto P_0c086000;
P_0c086000: /* original e008, guest PC 0x0c086000 */
if(!s->budget--) { s->failed_pc=0x0c086000u; return 0; }
r[0]=0x00000008u;
goto P_0c086002;
P_0c086002: /* original fe87, guest PC 0x0c086002 */
if(!s->budget--) { s->failed_pc=0x0c086002u; return 0; }
vf3_matrix_store(s,ram,8,r[14]+r[0]);
goto P_0c086004;
P_0c086004: /* original e00c, guest PC 0x0c086004 */
if(!s->budget--) { s->failed_pc=0x0c086004u; return 0; }
r[0]=0x0000000cu;
goto P_0c086006;
P_0c086006: /* original fe97, guest PC 0x0c086006 */
if(!s->budget--) { s->failed_pc=0x0c086006u; return 0; }
vf3_matrix_store(s,ram,9,r[14]+r[0]);
goto P_0c086008;
P_0c086008: /* original bf13, guest PC 0x0c086008 */
if(!s->budget--) { s->failed_pc=0x0c086008u; return 0; }
target=0x0c085e32u; r[16]=0x0c08600cu;
r[4]=r[11];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08600cu) { target=s->pc; goto dispatch; }
goto P_0c08600c;
P_0c08600a: /* original 64b3, guest PC 0x0c08600a */
if(!s->budget--) { s->failed_pc=0x0c08600au; return 0; }
r[4]=r[11];
goto P_0c08600c;
P_0c08600c: /* original 9014, guest PC 0x0c08600c */
if(!s->budget--) { s->failed_pc=0x0c08600cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c086038u,2);
goto P_0c08600e;
P_0c08600e: /* original 64b3, guest PC 0x0c08600e */
if(!s->budget--) { s->failed_pc=0x0c08600eu; return 0; }
r[4]=r[11];
goto P_0c086010;
P_0c086010: /* original 4f26, guest PC 0x0c086010 */
if(!s->budget--) { s->failed_pc=0x0c086010u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c086012;
P_0c086012: /* original f4d6, guest PC 0x0c086012 */
if(!s->budget--) { s->failed_pc=0x0c086012u; return 0; }
vf3_matrix_load(s,ram,4,r[13]+r[0]);
goto P_0c086014;
P_0c086014: /* original 7004, guest PC 0x0c086014 */
if(!s->budget--) { s->failed_pc=0x0c086014u; return 0; }
r[0]+=0x00000004u;
goto P_0c086016;
P_0c086016: /* original f5d6, guest PC 0x0c086016 */
if(!s->budget--) { s->failed_pc=0x0c086016u; return 0; }
vf3_matrix_load(s,ram,5,r[13]+r[0]);
goto P_0c086018;
P_0c086018: /* original 65c3, guest PC 0x0c086018 */
if(!s->budget--) { s->failed_pc=0x0c086018u; return 0; }
r[5]=r[12];
goto P_0c08601a;
P_0c08601a: /* original 7004, guest PC 0x0c08601a */
if(!s->budget--) { s->failed_pc=0x0c08601au; return 0; }
r[0]+=0x00000004u;
goto P_0c08601c;
P_0c08601c: /* original f5f0, guest PC 0x0c08601c */
if(!s->budget--) { s->failed_pc=0x0c08601cu; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[15],r[18],'+');
goto P_0c08601e;
P_0c08601e: /* original fff9, guest PC 0x0c08601e */
if(!s->budget--) { s->failed_pc=0x0c08601eu; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c086020;
P_0c086020: /* original f6d6, guest PC 0x0c086020 */
if(!s->budget--) { s->failed_pc=0x0c086020u; return 0; }
vf3_matrix_load(s,ram,6,r[13]+r[0]);
goto P_0c086022;
P_0c086022: /* original 7e10, guest PC 0x0c086022 */
if(!s->budget--) { s->failed_pc=0x0c086022u; return 0; }
r[14]+=0x00000010u;
goto P_0c086024;
P_0c086024: /* original 6bf6, guest PC 0x0c086024 */
if(!s->budget--) { s->failed_pc=0x0c086024u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c086026;
P_0c086026: /* original 66e3, guest PC 0x0c086026 */
if(!s->budget--) { s->failed_pc=0x0c086026u; return 0; }
r[6]=r[14];
goto P_0c086028;
P_0c086028: /* original f64d, guest PC 0x0c086028 */
if(!s->budget--) { s->failed_pc=0x0c086028u; return 0; }
fr[6]^=0x80000000u;
goto P_0c08602a;
P_0c08602a: /* original 6cf6, guest PC 0x0c08602a */
if(!s->budget--) { s->failed_pc=0x0c08602au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c08602c;
P_0c08602c: /* original 6df6, guest PC 0x0c08602c */
if(!s->budget--) { s->failed_pc=0x0c08602cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c08602e;
P_0c08602e: /* original ae55, guest PC 0x0c08602e */
if(!s->budget--) { s->failed_pc=0x0c08602eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c085cdc;
P_0c086030: /* original 6ef6, guest PC 0x0c086030 */
if(!s->budget--) { s->failed_pc=0x0c086030u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c086032u,s,ram);
P_0c08605a: /* original 4f22, guest PC 0x0c08605a */
if(!s->budget--) { s->failed_pc=0x0c08605au; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c08605c;
P_0c08605c: /* original d23f, guest PC 0x0c08605c */
if(!s->budget--) { s->failed_pc=0x0c08605cu; return 0; }
r[2]=read(ram,0x0c08615cu,4);
goto P_0c08605e;
P_0c08605e: /* original 3cec, guest PC 0x0c08605e */
if(!s->budget--) { s->failed_pc=0x0c08605eu; return 0; }
r[12]+=r[14];
goto P_0c086060;
P_0c086060: /* original 9d78, guest PC 0x0c086060 */
if(!s->budget--) { s->failed_pc=0x0c086060u; return 0; }
r[13]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c086154u,2);
goto P_0c086062;
P_0c086062: /* original 66c3, guest PC 0x0c086062 */
if(!s->budget--) { s->failed_pc=0x0c086062u; return 0; }
r[6]=r[12];
goto P_0c086064;
P_0c086064: /* original 2232, guest PC 0x0c086064 */
if(!s->budget--) { s->failed_pc=0x0c086064u; return 0; }
write(ram,r[2],r[3],4);
goto P_0c086066;
P_0c086066: /* original d13e, guest PC 0x0c086066 */
if(!s->budget--) { s->failed_pc=0x0c086066u; return 0; }
r[1]=read(ram,0x0c086160u,4);
goto P_0c086068;
P_0c086068: /* original 3dec, guest PC 0x0c086068 */
if(!s->budget--) { s->failed_pc=0x0c086068u; return 0; }
r[13]+=r[14];
goto P_0c08606a;
P_0c08606a: /* original 6412, guest PC 0x0c08606a */
if(!s->budget--) { s->failed_pc=0x0c08606au; return 0; }
tmp=read(ram,r[1],4);
r[4]=tmp;
goto P_0c08606c;
P_0c08606c: /* original bf93, guest PC 0x0c08606c */
if(!s->budget--) { s->failed_pc=0x0c08606cu; return 0; }
target=0x0c085f96u; r[16]=0x0c086070u;
r[5]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c086070u) { target=s->pc; goto dispatch; }
goto P_0c086070;
P_0c08606e: /* original 65d3, guest PC 0x0c08606e */
if(!s->budget--) { s->failed_pc=0x0c08606eu; return 0; }
r[5]=r[13];
goto P_0c086070;
P_0c086070: /* original 4f26, guest PC 0x0c086070 */
if(!s->budget--) { s->failed_pc=0x0c086070u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c086072;
P_0c086072: /* original 66c3, guest PC 0x0c086072 */
if(!s->budget--) { s->failed_pc=0x0c086072u; return 0; }
r[6]=r[12];
goto P_0c086074;
P_0c086074: /* original d23b, guest PC 0x0c086074 */
if(!s->budget--) { s->failed_pc=0x0c086074u; return 0; }
r[2]=read(ram,0x0c086164u,4);
goto P_0c086076;
P_0c086076: /* original 7d30, guest PC 0x0c086076 */
if(!s->budget--) { s->failed_pc=0x0c086076u; return 0; }
r[13]+=0x00000030u;
goto P_0c086078;
P_0c086078: /* original 67e3, guest PC 0x0c086078 */
if(!s->budget--) { s->failed_pc=0x0c086078u; return 0; }
r[7]=r[14];
goto P_0c08607a;
P_0c08607a: /* original 6cf6, guest PC 0x0c08607a */
if(!s->budget--) { s->failed_pc=0x0c08607au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c08607c;
P_0c08607c: /* original 65d3, guest PC 0x0c08607c */
if(!s->budget--) { s->failed_pc=0x0c08607cu; return 0; }
r[5]=r[13];
goto P_0c08607e;
P_0c08607e: /* original 6422, guest PC 0x0c08607e */
if(!s->budget--) { s->failed_pc=0x0c08607eu; return 0; }
tmp=read(ram,r[2],4);
r[4]=tmp;
goto P_0c086080;
P_0c086080: /* original 6df6, guest PC 0x0c086080 */
if(!s->budget--) { s->failed_pc=0x0c086080u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c086082;
P_0c086082: /* original af88, guest PC 0x0c086082 */
if(!s->budget--) { s->failed_pc=0x0c086082u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c085f96;
P_0c086084: /* original 6ef6, guest PC 0x0c086084 */
if(!s->budget--) { s->failed_pc=0x0c086084u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c086086u,s,ram);
P_0c08b648: /* original 4f22, guest PC 0x0c08b648 */
if(!s->budget--) { s->failed_pc=0x0c08b648u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c08b64a;
P_0c08b64a: /* original 7ffc, guest PC 0x0c08b64a */
if(!s->budget--) { s->failed_pc=0x0c08b64au; return 0; }
r[15]+=0xfffffffcu;
goto P_0c08b64c;
P_0c08b64c: /* original 2fe2, guest PC 0x0c08b64c */
if(!s->budget--) { s->failed_pc=0x0c08b64cu; return 0; }
write(ram,r[15],r[14],4);
goto P_0c08b64e;
P_0c08b64e: /* original b019, guest PC 0x0c08b64e */
if(!s->budget--) { s->failed_pc=0x0c08b64eu; return 0; }
target=0x0c08b684u; r[16]=0x0c08b652u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08b652u) { target=s->pc; goto dispatch; }
goto P_0c08b652;
P_0c08b650: /* original 64e3, guest PC 0x0c08b650 */
if(!s->budget--) { s->failed_pc=0x0c08b650u; return 0; }
r[4]=r[14];
goto P_0c08b652;
P_0c08b652: /* original b06d, guest PC 0x0c08b652 */
if(!s->budget--) { s->failed_pc=0x0c08b652u; return 0; }
target=0x0c08b730u; r[16]=0x0c08b656u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08b656u) { target=s->pc; goto dispatch; }
goto P_0c08b656;
P_0c08b654: /* original 64e3, guest PC 0x0c08b654 */
if(!s->budget--) { s->failed_pc=0x0c08b654u; return 0; }
r[4]=r[14];
goto P_0c08b656;
P_0c08b656: /* original 63f2, guest PC 0x0c08b656 */
if(!s->budget--) { s->failed_pc=0x0c08b656u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c08b658;
P_0c08b658: /* original 7f04, guest PC 0x0c08b658 */
if(!s->budget--) { s->failed_pc=0x0c08b658u; return 0; }
r[15]+=0x00000004u;
goto P_0c08b65a;
P_0c08b65a: /* original 4f26, guest PC 0x0c08b65a */
if(!s->budget--) { s->failed_pc=0x0c08b65au; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c08b65c;
P_0c08b65c: /* original d24b, guest PC 0x0c08b65c */
if(!s->budget--) { s->failed_pc=0x0c08b65cu; return 0; }
r[2]=read(ram,0x0c08b78cu,4);
goto P_0c08b65e;
P_0c08b65e: /* original 1323, guest PC 0x0c08b65e */
if(!s->budget--) { s->failed_pc=0x0c08b65eu; return 0; }
write(ram,r[3]+12,r[2],4);
goto P_0c08b660;
P_0c08b660: /* original 000b, guest PC 0x0c08b660 */
if(!s->budget--) { s->failed_pc=0x0c08b660u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c08b662: /* original 6ef6, guest PC 0x0c08b662 */
if(!s->budget--) { s->failed_pc=0x0c08b662u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c08b664u,s,ram);
P_0c08b668: /* original 4f22, guest PC 0x0c08b668 */
if(!s->budget--) { s->failed_pc=0x0c08b668u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c08b66a;
P_0c08b66a: /* original 7ffc, guest PC 0x0c08b66a */
if(!s->budget--) { s->failed_pc=0x0c08b66au; return 0; }
r[15]+=0xfffffffcu;
goto P_0c08b66c;
P_0c08b66c: /* original 2fe2, guest PC 0x0c08b66c */
if(!s->budget--) { s->failed_pc=0x0c08b66cu; return 0; }
write(ram,r[15],r[14],4);
goto P_0c08b66e;
P_0c08b66e: /* original b009, guest PC 0x0c08b66e */
if(!s->budget--) { s->failed_pc=0x0c08b66eu; return 0; }
target=0x0c08b684u; r[16]=0x0c08b672u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08b672u) { target=s->pc; goto dispatch; }
goto P_0c08b672;
P_0c08b670: /* original 64e3, guest PC 0x0c08b670 */
if(!s->budget--) { s->failed_pc=0x0c08b670u; return 0; }
r[4]=r[14];
goto P_0c08b672;
P_0c08b672: /* original b05d, guest PC 0x0c08b672 */
if(!s->budget--) { s->failed_pc=0x0c08b672u; return 0; }
target=0x0c08b730u; r[16]=0x0c08b676u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08b676u) { target=s->pc; goto dispatch; }
goto P_0c08b676;
P_0c08b674: /* original 64e3, guest PC 0x0c08b674 */
if(!s->budget--) { s->failed_pc=0x0c08b674u; return 0; }
r[4]=r[14];
goto P_0c08b676;
P_0c08b676: /* original 63f2, guest PC 0x0c08b676 */
if(!s->budget--) { s->failed_pc=0x0c08b676u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c08b678;
P_0c08b678: /* original 7f04, guest PC 0x0c08b678 */
if(!s->budget--) { s->failed_pc=0x0c08b678u; return 0; }
r[15]+=0x00000004u;
goto P_0c08b67a;
P_0c08b67a: /* original 4f26, guest PC 0x0c08b67a */
if(!s->budget--) { s->failed_pc=0x0c08b67au; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c08b67c;
P_0c08b67c: /* original d244, guest PC 0x0c08b67c */
if(!s->budget--) { s->failed_pc=0x0c08b67cu; return 0; }
r[2]=read(ram,0x0c08b790u,4);
goto P_0c08b67e;
P_0c08b67e: /* original 1323, guest PC 0x0c08b67e */
if(!s->budget--) { s->failed_pc=0x0c08b67eu; return 0; }
write(ram,r[3]+12,r[2],4);
goto P_0c08b680;
P_0c08b680: /* original 000b, guest PC 0x0c08b680 */
if(!s->budget--) { s->failed_pc=0x0c08b680u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c08b682: /* original 6ef6, guest PC 0x0c08b682 */
if(!s->budget--) { s->failed_pc=0x0c08b682u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c08b684u,s,ram);
P_0c090c8c: /* original 2fe6, guest PC 0x0c090c8c */
if(!s->budget--) { s->failed_pc=0x0c090c8cu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c090c8e;
P_0c090c8e: /* original 6e43, guest PC 0x0c090c8e */
if(!s->budget--) { s->failed_pc=0x0c090c8eu; return 0; }
r[14]=r[4];
goto P_0c090c90;
P_0c090c90: /* original 54ec, guest PC 0x0c090c90 */
if(!s->budget--) { s->failed_pc=0x0c090c90u; return 0; }
r[4]=read(ram,r[14]+48,4);
goto P_0c090c92;
P_0c090c92: /* original e310, guest PC 0x0c090c92 */
if(!s->budget--) { s->failed_pc=0x0c090c92u; return 0; }
r[3]=0x00000010u;
return vf3_matrix_family(0x0c090c94u,s,ram);
P_0c09102a: /* original 4f22, guest PC 0x0c09102a */
if(!s->budget--) { s->failed_pc=0x0c09102au; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c09102c;
P_0c09102c: /* original d318, guest PC 0x0c09102c */
if(!s->budget--) { s->failed_pc=0x0c09102cu; return 0; }
r[3]=read(ram,0x0c091090u,4);
goto P_0c09102e;
P_0c09102e: /* original 430b, guest PC 0x0c09102e */
if(!s->budget--) { s->failed_pc=0x0c09102eu; return 0; }
target=r[3];
r[16]=0x0c091032u;
r[14]=r[4];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c091032u) { target=s->pc; goto dispatch; }
goto P_0c091032;
P_0c091030: /* original 6e43, guest PC 0x0c091030 */
if(!s->budget--) { s->failed_pc=0x0c091030u; return 0; }
r[14]=r[4];
goto P_0c091032;
P_0c091032: /* original be2b, guest PC 0x0c091032 */
if(!s->budget--) { s->failed_pc=0x0c091032u; return 0; }
target=0x0c090c8cu; r[16]=0x0c091036u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c091036u) { target=s->pc; goto dispatch; }
goto P_0c091036;
P_0c091034: /* original 64e3, guest PC 0x0c091034 */
if(!s->budget--) { s->failed_pc=0x0c091034u; return 0; }
r[4]=r[14];
goto P_0c091036;
P_0c091036: /* original 4f26, guest PC 0x0c091036 */
if(!s->budget--) { s->failed_pc=0x0c091036u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c091038;
P_0c091038: /* original 9024, guest PC 0x0c091038 */
if(!s->budget--) { s->failed_pc=0x0c091038u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c091084u,2);
goto P_0c09103a;
P_0c09103a: /* original e305, guest PC 0x0c09103a */
if(!s->budget--) { s->failed_pc=0x0c09103au; return 0; }
r[3]=0x00000005u;
goto P_0c09103c;
P_0c09103c: /* original 64e3, guest PC 0x0c09103c */
if(!s->budget--) { s->failed_pc=0x0c09103cu; return 0; }
r[4]=r[14];
goto P_0c09103e;
P_0c09103e: /* original 0e34, guest PC 0x0c09103e */
if(!s->budget--) { s->failed_pc=0x0c09103eu; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c091040;
P_0c091040: /* original a000, guest PC 0x0c091040 */
if(!s->budget--) { s->failed_pc=0x0c091040u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c091044;
P_0c091042: /* original 6ef6, guest PC 0x0c091042 */
if(!s->budget--) { s->failed_pc=0x0c091042u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c091044;
P_0c091044: /* original 2fe6, guest PC 0x0c091044 */
if(!s->budget--) { s->failed_pc=0x0c091044u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c091046;
P_0c091046: /* original d115, guest PC 0x0c091046 */
if(!s->budget--) { s->failed_pc=0x0c091046u; return 0; }
r[1]=read(ram,0x0c09109cu,4);
goto P_0c091048;
P_0c091048: /* original 4f22, guest PC 0x0c091048 */
if(!s->budget--) { s->failed_pc=0x0c091048u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c09104a;
P_0c09104a: /* original 6212, guest PC 0x0c09104a */
if(!s->budget--) { s->failed_pc=0x0c09104au; return 0; }
tmp=read(ram,r[1],4);
r[2]=tmp;
goto P_0c09104c;
P_0c09104c: /* original d312, guest PC 0x0c09104c */
if(!s->budget--) { s->failed_pc=0x0c09104cu; return 0; }
r[3]=read(ram,0x0c091098u,4);
goto P_0c09104e;
P_0c09104e: /* original 2238, guest PC 0x0c09104e */
if(!s->budget--) { s->failed_pc=0x0c09104eu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c091050;
P_0c091050: /* original 8f14, guest PC 0x0c091050 */
if(!s->budget--) { s->failed_pc=0x0c091050u; return 0; }
cond=r[17]&1u;
r[14]=r[4];
if(!cond) { goto P_0c09107c; }
goto P_0c091054;
P_0c091052: /* original 6e43, guest PC 0x0c091052 */
if(!s->budget--) { s->failed_pc=0x0c091052u; return 0; }
r[14]=r[4];
goto P_0c091054;
P_0c091054: /* original d313, guest PC 0x0c091054 */
if(!s->budget--) { s->failed_pc=0x0c091054u; return 0; }
r[3]=read(ram,0x0c0910a4u,4);
goto P_0c091056;
P_0c091056: /* original 430b, guest PC 0x0c091056 */
if(!s->budget--) { s->failed_pc=0x0c091056u; return 0; }
target=r[3];
r[16]=0x0c09105au;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09105au) { target=s->pc; goto dispatch; }
goto P_0c09105a;
P_0c091058: /* original 64e3, guest PC 0x0c091058 */
if(!s->budget--) { s->failed_pc=0x0c091058u; return 0; }
r[4]=r[14];
goto P_0c09105a;
P_0c09105a: /* original d213, guest PC 0x0c09105a */
if(!s->budget--) { s->failed_pc=0x0c09105au; return 0; }
r[2]=read(ram,0x0c0910a8u,4);
goto P_0c09105c;
P_0c09105c: /* original 420b, guest PC 0x0c09105c */
if(!s->budget--) { s->failed_pc=0x0c09105cu; return 0; }
target=r[2];
r[16]=0x0c091060u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c091060u) { target=s->pc; goto dispatch; }
goto P_0c091060;
P_0c09105e: /* original 64e3, guest PC 0x0c09105e */
if(!s->budget--) { s->failed_pc=0x0c09105eu; return 0; }
r[4]=r[14];
goto P_0c091060;
P_0c091060: /* original d312, guest PC 0x0c091060 */
if(!s->budget--) { s->failed_pc=0x0c091060u; return 0; }
r[3]=read(ram,0x0c0910acu,4);
goto P_0c091062;
P_0c091062: /* original 430b, guest PC 0x0c091062 */
if(!s->budget--) { s->failed_pc=0x0c091062u; return 0; }
target=r[3];
r[16]=0x0c091066u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c091066u) { target=s->pc; goto dispatch; }
goto P_0c091066;
P_0c091064: /* original 64e3, guest PC 0x0c091064 */
if(!s->budget--) { s->failed_pc=0x0c091064u; return 0; }
r[4]=r[14];
goto P_0c091066;
P_0c091066: /* original d212, guest PC 0x0c091066 */
if(!s->budget--) { s->failed_pc=0x0c091066u; return 0; }
r[2]=read(ram,0x0c0910b0u,4);
goto P_0c091068;
P_0c091068: /* original 420b, guest PC 0x0c091068 */
if(!s->budget--) { s->failed_pc=0x0c091068u; return 0; }
target=r[2];
r[16]=0x0c09106cu;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09106cu) { target=s->pc; goto dispatch; }
goto P_0c09106c;
P_0c09106a: /* original 64e3, guest PC 0x0c09106a */
if(!s->budget--) { s->failed_pc=0x0c09106au; return 0; }
r[4]=r[14];
goto P_0c09106c;
P_0c09106c: /* original bb23, guest PC 0x0c09106c */
if(!s->budget--) { s->failed_pc=0x0c09106cu; return 0; }
target=0x0c0906b6u; r[16]=0x0c091070u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c091070u) { target=s->pc; goto dispatch; }
goto P_0c091070;
P_0c09106e: /* original 64e3, guest PC 0x0c09106e */
if(!s->budget--) { s->failed_pc=0x0c09106eu; return 0; }
r[4]=r[14];
goto P_0c091070;
P_0c091070: /* original d210, guest PC 0x0c091070 */
if(!s->budget--) { s->failed_pc=0x0c091070u; return 0; }
r[2]=read(ram,0x0c0910b4u,4);
goto P_0c091072;
P_0c091072: /* original 420b, guest PC 0x0c091072 */
if(!s->budget--) { s->failed_pc=0x0c091072u; return 0; }
target=r[2];
r[16]=0x0c091076u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c091076u) { target=s->pc; goto dispatch; }
goto P_0c091076;
P_0c091074: /* original 64e3, guest PC 0x0c091074 */
if(!s->budget--) { s->failed_pc=0x0c091074u; return 0; }
r[4]=r[14];
goto P_0c091076;
P_0c091076: /* original d310, guest PC 0x0c091076 */
if(!s->budget--) { s->failed_pc=0x0c091076u; return 0; }
r[3]=read(ram,0x0c0910b8u,4);
goto P_0c091078;
P_0c091078: /* original 430b, guest PC 0x0c091078 */
if(!s->budget--) { s->failed_pc=0x0c091078u; return 0; }
target=r[3];
r[16]=0x0c09107cu;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09107cu) { target=s->pc; goto dispatch; }
goto P_0c09107c;
P_0c09107a: /* original 64e3, guest PC 0x0c09107a */
if(!s->budget--) { s->failed_pc=0x0c09107au; return 0; }
r[4]=r[14];
goto P_0c09107c;
P_0c09107c: /* original 4f26, guest PC 0x0c09107c */
if(!s->budget--) { s->failed_pc=0x0c09107cu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c09107e;
P_0c09107e: /* original 000b, guest PC 0x0c09107e */
if(!s->budget--) { s->failed_pc=0x0c09107eu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c091080: /* original 6ef6, guest PC 0x0c091080 */
if(!s->budget--) { s->failed_pc=0x0c091080u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c091082u,s,ram);
P_0c09493c: /* original 4715, guest PC 0x0c09493c */
if(!s->budget--) { s->failed_pc=0x0c09493cu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[7]>0)!=0);
goto P_0c09493e;
P_0c09493e: /* original 6453, guest PC 0x0c09493e */
if(!s->budget--) { s->failed_pc=0x0c09493eu; return 0; }
r[4]=r[5];
goto P_0c094940;
P_0c094940: /* original 8f15, guest PC 0x0c094940 */
if(!s->budget--) { s->failed_pc=0x0c094940u; return 0; }
cond=r[17]&1u;
r[5]=r[6];
if(!cond) { goto P_0c09496e; }
goto P_0c094944;
P_0c094942: /* original 6563, guest PC 0x0c094942 */
if(!s->budget--) { s->failed_pc=0x0c094942u; return 0; }
r[5]=r[6];
goto P_0c094944;
P_0c094944: /* original f549, guest PC 0x0c094944 */
if(!s->budget--) { s->failed_pc=0x0c094944u; return 0; }
vf3_matrix_load(s,ram,5,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c094946;
P_0c094946: /* original 77ff, guest PC 0x0c094946 */
if(!s->budget--) { s->failed_pc=0x0c094946u; return 0; }
r[7]+=0xffffffffu;
goto P_0c094948;
P_0c094948: /* original 4715, guest PC 0x0c094948 */
if(!s->budget--) { s->failed_pc=0x0c094948u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[7]>0)!=0);
goto P_0c09494a;
P_0c09494a: /* original f649, guest PC 0x0c09494a */
if(!s->budget--) { s->failed_pc=0x0c09494au; return 0; }
vf3_matrix_load(s,ram,6,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c09494c;
P_0c09494c: /* original f749, guest PC 0x0c09494c */
if(!s->budget--) { s->failed_pc=0x0c09494cu; return 0; }
vf3_matrix_load(s,ram,7,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c09494e;
P_0c09494e: /* original f849, guest PC 0x0c09494e */
if(!s->budget--) { s->failed_pc=0x0c09494eu; return 0; }
vf3_matrix_load(s,ram,8,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c094950;
P_0c094950: /* original f949, guest PC 0x0c094950 */
if(!s->budget--) { s->failed_pc=0x0c094950u; return 0; }
vf3_matrix_load(s,ram,9,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c094952;
P_0c094952: /* original f449, guest PC 0x0c094952 */
if(!s->budget--) { s->failed_pc=0x0c094952u; return 0; }
vf3_matrix_load(s,ram,4,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c094954;
P_0c094954: /* original f55a, guest PC 0x0c094954 */
if(!s->budget--) { s->failed_pc=0x0c094954u; return 0; }
vf3_matrix_store(s,ram,5,r[5]);
goto P_0c094956;
P_0c094956: /* original 7504, guest PC 0x0c094956 */
if(!s->budget--) { s->failed_pc=0x0c094956u; return 0; }
r[5]+=0x00000004u;
goto P_0c094958;
P_0c094958: /* original f56a, guest PC 0x0c094958 */
if(!s->budget--) { s->failed_pc=0x0c094958u; return 0; }
vf3_matrix_store(s,ram,6,r[5]);
goto P_0c09495a;
P_0c09495a: /* original 7504, guest PC 0x0c09495a */
if(!s->budget--) { s->failed_pc=0x0c09495au; return 0; }
r[5]+=0x00000004u;
goto P_0c09495c;
P_0c09495c: /* original f57a, guest PC 0x0c09495c */
if(!s->budget--) { s->failed_pc=0x0c09495cu; return 0; }
vf3_matrix_store(s,ram,7,r[5]);
goto P_0c09495e;
P_0c09495e: /* original 7504, guest PC 0x0c09495e */
if(!s->budget--) { s->failed_pc=0x0c09495eu; return 0; }
r[5]+=0x00000004u;
goto P_0c094960;
P_0c094960: /* original f58a, guest PC 0x0c094960 */
if(!s->budget--) { s->failed_pc=0x0c094960u; return 0; }
vf3_matrix_store(s,ram,8,r[5]);
goto P_0c094962;
P_0c094962: /* original 7504, guest PC 0x0c094962 */
if(!s->budget--) { s->failed_pc=0x0c094962u; return 0; }
r[5]+=0x00000004u;
goto P_0c094964;
P_0c094964: /* original f59a, guest PC 0x0c094964 */
if(!s->budget--) { s->failed_pc=0x0c094964u; return 0; }
vf3_matrix_store(s,ram,9,r[5]);
goto P_0c094966;
P_0c094966: /* original 7504, guest PC 0x0c094966 */
if(!s->budget--) { s->failed_pc=0x0c094966u; return 0; }
r[5]+=0x00000004u;
goto P_0c094968;
P_0c094968: /* original f54a, guest PC 0x0c094968 */
if(!s->budget--) { s->failed_pc=0x0c094968u; return 0; }
vf3_matrix_store(s,ram,4,r[5]);
goto P_0c09496a;
P_0c09496a: /* original 8deb, guest PC 0x0c09496a */
if(!s->budget--) { s->failed_pc=0x0c09496au; return 0; }
cond=r[17]&1u;
r[5]+=0x00000004u;
if(cond) { goto P_0c094944; }
goto P_0c09496e;
P_0c09496c: /* original 7504, guest PC 0x0c09496c */
if(!s->budget--) { s->failed_pc=0x0c09496cu; return 0; }
r[5]+=0x00000004u;
goto P_0c09496e;
P_0c09496e: /* original 000b, guest PC 0x0c09496e */
if(!s->budget--) { s->failed_pc=0x0c09496eu; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c094970: /* original 0009, guest PC 0x0c094970 */
if(!s->budget--) { s->failed_pc=0x0c094970u; return 0; }
goto P_0c094972;
P_0c094972: /* original 2fe6, guest PC 0x0c094972 */
if(!s->budget--) { s->failed_pc=0x0c094972u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c094974;
P_0c094974: /* original 6e43, guest PC 0x0c094974 */
if(!s->budget--) { s->failed_pc=0x0c094974u; return 0; }
r[14]=r[4];
goto P_0c094976;
P_0c094976: /* original 2fd6, guest PC 0x0c094976 */
if(!s->budget--) { s->failed_pc=0x0c094976u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c094978;
P_0c094978: /* original 906a, guest PC 0x0c094978 */
if(!s->budget--) { s->failed_pc=0x0c094978u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c094a50u,2);
goto P_0c09497a;
P_0c09497a: /* original 4f22, guest PC 0x0c09497a */
if(!s->budget--) { s->failed_pc=0x0c09497au; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c09497c;
P_0c09497c: /* original 05ee, guest PC 0x0c09497c */
if(!s->budget--) { s->failed_pc=0x0c09497cu; return 0; }
r[5]=read(ram,r[14]+r[0],4);
goto P_0c09497e;
P_0c09497e: /* original 7004, guest PC 0x0c09497e */
if(!s->budget--) { s->failed_pc=0x0c09497eu; return 0; }
r[0]+=0x00000004u;
goto P_0c094980;
P_0c094980: /* original 04ec, guest PC 0x0c094980 */
if(!s->budget--) { s->failed_pc=0x0c094980u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c094982;
P_0c094982: /* original 7001, guest PC 0x0c094982 */
if(!s->budget--) { s->failed_pc=0x0c094982u; return 0; }
r[0]+=0x00000001u;
goto P_0c094984;
P_0c094984: /* original 9265, guest PC 0x0c094984 */
if(!s->budget--) { s->failed_pc=0x0c094984u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c094a52u,2);
goto P_0c094986;
P_0c094986: /* original 644c, guest PC 0x0c094986 */
if(!s->budget--) { s->failed_pc=0x0c094986u; return 0; }
r[4]=r[4]&255u;
goto P_0c094988;
P_0c094988: /* original dd35, guest PC 0x0c094988 */
if(!s->budget--) { s->failed_pc=0x0c094988u; return 0; }
r[13]=read(ram,0x0c094a60u,4);
goto P_0c09498a;
P_0c09498a: /* original 7401, guest PC 0x0c09498a */
if(!s->budget--) { s->failed_pc=0x0c09498au; return 0; }
r[4]+=0x00000001u;
goto P_0c09498c;
P_0c09498c: /* original 6343, guest PC 0x0c09498c */
if(!s->budget--) { s->failed_pc=0x0c09498cu; return 0; }
r[3]=r[4];
goto P_0c09498e;
P_0c09498e: /* original 4308, guest PC 0x0c09498e */
if(!s->budget--) { s->failed_pc=0x0c09498eu; return 0; }
r[3]<<=2;
goto P_0c094990;
P_0c094990: /* original 353c, guest PC 0x0c094990 */
if(!s->budget--) { s->failed_pc=0x0c094990u; return 0; }
r[5]+=r[3];
goto P_0c094992;
P_0c094992: /* original 6650, guest PC 0x0c094992 */
if(!s->budget--) { s->failed_pc=0x0c094992u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[5],1);
r[6]=tmp;
goto P_0c094994;
P_0c094994: /* original 666c, guest PC 0x0c094994 */
if(!s->budget--) { s->failed_pc=0x0c094994u; return 0; }
r[6]=r[6]&255u;
goto P_0c094996;
P_0c094996: /* original 3620, guest PC 0x0c094996 */
if(!s->budget--) { s->failed_pc=0x0c094996u; return 0; }
r[17]=(r[17]&~1u)|((r[6]==r[2])!=0);
goto P_0c094998;
P_0c094998: /* original 8d07, guest PC 0x0c094998 */
if(!s->budget--) { s->failed_pc=0x0c094998u; return 0; }
cond=r[17]&1u;
r[7]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
if(cond) { goto P_0c0949aa; }
goto P_0c09499c;
P_0c09499a: /* original 07ec, guest PC 0x0c09499a */
if(!s->budget--) { s->failed_pc=0x0c09499au; return 0; }
r[7]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c09499c;
P_0c09499c: /* original 935a, guest PC 0x0c09499c */
if(!s->budget--) { s->failed_pc=0x0c09499cu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c094a54u,2);
goto P_0c09499e;
P_0c09499e: /* original 3630, guest PC 0x0c09499e */
if(!s->budget--) { s->failed_pc=0x0c09499eu; return 0; }
r[17]=(r[17]&~1u)|((r[6]==r[3])!=0);
goto P_0c0949a0;
P_0c0949a0: /* original 8912, guest PC 0x0c0949a0 */
if(!s->budget--) { s->failed_pc=0x0c0949a0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0949c8; }
goto P_0c0949a2;
P_0c0949a2: /* original 4715, guest PC 0x0c0949a2 */
if(!s->budget--) { s->failed_pc=0x0c0949a2u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[7]>0)!=0);
goto P_0c0949a4;
P_0c0949a4: /* original 893d, guest PC 0x0c0949a4 */
if(!s->budget--) { s->failed_pc=0x0c0949a4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c094a22; }
goto P_0c0949a6;
P_0c0949a6: /* original a012, guest PC 0x0c0949a6 */
if(!s->budget--) { s->failed_pc=0x0c0949a6u; return 0; }
goto P_0c0949ce;
P_0c0949a8: /* original 0009, guest PC 0x0c0949a8 */
if(!s->budget--) { s->failed_pc=0x0c0949a8u; return 0; }
goto P_0c0949aa;
P_0c0949aa: /* original 50ed, guest PC 0x0c0949aa */
if(!s->budget--) { s->failed_pc=0x0c0949aau; return 0; }
r[0]=read(ram,r[14]+52,4);
goto P_0c0949ac;
P_0c0949ac: /* original 881c, guest PC 0x0c0949ac */
if(!s->budget--) { s->failed_pc=0x0c0949acu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000001cu)!=0);
goto P_0c0949ae;
P_0c0949ae: /* original 8f05, guest PC 0x0c0949ae */
if(!s->budget--) { s->failed_pc=0x0c0949aeu; return 0; }
cond=r[17]&1u;
r[4]=r[0];
if(!cond) { goto P_0c0949bc; }
goto P_0c0949b2;
P_0c0949b0: /* original 6403, guest PC 0x0c0949b0 */
if(!s->budget--) { s->failed_pc=0x0c0949b0u; return 0; }
r[4]=r[0];
goto P_0c0949b2;
P_0c0949b2: /* original 9050, guest PC 0x0c0949b2 */
if(!s->budget--) { s->failed_pc=0x0c0949b2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c094a56u,2);
goto P_0c0949b4;
P_0c0949b4: /* original e301, guest PC 0x0c0949b4 */
if(!s->budget--) { s->failed_pc=0x0c0949b4u; return 0; }
r[3]=0x00000001u;
goto P_0c0949b6;
P_0c0949b6: /* original 04de, guest PC 0x0c0949b6 */
if(!s->budget--) { s->failed_pc=0x0c0949b6u; return 0; }
r[4]=read(ram,r[13]+r[0],4);
goto P_0c0949b8;
P_0c0949b8: /* original 2439, guest PC 0x0c0949b8 */
if(!s->budget--) { s->failed_pc=0x0c0949b8u; return 0; }
r[4]&=r[3];
goto P_0c0949ba;
P_0c0949ba: /* original 0d46, guest PC 0x0c0949ba */
if(!s->budget--) { s->failed_pc=0x0c0949bau; return 0; }
write(ram,r[13]+r[0],r[4],4);
goto P_0c0949bc;
P_0c0949bc: /* original 904c, guest PC 0x0c0949bc */
if(!s->budget--) { s->failed_pc=0x0c0949bcu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c094a58u,2);
goto P_0c0949be;
P_0c0949be: /* original e300, guest PC 0x0c0949be */
if(!s->budget--) { s->failed_pc=0x0c0949beu; return 0; }
r[3]=0x00000000u;
goto P_0c0949c0;
P_0c0949c0: /* original 0e36, guest PC 0x0c0949c0 */
if(!s->budget--) { s->failed_pc=0x0c0949c0u; return 0; }
write(ram,r[14]+r[0],r[3],4);
goto P_0c0949c2;
P_0c0949c2: /* original d428, guest PC 0x0c0949c2 */
if(!s->budget--) { s->failed_pc=0x0c0949c2u; return 0; }
r[4]=read(ram,0x0c094a64u,4);
goto P_0c0949c4;
P_0c0949c4: /* original a031, guest PC 0x0c0949c4 */
if(!s->budget--) { s->failed_pc=0x0c0949c4u; return 0; }
goto P_0c094a2a;
P_0c0949c6: /* original 0009, guest PC 0x0c0949c6 */
if(!s->budget--) { s->failed_pc=0x0c0949c6u; return 0; }
goto P_0c0949c8;
P_0c0949c8: /* original 6650, guest PC 0x0c0949c8 */
if(!s->budget--) { s->failed_pc=0x0c0949c8u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[5],1);
r[6]=tmp;
goto P_0c0949ca;
P_0c0949ca: /* original e400, guest PC 0x0c0949ca */
if(!s->budget--) { s->failed_pc=0x0c0949cau; return 0; }
r[4]=0x00000000u;
goto P_0c0949cc;
P_0c0949cc: /* original 666c, guest PC 0x0c0949cc */
if(!s->budget--) { s->failed_pc=0x0c0949ccu; return 0; }
r[6]=r[6]&255u;
goto P_0c0949ce;
P_0c0949ce: /* original 9044, guest PC 0x0c0949ce */
if(!s->budget--) { s->failed_pc=0x0c0949ceu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c094a5au,2);
goto P_0c0949d0;
P_0c0949d0: /* original 4608, guest PC 0x0c0949d0 */
if(!s->budget--) { s->failed_pc=0x0c0949d0u; return 0; }
r[6]<<=2;
goto P_0c0949d2;
P_0c0949d2: /* original 0e44, guest PC 0x0c0949d2 */
if(!s->budget--) { s->failed_pc=0x0c0949d2u; return 0; }
write(ram,r[14]+r[0],r[4],1);
goto P_0c0949d4;
P_0c0949d4: /* original 8451, guest PC 0x0c0949d4 */
if(!s->budget--) { s->failed_pc=0x0c0949d4u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[5]+1,1);
goto P_0c0949d6;
P_0c0949d6: /* original 640c, guest PC 0x0c0949d6 */
if(!s->budget--) { s->failed_pc=0x0c0949d6u; return 0; }
r[4]=r[0]&255u;
goto P_0c0949d8;
P_0c0949d8: /* original 9040, guest PC 0x0c0949d8 */
if(!s->budget--) { s->failed_pc=0x0c0949d8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c094a5cu,2);
goto P_0c0949da;
P_0c0949da: /* original 445a, guest PC 0x0c0949da */
if(!s->budget--) { s->failed_pc=0x0c0949dau; return 0; }
r[53]=r[4];
goto P_0c0949dc;
P_0c0949dc: /* original f32d, guest PC 0x0c0949dc */
if(!s->budget--) { s->failed_pc=0x0c0949dcu; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c0949de;
P_0c0949de: /* original f43c, guest PC 0x0c0949de */
if(!s->budget--) { s->failed_pc=0x0c0949deu; return 0; }
vf3_matrix_move(s,4,3);
goto P_0c0949e0;
P_0c0949e0: /* original f49d, guest PC 0x0c0949e0 */
if(!s->budget--) { s->failed_pc=0x0c0949e0u; return 0; }
fr[4]=0x3f800000u;
goto P_0c0949e2;
P_0c0949e2: /* original f433, guest PC 0x0c0949e2 */
if(!s->budget--) { s->failed_pc=0x0c0949e2u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'/');
goto P_0c0949e4;
P_0c0949e4: /* original fe47, guest PC 0x0c0949e4 */
if(!s->budget--) { s->failed_pc=0x0c0949e4u; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c0949e6;
P_0c0949e6: /* original 7004, guest PC 0x0c0949e6 */
if(!s->budget--) { s->failed_pc=0x0c0949e6u; return 0; }
r[0]+=0x00000004u;
goto P_0c0949e8;
P_0c0949e8: /* original f38d, guest PC 0x0c0949e8 */
if(!s->budget--) { s->failed_pc=0x0c0949e8u; return 0; }
fr[3]=0;
goto P_0c0949ea;
P_0c0949ea: /* original fe37, guest PC 0x0c0949ea */
if(!s->budget--) { s->failed_pc=0x0c0949eau; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0949ec;
P_0c0949ec: /* original 8551, guest PC 0x0c0949ec */
if(!s->budget--) { s->failed_pc=0x0c0949ecu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[5]+2,2);
goto P_0c0949ee;
P_0c0949ee: /* original 6d0d, guest PC 0x0c0949ee */
if(!s->budget--) { s->failed_pc=0x0c0949eeu; return 0; }
r[13]=r[0]&65535u;
goto P_0c0949f0;
P_0c0949f0: /* original 9035, guest PC 0x0c0949f0 */
if(!s->budget--) { s->failed_pc=0x0c0949f0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c094a5eu,2);
goto P_0c0949f2;
P_0c0949f2: /* original 0ed4, guest PC 0x0c0949f2 */
if(!s->budget--) { s->failed_pc=0x0c0949f2u; return 0; }
write(ram,r[14]+r[0],r[13],1);
goto P_0c0949f4;
P_0c0949f4: /* original e07c, guest PC 0x0c0949f4 */
if(!s->budget--) { s->failed_pc=0x0c0949f4u; return 0; }
r[0]=0x0000007cu;
goto P_0c0949f6;
P_0c0949f6: /* original 03ee, guest PC 0x0c0949f6 */
if(!s->budget--) { s->failed_pc=0x0c0949f6u; return 0; }
r[3]=read(ram,r[14]+r[0],4);
goto P_0c0949f8;
P_0c0949f8: /* original e070, guest PC 0x0c0949f8 */
if(!s->budget--) { s->failed_pc=0x0c0949f8u; return 0; }
r[0]=0x00000070u;
goto P_0c0949fa;
P_0c0949fa: /* original 0e36, guest PC 0x0c0949fa */
if(!s->budget--) { s->failed_pc=0x0c0949fau; return 0; }
write(ram,r[14]+r[0],r[3],4);
goto P_0c0949fc;
P_0c0949fc: /* original 63e3, guest PC 0x0c0949fc */
if(!s->budget--) { s->failed_pc=0x0c0949fcu; return 0; }
r[3]=r[14];
goto P_0c0949fe;
P_0c0949fe: /* original 734c, guest PC 0x0c0949fe */
if(!s->budget--) { s->failed_pc=0x0c0949feu; return 0; }
r[3]+=0x0000004cu;
goto P_0c094a00;
P_0c094a00: /* original 363c, guest PC 0x0c094a00 */
if(!s->budget--) { s->failed_pc=0x0c094a00u; return 0; }
r[6]+=r[3];
goto P_0c094a02;
P_0c094a02: /* original 6262, guest PC 0x0c094a02 */
if(!s->budget--) { s->failed_pc=0x0c094a02u; return 0; }
tmp=read(ram,r[6],4);
r[2]=tmp;
goto P_0c094a04;
P_0c094a04: /* original e07c, guest PC 0x0c094a04 */
if(!s->budget--) { s->failed_pc=0x0c094a04u; return 0; }
r[0]=0x0000007cu;
goto P_0c094a06;
P_0c094a06: /* original 0e26, guest PC 0x0c094a06 */
if(!s->budget--) { s->failed_pc=0x0c094a06u; return 0; }
write(ram,r[14]+r[0],r[2],4);
goto P_0c094a08;
P_0c094a08: /* original 85ef, guest PC 0x0c094a08 */
if(!s->budget--) { s->failed_pc=0x0c094a08u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+30,2);
goto P_0c094a0a;
P_0c094a0a: /* original 6703, guest PC 0x0c094a0a */
if(!s->budget--) { s->failed_pc=0x0c094a0au; return 0; }
r[7]=r[0];
goto P_0c094a0c;
P_0c094a0c: /* original e074, guest PC 0x0c094a0c */
if(!s->budget--) { s->failed_pc=0x0c094a0cu; return 0; }
r[0]=0x00000074u;
goto P_0c094a0e;
P_0c094a0e: /* original 06ee, guest PC 0x0c094a0e */
if(!s->budget--) { s->failed_pc=0x0c094a0eu; return 0; }
r[6]=read(ram,r[14]+r[0],4);
goto P_0c094a10;
P_0c094a10: /* original e078, guest PC 0x0c094a10 */
if(!s->budget--) { s->failed_pc=0x0c094a10u; return 0; }
r[0]=0x00000078u;
goto P_0c094a12;
P_0c094a12: /* original 05ee, guest PC 0x0c094a12 */
if(!s->budget--) { s->failed_pc=0x0c094a12u; return 0; }
r[5]=read(ram,r[14]+r[0],4);
goto P_0c094a14;
P_0c094a14: /* original bf92, guest PC 0x0c094a14 */
if(!s->budget--) { s->failed_pc=0x0c094a14u; return 0; }
target=0x0c09493cu; r[16]=0x0c094a18u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c094a18u) { target=s->pc; goto dispatch; }
goto P_0c094a18;
P_0c094a16: /* original 64e3, guest PC 0x0c094a16 */
if(!s->budget--) { s->failed_pc=0x0c094a16u; return 0; }
r[4]=r[14];
goto P_0c094a18;
P_0c094a18: /* original d413, guest PC 0x0c094a18 */
if(!s->budget--) { s->failed_pc=0x0c094a18u; return 0; }
r[4]=read(ram,0x0c094a68u,4);
goto P_0c094a1a;
P_0c094a1a: /* original 7dff, guest PC 0x0c094a1a */
if(!s->budget--) { s->failed_pc=0x0c094a1au; return 0; }
r[13]+=0xffffffffu;
goto P_0c094a1c;
P_0c094a1c: /* original 901f, guest PC 0x0c094a1c */
if(!s->budget--) { s->failed_pc=0x0c094a1cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c094a5eu,2);
goto P_0c094a1e;
P_0c094a1e: /* original a004, guest PC 0x0c094a1e */
if(!s->budget--) { s->failed_pc=0x0c094a1eu; return 0; }
write(ram,r[14]+r[0],r[13],1);
goto P_0c094a2a;
P_0c094a20: /* original 0ed4, guest PC 0x0c094a20 */
if(!s->budget--) { s->failed_pc=0x0c094a20u; return 0; }
write(ram,r[14]+r[0],r[13],1);
goto P_0c094a22;
P_0c094a22: /* original 901c, guest PC 0x0c094a22 */
if(!s->budget--) { s->failed_pc=0x0c094a22u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c094a5eu,2);
goto P_0c094a24;
P_0c094a24: /* original 77ff, guest PC 0x0c094a24 */
if(!s->budget--) { s->failed_pc=0x0c094a24u; return 0; }
r[7]+=0xffffffffu;
goto P_0c094a26;
P_0c094a26: /* original 0e74, guest PC 0x0c094a26 */
if(!s->budget--) { s->failed_pc=0x0c094a26u; return 0; }
write(ram,r[14]+r[0],r[7],1);
goto P_0c094a28;
P_0c094a28: /* original d40f, guest PC 0x0c094a28 */
if(!s->budget--) { s->failed_pc=0x0c094a28u; return 0; }
r[4]=read(ram,0x0c094a68u,4);
goto P_0c094a2a;
P_0c094a2a: /* original 4f26, guest PC 0x0c094a2a */
if(!s->budget--) { s->failed_pc=0x0c094a2au; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c094a2c;
P_0c094a2c: /* original 6043, guest PC 0x0c094a2c */
if(!s->budget--) { s->failed_pc=0x0c094a2cu; return 0; }
r[0]=r[4];
goto P_0c094a2e;
P_0c094a2e: /* original 6df6, guest PC 0x0c094a2e */
if(!s->budget--) { s->failed_pc=0x0c094a2eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c094a30;
P_0c094a30: /* original 000b, guest PC 0x0c094a30 */
if(!s->budget--) { s->failed_pc=0x0c094a30u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c094a32: /* original 6ef6, guest PC 0x0c094a32 */
if(!s->budget--) { s->failed_pc=0x0c094a32u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c094a34u,s,ram);
P_0c094ccc: /* original 2fe6, guest PC 0x0c094ccc */
if(!s->budget--) { s->failed_pc=0x0c094cccu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c094cce;
P_0c094cce: /* original 6e43, guest PC 0x0c094cce */
if(!s->budget--) { s->failed_pc=0x0c094cceu; return 0; }
r[14]=r[4];
goto P_0c094cd0;
P_0c094cd0: /* original 9065, guest PC 0x0c094cd0 */
if(!s->budget--) { s->failed_pc=0x0c094cd0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c094d9eu,2);
goto P_0c094cd2;
P_0c094cd2: /* original 4f22, guest PC 0x0c094cd2 */
if(!s->budget--) { s->failed_pc=0x0c094cd2u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c094cd4;
P_0c094cd4: /* original 00ec, guest PC 0x0c094cd4 */
if(!s->budget--) { s->failed_pc=0x0c094cd4u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c094cd6;
P_0c094cd6: /* original 8801, guest PC 0x0c094cd6 */
if(!s->budget--) { s->failed_pc=0x0c094cd6u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c094cd8;
P_0c094cd8: /* original 8d0a, guest PC 0x0c094cd8 */
if(!s->budget--) { s->failed_pc=0x0c094cd8u; return 0; }
cond=r[17]&1u;
r[4]=r[0];
if(cond) { goto P_0c094cf0; }
goto P_0c094cdc;
P_0c094cda: /* original 6403, guest PC 0x0c094cda */
if(!s->budget--) { s->failed_pc=0x0c094cdau; return 0; }
r[4]=r[0];
goto P_0c094cdc;
P_0c094cdc: /* original 50ed, guest PC 0x0c094cdc */
if(!s->budget--) { s->failed_pc=0x0c094cdcu; return 0; }
r[0]=read(ram,r[14]+52,4);
goto P_0c094cde;
P_0c094cde: /* original 881c, guest PC 0x0c094cde */
if(!s->budget--) { s->failed_pc=0x0c094cdeu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000001cu)!=0);
goto P_0c094ce0;
P_0c094ce0: /* original 8f06, guest PC 0x0c094ce0 */
if(!s->budget--) { s->failed_pc=0x0c094ce0u; return 0; }
cond=r[17]&1u;
r[4]=r[0];
if(!cond) { goto P_0c094cf0; }
goto P_0c094ce4;
P_0c094ce2: /* original 6403, guest PC 0x0c094ce2 */
if(!s->budget--) { s->failed_pc=0x0c094ce2u; return 0; }
r[4]=r[0];
goto P_0c094ce4;
P_0c094ce4: /* original 905c, guest PC 0x0c094ce4 */
if(!s->budget--) { s->failed_pc=0x0c094ce4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c094da0u,2);
goto P_0c094ce6;
P_0c094ce6: /* original 04ec, guest PC 0x0c094ce6 */
if(!s->budget--) { s->failed_pc=0x0c094ce6u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c094ce8;
P_0c094ce8: /* original 2448, guest PC 0x0c094ce8 */
if(!s->budget--) { s->failed_pc=0x0c094ce8u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c094cea;
P_0c094cea: /* original 8901, guest PC 0x0c094cea */
if(!s->budget--) { s->failed_pc=0x0c094ceau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c094cf0; }
goto P_0c094cec;
P_0c094cec: /* original e300, guest PC 0x0c094cec */
if(!s->budget--) { s->failed_pc=0x0c094cecu; return 0; }
r[3]=0x00000000u;
goto P_0c094cee;
P_0c094cee: /* original 0e34, guest PC 0x0c094cee */
if(!s->budget--) { s->failed_pc=0x0c094ceeu; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c094cf0;
P_0c094cf0: /* original 9057, guest PC 0x0c094cf0 */
if(!s->budget--) { s->failed_pc=0x0c094cf0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c094da2u,2);
goto P_0c094cf2;
P_0c094cf2: /* original f39d, guest PC 0x0c094cf2 */
if(!s->budget--) { s->failed_pc=0x0c094cf2u; return 0; }
fr[3]=0x3f800000u;
goto P_0c094cf4;
P_0c094cf4: /* original f2e6, guest PC 0x0c094cf4 */
if(!s->budget--) { s->failed_pc=0x0c094cf4u; return 0; }
vf3_matrix_load(s,ram,2,r[14]+r[0]);
goto P_0c094cf6;
P_0c094cf6: /* original f325, guest PC 0x0c094cf6 */
if(!s->budget--) { s->failed_pc=0x0c094cf6u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[2]))!=0);
goto P_0c094cf8;
P_0c094cf8: /* original 8905, guest PC 0x0c094cf8 */
if(!s->budget--) { s->failed_pc=0x0c094cf8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c094d06; }
goto P_0c094cfa;
P_0c094cfa: /* original be3a, guest PC 0x0c094cfa */
if(!s->budget--) { s->failed_pc=0x0c094cfau; return 0; }
target=0x0c094972u; r[16]=0x0c094cfeu;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c094cfeu) { target=s->pc; goto dispatch; }
goto P_0c094cfe;
P_0c094cfc: /* original 64e3, guest PC 0x0c094cfc */
if(!s->budget--) { s->failed_pc=0x0c094cfcu; return 0; }
r[4]=r[14];
goto P_0c094cfe;
P_0c094cfe: /* original d329, guest PC 0x0c094cfe */
if(!s->budget--) { s->failed_pc=0x0c094cfeu; return 0; }
r[3]=read(ram,0x0c094da4u,4);
goto P_0c094d00;
P_0c094d00: /* original 6403, guest PC 0x0c094d00 */
if(!s->budget--) { s->failed_pc=0x0c094d00u; return 0; }
r[4]=r[0];
goto P_0c094d02;
P_0c094d02: /* original 2438, guest PC 0x0c094d02 */
if(!s->budget--) { s->failed_pc=0x0c094d02u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[3])==0)!=0);
goto P_0c094d04;
P_0c094d04: /* original 8944, guest PC 0x0c094d04 */
if(!s->budget--) { s->failed_pc=0x0c094d04u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c094d90; }
goto P_0c094d06;
P_0c094d06: /* original e070, guest PC 0x0c094d06 */
if(!s->budget--) { s->failed_pc=0x0c094d06u; return 0; }
r[0]=0x00000070u;
goto P_0c094d08;
P_0c094d08: /* original 05ee, guest PC 0x0c094d08 */
if(!s->budget--) { s->failed_pc=0x0c094d08u; return 0; }
r[5]=read(ram,r[14]+r[0],4);
goto P_0c094d0a;
P_0c094d0a: /* original e07c, guest PC 0x0c094d0a */
if(!s->budget--) { s->failed_pc=0x0c094d0au; return 0; }
r[0]=0x0000007cu;
goto P_0c094d0c;
P_0c094d0c: /* original 06ee, guest PC 0x0c094d0c */
if(!s->budget--) { s->failed_pc=0x0c094d0cu; return 0; }
r[6]=read(ram,r[14]+r[0],4);
goto P_0c094d0e;
P_0c094d0e: /* original e074, guest PC 0x0c094d0e */
if(!s->budget--) { s->failed_pc=0x0c094d0eu; return 0; }
r[0]=0x00000074u;
goto P_0c094d10;
P_0c094d10: /* original 04ee, guest PC 0x0c094d10 */
if(!s->budget--) { s->failed_pc=0x0c094d10u; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c094d12;
P_0c094d12: /* original 7018, guest PC 0x0c094d12 */
if(!s->budget--) { s->failed_pc=0x0c094d12u; return 0; }
r[0]+=0x00000018u;
goto P_0c094d14;
P_0c094d14: /* original f5e6, guest PC 0x0c094d14 */
if(!s->budget--) { s->failed_pc=0x0c094d14u; return 0; }
vf3_matrix_load(s,ram,5,r[14]+r[0]);
goto P_0c094d16;
P_0c094d16: /* original 7004, guest PC 0x0c094d16 */
if(!s->budget--) { s->failed_pc=0x0c094d16u; return 0; }
r[0]+=0x00000004u;
goto P_0c094d18;
P_0c094d18: /* original f3e6, guest PC 0x0c094d18 */
if(!s->budget--) { s->failed_pc=0x0c094d18u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c094d1a;
P_0c094d1a: /* original f45c, guest PC 0x0c094d1a */
if(!s->budget--) { s->failed_pc=0x0c094d1au; return 0; }
vf3_matrix_move(s,4,5);
goto P_0c094d1c;
P_0c094d1c: /* original f430, guest PC 0x0c094d1c */
if(!s->budget--) { s->failed_pc=0x0c094d1cu; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'+');
goto P_0c094d1e;
P_0c094d1e: /* original f59d, guest PC 0x0c094d1e */
if(!s->budget--) { s->failed_pc=0x0c094d1eu; return 0; }
fr[5]=0x3f800000u;
goto P_0c094d20;
P_0c094d20: /* original f455, guest PC 0x0c094d20 */
if(!s->budget--) { s->failed_pc=0x0c094d20u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[4])>as_float(fr[5]))!=0);
goto P_0c094d22;
P_0c094d22: /* original 8b00, guest PC 0x0c094d22 */
if(!s->budget--) { s->failed_pc=0x0c094d22u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c094d26; }
goto P_0c094d24;
P_0c094d24: /* original f45c, guest PC 0x0c094d24 */
if(!s->budget--) { s->failed_pc=0x0c094d24u; return 0; }
vf3_matrix_move(s,4,5);
goto P_0c094d26;
P_0c094d26: /* original 903c, guest PC 0x0c094d26 */
if(!s->budget--) { s->failed_pc=0x0c094d26u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c094da2u,2);
goto P_0c094d28;
P_0c094d28: /* original fe47, guest PC 0x0c094d28 */
if(!s->budget--) { s->failed_pc=0x0c094d28u; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c094d2a;
P_0c094d2a: /* original e040, guest PC 0x0c094d2a */
if(!s->budget--) { s->failed_pc=0x0c094d2au; return 0; }
r[0]=0x00000040u;
goto P_0c094d2c;
P_0c094d2c: /* original 00ed, guest PC 0x0c094d2c */
if(!s->budget--) { s->failed_pc=0x0c094d2cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c094d2e;
P_0c094d2e: /* original 8801, guest PC 0x0c094d2e */
if(!s->budget--) { s->failed_pc=0x0c094d2eu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c094d30;
P_0c094d30: /* original 85ef, guest PC 0x0c094d30 */
if(!s->budget--) { s->failed_pc=0x0c094d30u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+30,2);
goto P_0c094d32;
P_0c094d32: /* original 6703, guest PC 0x0c094d32 */
if(!s->budget--) { s->failed_pc=0x0c094d32u; return 0; }
r[7]=r[0];
goto P_0c094d34;
P_0c094d34: /* original 4715, guest PC 0x0c094d34 */
if(!s->budget--) { s->failed_pc=0x0c094d34u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[7]>0)!=0);
goto P_0c094d36;
P_0c094d36: /* original 8f2f, guest PC 0x0c094d36 */
if(!s->budget--) { s->failed_pc=0x0c094d36u; return 0; }
cond=r[17]&1u;
fr[5]=vf3_fpu_binary(fr[5],fr[4],r[18],'-');
if(!cond) { goto P_0c094d98; }
goto P_0c094d3a;
P_0c094d38: /* original f541, guest PC 0x0c094d38 */
if(!s->budget--) { s->failed_pc=0x0c094d38u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[4],r[18],'-');
goto P_0c094d3a;
P_0c094d3a: /* original f759, guest PC 0x0c094d3a */
if(!s->budget--) { s->failed_pc=0x0c094d3au; return 0; }
vf3_matrix_load(s,ram,7,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c094d3c;
P_0c094d3c: /* original f369, guest PC 0x0c094d3c */
if(!s->budget--) { s->failed_pc=0x0c094d3cu; return 0; }
vf3_matrix_load(s,ram,3,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c094d3e;
P_0c094d3e: /* original f752, guest PC 0x0c094d3e */
if(!s->budget--) { s->failed_pc=0x0c094d3eu; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[5],r[18],'*');
goto P_0c094d40;
P_0c094d40: /* original f859, guest PC 0x0c094d40 */
if(!s->budget--) { s->failed_pc=0x0c094d40u; return 0; }
vf3_matrix_load(s,ram,8,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c094d42;
P_0c094d42: /* original f04c, guest PC 0x0c094d42 */
if(!s->budget--) { s->failed_pc=0x0c094d42u; return 0; }
vf3_matrix_move(s,0,4);
goto P_0c094d44;
P_0c094d44: /* original f852, guest PC 0x0c094d44 */
if(!s->budget--) { s->failed_pc=0x0c094d44u; return 0; }
fr[8]=vf3_fpu_binary(fr[8],fr[5],r[18],'*');
goto P_0c094d46;
P_0c094d46: /* original f659, guest PC 0x0c094d46 */
if(!s->budget--) { s->failed_pc=0x0c094d46u; return 0; }
vf3_matrix_load(s,ram,6,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c094d48;
P_0c094d48: /* original f73e, guest PC 0x0c094d48 */
if(!s->budget--) { s->failed_pc=0x0c094d48u; return 0; }
fr[7]=vf3_fpu_mac(fr[0],fr[3],fr[7],r[18]);
goto P_0c094d4a;
P_0c094d4a: /* original f369, guest PC 0x0c094d4a */
if(!s->budget--) { s->failed_pc=0x0c094d4au; return 0; }
vf3_matrix_load(s,ram,3,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c094d4c;
P_0c094d4c: /* original f652, guest PC 0x0c094d4c */
if(!s->budget--) { s->failed_pc=0x0c094d4cu; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[5],r[18],'*');
goto P_0c094d4e;
P_0c094d4e: /* original f83e, guest PC 0x0c094d4e */
if(!s->budget--) { s->failed_pc=0x0c094d4eu; return 0; }
fr[8]=vf3_fpu_mac(fr[0],fr[3],fr[8],r[18]);
goto P_0c094d50;
P_0c094d50: /* original f369, guest PC 0x0c094d50 */
if(!s->budget--) { s->failed_pc=0x0c094d50u; return 0; }
vf3_matrix_load(s,ram,3,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c094d52;
P_0c094d52: /* original f47a, guest PC 0x0c094d52 */
if(!s->budget--) { s->failed_pc=0x0c094d52u; return 0; }
vf3_matrix_store(s,ram,7,r[4]);
goto P_0c094d54;
P_0c094d54: /* original 7404, guest PC 0x0c094d54 */
if(!s->budget--) { s->failed_pc=0x0c094d54u; return 0; }
r[4]+=0x00000004u;
goto P_0c094d56;
P_0c094d56: /* original f63e, guest PC 0x0c094d56 */
if(!s->budget--) { s->failed_pc=0x0c094d56u; return 0; }
fr[6]=vf3_fpu_mac(fr[0],fr[3],fr[6],r[18]);
goto P_0c094d58;
P_0c094d58: /* original f48a, guest PC 0x0c094d58 */
if(!s->budget--) { s->failed_pc=0x0c094d58u; return 0; }
vf3_matrix_store(s,ram,8,r[4]);
goto P_0c094d5a;
P_0c094d5a: /* original 7404, guest PC 0x0c094d5a */
if(!s->budget--) { s->failed_pc=0x0c094d5au; return 0; }
r[4]+=0x00000004u;
goto P_0c094d5c;
P_0c094d5c: /* original f46a, guest PC 0x0c094d5c */
if(!s->budget--) { s->failed_pc=0x0c094d5cu; return 0; }
vf3_matrix_store(s,ram,6,r[4]);
goto P_0c094d5e;
P_0c094d5e: /* original 7404, guest PC 0x0c094d5e */
if(!s->budget--) { s->failed_pc=0x0c094d5eu; return 0; }
r[4]+=0x00000004u;
goto P_0c094d60;
P_0c094d60: /* original f759, guest PC 0x0c094d60 */
if(!s->budget--) { s->failed_pc=0x0c094d60u; return 0; }
vf3_matrix_load(s,ram,7,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c094d62;
P_0c094d62: /* original f369, guest PC 0x0c094d62 */
if(!s->budget--) { s->failed_pc=0x0c094d62u; return 0; }
vf3_matrix_load(s,ram,3,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c094d64;
P_0c094d64: /* original f752, guest PC 0x0c094d64 */
if(!s->budget--) { s->failed_pc=0x0c094d64u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[5],r[18],'*');
goto P_0c094d66;
P_0c094d66: /* original f859, guest PC 0x0c094d66 */
if(!s->budget--) { s->failed_pc=0x0c094d66u; return 0; }
vf3_matrix_load(s,ram,8,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c094d68;
P_0c094d68: /* original f852, guest PC 0x0c094d68 */
if(!s->budget--) { s->failed_pc=0x0c094d68u; return 0; }
fr[8]=vf3_fpu_binary(fr[8],fr[5],r[18],'*');
goto P_0c094d6a;
P_0c094d6a: /* original f659, guest PC 0x0c094d6a */
if(!s->budget--) { s->failed_pc=0x0c094d6au; return 0; }
vf3_matrix_load(s,ram,6,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c094d6c;
P_0c094d6c: /* original f73e, guest PC 0x0c094d6c */
if(!s->budget--) { s->failed_pc=0x0c094d6cu; return 0; }
fr[7]=vf3_fpu_mac(fr[0],fr[3],fr[7],r[18]);
goto P_0c094d6e;
P_0c094d6e: /* original f369, guest PC 0x0c094d6e */
if(!s->budget--) { s->failed_pc=0x0c094d6eu; return 0; }
vf3_matrix_load(s,ram,3,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c094d70;
P_0c094d70: /* original f652, guest PC 0x0c094d70 */
if(!s->budget--) { s->failed_pc=0x0c094d70u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[5],r[18],'*');
goto P_0c094d72;
P_0c094d72: /* original f83e, guest PC 0x0c094d72 */
if(!s->budget--) { s->failed_pc=0x0c094d72u; return 0; }
fr[8]=vf3_fpu_mac(fr[0],fr[3],fr[8],r[18]);
goto P_0c094d74;
P_0c094d74: /* original f369, guest PC 0x0c094d74 */
if(!s->budget--) { s->failed_pc=0x0c094d74u; return 0; }
vf3_matrix_load(s,ram,3,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c094d76;
P_0c094d76: /* original f47a, guest PC 0x0c094d76 */
if(!s->budget--) { s->failed_pc=0x0c094d76u; return 0; }
vf3_matrix_store(s,ram,7,r[4]);
goto P_0c094d78;
P_0c094d78: /* original f63e, guest PC 0x0c094d78 */
if(!s->budget--) { s->failed_pc=0x0c094d78u; return 0; }
fr[6]=vf3_fpu_mac(fr[0],fr[3],fr[6],r[18]);
goto P_0c094d7a;
P_0c094d7a: /* original 7404, guest PC 0x0c094d7a */
if(!s->budget--) { s->failed_pc=0x0c094d7au; return 0; }
r[4]+=0x00000004u;
goto P_0c094d7c;
P_0c094d7c: /* original f48a, guest PC 0x0c094d7c */
if(!s->budget--) { s->failed_pc=0x0c094d7cu; return 0; }
vf3_matrix_store(s,ram,8,r[4]);
goto P_0c094d7e;
P_0c094d7e: /* original 77ff, guest PC 0x0c094d7e */
if(!s->budget--) { s->failed_pc=0x0c094d7eu; return 0; }
r[7]+=0xffffffffu;
goto P_0c094d80;
P_0c094d80: /* original 7404, guest PC 0x0c094d80 */
if(!s->budget--) { s->failed_pc=0x0c094d80u; return 0; }
r[4]+=0x00000004u;
goto P_0c094d82;
P_0c094d82: /* original 4715, guest PC 0x0c094d82 */
if(!s->budget--) { s->failed_pc=0x0c094d82u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[7]>0)!=0);
goto P_0c094d84;
P_0c094d84: /* original f46a, guest PC 0x0c094d84 */
if(!s->budget--) { s->failed_pc=0x0c094d84u; return 0; }
vf3_matrix_store(s,ram,6,r[4]);
goto P_0c094d86;
P_0c094d86: /* original 8dd8, guest PC 0x0c094d86 */
if(!s->budget--) { s->failed_pc=0x0c094d86u; return 0; }
cond=r[17]&1u;
r[4]+=0x00000004u;
if(cond) { goto P_0c094d3a; }
goto P_0c094d8a;
P_0c094d88: /* original 7404, guest PC 0x0c094d88 */
if(!s->budget--) { s->failed_pc=0x0c094d88u; return 0; }
r[4]+=0x00000004u;
goto P_0c094d8a;
P_0c094d8a: /* original 4f26, guest PC 0x0c094d8a */
if(!s->budget--) { s->failed_pc=0x0c094d8au; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c094d8c;
P_0c094d8c: /* original 000b, guest PC 0x0c094d8c */
if(!s->budget--) { s->failed_pc=0x0c094d8cu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c094d8e: /* original 6ef6, guest PC 0x0c094d8e */
if(!s->budget--) { s->failed_pc=0x0c094d8eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c094d90;
P_0c094d90: /* original 62e2, guest PC 0x0c094d90 */
if(!s->budget--) { s->failed_pc=0x0c094d90u; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c094d92;
P_0c094d92: /* original e3fe, guest PC 0x0c094d92 */
if(!s->budget--) { s->failed_pc=0x0c094d92u; return 0; }
r[3]=0xfffffffeu;
goto P_0c094d94;
P_0c094d94: /* original 2239, guest PC 0x0c094d94 */
if(!s->budget--) { s->failed_pc=0x0c094d94u; return 0; }
r[2]&=r[3];
goto P_0c094d96;
P_0c094d96: /* original 2e22, guest PC 0x0c094d96 */
if(!s->budget--) { s->failed_pc=0x0c094d96u; return 0; }
write(ram,r[14],r[2],4);
goto P_0c094d98;
P_0c094d98: /* original 4f26, guest PC 0x0c094d98 */
if(!s->budget--) { s->failed_pc=0x0c094d98u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c094d9a;
P_0c094d9a: /* original 000b, guest PC 0x0c094d9a */
if(!s->budget--) { s->failed_pc=0x0c094d9au; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c094d9c: /* original 6ef6, guest PC 0x0c094d9c */
if(!s->budget--) { s->failed_pc=0x0c094d9cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c094d9eu,s,ram);
P_0c09514a: /* original 4f22, guest PC 0x0c09514a */
if(!s->budget--) { s->failed_pc=0x0c09514au; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c09514c;
P_0c09514c: /* original 3c5c, guest PC 0x0c09514c */
if(!s->budget--) { s->failed_pc=0x0c09514cu; return 0; }
r[12]+=r[5];
goto P_0c09514e;
P_0c09514e: /* original 6ec3, guest PC 0x0c09514e */
if(!s->budget--) { s->failed_pc=0x0c09514eu; return 0; }
r[14]=r[12];
goto P_0c095150;
P_0c095150: /* original 3e5c, guest PC 0x0c095150 */
if(!s->budget--) { s->failed_pc=0x0c095150u; return 0; }
r[14]+=r[5];
goto P_0c095152;
P_0c095152: /* original 6de3, guest PC 0x0c095152 */
if(!s->budget--) { s->failed_pc=0x0c095152u; return 0; }
r[13]=r[14];
goto P_0c095154;
P_0c095154: /* original 3d5c, guest PC 0x0c095154 */
if(!s->budget--) { s->failed_pc=0x0c095154u; return 0; }
r[13]+=r[5];
goto P_0c095156;
P_0c095156: /* original 35dc, guest PC 0x0c095156 */
if(!s->budget--) { s->failed_pc=0x0c095156u; return 0; }
r[5]+=r[13];
goto P_0c095158;
P_0c095158: /* original 7ffc, guest PC 0x0c095158 */
if(!s->budget--) { s->failed_pc=0x0c095158u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c09515a;
P_0c09515a: /* original bdb7, guest PC 0x0c09515a */
if(!s->budget--) { s->failed_pc=0x0c09515au; return 0; }
target=0x0c094cccu; r[16]=0x0c09515eu;
write(ram,r[15],r[5],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09515eu) { target=s->pc; goto dispatch; }
goto P_0c09515e;
P_0c09515c: /* original 2f52, guest PC 0x0c09515c */
if(!s->budget--) { s->failed_pc=0x0c09515cu; return 0; }
write(ram,r[15],r[5],4);
goto P_0c09515e;
P_0c09515e: /* original bdb5, guest PC 0x0c09515e */
if(!s->budget--) { s->failed_pc=0x0c09515eu; return 0; }
target=0x0c094cccu; r[16]=0x0c095162u;
r[4]=r[12];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c095162u) { target=s->pc; goto dispatch; }
goto P_0c095162;
P_0c095160: /* original 64c3, guest PC 0x0c095160 */
if(!s->budget--) { s->failed_pc=0x0c095160u; return 0; }
r[4]=r[12];
goto P_0c095162;
P_0c095162: /* original bdb3, guest PC 0x0c095162 */
if(!s->budget--) { s->failed_pc=0x0c095162u; return 0; }
target=0x0c094cccu; r[16]=0x0c095166u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c095166u) { target=s->pc; goto dispatch; }
goto P_0c095166;
P_0c095164: /* original 64e3, guest PC 0x0c095164 */
if(!s->budget--) { s->failed_pc=0x0c095164u; return 0; }
r[4]=r[14];
goto P_0c095166;
P_0c095166: /* original bdb1, guest PC 0x0c095166 */
if(!s->budget--) { s->failed_pc=0x0c095166u; return 0; }
target=0x0c094cccu; r[16]=0x0c09516au;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09516au) { target=s->pc; goto dispatch; }
goto P_0c09516a;
P_0c095168: /* original 64d3, guest PC 0x0c095168 */
if(!s->budget--) { s->failed_pc=0x0c095168u; return 0; }
r[4]=r[13];
goto P_0c09516a;
P_0c09516a: /* original 64f2, guest PC 0x0c09516a */
if(!s->budget--) { s->failed_pc=0x0c09516au; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c09516c;
P_0c09516c: /* original 7f04, guest PC 0x0c09516c */
if(!s->budget--) { s->failed_pc=0x0c09516cu; return 0; }
r[15]+=0x00000004u;
goto P_0c09516e;
P_0c09516e: /* original 4f26, guest PC 0x0c09516e */
if(!s->budget--) { s->failed_pc=0x0c09516eu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c095170;
P_0c095170: /* original 6cf6, guest PC 0x0c095170 */
if(!s->budget--) { s->failed_pc=0x0c095170u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c095172;
P_0c095172: /* original 6df6, guest PC 0x0c095172 */
if(!s->budget--) { s->failed_pc=0x0c095172u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c095174;
P_0c095174: /* original adaa, guest PC 0x0c095174 */
if(!s->budget--) { s->failed_pc=0x0c095174u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c094ccc;
P_0c095176: /* original 6ef6, guest PC 0x0c095176 */
if(!s->budget--) { s->failed_pc=0x0c095176u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c095178u,s,ram);
P_0c0a028a: /* original 4f22, guest PC 0x0c0a028a */
if(!s->budget--) { s->failed_pc=0x0c0a028au; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0a028c;
P_0c0a028c: /* original d32f, guest PC 0x0c0a028c */
if(!s->budget--) { s->failed_pc=0x0c0a028cu; return 0; }
r[3]=read(ram,0x0c0a034cu,4);
goto P_0c0a028e;
P_0c0a028e: /* original de2e, guest PC 0x0c0a028e */
if(!s->budget--) { s->failed_pc=0x0c0a028eu; return 0; }
r[14]=read(ram,0x0c0a0348u,4);
goto P_0c0a0290;
P_0c0a0290: /* original 7ff8, guest PC 0x0c0a0290 */
if(!s->budget--) { s->failed_pc=0x0c0a0290u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c0a0292;
P_0c0a0292: /* original 1f31, guest PC 0x0c0a0292 */
if(!s->budget--) { s->failed_pc=0x0c0a0292u; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c0a0294;
P_0c0a0294: /* original e307, guest PC 0x0c0a0294 */
if(!s->budget--) { s->failed_pc=0x0c0a0294u; return 0; }
r[3]=0x00000007u;
goto P_0c0a0296;
P_0c0a0296: /* original d22e, guest PC 0x0c0a0296 */
if(!s->budget--) { s->failed_pc=0x0c0a0296u; return 0; }
r[2]=read(ram,0x0c0a0350u,4);
goto P_0c0a0298;
P_0c0a0298: /* original 6422, guest PC 0x0c0a0298 */
if(!s->budget--) { s->failed_pc=0x0c0a0298u; return 0; }
tmp=read(ram,r[2],4);
r[4]=tmp;
goto P_0c0a029a;
P_0c0a029a: /* original 3c48, guest PC 0x0c0a029a */
if(!s->budget--) { s->failed_pc=0x0c0a029au; return 0; }
r[12]-=r[4];
goto P_0c0a029c;
P_0c0a029c: /* original 2fc2, guest PC 0x0c0a029c */
if(!s->budget--) { s->failed_pc=0x0c0a029cu; return 0; }
write(ram,r[15],r[12],4);
goto P_0c0a029e;
P_0c0a029e: /* original e428, guest PC 0x0c0a029e */
if(!s->budget--) { s->failed_pc=0x0c0a029eu; return 0; }
r[4]=0x00000028u;
goto P_0c0a02a0;
P_0c0a02a0: /* original d52c, guest PC 0x0c0a02a0 */
if(!s->budget--) { s->failed_pc=0x0c0a02a0u; return 0; }
r[5]=read(ram,0x0c0a0354u,4);
goto P_0c0a02a2;
P_0c0a02a2: /* original 4c3c, guest PC 0x0c0a02a2 */
if(!s->budget--) { s->failed_pc=0x0c0a02a2u; return 0; }
r[12]=(r[3]&0x80000000u)?((r[3]&31u)?(uint32_t)((int32_t)r[12]>>((-r[3])&31u)):((int32_t)r[12]<0?0xffffffffu:0)):r[12]<<(r[3]&31u);
goto P_0c0a02a4;
P_0c0a02a4: /* original d12c, guest PC 0x0c0a02a4 */
if(!s->budget--) { s->failed_pc=0x0c0a02a4u; return 0; }
r[1]=read(ram,0x0c0a0358u,4);
goto P_0c0a02a6;
P_0c0a02a6: /* original 24cb, guest PC 0x0c0a02a6 */
if(!s->budget--) { s->failed_pc=0x0c0a02a6u; return 0; }
r[4]|=r[12];
goto P_0c0a02a8;
P_0c0a02a8: /* original 410b, guest PC 0x0c0a02a8 */
if(!s->budget--) { s->failed_pc=0x0c0a02a8u; return 0; }
target=r[1];
r[16]=0x0c0a02acu;
r[6]=0x00000001u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a02acu) { target=s->pc; goto dispatch; }
goto P_0c0a02ac;
P_0c0a02aa: /* original e601, guest PC 0x0c0a02aa */
if(!s->budget--) { s->failed_pc=0x0c0a02aau; return 0; }
r[6]=0x00000001u;
goto P_0c0a02ac;
P_0c0a02ac: /* original 9041, guest PC 0x0c0a02ac */
if(!s->budget--) { s->failed_pc=0x0c0a02acu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a0332u,2);
goto P_0c0a02ae;
P_0c0a02ae: /* original e41c, guest PC 0x0c0a02ae */
if(!s->budget--) { s->failed_pc=0x0c0a02aeu; return 0; }
r[4]=0x0000001cu;
goto P_0c0a02b0;
P_0c0a02b0: /* original dd2b, guest PC 0x0c0a02b0 */
if(!s->budget--) { s->failed_pc=0x0c0a02b0u; return 0; }
r[13]=read(ram,0x0c0a0360u,4);
goto P_0c0a02b2;
P_0c0a02b2: /* original 24cb, guest PC 0x0c0a02b2 */
if(!s->budget--) { s->failed_pc=0x0c0a02b2u; return 0; }
r[4]|=r[12];
goto P_0c0a02b4;
P_0c0a02b4: /* original 03ec, guest PC 0x0c0a02b4 */
if(!s->budget--) { s->failed_pc=0x0c0a02b4u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0a02b6;
P_0c0a02b6: /* original db29, guest PC 0x0c0a02b6 */
if(!s->budget--) { s->failed_pc=0x0c0a02b6u; return 0; }
r[11]=read(ram,0x0c0a035cu,4);
goto P_0c0a02b8;
P_0c0a02b8: /* original 2f36, guest PC 0x0c0a02b8 */
if(!s->budget--) { s->failed_pc=0x0c0a02b8u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a02ba;
P_0c0a02ba: /* original 4d0b, guest PC 0x0c0a02ba */
if(!s->budget--) { s->failed_pc=0x0c0a02bau; return 0; }
target=r[13];
r[16]=0x0c0a02beu;
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a02beu) { target=s->pc; goto dispatch; }
goto P_0c0a02be;
P_0c0a02bc: /* original 2fb6, guest PC 0x0c0a02bc */
if(!s->budget--) { s->failed_pc=0x0c0a02bcu; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a02be;
P_0c0a02be: /* original 903b, guest PC 0x0c0a02be */
if(!s->budget--) { s->failed_pc=0x0c0a02beu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a0338u,2);
goto P_0c0a02c0;
P_0c0a02c0: /* original e420, guest PC 0x0c0a02c0 */
if(!s->budget--) { s->failed_pc=0x0c0a02c0u; return 0; }
r[4]=0x00000020u;
goto P_0c0a02c2;
P_0c0a02c2: /* original 24cb, guest PC 0x0c0a02c2 */
if(!s->budget--) { s->failed_pc=0x0c0a02c2u; return 0; }
r[4]|=r[12];
goto P_0c0a02c4;
P_0c0a02c4: /* original 03ec, guest PC 0x0c0a02c4 */
if(!s->budget--) { s->failed_pc=0x0c0a02c4u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0a02c6;
P_0c0a02c6: /* original 2f36, guest PC 0x0c0a02c6 */
if(!s->budget--) { s->failed_pc=0x0c0a02c6u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a02c8;
P_0c0a02c8: /* original 4d0b, guest PC 0x0c0a02c8 */
if(!s->budget--) { s->failed_pc=0x0c0a02c8u; return 0; }
target=r[13];
r[16]=0x0c0a02ccu;
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a02ccu) { target=s->pc; goto dispatch; }
goto P_0c0a02cc;
P_0c0a02ca: /* original 2fb6, guest PC 0x0c0a02ca */
if(!s->budget--) { s->failed_pc=0x0c0a02cau; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a02cc;
P_0c0a02cc: /* original 9035, guest PC 0x0c0a02cc */
if(!s->budget--) { s->failed_pc=0x0c0a02ccu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a033au,2);
goto P_0c0a02ce;
P_0c0a02ce: /* original e424, guest PC 0x0c0a02ce */
if(!s->budget--) { s->failed_pc=0x0c0a02ceu; return 0; }
r[4]=0x00000024u;
goto P_0c0a02d0;
P_0c0a02d0: /* original 24cb, guest PC 0x0c0a02d0 */
if(!s->budget--) { s->failed_pc=0x0c0a02d0u; return 0; }
r[4]|=r[12];
goto P_0c0a02d2;
P_0c0a02d2: /* original 03ec, guest PC 0x0c0a02d2 */
if(!s->budget--) { s->failed_pc=0x0c0a02d2u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0a02d4;
P_0c0a02d4: /* original 2f36, guest PC 0x0c0a02d4 */
if(!s->budget--) { s->failed_pc=0x0c0a02d4u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a02d6;
P_0c0a02d6: /* original 4d0b, guest PC 0x0c0a02d6 */
if(!s->budget--) { s->failed_pc=0x0c0a02d6u; return 0; }
target=r[13];
r[16]=0x0c0a02dau;
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a02dau) { target=s->pc; goto dispatch; }
goto P_0c0a02da;
P_0c0a02d8: /* original 2fb6, guest PC 0x0c0a02d8 */
if(!s->budget--) { s->failed_pc=0x0c0a02d8u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a02da;
P_0c0a02da: /* original 902f, guest PC 0x0c0a02da */
if(!s->budget--) { s->failed_pc=0x0c0a02dau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a033cu,2);
goto P_0c0a02dc;
P_0c0a02dc: /* original e428, guest PC 0x0c0a02dc */
if(!s->budget--) { s->failed_pc=0x0c0a02dcu; return 0; }
r[4]=0x00000028u;
goto P_0c0a02de;
P_0c0a02de: /* original 24cb, guest PC 0x0c0a02de */
if(!s->budget--) { s->failed_pc=0x0c0a02deu; return 0; }
r[4]|=r[12];
goto P_0c0a02e0;
P_0c0a02e0: /* original 03ec, guest PC 0x0c0a02e0 */
if(!s->budget--) { s->failed_pc=0x0c0a02e0u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0a02e2;
P_0c0a02e2: /* original 2f36, guest PC 0x0c0a02e2 */
if(!s->budget--) { s->failed_pc=0x0c0a02e2u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a02e4;
P_0c0a02e4: /* original 4d0b, guest PC 0x0c0a02e4 */
if(!s->budget--) { s->failed_pc=0x0c0a02e4u; return 0; }
target=r[13];
r[16]=0x0c0a02e8u;
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a02e8u) { target=s->pc; goto dispatch; }
goto P_0c0a02e8;
P_0c0a02e6: /* original 2fb6, guest PC 0x0c0a02e6 */
if(!s->budget--) { s->failed_pc=0x0c0a02e6u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a02e8;
P_0c0a02e8: /* original 9029, guest PC 0x0c0a02e8 */
if(!s->budget--) { s->failed_pc=0x0c0a02e8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a033eu,2);
goto P_0c0a02ea;
P_0c0a02ea: /* original e307, guest PC 0x0c0a02ea */
if(!s->budget--) { s->failed_pc=0x0c0a02eau; return 0; }
r[3]=0x00000007u;
goto P_0c0a02ec;
P_0c0a02ec: /* original e601, guest PC 0x0c0a02ec */
if(!s->budget--) { s->failed_pc=0x0c0a02ecu; return 0; }
r[6]=0x00000001u;
goto P_0c0a02ee;
P_0c0a02ee: /* original 04ec, guest PC 0x0c0a02ee */
if(!s->budget--) { s->failed_pc=0x0c0a02eeu; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0a02f0;
P_0c0a02f0: /* original d01c, guest PC 0x0c0a02f0 */
if(!s->budget--) { s->failed_pc=0x0c0a02f0u; return 0; }
r[0]=read(ram,0x0c0a0364u,4);
goto P_0c0a02f2;
P_0c0a02f2: /* original 044c, guest PC 0x0c0a02f2 */
if(!s->budget--) { s->failed_pc=0x0c0a02f2u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c0a02f4;
P_0c0a02f4: /* original 9024, guest PC 0x0c0a02f4 */
if(!s->budget--) { s->failed_pc=0x0c0a02f4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a0340u,2);
goto P_0c0a02f6;
P_0c0a02f6: /* original 0e44, guest PC 0x0c0a02f6 */
if(!s->budget--) { s->failed_pc=0x0c0a02f6u; return 0; }
write(ram,r[14]+r[0],r[4],1);
goto P_0c0a02f8;
P_0c0a02f8: /* original 70f9, guest PC 0x0c0a02f8 */
if(!s->budget--) { s->failed_pc=0x0c0a02f8u; return 0; }
r[0]+=0xfffffff9u;
goto P_0c0a02fa;
P_0c0a02fa: /* original 04ec, guest PC 0x0c0a02fa */
if(!s->budget--) { s->failed_pc=0x0c0a02fau; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0a02fc;
P_0c0a02fc: /* original 52f8, guest PC 0x0c0a02fc */
if(!s->budget--) { s->failed_pc=0x0c0a02fcu; return 0; }
r[2]=read(ram,r[15]+32,4);
goto P_0c0a02fe;
P_0c0a02fe: /* original 4400, guest PC 0x0c0a02fe */
if(!s->budget--) { s->failed_pc=0x0c0a02feu; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c0a0300;
P_0c0a0300: /* original 951e, guest PC 0x0c0a0300 */
if(!s->budget--) { s->failed_pc=0x0c0a0300u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a0340u,2);
goto P_0c0a0302;
P_0c0a0302: /* original 740e, guest PC 0x0c0a0302 */
if(!s->budget--) { s->failed_pc=0x0c0a0302u; return 0; }
r[4]+=0x0000000eu;
goto P_0c0a0304;
P_0c0a0304: /* original 423c, guest PC 0x0c0a0304 */
if(!s->budget--) { s->failed_pc=0x0c0a0304u; return 0; }
r[2]=(r[3]&0x80000000u)?((r[3]&31u)?(uint32_t)((int32_t)r[2]>>((-r[3])&31u)):((int32_t)r[2]<0?0xffffffffu:0)):r[2]<<(r[3]&31u);
goto P_0c0a0306;
P_0c0a0306: /* original 4400, guest PC 0x0c0a0306 */
if(!s->budget--) { s->failed_pc=0x0c0a0306u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c0a0308;
P_0c0a0308: /* original 242b, guest PC 0x0c0a0308 */
if(!s->budget--) { s->failed_pc=0x0c0a0308u; return 0; }
r[4]|=r[2];
goto P_0c0a030a;
P_0c0a030a: /* original d213, guest PC 0x0c0a030a */
if(!s->budget--) { s->failed_pc=0x0c0a030au; return 0; }
r[2]=read(ram,0x0c0a0358u,4);
goto P_0c0a030c;
P_0c0a030c: /* original 420b, guest PC 0x0c0a030c */
if(!s->budget--) { s->failed_pc=0x0c0a030cu; return 0; }
target=r[2];
r[16]=0x0c0a0310u;
r[5]+=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a0310u) { target=s->pc; goto dispatch; }
goto P_0c0a0310;
P_0c0a030e: /* original 35ec, guest PC 0x0c0a030e */
if(!s->budget--) { s->failed_pc=0x0c0a030eu; return 0; }
r[5]+=r[14];
goto P_0c0a0310;
P_0c0a0310: /* original 55f9, guest PC 0x0c0a0310 */
if(!s->budget--) { s->failed_pc=0x0c0a0310u; return 0; }
r[5]=read(ram,r[15]+36,4);
goto P_0c0a0312;
P_0c0a0312: /* original e3fa, guest PC 0x0c0a0312 */
if(!s->budget--) { s->failed_pc=0x0c0a0312u; return 0; }
r[3]=0xfffffffau;
goto P_0c0a0314;
P_0c0a0314: /* original 9415, guest PC 0x0c0a0314 */
if(!s->budget--) { s->failed_pc=0x0c0a0314u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a0342u,2);
goto P_0c0a0316;
P_0c0a0316: /* original 5553, guest PC 0x0c0a0316 */
if(!s->budget--) { s->failed_pc=0x0c0a0316u; return 0; }
r[5]=read(ram,r[5]+12,4);
goto P_0c0a0318;
P_0c0a0318: /* original 453c, guest PC 0x0c0a0318 */
if(!s->budget--) { s->failed_pc=0x0c0a0318u; return 0; }
r[5]=(r[3]&0x80000000u)?((r[3]&31u)?(uint32_t)((int32_t)r[5]>>((-r[3])&31u)):((int32_t)r[5]<0?0xffffffffu:0)):r[5]<<(r[3]&31u);
goto P_0c0a031a;
P_0c0a031a: /* original 2f56, guest PC 0x0c0a031a */
if(!s->budget--) { s->failed_pc=0x0c0a031au; return 0; }
tmp=r[5]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a031c;
P_0c0a031c: /* original d212, guest PC 0x0c0a031c */
if(!s->budget--) { s->failed_pc=0x0c0a031cu; return 0; }
r[2]=read(ram,0x0c0a0368u,4);
goto P_0c0a031e;
P_0c0a031e: /* original 4d0b, guest PC 0x0c0a031e */
if(!s->budget--) { s->failed_pc=0x0c0a031eu; return 0; }
target=r[13];
r[16]=0x0c0a0322u;
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a0322u) { target=s->pc; goto dispatch; }
goto P_0c0a0322;
P_0c0a0320: /* original 2f26, guest PC 0x0c0a0320 */
if(!s->budget--) { s->failed_pc=0x0c0a0320u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a0322;
P_0c0a0322: /* original 7f30, guest PC 0x0c0a0322 */
if(!s->budget--) { s->failed_pc=0x0c0a0322u; return 0; }
r[15]+=0x00000030u;
goto P_0c0a0324;
P_0c0a0324: /* original 4f26, guest PC 0x0c0a0324 */
if(!s->budget--) { s->failed_pc=0x0c0a0324u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a0326;
P_0c0a0326: /* original 6bf6, guest PC 0x0c0a0326 */
if(!s->budget--) { s->failed_pc=0x0c0a0326u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0a0328;
P_0c0a0328: /* original 6cf6, guest PC 0x0c0a0328 */
if(!s->budget--) { s->failed_pc=0x0c0a0328u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0a032a;
P_0c0a032a: /* original 6df6, guest PC 0x0c0a032a */
if(!s->budget--) { s->failed_pc=0x0c0a032au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0a032c;
P_0c0a032c: /* original 000b, guest PC 0x0c0a032c */
if(!s->budget--) { s->failed_pc=0x0c0a032cu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0a032e: /* original 6ef6, guest PC 0x0c0a032e */
if(!s->budget--) { s->failed_pc=0x0c0a032eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0a0330u,s,ram);
P_0c0a036c: /* original 2fe6, guest PC 0x0c0a036c */
if(!s->budget--) { s->failed_pc=0x0c0a036cu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a036e;
P_0c0a036e: /* original e606, guest PC 0x0c0a036e */
if(!s->budget--) { s->failed_pc=0x0c0a036eu; return 0; }
r[6]=0x00000006u;
goto P_0c0a0370;
P_0c0a0370: /* original 2fd6, guest PC 0x0c0a0370 */
if(!s->budget--) { s->failed_pc=0x0c0a0370u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a0372;
P_0c0a0372: /* original e700, guest PC 0x0c0a0372 */
if(!s->budget--) { s->failed_pc=0x0c0a0372u; return 0; }
r[7]=0x00000000u;
goto P_0c0a0374;
P_0c0a0374: /* original 2fc6, guest PC 0x0c0a0374 */
if(!s->budget--) { s->failed_pc=0x0c0a0374u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a0376;
P_0c0a0376: /* original 2fb6, guest PC 0x0c0a0376 */
if(!s->budget--) { s->failed_pc=0x0c0a0376u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a0378;
P_0c0a0378: /* original d433, guest PC 0x0c0a0378 */
if(!s->budget--) { s->failed_pc=0x0c0a0378u; return 0; }
r[4]=read(ram,0x0c0a0448u,4);
goto P_0c0a037a;
P_0c0a037a: /* original 9063, guest PC 0x0c0a037a */
if(!s->budget--) { s->failed_pc=0x0c0a037au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a0444u,2);
goto P_0c0a037c;
P_0c0a037c: /* original 4f22, guest PC 0x0c0a037c */
if(!s->budget--) { s->failed_pc=0x0c0a037cu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0a037e;
P_0c0a037e: /* original 054c, guest PC 0x0c0a037e */
if(!s->budget--) { s->failed_pc=0x0c0a037eu; return 0; }
r[5]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c0a0380;
P_0c0a0380: /* original dc32, guest PC 0x0c0a0380 */
if(!s->budget--) { s->failed_pc=0x0c0a0380u; return 0; }
r[12]=read(ram,0x0c0a044cu,4);
goto P_0c0a0382;
P_0c0a0382: /* original 3563, guest PC 0x0c0a0382 */
if(!s->budget--) { s->failed_pc=0x0c0a0382u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[5]>=(int32_t)r[6])!=0);
goto P_0c0a0384;
P_0c0a0384: /* original 8f08, guest PC 0x0c0a0384 */
if(!s->budget--) { s->failed_pc=0x0c0a0384u; return 0; }
cond=r[17]&1u;
r[14]=r[7];
if(!cond) { goto P_0c0a0398; }
goto P_0c0a0388;
P_0c0a0386: /* original 6e73, guest PC 0x0c0a0386 */
if(!s->budget--) { s->failed_pc=0x0c0a0386u; return 0; }
r[14]=r[7];
goto P_0c0a0388;
P_0c0a0388: /* original e50c, guest PC 0x0c0a0388 */
if(!s->budget--) { s->failed_pc=0x0c0a0388u; return 0; }
r[5]=0x0000000cu;
goto P_0c0a038a;
P_0c0a038a: /* original 6053, guest PC 0x0c0a038a */
if(!s->budget--) { s->failed_pc=0x0c0a038au; return 0; }
r[0]=r[5];
goto P_0c0a038c;
P_0c0a038c: /* original 707c, guest PC 0x0c0a038c */
if(!s->budget--) { s->failed_pc=0x0c0a038cu; return 0; }
r[0]+=0x0000007cu;
goto P_0c0a038e;
P_0c0a038e: /* original 034c, guest PC 0x0c0a038e */
if(!s->budget--) { s->failed_pc=0x0c0a038eu; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c0a0390;
P_0c0a0390: /* original 3353, guest PC 0x0c0a0390 */
if(!s->budget--) { s->failed_pc=0x0c0a0390u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>=(int32_t)r[5])!=0);
goto P_0c0a0392;
P_0c0a0392: /* original 8f01, guest PC 0x0c0a0392 */
if(!s->budget--) { s->failed_pc=0x0c0a0392u; return 0; }
cond=r[17]&1u;
r[14]=r[6];
if(!cond) { goto P_0c0a0398; }
goto P_0c0a0396;
P_0c0a0394: /* original 6e63, guest PC 0x0c0a0394 */
if(!s->budget--) { s->failed_pc=0x0c0a0394u; return 0; }
r[14]=r[6];
goto P_0c0a0396;
P_0c0a0396: /* original 6e53, guest PC 0x0c0a0396 */
if(!s->budget--) { s->failed_pc=0x0c0a0396u; return 0; }
r[14]=r[5];
goto P_0c0a0398;
P_0c0a0398: /* original eb18, guest PC 0x0c0a0398 */
if(!s->budget--) { s->failed_pc=0x0c0a0398u; return 0; }
r[11]=0x00000018u;
goto P_0c0a039a;
P_0c0a039a: /* original a018, guest PC 0x0c0a039a */
if(!s->budget--) { s->failed_pc=0x0c0a039au; return 0; }
r[13]=r[7];
goto P_0c0a03ce;
P_0c0a039c: /* original 6d73, guest PC 0x0c0a039c */
if(!s->budget--) { s->failed_pc=0x0c0a039cu; return 0; }
r[13]=r[7];
goto P_0c0a039e;
P_0c0a039e: /* original 65e3, guest PC 0x0c0a039e */
if(!s->budget--) { s->failed_pc=0x0c0a039eu; return 0; }
r[5]=r[14];
goto P_0c0a03a0;
P_0c0a03a0: /* original b03d, guest PC 0x0c0a03a0 */
if(!s->budget--) { s->failed_pc=0x0c0a03a0u; return 0; }
target=0x0c0a041eu; r[16]=0x0c0a03a4u;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a03a4u) { target=s->pc; goto dispatch; }
goto P_0c0a03a4;
P_0c0a03a2: /* original 64d3, guest PC 0x0c0a03a2 */
if(!s->budget--) { s->failed_pc=0x0c0a03a2u; return 0; }
r[4]=r[13];
goto P_0c0a03a4;
P_0c0a03a4: /* original 65e3, guest PC 0x0c0a03a4 */
if(!s->budget--) { s->failed_pc=0x0c0a03a4u; return 0; }
r[5]=r[14];
goto P_0c0a03a6;
P_0c0a03a6: /* original 63c3, guest PC 0x0c0a03a6 */
if(!s->budget--) { s->failed_pc=0x0c0a03a6u; return 0; }
r[3]=r[12];
goto P_0c0a03a8;
P_0c0a03a8: /* original 4508, guest PC 0x0c0a03a8 */
if(!s->budget--) { s->failed_pc=0x0c0a03a8u; return 0; }
r[5]<<=2;
goto P_0c0a03aa;
P_0c0a03aa: /* original 353c, guest PC 0x0c0a03aa */
if(!s->budget--) { s->failed_pc=0x0c0a03aau; return 0; }
r[5]+=r[3];
goto P_0c0a03ac;
P_0c0a03ac: /* original b056, guest PC 0x0c0a03ac */
if(!s->budget--) { s->failed_pc=0x0c0a03acu; return 0; }
target=0x0c0a045cu; r[16]=0x0c0a03b0u;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a03b0u) { target=s->pc; goto dispatch; }
goto P_0c0a03b0;
P_0c0a03ae: /* original 64d3, guest PC 0x0c0a03ae */
if(!s->budget--) { s->failed_pc=0x0c0a03aeu; return 0; }
r[4]=r[13];
goto P_0c0a03b0;
P_0c0a03b0: /* original 63c3, guest PC 0x0c0a03b0 */
if(!s->budget--) { s->failed_pc=0x0c0a03b0u; return 0; }
r[3]=r[12];
goto P_0c0a03b2;
P_0c0a03b2: /* original 65e3, guest PC 0x0c0a03b2 */
if(!s->budget--) { s->failed_pc=0x0c0a03b2u; return 0; }
r[5]=r[14];
goto P_0c0a03b4;
P_0c0a03b4: /* original 7348, guest PC 0x0c0a03b4 */
if(!s->budget--) { s->failed_pc=0x0c0a03b4u; return 0; }
r[3]+=0x00000048u;
goto P_0c0a03b6;
P_0c0a03b6: /* original 4508, guest PC 0x0c0a03b6 */
if(!s->budget--) { s->failed_pc=0x0c0a03b6u; return 0; }
r[5]<<=2;
goto P_0c0a03b8;
P_0c0a03b8: /* original 353c, guest PC 0x0c0a03b8 */
if(!s->budget--) { s->failed_pc=0x0c0a03b8u; return 0; }
r[5]+=r[3];
goto P_0c0a03ba;
P_0c0a03ba: /* original b08f, guest PC 0x0c0a03ba */
if(!s->budget--) { s->failed_pc=0x0c0a03bau; return 0; }
target=0x0c0a04dcu; r[16]=0x0c0a03beu;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a03beu) { target=s->pc; goto dispatch; }
goto P_0c0a03be;
P_0c0a03bc: /* original 64d3, guest PC 0x0c0a03bc */
if(!s->budget--) { s->failed_pc=0x0c0a03bcu; return 0; }
r[4]=r[13];
goto P_0c0a03be;
P_0c0a03be: /* original 9642, guest PC 0x0c0a03be */
if(!s->budget--) { s->failed_pc=0x0c0a03beu; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a0446u,2);
goto P_0c0a03c0;
P_0c0a03c0: /* original 65e3, guest PC 0x0c0a03c0 */
if(!s->budget--) { s->failed_pc=0x0c0a03c0u; return 0; }
r[5]=r[14];
goto P_0c0a03c2;
P_0c0a03c2: /* original 36cc, guest PC 0x0c0a03c2 */
if(!s->budget--) { s->failed_pc=0x0c0a03c2u; return 0; }
r[6]+=r[12];
goto P_0c0a03c4;
P_0c0a03c4: /* original 36ec, guest PC 0x0c0a03c4 */
if(!s->budget--) { s->failed_pc=0x0c0a03c4u; return 0; }
r[6]+=r[14];
goto P_0c0a03c6;
P_0c0a03c6: /* original b0e1, guest PC 0x0c0a03c6 */
if(!s->budget--) { s->failed_pc=0x0c0a03c6u; return 0; }
target=0x0c0a058cu; r[16]=0x0c0a03cau;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a03cau) { target=s->pc; goto dispatch; }
goto P_0c0a03ca;
P_0c0a03c8: /* original 64d3, guest PC 0x0c0a03c8 */
if(!s->budget--) { s->failed_pc=0x0c0a03c8u; return 0; }
r[4]=r[13];
goto P_0c0a03ca;
P_0c0a03ca: /* original 7e01, guest PC 0x0c0a03ca */
if(!s->budget--) { s->failed_pc=0x0c0a03cau; return 0; }
r[14]+=0x00000001u;
goto P_0c0a03cc;
P_0c0a03cc: /* original 7d04, guest PC 0x0c0a03cc */
if(!s->budget--) { s->failed_pc=0x0c0a03ccu; return 0; }
r[13]+=0x00000004u;
goto P_0c0a03ce;
P_0c0a03ce: /* original 3db3, guest PC 0x0c0a03ce */
if(!s->budget--) { s->failed_pc=0x0c0a03ceu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[13]>=(int32_t)r[11])!=0);
goto P_0c0a03d0;
P_0c0a03d0: /* original 8be5, guest PC 0x0c0a03d0 */
if(!s->budget--) { s->failed_pc=0x0c0a03d0u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a039e; }
goto P_0c0a03d2;
P_0c0a03d2: /* original 4f26, guest PC 0x0c0a03d2 */
if(!s->budget--) { s->failed_pc=0x0c0a03d2u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a03d4;
P_0c0a03d4: /* original 6bf6, guest PC 0x0c0a03d4 */
if(!s->budget--) { s->failed_pc=0x0c0a03d4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0a03d6;
P_0c0a03d6: /* original 6cf6, guest PC 0x0c0a03d6 */
if(!s->budget--) { s->failed_pc=0x0c0a03d6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0a03d8;
P_0c0a03d8: /* original 6df6, guest PC 0x0c0a03d8 */
if(!s->budget--) { s->failed_pc=0x0c0a03d8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0a03da;
P_0c0a03da: /* original 000b, guest PC 0x0c0a03da */
if(!s->budget--) { s->failed_pc=0x0c0a03dau; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0a03dc: /* original 6ef6, guest PC 0x0c0a03dc */
if(!s->budget--) { s->failed_pc=0x0c0a03dcu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0a03deu,s,ram);
P_0c0a03f0: /* original 4f22, guest PC 0x0c0a03f0 */
if(!s->budget--) { s->failed_pc=0x0c0a03f0u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0a03f2;
P_0c0a03f2: /* original 3c58, guest PC 0x0c0a03f2 */
if(!s->budget--) { s->failed_pc=0x0c0a03f2u; return 0; }
r[12]-=r[5];
goto P_0c0a03f4;
P_0c0a03f4: /* original dd15, guest PC 0x0c0a03f4 */
if(!s->budget--) { s->failed_pc=0x0c0a03f4u; return 0; }
r[13]=read(ram,0x0c0a044cu,4);
goto P_0c0a03f6;
P_0c0a03f6: /* original 65e3, guest PC 0x0c0a03f6 */
if(!s->budget--) { s->failed_pc=0x0c0a03f6u; return 0; }
r[5]=r[14];
goto P_0c0a03f8;
P_0c0a03f8: /* original b011, guest PC 0x0c0a03f8 */
if(!s->budget--) { s->failed_pc=0x0c0a03f8u; return 0; }
target=0x0c0a041eu; r[16]=0x0c0a03fcu;
r[4]=r[12];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a03fcu) { target=s->pc; goto dispatch; }
goto P_0c0a03fc;
P_0c0a03fa: /* original 64c3, guest PC 0x0c0a03fa */
if(!s->budget--) { s->failed_pc=0x0c0a03fau; return 0; }
r[4]=r[12];
goto P_0c0a03fc;
P_0c0a03fc: /* original 63d3, guest PC 0x0c0a03fc */
if(!s->budget--) { s->failed_pc=0x0c0a03fcu; return 0; }
r[3]=r[13];
goto P_0c0a03fe;
P_0c0a03fe: /* original 65e3, guest PC 0x0c0a03fe */
if(!s->budget--) { s->failed_pc=0x0c0a03feu; return 0; }
r[5]=r[14];
goto P_0c0a0400;
P_0c0a0400: /* original 7348, guest PC 0x0c0a0400 */
if(!s->budget--) { s->failed_pc=0x0c0a0400u; return 0; }
r[3]+=0x00000048u;
goto P_0c0a0402;
P_0c0a0402: /* original 4508, guest PC 0x0c0a0402 */
if(!s->budget--) { s->failed_pc=0x0c0a0402u; return 0; }
r[5]<<=2;
goto P_0c0a0404;
P_0c0a0404: /* original 353c, guest PC 0x0c0a0404 */
if(!s->budget--) { s->failed_pc=0x0c0a0404u; return 0; }
r[5]+=r[3];
goto P_0c0a0406;
P_0c0a0406: /* original b069, guest PC 0x0c0a0406 */
if(!s->budget--) { s->failed_pc=0x0c0a0406u; return 0; }
target=0x0c0a04dcu; r[16]=0x0c0a040au;
r[4]=r[12];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a040au) { target=s->pc; goto dispatch; }
goto P_0c0a040a;
P_0c0a0408: /* original 64c3, guest PC 0x0c0a0408 */
if(!s->budget--) { s->failed_pc=0x0c0a0408u; return 0; }
r[4]=r[12];
goto P_0c0a040a;
P_0c0a040a: /* original 4f26, guest PC 0x0c0a040a */
if(!s->budget--) { s->failed_pc=0x0c0a040au; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a040c;
P_0c0a040c: /* original 64c3, guest PC 0x0c0a040c */
if(!s->budget--) { s->failed_pc=0x0c0a040cu; return 0; }
r[4]=r[12];
goto P_0c0a040e;
P_0c0a040e: /* original 961a, guest PC 0x0c0a040e */
if(!s->budget--) { s->failed_pc=0x0c0a040eu; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a0446u,2);
goto P_0c0a0410;
P_0c0a0410: /* original 65e3, guest PC 0x0c0a0410 */
if(!s->budget--) { s->failed_pc=0x0c0a0410u; return 0; }
r[5]=r[14];
goto P_0c0a0412;
P_0c0a0412: /* original 6cf6, guest PC 0x0c0a0412 */
if(!s->budget--) { s->failed_pc=0x0c0a0412u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0a0414;
P_0c0a0414: /* original 36dc, guest PC 0x0c0a0414 */
if(!s->budget--) { s->failed_pc=0x0c0a0414u; return 0; }
r[6]+=r[13];
goto P_0c0a0416;
P_0c0a0416: /* original 36ec, guest PC 0x0c0a0416 */
if(!s->budget--) { s->failed_pc=0x0c0a0416u; return 0; }
r[6]+=r[14];
goto P_0c0a0418;
P_0c0a0418: /* original 6df6, guest PC 0x0c0a0418 */
if(!s->budget--) { s->failed_pc=0x0c0a0418u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0a041a;
P_0c0a041a: /* original a0b7, guest PC 0x0c0a041a */
if(!s->budget--) { s->failed_pc=0x0c0a041au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0a058c;
P_0c0a041c: /* original 6ef6, guest PC 0x0c0a041c */
if(!s->budget--) { s->failed_pc=0x0c0a041cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0a041eu,s,ram);
P_0c0a058c: /* original 2fe6, guest PC 0x0c0a058c */
if(!s->budget--) { s->failed_pc=0x0c0a058cu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a058e;
P_0c0a058e: /* original 4f22, guest PC 0x0c0a058e */
if(!s->budget--) { s->failed_pc=0x0c0a058eu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0a0590;
P_0c0a0590: /* original 7ff8, guest PC 0x0c0a0590 */
if(!s->budget--) { s->failed_pc=0x0c0a0590u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c0a0592;
P_0c0a0592: /* original 2f42, guest PC 0x0c0a0592 */
if(!s->budget--) { s->failed_pc=0x0c0a0592u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c0a0594;
P_0c0a0594: /* original 1f61, guest PC 0x0c0a0594 */
if(!s->budget--) { s->failed_pc=0x0c0a0594u; return 0; }
write(ram,r[15]+4,r[6],4);
goto P_0c0a0596;
P_0c0a0596: /* original d312, guest PC 0x0c0a0596 */
if(!s->budget--) { s->failed_pc=0x0c0a0596u; return 0; }
r[3]=read(ram,0x0c0a05e0u,4);
goto P_0c0a0598;
P_0c0a0598: /* original 430b, guest PC 0x0c0a0598 */
if(!s->budget--) { s->failed_pc=0x0c0a0598u; return 0; }
target=r[3];
r[16]=0x0c0a059cu;
r[4]=r[6];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a059cu) { target=s->pc; goto dispatch; }
goto P_0c0a059c;
P_0c0a059a: /* original 6463, guest PC 0x0c0a059a */
if(!s->budget--) { s->failed_pc=0x0c0a059au; return 0; }
r[4]=r[6];
goto P_0c0a059c;
P_0c0a059c: /* original d215, guest PC 0x0c0a059c */
if(!s->budget--) { s->failed_pc=0x0c0a059cu; return 0; }
r[2]=read(ram,0x0c0a05f4u,4);
goto P_0c0a059e;
P_0c0a059e: /* original e40d, guest PC 0x0c0a059e */
if(!s->budget--) { s->failed_pc=0x0c0a059eu; return 0; }
r[4]=0x0000000du;
goto P_0c0a05a0;
P_0c0a05a0: /* original 610c, guest PC 0x0c0a05a0 */
if(!s->budget--) { s->failed_pc=0x0c0a05a0u; return 0; }
r[1]=r[0]&255u;
goto P_0c0a05a2;
P_0c0a05a2: /* original 420b, guest PC 0x0c0a05a2 */
if(!s->budget--) { s->failed_pc=0x0c0a05a2u; return 0; }
target=r[2];
r[16]=0x0c0a05a6u;
r[0]=r[4];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a05a6u) { target=s->pc; goto dispatch; }
goto P_0c0a05a6;
P_0c0a05a4: /* original 6043, guest PC 0x0c0a05a4 */
if(!s->budget--) { s->failed_pc=0x0c0a05a4u; return 0; }
r[0]=r[4];
goto P_0c0a05a6;
P_0c0a05a6: /* original 64f2, guest PC 0x0c0a05a6 */
if(!s->budget--) { s->failed_pc=0x0c0a05a6u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c0a05a8;
P_0c0a05a8: /* original e307, guest PC 0x0c0a05a8 */
if(!s->budget--) { s->failed_pc=0x0c0a05a8u; return 0; }
r[3]=0x00000007u;
goto P_0c0a05aa;
P_0c0a05aa: /* original 6503, guest PC 0x0c0a05aa */
if(!s->budget--) { s->failed_pc=0x0c0a05aau; return 0; }
r[5]=r[0];
goto P_0c0a05ac;
P_0c0a05ac: /* original 6053, guest PC 0x0c0a05ac */
if(!s->budget--) { s->failed_pc=0x0c0a05acu; return 0; }
r[0]=r[5];
goto P_0c0a05ae;
P_0c0a05ae: /* original 740c, guest PC 0x0c0a05ae */
if(!s->budget--) { s->failed_pc=0x0c0a05aeu; return 0; }
r[4]+=0x0000000cu;
goto P_0c0a05b0;
P_0c0a05b0: /* original 8809, guest PC 0x0c0a05b0 */
if(!s->budget--) { s->failed_pc=0x0c0a05b0u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000009u)!=0);
goto P_0c0a05b2;
P_0c0a05b2: /* original e254, guest PC 0x0c0a05b2 */
if(!s->budget--) { s->failed_pc=0x0c0a05b2u; return 0; }
r[2]=0x00000054u;
goto P_0c0a05b4;
P_0c0a05b4: /* original 6e53, guest PC 0x0c0a05b4 */
if(!s->budget--) { s->failed_pc=0x0c0a05b4u; return 0; }
r[14]=r[5];
goto P_0c0a05b6;
P_0c0a05b6: /* original 443c, guest PC 0x0c0a05b6 */
if(!s->budget--) { s->failed_pc=0x0c0a05b6u; return 0; }
r[4]=(r[3]&0x80000000u)?((r[3]&31u)?(uint32_t)((int32_t)r[4]>>((-r[3])&31u)):((int32_t)r[4]<0?0xffffffffu:0)):r[4]<<(r[3]&31u);
goto P_0c0a05b8;
P_0c0a05b8: /* original 242b, guest PC 0x0c0a05b8 */
if(!s->budget--) { s->failed_pc=0x0c0a05b8u; return 0; }
r[4]|=r[2];
goto P_0c0a05ba;
P_0c0a05ba: /* original 8f1f, guest PC 0x0c0a05ba */
if(!s->budget--) { s->failed_pc=0x0c0a05bau; return 0; }
cond=r[17]&1u;
r[14]<<=2;
if(!cond) { goto P_0c0a05fc; }
goto P_0c0a05be;
P_0c0a05bc: /* original 4e08, guest PC 0x0c0a05bc */
if(!s->budget--) { s->failed_pc=0x0c0a05bcu; return 0; }
r[14]<<=2;
goto P_0c0a05be;
P_0c0a05be: /* original 7f08, guest PC 0x0c0a05be */
if(!s->budget--) { s->failed_pc=0x0c0a05beu; return 0; }
r[15]+=0x00000008u;
goto P_0c0a05c0;
P_0c0a05c0: /* original d00d, guest PC 0x0c0a05c0 */
if(!s->budget--) { s->failed_pc=0x0c0a05c0u; return 0; }
r[0]=read(ram,0x0c0a05f8u,4);
goto P_0c0a05c2;
P_0c0a05c2: /* original 4f26, guest PC 0x0c0a05c2 */
if(!s->budget--) { s->failed_pc=0x0c0a05c2u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a05c4;
P_0c0a05c4: /* original d307, guest PC 0x0c0a05c4 */
if(!s->budget--) { s->failed_pc=0x0c0a05c4u; return 0; }
r[3]=read(ram,0x0c0a05e4u,4);
goto P_0c0a05c6;
P_0c0a05c6: /* original e601, guest PC 0x0c0a05c6 */
if(!s->budget--) { s->failed_pc=0x0c0a05c6u; return 0; }
r[6]=0x00000001u;
goto P_0c0a05c8;
P_0c0a05c8: /* original 05ee, guest PC 0x0c0a05c8 */
if(!s->budget--) { s->failed_pc=0x0c0a05c8u; return 0; }
r[5]=read(ram,r[14]+r[0],4);
goto P_0c0a05ca;
P_0c0a05ca: /* original 432b, guest PC 0x0c0a05ca */
if(!s->budget--) { s->failed_pc=0x0c0a05cau; return 0; }
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
P_0c0a05cc: /* original 6ef6, guest PC 0x0c0a05cc */
if(!s->budget--) { s->failed_pc=0x0c0a05ccu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0a05ceu,s,ram);
P_0c0a05fc: /* original d63f, guest PC 0x0c0a05fc */
if(!s->budget--) { s->failed_pc=0x0c0a05fcu; return 0; }
r[6]=read(ram,0x0c0a06fcu,4);
goto P_0c0a05fe;
P_0c0a05fe: /* original e100, guest PC 0x0c0a05fe */
if(!s->budget--) { s->failed_pc=0x0c0a05feu; return 0; }
r[1]=0x00000000u;
goto P_0c0a0600;
P_0c0a0600: /* original 2f16, guest PC 0x0c0a0600 */
if(!s->budget--) { s->failed_pc=0x0c0a0600u; return 0; }
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a0602;
P_0c0a0602: /* original 6713, guest PC 0x0c0a0602 */
if(!s->budget--) { s->failed_pc=0x0c0a0602u; return 0; }
r[7]=r[1];
goto P_0c0a0604;
P_0c0a0604: /* original d33f, guest PC 0x0c0a0604 */
if(!s->budget--) { s->failed_pc=0x0c0a0604u; return 0; }
r[3]=read(ram,0x0c0a0704u,4);
goto P_0c0a0606;
P_0c0a0606: /* original d03e, guest PC 0x0c0a0606 */
if(!s->budget--) { s->failed_pc=0x0c0a0606u; return 0; }
r[0]=read(ram,0x0c0a0700u,4);
goto P_0c0a0608;
P_0c0a0608: /* original 430b, guest PC 0x0c0a0608 */
if(!s->budget--) { s->failed_pc=0x0c0a0608u; return 0; }
target=r[3];
r[16]=0x0c0a060cu;
r[5]=read(ram,r[14]+r[0],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a060cu) { target=s->pc; goto dispatch; }
goto P_0c0a060c;
P_0c0a060a: /* original 05ee, guest PC 0x0c0a060a */
if(!s->budget--) { s->failed_pc=0x0c0a060au; return 0; }
r[5]=read(ram,r[14]+r[0],4);
goto P_0c0a060c;
P_0c0a060c: /* original 7f0c, guest PC 0x0c0a060c */
if(!s->budget--) { s->failed_pc=0x0c0a060cu; return 0; }
r[15]+=0x0000000cu;
goto P_0c0a060e;
P_0c0a060e: /* original 4f26, guest PC 0x0c0a060e */
if(!s->budget--) { s->failed_pc=0x0c0a060eu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a0610;
P_0c0a0610: /* original 000b, guest PC 0x0c0a0610 */
if(!s->budget--) { s->failed_pc=0x0c0a0610u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0a0612: /* original 6ef6, guest PC 0x0c0a0612 */
if(!s->budget--) { s->failed_pc=0x0c0a0612u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0a0614u,s,ram);
P_0c0a7784: /* original 2fe6, guest PC 0x0c0a7784 */
if(!s->budget--) { s->failed_pc=0x0c0a7784u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a7786;
P_0c0a7786: /* original 904b, guest PC 0x0c0a7786 */
if(!s->budget--) { s->failed_pc=0x0c0a7786u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a7820u,2);
goto P_0c0a7788;
P_0c0a7788: /* original de2f, guest PC 0x0c0a7788 */
if(!s->budget--) { s->failed_pc=0x0c0a7788u; return 0; }
r[14]=read(ram,0x0c0a7848u,4);
goto P_0c0a778a;
P_0c0a778a: /* original 05ee, guest PC 0x0c0a778a */
if(!s->budget--) { s->failed_pc=0x0c0a778au; return 0; }
r[5]=read(ram,r[14]+r[0],4);
goto P_0c0a778c;
P_0c0a778c: /* original 70fc, guest PC 0x0c0a778c */
if(!s->budget--) { s->failed_pc=0x0c0a778cu; return 0; }
r[0]+=0xfffffffcu;
goto P_0c0a778e;
P_0c0a778e: /* original 04ee, guest PC 0x0c0a778e */
if(!s->budget--) { s->failed_pc=0x0c0a778eu; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c0a7790;
P_0c0a7790: /* original a000, guest PC 0x0c0a7790 */
if(!s->budget--) { s->failed_pc=0x0c0a7790u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0a7794u,s,ram);
P_0c0a7792: /* original 6ef6, guest PC 0x0c0a7792 */
if(!s->budget--) { s->failed_pc=0x0c0a7792u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0a7794u,s,ram);
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
P_0c0adb86: /* original 4f22, guest PC 0x0c0adb86 */
if(!s->budget--) { s->failed_pc=0x0c0adb86u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0adb88;
P_0c0adb88: /* original 600c, guest PC 0x0c0adb88 */
if(!s->budget--) { s->failed_pc=0x0c0adb88u; return 0; }
r[0]=r[0]&255u;
goto P_0c0adb8a;
P_0c0adb8a: /* original 220b, guest PC 0x0c0adb8a */
if(!s->budget--) { s->failed_pc=0x0c0adb8au; return 0; }
r[2]|=r[0];
goto P_0c0adb8c;
P_0c0adb8c: /* original 905f, guest PC 0x0c0adb8c */
if(!s->budget--) { s->failed_pc=0x0c0adb8cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0adc4eu,2);
goto P_0c0adb8e;
P_0c0adb8e: /* original 4f12, guest PC 0x0c0adb8e */
if(!s->budget--) { s->failed_pc=0x0c0adb8eu; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c0adb90;
P_0c0adb90: /* original 0426, guest PC 0x0c0adb90 */
if(!s->budget--) { s->failed_pc=0x0c0adb90u; return 0; }
write(ram,r[4]+r[0],r[2],4);
goto P_0c0adb92;
P_0c0adb92: /* original 8465, guest PC 0x0c0adb92 */
if(!s->budget--) { s->failed_pc=0x0c0adb92u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[6]+5,1);
goto P_0c0adb94;
P_0c0adb94: /* original 925c, guest PC 0x0c0adb94 */
if(!s->budget--) { s->failed_pc=0x0c0adb94u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0adc50u,2);
goto P_0c0adb96;
P_0c0adb96: /* original 600c, guest PC 0x0c0adb96 */
if(!s->budget--) { s->failed_pc=0x0c0adb96u; return 0; }
r[0]=r[0]&255u;
goto P_0c0adb98;
P_0c0adb98: /* original 4018, guest PC 0x0c0adb98 */
if(!s->budget--) { s->failed_pc=0x0c0adb98u; return 0; }
r[0]<<=8;
goto P_0c0adb9a;
P_0c0adb9a: /* original 2029, guest PC 0x0c0adb9a */
if(!s->budget--) { s->failed_pc=0x0c0adb9au; return 0; }
r[0]&=r[2];
goto P_0c0adb9c;
P_0c0adb9c: /* original 6103, guest PC 0x0c0adb9c */
if(!s->budget--) { s->failed_pc=0x0c0adb9cu; return 0; }
r[1]=r[0];
goto P_0c0adb9e;
P_0c0adb9e: /* original 8464, guest PC 0x0c0adb9e */
if(!s->budget--) { s->failed_pc=0x0c0adb9eu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[6]+4,1);
goto P_0c0adba0;
P_0c0adba0: /* original 600c, guest PC 0x0c0adba0 */
if(!s->budget--) { s->failed_pc=0x0c0adba0u; return 0; }
r[0]=r[0]&255u;
goto P_0c0adba2;
P_0c0adba2: /* original 210b, guest PC 0x0c0adba2 */
if(!s->budget--) { s->failed_pc=0x0c0adba2u; return 0; }
r[1]|=r[0];
goto P_0c0adba4;
P_0c0adba4: /* original 9055, guest PC 0x0c0adba4 */
if(!s->budget--) { s->failed_pc=0x0c0adba4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0adc52u,2);
goto P_0c0adba6;
P_0c0adba6: /* original 0415, guest PC 0x0c0adba6 */
if(!s->budget--) { s->failed_pc=0x0c0adba6u; return 0; }
write(ram,r[4]+r[0],r[1],2);
goto P_0c0adba8;
P_0c0adba8: /* original 8463, guest PC 0x0c0adba8 */
if(!s->budget--) { s->failed_pc=0x0c0adba8u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[6]+3,1);
goto P_0c0adbaa;
P_0c0adbaa: /* original 6703, guest PC 0x0c0adbaa */
if(!s->budget--) { s->failed_pc=0x0c0adbaau; return 0; }
r[7]=r[0];
goto P_0c0adbac;
P_0c0adbac: /* original 9052, guest PC 0x0c0adbac */
if(!s->budget--) { s->failed_pc=0x0c0adbacu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0adc54u,2);
goto P_0c0adbae;
P_0c0adbae: /* original 034c, guest PC 0x0c0adbae */
if(!s->budget--) { s->failed_pc=0x0c0adbaeu; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c0adbb0;
P_0c0adbb0: /* original 633c, guest PC 0x0c0adbb0 */
if(!s->budget--) { s->failed_pc=0x0c0adbb0u; return 0; }
r[3]=r[3]&255u;
goto P_0c0adbb2;
P_0c0adbb2: /* original 7364, guest PC 0x0c0adbb2 */
if(!s->budget--) { s->failed_pc=0x0c0adbb2u; return 0; }
r[3]+=0x00000064u;
goto P_0c0adbb4;
P_0c0adbb4: /* original 0377, guest PC 0x0c0adbb4 */
if(!s->budget--) { s->failed_pc=0x0c0adbb4u; return 0; }
r[19]=r[3]*r[7];
goto P_0c0adbb6;
P_0c0adbb6: /* original 071a, guest PC 0x0c0adbb6 */
if(!s->budget--) { s->failed_pc=0x0c0adbb6u; return 0; }
r[7]=r[19];
goto P_0c0adbb8;
P_0c0adbb8: /* original d32c, guest PC 0x0c0adbb8 */
if(!s->budget--) { s->failed_pc=0x0c0adbb8u; return 0; }
r[3]=read(ram,0x0c0adc6cu,4);
goto P_0c0adbba;
P_0c0adbba: /* original e064, guest PC 0x0c0adbba */
if(!s->budget--) { s->failed_pc=0x0c0adbbau; return 0; }
r[0]=0x00000064u;
goto P_0c0adbbc;
P_0c0adbbc: /* original 430b, guest PC 0x0c0adbbc */
if(!s->budget--) { s->failed_pc=0x0c0adbbcu; return 0; }
target=r[3];
r[16]=0x0c0adbc0u;
r[1]=r[7];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0adbc0u) { target=s->pc; goto dispatch; }
goto P_0c0adbc0;
P_0c0adbbe: /* original 6173, guest PC 0x0c0adbbe */
if(!s->budget--) { s->failed_pc=0x0c0adbbeu; return 0; }
r[1]=r[7];
goto P_0c0adbc0;
P_0c0adbc0: /* original 6703, guest PC 0x0c0adbc0 */
if(!s->budget--) { s->failed_pc=0x0c0adbc0u; return 0; }
r[7]=r[0];
goto P_0c0adbc2;
P_0c0adbc2: /* original 9041, guest PC 0x0c0adbc2 */
if(!s->budget--) { s->failed_pc=0x0c0adbc2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0adc48u,2);
goto P_0c0adbc4;
P_0c0adbc4: /* original 4f16, guest PC 0x0c0adbc4 */
if(!s->budget--) { s->failed_pc=0x0c0adbc4u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c0adbc6;
P_0c0adbc6: /* original 0474, guest PC 0x0c0adbc6 */
if(!s->budget--) { s->failed_pc=0x0c0adbc6u; return 0; }
write(ram,r[4]+r[0],r[7],1);
goto P_0c0adbc8;
P_0c0adbc8: /* original 7608, guest PC 0x0c0adbc8 */
if(!s->budget--) { s->failed_pc=0x0c0adbc8u; return 0; }
r[6]+=0x00000008u;
goto P_0c0adbca;
P_0c0adbca: /* original 9044, guest PC 0x0c0adbca */
if(!s->budget--) { s->failed_pc=0x0c0adbcau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0adc56u,2);
goto P_0c0adbcc;
P_0c0adbcc: /* original 034e, guest PC 0x0c0adbcc */
if(!s->budget--) { s->failed_pc=0x0c0adbccu; return 0; }
r[3]=read(ram,r[4]+r[0],4);
goto P_0c0adbce;
P_0c0adbce: /* original 7301, guest PC 0x0c0adbce */
if(!s->budget--) { s->failed_pc=0x0c0adbceu; return 0; }
r[3]+=0x00000001u;
goto P_0c0adbd0;
P_0c0adbd0: /* original 0436, guest PC 0x0c0adbd0 */
if(!s->budget--) { s->failed_pc=0x0c0adbd0u; return 0; }
write(ram,r[4]+r[0],r[3],4);
goto P_0c0adbd2;
P_0c0adbd2: /* original acd1, guest PC 0x0c0adbd2 */
if(!s->budget--) { s->failed_pc=0x0c0adbd2u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0ad578;
P_0c0adbd4: /* original 4f26, guest PC 0x0c0adbd4 */
if(!s->budget--) { s->failed_pc=0x0c0adbd4u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
return vf3_matrix_family(0x0c0adbd6u,s,ram);
P_0c0adc72: /* original 4f22, guest PC 0x0c0adc72 */
if(!s->budget--) { s->failed_pc=0x0c0adc72u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0adc74;
P_0c0adc74: /* original d359, guest PC 0x0c0adc74 */
if(!s->budget--) { s->failed_pc=0x0c0adc74u; return 0; }
r[3]=read(ram,0x0c0adddcu,4);
goto P_0c0adc76;
P_0c0adc76: /* original 7ff4, guest PC 0x0c0adc76 */
if(!s->budget--) { s->failed_pc=0x0c0adc76u; return 0; }
r[15]+=0xfffffff4u;
goto P_0c0adc78;
P_0c0adc78: /* original 2f32, guest PC 0x0c0adc78 */
if(!s->budget--) { s->failed_pc=0x0c0adc78u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c0adc7a;
P_0c0adc7a: /* original 67f3, guest PC 0x0c0adc7a */
if(!s->budget--) { s->failed_pc=0x0c0adc7au; return 0; }
r[7]=r[15];
goto P_0c0adc7c;
P_0c0adc7c: /* original 91a1, guest PC 0x0c0adc7c */
if(!s->budget--) { s->failed_pc=0x0c0adc7cu; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0addc2u,2);
goto P_0c0adc7e;
P_0c0adc7e: /* original 6ef3, guest PC 0x0c0adc7e */
if(!s->budget--) { s->failed_pc=0x0c0adc7eu; return 0; }
r[14]=r[15];
goto P_0c0adc80;
P_0c0adc80: /* original 8461, guest PC 0x0c0adc80 */
if(!s->budget--) { s->failed_pc=0x0c0adc80u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[6]+1,1);
goto P_0c0adc82;
P_0c0adc82: /* original 7e04, guest PC 0x0c0adc82 */
if(!s->budget--) { s->failed_pc=0x0c0adc82u; return 0; }
r[14]+=0x00000004u;
goto P_0c0adc84;
P_0c0adc84: /* original 314c, guest PC 0x0c0adc84 */
if(!s->budget--) { s->failed_pc=0x0c0adc84u; return 0; }
r[1]+=r[4];
goto P_0c0adc86;
P_0c0adc86: /* original 2100, guest PC 0x0c0adc86 */
if(!s->budget--) { s->failed_pc=0x0c0adc86u; return 0; }
write(ram,r[1],r[0],1);
goto P_0c0adc88;
P_0c0adc88: /* original 7704, guest PC 0x0c0adc88 */
if(!s->budget--) { s->failed_pc=0x0c0adc88u; return 0; }
r[7]+=0x00000004u;
goto P_0c0adc8a;
P_0c0adc8a: /* original 929b, guest PC 0x0c0adc8a */
if(!s->budget--) { s->failed_pc=0x0c0adc8au; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0addc4u,2);
goto P_0c0adc8c;
P_0c0adc8c: /* original 8462, guest PC 0x0c0adc8c */
if(!s->budget--) { s->failed_pc=0x0c0adc8cu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[6]+2,1);
goto P_0c0adc8e;
P_0c0adc8e: /* original 324c, guest PC 0x0c0adc8e */
if(!s->budget--) { s->failed_pc=0x0c0adc8eu; return 0; }
r[2]+=r[4];
goto P_0c0adc90;
P_0c0adc90: /* original 2200, guest PC 0x0c0adc90 */
if(!s->budget--) { s->failed_pc=0x0c0adc90u; return 0; }
write(ram,r[2],r[0],1);
goto P_0c0adc92;
P_0c0adc92: /* original 9198, guest PC 0x0c0adc92 */
if(!s->budget--) { s->failed_pc=0x0c0adc92u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0addc6u,2);
goto P_0c0adc94;
P_0c0adc94: /* original 8463, guest PC 0x0c0adc94 */
if(!s->budget--) { s->failed_pc=0x0c0adc94u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[6]+3,1);
goto P_0c0adc96;
P_0c0adc96: /* original 314c, guest PC 0x0c0adc96 */
if(!s->budget--) { s->failed_pc=0x0c0adc96u; return 0; }
r[1]+=r[4];
goto P_0c0adc98;
P_0c0adc98: /* original 2100, guest PC 0x0c0adc98 */
if(!s->budget--) { s->failed_pc=0x0c0adc98u; return 0; }
write(ram,r[1],r[0],1);
goto P_0c0adc9a;
P_0c0adc9a: /* original 8467, guest PC 0x0c0adc9a */
if(!s->budget--) { s->failed_pc=0x0c0adc9au; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[6]+7,1);
goto P_0c0adc9c;
P_0c0adc9c: /* original d350, guest PC 0x0c0adc9c */
if(!s->budget--) { s->failed_pc=0x0c0adc9cu; return 0; }
r[3]=read(ram,0x0c0adde0u,4);
goto P_0c0adc9e;
P_0c0adc9e: /* original 600c, guest PC 0x0c0adc9e */
if(!s->budget--) { s->failed_pc=0x0c0adc9eu; return 0; }
r[0]=r[0]&255u;
goto P_0c0adca0;
P_0c0adca0: /* original d250, guest PC 0x0c0adca0 */
if(!s->budget--) { s->failed_pc=0x0c0adca0u; return 0; }
r[2]=read(ram,0x0c0adde4u,4);
goto P_0c0adca2;
P_0c0adca2: /* original 4028, guest PC 0x0c0adca2 */
if(!s->budget--) { s->failed_pc=0x0c0adca2u; return 0; }
r[0]<<=16;
goto P_0c0adca4;
P_0c0adca4: /* original 4018, guest PC 0x0c0adca4 */
if(!s->budget--) { s->failed_pc=0x0c0adca4u; return 0; }
r[0]<<=8;
goto P_0c0adca6;
P_0c0adca6: /* original 2039, guest PC 0x0c0adca6 */
if(!s->budget--) { s->failed_pc=0x0c0adca6u; return 0; }
r[0]&=r[3];
goto P_0c0adca8;
P_0c0adca8: /* original 6103, guest PC 0x0c0adca8 */
if(!s->budget--) { s->failed_pc=0x0c0adca8u; return 0; }
r[1]=r[0];
goto P_0c0adcaa;
P_0c0adcaa: /* original 8466, guest PC 0x0c0adcaa */
if(!s->budget--) { s->failed_pc=0x0c0adcaau; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[6]+6,1);
goto P_0c0adcac;
P_0c0adcac: /* original 600c, guest PC 0x0c0adcac */
if(!s->budget--) { s->failed_pc=0x0c0adcacu; return 0; }
r[0]=r[0]&255u;
goto P_0c0adcae;
P_0c0adcae: /* original 4028, guest PC 0x0c0adcae */
if(!s->budget--) { s->failed_pc=0x0c0adcaeu; return 0; }
r[0]<<=16;
goto P_0c0adcb0;
P_0c0adcb0: /* original 2029, guest PC 0x0c0adcb0 */
if(!s->budget--) { s->failed_pc=0x0c0adcb0u; return 0; }
r[0]&=r[2];
goto P_0c0adcb2;
P_0c0adcb2: /* original 210b, guest PC 0x0c0adcb2 */
if(!s->budget--) { s->failed_pc=0x0c0adcb2u; return 0; }
r[1]|=r[0];
goto P_0c0adcb4;
P_0c0adcb4: /* original 8465, guest PC 0x0c0adcb4 */
if(!s->budget--) { s->failed_pc=0x0c0adcb4u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[6]+5,1);
goto P_0c0adcb6;
P_0c0adcb6: /* original 4329, guest PC 0x0c0adcb6 */
if(!s->budget--) { s->failed_pc=0x0c0adcb6u; return 0; }
r[3]>>=16;
goto P_0c0adcb8;
P_0c0adcb8: /* original 600c, guest PC 0x0c0adcb8 */
if(!s->budget--) { s->failed_pc=0x0c0adcb8u; return 0; }
r[0]=r[0]&255u;
goto P_0c0adcba;
P_0c0adcba: /* original 4018, guest PC 0x0c0adcba */
if(!s->budget--) { s->failed_pc=0x0c0adcbau; return 0; }
r[0]<<=8;
goto P_0c0adcbc;
P_0c0adcbc: /* original 2039, guest PC 0x0c0adcbc */
if(!s->budget--) { s->failed_pc=0x0c0adcbcu; return 0; }
r[0]&=r[3];
goto P_0c0adcbe;
P_0c0adcbe: /* original 210b, guest PC 0x0c0adcbe */
if(!s->budget--) { s->failed_pc=0x0c0adcbeu; return 0; }
r[1]|=r[0];
goto P_0c0adcc0;
P_0c0adcc0: /* original 8464, guest PC 0x0c0adcc0 */
if(!s->budget--) { s->failed_pc=0x0c0adcc0u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[6]+4,1);
goto P_0c0adcc2;
P_0c0adcc2: /* original 600c, guest PC 0x0c0adcc2 */
if(!s->budget--) { s->failed_pc=0x0c0adcc2u; return 0; }
r[0]=r[0]&255u;
goto P_0c0adcc4;
P_0c0adcc4: /* original 210b, guest PC 0x0c0adcc4 */
if(!s->budget--) { s->failed_pc=0x0c0adcc4u; return 0; }
r[1]|=r[0];
goto P_0c0adcc6;
P_0c0adcc6: /* original 2712, guest PC 0x0c0adcc6 */
if(!s->budget--) { s->failed_pc=0x0c0adcc6u; return 0; }
write(ram,r[7],r[1],4);
goto P_0c0adcc8;
P_0c0adcc8: /* original 61f2, guest PC 0x0c0adcc8 */
if(!s->budget--) { s->failed_pc=0x0c0adcc8u; return 0; }
tmp=read(ram,r[15],4);
r[1]=tmp;
goto P_0c0adcca;
P_0c0adcca: /* original f4e8, guest PC 0x0c0adcca */
if(!s->budget--) { s->failed_pc=0x0c0adccau; return 0; }
vf3_matrix_load(s,ram,4,r[14]);
goto P_0c0adccc;
P_0c0adccc: /* original f618, guest PC 0x0c0adccc */
if(!s->budget--) { s->failed_pc=0x0c0adcccu; return 0; }
vf3_matrix_load(s,ram,6,r[1]);
goto P_0c0adcce;
P_0c0adcce: /* original f34c, guest PC 0x0c0adcce */
if(!s->budget--) { s->failed_pc=0x0c0adcceu; return 0; }
vf3_matrix_move(s,3,4);
goto P_0c0adcd0;
P_0c0adcd0: /* original f362, guest PC 0x0c0adcd0 */
if(!s->budget--) { s->failed_pc=0x0c0adcd0u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[6],r[18],'*');
goto P_0c0adcd2;
P_0c0adcd2: /* original f58d, guest PC 0x0c0adcd2 */
if(!s->budget--) { s->failed_pc=0x0c0adcd2u; return 0; }
fr[5]=0;
goto P_0c0adcd4;
P_0c0adcd4: /* original f25c, guest PC 0x0c0adcd4 */
if(!s->budget--) { s->failed_pc=0x0c0adcd4u; return 0; }
vf3_matrix_move(s,2,5);
goto P_0c0adcd6;
P_0c0adcd6: /* original 9077, guest PC 0x0c0adcd6 */
if(!s->budget--) { s->failed_pc=0x0c0adcd6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0addc8u,2);
goto P_0c0adcd8;
P_0c0adcd8: /* original f34d, guest PC 0x0c0adcd8 */
if(!s->budget--) { s->failed_pc=0x0c0adcd8u; return 0; }
fr[3]^=0x80000000u;
goto P_0c0adcda;
P_0c0adcda: /* original f53c, guest PC 0x0c0adcda */
if(!s->budget--) { s->failed_pc=0x0c0adcdau; return 0; }
vf3_matrix_move(s,5,3);
goto P_0c0adcdc;
P_0c0adcdc: /* original f521, guest PC 0x0c0adcdc */
if(!s->budget--) { s->failed_pc=0x0c0adcdcu; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[2],r[18],'-');
goto P_0c0adcde;
P_0c0adcde: /* original f457, guest PC 0x0c0adcde */
if(!s->budget--) { s->failed_pc=0x0c0adcdeu; return 0; }
vf3_matrix_store(s,ram,5,r[4]+r[0]);
goto P_0c0adce0;
P_0c0adce0: /* original f59d, guest PC 0x0c0adce0 */
if(!s->budget--) { s->failed_pc=0x0c0adce0u; return 0; }
fr[5]=0x3f800000u;
goto P_0c0adce2;
P_0c0adce2: /* original f450, guest PC 0x0c0adce2 */
if(!s->budget--) { s->failed_pc=0x0c0adce2u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[5],r[18],'+');
goto P_0c0adce4;
P_0c0adce4: /* original 9071, guest PC 0x0c0adce4 */
if(!s->budget--) { s->failed_pc=0x0c0adce4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0addcau,2);
goto P_0c0adce6;
P_0c0adce6: /* original f447, guest PC 0x0c0adce6 */
if(!s->budget--) { s->failed_pc=0x0c0adce6u; return 0; }
vf3_matrix_store(s,ram,4,r[4]+r[0]);
goto P_0c0adce8;
P_0c0adce8: /* original 846b, guest PC 0x0c0adce8 */
if(!s->budget--) { s->failed_pc=0x0c0adce8u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[6]+11,1);
goto P_0c0adcea;
P_0c0adcea: /* original 600c, guest PC 0x0c0adcea */
if(!s->budget--) { s->failed_pc=0x0c0adceau; return 0; }
r[0]=r[0]&255u;
goto P_0c0adcec;
P_0c0adcec: /* original 4028, guest PC 0x0c0adcec */
if(!s->budget--) { s->failed_pc=0x0c0adcecu; return 0; }
r[0]<<=16;
goto P_0c0adcee;
P_0c0adcee: /* original 4018, guest PC 0x0c0adcee */
if(!s->budget--) { s->failed_pc=0x0c0adceeu; return 0; }
r[0]<<=8;
goto P_0c0adcf0;
P_0c0adcf0: /* original d13b, guest PC 0x0c0adcf0 */
if(!s->budget--) { s->failed_pc=0x0c0adcf0u; return 0; }
r[1]=read(ram,0x0c0adde0u,4);
goto P_0c0adcf2;
P_0c0adcf2: /* original 2019, guest PC 0x0c0adcf2 */
if(!s->budget--) { s->failed_pc=0x0c0adcf2u; return 0; }
r[0]&=r[1];
goto P_0c0adcf4;
P_0c0adcf4: /* original 6303, guest PC 0x0c0adcf4 */
if(!s->budget--) { s->failed_pc=0x0c0adcf4u; return 0; }
r[3]=r[0];
goto P_0c0adcf6;
P_0c0adcf6: /* original 846a, guest PC 0x0c0adcf6 */
if(!s->budget--) { s->failed_pc=0x0c0adcf6u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[6]+10,1);
goto P_0c0adcf8;
P_0c0adcf8: /* original 600c, guest PC 0x0c0adcf8 */
if(!s->budget--) { s->failed_pc=0x0c0adcf8u; return 0; }
r[0]=r[0]&255u;
goto P_0c0adcfa;
P_0c0adcfa: /* original 4028, guest PC 0x0c0adcfa */
if(!s->budget--) { s->failed_pc=0x0c0adcfau; return 0; }
r[0]<<=16;
goto P_0c0adcfc;
P_0c0adcfc: /* original 2029, guest PC 0x0c0adcfc */
if(!s->budget--) { s->failed_pc=0x0c0adcfcu; return 0; }
r[0]&=r[2];
goto P_0c0adcfe;
P_0c0adcfe: /* original 230b, guest PC 0x0c0adcfe */
if(!s->budget--) { s->failed_pc=0x0c0adcfeu; return 0; }
r[3]|=r[0];
goto P_0c0add00;
P_0c0add00: /* original 8469, guest PC 0x0c0add00 */
if(!s->budget--) { s->failed_pc=0x0c0add00u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[6]+9,1);
goto P_0c0add02;
P_0c0add02: /* original 4219, guest PC 0x0c0add02 */
if(!s->budget--) { s->failed_pc=0x0c0add02u; return 0; }
r[2]>>=8;
goto P_0c0add04;
P_0c0add04: /* original 600c, guest PC 0x0c0add04 */
if(!s->budget--) { s->failed_pc=0x0c0add04u; return 0; }
r[0]=r[0]&255u;
goto P_0c0add06;
P_0c0add06: /* original 4018, guest PC 0x0c0add06 */
if(!s->budget--) { s->failed_pc=0x0c0add06u; return 0; }
r[0]<<=8;
goto P_0c0add08;
P_0c0add08: /* original 2029, guest PC 0x0c0add08 */
if(!s->budget--) { s->failed_pc=0x0c0add08u; return 0; }
r[0]&=r[2];
goto P_0c0add0a;
P_0c0add0a: /* original 230b, guest PC 0x0c0add0a */
if(!s->budget--) { s->failed_pc=0x0c0add0au; return 0; }
r[3]|=r[0];
goto P_0c0add0c;
P_0c0add0c: /* original 8468, guest PC 0x0c0add0c */
if(!s->budget--) { s->failed_pc=0x0c0add0cu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[6]+8,1);
goto P_0c0add0e;
P_0c0add0e: /* original 600c, guest PC 0x0c0add0e */
if(!s->budget--) { s->failed_pc=0x0c0add0eu; return 0; }
r[0]=r[0]&255u;
goto P_0c0add10;
P_0c0add10: /* original 230b, guest PC 0x0c0add10 */
if(!s->budget--) { s->failed_pc=0x0c0add10u; return 0; }
r[3]|=r[0];
goto P_0c0add12;
P_0c0add12: /* original 2732, guest PC 0x0c0add12 */
if(!s->budget--) { s->failed_pc=0x0c0add12u; return 0; }
write(ram,r[7],r[3],4);
goto P_0c0add14;
P_0c0add14: /* original 905a, guest PC 0x0c0add14 */
if(!s->budget--) { s->failed_pc=0x0c0add14u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0addccu,2);
goto P_0c0add16;
P_0c0add16: /* original f3e8, guest PC 0x0c0add16 */
if(!s->budget--) { s->failed_pc=0x0c0add16u; return 0; }
vf3_matrix_load(s,ram,3,r[14]);
goto P_0c0add18;
P_0c0add18: /* original f437, guest PC 0x0c0add18 */
if(!s->budget--) { s->failed_pc=0x0c0add18u; return 0; }
vf3_matrix_store(s,ram,3,r[4]+r[0]);
goto P_0c0add1a;
P_0c0add1a: /* original bc2d, guest PC 0x0c0add1a */
if(!s->budget--) { s->failed_pc=0x0c0add1au; return 0; }
target=0x0c0ad578u; r[16]=0x0c0add1eu;
r[6]+=0x0000000cu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0add1eu) { target=s->pc; goto dispatch; }
goto P_0c0add1e;
P_0c0add1c: /* original 760c, guest PC 0x0c0add1c */
if(!s->budget--) { s->failed_pc=0x0c0add1cu; return 0; }
r[6]+=0x0000000cu;
goto P_0c0add1e;
P_0c0add1e: /* original 7f0c, guest PC 0x0c0add1e */
if(!s->budget--) { s->failed_pc=0x0c0add1eu; return 0; }
r[15]+=0x0000000cu;
goto P_0c0add20;
P_0c0add20: /* original 4f26, guest PC 0x0c0add20 */
if(!s->budget--) { s->failed_pc=0x0c0add20u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0add22;
P_0c0add22: /* original 000b, guest PC 0x0c0add22 */
if(!s->budget--) { s->failed_pc=0x0c0add22u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0add24: /* original 6ef6, guest PC 0x0c0add24 */
if(!s->budget--) { s->failed_pc=0x0c0add24u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0add26u,s,ram);
P_0c0adf70: /* original 4f22, guest PC 0x0c0adf70 */
if(!s->budget--) { s->failed_pc=0x0c0adf70u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0adf72;
P_0c0adf72: /* original 7ff4, guest PC 0x0c0adf72 */
if(!s->budget--) { s->failed_pc=0x0c0adf72u; return 0; }
r[15]+=0xfffffff4u;
goto P_0c0adf74;
P_0c0adf74: /* original 63f3, guest PC 0x0c0adf74 */
if(!s->budget--) { s->failed_pc=0x0c0adf74u; return 0; }
r[3]=r[15];
goto P_0c0adf76;
P_0c0adf76: /* original 7304, guest PC 0x0c0adf76 */
if(!s->budget--) { s->failed_pc=0x0c0adf76u; return 0; }
r[3]+=0x00000004u;
goto P_0c0adf78;
P_0c0adf78: /* original 2f32, guest PC 0x0c0adf78 */
if(!s->budget--) { s->failed_pc=0x0c0adf78u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c0adf7a;
P_0c0adf7a: /* original 67f3, guest PC 0x0c0adf7a */
if(!s->budget--) { s->failed_pc=0x0c0adf7au; return 0; }
r[7]=r[15];
goto P_0c0adf7c;
P_0c0adf7c: /* original 8464, guest PC 0x0c0adf7c */
if(!s->budget--) { s->failed_pc=0x0c0adf7cu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[6]+4,1);
goto P_0c0adf7e;
P_0c0adf7e: /* original 7704, guest PC 0x0c0adf7e */
if(!s->budget--) { s->failed_pc=0x0c0adf7eu; return 0; }
r[7]+=0x00000004u;
goto P_0c0adf80;
P_0c0adf80: /* original d33f, guest PC 0x0c0adf80 */
if(!s->budget--) { s->failed_pc=0x0c0adf80u; return 0; }
r[3]=read(ram,0x0c0ae080u,4);
goto P_0c0adf82;
P_0c0adf82: /* original 600c, guest PC 0x0c0adf82 */
if(!s->budget--) { s->failed_pc=0x0c0adf82u; return 0; }
r[0]=r[0]&255u;
goto P_0c0adf84;
P_0c0adf84: /* original d23f, guest PC 0x0c0adf84 */
if(!s->budget--) { s->failed_pc=0x0c0adf84u; return 0; }
r[2]=read(ram,0x0c0ae084u,4);
goto P_0c0adf86;
P_0c0adf86: /* original 4028, guest PC 0x0c0adf86 */
if(!s->budget--) { s->failed_pc=0x0c0adf86u; return 0; }
r[0]<<=16;
goto P_0c0adf88;
P_0c0adf88: /* original 4018, guest PC 0x0c0adf88 */
if(!s->budget--) { s->failed_pc=0x0c0adf88u; return 0; }
r[0]<<=8;
goto P_0c0adf8a;
P_0c0adf8a: /* original 2039, guest PC 0x0c0adf8a */
if(!s->budget--) { s->failed_pc=0x0c0adf8au; return 0; }
r[0]&=r[3];
goto P_0c0adf8c;
P_0c0adf8c: /* original 6103, guest PC 0x0c0adf8c */
if(!s->budget--) { s->failed_pc=0x0c0adf8cu; return 0; }
r[1]=r[0];
goto P_0c0adf8e;
P_0c0adf8e: /* original 8463, guest PC 0x0c0adf8e */
if(!s->budget--) { s->failed_pc=0x0c0adf8eu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[6]+3,1);
goto P_0c0adf90;
P_0c0adf90: /* original 4329, guest PC 0x0c0adf90 */
if(!s->budget--) { s->failed_pc=0x0c0adf90u; return 0; }
r[3]>>=16;
goto P_0c0adf92;
P_0c0adf92: /* original 600c, guest PC 0x0c0adf92 */
if(!s->budget--) { s->failed_pc=0x0c0adf92u; return 0; }
r[0]=r[0]&255u;
goto P_0c0adf94;
P_0c0adf94: /* original 4028, guest PC 0x0c0adf94 */
if(!s->budget--) { s->failed_pc=0x0c0adf94u; return 0; }
r[0]<<=16;
goto P_0c0adf96;
P_0c0adf96: /* original 2029, guest PC 0x0c0adf96 */
if(!s->budget--) { s->failed_pc=0x0c0adf96u; return 0; }
r[0]&=r[2];
goto P_0c0adf98;
P_0c0adf98: /* original 210b, guest PC 0x0c0adf98 */
if(!s->budget--) { s->failed_pc=0x0c0adf98u; return 0; }
r[1]|=r[0];
goto P_0c0adf9a;
P_0c0adf9a: /* original 8462, guest PC 0x0c0adf9a */
if(!s->budget--) { s->failed_pc=0x0c0adf9au; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[6]+2,1);
goto P_0c0adf9c;
P_0c0adf9c: /* original 600c, guest PC 0x0c0adf9c */
if(!s->budget--) { s->failed_pc=0x0c0adf9cu; return 0; }
r[0]=r[0]&255u;
goto P_0c0adf9e;
P_0c0adf9e: /* original 4018, guest PC 0x0c0adf9e */
if(!s->budget--) { s->failed_pc=0x0c0adf9eu; return 0; }
r[0]<<=8;
goto P_0c0adfa0;
P_0c0adfa0: /* original 2039, guest PC 0x0c0adfa0 */
if(!s->budget--) { s->failed_pc=0x0c0adfa0u; return 0; }
r[0]&=r[3];
goto P_0c0adfa2;
P_0c0adfa2: /* original 210b, guest PC 0x0c0adfa2 */
if(!s->budget--) { s->failed_pc=0x0c0adfa2u; return 0; }
r[1]|=r[0];
goto P_0c0adfa4;
P_0c0adfa4: /* original 8461, guest PC 0x0c0adfa4 */
if(!s->budget--) { s->failed_pc=0x0c0adfa4u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[6]+1,1);
goto P_0c0adfa6;
P_0c0adfa6: /* original 600c, guest PC 0x0c0adfa6 */
if(!s->budget--) { s->failed_pc=0x0c0adfa6u; return 0; }
r[0]=r[0]&255u;
goto P_0c0adfa8;
P_0c0adfa8: /* original 210b, guest PC 0x0c0adfa8 */
if(!s->budget--) { s->failed_pc=0x0c0adfa8u; return 0; }
r[1]|=r[0];
goto P_0c0adfaa;
P_0c0adfaa: /* original 2712, guest PC 0x0c0adfaa */
if(!s->budget--) { s->failed_pc=0x0c0adfaau; return 0; }
write(ram,r[7],r[1],4);
goto P_0c0adfac;
P_0c0adfac: /* original 61f2, guest PC 0x0c0adfac */
if(!s->budget--) { s->failed_pc=0x0c0adfacu; return 0; }
tmp=read(ram,r[15],4);
r[1]=tmp;
goto P_0c0adfae;
P_0c0adfae: /* original f318, guest PC 0x0c0adfae */
if(!s->budget--) { s->failed_pc=0x0c0adfaeu; return 0; }
vf3_matrix_load(s,ram,3,r[1]);
goto P_0c0adfb0;
P_0c0adfb0: /* original 905f, guest PC 0x0c0adfb0 */
if(!s->budget--) { s->failed_pc=0x0c0adfb0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ae072u,2);
goto P_0c0adfb2;
P_0c0adfb2: /* original f437, guest PC 0x0c0adfb2 */
if(!s->budget--) { s->failed_pc=0x0c0adfb2u; return 0; }
vf3_matrix_store(s,ram,3,r[4]+r[0]);
goto P_0c0adfb4;
P_0c0adfb4: /* original bae0, guest PC 0x0c0adfb4 */
if(!s->budget--) { s->failed_pc=0x0c0adfb4u; return 0; }
target=0x0c0ad578u; r[16]=0x0c0adfb8u;
r[6]+=0x00000005u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0adfb8u) { target=s->pc; goto dispatch; }
goto P_0c0adfb8;
P_0c0adfb6: /* original 7605, guest PC 0x0c0adfb6 */
if(!s->budget--) { s->failed_pc=0x0c0adfb6u; return 0; }
r[6]+=0x00000005u;
goto P_0c0adfb8;
P_0c0adfb8: /* original 7f0c, guest PC 0x0c0adfb8 */
if(!s->budget--) { s->failed_pc=0x0c0adfb8u; return 0; }
r[15]+=0x0000000cu;
goto P_0c0adfba;
P_0c0adfba: /* original 4f26, guest PC 0x0c0adfba */
if(!s->budget--) { s->failed_pc=0x0c0adfbau; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0adfbc;
P_0c0adfbc: /* original 000b, guest PC 0x0c0adfbc */
if(!s->budget--) { s->failed_pc=0x0c0adfbcu; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c0adfbe: /* original 0009, guest PC 0x0c0adfbe */
if(!s->budget--) { s->failed_pc=0x0c0adfbeu; return 0; }
return vf3_matrix_family(0x0c0adfc0u,s,ram);
P_0c0c18fe: /* original 4f22, guest PC 0x0c0c18fe */
if(!s->budget--) { s->failed_pc=0x0c0c18feu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0c1900;
P_0c0c1900: /* original 945d, guest PC 0x0c0c1900 */
if(!s->budget--) { s->failed_pc=0x0c0c1900u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c19beu,2);
goto P_0c0c1902;
P_0c0c1902: /* original d331, guest PC 0x0c0c1902 */
if(!s->budget--) { s->failed_pc=0x0c0c1902u; return 0; }
r[3]=read(ram,0x0c0c19c8u,4);
goto P_0c0c1904;
P_0c0c1904: /* original 7fcc, guest PC 0x0c0c1904 */
if(!s->budget--) { s->failed_pc=0x0c0c1904u; return 0; }
r[15]+=0xffffffccu;
goto P_0c0c1906;
P_0c0c1906: /* original 430b, guest PC 0x0c0c1906 */
if(!s->budget--) { s->failed_pc=0x0c0c1906u; return 0; }
target=r[3];
r[16]=0x0c0c190au;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c190au) { target=s->pc; goto dispatch; }
goto P_0c0c190a;
P_0c0c1908: /* original 0009, guest PC 0x0c0c1908 */
if(!s->budget--) { s->failed_pc=0x0c0c1908u; return 0; }
goto P_0c0c190a;
P_0c0c190a: /* original 6e03, guest PC 0x0c0c190a */
if(!s->budget--) { s->failed_pc=0x0c0c190au; return 0; }
r[14]=r[0];
goto P_0c0c190c;
P_0c0c190c: /* original c72f, guest PC 0x0c0c190c */
if(!s->budget--) { s->failed_pc=0x0c0c190cu; return 0; }
r[0]=0x0c0c19ccu;
goto P_0c0c190e;
P_0c0c190e: /* original 52e8, guest PC 0x0c0c190e */
if(!s->budget--) { s->failed_pc=0x0c0c190eu; return 0; }
r[2]=read(ram,r[14]+32,4);
goto P_0c0c1910;
P_0c0c1910: /* original 2f22, guest PC 0x0c0c1910 */
if(!s->budget--) { s->failed_pc=0x0c0c1910u; return 0; }
write(ram,r[15],r[2],4);
goto P_0c0c1912;
P_0c0c1912: /* original f308, guest PC 0x0c0c1912 */
if(!s->budget--) { s->failed_pc=0x0c0c1912u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c0c1914;
P_0c0c1914: /* original e018, guest PC 0x0c0c1914 */
if(!s->budget--) { s->failed_pc=0x0c0c1914u; return 0; }
r[0]=0x00000018u;
goto P_0c0c1916;
P_0c0c1916: /* original fee6, guest PC 0x0c0c1916 */
if(!s->budget--) { s->failed_pc=0x0c0c1916u; return 0; }
vf3_matrix_load(s,ram,14,r[14]+r[0]);
goto P_0c0c1918;
P_0c0c1918: /* original c72d, guest PC 0x0c0c1918 */
if(!s->budget--) { s->failed_pc=0x0c0c1918u; return 0; }
r[0]=0x0c0c19d0u;
goto P_0c0c191a;
P_0c0c191a: /* original f208, guest PC 0x0c0c191a */
if(!s->budget--) { s->failed_pc=0x0c0c191au; return 0; }
vf3_matrix_load(s,ram,2,r[0]);
goto P_0c0c191c;
P_0c0c191c: /* original e01c, guest PC 0x0c0c191c */
if(!s->budget--) { s->failed_pc=0x0c0c191cu; return 0; }
r[0]=0x0000001cu;
goto P_0c0c191e;
P_0c0c191e: /* original ffe6, guest PC 0x0c0c191e */
if(!s->budget--) { s->failed_pc=0x0c0c191eu; return 0; }
vf3_matrix_load(s,ram,15,r[14]+r[0]);
goto P_0c0c1920;
P_0c0c1920: /* original fe32, guest PC 0x0c0c1920 */
if(!s->budget--) { s->failed_pc=0x0c0c1920u; return 0; }
fr[14]=vf3_fpu_binary(fr[14],fr[3],r[18],'*');
goto P_0c0c1922;
P_0c0c1922: /* original c72c, guest PC 0x0c0c1922 */
if(!s->budget--) { s->failed_pc=0x0c0c1922u; return 0; }
r[0]=0x0c0c19d4u;
goto P_0c0c1924;
P_0c0c1924: /* original d32c, guest PC 0x0c0c1924 */
if(!s->budget--) { s->failed_pc=0x0c0c1924u; return 0; }
r[3]=read(ram,0x0c0c19d8u,4);
goto P_0c0c1926;
P_0c0c1926: /* original ff22, guest PC 0x0c0c1926 */
if(!s->budget--) { s->failed_pc=0x0c0c1926u; return 0; }
fr[15]=vf3_fpu_binary(fr[15],fr[2],r[18],'*');
goto P_0c0c1928;
P_0c0c1928: /* original f808, guest PC 0x0c0c1928 */
if(!s->budget--) { s->failed_pc=0x0c0c1928u; return 0; }
vf3_matrix_load(s,ram,8,r[0]);
goto P_0c0c192a;
P_0c0c192a: /* original fd8d, guest PC 0x0c0c192a */
if(!s->budget--) { s->failed_pc=0x0c0c192au; return 0; }
fr[13]=0;
goto P_0c0c192c;
P_0c0c192c: /* original f5dc, guest PC 0x0c0c192c */
if(!s->budget--) { s->failed_pc=0x0c0c192cu; return 0; }
vf3_matrix_move(s,5,13);
goto P_0c0c192e;
P_0c0c192e: /* original f4dc, guest PC 0x0c0c192e */
if(!s->budget--) { s->failed_pc=0x0c0c192eu; return 0; }
vf3_matrix_move(s,4,13);
goto P_0c0c1930;
P_0c0c1930: /* original f7fc, guest PC 0x0c0c1930 */
if(!s->budget--) { s->failed_pc=0x0c0c1930u; return 0; }
vf3_matrix_move(s,7,15);
goto P_0c0c1932;
P_0c0c1932: /* original f6ec, guest PC 0x0c0c1932 */
if(!s->budget--) { s->failed_pc=0x0c0c1932u; return 0; }
vf3_matrix_move(s,6,14);
goto P_0c0c1934;
P_0c0c1934: /* original 430b, guest PC 0x0c0c1934 */
if(!s->budget--) { s->failed_pc=0x0c0c1934u; return 0; }
target=r[3];
r[16]=0x0c0c1938u;
r[4]=r[15];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c1938u) { target=s->pc; goto dispatch; }
goto P_0c0c1938;
P_0c0c1936: /* original 64f3, guest PC 0x0c0c1936 */
if(!s->budget--) { s->failed_pc=0x0c0c1936u; return 0; }
r[4]=r[15];
goto P_0c0c1938;
P_0c0c1938: /* original e014, guest PC 0x0c0c1938 */
if(!s->budget--) { s->failed_pc=0x0c0c1938u; return 0; }
r[0]=0x00000014u;
goto P_0c0c193a;
P_0c0c193a: /* original d328, guest PC 0x0c0c193a */
if(!s->budget--) { s->failed_pc=0x0c0c193au; return 0; }
r[3]=read(ram,0x0c0c19dcu,4);
goto P_0c0c193c;
P_0c0c193c: /* original f9e6, guest PC 0x0c0c193c */
if(!s->budget--) { s->failed_pc=0x0c0c193cu; return 0; }
vf3_matrix_load(s,ram,9,r[14]+r[0]);
goto P_0c0c193e;
P_0c0c193e: /* original e010, guest PC 0x0c0c193e */
if(!s->budget--) { s->failed_pc=0x0c0c193eu; return 0; }
r[0]=0x00000010u;
goto P_0c0c1940;
P_0c0c1940: /* original f8e6, guest PC 0x0c0c1940 */
if(!s->budget--) { s->failed_pc=0x0c0c1940u; return 0; }
vf3_matrix_load(s,ram,8,r[14]+r[0]);
goto P_0c0c1942;
P_0c0c1942: /* original e00c, guest PC 0x0c0c1942 */
if(!s->budget--) { s->failed_pc=0x0c0c1942u; return 0; }
r[0]=0x0000000cu;
goto P_0c0c1944;
P_0c0c1944: /* original f7e6, guest PC 0x0c0c1944 */
if(!s->budget--) { s->failed_pc=0x0c0c1944u; return 0; }
vf3_matrix_load(s,ram,7,r[14]+r[0]);
goto P_0c0c1946;
P_0c0c1946: /* original e008, guest PC 0x0c0c1946 */
if(!s->budget--) { s->failed_pc=0x0c0c1946u; return 0; }
r[0]=0x00000008u;
goto P_0c0c1948;
P_0c0c1948: /* original f6e6, guest PC 0x0c0c1948 */
if(!s->budget--) { s->failed_pc=0x0c0c1948u; return 0; }
vf3_matrix_load(s,ram,6,r[14]+r[0]);
goto P_0c0c194a;
P_0c0c194a: /* original e004, guest PC 0x0c0c194a */
if(!s->budget--) { s->failed_pc=0x0c0c194au; return 0; }
r[0]=0x00000004u;
goto P_0c0c194c;
P_0c0c194c: /* original f4e8, guest PC 0x0c0c194c */
if(!s->budget--) { s->failed_pc=0x0c0c194cu; return 0; }
vf3_matrix_load(s,ram,4,r[14]);
goto P_0c0c194e;
P_0c0c194e: /* original f5e6, guest PC 0x0c0c194e */
if(!s->budget--) { s->failed_pc=0x0c0c194eu; return 0; }
vf3_matrix_load(s,ram,5,r[14]+r[0]);
goto P_0c0c1950;
P_0c0c1950: /* original 430b, guest PC 0x0c0c1950 */
if(!s->budget--) { s->failed_pc=0x0c0c1950u; return 0; }
target=r[3];
r[16]=0x0c0c1954u;
r[4]=r[15];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c1954u) { target=s->pc; goto dispatch; }
goto P_0c0c1954;
P_0c0c1952: /* original 64f3, guest PC 0x0c0c1952 */
if(!s->budget--) { s->failed_pc=0x0c0c1952u; return 0; }
r[4]=r[15];
goto P_0c0c1954;
P_0c0c1954: /* original e030, guest PC 0x0c0c1954 */
if(!s->budget--) { s->failed_pc=0x0c0c1954u; return 0; }
r[0]=0x00000030u;
goto P_0c0c1956;
P_0c0c1956: /* original e200, guest PC 0x0c0c1956 */
if(!s->budget--) { s->failed_pc=0x0c0c1956u; return 0; }
r[2]=0x00000000u;
goto P_0c0c1958;
P_0c0c1958: /* original 1f2a, guest PC 0x0c0c1958 */
if(!s->budget--) { s->failed_pc=0x0c0c1958u; return 0; }
write(ram,r[15]+40,r[2],4);
goto P_0c0c195a;
P_0c0c195a: /* original 9331, guest PC 0x0c0c195a */
if(!s->budget--) { s->failed_pc=0x0c0c195au; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c19c0u,2);
goto P_0c0c195c;
P_0c0c195c: /* original 1f3b, guest PC 0x0c0c195c */
if(!s->budget--) { s->failed_pc=0x0c0c195cu; return 0; }
write(ram,r[15]+44,r[3],4);
goto P_0c0c195e;
P_0c0c195e: /* original f39d, guest PC 0x0c0c195e */
if(!s->budget--) { s->failed_pc=0x0c0c195eu; return 0; }
fr[3]=0x3f800000u;
goto P_0c0c1960;
P_0c0c1960: /* original ff37, guest PC 0x0c0c1960 */
if(!s->budget--) { s->failed_pc=0x0c0c1960u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0c1962;
P_0c0c1962: /* original d31f, guest PC 0x0c0c1962 */
if(!s->budget--) { s->failed_pc=0x0c0c1962u; return 0; }
r[3]=read(ram,0x0c0c19e0u,4);
goto P_0c0c1964;
P_0c0c1964: /* original 430b, guest PC 0x0c0c1964 */
if(!s->budget--) { s->failed_pc=0x0c0c1964u; return 0; }
target=r[3];
r[16]=0x0c0c1968u;
r[4]=r[15];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c1968u) { target=s->pc; goto dispatch; }
goto P_0c0c1968;
P_0c0c1966: /* original 64f3, guest PC 0x0c0c1966 */
if(!s->budget--) { s->failed_pc=0x0c0c1966u; return 0; }
r[4]=r[15];
goto P_0c0c1968;
P_0c0c1968: /* original c71a, guest PC 0x0c0c1968 */
if(!s->budget--) { s->failed_pc=0x0c0c1968u; return 0; }
r[0]=0x0c0c19d4u;
goto P_0c0c196a;
P_0c0c196a: /* original d31b, guest PC 0x0c0c196a */
if(!s->budget--) { s->failed_pc=0x0c0c196au; return 0; }
r[3]=read(ram,0x0c0c19d8u,4);
goto P_0c0c196c;
P_0c0c196c: /* original f808, guest PC 0x0c0c196c */
if(!s->budget--) { s->failed_pc=0x0c0c196cu; return 0; }
vf3_matrix_load(s,ram,8,r[0]);
goto P_0c0c196e;
P_0c0c196e: /* original c71d, guest PC 0x0c0c196e */
if(!s->budget--) { s->failed_pc=0x0c0c196eu; return 0; }
r[0]=0x0c0c19e4u;
goto P_0c0c1970;
P_0c0c1970: /* original f508, guest PC 0x0c0c1970 */
if(!s->budget--) { s->failed_pc=0x0c0c1970u; return 0; }
vf3_matrix_load(s,ram,5,r[0]);
goto P_0c0c1972;
P_0c0c1972: /* original f4dc, guest PC 0x0c0c1972 */
if(!s->budget--) { s->failed_pc=0x0c0c1972u; return 0; }
vf3_matrix_move(s,4,13);
goto P_0c0c1974;
P_0c0c1974: /* original f7fc, guest PC 0x0c0c1974 */
if(!s->budget--) { s->failed_pc=0x0c0c1974u; return 0; }
vf3_matrix_move(s,7,15);
goto P_0c0c1976;
P_0c0c1976: /* original f6ec, guest PC 0x0c0c1976 */
if(!s->budget--) { s->failed_pc=0x0c0c1976u; return 0; }
vf3_matrix_move(s,6,14);
goto P_0c0c1978;
P_0c0c1978: /* original 430b, guest PC 0x0c0c1978 */
if(!s->budget--) { s->failed_pc=0x0c0c1978u; return 0; }
target=r[3];
r[16]=0x0c0c197cu;
r[4]=r[15];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c197cu) { target=s->pc; goto dispatch; }
goto P_0c0c197c;
P_0c0c197a: /* original 64f3, guest PC 0x0c0c197a */
if(!s->budget--) { s->failed_pc=0x0c0c197au; return 0; }
r[4]=r[15];
goto P_0c0c197c;
P_0c0c197c: /* original e014, guest PC 0x0c0c197c */
if(!s->budget--) { s->failed_pc=0x0c0c197cu; return 0; }
r[0]=0x00000014u;
goto P_0c0c197e;
P_0c0c197e: /* original d317, guest PC 0x0c0c197e */
if(!s->budget--) { s->failed_pc=0x0c0c197eu; return 0; }
r[3]=read(ram,0x0c0c19dcu,4);
goto P_0c0c1980;
P_0c0c1980: /* original f9e6, guest PC 0x0c0c1980 */
if(!s->budget--) { s->failed_pc=0x0c0c1980u; return 0; }
vf3_matrix_load(s,ram,9,r[14]+r[0]);
goto P_0c0c1982;
P_0c0c1982: /* original e010, guest PC 0x0c0c1982 */
if(!s->budget--) { s->failed_pc=0x0c0c1982u; return 0; }
r[0]=0x00000010u;
goto P_0c0c1984;
P_0c0c1984: /* original f8e6, guest PC 0x0c0c1984 */
if(!s->budget--) { s->failed_pc=0x0c0c1984u; return 0; }
vf3_matrix_load(s,ram,8,r[14]+r[0]);
goto P_0c0c1986;
P_0c0c1986: /* original e00c, guest PC 0x0c0c1986 */
if(!s->budget--) { s->failed_pc=0x0c0c1986u; return 0; }
r[0]=0x0000000cu;
goto P_0c0c1988;
P_0c0c1988: /* original f7e6, guest PC 0x0c0c1988 */
if(!s->budget--) { s->failed_pc=0x0c0c1988u; return 0; }
vf3_matrix_load(s,ram,7,r[14]+r[0]);
goto P_0c0c198a;
P_0c0c198a: /* original e008, guest PC 0x0c0c198a */
if(!s->budget--) { s->failed_pc=0x0c0c198au; return 0; }
r[0]=0x00000008u;
goto P_0c0c198c;
P_0c0c198c: /* original f6e6, guest PC 0x0c0c198c */
if(!s->budget--) { s->failed_pc=0x0c0c198cu; return 0; }
vf3_matrix_load(s,ram,6,r[14]+r[0]);
goto P_0c0c198e;
P_0c0c198e: /* original e004, guest PC 0x0c0c198e */
if(!s->budget--) { s->failed_pc=0x0c0c198eu; return 0; }
r[0]=0x00000004u;
goto P_0c0c1990;
P_0c0c1990: /* original f4e8, guest PC 0x0c0c1990 */
if(!s->budget--) { s->failed_pc=0x0c0c1990u; return 0; }
vf3_matrix_load(s,ram,4,r[14]);
goto P_0c0c1992;
P_0c0c1992: /* original f5e6, guest PC 0x0c0c1992 */
if(!s->budget--) { s->failed_pc=0x0c0c1992u; return 0; }
vf3_matrix_load(s,ram,5,r[14]+r[0]);
goto P_0c0c1994;
P_0c0c1994: /* original 430b, guest PC 0x0c0c1994 */
if(!s->budget--) { s->failed_pc=0x0c0c1994u; return 0; }
target=r[3];
r[16]=0x0c0c1998u;
r[4]=r[15];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c1998u) { target=s->pc; goto dispatch; }
goto P_0c0c1998;
P_0c0c1996: /* original 64f3, guest PC 0x0c0c1996 */
if(!s->budget--) { s->failed_pc=0x0c0c1996u; return 0; }
r[4]=r[15];
goto P_0c0c1998;
P_0c0c1998: /* original e030, guest PC 0x0c0c1998 */
if(!s->budget--) { s->failed_pc=0x0c0c1998u; return 0; }
r[0]=0x00000030u;
goto P_0c0c199a;
P_0c0c199a: /* original e200, guest PC 0x0c0c199a */
if(!s->budget--) { s->failed_pc=0x0c0c199au; return 0; }
r[2]=0x00000000u;
goto P_0c0c199c;
P_0c0c199c: /* original 1f2a, guest PC 0x0c0c199c */
if(!s->budget--) { s->failed_pc=0x0c0c199cu; return 0; }
write(ram,r[15]+40,r[2],4);
goto P_0c0c199e;
P_0c0c199e: /* original 930f, guest PC 0x0c0c199e */
if(!s->budget--) { s->failed_pc=0x0c0c199eu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c19c0u,2);
goto P_0c0c19a0;
P_0c0c19a0: /* original 1f3b, guest PC 0x0c0c19a0 */
if(!s->budget--) { s->failed_pc=0x0c0c19a0u; return 0; }
write(ram,r[15]+44,r[3],4);
goto P_0c0c19a2;
P_0c0c19a2: /* original f39d, guest PC 0x0c0c19a2 */
if(!s->budget--) { s->failed_pc=0x0c0c19a2u; return 0; }
fr[3]=0x3f800000u;
goto P_0c0c19a4;
P_0c0c19a4: /* original ff37, guest PC 0x0c0c19a4 */
if(!s->budget--) { s->failed_pc=0x0c0c19a4u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0c19a6;
P_0c0c19a6: /* original d30e, guest PC 0x0c0c19a6 */
if(!s->budget--) { s->failed_pc=0x0c0c19a6u; return 0; }
r[3]=read(ram,0x0c0c19e0u,4);
goto P_0c0c19a8;
P_0c0c19a8: /* original 430b, guest PC 0x0c0c19a8 */
if(!s->budget--) { s->failed_pc=0x0c0c19a8u; return 0; }
target=r[3];
r[16]=0x0c0c19acu;
r[4]=r[15];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c19acu) { target=s->pc; goto dispatch; }
goto P_0c0c19ac;
P_0c0c19aa: /* original 64f3, guest PC 0x0c0c19aa */
if(!s->budget--) { s->failed_pc=0x0c0c19aau; return 0; }
r[4]=r[15];
goto P_0c0c19ac;
P_0c0c19ac: /* original 7f34, guest PC 0x0c0c19ac */
if(!s->budget--) { s->failed_pc=0x0c0c19acu; return 0; }
r[15]+=0x00000034u;
goto P_0c0c19ae;
P_0c0c19ae: /* original 4f26, guest PC 0x0c0c19ae */
if(!s->budget--) { s->failed_pc=0x0c0c19aeu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c19b0;
P_0c0c19b0: /* original fdf9, guest PC 0x0c0c19b0 */
if(!s->budget--) { s->failed_pc=0x0c0c19b0u; return 0; }
vf3_matrix_load(s,ram,13,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0c19b2;
P_0c0c19b2: /* original fef9, guest PC 0x0c0c19b2 */
if(!s->budget--) { s->failed_pc=0x0c0c19b2u; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0c19b4;
P_0c0c19b4: /* original fff9, guest PC 0x0c0c19b4 */
if(!s->budget--) { s->failed_pc=0x0c0c19b4u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0c19b6;
P_0c0c19b6: /* original 000b, guest PC 0x0c0c19b6 */
if(!s->budget--) { s->failed_pc=0x0c0c19b6u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0c19b8: /* original 6ef6, guest PC 0x0c0c19b8 */
if(!s->budget--) { s->failed_pc=0x0c0c19b8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0c19bau,s,ram);
P_0c0c8d64: /* original 4f22, guest PC 0x0c0c8d64 */
if(!s->budget--) { s->failed_pc=0x0c0c8d64u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0c8d66;
P_0c0c8d66: /* original dd36, guest PC 0x0c0c8d66 */
if(!s->budget--) { s->failed_pc=0x0c0c8d66u; return 0; }
r[13]=read(ram,0x0c0c8e40u,4);
goto P_0c0c8d68;
P_0c0c8d68: /* original a00a, guest PC 0x0c0c8d68 */
if(!s->budget--) { s->failed_pc=0x0c0c8d68u; return 0; }
r[14]=r[4];
goto P_0c0c8d80;
P_0c0c8d6a: /* original 6e43, guest PC 0x0c0c8d6a */
if(!s->budget--) { s->failed_pc=0x0c0c8d6au; return 0; }
r[14]=r[4];
goto P_0c0c8d6c;
P_0c0c8d6c: /* original 85e1, guest PC 0x0c0c8d6c */
if(!s->budget--) { s->failed_pc=0x0c0c8d6cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+2,2);
goto P_0c0c8d6e;
P_0c0c8d6e: /* original e307, guest PC 0x0c0c8d6e */
if(!s->budget--) { s->failed_pc=0x0c0c8d6eu; return 0; }
r[3]=0x00000007u;
goto P_0c0c8d70;
P_0c0c8d70: /* original 64e1, guest PC 0x0c0c8d70 */
if(!s->budget--) { s->failed_pc=0x0c0c8d70u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[14],2);
r[4]=tmp;
goto P_0c0c8d72;
P_0c0c8d72: /* original e601, guest PC 0x0c0c8d72 */
if(!s->budget--) { s->failed_pc=0x0c0c8d72u; return 0; }
r[6]=0x00000001u;
goto P_0c0c8d74;
P_0c0c8d74: /* original 403c, guest PC 0x0c0c8d74 */
if(!s->budget--) { s->failed_pc=0x0c0c8d74u; return 0; }
r[0]=(r[3]&0x80000000u)?((r[3]&31u)?(uint32_t)((int32_t)r[0]>>((-r[3])&31u)):((int32_t)r[0]<0?0xffffffffu:0)):r[0]<<(r[3]&31u);
goto P_0c0c8d76;
P_0c0c8d76: /* original 4400, guest PC 0x0c0c8d76 */
if(!s->budget--) { s->failed_pc=0x0c0c8d76u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c0c8d78;
P_0c0c8d78: /* original 240b, guest PC 0x0c0c8d78 */
if(!s->budget--) { s->failed_pc=0x0c0c8d78u; return 0; }
r[4]|=r[0];
goto P_0c0c8d7a;
P_0c0c8d7a: /* original 4d0b, guest PC 0x0c0c8d7a */
if(!s->budget--) { s->failed_pc=0x0c0c8d7au; return 0; }
target=r[13];
r[16]=0x0c0c8d7eu;
r[5]=read(ram,r[14]+4,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c8d7eu) { target=s->pc; goto dispatch; }
goto P_0c0c8d7e;
P_0c0c8d7c: /* original 55e1, guest PC 0x0c0c8d7c */
if(!s->budget--) { s->failed_pc=0x0c0c8d7cu; return 0; }
r[5]=read(ram,r[14]+4,4);
goto P_0c0c8d7e;
P_0c0c8d7e: /* original 7e08, guest PC 0x0c0c8d7e */
if(!s->budget--) { s->failed_pc=0x0c0c8d7eu; return 0; }
r[14]+=0x00000008u;
goto P_0c0c8d80;
P_0c0c8d80: /* original 62e1, guest PC 0x0c0c8d80 */
if(!s->budget--) { s->failed_pc=0x0c0c8d80u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[14],2);
r[2]=tmp;
goto P_0c0c8d82;
P_0c0c8d82: /* original 4211, guest PC 0x0c0c8d82 */
if(!s->budget--) { s->failed_pc=0x0c0c8d82u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>=0)!=0);
goto P_0c0c8d84;
P_0c0c8d84: /* original 89f2, guest PC 0x0c0c8d84 */
if(!s->budget--) { s->failed_pc=0x0c0c8d84u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c8d6c; }
goto P_0c0c8d86;
P_0c0c8d86: /* original 4f26, guest PC 0x0c0c8d86 */
if(!s->budget--) { s->failed_pc=0x0c0c8d86u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c8d88;
P_0c0c8d88: /* original 6df6, guest PC 0x0c0c8d88 */
if(!s->budget--) { s->failed_pc=0x0c0c8d88u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0c8d8a;
P_0c0c8d8a: /* original 000b, guest PC 0x0c0c8d8a */
if(!s->budget--) { s->failed_pc=0x0c0c8d8au; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0c8d8c: /* original 6ef6, guest PC 0x0c0c8d8c */
if(!s->budget--) { s->failed_pc=0x0c0c8d8cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0c8d8eu,s,ram);
P_0c0c9b94: /* original 000b, guest PC 0x0c0c9b94 */
if(!s->budget--) { s->failed_pc=0x0c0c9b94u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c0c9b96: /* original 0009, guest PC 0x0c0c9b96 */
if(!s->budget--) { s->failed_pc=0x0c0c9b96u; return 0; }
goto P_0c0c9b98;
P_0c0c9b98: /* original 000b, guest PC 0x0c0c9b98 */
if(!s->budget--) { s->failed_pc=0x0c0c9b98u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c0c9b9a: /* original 0009, guest PC 0x0c0c9b9a */
if(!s->budget--) { s->failed_pc=0x0c0c9b9au; return 0; }
goto P_0c0c9b9c;
P_0c0c9b9c: /* original 000b, guest PC 0x0c0c9b9c */
if(!s->budget--) { s->failed_pc=0x0c0c9b9cu; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c0c9b9e: /* original 0009, guest PC 0x0c0c9b9e */
if(!s->budget--) { s->failed_pc=0x0c0c9b9eu; return 0; }
return vf3_matrix_family(0x0c0c9ba0u,s,ram);
unsupported: s->failed_pc=target; return 0;
}
static const uint32_t owned_pcs[]={
0x0c042fa0u,0x0c042fa2u,0x0c042fa4u,0x0c042fa6u,0x0c042fa8u,0x0c042faau,0x0c042facu,0x0c042faeu,0x0c042fb0u,0x0c042fb2u,0x0c042fb4u,0x0c042fb6u,0x0c042fb8u,0x0c042fbau,0x0c042fbcu,0x0c042fbeu,
0x0c042fc0u,0x0c042fc2u,0x0c042fc4u,0x0c042fc6u,0x0c042fc8u,0x0c042fcau,0x0c042fccu,0x0c042fceu,0x0c042fd0u,0x0c042fd2u,0x0c042fd4u,0x0c042fd6u,0x0c042fd8u,0x0c06233eu,0x0c062340u,0x0c062342u,
0x0c062344u,0x0c062346u,0x0c062348u,0x0c06234au,0x0c06234cu,0x0c06234eu,0x0c062350u,0x0c062352u,0x0c062354u,0x0c062356u,0x0c062358u,0x0c06235au,0x0c06235cu,0x0c06235eu,0x0c062360u,0x0c062362u,
0x0c062364u,0x0c062366u,0x0c062368u,0x0c06236au,0x0c06236cu,0x0c06236eu,0x0c062370u,0x0c062372u,0x0c062374u,0x0c062376u,0x0c062378u,0x0c06237au,0x0c07ac28u,0x0c07ac2au,0x0c07ac2cu,0x0c07ac2eu,
0x0c07ac30u,0x0c07ac32u,0x0c07ac34u,0x0c07ac36u,0x0c07ac38u,0x0c07ac3au,0x0c07ac3cu,0x0c07ac3eu,0x0c07ac40u,0x0c07ac42u,0x0c07ac44u,0x0c07ac46u,0x0c07ac48u,0x0c07ac4au,0x0c07ac4cu,0x0c07ac4eu,
0x0c07ac50u,0x0c07ac52u,0x0c07ac54u,0x0c07ac56u,0x0c07ac58u,0x0c07ac5au,0x0c07ac5cu,0x0c07ac5eu,0x0c07ac60u,0x0c07ac62u,0x0c07ac64u,0x0c07ac66u,0x0c07ac68u,0x0c07ac6eu,0x0c07ac70u,0x0c07ac72u,
0x0c07ac74u,0x0c07ac76u,0x0c07ac78u,0x0c07ac7au,0x0c07ac7cu,0x0c07ac7eu,0x0c07ac80u,0x0c07ac82u,0x0c07ac84u,0x0c07ac86u,0x0c07ac88u,0x0c07ac8au,0x0c07ac8cu,0x0c07ac8eu,0x0c07ac90u,0x0c07ac92u,
0x0c07ad12u,0x0c07ad14u,0x0c07ad16u,0x0c07ad18u,0x0c07ad1au,0x0c07ad1cu,0x0c07ad1eu,0x0c07ad20u,0x0c07ad22u,0x0c07ad24u,0x0c07ad26u,0x0c07ad28u,0x0c07ad2au,0x0c07ad2cu,0x0c07ad2eu,0x0c07ad30u,
0x0c07ad32u,0x0c07ad34u,0x0c07ad36u,0x0c07ad38u,0x0c07ad3au,0x0c07ad3cu,0x0c07ad3eu,0x0c07ad40u,0x0c07ad42u,0x0c07ad44u,0x0c07ad46u,0x0c07ad48u,0x0c07ad4au,0x0c07ad4cu,0x0c07ad4eu,0x0c07ad50u,
0x0c07ad52u,0x0c07ad54u,0x0c07ad56u,0x0c07ba28u,0x0c07ba2au,0x0c07ba2cu,0x0c07ba2eu,0x0c07ba30u,0x0c07ba32u,0x0c07ba34u,0x0c07ba36u,0x0c07ba38u,0x0c07ba3au,0x0c07ba3cu,0x0c07ba3eu,0x0c07ba40u,
0x0c07ba42u,0x0c07ba44u,0x0c07ba46u,0x0c07ba48u,0x0c07ba4au,0x0c07ba4cu,0x0c07ba4eu,0x0c07ba50u,0x0c07ba52u,0x0c07ba54u,0x0c07ba56u,0x0c07ba58u,0x0c07ba5au,0x0c07ba5cu,0x0c07ba5eu,0x0c07ba60u,
0x0c07ba62u,0x0c07ba64u,0x0c07ba66u,0x0c07ba68u,0x0c07ba6au,0x0c07ba6cu,0x0c07ba6eu,0x0c07ba70u,0x0c07ba72u,0x0c07ba74u,0x0c07ba76u,0x0c07ba78u,0x0c07ba7au,0x0c07ba7cu,0x0c07ba7eu,0x0c07ba80u,
0x0c07ba82u,0x0c07ba84u,0x0c07ba86u,0x0c07ba88u,0x0c07ba8au,0x0c07ba8cu,0x0c07ba8eu,0x0c07ba90u,0x0c07ba92u,0x0c07ba94u,0x0c07ba96u,0x0c07ba98u,0x0c07ba9au,0x0c07ba9cu,0x0c07ba9eu,0x0c07baa0u,
0x0c07baa2u,0x0c07baa4u,0x0c07baa6u,0x0c07baa8u,0x0c07baaau,0x0c07baacu,0x0c07baaeu,0x0c07bab0u,0x0c07bab2u,0x0c07bab4u,0x0c07bab6u,0x0c07bab8u,0x0c07babau,0x0c07babcu,0x0c07babeu,0x0c07bac0u,
0x0c07bac2u,0x0c07bac4u,0x0c07bac6u,0x0c07bac8u,0x0c07bacau,0x0c07baccu,0x0c07baceu,0x0c07bad0u,0x0c07bad2u,0x0c07bad4u,0x0c07bad6u,0x0c07bad8u,0x0c07badau,0x0c07badcu,0x0c07badeu,0x0c07bae0u,
0x0c07bae2u,0x0c07bae4u,0x0c07bae6u,0x0c07bae8u,0x0c07baeau,0x0c07baecu,0x0c07baeeu,0x0c07baf0u,0x0c07baf2u,0x0c07baf4u,0x0c07baf6u,0x0c07baf8u,0x0c07bafau,0x0c07bafcu,0x0c07bafeu,0x0c07bb00u,
0x0c07bb02u,0x0c07bb04u,0x0c07bb06u,0x0c07bb08u,0x0c07bb0au,0x0c07bb0cu,0x0c07bb0eu,0x0c07bb10u,0x0c07bb12u,0x0c07bb14u,0x0c07bb16u,0x0c07bb18u,0x0c07bb1au,0x0c07bb1cu,0x0c07bb1eu,0x0c07bb20u,
0x0c07bb22u,0x0c07bb24u,0x0c07bb26u,0x0c07bb28u,0x0c07bb2au,0x0c07bb2cu,0x0c07bb2eu,0x0c07bb30u,0x0c07bb32u,0x0c07bb34u,0x0c07bb36u,0x0c07bb38u,0x0c07bb3au,0x0c07bb3cu,0x0c07bb3eu,0x0c07bb40u,
0x0c07bb42u,0x0c07bb44u,0x0c07bb46u,0x0c07bba0u,0x0c07bba2u,0x0c07bba4u,0x0c07bba6u,0x0c07bba8u,0x0c07bbaau,0x0c07bbacu,0x0c07bbaeu,0x0c07bbb0u,0x0c07bbb2u,0x0c07bbb4u,0x0c07bbb6u,0x0c07bbb8u,
0x0c07bbbau,0x0c07bbbcu,0x0c07bbbeu,0x0c07bbc0u,0x0c07bbc2u,0x0c07bbc4u,0x0c07bbc6u,0x0c07bbc8u,0x0c07bbcau,0x0c07bbccu,0x0c07bbceu,0x0c07bbd0u,0x0c07bbd2u,0x0c07bbd4u,0x0c07bbd6u,0x0c07bbd8u,
0x0c07bbdau,0x0c07bbdcu,0x0c07bbdeu,0x0c07bbe0u,0x0c07bbe2u,0x0c07bbe4u,0x0c07bbe6u,0x0c07bbe8u,0x0c07bbeau,0x0c07bbecu,0x0c07bbeeu,0x0c07bbf0u,0x0c07bbf2u,0x0c07bbf4u,0x0c07bbf6u,0x0c07bbf8u,
0x0c07bbfau,0x0c07bbfcu,0x0c07bbfeu,0x0c07bc00u,0x0c07bc02u,0x0c07bc04u,0x0c07bc06u,0x0c07bc08u,0x0c07bc0au,0x0c07bc0cu,0x0c07bc0eu,0x0c07bc10u,0x0c07bc12u,0x0c07bc14u,0x0c07bc16u,0x0c07bc18u,
0x0c07bc1au,0x0c07bc1cu,0x0c07bc1eu,0x0c07bc20u,0x0c07bc22u,0x0c07bc24u,0x0c07bc26u,0x0c07bc28u,0x0c07bc2au,0x0c07bc2cu,0x0c07bc2eu,0x0c07bc30u,0x0c07bc32u,0x0c07bc34u,0x0c07bc36u,0x0c07bc38u,
0x0c07bc3au,0x0c07bc3cu,0x0c07bc3eu,0x0c07bc40u,0x0c07bc42u,0x0c07bc44u,0x0c07bc46u,0x0c07bc48u,0x0c07bc4au,0x0c07bc4cu,0x0c07bc4eu,0x0c07bc50u,0x0c07bc52u,0x0c07bc54u,0x0c07bc56u,0x0c07bc58u,
0x0c07bc5au,0x0c07bc5cu,0x0c07bc5eu,0x0c07bc60u,0x0c07bc62u,0x0c07bc64u,0x0c07bc66u,0x0c07bc68u,0x0c07bc6au,0x0c07bc6cu,0x0c07bc6eu,0x0c07bc70u,0x0c07bc72u,0x0c07bc74u,0x0c07bc76u,0x0c07bc78u,
0x0c07bc7au,0x0c07bc7cu,0x0c07bc7eu,0x0c07bc80u,0x0c07bc82u,0x0c07bc84u,0x0c07bc86u,0x0c07bc88u,0x0c07bc8au,0x0c07bc8cu,0x0c07bc8eu,0x0c07bc90u,0x0c07bc92u,0x0c07bc94u,0x0c07bc96u,0x0c07bc98u,
0x0c07bc9au,0x0c07bc9cu,0x0c07bc9eu,0x0c07bca0u,0x0c07bca2u,0x0c07bca4u,0x0c07bca6u,0x0c07bca8u,0x0c07bcaau,0x0c07bcacu,0x0c07bcaeu,0x0c07bcb0u,0x0c07bcb2u,0x0c07bcb4u,0x0c07bcb6u,0x0c07bcb8u,
0x0c07bcbau,0x0c07bcbcu,0x0c07bcbeu,0x0c07bcc0u,0x0c07bcc2u,0x0c07bcc4u,0x0c07bcc6u,0x0c07bcc8u,0x0c07bccau,0x0c07bcccu,0x0c07bcceu,0x0c07bcd0u,0x0c07bcd2u,0x0c07bcd4u,0x0c07bcd6u,0x0c07bcd8u,
0x0c07bcdau,0x0c07bcdcu,0x0c07bcdeu,0x0c07bce0u,0x0c07bce2u,0x0c07bce4u,0x0c07bce6u,0x0c07bce8u,0x0c07bceau,0x0c07bcecu,0x0c07bceeu,0x0c07bcf0u,0x0c07bcf2u,0x0c07bcf4u,0x0c07bcf6u,0x0c07bcf8u,
0x0c07bd14u,0x0c07bd16u,0x0c07bd18u,0x0c07bd1au,0x0c07bd1cu,0x0c07bd1eu,0x0c07bd20u,0x0c07bd22u,0x0c07bd24u,0x0c07bd26u,0x0c07bd28u,0x0c07bd2au,0x0c07bd2cu,0x0c07bd2eu,0x0c07bd30u,0x0c07bd32u,
0x0c07bd34u,0x0c07bd36u,0x0c07bd38u,0x0c07bd3au,0x0c07bd3cu,0x0c07bd3eu,0x0c07bd40u,0x0c07bd42u,0x0c07bd44u,0x0c07bd46u,0x0c07bd48u,0x0c07bd4au,0x0c07bd4cu,0x0c07bd4eu,0x0c07bd50u,0x0c07bd52u,
0x0c07bd54u,0x0c07bd56u,0x0c07bd58u,0x0c07bd5au,0x0c07bd5cu,0x0c07bd5eu,0x0c07bd60u,0x0c07bd62u,0x0c07bd64u,0x0c07bd66u,0x0c07bd68u,0x0c07bd6au,0x0c07bd6cu,0x0c07bd6eu,0x0c07bd70u,0x0c07bd72u,
0x0c07bd74u,0x0c07bd76u,0x0c07bd78u,0x0c07bd7au,0x0c07bd7cu,0x0c07bd7eu,0x0c07bd80u,0x0c07bd82u,0x0c07bd84u,0x0c07bd86u,0x0c07bd88u,0x0c07bd8au,0x0c07bd8cu,0x0c07bd8eu,0x0c07bd90u,0x0c07bd92u,
0x0c07bd94u,0x0c07bd96u,0x0c07bd98u,0x0c07bd9au,0x0c07bd9cu,0x0c07bd9eu,0x0c07bda0u,0x0c07bda2u,0x0c07bda4u,0x0c07bda6u,0x0c07bda8u,0x0c07bdaau,0x0c07bdacu,0x0c07bdaeu,0x0c07bdb0u,0x0c07bdb2u,
0x0c07bdb4u,0x0c07bdb6u,0x0c07bdb8u,0x0c07bdbau,0x0c07bdbcu,0x0c07bdbeu,0x0c07bdc0u,0x0c07bdc2u,0x0c07bdc4u,0x0c07bdc6u,0x0c07bdc8u,0x0c07bdcau,0x0c07bdccu,0x0c07bdceu,0x0c07bdd0u,0x0c07bdd2u,
0x0c07bdd4u,0x0c07bdd6u,0x0c07bdd8u,0x0c07bddau,0x0c07bddcu,0x0c07bddeu,0x0c07bde0u,0x0c07bde2u,0x0c07bde4u,0x0c07bde6u,0x0c07bde8u,0x0c07bdeau,0x0c07bdecu,0x0c07bdeeu,0x0c07bdf0u,0x0c07bdf2u,
0x0c07bdf4u,0x0c07bdf6u,0x0c07bdf8u,0x0c07bdfau,0x0c07bdfcu,0x0c07bdfeu,0x0c07be00u,0x0c07be02u,0x0c07be04u,0x0c07be06u,0x0c07be08u,0x0c07be0au,0x0c07be0cu,0x0c07be0eu,0x0c07be10u,0x0c07be12u,
0x0c07be14u,0x0c07be16u,0x0c07be18u,0x0c07be1au,0x0c07be1cu,0x0c07be1eu,0x0c07be20u,0x0c07be22u,0x0c07be24u,0x0c07be26u,0x0c07be28u,0x0c07be2au,0x0c07be2cu,0x0c07be2eu,0x0c07be30u,0x0c07be32u,
0x0c07be34u,0x0c07be36u,0x0c07be38u,0x0c07be3au,0x0c07be3cu,0x0c07be3eu,0x0c07be40u,0x0c07be42u,0x0c07be44u,0x0c07be46u,0x0c07be48u,0x0c07be4au,0x0c07be4cu,0x0c07be4eu,0x0c07be50u,0x0c07be52u,
0x0c07be54u,0x0c07be56u,0x0c07be58u,0x0c07be5au,0x0c07be5cu,0x0c07be5eu,0x0c07be60u,0x0c07be62u,0x0c07be64u,0x0c07be66u,0x0c07be68u,0x0c07be6au,0x0c07be6cu,0x0c07be6eu,0x0c07be70u,0x0c07be72u,
0x0c07be74u,0x0c07be76u,0x0c07be78u,0x0c07be7au,0x0c07be7cu,0x0c07be7eu,0x0c07be80u,0x0c07be82u,0x0c07be84u,0x0c07be86u,0x0c07be88u,0x0c07be8au,0x0c07be8cu,0x0c07be8eu,0x0c07be90u,0x0c07be92u,
0x0c07be94u,0x0c07be96u,0x0c07be98u,0x0c07be9au,0x0c07beb0u,0x0c07beb2u,0x0c07beb4u,0x0c07beb6u,0x0c07beb8u,0x0c07bebau,0x0c07bebcu,0x0c07bebeu,0x0c07bec0u,0x0c07bec2u,0x0c07bec4u,0x0c07bec6u,
0x0c07bec8u,0x0c07becau,0x0c07beccu,0x0c07beceu,0x0c07bed0u,0x0c07bed2u,0x0c07bed4u,0x0c07bed6u,0x0c07bed8u,0x0c07bedau,0x0c07bedcu,0x0c07bedeu,0x0c07bee0u,0x0c07bee2u,0x0c07bee4u,0x0c07bee6u,
0x0c07bee8u,0x0c07beeau,0x0c07beecu,0x0c07beeeu,0x0c07bef0u,0x0c07bef2u,0x0c07bef4u,0x0c07bef6u,0x0c07bef8u,0x0c07befau,0x0c07befcu,0x0c07befeu,0x0c07bf00u,0x0c07bf02u,0x0c07bf04u,0x0c07bf06u,
0x0c07bf08u,0x0c07bf0au,0x0c07bf0cu,0x0c07bf0eu,0x0c07bf10u,0x0c07bf12u,0x0c07bf14u,0x0c07bf16u,0x0c07bf18u,0x0c07bf1au,0x0c07bf1cu,0x0c07bf1eu,0x0c07bf20u,0x0c07bf22u,0x0c07bf24u,0x0c07bf26u,
0x0c07bf28u,0x0c07bf2au,0x0c07bf2cu,0x0c07bf2eu,0x0c07bf30u,0x0c07bf32u,0x0c07bf34u,0x0c07bf36u,0x0c07bf38u,0x0c07bf3au,0x0c07bf3cu,0x0c07bf3eu,0x0c07bf40u,0x0c07bf42u,0x0c07bf44u,0x0c07bf46u,
0x0c07bf48u,0x0c07bf4au,0x0c07bf4cu,0x0c07bf4eu,0x0c07bf50u,0x0c07bf52u,0x0c07bf54u,0x0c07bf56u,0x0c07bf58u,0x0c07bf5au,0x0c07bf5cu,0x0c07bf5eu,0x0c07bf60u,0x0c07bf62u,0x0c07bf64u,0x0c07bf66u,
0x0c07bf68u,0x0c07bf6au,0x0c07bf6cu,0x0c07bf6eu,0x0c07bf70u,0x0c07bf72u,0x0c07bf74u,0x0c07bf76u,0x0c07bf78u,0x0c07bf7au,0x0c07bf7cu,0x0c07bf7eu,0x0c07bf80u,0x0c07bf82u,0x0c07bf84u,0x0c07bf86u,
0x0c07bf88u,0x0c07bf8au,0x0c07bf8cu,0x0c07bf8eu,0x0c07bf90u,0x0c07bf92u,0x0c07bf94u,0x0c07bf96u,0x0c07bf98u,0x0c07bf9au,0x0c07bf9cu,0x0c07bf9eu,0x0c07bfa0u,0x0c07bfa2u,0x0c07bfa4u,0x0c07bfa6u,
0x0c07bfa8u,0x0c07bfaau,0x0c07bfacu,0x0c07bfaeu,0x0c07bfb0u,0x0c07bfb2u,0x0c07bfb4u,0x0c07bfb6u,0x0c07bfb8u,0x0c07bfbau,0x0c07bfbcu,0x0c07bfbeu,0x0c07bfc0u,0x0c07bfc2u,0x0c07bfc4u,0x0c07bfc6u,
0x0c07bfc8u,0x0c07bfcau,0x0c07bfccu,0x0c07bfceu,0x0c07bfd0u,0x0c07bfd2u,0x0c07bfd4u,0x0c07bfd6u,0x0c07bfd8u,0x0c07bfdau,0x0c07bfdcu,0x0c07bfdeu,0x0c07bfe0u,0x0c07bfe2u,0x0c07bfe4u,0x0c07bfe6u,
0x0c07bfe8u,0x0c07bfeau,0x0c07bfecu,0x0c07bfeeu,0x0c07bff0u,0x0c07bff2u,0x0c07bff4u,0x0c07bff6u,0x0c07bff8u,0x0c07bffau,0x0c07bffcu,0x0c07bffeu,0x0c07c000u,0x0c07c002u,0x0c07c004u,0x0c07c006u,
0x0c07c008u,0x0c07c00au,0x0c07c00cu,0x0c07c00eu,0x0c07c010u,0x0c07c012u,0x0c07c014u,0x0c07c016u,0x0c07c018u,0x0c07c01au,0x0c07c01cu,0x0c07c01eu,0x0c07c020u,0x0c07c022u,0x0c07c024u,0x0c07c026u,
0x0c07c028u,0x0c07c02au,0x0c07c02cu,0x0c07c02eu,0x0c07c030u,0x0c07c032u,0x0c07c034u,0x0c07c036u,0x0c07c038u,0x0c07c03au,0x0c07c03cu,0x0c07c03eu,0x0c07c040u,0x0c07c042u,0x0c07c05cu,0x0c07c05eu,
0x0c07c060u,0x0c07c062u,0x0c07c064u,0x0c07c066u,0x0c07c068u,0x0c07c06au,0x0c07c06cu,0x0c07c06eu,0x0c07c070u,0x0c07c072u,0x0c07c074u,0x0c07c076u,0x0c07c078u,0x0c07c07au,0x0c07c07cu,0x0c07c07eu,
0x0c07c080u,0x0c07c082u,0x0c07c084u,0x0c07c086u,0x0c07c088u,0x0c07c08au,0x0c07c08cu,0x0c07c08eu,0x0c07c090u,0x0c07c092u,0x0c07c094u,0x0c07c096u,0x0c07c098u,0x0c07c09au,0x0c07c09cu,0x0c07c09eu,
0x0c07c0a0u,0x0c07c0a2u,0x0c07c0a4u,0x0c07c0a6u,0x0c07c0a8u,0x0c07c0aau,0x0c07c0acu,0x0c07c0aeu,0x0c07c0b0u,0x0c07c0b2u,0x0c07c0b4u,0x0c07c0b6u,0x0c07c0b8u,0x0c07c0bau,0x0c07c0bcu,0x0c07c0beu,
0x0c07c0c0u,0x0c07c0c2u,0x0c07c0c4u,0x0c07c0c6u,0x0c07c0c8u,0x0c07c0cau,0x0c07c0ccu,0x0c07c0ceu,0x0c07c0d0u,0x0c07c0d2u,0x0c07c0d4u,0x0c07c0d6u,0x0c07c0d8u,0x0c07c0dau,0x0c07c0dcu,0x0c07c0deu,
0x0c07c0e0u,0x0c07c0e2u,0x0c07c0e4u,0x0c07c0e6u,0x0c07c0e8u,0x0c07c0eau,0x0c07c0ecu,0x0c07c0eeu,0x0c07c0f0u,0x0c07c0f2u,0x0c07c0f4u,0x0c07c0f6u,0x0c07c0f8u,0x0c07c0fau,0x0c07c0fcu,0x0c07c0feu,
0x0c07c100u,0x0c07c102u,0x0c07c12cu,0x0c07c12eu,0x0c07c130u,0x0c07c132u,0x0c07c134u,0x0c07c136u,0x0c07c138u,0x0c07c13au,0x0c07c13cu,0x0c07c13eu,0x0c07c140u,0x0c07c142u,0x0c07c144u,0x0c07c146u,
0x0c07c148u,0x0c07c14au,0x0c07c14cu,0x0c07c14eu,0x0c07c150u,0x0c07c152u,0x0c07c154u,0x0c07c156u,0x0c07c158u,0x0c07c15au,0x0c07c15cu,0x0c07c15eu,0x0c07c160u,0x0c07c162u,0x0c07c164u,0x0c07c166u,
0x0c07c168u,0x0c07c16au,0x0c07c16cu,0x0c07c16eu,0x0c07c170u,0x0c07c172u,0x0c07c174u,0x0c07c176u,0x0c07c178u,0x0c07c17au,0x0c07c17cu,0x0c07c17eu,0x0c07c180u,0x0c07c182u,0x0c07c184u,0x0c07c186u,
0x0c07c188u,0x0c07c18au,0x0c07c18cu,0x0c07c18eu,0x0c07c190u,0x0c07c192u,0x0c07c194u,0x0c07c196u,0x0c07c198u,0x0c07c19au,0x0c07c19cu,0x0c07c19eu,0x0c07c1a0u,0x0c07c1a2u,0x0c07c1a4u,0x0c07c1a6u,
0x0c07c1a8u,0x0c07c1aau,0x0c07c1acu,0x0c07c1aeu,0x0c07c1b0u,0x0c07c1b2u,0x0c07c1b4u,0x0c07c1b6u,0x0c07c1b8u,0x0c07c1bau,0x0c07c1bcu,0x0c07c1beu,0x0c07c1c0u,0x0c07c1c2u,0x0c07c1c4u,0x0c07c1c6u,
0x0c07c1c8u,0x0c07c1cau,0x0c07c1ccu,0x0c07c1ceu,0x0c07c1d0u,0x0c07c1d2u,0x0c07c1d4u,0x0c07c1d6u,0x0c07c1d8u,0x0c07c1dau,0x0c07c1dcu,0x0c07c1deu,0x0c07c1e0u,0x0c07c1e2u,0x0c07c1e4u,0x0c07c1e6u,
0x0c07c1e8u,0x0c07c1eau,0x0c07c1ecu,0x0c07c1eeu,0x0c07c1f0u,0x0c07c1f2u,0x0c07c1f4u,0x0c07c1f6u,0x0c07c1f8u,0x0c07c1fau,0x0c07c1fcu,0x0c07c1feu,0x0c07c200u,0x0c07c202u,0x0c07c204u,0x0c07c206u,
0x0c07c208u,0x0c07c20au,0x0c07c20cu,0x0c07c20eu,0x0c07c210u,0x0c07c212u,0x0c07c214u,0x0c07c216u,0x0c07c218u,0x0c07c21au,0x0c07c21cu,0x0c07c21eu,0x0c07c220u,0x0c07c222u,0x0c07c224u,0x0c07c226u,
0x0c07c228u,0x0c07c22au,0x0c07c22cu,0x0c07c22eu,0x0c07c230u,0x0c07c232u,0x0c07c234u,0x0c07c236u,0x0c07c238u,0x0c07c23au,0x0c07c23cu,0x0c07c23eu,0x0c07c240u,0x0c07c242u,0x0c07c244u,0x0c07c246u,
0x0c07c248u,0x0c07c24au,0x0c07c24cu,0x0c07c24eu,0x0c07c250u,0x0c07c252u,0x0c07c254u,0x0c07c256u,0x0c07c258u,0x0c07c25au,0x0c07c25cu,0x0c07c25eu,0x0c07c260u,0x0c07c262u,0x0c07c264u,0x0c07c266u,
0x0c07c268u,0x0c07c26au,0x0c07c26cu,0x0c07c26eu,0x0c07c270u,0x0c07c272u,0x0c07c274u,0x0c07c276u,0x0c07c278u,0x0c07c27au,0x0c07c27cu,0x0c07c27eu,0x0c07c280u,0x0c07c282u,0x0c07c284u,0x0c07c286u,
0x0c07c288u,0x0c07c28au,0x0c07c28cu,0x0c07c28eu,0x0c07c290u,0x0c07c292u,0x0c07c294u,0x0c07c296u,0x0c07c298u,0x0c07c29au,0x0c07c29cu,0x0c07c29eu,0x0c07c2a0u,0x0c07c2a2u,0x0c07c2a4u,0x0c07c2a6u,
0x0c07c2a8u,0x0c07c2aau,0x0c07c2acu,0x0c07c2aeu,0x0c07c2b0u,0x0c07c2b2u,0x0c07c2b4u,0x0c07c2d0u,0x0c07c2d2u,0x0c07c2d4u,0x0c07c2d6u,0x0c07c2d8u,0x0c07c2dau,0x0c07c2dcu,0x0c07c2deu,0x0c07c2e0u,
0x0c07c2e2u,0x0c07c2e4u,0x0c07c2e6u,0x0c07c2e8u,0x0c07c2eau,0x0c07c2ecu,0x0c07c2eeu,0x0c07c2f0u,0x0c07c2f2u,0x0c07c2f4u,0x0c07c2f6u,0x0c07c2f8u,0x0c07c2fau,0x0c07c2fcu,0x0c07c2feu,0x0c07c300u,
0x0c07c302u,0x0c07c304u,0x0c07c306u,0x0c07c308u,0x0c07c30au,0x0c07c30cu,0x0c07c30eu,0x0c07c310u,0x0c07c312u,0x0c07c314u,0x0c07c316u,0x0c07c318u,0x0c07c31au,0x0c07c31cu,0x0c07c31eu,0x0c07c320u,
0x0c07c322u,0x0c07c324u,0x0c07c326u,0x0c07c328u,0x0c07c32au,0x0c07c32cu,0x0c07c32eu,0x0c07c330u,0x0c07c332u,0x0c07c874u,0x0c07c876u,0x0c07c878u,0x0c07c87au,0x0c07c87cu,0x0c07c96au,0x0c07c96cu,
0x0c07c96eu,0x0c07c970u,0x0c07c972u,0x0c07c974u,0x0c07c976u,0x0c07c978u,0x0c07c97au,0x0c07c97cu,0x0c07c97eu,0x0c07c980u,0x0c07c982u,0x0c07c984u,0x0c07c986u,0x0c07c988u,0x0c07c98au,0x0c07c98cu,
0x0c07c98eu,0x0c07c990u,0x0c07c992u,0x0c07c994u,0x0c07c996u,0x0c07c998u,0x0c07c9d4u,0x0c07c9d6u,0x0c07c9d8u,0x0c07c9dau,0x0c07c9dcu,0x0c07c9deu,0x0c07c9e0u,0x0c07c9e2u,0x0c07c9e4u,0x0c07e866u,
0x0c07e868u,0x0c07e86au,0x0c07e86cu,0x0c07e86eu,0x0c07e870u,0x0c07e872u,0x0c07e874u,0x0c07e876u,0x0c07e878u,0x0c07e87au,0x0c07e87cu,0x0c07e87eu,0x0c07e880u,0x0c07e882u,0x0c07e884u,0x0c07e886u,
0x0c07e888u,0x0c07e88au,0x0c07e88cu,0x0c07e88eu,0x0c07e890u,0x0c07e892u,0x0c07e894u,0x0c07e896u,0x0c07e898u,0x0c07e89au,0x0c07e89cu,0x0c07e89eu,0x0c07e8a0u,0x0c07e8a2u,0x0c07e8a4u,0x0c07e8e6u,
0x0c07e8e8u,0x0c07e8eau,0x0c07e8ecu,0x0c07e8eeu,0x0c07e8f0u,0x0c07e8f2u,0x0c07e8f4u,0x0c07e8f6u,0x0c07e8f8u,0x0c07e8fau,0x0c07e8fcu,0x0c07e8feu,0x0c07e900u,0x0c07e902u,0x0c07e904u,0x0c07e906u,
0x0c07e908u,0x0c07e90au,0x0c07e90cu,0x0c07e90eu,0x0c07f722u,0x0c07f724u,0x0c07f726u,0x0c07f728u,0x0c07f72au,0x0c07f72cu,0x0c07f72eu,0x0c07f730u,0x0c07f732u,0x0c07f734u,0x0c07f736u,0x0c07f738u,
0x0c07f73au,0x0c07f73cu,0x0c07f73eu,0x0c07f740u,0x0c07f742u,0x0c07f744u,0x0c07f746u,0x0c07f748u,0x0c07f74au,0x0c07f74cu,0x0c07f74eu,0x0c07f750u,0x0c07f752u,0x0c07f754u,0x0c07f756u,0x0c07f758u,
0x0c07f75au,0x0c07f75cu,0x0c07f75eu,0x0c07f760u,0x0c07f762u,0x0c07f764u,0x0c07f766u,0x0c07f768u,0x0c07f76au,0x0c07f76cu,0x0c07f76eu,0x0c07f770u,0x0c07f772u,0x0c07f774u,0x0c07f776u,0x0c07f778u,
0x0c07f77au,0x0c07f77cu,0x0c07f77eu,0x0c07f780u,0x0c07f782u,0x0c07f784u,0x0c07f786u,0x0c07f788u,0x0c07f78au,0x0c07f78cu,0x0c07f78eu,0x0c07f790u,0x0c07f792u,0x0c07f794u,0x0c07f796u,0x0c07f798u,
0x0c07f79au,0x0c07f79cu,0x0c07f79eu,0x0c07f7a0u,0x0c07f7a2u,0x0c07f7a4u,0x0c07f7a6u,0x0c07f7a8u,0x0c07f7aau,0x0c07f7acu,0x0c07f7aeu,0x0c07f7b0u,0x0c07f7b2u,0x0c07f7b4u,0x0c07f7b6u,0x0c07f7b8u,
0x0c07f7bau,0x0c07f7bcu,0x0c07f7beu,0x0c07f7c0u,0x0c07f7c2u,0x0c07f7c4u,0x0c07f7c6u,0x0c07f7c8u,0x0c07f7cau,0x0c07f7ccu,0x0c07f7ceu,0x0c07f7d0u,0x0c07f7d2u,0x0c07f7d4u,0x0c07f7d6u,0x0c07f7d8u,
0x0c07f7dau,0x0c07f7dcu,0x0c07f7deu,0x0c07f7e0u,0x0c07f7e2u,0x0c07f7e4u,0x0c07f7e6u,0x0c07f7e8u,0x0c07f7eau,0x0c07f7ecu,0x0c07f7eeu,0x0c07f7f0u,0x0c07f7f2u,0x0c07f7f4u,0x0c07f7f6u,0x0c07f7f8u,
0x0c07f7fau,0x0c07f7fcu,0x0c07f7feu,0x0c07f800u,0x0c07f802u,0x0c07f804u,0x0c07f806u,0x0c07f808u,0x0c07f80au,0x0c07f80cu,0x0c07f80eu,0x0c07f810u,0x0c07f812u,0x0c07f814u,0x0c07f816u,0x0c07f818u,
0x0c07f81au,0x0c07f81cu,0x0c07f81eu,0x0c07f820u,0x0c07f822u,0x0c07f824u,0x0c07f826u,0x0c07f828u,0x0c07f82au,0x0c07f82cu,0x0c07f82eu,0x0c07f830u,0x0c07f832u,0x0c07f834u,0x0c07f836u,0x0c07f864u,
0x0c07f866u,0x0c07f868u,0x0c07f86au,0x0c07f86cu,0x0c07f86eu,0x0c07f870u,0x0c07f872u,0x0c07f874u,0x0c07f876u,0x0c07f878u,0x0c07f87au,0x0c07f87cu,0x0c07f87eu,0x0c07f880u,0x0c07f882u,0x0c07f884u,
0x0c07f886u,0x0c07f888u,0x0c07f88au,0x0c07f88cu,0x0c07f88eu,0x0c07f890u,0x0c07f892u,0x0c07f894u,0x0c07f896u,0x0c07f898u,0x0c07f89au,0x0c07f89cu,0x0c07f89eu,0x0c07f8a0u,0x0c07f8a2u,0x0c07f8a4u,
0x0c07f8a6u,0x0c07f8a8u,0x0c07f8aau,0x0c07f8acu,0x0c07f8aeu,0x0c07f8b0u,0x0c07f8b2u,0x0c07f8b4u,0x0c07f8b6u,0x0c07f8b8u,0x0c07f8bau,0x0c07f8bcu,0x0c07f8beu,0x0c07f8c0u,0x0c07f8c2u,0x0c07f8c4u,
0x0c07f8c6u,0x0c07f8c8u,0x0c07f8cau,0x0c07f8ccu,0x0c07f8ceu,0x0c07f8d0u,0x0c07f8d2u,0x0c07f8d4u,0x0c07f8d6u,0x0c07f8d8u,0x0c07f8dau,0x0c07f8dcu,0x0c07f8deu,0x0c07f8e0u,0x0c07f8e2u,0x0c07f8e4u,
0x0c07f8e6u,0x0c07f8e8u,0x0c07f8eau,0x0c07f8ecu,0x0c07f8eeu,0x0c07f8f0u,0x0c07f8f2u,0x0c07f8f4u,0x0c07f8f6u,0x0c07f8f8u,0x0c07f8fau,0x0c07f8fcu,0x0c07f8feu,0x0c07f900u,0x0c07f902u,0x0c07f904u,
0x0c07f906u,0x0c07f908u,0x0c07f90au,0x0c07f90cu,0x0c07f90eu,0x0c07f910u,0x0c07f912u,0x0c07f914u,0x0c07f916u,0x0c07f918u,0x0c07f91au,0x0c07f91cu,0x0c07f91eu,0x0c07f920u,0x0c07f922u,0x0c07f924u,
0x0c07f926u,0x0c07f928u,0x0c07f92au,0x0c07f92cu,0x0c07f92eu,0x0c07f930u,0x0c07f932u,0x0c07f934u,0x0c07f936u,0x0c07f938u,0x0c07f93au,0x0c07f93cu,0x0c07f93eu,0x0c07f940u,0x0c07f942u,0x0c07f944u,
0x0c07f946u,0x0c07f948u,0x0c07f94au,0x0c07f94cu,0x0c07f94eu,0x0c07f950u,0x0c07f952u,0x0c07f954u,0x0c07f956u,0x0c07f958u,0x0c07f95au,0x0c07f95cu,0x0c07f95eu,0x0c07f960u,0x0c07f962u,0x0c07f964u,
0x0c07f966u,0x0c07f968u,0x0c07f96au,0x0c07f96cu,0x0c07f96eu,0x0c07f970u,0x0c07f972u,0x0c07f974u,0x0c07f976u,0x0c07f9c4u,0x0c07f9c6u,0x0c07f9c8u,0x0c07f9cau,0x0c07f9ccu,0x0c07f9ceu,0x0c07f9d0u,
0x0c07f9d2u,0x0c07f9d4u,0x0c07f9d6u,0x0c07f9d8u,0x0c07f9dau,0x0c07f9dcu,0x0c07f9deu,0x0c07f9e0u,0x0c07f9e2u,0x0c07f9e4u,0x0c07f9e6u,0x0c07f9e8u,0x0c07f9eau,0x0c07f9ecu,0x0c07f9eeu,0x0c07f9f0u,
0x0c07f9f2u,0x0c07f9f4u,0x0c07f9f6u,0x0c07f9f8u,0x0c07f9fau,0x0c07f9fcu,0x0c07f9feu,0x0c07fa00u,0x0c07fa02u,0x0c07fa04u,0x0c07fa06u,0x0c07fa08u,0x0c07fa0au,0x0c07fa0cu,0x0c07fa0eu,0x0c07fa10u,
0x0c07fa12u,0x0c07fa14u,0x0c07fa16u,0x0c07fa18u,0x0c07fa1au,0x0c07fa1cu,0x0c07fa1eu,0x0c07fa20u,0x0c07fa22u,0x0c07fa24u,0x0c07fa26u,0x0c07fa28u,0x0c07fa2au,0x0c07fa2cu,0x0c07fa2eu,0x0c07fa30u,
0x0c07fa32u,0x0c07fa34u,0x0c07fa36u,0x0c07fa38u,0x0c07fa3au,0x0c07fa3cu,0x0c07fa3eu,0x0c07fa40u,0x0c07fa42u,0x0c07fa44u,0x0c07fa46u,0x0c07fa48u,0x0c07fa4au,0x0c07fa4cu,0x0c07fa4eu,0x0c07fa50u,
0x0c07fa52u,0x0c07fa54u,0x0c07fa56u,0x0c07fa58u,0x0c07fa5au,0x0c07fa5cu,0x0c07fa5eu,0x0c07fa60u,0x0c07fa62u,0x0c07fa64u,0x0c07fa66u,0x0c07fa68u,0x0c07fa6au,0x0c07fa6cu,0x0c07fa6eu,0x0c07fa70u,
0x0c07fa72u,0x0c07fa74u,0x0c07fa76u,0x0c07fa78u,0x0c07fa7au,0x0c07fa7cu,0x0c07fa7eu,0x0c07fa80u,0x0c07fa82u,0x0c07fa84u,0x0c07fa86u,0x0c07fa88u,0x0c07fa8au,0x0c07fa8cu,0x0c07fa8eu,0x0c07fa90u,
0x0c07fa92u,0x0c07fa94u,0x0c07fa96u,0x0c07fa98u,0x0c07fa9au,0x0c07fa9cu,0x0c07fa9eu,0x0c07faa0u,0x0c07faa2u,0x0c07faa4u,0x0c07faa6u,0x0c07faa8u,0x0c07faaau,0x0c07faacu,0x0c07faaeu,0x0c07fab0u,
0x0c07fab2u,0x0c07fab4u,0x0c07fab6u,0x0c07fab8u,0x0c07fabau,0x0c07fabcu,0x0c07fabeu,0x0c07fac0u,0x0c07fac2u,0x0c07fac4u,0x0c07fac6u,0x0c07fac8u,0x0c07facau,0x0c07faccu,0x0c07faceu,0x0c07fad0u,
0x0c07fad2u,0x0c07fad4u,0x0c07fad6u,0x0c07fad8u,0x0c07fadau,0x0c07fadcu,0x0c07fadeu,0x0c07fb24u,0x0c07fb26u,0x0c07fb28u,0x0c07fb2au,0x0c07fb2cu,0x0c07fb2eu,0x0c07fb30u,0x0c07fb32u,0x0c07fb34u,
0x0c07fb36u,0x0c07fb38u,0x0c07fb3au,0x0c07fb3cu,0x0c07fb3eu,0x0c07fb40u,0x0c07fb42u,0x0c07fb44u,0x0c07fb46u,0x0c07fb48u,0x0c07fb4au,0x0c07fb4cu,0x0c07fb4eu,0x0c07fb50u,0x0c07fb52u,0x0c07fb54u,
0x0c07fb56u,0x0c07fb58u,0x0c07fb5au,0x0c07fb5cu,0x0c07fb5eu,0x0c07fb60u,0x0c07fb62u,0x0c07fb64u,0x0c07fb66u,0x0c07fb68u,0x0c07fb6au,0x0c07fb6cu,0x0c07fb6eu,0x0c07fb70u,0x0c07fb72u,0x0c07fb74u,
0x0c07fb76u,0x0c07fb78u,0x0c07fb7au,0x0c07fb7cu,0x0c07fb7eu,0x0c07fb80u,0x0c07fb82u,0x0c07fb84u,0x0c07fb86u,0x0c07fb88u,0x0c07fb8au,0x0c07fb8cu,0x0c07fb8eu,0x0c07fb90u,0x0c07fb92u,0x0c07fb94u,
0x0c07fb96u,0x0c07fb98u,0x0c07fb9au,0x0c07fb9cu,0x0c07fb9eu,0x0c07fba0u,0x0c07fba2u,0x0c07fba4u,0x0c07fba6u,0x0c07fba8u,0x0c07fbaau,0x0c07fbacu,0x0c07fbaeu,0x0c07fbb0u,0x0c07fbb2u,0x0c07fbb4u,
0x0c07fbb6u,0x0c07fbb8u,0x0c07fbbau,0x0c07fbbcu,0x0c07fbbeu,0x0c07fbc0u,0x0c07fbc2u,0x0c07fbc4u,0x0c07fbc6u,0x0c07fbc8u,0x0c07fbcau,0x0c07fbccu,0x0c07fbceu,0x0c07fbd0u,0x0c07fbd2u,0x0c07fbd4u,
0x0c07fbd6u,0x0c07fbd8u,0x0c07fbdau,0x0c07fbdcu,0x0c07fbdeu,0x0c07fbe0u,0x0c07fbe2u,0x0c080006u,0x0c080008u,0x0c08000au,0x0c08000cu,0x0c08000eu,0x0c080010u,0x0c080012u,0x0c080014u,0x0c080016u,
0x0c080018u,0x0c08001au,0x0c08001cu,0x0c08001eu,0x0c080020u,0x0c080022u,0x0c080024u,0x0c080026u,0x0c080028u,0x0c08002au,0x0c08002cu,0x0c08002eu,0x0c080030u,0x0c080032u,0x0c080034u,0x0c080036u,
0x0c080038u,0x0c08003au,0x0c08003cu,0x0c08003eu,0x0c080040u,0x0c080042u,0x0c080044u,0x0c080046u,0x0c080048u,0x0c08004au,0x0c08004cu,0x0c08004eu,0x0c080050u,0x0c080052u,0x0c080054u,0x0c080056u,
0x0c080058u,0x0c08005au,0x0c08005cu,0x0c08005eu,0x0c080060u,0x0c080062u,0x0c080064u,0x0c080066u,0x0c080068u,0x0c08006au,0x0c08006cu,0x0c08006eu,0x0c080070u,0x0c080072u,0x0c080074u,0x0c080076u,
0x0c080078u,0x0c08007au,0x0c08007cu,0x0c08007eu,0x0c080080u,0x0c080082u,0x0c0800d8u,0x0c0800dau,0x0c0800dcu,0x0c0800deu,0x0c0800e0u,0x0c0800e2u,0x0c0800e4u,0x0c0800e6u,0x0c0800e8u,0x0c0800eau,
0x0c0800ecu,0x0c0800eeu,0x0c0800f0u,0x0c0800f2u,0x0c0800f4u,0x0c0800f6u,0x0c0800f8u,0x0c0800fau,0x0c0800fcu,0x0c0800feu,0x0c080100u,0x0c080102u,0x0c080104u,0x0c080106u,0x0c080108u,0x0c08010au,
0x0c08010cu,0x0c08010eu,0x0c080110u,0x0c08019eu,0x0c0801a0u,0x0c0801a2u,0x0c0801a4u,0x0c0801a6u,0x0c0801a8u,0x0c0801aau,0x0c0801acu,0x0c0801aeu,0x0c0801b0u,0x0c0801b2u,0x0c0801b4u,0x0c0801b6u,
0x0c0801b8u,0x0c0801bau,0x0c0801bcu,0x0c0801beu,0x0c0801c0u,0x0c0801c2u,0x0c0801c4u,0x0c0801c6u,0x0c0801c8u,0x0c0801cau,0x0c0801ccu,0x0c0801ceu,0x0c0801d0u,0x0c0801d2u,0x0c0801d4u,0x0c0801d6u,
0x0c0801d8u,0x0c0801dau,0x0c0801dcu,0x0c080238u,0x0c08023au,0x0c08023cu,0x0c08023eu,0x0c080240u,0x0c080242u,0x0c080244u,0x0c080246u,0x0c080248u,0x0c08024au,0x0c08024cu,0x0c08024eu,0x0c080250u,
0x0c080252u,0x0c080254u,0x0c080256u,0x0c080258u,0x0c08025au,0x0c08025cu,0x0c08025eu,0x0c080260u,0x0c0803feu,0x0c080400u,0x0c080402u,0x0c080404u,0x0c080406u,0x0c080408u,0x0c08040au,0x0c08040cu,
0x0c08040eu,0x0c080410u,0x0c080412u,0x0c080414u,0x0c080416u,0x0c080418u,0x0c08041au,0x0c08041cu,0x0c08041eu,0x0c080420u,0x0c080422u,0x0c080424u,0x0c080426u,0x0c080428u,0x0c08042au,0x0c08042cu,
0x0c08042eu,0x0c080430u,0x0c080432u,0x0c080434u,0x0c080436u,0x0c080438u,0x0c08043au,0x0c08043cu,0x0c08043eu,0x0c080440u,0x0c080442u,0x0c080444u,0x0c080446u,0x0c080448u,0x0c08044au,0x0c08044cu,
0x0c08044eu,0x0c080450u,0x0c080452u,0x0c080454u,0x0c080456u,0x0c080458u,0x0c08045au,0x0c08045cu,0x0c08045eu,0x0c080460u,0x0c080462u,0x0c081a9eu,0x0c081aa0u,0x0c081aa2u,0x0c081aa4u,0x0c081aa6u,
0x0c081aa8u,0x0c081aaau,0x0c081aacu,0x0c081aaeu,0x0c081ab0u,0x0c081ab2u,0x0c081ab4u,0x0c081ab6u,0x0c081ab8u,0x0c081abau,0x0c081abcu,0x0c081abeu,0x0c081ac0u,0x0c081ac2u,0x0c081ac4u,0x0c081ac6u,
0x0c081ac8u,0x0c081acau,0x0c081accu,0x0c081aceu,0x0c081ad0u,0x0c081ad2u,0x0c081ad4u,0x0c081ad6u,0x0c081ad8u,0x0c081adau,0x0c081adcu,0x0c081adeu,0x0c081ae0u,0x0c081ae2u,0x0c081ae4u,0x0c081ae6u,
0x0c081ae8u,0x0c081aeau,0x0c081aecu,0x0c081aeeu,0x0c081af0u,0x0c081af2u,0x0c081af4u,0x0c081af6u,0x0c081af8u,0x0c081afau,0x0c081afcu,0x0c081afeu,0x0c081b00u,0x0c081b02u,0x0c081b04u,0x0c081b06u,
0x0c081b08u,0x0c081b0au,0x0c081b0cu,0x0c081b0eu,0x0c081b10u,0x0c081b12u,0x0c081b14u,0x0c081b16u,0x0c081b18u,0x0c081b1au,0x0c081b1cu,0x0c081b1eu,0x0c081b20u,0x0c081b22u,0x0c081b24u,0x0c081b60u,
0x0c081b62u,0x0c081b64u,0x0c081b66u,0x0c081b68u,0x0c081b6au,0x0c081b6cu,0x0c081b6eu,0x0c081b70u,0x0c081b72u,0x0c081b74u,0x0c081b76u,0x0c081b78u,0x0c081b7au,0x0c081b7cu,0x0c081b7eu,0x0c081b80u,
0x0c081b82u,0x0c081b84u,0x0c081b86u,0x0c081b88u,0x0c081b8au,0x0c081b8cu,0x0c081b8eu,0x0c081b90u,0x0c081b92u,0x0c081b94u,0x0c081b96u,0x0c081b98u,0x0c081b9au,0x0c081b9cu,0x0c081b9eu,0x0c081ba0u,
0x0c081ba2u,0x0c081ba4u,0x0c081ba6u,0x0c081ba8u,0x0c081baau,0x0c081bacu,0x0c081baeu,0x0c081bb0u,0x0c081bb2u,0x0c081bb4u,0x0c081bb6u,0x0c081bb8u,0x0c081bbau,0x0c081bbcu,0x0c081bbeu,0x0c081bc0u,
0x0c081bc2u,0x0c081bc4u,0x0c081bc6u,0x0c081bc8u,0x0c081bcau,0x0c081bccu,0x0c081bceu,0x0c081bd0u,0x0c081bd2u,0x0c081bd4u,0x0c081bd6u,0x0c081bd8u,0x0c081bf0u,0x0c081bf2u,0x0c081bf4u,0x0c081bf6u,
0x0c081bf8u,0x0c081bfau,0x0c081bfcu,0x0c081bfeu,0x0c081c00u,0x0c081c02u,0x0c081c04u,0x0c081c06u,0x0c081c08u,0x0c081c0au,0x0c081c0cu,0x0c081c0eu,0x0c081c10u,0x0c081c12u,0x0c081c14u,0x0c081c16u,
0x0c081c18u,0x0c081c1au,0x0c081c1cu,0x0c081c1eu,0x0c081c20u,0x0c081c22u,0x0c081c24u,0x0c081c26u,0x0c081c28u,0x0c081c2au,0x0c081c2cu,0x0c081c2eu,0x0c081c30u,0x0c081c32u,0x0c081c34u,0x0c081c36u,
0x0c081c38u,0x0c081c3au,0x0c081c3cu,0x0c081c3eu,0x0c081c40u,0x0c081c42u,0x0c081c44u,0x0c081c46u,0x0c081c48u,0x0c081c4au,0x0c081c4cu,0x0c081c4eu,0x0c081c50u,0x0c081c52u,0x0c081c54u,0x0c081c56u,
0x0c081c58u,0x0c081c5au,0x0c081c5cu,0x0c081c5eu,0x0c081c60u,0x0c081c62u,0x0c081c64u,0x0c081c66u,0x0c081c68u,0x0c081c6au,0x0c081c6cu,0x0c081c6eu,0x0c081c70u,0x0c081c72u,0x0c081c74u,0x0c081c76u,
0x0c081c78u,0x0c081c7au,0x0c081c7cu,0x0c081c7eu,0x0c081c80u,0x0c081c82u,0x0c081c84u,0x0c081c86u,0x0c081c88u,0x0c081c8au,0x0c081c8cu,0x0c081c8eu,0x0c081c90u,0x0c081c92u,0x0c081c94u,0x0c081c96u,
0x0c081c98u,0x0c081c9au,0x0c081c9cu,0x0c081c9eu,0x0c081ca0u,0x0c081ca2u,0x0c081ca4u,0x0c081ca6u,0x0c081ca8u,0x0c081caau,0x0c081cacu,0x0c081caeu,0x0c081cb0u,0x0c081cb2u,0x0c081cb4u,0x0c081cb6u,
0x0c081cb8u,0x0c081cbau,0x0c081cbcu,0x0c081cbeu,0x0c081cc0u,0x0c081cc2u,0x0c081cc4u,0x0c081cc6u,0x0c081cc8u,0x0c081ccau,0x0c081cccu,0x0c081cceu,0x0c081cd0u,0x0c081cd2u,0x0c081cd4u,0x0c081cd6u,
0x0c081cd8u,0x0c081cdau,0x0c081cdcu,0x0c081cdeu,0x0c081ce0u,0x0c081ce2u,0x0c081ce4u,0x0c081ce6u,0x0c083c86u,0x0c083c88u,0x0c083c8au,0x0c083c8cu,0x0c083c8eu,0x0c083c90u,0x0c083c92u,0x0c083c94u,
0x0c083c96u,0x0c083c98u,0x0c083c9au,0x0c083c9cu,0x0c083c9eu,0x0c083ca0u,0x0c083ca2u,0x0c083ca4u,0x0c083ca6u,0x0c083ca8u,0x0c083caau,0x0c083cacu,0x0c083caeu,0x0c083cb0u,0x0c083cb2u,0x0c083cb4u,
0x0c083cb6u,0x0c083cb8u,0x0c083cbau,0x0c083cbcu,0x0c083cbeu,0x0c083cc0u,0x0c083cc2u,0x0c083cc4u,0x0c083cc6u,0x0c083cc8u,0x0c083ccau,0x0c083cceu,0x0c083cd0u,0x0c083cd2u,0x0c083cd4u,0x0c083cd6u,
0x0c083cd8u,0x0c083cdau,0x0c083cdcu,0x0c083cdeu,0x0c083ce0u,0x0c083ce2u,0x0c083ce4u,0x0c083ce6u,0x0c083ce8u,0x0c083ceau,0x0c083cecu,0x0c083ceeu,0x0c083cf0u,0x0c083cf2u,0x0c083cf4u,0x0c083cf6u,
0x0c083cf8u,0x0c083cfau,0x0c083cfcu,0x0c083cfeu,0x0c083d00u,0x0c083d02u,0x0c083d04u,0x0c083d06u,0x0c083d08u,0x0c083d0au,0x0c083d0cu,0x0c083d0eu,0x0c083d10u,0x0c083d12u,0x0c085cdcu,0x0c085cdeu,
0x0c085ce0u,0x0c085ce2u,0x0c085ce4u,0x0c085ce6u,0x0c085ce8u,0x0c085ceau,0x0c085cecu,0x0c085ceeu,0x0c085cf0u,0x0c085cf2u,0x0c085cf4u,0x0c085cf6u,0x0c085cf8u,0x0c085cfau,0x0c085cfcu,0x0c085cfeu,
0x0c085d00u,0x0c085d02u,0x0c085d04u,0x0c085d06u,0x0c085d08u,0x0c085d0au,0x0c085d0cu,0x0c085d0eu,0x0c085d10u,0x0c085d12u,0x0c085d14u,0x0c085d16u,0x0c085d18u,0x0c085d1au,0x0c085d1cu,0x0c085d1eu,
0x0c085d20u,0x0c085d22u,0x0c085d24u,0x0c085d26u,0x0c085d28u,0x0c085d2au,0x0c085d2cu,0x0c085d2eu,0x0c085d30u,0x0c085d32u,0x0c085d34u,0x0c085d36u,0x0c085d38u,0x0c085d3au,0x0c085d3cu,0x0c085d3eu,
0x0c085d40u,0x0c085d42u,0x0c085d44u,0x0c085d46u,0x0c085d48u,0x0c085d4au,0x0c085d4cu,0x0c085d4eu,0x0c085d50u,0x0c085d52u,0x0c085d54u,0x0c085d56u,0x0c085d58u,0x0c085d5au,0x0c085d5cu,0x0c085d7cu,
0x0c085d7eu,0x0c085d80u,0x0c085d82u,0x0c085d84u,0x0c085d86u,0x0c085d88u,0x0c085d8au,0x0c085d8cu,0x0c085d8eu,0x0c085d90u,0x0c085d92u,0x0c085d94u,0x0c085d96u,0x0c085d98u,0x0c085d9au,0x0c085d9cu,
0x0c085d9eu,0x0c085da0u,0x0c085da2u,0x0c085da4u,0x0c085da6u,0x0c085da8u,0x0c085daau,0x0c085dacu,0x0c085daeu,0x0c085db0u,0x0c085db2u,0x0c085db4u,0x0c085db6u,0x0c085db8u,0x0c085dbau,0x0c085dbcu,
0x0c085dbeu,0x0c085dc0u,0x0c085dc2u,0x0c085dc4u,0x0c085dc6u,0x0c085dc8u,0x0c085dcau,0x0c085dccu,0x0c085dceu,0x0c085dd0u,0x0c085dd2u,0x0c085dd4u,0x0c085dd6u,0x0c085dd8u,0x0c085ddau,0x0c085ddcu,
0x0c085ddeu,0x0c085de0u,0x0c085de2u,0x0c085de4u,0x0c085de6u,0x0c085de8u,0x0c085deau,0x0c085decu,0x0c085deeu,0x0c085df0u,0x0c085df2u,0x0c085df4u,0x0c085df6u,0x0c085df8u,0x0c085dfau,0x0c085dfcu,
0x0c085dfeu,0x0c085e00u,0x0c085e02u,0x0c085e04u,0x0c085e06u,0x0c085e08u,0x0c085e0au,0x0c085e0cu,0x0c085e0eu,0x0c085e10u,0x0c085e12u,0x0c085e14u,0x0c085e16u,0x0c085e18u,0x0c085e1au,0x0c085e1cu,
0x0c085e1eu,0x0c085e20u,0x0c085e22u,0x0c085e24u,0x0c085e26u,0x0c085e28u,0x0c085e2au,0x0c085e2cu,0x0c085e2eu,0x0c085e30u,0x0c085f96u,0x0c085f98u,0x0c085f9au,0x0c085f9cu,0x0c085f9eu,0x0c085fa0u,
0x0c085fa2u,0x0c085fa4u,0x0c085fa6u,0x0c085fa8u,0x0c085faau,0x0c085facu,0x0c085faeu,0x0c085fb0u,0x0c085fb2u,0x0c085fb4u,0x0c085fb6u,0x0c085fb8u,0x0c085fbau,0x0c085fbcu,0x0c085fbeu,0x0c085fc0u,
0x0c085fc2u,0x0c085fc4u,0x0c085fc6u,0x0c085fc8u,0x0c085fcau,0x0c085fccu,0x0c085fceu,0x0c085fd0u,0x0c085fd2u,0x0c085fd4u,0x0c085fd6u,0x0c085fd8u,0x0c085fdau,0x0c085fdcu,0x0c085fdeu,0x0c085fe0u,
0x0c085fe2u,0x0c085fe4u,0x0c085fe6u,0x0c085fe8u,0x0c085feau,0x0c085fecu,0x0c085feeu,0x0c085ff0u,0x0c085ff2u,0x0c085ff4u,0x0c085ff6u,0x0c085ff8u,0x0c085ffau,0x0c085ffcu,0x0c085ffeu,0x0c086000u,
0x0c086002u,0x0c086004u,0x0c086006u,0x0c086008u,0x0c08600au,0x0c08600cu,0x0c08600eu,0x0c086010u,0x0c086012u,0x0c086014u,0x0c086016u,0x0c086018u,0x0c08601au,0x0c08601cu,0x0c08601eu,0x0c086020u,
0x0c086022u,0x0c086024u,0x0c086026u,0x0c086028u,0x0c08602au,0x0c08602cu,0x0c08602eu,0x0c086030u,0x0c08605au,0x0c08605cu,0x0c08605eu,0x0c086060u,0x0c086062u,0x0c086064u,0x0c086066u,0x0c086068u,
0x0c08606au,0x0c08606cu,0x0c08606eu,0x0c086070u,0x0c086072u,0x0c086074u,0x0c086076u,0x0c086078u,0x0c08607au,0x0c08607cu,0x0c08607eu,0x0c086080u,0x0c086082u,0x0c086084u,0x0c08b648u,0x0c08b64au,
0x0c08b64cu,0x0c08b64eu,0x0c08b650u,0x0c08b652u,0x0c08b654u,0x0c08b656u,0x0c08b658u,0x0c08b65au,0x0c08b65cu,0x0c08b65eu,0x0c08b660u,0x0c08b662u,0x0c08b668u,0x0c08b66au,0x0c08b66cu,0x0c08b66eu,
0x0c08b670u,0x0c08b672u,0x0c08b674u,0x0c08b676u,0x0c08b678u,0x0c08b67au,0x0c08b67cu,0x0c08b67eu,0x0c08b680u,0x0c08b682u,0x0c090c8cu,0x0c090c8eu,0x0c090c90u,0x0c090c92u,0x0c09102au,0x0c09102cu,
0x0c09102eu,0x0c091030u,0x0c091032u,0x0c091034u,0x0c091036u,0x0c091038u,0x0c09103au,0x0c09103cu,0x0c09103eu,0x0c091040u,0x0c091042u,0x0c091044u,0x0c091046u,0x0c091048u,0x0c09104au,0x0c09104cu,
0x0c09104eu,0x0c091050u,0x0c091052u,0x0c091054u,0x0c091056u,0x0c091058u,0x0c09105au,0x0c09105cu,0x0c09105eu,0x0c091060u,0x0c091062u,0x0c091064u,0x0c091066u,0x0c091068u,0x0c09106au,0x0c09106cu,
0x0c09106eu,0x0c091070u,0x0c091072u,0x0c091074u,0x0c091076u,0x0c091078u,0x0c09107au,0x0c09107cu,0x0c09107eu,0x0c091080u,0x0c09493cu,0x0c09493eu,0x0c094940u,0x0c094942u,0x0c094944u,0x0c094946u,
0x0c094948u,0x0c09494au,0x0c09494cu,0x0c09494eu,0x0c094950u,0x0c094952u,0x0c094954u,0x0c094956u,0x0c094958u,0x0c09495au,0x0c09495cu,0x0c09495eu,0x0c094960u,0x0c094962u,0x0c094964u,0x0c094966u,
0x0c094968u,0x0c09496au,0x0c09496cu,0x0c09496eu,0x0c094970u,0x0c094972u,0x0c094974u,0x0c094976u,0x0c094978u,0x0c09497au,0x0c09497cu,0x0c09497eu,0x0c094980u,0x0c094982u,0x0c094984u,0x0c094986u,
0x0c094988u,0x0c09498au,0x0c09498cu,0x0c09498eu,0x0c094990u,0x0c094992u,0x0c094994u,0x0c094996u,0x0c094998u,0x0c09499au,0x0c09499cu,0x0c09499eu,0x0c0949a0u,0x0c0949a2u,0x0c0949a4u,0x0c0949a6u,
0x0c0949a8u,0x0c0949aau,0x0c0949acu,0x0c0949aeu,0x0c0949b0u,0x0c0949b2u,0x0c0949b4u,0x0c0949b6u,0x0c0949b8u,0x0c0949bau,0x0c0949bcu,0x0c0949beu,0x0c0949c0u,0x0c0949c2u,0x0c0949c4u,0x0c0949c6u,
0x0c0949c8u,0x0c0949cau,0x0c0949ccu,0x0c0949ceu,0x0c0949d0u,0x0c0949d2u,0x0c0949d4u,0x0c0949d6u,0x0c0949d8u,0x0c0949dau,0x0c0949dcu,0x0c0949deu,0x0c0949e0u,0x0c0949e2u,0x0c0949e4u,0x0c0949e6u,
0x0c0949e8u,0x0c0949eau,0x0c0949ecu,0x0c0949eeu,0x0c0949f0u,0x0c0949f2u,0x0c0949f4u,0x0c0949f6u,0x0c0949f8u,0x0c0949fau,0x0c0949fcu,0x0c0949feu,0x0c094a00u,0x0c094a02u,0x0c094a04u,0x0c094a06u,
0x0c094a08u,0x0c094a0au,0x0c094a0cu,0x0c094a0eu,0x0c094a10u,0x0c094a12u,0x0c094a14u,0x0c094a16u,0x0c094a18u,0x0c094a1au,0x0c094a1cu,0x0c094a1eu,0x0c094a20u,0x0c094a22u,0x0c094a24u,0x0c094a26u,
0x0c094a28u,0x0c094a2au,0x0c094a2cu,0x0c094a2eu,0x0c094a30u,0x0c094a32u,0x0c094cccu,0x0c094cceu,0x0c094cd0u,0x0c094cd2u,0x0c094cd4u,0x0c094cd6u,0x0c094cd8u,0x0c094cdau,0x0c094cdcu,0x0c094cdeu,
0x0c094ce0u,0x0c094ce2u,0x0c094ce4u,0x0c094ce6u,0x0c094ce8u,0x0c094ceau,0x0c094cecu,0x0c094ceeu,0x0c094cf0u,0x0c094cf2u,0x0c094cf4u,0x0c094cf6u,0x0c094cf8u,0x0c094cfau,0x0c094cfcu,0x0c094cfeu,
0x0c094d00u,0x0c094d02u,0x0c094d04u,0x0c094d06u,0x0c094d08u,0x0c094d0au,0x0c094d0cu,0x0c094d0eu,0x0c094d10u,0x0c094d12u,0x0c094d14u,0x0c094d16u,0x0c094d18u,0x0c094d1au,0x0c094d1cu,0x0c094d1eu,
0x0c094d20u,0x0c094d22u,0x0c094d24u,0x0c094d26u,0x0c094d28u,0x0c094d2au,0x0c094d2cu,0x0c094d2eu,0x0c094d30u,0x0c094d32u,0x0c094d34u,0x0c094d36u,0x0c094d38u,0x0c094d3au,0x0c094d3cu,0x0c094d3eu,
0x0c094d40u,0x0c094d42u,0x0c094d44u,0x0c094d46u,0x0c094d48u,0x0c094d4au,0x0c094d4cu,0x0c094d4eu,0x0c094d50u,0x0c094d52u,0x0c094d54u,0x0c094d56u,0x0c094d58u,0x0c094d5au,0x0c094d5cu,0x0c094d5eu,
0x0c094d60u,0x0c094d62u,0x0c094d64u,0x0c094d66u,0x0c094d68u,0x0c094d6au,0x0c094d6cu,0x0c094d6eu,0x0c094d70u,0x0c094d72u,0x0c094d74u,0x0c094d76u,0x0c094d78u,0x0c094d7au,0x0c094d7cu,0x0c094d7eu,
0x0c094d80u,0x0c094d82u,0x0c094d84u,0x0c094d86u,0x0c094d88u,0x0c094d8au,0x0c094d8cu,0x0c094d8eu,0x0c094d90u,0x0c094d92u,0x0c094d94u,0x0c094d96u,0x0c094d98u,0x0c094d9au,0x0c094d9cu,0x0c09514au,
0x0c09514cu,0x0c09514eu,0x0c095150u,0x0c095152u,0x0c095154u,0x0c095156u,0x0c095158u,0x0c09515au,0x0c09515cu,0x0c09515eu,0x0c095160u,0x0c095162u,0x0c095164u,0x0c095166u,0x0c095168u,0x0c09516au,
0x0c09516cu,0x0c09516eu,0x0c095170u,0x0c095172u,0x0c095174u,0x0c095176u,0x0c0a028au,0x0c0a028cu,0x0c0a028eu,0x0c0a0290u,0x0c0a0292u,0x0c0a0294u,0x0c0a0296u,0x0c0a0298u,0x0c0a029au,0x0c0a029cu,
0x0c0a029eu,0x0c0a02a0u,0x0c0a02a2u,0x0c0a02a4u,0x0c0a02a6u,0x0c0a02a8u,0x0c0a02aau,0x0c0a02acu,0x0c0a02aeu,0x0c0a02b0u,0x0c0a02b2u,0x0c0a02b4u,0x0c0a02b6u,0x0c0a02b8u,0x0c0a02bau,0x0c0a02bcu,
0x0c0a02beu,0x0c0a02c0u,0x0c0a02c2u,0x0c0a02c4u,0x0c0a02c6u,0x0c0a02c8u,0x0c0a02cau,0x0c0a02ccu,0x0c0a02ceu,0x0c0a02d0u,0x0c0a02d2u,0x0c0a02d4u,0x0c0a02d6u,0x0c0a02d8u,0x0c0a02dau,0x0c0a02dcu,
0x0c0a02deu,0x0c0a02e0u,0x0c0a02e2u,0x0c0a02e4u,0x0c0a02e6u,0x0c0a02e8u,0x0c0a02eau,0x0c0a02ecu,0x0c0a02eeu,0x0c0a02f0u,0x0c0a02f2u,0x0c0a02f4u,0x0c0a02f6u,0x0c0a02f8u,0x0c0a02fau,0x0c0a02fcu,
0x0c0a02feu,0x0c0a0300u,0x0c0a0302u,0x0c0a0304u,0x0c0a0306u,0x0c0a0308u,0x0c0a030au,0x0c0a030cu,0x0c0a030eu,0x0c0a0310u,0x0c0a0312u,0x0c0a0314u,0x0c0a0316u,0x0c0a0318u,0x0c0a031au,0x0c0a031cu,
0x0c0a031eu,0x0c0a0320u,0x0c0a0322u,0x0c0a0324u,0x0c0a0326u,0x0c0a0328u,0x0c0a032au,0x0c0a032cu,0x0c0a032eu,0x0c0a036cu,0x0c0a036eu,0x0c0a0370u,0x0c0a0372u,0x0c0a0374u,0x0c0a0376u,0x0c0a0378u,
0x0c0a037au,0x0c0a037cu,0x0c0a037eu,0x0c0a0380u,0x0c0a0382u,0x0c0a0384u,0x0c0a0386u,0x0c0a0388u,0x0c0a038au,0x0c0a038cu,0x0c0a038eu,0x0c0a0390u,0x0c0a0392u,0x0c0a0394u,0x0c0a0396u,0x0c0a0398u,
0x0c0a039au,0x0c0a039cu,0x0c0a039eu,0x0c0a03a0u,0x0c0a03a2u,0x0c0a03a4u,0x0c0a03a6u,0x0c0a03a8u,0x0c0a03aau,0x0c0a03acu,0x0c0a03aeu,0x0c0a03b0u,0x0c0a03b2u,0x0c0a03b4u,0x0c0a03b6u,0x0c0a03b8u,
0x0c0a03bau,0x0c0a03bcu,0x0c0a03beu,0x0c0a03c0u,0x0c0a03c2u,0x0c0a03c4u,0x0c0a03c6u,0x0c0a03c8u,0x0c0a03cau,0x0c0a03ccu,0x0c0a03ceu,0x0c0a03d0u,0x0c0a03d2u,0x0c0a03d4u,0x0c0a03d6u,0x0c0a03d8u,
0x0c0a03dau,0x0c0a03dcu,0x0c0a03f0u,0x0c0a03f2u,0x0c0a03f4u,0x0c0a03f6u,0x0c0a03f8u,0x0c0a03fau,0x0c0a03fcu,0x0c0a03feu,0x0c0a0400u,0x0c0a0402u,0x0c0a0404u,0x0c0a0406u,0x0c0a0408u,0x0c0a040au,
0x0c0a040cu,0x0c0a040eu,0x0c0a0410u,0x0c0a0412u,0x0c0a0414u,0x0c0a0416u,0x0c0a0418u,0x0c0a041au,0x0c0a041cu,0x0c0a058cu,0x0c0a058eu,0x0c0a0590u,0x0c0a0592u,0x0c0a0594u,0x0c0a0596u,0x0c0a0598u,
0x0c0a059au,0x0c0a059cu,0x0c0a059eu,0x0c0a05a0u,0x0c0a05a2u,0x0c0a05a4u,0x0c0a05a6u,0x0c0a05a8u,0x0c0a05aau,0x0c0a05acu,0x0c0a05aeu,0x0c0a05b0u,0x0c0a05b2u,0x0c0a05b4u,0x0c0a05b6u,0x0c0a05b8u,
0x0c0a05bau,0x0c0a05bcu,0x0c0a05beu,0x0c0a05c0u,0x0c0a05c2u,0x0c0a05c4u,0x0c0a05c6u,0x0c0a05c8u,0x0c0a05cau,0x0c0a05ccu,0x0c0a05fcu,0x0c0a05feu,0x0c0a0600u,0x0c0a0602u,0x0c0a0604u,0x0c0a0606u,
0x0c0a0608u,0x0c0a060au,0x0c0a060cu,0x0c0a060eu,0x0c0a0610u,0x0c0a0612u,0x0c0a7784u,0x0c0a7786u,0x0c0a7788u,0x0c0a778au,0x0c0a778cu,0x0c0a778eu,0x0c0a7790u,0x0c0a7792u,0x0c0ad578u,0x0c0ad57au,
0x0c0ad57cu,0x0c0ad57eu,0x0c0ad580u,0x0c0ad582u,0x0c0ad584u,0x0c0ad586u,0x0c0ad588u,0x0c0adb86u,0x0c0adb88u,0x0c0adb8au,0x0c0adb8cu,0x0c0adb8eu,0x0c0adb90u,0x0c0adb92u,0x0c0adb94u,0x0c0adb96u,
0x0c0adb98u,0x0c0adb9au,0x0c0adb9cu,0x0c0adb9eu,0x0c0adba0u,0x0c0adba2u,0x0c0adba4u,0x0c0adba6u,0x0c0adba8u,0x0c0adbaau,0x0c0adbacu,0x0c0adbaeu,0x0c0adbb0u,0x0c0adbb2u,0x0c0adbb4u,0x0c0adbb6u,
0x0c0adbb8u,0x0c0adbbau,0x0c0adbbcu,0x0c0adbbeu,0x0c0adbc0u,0x0c0adbc2u,0x0c0adbc4u,0x0c0adbc6u,0x0c0adbc8u,0x0c0adbcau,0x0c0adbccu,0x0c0adbceu,0x0c0adbd0u,0x0c0adbd2u,0x0c0adbd4u,0x0c0adc72u,
0x0c0adc74u,0x0c0adc76u,0x0c0adc78u,0x0c0adc7au,0x0c0adc7cu,0x0c0adc7eu,0x0c0adc80u,0x0c0adc82u,0x0c0adc84u,0x0c0adc86u,0x0c0adc88u,0x0c0adc8au,0x0c0adc8cu,0x0c0adc8eu,0x0c0adc90u,0x0c0adc92u,
0x0c0adc94u,0x0c0adc96u,0x0c0adc98u,0x0c0adc9au,0x0c0adc9cu,0x0c0adc9eu,0x0c0adca0u,0x0c0adca2u,0x0c0adca4u,0x0c0adca6u,0x0c0adca8u,0x0c0adcaau,0x0c0adcacu,0x0c0adcaeu,0x0c0adcb0u,0x0c0adcb2u,
0x0c0adcb4u,0x0c0adcb6u,0x0c0adcb8u,0x0c0adcbau,0x0c0adcbcu,0x0c0adcbeu,0x0c0adcc0u,0x0c0adcc2u,0x0c0adcc4u,0x0c0adcc6u,0x0c0adcc8u,0x0c0adccau,0x0c0adcccu,0x0c0adcceu,0x0c0adcd0u,0x0c0adcd2u,
0x0c0adcd4u,0x0c0adcd6u,0x0c0adcd8u,0x0c0adcdau,0x0c0adcdcu,0x0c0adcdeu,0x0c0adce0u,0x0c0adce2u,0x0c0adce4u,0x0c0adce6u,0x0c0adce8u,0x0c0adceau,0x0c0adcecu,0x0c0adceeu,0x0c0adcf0u,0x0c0adcf2u,
0x0c0adcf4u,0x0c0adcf6u,0x0c0adcf8u,0x0c0adcfau,0x0c0adcfcu,0x0c0adcfeu,0x0c0add00u,0x0c0add02u,0x0c0add04u,0x0c0add06u,0x0c0add08u,0x0c0add0au,0x0c0add0cu,0x0c0add0eu,0x0c0add10u,0x0c0add12u,
0x0c0add14u,0x0c0add16u,0x0c0add18u,0x0c0add1au,0x0c0add1cu,0x0c0add1eu,0x0c0add20u,0x0c0add22u,0x0c0add24u,0x0c0adf70u,0x0c0adf72u,0x0c0adf74u,0x0c0adf76u,0x0c0adf78u,0x0c0adf7au,0x0c0adf7cu,
0x0c0adf7eu,0x0c0adf80u,0x0c0adf82u,0x0c0adf84u,0x0c0adf86u,0x0c0adf88u,0x0c0adf8au,0x0c0adf8cu,0x0c0adf8eu,0x0c0adf90u,0x0c0adf92u,0x0c0adf94u,0x0c0adf96u,0x0c0adf98u,0x0c0adf9au,0x0c0adf9cu,
0x0c0adf9eu,0x0c0adfa0u,0x0c0adfa2u,0x0c0adfa4u,0x0c0adfa6u,0x0c0adfa8u,0x0c0adfaau,0x0c0adfacu,0x0c0adfaeu,0x0c0adfb0u,0x0c0adfb2u,0x0c0adfb4u,0x0c0adfb6u,0x0c0adfb8u,0x0c0adfbau,0x0c0adfbcu,
0x0c0adfbeu,0x0c0c18feu,0x0c0c1900u,0x0c0c1902u,0x0c0c1904u,0x0c0c1906u,0x0c0c1908u,0x0c0c190au,0x0c0c190cu,0x0c0c190eu,0x0c0c1910u,0x0c0c1912u,0x0c0c1914u,0x0c0c1916u,0x0c0c1918u,0x0c0c191au,
0x0c0c191cu,0x0c0c191eu,0x0c0c1920u,0x0c0c1922u,0x0c0c1924u,0x0c0c1926u,0x0c0c1928u,0x0c0c192au,0x0c0c192cu,0x0c0c192eu,0x0c0c1930u,0x0c0c1932u,0x0c0c1934u,0x0c0c1936u,0x0c0c1938u,0x0c0c193au,
0x0c0c193cu,0x0c0c193eu,0x0c0c1940u,0x0c0c1942u,0x0c0c1944u,0x0c0c1946u,0x0c0c1948u,0x0c0c194au,0x0c0c194cu,0x0c0c194eu,0x0c0c1950u,0x0c0c1952u,0x0c0c1954u,0x0c0c1956u,0x0c0c1958u,0x0c0c195au,
0x0c0c195cu,0x0c0c195eu,0x0c0c1960u,0x0c0c1962u,0x0c0c1964u,0x0c0c1966u,0x0c0c1968u,0x0c0c196au,0x0c0c196cu,0x0c0c196eu,0x0c0c1970u,0x0c0c1972u,0x0c0c1974u,0x0c0c1976u,0x0c0c1978u,0x0c0c197au,
0x0c0c197cu,0x0c0c197eu,0x0c0c1980u,0x0c0c1982u,0x0c0c1984u,0x0c0c1986u,0x0c0c1988u,0x0c0c198au,0x0c0c198cu,0x0c0c198eu,0x0c0c1990u,0x0c0c1992u,0x0c0c1994u,0x0c0c1996u,0x0c0c1998u,0x0c0c199au,
0x0c0c199cu,0x0c0c199eu,0x0c0c19a0u,0x0c0c19a2u,0x0c0c19a4u,0x0c0c19a6u,0x0c0c19a8u,0x0c0c19aau,0x0c0c19acu,0x0c0c19aeu,0x0c0c19b0u,0x0c0c19b2u,0x0c0c19b4u,0x0c0c19b6u,0x0c0c19b8u,0x0c0c8d64u,
0x0c0c8d66u,0x0c0c8d68u,0x0c0c8d6au,0x0c0c8d6cu,0x0c0c8d6eu,0x0c0c8d70u,0x0c0c8d72u,0x0c0c8d74u,0x0c0c8d76u,0x0c0c8d78u,0x0c0c8d7au,0x0c0c8d7cu,0x0c0c8d7eu,0x0c0c8d80u,0x0c0c8d82u,0x0c0c8d84u,
0x0c0c8d86u,0x0c0c8d88u,0x0c0c8d8au,0x0c0c8d8cu,0x0c0c9b94u,0x0c0c9b96u,0x0c0c9b98u,0x0c0c9b9au,0x0c0c9b9cu,0x0c0c9b9eu,
};
int vf3_target_retained_scene_adapter_contains(uint32_t pc) {
pc&=0x1fffffffu; unsigned lo=0,hi=sizeof(owned_pcs)/sizeof(owned_pcs[0]);
while(lo<hi) { unsigned mid=lo+(hi-lo)/2; if(owned_pcs[mid]<pc) lo=mid+1; else hi=mid; }
return lo<sizeof(owned_pcs)/sizeof(owned_pcs[0]) && owned_pcs[lo]==pc;
}
