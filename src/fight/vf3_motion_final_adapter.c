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
int vf3_motion_final_adapter(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c06cf30u: goto P_0c06cf30;
case 0x0c06cf32u: goto P_0c06cf32;
case 0x0c06cf34u: goto P_0c06cf34;
case 0x0c06cf36u: goto P_0c06cf36;
case 0x0c06cf38u: goto P_0c06cf38;
case 0x0c06cf3au: goto P_0c06cf3a;
case 0x0c06cf3cu: goto P_0c06cf3c;
case 0x0c06cf3eu: goto P_0c06cf3e;
case 0x0c06cf40u: goto P_0c06cf40;
case 0x0c06cf42u: goto P_0c06cf42;
case 0x0c06cf44u: goto P_0c06cf44;
case 0x0c06cf46u: goto P_0c06cf46;
case 0x0c06cf48u: goto P_0c06cf48;
case 0x0c06cf4au: goto P_0c06cf4a;
case 0x0c06cf4cu: goto P_0c06cf4c;
case 0x0c06cf4eu: goto P_0c06cf4e;
case 0x0c06cf50u: goto P_0c06cf50;
case 0x0c06cf52u: goto P_0c06cf52;
case 0x0c06cf54u: goto P_0c06cf54;
case 0x0c06cf56u: goto P_0c06cf56;
case 0x0c06cf58u: goto P_0c06cf58;
case 0x0c06cf5au: goto P_0c06cf5a;
case 0x0c06cf5cu: goto P_0c06cf5c;
case 0x0c06cf5eu: goto P_0c06cf5e;
case 0x0c06cf60u: goto P_0c06cf60;
case 0x0c06cf62u: goto P_0c06cf62;
case 0x0c06cf64u: goto P_0c06cf64;
case 0x0c06cf66u: goto P_0c06cf66;
case 0x0c06cf68u: goto P_0c06cf68;
case 0x0c06cf6au: goto P_0c06cf6a;
case 0x0c06cf6cu: goto P_0c06cf6c;
case 0x0c06cf6eu: goto P_0c06cf6e;
case 0x0c06cf70u: goto P_0c06cf70;
case 0x0c06cf72u: goto P_0c06cf72;
case 0x0c06cf74u: goto P_0c06cf74;
case 0x0c06cf76u: goto P_0c06cf76;
case 0x0c06cf78u: goto P_0c06cf78;
case 0x0c06cf7au: goto P_0c06cf7a;
case 0x0c06cf7cu: goto P_0c06cf7c;
case 0x0c06cf7eu: goto P_0c06cf7e;
case 0x0c06cf80u: goto P_0c06cf80;
case 0x0c06cf82u: goto P_0c06cf82;
case 0x0c06cf84u: goto P_0c06cf84;
case 0x0c06cf86u: goto P_0c06cf86;
case 0x0c06cf88u: goto P_0c06cf88;
case 0x0c06cf8au: goto P_0c06cf8a;
case 0x0c06cf8cu: goto P_0c06cf8c;
case 0x0c06cf8eu: goto P_0c06cf8e;
case 0x0c06cf90u: goto P_0c06cf90;
case 0x0c06cf92u: goto P_0c06cf92;
case 0x0c06cf94u: goto P_0c06cf94;
case 0x0c06cf96u: goto P_0c06cf96;
case 0x0c06cf98u: goto P_0c06cf98;
case 0x0c06cf9au: goto P_0c06cf9a;
case 0x0c06cf9cu: goto P_0c06cf9c;
case 0x0c06cf9eu: goto P_0c06cf9e;
case 0x0c06cfa0u: goto P_0c06cfa0;
case 0x0c06cfa2u: goto P_0c06cfa2;
case 0x0c06cfa4u: goto P_0c06cfa4;
case 0x0c06cfa6u: goto P_0c06cfa6;
case 0x0c06cfa8u: goto P_0c06cfa8;
case 0x0c06cfaau: goto P_0c06cfaa;
case 0x0c06cfacu: goto P_0c06cfac;
case 0x0c06cfaeu: goto P_0c06cfae;
case 0x0c06cfb0u: goto P_0c06cfb0;
case 0x0c06cfb2u: goto P_0c06cfb2;
case 0x0c06cfb4u: goto P_0c06cfb4;
case 0x0c06cfb6u: goto P_0c06cfb6;
case 0x0c06cfb8u: goto P_0c06cfb8;
case 0x0c06cfbau: goto P_0c06cfba;
case 0x0c06cfbcu: goto P_0c06cfbc;
case 0x0c06cfbeu: goto P_0c06cfbe;
case 0x0c06cfc0u: goto P_0c06cfc0;
case 0x0c06cfc2u: goto P_0c06cfc2;
case 0x0c06cfc4u: goto P_0c06cfc4;
case 0x0c06cfc6u: goto P_0c06cfc6;
case 0x0c06cfc8u: goto P_0c06cfc8;
case 0x0c06cfcau: goto P_0c06cfca;
case 0x0c06cfccu: goto P_0c06cfcc;
case 0x0c06cfceu: goto P_0c06cfce;
case 0x0c072e2cu: goto P_0c072e2c;
case 0x0c072e2eu: goto P_0c072e2e;
case 0x0c072e30u: goto P_0c072e30;
case 0x0c072e32u: goto P_0c072e32;
case 0x0c072e34u: goto P_0c072e34;
case 0x0c072e36u: goto P_0c072e36;
case 0x0c072e38u: goto P_0c072e38;
case 0x0c072e3au: goto P_0c072e3a;
case 0x0c072e3cu: goto P_0c072e3c;
case 0x0c072e3eu: goto P_0c072e3e;
case 0x0c072e40u: goto P_0c072e40;
case 0x0c072e42u: goto P_0c072e42;
case 0x0c072e44u: goto P_0c072e44;
case 0x0c072e46u: goto P_0c072e46;
case 0x0c072e48u: goto P_0c072e48;
case 0x0c072e4au: goto P_0c072e4a;
case 0x0c072e4cu: goto P_0c072e4c;
case 0x0c072e4eu: goto P_0c072e4e;
case 0x0c072e50u: goto P_0c072e50;
case 0x0c072e52u: goto P_0c072e52;
case 0x0c072e54u: goto P_0c072e54;
case 0x0c072e56u: goto P_0c072e56;
case 0x0c072e58u: goto P_0c072e58;
case 0x0c072e5au: goto P_0c072e5a;
case 0x0c072e5cu: goto P_0c072e5c;
case 0x0c072e5eu: goto P_0c072e5e;
case 0x0c072e60u: goto P_0c072e60;
case 0x0c072e62u: goto P_0c072e62;
case 0x0c072e64u: goto P_0c072e64;
case 0x0c072e66u: goto P_0c072e66;
case 0x0c072e68u: goto P_0c072e68;
case 0x0c072e6au: goto P_0c072e6a;
case 0x0c072e6cu: goto P_0c072e6c;
case 0x0c072e6eu: goto P_0c072e6e;
case 0x0c072e70u: goto P_0c072e70;
case 0x0c072e72u: goto P_0c072e72;
case 0x0c072e74u: goto P_0c072e74;
case 0x0c072e76u: goto P_0c072e76;
case 0x0c072e78u: goto P_0c072e78;
case 0x0c072e7au: goto P_0c072e7a;
case 0x0c072e7cu: goto P_0c072e7c;
case 0x0c072e7eu: goto P_0c072e7e;
case 0x0c072e80u: goto P_0c072e80;
case 0x0c072e82u: goto P_0c072e82;
case 0x0c072e84u: goto P_0c072e84;
case 0x0c072e86u: goto P_0c072e86;
case 0x0c072e88u: goto P_0c072e88;
case 0x0c072e8au: goto P_0c072e8a;
case 0x0c072e8cu: goto P_0c072e8c;
case 0x0c072e8eu: goto P_0c072e8e;
case 0x0c072e90u: goto P_0c072e90;
case 0x0c072e92u: goto P_0c072e92;
case 0x0c072e94u: goto P_0c072e94;
case 0x0c072e96u: goto P_0c072e96;
case 0x0c072e98u: goto P_0c072e98;
case 0x0c072e9au: goto P_0c072e9a;
case 0x0c072e9cu: goto P_0c072e9c;
case 0x0c072e9eu: goto P_0c072e9e;
case 0x0c072ea0u: goto P_0c072ea0;
case 0x0c072ea2u: goto P_0c072ea2;
case 0x0c072ea4u: goto P_0c072ea4;
case 0x0c072ea6u: goto P_0c072ea6;
case 0x0c072ea8u: goto P_0c072ea8;
case 0x0c072eaau: goto P_0c072eaa;
case 0x0c072eacu: goto P_0c072eac;
case 0x0c072eaeu: goto P_0c072eae;
case 0x0c072eb0u: goto P_0c072eb0;
case 0x0c072eb2u: goto P_0c072eb2;
case 0x0c072eb4u: goto P_0c072eb4;
case 0x0c072eb6u: goto P_0c072eb6;
case 0x0c072eb8u: goto P_0c072eb8;
case 0x0c072ebau: goto P_0c072eba;
case 0x0c072ebcu: goto P_0c072ebc;
case 0x0c072ebeu: goto P_0c072ebe;
case 0x0c072ec0u: goto P_0c072ec0;
case 0x0c08e5ceu: goto P_0c08e5ce;
case 0x0c08e5d0u: goto P_0c08e5d0;
case 0x0c08e5d2u: goto P_0c08e5d2;
case 0x0c08e5d4u: goto P_0c08e5d4;
case 0x0c08e5d6u: goto P_0c08e5d6;
case 0x0c08e5d8u: goto P_0c08e5d8;
case 0x0c08e5dau: goto P_0c08e5da;
case 0x0c08e5dcu: goto P_0c08e5dc;
case 0x0c08e5deu: goto P_0c08e5de;
case 0x0c08e5e0u: goto P_0c08e5e0;
case 0x0c08e5e2u: goto P_0c08e5e2;
case 0x0c08e5e4u: goto P_0c08e5e4;
case 0x0c08e5e6u: goto P_0c08e5e6;
case 0x0c08e5e8u: goto P_0c08e5e8;
case 0x0c08e5eau: goto P_0c08e5ea;
case 0x0c08e5ecu: goto P_0c08e5ec;
case 0x0c08e5eeu: goto P_0c08e5ee;
case 0x0c08e5f0u: goto P_0c08e5f0;
case 0x0c08e5f2u: goto P_0c08e5f2;
case 0x0c08e5f4u: goto P_0c08e5f4;
case 0x0c08e5f6u: goto P_0c08e5f6;
case 0x0c08e5f8u: goto P_0c08e5f8;
case 0x0c08e5fau: goto P_0c08e5fa;
case 0x0c08e5fcu: goto P_0c08e5fc;
case 0x0c08e5feu: goto P_0c08e5fe;
case 0x0c08e600u: goto P_0c08e600;
case 0x0c08e602u: goto P_0c08e602;
case 0x0c08e604u: goto P_0c08e604;
case 0x0c08e606u: goto P_0c08e606;
case 0x0c08e608u: goto P_0c08e608;
case 0x0c08e60au: goto P_0c08e60a;
case 0x0c08e60cu: goto P_0c08e60c;
case 0x0c08e60eu: goto P_0c08e60e;
case 0x0c08e610u: goto P_0c08e610;
case 0x0c08e612u: goto P_0c08e612;
case 0x0c08e614u: goto P_0c08e614;
case 0x0c08e616u: goto P_0c08e616;
case 0x0c08e618u: goto P_0c08e618;
case 0x0c08e61au: goto P_0c08e61a;
case 0x0c08e61cu: goto P_0c08e61c;
case 0x0c08e61eu: goto P_0c08e61e;
case 0x0c08e620u: goto P_0c08e620;
case 0x0c08e622u: goto P_0c08e622;
case 0x0c08e624u: goto P_0c08e624;
case 0x0c08e626u: goto P_0c08e626;
case 0x0c08e628u: goto P_0c08e628;
case 0x0c08e62au: goto P_0c08e62a;
case 0x0c08e62cu: goto P_0c08e62c;
case 0x0c08e62eu: goto P_0c08e62e;
case 0x0c08e630u: goto P_0c08e630;
case 0x0c08e632u: goto P_0c08e632;
case 0x0c08e634u: goto P_0c08e634;
case 0x0c08e636u: goto P_0c08e636;
case 0x0c08e638u: goto P_0c08e638;
case 0x0c08e63au: goto P_0c08e63a;
case 0x0c08e63cu: goto P_0c08e63c;
case 0x0c08e63eu: goto P_0c08e63e;
case 0x0c08e640u: goto P_0c08e640;
case 0x0c08e642u: goto P_0c08e642;
case 0x0c08e644u: goto P_0c08e644;
case 0x0c08e646u: goto P_0c08e646;
case 0x0c08e648u: goto P_0c08e648;
case 0x0c08e64au: goto P_0c08e64a;
case 0x0c08e64cu: goto P_0c08e64c;
case 0x0c08e64eu: goto P_0c08e64e;
case 0x0c08e650u: goto P_0c08e650;
case 0x0c08e652u: goto P_0c08e652;
case 0x0c08e654u: goto P_0c08e654;
case 0x0c08e656u: goto P_0c08e656;
case 0x0c08e658u: goto P_0c08e658;
case 0x0c08e65au: goto P_0c08e65a;
case 0x0c08e65cu: goto P_0c08e65c;
case 0x0c08e65eu: goto P_0c08e65e;
case 0x0c08e660u: goto P_0c08e660;
case 0x0c08e662u: goto P_0c08e662;
case 0x0c08e664u: goto P_0c08e664;
case 0x0c08e666u: goto P_0c08e666;
case 0x0c08e668u: goto P_0c08e668;
case 0x0c08e66au: goto P_0c08e66a;
case 0x0c08e66cu: goto P_0c08e66c;
case 0x0c08e66eu: goto P_0c08e66e;
case 0x0c09fe7au: goto P_0c09fe7a;
case 0x0c09fe7cu: goto P_0c09fe7c;
case 0x0c09fe7eu: goto P_0c09fe7e;
case 0x0c09fe80u: goto P_0c09fe80;
case 0x0c09fe82u: goto P_0c09fe82;
case 0x0c09fe84u: goto P_0c09fe84;
case 0x0c09fe86u: goto P_0c09fe86;
case 0x0c09fe88u: goto P_0c09fe88;
case 0x0c09fe8au: goto P_0c09fe8a;
case 0x0c09fe8cu: goto P_0c09fe8c;
case 0x0c09fe8eu: goto P_0c09fe8e;
case 0x0c09fe90u: goto P_0c09fe90;
case 0x0c09fe92u: goto P_0c09fe92;
case 0x0c09fe94u: goto P_0c09fe94;
case 0x0c09fe96u: goto P_0c09fe96;
case 0x0c09fe98u: goto P_0c09fe98;
case 0x0c09fe9au: goto P_0c09fe9a;
case 0x0c09fe9cu: goto P_0c09fe9c;
case 0x0c09fe9eu: goto P_0c09fe9e;
case 0x0c09fea0u: goto P_0c09fea0;
case 0x0c09fea2u: goto P_0c09fea2;
case 0x0c09fea4u: goto P_0c09fea4;
case 0x0c09fea6u: goto P_0c09fea6;
case 0x0c09fea8u: goto P_0c09fea8;
case 0x0c09feaau: goto P_0c09feaa;
case 0x0c09feacu: goto P_0c09feac;
case 0x0c09feaeu: goto P_0c09feae;
case 0x0c09feb0u: goto P_0c09feb0;
case 0x0c09feb2u: goto P_0c09feb2;
case 0x0c09feb4u: goto P_0c09feb4;
case 0x0c09feb6u: goto P_0c09feb6;
case 0x0c09feb8u: goto P_0c09feb8;
case 0x0c09febau: goto P_0c09feba;
case 0x0c09febcu: goto P_0c09febc;
case 0x0c09febeu: goto P_0c09febe;
case 0x0c09fec0u: goto P_0c09fec0;
case 0x0c09fec2u: goto P_0c09fec2;
case 0x0c09fec4u: goto P_0c09fec4;
case 0x0c09fec6u: goto P_0c09fec6;
case 0x0c09fec8u: goto P_0c09fec8;
case 0x0c09fecau: goto P_0c09feca;
case 0x0c09feccu: goto P_0c09fecc;
case 0x0c09feceu: goto P_0c09fece;
case 0x0c09fed0u: goto P_0c09fed0;
case 0x0c09fed2u: goto P_0c09fed2;
case 0x0c09fed4u: goto P_0c09fed4;
case 0x0c09fed6u: goto P_0c09fed6;
case 0x0c09fed8u: goto P_0c09fed8;
case 0x0c09fedau: goto P_0c09feda;
case 0x0c09fedcu: goto P_0c09fedc;
case 0x0c09fedeu: goto P_0c09fede;
case 0x0c09fee0u: goto P_0c09fee0;
case 0x0c09fee2u: goto P_0c09fee2;
case 0x0c09fee4u: goto P_0c09fee4;
case 0x0c09fee6u: goto P_0c09fee6;
case 0x0c09fee8u: goto P_0c09fee8;
case 0x0c09feeau: goto P_0c09feea;
case 0x0c09feecu: goto P_0c09feec;
case 0x0c09feeeu: goto P_0c09feee;
case 0x0c09fef0u: goto P_0c09fef0;
case 0x0c09fef2u: goto P_0c09fef2;
case 0x0c09fef4u: goto P_0c09fef4;
case 0x0c09fef6u: goto P_0c09fef6;
case 0x0c09fef8u: goto P_0c09fef8;
case 0x0c09fefau: goto P_0c09fefa;
case 0x0c09fefcu: goto P_0c09fefc;
case 0x0c0a2e06u: goto P_0c0a2e06;
case 0x0c0a2e08u: goto P_0c0a2e08;
case 0x0c0a2e0au: goto P_0c0a2e0a;
case 0x0c0a2e0cu: goto P_0c0a2e0c;
case 0x0c0a2e0eu: goto P_0c0a2e0e;
case 0x0c0a2e10u: goto P_0c0a2e10;
case 0x0c0a2e12u: goto P_0c0a2e12;
case 0x0c0a2e14u: goto P_0c0a2e14;
case 0x0c0a2e16u: goto P_0c0a2e16;
case 0x0c0a2e18u: goto P_0c0a2e18;
case 0x0c0a2e1au: goto P_0c0a2e1a;
case 0x0c0a2e1cu: goto P_0c0a2e1c;
case 0x0c0a2e1eu: goto P_0c0a2e1e;
case 0x0c0a2e20u: goto P_0c0a2e20;
case 0x0c0a2e22u: goto P_0c0a2e22;
case 0x0c0a2e24u: goto P_0c0a2e24;
case 0x0c0a2e26u: goto P_0c0a2e26;
case 0x0c0a2e28u: goto P_0c0a2e28;
case 0x0c0a2e2au: goto P_0c0a2e2a;
case 0x0c0a2e2cu: goto P_0c0a2e2c;
case 0x0c0a2e2eu: goto P_0c0a2e2e;
case 0x0c0a2e30u: goto P_0c0a2e30;
case 0x0c0a2e32u: goto P_0c0a2e32;
case 0x0c0a2e34u: goto P_0c0a2e34;
case 0x0c0a2e36u: goto P_0c0a2e36;
case 0x0c0a2e38u: goto P_0c0a2e38;
case 0x0c0a2e3au: goto P_0c0a2e3a;
case 0x0c0a2e3cu: goto P_0c0a2e3c;
case 0x0c0a2e3eu: goto P_0c0a2e3e;
case 0x0c0a2e40u: goto P_0c0a2e40;
case 0x0c0a2e42u: goto P_0c0a2e42;
case 0x0c0a2e44u: goto P_0c0a2e44;
case 0x0c0a2e46u: goto P_0c0a2e46;
case 0x0c0a3414u: goto P_0c0a3414;
case 0x0c0a3416u: goto P_0c0a3416;
case 0x0c0a3418u: goto P_0c0a3418;
case 0x0c0a341au: goto P_0c0a341a;
case 0x0c0a341cu: goto P_0c0a341c;
case 0x0c0a341eu: goto P_0c0a341e;
case 0x0c0a3420u: goto P_0c0a3420;
case 0x0c0a3422u: goto P_0c0a3422;
case 0x0c0a3424u: goto P_0c0a3424;
case 0x0c0a3426u: goto P_0c0a3426;
case 0x0c0a3428u: goto P_0c0a3428;
case 0x0c0a342au: goto P_0c0a342a;
case 0x0c0a342cu: goto P_0c0a342c;
case 0x0c0a342eu: goto P_0c0a342e;
case 0x0c0a3430u: goto P_0c0a3430;
case 0x0c0a3432u: goto P_0c0a3432;
case 0x0c0a3434u: goto P_0c0a3434;
case 0x0c0a3436u: goto P_0c0a3436;
case 0x0c0a3438u: goto P_0c0a3438;
case 0x0c0a343au: goto P_0c0a343a;
case 0x0c0a343cu: goto P_0c0a343c;
case 0x0c0a343eu: goto P_0c0a343e;
case 0x0c0a3440u: goto P_0c0a3440;
case 0x0c0a3442u: goto P_0c0a3442;
case 0x0c0a3444u: goto P_0c0a3444;
case 0x0c0a3446u: goto P_0c0a3446;
case 0x0c0a3448u: goto P_0c0a3448;
case 0x0c0a344au: goto P_0c0a344a;
case 0x0c0a344cu: goto P_0c0a344c;
case 0x0c0a344eu: goto P_0c0a344e;
case 0x0c0a3450u: goto P_0c0a3450;
case 0x0c0a3452u: goto P_0c0a3452;
case 0x0c0a3454u: goto P_0c0a3454;
case 0x0c0a3456u: goto P_0c0a3456;
case 0x0c0a3458u: goto P_0c0a3458;
case 0x0c0a345au: goto P_0c0a345a;
case 0x0c0a345cu: goto P_0c0a345c;
case 0x0c0a345eu: goto P_0c0a345e;
case 0x0c0a3460u: goto P_0c0a3460;
case 0x0c0a3462u: goto P_0c0a3462;
case 0x0c0a3464u: goto P_0c0a3464;
case 0x0c0a3466u: goto P_0c0a3466;
case 0x0c0a3468u: goto P_0c0a3468;
case 0x0c0a346au: goto P_0c0a346a;
case 0x0c0a346cu: goto P_0c0a346c;
case 0x0c0a346eu: goto P_0c0a346e;
case 0x0c0a3470u: goto P_0c0a3470;
case 0x0c0a3472u: goto P_0c0a3472;
case 0x0c0a3474u: goto P_0c0a3474;
case 0x0c0a3476u: goto P_0c0a3476;
case 0x0c0a3478u: goto P_0c0a3478;
case 0x0c0a347au: goto P_0c0a347a;
case 0x0c0a347cu: goto P_0c0a347c;
case 0x0c0a347eu: goto P_0c0a347e;
case 0x0c0a3480u: goto P_0c0a3480;
case 0x0c0a3482u: goto P_0c0a3482;
case 0x0c0a3484u: goto P_0c0a3484;
case 0x0c0a3486u: goto P_0c0a3486;
case 0x0c0a3488u: goto P_0c0a3488;
case 0x0c0a348au: goto P_0c0a348a;
case 0x0c0a348cu: goto P_0c0a348c;
case 0x0c0a348eu: goto P_0c0a348e;
case 0x0c0a3490u: goto P_0c0a3490;
case 0x0c0a3492u: goto P_0c0a3492;
case 0x0c0a3494u: goto P_0c0a3494;
case 0x0c0a3496u: goto P_0c0a3496;
case 0x0c0a3498u: goto P_0c0a3498;
case 0x0c0a349au: goto P_0c0a349a;
case 0x0c0a349cu: goto P_0c0a349c;
case 0x0c0a349eu: goto P_0c0a349e;
case 0x0c0a34a0u: goto P_0c0a34a0;
case 0x0c0a34a2u: goto P_0c0a34a2;
case 0x0c0a34a4u: goto P_0c0a34a4;
case 0x0c0a34a6u: goto P_0c0a34a6;
case 0x0c0a34a8u: goto P_0c0a34a8;
case 0x0c0a34aau: goto P_0c0a34aa;
case 0x0c0a34acu: goto P_0c0a34ac;
case 0x0c0a34aeu: goto P_0c0a34ae;
case 0x0c0a34b0u: goto P_0c0a34b0;
case 0x0c0a34b2u: goto P_0c0a34b2;
case 0x0c0a34b4u: goto P_0c0a34b4;
case 0x0c0a34b6u: goto P_0c0a34b6;
case 0x0c0a34b8u: goto P_0c0a34b8;
case 0x0c0a34bau: goto P_0c0a34ba;
case 0x0c0a34bcu: goto P_0c0a34bc;
case 0x0c0a34beu: goto P_0c0a34be;
case 0x0c0a34c0u: goto P_0c0a34c0;
case 0x0c0a34c2u: goto P_0c0a34c2;
case 0x0c0a34c4u: goto P_0c0a34c4;
case 0x0c0a34c6u: goto P_0c0a34c6;
case 0x0c0a34c8u: goto P_0c0a34c8;
case 0x0c0a34cau: goto P_0c0a34ca;
case 0x0c0a34ccu: goto P_0c0a34cc;
case 0x0c0a34ceu: goto P_0c0a34ce;
case 0x0c0a34d0u: goto P_0c0a34d0;
case 0x0c0a34d2u: goto P_0c0a34d2;
case 0x0c0a34d4u: goto P_0c0a34d4;
case 0x0c0a34d6u: goto P_0c0a34d6;
case 0x0c0a34d8u: goto P_0c0a34d8;
case 0x0c0a34dau: goto P_0c0a34da;
case 0x0c0a3696u: goto P_0c0a3696;
case 0x0c0a3698u: goto P_0c0a3698;
case 0x0c0a369au: goto P_0c0a369a;
case 0x0c0a369cu: goto P_0c0a369c;
case 0x0c0a369eu: goto P_0c0a369e;
case 0x0c0a36a0u: goto P_0c0a36a0;
case 0x0c0a36a2u: goto P_0c0a36a2;
case 0x0c0a36a4u: goto P_0c0a36a4;
case 0x0c0a36a6u: goto P_0c0a36a6;
case 0x0c0a36a8u: goto P_0c0a36a8;
case 0x0c0a36aau: goto P_0c0a36aa;
case 0x0c0a36acu: goto P_0c0a36ac;
case 0x0c0a36aeu: goto P_0c0a36ae;
case 0x0c0a36b0u: goto P_0c0a36b0;
case 0x0c0a36b2u: goto P_0c0a36b2;
case 0x0c0a36b4u: goto P_0c0a36b4;
case 0x0c0a36b6u: goto P_0c0a36b6;
case 0x0c0a36b8u: goto P_0c0a36b8;
case 0x0c0a36bau: goto P_0c0a36ba;
case 0x0c0a36bcu: goto P_0c0a36bc;
case 0x0c0a36beu: goto P_0c0a36be;
case 0x0c0a36c0u: goto P_0c0a36c0;
case 0x0c0a36c2u: goto P_0c0a36c2;
case 0x0c0a36c4u: goto P_0c0a36c4;
case 0x0c0a36c6u: goto P_0c0a36c6;
case 0x0c0a36c8u: goto P_0c0a36c8;
case 0x0c0a36cau: goto P_0c0a36ca;
case 0x0c0a36ccu: goto P_0c0a36cc;
case 0x0c0a36ceu: goto P_0c0a36ce;
case 0x0c0a36d0u: goto P_0c0a36d0;
case 0x0c0a36d2u: goto P_0c0a36d2;
case 0x0c0a36d4u: goto P_0c0a36d4;
case 0x0c0a36d6u: goto P_0c0a36d6;
case 0x0c0a36d8u: goto P_0c0a36d8;
case 0x0c0a36dau: goto P_0c0a36da;
case 0x0c0a36dcu: goto P_0c0a36dc;
case 0x0c0a36deu: goto P_0c0a36de;
case 0x0c0a36e0u: goto P_0c0a36e0;
case 0x0c0a36e2u: goto P_0c0a36e2;
case 0x0c0a36e4u: goto P_0c0a36e4;
case 0x0c0a36e6u: goto P_0c0a36e6;
case 0x0c0a36e8u: goto P_0c0a36e8;
case 0x0c0a36eau: goto P_0c0a36ea;
case 0x0c0a36ecu: goto P_0c0a36ec;
case 0x0c0a36eeu: goto P_0c0a36ee;
case 0x0c0a36f0u: goto P_0c0a36f0;
case 0x0c0a36f2u: goto P_0c0a36f2;
case 0x0c0a36f4u: goto P_0c0a36f4;
case 0x0c0a36f6u: goto P_0c0a36f6;
case 0x0c0a36f8u: goto P_0c0a36f8;
case 0x0c0a36fau: goto P_0c0a36fa;
case 0x0c0a36fcu: goto P_0c0a36fc;
case 0x0c0a36feu: goto P_0c0a36fe;
case 0x0c0a3700u: goto P_0c0a3700;
case 0x0c0a3702u: goto P_0c0a3702;
case 0x0c0a3704u: goto P_0c0a3704;
case 0x0c0a3706u: goto P_0c0a3706;
case 0x0c0a3708u: goto P_0c0a3708;
case 0x0c0a370au: goto P_0c0a370a;
case 0x0c0a370cu: goto P_0c0a370c;
case 0x0c0a370eu: goto P_0c0a370e;
case 0x0c0a3710u: goto P_0c0a3710;
case 0x0c0a3712u: goto P_0c0a3712;
case 0x0c0a3714u: goto P_0c0a3714;
case 0x0c0a374au: goto P_0c0a374a;
case 0x0c0a374cu: goto P_0c0a374c;
case 0x0c0a374eu: goto P_0c0a374e;
case 0x0c0a3750u: goto P_0c0a3750;
case 0x0c0a3752u: goto P_0c0a3752;
case 0x0c0a3754u: goto P_0c0a3754;
case 0x0c0a3756u: goto P_0c0a3756;
case 0x0c0a3758u: goto P_0c0a3758;
case 0x0c0a375au: goto P_0c0a375a;
case 0x0c0a375cu: goto P_0c0a375c;
case 0x0c0a375eu: goto P_0c0a375e;
case 0x0c0a3760u: goto P_0c0a3760;
case 0x0c0a3762u: goto P_0c0a3762;
case 0x0c0a3764u: goto P_0c0a3764;
case 0x0c0a3766u: goto P_0c0a3766;
case 0x0c0a3768u: goto P_0c0a3768;
case 0x0c0a376au: goto P_0c0a376a;
case 0x0c0a376cu: goto P_0c0a376c;
case 0x0c0a376eu: goto P_0c0a376e;
case 0x0c0a3770u: goto P_0c0a3770;
case 0x0c0a3772u: goto P_0c0a3772;
case 0x0c0a3774u: goto P_0c0a3774;
case 0x0c0a3776u: goto P_0c0a3776;
case 0x0c0a3778u: goto P_0c0a3778;
case 0x0c0a377au: goto P_0c0a377a;
case 0x0c0a377cu: goto P_0c0a377c;
case 0x0c0a377eu: goto P_0c0a377e;
case 0x0c0a3780u: goto P_0c0a3780;
case 0x0c0a3782u: goto P_0c0a3782;
case 0x0c0a3784u: goto P_0c0a3784;
case 0x0c0a3786u: goto P_0c0a3786;
case 0x0c0a3788u: goto P_0c0a3788;
case 0x0c0a378au: goto P_0c0a378a;
case 0x0c0a378cu: goto P_0c0a378c;
case 0x0c0a378eu: goto P_0c0a378e;
case 0x0c0a3790u: goto P_0c0a3790;
case 0x0c0a3792u: goto P_0c0a3792;
case 0x0c0a3794u: goto P_0c0a3794;
case 0x0c0a3796u: goto P_0c0a3796;
case 0x0c0a3798u: goto P_0c0a3798;
case 0x0c0a379au: goto P_0c0a379a;
case 0x0c0a379cu: goto P_0c0a379c;
case 0x0c0a379eu: goto P_0c0a379e;
case 0x0c0a37a0u: goto P_0c0a37a0;
case 0x0c0a37a2u: goto P_0c0a37a2;
case 0x0c0a37a4u: goto P_0c0a37a4;
case 0x0c0a37a6u: goto P_0c0a37a6;
case 0x0c0a37a8u: goto P_0c0a37a8;
case 0x0c0a37aau: goto P_0c0a37aa;
case 0x0c0a37acu: goto P_0c0a37ac;
case 0x0c0a37aeu: goto P_0c0a37ae;
case 0x0c0a37b0u: goto P_0c0a37b0;
case 0x0c0a37b2u: goto P_0c0a37b2;
case 0x0c0a37b4u: goto P_0c0a37b4;
case 0x0c0a37b6u: goto P_0c0a37b6;
case 0x0c0a37b8u: goto P_0c0a37b8;
case 0x0c0a37bau: goto P_0c0a37ba;
case 0x0c0a37bcu: goto P_0c0a37bc;
case 0x0c0a37beu: goto P_0c0a37be;
case 0x0c0a37c0u: goto P_0c0a37c0;
case 0x0c0a37c2u: goto P_0c0a37c2;
case 0x0c0a37c4u: goto P_0c0a37c4;
case 0x0c0a37c6u: goto P_0c0a37c6;
case 0x0c0a37c8u: goto P_0c0a37c8;
case 0x0c0a37cau: goto P_0c0a37ca;
case 0x0c0a37ccu: goto P_0c0a37cc;
case 0x0c0a37ceu: goto P_0c0a37ce;
case 0x0c0a37d0u: goto P_0c0a37d0;
case 0x0c0a37d2u: goto P_0c0a37d2;
case 0x0c0a37d4u: goto P_0c0a37d4;
case 0x0c0a37d6u: goto P_0c0a37d6;
case 0x0c0a37d8u: goto P_0c0a37d8;
case 0x0c0a37dau: goto P_0c0a37da;
case 0x0c0a37dcu: goto P_0c0a37dc;
case 0x0c0a37deu: goto P_0c0a37de;
case 0x0c0a37e0u: goto P_0c0a37e0;
case 0x0c0a37e2u: goto P_0c0a37e2;
case 0x0c0a37e4u: goto P_0c0a37e4;
case 0x0c0a37e6u: goto P_0c0a37e6;
case 0x0c0a37e8u: goto P_0c0a37e8;
case 0x0c0a37eau: goto P_0c0a37ea;
case 0x0c0a37ecu: goto P_0c0a37ec;
case 0x0c0a37eeu: goto P_0c0a37ee;
case 0x0c0a37f0u: goto P_0c0a37f0;
case 0x0c0a37f2u: goto P_0c0a37f2;
case 0x0c0a37f4u: goto P_0c0a37f4;
case 0x0c0a37f6u: goto P_0c0a37f6;
case 0x0c0a37f8u: goto P_0c0a37f8;
case 0x0c0a37fau: goto P_0c0a37fa;
case 0x0c0a37fcu: goto P_0c0a37fc;
case 0x0c0a37feu: goto P_0c0a37fe;
case 0x0c0a3800u: goto P_0c0a3800;
case 0x0c0a3802u: goto P_0c0a3802;
case 0x0c0a3804u: goto P_0c0a3804;
case 0x0c0a3806u: goto P_0c0a3806;
case 0x0c0a3808u: goto P_0c0a3808;
case 0x0c0a380au: goto P_0c0a380a;
case 0x0c0a380cu: goto P_0c0a380c;
case 0x0c0a380eu: goto P_0c0a380e;
case 0x0c0a3810u: goto P_0c0a3810;
case 0x0c0a3812u: goto P_0c0a3812;
case 0x0c0a3814u: goto P_0c0a3814;
case 0x0c0a3816u: goto P_0c0a3816;
case 0x0c0a3818u: goto P_0c0a3818;
case 0x0c0a381au: goto P_0c0a381a;
case 0x0c0a381cu: goto P_0c0a381c;
case 0x0c0a381eu: goto P_0c0a381e;
case 0x0c0a3820u: goto P_0c0a3820;
case 0x0c0a3822u: goto P_0c0a3822;
case 0x0c0a3824u: goto P_0c0a3824;
case 0x0c0a3826u: goto P_0c0a3826;
case 0x0c0a3828u: goto P_0c0a3828;
case 0x0c0a382au: goto P_0c0a382a;
case 0x0c0a382cu: goto P_0c0a382c;
case 0x0c0a382eu: goto P_0c0a382e;
case 0x0c0a3830u: goto P_0c0a3830;
case 0x0c0a3832u: goto P_0c0a3832;
case 0x0c0a3834u: goto P_0c0a3834;
case 0x0c0a3836u: goto P_0c0a3836;
case 0x0c0a3838u: goto P_0c0a3838;
case 0x0c0a383au: goto P_0c0a383a;
case 0x0c0a383cu: goto P_0c0a383c;
case 0x0c0a383eu: goto P_0c0a383e;
case 0x0c0a3840u: goto P_0c0a3840;
case 0x0c0a3842u: goto P_0c0a3842;
case 0x0c0a3844u: goto P_0c0a3844;
case 0x0c0a3846u: goto P_0c0a3846;
case 0x0c0a3848u: goto P_0c0a3848;
case 0x0c0a384au: goto P_0c0a384a;
case 0x0c0a384cu: goto P_0c0a384c;
case 0x0c0a384eu: goto P_0c0a384e;
case 0x0c0a3850u: goto P_0c0a3850;
case 0x0c0a3852u: goto P_0c0a3852;
case 0x0c0a3854u: goto P_0c0a3854;
case 0x0c0a3856u: goto P_0c0a3856;
case 0x0c0a3858u: goto P_0c0a3858;
case 0x0c0a396cu: goto P_0c0a396c;
case 0x0c0a396eu: goto P_0c0a396e;
case 0x0c0a3970u: goto P_0c0a3970;
case 0x0c0a3972u: goto P_0c0a3972;
case 0x0c0a3974u: goto P_0c0a3974;
case 0x0c0a3976u: goto P_0c0a3976;
case 0x0c0a3978u: goto P_0c0a3978;
case 0x0c0a397au: goto P_0c0a397a;
case 0x0c0a397cu: goto P_0c0a397c;
case 0x0c0a397eu: goto P_0c0a397e;
case 0x0c0a3980u: goto P_0c0a3980;
case 0x0c0a3982u: goto P_0c0a3982;
case 0x0c0a3984u: goto P_0c0a3984;
case 0x0c0a3986u: goto P_0c0a3986;
case 0x0c0a3988u: goto P_0c0a3988;
case 0x0c0a398au: goto P_0c0a398a;
case 0x0c0a398cu: goto P_0c0a398c;
case 0x0c0a398eu: goto P_0c0a398e;
case 0x0c0a3990u: goto P_0c0a3990;
case 0x0c0a3992u: goto P_0c0a3992;
case 0x0c0a3994u: goto P_0c0a3994;
case 0x0c0a3996u: goto P_0c0a3996;
case 0x0c0a3998u: goto P_0c0a3998;
case 0x0c0a399au: goto P_0c0a399a;
case 0x0c0a399cu: goto P_0c0a399c;
case 0x0c0a399eu: goto P_0c0a399e;
case 0x0c0a39a0u: goto P_0c0a39a0;
case 0x0c0a39a2u: goto P_0c0a39a2;
case 0x0c0a39a4u: goto P_0c0a39a4;
case 0x0c0a39a6u: goto P_0c0a39a6;
case 0x0c0a39a8u: goto P_0c0a39a8;
case 0x0c0a39aau: goto P_0c0a39aa;
case 0x0c0a39acu: goto P_0c0a39ac;
case 0x0c0a39aeu: goto P_0c0a39ae;
case 0x0c0a39b0u: goto P_0c0a39b0;
case 0x0c0a39b2u: goto P_0c0a39b2;
case 0x0c0a39b4u: goto P_0c0a39b4;
case 0x0c0a39b6u: goto P_0c0a39b6;
case 0x0c0a39b8u: goto P_0c0a39b8;
case 0x0c0a39bau: goto P_0c0a39ba;
case 0x0c0a39bcu: goto P_0c0a39bc;
case 0x0c0a39beu: goto P_0c0a39be;
case 0x0c0a39c0u: goto P_0c0a39c0;
case 0x0c0a39c2u: goto P_0c0a39c2;
case 0x0c0a39c4u: goto P_0c0a39c4;
case 0x0c0a39c6u: goto P_0c0a39c6;
case 0x0c0a39c8u: goto P_0c0a39c8;
case 0x0c0a39cau: goto P_0c0a39ca;
case 0x0c0a39ccu: goto P_0c0a39cc;
case 0x0c0a39ceu: goto P_0c0a39ce;
case 0x0c0a39d0u: goto P_0c0a39d0;
case 0x0c0a39d2u: goto P_0c0a39d2;
case 0x0c0a39d4u: goto P_0c0a39d4;
case 0x0c0a39d6u: goto P_0c0a39d6;
case 0x0c0a39d8u: goto P_0c0a39d8;
case 0x0c0a39dau: goto P_0c0a39da;
case 0x0c0a39dcu: goto P_0c0a39dc;
case 0x0c0a39deu: goto P_0c0a39de;
case 0x0c0a39e0u: goto P_0c0a39e0;
case 0x0c0a39e2u: goto P_0c0a39e2;
case 0x0c0a39e4u: goto P_0c0a39e4;
case 0x0c0a39e6u: goto P_0c0a39e6;
case 0x0c0a39e8u: goto P_0c0a39e8;
case 0x0c0a39eau: goto P_0c0a39ea;
case 0x0c0a39ecu: goto P_0c0a39ec;
case 0x0c0a39eeu: goto P_0c0a39ee;
case 0x0c0a39f0u: goto P_0c0a39f0;
case 0x0c0a39f2u: goto P_0c0a39f2;
case 0x0c0a39f4u: goto P_0c0a39f4;
case 0x0c0a39f6u: goto P_0c0a39f6;
case 0x0c0a39f8u: goto P_0c0a39f8;
case 0x0c0a39fau: goto P_0c0a39fa;
case 0x0c0a39fcu: goto P_0c0a39fc;
case 0x0c0a39feu: goto P_0c0a39fe;
case 0x0c0a3a00u: goto P_0c0a3a00;
case 0x0c0a3a02u: goto P_0c0a3a02;
case 0x0c0a3a04u: goto P_0c0a3a04;
case 0x0c0a3a06u: goto P_0c0a3a06;
case 0x0c0a3a08u: goto P_0c0a3a08;
case 0x0c0a3a0au: goto P_0c0a3a0a;
case 0x0c0a3a0cu: goto P_0c0a3a0c;
case 0x0c0a3a0eu: goto P_0c0a3a0e;
case 0x0c0a3a10u: goto P_0c0a3a10;
case 0x0c0a3a12u: goto P_0c0a3a12;
case 0x0c0a3a14u: goto P_0c0a3a14;
case 0x0c0a3a16u: goto P_0c0a3a16;
case 0x0c0a3a18u: goto P_0c0a3a18;
case 0x0c0a3a1au: goto P_0c0a3a1a;
case 0x0c0a3a1cu: goto P_0c0a3a1c;
case 0x0c0a3a1eu: goto P_0c0a3a1e;
case 0x0c0a3a20u: goto P_0c0a3a20;
case 0x0c0a3a22u: goto P_0c0a3a22;
case 0x0c0a3a24u: goto P_0c0a3a24;
case 0x0c0a3a26u: goto P_0c0a3a26;
case 0x0c0a3a28u: goto P_0c0a3a28;
case 0x0c0a3a2au: goto P_0c0a3a2a;
case 0x0c0a3a2cu: goto P_0c0a3a2c;
case 0x0c0a3a2eu: goto P_0c0a3a2e;
case 0x0c0a3a30u: goto P_0c0a3a30;
case 0x0c0a3a32u: goto P_0c0a3a32;
case 0x0c0a3a34u: goto P_0c0a3a34;
case 0x0c0a3a36u: goto P_0c0a3a36;
case 0x0c0a3a38u: goto P_0c0a3a38;
case 0x0c0a3a3au: goto P_0c0a3a3a;
case 0x0c0a3a3cu: goto P_0c0a3a3c;
case 0x0c0a3a3eu: goto P_0c0a3a3e;
case 0x0c0a3a40u: goto P_0c0a3a40;
case 0x0c0a3a42u: goto P_0c0a3a42;
case 0x0c0a3a44u: goto P_0c0a3a44;
case 0x0c0a3a46u: goto P_0c0a3a46;
case 0x0c0a3a48u: goto P_0c0a3a48;
case 0x0c0a3a4au: goto P_0c0a3a4a;
case 0x0c0a3a4cu: goto P_0c0a3a4c;
case 0x0c0a3a4eu: goto P_0c0a3a4e;
case 0x0c0a3a50u: goto P_0c0a3a50;
case 0x0c0a3a52u: goto P_0c0a3a52;
case 0x0c0a3a54u: goto P_0c0a3a54;
case 0x0c0a3a56u: goto P_0c0a3a56;
case 0x0c0a3a58u: goto P_0c0a3a58;
case 0x0c0a3a5au: goto P_0c0a3a5a;
case 0x0c0a3a5cu: goto P_0c0a3a5c;
case 0x0c0a3a5eu: goto P_0c0a3a5e;
case 0x0c0a3a60u: goto P_0c0a3a60;
case 0x0c0a3a62u: goto P_0c0a3a62;
case 0x0c0a3a64u: goto P_0c0a3a64;
case 0x0c0a3a66u: goto P_0c0a3a66;
case 0x0c0a3a68u: goto P_0c0a3a68;
case 0x0c0a3a6au: goto P_0c0a3a6a;
case 0x0c0a3a6cu: goto P_0c0a3a6c;
case 0x0c0a3a6eu: goto P_0c0a3a6e;
case 0x0c0a3a70u: goto P_0c0a3a70;
case 0x0c0a3a72u: goto P_0c0a3a72;
case 0x0c0a3a74u: goto P_0c0a3a74;
case 0x0c0a3a76u: goto P_0c0a3a76;
case 0x0c0a3a78u: goto P_0c0a3a78;
case 0x0c0a3a7au: goto P_0c0a3a7a;
case 0x0c0a3a7cu: goto P_0c0a3a7c;
case 0x0c0a3a7eu: goto P_0c0a3a7e;
case 0x0c0a3a80u: goto P_0c0a3a80;
case 0x0c0a3adeu: goto P_0c0a3ade;
case 0x0c0a3ae0u: goto P_0c0a3ae0;
case 0x0c0a3ae2u: goto P_0c0a3ae2;
case 0x0c0a3ae4u: goto P_0c0a3ae4;
case 0x0c0a3ae6u: goto P_0c0a3ae6;
case 0x0c0a3ae8u: goto P_0c0a3ae8;
case 0x0c0a3aeau: goto P_0c0a3aea;
case 0x0c0a3aecu: goto P_0c0a3aec;
case 0x0c0a3c98u: goto P_0c0a3c98;
case 0x0c0a3c9au: goto P_0c0a3c9a;
case 0x0c0a3c9cu: goto P_0c0a3c9c;
case 0x0c0a3c9eu: goto P_0c0a3c9e;
case 0x0c0a3ca0u: goto P_0c0a3ca0;
case 0x0c0a3ca2u: goto P_0c0a3ca2;
case 0x0c0a3ca4u: goto P_0c0a3ca4;
case 0x0c0a3ca6u: goto P_0c0a3ca6;
case 0x0c0a3ca8u: goto P_0c0a3ca8;
case 0x0c0a3caau: goto P_0c0a3caa;
case 0x0c0a3cacu: goto P_0c0a3cac;
case 0x0c0a3caeu: goto P_0c0a3cae;
case 0x0c0a3cb0u: goto P_0c0a3cb0;
case 0x0c0a3cb2u: goto P_0c0a3cb2;
case 0x0c0a3cb4u: goto P_0c0a3cb4;
case 0x0c0a3cb6u: goto P_0c0a3cb6;
case 0x0c0a3cb8u: goto P_0c0a3cb8;
case 0x0c0a3cbau: goto P_0c0a3cba;
case 0x0c0a3cbcu: goto P_0c0a3cbc;
case 0x0c0a3cbeu: goto P_0c0a3cbe;
case 0x0c0a3cc0u: goto P_0c0a3cc0;
case 0x0c0a3cc2u: goto P_0c0a3cc2;
case 0x0c0a3cc4u: goto P_0c0a3cc4;
case 0x0c0a3cc6u: goto P_0c0a3cc6;
case 0x0c0a3cc8u: goto P_0c0a3cc8;
case 0x0c0a3ccau: goto P_0c0a3cca;
case 0x0c0a3cccu: goto P_0c0a3ccc;
case 0x0c0a3cceu: goto P_0c0a3cce;
case 0x0c0a3cd0u: goto P_0c0a3cd0;
case 0x0c0a3cd2u: goto P_0c0a3cd2;
case 0x0c0a3cd4u: goto P_0c0a3cd4;
case 0x0c0a3cd6u: goto P_0c0a3cd6;
case 0x0c0a3cd8u: goto P_0c0a3cd8;
case 0x0c0a3cdau: goto P_0c0a3cda;
case 0x0c0a3cdcu: goto P_0c0a3cdc;
case 0x0c0a3cdeu: goto P_0c0a3cde;
case 0x0c0a3ce0u: goto P_0c0a3ce0;
case 0x0c0a3ce2u: goto P_0c0a3ce2;
case 0x0c0a3ce4u: goto P_0c0a3ce4;
case 0x0c0a3ce6u: goto P_0c0a3ce6;
case 0x0c0a3ce8u: goto P_0c0a3ce8;
case 0x0c0a3ceau: goto P_0c0a3cea;
case 0x0c0a3cecu: goto P_0c0a3cec;
case 0x0c0a3ceeu: goto P_0c0a3cee;
case 0x0c0a3cf0u: goto P_0c0a3cf0;
case 0x0c0a3cf2u: goto P_0c0a3cf2;
case 0x0c0a3cf4u: goto P_0c0a3cf4;
case 0x0c0a3cf6u: goto P_0c0a3cf6;
case 0x0c0a3cf8u: goto P_0c0a3cf8;
case 0x0c0a3cfau: goto P_0c0a3cfa;
case 0x0c0a3cfcu: goto P_0c0a3cfc;
case 0x0c0a3cfeu: goto P_0c0a3cfe;
case 0x0c0a3d00u: goto P_0c0a3d00;
case 0x0c0a3d02u: goto P_0c0a3d02;
case 0x0c0a3d04u: goto P_0c0a3d04;
case 0x0c0a3d06u: goto P_0c0a3d06;
case 0x0c0a3d08u: goto P_0c0a3d08;
case 0x0c0a3d0au: goto P_0c0a3d0a;
case 0x0c0a3d0cu: goto P_0c0a3d0c;
case 0x0c0a3d0eu: goto P_0c0a3d0e;
case 0x0c0a3d10u: goto P_0c0a3d10;
case 0x0c0a3d12u: goto P_0c0a3d12;
case 0x0c0a3d14u: goto P_0c0a3d14;
case 0x0c0a3d16u: goto P_0c0a3d16;
case 0x0c0a3d18u: goto P_0c0a3d18;
case 0x0c0a3d1au: goto P_0c0a3d1a;
case 0x0c0a3d1cu: goto P_0c0a3d1c;
case 0x0c0a3d1eu: goto P_0c0a3d1e;
case 0x0c0a3d20u: goto P_0c0a3d20;
case 0x0c0a3d22u: goto P_0c0a3d22;
case 0x0c0a3d24u: goto P_0c0a3d24;
case 0x0c0a3d26u: goto P_0c0a3d26;
case 0x0c0a3d28u: goto P_0c0a3d28;
case 0x0c0a3d2au: goto P_0c0a3d2a;
case 0x0c0a3d2cu: goto P_0c0a3d2c;
case 0x0c0a3d2eu: goto P_0c0a3d2e;
case 0x0c0a3d30u: goto P_0c0a3d30;
case 0x0c0a3d32u: goto P_0c0a3d32;
case 0x0c0a3d34u: goto P_0c0a3d34;
case 0x0c0a3d36u: goto P_0c0a3d36;
case 0x0c0a3d38u: goto P_0c0a3d38;
case 0x0c0a3d3au: goto P_0c0a3d3a;
case 0x0c0a3d3cu: goto P_0c0a3d3c;
case 0x0c0a3d3eu: goto P_0c0a3d3e;
case 0x0c0a3d40u: goto P_0c0a3d40;
case 0x0c0a3d42u: goto P_0c0a3d42;
case 0x0c0a3d44u: goto P_0c0a3d44;
case 0x0c0a3d46u: goto P_0c0a3d46;
case 0x0c0a3d48u: goto P_0c0a3d48;
case 0x0c0a3d4au: goto P_0c0a3d4a;
case 0x0c0a3d4cu: goto P_0c0a3d4c;
case 0x0c0a3d4eu: goto P_0c0a3d4e;
case 0x0c0a3d50u: goto P_0c0a3d50;
case 0x0c0a3d52u: goto P_0c0a3d52;
case 0x0c0a3d54u: goto P_0c0a3d54;
case 0x0c0a3d56u: goto P_0c0a3d56;
case 0x0c0a3d58u: goto P_0c0a3d58;
case 0x0c0a3d5au: goto P_0c0a3d5a;
case 0x0c0a3d5cu: goto P_0c0a3d5c;
case 0x0c0a3d5eu: goto P_0c0a3d5e;
case 0x0c0a3d60u: goto P_0c0a3d60;
case 0x0c0a3d62u: goto P_0c0a3d62;
case 0x0c0a3d64u: goto P_0c0a3d64;
case 0x0c0a3d66u: goto P_0c0a3d66;
case 0x0c0a3d68u: goto P_0c0a3d68;
case 0x0c0a3d6au: goto P_0c0a3d6a;
case 0x0c0a3d6cu: goto P_0c0a3d6c;
case 0x0c0a3d6eu: goto P_0c0a3d6e;
case 0x0c0a3d70u: goto P_0c0a3d70;
case 0x0c0a3d72u: goto P_0c0a3d72;
case 0x0c0a3d74u: goto P_0c0a3d74;
case 0x0c0a3d76u: goto P_0c0a3d76;
case 0x0c0a3d78u: goto P_0c0a3d78;
case 0x0c0a3d7au: goto P_0c0a3d7a;
case 0x0c0a3d7cu: goto P_0c0a3d7c;
case 0x0c0a3d7eu: goto P_0c0a3d7e;
case 0x0c0a3d80u: goto P_0c0a3d80;
case 0x0c0a3d82u: goto P_0c0a3d82;
case 0x0c0a3d84u: goto P_0c0a3d84;
case 0x0c0a3d86u: goto P_0c0a3d86;
case 0x0c0a3d88u: goto P_0c0a3d88;
case 0x0c0a3d8au: goto P_0c0a3d8a;
case 0x0c0a3d8cu: goto P_0c0a3d8c;
case 0x0c0a3d8eu: goto P_0c0a3d8e;
case 0x0c0a3d90u: goto P_0c0a3d90;
case 0x0c0a3d92u: goto P_0c0a3d92;
case 0x0c0a3d94u: goto P_0c0a3d94;
case 0x0c0a3d96u: goto P_0c0a3d96;
case 0x0c0a3d98u: goto P_0c0a3d98;
case 0x0c0a3d9au: goto P_0c0a3d9a;
case 0x0c0a3d9cu: goto P_0c0a3d9c;
case 0x0c0a3d9eu: goto P_0c0a3d9e;
case 0x0c0a3da0u: goto P_0c0a3da0;
case 0x0c0a3da2u: goto P_0c0a3da2;
case 0x0c0a3da4u: goto P_0c0a3da4;
case 0x0c0a3da6u: goto P_0c0a3da6;
case 0x0c0a3da8u: goto P_0c0a3da8;
case 0x0c0a3daau: goto P_0c0a3daa;
case 0x0c0a3dacu: goto P_0c0a3dac;
case 0x0c0a3e0au: goto P_0c0a3e0a;
case 0x0c0a3e0cu: goto P_0c0a3e0c;
case 0x0c0a3e0eu: goto P_0c0a3e0e;
case 0x0c0a3e10u: goto P_0c0a3e10;
case 0x0c0a3e12u: goto P_0c0a3e12;
case 0x0c0a3e14u: goto P_0c0a3e14;
case 0x0c0a3e16u: goto P_0c0a3e16;
case 0x0c0a3e18u: goto P_0c0a3e18;
case 0x0c0a4012u: goto P_0c0a4012;
case 0x0c0a4014u: goto P_0c0a4014;
case 0x0c0a4016u: goto P_0c0a4016;
case 0x0c0a4018u: goto P_0c0a4018;
case 0x0c0a401au: goto P_0c0a401a;
case 0x0c0a401cu: goto P_0c0a401c;
case 0x0c0a401eu: goto P_0c0a401e;
case 0x0c0a4020u: goto P_0c0a4020;
case 0x0c0a4022u: goto P_0c0a4022;
case 0x0c0a4024u: goto P_0c0a4024;
case 0x0c0a4026u: goto P_0c0a4026;
case 0x0c0a4028u: goto P_0c0a4028;
case 0x0c0a402au: goto P_0c0a402a;
case 0x0c0a402cu: goto P_0c0a402c;
case 0x0c0a402eu: goto P_0c0a402e;
case 0x0c0a4030u: goto P_0c0a4030;
case 0x0c0a4032u: goto P_0c0a4032;
case 0x0c0a4034u: goto P_0c0a4034;
case 0x0c0a4036u: goto P_0c0a4036;
case 0x0c0a4038u: goto P_0c0a4038;
case 0x0c0a403au: goto P_0c0a403a;
case 0x0c0a403cu: goto P_0c0a403c;
case 0x0c0a403eu: goto P_0c0a403e;
case 0x0c0a4040u: goto P_0c0a4040;
case 0x0c0a4042u: goto P_0c0a4042;
case 0x0c0a4044u: goto P_0c0a4044;
case 0x0c0a4046u: goto P_0c0a4046;
case 0x0c0a4048u: goto P_0c0a4048;
case 0x0c0a404au: goto P_0c0a404a;
case 0x0c0a404cu: goto P_0c0a404c;
case 0x0c0a404eu: goto P_0c0a404e;
case 0x0c0a4050u: goto P_0c0a4050;
case 0x0c0a4052u: goto P_0c0a4052;
case 0x0c0a4054u: goto P_0c0a4054;
case 0x0c0a4056u: goto P_0c0a4056;
case 0x0c0a4058u: goto P_0c0a4058;
case 0x0c0a405au: goto P_0c0a405a;
case 0x0c0a405cu: goto P_0c0a405c;
case 0x0c0a405eu: goto P_0c0a405e;
case 0x0c0a4060u: goto P_0c0a4060;
case 0x0c0a4062u: goto P_0c0a4062;
case 0x0c0a4064u: goto P_0c0a4064;
case 0x0c0a4066u: goto P_0c0a4066;
case 0x0c0a4068u: goto P_0c0a4068;
case 0x0c0a406au: goto P_0c0a406a;
case 0x0c0a406cu: goto P_0c0a406c;
case 0x0c0a406eu: goto P_0c0a406e;
case 0x0c0a4070u: goto P_0c0a4070;
case 0x0c0a4072u: goto P_0c0a4072;
case 0x0c0a4074u: goto P_0c0a4074;
case 0x0c0a4076u: goto P_0c0a4076;
case 0x0c0a4078u: goto P_0c0a4078;
case 0x0c0a407au: goto P_0c0a407a;
case 0x0c0a407cu: goto P_0c0a407c;
case 0x0c0a407eu: goto P_0c0a407e;
case 0x0c0a4080u: goto P_0c0a4080;
case 0x0c0a4082u: goto P_0c0a4082;
case 0x0c0a4084u: goto P_0c0a4084;
case 0x0c0a4086u: goto P_0c0a4086;
case 0x0c0a4088u: goto P_0c0a4088;
case 0x0c0a408au: goto P_0c0a408a;
case 0x0c0a408cu: goto P_0c0a408c;
case 0x0c0a408eu: goto P_0c0a408e;
case 0x0c0a4090u: goto P_0c0a4090;
case 0x0c0a4092u: goto P_0c0a4092;
case 0x0c0a4094u: goto P_0c0a4094;
case 0x0c0a4096u: goto P_0c0a4096;
case 0x0c0a4098u: goto P_0c0a4098;
case 0x0c0a409au: goto P_0c0a409a;
case 0x0c0a409cu: goto P_0c0a409c;
case 0x0c0a409eu: goto P_0c0a409e;
case 0x0c0a40a0u: goto P_0c0a40a0;
case 0x0c0a40a2u: goto P_0c0a40a2;
case 0x0c0a40a4u: goto P_0c0a40a4;
case 0x0c0a40a6u: goto P_0c0a40a6;
case 0x0c0a40a8u: goto P_0c0a40a8;
case 0x0c0a40aau: goto P_0c0a40aa;
case 0x0c0a4190u: goto P_0c0a4190;
case 0x0c0a4192u: goto P_0c0a4192;
case 0x0c0a4194u: goto P_0c0a4194;
case 0x0c0a4196u: goto P_0c0a4196;
case 0x0c0a4198u: goto P_0c0a4198;
case 0x0c0a419au: goto P_0c0a419a;
case 0x0c0a419cu: goto P_0c0a419c;
case 0x0c0a419eu: goto P_0c0a419e;
case 0x0c0a41a0u: goto P_0c0a41a0;
case 0x0c0a41a2u: goto P_0c0a41a2;
case 0x0c0a41a4u: goto P_0c0a41a4;
case 0x0c0a41a6u: goto P_0c0a41a6;
case 0x0c0a41a8u: goto P_0c0a41a8;
case 0x0c0a41aau: goto P_0c0a41aa;
case 0x0c0a41acu: goto P_0c0a41ac;
case 0x0c0a41aeu: goto P_0c0a41ae;
case 0x0c0a41b0u: goto P_0c0a41b0;
case 0x0c0a41b2u: goto P_0c0a41b2;
case 0x0c0a41b4u: goto P_0c0a41b4;
case 0x0c0a41b6u: goto P_0c0a41b6;
case 0x0c0a41b8u: goto P_0c0a41b8;
case 0x0c0a41bau: goto P_0c0a41ba;
case 0x0c0a41bcu: goto P_0c0a41bc;
case 0x0c0a41beu: goto P_0c0a41be;
case 0x0c0a41c0u: goto P_0c0a41c0;
case 0x0c0a41c2u: goto P_0c0a41c2;
case 0x0c0a41c4u: goto P_0c0a41c4;
case 0x0c0a41c6u: goto P_0c0a41c6;
case 0x0c0a41c8u: goto P_0c0a41c8;
case 0x0c0a41cau: goto P_0c0a41ca;
case 0x0c0a41ccu: goto P_0c0a41cc;
case 0x0c0a41ceu: goto P_0c0a41ce;
case 0x0c0a41d0u: goto P_0c0a41d0;
case 0x0c0a41d2u: goto P_0c0a41d2;
case 0x0c0a41d4u: goto P_0c0a41d4;
case 0x0c0a41d6u: goto P_0c0a41d6;
case 0x0c0a41d8u: goto P_0c0a41d8;
case 0x0c0a41dau: goto P_0c0a41da;
case 0x0c0a41dcu: goto P_0c0a41dc;
case 0x0c0a41deu: goto P_0c0a41de;
case 0x0c0a41e0u: goto P_0c0a41e0;
case 0x0c0a41e2u: goto P_0c0a41e2;
case 0x0c0a41e4u: goto P_0c0a41e4;
case 0x0c0a41e6u: goto P_0c0a41e6;
case 0x0c0a41e8u: goto P_0c0a41e8;
case 0x0c0a41eau: goto P_0c0a41ea;
case 0x0c0a41ecu: goto P_0c0a41ec;
case 0x0c0a41eeu: goto P_0c0a41ee;
case 0x0c0a41f0u: goto P_0c0a41f0;
case 0x0c0a41f2u: goto P_0c0a41f2;
case 0x0c0a41f4u: goto P_0c0a41f4;
case 0x0c0a41f6u: goto P_0c0a41f6;
case 0x0c0a41f8u: goto P_0c0a41f8;
case 0x0c0a41fau: goto P_0c0a41fa;
case 0x0c0a41fcu: goto P_0c0a41fc;
case 0x0c0a41feu: goto P_0c0a41fe;
case 0x0c0a4200u: goto P_0c0a4200;
case 0x0c0a4202u: goto P_0c0a4202;
case 0x0c0a4204u: goto P_0c0a4204;
case 0x0c0a4206u: goto P_0c0a4206;
case 0x0c0a4208u: goto P_0c0a4208;
case 0x0c0a420au: goto P_0c0a420a;
case 0x0c0a420cu: goto P_0c0a420c;
case 0x0c0a420eu: goto P_0c0a420e;
case 0x0c0a4210u: goto P_0c0a4210;
case 0x0c0a4212u: goto P_0c0a4212;
case 0x0c0a4214u: goto P_0c0a4214;
case 0x0c0a4216u: goto P_0c0a4216;
case 0x0c0a4218u: goto P_0c0a4218;
case 0x0c0a421au: goto P_0c0a421a;
case 0x0c0a421cu: goto P_0c0a421c;
case 0x0c0a421eu: goto P_0c0a421e;
case 0x0c0a4220u: goto P_0c0a4220;
case 0x0c0a4222u: goto P_0c0a4222;
case 0x0c0a4224u: goto P_0c0a4224;
case 0x0c0a4226u: goto P_0c0a4226;
case 0x0c0a4228u: goto P_0c0a4228;
case 0x0c0a422au: goto P_0c0a422a;
case 0x0c0a422cu: goto P_0c0a422c;
case 0x0c0a422eu: goto P_0c0a422e;
case 0x0c0a4230u: goto P_0c0a4230;
case 0x0c0a4232u: goto P_0c0a4232;
case 0x0c0a4234u: goto P_0c0a4234;
case 0x0c0a4236u: goto P_0c0a4236;
case 0x0c0a4238u: goto P_0c0a4238;
case 0x0c0a432cu: goto P_0c0a432c;
case 0x0c0a432eu: goto P_0c0a432e;
case 0x0c0a4330u: goto P_0c0a4330;
case 0x0c0a4332u: goto P_0c0a4332;
case 0x0c0a4334u: goto P_0c0a4334;
case 0x0c0a4336u: goto P_0c0a4336;
case 0x0c0a4338u: goto P_0c0a4338;
case 0x0c0a433au: goto P_0c0a433a;
case 0x0c0a433cu: goto P_0c0a433c;
case 0x0c0a433eu: goto P_0c0a433e;
case 0x0c0a4340u: goto P_0c0a4340;
case 0x0c0a4342u: goto P_0c0a4342;
case 0x0c0a4344u: goto P_0c0a4344;
case 0x0c0a4346u: goto P_0c0a4346;
case 0x0c0a4348u: goto P_0c0a4348;
case 0x0c0a434au: goto P_0c0a434a;
case 0x0c0a434cu: goto P_0c0a434c;
case 0x0c0a434eu: goto P_0c0a434e;
case 0x0c0a4350u: goto P_0c0a4350;
case 0x0c0a4352u: goto P_0c0a4352;
case 0x0c0a4354u: goto P_0c0a4354;
case 0x0c0a4356u: goto P_0c0a4356;
case 0x0c0a4358u: goto P_0c0a4358;
case 0x0c0a435au: goto P_0c0a435a;
case 0x0c0a435cu: goto P_0c0a435c;
case 0x0c0a435eu: goto P_0c0a435e;
case 0x0c0a4360u: goto P_0c0a4360;
case 0x0c0a4362u: goto P_0c0a4362;
case 0x0c0a4364u: goto P_0c0a4364;
case 0x0c0a4366u: goto P_0c0a4366;
case 0x0c0a4368u: goto P_0c0a4368;
case 0x0c0a436au: goto P_0c0a436a;
case 0x0c0a436cu: goto P_0c0a436c;
case 0x0c0a436eu: goto P_0c0a436e;
case 0x0c0a4370u: goto P_0c0a4370;
case 0x0c0a4372u: goto P_0c0a4372;
case 0x0c0a4374u: goto P_0c0a4374;
case 0x0c0a4376u: goto P_0c0a4376;
case 0x0c0a4378u: goto P_0c0a4378;
case 0x0c0a437au: goto P_0c0a437a;
case 0x0c0a437cu: goto P_0c0a437c;
case 0x0c0a437eu: goto P_0c0a437e;
case 0x0c0a4380u: goto P_0c0a4380;
case 0x0c0a4382u: goto P_0c0a4382;
case 0x0c0a4384u: goto P_0c0a4384;
case 0x0c0a4386u: goto P_0c0a4386;
case 0x0c0a4388u: goto P_0c0a4388;
case 0x0c0a438au: goto P_0c0a438a;
case 0x0c0a438cu: goto P_0c0a438c;
case 0x0c0a438eu: goto P_0c0a438e;
case 0x0c0a4390u: goto P_0c0a4390;
case 0x0c0a4392u: goto P_0c0a4392;
case 0x0c0a4394u: goto P_0c0a4394;
case 0x0c0a4396u: goto P_0c0a4396;
case 0x0c0a4398u: goto P_0c0a4398;
case 0x0c0a439au: goto P_0c0a439a;
case 0x0c0a439cu: goto P_0c0a439c;
case 0x0c0a439eu: goto P_0c0a439e;
case 0x0c0a43a0u: goto P_0c0a43a0;
case 0x0c0a43a2u: goto P_0c0a43a2;
case 0x0c0a43a4u: goto P_0c0a43a4;
case 0x0c0a43a6u: goto P_0c0a43a6;
case 0x0c0a43a8u: goto P_0c0a43a8;
case 0x0c0a43aau: goto P_0c0a43aa;
case 0x0c0a43acu: goto P_0c0a43ac;
case 0x0c0a43aeu: goto P_0c0a43ae;
case 0x0c0a43b0u: goto P_0c0a43b0;
case 0x0c0a43b2u: goto P_0c0a43b2;
case 0x0c0a43b4u: goto P_0c0a43b4;
case 0x0c0a43b6u: goto P_0c0a43b6;
case 0x0c0a43b8u: goto P_0c0a43b8;
case 0x0c0a43bau: goto P_0c0a43ba;
case 0x0c0a43bcu: goto P_0c0a43bc;
case 0x0c0a43beu: goto P_0c0a43be;
case 0x0c0a43c0u: goto P_0c0a43c0;
case 0x0c0a43c2u: goto P_0c0a43c2;
case 0x0c0a43c4u: goto P_0c0a43c4;
case 0x0c0a43c6u: goto P_0c0a43c6;
case 0x0c0a43c8u: goto P_0c0a43c8;
case 0x0c0a43cau: goto P_0c0a43ca;
case 0x0c0a43ccu: goto P_0c0a43cc;
case 0x0c0a43ceu: goto P_0c0a43ce;
case 0x0c0a43d0u: goto P_0c0a43d0;
case 0x0c0a43d2u: goto P_0c0a43d2;
case 0x0c0a43d4u: goto P_0c0a43d4;
case 0x0c0a43d6u: goto P_0c0a43d6;
case 0x0c0a43d8u: goto P_0c0a43d8;
case 0x0c0a43dau: goto P_0c0a43da;
case 0x0c0a43dcu: goto P_0c0a43dc;
case 0x0c0a4508u: goto P_0c0a4508;
case 0x0c0a450au: goto P_0c0a450a;
case 0x0c0a450cu: goto P_0c0a450c;
case 0x0c0a450eu: goto P_0c0a450e;
case 0x0c0a4510u: goto P_0c0a4510;
case 0x0c0a4512u: goto P_0c0a4512;
case 0x0c0a4514u: goto P_0c0a4514;
case 0x0c0a4516u: goto P_0c0a4516;
case 0x0c0a4518u: goto P_0c0a4518;
case 0x0c0a451au: goto P_0c0a451a;
case 0x0c0a451cu: goto P_0c0a451c;
case 0x0c0a451eu: goto P_0c0a451e;
case 0x0c0a4520u: goto P_0c0a4520;
case 0x0c0a4522u: goto P_0c0a4522;
case 0x0c0a4524u: goto P_0c0a4524;
case 0x0c0a4526u: goto P_0c0a4526;
case 0x0c0a4528u: goto P_0c0a4528;
case 0x0c0a452au: goto P_0c0a452a;
case 0x0c0a452cu: goto P_0c0a452c;
case 0x0c0a452eu: goto P_0c0a452e;
case 0x0c0a4530u: goto P_0c0a4530;
case 0x0c0a4532u: goto P_0c0a4532;
case 0x0c0a4534u: goto P_0c0a4534;
case 0x0c0a4536u: goto P_0c0a4536;
case 0x0c0a4538u: goto P_0c0a4538;
case 0x0c0a453au: goto P_0c0a453a;
case 0x0c0a453cu: goto P_0c0a453c;
case 0x0c0a453eu: goto P_0c0a453e;
case 0x0c0a4540u: goto P_0c0a4540;
case 0x0c0a4542u: goto P_0c0a4542;
case 0x0c0a4544u: goto P_0c0a4544;
case 0x0c0a4546u: goto P_0c0a4546;
case 0x0c0a4548u: goto P_0c0a4548;
case 0x0c0a454au: goto P_0c0a454a;
case 0x0c0a454cu: goto P_0c0a454c;
case 0x0c0a454eu: goto P_0c0a454e;
case 0x0c0a4550u: goto P_0c0a4550;
case 0x0c0a4552u: goto P_0c0a4552;
case 0x0c0a4554u: goto P_0c0a4554;
case 0x0c0a4556u: goto P_0c0a4556;
case 0x0c0a4558u: goto P_0c0a4558;
case 0x0c0a455au: goto P_0c0a455a;
case 0x0c0a455cu: goto P_0c0a455c;
case 0x0c0a455eu: goto P_0c0a455e;
case 0x0c0a4560u: goto P_0c0a4560;
case 0x0c0a4562u: goto P_0c0a4562;
case 0x0c0a4564u: goto P_0c0a4564;
case 0x0c0a4566u: goto P_0c0a4566;
case 0x0c0a4568u: goto P_0c0a4568;
case 0x0c0a456au: goto P_0c0a456a;
case 0x0c0a456cu: goto P_0c0a456c;
case 0x0c0a456eu: goto P_0c0a456e;
case 0x0c0a4570u: goto P_0c0a4570;
case 0x0c0a4572u: goto P_0c0a4572;
case 0x0c0a4574u: goto P_0c0a4574;
case 0x0c0a4576u: goto P_0c0a4576;
case 0x0c0a4578u: goto P_0c0a4578;
case 0x0c0a457au: goto P_0c0a457a;
case 0x0c0a457cu: goto P_0c0a457c;
case 0x0c0a457eu: goto P_0c0a457e;
case 0x0c0a4580u: goto P_0c0a4580;
case 0x0c0a4582u: goto P_0c0a4582;
case 0x0c0a4584u: goto P_0c0a4584;
case 0x0c0a4586u: goto P_0c0a4586;
case 0x0c0a4588u: goto P_0c0a4588;
case 0x0c0a458au: goto P_0c0a458a;
case 0x0c0a458cu: goto P_0c0a458c;
case 0x0c0a458eu: goto P_0c0a458e;
case 0x0c0a4590u: goto P_0c0a4590;
case 0x0c0a4592u: goto P_0c0a4592;
case 0x0c0a4594u: goto P_0c0a4594;
case 0x0c0a4596u: goto P_0c0a4596;
case 0x0c0a4598u: goto P_0c0a4598;
case 0x0c0a459au: goto P_0c0a459a;
case 0x0c0a459cu: goto P_0c0a459c;
case 0x0c0a459eu: goto P_0c0a459e;
case 0x0c0a45a0u: goto P_0c0a45a0;
case 0x0c0a45a2u: goto P_0c0a45a2;
case 0x0c0a45a4u: goto P_0c0a45a4;
case 0x0c0a45a6u: goto P_0c0a45a6;
case 0x0c0a45a8u: goto P_0c0a45a8;
case 0x0c0a45aau: goto P_0c0a45aa;
case 0x0c0a45acu: goto P_0c0a45ac;
case 0x0c0a45aeu: goto P_0c0a45ae;
case 0x0c0a45b0u: goto P_0c0a45b0;
case 0x0c0a45b2u: goto P_0c0a45b2;
case 0x0c0a45b4u: goto P_0c0a45b4;
case 0x0c0a45b6u: goto P_0c0a45b6;
case 0x0c0a45b8u: goto P_0c0a45b8;
case 0x0c0a45bau: goto P_0c0a45ba;
case 0x0c0a45bcu: goto P_0c0a45bc;
case 0x0c0a45beu: goto P_0c0a45be;
case 0x0c0a45c0u: goto P_0c0a45c0;
case 0x0c0a45c2u: goto P_0c0a45c2;
case 0x0c0a45c4u: goto P_0c0a45c4;
case 0x0c0a45c6u: goto P_0c0a45c6;
case 0x0c0a45c8u: goto P_0c0a45c8;
case 0x0c0a45cau: goto P_0c0a45ca;
case 0x0c0a45ccu: goto P_0c0a45cc;
case 0x0c0a45ceu: goto P_0c0a45ce;
case 0x0c0a45d0u: goto P_0c0a45d0;
case 0x0c0a45d2u: goto P_0c0a45d2;
case 0x0c0a45d4u: goto P_0c0a45d4;
case 0x0c0a45d6u: goto P_0c0a45d6;
case 0x0c0a45d8u: goto P_0c0a45d8;
case 0x0c0a45dau: goto P_0c0a45da;
case 0x0c0a45dcu: goto P_0c0a45dc;
case 0x0c0a45deu: goto P_0c0a45de;
case 0x0c0a45e0u: goto P_0c0a45e0;
case 0x0c0a45e2u: goto P_0c0a45e2;
case 0x0c0a45e4u: goto P_0c0a45e4;
case 0x0c0a45e6u: goto P_0c0a45e6;
case 0x0c0a45e8u: goto P_0c0a45e8;
case 0x0c0a45eau: goto P_0c0a45ea;
case 0x0c0a45ecu: goto P_0c0a45ec;
case 0x0c0a45eeu: goto P_0c0a45ee;
case 0x0c0a45f0u: goto P_0c0a45f0;
case 0x0c0a45f2u: goto P_0c0a45f2;
case 0x0c0a45f4u: goto P_0c0a45f4;
case 0x0c0a45f6u: goto P_0c0a45f6;
case 0x0c0a45f8u: goto P_0c0a45f8;
case 0x0c0a45fau: goto P_0c0a45fa;
case 0x0c0a45fcu: goto P_0c0a45fc;
case 0x0c0a45feu: goto P_0c0a45fe;
case 0x0c0a4600u: goto P_0c0a4600;
case 0x0c0a4602u: goto P_0c0a4602;
case 0x0c0a4604u: goto P_0c0a4604;
case 0x0c0a4606u: goto P_0c0a4606;
case 0x0c0a4608u: goto P_0c0a4608;
case 0x0c0a460au: goto P_0c0a460a;
case 0x0c0a460cu: goto P_0c0a460c;
case 0x0c0a460eu: goto P_0c0a460e;
case 0x0c0a4610u: goto P_0c0a4610;
case 0x0c0a4612u: goto P_0c0a4612;
case 0x0c0a4614u: goto P_0c0a4614;
case 0x0c0a4616u: goto P_0c0a4616;
case 0x0c0a4618u: goto P_0c0a4618;
case 0x0c0a47d4u: goto P_0c0a47d4;
case 0x0c0a47d6u: goto P_0c0a47d6;
case 0x0c0a47d8u: goto P_0c0a47d8;
case 0x0c0a47dau: goto P_0c0a47da;
case 0x0c0a47dcu: goto P_0c0a47dc;
case 0x0c0a47deu: goto P_0c0a47de;
case 0x0c0a47e0u: goto P_0c0a47e0;
case 0x0c0a47e2u: goto P_0c0a47e2;
case 0x0c0a47e4u: goto P_0c0a47e4;
case 0x0c0a47e6u: goto P_0c0a47e6;
case 0x0c0a47e8u: goto P_0c0a47e8;
case 0x0c0a47eau: goto P_0c0a47ea;
case 0x0c0a47ecu: goto P_0c0a47ec;
case 0x0c0a47eeu: goto P_0c0a47ee;
case 0x0c0a47f0u: goto P_0c0a47f0;
case 0x0c0a47f2u: goto P_0c0a47f2;
case 0x0c0a47f4u: goto P_0c0a47f4;
case 0x0c0a47f6u: goto P_0c0a47f6;
case 0x0c0a47f8u: goto P_0c0a47f8;
case 0x0c0a47fau: goto P_0c0a47fa;
case 0x0c0a47fcu: goto P_0c0a47fc;
case 0x0c0a47feu: goto P_0c0a47fe;
case 0x0c0a4800u: goto P_0c0a4800;
case 0x0c0a4802u: goto P_0c0a4802;
case 0x0c0a4804u: goto P_0c0a4804;
case 0x0c0a4806u: goto P_0c0a4806;
case 0x0c0a4808u: goto P_0c0a4808;
case 0x0c0a480au: goto P_0c0a480a;
case 0x0c0a480cu: goto P_0c0a480c;
case 0x0c0a480eu: goto P_0c0a480e;
case 0x0c0a4810u: goto P_0c0a4810;
case 0x0c0a4812u: goto P_0c0a4812;
case 0x0c0a4814u: goto P_0c0a4814;
case 0x0c0a4816u: goto P_0c0a4816;
case 0x0c0a4818u: goto P_0c0a4818;
case 0x0c0a481au: goto P_0c0a481a;
case 0x0c0a481cu: goto P_0c0a481c;
case 0x0c0a481eu: goto P_0c0a481e;
case 0x0c0a4820u: goto P_0c0a4820;
case 0x0c0a4822u: goto P_0c0a4822;
case 0x0c0a4824u: goto P_0c0a4824;
case 0x0c0a4826u: goto P_0c0a4826;
case 0x0c0a4828u: goto P_0c0a4828;
case 0x0c0a482au: goto P_0c0a482a;
case 0x0c0a482cu: goto P_0c0a482c;
case 0x0c0a482eu: goto P_0c0a482e;
case 0x0c0a4830u: goto P_0c0a4830;
case 0x0c0a4832u: goto P_0c0a4832;
case 0x0c0a4834u: goto P_0c0a4834;
case 0x0c0a4836u: goto P_0c0a4836;
case 0x0c0a4838u: goto P_0c0a4838;
case 0x0c0a483au: goto P_0c0a483a;
case 0x0c0a483cu: goto P_0c0a483c;
case 0x0c0a483eu: goto P_0c0a483e;
case 0x0c0a4840u: goto P_0c0a4840;
case 0x0c0a4842u: goto P_0c0a4842;
case 0x0c0a4844u: goto P_0c0a4844;
case 0x0c0a4846u: goto P_0c0a4846;
case 0x0c0a4848u: goto P_0c0a4848;
case 0x0c0a484au: goto P_0c0a484a;
case 0x0c0a484cu: goto P_0c0a484c;
case 0x0c0a484eu: goto P_0c0a484e;
case 0x0c0a4850u: goto P_0c0a4850;
case 0x0c0a4852u: goto P_0c0a4852;
case 0x0c0a4854u: goto P_0c0a4854;
case 0x0c0a4856u: goto P_0c0a4856;
case 0x0c0a4858u: goto P_0c0a4858;
case 0x0c0a485au: goto P_0c0a485a;
case 0x0c0a485cu: goto P_0c0a485c;
case 0x0c0a485eu: goto P_0c0a485e;
case 0x0c0a4860u: goto P_0c0a4860;
case 0x0c0a4862u: goto P_0c0a4862;
case 0x0c0a4864u: goto P_0c0a4864;
case 0x0c0a4866u: goto P_0c0a4866;
case 0x0c0a4868u: goto P_0c0a4868;
case 0x0c0a486au: goto P_0c0a486a;
case 0x0c0a486cu: goto P_0c0a486c;
case 0x0c0a4948u: goto P_0c0a4948;
case 0x0c0a494au: goto P_0c0a494a;
case 0x0c0a494cu: goto P_0c0a494c;
case 0x0c0a494eu: goto P_0c0a494e;
case 0x0c0a4950u: goto P_0c0a4950;
case 0x0c0a4952u: goto P_0c0a4952;
case 0x0c0a4954u: goto P_0c0a4954;
case 0x0c0a4956u: goto P_0c0a4956;
case 0x0c0a4958u: goto P_0c0a4958;
case 0x0c0a495au: goto P_0c0a495a;
case 0x0c0a495cu: goto P_0c0a495c;
case 0x0c0a495eu: goto P_0c0a495e;
case 0x0c0a4960u: goto P_0c0a4960;
case 0x0c0a4962u: goto P_0c0a4962;
case 0x0c0a4964u: goto P_0c0a4964;
case 0x0c0a4966u: goto P_0c0a4966;
case 0x0c0a4968u: goto P_0c0a4968;
case 0x0c0a496au: goto P_0c0a496a;
case 0x0c0a496cu: goto P_0c0a496c;
case 0x0c0a496eu: goto P_0c0a496e;
case 0x0c0a4970u: goto P_0c0a4970;
case 0x0c0a4972u: goto P_0c0a4972;
case 0x0c0a4974u: goto P_0c0a4974;
case 0x0c0a4976u: goto P_0c0a4976;
case 0x0c0a4978u: goto P_0c0a4978;
case 0x0c0a497au: goto P_0c0a497a;
case 0x0c0a497cu: goto P_0c0a497c;
case 0x0c0a497eu: goto P_0c0a497e;
case 0x0c0a4980u: goto P_0c0a4980;
case 0x0c0a4982u: goto P_0c0a4982;
case 0x0c0a4984u: goto P_0c0a4984;
case 0x0c0a4986u: goto P_0c0a4986;
case 0x0c0a4988u: goto P_0c0a4988;
case 0x0c0a498au: goto P_0c0a498a;
case 0x0c0a498cu: goto P_0c0a498c;
case 0x0c0a498eu: goto P_0c0a498e;
case 0x0c0a4990u: goto P_0c0a4990;
case 0x0c0a4992u: goto P_0c0a4992;
case 0x0c0a4994u: goto P_0c0a4994;
case 0x0c0a4996u: goto P_0c0a4996;
case 0x0c0a4998u: goto P_0c0a4998;
case 0x0c0a499au: goto P_0c0a499a;
case 0x0c0a499cu: goto P_0c0a499c;
case 0x0c0a499eu: goto P_0c0a499e;
case 0x0c0a49a0u: goto P_0c0a49a0;
case 0x0c0a49a2u: goto P_0c0a49a2;
case 0x0c0a49a4u: goto P_0c0a49a4;
case 0x0c0a49a6u: goto P_0c0a49a6;
case 0x0c0a49a8u: goto P_0c0a49a8;
case 0x0c0a49aau: goto P_0c0a49aa;
case 0x0c0a49acu: goto P_0c0a49ac;
case 0x0c0a49aeu: goto P_0c0a49ae;
case 0x0c0a49b0u: goto P_0c0a49b0;
case 0x0c0a49b2u: goto P_0c0a49b2;
case 0x0c0a49b4u: goto P_0c0a49b4;
case 0x0c0a49b6u: goto P_0c0a49b6;
case 0x0c0a49b8u: goto P_0c0a49b8;
case 0x0c0a49bau: goto P_0c0a49ba;
case 0x0c0a49bcu: goto P_0c0a49bc;
case 0x0c0a49beu: goto P_0c0a49be;
case 0x0c0a49c0u: goto P_0c0a49c0;
case 0x0c0a49c2u: goto P_0c0a49c2;
case 0x0c0a49c4u: goto P_0c0a49c4;
case 0x0c0a49c6u: goto P_0c0a49c6;
case 0x0c0a49c8u: goto P_0c0a49c8;
case 0x0c0a49cau: goto P_0c0a49ca;
case 0x0c0a49ccu: goto P_0c0a49cc;
case 0x0c0a49ceu: goto P_0c0a49ce;
case 0x0c0a49d0u: goto P_0c0a49d0;
case 0x0c0a49d2u: goto P_0c0a49d2;
case 0x0c0a49d4u: goto P_0c0a49d4;
case 0x0c0a49d6u: goto P_0c0a49d6;
case 0x0c0a49d8u: goto P_0c0a49d8;
case 0x0c0a49dau: goto P_0c0a49da;
case 0x0c0a49dcu: goto P_0c0a49dc;
case 0x0c0a49deu: goto P_0c0a49de;
case 0x0c0a49e0u: goto P_0c0a49e0;
case 0x0c0a4abcu: goto P_0c0a4abc;
case 0x0c0a4abeu: goto P_0c0a4abe;
case 0x0c0a4ac0u: goto P_0c0a4ac0;
case 0x0c0a4ac2u: goto P_0c0a4ac2;
case 0x0c0a4ac4u: goto P_0c0a4ac4;
case 0x0c0a4ac6u: goto P_0c0a4ac6;
case 0x0c0a4ac8u: goto P_0c0a4ac8;
case 0x0c0a4acau: goto P_0c0a4aca;
case 0x0c0a4accu: goto P_0c0a4acc;
case 0x0c0a4aceu: goto P_0c0a4ace;
case 0x0c0a4ad0u: goto P_0c0a4ad0;
case 0x0c0a4ad2u: goto P_0c0a4ad2;
case 0x0c0a4ad4u: goto P_0c0a4ad4;
case 0x0c0a4ad6u: goto P_0c0a4ad6;
case 0x0c0a4ad8u: goto P_0c0a4ad8;
case 0x0c0a4adau: goto P_0c0a4ada;
case 0x0c0a4adcu: goto P_0c0a4adc;
case 0x0c0a4adeu: goto P_0c0a4ade;
case 0x0c0a4ae0u: goto P_0c0a4ae0;
case 0x0c0a4ae2u: goto P_0c0a4ae2;
case 0x0c0a4ae4u: goto P_0c0a4ae4;
case 0x0c0a4ae6u: goto P_0c0a4ae6;
case 0x0c0a4ae8u: goto P_0c0a4ae8;
case 0x0c0a4aeau: goto P_0c0a4aea;
case 0x0c0a4aecu: goto P_0c0a4aec;
case 0x0c0a4aeeu: goto P_0c0a4aee;
case 0x0c0a4af0u: goto P_0c0a4af0;
case 0x0c0a4af2u: goto P_0c0a4af2;
case 0x0c0a4af4u: goto P_0c0a4af4;
case 0x0c0a4af6u: goto P_0c0a4af6;
case 0x0c0a4af8u: goto P_0c0a4af8;
case 0x0c0a4afau: goto P_0c0a4afa;
case 0x0c0a4afcu: goto P_0c0a4afc;
case 0x0c0a4afeu: goto P_0c0a4afe;
case 0x0c0a4b00u: goto P_0c0a4b00;
case 0x0c0a4b02u: goto P_0c0a4b02;
case 0x0c0a4b04u: goto P_0c0a4b04;
case 0x0c0a4b06u: goto P_0c0a4b06;
case 0x0c0a4b08u: goto P_0c0a4b08;
case 0x0c0a4b0au: goto P_0c0a4b0a;
case 0x0c0a4b0cu: goto P_0c0a4b0c;
case 0x0c0a4b0eu: goto P_0c0a4b0e;
case 0x0c0a4b10u: goto P_0c0a4b10;
case 0x0c0a4b12u: goto P_0c0a4b12;
case 0x0c0a4b14u: goto P_0c0a4b14;
case 0x0c0a4b16u: goto P_0c0a4b16;
case 0x0c0a4b18u: goto P_0c0a4b18;
case 0x0c0a4b1au: goto P_0c0a4b1a;
case 0x0c0a4b1cu: goto P_0c0a4b1c;
case 0x0c0a4b1eu: goto P_0c0a4b1e;
case 0x0c0a4b20u: goto P_0c0a4b20;
case 0x0c0a4b22u: goto P_0c0a4b22;
case 0x0c0a4b24u: goto P_0c0a4b24;
case 0x0c0a4b26u: goto P_0c0a4b26;
case 0x0c0a4b28u: goto P_0c0a4b28;
case 0x0c0a4b2au: goto P_0c0a4b2a;
case 0x0c0a4b2cu: goto P_0c0a4b2c;
case 0x0c0a4b2eu: goto P_0c0a4b2e;
case 0x0c0a4b30u: goto P_0c0a4b30;
case 0x0c0a4b32u: goto P_0c0a4b32;
case 0x0c0a4b34u: goto P_0c0a4b34;
case 0x0c0a4b36u: goto P_0c0a4b36;
case 0x0c0a4b38u: goto P_0c0a4b38;
case 0x0c0a4b3au: goto P_0c0a4b3a;
case 0x0c0a4b3cu: goto P_0c0a4b3c;
case 0x0c0a4b3eu: goto P_0c0a4b3e;
case 0x0c0a4b40u: goto P_0c0a4b40;
case 0x0c0a4b42u: goto P_0c0a4b42;
case 0x0c0a4b44u: goto P_0c0a4b44;
case 0x0c0a4b46u: goto P_0c0a4b46;
case 0x0c0a4b48u: goto P_0c0a4b48;
case 0x0c0a4b4au: goto P_0c0a4b4a;
case 0x0c0a4b4cu: goto P_0c0a4b4c;
case 0x0c0a4b4eu: goto P_0c0a4b4e;
case 0x0c0a4b50u: goto P_0c0a4b50;
case 0x0c0a4b52u: goto P_0c0a4b52;
case 0x0c0a4b54u: goto P_0c0a4b54;
case 0x0c0a4b56u: goto P_0c0a4b56;
case 0x0c0a4b58u: goto P_0c0a4b58;
case 0x0c0a4b5au: goto P_0c0a4b5a;
case 0x0c0a4b5cu: goto P_0c0a4b5c;
case 0x0c0a4c44u: goto P_0c0a4c44;
case 0x0c0a4c46u: goto P_0c0a4c46;
case 0x0c0a4c48u: goto P_0c0a4c48;
case 0x0c0a4c4au: goto P_0c0a4c4a;
case 0x0c0a4c4cu: goto P_0c0a4c4c;
case 0x0c0a4c4eu: goto P_0c0a4c4e;
case 0x0c0a4c50u: goto P_0c0a4c50;
case 0x0c0a4c52u: goto P_0c0a4c52;
case 0x0c0a4c54u: goto P_0c0a4c54;
case 0x0c0a4c56u: goto P_0c0a4c56;
case 0x0c0a4c58u: goto P_0c0a4c58;
case 0x0c0a4c5au: goto P_0c0a4c5a;
case 0x0c0a4c5cu: goto P_0c0a4c5c;
case 0x0c0a4c5eu: goto P_0c0a4c5e;
case 0x0c0a4c60u: goto P_0c0a4c60;
case 0x0c0a4c62u: goto P_0c0a4c62;
case 0x0c0a4c64u: goto P_0c0a4c64;
case 0x0c0a4c66u: goto P_0c0a4c66;
case 0x0c0a4c68u: goto P_0c0a4c68;
case 0x0c0a4c6au: goto P_0c0a4c6a;
case 0x0c0a4c6cu: goto P_0c0a4c6c;
case 0x0c0a4c6eu: goto P_0c0a4c6e;
case 0x0c0a4c70u: goto P_0c0a4c70;
case 0x0c0a4c72u: goto P_0c0a4c72;
case 0x0c0a4c74u: goto P_0c0a4c74;
case 0x0c0a4c76u: goto P_0c0a4c76;
case 0x0c0a4c78u: goto P_0c0a4c78;
case 0x0c0a4c7au: goto P_0c0a4c7a;
case 0x0c0a4c7cu: goto P_0c0a4c7c;
case 0x0c0a4c7eu: goto P_0c0a4c7e;
case 0x0c0a4c80u: goto P_0c0a4c80;
case 0x0c0a4c82u: goto P_0c0a4c82;
case 0x0c0a4c84u: goto P_0c0a4c84;
case 0x0c0a4c86u: goto P_0c0a4c86;
case 0x0c0a4c88u: goto P_0c0a4c88;
case 0x0c0a4c8au: goto P_0c0a4c8a;
case 0x0c0a4c8cu: goto P_0c0a4c8c;
case 0x0c0a4c8eu: goto P_0c0a4c8e;
case 0x0c0a4c90u: goto P_0c0a4c90;
case 0x0c0a4c92u: goto P_0c0a4c92;
case 0x0c0a4c94u: goto P_0c0a4c94;
case 0x0c0a4c96u: goto P_0c0a4c96;
case 0x0c0a4c98u: goto P_0c0a4c98;
case 0x0c0a4c9au: goto P_0c0a4c9a;
case 0x0c0a4c9cu: goto P_0c0a4c9c;
case 0x0c0a4c9eu: goto P_0c0a4c9e;
case 0x0c0a4ca0u: goto P_0c0a4ca0;
case 0x0c0a4ca2u: goto P_0c0a4ca2;
case 0x0c0a4ca4u: goto P_0c0a4ca4;
case 0x0c0a4ca6u: goto P_0c0a4ca6;
case 0x0c0a4ca8u: goto P_0c0a4ca8;
case 0x0c0a4caau: goto P_0c0a4caa;
case 0x0c0a4cacu: goto P_0c0a4cac;
case 0x0c0a4caeu: goto P_0c0a4cae;
case 0x0c0a4cb0u: goto P_0c0a4cb0;
case 0x0c0a4cb2u: goto P_0c0a4cb2;
case 0x0c0a4cb4u: goto P_0c0a4cb4;
case 0x0c0a4cb6u: goto P_0c0a4cb6;
case 0x0c0a4cb8u: goto P_0c0a4cb8;
case 0x0c0a4cbau: goto P_0c0a4cba;
case 0x0c0a4cbcu: goto P_0c0a4cbc;
case 0x0c0a4cbeu: goto P_0c0a4cbe;
case 0x0c0a4cc0u: goto P_0c0a4cc0;
case 0x0c0a4cc2u: goto P_0c0a4cc2;
case 0x0c0a4cc4u: goto P_0c0a4cc4;
case 0x0c0a4cc6u: goto P_0c0a4cc6;
case 0x0c0a4cc8u: goto P_0c0a4cc8;
case 0x0c0a4ccau: goto P_0c0a4cca;
case 0x0c0a4cccu: goto P_0c0a4ccc;
case 0x0c0a4cceu: goto P_0c0a4cce;
case 0x0c0a4cd0u: goto P_0c0a4cd0;
case 0x0c0a4cd2u: goto P_0c0a4cd2;
case 0x0c0a4cd4u: goto P_0c0a4cd4;
case 0x0c0a4cd6u: goto P_0c0a4cd6;
case 0x0c0a4cd8u: goto P_0c0a4cd8;
case 0x0c0a4cdau: goto P_0c0a4cda;
case 0x0c0a4cdcu: goto P_0c0a4cdc;
case 0x0c0a4cdeu: goto P_0c0a4cde;
case 0x0c0a4ce0u: goto P_0c0a4ce0;
case 0x0c0a4ce2u: goto P_0c0a4ce2;
case 0x0c0a4ce4u: goto P_0c0a4ce4;
case 0x0c0a4ce6u: goto P_0c0a4ce6;
case 0x0c0a4ce8u: goto P_0c0a4ce8;
case 0x0c0a4ceau: goto P_0c0a4cea;
case 0x0c0a4cecu: goto P_0c0a4cec;
case 0x0c0a4ceeu: goto P_0c0a4cee;
case 0x0c0a4cf0u: goto P_0c0a4cf0;
case 0x0c0a4cf2u: goto P_0c0a4cf2;
case 0x0c0a4cf4u: goto P_0c0a4cf4;
case 0x0c0a4cf6u: goto P_0c0a4cf6;
case 0x0c0a4cf8u: goto P_0c0a4cf8;
case 0x0c0a4cfau: goto P_0c0a4cfa;
case 0x0c0a4cfcu: goto P_0c0a4cfc;
case 0x0c0a4cfeu: goto P_0c0a4cfe;
case 0x0c0a4d00u: goto P_0c0a4d00;
case 0x0c0a4d02u: goto P_0c0a4d02;
case 0x0c0a4d04u: goto P_0c0a4d04;
case 0x0c0a4e18u: goto P_0c0a4e18;
case 0x0c0a4e1au: goto P_0c0a4e1a;
case 0x0c0a4e1cu: goto P_0c0a4e1c;
case 0x0c0a4e1eu: goto P_0c0a4e1e;
case 0x0c0a4e20u: goto P_0c0a4e20;
case 0x0c0a4e22u: goto P_0c0a4e22;
case 0x0c0a4e24u: goto P_0c0a4e24;
case 0x0c0a4e26u: goto P_0c0a4e26;
case 0x0c0a4e28u: goto P_0c0a4e28;
case 0x0c0a4e2au: goto P_0c0a4e2a;
case 0x0c0a4e2cu: goto P_0c0a4e2c;
case 0x0c0a4e2eu: goto P_0c0a4e2e;
case 0x0c0a4e30u: goto P_0c0a4e30;
case 0x0c0a4e32u: goto P_0c0a4e32;
case 0x0c0a4e34u: goto P_0c0a4e34;
case 0x0c0a4e36u: goto P_0c0a4e36;
case 0x0c0a4e38u: goto P_0c0a4e38;
case 0x0c0a4e3au: goto P_0c0a4e3a;
case 0x0c0a4e3cu: goto P_0c0a4e3c;
case 0x0c0a4e3eu: goto P_0c0a4e3e;
case 0x0c0a4e40u: goto P_0c0a4e40;
case 0x0c0a4e42u: goto P_0c0a4e42;
case 0x0c0a4e44u: goto P_0c0a4e44;
case 0x0c0a4e46u: goto P_0c0a4e46;
case 0x0c0a4e48u: goto P_0c0a4e48;
case 0x0c0a4e4au: goto P_0c0a4e4a;
case 0x0c0a4e4cu: goto P_0c0a4e4c;
case 0x0c0a4e4eu: goto P_0c0a4e4e;
case 0x0c0a4e50u: goto P_0c0a4e50;
case 0x0c0a4e52u: goto P_0c0a4e52;
case 0x0c0a4e54u: goto P_0c0a4e54;
case 0x0c0a4e56u: goto P_0c0a4e56;
case 0x0c0a4e58u: goto P_0c0a4e58;
case 0x0c0a4e5au: goto P_0c0a4e5a;
case 0x0c0a4e5cu: goto P_0c0a4e5c;
case 0x0c0a4e5eu: goto P_0c0a4e5e;
case 0x0c0a4e60u: goto P_0c0a4e60;
case 0x0c0a4e62u: goto P_0c0a4e62;
case 0x0c0a4e64u: goto P_0c0a4e64;
case 0x0c0a4e66u: goto P_0c0a4e66;
case 0x0c0a4e68u: goto P_0c0a4e68;
case 0x0c0a4e6au: goto P_0c0a4e6a;
case 0x0c0a4e6cu: goto P_0c0a4e6c;
case 0x0c0a4e6eu: goto P_0c0a4e6e;
case 0x0c0a4e70u: goto P_0c0a4e70;
case 0x0c0a4e72u: goto P_0c0a4e72;
case 0x0c0a4e74u: goto P_0c0a4e74;
case 0x0c0a4e76u: goto P_0c0a4e76;
case 0x0c0a4e78u: goto P_0c0a4e78;
case 0x0c0a4e7au: goto P_0c0a4e7a;
case 0x0c0a4e7cu: goto P_0c0a4e7c;
case 0x0c0a4e7eu: goto P_0c0a4e7e;
case 0x0c0a4e80u: goto P_0c0a4e80;
case 0x0c0a4e82u: goto P_0c0a4e82;
case 0x0c0a4e84u: goto P_0c0a4e84;
case 0x0c0a4e86u: goto P_0c0a4e86;
case 0x0c0a4e88u: goto P_0c0a4e88;
case 0x0c0a4e8au: goto P_0c0a4e8a;
case 0x0c0a4e8cu: goto P_0c0a4e8c;
case 0x0c0a4e8eu: goto P_0c0a4e8e;
case 0x0c0a4e90u: goto P_0c0a4e90;
case 0x0c0a4e92u: goto P_0c0a4e92;
case 0x0c0a4e94u: goto P_0c0a4e94;
case 0x0c0a4e96u: goto P_0c0a4e96;
case 0x0c0a4e98u: goto P_0c0a4e98;
case 0x0c0a4e9au: goto P_0c0a4e9a;
case 0x0c0a4e9cu: goto P_0c0a4e9c;
case 0x0c0a4e9eu: goto P_0c0a4e9e;
case 0x0c0a4ea0u: goto P_0c0a4ea0;
case 0x0c0a4f90u: goto P_0c0a4f90;
case 0x0c0a4f92u: goto P_0c0a4f92;
case 0x0c0a4f94u: goto P_0c0a4f94;
case 0x0c0a4f96u: goto P_0c0a4f96;
case 0x0c0a4f98u: goto P_0c0a4f98;
case 0x0c0a4f9au: goto P_0c0a4f9a;
case 0x0c0a4f9cu: goto P_0c0a4f9c;
case 0x0c0a4f9eu: goto P_0c0a4f9e;
case 0x0c0a4fa0u: goto P_0c0a4fa0;
case 0x0c0a4fa2u: goto P_0c0a4fa2;
case 0x0c0a4fa4u: goto P_0c0a4fa4;
case 0x0c0a4fa6u: goto P_0c0a4fa6;
case 0x0c0a4fa8u: goto P_0c0a4fa8;
case 0x0c0a4faau: goto P_0c0a4faa;
case 0x0c0a4facu: goto P_0c0a4fac;
case 0x0c0a4faeu: goto P_0c0a4fae;
case 0x0c0a4fb0u: goto P_0c0a4fb0;
case 0x0c0a4fb2u: goto P_0c0a4fb2;
case 0x0c0a4fb4u: goto P_0c0a4fb4;
case 0x0c0a4fb6u: goto P_0c0a4fb6;
case 0x0c0a4fb8u: goto P_0c0a4fb8;
case 0x0c0a4fbau: goto P_0c0a4fba;
case 0x0c0a4fbcu: goto P_0c0a4fbc;
case 0x0c0a4fbeu: goto P_0c0a4fbe;
case 0x0c0a4fc0u: goto P_0c0a4fc0;
case 0x0c0a4fc2u: goto P_0c0a4fc2;
case 0x0c0a4fc4u: goto P_0c0a4fc4;
case 0x0c0a4fc6u: goto P_0c0a4fc6;
case 0x0c0a4fc8u: goto P_0c0a4fc8;
case 0x0c0a4fcau: goto P_0c0a4fca;
case 0x0c0a4fccu: goto P_0c0a4fcc;
case 0x0c0a4fceu: goto P_0c0a4fce;
case 0x0c0a4fd0u: goto P_0c0a4fd0;
case 0x0c0a4fd2u: goto P_0c0a4fd2;
case 0x0c0a4fd4u: goto P_0c0a4fd4;
case 0x0c0a4fd6u: goto P_0c0a4fd6;
case 0x0c0a4fd8u: goto P_0c0a4fd8;
case 0x0c0a4fdau: goto P_0c0a4fda;
case 0x0c0a4fdcu: goto P_0c0a4fdc;
case 0x0c0a4fdeu: goto P_0c0a4fde;
case 0x0c0a4fe0u: goto P_0c0a4fe0;
case 0x0c0a4fe2u: goto P_0c0a4fe2;
case 0x0c0a4fe4u: goto P_0c0a4fe4;
case 0x0c0a4fe6u: goto P_0c0a4fe6;
case 0x0c0a4fe8u: goto P_0c0a4fe8;
case 0x0c0a4feau: goto P_0c0a4fea;
case 0x0c0a4fecu: goto P_0c0a4fec;
case 0x0c0a4feeu: goto P_0c0a4fee;
case 0x0c0a4ff0u: goto P_0c0a4ff0;
case 0x0c0a4ff2u: goto P_0c0a4ff2;
case 0x0c0a4ff4u: goto P_0c0a4ff4;
case 0x0c0a4ff6u: goto P_0c0a4ff6;
case 0x0c0a4ff8u: goto P_0c0a4ff8;
case 0x0c0a4ffau: goto P_0c0a4ffa;
case 0x0c0a4ffcu: goto P_0c0a4ffc;
case 0x0c0a4ffeu: goto P_0c0a4ffe;
case 0x0c0a5000u: goto P_0c0a5000;
case 0x0c0a5002u: goto P_0c0a5002;
case 0x0c0a5004u: goto P_0c0a5004;
case 0x0c0a5006u: goto P_0c0a5006;
case 0x0c0a5008u: goto P_0c0a5008;
case 0x0c0a500au: goto P_0c0a500a;
case 0x0c0a500cu: goto P_0c0a500c;
case 0x0c0a500eu: goto P_0c0a500e;
case 0x0c0a5010u: goto P_0c0a5010;
case 0x0c0a5012u: goto P_0c0a5012;
case 0x0c0a5014u: goto P_0c0a5014;
case 0x0c0a5016u: goto P_0c0a5016;
case 0x0c0a5018u: goto P_0c0a5018;
case 0x0c0a5124u: goto P_0c0a5124;
case 0x0c0a5126u: goto P_0c0a5126;
case 0x0c0a5128u: goto P_0c0a5128;
case 0x0c0a512au: goto P_0c0a512a;
case 0x0c0a512cu: goto P_0c0a512c;
case 0x0c0a512eu: goto P_0c0a512e;
case 0x0c0a5130u: goto P_0c0a5130;
case 0x0c0a5132u: goto P_0c0a5132;
case 0x0c0a5134u: goto P_0c0a5134;
case 0x0c0a5136u: goto P_0c0a5136;
case 0x0c0a5138u: goto P_0c0a5138;
case 0x0c0a513au: goto P_0c0a513a;
case 0x0c0a513cu: goto P_0c0a513c;
case 0x0c0a513eu: goto P_0c0a513e;
case 0x0c0a5140u: goto P_0c0a5140;
case 0x0c0a5142u: goto P_0c0a5142;
case 0x0c0a5144u: goto P_0c0a5144;
case 0x0c0a5146u: goto P_0c0a5146;
case 0x0c0a5148u: goto P_0c0a5148;
case 0x0c0a514au: goto P_0c0a514a;
case 0x0c0a514cu: goto P_0c0a514c;
case 0x0c0a514eu: goto P_0c0a514e;
case 0x0c0a5150u: goto P_0c0a5150;
case 0x0c0a5152u: goto P_0c0a5152;
case 0x0c0a5154u: goto P_0c0a5154;
case 0x0c0a5156u: goto P_0c0a5156;
case 0x0c0a5158u: goto P_0c0a5158;
case 0x0c0a515au: goto P_0c0a515a;
case 0x0c0a515cu: goto P_0c0a515c;
case 0x0c0a515eu: goto P_0c0a515e;
case 0x0c0a5160u: goto P_0c0a5160;
case 0x0c0a5162u: goto P_0c0a5162;
case 0x0c0a5164u: goto P_0c0a5164;
case 0x0c0a5166u: goto P_0c0a5166;
case 0x0c0a5168u: goto P_0c0a5168;
case 0x0c0a516au: goto P_0c0a516a;
case 0x0c0a516cu: goto P_0c0a516c;
case 0x0c0a516eu: goto P_0c0a516e;
case 0x0c0a5170u: goto P_0c0a5170;
case 0x0c0a5172u: goto P_0c0a5172;
case 0x0c0a5174u: goto P_0c0a5174;
case 0x0c0a5176u: goto P_0c0a5176;
case 0x0c0a5178u: goto P_0c0a5178;
case 0x0c0a517au: goto P_0c0a517a;
case 0x0c0a517cu: goto P_0c0a517c;
case 0x0c0a517eu: goto P_0c0a517e;
case 0x0c0a5180u: goto P_0c0a5180;
case 0x0c0a5182u: goto P_0c0a5182;
case 0x0c0a5184u: goto P_0c0a5184;
case 0x0c0a5186u: goto P_0c0a5186;
case 0x0c0a5188u: goto P_0c0a5188;
case 0x0c0a518au: goto P_0c0a518a;
case 0x0c0a518cu: goto P_0c0a518c;
case 0x0c0a518eu: goto P_0c0a518e;
case 0x0c0a5190u: goto P_0c0a5190;
case 0x0c0a5192u: goto P_0c0a5192;
case 0x0c0a5194u: goto P_0c0a5194;
case 0x0c0a5196u: goto P_0c0a5196;
case 0x0c0a5198u: goto P_0c0a5198;
case 0x0c0a519au: goto P_0c0a519a;
case 0x0c0a519cu: goto P_0c0a519c;
case 0x0c0a519eu: goto P_0c0a519e;
case 0x0c0a51a0u: goto P_0c0a51a0;
case 0x0c0a51a2u: goto P_0c0a51a2;
case 0x0c0a51a4u: goto P_0c0a51a4;
case 0x0c0a51a6u: goto P_0c0a51a6;
case 0x0c0a51a8u: goto P_0c0a51a8;
case 0x0c0a51aau: goto P_0c0a51aa;
case 0x0c0a51acu: goto P_0c0a51ac;
case 0x0c0a51aeu: goto P_0c0a51ae;
case 0x0c0a51b0u: goto P_0c0a51b0;
case 0x0c0a51b2u: goto P_0c0a51b2;
case 0x0c0a51b4u: goto P_0c0a51b4;
case 0x0c0a51b6u: goto P_0c0a51b6;
case 0x0c0a51b8u: goto P_0c0a51b8;
case 0x0c0a51bau: goto P_0c0a51ba;
case 0x0c0a51bcu: goto P_0c0a51bc;
case 0x0c0a51beu: goto P_0c0a51be;
case 0x0c0a51c0u: goto P_0c0a51c0;
case 0x0c0a51c2u: goto P_0c0a51c2;
case 0x0c0a51c4u: goto P_0c0a51c4;
case 0x0c0a51c6u: goto P_0c0a51c6;
case 0x0c0a51c8u: goto P_0c0a51c8;
case 0x0c0a51cau: goto P_0c0a51ca;
case 0x0c0a51ccu: goto P_0c0a51cc;
case 0x0c0a51ceu: goto P_0c0a51ce;
case 0x0c0a51d0u: goto P_0c0a51d0;
case 0x0c0a51d2u: goto P_0c0a51d2;
case 0x0c0a51d4u: goto P_0c0a51d4;
case 0x0c0a51d6u: goto P_0c0a51d6;
case 0x0c0a51d8u: goto P_0c0a51d8;
case 0x0c0a51dau: goto P_0c0a51da;
case 0x0c0a51dcu: goto P_0c0a51dc;
case 0x0c0a51deu: goto P_0c0a51de;
case 0x0c0a51e0u: goto P_0c0a51e0;
case 0x0c0a51e2u: goto P_0c0a51e2;
case 0x0c0a51e4u: goto P_0c0a51e4;
case 0x0c0a51e6u: goto P_0c0a51e6;
case 0x0c0a51e8u: goto P_0c0a51e8;
case 0x0c0a51eau: goto P_0c0a51ea;
case 0x0c0a51ecu: goto P_0c0a51ec;
case 0x0c0a51eeu: goto P_0c0a51ee;
case 0x0c0a51f0u: goto P_0c0a51f0;
case 0x0c0a51f2u: goto P_0c0a51f2;
case 0x0c0a51f4u: goto P_0c0a51f4;
case 0x0c0a51f6u: goto P_0c0a51f6;
case 0x0c0a51f8u: goto P_0c0a51f8;
case 0x0c0a51fau: goto P_0c0a51fa;
case 0x0c0a51fcu: goto P_0c0a51fc;
case 0x0c0a51feu: goto P_0c0a51fe;
case 0x0c0a5200u: goto P_0c0a5200;
case 0x0c0a5202u: goto P_0c0a5202;
case 0x0c0a5204u: goto P_0c0a5204;
case 0x0c0a5206u: goto P_0c0a5206;
case 0x0c0a5208u: goto P_0c0a5208;
case 0x0c0a520au: goto P_0c0a520a;
case 0x0c0a520cu: goto P_0c0a520c;
case 0x0c0a520eu: goto P_0c0a520e;
case 0x0c0a5210u: goto P_0c0a5210;
case 0x0c0a5212u: goto P_0c0a5212;
case 0x0c0a5214u: goto P_0c0a5214;
case 0x0c0a5216u: goto P_0c0a5216;
case 0x0c0a5218u: goto P_0c0a5218;
case 0x0c0a521au: goto P_0c0a521a;
case 0x0c0a521cu: goto P_0c0a521c;
case 0x0c0a521eu: goto P_0c0a521e;
case 0x0c0a5220u: goto P_0c0a5220;
case 0x0c0a5222u: goto P_0c0a5222;
case 0x0c0a5224u: goto P_0c0a5224;
case 0x0c0a5226u: goto P_0c0a5226;
case 0x0c0a5228u: goto P_0c0a5228;
case 0x0c0a522au: goto P_0c0a522a;
case 0x0c0a522cu: goto P_0c0a522c;
case 0x0c0a522eu: goto P_0c0a522e;
case 0x0c0a5230u: goto P_0c0a5230;
case 0x0c0a5232u: goto P_0c0a5232;
case 0x0c0a5234u: goto P_0c0a5234;
case 0x0c0a5236u: goto P_0c0a5236;
case 0x0c0a5238u: goto P_0c0a5238;
case 0x0c0a523au: goto P_0c0a523a;
case 0x0c0a523cu: goto P_0c0a523c;
case 0x0c0a523eu: goto P_0c0a523e;
case 0x0c0a5240u: goto P_0c0a5240;
case 0x0c0a5242u: goto P_0c0a5242;
case 0x0c0a5244u: goto P_0c0a5244;
case 0x0c0a5246u: goto P_0c0a5246;
case 0x0c0a5248u: goto P_0c0a5248;
case 0x0c0a524au: goto P_0c0a524a;
case 0x0c0a524cu: goto P_0c0a524c;
case 0x0c0a524eu: goto P_0c0a524e;
case 0x0c0a5250u: goto P_0c0a5250;
case 0x0c0a5252u: goto P_0c0a5252;
case 0x0c0a5254u: goto P_0c0a5254;
case 0x0c0a5256u: goto P_0c0a5256;
case 0x0c0a5258u: goto P_0c0a5258;
case 0x0c0a525au: goto P_0c0a525a;
case 0x0c0a525cu: goto P_0c0a525c;
case 0x0c0a525eu: goto P_0c0a525e;
case 0x0c0a5260u: goto P_0c0a5260;
case 0x0c0a5262u: goto P_0c0a5262;
case 0x0c0a5264u: goto P_0c0a5264;
case 0x0c0a5266u: goto P_0c0a5266;
case 0x0c0a5268u: goto P_0c0a5268;
case 0x0c0a526au: goto P_0c0a526a;
case 0x0c0a526cu: goto P_0c0a526c;
case 0x0c0a526eu: goto P_0c0a526e;
case 0x0c0a5270u: goto P_0c0a5270;
case 0x0c0a5272u: goto P_0c0a5272;
case 0x0c0a5274u: goto P_0c0a5274;
case 0x0c0a5276u: goto P_0c0a5276;
case 0x0c0a5278u: goto P_0c0a5278;
case 0x0c0a527au: goto P_0c0a527a;
case 0x0c0a527cu: goto P_0c0a527c;
case 0x0c0a527eu: goto P_0c0a527e;
case 0x0c0a5280u: goto P_0c0a5280;
case 0x0c0a5282u: goto P_0c0a5282;
case 0x0c0a5284u: goto P_0c0a5284;
case 0x0c0a5286u: goto P_0c0a5286;
case 0x0c0a5288u: goto P_0c0a5288;
case 0x0c0a528au: goto P_0c0a528a;
case 0x0c0a528cu: goto P_0c0a528c;
case 0x0c0a5a3cu: goto P_0c0a5a3c;
case 0x0c0a5a3eu: goto P_0c0a5a3e;
case 0x0c0a5a40u: goto P_0c0a5a40;
case 0x0c0a5a42u: goto P_0c0a5a42;
case 0x0c0a5a44u: goto P_0c0a5a44;
case 0x0c0a5a46u: goto P_0c0a5a46;
case 0x0c0a5a48u: goto P_0c0a5a48;
case 0x0c0a5a4au: goto P_0c0a5a4a;
case 0x0c0a5a4cu: goto P_0c0a5a4c;
case 0x0c0a5a4eu: goto P_0c0a5a4e;
case 0x0c0a5a50u: goto P_0c0a5a50;
case 0x0c0a5a52u: goto P_0c0a5a52;
case 0x0c0a5a54u: goto P_0c0a5a54;
case 0x0c0a5a56u: goto P_0c0a5a56;
case 0x0c0a5a58u: goto P_0c0a5a58;
case 0x0c0a5a5au: goto P_0c0a5a5a;
case 0x0c0a5a5cu: goto P_0c0a5a5c;
case 0x0c0a5a5eu: goto P_0c0a5a5e;
case 0x0c0a5a60u: goto P_0c0a5a60;
case 0x0c0a5a62u: goto P_0c0a5a62;
case 0x0c0a5a64u: goto P_0c0a5a64;
case 0x0c0a5a66u: goto P_0c0a5a66;
case 0x0c0a5a68u: goto P_0c0a5a68;
case 0x0c0a5a6au: goto P_0c0a5a6a;
case 0x0c0a5a6cu: goto P_0c0a5a6c;
case 0x0c0a5a6eu: goto P_0c0a5a6e;
case 0x0c0a5a70u: goto P_0c0a5a70;
case 0x0c0a5a72u: goto P_0c0a5a72;
case 0x0c0a5a74u: goto P_0c0a5a74;
case 0x0c0a5a76u: goto P_0c0a5a76;
case 0x0c0a5a78u: goto P_0c0a5a78;
case 0x0c0a5a7au: goto P_0c0a5a7a;
case 0x0c0a5a7cu: goto P_0c0a5a7c;
case 0x0c0a5a7eu: goto P_0c0a5a7e;
case 0x0c0a5a80u: goto P_0c0a5a80;
case 0x0c0a5a82u: goto P_0c0a5a82;
case 0x0c0a5a84u: goto P_0c0a5a84;
case 0x0c0a5a86u: goto P_0c0a5a86;
case 0x0c0a5a88u: goto P_0c0a5a88;
case 0x0c0a5a8au: goto P_0c0a5a8a;
case 0x0c0a5a8cu: goto P_0c0a5a8c;
case 0x0c0a5a8eu: goto P_0c0a5a8e;
case 0x0c0a5a90u: goto P_0c0a5a90;
case 0x0c0a5a92u: goto P_0c0a5a92;
case 0x0c0a5a94u: goto P_0c0a5a94;
case 0x0c0a5a96u: goto P_0c0a5a96;
case 0x0c0a5a98u: goto P_0c0a5a98;
case 0x0c0a5a9au: goto P_0c0a5a9a;
case 0x0c0a5a9cu: goto P_0c0a5a9c;
case 0x0c0a5a9eu: goto P_0c0a5a9e;
case 0x0c0a5aa0u: goto P_0c0a5aa0;
case 0x0c0a5aa2u: goto P_0c0a5aa2;
case 0x0c0a5aa4u: goto P_0c0a5aa4;
case 0x0c0a5aa6u: goto P_0c0a5aa6;
case 0x0c0a5aa8u: goto P_0c0a5aa8;
case 0x0c0a5aaau: goto P_0c0a5aaa;
case 0x0c0a5aacu: goto P_0c0a5aac;
case 0x0c0a5aaeu: goto P_0c0a5aae;
case 0x0c0a5ab0u: goto P_0c0a5ab0;
case 0x0c0a5ab2u: goto P_0c0a5ab2;
case 0x0c0a5ab4u: goto P_0c0a5ab4;
case 0x0c0a5ab6u: goto P_0c0a5ab6;
case 0x0c0a5ab8u: goto P_0c0a5ab8;
case 0x0c0a5abau: goto P_0c0a5aba;
case 0x0c0a5abcu: goto P_0c0a5abc;
case 0x0c0a5abeu: goto P_0c0a5abe;
case 0x0c0a5ac0u: goto P_0c0a5ac0;
case 0x0c0a5ac2u: goto P_0c0a5ac2;
case 0x0c0a5ac4u: goto P_0c0a5ac4;
case 0x0c0a5ac6u: goto P_0c0a5ac6;
case 0x0c0a5ac8u: goto P_0c0a5ac8;
case 0x0c0a5acau: goto P_0c0a5aca;
case 0x0c0a5accu: goto P_0c0a5acc;
case 0x0c0a5aceu: goto P_0c0a5ace;
case 0x0c0a5ad0u: goto P_0c0a5ad0;
case 0x0c0a5ad2u: goto P_0c0a5ad2;
case 0x0c0a5ad4u: goto P_0c0a5ad4;
case 0x0c0a5ad6u: goto P_0c0a5ad6;
case 0x0c0a5ad8u: goto P_0c0a5ad8;
case 0x0c0a5adau: goto P_0c0a5ada;
case 0x0c0a5adcu: goto P_0c0a5adc;
case 0x0c0a5adeu: goto P_0c0a5ade;
case 0x0c0a5ae0u: goto P_0c0a5ae0;
case 0x0c0a5ae2u: goto P_0c0a5ae2;
case 0x0c0a5ae4u: goto P_0c0a5ae4;
case 0x0c0a5ae6u: goto P_0c0a5ae6;
case 0x0c0a5ae8u: goto P_0c0a5ae8;
case 0x0c0a5aeau: goto P_0c0a5aea;
case 0x0c0a5aecu: goto P_0c0a5aec;
case 0x0c0a5aeeu: goto P_0c0a5aee;
case 0x0c0a5af0u: goto P_0c0a5af0;
case 0x0c0a5af2u: goto P_0c0a5af2;
case 0x0c0a5af4u: goto P_0c0a5af4;
case 0x0c0a5af6u: goto P_0c0a5af6;
case 0x0c0a5af8u: goto P_0c0a5af8;
case 0x0c0a5afau: goto P_0c0a5afa;
case 0x0c0a5afcu: goto P_0c0a5afc;
case 0x0c0a5afeu: goto P_0c0a5afe;
case 0x0c0a5b00u: goto P_0c0a5b00;
case 0x0c0a5b02u: goto P_0c0a5b02;
case 0x0c0a5b04u: goto P_0c0a5b04;
case 0x0c0a5b06u: goto P_0c0a5b06;
case 0x0c0a5b08u: goto P_0c0a5b08;
case 0x0c0a5b0au: goto P_0c0a5b0a;
case 0x0c0a5b0cu: goto P_0c0a5b0c;
case 0x0c0a5b0eu: goto P_0c0a5b0e;
case 0x0c0a5b10u: goto P_0c0a5b10;
case 0x0c0a5b12u: goto P_0c0a5b12;
case 0x0c0a5b14u: goto P_0c0a5b14;
case 0x0c0a5c8cu: goto P_0c0a5c8c;
case 0x0c0a5c8eu: goto P_0c0a5c8e;
case 0x0c0a5c90u: goto P_0c0a5c90;
case 0x0c0a5c92u: goto P_0c0a5c92;
case 0x0c0a5c94u: goto P_0c0a5c94;
case 0x0c0a5c96u: goto P_0c0a5c96;
case 0x0c0a5c98u: goto P_0c0a5c98;
case 0x0c0a5c9au: goto P_0c0a5c9a;
case 0x0c0a5c9cu: goto P_0c0a5c9c;
case 0x0c0a5c9eu: goto P_0c0a5c9e;
case 0x0c0a5ca0u: goto P_0c0a5ca0;
case 0x0c0a5ca2u: goto P_0c0a5ca2;
case 0x0c0a5ca4u: goto P_0c0a5ca4;
case 0x0c0a5ca6u: goto P_0c0a5ca6;
case 0x0c0a5ca8u: goto P_0c0a5ca8;
case 0x0c0a5caau: goto P_0c0a5caa;
case 0x0c0a5cacu: goto P_0c0a5cac;
case 0x0c0a5caeu: goto P_0c0a5cae;
case 0x0c0a5cb0u: goto P_0c0a5cb0;
case 0x0c0a5cb2u: goto P_0c0a5cb2;
case 0x0c0a5cb4u: goto P_0c0a5cb4;
case 0x0c0a5cb6u: goto P_0c0a5cb6;
case 0x0c0a5cb8u: goto P_0c0a5cb8;
case 0x0c0a5cbau: goto P_0c0a5cba;
case 0x0c0a5cbcu: goto P_0c0a5cbc;
case 0x0c0a5cbeu: goto P_0c0a5cbe;
case 0x0c0a5cc0u: goto P_0c0a5cc0;
case 0x0c0a5cc2u: goto P_0c0a5cc2;
case 0x0c0a5cc4u: goto P_0c0a5cc4;
case 0x0c0a5cc6u: goto P_0c0a5cc6;
case 0x0c0a5cc8u: goto P_0c0a5cc8;
case 0x0c0a5ccau: goto P_0c0a5cca;
case 0x0c0a5cccu: goto P_0c0a5ccc;
case 0x0c0a5cceu: goto P_0c0a5cce;
case 0x0c0a5cd0u: goto P_0c0a5cd0;
case 0x0c0a5cd2u: goto P_0c0a5cd2;
case 0x0c0a5cd4u: goto P_0c0a5cd4;
case 0x0c0a5cd6u: goto P_0c0a5cd6;
case 0x0c0a5cd8u: goto P_0c0a5cd8;
case 0x0c0a5cdau: goto P_0c0a5cda;
case 0x0c0a5cdcu: goto P_0c0a5cdc;
case 0x0c0a5cdeu: goto P_0c0a5cde;
case 0x0c0a5ce0u: goto P_0c0a5ce0;
case 0x0c0a5ce2u: goto P_0c0a5ce2;
case 0x0c0a5ce4u: goto P_0c0a5ce4;
case 0x0c0a5ce6u: goto P_0c0a5ce6;
case 0x0c0a5ce8u: goto P_0c0a5ce8;
case 0x0c0a5ceau: goto P_0c0a5cea;
case 0x0c0a5cecu: goto P_0c0a5cec;
case 0x0c0a5ceeu: goto P_0c0a5cee;
case 0x0c0a5cf0u: goto P_0c0a5cf0;
case 0x0c0a5cf2u: goto P_0c0a5cf2;
case 0x0c0a5cf4u: goto P_0c0a5cf4;
case 0x0c0a5cf6u: goto P_0c0a5cf6;
case 0x0c0a5cf8u: goto P_0c0a5cf8;
case 0x0c0a5cfau: goto P_0c0a5cfa;
case 0x0c0a5cfcu: goto P_0c0a5cfc;
case 0x0c0a5cfeu: goto P_0c0a5cfe;
case 0x0c0a5d00u: goto P_0c0a5d00;
case 0x0c0a5d02u: goto P_0c0a5d02;
case 0x0c0a5d04u: goto P_0c0a5d04;
case 0x0c0a5d06u: goto P_0c0a5d06;
case 0x0c0a5d08u: goto P_0c0a5d08;
case 0x0c0a5d0au: goto P_0c0a5d0a;
case 0x0c0a5d0cu: goto P_0c0a5d0c;
case 0x0c0a5d0eu: goto P_0c0a5d0e;
case 0x0c0a5d10u: goto P_0c0a5d10;
case 0x0c0a5d12u: goto P_0c0a5d12;
case 0x0c0a5d14u: goto P_0c0a5d14;
case 0x0c0a5d16u: goto P_0c0a5d16;
case 0x0c0a5d18u: goto P_0c0a5d18;
case 0x0c0a5d1au: goto P_0c0a5d1a;
case 0x0c0a5d1cu: goto P_0c0a5d1c;
case 0x0c0a5d1eu: goto P_0c0a5d1e;
case 0x0c0a5d20u: goto P_0c0a5d20;
case 0x0c0a5d22u: goto P_0c0a5d22;
case 0x0c0a5d24u: goto P_0c0a5d24;
case 0x0c0a5d26u: goto P_0c0a5d26;
case 0x0c0a5d28u: goto P_0c0a5d28;
case 0x0c0a5d2au: goto P_0c0a5d2a;
case 0x0c0a5d2cu: goto P_0c0a5d2c;
case 0x0c0a5d2eu: goto P_0c0a5d2e;
case 0x0c0a5d30u: goto P_0c0a5d30;
case 0x0c0a5d32u: goto P_0c0a5d32;
case 0x0c0a5d34u: goto P_0c0a5d34;
case 0x0c0a5d36u: goto P_0c0a5d36;
case 0x0c0a5d38u: goto P_0c0a5d38;
case 0x0c0a5d3au: goto P_0c0a5d3a;
case 0x0c0a5d3cu: goto P_0c0a5d3c;
case 0x0c0a5d3eu: goto P_0c0a5d3e;
case 0x0c0a5d40u: goto P_0c0a5d40;
case 0x0c0a5d42u: goto P_0c0a5d42;
case 0x0c0a5d44u: goto P_0c0a5d44;
case 0x0c0a5d46u: goto P_0c0a5d46;
case 0x0c0a5d48u: goto P_0c0a5d48;
case 0x0c0a5d4au: goto P_0c0a5d4a;
case 0x0c0a5d4cu: goto P_0c0a5d4c;
case 0x0c0a5d4eu: goto P_0c0a5d4e;
case 0x0c0a5d50u: goto P_0c0a5d50;
case 0x0c0a5d52u: goto P_0c0a5d52;
case 0x0c0a5d54u: goto P_0c0a5d54;
case 0x0c0a5d56u: goto P_0c0a5d56;
case 0x0c0a5d58u: goto P_0c0a5d58;
case 0x0c0a5d5au: goto P_0c0a5d5a;
case 0x0c0a5d5cu: goto P_0c0a5d5c;
case 0x0c0a5ec8u: goto P_0c0a5ec8;
case 0x0c0a5ecau: goto P_0c0a5eca;
case 0x0c0a5eccu: goto P_0c0a5ecc;
case 0x0c0a5eceu: goto P_0c0a5ece;
case 0x0c0a5ed0u: goto P_0c0a5ed0;
case 0x0c0a5ed2u: goto P_0c0a5ed2;
case 0x0c0a5ed4u: goto P_0c0a5ed4;
case 0x0c0a5ed6u: goto P_0c0a5ed6;
case 0x0c0a5ed8u: goto P_0c0a5ed8;
case 0x0c0a5edau: goto P_0c0a5eda;
case 0x0c0a5edcu: goto P_0c0a5edc;
case 0x0c0a5edeu: goto P_0c0a5ede;
case 0x0c0a5ee0u: goto P_0c0a5ee0;
case 0x0c0a5ee2u: goto P_0c0a5ee2;
case 0x0c0a5ee4u: goto P_0c0a5ee4;
case 0x0c0a5ee6u: goto P_0c0a5ee6;
case 0x0c0a5ee8u: goto P_0c0a5ee8;
case 0x0c0a5eeau: goto P_0c0a5eea;
case 0x0c0a5eecu: goto P_0c0a5eec;
case 0x0c0a5eeeu: goto P_0c0a5eee;
case 0x0c0a5ef0u: goto P_0c0a5ef0;
case 0x0c0a5ef2u: goto P_0c0a5ef2;
case 0x0c0a5ef4u: goto P_0c0a5ef4;
case 0x0c0a5ef6u: goto P_0c0a5ef6;
case 0x0c0a5ef8u: goto P_0c0a5ef8;
case 0x0c0a5efau: goto P_0c0a5efa;
case 0x0c0a5efcu: goto P_0c0a5efc;
case 0x0c0a5efeu: goto P_0c0a5efe;
case 0x0c0a5f00u: goto P_0c0a5f00;
case 0x0c0a5f02u: goto P_0c0a5f02;
case 0x0c0a5f04u: goto P_0c0a5f04;
case 0x0c0a5f06u: goto P_0c0a5f06;
case 0x0c0a5f08u: goto P_0c0a5f08;
case 0x0c0a5f0au: goto P_0c0a5f0a;
case 0x0c0a5f0cu: goto P_0c0a5f0c;
case 0x0c0a5f0eu: goto P_0c0a5f0e;
case 0x0c0a5f10u: goto P_0c0a5f10;
case 0x0c0a5f12u: goto P_0c0a5f12;
case 0x0c0a5f14u: goto P_0c0a5f14;
case 0x0c0a5f16u: goto P_0c0a5f16;
case 0x0c0a5f18u: goto P_0c0a5f18;
case 0x0c0a5f1au: goto P_0c0a5f1a;
case 0x0c0a5f1cu: goto P_0c0a5f1c;
case 0x0c0a5f1eu: goto P_0c0a5f1e;
case 0x0c0a5f20u: goto P_0c0a5f20;
case 0x0c0a5f22u: goto P_0c0a5f22;
case 0x0c0a5f24u: goto P_0c0a5f24;
case 0x0c0a5f26u: goto P_0c0a5f26;
case 0x0c0a5f28u: goto P_0c0a5f28;
case 0x0c0a5f2au: goto P_0c0a5f2a;
case 0x0c0a5f2cu: goto P_0c0a5f2c;
case 0x0c0a5f2eu: goto P_0c0a5f2e;
case 0x0c0a5f30u: goto P_0c0a5f30;
case 0x0c0a5f32u: goto P_0c0a5f32;
case 0x0c0a5f34u: goto P_0c0a5f34;
case 0x0c0a5f36u: goto P_0c0a5f36;
case 0x0c0a5f38u: goto P_0c0a5f38;
case 0x0c0a5f3au: goto P_0c0a5f3a;
case 0x0c0a5f3cu: goto P_0c0a5f3c;
case 0x0c0a5f3eu: goto P_0c0a5f3e;
case 0x0c0a5f40u: goto P_0c0a5f40;
case 0x0c0a5f42u: goto P_0c0a5f42;
case 0x0c0a5f44u: goto P_0c0a5f44;
case 0x0c0a5f46u: goto P_0c0a5f46;
case 0x0c0a5f48u: goto P_0c0a5f48;
case 0x0c0a5f4au: goto P_0c0a5f4a;
case 0x0c0a5f4cu: goto P_0c0a5f4c;
case 0x0c0a5f4eu: goto P_0c0a5f4e;
case 0x0c0a5f50u: goto P_0c0a5f50;
case 0x0c0a6010u: goto P_0c0a6010;
case 0x0c0a6012u: goto P_0c0a6012;
case 0x0c0a6014u: goto P_0c0a6014;
case 0x0c0a6016u: goto P_0c0a6016;
case 0x0c0a6018u: goto P_0c0a6018;
case 0x0c0a601au: goto P_0c0a601a;
case 0x0c0a601cu: goto P_0c0a601c;
case 0x0c0a601eu: goto P_0c0a601e;
case 0x0c0a6020u: goto P_0c0a6020;
case 0x0c0a6022u: goto P_0c0a6022;
case 0x0c0a6024u: goto P_0c0a6024;
case 0x0c0a6026u: goto P_0c0a6026;
case 0x0c0a6028u: goto P_0c0a6028;
case 0x0c0a602au: goto P_0c0a602a;
case 0x0c0a602cu: goto P_0c0a602c;
case 0x0c0a602eu: goto P_0c0a602e;
case 0x0c0a6030u: goto P_0c0a6030;
case 0x0c0a6032u: goto P_0c0a6032;
case 0x0c0a6034u: goto P_0c0a6034;
case 0x0c0a6036u: goto P_0c0a6036;
case 0x0c0a6038u: goto P_0c0a6038;
case 0x0c0a603au: goto P_0c0a603a;
case 0x0c0a603cu: goto P_0c0a603c;
case 0x0c0a603eu: goto P_0c0a603e;
case 0x0c0a6040u: goto P_0c0a6040;
case 0x0c0a6042u: goto P_0c0a6042;
case 0x0c0a6044u: goto P_0c0a6044;
case 0x0c0a6046u: goto P_0c0a6046;
case 0x0c0a6048u: goto P_0c0a6048;
case 0x0c0a604au: goto P_0c0a604a;
case 0x0c0a604cu: goto P_0c0a604c;
case 0x0c0a604eu: goto P_0c0a604e;
case 0x0c0a6050u: goto P_0c0a6050;
case 0x0c0a6052u: goto P_0c0a6052;
case 0x0c0a6054u: goto P_0c0a6054;
case 0x0c0a6056u: goto P_0c0a6056;
case 0x0c0a6058u: goto P_0c0a6058;
case 0x0c0a605au: goto P_0c0a605a;
case 0x0c0a605cu: goto P_0c0a605c;
case 0x0c0a605eu: goto P_0c0a605e;
case 0x0c0a6060u: goto P_0c0a6060;
case 0x0c0a6062u: goto P_0c0a6062;
case 0x0c0a6064u: goto P_0c0a6064;
case 0x0c0a6066u: goto P_0c0a6066;
case 0x0c0a6068u: goto P_0c0a6068;
case 0x0c0a606au: goto P_0c0a606a;
case 0x0c0a606cu: goto P_0c0a606c;
case 0x0c0a606eu: goto P_0c0a606e;
case 0x0c0a6070u: goto P_0c0a6070;
case 0x0c0a6072u: goto P_0c0a6072;
case 0x0c0a6074u: goto P_0c0a6074;
case 0x0c0a6076u: goto P_0c0a6076;
case 0x0c0a6078u: goto P_0c0a6078;
case 0x0c0a607au: goto P_0c0a607a;
case 0x0c0a607cu: goto P_0c0a607c;
case 0x0c0a607eu: goto P_0c0a607e;
case 0x0c0a6080u: goto P_0c0a6080;
case 0x0c0a6082u: goto P_0c0a6082;
case 0x0c0a6084u: goto P_0c0a6084;
case 0x0c0a6086u: goto P_0c0a6086;
case 0x0c0a6088u: goto P_0c0a6088;
case 0x0c0a608au: goto P_0c0a608a;
case 0x0c0a608cu: goto P_0c0a608c;
case 0x0c0a608eu: goto P_0c0a608e;
case 0x0c0a6090u: goto P_0c0a6090;
case 0x0c0a6092u: goto P_0c0a6092;
case 0x0c0a6094u: goto P_0c0a6094;
case 0x0c0a6096u: goto P_0c0a6096;
case 0x0c0a6098u: goto P_0c0a6098;
case 0x0c0a6158u: goto P_0c0a6158;
case 0x0c0a615au: goto P_0c0a615a;
case 0x0c0a615cu: goto P_0c0a615c;
case 0x0c0a615eu: goto P_0c0a615e;
case 0x0c0a6160u: goto P_0c0a6160;
case 0x0c0a6162u: goto P_0c0a6162;
case 0x0c0a6164u: goto P_0c0a6164;
case 0x0c0a6166u: goto P_0c0a6166;
case 0x0c0a6168u: goto P_0c0a6168;
case 0x0c0a616au: goto P_0c0a616a;
case 0x0c0a616cu: goto P_0c0a616c;
case 0x0c0a616eu: goto P_0c0a616e;
case 0x0c0a6170u: goto P_0c0a6170;
case 0x0c0a6172u: goto P_0c0a6172;
case 0x0c0a6174u: goto P_0c0a6174;
case 0x0c0a6176u: goto P_0c0a6176;
case 0x0c0a6178u: goto P_0c0a6178;
case 0x0c0a617au: goto P_0c0a617a;
case 0x0c0a617cu: goto P_0c0a617c;
case 0x0c0a617eu: goto P_0c0a617e;
case 0x0c0a6180u: goto P_0c0a6180;
case 0x0c0a6182u: goto P_0c0a6182;
case 0x0c0a6184u: goto P_0c0a6184;
case 0x0c0a6186u: goto P_0c0a6186;
case 0x0c0a6188u: goto P_0c0a6188;
case 0x0c0a618au: goto P_0c0a618a;
case 0x0c0a618cu: goto P_0c0a618c;
case 0x0c0a618eu: goto P_0c0a618e;
case 0x0c0a6190u: goto P_0c0a6190;
case 0x0c0a6192u: goto P_0c0a6192;
case 0x0c0a6194u: goto P_0c0a6194;
case 0x0c0a6196u: goto P_0c0a6196;
case 0x0c0a6198u: goto P_0c0a6198;
case 0x0c0a619au: goto P_0c0a619a;
case 0x0c0a619cu: goto P_0c0a619c;
case 0x0c0a619eu: goto P_0c0a619e;
case 0x0c0a61a0u: goto P_0c0a61a0;
case 0x0c0a61a2u: goto P_0c0a61a2;
case 0x0c0a61a4u: goto P_0c0a61a4;
case 0x0c0a61a6u: goto P_0c0a61a6;
case 0x0c0a61a8u: goto P_0c0a61a8;
case 0x0c0a61aau: goto P_0c0a61aa;
case 0x0c0a61acu: goto P_0c0a61ac;
case 0x0c0a61aeu: goto P_0c0a61ae;
case 0x0c0a61b0u: goto P_0c0a61b0;
case 0x0c0a61b2u: goto P_0c0a61b2;
case 0x0c0a61b4u: goto P_0c0a61b4;
case 0x0c0a61b6u: goto P_0c0a61b6;
case 0x0c0a61b8u: goto P_0c0a61b8;
case 0x0c0a61bau: goto P_0c0a61ba;
case 0x0c0a61bcu: goto P_0c0a61bc;
case 0x0c0a61beu: goto P_0c0a61be;
case 0x0c0a61c0u: goto P_0c0a61c0;
case 0x0c0a61c2u: goto P_0c0a61c2;
case 0x0c0a61c4u: goto P_0c0a61c4;
case 0x0c0a61c6u: goto P_0c0a61c6;
case 0x0c0a61c8u: goto P_0c0a61c8;
case 0x0c0a61cau: goto P_0c0a61ca;
case 0x0c0a61ccu: goto P_0c0a61cc;
case 0x0c0a61ceu: goto P_0c0a61ce;
case 0x0c0a61d0u: goto P_0c0a61d0;
case 0x0c0a61d2u: goto P_0c0a61d2;
case 0x0c0a61d4u: goto P_0c0a61d4;
case 0x0c0a61d6u: goto P_0c0a61d6;
case 0x0c0a61d8u: goto P_0c0a61d8;
case 0x0c0a61dau: goto P_0c0a61da;
case 0x0c0a61dcu: goto P_0c0a61dc;
case 0x0c0a61deu: goto P_0c0a61de;
case 0x0c0a61e0u: goto P_0c0a61e0;
case 0x0c0a61e2u: goto P_0c0a61e2;
case 0x0c0a61e4u: goto P_0c0a61e4;
case 0x0c0a61e6u: goto P_0c0a61e6;
case 0x0c0a61e8u: goto P_0c0a61e8;
case 0x0c0a61eau: goto P_0c0a61ea;
case 0x0c0a61ecu: goto P_0c0a61ec;
case 0x0c0a61eeu: goto P_0c0a61ee;
case 0x0c0a61f0u: goto P_0c0a61f0;
case 0x0c0a61f2u: goto P_0c0a61f2;
case 0x0c0a61f4u: goto P_0c0a61f4;
case 0x0c0a61f6u: goto P_0c0a61f6;
case 0x0c0a61f8u: goto P_0c0a61f8;
case 0x0c0a62e0u: goto P_0c0a62e0;
case 0x0c0a62e2u: goto P_0c0a62e2;
case 0x0c0a62e4u: goto P_0c0a62e4;
case 0x0c0a62e6u: goto P_0c0a62e6;
case 0x0c0a62e8u: goto P_0c0a62e8;
case 0x0c0a62eau: goto P_0c0a62ea;
case 0x0c0a62ecu: goto P_0c0a62ec;
case 0x0c0a62eeu: goto P_0c0a62ee;
case 0x0c0a62f0u: goto P_0c0a62f0;
case 0x0c0a62f2u: goto P_0c0a62f2;
case 0x0c0a62f4u: goto P_0c0a62f4;
case 0x0c0a62f6u: goto P_0c0a62f6;
case 0x0c0a62f8u: goto P_0c0a62f8;
case 0x0c0a62fau: goto P_0c0a62fa;
case 0x0c0a62fcu: goto P_0c0a62fc;
case 0x0c0a62feu: goto P_0c0a62fe;
case 0x0c0a6300u: goto P_0c0a6300;
case 0x0c0a6302u: goto P_0c0a6302;
case 0x0c0a6304u: goto P_0c0a6304;
case 0x0c0a6306u: goto P_0c0a6306;
case 0x0c0a6308u: goto P_0c0a6308;
case 0x0c0a630au: goto P_0c0a630a;
case 0x0c0a630cu: goto P_0c0a630c;
case 0x0c0a630eu: goto P_0c0a630e;
case 0x0c0a6310u: goto P_0c0a6310;
case 0x0c0a6312u: goto P_0c0a6312;
case 0x0c0a6314u: goto P_0c0a6314;
case 0x0c0a6316u: goto P_0c0a6316;
case 0x0c0a6318u: goto P_0c0a6318;
case 0x0c0a631au: goto P_0c0a631a;
case 0x0c0a631cu: goto P_0c0a631c;
case 0x0c0a631eu: goto P_0c0a631e;
case 0x0c0a6320u: goto P_0c0a6320;
case 0x0c0a6322u: goto P_0c0a6322;
case 0x0c0a6324u: goto P_0c0a6324;
case 0x0c0a6326u: goto P_0c0a6326;
case 0x0c0a6328u: goto P_0c0a6328;
case 0x0c0a632au: goto P_0c0a632a;
case 0x0c0a632cu: goto P_0c0a632c;
case 0x0c0a632eu: goto P_0c0a632e;
case 0x0c0a6330u: goto P_0c0a6330;
case 0x0c0a6332u: goto P_0c0a6332;
case 0x0c0a6334u: goto P_0c0a6334;
case 0x0c0a6336u: goto P_0c0a6336;
case 0x0c0a6338u: goto P_0c0a6338;
case 0x0c0a633au: goto P_0c0a633a;
case 0x0c0a633cu: goto P_0c0a633c;
case 0x0c0a633eu: goto P_0c0a633e;
case 0x0c0a6340u: goto P_0c0a6340;
case 0x0c0a6342u: goto P_0c0a6342;
case 0x0c0a6344u: goto P_0c0a6344;
case 0x0c0a6346u: goto P_0c0a6346;
case 0x0c0a6348u: goto P_0c0a6348;
case 0x0c0a634au: goto P_0c0a634a;
case 0x0c0a634cu: goto P_0c0a634c;
case 0x0c0a634eu: goto P_0c0a634e;
case 0x0c0a6350u: goto P_0c0a6350;
case 0x0c0a6352u: goto P_0c0a6352;
case 0x0c0a6354u: goto P_0c0a6354;
case 0x0c0a6356u: goto P_0c0a6356;
case 0x0c0a6358u: goto P_0c0a6358;
case 0x0c0a635au: goto P_0c0a635a;
case 0x0c0a635cu: goto P_0c0a635c;
case 0x0c0a635eu: goto P_0c0a635e;
case 0x0c0a6360u: goto P_0c0a6360;
case 0x0c0a6362u: goto P_0c0a6362;
case 0x0c0a6364u: goto P_0c0a6364;
case 0x0c0a6366u: goto P_0c0a6366;
case 0x0c0a6368u: goto P_0c0a6368;
case 0x0c0a636au: goto P_0c0a636a;
case 0x0c0a636cu: goto P_0c0a636c;
case 0x0c0a636eu: goto P_0c0a636e;
case 0x0c0a6370u: goto P_0c0a6370;
case 0x0c0a6372u: goto P_0c0a6372;
case 0x0c0a6374u: goto P_0c0a6374;
case 0x0c0a6376u: goto P_0c0a6376;
case 0x0c0a6378u: goto P_0c0a6378;
case 0x0c0a637au: goto P_0c0a637a;
case 0x0c0a637cu: goto P_0c0a637c;
case 0x0c0a637eu: goto P_0c0a637e;
case 0x0c0a6380u: goto P_0c0a6380;
case 0x0c0a6382u: goto P_0c0a6382;
case 0x0c0a6384u: goto P_0c0a6384;
case 0x0c0a6386u: goto P_0c0a6386;
case 0x0c0a6388u: goto P_0c0a6388;
case 0x0c0beaf8u: goto P_0c0beaf8;
case 0x0c0beafau: goto P_0c0beafa;
case 0x0c0beafcu: goto P_0c0beafc;
case 0x0c0beafeu: goto P_0c0beafe;
case 0x0c0beb00u: goto P_0c0beb00;
case 0x0c0beb02u: goto P_0c0beb02;
case 0x0c0beb04u: goto P_0c0beb04;
case 0x0c0beb06u: goto P_0c0beb06;
case 0x0c0beb08u: goto P_0c0beb08;
case 0x0c0beb0au: goto P_0c0beb0a;
case 0x0c0beb0cu: goto P_0c0beb0c;
case 0x0c0beb0eu: goto P_0c0beb0e;
case 0x0c0beb10u: goto P_0c0beb10;
case 0x0c0beb12u: goto P_0c0beb12;
case 0x0c0beb14u: goto P_0c0beb14;
case 0x0c0beb16u: goto P_0c0beb16;
case 0x0c0beb18u: goto P_0c0beb18;
case 0x0c0beb1au: goto P_0c0beb1a;
case 0x0c0beb1cu: goto P_0c0beb1c;
case 0x0c0beb1eu: goto P_0c0beb1e;
case 0x0c0beb20u: goto P_0c0beb20;
case 0x0c0beb22u: goto P_0c0beb22;
case 0x0c0beb24u: goto P_0c0beb24;
case 0x0c0beb26u: goto P_0c0beb26;
case 0x0c0beb28u: goto P_0c0beb28;
case 0x0c0beb2au: goto P_0c0beb2a;
case 0x0c0beb2cu: goto P_0c0beb2c;
case 0x0c0beb2eu: goto P_0c0beb2e;
case 0x0c0beb30u: goto P_0c0beb30;
case 0x0c0beb32u: goto P_0c0beb32;
case 0x0c0beb34u: goto P_0c0beb34;
case 0x0c0beb36u: goto P_0c0beb36;
case 0x0c0beb38u: goto P_0c0beb38;
case 0x0c0beb3au: goto P_0c0beb3a;
case 0x0c0beb3cu: goto P_0c0beb3c;
case 0x0c0beb3eu: goto P_0c0beb3e;
case 0x0c0beb40u: goto P_0c0beb40;
case 0x0c0beb42u: goto P_0c0beb42;
case 0x0c0beb44u: goto P_0c0beb44;
case 0x0c0beb46u: goto P_0c0beb46;
case 0x0c0beb48u: goto P_0c0beb48;
case 0x0c0beb4au: goto P_0c0beb4a;
case 0x0c0beb4cu: goto P_0c0beb4c;
case 0x0c0beb4eu: goto P_0c0beb4e;
case 0x0c0beb50u: goto P_0c0beb50;
case 0x0c0beb52u: goto P_0c0beb52;
case 0x0c0beb54u: goto P_0c0beb54;
case 0x0c0beb56u: goto P_0c0beb56;
case 0x0c0beb58u: goto P_0c0beb58;
case 0x0c0beb5au: goto P_0c0beb5a;
case 0x0c0beb5cu: goto P_0c0beb5c;
case 0x0c0beb5eu: goto P_0c0beb5e;
case 0x0c0beb60u: goto P_0c0beb60;
case 0x0c0beb62u: goto P_0c0beb62;
case 0x0c0beb64u: goto P_0c0beb64;
case 0x0c0beb66u: goto P_0c0beb66;
case 0x0c0beb68u: goto P_0c0beb68;
case 0x0c0beb6au: goto P_0c0beb6a;
case 0x0c0beb6cu: goto P_0c0beb6c;
case 0x0c0beb6eu: goto P_0c0beb6e;
case 0x0c0beb70u: goto P_0c0beb70;
case 0x0c0beb72u: goto P_0c0beb72;
case 0x0c0beb74u: goto P_0c0beb74;
case 0x0c0beb76u: goto P_0c0beb76;
case 0x0c0beb78u: goto P_0c0beb78;
case 0x0c0beb7au: goto P_0c0beb7a;
case 0x0c0beb7cu: goto P_0c0beb7c;
case 0x0c0beb7eu: goto P_0c0beb7e;
case 0x0c0beb80u: goto P_0c0beb80;
case 0x0c0beb82u: goto P_0c0beb82;
case 0x0c0beb84u: goto P_0c0beb84;
case 0x0c0beb86u: goto P_0c0beb86;
case 0x0c0beb88u: goto P_0c0beb88;
case 0x0c0beb8au: goto P_0c0beb8a;
case 0x0c0beb8cu: goto P_0c0beb8c;
case 0x0c0beb8eu: goto P_0c0beb8e;
case 0x0c0beb90u: goto P_0c0beb90;
case 0x0c0beb92u: goto P_0c0beb92;
case 0x0c0beb94u: goto P_0c0beb94;
case 0x0c0beb96u: goto P_0c0beb96;
case 0x0c0beb98u: goto P_0c0beb98;
case 0x0c0beb9au: goto P_0c0beb9a;
case 0x0c0beb9cu: goto P_0c0beb9c;
case 0x0c0beb9eu: goto P_0c0beb9e;
case 0x0c0beba0u: goto P_0c0beba0;
case 0x0c0beba2u: goto P_0c0beba2;
case 0x0c0beba4u: goto P_0c0beba4;
case 0x0c0beba6u: goto P_0c0beba6;
case 0x0c0beba8u: goto P_0c0beba8;
case 0x0c0bebaau: goto P_0c0bebaa;
case 0x0c0bebacu: goto P_0c0bebac;
case 0x0c0bebaeu: goto P_0c0bebae;
case 0x0c0bebb0u: goto P_0c0bebb0;
case 0x0c0bebb2u: goto P_0c0bebb2;
case 0x0c0bebb4u: goto P_0c0bebb4;
case 0x0c0bebb6u: goto P_0c0bebb6;
case 0x0c0bebb8u: goto P_0c0bebb8;
case 0x0c0bebbau: goto P_0c0bebba;
case 0x0c0bebbcu: goto P_0c0bebbc;
case 0x0c0bebbeu: goto P_0c0bebbe;
case 0x0c0bebc0u: goto P_0c0bebc0;
case 0x0c0bebc2u: goto P_0c0bebc2;
case 0x0c0bebc4u: goto P_0c0bebc4;
case 0x0c0bebc6u: goto P_0c0bebc6;
case 0x0c0bebc8u: goto P_0c0bebc8;
case 0x0c0bebcau: goto P_0c0bebca;
case 0x0c0bebccu: goto P_0c0bebcc;
case 0x0c0bebceu: goto P_0c0bebce;
case 0x0c0bebd0u: goto P_0c0bebd0;
case 0x0c0bebd2u: goto P_0c0bebd2;
case 0x0c0bebd4u: goto P_0c0bebd4;
case 0x0c0bebd6u: goto P_0c0bebd6;
case 0x0c0bebd8u: goto P_0c0bebd8;
case 0x0c0bebdau: goto P_0c0bebda;
case 0x0c0bebdcu: goto P_0c0bebdc;
case 0x0c0bebdeu: goto P_0c0bebde;
case 0x0c0bebe0u: goto P_0c0bebe0;
case 0x0c0bebe2u: goto P_0c0bebe2;
case 0x0c0bebe4u: goto P_0c0bebe4;
case 0x0c0c1192u: goto P_0c0c1192;
case 0x0c0c1194u: goto P_0c0c1194;
case 0x0c0c1196u: goto P_0c0c1196;
case 0x0c0c1198u: goto P_0c0c1198;
case 0x0c0c119au: goto P_0c0c119a;
case 0x0c0c119cu: goto P_0c0c119c;
case 0x0c0c119eu: goto P_0c0c119e;
case 0x0c0c11a0u: goto P_0c0c11a0;
case 0x0c0c11a2u: goto P_0c0c11a2;
case 0x0c0c11a4u: goto P_0c0c11a4;
case 0x0c0c11a6u: goto P_0c0c11a6;
case 0x0c0c11a8u: goto P_0c0c11a8;
case 0x0c0c11aau: goto P_0c0c11aa;
case 0x0c0c11acu: goto P_0c0c11ac;
case 0x0c0c11aeu: goto P_0c0c11ae;
case 0x0c0c11b0u: goto P_0c0c11b0;
case 0x0c0c11b2u: goto P_0c0c11b2;
case 0x0c0c11b4u: goto P_0c0c11b4;
case 0x0c0c11b6u: goto P_0c0c11b6;
case 0x0c0c11b8u: goto P_0c0c11b8;
case 0x0c0c11bau: goto P_0c0c11ba;
case 0x0c0c11bcu: goto P_0c0c11bc;
case 0x0c0c11beu: goto P_0c0c11be;
case 0x0c0c11c0u: goto P_0c0c11c0;
case 0x0c0c11c2u: goto P_0c0c11c2;
case 0x0c0c11c4u: goto P_0c0c11c4;
case 0x0c0c11c6u: goto P_0c0c11c6;
case 0x0c0c11c8u: goto P_0c0c11c8;
case 0x0c0c11cau: goto P_0c0c11ca;
case 0x0c0c11ccu: goto P_0c0c11cc;
case 0x0c0ca078u: goto P_0c0ca078;
case 0x0c0ca07au: goto P_0c0ca07a;
case 0x0c0ca07cu: goto P_0c0ca07c;
case 0x0c0ca07eu: goto P_0c0ca07e;
case 0x0c0ca080u: goto P_0c0ca080;
case 0x0c0ca082u: goto P_0c0ca082;
case 0x0c0ca084u: goto P_0c0ca084;
case 0x0c0ca086u: goto P_0c0ca086;
case 0x0c0ca088u: goto P_0c0ca088;
case 0x0c0ca08au: goto P_0c0ca08a;
case 0x0c0ca08cu: goto P_0c0ca08c;
case 0x0c0ca08eu: goto P_0c0ca08e;
case 0x0c0ca090u: goto P_0c0ca090;
case 0x0c0ca092u: goto P_0c0ca092;
case 0x0c0ca094u: goto P_0c0ca094;
case 0x0c0ca096u: goto P_0c0ca096;
case 0x0c0ca098u: goto P_0c0ca098;
case 0x0c0ca09au: goto P_0c0ca09a;
case 0x0c0ca09cu: goto P_0c0ca09c;
case 0x0c0ca09eu: goto P_0c0ca09e;
case 0x0c0ca0a0u: goto P_0c0ca0a0;
case 0x0c0ca0a2u: goto P_0c0ca0a2;
case 0x0c0ca0a4u: goto P_0c0ca0a4;
case 0x0c0ca0a6u: goto P_0c0ca0a6;
case 0x0c0ca0a8u: goto P_0c0ca0a8;
case 0x0c0ca0aau: goto P_0c0ca0aa;
case 0x0c0ca0acu: goto P_0c0ca0ac;
case 0x0c0ca0aeu: goto P_0c0ca0ae;
case 0x0c0ca0b0u: goto P_0c0ca0b0;
case 0x0c0ca0b2u: goto P_0c0ca0b2;
case 0x0c0ca0b4u: goto P_0c0ca0b4;
case 0x0c0ca0b6u: goto P_0c0ca0b6;
case 0x0c0ca0b8u: goto P_0c0ca0b8;
case 0x0c0ca0bau: goto P_0c0ca0ba;
default: return vf3_matrix_family(target,s,ram);
}
P_0c06cf30: /* original 4f22, guest PC 0x0c06cf30 */
if(!s->budget--) { s->failed_pc=0x0c06cf30u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c06cf32;
P_0c06cf32: /* original fe57, guest PC 0x0c06cf32 */
if(!s->budget--) { s->failed_pc=0x0c06cf32u; return 0; }
vf3_matrix_store(s,ram,5,r[14]+r[0]);
goto P_0c06cf34;
P_0c06cf34: /* original 700c, guest PC 0x0c06cf34 */
if(!s->budget--) { s->failed_pc=0x0c06cf34u; return 0; }
r[0]+=0x0000000cu;
goto P_0c06cf36;
P_0c06cf36: /* original fe57, guest PC 0x0c06cf36 */
if(!s->budget--) { s->failed_pc=0x0c06cf36u; return 0; }
vf3_matrix_store(s,ram,5,r[14]+r[0]);
goto P_0c06cf38;
P_0c06cf38: /* original 7004, guest PC 0x0c06cf38 */
if(!s->budget--) { s->failed_pc=0x0c06cf38u; return 0; }
r[0]+=0x00000004u;
goto P_0c06cf3a;
P_0c06cf3a: /* original fe57, guest PC 0x0c06cf3a */
if(!s->budget--) { s->failed_pc=0x0c06cf3au; return 0; }
vf3_matrix_store(s,ram,5,r[14]+r[0]);
goto P_0c06cf3c;
P_0c06cf3c: /* original 7004, guest PC 0x0c06cf3c */
if(!s->budget--) { s->failed_pc=0x0c06cf3cu; return 0; }
r[0]+=0x00000004u;
goto P_0c06cf3e;
P_0c06cf3e: /* original fe57, guest PC 0x0c06cf3e */
if(!s->budget--) { s->failed_pc=0x0c06cf3eu; return 0; }
vf3_matrix_store(s,ram,5,r[14]+r[0]);
goto P_0c06cf40;
P_0c06cf40: /* original 7004, guest PC 0x0c06cf40 */
if(!s->budget--) { s->failed_pc=0x0c06cf40u; return 0; }
r[0]+=0x00000004u;
goto P_0c06cf42;
P_0c06cf42: /* original fe57, guest PC 0x0c06cf42 */
if(!s->budget--) { s->failed_pc=0x0c06cf42u; return 0; }
vf3_matrix_store(s,ram,5,r[14]+r[0]);
goto P_0c06cf44;
P_0c06cf44: /* original 7004, guest PC 0x0c06cf44 */
if(!s->budget--) { s->failed_pc=0x0c06cf44u; return 0; }
r[0]+=0x00000004u;
goto P_0c06cf46;
P_0c06cf46: /* original fe57, guest PC 0x0c06cf46 */
if(!s->budget--) { s->failed_pc=0x0c06cf46u; return 0; }
vf3_matrix_store(s,ram,5,r[14]+r[0]);
goto P_0c06cf48;
P_0c06cf48: /* original e014, guest PC 0x0c06cf48 */
if(!s->budget--) { s->failed_pc=0x0c06cf48u; return 0; }
r[0]=0x00000014u;
goto P_0c06cf4a;
P_0c06cf4a: /* original f59d, guest PC 0x0c06cf4a */
if(!s->budget--) { s->failed_pc=0x0c06cf4au; return 0; }
fr[5]=0x3f800000u;
goto P_0c06cf4c;
P_0c06cf4c: /* original fe57, guest PC 0x0c06cf4c */
if(!s->budget--) { s->failed_pc=0x0c06cf4cu; return 0; }
vf3_matrix_store(s,ram,5,r[14]+r[0]);
goto P_0c06cf4e;
P_0c06cf4e: /* original 906f, guest PC 0x0c06cf4e */
if(!s->budget--) { s->failed_pc=0x0c06cf4eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06d030u,2);
goto P_0c06cf50;
P_0c06cf50: /* original fe57, guest PC 0x0c06cf50 */
if(!s->budget--) { s->failed_pc=0x0c06cf50u; return 0; }
vf3_matrix_store(s,ram,5,r[14]+r[0]);
goto P_0c06cf52;
P_0c06cf52: /* original c73e, guest PC 0x0c06cf52 */
if(!s->budget--) { s->failed_pc=0x0c06cf52u; return 0; }
r[0]=0x0c06d04cu;
goto P_0c06cf54;
P_0c06cf54: /* original f508, guest PC 0x0c06cf54 */
if(!s->budget--) { s->failed_pc=0x0c06cf54u; return 0; }
vf3_matrix_load(s,ram,5,r[0]);
goto P_0c06cf56;
P_0c06cf56: /* original e018, guest PC 0x0c06cf56 */
if(!s->budget--) { s->failed_pc=0x0c06cf56u; return 0; }
r[0]=0x00000018u;
goto P_0c06cf58;
P_0c06cf58: /* original fe57, guest PC 0x0c06cf58 */
if(!s->budget--) { s->failed_pc=0x0c06cf58u; return 0; }
vf3_matrix_store(s,ram,5,r[14]+r[0]);
goto P_0c06cf5a;
P_0c06cf5a: /* original 906a, guest PC 0x0c06cf5a */
if(!s->budget--) { s->failed_pc=0x0c06cf5au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06d032u,2);
goto P_0c06cf5c;
P_0c06cf5c: /* original fe57, guest PC 0x0c06cf5c */
if(!s->budget--) { s->failed_pc=0x0c06cf5cu; return 0; }
vf3_matrix_store(s,ram,5,r[14]+r[0]);
goto P_0c06cf5e;
P_0c06cf5e: /* original 6043, guest PC 0x0c06cf5e */
if(!s->budget--) { s->failed_pc=0x0c06cf5eu; return 0; }
r[0]=r[4];
goto P_0c06cf60;
P_0c06cf60: /* original 81ee, guest PC 0x0c06cf60 */
if(!s->budget--) { s->failed_pc=0x0c06cf60u; return 0; }
write(ram,r[14]+28,r[0],2);
goto P_0c06cf62;
P_0c06cf62: /* original e314, guest PC 0x0c06cf62 */
if(!s->budget--) { s->failed_pc=0x0c06cf62u; return 0; }
r[3]=0x00000014u;
goto P_0c06cf64;
P_0c06cf64: /* original 81ef, guest PC 0x0c06cf64 */
if(!s->budget--) { s->failed_pc=0x0c06cf64u; return 0; }
write(ram,r[14]+30,r[0],2);
goto P_0c06cf66;
P_0c06cf66: /* original 9065, guest PC 0x0c06cf66 */
if(!s->budget--) { s->failed_pc=0x0c06cf66u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06d034u,2);
goto P_0c06cf68;
P_0c06cf68: /* original 0e44, guest PC 0x0c06cf68 */
if(!s->budget--) { s->failed_pc=0x0c06cf68u; return 0; }
write(ram,r[14]+r[0],r[4],1);
goto P_0c06cf6a;
P_0c06cf6a: /* original 9064, guest PC 0x0c06cf6a */
if(!s->budget--) { s->failed_pc=0x0c06cf6au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06d036u,2);
goto P_0c06cf6c;
P_0c06cf6c: /* original 0e34, guest PC 0x0c06cf6c */
if(!s->budget--) { s->failed_pc=0x0c06cf6cu; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c06cf6e;
P_0c06cf6e: /* original e020, guest PC 0x0c06cf6e */
if(!s->budget--) { s->failed_pc=0x0c06cf6eu; return 0; }
r[0]=0x00000020u;
goto P_0c06cf70;
P_0c06cf70: /* original 9362, guest PC 0x0c06cf70 */
if(!s->budget--) { s->failed_pc=0x0c06cf70u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06d038u,2);
goto P_0c06cf72;
P_0c06cf72: /* original d437, guest PC 0x0c06cf72 */
if(!s->budget--) { s->failed_pc=0x0c06cf72u; return 0; }
r[4]=read(ram,0x0c06d050u,4);
goto P_0c06cf74;
P_0c06cf74: /* original 0435, guest PC 0x0c06cf74 */
if(!s->budget--) { s->failed_pc=0x0c06cf74u; return 0; }
write(ram,r[4]+r[0],r[3],2);
goto P_0c06cf76;
P_0c06cf76: /* original e022, guest PC 0x0c06cf76 */
if(!s->budget--) { s->failed_pc=0x0c06cf76u; return 0; }
r[0]=0x00000022u;
goto P_0c06cf78;
P_0c06cf78: /* original 925f, guest PC 0x0c06cf78 */
if(!s->budget--) { s->failed_pc=0x0c06cf78u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06d03au,2);
goto P_0c06cf7a;
P_0c06cf7a: /* original 0425, guest PC 0x0c06cf7a */
if(!s->budget--) { s->failed_pc=0x0c06cf7au; return 0; }
write(ram,r[4]+r[0],r[2],2);
goto P_0c06cf7c;
P_0c06cf7c: /* original c735, guest PC 0x0c06cf7c */
if(!s->budget--) { s->failed_pc=0x0c06cf7cu; return 0; }
r[0]=0x0c06d054u;
goto P_0c06cf7e;
P_0c06cf7e: /* original f508, guest PC 0x0c06cf7e */
if(!s->budget--) { s->failed_pc=0x0c06cf7eu; return 0; }
vf3_matrix_load(s,ram,5,r[0]);
goto P_0c06cf80;
P_0c06cf80: /* original 905c, guest PC 0x0c06cf80 */
if(!s->budget--) { s->failed_pc=0x0c06cf80u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06d03cu,2);
goto P_0c06cf82;
P_0c06cf82: /* original fe57, guest PC 0x0c06cf82 */
if(!s->budget--) { s->failed_pc=0x0c06cf82u; return 0; }
vf3_matrix_store(s,ram,5,r[14]+r[0]);
goto P_0c06cf84;
P_0c06cf84: /* original 7004, guest PC 0x0c06cf84 */
if(!s->budget--) { s->failed_pc=0x0c06cf84u; return 0; }
r[0]+=0x00000004u;
goto P_0c06cf86;
P_0c06cf86: /* original fe57, guest PC 0x0c06cf86 */
if(!s->budget--) { s->failed_pc=0x0c06cf86u; return 0; }
vf3_matrix_store(s,ram,5,r[14]+r[0]);
goto P_0c06cf88;
P_0c06cf88: /* original 7004, guest PC 0x0c06cf88 */
if(!s->budget--) { s->failed_pc=0x0c06cf88u; return 0; }
r[0]+=0x00000004u;
goto P_0c06cf8a;
P_0c06cf8a: /* original fe57, guest PC 0x0c06cf8a */
if(!s->budget--) { s->failed_pc=0x0c06cf8au; return 0; }
vf3_matrix_store(s,ram,5,r[14]+r[0]);
goto P_0c06cf8c;
P_0c06cf8c: /* original 9057, guest PC 0x0c06cf8c */
if(!s->budget--) { s->failed_pc=0x0c06cf8cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06d03eu,2);
goto P_0c06cf8e;
P_0c06cf8e: /* original fe47, guest PC 0x0c06cf8e */
if(!s->budget--) { s->failed_pc=0x0c06cf8eu; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c06cf90;
P_0c06cf90: /* original 7004, guest PC 0x0c06cf90 */
if(!s->budget--) { s->failed_pc=0x0c06cf90u; return 0; }
r[0]+=0x00000004u;
goto P_0c06cf92;
P_0c06cf92: /* original fe47, guest PC 0x0c06cf92 */
if(!s->budget--) { s->failed_pc=0x0c06cf92u; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c06cf94;
P_0c06cf94: /* original 9054, guest PC 0x0c06cf94 */
if(!s->budget--) { s->failed_pc=0x0c06cf94u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06d040u,2);
goto P_0c06cf96;
P_0c06cf96: /* original fe47, guest PC 0x0c06cf96 */
if(!s->budget--) { s->failed_pc=0x0c06cf96u; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c06cf98;
P_0c06cf98: /* original c72f, guest PC 0x0c06cf98 */
if(!s->budget--) { s->failed_pc=0x0c06cf98u; return 0; }
r[0]=0x0c06d058u;
goto P_0c06cf9a;
P_0c06cf9a: /* original f408, guest PC 0x0c06cf9a */
if(!s->budget--) { s->failed_pc=0x0c06cf9au; return 0; }
vf3_matrix_load(s,ram,4,r[0]);
goto P_0c06cf9c;
P_0c06cf9c: /* original 9051, guest PC 0x0c06cf9c */
if(!s->budget--) { s->failed_pc=0x0c06cf9cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06d042u,2);
goto P_0c06cf9e;
P_0c06cf9e: /* original fe47, guest PC 0x0c06cf9e */
if(!s->budget--) { s->failed_pc=0x0c06cf9eu; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c06cfa0;
P_0c06cfa0: /* original b518, guest PC 0x0c06cfa0 */
if(!s->budget--) { s->failed_pc=0x0c06cfa0u; return 0; }
target=0x0c06d9d4u; r[16]=0x0c06cfa4u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c06cfa4u) { target=s->pc; goto dispatch; }
goto P_0c06cfa4;
P_0c06cfa2: /* original 64e3, guest PC 0x0c06cfa2 */
if(!s->budget--) { s->failed_pc=0x0c06cfa2u; return 0; }
r[4]=r[14];
goto P_0c06cfa4;
P_0c06cfa4: /* original d22d, guest PC 0x0c06cfa4 */
if(!s->budget--) { s->failed_pc=0x0c06cfa4u; return 0; }
r[2]=read(ram,0x0c06d05cu,4);
goto P_0c06cfa6;
P_0c06cfa6: /* original 420b, guest PC 0x0c06cfa6 */
if(!s->budget--) { s->failed_pc=0x0c06cfa6u; return 0; }
target=r[2];
r[16]=0x0c06cfaau;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c06cfaau) { target=s->pc; goto dispatch; }
goto P_0c06cfaa;
P_0c06cfa8: /* original 0009, guest PC 0x0c06cfa8 */
if(!s->budget--) { s->failed_pc=0x0c06cfa8u; return 0; }
goto P_0c06cfaa;
P_0c06cfaa: /* original 4f26, guest PC 0x0c06cfaa */
if(!s->budget--) { s->failed_pc=0x0c06cfaau; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c06cfac;
P_0c06cfac: /* original d32c, guest PC 0x0c06cfac */
if(!s->budget--) { s->failed_pc=0x0c06cfacu; return 0; }
r[3]=read(ram,0x0c06d060u,4);
goto P_0c06cfae;
P_0c06cfae: /* original 64e3, guest PC 0x0c06cfae */
if(!s->budget--) { s->failed_pc=0x0c06cfaeu; return 0; }
r[4]=r[14];
goto P_0c06cfb0;
P_0c06cfb0: /* original 1e33, guest PC 0x0c06cfb0 */
if(!s->budget--) { s->failed_pc=0x0c06cfb0u; return 0; }
write(ram,r[14]+12,r[3],4);
goto P_0c06cfb2;
P_0c06cfb2: /* original 6233, guest PC 0x0c06cfb2 */
if(!s->budget--) { s->failed_pc=0x0c06cfb2u; return 0; }
r[2]=r[3];
goto P_0c06cfb4;
P_0c06cfb4: /* original 422b, guest PC 0x0c06cfb4 */
if(!s->budget--) { s->failed_pc=0x0c06cfb4u; return 0; }
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
P_0c06cfb6: /* original 6ef6, guest PC 0x0c06cfb6 */
if(!s->budget--) { s->failed_pc=0x0c06cfb6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c06cfb8;
P_0c06cfb8: /* original 2fe6, guest PC 0x0c06cfb8 */
if(!s->budget--) { s->failed_pc=0x0c06cfb8u; return 0; }
r[15]-=4; write(ram,r[15],r[14],4);
goto P_0c06cfba;
P_0c06cfba: /* original 2fd6, guest PC 0x0c06cfba */
if(!s->budget--) { s->failed_pc=0x0c06cfbau; return 0; }
r[15]-=4; write(ram,r[15],r[13],4);
goto P_0c06cfbc;
P_0c06cfbc: /* original 2fc6, guest PC 0x0c06cfbc */
if(!s->budget--) { s->failed_pc=0x0c06cfbcu; return 0; }
r[15]-=4; write(ram,r[15],r[12],4);
goto P_0c06cfbe;
P_0c06cfbe: /* original 2fb6, guest PC 0x0c06cfbe */
if(!s->budget--) { s->failed_pc=0x0c06cfbeu; return 0; }
r[15]-=4; write(ram,r[15],r[11],4);
goto P_0c06cfc0;
P_0c06cfc0: /* original 6b43, guest PC 0x0c06cfc0 */
if(!s->budget--) { s->failed_pc=0x0c06cfc0u; return 0; }
r[11]=r[4];
goto P_0c06cfc2;
P_0c06cfc2: /* original 2fa6, guest PC 0x0c06cfc2 */
if(!s->budget--) { s->failed_pc=0x0c06cfc2u; return 0; }
r[15]-=4; write(ram,r[15],r[10],4);
goto P_0c06cfc4;
P_0c06cfc4: /* original 2f96, guest PC 0x0c06cfc4 */
if(!s->budget--) { s->failed_pc=0x0c06cfc4u; return 0; }
r[15]-=4; write(ram,r[15],r[9],4);
goto P_0c06cfc6;
P_0c06cfc6: /* original 2f86, guest PC 0x0c06cfc6 */
if(!s->budget--) { s->failed_pc=0x0c06cfc6u; return 0; }
r[15]-=4; write(ram,r[15],r[8],4);
goto P_0c06cfc8;
P_0c06cfc8: /* original fffb, guest PC 0x0c06cfc8 */
if(!s->budget--) { s->failed_pc=0x0c06cfc8u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c06cfca;
P_0c06cfca: /* original ffeb, guest PC 0x0c06cfca */
if(!s->budget--) { s->failed_pc=0x0c06cfcau; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,14,r[15]);
goto P_0c06cfcc;
P_0c06cfcc: /* original ffdb, guest PC 0x0c06cfcc */
if(!s->budget--) { s->failed_pc=0x0c06cfccu; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,13,r[15]);
goto P_0c06cfce;
P_0c06cfce: /* original ffcb, guest PC 0x0c06cfce */
if(!s->budget--) { s->failed_pc=0x0c06cfceu; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,12,r[15]);
return vf3_matrix_family(0x0c06cfd0u,s,ram);
P_0c072e2c: /* original 4f22, guest PC 0x0c072e2c */
if(!s->budget--) { s->failed_pc=0x0c072e2cu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c072e2e;
P_0c072e2e: /* original dd56, guest PC 0x0c072e2e */
if(!s->budget--) { s->failed_pc=0x0c072e2eu; return 0; }
r[13]=read(ram,0x0c072f88u,4);
goto P_0c072e30;
P_0c072e30: /* original 64e3, guest PC 0x0c072e30 */
if(!s->budget--) { s->failed_pc=0x0c072e30u; return 0; }
r[4]=r[14];
goto P_0c072e32;
P_0c072e32: /* original 4d0b, guest PC 0x0c072e32 */
if(!s->budget--) { s->failed_pc=0x0c072e32u; return 0; }
target=r[13];
r[16]=0x0c072e36u;
r[4]+=0x00000017u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c072e36u) { target=s->pc; goto dispatch; }
goto P_0c072e36;
P_0c072e34: /* original 7417, guest PC 0x0c072e34 */
if(!s->budget--) { s->failed_pc=0x0c072e34u; return 0; }
r[4]+=0x00000017u;
goto P_0c072e36;
P_0c072e36: /* original 64e3, guest PC 0x0c072e36 */
if(!s->budget--) { s->failed_pc=0x0c072e36u; return 0; }
r[4]=r[14];
goto P_0c072e38;
P_0c072e38: /* original e502, guest PC 0x0c072e38 */
if(!s->budget--) { s->failed_pc=0x0c072e38u; return 0; }
r[5]=0x00000002u;
goto P_0c072e3a;
P_0c072e3a: /* original 4d0b, guest PC 0x0c072e3a */
if(!s->budget--) { s->failed_pc=0x0c072e3au; return 0; }
target=r[13];
r[16]=0x0c072e3eu;
r[4]+=0x00000018u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c072e3eu) { target=s->pc; goto dispatch; }
goto P_0c072e3e;
P_0c072e3c: /* original 7418, guest PC 0x0c072e3c */
if(!s->budget--) { s->failed_pc=0x0c072e3cu; return 0; }
r[4]+=0x00000018u;
goto P_0c072e3e;
P_0c072e3e: /* original 64e3, guest PC 0x0c072e3e */
if(!s->budget--) { s->failed_pc=0x0c072e3eu; return 0; }
r[4]=r[14];
goto P_0c072e40;
P_0c072e40: /* original e502, guest PC 0x0c072e40 */
if(!s->budget--) { s->failed_pc=0x0c072e40u; return 0; }
r[5]=0x00000002u;
goto P_0c072e42;
P_0c072e42: /* original 4d0b, guest PC 0x0c072e42 */
if(!s->budget--) { s->failed_pc=0x0c072e42u; return 0; }
target=r[13];
r[16]=0x0c072e46u;
r[4]+=0x0000001au;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c072e46u) { target=s->pc; goto dispatch; }
goto P_0c072e46;
P_0c072e44: /* original 741a, guest PC 0x0c072e44 */
if(!s->budget--) { s->failed_pc=0x0c072e44u; return 0; }
r[4]+=0x0000001au;
goto P_0c072e46;
P_0c072e46: /* original 64e3, guest PC 0x0c072e46 */
if(!s->budget--) { s->failed_pc=0x0c072e46u; return 0; }
r[4]=r[14];
goto P_0c072e48;
P_0c072e48: /* original e502, guest PC 0x0c072e48 */
if(!s->budget--) { s->failed_pc=0x0c072e48u; return 0; }
r[5]=0x00000002u;
goto P_0c072e4a;
P_0c072e4a: /* original 4d0b, guest PC 0x0c072e4a */
if(!s->budget--) { s->failed_pc=0x0c072e4au; return 0; }
target=r[13];
r[16]=0x0c072e4eu;
r[4]+=0x00000019u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c072e4eu) { target=s->pc; goto dispatch; }
goto P_0c072e4e;
P_0c072e4c: /* original 7419, guest PC 0x0c072e4c */
if(!s->budget--) { s->failed_pc=0x0c072e4cu; return 0; }
r[4]+=0x00000019u;
goto P_0c072e4e;
P_0c072e4e: /* original 64e3, guest PC 0x0c072e4e */
if(!s->budget--) { s->failed_pc=0x0c072e4eu; return 0; }
r[4]=r[14];
goto P_0c072e50;
P_0c072e50: /* original e502, guest PC 0x0c072e50 */
if(!s->budget--) { s->failed_pc=0x0c072e50u; return 0; }
r[5]=0x00000002u;
goto P_0c072e52;
P_0c072e52: /* original 4d0b, guest PC 0x0c072e52 */
if(!s->budget--) { s->failed_pc=0x0c072e52u; return 0; }
target=r[13];
r[16]=0x0c072e56u;
r[4]+=0x0000001bu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c072e56u) { target=s->pc; goto dispatch; }
goto P_0c072e56;
P_0c072e54: /* original 741b, guest PC 0x0c072e54 */
if(!s->budget--) { s->failed_pc=0x0c072e54u; return 0; }
r[4]+=0x0000001bu;
goto P_0c072e56;
P_0c072e56: /* original 64e3, guest PC 0x0c072e56 */
if(!s->budget--) { s->failed_pc=0x0c072e56u; return 0; }
r[4]=r[14];
goto P_0c072e58;
P_0c072e58: /* original e500, guest PC 0x0c072e58 */
if(!s->budget--) { s->failed_pc=0x0c072e58u; return 0; }
r[5]=0x00000000u;
goto P_0c072e5a;
P_0c072e5a: /* original 4d0b, guest PC 0x0c072e5a */
if(!s->budget--) { s->failed_pc=0x0c072e5au; return 0; }
target=r[13];
r[16]=0x0c072e5eu;
r[4]+=0x0000001cu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c072e5eu) { target=s->pc; goto dispatch; }
goto P_0c072e5e;
P_0c072e5c: /* original 741c, guest PC 0x0c072e5c */
if(!s->budget--) { s->failed_pc=0x0c072e5cu; return 0; }
r[4]+=0x0000001cu;
goto P_0c072e5e;
P_0c072e5e: /* original 64e3, guest PC 0x0c072e5e */
if(!s->budget--) { s->failed_pc=0x0c072e5eu; return 0; }
r[4]=r[14];
goto P_0c072e60;
P_0c072e60: /* original e51b, guest PC 0x0c072e60 */
if(!s->budget--) { s->failed_pc=0x0c072e60u; return 0; }
r[5]=0x0000001bu;
goto P_0c072e62;
P_0c072e62: /* original 4d0b, guest PC 0x0c072e62 */
if(!s->budget--) { s->failed_pc=0x0c072e62u; return 0; }
target=r[13];
r[16]=0x0c072e66u;
r[4]+=0x0000001du;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c072e66u) { target=s->pc; goto dispatch; }
goto P_0c072e66;
P_0c072e64: /* original 741d, guest PC 0x0c072e64 */
if(!s->budget--) { s->failed_pc=0x0c072e64u; return 0; }
r[4]+=0x0000001du;
goto P_0c072e66;
P_0c072e66: /* original b25b, guest PC 0x0c072e66 */
if(!s->budget--) { s->failed_pc=0x0c072e66u; return 0; }
target=0x0c073320u; r[16]=0x0c072e6au;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c072e6au) { target=s->pc; goto dispatch; }
goto P_0c072e6a;
P_0c072e68: /* original 64e3, guest PC 0x0c072e68 */
if(!s->budget--) { s->failed_pc=0x0c072e68u; return 0; }
r[4]=r[14];
goto P_0c072e6a;
P_0c072e6a: /* original 64e3, guest PC 0x0c072e6a */
if(!s->budget--) { s->failed_pc=0x0c072e6au; return 0; }
r[4]=r[14];
goto P_0c072e6c;
P_0c072e6c: /* original e501, guest PC 0x0c072e6c */
if(!s->budget--) { s->failed_pc=0x0c072e6cu; return 0; }
r[5]=0x00000001u;
goto P_0c072e6e;
P_0c072e6e: /* original 4d0b, guest PC 0x0c072e6e */
if(!s->budget--) { s->failed_pc=0x0c072e6eu; return 0; }
target=r[13];
r[16]=0x0c072e72u;
r[4]+=0x00000022u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c072e72u) { target=s->pc; goto dispatch; }
goto P_0c072e72;
P_0c072e70: /* original 7422, guest PC 0x0c072e70 */
if(!s->budget--) { s->failed_pc=0x0c072e70u; return 0; }
r[4]+=0x00000022u;
goto P_0c072e72;
P_0c072e72: /* original 64e3, guest PC 0x0c072e72 */
if(!s->budget--) { s->failed_pc=0x0c072e72u; return 0; }
r[4]=r[14];
goto P_0c072e74;
P_0c072e74: /* original e501, guest PC 0x0c072e74 */
if(!s->budget--) { s->failed_pc=0x0c072e74u; return 0; }
r[5]=0x00000001u;
goto P_0c072e76;
P_0c072e76: /* original 4d0b, guest PC 0x0c072e76 */
if(!s->budget--) { s->failed_pc=0x0c072e76u; return 0; }
target=r[13];
r[16]=0x0c072e7au;
r[4]+=0x00000023u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c072e7au) { target=s->pc; goto dispatch; }
goto P_0c072e7a;
P_0c072e78: /* original 7423, guest PC 0x0c072e78 */
if(!s->budget--) { s->failed_pc=0x0c072e78u; return 0; }
r[4]+=0x00000023u;
goto P_0c072e7a;
P_0c072e7a: /* original 64e3, guest PC 0x0c072e7a */
if(!s->budget--) { s->failed_pc=0x0c072e7au; return 0; }
r[4]=r[14];
goto P_0c072e7c;
P_0c072e7c: /* original e501, guest PC 0x0c072e7c */
if(!s->budget--) { s->failed_pc=0x0c072e7cu; return 0; }
r[5]=0x00000001u;
goto P_0c072e7e;
P_0c072e7e: /* original 4d0b, guest PC 0x0c072e7e */
if(!s->budget--) { s->failed_pc=0x0c072e7eu; return 0; }
target=r[13];
r[16]=0x0c072e82u;
r[4]+=0x00000024u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c072e82u) { target=s->pc; goto dispatch; }
goto P_0c072e82;
P_0c072e80: /* original 7424, guest PC 0x0c072e80 */
if(!s->budget--) { s->failed_pc=0x0c072e80u; return 0; }
r[4]+=0x00000024u;
goto P_0c072e82;
P_0c072e82: /* original 64e3, guest PC 0x0c072e82 */
if(!s->budget--) { s->failed_pc=0x0c072e82u; return 0; }
r[4]=r[14];
goto P_0c072e84;
P_0c072e84: /* original e500, guest PC 0x0c072e84 */
if(!s->budget--) { s->failed_pc=0x0c072e84u; return 0; }
r[5]=0x00000000u;
goto P_0c072e86;
P_0c072e86: /* original 4d0b, guest PC 0x0c072e86 */
if(!s->budget--) { s->failed_pc=0x0c072e86u; return 0; }
target=r[13];
r[16]=0x0c072e8au;
r[4]+=0x00000025u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c072e8au) { target=s->pc; goto dispatch; }
goto P_0c072e8a;
P_0c072e88: /* original 7425, guest PC 0x0c072e88 */
if(!s->budget--) { s->failed_pc=0x0c072e88u; return 0; }
r[4]+=0x00000025u;
goto P_0c072e8a;
P_0c072e8a: /* original 64e3, guest PC 0x0c072e8a */
if(!s->budget--) { s->failed_pc=0x0c072e8au; return 0; }
r[4]=r[14];
goto P_0c072e8c;
P_0c072e8c: /* original e500, guest PC 0x0c072e8c */
if(!s->budget--) { s->failed_pc=0x0c072e8cu; return 0; }
r[5]=0x00000000u;
goto P_0c072e8e;
P_0c072e8e: /* original 4d0b, guest PC 0x0c072e8e */
if(!s->budget--) { s->failed_pc=0x0c072e8eu; return 0; }
target=r[13];
r[16]=0x0c072e92u;
r[4]+=0x00000026u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c072e92u) { target=s->pc; goto dispatch; }
goto P_0c072e92;
P_0c072e90: /* original 7426, guest PC 0x0c072e90 */
if(!s->budget--) { s->failed_pc=0x0c072e90u; return 0; }
r[4]+=0x00000026u;
goto P_0c072e92;
P_0c072e92: /* original 64e3, guest PC 0x0c072e92 */
if(!s->budget--) { s->failed_pc=0x0c072e92u; return 0; }
r[4]=r[14];
goto P_0c072e94;
P_0c072e94: /* original e500, guest PC 0x0c072e94 */
if(!s->budget--) { s->failed_pc=0x0c072e94u; return 0; }
r[5]=0x00000000u;
goto P_0c072e96;
P_0c072e96: /* original 4d0b, guest PC 0x0c072e96 */
if(!s->budget--) { s->failed_pc=0x0c072e96u; return 0; }
target=r[13];
r[16]=0x0c072e9au;
r[4]+=0x00000027u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c072e9au) { target=s->pc; goto dispatch; }
goto P_0c072e9a;
P_0c072e98: /* original 7427, guest PC 0x0c072e98 */
if(!s->budget--) { s->failed_pc=0x0c072e98u; return 0; }
r[4]+=0x00000027u;
goto P_0c072e9a;
P_0c072e9a: /* original 64e3, guest PC 0x0c072e9a */
if(!s->budget--) { s->failed_pc=0x0c072e9au; return 0; }
r[4]=r[14];
goto P_0c072e9c;
P_0c072e9c: /* original e500, guest PC 0x0c072e9c */
if(!s->budget--) { s->failed_pc=0x0c072e9cu; return 0; }
r[5]=0x00000000u;
goto P_0c072e9e;
P_0c072e9e: /* original 4d0b, guest PC 0x0c072e9e */
if(!s->budget--) { s->failed_pc=0x0c072e9eu; return 0; }
target=r[13];
r[16]=0x0c072ea2u;
r[4]+=0x00000028u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c072ea2u) { target=s->pc; goto dispatch; }
goto P_0c072ea2;
P_0c072ea0: /* original 7428, guest PC 0x0c072ea0 */
if(!s->budget--) { s->failed_pc=0x0c072ea0u; return 0; }
r[4]+=0x00000028u;
goto P_0c072ea2;
P_0c072ea2: /* original 64e3, guest PC 0x0c072ea2 */
if(!s->budget--) { s->failed_pc=0x0c072ea2u; return 0; }
r[4]=r[14];
goto P_0c072ea4;
P_0c072ea4: /* original e500, guest PC 0x0c072ea4 */
if(!s->budget--) { s->failed_pc=0x0c072ea4u; return 0; }
r[5]=0x00000000u;
goto P_0c072ea6;
P_0c072ea6: /* original 4d0b, guest PC 0x0c072ea6 */
if(!s->budget--) { s->failed_pc=0x0c072ea6u; return 0; }
target=r[13];
r[16]=0x0c072eaau;
r[4]+=0x00000029u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c072eaau) { target=s->pc; goto dispatch; }
goto P_0c072eaa;
P_0c072ea8: /* original 7429, guest PC 0x0c072ea8 */
if(!s->budget--) { s->failed_pc=0x0c072ea8u; return 0; }
r[4]+=0x00000029u;
goto P_0c072eaa;
P_0c072eaa: /* original 64e3, guest PC 0x0c072eaa */
if(!s->budget--) { s->failed_pc=0x0c072eaau; return 0; }
r[4]=r[14];
goto P_0c072eac;
P_0c072eac: /* original e500, guest PC 0x0c072eac */
if(!s->budget--) { s->failed_pc=0x0c072eacu; return 0; }
r[5]=0x00000000u;
goto P_0c072eae;
P_0c072eae: /* original 4d0b, guest PC 0x0c072eae */
if(!s->budget--) { s->failed_pc=0x0c072eaeu; return 0; }
target=r[13];
r[16]=0x0c072eb2u;
r[4]+=0x0000002au;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c072eb2u) { target=s->pc; goto dispatch; }
goto P_0c072eb2;
P_0c072eb0: /* original 742a, guest PC 0x0c072eb0 */
if(!s->budget--) { s->failed_pc=0x0c072eb0u; return 0; }
r[4]+=0x0000002au;
goto P_0c072eb2;
P_0c072eb2: /* original 64e3, guest PC 0x0c072eb2 */
if(!s->budget--) { s->failed_pc=0x0c072eb2u; return 0; }
r[4]=r[14];
goto P_0c072eb4;
P_0c072eb4: /* original e500, guest PC 0x0c072eb4 */
if(!s->budget--) { s->failed_pc=0x0c072eb4u; return 0; }
r[5]=0x00000000u;
goto P_0c072eb6;
P_0c072eb6: /* original 4d0b, guest PC 0x0c072eb6 */
if(!s->budget--) { s->failed_pc=0x0c072eb6u; return 0; }
target=r[13];
r[16]=0x0c072ebau;
r[4]+=0x0000002bu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c072ebau) { target=s->pc; goto dispatch; }
goto P_0c072eba;
P_0c072eb8: /* original 742b, guest PC 0x0c072eb8 */
if(!s->budget--) { s->failed_pc=0x0c072eb8u; return 0; }
r[4]+=0x0000002bu;
goto P_0c072eba;
P_0c072eba: /* original 4f26, guest PC 0x0c072eba */
if(!s->budget--) { s->failed_pc=0x0c072ebau; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c072ebc;
P_0c072ebc: /* original 6df6, guest PC 0x0c072ebc */
if(!s->budget--) { s->failed_pc=0x0c072ebcu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c072ebe;
P_0c072ebe: /* original 000b, guest PC 0x0c072ebe */
if(!s->budget--) { s->failed_pc=0x0c072ebeu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c072ec0: /* original 6ef6, guest PC 0x0c072ec0 */
if(!s->budget--) { s->failed_pc=0x0c072ec0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c072ec2u,s,ram);
P_0c08e5ce: /* original 4f22, guest PC 0x0c08e5ce */
if(!s->budget--) { s->failed_pc=0x0c08e5ceu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c08e5d0;
P_0c08e5d0: /* original dd2b, guest PC 0x0c08e5d0 */
if(!s->budget--) { s->failed_pc=0x0c08e5d0u; return 0; }
r[13]=read(ram,0x0c08e680u,4);
goto P_0c08e5d2;
P_0c08e5d2: /* original de2a, guest PC 0x0c08e5d2 */
if(!s->budget--) { s->failed_pc=0x0c08e5d2u; return 0; }
r[14]=read(ram,0x0c08e67cu,4);
goto P_0c08e5d4;
P_0c08e5d4: /* original 4d0b, guest PC 0x0c08e5d4 */
if(!s->budget--) { s->failed_pc=0x0c08e5d4u; return 0; }
target=r[13];
r[16]=0x0c08e5d8u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08e5d8u) { target=s->pc; goto dispatch; }
goto P_0c08e5d8;
P_0c08e5d6: /* original 64e3, guest PC 0x0c08e5d6 */
if(!s->budget--) { s->failed_pc=0x0c08e5d6u; return 0; }
r[4]=r[14];
goto P_0c08e5d8;
P_0c08e5d8: /* original 64e3, guest PC 0x0c08e5d8 */
if(!s->budget--) { s->failed_pc=0x0c08e5d8u; return 0; }
r[4]=r[14];
goto P_0c08e5da;
P_0c08e5da: /* original e503, guest PC 0x0c08e5da */
if(!s->budget--) { s->failed_pc=0x0c08e5dau; return 0; }
r[5]=0x00000003u;
goto P_0c08e5dc;
P_0c08e5dc: /* original 4d0b, guest PC 0x0c08e5dc */
if(!s->budget--) { s->failed_pc=0x0c08e5dcu; return 0; }
target=r[13];
r[16]=0x0c08e5e0u;
r[4]+=0x00000001u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08e5e0u) { target=s->pc; goto dispatch; }
goto P_0c08e5e0;
P_0c08e5de: /* original 7401, guest PC 0x0c08e5de */
if(!s->budget--) { s->failed_pc=0x0c08e5deu; return 0; }
r[4]+=0x00000001u;
goto P_0c08e5e0;
P_0c08e5e0: /* original 64e3, guest PC 0x0c08e5e0 */
if(!s->budget--) { s->failed_pc=0x0c08e5e0u; return 0; }
r[4]=r[14];
goto P_0c08e5e2;
P_0c08e5e2: /* original e501, guest PC 0x0c08e5e2 */
if(!s->budget--) { s->failed_pc=0x0c08e5e2u; return 0; }
r[5]=0x00000001u;
goto P_0c08e5e4;
P_0c08e5e4: /* original 4d0b, guest PC 0x0c08e5e4 */
if(!s->budget--) { s->failed_pc=0x0c08e5e4u; return 0; }
target=r[13];
r[16]=0x0c08e5e8u;
r[4]+=0x00000002u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08e5e8u) { target=s->pc; goto dispatch; }
goto P_0c08e5e8;
P_0c08e5e6: /* original 7402, guest PC 0x0c08e5e6 */
if(!s->budget--) { s->failed_pc=0x0c08e5e6u; return 0; }
r[4]+=0x00000002u;
goto P_0c08e5e8;
P_0c08e5e8: /* original 9b46, guest PC 0x0c08e5e8 */
if(!s->budget--) { s->failed_pc=0x0c08e5e8u; return 0; }
r[11]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08e678u,2);
goto P_0c08e5ea;
P_0c08e5ea: /* original 64e3, guest PC 0x0c08e5ea */
if(!s->budget--) { s->failed_pc=0x0c08e5eau; return 0; }
r[4]=r[14];
goto P_0c08e5ec;
P_0c08e5ec: /* original dc25, guest PC 0x0c08e5ec */
if(!s->budget--) { s->failed_pc=0x0c08e5ecu; return 0; }
r[12]=read(ram,0x0c08e684u,4);
goto P_0c08e5ee;
P_0c08e5ee: /* original 65b3, guest PC 0x0c08e5ee */
if(!s->budget--) { s->failed_pc=0x0c08e5eeu; return 0; }
r[5]=r[11];
goto P_0c08e5f0;
P_0c08e5f0: /* original 4c0b, guest PC 0x0c08e5f0 */
if(!s->budget--) { s->failed_pc=0x0c08e5f0u; return 0; }
target=r[12];
r[16]=0x0c08e5f4u;
r[4]+=0x00000004u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08e5f4u) { target=s->pc; goto dispatch; }
goto P_0c08e5f4;
P_0c08e5f2: /* original 7404, guest PC 0x0c08e5f2 */
if(!s->budget--) { s->failed_pc=0x0c08e5f2u; return 0; }
r[4]+=0x00000004u;
goto P_0c08e5f4;
P_0c08e5f4: /* original 64e3, guest PC 0x0c08e5f4 */
if(!s->budget--) { s->failed_pc=0x0c08e5f4u; return 0; }
r[4]=r[14];
goto P_0c08e5f6;
P_0c08e5f6: /* original 65b3, guest PC 0x0c08e5f6 */
if(!s->budget--) { s->failed_pc=0x0c08e5f6u; return 0; }
r[5]=r[11];
goto P_0c08e5f8;
P_0c08e5f8: /* original 4c0b, guest PC 0x0c08e5f8 */
if(!s->budget--) { s->failed_pc=0x0c08e5f8u; return 0; }
target=r[12];
r[16]=0x0c08e5fcu;
r[4]+=0x00000008u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08e5fcu) { target=s->pc; goto dispatch; }
goto P_0c08e5fc;
P_0c08e5fa: /* original 7408, guest PC 0x0c08e5fa */
if(!s->budget--) { s->failed_pc=0x0c08e5fau; return 0; }
r[4]+=0x00000008u;
goto P_0c08e5fc;
P_0c08e5fc: /* original 64e3, guest PC 0x0c08e5fc */
if(!s->budget--) { s->failed_pc=0x0c08e5fcu; return 0; }
r[4]=r[14];
goto P_0c08e5fe;
P_0c08e5fe: /* original 65b3, guest PC 0x0c08e5fe */
if(!s->budget--) { s->failed_pc=0x0c08e5feu; return 0; }
r[5]=r[11];
goto P_0c08e600;
P_0c08e600: /* original 4c0b, guest PC 0x0c08e600 */
if(!s->budget--) { s->failed_pc=0x0c08e600u; return 0; }
target=r[12];
r[16]=0x0c08e604u;
r[4]+=0x00000006u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08e604u) { target=s->pc; goto dispatch; }
goto P_0c08e604;
P_0c08e602: /* original 7406, guest PC 0x0c08e602 */
if(!s->budget--) { s->failed_pc=0x0c08e602u; return 0; }
r[4]+=0x00000006u;
goto P_0c08e604;
P_0c08e604: /* original 64e3, guest PC 0x0c08e604 */
if(!s->budget--) { s->failed_pc=0x0c08e604u; return 0; }
r[4]=r[14];
goto P_0c08e606;
P_0c08e606: /* original e501, guest PC 0x0c08e606 */
if(!s->budget--) { s->failed_pc=0x0c08e606u; return 0; }
r[5]=0x00000001u;
goto P_0c08e608;
P_0c08e608: /* original 4c0b, guest PC 0x0c08e608 */
if(!s->budget--) { s->failed_pc=0x0c08e608u; return 0; }
target=r[12];
r[16]=0x0c08e60cu;
r[4]+=0x0000000au;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08e60cu) { target=s->pc; goto dispatch; }
goto P_0c08e60c;
P_0c08e60a: /* original 740a, guest PC 0x0c08e60a */
if(!s->budget--) { s->failed_pc=0x0c08e60au; return 0; }
r[4]+=0x0000000au;
goto P_0c08e60c;
P_0c08e60c: /* original 64e3, guest PC 0x0c08e60c */
if(!s->budget--) { s->failed_pc=0x0c08e60cu; return 0; }
r[4]=r[14];
goto P_0c08e60e;
P_0c08e60e: /* original e500, guest PC 0x0c08e60e */
if(!s->budget--) { s->failed_pc=0x0c08e60eu; return 0; }
r[5]=0x00000000u;
goto P_0c08e610;
P_0c08e610: /* original 4d0b, guest PC 0x0c08e610 */
if(!s->budget--) { s->failed_pc=0x0c08e610u; return 0; }
target=r[13];
r[16]=0x0c08e614u;
r[4]+=0x00000003u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08e614u) { target=s->pc; goto dispatch; }
goto P_0c08e614;
P_0c08e612: /* original 7403, guest PC 0x0c08e612 */
if(!s->budget--) { s->failed_pc=0x0c08e612u; return 0; }
r[4]+=0x00000003u;
goto P_0c08e614;
P_0c08e614: /* original 64e3, guest PC 0x0c08e614 */
if(!s->budget--) { s->failed_pc=0x0c08e614u; return 0; }
r[4]=r[14];
goto P_0c08e616;
P_0c08e616: /* original e500, guest PC 0x0c08e616 */
if(!s->budget--) { s->failed_pc=0x0c08e616u; return 0; }
r[5]=0x00000000u;
goto P_0c08e618;
P_0c08e618: /* original 4d0b, guest PC 0x0c08e618 */
if(!s->budget--) { s->failed_pc=0x0c08e618u; return 0; }
target=r[13];
r[16]=0x0c08e61cu;
r[4]+=0x0000000cu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08e61cu) { target=s->pc; goto dispatch; }
goto P_0c08e61c;
P_0c08e61a: /* original 740c, guest PC 0x0c08e61a */
if(!s->budget--) { s->failed_pc=0x0c08e61au; return 0; }
r[4]+=0x0000000cu;
goto P_0c08e61c;
P_0c08e61c: /* original 64e3, guest PC 0x0c08e61c */
if(!s->budget--) { s->failed_pc=0x0c08e61cu; return 0; }
r[4]=r[14];
goto P_0c08e61e;
P_0c08e61e: /* original e500, guest PC 0x0c08e61e */
if(!s->budget--) { s->failed_pc=0x0c08e61eu; return 0; }
r[5]=0x00000000u;
goto P_0c08e620;
P_0c08e620: /* original 4d0b, guest PC 0x0c08e620 */
if(!s->budget--) { s->failed_pc=0x0c08e620u; return 0; }
target=r[13];
r[16]=0x0c08e624u;
r[4]+=0x0000000eu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08e624u) { target=s->pc; goto dispatch; }
goto P_0c08e624;
P_0c08e622: /* original 740e, guest PC 0x0c08e622 */
if(!s->budget--) { s->failed_pc=0x0c08e622u; return 0; }
r[4]+=0x0000000eu;
goto P_0c08e624;
P_0c08e624: /* original 64e3, guest PC 0x0c08e624 */
if(!s->budget--) { s->failed_pc=0x0c08e624u; return 0; }
r[4]=r[14];
goto P_0c08e626;
P_0c08e626: /* original e500, guest PC 0x0c08e626 */
if(!s->budget--) { s->failed_pc=0x0c08e626u; return 0; }
r[5]=0x00000000u;
goto P_0c08e628;
P_0c08e628: /* original 4d0b, guest PC 0x0c08e628 */
if(!s->budget--) { s->failed_pc=0x0c08e628u; return 0; }
target=r[13];
r[16]=0x0c08e62cu;
r[4]+=0x0000000fu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08e62cu) { target=s->pc; goto dispatch; }
goto P_0c08e62c;
P_0c08e62a: /* original 740f, guest PC 0x0c08e62a */
if(!s->budget--) { s->failed_pc=0x0c08e62au; return 0; }
r[4]+=0x0000000fu;
goto P_0c08e62c;
P_0c08e62c: /* original 64e3, guest PC 0x0c08e62c */
if(!s->budget--) { s->failed_pc=0x0c08e62cu; return 0; }
r[4]=r[14];
goto P_0c08e62e;
P_0c08e62e: /* original e501, guest PC 0x0c08e62e */
if(!s->budget--) { s->failed_pc=0x0c08e62eu; return 0; }
r[5]=0x00000001u;
goto P_0c08e630;
P_0c08e630: /* original 4d0b, guest PC 0x0c08e630 */
if(!s->budget--) { s->failed_pc=0x0c08e630u; return 0; }
target=r[13];
r[16]=0x0c08e634u;
r[4]+=0x00000010u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08e634u) { target=s->pc; goto dispatch; }
goto P_0c08e634;
P_0c08e632: /* original 7410, guest PC 0x0c08e632 */
if(!s->budget--) { s->failed_pc=0x0c08e632u; return 0; }
r[4]+=0x00000010u;
goto P_0c08e634;
P_0c08e634: /* original 64e3, guest PC 0x0c08e634 */
if(!s->budget--) { s->failed_pc=0x0c08e634u; return 0; }
r[4]=r[14];
goto P_0c08e636;
P_0c08e636: /* original e500, guest PC 0x0c08e636 */
if(!s->budget--) { s->failed_pc=0x0c08e636u; return 0; }
r[5]=0x00000000u;
goto P_0c08e638;
P_0c08e638: /* original 4d0b, guest PC 0x0c08e638 */
if(!s->budget--) { s->failed_pc=0x0c08e638u; return 0; }
target=r[13];
r[16]=0x0c08e63cu;
r[4]+=0x00000011u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08e63cu) { target=s->pc; goto dispatch; }
goto P_0c08e63c;
P_0c08e63a: /* original 7411, guest PC 0x0c08e63a */
if(!s->budget--) { s->failed_pc=0x0c08e63au; return 0; }
r[4]+=0x00000011u;
goto P_0c08e63c;
P_0c08e63c: /* original 64e3, guest PC 0x0c08e63c */
if(!s->budget--) { s->failed_pc=0x0c08e63cu; return 0; }
r[4]=r[14];
goto P_0c08e63e;
P_0c08e63e: /* original e501, guest PC 0x0c08e63e */
if(!s->budget--) { s->failed_pc=0x0c08e63eu; return 0; }
r[5]=0x00000001u;
goto P_0c08e640;
P_0c08e640: /* original 4d0b, guest PC 0x0c08e640 */
if(!s->budget--) { s->failed_pc=0x0c08e640u; return 0; }
target=r[13];
r[16]=0x0c08e644u;
r[4]+=0x00000012u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08e644u) { target=s->pc; goto dispatch; }
goto P_0c08e644;
P_0c08e642: /* original 7412, guest PC 0x0c08e642 */
if(!s->budget--) { s->failed_pc=0x0c08e642u; return 0; }
r[4]+=0x00000012u;
goto P_0c08e644;
P_0c08e644: /* original 64e3, guest PC 0x0c08e644 */
if(!s->budget--) { s->failed_pc=0x0c08e644u; return 0; }
r[4]=r[14];
goto P_0c08e646;
P_0c08e646: /* original e500, guest PC 0x0c08e646 */
if(!s->budget--) { s->failed_pc=0x0c08e646u; return 0; }
r[5]=0x00000000u;
goto P_0c08e648;
P_0c08e648: /* original 4d0b, guest PC 0x0c08e648 */
if(!s->budget--) { s->failed_pc=0x0c08e648u; return 0; }
target=r[13];
r[16]=0x0c08e64cu;
r[4]+=0x00000013u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08e64cu) { target=s->pc; goto dispatch; }
goto P_0c08e64c;
P_0c08e64a: /* original 7413, guest PC 0x0c08e64a */
if(!s->budget--) { s->failed_pc=0x0c08e64au; return 0; }
r[4]+=0x00000013u;
goto P_0c08e64c;
P_0c08e64c: /* original 64e3, guest PC 0x0c08e64c */
if(!s->budget--) { s->failed_pc=0x0c08e64cu; return 0; }
r[4]=r[14];
goto P_0c08e64e;
P_0c08e64e: /* original e500, guest PC 0x0c08e64e */
if(!s->budget--) { s->failed_pc=0x0c08e64eu; return 0; }
r[5]=0x00000000u;
goto P_0c08e650;
P_0c08e650: /* original 4d0b, guest PC 0x0c08e650 */
if(!s->budget--) { s->failed_pc=0x0c08e650u; return 0; }
target=r[13];
r[16]=0x0c08e654u;
r[4]+=0x00000015u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08e654u) { target=s->pc; goto dispatch; }
goto P_0c08e654;
P_0c08e652: /* original 7415, guest PC 0x0c08e652 */
if(!s->budget--) { s->failed_pc=0x0c08e652u; return 0; }
r[4]+=0x00000015u;
goto P_0c08e654;
P_0c08e654: /* original 64e3, guest PC 0x0c08e654 */
if(!s->budget--) { s->failed_pc=0x0c08e654u; return 0; }
r[4]=r[14];
goto P_0c08e656;
P_0c08e656: /* original e500, guest PC 0x0c08e656 */
if(!s->budget--) { s->failed_pc=0x0c08e656u; return 0; }
r[5]=0x00000000u;
goto P_0c08e658;
P_0c08e658: /* original 4d0b, guest PC 0x0c08e658 */
if(!s->budget--) { s->failed_pc=0x0c08e658u; return 0; }
target=r[13];
r[16]=0x0c08e65cu;
r[4]+=0x00000014u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08e65cu) { target=s->pc; goto dispatch; }
goto P_0c08e65c;
P_0c08e65a: /* original 7414, guest PC 0x0c08e65a */
if(!s->budget--) { s->failed_pc=0x0c08e65au; return 0; }
r[4]+=0x00000014u;
goto P_0c08e65c;
P_0c08e65c: /* original 64e3, guest PC 0x0c08e65c */
if(!s->budget--) { s->failed_pc=0x0c08e65cu; return 0; }
r[4]=r[14];
goto P_0c08e65e;
P_0c08e65e: /* original e500, guest PC 0x0c08e65e */
if(!s->budget--) { s->failed_pc=0x0c08e65eu; return 0; }
r[5]=0x00000000u;
goto P_0c08e660;
P_0c08e660: /* original 4d0b, guest PC 0x0c08e660 */
if(!s->budget--) { s->failed_pc=0x0c08e660u; return 0; }
target=r[13];
r[16]=0x0c08e664u;
r[4]+=0x00000016u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08e664u) { target=s->pc; goto dispatch; }
goto P_0c08e664;
P_0c08e662: /* original 7416, guest PC 0x0c08e662 */
if(!s->budget--) { s->failed_pc=0x0c08e662u; return 0; }
r[4]+=0x00000016u;
goto P_0c08e664;
P_0c08e664: /* original 4f26, guest PC 0x0c08e664 */
if(!s->budget--) { s->failed_pc=0x0c08e664u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c08e666;
P_0c08e666: /* original 6bf6, guest PC 0x0c08e666 */
if(!s->budget--) { s->failed_pc=0x0c08e666u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c08e668;
P_0c08e668: /* original 6cf6, guest PC 0x0c08e668 */
if(!s->budget--) { s->failed_pc=0x0c08e668u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c08e66a;
P_0c08e66a: /* original 6df6, guest PC 0x0c08e66a */
if(!s->budget--) { s->failed_pc=0x0c08e66au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c08e66c;
P_0c08e66c: /* original 000b, guest PC 0x0c08e66c */
if(!s->budget--) { s->failed_pc=0x0c08e66cu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c08e66e: /* original 6ef6, guest PC 0x0c08e66e */
if(!s->budget--) { s->failed_pc=0x0c08e66eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c08e670u,s,ram);
P_0c09fe7a: /* original 4f22, guest PC 0x0c09fe7a */
if(!s->budget--) { s->failed_pc=0x0c09fe7au; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c09fe7c;
P_0c09fe7c: /* original d343, guest PC 0x0c09fe7c */
if(!s->budget--) { s->failed_pc=0x0c09fe7cu; return 0; }
r[3]=read(ram,0x0c09ff8cu,4);
goto P_0c09fe7e;
P_0c09fe7e: /* original 6e93, guest PC 0x0c09fe7e */
if(!s->budget--) { s->failed_pc=0x0c09fe7eu; return 0; }
r[14]=r[9];
goto P_0c09fe80;
P_0c09fe80: /* original dc41, guest PC 0x0c09fe80 */
if(!s->budget--) { s->failed_pc=0x0c09fe80u; return 0; }
r[12]=read(ram,0x0c09ff88u,4);
goto P_0c09fe82;
P_0c09fe82: /* original 7ff0, guest PC 0x0c09fe82 */
if(!s->budget--) { s->failed_pc=0x0c09fe82u; return 0; }
r[15]+=0xfffffff0u;
goto P_0c09fe84;
P_0c09fe84: /* original 2f32, guest PC 0x0c09fe84 */
if(!s->budget--) { s->failed_pc=0x0c09fe84u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c09fe86;
P_0c09fe86: /* original 6bc3, guest PC 0x0c09fe86 */
if(!s->budget--) { s->failed_pc=0x0c09fe86u; return 0; }
r[11]=r[12];
goto P_0c09fe88;
P_0c09fe88: /* original d241, guest PC 0x0c09fe88 */
if(!s->budget--) { s->failed_pc=0x0c09fe88u; return 0; }
r[2]=read(ram,0x0c09ff90u,4);
goto P_0c09fe8a;
P_0c09fe8a: /* original 1f23, guest PC 0x0c09fe8a */
if(!s->budget--) { s->failed_pc=0x0c09fe8au; return 0; }
write(ram,r[15]+12,r[2],4);
goto P_0c09fe8c;
P_0c09fe8c: /* original d341, guest PC 0x0c09fe8c */
if(!s->budget--) { s->failed_pc=0x0c09fe8cu; return 0; }
r[3]=read(ram,0x0c09ff94u,4);
goto P_0c09fe8e;
P_0c09fe8e: /* original 1f31, guest PC 0x0c09fe8e */
if(!s->budget--) { s->failed_pc=0x0c09fe8eu; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c09fe90;
P_0c09fe90: /* original d241, guest PC 0x0c09fe90 */
if(!s->budget--) { s->failed_pc=0x0c09fe90u; return 0; }
r[2]=read(ram,0x0c09ff98u,4);
goto P_0c09fe92;
P_0c09fe92: /* original 1f22, guest PC 0x0c09fe92 */
if(!s->budget--) { s->failed_pc=0x0c09fe92u; return 0; }
write(ram,r[15]+8,r[2],4);
goto P_0c09fe94;
P_0c09fe94: /* original 9a73, guest PC 0x0c09fe94 */
if(!s->budget--) { s->failed_pc=0x0c09fe94u; return 0; }
r[10]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09ff7eu,2);
goto P_0c09fe96;
P_0c09fe96: /* original dd41, guest PC 0x0c09fe96 */
if(!s->budget--) { s->failed_pc=0x0c09fe96u; return 0; }
r[13]=read(ram,0x0c09ff9cu,4);
goto P_0c09fe98;
P_0c09fe98: /* original 3acc, guest PC 0x0c09fe98 */
if(!s->budget--) { s->failed_pc=0x0c09fe98u; return 0; }
r[10]+=r[12];
goto P_0c09fe9a;
P_0c09fe9a: /* original 65f2, guest PC 0x0c09fe9a */
if(!s->budget--) { s->failed_pc=0x0c09fe9au; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c09fe9c;
P_0c09fe9c: /* original 7504, guest PC 0x0c09fe9c */
if(!s->budget--) { s->failed_pc=0x0c09fe9cu; return 0; }
r[5]+=0x00000004u;
goto P_0c09fe9e;
P_0c09fe9e: /* original 2f52, guest PC 0x0c09fe9e */
if(!s->budget--) { s->failed_pc=0x0c09fe9eu; return 0; }
write(ram,r[15],r[5],4);
goto P_0c09fea0;
P_0c09fea0: /* original 75fc, guest PC 0x0c09fea0 */
if(!s->budget--) { s->failed_pc=0x0c09fea0u; return 0; }
r[5]+=0xfffffffcu;
goto P_0c09fea2;
P_0c09fea2: /* original 6552, guest PC 0x0c09fea2 */
if(!s->budget--) { s->failed_pc=0x0c09fea2u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c09fea4;
P_0c09fea4: /* original 4d0b, guest PC 0x0c09fea4 */
if(!s->budget--) { s->failed_pc=0x0c09fea4u; return 0; }
target=r[13];
r[16]=0x0c09fea8u;
r[4]=r[11];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09fea8u) { target=s->pc; goto dispatch; }
goto P_0c09fea8;
P_0c09fea6: /* original 64b3, guest PC 0x0c09fea6 */
if(!s->budget--) { s->failed_pc=0x0c09fea6u; return 0; }
r[4]=r[11];
goto P_0c09fea8;
P_0c09fea8: /* original 55f3, guest PC 0x0c09fea8 */
if(!s->budget--) { s->failed_pc=0x0c09fea8u; return 0; }
r[5]=read(ram,r[15]+12,4);
goto P_0c09feaa;
P_0c09feaa: /* original 64c3, guest PC 0x0c09feaa */
if(!s->budget--) { s->failed_pc=0x0c09feaau; return 0; }
r[4]=r[12];
goto P_0c09feac;
P_0c09feac: /* original 7448, guest PC 0x0c09feac */
if(!s->budget--) { s->failed_pc=0x0c09feacu; return 0; }
r[4]+=0x00000048u;
goto P_0c09feae;
P_0c09feae: /* original 7504, guest PC 0x0c09feae */
if(!s->budget--) { s->failed_pc=0x0c09feaeu; return 0; }
r[5]+=0x00000004u;
goto P_0c09feb0;
P_0c09feb0: /* original 1f53, guest PC 0x0c09feb0 */
if(!s->budget--) { s->failed_pc=0x0c09feb0u; return 0; }
write(ram,r[15]+12,r[5],4);
goto P_0c09feb2;
P_0c09feb2: /* original 75fc, guest PC 0x0c09feb2 */
if(!s->budget--) { s->failed_pc=0x0c09feb2u; return 0; }
r[5]+=0xfffffffcu;
goto P_0c09feb4;
P_0c09feb4: /* original 6552, guest PC 0x0c09feb4 */
if(!s->budget--) { s->failed_pc=0x0c09feb4u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c09feb6;
P_0c09feb6: /* original 4d0b, guest PC 0x0c09feb6 */
if(!s->budget--) { s->failed_pc=0x0c09feb6u; return 0; }
target=r[13];
r[16]=0x0c09febau;
r[4]+=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09febau) { target=s->pc; goto dispatch; }
goto P_0c09feba;
P_0c09feb8: /* original 34ec, guest PC 0x0c09feb8 */
if(!s->budget--) { s->failed_pc=0x0c09feb8u; return 0; }
r[4]+=r[14];
goto P_0c09feba;
P_0c09feba: /* original 55f1, guest PC 0x0c09feba */
if(!s->budget--) { s->failed_pc=0x0c09febau; return 0; }
r[5]=read(ram,r[15]+4,4);
goto P_0c09febc;
P_0c09febc: /* original 7502, guest PC 0x0c09febc */
if(!s->budget--) { s->failed_pc=0x0c09febcu; return 0; }
r[5]+=0x00000002u;
goto P_0c09febe;
P_0c09febe: /* original 1f51, guest PC 0x0c09febe */
if(!s->budget--) { s->failed_pc=0x0c09febeu; return 0; }
write(ram,r[15]+4,r[5],4);
goto P_0c09fec0;
P_0c09fec0: /* original 75fe, guest PC 0x0c09fec0 */
if(!s->budget--) { s->failed_pc=0x0c09fec0u; return 0; }
r[5]+=0xfffffffeu;
goto P_0c09fec2;
P_0c09fec2: /* original 945d, guest PC 0x0c09fec2 */
if(!s->budget--) { s->failed_pc=0x0c09fec2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09ff80u,2);
goto P_0c09fec4;
P_0c09fec4: /* original 6551, guest PC 0x0c09fec4 */
if(!s->budget--) { s->failed_pc=0x0c09fec4u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[5],2);
r[5]=tmp;
goto P_0c09fec6;
P_0c09fec6: /* original 34cc, guest PC 0x0c09fec6 */
if(!s->budget--) { s->failed_pc=0x0c09fec6u; return 0; }
r[4]+=r[12];
goto P_0c09fec8;
P_0c09fec8: /* original 655d, guest PC 0x0c09fec8 */
if(!s->budget--) { s->failed_pc=0x0c09fec8u; return 0; }
r[5]=r[5]&65535u;
goto P_0c09feca;
P_0c09feca: /* original 4d0b, guest PC 0x0c09feca */
if(!s->budget--) { s->failed_pc=0x0c09fecau; return 0; }
target=r[13];
r[16]=0x0c09feceu;
r[4]+=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09feceu) { target=s->pc; goto dispatch; }
goto P_0c09fece;
P_0c09fecc: /* original 34ec, guest PC 0x0c09fecc */
if(!s->budget--) { s->failed_pc=0x0c09feccu; return 0; }
r[4]+=r[14];
goto P_0c09fece;
P_0c09fece: /* original 55f2, guest PC 0x0c09fece */
if(!s->budget--) { s->failed_pc=0x0c09feceu; return 0; }
r[5]=read(ram,r[15]+8,4);
goto P_0c09fed0;
P_0c09fed0: /* original 7501, guest PC 0x0c09fed0 */
if(!s->budget--) { s->failed_pc=0x0c09fed0u; return 0; }
r[5]+=0x00000001u;
goto P_0c09fed2;
P_0c09fed2: /* original 1f52, guest PC 0x0c09fed2 */
if(!s->budget--) { s->failed_pc=0x0c09fed2u; return 0; }
write(ram,r[15]+8,r[5],4);
goto P_0c09fed4;
P_0c09fed4: /* original 75ff, guest PC 0x0c09fed4 */
if(!s->budget--) { s->failed_pc=0x0c09fed4u; return 0; }
r[5]+=0xffffffffu;
goto P_0c09fed6;
P_0c09fed6: /* original d332, guest PC 0x0c09fed6 */
if(!s->budget--) { s->failed_pc=0x0c09fed6u; return 0; }
r[3]=read(ram,0x0c09ffa0u,4);
goto P_0c09fed8;
P_0c09fed8: /* original 6550, guest PC 0x0c09fed8 */
if(!s->budget--) { s->failed_pc=0x0c09fed8u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[5],1);
r[5]=tmp;
goto P_0c09feda;
P_0c09feda: /* original 430b, guest PC 0x0c09feda */
if(!s->budget--) { s->failed_pc=0x0c09fedau; return 0; }
target=r[3];
r[16]=0x0c09fedeu;
r[4]=r[10];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09fedeu) { target=s->pc; goto dispatch; }
goto P_0c09fede;
P_0c09fedc: /* original 64a3, guest PC 0x0c09fedc */
if(!s->budget--) { s->failed_pc=0x0c09fedcu; return 0; }
r[4]=r[10];
goto P_0c09fede;
P_0c09fede: /* original 7901, guest PC 0x0c09fede */
if(!s->budget--) { s->failed_pc=0x0c09fedeu; return 0; }
r[9]+=0x00000001u;
goto P_0c09fee0;
P_0c09fee0: /* original 3983, guest PC 0x0c09fee0 */
if(!s->budget--) { s->failed_pc=0x0c09fee0u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[9]>=(int32_t)r[8])!=0);
goto P_0c09fee2;
P_0c09fee2: /* original 7e04, guest PC 0x0c09fee2 */
if(!s->budget--) { s->failed_pc=0x0c09fee2u; return 0; }
r[14]+=0x00000004u;
goto P_0c09fee4;
P_0c09fee4: /* original 7a01, guest PC 0x0c09fee4 */
if(!s->budget--) { s->failed_pc=0x0c09fee4u; return 0; }
r[10]+=0x00000001u;
goto P_0c09fee6;
P_0c09fee6: /* original 8fd8, guest PC 0x0c09fee6 */
if(!s->budget--) { s->failed_pc=0x0c09fee6u; return 0; }
cond=r[17]&1u;
r[11]+=0x00000004u;
if(!cond) { goto P_0c09fe9a; }
goto P_0c09feea;
P_0c09fee8: /* original 7b04, guest PC 0x0c09fee8 */
if(!s->budget--) { s->failed_pc=0x0c09fee8u; return 0; }
r[11]+=0x00000004u;
goto P_0c09feea;
P_0c09feea: /* original 7f10, guest PC 0x0c09feea */
if(!s->budget--) { s->failed_pc=0x0c09feeau; return 0; }
r[15]+=0x00000010u;
goto P_0c09feec;
P_0c09feec: /* original 4f26, guest PC 0x0c09feec */
if(!s->budget--) { s->failed_pc=0x0c09feecu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c09feee;
P_0c09feee: /* original 68f6, guest PC 0x0c09feee */
if(!s->budget--) { s->failed_pc=0x0c09feeeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c09fef0;
P_0c09fef0: /* original 69f6, guest PC 0x0c09fef0 */
if(!s->budget--) { s->failed_pc=0x0c09fef0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c09fef2;
P_0c09fef2: /* original 6af6, guest PC 0x0c09fef2 */
if(!s->budget--) { s->failed_pc=0x0c09fef2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c09fef4;
P_0c09fef4: /* original 6bf6, guest PC 0x0c09fef4 */
if(!s->budget--) { s->failed_pc=0x0c09fef4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c09fef6;
P_0c09fef6: /* original 6cf6, guest PC 0x0c09fef6 */
if(!s->budget--) { s->failed_pc=0x0c09fef6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c09fef8;
P_0c09fef8: /* original 6df6, guest PC 0x0c09fef8 */
if(!s->budget--) { s->failed_pc=0x0c09fef8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c09fefa;
P_0c09fefa: /* original 000b, guest PC 0x0c09fefa */
if(!s->budget--) { s->failed_pc=0x0c09fefau; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c09fefc: /* original 6ef6, guest PC 0x0c09fefc */
if(!s->budget--) { s->failed_pc=0x0c09fefcu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c09fefeu,s,ram);
P_0c0a2e06: /* original d359, guest PC 0x0c0a2e06 */
if(!s->budget--) { s->failed_pc=0x0c0a2e06u; return 0; }
r[3]=read(ram,0x0c0a2f6cu,4);
goto P_0c0a2e08;
P_0c0a2e08: /* original 6643, guest PC 0x0c0a2e08 */
if(!s->budget--) { s->failed_pc=0x0c0a2e08u; return 0; }
r[6]=r[4];
goto P_0c0a2e0a;
P_0c0a2e0a: /* original 4608, guest PC 0x0c0a2e0a */
if(!s->budget--) { s->failed_pc=0x0c0a2e0au; return 0; }
r[6]<<=2;
goto P_0c0a2e0c;
P_0c0a2e0c: /* original 363c, guest PC 0x0c0a2e0c */
if(!s->budget--) { s->failed_pc=0x0c0a2e0cu; return 0; }
r[6]+=r[3];
goto P_0c0a2e0e;
P_0c0a2e0e: /* original 6262, guest PC 0x0c0a2e0e */
if(!s->budget--) { s->failed_pc=0x0c0a2e0eu; return 0; }
tmp=read(ram,r[6],4);
r[2]=tmp;
goto P_0c0a2e10;
P_0c0a2e10: /* original 2228, guest PC 0x0c0a2e10 */
if(!s->budget--) { s->failed_pc=0x0c0a2e10u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c0a2e12;
P_0c0a2e12: /* original 8b09, guest PC 0x0c0a2e12 */
if(!s->budget--) { s->failed_pc=0x0c0a2e12u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a2e28; }
goto P_0c0a2e14;
P_0c0a2e14: /* original 6062, guest PC 0x0c0a2e14 */
if(!s->budget--) { s->failed_pc=0x0c0a2e14u; return 0; }
tmp=read(ram,r[6],4);
r[0]=tmp;
goto P_0c0a2e16;
P_0c0a2e16: /* original 88ff, guest PC 0x0c0a2e16 */
if(!s->budget--) { s->failed_pc=0x0c0a2e16u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c0a2e18;
P_0c0a2e18: /* original 8906, guest PC 0x0c0a2e18 */
if(!s->budget--) { s->failed_pc=0x0c0a2e18u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a2e28; }
goto P_0c0a2e1a;
P_0c0a2e1a: /* original 5051, guest PC 0x0c0a2e1a */
if(!s->budget--) { s->failed_pc=0x0c0a2e1au; return 0; }
r[0]=read(ram,r[5]+4,4);
goto P_0c0a2e1c;
P_0c0a2e1c: /* original c801, guest PC 0x0c0a2e1c */
if(!s->budget--) { s->failed_pc=0x0c0a2e1cu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&1u)==0)!=0);
goto P_0c0a2e1e;
P_0c0a2e1e: /* original 8901, guest PC 0x0c0a2e1e */
if(!s->budget--) { s->failed_pc=0x0c0a2e1eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a2e24; }
goto P_0c0a2e20;
P_0c0a2e20: /* original a002, guest PC 0x0c0a2e20 */
if(!s->budget--) { s->failed_pc=0x0c0a2e20u; return 0; }
write(ram,r[6],r[5],4);
goto P_0c0a2e28;
P_0c0a2e22: /* original 2652, guest PC 0x0c0a2e22 */
if(!s->budget--) { s->failed_pc=0x0c0a2e22u; return 0; }
write(ram,r[6],r[5],4);
goto P_0c0a2e24;
P_0c0a2e24: /* original 6152, guest PC 0x0c0a2e24 */
if(!s->budget--) { s->failed_pc=0x0c0a2e24u; return 0; }
tmp=read(ram,r[5],4);
r[1]=tmp;
goto P_0c0a2e26;
P_0c0a2e26: /* original 2612, guest PC 0x0c0a2e26 */
if(!s->budget--) { s->failed_pc=0x0c0a2e26u; return 0; }
write(ram,r[6],r[1],4);
goto P_0c0a2e28;
P_0c0a2e28: /* original 000b, guest PC 0x0c0a2e28 */
if(!s->budget--) { s->failed_pc=0x0c0a2e28u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c0a2e2a: /* original 0009, guest PC 0x0c0a2e2a */
if(!s->budget--) { s->failed_pc=0x0c0a2e2au; return 0; }
goto P_0c0a2e2c;
P_0c0a2e2c: /* original d34f, guest PC 0x0c0a2e2c */
if(!s->budget--) { s->failed_pc=0x0c0a2e2cu; return 0; }
r[3]=read(ram,0x0c0a2f6cu,4);
goto P_0c0a2e2e;
P_0c0a2e2e: /* original 6543, guest PC 0x0c0a2e2e */
if(!s->budget--) { s->failed_pc=0x0c0a2e2eu; return 0; }
r[5]=r[4];
goto P_0c0a2e30;
P_0c0a2e30: /* original 4508, guest PC 0x0c0a2e30 */
if(!s->budget--) { s->failed_pc=0x0c0a2e30u; return 0; }
r[5]<<=2;
goto P_0c0a2e32;
P_0c0a2e32: /* original 353c, guest PC 0x0c0a2e32 */
if(!s->budget--) { s->failed_pc=0x0c0a2e32u; return 0; }
r[5]+=r[3];
goto P_0c0a2e34;
P_0c0a2e34: /* original 6252, guest PC 0x0c0a2e34 */
if(!s->budget--) { s->failed_pc=0x0c0a2e34u; return 0; }
tmp=read(ram,r[5],4);
r[2]=tmp;
goto P_0c0a2e36;
P_0c0a2e36: /* original 2228, guest PC 0x0c0a2e36 */
if(!s->budget--) { s->failed_pc=0x0c0a2e36u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c0a2e38;
P_0c0a2e38: /* original 8904, guest PC 0x0c0a2e38 */
if(!s->budget--) { s->failed_pc=0x0c0a2e38u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a2e44; }
goto P_0c0a2e3a;
P_0c0a2e3a: /* original 6052, guest PC 0x0c0a2e3a */
if(!s->budget--) { s->failed_pc=0x0c0a2e3au; return 0; }
tmp=read(ram,r[5],4);
r[0]=tmp;
goto P_0c0a2e3c;
P_0c0a2e3c: /* original 88ff, guest PC 0x0c0a2e3c */
if(!s->budget--) { s->failed_pc=0x0c0a2e3cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c0a2e3e;
P_0c0a2e3e: /* original 8901, guest PC 0x0c0a2e3e */
if(!s->budget--) { s->failed_pc=0x0c0a2e3eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a2e44; }
goto P_0c0a2e40;
P_0c0a2e40: /* original e100, guest PC 0x0c0a2e40 */
if(!s->budget--) { s->failed_pc=0x0c0a2e40u; return 0; }
r[1]=0x00000000u;
goto P_0c0a2e42;
P_0c0a2e42: /* original 2512, guest PC 0x0c0a2e42 */
if(!s->budget--) { s->failed_pc=0x0c0a2e42u; return 0; }
write(ram,r[5],r[1],4);
goto P_0c0a2e44;
P_0c0a2e44: /* original 000b, guest PC 0x0c0a2e44 */
if(!s->budget--) { s->failed_pc=0x0c0a2e44u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c0a2e46: /* original 0009, guest PC 0x0c0a2e46 */
if(!s->budget--) { s->failed_pc=0x0c0a2e46u; return 0; }
return vf3_matrix_family(0x0c0a2e48u,s,ram);
P_0c0a3414: /* original 4f22, guest PC 0x0c0a3414 */
if(!s->budget--) { s->failed_pc=0x0c0a3414u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0a3416;
P_0c0a3416: /* original bd09, guest PC 0x0c0a3416 */
if(!s->budget--) { s->failed_pc=0x0c0a3416u; return 0; }
target=0x0c0a2e2cu; r[16]=0x0c0a341au;
r[4]=0x0000005fu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a341au) { target=s->pc; goto dispatch; }
goto P_0c0a341a;
P_0c0a3418: /* original e45f, guest PC 0x0c0a3418 */
if(!s->budget--) { s->failed_pc=0x0c0a3418u; return 0; }
r[4]=0x0000005fu;
goto P_0c0a341a;
P_0c0a341a: /* original bd07, guest PC 0x0c0a341a */
if(!s->budget--) { s->failed_pc=0x0c0a341au; return 0; }
target=0x0c0a2e2cu; r[16]=0x0c0a341eu;
r[4]=0x00000060u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a341eu) { target=s->pc; goto dispatch; }
goto P_0c0a341e;
P_0c0a341c: /* original e460, guest PC 0x0c0a341c */
if(!s->budget--) { s->failed_pc=0x0c0a341cu; return 0; }
r[4]=0x00000060u;
goto P_0c0a341e;
P_0c0a341e: /* original bd05, guest PC 0x0c0a341e */
if(!s->budget--) { s->failed_pc=0x0c0a341eu; return 0; }
target=0x0c0a2e2cu; r[16]=0x0c0a3422u;
r[4]=0x00000061u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a3422u) { target=s->pc; goto dispatch; }
goto P_0c0a3422;
P_0c0a3420: /* original e461, guest PC 0x0c0a3420 */
if(!s->budget--) { s->failed_pc=0x0c0a3420u; return 0; }
r[4]=0x00000061u;
goto P_0c0a3422;
P_0c0a3422: /* original bd03, guest PC 0x0c0a3422 */
if(!s->budget--) { s->failed_pc=0x0c0a3422u; return 0; }
target=0x0c0a2e2cu; r[16]=0x0c0a3426u;
r[4]=0x00000062u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a3426u) { target=s->pc; goto dispatch; }
goto P_0c0a3426;
P_0c0a3424: /* original e462, guest PC 0x0c0a3424 */
if(!s->budget--) { s->failed_pc=0x0c0a3424u; return 0; }
r[4]=0x00000062u;
goto P_0c0a3426;
P_0c0a3426: /* original bd01, guest PC 0x0c0a3426 */
if(!s->budget--) { s->failed_pc=0x0c0a3426u; return 0; }
target=0x0c0a2e2cu; r[16]=0x0c0a342au;
r[4]=0x00000063u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a342au) { target=s->pc; goto dispatch; }
goto P_0c0a342a;
P_0c0a3428: /* original e463, guest PC 0x0c0a3428 */
if(!s->budget--) { s->failed_pc=0x0c0a3428u; return 0; }
r[4]=0x00000063u;
goto P_0c0a342a;
P_0c0a342a: /* original bcff, guest PC 0x0c0a342a */
if(!s->budget--) { s->failed_pc=0x0c0a342au; return 0; }
target=0x0c0a2e2cu; r[16]=0x0c0a342eu;
r[4]=0x00000064u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a342eu) { target=s->pc; goto dispatch; }
goto P_0c0a342e;
P_0c0a342c: /* original e464, guest PC 0x0c0a342c */
if(!s->budget--) { s->failed_pc=0x0c0a342cu; return 0; }
r[4]=0x00000064u;
goto P_0c0a342e;
P_0c0a342e: /* original bcfd, guest PC 0x0c0a342e */
if(!s->budget--) { s->failed_pc=0x0c0a342eu; return 0; }
target=0x0c0a2e2cu; r[16]=0x0c0a3432u;
r[4]=0x00000065u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a3432u) { target=s->pc; goto dispatch; }
goto P_0c0a3432;
P_0c0a3430: /* original e465, guest PC 0x0c0a3430 */
if(!s->budget--) { s->failed_pc=0x0c0a3430u; return 0; }
r[4]=0x00000065u;
goto P_0c0a3432;
P_0c0a3432: /* original bcfb, guest PC 0x0c0a3432 */
if(!s->budget--) { s->failed_pc=0x0c0a3432u; return 0; }
target=0x0c0a2e2cu; r[16]=0x0c0a3436u;
r[4]=0x00000066u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a3436u) { target=s->pc; goto dispatch; }
goto P_0c0a3436;
P_0c0a3434: /* original e466, guest PC 0x0c0a3434 */
if(!s->budget--) { s->failed_pc=0x0c0a3434u; return 0; }
r[4]=0x00000066u;
goto P_0c0a3436;
P_0c0a3436: /* original bcf9, guest PC 0x0c0a3436 */
if(!s->budget--) { s->failed_pc=0x0c0a3436u; return 0; }
target=0x0c0a2e2cu; r[16]=0x0c0a343au;
r[4]=0x00000067u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a343au) { target=s->pc; goto dispatch; }
goto P_0c0a343a;
P_0c0a3438: /* original e467, guest PC 0x0c0a3438 */
if(!s->budget--) { s->failed_pc=0x0c0a3438u; return 0; }
r[4]=0x00000067u;
goto P_0c0a343a;
P_0c0a343a: /* original bcf7, guest PC 0x0c0a343a */
if(!s->budget--) { s->failed_pc=0x0c0a343au; return 0; }
target=0x0c0a2e2cu; r[16]=0x0c0a343eu;
r[4]=0x00000068u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a343eu) { target=s->pc; goto dispatch; }
goto P_0c0a343e;
P_0c0a343c: /* original e468, guest PC 0x0c0a343c */
if(!s->budget--) { s->failed_pc=0x0c0a343cu; return 0; }
r[4]=0x00000068u;
goto P_0c0a343e;
P_0c0a343e: /* original bcf5, guest PC 0x0c0a343e */
if(!s->budget--) { s->failed_pc=0x0c0a343eu; return 0; }
target=0x0c0a2e2cu; r[16]=0x0c0a3442u;
r[4]=0x00000069u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a3442u) { target=s->pc; goto dispatch; }
goto P_0c0a3442;
P_0c0a3440: /* original e469, guest PC 0x0c0a3440 */
if(!s->budget--) { s->failed_pc=0x0c0a3440u; return 0; }
r[4]=0x00000069u;
goto P_0c0a3442;
P_0c0a3442: /* original bcf3, guest PC 0x0c0a3442 */
if(!s->budget--) { s->failed_pc=0x0c0a3442u; return 0; }
target=0x0c0a2e2cu; r[16]=0x0c0a3446u;
r[4]=0x0000006au;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a3446u) { target=s->pc; goto dispatch; }
goto P_0c0a3446;
P_0c0a3444: /* original e46a, guest PC 0x0c0a3444 */
if(!s->budget--) { s->failed_pc=0x0c0a3444u; return 0; }
r[4]=0x0000006au;
goto P_0c0a3446;
P_0c0a3446: /* original bcf1, guest PC 0x0c0a3446 */
if(!s->budget--) { s->failed_pc=0x0c0a3446u; return 0; }
target=0x0c0a2e2cu; r[16]=0x0c0a344au;
r[4]=0x0000006bu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a344au) { target=s->pc; goto dispatch; }
goto P_0c0a344a;
P_0c0a3448: /* original e46b, guest PC 0x0c0a3448 */
if(!s->budget--) { s->failed_pc=0x0c0a3448u; return 0; }
r[4]=0x0000006bu;
goto P_0c0a344a;
P_0c0a344a: /* original bcef, guest PC 0x0c0a344a */
if(!s->budget--) { s->failed_pc=0x0c0a344au; return 0; }
target=0x0c0a2e2cu; r[16]=0x0c0a344eu;
r[4]=0x0000006cu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a344eu) { target=s->pc; goto dispatch; }
goto P_0c0a344e;
P_0c0a344c: /* original e46c, guest PC 0x0c0a344c */
if(!s->budget--) { s->failed_pc=0x0c0a344cu; return 0; }
r[4]=0x0000006cu;
goto P_0c0a344e;
P_0c0a344e: /* original bced, guest PC 0x0c0a344e */
if(!s->budget--) { s->failed_pc=0x0c0a344eu; return 0; }
target=0x0c0a2e2cu; r[16]=0x0c0a3452u;
r[4]=0x00000004u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a3452u) { target=s->pc; goto dispatch; }
goto P_0c0a3452;
P_0c0a3450: /* original e404, guest PC 0x0c0a3450 */
if(!s->budget--) { s->failed_pc=0x0c0a3450u; return 0; }
r[4]=0x00000004u;
goto P_0c0a3452;
P_0c0a3452: /* original bceb, guest PC 0x0c0a3452 */
if(!s->budget--) { s->failed_pc=0x0c0a3452u; return 0; }
target=0x0c0a2e2cu; r[16]=0x0c0a3456u;
r[4]=0x00000005u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a3456u) { target=s->pc; goto dispatch; }
goto P_0c0a3456;
P_0c0a3454: /* original e405, guest PC 0x0c0a3454 */
if(!s->budget--) { s->failed_pc=0x0c0a3454u; return 0; }
r[4]=0x00000005u;
goto P_0c0a3456;
P_0c0a3456: /* original bce9, guest PC 0x0c0a3456 */
if(!s->budget--) { s->failed_pc=0x0c0a3456u; return 0; }
target=0x0c0a2e2cu; r[16]=0x0c0a345au;
r[4]=0x00000072u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a345au) { target=s->pc; goto dispatch; }
goto P_0c0a345a;
P_0c0a3458: /* original e472, guest PC 0x0c0a3458 */
if(!s->budget--) { s->failed_pc=0x0c0a3458u; return 0; }
r[4]=0x00000072u;
goto P_0c0a345a;
P_0c0a345a: /* original bce7, guest PC 0x0c0a345a */
if(!s->budget--) { s->failed_pc=0x0c0a345au; return 0; }
target=0x0c0a2e2cu; r[16]=0x0c0a345eu;
r[4]=0x00000071u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a345eu) { target=s->pc; goto dispatch; }
goto P_0c0a345e;
P_0c0a345c: /* original e471, guest PC 0x0c0a345c */
if(!s->budget--) { s->failed_pc=0x0c0a345cu; return 0; }
r[4]=0x00000071u;
goto P_0c0a345e;
P_0c0a345e: /* original bce5, guest PC 0x0c0a345e */
if(!s->budget--) { s->failed_pc=0x0c0a345eu; return 0; }
target=0x0c0a2e2cu; r[16]=0x0c0a3462u;
r[4]=0x00000016u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a3462u) { target=s->pc; goto dispatch; }
goto P_0c0a3462;
P_0c0a3460: /* original e416, guest PC 0x0c0a3460 */
if(!s->budget--) { s->failed_pc=0x0c0a3460u; return 0; }
r[4]=0x00000016u;
goto P_0c0a3462;
P_0c0a3462: /* original bce3, guest PC 0x0c0a3462 */
if(!s->budget--) { s->failed_pc=0x0c0a3462u; return 0; }
target=0x0c0a2e2cu; r[16]=0x0c0a3466u;
r[4]=0x00000018u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a3466u) { target=s->pc; goto dispatch; }
goto P_0c0a3466;
P_0c0a3464: /* original e418, guest PC 0x0c0a3464 */
if(!s->budget--) { s->failed_pc=0x0c0a3464u; return 0; }
r[4]=0x00000018u;
goto P_0c0a3466;
P_0c0a3466: /* original bce1, guest PC 0x0c0a3466 */
if(!s->budget--) { s->failed_pc=0x0c0a3466u; return 0; }
target=0x0c0a2e2cu; r[16]=0x0c0a346au;
r[4]=0x00000019u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a346au) { target=s->pc; goto dispatch; }
goto P_0c0a346a;
P_0c0a3468: /* original e419, guest PC 0x0c0a3468 */
if(!s->budget--) { s->failed_pc=0x0c0a3468u; return 0; }
r[4]=0x00000019u;
goto P_0c0a346a;
P_0c0a346a: /* original bcdf, guest PC 0x0c0a346a */
if(!s->budget--) { s->failed_pc=0x0c0a346au; return 0; }
target=0x0c0a2e2cu; r[16]=0x0c0a346eu;
r[4]=0x0000001au;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a346eu) { target=s->pc; goto dispatch; }
goto P_0c0a346e;
P_0c0a346c: /* original e41a, guest PC 0x0c0a346c */
if(!s->budget--) { s->failed_pc=0x0c0a346cu; return 0; }
r[4]=0x0000001au;
goto P_0c0a346e;
P_0c0a346e: /* original bcdd, guest PC 0x0c0a346e */
if(!s->budget--) { s->failed_pc=0x0c0a346eu; return 0; }
target=0x0c0a2e2cu; r[16]=0x0c0a3472u;
r[4]=0x0000001cu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a3472u) { target=s->pc; goto dispatch; }
goto P_0c0a3472;
P_0c0a3470: /* original e41c, guest PC 0x0c0a3470 */
if(!s->budget--) { s->failed_pc=0x0c0a3470u; return 0; }
r[4]=0x0000001cu;
goto P_0c0a3472;
P_0c0a3472: /* original bcdb, guest PC 0x0c0a3472 */
if(!s->budget--) { s->failed_pc=0x0c0a3472u; return 0; }
target=0x0c0a2e2cu; r[16]=0x0c0a3476u;
r[4]=0x0000001du;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a3476u) { target=s->pc; goto dispatch; }
goto P_0c0a3476;
P_0c0a3474: /* original e41d, guest PC 0x0c0a3474 */
if(!s->budget--) { s->failed_pc=0x0c0a3474u; return 0; }
r[4]=0x0000001du;
goto P_0c0a3476;
P_0c0a3476: /* original bcd9, guest PC 0x0c0a3476 */
if(!s->budget--) { s->failed_pc=0x0c0a3476u; return 0; }
target=0x0c0a2e2cu; r[16]=0x0c0a347au;
r[4]=0x0000001eu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a347au) { target=s->pc; goto dispatch; }
goto P_0c0a347a;
P_0c0a3478: /* original e41e, guest PC 0x0c0a3478 */
if(!s->budget--) { s->failed_pc=0x0c0a3478u; return 0; }
r[4]=0x0000001eu;
goto P_0c0a347a;
P_0c0a347a: /* original bcd7, guest PC 0x0c0a347a */
if(!s->budget--) { s->failed_pc=0x0c0a347au; return 0; }
target=0x0c0a2e2cu; r[16]=0x0c0a347eu;
r[4]=0x0000001fu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a347eu) { target=s->pc; goto dispatch; }
goto P_0c0a347e;
P_0c0a347c: /* original e41f, guest PC 0x0c0a347c */
if(!s->budget--) { s->failed_pc=0x0c0a347cu; return 0; }
r[4]=0x0000001fu;
goto P_0c0a347e;
P_0c0a347e: /* original bcd5, guest PC 0x0c0a347e */
if(!s->budget--) { s->failed_pc=0x0c0a347eu; return 0; }
target=0x0c0a2e2cu; r[16]=0x0c0a3482u;
r[4]=0x00000020u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a3482u) { target=s->pc; goto dispatch; }
goto P_0c0a3482;
P_0c0a3480: /* original e420, guest PC 0x0c0a3480 */
if(!s->budget--) { s->failed_pc=0x0c0a3480u; return 0; }
r[4]=0x00000020u;
goto P_0c0a3482;
P_0c0a3482: /* original bcd3, guest PC 0x0c0a3482 */
if(!s->budget--) { s->failed_pc=0x0c0a3482u; return 0; }
target=0x0c0a2e2cu; r[16]=0x0c0a3486u;
r[4]=0x00000022u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a3486u) { target=s->pc; goto dispatch; }
goto P_0c0a3486;
P_0c0a3484: /* original e422, guest PC 0x0c0a3484 */
if(!s->budget--) { s->failed_pc=0x0c0a3484u; return 0; }
r[4]=0x00000022u;
goto P_0c0a3486;
P_0c0a3486: /* original bcd1, guest PC 0x0c0a3486 */
if(!s->budget--) { s->failed_pc=0x0c0a3486u; return 0; }
target=0x0c0a2e2cu; r[16]=0x0c0a348au;
r[4]=0x00000024u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a348au) { target=s->pc; goto dispatch; }
goto P_0c0a348a;
P_0c0a3488: /* original e424, guest PC 0x0c0a3488 */
if(!s->budget--) { s->failed_pc=0x0c0a3488u; return 0; }
r[4]=0x00000024u;
goto P_0c0a348a;
P_0c0a348a: /* original bccf, guest PC 0x0c0a348a */
if(!s->budget--) { s->failed_pc=0x0c0a348au; return 0; }
target=0x0c0a2e2cu; r[16]=0x0c0a348eu;
r[4]=0x00000025u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a348eu) { target=s->pc; goto dispatch; }
goto P_0c0a348e;
P_0c0a348c: /* original e425, guest PC 0x0c0a348c */
if(!s->budget--) { s->failed_pc=0x0c0a348cu; return 0; }
r[4]=0x00000025u;
goto P_0c0a348e;
P_0c0a348e: /* original bccd, guest PC 0x0c0a348e */
if(!s->budget--) { s->failed_pc=0x0c0a348eu; return 0; }
target=0x0c0a2e2cu; r[16]=0x0c0a3492u;
r[4]=0x00000026u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a3492u) { target=s->pc; goto dispatch; }
goto P_0c0a3492;
P_0c0a3490: /* original e426, guest PC 0x0c0a3490 */
if(!s->budget--) { s->failed_pc=0x0c0a3490u; return 0; }
r[4]=0x00000026u;
goto P_0c0a3492;
P_0c0a3492: /* original bccb, guest PC 0x0c0a3492 */
if(!s->budget--) { s->failed_pc=0x0c0a3492u; return 0; }
target=0x0c0a2e2cu; r[16]=0x0c0a3496u;
r[4]=0x00000027u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a3496u) { target=s->pc; goto dispatch; }
goto P_0c0a3496;
P_0c0a3494: /* original e427, guest PC 0x0c0a3494 */
if(!s->budget--) { s->failed_pc=0x0c0a3494u; return 0; }
r[4]=0x00000027u;
goto P_0c0a3496;
P_0c0a3496: /* original bcc9, guest PC 0x0c0a3496 */
if(!s->budget--) { s->failed_pc=0x0c0a3496u; return 0; }
target=0x0c0a2e2cu; r[16]=0x0c0a349au;
r[4]=0x00000028u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a349au) { target=s->pc; goto dispatch; }
goto P_0c0a349a;
P_0c0a3498: /* original e428, guest PC 0x0c0a3498 */
if(!s->budget--) { s->failed_pc=0x0c0a3498u; return 0; }
r[4]=0x00000028u;
goto P_0c0a349a;
P_0c0a349a: /* original bcc7, guest PC 0x0c0a349a */
if(!s->budget--) { s->failed_pc=0x0c0a349au; return 0; }
target=0x0c0a2e2cu; r[16]=0x0c0a349eu;
r[4]=0x0000002au;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a349eu) { target=s->pc; goto dispatch; }
goto P_0c0a349e;
P_0c0a349c: /* original e42a, guest PC 0x0c0a349c */
if(!s->budget--) { s->failed_pc=0x0c0a349cu; return 0; }
r[4]=0x0000002au;
goto P_0c0a349e;
P_0c0a349e: /* original bcc5, guest PC 0x0c0a349e */
if(!s->budget--) { s->failed_pc=0x0c0a349eu; return 0; }
target=0x0c0a2e2cu; r[16]=0x0c0a34a2u;
r[4]=0x0000002bu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a34a2u) { target=s->pc; goto dispatch; }
goto P_0c0a34a2;
P_0c0a34a0: /* original e42b, guest PC 0x0c0a34a0 */
if(!s->budget--) { s->failed_pc=0x0c0a34a0u; return 0; }
r[4]=0x0000002bu;
goto P_0c0a34a2;
P_0c0a34a2: /* original bcc3, guest PC 0x0c0a34a2 */
if(!s->budget--) { s->failed_pc=0x0c0a34a2u; return 0; }
target=0x0c0a2e2cu; r[16]=0x0c0a34a6u;
r[4]=0x0000002cu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a34a6u) { target=s->pc; goto dispatch; }
goto P_0c0a34a6;
P_0c0a34a4: /* original e42c, guest PC 0x0c0a34a4 */
if(!s->budget--) { s->failed_pc=0x0c0a34a4u; return 0; }
r[4]=0x0000002cu;
goto P_0c0a34a6;
P_0c0a34a6: /* original bcc1, guest PC 0x0c0a34a6 */
if(!s->budget--) { s->failed_pc=0x0c0a34a6u; return 0; }
target=0x0c0a2e2cu; r[16]=0x0c0a34aau;
r[4]=0x0000002du;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a34aau) { target=s->pc; goto dispatch; }
goto P_0c0a34aa;
P_0c0a34a8: /* original e42d, guest PC 0x0c0a34a8 */
if(!s->budget--) { s->failed_pc=0x0c0a34a8u; return 0; }
r[4]=0x0000002du;
goto P_0c0a34aa;
P_0c0a34aa: /* original bcbf, guest PC 0x0c0a34aa */
if(!s->budget--) { s->failed_pc=0x0c0a34aau; return 0; }
target=0x0c0a2e2cu; r[16]=0x0c0a34aeu;
r[4]=0x0000002eu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a34aeu) { target=s->pc; goto dispatch; }
goto P_0c0a34ae;
P_0c0a34ac: /* original e42e, guest PC 0x0c0a34ac */
if(!s->budget--) { s->failed_pc=0x0c0a34acu; return 0; }
r[4]=0x0000002eu;
goto P_0c0a34ae;
P_0c0a34ae: /* original bcbd, guest PC 0x0c0a34ae */
if(!s->budget--) { s->failed_pc=0x0c0a34aeu; return 0; }
target=0x0c0a2e2cu; r[16]=0x0c0a34b2u;
r[4]=0x00000032u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a34b2u) { target=s->pc; goto dispatch; }
goto P_0c0a34b2;
P_0c0a34b0: /* original e432, guest PC 0x0c0a34b0 */
if(!s->budget--) { s->failed_pc=0x0c0a34b0u; return 0; }
r[4]=0x00000032u;
goto P_0c0a34b2;
P_0c0a34b2: /* original bcbb, guest PC 0x0c0a34b2 */
if(!s->budget--) { s->failed_pc=0x0c0a34b2u; return 0; }
target=0x0c0a2e2cu; r[16]=0x0c0a34b6u;
r[4]=0x00000042u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a34b6u) { target=s->pc; goto dispatch; }
goto P_0c0a34b6;
P_0c0a34b4: /* original e442, guest PC 0x0c0a34b4 */
if(!s->budget--) { s->failed_pc=0x0c0a34b4u; return 0; }
r[4]=0x00000042u;
goto P_0c0a34b6;
P_0c0a34b6: /* original bcb9, guest PC 0x0c0a34b6 */
if(!s->budget--) { s->failed_pc=0x0c0a34b6u; return 0; }
target=0x0c0a2e2cu; r[16]=0x0c0a34bau;
r[4]=0x00000044u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a34bau) { target=s->pc; goto dispatch; }
goto P_0c0a34ba;
P_0c0a34b8: /* original e444, guest PC 0x0c0a34b8 */
if(!s->budget--) { s->failed_pc=0x0c0a34b8u; return 0; }
r[4]=0x00000044u;
goto P_0c0a34ba;
P_0c0a34ba: /* original bcb7, guest PC 0x0c0a34ba */
if(!s->budget--) { s->failed_pc=0x0c0a34bau; return 0; }
target=0x0c0a2e2cu; r[16]=0x0c0a34beu;
r[4]=0x00000046u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a34beu) { target=s->pc; goto dispatch; }
goto P_0c0a34be;
P_0c0a34bc: /* original e446, guest PC 0x0c0a34bc */
if(!s->budget--) { s->failed_pc=0x0c0a34bcu; return 0; }
r[4]=0x00000046u;
goto P_0c0a34be;
P_0c0a34be: /* original bcb5, guest PC 0x0c0a34be */
if(!s->budget--) { s->failed_pc=0x0c0a34beu; return 0; }
target=0x0c0a2e2cu; r[16]=0x0c0a34c2u;
r[4]=0x00000048u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a34c2u) { target=s->pc; goto dispatch; }
goto P_0c0a34c2;
P_0c0a34c0: /* original e448, guest PC 0x0c0a34c0 */
if(!s->budget--) { s->failed_pc=0x0c0a34c0u; return 0; }
r[4]=0x00000048u;
goto P_0c0a34c2;
P_0c0a34c2: /* original bcb3, guest PC 0x0c0a34c2 */
if(!s->budget--) { s->failed_pc=0x0c0a34c2u; return 0; }
target=0x0c0a2e2cu; r[16]=0x0c0a34c6u;
r[4]=0x0000004au;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a34c6u) { target=s->pc; goto dispatch; }
goto P_0c0a34c6;
P_0c0a34c4: /* original e44a, guest PC 0x0c0a34c4 */
if(!s->budget--) { s->failed_pc=0x0c0a34c4u; return 0; }
r[4]=0x0000004au;
goto P_0c0a34c6;
P_0c0a34c6: /* original bcb1, guest PC 0x0c0a34c6 */
if(!s->budget--) { s->failed_pc=0x0c0a34c6u; return 0; }
target=0x0c0a2e2cu; r[16]=0x0c0a34cau;
r[4]=0x0000004cu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a34cau) { target=s->pc; goto dispatch; }
goto P_0c0a34ca;
P_0c0a34c8: /* original e44c, guest PC 0x0c0a34c8 */
if(!s->budget--) { s->failed_pc=0x0c0a34c8u; return 0; }
r[4]=0x0000004cu;
goto P_0c0a34ca;
P_0c0a34ca: /* original bcaf, guest PC 0x0c0a34ca */
if(!s->budget--) { s->failed_pc=0x0c0a34cau; return 0; }
target=0x0c0a2e2cu; r[16]=0x0c0a34ceu;
r[4]=0x0000004eu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a34ceu) { target=s->pc; goto dispatch; }
goto P_0c0a34ce;
P_0c0a34cc: /* original e44e, guest PC 0x0c0a34cc */
if(!s->budget--) { s->failed_pc=0x0c0a34ccu; return 0; }
r[4]=0x0000004eu;
goto P_0c0a34ce;
P_0c0a34ce: /* original bcad, guest PC 0x0c0a34ce */
if(!s->budget--) { s->failed_pc=0x0c0a34ceu; return 0; }
target=0x0c0a2e2cu; r[16]=0x0c0a34d2u;
r[4]=0x0000006du;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a34d2u) { target=s->pc; goto dispatch; }
goto P_0c0a34d2;
P_0c0a34d0: /* original e46d, guest PC 0x0c0a34d0 */
if(!s->budget--) { s->failed_pc=0x0c0a34d0u; return 0; }
r[4]=0x0000006du;
goto P_0c0a34d2;
P_0c0a34d2: /* original bcab, guest PC 0x0c0a34d2 */
if(!s->budget--) { s->failed_pc=0x0c0a34d2u; return 0; }
target=0x0c0a2e2cu; r[16]=0x0c0a34d6u;
r[4]=0x0000006eu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a34d6u) { target=s->pc; goto dispatch; }
goto P_0c0a34d6;
P_0c0a34d4: /* original e46e, guest PC 0x0c0a34d4 */
if(!s->budget--) { s->failed_pc=0x0c0a34d4u; return 0; }
r[4]=0x0000006eu;
goto P_0c0a34d6;
P_0c0a34d6: /* original e46f, guest PC 0x0c0a34d6 */
if(!s->budget--) { s->failed_pc=0x0c0a34d6u; return 0; }
r[4]=0x0000006fu;
goto P_0c0a34d8;
P_0c0a34d8: /* original aca8, guest PC 0x0c0a34d8 */
if(!s->budget--) { s->failed_pc=0x0c0a34d8u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a2e2c;
P_0c0a34da: /* original 4f26, guest PC 0x0c0a34da */
if(!s->budget--) { s->failed_pc=0x0c0a34dau; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
return vf3_matrix_family(0x0c0a34dcu,s,ram);
P_0c0a3696: /* original 4f22, guest PC 0x0c0a3696 */
if(!s->budget--) { s->failed_pc=0x0c0a3696u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0a3698;
P_0c0a3698: /* original 9440, guest PC 0x0c0a3698 */
if(!s->budget--) { s->failed_pc=0x0c0a3698u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a371cu,2);
goto P_0c0a369a;
P_0c0a369a: /* original bbc7, guest PC 0x0c0a369a */
if(!s->budget--) { s->failed_pc=0x0c0a369au; return 0; }
target=0x0c0a2e2cu; r[16]=0x0c0a369eu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a369eu) { target=s->pc; goto dispatch; }
goto P_0c0a369e;
P_0c0a369c: /* original 0009, guest PC 0x0c0a369c */
if(!s->budget--) { s->failed_pc=0x0c0a369cu; return 0; }
goto P_0c0a369e;
P_0c0a369e: /* original 943e, guest PC 0x0c0a369e */
if(!s->budget--) { s->failed_pc=0x0c0a369eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a371eu,2);
goto P_0c0a36a0;
P_0c0a36a0: /* original bbc4, guest PC 0x0c0a36a0 */
if(!s->budget--) { s->failed_pc=0x0c0a36a0u; return 0; }
target=0x0c0a2e2cu; r[16]=0x0c0a36a4u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a36a4u) { target=s->pc; goto dispatch; }
goto P_0c0a36a4;
P_0c0a36a2: /* original 0009, guest PC 0x0c0a36a2 */
if(!s->budget--) { s->failed_pc=0x0c0a36a2u; return 0; }
goto P_0c0a36a4;
P_0c0a36a4: /* original 943c, guest PC 0x0c0a36a4 */
if(!s->budget--) { s->failed_pc=0x0c0a36a4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a3720u,2);
goto P_0c0a36a6;
P_0c0a36a6: /* original bbc1, guest PC 0x0c0a36a6 */
if(!s->budget--) { s->failed_pc=0x0c0a36a6u; return 0; }
target=0x0c0a2e2cu; r[16]=0x0c0a36aau;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a36aau) { target=s->pc; goto dispatch; }
goto P_0c0a36aa;
P_0c0a36a8: /* original 0009, guest PC 0x0c0a36a8 */
if(!s->budget--) { s->failed_pc=0x0c0a36a8u; return 0; }
goto P_0c0a36aa;
P_0c0a36aa: /* original 943a, guest PC 0x0c0a36aa */
if(!s->budget--) { s->failed_pc=0x0c0a36aau; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a3722u,2);
goto P_0c0a36ac;
P_0c0a36ac: /* original bbbe, guest PC 0x0c0a36ac */
if(!s->budget--) { s->failed_pc=0x0c0a36acu; return 0; }
target=0x0c0a2e2cu; r[16]=0x0c0a36b0u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a36b0u) { target=s->pc; goto dispatch; }
goto P_0c0a36b0;
P_0c0a36ae: /* original 0009, guest PC 0x0c0a36ae */
if(!s->budget--) { s->failed_pc=0x0c0a36aeu; return 0; }
goto P_0c0a36b0;
P_0c0a36b0: /* original 9438, guest PC 0x0c0a36b0 */
if(!s->budget--) { s->failed_pc=0x0c0a36b0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a3724u,2);
goto P_0c0a36b2;
P_0c0a36b2: /* original bbbb, guest PC 0x0c0a36b2 */
if(!s->budget--) { s->failed_pc=0x0c0a36b2u; return 0; }
target=0x0c0a2e2cu; r[16]=0x0c0a36b6u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a36b6u) { target=s->pc; goto dispatch; }
goto P_0c0a36b6;
P_0c0a36b4: /* original 0009, guest PC 0x0c0a36b4 */
if(!s->budget--) { s->failed_pc=0x0c0a36b4u; return 0; }
goto P_0c0a36b6;
P_0c0a36b6: /* original 9436, guest PC 0x0c0a36b6 */
if(!s->budget--) { s->failed_pc=0x0c0a36b6u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a3726u,2);
goto P_0c0a36b8;
P_0c0a36b8: /* original bbb8, guest PC 0x0c0a36b8 */
if(!s->budget--) { s->failed_pc=0x0c0a36b8u; return 0; }
target=0x0c0a2e2cu; r[16]=0x0c0a36bcu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a36bcu) { target=s->pc; goto dispatch; }
goto P_0c0a36bc;
P_0c0a36ba: /* original 0009, guest PC 0x0c0a36ba */
if(!s->budget--) { s->failed_pc=0x0c0a36bau; return 0; }
goto P_0c0a36bc;
P_0c0a36bc: /* original 9434, guest PC 0x0c0a36bc */
if(!s->budget--) { s->failed_pc=0x0c0a36bcu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a3728u,2);
goto P_0c0a36be;
P_0c0a36be: /* original bbb5, guest PC 0x0c0a36be */
if(!s->budget--) { s->failed_pc=0x0c0a36beu; return 0; }
target=0x0c0a2e2cu; r[16]=0x0c0a36c2u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a36c2u) { target=s->pc; goto dispatch; }
goto P_0c0a36c2;
P_0c0a36c0: /* original 0009, guest PC 0x0c0a36c0 */
if(!s->budget--) { s->failed_pc=0x0c0a36c0u; return 0; }
goto P_0c0a36c2;
P_0c0a36c2: /* original 9432, guest PC 0x0c0a36c2 */
if(!s->budget--) { s->failed_pc=0x0c0a36c2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a372au,2);
goto P_0c0a36c4;
P_0c0a36c4: /* original bbb2, guest PC 0x0c0a36c4 */
if(!s->budget--) { s->failed_pc=0x0c0a36c4u; return 0; }
target=0x0c0a2e2cu; r[16]=0x0c0a36c8u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a36c8u) { target=s->pc; goto dispatch; }
goto P_0c0a36c8;
P_0c0a36c6: /* original 0009, guest PC 0x0c0a36c6 */
if(!s->budget--) { s->failed_pc=0x0c0a36c6u; return 0; }
goto P_0c0a36c8;
P_0c0a36c8: /* original 9430, guest PC 0x0c0a36c8 */
if(!s->budget--) { s->failed_pc=0x0c0a36c8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a372cu,2);
goto P_0c0a36ca;
P_0c0a36ca: /* original bbaf, guest PC 0x0c0a36ca */
if(!s->budget--) { s->failed_pc=0x0c0a36cau; return 0; }
target=0x0c0a2e2cu; r[16]=0x0c0a36ceu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a36ceu) { target=s->pc; goto dispatch; }
goto P_0c0a36ce;
P_0c0a36cc: /* original 0009, guest PC 0x0c0a36cc */
if(!s->budget--) { s->failed_pc=0x0c0a36ccu; return 0; }
goto P_0c0a36ce;
P_0c0a36ce: /* original 942e, guest PC 0x0c0a36ce */
if(!s->budget--) { s->failed_pc=0x0c0a36ceu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a372eu,2);
goto P_0c0a36d0;
P_0c0a36d0: /* original bbac, guest PC 0x0c0a36d0 */
if(!s->budget--) { s->failed_pc=0x0c0a36d0u; return 0; }
target=0x0c0a2e2cu; r[16]=0x0c0a36d4u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a36d4u) { target=s->pc; goto dispatch; }
goto P_0c0a36d4;
P_0c0a36d2: /* original 0009, guest PC 0x0c0a36d2 */
if(!s->budget--) { s->failed_pc=0x0c0a36d2u; return 0; }
goto P_0c0a36d4;
P_0c0a36d4: /* original 942c, guest PC 0x0c0a36d4 */
if(!s->budget--) { s->failed_pc=0x0c0a36d4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a3730u,2);
goto P_0c0a36d6;
P_0c0a36d6: /* original bba9, guest PC 0x0c0a36d6 */
if(!s->budget--) { s->failed_pc=0x0c0a36d6u; return 0; }
target=0x0c0a2e2cu; r[16]=0x0c0a36dau;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a36dau) { target=s->pc; goto dispatch; }
goto P_0c0a36da;
P_0c0a36d8: /* original 0009, guest PC 0x0c0a36d8 */
if(!s->budget--) { s->failed_pc=0x0c0a36d8u; return 0; }
goto P_0c0a36da;
P_0c0a36da: /* original 942a, guest PC 0x0c0a36da */
if(!s->budget--) { s->failed_pc=0x0c0a36dau; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a3732u,2);
goto P_0c0a36dc;
P_0c0a36dc: /* original bba6, guest PC 0x0c0a36dc */
if(!s->budget--) { s->failed_pc=0x0c0a36dcu; return 0; }
target=0x0c0a2e2cu; r[16]=0x0c0a36e0u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a36e0u) { target=s->pc; goto dispatch; }
goto P_0c0a36e0;
P_0c0a36de: /* original 0009, guest PC 0x0c0a36de */
if(!s->budget--) { s->failed_pc=0x0c0a36deu; return 0; }
goto P_0c0a36e0;
P_0c0a36e0: /* original 9428, guest PC 0x0c0a36e0 */
if(!s->budget--) { s->failed_pc=0x0c0a36e0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a3734u,2);
goto P_0c0a36e2;
P_0c0a36e2: /* original bba3, guest PC 0x0c0a36e2 */
if(!s->budget--) { s->failed_pc=0x0c0a36e2u; return 0; }
target=0x0c0a2e2cu; r[16]=0x0c0a36e6u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a36e6u) { target=s->pc; goto dispatch; }
goto P_0c0a36e6;
P_0c0a36e4: /* original 0009, guest PC 0x0c0a36e4 */
if(!s->budget--) { s->failed_pc=0x0c0a36e4u; return 0; }
goto P_0c0a36e6;
P_0c0a36e6: /* original 9426, guest PC 0x0c0a36e6 */
if(!s->budget--) { s->failed_pc=0x0c0a36e6u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a3736u,2);
goto P_0c0a36e8;
P_0c0a36e8: /* original bba0, guest PC 0x0c0a36e8 */
if(!s->budget--) { s->failed_pc=0x0c0a36e8u; return 0; }
target=0x0c0a2e2cu; r[16]=0x0c0a36ecu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a36ecu) { target=s->pc; goto dispatch; }
goto P_0c0a36ec;
P_0c0a36ea: /* original 0009, guest PC 0x0c0a36ea */
if(!s->budget--) { s->failed_pc=0x0c0a36eau; return 0; }
goto P_0c0a36ec;
P_0c0a36ec: /* original 9424, guest PC 0x0c0a36ec */
if(!s->budget--) { s->failed_pc=0x0c0a36ecu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a3738u,2);
goto P_0c0a36ee;
P_0c0a36ee: /* original bb9d, guest PC 0x0c0a36ee */
if(!s->budget--) { s->failed_pc=0x0c0a36eeu; return 0; }
target=0x0c0a2e2cu; r[16]=0x0c0a36f2u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a36f2u) { target=s->pc; goto dispatch; }
goto P_0c0a36f2;
P_0c0a36f0: /* original 0009, guest PC 0x0c0a36f0 */
if(!s->budget--) { s->failed_pc=0x0c0a36f0u; return 0; }
goto P_0c0a36f2;
P_0c0a36f2: /* original 9422, guest PC 0x0c0a36f2 */
if(!s->budget--) { s->failed_pc=0x0c0a36f2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a373au,2);
goto P_0c0a36f4;
P_0c0a36f4: /* original bb9a, guest PC 0x0c0a36f4 */
if(!s->budget--) { s->failed_pc=0x0c0a36f4u; return 0; }
target=0x0c0a2e2cu; r[16]=0x0c0a36f8u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a36f8u) { target=s->pc; goto dispatch; }
goto P_0c0a36f8;
P_0c0a36f6: /* original 0009, guest PC 0x0c0a36f6 */
if(!s->budget--) { s->failed_pc=0x0c0a36f6u; return 0; }
goto P_0c0a36f8;
P_0c0a36f8: /* original 9420, guest PC 0x0c0a36f8 */
if(!s->budget--) { s->failed_pc=0x0c0a36f8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a373cu,2);
goto P_0c0a36fa;
P_0c0a36fa: /* original bb97, guest PC 0x0c0a36fa */
if(!s->budget--) { s->failed_pc=0x0c0a36fau; return 0; }
target=0x0c0a2e2cu; r[16]=0x0c0a36feu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a36feu) { target=s->pc; goto dispatch; }
goto P_0c0a36fe;
P_0c0a36fc: /* original 0009, guest PC 0x0c0a36fc */
if(!s->budget--) { s->failed_pc=0x0c0a36fcu; return 0; }
goto P_0c0a36fe;
P_0c0a36fe: /* original 941e, guest PC 0x0c0a36fe */
if(!s->budget--) { s->failed_pc=0x0c0a36feu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a373eu,2);
goto P_0c0a3700;
P_0c0a3700: /* original bb94, guest PC 0x0c0a3700 */
if(!s->budget--) { s->failed_pc=0x0c0a3700u; return 0; }
target=0x0c0a2e2cu; r[16]=0x0c0a3704u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a3704u) { target=s->pc; goto dispatch; }
goto P_0c0a3704;
P_0c0a3702: /* original 0009, guest PC 0x0c0a3702 */
if(!s->budget--) { s->failed_pc=0x0c0a3702u; return 0; }
goto P_0c0a3704;
P_0c0a3704: /* original 941c, guest PC 0x0c0a3704 */
if(!s->budget--) { s->failed_pc=0x0c0a3704u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a3740u,2);
goto P_0c0a3706;
P_0c0a3706: /* original bb91, guest PC 0x0c0a3706 */
if(!s->budget--) { s->failed_pc=0x0c0a3706u; return 0; }
target=0x0c0a2e2cu; r[16]=0x0c0a370au;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a370au) { target=s->pc; goto dispatch; }
goto P_0c0a370a;
P_0c0a3708: /* original 0009, guest PC 0x0c0a3708 */
if(!s->budget--) { s->failed_pc=0x0c0a3708u; return 0; }
goto P_0c0a370a;
P_0c0a370a: /* original 941a, guest PC 0x0c0a370a */
if(!s->budget--) { s->failed_pc=0x0c0a370au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a3742u,2);
goto P_0c0a370c;
P_0c0a370c: /* original bb8e, guest PC 0x0c0a370c */
if(!s->budget--) { s->failed_pc=0x0c0a370cu; return 0; }
target=0x0c0a2e2cu; r[16]=0x0c0a3710u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a3710u) { target=s->pc; goto dispatch; }
goto P_0c0a3710;
P_0c0a370e: /* original 0009, guest PC 0x0c0a370e */
if(!s->budget--) { s->failed_pc=0x0c0a370eu; return 0; }
goto P_0c0a3710;
P_0c0a3710: /* original 9418, guest PC 0x0c0a3710 */
if(!s->budget--) { s->failed_pc=0x0c0a3710u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a3744u,2);
goto P_0c0a3712;
P_0c0a3712: /* original ab8b, guest PC 0x0c0a3712 */
if(!s->budget--) { s->failed_pc=0x0c0a3712u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a2e2c;
P_0c0a3714: /* original 4f26, guest PC 0x0c0a3714 */
if(!s->budget--) { s->failed_pc=0x0c0a3714u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
return vf3_matrix_family(0x0c0a3716u,s,ram);
P_0c0a374a: /* original 4f22, guest PC 0x0c0a374a */
if(!s->budget--) { s->failed_pc=0x0c0a374au; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0a374c;
P_0c0a374c: /* original 9485, guest PC 0x0c0a374c */
if(!s->budget--) { s->failed_pc=0x0c0a374cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a385au,2);
goto P_0c0a374e;
P_0c0a374e: /* original bb5a, guest PC 0x0c0a374e */
if(!s->budget--) { s->failed_pc=0x0c0a374eu; return 0; }
target=0x0c0a2e06u; r[16]=0x0c0a3752u;
tmp=read(ram,r[14],4);
r[5]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a3752u) { target=s->pc; goto dispatch; }
goto P_0c0a3752;
P_0c0a3750: /* original 65e2, guest PC 0x0c0a3750 */
if(!s->budget--) { s->failed_pc=0x0c0a3750u; return 0; }
tmp=read(ram,r[14],4);
r[5]=tmp;
goto P_0c0a3752;
P_0c0a3752: /* original 9483, guest PC 0x0c0a3752 */
if(!s->budget--) { s->failed_pc=0x0c0a3752u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a385cu,2);
goto P_0c0a3754;
P_0c0a3754: /* original e040, guest PC 0x0c0a3754 */
if(!s->budget--) { s->failed_pc=0x0c0a3754u; return 0; }
r[0]=0x00000040u;
goto P_0c0a3756;
P_0c0a3756: /* original bb56, guest PC 0x0c0a3756 */
if(!s->budget--) { s->failed_pc=0x0c0a3756u; return 0; }
target=0x0c0a2e06u; r[16]=0x0c0a375au;
r[5]=read(ram,r[14]+r[0],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a375au) { target=s->pc; goto dispatch; }
goto P_0c0a375a;
P_0c0a3758: /* original 05ee, guest PC 0x0c0a3758 */
if(!s->budget--) { s->failed_pc=0x0c0a3758u; return 0; }
r[5]=read(ram,r[14]+r[0],4);
goto P_0c0a375a;
P_0c0a375a: /* original 9480, guest PC 0x0c0a375a */
if(!s->budget--) { s->failed_pc=0x0c0a375au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a385eu,2);
goto P_0c0a375c;
P_0c0a375c: /* original bb53, guest PC 0x0c0a375c */
if(!s->budget--) { s->failed_pc=0x0c0a375cu; return 0; }
target=0x0c0a2e06u; r[16]=0x0c0a3760u;
r[5]=read(ram,r[14]+4,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a3760u) { target=s->pc; goto dispatch; }
goto P_0c0a3760;
P_0c0a375e: /* original 55e1, guest PC 0x0c0a375e */
if(!s->budget--) { s->failed_pc=0x0c0a375eu; return 0; }
r[5]=read(ram,r[14]+4,4);
goto P_0c0a3760;
P_0c0a3760: /* original 947e, guest PC 0x0c0a3760 */
if(!s->budget--) { s->failed_pc=0x0c0a3760u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a3860u,2);
goto P_0c0a3762;
P_0c0a3762: /* original bb50, guest PC 0x0c0a3762 */
if(!s->budget--) { s->failed_pc=0x0c0a3762u; return 0; }
target=0x0c0a2e06u; r[16]=0x0c0a3766u;
r[5]=read(ram,r[14]+8,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a3766u) { target=s->pc; goto dispatch; }
goto P_0c0a3766;
P_0c0a3764: /* original 55e2, guest PC 0x0c0a3764 */
if(!s->budget--) { s->failed_pc=0x0c0a3764u; return 0; }
r[5]=read(ram,r[14]+8,4);
goto P_0c0a3766;
P_0c0a3766: /* original 947c, guest PC 0x0c0a3766 */
if(!s->budget--) { s->failed_pc=0x0c0a3766u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a3862u,2);
goto P_0c0a3768;
P_0c0a3768: /* original bb4d, guest PC 0x0c0a3768 */
if(!s->budget--) { s->failed_pc=0x0c0a3768u; return 0; }
target=0x0c0a2e06u; r[16]=0x0c0a376cu;
r[5]=read(ram,r[14]+60,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a376cu) { target=s->pc; goto dispatch; }
goto P_0c0a376c;
P_0c0a376a: /* original 55ef, guest PC 0x0c0a376a */
if(!s->budget--) { s->failed_pc=0x0c0a376au; return 0; }
r[5]=read(ram,r[14]+60,4);
goto P_0c0a376c;
P_0c0a376c: /* original 947a, guest PC 0x0c0a376c */
if(!s->budget--) { s->failed_pc=0x0c0a376cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a3864u,2);
goto P_0c0a376e;
P_0c0a376e: /* original bb4a, guest PC 0x0c0a376e */
if(!s->budget--) { s->failed_pc=0x0c0a376eu; return 0; }
target=0x0c0a2e06u; r[16]=0x0c0a3772u;
r[5]=read(ram,r[14]+36,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a3772u) { target=s->pc; goto dispatch; }
goto P_0c0a3772;
P_0c0a3770: /* original 55e9, guest PC 0x0c0a3770 */
if(!s->budget--) { s->failed_pc=0x0c0a3770u; return 0; }
r[5]=read(ram,r[14]+36,4);
goto P_0c0a3772;
P_0c0a3772: /* original 9478, guest PC 0x0c0a3772 */
if(!s->budget--) { s->failed_pc=0x0c0a3772u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a3866u,2);
goto P_0c0a3774;
P_0c0a3774: /* original bb47, guest PC 0x0c0a3774 */
if(!s->budget--) { s->failed_pc=0x0c0a3774u; return 0; }
target=0x0c0a2e06u; r[16]=0x0c0a3778u;
r[5]=read(ram,r[14]+40,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a3778u) { target=s->pc; goto dispatch; }
goto P_0c0a3778;
P_0c0a3776: /* original 55ea, guest PC 0x0c0a3776 */
if(!s->budget--) { s->failed_pc=0x0c0a3776u; return 0; }
r[5]=read(ram,r[14]+40,4);
goto P_0c0a3778;
P_0c0a3778: /* original 9476, guest PC 0x0c0a3778 */
if(!s->budget--) { s->failed_pc=0x0c0a3778u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a3868u,2);
goto P_0c0a377a;
P_0c0a377a: /* original bb44, guest PC 0x0c0a377a */
if(!s->budget--) { s->failed_pc=0x0c0a377au; return 0; }
target=0x0c0a2e06u; r[16]=0x0c0a377eu;
r[5]=read(ram,r[14]+44,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a377eu) { target=s->pc; goto dispatch; }
goto P_0c0a377e;
P_0c0a377c: /* original 55eb, guest PC 0x0c0a377c */
if(!s->budget--) { s->failed_pc=0x0c0a377cu; return 0; }
r[5]=read(ram,r[14]+44,4);
goto P_0c0a377e;
P_0c0a377e: /* original 9474, guest PC 0x0c0a377e */
if(!s->budget--) { s->failed_pc=0x0c0a377eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a386au,2);
goto P_0c0a3780;
P_0c0a3780: /* original bb41, guest PC 0x0c0a3780 */
if(!s->budget--) { s->failed_pc=0x0c0a3780u; return 0; }
target=0x0c0a2e06u; r[16]=0x0c0a3784u;
r[5]=read(ram,r[14]+48,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a3784u) { target=s->pc; goto dispatch; }
goto P_0c0a3784;
P_0c0a3782: /* original 55ec, guest PC 0x0c0a3782 */
if(!s->budget--) { s->failed_pc=0x0c0a3782u; return 0; }
r[5]=read(ram,r[14]+48,4);
goto P_0c0a3784;
P_0c0a3784: /* original 9472, guest PC 0x0c0a3784 */
if(!s->budget--) { s->failed_pc=0x0c0a3784u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a386cu,2);
goto P_0c0a3786;
P_0c0a3786: /* original bb3e, guest PC 0x0c0a3786 */
if(!s->budget--) { s->failed_pc=0x0c0a3786u; return 0; }
target=0x0c0a2e06u; r[16]=0x0c0a378au;
r[5]=read(ram,r[14]+52,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a378au) { target=s->pc; goto dispatch; }
goto P_0c0a378a;
P_0c0a3788: /* original 55ed, guest PC 0x0c0a3788 */
if(!s->budget--) { s->failed_pc=0x0c0a3788u; return 0; }
r[5]=read(ram,r[14]+52,4);
goto P_0c0a378a;
P_0c0a378a: /* original 9470, guest PC 0x0c0a378a */
if(!s->budget--) { s->failed_pc=0x0c0a378au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a386eu,2);
goto P_0c0a378c;
P_0c0a378c: /* original bb3b, guest PC 0x0c0a378c */
if(!s->budget--) { s->failed_pc=0x0c0a378cu; return 0; }
target=0x0c0a2e06u; r[16]=0x0c0a3790u;
r[5]=read(ram,r[14]+32,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a3790u) { target=s->pc; goto dispatch; }
goto P_0c0a3790;
P_0c0a378e: /* original 55e8, guest PC 0x0c0a378e */
if(!s->budget--) { s->failed_pc=0x0c0a378eu; return 0; }
r[5]=read(ram,r[14]+32,4);
goto P_0c0a3790;
P_0c0a3790: /* original 946e, guest PC 0x0c0a3790 */
if(!s->budget--) { s->failed_pc=0x0c0a3790u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a3870u,2);
goto P_0c0a3792;
P_0c0a3792: /* original bb38, guest PC 0x0c0a3792 */
if(!s->budget--) { s->failed_pc=0x0c0a3792u; return 0; }
target=0x0c0a2e06u; r[16]=0x0c0a3796u;
r[5]=read(ram,r[14]+12,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a3796u) { target=s->pc; goto dispatch; }
goto P_0c0a3796;
P_0c0a3794: /* original 55e3, guest PC 0x0c0a3794 */
if(!s->budget--) { s->failed_pc=0x0c0a3794u; return 0; }
r[5]=read(ram,r[14]+12,4);
goto P_0c0a3796;
P_0c0a3796: /* original 946c, guest PC 0x0c0a3796 */
if(!s->budget--) { s->failed_pc=0x0c0a3796u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a3872u,2);
goto P_0c0a3798;
P_0c0a3798: /* original bb35, guest PC 0x0c0a3798 */
if(!s->budget--) { s->failed_pc=0x0c0a3798u; return 0; }
target=0x0c0a2e06u; r[16]=0x0c0a379cu;
r[5]=read(ram,r[14]+16,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a379cu) { target=s->pc; goto dispatch; }
goto P_0c0a379c;
P_0c0a379a: /* original 55e4, guest PC 0x0c0a379a */
if(!s->budget--) { s->failed_pc=0x0c0a379au; return 0; }
r[5]=read(ram,r[14]+16,4);
goto P_0c0a379c;
P_0c0a379c: /* original 946a, guest PC 0x0c0a379c */
if(!s->budget--) { s->failed_pc=0x0c0a379cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a3874u,2);
goto P_0c0a379e;
P_0c0a379e: /* original bb32, guest PC 0x0c0a379e */
if(!s->budget--) { s->failed_pc=0x0c0a379eu; return 0; }
target=0x0c0a2e06u; r[16]=0x0c0a37a2u;
r[5]=read(ram,r[14]+20,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a37a2u) { target=s->pc; goto dispatch; }
goto P_0c0a37a2;
P_0c0a37a0: /* original 55e5, guest PC 0x0c0a37a0 */
if(!s->budget--) { s->failed_pc=0x0c0a37a0u; return 0; }
r[5]=read(ram,r[14]+20,4);
goto P_0c0a37a2;
P_0c0a37a2: /* original 9468, guest PC 0x0c0a37a2 */
if(!s->budget--) { s->failed_pc=0x0c0a37a2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a3876u,2);
goto P_0c0a37a4;
P_0c0a37a4: /* original bb2f, guest PC 0x0c0a37a4 */
if(!s->budget--) { s->failed_pc=0x0c0a37a4u; return 0; }
target=0x0c0a2e06u; r[16]=0x0c0a37a8u;
r[5]=read(ram,r[14]+24,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a37a8u) { target=s->pc; goto dispatch; }
goto P_0c0a37a8;
P_0c0a37a6: /* original 55e6, guest PC 0x0c0a37a6 */
if(!s->budget--) { s->failed_pc=0x0c0a37a6u; return 0; }
r[5]=read(ram,r[14]+24,4);
goto P_0c0a37a8;
P_0c0a37a8: /* original 9466, guest PC 0x0c0a37a8 */
if(!s->budget--) { s->failed_pc=0x0c0a37a8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a3878u,2);
goto P_0c0a37aa;
P_0c0a37aa: /* original bb2c, guest PC 0x0c0a37aa */
if(!s->budget--) { s->failed_pc=0x0c0a37aau; return 0; }
target=0x0c0a2e06u; r[16]=0x0c0a37aeu;
r[5]=read(ram,r[14]+28,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a37aeu) { target=s->pc; goto dispatch; }
goto P_0c0a37ae;
P_0c0a37ac: /* original 55e7, guest PC 0x0c0a37ac */
if(!s->budget--) { s->failed_pc=0x0c0a37acu; return 0; }
r[5]=read(ram,r[14]+28,4);
goto P_0c0a37ae;
P_0c0a37ae: /* original 9464, guest PC 0x0c0a37ae */
if(!s->budget--) { s->failed_pc=0x0c0a37aeu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a387au,2);
goto P_0c0a37b0;
P_0c0a37b0: /* original bb29, guest PC 0x0c0a37b0 */
if(!s->budget--) { s->failed_pc=0x0c0a37b0u; return 0; }
target=0x0c0a2e06u; r[16]=0x0c0a37b4u;
r[5]=read(ram,r[14]+56,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a37b4u) { target=s->pc; goto dispatch; }
goto P_0c0a37b4;
P_0c0a37b2: /* original 55ee, guest PC 0x0c0a37b2 */
if(!s->budget--) { s->failed_pc=0x0c0a37b2u; return 0; }
r[5]=read(ram,r[14]+56,4);
goto P_0c0a37b4;
P_0c0a37b4: /* original 9462, guest PC 0x0c0a37b4 */
if(!s->budget--) { s->failed_pc=0x0c0a37b4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a387cu,2);
goto P_0c0a37b6;
P_0c0a37b6: /* original e044, guest PC 0x0c0a37b6 */
if(!s->budget--) { s->failed_pc=0x0c0a37b6u; return 0; }
r[0]=0x00000044u;
goto P_0c0a37b8;
P_0c0a37b8: /* original bb25, guest PC 0x0c0a37b8 */
if(!s->budget--) { s->failed_pc=0x0c0a37b8u; return 0; }
target=0x0c0a2e06u; r[16]=0x0c0a37bcu;
r[5]=read(ram,r[14]+r[0],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a37bcu) { target=s->pc; goto dispatch; }
goto P_0c0a37bc;
P_0c0a37ba: /* original 05ee, guest PC 0x0c0a37ba */
if(!s->budget--) { s->failed_pc=0x0c0a37bau; return 0; }
r[5]=read(ram,r[14]+r[0],4);
goto P_0c0a37bc;
P_0c0a37bc: /* original 945f, guest PC 0x0c0a37bc */
if(!s->budget--) { s->failed_pc=0x0c0a37bcu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a387eu,2);
goto P_0c0a37be;
P_0c0a37be: /* original e048, guest PC 0x0c0a37be */
if(!s->budget--) { s->failed_pc=0x0c0a37beu; return 0; }
r[0]=0x00000048u;
goto P_0c0a37c0;
P_0c0a37c0: /* original bb21, guest PC 0x0c0a37c0 */
if(!s->budget--) { s->failed_pc=0x0c0a37c0u; return 0; }
target=0x0c0a2e06u; r[16]=0x0c0a37c4u;
r[5]=read(ram,r[14]+r[0],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a37c4u) { target=s->pc; goto dispatch; }
goto P_0c0a37c4;
P_0c0a37c2: /* original 05ee, guest PC 0x0c0a37c2 */
if(!s->budget--) { s->failed_pc=0x0c0a37c2u; return 0; }
r[5]=read(ram,r[14]+r[0],4);
goto P_0c0a37c4;
P_0c0a37c4: /* original 945c, guest PC 0x0c0a37c4 */
if(!s->budget--) { s->failed_pc=0x0c0a37c4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a3880u,2);
goto P_0c0a37c6;
P_0c0a37c6: /* original e04c, guest PC 0x0c0a37c6 */
if(!s->budget--) { s->failed_pc=0x0c0a37c6u; return 0; }
r[0]=0x0000004cu;
goto P_0c0a37c8;
P_0c0a37c8: /* original bb1d, guest PC 0x0c0a37c8 */
if(!s->budget--) { s->failed_pc=0x0c0a37c8u; return 0; }
target=0x0c0a2e06u; r[16]=0x0c0a37ccu;
r[5]=read(ram,r[14]+r[0],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a37ccu) { target=s->pc; goto dispatch; }
goto P_0c0a37cc;
P_0c0a37ca: /* original 05ee, guest PC 0x0c0a37ca */
if(!s->budget--) { s->failed_pc=0x0c0a37cau; return 0; }
r[5]=read(ram,r[14]+r[0],4);
goto P_0c0a37cc;
P_0c0a37cc: /* original 65e3, guest PC 0x0c0a37cc */
if(!s->budget--) { s->failed_pc=0x0c0a37ccu; return 0; }
r[5]=r[14];
goto P_0c0a37ce;
P_0c0a37ce: /* original 7550, guest PC 0x0c0a37ce */
if(!s->budget--) { s->failed_pc=0x0c0a37ceu; return 0; }
r[5]+=0x00000050u;
goto P_0c0a37d0;
P_0c0a37d0: /* original 4f26, guest PC 0x0c0a37d0 */
if(!s->budget--) { s->failed_pc=0x0c0a37d0u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a37d2;
P_0c0a37d2: /* original 9456, guest PC 0x0c0a37d2 */
if(!s->budget--) { s->failed_pc=0x0c0a37d2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a3882u,2);
goto P_0c0a37d4;
P_0c0a37d4: /* original 6552, guest PC 0x0c0a37d4 */
if(!s->budget--) { s->failed_pc=0x0c0a37d4u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0a37d6;
P_0c0a37d6: /* original ab16, guest PC 0x0c0a37d6 */
if(!s->budget--) { s->failed_pc=0x0c0a37d6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0a2e06;
P_0c0a37d8: /* original 6ef6, guest PC 0x0c0a37d8 */
if(!s->budget--) { s->failed_pc=0x0c0a37d8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0a37da;
P_0c0a37da: /* original 4f22, guest PC 0x0c0a37da */
if(!s->budget--) { s->failed_pc=0x0c0a37dau; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0a37dc;
P_0c0a37dc: /* original 9452, guest PC 0x0c0a37dc */
if(!s->budget--) { s->failed_pc=0x0c0a37dcu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a3884u,2);
goto P_0c0a37de;
P_0c0a37de: /* original bb25, guest PC 0x0c0a37de */
if(!s->budget--) { s->failed_pc=0x0c0a37deu; return 0; }
target=0x0c0a2e2cu; r[16]=0x0c0a37e2u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a37e2u) { target=s->pc; goto dispatch; }
goto P_0c0a37e2;
P_0c0a37e0: /* original 0009, guest PC 0x0c0a37e0 */
if(!s->budget--) { s->failed_pc=0x0c0a37e0u; return 0; }
goto P_0c0a37e2;
P_0c0a37e2: /* original 9450, guest PC 0x0c0a37e2 */
if(!s->budget--) { s->failed_pc=0x0c0a37e2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a3886u,2);
goto P_0c0a37e4;
P_0c0a37e4: /* original bb22, guest PC 0x0c0a37e4 */
if(!s->budget--) { s->failed_pc=0x0c0a37e4u; return 0; }
target=0x0c0a2e2cu; r[16]=0x0c0a37e8u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a37e8u) { target=s->pc; goto dispatch; }
goto P_0c0a37e8;
P_0c0a37e6: /* original 0009, guest PC 0x0c0a37e6 */
if(!s->budget--) { s->failed_pc=0x0c0a37e6u; return 0; }
goto P_0c0a37e8;
P_0c0a37e8: /* original 944e, guest PC 0x0c0a37e8 */
if(!s->budget--) { s->failed_pc=0x0c0a37e8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a3888u,2);
goto P_0c0a37ea;
P_0c0a37ea: /* original bb1f, guest PC 0x0c0a37ea */
if(!s->budget--) { s->failed_pc=0x0c0a37eau; return 0; }
target=0x0c0a2e2cu; r[16]=0x0c0a37eeu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a37eeu) { target=s->pc; goto dispatch; }
goto P_0c0a37ee;
P_0c0a37ec: /* original 0009, guest PC 0x0c0a37ec */
if(!s->budget--) { s->failed_pc=0x0c0a37ecu; return 0; }
goto P_0c0a37ee;
P_0c0a37ee: /* original 944c, guest PC 0x0c0a37ee */
if(!s->budget--) { s->failed_pc=0x0c0a37eeu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a388au,2);
goto P_0c0a37f0;
P_0c0a37f0: /* original bb1c, guest PC 0x0c0a37f0 */
if(!s->budget--) { s->failed_pc=0x0c0a37f0u; return 0; }
target=0x0c0a2e2cu; r[16]=0x0c0a37f4u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a37f4u) { target=s->pc; goto dispatch; }
goto P_0c0a37f4;
P_0c0a37f2: /* original 0009, guest PC 0x0c0a37f2 */
if(!s->budget--) { s->failed_pc=0x0c0a37f2u; return 0; }
goto P_0c0a37f4;
P_0c0a37f4: /* original 944a, guest PC 0x0c0a37f4 */
if(!s->budget--) { s->failed_pc=0x0c0a37f4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a388cu,2);
goto P_0c0a37f6;
P_0c0a37f6: /* original bb19, guest PC 0x0c0a37f6 */
if(!s->budget--) { s->failed_pc=0x0c0a37f6u; return 0; }
target=0x0c0a2e2cu; r[16]=0x0c0a37fau;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a37fau) { target=s->pc; goto dispatch; }
goto P_0c0a37fa;
P_0c0a37f8: /* original 0009, guest PC 0x0c0a37f8 */
if(!s->budget--) { s->failed_pc=0x0c0a37f8u; return 0; }
goto P_0c0a37fa;
P_0c0a37fa: /* original 9448, guest PC 0x0c0a37fa */
if(!s->budget--) { s->failed_pc=0x0c0a37fau; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a388eu,2);
goto P_0c0a37fc;
P_0c0a37fc: /* original bb16, guest PC 0x0c0a37fc */
if(!s->budget--) { s->failed_pc=0x0c0a37fcu; return 0; }
target=0x0c0a2e2cu; r[16]=0x0c0a3800u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a3800u) { target=s->pc; goto dispatch; }
goto P_0c0a3800;
P_0c0a37fe: /* original 0009, guest PC 0x0c0a37fe */
if(!s->budget--) { s->failed_pc=0x0c0a37feu; return 0; }
goto P_0c0a3800;
P_0c0a3800: /* original 9446, guest PC 0x0c0a3800 */
if(!s->budget--) { s->failed_pc=0x0c0a3800u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a3890u,2);
goto P_0c0a3802;
P_0c0a3802: /* original bb13, guest PC 0x0c0a3802 */
if(!s->budget--) { s->failed_pc=0x0c0a3802u; return 0; }
target=0x0c0a2e2cu; r[16]=0x0c0a3806u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a3806u) { target=s->pc; goto dispatch; }
goto P_0c0a3806;
P_0c0a3804: /* original 0009, guest PC 0x0c0a3804 */
if(!s->budget--) { s->failed_pc=0x0c0a3804u; return 0; }
goto P_0c0a3806;
P_0c0a3806: /* original 9444, guest PC 0x0c0a3806 */
if(!s->budget--) { s->failed_pc=0x0c0a3806u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a3892u,2);
goto P_0c0a3808;
P_0c0a3808: /* original bb10, guest PC 0x0c0a3808 */
if(!s->budget--) { s->failed_pc=0x0c0a3808u; return 0; }
target=0x0c0a2e2cu; r[16]=0x0c0a380cu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a380cu) { target=s->pc; goto dispatch; }
goto P_0c0a380c;
P_0c0a380a: /* original 0009, guest PC 0x0c0a380a */
if(!s->budget--) { s->failed_pc=0x0c0a380au; return 0; }
goto P_0c0a380c;
P_0c0a380c: /* original 9442, guest PC 0x0c0a380c */
if(!s->budget--) { s->failed_pc=0x0c0a380cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a3894u,2);
goto P_0c0a380e;
P_0c0a380e: /* original bb0d, guest PC 0x0c0a380e */
if(!s->budget--) { s->failed_pc=0x0c0a380eu; return 0; }
target=0x0c0a2e2cu; r[16]=0x0c0a3812u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a3812u) { target=s->pc; goto dispatch; }
goto P_0c0a3812;
P_0c0a3810: /* original 0009, guest PC 0x0c0a3810 */
if(!s->budget--) { s->failed_pc=0x0c0a3810u; return 0; }
goto P_0c0a3812;
P_0c0a3812: /* original 9440, guest PC 0x0c0a3812 */
if(!s->budget--) { s->failed_pc=0x0c0a3812u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a3896u,2);
goto P_0c0a3814;
P_0c0a3814: /* original bb0a, guest PC 0x0c0a3814 */
if(!s->budget--) { s->failed_pc=0x0c0a3814u; return 0; }
target=0x0c0a2e2cu; r[16]=0x0c0a3818u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a3818u) { target=s->pc; goto dispatch; }
goto P_0c0a3818;
P_0c0a3816: /* original 0009, guest PC 0x0c0a3816 */
if(!s->budget--) { s->failed_pc=0x0c0a3816u; return 0; }
goto P_0c0a3818;
P_0c0a3818: /* original 943e, guest PC 0x0c0a3818 */
if(!s->budget--) { s->failed_pc=0x0c0a3818u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a3898u,2);
goto P_0c0a381a;
P_0c0a381a: /* original bb07, guest PC 0x0c0a381a */
if(!s->budget--) { s->failed_pc=0x0c0a381au; return 0; }
target=0x0c0a2e2cu; r[16]=0x0c0a381eu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a381eu) { target=s->pc; goto dispatch; }
goto P_0c0a381e;
P_0c0a381c: /* original 0009, guest PC 0x0c0a381c */
if(!s->budget--) { s->failed_pc=0x0c0a381cu; return 0; }
goto P_0c0a381e;
P_0c0a381e: /* original 943c, guest PC 0x0c0a381e */
if(!s->budget--) { s->failed_pc=0x0c0a381eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a389au,2);
goto P_0c0a3820;
P_0c0a3820: /* original bb04, guest PC 0x0c0a3820 */
if(!s->budget--) { s->failed_pc=0x0c0a3820u; return 0; }
target=0x0c0a2e2cu; r[16]=0x0c0a3824u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a3824u) { target=s->pc; goto dispatch; }
goto P_0c0a3824;
P_0c0a3822: /* original 0009, guest PC 0x0c0a3822 */
if(!s->budget--) { s->failed_pc=0x0c0a3822u; return 0; }
goto P_0c0a3824;
P_0c0a3824: /* original 943a, guest PC 0x0c0a3824 */
if(!s->budget--) { s->failed_pc=0x0c0a3824u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a389cu,2);
goto P_0c0a3826;
P_0c0a3826: /* original bb01, guest PC 0x0c0a3826 */
if(!s->budget--) { s->failed_pc=0x0c0a3826u; return 0; }
target=0x0c0a2e2cu; r[16]=0x0c0a382au;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a382au) { target=s->pc; goto dispatch; }
goto P_0c0a382a;
P_0c0a3828: /* original 0009, guest PC 0x0c0a3828 */
if(!s->budget--) { s->failed_pc=0x0c0a3828u; return 0; }
goto P_0c0a382a;
P_0c0a382a: /* original 9438, guest PC 0x0c0a382a */
if(!s->budget--) { s->failed_pc=0x0c0a382au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a389eu,2);
goto P_0c0a382c;
P_0c0a382c: /* original bafe, guest PC 0x0c0a382c */
if(!s->budget--) { s->failed_pc=0x0c0a382cu; return 0; }
target=0x0c0a2e2cu; r[16]=0x0c0a3830u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a3830u) { target=s->pc; goto dispatch; }
goto P_0c0a3830;
P_0c0a382e: /* original 0009, guest PC 0x0c0a382e */
if(!s->budget--) { s->failed_pc=0x0c0a382eu; return 0; }
goto P_0c0a3830;
P_0c0a3830: /* original 9436, guest PC 0x0c0a3830 */
if(!s->budget--) { s->failed_pc=0x0c0a3830u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a38a0u,2);
goto P_0c0a3832;
P_0c0a3832: /* original bafb, guest PC 0x0c0a3832 */
if(!s->budget--) { s->failed_pc=0x0c0a3832u; return 0; }
target=0x0c0a2e2cu; r[16]=0x0c0a3836u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a3836u) { target=s->pc; goto dispatch; }
goto P_0c0a3836;
P_0c0a3834: /* original 0009, guest PC 0x0c0a3834 */
if(!s->budget--) { s->failed_pc=0x0c0a3834u; return 0; }
goto P_0c0a3836;
P_0c0a3836: /* original 9434, guest PC 0x0c0a3836 */
if(!s->budget--) { s->failed_pc=0x0c0a3836u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a38a2u,2);
goto P_0c0a3838;
P_0c0a3838: /* original baf8, guest PC 0x0c0a3838 */
if(!s->budget--) { s->failed_pc=0x0c0a3838u; return 0; }
target=0x0c0a2e2cu; r[16]=0x0c0a383cu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a383cu) { target=s->pc; goto dispatch; }
goto P_0c0a383c;
P_0c0a383a: /* original 0009, guest PC 0x0c0a383a */
if(!s->budget--) { s->failed_pc=0x0c0a383au; return 0; }
goto P_0c0a383c;
P_0c0a383c: /* original 9432, guest PC 0x0c0a383c */
if(!s->budget--) { s->failed_pc=0x0c0a383cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a38a4u,2);
goto P_0c0a383e;
P_0c0a383e: /* original baf5, guest PC 0x0c0a383e */
if(!s->budget--) { s->failed_pc=0x0c0a383eu; return 0; }
target=0x0c0a2e2cu; r[16]=0x0c0a3842u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a3842u) { target=s->pc; goto dispatch; }
goto P_0c0a3842;
P_0c0a3840: /* original 0009, guest PC 0x0c0a3840 */
if(!s->budget--) { s->failed_pc=0x0c0a3840u; return 0; }
goto P_0c0a3842;
P_0c0a3842: /* original 9430, guest PC 0x0c0a3842 */
if(!s->budget--) { s->failed_pc=0x0c0a3842u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a38a6u,2);
goto P_0c0a3844;
P_0c0a3844: /* original baf2, guest PC 0x0c0a3844 */
if(!s->budget--) { s->failed_pc=0x0c0a3844u; return 0; }
target=0x0c0a2e2cu; r[16]=0x0c0a3848u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a3848u) { target=s->pc; goto dispatch; }
goto P_0c0a3848;
P_0c0a3846: /* original 0009, guest PC 0x0c0a3846 */
if(!s->budget--) { s->failed_pc=0x0c0a3846u; return 0; }
goto P_0c0a3848;
P_0c0a3848: /* original 942e, guest PC 0x0c0a3848 */
if(!s->budget--) { s->failed_pc=0x0c0a3848u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a38a8u,2);
goto P_0c0a384a;
P_0c0a384a: /* original baef, guest PC 0x0c0a384a */
if(!s->budget--) { s->failed_pc=0x0c0a384au; return 0; }
target=0x0c0a2e2cu; r[16]=0x0c0a384eu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a384eu) { target=s->pc; goto dispatch; }
goto P_0c0a384e;
P_0c0a384c: /* original 0009, guest PC 0x0c0a384c */
if(!s->budget--) { s->failed_pc=0x0c0a384cu; return 0; }
goto P_0c0a384e;
P_0c0a384e: /* original 942c, guest PC 0x0c0a384e */
if(!s->budget--) { s->failed_pc=0x0c0a384eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a38aau,2);
goto P_0c0a3850;
P_0c0a3850: /* original baec, guest PC 0x0c0a3850 */
if(!s->budget--) { s->failed_pc=0x0c0a3850u; return 0; }
target=0x0c0a2e2cu; r[16]=0x0c0a3854u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a3854u) { target=s->pc; goto dispatch; }
goto P_0c0a3854;
P_0c0a3852: /* original 0009, guest PC 0x0c0a3852 */
if(!s->budget--) { s->failed_pc=0x0c0a3852u; return 0; }
goto P_0c0a3854;
P_0c0a3854: /* original 942a, guest PC 0x0c0a3854 */
if(!s->budget--) { s->failed_pc=0x0c0a3854u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a38acu,2);
goto P_0c0a3856;
P_0c0a3856: /* original aae9, guest PC 0x0c0a3856 */
if(!s->budget--) { s->failed_pc=0x0c0a3856u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a2e2c;
P_0c0a3858: /* original 4f26, guest PC 0x0c0a3858 */
if(!s->budget--) { s->failed_pc=0x0c0a3858u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
return vf3_matrix_family(0x0c0a385au,s,ram);
P_0c0a396c: /* original 4f22, guest PC 0x0c0a396c */
if(!s->budget--) { s->failed_pc=0x0c0a396cu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0a396e;
P_0c0a396e: /* original 9488, guest PC 0x0c0a396e */
if(!s->budget--) { s->failed_pc=0x0c0a396eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a3a82u,2);
goto P_0c0a3970;
P_0c0a3970: /* original ba5c, guest PC 0x0c0a3970 */
if(!s->budget--) { s->failed_pc=0x0c0a3970u; return 0; }
target=0x0c0a2e2cu; r[16]=0x0c0a3974u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a3974u) { target=s->pc; goto dispatch; }
goto P_0c0a3974;
P_0c0a3972: /* original 0009, guest PC 0x0c0a3972 */
if(!s->budget--) { s->failed_pc=0x0c0a3972u; return 0; }
goto P_0c0a3974;
P_0c0a3974: /* original 9486, guest PC 0x0c0a3974 */
if(!s->budget--) { s->failed_pc=0x0c0a3974u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a3a84u,2);
goto P_0c0a3976;
P_0c0a3976: /* original ba59, guest PC 0x0c0a3976 */
if(!s->budget--) { s->failed_pc=0x0c0a3976u; return 0; }
target=0x0c0a2e2cu; r[16]=0x0c0a397au;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a397au) { target=s->pc; goto dispatch; }
goto P_0c0a397a;
P_0c0a3978: /* original 0009, guest PC 0x0c0a3978 */
if(!s->budget--) { s->failed_pc=0x0c0a3978u; return 0; }
goto P_0c0a397a;
P_0c0a397a: /* original 9484, guest PC 0x0c0a397a */
if(!s->budget--) { s->failed_pc=0x0c0a397au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a3a86u,2);
goto P_0c0a397c;
P_0c0a397c: /* original ba56, guest PC 0x0c0a397c */
if(!s->budget--) { s->failed_pc=0x0c0a397cu; return 0; }
target=0x0c0a2e2cu; r[16]=0x0c0a3980u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a3980u) { target=s->pc; goto dispatch; }
goto P_0c0a3980;
P_0c0a397e: /* original 0009, guest PC 0x0c0a397e */
if(!s->budget--) { s->failed_pc=0x0c0a397eu; return 0; }
goto P_0c0a3980;
P_0c0a3980: /* original 9482, guest PC 0x0c0a3980 */
if(!s->budget--) { s->failed_pc=0x0c0a3980u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a3a88u,2);
goto P_0c0a3982;
P_0c0a3982: /* original ba53, guest PC 0x0c0a3982 */
if(!s->budget--) { s->failed_pc=0x0c0a3982u; return 0; }
target=0x0c0a2e2cu; r[16]=0x0c0a3986u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a3986u) { target=s->pc; goto dispatch; }
goto P_0c0a3986;
P_0c0a3984: /* original 0009, guest PC 0x0c0a3984 */
if(!s->budget--) { s->failed_pc=0x0c0a3984u; return 0; }
goto P_0c0a3986;
P_0c0a3986: /* original 9480, guest PC 0x0c0a3986 */
if(!s->budget--) { s->failed_pc=0x0c0a3986u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a3a8au,2);
goto P_0c0a3988;
P_0c0a3988: /* original ba50, guest PC 0x0c0a3988 */
if(!s->budget--) { s->failed_pc=0x0c0a3988u; return 0; }
target=0x0c0a2e2cu; r[16]=0x0c0a398cu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a398cu) { target=s->pc; goto dispatch; }
goto P_0c0a398c;
P_0c0a398a: /* original 0009, guest PC 0x0c0a398a */
if(!s->budget--) { s->failed_pc=0x0c0a398au; return 0; }
goto P_0c0a398c;
P_0c0a398c: /* original 947e, guest PC 0x0c0a398c */
if(!s->budget--) { s->failed_pc=0x0c0a398cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a3a8cu,2);
goto P_0c0a398e;
P_0c0a398e: /* original ba4d, guest PC 0x0c0a398e */
if(!s->budget--) { s->failed_pc=0x0c0a398eu; return 0; }
target=0x0c0a2e2cu; r[16]=0x0c0a3992u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a3992u) { target=s->pc; goto dispatch; }
goto P_0c0a3992;
P_0c0a3990: /* original 0009, guest PC 0x0c0a3990 */
if(!s->budget--) { s->failed_pc=0x0c0a3990u; return 0; }
goto P_0c0a3992;
P_0c0a3992: /* original 947c, guest PC 0x0c0a3992 */
if(!s->budget--) { s->failed_pc=0x0c0a3992u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a3a8eu,2);
goto P_0c0a3994;
P_0c0a3994: /* original ba4a, guest PC 0x0c0a3994 */
if(!s->budget--) { s->failed_pc=0x0c0a3994u; return 0; }
target=0x0c0a2e2cu; r[16]=0x0c0a3998u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a3998u) { target=s->pc; goto dispatch; }
goto P_0c0a3998;
P_0c0a3996: /* original 0009, guest PC 0x0c0a3996 */
if(!s->budget--) { s->failed_pc=0x0c0a3996u; return 0; }
goto P_0c0a3998;
P_0c0a3998: /* original 947a, guest PC 0x0c0a3998 */
if(!s->budget--) { s->failed_pc=0x0c0a3998u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a3a90u,2);
goto P_0c0a399a;
P_0c0a399a: /* original ba47, guest PC 0x0c0a399a */
if(!s->budget--) { s->failed_pc=0x0c0a399au; return 0; }
target=0x0c0a2e2cu; r[16]=0x0c0a399eu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a399eu) { target=s->pc; goto dispatch; }
goto P_0c0a399e;
P_0c0a399c: /* original 0009, guest PC 0x0c0a399c */
if(!s->budget--) { s->failed_pc=0x0c0a399cu; return 0; }
goto P_0c0a399e;
P_0c0a399e: /* original 9478, guest PC 0x0c0a399e */
if(!s->budget--) { s->failed_pc=0x0c0a399eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a3a92u,2);
goto P_0c0a39a0;
P_0c0a39a0: /* original ba44, guest PC 0x0c0a39a0 */
if(!s->budget--) { s->failed_pc=0x0c0a39a0u; return 0; }
target=0x0c0a2e2cu; r[16]=0x0c0a39a4u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a39a4u) { target=s->pc; goto dispatch; }
goto P_0c0a39a4;
P_0c0a39a2: /* original 0009, guest PC 0x0c0a39a2 */
if(!s->budget--) { s->failed_pc=0x0c0a39a2u; return 0; }
goto P_0c0a39a4;
P_0c0a39a4: /* original 9476, guest PC 0x0c0a39a4 */
if(!s->budget--) { s->failed_pc=0x0c0a39a4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a3a94u,2);
goto P_0c0a39a6;
P_0c0a39a6: /* original ba41, guest PC 0x0c0a39a6 */
if(!s->budget--) { s->failed_pc=0x0c0a39a6u; return 0; }
target=0x0c0a2e2cu; r[16]=0x0c0a39aau;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a39aau) { target=s->pc; goto dispatch; }
goto P_0c0a39aa;
P_0c0a39a8: /* original 0009, guest PC 0x0c0a39a8 */
if(!s->budget--) { s->failed_pc=0x0c0a39a8u; return 0; }
goto P_0c0a39aa;
P_0c0a39aa: /* original 9474, guest PC 0x0c0a39aa */
if(!s->budget--) { s->failed_pc=0x0c0a39aau; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a3a96u,2);
goto P_0c0a39ac;
P_0c0a39ac: /* original ba3e, guest PC 0x0c0a39ac */
if(!s->budget--) { s->failed_pc=0x0c0a39acu; return 0; }
target=0x0c0a2e2cu; r[16]=0x0c0a39b0u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a39b0u) { target=s->pc; goto dispatch; }
goto P_0c0a39b0;
P_0c0a39ae: /* original 0009, guest PC 0x0c0a39ae */
if(!s->budget--) { s->failed_pc=0x0c0a39aeu; return 0; }
goto P_0c0a39b0;
P_0c0a39b0: /* original 9472, guest PC 0x0c0a39b0 */
if(!s->budget--) { s->failed_pc=0x0c0a39b0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a3a98u,2);
goto P_0c0a39b2;
P_0c0a39b2: /* original ba3b, guest PC 0x0c0a39b2 */
if(!s->budget--) { s->failed_pc=0x0c0a39b2u; return 0; }
target=0x0c0a2e2cu; r[16]=0x0c0a39b6u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a39b6u) { target=s->pc; goto dispatch; }
goto P_0c0a39b6;
P_0c0a39b4: /* original 0009, guest PC 0x0c0a39b4 */
if(!s->budget--) { s->failed_pc=0x0c0a39b4u; return 0; }
goto P_0c0a39b6;
P_0c0a39b6: /* original 9470, guest PC 0x0c0a39b6 */
if(!s->budget--) { s->failed_pc=0x0c0a39b6u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a3a9au,2);
goto P_0c0a39b8;
P_0c0a39b8: /* original ba38, guest PC 0x0c0a39b8 */
if(!s->budget--) { s->failed_pc=0x0c0a39b8u; return 0; }
target=0x0c0a2e2cu; r[16]=0x0c0a39bcu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a39bcu) { target=s->pc; goto dispatch; }
goto P_0c0a39bc;
P_0c0a39ba: /* original 0009, guest PC 0x0c0a39ba */
if(!s->budget--) { s->failed_pc=0x0c0a39bau; return 0; }
goto P_0c0a39bc;
P_0c0a39bc: /* original 946e, guest PC 0x0c0a39bc */
if(!s->budget--) { s->failed_pc=0x0c0a39bcu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a3a9cu,2);
goto P_0c0a39be;
P_0c0a39be: /* original ba35, guest PC 0x0c0a39be */
if(!s->budget--) { s->failed_pc=0x0c0a39beu; return 0; }
target=0x0c0a2e2cu; r[16]=0x0c0a39c2u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a39c2u) { target=s->pc; goto dispatch; }
goto P_0c0a39c2;
P_0c0a39c0: /* original 0009, guest PC 0x0c0a39c0 */
if(!s->budget--) { s->failed_pc=0x0c0a39c0u; return 0; }
goto P_0c0a39c2;
P_0c0a39c2: /* original 946c, guest PC 0x0c0a39c2 */
if(!s->budget--) { s->failed_pc=0x0c0a39c2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a3a9eu,2);
goto P_0c0a39c4;
P_0c0a39c4: /* original ba32, guest PC 0x0c0a39c4 */
if(!s->budget--) { s->failed_pc=0x0c0a39c4u; return 0; }
target=0x0c0a2e2cu; r[16]=0x0c0a39c8u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a39c8u) { target=s->pc; goto dispatch; }
goto P_0c0a39c8;
P_0c0a39c6: /* original 0009, guest PC 0x0c0a39c6 */
if(!s->budget--) { s->failed_pc=0x0c0a39c6u; return 0; }
goto P_0c0a39c8;
P_0c0a39c8: /* original 946a, guest PC 0x0c0a39c8 */
if(!s->budget--) { s->failed_pc=0x0c0a39c8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a3aa0u,2);
goto P_0c0a39ca;
P_0c0a39ca: /* original ba2f, guest PC 0x0c0a39ca */
if(!s->budget--) { s->failed_pc=0x0c0a39cau; return 0; }
target=0x0c0a2e2cu; r[16]=0x0c0a39ceu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a39ceu) { target=s->pc; goto dispatch; }
goto P_0c0a39ce;
P_0c0a39cc: /* original 0009, guest PC 0x0c0a39cc */
if(!s->budget--) { s->failed_pc=0x0c0a39ccu; return 0; }
goto P_0c0a39ce;
P_0c0a39ce: /* original 9468, guest PC 0x0c0a39ce */
if(!s->budget--) { s->failed_pc=0x0c0a39ceu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a3aa2u,2);
goto P_0c0a39d0;
P_0c0a39d0: /* original ba2c, guest PC 0x0c0a39d0 */
if(!s->budget--) { s->failed_pc=0x0c0a39d0u; return 0; }
target=0x0c0a2e2cu; r[16]=0x0c0a39d4u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a39d4u) { target=s->pc; goto dispatch; }
goto P_0c0a39d4;
P_0c0a39d2: /* original 0009, guest PC 0x0c0a39d2 */
if(!s->budget--) { s->failed_pc=0x0c0a39d2u; return 0; }
goto P_0c0a39d4;
P_0c0a39d4: /* original 9466, guest PC 0x0c0a39d4 */
if(!s->budget--) { s->failed_pc=0x0c0a39d4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a3aa4u,2);
goto P_0c0a39d6;
P_0c0a39d6: /* original ba29, guest PC 0x0c0a39d6 */
if(!s->budget--) { s->failed_pc=0x0c0a39d6u; return 0; }
target=0x0c0a2e2cu; r[16]=0x0c0a39dau;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a39dau) { target=s->pc; goto dispatch; }
goto P_0c0a39da;
P_0c0a39d8: /* original 0009, guest PC 0x0c0a39d8 */
if(!s->budget--) { s->failed_pc=0x0c0a39d8u; return 0; }
goto P_0c0a39da;
P_0c0a39da: /* original 9464, guest PC 0x0c0a39da */
if(!s->budget--) { s->failed_pc=0x0c0a39dau; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a3aa6u,2);
goto P_0c0a39dc;
P_0c0a39dc: /* original ba26, guest PC 0x0c0a39dc */
if(!s->budget--) { s->failed_pc=0x0c0a39dcu; return 0; }
target=0x0c0a2e2cu; r[16]=0x0c0a39e0u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a39e0u) { target=s->pc; goto dispatch; }
goto P_0c0a39e0;
P_0c0a39de: /* original 0009, guest PC 0x0c0a39de */
if(!s->budget--) { s->failed_pc=0x0c0a39deu; return 0; }
goto P_0c0a39e0;
P_0c0a39e0: /* original 9462, guest PC 0x0c0a39e0 */
if(!s->budget--) { s->failed_pc=0x0c0a39e0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a3aa8u,2);
goto P_0c0a39e2;
P_0c0a39e2: /* original ba23, guest PC 0x0c0a39e2 */
if(!s->budget--) { s->failed_pc=0x0c0a39e2u; return 0; }
target=0x0c0a2e2cu; r[16]=0x0c0a39e6u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a39e6u) { target=s->pc; goto dispatch; }
goto P_0c0a39e6;
P_0c0a39e4: /* original 0009, guest PC 0x0c0a39e4 */
if(!s->budget--) { s->failed_pc=0x0c0a39e4u; return 0; }
goto P_0c0a39e6;
P_0c0a39e6: /* original 9460, guest PC 0x0c0a39e6 */
if(!s->budget--) { s->failed_pc=0x0c0a39e6u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a3aaau,2);
goto P_0c0a39e8;
P_0c0a39e8: /* original ba20, guest PC 0x0c0a39e8 */
if(!s->budget--) { s->failed_pc=0x0c0a39e8u; return 0; }
target=0x0c0a2e2cu; r[16]=0x0c0a39ecu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a39ecu) { target=s->pc; goto dispatch; }
goto P_0c0a39ec;
P_0c0a39ea: /* original 0009, guest PC 0x0c0a39ea */
if(!s->budget--) { s->failed_pc=0x0c0a39eau; return 0; }
goto P_0c0a39ec;
P_0c0a39ec: /* original 945e, guest PC 0x0c0a39ec */
if(!s->budget--) { s->failed_pc=0x0c0a39ecu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a3aacu,2);
goto P_0c0a39ee;
P_0c0a39ee: /* original ba1d, guest PC 0x0c0a39ee */
if(!s->budget--) { s->failed_pc=0x0c0a39eeu; return 0; }
target=0x0c0a2e2cu; r[16]=0x0c0a39f2u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a39f2u) { target=s->pc; goto dispatch; }
goto P_0c0a39f2;
P_0c0a39f0: /* original 0009, guest PC 0x0c0a39f0 */
if(!s->budget--) { s->failed_pc=0x0c0a39f0u; return 0; }
goto P_0c0a39f2;
P_0c0a39f2: /* original 945c, guest PC 0x0c0a39f2 */
if(!s->budget--) { s->failed_pc=0x0c0a39f2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a3aaeu,2);
goto P_0c0a39f4;
P_0c0a39f4: /* original ba1a, guest PC 0x0c0a39f4 */
if(!s->budget--) { s->failed_pc=0x0c0a39f4u; return 0; }
target=0x0c0a2e2cu; r[16]=0x0c0a39f8u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a39f8u) { target=s->pc; goto dispatch; }
goto P_0c0a39f8;
P_0c0a39f6: /* original 0009, guest PC 0x0c0a39f6 */
if(!s->budget--) { s->failed_pc=0x0c0a39f6u; return 0; }
goto P_0c0a39f8;
P_0c0a39f8: /* original 945a, guest PC 0x0c0a39f8 */
if(!s->budget--) { s->failed_pc=0x0c0a39f8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a3ab0u,2);
goto P_0c0a39fa;
P_0c0a39fa: /* original ba17, guest PC 0x0c0a39fa */
if(!s->budget--) { s->failed_pc=0x0c0a39fau; return 0; }
target=0x0c0a2e2cu; r[16]=0x0c0a39feu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a39feu) { target=s->pc; goto dispatch; }
goto P_0c0a39fe;
P_0c0a39fc: /* original 0009, guest PC 0x0c0a39fc */
if(!s->budget--) { s->failed_pc=0x0c0a39fcu; return 0; }
goto P_0c0a39fe;
P_0c0a39fe: /* original 9458, guest PC 0x0c0a39fe */
if(!s->budget--) { s->failed_pc=0x0c0a39feu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a3ab2u,2);
goto P_0c0a3a00;
P_0c0a3a00: /* original ba14, guest PC 0x0c0a3a00 */
if(!s->budget--) { s->failed_pc=0x0c0a3a00u; return 0; }
target=0x0c0a2e2cu; r[16]=0x0c0a3a04u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a3a04u) { target=s->pc; goto dispatch; }
goto P_0c0a3a04;
P_0c0a3a02: /* original 0009, guest PC 0x0c0a3a02 */
if(!s->budget--) { s->failed_pc=0x0c0a3a02u; return 0; }
goto P_0c0a3a04;
P_0c0a3a04: /* original 9456, guest PC 0x0c0a3a04 */
if(!s->budget--) { s->failed_pc=0x0c0a3a04u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a3ab4u,2);
goto P_0c0a3a06;
P_0c0a3a06: /* original ba11, guest PC 0x0c0a3a06 */
if(!s->budget--) { s->failed_pc=0x0c0a3a06u; return 0; }
target=0x0c0a2e2cu; r[16]=0x0c0a3a0au;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a3a0au) { target=s->pc; goto dispatch; }
goto P_0c0a3a0a;
P_0c0a3a08: /* original 0009, guest PC 0x0c0a3a08 */
if(!s->budget--) { s->failed_pc=0x0c0a3a08u; return 0; }
goto P_0c0a3a0a;
P_0c0a3a0a: /* original 9454, guest PC 0x0c0a3a0a */
if(!s->budget--) { s->failed_pc=0x0c0a3a0au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a3ab6u,2);
goto P_0c0a3a0c;
P_0c0a3a0c: /* original ba0e, guest PC 0x0c0a3a0c */
if(!s->budget--) { s->failed_pc=0x0c0a3a0cu; return 0; }
target=0x0c0a2e2cu; r[16]=0x0c0a3a10u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a3a10u) { target=s->pc; goto dispatch; }
goto P_0c0a3a10;
P_0c0a3a0e: /* original 0009, guest PC 0x0c0a3a0e */
if(!s->budget--) { s->failed_pc=0x0c0a3a0eu; return 0; }
goto P_0c0a3a10;
P_0c0a3a10: /* original 9452, guest PC 0x0c0a3a10 */
if(!s->budget--) { s->failed_pc=0x0c0a3a10u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a3ab8u,2);
goto P_0c0a3a12;
P_0c0a3a12: /* original ba0b, guest PC 0x0c0a3a12 */
if(!s->budget--) { s->failed_pc=0x0c0a3a12u; return 0; }
target=0x0c0a2e2cu; r[16]=0x0c0a3a16u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a3a16u) { target=s->pc; goto dispatch; }
goto P_0c0a3a16;
P_0c0a3a14: /* original 0009, guest PC 0x0c0a3a14 */
if(!s->budget--) { s->failed_pc=0x0c0a3a14u; return 0; }
goto P_0c0a3a16;
P_0c0a3a16: /* original 9450, guest PC 0x0c0a3a16 */
if(!s->budget--) { s->failed_pc=0x0c0a3a16u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a3abau,2);
goto P_0c0a3a18;
P_0c0a3a18: /* original ba08, guest PC 0x0c0a3a18 */
if(!s->budget--) { s->failed_pc=0x0c0a3a18u; return 0; }
target=0x0c0a2e2cu; r[16]=0x0c0a3a1cu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a3a1cu) { target=s->pc; goto dispatch; }
goto P_0c0a3a1c;
P_0c0a3a1a: /* original 0009, guest PC 0x0c0a3a1a */
if(!s->budget--) { s->failed_pc=0x0c0a3a1au; return 0; }
goto P_0c0a3a1c;
P_0c0a3a1c: /* original 944e, guest PC 0x0c0a3a1c */
if(!s->budget--) { s->failed_pc=0x0c0a3a1cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a3abcu,2);
goto P_0c0a3a1e;
P_0c0a3a1e: /* original ba05, guest PC 0x0c0a3a1e */
if(!s->budget--) { s->failed_pc=0x0c0a3a1eu; return 0; }
target=0x0c0a2e2cu; r[16]=0x0c0a3a22u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a3a22u) { target=s->pc; goto dispatch; }
goto P_0c0a3a22;
P_0c0a3a20: /* original 0009, guest PC 0x0c0a3a20 */
if(!s->budget--) { s->failed_pc=0x0c0a3a20u; return 0; }
goto P_0c0a3a22;
P_0c0a3a22: /* original 944c, guest PC 0x0c0a3a22 */
if(!s->budget--) { s->failed_pc=0x0c0a3a22u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a3abeu,2);
goto P_0c0a3a24;
P_0c0a3a24: /* original ba02, guest PC 0x0c0a3a24 */
if(!s->budget--) { s->failed_pc=0x0c0a3a24u; return 0; }
target=0x0c0a2e2cu; r[16]=0x0c0a3a28u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a3a28u) { target=s->pc; goto dispatch; }
goto P_0c0a3a28;
P_0c0a3a26: /* original 0009, guest PC 0x0c0a3a26 */
if(!s->budget--) { s->failed_pc=0x0c0a3a26u; return 0; }
goto P_0c0a3a28;
P_0c0a3a28: /* original 944a, guest PC 0x0c0a3a28 */
if(!s->budget--) { s->failed_pc=0x0c0a3a28u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a3ac0u,2);
goto P_0c0a3a2a;
P_0c0a3a2a: /* original b9ff, guest PC 0x0c0a3a2a */
if(!s->budget--) { s->failed_pc=0x0c0a3a2au; return 0; }
target=0x0c0a2e2cu; r[16]=0x0c0a3a2eu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a3a2eu) { target=s->pc; goto dispatch; }
goto P_0c0a3a2e;
P_0c0a3a2c: /* original 0009, guest PC 0x0c0a3a2c */
if(!s->budget--) { s->failed_pc=0x0c0a3a2cu; return 0; }
goto P_0c0a3a2e;
P_0c0a3a2e: /* original 9448, guest PC 0x0c0a3a2e */
if(!s->budget--) { s->failed_pc=0x0c0a3a2eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a3ac2u,2);
goto P_0c0a3a30;
P_0c0a3a30: /* original b9fc, guest PC 0x0c0a3a30 */
if(!s->budget--) { s->failed_pc=0x0c0a3a30u; return 0; }
target=0x0c0a2e2cu; r[16]=0x0c0a3a34u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a3a34u) { target=s->pc; goto dispatch; }
goto P_0c0a3a34;
P_0c0a3a32: /* original 0009, guest PC 0x0c0a3a32 */
if(!s->budget--) { s->failed_pc=0x0c0a3a32u; return 0; }
goto P_0c0a3a34;
P_0c0a3a34: /* original 9446, guest PC 0x0c0a3a34 */
if(!s->budget--) { s->failed_pc=0x0c0a3a34u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a3ac4u,2);
goto P_0c0a3a36;
P_0c0a3a36: /* original b9f9, guest PC 0x0c0a3a36 */
if(!s->budget--) { s->failed_pc=0x0c0a3a36u; return 0; }
target=0x0c0a2e2cu; r[16]=0x0c0a3a3au;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a3a3au) { target=s->pc; goto dispatch; }
goto P_0c0a3a3a;
P_0c0a3a38: /* original 0009, guest PC 0x0c0a3a38 */
if(!s->budget--) { s->failed_pc=0x0c0a3a38u; return 0; }
goto P_0c0a3a3a;
P_0c0a3a3a: /* original 9444, guest PC 0x0c0a3a3a */
if(!s->budget--) { s->failed_pc=0x0c0a3a3au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a3ac6u,2);
goto P_0c0a3a3c;
P_0c0a3a3c: /* original b9f6, guest PC 0x0c0a3a3c */
if(!s->budget--) { s->failed_pc=0x0c0a3a3cu; return 0; }
target=0x0c0a2e2cu; r[16]=0x0c0a3a40u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a3a40u) { target=s->pc; goto dispatch; }
goto P_0c0a3a40;
P_0c0a3a3e: /* original 0009, guest PC 0x0c0a3a3e */
if(!s->budget--) { s->failed_pc=0x0c0a3a3eu; return 0; }
goto P_0c0a3a40;
P_0c0a3a40: /* original 9442, guest PC 0x0c0a3a40 */
if(!s->budget--) { s->failed_pc=0x0c0a3a40u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a3ac8u,2);
goto P_0c0a3a42;
P_0c0a3a42: /* original b9f3, guest PC 0x0c0a3a42 */
if(!s->budget--) { s->failed_pc=0x0c0a3a42u; return 0; }
target=0x0c0a2e2cu; r[16]=0x0c0a3a46u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a3a46u) { target=s->pc; goto dispatch; }
goto P_0c0a3a46;
P_0c0a3a44: /* original 0009, guest PC 0x0c0a3a44 */
if(!s->budget--) { s->failed_pc=0x0c0a3a44u; return 0; }
goto P_0c0a3a46;
P_0c0a3a46: /* original 9440, guest PC 0x0c0a3a46 */
if(!s->budget--) { s->failed_pc=0x0c0a3a46u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a3acau,2);
goto P_0c0a3a48;
P_0c0a3a48: /* original b9f0, guest PC 0x0c0a3a48 */
if(!s->budget--) { s->failed_pc=0x0c0a3a48u; return 0; }
target=0x0c0a2e2cu; r[16]=0x0c0a3a4cu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a3a4cu) { target=s->pc; goto dispatch; }
goto P_0c0a3a4c;
P_0c0a3a4a: /* original 0009, guest PC 0x0c0a3a4a */
if(!s->budget--) { s->failed_pc=0x0c0a3a4au; return 0; }
goto P_0c0a3a4c;
P_0c0a3a4c: /* original 943e, guest PC 0x0c0a3a4c */
if(!s->budget--) { s->failed_pc=0x0c0a3a4cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a3accu,2);
goto P_0c0a3a4e;
P_0c0a3a4e: /* original b9ed, guest PC 0x0c0a3a4e */
if(!s->budget--) { s->failed_pc=0x0c0a3a4eu; return 0; }
target=0x0c0a2e2cu; r[16]=0x0c0a3a52u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a3a52u) { target=s->pc; goto dispatch; }
goto P_0c0a3a52;
P_0c0a3a50: /* original 0009, guest PC 0x0c0a3a50 */
if(!s->budget--) { s->failed_pc=0x0c0a3a50u; return 0; }
goto P_0c0a3a52;
P_0c0a3a52: /* original 943c, guest PC 0x0c0a3a52 */
if(!s->budget--) { s->failed_pc=0x0c0a3a52u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a3aceu,2);
goto P_0c0a3a54;
P_0c0a3a54: /* original b9ea, guest PC 0x0c0a3a54 */
if(!s->budget--) { s->failed_pc=0x0c0a3a54u; return 0; }
target=0x0c0a2e2cu; r[16]=0x0c0a3a58u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a3a58u) { target=s->pc; goto dispatch; }
goto P_0c0a3a58;
P_0c0a3a56: /* original 0009, guest PC 0x0c0a3a56 */
if(!s->budget--) { s->failed_pc=0x0c0a3a56u; return 0; }
goto P_0c0a3a58;
P_0c0a3a58: /* original 943a, guest PC 0x0c0a3a58 */
if(!s->budget--) { s->failed_pc=0x0c0a3a58u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a3ad0u,2);
goto P_0c0a3a5a;
P_0c0a3a5a: /* original b9e7, guest PC 0x0c0a3a5a */
if(!s->budget--) { s->failed_pc=0x0c0a3a5au; return 0; }
target=0x0c0a2e2cu; r[16]=0x0c0a3a5eu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a3a5eu) { target=s->pc; goto dispatch; }
goto P_0c0a3a5e;
P_0c0a3a5c: /* original 0009, guest PC 0x0c0a3a5c */
if(!s->budget--) { s->failed_pc=0x0c0a3a5cu; return 0; }
goto P_0c0a3a5e;
P_0c0a3a5e: /* original 9438, guest PC 0x0c0a3a5e */
if(!s->budget--) { s->failed_pc=0x0c0a3a5eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a3ad2u,2);
goto P_0c0a3a60;
P_0c0a3a60: /* original b9e4, guest PC 0x0c0a3a60 */
if(!s->budget--) { s->failed_pc=0x0c0a3a60u; return 0; }
target=0x0c0a2e2cu; r[16]=0x0c0a3a64u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a3a64u) { target=s->pc; goto dispatch; }
goto P_0c0a3a64;
P_0c0a3a62: /* original 0009, guest PC 0x0c0a3a62 */
if(!s->budget--) { s->failed_pc=0x0c0a3a62u; return 0; }
goto P_0c0a3a64;
P_0c0a3a64: /* original 9436, guest PC 0x0c0a3a64 */
if(!s->budget--) { s->failed_pc=0x0c0a3a64u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a3ad4u,2);
goto P_0c0a3a66;
P_0c0a3a66: /* original b9e1, guest PC 0x0c0a3a66 */
if(!s->budget--) { s->failed_pc=0x0c0a3a66u; return 0; }
target=0x0c0a2e2cu; r[16]=0x0c0a3a6au;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a3a6au) { target=s->pc; goto dispatch; }
goto P_0c0a3a6a;
P_0c0a3a68: /* original 0009, guest PC 0x0c0a3a68 */
if(!s->budget--) { s->failed_pc=0x0c0a3a68u; return 0; }
goto P_0c0a3a6a;
P_0c0a3a6a: /* original 9434, guest PC 0x0c0a3a6a */
if(!s->budget--) { s->failed_pc=0x0c0a3a6au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a3ad6u,2);
goto P_0c0a3a6c;
P_0c0a3a6c: /* original b9de, guest PC 0x0c0a3a6c */
if(!s->budget--) { s->failed_pc=0x0c0a3a6cu; return 0; }
target=0x0c0a2e2cu; r[16]=0x0c0a3a70u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a3a70u) { target=s->pc; goto dispatch; }
goto P_0c0a3a70;
P_0c0a3a6e: /* original 0009, guest PC 0x0c0a3a6e */
if(!s->budget--) { s->failed_pc=0x0c0a3a6eu; return 0; }
goto P_0c0a3a70;
P_0c0a3a70: /* original 9432, guest PC 0x0c0a3a70 */
if(!s->budget--) { s->failed_pc=0x0c0a3a70u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a3ad8u,2);
goto P_0c0a3a72;
P_0c0a3a72: /* original b9db, guest PC 0x0c0a3a72 */
if(!s->budget--) { s->failed_pc=0x0c0a3a72u; return 0; }
target=0x0c0a2e2cu; r[16]=0x0c0a3a76u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a3a76u) { target=s->pc; goto dispatch; }
goto P_0c0a3a76;
P_0c0a3a74: /* original 0009, guest PC 0x0c0a3a74 */
if(!s->budget--) { s->failed_pc=0x0c0a3a74u; return 0; }
goto P_0c0a3a76;
P_0c0a3a76: /* original 9430, guest PC 0x0c0a3a76 */
if(!s->budget--) { s->failed_pc=0x0c0a3a76u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a3adau,2);
goto P_0c0a3a78;
P_0c0a3a78: /* original b9d8, guest PC 0x0c0a3a78 */
if(!s->budget--) { s->failed_pc=0x0c0a3a78u; return 0; }
target=0x0c0a2e2cu; r[16]=0x0c0a3a7cu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a3a7cu) { target=s->pc; goto dispatch; }
goto P_0c0a3a7c;
P_0c0a3a7a: /* original 0009, guest PC 0x0c0a3a7a */
if(!s->budget--) { s->failed_pc=0x0c0a3a7au; return 0; }
goto P_0c0a3a7c;
P_0c0a3a7c: /* original 942e, guest PC 0x0c0a3a7c */
if(!s->budget--) { s->failed_pc=0x0c0a3a7cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a3adcu,2);
goto P_0c0a3a7e;
P_0c0a3a7e: /* original a02e, guest PC 0x0c0a3a7e */
if(!s->budget--) { s->failed_pc=0x0c0a3a7eu; return 0; }
goto P_0c0a3ade;
P_0c0a3a80: /* original 0009, guest PC 0x0c0a3a80 */
if(!s->budget--) { s->failed_pc=0x0c0a3a80u; return 0; }
return vf3_matrix_family(0x0c0a3a82u,s,ram);
P_0c0a3ade: /* original b9a5, guest PC 0x0c0a3ade */
if(!s->budget--) { s->failed_pc=0x0c0a3adeu; return 0; }
target=0x0c0a2e2cu; r[16]=0x0c0a3ae2u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a3ae2u) { target=s->pc; goto dispatch; }
goto P_0c0a3ae2;
P_0c0a3ae0: /* original 0009, guest PC 0x0c0a3ae0 */
if(!s->budget--) { s->failed_pc=0x0c0a3ae0u; return 0; }
goto P_0c0a3ae2;
P_0c0a3ae2: /* original 9404, guest PC 0x0c0a3ae2 */
if(!s->budget--) { s->failed_pc=0x0c0a3ae2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a3aeeu,2);
goto P_0c0a3ae4;
P_0c0a3ae4: /* original b9a2, guest PC 0x0c0a3ae4 */
if(!s->budget--) { s->failed_pc=0x0c0a3ae4u; return 0; }
target=0x0c0a2e2cu; r[16]=0x0c0a3ae8u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a3ae8u) { target=s->pc; goto dispatch; }
goto P_0c0a3ae8;
P_0c0a3ae6: /* original 0009, guest PC 0x0c0a3ae6 */
if(!s->budget--) { s->failed_pc=0x0c0a3ae6u; return 0; }
goto P_0c0a3ae8;
P_0c0a3ae8: /* original 9402, guest PC 0x0c0a3ae8 */
if(!s->budget--) { s->failed_pc=0x0c0a3ae8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a3af0u,2);
goto P_0c0a3aea;
P_0c0a3aea: /* original a99f, guest PC 0x0c0a3aea */
if(!s->budget--) { s->failed_pc=0x0c0a3aeau; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a2e2c;
P_0c0a3aec: /* original 4f26, guest PC 0x0c0a3aec */
if(!s->budget--) { s->failed_pc=0x0c0a3aecu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
return vf3_matrix_family(0x0c0a3aeeu,s,ram);
P_0c0a3c98: /* original 4f22, guest PC 0x0c0a3c98 */
if(!s->budget--) { s->failed_pc=0x0c0a3c98u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0a3c9a;
P_0c0a3c9a: /* original 9488, guest PC 0x0c0a3c9a */
if(!s->budget--) { s->failed_pc=0x0c0a3c9au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a3daeu,2);
goto P_0c0a3c9c;
P_0c0a3c9c: /* original b8c6, guest PC 0x0c0a3c9c */
if(!s->budget--) { s->failed_pc=0x0c0a3c9cu; return 0; }
target=0x0c0a2e2cu; r[16]=0x0c0a3ca0u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a3ca0u) { target=s->pc; goto dispatch; }
goto P_0c0a3ca0;
P_0c0a3c9e: /* original 0009, guest PC 0x0c0a3c9e */
if(!s->budget--) { s->failed_pc=0x0c0a3c9eu; return 0; }
goto P_0c0a3ca0;
P_0c0a3ca0: /* original 9486, guest PC 0x0c0a3ca0 */
if(!s->budget--) { s->failed_pc=0x0c0a3ca0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a3db0u,2);
goto P_0c0a3ca2;
P_0c0a3ca2: /* original b8c3, guest PC 0x0c0a3ca2 */
if(!s->budget--) { s->failed_pc=0x0c0a3ca2u; return 0; }
target=0x0c0a2e2cu; r[16]=0x0c0a3ca6u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a3ca6u) { target=s->pc; goto dispatch; }
goto P_0c0a3ca6;
P_0c0a3ca4: /* original 0009, guest PC 0x0c0a3ca4 */
if(!s->budget--) { s->failed_pc=0x0c0a3ca4u; return 0; }
goto P_0c0a3ca6;
P_0c0a3ca6: /* original 9484, guest PC 0x0c0a3ca6 */
if(!s->budget--) { s->failed_pc=0x0c0a3ca6u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a3db2u,2);
goto P_0c0a3ca8;
P_0c0a3ca8: /* original b8c0, guest PC 0x0c0a3ca8 */
if(!s->budget--) { s->failed_pc=0x0c0a3ca8u; return 0; }
target=0x0c0a2e2cu; r[16]=0x0c0a3cacu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a3cacu) { target=s->pc; goto dispatch; }
goto P_0c0a3cac;
P_0c0a3caa: /* original 0009, guest PC 0x0c0a3caa */
if(!s->budget--) { s->failed_pc=0x0c0a3caau; return 0; }
goto P_0c0a3cac;
P_0c0a3cac: /* original 9482, guest PC 0x0c0a3cac */
if(!s->budget--) { s->failed_pc=0x0c0a3cacu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a3db4u,2);
goto P_0c0a3cae;
P_0c0a3cae: /* original b8bd, guest PC 0x0c0a3cae */
if(!s->budget--) { s->failed_pc=0x0c0a3caeu; return 0; }
target=0x0c0a2e2cu; r[16]=0x0c0a3cb2u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a3cb2u) { target=s->pc; goto dispatch; }
goto P_0c0a3cb2;
P_0c0a3cb0: /* original 0009, guest PC 0x0c0a3cb0 */
if(!s->budget--) { s->failed_pc=0x0c0a3cb0u; return 0; }
goto P_0c0a3cb2;
P_0c0a3cb2: /* original 9480, guest PC 0x0c0a3cb2 */
if(!s->budget--) { s->failed_pc=0x0c0a3cb2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a3db6u,2);
goto P_0c0a3cb4;
P_0c0a3cb4: /* original b8ba, guest PC 0x0c0a3cb4 */
if(!s->budget--) { s->failed_pc=0x0c0a3cb4u; return 0; }
target=0x0c0a2e2cu; r[16]=0x0c0a3cb8u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a3cb8u) { target=s->pc; goto dispatch; }
goto P_0c0a3cb8;
P_0c0a3cb6: /* original 0009, guest PC 0x0c0a3cb6 */
if(!s->budget--) { s->failed_pc=0x0c0a3cb6u; return 0; }
goto P_0c0a3cb8;
P_0c0a3cb8: /* original 947e, guest PC 0x0c0a3cb8 */
if(!s->budget--) { s->failed_pc=0x0c0a3cb8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a3db8u,2);
goto P_0c0a3cba;
P_0c0a3cba: /* original b8b7, guest PC 0x0c0a3cba */
if(!s->budget--) { s->failed_pc=0x0c0a3cbau; return 0; }
target=0x0c0a2e2cu; r[16]=0x0c0a3cbeu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a3cbeu) { target=s->pc; goto dispatch; }
goto P_0c0a3cbe;
P_0c0a3cbc: /* original 0009, guest PC 0x0c0a3cbc */
if(!s->budget--) { s->failed_pc=0x0c0a3cbcu; return 0; }
goto P_0c0a3cbe;
P_0c0a3cbe: /* original 947c, guest PC 0x0c0a3cbe */
if(!s->budget--) { s->failed_pc=0x0c0a3cbeu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a3dbau,2);
goto P_0c0a3cc0;
P_0c0a3cc0: /* original b8b4, guest PC 0x0c0a3cc0 */
if(!s->budget--) { s->failed_pc=0x0c0a3cc0u; return 0; }
target=0x0c0a2e2cu; r[16]=0x0c0a3cc4u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a3cc4u) { target=s->pc; goto dispatch; }
goto P_0c0a3cc4;
P_0c0a3cc2: /* original 0009, guest PC 0x0c0a3cc2 */
if(!s->budget--) { s->failed_pc=0x0c0a3cc2u; return 0; }
goto P_0c0a3cc4;
P_0c0a3cc4: /* original 947a, guest PC 0x0c0a3cc4 */
if(!s->budget--) { s->failed_pc=0x0c0a3cc4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a3dbcu,2);
goto P_0c0a3cc6;
P_0c0a3cc6: /* original b8b1, guest PC 0x0c0a3cc6 */
if(!s->budget--) { s->failed_pc=0x0c0a3cc6u; return 0; }
target=0x0c0a2e2cu; r[16]=0x0c0a3ccau;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a3ccau) { target=s->pc; goto dispatch; }
goto P_0c0a3cca;
P_0c0a3cc8: /* original 0009, guest PC 0x0c0a3cc8 */
if(!s->budget--) { s->failed_pc=0x0c0a3cc8u; return 0; }
goto P_0c0a3cca;
P_0c0a3cca: /* original 9478, guest PC 0x0c0a3cca */
if(!s->budget--) { s->failed_pc=0x0c0a3ccau; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a3dbeu,2);
goto P_0c0a3ccc;
P_0c0a3ccc: /* original b8ae, guest PC 0x0c0a3ccc */
if(!s->budget--) { s->failed_pc=0x0c0a3cccu; return 0; }
target=0x0c0a2e2cu; r[16]=0x0c0a3cd0u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a3cd0u) { target=s->pc; goto dispatch; }
goto P_0c0a3cd0;
P_0c0a3cce: /* original 0009, guest PC 0x0c0a3cce */
if(!s->budget--) { s->failed_pc=0x0c0a3cceu; return 0; }
goto P_0c0a3cd0;
P_0c0a3cd0: /* original 9476, guest PC 0x0c0a3cd0 */
if(!s->budget--) { s->failed_pc=0x0c0a3cd0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a3dc0u,2);
goto P_0c0a3cd2;
P_0c0a3cd2: /* original b8ab, guest PC 0x0c0a3cd2 */
if(!s->budget--) { s->failed_pc=0x0c0a3cd2u; return 0; }
target=0x0c0a2e2cu; r[16]=0x0c0a3cd6u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a3cd6u) { target=s->pc; goto dispatch; }
goto P_0c0a3cd6;
P_0c0a3cd4: /* original 0009, guest PC 0x0c0a3cd4 */
if(!s->budget--) { s->failed_pc=0x0c0a3cd4u; return 0; }
goto P_0c0a3cd6;
P_0c0a3cd6: /* original 9474, guest PC 0x0c0a3cd6 */
if(!s->budget--) { s->failed_pc=0x0c0a3cd6u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a3dc2u,2);
goto P_0c0a3cd8;
P_0c0a3cd8: /* original b8a8, guest PC 0x0c0a3cd8 */
if(!s->budget--) { s->failed_pc=0x0c0a3cd8u; return 0; }
target=0x0c0a2e2cu; r[16]=0x0c0a3cdcu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a3cdcu) { target=s->pc; goto dispatch; }
goto P_0c0a3cdc;
P_0c0a3cda: /* original 0009, guest PC 0x0c0a3cda */
if(!s->budget--) { s->failed_pc=0x0c0a3cdau; return 0; }
goto P_0c0a3cdc;
P_0c0a3cdc: /* original 9472, guest PC 0x0c0a3cdc */
if(!s->budget--) { s->failed_pc=0x0c0a3cdcu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a3dc4u,2);
goto P_0c0a3cde;
P_0c0a3cde: /* original b8a5, guest PC 0x0c0a3cde */
if(!s->budget--) { s->failed_pc=0x0c0a3cdeu; return 0; }
target=0x0c0a2e2cu; r[16]=0x0c0a3ce2u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a3ce2u) { target=s->pc; goto dispatch; }
goto P_0c0a3ce2;
P_0c0a3ce0: /* original 0009, guest PC 0x0c0a3ce0 */
if(!s->budget--) { s->failed_pc=0x0c0a3ce0u; return 0; }
goto P_0c0a3ce2;
P_0c0a3ce2: /* original 9470, guest PC 0x0c0a3ce2 */
if(!s->budget--) { s->failed_pc=0x0c0a3ce2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a3dc6u,2);
goto P_0c0a3ce4;
P_0c0a3ce4: /* original b8a2, guest PC 0x0c0a3ce4 */
if(!s->budget--) { s->failed_pc=0x0c0a3ce4u; return 0; }
target=0x0c0a2e2cu; r[16]=0x0c0a3ce8u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a3ce8u) { target=s->pc; goto dispatch; }
goto P_0c0a3ce8;
P_0c0a3ce6: /* original 0009, guest PC 0x0c0a3ce6 */
if(!s->budget--) { s->failed_pc=0x0c0a3ce6u; return 0; }
goto P_0c0a3ce8;
P_0c0a3ce8: /* original 946e, guest PC 0x0c0a3ce8 */
if(!s->budget--) { s->failed_pc=0x0c0a3ce8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a3dc8u,2);
goto P_0c0a3cea;
P_0c0a3cea: /* original b89f, guest PC 0x0c0a3cea */
if(!s->budget--) { s->failed_pc=0x0c0a3ceau; return 0; }
target=0x0c0a2e2cu; r[16]=0x0c0a3ceeu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a3ceeu) { target=s->pc; goto dispatch; }
goto P_0c0a3cee;
P_0c0a3cec: /* original 0009, guest PC 0x0c0a3cec */
if(!s->budget--) { s->failed_pc=0x0c0a3cecu; return 0; }
goto P_0c0a3cee;
P_0c0a3cee: /* original 946c, guest PC 0x0c0a3cee */
if(!s->budget--) { s->failed_pc=0x0c0a3ceeu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a3dcau,2);
goto P_0c0a3cf0;
P_0c0a3cf0: /* original b89c, guest PC 0x0c0a3cf0 */
if(!s->budget--) { s->failed_pc=0x0c0a3cf0u; return 0; }
target=0x0c0a2e2cu; r[16]=0x0c0a3cf4u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a3cf4u) { target=s->pc; goto dispatch; }
goto P_0c0a3cf4;
P_0c0a3cf2: /* original 0009, guest PC 0x0c0a3cf2 */
if(!s->budget--) { s->failed_pc=0x0c0a3cf2u; return 0; }
goto P_0c0a3cf4;
P_0c0a3cf4: /* original 946a, guest PC 0x0c0a3cf4 */
if(!s->budget--) { s->failed_pc=0x0c0a3cf4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a3dccu,2);
goto P_0c0a3cf6;
P_0c0a3cf6: /* original b899, guest PC 0x0c0a3cf6 */
if(!s->budget--) { s->failed_pc=0x0c0a3cf6u; return 0; }
target=0x0c0a2e2cu; r[16]=0x0c0a3cfau;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a3cfau) { target=s->pc; goto dispatch; }
goto P_0c0a3cfa;
P_0c0a3cf8: /* original 0009, guest PC 0x0c0a3cf8 */
if(!s->budget--) { s->failed_pc=0x0c0a3cf8u; return 0; }
goto P_0c0a3cfa;
P_0c0a3cfa: /* original 9468, guest PC 0x0c0a3cfa */
if(!s->budget--) { s->failed_pc=0x0c0a3cfau; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a3dceu,2);
goto P_0c0a3cfc;
P_0c0a3cfc: /* original b896, guest PC 0x0c0a3cfc */
if(!s->budget--) { s->failed_pc=0x0c0a3cfcu; return 0; }
target=0x0c0a2e2cu; r[16]=0x0c0a3d00u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a3d00u) { target=s->pc; goto dispatch; }
goto P_0c0a3d00;
P_0c0a3cfe: /* original 0009, guest PC 0x0c0a3cfe */
if(!s->budget--) { s->failed_pc=0x0c0a3cfeu; return 0; }
goto P_0c0a3d00;
P_0c0a3d00: /* original 9466, guest PC 0x0c0a3d00 */
if(!s->budget--) { s->failed_pc=0x0c0a3d00u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a3dd0u,2);
goto P_0c0a3d02;
P_0c0a3d02: /* original b893, guest PC 0x0c0a3d02 */
if(!s->budget--) { s->failed_pc=0x0c0a3d02u; return 0; }
target=0x0c0a2e2cu; r[16]=0x0c0a3d06u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a3d06u) { target=s->pc; goto dispatch; }
goto P_0c0a3d06;
P_0c0a3d04: /* original 0009, guest PC 0x0c0a3d04 */
if(!s->budget--) { s->failed_pc=0x0c0a3d04u; return 0; }
goto P_0c0a3d06;
P_0c0a3d06: /* original 9464, guest PC 0x0c0a3d06 */
if(!s->budget--) { s->failed_pc=0x0c0a3d06u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a3dd2u,2);
goto P_0c0a3d08;
P_0c0a3d08: /* original b890, guest PC 0x0c0a3d08 */
if(!s->budget--) { s->failed_pc=0x0c0a3d08u; return 0; }
target=0x0c0a2e2cu; r[16]=0x0c0a3d0cu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a3d0cu) { target=s->pc; goto dispatch; }
goto P_0c0a3d0c;
P_0c0a3d0a: /* original 0009, guest PC 0x0c0a3d0a */
if(!s->budget--) { s->failed_pc=0x0c0a3d0au; return 0; }
goto P_0c0a3d0c;
P_0c0a3d0c: /* original 9462, guest PC 0x0c0a3d0c */
if(!s->budget--) { s->failed_pc=0x0c0a3d0cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a3dd4u,2);
goto P_0c0a3d0e;
P_0c0a3d0e: /* original b88d, guest PC 0x0c0a3d0e */
if(!s->budget--) { s->failed_pc=0x0c0a3d0eu; return 0; }
target=0x0c0a2e2cu; r[16]=0x0c0a3d12u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a3d12u) { target=s->pc; goto dispatch; }
goto P_0c0a3d12;
P_0c0a3d10: /* original 0009, guest PC 0x0c0a3d10 */
if(!s->budget--) { s->failed_pc=0x0c0a3d10u; return 0; }
goto P_0c0a3d12;
P_0c0a3d12: /* original 9460, guest PC 0x0c0a3d12 */
if(!s->budget--) { s->failed_pc=0x0c0a3d12u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a3dd6u,2);
goto P_0c0a3d14;
P_0c0a3d14: /* original b88a, guest PC 0x0c0a3d14 */
if(!s->budget--) { s->failed_pc=0x0c0a3d14u; return 0; }
target=0x0c0a2e2cu; r[16]=0x0c0a3d18u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a3d18u) { target=s->pc; goto dispatch; }
goto P_0c0a3d18;
P_0c0a3d16: /* original 0009, guest PC 0x0c0a3d16 */
if(!s->budget--) { s->failed_pc=0x0c0a3d16u; return 0; }
goto P_0c0a3d18;
P_0c0a3d18: /* original 945e, guest PC 0x0c0a3d18 */
if(!s->budget--) { s->failed_pc=0x0c0a3d18u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a3dd8u,2);
goto P_0c0a3d1a;
P_0c0a3d1a: /* original b887, guest PC 0x0c0a3d1a */
if(!s->budget--) { s->failed_pc=0x0c0a3d1au; return 0; }
target=0x0c0a2e2cu; r[16]=0x0c0a3d1eu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a3d1eu) { target=s->pc; goto dispatch; }
goto P_0c0a3d1e;
P_0c0a3d1c: /* original 0009, guest PC 0x0c0a3d1c */
if(!s->budget--) { s->failed_pc=0x0c0a3d1cu; return 0; }
goto P_0c0a3d1e;
P_0c0a3d1e: /* original 945c, guest PC 0x0c0a3d1e */
if(!s->budget--) { s->failed_pc=0x0c0a3d1eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a3ddau,2);
goto P_0c0a3d20;
P_0c0a3d20: /* original b884, guest PC 0x0c0a3d20 */
if(!s->budget--) { s->failed_pc=0x0c0a3d20u; return 0; }
target=0x0c0a2e2cu; r[16]=0x0c0a3d24u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a3d24u) { target=s->pc; goto dispatch; }
goto P_0c0a3d24;
P_0c0a3d22: /* original 0009, guest PC 0x0c0a3d22 */
if(!s->budget--) { s->failed_pc=0x0c0a3d22u; return 0; }
goto P_0c0a3d24;
P_0c0a3d24: /* original 945a, guest PC 0x0c0a3d24 */
if(!s->budget--) { s->failed_pc=0x0c0a3d24u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a3ddcu,2);
goto P_0c0a3d26;
P_0c0a3d26: /* original b881, guest PC 0x0c0a3d26 */
if(!s->budget--) { s->failed_pc=0x0c0a3d26u; return 0; }
target=0x0c0a2e2cu; r[16]=0x0c0a3d2au;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a3d2au) { target=s->pc; goto dispatch; }
goto P_0c0a3d2a;
P_0c0a3d28: /* original 0009, guest PC 0x0c0a3d28 */
if(!s->budget--) { s->failed_pc=0x0c0a3d28u; return 0; }
goto P_0c0a3d2a;
P_0c0a3d2a: /* original 9458, guest PC 0x0c0a3d2a */
if(!s->budget--) { s->failed_pc=0x0c0a3d2au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a3ddeu,2);
goto P_0c0a3d2c;
P_0c0a3d2c: /* original b87e, guest PC 0x0c0a3d2c */
if(!s->budget--) { s->failed_pc=0x0c0a3d2cu; return 0; }
target=0x0c0a2e2cu; r[16]=0x0c0a3d30u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a3d30u) { target=s->pc; goto dispatch; }
goto P_0c0a3d30;
P_0c0a3d2e: /* original 0009, guest PC 0x0c0a3d2e */
if(!s->budget--) { s->failed_pc=0x0c0a3d2eu; return 0; }
goto P_0c0a3d30;
P_0c0a3d30: /* original 9456, guest PC 0x0c0a3d30 */
if(!s->budget--) { s->failed_pc=0x0c0a3d30u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a3de0u,2);
goto P_0c0a3d32;
P_0c0a3d32: /* original b87b, guest PC 0x0c0a3d32 */
if(!s->budget--) { s->failed_pc=0x0c0a3d32u; return 0; }
target=0x0c0a2e2cu; r[16]=0x0c0a3d36u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a3d36u) { target=s->pc; goto dispatch; }
goto P_0c0a3d36;
P_0c0a3d34: /* original 0009, guest PC 0x0c0a3d34 */
if(!s->budget--) { s->failed_pc=0x0c0a3d34u; return 0; }
goto P_0c0a3d36;
P_0c0a3d36: /* original 9454, guest PC 0x0c0a3d36 */
if(!s->budget--) { s->failed_pc=0x0c0a3d36u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a3de2u,2);
goto P_0c0a3d38;
P_0c0a3d38: /* original b878, guest PC 0x0c0a3d38 */
if(!s->budget--) { s->failed_pc=0x0c0a3d38u; return 0; }
target=0x0c0a2e2cu; r[16]=0x0c0a3d3cu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a3d3cu) { target=s->pc; goto dispatch; }
goto P_0c0a3d3c;
P_0c0a3d3a: /* original 0009, guest PC 0x0c0a3d3a */
if(!s->budget--) { s->failed_pc=0x0c0a3d3au; return 0; }
goto P_0c0a3d3c;
P_0c0a3d3c: /* original 9452, guest PC 0x0c0a3d3c */
if(!s->budget--) { s->failed_pc=0x0c0a3d3cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a3de4u,2);
goto P_0c0a3d3e;
P_0c0a3d3e: /* original b875, guest PC 0x0c0a3d3e */
if(!s->budget--) { s->failed_pc=0x0c0a3d3eu; return 0; }
target=0x0c0a2e2cu; r[16]=0x0c0a3d42u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a3d42u) { target=s->pc; goto dispatch; }
goto P_0c0a3d42;
P_0c0a3d40: /* original 0009, guest PC 0x0c0a3d40 */
if(!s->budget--) { s->failed_pc=0x0c0a3d40u; return 0; }
goto P_0c0a3d42;
P_0c0a3d42: /* original 9450, guest PC 0x0c0a3d42 */
if(!s->budget--) { s->failed_pc=0x0c0a3d42u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a3de6u,2);
goto P_0c0a3d44;
P_0c0a3d44: /* original b872, guest PC 0x0c0a3d44 */
if(!s->budget--) { s->failed_pc=0x0c0a3d44u; return 0; }
target=0x0c0a2e2cu; r[16]=0x0c0a3d48u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a3d48u) { target=s->pc; goto dispatch; }
goto P_0c0a3d48;
P_0c0a3d46: /* original 0009, guest PC 0x0c0a3d46 */
if(!s->budget--) { s->failed_pc=0x0c0a3d46u; return 0; }
goto P_0c0a3d48;
P_0c0a3d48: /* original 944e, guest PC 0x0c0a3d48 */
if(!s->budget--) { s->failed_pc=0x0c0a3d48u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a3de8u,2);
goto P_0c0a3d4a;
P_0c0a3d4a: /* original b86f, guest PC 0x0c0a3d4a */
if(!s->budget--) { s->failed_pc=0x0c0a3d4au; return 0; }
target=0x0c0a2e2cu; r[16]=0x0c0a3d4eu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a3d4eu) { target=s->pc; goto dispatch; }
goto P_0c0a3d4e;
P_0c0a3d4c: /* original 0009, guest PC 0x0c0a3d4c */
if(!s->budget--) { s->failed_pc=0x0c0a3d4cu; return 0; }
goto P_0c0a3d4e;
P_0c0a3d4e: /* original 944c, guest PC 0x0c0a3d4e */
if(!s->budget--) { s->failed_pc=0x0c0a3d4eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a3deau,2);
goto P_0c0a3d50;
P_0c0a3d50: /* original b86c, guest PC 0x0c0a3d50 */
if(!s->budget--) { s->failed_pc=0x0c0a3d50u; return 0; }
target=0x0c0a2e2cu; r[16]=0x0c0a3d54u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a3d54u) { target=s->pc; goto dispatch; }
goto P_0c0a3d54;
P_0c0a3d52: /* original 0009, guest PC 0x0c0a3d52 */
if(!s->budget--) { s->failed_pc=0x0c0a3d52u; return 0; }
goto P_0c0a3d54;
P_0c0a3d54: /* original 944a, guest PC 0x0c0a3d54 */
if(!s->budget--) { s->failed_pc=0x0c0a3d54u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a3decu,2);
goto P_0c0a3d56;
P_0c0a3d56: /* original b869, guest PC 0x0c0a3d56 */
if(!s->budget--) { s->failed_pc=0x0c0a3d56u; return 0; }
target=0x0c0a2e2cu; r[16]=0x0c0a3d5au;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a3d5au) { target=s->pc; goto dispatch; }
goto P_0c0a3d5a;
P_0c0a3d58: /* original 0009, guest PC 0x0c0a3d58 */
if(!s->budget--) { s->failed_pc=0x0c0a3d58u; return 0; }
goto P_0c0a3d5a;
P_0c0a3d5a: /* original 9448, guest PC 0x0c0a3d5a */
if(!s->budget--) { s->failed_pc=0x0c0a3d5au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a3deeu,2);
goto P_0c0a3d5c;
P_0c0a3d5c: /* original b866, guest PC 0x0c0a3d5c */
if(!s->budget--) { s->failed_pc=0x0c0a3d5cu; return 0; }
target=0x0c0a2e2cu; r[16]=0x0c0a3d60u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a3d60u) { target=s->pc; goto dispatch; }
goto P_0c0a3d60;
P_0c0a3d5e: /* original 0009, guest PC 0x0c0a3d5e */
if(!s->budget--) { s->failed_pc=0x0c0a3d5eu; return 0; }
goto P_0c0a3d60;
P_0c0a3d60: /* original 9446, guest PC 0x0c0a3d60 */
if(!s->budget--) { s->failed_pc=0x0c0a3d60u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a3df0u,2);
goto P_0c0a3d62;
P_0c0a3d62: /* original b863, guest PC 0x0c0a3d62 */
if(!s->budget--) { s->failed_pc=0x0c0a3d62u; return 0; }
target=0x0c0a2e2cu; r[16]=0x0c0a3d66u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a3d66u) { target=s->pc; goto dispatch; }
goto P_0c0a3d66;
P_0c0a3d64: /* original 0009, guest PC 0x0c0a3d64 */
if(!s->budget--) { s->failed_pc=0x0c0a3d64u; return 0; }
goto P_0c0a3d66;
P_0c0a3d66: /* original 9444, guest PC 0x0c0a3d66 */
if(!s->budget--) { s->failed_pc=0x0c0a3d66u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a3df2u,2);
goto P_0c0a3d68;
P_0c0a3d68: /* original b860, guest PC 0x0c0a3d68 */
if(!s->budget--) { s->failed_pc=0x0c0a3d68u; return 0; }
target=0x0c0a2e2cu; r[16]=0x0c0a3d6cu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a3d6cu) { target=s->pc; goto dispatch; }
goto P_0c0a3d6c;
P_0c0a3d6a: /* original 0009, guest PC 0x0c0a3d6a */
if(!s->budget--) { s->failed_pc=0x0c0a3d6au; return 0; }
goto P_0c0a3d6c;
P_0c0a3d6c: /* original 9442, guest PC 0x0c0a3d6c */
if(!s->budget--) { s->failed_pc=0x0c0a3d6cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a3df4u,2);
goto P_0c0a3d6e;
P_0c0a3d6e: /* original b85d, guest PC 0x0c0a3d6e */
if(!s->budget--) { s->failed_pc=0x0c0a3d6eu; return 0; }
target=0x0c0a2e2cu; r[16]=0x0c0a3d72u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a3d72u) { target=s->pc; goto dispatch; }
goto P_0c0a3d72;
P_0c0a3d70: /* original 0009, guest PC 0x0c0a3d70 */
if(!s->budget--) { s->failed_pc=0x0c0a3d70u; return 0; }
goto P_0c0a3d72;
P_0c0a3d72: /* original 9440, guest PC 0x0c0a3d72 */
if(!s->budget--) { s->failed_pc=0x0c0a3d72u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a3df6u,2);
goto P_0c0a3d74;
P_0c0a3d74: /* original b85a, guest PC 0x0c0a3d74 */
if(!s->budget--) { s->failed_pc=0x0c0a3d74u; return 0; }
target=0x0c0a2e2cu; r[16]=0x0c0a3d78u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a3d78u) { target=s->pc; goto dispatch; }
goto P_0c0a3d78;
P_0c0a3d76: /* original 0009, guest PC 0x0c0a3d76 */
if(!s->budget--) { s->failed_pc=0x0c0a3d76u; return 0; }
goto P_0c0a3d78;
P_0c0a3d78: /* original 943e, guest PC 0x0c0a3d78 */
if(!s->budget--) { s->failed_pc=0x0c0a3d78u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a3df8u,2);
goto P_0c0a3d7a;
P_0c0a3d7a: /* original b857, guest PC 0x0c0a3d7a */
if(!s->budget--) { s->failed_pc=0x0c0a3d7au; return 0; }
target=0x0c0a2e2cu; r[16]=0x0c0a3d7eu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a3d7eu) { target=s->pc; goto dispatch; }
goto P_0c0a3d7e;
P_0c0a3d7c: /* original 0009, guest PC 0x0c0a3d7c */
if(!s->budget--) { s->failed_pc=0x0c0a3d7cu; return 0; }
goto P_0c0a3d7e;
P_0c0a3d7e: /* original 943c, guest PC 0x0c0a3d7e */
if(!s->budget--) { s->failed_pc=0x0c0a3d7eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a3dfau,2);
goto P_0c0a3d80;
P_0c0a3d80: /* original b854, guest PC 0x0c0a3d80 */
if(!s->budget--) { s->failed_pc=0x0c0a3d80u; return 0; }
target=0x0c0a2e2cu; r[16]=0x0c0a3d84u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a3d84u) { target=s->pc; goto dispatch; }
goto P_0c0a3d84;
P_0c0a3d82: /* original 0009, guest PC 0x0c0a3d82 */
if(!s->budget--) { s->failed_pc=0x0c0a3d82u; return 0; }
goto P_0c0a3d84;
P_0c0a3d84: /* original 943a, guest PC 0x0c0a3d84 */
if(!s->budget--) { s->failed_pc=0x0c0a3d84u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a3dfcu,2);
goto P_0c0a3d86;
P_0c0a3d86: /* original b851, guest PC 0x0c0a3d86 */
if(!s->budget--) { s->failed_pc=0x0c0a3d86u; return 0; }
target=0x0c0a2e2cu; r[16]=0x0c0a3d8au;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a3d8au) { target=s->pc; goto dispatch; }
goto P_0c0a3d8a;
P_0c0a3d88: /* original 0009, guest PC 0x0c0a3d88 */
if(!s->budget--) { s->failed_pc=0x0c0a3d88u; return 0; }
goto P_0c0a3d8a;
P_0c0a3d8a: /* original 9438, guest PC 0x0c0a3d8a */
if(!s->budget--) { s->failed_pc=0x0c0a3d8au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a3dfeu,2);
goto P_0c0a3d8c;
P_0c0a3d8c: /* original b84e, guest PC 0x0c0a3d8c */
if(!s->budget--) { s->failed_pc=0x0c0a3d8cu; return 0; }
target=0x0c0a2e2cu; r[16]=0x0c0a3d90u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a3d90u) { target=s->pc; goto dispatch; }
goto P_0c0a3d90;
P_0c0a3d8e: /* original 0009, guest PC 0x0c0a3d8e */
if(!s->budget--) { s->failed_pc=0x0c0a3d8eu; return 0; }
goto P_0c0a3d90;
P_0c0a3d90: /* original 9436, guest PC 0x0c0a3d90 */
if(!s->budget--) { s->failed_pc=0x0c0a3d90u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a3e00u,2);
goto P_0c0a3d92;
P_0c0a3d92: /* original b84b, guest PC 0x0c0a3d92 */
if(!s->budget--) { s->failed_pc=0x0c0a3d92u; return 0; }
target=0x0c0a2e2cu; r[16]=0x0c0a3d96u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a3d96u) { target=s->pc; goto dispatch; }
goto P_0c0a3d96;
P_0c0a3d94: /* original 0009, guest PC 0x0c0a3d94 */
if(!s->budget--) { s->failed_pc=0x0c0a3d94u; return 0; }
goto P_0c0a3d96;
P_0c0a3d96: /* original 9434, guest PC 0x0c0a3d96 */
if(!s->budget--) { s->failed_pc=0x0c0a3d96u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a3e02u,2);
goto P_0c0a3d98;
P_0c0a3d98: /* original b848, guest PC 0x0c0a3d98 */
if(!s->budget--) { s->failed_pc=0x0c0a3d98u; return 0; }
target=0x0c0a2e2cu; r[16]=0x0c0a3d9cu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a3d9cu) { target=s->pc; goto dispatch; }
goto P_0c0a3d9c;
P_0c0a3d9a: /* original 0009, guest PC 0x0c0a3d9a */
if(!s->budget--) { s->failed_pc=0x0c0a3d9au; return 0; }
goto P_0c0a3d9c;
P_0c0a3d9c: /* original 9432, guest PC 0x0c0a3d9c */
if(!s->budget--) { s->failed_pc=0x0c0a3d9cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a3e04u,2);
goto P_0c0a3d9e;
P_0c0a3d9e: /* original b845, guest PC 0x0c0a3d9e */
if(!s->budget--) { s->failed_pc=0x0c0a3d9eu; return 0; }
target=0x0c0a2e2cu; r[16]=0x0c0a3da2u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a3da2u) { target=s->pc; goto dispatch; }
goto P_0c0a3da2;
P_0c0a3da0: /* original 0009, guest PC 0x0c0a3da0 */
if(!s->budget--) { s->failed_pc=0x0c0a3da0u; return 0; }
goto P_0c0a3da2;
P_0c0a3da2: /* original 9430, guest PC 0x0c0a3da2 */
if(!s->budget--) { s->failed_pc=0x0c0a3da2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a3e06u,2);
goto P_0c0a3da4;
P_0c0a3da4: /* original b842, guest PC 0x0c0a3da4 */
if(!s->budget--) { s->failed_pc=0x0c0a3da4u; return 0; }
target=0x0c0a2e2cu; r[16]=0x0c0a3da8u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a3da8u) { target=s->pc; goto dispatch; }
goto P_0c0a3da8;
P_0c0a3da6: /* original 0009, guest PC 0x0c0a3da6 */
if(!s->budget--) { s->failed_pc=0x0c0a3da6u; return 0; }
goto P_0c0a3da8;
P_0c0a3da8: /* original 942e, guest PC 0x0c0a3da8 */
if(!s->budget--) { s->failed_pc=0x0c0a3da8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a3e08u,2);
goto P_0c0a3daa;
P_0c0a3daa: /* original a02e, guest PC 0x0c0a3daa */
if(!s->budget--) { s->failed_pc=0x0c0a3daau; return 0; }
goto P_0c0a3e0a;
P_0c0a3dac: /* original 0009, guest PC 0x0c0a3dac */
if(!s->budget--) { s->failed_pc=0x0c0a3dacu; return 0; }
return vf3_matrix_family(0x0c0a3daeu,s,ram);
P_0c0a3e0a: /* original b80f, guest PC 0x0c0a3e0a */
if(!s->budget--) { s->failed_pc=0x0c0a3e0au; return 0; }
target=0x0c0a2e2cu; r[16]=0x0c0a3e0eu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a3e0eu) { target=s->pc; goto dispatch; }
goto P_0c0a3e0e;
P_0c0a3e0c: /* original 0009, guest PC 0x0c0a3e0c */
if(!s->budget--) { s->failed_pc=0x0c0a3e0cu; return 0; }
goto P_0c0a3e0e;
P_0c0a3e0e: /* original 9404, guest PC 0x0c0a3e0e */
if(!s->budget--) { s->failed_pc=0x0c0a3e0eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a3e1au,2);
goto P_0c0a3e10;
P_0c0a3e10: /* original b80c, guest PC 0x0c0a3e10 */
if(!s->budget--) { s->failed_pc=0x0c0a3e10u; return 0; }
target=0x0c0a2e2cu; r[16]=0x0c0a3e14u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a3e14u) { target=s->pc; goto dispatch; }
goto P_0c0a3e14;
P_0c0a3e12: /* original 0009, guest PC 0x0c0a3e12 */
if(!s->budget--) { s->failed_pc=0x0c0a3e12u; return 0; }
goto P_0c0a3e14;
P_0c0a3e14: /* original 9402, guest PC 0x0c0a3e14 */
if(!s->budget--) { s->failed_pc=0x0c0a3e14u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a3e1cu,2);
goto P_0c0a3e16;
P_0c0a3e16: /* original a809, guest PC 0x0c0a3e16 */
if(!s->budget--) { s->failed_pc=0x0c0a3e16u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a2e2c;
P_0c0a3e18: /* original 4f26, guest PC 0x0c0a3e18 */
if(!s->budget--) { s->failed_pc=0x0c0a3e18u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
return vf3_matrix_family(0x0c0a3e1au,s,ram);
P_0c0a4012: /* original 4f22, guest PC 0x0c0a4012 */
if(!s->budget--) { s->failed_pc=0x0c0a4012u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0a4014;
P_0c0a4014: /* original d35d, guest PC 0x0c0a4014 */
if(!s->budget--) { s->failed_pc=0x0c0a4014u; return 0; }
r[3]=read(ram,0x0c0a418cu,4);
goto P_0c0a4016;
P_0c0a4016: /* original 94a4, guest PC 0x0c0a4016 */
if(!s->budget--) { s->failed_pc=0x0c0a4016u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a4162u,2);
goto P_0c0a4018;
P_0c0a4018: /* original 430b, guest PC 0x0c0a4018 */
if(!s->budget--) { s->failed_pc=0x0c0a4018u; return 0; }
target=r[3];
r[16]=0x0c0a401cu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a401cu) { target=s->pc; goto dispatch; }
goto P_0c0a401c;
P_0c0a401a: /* original 0009, guest PC 0x0c0a401a */
if(!s->budget--) { s->failed_pc=0x0c0a401au; return 0; }
goto P_0c0a401c;
P_0c0a401c: /* original d25b, guest PC 0x0c0a401c */
if(!s->budget--) { s->failed_pc=0x0c0a401cu; return 0; }
r[2]=read(ram,0x0c0a418cu,4);
goto P_0c0a401e;
P_0c0a401e: /* original 94a1, guest PC 0x0c0a401e */
if(!s->budget--) { s->failed_pc=0x0c0a401eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a4164u,2);
goto P_0c0a4020;
P_0c0a4020: /* original 420b, guest PC 0x0c0a4020 */
if(!s->budget--) { s->failed_pc=0x0c0a4020u; return 0; }
target=r[2];
r[16]=0x0c0a4024u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a4024u) { target=s->pc; goto dispatch; }
goto P_0c0a4024;
P_0c0a4022: /* original 0009, guest PC 0x0c0a4022 */
if(!s->budget--) { s->failed_pc=0x0c0a4022u; return 0; }
goto P_0c0a4024;
P_0c0a4024: /* original d359, guest PC 0x0c0a4024 */
if(!s->budget--) { s->failed_pc=0x0c0a4024u; return 0; }
r[3]=read(ram,0x0c0a418cu,4);
goto P_0c0a4026;
P_0c0a4026: /* original 949e, guest PC 0x0c0a4026 */
if(!s->budget--) { s->failed_pc=0x0c0a4026u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a4166u,2);
goto P_0c0a4028;
P_0c0a4028: /* original 430b, guest PC 0x0c0a4028 */
if(!s->budget--) { s->failed_pc=0x0c0a4028u; return 0; }
target=r[3];
r[16]=0x0c0a402cu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a402cu) { target=s->pc; goto dispatch; }
goto P_0c0a402c;
P_0c0a402a: /* original 0009, guest PC 0x0c0a402a */
if(!s->budget--) { s->failed_pc=0x0c0a402au; return 0; }
goto P_0c0a402c;
P_0c0a402c: /* original d257, guest PC 0x0c0a402c */
if(!s->budget--) { s->failed_pc=0x0c0a402cu; return 0; }
r[2]=read(ram,0x0c0a418cu,4);
goto P_0c0a402e;
P_0c0a402e: /* original 949b, guest PC 0x0c0a402e */
if(!s->budget--) { s->failed_pc=0x0c0a402eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a4168u,2);
goto P_0c0a4030;
P_0c0a4030: /* original 420b, guest PC 0x0c0a4030 */
if(!s->budget--) { s->failed_pc=0x0c0a4030u; return 0; }
target=r[2];
r[16]=0x0c0a4034u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a4034u) { target=s->pc; goto dispatch; }
goto P_0c0a4034;
P_0c0a4032: /* original 0009, guest PC 0x0c0a4032 */
if(!s->budget--) { s->failed_pc=0x0c0a4032u; return 0; }
goto P_0c0a4034;
P_0c0a4034: /* original d355, guest PC 0x0c0a4034 */
if(!s->budget--) { s->failed_pc=0x0c0a4034u; return 0; }
r[3]=read(ram,0x0c0a418cu,4);
goto P_0c0a4036;
P_0c0a4036: /* original 9498, guest PC 0x0c0a4036 */
if(!s->budget--) { s->failed_pc=0x0c0a4036u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a416au,2);
goto P_0c0a4038;
P_0c0a4038: /* original 430b, guest PC 0x0c0a4038 */
if(!s->budget--) { s->failed_pc=0x0c0a4038u; return 0; }
target=r[3];
r[16]=0x0c0a403cu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a403cu) { target=s->pc; goto dispatch; }
goto P_0c0a403c;
P_0c0a403a: /* original 0009, guest PC 0x0c0a403a */
if(!s->budget--) { s->failed_pc=0x0c0a403au; return 0; }
goto P_0c0a403c;
P_0c0a403c: /* original d253, guest PC 0x0c0a403c */
if(!s->budget--) { s->failed_pc=0x0c0a403cu; return 0; }
r[2]=read(ram,0x0c0a418cu,4);
goto P_0c0a403e;
P_0c0a403e: /* original 9495, guest PC 0x0c0a403e */
if(!s->budget--) { s->failed_pc=0x0c0a403eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a416cu,2);
goto P_0c0a4040;
P_0c0a4040: /* original 420b, guest PC 0x0c0a4040 */
if(!s->budget--) { s->failed_pc=0x0c0a4040u; return 0; }
target=r[2];
r[16]=0x0c0a4044u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a4044u) { target=s->pc; goto dispatch; }
goto P_0c0a4044;
P_0c0a4042: /* original 0009, guest PC 0x0c0a4042 */
if(!s->budget--) { s->failed_pc=0x0c0a4042u; return 0; }
goto P_0c0a4044;
P_0c0a4044: /* original d351, guest PC 0x0c0a4044 */
if(!s->budget--) { s->failed_pc=0x0c0a4044u; return 0; }
r[3]=read(ram,0x0c0a418cu,4);
goto P_0c0a4046;
P_0c0a4046: /* original 9492, guest PC 0x0c0a4046 */
if(!s->budget--) { s->failed_pc=0x0c0a4046u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a416eu,2);
goto P_0c0a4048;
P_0c0a4048: /* original 430b, guest PC 0x0c0a4048 */
if(!s->budget--) { s->failed_pc=0x0c0a4048u; return 0; }
target=r[3];
r[16]=0x0c0a404cu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a404cu) { target=s->pc; goto dispatch; }
goto P_0c0a404c;
P_0c0a404a: /* original 0009, guest PC 0x0c0a404a */
if(!s->budget--) { s->failed_pc=0x0c0a404au; return 0; }
goto P_0c0a404c;
P_0c0a404c: /* original d24f, guest PC 0x0c0a404c */
if(!s->budget--) { s->failed_pc=0x0c0a404cu; return 0; }
r[2]=read(ram,0x0c0a418cu,4);
goto P_0c0a404e;
P_0c0a404e: /* original 948f, guest PC 0x0c0a404e */
if(!s->budget--) { s->failed_pc=0x0c0a404eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a4170u,2);
goto P_0c0a4050;
P_0c0a4050: /* original 420b, guest PC 0x0c0a4050 */
if(!s->budget--) { s->failed_pc=0x0c0a4050u; return 0; }
target=r[2];
r[16]=0x0c0a4054u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a4054u) { target=s->pc; goto dispatch; }
goto P_0c0a4054;
P_0c0a4052: /* original 0009, guest PC 0x0c0a4052 */
if(!s->budget--) { s->failed_pc=0x0c0a4052u; return 0; }
goto P_0c0a4054;
P_0c0a4054: /* original d34d, guest PC 0x0c0a4054 */
if(!s->budget--) { s->failed_pc=0x0c0a4054u; return 0; }
r[3]=read(ram,0x0c0a418cu,4);
goto P_0c0a4056;
P_0c0a4056: /* original 948c, guest PC 0x0c0a4056 */
if(!s->budget--) { s->failed_pc=0x0c0a4056u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a4172u,2);
goto P_0c0a4058;
P_0c0a4058: /* original 430b, guest PC 0x0c0a4058 */
if(!s->budget--) { s->failed_pc=0x0c0a4058u; return 0; }
target=r[3];
r[16]=0x0c0a405cu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a405cu) { target=s->pc; goto dispatch; }
goto P_0c0a405c;
P_0c0a405a: /* original 0009, guest PC 0x0c0a405a */
if(!s->budget--) { s->failed_pc=0x0c0a405au; return 0; }
goto P_0c0a405c;
P_0c0a405c: /* original d24b, guest PC 0x0c0a405c */
if(!s->budget--) { s->failed_pc=0x0c0a405cu; return 0; }
r[2]=read(ram,0x0c0a418cu,4);
goto P_0c0a405e;
P_0c0a405e: /* original 9489, guest PC 0x0c0a405e */
if(!s->budget--) { s->failed_pc=0x0c0a405eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a4174u,2);
goto P_0c0a4060;
P_0c0a4060: /* original 420b, guest PC 0x0c0a4060 */
if(!s->budget--) { s->failed_pc=0x0c0a4060u; return 0; }
target=r[2];
r[16]=0x0c0a4064u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a4064u) { target=s->pc; goto dispatch; }
goto P_0c0a4064;
P_0c0a4062: /* original 0009, guest PC 0x0c0a4062 */
if(!s->budget--) { s->failed_pc=0x0c0a4062u; return 0; }
goto P_0c0a4064;
P_0c0a4064: /* original d349, guest PC 0x0c0a4064 */
if(!s->budget--) { s->failed_pc=0x0c0a4064u; return 0; }
r[3]=read(ram,0x0c0a418cu,4);
goto P_0c0a4066;
P_0c0a4066: /* original 9486, guest PC 0x0c0a4066 */
if(!s->budget--) { s->failed_pc=0x0c0a4066u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a4176u,2);
goto P_0c0a4068;
P_0c0a4068: /* original 430b, guest PC 0x0c0a4068 */
if(!s->budget--) { s->failed_pc=0x0c0a4068u; return 0; }
target=r[3];
r[16]=0x0c0a406cu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a406cu) { target=s->pc; goto dispatch; }
goto P_0c0a406c;
P_0c0a406a: /* original 0009, guest PC 0x0c0a406a */
if(!s->budget--) { s->failed_pc=0x0c0a406au; return 0; }
goto P_0c0a406c;
P_0c0a406c: /* original d247, guest PC 0x0c0a406c */
if(!s->budget--) { s->failed_pc=0x0c0a406cu; return 0; }
r[2]=read(ram,0x0c0a418cu,4);
goto P_0c0a406e;
P_0c0a406e: /* original 9483, guest PC 0x0c0a406e */
if(!s->budget--) { s->failed_pc=0x0c0a406eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a4178u,2);
goto P_0c0a4070;
P_0c0a4070: /* original 420b, guest PC 0x0c0a4070 */
if(!s->budget--) { s->failed_pc=0x0c0a4070u; return 0; }
target=r[2];
r[16]=0x0c0a4074u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a4074u) { target=s->pc; goto dispatch; }
goto P_0c0a4074;
P_0c0a4072: /* original 0009, guest PC 0x0c0a4072 */
if(!s->budget--) { s->failed_pc=0x0c0a4072u; return 0; }
goto P_0c0a4074;
P_0c0a4074: /* original d345, guest PC 0x0c0a4074 */
if(!s->budget--) { s->failed_pc=0x0c0a4074u; return 0; }
r[3]=read(ram,0x0c0a418cu,4);
goto P_0c0a4076;
P_0c0a4076: /* original 9480, guest PC 0x0c0a4076 */
if(!s->budget--) { s->failed_pc=0x0c0a4076u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a417au,2);
goto P_0c0a4078;
P_0c0a4078: /* original 430b, guest PC 0x0c0a4078 */
if(!s->budget--) { s->failed_pc=0x0c0a4078u; return 0; }
target=r[3];
r[16]=0x0c0a407cu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a407cu) { target=s->pc; goto dispatch; }
goto P_0c0a407c;
P_0c0a407a: /* original 0009, guest PC 0x0c0a407a */
if(!s->budget--) { s->failed_pc=0x0c0a407au; return 0; }
goto P_0c0a407c;
P_0c0a407c: /* original d243, guest PC 0x0c0a407c */
if(!s->budget--) { s->failed_pc=0x0c0a407cu; return 0; }
r[2]=read(ram,0x0c0a418cu,4);
goto P_0c0a407e;
P_0c0a407e: /* original 947d, guest PC 0x0c0a407e */
if(!s->budget--) { s->failed_pc=0x0c0a407eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a417cu,2);
goto P_0c0a4080;
P_0c0a4080: /* original 420b, guest PC 0x0c0a4080 */
if(!s->budget--) { s->failed_pc=0x0c0a4080u; return 0; }
target=r[2];
r[16]=0x0c0a4084u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a4084u) { target=s->pc; goto dispatch; }
goto P_0c0a4084;
P_0c0a4082: /* original 0009, guest PC 0x0c0a4082 */
if(!s->budget--) { s->failed_pc=0x0c0a4082u; return 0; }
goto P_0c0a4084;
P_0c0a4084: /* original d341, guest PC 0x0c0a4084 */
if(!s->budget--) { s->failed_pc=0x0c0a4084u; return 0; }
r[3]=read(ram,0x0c0a418cu,4);
goto P_0c0a4086;
P_0c0a4086: /* original 947a, guest PC 0x0c0a4086 */
if(!s->budget--) { s->failed_pc=0x0c0a4086u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a417eu,2);
goto P_0c0a4088;
P_0c0a4088: /* original 430b, guest PC 0x0c0a4088 */
if(!s->budget--) { s->failed_pc=0x0c0a4088u; return 0; }
target=r[3];
r[16]=0x0c0a408cu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a408cu) { target=s->pc; goto dispatch; }
goto P_0c0a408c;
P_0c0a408a: /* original 0009, guest PC 0x0c0a408a */
if(!s->budget--) { s->failed_pc=0x0c0a408au; return 0; }
goto P_0c0a408c;
P_0c0a408c: /* original d23f, guest PC 0x0c0a408c */
if(!s->budget--) { s->failed_pc=0x0c0a408cu; return 0; }
r[2]=read(ram,0x0c0a418cu,4);
goto P_0c0a408e;
P_0c0a408e: /* original 9477, guest PC 0x0c0a408e */
if(!s->budget--) { s->failed_pc=0x0c0a408eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a4180u,2);
goto P_0c0a4090;
P_0c0a4090: /* original 420b, guest PC 0x0c0a4090 */
if(!s->budget--) { s->failed_pc=0x0c0a4090u; return 0; }
target=r[2];
r[16]=0x0c0a4094u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a4094u) { target=s->pc; goto dispatch; }
goto P_0c0a4094;
P_0c0a4092: /* original 0009, guest PC 0x0c0a4092 */
if(!s->budget--) { s->failed_pc=0x0c0a4092u; return 0; }
goto P_0c0a4094;
P_0c0a4094: /* original d33d, guest PC 0x0c0a4094 */
if(!s->budget--) { s->failed_pc=0x0c0a4094u; return 0; }
r[3]=read(ram,0x0c0a418cu,4);
goto P_0c0a4096;
P_0c0a4096: /* original 9474, guest PC 0x0c0a4096 */
if(!s->budget--) { s->failed_pc=0x0c0a4096u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a4182u,2);
goto P_0c0a4098;
P_0c0a4098: /* original 430b, guest PC 0x0c0a4098 */
if(!s->budget--) { s->failed_pc=0x0c0a4098u; return 0; }
target=r[3];
r[16]=0x0c0a409cu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a409cu) { target=s->pc; goto dispatch; }
goto P_0c0a409c;
P_0c0a409a: /* original 0009, guest PC 0x0c0a409a */
if(!s->budget--) { s->failed_pc=0x0c0a409au; return 0; }
goto P_0c0a409c;
P_0c0a409c: /* original d23b, guest PC 0x0c0a409c */
if(!s->budget--) { s->failed_pc=0x0c0a409cu; return 0; }
r[2]=read(ram,0x0c0a418cu,4);
goto P_0c0a409e;
P_0c0a409e: /* original 9471, guest PC 0x0c0a409e */
if(!s->budget--) { s->failed_pc=0x0c0a409eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a4184u,2);
goto P_0c0a40a0;
P_0c0a40a0: /* original 420b, guest PC 0x0c0a40a0 */
if(!s->budget--) { s->failed_pc=0x0c0a40a0u; return 0; }
target=r[2];
r[16]=0x0c0a40a4u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a40a4u) { target=s->pc; goto dispatch; }
goto P_0c0a40a4;
P_0c0a40a2: /* original 0009, guest PC 0x0c0a40a2 */
if(!s->budget--) { s->failed_pc=0x0c0a40a2u; return 0; }
goto P_0c0a40a4;
P_0c0a40a4: /* original d339, guest PC 0x0c0a40a4 */
if(!s->budget--) { s->failed_pc=0x0c0a40a4u; return 0; }
r[3]=read(ram,0x0c0a418cu,4);
goto P_0c0a40a6;
P_0c0a40a6: /* original 946e, guest PC 0x0c0a40a6 */
if(!s->budget--) { s->failed_pc=0x0c0a40a6u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a4186u,2);
goto P_0c0a40a8;
P_0c0a40a8: /* original 432b, guest PC 0x0c0a40a8 */
if(!s->budget--) { s->failed_pc=0x0c0a40a8u; return 0; }
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
P_0c0a40aa: /* original 4f26, guest PC 0x0c0a40aa */
if(!s->budget--) { s->failed_pc=0x0c0a40aau; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
return vf3_matrix_family(0x0c0a40acu,s,ram);
P_0c0a4190: /* original 4f22, guest PC 0x0c0a4190 */
if(!s->budget--) { s->failed_pc=0x0c0a4190u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0a4192;
P_0c0a4192: /* original d364, guest PC 0x0c0a4192 */
if(!s->budget--) { s->failed_pc=0x0c0a4192u; return 0; }
r[3]=read(ram,0x0c0a4324u,4);
goto P_0c0a4194;
P_0c0a4194: /* original 94b0, guest PC 0x0c0a4194 */
if(!s->budget--) { s->failed_pc=0x0c0a4194u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a42f8u,2);
goto P_0c0a4196;
P_0c0a4196: /* original 430b, guest PC 0x0c0a4196 */
if(!s->budget--) { s->failed_pc=0x0c0a4196u; return 0; }
target=r[3];
r[16]=0x0c0a419au;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a419au) { target=s->pc; goto dispatch; }
goto P_0c0a419a;
P_0c0a4198: /* original 0009, guest PC 0x0c0a4198 */
if(!s->budget--) { s->failed_pc=0x0c0a4198u; return 0; }
goto P_0c0a419a;
P_0c0a419a: /* original d262, guest PC 0x0c0a419a */
if(!s->budget--) { s->failed_pc=0x0c0a419au; return 0; }
r[2]=read(ram,0x0c0a4324u,4);
goto P_0c0a419c;
P_0c0a419c: /* original 94ad, guest PC 0x0c0a419c */
if(!s->budget--) { s->failed_pc=0x0c0a419cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a42fau,2);
goto P_0c0a419e;
P_0c0a419e: /* original 420b, guest PC 0x0c0a419e */
if(!s->budget--) { s->failed_pc=0x0c0a419eu; return 0; }
target=r[2];
r[16]=0x0c0a41a2u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a41a2u) { target=s->pc; goto dispatch; }
goto P_0c0a41a2;
P_0c0a41a0: /* original 0009, guest PC 0x0c0a41a0 */
if(!s->budget--) { s->failed_pc=0x0c0a41a0u; return 0; }
goto P_0c0a41a2;
P_0c0a41a2: /* original d360, guest PC 0x0c0a41a2 */
if(!s->budget--) { s->failed_pc=0x0c0a41a2u; return 0; }
r[3]=read(ram,0x0c0a4324u,4);
goto P_0c0a41a4;
P_0c0a41a4: /* original 94aa, guest PC 0x0c0a41a4 */
if(!s->budget--) { s->failed_pc=0x0c0a41a4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a42fcu,2);
goto P_0c0a41a6;
P_0c0a41a6: /* original 430b, guest PC 0x0c0a41a6 */
if(!s->budget--) { s->failed_pc=0x0c0a41a6u; return 0; }
target=r[3];
r[16]=0x0c0a41aau;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a41aau) { target=s->pc; goto dispatch; }
goto P_0c0a41aa;
P_0c0a41a8: /* original 0009, guest PC 0x0c0a41a8 */
if(!s->budget--) { s->failed_pc=0x0c0a41a8u; return 0; }
goto P_0c0a41aa;
P_0c0a41aa: /* original d25e, guest PC 0x0c0a41aa */
if(!s->budget--) { s->failed_pc=0x0c0a41aau; return 0; }
r[2]=read(ram,0x0c0a4324u,4);
goto P_0c0a41ac;
P_0c0a41ac: /* original 94a7, guest PC 0x0c0a41ac */
if(!s->budget--) { s->failed_pc=0x0c0a41acu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a42feu,2);
goto P_0c0a41ae;
P_0c0a41ae: /* original 420b, guest PC 0x0c0a41ae */
if(!s->budget--) { s->failed_pc=0x0c0a41aeu; return 0; }
target=r[2];
r[16]=0x0c0a41b2u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a41b2u) { target=s->pc; goto dispatch; }
goto P_0c0a41b2;
P_0c0a41b0: /* original 0009, guest PC 0x0c0a41b0 */
if(!s->budget--) { s->failed_pc=0x0c0a41b0u; return 0; }
goto P_0c0a41b2;
P_0c0a41b2: /* original d35c, guest PC 0x0c0a41b2 */
if(!s->budget--) { s->failed_pc=0x0c0a41b2u; return 0; }
r[3]=read(ram,0x0c0a4324u,4);
goto P_0c0a41b4;
P_0c0a41b4: /* original 94a4, guest PC 0x0c0a41b4 */
if(!s->budget--) { s->failed_pc=0x0c0a41b4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a4300u,2);
goto P_0c0a41b6;
P_0c0a41b6: /* original 430b, guest PC 0x0c0a41b6 */
if(!s->budget--) { s->failed_pc=0x0c0a41b6u; return 0; }
target=r[3];
r[16]=0x0c0a41bau;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a41bau) { target=s->pc; goto dispatch; }
goto P_0c0a41ba;
P_0c0a41b8: /* original 0009, guest PC 0x0c0a41b8 */
if(!s->budget--) { s->failed_pc=0x0c0a41b8u; return 0; }
goto P_0c0a41ba;
P_0c0a41ba: /* original d25a, guest PC 0x0c0a41ba */
if(!s->budget--) { s->failed_pc=0x0c0a41bau; return 0; }
r[2]=read(ram,0x0c0a4324u,4);
goto P_0c0a41bc;
P_0c0a41bc: /* original 94a1, guest PC 0x0c0a41bc */
if(!s->budget--) { s->failed_pc=0x0c0a41bcu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a4302u,2);
goto P_0c0a41be;
P_0c0a41be: /* original 420b, guest PC 0x0c0a41be */
if(!s->budget--) { s->failed_pc=0x0c0a41beu; return 0; }
target=r[2];
r[16]=0x0c0a41c2u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a41c2u) { target=s->pc; goto dispatch; }
goto P_0c0a41c2;
P_0c0a41c0: /* original 0009, guest PC 0x0c0a41c0 */
if(!s->budget--) { s->failed_pc=0x0c0a41c0u; return 0; }
goto P_0c0a41c2;
P_0c0a41c2: /* original d358, guest PC 0x0c0a41c2 */
if(!s->budget--) { s->failed_pc=0x0c0a41c2u; return 0; }
r[3]=read(ram,0x0c0a4324u,4);
goto P_0c0a41c4;
P_0c0a41c4: /* original 949e, guest PC 0x0c0a41c4 */
if(!s->budget--) { s->failed_pc=0x0c0a41c4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a4304u,2);
goto P_0c0a41c6;
P_0c0a41c6: /* original 430b, guest PC 0x0c0a41c6 */
if(!s->budget--) { s->failed_pc=0x0c0a41c6u; return 0; }
target=r[3];
r[16]=0x0c0a41cau;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a41cau) { target=s->pc; goto dispatch; }
goto P_0c0a41ca;
P_0c0a41c8: /* original 0009, guest PC 0x0c0a41c8 */
if(!s->budget--) { s->failed_pc=0x0c0a41c8u; return 0; }
goto P_0c0a41ca;
P_0c0a41ca: /* original d256, guest PC 0x0c0a41ca */
if(!s->budget--) { s->failed_pc=0x0c0a41cau; return 0; }
r[2]=read(ram,0x0c0a4324u,4);
goto P_0c0a41cc;
P_0c0a41cc: /* original 949b, guest PC 0x0c0a41cc */
if(!s->budget--) { s->failed_pc=0x0c0a41ccu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a4306u,2);
goto P_0c0a41ce;
P_0c0a41ce: /* original 420b, guest PC 0x0c0a41ce */
if(!s->budget--) { s->failed_pc=0x0c0a41ceu; return 0; }
target=r[2];
r[16]=0x0c0a41d2u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a41d2u) { target=s->pc; goto dispatch; }
goto P_0c0a41d2;
P_0c0a41d0: /* original 0009, guest PC 0x0c0a41d0 */
if(!s->budget--) { s->failed_pc=0x0c0a41d0u; return 0; }
goto P_0c0a41d2;
P_0c0a41d2: /* original d354, guest PC 0x0c0a41d2 */
if(!s->budget--) { s->failed_pc=0x0c0a41d2u; return 0; }
r[3]=read(ram,0x0c0a4324u,4);
goto P_0c0a41d4;
P_0c0a41d4: /* original 9498, guest PC 0x0c0a41d4 */
if(!s->budget--) { s->failed_pc=0x0c0a41d4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a4308u,2);
goto P_0c0a41d6;
P_0c0a41d6: /* original 430b, guest PC 0x0c0a41d6 */
if(!s->budget--) { s->failed_pc=0x0c0a41d6u; return 0; }
target=r[3];
r[16]=0x0c0a41dau;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a41dau) { target=s->pc; goto dispatch; }
goto P_0c0a41da;
P_0c0a41d8: /* original 0009, guest PC 0x0c0a41d8 */
if(!s->budget--) { s->failed_pc=0x0c0a41d8u; return 0; }
goto P_0c0a41da;
P_0c0a41da: /* original d252, guest PC 0x0c0a41da */
if(!s->budget--) { s->failed_pc=0x0c0a41dau; return 0; }
r[2]=read(ram,0x0c0a4324u,4);
goto P_0c0a41dc;
P_0c0a41dc: /* original 9495, guest PC 0x0c0a41dc */
if(!s->budget--) { s->failed_pc=0x0c0a41dcu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a430au,2);
goto P_0c0a41de;
P_0c0a41de: /* original 420b, guest PC 0x0c0a41de */
if(!s->budget--) { s->failed_pc=0x0c0a41deu; return 0; }
target=r[2];
r[16]=0x0c0a41e2u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a41e2u) { target=s->pc; goto dispatch; }
goto P_0c0a41e2;
P_0c0a41e0: /* original 0009, guest PC 0x0c0a41e0 */
if(!s->budget--) { s->failed_pc=0x0c0a41e0u; return 0; }
goto P_0c0a41e2;
P_0c0a41e2: /* original d350, guest PC 0x0c0a41e2 */
if(!s->budget--) { s->failed_pc=0x0c0a41e2u; return 0; }
r[3]=read(ram,0x0c0a4324u,4);
goto P_0c0a41e4;
P_0c0a41e4: /* original 9492, guest PC 0x0c0a41e4 */
if(!s->budget--) { s->failed_pc=0x0c0a41e4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a430cu,2);
goto P_0c0a41e6;
P_0c0a41e6: /* original 430b, guest PC 0x0c0a41e6 */
if(!s->budget--) { s->failed_pc=0x0c0a41e6u; return 0; }
target=r[3];
r[16]=0x0c0a41eau;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a41eau) { target=s->pc; goto dispatch; }
goto P_0c0a41ea;
P_0c0a41e8: /* original 0009, guest PC 0x0c0a41e8 */
if(!s->budget--) { s->failed_pc=0x0c0a41e8u; return 0; }
goto P_0c0a41ea;
P_0c0a41ea: /* original d24e, guest PC 0x0c0a41ea */
if(!s->budget--) { s->failed_pc=0x0c0a41eau; return 0; }
r[2]=read(ram,0x0c0a4324u,4);
goto P_0c0a41ec;
P_0c0a41ec: /* original 948f, guest PC 0x0c0a41ec */
if(!s->budget--) { s->failed_pc=0x0c0a41ecu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a430eu,2);
goto P_0c0a41ee;
P_0c0a41ee: /* original 420b, guest PC 0x0c0a41ee */
if(!s->budget--) { s->failed_pc=0x0c0a41eeu; return 0; }
target=r[2];
r[16]=0x0c0a41f2u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a41f2u) { target=s->pc; goto dispatch; }
goto P_0c0a41f2;
P_0c0a41f0: /* original 0009, guest PC 0x0c0a41f0 */
if(!s->budget--) { s->failed_pc=0x0c0a41f0u; return 0; }
goto P_0c0a41f2;
P_0c0a41f2: /* original d34c, guest PC 0x0c0a41f2 */
if(!s->budget--) { s->failed_pc=0x0c0a41f2u; return 0; }
r[3]=read(ram,0x0c0a4324u,4);
goto P_0c0a41f4;
P_0c0a41f4: /* original 948c, guest PC 0x0c0a41f4 */
if(!s->budget--) { s->failed_pc=0x0c0a41f4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a4310u,2);
goto P_0c0a41f6;
P_0c0a41f6: /* original 430b, guest PC 0x0c0a41f6 */
if(!s->budget--) { s->failed_pc=0x0c0a41f6u; return 0; }
target=r[3];
r[16]=0x0c0a41fau;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a41fau) { target=s->pc; goto dispatch; }
goto P_0c0a41fa;
P_0c0a41f8: /* original 0009, guest PC 0x0c0a41f8 */
if(!s->budget--) { s->failed_pc=0x0c0a41f8u; return 0; }
goto P_0c0a41fa;
P_0c0a41fa: /* original d24a, guest PC 0x0c0a41fa */
if(!s->budget--) { s->failed_pc=0x0c0a41fau; return 0; }
r[2]=read(ram,0x0c0a4324u,4);
goto P_0c0a41fc;
P_0c0a41fc: /* original 9489, guest PC 0x0c0a41fc */
if(!s->budget--) { s->failed_pc=0x0c0a41fcu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a4312u,2);
goto P_0c0a41fe;
P_0c0a41fe: /* original 420b, guest PC 0x0c0a41fe */
if(!s->budget--) { s->failed_pc=0x0c0a41feu; return 0; }
target=r[2];
r[16]=0x0c0a4202u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a4202u) { target=s->pc; goto dispatch; }
goto P_0c0a4202;
P_0c0a4200: /* original 0009, guest PC 0x0c0a4200 */
if(!s->budget--) { s->failed_pc=0x0c0a4200u; return 0; }
goto P_0c0a4202;
P_0c0a4202: /* original d348, guest PC 0x0c0a4202 */
if(!s->budget--) { s->failed_pc=0x0c0a4202u; return 0; }
r[3]=read(ram,0x0c0a4324u,4);
goto P_0c0a4204;
P_0c0a4204: /* original 9486, guest PC 0x0c0a4204 */
if(!s->budget--) { s->failed_pc=0x0c0a4204u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a4314u,2);
goto P_0c0a4206;
P_0c0a4206: /* original 430b, guest PC 0x0c0a4206 */
if(!s->budget--) { s->failed_pc=0x0c0a4206u; return 0; }
target=r[3];
r[16]=0x0c0a420au;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a420au) { target=s->pc; goto dispatch; }
goto P_0c0a420a;
P_0c0a4208: /* original 0009, guest PC 0x0c0a4208 */
if(!s->budget--) { s->failed_pc=0x0c0a4208u; return 0; }
goto P_0c0a420a;
P_0c0a420a: /* original d246, guest PC 0x0c0a420a */
if(!s->budget--) { s->failed_pc=0x0c0a420au; return 0; }
r[2]=read(ram,0x0c0a4324u,4);
goto P_0c0a420c;
P_0c0a420c: /* original 9483, guest PC 0x0c0a420c */
if(!s->budget--) { s->failed_pc=0x0c0a420cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a4316u,2);
goto P_0c0a420e;
P_0c0a420e: /* original 420b, guest PC 0x0c0a420e */
if(!s->budget--) { s->failed_pc=0x0c0a420eu; return 0; }
target=r[2];
r[16]=0x0c0a4212u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a4212u) { target=s->pc; goto dispatch; }
goto P_0c0a4212;
P_0c0a4210: /* original 0009, guest PC 0x0c0a4210 */
if(!s->budget--) { s->failed_pc=0x0c0a4210u; return 0; }
goto P_0c0a4212;
P_0c0a4212: /* original d344, guest PC 0x0c0a4212 */
if(!s->budget--) { s->failed_pc=0x0c0a4212u; return 0; }
r[3]=read(ram,0x0c0a4324u,4);
goto P_0c0a4214;
P_0c0a4214: /* original 9480, guest PC 0x0c0a4214 */
if(!s->budget--) { s->failed_pc=0x0c0a4214u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a4318u,2);
goto P_0c0a4216;
P_0c0a4216: /* original 430b, guest PC 0x0c0a4216 */
if(!s->budget--) { s->failed_pc=0x0c0a4216u; return 0; }
target=r[3];
r[16]=0x0c0a421au;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a421au) { target=s->pc; goto dispatch; }
goto P_0c0a421a;
P_0c0a4218: /* original 0009, guest PC 0x0c0a4218 */
if(!s->budget--) { s->failed_pc=0x0c0a4218u; return 0; }
goto P_0c0a421a;
P_0c0a421a: /* original d242, guest PC 0x0c0a421a */
if(!s->budget--) { s->failed_pc=0x0c0a421au; return 0; }
r[2]=read(ram,0x0c0a4324u,4);
goto P_0c0a421c;
P_0c0a421c: /* original 947d, guest PC 0x0c0a421c */
if(!s->budget--) { s->failed_pc=0x0c0a421cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a431au,2);
goto P_0c0a421e;
P_0c0a421e: /* original 420b, guest PC 0x0c0a421e */
if(!s->budget--) { s->failed_pc=0x0c0a421eu; return 0; }
target=r[2];
r[16]=0x0c0a4222u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a4222u) { target=s->pc; goto dispatch; }
goto P_0c0a4222;
P_0c0a4220: /* original 0009, guest PC 0x0c0a4220 */
if(!s->budget--) { s->failed_pc=0x0c0a4220u; return 0; }
goto P_0c0a4222;
P_0c0a4222: /* original d340, guest PC 0x0c0a4222 */
if(!s->budget--) { s->failed_pc=0x0c0a4222u; return 0; }
r[3]=read(ram,0x0c0a4324u,4);
goto P_0c0a4224;
P_0c0a4224: /* original 947a, guest PC 0x0c0a4224 */
if(!s->budget--) { s->failed_pc=0x0c0a4224u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a431cu,2);
goto P_0c0a4226;
P_0c0a4226: /* original 430b, guest PC 0x0c0a4226 */
if(!s->budget--) { s->failed_pc=0x0c0a4226u; return 0; }
target=r[3];
r[16]=0x0c0a422au;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a422au) { target=s->pc; goto dispatch; }
goto P_0c0a422a;
P_0c0a4228: /* original 0009, guest PC 0x0c0a4228 */
if(!s->budget--) { s->failed_pc=0x0c0a4228u; return 0; }
goto P_0c0a422a;
P_0c0a422a: /* original d23e, guest PC 0x0c0a422a */
if(!s->budget--) { s->failed_pc=0x0c0a422au; return 0; }
r[2]=read(ram,0x0c0a4324u,4);
goto P_0c0a422c;
P_0c0a422c: /* original 9477, guest PC 0x0c0a422c */
if(!s->budget--) { s->failed_pc=0x0c0a422cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a431eu,2);
goto P_0c0a422e;
P_0c0a422e: /* original 420b, guest PC 0x0c0a422e */
if(!s->budget--) { s->failed_pc=0x0c0a422eu; return 0; }
target=r[2];
r[16]=0x0c0a4232u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a4232u) { target=s->pc; goto dispatch; }
goto P_0c0a4232;
P_0c0a4230: /* original 0009, guest PC 0x0c0a4230 */
if(!s->budget--) { s->failed_pc=0x0c0a4230u; return 0; }
goto P_0c0a4232;
P_0c0a4232: /* original d33c, guest PC 0x0c0a4232 */
if(!s->budget--) { s->failed_pc=0x0c0a4232u; return 0; }
r[3]=read(ram,0x0c0a4324u,4);
goto P_0c0a4234;
P_0c0a4234: /* original 9474, guest PC 0x0c0a4234 */
if(!s->budget--) { s->failed_pc=0x0c0a4234u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a4320u,2);
goto P_0c0a4236;
P_0c0a4236: /* original 432b, guest PC 0x0c0a4236 */
if(!s->budget--) { s->failed_pc=0x0c0a4236u; return 0; }
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
P_0c0a4238: /* original 4f26, guest PC 0x0c0a4238 */
if(!s->budget--) { s->failed_pc=0x0c0a4238u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
return vf3_matrix_family(0x0c0a423au,s,ram);
P_0c0a432c: /* original 4f22, guest PC 0x0c0a432c */
if(!s->budget--) { s->failed_pc=0x0c0a432cu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0a432e;
P_0c0a432e: /* original d337, guest PC 0x0c0a432e */
if(!s->budget--) { s->failed_pc=0x0c0a432eu; return 0; }
r[3]=read(ram,0x0c0a440cu,4);
goto P_0c0a4330;
P_0c0a4330: /* original 9455, guest PC 0x0c0a4330 */
if(!s->budget--) { s->failed_pc=0x0c0a4330u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a43deu,2);
goto P_0c0a4332;
P_0c0a4332: /* original 430b, guest PC 0x0c0a4332 */
if(!s->budget--) { s->failed_pc=0x0c0a4332u; return 0; }
target=r[3];
r[16]=0x0c0a4336u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a4336u) { target=s->pc; goto dispatch; }
goto P_0c0a4336;
P_0c0a4334: /* original 0009, guest PC 0x0c0a4334 */
if(!s->budget--) { s->failed_pc=0x0c0a4334u; return 0; }
goto P_0c0a4336;
P_0c0a4336: /* original d235, guest PC 0x0c0a4336 */
if(!s->budget--) { s->failed_pc=0x0c0a4336u; return 0; }
r[2]=read(ram,0x0c0a440cu,4);
goto P_0c0a4338;
P_0c0a4338: /* original 9452, guest PC 0x0c0a4338 */
if(!s->budget--) { s->failed_pc=0x0c0a4338u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a43e0u,2);
goto P_0c0a433a;
P_0c0a433a: /* original 420b, guest PC 0x0c0a433a */
if(!s->budget--) { s->failed_pc=0x0c0a433au; return 0; }
target=r[2];
r[16]=0x0c0a433eu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a433eu) { target=s->pc; goto dispatch; }
goto P_0c0a433e;
P_0c0a433c: /* original 0009, guest PC 0x0c0a433c */
if(!s->budget--) { s->failed_pc=0x0c0a433cu; return 0; }
goto P_0c0a433e;
P_0c0a433e: /* original d333, guest PC 0x0c0a433e */
if(!s->budget--) { s->failed_pc=0x0c0a433eu; return 0; }
r[3]=read(ram,0x0c0a440cu,4);
goto P_0c0a4340;
P_0c0a4340: /* original 944f, guest PC 0x0c0a4340 */
if(!s->budget--) { s->failed_pc=0x0c0a4340u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a43e2u,2);
goto P_0c0a4342;
P_0c0a4342: /* original 430b, guest PC 0x0c0a4342 */
if(!s->budget--) { s->failed_pc=0x0c0a4342u; return 0; }
target=r[3];
r[16]=0x0c0a4346u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a4346u) { target=s->pc; goto dispatch; }
goto P_0c0a4346;
P_0c0a4344: /* original 0009, guest PC 0x0c0a4344 */
if(!s->budget--) { s->failed_pc=0x0c0a4344u; return 0; }
goto P_0c0a4346;
P_0c0a4346: /* original d231, guest PC 0x0c0a4346 */
if(!s->budget--) { s->failed_pc=0x0c0a4346u; return 0; }
r[2]=read(ram,0x0c0a440cu,4);
goto P_0c0a4348;
P_0c0a4348: /* original 944c, guest PC 0x0c0a4348 */
if(!s->budget--) { s->failed_pc=0x0c0a4348u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a43e4u,2);
goto P_0c0a434a;
P_0c0a434a: /* original 420b, guest PC 0x0c0a434a */
if(!s->budget--) { s->failed_pc=0x0c0a434au; return 0; }
target=r[2];
r[16]=0x0c0a434eu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a434eu) { target=s->pc; goto dispatch; }
goto P_0c0a434e;
P_0c0a434c: /* original 0009, guest PC 0x0c0a434c */
if(!s->budget--) { s->failed_pc=0x0c0a434cu; return 0; }
goto P_0c0a434e;
P_0c0a434e: /* original d32f, guest PC 0x0c0a434e */
if(!s->budget--) { s->failed_pc=0x0c0a434eu; return 0; }
r[3]=read(ram,0x0c0a440cu,4);
goto P_0c0a4350;
P_0c0a4350: /* original 9449, guest PC 0x0c0a4350 */
if(!s->budget--) { s->failed_pc=0x0c0a4350u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a43e6u,2);
goto P_0c0a4352;
P_0c0a4352: /* original 430b, guest PC 0x0c0a4352 */
if(!s->budget--) { s->failed_pc=0x0c0a4352u; return 0; }
target=r[3];
r[16]=0x0c0a4356u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a4356u) { target=s->pc; goto dispatch; }
goto P_0c0a4356;
P_0c0a4354: /* original 0009, guest PC 0x0c0a4354 */
if(!s->budget--) { s->failed_pc=0x0c0a4354u; return 0; }
goto P_0c0a4356;
P_0c0a4356: /* original d22d, guest PC 0x0c0a4356 */
if(!s->budget--) { s->failed_pc=0x0c0a4356u; return 0; }
r[2]=read(ram,0x0c0a440cu,4);
goto P_0c0a4358;
P_0c0a4358: /* original 9446, guest PC 0x0c0a4358 */
if(!s->budget--) { s->failed_pc=0x0c0a4358u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a43e8u,2);
goto P_0c0a435a;
P_0c0a435a: /* original 420b, guest PC 0x0c0a435a */
if(!s->budget--) { s->failed_pc=0x0c0a435au; return 0; }
target=r[2];
r[16]=0x0c0a435eu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a435eu) { target=s->pc; goto dispatch; }
goto P_0c0a435e;
P_0c0a435c: /* original 0009, guest PC 0x0c0a435c */
if(!s->budget--) { s->failed_pc=0x0c0a435cu; return 0; }
goto P_0c0a435e;
P_0c0a435e: /* original d32b, guest PC 0x0c0a435e */
if(!s->budget--) { s->failed_pc=0x0c0a435eu; return 0; }
r[3]=read(ram,0x0c0a440cu,4);
goto P_0c0a4360;
P_0c0a4360: /* original 9443, guest PC 0x0c0a4360 */
if(!s->budget--) { s->failed_pc=0x0c0a4360u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a43eau,2);
goto P_0c0a4362;
P_0c0a4362: /* original 430b, guest PC 0x0c0a4362 */
if(!s->budget--) { s->failed_pc=0x0c0a4362u; return 0; }
target=r[3];
r[16]=0x0c0a4366u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a4366u) { target=s->pc; goto dispatch; }
goto P_0c0a4366;
P_0c0a4364: /* original 0009, guest PC 0x0c0a4364 */
if(!s->budget--) { s->failed_pc=0x0c0a4364u; return 0; }
goto P_0c0a4366;
P_0c0a4366: /* original d229, guest PC 0x0c0a4366 */
if(!s->budget--) { s->failed_pc=0x0c0a4366u; return 0; }
r[2]=read(ram,0x0c0a440cu,4);
goto P_0c0a4368;
P_0c0a4368: /* original 9440, guest PC 0x0c0a4368 */
if(!s->budget--) { s->failed_pc=0x0c0a4368u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a43ecu,2);
goto P_0c0a436a;
P_0c0a436a: /* original 420b, guest PC 0x0c0a436a */
if(!s->budget--) { s->failed_pc=0x0c0a436au; return 0; }
target=r[2];
r[16]=0x0c0a436eu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a436eu) { target=s->pc; goto dispatch; }
goto P_0c0a436e;
P_0c0a436c: /* original 0009, guest PC 0x0c0a436c */
if(!s->budget--) { s->failed_pc=0x0c0a436cu; return 0; }
goto P_0c0a436e;
P_0c0a436e: /* original d327, guest PC 0x0c0a436e */
if(!s->budget--) { s->failed_pc=0x0c0a436eu; return 0; }
r[3]=read(ram,0x0c0a440cu,4);
goto P_0c0a4370;
P_0c0a4370: /* original 943d, guest PC 0x0c0a4370 */
if(!s->budget--) { s->failed_pc=0x0c0a4370u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a43eeu,2);
goto P_0c0a4372;
P_0c0a4372: /* original 430b, guest PC 0x0c0a4372 */
if(!s->budget--) { s->failed_pc=0x0c0a4372u; return 0; }
target=r[3];
r[16]=0x0c0a4376u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a4376u) { target=s->pc; goto dispatch; }
goto P_0c0a4376;
P_0c0a4374: /* original 0009, guest PC 0x0c0a4374 */
if(!s->budget--) { s->failed_pc=0x0c0a4374u; return 0; }
goto P_0c0a4376;
P_0c0a4376: /* original d225, guest PC 0x0c0a4376 */
if(!s->budget--) { s->failed_pc=0x0c0a4376u; return 0; }
r[2]=read(ram,0x0c0a440cu,4);
goto P_0c0a4378;
P_0c0a4378: /* original 943a, guest PC 0x0c0a4378 */
if(!s->budget--) { s->failed_pc=0x0c0a4378u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a43f0u,2);
goto P_0c0a437a;
P_0c0a437a: /* original 420b, guest PC 0x0c0a437a */
if(!s->budget--) { s->failed_pc=0x0c0a437au; return 0; }
target=r[2];
r[16]=0x0c0a437eu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a437eu) { target=s->pc; goto dispatch; }
goto P_0c0a437e;
P_0c0a437c: /* original 0009, guest PC 0x0c0a437c */
if(!s->budget--) { s->failed_pc=0x0c0a437cu; return 0; }
goto P_0c0a437e;
P_0c0a437e: /* original d323, guest PC 0x0c0a437e */
if(!s->budget--) { s->failed_pc=0x0c0a437eu; return 0; }
r[3]=read(ram,0x0c0a440cu,4);
goto P_0c0a4380;
P_0c0a4380: /* original 9437, guest PC 0x0c0a4380 */
if(!s->budget--) { s->failed_pc=0x0c0a4380u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a43f2u,2);
goto P_0c0a4382;
P_0c0a4382: /* original 430b, guest PC 0x0c0a4382 */
if(!s->budget--) { s->failed_pc=0x0c0a4382u; return 0; }
target=r[3];
r[16]=0x0c0a4386u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a4386u) { target=s->pc; goto dispatch; }
goto P_0c0a4386;
P_0c0a4384: /* original 0009, guest PC 0x0c0a4384 */
if(!s->budget--) { s->failed_pc=0x0c0a4384u; return 0; }
goto P_0c0a4386;
P_0c0a4386: /* original d221, guest PC 0x0c0a4386 */
if(!s->budget--) { s->failed_pc=0x0c0a4386u; return 0; }
r[2]=read(ram,0x0c0a440cu,4);
goto P_0c0a4388;
P_0c0a4388: /* original 9434, guest PC 0x0c0a4388 */
if(!s->budget--) { s->failed_pc=0x0c0a4388u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a43f4u,2);
goto P_0c0a438a;
P_0c0a438a: /* original 420b, guest PC 0x0c0a438a */
if(!s->budget--) { s->failed_pc=0x0c0a438au; return 0; }
target=r[2];
r[16]=0x0c0a438eu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a438eu) { target=s->pc; goto dispatch; }
goto P_0c0a438e;
P_0c0a438c: /* original 0009, guest PC 0x0c0a438c */
if(!s->budget--) { s->failed_pc=0x0c0a438cu; return 0; }
goto P_0c0a438e;
P_0c0a438e: /* original d31f, guest PC 0x0c0a438e */
if(!s->budget--) { s->failed_pc=0x0c0a438eu; return 0; }
r[3]=read(ram,0x0c0a440cu,4);
goto P_0c0a4390;
P_0c0a4390: /* original 9431, guest PC 0x0c0a4390 */
if(!s->budget--) { s->failed_pc=0x0c0a4390u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a43f6u,2);
goto P_0c0a4392;
P_0c0a4392: /* original 430b, guest PC 0x0c0a4392 */
if(!s->budget--) { s->failed_pc=0x0c0a4392u; return 0; }
target=r[3];
r[16]=0x0c0a4396u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a4396u) { target=s->pc; goto dispatch; }
goto P_0c0a4396;
P_0c0a4394: /* original 0009, guest PC 0x0c0a4394 */
if(!s->budget--) { s->failed_pc=0x0c0a4394u; return 0; }
goto P_0c0a4396;
P_0c0a4396: /* original d21d, guest PC 0x0c0a4396 */
if(!s->budget--) { s->failed_pc=0x0c0a4396u; return 0; }
r[2]=read(ram,0x0c0a440cu,4);
goto P_0c0a4398;
P_0c0a4398: /* original 942e, guest PC 0x0c0a4398 */
if(!s->budget--) { s->failed_pc=0x0c0a4398u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a43f8u,2);
goto P_0c0a439a;
P_0c0a439a: /* original 420b, guest PC 0x0c0a439a */
if(!s->budget--) { s->failed_pc=0x0c0a439au; return 0; }
target=r[2];
r[16]=0x0c0a439eu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a439eu) { target=s->pc; goto dispatch; }
goto P_0c0a439e;
P_0c0a439c: /* original 0009, guest PC 0x0c0a439c */
if(!s->budget--) { s->failed_pc=0x0c0a439cu; return 0; }
goto P_0c0a439e;
P_0c0a439e: /* original d31b, guest PC 0x0c0a439e */
if(!s->budget--) { s->failed_pc=0x0c0a439eu; return 0; }
r[3]=read(ram,0x0c0a440cu,4);
goto P_0c0a43a0;
P_0c0a43a0: /* original 942b, guest PC 0x0c0a43a0 */
if(!s->budget--) { s->failed_pc=0x0c0a43a0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a43fau,2);
goto P_0c0a43a2;
P_0c0a43a2: /* original 430b, guest PC 0x0c0a43a2 */
if(!s->budget--) { s->failed_pc=0x0c0a43a2u; return 0; }
target=r[3];
r[16]=0x0c0a43a6u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a43a6u) { target=s->pc; goto dispatch; }
goto P_0c0a43a6;
P_0c0a43a4: /* original 0009, guest PC 0x0c0a43a4 */
if(!s->budget--) { s->failed_pc=0x0c0a43a4u; return 0; }
goto P_0c0a43a6;
P_0c0a43a6: /* original d219, guest PC 0x0c0a43a6 */
if(!s->budget--) { s->failed_pc=0x0c0a43a6u; return 0; }
r[2]=read(ram,0x0c0a440cu,4);
goto P_0c0a43a8;
P_0c0a43a8: /* original 9428, guest PC 0x0c0a43a8 */
if(!s->budget--) { s->failed_pc=0x0c0a43a8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a43fcu,2);
goto P_0c0a43aa;
P_0c0a43aa: /* original 420b, guest PC 0x0c0a43aa */
if(!s->budget--) { s->failed_pc=0x0c0a43aau; return 0; }
target=r[2];
r[16]=0x0c0a43aeu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a43aeu) { target=s->pc; goto dispatch; }
goto P_0c0a43ae;
P_0c0a43ac: /* original 0009, guest PC 0x0c0a43ac */
if(!s->budget--) { s->failed_pc=0x0c0a43acu; return 0; }
goto P_0c0a43ae;
P_0c0a43ae: /* original d317, guest PC 0x0c0a43ae */
if(!s->budget--) { s->failed_pc=0x0c0a43aeu; return 0; }
r[3]=read(ram,0x0c0a440cu,4);
goto P_0c0a43b0;
P_0c0a43b0: /* original 9425, guest PC 0x0c0a43b0 */
if(!s->budget--) { s->failed_pc=0x0c0a43b0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a43feu,2);
goto P_0c0a43b2;
P_0c0a43b2: /* original 430b, guest PC 0x0c0a43b2 */
if(!s->budget--) { s->failed_pc=0x0c0a43b2u; return 0; }
target=r[3];
r[16]=0x0c0a43b6u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a43b6u) { target=s->pc; goto dispatch; }
goto P_0c0a43b6;
P_0c0a43b4: /* original 0009, guest PC 0x0c0a43b4 */
if(!s->budget--) { s->failed_pc=0x0c0a43b4u; return 0; }
goto P_0c0a43b6;
P_0c0a43b6: /* original d215, guest PC 0x0c0a43b6 */
if(!s->budget--) { s->failed_pc=0x0c0a43b6u; return 0; }
r[2]=read(ram,0x0c0a440cu,4);
goto P_0c0a43b8;
P_0c0a43b8: /* original 9422, guest PC 0x0c0a43b8 */
if(!s->budget--) { s->failed_pc=0x0c0a43b8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a4400u,2);
goto P_0c0a43ba;
P_0c0a43ba: /* original 420b, guest PC 0x0c0a43ba */
if(!s->budget--) { s->failed_pc=0x0c0a43bau; return 0; }
target=r[2];
r[16]=0x0c0a43beu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a43beu) { target=s->pc; goto dispatch; }
goto P_0c0a43be;
P_0c0a43bc: /* original 0009, guest PC 0x0c0a43bc */
if(!s->budget--) { s->failed_pc=0x0c0a43bcu; return 0; }
goto P_0c0a43be;
P_0c0a43be: /* original d313, guest PC 0x0c0a43be */
if(!s->budget--) { s->failed_pc=0x0c0a43beu; return 0; }
r[3]=read(ram,0x0c0a440cu,4);
goto P_0c0a43c0;
P_0c0a43c0: /* original 941f, guest PC 0x0c0a43c0 */
if(!s->budget--) { s->failed_pc=0x0c0a43c0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a4402u,2);
goto P_0c0a43c2;
P_0c0a43c2: /* original 430b, guest PC 0x0c0a43c2 */
if(!s->budget--) { s->failed_pc=0x0c0a43c2u; return 0; }
target=r[3];
r[16]=0x0c0a43c6u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a43c6u) { target=s->pc; goto dispatch; }
goto P_0c0a43c6;
P_0c0a43c4: /* original 0009, guest PC 0x0c0a43c4 */
if(!s->budget--) { s->failed_pc=0x0c0a43c4u; return 0; }
goto P_0c0a43c6;
P_0c0a43c6: /* original d211, guest PC 0x0c0a43c6 */
if(!s->budget--) { s->failed_pc=0x0c0a43c6u; return 0; }
r[2]=read(ram,0x0c0a440cu,4);
goto P_0c0a43c8;
P_0c0a43c8: /* original 941c, guest PC 0x0c0a43c8 */
if(!s->budget--) { s->failed_pc=0x0c0a43c8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a4404u,2);
goto P_0c0a43ca;
P_0c0a43ca: /* original 420b, guest PC 0x0c0a43ca */
if(!s->budget--) { s->failed_pc=0x0c0a43cau; return 0; }
target=r[2];
r[16]=0x0c0a43ceu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a43ceu) { target=s->pc; goto dispatch; }
goto P_0c0a43ce;
P_0c0a43cc: /* original 0009, guest PC 0x0c0a43cc */
if(!s->budget--) { s->failed_pc=0x0c0a43ccu; return 0; }
goto P_0c0a43ce;
P_0c0a43ce: /* original d30f, guest PC 0x0c0a43ce */
if(!s->budget--) { s->failed_pc=0x0c0a43ceu; return 0; }
r[3]=read(ram,0x0c0a440cu,4);
goto P_0c0a43d0;
P_0c0a43d0: /* original 9419, guest PC 0x0c0a43d0 */
if(!s->budget--) { s->failed_pc=0x0c0a43d0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a4406u,2);
goto P_0c0a43d2;
P_0c0a43d2: /* original 430b, guest PC 0x0c0a43d2 */
if(!s->budget--) { s->failed_pc=0x0c0a43d2u; return 0; }
target=r[3];
r[16]=0x0c0a43d6u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a43d6u) { target=s->pc; goto dispatch; }
goto P_0c0a43d6;
P_0c0a43d4: /* original 0009, guest PC 0x0c0a43d4 */
if(!s->budget--) { s->failed_pc=0x0c0a43d4u; return 0; }
goto P_0c0a43d6;
P_0c0a43d6: /* original d20d, guest PC 0x0c0a43d6 */
if(!s->budget--) { s->failed_pc=0x0c0a43d6u; return 0; }
r[2]=read(ram,0x0c0a440cu,4);
goto P_0c0a43d8;
P_0c0a43d8: /* original 9416, guest PC 0x0c0a43d8 */
if(!s->budget--) { s->failed_pc=0x0c0a43d8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a4408u,2);
goto P_0c0a43da;
P_0c0a43da: /* original 422b, guest PC 0x0c0a43da */
if(!s->budget--) { s->failed_pc=0x0c0a43dau; return 0; }
target=r[2];
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
P_0c0a43dc: /* original 4f26, guest PC 0x0c0a43dc */
if(!s->budget--) { s->failed_pc=0x0c0a43dcu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
return vf3_matrix_family(0x0c0a43deu,s,ram);
P_0c0a4508: /* original 4f22, guest PC 0x0c0a4508 */
if(!s->budget--) { s->failed_pc=0x0c0a4508u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0a450a;
P_0c0a450a: /* original d355, guest PC 0x0c0a450a */
if(!s->budget--) { s->failed_pc=0x0c0a450au; return 0; }
r[3]=read(ram,0x0c0a4660u,4);
goto P_0c0a450c;
P_0c0a450c: /* original 9485, guest PC 0x0c0a450c */
if(!s->budget--) { s->failed_pc=0x0c0a450cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a461au,2);
goto P_0c0a450e;
P_0c0a450e: /* original 430b, guest PC 0x0c0a450e */
if(!s->budget--) { s->failed_pc=0x0c0a450eu; return 0; }
target=r[3];
r[16]=0x0c0a4512u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a4512u) { target=s->pc; goto dispatch; }
goto P_0c0a4512;
P_0c0a4510: /* original 0009, guest PC 0x0c0a4510 */
if(!s->budget--) { s->failed_pc=0x0c0a4510u; return 0; }
goto P_0c0a4512;
P_0c0a4512: /* original d253, guest PC 0x0c0a4512 */
if(!s->budget--) { s->failed_pc=0x0c0a4512u; return 0; }
r[2]=read(ram,0x0c0a4660u,4);
goto P_0c0a4514;
P_0c0a4514: /* original 9482, guest PC 0x0c0a4514 */
if(!s->budget--) { s->failed_pc=0x0c0a4514u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a461cu,2);
goto P_0c0a4516;
P_0c0a4516: /* original 420b, guest PC 0x0c0a4516 */
if(!s->budget--) { s->failed_pc=0x0c0a4516u; return 0; }
target=r[2];
r[16]=0x0c0a451au;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a451au) { target=s->pc; goto dispatch; }
goto P_0c0a451a;
P_0c0a4518: /* original 0009, guest PC 0x0c0a4518 */
if(!s->budget--) { s->failed_pc=0x0c0a4518u; return 0; }
goto P_0c0a451a;
P_0c0a451a: /* original d351, guest PC 0x0c0a451a */
if(!s->budget--) { s->failed_pc=0x0c0a451au; return 0; }
r[3]=read(ram,0x0c0a4660u,4);
goto P_0c0a451c;
P_0c0a451c: /* original 947f, guest PC 0x0c0a451c */
if(!s->budget--) { s->failed_pc=0x0c0a451cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a461eu,2);
goto P_0c0a451e;
P_0c0a451e: /* original 430b, guest PC 0x0c0a451e */
if(!s->budget--) { s->failed_pc=0x0c0a451eu; return 0; }
target=r[3];
r[16]=0x0c0a4522u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a4522u) { target=s->pc; goto dispatch; }
goto P_0c0a4522;
P_0c0a4520: /* original 0009, guest PC 0x0c0a4520 */
if(!s->budget--) { s->failed_pc=0x0c0a4520u; return 0; }
goto P_0c0a4522;
P_0c0a4522: /* original d24f, guest PC 0x0c0a4522 */
if(!s->budget--) { s->failed_pc=0x0c0a4522u; return 0; }
r[2]=read(ram,0x0c0a4660u,4);
goto P_0c0a4524;
P_0c0a4524: /* original 947c, guest PC 0x0c0a4524 */
if(!s->budget--) { s->failed_pc=0x0c0a4524u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a4620u,2);
goto P_0c0a4526;
P_0c0a4526: /* original 420b, guest PC 0x0c0a4526 */
if(!s->budget--) { s->failed_pc=0x0c0a4526u; return 0; }
target=r[2];
r[16]=0x0c0a452au;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a452au) { target=s->pc; goto dispatch; }
goto P_0c0a452a;
P_0c0a4528: /* original 0009, guest PC 0x0c0a4528 */
if(!s->budget--) { s->failed_pc=0x0c0a4528u; return 0; }
goto P_0c0a452a;
P_0c0a452a: /* original d34d, guest PC 0x0c0a452a */
if(!s->budget--) { s->failed_pc=0x0c0a452au; return 0; }
r[3]=read(ram,0x0c0a4660u,4);
goto P_0c0a452c;
P_0c0a452c: /* original 9479, guest PC 0x0c0a452c */
if(!s->budget--) { s->failed_pc=0x0c0a452cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a4622u,2);
goto P_0c0a452e;
P_0c0a452e: /* original 430b, guest PC 0x0c0a452e */
if(!s->budget--) { s->failed_pc=0x0c0a452eu; return 0; }
target=r[3];
r[16]=0x0c0a4532u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a4532u) { target=s->pc; goto dispatch; }
goto P_0c0a4532;
P_0c0a4530: /* original 0009, guest PC 0x0c0a4530 */
if(!s->budget--) { s->failed_pc=0x0c0a4530u; return 0; }
goto P_0c0a4532;
P_0c0a4532: /* original d24b, guest PC 0x0c0a4532 */
if(!s->budget--) { s->failed_pc=0x0c0a4532u; return 0; }
r[2]=read(ram,0x0c0a4660u,4);
goto P_0c0a4534;
P_0c0a4534: /* original 9476, guest PC 0x0c0a4534 */
if(!s->budget--) { s->failed_pc=0x0c0a4534u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a4624u,2);
goto P_0c0a4536;
P_0c0a4536: /* original 420b, guest PC 0x0c0a4536 */
if(!s->budget--) { s->failed_pc=0x0c0a4536u; return 0; }
target=r[2];
r[16]=0x0c0a453au;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a453au) { target=s->pc; goto dispatch; }
goto P_0c0a453a;
P_0c0a4538: /* original 0009, guest PC 0x0c0a4538 */
if(!s->budget--) { s->failed_pc=0x0c0a4538u; return 0; }
goto P_0c0a453a;
P_0c0a453a: /* original d349, guest PC 0x0c0a453a */
if(!s->budget--) { s->failed_pc=0x0c0a453au; return 0; }
r[3]=read(ram,0x0c0a4660u,4);
goto P_0c0a453c;
P_0c0a453c: /* original 9473, guest PC 0x0c0a453c */
if(!s->budget--) { s->failed_pc=0x0c0a453cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a4626u,2);
goto P_0c0a453e;
P_0c0a453e: /* original 430b, guest PC 0x0c0a453e */
if(!s->budget--) { s->failed_pc=0x0c0a453eu; return 0; }
target=r[3];
r[16]=0x0c0a4542u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a4542u) { target=s->pc; goto dispatch; }
goto P_0c0a4542;
P_0c0a4540: /* original 0009, guest PC 0x0c0a4540 */
if(!s->budget--) { s->failed_pc=0x0c0a4540u; return 0; }
goto P_0c0a4542;
P_0c0a4542: /* original d247, guest PC 0x0c0a4542 */
if(!s->budget--) { s->failed_pc=0x0c0a4542u; return 0; }
r[2]=read(ram,0x0c0a4660u,4);
goto P_0c0a4544;
P_0c0a4544: /* original 9470, guest PC 0x0c0a4544 */
if(!s->budget--) { s->failed_pc=0x0c0a4544u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a4628u,2);
goto P_0c0a4546;
P_0c0a4546: /* original 420b, guest PC 0x0c0a4546 */
if(!s->budget--) { s->failed_pc=0x0c0a4546u; return 0; }
target=r[2];
r[16]=0x0c0a454au;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a454au) { target=s->pc; goto dispatch; }
goto P_0c0a454a;
P_0c0a4548: /* original 0009, guest PC 0x0c0a4548 */
if(!s->budget--) { s->failed_pc=0x0c0a4548u; return 0; }
goto P_0c0a454a;
P_0c0a454a: /* original d345, guest PC 0x0c0a454a */
if(!s->budget--) { s->failed_pc=0x0c0a454au; return 0; }
r[3]=read(ram,0x0c0a4660u,4);
goto P_0c0a454c;
P_0c0a454c: /* original 946d, guest PC 0x0c0a454c */
if(!s->budget--) { s->failed_pc=0x0c0a454cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a462au,2);
goto P_0c0a454e;
P_0c0a454e: /* original 430b, guest PC 0x0c0a454e */
if(!s->budget--) { s->failed_pc=0x0c0a454eu; return 0; }
target=r[3];
r[16]=0x0c0a4552u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a4552u) { target=s->pc; goto dispatch; }
goto P_0c0a4552;
P_0c0a4550: /* original 0009, guest PC 0x0c0a4550 */
if(!s->budget--) { s->failed_pc=0x0c0a4550u; return 0; }
goto P_0c0a4552;
P_0c0a4552: /* original d243, guest PC 0x0c0a4552 */
if(!s->budget--) { s->failed_pc=0x0c0a4552u; return 0; }
r[2]=read(ram,0x0c0a4660u,4);
goto P_0c0a4554;
P_0c0a4554: /* original 946a, guest PC 0x0c0a4554 */
if(!s->budget--) { s->failed_pc=0x0c0a4554u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a462cu,2);
goto P_0c0a4556;
P_0c0a4556: /* original 420b, guest PC 0x0c0a4556 */
if(!s->budget--) { s->failed_pc=0x0c0a4556u; return 0; }
target=r[2];
r[16]=0x0c0a455au;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a455au) { target=s->pc; goto dispatch; }
goto P_0c0a455a;
P_0c0a4558: /* original 0009, guest PC 0x0c0a4558 */
if(!s->budget--) { s->failed_pc=0x0c0a4558u; return 0; }
goto P_0c0a455a;
P_0c0a455a: /* original d341, guest PC 0x0c0a455a */
if(!s->budget--) { s->failed_pc=0x0c0a455au; return 0; }
r[3]=read(ram,0x0c0a4660u,4);
goto P_0c0a455c;
P_0c0a455c: /* original 9467, guest PC 0x0c0a455c */
if(!s->budget--) { s->failed_pc=0x0c0a455cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a462eu,2);
goto P_0c0a455e;
P_0c0a455e: /* original 430b, guest PC 0x0c0a455e */
if(!s->budget--) { s->failed_pc=0x0c0a455eu; return 0; }
target=r[3];
r[16]=0x0c0a4562u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a4562u) { target=s->pc; goto dispatch; }
goto P_0c0a4562;
P_0c0a4560: /* original 0009, guest PC 0x0c0a4560 */
if(!s->budget--) { s->failed_pc=0x0c0a4560u; return 0; }
goto P_0c0a4562;
P_0c0a4562: /* original d23f, guest PC 0x0c0a4562 */
if(!s->budget--) { s->failed_pc=0x0c0a4562u; return 0; }
r[2]=read(ram,0x0c0a4660u,4);
goto P_0c0a4564;
P_0c0a4564: /* original 9464, guest PC 0x0c0a4564 */
if(!s->budget--) { s->failed_pc=0x0c0a4564u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a4630u,2);
goto P_0c0a4566;
P_0c0a4566: /* original 420b, guest PC 0x0c0a4566 */
if(!s->budget--) { s->failed_pc=0x0c0a4566u; return 0; }
target=r[2];
r[16]=0x0c0a456au;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a456au) { target=s->pc; goto dispatch; }
goto P_0c0a456a;
P_0c0a4568: /* original 0009, guest PC 0x0c0a4568 */
if(!s->budget--) { s->failed_pc=0x0c0a4568u; return 0; }
goto P_0c0a456a;
P_0c0a456a: /* original d33d, guest PC 0x0c0a456a */
if(!s->budget--) { s->failed_pc=0x0c0a456au; return 0; }
r[3]=read(ram,0x0c0a4660u,4);
goto P_0c0a456c;
P_0c0a456c: /* original 9461, guest PC 0x0c0a456c */
if(!s->budget--) { s->failed_pc=0x0c0a456cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a4632u,2);
goto P_0c0a456e;
P_0c0a456e: /* original 430b, guest PC 0x0c0a456e */
if(!s->budget--) { s->failed_pc=0x0c0a456eu; return 0; }
target=r[3];
r[16]=0x0c0a4572u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a4572u) { target=s->pc; goto dispatch; }
goto P_0c0a4572;
P_0c0a4570: /* original 0009, guest PC 0x0c0a4570 */
if(!s->budget--) { s->failed_pc=0x0c0a4570u; return 0; }
goto P_0c0a4572;
P_0c0a4572: /* original d23b, guest PC 0x0c0a4572 */
if(!s->budget--) { s->failed_pc=0x0c0a4572u; return 0; }
r[2]=read(ram,0x0c0a4660u,4);
goto P_0c0a4574;
P_0c0a4574: /* original 945e, guest PC 0x0c0a4574 */
if(!s->budget--) { s->failed_pc=0x0c0a4574u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a4634u,2);
goto P_0c0a4576;
P_0c0a4576: /* original 420b, guest PC 0x0c0a4576 */
if(!s->budget--) { s->failed_pc=0x0c0a4576u; return 0; }
target=r[2];
r[16]=0x0c0a457au;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a457au) { target=s->pc; goto dispatch; }
goto P_0c0a457a;
P_0c0a4578: /* original 0009, guest PC 0x0c0a4578 */
if(!s->budget--) { s->failed_pc=0x0c0a4578u; return 0; }
goto P_0c0a457a;
P_0c0a457a: /* original d339, guest PC 0x0c0a457a */
if(!s->budget--) { s->failed_pc=0x0c0a457au; return 0; }
r[3]=read(ram,0x0c0a4660u,4);
goto P_0c0a457c;
P_0c0a457c: /* original 945b, guest PC 0x0c0a457c */
if(!s->budget--) { s->failed_pc=0x0c0a457cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a4636u,2);
goto P_0c0a457e;
P_0c0a457e: /* original 430b, guest PC 0x0c0a457e */
if(!s->budget--) { s->failed_pc=0x0c0a457eu; return 0; }
target=r[3];
r[16]=0x0c0a4582u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a4582u) { target=s->pc; goto dispatch; }
goto P_0c0a4582;
P_0c0a4580: /* original 0009, guest PC 0x0c0a4580 */
if(!s->budget--) { s->failed_pc=0x0c0a4580u; return 0; }
goto P_0c0a4582;
P_0c0a4582: /* original d237, guest PC 0x0c0a4582 */
if(!s->budget--) { s->failed_pc=0x0c0a4582u; return 0; }
r[2]=read(ram,0x0c0a4660u,4);
goto P_0c0a4584;
P_0c0a4584: /* original 9458, guest PC 0x0c0a4584 */
if(!s->budget--) { s->failed_pc=0x0c0a4584u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a4638u,2);
goto P_0c0a4586;
P_0c0a4586: /* original 420b, guest PC 0x0c0a4586 */
if(!s->budget--) { s->failed_pc=0x0c0a4586u; return 0; }
target=r[2];
r[16]=0x0c0a458au;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a458au) { target=s->pc; goto dispatch; }
goto P_0c0a458a;
P_0c0a4588: /* original 0009, guest PC 0x0c0a4588 */
if(!s->budget--) { s->failed_pc=0x0c0a4588u; return 0; }
goto P_0c0a458a;
P_0c0a458a: /* original d335, guest PC 0x0c0a458a */
if(!s->budget--) { s->failed_pc=0x0c0a458au; return 0; }
r[3]=read(ram,0x0c0a4660u,4);
goto P_0c0a458c;
P_0c0a458c: /* original 9455, guest PC 0x0c0a458c */
if(!s->budget--) { s->failed_pc=0x0c0a458cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a463au,2);
goto P_0c0a458e;
P_0c0a458e: /* original 430b, guest PC 0x0c0a458e */
if(!s->budget--) { s->failed_pc=0x0c0a458eu; return 0; }
target=r[3];
r[16]=0x0c0a4592u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a4592u) { target=s->pc; goto dispatch; }
goto P_0c0a4592;
P_0c0a4590: /* original 0009, guest PC 0x0c0a4590 */
if(!s->budget--) { s->failed_pc=0x0c0a4590u; return 0; }
goto P_0c0a4592;
P_0c0a4592: /* original d233, guest PC 0x0c0a4592 */
if(!s->budget--) { s->failed_pc=0x0c0a4592u; return 0; }
r[2]=read(ram,0x0c0a4660u,4);
goto P_0c0a4594;
P_0c0a4594: /* original 9452, guest PC 0x0c0a4594 */
if(!s->budget--) { s->failed_pc=0x0c0a4594u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a463cu,2);
goto P_0c0a4596;
P_0c0a4596: /* original 420b, guest PC 0x0c0a4596 */
if(!s->budget--) { s->failed_pc=0x0c0a4596u; return 0; }
target=r[2];
r[16]=0x0c0a459au;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a459au) { target=s->pc; goto dispatch; }
goto P_0c0a459a;
P_0c0a4598: /* original 0009, guest PC 0x0c0a4598 */
if(!s->budget--) { s->failed_pc=0x0c0a4598u; return 0; }
goto P_0c0a459a;
P_0c0a459a: /* original d331, guest PC 0x0c0a459a */
if(!s->budget--) { s->failed_pc=0x0c0a459au; return 0; }
r[3]=read(ram,0x0c0a4660u,4);
goto P_0c0a459c;
P_0c0a459c: /* original 944f, guest PC 0x0c0a459c */
if(!s->budget--) { s->failed_pc=0x0c0a459cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a463eu,2);
goto P_0c0a459e;
P_0c0a459e: /* original 430b, guest PC 0x0c0a459e */
if(!s->budget--) { s->failed_pc=0x0c0a459eu; return 0; }
target=r[3];
r[16]=0x0c0a45a2u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a45a2u) { target=s->pc; goto dispatch; }
goto P_0c0a45a2;
P_0c0a45a0: /* original 0009, guest PC 0x0c0a45a0 */
if(!s->budget--) { s->failed_pc=0x0c0a45a0u; return 0; }
goto P_0c0a45a2;
P_0c0a45a2: /* original d22f, guest PC 0x0c0a45a2 */
if(!s->budget--) { s->failed_pc=0x0c0a45a2u; return 0; }
r[2]=read(ram,0x0c0a4660u,4);
goto P_0c0a45a4;
P_0c0a45a4: /* original 944c, guest PC 0x0c0a45a4 */
if(!s->budget--) { s->failed_pc=0x0c0a45a4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a4640u,2);
goto P_0c0a45a6;
P_0c0a45a6: /* original 420b, guest PC 0x0c0a45a6 */
if(!s->budget--) { s->failed_pc=0x0c0a45a6u; return 0; }
target=r[2];
r[16]=0x0c0a45aau;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a45aau) { target=s->pc; goto dispatch; }
goto P_0c0a45aa;
P_0c0a45a8: /* original 0009, guest PC 0x0c0a45a8 */
if(!s->budget--) { s->failed_pc=0x0c0a45a8u; return 0; }
goto P_0c0a45aa;
P_0c0a45aa: /* original d32d, guest PC 0x0c0a45aa */
if(!s->budget--) { s->failed_pc=0x0c0a45aau; return 0; }
r[3]=read(ram,0x0c0a4660u,4);
goto P_0c0a45ac;
P_0c0a45ac: /* original 9449, guest PC 0x0c0a45ac */
if(!s->budget--) { s->failed_pc=0x0c0a45acu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a4642u,2);
goto P_0c0a45ae;
P_0c0a45ae: /* original 430b, guest PC 0x0c0a45ae */
if(!s->budget--) { s->failed_pc=0x0c0a45aeu; return 0; }
target=r[3];
r[16]=0x0c0a45b2u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a45b2u) { target=s->pc; goto dispatch; }
goto P_0c0a45b2;
P_0c0a45b0: /* original 0009, guest PC 0x0c0a45b0 */
if(!s->budget--) { s->failed_pc=0x0c0a45b0u; return 0; }
goto P_0c0a45b2;
P_0c0a45b2: /* original d22b, guest PC 0x0c0a45b2 */
if(!s->budget--) { s->failed_pc=0x0c0a45b2u; return 0; }
r[2]=read(ram,0x0c0a4660u,4);
goto P_0c0a45b4;
P_0c0a45b4: /* original 9446, guest PC 0x0c0a45b4 */
if(!s->budget--) { s->failed_pc=0x0c0a45b4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a4644u,2);
goto P_0c0a45b6;
P_0c0a45b6: /* original 420b, guest PC 0x0c0a45b6 */
if(!s->budget--) { s->failed_pc=0x0c0a45b6u; return 0; }
target=r[2];
r[16]=0x0c0a45bau;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a45bau) { target=s->pc; goto dispatch; }
goto P_0c0a45ba;
P_0c0a45b8: /* original 0009, guest PC 0x0c0a45b8 */
if(!s->budget--) { s->failed_pc=0x0c0a45b8u; return 0; }
goto P_0c0a45ba;
P_0c0a45ba: /* original d329, guest PC 0x0c0a45ba */
if(!s->budget--) { s->failed_pc=0x0c0a45bau; return 0; }
r[3]=read(ram,0x0c0a4660u,4);
goto P_0c0a45bc;
P_0c0a45bc: /* original 9443, guest PC 0x0c0a45bc */
if(!s->budget--) { s->failed_pc=0x0c0a45bcu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a4646u,2);
goto P_0c0a45be;
P_0c0a45be: /* original 430b, guest PC 0x0c0a45be */
if(!s->budget--) { s->failed_pc=0x0c0a45beu; return 0; }
target=r[3];
r[16]=0x0c0a45c2u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a45c2u) { target=s->pc; goto dispatch; }
goto P_0c0a45c2;
P_0c0a45c0: /* original 0009, guest PC 0x0c0a45c0 */
if(!s->budget--) { s->failed_pc=0x0c0a45c0u; return 0; }
goto P_0c0a45c2;
P_0c0a45c2: /* original d227, guest PC 0x0c0a45c2 */
if(!s->budget--) { s->failed_pc=0x0c0a45c2u; return 0; }
r[2]=read(ram,0x0c0a4660u,4);
goto P_0c0a45c4;
P_0c0a45c4: /* original 9440, guest PC 0x0c0a45c4 */
if(!s->budget--) { s->failed_pc=0x0c0a45c4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a4648u,2);
goto P_0c0a45c6;
P_0c0a45c6: /* original 420b, guest PC 0x0c0a45c6 */
if(!s->budget--) { s->failed_pc=0x0c0a45c6u; return 0; }
target=r[2];
r[16]=0x0c0a45cau;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a45cau) { target=s->pc; goto dispatch; }
goto P_0c0a45ca;
P_0c0a45c8: /* original 0009, guest PC 0x0c0a45c8 */
if(!s->budget--) { s->failed_pc=0x0c0a45c8u; return 0; }
goto P_0c0a45ca;
P_0c0a45ca: /* original d325, guest PC 0x0c0a45ca */
if(!s->budget--) { s->failed_pc=0x0c0a45cau; return 0; }
r[3]=read(ram,0x0c0a4660u,4);
goto P_0c0a45cc;
P_0c0a45cc: /* original 943d, guest PC 0x0c0a45cc */
if(!s->budget--) { s->failed_pc=0x0c0a45ccu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a464au,2);
goto P_0c0a45ce;
P_0c0a45ce: /* original 430b, guest PC 0x0c0a45ce */
if(!s->budget--) { s->failed_pc=0x0c0a45ceu; return 0; }
target=r[3];
r[16]=0x0c0a45d2u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a45d2u) { target=s->pc; goto dispatch; }
goto P_0c0a45d2;
P_0c0a45d0: /* original 0009, guest PC 0x0c0a45d0 */
if(!s->budget--) { s->failed_pc=0x0c0a45d0u; return 0; }
goto P_0c0a45d2;
P_0c0a45d2: /* original d223, guest PC 0x0c0a45d2 */
if(!s->budget--) { s->failed_pc=0x0c0a45d2u; return 0; }
r[2]=read(ram,0x0c0a4660u,4);
goto P_0c0a45d4;
P_0c0a45d4: /* original 943a, guest PC 0x0c0a45d4 */
if(!s->budget--) { s->failed_pc=0x0c0a45d4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a464cu,2);
goto P_0c0a45d6;
P_0c0a45d6: /* original 420b, guest PC 0x0c0a45d6 */
if(!s->budget--) { s->failed_pc=0x0c0a45d6u; return 0; }
target=r[2];
r[16]=0x0c0a45dau;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a45dau) { target=s->pc; goto dispatch; }
goto P_0c0a45da;
P_0c0a45d8: /* original 0009, guest PC 0x0c0a45d8 */
if(!s->budget--) { s->failed_pc=0x0c0a45d8u; return 0; }
goto P_0c0a45da;
P_0c0a45da: /* original d321, guest PC 0x0c0a45da */
if(!s->budget--) { s->failed_pc=0x0c0a45dau; return 0; }
r[3]=read(ram,0x0c0a4660u,4);
goto P_0c0a45dc;
P_0c0a45dc: /* original 9437, guest PC 0x0c0a45dc */
if(!s->budget--) { s->failed_pc=0x0c0a45dcu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a464eu,2);
goto P_0c0a45de;
P_0c0a45de: /* original 430b, guest PC 0x0c0a45de */
if(!s->budget--) { s->failed_pc=0x0c0a45deu; return 0; }
target=r[3];
r[16]=0x0c0a45e2u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a45e2u) { target=s->pc; goto dispatch; }
goto P_0c0a45e2;
P_0c0a45e0: /* original 0009, guest PC 0x0c0a45e0 */
if(!s->budget--) { s->failed_pc=0x0c0a45e0u; return 0; }
goto P_0c0a45e2;
P_0c0a45e2: /* original d21f, guest PC 0x0c0a45e2 */
if(!s->budget--) { s->failed_pc=0x0c0a45e2u; return 0; }
r[2]=read(ram,0x0c0a4660u,4);
goto P_0c0a45e4;
P_0c0a45e4: /* original 9434, guest PC 0x0c0a45e4 */
if(!s->budget--) { s->failed_pc=0x0c0a45e4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a4650u,2);
goto P_0c0a45e6;
P_0c0a45e6: /* original 420b, guest PC 0x0c0a45e6 */
if(!s->budget--) { s->failed_pc=0x0c0a45e6u; return 0; }
target=r[2];
r[16]=0x0c0a45eau;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a45eau) { target=s->pc; goto dispatch; }
goto P_0c0a45ea;
P_0c0a45e8: /* original 0009, guest PC 0x0c0a45e8 */
if(!s->budget--) { s->failed_pc=0x0c0a45e8u; return 0; }
goto P_0c0a45ea;
P_0c0a45ea: /* original d31d, guest PC 0x0c0a45ea */
if(!s->budget--) { s->failed_pc=0x0c0a45eau; return 0; }
r[3]=read(ram,0x0c0a4660u,4);
goto P_0c0a45ec;
P_0c0a45ec: /* original 9431, guest PC 0x0c0a45ec */
if(!s->budget--) { s->failed_pc=0x0c0a45ecu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a4652u,2);
goto P_0c0a45ee;
P_0c0a45ee: /* original 430b, guest PC 0x0c0a45ee */
if(!s->budget--) { s->failed_pc=0x0c0a45eeu; return 0; }
target=r[3];
r[16]=0x0c0a45f2u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a45f2u) { target=s->pc; goto dispatch; }
goto P_0c0a45f2;
P_0c0a45f0: /* original 0009, guest PC 0x0c0a45f0 */
if(!s->budget--) { s->failed_pc=0x0c0a45f0u; return 0; }
goto P_0c0a45f2;
P_0c0a45f2: /* original d21b, guest PC 0x0c0a45f2 */
if(!s->budget--) { s->failed_pc=0x0c0a45f2u; return 0; }
r[2]=read(ram,0x0c0a4660u,4);
goto P_0c0a45f4;
P_0c0a45f4: /* original 942e, guest PC 0x0c0a45f4 */
if(!s->budget--) { s->failed_pc=0x0c0a45f4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a4654u,2);
goto P_0c0a45f6;
P_0c0a45f6: /* original 420b, guest PC 0x0c0a45f6 */
if(!s->budget--) { s->failed_pc=0x0c0a45f6u; return 0; }
target=r[2];
r[16]=0x0c0a45fau;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a45fau) { target=s->pc; goto dispatch; }
goto P_0c0a45fa;
P_0c0a45f8: /* original 0009, guest PC 0x0c0a45f8 */
if(!s->budget--) { s->failed_pc=0x0c0a45f8u; return 0; }
goto P_0c0a45fa;
P_0c0a45fa: /* original d319, guest PC 0x0c0a45fa */
if(!s->budget--) { s->failed_pc=0x0c0a45fau; return 0; }
r[3]=read(ram,0x0c0a4660u,4);
goto P_0c0a45fc;
P_0c0a45fc: /* original 942b, guest PC 0x0c0a45fc */
if(!s->budget--) { s->failed_pc=0x0c0a45fcu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a4656u,2);
goto P_0c0a45fe;
P_0c0a45fe: /* original 430b, guest PC 0x0c0a45fe */
if(!s->budget--) { s->failed_pc=0x0c0a45feu; return 0; }
target=r[3];
r[16]=0x0c0a4602u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a4602u) { target=s->pc; goto dispatch; }
goto P_0c0a4602;
P_0c0a4600: /* original 0009, guest PC 0x0c0a4600 */
if(!s->budget--) { s->failed_pc=0x0c0a4600u; return 0; }
goto P_0c0a4602;
P_0c0a4602: /* original d217, guest PC 0x0c0a4602 */
if(!s->budget--) { s->failed_pc=0x0c0a4602u; return 0; }
r[2]=read(ram,0x0c0a4660u,4);
goto P_0c0a4604;
P_0c0a4604: /* original 9428, guest PC 0x0c0a4604 */
if(!s->budget--) { s->failed_pc=0x0c0a4604u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a4658u,2);
goto P_0c0a4606;
P_0c0a4606: /* original 420b, guest PC 0x0c0a4606 */
if(!s->budget--) { s->failed_pc=0x0c0a4606u; return 0; }
target=r[2];
r[16]=0x0c0a460au;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a460au) { target=s->pc; goto dispatch; }
goto P_0c0a460a;
P_0c0a4608: /* original 0009, guest PC 0x0c0a4608 */
if(!s->budget--) { s->failed_pc=0x0c0a4608u; return 0; }
goto P_0c0a460a;
P_0c0a460a: /* original d315, guest PC 0x0c0a460a */
if(!s->budget--) { s->failed_pc=0x0c0a460au; return 0; }
r[3]=read(ram,0x0c0a4660u,4);
goto P_0c0a460c;
P_0c0a460c: /* original 9425, guest PC 0x0c0a460c */
if(!s->budget--) { s->failed_pc=0x0c0a460cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a465au,2);
goto P_0c0a460e;
P_0c0a460e: /* original 430b, guest PC 0x0c0a460e */
if(!s->budget--) { s->failed_pc=0x0c0a460eu; return 0; }
target=r[3];
r[16]=0x0c0a4612u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a4612u) { target=s->pc; goto dispatch; }
goto P_0c0a4612;
P_0c0a4610: /* original 0009, guest PC 0x0c0a4610 */
if(!s->budget--) { s->failed_pc=0x0c0a4610u; return 0; }
goto P_0c0a4612;
P_0c0a4612: /* original d213, guest PC 0x0c0a4612 */
if(!s->budget--) { s->failed_pc=0x0c0a4612u; return 0; }
r[2]=read(ram,0x0c0a4660u,4);
goto P_0c0a4614;
P_0c0a4614: /* original 9422, guest PC 0x0c0a4614 */
if(!s->budget--) { s->failed_pc=0x0c0a4614u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a465cu,2);
goto P_0c0a4616;
P_0c0a4616: /* original 422b, guest PC 0x0c0a4616 */
if(!s->budget--) { s->failed_pc=0x0c0a4616u; return 0; }
target=r[2];
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
P_0c0a4618: /* original 4f26, guest PC 0x0c0a4618 */
if(!s->budget--) { s->failed_pc=0x0c0a4618u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
return vf3_matrix_family(0x0c0a461au,s,ram);
P_0c0a47d4: /* original 4f22, guest PC 0x0c0a47d4 */
if(!s->budget--) { s->failed_pc=0x0c0a47d4u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0a47d6;
P_0c0a47d6: /* original d35a, guest PC 0x0c0a47d6 */
if(!s->budget--) { s->failed_pc=0x0c0a47d6u; return 0; }
r[3]=read(ram,0x0c0a4940u,4);
goto P_0c0a47d8;
P_0c0a47d8: /* original 949e, guest PC 0x0c0a47d8 */
if(!s->budget--) { s->failed_pc=0x0c0a47d8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a4918u,2);
goto P_0c0a47da;
P_0c0a47da: /* original 430b, guest PC 0x0c0a47da */
if(!s->budget--) { s->failed_pc=0x0c0a47dau; return 0; }
target=r[3];
r[16]=0x0c0a47deu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a47deu) { target=s->pc; goto dispatch; }
goto P_0c0a47de;
P_0c0a47dc: /* original 0009, guest PC 0x0c0a47dc */
if(!s->budget--) { s->failed_pc=0x0c0a47dcu; return 0; }
goto P_0c0a47de;
P_0c0a47de: /* original d258, guest PC 0x0c0a47de */
if(!s->budget--) { s->failed_pc=0x0c0a47deu; return 0; }
r[2]=read(ram,0x0c0a4940u,4);
goto P_0c0a47e0;
P_0c0a47e0: /* original 949b, guest PC 0x0c0a47e0 */
if(!s->budget--) { s->failed_pc=0x0c0a47e0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a491au,2);
goto P_0c0a47e2;
P_0c0a47e2: /* original 420b, guest PC 0x0c0a47e2 */
if(!s->budget--) { s->failed_pc=0x0c0a47e2u; return 0; }
target=r[2];
r[16]=0x0c0a47e6u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a47e6u) { target=s->pc; goto dispatch; }
goto P_0c0a47e6;
P_0c0a47e4: /* original 0009, guest PC 0x0c0a47e4 */
if(!s->budget--) { s->failed_pc=0x0c0a47e4u; return 0; }
goto P_0c0a47e6;
P_0c0a47e6: /* original d356, guest PC 0x0c0a47e6 */
if(!s->budget--) { s->failed_pc=0x0c0a47e6u; return 0; }
r[3]=read(ram,0x0c0a4940u,4);
goto P_0c0a47e8;
P_0c0a47e8: /* original 9498, guest PC 0x0c0a47e8 */
if(!s->budget--) { s->failed_pc=0x0c0a47e8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a491cu,2);
goto P_0c0a47ea;
P_0c0a47ea: /* original 430b, guest PC 0x0c0a47ea */
if(!s->budget--) { s->failed_pc=0x0c0a47eau; return 0; }
target=r[3];
r[16]=0x0c0a47eeu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a47eeu) { target=s->pc; goto dispatch; }
goto P_0c0a47ee;
P_0c0a47ec: /* original 0009, guest PC 0x0c0a47ec */
if(!s->budget--) { s->failed_pc=0x0c0a47ecu; return 0; }
goto P_0c0a47ee;
P_0c0a47ee: /* original d254, guest PC 0x0c0a47ee */
if(!s->budget--) { s->failed_pc=0x0c0a47eeu; return 0; }
r[2]=read(ram,0x0c0a4940u,4);
goto P_0c0a47f0;
P_0c0a47f0: /* original 9495, guest PC 0x0c0a47f0 */
if(!s->budget--) { s->failed_pc=0x0c0a47f0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a491eu,2);
goto P_0c0a47f2;
P_0c0a47f2: /* original 420b, guest PC 0x0c0a47f2 */
if(!s->budget--) { s->failed_pc=0x0c0a47f2u; return 0; }
target=r[2];
r[16]=0x0c0a47f6u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a47f6u) { target=s->pc; goto dispatch; }
goto P_0c0a47f6;
P_0c0a47f4: /* original 0009, guest PC 0x0c0a47f4 */
if(!s->budget--) { s->failed_pc=0x0c0a47f4u; return 0; }
goto P_0c0a47f6;
P_0c0a47f6: /* original d352, guest PC 0x0c0a47f6 */
if(!s->budget--) { s->failed_pc=0x0c0a47f6u; return 0; }
r[3]=read(ram,0x0c0a4940u,4);
goto P_0c0a47f8;
P_0c0a47f8: /* original 9492, guest PC 0x0c0a47f8 */
if(!s->budget--) { s->failed_pc=0x0c0a47f8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a4920u,2);
goto P_0c0a47fa;
P_0c0a47fa: /* original 430b, guest PC 0x0c0a47fa */
if(!s->budget--) { s->failed_pc=0x0c0a47fau; return 0; }
target=r[3];
r[16]=0x0c0a47feu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a47feu) { target=s->pc; goto dispatch; }
goto P_0c0a47fe;
P_0c0a47fc: /* original 0009, guest PC 0x0c0a47fc */
if(!s->budget--) { s->failed_pc=0x0c0a47fcu; return 0; }
goto P_0c0a47fe;
P_0c0a47fe: /* original d250, guest PC 0x0c0a47fe */
if(!s->budget--) { s->failed_pc=0x0c0a47feu; return 0; }
r[2]=read(ram,0x0c0a4940u,4);
goto P_0c0a4800;
P_0c0a4800: /* original 948f, guest PC 0x0c0a4800 */
if(!s->budget--) { s->failed_pc=0x0c0a4800u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a4922u,2);
goto P_0c0a4802;
P_0c0a4802: /* original 420b, guest PC 0x0c0a4802 */
if(!s->budget--) { s->failed_pc=0x0c0a4802u; return 0; }
target=r[2];
r[16]=0x0c0a4806u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a4806u) { target=s->pc; goto dispatch; }
goto P_0c0a4806;
P_0c0a4804: /* original 0009, guest PC 0x0c0a4804 */
if(!s->budget--) { s->failed_pc=0x0c0a4804u; return 0; }
goto P_0c0a4806;
P_0c0a4806: /* original d34e, guest PC 0x0c0a4806 */
if(!s->budget--) { s->failed_pc=0x0c0a4806u; return 0; }
r[3]=read(ram,0x0c0a4940u,4);
goto P_0c0a4808;
P_0c0a4808: /* original 948c, guest PC 0x0c0a4808 */
if(!s->budget--) { s->failed_pc=0x0c0a4808u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a4924u,2);
goto P_0c0a480a;
P_0c0a480a: /* original 430b, guest PC 0x0c0a480a */
if(!s->budget--) { s->failed_pc=0x0c0a480au; return 0; }
target=r[3];
r[16]=0x0c0a480eu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a480eu) { target=s->pc; goto dispatch; }
goto P_0c0a480e;
P_0c0a480c: /* original 0009, guest PC 0x0c0a480c */
if(!s->budget--) { s->failed_pc=0x0c0a480cu; return 0; }
goto P_0c0a480e;
P_0c0a480e: /* original d24c, guest PC 0x0c0a480e */
if(!s->budget--) { s->failed_pc=0x0c0a480eu; return 0; }
r[2]=read(ram,0x0c0a4940u,4);
goto P_0c0a4810;
P_0c0a4810: /* original 9489, guest PC 0x0c0a4810 */
if(!s->budget--) { s->failed_pc=0x0c0a4810u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a4926u,2);
goto P_0c0a4812;
P_0c0a4812: /* original 420b, guest PC 0x0c0a4812 */
if(!s->budget--) { s->failed_pc=0x0c0a4812u; return 0; }
target=r[2];
r[16]=0x0c0a4816u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a4816u) { target=s->pc; goto dispatch; }
goto P_0c0a4816;
P_0c0a4814: /* original 0009, guest PC 0x0c0a4814 */
if(!s->budget--) { s->failed_pc=0x0c0a4814u; return 0; }
goto P_0c0a4816;
P_0c0a4816: /* original d34a, guest PC 0x0c0a4816 */
if(!s->budget--) { s->failed_pc=0x0c0a4816u; return 0; }
r[3]=read(ram,0x0c0a4940u,4);
goto P_0c0a4818;
P_0c0a4818: /* original 9486, guest PC 0x0c0a4818 */
if(!s->budget--) { s->failed_pc=0x0c0a4818u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a4928u,2);
goto P_0c0a481a;
P_0c0a481a: /* original 430b, guest PC 0x0c0a481a */
if(!s->budget--) { s->failed_pc=0x0c0a481au; return 0; }
target=r[3];
r[16]=0x0c0a481eu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a481eu) { target=s->pc; goto dispatch; }
goto P_0c0a481e;
P_0c0a481c: /* original 0009, guest PC 0x0c0a481c */
if(!s->budget--) { s->failed_pc=0x0c0a481cu; return 0; }
goto P_0c0a481e;
P_0c0a481e: /* original d248, guest PC 0x0c0a481e */
if(!s->budget--) { s->failed_pc=0x0c0a481eu; return 0; }
r[2]=read(ram,0x0c0a4940u,4);
goto P_0c0a4820;
P_0c0a4820: /* original 9483, guest PC 0x0c0a4820 */
if(!s->budget--) { s->failed_pc=0x0c0a4820u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a492au,2);
goto P_0c0a4822;
P_0c0a4822: /* original 420b, guest PC 0x0c0a4822 */
if(!s->budget--) { s->failed_pc=0x0c0a4822u; return 0; }
target=r[2];
r[16]=0x0c0a4826u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a4826u) { target=s->pc; goto dispatch; }
goto P_0c0a4826;
P_0c0a4824: /* original 0009, guest PC 0x0c0a4824 */
if(!s->budget--) { s->failed_pc=0x0c0a4824u; return 0; }
goto P_0c0a4826;
P_0c0a4826: /* original d346, guest PC 0x0c0a4826 */
if(!s->budget--) { s->failed_pc=0x0c0a4826u; return 0; }
r[3]=read(ram,0x0c0a4940u,4);
goto P_0c0a4828;
P_0c0a4828: /* original 9480, guest PC 0x0c0a4828 */
if(!s->budget--) { s->failed_pc=0x0c0a4828u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a492cu,2);
goto P_0c0a482a;
P_0c0a482a: /* original 430b, guest PC 0x0c0a482a */
if(!s->budget--) { s->failed_pc=0x0c0a482au; return 0; }
target=r[3];
r[16]=0x0c0a482eu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a482eu) { target=s->pc; goto dispatch; }
goto P_0c0a482e;
P_0c0a482c: /* original 0009, guest PC 0x0c0a482c */
if(!s->budget--) { s->failed_pc=0x0c0a482cu; return 0; }
goto P_0c0a482e;
P_0c0a482e: /* original d244, guest PC 0x0c0a482e */
if(!s->budget--) { s->failed_pc=0x0c0a482eu; return 0; }
r[2]=read(ram,0x0c0a4940u,4);
goto P_0c0a4830;
P_0c0a4830: /* original 947d, guest PC 0x0c0a4830 */
if(!s->budget--) { s->failed_pc=0x0c0a4830u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a492eu,2);
goto P_0c0a4832;
P_0c0a4832: /* original 420b, guest PC 0x0c0a4832 */
if(!s->budget--) { s->failed_pc=0x0c0a4832u; return 0; }
target=r[2];
r[16]=0x0c0a4836u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a4836u) { target=s->pc; goto dispatch; }
goto P_0c0a4836;
P_0c0a4834: /* original 0009, guest PC 0x0c0a4834 */
if(!s->budget--) { s->failed_pc=0x0c0a4834u; return 0; }
goto P_0c0a4836;
P_0c0a4836: /* original d342, guest PC 0x0c0a4836 */
if(!s->budget--) { s->failed_pc=0x0c0a4836u; return 0; }
r[3]=read(ram,0x0c0a4940u,4);
goto P_0c0a4838;
P_0c0a4838: /* original 947a, guest PC 0x0c0a4838 */
if(!s->budget--) { s->failed_pc=0x0c0a4838u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a4930u,2);
goto P_0c0a483a;
P_0c0a483a: /* original 430b, guest PC 0x0c0a483a */
if(!s->budget--) { s->failed_pc=0x0c0a483au; return 0; }
target=r[3];
r[16]=0x0c0a483eu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a483eu) { target=s->pc; goto dispatch; }
goto P_0c0a483e;
P_0c0a483c: /* original 0009, guest PC 0x0c0a483c */
if(!s->budget--) { s->failed_pc=0x0c0a483cu; return 0; }
goto P_0c0a483e;
P_0c0a483e: /* original d240, guest PC 0x0c0a483e */
if(!s->budget--) { s->failed_pc=0x0c0a483eu; return 0; }
r[2]=read(ram,0x0c0a4940u,4);
goto P_0c0a4840;
P_0c0a4840: /* original 9477, guest PC 0x0c0a4840 */
if(!s->budget--) { s->failed_pc=0x0c0a4840u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a4932u,2);
goto P_0c0a4842;
P_0c0a4842: /* original 420b, guest PC 0x0c0a4842 */
if(!s->budget--) { s->failed_pc=0x0c0a4842u; return 0; }
target=r[2];
r[16]=0x0c0a4846u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a4846u) { target=s->pc; goto dispatch; }
goto P_0c0a4846;
P_0c0a4844: /* original 0009, guest PC 0x0c0a4844 */
if(!s->budget--) { s->failed_pc=0x0c0a4844u; return 0; }
goto P_0c0a4846;
P_0c0a4846: /* original d33e, guest PC 0x0c0a4846 */
if(!s->budget--) { s->failed_pc=0x0c0a4846u; return 0; }
r[3]=read(ram,0x0c0a4940u,4);
goto P_0c0a4848;
P_0c0a4848: /* original 9474, guest PC 0x0c0a4848 */
if(!s->budget--) { s->failed_pc=0x0c0a4848u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a4934u,2);
goto P_0c0a484a;
P_0c0a484a: /* original 430b, guest PC 0x0c0a484a */
if(!s->budget--) { s->failed_pc=0x0c0a484au; return 0; }
target=r[3];
r[16]=0x0c0a484eu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a484eu) { target=s->pc; goto dispatch; }
goto P_0c0a484e;
P_0c0a484c: /* original 0009, guest PC 0x0c0a484c */
if(!s->budget--) { s->failed_pc=0x0c0a484cu; return 0; }
goto P_0c0a484e;
P_0c0a484e: /* original d23c, guest PC 0x0c0a484e */
if(!s->budget--) { s->failed_pc=0x0c0a484eu; return 0; }
r[2]=read(ram,0x0c0a4940u,4);
goto P_0c0a4850;
P_0c0a4850: /* original 9471, guest PC 0x0c0a4850 */
if(!s->budget--) { s->failed_pc=0x0c0a4850u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a4936u,2);
goto P_0c0a4852;
P_0c0a4852: /* original 420b, guest PC 0x0c0a4852 */
if(!s->budget--) { s->failed_pc=0x0c0a4852u; return 0; }
target=r[2];
r[16]=0x0c0a4856u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a4856u) { target=s->pc; goto dispatch; }
goto P_0c0a4856;
P_0c0a4854: /* original 0009, guest PC 0x0c0a4854 */
if(!s->budget--) { s->failed_pc=0x0c0a4854u; return 0; }
goto P_0c0a4856;
P_0c0a4856: /* original d33a, guest PC 0x0c0a4856 */
if(!s->budget--) { s->failed_pc=0x0c0a4856u; return 0; }
r[3]=read(ram,0x0c0a4940u,4);
goto P_0c0a4858;
P_0c0a4858: /* original 946e, guest PC 0x0c0a4858 */
if(!s->budget--) { s->failed_pc=0x0c0a4858u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a4938u,2);
goto P_0c0a485a;
P_0c0a485a: /* original 430b, guest PC 0x0c0a485a */
if(!s->budget--) { s->failed_pc=0x0c0a485au; return 0; }
target=r[3];
r[16]=0x0c0a485eu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a485eu) { target=s->pc; goto dispatch; }
goto P_0c0a485e;
P_0c0a485c: /* original 0009, guest PC 0x0c0a485c */
if(!s->budget--) { s->failed_pc=0x0c0a485cu; return 0; }
goto P_0c0a485e;
P_0c0a485e: /* original d238, guest PC 0x0c0a485e */
if(!s->budget--) { s->failed_pc=0x0c0a485eu; return 0; }
r[2]=read(ram,0x0c0a4940u,4);
goto P_0c0a4860;
P_0c0a4860: /* original 946b, guest PC 0x0c0a4860 */
if(!s->budget--) { s->failed_pc=0x0c0a4860u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a493au,2);
goto P_0c0a4862;
P_0c0a4862: /* original 420b, guest PC 0x0c0a4862 */
if(!s->budget--) { s->failed_pc=0x0c0a4862u; return 0; }
target=r[2];
r[16]=0x0c0a4866u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a4866u) { target=s->pc; goto dispatch; }
goto P_0c0a4866;
P_0c0a4864: /* original 0009, guest PC 0x0c0a4864 */
if(!s->budget--) { s->failed_pc=0x0c0a4864u; return 0; }
goto P_0c0a4866;
P_0c0a4866: /* original d336, guest PC 0x0c0a4866 */
if(!s->budget--) { s->failed_pc=0x0c0a4866u; return 0; }
r[3]=read(ram,0x0c0a4940u,4);
goto P_0c0a4868;
P_0c0a4868: /* original 9468, guest PC 0x0c0a4868 */
if(!s->budget--) { s->failed_pc=0x0c0a4868u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a493cu,2);
goto P_0c0a486a;
P_0c0a486a: /* original 432b, guest PC 0x0c0a486a */
if(!s->budget--) { s->failed_pc=0x0c0a486au; return 0; }
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
P_0c0a486c: /* original 4f26, guest PC 0x0c0a486c */
if(!s->budget--) { s->failed_pc=0x0c0a486cu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
return vf3_matrix_family(0x0c0a486eu,s,ram);
P_0c0a4948: /* original 4f22, guest PC 0x0c0a4948 */
if(!s->budget--) { s->failed_pc=0x0c0a4948u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0a494a;
P_0c0a494a: /* original d35a, guest PC 0x0c0a494a */
if(!s->budget--) { s->failed_pc=0x0c0a494au; return 0; }
r[3]=read(ram,0x0c0a4ab4u,4);
goto P_0c0a494c;
P_0c0a494c: /* original 949e, guest PC 0x0c0a494c */
if(!s->budget--) { s->failed_pc=0x0c0a494cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a4a8cu,2);
goto P_0c0a494e;
P_0c0a494e: /* original 430b, guest PC 0x0c0a494e */
if(!s->budget--) { s->failed_pc=0x0c0a494eu; return 0; }
target=r[3];
r[16]=0x0c0a4952u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a4952u) { target=s->pc; goto dispatch; }
goto P_0c0a4952;
P_0c0a4950: /* original 0009, guest PC 0x0c0a4950 */
if(!s->budget--) { s->failed_pc=0x0c0a4950u; return 0; }
goto P_0c0a4952;
P_0c0a4952: /* original d258, guest PC 0x0c0a4952 */
if(!s->budget--) { s->failed_pc=0x0c0a4952u; return 0; }
r[2]=read(ram,0x0c0a4ab4u,4);
goto P_0c0a4954;
P_0c0a4954: /* original 949b, guest PC 0x0c0a4954 */
if(!s->budget--) { s->failed_pc=0x0c0a4954u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a4a8eu,2);
goto P_0c0a4956;
P_0c0a4956: /* original 420b, guest PC 0x0c0a4956 */
if(!s->budget--) { s->failed_pc=0x0c0a4956u; return 0; }
target=r[2];
r[16]=0x0c0a495au;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a495au) { target=s->pc; goto dispatch; }
goto P_0c0a495a;
P_0c0a4958: /* original 0009, guest PC 0x0c0a4958 */
if(!s->budget--) { s->failed_pc=0x0c0a4958u; return 0; }
goto P_0c0a495a;
P_0c0a495a: /* original d356, guest PC 0x0c0a495a */
if(!s->budget--) { s->failed_pc=0x0c0a495au; return 0; }
r[3]=read(ram,0x0c0a4ab4u,4);
goto P_0c0a495c;
P_0c0a495c: /* original 9498, guest PC 0x0c0a495c */
if(!s->budget--) { s->failed_pc=0x0c0a495cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a4a90u,2);
goto P_0c0a495e;
P_0c0a495e: /* original 430b, guest PC 0x0c0a495e */
if(!s->budget--) { s->failed_pc=0x0c0a495eu; return 0; }
target=r[3];
r[16]=0x0c0a4962u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a4962u) { target=s->pc; goto dispatch; }
goto P_0c0a4962;
P_0c0a4960: /* original 0009, guest PC 0x0c0a4960 */
if(!s->budget--) { s->failed_pc=0x0c0a4960u; return 0; }
goto P_0c0a4962;
P_0c0a4962: /* original d254, guest PC 0x0c0a4962 */
if(!s->budget--) { s->failed_pc=0x0c0a4962u; return 0; }
r[2]=read(ram,0x0c0a4ab4u,4);
goto P_0c0a4964;
P_0c0a4964: /* original 9495, guest PC 0x0c0a4964 */
if(!s->budget--) { s->failed_pc=0x0c0a4964u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a4a92u,2);
goto P_0c0a4966;
P_0c0a4966: /* original 420b, guest PC 0x0c0a4966 */
if(!s->budget--) { s->failed_pc=0x0c0a4966u; return 0; }
target=r[2];
r[16]=0x0c0a496au;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a496au) { target=s->pc; goto dispatch; }
goto P_0c0a496a;
P_0c0a4968: /* original 0009, guest PC 0x0c0a4968 */
if(!s->budget--) { s->failed_pc=0x0c0a4968u; return 0; }
goto P_0c0a496a;
P_0c0a496a: /* original d352, guest PC 0x0c0a496a */
if(!s->budget--) { s->failed_pc=0x0c0a496au; return 0; }
r[3]=read(ram,0x0c0a4ab4u,4);
goto P_0c0a496c;
P_0c0a496c: /* original 9492, guest PC 0x0c0a496c */
if(!s->budget--) { s->failed_pc=0x0c0a496cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a4a94u,2);
goto P_0c0a496e;
P_0c0a496e: /* original 430b, guest PC 0x0c0a496e */
if(!s->budget--) { s->failed_pc=0x0c0a496eu; return 0; }
target=r[3];
r[16]=0x0c0a4972u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a4972u) { target=s->pc; goto dispatch; }
goto P_0c0a4972;
P_0c0a4970: /* original 0009, guest PC 0x0c0a4970 */
if(!s->budget--) { s->failed_pc=0x0c0a4970u; return 0; }
goto P_0c0a4972;
P_0c0a4972: /* original d250, guest PC 0x0c0a4972 */
if(!s->budget--) { s->failed_pc=0x0c0a4972u; return 0; }
r[2]=read(ram,0x0c0a4ab4u,4);
goto P_0c0a4974;
P_0c0a4974: /* original 948f, guest PC 0x0c0a4974 */
if(!s->budget--) { s->failed_pc=0x0c0a4974u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a4a96u,2);
goto P_0c0a4976;
P_0c0a4976: /* original 420b, guest PC 0x0c0a4976 */
if(!s->budget--) { s->failed_pc=0x0c0a4976u; return 0; }
target=r[2];
r[16]=0x0c0a497au;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a497au) { target=s->pc; goto dispatch; }
goto P_0c0a497a;
P_0c0a4978: /* original 0009, guest PC 0x0c0a4978 */
if(!s->budget--) { s->failed_pc=0x0c0a4978u; return 0; }
goto P_0c0a497a;
P_0c0a497a: /* original d34e, guest PC 0x0c0a497a */
if(!s->budget--) { s->failed_pc=0x0c0a497au; return 0; }
r[3]=read(ram,0x0c0a4ab4u,4);
goto P_0c0a497c;
P_0c0a497c: /* original 948c, guest PC 0x0c0a497c */
if(!s->budget--) { s->failed_pc=0x0c0a497cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a4a98u,2);
goto P_0c0a497e;
P_0c0a497e: /* original 430b, guest PC 0x0c0a497e */
if(!s->budget--) { s->failed_pc=0x0c0a497eu; return 0; }
target=r[3];
r[16]=0x0c0a4982u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a4982u) { target=s->pc; goto dispatch; }
goto P_0c0a4982;
P_0c0a4980: /* original 0009, guest PC 0x0c0a4980 */
if(!s->budget--) { s->failed_pc=0x0c0a4980u; return 0; }
goto P_0c0a4982;
P_0c0a4982: /* original d24c, guest PC 0x0c0a4982 */
if(!s->budget--) { s->failed_pc=0x0c0a4982u; return 0; }
r[2]=read(ram,0x0c0a4ab4u,4);
goto P_0c0a4984;
P_0c0a4984: /* original 9489, guest PC 0x0c0a4984 */
if(!s->budget--) { s->failed_pc=0x0c0a4984u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a4a9au,2);
goto P_0c0a4986;
P_0c0a4986: /* original 420b, guest PC 0x0c0a4986 */
if(!s->budget--) { s->failed_pc=0x0c0a4986u; return 0; }
target=r[2];
r[16]=0x0c0a498au;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a498au) { target=s->pc; goto dispatch; }
goto P_0c0a498a;
P_0c0a4988: /* original 0009, guest PC 0x0c0a4988 */
if(!s->budget--) { s->failed_pc=0x0c0a4988u; return 0; }
goto P_0c0a498a;
P_0c0a498a: /* original d34a, guest PC 0x0c0a498a */
if(!s->budget--) { s->failed_pc=0x0c0a498au; return 0; }
r[3]=read(ram,0x0c0a4ab4u,4);
goto P_0c0a498c;
P_0c0a498c: /* original 9486, guest PC 0x0c0a498c */
if(!s->budget--) { s->failed_pc=0x0c0a498cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a4a9cu,2);
goto P_0c0a498e;
P_0c0a498e: /* original 430b, guest PC 0x0c0a498e */
if(!s->budget--) { s->failed_pc=0x0c0a498eu; return 0; }
target=r[3];
r[16]=0x0c0a4992u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a4992u) { target=s->pc; goto dispatch; }
goto P_0c0a4992;
P_0c0a4990: /* original 0009, guest PC 0x0c0a4990 */
if(!s->budget--) { s->failed_pc=0x0c0a4990u; return 0; }
goto P_0c0a4992;
P_0c0a4992: /* original d248, guest PC 0x0c0a4992 */
if(!s->budget--) { s->failed_pc=0x0c0a4992u; return 0; }
r[2]=read(ram,0x0c0a4ab4u,4);
goto P_0c0a4994;
P_0c0a4994: /* original 9483, guest PC 0x0c0a4994 */
if(!s->budget--) { s->failed_pc=0x0c0a4994u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a4a9eu,2);
goto P_0c0a4996;
P_0c0a4996: /* original 420b, guest PC 0x0c0a4996 */
if(!s->budget--) { s->failed_pc=0x0c0a4996u; return 0; }
target=r[2];
r[16]=0x0c0a499au;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a499au) { target=s->pc; goto dispatch; }
goto P_0c0a499a;
P_0c0a4998: /* original 0009, guest PC 0x0c0a4998 */
if(!s->budget--) { s->failed_pc=0x0c0a4998u; return 0; }
goto P_0c0a499a;
P_0c0a499a: /* original d346, guest PC 0x0c0a499a */
if(!s->budget--) { s->failed_pc=0x0c0a499au; return 0; }
r[3]=read(ram,0x0c0a4ab4u,4);
goto P_0c0a499c;
P_0c0a499c: /* original 9480, guest PC 0x0c0a499c */
if(!s->budget--) { s->failed_pc=0x0c0a499cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a4aa0u,2);
goto P_0c0a499e;
P_0c0a499e: /* original 430b, guest PC 0x0c0a499e */
if(!s->budget--) { s->failed_pc=0x0c0a499eu; return 0; }
target=r[3];
r[16]=0x0c0a49a2u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a49a2u) { target=s->pc; goto dispatch; }
goto P_0c0a49a2;
P_0c0a49a0: /* original 0009, guest PC 0x0c0a49a0 */
if(!s->budget--) { s->failed_pc=0x0c0a49a0u; return 0; }
goto P_0c0a49a2;
P_0c0a49a2: /* original d244, guest PC 0x0c0a49a2 */
if(!s->budget--) { s->failed_pc=0x0c0a49a2u; return 0; }
r[2]=read(ram,0x0c0a4ab4u,4);
goto P_0c0a49a4;
P_0c0a49a4: /* original 947d, guest PC 0x0c0a49a4 */
if(!s->budget--) { s->failed_pc=0x0c0a49a4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a4aa2u,2);
goto P_0c0a49a6;
P_0c0a49a6: /* original 420b, guest PC 0x0c0a49a6 */
if(!s->budget--) { s->failed_pc=0x0c0a49a6u; return 0; }
target=r[2];
r[16]=0x0c0a49aau;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a49aau) { target=s->pc; goto dispatch; }
goto P_0c0a49aa;
P_0c0a49a8: /* original 0009, guest PC 0x0c0a49a8 */
if(!s->budget--) { s->failed_pc=0x0c0a49a8u; return 0; }
goto P_0c0a49aa;
P_0c0a49aa: /* original d342, guest PC 0x0c0a49aa */
if(!s->budget--) { s->failed_pc=0x0c0a49aau; return 0; }
r[3]=read(ram,0x0c0a4ab4u,4);
goto P_0c0a49ac;
P_0c0a49ac: /* original 947a, guest PC 0x0c0a49ac */
if(!s->budget--) { s->failed_pc=0x0c0a49acu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a4aa4u,2);
goto P_0c0a49ae;
P_0c0a49ae: /* original 430b, guest PC 0x0c0a49ae */
if(!s->budget--) { s->failed_pc=0x0c0a49aeu; return 0; }
target=r[3];
r[16]=0x0c0a49b2u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a49b2u) { target=s->pc; goto dispatch; }
goto P_0c0a49b2;
P_0c0a49b0: /* original 0009, guest PC 0x0c0a49b0 */
if(!s->budget--) { s->failed_pc=0x0c0a49b0u; return 0; }
goto P_0c0a49b2;
P_0c0a49b2: /* original d240, guest PC 0x0c0a49b2 */
if(!s->budget--) { s->failed_pc=0x0c0a49b2u; return 0; }
r[2]=read(ram,0x0c0a4ab4u,4);
goto P_0c0a49b4;
P_0c0a49b4: /* original 9477, guest PC 0x0c0a49b4 */
if(!s->budget--) { s->failed_pc=0x0c0a49b4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a4aa6u,2);
goto P_0c0a49b6;
P_0c0a49b6: /* original 420b, guest PC 0x0c0a49b6 */
if(!s->budget--) { s->failed_pc=0x0c0a49b6u; return 0; }
target=r[2];
r[16]=0x0c0a49bau;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a49bau) { target=s->pc; goto dispatch; }
goto P_0c0a49ba;
P_0c0a49b8: /* original 0009, guest PC 0x0c0a49b8 */
if(!s->budget--) { s->failed_pc=0x0c0a49b8u; return 0; }
goto P_0c0a49ba;
P_0c0a49ba: /* original d33e, guest PC 0x0c0a49ba */
if(!s->budget--) { s->failed_pc=0x0c0a49bau; return 0; }
r[3]=read(ram,0x0c0a4ab4u,4);
goto P_0c0a49bc;
P_0c0a49bc: /* original 9474, guest PC 0x0c0a49bc */
if(!s->budget--) { s->failed_pc=0x0c0a49bcu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a4aa8u,2);
goto P_0c0a49be;
P_0c0a49be: /* original 430b, guest PC 0x0c0a49be */
if(!s->budget--) { s->failed_pc=0x0c0a49beu; return 0; }
target=r[3];
r[16]=0x0c0a49c2u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a49c2u) { target=s->pc; goto dispatch; }
goto P_0c0a49c2;
P_0c0a49c0: /* original 0009, guest PC 0x0c0a49c0 */
if(!s->budget--) { s->failed_pc=0x0c0a49c0u; return 0; }
goto P_0c0a49c2;
P_0c0a49c2: /* original d23c, guest PC 0x0c0a49c2 */
if(!s->budget--) { s->failed_pc=0x0c0a49c2u; return 0; }
r[2]=read(ram,0x0c0a4ab4u,4);
goto P_0c0a49c4;
P_0c0a49c4: /* original 9471, guest PC 0x0c0a49c4 */
if(!s->budget--) { s->failed_pc=0x0c0a49c4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a4aaau,2);
goto P_0c0a49c6;
P_0c0a49c6: /* original 420b, guest PC 0x0c0a49c6 */
if(!s->budget--) { s->failed_pc=0x0c0a49c6u; return 0; }
target=r[2];
r[16]=0x0c0a49cau;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a49cau) { target=s->pc; goto dispatch; }
goto P_0c0a49ca;
P_0c0a49c8: /* original 0009, guest PC 0x0c0a49c8 */
if(!s->budget--) { s->failed_pc=0x0c0a49c8u; return 0; }
goto P_0c0a49ca;
P_0c0a49ca: /* original d33a, guest PC 0x0c0a49ca */
if(!s->budget--) { s->failed_pc=0x0c0a49cau; return 0; }
r[3]=read(ram,0x0c0a4ab4u,4);
goto P_0c0a49cc;
P_0c0a49cc: /* original 946e, guest PC 0x0c0a49cc */
if(!s->budget--) { s->failed_pc=0x0c0a49ccu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a4aacu,2);
goto P_0c0a49ce;
P_0c0a49ce: /* original 430b, guest PC 0x0c0a49ce */
if(!s->budget--) { s->failed_pc=0x0c0a49ceu; return 0; }
target=r[3];
r[16]=0x0c0a49d2u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a49d2u) { target=s->pc; goto dispatch; }
goto P_0c0a49d2;
P_0c0a49d0: /* original 0009, guest PC 0x0c0a49d0 */
if(!s->budget--) { s->failed_pc=0x0c0a49d0u; return 0; }
goto P_0c0a49d2;
P_0c0a49d2: /* original d238, guest PC 0x0c0a49d2 */
if(!s->budget--) { s->failed_pc=0x0c0a49d2u; return 0; }
r[2]=read(ram,0x0c0a4ab4u,4);
goto P_0c0a49d4;
P_0c0a49d4: /* original 946b, guest PC 0x0c0a49d4 */
if(!s->budget--) { s->failed_pc=0x0c0a49d4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a4aaeu,2);
goto P_0c0a49d6;
P_0c0a49d6: /* original 420b, guest PC 0x0c0a49d6 */
if(!s->budget--) { s->failed_pc=0x0c0a49d6u; return 0; }
target=r[2];
r[16]=0x0c0a49dau;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a49dau) { target=s->pc; goto dispatch; }
goto P_0c0a49da;
P_0c0a49d8: /* original 0009, guest PC 0x0c0a49d8 */
if(!s->budget--) { s->failed_pc=0x0c0a49d8u; return 0; }
goto P_0c0a49da;
P_0c0a49da: /* original d336, guest PC 0x0c0a49da */
if(!s->budget--) { s->failed_pc=0x0c0a49dau; return 0; }
r[3]=read(ram,0x0c0a4ab4u,4);
goto P_0c0a49dc;
P_0c0a49dc: /* original 9468, guest PC 0x0c0a49dc */
if(!s->budget--) { s->failed_pc=0x0c0a49dcu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a4ab0u,2);
goto P_0c0a49de;
P_0c0a49de: /* original 432b, guest PC 0x0c0a49de */
if(!s->budget--) { s->failed_pc=0x0c0a49deu; return 0; }
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
P_0c0a49e0: /* original 4f26, guest PC 0x0c0a49e0 */
if(!s->budget--) { s->failed_pc=0x0c0a49e0u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
return vf3_matrix_family(0x0c0a49e2u,s,ram);
P_0c0a4abc: /* original 4f22, guest PC 0x0c0a4abc */
if(!s->budget--) { s->failed_pc=0x0c0a4abcu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0a4abe;
P_0c0a4abe: /* original d35f, guest PC 0x0c0a4abe */
if(!s->budget--) { s->failed_pc=0x0c0a4abeu; return 0; }
r[3]=read(ram,0x0c0a4c3cu,4);
goto P_0c0a4ac0;
P_0c0a4ac0: /* original 94a7, guest PC 0x0c0a4ac0 */
if(!s->budget--) { s->failed_pc=0x0c0a4ac0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a4c12u,2);
goto P_0c0a4ac2;
P_0c0a4ac2: /* original 430b, guest PC 0x0c0a4ac2 */
if(!s->budget--) { s->failed_pc=0x0c0a4ac2u; return 0; }
target=r[3];
r[16]=0x0c0a4ac6u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a4ac6u) { target=s->pc; goto dispatch; }
goto P_0c0a4ac6;
P_0c0a4ac4: /* original 0009, guest PC 0x0c0a4ac4 */
if(!s->budget--) { s->failed_pc=0x0c0a4ac4u; return 0; }
goto P_0c0a4ac6;
P_0c0a4ac6: /* original d25d, guest PC 0x0c0a4ac6 */
if(!s->budget--) { s->failed_pc=0x0c0a4ac6u; return 0; }
r[2]=read(ram,0x0c0a4c3cu,4);
goto P_0c0a4ac8;
P_0c0a4ac8: /* original 94a4, guest PC 0x0c0a4ac8 */
if(!s->budget--) { s->failed_pc=0x0c0a4ac8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a4c14u,2);
goto P_0c0a4aca;
P_0c0a4aca: /* original 420b, guest PC 0x0c0a4aca */
if(!s->budget--) { s->failed_pc=0x0c0a4acau; return 0; }
target=r[2];
r[16]=0x0c0a4aceu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a4aceu) { target=s->pc; goto dispatch; }
goto P_0c0a4ace;
P_0c0a4acc: /* original 0009, guest PC 0x0c0a4acc */
if(!s->budget--) { s->failed_pc=0x0c0a4accu; return 0; }
goto P_0c0a4ace;
P_0c0a4ace: /* original d35b, guest PC 0x0c0a4ace */
if(!s->budget--) { s->failed_pc=0x0c0a4aceu; return 0; }
r[3]=read(ram,0x0c0a4c3cu,4);
goto P_0c0a4ad0;
P_0c0a4ad0: /* original 94a1, guest PC 0x0c0a4ad0 */
if(!s->budget--) { s->failed_pc=0x0c0a4ad0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a4c16u,2);
goto P_0c0a4ad2;
P_0c0a4ad2: /* original 430b, guest PC 0x0c0a4ad2 */
if(!s->budget--) { s->failed_pc=0x0c0a4ad2u; return 0; }
target=r[3];
r[16]=0x0c0a4ad6u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a4ad6u) { target=s->pc; goto dispatch; }
goto P_0c0a4ad6;
P_0c0a4ad4: /* original 0009, guest PC 0x0c0a4ad4 */
if(!s->budget--) { s->failed_pc=0x0c0a4ad4u; return 0; }
goto P_0c0a4ad6;
P_0c0a4ad6: /* original d259, guest PC 0x0c0a4ad6 */
if(!s->budget--) { s->failed_pc=0x0c0a4ad6u; return 0; }
r[2]=read(ram,0x0c0a4c3cu,4);
goto P_0c0a4ad8;
P_0c0a4ad8: /* original 949e, guest PC 0x0c0a4ad8 */
if(!s->budget--) { s->failed_pc=0x0c0a4ad8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a4c18u,2);
goto P_0c0a4ada;
P_0c0a4ada: /* original 420b, guest PC 0x0c0a4ada */
if(!s->budget--) { s->failed_pc=0x0c0a4adau; return 0; }
target=r[2];
r[16]=0x0c0a4adeu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a4adeu) { target=s->pc; goto dispatch; }
goto P_0c0a4ade;
P_0c0a4adc: /* original 0009, guest PC 0x0c0a4adc */
if(!s->budget--) { s->failed_pc=0x0c0a4adcu; return 0; }
goto P_0c0a4ade;
P_0c0a4ade: /* original d357, guest PC 0x0c0a4ade */
if(!s->budget--) { s->failed_pc=0x0c0a4adeu; return 0; }
r[3]=read(ram,0x0c0a4c3cu,4);
goto P_0c0a4ae0;
P_0c0a4ae0: /* original 949b, guest PC 0x0c0a4ae0 */
if(!s->budget--) { s->failed_pc=0x0c0a4ae0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a4c1au,2);
goto P_0c0a4ae2;
P_0c0a4ae2: /* original 430b, guest PC 0x0c0a4ae2 */
if(!s->budget--) { s->failed_pc=0x0c0a4ae2u; return 0; }
target=r[3];
r[16]=0x0c0a4ae6u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a4ae6u) { target=s->pc; goto dispatch; }
goto P_0c0a4ae6;
P_0c0a4ae4: /* original 0009, guest PC 0x0c0a4ae4 */
if(!s->budget--) { s->failed_pc=0x0c0a4ae4u; return 0; }
goto P_0c0a4ae6;
P_0c0a4ae6: /* original d255, guest PC 0x0c0a4ae6 */
if(!s->budget--) { s->failed_pc=0x0c0a4ae6u; return 0; }
r[2]=read(ram,0x0c0a4c3cu,4);
goto P_0c0a4ae8;
P_0c0a4ae8: /* original 9498, guest PC 0x0c0a4ae8 */
if(!s->budget--) { s->failed_pc=0x0c0a4ae8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a4c1cu,2);
goto P_0c0a4aea;
P_0c0a4aea: /* original 420b, guest PC 0x0c0a4aea */
if(!s->budget--) { s->failed_pc=0x0c0a4aeau; return 0; }
target=r[2];
r[16]=0x0c0a4aeeu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a4aeeu) { target=s->pc; goto dispatch; }
goto P_0c0a4aee;
P_0c0a4aec: /* original 0009, guest PC 0x0c0a4aec */
if(!s->budget--) { s->failed_pc=0x0c0a4aecu; return 0; }
goto P_0c0a4aee;
P_0c0a4aee: /* original d353, guest PC 0x0c0a4aee */
if(!s->budget--) { s->failed_pc=0x0c0a4aeeu; return 0; }
r[3]=read(ram,0x0c0a4c3cu,4);
goto P_0c0a4af0;
P_0c0a4af0: /* original 9495, guest PC 0x0c0a4af0 */
if(!s->budget--) { s->failed_pc=0x0c0a4af0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a4c1eu,2);
goto P_0c0a4af2;
P_0c0a4af2: /* original 430b, guest PC 0x0c0a4af2 */
if(!s->budget--) { s->failed_pc=0x0c0a4af2u; return 0; }
target=r[3];
r[16]=0x0c0a4af6u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a4af6u) { target=s->pc; goto dispatch; }
goto P_0c0a4af6;
P_0c0a4af4: /* original 0009, guest PC 0x0c0a4af4 */
if(!s->budget--) { s->failed_pc=0x0c0a4af4u; return 0; }
goto P_0c0a4af6;
P_0c0a4af6: /* original d251, guest PC 0x0c0a4af6 */
if(!s->budget--) { s->failed_pc=0x0c0a4af6u; return 0; }
r[2]=read(ram,0x0c0a4c3cu,4);
goto P_0c0a4af8;
P_0c0a4af8: /* original 9492, guest PC 0x0c0a4af8 */
if(!s->budget--) { s->failed_pc=0x0c0a4af8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a4c20u,2);
goto P_0c0a4afa;
P_0c0a4afa: /* original 420b, guest PC 0x0c0a4afa */
if(!s->budget--) { s->failed_pc=0x0c0a4afau; return 0; }
target=r[2];
r[16]=0x0c0a4afeu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a4afeu) { target=s->pc; goto dispatch; }
goto P_0c0a4afe;
P_0c0a4afc: /* original 0009, guest PC 0x0c0a4afc */
if(!s->budget--) { s->failed_pc=0x0c0a4afcu; return 0; }
goto P_0c0a4afe;
P_0c0a4afe: /* original d34f, guest PC 0x0c0a4afe */
if(!s->budget--) { s->failed_pc=0x0c0a4afeu; return 0; }
r[3]=read(ram,0x0c0a4c3cu,4);
goto P_0c0a4b00;
P_0c0a4b00: /* original 948f, guest PC 0x0c0a4b00 */
if(!s->budget--) { s->failed_pc=0x0c0a4b00u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a4c22u,2);
goto P_0c0a4b02;
P_0c0a4b02: /* original 430b, guest PC 0x0c0a4b02 */
if(!s->budget--) { s->failed_pc=0x0c0a4b02u; return 0; }
target=r[3];
r[16]=0x0c0a4b06u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a4b06u) { target=s->pc; goto dispatch; }
goto P_0c0a4b06;
P_0c0a4b04: /* original 0009, guest PC 0x0c0a4b04 */
if(!s->budget--) { s->failed_pc=0x0c0a4b04u; return 0; }
goto P_0c0a4b06;
P_0c0a4b06: /* original d24d, guest PC 0x0c0a4b06 */
if(!s->budget--) { s->failed_pc=0x0c0a4b06u; return 0; }
r[2]=read(ram,0x0c0a4c3cu,4);
goto P_0c0a4b08;
P_0c0a4b08: /* original 948c, guest PC 0x0c0a4b08 */
if(!s->budget--) { s->failed_pc=0x0c0a4b08u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a4c24u,2);
goto P_0c0a4b0a;
P_0c0a4b0a: /* original 420b, guest PC 0x0c0a4b0a */
if(!s->budget--) { s->failed_pc=0x0c0a4b0au; return 0; }
target=r[2];
r[16]=0x0c0a4b0eu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a4b0eu) { target=s->pc; goto dispatch; }
goto P_0c0a4b0e;
P_0c0a4b0c: /* original 0009, guest PC 0x0c0a4b0c */
if(!s->budget--) { s->failed_pc=0x0c0a4b0cu; return 0; }
goto P_0c0a4b0e;
P_0c0a4b0e: /* original d34b, guest PC 0x0c0a4b0e */
if(!s->budget--) { s->failed_pc=0x0c0a4b0eu; return 0; }
r[3]=read(ram,0x0c0a4c3cu,4);
goto P_0c0a4b10;
P_0c0a4b10: /* original 9489, guest PC 0x0c0a4b10 */
if(!s->budget--) { s->failed_pc=0x0c0a4b10u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a4c26u,2);
goto P_0c0a4b12;
P_0c0a4b12: /* original 430b, guest PC 0x0c0a4b12 */
if(!s->budget--) { s->failed_pc=0x0c0a4b12u; return 0; }
target=r[3];
r[16]=0x0c0a4b16u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a4b16u) { target=s->pc; goto dispatch; }
goto P_0c0a4b16;
P_0c0a4b14: /* original 0009, guest PC 0x0c0a4b14 */
if(!s->budget--) { s->failed_pc=0x0c0a4b14u; return 0; }
goto P_0c0a4b16;
P_0c0a4b16: /* original d249, guest PC 0x0c0a4b16 */
if(!s->budget--) { s->failed_pc=0x0c0a4b16u; return 0; }
r[2]=read(ram,0x0c0a4c3cu,4);
goto P_0c0a4b18;
P_0c0a4b18: /* original 9486, guest PC 0x0c0a4b18 */
if(!s->budget--) { s->failed_pc=0x0c0a4b18u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a4c28u,2);
goto P_0c0a4b1a;
P_0c0a4b1a: /* original 420b, guest PC 0x0c0a4b1a */
if(!s->budget--) { s->failed_pc=0x0c0a4b1au; return 0; }
target=r[2];
r[16]=0x0c0a4b1eu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a4b1eu) { target=s->pc; goto dispatch; }
goto P_0c0a4b1e;
P_0c0a4b1c: /* original 0009, guest PC 0x0c0a4b1c */
if(!s->budget--) { s->failed_pc=0x0c0a4b1cu; return 0; }
goto P_0c0a4b1e;
P_0c0a4b1e: /* original d347, guest PC 0x0c0a4b1e */
if(!s->budget--) { s->failed_pc=0x0c0a4b1eu; return 0; }
r[3]=read(ram,0x0c0a4c3cu,4);
goto P_0c0a4b20;
P_0c0a4b20: /* original 9483, guest PC 0x0c0a4b20 */
if(!s->budget--) { s->failed_pc=0x0c0a4b20u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a4c2au,2);
goto P_0c0a4b22;
P_0c0a4b22: /* original 430b, guest PC 0x0c0a4b22 */
if(!s->budget--) { s->failed_pc=0x0c0a4b22u; return 0; }
target=r[3];
r[16]=0x0c0a4b26u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a4b26u) { target=s->pc; goto dispatch; }
goto P_0c0a4b26;
P_0c0a4b24: /* original 0009, guest PC 0x0c0a4b24 */
if(!s->budget--) { s->failed_pc=0x0c0a4b24u; return 0; }
goto P_0c0a4b26;
P_0c0a4b26: /* original d245, guest PC 0x0c0a4b26 */
if(!s->budget--) { s->failed_pc=0x0c0a4b26u; return 0; }
r[2]=read(ram,0x0c0a4c3cu,4);
goto P_0c0a4b28;
P_0c0a4b28: /* original 9480, guest PC 0x0c0a4b28 */
if(!s->budget--) { s->failed_pc=0x0c0a4b28u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a4c2cu,2);
goto P_0c0a4b2a;
P_0c0a4b2a: /* original 420b, guest PC 0x0c0a4b2a */
if(!s->budget--) { s->failed_pc=0x0c0a4b2au; return 0; }
target=r[2];
r[16]=0x0c0a4b2eu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a4b2eu) { target=s->pc; goto dispatch; }
goto P_0c0a4b2e;
P_0c0a4b2c: /* original 0009, guest PC 0x0c0a4b2c */
if(!s->budget--) { s->failed_pc=0x0c0a4b2cu; return 0; }
goto P_0c0a4b2e;
P_0c0a4b2e: /* original d343, guest PC 0x0c0a4b2e */
if(!s->budget--) { s->failed_pc=0x0c0a4b2eu; return 0; }
r[3]=read(ram,0x0c0a4c3cu,4);
goto P_0c0a4b30;
P_0c0a4b30: /* original 947d, guest PC 0x0c0a4b30 */
if(!s->budget--) { s->failed_pc=0x0c0a4b30u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a4c2eu,2);
goto P_0c0a4b32;
P_0c0a4b32: /* original 430b, guest PC 0x0c0a4b32 */
if(!s->budget--) { s->failed_pc=0x0c0a4b32u; return 0; }
target=r[3];
r[16]=0x0c0a4b36u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a4b36u) { target=s->pc; goto dispatch; }
goto P_0c0a4b36;
P_0c0a4b34: /* original 0009, guest PC 0x0c0a4b34 */
if(!s->budget--) { s->failed_pc=0x0c0a4b34u; return 0; }
goto P_0c0a4b36;
P_0c0a4b36: /* original d241, guest PC 0x0c0a4b36 */
if(!s->budget--) { s->failed_pc=0x0c0a4b36u; return 0; }
r[2]=read(ram,0x0c0a4c3cu,4);
goto P_0c0a4b38;
P_0c0a4b38: /* original 947a, guest PC 0x0c0a4b38 */
if(!s->budget--) { s->failed_pc=0x0c0a4b38u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a4c30u,2);
goto P_0c0a4b3a;
P_0c0a4b3a: /* original 420b, guest PC 0x0c0a4b3a */
if(!s->budget--) { s->failed_pc=0x0c0a4b3au; return 0; }
target=r[2];
r[16]=0x0c0a4b3eu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a4b3eu) { target=s->pc; goto dispatch; }
goto P_0c0a4b3e;
P_0c0a4b3c: /* original 0009, guest PC 0x0c0a4b3c */
if(!s->budget--) { s->failed_pc=0x0c0a4b3cu; return 0; }
goto P_0c0a4b3e;
P_0c0a4b3e: /* original d33f, guest PC 0x0c0a4b3e */
if(!s->budget--) { s->failed_pc=0x0c0a4b3eu; return 0; }
r[3]=read(ram,0x0c0a4c3cu,4);
goto P_0c0a4b40;
P_0c0a4b40: /* original 9477, guest PC 0x0c0a4b40 */
if(!s->budget--) { s->failed_pc=0x0c0a4b40u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a4c32u,2);
goto P_0c0a4b42;
P_0c0a4b42: /* original 430b, guest PC 0x0c0a4b42 */
if(!s->budget--) { s->failed_pc=0x0c0a4b42u; return 0; }
target=r[3];
r[16]=0x0c0a4b46u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a4b46u) { target=s->pc; goto dispatch; }
goto P_0c0a4b46;
P_0c0a4b44: /* original 0009, guest PC 0x0c0a4b44 */
if(!s->budget--) { s->failed_pc=0x0c0a4b44u; return 0; }
goto P_0c0a4b46;
P_0c0a4b46: /* original d23d, guest PC 0x0c0a4b46 */
if(!s->budget--) { s->failed_pc=0x0c0a4b46u; return 0; }
r[2]=read(ram,0x0c0a4c3cu,4);
goto P_0c0a4b48;
P_0c0a4b48: /* original 9474, guest PC 0x0c0a4b48 */
if(!s->budget--) { s->failed_pc=0x0c0a4b48u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a4c34u,2);
goto P_0c0a4b4a;
P_0c0a4b4a: /* original 420b, guest PC 0x0c0a4b4a */
if(!s->budget--) { s->failed_pc=0x0c0a4b4au; return 0; }
target=r[2];
r[16]=0x0c0a4b4eu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a4b4eu) { target=s->pc; goto dispatch; }
goto P_0c0a4b4e;
P_0c0a4b4c: /* original 0009, guest PC 0x0c0a4b4c */
if(!s->budget--) { s->failed_pc=0x0c0a4b4cu; return 0; }
goto P_0c0a4b4e;
P_0c0a4b4e: /* original d33b, guest PC 0x0c0a4b4e */
if(!s->budget--) { s->failed_pc=0x0c0a4b4eu; return 0; }
r[3]=read(ram,0x0c0a4c3cu,4);
goto P_0c0a4b50;
P_0c0a4b50: /* original 9471, guest PC 0x0c0a4b50 */
if(!s->budget--) { s->failed_pc=0x0c0a4b50u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a4c36u,2);
goto P_0c0a4b52;
P_0c0a4b52: /* original 430b, guest PC 0x0c0a4b52 */
if(!s->budget--) { s->failed_pc=0x0c0a4b52u; return 0; }
target=r[3];
r[16]=0x0c0a4b56u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a4b56u) { target=s->pc; goto dispatch; }
goto P_0c0a4b56;
P_0c0a4b54: /* original 0009, guest PC 0x0c0a4b54 */
if(!s->budget--) { s->failed_pc=0x0c0a4b54u; return 0; }
goto P_0c0a4b56;
P_0c0a4b56: /* original d239, guest PC 0x0c0a4b56 */
if(!s->budget--) { s->failed_pc=0x0c0a4b56u; return 0; }
r[2]=read(ram,0x0c0a4c3cu,4);
goto P_0c0a4b58;
P_0c0a4b58: /* original 946e, guest PC 0x0c0a4b58 */
if(!s->budget--) { s->failed_pc=0x0c0a4b58u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a4c38u,2);
goto P_0c0a4b5a;
P_0c0a4b5a: /* original 422b, guest PC 0x0c0a4b5a */
if(!s->budget--) { s->failed_pc=0x0c0a4b5au; return 0; }
target=r[2];
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
P_0c0a4b5c: /* original 4f26, guest PC 0x0c0a4b5c */
if(!s->budget--) { s->failed_pc=0x0c0a4b5cu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
return vf3_matrix_family(0x0c0a4b5eu,s,ram);
P_0c0a4c44: /* original 4f22, guest PC 0x0c0a4c44 */
if(!s->budget--) { s->failed_pc=0x0c0a4c44u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0a4c46;
P_0c0a4c46: /* original d33c, guest PC 0x0c0a4c46 */
if(!s->budget--) { s->failed_pc=0x0c0a4c46u; return 0; }
r[3]=read(ram,0x0c0a4d38u,4);
goto P_0c0a4c48;
P_0c0a4c48: /* original 945d, guest PC 0x0c0a4c48 */
if(!s->budget--) { s->failed_pc=0x0c0a4c48u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a4d06u,2);
goto P_0c0a4c4a;
P_0c0a4c4a: /* original 430b, guest PC 0x0c0a4c4a */
if(!s->budget--) { s->failed_pc=0x0c0a4c4au; return 0; }
target=r[3];
r[16]=0x0c0a4c4eu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a4c4eu) { target=s->pc; goto dispatch; }
goto P_0c0a4c4e;
P_0c0a4c4c: /* original 0009, guest PC 0x0c0a4c4c */
if(!s->budget--) { s->failed_pc=0x0c0a4c4cu; return 0; }
goto P_0c0a4c4e;
P_0c0a4c4e: /* original d23a, guest PC 0x0c0a4c4e */
if(!s->budget--) { s->failed_pc=0x0c0a4c4eu; return 0; }
r[2]=read(ram,0x0c0a4d38u,4);
goto P_0c0a4c50;
P_0c0a4c50: /* original 945a, guest PC 0x0c0a4c50 */
if(!s->budget--) { s->failed_pc=0x0c0a4c50u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a4d08u,2);
goto P_0c0a4c52;
P_0c0a4c52: /* original 420b, guest PC 0x0c0a4c52 */
if(!s->budget--) { s->failed_pc=0x0c0a4c52u; return 0; }
target=r[2];
r[16]=0x0c0a4c56u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a4c56u) { target=s->pc; goto dispatch; }
goto P_0c0a4c56;
P_0c0a4c54: /* original 0009, guest PC 0x0c0a4c54 */
if(!s->budget--) { s->failed_pc=0x0c0a4c54u; return 0; }
goto P_0c0a4c56;
P_0c0a4c56: /* original d338, guest PC 0x0c0a4c56 */
if(!s->budget--) { s->failed_pc=0x0c0a4c56u; return 0; }
r[3]=read(ram,0x0c0a4d38u,4);
goto P_0c0a4c58;
P_0c0a4c58: /* original 9457, guest PC 0x0c0a4c58 */
if(!s->budget--) { s->failed_pc=0x0c0a4c58u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a4d0au,2);
goto P_0c0a4c5a;
P_0c0a4c5a: /* original 430b, guest PC 0x0c0a4c5a */
if(!s->budget--) { s->failed_pc=0x0c0a4c5au; return 0; }
target=r[3];
r[16]=0x0c0a4c5eu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a4c5eu) { target=s->pc; goto dispatch; }
goto P_0c0a4c5e;
P_0c0a4c5c: /* original 0009, guest PC 0x0c0a4c5c */
if(!s->budget--) { s->failed_pc=0x0c0a4c5cu; return 0; }
goto P_0c0a4c5e;
P_0c0a4c5e: /* original d236, guest PC 0x0c0a4c5e */
if(!s->budget--) { s->failed_pc=0x0c0a4c5eu; return 0; }
r[2]=read(ram,0x0c0a4d38u,4);
goto P_0c0a4c60;
P_0c0a4c60: /* original 9454, guest PC 0x0c0a4c60 */
if(!s->budget--) { s->failed_pc=0x0c0a4c60u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a4d0cu,2);
goto P_0c0a4c62;
P_0c0a4c62: /* original 420b, guest PC 0x0c0a4c62 */
if(!s->budget--) { s->failed_pc=0x0c0a4c62u; return 0; }
target=r[2];
r[16]=0x0c0a4c66u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a4c66u) { target=s->pc; goto dispatch; }
goto P_0c0a4c66;
P_0c0a4c64: /* original 0009, guest PC 0x0c0a4c64 */
if(!s->budget--) { s->failed_pc=0x0c0a4c64u; return 0; }
goto P_0c0a4c66;
P_0c0a4c66: /* original d334, guest PC 0x0c0a4c66 */
if(!s->budget--) { s->failed_pc=0x0c0a4c66u; return 0; }
r[3]=read(ram,0x0c0a4d38u,4);
goto P_0c0a4c68;
P_0c0a4c68: /* original 9451, guest PC 0x0c0a4c68 */
if(!s->budget--) { s->failed_pc=0x0c0a4c68u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a4d0eu,2);
goto P_0c0a4c6a;
P_0c0a4c6a: /* original 430b, guest PC 0x0c0a4c6a */
if(!s->budget--) { s->failed_pc=0x0c0a4c6au; return 0; }
target=r[3];
r[16]=0x0c0a4c6eu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a4c6eu) { target=s->pc; goto dispatch; }
goto P_0c0a4c6e;
P_0c0a4c6c: /* original 0009, guest PC 0x0c0a4c6c */
if(!s->budget--) { s->failed_pc=0x0c0a4c6cu; return 0; }
goto P_0c0a4c6e;
P_0c0a4c6e: /* original d232, guest PC 0x0c0a4c6e */
if(!s->budget--) { s->failed_pc=0x0c0a4c6eu; return 0; }
r[2]=read(ram,0x0c0a4d38u,4);
goto P_0c0a4c70;
P_0c0a4c70: /* original 944e, guest PC 0x0c0a4c70 */
if(!s->budget--) { s->failed_pc=0x0c0a4c70u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a4d10u,2);
goto P_0c0a4c72;
P_0c0a4c72: /* original 420b, guest PC 0x0c0a4c72 */
if(!s->budget--) { s->failed_pc=0x0c0a4c72u; return 0; }
target=r[2];
r[16]=0x0c0a4c76u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a4c76u) { target=s->pc; goto dispatch; }
goto P_0c0a4c76;
P_0c0a4c74: /* original 0009, guest PC 0x0c0a4c74 */
if(!s->budget--) { s->failed_pc=0x0c0a4c74u; return 0; }
goto P_0c0a4c76;
P_0c0a4c76: /* original d330, guest PC 0x0c0a4c76 */
if(!s->budget--) { s->failed_pc=0x0c0a4c76u; return 0; }
r[3]=read(ram,0x0c0a4d38u,4);
goto P_0c0a4c78;
P_0c0a4c78: /* original 944b, guest PC 0x0c0a4c78 */
if(!s->budget--) { s->failed_pc=0x0c0a4c78u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a4d12u,2);
goto P_0c0a4c7a;
P_0c0a4c7a: /* original 430b, guest PC 0x0c0a4c7a */
if(!s->budget--) { s->failed_pc=0x0c0a4c7au; return 0; }
target=r[3];
r[16]=0x0c0a4c7eu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a4c7eu) { target=s->pc; goto dispatch; }
goto P_0c0a4c7e;
P_0c0a4c7c: /* original 0009, guest PC 0x0c0a4c7c */
if(!s->budget--) { s->failed_pc=0x0c0a4c7cu; return 0; }
goto P_0c0a4c7e;
P_0c0a4c7e: /* original d22e, guest PC 0x0c0a4c7e */
if(!s->budget--) { s->failed_pc=0x0c0a4c7eu; return 0; }
r[2]=read(ram,0x0c0a4d38u,4);
goto P_0c0a4c80;
P_0c0a4c80: /* original 9448, guest PC 0x0c0a4c80 */
if(!s->budget--) { s->failed_pc=0x0c0a4c80u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a4d14u,2);
goto P_0c0a4c82;
P_0c0a4c82: /* original 420b, guest PC 0x0c0a4c82 */
if(!s->budget--) { s->failed_pc=0x0c0a4c82u; return 0; }
target=r[2];
r[16]=0x0c0a4c86u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a4c86u) { target=s->pc; goto dispatch; }
goto P_0c0a4c86;
P_0c0a4c84: /* original 0009, guest PC 0x0c0a4c84 */
if(!s->budget--) { s->failed_pc=0x0c0a4c84u; return 0; }
goto P_0c0a4c86;
P_0c0a4c86: /* original d32c, guest PC 0x0c0a4c86 */
if(!s->budget--) { s->failed_pc=0x0c0a4c86u; return 0; }
r[3]=read(ram,0x0c0a4d38u,4);
goto P_0c0a4c88;
P_0c0a4c88: /* original 9445, guest PC 0x0c0a4c88 */
if(!s->budget--) { s->failed_pc=0x0c0a4c88u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a4d16u,2);
goto P_0c0a4c8a;
P_0c0a4c8a: /* original 430b, guest PC 0x0c0a4c8a */
if(!s->budget--) { s->failed_pc=0x0c0a4c8au; return 0; }
target=r[3];
r[16]=0x0c0a4c8eu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a4c8eu) { target=s->pc; goto dispatch; }
goto P_0c0a4c8e;
P_0c0a4c8c: /* original 0009, guest PC 0x0c0a4c8c */
if(!s->budget--) { s->failed_pc=0x0c0a4c8cu; return 0; }
goto P_0c0a4c8e;
P_0c0a4c8e: /* original d22a, guest PC 0x0c0a4c8e */
if(!s->budget--) { s->failed_pc=0x0c0a4c8eu; return 0; }
r[2]=read(ram,0x0c0a4d38u,4);
goto P_0c0a4c90;
P_0c0a4c90: /* original 9442, guest PC 0x0c0a4c90 */
if(!s->budget--) { s->failed_pc=0x0c0a4c90u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a4d18u,2);
goto P_0c0a4c92;
P_0c0a4c92: /* original 420b, guest PC 0x0c0a4c92 */
if(!s->budget--) { s->failed_pc=0x0c0a4c92u; return 0; }
target=r[2];
r[16]=0x0c0a4c96u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a4c96u) { target=s->pc; goto dispatch; }
goto P_0c0a4c96;
P_0c0a4c94: /* original 0009, guest PC 0x0c0a4c94 */
if(!s->budget--) { s->failed_pc=0x0c0a4c94u; return 0; }
goto P_0c0a4c96;
P_0c0a4c96: /* original d328, guest PC 0x0c0a4c96 */
if(!s->budget--) { s->failed_pc=0x0c0a4c96u; return 0; }
r[3]=read(ram,0x0c0a4d38u,4);
goto P_0c0a4c98;
P_0c0a4c98: /* original 943f, guest PC 0x0c0a4c98 */
if(!s->budget--) { s->failed_pc=0x0c0a4c98u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a4d1au,2);
goto P_0c0a4c9a;
P_0c0a4c9a: /* original 430b, guest PC 0x0c0a4c9a */
if(!s->budget--) { s->failed_pc=0x0c0a4c9au; return 0; }
target=r[3];
r[16]=0x0c0a4c9eu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a4c9eu) { target=s->pc; goto dispatch; }
goto P_0c0a4c9e;
P_0c0a4c9c: /* original 0009, guest PC 0x0c0a4c9c */
if(!s->budget--) { s->failed_pc=0x0c0a4c9cu; return 0; }
goto P_0c0a4c9e;
P_0c0a4c9e: /* original d226, guest PC 0x0c0a4c9e */
if(!s->budget--) { s->failed_pc=0x0c0a4c9eu; return 0; }
r[2]=read(ram,0x0c0a4d38u,4);
goto P_0c0a4ca0;
P_0c0a4ca0: /* original 943c, guest PC 0x0c0a4ca0 */
if(!s->budget--) { s->failed_pc=0x0c0a4ca0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a4d1cu,2);
goto P_0c0a4ca2;
P_0c0a4ca2: /* original 420b, guest PC 0x0c0a4ca2 */
if(!s->budget--) { s->failed_pc=0x0c0a4ca2u; return 0; }
target=r[2];
r[16]=0x0c0a4ca6u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a4ca6u) { target=s->pc; goto dispatch; }
goto P_0c0a4ca6;
P_0c0a4ca4: /* original 0009, guest PC 0x0c0a4ca4 */
if(!s->budget--) { s->failed_pc=0x0c0a4ca4u; return 0; }
goto P_0c0a4ca6;
P_0c0a4ca6: /* original d324, guest PC 0x0c0a4ca6 */
if(!s->budget--) { s->failed_pc=0x0c0a4ca6u; return 0; }
r[3]=read(ram,0x0c0a4d38u,4);
goto P_0c0a4ca8;
P_0c0a4ca8: /* original 9439, guest PC 0x0c0a4ca8 */
if(!s->budget--) { s->failed_pc=0x0c0a4ca8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a4d1eu,2);
goto P_0c0a4caa;
P_0c0a4caa: /* original 430b, guest PC 0x0c0a4caa */
if(!s->budget--) { s->failed_pc=0x0c0a4caau; return 0; }
target=r[3];
r[16]=0x0c0a4caeu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a4caeu) { target=s->pc; goto dispatch; }
goto P_0c0a4cae;
P_0c0a4cac: /* original 0009, guest PC 0x0c0a4cac */
if(!s->budget--) { s->failed_pc=0x0c0a4cacu; return 0; }
goto P_0c0a4cae;
P_0c0a4cae: /* original d222, guest PC 0x0c0a4cae */
if(!s->budget--) { s->failed_pc=0x0c0a4caeu; return 0; }
r[2]=read(ram,0x0c0a4d38u,4);
goto P_0c0a4cb0;
P_0c0a4cb0: /* original 9436, guest PC 0x0c0a4cb0 */
if(!s->budget--) { s->failed_pc=0x0c0a4cb0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a4d20u,2);
goto P_0c0a4cb2;
P_0c0a4cb2: /* original 420b, guest PC 0x0c0a4cb2 */
if(!s->budget--) { s->failed_pc=0x0c0a4cb2u; return 0; }
target=r[2];
r[16]=0x0c0a4cb6u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a4cb6u) { target=s->pc; goto dispatch; }
goto P_0c0a4cb6;
P_0c0a4cb4: /* original 0009, guest PC 0x0c0a4cb4 */
if(!s->budget--) { s->failed_pc=0x0c0a4cb4u; return 0; }
goto P_0c0a4cb6;
P_0c0a4cb6: /* original d320, guest PC 0x0c0a4cb6 */
if(!s->budget--) { s->failed_pc=0x0c0a4cb6u; return 0; }
r[3]=read(ram,0x0c0a4d38u,4);
goto P_0c0a4cb8;
P_0c0a4cb8: /* original 9433, guest PC 0x0c0a4cb8 */
if(!s->budget--) { s->failed_pc=0x0c0a4cb8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a4d22u,2);
goto P_0c0a4cba;
P_0c0a4cba: /* original 430b, guest PC 0x0c0a4cba */
if(!s->budget--) { s->failed_pc=0x0c0a4cbau; return 0; }
target=r[3];
r[16]=0x0c0a4cbeu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a4cbeu) { target=s->pc; goto dispatch; }
goto P_0c0a4cbe;
P_0c0a4cbc: /* original 0009, guest PC 0x0c0a4cbc */
if(!s->budget--) { s->failed_pc=0x0c0a4cbcu; return 0; }
goto P_0c0a4cbe;
P_0c0a4cbe: /* original d21e, guest PC 0x0c0a4cbe */
if(!s->budget--) { s->failed_pc=0x0c0a4cbeu; return 0; }
r[2]=read(ram,0x0c0a4d38u,4);
goto P_0c0a4cc0;
P_0c0a4cc0: /* original 9430, guest PC 0x0c0a4cc0 */
if(!s->budget--) { s->failed_pc=0x0c0a4cc0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a4d24u,2);
goto P_0c0a4cc2;
P_0c0a4cc2: /* original 420b, guest PC 0x0c0a4cc2 */
if(!s->budget--) { s->failed_pc=0x0c0a4cc2u; return 0; }
target=r[2];
r[16]=0x0c0a4cc6u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a4cc6u) { target=s->pc; goto dispatch; }
goto P_0c0a4cc6;
P_0c0a4cc4: /* original 0009, guest PC 0x0c0a4cc4 */
if(!s->budget--) { s->failed_pc=0x0c0a4cc4u; return 0; }
goto P_0c0a4cc6;
P_0c0a4cc6: /* original d31c, guest PC 0x0c0a4cc6 */
if(!s->budget--) { s->failed_pc=0x0c0a4cc6u; return 0; }
r[3]=read(ram,0x0c0a4d38u,4);
goto P_0c0a4cc8;
P_0c0a4cc8: /* original 942d, guest PC 0x0c0a4cc8 */
if(!s->budget--) { s->failed_pc=0x0c0a4cc8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a4d26u,2);
goto P_0c0a4cca;
P_0c0a4cca: /* original 430b, guest PC 0x0c0a4cca */
if(!s->budget--) { s->failed_pc=0x0c0a4ccau; return 0; }
target=r[3];
r[16]=0x0c0a4cceu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a4cceu) { target=s->pc; goto dispatch; }
goto P_0c0a4cce;
P_0c0a4ccc: /* original 0009, guest PC 0x0c0a4ccc */
if(!s->budget--) { s->failed_pc=0x0c0a4cccu; return 0; }
goto P_0c0a4cce;
P_0c0a4cce: /* original d21a, guest PC 0x0c0a4cce */
if(!s->budget--) { s->failed_pc=0x0c0a4cceu; return 0; }
r[2]=read(ram,0x0c0a4d38u,4);
goto P_0c0a4cd0;
P_0c0a4cd0: /* original 942a, guest PC 0x0c0a4cd0 */
if(!s->budget--) { s->failed_pc=0x0c0a4cd0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a4d28u,2);
goto P_0c0a4cd2;
P_0c0a4cd2: /* original 420b, guest PC 0x0c0a4cd2 */
if(!s->budget--) { s->failed_pc=0x0c0a4cd2u; return 0; }
target=r[2];
r[16]=0x0c0a4cd6u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a4cd6u) { target=s->pc; goto dispatch; }
goto P_0c0a4cd6;
P_0c0a4cd4: /* original 0009, guest PC 0x0c0a4cd4 */
if(!s->budget--) { s->failed_pc=0x0c0a4cd4u; return 0; }
goto P_0c0a4cd6;
P_0c0a4cd6: /* original d318, guest PC 0x0c0a4cd6 */
if(!s->budget--) { s->failed_pc=0x0c0a4cd6u; return 0; }
r[3]=read(ram,0x0c0a4d38u,4);
goto P_0c0a4cd8;
P_0c0a4cd8: /* original 9427, guest PC 0x0c0a4cd8 */
if(!s->budget--) { s->failed_pc=0x0c0a4cd8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a4d2au,2);
goto P_0c0a4cda;
P_0c0a4cda: /* original 430b, guest PC 0x0c0a4cda */
if(!s->budget--) { s->failed_pc=0x0c0a4cdau; return 0; }
target=r[3];
r[16]=0x0c0a4cdeu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a4cdeu) { target=s->pc; goto dispatch; }
goto P_0c0a4cde;
P_0c0a4cdc: /* original 0009, guest PC 0x0c0a4cdc */
if(!s->budget--) { s->failed_pc=0x0c0a4cdcu; return 0; }
goto P_0c0a4cde;
P_0c0a4cde: /* original d216, guest PC 0x0c0a4cde */
if(!s->budget--) { s->failed_pc=0x0c0a4cdeu; return 0; }
r[2]=read(ram,0x0c0a4d38u,4);
goto P_0c0a4ce0;
P_0c0a4ce0: /* original 9424, guest PC 0x0c0a4ce0 */
if(!s->budget--) { s->failed_pc=0x0c0a4ce0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a4d2cu,2);
goto P_0c0a4ce2;
P_0c0a4ce2: /* original 420b, guest PC 0x0c0a4ce2 */
if(!s->budget--) { s->failed_pc=0x0c0a4ce2u; return 0; }
target=r[2];
r[16]=0x0c0a4ce6u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a4ce6u) { target=s->pc; goto dispatch; }
goto P_0c0a4ce6;
P_0c0a4ce4: /* original 0009, guest PC 0x0c0a4ce4 */
if(!s->budget--) { s->failed_pc=0x0c0a4ce4u; return 0; }
goto P_0c0a4ce6;
P_0c0a4ce6: /* original d314, guest PC 0x0c0a4ce6 */
if(!s->budget--) { s->failed_pc=0x0c0a4ce6u; return 0; }
r[3]=read(ram,0x0c0a4d38u,4);
goto P_0c0a4ce8;
P_0c0a4ce8: /* original 9421, guest PC 0x0c0a4ce8 */
if(!s->budget--) { s->failed_pc=0x0c0a4ce8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a4d2eu,2);
goto P_0c0a4cea;
P_0c0a4cea: /* original 430b, guest PC 0x0c0a4cea */
if(!s->budget--) { s->failed_pc=0x0c0a4ceau; return 0; }
target=r[3];
r[16]=0x0c0a4ceeu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a4ceeu) { target=s->pc; goto dispatch; }
goto P_0c0a4cee;
P_0c0a4cec: /* original 0009, guest PC 0x0c0a4cec */
if(!s->budget--) { s->failed_pc=0x0c0a4cecu; return 0; }
goto P_0c0a4cee;
P_0c0a4cee: /* original d212, guest PC 0x0c0a4cee */
if(!s->budget--) { s->failed_pc=0x0c0a4ceeu; return 0; }
r[2]=read(ram,0x0c0a4d38u,4);
goto P_0c0a4cf0;
P_0c0a4cf0: /* original 941e, guest PC 0x0c0a4cf0 */
if(!s->budget--) { s->failed_pc=0x0c0a4cf0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a4d30u,2);
goto P_0c0a4cf2;
P_0c0a4cf2: /* original 420b, guest PC 0x0c0a4cf2 */
if(!s->budget--) { s->failed_pc=0x0c0a4cf2u; return 0; }
target=r[2];
r[16]=0x0c0a4cf6u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a4cf6u) { target=s->pc; goto dispatch; }
goto P_0c0a4cf6;
P_0c0a4cf4: /* original 0009, guest PC 0x0c0a4cf4 */
if(!s->budget--) { s->failed_pc=0x0c0a4cf4u; return 0; }
goto P_0c0a4cf6;
P_0c0a4cf6: /* original d310, guest PC 0x0c0a4cf6 */
if(!s->budget--) { s->failed_pc=0x0c0a4cf6u; return 0; }
r[3]=read(ram,0x0c0a4d38u,4);
goto P_0c0a4cf8;
P_0c0a4cf8: /* original 941b, guest PC 0x0c0a4cf8 */
if(!s->budget--) { s->failed_pc=0x0c0a4cf8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a4d32u,2);
goto P_0c0a4cfa;
P_0c0a4cfa: /* original 430b, guest PC 0x0c0a4cfa */
if(!s->budget--) { s->failed_pc=0x0c0a4cfau; return 0; }
target=r[3];
r[16]=0x0c0a4cfeu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a4cfeu) { target=s->pc; goto dispatch; }
goto P_0c0a4cfe;
P_0c0a4cfc: /* original 0009, guest PC 0x0c0a4cfc */
if(!s->budget--) { s->failed_pc=0x0c0a4cfcu; return 0; }
goto P_0c0a4cfe;
P_0c0a4cfe: /* original d20e, guest PC 0x0c0a4cfe */
if(!s->budget--) { s->failed_pc=0x0c0a4cfeu; return 0; }
r[2]=read(ram,0x0c0a4d38u,4);
goto P_0c0a4d00;
P_0c0a4d00: /* original 9418, guest PC 0x0c0a4d00 */
if(!s->budget--) { s->failed_pc=0x0c0a4d00u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a4d34u,2);
goto P_0c0a4d02;
P_0c0a4d02: /* original 422b, guest PC 0x0c0a4d02 */
if(!s->budget--) { s->failed_pc=0x0c0a4d02u; return 0; }
target=r[2];
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
P_0c0a4d04: /* original 4f26, guest PC 0x0c0a4d04 */
if(!s->budget--) { s->failed_pc=0x0c0a4d04u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
return vf3_matrix_family(0x0c0a4d06u,s,ram);
P_0c0a4e18: /* original 4f22, guest PC 0x0c0a4e18 */
if(!s->budget--) { s->failed_pc=0x0c0a4e18u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0a4e1a;
P_0c0a4e1a: /* original d337, guest PC 0x0c0a4e1a */
if(!s->budget--) { s->failed_pc=0x0c0a4e1au; return 0; }
r[3]=read(ram,0x0c0a4ef8u,4);
goto P_0c0a4e1c;
P_0c0a4e1c: /* original 9459, guest PC 0x0c0a4e1c */
if(!s->budget--) { s->failed_pc=0x0c0a4e1cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a4ed2u,2);
goto P_0c0a4e1e;
P_0c0a4e1e: /* original 430b, guest PC 0x0c0a4e1e */
if(!s->budget--) { s->failed_pc=0x0c0a4e1eu; return 0; }
target=r[3];
r[16]=0x0c0a4e22u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a4e22u) { target=s->pc; goto dispatch; }
goto P_0c0a4e22;
P_0c0a4e20: /* original 0009, guest PC 0x0c0a4e20 */
if(!s->budget--) { s->failed_pc=0x0c0a4e20u; return 0; }
goto P_0c0a4e22;
P_0c0a4e22: /* original d235, guest PC 0x0c0a4e22 */
if(!s->budget--) { s->failed_pc=0x0c0a4e22u; return 0; }
r[2]=read(ram,0x0c0a4ef8u,4);
goto P_0c0a4e24;
P_0c0a4e24: /* original 9456, guest PC 0x0c0a4e24 */
if(!s->budget--) { s->failed_pc=0x0c0a4e24u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a4ed4u,2);
goto P_0c0a4e26;
P_0c0a4e26: /* original 420b, guest PC 0x0c0a4e26 */
if(!s->budget--) { s->failed_pc=0x0c0a4e26u; return 0; }
target=r[2];
r[16]=0x0c0a4e2au;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a4e2au) { target=s->pc; goto dispatch; }
goto P_0c0a4e2a;
P_0c0a4e28: /* original 0009, guest PC 0x0c0a4e28 */
if(!s->budget--) { s->failed_pc=0x0c0a4e28u; return 0; }
goto P_0c0a4e2a;
P_0c0a4e2a: /* original d333, guest PC 0x0c0a4e2a */
if(!s->budget--) { s->failed_pc=0x0c0a4e2au; return 0; }
r[3]=read(ram,0x0c0a4ef8u,4);
goto P_0c0a4e2c;
P_0c0a4e2c: /* original 9453, guest PC 0x0c0a4e2c */
if(!s->budget--) { s->failed_pc=0x0c0a4e2cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a4ed6u,2);
goto P_0c0a4e2e;
P_0c0a4e2e: /* original 430b, guest PC 0x0c0a4e2e */
if(!s->budget--) { s->failed_pc=0x0c0a4e2eu; return 0; }
target=r[3];
r[16]=0x0c0a4e32u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a4e32u) { target=s->pc; goto dispatch; }
goto P_0c0a4e32;
P_0c0a4e30: /* original 0009, guest PC 0x0c0a4e30 */
if(!s->budget--) { s->failed_pc=0x0c0a4e30u; return 0; }
goto P_0c0a4e32;
P_0c0a4e32: /* original d231, guest PC 0x0c0a4e32 */
if(!s->budget--) { s->failed_pc=0x0c0a4e32u; return 0; }
r[2]=read(ram,0x0c0a4ef8u,4);
goto P_0c0a4e34;
P_0c0a4e34: /* original 9450, guest PC 0x0c0a4e34 */
if(!s->budget--) { s->failed_pc=0x0c0a4e34u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a4ed8u,2);
goto P_0c0a4e36;
P_0c0a4e36: /* original 420b, guest PC 0x0c0a4e36 */
if(!s->budget--) { s->failed_pc=0x0c0a4e36u; return 0; }
target=r[2];
r[16]=0x0c0a4e3au;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a4e3au) { target=s->pc; goto dispatch; }
goto P_0c0a4e3a;
P_0c0a4e38: /* original 0009, guest PC 0x0c0a4e38 */
if(!s->budget--) { s->failed_pc=0x0c0a4e38u; return 0; }
goto P_0c0a4e3a;
P_0c0a4e3a: /* original d32f, guest PC 0x0c0a4e3a */
if(!s->budget--) { s->failed_pc=0x0c0a4e3au; return 0; }
r[3]=read(ram,0x0c0a4ef8u,4);
goto P_0c0a4e3c;
P_0c0a4e3c: /* original 944d, guest PC 0x0c0a4e3c */
if(!s->budget--) { s->failed_pc=0x0c0a4e3cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a4edau,2);
goto P_0c0a4e3e;
P_0c0a4e3e: /* original 430b, guest PC 0x0c0a4e3e */
if(!s->budget--) { s->failed_pc=0x0c0a4e3eu; return 0; }
target=r[3];
r[16]=0x0c0a4e42u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a4e42u) { target=s->pc; goto dispatch; }
goto P_0c0a4e42;
P_0c0a4e40: /* original 0009, guest PC 0x0c0a4e40 */
if(!s->budget--) { s->failed_pc=0x0c0a4e40u; return 0; }
goto P_0c0a4e42;
P_0c0a4e42: /* original d22d, guest PC 0x0c0a4e42 */
if(!s->budget--) { s->failed_pc=0x0c0a4e42u; return 0; }
r[2]=read(ram,0x0c0a4ef8u,4);
goto P_0c0a4e44;
P_0c0a4e44: /* original 944a, guest PC 0x0c0a4e44 */
if(!s->budget--) { s->failed_pc=0x0c0a4e44u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a4edcu,2);
goto P_0c0a4e46;
P_0c0a4e46: /* original 420b, guest PC 0x0c0a4e46 */
if(!s->budget--) { s->failed_pc=0x0c0a4e46u; return 0; }
target=r[2];
r[16]=0x0c0a4e4au;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a4e4au) { target=s->pc; goto dispatch; }
goto P_0c0a4e4a;
P_0c0a4e48: /* original 0009, guest PC 0x0c0a4e48 */
if(!s->budget--) { s->failed_pc=0x0c0a4e48u; return 0; }
goto P_0c0a4e4a;
P_0c0a4e4a: /* original d32b, guest PC 0x0c0a4e4a */
if(!s->budget--) { s->failed_pc=0x0c0a4e4au; return 0; }
r[3]=read(ram,0x0c0a4ef8u,4);
goto P_0c0a4e4c;
P_0c0a4e4c: /* original 9447, guest PC 0x0c0a4e4c */
if(!s->budget--) { s->failed_pc=0x0c0a4e4cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a4edeu,2);
goto P_0c0a4e4e;
P_0c0a4e4e: /* original 430b, guest PC 0x0c0a4e4e */
if(!s->budget--) { s->failed_pc=0x0c0a4e4eu; return 0; }
target=r[3];
r[16]=0x0c0a4e52u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a4e52u) { target=s->pc; goto dispatch; }
goto P_0c0a4e52;
P_0c0a4e50: /* original 0009, guest PC 0x0c0a4e50 */
if(!s->budget--) { s->failed_pc=0x0c0a4e50u; return 0; }
goto P_0c0a4e52;
P_0c0a4e52: /* original d229, guest PC 0x0c0a4e52 */
if(!s->budget--) { s->failed_pc=0x0c0a4e52u; return 0; }
r[2]=read(ram,0x0c0a4ef8u,4);
goto P_0c0a4e54;
P_0c0a4e54: /* original 9444, guest PC 0x0c0a4e54 */
if(!s->budget--) { s->failed_pc=0x0c0a4e54u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a4ee0u,2);
goto P_0c0a4e56;
P_0c0a4e56: /* original 420b, guest PC 0x0c0a4e56 */
if(!s->budget--) { s->failed_pc=0x0c0a4e56u; return 0; }
target=r[2];
r[16]=0x0c0a4e5au;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a4e5au) { target=s->pc; goto dispatch; }
goto P_0c0a4e5a;
P_0c0a4e58: /* original 0009, guest PC 0x0c0a4e58 */
if(!s->budget--) { s->failed_pc=0x0c0a4e58u; return 0; }
goto P_0c0a4e5a;
P_0c0a4e5a: /* original d327, guest PC 0x0c0a4e5a */
if(!s->budget--) { s->failed_pc=0x0c0a4e5au; return 0; }
r[3]=read(ram,0x0c0a4ef8u,4);
goto P_0c0a4e5c;
P_0c0a4e5c: /* original 9441, guest PC 0x0c0a4e5c */
if(!s->budget--) { s->failed_pc=0x0c0a4e5cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a4ee2u,2);
goto P_0c0a4e5e;
P_0c0a4e5e: /* original 430b, guest PC 0x0c0a4e5e */
if(!s->budget--) { s->failed_pc=0x0c0a4e5eu; return 0; }
target=r[3];
r[16]=0x0c0a4e62u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a4e62u) { target=s->pc; goto dispatch; }
goto P_0c0a4e62;
P_0c0a4e60: /* original 0009, guest PC 0x0c0a4e60 */
if(!s->budget--) { s->failed_pc=0x0c0a4e60u; return 0; }
goto P_0c0a4e62;
P_0c0a4e62: /* original d225, guest PC 0x0c0a4e62 */
if(!s->budget--) { s->failed_pc=0x0c0a4e62u; return 0; }
r[2]=read(ram,0x0c0a4ef8u,4);
goto P_0c0a4e64;
P_0c0a4e64: /* original 943e, guest PC 0x0c0a4e64 */
if(!s->budget--) { s->failed_pc=0x0c0a4e64u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a4ee4u,2);
goto P_0c0a4e66;
P_0c0a4e66: /* original 420b, guest PC 0x0c0a4e66 */
if(!s->budget--) { s->failed_pc=0x0c0a4e66u; return 0; }
target=r[2];
r[16]=0x0c0a4e6au;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a4e6au) { target=s->pc; goto dispatch; }
goto P_0c0a4e6a;
P_0c0a4e68: /* original 0009, guest PC 0x0c0a4e68 */
if(!s->budget--) { s->failed_pc=0x0c0a4e68u; return 0; }
goto P_0c0a4e6a;
P_0c0a4e6a: /* original d323, guest PC 0x0c0a4e6a */
if(!s->budget--) { s->failed_pc=0x0c0a4e6au; return 0; }
r[3]=read(ram,0x0c0a4ef8u,4);
goto P_0c0a4e6c;
P_0c0a4e6c: /* original 943b, guest PC 0x0c0a4e6c */
if(!s->budget--) { s->failed_pc=0x0c0a4e6cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a4ee6u,2);
goto P_0c0a4e6e;
P_0c0a4e6e: /* original 430b, guest PC 0x0c0a4e6e */
if(!s->budget--) { s->failed_pc=0x0c0a4e6eu; return 0; }
target=r[3];
r[16]=0x0c0a4e72u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a4e72u) { target=s->pc; goto dispatch; }
goto P_0c0a4e72;
P_0c0a4e70: /* original 0009, guest PC 0x0c0a4e70 */
if(!s->budget--) { s->failed_pc=0x0c0a4e70u; return 0; }
goto P_0c0a4e72;
P_0c0a4e72: /* original d221, guest PC 0x0c0a4e72 */
if(!s->budget--) { s->failed_pc=0x0c0a4e72u; return 0; }
r[2]=read(ram,0x0c0a4ef8u,4);
goto P_0c0a4e74;
P_0c0a4e74: /* original 9438, guest PC 0x0c0a4e74 */
if(!s->budget--) { s->failed_pc=0x0c0a4e74u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a4ee8u,2);
goto P_0c0a4e76;
P_0c0a4e76: /* original 420b, guest PC 0x0c0a4e76 */
if(!s->budget--) { s->failed_pc=0x0c0a4e76u; return 0; }
target=r[2];
r[16]=0x0c0a4e7au;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a4e7au) { target=s->pc; goto dispatch; }
goto P_0c0a4e7a;
P_0c0a4e78: /* original 0009, guest PC 0x0c0a4e78 */
if(!s->budget--) { s->failed_pc=0x0c0a4e78u; return 0; }
goto P_0c0a4e7a;
P_0c0a4e7a: /* original d31f, guest PC 0x0c0a4e7a */
if(!s->budget--) { s->failed_pc=0x0c0a4e7au; return 0; }
r[3]=read(ram,0x0c0a4ef8u,4);
goto P_0c0a4e7c;
P_0c0a4e7c: /* original 9435, guest PC 0x0c0a4e7c */
if(!s->budget--) { s->failed_pc=0x0c0a4e7cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a4eeau,2);
goto P_0c0a4e7e;
P_0c0a4e7e: /* original 430b, guest PC 0x0c0a4e7e */
if(!s->budget--) { s->failed_pc=0x0c0a4e7eu; return 0; }
target=r[3];
r[16]=0x0c0a4e82u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a4e82u) { target=s->pc; goto dispatch; }
goto P_0c0a4e82;
P_0c0a4e80: /* original 0009, guest PC 0x0c0a4e80 */
if(!s->budget--) { s->failed_pc=0x0c0a4e80u; return 0; }
goto P_0c0a4e82;
P_0c0a4e82: /* original d21d, guest PC 0x0c0a4e82 */
if(!s->budget--) { s->failed_pc=0x0c0a4e82u; return 0; }
r[2]=read(ram,0x0c0a4ef8u,4);
goto P_0c0a4e84;
P_0c0a4e84: /* original 9432, guest PC 0x0c0a4e84 */
if(!s->budget--) { s->failed_pc=0x0c0a4e84u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a4eecu,2);
goto P_0c0a4e86;
P_0c0a4e86: /* original 420b, guest PC 0x0c0a4e86 */
if(!s->budget--) { s->failed_pc=0x0c0a4e86u; return 0; }
target=r[2];
r[16]=0x0c0a4e8au;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a4e8au) { target=s->pc; goto dispatch; }
goto P_0c0a4e8a;
P_0c0a4e88: /* original 0009, guest PC 0x0c0a4e88 */
if(!s->budget--) { s->failed_pc=0x0c0a4e88u; return 0; }
goto P_0c0a4e8a;
P_0c0a4e8a: /* original d31b, guest PC 0x0c0a4e8a */
if(!s->budget--) { s->failed_pc=0x0c0a4e8au; return 0; }
r[3]=read(ram,0x0c0a4ef8u,4);
goto P_0c0a4e8c;
P_0c0a4e8c: /* original 942f, guest PC 0x0c0a4e8c */
if(!s->budget--) { s->failed_pc=0x0c0a4e8cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a4eeeu,2);
goto P_0c0a4e8e;
P_0c0a4e8e: /* original 430b, guest PC 0x0c0a4e8e */
if(!s->budget--) { s->failed_pc=0x0c0a4e8eu; return 0; }
target=r[3];
r[16]=0x0c0a4e92u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a4e92u) { target=s->pc; goto dispatch; }
goto P_0c0a4e92;
P_0c0a4e90: /* original 0009, guest PC 0x0c0a4e90 */
if(!s->budget--) { s->failed_pc=0x0c0a4e90u; return 0; }
goto P_0c0a4e92;
P_0c0a4e92: /* original d219, guest PC 0x0c0a4e92 */
if(!s->budget--) { s->failed_pc=0x0c0a4e92u; return 0; }
r[2]=read(ram,0x0c0a4ef8u,4);
goto P_0c0a4e94;
P_0c0a4e94: /* original 942c, guest PC 0x0c0a4e94 */
if(!s->budget--) { s->failed_pc=0x0c0a4e94u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a4ef0u,2);
goto P_0c0a4e96;
P_0c0a4e96: /* original 420b, guest PC 0x0c0a4e96 */
if(!s->budget--) { s->failed_pc=0x0c0a4e96u; return 0; }
target=r[2];
r[16]=0x0c0a4e9au;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a4e9au) { target=s->pc; goto dispatch; }
goto P_0c0a4e9a;
P_0c0a4e98: /* original 0009, guest PC 0x0c0a4e98 */
if(!s->budget--) { s->failed_pc=0x0c0a4e98u; return 0; }
goto P_0c0a4e9a;
P_0c0a4e9a: /* original d317, guest PC 0x0c0a4e9a */
if(!s->budget--) { s->failed_pc=0x0c0a4e9au; return 0; }
r[3]=read(ram,0x0c0a4ef8u,4);
goto P_0c0a4e9c;
P_0c0a4e9c: /* original 9429, guest PC 0x0c0a4e9c */
if(!s->budget--) { s->failed_pc=0x0c0a4e9cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a4ef2u,2);
goto P_0c0a4e9e;
P_0c0a4e9e: /* original 432b, guest PC 0x0c0a4e9e */
if(!s->budget--) { s->failed_pc=0x0c0a4e9eu; return 0; }
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
P_0c0a4ea0: /* original 4f26, guest PC 0x0c0a4ea0 */
if(!s->budget--) { s->failed_pc=0x0c0a4ea0u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
return vf3_matrix_family(0x0c0a4ea2u,s,ram);
P_0c0a4f90: /* original 4f22, guest PC 0x0c0a4f90 */
if(!s->budget--) { s->failed_pc=0x0c0a4f90u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0a4f92;
P_0c0a4f92: /* original d334, guest PC 0x0c0a4f92 */
if(!s->budget--) { s->failed_pc=0x0c0a4f92u; return 0; }
r[3]=read(ram,0x0c0a5064u,4);
goto P_0c0a4f94;
P_0c0a4f94: /* original 9452, guest PC 0x0c0a4f94 */
if(!s->budget--) { s->failed_pc=0x0c0a4f94u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a503cu,2);
goto P_0c0a4f96;
P_0c0a4f96: /* original 430b, guest PC 0x0c0a4f96 */
if(!s->budget--) { s->failed_pc=0x0c0a4f96u; return 0; }
target=r[3];
r[16]=0x0c0a4f9au;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a4f9au) { target=s->pc; goto dispatch; }
goto P_0c0a4f9a;
P_0c0a4f98: /* original 0009, guest PC 0x0c0a4f98 */
if(!s->budget--) { s->failed_pc=0x0c0a4f98u; return 0; }
goto P_0c0a4f9a;
P_0c0a4f9a: /* original d232, guest PC 0x0c0a4f9a */
if(!s->budget--) { s->failed_pc=0x0c0a4f9au; return 0; }
r[2]=read(ram,0x0c0a5064u,4);
goto P_0c0a4f9c;
P_0c0a4f9c: /* original 944f, guest PC 0x0c0a4f9c */
if(!s->budget--) { s->failed_pc=0x0c0a4f9cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a503eu,2);
goto P_0c0a4f9e;
P_0c0a4f9e: /* original 420b, guest PC 0x0c0a4f9e */
if(!s->budget--) { s->failed_pc=0x0c0a4f9eu; return 0; }
target=r[2];
r[16]=0x0c0a4fa2u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a4fa2u) { target=s->pc; goto dispatch; }
goto P_0c0a4fa2;
P_0c0a4fa0: /* original 0009, guest PC 0x0c0a4fa0 */
if(!s->budget--) { s->failed_pc=0x0c0a4fa0u; return 0; }
goto P_0c0a4fa2;
P_0c0a4fa2: /* original d330, guest PC 0x0c0a4fa2 */
if(!s->budget--) { s->failed_pc=0x0c0a4fa2u; return 0; }
r[3]=read(ram,0x0c0a5064u,4);
goto P_0c0a4fa4;
P_0c0a4fa4: /* original 944c, guest PC 0x0c0a4fa4 */
if(!s->budget--) { s->failed_pc=0x0c0a4fa4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a5040u,2);
goto P_0c0a4fa6;
P_0c0a4fa6: /* original 430b, guest PC 0x0c0a4fa6 */
if(!s->budget--) { s->failed_pc=0x0c0a4fa6u; return 0; }
target=r[3];
r[16]=0x0c0a4faau;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a4faau) { target=s->pc; goto dispatch; }
goto P_0c0a4faa;
P_0c0a4fa8: /* original 0009, guest PC 0x0c0a4fa8 */
if(!s->budget--) { s->failed_pc=0x0c0a4fa8u; return 0; }
goto P_0c0a4faa;
P_0c0a4faa: /* original d22e, guest PC 0x0c0a4faa */
if(!s->budget--) { s->failed_pc=0x0c0a4faau; return 0; }
r[2]=read(ram,0x0c0a5064u,4);
goto P_0c0a4fac;
P_0c0a4fac: /* original 9449, guest PC 0x0c0a4fac */
if(!s->budget--) { s->failed_pc=0x0c0a4facu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a5042u,2);
goto P_0c0a4fae;
P_0c0a4fae: /* original 420b, guest PC 0x0c0a4fae */
if(!s->budget--) { s->failed_pc=0x0c0a4faeu; return 0; }
target=r[2];
r[16]=0x0c0a4fb2u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a4fb2u) { target=s->pc; goto dispatch; }
goto P_0c0a4fb2;
P_0c0a4fb0: /* original 0009, guest PC 0x0c0a4fb0 */
if(!s->budget--) { s->failed_pc=0x0c0a4fb0u; return 0; }
goto P_0c0a4fb2;
P_0c0a4fb2: /* original d32c, guest PC 0x0c0a4fb2 */
if(!s->budget--) { s->failed_pc=0x0c0a4fb2u; return 0; }
r[3]=read(ram,0x0c0a5064u,4);
goto P_0c0a4fb4;
P_0c0a4fb4: /* original 9446, guest PC 0x0c0a4fb4 */
if(!s->budget--) { s->failed_pc=0x0c0a4fb4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a5044u,2);
goto P_0c0a4fb6;
P_0c0a4fb6: /* original 430b, guest PC 0x0c0a4fb6 */
if(!s->budget--) { s->failed_pc=0x0c0a4fb6u; return 0; }
target=r[3];
r[16]=0x0c0a4fbau;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a4fbau) { target=s->pc; goto dispatch; }
goto P_0c0a4fba;
P_0c0a4fb8: /* original 0009, guest PC 0x0c0a4fb8 */
if(!s->budget--) { s->failed_pc=0x0c0a4fb8u; return 0; }
goto P_0c0a4fba;
P_0c0a4fba: /* original d22a, guest PC 0x0c0a4fba */
if(!s->budget--) { s->failed_pc=0x0c0a4fbau; return 0; }
r[2]=read(ram,0x0c0a5064u,4);
goto P_0c0a4fbc;
P_0c0a4fbc: /* original 9443, guest PC 0x0c0a4fbc */
if(!s->budget--) { s->failed_pc=0x0c0a4fbcu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a5046u,2);
goto P_0c0a4fbe;
P_0c0a4fbe: /* original 420b, guest PC 0x0c0a4fbe */
if(!s->budget--) { s->failed_pc=0x0c0a4fbeu; return 0; }
target=r[2];
r[16]=0x0c0a4fc2u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a4fc2u) { target=s->pc; goto dispatch; }
goto P_0c0a4fc2;
P_0c0a4fc0: /* original 0009, guest PC 0x0c0a4fc0 */
if(!s->budget--) { s->failed_pc=0x0c0a4fc0u; return 0; }
goto P_0c0a4fc2;
P_0c0a4fc2: /* original d328, guest PC 0x0c0a4fc2 */
if(!s->budget--) { s->failed_pc=0x0c0a4fc2u; return 0; }
r[3]=read(ram,0x0c0a5064u,4);
goto P_0c0a4fc4;
P_0c0a4fc4: /* original 9440, guest PC 0x0c0a4fc4 */
if(!s->budget--) { s->failed_pc=0x0c0a4fc4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a5048u,2);
goto P_0c0a4fc6;
P_0c0a4fc6: /* original 430b, guest PC 0x0c0a4fc6 */
if(!s->budget--) { s->failed_pc=0x0c0a4fc6u; return 0; }
target=r[3];
r[16]=0x0c0a4fcau;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a4fcau) { target=s->pc; goto dispatch; }
goto P_0c0a4fca;
P_0c0a4fc8: /* original 0009, guest PC 0x0c0a4fc8 */
if(!s->budget--) { s->failed_pc=0x0c0a4fc8u; return 0; }
goto P_0c0a4fca;
P_0c0a4fca: /* original d226, guest PC 0x0c0a4fca */
if(!s->budget--) { s->failed_pc=0x0c0a4fcau; return 0; }
r[2]=read(ram,0x0c0a5064u,4);
goto P_0c0a4fcc;
P_0c0a4fcc: /* original 943d, guest PC 0x0c0a4fcc */
if(!s->budget--) { s->failed_pc=0x0c0a4fccu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a504au,2);
goto P_0c0a4fce;
P_0c0a4fce: /* original 420b, guest PC 0x0c0a4fce */
if(!s->budget--) { s->failed_pc=0x0c0a4fceu; return 0; }
target=r[2];
r[16]=0x0c0a4fd2u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a4fd2u) { target=s->pc; goto dispatch; }
goto P_0c0a4fd2;
P_0c0a4fd0: /* original 0009, guest PC 0x0c0a4fd0 */
if(!s->budget--) { s->failed_pc=0x0c0a4fd0u; return 0; }
goto P_0c0a4fd2;
P_0c0a4fd2: /* original d324, guest PC 0x0c0a4fd2 */
if(!s->budget--) { s->failed_pc=0x0c0a4fd2u; return 0; }
r[3]=read(ram,0x0c0a5064u,4);
goto P_0c0a4fd4;
P_0c0a4fd4: /* original 943a, guest PC 0x0c0a4fd4 */
if(!s->budget--) { s->failed_pc=0x0c0a4fd4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a504cu,2);
goto P_0c0a4fd6;
P_0c0a4fd6: /* original 430b, guest PC 0x0c0a4fd6 */
if(!s->budget--) { s->failed_pc=0x0c0a4fd6u; return 0; }
target=r[3];
r[16]=0x0c0a4fdau;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a4fdau) { target=s->pc; goto dispatch; }
goto P_0c0a4fda;
P_0c0a4fd8: /* original 0009, guest PC 0x0c0a4fd8 */
if(!s->budget--) { s->failed_pc=0x0c0a4fd8u; return 0; }
goto P_0c0a4fda;
P_0c0a4fda: /* original d222, guest PC 0x0c0a4fda */
if(!s->budget--) { s->failed_pc=0x0c0a4fdau; return 0; }
r[2]=read(ram,0x0c0a5064u,4);
goto P_0c0a4fdc;
P_0c0a4fdc: /* original 9437, guest PC 0x0c0a4fdc */
if(!s->budget--) { s->failed_pc=0x0c0a4fdcu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a504eu,2);
goto P_0c0a4fde;
P_0c0a4fde: /* original 420b, guest PC 0x0c0a4fde */
if(!s->budget--) { s->failed_pc=0x0c0a4fdeu; return 0; }
target=r[2];
r[16]=0x0c0a4fe2u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a4fe2u) { target=s->pc; goto dispatch; }
goto P_0c0a4fe2;
P_0c0a4fe0: /* original 0009, guest PC 0x0c0a4fe0 */
if(!s->budget--) { s->failed_pc=0x0c0a4fe0u; return 0; }
goto P_0c0a4fe2;
P_0c0a4fe2: /* original d320, guest PC 0x0c0a4fe2 */
if(!s->budget--) { s->failed_pc=0x0c0a4fe2u; return 0; }
r[3]=read(ram,0x0c0a5064u,4);
goto P_0c0a4fe4;
P_0c0a4fe4: /* original 9434, guest PC 0x0c0a4fe4 */
if(!s->budget--) { s->failed_pc=0x0c0a4fe4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a5050u,2);
goto P_0c0a4fe6;
P_0c0a4fe6: /* original 430b, guest PC 0x0c0a4fe6 */
if(!s->budget--) { s->failed_pc=0x0c0a4fe6u; return 0; }
target=r[3];
r[16]=0x0c0a4feau;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a4feau) { target=s->pc; goto dispatch; }
goto P_0c0a4fea;
P_0c0a4fe8: /* original 0009, guest PC 0x0c0a4fe8 */
if(!s->budget--) { s->failed_pc=0x0c0a4fe8u; return 0; }
goto P_0c0a4fea;
P_0c0a4fea: /* original d21e, guest PC 0x0c0a4fea */
if(!s->budget--) { s->failed_pc=0x0c0a4feau; return 0; }
r[2]=read(ram,0x0c0a5064u,4);
goto P_0c0a4fec;
P_0c0a4fec: /* original 9431, guest PC 0x0c0a4fec */
if(!s->budget--) { s->failed_pc=0x0c0a4fecu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a5052u,2);
goto P_0c0a4fee;
P_0c0a4fee: /* original 420b, guest PC 0x0c0a4fee */
if(!s->budget--) { s->failed_pc=0x0c0a4feeu; return 0; }
target=r[2];
r[16]=0x0c0a4ff2u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a4ff2u) { target=s->pc; goto dispatch; }
goto P_0c0a4ff2;
P_0c0a4ff0: /* original 0009, guest PC 0x0c0a4ff0 */
if(!s->budget--) { s->failed_pc=0x0c0a4ff0u; return 0; }
goto P_0c0a4ff2;
P_0c0a4ff2: /* original d31c, guest PC 0x0c0a4ff2 */
if(!s->budget--) { s->failed_pc=0x0c0a4ff2u; return 0; }
r[3]=read(ram,0x0c0a5064u,4);
goto P_0c0a4ff4;
P_0c0a4ff4: /* original 942e, guest PC 0x0c0a4ff4 */
if(!s->budget--) { s->failed_pc=0x0c0a4ff4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a5054u,2);
goto P_0c0a4ff6;
P_0c0a4ff6: /* original 430b, guest PC 0x0c0a4ff6 */
if(!s->budget--) { s->failed_pc=0x0c0a4ff6u; return 0; }
target=r[3];
r[16]=0x0c0a4ffau;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a4ffau) { target=s->pc; goto dispatch; }
goto P_0c0a4ffa;
P_0c0a4ff8: /* original 0009, guest PC 0x0c0a4ff8 */
if(!s->budget--) { s->failed_pc=0x0c0a4ff8u; return 0; }
goto P_0c0a4ffa;
P_0c0a4ffa: /* original d21a, guest PC 0x0c0a4ffa */
if(!s->budget--) { s->failed_pc=0x0c0a4ffau; return 0; }
r[2]=read(ram,0x0c0a5064u,4);
goto P_0c0a4ffc;
P_0c0a4ffc: /* original 942b, guest PC 0x0c0a4ffc */
if(!s->budget--) { s->failed_pc=0x0c0a4ffcu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a5056u,2);
goto P_0c0a4ffe;
P_0c0a4ffe: /* original 420b, guest PC 0x0c0a4ffe */
if(!s->budget--) { s->failed_pc=0x0c0a4ffeu; return 0; }
target=r[2];
r[16]=0x0c0a5002u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a5002u) { target=s->pc; goto dispatch; }
goto P_0c0a5002;
P_0c0a5000: /* original 0009, guest PC 0x0c0a5000 */
if(!s->budget--) { s->failed_pc=0x0c0a5000u; return 0; }
goto P_0c0a5002;
P_0c0a5002: /* original d318, guest PC 0x0c0a5002 */
if(!s->budget--) { s->failed_pc=0x0c0a5002u; return 0; }
r[3]=read(ram,0x0c0a5064u,4);
goto P_0c0a5004;
P_0c0a5004: /* original 9428, guest PC 0x0c0a5004 */
if(!s->budget--) { s->failed_pc=0x0c0a5004u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a5058u,2);
goto P_0c0a5006;
P_0c0a5006: /* original 430b, guest PC 0x0c0a5006 */
if(!s->budget--) { s->failed_pc=0x0c0a5006u; return 0; }
target=r[3];
r[16]=0x0c0a500au;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a500au) { target=s->pc; goto dispatch; }
goto P_0c0a500a;
P_0c0a5008: /* original 0009, guest PC 0x0c0a5008 */
if(!s->budget--) { s->failed_pc=0x0c0a5008u; return 0; }
goto P_0c0a500a;
P_0c0a500a: /* original d216, guest PC 0x0c0a500a */
if(!s->budget--) { s->failed_pc=0x0c0a500au; return 0; }
r[2]=read(ram,0x0c0a5064u,4);
goto P_0c0a500c;
P_0c0a500c: /* original 9425, guest PC 0x0c0a500c */
if(!s->budget--) { s->failed_pc=0x0c0a500cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a505au,2);
goto P_0c0a500e;
P_0c0a500e: /* original 420b, guest PC 0x0c0a500e */
if(!s->budget--) { s->failed_pc=0x0c0a500eu; return 0; }
target=r[2];
r[16]=0x0c0a5012u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a5012u) { target=s->pc; goto dispatch; }
goto P_0c0a5012;
P_0c0a5010: /* original 0009, guest PC 0x0c0a5010 */
if(!s->budget--) { s->failed_pc=0x0c0a5010u; return 0; }
goto P_0c0a5012;
P_0c0a5012: /* original d314, guest PC 0x0c0a5012 */
if(!s->budget--) { s->failed_pc=0x0c0a5012u; return 0; }
r[3]=read(ram,0x0c0a5064u,4);
goto P_0c0a5014;
P_0c0a5014: /* original 9422, guest PC 0x0c0a5014 */
if(!s->budget--) { s->failed_pc=0x0c0a5014u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a505cu,2);
goto P_0c0a5016;
P_0c0a5016: /* original 432b, guest PC 0x0c0a5016 */
if(!s->budget--) { s->failed_pc=0x0c0a5016u; return 0; }
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
P_0c0a5018: /* original 4f26, guest PC 0x0c0a5018 */
if(!s->budget--) { s->failed_pc=0x0c0a5018u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
return vf3_matrix_family(0x0c0a501au,s,ram);
P_0c0a5124: /* original 4f22, guest PC 0x0c0a5124 */
if(!s->budget--) { s->failed_pc=0x0c0a5124u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0a5126;
P_0c0a5126: /* original d370, guest PC 0x0c0a5126 */
if(!s->budget--) { s->failed_pc=0x0c0a5126u; return 0; }
r[3]=read(ram,0x0c0a52e8u,4);
goto P_0c0a5128;
P_0c0a5128: /* original 94b1, guest PC 0x0c0a5128 */
if(!s->budget--) { s->failed_pc=0x0c0a5128u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a528eu,2);
goto P_0c0a512a;
P_0c0a512a: /* original 430b, guest PC 0x0c0a512a */
if(!s->budget--) { s->failed_pc=0x0c0a512au; return 0; }
target=r[3];
r[16]=0x0c0a512eu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a512eu) { target=s->pc; goto dispatch; }
goto P_0c0a512e;
P_0c0a512c: /* original 0009, guest PC 0x0c0a512c */
if(!s->budget--) { s->failed_pc=0x0c0a512cu; return 0; }
goto P_0c0a512e;
P_0c0a512e: /* original d26e, guest PC 0x0c0a512e */
if(!s->budget--) { s->failed_pc=0x0c0a512eu; return 0; }
r[2]=read(ram,0x0c0a52e8u,4);
goto P_0c0a5130;
P_0c0a5130: /* original 94ae, guest PC 0x0c0a5130 */
if(!s->budget--) { s->failed_pc=0x0c0a5130u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a5290u,2);
goto P_0c0a5132;
P_0c0a5132: /* original 420b, guest PC 0x0c0a5132 */
if(!s->budget--) { s->failed_pc=0x0c0a5132u; return 0; }
target=r[2];
r[16]=0x0c0a5136u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a5136u) { target=s->pc; goto dispatch; }
goto P_0c0a5136;
P_0c0a5134: /* original 0009, guest PC 0x0c0a5134 */
if(!s->budget--) { s->failed_pc=0x0c0a5134u; return 0; }
goto P_0c0a5136;
P_0c0a5136: /* original d36c, guest PC 0x0c0a5136 */
if(!s->budget--) { s->failed_pc=0x0c0a5136u; return 0; }
r[3]=read(ram,0x0c0a52e8u,4);
goto P_0c0a5138;
P_0c0a5138: /* original 94ab, guest PC 0x0c0a5138 */
if(!s->budget--) { s->failed_pc=0x0c0a5138u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a5292u,2);
goto P_0c0a513a;
P_0c0a513a: /* original 430b, guest PC 0x0c0a513a */
if(!s->budget--) { s->failed_pc=0x0c0a513au; return 0; }
target=r[3];
r[16]=0x0c0a513eu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a513eu) { target=s->pc; goto dispatch; }
goto P_0c0a513e;
P_0c0a513c: /* original 0009, guest PC 0x0c0a513c */
if(!s->budget--) { s->failed_pc=0x0c0a513cu; return 0; }
goto P_0c0a513e;
P_0c0a513e: /* original d26a, guest PC 0x0c0a513e */
if(!s->budget--) { s->failed_pc=0x0c0a513eu; return 0; }
r[2]=read(ram,0x0c0a52e8u,4);
goto P_0c0a5140;
P_0c0a5140: /* original 94a8, guest PC 0x0c0a5140 */
if(!s->budget--) { s->failed_pc=0x0c0a5140u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a5294u,2);
goto P_0c0a5142;
P_0c0a5142: /* original 420b, guest PC 0x0c0a5142 */
if(!s->budget--) { s->failed_pc=0x0c0a5142u; return 0; }
target=r[2];
r[16]=0x0c0a5146u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a5146u) { target=s->pc; goto dispatch; }
goto P_0c0a5146;
P_0c0a5144: /* original 0009, guest PC 0x0c0a5144 */
if(!s->budget--) { s->failed_pc=0x0c0a5144u; return 0; }
goto P_0c0a5146;
P_0c0a5146: /* original d368, guest PC 0x0c0a5146 */
if(!s->budget--) { s->failed_pc=0x0c0a5146u; return 0; }
r[3]=read(ram,0x0c0a52e8u,4);
goto P_0c0a5148;
P_0c0a5148: /* original 94a5, guest PC 0x0c0a5148 */
if(!s->budget--) { s->failed_pc=0x0c0a5148u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a5296u,2);
goto P_0c0a514a;
P_0c0a514a: /* original 430b, guest PC 0x0c0a514a */
if(!s->budget--) { s->failed_pc=0x0c0a514au; return 0; }
target=r[3];
r[16]=0x0c0a514eu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a514eu) { target=s->pc; goto dispatch; }
goto P_0c0a514e;
P_0c0a514c: /* original 0009, guest PC 0x0c0a514c */
if(!s->budget--) { s->failed_pc=0x0c0a514cu; return 0; }
goto P_0c0a514e;
P_0c0a514e: /* original d266, guest PC 0x0c0a514e */
if(!s->budget--) { s->failed_pc=0x0c0a514eu; return 0; }
r[2]=read(ram,0x0c0a52e8u,4);
goto P_0c0a5150;
P_0c0a5150: /* original 94a2, guest PC 0x0c0a5150 */
if(!s->budget--) { s->failed_pc=0x0c0a5150u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a5298u,2);
goto P_0c0a5152;
P_0c0a5152: /* original 420b, guest PC 0x0c0a5152 */
if(!s->budget--) { s->failed_pc=0x0c0a5152u; return 0; }
target=r[2];
r[16]=0x0c0a5156u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a5156u) { target=s->pc; goto dispatch; }
goto P_0c0a5156;
P_0c0a5154: /* original 0009, guest PC 0x0c0a5154 */
if(!s->budget--) { s->failed_pc=0x0c0a5154u; return 0; }
goto P_0c0a5156;
P_0c0a5156: /* original d364, guest PC 0x0c0a5156 */
if(!s->budget--) { s->failed_pc=0x0c0a5156u; return 0; }
r[3]=read(ram,0x0c0a52e8u,4);
goto P_0c0a5158;
P_0c0a5158: /* original 949f, guest PC 0x0c0a5158 */
if(!s->budget--) { s->failed_pc=0x0c0a5158u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a529au,2);
goto P_0c0a515a;
P_0c0a515a: /* original 430b, guest PC 0x0c0a515a */
if(!s->budget--) { s->failed_pc=0x0c0a515au; return 0; }
target=r[3];
r[16]=0x0c0a515eu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a515eu) { target=s->pc; goto dispatch; }
goto P_0c0a515e;
P_0c0a515c: /* original 0009, guest PC 0x0c0a515c */
if(!s->budget--) { s->failed_pc=0x0c0a515cu; return 0; }
goto P_0c0a515e;
P_0c0a515e: /* original d262, guest PC 0x0c0a515e */
if(!s->budget--) { s->failed_pc=0x0c0a515eu; return 0; }
r[2]=read(ram,0x0c0a52e8u,4);
goto P_0c0a5160;
P_0c0a5160: /* original 949c, guest PC 0x0c0a5160 */
if(!s->budget--) { s->failed_pc=0x0c0a5160u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a529cu,2);
goto P_0c0a5162;
P_0c0a5162: /* original 420b, guest PC 0x0c0a5162 */
if(!s->budget--) { s->failed_pc=0x0c0a5162u; return 0; }
target=r[2];
r[16]=0x0c0a5166u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a5166u) { target=s->pc; goto dispatch; }
goto P_0c0a5166;
P_0c0a5164: /* original 0009, guest PC 0x0c0a5164 */
if(!s->budget--) { s->failed_pc=0x0c0a5164u; return 0; }
goto P_0c0a5166;
P_0c0a5166: /* original d360, guest PC 0x0c0a5166 */
if(!s->budget--) { s->failed_pc=0x0c0a5166u; return 0; }
r[3]=read(ram,0x0c0a52e8u,4);
goto P_0c0a5168;
P_0c0a5168: /* original 9499, guest PC 0x0c0a5168 */
if(!s->budget--) { s->failed_pc=0x0c0a5168u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a529eu,2);
goto P_0c0a516a;
P_0c0a516a: /* original 430b, guest PC 0x0c0a516a */
if(!s->budget--) { s->failed_pc=0x0c0a516au; return 0; }
target=r[3];
r[16]=0x0c0a516eu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a516eu) { target=s->pc; goto dispatch; }
goto P_0c0a516e;
P_0c0a516c: /* original 0009, guest PC 0x0c0a516c */
if(!s->budget--) { s->failed_pc=0x0c0a516cu; return 0; }
goto P_0c0a516e;
P_0c0a516e: /* original d25e, guest PC 0x0c0a516e */
if(!s->budget--) { s->failed_pc=0x0c0a516eu; return 0; }
r[2]=read(ram,0x0c0a52e8u,4);
goto P_0c0a5170;
P_0c0a5170: /* original 9496, guest PC 0x0c0a5170 */
if(!s->budget--) { s->failed_pc=0x0c0a5170u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a52a0u,2);
goto P_0c0a5172;
P_0c0a5172: /* original 420b, guest PC 0x0c0a5172 */
if(!s->budget--) { s->failed_pc=0x0c0a5172u; return 0; }
target=r[2];
r[16]=0x0c0a5176u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a5176u) { target=s->pc; goto dispatch; }
goto P_0c0a5176;
P_0c0a5174: /* original 0009, guest PC 0x0c0a5174 */
if(!s->budget--) { s->failed_pc=0x0c0a5174u; return 0; }
goto P_0c0a5176;
P_0c0a5176: /* original d35c, guest PC 0x0c0a5176 */
if(!s->budget--) { s->failed_pc=0x0c0a5176u; return 0; }
r[3]=read(ram,0x0c0a52e8u,4);
goto P_0c0a5178;
P_0c0a5178: /* original 9493, guest PC 0x0c0a5178 */
if(!s->budget--) { s->failed_pc=0x0c0a5178u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a52a2u,2);
goto P_0c0a517a;
P_0c0a517a: /* original 430b, guest PC 0x0c0a517a */
if(!s->budget--) { s->failed_pc=0x0c0a517au; return 0; }
target=r[3];
r[16]=0x0c0a517eu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a517eu) { target=s->pc; goto dispatch; }
goto P_0c0a517e;
P_0c0a517c: /* original 0009, guest PC 0x0c0a517c */
if(!s->budget--) { s->failed_pc=0x0c0a517cu; return 0; }
goto P_0c0a517e;
P_0c0a517e: /* original d25a, guest PC 0x0c0a517e */
if(!s->budget--) { s->failed_pc=0x0c0a517eu; return 0; }
r[2]=read(ram,0x0c0a52e8u,4);
goto P_0c0a5180;
P_0c0a5180: /* original 9490, guest PC 0x0c0a5180 */
if(!s->budget--) { s->failed_pc=0x0c0a5180u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a52a4u,2);
goto P_0c0a5182;
P_0c0a5182: /* original 420b, guest PC 0x0c0a5182 */
if(!s->budget--) { s->failed_pc=0x0c0a5182u; return 0; }
target=r[2];
r[16]=0x0c0a5186u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a5186u) { target=s->pc; goto dispatch; }
goto P_0c0a5186;
P_0c0a5184: /* original 0009, guest PC 0x0c0a5184 */
if(!s->budget--) { s->failed_pc=0x0c0a5184u; return 0; }
goto P_0c0a5186;
P_0c0a5186: /* original d358, guest PC 0x0c0a5186 */
if(!s->budget--) { s->failed_pc=0x0c0a5186u; return 0; }
r[3]=read(ram,0x0c0a52e8u,4);
goto P_0c0a5188;
P_0c0a5188: /* original 948d, guest PC 0x0c0a5188 */
if(!s->budget--) { s->failed_pc=0x0c0a5188u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a52a6u,2);
goto P_0c0a518a;
P_0c0a518a: /* original 430b, guest PC 0x0c0a518a */
if(!s->budget--) { s->failed_pc=0x0c0a518au; return 0; }
target=r[3];
r[16]=0x0c0a518eu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a518eu) { target=s->pc; goto dispatch; }
goto P_0c0a518e;
P_0c0a518c: /* original 0009, guest PC 0x0c0a518c */
if(!s->budget--) { s->failed_pc=0x0c0a518cu; return 0; }
goto P_0c0a518e;
P_0c0a518e: /* original d256, guest PC 0x0c0a518e */
if(!s->budget--) { s->failed_pc=0x0c0a518eu; return 0; }
r[2]=read(ram,0x0c0a52e8u,4);
goto P_0c0a5190;
P_0c0a5190: /* original 948a, guest PC 0x0c0a5190 */
if(!s->budget--) { s->failed_pc=0x0c0a5190u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a52a8u,2);
goto P_0c0a5192;
P_0c0a5192: /* original 420b, guest PC 0x0c0a5192 */
if(!s->budget--) { s->failed_pc=0x0c0a5192u; return 0; }
target=r[2];
r[16]=0x0c0a5196u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a5196u) { target=s->pc; goto dispatch; }
goto P_0c0a5196;
P_0c0a5194: /* original 0009, guest PC 0x0c0a5194 */
if(!s->budget--) { s->failed_pc=0x0c0a5194u; return 0; }
goto P_0c0a5196;
P_0c0a5196: /* original d354, guest PC 0x0c0a5196 */
if(!s->budget--) { s->failed_pc=0x0c0a5196u; return 0; }
r[3]=read(ram,0x0c0a52e8u,4);
goto P_0c0a5198;
P_0c0a5198: /* original 9487, guest PC 0x0c0a5198 */
if(!s->budget--) { s->failed_pc=0x0c0a5198u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a52aau,2);
goto P_0c0a519a;
P_0c0a519a: /* original 430b, guest PC 0x0c0a519a */
if(!s->budget--) { s->failed_pc=0x0c0a519au; return 0; }
target=r[3];
r[16]=0x0c0a519eu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a519eu) { target=s->pc; goto dispatch; }
goto P_0c0a519e;
P_0c0a519c: /* original 0009, guest PC 0x0c0a519c */
if(!s->budget--) { s->failed_pc=0x0c0a519cu; return 0; }
goto P_0c0a519e;
P_0c0a519e: /* original d252, guest PC 0x0c0a519e */
if(!s->budget--) { s->failed_pc=0x0c0a519eu; return 0; }
r[2]=read(ram,0x0c0a52e8u,4);
goto P_0c0a51a0;
P_0c0a51a0: /* original 9484, guest PC 0x0c0a51a0 */
if(!s->budget--) { s->failed_pc=0x0c0a51a0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a52acu,2);
goto P_0c0a51a2;
P_0c0a51a2: /* original 420b, guest PC 0x0c0a51a2 */
if(!s->budget--) { s->failed_pc=0x0c0a51a2u; return 0; }
target=r[2];
r[16]=0x0c0a51a6u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a51a6u) { target=s->pc; goto dispatch; }
goto P_0c0a51a6;
P_0c0a51a4: /* original 0009, guest PC 0x0c0a51a4 */
if(!s->budget--) { s->failed_pc=0x0c0a51a4u; return 0; }
goto P_0c0a51a6;
P_0c0a51a6: /* original d350, guest PC 0x0c0a51a6 */
if(!s->budget--) { s->failed_pc=0x0c0a51a6u; return 0; }
r[3]=read(ram,0x0c0a52e8u,4);
goto P_0c0a51a8;
P_0c0a51a8: /* original 9481, guest PC 0x0c0a51a8 */
if(!s->budget--) { s->failed_pc=0x0c0a51a8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a52aeu,2);
goto P_0c0a51aa;
P_0c0a51aa: /* original 430b, guest PC 0x0c0a51aa */
if(!s->budget--) { s->failed_pc=0x0c0a51aau; return 0; }
target=r[3];
r[16]=0x0c0a51aeu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a51aeu) { target=s->pc; goto dispatch; }
goto P_0c0a51ae;
P_0c0a51ac: /* original 0009, guest PC 0x0c0a51ac */
if(!s->budget--) { s->failed_pc=0x0c0a51acu; return 0; }
goto P_0c0a51ae;
P_0c0a51ae: /* original d24e, guest PC 0x0c0a51ae */
if(!s->budget--) { s->failed_pc=0x0c0a51aeu; return 0; }
r[2]=read(ram,0x0c0a52e8u,4);
goto P_0c0a51b0;
P_0c0a51b0: /* original 947e, guest PC 0x0c0a51b0 */
if(!s->budget--) { s->failed_pc=0x0c0a51b0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a52b0u,2);
goto P_0c0a51b2;
P_0c0a51b2: /* original 420b, guest PC 0x0c0a51b2 */
if(!s->budget--) { s->failed_pc=0x0c0a51b2u; return 0; }
target=r[2];
r[16]=0x0c0a51b6u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a51b6u) { target=s->pc; goto dispatch; }
goto P_0c0a51b6;
P_0c0a51b4: /* original 0009, guest PC 0x0c0a51b4 */
if(!s->budget--) { s->failed_pc=0x0c0a51b4u; return 0; }
goto P_0c0a51b6;
P_0c0a51b6: /* original d34c, guest PC 0x0c0a51b6 */
if(!s->budget--) { s->failed_pc=0x0c0a51b6u; return 0; }
r[3]=read(ram,0x0c0a52e8u,4);
goto P_0c0a51b8;
P_0c0a51b8: /* original 947b, guest PC 0x0c0a51b8 */
if(!s->budget--) { s->failed_pc=0x0c0a51b8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a52b2u,2);
goto P_0c0a51ba;
P_0c0a51ba: /* original 430b, guest PC 0x0c0a51ba */
if(!s->budget--) { s->failed_pc=0x0c0a51bau; return 0; }
target=r[3];
r[16]=0x0c0a51beu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a51beu) { target=s->pc; goto dispatch; }
goto P_0c0a51be;
P_0c0a51bc: /* original 0009, guest PC 0x0c0a51bc */
if(!s->budget--) { s->failed_pc=0x0c0a51bcu; return 0; }
goto P_0c0a51be;
P_0c0a51be: /* original d24a, guest PC 0x0c0a51be */
if(!s->budget--) { s->failed_pc=0x0c0a51beu; return 0; }
r[2]=read(ram,0x0c0a52e8u,4);
goto P_0c0a51c0;
P_0c0a51c0: /* original 9478, guest PC 0x0c0a51c0 */
if(!s->budget--) { s->failed_pc=0x0c0a51c0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a52b4u,2);
goto P_0c0a51c2;
P_0c0a51c2: /* original 420b, guest PC 0x0c0a51c2 */
if(!s->budget--) { s->failed_pc=0x0c0a51c2u; return 0; }
target=r[2];
r[16]=0x0c0a51c6u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a51c6u) { target=s->pc; goto dispatch; }
goto P_0c0a51c6;
P_0c0a51c4: /* original 0009, guest PC 0x0c0a51c4 */
if(!s->budget--) { s->failed_pc=0x0c0a51c4u; return 0; }
goto P_0c0a51c6;
P_0c0a51c6: /* original d348, guest PC 0x0c0a51c6 */
if(!s->budget--) { s->failed_pc=0x0c0a51c6u; return 0; }
r[3]=read(ram,0x0c0a52e8u,4);
goto P_0c0a51c8;
P_0c0a51c8: /* original 9475, guest PC 0x0c0a51c8 */
if(!s->budget--) { s->failed_pc=0x0c0a51c8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a52b6u,2);
goto P_0c0a51ca;
P_0c0a51ca: /* original 430b, guest PC 0x0c0a51ca */
if(!s->budget--) { s->failed_pc=0x0c0a51cau; return 0; }
target=r[3];
r[16]=0x0c0a51ceu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a51ceu) { target=s->pc; goto dispatch; }
goto P_0c0a51ce;
P_0c0a51cc: /* original 0009, guest PC 0x0c0a51cc */
if(!s->budget--) { s->failed_pc=0x0c0a51ccu; return 0; }
goto P_0c0a51ce;
P_0c0a51ce: /* original d246, guest PC 0x0c0a51ce */
if(!s->budget--) { s->failed_pc=0x0c0a51ceu; return 0; }
r[2]=read(ram,0x0c0a52e8u,4);
goto P_0c0a51d0;
P_0c0a51d0: /* original 9472, guest PC 0x0c0a51d0 */
if(!s->budget--) { s->failed_pc=0x0c0a51d0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a52b8u,2);
goto P_0c0a51d2;
P_0c0a51d2: /* original 420b, guest PC 0x0c0a51d2 */
if(!s->budget--) { s->failed_pc=0x0c0a51d2u; return 0; }
target=r[2];
r[16]=0x0c0a51d6u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a51d6u) { target=s->pc; goto dispatch; }
goto P_0c0a51d6;
P_0c0a51d4: /* original 0009, guest PC 0x0c0a51d4 */
if(!s->budget--) { s->failed_pc=0x0c0a51d4u; return 0; }
goto P_0c0a51d6;
P_0c0a51d6: /* original d344, guest PC 0x0c0a51d6 */
if(!s->budget--) { s->failed_pc=0x0c0a51d6u; return 0; }
r[3]=read(ram,0x0c0a52e8u,4);
goto P_0c0a51d8;
P_0c0a51d8: /* original 946f, guest PC 0x0c0a51d8 */
if(!s->budget--) { s->failed_pc=0x0c0a51d8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a52bau,2);
goto P_0c0a51da;
P_0c0a51da: /* original 430b, guest PC 0x0c0a51da */
if(!s->budget--) { s->failed_pc=0x0c0a51dau; return 0; }
target=r[3];
r[16]=0x0c0a51deu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a51deu) { target=s->pc; goto dispatch; }
goto P_0c0a51de;
P_0c0a51dc: /* original 0009, guest PC 0x0c0a51dc */
if(!s->budget--) { s->failed_pc=0x0c0a51dcu; return 0; }
goto P_0c0a51de;
P_0c0a51de: /* original d242, guest PC 0x0c0a51de */
if(!s->budget--) { s->failed_pc=0x0c0a51deu; return 0; }
r[2]=read(ram,0x0c0a52e8u,4);
goto P_0c0a51e0;
P_0c0a51e0: /* original 946c, guest PC 0x0c0a51e0 */
if(!s->budget--) { s->failed_pc=0x0c0a51e0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a52bcu,2);
goto P_0c0a51e2;
P_0c0a51e2: /* original 420b, guest PC 0x0c0a51e2 */
if(!s->budget--) { s->failed_pc=0x0c0a51e2u; return 0; }
target=r[2];
r[16]=0x0c0a51e6u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a51e6u) { target=s->pc; goto dispatch; }
goto P_0c0a51e6;
P_0c0a51e4: /* original 0009, guest PC 0x0c0a51e4 */
if(!s->budget--) { s->failed_pc=0x0c0a51e4u; return 0; }
goto P_0c0a51e6;
P_0c0a51e6: /* original d340, guest PC 0x0c0a51e6 */
if(!s->budget--) { s->failed_pc=0x0c0a51e6u; return 0; }
r[3]=read(ram,0x0c0a52e8u,4);
goto P_0c0a51e8;
P_0c0a51e8: /* original 9469, guest PC 0x0c0a51e8 */
if(!s->budget--) { s->failed_pc=0x0c0a51e8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a52beu,2);
goto P_0c0a51ea;
P_0c0a51ea: /* original 430b, guest PC 0x0c0a51ea */
if(!s->budget--) { s->failed_pc=0x0c0a51eau; return 0; }
target=r[3];
r[16]=0x0c0a51eeu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a51eeu) { target=s->pc; goto dispatch; }
goto P_0c0a51ee;
P_0c0a51ec: /* original 0009, guest PC 0x0c0a51ec */
if(!s->budget--) { s->failed_pc=0x0c0a51ecu; return 0; }
goto P_0c0a51ee;
P_0c0a51ee: /* original d23e, guest PC 0x0c0a51ee */
if(!s->budget--) { s->failed_pc=0x0c0a51eeu; return 0; }
r[2]=read(ram,0x0c0a52e8u,4);
goto P_0c0a51f0;
P_0c0a51f0: /* original 9466, guest PC 0x0c0a51f0 */
if(!s->budget--) { s->failed_pc=0x0c0a51f0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a52c0u,2);
goto P_0c0a51f2;
P_0c0a51f2: /* original 420b, guest PC 0x0c0a51f2 */
if(!s->budget--) { s->failed_pc=0x0c0a51f2u; return 0; }
target=r[2];
r[16]=0x0c0a51f6u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a51f6u) { target=s->pc; goto dispatch; }
goto P_0c0a51f6;
P_0c0a51f4: /* original 0009, guest PC 0x0c0a51f4 */
if(!s->budget--) { s->failed_pc=0x0c0a51f4u; return 0; }
goto P_0c0a51f6;
P_0c0a51f6: /* original d33c, guest PC 0x0c0a51f6 */
if(!s->budget--) { s->failed_pc=0x0c0a51f6u; return 0; }
r[3]=read(ram,0x0c0a52e8u,4);
goto P_0c0a51f8;
P_0c0a51f8: /* original 9463, guest PC 0x0c0a51f8 */
if(!s->budget--) { s->failed_pc=0x0c0a51f8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a52c2u,2);
goto P_0c0a51fa;
P_0c0a51fa: /* original 430b, guest PC 0x0c0a51fa */
if(!s->budget--) { s->failed_pc=0x0c0a51fau; return 0; }
target=r[3];
r[16]=0x0c0a51feu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a51feu) { target=s->pc; goto dispatch; }
goto P_0c0a51fe;
P_0c0a51fc: /* original 0009, guest PC 0x0c0a51fc */
if(!s->budget--) { s->failed_pc=0x0c0a51fcu; return 0; }
goto P_0c0a51fe;
P_0c0a51fe: /* original d23a, guest PC 0x0c0a51fe */
if(!s->budget--) { s->failed_pc=0x0c0a51feu; return 0; }
r[2]=read(ram,0x0c0a52e8u,4);
goto P_0c0a5200;
P_0c0a5200: /* original 9460, guest PC 0x0c0a5200 */
if(!s->budget--) { s->failed_pc=0x0c0a5200u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a52c4u,2);
goto P_0c0a5202;
P_0c0a5202: /* original 420b, guest PC 0x0c0a5202 */
if(!s->budget--) { s->failed_pc=0x0c0a5202u; return 0; }
target=r[2];
r[16]=0x0c0a5206u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a5206u) { target=s->pc; goto dispatch; }
goto P_0c0a5206;
P_0c0a5204: /* original 0009, guest PC 0x0c0a5204 */
if(!s->budget--) { s->failed_pc=0x0c0a5204u; return 0; }
goto P_0c0a5206;
P_0c0a5206: /* original d338, guest PC 0x0c0a5206 */
if(!s->budget--) { s->failed_pc=0x0c0a5206u; return 0; }
r[3]=read(ram,0x0c0a52e8u,4);
goto P_0c0a5208;
P_0c0a5208: /* original 945d, guest PC 0x0c0a5208 */
if(!s->budget--) { s->failed_pc=0x0c0a5208u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a52c6u,2);
goto P_0c0a520a;
P_0c0a520a: /* original 430b, guest PC 0x0c0a520a */
if(!s->budget--) { s->failed_pc=0x0c0a520au; return 0; }
target=r[3];
r[16]=0x0c0a520eu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a520eu) { target=s->pc; goto dispatch; }
goto P_0c0a520e;
P_0c0a520c: /* original 0009, guest PC 0x0c0a520c */
if(!s->budget--) { s->failed_pc=0x0c0a520cu; return 0; }
goto P_0c0a520e;
P_0c0a520e: /* original d236, guest PC 0x0c0a520e */
if(!s->budget--) { s->failed_pc=0x0c0a520eu; return 0; }
r[2]=read(ram,0x0c0a52e8u,4);
goto P_0c0a5210;
P_0c0a5210: /* original 945a, guest PC 0x0c0a5210 */
if(!s->budget--) { s->failed_pc=0x0c0a5210u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a52c8u,2);
goto P_0c0a5212;
P_0c0a5212: /* original 420b, guest PC 0x0c0a5212 */
if(!s->budget--) { s->failed_pc=0x0c0a5212u; return 0; }
target=r[2];
r[16]=0x0c0a5216u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a5216u) { target=s->pc; goto dispatch; }
goto P_0c0a5216;
P_0c0a5214: /* original 0009, guest PC 0x0c0a5214 */
if(!s->budget--) { s->failed_pc=0x0c0a5214u; return 0; }
goto P_0c0a5216;
P_0c0a5216: /* original d334, guest PC 0x0c0a5216 */
if(!s->budget--) { s->failed_pc=0x0c0a5216u; return 0; }
r[3]=read(ram,0x0c0a52e8u,4);
goto P_0c0a5218;
P_0c0a5218: /* original 9457, guest PC 0x0c0a5218 */
if(!s->budget--) { s->failed_pc=0x0c0a5218u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a52cau,2);
goto P_0c0a521a;
P_0c0a521a: /* original 430b, guest PC 0x0c0a521a */
if(!s->budget--) { s->failed_pc=0x0c0a521au; return 0; }
target=r[3];
r[16]=0x0c0a521eu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a521eu) { target=s->pc; goto dispatch; }
goto P_0c0a521e;
P_0c0a521c: /* original 0009, guest PC 0x0c0a521c */
if(!s->budget--) { s->failed_pc=0x0c0a521cu; return 0; }
goto P_0c0a521e;
P_0c0a521e: /* original d232, guest PC 0x0c0a521e */
if(!s->budget--) { s->failed_pc=0x0c0a521eu; return 0; }
r[2]=read(ram,0x0c0a52e8u,4);
goto P_0c0a5220;
P_0c0a5220: /* original 9454, guest PC 0x0c0a5220 */
if(!s->budget--) { s->failed_pc=0x0c0a5220u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a52ccu,2);
goto P_0c0a5222;
P_0c0a5222: /* original 420b, guest PC 0x0c0a5222 */
if(!s->budget--) { s->failed_pc=0x0c0a5222u; return 0; }
target=r[2];
r[16]=0x0c0a5226u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a5226u) { target=s->pc; goto dispatch; }
goto P_0c0a5226;
P_0c0a5224: /* original 0009, guest PC 0x0c0a5224 */
if(!s->budget--) { s->failed_pc=0x0c0a5224u; return 0; }
goto P_0c0a5226;
P_0c0a5226: /* original d330, guest PC 0x0c0a5226 */
if(!s->budget--) { s->failed_pc=0x0c0a5226u; return 0; }
r[3]=read(ram,0x0c0a52e8u,4);
goto P_0c0a5228;
P_0c0a5228: /* original 9451, guest PC 0x0c0a5228 */
if(!s->budget--) { s->failed_pc=0x0c0a5228u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a52ceu,2);
goto P_0c0a522a;
P_0c0a522a: /* original 430b, guest PC 0x0c0a522a */
if(!s->budget--) { s->failed_pc=0x0c0a522au; return 0; }
target=r[3];
r[16]=0x0c0a522eu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a522eu) { target=s->pc; goto dispatch; }
goto P_0c0a522e;
P_0c0a522c: /* original 0009, guest PC 0x0c0a522c */
if(!s->budget--) { s->failed_pc=0x0c0a522cu; return 0; }
goto P_0c0a522e;
P_0c0a522e: /* original d22e, guest PC 0x0c0a522e */
if(!s->budget--) { s->failed_pc=0x0c0a522eu; return 0; }
r[2]=read(ram,0x0c0a52e8u,4);
goto P_0c0a5230;
P_0c0a5230: /* original 944e, guest PC 0x0c0a5230 */
if(!s->budget--) { s->failed_pc=0x0c0a5230u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a52d0u,2);
goto P_0c0a5232;
P_0c0a5232: /* original 420b, guest PC 0x0c0a5232 */
if(!s->budget--) { s->failed_pc=0x0c0a5232u; return 0; }
target=r[2];
r[16]=0x0c0a5236u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a5236u) { target=s->pc; goto dispatch; }
goto P_0c0a5236;
P_0c0a5234: /* original 0009, guest PC 0x0c0a5234 */
if(!s->budget--) { s->failed_pc=0x0c0a5234u; return 0; }
goto P_0c0a5236;
P_0c0a5236: /* original d32c, guest PC 0x0c0a5236 */
if(!s->budget--) { s->failed_pc=0x0c0a5236u; return 0; }
r[3]=read(ram,0x0c0a52e8u,4);
goto P_0c0a5238;
P_0c0a5238: /* original 944b, guest PC 0x0c0a5238 */
if(!s->budget--) { s->failed_pc=0x0c0a5238u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a52d2u,2);
goto P_0c0a523a;
P_0c0a523a: /* original 430b, guest PC 0x0c0a523a */
if(!s->budget--) { s->failed_pc=0x0c0a523au; return 0; }
target=r[3];
r[16]=0x0c0a523eu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a523eu) { target=s->pc; goto dispatch; }
goto P_0c0a523e;
P_0c0a523c: /* original 0009, guest PC 0x0c0a523c */
if(!s->budget--) { s->failed_pc=0x0c0a523cu; return 0; }
goto P_0c0a523e;
P_0c0a523e: /* original d22a, guest PC 0x0c0a523e */
if(!s->budget--) { s->failed_pc=0x0c0a523eu; return 0; }
r[2]=read(ram,0x0c0a52e8u,4);
goto P_0c0a5240;
P_0c0a5240: /* original 9448, guest PC 0x0c0a5240 */
if(!s->budget--) { s->failed_pc=0x0c0a5240u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a52d4u,2);
goto P_0c0a5242;
P_0c0a5242: /* original 420b, guest PC 0x0c0a5242 */
if(!s->budget--) { s->failed_pc=0x0c0a5242u; return 0; }
target=r[2];
r[16]=0x0c0a5246u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a5246u) { target=s->pc; goto dispatch; }
goto P_0c0a5246;
P_0c0a5244: /* original 0009, guest PC 0x0c0a5244 */
if(!s->budget--) { s->failed_pc=0x0c0a5244u; return 0; }
goto P_0c0a5246;
P_0c0a5246: /* original d328, guest PC 0x0c0a5246 */
if(!s->budget--) { s->failed_pc=0x0c0a5246u; return 0; }
r[3]=read(ram,0x0c0a52e8u,4);
goto P_0c0a5248;
P_0c0a5248: /* original 9445, guest PC 0x0c0a5248 */
if(!s->budget--) { s->failed_pc=0x0c0a5248u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a52d6u,2);
goto P_0c0a524a;
P_0c0a524a: /* original 430b, guest PC 0x0c0a524a */
if(!s->budget--) { s->failed_pc=0x0c0a524au; return 0; }
target=r[3];
r[16]=0x0c0a524eu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a524eu) { target=s->pc; goto dispatch; }
goto P_0c0a524e;
P_0c0a524c: /* original 0009, guest PC 0x0c0a524c */
if(!s->budget--) { s->failed_pc=0x0c0a524cu; return 0; }
goto P_0c0a524e;
P_0c0a524e: /* original d226, guest PC 0x0c0a524e */
if(!s->budget--) { s->failed_pc=0x0c0a524eu; return 0; }
r[2]=read(ram,0x0c0a52e8u,4);
goto P_0c0a5250;
P_0c0a5250: /* original 9442, guest PC 0x0c0a5250 */
if(!s->budget--) { s->failed_pc=0x0c0a5250u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a52d8u,2);
goto P_0c0a5252;
P_0c0a5252: /* original 420b, guest PC 0x0c0a5252 */
if(!s->budget--) { s->failed_pc=0x0c0a5252u; return 0; }
target=r[2];
r[16]=0x0c0a5256u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a5256u) { target=s->pc; goto dispatch; }
goto P_0c0a5256;
P_0c0a5254: /* original 0009, guest PC 0x0c0a5254 */
if(!s->budget--) { s->failed_pc=0x0c0a5254u; return 0; }
goto P_0c0a5256;
P_0c0a5256: /* original d324, guest PC 0x0c0a5256 */
if(!s->budget--) { s->failed_pc=0x0c0a5256u; return 0; }
r[3]=read(ram,0x0c0a52e8u,4);
goto P_0c0a5258;
P_0c0a5258: /* original 943f, guest PC 0x0c0a5258 */
if(!s->budget--) { s->failed_pc=0x0c0a5258u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a52dau,2);
goto P_0c0a525a;
P_0c0a525a: /* original 430b, guest PC 0x0c0a525a */
if(!s->budget--) { s->failed_pc=0x0c0a525au; return 0; }
target=r[3];
r[16]=0x0c0a525eu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a525eu) { target=s->pc; goto dispatch; }
goto P_0c0a525e;
P_0c0a525c: /* original 0009, guest PC 0x0c0a525c */
if(!s->budget--) { s->failed_pc=0x0c0a525cu; return 0; }
goto P_0c0a525e;
P_0c0a525e: /* original d222, guest PC 0x0c0a525e */
if(!s->budget--) { s->failed_pc=0x0c0a525eu; return 0; }
r[2]=read(ram,0x0c0a52e8u,4);
goto P_0c0a5260;
P_0c0a5260: /* original 943c, guest PC 0x0c0a5260 */
if(!s->budget--) { s->failed_pc=0x0c0a5260u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a52dcu,2);
goto P_0c0a5262;
P_0c0a5262: /* original 420b, guest PC 0x0c0a5262 */
if(!s->budget--) { s->failed_pc=0x0c0a5262u; return 0; }
target=r[2];
r[16]=0x0c0a5266u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a5266u) { target=s->pc; goto dispatch; }
goto P_0c0a5266;
P_0c0a5264: /* original 0009, guest PC 0x0c0a5264 */
if(!s->budget--) { s->failed_pc=0x0c0a5264u; return 0; }
goto P_0c0a5266;
P_0c0a5266: /* original d320, guest PC 0x0c0a5266 */
if(!s->budget--) { s->failed_pc=0x0c0a5266u; return 0; }
r[3]=read(ram,0x0c0a52e8u,4);
goto P_0c0a5268;
P_0c0a5268: /* original 9439, guest PC 0x0c0a5268 */
if(!s->budget--) { s->failed_pc=0x0c0a5268u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a52deu,2);
goto P_0c0a526a;
P_0c0a526a: /* original 430b, guest PC 0x0c0a526a */
if(!s->budget--) { s->failed_pc=0x0c0a526au; return 0; }
target=r[3];
r[16]=0x0c0a526eu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a526eu) { target=s->pc; goto dispatch; }
goto P_0c0a526e;
P_0c0a526c: /* original 0009, guest PC 0x0c0a526c */
if(!s->budget--) { s->failed_pc=0x0c0a526cu; return 0; }
goto P_0c0a526e;
P_0c0a526e: /* original d21e, guest PC 0x0c0a526e */
if(!s->budget--) { s->failed_pc=0x0c0a526eu; return 0; }
r[2]=read(ram,0x0c0a52e8u,4);
goto P_0c0a5270;
P_0c0a5270: /* original 9436, guest PC 0x0c0a5270 */
if(!s->budget--) { s->failed_pc=0x0c0a5270u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a52e0u,2);
goto P_0c0a5272;
P_0c0a5272: /* original 420b, guest PC 0x0c0a5272 */
if(!s->budget--) { s->failed_pc=0x0c0a5272u; return 0; }
target=r[2];
r[16]=0x0c0a5276u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a5276u) { target=s->pc; goto dispatch; }
goto P_0c0a5276;
P_0c0a5274: /* original 0009, guest PC 0x0c0a5274 */
if(!s->budget--) { s->failed_pc=0x0c0a5274u; return 0; }
goto P_0c0a5276;
P_0c0a5276: /* original d31c, guest PC 0x0c0a5276 */
if(!s->budget--) { s->failed_pc=0x0c0a5276u; return 0; }
r[3]=read(ram,0x0c0a52e8u,4);
goto P_0c0a5278;
P_0c0a5278: /* original 9433, guest PC 0x0c0a5278 */
if(!s->budget--) { s->failed_pc=0x0c0a5278u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a52e2u,2);
goto P_0c0a527a;
P_0c0a527a: /* original 430b, guest PC 0x0c0a527a */
if(!s->budget--) { s->failed_pc=0x0c0a527au; return 0; }
target=r[3];
r[16]=0x0c0a527eu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a527eu) { target=s->pc; goto dispatch; }
goto P_0c0a527e;
P_0c0a527c: /* original 0009, guest PC 0x0c0a527c */
if(!s->budget--) { s->failed_pc=0x0c0a527cu; return 0; }
goto P_0c0a527e;
P_0c0a527e: /* original d21a, guest PC 0x0c0a527e */
if(!s->budget--) { s->failed_pc=0x0c0a527eu; return 0; }
r[2]=read(ram,0x0c0a52e8u,4);
goto P_0c0a5280;
P_0c0a5280: /* original 9430, guest PC 0x0c0a5280 */
if(!s->budget--) { s->failed_pc=0x0c0a5280u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a52e4u,2);
goto P_0c0a5282;
P_0c0a5282: /* original 420b, guest PC 0x0c0a5282 */
if(!s->budget--) { s->failed_pc=0x0c0a5282u; return 0; }
target=r[2];
r[16]=0x0c0a5286u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a5286u) { target=s->pc; goto dispatch; }
goto P_0c0a5286;
P_0c0a5284: /* original 0009, guest PC 0x0c0a5284 */
if(!s->budget--) { s->failed_pc=0x0c0a5284u; return 0; }
goto P_0c0a5286;
P_0c0a5286: /* original d318, guest PC 0x0c0a5286 */
if(!s->budget--) { s->failed_pc=0x0c0a5286u; return 0; }
r[3]=read(ram,0x0c0a52e8u,4);
goto P_0c0a5288;
P_0c0a5288: /* original 942d, guest PC 0x0c0a5288 */
if(!s->budget--) { s->failed_pc=0x0c0a5288u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a52e6u,2);
goto P_0c0a528a;
P_0c0a528a: /* original 432b, guest PC 0x0c0a528a */
if(!s->budget--) { s->failed_pc=0x0c0a528au; return 0; }
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
P_0c0a528c: /* original 4f26, guest PC 0x0c0a528c */
if(!s->budget--) { s->failed_pc=0x0c0a528cu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
return vf3_matrix_family(0x0c0a528eu,s,ram);
P_0c0a5a3c: /* original 4f22, guest PC 0x0c0a5a3c */
if(!s->budget--) { s->failed_pc=0x0c0a5a3cu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0a5a3e;
P_0c0a5a3e: /* original d343, guest PC 0x0c0a5a3e */
if(!s->budget--) { s->failed_pc=0x0c0a5a3eu; return 0; }
r[3]=read(ram,0x0c0a5b4cu,4);
goto P_0c0a5a40;
P_0c0a5a40: /* original 9469, guest PC 0x0c0a5a40 */
if(!s->budget--) { s->failed_pc=0x0c0a5a40u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a5b16u,2);
goto P_0c0a5a42;
P_0c0a5a42: /* original 430b, guest PC 0x0c0a5a42 */
if(!s->budget--) { s->failed_pc=0x0c0a5a42u; return 0; }
target=r[3];
r[16]=0x0c0a5a46u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a5a46u) { target=s->pc; goto dispatch; }
goto P_0c0a5a46;
P_0c0a5a44: /* original 0009, guest PC 0x0c0a5a44 */
if(!s->budget--) { s->failed_pc=0x0c0a5a44u; return 0; }
goto P_0c0a5a46;
P_0c0a5a46: /* original d241, guest PC 0x0c0a5a46 */
if(!s->budget--) { s->failed_pc=0x0c0a5a46u; return 0; }
r[2]=read(ram,0x0c0a5b4cu,4);
goto P_0c0a5a48;
P_0c0a5a48: /* original 9466, guest PC 0x0c0a5a48 */
if(!s->budget--) { s->failed_pc=0x0c0a5a48u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a5b18u,2);
goto P_0c0a5a4a;
P_0c0a5a4a: /* original 420b, guest PC 0x0c0a5a4a */
if(!s->budget--) { s->failed_pc=0x0c0a5a4au; return 0; }
target=r[2];
r[16]=0x0c0a5a4eu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a5a4eu) { target=s->pc; goto dispatch; }
goto P_0c0a5a4e;
P_0c0a5a4c: /* original 0009, guest PC 0x0c0a5a4c */
if(!s->budget--) { s->failed_pc=0x0c0a5a4cu; return 0; }
goto P_0c0a5a4e;
P_0c0a5a4e: /* original d33f, guest PC 0x0c0a5a4e */
if(!s->budget--) { s->failed_pc=0x0c0a5a4eu; return 0; }
r[3]=read(ram,0x0c0a5b4cu,4);
goto P_0c0a5a50;
P_0c0a5a50: /* original 9463, guest PC 0x0c0a5a50 */
if(!s->budget--) { s->failed_pc=0x0c0a5a50u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a5b1au,2);
goto P_0c0a5a52;
P_0c0a5a52: /* original 430b, guest PC 0x0c0a5a52 */
if(!s->budget--) { s->failed_pc=0x0c0a5a52u; return 0; }
target=r[3];
r[16]=0x0c0a5a56u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a5a56u) { target=s->pc; goto dispatch; }
goto P_0c0a5a56;
P_0c0a5a54: /* original 0009, guest PC 0x0c0a5a54 */
if(!s->budget--) { s->failed_pc=0x0c0a5a54u; return 0; }
goto P_0c0a5a56;
P_0c0a5a56: /* original d23d, guest PC 0x0c0a5a56 */
if(!s->budget--) { s->failed_pc=0x0c0a5a56u; return 0; }
r[2]=read(ram,0x0c0a5b4cu,4);
goto P_0c0a5a58;
P_0c0a5a58: /* original 9460, guest PC 0x0c0a5a58 */
if(!s->budget--) { s->failed_pc=0x0c0a5a58u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a5b1cu,2);
goto P_0c0a5a5a;
P_0c0a5a5a: /* original 420b, guest PC 0x0c0a5a5a */
if(!s->budget--) { s->failed_pc=0x0c0a5a5au; return 0; }
target=r[2];
r[16]=0x0c0a5a5eu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a5a5eu) { target=s->pc; goto dispatch; }
goto P_0c0a5a5e;
P_0c0a5a5c: /* original 0009, guest PC 0x0c0a5a5c */
if(!s->budget--) { s->failed_pc=0x0c0a5a5cu; return 0; }
goto P_0c0a5a5e;
P_0c0a5a5e: /* original d33b, guest PC 0x0c0a5a5e */
if(!s->budget--) { s->failed_pc=0x0c0a5a5eu; return 0; }
r[3]=read(ram,0x0c0a5b4cu,4);
goto P_0c0a5a60;
P_0c0a5a60: /* original 945d, guest PC 0x0c0a5a60 */
if(!s->budget--) { s->failed_pc=0x0c0a5a60u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a5b1eu,2);
goto P_0c0a5a62;
P_0c0a5a62: /* original 430b, guest PC 0x0c0a5a62 */
if(!s->budget--) { s->failed_pc=0x0c0a5a62u; return 0; }
target=r[3];
r[16]=0x0c0a5a66u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a5a66u) { target=s->pc; goto dispatch; }
goto P_0c0a5a66;
P_0c0a5a64: /* original 0009, guest PC 0x0c0a5a64 */
if(!s->budget--) { s->failed_pc=0x0c0a5a64u; return 0; }
goto P_0c0a5a66;
P_0c0a5a66: /* original d239, guest PC 0x0c0a5a66 */
if(!s->budget--) { s->failed_pc=0x0c0a5a66u; return 0; }
r[2]=read(ram,0x0c0a5b4cu,4);
goto P_0c0a5a68;
P_0c0a5a68: /* original 945a, guest PC 0x0c0a5a68 */
if(!s->budget--) { s->failed_pc=0x0c0a5a68u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a5b20u,2);
goto P_0c0a5a6a;
P_0c0a5a6a: /* original 420b, guest PC 0x0c0a5a6a */
if(!s->budget--) { s->failed_pc=0x0c0a5a6au; return 0; }
target=r[2];
r[16]=0x0c0a5a6eu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a5a6eu) { target=s->pc; goto dispatch; }
goto P_0c0a5a6e;
P_0c0a5a6c: /* original 0009, guest PC 0x0c0a5a6c */
if(!s->budget--) { s->failed_pc=0x0c0a5a6cu; return 0; }
goto P_0c0a5a6e;
P_0c0a5a6e: /* original d337, guest PC 0x0c0a5a6e */
if(!s->budget--) { s->failed_pc=0x0c0a5a6eu; return 0; }
r[3]=read(ram,0x0c0a5b4cu,4);
goto P_0c0a5a70;
P_0c0a5a70: /* original 9457, guest PC 0x0c0a5a70 */
if(!s->budget--) { s->failed_pc=0x0c0a5a70u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a5b22u,2);
goto P_0c0a5a72;
P_0c0a5a72: /* original 430b, guest PC 0x0c0a5a72 */
if(!s->budget--) { s->failed_pc=0x0c0a5a72u; return 0; }
target=r[3];
r[16]=0x0c0a5a76u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a5a76u) { target=s->pc; goto dispatch; }
goto P_0c0a5a76;
P_0c0a5a74: /* original 0009, guest PC 0x0c0a5a74 */
if(!s->budget--) { s->failed_pc=0x0c0a5a74u; return 0; }
goto P_0c0a5a76;
P_0c0a5a76: /* original d235, guest PC 0x0c0a5a76 */
if(!s->budget--) { s->failed_pc=0x0c0a5a76u; return 0; }
r[2]=read(ram,0x0c0a5b4cu,4);
goto P_0c0a5a78;
P_0c0a5a78: /* original 9454, guest PC 0x0c0a5a78 */
if(!s->budget--) { s->failed_pc=0x0c0a5a78u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a5b24u,2);
goto P_0c0a5a7a;
P_0c0a5a7a: /* original 420b, guest PC 0x0c0a5a7a */
if(!s->budget--) { s->failed_pc=0x0c0a5a7au; return 0; }
target=r[2];
r[16]=0x0c0a5a7eu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a5a7eu) { target=s->pc; goto dispatch; }
goto P_0c0a5a7e;
P_0c0a5a7c: /* original 0009, guest PC 0x0c0a5a7c */
if(!s->budget--) { s->failed_pc=0x0c0a5a7cu; return 0; }
goto P_0c0a5a7e;
P_0c0a5a7e: /* original d333, guest PC 0x0c0a5a7e */
if(!s->budget--) { s->failed_pc=0x0c0a5a7eu; return 0; }
r[3]=read(ram,0x0c0a5b4cu,4);
goto P_0c0a5a80;
P_0c0a5a80: /* original 9451, guest PC 0x0c0a5a80 */
if(!s->budget--) { s->failed_pc=0x0c0a5a80u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a5b26u,2);
goto P_0c0a5a82;
P_0c0a5a82: /* original 430b, guest PC 0x0c0a5a82 */
if(!s->budget--) { s->failed_pc=0x0c0a5a82u; return 0; }
target=r[3];
r[16]=0x0c0a5a86u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a5a86u) { target=s->pc; goto dispatch; }
goto P_0c0a5a86;
P_0c0a5a84: /* original 0009, guest PC 0x0c0a5a84 */
if(!s->budget--) { s->failed_pc=0x0c0a5a84u; return 0; }
goto P_0c0a5a86;
P_0c0a5a86: /* original d231, guest PC 0x0c0a5a86 */
if(!s->budget--) { s->failed_pc=0x0c0a5a86u; return 0; }
r[2]=read(ram,0x0c0a5b4cu,4);
goto P_0c0a5a88;
P_0c0a5a88: /* original 944e, guest PC 0x0c0a5a88 */
if(!s->budget--) { s->failed_pc=0x0c0a5a88u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a5b28u,2);
goto P_0c0a5a8a;
P_0c0a5a8a: /* original 420b, guest PC 0x0c0a5a8a */
if(!s->budget--) { s->failed_pc=0x0c0a5a8au; return 0; }
target=r[2];
r[16]=0x0c0a5a8eu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a5a8eu) { target=s->pc; goto dispatch; }
goto P_0c0a5a8e;
P_0c0a5a8c: /* original 0009, guest PC 0x0c0a5a8c */
if(!s->budget--) { s->failed_pc=0x0c0a5a8cu; return 0; }
goto P_0c0a5a8e;
P_0c0a5a8e: /* original d32f, guest PC 0x0c0a5a8e */
if(!s->budget--) { s->failed_pc=0x0c0a5a8eu; return 0; }
r[3]=read(ram,0x0c0a5b4cu,4);
goto P_0c0a5a90;
P_0c0a5a90: /* original 944b, guest PC 0x0c0a5a90 */
if(!s->budget--) { s->failed_pc=0x0c0a5a90u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a5b2au,2);
goto P_0c0a5a92;
P_0c0a5a92: /* original 430b, guest PC 0x0c0a5a92 */
if(!s->budget--) { s->failed_pc=0x0c0a5a92u; return 0; }
target=r[3];
r[16]=0x0c0a5a96u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a5a96u) { target=s->pc; goto dispatch; }
goto P_0c0a5a96;
P_0c0a5a94: /* original 0009, guest PC 0x0c0a5a94 */
if(!s->budget--) { s->failed_pc=0x0c0a5a94u; return 0; }
goto P_0c0a5a96;
P_0c0a5a96: /* original d22d, guest PC 0x0c0a5a96 */
if(!s->budget--) { s->failed_pc=0x0c0a5a96u; return 0; }
r[2]=read(ram,0x0c0a5b4cu,4);
goto P_0c0a5a98;
P_0c0a5a98: /* original 9448, guest PC 0x0c0a5a98 */
if(!s->budget--) { s->failed_pc=0x0c0a5a98u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a5b2cu,2);
goto P_0c0a5a9a;
P_0c0a5a9a: /* original 420b, guest PC 0x0c0a5a9a */
if(!s->budget--) { s->failed_pc=0x0c0a5a9au; return 0; }
target=r[2];
r[16]=0x0c0a5a9eu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a5a9eu) { target=s->pc; goto dispatch; }
goto P_0c0a5a9e;
P_0c0a5a9c: /* original 0009, guest PC 0x0c0a5a9c */
if(!s->budget--) { s->failed_pc=0x0c0a5a9cu; return 0; }
goto P_0c0a5a9e;
P_0c0a5a9e: /* original d32b, guest PC 0x0c0a5a9e */
if(!s->budget--) { s->failed_pc=0x0c0a5a9eu; return 0; }
r[3]=read(ram,0x0c0a5b4cu,4);
goto P_0c0a5aa0;
P_0c0a5aa0: /* original 9445, guest PC 0x0c0a5aa0 */
if(!s->budget--) { s->failed_pc=0x0c0a5aa0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a5b2eu,2);
goto P_0c0a5aa2;
P_0c0a5aa2: /* original 430b, guest PC 0x0c0a5aa2 */
if(!s->budget--) { s->failed_pc=0x0c0a5aa2u; return 0; }
target=r[3];
r[16]=0x0c0a5aa6u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a5aa6u) { target=s->pc; goto dispatch; }
goto P_0c0a5aa6;
P_0c0a5aa4: /* original 0009, guest PC 0x0c0a5aa4 */
if(!s->budget--) { s->failed_pc=0x0c0a5aa4u; return 0; }
goto P_0c0a5aa6;
P_0c0a5aa6: /* original d229, guest PC 0x0c0a5aa6 */
if(!s->budget--) { s->failed_pc=0x0c0a5aa6u; return 0; }
r[2]=read(ram,0x0c0a5b4cu,4);
goto P_0c0a5aa8;
P_0c0a5aa8: /* original 9442, guest PC 0x0c0a5aa8 */
if(!s->budget--) { s->failed_pc=0x0c0a5aa8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a5b30u,2);
goto P_0c0a5aaa;
P_0c0a5aaa: /* original 420b, guest PC 0x0c0a5aaa */
if(!s->budget--) { s->failed_pc=0x0c0a5aaau; return 0; }
target=r[2];
r[16]=0x0c0a5aaeu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a5aaeu) { target=s->pc; goto dispatch; }
goto P_0c0a5aae;
P_0c0a5aac: /* original 0009, guest PC 0x0c0a5aac */
if(!s->budget--) { s->failed_pc=0x0c0a5aacu; return 0; }
goto P_0c0a5aae;
P_0c0a5aae: /* original d327, guest PC 0x0c0a5aae */
if(!s->budget--) { s->failed_pc=0x0c0a5aaeu; return 0; }
r[3]=read(ram,0x0c0a5b4cu,4);
goto P_0c0a5ab0;
P_0c0a5ab0: /* original 943f, guest PC 0x0c0a5ab0 */
if(!s->budget--) { s->failed_pc=0x0c0a5ab0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a5b32u,2);
goto P_0c0a5ab2;
P_0c0a5ab2: /* original 430b, guest PC 0x0c0a5ab2 */
if(!s->budget--) { s->failed_pc=0x0c0a5ab2u; return 0; }
target=r[3];
r[16]=0x0c0a5ab6u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a5ab6u) { target=s->pc; goto dispatch; }
goto P_0c0a5ab6;
P_0c0a5ab4: /* original 0009, guest PC 0x0c0a5ab4 */
if(!s->budget--) { s->failed_pc=0x0c0a5ab4u; return 0; }
goto P_0c0a5ab6;
P_0c0a5ab6: /* original d225, guest PC 0x0c0a5ab6 */
if(!s->budget--) { s->failed_pc=0x0c0a5ab6u; return 0; }
r[2]=read(ram,0x0c0a5b4cu,4);
goto P_0c0a5ab8;
P_0c0a5ab8: /* original 943c, guest PC 0x0c0a5ab8 */
if(!s->budget--) { s->failed_pc=0x0c0a5ab8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a5b34u,2);
goto P_0c0a5aba;
P_0c0a5aba: /* original 420b, guest PC 0x0c0a5aba */
if(!s->budget--) { s->failed_pc=0x0c0a5abau; return 0; }
target=r[2];
r[16]=0x0c0a5abeu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a5abeu) { target=s->pc; goto dispatch; }
goto P_0c0a5abe;
P_0c0a5abc: /* original 0009, guest PC 0x0c0a5abc */
if(!s->budget--) { s->failed_pc=0x0c0a5abcu; return 0; }
goto P_0c0a5abe;
P_0c0a5abe: /* original d323, guest PC 0x0c0a5abe */
if(!s->budget--) { s->failed_pc=0x0c0a5abeu; return 0; }
r[3]=read(ram,0x0c0a5b4cu,4);
goto P_0c0a5ac0;
P_0c0a5ac0: /* original 9439, guest PC 0x0c0a5ac0 */
if(!s->budget--) { s->failed_pc=0x0c0a5ac0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a5b36u,2);
goto P_0c0a5ac2;
P_0c0a5ac2: /* original 430b, guest PC 0x0c0a5ac2 */
if(!s->budget--) { s->failed_pc=0x0c0a5ac2u; return 0; }
target=r[3];
r[16]=0x0c0a5ac6u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a5ac6u) { target=s->pc; goto dispatch; }
goto P_0c0a5ac6;
P_0c0a5ac4: /* original 0009, guest PC 0x0c0a5ac4 */
if(!s->budget--) { s->failed_pc=0x0c0a5ac4u; return 0; }
goto P_0c0a5ac6;
P_0c0a5ac6: /* original d221, guest PC 0x0c0a5ac6 */
if(!s->budget--) { s->failed_pc=0x0c0a5ac6u; return 0; }
r[2]=read(ram,0x0c0a5b4cu,4);
goto P_0c0a5ac8;
P_0c0a5ac8: /* original 9436, guest PC 0x0c0a5ac8 */
if(!s->budget--) { s->failed_pc=0x0c0a5ac8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a5b38u,2);
goto P_0c0a5aca;
P_0c0a5aca: /* original 420b, guest PC 0x0c0a5aca */
if(!s->budget--) { s->failed_pc=0x0c0a5acau; return 0; }
target=r[2];
r[16]=0x0c0a5aceu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a5aceu) { target=s->pc; goto dispatch; }
goto P_0c0a5ace;
P_0c0a5acc: /* original 0009, guest PC 0x0c0a5acc */
if(!s->budget--) { s->failed_pc=0x0c0a5accu; return 0; }
goto P_0c0a5ace;
P_0c0a5ace: /* original d31f, guest PC 0x0c0a5ace */
if(!s->budget--) { s->failed_pc=0x0c0a5aceu; return 0; }
r[3]=read(ram,0x0c0a5b4cu,4);
goto P_0c0a5ad0;
P_0c0a5ad0: /* original 9433, guest PC 0x0c0a5ad0 */
if(!s->budget--) { s->failed_pc=0x0c0a5ad0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a5b3au,2);
goto P_0c0a5ad2;
P_0c0a5ad2: /* original 430b, guest PC 0x0c0a5ad2 */
if(!s->budget--) { s->failed_pc=0x0c0a5ad2u; return 0; }
target=r[3];
r[16]=0x0c0a5ad6u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a5ad6u) { target=s->pc; goto dispatch; }
goto P_0c0a5ad6;
P_0c0a5ad4: /* original 0009, guest PC 0x0c0a5ad4 */
if(!s->budget--) { s->failed_pc=0x0c0a5ad4u; return 0; }
goto P_0c0a5ad6;
P_0c0a5ad6: /* original d21d, guest PC 0x0c0a5ad6 */
if(!s->budget--) { s->failed_pc=0x0c0a5ad6u; return 0; }
r[2]=read(ram,0x0c0a5b4cu,4);
goto P_0c0a5ad8;
P_0c0a5ad8: /* original 9430, guest PC 0x0c0a5ad8 */
if(!s->budget--) { s->failed_pc=0x0c0a5ad8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a5b3cu,2);
goto P_0c0a5ada;
P_0c0a5ada: /* original 420b, guest PC 0x0c0a5ada */
if(!s->budget--) { s->failed_pc=0x0c0a5adau; return 0; }
target=r[2];
r[16]=0x0c0a5adeu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a5adeu) { target=s->pc; goto dispatch; }
goto P_0c0a5ade;
P_0c0a5adc: /* original 0009, guest PC 0x0c0a5adc */
if(!s->budget--) { s->failed_pc=0x0c0a5adcu; return 0; }
goto P_0c0a5ade;
P_0c0a5ade: /* original d31b, guest PC 0x0c0a5ade */
if(!s->budget--) { s->failed_pc=0x0c0a5adeu; return 0; }
r[3]=read(ram,0x0c0a5b4cu,4);
goto P_0c0a5ae0;
P_0c0a5ae0: /* original 942d, guest PC 0x0c0a5ae0 */
if(!s->budget--) { s->failed_pc=0x0c0a5ae0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a5b3eu,2);
goto P_0c0a5ae2;
P_0c0a5ae2: /* original 430b, guest PC 0x0c0a5ae2 */
if(!s->budget--) { s->failed_pc=0x0c0a5ae2u; return 0; }
target=r[3];
r[16]=0x0c0a5ae6u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a5ae6u) { target=s->pc; goto dispatch; }
goto P_0c0a5ae6;
P_0c0a5ae4: /* original 0009, guest PC 0x0c0a5ae4 */
if(!s->budget--) { s->failed_pc=0x0c0a5ae4u; return 0; }
goto P_0c0a5ae6;
P_0c0a5ae6: /* original d219, guest PC 0x0c0a5ae6 */
if(!s->budget--) { s->failed_pc=0x0c0a5ae6u; return 0; }
r[2]=read(ram,0x0c0a5b4cu,4);
goto P_0c0a5ae8;
P_0c0a5ae8: /* original 942a, guest PC 0x0c0a5ae8 */
if(!s->budget--) { s->failed_pc=0x0c0a5ae8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a5b40u,2);
goto P_0c0a5aea;
P_0c0a5aea: /* original 420b, guest PC 0x0c0a5aea */
if(!s->budget--) { s->failed_pc=0x0c0a5aeau; return 0; }
target=r[2];
r[16]=0x0c0a5aeeu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a5aeeu) { target=s->pc; goto dispatch; }
goto P_0c0a5aee;
P_0c0a5aec: /* original 0009, guest PC 0x0c0a5aec */
if(!s->budget--) { s->failed_pc=0x0c0a5aecu; return 0; }
goto P_0c0a5aee;
P_0c0a5aee: /* original d317, guest PC 0x0c0a5aee */
if(!s->budget--) { s->failed_pc=0x0c0a5aeeu; return 0; }
r[3]=read(ram,0x0c0a5b4cu,4);
goto P_0c0a5af0;
P_0c0a5af0: /* original 9427, guest PC 0x0c0a5af0 */
if(!s->budget--) { s->failed_pc=0x0c0a5af0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a5b42u,2);
goto P_0c0a5af2;
P_0c0a5af2: /* original 430b, guest PC 0x0c0a5af2 */
if(!s->budget--) { s->failed_pc=0x0c0a5af2u; return 0; }
target=r[3];
r[16]=0x0c0a5af6u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a5af6u) { target=s->pc; goto dispatch; }
goto P_0c0a5af6;
P_0c0a5af4: /* original 0009, guest PC 0x0c0a5af4 */
if(!s->budget--) { s->failed_pc=0x0c0a5af4u; return 0; }
goto P_0c0a5af6;
P_0c0a5af6: /* original d215, guest PC 0x0c0a5af6 */
if(!s->budget--) { s->failed_pc=0x0c0a5af6u; return 0; }
r[2]=read(ram,0x0c0a5b4cu,4);
goto P_0c0a5af8;
P_0c0a5af8: /* original 9424, guest PC 0x0c0a5af8 */
if(!s->budget--) { s->failed_pc=0x0c0a5af8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a5b44u,2);
goto P_0c0a5afa;
P_0c0a5afa: /* original 420b, guest PC 0x0c0a5afa */
if(!s->budget--) { s->failed_pc=0x0c0a5afau; return 0; }
target=r[2];
r[16]=0x0c0a5afeu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a5afeu) { target=s->pc; goto dispatch; }
goto P_0c0a5afe;
P_0c0a5afc: /* original 0009, guest PC 0x0c0a5afc */
if(!s->budget--) { s->failed_pc=0x0c0a5afcu; return 0; }
goto P_0c0a5afe;
P_0c0a5afe: /* original d313, guest PC 0x0c0a5afe */
if(!s->budget--) { s->failed_pc=0x0c0a5afeu; return 0; }
r[3]=read(ram,0x0c0a5b4cu,4);
goto P_0c0a5b00;
P_0c0a5b00: /* original 9421, guest PC 0x0c0a5b00 */
if(!s->budget--) { s->failed_pc=0x0c0a5b00u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a5b46u,2);
goto P_0c0a5b02;
P_0c0a5b02: /* original 430b, guest PC 0x0c0a5b02 */
if(!s->budget--) { s->failed_pc=0x0c0a5b02u; return 0; }
target=r[3];
r[16]=0x0c0a5b06u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a5b06u) { target=s->pc; goto dispatch; }
goto P_0c0a5b06;
P_0c0a5b04: /* original 0009, guest PC 0x0c0a5b04 */
if(!s->budget--) { s->failed_pc=0x0c0a5b04u; return 0; }
goto P_0c0a5b06;
P_0c0a5b06: /* original d211, guest PC 0x0c0a5b06 */
if(!s->budget--) { s->failed_pc=0x0c0a5b06u; return 0; }
r[2]=read(ram,0x0c0a5b4cu,4);
goto P_0c0a5b08;
P_0c0a5b08: /* original 941e, guest PC 0x0c0a5b08 */
if(!s->budget--) { s->failed_pc=0x0c0a5b08u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a5b48u,2);
goto P_0c0a5b0a;
P_0c0a5b0a: /* original 420b, guest PC 0x0c0a5b0a */
if(!s->budget--) { s->failed_pc=0x0c0a5b0au; return 0; }
target=r[2];
r[16]=0x0c0a5b0eu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a5b0eu) { target=s->pc; goto dispatch; }
goto P_0c0a5b0e;
P_0c0a5b0c: /* original 0009, guest PC 0x0c0a5b0c */
if(!s->budget--) { s->failed_pc=0x0c0a5b0cu; return 0; }
goto P_0c0a5b0e;
P_0c0a5b0e: /* original d30f, guest PC 0x0c0a5b0e */
if(!s->budget--) { s->failed_pc=0x0c0a5b0eu; return 0; }
r[3]=read(ram,0x0c0a5b4cu,4);
goto P_0c0a5b10;
P_0c0a5b10: /* original 941b, guest PC 0x0c0a5b10 */
if(!s->budget--) { s->failed_pc=0x0c0a5b10u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a5b4au,2);
goto P_0c0a5b12;
P_0c0a5b12: /* original 432b, guest PC 0x0c0a5b12 */
if(!s->budget--) { s->failed_pc=0x0c0a5b12u; return 0; }
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
P_0c0a5b14: /* original 4f26, guest PC 0x0c0a5b14 */
if(!s->budget--) { s->failed_pc=0x0c0a5b14u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
return vf3_matrix_family(0x0c0a5b16u,s,ram);
P_0c0a5c8c: /* original 4f22, guest PC 0x0c0a5c8c */
if(!s->budget--) { s->failed_pc=0x0c0a5c8cu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0a5c8e;
P_0c0a5c8e: /* original d341, guest PC 0x0c0a5c8e */
if(!s->budget--) { s->failed_pc=0x0c0a5c8eu; return 0; }
r[3]=read(ram,0x0c0a5d94u,4);
goto P_0c0a5c90;
P_0c0a5c90: /* original 9465, guest PC 0x0c0a5c90 */
if(!s->budget--) { s->failed_pc=0x0c0a5c90u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a5d5eu,2);
goto P_0c0a5c92;
P_0c0a5c92: /* original 430b, guest PC 0x0c0a5c92 */
if(!s->budget--) { s->failed_pc=0x0c0a5c92u; return 0; }
target=r[3];
r[16]=0x0c0a5c96u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a5c96u) { target=s->pc; goto dispatch; }
goto P_0c0a5c96;
P_0c0a5c94: /* original 0009, guest PC 0x0c0a5c94 */
if(!s->budget--) { s->failed_pc=0x0c0a5c94u; return 0; }
goto P_0c0a5c96;
P_0c0a5c96: /* original d23f, guest PC 0x0c0a5c96 */
if(!s->budget--) { s->failed_pc=0x0c0a5c96u; return 0; }
r[2]=read(ram,0x0c0a5d94u,4);
goto P_0c0a5c98;
P_0c0a5c98: /* original 9462, guest PC 0x0c0a5c98 */
if(!s->budget--) { s->failed_pc=0x0c0a5c98u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a5d60u,2);
goto P_0c0a5c9a;
P_0c0a5c9a: /* original 420b, guest PC 0x0c0a5c9a */
if(!s->budget--) { s->failed_pc=0x0c0a5c9au; return 0; }
target=r[2];
r[16]=0x0c0a5c9eu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a5c9eu) { target=s->pc; goto dispatch; }
goto P_0c0a5c9e;
P_0c0a5c9c: /* original 0009, guest PC 0x0c0a5c9c */
if(!s->budget--) { s->failed_pc=0x0c0a5c9cu; return 0; }
goto P_0c0a5c9e;
P_0c0a5c9e: /* original d33d, guest PC 0x0c0a5c9e */
if(!s->budget--) { s->failed_pc=0x0c0a5c9eu; return 0; }
r[3]=read(ram,0x0c0a5d94u,4);
goto P_0c0a5ca0;
P_0c0a5ca0: /* original 945f, guest PC 0x0c0a5ca0 */
if(!s->budget--) { s->failed_pc=0x0c0a5ca0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a5d62u,2);
goto P_0c0a5ca2;
P_0c0a5ca2: /* original 430b, guest PC 0x0c0a5ca2 */
if(!s->budget--) { s->failed_pc=0x0c0a5ca2u; return 0; }
target=r[3];
r[16]=0x0c0a5ca6u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a5ca6u) { target=s->pc; goto dispatch; }
goto P_0c0a5ca6;
P_0c0a5ca4: /* original 0009, guest PC 0x0c0a5ca4 */
if(!s->budget--) { s->failed_pc=0x0c0a5ca4u; return 0; }
goto P_0c0a5ca6;
P_0c0a5ca6: /* original d23b, guest PC 0x0c0a5ca6 */
if(!s->budget--) { s->failed_pc=0x0c0a5ca6u; return 0; }
r[2]=read(ram,0x0c0a5d94u,4);
goto P_0c0a5ca8;
P_0c0a5ca8: /* original 945c, guest PC 0x0c0a5ca8 */
if(!s->budget--) { s->failed_pc=0x0c0a5ca8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a5d64u,2);
goto P_0c0a5caa;
P_0c0a5caa: /* original 420b, guest PC 0x0c0a5caa */
if(!s->budget--) { s->failed_pc=0x0c0a5caau; return 0; }
target=r[2];
r[16]=0x0c0a5caeu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a5caeu) { target=s->pc; goto dispatch; }
goto P_0c0a5cae;
P_0c0a5cac: /* original 0009, guest PC 0x0c0a5cac */
if(!s->budget--) { s->failed_pc=0x0c0a5cacu; return 0; }
goto P_0c0a5cae;
P_0c0a5cae: /* original d339, guest PC 0x0c0a5cae */
if(!s->budget--) { s->failed_pc=0x0c0a5caeu; return 0; }
r[3]=read(ram,0x0c0a5d94u,4);
goto P_0c0a5cb0;
P_0c0a5cb0: /* original 9459, guest PC 0x0c0a5cb0 */
if(!s->budget--) { s->failed_pc=0x0c0a5cb0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a5d66u,2);
goto P_0c0a5cb2;
P_0c0a5cb2: /* original 430b, guest PC 0x0c0a5cb2 */
if(!s->budget--) { s->failed_pc=0x0c0a5cb2u; return 0; }
target=r[3];
r[16]=0x0c0a5cb6u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a5cb6u) { target=s->pc; goto dispatch; }
goto P_0c0a5cb6;
P_0c0a5cb4: /* original 0009, guest PC 0x0c0a5cb4 */
if(!s->budget--) { s->failed_pc=0x0c0a5cb4u; return 0; }
goto P_0c0a5cb6;
P_0c0a5cb6: /* original d237, guest PC 0x0c0a5cb6 */
if(!s->budget--) { s->failed_pc=0x0c0a5cb6u; return 0; }
r[2]=read(ram,0x0c0a5d94u,4);
goto P_0c0a5cb8;
P_0c0a5cb8: /* original 9456, guest PC 0x0c0a5cb8 */
if(!s->budget--) { s->failed_pc=0x0c0a5cb8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a5d68u,2);
goto P_0c0a5cba;
P_0c0a5cba: /* original 420b, guest PC 0x0c0a5cba */
if(!s->budget--) { s->failed_pc=0x0c0a5cbau; return 0; }
target=r[2];
r[16]=0x0c0a5cbeu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a5cbeu) { target=s->pc; goto dispatch; }
goto P_0c0a5cbe;
P_0c0a5cbc: /* original 0009, guest PC 0x0c0a5cbc */
if(!s->budget--) { s->failed_pc=0x0c0a5cbcu; return 0; }
goto P_0c0a5cbe;
P_0c0a5cbe: /* original d335, guest PC 0x0c0a5cbe */
if(!s->budget--) { s->failed_pc=0x0c0a5cbeu; return 0; }
r[3]=read(ram,0x0c0a5d94u,4);
goto P_0c0a5cc0;
P_0c0a5cc0: /* original 9453, guest PC 0x0c0a5cc0 */
if(!s->budget--) { s->failed_pc=0x0c0a5cc0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a5d6au,2);
goto P_0c0a5cc2;
P_0c0a5cc2: /* original 430b, guest PC 0x0c0a5cc2 */
if(!s->budget--) { s->failed_pc=0x0c0a5cc2u; return 0; }
target=r[3];
r[16]=0x0c0a5cc6u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a5cc6u) { target=s->pc; goto dispatch; }
goto P_0c0a5cc6;
P_0c0a5cc4: /* original 0009, guest PC 0x0c0a5cc4 */
if(!s->budget--) { s->failed_pc=0x0c0a5cc4u; return 0; }
goto P_0c0a5cc6;
P_0c0a5cc6: /* original d233, guest PC 0x0c0a5cc6 */
if(!s->budget--) { s->failed_pc=0x0c0a5cc6u; return 0; }
r[2]=read(ram,0x0c0a5d94u,4);
goto P_0c0a5cc8;
P_0c0a5cc8: /* original 9450, guest PC 0x0c0a5cc8 */
if(!s->budget--) { s->failed_pc=0x0c0a5cc8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a5d6cu,2);
goto P_0c0a5cca;
P_0c0a5cca: /* original 420b, guest PC 0x0c0a5cca */
if(!s->budget--) { s->failed_pc=0x0c0a5ccau; return 0; }
target=r[2];
r[16]=0x0c0a5cceu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a5cceu) { target=s->pc; goto dispatch; }
goto P_0c0a5cce;
P_0c0a5ccc: /* original 0009, guest PC 0x0c0a5ccc */
if(!s->budget--) { s->failed_pc=0x0c0a5cccu; return 0; }
goto P_0c0a5cce;
P_0c0a5cce: /* original d331, guest PC 0x0c0a5cce */
if(!s->budget--) { s->failed_pc=0x0c0a5cceu; return 0; }
r[3]=read(ram,0x0c0a5d94u,4);
goto P_0c0a5cd0;
P_0c0a5cd0: /* original 944d, guest PC 0x0c0a5cd0 */
if(!s->budget--) { s->failed_pc=0x0c0a5cd0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a5d6eu,2);
goto P_0c0a5cd2;
P_0c0a5cd2: /* original 430b, guest PC 0x0c0a5cd2 */
if(!s->budget--) { s->failed_pc=0x0c0a5cd2u; return 0; }
target=r[3];
r[16]=0x0c0a5cd6u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a5cd6u) { target=s->pc; goto dispatch; }
goto P_0c0a5cd6;
P_0c0a5cd4: /* original 0009, guest PC 0x0c0a5cd4 */
if(!s->budget--) { s->failed_pc=0x0c0a5cd4u; return 0; }
goto P_0c0a5cd6;
P_0c0a5cd6: /* original d22f, guest PC 0x0c0a5cd6 */
if(!s->budget--) { s->failed_pc=0x0c0a5cd6u; return 0; }
r[2]=read(ram,0x0c0a5d94u,4);
goto P_0c0a5cd8;
P_0c0a5cd8: /* original 944a, guest PC 0x0c0a5cd8 */
if(!s->budget--) { s->failed_pc=0x0c0a5cd8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a5d70u,2);
goto P_0c0a5cda;
P_0c0a5cda: /* original 420b, guest PC 0x0c0a5cda */
if(!s->budget--) { s->failed_pc=0x0c0a5cdau; return 0; }
target=r[2];
r[16]=0x0c0a5cdeu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a5cdeu) { target=s->pc; goto dispatch; }
goto P_0c0a5cde;
P_0c0a5cdc: /* original 0009, guest PC 0x0c0a5cdc */
if(!s->budget--) { s->failed_pc=0x0c0a5cdcu; return 0; }
goto P_0c0a5cde;
P_0c0a5cde: /* original d32d, guest PC 0x0c0a5cde */
if(!s->budget--) { s->failed_pc=0x0c0a5cdeu; return 0; }
r[3]=read(ram,0x0c0a5d94u,4);
goto P_0c0a5ce0;
P_0c0a5ce0: /* original 9447, guest PC 0x0c0a5ce0 */
if(!s->budget--) { s->failed_pc=0x0c0a5ce0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a5d72u,2);
goto P_0c0a5ce2;
P_0c0a5ce2: /* original 430b, guest PC 0x0c0a5ce2 */
if(!s->budget--) { s->failed_pc=0x0c0a5ce2u; return 0; }
target=r[3];
r[16]=0x0c0a5ce6u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a5ce6u) { target=s->pc; goto dispatch; }
goto P_0c0a5ce6;
P_0c0a5ce4: /* original 0009, guest PC 0x0c0a5ce4 */
if(!s->budget--) { s->failed_pc=0x0c0a5ce4u; return 0; }
goto P_0c0a5ce6;
P_0c0a5ce6: /* original d22b, guest PC 0x0c0a5ce6 */
if(!s->budget--) { s->failed_pc=0x0c0a5ce6u; return 0; }
r[2]=read(ram,0x0c0a5d94u,4);
goto P_0c0a5ce8;
P_0c0a5ce8: /* original 9444, guest PC 0x0c0a5ce8 */
if(!s->budget--) { s->failed_pc=0x0c0a5ce8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a5d74u,2);
goto P_0c0a5cea;
P_0c0a5cea: /* original 420b, guest PC 0x0c0a5cea */
if(!s->budget--) { s->failed_pc=0x0c0a5ceau; return 0; }
target=r[2];
r[16]=0x0c0a5ceeu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a5ceeu) { target=s->pc; goto dispatch; }
goto P_0c0a5cee;
P_0c0a5cec: /* original 0009, guest PC 0x0c0a5cec */
if(!s->budget--) { s->failed_pc=0x0c0a5cecu; return 0; }
goto P_0c0a5cee;
P_0c0a5cee: /* original d329, guest PC 0x0c0a5cee */
if(!s->budget--) { s->failed_pc=0x0c0a5ceeu; return 0; }
r[3]=read(ram,0x0c0a5d94u,4);
goto P_0c0a5cf0;
P_0c0a5cf0: /* original 9441, guest PC 0x0c0a5cf0 */
if(!s->budget--) { s->failed_pc=0x0c0a5cf0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a5d76u,2);
goto P_0c0a5cf2;
P_0c0a5cf2: /* original 430b, guest PC 0x0c0a5cf2 */
if(!s->budget--) { s->failed_pc=0x0c0a5cf2u; return 0; }
target=r[3];
r[16]=0x0c0a5cf6u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a5cf6u) { target=s->pc; goto dispatch; }
goto P_0c0a5cf6;
P_0c0a5cf4: /* original 0009, guest PC 0x0c0a5cf4 */
if(!s->budget--) { s->failed_pc=0x0c0a5cf4u; return 0; }
goto P_0c0a5cf6;
P_0c0a5cf6: /* original d227, guest PC 0x0c0a5cf6 */
if(!s->budget--) { s->failed_pc=0x0c0a5cf6u; return 0; }
r[2]=read(ram,0x0c0a5d94u,4);
goto P_0c0a5cf8;
P_0c0a5cf8: /* original 943e, guest PC 0x0c0a5cf8 */
if(!s->budget--) { s->failed_pc=0x0c0a5cf8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a5d78u,2);
goto P_0c0a5cfa;
P_0c0a5cfa: /* original 420b, guest PC 0x0c0a5cfa */
if(!s->budget--) { s->failed_pc=0x0c0a5cfau; return 0; }
target=r[2];
r[16]=0x0c0a5cfeu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a5cfeu) { target=s->pc; goto dispatch; }
goto P_0c0a5cfe;
P_0c0a5cfc: /* original 0009, guest PC 0x0c0a5cfc */
if(!s->budget--) { s->failed_pc=0x0c0a5cfcu; return 0; }
goto P_0c0a5cfe;
P_0c0a5cfe: /* original d325, guest PC 0x0c0a5cfe */
if(!s->budget--) { s->failed_pc=0x0c0a5cfeu; return 0; }
r[3]=read(ram,0x0c0a5d94u,4);
goto P_0c0a5d00;
P_0c0a5d00: /* original 943b, guest PC 0x0c0a5d00 */
if(!s->budget--) { s->failed_pc=0x0c0a5d00u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a5d7au,2);
goto P_0c0a5d02;
P_0c0a5d02: /* original 430b, guest PC 0x0c0a5d02 */
if(!s->budget--) { s->failed_pc=0x0c0a5d02u; return 0; }
target=r[3];
r[16]=0x0c0a5d06u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a5d06u) { target=s->pc; goto dispatch; }
goto P_0c0a5d06;
P_0c0a5d04: /* original 0009, guest PC 0x0c0a5d04 */
if(!s->budget--) { s->failed_pc=0x0c0a5d04u; return 0; }
goto P_0c0a5d06;
P_0c0a5d06: /* original d223, guest PC 0x0c0a5d06 */
if(!s->budget--) { s->failed_pc=0x0c0a5d06u; return 0; }
r[2]=read(ram,0x0c0a5d94u,4);
goto P_0c0a5d08;
P_0c0a5d08: /* original 9438, guest PC 0x0c0a5d08 */
if(!s->budget--) { s->failed_pc=0x0c0a5d08u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a5d7cu,2);
goto P_0c0a5d0a;
P_0c0a5d0a: /* original 420b, guest PC 0x0c0a5d0a */
if(!s->budget--) { s->failed_pc=0x0c0a5d0au; return 0; }
target=r[2];
r[16]=0x0c0a5d0eu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a5d0eu) { target=s->pc; goto dispatch; }
goto P_0c0a5d0e;
P_0c0a5d0c: /* original 0009, guest PC 0x0c0a5d0c */
if(!s->budget--) { s->failed_pc=0x0c0a5d0cu; return 0; }
goto P_0c0a5d0e;
P_0c0a5d0e: /* original d321, guest PC 0x0c0a5d0e */
if(!s->budget--) { s->failed_pc=0x0c0a5d0eu; return 0; }
r[3]=read(ram,0x0c0a5d94u,4);
goto P_0c0a5d10;
P_0c0a5d10: /* original 9435, guest PC 0x0c0a5d10 */
if(!s->budget--) { s->failed_pc=0x0c0a5d10u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a5d7eu,2);
goto P_0c0a5d12;
P_0c0a5d12: /* original 430b, guest PC 0x0c0a5d12 */
if(!s->budget--) { s->failed_pc=0x0c0a5d12u; return 0; }
target=r[3];
r[16]=0x0c0a5d16u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a5d16u) { target=s->pc; goto dispatch; }
goto P_0c0a5d16;
P_0c0a5d14: /* original 0009, guest PC 0x0c0a5d14 */
if(!s->budget--) { s->failed_pc=0x0c0a5d14u; return 0; }
goto P_0c0a5d16;
P_0c0a5d16: /* original d21f, guest PC 0x0c0a5d16 */
if(!s->budget--) { s->failed_pc=0x0c0a5d16u; return 0; }
r[2]=read(ram,0x0c0a5d94u,4);
goto P_0c0a5d18;
P_0c0a5d18: /* original 9432, guest PC 0x0c0a5d18 */
if(!s->budget--) { s->failed_pc=0x0c0a5d18u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a5d80u,2);
goto P_0c0a5d1a;
P_0c0a5d1a: /* original 420b, guest PC 0x0c0a5d1a */
if(!s->budget--) { s->failed_pc=0x0c0a5d1au; return 0; }
target=r[2];
r[16]=0x0c0a5d1eu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a5d1eu) { target=s->pc; goto dispatch; }
goto P_0c0a5d1e;
P_0c0a5d1c: /* original 0009, guest PC 0x0c0a5d1c */
if(!s->budget--) { s->failed_pc=0x0c0a5d1cu; return 0; }
goto P_0c0a5d1e;
P_0c0a5d1e: /* original d31d, guest PC 0x0c0a5d1e */
if(!s->budget--) { s->failed_pc=0x0c0a5d1eu; return 0; }
r[3]=read(ram,0x0c0a5d94u,4);
goto P_0c0a5d20;
P_0c0a5d20: /* original 942f, guest PC 0x0c0a5d20 */
if(!s->budget--) { s->failed_pc=0x0c0a5d20u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a5d82u,2);
goto P_0c0a5d22;
P_0c0a5d22: /* original 430b, guest PC 0x0c0a5d22 */
if(!s->budget--) { s->failed_pc=0x0c0a5d22u; return 0; }
target=r[3];
r[16]=0x0c0a5d26u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a5d26u) { target=s->pc; goto dispatch; }
goto P_0c0a5d26;
P_0c0a5d24: /* original 0009, guest PC 0x0c0a5d24 */
if(!s->budget--) { s->failed_pc=0x0c0a5d24u; return 0; }
goto P_0c0a5d26;
P_0c0a5d26: /* original d21b, guest PC 0x0c0a5d26 */
if(!s->budget--) { s->failed_pc=0x0c0a5d26u; return 0; }
r[2]=read(ram,0x0c0a5d94u,4);
goto P_0c0a5d28;
P_0c0a5d28: /* original 942c, guest PC 0x0c0a5d28 */
if(!s->budget--) { s->failed_pc=0x0c0a5d28u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a5d84u,2);
goto P_0c0a5d2a;
P_0c0a5d2a: /* original 420b, guest PC 0x0c0a5d2a */
if(!s->budget--) { s->failed_pc=0x0c0a5d2au; return 0; }
target=r[2];
r[16]=0x0c0a5d2eu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a5d2eu) { target=s->pc; goto dispatch; }
goto P_0c0a5d2e;
P_0c0a5d2c: /* original 0009, guest PC 0x0c0a5d2c */
if(!s->budget--) { s->failed_pc=0x0c0a5d2cu; return 0; }
goto P_0c0a5d2e;
P_0c0a5d2e: /* original d319, guest PC 0x0c0a5d2e */
if(!s->budget--) { s->failed_pc=0x0c0a5d2eu; return 0; }
r[3]=read(ram,0x0c0a5d94u,4);
goto P_0c0a5d30;
P_0c0a5d30: /* original 9429, guest PC 0x0c0a5d30 */
if(!s->budget--) { s->failed_pc=0x0c0a5d30u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a5d86u,2);
goto P_0c0a5d32;
P_0c0a5d32: /* original 430b, guest PC 0x0c0a5d32 */
if(!s->budget--) { s->failed_pc=0x0c0a5d32u; return 0; }
target=r[3];
r[16]=0x0c0a5d36u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a5d36u) { target=s->pc; goto dispatch; }
goto P_0c0a5d36;
P_0c0a5d34: /* original 0009, guest PC 0x0c0a5d34 */
if(!s->budget--) { s->failed_pc=0x0c0a5d34u; return 0; }
goto P_0c0a5d36;
P_0c0a5d36: /* original d217, guest PC 0x0c0a5d36 */
if(!s->budget--) { s->failed_pc=0x0c0a5d36u; return 0; }
r[2]=read(ram,0x0c0a5d94u,4);
goto P_0c0a5d38;
P_0c0a5d38: /* original 9426, guest PC 0x0c0a5d38 */
if(!s->budget--) { s->failed_pc=0x0c0a5d38u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a5d88u,2);
goto P_0c0a5d3a;
P_0c0a5d3a: /* original 420b, guest PC 0x0c0a5d3a */
if(!s->budget--) { s->failed_pc=0x0c0a5d3au; return 0; }
target=r[2];
r[16]=0x0c0a5d3eu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a5d3eu) { target=s->pc; goto dispatch; }
goto P_0c0a5d3e;
P_0c0a5d3c: /* original 0009, guest PC 0x0c0a5d3c */
if(!s->budget--) { s->failed_pc=0x0c0a5d3cu; return 0; }
goto P_0c0a5d3e;
P_0c0a5d3e: /* original d315, guest PC 0x0c0a5d3e */
if(!s->budget--) { s->failed_pc=0x0c0a5d3eu; return 0; }
r[3]=read(ram,0x0c0a5d94u,4);
goto P_0c0a5d40;
P_0c0a5d40: /* original 9423, guest PC 0x0c0a5d40 */
if(!s->budget--) { s->failed_pc=0x0c0a5d40u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a5d8au,2);
goto P_0c0a5d42;
P_0c0a5d42: /* original 430b, guest PC 0x0c0a5d42 */
if(!s->budget--) { s->failed_pc=0x0c0a5d42u; return 0; }
target=r[3];
r[16]=0x0c0a5d46u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a5d46u) { target=s->pc; goto dispatch; }
goto P_0c0a5d46;
P_0c0a5d44: /* original 0009, guest PC 0x0c0a5d44 */
if(!s->budget--) { s->failed_pc=0x0c0a5d44u; return 0; }
goto P_0c0a5d46;
P_0c0a5d46: /* original d213, guest PC 0x0c0a5d46 */
if(!s->budget--) { s->failed_pc=0x0c0a5d46u; return 0; }
r[2]=read(ram,0x0c0a5d94u,4);
goto P_0c0a5d48;
P_0c0a5d48: /* original 9420, guest PC 0x0c0a5d48 */
if(!s->budget--) { s->failed_pc=0x0c0a5d48u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a5d8cu,2);
goto P_0c0a5d4a;
P_0c0a5d4a: /* original 420b, guest PC 0x0c0a5d4a */
if(!s->budget--) { s->failed_pc=0x0c0a5d4au; return 0; }
target=r[2];
r[16]=0x0c0a5d4eu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a5d4eu) { target=s->pc; goto dispatch; }
goto P_0c0a5d4e;
P_0c0a5d4c: /* original 0009, guest PC 0x0c0a5d4c */
if(!s->budget--) { s->failed_pc=0x0c0a5d4cu; return 0; }
goto P_0c0a5d4e;
P_0c0a5d4e: /* original d311, guest PC 0x0c0a5d4e */
if(!s->budget--) { s->failed_pc=0x0c0a5d4eu; return 0; }
r[3]=read(ram,0x0c0a5d94u,4);
goto P_0c0a5d50;
P_0c0a5d50: /* original 941d, guest PC 0x0c0a5d50 */
if(!s->budget--) { s->failed_pc=0x0c0a5d50u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a5d8eu,2);
goto P_0c0a5d52;
P_0c0a5d52: /* original 430b, guest PC 0x0c0a5d52 */
if(!s->budget--) { s->failed_pc=0x0c0a5d52u; return 0; }
target=r[3];
r[16]=0x0c0a5d56u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a5d56u) { target=s->pc; goto dispatch; }
goto P_0c0a5d56;
P_0c0a5d54: /* original 0009, guest PC 0x0c0a5d54 */
if(!s->budget--) { s->failed_pc=0x0c0a5d54u; return 0; }
goto P_0c0a5d56;
P_0c0a5d56: /* original d20f, guest PC 0x0c0a5d56 */
if(!s->budget--) { s->failed_pc=0x0c0a5d56u; return 0; }
r[2]=read(ram,0x0c0a5d94u,4);
goto P_0c0a5d58;
P_0c0a5d58: /* original 941a, guest PC 0x0c0a5d58 */
if(!s->budget--) { s->failed_pc=0x0c0a5d58u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a5d90u,2);
goto P_0c0a5d5a;
P_0c0a5d5a: /* original 422b, guest PC 0x0c0a5d5a */
if(!s->budget--) { s->failed_pc=0x0c0a5d5au; return 0; }
target=r[2];
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
P_0c0a5d5c: /* original 4f26, guest PC 0x0c0a5d5c */
if(!s->budget--) { s->failed_pc=0x0c0a5d5cu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
return vf3_matrix_family(0x0c0a5d5eu,s,ram);
P_0c0a5ec8: /* original 4f22, guest PC 0x0c0a5ec8 */
if(!s->budget--) { s->failed_pc=0x0c0a5ec8u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0a5eca;
P_0c0a5eca: /* original d34f, guest PC 0x0c0a5eca */
if(!s->budget--) { s->failed_pc=0x0c0a5ecau; return 0; }
r[3]=read(ram,0x0c0a6008u,4);
goto P_0c0a5ecc;
P_0c0a5ecc: /* original 948b, guest PC 0x0c0a5ecc */
if(!s->budget--) { s->failed_pc=0x0c0a5eccu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a5fe6u,2);
goto P_0c0a5ece;
P_0c0a5ece: /* original 430b, guest PC 0x0c0a5ece */
if(!s->budget--) { s->failed_pc=0x0c0a5eceu; return 0; }
target=r[3];
r[16]=0x0c0a5ed2u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a5ed2u) { target=s->pc; goto dispatch; }
goto P_0c0a5ed2;
P_0c0a5ed0: /* original 0009, guest PC 0x0c0a5ed0 */
if(!s->budget--) { s->failed_pc=0x0c0a5ed0u; return 0; }
goto P_0c0a5ed2;
P_0c0a5ed2: /* original d24d, guest PC 0x0c0a5ed2 */
if(!s->budget--) { s->failed_pc=0x0c0a5ed2u; return 0; }
r[2]=read(ram,0x0c0a6008u,4);
goto P_0c0a5ed4;
P_0c0a5ed4: /* original 9488, guest PC 0x0c0a5ed4 */
if(!s->budget--) { s->failed_pc=0x0c0a5ed4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a5fe8u,2);
goto P_0c0a5ed6;
P_0c0a5ed6: /* original 420b, guest PC 0x0c0a5ed6 */
if(!s->budget--) { s->failed_pc=0x0c0a5ed6u; return 0; }
target=r[2];
r[16]=0x0c0a5edau;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a5edau) { target=s->pc; goto dispatch; }
goto P_0c0a5eda;
P_0c0a5ed8: /* original 0009, guest PC 0x0c0a5ed8 */
if(!s->budget--) { s->failed_pc=0x0c0a5ed8u; return 0; }
goto P_0c0a5eda;
P_0c0a5eda: /* original d34b, guest PC 0x0c0a5eda */
if(!s->budget--) { s->failed_pc=0x0c0a5edau; return 0; }
r[3]=read(ram,0x0c0a6008u,4);
goto P_0c0a5edc;
P_0c0a5edc: /* original 9485, guest PC 0x0c0a5edc */
if(!s->budget--) { s->failed_pc=0x0c0a5edcu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a5feau,2);
goto P_0c0a5ede;
P_0c0a5ede: /* original 430b, guest PC 0x0c0a5ede */
if(!s->budget--) { s->failed_pc=0x0c0a5edeu; return 0; }
target=r[3];
r[16]=0x0c0a5ee2u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a5ee2u) { target=s->pc; goto dispatch; }
goto P_0c0a5ee2;
P_0c0a5ee0: /* original 0009, guest PC 0x0c0a5ee0 */
if(!s->budget--) { s->failed_pc=0x0c0a5ee0u; return 0; }
goto P_0c0a5ee2;
P_0c0a5ee2: /* original d249, guest PC 0x0c0a5ee2 */
if(!s->budget--) { s->failed_pc=0x0c0a5ee2u; return 0; }
r[2]=read(ram,0x0c0a6008u,4);
goto P_0c0a5ee4;
P_0c0a5ee4: /* original 9482, guest PC 0x0c0a5ee4 */
if(!s->budget--) { s->failed_pc=0x0c0a5ee4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a5fecu,2);
goto P_0c0a5ee6;
P_0c0a5ee6: /* original 420b, guest PC 0x0c0a5ee6 */
if(!s->budget--) { s->failed_pc=0x0c0a5ee6u; return 0; }
target=r[2];
r[16]=0x0c0a5eeau;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a5eeau) { target=s->pc; goto dispatch; }
goto P_0c0a5eea;
P_0c0a5ee8: /* original 0009, guest PC 0x0c0a5ee8 */
if(!s->budget--) { s->failed_pc=0x0c0a5ee8u; return 0; }
goto P_0c0a5eea;
P_0c0a5eea: /* original d347, guest PC 0x0c0a5eea */
if(!s->budget--) { s->failed_pc=0x0c0a5eeau; return 0; }
r[3]=read(ram,0x0c0a6008u,4);
goto P_0c0a5eec;
P_0c0a5eec: /* original 947f, guest PC 0x0c0a5eec */
if(!s->budget--) { s->failed_pc=0x0c0a5eecu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a5feeu,2);
goto P_0c0a5eee;
P_0c0a5eee: /* original 430b, guest PC 0x0c0a5eee */
if(!s->budget--) { s->failed_pc=0x0c0a5eeeu; return 0; }
target=r[3];
r[16]=0x0c0a5ef2u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a5ef2u) { target=s->pc; goto dispatch; }
goto P_0c0a5ef2;
P_0c0a5ef0: /* original 0009, guest PC 0x0c0a5ef0 */
if(!s->budget--) { s->failed_pc=0x0c0a5ef0u; return 0; }
goto P_0c0a5ef2;
P_0c0a5ef2: /* original d245, guest PC 0x0c0a5ef2 */
if(!s->budget--) { s->failed_pc=0x0c0a5ef2u; return 0; }
r[2]=read(ram,0x0c0a6008u,4);
goto P_0c0a5ef4;
P_0c0a5ef4: /* original 947c, guest PC 0x0c0a5ef4 */
if(!s->budget--) { s->failed_pc=0x0c0a5ef4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a5ff0u,2);
goto P_0c0a5ef6;
P_0c0a5ef6: /* original 420b, guest PC 0x0c0a5ef6 */
if(!s->budget--) { s->failed_pc=0x0c0a5ef6u; return 0; }
target=r[2];
r[16]=0x0c0a5efau;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a5efau) { target=s->pc; goto dispatch; }
goto P_0c0a5efa;
P_0c0a5ef8: /* original 0009, guest PC 0x0c0a5ef8 */
if(!s->budget--) { s->failed_pc=0x0c0a5ef8u; return 0; }
goto P_0c0a5efa;
P_0c0a5efa: /* original d343, guest PC 0x0c0a5efa */
if(!s->budget--) { s->failed_pc=0x0c0a5efau; return 0; }
r[3]=read(ram,0x0c0a6008u,4);
goto P_0c0a5efc;
P_0c0a5efc: /* original 9479, guest PC 0x0c0a5efc */
if(!s->budget--) { s->failed_pc=0x0c0a5efcu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a5ff2u,2);
goto P_0c0a5efe;
P_0c0a5efe: /* original 430b, guest PC 0x0c0a5efe */
if(!s->budget--) { s->failed_pc=0x0c0a5efeu; return 0; }
target=r[3];
r[16]=0x0c0a5f02u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a5f02u) { target=s->pc; goto dispatch; }
goto P_0c0a5f02;
P_0c0a5f00: /* original 0009, guest PC 0x0c0a5f00 */
if(!s->budget--) { s->failed_pc=0x0c0a5f00u; return 0; }
goto P_0c0a5f02;
P_0c0a5f02: /* original d241, guest PC 0x0c0a5f02 */
if(!s->budget--) { s->failed_pc=0x0c0a5f02u; return 0; }
r[2]=read(ram,0x0c0a6008u,4);
goto P_0c0a5f04;
P_0c0a5f04: /* original 9476, guest PC 0x0c0a5f04 */
if(!s->budget--) { s->failed_pc=0x0c0a5f04u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a5ff4u,2);
goto P_0c0a5f06;
P_0c0a5f06: /* original 420b, guest PC 0x0c0a5f06 */
if(!s->budget--) { s->failed_pc=0x0c0a5f06u; return 0; }
target=r[2];
r[16]=0x0c0a5f0au;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a5f0au) { target=s->pc; goto dispatch; }
goto P_0c0a5f0a;
P_0c0a5f08: /* original 0009, guest PC 0x0c0a5f08 */
if(!s->budget--) { s->failed_pc=0x0c0a5f08u; return 0; }
goto P_0c0a5f0a;
P_0c0a5f0a: /* original d33f, guest PC 0x0c0a5f0a */
if(!s->budget--) { s->failed_pc=0x0c0a5f0au; return 0; }
r[3]=read(ram,0x0c0a6008u,4);
goto P_0c0a5f0c;
P_0c0a5f0c: /* original 9473, guest PC 0x0c0a5f0c */
if(!s->budget--) { s->failed_pc=0x0c0a5f0cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a5ff6u,2);
goto P_0c0a5f0e;
P_0c0a5f0e: /* original 430b, guest PC 0x0c0a5f0e */
if(!s->budget--) { s->failed_pc=0x0c0a5f0eu; return 0; }
target=r[3];
r[16]=0x0c0a5f12u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a5f12u) { target=s->pc; goto dispatch; }
goto P_0c0a5f12;
P_0c0a5f10: /* original 0009, guest PC 0x0c0a5f10 */
if(!s->budget--) { s->failed_pc=0x0c0a5f10u; return 0; }
goto P_0c0a5f12;
P_0c0a5f12: /* original d23d, guest PC 0x0c0a5f12 */
if(!s->budget--) { s->failed_pc=0x0c0a5f12u; return 0; }
r[2]=read(ram,0x0c0a6008u,4);
goto P_0c0a5f14;
P_0c0a5f14: /* original 9470, guest PC 0x0c0a5f14 */
if(!s->budget--) { s->failed_pc=0x0c0a5f14u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a5ff8u,2);
goto P_0c0a5f16;
P_0c0a5f16: /* original 420b, guest PC 0x0c0a5f16 */
if(!s->budget--) { s->failed_pc=0x0c0a5f16u; return 0; }
target=r[2];
r[16]=0x0c0a5f1au;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a5f1au) { target=s->pc; goto dispatch; }
goto P_0c0a5f1a;
P_0c0a5f18: /* original 0009, guest PC 0x0c0a5f18 */
if(!s->budget--) { s->failed_pc=0x0c0a5f18u; return 0; }
goto P_0c0a5f1a;
P_0c0a5f1a: /* original d33b, guest PC 0x0c0a5f1a */
if(!s->budget--) { s->failed_pc=0x0c0a5f1au; return 0; }
r[3]=read(ram,0x0c0a6008u,4);
goto P_0c0a5f1c;
P_0c0a5f1c: /* original 946d, guest PC 0x0c0a5f1c */
if(!s->budget--) { s->failed_pc=0x0c0a5f1cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a5ffau,2);
goto P_0c0a5f1e;
P_0c0a5f1e: /* original 430b, guest PC 0x0c0a5f1e */
if(!s->budget--) { s->failed_pc=0x0c0a5f1eu; return 0; }
target=r[3];
r[16]=0x0c0a5f22u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a5f22u) { target=s->pc; goto dispatch; }
goto P_0c0a5f22;
P_0c0a5f20: /* original 0009, guest PC 0x0c0a5f20 */
if(!s->budget--) { s->failed_pc=0x0c0a5f20u; return 0; }
goto P_0c0a5f22;
P_0c0a5f22: /* original d239, guest PC 0x0c0a5f22 */
if(!s->budget--) { s->failed_pc=0x0c0a5f22u; return 0; }
r[2]=read(ram,0x0c0a6008u,4);
goto P_0c0a5f24;
P_0c0a5f24: /* original 946a, guest PC 0x0c0a5f24 */
if(!s->budget--) { s->failed_pc=0x0c0a5f24u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a5ffcu,2);
goto P_0c0a5f26;
P_0c0a5f26: /* original 420b, guest PC 0x0c0a5f26 */
if(!s->budget--) { s->failed_pc=0x0c0a5f26u; return 0; }
target=r[2];
r[16]=0x0c0a5f2au;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a5f2au) { target=s->pc; goto dispatch; }
goto P_0c0a5f2a;
P_0c0a5f28: /* original 0009, guest PC 0x0c0a5f28 */
if(!s->budget--) { s->failed_pc=0x0c0a5f28u; return 0; }
goto P_0c0a5f2a;
P_0c0a5f2a: /* original d337, guest PC 0x0c0a5f2a */
if(!s->budget--) { s->failed_pc=0x0c0a5f2au; return 0; }
r[3]=read(ram,0x0c0a6008u,4);
goto P_0c0a5f2c;
P_0c0a5f2c: /* original 9467, guest PC 0x0c0a5f2c */
if(!s->budget--) { s->failed_pc=0x0c0a5f2cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a5ffeu,2);
goto P_0c0a5f2e;
P_0c0a5f2e: /* original 430b, guest PC 0x0c0a5f2e */
if(!s->budget--) { s->failed_pc=0x0c0a5f2eu; return 0; }
target=r[3];
r[16]=0x0c0a5f32u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a5f32u) { target=s->pc; goto dispatch; }
goto P_0c0a5f32;
P_0c0a5f30: /* original 0009, guest PC 0x0c0a5f30 */
if(!s->budget--) { s->failed_pc=0x0c0a5f30u; return 0; }
goto P_0c0a5f32;
P_0c0a5f32: /* original d235, guest PC 0x0c0a5f32 */
if(!s->budget--) { s->failed_pc=0x0c0a5f32u; return 0; }
r[2]=read(ram,0x0c0a6008u,4);
goto P_0c0a5f34;
P_0c0a5f34: /* original 9464, guest PC 0x0c0a5f34 */
if(!s->budget--) { s->failed_pc=0x0c0a5f34u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a6000u,2);
goto P_0c0a5f36;
P_0c0a5f36: /* original 420b, guest PC 0x0c0a5f36 */
if(!s->budget--) { s->failed_pc=0x0c0a5f36u; return 0; }
target=r[2];
r[16]=0x0c0a5f3au;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a5f3au) { target=s->pc; goto dispatch; }
goto P_0c0a5f3a;
P_0c0a5f38: /* original 0009, guest PC 0x0c0a5f38 */
if(!s->budget--) { s->failed_pc=0x0c0a5f38u; return 0; }
goto P_0c0a5f3a;
P_0c0a5f3a: /* original d333, guest PC 0x0c0a5f3a */
if(!s->budget--) { s->failed_pc=0x0c0a5f3au; return 0; }
r[3]=read(ram,0x0c0a6008u,4);
goto P_0c0a5f3c;
P_0c0a5f3c: /* original 9461, guest PC 0x0c0a5f3c */
if(!s->budget--) { s->failed_pc=0x0c0a5f3cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a6002u,2);
goto P_0c0a5f3e;
P_0c0a5f3e: /* original 430b, guest PC 0x0c0a5f3e */
if(!s->budget--) { s->failed_pc=0x0c0a5f3eu; return 0; }
target=r[3];
r[16]=0x0c0a5f42u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a5f42u) { target=s->pc; goto dispatch; }
goto P_0c0a5f42;
P_0c0a5f40: /* original 0009, guest PC 0x0c0a5f40 */
if(!s->budget--) { s->failed_pc=0x0c0a5f40u; return 0; }
goto P_0c0a5f42;
P_0c0a5f42: /* original d231, guest PC 0x0c0a5f42 */
if(!s->budget--) { s->failed_pc=0x0c0a5f42u; return 0; }
r[2]=read(ram,0x0c0a6008u,4);
goto P_0c0a5f44;
P_0c0a5f44: /* original 945e, guest PC 0x0c0a5f44 */
if(!s->budget--) { s->failed_pc=0x0c0a5f44u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a6004u,2);
goto P_0c0a5f46;
P_0c0a5f46: /* original 420b, guest PC 0x0c0a5f46 */
if(!s->budget--) { s->failed_pc=0x0c0a5f46u; return 0; }
target=r[2];
r[16]=0x0c0a5f4au;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a5f4au) { target=s->pc; goto dispatch; }
goto P_0c0a5f4a;
P_0c0a5f48: /* original 0009, guest PC 0x0c0a5f48 */
if(!s->budget--) { s->failed_pc=0x0c0a5f48u; return 0; }
goto P_0c0a5f4a;
P_0c0a5f4a: /* original d32f, guest PC 0x0c0a5f4a */
if(!s->budget--) { s->failed_pc=0x0c0a5f4au; return 0; }
r[3]=read(ram,0x0c0a6008u,4);
goto P_0c0a5f4c;
P_0c0a5f4c: /* original 945b, guest PC 0x0c0a5f4c */
if(!s->budget--) { s->failed_pc=0x0c0a5f4cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a6006u,2);
goto P_0c0a5f4e;
P_0c0a5f4e: /* original 432b, guest PC 0x0c0a5f4e */
if(!s->budget--) { s->failed_pc=0x0c0a5f4eu; return 0; }
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
P_0c0a5f50: /* original 4f26, guest PC 0x0c0a5f50 */
if(!s->budget--) { s->failed_pc=0x0c0a5f50u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
return vf3_matrix_family(0x0c0a5f52u,s,ram);
P_0c0a6010: /* original 4f22, guest PC 0x0c0a6010 */
if(!s->budget--) { s->failed_pc=0x0c0a6010u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0a6012;
P_0c0a6012: /* original d34f, guest PC 0x0c0a6012 */
if(!s->budget--) { s->failed_pc=0x0c0a6012u; return 0; }
r[3]=read(ram,0x0c0a6150u,4);
goto P_0c0a6014;
P_0c0a6014: /* original 948b, guest PC 0x0c0a6014 */
if(!s->budget--) { s->failed_pc=0x0c0a6014u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a612eu,2);
goto P_0c0a6016;
P_0c0a6016: /* original 430b, guest PC 0x0c0a6016 */
if(!s->budget--) { s->failed_pc=0x0c0a6016u; return 0; }
target=r[3];
r[16]=0x0c0a601au;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a601au) { target=s->pc; goto dispatch; }
goto P_0c0a601a;
P_0c0a6018: /* original 0009, guest PC 0x0c0a6018 */
if(!s->budget--) { s->failed_pc=0x0c0a6018u; return 0; }
goto P_0c0a601a;
P_0c0a601a: /* original d24d, guest PC 0x0c0a601a */
if(!s->budget--) { s->failed_pc=0x0c0a601au; return 0; }
r[2]=read(ram,0x0c0a6150u,4);
goto P_0c0a601c;
P_0c0a601c: /* original 9488, guest PC 0x0c0a601c */
if(!s->budget--) { s->failed_pc=0x0c0a601cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a6130u,2);
goto P_0c0a601e;
P_0c0a601e: /* original 420b, guest PC 0x0c0a601e */
if(!s->budget--) { s->failed_pc=0x0c0a601eu; return 0; }
target=r[2];
r[16]=0x0c0a6022u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a6022u) { target=s->pc; goto dispatch; }
goto P_0c0a6022;
P_0c0a6020: /* original 0009, guest PC 0x0c0a6020 */
if(!s->budget--) { s->failed_pc=0x0c0a6020u; return 0; }
goto P_0c0a6022;
P_0c0a6022: /* original d34b, guest PC 0x0c0a6022 */
if(!s->budget--) { s->failed_pc=0x0c0a6022u; return 0; }
r[3]=read(ram,0x0c0a6150u,4);
goto P_0c0a6024;
P_0c0a6024: /* original 9485, guest PC 0x0c0a6024 */
if(!s->budget--) { s->failed_pc=0x0c0a6024u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a6132u,2);
goto P_0c0a6026;
P_0c0a6026: /* original 430b, guest PC 0x0c0a6026 */
if(!s->budget--) { s->failed_pc=0x0c0a6026u; return 0; }
target=r[3];
r[16]=0x0c0a602au;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a602au) { target=s->pc; goto dispatch; }
goto P_0c0a602a;
P_0c0a6028: /* original 0009, guest PC 0x0c0a6028 */
if(!s->budget--) { s->failed_pc=0x0c0a6028u; return 0; }
goto P_0c0a602a;
P_0c0a602a: /* original d249, guest PC 0x0c0a602a */
if(!s->budget--) { s->failed_pc=0x0c0a602au; return 0; }
r[2]=read(ram,0x0c0a6150u,4);
goto P_0c0a602c;
P_0c0a602c: /* original 9482, guest PC 0x0c0a602c */
if(!s->budget--) { s->failed_pc=0x0c0a602cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a6134u,2);
goto P_0c0a602e;
P_0c0a602e: /* original 420b, guest PC 0x0c0a602e */
if(!s->budget--) { s->failed_pc=0x0c0a602eu; return 0; }
target=r[2];
r[16]=0x0c0a6032u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a6032u) { target=s->pc; goto dispatch; }
goto P_0c0a6032;
P_0c0a6030: /* original 0009, guest PC 0x0c0a6030 */
if(!s->budget--) { s->failed_pc=0x0c0a6030u; return 0; }
goto P_0c0a6032;
P_0c0a6032: /* original d347, guest PC 0x0c0a6032 */
if(!s->budget--) { s->failed_pc=0x0c0a6032u; return 0; }
r[3]=read(ram,0x0c0a6150u,4);
goto P_0c0a6034;
P_0c0a6034: /* original 947f, guest PC 0x0c0a6034 */
if(!s->budget--) { s->failed_pc=0x0c0a6034u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a6136u,2);
goto P_0c0a6036;
P_0c0a6036: /* original 430b, guest PC 0x0c0a6036 */
if(!s->budget--) { s->failed_pc=0x0c0a6036u; return 0; }
target=r[3];
r[16]=0x0c0a603au;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a603au) { target=s->pc; goto dispatch; }
goto P_0c0a603a;
P_0c0a6038: /* original 0009, guest PC 0x0c0a6038 */
if(!s->budget--) { s->failed_pc=0x0c0a6038u; return 0; }
goto P_0c0a603a;
P_0c0a603a: /* original d245, guest PC 0x0c0a603a */
if(!s->budget--) { s->failed_pc=0x0c0a603au; return 0; }
r[2]=read(ram,0x0c0a6150u,4);
goto P_0c0a603c;
P_0c0a603c: /* original 947c, guest PC 0x0c0a603c */
if(!s->budget--) { s->failed_pc=0x0c0a603cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a6138u,2);
goto P_0c0a603e;
P_0c0a603e: /* original 420b, guest PC 0x0c0a603e */
if(!s->budget--) { s->failed_pc=0x0c0a603eu; return 0; }
target=r[2];
r[16]=0x0c0a6042u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a6042u) { target=s->pc; goto dispatch; }
goto P_0c0a6042;
P_0c0a6040: /* original 0009, guest PC 0x0c0a6040 */
if(!s->budget--) { s->failed_pc=0x0c0a6040u; return 0; }
goto P_0c0a6042;
P_0c0a6042: /* original d343, guest PC 0x0c0a6042 */
if(!s->budget--) { s->failed_pc=0x0c0a6042u; return 0; }
r[3]=read(ram,0x0c0a6150u,4);
goto P_0c0a6044;
P_0c0a6044: /* original 9479, guest PC 0x0c0a6044 */
if(!s->budget--) { s->failed_pc=0x0c0a6044u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a613au,2);
goto P_0c0a6046;
P_0c0a6046: /* original 430b, guest PC 0x0c0a6046 */
if(!s->budget--) { s->failed_pc=0x0c0a6046u; return 0; }
target=r[3];
r[16]=0x0c0a604au;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a604au) { target=s->pc; goto dispatch; }
goto P_0c0a604a;
P_0c0a6048: /* original 0009, guest PC 0x0c0a6048 */
if(!s->budget--) { s->failed_pc=0x0c0a6048u; return 0; }
goto P_0c0a604a;
P_0c0a604a: /* original d241, guest PC 0x0c0a604a */
if(!s->budget--) { s->failed_pc=0x0c0a604au; return 0; }
r[2]=read(ram,0x0c0a6150u,4);
goto P_0c0a604c;
P_0c0a604c: /* original 9476, guest PC 0x0c0a604c */
if(!s->budget--) { s->failed_pc=0x0c0a604cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a613cu,2);
goto P_0c0a604e;
P_0c0a604e: /* original 420b, guest PC 0x0c0a604e */
if(!s->budget--) { s->failed_pc=0x0c0a604eu; return 0; }
target=r[2];
r[16]=0x0c0a6052u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a6052u) { target=s->pc; goto dispatch; }
goto P_0c0a6052;
P_0c0a6050: /* original 0009, guest PC 0x0c0a6050 */
if(!s->budget--) { s->failed_pc=0x0c0a6050u; return 0; }
goto P_0c0a6052;
P_0c0a6052: /* original d33f, guest PC 0x0c0a6052 */
if(!s->budget--) { s->failed_pc=0x0c0a6052u; return 0; }
r[3]=read(ram,0x0c0a6150u,4);
goto P_0c0a6054;
P_0c0a6054: /* original 9473, guest PC 0x0c0a6054 */
if(!s->budget--) { s->failed_pc=0x0c0a6054u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a613eu,2);
goto P_0c0a6056;
P_0c0a6056: /* original 430b, guest PC 0x0c0a6056 */
if(!s->budget--) { s->failed_pc=0x0c0a6056u; return 0; }
target=r[3];
r[16]=0x0c0a605au;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a605au) { target=s->pc; goto dispatch; }
goto P_0c0a605a;
P_0c0a6058: /* original 0009, guest PC 0x0c0a6058 */
if(!s->budget--) { s->failed_pc=0x0c0a6058u; return 0; }
goto P_0c0a605a;
P_0c0a605a: /* original d23d, guest PC 0x0c0a605a */
if(!s->budget--) { s->failed_pc=0x0c0a605au; return 0; }
r[2]=read(ram,0x0c0a6150u,4);
goto P_0c0a605c;
P_0c0a605c: /* original 9470, guest PC 0x0c0a605c */
if(!s->budget--) { s->failed_pc=0x0c0a605cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a6140u,2);
goto P_0c0a605e;
P_0c0a605e: /* original 420b, guest PC 0x0c0a605e */
if(!s->budget--) { s->failed_pc=0x0c0a605eu; return 0; }
target=r[2];
r[16]=0x0c0a6062u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a6062u) { target=s->pc; goto dispatch; }
goto P_0c0a6062;
P_0c0a6060: /* original 0009, guest PC 0x0c0a6060 */
if(!s->budget--) { s->failed_pc=0x0c0a6060u; return 0; }
goto P_0c0a6062;
P_0c0a6062: /* original d33b, guest PC 0x0c0a6062 */
if(!s->budget--) { s->failed_pc=0x0c0a6062u; return 0; }
r[3]=read(ram,0x0c0a6150u,4);
goto P_0c0a6064;
P_0c0a6064: /* original 946d, guest PC 0x0c0a6064 */
if(!s->budget--) { s->failed_pc=0x0c0a6064u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a6142u,2);
goto P_0c0a6066;
P_0c0a6066: /* original 430b, guest PC 0x0c0a6066 */
if(!s->budget--) { s->failed_pc=0x0c0a6066u; return 0; }
target=r[3];
r[16]=0x0c0a606au;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a606au) { target=s->pc; goto dispatch; }
goto P_0c0a606a;
P_0c0a6068: /* original 0009, guest PC 0x0c0a6068 */
if(!s->budget--) { s->failed_pc=0x0c0a6068u; return 0; }
goto P_0c0a606a;
P_0c0a606a: /* original d239, guest PC 0x0c0a606a */
if(!s->budget--) { s->failed_pc=0x0c0a606au; return 0; }
r[2]=read(ram,0x0c0a6150u,4);
goto P_0c0a606c;
P_0c0a606c: /* original 946a, guest PC 0x0c0a606c */
if(!s->budget--) { s->failed_pc=0x0c0a606cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a6144u,2);
goto P_0c0a606e;
P_0c0a606e: /* original 420b, guest PC 0x0c0a606e */
if(!s->budget--) { s->failed_pc=0x0c0a606eu; return 0; }
target=r[2];
r[16]=0x0c0a6072u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a6072u) { target=s->pc; goto dispatch; }
goto P_0c0a6072;
P_0c0a6070: /* original 0009, guest PC 0x0c0a6070 */
if(!s->budget--) { s->failed_pc=0x0c0a6070u; return 0; }
goto P_0c0a6072;
P_0c0a6072: /* original d337, guest PC 0x0c0a6072 */
if(!s->budget--) { s->failed_pc=0x0c0a6072u; return 0; }
r[3]=read(ram,0x0c0a6150u,4);
goto P_0c0a6074;
P_0c0a6074: /* original 9467, guest PC 0x0c0a6074 */
if(!s->budget--) { s->failed_pc=0x0c0a6074u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a6146u,2);
goto P_0c0a6076;
P_0c0a6076: /* original 430b, guest PC 0x0c0a6076 */
if(!s->budget--) { s->failed_pc=0x0c0a6076u; return 0; }
target=r[3];
r[16]=0x0c0a607au;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a607au) { target=s->pc; goto dispatch; }
goto P_0c0a607a;
P_0c0a6078: /* original 0009, guest PC 0x0c0a6078 */
if(!s->budget--) { s->failed_pc=0x0c0a6078u; return 0; }
goto P_0c0a607a;
P_0c0a607a: /* original d235, guest PC 0x0c0a607a */
if(!s->budget--) { s->failed_pc=0x0c0a607au; return 0; }
r[2]=read(ram,0x0c0a6150u,4);
goto P_0c0a607c;
P_0c0a607c: /* original 9464, guest PC 0x0c0a607c */
if(!s->budget--) { s->failed_pc=0x0c0a607cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a6148u,2);
goto P_0c0a607e;
P_0c0a607e: /* original 420b, guest PC 0x0c0a607e */
if(!s->budget--) { s->failed_pc=0x0c0a607eu; return 0; }
target=r[2];
r[16]=0x0c0a6082u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a6082u) { target=s->pc; goto dispatch; }
goto P_0c0a6082;
P_0c0a6080: /* original 0009, guest PC 0x0c0a6080 */
if(!s->budget--) { s->failed_pc=0x0c0a6080u; return 0; }
goto P_0c0a6082;
P_0c0a6082: /* original d333, guest PC 0x0c0a6082 */
if(!s->budget--) { s->failed_pc=0x0c0a6082u; return 0; }
r[3]=read(ram,0x0c0a6150u,4);
goto P_0c0a6084;
P_0c0a6084: /* original 9461, guest PC 0x0c0a6084 */
if(!s->budget--) { s->failed_pc=0x0c0a6084u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a614au,2);
goto P_0c0a6086;
P_0c0a6086: /* original 430b, guest PC 0x0c0a6086 */
if(!s->budget--) { s->failed_pc=0x0c0a6086u; return 0; }
target=r[3];
r[16]=0x0c0a608au;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a608au) { target=s->pc; goto dispatch; }
goto P_0c0a608a;
P_0c0a6088: /* original 0009, guest PC 0x0c0a6088 */
if(!s->budget--) { s->failed_pc=0x0c0a6088u; return 0; }
goto P_0c0a608a;
P_0c0a608a: /* original d231, guest PC 0x0c0a608a */
if(!s->budget--) { s->failed_pc=0x0c0a608au; return 0; }
r[2]=read(ram,0x0c0a6150u,4);
goto P_0c0a608c;
P_0c0a608c: /* original 945e, guest PC 0x0c0a608c */
if(!s->budget--) { s->failed_pc=0x0c0a608cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a614cu,2);
goto P_0c0a608e;
P_0c0a608e: /* original 420b, guest PC 0x0c0a608e */
if(!s->budget--) { s->failed_pc=0x0c0a608eu; return 0; }
target=r[2];
r[16]=0x0c0a6092u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a6092u) { target=s->pc; goto dispatch; }
goto P_0c0a6092;
P_0c0a6090: /* original 0009, guest PC 0x0c0a6090 */
if(!s->budget--) { s->failed_pc=0x0c0a6090u; return 0; }
goto P_0c0a6092;
P_0c0a6092: /* original d32f, guest PC 0x0c0a6092 */
if(!s->budget--) { s->failed_pc=0x0c0a6092u; return 0; }
r[3]=read(ram,0x0c0a6150u,4);
goto P_0c0a6094;
P_0c0a6094: /* original 945b, guest PC 0x0c0a6094 */
if(!s->budget--) { s->failed_pc=0x0c0a6094u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a614eu,2);
goto P_0c0a6096;
P_0c0a6096: /* original 432b, guest PC 0x0c0a6096 */
if(!s->budget--) { s->failed_pc=0x0c0a6096u; return 0; }
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
P_0c0a6098: /* original 4f26, guest PC 0x0c0a6098 */
if(!s->budget--) { s->failed_pc=0x0c0a6098u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
return vf3_matrix_family(0x0c0a609au,s,ram);
P_0c0a6158: /* original 4f22, guest PC 0x0c0a6158 */
if(!s->budget--) { s->failed_pc=0x0c0a6158u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0a615a;
P_0c0a615a: /* original d35f, guest PC 0x0c0a615a */
if(!s->budget--) { s->failed_pc=0x0c0a615au; return 0; }
r[3]=read(ram,0x0c0a62d8u,4);
goto P_0c0a615c;
P_0c0a615c: /* original 94a7, guest PC 0x0c0a615c */
if(!s->budget--) { s->failed_pc=0x0c0a615cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a62aeu,2);
goto P_0c0a615e;
P_0c0a615e: /* original 430b, guest PC 0x0c0a615e */
if(!s->budget--) { s->failed_pc=0x0c0a615eu; return 0; }
target=r[3];
r[16]=0x0c0a6162u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a6162u) { target=s->pc; goto dispatch; }
goto P_0c0a6162;
P_0c0a6160: /* original 0009, guest PC 0x0c0a6160 */
if(!s->budget--) { s->failed_pc=0x0c0a6160u; return 0; }
goto P_0c0a6162;
P_0c0a6162: /* original d25d, guest PC 0x0c0a6162 */
if(!s->budget--) { s->failed_pc=0x0c0a6162u; return 0; }
r[2]=read(ram,0x0c0a62d8u,4);
goto P_0c0a6164;
P_0c0a6164: /* original 94a4, guest PC 0x0c0a6164 */
if(!s->budget--) { s->failed_pc=0x0c0a6164u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a62b0u,2);
goto P_0c0a6166;
P_0c0a6166: /* original 420b, guest PC 0x0c0a6166 */
if(!s->budget--) { s->failed_pc=0x0c0a6166u; return 0; }
target=r[2];
r[16]=0x0c0a616au;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a616au) { target=s->pc; goto dispatch; }
goto P_0c0a616a;
P_0c0a6168: /* original 0009, guest PC 0x0c0a6168 */
if(!s->budget--) { s->failed_pc=0x0c0a6168u; return 0; }
goto P_0c0a616a;
P_0c0a616a: /* original d35b, guest PC 0x0c0a616a */
if(!s->budget--) { s->failed_pc=0x0c0a616au; return 0; }
r[3]=read(ram,0x0c0a62d8u,4);
goto P_0c0a616c;
P_0c0a616c: /* original 94a1, guest PC 0x0c0a616c */
if(!s->budget--) { s->failed_pc=0x0c0a616cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a62b2u,2);
goto P_0c0a616e;
P_0c0a616e: /* original 430b, guest PC 0x0c0a616e */
if(!s->budget--) { s->failed_pc=0x0c0a616eu; return 0; }
target=r[3];
r[16]=0x0c0a6172u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a6172u) { target=s->pc; goto dispatch; }
goto P_0c0a6172;
P_0c0a6170: /* original 0009, guest PC 0x0c0a6170 */
if(!s->budget--) { s->failed_pc=0x0c0a6170u; return 0; }
goto P_0c0a6172;
P_0c0a6172: /* original d259, guest PC 0x0c0a6172 */
if(!s->budget--) { s->failed_pc=0x0c0a6172u; return 0; }
r[2]=read(ram,0x0c0a62d8u,4);
goto P_0c0a6174;
P_0c0a6174: /* original 949e, guest PC 0x0c0a6174 */
if(!s->budget--) { s->failed_pc=0x0c0a6174u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a62b4u,2);
goto P_0c0a6176;
P_0c0a6176: /* original 420b, guest PC 0x0c0a6176 */
if(!s->budget--) { s->failed_pc=0x0c0a6176u; return 0; }
target=r[2];
r[16]=0x0c0a617au;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a617au) { target=s->pc; goto dispatch; }
goto P_0c0a617a;
P_0c0a6178: /* original 0009, guest PC 0x0c0a6178 */
if(!s->budget--) { s->failed_pc=0x0c0a6178u; return 0; }
goto P_0c0a617a;
P_0c0a617a: /* original d357, guest PC 0x0c0a617a */
if(!s->budget--) { s->failed_pc=0x0c0a617au; return 0; }
r[3]=read(ram,0x0c0a62d8u,4);
goto P_0c0a617c;
P_0c0a617c: /* original 949b, guest PC 0x0c0a617c */
if(!s->budget--) { s->failed_pc=0x0c0a617cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a62b6u,2);
goto P_0c0a617e;
P_0c0a617e: /* original 430b, guest PC 0x0c0a617e */
if(!s->budget--) { s->failed_pc=0x0c0a617eu; return 0; }
target=r[3];
r[16]=0x0c0a6182u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a6182u) { target=s->pc; goto dispatch; }
goto P_0c0a6182;
P_0c0a6180: /* original 0009, guest PC 0x0c0a6180 */
if(!s->budget--) { s->failed_pc=0x0c0a6180u; return 0; }
goto P_0c0a6182;
P_0c0a6182: /* original d255, guest PC 0x0c0a6182 */
if(!s->budget--) { s->failed_pc=0x0c0a6182u; return 0; }
r[2]=read(ram,0x0c0a62d8u,4);
goto P_0c0a6184;
P_0c0a6184: /* original 9498, guest PC 0x0c0a6184 */
if(!s->budget--) { s->failed_pc=0x0c0a6184u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a62b8u,2);
goto P_0c0a6186;
P_0c0a6186: /* original 420b, guest PC 0x0c0a6186 */
if(!s->budget--) { s->failed_pc=0x0c0a6186u; return 0; }
target=r[2];
r[16]=0x0c0a618au;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a618au) { target=s->pc; goto dispatch; }
goto P_0c0a618a;
P_0c0a6188: /* original 0009, guest PC 0x0c0a6188 */
if(!s->budget--) { s->failed_pc=0x0c0a6188u; return 0; }
goto P_0c0a618a;
P_0c0a618a: /* original d353, guest PC 0x0c0a618a */
if(!s->budget--) { s->failed_pc=0x0c0a618au; return 0; }
r[3]=read(ram,0x0c0a62d8u,4);
goto P_0c0a618c;
P_0c0a618c: /* original 9495, guest PC 0x0c0a618c */
if(!s->budget--) { s->failed_pc=0x0c0a618cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a62bau,2);
goto P_0c0a618e;
P_0c0a618e: /* original 430b, guest PC 0x0c0a618e */
if(!s->budget--) { s->failed_pc=0x0c0a618eu; return 0; }
target=r[3];
r[16]=0x0c0a6192u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a6192u) { target=s->pc; goto dispatch; }
goto P_0c0a6192;
P_0c0a6190: /* original 0009, guest PC 0x0c0a6190 */
if(!s->budget--) { s->failed_pc=0x0c0a6190u; return 0; }
goto P_0c0a6192;
P_0c0a6192: /* original d251, guest PC 0x0c0a6192 */
if(!s->budget--) { s->failed_pc=0x0c0a6192u; return 0; }
r[2]=read(ram,0x0c0a62d8u,4);
goto P_0c0a6194;
P_0c0a6194: /* original 9492, guest PC 0x0c0a6194 */
if(!s->budget--) { s->failed_pc=0x0c0a6194u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a62bcu,2);
goto P_0c0a6196;
P_0c0a6196: /* original 420b, guest PC 0x0c0a6196 */
if(!s->budget--) { s->failed_pc=0x0c0a6196u; return 0; }
target=r[2];
r[16]=0x0c0a619au;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a619au) { target=s->pc; goto dispatch; }
goto P_0c0a619a;
P_0c0a6198: /* original 0009, guest PC 0x0c0a6198 */
if(!s->budget--) { s->failed_pc=0x0c0a6198u; return 0; }
goto P_0c0a619a;
P_0c0a619a: /* original d34f, guest PC 0x0c0a619a */
if(!s->budget--) { s->failed_pc=0x0c0a619au; return 0; }
r[3]=read(ram,0x0c0a62d8u,4);
goto P_0c0a619c;
P_0c0a619c: /* original 948f, guest PC 0x0c0a619c */
if(!s->budget--) { s->failed_pc=0x0c0a619cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a62beu,2);
goto P_0c0a619e;
P_0c0a619e: /* original 430b, guest PC 0x0c0a619e */
if(!s->budget--) { s->failed_pc=0x0c0a619eu; return 0; }
target=r[3];
r[16]=0x0c0a61a2u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a61a2u) { target=s->pc; goto dispatch; }
goto P_0c0a61a2;
P_0c0a61a0: /* original 0009, guest PC 0x0c0a61a0 */
if(!s->budget--) { s->failed_pc=0x0c0a61a0u; return 0; }
goto P_0c0a61a2;
P_0c0a61a2: /* original d24d, guest PC 0x0c0a61a2 */
if(!s->budget--) { s->failed_pc=0x0c0a61a2u; return 0; }
r[2]=read(ram,0x0c0a62d8u,4);
goto P_0c0a61a4;
P_0c0a61a4: /* original 948c, guest PC 0x0c0a61a4 */
if(!s->budget--) { s->failed_pc=0x0c0a61a4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a62c0u,2);
goto P_0c0a61a6;
P_0c0a61a6: /* original 420b, guest PC 0x0c0a61a6 */
if(!s->budget--) { s->failed_pc=0x0c0a61a6u; return 0; }
target=r[2];
r[16]=0x0c0a61aau;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a61aau) { target=s->pc; goto dispatch; }
goto P_0c0a61aa;
P_0c0a61a8: /* original 0009, guest PC 0x0c0a61a8 */
if(!s->budget--) { s->failed_pc=0x0c0a61a8u; return 0; }
goto P_0c0a61aa;
P_0c0a61aa: /* original d34b, guest PC 0x0c0a61aa */
if(!s->budget--) { s->failed_pc=0x0c0a61aau; return 0; }
r[3]=read(ram,0x0c0a62d8u,4);
goto P_0c0a61ac;
P_0c0a61ac: /* original 9489, guest PC 0x0c0a61ac */
if(!s->budget--) { s->failed_pc=0x0c0a61acu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a62c2u,2);
goto P_0c0a61ae;
P_0c0a61ae: /* original 430b, guest PC 0x0c0a61ae */
if(!s->budget--) { s->failed_pc=0x0c0a61aeu; return 0; }
target=r[3];
r[16]=0x0c0a61b2u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a61b2u) { target=s->pc; goto dispatch; }
goto P_0c0a61b2;
P_0c0a61b0: /* original 0009, guest PC 0x0c0a61b0 */
if(!s->budget--) { s->failed_pc=0x0c0a61b0u; return 0; }
goto P_0c0a61b2;
P_0c0a61b2: /* original d249, guest PC 0x0c0a61b2 */
if(!s->budget--) { s->failed_pc=0x0c0a61b2u; return 0; }
r[2]=read(ram,0x0c0a62d8u,4);
goto P_0c0a61b4;
P_0c0a61b4: /* original 9486, guest PC 0x0c0a61b4 */
if(!s->budget--) { s->failed_pc=0x0c0a61b4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a62c4u,2);
goto P_0c0a61b6;
P_0c0a61b6: /* original 420b, guest PC 0x0c0a61b6 */
if(!s->budget--) { s->failed_pc=0x0c0a61b6u; return 0; }
target=r[2];
r[16]=0x0c0a61bau;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a61bau) { target=s->pc; goto dispatch; }
goto P_0c0a61ba;
P_0c0a61b8: /* original 0009, guest PC 0x0c0a61b8 */
if(!s->budget--) { s->failed_pc=0x0c0a61b8u; return 0; }
goto P_0c0a61ba;
P_0c0a61ba: /* original d347, guest PC 0x0c0a61ba */
if(!s->budget--) { s->failed_pc=0x0c0a61bau; return 0; }
r[3]=read(ram,0x0c0a62d8u,4);
goto P_0c0a61bc;
P_0c0a61bc: /* original 9483, guest PC 0x0c0a61bc */
if(!s->budget--) { s->failed_pc=0x0c0a61bcu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a62c6u,2);
goto P_0c0a61be;
P_0c0a61be: /* original 430b, guest PC 0x0c0a61be */
if(!s->budget--) { s->failed_pc=0x0c0a61beu; return 0; }
target=r[3];
r[16]=0x0c0a61c2u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a61c2u) { target=s->pc; goto dispatch; }
goto P_0c0a61c2;
P_0c0a61c0: /* original 0009, guest PC 0x0c0a61c0 */
if(!s->budget--) { s->failed_pc=0x0c0a61c0u; return 0; }
goto P_0c0a61c2;
P_0c0a61c2: /* original d245, guest PC 0x0c0a61c2 */
if(!s->budget--) { s->failed_pc=0x0c0a61c2u; return 0; }
r[2]=read(ram,0x0c0a62d8u,4);
goto P_0c0a61c4;
P_0c0a61c4: /* original 9480, guest PC 0x0c0a61c4 */
if(!s->budget--) { s->failed_pc=0x0c0a61c4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a62c8u,2);
goto P_0c0a61c6;
P_0c0a61c6: /* original 420b, guest PC 0x0c0a61c6 */
if(!s->budget--) { s->failed_pc=0x0c0a61c6u; return 0; }
target=r[2];
r[16]=0x0c0a61cau;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a61cau) { target=s->pc; goto dispatch; }
goto P_0c0a61ca;
P_0c0a61c8: /* original 0009, guest PC 0x0c0a61c8 */
if(!s->budget--) { s->failed_pc=0x0c0a61c8u; return 0; }
goto P_0c0a61ca;
P_0c0a61ca: /* original d343, guest PC 0x0c0a61ca */
if(!s->budget--) { s->failed_pc=0x0c0a61cau; return 0; }
r[3]=read(ram,0x0c0a62d8u,4);
goto P_0c0a61cc;
P_0c0a61cc: /* original 947d, guest PC 0x0c0a61cc */
if(!s->budget--) { s->failed_pc=0x0c0a61ccu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a62cau,2);
goto P_0c0a61ce;
P_0c0a61ce: /* original 430b, guest PC 0x0c0a61ce */
if(!s->budget--) { s->failed_pc=0x0c0a61ceu; return 0; }
target=r[3];
r[16]=0x0c0a61d2u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a61d2u) { target=s->pc; goto dispatch; }
goto P_0c0a61d2;
P_0c0a61d0: /* original 0009, guest PC 0x0c0a61d0 */
if(!s->budget--) { s->failed_pc=0x0c0a61d0u; return 0; }
goto P_0c0a61d2;
P_0c0a61d2: /* original d241, guest PC 0x0c0a61d2 */
if(!s->budget--) { s->failed_pc=0x0c0a61d2u; return 0; }
r[2]=read(ram,0x0c0a62d8u,4);
goto P_0c0a61d4;
P_0c0a61d4: /* original 947a, guest PC 0x0c0a61d4 */
if(!s->budget--) { s->failed_pc=0x0c0a61d4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a62ccu,2);
goto P_0c0a61d6;
P_0c0a61d6: /* original 420b, guest PC 0x0c0a61d6 */
if(!s->budget--) { s->failed_pc=0x0c0a61d6u; return 0; }
target=r[2];
r[16]=0x0c0a61dau;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a61dau) { target=s->pc; goto dispatch; }
goto P_0c0a61da;
P_0c0a61d8: /* original 0009, guest PC 0x0c0a61d8 */
if(!s->budget--) { s->failed_pc=0x0c0a61d8u; return 0; }
goto P_0c0a61da;
P_0c0a61da: /* original d33f, guest PC 0x0c0a61da */
if(!s->budget--) { s->failed_pc=0x0c0a61dau; return 0; }
r[3]=read(ram,0x0c0a62d8u,4);
goto P_0c0a61dc;
P_0c0a61dc: /* original 9477, guest PC 0x0c0a61dc */
if(!s->budget--) { s->failed_pc=0x0c0a61dcu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a62ceu,2);
goto P_0c0a61de;
P_0c0a61de: /* original 430b, guest PC 0x0c0a61de */
if(!s->budget--) { s->failed_pc=0x0c0a61deu; return 0; }
target=r[3];
r[16]=0x0c0a61e2u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a61e2u) { target=s->pc; goto dispatch; }
goto P_0c0a61e2;
P_0c0a61e0: /* original 0009, guest PC 0x0c0a61e0 */
if(!s->budget--) { s->failed_pc=0x0c0a61e0u; return 0; }
goto P_0c0a61e2;
P_0c0a61e2: /* original d23d, guest PC 0x0c0a61e2 */
if(!s->budget--) { s->failed_pc=0x0c0a61e2u; return 0; }
r[2]=read(ram,0x0c0a62d8u,4);
goto P_0c0a61e4;
P_0c0a61e4: /* original 9474, guest PC 0x0c0a61e4 */
if(!s->budget--) { s->failed_pc=0x0c0a61e4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a62d0u,2);
goto P_0c0a61e6;
P_0c0a61e6: /* original 420b, guest PC 0x0c0a61e6 */
if(!s->budget--) { s->failed_pc=0x0c0a61e6u; return 0; }
target=r[2];
r[16]=0x0c0a61eau;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a61eau) { target=s->pc; goto dispatch; }
goto P_0c0a61ea;
P_0c0a61e8: /* original 0009, guest PC 0x0c0a61e8 */
if(!s->budget--) { s->failed_pc=0x0c0a61e8u; return 0; }
goto P_0c0a61ea;
P_0c0a61ea: /* original d33b, guest PC 0x0c0a61ea */
if(!s->budget--) { s->failed_pc=0x0c0a61eau; return 0; }
r[3]=read(ram,0x0c0a62d8u,4);
goto P_0c0a61ec;
P_0c0a61ec: /* original 9471, guest PC 0x0c0a61ec */
if(!s->budget--) { s->failed_pc=0x0c0a61ecu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a62d2u,2);
goto P_0c0a61ee;
P_0c0a61ee: /* original 430b, guest PC 0x0c0a61ee */
if(!s->budget--) { s->failed_pc=0x0c0a61eeu; return 0; }
target=r[3];
r[16]=0x0c0a61f2u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a61f2u) { target=s->pc; goto dispatch; }
goto P_0c0a61f2;
P_0c0a61f0: /* original 0009, guest PC 0x0c0a61f0 */
if(!s->budget--) { s->failed_pc=0x0c0a61f0u; return 0; }
goto P_0c0a61f2;
P_0c0a61f2: /* original d239, guest PC 0x0c0a61f2 */
if(!s->budget--) { s->failed_pc=0x0c0a61f2u; return 0; }
r[2]=read(ram,0x0c0a62d8u,4);
goto P_0c0a61f4;
P_0c0a61f4: /* original 946e, guest PC 0x0c0a61f4 */
if(!s->budget--) { s->failed_pc=0x0c0a61f4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a62d4u,2);
goto P_0c0a61f6;
P_0c0a61f6: /* original 422b, guest PC 0x0c0a61f6 */
if(!s->budget--) { s->failed_pc=0x0c0a61f6u; return 0; }
target=r[2];
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
P_0c0a61f8: /* original 4f26, guest PC 0x0c0a61f8 */
if(!s->budget--) { s->failed_pc=0x0c0a61f8u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
return vf3_matrix_family(0x0c0a61fau,s,ram);
P_0c0a62e0: /* original 4f22, guest PC 0x0c0a62e0 */
if(!s->budget--) { s->failed_pc=0x0c0a62e0u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0a62e2;
P_0c0a62e2: /* original d364, guest PC 0x0c0a62e2 */
if(!s->budget--) { s->failed_pc=0x0c0a62e2u; return 0; }
r[3]=read(ram,0x0c0a6474u,4);
goto P_0c0a62e4;
P_0c0a62e4: /* original 94b0, guest PC 0x0c0a62e4 */
if(!s->budget--) { s->failed_pc=0x0c0a62e4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a6448u,2);
goto P_0c0a62e6;
P_0c0a62e6: /* original 430b, guest PC 0x0c0a62e6 */
if(!s->budget--) { s->failed_pc=0x0c0a62e6u; return 0; }
target=r[3];
r[16]=0x0c0a62eau;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a62eau) { target=s->pc; goto dispatch; }
goto P_0c0a62ea;
P_0c0a62e8: /* original 0009, guest PC 0x0c0a62e8 */
if(!s->budget--) { s->failed_pc=0x0c0a62e8u; return 0; }
goto P_0c0a62ea;
P_0c0a62ea: /* original d262, guest PC 0x0c0a62ea */
if(!s->budget--) { s->failed_pc=0x0c0a62eau; return 0; }
r[2]=read(ram,0x0c0a6474u,4);
goto P_0c0a62ec;
P_0c0a62ec: /* original 94ad, guest PC 0x0c0a62ec */
if(!s->budget--) { s->failed_pc=0x0c0a62ecu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a644au,2);
goto P_0c0a62ee;
P_0c0a62ee: /* original 420b, guest PC 0x0c0a62ee */
if(!s->budget--) { s->failed_pc=0x0c0a62eeu; return 0; }
target=r[2];
r[16]=0x0c0a62f2u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a62f2u) { target=s->pc; goto dispatch; }
goto P_0c0a62f2;
P_0c0a62f0: /* original 0009, guest PC 0x0c0a62f0 */
if(!s->budget--) { s->failed_pc=0x0c0a62f0u; return 0; }
goto P_0c0a62f2;
P_0c0a62f2: /* original d360, guest PC 0x0c0a62f2 */
if(!s->budget--) { s->failed_pc=0x0c0a62f2u; return 0; }
r[3]=read(ram,0x0c0a6474u,4);
goto P_0c0a62f4;
P_0c0a62f4: /* original 94aa, guest PC 0x0c0a62f4 */
if(!s->budget--) { s->failed_pc=0x0c0a62f4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a644cu,2);
goto P_0c0a62f6;
P_0c0a62f6: /* original 430b, guest PC 0x0c0a62f6 */
if(!s->budget--) { s->failed_pc=0x0c0a62f6u; return 0; }
target=r[3];
r[16]=0x0c0a62fau;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a62fau) { target=s->pc; goto dispatch; }
goto P_0c0a62fa;
P_0c0a62f8: /* original 0009, guest PC 0x0c0a62f8 */
if(!s->budget--) { s->failed_pc=0x0c0a62f8u; return 0; }
goto P_0c0a62fa;
P_0c0a62fa: /* original d25e, guest PC 0x0c0a62fa */
if(!s->budget--) { s->failed_pc=0x0c0a62fau; return 0; }
r[2]=read(ram,0x0c0a6474u,4);
goto P_0c0a62fc;
P_0c0a62fc: /* original 94a7, guest PC 0x0c0a62fc */
if(!s->budget--) { s->failed_pc=0x0c0a62fcu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a644eu,2);
goto P_0c0a62fe;
P_0c0a62fe: /* original 420b, guest PC 0x0c0a62fe */
if(!s->budget--) { s->failed_pc=0x0c0a62feu; return 0; }
target=r[2];
r[16]=0x0c0a6302u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a6302u) { target=s->pc; goto dispatch; }
goto P_0c0a6302;
P_0c0a6300: /* original 0009, guest PC 0x0c0a6300 */
if(!s->budget--) { s->failed_pc=0x0c0a6300u; return 0; }
goto P_0c0a6302;
P_0c0a6302: /* original d35c, guest PC 0x0c0a6302 */
if(!s->budget--) { s->failed_pc=0x0c0a6302u; return 0; }
r[3]=read(ram,0x0c0a6474u,4);
goto P_0c0a6304;
P_0c0a6304: /* original 94a4, guest PC 0x0c0a6304 */
if(!s->budget--) { s->failed_pc=0x0c0a6304u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a6450u,2);
goto P_0c0a6306;
P_0c0a6306: /* original 430b, guest PC 0x0c0a6306 */
if(!s->budget--) { s->failed_pc=0x0c0a6306u; return 0; }
target=r[3];
r[16]=0x0c0a630au;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a630au) { target=s->pc; goto dispatch; }
goto P_0c0a630a;
P_0c0a6308: /* original 0009, guest PC 0x0c0a6308 */
if(!s->budget--) { s->failed_pc=0x0c0a6308u; return 0; }
goto P_0c0a630a;
P_0c0a630a: /* original d25a, guest PC 0x0c0a630a */
if(!s->budget--) { s->failed_pc=0x0c0a630au; return 0; }
r[2]=read(ram,0x0c0a6474u,4);
goto P_0c0a630c;
P_0c0a630c: /* original 94a1, guest PC 0x0c0a630c */
if(!s->budget--) { s->failed_pc=0x0c0a630cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a6452u,2);
goto P_0c0a630e;
P_0c0a630e: /* original 420b, guest PC 0x0c0a630e */
if(!s->budget--) { s->failed_pc=0x0c0a630eu; return 0; }
target=r[2];
r[16]=0x0c0a6312u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a6312u) { target=s->pc; goto dispatch; }
goto P_0c0a6312;
P_0c0a6310: /* original 0009, guest PC 0x0c0a6310 */
if(!s->budget--) { s->failed_pc=0x0c0a6310u; return 0; }
goto P_0c0a6312;
P_0c0a6312: /* original d358, guest PC 0x0c0a6312 */
if(!s->budget--) { s->failed_pc=0x0c0a6312u; return 0; }
r[3]=read(ram,0x0c0a6474u,4);
goto P_0c0a6314;
P_0c0a6314: /* original 949e, guest PC 0x0c0a6314 */
if(!s->budget--) { s->failed_pc=0x0c0a6314u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a6454u,2);
goto P_0c0a6316;
P_0c0a6316: /* original 430b, guest PC 0x0c0a6316 */
if(!s->budget--) { s->failed_pc=0x0c0a6316u; return 0; }
target=r[3];
r[16]=0x0c0a631au;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a631au) { target=s->pc; goto dispatch; }
goto P_0c0a631a;
P_0c0a6318: /* original 0009, guest PC 0x0c0a6318 */
if(!s->budget--) { s->failed_pc=0x0c0a6318u; return 0; }
goto P_0c0a631a;
P_0c0a631a: /* original d256, guest PC 0x0c0a631a */
if(!s->budget--) { s->failed_pc=0x0c0a631au; return 0; }
r[2]=read(ram,0x0c0a6474u,4);
goto P_0c0a631c;
P_0c0a631c: /* original 949b, guest PC 0x0c0a631c */
if(!s->budget--) { s->failed_pc=0x0c0a631cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a6456u,2);
goto P_0c0a631e;
P_0c0a631e: /* original 420b, guest PC 0x0c0a631e */
if(!s->budget--) { s->failed_pc=0x0c0a631eu; return 0; }
target=r[2];
r[16]=0x0c0a6322u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a6322u) { target=s->pc; goto dispatch; }
goto P_0c0a6322;
P_0c0a6320: /* original 0009, guest PC 0x0c0a6320 */
if(!s->budget--) { s->failed_pc=0x0c0a6320u; return 0; }
goto P_0c0a6322;
P_0c0a6322: /* original d354, guest PC 0x0c0a6322 */
if(!s->budget--) { s->failed_pc=0x0c0a6322u; return 0; }
r[3]=read(ram,0x0c0a6474u,4);
goto P_0c0a6324;
P_0c0a6324: /* original 9498, guest PC 0x0c0a6324 */
if(!s->budget--) { s->failed_pc=0x0c0a6324u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a6458u,2);
goto P_0c0a6326;
P_0c0a6326: /* original 430b, guest PC 0x0c0a6326 */
if(!s->budget--) { s->failed_pc=0x0c0a6326u; return 0; }
target=r[3];
r[16]=0x0c0a632au;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a632au) { target=s->pc; goto dispatch; }
goto P_0c0a632a;
P_0c0a6328: /* original 0009, guest PC 0x0c0a6328 */
if(!s->budget--) { s->failed_pc=0x0c0a6328u; return 0; }
goto P_0c0a632a;
P_0c0a632a: /* original d252, guest PC 0x0c0a632a */
if(!s->budget--) { s->failed_pc=0x0c0a632au; return 0; }
r[2]=read(ram,0x0c0a6474u,4);
goto P_0c0a632c;
P_0c0a632c: /* original 9495, guest PC 0x0c0a632c */
if(!s->budget--) { s->failed_pc=0x0c0a632cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a645au,2);
goto P_0c0a632e;
P_0c0a632e: /* original 420b, guest PC 0x0c0a632e */
if(!s->budget--) { s->failed_pc=0x0c0a632eu; return 0; }
target=r[2];
r[16]=0x0c0a6332u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a6332u) { target=s->pc; goto dispatch; }
goto P_0c0a6332;
P_0c0a6330: /* original 0009, guest PC 0x0c0a6330 */
if(!s->budget--) { s->failed_pc=0x0c0a6330u; return 0; }
goto P_0c0a6332;
P_0c0a6332: /* original d350, guest PC 0x0c0a6332 */
if(!s->budget--) { s->failed_pc=0x0c0a6332u; return 0; }
r[3]=read(ram,0x0c0a6474u,4);
goto P_0c0a6334;
P_0c0a6334: /* original 9492, guest PC 0x0c0a6334 */
if(!s->budget--) { s->failed_pc=0x0c0a6334u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a645cu,2);
goto P_0c0a6336;
P_0c0a6336: /* original 430b, guest PC 0x0c0a6336 */
if(!s->budget--) { s->failed_pc=0x0c0a6336u; return 0; }
target=r[3];
r[16]=0x0c0a633au;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a633au) { target=s->pc; goto dispatch; }
goto P_0c0a633a;
P_0c0a6338: /* original 0009, guest PC 0x0c0a6338 */
if(!s->budget--) { s->failed_pc=0x0c0a6338u; return 0; }
goto P_0c0a633a;
P_0c0a633a: /* original d24e, guest PC 0x0c0a633a */
if(!s->budget--) { s->failed_pc=0x0c0a633au; return 0; }
r[2]=read(ram,0x0c0a6474u,4);
goto P_0c0a633c;
P_0c0a633c: /* original 948f, guest PC 0x0c0a633c */
if(!s->budget--) { s->failed_pc=0x0c0a633cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a645eu,2);
goto P_0c0a633e;
P_0c0a633e: /* original 420b, guest PC 0x0c0a633e */
if(!s->budget--) { s->failed_pc=0x0c0a633eu; return 0; }
target=r[2];
r[16]=0x0c0a6342u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a6342u) { target=s->pc; goto dispatch; }
goto P_0c0a6342;
P_0c0a6340: /* original 0009, guest PC 0x0c0a6340 */
if(!s->budget--) { s->failed_pc=0x0c0a6340u; return 0; }
goto P_0c0a6342;
P_0c0a6342: /* original d34c, guest PC 0x0c0a6342 */
if(!s->budget--) { s->failed_pc=0x0c0a6342u; return 0; }
r[3]=read(ram,0x0c0a6474u,4);
goto P_0c0a6344;
P_0c0a6344: /* original 948c, guest PC 0x0c0a6344 */
if(!s->budget--) { s->failed_pc=0x0c0a6344u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a6460u,2);
goto P_0c0a6346;
P_0c0a6346: /* original 430b, guest PC 0x0c0a6346 */
if(!s->budget--) { s->failed_pc=0x0c0a6346u; return 0; }
target=r[3];
r[16]=0x0c0a634au;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a634au) { target=s->pc; goto dispatch; }
goto P_0c0a634a;
P_0c0a6348: /* original 0009, guest PC 0x0c0a6348 */
if(!s->budget--) { s->failed_pc=0x0c0a6348u; return 0; }
goto P_0c0a634a;
P_0c0a634a: /* original d24a, guest PC 0x0c0a634a */
if(!s->budget--) { s->failed_pc=0x0c0a634au; return 0; }
r[2]=read(ram,0x0c0a6474u,4);
goto P_0c0a634c;
P_0c0a634c: /* original 9489, guest PC 0x0c0a634c */
if(!s->budget--) { s->failed_pc=0x0c0a634cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a6462u,2);
goto P_0c0a634e;
P_0c0a634e: /* original 420b, guest PC 0x0c0a634e */
if(!s->budget--) { s->failed_pc=0x0c0a634eu; return 0; }
target=r[2];
r[16]=0x0c0a6352u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a6352u) { target=s->pc; goto dispatch; }
goto P_0c0a6352;
P_0c0a6350: /* original 0009, guest PC 0x0c0a6350 */
if(!s->budget--) { s->failed_pc=0x0c0a6350u; return 0; }
goto P_0c0a6352;
P_0c0a6352: /* original d348, guest PC 0x0c0a6352 */
if(!s->budget--) { s->failed_pc=0x0c0a6352u; return 0; }
r[3]=read(ram,0x0c0a6474u,4);
goto P_0c0a6354;
P_0c0a6354: /* original 9486, guest PC 0x0c0a6354 */
if(!s->budget--) { s->failed_pc=0x0c0a6354u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a6464u,2);
goto P_0c0a6356;
P_0c0a6356: /* original 430b, guest PC 0x0c0a6356 */
if(!s->budget--) { s->failed_pc=0x0c0a6356u; return 0; }
target=r[3];
r[16]=0x0c0a635au;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a635au) { target=s->pc; goto dispatch; }
goto P_0c0a635a;
P_0c0a6358: /* original 0009, guest PC 0x0c0a6358 */
if(!s->budget--) { s->failed_pc=0x0c0a6358u; return 0; }
goto P_0c0a635a;
P_0c0a635a: /* original d246, guest PC 0x0c0a635a */
if(!s->budget--) { s->failed_pc=0x0c0a635au; return 0; }
r[2]=read(ram,0x0c0a6474u,4);
goto P_0c0a635c;
P_0c0a635c: /* original 9483, guest PC 0x0c0a635c */
if(!s->budget--) { s->failed_pc=0x0c0a635cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a6466u,2);
goto P_0c0a635e;
P_0c0a635e: /* original 420b, guest PC 0x0c0a635e */
if(!s->budget--) { s->failed_pc=0x0c0a635eu; return 0; }
target=r[2];
r[16]=0x0c0a6362u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a6362u) { target=s->pc; goto dispatch; }
goto P_0c0a6362;
P_0c0a6360: /* original 0009, guest PC 0x0c0a6360 */
if(!s->budget--) { s->failed_pc=0x0c0a6360u; return 0; }
goto P_0c0a6362;
P_0c0a6362: /* original d344, guest PC 0x0c0a6362 */
if(!s->budget--) { s->failed_pc=0x0c0a6362u; return 0; }
r[3]=read(ram,0x0c0a6474u,4);
goto P_0c0a6364;
P_0c0a6364: /* original 9480, guest PC 0x0c0a6364 */
if(!s->budget--) { s->failed_pc=0x0c0a6364u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a6468u,2);
goto P_0c0a6366;
P_0c0a6366: /* original 430b, guest PC 0x0c0a6366 */
if(!s->budget--) { s->failed_pc=0x0c0a6366u; return 0; }
target=r[3];
r[16]=0x0c0a636au;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a636au) { target=s->pc; goto dispatch; }
goto P_0c0a636a;
P_0c0a6368: /* original 0009, guest PC 0x0c0a6368 */
if(!s->budget--) { s->failed_pc=0x0c0a6368u; return 0; }
goto P_0c0a636a;
P_0c0a636a: /* original d242, guest PC 0x0c0a636a */
if(!s->budget--) { s->failed_pc=0x0c0a636au; return 0; }
r[2]=read(ram,0x0c0a6474u,4);
goto P_0c0a636c;
P_0c0a636c: /* original 947d, guest PC 0x0c0a636c */
if(!s->budget--) { s->failed_pc=0x0c0a636cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a646au,2);
goto P_0c0a636e;
P_0c0a636e: /* original 420b, guest PC 0x0c0a636e */
if(!s->budget--) { s->failed_pc=0x0c0a636eu; return 0; }
target=r[2];
r[16]=0x0c0a6372u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a6372u) { target=s->pc; goto dispatch; }
goto P_0c0a6372;
P_0c0a6370: /* original 0009, guest PC 0x0c0a6370 */
if(!s->budget--) { s->failed_pc=0x0c0a6370u; return 0; }
goto P_0c0a6372;
P_0c0a6372: /* original d340, guest PC 0x0c0a6372 */
if(!s->budget--) { s->failed_pc=0x0c0a6372u; return 0; }
r[3]=read(ram,0x0c0a6474u,4);
goto P_0c0a6374;
P_0c0a6374: /* original 947a, guest PC 0x0c0a6374 */
if(!s->budget--) { s->failed_pc=0x0c0a6374u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a646cu,2);
goto P_0c0a6376;
P_0c0a6376: /* original 430b, guest PC 0x0c0a6376 */
if(!s->budget--) { s->failed_pc=0x0c0a6376u; return 0; }
target=r[3];
r[16]=0x0c0a637au;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a637au) { target=s->pc; goto dispatch; }
goto P_0c0a637a;
P_0c0a6378: /* original 0009, guest PC 0x0c0a6378 */
if(!s->budget--) { s->failed_pc=0x0c0a6378u; return 0; }
goto P_0c0a637a;
P_0c0a637a: /* original d23e, guest PC 0x0c0a637a */
if(!s->budget--) { s->failed_pc=0x0c0a637au; return 0; }
r[2]=read(ram,0x0c0a6474u,4);
goto P_0c0a637c;
P_0c0a637c: /* original 9477, guest PC 0x0c0a637c */
if(!s->budget--) { s->failed_pc=0x0c0a637cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a646eu,2);
goto P_0c0a637e;
P_0c0a637e: /* original 420b, guest PC 0x0c0a637e */
if(!s->budget--) { s->failed_pc=0x0c0a637eu; return 0; }
target=r[2];
r[16]=0x0c0a6382u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a6382u) { target=s->pc; goto dispatch; }
goto P_0c0a6382;
P_0c0a6380: /* original 0009, guest PC 0x0c0a6380 */
if(!s->budget--) { s->failed_pc=0x0c0a6380u; return 0; }
goto P_0c0a6382;
P_0c0a6382: /* original d33c, guest PC 0x0c0a6382 */
if(!s->budget--) { s->failed_pc=0x0c0a6382u; return 0; }
r[3]=read(ram,0x0c0a6474u,4);
goto P_0c0a6384;
P_0c0a6384: /* original 9474, guest PC 0x0c0a6384 */
if(!s->budget--) { s->failed_pc=0x0c0a6384u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a6470u,2);
goto P_0c0a6386;
P_0c0a6386: /* original 432b, guest PC 0x0c0a6386 */
if(!s->budget--) { s->failed_pc=0x0c0a6386u; return 0; }
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
P_0c0a6388: /* original 4f26, guest PC 0x0c0a6388 */
if(!s->budget--) { s->failed_pc=0x0c0a6388u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
return vf3_matrix_family(0x0c0a638au,s,ram);
P_0c0beaf8: /* original 4f22, guest PC 0x0c0beaf8 */
if(!s->budget--) { s->failed_pc=0x0c0beaf8u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0beafa;
P_0c0beafa: /* original 9474, guest PC 0x0c0beafa */
if(!s->budget--) { s->failed_pc=0x0c0beafau; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bebe6u,2);
goto P_0c0beafc;
P_0c0beafc: /* original dd4a, guest PC 0x0c0beafc */
if(!s->budget--) { s->failed_pc=0x0c0beafcu; return 0; }
r[13]=read(ram,0x0c0bec28u,4);
goto P_0c0beafe;
P_0c0beafe: /* original 4d0b, guest PC 0x0c0beafe */
if(!s->budget--) { s->failed_pc=0x0c0beafeu; return 0; }
target=r[13];
r[16]=0x0c0beb02u;
tmp=read(ram,r[14],4);
r[5]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0beb02u) { target=s->pc; goto dispatch; }
goto P_0c0beb02;
P_0c0beb00: /* original 65e2, guest PC 0x0c0beb00 */
if(!s->budget--) { s->failed_pc=0x0c0beb00u; return 0; }
tmp=read(ram,r[14],4);
r[5]=tmp;
goto P_0c0beb02;
P_0c0beb02: /* original 9471, guest PC 0x0c0beb02 */
if(!s->budget--) { s->failed_pc=0x0c0beb02u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bebe8u,2);
goto P_0c0beb04;
P_0c0beb04: /* original 4d0b, guest PC 0x0c0beb04 */
if(!s->budget--) { s->failed_pc=0x0c0beb04u; return 0; }
target=r[13];
r[16]=0x0c0beb08u;
r[5]=read(ram,r[14]+4,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0beb08u) { target=s->pc; goto dispatch; }
goto P_0c0beb08;
P_0c0beb06: /* original 55e1, guest PC 0x0c0beb06 */
if(!s->budget--) { s->failed_pc=0x0c0beb06u; return 0; }
r[5]=read(ram,r[14]+4,4);
goto P_0c0beb08;
P_0c0beb08: /* original 946f, guest PC 0x0c0beb08 */
if(!s->budget--) { s->failed_pc=0x0c0beb08u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bebeau,2);
goto P_0c0beb0a;
P_0c0beb0a: /* original 4d0b, guest PC 0x0c0beb0a */
if(!s->budget--) { s->failed_pc=0x0c0beb0au; return 0; }
target=r[13];
r[16]=0x0c0beb0eu;
r[5]=read(ram,r[14]+8,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0beb0eu) { target=s->pc; goto dispatch; }
goto P_0c0beb0e;
P_0c0beb0c: /* original 55e2, guest PC 0x0c0beb0c */
if(!s->budget--) { s->failed_pc=0x0c0beb0cu; return 0; }
r[5]=read(ram,r[14]+8,4);
goto P_0c0beb0e;
P_0c0beb0e: /* original 946d, guest PC 0x0c0beb0e */
if(!s->budget--) { s->failed_pc=0x0c0beb0eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bebecu,2);
goto P_0c0beb10;
P_0c0beb10: /* original 4d0b, guest PC 0x0c0beb10 */
if(!s->budget--) { s->failed_pc=0x0c0beb10u; return 0; }
target=r[13];
r[16]=0x0c0beb14u;
r[5]=read(ram,r[14]+12,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0beb14u) { target=s->pc; goto dispatch; }
goto P_0c0beb14;
P_0c0beb12: /* original 55e3, guest PC 0x0c0beb12 */
if(!s->budget--) { s->failed_pc=0x0c0beb12u; return 0; }
r[5]=read(ram,r[14]+12,4);
goto P_0c0beb14;
P_0c0beb14: /* original 946b, guest PC 0x0c0beb14 */
if(!s->budget--) { s->failed_pc=0x0c0beb14u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bebeeu,2);
goto P_0c0beb16;
P_0c0beb16: /* original 4d0b, guest PC 0x0c0beb16 */
if(!s->budget--) { s->failed_pc=0x0c0beb16u; return 0; }
target=r[13];
r[16]=0x0c0beb1au;
r[5]=read(ram,r[14]+16,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0beb1au) { target=s->pc; goto dispatch; }
goto P_0c0beb1a;
P_0c0beb18: /* original 55e4, guest PC 0x0c0beb18 */
if(!s->budget--) { s->failed_pc=0x0c0beb18u; return 0; }
r[5]=read(ram,r[14]+16,4);
goto P_0c0beb1a;
P_0c0beb1a: /* original 9469, guest PC 0x0c0beb1a */
if(!s->budget--) { s->failed_pc=0x0c0beb1au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bebf0u,2);
goto P_0c0beb1c;
P_0c0beb1c: /* original 4d0b, guest PC 0x0c0beb1c */
if(!s->budget--) { s->failed_pc=0x0c0beb1cu; return 0; }
target=r[13];
r[16]=0x0c0beb20u;
r[5]=read(ram,r[14]+20,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0beb20u) { target=s->pc; goto dispatch; }
goto P_0c0beb20;
P_0c0beb1e: /* original 55e5, guest PC 0x0c0beb1e */
if(!s->budget--) { s->failed_pc=0x0c0beb1eu; return 0; }
r[5]=read(ram,r[14]+20,4);
goto P_0c0beb20;
P_0c0beb20: /* original 9467, guest PC 0x0c0beb20 */
if(!s->budget--) { s->failed_pc=0x0c0beb20u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bebf2u,2);
goto P_0c0beb22;
P_0c0beb22: /* original 4d0b, guest PC 0x0c0beb22 */
if(!s->budget--) { s->failed_pc=0x0c0beb22u; return 0; }
target=r[13];
r[16]=0x0c0beb26u;
r[5]=read(ram,r[14]+24,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0beb26u) { target=s->pc; goto dispatch; }
goto P_0c0beb26;
P_0c0beb24: /* original 55e6, guest PC 0x0c0beb24 */
if(!s->budget--) { s->failed_pc=0x0c0beb24u; return 0; }
r[5]=read(ram,r[14]+24,4);
goto P_0c0beb26;
P_0c0beb26: /* original 9465, guest PC 0x0c0beb26 */
if(!s->budget--) { s->failed_pc=0x0c0beb26u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bebf4u,2);
goto P_0c0beb28;
P_0c0beb28: /* original 4d0b, guest PC 0x0c0beb28 */
if(!s->budget--) { s->failed_pc=0x0c0beb28u; return 0; }
target=r[13];
r[16]=0x0c0beb2cu;
r[5]=read(ram,r[14]+28,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0beb2cu) { target=s->pc; goto dispatch; }
goto P_0c0beb2c;
P_0c0beb2a: /* original 55e7, guest PC 0x0c0beb2a */
if(!s->budget--) { s->failed_pc=0x0c0beb2au; return 0; }
r[5]=read(ram,r[14]+28,4);
goto P_0c0beb2c;
P_0c0beb2c: /* original 9463, guest PC 0x0c0beb2c */
if(!s->budget--) { s->failed_pc=0x0c0beb2cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bebf6u,2);
goto P_0c0beb2e;
P_0c0beb2e: /* original 4d0b, guest PC 0x0c0beb2e */
if(!s->budget--) { s->failed_pc=0x0c0beb2eu; return 0; }
target=r[13];
r[16]=0x0c0beb32u;
r[5]=read(ram,r[14]+32,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0beb32u) { target=s->pc; goto dispatch; }
goto P_0c0beb32;
P_0c0beb30: /* original 55e8, guest PC 0x0c0beb30 */
if(!s->budget--) { s->failed_pc=0x0c0beb30u; return 0; }
r[5]=read(ram,r[14]+32,4);
goto P_0c0beb32;
P_0c0beb32: /* original 9461, guest PC 0x0c0beb32 */
if(!s->budget--) { s->failed_pc=0x0c0beb32u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bebf8u,2);
goto P_0c0beb34;
P_0c0beb34: /* original 4d0b, guest PC 0x0c0beb34 */
if(!s->budget--) { s->failed_pc=0x0c0beb34u; return 0; }
target=r[13];
r[16]=0x0c0beb38u;
r[5]=read(ram,r[14]+36,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0beb38u) { target=s->pc; goto dispatch; }
goto P_0c0beb38;
P_0c0beb36: /* original 55e9, guest PC 0x0c0beb36 */
if(!s->budget--) { s->failed_pc=0x0c0beb36u; return 0; }
r[5]=read(ram,r[14]+36,4);
goto P_0c0beb38;
P_0c0beb38: /* original 945f, guest PC 0x0c0beb38 */
if(!s->budget--) { s->failed_pc=0x0c0beb38u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bebfau,2);
goto P_0c0beb3a;
P_0c0beb3a: /* original 4d0b, guest PC 0x0c0beb3a */
if(!s->budget--) { s->failed_pc=0x0c0beb3au; return 0; }
target=r[13];
r[16]=0x0c0beb3eu;
r[5]=read(ram,r[14]+40,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0beb3eu) { target=s->pc; goto dispatch; }
goto P_0c0beb3e;
P_0c0beb3c: /* original 55ea, guest PC 0x0c0beb3c */
if(!s->budget--) { s->failed_pc=0x0c0beb3cu; return 0; }
r[5]=read(ram,r[14]+40,4);
goto P_0c0beb3e;
P_0c0beb3e: /* original 945d, guest PC 0x0c0beb3e */
if(!s->budget--) { s->failed_pc=0x0c0beb3eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bebfcu,2);
goto P_0c0beb40;
P_0c0beb40: /* original 4d0b, guest PC 0x0c0beb40 */
if(!s->budget--) { s->failed_pc=0x0c0beb40u; return 0; }
target=r[13];
r[16]=0x0c0beb44u;
r[5]=read(ram,r[14]+44,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0beb44u) { target=s->pc; goto dispatch; }
goto P_0c0beb44;
P_0c0beb42: /* original 55eb, guest PC 0x0c0beb42 */
if(!s->budget--) { s->failed_pc=0x0c0beb42u; return 0; }
r[5]=read(ram,r[14]+44,4);
goto P_0c0beb44;
P_0c0beb44: /* original 945b, guest PC 0x0c0beb44 */
if(!s->budget--) { s->failed_pc=0x0c0beb44u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bebfeu,2);
goto P_0c0beb46;
P_0c0beb46: /* original 4d0b, guest PC 0x0c0beb46 */
if(!s->budget--) { s->failed_pc=0x0c0beb46u; return 0; }
target=r[13];
r[16]=0x0c0beb4au;
r[5]=read(ram,r[14]+48,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0beb4au) { target=s->pc; goto dispatch; }
goto P_0c0beb4a;
P_0c0beb48: /* original 55ec, guest PC 0x0c0beb48 */
if(!s->budget--) { s->failed_pc=0x0c0beb48u; return 0; }
r[5]=read(ram,r[14]+48,4);
goto P_0c0beb4a;
P_0c0beb4a: /* original 9459, guest PC 0x0c0beb4a */
if(!s->budget--) { s->failed_pc=0x0c0beb4au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bec00u,2);
goto P_0c0beb4c;
P_0c0beb4c: /* original 4d0b, guest PC 0x0c0beb4c */
if(!s->budget--) { s->failed_pc=0x0c0beb4cu; return 0; }
target=r[13];
r[16]=0x0c0beb50u;
r[5]=read(ram,r[14]+52,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0beb50u) { target=s->pc; goto dispatch; }
goto P_0c0beb50;
P_0c0beb4e: /* original 55ed, guest PC 0x0c0beb4e */
if(!s->budget--) { s->failed_pc=0x0c0beb4eu; return 0; }
r[5]=read(ram,r[14]+52,4);
goto P_0c0beb50;
P_0c0beb50: /* original 9457, guest PC 0x0c0beb50 */
if(!s->budget--) { s->failed_pc=0x0c0beb50u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bec02u,2);
goto P_0c0beb52;
P_0c0beb52: /* original 4d0b, guest PC 0x0c0beb52 */
if(!s->budget--) { s->failed_pc=0x0c0beb52u; return 0; }
target=r[13];
r[16]=0x0c0beb56u;
r[5]=read(ram,r[14]+56,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0beb56u) { target=s->pc; goto dispatch; }
goto P_0c0beb56;
P_0c0beb54: /* original 55ee, guest PC 0x0c0beb54 */
if(!s->budget--) { s->failed_pc=0x0c0beb54u; return 0; }
r[5]=read(ram,r[14]+56,4);
goto P_0c0beb56;
P_0c0beb56: /* original 9455, guest PC 0x0c0beb56 */
if(!s->budget--) { s->failed_pc=0x0c0beb56u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bec04u,2);
goto P_0c0beb58;
P_0c0beb58: /* original 4d0b, guest PC 0x0c0beb58 */
if(!s->budget--) { s->failed_pc=0x0c0beb58u; return 0; }
target=r[13];
r[16]=0x0c0beb5cu;
r[5]=read(ram,r[14]+60,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0beb5cu) { target=s->pc; goto dispatch; }
goto P_0c0beb5c;
P_0c0beb5a: /* original 55ef, guest PC 0x0c0beb5a */
if(!s->budget--) { s->failed_pc=0x0c0beb5au; return 0; }
r[5]=read(ram,r[14]+60,4);
goto P_0c0beb5c;
P_0c0beb5c: /* original 9453, guest PC 0x0c0beb5c */
if(!s->budget--) { s->failed_pc=0x0c0beb5cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bec06u,2);
goto P_0c0beb5e;
P_0c0beb5e: /* original e040, guest PC 0x0c0beb5e */
if(!s->budget--) { s->failed_pc=0x0c0beb5eu; return 0; }
r[0]=0x00000040u;
goto P_0c0beb60;
P_0c0beb60: /* original 4d0b, guest PC 0x0c0beb60 */
if(!s->budget--) { s->failed_pc=0x0c0beb60u; return 0; }
target=r[13];
r[16]=0x0c0beb64u;
r[5]=read(ram,r[14]+r[0],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0beb64u) { target=s->pc; goto dispatch; }
goto P_0c0beb64;
P_0c0beb62: /* original 05ee, guest PC 0x0c0beb62 */
if(!s->budget--) { s->failed_pc=0x0c0beb62u; return 0; }
r[5]=read(ram,r[14]+r[0],4);
goto P_0c0beb64;
P_0c0beb64: /* original 9450, guest PC 0x0c0beb64 */
if(!s->budget--) { s->failed_pc=0x0c0beb64u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bec08u,2);
goto P_0c0beb66;
P_0c0beb66: /* original e044, guest PC 0x0c0beb66 */
if(!s->budget--) { s->failed_pc=0x0c0beb66u; return 0; }
r[0]=0x00000044u;
goto P_0c0beb68;
P_0c0beb68: /* original 4d0b, guest PC 0x0c0beb68 */
if(!s->budget--) { s->failed_pc=0x0c0beb68u; return 0; }
target=r[13];
r[16]=0x0c0beb6cu;
r[5]=read(ram,r[14]+r[0],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0beb6cu) { target=s->pc; goto dispatch; }
goto P_0c0beb6c;
P_0c0beb6a: /* original 05ee, guest PC 0x0c0beb6a */
if(!s->budget--) { s->failed_pc=0x0c0beb6au; return 0; }
r[5]=read(ram,r[14]+r[0],4);
goto P_0c0beb6c;
P_0c0beb6c: /* original 944d, guest PC 0x0c0beb6c */
if(!s->budget--) { s->failed_pc=0x0c0beb6cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bec0au,2);
goto P_0c0beb6e;
P_0c0beb6e: /* original e048, guest PC 0x0c0beb6e */
if(!s->budget--) { s->failed_pc=0x0c0beb6eu; return 0; }
r[0]=0x00000048u;
goto P_0c0beb70;
P_0c0beb70: /* original 4d0b, guest PC 0x0c0beb70 */
if(!s->budget--) { s->failed_pc=0x0c0beb70u; return 0; }
target=r[13];
r[16]=0x0c0beb74u;
r[5]=read(ram,r[14]+r[0],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0beb74u) { target=s->pc; goto dispatch; }
goto P_0c0beb74;
P_0c0beb72: /* original 05ee, guest PC 0x0c0beb72 */
if(!s->budget--) { s->failed_pc=0x0c0beb72u; return 0; }
r[5]=read(ram,r[14]+r[0],4);
goto P_0c0beb74;
P_0c0beb74: /* original 944a, guest PC 0x0c0beb74 */
if(!s->budget--) { s->failed_pc=0x0c0beb74u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bec0cu,2);
goto P_0c0beb76;
P_0c0beb76: /* original e04c, guest PC 0x0c0beb76 */
if(!s->budget--) { s->failed_pc=0x0c0beb76u; return 0; }
r[0]=0x0000004cu;
goto P_0c0beb78;
P_0c0beb78: /* original 4d0b, guest PC 0x0c0beb78 */
if(!s->budget--) { s->failed_pc=0x0c0beb78u; return 0; }
target=r[13];
r[16]=0x0c0beb7cu;
r[5]=read(ram,r[14]+r[0],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0beb7cu) { target=s->pc; goto dispatch; }
goto P_0c0beb7c;
P_0c0beb7a: /* original 05ee, guest PC 0x0c0beb7a */
if(!s->budget--) { s->failed_pc=0x0c0beb7au; return 0; }
r[5]=read(ram,r[14]+r[0],4);
goto P_0c0beb7c;
P_0c0beb7c: /* original 9447, guest PC 0x0c0beb7c */
if(!s->budget--) { s->failed_pc=0x0c0beb7cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bec0eu,2);
goto P_0c0beb7e;
P_0c0beb7e: /* original e050, guest PC 0x0c0beb7e */
if(!s->budget--) { s->failed_pc=0x0c0beb7eu; return 0; }
r[0]=0x00000050u;
goto P_0c0beb80;
P_0c0beb80: /* original 4d0b, guest PC 0x0c0beb80 */
if(!s->budget--) { s->failed_pc=0x0c0beb80u; return 0; }
target=r[13];
r[16]=0x0c0beb84u;
r[5]=read(ram,r[14]+r[0],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0beb84u) { target=s->pc; goto dispatch; }
goto P_0c0beb84;
P_0c0beb82: /* original 05ee, guest PC 0x0c0beb82 */
if(!s->budget--) { s->failed_pc=0x0c0beb82u; return 0; }
r[5]=read(ram,r[14]+r[0],4);
goto P_0c0beb84;
P_0c0beb84: /* original 9444, guest PC 0x0c0beb84 */
if(!s->budget--) { s->failed_pc=0x0c0beb84u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bec10u,2);
goto P_0c0beb86;
P_0c0beb86: /* original e054, guest PC 0x0c0beb86 */
if(!s->budget--) { s->failed_pc=0x0c0beb86u; return 0; }
r[0]=0x00000054u;
goto P_0c0beb88;
P_0c0beb88: /* original 4d0b, guest PC 0x0c0beb88 */
if(!s->budget--) { s->failed_pc=0x0c0beb88u; return 0; }
target=r[13];
r[16]=0x0c0beb8cu;
r[5]=read(ram,r[14]+r[0],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0beb8cu) { target=s->pc; goto dispatch; }
goto P_0c0beb8c;
P_0c0beb8a: /* original 05ee, guest PC 0x0c0beb8a */
if(!s->budget--) { s->failed_pc=0x0c0beb8au; return 0; }
r[5]=read(ram,r[14]+r[0],4);
goto P_0c0beb8c;
P_0c0beb8c: /* original 9441, guest PC 0x0c0beb8c */
if(!s->budget--) { s->failed_pc=0x0c0beb8cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bec12u,2);
goto P_0c0beb8e;
P_0c0beb8e: /* original e058, guest PC 0x0c0beb8e */
if(!s->budget--) { s->failed_pc=0x0c0beb8eu; return 0; }
r[0]=0x00000058u;
goto P_0c0beb90;
P_0c0beb90: /* original 4d0b, guest PC 0x0c0beb90 */
if(!s->budget--) { s->failed_pc=0x0c0beb90u; return 0; }
target=r[13];
r[16]=0x0c0beb94u;
r[5]=read(ram,r[14]+r[0],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0beb94u) { target=s->pc; goto dispatch; }
goto P_0c0beb94;
P_0c0beb92: /* original 05ee, guest PC 0x0c0beb92 */
if(!s->budget--) { s->failed_pc=0x0c0beb92u; return 0; }
r[5]=read(ram,r[14]+r[0],4);
goto P_0c0beb94;
P_0c0beb94: /* original 943e, guest PC 0x0c0beb94 */
if(!s->budget--) { s->failed_pc=0x0c0beb94u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bec14u,2);
goto P_0c0beb96;
P_0c0beb96: /* original e05c, guest PC 0x0c0beb96 */
if(!s->budget--) { s->failed_pc=0x0c0beb96u; return 0; }
r[0]=0x0000005cu;
goto P_0c0beb98;
P_0c0beb98: /* original 4d0b, guest PC 0x0c0beb98 */
if(!s->budget--) { s->failed_pc=0x0c0beb98u; return 0; }
target=r[13];
r[16]=0x0c0beb9cu;
r[5]=read(ram,r[14]+r[0],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0beb9cu) { target=s->pc; goto dispatch; }
goto P_0c0beb9c;
P_0c0beb9a: /* original 05ee, guest PC 0x0c0beb9a */
if(!s->budget--) { s->failed_pc=0x0c0beb9au; return 0; }
r[5]=read(ram,r[14]+r[0],4);
goto P_0c0beb9c;
P_0c0beb9c: /* original 943b, guest PC 0x0c0beb9c */
if(!s->budget--) { s->failed_pc=0x0c0beb9cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bec16u,2);
goto P_0c0beb9e;
P_0c0beb9e: /* original e060, guest PC 0x0c0beb9e */
if(!s->budget--) { s->failed_pc=0x0c0beb9eu; return 0; }
r[0]=0x00000060u;
goto P_0c0beba0;
P_0c0beba0: /* original 4d0b, guest PC 0x0c0beba0 */
if(!s->budget--) { s->failed_pc=0x0c0beba0u; return 0; }
target=r[13];
r[16]=0x0c0beba4u;
r[5]=read(ram,r[14]+r[0],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0beba4u) { target=s->pc; goto dispatch; }
goto P_0c0beba4;
P_0c0beba2: /* original 05ee, guest PC 0x0c0beba2 */
if(!s->budget--) { s->failed_pc=0x0c0beba2u; return 0; }
r[5]=read(ram,r[14]+r[0],4);
goto P_0c0beba4;
P_0c0beba4: /* original 9438, guest PC 0x0c0beba4 */
if(!s->budget--) { s->failed_pc=0x0c0beba4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bec18u,2);
goto P_0c0beba6;
P_0c0beba6: /* original e064, guest PC 0x0c0beba6 */
if(!s->budget--) { s->failed_pc=0x0c0beba6u; return 0; }
r[0]=0x00000064u;
goto P_0c0beba8;
P_0c0beba8: /* original 4d0b, guest PC 0x0c0beba8 */
if(!s->budget--) { s->failed_pc=0x0c0beba8u; return 0; }
target=r[13];
r[16]=0x0c0bebacu;
r[5]=read(ram,r[14]+r[0],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0bebacu) { target=s->pc; goto dispatch; }
goto P_0c0bebac;
P_0c0bebaa: /* original 05ee, guest PC 0x0c0bebaa */
if(!s->budget--) { s->failed_pc=0x0c0bebaau; return 0; }
r[5]=read(ram,r[14]+r[0],4);
goto P_0c0bebac;
P_0c0bebac: /* original 9435, guest PC 0x0c0bebac */
if(!s->budget--) { s->failed_pc=0x0c0bebacu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bec1au,2);
goto P_0c0bebae;
P_0c0bebae: /* original e070, guest PC 0x0c0bebae */
if(!s->budget--) { s->failed_pc=0x0c0bebaeu; return 0; }
r[0]=0x00000070u;
goto P_0c0bebb0;
P_0c0bebb0: /* original 4d0b, guest PC 0x0c0bebb0 */
if(!s->budget--) { s->failed_pc=0x0c0bebb0u; return 0; }
target=r[13];
r[16]=0x0c0bebb4u;
r[5]=read(ram,r[14]+r[0],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0bebb4u) { target=s->pc; goto dispatch; }
goto P_0c0bebb4;
P_0c0bebb2: /* original 05ee, guest PC 0x0c0bebb2 */
if(!s->budget--) { s->failed_pc=0x0c0bebb2u; return 0; }
r[5]=read(ram,r[14]+r[0],4);
goto P_0c0bebb4;
P_0c0bebb4: /* original 9432, guest PC 0x0c0bebb4 */
if(!s->budget--) { s->failed_pc=0x0c0bebb4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bec1cu,2);
goto P_0c0bebb6;
P_0c0bebb6: /* original e078, guest PC 0x0c0bebb6 */
if(!s->budget--) { s->failed_pc=0x0c0bebb6u; return 0; }
r[0]=0x00000078u;
goto P_0c0bebb8;
P_0c0bebb8: /* original 4d0b, guest PC 0x0c0bebb8 */
if(!s->budget--) { s->failed_pc=0x0c0bebb8u; return 0; }
target=r[13];
r[16]=0x0c0bebbcu;
r[5]=read(ram,r[14]+r[0],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0bebbcu) { target=s->pc; goto dispatch; }
goto P_0c0bebbc;
P_0c0bebba: /* original 05ee, guest PC 0x0c0bebba */
if(!s->budget--) { s->failed_pc=0x0c0bebbau; return 0; }
r[5]=read(ram,r[14]+r[0],4);
goto P_0c0bebbc;
P_0c0bebbc: /* original 942f, guest PC 0x0c0bebbc */
if(!s->budget--) { s->failed_pc=0x0c0bebbcu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bec1eu,2);
goto P_0c0bebbe;
P_0c0bebbe: /* original e068, guest PC 0x0c0bebbe */
if(!s->budget--) { s->failed_pc=0x0c0bebbeu; return 0; }
r[0]=0x00000068u;
goto P_0c0bebc0;
P_0c0bebc0: /* original 4d0b, guest PC 0x0c0bebc0 */
if(!s->budget--) { s->failed_pc=0x0c0bebc0u; return 0; }
target=r[13];
r[16]=0x0c0bebc4u;
r[5]=read(ram,r[14]+r[0],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0bebc4u) { target=s->pc; goto dispatch; }
goto P_0c0bebc4;
P_0c0bebc2: /* original 05ee, guest PC 0x0c0bebc2 */
if(!s->budget--) { s->failed_pc=0x0c0bebc2u; return 0; }
r[5]=read(ram,r[14]+r[0],4);
goto P_0c0bebc4;
P_0c0bebc4: /* original 942c, guest PC 0x0c0bebc4 */
if(!s->budget--) { s->failed_pc=0x0c0bebc4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bec20u,2);
goto P_0c0bebc6;
P_0c0bebc6: /* original e06c, guest PC 0x0c0bebc6 */
if(!s->budget--) { s->failed_pc=0x0c0bebc6u; return 0; }
r[0]=0x0000006cu;
goto P_0c0bebc8;
P_0c0bebc8: /* original 4d0b, guest PC 0x0c0bebc8 */
if(!s->budget--) { s->failed_pc=0x0c0bebc8u; return 0; }
target=r[13];
r[16]=0x0c0bebccu;
r[5]=read(ram,r[14]+r[0],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0bebccu) { target=s->pc; goto dispatch; }
goto P_0c0bebcc;
P_0c0bebca: /* original 05ee, guest PC 0x0c0bebca */
if(!s->budget--) { s->failed_pc=0x0c0bebcau; return 0; }
r[5]=read(ram,r[14]+r[0],4);
goto P_0c0bebcc;
P_0c0bebcc: /* original 9429, guest PC 0x0c0bebcc */
if(!s->budget--) { s->failed_pc=0x0c0bebccu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bec22u,2);
goto P_0c0bebce;
P_0c0bebce: /* original e074, guest PC 0x0c0bebce */
if(!s->budget--) { s->failed_pc=0x0c0bebceu; return 0; }
r[0]=0x00000074u;
goto P_0c0bebd0;
P_0c0bebd0: /* original 4d0b, guest PC 0x0c0bebd0 */
if(!s->budget--) { s->failed_pc=0x0c0bebd0u; return 0; }
target=r[13];
r[16]=0x0c0bebd4u;
r[5]=read(ram,r[14]+r[0],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0bebd4u) { target=s->pc; goto dispatch; }
goto P_0c0bebd4;
P_0c0bebd2: /* original 05ee, guest PC 0x0c0bebd2 */
if(!s->budget--) { s->failed_pc=0x0c0bebd2u; return 0; }
r[5]=read(ram,r[14]+r[0],4);
goto P_0c0bebd4;
P_0c0bebd4: /* original 9426, guest PC 0x0c0bebd4 */
if(!s->budget--) { s->failed_pc=0x0c0bebd4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bec24u,2);
goto P_0c0bebd6;
P_0c0bebd6: /* original 65e3, guest PC 0x0c0bebd6 */
if(!s->budget--) { s->failed_pc=0x0c0bebd6u; return 0; }
r[5]=r[14];
goto P_0c0bebd8;
P_0c0bebd8: /* original 757c, guest PC 0x0c0bebd8 */
if(!s->budget--) { s->failed_pc=0x0c0bebd8u; return 0; }
r[5]+=0x0000007cu;
goto P_0c0bebda;
P_0c0bebda: /* original 4d0b, guest PC 0x0c0bebda */
if(!s->budget--) { s->failed_pc=0x0c0bebdau; return 0; }
target=r[13];
r[16]=0x0c0bebdeu;
tmp=read(ram,r[5],4);
r[5]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0bebdeu) { target=s->pc; goto dispatch; }
goto P_0c0bebde;
P_0c0bebdc: /* original 6552, guest PC 0x0c0bebdc */
if(!s->budget--) { s->failed_pc=0x0c0bebdcu; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0bebde;
P_0c0bebde: /* original 4f26, guest PC 0x0c0bebde */
if(!s->budget--) { s->failed_pc=0x0c0bebdeu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0bebe0;
P_0c0bebe0: /* original 6df6, guest PC 0x0c0bebe0 */
if(!s->budget--) { s->failed_pc=0x0c0bebe0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0bebe2;
P_0c0bebe2: /* original 000b, guest PC 0x0c0bebe2 */
if(!s->budget--) { s->failed_pc=0x0c0bebe2u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0bebe4: /* original 6ef6, guest PC 0x0c0bebe4 */
if(!s->budget--) { s->failed_pc=0x0c0bebe4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0bebe6u,s,ram);
P_0c0c1192: /* original 2fe6, guest PC 0x0c0c1192 */
if(!s->budget--) { s->failed_pc=0x0c0c1192u; return 0; }
r[15]-=4; write(ram,r[15],r[14],4);
goto P_0c0c1194;
P_0c0c1194: /* original d314, guest PC 0x0c0c1194 */
if(!s->budget--) { s->failed_pc=0x0c0c1194u; return 0; }
r[3]=read(ram,0x0c0c11e8u,4);
goto P_0c0c1196;
P_0c0c1196: /* original 7ffc, guest PC 0x0c0c1196 */
if(!s->budget--) { s->failed_pc=0x0c0c1196u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c0c1198;
P_0c0c1198: /* original d114, guest PC 0x0c0c1198 */
if(!s->budget--) { s->failed_pc=0x0c0c1198u; return 0; }
r[1]=read(ram,0x0c0c11ecu,4);
goto P_0c0c119a;
P_0c0c119a: /* original 6e32, guest PC 0x0c0c119a */
if(!s->budget--) { s->failed_pc=0x0c0c119au; return 0; }
tmp=read(ram,r[3],4);
r[14]=tmp;
goto P_0c0c119c;
P_0c0c119c: /* original 6210, guest PC 0x0c0c119c */
if(!s->budget--) { s->failed_pc=0x0c0c119cu; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[1],1);
r[2]=tmp;
goto P_0c0c119e;
P_0c0c119e: /* original 622c, guest PC 0x0c0c119e */
if(!s->budget--) { s->failed_pc=0x0c0c119eu; return 0; }
r[2]=r[2]&255u;
goto P_0c0c11a0;
P_0c0c11a0: /* original 2f22, guest PC 0x0c0c11a0 */
if(!s->budget--) { s->failed_pc=0x0c0c11a0u; return 0; }
write(ram,r[15],r[2],4);
goto P_0c0c11a2;
P_0c0c11a2: /* original d313, guest PC 0x0c0c11a2 */
if(!s->budget--) { s->failed_pc=0x0c0c11a2u; return 0; }
r[3]=read(ram,0x0c0c11f0u,4);
goto P_0c0c11a4;
P_0c0c11a4: /* original 2e39, guest PC 0x0c0c11a4 */
if(!s->budget--) { s->failed_pc=0x0c0c11a4u; return 0; }
r[14]&=r[3];
goto P_0c0c11a6;
P_0c0c11a6: /* original 2ee8, guest PC 0x0c0c11a6 */
if(!s->budget--) { s->failed_pc=0x0c0c11a6u; return 0; }
r[17]=(r[17]&~1u)|(((r[14]&r[14])==0)!=0);
goto P_0c0c11a8;
P_0c0c11a8: /* original 8b0e, guest PC 0x0c0c11a8 */
if(!s->budget--) { s->failed_pc=0x0c0c11a8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c11c8; }
goto P_0c0c11aa;
P_0c0c11aa: /* original 60f2, guest PC 0x0c0c11aa */
if(!s->budget--) { s->failed_pc=0x0c0c11aau; return 0; }
tmp=read(ram,r[15],4);
r[0]=tmp;
goto P_0c0c11ac;
P_0c0c11ac: /* original 8801, guest PC 0x0c0c11ac */
if(!s->budget--) { s->failed_pc=0x0c0c11acu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c0c11ae;
P_0c0c11ae: /* original 890b, guest PC 0x0c0c11ae */
if(!s->budget--) { s->failed_pc=0x0c0c11aeu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c11c8; }
goto P_0c0c11b0;
P_0c0c11b0: /* original ee3f, guest PC 0x0c0c11b0 */
if(!s->budget--) { s->failed_pc=0x0c0c11b0u; return 0; }
r[14]=0x0000003fu;
goto P_0c0c11b2;
P_0c0c11b2: /* original 26e9, guest PC 0x0c0c11b2 */
if(!s->budget--) { s->failed_pc=0x0c0c11b2u; return 0; }
r[6]&=r[14];
goto P_0c0c11b4;
P_0c0c11b4: /* original 4618, guest PC 0x0c0c11b4 */
if(!s->budget--) { s->failed_pc=0x0c0c11b4u; return 0; }
r[6]<<=8;
goto P_0c0c11b6;
P_0c0c11b6: /* original 25e9, guest PC 0x0c0c11b6 */
if(!s->budget--) { s->failed_pc=0x0c0c11b6u; return 0; }
r[5]&=r[14];
goto P_0c0c11b8;
P_0c0c11b8: /* original 27e9, guest PC 0x0c0c11b8 */
if(!s->budget--) { s->failed_pc=0x0c0c11b8u; return 0; }
r[7]&=r[14];
goto P_0c0c11ba;
P_0c0c11ba: /* original 4728, guest PC 0x0c0c11ba */
if(!s->budget--) { s->failed_pc=0x0c0c11bau; return 0; }
r[7]<<=16;
goto P_0c0c11bc;
P_0c0c11bc: /* original 4508, guest PC 0x0c0c11bc */
if(!s->budget--) { s->failed_pc=0x0c0c11bcu; return 0; }
r[5]<<=2;
goto P_0c0c11be;
P_0c0c11be: /* original 4608, guest PC 0x0c0c11be */
if(!s->budget--) { s->failed_pc=0x0c0c11beu; return 0; }
r[6]<<=2;
goto P_0c0c11c0;
P_0c0c11c0: /* original 4708, guest PC 0x0c0c11c0 */
if(!s->budget--) { s->failed_pc=0x0c0c11c0u; return 0; }
r[7]<<=2;
goto P_0c0c11c2;
P_0c0c11c2: /* original 256b, guest PC 0x0c0c11c2 */
if(!s->budget--) { s->failed_pc=0x0c0c11c2u; return 0; }
r[5]|=r[6];
goto P_0c0c11c4;
P_0c0c11c4: /* original 257b, guest PC 0x0c0c11c4 */
if(!s->budget--) { s->failed_pc=0x0c0c11c4u; return 0; }
r[5]|=r[7];
goto P_0c0c11c6;
P_0c0c11c6: /* original 2452, guest PC 0x0c0c11c6 */
if(!s->budget--) { s->failed_pc=0x0c0c11c6u; return 0; }
write(ram,r[4],r[5],4);
goto P_0c0c11c8;
P_0c0c11c8: /* original 7f04, guest PC 0x0c0c11c8 */
if(!s->budget--) { s->failed_pc=0x0c0c11c8u; return 0; }
r[15]+=0x00000004u;
goto P_0c0c11ca;
P_0c0c11ca: /* original 000b, guest PC 0x0c0c11ca */
if(!s->budget--) { s->failed_pc=0x0c0c11cau; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0c11cc: /* original 6ef6, guest PC 0x0c0c11cc */
if(!s->budget--) { s->failed_pc=0x0c0c11ccu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0c11ceu,s,ram);
P_0c0ca078: /* original c740, guest PC 0x0c0ca078 */
if(!s->budget--) { s->failed_pc=0x0c0ca078u; return 0; }
r[0]=0x0c0ca17cu;
goto P_0c0ca07a;
P_0c0ca07a: /* original d43f, guest PC 0x0c0ca07a */
if(!s->budget--) { s->failed_pc=0x0c0ca07au; return 0; }
r[4]=read(ram,0x0c0ca178u,4);
goto P_0c0ca07c;
P_0c0ca07c: /* original f508, guest PC 0x0c0ca07c */
if(!s->budget--) { s->failed_pc=0x0c0ca07cu; return 0; }
vf3_matrix_load(s,ram,5,r[0]);
goto P_0c0ca07e;
P_0c0ca07e: /* original e004, guest PC 0x0c0ca07e */
if(!s->budget--) { s->failed_pc=0x0c0ca07eu; return 0; }
r[0]=0x00000004u;
goto P_0c0ca080;
P_0c0ca080: /* original f69d, guest PC 0x0c0ca080 */
if(!s->budget--) { s->failed_pc=0x0c0ca080u; return 0; }
fr[6]=0x3f800000u;
goto P_0c0ca082;
P_0c0ca082: /* original e600, guest PC 0x0c0ca082 */
if(!s->budget--) { s->failed_pc=0x0c0ca082u; return 0; }
r[6]=0x00000000u;
goto P_0c0ca084;
P_0c0ca084: /* original f48d, guest PC 0x0c0ca084 */
if(!s->budget--) { s->failed_pc=0x0c0ca084u; return 0; }
fr[4]=0;
goto P_0c0ca086;
P_0c0ca086: /* original d53b, guest PC 0x0c0ca086 */
if(!s->budget--) { s->failed_pc=0x0c0ca086u; return 0; }
r[5]=read(ram,0x0c0ca174u,4);
goto P_0c0ca088;
P_0c0ca088: /* original f467, guest PC 0x0c0ca088 */
if(!s->budget--) { s->failed_pc=0x0c0ca088u; return 0; }
vf3_matrix_store(s,ram,6,r[4]+r[0]);
goto P_0c0ca08a;
P_0c0ca08a: /* original e008, guest PC 0x0c0ca08a */
if(!s->budget--) { s->failed_pc=0x0c0ca08au; return 0; }
r[0]=0x00000008u;
goto P_0c0ca08c;
P_0c0ca08c: /* original f447, guest PC 0x0c0ca08c */
if(!s->budget--) { s->failed_pc=0x0c0ca08cu; return 0; }
vf3_matrix_store(s,ram,4,r[4]+r[0]);
goto P_0c0ca08e;
P_0c0ca08e: /* original e00c, guest PC 0x0c0ca08e */
if(!s->budget--) { s->failed_pc=0x0c0ca08eu; return 0; }
r[0]=0x0000000cu;
goto P_0c0ca090;
P_0c0ca090: /* original f447, guest PC 0x0c0ca090 */
if(!s->budget--) { s->failed_pc=0x0c0ca090u; return 0; }
vf3_matrix_store(s,ram,4,r[4]+r[0]);
goto P_0c0ca092;
P_0c0ca092: /* original e010, guest PC 0x0c0ca092 */
if(!s->budget--) { s->failed_pc=0x0c0ca092u; return 0; }
r[0]=0x00000010u;
goto P_0c0ca094;
P_0c0ca094: /* original f467, guest PC 0x0c0ca094 */
if(!s->budget--) { s->failed_pc=0x0c0ca094u; return 0; }
vf3_matrix_store(s,ram,6,r[4]+r[0]);
goto P_0c0ca096;
P_0c0ca096: /* original e014, guest PC 0x0c0ca096 */
if(!s->budget--) { s->failed_pc=0x0c0ca096u; return 0; }
r[0]=0x00000014u;
goto P_0c0ca098;
P_0c0ca098: /* original f457, guest PC 0x0c0ca098 */
if(!s->budget--) { s->failed_pc=0x0c0ca098u; return 0; }
vf3_matrix_store(s,ram,5,r[4]+r[0]);
goto P_0c0ca09a;
P_0c0ca09a: /* original e01a, guest PC 0x0c0ca09a */
if(!s->budget--) { s->failed_pc=0x0c0ca09au; return 0; }
r[0]=0x0000001au;
goto P_0c0ca09c;
P_0c0ca09c: /* original 0464, guest PC 0x0c0ca09c */
if(!s->budget--) { s->failed_pc=0x0c0ca09cu; return 0; }
write(ram,r[4]+r[0],r[6],1);
goto P_0c0ca09e;
P_0c0ca09e: /* original e019, guest PC 0x0c0ca09e */
if(!s->budget--) { s->failed_pc=0x0c0ca09eu; return 0; }
r[0]=0x00000019u;
goto P_0c0ca0a0;
P_0c0ca0a0: /* original 0464, guest PC 0x0c0ca0a0 */
if(!s->budget--) { s->failed_pc=0x0c0ca0a0u; return 0; }
write(ram,r[4]+r[0],r[6],1);
goto P_0c0ca0a2;
P_0c0ca0a2: /* original e018, guest PC 0x0c0ca0a2 */
if(!s->budget--) { s->failed_pc=0x0c0ca0a2u; return 0; }
r[0]=0x00000018u;
goto P_0c0ca0a4;
P_0c0ca0a4: /* original 0464, guest PC 0x0c0ca0a4 */
if(!s->budget--) { s->failed_pc=0x0c0ca0a4u; return 0; }
write(ram,r[4]+r[0],r[6],1);
goto P_0c0ca0a6;
P_0c0ca0a6: /* original e01c, guest PC 0x0c0ca0a6 */
if(!s->budget--) { s->failed_pc=0x0c0ca0a6u; return 0; }
r[0]=0x0000001cu;
goto P_0c0ca0a8;
P_0c0ca0a8: /* original f447, guest PC 0x0c0ca0a8 */
if(!s->budget--) { s->failed_pc=0x0c0ca0a8u; return 0; }
vf3_matrix_store(s,ram,4,r[4]+r[0]);
goto P_0c0ca0aa;
P_0c0ca0aa: /* original e020, guest PC 0x0c0ca0aa */
if(!s->budget--) { s->failed_pc=0x0c0ca0aau; return 0; }
r[0]=0x00000020u;
goto P_0c0ca0ac;
P_0c0ca0ac: /* original f447, guest PC 0x0c0ca0ac */
if(!s->budget--) { s->failed_pc=0x0c0ca0acu; return 0; }
vf3_matrix_store(s,ram,4,r[4]+r[0]);
goto P_0c0ca0ae;
P_0c0ca0ae: /* original e024, guest PC 0x0c0ca0ae */
if(!s->budget--) { s->failed_pc=0x0c0ca0aeu; return 0; }
r[0]=0x00000024u;
goto P_0c0ca0b0;
P_0c0ca0b0: /* original f447, guest PC 0x0c0ca0b0 */
if(!s->budget--) { s->failed_pc=0x0c0ca0b0u; return 0; }
vf3_matrix_store(s,ram,4,r[4]+r[0]);
goto P_0c0ca0b2;
P_0c0ca0b2: /* original e028, guest PC 0x0c0ca0b2 */
if(!s->budget--) { s->failed_pc=0x0c0ca0b2u; return 0; }
r[0]=0x00000028u;
goto P_0c0ca0b4;
P_0c0ca0b4: /* original f457, guest PC 0x0c0ca0b4 */
if(!s->budget--) { s->failed_pc=0x0c0ca0b4u; return 0; }
vf3_matrix_store(s,ram,5,r[4]+r[0]);
goto P_0c0ca0b6;
P_0c0ca0b6: /* original 6063, guest PC 0x0c0ca0b6 */
if(!s->budget--) { s->failed_pc=0x0c0ca0b6u; return 0; }
r[0]=r[6];
goto P_0c0ca0b8;
P_0c0ca0b8: /* original 000b, guest PC 0x0c0ca0b8 */
if(!s->budget--) { s->failed_pc=0x0c0ca0b8u; return 0; }
target=r[16];
write(ram,r[5]+1,r[0],1);
s->pc=target; return ram->oob==0;
P_0c0ca0ba: /* original 8051, guest PC 0x0c0ca0ba */
if(!s->budget--) { s->failed_pc=0x0c0ca0bau; return 0; }
write(ram,r[5]+1,r[0],1);
return vf3_matrix_family(0x0c0ca0bcu,s,ram);
unsupported: s->failed_pc=target; return 0;
}
static const uint32_t owned_pcs[]={
0x0c06cf30u,0x0c06cf32u,0x0c06cf34u,0x0c06cf36u,0x0c06cf38u,0x0c06cf3au,0x0c06cf3cu,0x0c06cf3eu,0x0c06cf40u,0x0c06cf42u,0x0c06cf44u,0x0c06cf46u,0x0c06cf48u,0x0c06cf4au,0x0c06cf4cu,0x0c06cf4eu,
0x0c06cf50u,0x0c06cf52u,0x0c06cf54u,0x0c06cf56u,0x0c06cf58u,0x0c06cf5au,0x0c06cf5cu,0x0c06cf5eu,0x0c06cf60u,0x0c06cf62u,0x0c06cf64u,0x0c06cf66u,0x0c06cf68u,0x0c06cf6au,0x0c06cf6cu,0x0c06cf6eu,
0x0c06cf70u,0x0c06cf72u,0x0c06cf74u,0x0c06cf76u,0x0c06cf78u,0x0c06cf7au,0x0c06cf7cu,0x0c06cf7eu,0x0c06cf80u,0x0c06cf82u,0x0c06cf84u,0x0c06cf86u,0x0c06cf88u,0x0c06cf8au,0x0c06cf8cu,0x0c06cf8eu,
0x0c06cf90u,0x0c06cf92u,0x0c06cf94u,0x0c06cf96u,0x0c06cf98u,0x0c06cf9au,0x0c06cf9cu,0x0c06cf9eu,0x0c06cfa0u,0x0c06cfa2u,0x0c06cfa4u,0x0c06cfa6u,0x0c06cfa8u,0x0c06cfaau,0x0c06cfacu,0x0c06cfaeu,
0x0c06cfb0u,0x0c06cfb2u,0x0c06cfb4u,0x0c06cfb6u,0x0c06cfb8u,0x0c06cfbau,0x0c06cfbcu,0x0c06cfbeu,0x0c06cfc0u,0x0c06cfc2u,0x0c06cfc4u,0x0c06cfc6u,0x0c06cfc8u,0x0c06cfcau,0x0c06cfccu,0x0c06cfceu,
0x0c072e2cu,0x0c072e2eu,0x0c072e30u,0x0c072e32u,0x0c072e34u,0x0c072e36u,0x0c072e38u,0x0c072e3au,0x0c072e3cu,0x0c072e3eu,0x0c072e40u,0x0c072e42u,0x0c072e44u,0x0c072e46u,0x0c072e48u,0x0c072e4au,
0x0c072e4cu,0x0c072e4eu,0x0c072e50u,0x0c072e52u,0x0c072e54u,0x0c072e56u,0x0c072e58u,0x0c072e5au,0x0c072e5cu,0x0c072e5eu,0x0c072e60u,0x0c072e62u,0x0c072e64u,0x0c072e66u,0x0c072e68u,0x0c072e6au,
0x0c072e6cu,0x0c072e6eu,0x0c072e70u,0x0c072e72u,0x0c072e74u,0x0c072e76u,0x0c072e78u,0x0c072e7au,0x0c072e7cu,0x0c072e7eu,0x0c072e80u,0x0c072e82u,0x0c072e84u,0x0c072e86u,0x0c072e88u,0x0c072e8au,
0x0c072e8cu,0x0c072e8eu,0x0c072e90u,0x0c072e92u,0x0c072e94u,0x0c072e96u,0x0c072e98u,0x0c072e9au,0x0c072e9cu,0x0c072e9eu,0x0c072ea0u,0x0c072ea2u,0x0c072ea4u,0x0c072ea6u,0x0c072ea8u,0x0c072eaau,
0x0c072eacu,0x0c072eaeu,0x0c072eb0u,0x0c072eb2u,0x0c072eb4u,0x0c072eb6u,0x0c072eb8u,0x0c072ebau,0x0c072ebcu,0x0c072ebeu,0x0c072ec0u,0x0c08e5ceu,0x0c08e5d0u,0x0c08e5d2u,0x0c08e5d4u,0x0c08e5d6u,
0x0c08e5d8u,0x0c08e5dau,0x0c08e5dcu,0x0c08e5deu,0x0c08e5e0u,0x0c08e5e2u,0x0c08e5e4u,0x0c08e5e6u,0x0c08e5e8u,0x0c08e5eau,0x0c08e5ecu,0x0c08e5eeu,0x0c08e5f0u,0x0c08e5f2u,0x0c08e5f4u,0x0c08e5f6u,
0x0c08e5f8u,0x0c08e5fau,0x0c08e5fcu,0x0c08e5feu,0x0c08e600u,0x0c08e602u,0x0c08e604u,0x0c08e606u,0x0c08e608u,0x0c08e60au,0x0c08e60cu,0x0c08e60eu,0x0c08e610u,0x0c08e612u,0x0c08e614u,0x0c08e616u,
0x0c08e618u,0x0c08e61au,0x0c08e61cu,0x0c08e61eu,0x0c08e620u,0x0c08e622u,0x0c08e624u,0x0c08e626u,0x0c08e628u,0x0c08e62au,0x0c08e62cu,0x0c08e62eu,0x0c08e630u,0x0c08e632u,0x0c08e634u,0x0c08e636u,
0x0c08e638u,0x0c08e63au,0x0c08e63cu,0x0c08e63eu,0x0c08e640u,0x0c08e642u,0x0c08e644u,0x0c08e646u,0x0c08e648u,0x0c08e64au,0x0c08e64cu,0x0c08e64eu,0x0c08e650u,0x0c08e652u,0x0c08e654u,0x0c08e656u,
0x0c08e658u,0x0c08e65au,0x0c08e65cu,0x0c08e65eu,0x0c08e660u,0x0c08e662u,0x0c08e664u,0x0c08e666u,0x0c08e668u,0x0c08e66au,0x0c08e66cu,0x0c08e66eu,0x0c09fe7au,0x0c09fe7cu,0x0c09fe7eu,0x0c09fe80u,
0x0c09fe82u,0x0c09fe84u,0x0c09fe86u,0x0c09fe88u,0x0c09fe8au,0x0c09fe8cu,0x0c09fe8eu,0x0c09fe90u,0x0c09fe92u,0x0c09fe94u,0x0c09fe96u,0x0c09fe98u,0x0c09fe9au,0x0c09fe9cu,0x0c09fe9eu,0x0c09fea0u,
0x0c09fea2u,0x0c09fea4u,0x0c09fea6u,0x0c09fea8u,0x0c09feaau,0x0c09feacu,0x0c09feaeu,0x0c09feb0u,0x0c09feb2u,0x0c09feb4u,0x0c09feb6u,0x0c09feb8u,0x0c09febau,0x0c09febcu,0x0c09febeu,0x0c09fec0u,
0x0c09fec2u,0x0c09fec4u,0x0c09fec6u,0x0c09fec8u,0x0c09fecau,0x0c09feccu,0x0c09feceu,0x0c09fed0u,0x0c09fed2u,0x0c09fed4u,0x0c09fed6u,0x0c09fed8u,0x0c09fedau,0x0c09fedcu,0x0c09fedeu,0x0c09fee0u,
0x0c09fee2u,0x0c09fee4u,0x0c09fee6u,0x0c09fee8u,0x0c09feeau,0x0c09feecu,0x0c09feeeu,0x0c09fef0u,0x0c09fef2u,0x0c09fef4u,0x0c09fef6u,0x0c09fef8u,0x0c09fefau,0x0c09fefcu,0x0c0a2e06u,0x0c0a2e08u,
0x0c0a2e0au,0x0c0a2e0cu,0x0c0a2e0eu,0x0c0a2e10u,0x0c0a2e12u,0x0c0a2e14u,0x0c0a2e16u,0x0c0a2e18u,0x0c0a2e1au,0x0c0a2e1cu,0x0c0a2e1eu,0x0c0a2e20u,0x0c0a2e22u,0x0c0a2e24u,0x0c0a2e26u,0x0c0a2e28u,
0x0c0a2e2au,0x0c0a2e2cu,0x0c0a2e2eu,0x0c0a2e30u,0x0c0a2e32u,0x0c0a2e34u,0x0c0a2e36u,0x0c0a2e38u,0x0c0a2e3au,0x0c0a2e3cu,0x0c0a2e3eu,0x0c0a2e40u,0x0c0a2e42u,0x0c0a2e44u,0x0c0a2e46u,0x0c0a3414u,
0x0c0a3416u,0x0c0a3418u,0x0c0a341au,0x0c0a341cu,0x0c0a341eu,0x0c0a3420u,0x0c0a3422u,0x0c0a3424u,0x0c0a3426u,0x0c0a3428u,0x0c0a342au,0x0c0a342cu,0x0c0a342eu,0x0c0a3430u,0x0c0a3432u,0x0c0a3434u,
0x0c0a3436u,0x0c0a3438u,0x0c0a343au,0x0c0a343cu,0x0c0a343eu,0x0c0a3440u,0x0c0a3442u,0x0c0a3444u,0x0c0a3446u,0x0c0a3448u,0x0c0a344au,0x0c0a344cu,0x0c0a344eu,0x0c0a3450u,0x0c0a3452u,0x0c0a3454u,
0x0c0a3456u,0x0c0a3458u,0x0c0a345au,0x0c0a345cu,0x0c0a345eu,0x0c0a3460u,0x0c0a3462u,0x0c0a3464u,0x0c0a3466u,0x0c0a3468u,0x0c0a346au,0x0c0a346cu,0x0c0a346eu,0x0c0a3470u,0x0c0a3472u,0x0c0a3474u,
0x0c0a3476u,0x0c0a3478u,0x0c0a347au,0x0c0a347cu,0x0c0a347eu,0x0c0a3480u,0x0c0a3482u,0x0c0a3484u,0x0c0a3486u,0x0c0a3488u,0x0c0a348au,0x0c0a348cu,0x0c0a348eu,0x0c0a3490u,0x0c0a3492u,0x0c0a3494u,
0x0c0a3496u,0x0c0a3498u,0x0c0a349au,0x0c0a349cu,0x0c0a349eu,0x0c0a34a0u,0x0c0a34a2u,0x0c0a34a4u,0x0c0a34a6u,0x0c0a34a8u,0x0c0a34aau,0x0c0a34acu,0x0c0a34aeu,0x0c0a34b0u,0x0c0a34b2u,0x0c0a34b4u,
0x0c0a34b6u,0x0c0a34b8u,0x0c0a34bau,0x0c0a34bcu,0x0c0a34beu,0x0c0a34c0u,0x0c0a34c2u,0x0c0a34c4u,0x0c0a34c6u,0x0c0a34c8u,0x0c0a34cau,0x0c0a34ccu,0x0c0a34ceu,0x0c0a34d0u,0x0c0a34d2u,0x0c0a34d4u,
0x0c0a34d6u,0x0c0a34d8u,0x0c0a34dau,0x0c0a3696u,0x0c0a3698u,0x0c0a369au,0x0c0a369cu,0x0c0a369eu,0x0c0a36a0u,0x0c0a36a2u,0x0c0a36a4u,0x0c0a36a6u,0x0c0a36a8u,0x0c0a36aau,0x0c0a36acu,0x0c0a36aeu,
0x0c0a36b0u,0x0c0a36b2u,0x0c0a36b4u,0x0c0a36b6u,0x0c0a36b8u,0x0c0a36bau,0x0c0a36bcu,0x0c0a36beu,0x0c0a36c0u,0x0c0a36c2u,0x0c0a36c4u,0x0c0a36c6u,0x0c0a36c8u,0x0c0a36cau,0x0c0a36ccu,0x0c0a36ceu,
0x0c0a36d0u,0x0c0a36d2u,0x0c0a36d4u,0x0c0a36d6u,0x0c0a36d8u,0x0c0a36dau,0x0c0a36dcu,0x0c0a36deu,0x0c0a36e0u,0x0c0a36e2u,0x0c0a36e4u,0x0c0a36e6u,0x0c0a36e8u,0x0c0a36eau,0x0c0a36ecu,0x0c0a36eeu,
0x0c0a36f0u,0x0c0a36f2u,0x0c0a36f4u,0x0c0a36f6u,0x0c0a36f8u,0x0c0a36fau,0x0c0a36fcu,0x0c0a36feu,0x0c0a3700u,0x0c0a3702u,0x0c0a3704u,0x0c0a3706u,0x0c0a3708u,0x0c0a370au,0x0c0a370cu,0x0c0a370eu,
0x0c0a3710u,0x0c0a3712u,0x0c0a3714u,0x0c0a374au,0x0c0a374cu,0x0c0a374eu,0x0c0a3750u,0x0c0a3752u,0x0c0a3754u,0x0c0a3756u,0x0c0a3758u,0x0c0a375au,0x0c0a375cu,0x0c0a375eu,0x0c0a3760u,0x0c0a3762u,
0x0c0a3764u,0x0c0a3766u,0x0c0a3768u,0x0c0a376au,0x0c0a376cu,0x0c0a376eu,0x0c0a3770u,0x0c0a3772u,0x0c0a3774u,0x0c0a3776u,0x0c0a3778u,0x0c0a377au,0x0c0a377cu,0x0c0a377eu,0x0c0a3780u,0x0c0a3782u,
0x0c0a3784u,0x0c0a3786u,0x0c0a3788u,0x0c0a378au,0x0c0a378cu,0x0c0a378eu,0x0c0a3790u,0x0c0a3792u,0x0c0a3794u,0x0c0a3796u,0x0c0a3798u,0x0c0a379au,0x0c0a379cu,0x0c0a379eu,0x0c0a37a0u,0x0c0a37a2u,
0x0c0a37a4u,0x0c0a37a6u,0x0c0a37a8u,0x0c0a37aau,0x0c0a37acu,0x0c0a37aeu,0x0c0a37b0u,0x0c0a37b2u,0x0c0a37b4u,0x0c0a37b6u,0x0c0a37b8u,0x0c0a37bau,0x0c0a37bcu,0x0c0a37beu,0x0c0a37c0u,0x0c0a37c2u,
0x0c0a37c4u,0x0c0a37c6u,0x0c0a37c8u,0x0c0a37cau,0x0c0a37ccu,0x0c0a37ceu,0x0c0a37d0u,0x0c0a37d2u,0x0c0a37d4u,0x0c0a37d6u,0x0c0a37d8u,0x0c0a37dau,0x0c0a37dcu,0x0c0a37deu,0x0c0a37e0u,0x0c0a37e2u,
0x0c0a37e4u,0x0c0a37e6u,0x0c0a37e8u,0x0c0a37eau,0x0c0a37ecu,0x0c0a37eeu,0x0c0a37f0u,0x0c0a37f2u,0x0c0a37f4u,0x0c0a37f6u,0x0c0a37f8u,0x0c0a37fau,0x0c0a37fcu,0x0c0a37feu,0x0c0a3800u,0x0c0a3802u,
0x0c0a3804u,0x0c0a3806u,0x0c0a3808u,0x0c0a380au,0x0c0a380cu,0x0c0a380eu,0x0c0a3810u,0x0c0a3812u,0x0c0a3814u,0x0c0a3816u,0x0c0a3818u,0x0c0a381au,0x0c0a381cu,0x0c0a381eu,0x0c0a3820u,0x0c0a3822u,
0x0c0a3824u,0x0c0a3826u,0x0c0a3828u,0x0c0a382au,0x0c0a382cu,0x0c0a382eu,0x0c0a3830u,0x0c0a3832u,0x0c0a3834u,0x0c0a3836u,0x0c0a3838u,0x0c0a383au,0x0c0a383cu,0x0c0a383eu,0x0c0a3840u,0x0c0a3842u,
0x0c0a3844u,0x0c0a3846u,0x0c0a3848u,0x0c0a384au,0x0c0a384cu,0x0c0a384eu,0x0c0a3850u,0x0c0a3852u,0x0c0a3854u,0x0c0a3856u,0x0c0a3858u,0x0c0a396cu,0x0c0a396eu,0x0c0a3970u,0x0c0a3972u,0x0c0a3974u,
0x0c0a3976u,0x0c0a3978u,0x0c0a397au,0x0c0a397cu,0x0c0a397eu,0x0c0a3980u,0x0c0a3982u,0x0c0a3984u,0x0c0a3986u,0x0c0a3988u,0x0c0a398au,0x0c0a398cu,0x0c0a398eu,0x0c0a3990u,0x0c0a3992u,0x0c0a3994u,
0x0c0a3996u,0x0c0a3998u,0x0c0a399au,0x0c0a399cu,0x0c0a399eu,0x0c0a39a0u,0x0c0a39a2u,0x0c0a39a4u,0x0c0a39a6u,0x0c0a39a8u,0x0c0a39aau,0x0c0a39acu,0x0c0a39aeu,0x0c0a39b0u,0x0c0a39b2u,0x0c0a39b4u,
0x0c0a39b6u,0x0c0a39b8u,0x0c0a39bau,0x0c0a39bcu,0x0c0a39beu,0x0c0a39c0u,0x0c0a39c2u,0x0c0a39c4u,0x0c0a39c6u,0x0c0a39c8u,0x0c0a39cau,0x0c0a39ccu,0x0c0a39ceu,0x0c0a39d0u,0x0c0a39d2u,0x0c0a39d4u,
0x0c0a39d6u,0x0c0a39d8u,0x0c0a39dau,0x0c0a39dcu,0x0c0a39deu,0x0c0a39e0u,0x0c0a39e2u,0x0c0a39e4u,0x0c0a39e6u,0x0c0a39e8u,0x0c0a39eau,0x0c0a39ecu,0x0c0a39eeu,0x0c0a39f0u,0x0c0a39f2u,0x0c0a39f4u,
0x0c0a39f6u,0x0c0a39f8u,0x0c0a39fau,0x0c0a39fcu,0x0c0a39feu,0x0c0a3a00u,0x0c0a3a02u,0x0c0a3a04u,0x0c0a3a06u,0x0c0a3a08u,0x0c0a3a0au,0x0c0a3a0cu,0x0c0a3a0eu,0x0c0a3a10u,0x0c0a3a12u,0x0c0a3a14u,
0x0c0a3a16u,0x0c0a3a18u,0x0c0a3a1au,0x0c0a3a1cu,0x0c0a3a1eu,0x0c0a3a20u,0x0c0a3a22u,0x0c0a3a24u,0x0c0a3a26u,0x0c0a3a28u,0x0c0a3a2au,0x0c0a3a2cu,0x0c0a3a2eu,0x0c0a3a30u,0x0c0a3a32u,0x0c0a3a34u,
0x0c0a3a36u,0x0c0a3a38u,0x0c0a3a3au,0x0c0a3a3cu,0x0c0a3a3eu,0x0c0a3a40u,0x0c0a3a42u,0x0c0a3a44u,0x0c0a3a46u,0x0c0a3a48u,0x0c0a3a4au,0x0c0a3a4cu,0x0c0a3a4eu,0x0c0a3a50u,0x0c0a3a52u,0x0c0a3a54u,
0x0c0a3a56u,0x0c0a3a58u,0x0c0a3a5au,0x0c0a3a5cu,0x0c0a3a5eu,0x0c0a3a60u,0x0c0a3a62u,0x0c0a3a64u,0x0c0a3a66u,0x0c0a3a68u,0x0c0a3a6au,0x0c0a3a6cu,0x0c0a3a6eu,0x0c0a3a70u,0x0c0a3a72u,0x0c0a3a74u,
0x0c0a3a76u,0x0c0a3a78u,0x0c0a3a7au,0x0c0a3a7cu,0x0c0a3a7eu,0x0c0a3a80u,0x0c0a3adeu,0x0c0a3ae0u,0x0c0a3ae2u,0x0c0a3ae4u,0x0c0a3ae6u,0x0c0a3ae8u,0x0c0a3aeau,0x0c0a3aecu,0x0c0a3c98u,0x0c0a3c9au,
0x0c0a3c9cu,0x0c0a3c9eu,0x0c0a3ca0u,0x0c0a3ca2u,0x0c0a3ca4u,0x0c0a3ca6u,0x0c0a3ca8u,0x0c0a3caau,0x0c0a3cacu,0x0c0a3caeu,0x0c0a3cb0u,0x0c0a3cb2u,0x0c0a3cb4u,0x0c0a3cb6u,0x0c0a3cb8u,0x0c0a3cbau,
0x0c0a3cbcu,0x0c0a3cbeu,0x0c0a3cc0u,0x0c0a3cc2u,0x0c0a3cc4u,0x0c0a3cc6u,0x0c0a3cc8u,0x0c0a3ccau,0x0c0a3cccu,0x0c0a3cceu,0x0c0a3cd0u,0x0c0a3cd2u,0x0c0a3cd4u,0x0c0a3cd6u,0x0c0a3cd8u,0x0c0a3cdau,
0x0c0a3cdcu,0x0c0a3cdeu,0x0c0a3ce0u,0x0c0a3ce2u,0x0c0a3ce4u,0x0c0a3ce6u,0x0c0a3ce8u,0x0c0a3ceau,0x0c0a3cecu,0x0c0a3ceeu,0x0c0a3cf0u,0x0c0a3cf2u,0x0c0a3cf4u,0x0c0a3cf6u,0x0c0a3cf8u,0x0c0a3cfau,
0x0c0a3cfcu,0x0c0a3cfeu,0x0c0a3d00u,0x0c0a3d02u,0x0c0a3d04u,0x0c0a3d06u,0x0c0a3d08u,0x0c0a3d0au,0x0c0a3d0cu,0x0c0a3d0eu,0x0c0a3d10u,0x0c0a3d12u,0x0c0a3d14u,0x0c0a3d16u,0x0c0a3d18u,0x0c0a3d1au,
0x0c0a3d1cu,0x0c0a3d1eu,0x0c0a3d20u,0x0c0a3d22u,0x0c0a3d24u,0x0c0a3d26u,0x0c0a3d28u,0x0c0a3d2au,0x0c0a3d2cu,0x0c0a3d2eu,0x0c0a3d30u,0x0c0a3d32u,0x0c0a3d34u,0x0c0a3d36u,0x0c0a3d38u,0x0c0a3d3au,
0x0c0a3d3cu,0x0c0a3d3eu,0x0c0a3d40u,0x0c0a3d42u,0x0c0a3d44u,0x0c0a3d46u,0x0c0a3d48u,0x0c0a3d4au,0x0c0a3d4cu,0x0c0a3d4eu,0x0c0a3d50u,0x0c0a3d52u,0x0c0a3d54u,0x0c0a3d56u,0x0c0a3d58u,0x0c0a3d5au,
0x0c0a3d5cu,0x0c0a3d5eu,0x0c0a3d60u,0x0c0a3d62u,0x0c0a3d64u,0x0c0a3d66u,0x0c0a3d68u,0x0c0a3d6au,0x0c0a3d6cu,0x0c0a3d6eu,0x0c0a3d70u,0x0c0a3d72u,0x0c0a3d74u,0x0c0a3d76u,0x0c0a3d78u,0x0c0a3d7au,
0x0c0a3d7cu,0x0c0a3d7eu,0x0c0a3d80u,0x0c0a3d82u,0x0c0a3d84u,0x0c0a3d86u,0x0c0a3d88u,0x0c0a3d8au,0x0c0a3d8cu,0x0c0a3d8eu,0x0c0a3d90u,0x0c0a3d92u,0x0c0a3d94u,0x0c0a3d96u,0x0c0a3d98u,0x0c0a3d9au,
0x0c0a3d9cu,0x0c0a3d9eu,0x0c0a3da0u,0x0c0a3da2u,0x0c0a3da4u,0x0c0a3da6u,0x0c0a3da8u,0x0c0a3daau,0x0c0a3dacu,0x0c0a3e0au,0x0c0a3e0cu,0x0c0a3e0eu,0x0c0a3e10u,0x0c0a3e12u,0x0c0a3e14u,0x0c0a3e16u,
0x0c0a3e18u,0x0c0a4012u,0x0c0a4014u,0x0c0a4016u,0x0c0a4018u,0x0c0a401au,0x0c0a401cu,0x0c0a401eu,0x0c0a4020u,0x0c0a4022u,0x0c0a4024u,0x0c0a4026u,0x0c0a4028u,0x0c0a402au,0x0c0a402cu,0x0c0a402eu,
0x0c0a4030u,0x0c0a4032u,0x0c0a4034u,0x0c0a4036u,0x0c0a4038u,0x0c0a403au,0x0c0a403cu,0x0c0a403eu,0x0c0a4040u,0x0c0a4042u,0x0c0a4044u,0x0c0a4046u,0x0c0a4048u,0x0c0a404au,0x0c0a404cu,0x0c0a404eu,
0x0c0a4050u,0x0c0a4052u,0x0c0a4054u,0x0c0a4056u,0x0c0a4058u,0x0c0a405au,0x0c0a405cu,0x0c0a405eu,0x0c0a4060u,0x0c0a4062u,0x0c0a4064u,0x0c0a4066u,0x0c0a4068u,0x0c0a406au,0x0c0a406cu,0x0c0a406eu,
0x0c0a4070u,0x0c0a4072u,0x0c0a4074u,0x0c0a4076u,0x0c0a4078u,0x0c0a407au,0x0c0a407cu,0x0c0a407eu,0x0c0a4080u,0x0c0a4082u,0x0c0a4084u,0x0c0a4086u,0x0c0a4088u,0x0c0a408au,0x0c0a408cu,0x0c0a408eu,
0x0c0a4090u,0x0c0a4092u,0x0c0a4094u,0x0c0a4096u,0x0c0a4098u,0x0c0a409au,0x0c0a409cu,0x0c0a409eu,0x0c0a40a0u,0x0c0a40a2u,0x0c0a40a4u,0x0c0a40a6u,0x0c0a40a8u,0x0c0a40aau,0x0c0a4190u,0x0c0a4192u,
0x0c0a4194u,0x0c0a4196u,0x0c0a4198u,0x0c0a419au,0x0c0a419cu,0x0c0a419eu,0x0c0a41a0u,0x0c0a41a2u,0x0c0a41a4u,0x0c0a41a6u,0x0c0a41a8u,0x0c0a41aau,0x0c0a41acu,0x0c0a41aeu,0x0c0a41b0u,0x0c0a41b2u,
0x0c0a41b4u,0x0c0a41b6u,0x0c0a41b8u,0x0c0a41bau,0x0c0a41bcu,0x0c0a41beu,0x0c0a41c0u,0x0c0a41c2u,0x0c0a41c4u,0x0c0a41c6u,0x0c0a41c8u,0x0c0a41cau,0x0c0a41ccu,0x0c0a41ceu,0x0c0a41d0u,0x0c0a41d2u,
0x0c0a41d4u,0x0c0a41d6u,0x0c0a41d8u,0x0c0a41dau,0x0c0a41dcu,0x0c0a41deu,0x0c0a41e0u,0x0c0a41e2u,0x0c0a41e4u,0x0c0a41e6u,0x0c0a41e8u,0x0c0a41eau,0x0c0a41ecu,0x0c0a41eeu,0x0c0a41f0u,0x0c0a41f2u,
0x0c0a41f4u,0x0c0a41f6u,0x0c0a41f8u,0x0c0a41fau,0x0c0a41fcu,0x0c0a41feu,0x0c0a4200u,0x0c0a4202u,0x0c0a4204u,0x0c0a4206u,0x0c0a4208u,0x0c0a420au,0x0c0a420cu,0x0c0a420eu,0x0c0a4210u,0x0c0a4212u,
0x0c0a4214u,0x0c0a4216u,0x0c0a4218u,0x0c0a421au,0x0c0a421cu,0x0c0a421eu,0x0c0a4220u,0x0c0a4222u,0x0c0a4224u,0x0c0a4226u,0x0c0a4228u,0x0c0a422au,0x0c0a422cu,0x0c0a422eu,0x0c0a4230u,0x0c0a4232u,
0x0c0a4234u,0x0c0a4236u,0x0c0a4238u,0x0c0a432cu,0x0c0a432eu,0x0c0a4330u,0x0c0a4332u,0x0c0a4334u,0x0c0a4336u,0x0c0a4338u,0x0c0a433au,0x0c0a433cu,0x0c0a433eu,0x0c0a4340u,0x0c0a4342u,0x0c0a4344u,
0x0c0a4346u,0x0c0a4348u,0x0c0a434au,0x0c0a434cu,0x0c0a434eu,0x0c0a4350u,0x0c0a4352u,0x0c0a4354u,0x0c0a4356u,0x0c0a4358u,0x0c0a435au,0x0c0a435cu,0x0c0a435eu,0x0c0a4360u,0x0c0a4362u,0x0c0a4364u,
0x0c0a4366u,0x0c0a4368u,0x0c0a436au,0x0c0a436cu,0x0c0a436eu,0x0c0a4370u,0x0c0a4372u,0x0c0a4374u,0x0c0a4376u,0x0c0a4378u,0x0c0a437au,0x0c0a437cu,0x0c0a437eu,0x0c0a4380u,0x0c0a4382u,0x0c0a4384u,
0x0c0a4386u,0x0c0a4388u,0x0c0a438au,0x0c0a438cu,0x0c0a438eu,0x0c0a4390u,0x0c0a4392u,0x0c0a4394u,0x0c0a4396u,0x0c0a4398u,0x0c0a439au,0x0c0a439cu,0x0c0a439eu,0x0c0a43a0u,0x0c0a43a2u,0x0c0a43a4u,
0x0c0a43a6u,0x0c0a43a8u,0x0c0a43aau,0x0c0a43acu,0x0c0a43aeu,0x0c0a43b0u,0x0c0a43b2u,0x0c0a43b4u,0x0c0a43b6u,0x0c0a43b8u,0x0c0a43bau,0x0c0a43bcu,0x0c0a43beu,0x0c0a43c0u,0x0c0a43c2u,0x0c0a43c4u,
0x0c0a43c6u,0x0c0a43c8u,0x0c0a43cau,0x0c0a43ccu,0x0c0a43ceu,0x0c0a43d0u,0x0c0a43d2u,0x0c0a43d4u,0x0c0a43d6u,0x0c0a43d8u,0x0c0a43dau,0x0c0a43dcu,0x0c0a4508u,0x0c0a450au,0x0c0a450cu,0x0c0a450eu,
0x0c0a4510u,0x0c0a4512u,0x0c0a4514u,0x0c0a4516u,0x0c0a4518u,0x0c0a451au,0x0c0a451cu,0x0c0a451eu,0x0c0a4520u,0x0c0a4522u,0x0c0a4524u,0x0c0a4526u,0x0c0a4528u,0x0c0a452au,0x0c0a452cu,0x0c0a452eu,
0x0c0a4530u,0x0c0a4532u,0x0c0a4534u,0x0c0a4536u,0x0c0a4538u,0x0c0a453au,0x0c0a453cu,0x0c0a453eu,0x0c0a4540u,0x0c0a4542u,0x0c0a4544u,0x0c0a4546u,0x0c0a4548u,0x0c0a454au,0x0c0a454cu,0x0c0a454eu,
0x0c0a4550u,0x0c0a4552u,0x0c0a4554u,0x0c0a4556u,0x0c0a4558u,0x0c0a455au,0x0c0a455cu,0x0c0a455eu,0x0c0a4560u,0x0c0a4562u,0x0c0a4564u,0x0c0a4566u,0x0c0a4568u,0x0c0a456au,0x0c0a456cu,0x0c0a456eu,
0x0c0a4570u,0x0c0a4572u,0x0c0a4574u,0x0c0a4576u,0x0c0a4578u,0x0c0a457au,0x0c0a457cu,0x0c0a457eu,0x0c0a4580u,0x0c0a4582u,0x0c0a4584u,0x0c0a4586u,0x0c0a4588u,0x0c0a458au,0x0c0a458cu,0x0c0a458eu,
0x0c0a4590u,0x0c0a4592u,0x0c0a4594u,0x0c0a4596u,0x0c0a4598u,0x0c0a459au,0x0c0a459cu,0x0c0a459eu,0x0c0a45a0u,0x0c0a45a2u,0x0c0a45a4u,0x0c0a45a6u,0x0c0a45a8u,0x0c0a45aau,0x0c0a45acu,0x0c0a45aeu,
0x0c0a45b0u,0x0c0a45b2u,0x0c0a45b4u,0x0c0a45b6u,0x0c0a45b8u,0x0c0a45bau,0x0c0a45bcu,0x0c0a45beu,0x0c0a45c0u,0x0c0a45c2u,0x0c0a45c4u,0x0c0a45c6u,0x0c0a45c8u,0x0c0a45cau,0x0c0a45ccu,0x0c0a45ceu,
0x0c0a45d0u,0x0c0a45d2u,0x0c0a45d4u,0x0c0a45d6u,0x0c0a45d8u,0x0c0a45dau,0x0c0a45dcu,0x0c0a45deu,0x0c0a45e0u,0x0c0a45e2u,0x0c0a45e4u,0x0c0a45e6u,0x0c0a45e8u,0x0c0a45eau,0x0c0a45ecu,0x0c0a45eeu,
0x0c0a45f0u,0x0c0a45f2u,0x0c0a45f4u,0x0c0a45f6u,0x0c0a45f8u,0x0c0a45fau,0x0c0a45fcu,0x0c0a45feu,0x0c0a4600u,0x0c0a4602u,0x0c0a4604u,0x0c0a4606u,0x0c0a4608u,0x0c0a460au,0x0c0a460cu,0x0c0a460eu,
0x0c0a4610u,0x0c0a4612u,0x0c0a4614u,0x0c0a4616u,0x0c0a4618u,0x0c0a47d4u,0x0c0a47d6u,0x0c0a47d8u,0x0c0a47dau,0x0c0a47dcu,0x0c0a47deu,0x0c0a47e0u,0x0c0a47e2u,0x0c0a47e4u,0x0c0a47e6u,0x0c0a47e8u,
0x0c0a47eau,0x0c0a47ecu,0x0c0a47eeu,0x0c0a47f0u,0x0c0a47f2u,0x0c0a47f4u,0x0c0a47f6u,0x0c0a47f8u,0x0c0a47fau,0x0c0a47fcu,0x0c0a47feu,0x0c0a4800u,0x0c0a4802u,0x0c0a4804u,0x0c0a4806u,0x0c0a4808u,
0x0c0a480au,0x0c0a480cu,0x0c0a480eu,0x0c0a4810u,0x0c0a4812u,0x0c0a4814u,0x0c0a4816u,0x0c0a4818u,0x0c0a481au,0x0c0a481cu,0x0c0a481eu,0x0c0a4820u,0x0c0a4822u,0x0c0a4824u,0x0c0a4826u,0x0c0a4828u,
0x0c0a482au,0x0c0a482cu,0x0c0a482eu,0x0c0a4830u,0x0c0a4832u,0x0c0a4834u,0x0c0a4836u,0x0c0a4838u,0x0c0a483au,0x0c0a483cu,0x0c0a483eu,0x0c0a4840u,0x0c0a4842u,0x0c0a4844u,0x0c0a4846u,0x0c0a4848u,
0x0c0a484au,0x0c0a484cu,0x0c0a484eu,0x0c0a4850u,0x0c0a4852u,0x0c0a4854u,0x0c0a4856u,0x0c0a4858u,0x0c0a485au,0x0c0a485cu,0x0c0a485eu,0x0c0a4860u,0x0c0a4862u,0x0c0a4864u,0x0c0a4866u,0x0c0a4868u,
0x0c0a486au,0x0c0a486cu,0x0c0a4948u,0x0c0a494au,0x0c0a494cu,0x0c0a494eu,0x0c0a4950u,0x0c0a4952u,0x0c0a4954u,0x0c0a4956u,0x0c0a4958u,0x0c0a495au,0x0c0a495cu,0x0c0a495eu,0x0c0a4960u,0x0c0a4962u,
0x0c0a4964u,0x0c0a4966u,0x0c0a4968u,0x0c0a496au,0x0c0a496cu,0x0c0a496eu,0x0c0a4970u,0x0c0a4972u,0x0c0a4974u,0x0c0a4976u,0x0c0a4978u,0x0c0a497au,0x0c0a497cu,0x0c0a497eu,0x0c0a4980u,0x0c0a4982u,
0x0c0a4984u,0x0c0a4986u,0x0c0a4988u,0x0c0a498au,0x0c0a498cu,0x0c0a498eu,0x0c0a4990u,0x0c0a4992u,0x0c0a4994u,0x0c0a4996u,0x0c0a4998u,0x0c0a499au,0x0c0a499cu,0x0c0a499eu,0x0c0a49a0u,0x0c0a49a2u,
0x0c0a49a4u,0x0c0a49a6u,0x0c0a49a8u,0x0c0a49aau,0x0c0a49acu,0x0c0a49aeu,0x0c0a49b0u,0x0c0a49b2u,0x0c0a49b4u,0x0c0a49b6u,0x0c0a49b8u,0x0c0a49bau,0x0c0a49bcu,0x0c0a49beu,0x0c0a49c0u,0x0c0a49c2u,
0x0c0a49c4u,0x0c0a49c6u,0x0c0a49c8u,0x0c0a49cau,0x0c0a49ccu,0x0c0a49ceu,0x0c0a49d0u,0x0c0a49d2u,0x0c0a49d4u,0x0c0a49d6u,0x0c0a49d8u,0x0c0a49dau,0x0c0a49dcu,0x0c0a49deu,0x0c0a49e0u,0x0c0a4abcu,
0x0c0a4abeu,0x0c0a4ac0u,0x0c0a4ac2u,0x0c0a4ac4u,0x0c0a4ac6u,0x0c0a4ac8u,0x0c0a4acau,0x0c0a4accu,0x0c0a4aceu,0x0c0a4ad0u,0x0c0a4ad2u,0x0c0a4ad4u,0x0c0a4ad6u,0x0c0a4ad8u,0x0c0a4adau,0x0c0a4adcu,
0x0c0a4adeu,0x0c0a4ae0u,0x0c0a4ae2u,0x0c0a4ae4u,0x0c0a4ae6u,0x0c0a4ae8u,0x0c0a4aeau,0x0c0a4aecu,0x0c0a4aeeu,0x0c0a4af0u,0x0c0a4af2u,0x0c0a4af4u,0x0c0a4af6u,0x0c0a4af8u,0x0c0a4afau,0x0c0a4afcu,
0x0c0a4afeu,0x0c0a4b00u,0x0c0a4b02u,0x0c0a4b04u,0x0c0a4b06u,0x0c0a4b08u,0x0c0a4b0au,0x0c0a4b0cu,0x0c0a4b0eu,0x0c0a4b10u,0x0c0a4b12u,0x0c0a4b14u,0x0c0a4b16u,0x0c0a4b18u,0x0c0a4b1au,0x0c0a4b1cu,
0x0c0a4b1eu,0x0c0a4b20u,0x0c0a4b22u,0x0c0a4b24u,0x0c0a4b26u,0x0c0a4b28u,0x0c0a4b2au,0x0c0a4b2cu,0x0c0a4b2eu,0x0c0a4b30u,0x0c0a4b32u,0x0c0a4b34u,0x0c0a4b36u,0x0c0a4b38u,0x0c0a4b3au,0x0c0a4b3cu,
0x0c0a4b3eu,0x0c0a4b40u,0x0c0a4b42u,0x0c0a4b44u,0x0c0a4b46u,0x0c0a4b48u,0x0c0a4b4au,0x0c0a4b4cu,0x0c0a4b4eu,0x0c0a4b50u,0x0c0a4b52u,0x0c0a4b54u,0x0c0a4b56u,0x0c0a4b58u,0x0c0a4b5au,0x0c0a4b5cu,
0x0c0a4c44u,0x0c0a4c46u,0x0c0a4c48u,0x0c0a4c4au,0x0c0a4c4cu,0x0c0a4c4eu,0x0c0a4c50u,0x0c0a4c52u,0x0c0a4c54u,0x0c0a4c56u,0x0c0a4c58u,0x0c0a4c5au,0x0c0a4c5cu,0x0c0a4c5eu,0x0c0a4c60u,0x0c0a4c62u,
0x0c0a4c64u,0x0c0a4c66u,0x0c0a4c68u,0x0c0a4c6au,0x0c0a4c6cu,0x0c0a4c6eu,0x0c0a4c70u,0x0c0a4c72u,0x0c0a4c74u,0x0c0a4c76u,0x0c0a4c78u,0x0c0a4c7au,0x0c0a4c7cu,0x0c0a4c7eu,0x0c0a4c80u,0x0c0a4c82u,
0x0c0a4c84u,0x0c0a4c86u,0x0c0a4c88u,0x0c0a4c8au,0x0c0a4c8cu,0x0c0a4c8eu,0x0c0a4c90u,0x0c0a4c92u,0x0c0a4c94u,0x0c0a4c96u,0x0c0a4c98u,0x0c0a4c9au,0x0c0a4c9cu,0x0c0a4c9eu,0x0c0a4ca0u,0x0c0a4ca2u,
0x0c0a4ca4u,0x0c0a4ca6u,0x0c0a4ca8u,0x0c0a4caau,0x0c0a4cacu,0x0c0a4caeu,0x0c0a4cb0u,0x0c0a4cb2u,0x0c0a4cb4u,0x0c0a4cb6u,0x0c0a4cb8u,0x0c0a4cbau,0x0c0a4cbcu,0x0c0a4cbeu,0x0c0a4cc0u,0x0c0a4cc2u,
0x0c0a4cc4u,0x0c0a4cc6u,0x0c0a4cc8u,0x0c0a4ccau,0x0c0a4cccu,0x0c0a4cceu,0x0c0a4cd0u,0x0c0a4cd2u,0x0c0a4cd4u,0x0c0a4cd6u,0x0c0a4cd8u,0x0c0a4cdau,0x0c0a4cdcu,0x0c0a4cdeu,0x0c0a4ce0u,0x0c0a4ce2u,
0x0c0a4ce4u,0x0c0a4ce6u,0x0c0a4ce8u,0x0c0a4ceau,0x0c0a4cecu,0x0c0a4ceeu,0x0c0a4cf0u,0x0c0a4cf2u,0x0c0a4cf4u,0x0c0a4cf6u,0x0c0a4cf8u,0x0c0a4cfau,0x0c0a4cfcu,0x0c0a4cfeu,0x0c0a4d00u,0x0c0a4d02u,
0x0c0a4d04u,0x0c0a4e18u,0x0c0a4e1au,0x0c0a4e1cu,0x0c0a4e1eu,0x0c0a4e20u,0x0c0a4e22u,0x0c0a4e24u,0x0c0a4e26u,0x0c0a4e28u,0x0c0a4e2au,0x0c0a4e2cu,0x0c0a4e2eu,0x0c0a4e30u,0x0c0a4e32u,0x0c0a4e34u,
0x0c0a4e36u,0x0c0a4e38u,0x0c0a4e3au,0x0c0a4e3cu,0x0c0a4e3eu,0x0c0a4e40u,0x0c0a4e42u,0x0c0a4e44u,0x0c0a4e46u,0x0c0a4e48u,0x0c0a4e4au,0x0c0a4e4cu,0x0c0a4e4eu,0x0c0a4e50u,0x0c0a4e52u,0x0c0a4e54u,
0x0c0a4e56u,0x0c0a4e58u,0x0c0a4e5au,0x0c0a4e5cu,0x0c0a4e5eu,0x0c0a4e60u,0x0c0a4e62u,0x0c0a4e64u,0x0c0a4e66u,0x0c0a4e68u,0x0c0a4e6au,0x0c0a4e6cu,0x0c0a4e6eu,0x0c0a4e70u,0x0c0a4e72u,0x0c0a4e74u,
0x0c0a4e76u,0x0c0a4e78u,0x0c0a4e7au,0x0c0a4e7cu,0x0c0a4e7eu,0x0c0a4e80u,0x0c0a4e82u,0x0c0a4e84u,0x0c0a4e86u,0x0c0a4e88u,0x0c0a4e8au,0x0c0a4e8cu,0x0c0a4e8eu,0x0c0a4e90u,0x0c0a4e92u,0x0c0a4e94u,
0x0c0a4e96u,0x0c0a4e98u,0x0c0a4e9au,0x0c0a4e9cu,0x0c0a4e9eu,0x0c0a4ea0u,0x0c0a4f90u,0x0c0a4f92u,0x0c0a4f94u,0x0c0a4f96u,0x0c0a4f98u,0x0c0a4f9au,0x0c0a4f9cu,0x0c0a4f9eu,0x0c0a4fa0u,0x0c0a4fa2u,
0x0c0a4fa4u,0x0c0a4fa6u,0x0c0a4fa8u,0x0c0a4faau,0x0c0a4facu,0x0c0a4faeu,0x0c0a4fb0u,0x0c0a4fb2u,0x0c0a4fb4u,0x0c0a4fb6u,0x0c0a4fb8u,0x0c0a4fbau,0x0c0a4fbcu,0x0c0a4fbeu,0x0c0a4fc0u,0x0c0a4fc2u,
0x0c0a4fc4u,0x0c0a4fc6u,0x0c0a4fc8u,0x0c0a4fcau,0x0c0a4fccu,0x0c0a4fceu,0x0c0a4fd0u,0x0c0a4fd2u,0x0c0a4fd4u,0x0c0a4fd6u,0x0c0a4fd8u,0x0c0a4fdau,0x0c0a4fdcu,0x0c0a4fdeu,0x0c0a4fe0u,0x0c0a4fe2u,
0x0c0a4fe4u,0x0c0a4fe6u,0x0c0a4fe8u,0x0c0a4feau,0x0c0a4fecu,0x0c0a4feeu,0x0c0a4ff0u,0x0c0a4ff2u,0x0c0a4ff4u,0x0c0a4ff6u,0x0c0a4ff8u,0x0c0a4ffau,0x0c0a4ffcu,0x0c0a4ffeu,0x0c0a5000u,0x0c0a5002u,
0x0c0a5004u,0x0c0a5006u,0x0c0a5008u,0x0c0a500au,0x0c0a500cu,0x0c0a500eu,0x0c0a5010u,0x0c0a5012u,0x0c0a5014u,0x0c0a5016u,0x0c0a5018u,0x0c0a5124u,0x0c0a5126u,0x0c0a5128u,0x0c0a512au,0x0c0a512cu,
0x0c0a512eu,0x0c0a5130u,0x0c0a5132u,0x0c0a5134u,0x0c0a5136u,0x0c0a5138u,0x0c0a513au,0x0c0a513cu,0x0c0a513eu,0x0c0a5140u,0x0c0a5142u,0x0c0a5144u,0x0c0a5146u,0x0c0a5148u,0x0c0a514au,0x0c0a514cu,
0x0c0a514eu,0x0c0a5150u,0x0c0a5152u,0x0c0a5154u,0x0c0a5156u,0x0c0a5158u,0x0c0a515au,0x0c0a515cu,0x0c0a515eu,0x0c0a5160u,0x0c0a5162u,0x0c0a5164u,0x0c0a5166u,0x0c0a5168u,0x0c0a516au,0x0c0a516cu,
0x0c0a516eu,0x0c0a5170u,0x0c0a5172u,0x0c0a5174u,0x0c0a5176u,0x0c0a5178u,0x0c0a517au,0x0c0a517cu,0x0c0a517eu,0x0c0a5180u,0x0c0a5182u,0x0c0a5184u,0x0c0a5186u,0x0c0a5188u,0x0c0a518au,0x0c0a518cu,
0x0c0a518eu,0x0c0a5190u,0x0c0a5192u,0x0c0a5194u,0x0c0a5196u,0x0c0a5198u,0x0c0a519au,0x0c0a519cu,0x0c0a519eu,0x0c0a51a0u,0x0c0a51a2u,0x0c0a51a4u,0x0c0a51a6u,0x0c0a51a8u,0x0c0a51aau,0x0c0a51acu,
0x0c0a51aeu,0x0c0a51b0u,0x0c0a51b2u,0x0c0a51b4u,0x0c0a51b6u,0x0c0a51b8u,0x0c0a51bau,0x0c0a51bcu,0x0c0a51beu,0x0c0a51c0u,0x0c0a51c2u,0x0c0a51c4u,0x0c0a51c6u,0x0c0a51c8u,0x0c0a51cau,0x0c0a51ccu,
0x0c0a51ceu,0x0c0a51d0u,0x0c0a51d2u,0x0c0a51d4u,0x0c0a51d6u,0x0c0a51d8u,0x0c0a51dau,0x0c0a51dcu,0x0c0a51deu,0x0c0a51e0u,0x0c0a51e2u,0x0c0a51e4u,0x0c0a51e6u,0x0c0a51e8u,0x0c0a51eau,0x0c0a51ecu,
0x0c0a51eeu,0x0c0a51f0u,0x0c0a51f2u,0x0c0a51f4u,0x0c0a51f6u,0x0c0a51f8u,0x0c0a51fau,0x0c0a51fcu,0x0c0a51feu,0x0c0a5200u,0x0c0a5202u,0x0c0a5204u,0x0c0a5206u,0x0c0a5208u,0x0c0a520au,0x0c0a520cu,
0x0c0a520eu,0x0c0a5210u,0x0c0a5212u,0x0c0a5214u,0x0c0a5216u,0x0c0a5218u,0x0c0a521au,0x0c0a521cu,0x0c0a521eu,0x0c0a5220u,0x0c0a5222u,0x0c0a5224u,0x0c0a5226u,0x0c0a5228u,0x0c0a522au,0x0c0a522cu,
0x0c0a522eu,0x0c0a5230u,0x0c0a5232u,0x0c0a5234u,0x0c0a5236u,0x0c0a5238u,0x0c0a523au,0x0c0a523cu,0x0c0a523eu,0x0c0a5240u,0x0c0a5242u,0x0c0a5244u,0x0c0a5246u,0x0c0a5248u,0x0c0a524au,0x0c0a524cu,
0x0c0a524eu,0x0c0a5250u,0x0c0a5252u,0x0c0a5254u,0x0c0a5256u,0x0c0a5258u,0x0c0a525au,0x0c0a525cu,0x0c0a525eu,0x0c0a5260u,0x0c0a5262u,0x0c0a5264u,0x0c0a5266u,0x0c0a5268u,0x0c0a526au,0x0c0a526cu,
0x0c0a526eu,0x0c0a5270u,0x0c0a5272u,0x0c0a5274u,0x0c0a5276u,0x0c0a5278u,0x0c0a527au,0x0c0a527cu,0x0c0a527eu,0x0c0a5280u,0x0c0a5282u,0x0c0a5284u,0x0c0a5286u,0x0c0a5288u,0x0c0a528au,0x0c0a528cu,
0x0c0a5a3cu,0x0c0a5a3eu,0x0c0a5a40u,0x0c0a5a42u,0x0c0a5a44u,0x0c0a5a46u,0x0c0a5a48u,0x0c0a5a4au,0x0c0a5a4cu,0x0c0a5a4eu,0x0c0a5a50u,0x0c0a5a52u,0x0c0a5a54u,0x0c0a5a56u,0x0c0a5a58u,0x0c0a5a5au,
0x0c0a5a5cu,0x0c0a5a5eu,0x0c0a5a60u,0x0c0a5a62u,0x0c0a5a64u,0x0c0a5a66u,0x0c0a5a68u,0x0c0a5a6au,0x0c0a5a6cu,0x0c0a5a6eu,0x0c0a5a70u,0x0c0a5a72u,0x0c0a5a74u,0x0c0a5a76u,0x0c0a5a78u,0x0c0a5a7au,
0x0c0a5a7cu,0x0c0a5a7eu,0x0c0a5a80u,0x0c0a5a82u,0x0c0a5a84u,0x0c0a5a86u,0x0c0a5a88u,0x0c0a5a8au,0x0c0a5a8cu,0x0c0a5a8eu,0x0c0a5a90u,0x0c0a5a92u,0x0c0a5a94u,0x0c0a5a96u,0x0c0a5a98u,0x0c0a5a9au,
0x0c0a5a9cu,0x0c0a5a9eu,0x0c0a5aa0u,0x0c0a5aa2u,0x0c0a5aa4u,0x0c0a5aa6u,0x0c0a5aa8u,0x0c0a5aaau,0x0c0a5aacu,0x0c0a5aaeu,0x0c0a5ab0u,0x0c0a5ab2u,0x0c0a5ab4u,0x0c0a5ab6u,0x0c0a5ab8u,0x0c0a5abau,
0x0c0a5abcu,0x0c0a5abeu,0x0c0a5ac0u,0x0c0a5ac2u,0x0c0a5ac4u,0x0c0a5ac6u,0x0c0a5ac8u,0x0c0a5acau,0x0c0a5accu,0x0c0a5aceu,0x0c0a5ad0u,0x0c0a5ad2u,0x0c0a5ad4u,0x0c0a5ad6u,0x0c0a5ad8u,0x0c0a5adau,
0x0c0a5adcu,0x0c0a5adeu,0x0c0a5ae0u,0x0c0a5ae2u,0x0c0a5ae4u,0x0c0a5ae6u,0x0c0a5ae8u,0x0c0a5aeau,0x0c0a5aecu,0x0c0a5aeeu,0x0c0a5af0u,0x0c0a5af2u,0x0c0a5af4u,0x0c0a5af6u,0x0c0a5af8u,0x0c0a5afau,
0x0c0a5afcu,0x0c0a5afeu,0x0c0a5b00u,0x0c0a5b02u,0x0c0a5b04u,0x0c0a5b06u,0x0c0a5b08u,0x0c0a5b0au,0x0c0a5b0cu,0x0c0a5b0eu,0x0c0a5b10u,0x0c0a5b12u,0x0c0a5b14u,0x0c0a5c8cu,0x0c0a5c8eu,0x0c0a5c90u,
0x0c0a5c92u,0x0c0a5c94u,0x0c0a5c96u,0x0c0a5c98u,0x0c0a5c9au,0x0c0a5c9cu,0x0c0a5c9eu,0x0c0a5ca0u,0x0c0a5ca2u,0x0c0a5ca4u,0x0c0a5ca6u,0x0c0a5ca8u,0x0c0a5caau,0x0c0a5cacu,0x0c0a5caeu,0x0c0a5cb0u,
0x0c0a5cb2u,0x0c0a5cb4u,0x0c0a5cb6u,0x0c0a5cb8u,0x0c0a5cbau,0x0c0a5cbcu,0x0c0a5cbeu,0x0c0a5cc0u,0x0c0a5cc2u,0x0c0a5cc4u,0x0c0a5cc6u,0x0c0a5cc8u,0x0c0a5ccau,0x0c0a5cccu,0x0c0a5cceu,0x0c0a5cd0u,
0x0c0a5cd2u,0x0c0a5cd4u,0x0c0a5cd6u,0x0c0a5cd8u,0x0c0a5cdau,0x0c0a5cdcu,0x0c0a5cdeu,0x0c0a5ce0u,0x0c0a5ce2u,0x0c0a5ce4u,0x0c0a5ce6u,0x0c0a5ce8u,0x0c0a5ceau,0x0c0a5cecu,0x0c0a5ceeu,0x0c0a5cf0u,
0x0c0a5cf2u,0x0c0a5cf4u,0x0c0a5cf6u,0x0c0a5cf8u,0x0c0a5cfau,0x0c0a5cfcu,0x0c0a5cfeu,0x0c0a5d00u,0x0c0a5d02u,0x0c0a5d04u,0x0c0a5d06u,0x0c0a5d08u,0x0c0a5d0au,0x0c0a5d0cu,0x0c0a5d0eu,0x0c0a5d10u,
0x0c0a5d12u,0x0c0a5d14u,0x0c0a5d16u,0x0c0a5d18u,0x0c0a5d1au,0x0c0a5d1cu,0x0c0a5d1eu,0x0c0a5d20u,0x0c0a5d22u,0x0c0a5d24u,0x0c0a5d26u,0x0c0a5d28u,0x0c0a5d2au,0x0c0a5d2cu,0x0c0a5d2eu,0x0c0a5d30u,
0x0c0a5d32u,0x0c0a5d34u,0x0c0a5d36u,0x0c0a5d38u,0x0c0a5d3au,0x0c0a5d3cu,0x0c0a5d3eu,0x0c0a5d40u,0x0c0a5d42u,0x0c0a5d44u,0x0c0a5d46u,0x0c0a5d48u,0x0c0a5d4au,0x0c0a5d4cu,0x0c0a5d4eu,0x0c0a5d50u,
0x0c0a5d52u,0x0c0a5d54u,0x0c0a5d56u,0x0c0a5d58u,0x0c0a5d5au,0x0c0a5d5cu,0x0c0a5ec8u,0x0c0a5ecau,0x0c0a5eccu,0x0c0a5eceu,0x0c0a5ed0u,0x0c0a5ed2u,0x0c0a5ed4u,0x0c0a5ed6u,0x0c0a5ed8u,0x0c0a5edau,
0x0c0a5edcu,0x0c0a5edeu,0x0c0a5ee0u,0x0c0a5ee2u,0x0c0a5ee4u,0x0c0a5ee6u,0x0c0a5ee8u,0x0c0a5eeau,0x0c0a5eecu,0x0c0a5eeeu,0x0c0a5ef0u,0x0c0a5ef2u,0x0c0a5ef4u,0x0c0a5ef6u,0x0c0a5ef8u,0x0c0a5efau,
0x0c0a5efcu,0x0c0a5efeu,0x0c0a5f00u,0x0c0a5f02u,0x0c0a5f04u,0x0c0a5f06u,0x0c0a5f08u,0x0c0a5f0au,0x0c0a5f0cu,0x0c0a5f0eu,0x0c0a5f10u,0x0c0a5f12u,0x0c0a5f14u,0x0c0a5f16u,0x0c0a5f18u,0x0c0a5f1au,
0x0c0a5f1cu,0x0c0a5f1eu,0x0c0a5f20u,0x0c0a5f22u,0x0c0a5f24u,0x0c0a5f26u,0x0c0a5f28u,0x0c0a5f2au,0x0c0a5f2cu,0x0c0a5f2eu,0x0c0a5f30u,0x0c0a5f32u,0x0c0a5f34u,0x0c0a5f36u,0x0c0a5f38u,0x0c0a5f3au,
0x0c0a5f3cu,0x0c0a5f3eu,0x0c0a5f40u,0x0c0a5f42u,0x0c0a5f44u,0x0c0a5f46u,0x0c0a5f48u,0x0c0a5f4au,0x0c0a5f4cu,0x0c0a5f4eu,0x0c0a5f50u,0x0c0a6010u,0x0c0a6012u,0x0c0a6014u,0x0c0a6016u,0x0c0a6018u,
0x0c0a601au,0x0c0a601cu,0x0c0a601eu,0x0c0a6020u,0x0c0a6022u,0x0c0a6024u,0x0c0a6026u,0x0c0a6028u,0x0c0a602au,0x0c0a602cu,0x0c0a602eu,0x0c0a6030u,0x0c0a6032u,0x0c0a6034u,0x0c0a6036u,0x0c0a6038u,
0x0c0a603au,0x0c0a603cu,0x0c0a603eu,0x0c0a6040u,0x0c0a6042u,0x0c0a6044u,0x0c0a6046u,0x0c0a6048u,0x0c0a604au,0x0c0a604cu,0x0c0a604eu,0x0c0a6050u,0x0c0a6052u,0x0c0a6054u,0x0c0a6056u,0x0c0a6058u,
0x0c0a605au,0x0c0a605cu,0x0c0a605eu,0x0c0a6060u,0x0c0a6062u,0x0c0a6064u,0x0c0a6066u,0x0c0a6068u,0x0c0a606au,0x0c0a606cu,0x0c0a606eu,0x0c0a6070u,0x0c0a6072u,0x0c0a6074u,0x0c0a6076u,0x0c0a6078u,
0x0c0a607au,0x0c0a607cu,0x0c0a607eu,0x0c0a6080u,0x0c0a6082u,0x0c0a6084u,0x0c0a6086u,0x0c0a6088u,0x0c0a608au,0x0c0a608cu,0x0c0a608eu,0x0c0a6090u,0x0c0a6092u,0x0c0a6094u,0x0c0a6096u,0x0c0a6098u,
0x0c0a6158u,0x0c0a615au,0x0c0a615cu,0x0c0a615eu,0x0c0a6160u,0x0c0a6162u,0x0c0a6164u,0x0c0a6166u,0x0c0a6168u,0x0c0a616au,0x0c0a616cu,0x0c0a616eu,0x0c0a6170u,0x0c0a6172u,0x0c0a6174u,0x0c0a6176u,
0x0c0a6178u,0x0c0a617au,0x0c0a617cu,0x0c0a617eu,0x0c0a6180u,0x0c0a6182u,0x0c0a6184u,0x0c0a6186u,0x0c0a6188u,0x0c0a618au,0x0c0a618cu,0x0c0a618eu,0x0c0a6190u,0x0c0a6192u,0x0c0a6194u,0x0c0a6196u,
0x0c0a6198u,0x0c0a619au,0x0c0a619cu,0x0c0a619eu,0x0c0a61a0u,0x0c0a61a2u,0x0c0a61a4u,0x0c0a61a6u,0x0c0a61a8u,0x0c0a61aau,0x0c0a61acu,0x0c0a61aeu,0x0c0a61b0u,0x0c0a61b2u,0x0c0a61b4u,0x0c0a61b6u,
0x0c0a61b8u,0x0c0a61bau,0x0c0a61bcu,0x0c0a61beu,0x0c0a61c0u,0x0c0a61c2u,0x0c0a61c4u,0x0c0a61c6u,0x0c0a61c8u,0x0c0a61cau,0x0c0a61ccu,0x0c0a61ceu,0x0c0a61d0u,0x0c0a61d2u,0x0c0a61d4u,0x0c0a61d6u,
0x0c0a61d8u,0x0c0a61dau,0x0c0a61dcu,0x0c0a61deu,0x0c0a61e0u,0x0c0a61e2u,0x0c0a61e4u,0x0c0a61e6u,0x0c0a61e8u,0x0c0a61eau,0x0c0a61ecu,0x0c0a61eeu,0x0c0a61f0u,0x0c0a61f2u,0x0c0a61f4u,0x0c0a61f6u,
0x0c0a61f8u,0x0c0a62e0u,0x0c0a62e2u,0x0c0a62e4u,0x0c0a62e6u,0x0c0a62e8u,0x0c0a62eau,0x0c0a62ecu,0x0c0a62eeu,0x0c0a62f0u,0x0c0a62f2u,0x0c0a62f4u,0x0c0a62f6u,0x0c0a62f8u,0x0c0a62fau,0x0c0a62fcu,
0x0c0a62feu,0x0c0a6300u,0x0c0a6302u,0x0c0a6304u,0x0c0a6306u,0x0c0a6308u,0x0c0a630au,0x0c0a630cu,0x0c0a630eu,0x0c0a6310u,0x0c0a6312u,0x0c0a6314u,0x0c0a6316u,0x0c0a6318u,0x0c0a631au,0x0c0a631cu,
0x0c0a631eu,0x0c0a6320u,0x0c0a6322u,0x0c0a6324u,0x0c0a6326u,0x0c0a6328u,0x0c0a632au,0x0c0a632cu,0x0c0a632eu,0x0c0a6330u,0x0c0a6332u,0x0c0a6334u,0x0c0a6336u,0x0c0a6338u,0x0c0a633au,0x0c0a633cu,
0x0c0a633eu,0x0c0a6340u,0x0c0a6342u,0x0c0a6344u,0x0c0a6346u,0x0c0a6348u,0x0c0a634au,0x0c0a634cu,0x0c0a634eu,0x0c0a6350u,0x0c0a6352u,0x0c0a6354u,0x0c0a6356u,0x0c0a6358u,0x0c0a635au,0x0c0a635cu,
0x0c0a635eu,0x0c0a6360u,0x0c0a6362u,0x0c0a6364u,0x0c0a6366u,0x0c0a6368u,0x0c0a636au,0x0c0a636cu,0x0c0a636eu,0x0c0a6370u,0x0c0a6372u,0x0c0a6374u,0x0c0a6376u,0x0c0a6378u,0x0c0a637au,0x0c0a637cu,
0x0c0a637eu,0x0c0a6380u,0x0c0a6382u,0x0c0a6384u,0x0c0a6386u,0x0c0a6388u,0x0c0beaf8u,0x0c0beafau,0x0c0beafcu,0x0c0beafeu,0x0c0beb00u,0x0c0beb02u,0x0c0beb04u,0x0c0beb06u,0x0c0beb08u,0x0c0beb0au,
0x0c0beb0cu,0x0c0beb0eu,0x0c0beb10u,0x0c0beb12u,0x0c0beb14u,0x0c0beb16u,0x0c0beb18u,0x0c0beb1au,0x0c0beb1cu,0x0c0beb1eu,0x0c0beb20u,0x0c0beb22u,0x0c0beb24u,0x0c0beb26u,0x0c0beb28u,0x0c0beb2au,
0x0c0beb2cu,0x0c0beb2eu,0x0c0beb30u,0x0c0beb32u,0x0c0beb34u,0x0c0beb36u,0x0c0beb38u,0x0c0beb3au,0x0c0beb3cu,0x0c0beb3eu,0x0c0beb40u,0x0c0beb42u,0x0c0beb44u,0x0c0beb46u,0x0c0beb48u,0x0c0beb4au,
0x0c0beb4cu,0x0c0beb4eu,0x0c0beb50u,0x0c0beb52u,0x0c0beb54u,0x0c0beb56u,0x0c0beb58u,0x0c0beb5au,0x0c0beb5cu,0x0c0beb5eu,0x0c0beb60u,0x0c0beb62u,0x0c0beb64u,0x0c0beb66u,0x0c0beb68u,0x0c0beb6au,
0x0c0beb6cu,0x0c0beb6eu,0x0c0beb70u,0x0c0beb72u,0x0c0beb74u,0x0c0beb76u,0x0c0beb78u,0x0c0beb7au,0x0c0beb7cu,0x0c0beb7eu,0x0c0beb80u,0x0c0beb82u,0x0c0beb84u,0x0c0beb86u,0x0c0beb88u,0x0c0beb8au,
0x0c0beb8cu,0x0c0beb8eu,0x0c0beb90u,0x0c0beb92u,0x0c0beb94u,0x0c0beb96u,0x0c0beb98u,0x0c0beb9au,0x0c0beb9cu,0x0c0beb9eu,0x0c0beba0u,0x0c0beba2u,0x0c0beba4u,0x0c0beba6u,0x0c0beba8u,0x0c0bebaau,
0x0c0bebacu,0x0c0bebaeu,0x0c0bebb0u,0x0c0bebb2u,0x0c0bebb4u,0x0c0bebb6u,0x0c0bebb8u,0x0c0bebbau,0x0c0bebbcu,0x0c0bebbeu,0x0c0bebc0u,0x0c0bebc2u,0x0c0bebc4u,0x0c0bebc6u,0x0c0bebc8u,0x0c0bebcau,
0x0c0bebccu,0x0c0bebceu,0x0c0bebd0u,0x0c0bebd2u,0x0c0bebd4u,0x0c0bebd6u,0x0c0bebd8u,0x0c0bebdau,0x0c0bebdcu,0x0c0bebdeu,0x0c0bebe0u,0x0c0bebe2u,0x0c0bebe4u,0x0c0c1192u,0x0c0c1194u,0x0c0c1196u,
0x0c0c1198u,0x0c0c119au,0x0c0c119cu,0x0c0c119eu,0x0c0c11a0u,0x0c0c11a2u,0x0c0c11a4u,0x0c0c11a6u,0x0c0c11a8u,0x0c0c11aau,0x0c0c11acu,0x0c0c11aeu,0x0c0c11b0u,0x0c0c11b2u,0x0c0c11b4u,0x0c0c11b6u,
0x0c0c11b8u,0x0c0c11bau,0x0c0c11bcu,0x0c0c11beu,0x0c0c11c0u,0x0c0c11c2u,0x0c0c11c4u,0x0c0c11c6u,0x0c0c11c8u,0x0c0c11cau,0x0c0c11ccu,0x0c0ca078u,0x0c0ca07au,0x0c0ca07cu,0x0c0ca07eu,0x0c0ca080u,
0x0c0ca082u,0x0c0ca084u,0x0c0ca086u,0x0c0ca088u,0x0c0ca08au,0x0c0ca08cu,0x0c0ca08eu,0x0c0ca090u,0x0c0ca092u,0x0c0ca094u,0x0c0ca096u,0x0c0ca098u,0x0c0ca09au,0x0c0ca09cu,0x0c0ca09eu,0x0c0ca0a0u,
0x0c0ca0a2u,0x0c0ca0a4u,0x0c0ca0a6u,0x0c0ca0a8u,0x0c0ca0aau,0x0c0ca0acu,0x0c0ca0aeu,0x0c0ca0b0u,0x0c0ca0b2u,0x0c0ca0b4u,0x0c0ca0b6u,0x0c0ca0b8u,0x0c0ca0bau,
};
int vf3_motion_final_adapter_contains(uint32_t pc) {
pc&=0x1fffffffu; unsigned lo=0,hi=sizeof(owned_pcs)/sizeof(owned_pcs[0]);
while(lo<hi) { unsigned mid=lo+(hi-lo)/2; if(owned_pcs[mid]<pc) lo=mid+1; else hi=mid; }
return lo<sizeof(owned_pcs)/sizeof(owned_pcs[0]) && owned_pcs[lo]==pc;
}
