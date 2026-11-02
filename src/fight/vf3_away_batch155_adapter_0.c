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
int vf3_away_batch155_adapter_0(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
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
case 0x0c0b98b8u: goto P_0c0b98b8;
case 0x0c0b98bau: goto P_0c0b98ba;
case 0x0c0b98bcu: goto P_0c0b98bc;
case 0x0c0b98beu: goto P_0c0b98be;
case 0x0c0b98c0u: goto P_0c0b98c0;
case 0x0c0b98c2u: goto P_0c0b98c2;
case 0x0c0b98c4u: goto P_0c0b98c4;
case 0x0c0b98c6u: goto P_0c0b98c6;
case 0x0c0b98c8u: goto P_0c0b98c8;
case 0x0c0b98cau: goto P_0c0b98ca;
case 0x0c0b98ccu: goto P_0c0b98cc;
case 0x0c0b98ceu: goto P_0c0b98ce;
case 0x0c0b98d0u: goto P_0c0b98d0;
case 0x0c0b98d2u: goto P_0c0b98d2;
case 0x0c0b98d4u: goto P_0c0b98d4;
case 0x0c0b98d6u: goto P_0c0b98d6;
case 0x0c0b98d8u: goto P_0c0b98d8;
case 0x0c0b98dau: goto P_0c0b98da;
case 0x0c0b98dcu: goto P_0c0b98dc;
case 0x0c0b98deu: goto P_0c0b98de;
case 0x0c0b98e0u: goto P_0c0b98e0;
case 0x0c0b98e2u: goto P_0c0b98e2;
case 0x0c0b98e4u: goto P_0c0b98e4;
case 0x0c0b98e6u: goto P_0c0b98e6;
case 0x0c0b98e8u: goto P_0c0b98e8;
case 0x0c0b98eau: goto P_0c0b98ea;
case 0x0c0b98ecu: goto P_0c0b98ec;
case 0x0c0b98eeu: goto P_0c0b98ee;
case 0x0c0b98f0u: goto P_0c0b98f0;
case 0x0c0b98f2u: goto P_0c0b98f2;
case 0x0c0b98f4u: goto P_0c0b98f4;
case 0x0c0b98f6u: goto P_0c0b98f6;
case 0x0c0b98f8u: goto P_0c0b98f8;
case 0x0c0b98fau: goto P_0c0b98fa;
case 0x0c0b98fcu: goto P_0c0b98fc;
case 0x0c0b98feu: goto P_0c0b98fe;
case 0x0c0b9900u: goto P_0c0b9900;
case 0x0c0b9902u: goto P_0c0b9902;
case 0x0c0b9904u: goto P_0c0b9904;
case 0x0c0b9906u: goto P_0c0b9906;
case 0x0c0b9908u: goto P_0c0b9908;
case 0x0c0b990au: goto P_0c0b990a;
case 0x0c0b990cu: goto P_0c0b990c;
case 0x0c0b990eu: goto P_0c0b990e;
case 0x0c0b9910u: goto P_0c0b9910;
case 0x0c0b9912u: goto P_0c0b9912;
case 0x0c0b9914u: goto P_0c0b9914;
case 0x0c0b9916u: goto P_0c0b9916;
case 0x0c0b9918u: goto P_0c0b9918;
case 0x0c0b991au: goto P_0c0b991a;
case 0x0c0b991cu: goto P_0c0b991c;
case 0x0c0b991eu: goto P_0c0b991e;
case 0x0c0b9920u: goto P_0c0b9920;
case 0x0c0b9922u: goto P_0c0b9922;
case 0x0c0b9924u: goto P_0c0b9924;
case 0x0c0b9926u: goto P_0c0b9926;
case 0x0c0b9928u: goto P_0c0b9928;
case 0x0c0b992au: goto P_0c0b992a;
case 0x0c0b992cu: goto P_0c0b992c;
case 0x0c0b992eu: goto P_0c0b992e;
case 0x0c0b9930u: goto P_0c0b9930;
case 0x0c0b9932u: goto P_0c0b9932;
case 0x0c0b9934u: goto P_0c0b9934;
case 0x0c0b9936u: goto P_0c0b9936;
case 0x0c0b9938u: goto P_0c0b9938;
case 0x0c0b993au: goto P_0c0b993a;
case 0x0c0b993cu: goto P_0c0b993c;
case 0x0c0b993eu: goto P_0c0b993e;
case 0x0c0b9940u: goto P_0c0b9940;
case 0x0c0b9942u: goto P_0c0b9942;
case 0x0c0b9944u: goto P_0c0b9944;
case 0x0c0b9946u: goto P_0c0b9946;
case 0x0c0b9948u: goto P_0c0b9948;
case 0x0c0b994au: goto P_0c0b994a;
case 0x0c0b994cu: goto P_0c0b994c;
case 0x0c0b994eu: goto P_0c0b994e;
case 0x0c0b9950u: goto P_0c0b9950;
case 0x0c0b9952u: goto P_0c0b9952;
case 0x0c0b9954u: goto P_0c0b9954;
case 0x0c0b9956u: goto P_0c0b9956;
case 0x0c0b9958u: goto P_0c0b9958;
case 0x0c0b995au: goto P_0c0b995a;
case 0x0c0b995cu: goto P_0c0b995c;
case 0x0c0b995eu: goto P_0c0b995e;
case 0x0c0b9960u: goto P_0c0b9960;
case 0x0c0b9962u: goto P_0c0b9962;
case 0x0c0b9964u: goto P_0c0b9964;
case 0x0c0b9966u: goto P_0c0b9966;
case 0x0c0b9968u: goto P_0c0b9968;
case 0x0c0b996au: goto P_0c0b996a;
case 0x0c0b996cu: goto P_0c0b996c;
case 0x0c0b996eu: goto P_0c0b996e;
case 0x0c0b9970u: goto P_0c0b9970;
case 0x0c0b9972u: goto P_0c0b9972;
case 0x0c0b9974u: goto P_0c0b9974;
case 0x0c0b9976u: goto P_0c0b9976;
case 0x0c0b9978u: goto P_0c0b9978;
case 0x0c0b997au: goto P_0c0b997a;
case 0x0c0b997cu: goto P_0c0b997c;
case 0x0c0b997eu: goto P_0c0b997e;
case 0x0c0b9980u: goto P_0c0b9980;
case 0x0c0b9982u: goto P_0c0b9982;
case 0x0c0b9984u: goto P_0c0b9984;
case 0x0c0b9986u: goto P_0c0b9986;
case 0x0c0b9988u: goto P_0c0b9988;
case 0x0c0b998au: goto P_0c0b998a;
case 0x0c0b998cu: goto P_0c0b998c;
case 0x0c0b998eu: goto P_0c0b998e;
case 0x0c0b9990u: goto P_0c0b9990;
case 0x0c0b9992u: goto P_0c0b9992;
case 0x0c0b9994u: goto P_0c0b9994;
case 0x0c0b9996u: goto P_0c0b9996;
case 0x0c0b9998u: goto P_0c0b9998;
case 0x0c0b999au: goto P_0c0b999a;
case 0x0c0b999cu: goto P_0c0b999c;
case 0x0c0b999eu: goto P_0c0b999e;
case 0x0c0b99a0u: goto P_0c0b99a0;
case 0x0c0b99a2u: goto P_0c0b99a2;
case 0x0c0b99a4u: goto P_0c0b99a4;
case 0x0c0b99a6u: goto P_0c0b99a6;
case 0x0c0b99a8u: goto P_0c0b99a8;
case 0x0c0b99aau: goto P_0c0b99aa;
case 0x0c0b99acu: goto P_0c0b99ac;
case 0x0c0b99aeu: goto P_0c0b99ae;
case 0x0c0b99b0u: goto P_0c0b99b0;
case 0x0c0b99b2u: goto P_0c0b99b2;
case 0x0c0b99b4u: goto P_0c0b99b4;
case 0x0c0b99b6u: goto P_0c0b99b6;
case 0x0c0b99b8u: goto P_0c0b99b8;
case 0x0c0b99bau: goto P_0c0b99ba;
case 0x0c0b99bcu: goto P_0c0b99bc;
case 0x0c0b99beu: goto P_0c0b99be;
case 0x0c0b99c0u: goto P_0c0b99c0;
case 0x0c0b99c2u: goto P_0c0b99c2;
case 0x0c0b99c4u: goto P_0c0b99c4;
case 0x0c0b99c6u: goto P_0c0b99c6;
case 0x0c0b99c8u: goto P_0c0b99c8;
case 0x0c0b99cau: goto P_0c0b99ca;
case 0x0c0b99ccu: goto P_0c0b99cc;
case 0x0c0b99ceu: goto P_0c0b99ce;
case 0x0c0b99d0u: goto P_0c0b99d0;
case 0x0c0b99d2u: goto P_0c0b99d2;
case 0x0c0b99d4u: goto P_0c0b99d4;
case 0x0c0b99d6u: goto P_0c0b99d6;
case 0x0c0b99d8u: goto P_0c0b99d8;
case 0x0c0b99dau: goto P_0c0b99da;
case 0x0c0b99dcu: goto P_0c0b99dc;
case 0x0c0b99deu: goto P_0c0b99de;
case 0x0c0b99e0u: goto P_0c0b99e0;
case 0x0c0b99e2u: goto P_0c0b99e2;
case 0x0c0b99e4u: goto P_0c0b99e4;
case 0x0c0b99e6u: goto P_0c0b99e6;
case 0x0c0b99e8u: goto P_0c0b99e8;
case 0x0c0b99eau: goto P_0c0b99ea;
case 0x0c0b99ecu: goto P_0c0b99ec;
case 0x0c0b99eeu: goto P_0c0b99ee;
case 0x0c0b99f0u: goto P_0c0b99f0;
case 0x0c0b99f2u: goto P_0c0b99f2;
case 0x0c0b99f4u: goto P_0c0b99f4;
case 0x0c0b99f6u: goto P_0c0b99f6;
case 0x0c0b99f8u: goto P_0c0b99f8;
case 0x0c0b99fau: goto P_0c0b99fa;
case 0x0c0b99fcu: goto P_0c0b99fc;
case 0x0c0b99feu: goto P_0c0b99fe;
case 0x0c0b9a00u: goto P_0c0b9a00;
case 0x0c0b9a02u: goto P_0c0b9a02;
case 0x0c0b9a04u: goto P_0c0b9a04;
case 0x0c0b9a06u: goto P_0c0b9a06;
case 0x0c0b9a08u: goto P_0c0b9a08;
case 0x0c0b9a0au: goto P_0c0b9a0a;
case 0x0c0b9a0cu: goto P_0c0b9a0c;
case 0x0c0b9a0eu: goto P_0c0b9a0e;
case 0x0c0b9a10u: goto P_0c0b9a10;
case 0x0c0b9a12u: goto P_0c0b9a12;
case 0x0c0b9a14u: goto P_0c0b9a14;
case 0x0c0b9a16u: goto P_0c0b9a16;
case 0x0c0b9a18u: goto P_0c0b9a18;
case 0x0c0b9a1au: goto P_0c0b9a1a;
case 0x0c0b9a8cu: goto P_0c0b9a8c;
case 0x0c0b9a8eu: goto P_0c0b9a8e;
case 0x0c0b9a90u: goto P_0c0b9a90;
case 0x0c0b9a92u: goto P_0c0b9a92;
case 0x0c0b9a94u: goto P_0c0b9a94;
case 0x0c0b9a96u: goto P_0c0b9a96;
case 0x0c0b9a98u: goto P_0c0b9a98;
case 0x0c0b9a9au: goto P_0c0b9a9a;
case 0x0c0b9a9cu: goto P_0c0b9a9c;
case 0x0c0b9a9eu: goto P_0c0b9a9e;
case 0x0c0b9aa0u: goto P_0c0b9aa0;
case 0x0c0b9aa2u: goto P_0c0b9aa2;
case 0x0c0b9aa4u: goto P_0c0b9aa4;
case 0x0c0b9aa6u: goto P_0c0b9aa6;
case 0x0c0b9aa8u: goto P_0c0b9aa8;
case 0x0c0b9aaau: goto P_0c0b9aaa;
case 0x0c0b9aacu: goto P_0c0b9aac;
case 0x0c0b9aaeu: goto P_0c0b9aae;
case 0x0c0b9ab0u: goto P_0c0b9ab0;
case 0x0c0b9ab2u: goto P_0c0b9ab2;
case 0x0c0b9ab4u: goto P_0c0b9ab4;
case 0x0c0b9ab6u: goto P_0c0b9ab6;
case 0x0c0b9ab8u: goto P_0c0b9ab8;
case 0x0c0b9abau: goto P_0c0b9aba;
case 0x0c0b9abcu: goto P_0c0b9abc;
case 0x0c0b9abeu: goto P_0c0b9abe;
case 0x0c0b9ac0u: goto P_0c0b9ac0;
case 0x0c0b9ac2u: goto P_0c0b9ac2;
case 0x0c0b9ac4u: goto P_0c0b9ac4;
case 0x0c0b9ac6u: goto P_0c0b9ac6;
case 0x0c0b9ac8u: goto P_0c0b9ac8;
case 0x0c0b9acau: goto P_0c0b9aca;
case 0x0c0b9accu: goto P_0c0b9acc;
case 0x0c0b9aceu: goto P_0c0b9ace;
case 0x0c0b9ad0u: goto P_0c0b9ad0;
case 0x0c0b9ad2u: goto P_0c0b9ad2;
case 0x0c0b9ad4u: goto P_0c0b9ad4;
case 0x0c0b9ad6u: goto P_0c0b9ad6;
case 0x0c0b9ad8u: goto P_0c0b9ad8;
case 0x0c0b9adau: goto P_0c0b9ada;
case 0x0c0b9adcu: goto P_0c0b9adc;
case 0x0c0b9adeu: goto P_0c0b9ade;
case 0x0c0b9ae0u: goto P_0c0b9ae0;
case 0x0c0b9ae2u: goto P_0c0b9ae2;
case 0x0c0b9ae4u: goto P_0c0b9ae4;
case 0x0c0b9ae6u: goto P_0c0b9ae6;
case 0x0c0b9ae8u: goto P_0c0b9ae8;
case 0x0c0b9aeau: goto P_0c0b9aea;
case 0x0c0b9aecu: goto P_0c0b9aec;
case 0x0c0b9aeeu: goto P_0c0b9aee;
case 0x0c0b9af0u: goto P_0c0b9af0;
case 0x0c0b9af2u: goto P_0c0b9af2;
case 0x0c0b9af4u: goto P_0c0b9af4;
case 0x0c0b9af6u: goto P_0c0b9af6;
case 0x0c0b9af8u: goto P_0c0b9af8;
case 0x0c0b9afau: goto P_0c0b9afa;
case 0x0c0b9afcu: goto P_0c0b9afc;
case 0x0c0b9afeu: goto P_0c0b9afe;
case 0x0c0b9b00u: goto P_0c0b9b00;
case 0x0c0b9b02u: goto P_0c0b9b02;
case 0x0c0b9b04u: goto P_0c0b9b04;
case 0x0c0b9b06u: goto P_0c0b9b06;
case 0x0c0b9b08u: goto P_0c0b9b08;
case 0x0c0b9b0au: goto P_0c0b9b0a;
case 0x0c0b9b0cu: goto P_0c0b9b0c;
case 0x0c0b9b0eu: goto P_0c0b9b0e;
case 0x0c0b9b10u: goto P_0c0b9b10;
case 0x0c0b9b12u: goto P_0c0b9b12;
case 0x0c0b9b14u: goto P_0c0b9b14;
case 0x0c0b9b16u: goto P_0c0b9b16;
case 0x0c0b9b18u: goto P_0c0b9b18;
case 0x0c0b9b1au: goto P_0c0b9b1a;
case 0x0c0b9b1cu: goto P_0c0b9b1c;
case 0x0c0b9b1eu: goto P_0c0b9b1e;
case 0x0c0b9b20u: goto P_0c0b9b20;
case 0x0c0b9b22u: goto P_0c0b9b22;
case 0x0c0b9b24u: goto P_0c0b9b24;
case 0x0c0b9b26u: goto P_0c0b9b26;
case 0x0c0b9b28u: goto P_0c0b9b28;
case 0x0c0b9b2au: goto P_0c0b9b2a;
case 0x0c0b9b2cu: goto P_0c0b9b2c;
case 0x0c0b9b2eu: goto P_0c0b9b2e;
case 0x0c0b9b30u: goto P_0c0b9b30;
case 0x0c0b9b32u: goto P_0c0b9b32;
case 0x0c0b9b34u: goto P_0c0b9b34;
case 0x0c0b9b36u: goto P_0c0b9b36;
case 0x0c0b9b38u: goto P_0c0b9b38;
case 0x0c0b9b3au: goto P_0c0b9b3a;
case 0x0c0b9b3cu: goto P_0c0b9b3c;
case 0x0c0b9b3eu: goto P_0c0b9b3e;
case 0x0c0b9b40u: goto P_0c0b9b40;
case 0x0c0b9b42u: goto P_0c0b9b42;
case 0x0c0b9b44u: goto P_0c0b9b44;
case 0x0c0b9b46u: goto P_0c0b9b46;
case 0x0c0b9b48u: goto P_0c0b9b48;
case 0x0c0b9b4au: goto P_0c0b9b4a;
case 0x0c0b9b4cu: goto P_0c0b9b4c;
case 0x0c0b9b4eu: goto P_0c0b9b4e;
case 0x0c0b9b50u: goto P_0c0b9b50;
case 0x0c0b9b52u: goto P_0c0b9b52;
case 0x0c0b9b54u: goto P_0c0b9b54;
case 0x0c0b9b56u: goto P_0c0b9b56;
case 0x0c0b9b58u: goto P_0c0b9b58;
case 0x0c0b9b5au: goto P_0c0b9b5a;
case 0x0c0b9b5cu: goto P_0c0b9b5c;
case 0x0c0b9b5eu: goto P_0c0b9b5e;
case 0x0c0b9b60u: goto P_0c0b9b60;
case 0x0c0b9b62u: goto P_0c0b9b62;
case 0x0c0b9b64u: goto P_0c0b9b64;
case 0x0c0b9b66u: goto P_0c0b9b66;
case 0x0c0b9b68u: goto P_0c0b9b68;
case 0x0c0b9b6au: goto P_0c0b9b6a;
case 0x0c0b9b6cu: goto P_0c0b9b6c;
case 0x0c0b9b6eu: goto P_0c0b9b6e;
case 0x0c0b9b70u: goto P_0c0b9b70;
case 0x0c0b9b72u: goto P_0c0b9b72;
case 0x0c0b9b74u: goto P_0c0b9b74;
case 0x0c0b9b76u: goto P_0c0b9b76;
case 0x0c0b9b78u: goto P_0c0b9b78;
case 0x0c0b9b7au: goto P_0c0b9b7a;
case 0x0c0b9b7cu: goto P_0c0b9b7c;
case 0x0c0b9b7eu: goto P_0c0b9b7e;
case 0x0c0b9b80u: goto P_0c0b9b80;
case 0x0c0b9b82u: goto P_0c0b9b82;
case 0x0c0b9b84u: goto P_0c0b9b84;
case 0x0c0b9b86u: goto P_0c0b9b86;
case 0x0c0b9b88u: goto P_0c0b9b88;
case 0x0c0b9b8au: goto P_0c0b9b8a;
case 0x0c0b9b8cu: goto P_0c0b9b8c;
case 0x0c0b9b8eu: goto P_0c0b9b8e;
case 0x0c0b9b90u: goto P_0c0b9b90;
case 0x0c0b9b92u: goto P_0c0b9b92;
case 0x0c0b9b94u: goto P_0c0b9b94;
case 0x0c0b9b96u: goto P_0c0b9b96;
case 0x0c0b9b98u: goto P_0c0b9b98;
case 0x0c0b9b9au: goto P_0c0b9b9a;
case 0x0c0b9b9cu: goto P_0c0b9b9c;
case 0x0c0b9b9eu: goto P_0c0b9b9e;
case 0x0c0b9ba0u: goto P_0c0b9ba0;
case 0x0c0b9ba2u: goto P_0c0b9ba2;
case 0x0c0b9ba4u: goto P_0c0b9ba4;
case 0x0c0b9ba6u: goto P_0c0b9ba6;
case 0x0c0b9ba8u: goto P_0c0b9ba8;
case 0x0c0b9baau: goto P_0c0b9baa;
case 0x0c0b9bacu: goto P_0c0b9bac;
case 0x0c0b9baeu: goto P_0c0b9bae;
case 0x0c0b9bb0u: goto P_0c0b9bb0;
case 0x0c0b9bb2u: goto P_0c0b9bb2;
case 0x0c0b9bb4u: goto P_0c0b9bb4;
case 0x0c0b9bb6u: goto P_0c0b9bb6;
case 0x0c0b9bb8u: goto P_0c0b9bb8;
case 0x0c0b9bbau: goto P_0c0b9bba;
case 0x0c0b9bbcu: goto P_0c0b9bbc;
case 0x0c0b9bbeu: goto P_0c0b9bbe;
case 0x0c0b9bc0u: goto P_0c0b9bc0;
case 0x0c0b9bc2u: goto P_0c0b9bc2;
case 0x0c0b9bc4u: goto P_0c0b9bc4;
case 0x0c0b9bc6u: goto P_0c0b9bc6;
case 0x0c0b9bc8u: goto P_0c0b9bc8;
case 0x0c0b9bcau: goto P_0c0b9bca;
case 0x0c0b9bccu: goto P_0c0b9bcc;
case 0x0c0b9bceu: goto P_0c0b9bce;
case 0x0c0b9bd0u: goto P_0c0b9bd0;
case 0x0c0b9bd2u: goto P_0c0b9bd2;
case 0x0c0b9bd4u: goto P_0c0b9bd4;
case 0x0c0b9bd6u: goto P_0c0b9bd6;
case 0x0c0b9bd8u: goto P_0c0b9bd8;
case 0x0c0b9bdau: goto P_0c0b9bda;
case 0x0c0b9bdcu: goto P_0c0b9bdc;
case 0x0c0b9bdeu: goto P_0c0b9bde;
case 0x0c0b9be0u: goto P_0c0b9be0;
case 0x0c0b9be2u: goto P_0c0b9be2;
case 0x0c0b9be4u: goto P_0c0b9be4;
case 0x0c0b9c5eu: goto P_0c0b9c5e;
case 0x0c0b9c60u: goto P_0c0b9c60;
case 0x0c0b9c62u: goto P_0c0b9c62;
case 0x0c0b9c64u: goto P_0c0b9c64;
case 0x0c0b9c66u: goto P_0c0b9c66;
case 0x0c0b9c68u: goto P_0c0b9c68;
case 0x0c0b9c6au: goto P_0c0b9c6a;
case 0x0c0b9c6cu: goto P_0c0b9c6c;
case 0x0c0b9c6eu: goto P_0c0b9c6e;
case 0x0c0b9c70u: goto P_0c0b9c70;
case 0x0c0b9c72u: goto P_0c0b9c72;
case 0x0c0b9c74u: goto P_0c0b9c74;
case 0x0c0b9c76u: goto P_0c0b9c76;
case 0x0c0b9c78u: goto P_0c0b9c78;
case 0x0c0b9c7au: goto P_0c0b9c7a;
case 0x0c0b9c7cu: goto P_0c0b9c7c;
case 0x0c0b9c7eu: goto P_0c0b9c7e;
case 0x0c0b9c80u: goto P_0c0b9c80;
case 0x0c0b9c82u: goto P_0c0b9c82;
case 0x0c0b9c84u: goto P_0c0b9c84;
case 0x0c0b9c86u: goto P_0c0b9c86;
case 0x0c0b9c88u: goto P_0c0b9c88;
case 0x0c0b9c8au: goto P_0c0b9c8a;
case 0x0c0b9c8cu: goto P_0c0b9c8c;
case 0x0c0b9c8eu: goto P_0c0b9c8e;
case 0x0c0b9c90u: goto P_0c0b9c90;
case 0x0c0b9c92u: goto P_0c0b9c92;
case 0x0c0b9c94u: goto P_0c0b9c94;
case 0x0c0b9c96u: goto P_0c0b9c96;
case 0x0c0b9c98u: goto P_0c0b9c98;
case 0x0c0b9c9au: goto P_0c0b9c9a;
case 0x0c0b9c9cu: goto P_0c0b9c9c;
case 0x0c0b9c9eu: goto P_0c0b9c9e;
case 0x0c0b9ca0u: goto P_0c0b9ca0;
case 0x0c0b9ca2u: goto P_0c0b9ca2;
case 0x0c0b9ca4u: goto P_0c0b9ca4;
case 0x0c0b9ca6u: goto P_0c0b9ca6;
case 0x0c0b9ca8u: goto P_0c0b9ca8;
case 0x0c0b9caau: goto P_0c0b9caa;
case 0x0c0b9cacu: goto P_0c0b9cac;
case 0x0c0b9caeu: goto P_0c0b9cae;
case 0x0c0b9cb0u: goto P_0c0b9cb0;
case 0x0c0b9cb2u: goto P_0c0b9cb2;
case 0x0c0b9cb4u: goto P_0c0b9cb4;
default: return vf3_matrix_family(target,s,ram);
}
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
if(!vf3_matrix_family(0x0c0a2e2cu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0a2e2cu; return 0; } return 1;
P_0c0b98b8: /* original 2fe6, guest PC 0x0c0b98b8 */
if(!s->budget--) { s->failed_pc=0x0c0b98b8u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0b98ba;
P_0c0b98ba: /* original 2fd6, guest PC 0x0c0b98ba */
if(!s->budget--) { s->failed_pc=0x0c0b98bau; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0b98bc;
P_0c0b98bc: /* original 2fc6, guest PC 0x0c0b98bc */
if(!s->budget--) { s->failed_pc=0x0c0b98bcu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0b98be;
P_0c0b98be: /* original 2fb6, guest PC 0x0c0b98be */
if(!s->budget--) { s->failed_pc=0x0c0b98beu; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0b98c0;
P_0c0b98c0: /* original 2fa6, guest PC 0x0c0b98c0 */
if(!s->budget--) { s->failed_pc=0x0c0b98c0u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0b98c2;
P_0c0b98c2: /* original 2f96, guest PC 0x0c0b98c2 */
if(!s->budget--) { s->failed_pc=0x0c0b98c2u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0b98c4;
P_0c0b98c4: /* original 4f22, guest PC 0x0c0b98c4 */
if(!s->budget--) { s->failed_pc=0x0c0b98c4u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0b98c6;
P_0c0b98c6: /* original 5d44, guest PC 0x0c0b98c6 */
if(!s->budget--) { s->failed_pc=0x0c0b98c6u; return 0; }
r[13]=read(ram,r[4]+16,4);
goto P_0c0b98c8;
P_0c0b98c8: /* original 94a8, guest PC 0x0c0b98c8 */
if(!s->budget--) { s->failed_pc=0x0c0b98c8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b9a1cu,2);
goto P_0c0b98ca;
P_0c0b98ca: /* original de6f, guest PC 0x0c0b98ca */
if(!s->budget--) { s->failed_pc=0x0c0b98cau; return 0; }
r[14]=read(ram,0x0c0b9a88u,4);
goto P_0c0b98cc;
P_0c0b98cc: /* original 7ff8, guest PC 0x0c0b98cc */
if(!s->budget--) { s->failed_pc=0x0c0b98ccu; return 0; }
r[15]+=0xfffffff8u;
goto P_0c0b98ce;
P_0c0b98ce: /* original 4e0b, guest PC 0x0c0b98ce */
if(!s->budget--) { s->failed_pc=0x0c0b98ceu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b98d2u;
tmp=read(ram,r[13],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b98d2u) { target=s->pc; goto dispatch; }
goto P_0c0b98d2;
P_0c0b98d0: /* original 65d2, guest PC 0x0c0b98d0 */
if(!s->budget--) { s->failed_pc=0x0c0b98d0u; return 0; }
tmp=read(ram,r[13],4);
r[5]=tmp;
goto P_0c0b98d2;
P_0c0b98d2: /* original 94a4, guest PC 0x0c0b98d2 */
if(!s->budget--) { s->failed_pc=0x0c0b98d2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b9a1eu,2);
goto P_0c0b98d4;
P_0c0b98d4: /* original 4e0b, guest PC 0x0c0b98d4 */
if(!s->budget--) { s->failed_pc=0x0c0b98d4u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b98d8u;
r[5]=read(ram,r[13]+4,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b98d8u) { target=s->pc; goto dispatch; }
goto P_0c0b98d8;
P_0c0b98d6: /* original 55d1, guest PC 0x0c0b98d6 */
if(!s->budget--) { s->failed_pc=0x0c0b98d6u; return 0; }
r[5]=read(ram,r[13]+4,4);
goto P_0c0b98d8;
P_0c0b98d8: /* original 94a2, guest PC 0x0c0b98d8 */
if(!s->budget--) { s->failed_pc=0x0c0b98d8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b9a20u,2);
goto P_0c0b98da;
P_0c0b98da: /* original 4e0b, guest PC 0x0c0b98da */
if(!s->budget--) { s->failed_pc=0x0c0b98dau; return 0; }
target=r[14];
r[16]=code_base|0x0c0b98deu;
r[5]=read(ram,r[13]+8,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b98deu) { target=s->pc; goto dispatch; }
goto P_0c0b98de;
P_0c0b98dc: /* original 55d2, guest PC 0x0c0b98dc */
if(!s->budget--) { s->failed_pc=0x0c0b98dcu; return 0; }
r[5]=read(ram,r[13]+8,4);
goto P_0c0b98de;
P_0c0b98de: /* original 94a0, guest PC 0x0c0b98de */
if(!s->budget--) { s->failed_pc=0x0c0b98deu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b9a22u,2);
goto P_0c0b98e0;
P_0c0b98e0: /* original 4e0b, guest PC 0x0c0b98e0 */
if(!s->budget--) { s->failed_pc=0x0c0b98e0u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b98e4u;
r[5]=read(ram,r[13]+12,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b98e4u) { target=s->pc; goto dispatch; }
goto P_0c0b98e4;
P_0c0b98e2: /* original 55d3, guest PC 0x0c0b98e2 */
if(!s->budget--) { s->failed_pc=0x0c0b98e2u; return 0; }
r[5]=read(ram,r[13]+12,4);
goto P_0c0b98e4;
P_0c0b98e4: /* original 949e, guest PC 0x0c0b98e4 */
if(!s->budget--) { s->failed_pc=0x0c0b98e4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b9a24u,2);
goto P_0c0b98e6;
P_0c0b98e6: /* original 4e0b, guest PC 0x0c0b98e6 */
if(!s->budget--) { s->failed_pc=0x0c0b98e6u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b98eau;
r[5]=read(ram,r[13]+16,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b98eau) { target=s->pc; goto dispatch; }
goto P_0c0b98ea;
P_0c0b98e8: /* original 55d4, guest PC 0x0c0b98e8 */
if(!s->budget--) { s->failed_pc=0x0c0b98e8u; return 0; }
r[5]=read(ram,r[13]+16,4);
goto P_0c0b98ea;
P_0c0b98ea: /* original 949c, guest PC 0x0c0b98ea */
if(!s->budget--) { s->failed_pc=0x0c0b98eau; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b9a26u,2);
goto P_0c0b98ec;
P_0c0b98ec: /* original 4e0b, guest PC 0x0c0b98ec */
if(!s->budget--) { s->failed_pc=0x0c0b98ecu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b98f0u;
r[5]=read(ram,r[13]+20,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b98f0u) { target=s->pc; goto dispatch; }
goto P_0c0b98f0;
P_0c0b98ee: /* original 55d5, guest PC 0x0c0b98ee */
if(!s->budget--) { s->failed_pc=0x0c0b98eeu; return 0; }
r[5]=read(ram,r[13]+20,4);
goto P_0c0b98f0;
P_0c0b98f0: /* original 949a, guest PC 0x0c0b98f0 */
if(!s->budget--) { s->failed_pc=0x0c0b98f0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b9a28u,2);
goto P_0c0b98f2;
P_0c0b98f2: /* original 4e0b, guest PC 0x0c0b98f2 */
if(!s->budget--) { s->failed_pc=0x0c0b98f2u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b98f6u;
r[5]=read(ram,r[13]+24,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b98f6u) { target=s->pc; goto dispatch; }
goto P_0c0b98f6;
P_0c0b98f4: /* original 55d6, guest PC 0x0c0b98f4 */
if(!s->budget--) { s->failed_pc=0x0c0b98f4u; return 0; }
r[5]=read(ram,r[13]+24,4);
goto P_0c0b98f6;
P_0c0b98f6: /* original 9498, guest PC 0x0c0b98f6 */
if(!s->budget--) { s->failed_pc=0x0c0b98f6u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b9a2au,2);
goto P_0c0b98f8;
P_0c0b98f8: /* original 4e0b, guest PC 0x0c0b98f8 */
if(!s->budget--) { s->failed_pc=0x0c0b98f8u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b98fcu;
r[5]=read(ram,r[13]+28,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b98fcu) { target=s->pc; goto dispatch; }
goto P_0c0b98fc;
P_0c0b98fa: /* original 55d7, guest PC 0x0c0b98fa */
if(!s->budget--) { s->failed_pc=0x0c0b98fau; return 0; }
r[5]=read(ram,r[13]+28,4);
goto P_0c0b98fc;
P_0c0b98fc: /* original 9496, guest PC 0x0c0b98fc */
if(!s->budget--) { s->failed_pc=0x0c0b98fcu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b9a2cu,2);
goto P_0c0b98fe;
P_0c0b98fe: /* original 4e0b, guest PC 0x0c0b98fe */
if(!s->budget--) { s->failed_pc=0x0c0b98feu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b9902u;
r[5]=read(ram,r[13]+32,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b9902u) { target=s->pc; goto dispatch; }
goto P_0c0b9902;
P_0c0b9900: /* original 55d8, guest PC 0x0c0b9900 */
if(!s->budget--) { s->failed_pc=0x0c0b9900u; return 0; }
r[5]=read(ram,r[13]+32,4);
goto P_0c0b9902;
P_0c0b9902: /* original 9494, guest PC 0x0c0b9902 */
if(!s->budget--) { s->failed_pc=0x0c0b9902u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b9a2eu,2);
goto P_0c0b9904;
P_0c0b9904: /* original 4e0b, guest PC 0x0c0b9904 */
if(!s->budget--) { s->failed_pc=0x0c0b9904u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b9908u;
r[5]=read(ram,r[13]+36,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b9908u) { target=s->pc; goto dispatch; }
goto P_0c0b9908;
P_0c0b9906: /* original 55d9, guest PC 0x0c0b9906 */
if(!s->budget--) { s->failed_pc=0x0c0b9906u; return 0; }
r[5]=read(ram,r[13]+36,4);
goto P_0c0b9908;
P_0c0b9908: /* original 9492, guest PC 0x0c0b9908 */
if(!s->budget--) { s->failed_pc=0x0c0b9908u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b9a30u,2);
goto P_0c0b990a;
P_0c0b990a: /* original 4e0b, guest PC 0x0c0b990a */
if(!s->budget--) { s->failed_pc=0x0c0b990au; return 0; }
target=r[14];
r[16]=code_base|0x0c0b990eu;
r[5]=read(ram,r[13]+40,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b990eu) { target=s->pc; goto dispatch; }
goto P_0c0b990e;
P_0c0b990c: /* original 55da, guest PC 0x0c0b990c */
if(!s->budget--) { s->failed_pc=0x0c0b990cu; return 0; }
r[5]=read(ram,r[13]+40,4);
goto P_0c0b990e;
P_0c0b990e: /* original 9490, guest PC 0x0c0b990e */
if(!s->budget--) { s->failed_pc=0x0c0b990eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b9a32u,2);
goto P_0c0b9910;
P_0c0b9910: /* original 4e0b, guest PC 0x0c0b9910 */
if(!s->budget--) { s->failed_pc=0x0c0b9910u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b9914u;
r[5]=read(ram,r[13]+44,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b9914u) { target=s->pc; goto dispatch; }
goto P_0c0b9914;
P_0c0b9912: /* original 55db, guest PC 0x0c0b9912 */
if(!s->budget--) { s->failed_pc=0x0c0b9912u; return 0; }
r[5]=read(ram,r[13]+44,4);
goto P_0c0b9914;
P_0c0b9914: /* original 948e, guest PC 0x0c0b9914 */
if(!s->budget--) { s->failed_pc=0x0c0b9914u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b9a34u,2);
goto P_0c0b9916;
P_0c0b9916: /* original 4e0b, guest PC 0x0c0b9916 */
if(!s->budget--) { s->failed_pc=0x0c0b9916u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b991au;
r[5]=read(ram,r[13]+48,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b991au) { target=s->pc; goto dispatch; }
goto P_0c0b991a;
P_0c0b9918: /* original 55dc, guest PC 0x0c0b9918 */
if(!s->budget--) { s->failed_pc=0x0c0b9918u; return 0; }
r[5]=read(ram,r[13]+48,4);
goto P_0c0b991a;
P_0c0b991a: /* original 948c, guest PC 0x0c0b991a */
if(!s->budget--) { s->failed_pc=0x0c0b991au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b9a36u,2);
goto P_0c0b991c;
P_0c0b991c: /* original 4e0b, guest PC 0x0c0b991c */
if(!s->budget--) { s->failed_pc=0x0c0b991cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b9920u;
r[5]=read(ram,r[13]+52,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b9920u) { target=s->pc; goto dispatch; }
goto P_0c0b9920;
P_0c0b991e: /* original 55dd, guest PC 0x0c0b991e */
if(!s->budget--) { s->failed_pc=0x0c0b991eu; return 0; }
r[5]=read(ram,r[13]+52,4);
goto P_0c0b9920;
P_0c0b9920: /* original 948a, guest PC 0x0c0b9920 */
if(!s->budget--) { s->failed_pc=0x0c0b9920u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b9a38u,2);
goto P_0c0b9922;
P_0c0b9922: /* original 4e0b, guest PC 0x0c0b9922 */
if(!s->budget--) { s->failed_pc=0x0c0b9922u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b9926u;
r[5]=read(ram,r[13]+56,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b9926u) { target=s->pc; goto dispatch; }
goto P_0c0b9926;
P_0c0b9924: /* original 55de, guest PC 0x0c0b9924 */
if(!s->budget--) { s->failed_pc=0x0c0b9924u; return 0; }
r[5]=read(ram,r[13]+56,4);
goto P_0c0b9926;
P_0c0b9926: /* original 9488, guest PC 0x0c0b9926 */
if(!s->budget--) { s->failed_pc=0x0c0b9926u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b9a3au,2);
goto P_0c0b9928;
P_0c0b9928: /* original 4e0b, guest PC 0x0c0b9928 */
if(!s->budget--) { s->failed_pc=0x0c0b9928u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b992cu;
r[5]=read(ram,r[13]+60,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b992cu) { target=s->pc; goto dispatch; }
goto P_0c0b992c;
P_0c0b992a: /* original 55df, guest PC 0x0c0b992a */
if(!s->budget--) { s->failed_pc=0x0c0b992au; return 0; }
r[5]=read(ram,r[13]+60,4);
goto P_0c0b992c;
P_0c0b992c: /* original 9486, guest PC 0x0c0b992c */
if(!s->budget--) { s->failed_pc=0x0c0b992cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b9a3cu,2);
goto P_0c0b992e;
P_0c0b992e: /* original e040, guest PC 0x0c0b992e */
if(!s->budget--) { s->failed_pc=0x0c0b992eu; return 0; }
r[0]=0x00000040u;
goto P_0c0b9930;
P_0c0b9930: /* original 4e0b, guest PC 0x0c0b9930 */
if(!s->budget--) { s->failed_pc=0x0c0b9930u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b9934u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b9934u) { target=s->pc; goto dispatch; }
goto P_0c0b9934;
P_0c0b9932: /* original 05de, guest PC 0x0c0b9932 */
if(!s->budget--) { s->failed_pc=0x0c0b9932u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b9934;
P_0c0b9934: /* original 9483, guest PC 0x0c0b9934 */
if(!s->budget--) { s->failed_pc=0x0c0b9934u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b9a3eu,2);
goto P_0c0b9936;
P_0c0b9936: /* original e044, guest PC 0x0c0b9936 */
if(!s->budget--) { s->failed_pc=0x0c0b9936u; return 0; }
r[0]=0x00000044u;
goto P_0c0b9938;
P_0c0b9938: /* original 4e0b, guest PC 0x0c0b9938 */
if(!s->budget--) { s->failed_pc=0x0c0b9938u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b993cu;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b993cu) { target=s->pc; goto dispatch; }
goto P_0c0b993c;
P_0c0b993a: /* original 05de, guest PC 0x0c0b993a */
if(!s->budget--) { s->failed_pc=0x0c0b993au; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b993c;
P_0c0b993c: /* original 9480, guest PC 0x0c0b993c */
if(!s->budget--) { s->failed_pc=0x0c0b993cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b9a40u,2);
goto P_0c0b993e;
P_0c0b993e: /* original e048, guest PC 0x0c0b993e */
if(!s->budget--) { s->failed_pc=0x0c0b993eu; return 0; }
r[0]=0x00000048u;
goto P_0c0b9940;
P_0c0b9940: /* original 4e0b, guest PC 0x0c0b9940 */
if(!s->budget--) { s->failed_pc=0x0c0b9940u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b9944u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b9944u) { target=s->pc; goto dispatch; }
goto P_0c0b9944;
P_0c0b9942: /* original 05de, guest PC 0x0c0b9942 */
if(!s->budget--) { s->failed_pc=0x0c0b9942u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b9944;
P_0c0b9944: /* original 947d, guest PC 0x0c0b9944 */
if(!s->budget--) { s->failed_pc=0x0c0b9944u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b9a42u,2);
goto P_0c0b9946;
P_0c0b9946: /* original e04c, guest PC 0x0c0b9946 */
if(!s->budget--) { s->failed_pc=0x0c0b9946u; return 0; }
r[0]=0x0000004cu;
goto P_0c0b9948;
P_0c0b9948: /* original 4e0b, guest PC 0x0c0b9948 */
if(!s->budget--) { s->failed_pc=0x0c0b9948u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b994cu;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b994cu) { target=s->pc; goto dispatch; }
goto P_0c0b994c;
P_0c0b994a: /* original 05de, guest PC 0x0c0b994a */
if(!s->budget--) { s->failed_pc=0x0c0b994au; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b994c;
P_0c0b994c: /* original 947a, guest PC 0x0c0b994c */
if(!s->budget--) { s->failed_pc=0x0c0b994cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b9a44u,2);
goto P_0c0b994e;
P_0c0b994e: /* original e050, guest PC 0x0c0b994e */
if(!s->budget--) { s->failed_pc=0x0c0b994eu; return 0; }
r[0]=0x00000050u;
goto P_0c0b9950;
P_0c0b9950: /* original 4e0b, guest PC 0x0c0b9950 */
if(!s->budget--) { s->failed_pc=0x0c0b9950u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b9954u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b9954u) { target=s->pc; goto dispatch; }
goto P_0c0b9954;
P_0c0b9952: /* original 05de, guest PC 0x0c0b9952 */
if(!s->budget--) { s->failed_pc=0x0c0b9952u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b9954;
P_0c0b9954: /* original 9477, guest PC 0x0c0b9954 */
if(!s->budget--) { s->failed_pc=0x0c0b9954u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b9a46u,2);
goto P_0c0b9956;
P_0c0b9956: /* original e054, guest PC 0x0c0b9956 */
if(!s->budget--) { s->failed_pc=0x0c0b9956u; return 0; }
r[0]=0x00000054u;
goto P_0c0b9958;
P_0c0b9958: /* original 4e0b, guest PC 0x0c0b9958 */
if(!s->budget--) { s->failed_pc=0x0c0b9958u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b995cu;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b995cu) { target=s->pc; goto dispatch; }
goto P_0c0b995c;
P_0c0b995a: /* original 05de, guest PC 0x0c0b995a */
if(!s->budget--) { s->failed_pc=0x0c0b995au; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b995c;
P_0c0b995c: /* original 9474, guest PC 0x0c0b995c */
if(!s->budget--) { s->failed_pc=0x0c0b995cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b9a48u,2);
goto P_0c0b995e;
P_0c0b995e: /* original e058, guest PC 0x0c0b995e */
if(!s->budget--) { s->failed_pc=0x0c0b995eu; return 0; }
r[0]=0x00000058u;
goto P_0c0b9960;
P_0c0b9960: /* original 4e0b, guest PC 0x0c0b9960 */
if(!s->budget--) { s->failed_pc=0x0c0b9960u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b9964u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b9964u) { target=s->pc; goto dispatch; }
goto P_0c0b9964;
P_0c0b9962: /* original 05de, guest PC 0x0c0b9962 */
if(!s->budget--) { s->failed_pc=0x0c0b9962u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b9964;
P_0c0b9964: /* original 9471, guest PC 0x0c0b9964 */
if(!s->budget--) { s->failed_pc=0x0c0b9964u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b9a4au,2);
goto P_0c0b9966;
P_0c0b9966: /* original e05c, guest PC 0x0c0b9966 */
if(!s->budget--) { s->failed_pc=0x0c0b9966u; return 0; }
r[0]=0x0000005cu;
goto P_0c0b9968;
P_0c0b9968: /* original 4e0b, guest PC 0x0c0b9968 */
if(!s->budget--) { s->failed_pc=0x0c0b9968u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b996cu;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b996cu) { target=s->pc; goto dispatch; }
goto P_0c0b996c;
P_0c0b996a: /* original 05de, guest PC 0x0c0b996a */
if(!s->budget--) { s->failed_pc=0x0c0b996au; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b996c;
P_0c0b996c: /* original 946e, guest PC 0x0c0b996c */
if(!s->budget--) { s->failed_pc=0x0c0b996cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b9a4cu,2);
goto P_0c0b996e;
P_0c0b996e: /* original e060, guest PC 0x0c0b996e */
if(!s->budget--) { s->failed_pc=0x0c0b996eu; return 0; }
r[0]=0x00000060u;
goto P_0c0b9970;
P_0c0b9970: /* original 4e0b, guest PC 0x0c0b9970 */
if(!s->budget--) { s->failed_pc=0x0c0b9970u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b9974u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b9974u) { target=s->pc; goto dispatch; }
goto P_0c0b9974;
P_0c0b9972: /* original 05de, guest PC 0x0c0b9972 */
if(!s->budget--) { s->failed_pc=0x0c0b9972u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b9974;
P_0c0b9974: /* original 946b, guest PC 0x0c0b9974 */
if(!s->budget--) { s->failed_pc=0x0c0b9974u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b9a4eu,2);
goto P_0c0b9976;
P_0c0b9976: /* original e064, guest PC 0x0c0b9976 */
if(!s->budget--) { s->failed_pc=0x0c0b9976u; return 0; }
r[0]=0x00000064u;
goto P_0c0b9978;
P_0c0b9978: /* original 4e0b, guest PC 0x0c0b9978 */
if(!s->budget--) { s->failed_pc=0x0c0b9978u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b997cu;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b997cu) { target=s->pc; goto dispatch; }
goto P_0c0b997c;
P_0c0b997a: /* original 05de, guest PC 0x0c0b997a */
if(!s->budget--) { s->failed_pc=0x0c0b997au; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b997c;
P_0c0b997c: /* original 9468, guest PC 0x0c0b997c */
if(!s->budget--) { s->failed_pc=0x0c0b997cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b9a50u,2);
goto P_0c0b997e;
P_0c0b997e: /* original e068, guest PC 0x0c0b997e */
if(!s->budget--) { s->failed_pc=0x0c0b997eu; return 0; }
r[0]=0x00000068u;
goto P_0c0b9980;
P_0c0b9980: /* original 4e0b, guest PC 0x0c0b9980 */
if(!s->budget--) { s->failed_pc=0x0c0b9980u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b9984u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b9984u) { target=s->pc; goto dispatch; }
goto P_0c0b9984;
P_0c0b9982: /* original 05de, guest PC 0x0c0b9982 */
if(!s->budget--) { s->failed_pc=0x0c0b9982u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b9984;
P_0c0b9984: /* original 9465, guest PC 0x0c0b9984 */
if(!s->budget--) { s->failed_pc=0x0c0b9984u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b9a52u,2);
goto P_0c0b9986;
P_0c0b9986: /* original e06c, guest PC 0x0c0b9986 */
if(!s->budget--) { s->failed_pc=0x0c0b9986u; return 0; }
r[0]=0x0000006cu;
goto P_0c0b9988;
P_0c0b9988: /* original 4e0b, guest PC 0x0c0b9988 */
if(!s->budget--) { s->failed_pc=0x0c0b9988u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b998cu;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b998cu) { target=s->pc; goto dispatch; }
goto P_0c0b998c;
P_0c0b998a: /* original 05de, guest PC 0x0c0b998a */
if(!s->budget--) { s->failed_pc=0x0c0b998au; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b998c;
P_0c0b998c: /* original 9462, guest PC 0x0c0b998c */
if(!s->budget--) { s->failed_pc=0x0c0b998cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b9a54u,2);
goto P_0c0b998e;
P_0c0b998e: /* original e070, guest PC 0x0c0b998e */
if(!s->budget--) { s->failed_pc=0x0c0b998eu; return 0; }
r[0]=0x00000070u;
goto P_0c0b9990;
P_0c0b9990: /* original 4e0b, guest PC 0x0c0b9990 */
if(!s->budget--) { s->failed_pc=0x0c0b9990u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b9994u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b9994u) { target=s->pc; goto dispatch; }
goto P_0c0b9994;
P_0c0b9992: /* original 05de, guest PC 0x0c0b9992 */
if(!s->budget--) { s->failed_pc=0x0c0b9992u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b9994;
P_0c0b9994: /* original 945f, guest PC 0x0c0b9994 */
if(!s->budget--) { s->failed_pc=0x0c0b9994u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b9a56u,2);
goto P_0c0b9996;
P_0c0b9996: /* original e074, guest PC 0x0c0b9996 */
if(!s->budget--) { s->failed_pc=0x0c0b9996u; return 0; }
r[0]=0x00000074u;
goto P_0c0b9998;
P_0c0b9998: /* original 4e0b, guest PC 0x0c0b9998 */
if(!s->budget--) { s->failed_pc=0x0c0b9998u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b999cu;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b999cu) { target=s->pc; goto dispatch; }
goto P_0c0b999c;
P_0c0b999a: /* original 05de, guest PC 0x0c0b999a */
if(!s->budget--) { s->failed_pc=0x0c0b999au; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b999c;
P_0c0b999c: /* original 945c, guest PC 0x0c0b999c */
if(!s->budget--) { s->failed_pc=0x0c0b999cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b9a58u,2);
goto P_0c0b999e;
P_0c0b999e: /* original e078, guest PC 0x0c0b999e */
if(!s->budget--) { s->failed_pc=0x0c0b999eu; return 0; }
r[0]=0x00000078u;
goto P_0c0b99a0;
P_0c0b99a0: /* original 4e0b, guest PC 0x0c0b99a0 */
if(!s->budget--) { s->failed_pc=0x0c0b99a0u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b99a4u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b99a4u) { target=s->pc; goto dispatch; }
goto P_0c0b99a4;
P_0c0b99a2: /* original 05de, guest PC 0x0c0b99a2 */
if(!s->budget--) { s->failed_pc=0x0c0b99a2u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b99a4;
P_0c0b99a4: /* original 9459, guest PC 0x0c0b99a4 */
if(!s->budget--) { s->failed_pc=0x0c0b99a4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b9a5au,2);
goto P_0c0b99a6;
P_0c0b99a6: /* original e07c, guest PC 0x0c0b99a6 */
if(!s->budget--) { s->failed_pc=0x0c0b99a6u; return 0; }
r[0]=0x0000007cu;
goto P_0c0b99a8;
P_0c0b99a8: /* original 4e0b, guest PC 0x0c0b99a8 */
if(!s->budget--) { s->failed_pc=0x0c0b99a8u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b99acu;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b99acu) { target=s->pc; goto dispatch; }
goto P_0c0b99ac;
P_0c0b99aa: /* original 05de, guest PC 0x0c0b99aa */
if(!s->budget--) { s->failed_pc=0x0c0b99aau; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b99ac;
P_0c0b99ac: /* original 9457, guest PC 0x0c0b99ac */
if(!s->budget--) { s->failed_pc=0x0c0b99acu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b9a5eu,2);
goto P_0c0b99ae;
P_0c0b99ae: /* original 9055, guest PC 0x0c0b99ae */
if(!s->budget--) { s->failed_pc=0x0c0b99aeu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b9a5cu,2);
goto P_0c0b99b0;
P_0c0b99b0: /* original 4e0b, guest PC 0x0c0b99b0 */
if(!s->budget--) { s->failed_pc=0x0c0b99b0u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b99b4u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b99b4u) { target=s->pc; goto dispatch; }
goto P_0c0b99b4;
P_0c0b99b2: /* original 05de, guest PC 0x0c0b99b2 */
if(!s->budget--) { s->failed_pc=0x0c0b99b2u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b99b4;
P_0c0b99b4: /* original 9554, guest PC 0x0c0b99b4 */
if(!s->budget--) { s->failed_pc=0x0c0b99b4u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b9a60u,2);
goto P_0c0b99b6;
P_0c0b99b6: /* original 35dc, guest PC 0x0c0b99b6 */
if(!s->budget--) { s->failed_pc=0x0c0b99b6u; return 0; }
r[5]+=r[13];
goto P_0c0b99b8;
P_0c0b99b8: /* original 2f52, guest PC 0x0c0b99b8 */
if(!s->budget--) { s->failed_pc=0x0c0b99b8u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0b99ba;
P_0c0b99ba: /* original 9452, guest PC 0x0c0b99ba */
if(!s->budget--) { s->failed_pc=0x0c0b99bau; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b9a62u,2);
goto P_0c0b99bc;
P_0c0b99bc: /* original 4e0b, guest PC 0x0c0b99bc */
if(!s->budget--) { s->failed_pc=0x0c0b99bcu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b99c0u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b99c0u) { target=s->pc; goto dispatch; }
goto P_0c0b99c0;
P_0c0b99be: /* original 6552, guest PC 0x0c0b99be */
if(!s->budget--) { s->failed_pc=0x0c0b99beu; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b99c0;
P_0c0b99c0: /* original 9550, guest PC 0x0c0b99c0 */
if(!s->budget--) { s->failed_pc=0x0c0b99c0u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b9a64u,2);
goto P_0c0b99c2;
P_0c0b99c2: /* original 35dc, guest PC 0x0c0b99c2 */
if(!s->budget--) { s->failed_pc=0x0c0b99c2u; return 0; }
r[5]+=r[13];
goto P_0c0b99c4;
P_0c0b99c4: /* original 1f51, guest PC 0x0c0b99c4 */
if(!s->budget--) { s->failed_pc=0x0c0b99c4u; return 0; }
write(ram,r[15]+4,r[5],4);
goto P_0c0b99c6;
P_0c0b99c6: /* original 944e, guest PC 0x0c0b99c6 */
if(!s->budget--) { s->failed_pc=0x0c0b99c6u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b9a66u,2);
goto P_0c0b99c8;
P_0c0b99c8: /* original 4e0b, guest PC 0x0c0b99c8 */
if(!s->budget--) { s->failed_pc=0x0c0b99c8u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b99ccu;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b99ccu) { target=s->pc; goto dispatch; }
goto P_0c0b99cc;
P_0c0b99ca: /* original 6552, guest PC 0x0c0b99ca */
if(!s->budget--) { s->failed_pc=0x0c0b99cau; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b99cc;
P_0c0b99cc: /* original 944d, guest PC 0x0c0b99cc */
if(!s->budget--) { s->failed_pc=0x0c0b99ccu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b9a6au,2);
goto P_0c0b99ce;
P_0c0b99ce: /* original 904b, guest PC 0x0c0b99ce */
if(!s->budget--) { s->failed_pc=0x0c0b99ceu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b9a68u,2);
goto P_0c0b99d0;
P_0c0b99d0: /* original 4e0b, guest PC 0x0c0b99d0 */
if(!s->budget--) { s->failed_pc=0x0c0b99d0u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b99d4u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b99d4u) { target=s->pc; goto dispatch; }
goto P_0c0b99d4;
P_0c0b99d2: /* original 05de, guest PC 0x0c0b99d2 */
if(!s->budget--) { s->failed_pc=0x0c0b99d2u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b99d4;
P_0c0b99d4: /* original 944b, guest PC 0x0c0b99d4 */
if(!s->budget--) { s->failed_pc=0x0c0b99d4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b9a6eu,2);
goto P_0c0b99d6;
P_0c0b99d6: /* original 9049, guest PC 0x0c0b99d6 */
if(!s->budget--) { s->failed_pc=0x0c0b99d6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b9a6cu,2);
goto P_0c0b99d8;
P_0c0b99d8: /* original 4e0b, guest PC 0x0c0b99d8 */
if(!s->budget--) { s->failed_pc=0x0c0b99d8u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b99dcu;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b99dcu) { target=s->pc; goto dispatch; }
goto P_0c0b99dc;
P_0c0b99da: /* original 05de, guest PC 0x0c0b99da */
if(!s->budget--) { s->failed_pc=0x0c0b99dau; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b99dc;
P_0c0b99dc: /* original 9948, guest PC 0x0c0b99dc */
if(!s->budget--) { s->failed_pc=0x0c0b99dcu; return 0; }
r[9]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b9a70u,2);
goto P_0c0b99de;
P_0c0b99de: /* original 9448, guest PC 0x0c0b99de */
if(!s->budget--) { s->failed_pc=0x0c0b99deu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b9a72u,2);
goto P_0c0b99e0;
P_0c0b99e0: /* original 39dc, guest PC 0x0c0b99e0 */
if(!s->budget--) { s->failed_pc=0x0c0b99e0u; return 0; }
r[9]+=r[13];
goto P_0c0b99e2;
P_0c0b99e2: /* original 4e0b, guest PC 0x0c0b99e2 */
if(!s->budget--) { s->failed_pc=0x0c0b99e2u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b99e6u;
tmp=read(ram,r[9],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b99e6u) { target=s->pc; goto dispatch; }
goto P_0c0b99e6;
P_0c0b99e4: /* original 6592, guest PC 0x0c0b99e4 */
if(!s->budget--) { s->failed_pc=0x0c0b99e4u; return 0; }
tmp=read(ram,r[9],4);
r[5]=tmp;
goto P_0c0b99e6;
P_0c0b99e6: /* original 9445, guest PC 0x0c0b99e6 */
if(!s->budget--) { s->failed_pc=0x0c0b99e6u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b9a74u,2);
goto P_0c0b99e8;
P_0c0b99e8: /* original 4e0b, guest PC 0x0c0b99e8 */
if(!s->budget--) { s->failed_pc=0x0c0b99e8u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b99ecu;
tmp=read(ram,r[9],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b99ecu) { target=s->pc; goto dispatch; }
goto P_0c0b99ec;
P_0c0b99ea: /* original 6592, guest PC 0x0c0b99ea */
if(!s->budget--) { s->failed_pc=0x0c0b99eau; return 0; }
tmp=read(ram,r[9],4);
r[5]=tmp;
goto P_0c0b99ec;
P_0c0b99ec: /* original 9443, guest PC 0x0c0b99ec */
if(!s->budget--) { s->failed_pc=0x0c0b99ecu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b9a76u,2);
goto P_0c0b99ee;
P_0c0b99ee: /* original 4e0b, guest PC 0x0c0b99ee */
if(!s->budget--) { s->failed_pc=0x0c0b99eeu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b99f2u;
tmp=read(ram,r[9],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b99f2u) { target=s->pc; goto dispatch; }
goto P_0c0b99f2;
P_0c0b99f0: /* original 6592, guest PC 0x0c0b99f0 */
if(!s->budget--) { s->failed_pc=0x0c0b99f0u; return 0; }
tmp=read(ram,r[9],4);
r[5]=tmp;
goto P_0c0b99f2;
P_0c0b99f2: /* original 9441, guest PC 0x0c0b99f2 */
if(!s->budget--) { s->failed_pc=0x0c0b99f2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b9a78u,2);
goto P_0c0b99f4;
P_0c0b99f4: /* original 4e0b, guest PC 0x0c0b99f4 */
if(!s->budget--) { s->failed_pc=0x0c0b99f4u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b99f8u;
tmp=read(ram,r[9],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b99f8u) { target=s->pc; goto dispatch; }
goto P_0c0b99f8;
P_0c0b99f6: /* original 6592, guest PC 0x0c0b99f6 */
if(!s->budget--) { s->failed_pc=0x0c0b99f6u; return 0; }
tmp=read(ram,r[9],4);
r[5]=tmp;
goto P_0c0b99f8;
P_0c0b99f8: /* original 9c3f, guest PC 0x0c0b99f8 */
if(!s->budget--) { s->failed_pc=0x0c0b99f8u; return 0; }
r[12]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b9a7au,2);
goto P_0c0b99fa;
P_0c0b99fa: /* original 943f, guest PC 0x0c0b99fa */
if(!s->budget--) { s->failed_pc=0x0c0b99fau; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b9a7cu,2);
goto P_0c0b99fc;
P_0c0b99fc: /* original 3cdc, guest PC 0x0c0b99fc */
if(!s->budget--) { s->failed_pc=0x0c0b99fcu; return 0; }
r[12]+=r[13];
goto P_0c0b99fe;
P_0c0b99fe: /* original 4e0b, guest PC 0x0c0b99fe */
if(!s->budget--) { s->failed_pc=0x0c0b99feu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b9a02u;
tmp=read(ram,r[12],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b9a02u) { target=s->pc; goto dispatch; }
goto P_0c0b9a02;
P_0c0b9a00: /* original 65c2, guest PC 0x0c0b9a00 */
if(!s->budget--) { s->failed_pc=0x0c0b9a00u; return 0; }
tmp=read(ram,r[12],4);
r[5]=tmp;
goto P_0c0b9a02;
P_0c0b9a02: /* original 943c, guest PC 0x0c0b9a02 */
if(!s->budget--) { s->failed_pc=0x0c0b9a02u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b9a7eu,2);
goto P_0c0b9a04;
P_0c0b9a04: /* original 4e0b, guest PC 0x0c0b9a04 */
if(!s->budget--) { s->failed_pc=0x0c0b9a04u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b9a08u;
tmp=read(ram,r[12],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b9a08u) { target=s->pc; goto dispatch; }
goto P_0c0b9a08;
P_0c0b9a06: /* original 65c2, guest PC 0x0c0b9a06 */
if(!s->budget--) { s->failed_pc=0x0c0b9a06u; return 0; }
tmp=read(ram,r[12],4);
r[5]=tmp;
goto P_0c0b9a08;
P_0c0b9a08: /* original 943a, guest PC 0x0c0b9a08 */
if(!s->budget--) { s->failed_pc=0x0c0b9a08u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b9a80u,2);
goto P_0c0b9a0a;
P_0c0b9a0a: /* original 4e0b, guest PC 0x0c0b9a0a */
if(!s->budget--) { s->failed_pc=0x0c0b9a0au; return 0; }
target=r[14];
r[16]=code_base|0x0c0b9a0eu;
tmp=read(ram,r[12],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b9a0eu) { target=s->pc; goto dispatch; }
goto P_0c0b9a0e;
P_0c0b9a0c: /* original 65c2, guest PC 0x0c0b9a0c */
if(!s->budget--) { s->failed_pc=0x0c0b9a0cu; return 0; }
tmp=read(ram,r[12],4);
r[5]=tmp;
goto P_0c0b9a0e;
P_0c0b9a0e: /* original 9438, guest PC 0x0c0b9a0e */
if(!s->budget--) { s->failed_pc=0x0c0b9a0eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b9a82u,2);
goto P_0c0b9a10;
P_0c0b9a10: /* original 4e0b, guest PC 0x0c0b9a10 */
if(!s->budget--) { s->failed_pc=0x0c0b9a10u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b9a14u;
tmp=read(ram,r[12],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b9a14u) { target=s->pc; goto dispatch; }
goto P_0c0b9a14;
P_0c0b9a12: /* original 65c2, guest PC 0x0c0b9a12 */
if(!s->budget--) { s->failed_pc=0x0c0b9a12u; return 0; }
tmp=read(ram,r[12],4);
r[5]=tmp;
goto P_0c0b9a14;
P_0c0b9a14: /* original 9b36, guest PC 0x0c0b9a14 */
if(!s->budget--) { s->failed_pc=0x0c0b9a14u; return 0; }
r[11]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b9a84u,2);
goto P_0c0b9a16;
P_0c0b9a16: /* original 3bdc, guest PC 0x0c0b9a16 */
if(!s->budget--) { s->failed_pc=0x0c0b9a16u; return 0; }
r[11]+=r[13];
goto P_0c0b9a18;
P_0c0b9a18: /* original a038, guest PC 0x0c0b9a18 */
if(!s->budget--) { s->failed_pc=0x0c0b9a18u; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
goto P_0c0b9a8c;
P_0c0b9a1a: /* original 65b2, guest PC 0x0c0b9a1a */
if(!s->budget--) { s->failed_pc=0x0c0b9a1au; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
if(!vf3_matrix_family(0x0c0b9a1cu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0b9a1cu; return 0; } return 1;
P_0c0b9a8c: /* original 94ab, guest PC 0x0c0b9a8c */
if(!s->budget--) { s->failed_pc=0x0c0b9a8cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b9be6u,2);
goto P_0c0b9a8e;
P_0c0b9a8e: /* original 4e0b, guest PC 0x0c0b9a8e */
if(!s->budget--) { s->failed_pc=0x0c0b9a8eu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b9a92u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b9a92u) { target=s->pc; goto dispatch; }
goto P_0c0b9a92;
P_0c0b9a90: /* original 0009, guest PC 0x0c0b9a90 */
if(!s->budget--) { s->failed_pc=0x0c0b9a90u; return 0; }
goto P_0c0b9a92;
P_0c0b9a92: /* original 94a9, guest PC 0x0c0b9a92 */
if(!s->budget--) { s->failed_pc=0x0c0b9a92u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b9be8u,2);
goto P_0c0b9a94;
P_0c0b9a94: /* original 4e0b, guest PC 0x0c0b9a94 */
if(!s->budget--) { s->failed_pc=0x0c0b9a94u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b9a98u;
tmp=read(ram,r[11],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b9a98u) { target=s->pc; goto dispatch; }
goto P_0c0b9a98;
P_0c0b9a96: /* original 65b2, guest PC 0x0c0b9a96 */
if(!s->budget--) { s->failed_pc=0x0c0b9a96u; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
goto P_0c0b9a98;
P_0c0b9a98: /* original 94a7, guest PC 0x0c0b9a98 */
if(!s->budget--) { s->failed_pc=0x0c0b9a98u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b9beau,2);
goto P_0c0b9a9a;
P_0c0b9a9a: /* original 4e0b, guest PC 0x0c0b9a9a */
if(!s->budget--) { s->failed_pc=0x0c0b9a9au; return 0; }
target=r[14];
r[16]=code_base|0x0c0b9a9eu;
tmp=read(ram,r[11],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b9a9eu) { target=s->pc; goto dispatch; }
goto P_0c0b9a9e;
P_0c0b9a9c: /* original 65b2, guest PC 0x0c0b9a9c */
if(!s->budget--) { s->failed_pc=0x0c0b9a9cu; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
goto P_0c0b9a9e;
P_0c0b9a9e: /* original 94a5, guest PC 0x0c0b9a9e */
if(!s->budget--) { s->failed_pc=0x0c0b9a9eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b9becu,2);
goto P_0c0b9aa0;
P_0c0b9aa0: /* original 4e0b, guest PC 0x0c0b9aa0 */
if(!s->budget--) { s->failed_pc=0x0c0b9aa0u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b9aa4u;
tmp=read(ram,r[11],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b9aa4u) { target=s->pc; goto dispatch; }
goto P_0c0b9aa4;
P_0c0b9aa2: /* original 65b2, guest PC 0x0c0b9aa2 */
if(!s->budget--) { s->failed_pc=0x0c0b9aa2u; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
goto P_0c0b9aa4;
P_0c0b9aa4: /* original 9aa3, guest PC 0x0c0b9aa4 */
if(!s->budget--) { s->failed_pc=0x0c0b9aa4u; return 0; }
r[10]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b9beeu,2);
goto P_0c0b9aa6;
P_0c0b9aa6: /* original 94a3, guest PC 0x0c0b9aa6 */
if(!s->budget--) { s->failed_pc=0x0c0b9aa6u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b9bf0u,2);
goto P_0c0b9aa8;
P_0c0b9aa8: /* original 3adc, guest PC 0x0c0b9aa8 */
if(!s->budget--) { s->failed_pc=0x0c0b9aa8u; return 0; }
r[10]+=r[13];
goto P_0c0b9aaa;
P_0c0b9aaa: /* original 4e0b, guest PC 0x0c0b9aaa */
if(!s->budget--) { s->failed_pc=0x0c0b9aaau; return 0; }
target=r[14];
r[16]=code_base|0x0c0b9aaeu;
tmp=read(ram,r[10],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b9aaeu) { target=s->pc; goto dispatch; }
goto P_0c0b9aae;
P_0c0b9aac: /* original 65a2, guest PC 0x0c0b9aac */
if(!s->budget--) { s->failed_pc=0x0c0b9aacu; return 0; }
tmp=read(ram,r[10],4);
r[5]=tmp;
goto P_0c0b9aae;
P_0c0b9aae: /* original 94a0, guest PC 0x0c0b9aae */
if(!s->budget--) { s->failed_pc=0x0c0b9aaeu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b9bf2u,2);
goto P_0c0b9ab0;
P_0c0b9ab0: /* original 4e0b, guest PC 0x0c0b9ab0 */
if(!s->budget--) { s->failed_pc=0x0c0b9ab0u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b9ab4u;
tmp=read(ram,r[10],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b9ab4u) { target=s->pc; goto dispatch; }
goto P_0c0b9ab4;
P_0c0b9ab2: /* original 65a2, guest PC 0x0c0b9ab2 */
if(!s->budget--) { s->failed_pc=0x0c0b9ab2u; return 0; }
tmp=read(ram,r[10],4);
r[5]=tmp;
goto P_0c0b9ab4;
P_0c0b9ab4: /* original 949e, guest PC 0x0c0b9ab4 */
if(!s->budget--) { s->failed_pc=0x0c0b9ab4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b9bf4u,2);
goto P_0c0b9ab6;
P_0c0b9ab6: /* original 4e0b, guest PC 0x0c0b9ab6 */
if(!s->budget--) { s->failed_pc=0x0c0b9ab6u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b9abau;
tmp=read(ram,r[10],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b9abau) { target=s->pc; goto dispatch; }
goto P_0c0b9aba;
P_0c0b9ab8: /* original 65a2, guest PC 0x0c0b9ab8 */
if(!s->budget--) { s->failed_pc=0x0c0b9ab8u; return 0; }
tmp=read(ram,r[10],4);
r[5]=tmp;
goto P_0c0b9aba;
P_0c0b9aba: /* original 949c, guest PC 0x0c0b9aba */
if(!s->budget--) { s->failed_pc=0x0c0b9abau; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b9bf6u,2);
goto P_0c0b9abc;
P_0c0b9abc: /* original 4e0b, guest PC 0x0c0b9abc */
if(!s->budget--) { s->failed_pc=0x0c0b9abcu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b9ac0u;
tmp=read(ram,r[10],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b9ac0u) { target=s->pc; goto dispatch; }
goto P_0c0b9ac0;
P_0c0b9abe: /* original 65a2, guest PC 0x0c0b9abe */
if(!s->budget--) { s->failed_pc=0x0c0b9abeu; return 0; }
tmp=read(ram,r[10],4);
r[5]=tmp;
goto P_0c0b9ac0;
P_0c0b9ac0: /* original 949a, guest PC 0x0c0b9ac0 */
if(!s->budget--) { s->failed_pc=0x0c0b9ac0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b9bf8u,2);
goto P_0c0b9ac2;
P_0c0b9ac2: /* original 65f2, guest PC 0x0c0b9ac2 */
if(!s->budget--) { s->failed_pc=0x0c0b9ac2u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0b9ac4;
P_0c0b9ac4: /* original 4e0b, guest PC 0x0c0b9ac4 */
if(!s->budget--) { s->failed_pc=0x0c0b9ac4u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b9ac8u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b9ac8u) { target=s->pc; goto dispatch; }
goto P_0c0b9ac8;
P_0c0b9ac6: /* original 6552, guest PC 0x0c0b9ac6 */
if(!s->budget--) { s->failed_pc=0x0c0b9ac6u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b9ac8;
P_0c0b9ac8: /* original 9497, guest PC 0x0c0b9ac8 */
if(!s->budget--) { s->failed_pc=0x0c0b9ac8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b9bfau,2);
goto P_0c0b9aca;
P_0c0b9aca: /* original 55f1, guest PC 0x0c0b9aca */
if(!s->budget--) { s->failed_pc=0x0c0b9acau; return 0; }
r[5]=read(ram,r[15]+4,4);
goto P_0c0b9acc;
P_0c0b9acc: /* original 4e0b, guest PC 0x0c0b9acc */
if(!s->budget--) { s->failed_pc=0x0c0b9accu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b9ad0u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b9ad0u) { target=s->pc; goto dispatch; }
goto P_0c0b9ad0;
P_0c0b9ace: /* original 6552, guest PC 0x0c0b9ace */
if(!s->budget--) { s->failed_pc=0x0c0b9aceu; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b9ad0;
P_0c0b9ad0: /* original 9494, guest PC 0x0c0b9ad0 */
if(!s->budget--) { s->failed_pc=0x0c0b9ad0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b9bfcu,2);
goto P_0c0b9ad2;
P_0c0b9ad2: /* original 4e0b, guest PC 0x0c0b9ad2 */
if(!s->budget--) { s->failed_pc=0x0c0b9ad2u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b9ad6u;
tmp=read(ram,r[9],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b9ad6u) { target=s->pc; goto dispatch; }
goto P_0c0b9ad6;
P_0c0b9ad4: /* original 6592, guest PC 0x0c0b9ad4 */
if(!s->budget--) { s->failed_pc=0x0c0b9ad4u; return 0; }
tmp=read(ram,r[9],4);
r[5]=tmp;
goto P_0c0b9ad6;
P_0c0b9ad6: /* original 9492, guest PC 0x0c0b9ad6 */
if(!s->budget--) { s->failed_pc=0x0c0b9ad6u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b9bfeu,2);
goto P_0c0b9ad8;
P_0c0b9ad8: /* original 4e0b, guest PC 0x0c0b9ad8 */
if(!s->budget--) { s->failed_pc=0x0c0b9ad8u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b9adcu;
tmp=read(ram,r[9],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b9adcu) { target=s->pc; goto dispatch; }
goto P_0c0b9adc;
P_0c0b9ada: /* original 6592, guest PC 0x0c0b9ada */
if(!s->budget--) { s->failed_pc=0x0c0b9adau; return 0; }
tmp=read(ram,r[9],4);
r[5]=tmp;
goto P_0c0b9adc;
P_0c0b9adc: /* original 9490, guest PC 0x0c0b9adc */
if(!s->budget--) { s->failed_pc=0x0c0b9adcu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b9c00u,2);
goto P_0c0b9ade;
P_0c0b9ade: /* original 4e0b, guest PC 0x0c0b9ade */
if(!s->budget--) { s->failed_pc=0x0c0b9adeu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b9ae2u;
tmp=read(ram,r[9],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b9ae2u) { target=s->pc; goto dispatch; }
goto P_0c0b9ae2;
P_0c0b9ae0: /* original 6592, guest PC 0x0c0b9ae0 */
if(!s->budget--) { s->failed_pc=0x0c0b9ae0u; return 0; }
tmp=read(ram,r[9],4);
r[5]=tmp;
goto P_0c0b9ae2;
P_0c0b9ae2: /* original 948e, guest PC 0x0c0b9ae2 */
if(!s->budget--) { s->failed_pc=0x0c0b9ae2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b9c02u,2);
goto P_0c0b9ae4;
P_0c0b9ae4: /* original 4e0b, guest PC 0x0c0b9ae4 */
if(!s->budget--) { s->failed_pc=0x0c0b9ae4u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b9ae8u;
tmp=read(ram,r[9],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b9ae8u) { target=s->pc; goto dispatch; }
goto P_0c0b9ae8;
P_0c0b9ae6: /* original 6592, guest PC 0x0c0b9ae6 */
if(!s->budget--) { s->failed_pc=0x0c0b9ae6u; return 0; }
tmp=read(ram,r[9],4);
r[5]=tmp;
goto P_0c0b9ae8;
P_0c0b9ae8: /* original 948c, guest PC 0x0c0b9ae8 */
if(!s->budget--) { s->failed_pc=0x0c0b9ae8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b9c04u,2);
goto P_0c0b9aea;
P_0c0b9aea: /* original 4e0b, guest PC 0x0c0b9aea */
if(!s->budget--) { s->failed_pc=0x0c0b9aeau; return 0; }
target=r[14];
r[16]=code_base|0x0c0b9aeeu;
tmp=read(ram,r[12],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b9aeeu) { target=s->pc; goto dispatch; }
goto P_0c0b9aee;
P_0c0b9aec: /* original 65c2, guest PC 0x0c0b9aec */
if(!s->budget--) { s->failed_pc=0x0c0b9aecu; return 0; }
tmp=read(ram,r[12],4);
r[5]=tmp;
goto P_0c0b9aee;
P_0c0b9aee: /* original 948a, guest PC 0x0c0b9aee */
if(!s->budget--) { s->failed_pc=0x0c0b9aeeu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b9c06u,2);
goto P_0c0b9af0;
P_0c0b9af0: /* original 4e0b, guest PC 0x0c0b9af0 */
if(!s->budget--) { s->failed_pc=0x0c0b9af0u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b9af4u;
tmp=read(ram,r[12],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b9af4u) { target=s->pc; goto dispatch; }
goto P_0c0b9af4;
P_0c0b9af2: /* original 65c2, guest PC 0x0c0b9af2 */
if(!s->budget--) { s->failed_pc=0x0c0b9af2u; return 0; }
tmp=read(ram,r[12],4);
r[5]=tmp;
goto P_0c0b9af4;
P_0c0b9af4: /* original 9488, guest PC 0x0c0b9af4 */
if(!s->budget--) { s->failed_pc=0x0c0b9af4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b9c08u,2);
goto P_0c0b9af6;
P_0c0b9af6: /* original 4e0b, guest PC 0x0c0b9af6 */
if(!s->budget--) { s->failed_pc=0x0c0b9af6u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b9afau;
tmp=read(ram,r[12],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b9afau) { target=s->pc; goto dispatch; }
goto P_0c0b9afa;
P_0c0b9af8: /* original 65c2, guest PC 0x0c0b9af8 */
if(!s->budget--) { s->failed_pc=0x0c0b9af8u; return 0; }
tmp=read(ram,r[12],4);
r[5]=tmp;
goto P_0c0b9afa;
P_0c0b9afa: /* original 9486, guest PC 0x0c0b9afa */
if(!s->budget--) { s->failed_pc=0x0c0b9afau; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b9c0au,2);
goto P_0c0b9afc;
P_0c0b9afc: /* original 4e0b, guest PC 0x0c0b9afc */
if(!s->budget--) { s->failed_pc=0x0c0b9afcu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b9b00u;
tmp=read(ram,r[12],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b9b00u) { target=s->pc; goto dispatch; }
goto P_0c0b9b00;
P_0c0b9afe: /* original 65c2, guest PC 0x0c0b9afe */
if(!s->budget--) { s->failed_pc=0x0c0b9afeu; return 0; }
tmp=read(ram,r[12],4);
r[5]=tmp;
goto P_0c0b9b00;
P_0c0b9b00: /* original 9484, guest PC 0x0c0b9b00 */
if(!s->budget--) { s->failed_pc=0x0c0b9b00u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b9c0cu,2);
goto P_0c0b9b02;
P_0c0b9b02: /* original 4e0b, guest PC 0x0c0b9b02 */
if(!s->budget--) { s->failed_pc=0x0c0b9b02u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b9b06u;
tmp=read(ram,r[11],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b9b06u) { target=s->pc; goto dispatch; }
goto P_0c0b9b06;
P_0c0b9b04: /* original 65b2, guest PC 0x0c0b9b04 */
if(!s->budget--) { s->failed_pc=0x0c0b9b04u; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
goto P_0c0b9b06;
P_0c0b9b06: /* original 9482, guest PC 0x0c0b9b06 */
if(!s->budget--) { s->failed_pc=0x0c0b9b06u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b9c0eu,2);
goto P_0c0b9b08;
P_0c0b9b08: /* original 4e0b, guest PC 0x0c0b9b08 */
if(!s->budget--) { s->failed_pc=0x0c0b9b08u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b9b0cu;
tmp=read(ram,r[11],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b9b0cu) { target=s->pc; goto dispatch; }
goto P_0c0b9b0c;
P_0c0b9b0a: /* original 65b2, guest PC 0x0c0b9b0a */
if(!s->budget--) { s->failed_pc=0x0c0b9b0au; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
goto P_0c0b9b0c;
P_0c0b9b0c: /* original 9480, guest PC 0x0c0b9b0c */
if(!s->budget--) { s->failed_pc=0x0c0b9b0cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b9c10u,2);
goto P_0c0b9b0e;
P_0c0b9b0e: /* original 4e0b, guest PC 0x0c0b9b0e */
if(!s->budget--) { s->failed_pc=0x0c0b9b0eu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b9b12u;
tmp=read(ram,r[11],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b9b12u) { target=s->pc; goto dispatch; }
goto P_0c0b9b12;
P_0c0b9b10: /* original 65b2, guest PC 0x0c0b9b10 */
if(!s->budget--) { s->failed_pc=0x0c0b9b10u; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
goto P_0c0b9b12;
P_0c0b9b12: /* original 947e, guest PC 0x0c0b9b12 */
if(!s->budget--) { s->failed_pc=0x0c0b9b12u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b9c12u,2);
goto P_0c0b9b14;
P_0c0b9b14: /* original 4e0b, guest PC 0x0c0b9b14 */
if(!s->budget--) { s->failed_pc=0x0c0b9b14u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b9b18u;
tmp=read(ram,r[11],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b9b18u) { target=s->pc; goto dispatch; }
goto P_0c0b9b18;
P_0c0b9b16: /* original 65b2, guest PC 0x0c0b9b16 */
if(!s->budget--) { s->failed_pc=0x0c0b9b16u; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
goto P_0c0b9b18;
P_0c0b9b18: /* original 947c, guest PC 0x0c0b9b18 */
if(!s->budget--) { s->failed_pc=0x0c0b9b18u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b9c14u,2);
goto P_0c0b9b1a;
P_0c0b9b1a: /* original 4e0b, guest PC 0x0c0b9b1a */
if(!s->budget--) { s->failed_pc=0x0c0b9b1au; return 0; }
target=r[14];
r[16]=code_base|0x0c0b9b1eu;
tmp=read(ram,r[10],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b9b1eu) { target=s->pc; goto dispatch; }
goto P_0c0b9b1e;
P_0c0b9b1c: /* original 65a2, guest PC 0x0c0b9b1c */
if(!s->budget--) { s->failed_pc=0x0c0b9b1cu; return 0; }
tmp=read(ram,r[10],4);
r[5]=tmp;
goto P_0c0b9b1e;
P_0c0b9b1e: /* original 947a, guest PC 0x0c0b9b1e */
if(!s->budget--) { s->failed_pc=0x0c0b9b1eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b9c16u,2);
goto P_0c0b9b20;
P_0c0b9b20: /* original 4e0b, guest PC 0x0c0b9b20 */
if(!s->budget--) { s->failed_pc=0x0c0b9b20u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b9b24u;
tmp=read(ram,r[10],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b9b24u) { target=s->pc; goto dispatch; }
goto P_0c0b9b24;
P_0c0b9b22: /* original 65a2, guest PC 0x0c0b9b22 */
if(!s->budget--) { s->failed_pc=0x0c0b9b22u; return 0; }
tmp=read(ram,r[10],4);
r[5]=tmp;
goto P_0c0b9b24;
P_0c0b9b24: /* original 9478, guest PC 0x0c0b9b24 */
if(!s->budget--) { s->failed_pc=0x0c0b9b24u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b9c18u,2);
goto P_0c0b9b26;
P_0c0b9b26: /* original 4e0b, guest PC 0x0c0b9b26 */
if(!s->budget--) { s->failed_pc=0x0c0b9b26u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b9b2au;
tmp=read(ram,r[10],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b9b2au) { target=s->pc; goto dispatch; }
goto P_0c0b9b2a;
P_0c0b9b28: /* original 65a2, guest PC 0x0c0b9b28 */
if(!s->budget--) { s->failed_pc=0x0c0b9b28u; return 0; }
tmp=read(ram,r[10],4);
r[5]=tmp;
goto P_0c0b9b2a;
P_0c0b9b2a: /* original 9476, guest PC 0x0c0b9b2a */
if(!s->budget--) { s->failed_pc=0x0c0b9b2au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b9c1au,2);
goto P_0c0b9b2c;
P_0c0b9b2c: /* original 4e0b, guest PC 0x0c0b9b2c */
if(!s->budget--) { s->failed_pc=0x0c0b9b2cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b9b30u;
tmp=read(ram,r[10],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b9b30u) { target=s->pc; goto dispatch; }
goto P_0c0b9b30;
P_0c0b9b2e: /* original 65a2, guest PC 0x0c0b9b2e */
if(!s->budget--) { s->failed_pc=0x0c0b9b2eu; return 0; }
tmp=read(ram,r[10],4);
r[5]=tmp;
goto P_0c0b9b30;
P_0c0b9b30: /* original 9574, guest PC 0x0c0b9b30 */
if(!s->budget--) { s->failed_pc=0x0c0b9b30u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b9c1cu,2);
goto P_0c0b9b32;
P_0c0b9b32: /* original 35dc, guest PC 0x0c0b9b32 */
if(!s->budget--) { s->failed_pc=0x0c0b9b32u; return 0; }
r[5]+=r[13];
goto P_0c0b9b34;
P_0c0b9b34: /* original 2f52, guest PC 0x0c0b9b34 */
if(!s->budget--) { s->failed_pc=0x0c0b9b34u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0b9b36;
P_0c0b9b36: /* original 9472, guest PC 0x0c0b9b36 */
if(!s->budget--) { s->failed_pc=0x0c0b9b36u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b9c1eu,2);
goto P_0c0b9b38;
P_0c0b9b38: /* original 4e0b, guest PC 0x0c0b9b38 */
if(!s->budget--) { s->failed_pc=0x0c0b9b38u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b9b3cu;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b9b3cu) { target=s->pc; goto dispatch; }
goto P_0c0b9b3c;
P_0c0b9b3a: /* original 6552, guest PC 0x0c0b9b3a */
if(!s->budget--) { s->failed_pc=0x0c0b9b3au; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b9b3c;
P_0c0b9b3c: /* original 9470, guest PC 0x0c0b9b3c */
if(!s->budget--) { s->failed_pc=0x0c0b9b3cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b9c20u,2);
goto P_0c0b9b3e;
P_0c0b9b3e: /* original 65f2, guest PC 0x0c0b9b3e */
if(!s->budget--) { s->failed_pc=0x0c0b9b3eu; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0b9b40;
P_0c0b9b40: /* original 4e0b, guest PC 0x0c0b9b40 */
if(!s->budget--) { s->failed_pc=0x0c0b9b40u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b9b44u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b9b44u) { target=s->pc; goto dispatch; }
goto P_0c0b9b44;
P_0c0b9b42: /* original 6552, guest PC 0x0c0b9b42 */
if(!s->budget--) { s->failed_pc=0x0c0b9b42u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b9b44;
P_0c0b9b44: /* original 956d, guest PC 0x0c0b9b44 */
if(!s->budget--) { s->failed_pc=0x0c0b9b44u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b9c22u,2);
goto P_0c0b9b46;
P_0c0b9b46: /* original 35dc, guest PC 0x0c0b9b46 */
if(!s->budget--) { s->failed_pc=0x0c0b9b46u; return 0; }
r[5]+=r[13];
goto P_0c0b9b48;
P_0c0b9b48: /* original 2f52, guest PC 0x0c0b9b48 */
if(!s->budget--) { s->failed_pc=0x0c0b9b48u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0b9b4a;
P_0c0b9b4a: /* original 946b, guest PC 0x0c0b9b4a */
if(!s->budget--) { s->failed_pc=0x0c0b9b4au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b9c24u,2);
goto P_0c0b9b4c;
P_0c0b9b4c: /* original 4e0b, guest PC 0x0c0b9b4c */
if(!s->budget--) { s->failed_pc=0x0c0b9b4cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b9b50u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b9b50u) { target=s->pc; goto dispatch; }
goto P_0c0b9b50;
P_0c0b9b4e: /* original 6552, guest PC 0x0c0b9b4e */
if(!s->budget--) { s->failed_pc=0x0c0b9b4eu; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b9b50;
P_0c0b9b50: /* original 9469, guest PC 0x0c0b9b50 */
if(!s->budget--) { s->failed_pc=0x0c0b9b50u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b9c26u,2);
goto P_0c0b9b52;
P_0c0b9b52: /* original 65f2, guest PC 0x0c0b9b52 */
if(!s->budget--) { s->failed_pc=0x0c0b9b52u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0b9b54;
P_0c0b9b54: /* original 4e0b, guest PC 0x0c0b9b54 */
if(!s->budget--) { s->failed_pc=0x0c0b9b54u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b9b58u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b9b58u) { target=s->pc; goto dispatch; }
goto P_0c0b9b58;
P_0c0b9b56: /* original 6552, guest PC 0x0c0b9b56 */
if(!s->budget--) { s->failed_pc=0x0c0b9b56u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b9b58;
P_0c0b9b58: /* original 9467, guest PC 0x0c0b9b58 */
if(!s->budget--) { s->failed_pc=0x0c0b9b58u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b9c2au,2);
goto P_0c0b9b5a;
P_0c0b9b5a: /* original 9065, guest PC 0x0c0b9b5a */
if(!s->budget--) { s->failed_pc=0x0c0b9b5au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b9c28u,2);
goto P_0c0b9b5c;
P_0c0b9b5c: /* original 4e0b, guest PC 0x0c0b9b5c */
if(!s->budget--) { s->failed_pc=0x0c0b9b5cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b9b60u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b9b60u) { target=s->pc; goto dispatch; }
goto P_0c0b9b60;
P_0c0b9b5e: /* original 05de, guest PC 0x0c0b9b5e */
if(!s->budget--) { s->failed_pc=0x0c0b9b5eu; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b9b60;
P_0c0b9b60: /* original 9564, guest PC 0x0c0b9b60 */
if(!s->budget--) { s->failed_pc=0x0c0b9b60u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b9c2cu,2);
goto P_0c0b9b62;
P_0c0b9b62: /* original 35dc, guest PC 0x0c0b9b62 */
if(!s->budget--) { s->failed_pc=0x0c0b9b62u; return 0; }
r[5]+=r[13];
goto P_0c0b9b64;
P_0c0b9b64: /* original 2f52, guest PC 0x0c0b9b64 */
if(!s->budget--) { s->failed_pc=0x0c0b9b64u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0b9b66;
P_0c0b9b66: /* original 9462, guest PC 0x0c0b9b66 */
if(!s->budget--) { s->failed_pc=0x0c0b9b66u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b9c2eu,2);
goto P_0c0b9b68;
P_0c0b9b68: /* original 4e0b, guest PC 0x0c0b9b68 */
if(!s->budget--) { s->failed_pc=0x0c0b9b68u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b9b6cu;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b9b6cu) { target=s->pc; goto dispatch; }
goto P_0c0b9b6c;
P_0c0b9b6a: /* original 6552, guest PC 0x0c0b9b6a */
if(!s->budget--) { s->failed_pc=0x0c0b9b6au; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b9b6c;
P_0c0b9b6c: /* original 9460, guest PC 0x0c0b9b6c */
if(!s->budget--) { s->failed_pc=0x0c0b9b6cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b9c30u,2);
goto P_0c0b9b6e;
P_0c0b9b6e: /* original 65f2, guest PC 0x0c0b9b6e */
if(!s->budget--) { s->failed_pc=0x0c0b9b6eu; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0b9b70;
P_0c0b9b70: /* original 4e0b, guest PC 0x0c0b9b70 */
if(!s->budget--) { s->failed_pc=0x0c0b9b70u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b9b74u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b9b74u) { target=s->pc; goto dispatch; }
goto P_0c0b9b74;
P_0c0b9b72: /* original 6552, guest PC 0x0c0b9b72 */
if(!s->budget--) { s->failed_pc=0x0c0b9b72u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b9b74;
P_0c0b9b74: /* original 945e, guest PC 0x0c0b9b74 */
if(!s->budget--) { s->failed_pc=0x0c0b9b74u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b9c34u,2);
goto P_0c0b9b76;
P_0c0b9b76: /* original 905c, guest PC 0x0c0b9b76 */
if(!s->budget--) { s->failed_pc=0x0c0b9b76u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b9c32u,2);
goto P_0c0b9b78;
P_0c0b9b78: /* original 4e0b, guest PC 0x0c0b9b78 */
if(!s->budget--) { s->failed_pc=0x0c0b9b78u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b9b7cu;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b9b7cu) { target=s->pc; goto dispatch; }
goto P_0c0b9b7c;
P_0c0b9b7a: /* original 05de, guest PC 0x0c0b9b7a */
if(!s->budget--) { s->failed_pc=0x0c0b9b7au; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b9b7c;
P_0c0b9b7c: /* original 955b, guest PC 0x0c0b9b7c */
if(!s->budget--) { s->failed_pc=0x0c0b9b7cu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b9c36u,2);
goto P_0c0b9b7e;
P_0c0b9b7e: /* original 35dc, guest PC 0x0c0b9b7e */
if(!s->budget--) { s->failed_pc=0x0c0b9b7eu; return 0; }
r[5]+=r[13];
goto P_0c0b9b80;
P_0c0b9b80: /* original 2f52, guest PC 0x0c0b9b80 */
if(!s->budget--) { s->failed_pc=0x0c0b9b80u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0b9b82;
P_0c0b9b82: /* original 9459, guest PC 0x0c0b9b82 */
if(!s->budget--) { s->failed_pc=0x0c0b9b82u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b9c38u,2);
goto P_0c0b9b84;
P_0c0b9b84: /* original 4e0b, guest PC 0x0c0b9b84 */
if(!s->budget--) { s->failed_pc=0x0c0b9b84u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b9b88u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b9b88u) { target=s->pc; goto dispatch; }
goto P_0c0b9b88;
P_0c0b9b86: /* original 6552, guest PC 0x0c0b9b86 */
if(!s->budget--) { s->failed_pc=0x0c0b9b86u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b9b88;
P_0c0b9b88: /* original 9457, guest PC 0x0c0b9b88 */
if(!s->budget--) { s->failed_pc=0x0c0b9b88u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b9c3au,2);
goto P_0c0b9b8a;
P_0c0b9b8a: /* original 65f2, guest PC 0x0c0b9b8a */
if(!s->budget--) { s->failed_pc=0x0c0b9b8au; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0b9b8c;
P_0c0b9b8c: /* original 4e0b, guest PC 0x0c0b9b8c */
if(!s->budget--) { s->failed_pc=0x0c0b9b8cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b9b90u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b9b90u) { target=s->pc; goto dispatch; }
goto P_0c0b9b90;
P_0c0b9b8e: /* original 6552, guest PC 0x0c0b9b8e */
if(!s->budget--) { s->failed_pc=0x0c0b9b8eu; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b9b90;
P_0c0b9b90: /* original 9455, guest PC 0x0c0b9b90 */
if(!s->budget--) { s->failed_pc=0x0c0b9b90u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b9c3eu,2);
goto P_0c0b9b92;
P_0c0b9b92: /* original 9053, guest PC 0x0c0b9b92 */
if(!s->budget--) { s->failed_pc=0x0c0b9b92u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b9c3cu,2);
goto P_0c0b9b94;
P_0c0b9b94: /* original 4e0b, guest PC 0x0c0b9b94 */
if(!s->budget--) { s->failed_pc=0x0c0b9b94u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b9b98u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b9b98u) { target=s->pc; goto dispatch; }
goto P_0c0b9b98;
P_0c0b9b96: /* original 05de, guest PC 0x0c0b9b96 */
if(!s->budget--) { s->failed_pc=0x0c0b9b96u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b9b98;
P_0c0b9b98: /* original 9552, guest PC 0x0c0b9b98 */
if(!s->budget--) { s->failed_pc=0x0c0b9b98u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b9c40u,2);
goto P_0c0b9b9a;
P_0c0b9b9a: /* original 35dc, guest PC 0x0c0b9b9a */
if(!s->budget--) { s->failed_pc=0x0c0b9b9au; return 0; }
r[5]+=r[13];
goto P_0c0b9b9c;
P_0c0b9b9c: /* original 2f52, guest PC 0x0c0b9b9c */
if(!s->budget--) { s->failed_pc=0x0c0b9b9cu; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0b9b9e;
P_0c0b9b9e: /* original 9450, guest PC 0x0c0b9b9e */
if(!s->budget--) { s->failed_pc=0x0c0b9b9eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b9c42u,2);
goto P_0c0b9ba0;
P_0c0b9ba0: /* original 4e0b, guest PC 0x0c0b9ba0 */
if(!s->budget--) { s->failed_pc=0x0c0b9ba0u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b9ba4u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b9ba4u) { target=s->pc; goto dispatch; }
goto P_0c0b9ba4;
P_0c0b9ba2: /* original 6552, guest PC 0x0c0b9ba2 */
if(!s->budget--) { s->failed_pc=0x0c0b9ba2u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b9ba4;
P_0c0b9ba4: /* original 944e, guest PC 0x0c0b9ba4 */
if(!s->budget--) { s->failed_pc=0x0c0b9ba4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b9c44u,2);
goto P_0c0b9ba6;
P_0c0b9ba6: /* original 65f2, guest PC 0x0c0b9ba6 */
if(!s->budget--) { s->failed_pc=0x0c0b9ba6u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0b9ba8;
P_0c0b9ba8: /* original 4e0b, guest PC 0x0c0b9ba8 */
if(!s->budget--) { s->failed_pc=0x0c0b9ba8u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b9bacu;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b9bacu) { target=s->pc; goto dispatch; }
goto P_0c0b9bac;
P_0c0b9baa: /* original 6552, guest PC 0x0c0b9baa */
if(!s->budget--) { s->failed_pc=0x0c0b9baau; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b9bac;
P_0c0b9bac: /* original 954b, guest PC 0x0c0b9bac */
if(!s->budget--) { s->failed_pc=0x0c0b9bacu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b9c46u,2);
goto P_0c0b9bae;
P_0c0b9bae: /* original 35dc, guest PC 0x0c0b9bae */
if(!s->budget--) { s->failed_pc=0x0c0b9baeu; return 0; }
r[5]+=r[13];
goto P_0c0b9bb0;
P_0c0b9bb0: /* original 2f52, guest PC 0x0c0b9bb0 */
if(!s->budget--) { s->failed_pc=0x0c0b9bb0u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0b9bb2;
P_0c0b9bb2: /* original 9449, guest PC 0x0c0b9bb2 */
if(!s->budget--) { s->failed_pc=0x0c0b9bb2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b9c48u,2);
goto P_0c0b9bb4;
P_0c0b9bb4: /* original 4e0b, guest PC 0x0c0b9bb4 */
if(!s->budget--) { s->failed_pc=0x0c0b9bb4u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b9bb8u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b9bb8u) { target=s->pc; goto dispatch; }
goto P_0c0b9bb8;
P_0c0b9bb6: /* original 6552, guest PC 0x0c0b9bb6 */
if(!s->budget--) { s->failed_pc=0x0c0b9bb6u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b9bb8;
P_0c0b9bb8: /* original 9447, guest PC 0x0c0b9bb8 */
if(!s->budget--) { s->failed_pc=0x0c0b9bb8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b9c4au,2);
goto P_0c0b9bba;
P_0c0b9bba: /* original 65f2, guest PC 0x0c0b9bba */
if(!s->budget--) { s->failed_pc=0x0c0b9bbau; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0b9bbc;
P_0c0b9bbc: /* original 4e0b, guest PC 0x0c0b9bbc */
if(!s->budget--) { s->failed_pc=0x0c0b9bbcu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b9bc0u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b9bc0u) { target=s->pc; goto dispatch; }
goto P_0c0b9bc0;
P_0c0b9bbe: /* original 6552, guest PC 0x0c0b9bbe */
if(!s->budget--) { s->failed_pc=0x0c0b9bbeu; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b9bc0;
P_0c0b9bc0: /* original 9445, guest PC 0x0c0b9bc0 */
if(!s->budget--) { s->failed_pc=0x0c0b9bc0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b9c4eu,2);
goto P_0c0b9bc2;
P_0c0b9bc2: /* original 9043, guest PC 0x0c0b9bc2 */
if(!s->budget--) { s->failed_pc=0x0c0b9bc2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b9c4cu,2);
goto P_0c0b9bc4;
P_0c0b9bc4: /* original 4e0b, guest PC 0x0c0b9bc4 */
if(!s->budget--) { s->failed_pc=0x0c0b9bc4u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b9bc8u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b9bc8u) { target=s->pc; goto dispatch; }
goto P_0c0b9bc8;
P_0c0b9bc6: /* original 05de, guest PC 0x0c0b9bc6 */
if(!s->budget--) { s->failed_pc=0x0c0b9bc6u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b9bc8;
P_0c0b9bc8: /* original 9443, guest PC 0x0c0b9bc8 */
if(!s->budget--) { s->failed_pc=0x0c0b9bc8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b9c52u,2);
goto P_0c0b9bca;
P_0c0b9bca: /* original 9041, guest PC 0x0c0b9bca */
if(!s->budget--) { s->failed_pc=0x0c0b9bcau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b9c50u,2);
goto P_0c0b9bcc;
P_0c0b9bcc: /* original 4e0b, guest PC 0x0c0b9bcc */
if(!s->budget--) { s->failed_pc=0x0c0b9bccu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b9bd0u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b9bd0u) { target=s->pc; goto dispatch; }
goto P_0c0b9bd0;
P_0c0b9bce: /* original 05de, guest PC 0x0c0b9bce */
if(!s->budget--) { s->failed_pc=0x0c0b9bceu; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b9bd0;
P_0c0b9bd0: /* original 9441, guest PC 0x0c0b9bd0 */
if(!s->budget--) { s->failed_pc=0x0c0b9bd0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b9c56u,2);
goto P_0c0b9bd2;
P_0c0b9bd2: /* original 903f, guest PC 0x0c0b9bd2 */
if(!s->budget--) { s->failed_pc=0x0c0b9bd2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b9c54u,2);
goto P_0c0b9bd4;
P_0c0b9bd4: /* original 4e0b, guest PC 0x0c0b9bd4 */
if(!s->budget--) { s->failed_pc=0x0c0b9bd4u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b9bd8u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b9bd8u) { target=s->pc; goto dispatch; }
goto P_0c0b9bd8;
P_0c0b9bd6: /* original 05de, guest PC 0x0c0b9bd6 */
if(!s->budget--) { s->failed_pc=0x0c0b9bd6u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b9bd8;
P_0c0b9bd8: /* original 943f, guest PC 0x0c0b9bd8 */
if(!s->budget--) { s->failed_pc=0x0c0b9bd8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b9c5au,2);
goto P_0c0b9bda;
P_0c0b9bda: /* original 903d, guest PC 0x0c0b9bda */
if(!s->budget--) { s->failed_pc=0x0c0b9bdau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b9c58u,2);
goto P_0c0b9bdc;
P_0c0b9bdc: /* original 4e0b, guest PC 0x0c0b9bdc */
if(!s->budget--) { s->failed_pc=0x0c0b9bdcu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b9be0u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b9be0u) { target=s->pc; goto dispatch; }
goto P_0c0b9be0;
P_0c0b9bde: /* original 05de, guest PC 0x0c0b9bde */
if(!s->budget--) { s->failed_pc=0x0c0b9bdeu; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b9be0;
P_0c0b9be0: /* original 903c, guest PC 0x0c0b9be0 */
if(!s->budget--) { s->failed_pc=0x0c0b9be0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b9c5cu,2);
goto P_0c0b9be2;
P_0c0b9be2: /* original a03c, guest PC 0x0c0b9be2 */
if(!s->budget--) { s->failed_pc=0x0c0b9be2u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b9c5e;
P_0c0b9be4: /* original 05de, guest PC 0x0c0b9be4 */
if(!s->budget--) { s->failed_pc=0x0c0b9be4u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
if(!vf3_matrix_family(0x0c0b9be6u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0b9be6u; return 0; } return 1;
P_0c0b9c5e: /* original 942a, guest PC 0x0c0b9c5e */
if(!s->budget--) { s->failed_pc=0x0c0b9c5eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b9cb6u,2);
goto P_0c0b9c60;
P_0c0b9c60: /* original 4e0b, guest PC 0x0c0b9c60 */
if(!s->budget--) { s->failed_pc=0x0c0b9c60u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b9c64u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b9c64u) { target=s->pc; goto dispatch; }
goto P_0c0b9c64;
P_0c0b9c62: /* original 0009, guest PC 0x0c0b9c62 */
if(!s->budget--) { s->failed_pc=0x0c0b9c62u; return 0; }
goto P_0c0b9c64;
P_0c0b9c64: /* original 9429, guest PC 0x0c0b9c64 */
if(!s->budget--) { s->failed_pc=0x0c0b9c64u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b9cbau,2);
goto P_0c0b9c66;
P_0c0b9c66: /* original 9027, guest PC 0x0c0b9c66 */
if(!s->budget--) { s->failed_pc=0x0c0b9c66u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b9cb8u,2);
goto P_0c0b9c68;
P_0c0b9c68: /* original 4e0b, guest PC 0x0c0b9c68 */
if(!s->budget--) { s->failed_pc=0x0c0b9c68u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b9c6cu;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b9c6cu) { target=s->pc; goto dispatch; }
goto P_0c0b9c6c;
P_0c0b9c6a: /* original 05de, guest PC 0x0c0b9c6a */
if(!s->budget--) { s->failed_pc=0x0c0b9c6au; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b9c6c;
P_0c0b9c6c: /* original 9427, guest PC 0x0c0b9c6c */
if(!s->budget--) { s->failed_pc=0x0c0b9c6cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b9cbeu,2);
goto P_0c0b9c6e;
P_0c0b9c6e: /* original 9025, guest PC 0x0c0b9c6e */
if(!s->budget--) { s->failed_pc=0x0c0b9c6eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b9cbcu,2);
goto P_0c0b9c70;
P_0c0b9c70: /* original 4e0b, guest PC 0x0c0b9c70 */
if(!s->budget--) { s->failed_pc=0x0c0b9c70u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b9c74u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b9c74u) { target=s->pc; goto dispatch; }
goto P_0c0b9c74;
P_0c0b9c72: /* original 05de, guest PC 0x0c0b9c72 */
if(!s->budget--) { s->failed_pc=0x0c0b9c72u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b9c74;
P_0c0b9c74: /* original 9425, guest PC 0x0c0b9c74 */
if(!s->budget--) { s->failed_pc=0x0c0b9c74u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b9cc2u,2);
goto P_0c0b9c76;
P_0c0b9c76: /* original 9023, guest PC 0x0c0b9c76 */
if(!s->budget--) { s->failed_pc=0x0c0b9c76u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b9cc0u,2);
goto P_0c0b9c78;
P_0c0b9c78: /* original 4e0b, guest PC 0x0c0b9c78 */
if(!s->budget--) { s->failed_pc=0x0c0b9c78u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b9c7cu;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b9c7cu) { target=s->pc; goto dispatch; }
goto P_0c0b9c7c;
P_0c0b9c7a: /* original 05de, guest PC 0x0c0b9c7a */
if(!s->budget--) { s->failed_pc=0x0c0b9c7au; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b9c7c;
P_0c0b9c7c: /* original 9423, guest PC 0x0c0b9c7c */
if(!s->budget--) { s->failed_pc=0x0c0b9c7cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b9cc6u,2);
goto P_0c0b9c7e;
P_0c0b9c7e: /* original 9021, guest PC 0x0c0b9c7e */
if(!s->budget--) { s->failed_pc=0x0c0b9c7eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b9cc4u,2);
goto P_0c0b9c80;
P_0c0b9c80: /* original 4e0b, guest PC 0x0c0b9c80 */
if(!s->budget--) { s->failed_pc=0x0c0b9c80u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b9c84u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b9c84u) { target=s->pc; goto dispatch; }
goto P_0c0b9c84;
P_0c0b9c82: /* original 05de, guest PC 0x0c0b9c82 */
if(!s->budget--) { s->failed_pc=0x0c0b9c82u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b9c84;
P_0c0b9c84: /* original 9421, guest PC 0x0c0b9c84 */
if(!s->budget--) { s->failed_pc=0x0c0b9c84u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b9ccau,2);
goto P_0c0b9c86;
P_0c0b9c86: /* original 901f, guest PC 0x0c0b9c86 */
if(!s->budget--) { s->failed_pc=0x0c0b9c86u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b9cc8u,2);
goto P_0c0b9c88;
P_0c0b9c88: /* original 4e0b, guest PC 0x0c0b9c88 */
if(!s->budget--) { s->failed_pc=0x0c0b9c88u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b9c8cu;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b9c8cu) { target=s->pc; goto dispatch; }
goto P_0c0b9c8c;
P_0c0b9c8a: /* original 05de, guest PC 0x0c0b9c8a */
if(!s->budget--) { s->failed_pc=0x0c0b9c8au; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b9c8c;
P_0c0b9c8c: /* original 941f, guest PC 0x0c0b9c8c */
if(!s->budget--) { s->failed_pc=0x0c0b9c8cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b9cceu,2);
goto P_0c0b9c8e;
P_0c0b9c8e: /* original 901d, guest PC 0x0c0b9c8e */
if(!s->budget--) { s->failed_pc=0x0c0b9c8eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b9cccu,2);
goto P_0c0b9c90;
P_0c0b9c90: /* original 4e0b, guest PC 0x0c0b9c90 */
if(!s->budget--) { s->failed_pc=0x0c0b9c90u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b9c94u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b9c94u) { target=s->pc; goto dispatch; }
goto P_0c0b9c94;
P_0c0b9c92: /* original 05de, guest PC 0x0c0b9c92 */
if(!s->budget--) { s->failed_pc=0x0c0b9c92u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b9c94;
P_0c0b9c94: /* original 941d, guest PC 0x0c0b9c94 */
if(!s->budget--) { s->failed_pc=0x0c0b9c94u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b9cd2u,2);
goto P_0c0b9c96;
P_0c0b9c96: /* original 901b, guest PC 0x0c0b9c96 */
if(!s->budget--) { s->failed_pc=0x0c0b9c96u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b9cd0u,2);
goto P_0c0b9c98;
P_0c0b9c98: /* original 4e0b, guest PC 0x0c0b9c98 */
if(!s->budget--) { s->failed_pc=0x0c0b9c98u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b9c9cu;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b9c9cu) { target=s->pc; goto dispatch; }
goto P_0c0b9c9c;
P_0c0b9c9a: /* original 05de, guest PC 0x0c0b9c9a */
if(!s->budget--) { s->failed_pc=0x0c0b9c9au; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b9c9c;
P_0c0b9c9c: /* original 941b, guest PC 0x0c0b9c9c */
if(!s->budget--) { s->failed_pc=0x0c0b9c9cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b9cd6u,2);
goto P_0c0b9c9e;
P_0c0b9c9e: /* original 9019, guest PC 0x0c0b9c9e */
if(!s->budget--) { s->failed_pc=0x0c0b9c9eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b9cd4u,2);
goto P_0c0b9ca0;
P_0c0b9ca0: /* original 4e0b, guest PC 0x0c0b9ca0 */
if(!s->budget--) { s->failed_pc=0x0c0b9ca0u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b9ca4u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b9ca4u) { target=s->pc; goto dispatch; }
goto P_0c0b9ca4;
P_0c0b9ca2: /* original 05de, guest PC 0x0c0b9ca2 */
if(!s->budget--) { s->failed_pc=0x0c0b9ca2u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b9ca4;
P_0c0b9ca4: /* original 7f08, guest PC 0x0c0b9ca4 */
if(!s->budget--) { s->failed_pc=0x0c0b9ca4u; return 0; }
r[15]+=0x00000008u;
goto P_0c0b9ca6;
P_0c0b9ca6: /* original 4f26, guest PC 0x0c0b9ca6 */
if(!s->budget--) { s->failed_pc=0x0c0b9ca6u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0b9ca8;
P_0c0b9ca8: /* original 69f6, guest PC 0x0c0b9ca8 */
if(!s->budget--) { s->failed_pc=0x0c0b9ca8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0b9caa;
P_0c0b9caa: /* original 6af6, guest PC 0x0c0b9caa */
if(!s->budget--) { s->failed_pc=0x0c0b9caau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0b9cac;
P_0c0b9cac: /* original 6bf6, guest PC 0x0c0b9cac */
if(!s->budget--) { s->failed_pc=0x0c0b9cacu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0b9cae;
P_0c0b9cae: /* original 6cf6, guest PC 0x0c0b9cae */
if(!s->budget--) { s->failed_pc=0x0c0b9caeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0b9cb0;
P_0c0b9cb0: /* original 6df6, guest PC 0x0c0b9cb0 */
if(!s->budget--) { s->failed_pc=0x0c0b9cb0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0b9cb2;
P_0c0b9cb2: /* original 000b, guest PC 0x0c0b9cb2 */
if(!s->budget--) { s->failed_pc=0x0c0b9cb2u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0b9cb4: /* original 6ef6, guest PC 0x0c0b9cb4 */
if(!s->budget--) { s->failed_pc=0x0c0b9cb4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0b9cb6u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0b9cb6u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
