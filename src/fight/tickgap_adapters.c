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
int vf3_tickgap_adapter(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c06f3bau: goto P_0c06f3ba;
case 0x0c06f3bcu: goto P_0c06f3bc;
case 0x0c06f3beu: goto P_0c06f3be;
case 0x0c06f3c0u: goto P_0c06f3c0;
case 0x0c06f3c2u: goto P_0c06f3c2;
case 0x0c06f3c4u: goto P_0c06f3c4;
case 0x0c06f3c6u: goto P_0c06f3c6;
case 0x0c06f3c8u: goto P_0c06f3c8;
case 0x0c06f3cau: goto P_0c06f3ca;
case 0x0c06f3ccu: goto P_0c06f3cc;
case 0x0c06f3ceu: goto P_0c06f3ce;
case 0x0c06f3d0u: goto P_0c06f3d0;
case 0x0c06f3d2u: goto P_0c06f3d2;
case 0x0c06f3d4u: goto P_0c06f3d4;
case 0x0c06f3d6u: goto P_0c06f3d6;
case 0x0c06f3d8u: goto P_0c06f3d8;
case 0x0c06f3dau: goto P_0c06f3da;
case 0x0c06f3dcu: goto P_0c06f3dc;
case 0x0c06f3deu: goto P_0c06f3de;
case 0x0c06f3e0u: goto P_0c06f3e0;
case 0x0c06f3e2u: goto P_0c06f3e2;
case 0x0c06f3e4u: goto P_0c06f3e4;
case 0x0c06f3e6u: goto P_0c06f3e6;
case 0x0c06f3e8u: goto P_0c06f3e8;
case 0x0c06f3eau: goto P_0c06f3ea;
case 0x0c06f3ecu: goto P_0c06f3ec;
case 0x0c06f3eeu: goto P_0c06f3ee;
case 0x0c06f3f0u: goto P_0c06f3f0;
case 0x0c06f3f2u: goto P_0c06f3f2;
case 0x0c06f3f4u: goto P_0c06f3f4;
case 0x0c06f3f6u: goto P_0c06f3f6;
case 0x0c06f3f8u: goto P_0c06f3f8;
case 0x0c06f3fau: goto P_0c06f3fa;
case 0x0c06f3fcu: goto P_0c06f3fc;
case 0x0c06f3feu: goto P_0c06f3fe;
case 0x0c06f400u: goto P_0c06f400;
case 0x0c06f402u: goto P_0c06f402;
case 0x0c06f404u: goto P_0c06f404;
case 0x0c06f406u: goto P_0c06f406;
case 0x0c06f408u: goto P_0c06f408;
case 0x0c06f40au: goto P_0c06f40a;
case 0x0c06f40cu: goto P_0c06f40c;
case 0x0c06f40eu: goto P_0c06f40e;
case 0x0c06f410u: goto P_0c06f410;
case 0x0c06f412u: goto P_0c06f412;
case 0x0c06f414u: goto P_0c06f414;
case 0x0c06f416u: goto P_0c06f416;
case 0x0c06f418u: goto P_0c06f418;
case 0x0c06f41au: goto P_0c06f41a;
case 0x0c06f41cu: goto P_0c06f41c;
case 0x0c06f41eu: goto P_0c06f41e;
case 0x0c06f420u: goto P_0c06f420;
case 0x0c06f422u: goto P_0c06f422;
case 0x0c06f424u: goto P_0c06f424;
case 0x0c06f426u: goto P_0c06f426;
case 0x0c06f428u: goto P_0c06f428;
case 0x0c06f42au: goto P_0c06f42a;
case 0x0c06f42cu: goto P_0c06f42c;
case 0x0c06f42eu: goto P_0c06f42e;
case 0x0c06f430u: goto P_0c06f430;
case 0x0c06f432u: goto P_0c06f432;
case 0x0c06f434u: goto P_0c06f434;
case 0x0c06f436u: goto P_0c06f436;
case 0x0c06f438u: goto P_0c06f438;
case 0x0c06f43au: goto P_0c06f43a;
case 0x0c06f43cu: goto P_0c06f43c;
case 0x0c06f43eu: goto P_0c06f43e;
case 0x0c06f440u: goto P_0c06f440;
case 0x0c06f442u: goto P_0c06f442;
case 0x0c06f444u: goto P_0c06f444;
case 0x0c06f446u: goto P_0c06f446;
case 0x0c06f448u: goto P_0c06f448;
case 0x0c06f44au: goto P_0c06f44a;
case 0x0c06f44cu: goto P_0c06f44c;
case 0x0c06f44eu: goto P_0c06f44e;
case 0x0c072b40u: goto P_0c072b40;
case 0x0c072b42u: goto P_0c072b42;
case 0x0c072b44u: goto P_0c072b44;
case 0x0c072b46u: goto P_0c072b46;
case 0x0c072b48u: goto P_0c072b48;
case 0x0c072b4au: goto P_0c072b4a;
case 0x0c072b4cu: goto P_0c072b4c;
case 0x0c072b4eu: goto P_0c072b4e;
case 0x0c072b50u: goto P_0c072b50;
case 0x0c072b52u: goto P_0c072b52;
case 0x0c072b54u: goto P_0c072b54;
case 0x0c072b56u: goto P_0c072b56;
case 0x0c072b58u: goto P_0c072b58;
case 0x0c072b5au: goto P_0c072b5a;
case 0x0c072b5cu: goto P_0c072b5c;
case 0x0c072b5eu: goto P_0c072b5e;
case 0x0c072b60u: goto P_0c072b60;
case 0x0c072b62u: goto P_0c072b62;
case 0x0c072b64u: goto P_0c072b64;
case 0x0c072b66u: goto P_0c072b66;
case 0x0c072b68u: goto P_0c072b68;
case 0x0c072b6au: goto P_0c072b6a;
case 0x0c072b6cu: goto P_0c072b6c;
case 0x0c072b6eu: goto P_0c072b6e;
case 0x0c072b70u: goto P_0c072b70;
case 0x0c072b72u: goto P_0c072b72;
case 0x0c072b74u: goto P_0c072b74;
case 0x0c072b76u: goto P_0c072b76;
case 0x0c072b78u: goto P_0c072b78;
case 0x0c072b7au: goto P_0c072b7a;
case 0x0c072b7cu: goto P_0c072b7c;
case 0x0c072b7eu: goto P_0c072b7e;
case 0x0c072b80u: goto P_0c072b80;
case 0x0c072b82u: goto P_0c072b82;
case 0x0c072b84u: goto P_0c072b84;
case 0x0c072b86u: goto P_0c072b86;
case 0x0c072b88u: goto P_0c072b88;
case 0x0c072b8au: goto P_0c072b8a;
case 0x0c072b8cu: goto P_0c072b8c;
case 0x0c072b8eu: goto P_0c072b8e;
case 0x0c072b90u: goto P_0c072b90;
case 0x0c072b92u: goto P_0c072b92;
case 0x0c072b94u: goto P_0c072b94;
case 0x0c072b96u: goto P_0c072b96;
case 0x0c072b98u: goto P_0c072b98;
case 0x0c072b9au: goto P_0c072b9a;
case 0x0c072b9cu: goto P_0c072b9c;
case 0x0c072b9eu: goto P_0c072b9e;
case 0x0c072ba0u: goto P_0c072ba0;
case 0x0c072ba2u: goto P_0c072ba2;
case 0x0c072ba4u: goto P_0c072ba4;
case 0x0c072ba6u: goto P_0c072ba6;
case 0x0c072ba8u: goto P_0c072ba8;
case 0x0c072baau: goto P_0c072baa;
case 0x0c072bacu: goto P_0c072bac;
case 0x0c072baeu: goto P_0c072bae;
case 0x0c072bb0u: goto P_0c072bb0;
case 0x0c072bb2u: goto P_0c072bb2;
case 0x0c072bb4u: goto P_0c072bb4;
case 0x0c072bb6u: goto P_0c072bb6;
case 0x0c072bb8u: goto P_0c072bb8;
case 0x0c072bbau: goto P_0c072bba;
case 0x0c072bd0u: goto P_0c072bd0;
case 0x0c072bd2u: goto P_0c072bd2;
case 0x0c072bd4u: goto P_0c072bd4;
case 0x0c072bd6u: goto P_0c072bd6;
case 0x0c072bd8u: goto P_0c072bd8;
case 0x0c072bdau: goto P_0c072bda;
case 0x0c072bdcu: goto P_0c072bdc;
case 0x0c072bdeu: goto P_0c072bde;
case 0x0c072be0u: goto P_0c072be0;
case 0x0c072be2u: goto P_0c072be2;
case 0x0c072be4u: goto P_0c072be4;
case 0x0c072be6u: goto P_0c072be6;
case 0x0c072be8u: goto P_0c072be8;
case 0x0c072beau: goto P_0c072bea;
case 0x0c072becu: goto P_0c072bec;
case 0x0c072beeu: goto P_0c072bee;
case 0x0c072bf0u: goto P_0c072bf0;
case 0x0c072bf2u: goto P_0c072bf2;
case 0x0c072bf4u: goto P_0c072bf4;
case 0x0c072bf6u: goto P_0c072bf6;
case 0x0c072bf8u: goto P_0c072bf8;
case 0x0c072bfau: goto P_0c072bfa;
case 0x0c072bfcu: goto P_0c072bfc;
case 0x0c072bfeu: goto P_0c072bfe;
case 0x0c072c00u: goto P_0c072c00;
case 0x0c072c02u: goto P_0c072c02;
case 0x0c072c04u: goto P_0c072c04;
case 0x0c072c06u: goto P_0c072c06;
case 0x0c072c08u: goto P_0c072c08;
case 0x0c072c0au: goto P_0c072c0a;
case 0x0c072c0cu: goto P_0c072c0c;
case 0x0c072c0eu: goto P_0c072c0e;
case 0x0c072c10u: goto P_0c072c10;
case 0x0c072c12u: goto P_0c072c12;
case 0x0c072c14u: goto P_0c072c14;
case 0x0c072c16u: goto P_0c072c16;
case 0x0c072c18u: goto P_0c072c18;
case 0x0c072c1au: goto P_0c072c1a;
case 0x0c072c1cu: goto P_0c072c1c;
case 0x0c072c1eu: goto P_0c072c1e;
case 0x0c072c20u: goto P_0c072c20;
case 0x0c072c22u: goto P_0c072c22;
case 0x0c072c24u: goto P_0c072c24;
case 0x0c072c26u: goto P_0c072c26;
case 0x0c072c28u: goto P_0c072c28;
case 0x0c072c2au: goto P_0c072c2a;
case 0x0c072c2cu: goto P_0c072c2c;
case 0x0c072c2eu: goto P_0c072c2e;
case 0x0c072c30u: goto P_0c072c30;
case 0x0c072c32u: goto P_0c072c32;
case 0x0c072c34u: goto P_0c072c34;
case 0x0c072c36u: goto P_0c072c36;
case 0x0c072c38u: goto P_0c072c38;
case 0x0c072c3au: goto P_0c072c3a;
case 0x0c072c3cu: goto P_0c072c3c;
case 0x0c072c3eu: goto P_0c072c3e;
case 0x0c072c40u: goto P_0c072c40;
case 0x0c072c42u: goto P_0c072c42;
case 0x0c072c44u: goto P_0c072c44;
case 0x0c072c46u: goto P_0c072c46;
case 0x0c072c48u: goto P_0c072c48;
case 0x0c072c4au: goto P_0c072c4a;
case 0x0c072c4cu: goto P_0c072c4c;
case 0x0c072c4eu: goto P_0c072c4e;
case 0x0c072c6cu: goto P_0c072c6c;
case 0x0c072c6eu: goto P_0c072c6e;
case 0x0c072c70u: goto P_0c072c70;
case 0x0c072c72u: goto P_0c072c72;
case 0x0c072c74u: goto P_0c072c74;
case 0x0c072c76u: goto P_0c072c76;
case 0x0c072c78u: goto P_0c072c78;
case 0x0c072c7au: goto P_0c072c7a;
case 0x0c072c7cu: goto P_0c072c7c;
case 0x0c072c7eu: goto P_0c072c7e;
case 0x0c072c80u: goto P_0c072c80;
case 0x0c072c82u: goto P_0c072c82;
case 0x0c072c84u: goto P_0c072c84;
case 0x0c072c86u: goto P_0c072c86;
case 0x0c072c88u: goto P_0c072c88;
case 0x0c072c8au: goto P_0c072c8a;
case 0x0c072c8cu: goto P_0c072c8c;
case 0x0c072c8eu: goto P_0c072c8e;
case 0x0c072c90u: goto P_0c072c90;
case 0x0c072c92u: goto P_0c072c92;
case 0x0c072c94u: goto P_0c072c94;
case 0x0c072c96u: goto P_0c072c96;
case 0x0c072c98u: goto P_0c072c98;
case 0x0c072c9au: goto P_0c072c9a;
case 0x0c072c9cu: goto P_0c072c9c;
case 0x0c072c9eu: goto P_0c072c9e;
case 0x0c072ca0u: goto P_0c072ca0;
case 0x0c072ca2u: goto P_0c072ca2;
case 0x0c072ca4u: goto P_0c072ca4;
case 0x0c072ca6u: goto P_0c072ca6;
case 0x0c072ca8u: goto P_0c072ca8;
case 0x0c072caau: goto P_0c072caa;
case 0x0c072cacu: goto P_0c072cac;
case 0x0c072caeu: goto P_0c072cae;
case 0x0c072cb0u: goto P_0c072cb0;
case 0x0c072cb2u: goto P_0c072cb2;
case 0x0c072cb4u: goto P_0c072cb4;
case 0x0c072cb6u: goto P_0c072cb6;
case 0x0c072cb8u: goto P_0c072cb8;
case 0x0c072cbau: goto P_0c072cba;
case 0x0c072cbcu: goto P_0c072cbc;
case 0x0c072cbeu: goto P_0c072cbe;
case 0x0c072cc0u: goto P_0c072cc0;
case 0x0c072cc2u: goto P_0c072cc2;
case 0x0c072cc4u: goto P_0c072cc4;
case 0x0c072cc6u: goto P_0c072cc6;
case 0x0c072cc8u: goto P_0c072cc8;
case 0x0c072ccau: goto P_0c072cca;
case 0x0c072cccu: goto P_0c072ccc;
case 0x0c072cceu: goto P_0c072cce;
case 0x0c072cd0u: goto P_0c072cd0;
case 0x0c072cd2u: goto P_0c072cd2;
case 0x0c072cd4u: goto P_0c072cd4;
case 0x0c072cd6u: goto P_0c072cd6;
case 0x0c072cd8u: goto P_0c072cd8;
case 0x0c072cdau: goto P_0c072cda;
case 0x0c072cdcu: goto P_0c072cdc;
case 0x0c072cdeu: goto P_0c072cde;
case 0x0c072ce0u: goto P_0c072ce0;
case 0x0c072ce2u: goto P_0c072ce2;
case 0x0c072ce4u: goto P_0c072ce4;
case 0x0c072ce6u: goto P_0c072ce6;
case 0x0c072ce8u: goto P_0c072ce8;
case 0x0c072ceau: goto P_0c072cea;
case 0x0c072cecu: goto P_0c072cec;
case 0x0c072ceeu: goto P_0c072cee;
case 0x0c072cf0u: goto P_0c072cf0;
case 0x0c072cf2u: goto P_0c072cf2;
case 0x0c072cf4u: goto P_0c072cf4;
case 0x0c072cf6u: goto P_0c072cf6;
case 0x0c072cf8u: goto P_0c072cf8;
case 0x0c072cfau: goto P_0c072cfa;
case 0x0c0738eau: goto P_0c0738ea;
case 0x0c0738ecu: goto P_0c0738ec;
case 0x0c0738eeu: goto P_0c0738ee;
case 0x0c0738f0u: goto P_0c0738f0;
case 0x0c0738f2u: goto P_0c0738f2;
case 0x0c0738f4u: goto P_0c0738f4;
case 0x0c0738f6u: goto P_0c0738f6;
case 0x0c0738f8u: goto P_0c0738f8;
case 0x0c0738fau: goto P_0c0738fa;
case 0x0c0738fcu: goto P_0c0738fc;
case 0x0c0738feu: goto P_0c0738fe;
case 0x0c073900u: goto P_0c073900;
case 0x0c073902u: goto P_0c073902;
case 0x0c073904u: goto P_0c073904;
case 0x0c073906u: goto P_0c073906;
case 0x0c073908u: goto P_0c073908;
case 0x0c07390au: goto P_0c07390a;
case 0x0c07390cu: goto P_0c07390c;
case 0x0c07390eu: goto P_0c07390e;
case 0x0c073910u: goto P_0c073910;
case 0x0c073912u: goto P_0c073912;
case 0x0c073914u: goto P_0c073914;
case 0x0c073916u: goto P_0c073916;
case 0x0c073918u: goto P_0c073918;
case 0x0c07391au: goto P_0c07391a;
case 0x0c07391cu: goto P_0c07391c;
case 0x0c07391eu: goto P_0c07391e;
case 0x0c073920u: goto P_0c073920;
case 0x0c073922u: goto P_0c073922;
case 0x0c073924u: goto P_0c073924;
case 0x0c073926u: goto P_0c073926;
case 0x0c073928u: goto P_0c073928;
case 0x0c07392au: goto P_0c07392a;
case 0x0c07392cu: goto P_0c07392c;
case 0x0c07392eu: goto P_0c07392e;
case 0x0c073930u: goto P_0c073930;
case 0x0c073932u: goto P_0c073932;
case 0x0c073934u: goto P_0c073934;
case 0x0c073936u: goto P_0c073936;
case 0x0c073938u: goto P_0c073938;
case 0x0c07393au: goto P_0c07393a;
case 0x0c07393cu: goto P_0c07393c;
case 0x0c07393eu: goto P_0c07393e;
case 0x0c073940u: goto P_0c073940;
case 0x0c073942u: goto P_0c073942;
case 0x0c073944u: goto P_0c073944;
case 0x0c073946u: goto P_0c073946;
case 0x0c073948u: goto P_0c073948;
case 0x0c07394au: goto P_0c07394a;
case 0x0c07394cu: goto P_0c07394c;
case 0x0c07394eu: goto P_0c07394e;
case 0x0c073984u: goto P_0c073984;
case 0x0c073986u: goto P_0c073986;
case 0x0c073988u: goto P_0c073988;
case 0x0c07398au: goto P_0c07398a;
case 0x0c07398cu: goto P_0c07398c;
case 0x0c07398eu: goto P_0c07398e;
case 0x0c073990u: goto P_0c073990;
case 0x0c073992u: goto P_0c073992;
case 0x0c073994u: goto P_0c073994;
case 0x0c073996u: goto P_0c073996;
case 0x0c073998u: goto P_0c073998;
case 0x0c07399au: goto P_0c07399a;
case 0x0c07399cu: goto P_0c07399c;
case 0x0c07399eu: goto P_0c07399e;
case 0x0c0739a0u: goto P_0c0739a0;
case 0x0c0739a2u: goto P_0c0739a2;
case 0x0c0739a4u: goto P_0c0739a4;
case 0x0c0739a6u: goto P_0c0739a6;
case 0x0c0739a8u: goto P_0c0739a8;
case 0x0c0739aau: goto P_0c0739aa;
case 0x0c0739acu: goto P_0c0739ac;
case 0x0c0739aeu: goto P_0c0739ae;
case 0x0c0739b0u: goto P_0c0739b0;
case 0x0c0739b2u: goto P_0c0739b2;
case 0x0c0739b4u: goto P_0c0739b4;
case 0x0c0739b6u: goto P_0c0739b6;
case 0x0c0739b8u: goto P_0c0739b8;
case 0x0c0739bau: goto P_0c0739ba;
case 0x0c0739bcu: goto P_0c0739bc;
case 0x0c0739beu: goto P_0c0739be;
case 0x0c0739c0u: goto P_0c0739c0;
case 0x0c0739c2u: goto P_0c0739c2;
case 0x0c0739c4u: goto P_0c0739c4;
case 0x0c0739c6u: goto P_0c0739c6;
case 0x0c0739c8u: goto P_0c0739c8;
case 0x0c0739cau: goto P_0c0739ca;
case 0x0c0739ccu: goto P_0c0739cc;
case 0x0c0739ceu: goto P_0c0739ce;
case 0x0c0739d0u: goto P_0c0739d0;
case 0x0c0739d2u: goto P_0c0739d2;
case 0x0c0739d4u: goto P_0c0739d4;
case 0x0c0739d6u: goto P_0c0739d6;
case 0x0c0739d8u: goto P_0c0739d8;
case 0x0c0739dau: goto P_0c0739da;
case 0x0c0739dcu: goto P_0c0739dc;
case 0x0c0739deu: goto P_0c0739de;
case 0x0c0739e0u: goto P_0c0739e0;
case 0x0c0739e2u: goto P_0c0739e2;
case 0x0c0739e4u: goto P_0c0739e4;
case 0x0c0739e6u: goto P_0c0739e6;
case 0x0c0739e8u: goto P_0c0739e8;
case 0x0c0739eau: goto P_0c0739ea;
case 0x0c0739ecu: goto P_0c0739ec;
case 0x0c0739eeu: goto P_0c0739ee;
case 0x0c0739f0u: goto P_0c0739f0;
case 0x0c0739f2u: goto P_0c0739f2;
case 0x0c0739f4u: goto P_0c0739f4;
case 0x0c0739f6u: goto P_0c0739f6;
case 0x0c0739f8u: goto P_0c0739f8;
case 0x0c0739fau: goto P_0c0739fa;
case 0x0c0739fcu: goto P_0c0739fc;
case 0x0c0739feu: goto P_0c0739fe;
case 0x0c073a00u: goto P_0c073a00;
case 0x0c073a02u: goto P_0c073a02;
case 0x0c073a04u: goto P_0c073a04;
case 0x0c073a06u: goto P_0c073a06;
case 0x0c073a08u: goto P_0c073a08;
case 0x0c073a0au: goto P_0c073a0a;
case 0x0c073a0cu: goto P_0c073a0c;
case 0x0c073a0eu: goto P_0c073a0e;
case 0x0c073a10u: goto P_0c073a10;
case 0x0c073a12u: goto P_0c073a12;
case 0x0c073a14u: goto P_0c073a14;
case 0x0c073a16u: goto P_0c073a16;
case 0x0c073a18u: goto P_0c073a18;
case 0x0c073a1au: goto P_0c073a1a;
case 0x0c073a1cu: goto P_0c073a1c;
case 0x0c073a1eu: goto P_0c073a1e;
case 0x0c073a20u: goto P_0c073a20;
case 0x0c073a22u: goto P_0c073a22;
case 0x0c073a24u: goto P_0c073a24;
case 0x0c073a26u: goto P_0c073a26;
case 0x0c073a28u: goto P_0c073a28;
case 0x0c073a2au: goto P_0c073a2a;
case 0x0c073a2cu: goto P_0c073a2c;
case 0x0c073a2eu: goto P_0c073a2e;
case 0x0c073a30u: goto P_0c073a30;
case 0x0c073a32u: goto P_0c073a32;
case 0x0c073a34u: goto P_0c073a34;
case 0x0c073a36u: goto P_0c073a36;
case 0x0c073a38u: goto P_0c073a38;
case 0x0c073a3au: goto P_0c073a3a;
case 0x0c073a3cu: goto P_0c073a3c;
case 0x0c073a3eu: goto P_0c073a3e;
case 0x0c073a40u: goto P_0c073a40;
case 0x0c073a42u: goto P_0c073a42;
case 0x0c073a44u: goto P_0c073a44;
case 0x0c073a46u: goto P_0c073a46;
case 0x0c073a48u: goto P_0c073a48;
case 0x0c073a4au: goto P_0c073a4a;
case 0x0c073a4cu: goto P_0c073a4c;
case 0x0c073a4eu: goto P_0c073a4e;
case 0x0c073a50u: goto P_0c073a50;
case 0x0c073a52u: goto P_0c073a52;
case 0x0c073a54u: goto P_0c073a54;
case 0x0c073a56u: goto P_0c073a56;
case 0x0c073a58u: goto P_0c073a58;
case 0x0c073a5au: goto P_0c073a5a;
case 0x0c073a5cu: goto P_0c073a5c;
case 0x0c073a5eu: goto P_0c073a5e;
case 0x0c073a60u: goto P_0c073a60;
case 0x0c073a62u: goto P_0c073a62;
case 0x0c073a64u: goto P_0c073a64;
case 0x0c073a66u: goto P_0c073a66;
case 0x0c073a68u: goto P_0c073a68;
case 0x0c073a6au: goto P_0c073a6a;
case 0x0c073a6cu: goto P_0c073a6c;
case 0x0c073a6eu: goto P_0c073a6e;
case 0x0c073a70u: goto P_0c073a70;
case 0x0c073a72u: goto P_0c073a72;
case 0x0c073a74u: goto P_0c073a74;
case 0x0c073a76u: goto P_0c073a76;
case 0x0c073a78u: goto P_0c073a78;
case 0x0c073a7au: goto P_0c073a7a;
case 0x0c073a7cu: goto P_0c073a7c;
case 0x0c073a7eu: goto P_0c073a7e;
case 0x0c076b92u: goto P_0c076b92;
case 0x0c076b94u: goto P_0c076b94;
case 0x0c076b96u: goto P_0c076b96;
case 0x0c076b98u: goto P_0c076b98;
case 0x0c076b9au: goto P_0c076b9a;
case 0x0c076b9cu: goto P_0c076b9c;
case 0x0c076b9eu: goto P_0c076b9e;
case 0x0c076ba0u: goto P_0c076ba0;
case 0x0c076ba2u: goto P_0c076ba2;
case 0x0c076ba4u: goto P_0c076ba4;
case 0x0c076ba6u: goto P_0c076ba6;
case 0x0c076ba8u: goto P_0c076ba8;
case 0x0c076baau: goto P_0c076baa;
case 0x0c076bacu: goto P_0c076bac;
case 0x0c076baeu: goto P_0c076bae;
case 0x0c076bb0u: goto P_0c076bb0;
case 0x0c076bb2u: goto P_0c076bb2;
case 0x0c076bb4u: goto P_0c076bb4;
case 0x0c076bb6u: goto P_0c076bb6;
case 0x0c076bb8u: goto P_0c076bb8;
case 0x0c076bbau: goto P_0c076bba;
case 0x0c076bbcu: goto P_0c076bbc;
case 0x0c076bbeu: goto P_0c076bbe;
case 0x0c076bc0u: goto P_0c076bc0;
case 0x0c076bc2u: goto P_0c076bc2;
case 0x0c076bc4u: goto P_0c076bc4;
case 0x0c076bc6u: goto P_0c076bc6;
case 0x0c076bc8u: goto P_0c076bc8;
case 0x0c076bcau: goto P_0c076bca;
case 0x0c076bccu: goto P_0c076bcc;
case 0x0c076bceu: goto P_0c076bce;
case 0x0c076bd0u: goto P_0c076bd0;
case 0x0c076bd2u: goto P_0c076bd2;
case 0x0c076bd4u: goto P_0c076bd4;
case 0x0c076bd6u: goto P_0c076bd6;
case 0x0c076bd8u: goto P_0c076bd8;
case 0x0c076bdau: goto P_0c076bda;
case 0x0c076bdcu: goto P_0c076bdc;
case 0x0c076bdeu: goto P_0c076bde;
case 0x0c076be0u: goto P_0c076be0;
case 0x0c076be2u: goto P_0c076be2;
case 0x0c076be4u: goto P_0c076be4;
case 0x0c076be6u: goto P_0c076be6;
case 0x0c076be8u: goto P_0c076be8;
case 0x0c076beau: goto P_0c076bea;
case 0x0c076becu: goto P_0c076bec;
case 0x0c076beeu: goto P_0c076bee;
case 0x0c076bf0u: goto P_0c076bf0;
case 0x0c076bf2u: goto P_0c076bf2;
case 0x0c076bf4u: goto P_0c076bf4;
case 0x0c076bf6u: goto P_0c076bf6;
case 0x0c076bf8u: goto P_0c076bf8;
case 0x0c076bfau: goto P_0c076bfa;
case 0x0c076bfcu: goto P_0c076bfc;
case 0x0c076bfeu: goto P_0c076bfe;
case 0x0c076c00u: goto P_0c076c00;
case 0x0c076c02u: goto P_0c076c02;
case 0x0c076c04u: goto P_0c076c04;
case 0x0c076c06u: goto P_0c076c06;
case 0x0c076c08u: goto P_0c076c08;
case 0x0c076c0au: goto P_0c076c0a;
case 0x0c076c0cu: goto P_0c076c0c;
case 0x0c076c0eu: goto P_0c076c0e;
case 0x0c076c10u: goto P_0c076c10;
case 0x0c076c12u: goto P_0c076c12;
case 0x0c076c14u: goto P_0c076c14;
case 0x0c076c16u: goto P_0c076c16;
case 0x0c076c18u: goto P_0c076c18;
case 0x0c076c1au: goto P_0c076c1a;
case 0x0c076c1cu: goto P_0c076c1c;
case 0x0c076c1eu: goto P_0c076c1e;
case 0x0c076c20u: goto P_0c076c20;
case 0x0c076c22u: goto P_0c076c22;
case 0x0c076c24u: goto P_0c076c24;
case 0x0c076c26u: goto P_0c076c26;
case 0x0c076c28u: goto P_0c076c28;
case 0x0c076c2au: goto P_0c076c2a;
case 0x0c076c2cu: goto P_0c076c2c;
case 0x0c076c2eu: goto P_0c076c2e;
case 0x0c076c30u: goto P_0c076c30;
case 0x0c076c32u: goto P_0c076c32;
case 0x0c076c34u: goto P_0c076c34;
case 0x0c076c36u: goto P_0c076c36;
case 0x0c076c38u: goto P_0c076c38;
case 0x0c076c3au: goto P_0c076c3a;
case 0x0c076c3cu: goto P_0c076c3c;
case 0x0c076c3eu: goto P_0c076c3e;
case 0x0c076c40u: goto P_0c076c40;
case 0x0c076c42u: goto P_0c076c42;
case 0x0c076c44u: goto P_0c076c44;
case 0x0c076c46u: goto P_0c076c46;
case 0x0c076c48u: goto P_0c076c48;
case 0x0c076c4au: goto P_0c076c4a;
case 0x0c076c4cu: goto P_0c076c4c;
case 0x0c076c4eu: goto P_0c076c4e;
case 0x0c076c50u: goto P_0c076c50;
case 0x0c076c52u: goto P_0c076c52;
case 0x0c076c54u: goto P_0c076c54;
case 0x0c076c56u: goto P_0c076c56;
case 0x0c076c58u: goto P_0c076c58;
case 0x0c076c5au: goto P_0c076c5a;
case 0x0c076c5cu: goto P_0c076c5c;
case 0x0c076c5eu: goto P_0c076c5e;
case 0x0c076c60u: goto P_0c076c60;
case 0x0c076c62u: goto P_0c076c62;
case 0x0c076c64u: goto P_0c076c64;
case 0x0c076c66u: goto P_0c076c66;
case 0x0c076c68u: goto P_0c076c68;
case 0x0c076c6au: goto P_0c076c6a;
case 0x0c076c6cu: goto P_0c076c6c;
case 0x0c076c6eu: goto P_0c076c6e;
case 0x0c076c70u: goto P_0c076c70;
case 0x0c076c72u: goto P_0c076c72;
case 0x0c076c74u: goto P_0c076c74;
case 0x0c076c76u: goto P_0c076c76;
case 0x0c076c78u: goto P_0c076c78;
case 0x0c076c7au: goto P_0c076c7a;
case 0x0c076c7cu: goto P_0c076c7c;
case 0x0c076c7eu: goto P_0c076c7e;
case 0x0c076c80u: goto P_0c076c80;
case 0x0c076c82u: goto P_0c076c82;
case 0x0c076c84u: goto P_0c076c84;
case 0x0c076c86u: goto P_0c076c86;
case 0x0c076c88u: goto P_0c076c88;
case 0x0c076c8au: goto P_0c076c8a;
case 0x0c076c8cu: goto P_0c076c8c;
case 0x0c076c8eu: goto P_0c076c8e;
case 0x0c076c90u: goto P_0c076c90;
case 0x0c076c92u: goto P_0c076c92;
case 0x0c076c94u: goto P_0c076c94;
case 0x0c076c96u: goto P_0c076c96;
case 0x0c076c98u: goto P_0c076c98;
case 0x0c076c9au: goto P_0c076c9a;
case 0x0c076c9cu: goto P_0c076c9c;
case 0x0c076c9eu: goto P_0c076c9e;
case 0x0c076cd8u: goto P_0c076cd8;
case 0x0c076cdau: goto P_0c076cda;
case 0x0c076cdcu: goto P_0c076cdc;
case 0x0c076cdeu: goto P_0c076cde;
case 0x0c076ce0u: goto P_0c076ce0;
case 0x0c076ce2u: goto P_0c076ce2;
case 0x0c076ce4u: goto P_0c076ce4;
case 0x0c076ce6u: goto P_0c076ce6;
case 0x0c076ce8u: goto P_0c076ce8;
case 0x0c076ceau: goto P_0c076cea;
case 0x0c076cecu: goto P_0c076cec;
case 0x0c076ceeu: goto P_0c076cee;
case 0x0c076cf0u: goto P_0c076cf0;
case 0x0c076cf2u: goto P_0c076cf2;
case 0x0c076cf4u: goto P_0c076cf4;
case 0x0c076cf6u: goto P_0c076cf6;
case 0x0c076cf8u: goto P_0c076cf8;
case 0x0c076cfau: goto P_0c076cfa;
case 0x0c076cfcu: goto P_0c076cfc;
case 0x0c076cfeu: goto P_0c076cfe;
case 0x0c076d00u: goto P_0c076d00;
case 0x0c076d02u: goto P_0c076d02;
case 0x0c076d04u: goto P_0c076d04;
case 0x0c076d06u: goto P_0c076d06;
case 0x0c076d08u: goto P_0c076d08;
case 0x0c076d0au: goto P_0c076d0a;
case 0x0c076d0cu: goto P_0c076d0c;
case 0x0c076d0eu: goto P_0c076d0e;
case 0x0c076d10u: goto P_0c076d10;
case 0x0c076d12u: goto P_0c076d12;
case 0x0c076d14u: goto P_0c076d14;
case 0x0c076d16u: goto P_0c076d16;
case 0x0c076d18u: goto P_0c076d18;
case 0x0c076d1au: goto P_0c076d1a;
case 0x0c076d1cu: goto P_0c076d1c;
case 0x0c076d1eu: goto P_0c076d1e;
case 0x0c076d20u: goto P_0c076d20;
case 0x0c076d22u: goto P_0c076d22;
case 0x0c076d24u: goto P_0c076d24;
case 0x0c076d26u: goto P_0c076d26;
case 0x0c076d28u: goto P_0c076d28;
case 0x0c076d2au: goto P_0c076d2a;
case 0x0c076d2cu: goto P_0c076d2c;
case 0x0c076d2eu: goto P_0c076d2e;
case 0x0c076d30u: goto P_0c076d30;
case 0x0c076d32u: goto P_0c076d32;
case 0x0c076d34u: goto P_0c076d34;
case 0x0c076d36u: goto P_0c076d36;
case 0x0c076d38u: goto P_0c076d38;
case 0x0c076d3au: goto P_0c076d3a;
case 0x0c076d3cu: goto P_0c076d3c;
case 0x0c076d3eu: goto P_0c076d3e;
case 0x0c076d40u: goto P_0c076d40;
case 0x0c076d42u: goto P_0c076d42;
case 0x0c076d44u: goto P_0c076d44;
case 0x0c076d46u: goto P_0c076d46;
case 0x0c076d48u: goto P_0c076d48;
case 0x0c076d4au: goto P_0c076d4a;
case 0x0c076d4cu: goto P_0c076d4c;
case 0x0c076d4eu: goto P_0c076d4e;
case 0x0c076d50u: goto P_0c076d50;
case 0x0c076d52u: goto P_0c076d52;
case 0x0c076d54u: goto P_0c076d54;
case 0x0c076d56u: goto P_0c076d56;
case 0x0c076d58u: goto P_0c076d58;
case 0x0c076d5au: goto P_0c076d5a;
case 0x0c076d5cu: goto P_0c076d5c;
case 0x0c076d5eu: goto P_0c076d5e;
case 0x0c076d60u: goto P_0c076d60;
case 0x0c076d62u: goto P_0c076d62;
case 0x0c076d64u: goto P_0c076d64;
case 0x0c076d66u: goto P_0c076d66;
case 0x0c076d68u: goto P_0c076d68;
case 0x0c076d6au: goto P_0c076d6a;
case 0x0c076d6cu: goto P_0c076d6c;
case 0x0c076d6eu: goto P_0c076d6e;
case 0x0c076d70u: goto P_0c076d70;
case 0x0c076d72u: goto P_0c076d72;
case 0x0c076d74u: goto P_0c076d74;
case 0x0c076d76u: goto P_0c076d76;
case 0x0c076d78u: goto P_0c076d78;
case 0x0c076d7au: goto P_0c076d7a;
case 0x0c076d7cu: goto P_0c076d7c;
case 0x0c076d7eu: goto P_0c076d7e;
case 0x0c076d80u: goto P_0c076d80;
case 0x0c076d82u: goto P_0c076d82;
case 0x0c076d84u: goto P_0c076d84;
case 0x0c076d86u: goto P_0c076d86;
case 0x0c076d88u: goto P_0c076d88;
case 0x0c076d8au: goto P_0c076d8a;
case 0x0c076d8cu: goto P_0c076d8c;
case 0x0c076d8eu: goto P_0c076d8e;
case 0x0c076d90u: goto P_0c076d90;
case 0x0c076d92u: goto P_0c076d92;
case 0x0c076d94u: goto P_0c076d94;
case 0x0c076d96u: goto P_0c076d96;
case 0x0c076d98u: goto P_0c076d98;
case 0x0c076d9au: goto P_0c076d9a;
case 0x0c076d9cu: goto P_0c076d9c;
case 0x0c076d9eu: goto P_0c076d9e;
case 0x0c076da0u: goto P_0c076da0;
case 0x0c076da2u: goto P_0c076da2;
case 0x0c076da4u: goto P_0c076da4;
case 0x0c076da6u: goto P_0c076da6;
case 0x0c076da8u: goto P_0c076da8;
case 0x0c076de0u: goto P_0c076de0;
case 0x0c076de2u: goto P_0c076de2;
case 0x0c076de4u: goto P_0c076de4;
case 0x0c076de6u: goto P_0c076de6;
case 0x0c076de8u: goto P_0c076de8;
case 0x0c076deau: goto P_0c076dea;
case 0x0c076decu: goto P_0c076dec;
case 0x0c076deeu: goto P_0c076dee;
case 0x0c076df0u: goto P_0c076df0;
case 0x0c076df2u: goto P_0c076df2;
case 0x0c076df4u: goto P_0c076df4;
case 0x0c076df6u: goto P_0c076df6;
case 0x0c076df8u: goto P_0c076df8;
case 0x0c076dfau: goto P_0c076dfa;
case 0x0c076dfcu: goto P_0c076dfc;
case 0x0c076dfeu: goto P_0c076dfe;
case 0x0c076e00u: goto P_0c076e00;
case 0x0c076e02u: goto P_0c076e02;
case 0x0c076e04u: goto P_0c076e04;
case 0x0c076e06u: goto P_0c076e06;
case 0x0c076e08u: goto P_0c076e08;
case 0x0c076e0au: goto P_0c076e0a;
case 0x0c076e0cu: goto P_0c076e0c;
case 0x0c076e0eu: goto P_0c076e0e;
case 0x0c076e10u: goto P_0c076e10;
case 0x0c076e12u: goto P_0c076e12;
case 0x0c076e14u: goto P_0c076e14;
case 0x0c076e16u: goto P_0c076e16;
case 0x0c076e18u: goto P_0c076e18;
case 0x0c076e1au: goto P_0c076e1a;
case 0x0c076e1cu: goto P_0c076e1c;
case 0x0c076e1eu: goto P_0c076e1e;
case 0x0c076e20u: goto P_0c076e20;
case 0x0c076e22u: goto P_0c076e22;
case 0x0c076e24u: goto P_0c076e24;
case 0x0c076e26u: goto P_0c076e26;
case 0x0c076e28u: goto P_0c076e28;
case 0x0c076e2au: goto P_0c076e2a;
case 0x0c076e2cu: goto P_0c076e2c;
case 0x0c076e2eu: goto P_0c076e2e;
case 0x0c076e30u: goto P_0c076e30;
case 0x0c076e32u: goto P_0c076e32;
case 0x0c076e34u: goto P_0c076e34;
case 0x0c076e36u: goto P_0c076e36;
case 0x0c076e38u: goto P_0c076e38;
case 0x0c076e3au: goto P_0c076e3a;
case 0x0c076e3cu: goto P_0c076e3c;
case 0x0c076e3eu: goto P_0c076e3e;
case 0x0c076e40u: goto P_0c076e40;
case 0x0c076e42u: goto P_0c076e42;
case 0x0c076e44u: goto P_0c076e44;
case 0x0c076e46u: goto P_0c076e46;
case 0x0c076e48u: goto P_0c076e48;
case 0x0c076e4au: goto P_0c076e4a;
case 0x0c076e4cu: goto P_0c076e4c;
case 0x0c076e4eu: goto P_0c076e4e;
case 0x0c076e50u: goto P_0c076e50;
case 0x0c076e52u: goto P_0c076e52;
case 0x0c076e54u: goto P_0c076e54;
case 0x0c076e56u: goto P_0c076e56;
case 0x0c076e58u: goto P_0c076e58;
case 0x0c076e5au: goto P_0c076e5a;
case 0x0c076e5cu: goto P_0c076e5c;
case 0x0c076e5eu: goto P_0c076e5e;
case 0x0c076e60u: goto P_0c076e60;
case 0x0c076e62u: goto P_0c076e62;
case 0x0c076e64u: goto P_0c076e64;
case 0x0c076e66u: goto P_0c076e66;
case 0x0c076e68u: goto P_0c076e68;
case 0x0c076e6au: goto P_0c076e6a;
case 0x0c076e6cu: goto P_0c076e6c;
case 0x0c076e6eu: goto P_0c076e6e;
case 0x0c076e70u: goto P_0c076e70;
case 0x0c076e72u: goto P_0c076e72;
case 0x0c076e74u: goto P_0c076e74;
case 0x0c076e76u: goto P_0c076e76;
case 0x0c076e78u: goto P_0c076e78;
case 0x0c076e7au: goto P_0c076e7a;
case 0x0c076e7cu: goto P_0c076e7c;
case 0x0c076e7eu: goto P_0c076e7e;
case 0x0c076e80u: goto P_0c076e80;
case 0x0c076e82u: goto P_0c076e82;
case 0x0c076e84u: goto P_0c076e84;
case 0x0c076e86u: goto P_0c076e86;
case 0x0c076e88u: goto P_0c076e88;
case 0x0c076e8au: goto P_0c076e8a;
case 0x0c076e8cu: goto P_0c076e8c;
case 0x0c076e8eu: goto P_0c076e8e;
case 0x0c076e90u: goto P_0c076e90;
case 0x0c076e92u: goto P_0c076e92;
case 0x0c076e94u: goto P_0c076e94;
case 0x0c076e96u: goto P_0c076e96;
case 0x0c076e98u: goto P_0c076e98;
case 0x0c076e9au: goto P_0c076e9a;
case 0x0c076e9cu: goto P_0c076e9c;
case 0x0c076e9eu: goto P_0c076e9e;
case 0x0c076ea0u: goto P_0c076ea0;
case 0x0c076ea2u: goto P_0c076ea2;
case 0x0c076ea4u: goto P_0c076ea4;
case 0x0c076ea6u: goto P_0c076ea6;
case 0x0c076ea8u: goto P_0c076ea8;
case 0x0c076eaau: goto P_0c076eaa;
case 0x0c076eacu: goto P_0c076eac;
case 0x0c076eaeu: goto P_0c076eae;
case 0x0c076eb0u: goto P_0c076eb0;
case 0x0c076eb2u: goto P_0c076eb2;
case 0x0c076eb4u: goto P_0c076eb4;
case 0x0c076eb6u: goto P_0c076eb6;
case 0x0c076eb8u: goto P_0c076eb8;
case 0x0c076ebau: goto P_0c076eba;
case 0x0c076ef4u: goto P_0c076ef4;
case 0x0c076ef6u: goto P_0c076ef6;
case 0x0c076ef8u: goto P_0c076ef8;
case 0x0c076efau: goto P_0c076efa;
case 0x0c076efcu: goto P_0c076efc;
case 0x0c076efeu: goto P_0c076efe;
case 0x0c076f00u: goto P_0c076f00;
case 0x0c076f02u: goto P_0c076f02;
case 0x0c076f04u: goto P_0c076f04;
case 0x0c076f06u: goto P_0c076f06;
case 0x0c076f08u: goto P_0c076f08;
case 0x0c076f0au: goto P_0c076f0a;
case 0x0c076f0cu: goto P_0c076f0c;
case 0x0c076f0eu: goto P_0c076f0e;
case 0x0c076f10u: goto P_0c076f10;
case 0x0c076f12u: goto P_0c076f12;
case 0x0c076f14u: goto P_0c076f14;
case 0x0c076f16u: goto P_0c076f16;
case 0x0c076f18u: goto P_0c076f18;
case 0x0c076f1au: goto P_0c076f1a;
case 0x0c076f1cu: goto P_0c076f1c;
case 0x0c076f1eu: goto P_0c076f1e;
case 0x0c076f20u: goto P_0c076f20;
case 0x0c076f22u: goto P_0c076f22;
case 0x0c076f24u: goto P_0c076f24;
case 0x0c076f26u: goto P_0c076f26;
case 0x0c076f28u: goto P_0c076f28;
case 0x0c076f2au: goto P_0c076f2a;
case 0x0c076f2cu: goto P_0c076f2c;
case 0x0c076f2eu: goto P_0c076f2e;
case 0x0c076f30u: goto P_0c076f30;
case 0x0c076f32u: goto P_0c076f32;
case 0x0c076f34u: goto P_0c076f34;
case 0x0c076f36u: goto P_0c076f36;
case 0x0c076f38u: goto P_0c076f38;
case 0x0c076f3au: goto P_0c076f3a;
case 0x0c076f3cu: goto P_0c076f3c;
case 0x0c076f3eu: goto P_0c076f3e;
case 0x0c076f40u: goto P_0c076f40;
case 0x0c076f42u: goto P_0c076f42;
case 0x0c076f44u: goto P_0c076f44;
case 0x0c076f46u: goto P_0c076f46;
case 0x0c076f48u: goto P_0c076f48;
case 0x0c076f4au: goto P_0c076f4a;
case 0x0c076f4cu: goto P_0c076f4c;
case 0x0c076f4eu: goto P_0c076f4e;
case 0x0c076f50u: goto P_0c076f50;
case 0x0c076f52u: goto P_0c076f52;
case 0x0c076f54u: goto P_0c076f54;
case 0x0c076f56u: goto P_0c076f56;
case 0x0c076f58u: goto P_0c076f58;
case 0x0c076f5au: goto P_0c076f5a;
case 0x0c076f5cu: goto P_0c076f5c;
case 0x0c076f5eu: goto P_0c076f5e;
case 0x0c076f60u: goto P_0c076f60;
case 0x0c076f62u: goto P_0c076f62;
case 0x0c076f64u: goto P_0c076f64;
case 0x0c076f66u: goto P_0c076f66;
case 0x0c076f68u: goto P_0c076f68;
case 0x0c076f6au: goto P_0c076f6a;
case 0x0c076f6cu: goto P_0c076f6c;
case 0x0c076f6eu: goto P_0c076f6e;
case 0x0c076f70u: goto P_0c076f70;
case 0x0c076f72u: goto P_0c076f72;
case 0x0c076f74u: goto P_0c076f74;
case 0x0c076f76u: goto P_0c076f76;
case 0x0c076f78u: goto P_0c076f78;
case 0x0c076f7au: goto P_0c076f7a;
case 0x0c076f7cu: goto P_0c076f7c;
case 0x0c076f7eu: goto P_0c076f7e;
case 0x0c076f80u: goto P_0c076f80;
case 0x0c076f82u: goto P_0c076f82;
case 0x0c076f84u: goto P_0c076f84;
case 0x0c076f86u: goto P_0c076f86;
case 0x0c076f88u: goto P_0c076f88;
case 0x0c076f8au: goto P_0c076f8a;
case 0x0c076f8cu: goto P_0c076f8c;
case 0x0c076f8eu: goto P_0c076f8e;
case 0x0c076f90u: goto P_0c076f90;
case 0x0c076f92u: goto P_0c076f92;
case 0x0c076f94u: goto P_0c076f94;
case 0x0c076f96u: goto P_0c076f96;
case 0x0c076f98u: goto P_0c076f98;
case 0x0c076f9au: goto P_0c076f9a;
case 0x0c076f9cu: goto P_0c076f9c;
case 0x0c076f9eu: goto P_0c076f9e;
case 0x0c076fa0u: goto P_0c076fa0;
case 0x0c076fa2u: goto P_0c076fa2;
case 0x0c076fa4u: goto P_0c076fa4;
case 0x0c076fa6u: goto P_0c076fa6;
case 0x0c076fa8u: goto P_0c076fa8;
case 0x0c076faau: goto P_0c076faa;
case 0x0c076facu: goto P_0c076fac;
case 0x0c076faeu: goto P_0c076fae;
case 0x0c076fb0u: goto P_0c076fb0;
case 0x0c076fb2u: goto P_0c076fb2;
case 0x0c076fb4u: goto P_0c076fb4;
case 0x0c076fb6u: goto P_0c076fb6;
case 0x0c076fb8u: goto P_0c076fb8;
case 0x0c076fbau: goto P_0c076fba;
case 0x0c076fbcu: goto P_0c076fbc;
case 0x0c076fbeu: goto P_0c076fbe;
case 0x0c076fc0u: goto P_0c076fc0;
case 0x0c076fc2u: goto P_0c076fc2;
case 0x0c076fc4u: goto P_0c076fc4;
case 0x0c076fc6u: goto P_0c076fc6;
case 0x0c076fc8u: goto P_0c076fc8;
case 0x0c076fcau: goto P_0c076fca;
case 0x0c076fccu: goto P_0c076fcc;
case 0x0c076fceu: goto P_0c076fce;
case 0x0c076fd0u: goto P_0c076fd0;
case 0x0c076fd2u: goto P_0c076fd2;
case 0x0c076fd4u: goto P_0c076fd4;
case 0x0c076fd6u: goto P_0c076fd6;
case 0x0c076fd8u: goto P_0c076fd8;
case 0x0c076fdau: goto P_0c076fda;
case 0x0c076fdcu: goto P_0c076fdc;
case 0x0c076fdeu: goto P_0c076fde;
case 0x0c076fe0u: goto P_0c076fe0;
case 0x0c076fe2u: goto P_0c076fe2;
case 0x0c076fe4u: goto P_0c076fe4;
case 0x0c076fe6u: goto P_0c076fe6;
case 0x0c076fe8u: goto P_0c076fe8;
case 0x0c076feau: goto P_0c076fea;
case 0x0c076fecu: goto P_0c076fec;
case 0x0c076feeu: goto P_0c076fee;
case 0x0c076ff0u: goto P_0c076ff0;
case 0x0c076ff2u: goto P_0c076ff2;
case 0x0c076ff4u: goto P_0c076ff4;
case 0x0c076ff6u: goto P_0c076ff6;
case 0x0c076ff8u: goto P_0c076ff8;
case 0x0c076ffau: goto P_0c076ffa;
case 0x0c076ffcu: goto P_0c076ffc;
case 0x0c076ffeu: goto P_0c076ffe;
case 0x0c077000u: goto P_0c077000;
case 0x0c077002u: goto P_0c077002;
case 0x0c077004u: goto P_0c077004;
case 0x0c077006u: goto P_0c077006;
case 0x0c077008u: goto P_0c077008;
case 0x0c07700au: goto P_0c07700a;
case 0x0c07700cu: goto P_0c07700c;
case 0x0c07700eu: goto P_0c07700e;
case 0x0c077010u: goto P_0c077010;
case 0x0c077012u: goto P_0c077012;
case 0x0c077014u: goto P_0c077014;
case 0x0c077016u: goto P_0c077016;
case 0x0c077018u: goto P_0c077018;
case 0x0c07701au: goto P_0c07701a;
case 0x0c07701cu: goto P_0c07701c;
case 0x0c07701eu: goto P_0c07701e;
case 0x0c077020u: goto P_0c077020;
case 0x0c077022u: goto P_0c077022;
case 0x0c077024u: goto P_0c077024;
case 0x0c077026u: goto P_0c077026;
case 0x0c077028u: goto P_0c077028;
case 0x0c07702au: goto P_0c07702a;
case 0x0c07702cu: goto P_0c07702c;
case 0x0c07702eu: goto P_0c07702e;
case 0x0c077030u: goto P_0c077030;
case 0x0c077032u: goto P_0c077032;
case 0x0c077034u: goto P_0c077034;
case 0x0c077036u: goto P_0c077036;
case 0x0c077038u: goto P_0c077038;
case 0x0c07703au: goto P_0c07703a;
case 0x0c07703cu: goto P_0c07703c;
case 0x0c07703eu: goto P_0c07703e;
case 0x0c077040u: goto P_0c077040;
case 0x0c077042u: goto P_0c077042;
case 0x0c077044u: goto P_0c077044;
case 0x0c077046u: goto P_0c077046;
case 0x0c077048u: goto P_0c077048;
case 0x0c07704au: goto P_0c07704a;
case 0x0c07704cu: goto P_0c07704c;
case 0x0c07704eu: goto P_0c07704e;
case 0x0c077050u: goto P_0c077050;
case 0x0c077052u: goto P_0c077052;
case 0x0c077054u: goto P_0c077054;
case 0x0c077056u: goto P_0c077056;
case 0x0c077058u: goto P_0c077058;
case 0x0c07705au: goto P_0c07705a;
case 0x0c07705cu: goto P_0c07705c;
case 0x0c07705eu: goto P_0c07705e;
case 0x0c077080u: goto P_0c077080;
case 0x0c077082u: goto P_0c077082;
case 0x0c077084u: goto P_0c077084;
case 0x0c077086u: goto P_0c077086;
case 0x0c077088u: goto P_0c077088;
case 0x0c07708au: goto P_0c07708a;
case 0x0c07708cu: goto P_0c07708c;
case 0x0c07708eu: goto P_0c07708e;
case 0x0c077090u: goto P_0c077090;
case 0x0c077092u: goto P_0c077092;
case 0x0c077094u: goto P_0c077094;
case 0x0c077096u: goto P_0c077096;
case 0x0c077098u: goto P_0c077098;
case 0x0c07709au: goto P_0c07709a;
case 0x0c07709cu: goto P_0c07709c;
case 0x0c07709eu: goto P_0c07709e;
case 0x0c0770a0u: goto P_0c0770a0;
case 0x0c0770a2u: goto P_0c0770a2;
case 0x0c0770a4u: goto P_0c0770a4;
case 0x0c0770a6u: goto P_0c0770a6;
case 0x0c0770a8u: goto P_0c0770a8;
case 0x0c0770aau: goto P_0c0770aa;
case 0x0c0770acu: goto P_0c0770ac;
case 0x0c0770aeu: goto P_0c0770ae;
case 0x0c0770b0u: goto P_0c0770b0;
case 0x0c0770b2u: goto P_0c0770b2;
case 0x0c0770b4u: goto P_0c0770b4;
case 0x0c0770b6u: goto P_0c0770b6;
case 0x0c0770b8u: goto P_0c0770b8;
case 0x0c0770bau: goto P_0c0770ba;
case 0x0c0770bcu: goto P_0c0770bc;
case 0x0c0770beu: goto P_0c0770be;
case 0x0c0770c0u: goto P_0c0770c0;
case 0x0c0770c2u: goto P_0c0770c2;
case 0x0c0770c4u: goto P_0c0770c4;
case 0x0c0770c6u: goto P_0c0770c6;
case 0x0c0770c8u: goto P_0c0770c8;
case 0x0c0770cau: goto P_0c0770ca;
case 0x0c0770ccu: goto P_0c0770cc;
case 0x0c0770ceu: goto P_0c0770ce;
case 0x0c0770d0u: goto P_0c0770d0;
case 0x0c0770d2u: goto P_0c0770d2;
case 0x0c0770d4u: goto P_0c0770d4;
case 0x0c0770d6u: goto P_0c0770d6;
case 0x0c0770d8u: goto P_0c0770d8;
case 0x0c0770dau: goto P_0c0770da;
case 0x0c0770dcu: goto P_0c0770dc;
case 0x0c0770deu: goto P_0c0770de;
case 0x0c0770e0u: goto P_0c0770e0;
case 0x0c0770e2u: goto P_0c0770e2;
case 0x0c0770e4u: goto P_0c0770e4;
case 0x0c0770e6u: goto P_0c0770e6;
case 0x0c0770e8u: goto P_0c0770e8;
case 0x0c0770eau: goto P_0c0770ea;
case 0x0c0770ecu: goto P_0c0770ec;
case 0x0c0770eeu: goto P_0c0770ee;
case 0x0c0770f0u: goto P_0c0770f0;
case 0x0c0770f2u: goto P_0c0770f2;
case 0x0c0770f4u: goto P_0c0770f4;
case 0x0c0770f6u: goto P_0c0770f6;
case 0x0c0770f8u: goto P_0c0770f8;
case 0x0c0770fau: goto P_0c0770fa;
case 0x0c0770fcu: goto P_0c0770fc;
case 0x0c0770feu: goto P_0c0770fe;
case 0x0c077100u: goto P_0c077100;
case 0x0c077102u: goto P_0c077102;
case 0x0c077104u: goto P_0c077104;
case 0x0c077106u: goto P_0c077106;
case 0x0c077108u: goto P_0c077108;
case 0x0c07710au: goto P_0c07710a;
case 0x0c07710cu: goto P_0c07710c;
case 0x0c07710eu: goto P_0c07710e;
case 0x0c077110u: goto P_0c077110;
case 0x0c077112u: goto P_0c077112;
case 0x0c077114u: goto P_0c077114;
case 0x0c077116u: goto P_0c077116;
case 0x0c077118u: goto P_0c077118;
case 0x0c07711au: goto P_0c07711a;
case 0x0c07711cu: goto P_0c07711c;
case 0x0c07711eu: goto P_0c07711e;
case 0x0c077120u: goto P_0c077120;
case 0x0c077122u: goto P_0c077122;
case 0x0c077124u: goto P_0c077124;
case 0x0c077126u: goto P_0c077126;
case 0x0c077128u: goto P_0c077128;
case 0x0c07712au: goto P_0c07712a;
case 0x0c07712cu: goto P_0c07712c;
case 0x0c07712eu: goto P_0c07712e;
case 0x0c077130u: goto P_0c077130;
case 0x0c077132u: goto P_0c077132;
case 0x0c077134u: goto P_0c077134;
case 0x0c077136u: goto P_0c077136;
case 0x0c077138u: goto P_0c077138;
case 0x0c07713au: goto P_0c07713a;
case 0x0c07713cu: goto P_0c07713c;
case 0x0c07713eu: goto P_0c07713e;
case 0x0c077140u: goto P_0c077140;
case 0x0c077142u: goto P_0c077142;
case 0x0c077144u: goto P_0c077144;
case 0x0c077146u: goto P_0c077146;
case 0x0c077148u: goto P_0c077148;
case 0x0c07714au: goto P_0c07714a;
case 0x0c07714cu: goto P_0c07714c;
case 0x0c07714eu: goto P_0c07714e;
case 0x0c077150u: goto P_0c077150;
case 0x0c077152u: goto P_0c077152;
case 0x0c077154u: goto P_0c077154;
case 0x0c077156u: goto P_0c077156;
case 0x0c077158u: goto P_0c077158;
case 0x0c07715au: goto P_0c07715a;
case 0x0c07715cu: goto P_0c07715c;
case 0x0c07715eu: goto P_0c07715e;
case 0x0c077160u: goto P_0c077160;
case 0x0c077162u: goto P_0c077162;
case 0x0c077164u: goto P_0c077164;
case 0x0c077166u: goto P_0c077166;
case 0x0c077168u: goto P_0c077168;
case 0x0c07716au: goto P_0c07716a;
case 0x0c07716cu: goto P_0c07716c;
case 0x0c07716eu: goto P_0c07716e;
case 0x0c077170u: goto P_0c077170;
case 0x0c077172u: goto P_0c077172;
case 0x0c077174u: goto P_0c077174;
case 0x0c077176u: goto P_0c077176;
case 0x0c077178u: goto P_0c077178;
case 0x0c07717au: goto P_0c07717a;
case 0x0c07717cu: goto P_0c07717c;
case 0x0c07717eu: goto P_0c07717e;
case 0x0c077180u: goto P_0c077180;
case 0x0c077182u: goto P_0c077182;
case 0x0c077184u: goto P_0c077184;
case 0x0c077186u: goto P_0c077186;
case 0x0c077188u: goto P_0c077188;
case 0x0c07718au: goto P_0c07718a;
case 0x0c07718cu: goto P_0c07718c;
case 0x0c07718eu: goto P_0c07718e;
case 0x0c077190u: goto P_0c077190;
case 0x0c0771acu: goto P_0c0771ac;
case 0x0c0771aeu: goto P_0c0771ae;
case 0x0c0771b0u: goto P_0c0771b0;
case 0x0c0771b2u: goto P_0c0771b2;
case 0x0c0771b4u: goto P_0c0771b4;
case 0x0c0771b6u: goto P_0c0771b6;
case 0x0c0771b8u: goto P_0c0771b8;
case 0x0c0771bau: goto P_0c0771ba;
case 0x0c0771bcu: goto P_0c0771bc;
case 0x0c0771beu: goto P_0c0771be;
case 0x0c0771c0u: goto P_0c0771c0;
case 0x0c0771c2u: goto P_0c0771c2;
case 0x0c0771c4u: goto P_0c0771c4;
case 0x0c0771c6u: goto P_0c0771c6;
case 0x0c0771c8u: goto P_0c0771c8;
case 0x0c0771cau: goto P_0c0771ca;
case 0x0c0771ccu: goto P_0c0771cc;
case 0x0c0771ceu: goto P_0c0771ce;
case 0x0c0771d0u: goto P_0c0771d0;
case 0x0c0771d2u: goto P_0c0771d2;
case 0x0c0771d4u: goto P_0c0771d4;
case 0x0c0771d6u: goto P_0c0771d6;
case 0x0c0771d8u: goto P_0c0771d8;
case 0x0c0771dau: goto P_0c0771da;
case 0x0c0771dcu: goto P_0c0771dc;
case 0x0c0771deu: goto P_0c0771de;
case 0x0c0771e0u: goto P_0c0771e0;
case 0x0c0771e2u: goto P_0c0771e2;
case 0x0c0771e4u: goto P_0c0771e4;
case 0x0c0771e6u: goto P_0c0771e6;
case 0x0c0771e8u: goto P_0c0771e8;
case 0x0c0771eau: goto P_0c0771ea;
case 0x0c0771ecu: goto P_0c0771ec;
case 0x0c0771eeu: goto P_0c0771ee;
case 0x0c0771f0u: goto P_0c0771f0;
case 0x0c0771f2u: goto P_0c0771f2;
case 0x0c0771f4u: goto P_0c0771f4;
case 0x0c0771f6u: goto P_0c0771f6;
case 0x0c0771f8u: goto P_0c0771f8;
case 0x0c0771fau: goto P_0c0771fa;
case 0x0c0771fcu: goto P_0c0771fc;
case 0x0c0771feu: goto P_0c0771fe;
case 0x0c077200u: goto P_0c077200;
case 0x0c077202u: goto P_0c077202;
case 0x0c077204u: goto P_0c077204;
case 0x0c077206u: goto P_0c077206;
case 0x0c077208u: goto P_0c077208;
case 0x0c07720au: goto P_0c07720a;
case 0x0c07720cu: goto P_0c07720c;
case 0x0c07720eu: goto P_0c07720e;
case 0x0c077210u: goto P_0c077210;
case 0x0c077212u: goto P_0c077212;
case 0x0c077214u: goto P_0c077214;
case 0x0c077216u: goto P_0c077216;
case 0x0c077218u: goto P_0c077218;
case 0x0c07721au: goto P_0c07721a;
case 0x0c07721cu: goto P_0c07721c;
case 0x0c07721eu: goto P_0c07721e;
case 0x0c077220u: goto P_0c077220;
case 0x0c077222u: goto P_0c077222;
case 0x0c077224u: goto P_0c077224;
case 0x0c077226u: goto P_0c077226;
case 0x0c077228u: goto P_0c077228;
case 0x0c07722au: goto P_0c07722a;
case 0x0c07722cu: goto P_0c07722c;
case 0x0c07722eu: goto P_0c07722e;
case 0x0c077230u: goto P_0c077230;
case 0x0c077232u: goto P_0c077232;
case 0x0c077234u: goto P_0c077234;
case 0x0c077236u: goto P_0c077236;
case 0x0c077238u: goto P_0c077238;
case 0x0c07723au: goto P_0c07723a;
case 0x0c07723cu: goto P_0c07723c;
case 0x0c07723eu: goto P_0c07723e;
case 0x0c077240u: goto P_0c077240;
case 0x0c077242u: goto P_0c077242;
case 0x0c077244u: goto P_0c077244;
case 0x0c077246u: goto P_0c077246;
case 0x0c077248u: goto P_0c077248;
case 0x0c07724au: goto P_0c07724a;
case 0x0c07724cu: goto P_0c07724c;
case 0x0c07724eu: goto P_0c07724e;
case 0x0c077250u: goto P_0c077250;
case 0x0c077252u: goto P_0c077252;
case 0x0c077254u: goto P_0c077254;
case 0x0c077256u: goto P_0c077256;
case 0x0c077258u: goto P_0c077258;
case 0x0c07725au: goto P_0c07725a;
case 0x0c07725cu: goto P_0c07725c;
case 0x0c07725eu: goto P_0c07725e;
case 0x0c077260u: goto P_0c077260;
case 0x0c077262u: goto P_0c077262;
case 0x0c077264u: goto P_0c077264;
case 0x0c077266u: goto P_0c077266;
case 0x0c077268u: goto P_0c077268;
case 0x0c07726au: goto P_0c07726a;
case 0x0c07726cu: goto P_0c07726c;
case 0x0c07726eu: goto P_0c07726e;
case 0x0c077270u: goto P_0c077270;
case 0x0c077272u: goto P_0c077272;
case 0x0c077274u: goto P_0c077274;
case 0x0c077276u: goto P_0c077276;
case 0x0c077278u: goto P_0c077278;
case 0x0c07727au: goto P_0c07727a;
case 0x0c07727cu: goto P_0c07727c;
case 0x0c07727eu: goto P_0c07727e;
case 0x0c077280u: goto P_0c077280;
case 0x0c077282u: goto P_0c077282;
case 0x0c077284u: goto P_0c077284;
case 0x0c077286u: goto P_0c077286;
case 0x0c077288u: goto P_0c077288;
case 0x0c07728au: goto P_0c07728a;
case 0x0c0772a0u: goto P_0c0772a0;
case 0x0c0772a2u: goto P_0c0772a2;
case 0x0c0772a4u: goto P_0c0772a4;
case 0x0c0772a6u: goto P_0c0772a6;
case 0x0c0772a8u: goto P_0c0772a8;
case 0x0c0772aau: goto P_0c0772aa;
case 0x0c0772acu: goto P_0c0772ac;
case 0x0c0772aeu: goto P_0c0772ae;
case 0x0c0772b0u: goto P_0c0772b0;
case 0x0c0772b2u: goto P_0c0772b2;
case 0x0c0772b4u: goto P_0c0772b4;
case 0x0c0772b6u: goto P_0c0772b6;
case 0x0c0772b8u: goto P_0c0772b8;
case 0x0c0772bau: goto P_0c0772ba;
case 0x0c0772bcu: goto P_0c0772bc;
case 0x0c0772beu: goto P_0c0772be;
case 0x0c0772c0u: goto P_0c0772c0;
case 0x0c0772c2u: goto P_0c0772c2;
case 0x0c0772c4u: goto P_0c0772c4;
case 0x0c0772c6u: goto P_0c0772c6;
case 0x0c0772c8u: goto P_0c0772c8;
case 0x0c0772cau: goto P_0c0772ca;
case 0x0c0772ccu: goto P_0c0772cc;
case 0x0c0772ceu: goto P_0c0772ce;
case 0x0c0772d0u: goto P_0c0772d0;
case 0x0c0772d2u: goto P_0c0772d2;
case 0x0c0772d4u: goto P_0c0772d4;
case 0x0c0772d6u: goto P_0c0772d6;
case 0x0c0772d8u: goto P_0c0772d8;
case 0x0c0772dau: goto P_0c0772da;
case 0x0c0772dcu: goto P_0c0772dc;
case 0x0c0772deu: goto P_0c0772de;
case 0x0c0772e0u: goto P_0c0772e0;
case 0x0c0772e2u: goto P_0c0772e2;
case 0x0c0772e4u: goto P_0c0772e4;
case 0x0c0772e6u: goto P_0c0772e6;
case 0x0c0772e8u: goto P_0c0772e8;
case 0x0c0772eau: goto P_0c0772ea;
case 0x0c0772ecu: goto P_0c0772ec;
case 0x0c0772eeu: goto P_0c0772ee;
case 0x0c0772f0u: goto P_0c0772f0;
case 0x0c0772f2u: goto P_0c0772f2;
case 0x0c0772f4u: goto P_0c0772f4;
case 0x0c0772f6u: goto P_0c0772f6;
case 0x0c0772f8u: goto P_0c0772f8;
case 0x0c0772fau: goto P_0c0772fa;
case 0x0c0772fcu: goto P_0c0772fc;
case 0x0c0772feu: goto P_0c0772fe;
case 0x0c077300u: goto P_0c077300;
case 0x0c077302u: goto P_0c077302;
case 0x0c077304u: goto P_0c077304;
case 0x0c077306u: goto P_0c077306;
case 0x0c077308u: goto P_0c077308;
case 0x0c07730au: goto P_0c07730a;
case 0x0c07730cu: goto P_0c07730c;
case 0x0c07730eu: goto P_0c07730e;
case 0x0c077310u: goto P_0c077310;
case 0x0c077312u: goto P_0c077312;
case 0x0c077314u: goto P_0c077314;
case 0x0c077316u: goto P_0c077316;
case 0x0c077318u: goto P_0c077318;
case 0x0c07731au: goto P_0c07731a;
case 0x0c07731cu: goto P_0c07731c;
case 0x0c07731eu: goto P_0c07731e;
case 0x0c077320u: goto P_0c077320;
case 0x0c077322u: goto P_0c077322;
case 0x0c077324u: goto P_0c077324;
case 0x0c077326u: goto P_0c077326;
case 0x0c077328u: goto P_0c077328;
case 0x0c07732au: goto P_0c07732a;
case 0x0c07732cu: goto P_0c07732c;
case 0x0c07732eu: goto P_0c07732e;
case 0x0c077330u: goto P_0c077330;
case 0x0c077332u: goto P_0c077332;
case 0x0c077334u: goto P_0c077334;
case 0x0c077336u: goto P_0c077336;
case 0x0c077338u: goto P_0c077338;
case 0x0c07733au: goto P_0c07733a;
case 0x0c07733cu: goto P_0c07733c;
case 0x0c07734cu: goto P_0c07734c;
case 0x0c07734eu: goto P_0c07734e;
case 0x0c077350u: goto P_0c077350;
case 0x0c077352u: goto P_0c077352;
case 0x0c077354u: goto P_0c077354;
case 0x0c077356u: goto P_0c077356;
case 0x0c077358u: goto P_0c077358;
case 0x0c07735au: goto P_0c07735a;
case 0x0c07735cu: goto P_0c07735c;
case 0x0c07735eu: goto P_0c07735e;
case 0x0c077360u: goto P_0c077360;
case 0x0c077362u: goto P_0c077362;
case 0x0c077364u: goto P_0c077364;
case 0x0c077366u: goto P_0c077366;
case 0x0c077368u: goto P_0c077368;
case 0x0c07736au: goto P_0c07736a;
case 0x0c07736cu: goto P_0c07736c;
case 0x0c07736eu: goto P_0c07736e;
case 0x0c077370u: goto P_0c077370;
case 0x0c077372u: goto P_0c077372;
case 0x0c077374u: goto P_0c077374;
case 0x0c077376u: goto P_0c077376;
case 0x0c077378u: goto P_0c077378;
case 0x0c07737au: goto P_0c07737a;
case 0x0c07737cu: goto P_0c07737c;
case 0x0c07737eu: goto P_0c07737e;
case 0x0c077380u: goto P_0c077380;
case 0x0c077382u: goto P_0c077382;
case 0x0c077384u: goto P_0c077384;
case 0x0c077386u: goto P_0c077386;
case 0x0c077388u: goto P_0c077388;
case 0x0c07738au: goto P_0c07738a;
case 0x0c07738cu: goto P_0c07738c;
case 0x0c07738eu: goto P_0c07738e;
case 0x0c077390u: goto P_0c077390;
case 0x0c077392u: goto P_0c077392;
case 0x0c077394u: goto P_0c077394;
case 0x0c077396u: goto P_0c077396;
case 0x0c077398u: goto P_0c077398;
case 0x0c07739au: goto P_0c07739a;
case 0x0c07739cu: goto P_0c07739c;
case 0x0c07739eu: goto P_0c07739e;
case 0x0c0773a0u: goto P_0c0773a0;
case 0x0c0773a2u: goto P_0c0773a2;
case 0x0c0773a4u: goto P_0c0773a4;
case 0x0c0773a6u: goto P_0c0773a6;
case 0x0c0773a8u: goto P_0c0773a8;
case 0x0c0773aau: goto P_0c0773aa;
case 0x0c0773acu: goto P_0c0773ac;
case 0x0c0773aeu: goto P_0c0773ae;
case 0x0c0773b0u: goto P_0c0773b0;
case 0x0c0773b2u: goto P_0c0773b2;
case 0x0c0773b4u: goto P_0c0773b4;
case 0x0c0773b6u: goto P_0c0773b6;
case 0x0c0773b8u: goto P_0c0773b8;
case 0x0c0773bau: goto P_0c0773ba;
case 0x0c0773bcu: goto P_0c0773bc;
case 0x0c0773beu: goto P_0c0773be;
case 0x0c0773c0u: goto P_0c0773c0;
case 0x0c0773c2u: goto P_0c0773c2;
case 0x0c0773c4u: goto P_0c0773c4;
case 0x0c0773c6u: goto P_0c0773c6;
case 0x0c0773c8u: goto P_0c0773c8;
case 0x0c0773cau: goto P_0c0773ca;
case 0x0c0773ccu: goto P_0c0773cc;
case 0x0c0773ceu: goto P_0c0773ce;
case 0x0c0773d0u: goto P_0c0773d0;
case 0x0c0773d2u: goto P_0c0773d2;
case 0x0c0773d4u: goto P_0c0773d4;
case 0x0c0773d6u: goto P_0c0773d6;
case 0x0c0773d8u: goto P_0c0773d8;
case 0x0c0773dau: goto P_0c0773da;
case 0x0c0773dcu: goto P_0c0773dc;
case 0x0c0773deu: goto P_0c0773de;
case 0x0c0773e0u: goto P_0c0773e0;
case 0x0c0773e2u: goto P_0c0773e2;
case 0x0c0773e4u: goto P_0c0773e4;
case 0x0c0773e6u: goto P_0c0773e6;
case 0x0c0773e8u: goto P_0c0773e8;
case 0x0c0773eau: goto P_0c0773ea;
case 0x0c0773ecu: goto P_0c0773ec;
case 0x0c0773eeu: goto P_0c0773ee;
case 0x0c0773f0u: goto P_0c0773f0;
case 0x0c0773f2u: goto P_0c0773f2;
case 0x0c0773f4u: goto P_0c0773f4;
case 0x0c0773f6u: goto P_0c0773f6;
case 0x0c0773f8u: goto P_0c0773f8;
case 0x0c0773fau: goto P_0c0773fa;
case 0x0c0773fcu: goto P_0c0773fc;
case 0x0c0773feu: goto P_0c0773fe;
case 0x0c077400u: goto P_0c077400;
case 0x0c077402u: goto P_0c077402;
case 0x0c077404u: goto P_0c077404;
case 0x0c077406u: goto P_0c077406;
case 0x0c077408u: goto P_0c077408;
case 0x0c07740au: goto P_0c07740a;
case 0x0c07740cu: goto P_0c07740c;
case 0x0c07740eu: goto P_0c07740e;
case 0x0c077410u: goto P_0c077410;
case 0x0c077412u: goto P_0c077412;
case 0x0c077414u: goto P_0c077414;
case 0x0c077416u: goto P_0c077416;
case 0x0c077418u: goto P_0c077418;
case 0x0c07741au: goto P_0c07741a;
case 0x0c07741cu: goto P_0c07741c;
case 0x0c07741eu: goto P_0c07741e;
case 0x0c077420u: goto P_0c077420;
case 0x0c077422u: goto P_0c077422;
case 0x0c077424u: goto P_0c077424;
case 0x0c077426u: goto P_0c077426;
case 0x0c077428u: goto P_0c077428;
case 0x0c07742au: goto P_0c07742a;
case 0x0c07742cu: goto P_0c07742c;
case 0x0c07742eu: goto P_0c07742e;
case 0x0c077430u: goto P_0c077430;
case 0x0c077432u: goto P_0c077432;
case 0x0c077434u: goto P_0c077434;
case 0x0c077436u: goto P_0c077436;
case 0x0c077438u: goto P_0c077438;
case 0x0c07743au: goto P_0c07743a;
case 0x0c07743cu: goto P_0c07743c;
case 0x0c07743eu: goto P_0c07743e;
case 0x0c077440u: goto P_0c077440;
case 0x0c077442u: goto P_0c077442;
case 0x0c077444u: goto P_0c077444;
case 0x0c077446u: goto P_0c077446;
case 0x0c077448u: goto P_0c077448;
case 0x0c07744au: goto P_0c07744a;
case 0x0c07744cu: goto P_0c07744c;
case 0x0c07746cu: goto P_0c07746c;
case 0x0c07746eu: goto P_0c07746e;
case 0x0c077470u: goto P_0c077470;
case 0x0c077472u: goto P_0c077472;
case 0x0c077474u: goto P_0c077474;
case 0x0c077476u: goto P_0c077476;
case 0x0c077478u: goto P_0c077478;
case 0x0c07747au: goto P_0c07747a;
case 0x0c07747cu: goto P_0c07747c;
case 0x0c07747eu: goto P_0c07747e;
case 0x0c077480u: goto P_0c077480;
case 0x0c077482u: goto P_0c077482;
case 0x0c077484u: goto P_0c077484;
case 0x0c077486u: goto P_0c077486;
case 0x0c077488u: goto P_0c077488;
case 0x0c07748au: goto P_0c07748a;
case 0x0c07748cu: goto P_0c07748c;
case 0x0c07748eu: goto P_0c07748e;
case 0x0c077490u: goto P_0c077490;
case 0x0c077492u: goto P_0c077492;
case 0x0c077494u: goto P_0c077494;
case 0x0c077496u: goto P_0c077496;
case 0x0c077498u: goto P_0c077498;
case 0x0c07749au: goto P_0c07749a;
case 0x0c07749cu: goto P_0c07749c;
case 0x0c07749eu: goto P_0c07749e;
case 0x0c0774a0u: goto P_0c0774a0;
case 0x0c0774a2u: goto P_0c0774a2;
case 0x0c0774a4u: goto P_0c0774a4;
case 0x0c0774a6u: goto P_0c0774a6;
case 0x0c0774a8u: goto P_0c0774a8;
case 0x0c0774aau: goto P_0c0774aa;
case 0x0c0774acu: goto P_0c0774ac;
case 0x0c0774aeu: goto P_0c0774ae;
case 0x0c0774b0u: goto P_0c0774b0;
case 0x0c0774b2u: goto P_0c0774b2;
case 0x0c0774b4u: goto P_0c0774b4;
case 0x0c0774b6u: goto P_0c0774b6;
case 0x0c0774b8u: goto P_0c0774b8;
case 0x0c0774bau: goto P_0c0774ba;
case 0x0c0774bcu: goto P_0c0774bc;
case 0x0c0774beu: goto P_0c0774be;
case 0x0c0774c0u: goto P_0c0774c0;
case 0x0c0774c2u: goto P_0c0774c2;
case 0x0c0774c4u: goto P_0c0774c4;
case 0x0c0774c6u: goto P_0c0774c6;
case 0x0c0774c8u: goto P_0c0774c8;
case 0x0c0774cau: goto P_0c0774ca;
case 0x0c0774ccu: goto P_0c0774cc;
case 0x0c0774ceu: goto P_0c0774ce;
case 0x0c0774d0u: goto P_0c0774d0;
case 0x0c0774d2u: goto P_0c0774d2;
case 0x0c0774d4u: goto P_0c0774d4;
case 0x0c0774d6u: goto P_0c0774d6;
case 0x0c0774d8u: goto P_0c0774d8;
case 0x0c0774dau: goto P_0c0774da;
case 0x0c0774dcu: goto P_0c0774dc;
case 0x0c0774deu: goto P_0c0774de;
case 0x0c0774e0u: goto P_0c0774e0;
case 0x0c0774e2u: goto P_0c0774e2;
case 0x0c0774e4u: goto P_0c0774e4;
case 0x0c0774e6u: goto P_0c0774e6;
case 0x0c0774e8u: goto P_0c0774e8;
case 0x0c0774eau: goto P_0c0774ea;
case 0x0c0774ecu: goto P_0c0774ec;
case 0x0c0774eeu: goto P_0c0774ee;
case 0x0c0774f0u: goto P_0c0774f0;
case 0x0c0774f2u: goto P_0c0774f2;
case 0x0c0774f4u: goto P_0c0774f4;
case 0x0c0774f6u: goto P_0c0774f6;
case 0x0c0774f8u: goto P_0c0774f8;
case 0x0c0774fau: goto P_0c0774fa;
case 0x0c0774fcu: goto P_0c0774fc;
case 0x0c0774feu: goto P_0c0774fe;
case 0x0c077500u: goto P_0c077500;
case 0x0c077502u: goto P_0c077502;
case 0x0c077504u: goto P_0c077504;
case 0x0c077506u: goto P_0c077506;
case 0x0c077508u: goto P_0c077508;
case 0x0c07750au: goto P_0c07750a;
case 0x0c07750cu: goto P_0c07750c;
case 0x0c07750eu: goto P_0c07750e;
case 0x0c077510u: goto P_0c077510;
case 0x0c077512u: goto P_0c077512;
case 0x0c077514u: goto P_0c077514;
case 0x0c077516u: goto P_0c077516;
case 0x0c077518u: goto P_0c077518;
case 0x0c07751au: goto P_0c07751a;
case 0x0c07751cu: goto P_0c07751c;
case 0x0c07751eu: goto P_0c07751e;
case 0x0c077520u: goto P_0c077520;
case 0x0c077522u: goto P_0c077522;
case 0x0c077524u: goto P_0c077524;
case 0x0c077526u: goto P_0c077526;
case 0x0c077528u: goto P_0c077528;
case 0x0c07752au: goto P_0c07752a;
case 0x0c07752cu: goto P_0c07752c;
case 0x0c07752eu: goto P_0c07752e;
case 0x0c077530u: goto P_0c077530;
case 0x0c077532u: goto P_0c077532;
case 0x0c077534u: goto P_0c077534;
case 0x0c077536u: goto P_0c077536;
case 0x0c077538u: goto P_0c077538;
case 0x0c07753au: goto P_0c07753a;
case 0x0c07753cu: goto P_0c07753c;
case 0x0c07753eu: goto P_0c07753e;
case 0x0c077540u: goto P_0c077540;
case 0x0c077542u: goto P_0c077542;
case 0x0c077544u: goto P_0c077544;
case 0x0c077546u: goto P_0c077546;
case 0x0c077548u: goto P_0c077548;
case 0x0c07754au: goto P_0c07754a;
case 0x0c07754cu: goto P_0c07754c;
case 0x0c07754eu: goto P_0c07754e;
case 0x0c077550u: goto P_0c077550;
case 0x0c077552u: goto P_0c077552;
case 0x0c077554u: goto P_0c077554;
case 0x0c077556u: goto P_0c077556;
case 0x0c077558u: goto P_0c077558;
case 0x0c07755au: goto P_0c07755a;
case 0x0c07755cu: goto P_0c07755c;
case 0x0c07755eu: goto P_0c07755e;
case 0x0c077560u: goto P_0c077560;
case 0x0c077562u: goto P_0c077562;
case 0x0c077564u: goto P_0c077564;
case 0x0c077566u: goto P_0c077566;
case 0x0c077568u: goto P_0c077568;
case 0x0c07756au: goto P_0c07756a;
case 0x0c077584u: goto P_0c077584;
case 0x0c077586u: goto P_0c077586;
case 0x0c077588u: goto P_0c077588;
case 0x0c07758au: goto P_0c07758a;
case 0x0c07758cu: goto P_0c07758c;
case 0x0c07758eu: goto P_0c07758e;
case 0x0c077590u: goto P_0c077590;
case 0x0c077592u: goto P_0c077592;
case 0x0c077594u: goto P_0c077594;
case 0x0c077596u: goto P_0c077596;
case 0x0c077598u: goto P_0c077598;
case 0x0c07759au: goto P_0c07759a;
case 0x0c07759cu: goto P_0c07759c;
case 0x0c07759eu: goto P_0c07759e;
case 0x0c0775a0u: goto P_0c0775a0;
case 0x0c0775a2u: goto P_0c0775a2;
case 0x0c0775a4u: goto P_0c0775a4;
case 0x0c0775a6u: goto P_0c0775a6;
case 0x0c0775a8u: goto P_0c0775a8;
case 0x0c0775aau: goto P_0c0775aa;
case 0x0c0775acu: goto P_0c0775ac;
case 0x0c0775aeu: goto P_0c0775ae;
case 0x0c0775b0u: goto P_0c0775b0;
case 0x0c0775b2u: goto P_0c0775b2;
case 0x0c0775b4u: goto P_0c0775b4;
case 0x0c0775b6u: goto P_0c0775b6;
case 0x0c0775b8u: goto P_0c0775b8;
case 0x0c0775bau: goto P_0c0775ba;
case 0x0c0775bcu: goto P_0c0775bc;
case 0x0c0775beu: goto P_0c0775be;
case 0x0c0775c0u: goto P_0c0775c0;
case 0x0c0775c2u: goto P_0c0775c2;
case 0x0c0775c4u: goto P_0c0775c4;
case 0x0c0775c6u: goto P_0c0775c6;
case 0x0c0775c8u: goto P_0c0775c8;
case 0x0c0775cau: goto P_0c0775ca;
case 0x0c0775ccu: goto P_0c0775cc;
case 0x0c0775ceu: goto P_0c0775ce;
case 0x0c0775d0u: goto P_0c0775d0;
case 0x0c0775d2u: goto P_0c0775d2;
case 0x0c0775d4u: goto P_0c0775d4;
case 0x0c0775d6u: goto P_0c0775d6;
case 0x0c0775d8u: goto P_0c0775d8;
case 0x0c0775dau: goto P_0c0775da;
case 0x0c0775dcu: goto P_0c0775dc;
case 0x0c0775deu: goto P_0c0775de;
case 0x0c0775e0u: goto P_0c0775e0;
case 0x0c0775e2u: goto P_0c0775e2;
case 0x0c0775e4u: goto P_0c0775e4;
case 0x0c0775e6u: goto P_0c0775e6;
case 0x0c0775e8u: goto P_0c0775e8;
case 0x0c0775eau: goto P_0c0775ea;
case 0x0c0775ecu: goto P_0c0775ec;
case 0x0c0775eeu: goto P_0c0775ee;
case 0x0c0775f0u: goto P_0c0775f0;
case 0x0c0775f2u: goto P_0c0775f2;
case 0x0c0775f4u: goto P_0c0775f4;
case 0x0c0775f6u: goto P_0c0775f6;
case 0x0c0775f8u: goto P_0c0775f8;
case 0x0c0775fau: goto P_0c0775fa;
case 0x0c0775fcu: goto P_0c0775fc;
case 0x0c077614u: goto P_0c077614;
case 0x0c077616u: goto P_0c077616;
case 0x0c077618u: goto P_0c077618;
case 0x0c07761au: goto P_0c07761a;
case 0x0c07761cu: goto P_0c07761c;
case 0x0c07761eu: goto P_0c07761e;
case 0x0c077620u: goto P_0c077620;
case 0x0c077622u: goto P_0c077622;
case 0x0c077624u: goto P_0c077624;
case 0x0c077626u: goto P_0c077626;
case 0x0c077628u: goto P_0c077628;
case 0x0c07762au: goto P_0c07762a;
case 0x0c07762cu: goto P_0c07762c;
case 0x0c07762eu: goto P_0c07762e;
case 0x0c077630u: goto P_0c077630;
case 0x0c077632u: goto P_0c077632;
case 0x0c077634u: goto P_0c077634;
case 0x0c077636u: goto P_0c077636;
case 0x0c077638u: goto P_0c077638;
case 0x0c07763au: goto P_0c07763a;
case 0x0c07763cu: goto P_0c07763c;
case 0x0c07763eu: goto P_0c07763e;
case 0x0c077640u: goto P_0c077640;
case 0x0c077642u: goto P_0c077642;
case 0x0c077644u: goto P_0c077644;
case 0x0c077646u: goto P_0c077646;
case 0x0c077648u: goto P_0c077648;
case 0x0c07764au: goto P_0c07764a;
case 0x0c07764cu: goto P_0c07764c;
case 0x0c07764eu: goto P_0c07764e;
case 0x0c077650u: goto P_0c077650;
case 0x0c077652u: goto P_0c077652;
case 0x0c077654u: goto P_0c077654;
case 0x0c077656u: goto P_0c077656;
case 0x0c077658u: goto P_0c077658;
case 0x0c07765au: goto P_0c07765a;
case 0x0c07765cu: goto P_0c07765c;
case 0x0c07765eu: goto P_0c07765e;
case 0x0c077660u: goto P_0c077660;
case 0x0c077662u: goto P_0c077662;
case 0x0c077664u: goto P_0c077664;
case 0x0c077666u: goto P_0c077666;
case 0x0c077668u: goto P_0c077668;
case 0x0c07766au: goto P_0c07766a;
case 0x0c07766cu: goto P_0c07766c;
case 0x0c07766eu: goto P_0c07766e;
case 0x0c077670u: goto P_0c077670;
case 0x0c077672u: goto P_0c077672;
case 0x0c077674u: goto P_0c077674;
case 0x0c077676u: goto P_0c077676;
case 0x0c077678u: goto P_0c077678;
case 0x0c07767au: goto P_0c07767a;
case 0x0c07767cu: goto P_0c07767c;
case 0x0c07767eu: goto P_0c07767e;
case 0x0c077680u: goto P_0c077680;
case 0x0c077682u: goto P_0c077682;
case 0x0c077684u: goto P_0c077684;
case 0x0c077686u: goto P_0c077686;
case 0x0c077688u: goto P_0c077688;
case 0x0c07768au: goto P_0c07768a;
case 0x0c07768cu: goto P_0c07768c;
case 0x0c07768eu: goto P_0c07768e;
case 0x0c077690u: goto P_0c077690;
case 0x0c077692u: goto P_0c077692;
case 0x0c077694u: goto P_0c077694;
case 0x0c077696u: goto P_0c077696;
case 0x0c077698u: goto P_0c077698;
case 0x0c07769au: goto P_0c07769a;
case 0x0c07769cu: goto P_0c07769c;
case 0x0c07769eu: goto P_0c07769e;
case 0x0c0776a0u: goto P_0c0776a0;
case 0x0c0776a2u: goto P_0c0776a2;
case 0x0c0776a4u: goto P_0c0776a4;
case 0x0c0776a6u: goto P_0c0776a6;
case 0x0c0776a8u: goto P_0c0776a8;
case 0x0c0776aau: goto P_0c0776aa;
case 0x0c0776acu: goto P_0c0776ac;
case 0x0c0776aeu: goto P_0c0776ae;
case 0x0c0776b0u: goto P_0c0776b0;
case 0x0c0776b2u: goto P_0c0776b2;
case 0x0c0776b4u: goto P_0c0776b4;
case 0x0c0776b6u: goto P_0c0776b6;
case 0x0c0776b8u: goto P_0c0776b8;
case 0x0c0776bau: goto P_0c0776ba;
case 0x0c0776bcu: goto P_0c0776bc;
case 0x0c0776beu: goto P_0c0776be;
case 0x0c0776c0u: goto P_0c0776c0;
case 0x0c0776c2u: goto P_0c0776c2;
case 0x0c0776c4u: goto P_0c0776c4;
case 0x0c0776c6u: goto P_0c0776c6;
case 0x0c0776c8u: goto P_0c0776c8;
case 0x0c0776cau: goto P_0c0776ca;
case 0x0c0776ccu: goto P_0c0776cc;
case 0x0c0776ceu: goto P_0c0776ce;
case 0x0c0776d0u: goto P_0c0776d0;
case 0x0c0776d2u: goto P_0c0776d2;
case 0x0c0776d4u: goto P_0c0776d4;
case 0x0c0776d6u: goto P_0c0776d6;
case 0x0c0776d8u: goto P_0c0776d8;
case 0x0c0776dau: goto P_0c0776da;
case 0x0c0776dcu: goto P_0c0776dc;
case 0x0c0776deu: goto P_0c0776de;
case 0x0c0776e0u: goto P_0c0776e0;
case 0x0c0776e2u: goto P_0c0776e2;
case 0x0c0776e4u: goto P_0c0776e4;
case 0x0c0776e6u: goto P_0c0776e6;
case 0x0c0776e8u: goto P_0c0776e8;
case 0x0c0776eau: goto P_0c0776ea;
case 0x0c0776ecu: goto P_0c0776ec;
case 0x0c0776eeu: goto P_0c0776ee;
case 0x0c0776f0u: goto P_0c0776f0;
case 0x0c0776f2u: goto P_0c0776f2;
case 0x0c0776f4u: goto P_0c0776f4;
case 0x0c0776f6u: goto P_0c0776f6;
case 0x0c0776f8u: goto P_0c0776f8;
case 0x0c0776fau: goto P_0c0776fa;
case 0x0c0776fcu: goto P_0c0776fc;
case 0x0c0776feu: goto P_0c0776fe;
case 0x0c077700u: goto P_0c077700;
case 0x0c077702u: goto P_0c077702;
case 0x0c077704u: goto P_0c077704;
case 0x0c077706u: goto P_0c077706;
case 0x0c077708u: goto P_0c077708;
case 0x0c07770au: goto P_0c07770a;
case 0x0c07770cu: goto P_0c07770c;
case 0x0c07770eu: goto P_0c07770e;
case 0x0c077710u: goto P_0c077710;
case 0x0c077712u: goto P_0c077712;
case 0x0c077714u: goto P_0c077714;
case 0x0c077716u: goto P_0c077716;
case 0x0c077718u: goto P_0c077718;
case 0x0c07771au: goto P_0c07771a;
case 0x0c07771cu: goto P_0c07771c;
case 0x0c07771eu: goto P_0c07771e;
case 0x0c077720u: goto P_0c077720;
case 0x0c077722u: goto P_0c077722;
case 0x0c077724u: goto P_0c077724;
case 0x0c077726u: goto P_0c077726;
case 0x0c077728u: goto P_0c077728;
case 0x0c07772au: goto P_0c07772a;
case 0x0c07772cu: goto P_0c07772c;
case 0x0c07772eu: goto P_0c07772e;
case 0x0c077730u: goto P_0c077730;
case 0x0c077732u: goto P_0c077732;
case 0x0c077734u: goto P_0c077734;
case 0x0c077736u: goto P_0c077736;
case 0x0c077738u: goto P_0c077738;
case 0x0c07773au: goto P_0c07773a;
case 0x0c07773cu: goto P_0c07773c;
case 0x0c07773eu: goto P_0c07773e;
case 0x0c077740u: goto P_0c077740;
case 0x0c077742u: goto P_0c077742;
case 0x0c077744u: goto P_0c077744;
case 0x0c077746u: goto P_0c077746;
case 0x0c077748u: goto P_0c077748;
case 0x0c07774au: goto P_0c07774a;
case 0x0c07774cu: goto P_0c07774c;
case 0x0c07774eu: goto P_0c07774e;
case 0x0c077750u: goto P_0c077750;
case 0x0c077752u: goto P_0c077752;
case 0x0c077754u: goto P_0c077754;
case 0x0c077756u: goto P_0c077756;
case 0x0c077758u: goto P_0c077758;
case 0x0c07775au: goto P_0c07775a;
case 0x0c07775cu: goto P_0c07775c;
case 0x0c07775eu: goto P_0c07775e;
case 0x0c077760u: goto P_0c077760;
case 0x0c077762u: goto P_0c077762;
case 0x0c077764u: goto P_0c077764;
case 0x0c077784u: goto P_0c077784;
case 0x0c077786u: goto P_0c077786;
case 0x0c077788u: goto P_0c077788;
case 0x0c07778au: goto P_0c07778a;
case 0x0c07778cu: goto P_0c07778c;
case 0x0c07778eu: goto P_0c07778e;
case 0x0c077790u: goto P_0c077790;
case 0x0c077792u: goto P_0c077792;
case 0x0c077794u: goto P_0c077794;
case 0x0c077796u: goto P_0c077796;
case 0x0c077798u: goto P_0c077798;
case 0x0c07779au: goto P_0c07779a;
case 0x0c07779cu: goto P_0c07779c;
case 0x0c07779eu: goto P_0c07779e;
case 0x0c0777a0u: goto P_0c0777a0;
case 0x0c0777a2u: goto P_0c0777a2;
case 0x0c0777a4u: goto P_0c0777a4;
case 0x0c0777a6u: goto P_0c0777a6;
case 0x0c0777a8u: goto P_0c0777a8;
case 0x0c0777aau: goto P_0c0777aa;
case 0x0c0777acu: goto P_0c0777ac;
case 0x0c0777aeu: goto P_0c0777ae;
case 0x0c0777b0u: goto P_0c0777b0;
case 0x0c0777b2u: goto P_0c0777b2;
case 0x0c0777b4u: goto P_0c0777b4;
case 0x0c0777b6u: goto P_0c0777b6;
case 0x0c0777b8u: goto P_0c0777b8;
case 0x0c0777bau: goto P_0c0777ba;
case 0x0c0777bcu: goto P_0c0777bc;
case 0x0c0777beu: goto P_0c0777be;
case 0x0c0777c0u: goto P_0c0777c0;
case 0x0c0777c2u: goto P_0c0777c2;
case 0x0c0777c4u: goto P_0c0777c4;
case 0x0c0777c6u: goto P_0c0777c6;
case 0x0c0777c8u: goto P_0c0777c8;
case 0x0c0777cau: goto P_0c0777ca;
case 0x0c0777ccu: goto P_0c0777cc;
case 0x0c0777ceu: goto P_0c0777ce;
case 0x0c0777d0u: goto P_0c0777d0;
case 0x0c0777d2u: goto P_0c0777d2;
case 0x0c0777d4u: goto P_0c0777d4;
case 0x0c0777d6u: goto P_0c0777d6;
case 0x0c0777d8u: goto P_0c0777d8;
case 0x0c0777dau: goto P_0c0777da;
case 0x0c0777dcu: goto P_0c0777dc;
case 0x0c0777deu: goto P_0c0777de;
case 0x0c0777e0u: goto P_0c0777e0;
case 0x0c0777e2u: goto P_0c0777e2;
case 0x0c0777e4u: goto P_0c0777e4;
case 0x0c0777e6u: goto P_0c0777e6;
case 0x0c0777e8u: goto P_0c0777e8;
case 0x0c0777eau: goto P_0c0777ea;
case 0x0c0777ecu: goto P_0c0777ec;
case 0x0c0777eeu: goto P_0c0777ee;
case 0x0c0777f0u: goto P_0c0777f0;
case 0x0c0777f2u: goto P_0c0777f2;
case 0x0c0777f4u: goto P_0c0777f4;
case 0x0c0777f6u: goto P_0c0777f6;
case 0x0c0777f8u: goto P_0c0777f8;
case 0x0c0777fau: goto P_0c0777fa;
case 0x0c0777fcu: goto P_0c0777fc;
case 0x0c0777feu: goto P_0c0777fe;
case 0x0c077800u: goto P_0c077800;
case 0x0c077802u: goto P_0c077802;
case 0x0c077804u: goto P_0c077804;
case 0x0c077806u: goto P_0c077806;
case 0x0c077808u: goto P_0c077808;
case 0x0c07780au: goto P_0c07780a;
case 0x0c07780cu: goto P_0c07780c;
case 0x0c07780eu: goto P_0c07780e;
case 0x0c077810u: goto P_0c077810;
case 0x0c077812u: goto P_0c077812;
case 0x0c077814u: goto P_0c077814;
case 0x0c077816u: goto P_0c077816;
case 0x0c077818u: goto P_0c077818;
case 0x0c07781au: goto P_0c07781a;
case 0x0c07781cu: goto P_0c07781c;
case 0x0c07781eu: goto P_0c07781e;
case 0x0c077820u: goto P_0c077820;
case 0x0c077822u: goto P_0c077822;
case 0x0c077824u: goto P_0c077824;
case 0x0c077826u: goto P_0c077826;
case 0x0c077828u: goto P_0c077828;
case 0x0c07782au: goto P_0c07782a;
case 0x0c07782cu: goto P_0c07782c;
case 0x0c07782eu: goto P_0c07782e;
case 0x0c077830u: goto P_0c077830;
case 0x0c077832u: goto P_0c077832;
case 0x0c077834u: goto P_0c077834;
case 0x0c077836u: goto P_0c077836;
case 0x0c077838u: goto P_0c077838;
case 0x0c07783au: goto P_0c07783a;
case 0x0c07783cu: goto P_0c07783c;
case 0x0c07783eu: goto P_0c07783e;
case 0x0c077840u: goto P_0c077840;
case 0x0c077842u: goto P_0c077842;
case 0x0c077844u: goto P_0c077844;
case 0x0c077846u: goto P_0c077846;
case 0x0c077848u: goto P_0c077848;
case 0x0c07784au: goto P_0c07784a;
case 0x0c07784cu: goto P_0c07784c;
case 0x0c07784eu: goto P_0c07784e;
case 0x0c077850u: goto P_0c077850;
case 0x0c077852u: goto P_0c077852;
case 0x0c077854u: goto P_0c077854;
case 0x0c077856u: goto P_0c077856;
case 0x0c077858u: goto P_0c077858;
case 0x0c07785au: goto P_0c07785a;
case 0x0c07785cu: goto P_0c07785c;
case 0x0c07785eu: goto P_0c07785e;
case 0x0c077860u: goto P_0c077860;
case 0x0c077862u: goto P_0c077862;
case 0x0c077864u: goto P_0c077864;
case 0x0c077866u: goto P_0c077866;
case 0x0c077868u: goto P_0c077868;
case 0x0c07786au: goto P_0c07786a;
case 0x0c07786cu: goto P_0c07786c;
case 0x0c07786eu: goto P_0c07786e;
case 0x0c077870u: goto P_0c077870;
case 0x0c077872u: goto P_0c077872;
case 0x0c077874u: goto P_0c077874;
case 0x0c077876u: goto P_0c077876;
case 0x0c077878u: goto P_0c077878;
case 0x0c07787au: goto P_0c07787a;
case 0x0c07787cu: goto P_0c07787c;
case 0x0c07787eu: goto P_0c07787e;
case 0x0c077880u: goto P_0c077880;
case 0x0c077882u: goto P_0c077882;
case 0x0c077884u: goto P_0c077884;
case 0x0c077886u: goto P_0c077886;
case 0x0c077888u: goto P_0c077888;
case 0x0c07788au: goto P_0c07788a;
case 0x0c0778a4u: goto P_0c0778a4;
case 0x0c0778a6u: goto P_0c0778a6;
case 0x0c0778a8u: goto P_0c0778a8;
case 0x0c0778aau: goto P_0c0778aa;
case 0x0c0778acu: goto P_0c0778ac;
case 0x0c0778aeu: goto P_0c0778ae;
case 0x0c0778b0u: goto P_0c0778b0;
case 0x0c0778b2u: goto P_0c0778b2;
case 0x0c0778b4u: goto P_0c0778b4;
case 0x0c0778b6u: goto P_0c0778b6;
case 0x0c0778b8u: goto P_0c0778b8;
case 0x0c0778bau: goto P_0c0778ba;
case 0x0c0778bcu: goto P_0c0778bc;
case 0x0c0778beu: goto P_0c0778be;
case 0x0c0778c0u: goto P_0c0778c0;
case 0x0c0778c2u: goto P_0c0778c2;
case 0x0c0778c4u: goto P_0c0778c4;
case 0x0c0778c6u: goto P_0c0778c6;
case 0x0c0778c8u: goto P_0c0778c8;
case 0x0c0778cau: goto P_0c0778ca;
case 0x0c0778ccu: goto P_0c0778cc;
case 0x0c0778ceu: goto P_0c0778ce;
case 0x0c0778d0u: goto P_0c0778d0;
case 0x0c0778d2u: goto P_0c0778d2;
case 0x0c0778d4u: goto P_0c0778d4;
case 0x0c0778d6u: goto P_0c0778d6;
case 0x0c0778d8u: goto P_0c0778d8;
case 0x0c0778dau: goto P_0c0778da;
case 0x0c0778dcu: goto P_0c0778dc;
case 0x0c0778deu: goto P_0c0778de;
case 0x0c0778e0u: goto P_0c0778e0;
case 0x0c0778e2u: goto P_0c0778e2;
case 0x0c0778e4u: goto P_0c0778e4;
case 0x0c0778e6u: goto P_0c0778e6;
case 0x0c0778e8u: goto P_0c0778e8;
case 0x0c0778eau: goto P_0c0778ea;
case 0x0c0778ecu: goto P_0c0778ec;
case 0x0c0778eeu: goto P_0c0778ee;
case 0x0c0778f0u: goto P_0c0778f0;
case 0x0c0778f2u: goto P_0c0778f2;
case 0x0c0778f4u: goto P_0c0778f4;
case 0x0c0778f6u: goto P_0c0778f6;
case 0x0c0778f8u: goto P_0c0778f8;
case 0x0c0778fau: goto P_0c0778fa;
case 0x0c0778fcu: goto P_0c0778fc;
case 0x0c0778feu: goto P_0c0778fe;
case 0x0c077900u: goto P_0c077900;
case 0x0c077902u: goto P_0c077902;
case 0x0c077904u: goto P_0c077904;
case 0x0c077906u: goto P_0c077906;
case 0x0c077908u: goto P_0c077908;
case 0x0c07790au: goto P_0c07790a;
case 0x0c07790cu: goto P_0c07790c;
case 0x0c07790eu: goto P_0c07790e;
case 0x0c077910u: goto P_0c077910;
case 0x0c077912u: goto P_0c077912;
case 0x0c077914u: goto P_0c077914;
case 0x0c077916u: goto P_0c077916;
case 0x0c077918u: goto P_0c077918;
case 0x0c07791au: goto P_0c07791a;
case 0x0c07791cu: goto P_0c07791c;
case 0x0c07791eu: goto P_0c07791e;
case 0x0c077920u: goto P_0c077920;
case 0x0c077922u: goto P_0c077922;
case 0x0c077924u: goto P_0c077924;
case 0x0c077926u: goto P_0c077926;
case 0x0c077928u: goto P_0c077928;
case 0x0c07792au: goto P_0c07792a;
case 0x0c07792cu: goto P_0c07792c;
case 0x0c07792eu: goto P_0c07792e;
case 0x0c077930u: goto P_0c077930;
case 0x0c077932u: goto P_0c077932;
case 0x0c077934u: goto P_0c077934;
case 0x0c077936u: goto P_0c077936;
case 0x0c077938u: goto P_0c077938;
case 0x0c07793au: goto P_0c07793a;
case 0x0c07793cu: goto P_0c07793c;
case 0x0c07793eu: goto P_0c07793e;
case 0x0c077940u: goto P_0c077940;
case 0x0c077942u: goto P_0c077942;
case 0x0c077944u: goto P_0c077944;
case 0x0c077946u: goto P_0c077946;
case 0x0c077948u: goto P_0c077948;
case 0x0c07794au: goto P_0c07794a;
case 0x0c07794cu: goto P_0c07794c;
case 0x0c07794eu: goto P_0c07794e;
case 0x0c077950u: goto P_0c077950;
case 0x0c077952u: goto P_0c077952;
case 0x0c077954u: goto P_0c077954;
case 0x0c077956u: goto P_0c077956;
case 0x0c077958u: goto P_0c077958;
case 0x0c07795au: goto P_0c07795a;
case 0x0c07795cu: goto P_0c07795c;
case 0x0c07795eu: goto P_0c07795e;
case 0x0c077960u: goto P_0c077960;
case 0x0c077962u: goto P_0c077962;
case 0x0c077964u: goto P_0c077964;
case 0x0c077966u: goto P_0c077966;
case 0x0c077968u: goto P_0c077968;
case 0x0c07796au: goto P_0c07796a;
case 0x0c07796cu: goto P_0c07796c;
case 0x0c07796eu: goto P_0c07796e;
case 0x0c077970u: goto P_0c077970;
case 0x0c077972u: goto P_0c077972;
case 0x0c077974u: goto P_0c077974;
case 0x0c077976u: goto P_0c077976;
case 0x0c077978u: goto P_0c077978;
case 0x0c07797au: goto P_0c07797a;
case 0x0c07797cu: goto P_0c07797c;
case 0x0c07797eu: goto P_0c07797e;
case 0x0c077980u: goto P_0c077980;
case 0x0c077998u: goto P_0c077998;
case 0x0c07799au: goto P_0c07799a;
case 0x0c07799cu: goto P_0c07799c;
case 0x0c07799eu: goto P_0c07799e;
case 0x0c0779a0u: goto P_0c0779a0;
case 0x0c0779a2u: goto P_0c0779a2;
case 0x0c0779a4u: goto P_0c0779a4;
case 0x0c0779a6u: goto P_0c0779a6;
case 0x0c0779a8u: goto P_0c0779a8;
case 0x0c0779aau: goto P_0c0779aa;
case 0x0c0779acu: goto P_0c0779ac;
case 0x0c0779aeu: goto P_0c0779ae;
case 0x0c0779b0u: goto P_0c0779b0;
case 0x0c0779b2u: goto P_0c0779b2;
case 0x0c0779b4u: goto P_0c0779b4;
case 0x0c0779b6u: goto P_0c0779b6;
case 0x0c0779b8u: goto P_0c0779b8;
case 0x0c0779bau: goto P_0c0779ba;
case 0x0c0779bcu: goto P_0c0779bc;
case 0x0c0779beu: goto P_0c0779be;
case 0x0c0779c0u: goto P_0c0779c0;
case 0x0c0779c2u: goto P_0c0779c2;
case 0x0c0779c4u: goto P_0c0779c4;
case 0x0c0779c6u: goto P_0c0779c6;
case 0x0c0779c8u: goto P_0c0779c8;
case 0x0c0779cau: goto P_0c0779ca;
case 0x0c0779ccu: goto P_0c0779cc;
case 0x0c0779ceu: goto P_0c0779ce;
case 0x0c0779d0u: goto P_0c0779d0;
case 0x0c0779d2u: goto P_0c0779d2;
case 0x0c0779d4u: goto P_0c0779d4;
case 0x0c0779d6u: goto P_0c0779d6;
case 0x0c0779d8u: goto P_0c0779d8;
case 0x0c0779dau: goto P_0c0779da;
case 0x0c0779dcu: goto P_0c0779dc;
case 0x0c0779deu: goto P_0c0779de;
case 0x0c0779e0u: goto P_0c0779e0;
case 0x0c0779e2u: goto P_0c0779e2;
case 0x0c0779e4u: goto P_0c0779e4;
case 0x0c0779e6u: goto P_0c0779e6;
case 0x0c0779e8u: goto P_0c0779e8;
case 0x0c0779eau: goto P_0c0779ea;
case 0x0c0779ecu: goto P_0c0779ec;
case 0x0c0779eeu: goto P_0c0779ee;
case 0x0c0779f0u: goto P_0c0779f0;
case 0x0c0779f2u: goto P_0c0779f2;
case 0x0c0779f4u: goto P_0c0779f4;
case 0x0c0779f6u: goto P_0c0779f6;
case 0x0c0779f8u: goto P_0c0779f8;
case 0x0c0779fau: goto P_0c0779fa;
case 0x0c0779fcu: goto P_0c0779fc;
case 0x0c0779feu: goto P_0c0779fe;
case 0x0c077a00u: goto P_0c077a00;
case 0x0c077a02u: goto P_0c077a02;
case 0x0c077a04u: goto P_0c077a04;
case 0x0c077a06u: goto P_0c077a06;
case 0x0c077a08u: goto P_0c077a08;
case 0x0c077a0au: goto P_0c077a0a;
case 0x0c077a0cu: goto P_0c077a0c;
case 0x0c077a0eu: goto P_0c077a0e;
case 0x0c077a10u: goto P_0c077a10;
case 0x0c077a12u: goto P_0c077a12;
case 0x0c077a14u: goto P_0c077a14;
case 0x0c077a16u: goto P_0c077a16;
case 0x0c077a18u: goto P_0c077a18;
case 0x0c077a1au: goto P_0c077a1a;
case 0x0c077a1cu: goto P_0c077a1c;
case 0x0c077a1eu: goto P_0c077a1e;
case 0x0c077a20u: goto P_0c077a20;
case 0x0c077a22u: goto P_0c077a22;
case 0x0c077a24u: goto P_0c077a24;
case 0x0c077a26u: goto P_0c077a26;
case 0x0c077a28u: goto P_0c077a28;
case 0x0c077a2au: goto P_0c077a2a;
case 0x0c077a2cu: goto P_0c077a2c;
case 0x0c077a2eu: goto P_0c077a2e;
case 0x0c077a30u: goto P_0c077a30;
case 0x0c077a32u: goto P_0c077a32;
case 0x0c077a34u: goto P_0c077a34;
case 0x0c077a36u: goto P_0c077a36;
case 0x0c077a38u: goto P_0c077a38;
case 0x0c077a3au: goto P_0c077a3a;
case 0x0c077a3cu: goto P_0c077a3c;
case 0x0c077a3eu: goto P_0c077a3e;
case 0x0c077a40u: goto P_0c077a40;
case 0x0c077a42u: goto P_0c077a42;
case 0x0c077a44u: goto P_0c077a44;
case 0x0c077a46u: goto P_0c077a46;
case 0x0c077a48u: goto P_0c077a48;
case 0x0c077a4au: goto P_0c077a4a;
case 0x0c077a4cu: goto P_0c077a4c;
case 0x0c077a4eu: goto P_0c077a4e;
case 0x0c077a50u: goto P_0c077a50;
case 0x0c077a52u: goto P_0c077a52;
case 0x0c077a54u: goto P_0c077a54;
case 0x0c077a56u: goto P_0c077a56;
case 0x0c077a58u: goto P_0c077a58;
case 0x0c077a5au: goto P_0c077a5a;
case 0x0c077a5cu: goto P_0c077a5c;
case 0x0c077a5eu: goto P_0c077a5e;
case 0x0c077a60u: goto P_0c077a60;
case 0x0c077a62u: goto P_0c077a62;
case 0x0c077a64u: goto P_0c077a64;
case 0x0c077a66u: goto P_0c077a66;
case 0x0c077a68u: goto P_0c077a68;
case 0x0c077a6au: goto P_0c077a6a;
case 0x0c077a6cu: goto P_0c077a6c;
case 0x0c077a6eu: goto P_0c077a6e;
case 0x0c077a70u: goto P_0c077a70;
case 0x0c077a72u: goto P_0c077a72;
case 0x0c077a74u: goto P_0c077a74;
case 0x0c077a76u: goto P_0c077a76;
case 0x0c077a78u: goto P_0c077a78;
case 0x0c077a7au: goto P_0c077a7a;
case 0x0c077a7cu: goto P_0c077a7c;
case 0x0c077a7eu: goto P_0c077a7e;
case 0x0c077a80u: goto P_0c077a80;
case 0x0c077a82u: goto P_0c077a82;
case 0x0c077a84u: goto P_0c077a84;
case 0x0c077a86u: goto P_0c077a86;
case 0x0c077a88u: goto P_0c077a88;
case 0x0c077a8au: goto P_0c077a8a;
case 0x0c077a8cu: goto P_0c077a8c;
case 0x0c077a8eu: goto P_0c077a8e;
case 0x0c077a90u: goto P_0c077a90;
case 0x0c077a92u: goto P_0c077a92;
case 0x0c077a94u: goto P_0c077a94;
case 0x0c077a96u: goto P_0c077a96;
case 0x0c077a98u: goto P_0c077a98;
case 0x0c077a9au: goto P_0c077a9a;
case 0x0c077a9cu: goto P_0c077a9c;
case 0x0c077a9eu: goto P_0c077a9e;
case 0x0c077aa0u: goto P_0c077aa0;
case 0x0c077aa2u: goto P_0c077aa2;
case 0x0c077aa4u: goto P_0c077aa4;
case 0x0c077aa6u: goto P_0c077aa6;
case 0x0c077aa8u: goto P_0c077aa8;
case 0x0c077aaau: goto P_0c077aaa;
case 0x0c077aacu: goto P_0c077aac;
case 0x0c077aaeu: goto P_0c077aae;
case 0x0c077ad0u: goto P_0c077ad0;
case 0x0c077ad2u: goto P_0c077ad2;
case 0x0c077ad4u: goto P_0c077ad4;
case 0x0c077ad6u: goto P_0c077ad6;
case 0x0c077ad8u: goto P_0c077ad8;
case 0x0c077adau: goto P_0c077ada;
case 0x0c077adcu: goto P_0c077adc;
case 0x0c077adeu: goto P_0c077ade;
case 0x0c077ae0u: goto P_0c077ae0;
case 0x0c077ae2u: goto P_0c077ae2;
case 0x0c077ae4u: goto P_0c077ae4;
case 0x0c077ae6u: goto P_0c077ae6;
case 0x0c077ae8u: goto P_0c077ae8;
case 0x0c077aeau: goto P_0c077aea;
case 0x0c077aecu: goto P_0c077aec;
case 0x0c077aeeu: goto P_0c077aee;
case 0x0c077af0u: goto P_0c077af0;
case 0x0c077af2u: goto P_0c077af2;
case 0x0c077af4u: goto P_0c077af4;
case 0x0c077af6u: goto P_0c077af6;
case 0x0c077af8u: goto P_0c077af8;
case 0x0c077afau: goto P_0c077afa;
case 0x0c077afcu: goto P_0c077afc;
case 0x0c077afeu: goto P_0c077afe;
case 0x0c077b00u: goto P_0c077b00;
case 0x0c077b02u: goto P_0c077b02;
case 0x0c077b04u: goto P_0c077b04;
case 0x0c077b06u: goto P_0c077b06;
case 0x0c077b08u: goto P_0c077b08;
case 0x0c077b0au: goto P_0c077b0a;
case 0x0c077b0cu: goto P_0c077b0c;
case 0x0c077b0eu: goto P_0c077b0e;
case 0x0c077b10u: goto P_0c077b10;
case 0x0c077b12u: goto P_0c077b12;
case 0x0c077b14u: goto P_0c077b14;
case 0x0c077b16u: goto P_0c077b16;
case 0x0c077b18u: goto P_0c077b18;
case 0x0c077b1au: goto P_0c077b1a;
case 0x0c077b1cu: goto P_0c077b1c;
case 0x0c077b1eu: goto P_0c077b1e;
case 0x0c077b20u: goto P_0c077b20;
case 0x0c077b22u: goto P_0c077b22;
case 0x0c077b24u: goto P_0c077b24;
case 0x0c077b26u: goto P_0c077b26;
case 0x0c077b28u: goto P_0c077b28;
case 0x0c077b2au: goto P_0c077b2a;
case 0x0c077b2cu: goto P_0c077b2c;
case 0x0c077b2eu: goto P_0c077b2e;
case 0x0c077b30u: goto P_0c077b30;
case 0x0c077b32u: goto P_0c077b32;
case 0x0c077b34u: goto P_0c077b34;
case 0x0c077b36u: goto P_0c077b36;
case 0x0c077b38u: goto P_0c077b38;
case 0x0c077b3au: goto P_0c077b3a;
case 0x0c077b3cu: goto P_0c077b3c;
case 0x0c077b3eu: goto P_0c077b3e;
case 0x0c077b40u: goto P_0c077b40;
case 0x0c077b42u: goto P_0c077b42;
case 0x0c077b44u: goto P_0c077b44;
case 0x0c077b46u: goto P_0c077b46;
case 0x0c077b48u: goto P_0c077b48;
case 0x0c077b4au: goto P_0c077b4a;
case 0x0c077b4cu: goto P_0c077b4c;
case 0x0c077b4eu: goto P_0c077b4e;
case 0x0c077b50u: goto P_0c077b50;
case 0x0c077b52u: goto P_0c077b52;
case 0x0c077b54u: goto P_0c077b54;
case 0x0c077b56u: goto P_0c077b56;
case 0x0c077b58u: goto P_0c077b58;
case 0x0c077b5au: goto P_0c077b5a;
case 0x0c077b5cu: goto P_0c077b5c;
case 0x0c077b5eu: goto P_0c077b5e;
case 0x0c077b60u: goto P_0c077b60;
case 0x0c077b62u: goto P_0c077b62;
case 0x0c077b64u: goto P_0c077b64;
case 0x0c077b66u: goto P_0c077b66;
case 0x0c077b68u: goto P_0c077b68;
case 0x0c077b6au: goto P_0c077b6a;
case 0x0c077b6cu: goto P_0c077b6c;
case 0x0c077b6eu: goto P_0c077b6e;
case 0x0c077b70u: goto P_0c077b70;
case 0x0c077b72u: goto P_0c077b72;
case 0x0c077b74u: goto P_0c077b74;
case 0x0c077b76u: goto P_0c077b76;
case 0x0c077b78u: goto P_0c077b78;
case 0x0c077b7au: goto P_0c077b7a;
case 0x0c077b7cu: goto P_0c077b7c;
case 0x0c077b7eu: goto P_0c077b7e;
case 0x0c077b80u: goto P_0c077b80;
case 0x0c077b82u: goto P_0c077b82;
case 0x0c077b84u: goto P_0c077b84;
case 0x0c077b86u: goto P_0c077b86;
case 0x0c077b88u: goto P_0c077b88;
case 0x0c077b8au: goto P_0c077b8a;
case 0x0c077b8cu: goto P_0c077b8c;
case 0x0c077b8eu: goto P_0c077b8e;
case 0x0c077b90u: goto P_0c077b90;
case 0x0c077b92u: goto P_0c077b92;
case 0x0c077b94u: goto P_0c077b94;
case 0x0c077b96u: goto P_0c077b96;
case 0x0c077b98u: goto P_0c077b98;
case 0x0c077b9au: goto P_0c077b9a;
case 0x0c077b9cu: goto P_0c077b9c;
case 0x0c077b9eu: goto P_0c077b9e;
case 0x0c077bbcu: goto P_0c077bbc;
case 0x0c077bbeu: goto P_0c077bbe;
case 0x0c077bc0u: goto P_0c077bc0;
case 0x0c077bc2u: goto P_0c077bc2;
case 0x0c077bc4u: goto P_0c077bc4;
case 0x0c077bc6u: goto P_0c077bc6;
case 0x0c077bc8u: goto P_0c077bc8;
case 0x0c077bcau: goto P_0c077bca;
case 0x0c077bccu: goto P_0c077bcc;
case 0x0c077bceu: goto P_0c077bce;
case 0x0c077bd0u: goto P_0c077bd0;
case 0x0c077bd2u: goto P_0c077bd2;
case 0x0c077bd4u: goto P_0c077bd4;
case 0x0c077bd6u: goto P_0c077bd6;
case 0x0c077bd8u: goto P_0c077bd8;
case 0x0c077bdau: goto P_0c077bda;
case 0x0c077bdcu: goto P_0c077bdc;
case 0x0c077bdeu: goto P_0c077bde;
case 0x0c077be0u: goto P_0c077be0;
case 0x0c077be2u: goto P_0c077be2;
case 0x0c077be4u: goto P_0c077be4;
case 0x0c077be6u: goto P_0c077be6;
case 0x0c077be8u: goto P_0c077be8;
case 0x0c077beau: goto P_0c077bea;
case 0x0c077becu: goto P_0c077bec;
case 0x0c077beeu: goto P_0c077bee;
case 0x0c077bf0u: goto P_0c077bf0;
case 0x0c077bf2u: goto P_0c077bf2;
case 0x0c077bf4u: goto P_0c077bf4;
case 0x0c077bf6u: goto P_0c077bf6;
case 0x0c077bf8u: goto P_0c077bf8;
case 0x0c077bfau: goto P_0c077bfa;
case 0x0c077bfcu: goto P_0c077bfc;
case 0x0c077bfeu: goto P_0c077bfe;
case 0x0c077c00u: goto P_0c077c00;
case 0x0c077c02u: goto P_0c077c02;
case 0x0c077c04u: goto P_0c077c04;
case 0x0c077c06u: goto P_0c077c06;
case 0x0c077c08u: goto P_0c077c08;
case 0x0c077c0au: goto P_0c077c0a;
case 0x0c077c0cu: goto P_0c077c0c;
case 0x0c077c0eu: goto P_0c077c0e;
case 0x0c077c10u: goto P_0c077c10;
case 0x0c077c12u: goto P_0c077c12;
case 0x0c077c14u: goto P_0c077c14;
case 0x0c077c16u: goto P_0c077c16;
case 0x0c077c18u: goto P_0c077c18;
case 0x0c077c1au: goto P_0c077c1a;
case 0x0c077c1cu: goto P_0c077c1c;
case 0x0c077c1eu: goto P_0c077c1e;
case 0x0c077c20u: goto P_0c077c20;
case 0x0c077c22u: goto P_0c077c22;
case 0x0c077c24u: goto P_0c077c24;
case 0x0c077c26u: goto P_0c077c26;
case 0x0c077c28u: goto P_0c077c28;
case 0x0c077c2au: goto P_0c077c2a;
case 0x0c077c2cu: goto P_0c077c2c;
case 0x0c077c2eu: goto P_0c077c2e;
case 0x0c077c30u: goto P_0c077c30;
case 0x0c077c32u: goto P_0c077c32;
case 0x0c077c34u: goto P_0c077c34;
case 0x0c077c36u: goto P_0c077c36;
case 0x0c077c38u: goto P_0c077c38;
case 0x0c077c3au: goto P_0c077c3a;
case 0x0c077c3cu: goto P_0c077c3c;
case 0x0c077c3eu: goto P_0c077c3e;
case 0x0c077c40u: goto P_0c077c40;
case 0x0c077c42u: goto P_0c077c42;
case 0x0c077c44u: goto P_0c077c44;
case 0x0c077c46u: goto P_0c077c46;
case 0x0c077c48u: goto P_0c077c48;
case 0x0c077c4au: goto P_0c077c4a;
case 0x0c077c4cu: goto P_0c077c4c;
case 0x0c077c4eu: goto P_0c077c4e;
case 0x0c077c50u: goto P_0c077c50;
case 0x0c077c52u: goto P_0c077c52;
case 0x0c077c54u: goto P_0c077c54;
case 0x0c077c56u: goto P_0c077c56;
case 0x0c077c58u: goto P_0c077c58;
case 0x0c077c5au: goto P_0c077c5a;
case 0x0c077c5cu: goto P_0c077c5c;
case 0x0c077c5eu: goto P_0c077c5e;
case 0x0c077c60u: goto P_0c077c60;
case 0x0c077c62u: goto P_0c077c62;
case 0x0c077c64u: goto P_0c077c64;
case 0x0c077c66u: goto P_0c077c66;
case 0x0c077c68u: goto P_0c077c68;
case 0x0c077c6au: goto P_0c077c6a;
case 0x0c077c6cu: goto P_0c077c6c;
case 0x0c077c6eu: goto P_0c077c6e;
case 0x0c077c70u: goto P_0c077c70;
case 0x0c077c72u: goto P_0c077c72;
case 0x0c077c74u: goto P_0c077c74;
case 0x0c077c76u: goto P_0c077c76;
case 0x0c077c78u: goto P_0c077c78;
case 0x0c077c7au: goto P_0c077c7a;
case 0x0c077c7cu: goto P_0c077c7c;
case 0x0c077c7eu: goto P_0c077c7e;
case 0x0c077c80u: goto P_0c077c80;
case 0x0c077c82u: goto P_0c077c82;
case 0x0c077c84u: goto P_0c077c84;
case 0x0c077c86u: goto P_0c077c86;
case 0x0c077c88u: goto P_0c077c88;
case 0x0c077c8au: goto P_0c077c8a;
case 0x0c077c8cu: goto P_0c077c8c;
case 0x0c077c8eu: goto P_0c077c8e;
case 0x0c077c90u: goto P_0c077c90;
case 0x0c077c92u: goto P_0c077c92;
case 0x0c077c94u: goto P_0c077c94;
case 0x0c077c96u: goto P_0c077c96;
case 0x0c077c98u: goto P_0c077c98;
case 0x0c077c9au: goto P_0c077c9a;
case 0x0c077c9cu: goto P_0c077c9c;
case 0x0c077c9eu: goto P_0c077c9e;
case 0x0c077ca0u: goto P_0c077ca0;
case 0x0c077ca2u: goto P_0c077ca2;
case 0x0c077ca4u: goto P_0c077ca4;
case 0x0c077ca6u: goto P_0c077ca6;
case 0x0c077ca8u: goto P_0c077ca8;
case 0x0c077caau: goto P_0c077caa;
case 0x0c077cacu: goto P_0c077cac;
case 0x0c077caeu: goto P_0c077cae;
case 0x0c077cb0u: goto P_0c077cb0;
case 0x0c077cb2u: goto P_0c077cb2;
case 0x0c077cb4u: goto P_0c077cb4;
case 0x0c077cb6u: goto P_0c077cb6;
case 0x0c077cb8u: goto P_0c077cb8;
case 0x0c077cbau: goto P_0c077cba;
case 0x0c077cbcu: goto P_0c077cbc;
case 0x0c077cbeu: goto P_0c077cbe;
case 0x0c077cc0u: goto P_0c077cc0;
case 0x0c077cc2u: goto P_0c077cc2;
case 0x0c077cc4u: goto P_0c077cc4;
case 0x0c077cc6u: goto P_0c077cc6;
case 0x0c077cc8u: goto P_0c077cc8;
case 0x0c077ccau: goto P_0c077cca;
case 0x0c077cccu: goto P_0c077ccc;
case 0x0c077cceu: goto P_0c077cce;
case 0x0c077cd0u: goto P_0c077cd0;
case 0x0c077cd2u: goto P_0c077cd2;
case 0x0c077cd4u: goto P_0c077cd4;
case 0x0c077cd6u: goto P_0c077cd6;
case 0x0c077cd8u: goto P_0c077cd8;
case 0x0c077cdau: goto P_0c077cda;
case 0x0c077cdcu: goto P_0c077cdc;
case 0x0c077cdeu: goto P_0c077cde;
case 0x0c077ce0u: goto P_0c077ce0;
case 0x0c077ce2u: goto P_0c077ce2;
case 0x0c077ce4u: goto P_0c077ce4;
case 0x0c077ce6u: goto P_0c077ce6;
case 0x0c077ce8u: goto P_0c077ce8;
case 0x0c077ceau: goto P_0c077cea;
case 0x0c077cecu: goto P_0c077cec;
case 0x0c077ceeu: goto P_0c077cee;
case 0x0c077cf0u: goto P_0c077cf0;
case 0x0c077cf2u: goto P_0c077cf2;
case 0x0c077cf4u: goto P_0c077cf4;
case 0x0c077d1cu: goto P_0c077d1c;
case 0x0c077d1eu: goto P_0c077d1e;
case 0x0c077d20u: goto P_0c077d20;
case 0x0c077d22u: goto P_0c077d22;
case 0x0c077d24u: goto P_0c077d24;
case 0x0c077d26u: goto P_0c077d26;
case 0x0c077d28u: goto P_0c077d28;
case 0x0c077d2au: goto P_0c077d2a;
case 0x0c077d2cu: goto P_0c077d2c;
case 0x0c077d2eu: goto P_0c077d2e;
case 0x0c077d30u: goto P_0c077d30;
case 0x0c077d32u: goto P_0c077d32;
case 0x0c077d34u: goto P_0c077d34;
case 0x0c077d36u: goto P_0c077d36;
case 0x0c077d38u: goto P_0c077d38;
case 0x0c077d3au: goto P_0c077d3a;
case 0x0c077d3cu: goto P_0c077d3c;
case 0x0c077d3eu: goto P_0c077d3e;
case 0x0c077d40u: goto P_0c077d40;
case 0x0c077d42u: goto P_0c077d42;
case 0x0c077d44u: goto P_0c077d44;
case 0x0c077d46u: goto P_0c077d46;
case 0x0c077d48u: goto P_0c077d48;
case 0x0c077d4au: goto P_0c077d4a;
case 0x0c077d4cu: goto P_0c077d4c;
case 0x0c077d4eu: goto P_0c077d4e;
case 0x0c077d50u: goto P_0c077d50;
case 0x0c077d52u: goto P_0c077d52;
case 0x0c077d54u: goto P_0c077d54;
case 0x0c077d56u: goto P_0c077d56;
case 0x0c077d58u: goto P_0c077d58;
case 0x0c077d5au: goto P_0c077d5a;
case 0x0c077d5cu: goto P_0c077d5c;
case 0x0c077d5eu: goto P_0c077d5e;
case 0x0c077d60u: goto P_0c077d60;
case 0x0c077d62u: goto P_0c077d62;
case 0x0c077d64u: goto P_0c077d64;
case 0x0c077d66u: goto P_0c077d66;
case 0x0c077d68u: goto P_0c077d68;
case 0x0c077d6au: goto P_0c077d6a;
case 0x0c077d6cu: goto P_0c077d6c;
case 0x0c077d6eu: goto P_0c077d6e;
case 0x0c077d70u: goto P_0c077d70;
case 0x0c077d72u: goto P_0c077d72;
case 0x0c077d74u: goto P_0c077d74;
case 0x0c077d76u: goto P_0c077d76;
case 0x0c077d78u: goto P_0c077d78;
case 0x0c077d7au: goto P_0c077d7a;
case 0x0c077d7cu: goto P_0c077d7c;
case 0x0c077d7eu: goto P_0c077d7e;
case 0x0c077d80u: goto P_0c077d80;
case 0x0c077d82u: goto P_0c077d82;
case 0x0c077d84u: goto P_0c077d84;
case 0x0c077d86u: goto P_0c077d86;
case 0x0c077d88u: goto P_0c077d88;
case 0x0c077d8au: goto P_0c077d8a;
case 0x0c077d8cu: goto P_0c077d8c;
case 0x0c077d8eu: goto P_0c077d8e;
case 0x0c077d90u: goto P_0c077d90;
case 0x0c077d92u: goto P_0c077d92;
case 0x0c077d94u: goto P_0c077d94;
case 0x0c077d96u: goto P_0c077d96;
case 0x0c077d98u: goto P_0c077d98;
case 0x0c077d9au: goto P_0c077d9a;
case 0x0c077d9cu: goto P_0c077d9c;
case 0x0c077d9eu: goto P_0c077d9e;
case 0x0c077da0u: goto P_0c077da0;
case 0x0c077da2u: goto P_0c077da2;
case 0x0c077da4u: goto P_0c077da4;
case 0x0c077da6u: goto P_0c077da6;
case 0x0c077da8u: goto P_0c077da8;
case 0x0c077daau: goto P_0c077daa;
case 0x0c077dacu: goto P_0c077dac;
case 0x0c077daeu: goto P_0c077dae;
case 0x0c077db0u: goto P_0c077db0;
case 0x0c077db2u: goto P_0c077db2;
case 0x0c077db4u: goto P_0c077db4;
case 0x0c077db6u: goto P_0c077db6;
case 0x0c077db8u: goto P_0c077db8;
case 0x0c077dbau: goto P_0c077dba;
case 0x0c077dbcu: goto P_0c077dbc;
case 0x0c077dbeu: goto P_0c077dbe;
case 0x0c077dc0u: goto P_0c077dc0;
case 0x0c077dc2u: goto P_0c077dc2;
case 0x0c077dc4u: goto P_0c077dc4;
case 0x0c077dc6u: goto P_0c077dc6;
case 0x0c077dc8u: goto P_0c077dc8;
case 0x0c077dcau: goto P_0c077dca;
case 0x0c077dccu: goto P_0c077dcc;
case 0x0c077dceu: goto P_0c077dce;
case 0x0c077dd0u: goto P_0c077dd0;
case 0x0c077dd2u: goto P_0c077dd2;
case 0x0c077dd4u: goto P_0c077dd4;
case 0x0c077dd6u: goto P_0c077dd6;
case 0x0c077dd8u: goto P_0c077dd8;
case 0x0c077ddau: goto P_0c077dda;
case 0x0c077e04u: goto P_0c077e04;
case 0x0c077e06u: goto P_0c077e06;
case 0x0c077e08u: goto P_0c077e08;
case 0x0c077e0au: goto P_0c077e0a;
case 0x0c077e0cu: goto P_0c077e0c;
case 0x0c077e0eu: goto P_0c077e0e;
case 0x0c077e10u: goto P_0c077e10;
case 0x0c077e12u: goto P_0c077e12;
case 0x0c077e14u: goto P_0c077e14;
case 0x0c077e16u: goto P_0c077e16;
case 0x0c077e18u: goto P_0c077e18;
case 0x0c077e1au: goto P_0c077e1a;
case 0x0c077e1cu: goto P_0c077e1c;
case 0x0c077e1eu: goto P_0c077e1e;
case 0x0c077e20u: goto P_0c077e20;
case 0x0c077e22u: goto P_0c077e22;
case 0x0c077e24u: goto P_0c077e24;
case 0x0c077e26u: goto P_0c077e26;
case 0x0c077e28u: goto P_0c077e28;
case 0x0c077e2au: goto P_0c077e2a;
case 0x0c077e2cu: goto P_0c077e2c;
case 0x0c077e2eu: goto P_0c077e2e;
case 0x0c077e30u: goto P_0c077e30;
case 0x0c077e32u: goto P_0c077e32;
case 0x0c077e34u: goto P_0c077e34;
case 0x0c077e36u: goto P_0c077e36;
case 0x0c077e38u: goto P_0c077e38;
case 0x0c077e3au: goto P_0c077e3a;
case 0x0c077e3cu: goto P_0c077e3c;
case 0x0c077e3eu: goto P_0c077e3e;
case 0x0c077e40u: goto P_0c077e40;
case 0x0c077e42u: goto P_0c077e42;
case 0x0c077e44u: goto P_0c077e44;
case 0x0c077e46u: goto P_0c077e46;
case 0x0c077e48u: goto P_0c077e48;
case 0x0c077e4au: goto P_0c077e4a;
case 0x0c077e4cu: goto P_0c077e4c;
case 0x0c0786d4u: goto P_0c0786d4;
case 0x0c0786d6u: goto P_0c0786d6;
case 0x0c07873cu: goto P_0c07873c;
case 0x0c07873eu: goto P_0c07873e;
case 0x0c078858u: goto P_0c078858;
case 0x0c07885au: goto P_0c07885a;
case 0x0c07885cu: goto P_0c07885c;
case 0x0c0788a6u: goto P_0c0788a6;
case 0x0c0788a8u: goto P_0c0788a8;
case 0x0c0788aau: goto P_0c0788aa;
case 0x0c078dd0u: goto P_0c078dd0;
case 0x0c078dd2u: goto P_0c078dd2;
case 0x0c078dd4u: goto P_0c078dd4;
case 0x0c078dd6u: goto P_0c078dd6;
case 0x0c078dd8u: goto P_0c078dd8;
case 0x0c078ddau: goto P_0c078dda;
case 0x0c078ddcu: goto P_0c078ddc;
case 0x0c078ddeu: goto P_0c078dde;
case 0x0c078de0u: goto P_0c078de0;
case 0x0c078de2u: goto P_0c078de2;
case 0x0c078de4u: goto P_0c078de4;
case 0x0c078de6u: goto P_0c078de6;
case 0x0c078de8u: goto P_0c078de8;
case 0x0c078deau: goto P_0c078dea;
case 0x0c078decu: goto P_0c078dec;
case 0x0c078deeu: goto P_0c078dee;
case 0x0c078df0u: goto P_0c078df0;
case 0x0c078df2u: goto P_0c078df2;
case 0x0c078df4u: goto P_0c078df4;
case 0x0c078df6u: goto P_0c078df6;
case 0x0c078df8u: goto P_0c078df8;
case 0x0c078dfau: goto P_0c078dfa;
case 0x0c078dfcu: goto P_0c078dfc;
case 0x0c078dfeu: goto P_0c078dfe;
case 0x0c078e00u: goto P_0c078e00;
case 0x0c078e02u: goto P_0c078e02;
case 0x0c078e04u: goto P_0c078e04;
case 0x0c078e06u: goto P_0c078e06;
case 0x0c078e08u: goto P_0c078e08;
case 0x0c078e0au: goto P_0c078e0a;
case 0x0c078e0cu: goto P_0c078e0c;
case 0x0c078e0eu: goto P_0c078e0e;
case 0x0c078e10u: goto P_0c078e10;
case 0x0c078e12u: goto P_0c078e12;
case 0x0c078e14u: goto P_0c078e14;
case 0x0c078e16u: goto P_0c078e16;
case 0x0c079462u: goto P_0c079462;
case 0x0c079464u: goto P_0c079464;
case 0x0c079466u: goto P_0c079466;
case 0x0c079468u: goto P_0c079468;
case 0x0c07946au: goto P_0c07946a;
case 0x0c07946cu: goto P_0c07946c;
case 0x0c07946eu: goto P_0c07946e;
case 0x0c079470u: goto P_0c079470;
case 0x0c079472u: goto P_0c079472;
case 0x0c079474u: goto P_0c079474;
case 0x0c079476u: goto P_0c079476;
case 0x0c079478u: goto P_0c079478;
case 0x0c07947au: goto P_0c07947a;
case 0x0c07947cu: goto P_0c07947c;
case 0x0c07947eu: goto P_0c07947e;
case 0x0c079480u: goto P_0c079480;
case 0x0c079482u: goto P_0c079482;
case 0x0c079484u: goto P_0c079484;
case 0x0c079486u: goto P_0c079486;
case 0x0c079488u: goto P_0c079488;
case 0x0c07948au: goto P_0c07948a;
case 0x0c079f96u: goto P_0c079f96;
case 0x0c079f98u: goto P_0c079f98;
case 0x0c079f9au: goto P_0c079f9a;
case 0x0c079f9cu: goto P_0c079f9c;
case 0x0c079f9eu: goto P_0c079f9e;
case 0x0c079fa0u: goto P_0c079fa0;
case 0x0c079fa2u: goto P_0c079fa2;
case 0x0c079fa4u: goto P_0c079fa4;
case 0x0c079fa6u: goto P_0c079fa6;
case 0x0c079fa8u: goto P_0c079fa8;
case 0x0c079faau: goto P_0c079faa;
case 0x0c079facu: goto P_0c079fac;
case 0x0c079faeu: goto P_0c079fae;
case 0x0c079fb0u: goto P_0c079fb0;
case 0x0c079fb2u: goto P_0c079fb2;
case 0x0c079fb4u: goto P_0c079fb4;
case 0x0c079fb6u: goto P_0c079fb6;
case 0x0c079fb8u: goto P_0c079fb8;
case 0x0c079fbau: goto P_0c079fba;
case 0x0c079fbcu: goto P_0c079fbc;
case 0x0c079fbeu: goto P_0c079fbe;
case 0x0c079fc0u: goto P_0c079fc0;
case 0x0c079fc2u: goto P_0c079fc2;
case 0x0c07a336u: goto P_0c07a336;
case 0x0c07a338u: goto P_0c07a338;
case 0x0c07a33au: goto P_0c07a33a;
case 0x0c07a33cu: goto P_0c07a33c;
case 0x0c07a4d8u: goto P_0c07a4d8;
case 0x0c07a4dau: goto P_0c07a4da;
case 0x0c07a4dcu: goto P_0c07a4dc;
case 0x0c07a4deu: goto P_0c07a4de;
case 0x0c07a4e0u: goto P_0c07a4e0;
case 0x0c07a4e2u: goto P_0c07a4e2;
case 0x0c07a4e4u: goto P_0c07a4e4;
case 0x0c07a4e6u: goto P_0c07a4e6;
case 0x0c07a4e8u: goto P_0c07a4e8;
case 0x0c07a4eau: goto P_0c07a4ea;
case 0x0c07a4ecu: goto P_0c07a4ec;
case 0x0c07a4eeu: goto P_0c07a4ee;
case 0x0c07a4f0u: goto P_0c07a4f0;
case 0x0c07a4f2u: goto P_0c07a4f2;
case 0x0c07a4f4u: goto P_0c07a4f4;
case 0x0c07a4f6u: goto P_0c07a4f6;
case 0x0c07a4f8u: goto P_0c07a4f8;
case 0x0c07a4fau: goto P_0c07a4fa;
case 0x0c07a4fcu: goto P_0c07a4fc;
case 0x0c07a4feu: goto P_0c07a4fe;
case 0x0c07a500u: goto P_0c07a500;
case 0x0c07a502u: goto P_0c07a502;
case 0x0c07a504u: goto P_0c07a504;
case 0x0c07a506u: goto P_0c07a506;
case 0x0c07a508u: goto P_0c07a508;
case 0x0c07a50au: goto P_0c07a50a;
case 0x0c07a50cu: goto P_0c07a50c;
case 0x0c07a50eu: goto P_0c07a50e;
case 0x0c07a510u: goto P_0c07a510;
case 0x0c07a512u: goto P_0c07a512;
case 0x0c07a514u: goto P_0c07a514;
case 0x0c07a516u: goto P_0c07a516;
case 0x0c07a518u: goto P_0c07a518;
case 0x0c07a6c4u: goto P_0c07a6c4;
case 0x0c07a6c6u: goto P_0c07a6c6;
case 0x0c07a6c8u: goto P_0c07a6c8;
case 0x0c07a6cau: goto P_0c07a6ca;
case 0x0c07a6ccu: goto P_0c07a6cc;
case 0x0c07a6ceu: goto P_0c07a6ce;
case 0x0c07a6d0u: goto P_0c07a6d0;
case 0x0c07a6d2u: goto P_0c07a6d2;
case 0x0c07a6d4u: goto P_0c07a6d4;
case 0x0c07a6d6u: goto P_0c07a6d6;
case 0x0c07a6d8u: goto P_0c07a6d8;
case 0x0c07a6dau: goto P_0c07a6da;
case 0x0c07a6dcu: goto P_0c07a6dc;
case 0x0c07a6deu: goto P_0c07a6de;
case 0x0c07a6e0u: goto P_0c07a6e0;
case 0x0c07a6e2u: goto P_0c07a6e2;
case 0x0c07a6e4u: goto P_0c07a6e4;
case 0x0c07a6e6u: goto P_0c07a6e6;
case 0x0c07a6e8u: goto P_0c07a6e8;
case 0x0c07a6eau: goto P_0c07a6ea;
case 0x0c07a6ecu: goto P_0c07a6ec;
case 0x0c07a6eeu: goto P_0c07a6ee;
case 0x0c07a6f0u: goto P_0c07a6f0;
case 0x0c07a6f2u: goto P_0c07a6f2;
case 0x0c07a6f4u: goto P_0c07a6f4;
case 0x0c07a6f6u: goto P_0c07a6f6;
case 0x0c07a6f8u: goto P_0c07a6f8;
case 0x0c07a6fau: goto P_0c07a6fa;
case 0x0c07a6fcu: goto P_0c07a6fc;
case 0x0c07a6feu: goto P_0c07a6fe;
case 0x0c07a700u: goto P_0c07a700;
case 0x0c07a702u: goto P_0c07a702;
case 0x0c07a704u: goto P_0c07a704;
case 0x0c07a706u: goto P_0c07a706;
case 0x0c07a708u: goto P_0c07a708;
case 0x0c07a70au: goto P_0c07a70a;
case 0x0c07a70cu: goto P_0c07a70c;
case 0x0c07a70eu: goto P_0c07a70e;
case 0x0c07a710u: goto P_0c07a710;
case 0x0c07a712u: goto P_0c07a712;
case 0x0c07a714u: goto P_0c07a714;
case 0x0c07a716u: goto P_0c07a716;
case 0x0c07a718u: goto P_0c07a718;
case 0x0c07a71au: goto P_0c07a71a;
case 0x0c07a71cu: goto P_0c07a71c;
case 0x0c07a71eu: goto P_0c07a71e;
case 0x0c07a720u: goto P_0c07a720;
case 0x0c07a722u: goto P_0c07a722;
case 0x0c07a724u: goto P_0c07a724;
case 0x0c07a726u: goto P_0c07a726;
case 0x0c07a728u: goto P_0c07a728;
case 0x0c07a72au: goto P_0c07a72a;
case 0x0c07a72cu: goto P_0c07a72c;
case 0x0c07a72eu: goto P_0c07a72e;
case 0x0c07a730u: goto P_0c07a730;
case 0x0c07a732u: goto P_0c07a732;
case 0x0c07a734u: goto P_0c07a734;
case 0x0c07a736u: goto P_0c07a736;
case 0x0c07a738u: goto P_0c07a738;
case 0x0c07a73au: goto P_0c07a73a;
case 0x0c07a73cu: goto P_0c07a73c;
case 0x0c07a73eu: goto P_0c07a73e;
case 0x0c07a740u: goto P_0c07a740;
case 0x0c07a742u: goto P_0c07a742;
case 0x0c07a744u: goto P_0c07a744;
case 0x0c07a746u: goto P_0c07a746;
case 0x0c07a748u: goto P_0c07a748;
case 0x0c07a74au: goto P_0c07a74a;
case 0x0c07a74cu: goto P_0c07a74c;
case 0x0c07a74eu: goto P_0c07a74e;
case 0x0c07a750u: goto P_0c07a750;
case 0x0c07a752u: goto P_0c07a752;
case 0x0c07a754u: goto P_0c07a754;
case 0x0c07a756u: goto P_0c07a756;
case 0x0c07a758u: goto P_0c07a758;
case 0x0c07a782u: goto P_0c07a782;
case 0x0c07a784u: goto P_0c07a784;
case 0x0c07a786u: goto P_0c07a786;
case 0x0c07a788u: goto P_0c07a788;
case 0x0c07a78au: goto P_0c07a78a;
case 0x0c07a78cu: goto P_0c07a78c;
case 0x0c07a78eu: goto P_0c07a78e;
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
case 0x0c07c8cau: goto P_0c07c8ca;
case 0x0c07c8ccu: goto P_0c07c8cc;
case 0x0c07c8ceu: goto P_0c07c8ce;
case 0x0c07c8d0u: goto P_0c07c8d0;
case 0x0c07c8d2u: goto P_0c07c8d2;
case 0x0c07c8d4u: goto P_0c07c8d4;
case 0x0c07c8d6u: goto P_0c07c8d6;
case 0x0c07c8d8u: goto P_0c07c8d8;
case 0x0c07c8dau: goto P_0c07c8da;
case 0x0c07c8dcu: goto P_0c07c8dc;
case 0x0c07c8deu: goto P_0c07c8de;
case 0x0c07c8e0u: goto P_0c07c8e0;
case 0x0c07c8e2u: goto P_0c07c8e2;
case 0x0c07c8e4u: goto P_0c07c8e4;
case 0x0c07c8e6u: goto P_0c07c8e6;
case 0x0c07c8e8u: goto P_0c07c8e8;
case 0x0c07c8eau: goto P_0c07c8ea;
case 0x0c07c8ecu: goto P_0c07c8ec;
case 0x0c07c8eeu: goto P_0c07c8ee;
case 0x0c07c8f0u: goto P_0c07c8f0;
case 0x0c07c8f2u: goto P_0c07c8f2;
case 0x0c07c8f4u: goto P_0c07c8f4;
case 0x0c07c8f6u: goto P_0c07c8f6;
case 0x0c07c8f8u: goto P_0c07c8f8;
case 0x0c07c8fau: goto P_0c07c8fa;
case 0x0c07c8fcu: goto P_0c07c8fc;
case 0x0c07c8feu: goto P_0c07c8fe;
case 0x0c07c900u: goto P_0c07c900;
case 0x0c07c902u: goto P_0c07c902;
case 0x0c07c904u: goto P_0c07c904;
case 0x0c07c906u: goto P_0c07c906;
case 0x0c07c908u: goto P_0c07c908;
case 0x0c07c90au: goto P_0c07c90a;
case 0x0c07c90cu: goto P_0c07c90c;
case 0x0c07c90eu: goto P_0c07c90e;
case 0x0c07c910u: goto P_0c07c910;
case 0x0c07c912u: goto P_0c07c912;
case 0x0c07c914u: goto P_0c07c914;
case 0x0c07c916u: goto P_0c07c916;
case 0x0c07c918u: goto P_0c07c918;
case 0x0c07c91au: goto P_0c07c91a;
case 0x0c07c91cu: goto P_0c07c91c;
case 0x0c07c91eu: goto P_0c07c91e;
case 0x0c07c920u: goto P_0c07c920;
case 0x0c07c922u: goto P_0c07c922;
case 0x0c07c924u: goto P_0c07c924;
case 0x0c07c926u: goto P_0c07c926;
case 0x0c07c928u: goto P_0c07c928;
case 0x0c07c92au: goto P_0c07c92a;
case 0x0c07c92cu: goto P_0c07c92c;
case 0x0c07c968u: goto P_0c07c968;
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
case 0x0c08944cu: goto P_0c08944c;
case 0x0c08944eu: goto P_0c08944e;
case 0x0c089450u: goto P_0c089450;
case 0x0c089452u: goto P_0c089452;
case 0x0c089454u: goto P_0c089454;
case 0x0c089456u: goto P_0c089456;
case 0x0c089458u: goto P_0c089458;
case 0x0c08945au: goto P_0c08945a;
case 0x0c08945cu: goto P_0c08945c;
case 0x0c08945eu: goto P_0c08945e;
case 0x0c089460u: goto P_0c089460;
case 0x0c089462u: goto P_0c089462;
case 0x0c089464u: goto P_0c089464;
case 0x0c089466u: goto P_0c089466;
case 0x0c089468u: goto P_0c089468;
case 0x0c08946au: goto P_0c08946a;
case 0x0c08946cu: goto P_0c08946c;
case 0x0c08946eu: goto P_0c08946e;
case 0x0c089470u: goto P_0c089470;
case 0x0c089472u: goto P_0c089472;
case 0x0c089474u: goto P_0c089474;
case 0x0c089476u: goto P_0c089476;
case 0x0c089478u: goto P_0c089478;
case 0x0c08947au: goto P_0c08947a;
case 0x0c08947cu: goto P_0c08947c;
case 0x0c08947eu: goto P_0c08947e;
case 0x0c089480u: goto P_0c089480;
case 0x0c089482u: goto P_0c089482;
case 0x0c089484u: goto P_0c089484;
case 0x0c089486u: goto P_0c089486;
case 0x0c089488u: goto P_0c089488;
case 0x0c08948au: goto P_0c08948a;
case 0x0c08948cu: goto P_0c08948c;
case 0x0c08948eu: goto P_0c08948e;
case 0x0c089490u: goto P_0c089490;
case 0x0c089492u: goto P_0c089492;
case 0x0c089494u: goto P_0c089494;
case 0x0c089496u: goto P_0c089496;
case 0x0c089498u: goto P_0c089498;
case 0x0c08949au: goto P_0c08949a;
case 0x0c08949cu: goto P_0c08949c;
case 0x0c08949eu: goto P_0c08949e;
case 0x0c0894a0u: goto P_0c0894a0;
case 0x0c0894a2u: goto P_0c0894a2;
case 0x0c0894a4u: goto P_0c0894a4;
case 0x0c0894a6u: goto P_0c0894a6;
case 0x0c0894a8u: goto P_0c0894a8;
case 0x0c0894aau: goto P_0c0894aa;
case 0x0c0894acu: goto P_0c0894ac;
case 0x0c0894aeu: goto P_0c0894ae;
case 0x0c0894b0u: goto P_0c0894b0;
case 0x0c0894b2u: goto P_0c0894b2;
case 0x0c0894b4u: goto P_0c0894b4;
case 0x0c0894b6u: goto P_0c0894b6;
case 0x0c0894b8u: goto P_0c0894b8;
case 0x0c0894bau: goto P_0c0894ba;
case 0x0c0894bcu: goto P_0c0894bc;
case 0x0c0894beu: goto P_0c0894be;
case 0x0c0894c0u: goto P_0c0894c0;
case 0x0c0894c2u: goto P_0c0894c2;
case 0x0c0894c4u: goto P_0c0894c4;
case 0x0c0894c6u: goto P_0c0894c6;
case 0x0c0894c8u: goto P_0c0894c8;
case 0x0c0894cau: goto P_0c0894ca;
case 0x0c0894ccu: goto P_0c0894cc;
case 0x0c0894ceu: goto P_0c0894ce;
case 0x0c0894d0u: goto P_0c0894d0;
case 0x0c0894d2u: goto P_0c0894d2;
case 0x0c0894d4u: goto P_0c0894d4;
case 0x0c0894d6u: goto P_0c0894d6;
case 0x0c08b7eau: goto P_0c08b7ea;
case 0x0c08b7ecu: goto P_0c08b7ec;
case 0x0c08b7eeu: goto P_0c08b7ee;
case 0x0c08b7f0u: goto P_0c08b7f0;
case 0x0c08b7f2u: goto P_0c08b7f2;
case 0x0c08b7f4u: goto P_0c08b7f4;
case 0x0c08b7f6u: goto P_0c08b7f6;
case 0x0c08b7f8u: goto P_0c08b7f8;
case 0x0c08b7fau: goto P_0c08b7fa;
case 0x0c08b7fcu: goto P_0c08b7fc;
case 0x0c08b7feu: goto P_0c08b7fe;
case 0x0c08b800u: goto P_0c08b800;
case 0x0c08b802u: goto P_0c08b802;
case 0x0c08b804u: goto P_0c08b804;
case 0x0c08b806u: goto P_0c08b806;
case 0x0c08b808u: goto P_0c08b808;
case 0x0c08b80au: goto P_0c08b80a;
case 0x0c08b80cu: goto P_0c08b80c;
case 0x0c08b80eu: goto P_0c08b80e;
case 0x0c08b810u: goto P_0c08b810;
case 0x0c08b812u: goto P_0c08b812;
case 0x0c08b814u: goto P_0c08b814;
case 0x0c08b816u: goto P_0c08b816;
case 0x0c08b818u: goto P_0c08b818;
case 0x0c08b81au: goto P_0c08b81a;
case 0x0c08b81cu: goto P_0c08b81c;
case 0x0c08b81eu: goto P_0c08b81e;
case 0x0c08b820u: goto P_0c08b820;
case 0x0c08b822u: goto P_0c08b822;
case 0x0c08b824u: goto P_0c08b824;
case 0x0c08b826u: goto P_0c08b826;
case 0x0c08b828u: goto P_0c08b828;
case 0x0c08b82au: goto P_0c08b82a;
case 0x0c08b82cu: goto P_0c08b82c;
case 0x0c08b82eu: goto P_0c08b82e;
case 0x0c08b830u: goto P_0c08b830;
case 0x0c08b832u: goto P_0c08b832;
case 0x0c08b834u: goto P_0c08b834;
case 0x0c08b836u: goto P_0c08b836;
case 0x0c08b838u: goto P_0c08b838;
case 0x0c08b83au: goto P_0c08b83a;
case 0x0c08b83cu: goto P_0c08b83c;
case 0x0c08b83eu: goto P_0c08b83e;
case 0x0c08b840u: goto P_0c08b840;
case 0x0c08b842u: goto P_0c08b842;
case 0x0c08b844u: goto P_0c08b844;
case 0x0c08b846u: goto P_0c08b846;
case 0x0c08b848u: goto P_0c08b848;
case 0x0c08b84au: goto P_0c08b84a;
case 0x0c08b84cu: goto P_0c08b84c;
case 0x0c08b84eu: goto P_0c08b84e;
case 0x0c08b850u: goto P_0c08b850;
case 0x0c08b852u: goto P_0c08b852;
case 0x0c08b854u: goto P_0c08b854;
case 0x0c08b856u: goto P_0c08b856;
case 0x0c08b858u: goto P_0c08b858;
case 0x0c08b85au: goto P_0c08b85a;
case 0x0c08b85cu: goto P_0c08b85c;
case 0x0c08b85eu: goto P_0c08b85e;
case 0x0c08b860u: goto P_0c08b860;
case 0x0c08b862u: goto P_0c08b862;
case 0x0c08b864u: goto P_0c08b864;
case 0x0c08b866u: goto P_0c08b866;
case 0x0c08b868u: goto P_0c08b868;
case 0x0c08b86au: goto P_0c08b86a;
case 0x0c08b86cu: goto P_0c08b86c;
case 0x0c08b86eu: goto P_0c08b86e;
case 0x0c08b870u: goto P_0c08b870;
case 0x0c08b872u: goto P_0c08b872;
case 0x0c08b874u: goto P_0c08b874;
case 0x0c08b876u: goto P_0c08b876;
case 0x0c08b878u: goto P_0c08b878;
case 0x0c08b87au: goto P_0c08b87a;
case 0x0c08b87cu: goto P_0c08b87c;
case 0x0c08b87eu: goto P_0c08b87e;
case 0x0c08b880u: goto P_0c08b880;
case 0x0c08b882u: goto P_0c08b882;
case 0x0c08b884u: goto P_0c08b884;
case 0x0c08b886u: goto P_0c08b886;
case 0x0c08b888u: goto P_0c08b888;
case 0x0c091c20u: goto P_0c091c20;
case 0x0c091c22u: goto P_0c091c22;
case 0x0c091c24u: goto P_0c091c24;
case 0x0c091c26u: goto P_0c091c26;
case 0x0c091c28u: goto P_0c091c28;
case 0x0c091c2au: goto P_0c091c2a;
case 0x0c091c2cu: goto P_0c091c2c;
case 0x0c091c2eu: goto P_0c091c2e;
case 0x0c091c30u: goto P_0c091c30;
case 0x0c091c32u: goto P_0c091c32;
case 0x0c091c34u: goto P_0c091c34;
case 0x0c091c36u: goto P_0c091c36;
case 0x0c091c38u: goto P_0c091c38;
case 0x0c091c3au: goto P_0c091c3a;
case 0x0c091c3cu: goto P_0c091c3c;
case 0x0c091c3eu: goto P_0c091c3e;
case 0x0c091c40u: goto P_0c091c40;
case 0x0c091c42u: goto P_0c091c42;
case 0x0c091c44u: goto P_0c091c44;
case 0x0c091c46u: goto P_0c091c46;
case 0x0c091c48u: goto P_0c091c48;
case 0x0c091c4au: goto P_0c091c4a;
case 0x0c091c4cu: goto P_0c091c4c;
case 0x0c091c4eu: goto P_0c091c4e;
case 0x0c091c50u: goto P_0c091c50;
case 0x0c091c52u: goto P_0c091c52;
case 0x0c091c54u: goto P_0c091c54;
case 0x0c091c56u: goto P_0c091c56;
case 0x0c091c58u: goto P_0c091c58;
case 0x0c091c5au: goto P_0c091c5a;
case 0x0c091c5cu: goto P_0c091c5c;
case 0x0c091c5eu: goto P_0c091c5e;
case 0x0c091c60u: goto P_0c091c60;
case 0x0c091c62u: goto P_0c091c62;
case 0x0c091c64u: goto P_0c091c64;
case 0x0c091c66u: goto P_0c091c66;
case 0x0c091c68u: goto P_0c091c68;
case 0x0c091c6au: goto P_0c091c6a;
case 0x0c091c6cu: goto P_0c091c6c;
case 0x0c091c6eu: goto P_0c091c6e;
case 0x0c091c70u: goto P_0c091c70;
case 0x0c091c72u: goto P_0c091c72;
case 0x0c091c74u: goto P_0c091c74;
case 0x0c091c76u: goto P_0c091c76;
case 0x0c091c78u: goto P_0c091c78;
case 0x0c091c7au: goto P_0c091c7a;
case 0x0c091c7cu: goto P_0c091c7c;
case 0x0c091c7eu: goto P_0c091c7e;
case 0x0c091c80u: goto P_0c091c80;
case 0x0c091c82u: goto P_0c091c82;
case 0x0c091c84u: goto P_0c091c84;
case 0x0c091c86u: goto P_0c091c86;
case 0x0c091c88u: goto P_0c091c88;
case 0x0c091c8au: goto P_0c091c8a;
case 0x0c091c8cu: goto P_0c091c8c;
case 0x0c091c8eu: goto P_0c091c8e;
case 0x0c091c90u: goto P_0c091c90;
case 0x0c091c92u: goto P_0c091c92;
case 0x0c091c94u: goto P_0c091c94;
case 0x0c091c96u: goto P_0c091c96;
case 0x0c091c98u: goto P_0c091c98;
case 0x0c091c9au: goto P_0c091c9a;
case 0x0c091c9cu: goto P_0c091c9c;
case 0x0c091c9eu: goto P_0c091c9e;
case 0x0c091ca0u: goto P_0c091ca0;
case 0x0c091ca2u: goto P_0c091ca2;
case 0x0c091ca4u: goto P_0c091ca4;
case 0x0c091ca6u: goto P_0c091ca6;
case 0x0c091ca8u: goto P_0c091ca8;
case 0x0c091caau: goto P_0c091caa;
case 0x0c091cacu: goto P_0c091cac;
case 0x0c091caeu: goto P_0c091cae;
case 0x0c091cb0u: goto P_0c091cb0;
case 0x0c091cb2u: goto P_0c091cb2;
case 0x0c091cb4u: goto P_0c091cb4;
case 0x0c091cb6u: goto P_0c091cb6;
case 0x0c091cb8u: goto P_0c091cb8;
case 0x0c091cbau: goto P_0c091cba;
case 0x0c091cbcu: goto P_0c091cbc;
case 0x0c091cbeu: goto P_0c091cbe;
case 0x0c091cc0u: goto P_0c091cc0;
case 0x0c091cc2u: goto P_0c091cc2;
case 0x0c091cc4u: goto P_0c091cc4;
case 0x0c091cc6u: goto P_0c091cc6;
case 0x0c091cc8u: goto P_0c091cc8;
case 0x0c091ccau: goto P_0c091cca;
case 0x0c091cccu: goto P_0c091ccc;
case 0x0c091cceu: goto P_0c091cce;
case 0x0c091cd0u: goto P_0c091cd0;
case 0x0c091cd2u: goto P_0c091cd2;
case 0x0c091cd4u: goto P_0c091cd4;
case 0x0c091cd6u: goto P_0c091cd6;
case 0x0c091cd8u: goto P_0c091cd8;
case 0x0c091cdau: goto P_0c091cda;
case 0x0c091cdcu: goto P_0c091cdc;
case 0x0c091cdeu: goto P_0c091cde;
case 0x0c091ce0u: goto P_0c091ce0;
case 0x0c091ce2u: goto P_0c091ce2;
case 0x0c091ce4u: goto P_0c091ce4;
case 0x0c091ce6u: goto P_0c091ce6;
case 0x0c091ce8u: goto P_0c091ce8;
case 0x0c091ceau: goto P_0c091cea;
case 0x0c091cecu: goto P_0c091cec;
case 0x0c091ceeu: goto P_0c091cee;
case 0x0c091cf0u: goto P_0c091cf0;
case 0x0c091cf2u: goto P_0c091cf2;
case 0x0c091cf4u: goto P_0c091cf4;
case 0x0c091cf6u: goto P_0c091cf6;
case 0x0c091cf8u: goto P_0c091cf8;
case 0x0c091cfau: goto P_0c091cfa;
case 0x0c091cfcu: goto P_0c091cfc;
case 0x0c091cfeu: goto P_0c091cfe;
case 0x0c091d00u: goto P_0c091d00;
case 0x0c091d02u: goto P_0c091d02;
case 0x0c091d04u: goto P_0c091d04;
case 0x0c091d06u: goto P_0c091d06;
case 0x0c091d08u: goto P_0c091d08;
case 0x0c091d0au: goto P_0c091d0a;
case 0x0c091d0cu: goto P_0c091d0c;
case 0x0c091d0eu: goto P_0c091d0e;
case 0x0c091d10u: goto P_0c091d10;
case 0x0c091d12u: goto P_0c091d12;
case 0x0c091d14u: goto P_0c091d14;
case 0x0c091d16u: goto P_0c091d16;
case 0x0c091d18u: goto P_0c091d18;
case 0x0c091d1au: goto P_0c091d1a;
case 0x0c091d1cu: goto P_0c091d1c;
case 0x0c091d1eu: goto P_0c091d1e;
case 0x0c091d20u: goto P_0c091d20;
case 0x0c091d22u: goto P_0c091d22;
case 0x0c091d24u: goto P_0c091d24;
case 0x0c091d26u: goto P_0c091d26;
case 0x0c091d28u: goto P_0c091d28;
case 0x0c091d2au: goto P_0c091d2a;
case 0x0c091d2cu: goto P_0c091d2c;
case 0x0c091d2eu: goto P_0c091d2e;
case 0x0c091d30u: goto P_0c091d30;
case 0x0c091d32u: goto P_0c091d32;
case 0x0c091d34u: goto P_0c091d34;
case 0x0c091d36u: goto P_0c091d36;
case 0x0c091d38u: goto P_0c091d38;
case 0x0c091d3au: goto P_0c091d3a;
case 0x0c091d3cu: goto P_0c091d3c;
case 0x0c091d3eu: goto P_0c091d3e;
case 0x0c091d40u: goto P_0c091d40;
case 0x0c091d42u: goto P_0c091d42;
case 0x0c091d44u: goto P_0c091d44;
case 0x0c091d46u: goto P_0c091d46;
case 0x0c091d48u: goto P_0c091d48;
case 0x0c091d4au: goto P_0c091d4a;
case 0x0c091d4cu: goto P_0c091d4c;
case 0x0c091d4eu: goto P_0c091d4e;
case 0x0c091d50u: goto P_0c091d50;
case 0x0c091d52u: goto P_0c091d52;
case 0x0c091d54u: goto P_0c091d54;
case 0x0c091d56u: goto P_0c091d56;
case 0x0c091d58u: goto P_0c091d58;
case 0x0c091d5au: goto P_0c091d5a;
case 0x0c091d5cu: goto P_0c091d5c;
case 0x0c091d5eu: goto P_0c091d5e;
case 0x0c091d60u: goto P_0c091d60;
case 0x0c091d62u: goto P_0c091d62;
case 0x0c091d64u: goto P_0c091d64;
case 0x0c091d66u: goto P_0c091d66;
case 0x0c091d68u: goto P_0c091d68;
case 0x0c091d6au: goto P_0c091d6a;
case 0x0c091d98u: goto P_0c091d98;
case 0x0c091d9au: goto P_0c091d9a;
case 0x0c091d9cu: goto P_0c091d9c;
case 0x0c091d9eu: goto P_0c091d9e;
case 0x0c091da0u: goto P_0c091da0;
case 0x0c091da2u: goto P_0c091da2;
case 0x0c091da4u: goto P_0c091da4;
case 0x0c091da6u: goto P_0c091da6;
case 0x0c091da8u: goto P_0c091da8;
case 0x0c091daau: goto P_0c091daa;
case 0x0c091dacu: goto P_0c091dac;
case 0x0c091daeu: goto P_0c091dae;
case 0x0c091db0u: goto P_0c091db0;
case 0x0c091db2u: goto P_0c091db2;
case 0x0c091db4u: goto P_0c091db4;
case 0x0c091db6u: goto P_0c091db6;
case 0x0c091db8u: goto P_0c091db8;
case 0x0c091dbau: goto P_0c091dba;
case 0x0c091dbcu: goto P_0c091dbc;
case 0x0c092268u: goto P_0c092268;
case 0x0c09226au: goto P_0c09226a;
case 0x0c09226cu: goto P_0c09226c;
case 0x0c09226eu: goto P_0c09226e;
case 0x0c092270u: goto P_0c092270;
case 0x0c092272u: goto P_0c092272;
case 0x0c092274u: goto P_0c092274;
case 0x0c092276u: goto P_0c092276;
case 0x0c092278u: goto P_0c092278;
case 0x0c09227au: goto P_0c09227a;
case 0x0c09227cu: goto P_0c09227c;
case 0x0c09227eu: goto P_0c09227e;
case 0x0c092280u: goto P_0c092280;
case 0x0c092282u: goto P_0c092282;
case 0x0c092284u: goto P_0c092284;
case 0x0c092286u: goto P_0c092286;
case 0x0c092288u: goto P_0c092288;
case 0x0c09228au: goto P_0c09228a;
case 0x0c09228cu: goto P_0c09228c;
case 0x0c09228eu: goto P_0c09228e;
case 0x0c092290u: goto P_0c092290;
case 0x0c092292u: goto P_0c092292;
case 0x0c0a80b0u: goto P_0c0a80b0;
case 0x0c0a80b2u: goto P_0c0a80b2;
case 0x0c0a80b4u: goto P_0c0a80b4;
case 0x0c0a80b6u: goto P_0c0a80b6;
case 0x0c0a80b8u: goto P_0c0a80b8;
case 0x0c0a80bau: goto P_0c0a80ba;
case 0x0c0a80bcu: goto P_0c0a80bc;
case 0x0c0a80beu: goto P_0c0a80be;
case 0x0c0a80c0u: goto P_0c0a80c0;
case 0x0c0a80c2u: goto P_0c0a80c2;
case 0x0c0a80c4u: goto P_0c0a80c4;
case 0x0c0a80c6u: goto P_0c0a80c6;
case 0x0c0a80c8u: goto P_0c0a80c8;
case 0x0c0a80cau: goto P_0c0a80ca;
case 0x0c0a80ccu: goto P_0c0a80cc;
case 0x0c0a80ceu: goto P_0c0a80ce;
case 0x0c0a80d0u: goto P_0c0a80d0;
case 0x0c0a80d2u: goto P_0c0a80d2;
case 0x0c0a80d4u: goto P_0c0a80d4;
case 0x0c0a80d6u: goto P_0c0a80d6;
case 0x0c0a80d8u: goto P_0c0a80d8;
case 0x0c0a80dau: goto P_0c0a80da;
case 0x0c0a80dcu: goto P_0c0a80dc;
case 0x0c0a80deu: goto P_0c0a80de;
case 0x0c0a80e0u: goto P_0c0a80e0;
case 0x0c0a80e2u: goto P_0c0a80e2;
case 0x0c0a80e4u: goto P_0c0a80e4;
case 0x0c0a80e6u: goto P_0c0a80e6;
case 0x0c0a80e8u: goto P_0c0a80e8;
case 0x0c0a80eau: goto P_0c0a80ea;
case 0x0c0a80ecu: goto P_0c0a80ec;
case 0x0c0a80eeu: goto P_0c0a80ee;
case 0x0c0a80f0u: goto P_0c0a80f0;
case 0x0c0a80f2u: goto P_0c0a80f2;
case 0x0c0a80f4u: goto P_0c0a80f4;
case 0x0c0a80f6u: goto P_0c0a80f6;
case 0x0c0a80f8u: goto P_0c0a80f8;
case 0x0c0a80fau: goto P_0c0a80fa;
case 0x0c0a80fcu: goto P_0c0a80fc;
case 0x0c0a80feu: goto P_0c0a80fe;
case 0x0c0a8100u: goto P_0c0a8100;
case 0x0c0a8102u: goto P_0c0a8102;
case 0x0c0a8104u: goto P_0c0a8104;
case 0x0c0a8106u: goto P_0c0a8106;
case 0x0c0a8108u: goto P_0c0a8108;
case 0x0c0a810au: goto P_0c0a810a;
case 0x0c0a810cu: goto P_0c0a810c;
case 0x0c0a810eu: goto P_0c0a810e;
case 0x0c0a8110u: goto P_0c0a8110;
case 0x0c0a8112u: goto P_0c0a8112;
case 0x0c0a8114u: goto P_0c0a8114;
case 0x0c0a8116u: goto P_0c0a8116;
case 0x0c0a8118u: goto P_0c0a8118;
case 0x0c0a811au: goto P_0c0a811a;
case 0x0c0a811cu: goto P_0c0a811c;
case 0x0c0a811eu: goto P_0c0a811e;
case 0x0c0a8120u: goto P_0c0a8120;
case 0x0c0a8122u: goto P_0c0a8122;
case 0x0c0a8124u: goto P_0c0a8124;
case 0x0c0a8126u: goto P_0c0a8126;
case 0x0c0a8128u: goto P_0c0a8128;
case 0x0c0a812au: goto P_0c0a812a;
case 0x0c0a812cu: goto P_0c0a812c;
case 0x0c0a812eu: goto P_0c0a812e;
case 0x0c0a8130u: goto P_0c0a8130;
case 0x0c0a8132u: goto P_0c0a8132;
case 0x0c0a8134u: goto P_0c0a8134;
case 0x0c0a8136u: goto P_0c0a8136;
case 0x0c0a8138u: goto P_0c0a8138;
case 0x0c0a813au: goto P_0c0a813a;
case 0x0c0a813cu: goto P_0c0a813c;
case 0x0c0a813eu: goto P_0c0a813e;
case 0x0c0a8140u: goto P_0c0a8140;
case 0x0c0a8142u: goto P_0c0a8142;
case 0x0c0a8144u: goto P_0c0a8144;
case 0x0c0a8146u: goto P_0c0a8146;
case 0x0c0a8148u: goto P_0c0a8148;
case 0x0c0a814au: goto P_0c0a814a;
case 0x0c0a814cu: goto P_0c0a814c;
case 0x0c0a814eu: goto P_0c0a814e;
case 0x0c0a8150u: goto P_0c0a8150;
case 0x0c0a8152u: goto P_0c0a8152;
case 0x0c0a8154u: goto P_0c0a8154;
case 0x0c0a8156u: goto P_0c0a8156;
case 0x0c0a8158u: goto P_0c0a8158;
case 0x0c0a815au: goto P_0c0a815a;
case 0x0c0a815cu: goto P_0c0a815c;
case 0x0c0a815eu: goto P_0c0a815e;
case 0x0c0a8160u: goto P_0c0a8160;
case 0x0c0a8162u: goto P_0c0a8162;
case 0x0c0a8164u: goto P_0c0a8164;
case 0x0c0a8166u: goto P_0c0a8166;
case 0x0c0a8168u: goto P_0c0a8168;
case 0x0c0a816au: goto P_0c0a816a;
case 0x0c0a816cu: goto P_0c0a816c;
case 0x0c0a816eu: goto P_0c0a816e;
case 0x0c0a8170u: goto P_0c0a8170;
case 0x0c0a8172u: goto P_0c0a8172;
case 0x0c0a818cu: goto P_0c0a818c;
case 0x0c0a818eu: goto P_0c0a818e;
case 0x0c0a8190u: goto P_0c0a8190;
case 0x0c0a8192u: goto P_0c0a8192;
case 0x0c0a8194u: goto P_0c0a8194;
case 0x0c0a8196u: goto P_0c0a8196;
case 0x0c0a8198u: goto P_0c0a8198;
case 0x0c0a819au: goto P_0c0a819a;
case 0x0c0a819cu: goto P_0c0a819c;
case 0x0c0a819eu: goto P_0c0a819e;
case 0x0c0a81a0u: goto P_0c0a81a0;
case 0x0c0a81a2u: goto P_0c0a81a2;
case 0x0c0a81a4u: goto P_0c0a81a4;
case 0x0c0a81a6u: goto P_0c0a81a6;
case 0x0c0a81a8u: goto P_0c0a81a8;
case 0x0c0a81aau: goto P_0c0a81aa;
case 0x0c0a81acu: goto P_0c0a81ac;
case 0x0c0a81aeu: goto P_0c0a81ae;
case 0x0c0a81b0u: goto P_0c0a81b0;
case 0x0c0a81b2u: goto P_0c0a81b2;
case 0x0c0a81b4u: goto P_0c0a81b4;
case 0x0c0a81b6u: goto P_0c0a81b6;
case 0x0c0a81b8u: goto P_0c0a81b8;
case 0x0c0a81bau: goto P_0c0a81ba;
case 0x0c0a81bcu: goto P_0c0a81bc;
case 0x0c0a81beu: goto P_0c0a81be;
case 0x0c0a81c0u: goto P_0c0a81c0;
case 0x0c0a81c2u: goto P_0c0a81c2;
case 0x0c0a81c4u: goto P_0c0a81c4;
case 0x0c0a81c6u: goto P_0c0a81c6;
case 0x0c0a81c8u: goto P_0c0a81c8;
case 0x0c0a81cau: goto P_0c0a81ca;
case 0x0c0a81ccu: goto P_0c0a81cc;
case 0x0c0a81ceu: goto P_0c0a81ce;
case 0x0c0a81d0u: goto P_0c0a81d0;
case 0x0c0a81d2u: goto P_0c0a81d2;
case 0x0c0a81d4u: goto P_0c0a81d4;
case 0x0c0a81d6u: goto P_0c0a81d6;
case 0x0c0a81d8u: goto P_0c0a81d8;
case 0x0c0a81dau: goto P_0c0a81da;
case 0x0c0a81dcu: goto P_0c0a81dc;
case 0x0c0a81deu: goto P_0c0a81de;
case 0x0c0a81e0u: goto P_0c0a81e0;
case 0x0c0a81e2u: goto P_0c0a81e2;
case 0x0c0a81e4u: goto P_0c0a81e4;
case 0x0c0a81e6u: goto P_0c0a81e6;
case 0x0c0a81e8u: goto P_0c0a81e8;
case 0x0c0a81eau: goto P_0c0a81ea;
case 0x0c0a81ecu: goto P_0c0a81ec;
case 0x0c0c2b60u: goto P_0c0c2b60;
case 0x0c0c2b62u: goto P_0c0c2b62;
case 0x0c0c2b64u: goto P_0c0c2b64;
case 0x0c0c2b66u: goto P_0c0c2b66;
case 0x0c0c2b68u: goto P_0c0c2b68;
case 0x0c0c2b6au: goto P_0c0c2b6a;
case 0x0c0c2b6cu: goto P_0c0c2b6c;
case 0x0c0c2b6eu: goto P_0c0c2b6e;
case 0x0c0c2b70u: goto P_0c0c2b70;
case 0x0c0c2b72u: goto P_0c0c2b72;
case 0x0c0c2b74u: goto P_0c0c2b74;
case 0x0c0c2b76u: goto P_0c0c2b76;
case 0x0c0c2b78u: goto P_0c0c2b78;
case 0x0c0c2b7au: goto P_0c0c2b7a;
case 0x0c0c2b7cu: goto P_0c0c2b7c;
case 0x0c0c2b7eu: goto P_0c0c2b7e;
default: return vf3_matrix_family(target,s,ram);
}
P_0c06f3ba: /* original 2fe6, guest PC 0x0c06f3ba */
if(!s->budget--) { s->failed_pc=0x0c06f3bau; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06f3bc;
P_0c06f3bc: /* original 2fd6, guest PC 0x0c06f3bc */
if(!s->budget--) { s->failed_pc=0x0c06f3bcu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06f3be;
P_0c06f3be: /* original 2fc6, guest PC 0x0c06f3be */
if(!s->budget--) { s->failed_pc=0x0c06f3beu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06f3c0;
P_0c06f3c0: /* original 2fb6, guest PC 0x0c06f3c0 */
if(!s->budget--) { s->failed_pc=0x0c06f3c0u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06f3c2;
P_0c06f3c2: /* original 4f22, guest PC 0x0c06f3c2 */
if(!s->budget--) { s->failed_pc=0x0c06f3c2u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c06f3c4;
P_0c06f3c4: /* original d141, guest PC 0x0c06f3c4 */
if(!s->budget--) { s->failed_pc=0x0c06f3c4u; return 0; }
r[1]=read(ram,0x0c06f4ccu,4);
goto P_0c06f3c6;
P_0c06f3c6: /* original d340, guest PC 0x0c06f3c6 */
if(!s->budget--) { s->failed_pc=0x0c06f3c6u; return 0; }
r[3]=read(ram,0x0c06f4c8u,4);
goto P_0c06f3c8;
P_0c06f3c8: /* original 6212, guest PC 0x0c06f3c8 */
if(!s->budget--) { s->failed_pc=0x0c06f3c8u; return 0; }
tmp=read(ram,r[1],4);
r[2]=tmp;
goto P_0c06f3ca;
P_0c06f3ca: /* original 4f12, guest PC 0x0c06f3ca */
if(!s->budget--) { s->failed_pc=0x0c06f3cau; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c06f3cc;
P_0c06f3cc: /* original de3d, guest PC 0x0c06f3cc */
if(!s->budget--) { s->failed_pc=0x0c06f3ccu; return 0; }
r[14]=read(ram,0x0c06f4c4u,4);
goto P_0c06f3ce;
P_0c06f3ce: /* original 2238, guest PC 0x0c06f3ce */
if(!s->budget--) { s->failed_pc=0x0c06f3ceu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c06f3d0;
P_0c06f3d0: /* original 8f37, guest PC 0x0c06f3d0 */
if(!s->budget--) { s->failed_pc=0x0c06f3d0u; return 0; }
cond=r[17]&1u;
r[13]=r[4];
if(!cond) { goto P_0c06f442; }
goto P_0c06f3d4;
P_0c06f3d2: /* original 6d43, guest PC 0x0c06f3d2 */
if(!s->budget--) { s->failed_pc=0x0c06f3d2u; return 0; }
r[13]=r[4];
goto P_0c06f3d4;
P_0c06f3d4: /* original d33e, guest PC 0x0c06f3d4 */
if(!s->budget--) { s->failed_pc=0x0c06f3d4u; return 0; }
r[3]=read(ram,0x0c06f4d0u,4);
goto P_0c06f3d6;
P_0c06f3d6: /* original 430b, guest PC 0x0c06f3d6 */
if(!s->budget--) { s->failed_pc=0x0c06f3d6u; return 0; }
target=r[3];
r[16]=0x8c06f3dau;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c06f3dau) { target=s->pc; goto dispatch; }
goto P_0c06f3da;
P_0c06f3d8: /* original 0009, guest PC 0x0c06f3d8 */
if(!s->budget--) { s->failed_pc=0x0c06f3d8u; return 0; }
goto P_0c06f3da;
P_0c06f3da: /* original 2008, guest PC 0x0c06f3da */
if(!s->budget--) { s->failed_pc=0x0c06f3dau; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c06f3dc;
P_0c06f3dc: /* original 8931, guest PC 0x0c06f3dc */
if(!s->budget--) { s->failed_pc=0x0c06f3dcu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c06f442; }
goto P_0c06f3de;
P_0c06f3de: /* original 84d4, guest PC 0x0c06f3de */
if(!s->budget--) { s->failed_pc=0x0c06f3deu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+4,1);
goto P_0c06f3e0;
P_0c06f3e0: /* original d43c, guest PC 0x0c06f3e0 */
if(!s->budget--) { s->failed_pc=0x0c06f3e0u; return 0; }
r[4]=read(ram,0x0c06f4d4u,4);
goto P_0c06f3e2;
P_0c06f3e2: /* original 2008, guest PC 0x0c06f3e2 */
if(!s->budget--) { s->failed_pc=0x0c06f3e2u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c06f3e4;
P_0c06f3e4: /* original 8f02, guest PC 0x0c06f3e4 */
if(!s->budget--) { s->failed_pc=0x0c06f3e4u; return 0; }
cond=r[17]&1u;
r[0]=0x00000060u;
if(!cond) { goto P_0c06f3ec; }
goto P_0c06f3e8;
P_0c06f3e6: /* original e060, guest PC 0x0c06f3e6 */
if(!s->budget--) { s->failed_pc=0x0c06f3e6u; return 0; }
r[0]=0x00000060u;
goto P_0c06f3e8;
P_0c06f3e8: /* original a001, guest PC 0x0c06f3e8 */
if(!s->budget--) { s->failed_pc=0x0c06f3e8u; return 0; }
r[12]=read(ram,r[4]+16,4);
goto P_0c06f3ee;
P_0c06f3ea: /* original 5c44, guest PC 0x0c06f3ea */
if(!s->budget--) { s->failed_pc=0x0c06f3eau; return 0; }
r[12]=read(ram,r[4]+16,4);
goto P_0c06f3ec;
P_0c06f3ec: /* original 5c45, guest PC 0x0c06f3ec */
if(!s->budget--) { s->failed_pc=0x0c06f3ecu; return 0; }
r[12]=read(ram,r[4]+20,4);
goto P_0c06f3ee;
P_0c06f3ee: /* original 04cc, guest PC 0x0c06f3ee */
if(!s->budget--) { s->failed_pc=0x0c06f3eeu; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[12]+r[0],1);
goto P_0c06f3f0;
P_0c06f3f0: /* original 604c, guest PC 0x0c06f3f0 */
if(!s->budget--) { s->failed_pc=0x0c06f3f0u; return 0; }
r[0]=r[4]&255u;
goto P_0c06f3f2;
P_0c06f3f2: /* original 880b, guest PC 0x0c06f3f2 */
if(!s->budget--) { s->failed_pc=0x0c06f3f2u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000bu)!=0);
goto P_0c06f3f4;
P_0c06f3f4: /* original 8f06, guest PC 0x0c06f3f4 */
if(!s->budget--) { s->failed_pc=0x0c06f3f4u; return 0; }
cond=r[17]&1u;
r[4]=r[0];
if(!cond) { goto P_0c06f404; }
goto P_0c06f3f8;
P_0c06f3f6: /* original 6403, guest PC 0x0c06f3f6 */
if(!s->budget--) { s->failed_pc=0x0c06f3f6u; return 0; }
r[4]=r[0];
goto P_0c06f3f8;
P_0c06f3f8: /* original 905e, guest PC 0x0c06f3f8 */
if(!s->budget--) { s->failed_pc=0x0c06f3f8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06f4b8u,2);
goto P_0c06f3fa;
P_0c06f3fa: /* original 02ec, guest PC 0x0c06f3fa */
if(!s->budget--) { s->failed_pc=0x0c06f3fau; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c06f3fc;
P_0c06f3fc: /* original 2228, guest PC 0x0c06f3fc */
if(!s->budget--) { s->failed_pc=0x0c06f3fcu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c06f3fe;
P_0c06f3fe: /* original 8b0f, guest PC 0x0c06f3fe */
if(!s->budget--) { s->failed_pc=0x0c06f3feu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06f420; }
goto P_0c06f400;
P_0c06f400: /* original a00e, guest PC 0x0c06f400 */
if(!s->budget--) { s->failed_pc=0x0c06f400u; return 0; }
goto P_0c06f420;
P_0c06f402: /* original 0009, guest PC 0x0c06f402 */
if(!s->budget--) { s->failed_pc=0x0c06f402u; return 0; }
goto P_0c06f404;
P_0c06f404: /* original 6043, guest PC 0x0c06f404 */
if(!s->budget--) { s->failed_pc=0x0c06f404u; return 0; }
r[0]=r[4];
goto P_0c06f406;
P_0c06f406: /* original 8818, guest PC 0x0c06f406 */
if(!s->budget--) { s->failed_pc=0x0c06f406u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000018u)!=0);
goto P_0c06f408;
P_0c06f408: /* original 8b05, guest PC 0x0c06f408 */
if(!s->budget--) { s->failed_pc=0x0c06f408u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06f416; }
goto P_0c06f40a;
P_0c06f40a: /* original 9055, guest PC 0x0c06f40a */
if(!s->budget--) { s->failed_pc=0x0c06f40au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06f4b8u,2);
goto P_0c06f40c;
P_0c06f40c: /* original 02ec, guest PC 0x0c06f40c */
if(!s->budget--) { s->failed_pc=0x0c06f40cu; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c06f40e;
P_0c06f40e: /* original 2228, guest PC 0x0c06f40e */
if(!s->budget--) { s->failed_pc=0x0c06f40eu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c06f410;
P_0c06f410: /* original 8906, guest PC 0x0c06f410 */
if(!s->budget--) { s->failed_pc=0x0c06f410u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c06f420; }
goto P_0c06f412;
P_0c06f412: /* original a005, guest PC 0x0c06f412 */
if(!s->budget--) { s->failed_pc=0x0c06f412u; return 0; }
goto P_0c06f420;
P_0c06f414: /* original 0009, guest PC 0x0c06f414 */
if(!s->budget--) { s->failed_pc=0x0c06f414u; return 0; }
goto P_0c06f416;
P_0c06f416: /* original 880c, guest PC 0x0c06f416 */
if(!s->budget--) { s->failed_pc=0x0c06f416u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000cu)!=0);
goto P_0c06f418;
P_0c06f418: /* original 8b02, guest PC 0x0c06f418 */
if(!s->budget--) { s->failed_pc=0x0c06f418u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06f420; }
goto P_0c06f41a;
P_0c06f41a: /* original 904e, guest PC 0x0c06f41a */
if(!s->budget--) { s->failed_pc=0x0c06f41au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06f4bau,2);
goto P_0c06f41c;
P_0c06f41c: /* original 03ec, guest PC 0x0c06f41c */
if(!s->budget--) { s->failed_pc=0x0c06f41cu; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c06f41e;
P_0c06f41e: /* original 2338, guest PC 0x0c06f41e */
if(!s->budget--) { s->failed_pc=0x0c06f41eu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c06f420;
P_0c06f420: /* original a00c, guest PC 0x0c06f420 */
if(!s->budget--) { s->failed_pc=0x0c06f420u; return 0; }
r[14]=0x00000000u;
goto P_0c06f43c;
P_0c06f422: /* original ee00, guest PC 0x0c06f422 */
if(!s->budget--) { s->failed_pc=0x0c06f422u; return 0; }
r[14]=0x00000000u;
goto P_0c06f424;
P_0c06f424: /* original 954a, guest PC 0x0c06f424 */
if(!s->budget--) { s->failed_pc=0x0c06f424u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06f4bcu,2);
goto P_0c06f426;
P_0c06f426: /* original 63d3, guest PC 0x0c06f426 */
if(!s->budget--) { s->failed_pc=0x0c06f426u; return 0; }
r[3]=r[13];
goto P_0c06f428;
P_0c06f428: /* original 7314, guest PC 0x0c06f428 */
if(!s->budget--) { s->failed_pc=0x0c06f428u; return 0; }
r[3]+=0x00000014u;
goto P_0c06f42a;
P_0c06f42a: /* original 2e5f, guest PC 0x0c06f42a */
if(!s->budget--) { s->failed_pc=0x0c06f42au; return 0; }
r[19]=(uint32_t)((int32_t)(int16_t)r[14]*(int32_t)(int16_t)r[5]);
goto P_0c06f42c;
P_0c06f42c: /* original e068, guest PC 0x0c06f42c */
if(!s->budget--) { s->failed_pc=0x0c06f42cu; return 0; }
r[0]=0x00000068u;
goto P_0c06f42e;
P_0c06f42e: /* original 051a, guest PC 0x0c06f42e */
if(!s->budget--) { s->failed_pc=0x0c06f42eu; return 0; }
r[5]=r[19];
goto P_0c06f430;
P_0c06f430: /* original 655f, guest PC 0x0c06f430 */
if(!s->budget--) { s->failed_pc=0x0c06f430u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)r[5];
goto P_0c06f432;
P_0c06f432: /* original 353c, guest PC 0x0c06f432 */
if(!s->budget--) { s->failed_pc=0x0c06f432u; return 0; }
r[5]+=r[3];
goto P_0c06f434;
P_0c06f434: /* original 0b5e, guest PC 0x0c06f434 */
if(!s->budget--) { s->failed_pc=0x0c06f434u; return 0; }
r[11]=read(ram,r[5]+r[0],4);
goto P_0c06f436;
P_0c06f436: /* original 4b0b, guest PC 0x0c06f436 */
if(!s->budget--) { s->failed_pc=0x0c06f436u; return 0; }
target=r[11];
r[16]=0x8c06f43au;
r[4]=r[12];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c06f43au) { target=s->pc; goto dispatch; }
goto P_0c06f43a;
P_0c06f438: /* original 64c3, guest PC 0x0c06f438 */
if(!s->budget--) { s->failed_pc=0x0c06f438u; return 0; }
r[4]=r[12];
goto P_0c06f43a;
P_0c06f43a: /* original 7e01, guest PC 0x0c06f43a */
if(!s->budget--) { s->failed_pc=0x0c06f43au; return 0; }
r[14]+=0x00000001u;
goto P_0c06f43c;
P_0c06f43c: /* original 53d4, guest PC 0x0c06f43c */
if(!s->budget--) { s->failed_pc=0x0c06f43cu; return 0; }
r[3]=read(ram,r[13]+16,4);
goto P_0c06f43e;
P_0c06f43e: /* original 3e32, guest PC 0x0c06f43e */
if(!s->budget--) { s->failed_pc=0x0c06f43eu; return 0; }
r[17]=(r[17]&~1u)|((r[14]>=r[3])!=0);
goto P_0c06f440;
P_0c06f440: /* original 8bf0, guest PC 0x0c06f440 */
if(!s->budget--) { s->failed_pc=0x0c06f440u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06f424; }
goto P_0c06f442;
P_0c06f442: /* original 4f16, guest PC 0x0c06f442 */
if(!s->budget--) { s->failed_pc=0x0c06f442u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c06f444;
P_0c06f444: /* original 4f26, guest PC 0x0c06f444 */
if(!s->budget--) { s->failed_pc=0x0c06f444u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c06f446;
P_0c06f446: /* original 6bf6, guest PC 0x0c06f446 */
if(!s->budget--) { s->failed_pc=0x0c06f446u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c06f448;
P_0c06f448: /* original 6cf6, guest PC 0x0c06f448 */
if(!s->budget--) { s->failed_pc=0x0c06f448u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c06f44a;
P_0c06f44a: /* original 6df6, guest PC 0x0c06f44a */
if(!s->budget--) { s->failed_pc=0x0c06f44au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c06f44c;
P_0c06f44c: /* original 000b, guest PC 0x0c06f44c */
if(!s->budget--) { s->failed_pc=0x0c06f44cu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c06f44e: /* original 6ef6, guest PC 0x0c06f44e */
if(!s->budget--) { s->failed_pc=0x0c06f44eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c06f450u,s,ram);
P_0c072b40: /* original 2fe6, guest PC 0x0c072b40 */
if(!s->budget--) { s->failed_pc=0x0c072b40u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c072b42;
P_0c072b42: /* original 2fd6, guest PC 0x0c072b42 */
if(!s->budget--) { s->failed_pc=0x0c072b42u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c072b44;
P_0c072b44: /* original 2fc6, guest PC 0x0c072b44 */
if(!s->budget--) { s->failed_pc=0x0c072b44u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c072b46;
P_0c072b46: /* original 2fb6, guest PC 0x0c072b46 */
if(!s->budget--) { s->failed_pc=0x0c072b46u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c072b48;
P_0c072b48: /* original 2fa6, guest PC 0x0c072b48 */
if(!s->budget--) { s->failed_pc=0x0c072b48u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c072b4a;
P_0c072b4a: /* original 2f96, guest PC 0x0c072b4a */
if(!s->budget--) { s->failed_pc=0x0c072b4au; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c072b4c;
P_0c072b4c: /* original 2f86, guest PC 0x0c072b4c */
if(!s->budget--) { s->failed_pc=0x0c072b4cu; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c072b4e;
P_0c072b4e: /* original fffb, guest PC 0x0c072b4e */
if(!s->budget--) { s->failed_pc=0x0c072b4eu; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c072b50;
P_0c072b50: /* original 4f22, guest PC 0x0c072b50 */
if(!s->budget--) { s->failed_pc=0x0c072b50u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c072b52;
P_0c072b52: /* original 4f12, guest PC 0x0c072b52 */
if(!s->budget--) { s->failed_pc=0x0c072b52u; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c072b54;
P_0c072b54: /* original 7ff0, guest PC 0x0c072b54 */
if(!s->budget--) { s->failed_pc=0x0c072b54u; return 0; }
r[15]+=0xfffffff0u;
goto P_0c072b56;
P_0c072b56: /* original 2f42, guest PC 0x0c072b56 */
if(!s->budget--) { s->failed_pc=0x0c072b56u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c072b58;
P_0c072b58: /* original dd1a, guest PC 0x0c072b58 */
if(!s->budget--) { s->failed_pc=0x0c072b58u; return 0; }
r[13]=read(ram,0x0c072bc4u,4);
goto P_0c072b5a;
P_0c072b5a: /* original de19, guest PC 0x0c072b5a */
if(!s->budget--) { s->failed_pc=0x0c072b5au; return 0; }
r[14]=read(ram,0x0c072bc0u,4);
goto P_0c072b5c;
P_0c072b5c: /* original 53d8, guest PC 0x0c072b5c */
if(!s->budget--) { s->failed_pc=0x0c072b5cu; return 0; }
r[3]=read(ram,r[13]+32,4);
goto P_0c072b5e;
P_0c072b5e: /* original d21a, guest PC 0x0c072b5e */
if(!s->budget--) { s->failed_pc=0x0c072b5eu; return 0; }
r[2]=read(ram,0x0c072bc8u,4);
goto P_0c072b60;
P_0c072b60: /* original 420b, guest PC 0x0c072b60 */
if(!s->budget--) { s->failed_pc=0x0c072b60u; return 0; }
target=r[2];
r[16]=0x8c072b64u;
write(ram,r[15]+12,r[3],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c072b64u) { target=s->pc; goto dispatch; }
goto P_0c072b64;
P_0c072b62: /* original 1f33, guest PC 0x0c072b62 */
if(!s->budget--) { s->failed_pc=0x0c072b62u; return 0; }
write(ram,r[15]+12,r[3],4);
goto P_0c072b64;
P_0c072b64: /* original 2008, guest PC 0x0c072b64 */
if(!s->budget--) { s->failed_pc=0x0c072b64u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c072b66;
P_0c072b66: /* original 8b01, guest PC 0x0c072b66 */
if(!s->budget--) { s->failed_pc=0x0c072b66u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c072b6c; }
goto P_0c072b68;
P_0c072b68: /* original a0bc, guest PC 0x0c072b68 */
if(!s->budget--) { s->failed_pc=0x0c072b68u; return 0; }
goto P_0c072ce4;
P_0c072b6a: /* original 0009, guest PC 0x0c072b6a */
if(!s->budget--) { s->failed_pc=0x0c072b6au; return 0; }
goto P_0c072b6c;
P_0c072b6c: /* original 62f2, guest PC 0x0c072b6c */
if(!s->budget--) { s->failed_pc=0x0c072b6cu; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c072b6e;
P_0c072b6e: /* original 8424, guest PC 0x0c072b6e */
if(!s->budget--) { s->failed_pc=0x0c072b6eu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[2]+4,1);
goto P_0c072b70;
P_0c072b70: /* original 2008, guest PC 0x0c072b70 */
if(!s->budget--) { s->failed_pc=0x0c072b70u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c072b72;
P_0c072b72: /* original 8b01, guest PC 0x0c072b72 */
if(!s->budget--) { s->failed_pc=0x0c072b72u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c072b78; }
goto P_0c072b74;
P_0c072b74: /* original a001, guest PC 0x0c072b74 */
if(!s->budget--) { s->failed_pc=0x0c072b74u; return 0; }
r[0]=0x00000048u;
goto P_0c072b7a;
P_0c072b76: /* original e048, guest PC 0x0c072b76 */
if(!s->budget--) { s->failed_pc=0x0c072b76u; return 0; }
r[0]=0x00000048u;
goto P_0c072b78;
P_0c072b78: /* original e05c, guest PC 0x0c072b78 */
if(!s->budget--) { s->failed_pc=0x0c072b78u; return 0; }
r[0]=0x0000005cu;
goto P_0c072b7a;
P_0c072b7a: /* original 0ade, guest PC 0x0c072b7a */
if(!s->budget--) { s->failed_pc=0x0c072b7au; return 0; }
r[10]=read(ram,r[13]+r[0],4);
goto P_0c072b7c;
P_0c072b7c: /* original d313, guest PC 0x0c072b7c */
if(!s->budget--) { s->failed_pc=0x0c072b7cu; return 0; }
r[3]=read(ram,0x0c072bccu,4);
goto P_0c072b7e;
P_0c072b7e: /* original 64a2, guest PC 0x0c072b7e */
if(!s->budget--) { s->failed_pc=0x0c072b7eu; return 0; }
tmp=read(ram,r[10],4);
r[4]=tmp;
goto P_0c072b80;
P_0c072b80: /* original 2348, guest PC 0x0c072b80 */
if(!s->budget--) { s->failed_pc=0x0c072b80u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[4])==0)!=0);
goto P_0c072b82;
P_0c072b82: /* original 8b01, guest PC 0x0c072b82 */
if(!s->budget--) { s->failed_pc=0x0c072b82u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c072b88; }
goto P_0c072b84;
P_0c072b84: /* original a0ae, guest PC 0x0c072b84 */
if(!s->budget--) { s->failed_pc=0x0c072b84u; return 0; }
goto P_0c072ce4;
P_0c072b86: /* original 0009, guest PC 0x0c072b86 */
if(!s->budget--) { s->failed_pc=0x0c072b86u; return 0; }
goto P_0c072b88;
P_0c072b88: /* original e101, guest PC 0x0c072b88 */
if(!s->budget--) { s->failed_pc=0x0c072b88u; return 0; }
r[1]=0x00000001u;
goto P_0c072b8a;
P_0c072b8a: /* original 2148, guest PC 0x0c072b8a */
if(!s->budget--) { s->failed_pc=0x0c072b8au; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[4])==0)!=0);
goto P_0c072b8c;
P_0c072b8c: /* original 8b01, guest PC 0x0c072b8c */
if(!s->budget--) { s->failed_pc=0x0c072b8cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c072b92; }
goto P_0c072b8e;
P_0c072b8e: /* original a0a9, guest PC 0x0c072b8e */
if(!s->budget--) { s->failed_pc=0x0c072b8eu; return 0; }
goto P_0c072ce4;
P_0c072b90: /* original 0009, guest PC 0x0c072b90 */
if(!s->budget--) { s->failed_pc=0x0c072b90u; return 0; }
goto P_0c072b92;
P_0c072b92: /* original 64f2, guest PC 0x0c072b92 */
if(!s->budget--) { s->failed_pc=0x0c072b92u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c072b94;
P_0c072b94: /* original e060, guest PC 0x0c072b94 */
if(!s->budget--) { s->failed_pc=0x0c072b94u; return 0; }
r[0]=0x00000060u;
goto P_0c072b96;
P_0c072b96: /* original 044c, guest PC 0x0c072b96 */
if(!s->budget--) { s->failed_pc=0x0c072b96u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c072b98;
P_0c072b98: /* original 644c, guest PC 0x0c072b98 */
if(!s->budget--) { s->failed_pc=0x0c072b98u; return 0; }
r[4]=r[4]&255u;
goto P_0c072b9a;
P_0c072b9a: /* original 6043, guest PC 0x0c072b9a */
if(!s->budget--) { s->failed_pc=0x0c072b9au; return 0; }
r[0]=r[4];
goto P_0c072b9c;
P_0c072b9c: /* original 880b, guest PC 0x0c072b9c */
if(!s->budget--) { s->failed_pc=0x0c072b9cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000bu)!=0);
goto P_0c072b9e;
P_0c072b9e: /* original 8b05, guest PC 0x0c072b9e */
if(!s->budget--) { s->failed_pc=0x0c072b9eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c072bac; }
goto P_0c072ba0;
P_0c072ba0: /* original 900c, guest PC 0x0c072ba0 */
if(!s->budget--) { s->failed_pc=0x0c072ba0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c072bbcu,2);
goto P_0c072ba2;
P_0c072ba2: /* original 02ec, guest PC 0x0c072ba2 */
if(!s->budget--) { s->failed_pc=0x0c072ba2u; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c072ba4;
P_0c072ba4: /* original 2228, guest PC 0x0c072ba4 */
if(!s->budget--) { s->failed_pc=0x0c072ba4u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c072ba6;
P_0c072ba6: /* original 891b, guest PC 0x0c072ba6 */
if(!s->budget--) { s->failed_pc=0x0c072ba6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c072be0; }
goto P_0c072ba8;
P_0c072ba8: /* original a01a, guest PC 0x0c072ba8 */
if(!s->budget--) { s->failed_pc=0x0c072ba8u; return 0; }
r[4]=0x0000001au;
goto P_0c072be0;
P_0c072baa: /* original e41a, guest PC 0x0c072baa */
if(!s->budget--) { s->failed_pc=0x0c072baau; return 0; }
r[4]=0x0000001au;
goto P_0c072bac;
P_0c072bac: /* original 8818, guest PC 0x0c072bac */
if(!s->budget--) { s->failed_pc=0x0c072bacu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000018u)!=0);
goto P_0c072bae;
P_0c072bae: /* original 8b0f, guest PC 0x0c072bae */
if(!s->budget--) { s->failed_pc=0x0c072baeu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c072bd0; }
goto P_0c072bb0;
P_0c072bb0: /* original 9004, guest PC 0x0c072bb0 */
if(!s->budget--) { s->failed_pc=0x0c072bb0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c072bbcu,2);
goto P_0c072bb2;
P_0c072bb2: /* original 02ec, guest PC 0x0c072bb2 */
if(!s->budget--) { s->failed_pc=0x0c072bb2u; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c072bb4;
P_0c072bb4: /* original 2228, guest PC 0x0c072bb4 */
if(!s->budget--) { s->failed_pc=0x0c072bb4u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c072bb6;
P_0c072bb6: /* original 8913, guest PC 0x0c072bb6 */
if(!s->budget--) { s->failed_pc=0x0c072bb6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c072be0; }
goto P_0c072bb8;
P_0c072bb8: /* original a012, guest PC 0x0c072bb8 */
if(!s->budget--) { s->failed_pc=0x0c072bb8u; return 0; }
r[4]=0x0000001bu;
goto P_0c072be0;
P_0c072bba: /* original e41b, guest PC 0x0c072bba */
if(!s->budget--) { s->failed_pc=0x0c072bbau; return 0; }
r[4]=0x0000001bu;
return vf3_matrix_family(0x0c072bbcu,s,ram);
P_0c072bd0: /* original 6043, guest PC 0x0c072bd0 */
if(!s->budget--) { s->failed_pc=0x0c072bd0u; return 0; }
r[0]=r[4];
goto P_0c072bd2;
P_0c072bd2: /* original 880c, guest PC 0x0c072bd2 */
if(!s->budget--) { s->failed_pc=0x0c072bd2u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000cu)!=0);
goto P_0c072bd4;
P_0c072bd4: /* original 8b04, guest PC 0x0c072bd4 */
if(!s->budget--) { s->failed_pc=0x0c072bd4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c072be0; }
goto P_0c072bd6;
P_0c072bd6: /* original 903b, guest PC 0x0c072bd6 */
if(!s->budget--) { s->failed_pc=0x0c072bd6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c072c50u,2);
goto P_0c072bd8;
P_0c072bd8: /* original 02ec, guest PC 0x0c072bd8 */
if(!s->budget--) { s->failed_pc=0x0c072bd8u; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c072bda;
P_0c072bda: /* original 2228, guest PC 0x0c072bda */
if(!s->budget--) { s->failed_pc=0x0c072bdau; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c072bdc;
P_0c072bdc: /* original 8900, guest PC 0x0c072bdc */
if(!s->budget--) { s->failed_pc=0x0c072bdcu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c072be0; }
goto P_0c072bde;
P_0c072bde: /* original e41c, guest PC 0x0c072bde */
if(!s->budget--) { s->failed_pc=0x0c072bdeu; return 0; }
r[4]=0x0000001cu;
goto P_0c072be0;
P_0c072be0: /* original d21e, guest PC 0x0c072be0 */
if(!s->budget--) { s->failed_pc=0x0c072be0u; return 0; }
r[2]=read(ram,0x0c072c5cu,4);
goto P_0c072be2;
P_0c072be2: /* original 4408, guest PC 0x0c072be2 */
if(!s->budget--) { s->failed_pc=0x0c072be2u; return 0; }
r[4]<<=2;
goto P_0c072be4;
P_0c072be4: /* original 4400, guest PC 0x0c072be4 */
if(!s->budget--) { s->failed_pc=0x0c072be4u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c072be6;
P_0c072be6: /* original 342c, guest PC 0x0c072be6 */
if(!s->budget--) { s->failed_pc=0x0c072be6u; return 0; }
r[4]+=r[2];
goto P_0c072be8;
P_0c072be8: /* original 6442, guest PC 0x0c072be8 */
if(!s->budget--) { s->failed_pc=0x0c072be8u; return 0; }
tmp=read(ram,r[4],4);
r[4]=tmp;
goto P_0c072bea;
P_0c072bea: /* original 2448, guest PC 0x0c072bea */
if(!s->budget--) { s->failed_pc=0x0c072beau; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c072bec;
P_0c072bec: /* original 897a, guest PC 0x0c072bec */
if(!s->budget--) { s->failed_pc=0x0c072becu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c072ce4; }
goto P_0c072bee;
P_0c072bee: /* original d21c, guest PC 0x0c072bee */
if(!s->budget--) { s->failed_pc=0x0c072beeu; return 0; }
r[2]=read(ram,0x0c072c60u,4);
goto P_0c072bf0;
P_0c072bf0: /* original 420b, guest PC 0x0c072bf0 */
if(!s->budget--) { s->failed_pc=0x0c072bf0u; return 0; }
target=r[2];
r[16]=0x8c072bf4u;
r[4]=0x00000000u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c072bf4u) { target=s->pc; goto dispatch; }
goto P_0c072bf4;
P_0c072bf2: /* original e400, guest PC 0x0c072bf2 */
if(!s->budget--) { s->failed_pc=0x0c072bf2u; return 0; }
r[4]=0x00000000u;
goto P_0c072bf4;
P_0c072bf4: /* original a065, guest PC 0x0c072bf4 */
if(!s->budget--) { s->failed_pc=0x0c072bf4u; return 0; }
r[11]=0x00000000u;
goto P_0c072cc2;
P_0c072bf6: /* original eb00, guest PC 0x0c072bf6 */
if(!s->budget--) { s->failed_pc=0x0c072bf6u; return 0; }
r[11]=0x00000000u;
goto P_0c072bf8;
P_0c072bf8: /* original 9e2b, guest PC 0x0c072bf8 */
if(!s->budget--) { s->failed_pc=0x0c072bf8u; return 0; }
r[14]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c072c52u,2);
goto P_0c072bfa;
P_0c072bfa: /* original 63a3, guest PC 0x0c072bfa */
if(!s->budget--) { s->failed_pc=0x0c072bfau; return 0; }
r[3]=r[10];
goto P_0c072bfc;
P_0c072bfc: /* original 902a, guest PC 0x0c072bfc */
if(!s->budget--) { s->failed_pc=0x0c072bfcu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c072c54u,2);
goto P_0c072bfe;
P_0c072bfe: /* original 7314, guest PC 0x0c072bfe */
if(!s->budget--) { s->failed_pc=0x0c072bfeu; return 0; }
r[3]+=0x00000014u;
goto P_0c072c00;
P_0c072c00: /* original 2bef, guest PC 0x0c072c00 */
if(!s->budget--) { s->failed_pc=0x0c072c00u; return 0; }
r[19]=(uint32_t)((int32_t)(int16_t)r[11]*(int32_t)(int16_t)r[14]);
goto P_0c072c02;
P_0c072c02: /* original d418, guest PC 0x0c072c02 */
if(!s->budget--) { s->failed_pc=0x0c072c02u; return 0; }
r[4]=read(ram,0x0c072c64u,4);
goto P_0c072c04;
P_0c072c04: /* original e160, guest PC 0x0c072c04 */
if(!s->budget--) { s->failed_pc=0x0c072c04u; return 0; }
r[1]=0x00000060u;
goto P_0c072c06;
P_0c072c06: /* original 0e1a, guest PC 0x0c072c06 */
if(!s->budget--) { s->failed_pc=0x0c072c06u; return 0; }
r[14]=r[19];
goto P_0c072c08;
P_0c072c08: /* original 6eef, guest PC 0x0c072c08 */
if(!s->budget--) { s->failed_pc=0x0c072c08u; return 0; }
r[14]=(uint32_t)(int32_t)(int16_t)r[14];
goto P_0c072c0a;
P_0c072c0a: /* original 3e3c, guest PC 0x0c072c0a */
if(!s->budget--) { s->failed_pc=0x0c072c0au; return 0; }
r[14]+=r[3];
goto P_0c072c0c;
P_0c072c0c: /* original 00ee, guest PC 0x0c072c0c */
if(!s->budget--) { s->failed_pc=0x0c072c0cu; return 0; }
r[0]=read(ram,r[14]+r[0],4);
goto P_0c072c0e;
P_0c072c0e: /* original 4008, guest PC 0x0c072c0e */
if(!s->budget--) { s->failed_pc=0x0c072c0eu; return 0; }
r[0]<<=2;
goto P_0c072c10;
P_0c072c10: /* original 0c4e, guest PC 0x0c072c10 */
if(!s->budget--) { s->failed_pc=0x0c072c10u; return 0; }
r[12]=read(ram,r[4]+r[0],4);
goto P_0c072c12;
P_0c072c12: /* original 60f2, guest PC 0x0c072c12 */
if(!s->budget--) { s->failed_pc=0x0c072c12u; return 0; }
tmp=read(ram,r[15],4);
r[0]=tmp;
goto P_0c072c14;
P_0c072c14: /* original 001c, guest PC 0x0c072c14 */
if(!s->budget--) { s->failed_pc=0x0c072c14u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[1]+r[0],1);
goto P_0c072c16;
P_0c072c16: /* original 600c, guest PC 0x0c072c16 */
if(!s->budget--) { s->failed_pc=0x0c072c16u; return 0; }
r[0]=r[0]&255u;
goto P_0c072c18;
P_0c072c18: /* original 8808, guest PC 0x0c072c18 */
if(!s->budget--) { s->failed_pc=0x0c072c18u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000008u)!=0);
goto P_0c072c1a;
P_0c072c1a: /* original 8b27, guest PC 0x0c072c1a */
if(!s->budget--) { s->failed_pc=0x0c072c1au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c072c6c; }
goto P_0c072c1c;
P_0c072c1c: /* original 901b, guest PC 0x0c072c1c */
if(!s->budget--) { s->failed_pc=0x0c072c1cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c072c56u,2);
goto P_0c072c1e;
P_0c072c1e: /* original 54f3, guest PC 0x0c072c1e */
if(!s->budget--) { s->failed_pc=0x0c072c1eu; return 0; }
r[4]=read(ram,r[15]+12,4);
goto P_0c072c20;
P_0c072c20: /* original 044e, guest PC 0x0c072c20 */
if(!s->budget--) { s->failed_pc=0x0c072c20u; return 0; }
r[4]=read(ram,r[4]+r[0],4);
goto P_0c072c22;
P_0c072c22: /* original 6043, guest PC 0x0c072c22 */
if(!s->budget--) { s->failed_pc=0x0c072c22u; return 0; }
r[0]=r[4];
goto P_0c072c24;
P_0c072c24: /* original 8804, guest PC 0x0c072c24 */
if(!s->budget--) { s->failed_pc=0x0c072c24u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000004u)!=0);
goto P_0c072c26;
P_0c072c26: /* original 8902, guest PC 0x0c072c26 */
if(!s->budget--) { s->failed_pc=0x0c072c26u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c072c2e; }
goto P_0c072c28;
P_0c072c28: /* original 6043, guest PC 0x0c072c28 */
if(!s->budget--) { s->failed_pc=0x0c072c28u; return 0; }
r[0]=r[4];
goto P_0c072c2a;
P_0c072c2a: /* original 8814, guest PC 0x0c072c2a */
if(!s->budget--) { s->failed_pc=0x0c072c2au; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000014u)!=0);
goto P_0c072c2c;
P_0c072c2c: /* original 8b06, guest PC 0x0c072c2c */
if(!s->budget--) { s->failed_pc=0x0c072c2cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c072c3c; }
goto P_0c072c2e;
P_0c072c2e: /* original d20e, guest PC 0x0c072c2e */
if(!s->budget--) { s->failed_pc=0x0c072c2eu; return 0; }
r[2]=read(ram,0x0c072c68u,4);
goto P_0c072c30;
P_0c072c30: /* original 6320, guest PC 0x0c072c30 */
if(!s->budget--) { s->failed_pc=0x0c072c30u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[2],1);
r[3]=tmp;
goto P_0c072c32;
P_0c072c32: /* original 2338, guest PC 0x0c072c32 */
if(!s->budget--) { s->failed_pc=0x0c072c32u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c072c34;
P_0c072c34: /* original 8902, guest PC 0x0c072c34 */
if(!s->budget--) { s->failed_pc=0x0c072c34u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c072c3c; }
goto P_0c072c36;
P_0c072c36: /* original 900f, guest PC 0x0c072c36 */
if(!s->budget--) { s->failed_pc=0x0c072c36u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c072c58u,2);
goto P_0c072c38;
P_0c072c38: /* original e414, guest PC 0x0c072c38 */
if(!s->budget--) { s->failed_pc=0x0c072c38u; return 0; }
r[4]=0x00000014u;
goto P_0c072c3a;
P_0c072c3a: /* original 0e46, guest PC 0x0c072c3a */
if(!s->budget--) { s->failed_pc=0x0c072c3au; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c072c3c;
P_0c072c3c: /* original 900c, guest PC 0x0c072c3c */
if(!s->budget--) { s->failed_pc=0x0c072c3cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c072c58u,2);
goto P_0c072c3e;
P_0c072c3e: /* original 03ee, guest PC 0x0c072c3e */
if(!s->budget--) { s->failed_pc=0x0c072c3eu; return 0; }
r[3]=read(ram,r[14]+r[0],4);
goto P_0c072c40;
P_0c072c40: /* original 4315, guest PC 0x0c072c40 */
if(!s->budget--) { s->failed_pc=0x0c072c40u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>0)!=0);
goto P_0c072c42;
P_0c072c42: /* original 8b13, guest PC 0x0c072c42 */
if(!s->budget--) { s->failed_pc=0x0c072c42u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c072c6c; }
goto P_0c072c44;
P_0c072c44: /* original 2bb8, guest PC 0x0c072c44 */
if(!s->budget--) { s->failed_pc=0x0c072c44u; return 0; }
r[17]=(r[17]&~1u)|(((r[11]&r[11])==0)!=0);
goto P_0c072c46;
P_0c072c46: /* original 8b11, guest PC 0x0c072c46 */
if(!s->budget--) { s->failed_pc=0x0c072c46u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c072c6c; }
goto P_0c072c48;
P_0c072c48: /* original 03ee, guest PC 0x0c072c48 */
if(!s->budget--) { s->failed_pc=0x0c072c48u; return 0; }
r[3]=read(ram,r[14]+r[0],4);
goto P_0c072c4a;
P_0c072c4a: /* original 73ff, guest PC 0x0c072c4a */
if(!s->budget--) { s->failed_pc=0x0c072c4au; return 0; }
r[3]+=0xffffffffu;
goto P_0c072c4c;
P_0c072c4c: /* original a038, guest PC 0x0c072c4c */
if(!s->budget--) { s->failed_pc=0x0c072c4cu; return 0; }
write(ram,r[14]+r[0],r[3],4);
goto P_0c072cc0;
P_0c072c4e: /* original 0e36, guest PC 0x0c072c4e */
if(!s->budget--) { s->failed_pc=0x0c072c4eu; return 0; }
write(ram,r[14]+r[0],r[3],4);
return vf3_matrix_family(0x0c072c50u,s,ram);
P_0c072c6c: /* original 2cc8, guest PC 0x0c072c6c */
if(!s->budget--) { s->failed_pc=0x0c072c6cu; return 0; }
r[17]=(r[17]&~1u)|(((r[12]&r[12])==0)!=0);
goto P_0c072c6e;
P_0c072c6e: /* original 8927, guest PC 0x0c072c6e */
if(!s->budget--) { s->failed_pc=0x0c072c6eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c072cc0; }
goto P_0c072c70;
P_0c072c70: /* original 58c1, guest PC 0x0c072c70 */
if(!s->budget--) { s->failed_pc=0x0c072c70u; return 0; }
r[8]=read(ram,r[12]+4,4);
goto P_0c072c72;
P_0c072c72: /* original 64e2, guest PC 0x0c072c72 */
if(!s->budget--) { s->failed_pc=0x0c072c72u; return 0; }
tmp=read(ram,r[14],4);
r[4]=tmp;
goto P_0c072c74;
P_0c072c74: /* original 5381, guest PC 0x0c072c74 */
if(!s->budget--) { s->failed_pc=0x0c072c74u; return 0; }
r[3]=read(ram,r[8]+4,4);
goto P_0c072c76;
P_0c072c76: /* original 5dcb, guest PC 0x0c072c76 */
if(!s->budget--) { s->failed_pc=0x0c072c76u; return 0; }
r[13]=read(ram,r[12]+44,4);
goto P_0c072c78;
P_0c072c78: /* original 2448, guest PC 0x0c072c78 */
if(!s->budget--) { s->failed_pc=0x0c072c78u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c072c7a;
P_0c072c7a: /* original 8d02, guest PC 0x0c072c7a */
if(!s->budget--) { s->failed_pc=0x0c072c7au; return 0; }
cond=r[17]&1u;
write(ram,r[15]+4,r[3],4);
if(cond) { goto P_0c072c82; }
goto P_0c072c7e;
P_0c072c7c: /* original 1f31, guest PC 0x0c072c7c */
if(!s->budget--) { s->failed_pc=0x0c072c7cu; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c072c7e;
P_0c072c7e: /* original 51e1, guest PC 0x0c072c7e */
if(!s->budget--) { s->failed_pc=0x0c072c7eu; return 0; }
r[1]=read(ram,r[14]+4,4);
goto P_0c072c80;
P_0c072c80: /* original 1811, guest PC 0x0c072c80 */
if(!s->budget--) { s->failed_pc=0x0c072c80u; return 0; }
write(ram,r[8]+4,r[1],4);
goto P_0c072c82;
P_0c072c82: /* original 2dd8, guest PC 0x0c072c82 */
if(!s->budget--) { s->failed_pc=0x0c072c82u; return 0; }
r[17]=(r[17]&~1u)|(((r[13]&r[13])==0)!=0);
goto P_0c072c84;
P_0c072c84: /* original 8906, guest PC 0x0c072c84 */
if(!s->budget--) { s->failed_pc=0x0c072c84u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c072c94; }
goto P_0c072c86;
P_0c072c86: /* original 59d1, guest PC 0x0c072c86 */
if(!s->budget--) { s->failed_pc=0x0c072c86u; return 0; }
r[9]=read(ram,r[13]+4,4);
goto P_0c072c88;
P_0c072c88: /* original 2448, guest PC 0x0c072c88 */
if(!s->budget--) { s->failed_pc=0x0c072c88u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c072c8a;
P_0c072c8a: /* original 5291, guest PC 0x0c072c8a */
if(!s->budget--) { s->failed_pc=0x0c072c8au; return 0; }
r[2]=read(ram,r[9]+4,4);
goto P_0c072c8c;
P_0c072c8c: /* original 8d02, guest PC 0x0c072c8c */
if(!s->budget--) { s->failed_pc=0x0c072c8cu; return 0; }
cond=r[17]&1u;
write(ram,r[15]+8,r[2],4);
if(cond) { goto P_0c072c94; }
goto P_0c072c90;
P_0c072c8e: /* original 1f22, guest PC 0x0c072c8e */
if(!s->budget--) { s->failed_pc=0x0c072c8eu; return 0; }
write(ram,r[15]+8,r[2],4);
goto P_0c072c90;
P_0c072c90: /* original 51e2, guest PC 0x0c072c90 */
if(!s->budget--) { s->failed_pc=0x0c072c90u; return 0; }
r[1]=read(ram,r[14]+8,4);
goto P_0c072c92;
P_0c072c92: /* original 1911, guest PC 0x0c072c92 */
if(!s->budget--) { s->failed_pc=0x0c072c92u; return 0; }
write(ram,r[9]+4,r[1],4);
goto P_0c072c94;
P_0c072c94: /* original d319, guest PC 0x0c072c94 */
if(!s->budget--) { s->failed_pc=0x0c072c94u; return 0; }
r[3]=read(ram,0x0c072cfcu,4);
goto P_0c072c96;
P_0c072c96: /* original 430b, guest PC 0x0c072c96 */
if(!s->budget--) { s->failed_pc=0x0c072c96u; return 0; }
target=r[3];
r[16]=0x8c072c9au;
r[4]=read(ram,r[14]+12,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c072c9au) { target=s->pc; goto dispatch; }
goto P_0c072c9a;
P_0c072c98: /* original 54e3, guest PC 0x0c072c98 */
if(!s->budget--) { s->failed_pc=0x0c072c98u; return 0; }
r[4]=read(ram,r[14]+12,4);
goto P_0c072c9a;
P_0c072c9a: /* original ff9d, guest PC 0x0c072c9a */
if(!s->budget--) { s->failed_pc=0x0c072c9au; return 0; }
fr[15]=0x3f800000u;
goto P_0c072c9c;
P_0c072c9c: /* original de18, guest PC 0x0c072c9c */
if(!s->budget--) { s->failed_pc=0x0c072c9cu; return 0; }
r[14]=read(ram,0x0c072d00u,4);
goto P_0c072c9e;
P_0c072c9e: /* original f4fc, guest PC 0x0c072c9e */
if(!s->budget--) { s->failed_pc=0x0c072c9eu; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c072ca0;
P_0c072ca0: /* original 4e0b, guest PC 0x0c072ca0 */
if(!s->budget--) { s->failed_pc=0x0c072ca0u; return 0; }
target=r[14];
r[16]=0x8c072ca4u;
r[4]=r[12];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c072ca4u) { target=s->pc; goto dispatch; }
goto P_0c072ca4;
P_0c072ca2: /* original 64c3, guest PC 0x0c072ca2 */
if(!s->budget--) { s->failed_pc=0x0c072ca2u; return 0; }
r[4]=r[12];
goto P_0c072ca4;
P_0c072ca4: /* original 2dd8, guest PC 0x0c072ca4 */
if(!s->budget--) { s->failed_pc=0x0c072ca4u; return 0; }
r[17]=(r[17]&~1u)|(((r[13]&r[13])==0)!=0);
goto P_0c072ca6;
P_0c072ca6: /* original 8902, guest PC 0x0c072ca6 */
if(!s->budget--) { s->failed_pc=0x0c072ca6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c072cae; }
goto P_0c072ca8;
P_0c072ca8: /* original f4fc, guest PC 0x0c072ca8 */
if(!s->budget--) { s->failed_pc=0x0c072ca8u; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c072caa;
P_0c072caa: /* original 4e0b, guest PC 0x0c072caa */
if(!s->budget--) { s->failed_pc=0x0c072caau; return 0; }
target=r[14];
r[16]=0x8c072caeu;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c072caeu) { target=s->pc; goto dispatch; }
goto P_0c072cae;
P_0c072cac: /* original 64d3, guest PC 0x0c072cac */
if(!s->budget--) { s->failed_pc=0x0c072cacu; return 0; }
r[4]=r[13];
goto P_0c072cae;
P_0c072cae: /* original de15, guest PC 0x0c072cae */
if(!s->budget--) { s->failed_pc=0x0c072caeu; return 0; }
r[14]=read(ram,0x0c072d04u,4);
goto P_0c072cb0;
P_0c072cb0: /* original 4e0b, guest PC 0x0c072cb0 */
if(!s->budget--) { s->failed_pc=0x0c072cb0u; return 0; }
target=r[14];
r[16]=0x8c072cb4u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c072cb4u) { target=s->pc; goto dispatch; }
goto P_0c072cb4;
P_0c072cb2: /* original 0009, guest PC 0x0c072cb2 */
if(!s->budget--) { s->failed_pc=0x0c072cb2u; return 0; }
goto P_0c072cb4;
P_0c072cb4: /* original 53f1, guest PC 0x0c072cb4 */
if(!s->budget--) { s->failed_pc=0x0c072cb4u; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c072cb6;
P_0c072cb6: /* original 2dd8, guest PC 0x0c072cb6 */
if(!s->budget--) { s->failed_pc=0x0c072cb6u; return 0; }
r[17]=(r[17]&~1u)|(((r[13]&r[13])==0)!=0);
goto P_0c072cb8;
P_0c072cb8: /* original 8d02, guest PC 0x0c072cb8 */
if(!s->budget--) { s->failed_pc=0x0c072cb8u; return 0; }
cond=r[17]&1u;
write(ram,r[8]+4,r[3],4);
if(cond) { goto P_0c072cc0; }
goto P_0c072cbc;
P_0c072cba: /* original 1831, guest PC 0x0c072cba */
if(!s->budget--) { s->failed_pc=0x0c072cbau; return 0; }
write(ram,r[8]+4,r[3],4);
goto P_0c072cbc;
P_0c072cbc: /* original 51f2, guest PC 0x0c072cbc */
if(!s->budget--) { s->failed_pc=0x0c072cbcu; return 0; }
r[1]=read(ram,r[15]+8,4);
goto P_0c072cbe;
P_0c072cbe: /* original 1911, guest PC 0x0c072cbe */
if(!s->budget--) { s->failed_pc=0x0c072cbeu; return 0; }
write(ram,r[9]+4,r[1],4);
goto P_0c072cc0;
P_0c072cc0: /* original 7b01, guest PC 0x0c072cc0 */
if(!s->budget--) { s->failed_pc=0x0c072cc0u; return 0; }
r[11]+=0x00000001u;
goto P_0c072cc2;
P_0c072cc2: /* original 53a4, guest PC 0x0c072cc2 */
if(!s->budget--) { s->failed_pc=0x0c072cc2u; return 0; }
r[3]=read(ram,r[10]+16,4);
goto P_0c072cc4;
P_0c072cc4: /* original 3b32, guest PC 0x0c072cc4 */
if(!s->budget--) { s->failed_pc=0x0c072cc4u; return 0; }
r[17]=(r[17]&~1u)|((r[11]>=r[3])!=0);
goto P_0c072cc6;
P_0c072cc6: /* original 8b97, guest PC 0x0c072cc6 */
if(!s->budget--) { s->failed_pc=0x0c072cc6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c072bf8; }
goto P_0c072cc8;
P_0c072cc8: /* original 7f10, guest PC 0x0c072cc8 */
if(!s->budget--) { s->failed_pc=0x0c072cc8u; return 0; }
r[15]+=0x00000010u;
goto P_0c072cca;
P_0c072cca: /* original d30f, guest PC 0x0c072cca */
if(!s->budget--) { s->failed_pc=0x0c072ccau; return 0; }
r[3]=read(ram,0x0c072d08u,4);
goto P_0c072ccc;
P_0c072ccc: /* original 4f16, guest PC 0x0c072ccc */
if(!s->budget--) { s->failed_pc=0x0c072cccu; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c072cce;
P_0c072cce: /* original e401, guest PC 0x0c072cce */
if(!s->budget--) { s->failed_pc=0x0c072cceu; return 0; }
r[4]=0x00000001u;
goto P_0c072cd0;
P_0c072cd0: /* original 4f26, guest PC 0x0c072cd0 */
if(!s->budget--) { s->failed_pc=0x0c072cd0u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c072cd2;
P_0c072cd2: /* original fff9, guest PC 0x0c072cd2 */
if(!s->budget--) { s->failed_pc=0x0c072cd2u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c072cd4;
P_0c072cd4: /* original 68f6, guest PC 0x0c072cd4 */
if(!s->budget--) { s->failed_pc=0x0c072cd4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c072cd6;
P_0c072cd6: /* original 69f6, guest PC 0x0c072cd6 */
if(!s->budget--) { s->failed_pc=0x0c072cd6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c072cd8;
P_0c072cd8: /* original 6af6, guest PC 0x0c072cd8 */
if(!s->budget--) { s->failed_pc=0x0c072cd8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c072cda;
P_0c072cda: /* original 6bf6, guest PC 0x0c072cda */
if(!s->budget--) { s->failed_pc=0x0c072cdau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c072cdc;
P_0c072cdc: /* original 6cf6, guest PC 0x0c072cdc */
if(!s->budget--) { s->failed_pc=0x0c072cdcu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c072cde;
P_0c072cde: /* original 6df6, guest PC 0x0c072cde */
if(!s->budget--) { s->failed_pc=0x0c072cdeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c072ce0;
P_0c072ce0: /* original 432b, guest PC 0x0c072ce0 */
if(!s->budget--) { s->failed_pc=0x0c072ce0u; return 0; }
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
P_0c072ce2: /* original 6ef6, guest PC 0x0c072ce2 */
if(!s->budget--) { s->failed_pc=0x0c072ce2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c072ce4;
P_0c072ce4: /* original 7f10, guest PC 0x0c072ce4 */
if(!s->budget--) { s->failed_pc=0x0c072ce4u; return 0; }
r[15]+=0x00000010u;
goto P_0c072ce6;
P_0c072ce6: /* original 4f16, guest PC 0x0c072ce6 */
if(!s->budget--) { s->failed_pc=0x0c072ce6u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c072ce8;
P_0c072ce8: /* original 4f26, guest PC 0x0c072ce8 */
if(!s->budget--) { s->failed_pc=0x0c072ce8u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c072cea;
P_0c072cea: /* original fff9, guest PC 0x0c072cea */
if(!s->budget--) { s->failed_pc=0x0c072ceau; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c072cec;
P_0c072cec: /* original 68f6, guest PC 0x0c072cec */
if(!s->budget--) { s->failed_pc=0x0c072cecu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c072cee;
P_0c072cee: /* original 69f6, guest PC 0x0c072cee */
if(!s->budget--) { s->failed_pc=0x0c072ceeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c072cf0;
P_0c072cf0: /* original 6af6, guest PC 0x0c072cf0 */
if(!s->budget--) { s->failed_pc=0x0c072cf0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c072cf2;
P_0c072cf2: /* original 6bf6, guest PC 0x0c072cf2 */
if(!s->budget--) { s->failed_pc=0x0c072cf2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c072cf4;
P_0c072cf4: /* original 6cf6, guest PC 0x0c072cf4 */
if(!s->budget--) { s->failed_pc=0x0c072cf4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c072cf6;
P_0c072cf6: /* original 6df6, guest PC 0x0c072cf6 */
if(!s->budget--) { s->failed_pc=0x0c072cf6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c072cf8;
P_0c072cf8: /* original 000b, guest PC 0x0c072cf8 */
if(!s->budget--) { s->failed_pc=0x0c072cf8u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c072cfa: /* original 6ef6, guest PC 0x0c072cfa */
if(!s->budget--) { s->failed_pc=0x0c072cfau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c072cfcu,s,ram);
P_0c0738ea: /* original 2fe6, guest PC 0x0c0738ea */
if(!s->budget--) { s->failed_pc=0x0c0738eau; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0738ec;
P_0c0738ec: /* original 2fd6, guest PC 0x0c0738ec */
if(!s->budget--) { s->failed_pc=0x0c0738ecu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0738ee;
P_0c0738ee: /* original 2fc6, guest PC 0x0c0738ee */
if(!s->budget--) { s->failed_pc=0x0c0738eeu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0738f0;
P_0c0738f0: /* original 6c43, guest PC 0x0c0738f0 */
if(!s->budget--) { s->failed_pc=0x0c0738f0u; return 0; }
r[12]=r[4];
goto P_0c0738f2;
P_0c0738f2: /* original fffb, guest PC 0x0c0738f2 */
if(!s->budget--) { s->failed_pc=0x0c0738f2u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c0738f4;
P_0c0738f4: /* original d11a, guest PC 0x0c0738f4 */
if(!s->budget--) { s->failed_pc=0x0c0738f4u; return 0; }
r[1]=read(ram,0x0c073960u,4);
goto P_0c0738f6;
P_0c0738f6: /* original d418, guest PC 0x0c0738f6 */
if(!s->budget--) { s->failed_pc=0x0c0738f6u; return 0; }
r[4]=read(ram,0x0c073958u,4);
goto P_0c0738f8;
P_0c0738f8: /* original 6212, guest PC 0x0c0738f8 */
if(!s->budget--) { s->failed_pc=0x0c0738f8u; return 0; }
tmp=read(ram,r[1],4);
r[2]=tmp;
goto P_0c0738fa;
P_0c0738fa: /* original d318, guest PC 0x0c0738fa */
if(!s->budget--) { s->failed_pc=0x0c0738fau; return 0; }
r[3]=read(ram,0x0c07395cu,4);
goto P_0c0738fc;
P_0c0738fc: /* original 4f22, guest PC 0x0c0738fc */
if(!s->budget--) { s->failed_pc=0x0c0738fcu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0738fe;
P_0c0738fe: /* original 5e44, guest PC 0x0c0738fe */
if(!s->budget--) { s->failed_pc=0x0c0738feu; return 0; }
r[14]=read(ram,r[4]+16,4);
goto P_0c073900;
P_0c073900: /* original 2238, guest PC 0x0c073900 */
if(!s->budget--) { s->failed_pc=0x0c073900u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c073902;
P_0c073902: /* original 8d02, guest PC 0x0c073902 */
if(!s->budget--) { s->failed_pc=0x0c073902u; return 0; }
cond=r[17]&1u;
r[13]=read(ram,r[4]+20,4);
if(cond) { goto P_0c07390a; }
goto P_0c073906;
P_0c073904: /* original 5d45, guest PC 0x0c073904 */
if(!s->budget--) { s->failed_pc=0x0c073904u; return 0; }
r[13]=read(ram,r[4]+20,4);
goto P_0c073906;
P_0c073906: /* original a0b5, guest PC 0x0c073906 */
if(!s->budget--) { s->failed_pc=0x0c073906u; return 0; }
goto P_0c073a74;
P_0c073908: /* original 0009, guest PC 0x0c073908 */
if(!s->budget--) { s->failed_pc=0x0c073908u; return 0; }
goto P_0c07390a;
P_0c07390a: /* original 63e2, guest PC 0x0c07390a */
if(!s->budget--) { s->failed_pc=0x0c07390au; return 0; }
tmp=read(ram,r[14],4);
r[3]=tmp;
goto P_0c07390c;
P_0c07390c: /* original 65d3, guest PC 0x0c07390c */
if(!s->budget--) { s->failed_pc=0x0c07390cu; return 0; }
r[5]=r[13];
goto P_0c07390e;
P_0c07390e: /* original d41a, guest PC 0x0c07390e */
if(!s->budget--) { s->failed_pc=0x0c07390eu; return 0; }
r[4]=read(ram,0x0c073978u,4);
goto P_0c073910;
P_0c073910: /* original 2349, guest PC 0x0c073910 */
if(!s->budget--) { s->failed_pc=0x0c073910u; return 0; }
r[3]&=r[4];
goto P_0c073912;
P_0c073912: /* original 2e32, guest PC 0x0c073912 */
if(!s->budget--) { s->failed_pc=0x0c073912u; return 0; }
write(ram,r[14],r[3],4);
goto P_0c073914;
P_0c073914: /* original 62d2, guest PC 0x0c073914 */
if(!s->budget--) { s->failed_pc=0x0c073914u; return 0; }
tmp=read(ram,r[13],4);
r[2]=tmp;
goto P_0c073916;
P_0c073916: /* original 2249, guest PC 0x0c073916 */
if(!s->budget--) { s->failed_pc=0x0c073916u; return 0; }
r[2]&=r[4];
goto P_0c073918;
P_0c073918: /* original 2d22, guest PC 0x0c073918 */
if(!s->budget--) { s->failed_pc=0x0c073918u; return 0; }
write(ram,r[13],r[2],4);
goto P_0c07391a;
P_0c07391a: /* original 901a, guest PC 0x0c07391a */
if(!s->budget--) { s->failed_pc=0x0c07391au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c073952u,2);
goto P_0c07391c;
P_0c07391c: /* original ff8d, guest PC 0x0c07391c */
if(!s->budget--) { s->failed_pc=0x0c07391cu; return 0; }
fr[15]=0;
goto P_0c07391e;
P_0c07391e: /* original fef7, guest PC 0x0c07391e */
if(!s->budget--) { s->failed_pc=0x0c07391eu; return 0; }
vf3_matrix_store(s,ram,15,r[14]+r[0]);
goto P_0c073920;
P_0c073920: /* original 7004, guest PC 0x0c073920 */
if(!s->budget--) { s->failed_pc=0x0c073920u; return 0; }
r[0]+=0x00000004u;
goto P_0c073922;
P_0c073922: /* original fef7, guest PC 0x0c073922 */
if(!s->budget--) { s->failed_pc=0x0c073922u; return 0; }
vf3_matrix_store(s,ram,15,r[14]+r[0]);
goto P_0c073924;
P_0c073924: /* original 7004, guest PC 0x0c073924 */
if(!s->budget--) { s->failed_pc=0x0c073924u; return 0; }
r[0]+=0x00000004u;
goto P_0c073926;
P_0c073926: /* original fef7, guest PC 0x0c073926 */
if(!s->budget--) { s->failed_pc=0x0c073926u; return 0; }
vf3_matrix_store(s,ram,15,r[14]+r[0]);
goto P_0c073928;
P_0c073928: /* original 70f8, guest PC 0x0c073928 */
if(!s->budget--) { s->failed_pc=0x0c073928u; return 0; }
r[0]+=0xfffffff8u;
goto P_0c07392a;
P_0c07392a: /* original fdf7, guest PC 0x0c07392a */
if(!s->budget--) { s->failed_pc=0x0c07392au; return 0; }
vf3_matrix_store(s,ram,15,r[13]+r[0]);
goto P_0c07392c;
P_0c07392c: /* original 7004, guest PC 0x0c07392c */
if(!s->budget--) { s->failed_pc=0x0c07392cu; return 0; }
r[0]+=0x00000004u;
goto P_0c07392e;
P_0c07392e: /* original fdf7, guest PC 0x0c07392e */
if(!s->budget--) { s->failed_pc=0x0c07392eu; return 0; }
vf3_matrix_store(s,ram,15,r[13]+r[0]);
goto P_0c073930;
P_0c073930: /* original 7004, guest PC 0x0c073930 */
if(!s->budget--) { s->failed_pc=0x0c073930u; return 0; }
r[0]+=0x00000004u;
goto P_0c073932;
P_0c073932: /* original fdf7, guest PC 0x0c073932 */
if(!s->budget--) { s->failed_pc=0x0c073932u; return 0; }
vf3_matrix_store(s,ram,15,r[13]+r[0]);
goto P_0c073934;
P_0c073934: /* original b325, guest PC 0x0c073934 */
if(!s->budget--) { s->failed_pc=0x0c073934u; return 0; }
target=0x0c073f82u; r[16]=0x8c073938u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c073938u) { target=s->pc; goto dispatch; }
goto P_0c073938;
P_0c073936: /* original 64e3, guest PC 0x0c073936 */
if(!s->budget--) { s->failed_pc=0x0c073936u; return 0; }
r[4]=r[14];
goto P_0c073938;
P_0c073938: /* original d310, guest PC 0x0c073938 */
if(!s->budget--) { s->failed_pc=0x0c073938u; return 0; }
r[3]=read(ram,0x0c07397cu,4);
goto P_0c07393a;
P_0c07393a: /* original 6030, guest PC 0x0c07393a */
if(!s->budget--) { s->failed_pc=0x0c07393au; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[3],1);
r[0]=tmp;
goto P_0c07393c;
P_0c07393c: /* original 600c, guest PC 0x0c07393c */
if(!s->budget--) { s->failed_pc=0x0c07393cu; return 0; }
r[0]=r[0]&255u;
goto P_0c07393e;
P_0c07393e: /* original c90f, guest PC 0x0c07393e */
if(!s->budget--) { s->failed_pc=0x0c07393eu; return 0; }
r[0]&=15u;
goto P_0c073940;
P_0c073940: /* original 880f, guest PC 0x0c073940 */
if(!s->budget--) { s->failed_pc=0x0c073940u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000fu)!=0);
goto P_0c073942;
P_0c073942: /* original 8b1f, guest PC 0x0c073942 */
if(!s->budget--) { s->failed_pc=0x0c073942u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c073984; }
goto P_0c073944;
P_0c073944: /* original d10e, guest PC 0x0c073944 */
if(!s->budget--) { s->failed_pc=0x0c073944u; return 0; }
r[1]=read(ram,0x0c073980u,4);
goto P_0c073946;
P_0c073946: /* original 65d3, guest PC 0x0c073946 */
if(!s->budget--) { s->failed_pc=0x0c073946u; return 0; }
r[5]=r[13];
goto P_0c073948;
P_0c073948: /* original 410b, guest PC 0x0c073948 */
if(!s->budget--) { s->failed_pc=0x0c073948u; return 0; }
target=r[1];
r[16]=0x8c07394cu;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07394cu) { target=s->pc; goto dispatch; }
goto P_0c07394c;
P_0c07394a: /* original 64e3, guest PC 0x0c07394a */
if(!s->budget--) { s->failed_pc=0x0c07394au; return 0; }
r[4]=r[14];
goto P_0c07394c;
P_0c07394c: /* original a030, guest PC 0x0c07394c */
if(!s->budget--) { s->failed_pc=0x0c07394cu; return 0; }
goto P_0c0739b0;
P_0c07394e: /* original 0009, guest PC 0x0c07394e */
if(!s->budget--) { s->failed_pc=0x0c07394eu; return 0; }
return vf3_matrix_family(0x0c073950u,s,ram);
P_0c073984: /* original d241, guest PC 0x0c073984 */
if(!s->budget--) { s->failed_pc=0x0c073984u; return 0; }
r[2]=read(ram,0x0c073a8cu,4);
goto P_0c073986;
P_0c073986: /* original 6022, guest PC 0x0c073986 */
if(!s->budget--) { s->failed_pc=0x0c073986u; return 0; }
tmp=read(ram,r[2],4);
r[0]=tmp;
goto P_0c073988;
P_0c073988: /* original c802, guest PC 0x0c073988 */
if(!s->budget--) { s->failed_pc=0x0c073988u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&2u)==0)!=0);
goto P_0c07398a;
P_0c07398a: /* original 8911, guest PC 0x0c07398a */
if(!s->budget--) { s->failed_pc=0x0c07398au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0739b0; }
goto P_0c07398c;
P_0c07398c: /* original d140, guest PC 0x0c07398c */
if(!s->budget--) { s->failed_pc=0x0c07398cu; return 0; }
r[1]=read(ram,0x0c073a90u,4);
goto P_0c07398e;
P_0c07398e: /* original 65e3, guest PC 0x0c07398e */
if(!s->budget--) { s->failed_pc=0x0c07398eu; return 0; }
r[5]=r[14];
goto P_0c073990;
P_0c073990: /* original 66d3, guest PC 0x0c073990 */
if(!s->budget--) { s->failed_pc=0x0c073990u; return 0; }
r[6]=r[13];
goto P_0c073992;
P_0c073992: /* original 410b, guest PC 0x0c073992 */
if(!s->budget--) { s->failed_pc=0x0c073992u; return 0; }
target=r[1];
r[16]=0x8c073996u;
r[4]=r[12];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c073996u) { target=s->pc; goto dispatch; }
goto P_0c073996;
P_0c073994: /* original 64c3, guest PC 0x0c073994 */
if(!s->budget--) { s->failed_pc=0x0c073994u; return 0; }
r[4]=r[12];
goto P_0c073996;
P_0c073996: /* original 65d3, guest PC 0x0c073996 */
if(!s->budget--) { s->failed_pc=0x0c073996u; return 0; }
r[5]=r[13];
goto P_0c073998;
P_0c073998: /* original b6b3, guest PC 0x0c073998 */
if(!s->budget--) { s->failed_pc=0x0c073998u; return 0; }
target=0x0c074702u; r[16]=0x8c07399cu;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07399cu) { target=s->pc; goto dispatch; }
goto P_0c07399c;
P_0c07399a: /* original 64e3, guest PC 0x0c07399a */
if(!s->budget--) { s->failed_pc=0x0c07399au; return 0; }
r[4]=r[14];
goto P_0c07399c;
P_0c07399c: /* original 65e3, guest PC 0x0c07399c */
if(!s->budget--) { s->failed_pc=0x0c07399cu; return 0; }
r[5]=r[14];
goto P_0c07399e;
P_0c07399e: /* original b6b0, guest PC 0x0c07399e */
if(!s->budget--) { s->failed_pc=0x0c07399eu; return 0; }
target=0x0c074702u; r[16]=0x8c0739a2u;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0739a2u) { target=s->pc; goto dispatch; }
goto P_0c0739a2;
P_0c0739a0: /* original 64d3, guest PC 0x0c0739a0 */
if(!s->budget--) { s->failed_pc=0x0c0739a0u; return 0; }
r[4]=r[13];
goto P_0c0739a2;
P_0c0739a2: /* original 65d3, guest PC 0x0c0739a2 */
if(!s->budget--) { s->failed_pc=0x0c0739a2u; return 0; }
r[5]=r[13];
goto P_0c0739a4;
P_0c0739a4: /* original b705, guest PC 0x0c0739a4 */
if(!s->budget--) { s->failed_pc=0x0c0739a4u; return 0; }
target=0x0c0747b2u; r[16]=0x8c0739a8u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0739a8u) { target=s->pc; goto dispatch; }
goto P_0c0739a8;
P_0c0739a6: /* original 64e3, guest PC 0x0c0739a6 */
if(!s->budget--) { s->failed_pc=0x0c0739a6u; return 0; }
r[4]=r[14];
goto P_0c0739a8;
P_0c0739a8: /* original d23a, guest PC 0x0c0739a8 */
if(!s->budget--) { s->failed_pc=0x0c0739a8u; return 0; }
r[2]=read(ram,0x0c073a94u,4);
goto P_0c0739aa;
P_0c0739aa: /* original 65d3, guest PC 0x0c0739aa */
if(!s->budget--) { s->failed_pc=0x0c0739aau; return 0; }
r[5]=r[13];
goto P_0c0739ac;
P_0c0739ac: /* original 420b, guest PC 0x0c0739ac */
if(!s->budget--) { s->failed_pc=0x0c0739acu; return 0; }
target=r[2];
r[16]=0x8c0739b0u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0739b0u) { target=s->pc; goto dispatch; }
goto P_0c0739b0;
P_0c0739ae: /* original 64e3, guest PC 0x0c0739ae */
if(!s->budget--) { s->failed_pc=0x0c0739aeu; return 0; }
r[4]=r[14];
goto P_0c0739b0;
P_0c0739b0: /* original d339, guest PC 0x0c0739b0 */
if(!s->budget--) { s->failed_pc=0x0c0739b0u; return 0; }
r[3]=read(ram,0x0c073a98u,4);
goto P_0c0739b2;
P_0c0739b2: /* original 65d3, guest PC 0x0c0739b2 */
if(!s->budget--) { s->failed_pc=0x0c0739b2u; return 0; }
r[5]=r[13];
goto P_0c0739b4;
P_0c0739b4: /* original 430b, guest PC 0x0c0739b4 */
if(!s->budget--) { s->failed_pc=0x0c0739b4u; return 0; }
target=r[3];
r[16]=0x8c0739b8u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0739b8u) { target=s->pc; goto dispatch; }
goto P_0c0739b8;
P_0c0739b6: /* original 64e3, guest PC 0x0c0739b6 */
if(!s->budget--) { s->failed_pc=0x0c0739b6u; return 0; }
r[4]=r[14];
goto P_0c0739b8;
P_0c0739b8: /* original 65d3, guest PC 0x0c0739b8 */
if(!s->budget--) { s->failed_pc=0x0c0739b8u; return 0; }
r[5]=r[13];
goto P_0c0739ba;
P_0c0739ba: /* original b721, guest PC 0x0c0739ba */
if(!s->budget--) { s->failed_pc=0x0c0739bau; return 0; }
target=0x0c074800u; r[16]=0x8c0739beu;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0739beu) { target=s->pc; goto dispatch; }
goto P_0c0739be;
P_0c0739bc: /* original 64e3, guest PC 0x0c0739bc */
if(!s->budget--) { s->failed_pc=0x0c0739bcu; return 0; }
r[4]=r[14];
goto P_0c0739be;
P_0c0739be: /* original d337, guest PC 0x0c0739be */
if(!s->budget--) { s->failed_pc=0x0c0739beu; return 0; }
r[3]=read(ram,0x0c073a9cu,4);
goto P_0c0739c0;
P_0c0739c0: /* original 65d3, guest PC 0x0c0739c0 */
if(!s->budget--) { s->failed_pc=0x0c0739c0u; return 0; }
r[5]=r[13];
goto P_0c0739c2;
P_0c0739c2: /* original 430b, guest PC 0x0c0739c2 */
if(!s->budget--) { s->failed_pc=0x0c0739c2u; return 0; }
target=r[3];
r[16]=0x8c0739c6u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0739c6u) { target=s->pc; goto dispatch; }
goto P_0c0739c6;
P_0c0739c4: /* original 64e3, guest PC 0x0c0739c4 */
if(!s->budget--) { s->failed_pc=0x0c0739c4u; return 0; }
r[4]=r[14];
goto P_0c0739c6;
P_0c0739c6: /* original 905b, guest PC 0x0c0739c6 */
if(!s->budget--) { s->failed_pc=0x0c0739c6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c073a80u,2);
goto P_0c0739c8;
P_0c0739c8: /* original 65d3, guest PC 0x0c0739c8 */
if(!s->budget--) { s->failed_pc=0x0c0739c8u; return 0; }
r[5]=r[13];
goto P_0c0739ca;
P_0c0739ca: /* original fef7, guest PC 0x0c0739ca */
if(!s->budget--) { s->failed_pc=0x0c0739cau; return 0; }
vf3_matrix_store(s,ram,15,r[14]+r[0]);
goto P_0c0739cc;
P_0c0739cc: /* original 7004, guest PC 0x0c0739cc */
if(!s->budget--) { s->failed_pc=0x0c0739ccu; return 0; }
r[0]+=0x00000004u;
goto P_0c0739ce;
P_0c0739ce: /* original fef7, guest PC 0x0c0739ce */
if(!s->budget--) { s->failed_pc=0x0c0739ceu; return 0; }
vf3_matrix_store(s,ram,15,r[14]+r[0]);
goto P_0c0739d0;
P_0c0739d0: /* original 7004, guest PC 0x0c0739d0 */
if(!s->budget--) { s->failed_pc=0x0c0739d0u; return 0; }
r[0]+=0x00000004u;
goto P_0c0739d2;
P_0c0739d2: /* original fef7, guest PC 0x0c0739d2 */
if(!s->budget--) { s->failed_pc=0x0c0739d2u; return 0; }
vf3_matrix_store(s,ram,15,r[14]+r[0]);
goto P_0c0739d4;
P_0c0739d4: /* original 70f8, guest PC 0x0c0739d4 */
if(!s->budget--) { s->failed_pc=0x0c0739d4u; return 0; }
r[0]+=0xfffffff8u;
goto P_0c0739d6;
P_0c0739d6: /* original fdf7, guest PC 0x0c0739d6 */
if(!s->budget--) { s->failed_pc=0x0c0739d6u; return 0; }
vf3_matrix_store(s,ram,15,r[13]+r[0]);
goto P_0c0739d8;
P_0c0739d8: /* original 7004, guest PC 0x0c0739d8 */
if(!s->budget--) { s->failed_pc=0x0c0739d8u; return 0; }
r[0]+=0x00000004u;
goto P_0c0739da;
P_0c0739da: /* original fdf7, guest PC 0x0c0739da */
if(!s->budget--) { s->failed_pc=0x0c0739dau; return 0; }
vf3_matrix_store(s,ram,15,r[13]+r[0]);
goto P_0c0739dc;
P_0c0739dc: /* original 7004, guest PC 0x0c0739dc */
if(!s->budget--) { s->failed_pc=0x0c0739dcu; return 0; }
r[0]+=0x00000004u;
goto P_0c0739de;
P_0c0739de: /* original fdf7, guest PC 0x0c0739de */
if(!s->budget--) { s->failed_pc=0x0c0739deu; return 0; }
vf3_matrix_store(s,ram,15,r[13]+r[0]);
goto P_0c0739e0;
P_0c0739e0: /* original d32f, guest PC 0x0c0739e0 */
if(!s->budget--) { s->failed_pc=0x0c0739e0u; return 0; }
r[3]=read(ram,0x0c073aa0u,4);
goto P_0c0739e2;
P_0c0739e2: /* original 430b, guest PC 0x0c0739e2 */
if(!s->budget--) { s->failed_pc=0x0c0739e2u; return 0; }
target=r[3];
r[16]=0x8c0739e6u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0739e6u) { target=s->pc; goto dispatch; }
goto P_0c0739e6;
P_0c0739e4: /* original 64e3, guest PC 0x0c0739e4 */
if(!s->budget--) { s->failed_pc=0x0c0739e4u; return 0; }
r[4]=r[14];
goto P_0c0739e6;
P_0c0739e6: /* original 65d3, guest PC 0x0c0739e6 */
if(!s->budget--) { s->failed_pc=0x0c0739e6u; return 0; }
r[5]=r[13];
goto P_0c0739e8;
P_0c0739e8: /* original b76a, guest PC 0x0c0739e8 */
if(!s->budget--) { s->failed_pc=0x0c0739e8u; return 0; }
target=0x0c0748c0u; r[16]=0x8c0739ecu;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0739ecu) { target=s->pc; goto dispatch; }
goto P_0c0739ec;
P_0c0739ea: /* original 64e3, guest PC 0x0c0739ea */
if(!s->budget--) { s->failed_pc=0x0c0739eau; return 0; }
r[4]=r[14];
goto P_0c0739ec;
P_0c0739ec: /* original 9049, guest PC 0x0c0739ec */
if(!s->budget--) { s->failed_pc=0x0c0739ecu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c073a82u,2);
goto P_0c0739ee;
P_0c0739ee: /* original e201, guest PC 0x0c0739ee */
if(!s->budget--) { s->failed_pc=0x0c0739eeu; return 0; }
r[2]=0x00000001u;
goto P_0c0739f0;
P_0c0739f0: /* original fef7, guest PC 0x0c0739f0 */
if(!s->budget--) { s->failed_pc=0x0c0739f0u; return 0; }
vf3_matrix_store(s,ram,15,r[14]+r[0]);
goto P_0c0739f2;
P_0c0739f2: /* original fdf7, guest PC 0x0c0739f2 */
if(!s->budget--) { s->failed_pc=0x0c0739f2u; return 0; }
vf3_matrix_store(s,ram,15,r[13]+r[0]);
goto P_0c0739f4;
P_0c0739f4: /* original 63d2, guest PC 0x0c0739f4 */
if(!s->budget--) { s->failed_pc=0x0c0739f4u; return 0; }
tmp=read(ram,r[13],4);
r[3]=tmp;
goto P_0c0739f6;
P_0c0739f6: /* original 64e2, guest PC 0x0c0739f6 */
if(!s->budget--) { s->failed_pc=0x0c0739f6u; return 0; }
tmp=read(ram,r[14],4);
r[4]=tmp;
goto P_0c0739f8;
P_0c0739f8: /* original 2439, guest PC 0x0c0739f8 */
if(!s->budget--) { s->failed_pc=0x0c0739f8u; return 0; }
r[4]&=r[3];
goto P_0c0739fa;
P_0c0739fa: /* original 2428, guest PC 0x0c0739fa */
if(!s->budget--) { s->failed_pc=0x0c0739fau; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[2])==0)!=0);
goto P_0c0739fc;
P_0c0739fc: /* original 8921, guest PC 0x0c0739fc */
if(!s->budget--) { s->failed_pc=0x0c0739fcu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c073a42; }
goto P_0c0739fe;
P_0c0739fe: /* original c729, guest PC 0x0c0739fe */
if(!s->budget--) { s->failed_pc=0x0c0739feu; return 0; }
r[0]=0x0c073aa4u;
goto P_0c073a00;
P_0c073a00: /* original f308, guest PC 0x0c073a00 */
if(!s->budget--) { s->failed_pc=0x0c073a00u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c073a02;
P_0c073a02: /* original e05c, guest PC 0x0c073a02 */
if(!s->budget--) { s->failed_pc=0x0c073a02u; return 0; }
r[0]=0x0000005cu;
goto P_0c073a04;
P_0c073a04: /* original f2e6, guest PC 0x0c073a04 */
if(!s->budget--) { s->failed_pc=0x0c073a04u; return 0; }
vf3_matrix_load(s,ram,2,r[14]+r[0]);
goto P_0c073a06;
P_0c073a06: /* original f235, guest PC 0x0c073a06 */
if(!s->budget--) { s->failed_pc=0x0c073a06u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[2])>as_float(fr[3]))!=0);
goto P_0c073a08;
P_0c073a08: /* original 8b08, guest PC 0x0c073a08 */
if(!s->budget--) { s->failed_pc=0x0c073a08u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c073a1c; }
goto P_0c073a0a;
P_0c073a0a: /* original 65d3, guest PC 0x0c073a0a */
if(!s->budget--) { s->failed_pc=0x0c073a0au; return 0; }
r[5]=r[13];
goto P_0c073a0c;
P_0c073a0c: /* original b612, guest PC 0x0c073a0c */
if(!s->budget--) { s->failed_pc=0x0c073a0cu; return 0; }
target=0x0c074634u; r[16]=0x8c073a10u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c073a10u) { target=s->pc; goto dispatch; }
goto P_0c073a10;
P_0c073a0e: /* original 64e3, guest PC 0x0c073a0e */
if(!s->budget--) { s->failed_pc=0x0c073a0eu; return 0; }
r[4]=r[14];
goto P_0c073a10;
P_0c073a10: /* original 65e3, guest PC 0x0c073a10 */
if(!s->budget--) { s->failed_pc=0x0c073a10u; return 0; }
r[5]=r[14];
goto P_0c073a12;
P_0c073a12: /* original 66d3, guest PC 0x0c073a12 */
if(!s->budget--) { s->failed_pc=0x0c073a12u; return 0; }
r[6]=r[13];
goto P_0c073a14;
P_0c073a14: /* original b5bd, guest PC 0x0c073a14 */
if(!s->budget--) { s->failed_pc=0x0c073a14u; return 0; }
target=0x0c074592u; r[16]=0x8c073a18u;
r[4]=r[12];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c073a18u) { target=s->pc; goto dispatch; }
goto P_0c073a18;
P_0c073a16: /* original 64c3, guest PC 0x0c073a16 */
if(!s->budget--) { s->failed_pc=0x0c073a16u; return 0; }
r[4]=r[12];
goto P_0c073a18;
P_0c073a18: /* original a013, guest PC 0x0c073a18 */
if(!s->budget--) { s->failed_pc=0x0c073a18u; return 0; }
goto P_0c073a42;
P_0c073a1a: /* original 0009, guest PC 0x0c073a1a */
if(!s->budget--) { s->failed_pc=0x0c073a1au; return 0; }
goto P_0c073a1c;
P_0c073a1c: /* original 65e3, guest PC 0x0c073a1c */
if(!s->budget--) { s->failed_pc=0x0c073a1cu; return 0; }
r[5]=r[14];
goto P_0c073a1e;
P_0c073a1e: /* original 66d3, guest PC 0x0c073a1e */
if(!s->budget--) { s->failed_pc=0x0c073a1eu; return 0; }
r[6]=r[13];
goto P_0c073a20;
P_0c073a20: /* original b044, guest PC 0x0c073a20 */
if(!s->budget--) { s->failed_pc=0x0c073a20u; return 0; }
target=0x0c073aacu; r[16]=0x8c073a24u;
r[4]=r[12];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c073a24u) { target=s->pc; goto dispatch; }
goto P_0c073a24;
P_0c073a22: /* original 64c3, guest PC 0x0c073a22 */
if(!s->budget--) { s->failed_pc=0x0c073a22u; return 0; }
r[4]=r[12];
goto P_0c073a24;
P_0c073a24: /* original 65e3, guest PC 0x0c073a24 */
if(!s->budget--) { s->failed_pc=0x0c073a24u; return 0; }
r[5]=r[14];
goto P_0c073a26;
P_0c073a26: /* original 66d3, guest PC 0x0c073a26 */
if(!s->budget--) { s->failed_pc=0x0c073a26u; return 0; }
r[6]=r[13];
goto P_0c073a28;
P_0c073a28: /* original b389, guest PC 0x0c073a28 */
if(!s->budget--) { s->failed_pc=0x0c073a28u; return 0; }
target=0x0c07413eu; r[16]=0x8c073a2cu;
r[4]=r[12];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c073a2cu) { target=s->pc; goto dispatch; }
goto P_0c073a2c;
P_0c073a2a: /* original 64c3, guest PC 0x0c073a2a */
if(!s->budget--) { s->failed_pc=0x0c073a2au; return 0; }
r[4]=r[12];
goto P_0c073a2c;
P_0c073a2c: /* original 65d3, guest PC 0x0c073a2c */
if(!s->budget--) { s->failed_pc=0x0c073a2cu; return 0; }
r[5]=r[13];
goto P_0c073a2e;
P_0c073a2e: /* original b747, guest PC 0x0c073a2e */
if(!s->budget--) { s->failed_pc=0x0c073a2eu; return 0; }
target=0x0c0748c0u; r[16]=0x8c073a32u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c073a32u) { target=s->pc; goto dispatch; }
goto P_0c073a32;
P_0c073a30: /* original 64e3, guest PC 0x0c073a30 */
if(!s->budget--) { s->failed_pc=0x0c073a30u; return 0; }
r[4]=r[14];
goto P_0c073a32;
P_0c073a32: /* original 9027, guest PC 0x0c073a32 */
if(!s->budget--) { s->failed_pc=0x0c073a32u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c073a84u,2);
goto P_0c073a34;
P_0c073a34: /* original fef7, guest PC 0x0c073a34 */
if(!s->budget--) { s->failed_pc=0x0c073a34u; return 0; }
vf3_matrix_store(s,ram,15,r[14]+r[0]);
goto P_0c073a36;
P_0c073a36: /* original 7008, guest PC 0x0c073a36 */
if(!s->budget--) { s->failed_pc=0x0c073a36u; return 0; }
r[0]+=0x00000008u;
goto P_0c073a38;
P_0c073a38: /* original fef7, guest PC 0x0c073a38 */
if(!s->budget--) { s->failed_pc=0x0c073a38u; return 0; }
vf3_matrix_store(s,ram,15,r[14]+r[0]);
goto P_0c073a3a;
P_0c073a3a: /* original 70f8, guest PC 0x0c073a3a */
if(!s->budget--) { s->failed_pc=0x0c073a3au; return 0; }
r[0]+=0xfffffff8u;
goto P_0c073a3c;
P_0c073a3c: /* original fdf7, guest PC 0x0c073a3c */
if(!s->budget--) { s->failed_pc=0x0c073a3cu; return 0; }
vf3_matrix_store(s,ram,15,r[13]+r[0]);
goto P_0c073a3e;
P_0c073a3e: /* original 7008, guest PC 0x0c073a3e */
if(!s->budget--) { s->failed_pc=0x0c073a3eu; return 0; }
r[0]+=0x00000008u;
goto P_0c073a40;
P_0c073a40: /* original fdf7, guest PC 0x0c073a40 */
if(!s->budget--) { s->failed_pc=0x0c073a40u; return 0; }
vf3_matrix_store(s,ram,15,r[13]+r[0]);
goto P_0c073a42;
P_0c073a42: /* original d312, guest PC 0x0c073a42 */
if(!s->budget--) { s->failed_pc=0x0c073a42u; return 0; }
r[3]=read(ram,0x0c073a8cu,4);
goto P_0c073a44;
P_0c073a44: /* original 6032, guest PC 0x0c073a44 */
if(!s->budget--) { s->failed_pc=0x0c073a44u; return 0; }
tmp=read(ram,r[3],4);
r[0]=tmp;
goto P_0c073a46;
P_0c073a46: /* original c802, guest PC 0x0c073a46 */
if(!s->budget--) { s->failed_pc=0x0c073a46u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&2u)==0)!=0);
goto P_0c073a48;
P_0c073a48: /* original 8904, guest PC 0x0c073a48 */
if(!s->budget--) { s->failed_pc=0x0c073a48u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c073a54; }
goto P_0c073a4a;
P_0c073a4a: /* original d111, guest PC 0x0c073a4a */
if(!s->budget--) { s->failed_pc=0x0c073a4au; return 0; }
r[1]=read(ram,0x0c073a90u,4);
goto P_0c073a4c;
P_0c073a4c: /* original 65e3, guest PC 0x0c073a4c */
if(!s->budget--) { s->failed_pc=0x0c073a4cu; return 0; }
r[5]=r[14];
goto P_0c073a4e;
P_0c073a4e: /* original 66d3, guest PC 0x0c073a4e */
if(!s->budget--) { s->failed_pc=0x0c073a4eu; return 0; }
r[6]=r[13];
goto P_0c073a50;
P_0c073a50: /* original 410b, guest PC 0x0c073a50 */
if(!s->budget--) { s->failed_pc=0x0c073a50u; return 0; }
target=r[1];
r[16]=0x8c073a54u;
r[4]=r[12];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c073a54u) { target=s->pc; goto dispatch; }
goto P_0c073a54;
P_0c073a52: /* original 64c3, guest PC 0x0c073a52 */
if(!s->budget--) { s->failed_pc=0x0c073a52u; return 0; }
r[4]=r[12];
goto P_0c073a54;
P_0c073a54: /* original 65d3, guest PC 0x0c073a54 */
if(!s->budget--) { s->failed_pc=0x0c073a54u; return 0; }
r[5]=r[13];
goto P_0c073a56;
P_0c073a56: /* original b654, guest PC 0x0c073a56 */
if(!s->budget--) { s->failed_pc=0x0c073a56u; return 0; }
target=0x0c074702u; r[16]=0x8c073a5au;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c073a5au) { target=s->pc; goto dispatch; }
goto P_0c073a5a;
P_0c073a58: /* original 64e3, guest PC 0x0c073a58 */
if(!s->budget--) { s->failed_pc=0x0c073a58u; return 0; }
r[4]=r[14];
goto P_0c073a5a;
P_0c073a5a: /* original 65e3, guest PC 0x0c073a5a */
if(!s->budget--) { s->failed_pc=0x0c073a5au; return 0; }
r[5]=r[14];
goto P_0c073a5c;
P_0c073a5c: /* original b651, guest PC 0x0c073a5c */
if(!s->budget--) { s->failed_pc=0x0c073a5cu; return 0; }
target=0x0c074702u; r[16]=0x8c073a60u;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c073a60u) { target=s->pc; goto dispatch; }
goto P_0c073a60;
P_0c073a5e: /* original 64d3, guest PC 0x0c073a5e */
if(!s->budget--) { s->failed_pc=0x0c073a5eu; return 0; }
r[4]=r[13];
goto P_0c073a60;
P_0c073a60: /* original 65d3, guest PC 0x0c073a60 */
if(!s->budget--) { s->failed_pc=0x0c073a60u; return 0; }
r[5]=r[13];
goto P_0c073a62;
P_0c073a62: /* original b6e4, guest PC 0x0c073a62 */
if(!s->budget--) { s->failed_pc=0x0c073a62u; return 0; }
target=0x0c07482eu; r[16]=0x8c073a66u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c073a66u) { target=s->pc; goto dispatch; }
goto P_0c073a66;
P_0c073a64: /* original 64e3, guest PC 0x0c073a64 */
if(!s->budget--) { s->failed_pc=0x0c073a64u; return 0; }
r[4]=r[14];
goto P_0c073a66;
P_0c073a66: /* original d210, guest PC 0x0c073a66 */
if(!s->budget--) { s->failed_pc=0x0c073a66u; return 0; }
r[2]=read(ram,0x0c073aa8u,4);
goto P_0c073a68;
P_0c073a68: /* original 420b, guest PC 0x0c073a68 */
if(!s->budget--) { s->failed_pc=0x0c073a68u; return 0; }
target=r[2];
r[16]=0x8c073a6cu;
r[4]=r[12];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c073a6cu) { target=s->pc; goto dispatch; }
goto P_0c073a6c;
P_0c073a6a: /* original 64c3, guest PC 0x0c073a6a */
if(!s->budget--) { s->failed_pc=0x0c073a6au; return 0; }
r[4]=r[12];
goto P_0c073a6c;
P_0c073a6c: /* original 900b, guest PC 0x0c073a6c */
if(!s->budget--) { s->failed_pc=0x0c073a6cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c073a86u,2);
goto P_0c073a6e;
P_0c073a6e: /* original 03ee, guest PC 0x0c073a6e */
if(!s->budget--) { s->failed_pc=0x0c073a6eu; return 0; }
r[3]=read(ram,r[14]+r[0],4);
goto P_0c073a70;
P_0c073a70: /* original 900a, guest PC 0x0c073a70 */
if(!s->budget--) { s->failed_pc=0x0c073a70u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c073a88u,2);
goto P_0c073a72;
P_0c073a72: /* original 0e36, guest PC 0x0c073a72 */
if(!s->budget--) { s->failed_pc=0x0c073a72u; return 0; }
write(ram,r[14]+r[0],r[3],4);
goto P_0c073a74;
P_0c073a74: /* original 4f26, guest PC 0x0c073a74 */
if(!s->budget--) { s->failed_pc=0x0c073a74u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c073a76;
P_0c073a76: /* original fff9, guest PC 0x0c073a76 */
if(!s->budget--) { s->failed_pc=0x0c073a76u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c073a78;
P_0c073a78: /* original 6cf6, guest PC 0x0c073a78 */
if(!s->budget--) { s->failed_pc=0x0c073a78u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c073a7a;
P_0c073a7a: /* original 6df6, guest PC 0x0c073a7a */
if(!s->budget--) { s->failed_pc=0x0c073a7au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c073a7c;
P_0c073a7c: /* original 000b, guest PC 0x0c073a7c */
if(!s->budget--) { s->failed_pc=0x0c073a7cu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c073a7e: /* original 6ef6, guest PC 0x0c073a7e */
if(!s->budget--) { s->failed_pc=0x0c073a7eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c073a80u,s,ram);
P_0c076b92: /* original 2fe6, guest PC 0x0c076b92 */
if(!s->budget--) { s->failed_pc=0x0c076b92u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c076b94;
P_0c076b94: /* original 2fd6, guest PC 0x0c076b94 */
if(!s->budget--) { s->failed_pc=0x0c076b94u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c076b96;
P_0c076b96: /* original 2fc6, guest PC 0x0c076b96 */
if(!s->budget--) { s->failed_pc=0x0c076b96u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c076b98;
P_0c076b98: /* original 2fb6, guest PC 0x0c076b98 */
if(!s->budget--) { s->failed_pc=0x0c076b98u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c076b9a;
P_0c076b9a: /* original 2fa6, guest PC 0x0c076b9a */
if(!s->budget--) { s->failed_pc=0x0c076b9au; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c076b9c;
P_0c076b9c: /* original 6a43, guest PC 0x0c076b9c */
if(!s->budget--) { s->failed_pc=0x0c076b9cu; return 0; }
r[10]=r[4];
goto P_0c076b9e;
P_0c076b9e: /* original de4c, guest PC 0x0c076b9e */
if(!s->budget--) { s->failed_pc=0x0c076b9eu; return 0; }
r[14]=read(ram,0x0c076cd0u,4);
goto P_0c076ba0;
P_0c076ba0: /* original d446, guest PC 0x0c076ba0 */
if(!s->budget--) { s->failed_pc=0x0c076ba0u; return 0; }
r[4]=read(ram,0x0c076cbcu,4);
goto P_0c076ba2;
P_0c076ba2: /* original 937e, guest PC 0x0c076ba2 */
if(!s->budget--) { s->failed_pc=0x0c076ba2u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c076ca2u,2);
goto P_0c076ba4;
P_0c076ba4: /* original 62e2, guest PC 0x0c076ba4 */
if(!s->budget--) { s->failed_pc=0x0c076ba4u; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c076ba6;
P_0c076ba6: /* original 4f22, guest PC 0x0c076ba6 */
if(!s->budget--) { s->failed_pc=0x0c076ba6u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c076ba8;
P_0c076ba8: /* original 5c44, guest PC 0x0c076ba8 */
if(!s->budget--) { s->failed_pc=0x0c076ba8u; return 0; }
r[12]=read(ram,r[4]+16,4);
goto P_0c076baa;
P_0c076baa: /* original 2238, guest PC 0x0c076baa */
if(!s->budget--) { s->failed_pc=0x0c076baau; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c076bac;
P_0c076bac: /* original 5d45, guest PC 0x0c076bac */
if(!s->budget--) { s->failed_pc=0x0c076bacu; return 0; }
r[13]=read(ram,r[4]+20,4);
goto P_0c076bae;
P_0c076bae: /* original 8f04, guest PC 0x0c076bae */
if(!s->budget--) { s->failed_pc=0x0c076baeu; return 0; }
cond=r[17]&1u;
r[11]=r[4];
if(!cond) { goto P_0c076bba; }
goto P_0c076bb2;
P_0c076bb0: /* original 6b43, guest PC 0x0c076bb0 */
if(!s->budget--) { s->failed_pc=0x0c076bb0u; return 0; }
r[11]=r[4];
goto P_0c076bb2;
P_0c076bb2: /* original 50ba, guest PC 0x0c076bb2 */
if(!s->budget--) { s->failed_pc=0x0c076bb2u; return 0; }
r[0]=read(ram,r[11]+40,4);
goto P_0c076bb4;
P_0c076bb4: /* original 6002, guest PC 0x0c076bb4 */
if(!s->budget--) { s->failed_pc=0x0c076bb4u; return 0; }
tmp=read(ram,r[0],4);
r[0]=tmp;
goto P_0c076bb6;
P_0c076bb6: /* original c802, guest PC 0x0c076bb6 */
if(!s->budget--) { s->failed_pc=0x0c076bb6u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&2u)==0)!=0);
goto P_0c076bb8;
P_0c076bb8: /* original 8904, guest PC 0x0c076bb8 */
if(!s->budget--) { s->failed_pc=0x0c076bb8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c076bc4; }
goto P_0c076bba;
P_0c076bba: /* original 9073, guest PC 0x0c076bba */
if(!s->budget--) { s->failed_pc=0x0c076bbau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c076ca4u,2);
goto P_0c076bbc;
P_0c076bbc: /* original 03ee, guest PC 0x0c076bbc */
if(!s->budget--) { s->failed_pc=0x0c076bbcu; return 0; }
r[3]=read(ram,r[14]+r[0],4);
goto P_0c076bbe;
P_0c076bbe: /* original 9072, guest PC 0x0c076bbe */
if(!s->budget--) { s->failed_pc=0x0c076bbeu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c076ca6u,2);
goto P_0c076bc0;
P_0c076bc0: /* original 4319, guest PC 0x0c076bc0 */
if(!s->budget--) { s->failed_pc=0x0c076bc0u; return 0; }
r[3]>>=8;
goto P_0c076bc2;
P_0c076bc2: /* original 0c34, guest PC 0x0c076bc2 */
if(!s->budget--) { s->failed_pc=0x0c076bc2u; return 0; }
write(ram,r[12]+r[0],r[3],1);
goto P_0c076bc4;
P_0c076bc4: /* original 65c3, guest PC 0x0c076bc4 */
if(!s->budget--) { s->failed_pc=0x0c076bc4u; return 0; }
r[5]=r[12];
goto P_0c076bc6;
P_0c076bc6: /* original 66d3, guest PC 0x0c076bc6 */
if(!s->budget--) { s->failed_pc=0x0c076bc6u; return 0; }
r[6]=r[13];
goto P_0c076bc8;
P_0c076bc8: /* original b017, guest PC 0x0c076bc8 */
if(!s->budget--) { s->failed_pc=0x0c076bc8u; return 0; }
target=0x0c076bfau; r[16]=0x8c076bccu;
r[4]=r[10];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c076bccu) { target=s->pc; goto dispatch; }
goto P_0c076bcc;
P_0c076bca: /* original 64a3, guest PC 0x0c076bca */
if(!s->budget--) { s->failed_pc=0x0c076bcau; return 0; }
r[4]=r[10];
goto P_0c076bcc;
P_0c076bcc: /* original 62e2, guest PC 0x0c076bcc */
if(!s->budget--) { s->failed_pc=0x0c076bccu; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c076bce;
P_0c076bce: /* original 9368, guest PC 0x0c076bce */
if(!s->budget--) { s->failed_pc=0x0c076bceu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c076ca2u,2);
goto P_0c076bd0;
P_0c076bd0: /* original 2238, guest PC 0x0c076bd0 */
if(!s->budget--) { s->failed_pc=0x0c076bd0u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c076bd2;
P_0c076bd2: /* original 8f04, guest PC 0x0c076bd2 */
if(!s->budget--) { s->failed_pc=0x0c076bd2u; return 0; }
cond=r[17]&1u;
r[6]=r[12];
if(!cond) { goto P_0c076bde; }
goto P_0c076bd6;
P_0c076bd4: /* original 66c3, guest PC 0x0c076bd4 */
if(!s->budget--) { s->failed_pc=0x0c076bd4u; return 0; }
r[6]=r[12];
goto P_0c076bd6;
P_0c076bd6: /* original 50bb, guest PC 0x0c076bd6 */
if(!s->budget--) { s->failed_pc=0x0c076bd6u; return 0; }
r[0]=read(ram,r[11]+44,4);
goto P_0c076bd8;
P_0c076bd8: /* original 6002, guest PC 0x0c076bd8 */
if(!s->budget--) { s->failed_pc=0x0c076bd8u; return 0; }
tmp=read(ram,r[0],4);
r[0]=tmp;
goto P_0c076bda;
P_0c076bda: /* original c802, guest PC 0x0c076bda */
if(!s->budget--) { s->failed_pc=0x0c076bdau; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&2u)==0)!=0);
goto P_0c076bdc;
P_0c076bdc: /* original 8904, guest PC 0x0c076bdc */
if(!s->budget--) { s->failed_pc=0x0c076bdcu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c076be8; }
goto P_0c076bde;
P_0c076bde: /* original 9061, guest PC 0x0c076bde */
if(!s->budget--) { s->failed_pc=0x0c076bdeu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c076ca4u,2);
goto P_0c076be0;
P_0c076be0: /* original 03ee, guest PC 0x0c076be0 */
if(!s->budget--) { s->failed_pc=0x0c076be0u; return 0; }
r[3]=read(ram,r[14]+r[0],4);
goto P_0c076be2;
P_0c076be2: /* original 9060, guest PC 0x0c076be2 */
if(!s->budget--) { s->failed_pc=0x0c076be2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c076ca6u,2);
goto P_0c076be4;
P_0c076be4: /* original 4329, guest PC 0x0c076be4 */
if(!s->budget--) { s->failed_pc=0x0c076be4u; return 0; }
r[3]>>=16;
goto P_0c076be6;
P_0c076be6: /* original 0d34, guest PC 0x0c076be6 */
if(!s->budget--) { s->failed_pc=0x0c076be6u; return 0; }
write(ram,r[13]+r[0],r[3],1);
goto P_0c076be8;
P_0c076be8: /* original 4f26, guest PC 0x0c076be8 */
if(!s->budget--) { s->failed_pc=0x0c076be8u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c076bea;
P_0c076bea: /* original 64a3, guest PC 0x0c076bea */
if(!s->budget--) { s->failed_pc=0x0c076beau; return 0; }
r[4]=r[10];
goto P_0c076bec;
P_0c076bec: /* original 65d3, guest PC 0x0c076bec */
if(!s->budget--) { s->failed_pc=0x0c076becu; return 0; }
r[5]=r[13];
goto P_0c076bee;
P_0c076bee: /* original 6af6, guest PC 0x0c076bee */
if(!s->budget--) { s->failed_pc=0x0c076beeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c076bf0;
P_0c076bf0: /* original 6bf6, guest PC 0x0c076bf0 */
if(!s->budget--) { s->failed_pc=0x0c076bf0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c076bf2;
P_0c076bf2: /* original 6cf6, guest PC 0x0c076bf2 */
if(!s->budget--) { s->failed_pc=0x0c076bf2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c076bf4;
P_0c076bf4: /* original 6df6, guest PC 0x0c076bf4 */
if(!s->budget--) { s->failed_pc=0x0c076bf4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c076bf6;
P_0c076bf6: /* original a000, guest PC 0x0c076bf6 */
if(!s->budget--) { s->failed_pc=0x0c076bf6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c076bfa;
P_0c076bf8: /* original 6ef6, guest PC 0x0c076bf8 */
if(!s->budget--) { s->failed_pc=0x0c076bf8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c076bfa;
P_0c076bfa: /* original 2fe6, guest PC 0x0c076bfa */
if(!s->budget--) { s->failed_pc=0x0c076bfau; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c076bfc;
P_0c076bfc: /* original 2fd6, guest PC 0x0c076bfc */
if(!s->budget--) { s->failed_pc=0x0c076bfcu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c076bfe;
P_0c076bfe: /* original 2fc6, guest PC 0x0c076bfe */
if(!s->budget--) { s->failed_pc=0x0c076bfeu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c076c00;
P_0c076c00: /* original 4f22, guest PC 0x0c076c00 */
if(!s->budget--) { s->failed_pc=0x0c076c00u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c076c02;
P_0c076c02: /* original 9051, guest PC 0x0c076c02 */
if(!s->budget--) { s->failed_pc=0x0c076c02u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c076ca8u,2);
goto P_0c076c04;
P_0c076c04: /* original 9351, guest PC 0x0c076c04 */
if(!s->budget--) { s->failed_pc=0x0c076c04u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c076caau,2);
goto P_0c076c06;
P_0c076c06: /* original 3f0c, guest PC 0x0c076c06 */
if(!s->budget--) { s->failed_pc=0x0c076c06u; return 0; }
r[15]+=r[0];
goto P_0c076c08;
P_0c076c08: /* original 33fc, guest PC 0x0c076c08 */
if(!s->budget--) { s->failed_pc=0x0c076c08u; return 0; }
r[3]+=r[15];
goto P_0c076c0a;
P_0c076c0a: /* original 2342, guest PC 0x0c076c0a */
if(!s->budget--) { s->failed_pc=0x0c076c0au; return 0; }
write(ram,r[3],r[4],4);
goto P_0c076c0c;
P_0c076c0c: /* original 924e, guest PC 0x0c076c0c */
if(!s->budget--) { s->failed_pc=0x0c076c0cu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c076cacu,2);
goto P_0c076c0e;
P_0c076c0e: /* original 32fc, guest PC 0x0c076c0e */
if(!s->budget--) { s->failed_pc=0x0c076c0eu; return 0; }
r[2]+=r[15];
goto P_0c076c10;
P_0c076c10: /* original 2252, guest PC 0x0c076c10 */
if(!s->budget--) { s->failed_pc=0x0c076c10u; return 0; }
write(ram,r[2],r[5],4);
goto P_0c076c12;
P_0c076c12: /* original 934c, guest PC 0x0c076c12 */
if(!s->budget--) { s->failed_pc=0x0c076c12u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c076caeu,2);
goto P_0c076c14;
P_0c076c14: /* original 33fc, guest PC 0x0c076c14 */
if(!s->budget--) { s->failed_pc=0x0c076c14u; return 0; }
r[3]+=r[15];
goto P_0c076c16;
P_0c076c16: /* original 2362, guest PC 0x0c076c16 */
if(!s->budget--) { s->failed_pc=0x0c076c16u; return 0; }
write(ram,r[3],r[6],4);
goto P_0c076c18;
P_0c076c18: /* original 904a, guest PC 0x0c076c18 */
if(!s->budget--) { s->failed_pc=0x0c076c18u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c076cb0u,2);
goto P_0c076c1a;
P_0c076c1a: /* original d22d, guest PC 0x0c076c1a */
if(!s->budget--) { s->failed_pc=0x0c076c1au; return 0; }
r[2]=read(ram,0x0c076cd0u,4);
goto P_0c076c1c;
P_0c076c1c: /* original 0f26, guest PC 0x0c076c1c */
if(!s->budget--) { s->failed_pc=0x0c076c1cu; return 0; }
write(ram,r[15]+r[0],r[2],4);
goto P_0c076c1e;
P_0c076c1e: /* original 9045, guest PC 0x0c076c1e */
if(!s->budget--) { s->failed_pc=0x0c076c1eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c076cacu,2);
goto P_0c076c20;
P_0c076c20: /* original 0efe, guest PC 0x0c076c20 */
if(!s->budget--) { s->failed_pc=0x0c076c20u; return 0; }
r[14]=read(ram,r[15]+r[0],4);
goto P_0c076c22;
P_0c076c22: /* original 9044, guest PC 0x0c076c22 */
if(!s->budget--) { s->failed_pc=0x0c076c22u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c076caeu,2);
goto P_0c076c24;
P_0c076c24: /* original 0dfe, guest PC 0x0c076c24 */
if(!s->budget--) { s->failed_pc=0x0c076c24u; return 0; }
r[13]=read(ram,r[15]+r[0],4);
goto P_0c076c26;
P_0c076c26: /* original 9040, guest PC 0x0c076c26 */
if(!s->budget--) { s->failed_pc=0x0c076c26u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c076caau,2);
goto P_0c076c28;
P_0c076c28: /* original 0cfe, guest PC 0x0c076c28 */
if(!s->budget--) { s->failed_pc=0x0c076c28u; return 0; }
r[12]=read(ram,r[15]+r[0],4);
goto P_0c076c2a;
P_0c076c2a: /* original 9039, guest PC 0x0c076c2a */
if(!s->budget--) { s->failed_pc=0x0c076c2au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c076ca0u,2);
goto P_0c076c2c;
P_0c076c2c: /* original 03ee, guest PC 0x0c076c2c */
if(!s->budget--) { s->failed_pc=0x0c076c2cu; return 0; }
r[3]=read(ram,r[14]+r[0],4);
goto P_0c076c2e;
P_0c076c2e: /* original 9040, guest PC 0x0c076c2e */
if(!s->budget--) { s->failed_pc=0x0c076c2eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c076cb2u,2);
goto P_0c076c30;
P_0c076c30: /* original 0f36, guest PC 0x0c076c30 */
if(!s->budget--) { s->failed_pc=0x0c076c30u; return 0; }
write(ram,r[15]+r[0],r[3],4);
goto P_0c076c32;
P_0c076c32: /* original 903f, guest PC 0x0c076c32 */
if(!s->budget--) { s->failed_pc=0x0c076c32u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c076cb4u,2);
goto P_0c076c34;
P_0c076c34: /* original 62e2, guest PC 0x0c076c34 */
if(!s->budget--) { s->failed_pc=0x0c076c34u; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c076c36;
P_0c076c36: /* original 0f26, guest PC 0x0c076c36 */
if(!s->budget--) { s->failed_pc=0x0c076c36u; return 0; }
write(ram,r[15]+r[0],r[2],4);
goto P_0c076c38;
P_0c076c38: /* original e048, guest PC 0x0c076c38 */
if(!s->budget--) { s->failed_pc=0x0c076c38u; return 0; }
r[0]=0x00000048u;
goto P_0c076c3a;
P_0c076c3a: /* original 03ee, guest PC 0x0c076c3a */
if(!s->budget--) { s->failed_pc=0x0c076c3au; return 0; }
r[3]=read(ram,r[14]+r[0],4);
goto P_0c076c3c;
P_0c076c3c: /* original 903b, guest PC 0x0c076c3c */
if(!s->budget--) { s->failed_pc=0x0c076c3cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c076cb6u,2);
goto P_0c076c3e;
P_0c076c3e: /* original 0f36, guest PC 0x0c076c3e */
if(!s->budget--) { s->failed_pc=0x0c076c3eu; return 0; }
write(ram,r[15]+r[0],r[3],4);
goto P_0c076c40;
P_0c076c40: /* original e061, guest PC 0x0c076c40 */
if(!s->budget--) { s->failed_pc=0x0c076c40u; return 0; }
r[0]=0x00000061u;
goto P_0c076c42;
P_0c076c42: /* original 02ec, guest PC 0x0c076c42 */
if(!s->budget--) { s->failed_pc=0x0c076c42u; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c076c44;
P_0c076c44: /* original e07c, guest PC 0x0c076c44 */
if(!s->budget--) { s->failed_pc=0x0c076c44u; return 0; }
r[0]=0x0000007cu;
goto P_0c076c46;
P_0c076c46: /* original e300, guest PC 0x0c076c46 */
if(!s->budget--) { s->failed_pc=0x0c076c46u; return 0; }
r[3]=0x00000000u;
goto P_0c076c48;
P_0c076c48: /* original 622c, guest PC 0x0c076c48 */
if(!s->budget--) { s->failed_pc=0x0c076c48u; return 0; }
r[2]=r[2]&255u;
goto P_0c076c4a;
P_0c076c4a: /* original 6133, guest PC 0x0c076c4a */
if(!s->budget--) { s->failed_pc=0x0c076c4au; return 0; }
r[1]=r[3];
goto P_0c076c4c;
P_0c076c4c: /* original 0f26, guest PC 0x0c076c4c */
if(!s->budget--) { s->failed_pc=0x0c076c4cu; return 0; }
write(ram,r[15]+r[0],r[2],4);
goto P_0c076c4e;
P_0c076c4e: /* original e078, guest PC 0x0c076c4e */
if(!s->budget--) { s->failed_pc=0x0c076c4eu; return 0; }
r[0]=0x00000078u;
goto P_0c076c50;
P_0c076c50: /* original 0f36, guest PC 0x0c076c50 */
if(!s->budget--) { s->failed_pc=0x0c076c50u; return 0; }
write(ram,r[15]+r[0],r[3],4);
goto P_0c076c52;
P_0c076c52: /* original 1f1e, guest PC 0x0c076c52 */
if(!s->budget--) { s->failed_pc=0x0c076c52u; return 0; }
write(ram,r[15]+56,r[1],4);
goto P_0c076c54;
P_0c076c54: /* original 9027, guest PC 0x0c076c54 */
if(!s->budget--) { s->failed_pc=0x0c076c54u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c076ca6u,2);
goto P_0c076c56;
P_0c076c56: /* original 03ec, guest PC 0x0c076c56 */
if(!s->budget--) { s->failed_pc=0x0c076c56u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c076c58;
P_0c076c58: /* original 633c, guest PC 0x0c076c58 */
if(!s->budget--) { s->failed_pc=0x0c076c58u; return 0; }
r[3]=r[3]&255u;
goto P_0c076c5a;
P_0c076c5a: /* original 1f31, guest PC 0x0c076c5a */
if(!s->budget--) { s->failed_pc=0x0c076c5au; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c076c5c;
P_0c076c5c: /* original 9029, guest PC 0x0c076c5c */
if(!s->budget--) { s->failed_pc=0x0c076c5cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c076cb2u,2);
goto P_0c076c5e;
P_0c076c5e: /* original d21a, guest PC 0x0c076c5e */
if(!s->budget--) { s->failed_pc=0x0c076c5eu; return 0; }
r[2]=read(ram,0x0c076cc8u,4);
goto P_0c076c60;
P_0c076c60: /* original 01fe, guest PC 0x0c076c60 */
if(!s->budget--) { s->failed_pc=0x0c076c60u; return 0; }
r[1]=read(ram,r[15]+r[0],4);
goto P_0c076c62;
P_0c076c62: /* original 2128, guest PC 0x0c076c62 */
if(!s->budget--) { s->failed_pc=0x0c076c62u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[2])==0)!=0);
goto P_0c076c64;
P_0c076c64: /* original 8938, guest PC 0x0c076c64 */
if(!s->budget--) { s->failed_pc=0x0c076c64u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c076cd8; }
goto P_0c076c66;
P_0c076c66: /* original 9024, guest PC 0x0c076c66 */
if(!s->budget--) { s->failed_pc=0x0c076c66u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c076cb2u,2);
goto P_0c076c68;
P_0c076c68: /* original e100, guest PC 0x0c076c68 */
if(!s->budget--) { s->failed_pc=0x0c076c68u; return 0; }
r[1]=0x00000000u;
goto P_0c076c6a;
P_0c076c6a: /* original 6313, guest PC 0x0c076c6a */
if(!s->budget--) { s->failed_pc=0x0c076c6au; return 0; }
r[3]=r[1];
goto P_0c076c6c;
P_0c076c6c: /* original 0f16, guest PC 0x0c076c6c */
if(!s->budget--) { s->failed_pc=0x0c076c6cu; return 0; }
write(ram,r[15]+r[0],r[1],4);
goto P_0c076c6e;
P_0c076c6e: /* original 9017, guest PC 0x0c076c6e */
if(!s->budget--) { s->failed_pc=0x0c076c6eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c076ca0u,2);
goto P_0c076c70;
P_0c076c70: /* original 0e16, guest PC 0x0c076c70 */
if(!s->budget--) { s->failed_pc=0x0c076c70u; return 0; }
write(ram,r[14]+r[0],r[1],4);
goto P_0c076c72;
P_0c076c72: /* original 7010, guest PC 0x0c076c72 */
if(!s->budget--) { s->failed_pc=0x0c076c72u; return 0; }
r[0]+=0x00000010u;
goto P_0c076c74;
P_0c076c74: /* original 0e36, guest PC 0x0c076c74 */
if(!s->budget--) { s->failed_pc=0x0c076c74u; return 0; }
write(ram,r[14]+r[0],r[3],4);
goto P_0c076c76;
P_0c076c76: /* original 70f8, guest PC 0x0c076c76 */
if(!s->budget--) { s->failed_pc=0x0c076c76u; return 0; }
r[0]+=0xfffffff8u;
goto P_0c076c78;
P_0c076c78: /* original 0e35, guest PC 0x0c076c78 */
if(!s->budget--) { s->failed_pc=0x0c076c78u; return 0; }
write(ram,r[14]+r[0],r[3],2);
goto P_0c076c7a;
P_0c076c7a: /* original 700c, guest PC 0x0c076c7a */
if(!s->budget--) { s->failed_pc=0x0c076c7au; return 0; }
r[0]+=0x0000000cu;
goto P_0c076c7c;
P_0c076c7c: /* original 0e36, guest PC 0x0c076c7c */
if(!s->budget--) { s->failed_pc=0x0c076c7cu; return 0; }
write(ram,r[14]+r[0],r[3],4);
goto P_0c076c7e;
P_0c076c7e: /* original 7014, guest PC 0x0c076c7e */
if(!s->budget--) { s->failed_pc=0x0c076c7eu; return 0; }
r[0]+=0x00000014u;
goto P_0c076c80;
P_0c076c80: /* original 0e34, guest PC 0x0c076c80 */
if(!s->budget--) { s->failed_pc=0x0c076c80u; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c076c82;
P_0c076c82: /* original 7001, guest PC 0x0c076c82 */
if(!s->budget--) { s->failed_pc=0x0c076c82u; return 0; }
r[0]+=0x00000001u;
goto P_0c076c84;
P_0c076c84: /* original 0e34, guest PC 0x0c076c84 */
if(!s->budget--) { s->failed_pc=0x0c076c84u; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c076c86;
P_0c076c86: /* original 9017, guest PC 0x0c076c86 */
if(!s->budget--) { s->failed_pc=0x0c076c86u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c076cb8u,2);
goto P_0c076c88;
P_0c076c88: /* original 53f1, guest PC 0x0c076c88 */
if(!s->budget--) { s->failed_pc=0x0c076c88u; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c076c8a;
P_0c076c8a: /* original 0e34, guest PC 0x0c076c8a */
if(!s->budget--) { s->failed_pc=0x0c076c8au; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c076c8c;
P_0c076c8c: /* original e300, guest PC 0x0c076c8c */
if(!s->budget--) { s->failed_pc=0x0c076c8cu; return 0; }
r[3]=0x00000000u;
goto P_0c076c8e;
P_0c076c8e: /* original 9014, guest PC 0x0c076c8e */
if(!s->budget--) { s->failed_pc=0x0c076c8eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c076cbau,2);
goto P_0c076c90;
P_0c076c90: /* original 51f1, guest PC 0x0c076c90 */
if(!s->budget--) { s->failed_pc=0x0c076c90u; return 0; }
r[1]=read(ram,r[15]+4,4);
goto P_0c076c92;
P_0c076c92: /* original 0e14, guest PC 0x0c076c92 */
if(!s->budget--) { s->failed_pc=0x0c076c92u; return 0; }
write(ram,r[14]+r[0],r[1],1);
goto P_0c076c94;
P_0c076c94: /* original 7081, guest PC 0x0c076c94 */
if(!s->budget--) { s->failed_pc=0x0c076c94u; return 0; }
r[0]+=0xffffff81u;
goto P_0c076c96;
P_0c076c96: /* original 6133, guest PC 0x0c076c96 */
if(!s->budget--) { s->failed_pc=0x0c076c96u; return 0; }
r[1]=r[3];
goto P_0c076c98;
P_0c076c98: /* original 0e34, guest PC 0x0c076c98 */
if(!s->budget--) { s->failed_pc=0x0c076c98u; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c076c9a;
P_0c076c9a: /* original d30e, guest PC 0x0c076c9a */
if(!s->budget--) { s->failed_pc=0x0c076c9au; return 0; }
r[3]=read(ram,0x0c076cd4u,4);
goto P_0c076c9c;
P_0c076c9c: /* original 432b, guest PC 0x0c076c9c */
if(!s->budget--) { s->failed_pc=0x0c076c9cu; return 0; }
target=r[3];
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
P_0c076c9e: /* original 0009, guest PC 0x0c076c9e */
if(!s->budget--) { s->failed_pc=0x0c076c9eu; return 0; }
return vf3_matrix_family(0x0c076ca0u,s,ram);
P_0c076cd8: /* original 9067, guest PC 0x0c076cd8 */
if(!s->budget--) { s->failed_pc=0x0c076cd8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c076daau,2);
goto P_0c076cda;
P_0c076cda: /* original d339, guest PC 0x0c076cda */
if(!s->budget--) { s->failed_pc=0x0c076cdau; return 0; }
r[3]=read(ram,0x0c076dc0u,4);
goto P_0c076cdc;
P_0c076cdc: /* original 02fe, guest PC 0x0c076cdc */
if(!s->budget--) { s->failed_pc=0x0c076cdcu; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c076cde;
P_0c076cde: /* original 2238, guest PC 0x0c076cde */
if(!s->budget--) { s->failed_pc=0x0c076cdeu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c076ce0;
P_0c076ce0: /* original 8904, guest PC 0x0c076ce0 */
if(!s->budget--) { s->failed_pc=0x0c076ce0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c076cec; }
goto P_0c076ce2;
P_0c076ce2: /* original 9062, guest PC 0x0c076ce2 */
if(!s->budget--) { s->failed_pc=0x0c076ce2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c076daau,2);
goto P_0c076ce4;
P_0c076ce4: /* original d237, guest PC 0x0c076ce4 */
if(!s->budget--) { s->failed_pc=0x0c076ce4u; return 0; }
r[2]=read(ram,0x0c076dc4u,4);
goto P_0c076ce6;
P_0c076ce6: /* original 01fe, guest PC 0x0c076ce6 */
if(!s->budget--) { s->failed_pc=0x0c076ce6u; return 0; }
r[1]=read(ram,r[15]+r[0],4);
goto P_0c076ce8;
P_0c076ce8: /* original a004, guest PC 0x0c076ce8 */
if(!s->budget--) { s->failed_pc=0x0c076ce8u; return 0; }
r[1]|=r[2];
goto P_0c076cf4;
P_0c076cea: /* original 212b, guest PC 0x0c076cea */
if(!s->budget--) { s->failed_pc=0x0c076ceau; return 0; }
r[1]|=r[2];
goto P_0c076cec;
P_0c076cec: /* original 905d, guest PC 0x0c076cec */
if(!s->budget--) { s->failed_pc=0x0c076cecu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c076daau,2);
goto P_0c076cee;
P_0c076cee: /* original d236, guest PC 0x0c076cee */
if(!s->budget--) { s->failed_pc=0x0c076ceeu; return 0; }
r[2]=read(ram,0x0c076dc8u,4);
goto P_0c076cf0;
P_0c076cf0: /* original 01fe, guest PC 0x0c076cf0 */
if(!s->budget--) { s->failed_pc=0x0c076cf0u; return 0; }
r[1]=read(ram,r[15]+r[0],4);
goto P_0c076cf2;
P_0c076cf2: /* original 2129, guest PC 0x0c076cf2 */
if(!s->budget--) { s->failed_pc=0x0c076cf2u; return 0; }
r[1]&=r[2];
goto P_0c076cf4;
P_0c076cf4: /* original d335, guest PC 0x0c076cf4 */
if(!s->budget--) { s->failed_pc=0x0c076cf4u; return 0; }
r[3]=read(ram,0x0c076dccu,4);
goto P_0c076cf6;
P_0c076cf6: /* original 6213, guest PC 0x0c076cf6 */
if(!s->budget--) { s->failed_pc=0x0c076cf6u; return 0; }
r[2]=r[1];
goto P_0c076cf8;
P_0c076cf8: /* original 9057, guest PC 0x0c076cf8 */
if(!s->budget--) { s->failed_pc=0x0c076cf8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c076daau,2);
goto P_0c076cfa;
P_0c076cfa: /* original 2239, guest PC 0x0c076cfa */
if(!s->budget--) { s->failed_pc=0x0c076cfau; return 0; }
r[2]&=r[3];
goto P_0c076cfc;
P_0c076cfc: /* original 0f26, guest PC 0x0c076cfc */
if(!s->budget--) { s->failed_pc=0x0c076cfcu; return 0; }
write(ram,r[15]+r[0],r[2],4);
goto P_0c076cfe;
P_0c076cfe: /* original 9055, guest PC 0x0c076cfe */
if(!s->budget--) { s->failed_pc=0x0c076cfeu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c076dacu,2);
goto P_0c076d00;
P_0c076d00: /* original 01ee, guest PC 0x0c076d00 */
if(!s->budget--) { s->failed_pc=0x0c076d00u; return 0; }
r[1]=read(ram,r[14]+r[0],4);
goto P_0c076d02;
P_0c076d02: /* original 2118, guest PC 0x0c076d02 */
if(!s->budget--) { s->failed_pc=0x0c076d02u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[1])==0)!=0);
goto P_0c076d04;
P_0c076d04: /* original 890a, guest PC 0x0c076d04 */
if(!s->budget--) { s->failed_pc=0x0c076d04u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c076d1c; }
goto P_0c076d06;
P_0c076d06: /* original 9052, guest PC 0x0c076d06 */
if(!s->budget--) { s->failed_pc=0x0c076d06u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c076daeu,2);
goto P_0c076d08;
P_0c076d08: /* original 01ed, guest PC 0x0c076d08 */
if(!s->budget--) { s->failed_pc=0x0c076d08u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c076d0a;
P_0c076d0a: /* original 2118, guest PC 0x0c076d0a */
if(!s->budget--) { s->failed_pc=0x0c076d0au; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[1])==0)!=0);
goto P_0c076d0c;
P_0c076d0c: /* original 8903, guest PC 0x0c076d0c */
if(!s->budget--) { s->failed_pc=0x0c076d0cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c076d16; }
goto P_0c076d0e;
P_0c076d0e: /* original 03ed, guest PC 0x0c076d0e */
if(!s->budget--) { s->failed_pc=0x0c076d0eu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c076d10;
P_0c076d10: /* original 73ff, guest PC 0x0c076d10 */
if(!s->budget--) { s->failed_pc=0x0c076d10u; return 0; }
r[3]+=0xffffffffu;
goto P_0c076d12;
P_0c076d12: /* original a003, guest PC 0x0c076d12 */
if(!s->budget--) { s->failed_pc=0x0c076d12u; return 0; }
write(ram,r[14]+r[0],r[3],2);
goto P_0c076d1c;
P_0c076d14: /* original 0e35, guest PC 0x0c076d14 */
if(!s->budget--) { s->failed_pc=0x0c076d14u; return 0; }
write(ram,r[14]+r[0],r[3],2);
goto P_0c076d16;
P_0c076d16: /* original 9049, guest PC 0x0c076d16 */
if(!s->budget--) { s->failed_pc=0x0c076d16u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c076dacu,2);
goto P_0c076d18;
P_0c076d18: /* original e100, guest PC 0x0c076d18 */
if(!s->budget--) { s->failed_pc=0x0c076d18u; return 0; }
r[1]=0x00000000u;
goto P_0c076d1a;
P_0c076d1a: /* original 0e16, guest PC 0x0c076d1a */
if(!s->budget--) { s->failed_pc=0x0c076d1au; return 0; }
write(ram,r[14]+r[0],r[1],4);
goto P_0c076d1c;
P_0c076d1c: /* original 9048, guest PC 0x0c076d1c */
if(!s->budget--) { s->failed_pc=0x0c076d1cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c076db0u,2);
goto P_0c076d1e;
P_0c076d1e: /* original d32c, guest PC 0x0c076d1e */
if(!s->budget--) { s->failed_pc=0x0c076d1eu; return 0; }
r[3]=read(ram,0x0c076dd0u,4);
goto P_0c076d20;
P_0c076d20: /* original 02fe, guest PC 0x0c076d20 */
if(!s->budget--) { s->failed_pc=0x0c076d20u; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c076d22;
P_0c076d22: /* original 2238, guest PC 0x0c076d22 */
if(!s->budget--) { s->failed_pc=0x0c076d22u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c076d24;
P_0c076d24: /* original 890c, guest PC 0x0c076d24 */
if(!s->budget--) { s->failed_pc=0x0c076d24u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c076d40; }
goto P_0c076d26;
P_0c076d26: /* original 9044, guest PC 0x0c076d26 */
if(!s->budget--) { s->failed_pc=0x0c076d26u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c076db2u,2);
goto P_0c076d28;
P_0c076d28: /* original e200, guest PC 0x0c076d28 */
if(!s->budget--) { s->failed_pc=0x0c076d28u; return 0; }
r[2]=0x00000000u;
goto P_0c076d2a;
P_0c076d2a: /* original 6123, guest PC 0x0c076d2a */
if(!s->budget--) { s->failed_pc=0x0c076d2au; return 0; }
r[1]=r[2];
goto P_0c076d2c;
P_0c076d2c: /* original 0e26, guest PC 0x0c076d2c */
if(!s->budget--) { s->failed_pc=0x0c076d2cu; return 0; }
write(ram,r[14]+r[0],r[2],4);
goto P_0c076d2e;
P_0c076d2e: /* original 70f8, guest PC 0x0c076d2e */
if(!s->budget--) { s->failed_pc=0x0c076d2eu; return 0; }
r[0]+=0xfffffff8u;
goto P_0c076d30;
P_0c076d30: /* original 0e15, guest PC 0x0c076d30 */
if(!s->budget--) { s->failed_pc=0x0c076d30u; return 0; }
write(ram,r[14]+r[0],r[1],2);
goto P_0c076d32;
P_0c076d32: /* original 903a, guest PC 0x0c076d32 */
if(!s->budget--) { s->failed_pc=0x0c076d32u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c076daau,2);
goto P_0c076d34;
P_0c076d34: /* original d222, guest PC 0x0c076d34 */
if(!s->budget--) { s->failed_pc=0x0c076d34u; return 0; }
r[2]=read(ram,0x0c076dc0u,4);
goto P_0c076d36;
P_0c076d36: /* original 01fe, guest PC 0x0c076d36 */
if(!s->budget--) { s->failed_pc=0x0c076d36u; return 0; }
r[1]=read(ram,r[15]+r[0],4);
goto P_0c076d38;
P_0c076d38: /* original 9037, guest PC 0x0c076d38 */
if(!s->budget--) { s->failed_pc=0x0c076d38u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c076daau,2);
goto P_0c076d3a;
P_0c076d3a: /* original 212b, guest PC 0x0c076d3a */
if(!s->budget--) { s->failed_pc=0x0c076d3au; return 0; }
r[1]|=r[2];
goto P_0c076d3c;
P_0c076d3c: /* original a092, guest PC 0x0c076d3c */
if(!s->budget--) { s->failed_pc=0x0c076d3cu; return 0; }
write(ram,r[15]+r[0],r[1],4);
goto P_0c076e64;
P_0c076d3e: /* original 0f16, guest PC 0x0c076d3e */
if(!s->budget--) { s->failed_pc=0x0c076d3eu; return 0; }
write(ram,r[15]+r[0],r[1],4);
goto P_0c076d40;
P_0c076d40: /* original 9037, guest PC 0x0c076d40 */
if(!s->budget--) { s->failed_pc=0x0c076d40u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c076db2u,2);
goto P_0c076d42;
P_0c076d42: /* original 03ee, guest PC 0x0c076d42 */
if(!s->budget--) { s->failed_pc=0x0c076d42u; return 0; }
r[3]=read(ram,r[14]+r[0],4);
goto P_0c076d44;
P_0c076d44: /* original e070, guest PC 0x0c076d44 */
if(!s->budget--) { s->failed_pc=0x0c076d44u; return 0; }
r[0]=0x00000070u;
goto P_0c076d46;
P_0c076d46: /* original 0f36, guest PC 0x0c076d46 */
if(!s->budget--) { s->failed_pc=0x0c076d46u; return 0; }
write(ram,r[15]+r[0],r[3],4);
goto P_0c076d48;
P_0c076d48: /* original 9034, guest PC 0x0c076d48 */
if(!s->budget--) { s->failed_pc=0x0c076d48u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c076db4u,2);
goto P_0c076d4a;
P_0c076d4a: /* original 02ed, guest PC 0x0c076d4a */
if(!s->budget--) { s->failed_pc=0x0c076d4au; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c076d4c;
P_0c076d4c: /* original 4215, guest PC 0x0c076d4c */
if(!s->budget--) { s->failed_pc=0x0c076d4cu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>0)!=0);
goto P_0c076d4e;
P_0c076d4e: /* original 8b04, guest PC 0x0c076d4e */
if(!s->budget--) { s->failed_pc=0x0c076d4eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c076d5a; }
goto P_0c076d50;
P_0c076d50: /* original 9031, guest PC 0x0c076d50 */
if(!s->budget--) { s->failed_pc=0x0c076d50u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c076db6u,2);
goto P_0c076d52;
P_0c076d52: /* original d320, guest PC 0x0c076d52 */
if(!s->budget--) { s->failed_pc=0x0c076d52u; return 0; }
r[3]=read(ram,0x0c076dd4u,4);
goto P_0c076d54;
P_0c076d54: /* original 02fe, guest PC 0x0c076d54 */
if(!s->budget--) { s->failed_pc=0x0c076d54u; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c076d56;
P_0c076d56: /* original 2238, guest PC 0x0c076d56 */
if(!s->budget--) { s->failed_pc=0x0c076d56u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c076d58;
P_0c076d58: /* original 8b42, guest PC 0x0c076d58 */
if(!s->budget--) { s->failed_pc=0x0c076d58u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c076de0; }
goto P_0c076d5a;
P_0c076d5a: /* original 902c, guest PC 0x0c076d5a */
if(!s->budget--) { s->failed_pc=0x0c076d5au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c076db6u,2);
goto P_0c076d5c;
P_0c076d5c: /* original d31e, guest PC 0x0c076d5c */
if(!s->budget--) { s->failed_pc=0x0c076d5cu; return 0; }
r[3]=read(ram,0x0c076dd8u,4);
goto P_0c076d5e;
P_0c076d5e: /* original 01fe, guest PC 0x0c076d5e */
if(!s->budget--) { s->failed_pc=0x0c076d5eu; return 0; }
r[1]=read(ram,r[15]+r[0],4);
goto P_0c076d60;
P_0c076d60: /* original 2138, guest PC 0x0c076d60 */
if(!s->budget--) { s->failed_pc=0x0c076d60u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[3])==0)!=0);
goto P_0c076d62;
P_0c076d62: /* original 8b01, guest PC 0x0c076d62 */
if(!s->budget--) { s->failed_pc=0x0c076d62u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c076d68; }
goto P_0c076d64;
P_0c076d64: /* original a076, guest PC 0x0c076d64 */
if(!s->budget--) { s->failed_pc=0x0c076d64u; return 0; }
goto P_0c076e54;
P_0c076d66: /* original 0009, guest PC 0x0c076d66 */
if(!s->budget--) { s->failed_pc=0x0c076d66u; return 0; }
goto P_0c076d68;
P_0c076d68: /* original 9025, guest PC 0x0c076d68 */
if(!s->budget--) { s->failed_pc=0x0c076d68u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c076db6u,2);
goto P_0c076d6a;
P_0c076d6a: /* original d31c, guest PC 0x0c076d6a */
if(!s->budget--) { s->failed_pc=0x0c076d6au; return 0; }
r[3]=read(ram,0x0c076ddcu,4);
goto P_0c076d6c;
P_0c076d6c: /* original 02fe, guest PC 0x0c076d6c */
if(!s->budget--) { s->failed_pc=0x0c076d6cu; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c076d6e;
P_0c076d6e: /* original 2238, guest PC 0x0c076d6e */
if(!s->budget--) { s->failed_pc=0x0c076d6eu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c076d70;
P_0c076d70: /* original 8b08, guest PC 0x0c076d70 */
if(!s->budget--) { s->failed_pc=0x0c076d70u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c076d84; }
goto P_0c076d72;
P_0c076d72: /* original 9020, guest PC 0x0c076d72 */
if(!s->budget--) { s->failed_pc=0x0c076d72u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c076db6u,2);
goto P_0c076d74;
P_0c076d74: /* original d313, guest PC 0x0c076d74 */
if(!s->budget--) { s->failed_pc=0x0c076d74u; return 0; }
r[3]=read(ram,0x0c076dc4u,4);
goto P_0c076d76;
P_0c076d76: /* original 01fe, guest PC 0x0c076d76 */
if(!s->budget--) { s->failed_pc=0x0c076d76u; return 0; }
r[1]=read(ram,r[15]+r[0],4);
goto P_0c076d78;
P_0c076d78: /* original 2138, guest PC 0x0c076d78 */
if(!s->budget--) { s->failed_pc=0x0c076d78u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[3])==0)!=0);
goto P_0c076d7a;
P_0c076d7a: /* original 8957, guest PC 0x0c076d7a */
if(!s->budget--) { s->failed_pc=0x0c076d7au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c076e2c; }
goto P_0c076d7c;
P_0c076d7c: /* original 901a, guest PC 0x0c076d7c */
if(!s->budget--) { s->failed_pc=0x0c076d7cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c076db4u,2);
goto P_0c076d7e;
P_0c076d7e: /* original 03ed, guest PC 0x0c076d7e */
if(!s->budget--) { s->failed_pc=0x0c076d7eu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c076d80;
P_0c076d80: /* original 4315, guest PC 0x0c076d80 */
if(!s->budget--) { s->failed_pc=0x0c076d80u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>0)!=0);
goto P_0c076d82;
P_0c076d82: /* original 8967, guest PC 0x0c076d82 */
if(!s->budget--) { s->failed_pc=0x0c076d82u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c076e54; }
goto P_0c076d84;
P_0c076d84: /* original 9018, guest PC 0x0c076d84 */
if(!s->budget--) { s->failed_pc=0x0c076d84u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c076db8u,2);
goto P_0c076d86;
P_0c076d86: /* original 03ee, guest PC 0x0c076d86 */
if(!s->budget--) { s->failed_pc=0x0c076d86u; return 0; }
r[3]=read(ram,r[14]+r[0],4);
goto P_0c076d88;
P_0c076d88: /* original 2338, guest PC 0x0c076d88 */
if(!s->budget--) { s->failed_pc=0x0c076d88u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c076d8a;
P_0c076d8a: /* original 8b4f, guest PC 0x0c076d8a */
if(!s->budget--) { s->failed_pc=0x0c076d8au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c076e2c; }
goto P_0c076d8c;
P_0c076d8c: /* original 9015, guest PC 0x0c076d8c */
if(!s->budget--) { s->failed_pc=0x0c076d8cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c076dbau,2);
goto P_0c076d8e;
P_0c076d8e: /* original 03ee, guest PC 0x0c076d8e */
if(!s->budget--) { s->failed_pc=0x0c076d8eu; return 0; }
r[3]=read(ram,r[14]+r[0],4);
goto P_0c076d90;
P_0c076d90: /* original 2338, guest PC 0x0c076d90 */
if(!s->budget--) { s->failed_pc=0x0c076d90u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c076d92;
P_0c076d92: /* original 8b4b, guest PC 0x0c076d92 */
if(!s->budget--) { s->failed_pc=0x0c076d92u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c076e2c; }
goto P_0c076d94;
P_0c076d94: /* original e04c, guest PC 0x0c076d94 */
if(!s->budget--) { s->failed_pc=0x0c076d94u; return 0; }
r[0]=0x0000004cu;
goto P_0c076d96;
P_0c076d96: /* original 9311, guest PC 0x0c076d96 */
if(!s->budget--) { s->failed_pc=0x0c076d96u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c076dbcu,2);
goto P_0c076d98;
P_0c076d98: /* original 02ee, guest PC 0x0c076d98 */
if(!s->budget--) { s->failed_pc=0x0c076d98u; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c076d9a;
P_0c076d9a: /* original 2238, guest PC 0x0c076d9a */
if(!s->budget--) { s->failed_pc=0x0c076d9au; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c076d9c;
P_0c076d9c: /* original 8b5a, guest PC 0x0c076d9c */
if(!s->budget--) { s->failed_pc=0x0c076d9cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c076e54; }
goto P_0c076d9e;
P_0c076d9e: /* original 01ee, guest PC 0x0c076d9e */
if(!s->budget--) { s->failed_pc=0x0c076d9eu; return 0; }
r[1]=read(ram,r[14]+r[0],4);
goto P_0c076da0;
P_0c076da0: /* original 930d, guest PC 0x0c076da0 */
if(!s->budget--) { s->failed_pc=0x0c076da0u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c076dbeu,2);
goto P_0c076da2;
P_0c076da2: /* original 2138, guest PC 0x0c076da2 */
if(!s->budget--) { s->failed_pc=0x0c076da2u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[3])==0)!=0);
goto P_0c076da4;
P_0c076da4: /* original 8b5e, guest PC 0x0c076da4 */
if(!s->budget--) { s->failed_pc=0x0c076da4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c076e64; }
goto P_0c076da6;
P_0c076da6: /* original a041, guest PC 0x0c076da6 */
if(!s->budget--) { s->failed_pc=0x0c076da6u; return 0; }
goto P_0c076e2c;
P_0c076da8: /* original 0009, guest PC 0x0c076da8 */
if(!s->budget--) { s->failed_pc=0x0c076da8u; return 0; }
return vf3_matrix_family(0x0c076daau,s,ram);
P_0c076de0: /* original 906c, guest PC 0x0c076de0 */
if(!s->budget--) { s->failed_pc=0x0c076de0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c076ebcu,2);
goto P_0c076de2;
P_0c076de2: /* original d339, guest PC 0x0c076de2 */
if(!s->budget--) { s->failed_pc=0x0c076de2u; return 0; }
r[3]=read(ram,0x0c076ec8u,4);
goto P_0c076de4;
P_0c076de4: /* original 02fe, guest PC 0x0c076de4 */
if(!s->budget--) { s->failed_pc=0x0c076de4u; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c076de6;
P_0c076de6: /* original 2238, guest PC 0x0c076de6 */
if(!s->budget--) { s->failed_pc=0x0c076de6u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c076de8;
P_0c076de8: /* original 8b20, guest PC 0x0c076de8 */
if(!s->budget--) { s->failed_pc=0x0c076de8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c076e2c; }
goto P_0c076dea;
P_0c076dea: /* original 9068, guest PC 0x0c076dea */
if(!s->budget--) { s->failed_pc=0x0c076deau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c076ebeu,2);
goto P_0c076dec;
P_0c076dec: /* original e30d, guest PC 0x0c076dec */
if(!s->budget--) { s->failed_pc=0x0c076decu; return 0; }
r[3]=0x0000000du;
goto P_0c076dee;
P_0c076dee: /* original 01fe, guest PC 0x0c076dee */
if(!s->budget--) { s->failed_pc=0x0c076deeu; return 0; }
r[1]=read(ram,r[15]+r[0],4);
goto P_0c076df0;
P_0c076df0: /* original e06c, guest PC 0x0c076df0 */
if(!s->budget--) { s->failed_pc=0x0c076df0u; return 0; }
r[0]=0x0000006cu;
goto P_0c076df2;
P_0c076df2: /* original 413d, guest PC 0x0c076df2 */
if(!s->budget--) { s->failed_pc=0x0c076df2u; return 0; }
r[1]=(r[3]&0x80000000u)?((r[3]&31u)?r[1]>>((-r[3])&31u):0):r[1]<<(r[3]&31u);
goto P_0c076df4;
P_0c076df4: /* original 0f16, guest PC 0x0c076df4 */
if(!s->budget--) { s->failed_pc=0x0c076df4u; return 0; }
write(ram,r[15]+r[0],r[1],4);
goto P_0c076df6;
P_0c076df6: /* original 9061, guest PC 0x0c076df6 */
if(!s->budget--) { s->failed_pc=0x0c076df6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c076ebcu,2);
goto P_0c076df8;
P_0c076df8: /* original 02fe, guest PC 0x0c076df8 */
if(!s->budget--) { s->failed_pc=0x0c076df8u; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c076dfa;
P_0c076dfa: /* original 6013, guest PC 0x0c076dfa */
if(!s->budget--) { s->failed_pc=0x0c076dfau; return 0; }
r[0]=r[1];
goto P_0c076dfc;
P_0c076dfc: /* original 202b, guest PC 0x0c076dfc */
if(!s->budget--) { s->failed_pc=0x0c076dfcu; return 0; }
r[0]|=r[2];
goto P_0c076dfe;
P_0c076dfe: /* original 62f3, guest PC 0x0c076dfe */
if(!s->budget--) { s->failed_pc=0x0c076dfeu; return 0; }
r[2]=r[15];
goto P_0c076e00;
P_0c076e00: /* original 726c, guest PC 0x0c076e00 */
if(!s->budget--) { s->failed_pc=0x0c076e00u; return 0; }
r[2]+=0x0000006cu;
goto P_0c076e02;
P_0c076e02: /* original 2202, guest PC 0x0c076e02 */
if(!s->budget--) { s->failed_pc=0x0c076e02u; return 0; }
write(ram,r[2],r[0],4);
goto P_0c076e04;
P_0c076e04: /* original d131, guest PC 0x0c076e04 */
if(!s->budget--) { s->failed_pc=0x0c076e04u; return 0; }
r[1]=read(ram,0x0c076eccu,4);
goto P_0c076e06;
P_0c076e06: /* original 2018, guest PC 0x0c076e06 */
if(!s->budget--) { s->failed_pc=0x0c076e06u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[1])==0)!=0);
goto P_0c076e08;
P_0c076e08: /* original 8907, guest PC 0x0c076e08 */
if(!s->budget--) { s->failed_pc=0x0c076e08u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c076e1a; }
goto P_0c076e0a;
P_0c076e0a: /* original e064, guest PC 0x0c076e0a */
if(!s->budget--) { s->failed_pc=0x0c076e0au; return 0; }
r[0]=0x00000064u;
goto P_0c076e0c;
P_0c076e0c: /* original 02ed, guest PC 0x0c076e0c */
if(!s->budget--) { s->failed_pc=0x0c076e0cu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c076e0e;
P_0c076e0e: /* original 2228, guest PC 0x0c076e0e */
if(!s->budget--) { s->failed_pc=0x0c076e0eu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c076e10;
P_0c076e10: /* original 890c, guest PC 0x0c076e10 */
if(!s->budget--) { s->failed_pc=0x0c076e10u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c076e2c; }
goto P_0c076e12;
P_0c076e12: /* original 51ee, guest PC 0x0c076e12 */
if(!s->budget--) { s->failed_pc=0x0c076e12u; return 0; }
r[1]=read(ram,r[14]+56,4);
goto P_0c076e14;
P_0c076e14: /* original d32e, guest PC 0x0c076e14 */
if(!s->budget--) { s->failed_pc=0x0c076e14u; return 0; }
r[3]=read(ram,0x0c076ed0u,4);
goto P_0c076e16;
P_0c076e16: /* original 2138, guest PC 0x0c076e16 */
if(!s->budget--) { s->failed_pc=0x0c076e16u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[3])==0)!=0);
goto P_0c076e18;
P_0c076e18: /* original 8908, guest PC 0x0c076e18 */
if(!s->budget--) { s->failed_pc=0x0c076e18u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c076e2c; }
goto P_0c076e1a;
P_0c076e1a: /* original e04c, guest PC 0x0c076e1a */
if(!s->budget--) { s->failed_pc=0x0c076e1au; return 0; }
r[0]=0x0000004cu;
goto P_0c076e1c;
P_0c076e1c: /* original 9350, guest PC 0x0c076e1c */
if(!s->budget--) { s->failed_pc=0x0c076e1cu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c076ec0u,2);
goto P_0c076e1e;
P_0c076e1e: /* original 02ee, guest PC 0x0c076e1e */
if(!s->budget--) { s->failed_pc=0x0c076e1eu; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c076e20;
P_0c076e20: /* original 2238, guest PC 0x0c076e20 */
if(!s->budget--) { s->failed_pc=0x0c076e20u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c076e22;
P_0c076e22: /* original 8b03, guest PC 0x0c076e22 */
if(!s->budget--) { s->failed_pc=0x0c076e22u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c076e2c; }
goto P_0c076e24;
P_0c076e24: /* original e070, guest PC 0x0c076e24 */
if(!s->budget--) { s->failed_pc=0x0c076e24u; return 0; }
r[0]=0x00000070u;
goto P_0c076e26;
P_0c076e26: /* original 01fe, guest PC 0x0c076e26 */
if(!s->budget--) { s->failed_pc=0x0c076e26u; return 0; }
r[1]=read(ram,r[15]+r[0],4);
goto P_0c076e28;
P_0c076e28: /* original 2118, guest PC 0x0c076e28 */
if(!s->budget--) { s->failed_pc=0x0c076e28u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[1])==0)!=0);
goto P_0c076e2a;
P_0c076e2a: /* original 891b, guest PC 0x0c076e2a */
if(!s->budget--) { s->failed_pc=0x0c076e2au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c076e64; }
goto P_0c076e2c;
P_0c076e2c: /* original 9049, guest PC 0x0c076e2c */
if(!s->budget--) { s->failed_pc=0x0c076e2cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c076ec2u,2);
goto P_0c076e2e;
P_0c076e2e: /* original d329, guest PC 0x0c076e2e */
if(!s->budget--) { s->failed_pc=0x0c076e2eu; return 0; }
r[3]=read(ram,0x0c076ed4u,4);
goto P_0c076e30;
P_0c076e30: /* original 01fe, guest PC 0x0c076e30 */
if(!s->budget--) { s->failed_pc=0x0c076e30u; return 0; }
r[1]=read(ram,r[15]+r[0],4);
goto P_0c076e32;
P_0c076e32: /* original 9046, guest PC 0x0c076e32 */
if(!s->budget--) { s->failed_pc=0x0c076e32u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c076ec2u,2);
goto P_0c076e34;
P_0c076e34: /* original 213b, guest PC 0x0c076e34 */
if(!s->budget--) { s->failed_pc=0x0c076e34u; return 0; }
r[1]|=r[3];
goto P_0c076e36;
P_0c076e36: /* original 0f16, guest PC 0x0c076e36 */
if(!s->budget--) { s->failed_pc=0x0c076e36u; return 0; }
write(ram,r[15]+r[0],r[1],4);
goto P_0c076e38;
P_0c076e38: /* original e04c, guest PC 0x0c076e38 */
if(!s->budget--) { s->failed_pc=0x0c076e38u; return 0; }
r[0]=0x0000004cu;
goto P_0c076e3a;
P_0c076e3a: /* original 02ee, guest PC 0x0c076e3a */
if(!s->budget--) { s->failed_pc=0x0c076e3au; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c076e3c;
P_0c076e3c: /* original e06c, guest PC 0x0c076e3c */
if(!s->budget--) { s->failed_pc=0x0c076e3cu; return 0; }
r[0]=0x0000006cu;
goto P_0c076e3e;
P_0c076e3e: /* original 0f26, guest PC 0x0c076e3e */
if(!s->budget--) { s->failed_pc=0x0c076e3eu; return 0; }
write(ram,r[15]+r[0],r[2],4);
goto P_0c076e40;
P_0c076e40: /* original e06c, guest PC 0x0c076e40 */
if(!s->budget--) { s->failed_pc=0x0c076e40u; return 0; }
r[0]=0x0000006cu;
goto P_0c076e42;
P_0c076e42: /* original 01fe, guest PC 0x0c076e42 */
if(!s->budget--) { s->failed_pc=0x0c076e42u; return 0; }
r[1]=read(ram,r[15]+r[0],4);
goto P_0c076e44;
P_0c076e44: /* original d224, guest PC 0x0c076e44 */
if(!s->budget--) { s->failed_pc=0x0c076e44u; return 0; }
r[2]=read(ram,0x0c076ed8u,4);
goto P_0c076e46;
P_0c076e46: /* original 2128, guest PC 0x0c076e46 */
if(!s->budget--) { s->failed_pc=0x0c076e46u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[2])==0)!=0);
goto P_0c076e48;
P_0c076e48: /* original 8b04, guest PC 0x0c076e48 */
if(!s->budget--) { s->failed_pc=0x0c076e48u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c076e54; }
goto P_0c076e4a;
P_0c076e4a: /* original e06c, guest PC 0x0c076e4a */
if(!s->budget--) { s->failed_pc=0x0c076e4au; return 0; }
r[0]=0x0000006cu;
goto P_0c076e4c;
P_0c076e4c: /* original d123, guest PC 0x0c076e4c */
if(!s->budget--) { s->failed_pc=0x0c076e4cu; return 0; }
r[1]=read(ram,0x0c076edcu,4);
goto P_0c076e4e;
P_0c076e4e: /* original 00fe, guest PC 0x0c076e4e */
if(!s->budget--) { s->failed_pc=0x0c076e4eu; return 0; }
r[0]=read(ram,r[15]+r[0],4);
goto P_0c076e50;
P_0c076e50: /* original 2018, guest PC 0x0c076e50 */
if(!s->budget--) { s->failed_pc=0x0c076e50u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[1])==0)!=0);
goto P_0c076e52;
P_0c076e52: /* original 8959, guest PC 0x0c076e52 */
if(!s->budget--) { s->failed_pc=0x0c076e52u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c076f08; }
goto P_0c076e54;
P_0c076e54: /* original e070, guest PC 0x0c076e54 */
if(!s->budget--) { s->failed_pc=0x0c076e54u; return 0; }
r[0]=0x00000070u;
goto P_0c076e56;
P_0c076e56: /* original 02fe, guest PC 0x0c076e56 */
if(!s->budget--) { s->failed_pc=0x0c076e56u; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c076e58;
P_0c076e58: /* original 2228, guest PC 0x0c076e58 */
if(!s->budget--) { s->failed_pc=0x0c076e58u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c076e5a;
P_0c076e5a: /* original 8903, guest PC 0x0c076e5a */
if(!s->budget--) { s->failed_pc=0x0c076e5au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c076e64; }
goto P_0c076e5c;
P_0c076e5c: /* original 9032, guest PC 0x0c076e5c */
if(!s->budget--) { s->failed_pc=0x0c076e5cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c076ec4u,2);
goto P_0c076e5e;
P_0c076e5e: /* original 02ed, guest PC 0x0c076e5e */
if(!s->budget--) { s->failed_pc=0x0c076e5eu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c076e60;
P_0c076e60: /* original 2228, guest PC 0x0c076e60 */
if(!s->budget--) { s->failed_pc=0x0c076e60u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c076e62;
P_0c076e62: /* original 8b51, guest PC 0x0c076e62 */
if(!s->budget--) { s->failed_pc=0x0c076e62u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c076f08; }
goto P_0c076e64;
P_0c076e64: /* original e07c, guest PC 0x0c076e64 */
if(!s->budget--) { s->failed_pc=0x0c076e64u; return 0; }
r[0]=0x0000007cu;
goto P_0c076e66;
P_0c076e66: /* original 00fe, guest PC 0x0c076e66 */
if(!s->budget--) { s->failed_pc=0x0c076e66u; return 0; }
r[0]=read(ram,r[15]+r[0],4);
goto P_0c076e68;
P_0c076e68: /* original 8808, guest PC 0x0c076e68 */
if(!s->budget--) { s->failed_pc=0x0c076e68u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000008u)!=0);
goto P_0c076e6a;
P_0c076e6a: /* original 8b43, guest PC 0x0c076e6a */
if(!s->budget--) { s->failed_pc=0x0c076e6au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c076ef4; }
goto P_0c076e6c;
P_0c076e6c: /* original 9026, guest PC 0x0c076e6c */
if(!s->budget--) { s->failed_pc=0x0c076e6cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c076ebcu,2);
goto P_0c076e6e;
P_0c076e6e: /* original d31c, guest PC 0x0c076e6e */
if(!s->budget--) { s->failed_pc=0x0c076e6eu; return 0; }
r[3]=read(ram,0x0c076ee0u,4);
goto P_0c076e70;
P_0c076e70: /* original 02fe, guest PC 0x0c076e70 */
if(!s->budget--) { s->failed_pc=0x0c076e70u; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c076e72;
P_0c076e72: /* original 2238, guest PC 0x0c076e72 */
if(!s->budget--) { s->failed_pc=0x0c076e72u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c076e74;
P_0c076e74: /* original 8b3e, guest PC 0x0c076e74 */
if(!s->budget--) { s->failed_pc=0x0c076e74u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c076ef4; }
goto P_0c076e76;
P_0c076e76: /* original 9021, guest PC 0x0c076e76 */
if(!s->budget--) { s->failed_pc=0x0c076e76u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c076ebcu,2);
goto P_0c076e78;
P_0c076e78: /* original d21a, guest PC 0x0c076e78 */
if(!s->budget--) { s->failed_pc=0x0c076e78u; return 0; }
r[2]=read(ram,0x0c076ee4u,4);
goto P_0c076e7a;
P_0c076e7a: /* original 01fe, guest PC 0x0c076e7a */
if(!s->budget--) { s->failed_pc=0x0c076e7au; return 0; }
r[1]=read(ram,r[15]+r[0],4);
goto P_0c076e7c;
P_0c076e7c: /* original 2128, guest PC 0x0c076e7c */
if(!s->budget--) { s->failed_pc=0x0c076e7cu; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[2])==0)!=0);
goto P_0c076e7e;
P_0c076e7e: /* original 8b39, guest PC 0x0c076e7e */
if(!s->budget--) { s->failed_pc=0x0c076e7eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c076ef4; }
goto P_0c076e80;
P_0c076e80: /* original 901c, guest PC 0x0c076e80 */
if(!s->budget--) { s->failed_pc=0x0c076e80u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c076ebcu,2);
goto P_0c076e82;
P_0c076e82: /* original d112, guest PC 0x0c076e82 */
if(!s->budget--) { s->failed_pc=0x0c076e82u; return 0; }
r[1]=read(ram,0x0c076eccu,4);
goto P_0c076e84;
P_0c076e84: /* original 00fe, guest PC 0x0c076e84 */
if(!s->budget--) { s->failed_pc=0x0c076e84u; return 0; }
r[0]=read(ram,r[15]+r[0],4);
goto P_0c076e86;
P_0c076e86: /* original 2018, guest PC 0x0c076e86 */
if(!s->budget--) { s->failed_pc=0x0c076e86u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[1])==0)!=0);
goto P_0c076e88;
P_0c076e88: /* original 8b34, guest PC 0x0c076e88 */
if(!s->budget--) { s->failed_pc=0x0c076e88u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c076ef4; }
goto P_0c076e8a;
P_0c076e8a: /* original 9217, guest PC 0x0c076e8a */
if(!s->budget--) { s->failed_pc=0x0c076e8au; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c076ebcu,2);
goto P_0c076e8c;
P_0c076e8c: /* original 32fc, guest PC 0x0c076e8c */
if(!s->budget--) { s->failed_pc=0x0c076e8cu; return 0; }
r[2]+=r[15];
goto P_0c076e8e;
P_0c076e8e: /* original 6022, guest PC 0x0c076e8e */
if(!s->budget--) { s->failed_pc=0x0c076e8eu; return 0; }
tmp=read(ram,r[2],4);
r[0]=tmp;
goto P_0c076e90;
P_0c076e90: /* original c840, guest PC 0x0c076e90 */
if(!s->budget--) { s->failed_pc=0x0c076e90u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&64u)==0)!=0);
goto P_0c076e92;
P_0c076e92: /* original 8902, guest PC 0x0c076e92 */
if(!s->budget--) { s->failed_pc=0x0c076e92u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c076e9a; }
goto P_0c076e94;
P_0c076e94: /* original d114, guest PC 0x0c076e94 */
if(!s->budget--) { s->failed_pc=0x0c076e94u; return 0; }
r[1]=read(ram,0x0c076ee8u,4);
goto P_0c076e96;
P_0c076e96: /* original a006, guest PC 0x0c076e96 */
if(!s->budget--) { s->failed_pc=0x0c076e96u; return 0; }
goto P_0c076ea6;
P_0c076e98: /* original 0009, guest PC 0x0c076e98 */
if(!s->budget--) { s->failed_pc=0x0c076e98u; return 0; }
goto P_0c076e9a;
P_0c076e9a: /* original 920f, guest PC 0x0c076e9a */
if(!s->budget--) { s->failed_pc=0x0c076e9au; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c076ebcu,2);
goto P_0c076e9c;
P_0c076e9c: /* original 32fc, guest PC 0x0c076e9c */
if(!s->budget--) { s->failed_pc=0x0c076e9cu; return 0; }
r[2]+=r[15];
goto P_0c076e9e;
P_0c076e9e: /* original 6022, guest PC 0x0c076e9e */
if(!s->budget--) { s->failed_pc=0x0c076e9eu; return 0; }
tmp=read(ram,r[2],4);
r[0]=tmp;
goto P_0c076ea0;
P_0c076ea0: /* original c820, guest PC 0x0c076ea0 */
if(!s->budget--) { s->failed_pc=0x0c076ea0u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&32u)==0)!=0);
goto P_0c076ea2;
P_0c076ea2: /* original 8903, guest PC 0x0c076ea2 */
if(!s->budget--) { s->failed_pc=0x0c076ea2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c076eac; }
goto P_0c076ea4;
P_0c076ea4: /* original d111, guest PC 0x0c076ea4 */
if(!s->budget--) { s->failed_pc=0x0c076ea4u; return 0; }
r[1]=read(ram,0x0c076eecu,4);
goto P_0c076ea6;
P_0c076ea6: /* original e070, guest PC 0x0c076ea6 */
if(!s->budget--) { s->failed_pc=0x0c076ea6u; return 0; }
r[0]=0x00000070u;
goto P_0c076ea8;
P_0c076ea8: /* original a02b, guest PC 0x0c076ea8 */
if(!s->budget--) { s->failed_pc=0x0c076ea8u; return 0; }
write(ram,r[15]+r[0],r[1],4);
goto P_0c076f02;
P_0c076eaa: /* original 0f16, guest PC 0x0c076eaa */
if(!s->budget--) { s->failed_pc=0x0c076eaau; return 0; }
write(ram,r[15]+r[0],r[1],4);
goto P_0c076eac;
P_0c076eac: /* original e07c, guest PC 0x0c076eac */
if(!s->budget--) { s->failed_pc=0x0c076eacu; return 0; }
r[0]=0x0000007cu;
goto P_0c076eae;
P_0c076eae: /* original 02fe, guest PC 0x0c076eae */
if(!s->budget--) { s->failed_pc=0x0c076eaeu; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c076eb0;
P_0c076eb0: /* original d00f, guest PC 0x0c076eb0 */
if(!s->budget--) { s->failed_pc=0x0c076eb0u; return 0; }
r[0]=read(ram,0x0c076ef0u,4);
goto P_0c076eb2;
P_0c076eb2: /* original 4208, guest PC 0x0c076eb2 */
if(!s->budget--) { s->failed_pc=0x0c076eb2u; return 0; }
r[2]<<=2;
goto P_0c076eb4;
P_0c076eb4: /* original 032e, guest PC 0x0c076eb4 */
if(!s->budget--) { s->failed_pc=0x0c076eb4u; return 0; }
r[3]=read(ram,r[2]+r[0],4);
goto P_0c076eb6;
P_0c076eb6: /* original e070, guest PC 0x0c076eb6 */
if(!s->budget--) { s->failed_pc=0x0c076eb6u; return 0; }
r[0]=0x00000070u;
goto P_0c076eb8;
P_0c076eb8: /* original a023, guest PC 0x0c076eb8 */
if(!s->budget--) { s->failed_pc=0x0c076eb8u; return 0; }
write(ram,r[15]+r[0],r[3],4);
goto P_0c076f02;
P_0c076eba: /* original 0f36, guest PC 0x0c076eba */
if(!s->budget--) { s->failed_pc=0x0c076ebau; return 0; }
write(ram,r[15]+r[0],r[3],4);
return vf3_matrix_family(0x0c076ebcu,s,ram);
P_0c076ef4: /* original e07c, guest PC 0x0c076ef4 */
if(!s->budget--) { s->failed_pc=0x0c076ef4u; return 0; }
r[0]=0x0000007cu;
goto P_0c076ef6;
P_0c076ef6: /* original 01fe, guest PC 0x0c076ef6 */
if(!s->budget--) { s->failed_pc=0x0c076ef6u; return 0; }
r[1]=read(ram,r[15]+r[0],4);
goto P_0c076ef8;
P_0c076ef8: /* original d05e, guest PC 0x0c076ef8 */
if(!s->budget--) { s->failed_pc=0x0c076ef8u; return 0; }
r[0]=read(ram,0x0c077074u,4);
goto P_0c076efa;
P_0c076efa: /* original 4108, guest PC 0x0c076efa */
if(!s->budget--) { s->failed_pc=0x0c076efau; return 0; }
r[1]<<=2;
goto P_0c076efc;
P_0c076efc: /* original 031e, guest PC 0x0c076efc */
if(!s->budget--) { s->failed_pc=0x0c076efcu; return 0; }
r[3]=read(ram,r[1]+r[0],4);
goto P_0c076efe;
P_0c076efe: /* original e070, guest PC 0x0c076efe */
if(!s->budget--) { s->failed_pc=0x0c076efeu; return 0; }
r[0]=0x00000070u;
goto P_0c076f00;
P_0c076f00: /* original 0f36, guest PC 0x0c076f00 */
if(!s->budget--) { s->failed_pc=0x0c076f00u; return 0; }
write(ram,r[15]+r[0],r[3],4);
goto P_0c076f02;
P_0c076f02: /* original 90ad, guest PC 0x0c076f02 */
if(!s->budget--) { s->failed_pc=0x0c076f02u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077060u,2);
goto P_0c076f04;
P_0c076f04: /* original e200, guest PC 0x0c076f04 */
if(!s->budget--) { s->failed_pc=0x0c076f04u; return 0; }
r[2]=0x00000000u;
goto P_0c076f06;
P_0c076f06: /* original 0e26, guest PC 0x0c076f06 */
if(!s->budget--) { s->failed_pc=0x0c076f06u; return 0; }
write(ram,r[14]+r[0],r[2],4);
goto P_0c076f08;
P_0c076f08: /* original 90ab, guest PC 0x0c076f08 */
if(!s->budget--) { s->failed_pc=0x0c076f08u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077062u,2);
goto P_0c076f0a;
P_0c076f0a: /* original 03ec, guest PC 0x0c076f0a */
if(!s->budget--) { s->failed_pc=0x0c076f0au; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c076f0c;
P_0c076f0c: /* original 633c, guest PC 0x0c076f0c */
if(!s->budget--) { s->failed_pc=0x0c076f0cu; return 0; }
r[3]=r[3]&255u;
goto P_0c076f0e;
P_0c076f0e: /* original 1f38, guest PC 0x0c076f0e */
if(!s->budget--) { s->failed_pc=0x0c076f0eu; return 0; }
write(ram,r[15]+32,r[3],4);
goto P_0c076f10;
P_0c076f10: /* original 4308, guest PC 0x0c076f10 */
if(!s->budget--) { s->failed_pc=0x0c076f10u; return 0; }
r[3]<<=2;
goto P_0c076f12;
P_0c076f12: /* original 92a7, guest PC 0x0c076f12 */
if(!s->budget--) { s->failed_pc=0x0c076f12u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077064u,2);
goto P_0c076f14;
P_0c076f14: /* original 2329, guest PC 0x0c076f14 */
if(!s->budget--) { s->failed_pc=0x0c076f14u; return 0; }
r[3]&=r[2];
goto P_0c076f16;
P_0c076f16: /* original 1f35, guest PC 0x0c076f16 */
if(!s->budget--) { s->failed_pc=0x0c076f16u; return 0; }
write(ram,r[15]+20,r[3],4);
goto P_0c076f18;
P_0c076f18: /* original 50f8, guest PC 0x0c076f18 */
if(!s->budget--) { s->failed_pc=0x0c076f18u; return 0; }
r[0]=read(ram,r[15]+32,4);
goto P_0c076f1a;
P_0c076f1a: /* original 70ff, guest PC 0x0c076f1a */
if(!s->budget--) { s->failed_pc=0x0c076f1au; return 0; }
r[0]+=0xffffffffu;
goto P_0c076f1c;
P_0c076f1c: /* original 4008, guest PC 0x0c076f1c */
if(!s->budget--) { s->failed_pc=0x0c076f1cu; return 0; }
r[0]<<=2;
goto P_0c076f1e;
P_0c076f1e: /* original c9fc, guest PC 0x0c076f1e */
if(!s->budget--) { s->failed_pc=0x0c076f1eu; return 0; }
r[0]&=252u;
goto P_0c076f20;
P_0c076f20: /* original 6303, guest PC 0x0c076f20 */
if(!s->budget--) { s->failed_pc=0x0c076f20u; return 0; }
r[3]=r[0];
goto P_0c076f22;
P_0c076f22: /* original 2f02, guest PC 0x0c076f22 */
if(!s->budget--) { s->failed_pc=0x0c076f22u; return 0; }
write(ram,r[15],r[0],4);
goto P_0c076f24;
P_0c076f24: /* original 929f, guest PC 0x0c076f24 */
if(!s->budget--) { s->failed_pc=0x0c076f24u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077066u,2);
goto P_0c076f26;
P_0c076f26: /* original e058, guest PC 0x0c076f26 */
if(!s->budget--) { s->failed_pc=0x0c076f26u; return 0; }
r[0]=0x00000058u;
goto P_0c076f28;
P_0c076f28: /* original 32ec, guest PC 0x0c076f28 */
if(!s->budget--) { s->failed_pc=0x0c076f28u; return 0; }
r[2]+=r[14];
goto P_0c076f2a;
P_0c076f2a: /* original 323c, guest PC 0x0c076f2a */
if(!s->budget--) { s->failed_pc=0x0c076f2au; return 0; }
r[2]+=r[3];
goto P_0c076f2c;
P_0c076f2c: /* original 6120, guest PC 0x0c076f2c */
if(!s->budget--) { s->failed_pc=0x0c076f2cu; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[2],1);
r[1]=tmp;
goto P_0c076f2e;
P_0c076f2e: /* original 611c, guest PC 0x0c076f2e */
if(!s->budget--) { s->failed_pc=0x0c076f2eu; return 0; }
r[1]=r[1]&255u;
goto P_0c076f30;
P_0c076f30: /* original 0f16, guest PC 0x0c076f30 */
if(!s->budget--) { s->failed_pc=0x0c076f30u; return 0; }
write(ram,r[15]+r[0],r[1],4);
goto P_0c076f32;
P_0c076f32: /* original 61f3, guest PC 0x0c076f32 */
if(!s->budget--) { s->failed_pc=0x0c076f32u; return 0; }
r[1]=r[15];
goto P_0c076f34;
P_0c076f34: /* original 9297, guest PC 0x0c076f34 */
if(!s->budget--) { s->failed_pc=0x0c076f34u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077066u,2);
goto P_0c076f36;
P_0c076f36: /* original 7154, guest PC 0x0c076f36 */
if(!s->budget--) { s->failed_pc=0x0c076f36u; return 0; }
r[1]+=0x00000054u;
goto P_0c076f38;
P_0c076f38: /* original 63f2, guest PC 0x0c076f38 */
if(!s->budget--) { s->failed_pc=0x0c076f38u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c076f3a;
P_0c076f3a: /* original 32ec, guest PC 0x0c076f3a */
if(!s->budget--) { s->failed_pc=0x0c076f3au; return 0; }
r[2]+=r[14];
goto P_0c076f3c;
P_0c076f3c: /* original 323c, guest PC 0x0c076f3c */
if(!s->budget--) { s->failed_pc=0x0c076f3cu; return 0; }
r[2]+=r[3];
goto P_0c076f3e;
P_0c076f3e: /* original 8421, guest PC 0x0c076f3e */
if(!s->budget--) { s->failed_pc=0x0c076f3eu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[2]+1,1);
goto P_0c076f40;
P_0c076f40: /* original 600c, guest PC 0x0c076f40 */
if(!s->budget--) { s->failed_pc=0x0c076f40u; return 0; }
r[0]=r[0]&255u;
goto P_0c076f42;
P_0c076f42: /* original 2102, guest PC 0x0c076f42 */
if(!s->budget--) { s->failed_pc=0x0c076f42u; return 0; }
write(ram,r[1],r[0],4);
goto P_0c076f44;
P_0c076f44: /* original e058, guest PC 0x0c076f44 */
if(!s->budget--) { s->failed_pc=0x0c076f44u; return 0; }
r[0]=0x00000058u;
goto P_0c076f46;
P_0c076f46: /* original 02fe, guest PC 0x0c076f46 */
if(!s->budget--) { s->failed_pc=0x0c076f46u; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c076f48;
P_0c076f48: /* original 51f1, guest PC 0x0c076f48 */
if(!s->budget--) { s->failed_pc=0x0c076f48u; return 0; }
r[1]=read(ram,r[15]+4,4);
goto P_0c076f4a;
P_0c076f4a: /* original 6227, guest PC 0x0c076f4a */
if(!s->budget--) { s->failed_pc=0x0c076f4au; return 0; }
r[2]=~r[2];
goto P_0c076f4c;
P_0c076f4c: /* original e050, guest PC 0x0c076f4c */
if(!s->budget--) { s->failed_pc=0x0c076f4cu; return 0; }
r[0]=0x00000050u;
goto P_0c076f4e;
P_0c076f4e: /* original 2219, guest PC 0x0c076f4e */
if(!s->budget--) { s->failed_pc=0x0c076f4eu; return 0; }
r[2]&=r[1];
goto P_0c076f50;
P_0c076f50: /* original 0f26, guest PC 0x0c076f50 */
if(!s->budget--) { s->failed_pc=0x0c076f50u; return 0; }
write(ram,r[15]+r[0],r[2],4);
goto P_0c076f52;
P_0c076f52: /* original e050, guest PC 0x0c076f52 */
if(!s->budget--) { s->failed_pc=0x0c076f52u; return 0; }
r[0]=0x00000050u;
goto P_0c076f54;
P_0c076f54: /* original 9187, guest PC 0x0c076f54 */
if(!s->budget--) { s->failed_pc=0x0c076f54u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077066u,2);
goto P_0c076f56;
P_0c076f56: /* original 53f5, guest PC 0x0c076f56 */
if(!s->budget--) { s->failed_pc=0x0c076f56u; return 0; }
r[3]=read(ram,r[15]+20,4);
goto P_0c076f58;
P_0c076f58: /* original 52f1, guest PC 0x0c076f58 */
if(!s->budget--) { s->failed_pc=0x0c076f58u; return 0; }
r[2]=read(ram,r[15]+4,4);
goto P_0c076f5a;
P_0c076f5a: /* original 31ec, guest PC 0x0c076f5a */
if(!s->budget--) { s->failed_pc=0x0c076f5au; return 0; }
r[1]+=r[14];
goto P_0c076f5c;
P_0c076f5c: /* original 313c, guest PC 0x0c076f5c */
if(!s->budget--) { s->failed_pc=0x0c076f5cu; return 0; }
r[1]+=r[3];
goto P_0c076f5e;
P_0c076f5e: /* original 2120, guest PC 0x0c076f5e */
if(!s->budget--) { s->failed_pc=0x0c076f5eu; return 0; }
write(ram,r[1],r[2],1);
goto P_0c076f60;
P_0c076f60: /* original 9181, guest PC 0x0c076f60 */
if(!s->budget--) { s->failed_pc=0x0c076f60u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077066u,2);
goto P_0c076f62;
P_0c076f62: /* original 53f5, guest PC 0x0c076f62 */
if(!s->budget--) { s->failed_pc=0x0c076f62u; return 0; }
r[3]=read(ram,r[15]+20,4);
goto P_0c076f64;
P_0c076f64: /* original 00fc, guest PC 0x0c076f64 */
if(!s->budget--) { s->failed_pc=0x0c076f64u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[15]+r[0],1);
goto P_0c076f66;
P_0c076f66: /* original 31ec, guest PC 0x0c076f66 */
if(!s->budget--) { s->failed_pc=0x0c076f66u; return 0; }
r[1]+=r[14];
goto P_0c076f68;
P_0c076f68: /* original 313c, guest PC 0x0c076f68 */
if(!s->budget--) { s->failed_pc=0x0c076f68u; return 0; }
r[1]+=r[3];
goto P_0c076f6a;
P_0c076f6a: /* original 8012, guest PC 0x0c076f6a */
if(!s->budget--) { s->failed_pc=0x0c076f6au; return 0; }
write(ram,r[1]+2,r[0],1);
goto P_0c076f6c;
P_0c076f6c: /* original e058, guest PC 0x0c076f6c */
if(!s->budget--) { s->failed_pc=0x0c076f6cu; return 0; }
r[0]=0x00000058u;
goto P_0c076f6e;
P_0c076f6e: /* original 53f1, guest PC 0x0c076f6e */
if(!s->budget--) { s->failed_pc=0x0c076f6eu; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c076f70;
P_0c076f70: /* original 02fe, guest PC 0x0c076f70 */
if(!s->budget--) { s->failed_pc=0x0c076f70u; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c076f72;
P_0c076f72: /* original 6337, guest PC 0x0c076f72 */
if(!s->budget--) { s->failed_pc=0x0c076f72u; return 0; }
r[3]=~r[3];
goto P_0c076f74;
P_0c076f74: /* original 2329, guest PC 0x0c076f74 */
if(!s->budget--) { s->failed_pc=0x0c076f74u; return 0; }
r[3]&=r[2];
goto P_0c076f76;
P_0c076f76: /* original 1f3f, guest PC 0x0c076f76 */
if(!s->budget--) { s->failed_pc=0x0c076f76u; return 0; }
write(ram,r[15]+60,r[3],4);
goto P_0c076f78;
P_0c076f78: /* original 9275, guest PC 0x0c076f78 */
if(!s->budget--) { s->failed_pc=0x0c076f78u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077066u,2);
goto P_0c076f7a;
P_0c076f7a: /* original 53f5, guest PC 0x0c076f7a */
if(!s->budget--) { s->failed_pc=0x0c076f7au; return 0; }
r[3]=read(ram,r[15]+20,4);
goto P_0c076f7c;
P_0c076f7c: /* original 50ff, guest PC 0x0c076f7c */
if(!s->budget--) { s->failed_pc=0x0c076f7cu; return 0; }
r[0]=read(ram,r[15]+60,4);
goto P_0c076f7e;
P_0c076f7e: /* original 32ec, guest PC 0x0c076f7e */
if(!s->budget--) { s->failed_pc=0x0c076f7eu; return 0; }
r[2]+=r[14];
goto P_0c076f80;
P_0c076f80: /* original 323c, guest PC 0x0c076f80 */
if(!s->budget--) { s->failed_pc=0x0c076f80u; return 0; }
r[2]+=r[3];
goto P_0c076f82;
P_0c076f82: /* original 8023, guest PC 0x0c076f82 */
if(!s->budget--) { s->failed_pc=0x0c076f82u; return 0; }
write(ram,r[2]+3,r[0],1);
goto P_0c076f84;
P_0c076f84: /* original e04c, guest PC 0x0c076f84 */
if(!s->budget--) { s->failed_pc=0x0c076f84u; return 0; }
r[0]=0x0000004cu;
goto P_0c076f86;
P_0c076f86: /* original 53f1, guest PC 0x0c076f86 */
if(!s->budget--) { s->failed_pc=0x0c076f86u; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c076f88;
P_0c076f88: /* original 0f36, guest PC 0x0c076f88 */
if(!s->budget--) { s->failed_pc=0x0c076f88u; return 0; }
write(ram,r[15]+r[0],r[3],4);
goto P_0c076f8a;
P_0c076f8a: /* original 50f1, guest PC 0x0c076f8a */
if(!s->budget--) { s->failed_pc=0x0c076f8au; return 0; }
r[0]=read(ram,r[15]+4,4);
goto P_0c076f8c;
P_0c076f8c: /* original c8c0, guest PC 0x0c076f8c */
if(!s->budget--) { s->failed_pc=0x0c076f8cu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&192u)==0)!=0);
goto P_0c076f8e;
P_0c076f8e: /* original 8b09, guest PC 0x0c076f8e */
if(!s->budget--) { s->failed_pc=0x0c076f8eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c076fa4; }
goto P_0c076f90;
P_0c076f90: /* original 62f3, guest PC 0x0c076f90 */
if(!s->budget--) { s->failed_pc=0x0c076f90u; return 0; }
r[2]=r[15];
goto P_0c076f92;
P_0c076f92: /* original 61f3, guest PC 0x0c076f92 */
if(!s->budget--) { s->failed_pc=0x0c076f92u; return 0; }
r[1]=r[15];
goto P_0c076f94;
P_0c076f94: /* original 7254, guest PC 0x0c076f94 */
if(!s->budget--) { s->failed_pc=0x0c076f94u; return 0; }
r[2]+=0x00000054u;
goto P_0c076f96;
P_0c076f96: /* original 714c, guest PC 0x0c076f96 */
if(!s->budget--) { s->failed_pc=0x0c076f96u; return 0; }
r[1]+=0x0000004cu;
goto P_0c076f98;
P_0c076f98: /* original 6022, guest PC 0x0c076f98 */
if(!s->budget--) { s->failed_pc=0x0c076f98u; return 0; }
tmp=read(ram,r[2],4);
r[0]=tmp;
goto P_0c076f9a;
P_0c076f9a: /* original 6312, guest PC 0x0c076f9a */
if(!s->budget--) { s->failed_pc=0x0c076f9au; return 0; }
tmp=read(ram,r[1],4);
r[3]=tmp;
goto P_0c076f9c;
P_0c076f9c: /* original c9c0, guest PC 0x0c076f9c */
if(!s->budget--) { s->failed_pc=0x0c076f9cu; return 0; }
r[0]&=192u;
goto P_0c076f9e;
P_0c076f9e: /* original 230b, guest PC 0x0c076f9e */
if(!s->budget--) { s->failed_pc=0x0c076f9eu; return 0; }
r[3]|=r[0];
goto P_0c076fa0;
P_0c076fa0: /* original e04c, guest PC 0x0c076fa0 */
if(!s->budget--) { s->failed_pc=0x0c076fa0u; return 0; }
r[0]=0x0000004cu;
goto P_0c076fa2;
P_0c076fa2: /* original 0f36, guest PC 0x0c076fa2 */
if(!s->budget--) { s->failed_pc=0x0c076fa2u; return 0; }
write(ram,r[15]+r[0],r[3],4);
goto P_0c076fa4;
P_0c076fa4: /* original 62f3, guest PC 0x0c076fa4 */
if(!s->budget--) { s->failed_pc=0x0c076fa4u; return 0; }
r[2]=r[15];
goto P_0c076fa6;
P_0c076fa6: /* original 724c, guest PC 0x0c076fa6 */
if(!s->budget--) { s->failed_pc=0x0c076fa6u; return 0; }
r[2]+=0x0000004cu;
goto P_0c076fa8;
P_0c076fa8: /* original 6022, guest PC 0x0c076fa8 */
if(!s->budget--) { s->failed_pc=0x0c076fa8u; return 0; }
tmp=read(ram,r[2],4);
r[0]=tmp;
goto P_0c076faa;
P_0c076faa: /* original c830, guest PC 0x0c076faa */
if(!s->budget--) { s->failed_pc=0x0c076faau; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&48u)==0)!=0);
goto P_0c076fac;
P_0c076fac: /* original 8b09, guest PC 0x0c076fac */
if(!s->budget--) { s->failed_pc=0x0c076facu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c076fc2; }
goto P_0c076fae;
P_0c076fae: /* original 61f3, guest PC 0x0c076fae */
if(!s->budget--) { s->failed_pc=0x0c076faeu; return 0; }
r[1]=r[15];
goto P_0c076fb0;
P_0c076fb0: /* original 62f3, guest PC 0x0c076fb0 */
if(!s->budget--) { s->failed_pc=0x0c076fb0u; return 0; }
r[2]=r[15];
goto P_0c076fb2;
P_0c076fb2: /* original 7154, guest PC 0x0c076fb2 */
if(!s->budget--) { s->failed_pc=0x0c076fb2u; return 0; }
r[1]+=0x00000054u;
goto P_0c076fb4;
P_0c076fb4: /* original 724c, guest PC 0x0c076fb4 */
if(!s->budget--) { s->failed_pc=0x0c076fb4u; return 0; }
r[2]+=0x0000004cu;
goto P_0c076fb6;
P_0c076fb6: /* original 6012, guest PC 0x0c076fb6 */
if(!s->budget--) { s->failed_pc=0x0c076fb6u; return 0; }
tmp=read(ram,r[1],4);
r[0]=tmp;
goto P_0c076fb8;
P_0c076fb8: /* original 6322, guest PC 0x0c076fb8 */
if(!s->budget--) { s->failed_pc=0x0c076fb8u; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c076fba;
P_0c076fba: /* original c930, guest PC 0x0c076fba */
if(!s->budget--) { s->failed_pc=0x0c076fbau; return 0; }
r[0]&=48u;
goto P_0c076fbc;
P_0c076fbc: /* original 230b, guest PC 0x0c076fbc */
if(!s->budget--) { s->failed_pc=0x0c076fbcu; return 0; }
r[3]|=r[0];
goto P_0c076fbe;
P_0c076fbe: /* original e04c, guest PC 0x0c076fbe */
if(!s->budget--) { s->failed_pc=0x0c076fbeu; return 0; }
r[0]=0x0000004cu;
goto P_0c076fc0;
P_0c076fc0: /* original 0f36, guest PC 0x0c076fc0 */
if(!s->budget--) { s->failed_pc=0x0c076fc0u; return 0; }
write(ram,r[15]+r[0],r[3],4);
goto P_0c076fc2;
P_0c076fc2: /* original 9150, guest PC 0x0c076fc2 */
if(!s->budget--) { s->failed_pc=0x0c076fc2u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077066u,2);
goto P_0c076fc4;
P_0c076fc4: /* original e04c, guest PC 0x0c076fc4 */
if(!s->budget--) { s->failed_pc=0x0c076fc4u; return 0; }
r[0]=0x0000004cu;
goto P_0c076fc6;
P_0c076fc6: /* original 53f5, guest PC 0x0c076fc6 */
if(!s->budget--) { s->failed_pc=0x0c076fc6u; return 0; }
r[3]=read(ram,r[15]+20,4);
goto P_0c076fc8;
P_0c076fc8: /* original 00fc, guest PC 0x0c076fc8 */
if(!s->budget--) { s->failed_pc=0x0c076fc8u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[15]+r[0],1);
goto P_0c076fca;
P_0c076fca: /* original 31ec, guest PC 0x0c076fca */
if(!s->budget--) { s->failed_pc=0x0c076fcau; return 0; }
r[1]+=r[14];
goto P_0c076fcc;
P_0c076fcc: /* original 313c, guest PC 0x0c076fcc */
if(!s->budget--) { s->failed_pc=0x0c076fccu; return 0; }
r[1]+=r[3];
goto P_0c076fce;
P_0c076fce: /* original 8011, guest PC 0x0c076fce */
if(!s->budget--) { s->failed_pc=0x0c076fceu; return 0; }
write(ram,r[1]+1,r[0],1);
goto P_0c076fd0;
P_0c076fd0: /* original 904a, guest PC 0x0c076fd0 */
if(!s->budget--) { s->failed_pc=0x0c076fd0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077068u,2);
goto P_0c076fd2;
P_0c076fd2: /* original d229, guest PC 0x0c076fd2 */
if(!s->budget--) { s->failed_pc=0x0c076fd2u; return 0; }
r[2]=read(ram,0x0c077078u,4);
goto P_0c076fd4;
P_0c076fd4: /* original 03fe, guest PC 0x0c076fd4 */
if(!s->budget--) { s->failed_pc=0x0c076fd4u; return 0; }
r[3]=read(ram,r[15]+r[0],4);
goto P_0c076fd6;
P_0c076fd6: /* original 5131, guest PC 0x0c076fd6 */
if(!s->budget--) { s->failed_pc=0x0c076fd6u; return 0; }
r[1]=read(ram,r[3]+4,4);
goto P_0c076fd8;
P_0c076fd8: /* original 2128, guest PC 0x0c076fd8 */
if(!s->budget--) { s->failed_pc=0x0c076fd8u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[2])==0)!=0);
goto P_0c076fda;
P_0c076fda: /* original 890b, guest PC 0x0c076fda */
if(!s->budget--) { s->failed_pc=0x0c076fdau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c076ff4; }
goto P_0c076fdc;
P_0c076fdc: /* original 50f1, guest PC 0x0c076fdc */
if(!s->budget--) { s->failed_pc=0x0c076fdcu; return 0; }
r[0]=read(ram,r[15]+4,4);
goto P_0c076fde;
P_0c076fde: /* original 61f3, guest PC 0x0c076fde */
if(!s->budget--) { s->failed_pc=0x0c076fdeu; return 0; }
r[1]=r[15];
goto P_0c076fe0;
P_0c076fe0: /* original 7150, guest PC 0x0c076fe0 */
if(!s->budget--) { s->failed_pc=0x0c076fe0u; return 0; }
r[1]+=0x00000050u;
goto P_0c076fe2;
P_0c076fe2: /* original c910, guest PC 0x0c076fe2 */
if(!s->budget--) { s->failed_pc=0x0c076fe2u; return 0; }
r[0]&=16u;
goto P_0c076fe4;
P_0c076fe4: /* original 1f01, guest PC 0x0c076fe4 */
if(!s->budget--) { s->failed_pc=0x0c076fe4u; return 0; }
write(ram,r[15]+4,r[0],4);
goto P_0c076fe6;
P_0c076fe6: /* original e050, guest PC 0x0c076fe6 */
if(!s->budget--) { s->failed_pc=0x0c076fe6u; return 0; }
r[0]=0x00000050u;
goto P_0c076fe8;
P_0c076fe8: /* original 00fe, guest PC 0x0c076fe8 */
if(!s->budget--) { s->failed_pc=0x0c076fe8u; return 0; }
r[0]=read(ram,r[15]+r[0],4);
goto P_0c076fea;
P_0c076fea: /* original c910, guest PC 0x0c076fea */
if(!s->budget--) { s->failed_pc=0x0c076feau; return 0; }
r[0]&=16u;
goto P_0c076fec;
P_0c076fec: /* original 2102, guest PC 0x0c076fec */
if(!s->budget--) { s->failed_pc=0x0c076fecu; return 0; }
write(ram,r[1],r[0],4);
goto P_0c076fee;
P_0c076fee: /* original 50ff, guest PC 0x0c076fee */
if(!s->budget--) { s->failed_pc=0x0c076feeu; return 0; }
r[0]=read(ram,r[15]+60,4);
goto P_0c076ff0;
P_0c076ff0: /* original c910, guest PC 0x0c076ff0 */
if(!s->budget--) { s->failed_pc=0x0c076ff0u; return 0; }
r[0]&=16u;
goto P_0c076ff2;
P_0c076ff2: /* original 1f0f, guest PC 0x0c076ff2 */
if(!s->budget--) { s->failed_pc=0x0c076ff2u; return 0; }
write(ram,r[15]+60,r[0],4);
goto P_0c076ff4;
P_0c076ff4: /* original 52f8, guest PC 0x0c076ff4 */
if(!s->budget--) { s->failed_pc=0x0c076ff4u; return 0; }
r[2]=read(ram,r[15]+32,4);
goto P_0c076ff6;
P_0c076ff6: /* original 7201, guest PC 0x0c076ff6 */
if(!s->budget--) { s->failed_pc=0x0c076ff6u; return 0; }
r[2]+=0x00000001u;
goto P_0c076ff8;
P_0c076ff8: /* original 6023, guest PC 0x0c076ff8 */
if(!s->budget--) { s->failed_pc=0x0c076ff8u; return 0; }
r[0]=r[2];
goto P_0c076ffa;
P_0c076ffa: /* original c93f, guest PC 0x0c076ffa */
if(!s->budget--) { s->failed_pc=0x0c076ffau; return 0; }
r[0]&=63u;
goto P_0c076ffc;
P_0c076ffc: /* original 6303, guest PC 0x0c076ffc */
if(!s->budget--) { s->failed_pc=0x0c076ffcu; return 0; }
r[3]=r[0];
goto P_0c076ffe;
P_0c076ffe: /* original 1f08, guest PC 0x0c076ffe */
if(!s->budget--) { s->failed_pc=0x0c076ffeu; return 0; }
write(ram,r[15]+32,r[0],4);
goto P_0c077000;
P_0c077000: /* original 902f, guest PC 0x0c077000 */
if(!s->budget--) { s->failed_pc=0x0c077000u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077062u,2);
goto P_0c077002;
P_0c077002: /* original 0e34, guest PC 0x0c077002 */
if(!s->budget--) { s->failed_pc=0x0c077002u; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c077004;
P_0c077004: /* original e33f, guest PC 0x0c077004 */
if(!s->budget--) { s->failed_pc=0x0c077004u; return 0; }
r[3]=0x0000003fu;
goto P_0c077006;
P_0c077006: /* original 52f8, guest PC 0x0c077006 */
if(!s->budget--) { s->failed_pc=0x0c077006u; return 0; }
r[2]=read(ram,r[15]+32,4);
goto P_0c077008;
P_0c077008: /* original e058, guest PC 0x0c077008 */
if(!s->budget--) { s->failed_pc=0x0c077008u; return 0; }
r[0]=0x00000058u;
goto P_0c07700a;
P_0c07700a: /* original 7201, guest PC 0x0c07700a */
if(!s->budget--) { s->failed_pc=0x0c07700au; return 0; }
r[2]+=0x00000001u;
goto P_0c07700c;
P_0c07700c: /* original 2239, guest PC 0x0c07700c */
if(!s->budget--) { s->failed_pc=0x0c07700cu; return 0; }
r[2]&=r[3];
goto P_0c07700e;
P_0c07700e: /* original 0f26, guest PC 0x0c07700e */
if(!s->budget--) { s->failed_pc=0x0c07700eu; return 0; }
write(ram,r[15]+r[0],r[2],4);
goto P_0c077010;
P_0c077010: /* original 902b, guest PC 0x0c077010 */
if(!s->budget--) { s->failed_pc=0x0c077010u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07706au,2);
goto P_0c077012;
P_0c077012: /* original 52f8, guest PC 0x0c077012 */
if(!s->budget--) { s->failed_pc=0x0c077012u; return 0; }
r[2]=read(ram,r[15]+32,4);
goto P_0c077014;
P_0c077014: /* original 03ec, guest PC 0x0c077014 */
if(!s->budget--) { s->failed_pc=0x0c077014u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c077016;
P_0c077016: /* original 633c, guest PC 0x0c077016 */
if(!s->budget--) { s->failed_pc=0x0c077016u; return 0; }
r[3]=r[3]&255u;
goto P_0c077018;
P_0c077018: /* original 3320, guest PC 0x0c077018 */
if(!s->budget--) { s->failed_pc=0x0c077018u; return 0; }
r[17]=(r[17]&~1u)|((r[3]==r[2])!=0);
goto P_0c07701a;
P_0c07701a: /* original 8b03, guest PC 0x0c07701a */
if(!s->budget--) { s->failed_pc=0x0c07701au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c077024; }
goto P_0c07701c;
P_0c07701c: /* original e058, guest PC 0x0c07701c */
if(!s->budget--) { s->failed_pc=0x0c07701cu; return 0; }
r[0]=0x00000058u;
goto P_0c07701e;
P_0c07701e: /* original 01fc, guest PC 0x0c07701e */
if(!s->budget--) { s->failed_pc=0x0c07701eu; return 0; }
r[1]=(uint32_t)(int32_t)(int8_t)read(ram,r[15]+r[0],1);
goto P_0c077020;
P_0c077020: /* original 9023, guest PC 0x0c077020 */
if(!s->budget--) { s->failed_pc=0x0c077020u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07706au,2);
goto P_0c077022;
P_0c077022: /* original 0e14, guest PC 0x0c077022 */
if(!s->budget--) { s->failed_pc=0x0c077022u; return 0; }
write(ram,r[14]+r[0],r[1],1);
goto P_0c077024;
P_0c077024: /* original 9022, guest PC 0x0c077024 */
if(!s->budget--) { s->failed_pc=0x0c077024u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07706cu,2);
goto P_0c077026;
P_0c077026: /* original 52f8, guest PC 0x0c077026 */
if(!s->budget--) { s->failed_pc=0x0c077026u; return 0; }
r[2]=read(ram,r[15]+32,4);
goto P_0c077028;
P_0c077028: /* original 03ec, guest PC 0x0c077028 */
if(!s->budget--) { s->failed_pc=0x0c077028u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c07702a;
P_0c07702a: /* original 633c, guest PC 0x0c07702a */
if(!s->budget--) { s->failed_pc=0x0c07702au; return 0; }
r[3]=r[3]&255u;
goto P_0c07702c;
P_0c07702c: /* original 3320, guest PC 0x0c07702c */
if(!s->budget--) { s->failed_pc=0x0c07702cu; return 0; }
r[17]=(r[17]&~1u)|((r[3]==r[2])!=0);
goto P_0c07702e;
P_0c07702e: /* original 8b03, guest PC 0x0c07702e */
if(!s->budget--) { s->failed_pc=0x0c07702eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c077038; }
goto P_0c077030;
P_0c077030: /* original e058, guest PC 0x0c077030 */
if(!s->budget--) { s->failed_pc=0x0c077030u; return 0; }
r[0]=0x00000058u;
goto P_0c077032;
P_0c077032: /* original 01fc, guest PC 0x0c077032 */
if(!s->budget--) { s->failed_pc=0x0c077032u; return 0; }
r[1]=(uint32_t)(int32_t)(int8_t)read(ram,r[15]+r[0],1);
goto P_0c077034;
P_0c077034: /* original 901a, guest PC 0x0c077034 */
if(!s->budget--) { s->failed_pc=0x0c077034u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07706cu,2);
goto P_0c077036;
P_0c077036: /* original 0e14, guest PC 0x0c077036 */
if(!s->budget--) { s->failed_pc=0x0c077036u; return 0; }
write(ram,r[14]+r[0],r[1],1);
goto P_0c077038;
P_0c077038: /* original 9019, guest PC 0x0c077038 */
if(!s->budget--) { s->failed_pc=0x0c077038u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07706eu,2);
goto P_0c07703a;
P_0c07703a: /* original 52f8, guest PC 0x0c07703a */
if(!s->budget--) { s->failed_pc=0x0c07703au; return 0; }
r[2]=read(ram,r[15]+32,4);
goto P_0c07703c;
P_0c07703c: /* original 03ec, guest PC 0x0c07703c */
if(!s->budget--) { s->failed_pc=0x0c07703cu; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c07703e;
P_0c07703e: /* original 633c, guest PC 0x0c07703e */
if(!s->budget--) { s->failed_pc=0x0c07703eu; return 0; }
r[3]=r[3]&255u;
goto P_0c077040;
P_0c077040: /* original 3320, guest PC 0x0c077040 */
if(!s->budget--) { s->failed_pc=0x0c077040u; return 0; }
r[17]=(r[17]&~1u)|((r[3]==r[2])!=0);
goto P_0c077042;
P_0c077042: /* original 8b03, guest PC 0x0c077042 */
if(!s->budget--) { s->failed_pc=0x0c077042u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07704c; }
goto P_0c077044;
P_0c077044: /* original e058, guest PC 0x0c077044 */
if(!s->budget--) { s->failed_pc=0x0c077044u; return 0; }
r[0]=0x00000058u;
goto P_0c077046;
P_0c077046: /* original 01fc, guest PC 0x0c077046 */
if(!s->budget--) { s->failed_pc=0x0c077046u; return 0; }
r[1]=(uint32_t)(int32_t)(int8_t)read(ram,r[15]+r[0],1);
goto P_0c077048;
P_0c077048: /* original 9011, guest PC 0x0c077048 */
if(!s->budget--) { s->failed_pc=0x0c077048u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07706eu,2);
goto P_0c07704a;
P_0c07704a: /* original 0e14, guest PC 0x0c07704a */
if(!s->budget--) { s->failed_pc=0x0c07704au; return 0; }
write(ram,r[14]+r[0],r[1],1);
goto P_0c07704c;
P_0c07704c: /* original e050, guest PC 0x0c07704c */
if(!s->budget--) { s->failed_pc=0x0c07704cu; return 0; }
r[0]=0x00000050u;
goto P_0c07704e;
P_0c07704e: /* original 03ee, guest PC 0x0c07704e */
if(!s->budget--) { s->failed_pc=0x0c07704eu; return 0; }
r[3]=read(ram,r[14]+r[0],4);
goto P_0c077050;
P_0c077050: /* original e048, guest PC 0x0c077050 */
if(!s->budget--) { s->failed_pc=0x0c077050u; return 0; }
r[0]=0x00000048u;
goto P_0c077052;
P_0c077052: /* original 0f36, guest PC 0x0c077052 */
if(!s->budget--) { s->failed_pc=0x0c077052u; return 0; }
write(ram,r[15]+r[0],r[3],4);
goto P_0c077054;
P_0c077054: /* original 900c, guest PC 0x0c077054 */
if(!s->budget--) { s->failed_pc=0x0c077054u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077070u,2);
goto P_0c077056;
P_0c077056: /* original d309, guest PC 0x0c077056 */
if(!s->budget--) { s->failed_pc=0x0c077056u; return 0; }
r[3]=read(ram,0x0c07707cu,4);
goto P_0c077058;
P_0c077058: /* original 02fe, guest PC 0x0c077058 */
if(!s->budget--) { s->failed_pc=0x0c077058u; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c07705a;
P_0c07705a: /* original 2238, guest PC 0x0c07705a */
if(!s->budget--) { s->failed_pc=0x0c07705au; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c07705c;
P_0c07705c: /* original a010, guest PC 0x0c07705c */
if(!s->budget--) { s->failed_pc=0x0c07705cu; return 0; }
goto P_0c077080;
P_0c07705e: /* original 0009, guest PC 0x0c07705e */
if(!s->budget--) { s->failed_pc=0x0c07705eu; return 0; }
return vf3_matrix_family(0x0c077060u,s,ram);
P_0c077080: /* original 8904, guest PC 0x0c077080 */
if(!s->budget--) { s->failed_pc=0x0c077080u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07708c; }
goto P_0c077082;
P_0c077082: /* original 9286, guest PC 0x0c077082 */
if(!s->budget--) { s->failed_pc=0x0c077082u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077192u,2);
goto P_0c077084;
P_0c077084: /* original e044, guest PC 0x0c077084 */
if(!s->budget--) { s->failed_pc=0x0c077084u; return 0; }
r[0]=0x00000044u;
goto P_0c077086;
P_0c077086: /* original 0f26, guest PC 0x0c077086 */
if(!s->budget--) { s->failed_pc=0x0c077086u; return 0; }
write(ram,r[15]+r[0],r[2],4);
goto P_0c077088;
P_0c077088: /* original a004, guest PC 0x0c077088 */
if(!s->budget--) { s->failed_pc=0x0c077088u; return 0; }
r[1]=0x00000040u;
goto P_0c077094;
P_0c07708a: /* original e140, guest PC 0x0c07708a */
if(!s->budget--) { s->failed_pc=0x0c07708au; return 0; }
r[1]=0x00000040u;
goto P_0c07708c;
P_0c07708c: /* original e044, guest PC 0x0c07708c */
if(!s->budget--) { s->failed_pc=0x0c07708cu; return 0; }
r[0]=0x00000044u;
goto P_0c07708e;
P_0c07708e: /* original e240, guest PC 0x0c07708e */
if(!s->budget--) { s->failed_pc=0x0c07708eu; return 0; }
r[2]=0x00000040u;
goto P_0c077090;
P_0c077090: /* original 0f26, guest PC 0x0c077090 */
if(!s->budget--) { s->failed_pc=0x0c077090u; return 0; }
write(ram,r[15]+r[0],r[2],4);
goto P_0c077092;
P_0c077092: /* original 917e, guest PC 0x0c077092 */
if(!s->budget--) { s->failed_pc=0x0c077092u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077192u,2);
goto P_0c077094;
P_0c077094: /* original e040, guest PC 0x0c077094 */
if(!s->budget--) { s->failed_pc=0x0c077094u; return 0; }
r[0]=0x00000040u;
goto P_0c077096;
P_0c077096: /* original 0f16, guest PC 0x0c077096 */
if(!s->budget--) { s->failed_pc=0x0c077096u; return 0; }
write(ram,r[15]+r[0],r[1],4);
goto P_0c077098;
P_0c077098: /* original 907b, guest PC 0x0c077098 */
if(!s->budget--) { s->failed_pc=0x0c077098u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077192u,2);
goto P_0c07709a;
P_0c07709a: /* original d33f, guest PC 0x0c07709a */
if(!s->budget--) { s->failed_pc=0x0c07709au; return 0; }
r[3]=read(ram,0x0c077198u,4);
goto P_0c07709c;
P_0c07709c: /* original 02fe, guest PC 0x0c07709c */
if(!s->budget--) { s->failed_pc=0x0c07709cu; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c07709e;
P_0c07709e: /* original 2238, guest PC 0x0c07709e */
if(!s->budget--) { s->failed_pc=0x0c07709eu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0770a0;
P_0c0770a0: /* original 890b, guest PC 0x0c0770a0 */
if(!s->budget--) { s->failed_pc=0x0c0770a0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0770ba; }
goto P_0c0770a2;
P_0c0770a2: /* original 9176, guest PC 0x0c0770a2 */
if(!s->budget--) { s->failed_pc=0x0c0770a2u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077192u,2);
goto P_0c0770a4;
P_0c0770a4: /* original 31fc, guest PC 0x0c0770a4 */
if(!s->budget--) { s->failed_pc=0x0c0770a4u; return 0; }
r[1]+=r[15];
goto P_0c0770a6;
P_0c0770a6: /* original 6012, guest PC 0x0c0770a6 */
if(!s->budget--) { s->failed_pc=0x0c0770a6u; return 0; }
tmp=read(ram,r[1],4);
r[0]=tmp;
goto P_0c0770a8;
P_0c0770a8: /* original c880, guest PC 0x0c0770a8 */
if(!s->budget--) { s->failed_pc=0x0c0770a8u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&128u)==0)!=0);
goto P_0c0770aa;
P_0c0770aa: /* original 8906, guest PC 0x0c0770aa */
if(!s->budget--) { s->failed_pc=0x0c0770aau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0770ba; }
goto P_0c0770ac;
P_0c0770ac: /* original e050, guest PC 0x0c0770ac */
if(!s->budget--) { s->failed_pc=0x0c0770acu; return 0; }
r[0]=0x00000050u;
goto P_0c0770ae;
P_0c0770ae: /* original 02fe, guest PC 0x0c0770ae */
if(!s->budget--) { s->failed_pc=0x0c0770aeu; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c0770b0;
P_0c0770b0: /* original 2228, guest PC 0x0c0770b0 */
if(!s->budget--) { s->failed_pc=0x0c0770b0u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c0770b2;
P_0c0770b2: /* original 8902, guest PC 0x0c0770b2 */
if(!s->budget--) { s->failed_pc=0x0c0770b2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0770ba; }
goto P_0c0770b4;
P_0c0770b4: /* original d339, guest PC 0x0c0770b4 */
if(!s->budget--) { s->failed_pc=0x0c0770b4u; return 0; }
r[3]=read(ram,0x0c07719cu,4);
goto P_0c0770b6;
P_0c0770b6: /* original a11e, guest PC 0x0c0770b6 */
if(!s->budget--) { s->failed_pc=0x0c0770b6u; return 0; }
goto P_0c0772f6;
P_0c0770b8: /* original 0009, guest PC 0x0c0770b8 */
if(!s->budget--) { s->failed_pc=0x0c0770b8u; return 0; }
goto P_0c0770ba;
P_0c0770ba: /* original 51f1, guest PC 0x0c0770ba */
if(!s->budget--) { s->failed_pc=0x0c0770bau; return 0; }
r[1]=read(ram,r[15]+4,4);
goto P_0c0770bc;
P_0c0770bc: /* original 65e3, guest PC 0x0c0770bc */
if(!s->budget--) { s->failed_pc=0x0c0770bcu; return 0; }
r[5]=r[14];
goto P_0c0770be;
P_0c0770be: /* original 66d3, guest PC 0x0c0770be */
if(!s->budget--) { s->failed_pc=0x0c0770beu; return 0; }
r[6]=r[13];
goto P_0c0770c0;
P_0c0770c0: /* original e700, guest PC 0x0c0770c0 */
if(!s->budget--) { s->failed_pc=0x0c0770c0u; return 0; }
r[7]=0x00000000u;
goto P_0c0770c2;
P_0c0770c2: /* original 2f16, guest PC 0x0c0770c2 */
if(!s->budget--) { s->failed_pc=0x0c0770c2u; return 0; }
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0770c4;
P_0c0770c4: /* original 9066, guest PC 0x0c0770c4 */
if(!s->budget--) { s->failed_pc=0x0c0770c4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077194u,2);
goto P_0c0770c6;
P_0c0770c6: /* original 03fe, guest PC 0x0c0770c6 */
if(!s->budget--) { s->failed_pc=0x0c0770c6u; return 0; }
r[3]=read(ram,r[15]+r[0],4);
goto P_0c0770c8;
P_0c0770c8: /* original e058, guest PC 0x0c0770c8 */
if(!s->budget--) { s->failed_pc=0x0c0770c8u; return 0; }
r[0]=0x00000058u;
goto P_0c0770ca;
P_0c0770ca: /* original 2f36, guest PC 0x0c0770ca */
if(!s->budget--) { s->failed_pc=0x0c0770cau; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0770cc;
P_0c0770cc: /* original 02fe, guest PC 0x0c0770cc */
if(!s->budget--) { s->failed_pc=0x0c0770ccu; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c0770ce;
P_0c0770ce: /* original 2f26, guest PC 0x0c0770ce */
if(!s->budget--) { s->failed_pc=0x0c0770ceu; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0770d0;
P_0c0770d0: /* original d333, guest PC 0x0c0770d0 */
if(!s->budget--) { s->failed_pc=0x0c0770d0u; return 0; }
r[3]=read(ram,0x0c0771a0u,4);
goto P_0c0770d2;
P_0c0770d2: /* original 430b, guest PC 0x0c0770d2 */
if(!s->budget--) { s->failed_pc=0x0c0770d2u; return 0; }
target=r[3];
r[16]=0x8c0770d6u;
r[4]=r[12];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0770d6u) { target=s->pc; goto dispatch; }
goto P_0c0770d6;
P_0c0770d4: /* original 64c3, guest PC 0x0c0770d4 */
if(!s->budget--) { s->failed_pc=0x0c0770d4u; return 0; }
r[4]=r[12];
goto P_0c0770d6;
P_0c0770d6: /* original 7f0c, guest PC 0x0c0770d6 */
if(!s->budget--) { s->failed_pc=0x0c0770d6u; return 0; }
r[15]+=0x0000000cu;
goto P_0c0770d8;
P_0c0770d8: /* original 63e3, guest PC 0x0c0770d8 */
if(!s->budget--) { s->failed_pc=0x0c0770d8u; return 0; }
r[3]=r[14];
goto P_0c0770da;
P_0c0770da: /* original 61f3, guest PC 0x0c0770da */
if(!s->budget--) { s->failed_pc=0x0c0770dau; return 0; }
r[1]=r[15];
goto P_0c0770dc;
P_0c0770dc: /* original 7150, guest PC 0x0c0770dc */
if(!s->budget--) { s->failed_pc=0x0c0770dcu; return 0; }
r[1]+=0x00000050u;
goto P_0c0770de;
P_0c0770de: /* original 7338, guest PC 0x0c0770de */
if(!s->budget--) { s->failed_pc=0x0c0770deu; return 0; }
r[3]+=0x00000038u;
goto P_0c0770e0;
P_0c0770e0: /* original 2102, guest PC 0x0c0770e0 */
if(!s->budget--) { s->failed_pc=0x0c0770e0u; return 0; }
write(ram,r[1],r[0],4);
goto P_0c0770e2;
P_0c0770e2: /* original 8433, guest PC 0x0c0770e2 */
if(!s->budget--) { s->failed_pc=0x0c0770e2u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[3]+3,1);
goto P_0c0770e4;
P_0c0770e4: /* original 61f3, guest PC 0x0c0770e4 */
if(!s->budget--) { s->failed_pc=0x0c0770e4u; return 0; }
r[1]=r[15];
goto P_0c0770e6;
P_0c0770e6: /* original 7168, guest PC 0x0c0770e6 */
if(!s->budget--) { s->failed_pc=0x0c0770e6u; return 0; }
r[1]+=0x00000068u;
goto P_0c0770e8;
P_0c0770e8: /* original 600c, guest PC 0x0c0770e8 */
if(!s->budget--) { s->failed_pc=0x0c0770e8u; return 0; }
r[0]=r[0]&255u;
goto P_0c0770ea;
P_0c0770ea: /* original 2102, guest PC 0x0c0770ea */
if(!s->budget--) { s->failed_pc=0x0c0770eau; return 0; }
write(ram,r[1],r[0],4);
goto P_0c0770ec;
P_0c0770ec: /* original 9053, guest PC 0x0c0770ec */
if(!s->budget--) { s->failed_pc=0x0c0770ecu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077196u,2);
goto P_0c0770ee;
P_0c0770ee: /* original 03ee, guest PC 0x0c0770ee */
if(!s->budget--) { s->failed_pc=0x0c0770eeu; return 0; }
r[3]=read(ram,r[14]+r[0],4);
goto P_0c0770f0;
P_0c0770f0: /* original e064, guest PC 0x0c0770f0 */
if(!s->budget--) { s->failed_pc=0x0c0770f0u; return 0; }
r[0]=0x00000064u;
goto P_0c0770f2;
P_0c0770f2: /* original 0f36, guest PC 0x0c0770f2 */
if(!s->budget--) { s->failed_pc=0x0c0770f2u; return 0; }
write(ram,r[15]+r[0],r[3],4);
goto P_0c0770f4;
P_0c0770f4: /* original e062, guest PC 0x0c0770f4 */
if(!s->budget--) { s->failed_pc=0x0c0770f4u; return 0; }
r[0]=0x00000062u;
goto P_0c0770f6;
P_0c0770f6: /* original 02ec, guest PC 0x0c0770f6 */
if(!s->budget--) { s->failed_pc=0x0c0770f6u; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0770f8;
P_0c0770f8: /* original e060, guest PC 0x0c0770f8 */
if(!s->budget--) { s->failed_pc=0x0c0770f8u; return 0; }
r[0]=0x00000060u;
goto P_0c0770fa;
P_0c0770fa: /* original 622c, guest PC 0x0c0770fa */
if(!s->budget--) { s->failed_pc=0x0c0770fau; return 0; }
r[2]=r[2]&255u;
goto P_0c0770fc;
P_0c0770fc: /* original 0f26, guest PC 0x0c0770fc */
if(!s->budget--) { s->failed_pc=0x0c0770fcu; return 0; }
write(ram,r[15]+r[0],r[2],4);
goto P_0c0770fe;
P_0c0770fe: /* original e068, guest PC 0x0c0770fe */
if(!s->budget--) { s->failed_pc=0x0c0770feu; return 0; }
r[0]=0x00000068u;
goto P_0c077100;
P_0c077100: /* original 00fe, guest PC 0x0c077100 */
if(!s->budget--) { s->failed_pc=0x0c077100u; return 0; }
r[0]=read(ram,r[15]+r[0],4);
goto P_0c077102;
P_0c077102: /* original 880b, guest PC 0x0c077102 */
if(!s->budget--) { s->failed_pc=0x0c077102u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000bu)!=0);
goto P_0c077104;
P_0c077104: /* original 8901, guest PC 0x0c077104 */
if(!s->budget--) { s->failed_pc=0x0c077104u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07710a; }
goto P_0c077106;
P_0c077106: /* original a0f8, guest PC 0x0c077106 */
if(!s->budget--) { s->failed_pc=0x0c077106u; return 0; }
goto P_0c0772fa;
P_0c077108: /* original 0009, guest PC 0x0c077108 */
if(!s->budget--) { s->failed_pc=0x0c077108u; return 0; }
goto P_0c07710a;
P_0c07710a: /* original e064, guest PC 0x0c07710a */
if(!s->budget--) { s->failed_pc=0x0c07710au; return 0; }
r[0]=0x00000064u;
goto P_0c07710c;
P_0c07710c: /* original 01fe, guest PC 0x0c07710c */
if(!s->budget--) { s->failed_pc=0x0c07710cu; return 0; }
r[1]=read(ram,r[15]+r[0],4);
goto P_0c07710e;
P_0c07710e: /* original 2118, guest PC 0x0c07710e */
if(!s->budget--) { s->failed_pc=0x0c07710eu; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[1])==0)!=0);
goto P_0c077110;
P_0c077110: /* original 8901, guest PC 0x0c077110 */
if(!s->budget--) { s->failed_pc=0x0c077110u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c077116; }
goto P_0c077112;
P_0c077112: /* original a0f2, guest PC 0x0c077112 */
if(!s->budget--) { s->failed_pc=0x0c077112u; return 0; }
goto P_0c0772fa;
P_0c077114: /* original 0009, guest PC 0x0c077114 */
if(!s->budget--) { s->failed_pc=0x0c077114u; return 0; }
goto P_0c077116;
P_0c077116: /* original e060, guest PC 0x0c077116 */
if(!s->budget--) { s->failed_pc=0x0c077116u; return 0; }
r[0]=0x00000060u;
goto P_0c077118;
P_0c077118: /* original 00fe, guest PC 0x0c077118 */
if(!s->budget--) { s->failed_pc=0x0c077118u; return 0; }
r[0]=read(ram,r[15]+r[0],4);
goto P_0c07711a;
P_0c07711a: /* original 8804, guest PC 0x0c07711a */
if(!s->budget--) { s->failed_pc=0x0c07711au; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000004u)!=0);
goto P_0c07711c;
P_0c07711c: /* original 8b01, guest PC 0x0c07711c */
if(!s->budget--) { s->failed_pc=0x0c07711cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c077122; }
goto P_0c07711e;
P_0c07711e: /* original a0bf, guest PC 0x0c07711e */
if(!s->budget--) { s->failed_pc=0x0c07711eu; return 0; }
goto P_0c0772a0;
P_0c077120: /* original 0009, guest PC 0x0c077120 */
if(!s->budget--) { s->failed_pc=0x0c077120u; return 0; }
goto P_0c077122;
P_0c077122: /* original e060, guest PC 0x0c077122 */
if(!s->budget--) { s->failed_pc=0x0c077122u; return 0; }
r[0]=0x00000060u;
goto P_0c077124;
P_0c077124: /* original 00fe, guest PC 0x0c077124 */
if(!s->budget--) { s->failed_pc=0x0c077124u; return 0; }
r[0]=read(ram,r[15]+r[0],4);
goto P_0c077126;
P_0c077126: /* original 8805, guest PC 0x0c077126 */
if(!s->budget--) { s->failed_pc=0x0c077126u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000005u)!=0);
goto P_0c077128;
P_0c077128: /* original 8b01, guest PC 0x0c077128 */
if(!s->budget--) { s->failed_pc=0x0c077128u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07712e; }
goto P_0c07712a;
P_0c07712a: /* original a0b9, guest PC 0x0c07712a */
if(!s->budget--) { s->failed_pc=0x0c07712au; return 0; }
goto P_0c0772a0;
P_0c07712c: /* original 0009, guest PC 0x0c07712c */
if(!s->budget--) { s->failed_pc=0x0c07712cu; return 0; }
goto P_0c07712e;
P_0c07712e: /* original e060, guest PC 0x0c07712e */
if(!s->budget--) { s->failed_pc=0x0c07712eu; return 0; }
r[0]=0x00000060u;
goto P_0c077130;
P_0c077130: /* original 02fe, guest PC 0x0c077130 */
if(!s->budget--) { s->failed_pc=0x0c077130u; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c077132;
P_0c077132: /* original e305, guest PC 0x0c077132 */
if(!s->budget--) { s->failed_pc=0x0c077132u; return 0; }
r[3]=0x00000005u;
goto P_0c077134;
P_0c077134: /* original 3236, guest PC 0x0c077134 */
if(!s->budget--) { s->failed_pc=0x0c077134u; return 0; }
r[17]=(r[17]&~1u)|((r[2]>r[3])!=0);
goto P_0c077136;
P_0c077136: /* original 8b01, guest PC 0x0c077136 */
if(!s->budget--) { s->failed_pc=0x0c077136u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07713c; }
goto P_0c077138;
P_0c077138: /* original a67e, guest PC 0x0c077138 */
if(!s->budget--) { s->failed_pc=0x0c077138u; return 0; }
goto P_0c077e38;
P_0c07713a: /* original 0009, guest PC 0x0c07713a */
if(!s->budget--) { s->failed_pc=0x0c07713au; return 0; }
goto P_0c07713c;
P_0c07713c: /* original e050, guest PC 0x0c07713c */
if(!s->budget--) { s->failed_pc=0x0c07713cu; return 0; }
r[0]=0x00000050u;
goto P_0c07713e;
P_0c07713e: /* original 01fe, guest PC 0x0c07713e */
if(!s->budget--) { s->failed_pc=0x0c07713eu; return 0; }
r[1]=read(ram,r[15]+r[0],4);
goto P_0c077140;
P_0c077140: /* original 6313, guest PC 0x0c077140 */
if(!s->budget--) { s->failed_pc=0x0c077140u; return 0; }
r[3]=r[1];
goto P_0c077142;
P_0c077142: /* original 2338, guest PC 0x0c077142 */
if(!s->budget--) { s->failed_pc=0x0c077142u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c077144;
P_0c077144: /* original 8d02, guest PC 0x0c077144 */
if(!s->budget--) { s->failed_pc=0x0c077144u; return 0; }
cond=r[17]&1u;
write(ram,r[15]+48,r[1],4);
if(cond) { goto P_0c07714c; }
goto P_0c077148;
P_0c077146: /* original 1f1c, guest PC 0x0c077146 */
if(!s->budget--) { s->failed_pc=0x0c077146u; return 0; }
write(ram,r[15]+48,r[1],4);
goto P_0c077148;
P_0c077148: /* original e301, guest PC 0x0c077148 */
if(!s->budget--) { s->failed_pc=0x0c077148u; return 0; }
r[3]=0x00000001u;
goto P_0c07714a;
P_0c07714a: /* original 1f3c, guest PC 0x0c07714a */
if(!s->budget--) { s->failed_pc=0x0c07714au; return 0; }
write(ram,r[15]+48,r[3],4);
goto P_0c07714c;
P_0c07714c: /* original 61f3, guest PC 0x0c07714c */
if(!s->budget--) { s->failed_pc=0x0c07714cu; return 0; }
r[1]=r[15];
goto P_0c07714e;
P_0c07714e: /* original 7150, guest PC 0x0c07714e */
if(!s->budget--) { s->failed_pc=0x0c07714eu; return 0; }
r[1]+=0x00000050u;
goto P_0c077150;
P_0c077150: /* original d314, guest PC 0x0c077150 */
if(!s->budget--) { s->failed_pc=0x0c077150u; return 0; }
r[3]=read(ram,0x0c0771a4u,4);
goto P_0c077152;
P_0c077152: /* original 52fc, guest PC 0x0c077152 */
if(!s->budget--) { s->failed_pc=0x0c077152u; return 0; }
r[2]=read(ram,r[15]+48,4);
goto P_0c077154;
P_0c077154: /* original 323c, guest PC 0x0c077154 */
if(!s->budget--) { s->failed_pc=0x0c077154u; return 0; }
r[2]+=r[3];
goto P_0c077156;
P_0c077156: /* original 1f2e, guest PC 0x0c077156 */
if(!s->budget--) { s->failed_pc=0x0c077156u; return 0; }
write(ram,r[15]+56,r[2],4);
goto P_0c077158;
P_0c077158: /* original 6012, guest PC 0x0c077158 */
if(!s->budget--) { s->failed_pc=0x0c077158u; return 0; }
tmp=read(ram,r[1],4);
r[0]=tmp;
goto P_0c07715a;
P_0c07715a: /* original c802, guest PC 0x0c07715a */
if(!s->budget--) { s->failed_pc=0x0c07715au; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&2u)==0)!=0);
goto P_0c07715c;
P_0c07715c: /* original 8910, guest PC 0x0c07715c */
if(!s->budget--) { s->failed_pc=0x0c07715cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c077180; }
goto P_0c07715e;
P_0c07715e: /* original e06c, guest PC 0x0c07715e */
if(!s->budget--) { s->failed_pc=0x0c07715eu; return 0; }
r[0]=0x0000006cu;
goto P_0c077160;
P_0c077160: /* original e11e, guest PC 0x0c077160 */
if(!s->budget--) { s->failed_pc=0x0c077160u; return 0; }
r[1]=0x0000001eu;
goto P_0c077162;
P_0c077162: /* original 0f16, guest PC 0x0c077162 */
if(!s->budget--) { s->failed_pc=0x0c077162u; return 0; }
write(ram,r[15]+r[0],r[1],4);
goto P_0c077164;
P_0c077164: /* original 50f1, guest PC 0x0c077164 */
if(!s->budget--) { s->failed_pc=0x0c077164u; return 0; }
r[0]=read(ram,r[15]+4,4);
goto P_0c077166;
P_0c077166: /* original c810, guest PC 0x0c077166 */
if(!s->budget--) { s->failed_pc=0x0c077166u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&16u)==0)!=0);
goto P_0c077168;
P_0c077168: /* original 8902, guest PC 0x0c077168 */
if(!s->budget--) { s->failed_pc=0x0c077168u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c077170; }
goto P_0c07716a;
P_0c07716a: /* original e06c, guest PC 0x0c07716a */
if(!s->budget--) { s->failed_pc=0x0c07716au; return 0; }
r[0]=0x0000006cu;
goto P_0c07716c;
P_0c07716c: /* original e11d, guest PC 0x0c07716c */
if(!s->budget--) { s->failed_pc=0x0c07716cu; return 0; }
r[1]=0x0000001du;
goto P_0c07716e;
P_0c07716e: /* original 0f16, guest PC 0x0c07716e */
if(!s->budget--) { s->failed_pc=0x0c07716eu; return 0; }
write(ram,r[15]+r[0],r[1],4);
goto P_0c077170;
P_0c077170: /* original e06c, guest PC 0x0c077170 */
if(!s->budget--) { s->failed_pc=0x0c077170u; return 0; }
r[0]=0x0000006cu;
goto P_0c077172;
P_0c077172: /* original d209, guest PC 0x0c077172 */
if(!s->budget--) { s->failed_pc=0x0c077172u; return 0; }
r[2]=read(ram,0x0c077198u,4);
goto P_0c077174;
P_0c077174: /* original 03fe, guest PC 0x0c077174 */
if(!s->budget--) { s->failed_pc=0x0c077174u; return 0; }
r[3]=read(ram,r[15]+r[0],4);
goto P_0c077176;
P_0c077176: /* original 51fe, guest PC 0x0c077176 */
if(!s->budget--) { s->failed_pc=0x0c077176u; return 0; }
r[1]=read(ram,r[15]+56,4);
goto P_0c077178;
P_0c077178: /* original 633b, guest PC 0x0c077178 */
if(!s->budget--) { s->failed_pc=0x0c077178u; return 0; }
r[3]=0u-r[3];
goto P_0c07717a;
P_0c07717a: /* original 423d, guest PC 0x0c07717a */
if(!s->budget--) { s->failed_pc=0x0c07717au; return 0; }
r[2]=(r[3]&0x80000000u)?((r[3]&31u)?r[2]>>((-r[3])&31u):0):r[2]<<(r[3]&31u);
goto P_0c07717c;
P_0c07717c: /* original 212b, guest PC 0x0c07717c */
if(!s->budget--) { s->failed_pc=0x0c07717cu; return 0; }
r[1]|=r[2];
goto P_0c07717e;
P_0c07717e: /* original 1f1e, guest PC 0x0c07717e */
if(!s->budget--) { s->failed_pc=0x0c07717eu; return 0; }
write(ram,r[15]+56,r[1],4);
goto P_0c077180;
P_0c077180: /* original 62f3, guest PC 0x0c077180 */
if(!s->budget--) { s->failed_pc=0x0c077180u; return 0; }
r[2]=r[15];
goto P_0c077182;
P_0c077182: /* original 7250, guest PC 0x0c077182 */
if(!s->budget--) { s->failed_pc=0x0c077182u; return 0; }
r[2]+=0x00000050u;
goto P_0c077184;
P_0c077184: /* original 6022, guest PC 0x0c077184 */
if(!s->budget--) { s->failed_pc=0x0c077184u; return 0; }
tmp=read(ram,r[2],4);
r[0]=tmp;
goto P_0c077186;
P_0c077186: /* original c808, guest PC 0x0c077186 */
if(!s->budget--) { s->failed_pc=0x0c077186u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&8u)==0)!=0);
goto P_0c077188;
P_0c077188: /* original 8910, guest PC 0x0c077188 */
if(!s->budget--) { s->failed_pc=0x0c077188u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0771ac; }
goto P_0c07718a;
P_0c07718a: /* original 51fc, guest PC 0x0c07718a */
if(!s->budget--) { s->failed_pc=0x0c07718au; return 0; }
r[1]=read(ram,r[15]+48,4);
goto P_0c07718c;
P_0c07718c: /* original d306, guest PC 0x0c07718c */
if(!s->budget--) { s->failed_pc=0x0c07718cu; return 0; }
r[3]=read(ram,0x0c0771a8u,4);
goto P_0c07718e;
P_0c07718e: /* original a079, guest PC 0x0c07718e */
if(!s->budget--) { s->failed_pc=0x0c07718eu; return 0; }
r[1]+=r[3];
goto P_0c077284;
P_0c077190: /* original 313c, guest PC 0x0c077190 */
if(!s->budget--) { s->failed_pc=0x0c077190u; return 0; }
r[1]+=r[3];
return vf3_matrix_family(0x0c077192u,s,ram);
P_0c0771ac: /* original 62f3, guest PC 0x0c0771ac */
if(!s->budget--) { s->failed_pc=0x0c0771acu; return 0; }
r[2]=r[15];
goto P_0c0771ae;
P_0c0771ae: /* original 7250, guest PC 0x0c0771ae */
if(!s->budget--) { s->failed_pc=0x0c0771aeu; return 0; }
r[2]+=0x00000050u;
goto P_0c0771b0;
P_0c0771b0: /* original 6022, guest PC 0x0c0771b0 */
if(!s->budget--) { s->failed_pc=0x0c0771b0u; return 0; }
tmp=read(ram,r[2],4);
r[0]=tmp;
goto P_0c0771b2;
P_0c0771b2: /* original c804, guest PC 0x0c0771b2 */
if(!s->budget--) { s->failed_pc=0x0c0771b2u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&4u)==0)!=0);
goto P_0c0771b4;
P_0c0771b4: /* original 892b, guest PC 0x0c0771b4 */
if(!s->budget--) { s->failed_pc=0x0c0771b4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07720e; }
goto P_0c0771b6;
P_0c0771b6: /* original 50fe, guest PC 0x0c0771b6 */
if(!s->budget--) { s->failed_pc=0x0c0771b6u; return 0; }
r[0]=read(ram,r[15]+56,4);
goto P_0c0771b8;
P_0c0771b8: /* original cb40, guest PC 0x0c0771b8 */
if(!s->budget--) { s->failed_pc=0x0c0771b8u; return 0; }
r[0]|=64u;
goto P_0c0771ba;
P_0c0771ba: /* original 1f0e, guest PC 0x0c0771ba */
if(!s->budget--) { s->failed_pc=0x0c0771bau; return 0; }
write(ram,r[15]+56,r[0],4);
goto P_0c0771bc;
P_0c0771bc: /* original 50f1, guest PC 0x0c0771bc */
if(!s->budget--) { s->failed_pc=0x0c0771bcu; return 0; }
r[0]=read(ram,r[15]+4,4);
goto P_0c0771be;
P_0c0771be: /* original c9f0, guest PC 0x0c0771be */
if(!s->budget--) { s->failed_pc=0x0c0771beu; return 0; }
r[0]&=240u;
goto P_0c0771c0;
P_0c0771c0: /* original 81f5, guest PC 0x0c0771c0 */
if(!s->budget--) { s->failed_pc=0x0c0771c0u; return 0; }
write(ram,r[15]+10,r[0],2);
goto P_0c0771c2;
P_0c0771c2: /* original 600d, guest PC 0x0c0771c2 */
if(!s->budget--) { s->failed_pc=0x0c0771c2u; return 0; }
r[0]=r[0]&65535u;
goto P_0c0771c4;
P_0c0771c4: /* original 2008, guest PC 0x0c0771c4 */
if(!s->budget--) { s->failed_pc=0x0c0771c4u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c0771c6;
P_0c0771c6: /* original 895e, guest PC 0x0c0771c6 */
if(!s->budget--) { s->failed_pc=0x0c0771c6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c077286; }
goto P_0c0771c8;
P_0c0771c8: /* original 85f5, guest PC 0x0c0771c8 */
if(!s->budget--) { s->failed_pc=0x0c0771c8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+10,2);
goto P_0c0771ca;
P_0c0771ca: /* original 600d, guest PC 0x0c0771ca */
if(!s->budget--) { s->failed_pc=0x0c0771cau; return 0; }
r[0]=r[0]&65535u;
goto P_0c0771cc;
P_0c0771cc: /* original 4009, guest PC 0x0c0771cc */
if(!s->budget--) { s->failed_pc=0x0c0771ccu; return 0; }
r[0]>>=2;
goto P_0c0771ce;
P_0c0771ce: /* original 4009, guest PC 0x0c0771ce */
if(!s->budget--) { s->failed_pc=0x0c0771ceu; return 0; }
r[0]>>=2;
goto P_0c0771d0;
P_0c0771d0: /* original 81f5, guest PC 0x0c0771d0 */
if(!s->budget--) { s->failed_pc=0x0c0771d0u; return 0; }
write(ram,r[15]+10,r[0],2);
goto P_0c0771d2;
P_0c0771d2: /* original 600d, guest PC 0x0c0771d2 */
if(!s->budget--) { s->failed_pc=0x0c0771d2u; return 0; }
r[0]=r[0]&65535u;
goto P_0c0771d4;
P_0c0771d4: /* original d12e, guest PC 0x0c0771d4 */
if(!s->budget--) { s->failed_pc=0x0c0771d4u; return 0; }
r[1]=read(ram,0x0c077290u,4);
goto P_0c0771d6;
P_0c0771d6: /* original 4000, guest PC 0x0c0771d6 */
if(!s->budget--) { s->failed_pc=0x0c0771d6u; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c0771d8;
P_0c0771d8: /* original 001d, guest PC 0x0c0771d8 */
if(!s->budget--) { s->failed_pc=0x0c0771d8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[1]+r[0],2);
goto P_0c0771da;
P_0c0771da: /* original 81f5, guest PC 0x0c0771da */
if(!s->budget--) { s->failed_pc=0x0c0771dau; return 0; }
write(ram,r[15]+10,r[0],2);
goto P_0c0771dc;
P_0c0771dc: /* original 9056, guest PC 0x0c0771dc */
if(!s->budget--) { s->failed_pc=0x0c0771dcu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07728cu,2);
goto P_0c0771de;
P_0c0771de: /* original 03ed, guest PC 0x0c0771de */
if(!s->budget--) { s->failed_pc=0x0c0771deu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0771e0;
P_0c0771e0: /* original 85f5, guest PC 0x0c0771e0 */
if(!s->budget--) { s->failed_pc=0x0c0771e0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+10,2);
goto P_0c0771e2;
P_0c0771e2: /* original 3038, guest PC 0x0c0771e2 */
if(!s->budget--) { s->failed_pc=0x0c0771e2u; return 0; }
r[0]-=r[3];
goto P_0c0771e4;
P_0c0771e4: /* original 81f5, guest PC 0x0c0771e4 */
if(!s->budget--) { s->failed_pc=0x0c0771e4u; return 0; }
write(ram,r[15]+10,r[0],2);
goto P_0c0771e6;
P_0c0771e6: /* original d32b, guest PC 0x0c0771e6 */
if(!s->budget--) { s->failed_pc=0x0c0771e6u; return 0; }
r[3]=read(ram,0x0c077294u,4);
goto P_0c0771e8;
P_0c0771e8: /* original 6132, guest PC 0x0c0771e8 */
if(!s->budget--) { s->failed_pc=0x0c0771e8u; return 0; }
tmp=read(ram,r[3],4);
r[1]=tmp;
goto P_0c0771ea;
P_0c0771ea: /* original 851f, guest PC 0x0c0771ea */
if(!s->budget--) { s->failed_pc=0x0c0771eau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[1]+30,2);
goto P_0c0771ec;
P_0c0771ec: /* original 6203, guest PC 0x0c0771ec */
if(!s->budget--) { s->failed_pc=0x0c0771ecu; return 0; }
r[2]=r[0];
goto P_0c0771ee;
P_0c0771ee: /* original 85f5, guest PC 0x0c0771ee */
if(!s->budget--) { s->failed_pc=0x0c0771eeu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+10,2);
goto P_0c0771f0;
P_0c0771f0: /* original 302c, guest PC 0x0c0771f0 */
if(!s->budget--) { s->failed_pc=0x0c0771f0u; return 0; }
r[0]+=r[2];
goto P_0c0771f2;
P_0c0771f2: /* original 81f5, guest PC 0x0c0771f2 */
if(!s->budget--) { s->failed_pc=0x0c0771f2u; return 0; }
write(ram,r[15]+10,r[0],2);
goto P_0c0771f4;
P_0c0771f4: /* original 600d, guest PC 0x0c0771f4 */
if(!s->budget--) { s->failed_pc=0x0c0771f4u; return 0; }
r[0]=r[0]&65535u;
goto P_0c0771f6;
P_0c0771f6: /* original d128, guest PC 0x0c0771f6 */
if(!s->budget--) { s->failed_pc=0x0c0771f6u; return 0; }
r[1]=read(ram,0x0c077298u,4);
goto P_0c0771f8;
P_0c0771f8: /* original 2018, guest PC 0x0c0771f8 */
if(!s->budget--) { s->failed_pc=0x0c0771f8u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[1])==0)!=0);
goto P_0c0771fa;
P_0c0771fa: /* original 8903, guest PC 0x0c0771fa */
if(!s->budget--) { s->failed_pc=0x0c0771fau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c077204; }
goto P_0c0771fc;
P_0c0771fc: /* original 50fe, guest PC 0x0c0771fc */
if(!s->budget--) { s->failed_pc=0x0c0771fcu; return 0; }
r[0]=read(ram,r[15]+56,4);
goto P_0c0771fe;
P_0c0771fe: /* original cb80, guest PC 0x0c0771fe */
if(!s->budget--) { s->failed_pc=0x0c0771feu; return 0; }
r[0]|=128u;
goto P_0c077200;
P_0c077200: /* original a041, guest PC 0x0c077200 */
if(!s->budget--) { s->failed_pc=0x0c077200u; return 0; }
write(ram,r[15]+56,r[0],4);
goto P_0c077286;
P_0c077202: /* original 1f0e, guest PC 0x0c077202 */
if(!s->budget--) { s->failed_pc=0x0c077202u; return 0; }
write(ram,r[15]+56,r[0],4);
goto P_0c077204;
P_0c077204: /* original 51fe, guest PC 0x0c077204 */
if(!s->budget--) { s->failed_pc=0x0c077204u; return 0; }
r[1]=read(ram,r[15]+56,4);
goto P_0c077206;
P_0c077206: /* original 9242, guest PC 0x0c077206 */
if(!s->budget--) { s->failed_pc=0x0c077206u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07728eu,2);
goto P_0c077208;
P_0c077208: /* original 212b, guest PC 0x0c077208 */
if(!s->budget--) { s->failed_pc=0x0c077208u; return 0; }
r[1]|=r[2];
goto P_0c07720a;
P_0c07720a: /* original a03c, guest PC 0x0c07720a */
if(!s->budget--) { s->failed_pc=0x0c07720au; return 0; }
write(ram,r[15]+56,r[1],4);
goto P_0c077286;
P_0c07720c: /* original 1f1e, guest PC 0x0c07720c */
if(!s->budget--) { s->failed_pc=0x0c07720cu; return 0; }
write(ram,r[15]+56,r[1],4);
goto P_0c07720e;
P_0c07720e: /* original 53f1, guest PC 0x0c07720e */
if(!s->budget--) { s->failed_pc=0x0c07720eu; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c077210;
P_0c077210: /* original 1f3b, guest PC 0x0c077210 */
if(!s->budget--) { s->failed_pc=0x0c077210u; return 0; }
write(ram,r[15]+44,r[3],4);
goto P_0c077212;
P_0c077212: /* original 52ee, guest PC 0x0c077212 */
if(!s->budget--) { s->failed_pc=0x0c077212u; return 0; }
r[2]=read(ram,r[14]+56,4);
goto P_0c077214;
P_0c077214: /* original d321, guest PC 0x0c077214 */
if(!s->budget--) { s->failed_pc=0x0c077214u; return 0; }
r[3]=read(ram,0x0c07729cu,4);
goto P_0c077216;
P_0c077216: /* original 2238, guest PC 0x0c077216 */
if(!s->budget--) { s->failed_pc=0x0c077216u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c077218;
P_0c077218: /* original 8902, guest PC 0x0c077218 */
if(!s->budget--) { s->failed_pc=0x0c077218u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c077220; }
goto P_0c07721a;
P_0c07721a: /* original e050, guest PC 0x0c07721a */
if(!s->budget--) { s->failed_pc=0x0c07721au; return 0; }
r[0]=0x00000050u;
goto P_0c07721c;
P_0c07721c: /* original 00fe, guest PC 0x0c07721c */
if(!s->budget--) { s->failed_pc=0x0c07721cu; return 0; }
r[0]=read(ram,r[15]+r[0],4);
goto P_0c07721e;
P_0c07721e: /* original 1f0b, guest PC 0x0c07721e */
if(!s->budget--) { s->failed_pc=0x0c07721eu; return 0; }
write(ram,r[15]+44,r[0],4);
goto P_0c077220;
P_0c077220: /* original 50fb, guest PC 0x0c077220 */
if(!s->budget--) { s->failed_pc=0x0c077220u; return 0; }
r[0]=read(ram,r[15]+44,4);
goto P_0c077222;
P_0c077222: /* original c810, guest PC 0x0c077222 */
if(!s->budget--) { s->failed_pc=0x0c077222u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&16u)==0)!=0);
goto P_0c077224;
P_0c077224: /* original 8b13, guest PC 0x0c077224 */
if(!s->budget--) { s->failed_pc=0x0c077224u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07724e; }
goto P_0c077226;
P_0c077226: /* original 50fb, guest PC 0x0c077226 */
if(!s->budget--) { s->failed_pc=0x0c077226u; return 0; }
r[0]=read(ram,r[15]+44,4);
goto P_0c077228;
P_0c077228: /* original c820, guest PC 0x0c077228 */
if(!s->budget--) { s->failed_pc=0x0c077228u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&32u)==0)!=0);
goto P_0c07722a;
P_0c07722a: /* original 8b10, guest PC 0x0c07722a */
if(!s->budget--) { s->failed_pc=0x0c07722au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07724e; }
goto P_0c07722c;
P_0c07722c: /* original e040, guest PC 0x0c07722c */
if(!s->budget--) { s->failed_pc=0x0c07722cu; return 0; }
r[0]=0x00000040u;
goto P_0c07722e;
P_0c07722e: /* original 53fb, guest PC 0x0c07722e */
if(!s->budget--) { s->failed_pc=0x0c07722eu; return 0; }
r[3]=read(ram,r[15]+44,4);
goto P_0c077230;
P_0c077230: /* original 02fe, guest PC 0x0c077230 */
if(!s->budget--) { s->failed_pc=0x0c077230u; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c077232;
P_0c077232: /* original 2238, guest PC 0x0c077232 */
if(!s->budget--) { s->failed_pc=0x0c077232u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c077234;
P_0c077234: /* original 8902, guest PC 0x0c077234 */
if(!s->budget--) { s->failed_pc=0x0c077234u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07723c; }
goto P_0c077236;
P_0c077236: /* original 50fe, guest PC 0x0c077236 */
if(!s->budget--) { s->failed_pc=0x0c077236u; return 0; }
r[0]=read(ram,r[15]+56,4);
goto P_0c077238;
P_0c077238: /* original a007, guest PC 0x0c077238 */
if(!s->budget--) { s->failed_pc=0x0c077238u; return 0; }
r[0]|=32u;
goto P_0c07724a;
P_0c07723a: /* original cb20, guest PC 0x0c07723a */
if(!s->budget--) { s->failed_pc=0x0c07723au; return 0; }
r[0]|=32u;
goto P_0c07723c;
P_0c07723c: /* original e044, guest PC 0x0c07723c */
if(!s->budget--) { s->failed_pc=0x0c07723cu; return 0; }
r[0]=0x00000044u;
goto P_0c07723e;
P_0c07723e: /* original 53fb, guest PC 0x0c07723e */
if(!s->budget--) { s->failed_pc=0x0c07723eu; return 0; }
r[3]=read(ram,r[15]+44,4);
goto P_0c077240;
P_0c077240: /* original 02fe, guest PC 0x0c077240 */
if(!s->budget--) { s->failed_pc=0x0c077240u; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c077242;
P_0c077242: /* original 2238, guest PC 0x0c077242 */
if(!s->budget--) { s->failed_pc=0x0c077242u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c077244;
P_0c077244: /* original 8903, guest PC 0x0c077244 */
if(!s->budget--) { s->failed_pc=0x0c077244u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07724e; }
goto P_0c077246;
P_0c077246: /* original 50fe, guest PC 0x0c077246 */
if(!s->budget--) { s->failed_pc=0x0c077246u; return 0; }
r[0]=read(ram,r[15]+56,4);
goto P_0c077248;
P_0c077248: /* original cb10, guest PC 0x0c077248 */
if(!s->budget--) { s->failed_pc=0x0c077248u; return 0; }
r[0]|=16u;
goto P_0c07724a;
P_0c07724a: /* original a01c, guest PC 0x0c07724a */
if(!s->budget--) { s->failed_pc=0x0c07724au; return 0; }
write(ram,r[15]+56,r[0],4);
goto P_0c077286;
P_0c07724c: /* original 1f0e, guest PC 0x0c07724c */
if(!s->budget--) { s->failed_pc=0x0c07724cu; return 0; }
write(ram,r[15]+56,r[0],4);
goto P_0c07724e;
P_0c07724e: /* original 53fe, guest PC 0x0c07724e */
if(!s->budget--) { s->failed_pc=0x0c07724eu; return 0; }
r[3]=read(ram,r[15]+56,4);
goto P_0c077250;
P_0c077250: /* original 1f3d, guest PC 0x0c077250 */
if(!s->budget--) { s->failed_pc=0x0c077250u; return 0; }
write(ram,r[15]+52,r[3],4);
goto P_0c077252;
P_0c077252: /* original e3fe, guest PC 0x0c077252 */
if(!s->budget--) { s->failed_pc=0x0c077252u; return 0; }
r[3]=0xfffffffeu;
goto P_0c077254;
P_0c077254: /* original 52ee, guest PC 0x0c077254 */
if(!s->budget--) { s->failed_pc=0x0c077254u; return 0; }
r[2]=read(ram,r[14]+56,4);
goto P_0c077256;
P_0c077256: /* original 50fc, guest PC 0x0c077256 */
if(!s->budget--) { s->failed_pc=0x0c077256u; return 0; }
r[0]=read(ram,r[15]+48,4);
goto P_0c077258;
P_0c077258: /* original 2239, guest PC 0x0c077258 */
if(!s->budget--) { s->failed_pc=0x0c077258u; return 0; }
r[2]&=r[3];
goto P_0c07725a;
P_0c07725a: /* original c901, guest PC 0x0c07725a */
if(!s->budget--) { s->failed_pc=0x0c07725au; return 0; }
r[0]&=1u;
goto P_0c07725c;
P_0c07725c: /* original 202b, guest PC 0x0c07725c */
if(!s->budget--) { s->failed_pc=0x0c07725cu; return 0; }
r[0]|=r[2];
goto P_0c07725e;
P_0c07725e: /* original 1f0e, guest PC 0x0c07725e */
if(!s->budget--) { s->failed_pc=0x0c07725eu; return 0; }
write(ram,r[15]+56,r[0],4);
goto P_0c077260;
P_0c077260: /* original 50fd, guest PC 0x0c077260 */
if(!s->budget--) { s->failed_pc=0x0c077260u; return 0; }
r[0]=read(ram,r[15]+52,4);
goto P_0c077262;
P_0c077262: /* original c804, guest PC 0x0c077262 */
if(!s->budget--) { s->failed_pc=0x0c077262u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&4u)==0)!=0);
goto P_0c077264;
P_0c077264: /* original 8b09, guest PC 0x0c077264 */
if(!s->budget--) { s->failed_pc=0x0c077264u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07727a; }
goto P_0c077266;
P_0c077266: /* original 50fd, guest PC 0x0c077266 */
if(!s->budget--) { s->failed_pc=0x0c077266u; return 0; }
r[0]=read(ram,r[15]+52,4);
goto P_0c077268;
P_0c077268: /* original c802, guest PC 0x0c077268 */
if(!s->budget--) { s->failed_pc=0x0c077268u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&2u)==0)!=0);
goto P_0c07726a;
P_0c07726a: /* original 890c, guest PC 0x0c07726a */
if(!s->budget--) { s->failed_pc=0x0c07726au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c077286; }
goto P_0c07726c;
P_0c07726c: /* original 50fe, guest PC 0x0c07726c */
if(!s->budget--) { s->failed_pc=0x0c07726cu; return 0; }
r[0]=read(ram,r[15]+56,4);
goto P_0c07726e;
P_0c07726e: /* original e3fb, guest PC 0x0c07726e */
if(!s->budget--) { s->failed_pc=0x0c07726eu; return 0; }
r[3]=0xfffffffbu;
goto P_0c077270;
P_0c077270: /* original cb02, guest PC 0x0c077270 */
if(!s->budget--) { s->failed_pc=0x0c077270u; return 0; }
r[0]|=2u;
goto P_0c077272;
P_0c077272: /* original 6103, guest PC 0x0c077272 */
if(!s->budget--) { s->failed_pc=0x0c077272u; return 0; }
r[1]=r[0];
goto P_0c077274;
P_0c077274: /* original 1f0e, guest PC 0x0c077274 */
if(!s->budget--) { s->failed_pc=0x0c077274u; return 0; }
write(ram,r[15]+56,r[0],4);
goto P_0c077276;
P_0c077276: /* original a005, guest PC 0x0c077276 */
if(!s->budget--) { s->failed_pc=0x0c077276u; return 0; }
r[1]&=r[3];
goto P_0c077284;
P_0c077278: /* original 2139, guest PC 0x0c077278 */
if(!s->budget--) { s->failed_pc=0x0c077278u; return 0; }
r[1]&=r[3];
goto P_0c07727a;
P_0c07727a: /* original 50fe, guest PC 0x0c07727a */
if(!s->budget--) { s->failed_pc=0x0c07727au; return 0; }
r[0]=read(ram,r[15]+56,4);
goto P_0c07727c;
P_0c07727c: /* original e3fd, guest PC 0x0c07727c */
if(!s->budget--) { s->failed_pc=0x0c07727cu; return 0; }
r[3]=0xfffffffdu;
goto P_0c07727e;
P_0c07727e: /* original cb04, guest PC 0x0c07727e */
if(!s->budget--) { s->failed_pc=0x0c07727eu; return 0; }
r[0]|=4u;
goto P_0c077280;
P_0c077280: /* original 6103, guest PC 0x0c077280 */
if(!s->budget--) { s->failed_pc=0x0c077280u; return 0; }
r[1]=r[0];
goto P_0c077282;
P_0c077282: /* original 2139, guest PC 0x0c077282 */
if(!s->budget--) { s->failed_pc=0x0c077282u; return 0; }
r[1]&=r[3];
goto P_0c077284;
P_0c077284: /* original 1f1e, guest PC 0x0c077284 */
if(!s->budget--) { s->failed_pc=0x0c077284u; return 0; }
write(ram,r[15]+56,r[1],4);
goto P_0c077286;
P_0c077286: /* original 52fe, guest PC 0x0c077286 */
if(!s->budget--) { s->failed_pc=0x0c077286u; return 0; }
r[2]=read(ram,r[15]+56,4);
goto P_0c077288;
P_0c077288: /* original a5c1, guest PC 0x0c077288 */
if(!s->budget--) { s->failed_pc=0x0c077288u; return 0; }
write(ram,r[14]+48,r[2],4);
goto P_0c077e0e;
P_0c07728a: /* original 1e2c, guest PC 0x0c07728a */
if(!s->budget--) { s->failed_pc=0x0c07728au; return 0; }
write(ram,r[14]+48,r[2],4);
return vf3_matrix_family(0x0c07728cu,s,ram);
P_0c0772a0: /* original 61f3, guest PC 0x0c0772a0 */
if(!s->budget--) { s->failed_pc=0x0c0772a0u; return 0; }
r[1]=r[15];
goto P_0c0772a2;
P_0c0772a2: /* original 7150, guest PC 0x0c0772a2 */
if(!s->budget--) { s->failed_pc=0x0c0772a2u; return 0; }
r[1]+=0x00000050u;
goto P_0c0772a4;
P_0c0772a4: /* original 6012, guest PC 0x0c0772a4 */
if(!s->budget--) { s->failed_pc=0x0c0772a4u; return 0; }
tmp=read(ram,r[1],4);
r[0]=tmp;
goto P_0c0772a6;
P_0c0772a6: /* original c802, guest PC 0x0c0772a6 */
if(!s->budget--) { s->failed_pc=0x0c0772a6u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&2u)==0)!=0);
goto P_0c0772a8;
P_0c0772a8: /* original 8927, guest PC 0x0c0772a8 */
if(!s->budget--) { s->failed_pc=0x0c0772a8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0772fa; }
goto P_0c0772aa;
P_0c0772aa: /* original 62f3, guest PC 0x0c0772aa */
if(!s->budget--) { s->failed_pc=0x0c0772aau; return 0; }
r[2]=r[15];
goto P_0c0772ac;
P_0c0772ac: /* original 7250, guest PC 0x0c0772ac */
if(!s->budget--) { s->failed_pc=0x0c0772acu; return 0; }
r[2]+=0x00000050u;
goto P_0c0772ae;
P_0c0772ae: /* original 6022, guest PC 0x0c0772ae */
if(!s->budget--) { s->failed_pc=0x0c0772aeu; return 0; }
tmp=read(ram,r[2],4);
r[0]=tmp;
goto P_0c0772b0;
P_0c0772b0: /* original c801, guest PC 0x0c0772b0 */
if(!s->budget--) { s->failed_pc=0x0c0772b0u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&1u)==0)!=0);
goto P_0c0772b2;
P_0c0772b2: /* original 8b22, guest PC 0x0c0772b2 */
if(!s->budget--) { s->failed_pc=0x0c0772b2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0772fa; }
goto P_0c0772b4;
P_0c0772b4: /* original 61f3, guest PC 0x0c0772b4 */
if(!s->budget--) { s->failed_pc=0x0c0772b4u; return 0; }
r[1]=r[15];
goto P_0c0772b6;
P_0c0772b6: /* original 7150, guest PC 0x0c0772b6 */
if(!s->budget--) { s->failed_pc=0x0c0772b6u; return 0; }
r[1]+=0x00000050u;
goto P_0c0772b8;
P_0c0772b8: /* original 6012, guest PC 0x0c0772b8 */
if(!s->budget--) { s->failed_pc=0x0c0772b8u; return 0; }
tmp=read(ram,r[1],4);
r[0]=tmp;
goto P_0c0772ba;
P_0c0772ba: /* original c804, guest PC 0x0c0772ba */
if(!s->budget--) { s->failed_pc=0x0c0772bau; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&4u)==0)!=0);
goto P_0c0772bc;
P_0c0772bc: /* original 8b1d, guest PC 0x0c0772bc */
if(!s->budget--) { s->failed_pc=0x0c0772bcu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0772fa; }
goto P_0c0772be;
P_0c0772be: /* original 62f3, guest PC 0x0c0772be */
if(!s->budget--) { s->failed_pc=0x0c0772beu; return 0; }
r[2]=r[15];
goto P_0c0772c0;
P_0c0772c0: /* original 7250, guest PC 0x0c0772c0 */
if(!s->budget--) { s->failed_pc=0x0c0772c0u; return 0; }
r[2]+=0x00000050u;
goto P_0c0772c2;
P_0c0772c2: /* original 6022, guest PC 0x0c0772c2 */
if(!s->budget--) { s->failed_pc=0x0c0772c2u; return 0; }
tmp=read(ram,r[2],4);
r[0]=tmp;
goto P_0c0772c4;
P_0c0772c4: /* original c808, guest PC 0x0c0772c4 */
if(!s->budget--) { s->failed_pc=0x0c0772c4u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&8u)==0)!=0);
goto P_0c0772c6;
P_0c0772c6: /* original 8b18, guest PC 0x0c0772c6 */
if(!s->budget--) { s->failed_pc=0x0c0772c6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0772fa; }
goto P_0c0772c8;
P_0c0772c8: /* original 51ee, guest PC 0x0c0772c8 */
if(!s->budget--) { s->failed_pc=0x0c0772c8u; return 0; }
r[1]=read(ram,r[14]+56,4);
goto P_0c0772ca;
P_0c0772ca: /* original 6013, guest PC 0x0c0772ca */
if(!s->budget--) { s->failed_pc=0x0c0772cau; return 0; }
r[0]=r[1];
goto P_0c0772cc;
P_0c0772cc: /* original c80e, guest PC 0x0c0772cc */
if(!s->budget--) { s->failed_pc=0x0c0772ccu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&14u)==0)!=0);
goto P_0c0772ce;
P_0c0772ce: /* original 1f1e, guest PC 0x0c0772ce */
if(!s->budget--) { s->failed_pc=0x0c0772ceu; return 0; }
write(ram,r[15]+56,r[1],4);
goto P_0c0772d0;
P_0c0772d0: /* original 8b13, guest PC 0x0c0772d0 */
if(!s->budget--) { s->failed_pc=0x0c0772d0u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0772fa; }
goto P_0c0772d2;
P_0c0772d2: /* original e06c, guest PC 0x0c0772d2 */
if(!s->budget--) { s->failed_pc=0x0c0772d2u; return 0; }
r[0]=0x0000006cu;
goto P_0c0772d4;
P_0c0772d4: /* original e11e, guest PC 0x0c0772d4 */
if(!s->budget--) { s->failed_pc=0x0c0772d4u; return 0; }
r[1]=0x0000001eu;
goto P_0c0772d6;
P_0c0772d6: /* original 0f16, guest PC 0x0c0772d6 */
if(!s->budget--) { s->failed_pc=0x0c0772d6u; return 0; }
write(ram,r[15]+r[0],r[1],4);
goto P_0c0772d8;
P_0c0772d8: /* original 50f1, guest PC 0x0c0772d8 */
if(!s->budget--) { s->failed_pc=0x0c0772d8u; return 0; }
r[0]=read(ram,r[15]+4,4);
goto P_0c0772da;
P_0c0772da: /* original c810, guest PC 0x0c0772da */
if(!s->budget--) { s->failed_pc=0x0c0772dau; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&16u)==0)!=0);
goto P_0c0772dc;
P_0c0772dc: /* original 8902, guest PC 0x0c0772dc */
if(!s->budget--) { s->failed_pc=0x0c0772dcu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0772e4; }
goto P_0c0772de;
P_0c0772de: /* original e06c, guest PC 0x0c0772de */
if(!s->budget--) { s->failed_pc=0x0c0772deu; return 0; }
r[0]=0x0000006cu;
goto P_0c0772e0;
P_0c0772e0: /* original e11d, guest PC 0x0c0772e0 */
if(!s->budget--) { s->failed_pc=0x0c0772e0u; return 0; }
r[1]=0x0000001du;
goto P_0c0772e2;
P_0c0772e2: /* original 0f16, guest PC 0x0c0772e2 */
if(!s->budget--) { s->failed_pc=0x0c0772e2u; return 0; }
write(ram,r[15]+r[0],r[1],4);
goto P_0c0772e4;
P_0c0772e4: /* original e06c, guest PC 0x0c0772e4 */
if(!s->budget--) { s->failed_pc=0x0c0772e4u; return 0; }
r[0]=0x0000006cu;
goto P_0c0772e6;
P_0c0772e6: /* original d217, guest PC 0x0c0772e6 */
if(!s->budget--) { s->failed_pc=0x0c0772e6u; return 0; }
r[2]=read(ram,0x0c077344u,4);
goto P_0c0772e8;
P_0c0772e8: /* original 03fe, guest PC 0x0c0772e8 */
if(!s->budget--) { s->failed_pc=0x0c0772e8u; return 0; }
r[3]=read(ram,r[15]+r[0],4);
goto P_0c0772ea;
P_0c0772ea: /* original 51fe, guest PC 0x0c0772ea */
if(!s->budget--) { s->failed_pc=0x0c0772eau; return 0; }
r[1]=read(ram,r[15]+56,4);
goto P_0c0772ec;
P_0c0772ec: /* original 633b, guest PC 0x0c0772ec */
if(!s->budget--) { s->failed_pc=0x0c0772ecu; return 0; }
r[3]=0u-r[3];
goto P_0c0772ee;
P_0c0772ee: /* original 423d, guest PC 0x0c0772ee */
if(!s->budget--) { s->failed_pc=0x0c0772eeu; return 0; }
r[2]=(r[3]&0x80000000u)?((r[3]&31u)?r[2]>>((-r[3])&31u):0):r[2]<<(r[3]&31u);
goto P_0c0772f0;
P_0c0772f0: /* original 212b, guest PC 0x0c0772f0 */
if(!s->budget--) { s->failed_pc=0x0c0772f0u; return 0; }
r[1]|=r[2];
goto P_0c0772f2;
P_0c0772f2: /* original 6313, guest PC 0x0c0772f2 */
if(!s->budget--) { s->failed_pc=0x0c0772f2u; return 0; }
r[3]=r[1];
goto P_0c0772f4;
P_0c0772f4: /* original 1f1e, guest PC 0x0c0772f4 */
if(!s->budget--) { s->failed_pc=0x0c0772f4u; return 0; }
write(ram,r[15]+56,r[1],4);
goto P_0c0772f6;
P_0c0772f6: /* original a58a, guest PC 0x0c0772f6 */
if(!s->budget--) { s->failed_pc=0x0c0772f6u; return 0; }
write(ram,r[14]+48,r[3],4);
goto P_0c077e0e;
P_0c0772f8: /* original 1e3c, guest PC 0x0c0772f8 */
if(!s->budget--) { s->failed_pc=0x0c0772f8u; return 0; }
write(ram,r[14]+48,r[3],4);
goto P_0c0772fa;
P_0c0772fa: /* original 61f3, guest PC 0x0c0772fa */
if(!s->budget--) { s->failed_pc=0x0c0772fau; return 0; }
r[1]=r[15];
goto P_0c0772fc;
P_0c0772fc: /* original 7150, guest PC 0x0c0772fc */
if(!s->budget--) { s->failed_pc=0x0c0772fcu; return 0; }
r[1]+=0x00000050u;
goto P_0c0772fe;
P_0c0772fe: /* original 6012, guest PC 0x0c0772fe */
if(!s->budget--) { s->failed_pc=0x0c0772feu; return 0; }
tmp=read(ram,r[1],4);
r[0]=tmp;
goto P_0c077300;
P_0c077300: /* original c804, guest PC 0x0c077300 */
if(!s->budget--) { s->failed_pc=0x0c077300u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&4u)==0)!=0);
goto P_0c077302;
P_0c077302: /* original 8b01, guest PC 0x0c077302 */
if(!s->budget--) { s->failed_pc=0x0c077302u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c077308; }
goto P_0c077304;
P_0c077304: /* original a0b2, guest PC 0x0c077304 */
if(!s->budget--) { s->failed_pc=0x0c077304u; return 0; }
goto P_0c07746c;
P_0c077306: /* original 0009, guest PC 0x0c077306 */
if(!s->budget--) { s->failed_pc=0x0c077306u; return 0; }
goto P_0c077308;
P_0c077308: /* original 62f3, guest PC 0x0c077308 */
if(!s->budget--) { s->failed_pc=0x0c077308u; return 0; }
r[2]=r[15];
goto P_0c07730a;
P_0c07730a: /* original 7250, guest PC 0x0c07730a */
if(!s->budget--) { s->failed_pc=0x0c07730au; return 0; }
r[2]+=0x00000050u;
goto P_0c07730c;
P_0c07730c: /* original 6022, guest PC 0x0c07730c */
if(!s->budget--) { s->failed_pc=0x0c07730cu; return 0; }
tmp=read(ram,r[2],4);
r[0]=tmp;
goto P_0c07730e;
P_0c07730e: /* original c80b, guest PC 0x0c07730e */
if(!s->budget--) { s->failed_pc=0x0c07730eu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&11u)==0)!=0);
goto P_0c077310;
P_0c077310: /* original 8901, guest PC 0x0c077310 */
if(!s->budget--) { s->failed_pc=0x0c077310u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c077316; }
goto P_0c077312;
P_0c077312: /* original a0d5, guest PC 0x0c077312 */
if(!s->budget--) { s->failed_pc=0x0c077312u; return 0; }
goto P_0c0774c0;
P_0c077314: /* original 0009, guest PC 0x0c077314 */
if(!s->budget--) { s->failed_pc=0x0c077314u; return 0; }
goto P_0c077316;
P_0c077316: /* original 9012, guest PC 0x0c077316 */
if(!s->budget--) { s->failed_pc=0x0c077316u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07733eu,2);
goto P_0c077318;
P_0c077318: /* original d30b, guest PC 0x0c077318 */
if(!s->budget--) { s->failed_pc=0x0c077318u; return 0; }
r[3]=read(ram,0x0c077348u,4);
goto P_0c07731a;
P_0c07731a: /* original 01fe, guest PC 0x0c07731a */
if(!s->budget--) { s->failed_pc=0x0c07731au; return 0; }
r[1]=read(ram,r[15]+r[0],4);
goto P_0c07731c;
P_0c07731c: /* original 900f, guest PC 0x0c07731c */
if(!s->budget--) { s->failed_pc=0x0c07731cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07733eu,2);
goto P_0c07731e;
P_0c07731e: /* original 2139, guest PC 0x0c07731e */
if(!s->budget--) { s->failed_pc=0x0c07731eu; return 0; }
r[1]&=r[3];
goto P_0c077320;
P_0c077320: /* original 0f16, guest PC 0x0c077320 */
if(!s->budget--) { s->failed_pc=0x0c077320u; return 0; }
write(ram,r[15]+r[0],r[1],4);
goto P_0c077322;
P_0c077322: /* original 900d, guest PC 0x0c077322 */
if(!s->budget--) { s->failed_pc=0x0c077322u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077340u,2);
goto P_0c077324;
P_0c077324: /* original 02ec, guest PC 0x0c077324 */
if(!s->budget--) { s->failed_pc=0x0c077324u; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c077326;
P_0c077326: /* original 7001, guest PC 0x0c077326 */
if(!s->budget--) { s->failed_pc=0x0c077326u; return 0; }
r[0]+=0x00000001u;
goto P_0c077328;
P_0c077328: /* original 0e24, guest PC 0x0c077328 */
if(!s->budget--) { s->failed_pc=0x0c077328u; return 0; }
write(ram,r[14]+r[0],r[2],1);
goto P_0c07732a;
P_0c07732a: /* original 7015, guest PC 0x0c07732a */
if(!s->budget--) { s->failed_pc=0x0c07732au; return 0; }
r[0]+=0x00000015u;
goto P_0c07732c;
P_0c07732c: /* original 01ee, guest PC 0x0c07732c */
if(!s->budget--) { s->failed_pc=0x0c07732cu; return 0; }
r[1]=read(ram,r[14]+r[0],4);
goto P_0c07732e;
P_0c07732e: /* original 2118, guest PC 0x0c07732e */
if(!s->budget--) { s->failed_pc=0x0c07732eu; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[1])==0)!=0);
goto P_0c077330;
P_0c077330: /* original 890c, guest PC 0x0c077330 */
if(!s->budget--) { s->failed_pc=0x0c077330u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07734c; }
goto P_0c077332;
P_0c077332: /* original 9006, guest PC 0x0c077332 */
if(!s->budget--) { s->failed_pc=0x0c077332u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077342u,2);
goto P_0c077334;
P_0c077334: /* original 01ed, guest PC 0x0c077334 */
if(!s->budget--) { s->failed_pc=0x0c077334u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c077336;
P_0c077336: /* original 2118, guest PC 0x0c077336 */
if(!s->budget--) { s->failed_pc=0x0c077336u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[1])==0)!=0);
goto P_0c077338;
P_0c077338: /* original 8b3d, guest PC 0x0c077338 */
if(!s->budget--) { s->failed_pc=0x0c077338u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0773b6; }
goto P_0c07733a;
P_0c07733a: /* original a011, guest PC 0x0c07733a */
if(!s->budget--) { s->failed_pc=0x0c07733au; return 0; }
goto P_0c077360;
P_0c07733c: /* original 0009, guest PC 0x0c07733c */
if(!s->budget--) { s->failed_pc=0x0c07733cu; return 0; }
return vf3_matrix_family(0x0c07733eu,s,ram);
P_0c07734c: /* original 907f, guest PC 0x0c07734c */
if(!s->budget--) { s->failed_pc=0x0c07734cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07744eu,2);
goto P_0c07734e;
P_0c07734e: /* original d244, guest PC 0x0c07734e */
if(!s->budget--) { s->failed_pc=0x0c07734eu; return 0; }
r[2]=read(ram,0x0c077460u,4);
goto P_0c077350;
P_0c077350: /* original 01fe, guest PC 0x0c077350 */
if(!s->budget--) { s->failed_pc=0x0c077350u; return 0; }
r[1]=read(ram,r[15]+r[0],4);
goto P_0c077352;
P_0c077352: /* original 2128, guest PC 0x0c077352 */
if(!s->budget--) { s->failed_pc=0x0c077352u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[2])==0)!=0);
goto P_0c077354;
P_0c077354: /* original 8b2f, guest PC 0x0c077354 */
if(!s->budget--) { s->failed_pc=0x0c077354u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0773b6; }
goto P_0c077356;
P_0c077356: /* original 907b, guest PC 0x0c077356 */
if(!s->budget--) { s->failed_pc=0x0c077356u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077450u,2);
goto P_0c077358;
P_0c077358: /* original d342, guest PC 0x0c077358 */
if(!s->budget--) { s->failed_pc=0x0c077358u; return 0; }
r[3]=read(ram,0x0c077464u,4);
goto P_0c07735a;
P_0c07735a: /* original 02fe, guest PC 0x0c07735a */
if(!s->budget--) { s->failed_pc=0x0c07735au; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c07735c;
P_0c07735c: /* original 2238, guest PC 0x0c07735c */
if(!s->budget--) { s->failed_pc=0x0c07735cu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c07735e;
P_0c07735e: /* original 8b2a, guest PC 0x0c07735e */
if(!s->budget--) { s->failed_pc=0x0c07735eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0773b6; }
goto P_0c077360;
P_0c077360: /* original e078, guest PC 0x0c077360 */
if(!s->budget--) { s->failed_pc=0x0c077360u; return 0; }
r[0]=0x00000078u;
goto P_0c077362;
P_0c077362: /* original e104, guest PC 0x0c077362 */
if(!s->budget--) { s->failed_pc=0x0c077362u; return 0; }
r[1]=0x00000004u;
goto P_0c077364;
P_0c077364: /* original 0f16, guest PC 0x0c077364 */
if(!s->budget--) { s->failed_pc=0x0c077364u; return 0; }
write(ram,r[15]+r[0],r[1],4);
goto P_0c077366;
P_0c077366: /* original e050, guest PC 0x0c077366 */
if(!s->budget--) { s->failed_pc=0x0c077366u; return 0; }
r[0]=0x00000050u;
goto P_0c077368;
P_0c077368: /* original 03fe, guest PC 0x0c077368 */
if(!s->budget--) { s->failed_pc=0x0c077368u; return 0; }
r[3]=read(ram,r[15]+r[0],4);
goto P_0c07736a;
P_0c07736a: /* original e04c, guest PC 0x0c07736a */
if(!s->budget--) { s->failed_pc=0x0c07736au; return 0; }
r[0]=0x0000004cu;
goto P_0c07736c;
P_0c07736c: /* original 2f36, guest PC 0x0c07736c */
if(!s->budget--) { s->failed_pc=0x0c07736cu; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07736e;
P_0c07736e: /* original 52f2, guest PC 0x0c07736e */
if(!s->budget--) { s->failed_pc=0x0c07736eu; return 0; }
r[2]=read(ram,r[15]+8,4);
goto P_0c077370;
P_0c077370: /* original 2f26, guest PC 0x0c077370 */
if(!s->budget--) { s->failed_pc=0x0c077370u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c077372;
P_0c077372: /* original 03fe, guest PC 0x0c077372 */
if(!s->budget--) { s->failed_pc=0x0c077372u; return 0; }
r[3]=read(ram,r[15]+r[0],4);
goto P_0c077374;
P_0c077374: /* original e04c, guest PC 0x0c077374 */
if(!s->budget--) { s->failed_pc=0x0c077374u; return 0; }
r[0]=0x0000004cu;
goto P_0c077376;
P_0c077376: /* original 2f36, guest PC 0x0c077376 */
if(!s->budget--) { s->failed_pc=0x0c077376u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c077378;
P_0c077378: /* original 02fe, guest PC 0x0c077378 */
if(!s->budget--) { s->failed_pc=0x0c077378u; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c07737a;
P_0c07737a: /* original 2f26, guest PC 0x0c07737a */
if(!s->budget--) { s->failed_pc=0x0c07737au; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07737c;
P_0c07737c: /* original 9069, guest PC 0x0c07737c */
if(!s->budget--) { s->failed_pc=0x0c07737cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077452u,2);
goto P_0c07737e;
P_0c07737e: /* original 03fe, guest PC 0x0c07737e */
if(!s->budget--) { s->failed_pc=0x0c07737eu; return 0; }
r[3]=read(ram,r[15]+r[0],4);
goto P_0c077380;
P_0c077380: /* original e05c, guest PC 0x0c077380 */
if(!s->budget--) { s->failed_pc=0x0c077380u; return 0; }
r[0]=0x0000005cu;
goto P_0c077382;
P_0c077382: /* original 2f36, guest PC 0x0c077382 */
if(!s->budget--) { s->failed_pc=0x0c077382u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c077384;
P_0c077384: /* original 02fe, guest PC 0x0c077384 */
if(!s->budget--) { s->failed_pc=0x0c077384u; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c077386;
P_0c077386: /* original 2f26, guest PC 0x0c077386 */
if(!s->budget--) { s->failed_pc=0x0c077386u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c077388;
P_0c077388: /* original 9364, guest PC 0x0c077388 */
if(!s->budget--) { s->failed_pc=0x0c077388u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077454u,2);
goto P_0c07738a;
P_0c07738a: /* original 33fc, guest PC 0x0c07738a */
if(!s->budget--) { s->failed_pc=0x0c07738au; return 0; }
r[3]+=r[15];
goto P_0c07738c;
P_0c07738c: /* original 2f36, guest PC 0x0c07738c */
if(!s->budget--) { s->failed_pc=0x0c07738cu; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07738e;
P_0c07738e: /* original 9061, guest PC 0x0c07738e */
if(!s->budget--) { s->failed_pc=0x0c07738eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077454u,2);
goto P_0c077390;
P_0c077390: /* original 02fe, guest PC 0x0c077390 */
if(!s->budget--) { s->failed_pc=0x0c077390u; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c077392;
P_0c077392: /* original 2f26, guest PC 0x0c077392 */
if(!s->budget--) { s->failed_pc=0x0c077392u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c077394;
P_0c077394: /* original 905d, guest PC 0x0c077394 */
if(!s->budget--) { s->failed_pc=0x0c077394u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077452u,2);
goto P_0c077396;
P_0c077396: /* original 03fe, guest PC 0x0c077396 */
if(!s->budget--) { s->failed_pc=0x0c077396u; return 0; }
r[3]=read(ram,r[15]+r[0],4);
goto P_0c077398;
P_0c077398: /* original 2f36, guest PC 0x0c077398 */
if(!s->budget--) { s->failed_pc=0x0c077398u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07739a;
P_0c07739a: /* original 905c, guest PC 0x0c07739a */
if(!s->budget--) { s->failed_pc=0x0c07739au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077456u,2);
goto P_0c07739c;
P_0c07739c: /* original 02fe, guest PC 0x0c07739c */
if(!s->budget--) { s->failed_pc=0x0c07739cu; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c07739e;
P_0c07739e: /* original 2f26, guest PC 0x0c07739e */
if(!s->budget--) { s->failed_pc=0x0c07739eu; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0773a0;
P_0c0773a0: /* original 9759, guest PC 0x0c0773a0 */
if(!s->budget--) { s->failed_pc=0x0c0773a0u; return 0; }
r[7]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077456u,2);
goto P_0c0773a2;
P_0c0773a2: /* original 65e3, guest PC 0x0c0773a2 */
if(!s->budget--) { s->failed_pc=0x0c0773a2u; return 0; }
r[5]=r[14];
goto P_0c0773a4;
P_0c0773a4: /* original 66d3, guest PC 0x0c0773a4 */
if(!s->budget--) { s->failed_pc=0x0c0773a4u; return 0; }
r[6]=r[13];
goto P_0c0773a6;
P_0c0773a6: /* original 37fc, guest PC 0x0c0773a6 */
if(!s->budget--) { s->failed_pc=0x0c0773a6u; return 0; }
r[7]+=r[15];
goto P_0c0773a8;
P_0c0773a8: /* original b707, guest PC 0x0c0773a8 */
if(!s->budget--) { s->failed_pc=0x0c0773a8u; return 0; }
target=0x0c0781bau; r[16]=0x8c0773acu;
r[4]=r[12];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0773acu) { target=s->pc; goto dispatch; }
goto P_0c0773ac;
P_0c0773aa: /* original 64c3, guest PC 0x0c0773aa */
if(!s->budget--) { s->failed_pc=0x0c0773aau; return 0; }
r[4]=r[12];
goto P_0c0773ac;
P_0c0773ac: /* original 2008, guest PC 0x0c0773ac */
if(!s->budget--) { s->failed_pc=0x0c0773acu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c0773ae;
P_0c0773ae: /* original 8d02, guest PC 0x0c0773ae */
if(!s->budget--) { s->failed_pc=0x0c0773aeu; return 0; }
cond=r[17]&1u;
r[15]+=0x00000028u;
if(cond) { goto P_0c0773b6; }
goto P_0c0773b2;
P_0c0773b0: /* original 7f28, guest PC 0x0c0773b0 */
if(!s->budget--) { s->failed_pc=0x0c0773b0u; return 0; }
r[15]+=0x00000028u;
goto P_0c0773b2;
P_0c0773b2: /* original a545, guest PC 0x0c0773b2 */
if(!s->budget--) { s->failed_pc=0x0c0773b2u; return 0; }
goto P_0c077e40;
P_0c0773b4: /* original 0009, guest PC 0x0c0773b4 */
if(!s->budget--) { s->failed_pc=0x0c0773b4u; return 0; }
goto P_0c0773b6;
P_0c0773b6: /* original 904f, guest PC 0x0c0773b6 */
if(!s->budget--) { s->failed_pc=0x0c0773b6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077458u,2);
goto P_0c0773b8;
P_0c0773b8: /* original 02ec, guest PC 0x0c0773b8 */
if(!s->budget--) { s->failed_pc=0x0c0773b8u; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0773ba;
P_0c0773ba: /* original e06c, guest PC 0x0c0773ba */
if(!s->budget--) { s->failed_pc=0x0c0773bau; return 0; }
r[0]=0x0000006cu;
goto P_0c0773bc;
P_0c0773bc: /* original 622c, guest PC 0x0c0773bc */
if(!s->budget--) { s->failed_pc=0x0c0773bcu; return 0; }
r[2]=r[2]&255u;
goto P_0c0773be;
P_0c0773be: /* original 0f26, guest PC 0x0c0773be */
if(!s->budget--) { s->failed_pc=0x0c0773beu; return 0; }
write(ram,r[15]+r[0],r[2],4);
goto P_0c0773c0;
P_0c0773c0: /* original e06c, guest PC 0x0c0773c0 */
if(!s->budget--) { s->failed_pc=0x0c0773c0u; return 0; }
r[0]=0x0000006cu;
goto P_0c0773c2;
P_0c0773c2: /* original 03fc, guest PC 0x0c0773c2 */
if(!s->budget--) { s->failed_pc=0x0c0773c2u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[15]+r[0],1);
goto P_0c0773c4;
P_0c0773c4: /* original 9049, guest PC 0x0c0773c4 */
if(!s->budget--) { s->failed_pc=0x0c0773c4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07745au,2);
goto P_0c0773c6;
P_0c0773c6: /* original 0e34, guest PC 0x0c0773c6 */
if(!s->budget--) { s->failed_pc=0x0c0773c6u; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c0773c8;
P_0c0773c8: /* original e06c, guest PC 0x0c0773c8 */
if(!s->budget--) { s->failed_pc=0x0c0773c8u; return 0; }
r[0]=0x0000006cu;
goto P_0c0773ca;
P_0c0773ca: /* original 02fc, guest PC 0x0c0773ca */
if(!s->budget--) { s->failed_pc=0x0c0773cau; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[15]+r[0],1);
goto P_0c0773cc;
P_0c0773cc: /* original e300, guest PC 0x0c0773cc */
if(!s->budget--) { s->failed_pc=0x0c0773ccu; return 0; }
r[3]=0x00000000u;
goto P_0c0773ce;
P_0c0773ce: /* original 9045, guest PC 0x0c0773ce */
if(!s->budget--) { s->failed_pc=0x0c0773ceu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07745cu,2);
goto P_0c0773d0;
P_0c0773d0: /* original 0e24, guest PC 0x0c0773d0 */
if(!s->budget--) { s->failed_pc=0x0c0773d0u; return 0; }
write(ram,r[14]+r[0],r[2],1);
goto P_0c0773d2;
P_0c0773d2: /* original 7013, guest PC 0x0c0773d2 */
if(!s->budget--) { s->failed_pc=0x0c0773d2u; return 0; }
r[0]+=0x00000013u;
goto P_0c0773d4;
P_0c0773d4: /* original 0e36, guest PC 0x0c0773d4 */
if(!s->budget--) { s->failed_pc=0x0c0773d4u; return 0; }
write(ram,r[14]+r[0],r[3],4);
goto P_0c0773d6;
P_0c0773d6: /* original 70f8, guest PC 0x0c0773d6 */
if(!s->budget--) { s->failed_pc=0x0c0773d6u; return 0; }
r[0]+=0xfffffff8u;
goto P_0c0773d8;
P_0c0773d8: /* original 6233, guest PC 0x0c0773d8 */
if(!s->budget--) { s->failed_pc=0x0c0773d8u; return 0; }
r[2]=r[3];
goto P_0c0773da;
P_0c0773da: /* original 0e25, guest PC 0x0c0773da */
if(!s->budget--) { s->failed_pc=0x0c0773dau; return 0; }
write(ram,r[14]+r[0],r[2],2);
goto P_0c0773dc;
P_0c0773dc: /* original e03c, guest PC 0x0c0773dc */
if(!s->budget--) { s->failed_pc=0x0c0773dcu; return 0; }
r[0]=0x0000003cu;
goto P_0c0773de;
P_0c0773de: /* original 03ed, guest PC 0x0c0773de */
if(!s->budget--) { s->failed_pc=0x0c0773deu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0773e0;
P_0c0773e0: /* original 2338, guest PC 0x0c0773e0 */
if(!s->budget--) { s->failed_pc=0x0c0773e0u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0773e2;
P_0c0773e2: /* original 890a, guest PC 0x0c0773e2 */
if(!s->budget--) { s->failed_pc=0x0c0773e2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0773fa; }
goto P_0c0773e4;
P_0c0773e4: /* original e03e, guest PC 0x0c0773e4 */
if(!s->budget--) { s->failed_pc=0x0c0773e4u; return 0; }
r[0]=0x0000003eu;
goto P_0c0773e6;
P_0c0773e6: /* original 03ed, guest PC 0x0c0773e6 */
if(!s->budget--) { s->failed_pc=0x0c0773e6u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0773e8;
P_0c0773e8: /* original 9039, guest PC 0x0c0773e8 */
if(!s->budget--) { s->failed_pc=0x0c0773e8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07745eu,2);
goto P_0c0773ea;
P_0c0773ea: /* original 633d, guest PC 0x0c0773ea */
if(!s->budget--) { s->failed_pc=0x0c0773eau; return 0; }
r[3]=r[3]&65535u;
goto P_0c0773ec;
P_0c0773ec: /* original 02ec, guest PC 0x0c0773ec */
if(!s->budget--) { s->failed_pc=0x0c0773ecu; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0773ee;
P_0c0773ee: /* original 622c, guest PC 0x0c0773ee */
if(!s->budget--) { s->failed_pc=0x0c0773eeu; return 0; }
r[2]=r[2]&255u;
goto P_0c0773f0;
P_0c0773f0: /* original 3327, guest PC 0x0c0773f0 */
if(!s->budget--) { s->failed_pc=0x0c0773f0u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>(int32_t)r[2])!=0);
goto P_0c0773f2;
P_0c0773f2: /* original 8902, guest PC 0x0c0773f2 */
if(!s->budget--) { s->failed_pc=0x0c0773f2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0773fa; }
goto P_0c0773f4;
P_0c0773f4: /* original d21c, guest PC 0x0c0773f4 */
if(!s->budget--) { s->failed_pc=0x0c0773f4u; return 0; }
r[2]=read(ram,0x0c077468u,4);
goto P_0c0773f6;
P_0c0773f6: /* original a51f, guest PC 0x0c0773f6 */
if(!s->budget--) { s->failed_pc=0x0c0773f6u; return 0; }
write(ram,r[14]+48,r[2],4);
goto P_0c077e38;
P_0c0773f8: /* original 1e2c, guest PC 0x0c0773f8 */
if(!s->budget--) { s->failed_pc=0x0c0773f8u; return 0; }
write(ram,r[14]+48,r[2],4);
goto P_0c0773fa;
P_0c0773fa: /* original e050, guest PC 0x0c0773fa */
if(!s->budget--) { s->failed_pc=0x0c0773fau; return 0; }
r[0]=0x00000050u;
goto P_0c0773fc;
P_0c0773fc: /* original 66d3, guest PC 0x0c0773fc */
if(!s->budget--) { s->failed_pc=0x0c0773fcu; return 0; }
r[6]=r[13];
goto P_0c0773fe;
P_0c0773fe: /* original 01fe, guest PC 0x0c0773fe */
if(!s->budget--) { s->failed_pc=0x0c0773feu; return 0; }
r[1]=read(ram,r[15]+r[0],4);
goto P_0c077400;
P_0c077400: /* original e04c, guest PC 0x0c077400 */
if(!s->budget--) { s->failed_pc=0x0c077400u; return 0; }
r[0]=0x0000004cu;
goto P_0c077402;
P_0c077402: /* original 2f16, guest PC 0x0c077402 */
if(!s->budget--) { s->failed_pc=0x0c077402u; return 0; }
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c077404;
P_0c077404: /* original 53f2, guest PC 0x0c077404 */
if(!s->budget--) { s->failed_pc=0x0c077404u; return 0; }
r[3]=read(ram,r[15]+8,4);
goto P_0c077406;
P_0c077406: /* original 2f36, guest PC 0x0c077406 */
if(!s->budget--) { s->failed_pc=0x0c077406u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c077408;
P_0c077408: /* original 02fe, guest PC 0x0c077408 */
if(!s->budget--) { s->failed_pc=0x0c077408u; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c07740a;
P_0c07740a: /* original e04c, guest PC 0x0c07740a */
if(!s->budget--) { s->failed_pc=0x0c07740au; return 0; }
r[0]=0x0000004cu;
goto P_0c07740c;
P_0c07740c: /* original 2f26, guest PC 0x0c07740c */
if(!s->budget--) { s->failed_pc=0x0c07740cu; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07740e;
P_0c07740e: /* original 03fe, guest PC 0x0c07740e */
if(!s->budget--) { s->failed_pc=0x0c07740eu; return 0; }
r[3]=read(ram,r[15]+r[0],4);
goto P_0c077410;
P_0c077410: /* original 2f36, guest PC 0x0c077410 */
if(!s->budget--) { s->failed_pc=0x0c077410u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c077412;
P_0c077412: /* original 901e, guest PC 0x0c077412 */
if(!s->budget--) { s->failed_pc=0x0c077412u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077452u,2);
goto P_0c077414;
P_0c077414: /* original 02fe, guest PC 0x0c077414 */
if(!s->budget--) { s->failed_pc=0x0c077414u; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c077416;
P_0c077416: /* original e05c, guest PC 0x0c077416 */
if(!s->budget--) { s->failed_pc=0x0c077416u; return 0; }
r[0]=0x0000005cu;
goto P_0c077418;
P_0c077418: /* original 2f26, guest PC 0x0c077418 */
if(!s->budget--) { s->failed_pc=0x0c077418u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07741a;
P_0c07741a: /* original 03fe, guest PC 0x0c07741a */
if(!s->budget--) { s->failed_pc=0x0c07741au; return 0; }
r[3]=read(ram,r[15]+r[0],4);
goto P_0c07741c;
P_0c07741c: /* original 2f36, guest PC 0x0c07741c */
if(!s->budget--) { s->failed_pc=0x0c07741cu; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07741e;
P_0c07741e: /* original 9219, guest PC 0x0c07741e */
if(!s->budget--) { s->failed_pc=0x0c07741eu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077454u,2);
goto P_0c077420;
P_0c077420: /* original 32fc, guest PC 0x0c077420 */
if(!s->budget--) { s->failed_pc=0x0c077420u; return 0; }
r[2]+=r[15];
goto P_0c077422;
P_0c077422: /* original 2f26, guest PC 0x0c077422 */
if(!s->budget--) { s->failed_pc=0x0c077422u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c077424;
P_0c077424: /* original 9016, guest PC 0x0c077424 */
if(!s->budget--) { s->failed_pc=0x0c077424u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077454u,2);
goto P_0c077426;
P_0c077426: /* original 03fe, guest PC 0x0c077426 */
if(!s->budget--) { s->failed_pc=0x0c077426u; return 0; }
r[3]=read(ram,r[15]+r[0],4);
goto P_0c077428;
P_0c077428: /* original 2f36, guest PC 0x0c077428 */
if(!s->budget--) { s->failed_pc=0x0c077428u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07742a;
P_0c07742a: /* original 9012, guest PC 0x0c07742a */
if(!s->budget--) { s->failed_pc=0x0c07742au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077452u,2);
goto P_0c07742c;
P_0c07742c: /* original 02fe, guest PC 0x0c07742c */
if(!s->budget--) { s->failed_pc=0x0c07742cu; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c07742e;
P_0c07742e: /* original 2f26, guest PC 0x0c07742e */
if(!s->budget--) { s->failed_pc=0x0c07742eu; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c077430;
P_0c077430: /* original 9011, guest PC 0x0c077430 */
if(!s->budget--) { s->failed_pc=0x0c077430u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077456u,2);
goto P_0c077432;
P_0c077432: /* original 03fe, guest PC 0x0c077432 */
if(!s->budget--) { s->failed_pc=0x0c077432u; return 0; }
r[3]=read(ram,r[15]+r[0],4);
goto P_0c077434;
P_0c077434: /* original 2f36, guest PC 0x0c077434 */
if(!s->budget--) { s->failed_pc=0x0c077434u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c077436;
P_0c077436: /* original 970e, guest PC 0x0c077436 */
if(!s->budget--) { s->failed_pc=0x0c077436u; return 0; }
r[7]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077456u,2);
goto P_0c077438;
P_0c077438: /* original 37fc, guest PC 0x0c077438 */
if(!s->budget--) { s->failed_pc=0x0c077438u; return 0; }
r[7]+=r[15];
goto P_0c07743a;
P_0c07743a: /* original 65e3, guest PC 0x0c07743a */
if(!s->budget--) { s->failed_pc=0x0c07743au; return 0; }
r[5]=r[14];
goto P_0c07743c;
P_0c07743c: /* original b507, guest PC 0x0c07743c */
if(!s->budget--) { s->failed_pc=0x0c07743cu; return 0; }
target=0x0c077e4eu; r[16]=0x8c077440u;
r[4]=r[12];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c077440u) { target=s->pc; goto dispatch; }
goto P_0c077440;
P_0c07743e: /* original 64c3, guest PC 0x0c07743e */
if(!s->budget--) { s->failed_pc=0x0c07743eu; return 0; }
r[4]=r[12];
goto P_0c077440;
P_0c077440: /* original 2008, guest PC 0x0c077440 */
if(!s->budget--) { s->failed_pc=0x0c077440u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c077442;
P_0c077442: /* original 8d02, guest PC 0x0c077442 */
if(!s->budget--) { s->failed_pc=0x0c077442u; return 0; }
cond=r[17]&1u;
r[15]+=0x00000028u;
if(cond) { goto P_0c07744a; }
goto P_0c077446;
P_0c077444: /* original 7f28, guest PC 0x0c077444 */
if(!s->budget--) { s->failed_pc=0x0c077444u; return 0; }
r[15]+=0x00000028u;
goto P_0c077446;
P_0c077446: /* original a4fb, guest PC 0x0c077446 */
if(!s->budget--) { s->failed_pc=0x0c077446u; return 0; }
goto P_0c077e40;
P_0c077448: /* original 0009, guest PC 0x0c077448 */
if(!s->budget--) { s->failed_pc=0x0c077448u; return 0; }
goto P_0c07744a;
P_0c07744a: /* original a4f5, guest PC 0x0c07744a */
if(!s->budget--) { s->failed_pc=0x0c07744au; return 0; }
goto P_0c077e38;
P_0c07744c: /* original 0009, guest PC 0x0c07744c */
if(!s->budget--) { s->failed_pc=0x0c07744cu; return 0; }
return vf3_matrix_family(0x0c07744eu,s,ram);
P_0c07746c: /* original e050, guest PC 0x0c07746c */
if(!s->budget--) { s->failed_pc=0x0c07746cu; return 0; }
r[0]=0x00000050u;
goto P_0c07746e;
P_0c07746e: /* original 66d3, guest PC 0x0c07746e */
if(!s->budget--) { s->failed_pc=0x0c07746eu; return 0; }
r[6]=r[13];
goto P_0c077470;
P_0c077470: /* original 03fe, guest PC 0x0c077470 */
if(!s->budget--) { s->failed_pc=0x0c077470u; return 0; }
r[3]=read(ram,r[15]+r[0],4);
goto P_0c077472;
P_0c077472: /* original e04c, guest PC 0x0c077472 */
if(!s->budget--) { s->failed_pc=0x0c077472u; return 0; }
r[0]=0x0000004cu;
goto P_0c077474;
P_0c077474: /* original 2f36, guest PC 0x0c077474 */
if(!s->budget--) { s->failed_pc=0x0c077474u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c077476;
P_0c077476: /* original 52f2, guest PC 0x0c077476 */
if(!s->budget--) { s->failed_pc=0x0c077476u; return 0; }
r[2]=read(ram,r[15]+8,4);
goto P_0c077478;
P_0c077478: /* original 2f26, guest PC 0x0c077478 */
if(!s->budget--) { s->failed_pc=0x0c077478u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07747a;
P_0c07747a: /* original 03fe, guest PC 0x0c07747a */
if(!s->budget--) { s->failed_pc=0x0c07747au; return 0; }
r[3]=read(ram,r[15]+r[0],4);
goto P_0c07747c;
P_0c07747c: /* original e04c, guest PC 0x0c07747c */
if(!s->budget--) { s->failed_pc=0x0c07747cu; return 0; }
r[0]=0x0000004cu;
goto P_0c07747e;
P_0c07747e: /* original 2f36, guest PC 0x0c07747e */
if(!s->budget--) { s->failed_pc=0x0c07747eu; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c077480;
P_0c077480: /* original 02fe, guest PC 0x0c077480 */
if(!s->budget--) { s->failed_pc=0x0c077480u; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c077482;
P_0c077482: /* original 2f26, guest PC 0x0c077482 */
if(!s->budget--) { s->failed_pc=0x0c077482u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c077484;
P_0c077484: /* original 9072, guest PC 0x0c077484 */
if(!s->budget--) { s->failed_pc=0x0c077484u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07756cu,2);
goto P_0c077486;
P_0c077486: /* original 03fe, guest PC 0x0c077486 */
if(!s->budget--) { s->failed_pc=0x0c077486u; return 0; }
r[3]=read(ram,r[15]+r[0],4);
goto P_0c077488;
P_0c077488: /* original e05c, guest PC 0x0c077488 */
if(!s->budget--) { s->failed_pc=0x0c077488u; return 0; }
r[0]=0x0000005cu;
goto P_0c07748a;
P_0c07748a: /* original 2f36, guest PC 0x0c07748a */
if(!s->budget--) { s->failed_pc=0x0c07748au; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07748c;
P_0c07748c: /* original 02fe, guest PC 0x0c07748c */
if(!s->budget--) { s->failed_pc=0x0c07748cu; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c07748e;
P_0c07748e: /* original 2f26, guest PC 0x0c07748e */
if(!s->budget--) { s->failed_pc=0x0c07748eu; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c077490;
P_0c077490: /* original 936d, guest PC 0x0c077490 */
if(!s->budget--) { s->failed_pc=0x0c077490u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07756eu,2);
goto P_0c077492;
P_0c077492: /* original 33fc, guest PC 0x0c077492 */
if(!s->budget--) { s->failed_pc=0x0c077492u; return 0; }
r[3]+=r[15];
goto P_0c077494;
P_0c077494: /* original 2f36, guest PC 0x0c077494 */
if(!s->budget--) { s->failed_pc=0x0c077494u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c077496;
P_0c077496: /* original 906a, guest PC 0x0c077496 */
if(!s->budget--) { s->failed_pc=0x0c077496u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07756eu,2);
goto P_0c077498;
P_0c077498: /* original 02fe, guest PC 0x0c077498 */
if(!s->budget--) { s->failed_pc=0x0c077498u; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c07749a;
P_0c07749a: /* original 2f26, guest PC 0x0c07749a */
if(!s->budget--) { s->failed_pc=0x0c07749au; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07749c;
P_0c07749c: /* original 9066, guest PC 0x0c07749c */
if(!s->budget--) { s->failed_pc=0x0c07749cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07756cu,2);
goto P_0c07749e;
P_0c07749e: /* original 03fe, guest PC 0x0c07749e */
if(!s->budget--) { s->failed_pc=0x0c07749eu; return 0; }
r[3]=read(ram,r[15]+r[0],4);
goto P_0c0774a0;
P_0c0774a0: /* original 2f36, guest PC 0x0c0774a0 */
if(!s->budget--) { s->failed_pc=0x0c0774a0u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0774a2;
P_0c0774a2: /* original 9065, guest PC 0x0c0774a2 */
if(!s->budget--) { s->failed_pc=0x0c0774a2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077570u,2);
goto P_0c0774a4;
P_0c0774a4: /* original 02fe, guest PC 0x0c0774a4 */
if(!s->budget--) { s->failed_pc=0x0c0774a4u; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c0774a6;
P_0c0774a6: /* original 2f26, guest PC 0x0c0774a6 */
if(!s->budget--) { s->failed_pc=0x0c0774a6u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0774a8;
P_0c0774a8: /* original 9762, guest PC 0x0c0774a8 */
if(!s->budget--) { s->failed_pc=0x0c0774a8u; return 0; }
r[7]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077570u,2);
goto P_0c0774aa;
P_0c0774aa: /* original 37fc, guest PC 0x0c0774aa */
if(!s->budget--) { s->failed_pc=0x0c0774aau; return 0; }
r[7]+=r[15];
goto P_0c0774ac;
P_0c0774ac: /* original 65e3, guest PC 0x0c0774ac */
if(!s->budget--) { s->failed_pc=0x0c0774acu; return 0; }
r[5]=r[14];
goto P_0c0774ae;
P_0c0774ae: /* original b4ce, guest PC 0x0c0774ae */
if(!s->budget--) { s->failed_pc=0x0c0774aeu; return 0; }
target=0x0c077e4eu; r[16]=0x8c0774b2u;
r[4]=r[12];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0774b2u) { target=s->pc; goto dispatch; }
goto P_0c0774b2;
P_0c0774b0: /* original 64c3, guest PC 0x0c0774b0 */
if(!s->budget--) { s->failed_pc=0x0c0774b0u; return 0; }
r[4]=r[12];
goto P_0c0774b2;
P_0c0774b2: /* original 2008, guest PC 0x0c0774b2 */
if(!s->budget--) { s->failed_pc=0x0c0774b2u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c0774b4;
P_0c0774b4: /* original 8d02, guest PC 0x0c0774b4 */
if(!s->budget--) { s->failed_pc=0x0c0774b4u; return 0; }
cond=r[17]&1u;
r[15]+=0x00000028u;
if(cond) { goto P_0c0774bc; }
goto P_0c0774b8;
P_0c0774b6: /* original 7f28, guest PC 0x0c0774b6 */
if(!s->budget--) { s->failed_pc=0x0c0774b6u; return 0; }
r[15]+=0x00000028u;
goto P_0c0774b8;
P_0c0774b8: /* original a4c2, guest PC 0x0c0774b8 */
if(!s->budget--) { s->failed_pc=0x0c0774b8u; return 0; }
goto P_0c077e40;
P_0c0774ba: /* original 0009, guest PC 0x0c0774ba */
if(!s->budget--) { s->failed_pc=0x0c0774bau; return 0; }
goto P_0c0774bc;
P_0c0774bc: /* original a006, guest PC 0x0c0774bc */
if(!s->budget--) { s->failed_pc=0x0c0774bcu; return 0; }
goto P_0c0774cc;
P_0c0774be: /* original 0009, guest PC 0x0c0774be */
if(!s->budget--) { s->failed_pc=0x0c0774beu; return 0; }
goto P_0c0774c0;
P_0c0774c0: /* original 9057, guest PC 0x0c0774c0 */
if(!s->budget--) { s->failed_pc=0x0c0774c0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077572u,2);
goto P_0c0774c2;
P_0c0774c2: /* original d32f, guest PC 0x0c0774c2 */
if(!s->budget--) { s->failed_pc=0x0c0774c2u; return 0; }
r[3]=read(ram,0x0c077580u,4);
goto P_0c0774c4;
P_0c0774c4: /* original 02fe, guest PC 0x0c0774c4 */
if(!s->budget--) { s->failed_pc=0x0c0774c4u; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c0774c6;
P_0c0774c6: /* original 9054, guest PC 0x0c0774c6 */
if(!s->budget--) { s->failed_pc=0x0c0774c6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077572u,2);
goto P_0c0774c8;
P_0c0774c8: /* original 223b, guest PC 0x0c0774c8 */
if(!s->budget--) { s->failed_pc=0x0c0774c8u; return 0; }
r[2]|=r[3];
goto P_0c0774ca;
P_0c0774ca: /* original 0f26, guest PC 0x0c0774ca */
if(!s->budget--) { s->failed_pc=0x0c0774cau; return 0; }
write(ram,r[15]+r[0],r[2],4);
goto P_0c0774cc;
P_0c0774cc: /* original 9052, guest PC 0x0c0774cc */
if(!s->budget--) { s->failed_pc=0x0c0774ccu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077574u,2);
goto P_0c0774ce;
P_0c0774ce: /* original 01ed, guest PC 0x0c0774ce */
if(!s->budget--) { s->failed_pc=0x0c0774ceu; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0774d0;
P_0c0774d0: /* original 611d, guest PC 0x0c0774d0 */
if(!s->budget--) { s->failed_pc=0x0c0774d0u; return 0; }
r[1]=r[1]&65535u;
goto P_0c0774d2;
P_0c0774d2: /* original 1f15, guest PC 0x0c0774d2 */
if(!s->budget--) { s->failed_pc=0x0c0774d2u; return 0; }
write(ram,r[15]+20,r[1],4);
goto P_0c0774d4;
P_0c0774d4: /* original 904f, guest PC 0x0c0774d4 */
if(!s->budget--) { s->failed_pc=0x0c0774d4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077576u,2);
goto P_0c0774d6;
P_0c0774d6: /* original 03ee, guest PC 0x0c0774d6 */
if(!s->budget--) { s->failed_pc=0x0c0774d6u; return 0; }
r[3]=read(ram,r[14]+r[0],4);
goto P_0c0774d8;
P_0c0774d8: /* original 2338, guest PC 0x0c0774d8 */
if(!s->budget--) { s->failed_pc=0x0c0774d8u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0774da;
P_0c0774da: /* original 8953, guest PC 0x0c0774da */
if(!s->budget--) { s->failed_pc=0x0c0774dau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c077584; }
goto P_0c0774dc;
P_0c0774dc: /* original 53f5, guest PC 0x0c0774dc */
if(!s->budget--) { s->failed_pc=0x0c0774dcu; return 0; }
r[3]=read(ram,r[15]+20,4);
goto P_0c0774de;
P_0c0774de: /* original 2338, guest PC 0x0c0774de */
if(!s->budget--) { s->failed_pc=0x0c0774deu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0774e0;
P_0c0774e0: /* original 8950, guest PC 0x0c0774e0 */
if(!s->budget--) { s->failed_pc=0x0c0774e0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c077584; }
goto P_0c0774e2;
P_0c0774e2: /* original 52f5, guest PC 0x0c0774e2 */
if(!s->budget--) { s->failed_pc=0x0c0774e2u; return 0; }
r[2]=read(ram,r[15]+20,4);
goto P_0c0774e4;
P_0c0774e4: /* original 9348, guest PC 0x0c0774e4 */
if(!s->budget--) { s->failed_pc=0x0c0774e4u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077578u,2);
goto P_0c0774e6;
P_0c0774e6: /* original 3230, guest PC 0x0c0774e6 */
if(!s->budget--) { s->failed_pc=0x0c0774e6u; return 0; }
r[17]=(r[17]&~1u)|((r[2]==r[3])!=0);
goto P_0c0774e8;
P_0c0774e8: /* original 8916, guest PC 0x0c0774e8 */
if(!s->budget--) { s->failed_pc=0x0c0774e8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c077518; }
goto P_0c0774ea;
P_0c0774ea: /* original 51f5, guest PC 0x0c0774ea */
if(!s->budget--) { s->failed_pc=0x0c0774eau; return 0; }
r[1]=read(ram,r[15]+20,4);
goto P_0c0774ec;
P_0c0774ec: /* original 9245, guest PC 0x0c0774ec */
if(!s->budget--) { s->failed_pc=0x0c0774ecu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07757au,2);
goto P_0c0774ee;
P_0c0774ee: /* original 3120, guest PC 0x0c0774ee */
if(!s->budget--) { s->failed_pc=0x0c0774eeu; return 0; }
r[17]=(r[17]&~1u)|((r[1]==r[2])!=0);
goto P_0c0774f0;
P_0c0774f0: /* original 8b06, guest PC 0x0c0774f0 */
if(!s->budget--) { s->failed_pc=0x0c0774f0u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c077500; }
goto P_0c0774f2;
P_0c0774f2: /* original 9043, guest PC 0x0c0774f2 */
if(!s->budget--) { s->failed_pc=0x0c0774f2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07757cu,2);
goto P_0c0774f4;
P_0c0774f4: /* original 01ec, guest PC 0x0c0774f4 */
if(!s->budget--) { s->failed_pc=0x0c0774f4u; return 0; }
r[1]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0774f6;
P_0c0774f6: /* original 611c, guest PC 0x0c0774f6 */
if(!s->budget--) { s->failed_pc=0x0c0774f6u; return 0; }
r[1]=r[1]&255u;
goto P_0c0774f8;
P_0c0774f8: /* original 4115, guest PC 0x0c0774f8 */
if(!s->budget--) { s->failed_pc=0x0c0774f8u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[1]>0)!=0);
goto P_0c0774fa;
P_0c0774fa: /* original 8b0a, guest PC 0x0c0774fa */
if(!s->budget--) { s->failed_pc=0x0c0774fau; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c077512; }
goto P_0c0774fc;
P_0c0774fc: /* original a49c, guest PC 0x0c0774fc */
if(!s->budget--) { s->failed_pc=0x0c0774fcu; return 0; }
goto P_0c077e38;
P_0c0774fe: /* original 0009, guest PC 0x0c0774fe */
if(!s->budget--) { s->failed_pc=0x0c0774feu; return 0; }
goto P_0c077500;
P_0c077500: /* original e03e, guest PC 0x0c077500 */
if(!s->budget--) { s->failed_pc=0x0c077500u; return 0; }
r[0]=0x0000003eu;
goto P_0c077502;
P_0c077502: /* original 53f5, guest PC 0x0c077502 */
if(!s->budget--) { s->failed_pc=0x0c077502u; return 0; }
r[3]=read(ram,r[15]+20,4);
goto P_0c077504;
P_0c077504: /* original 02ed, guest PC 0x0c077504 */
if(!s->budget--) { s->failed_pc=0x0c077504u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c077506;
P_0c077506: /* original 622d, guest PC 0x0c077506 */
if(!s->budget--) { s->failed_pc=0x0c077506u; return 0; }
r[2]=r[2]&65535u;
goto P_0c077508;
P_0c077508: /* original 7201, guest PC 0x0c077508 */
if(!s->budget--) { s->failed_pc=0x0c077508u; return 0; }
r[2]+=0x00000001u;
goto P_0c07750a;
P_0c07750a: /* original 3232, guest PC 0x0c07750a */
if(!s->budget--) { s->failed_pc=0x0c07750au; return 0; }
r[17]=(r[17]&~1u)|((r[2]>=r[3])!=0);
goto P_0c07750c;
P_0c07750c: /* original 8901, guest PC 0x0c07750c */
if(!s->budget--) { s->failed_pc=0x0c07750cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c077512; }
goto P_0c07750e;
P_0c07750e: /* original a493, guest PC 0x0c07750e */
if(!s->budget--) { s->failed_pc=0x0c07750eu; return 0; }
goto P_0c077e38;
P_0c077510: /* original 0009, guest PC 0x0c077510 */
if(!s->budget--) { s->failed_pc=0x0c077510u; return 0; }
goto P_0c077512;
P_0c077512: /* original 902f, guest PC 0x0c077512 */
if(!s->budget--) { s->failed_pc=0x0c077512u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077574u,2);
goto P_0c077514;
P_0c077514: /* original e200, guest PC 0x0c077514 */
if(!s->budget--) { s->failed_pc=0x0c077514u; return 0; }
r[2]=0x00000000u;
goto P_0c077516;
P_0c077516: /* original 0e25, guest PC 0x0c077516 */
if(!s->budget--) { s->failed_pc=0x0c077516u; return 0; }
write(ram,r[14]+r[0],r[2],2);
goto P_0c077518;
P_0c077518: /* original e050, guest PC 0x0c077518 */
if(!s->budget--) { s->failed_pc=0x0c077518u; return 0; }
r[0]=0x00000050u;
goto P_0c07751a;
P_0c07751a: /* original 66d3, guest PC 0x0c07751a */
if(!s->budget--) { s->failed_pc=0x0c07751au; return 0; }
r[6]=r[13];
goto P_0c07751c;
P_0c07751c: /* original 03fe, guest PC 0x0c07751c */
if(!s->budget--) { s->failed_pc=0x0c07751cu; return 0; }
r[3]=read(ram,r[15]+r[0],4);
goto P_0c07751e;
P_0c07751e: /* original e04c, guest PC 0x0c07751e */
if(!s->budget--) { s->failed_pc=0x0c07751eu; return 0; }
r[0]=0x0000004cu;
goto P_0c077520;
P_0c077520: /* original 2f36, guest PC 0x0c077520 */
if(!s->budget--) { s->failed_pc=0x0c077520u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c077522;
P_0c077522: /* original 52f2, guest PC 0x0c077522 */
if(!s->budget--) { s->failed_pc=0x0c077522u; return 0; }
r[2]=read(ram,r[15]+8,4);
goto P_0c077524;
P_0c077524: /* original 2f26, guest PC 0x0c077524 */
if(!s->budget--) { s->failed_pc=0x0c077524u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c077526;
P_0c077526: /* original 03fe, guest PC 0x0c077526 */
if(!s->budget--) { s->failed_pc=0x0c077526u; return 0; }
r[3]=read(ram,r[15]+r[0],4);
goto P_0c077528;
P_0c077528: /* original e04c, guest PC 0x0c077528 */
if(!s->budget--) { s->failed_pc=0x0c077528u; return 0; }
r[0]=0x0000004cu;
goto P_0c07752a;
P_0c07752a: /* original 2f36, guest PC 0x0c07752a */
if(!s->budget--) { s->failed_pc=0x0c07752au; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07752c;
P_0c07752c: /* original 02fe, guest PC 0x0c07752c */
if(!s->budget--) { s->failed_pc=0x0c07752cu; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c07752e;
P_0c07752e: /* original 2f26, guest PC 0x0c07752e */
if(!s->budget--) { s->failed_pc=0x0c07752eu; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c077530;
P_0c077530: /* original 901c, guest PC 0x0c077530 */
if(!s->budget--) { s->failed_pc=0x0c077530u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07756cu,2);
goto P_0c077532;
P_0c077532: /* original 03fe, guest PC 0x0c077532 */
if(!s->budget--) { s->failed_pc=0x0c077532u; return 0; }
r[3]=read(ram,r[15]+r[0],4);
goto P_0c077534;
P_0c077534: /* original e05c, guest PC 0x0c077534 */
if(!s->budget--) { s->failed_pc=0x0c077534u; return 0; }
r[0]=0x0000005cu;
goto P_0c077536;
P_0c077536: /* original 2f36, guest PC 0x0c077536 */
if(!s->budget--) { s->failed_pc=0x0c077536u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c077538;
P_0c077538: /* original 02fe, guest PC 0x0c077538 */
if(!s->budget--) { s->failed_pc=0x0c077538u; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c07753a;
P_0c07753a: /* original 2f26, guest PC 0x0c07753a */
if(!s->budget--) { s->failed_pc=0x0c07753au; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07753c;
P_0c07753c: /* original 9317, guest PC 0x0c07753c */
if(!s->budget--) { s->failed_pc=0x0c07753cu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07756eu,2);
goto P_0c07753e;
P_0c07753e: /* original 33fc, guest PC 0x0c07753e */
if(!s->budget--) { s->failed_pc=0x0c07753eu; return 0; }
r[3]+=r[15];
goto P_0c077540;
P_0c077540: /* original 2f36, guest PC 0x0c077540 */
if(!s->budget--) { s->failed_pc=0x0c077540u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c077542;
P_0c077542: /* original 9014, guest PC 0x0c077542 */
if(!s->budget--) { s->failed_pc=0x0c077542u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07756eu,2);
goto P_0c077544;
P_0c077544: /* original 02fe, guest PC 0x0c077544 */
if(!s->budget--) { s->failed_pc=0x0c077544u; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c077546;
P_0c077546: /* original 2f26, guest PC 0x0c077546 */
if(!s->budget--) { s->failed_pc=0x0c077546u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c077548;
P_0c077548: /* original 9010, guest PC 0x0c077548 */
if(!s->budget--) { s->failed_pc=0x0c077548u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07756cu,2);
goto P_0c07754a;
P_0c07754a: /* original 03fe, guest PC 0x0c07754a */
if(!s->budget--) { s->failed_pc=0x0c07754au; return 0; }
r[3]=read(ram,r[15]+r[0],4);
goto P_0c07754c;
P_0c07754c: /* original 2f36, guest PC 0x0c07754c */
if(!s->budget--) { s->failed_pc=0x0c07754cu; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07754e;
P_0c07754e: /* original 900f, guest PC 0x0c07754e */
if(!s->budget--) { s->failed_pc=0x0c07754eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077570u,2);
goto P_0c077550;
P_0c077550: /* original 02fe, guest PC 0x0c077550 */
if(!s->budget--) { s->failed_pc=0x0c077550u; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c077552;
P_0c077552: /* original 2f26, guest PC 0x0c077552 */
if(!s->budget--) { s->failed_pc=0x0c077552u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c077554;
P_0c077554: /* original 970c, guest PC 0x0c077554 */
if(!s->budget--) { s->failed_pc=0x0c077554u; return 0; }
r[7]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077570u,2);
goto P_0c077556;
P_0c077556: /* original 37fc, guest PC 0x0c077556 */
if(!s->budget--) { s->failed_pc=0x0c077556u; return 0; }
r[7]+=r[15];
goto P_0c077558;
P_0c077558: /* original 65e3, guest PC 0x0c077558 */
if(!s->budget--) { s->failed_pc=0x0c077558u; return 0; }
r[5]=r[14];
goto P_0c07755a;
P_0c07755a: /* original b680, guest PC 0x0c07755a */
if(!s->budget--) { s->failed_pc=0x0c07755au; return 0; }
target=0x0c07825eu; r[16]=0x8c07755eu;
r[4]=r[12];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07755eu) { target=s->pc; goto dispatch; }
goto P_0c07755e;
P_0c07755c: /* original 64c3, guest PC 0x0c07755c */
if(!s->budget--) { s->failed_pc=0x0c07755cu; return 0; }
r[4]=r[12];
goto P_0c07755e;
P_0c07755e: /* original 2008, guest PC 0x0c07755e */
if(!s->budget--) { s->failed_pc=0x0c07755eu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c077560;
P_0c077560: /* original 8d02, guest PC 0x0c077560 */
if(!s->budget--) { s->failed_pc=0x0c077560u; return 0; }
cond=r[17]&1u;
r[15]+=0x00000028u;
if(cond) { goto P_0c077568; }
goto P_0c077564;
P_0c077562: /* original 7f28, guest PC 0x0c077562 */
if(!s->budget--) { s->failed_pc=0x0c077562u; return 0; }
r[15]+=0x00000028u;
goto P_0c077564;
P_0c077564: /* original a46c, guest PC 0x0c077564 */
if(!s->budget--) { s->failed_pc=0x0c077564u; return 0; }
goto P_0c077e40;
P_0c077566: /* original 0009, guest PC 0x0c077566 */
if(!s->budget--) { s->failed_pc=0x0c077566u; return 0; }
goto P_0c077568;
P_0c077568: /* original a455, guest PC 0x0c077568 */
if(!s->budget--) { s->failed_pc=0x0c077568u; return 0; }
goto P_0c077e16;
P_0c07756a: /* original 0009, guest PC 0x0c07756a */
if(!s->budget--) { s->failed_pc=0x0c07756au; return 0; }
return vf3_matrix_family(0x0c07756cu,s,ram);
P_0c077584: /* original 903b, guest PC 0x0c077584 */
if(!s->budget--) { s->failed_pc=0x0c077584u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0775feu,2);
goto P_0c077586;
P_0c077586: /* original e300, guest PC 0x0c077586 */
if(!s->budget--) { s->failed_pc=0x0c077586u; return 0; }
r[3]=0x00000000u;
goto P_0c077588;
P_0c077588: /* original 0e34, guest PC 0x0c077588 */
if(!s->budget--) { s->failed_pc=0x0c077588u; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c07758a;
P_0c07758a: /* original 9039, guest PC 0x0c07758a */
if(!s->budget--) { s->failed_pc=0x0c07758au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077600u,2);
goto P_0c07758c;
P_0c07758c: /* original d31f, guest PC 0x0c07758c */
if(!s->budget--) { s->failed_pc=0x0c07758cu; return 0; }
r[3]=read(ram,0x0c07760cu,4);
goto P_0c07758e;
P_0c07758e: /* original 02fe, guest PC 0x0c07758e */
if(!s->budget--) { s->failed_pc=0x0c07758eu; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c077590;
P_0c077590: /* original 2238, guest PC 0x0c077590 */
if(!s->budget--) { s->failed_pc=0x0c077590u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c077592;
P_0c077592: /* original 893f, guest PC 0x0c077592 */
if(!s->budget--) { s->failed_pc=0x0c077592u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c077614; }
goto P_0c077594;
P_0c077594: /* original 9035, guest PC 0x0c077594 */
if(!s->budget--) { s->failed_pc=0x0c077594u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077602u,2);
goto P_0c077596;
P_0c077596: /* original 02ee, guest PC 0x0c077596 */
if(!s->budget--) { s->failed_pc=0x0c077596u; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c077598;
P_0c077598: /* original 2228, guest PC 0x0c077598 */
if(!s->budget--) { s->failed_pc=0x0c077598u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c07759a;
P_0c07759a: /* original 8b6a, guest PC 0x0c07759a */
if(!s->budget--) { s->failed_pc=0x0c07759au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c077672; }
goto P_0c07759c;
P_0c07759c: /* original e070, guest PC 0x0c07759c */
if(!s->budget--) { s->failed_pc=0x0c07759cu; return 0; }
r[0]=0x00000070u;
goto P_0c07759e;
P_0c07759e: /* original 01fe, guest PC 0x0c07759e */
if(!s->budget--) { s->failed_pc=0x0c07759eu; return 0; }
r[1]=read(ram,r[15]+r[0],4);
goto P_0c0775a0;
P_0c0775a0: /* original 2118, guest PC 0x0c0775a0 */
if(!s->budget--) { s->failed_pc=0x0c0775a0u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[1])==0)!=0);
goto P_0c0775a2;
P_0c0775a2: /* original 8b66, guest PC 0x0c0775a2 */
if(!s->budget--) { s->failed_pc=0x0c0775a2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c077672; }
goto P_0c0775a4;
P_0c0775a4: /* original 902c, guest PC 0x0c0775a4 */
if(!s->budget--) { s->failed_pc=0x0c0775a4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077600u,2);
goto P_0c0775a6;
P_0c0775a6: /* original d31a, guest PC 0x0c0775a6 */
if(!s->budget--) { s->failed_pc=0x0c0775a6u; return 0; }
r[3]=read(ram,0x0c077610u,4);
goto P_0c0775a8;
P_0c0775a8: /* original 01fe, guest PC 0x0c0775a8 */
if(!s->budget--) { s->failed_pc=0x0c0775a8u; return 0; }
r[1]=read(ram,r[15]+r[0],4);
goto P_0c0775aa;
P_0c0775aa: /* original 2138, guest PC 0x0c0775aa */
if(!s->budget--) { s->failed_pc=0x0c0775aau; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[3])==0)!=0);
goto P_0c0775ac;
P_0c0775ac: /* original 8901, guest PC 0x0c0775ac */
if(!s->budget--) { s->failed_pc=0x0c0775acu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0775b2; }
goto P_0c0775ae;
P_0c0775ae: /* original a443, guest PC 0x0c0775ae */
if(!s->budget--) { s->failed_pc=0x0c0775aeu; return 0; }
goto P_0c077e38;
P_0c0775b0: /* original 0009, guest PC 0x0c0775b0 */
if(!s->budget--) { s->failed_pc=0x0c0775b0u; return 0; }
goto P_0c0775b2;
P_0c0775b2: /* original 9027, guest PC 0x0c0775b2 */
if(!s->budget--) { s->failed_pc=0x0c0775b2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077604u,2);
goto P_0c0775b4;
P_0c0775b4: /* original 03ec, guest PC 0x0c0775b4 */
if(!s->budget--) { s->failed_pc=0x0c0775b4u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0775b6;
P_0c0775b6: /* original 633c, guest PC 0x0c0775b6 */
if(!s->budget--) { s->failed_pc=0x0c0775b6u; return 0; }
r[3]=r[3]&255u;
goto P_0c0775b8;
P_0c0775b8: /* original 1f38, guest PC 0x0c0775b8 */
if(!s->budget--) { s->failed_pc=0x0c0775b8u; return 0; }
write(ram,r[15]+32,r[3],4);
goto P_0c0775ba;
P_0c0775ba: /* original 9024, guest PC 0x0c0775ba */
if(!s->budget--) { s->failed_pc=0x0c0775bau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077606u,2);
goto P_0c0775bc;
P_0c0775bc: /* original 02ec, guest PC 0x0c0775bc */
if(!s->budget--) { s->failed_pc=0x0c0775bcu; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0775be;
P_0c0775be: /* original e06c, guest PC 0x0c0775be */
if(!s->budget--) { s->failed_pc=0x0c0775beu; return 0; }
r[0]=0x0000006cu;
goto P_0c0775c0;
P_0c0775c0: /* original 622c, guest PC 0x0c0775c0 */
if(!s->budget--) { s->failed_pc=0x0c0775c0u; return 0; }
r[2]=r[2]&255u;
goto P_0c0775c2;
P_0c0775c2: /* original 1f27, guest PC 0x0c0775c2 */
if(!s->budget--) { s->failed_pc=0x0c0775c2u; return 0; }
write(ram,r[15]+28,r[2],4);
goto P_0c0775c4;
P_0c0775c4: /* original 53f8, guest PC 0x0c0775c4 */
if(!s->budget--) { s->failed_pc=0x0c0775c4u; return 0; }
r[3]=read(ram,r[15]+32,4);
goto P_0c0775c6;
P_0c0775c6: /* original 3328, guest PC 0x0c0775c6 */
if(!s->budget--) { s->failed_pc=0x0c0775c6u; return 0; }
r[3]-=r[2];
goto P_0c0775c8;
P_0c0775c8: /* original 1f36, guest PC 0x0c0775c8 */
if(!s->budget--) { s->failed_pc=0x0c0775c8u; return 0; }
write(ram,r[15]+24,r[3],4);
goto P_0c0775ca;
P_0c0775ca: /* original e30c, guest PC 0x0c0775ca */
if(!s->budget--) { s->failed_pc=0x0c0775cau; return 0; }
r[3]=0x0000000cu;
goto P_0c0775cc;
P_0c0775cc: /* original 0f36, guest PC 0x0c0775cc */
if(!s->budget--) { s->failed_pc=0x0c0775ccu; return 0; }
write(ram,r[15]+r[0],r[3],4);
goto P_0c0775ce;
P_0c0775ce: /* original e04c, guest PC 0x0c0775ce */
if(!s->budget--) { s->failed_pc=0x0c0775ceu; return 0; }
r[0]=0x0000004cu;
goto P_0c0775d0;
P_0c0775d0: /* original 02ee, guest PC 0x0c0775d0 */
if(!s->budget--) { s->failed_pc=0x0c0775d0u; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c0775d2;
P_0c0775d2: /* original 9319, guest PC 0x0c0775d2 */
if(!s->budget--) { s->failed_pc=0x0c0775d2u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077608u,2);
goto P_0c0775d4;
P_0c0775d4: /* original 2238, guest PC 0x0c0775d4 */
if(!s->budget--) { s->failed_pc=0x0c0775d4u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0775d6;
P_0c0775d6: /* original 8902, guest PC 0x0c0775d6 */
if(!s->budget--) { s->failed_pc=0x0c0775d6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0775de; }
goto P_0c0775d8;
P_0c0775d8: /* original e06c, guest PC 0x0c0775d8 */
if(!s->budget--) { s->failed_pc=0x0c0775d8u; return 0; }
r[0]=0x0000006cu;
goto P_0c0775da;
P_0c0775da: /* original e20d, guest PC 0x0c0775da */
if(!s->budget--) { s->failed_pc=0x0c0775dau; return 0; }
r[2]=0x0000000du;
goto P_0c0775dc;
P_0c0775dc: /* original 0f26, guest PC 0x0c0775dc */
if(!s->budget--) { s->failed_pc=0x0c0775dcu; return 0; }
write(ram,r[15]+r[0],r[2],4);
goto P_0c0775de;
P_0c0775de: /* original e06c, guest PC 0x0c0775de */
if(!s->budget--) { s->failed_pc=0x0c0775deu; return 0; }
r[0]=0x0000006cu;
goto P_0c0775e0;
P_0c0775e0: /* original 51f6, guest PC 0x0c0775e0 */
if(!s->budget--) { s->failed_pc=0x0c0775e0u; return 0; }
r[1]=read(ram,r[15]+24,4);
goto P_0c0775e2;
P_0c0775e2: /* original 03fe, guest PC 0x0c0775e2 */
if(!s->budget--) { s->failed_pc=0x0c0775e2u; return 0; }
r[3]=read(ram,r[15]+r[0],4);
goto P_0c0775e4;
P_0c0775e4: /* original 3136, guest PC 0x0c0775e4 */
if(!s->budget--) { s->failed_pc=0x0c0775e4u; return 0; }
r[17]=(r[17]&~1u)|((r[1]>r[3])!=0);
goto P_0c0775e6;
P_0c0775e6: /* original 8b00, guest PC 0x0c0775e6 */
if(!s->budget--) { s->failed_pc=0x0c0775e6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0775ea; }
goto P_0c0775e8;
P_0c0775e8: /* original 1f36, guest PC 0x0c0775e8 */
if(!s->budget--) { s->failed_pc=0x0c0775e8u; return 0; }
write(ram,r[15]+24,r[3],4);
goto P_0c0775ea;
P_0c0775ea: /* original 52f8, guest PC 0x0c0775ea */
if(!s->budget--) { s->failed_pc=0x0c0775eau; return 0; }
r[2]=read(ram,r[15]+32,4);
goto P_0c0775ec;
P_0c0775ec: /* original 53f6, guest PC 0x0c0775ec */
if(!s->budget--) { s->failed_pc=0x0c0775ecu; return 0; }
r[3]=read(ram,r[15]+24,4);
goto P_0c0775ee;
P_0c0775ee: /* original 3238, guest PC 0x0c0775ee */
if(!s->budget--) { s->failed_pc=0x0c0775eeu; return 0; }
r[2]-=r[3];
goto P_0c0775f0;
P_0c0775f0: /* original 6023, guest PC 0x0c0775f0 */
if(!s->budget--) { s->failed_pc=0x0c0775f0u; return 0; }
r[0]=r[2];
goto P_0c0775f2;
P_0c0775f2: /* original c93f, guest PC 0x0c0775f2 */
if(!s->budget--) { s->failed_pc=0x0c0775f2u; return 0; }
r[0]&=63u;
goto P_0c0775f4;
P_0c0775f4: /* original 6303, guest PC 0x0c0775f4 */
if(!s->budget--) { s->failed_pc=0x0c0775f4u; return 0; }
r[3]=r[0];
goto P_0c0775f6;
P_0c0775f6: /* original 1f07, guest PC 0x0c0775f6 */
if(!s->budget--) { s->failed_pc=0x0c0775f6u; return 0; }
write(ram,r[15]+28,r[0],4);
goto P_0c0775f8;
P_0c0775f8: /* original 9005, guest PC 0x0c0775f8 */
if(!s->budget--) { s->failed_pc=0x0c0775f8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077606u,2);
goto P_0c0775fa;
P_0c0775fa: /* original a41d, guest PC 0x0c0775fa */
if(!s->budget--) { s->failed_pc=0x0c0775fau; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c077e38;
P_0c0775fc: /* original 0e34, guest PC 0x0c0775fc */
if(!s->budget--) { s->failed_pc=0x0c0775fcu; return 0; }
write(ram,r[14]+r[0],r[3],1);
return vf3_matrix_family(0x0c0775feu,s,ram);
P_0c077614: /* original 90a7, guest PC 0x0c077614 */
if(!s->budget--) { s->failed_pc=0x0c077614u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077766u,2);
goto P_0c077616;
P_0c077616: /* original d357, guest PC 0x0c077616 */
if(!s->budget--) { s->failed_pc=0x0c077616u; return 0; }
r[3]=read(ram,0x0c077774u,4);
goto P_0c077618;
P_0c077618: /* original 02fe, guest PC 0x0c077618 */
if(!s->budget--) { s->failed_pc=0x0c077618u; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c07761a;
P_0c07761a: /* original 2238, guest PC 0x0c07761a */
if(!s->budget--) { s->failed_pc=0x0c07761au; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c07761c;
P_0c07761c: /* original 8b29, guest PC 0x0c07761c */
if(!s->budget--) { s->failed_pc=0x0c07761cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c077672; }
goto P_0c07761e;
P_0c07761e: /* original 90a2, guest PC 0x0c07761e */
if(!s->budget--) { s->failed_pc=0x0c07761eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077766u,2);
goto P_0c077620;
P_0c077620: /* original d255, guest PC 0x0c077620 */
if(!s->budget--) { s->failed_pc=0x0c077620u; return 0; }
r[2]=read(ram,0x0c077778u,4);
goto P_0c077622;
P_0c077622: /* original 01fe, guest PC 0x0c077622 */
if(!s->budget--) { s->failed_pc=0x0c077622u; return 0; }
r[1]=read(ram,r[15]+r[0],4);
goto P_0c077624;
P_0c077624: /* original 2128, guest PC 0x0c077624 */
if(!s->budget--) { s->failed_pc=0x0c077624u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[2])==0)!=0);
goto P_0c077626;
P_0c077626: /* original 8924, guest PC 0x0c077626 */
if(!s->budget--) { s->failed_pc=0x0c077626u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c077672; }
goto P_0c077628;
P_0c077628: /* original 909e, guest PC 0x0c077628 */
if(!s->budget--) { s->failed_pc=0x0c077628u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077768u,2);
goto P_0c07762a;
P_0c07762a: /* original 03ec, guest PC 0x0c07762a */
if(!s->budget--) { s->failed_pc=0x0c07762au; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c07762c;
P_0c07762c: /* original 633c, guest PC 0x0c07762c */
if(!s->budget--) { s->failed_pc=0x0c07762cu; return 0; }
r[3]=r[3]&255u;
goto P_0c07762e;
P_0c07762e: /* original 1f38, guest PC 0x0c07762e */
if(!s->budget--) { s->failed_pc=0x0c07762eu; return 0; }
write(ram,r[15]+32,r[3],4);
goto P_0c077630;
P_0c077630: /* original 909b, guest PC 0x0c077630 */
if(!s->budget--) { s->failed_pc=0x0c077630u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07776au,2);
goto P_0c077632;
P_0c077632: /* original 02ec, guest PC 0x0c077632 */
if(!s->budget--) { s->failed_pc=0x0c077632u; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c077634;
P_0c077634: /* original e06c, guest PC 0x0c077634 */
if(!s->budget--) { s->failed_pc=0x0c077634u; return 0; }
r[0]=0x0000006cu;
goto P_0c077636;
P_0c077636: /* original 622c, guest PC 0x0c077636 */
if(!s->budget--) { s->failed_pc=0x0c077636u; return 0; }
r[2]=r[2]&255u;
goto P_0c077638;
P_0c077638: /* original 1f27, guest PC 0x0c077638 */
if(!s->budget--) { s->failed_pc=0x0c077638u; return 0; }
write(ram,r[15]+28,r[2],4);
goto P_0c07763a;
P_0c07763a: /* original 53f8, guest PC 0x0c07763a */
if(!s->budget--) { s->failed_pc=0x0c07763au; return 0; }
r[3]=read(ram,r[15]+32,4);
goto P_0c07763c;
P_0c07763c: /* original 3328, guest PC 0x0c07763c */
if(!s->budget--) { s->failed_pc=0x0c07763cu; return 0; }
r[3]-=r[2];
goto P_0c07763e;
P_0c07763e: /* original 1f36, guest PC 0x0c07763e */
if(!s->budget--) { s->failed_pc=0x0c07763eu; return 0; }
write(ram,r[15]+24,r[3],4);
goto P_0c077640;
P_0c077640: /* original e30c, guest PC 0x0c077640 */
if(!s->budget--) { s->failed_pc=0x0c077640u; return 0; }
r[3]=0x0000000cu;
goto P_0c077642;
P_0c077642: /* original 0f36, guest PC 0x0c077642 */
if(!s->budget--) { s->failed_pc=0x0c077642u; return 0; }
write(ram,r[15]+r[0],r[3],4);
goto P_0c077644;
P_0c077644: /* original e04c, guest PC 0x0c077644 */
if(!s->budget--) { s->failed_pc=0x0c077644u; return 0; }
r[0]=0x0000004cu;
goto P_0c077646;
P_0c077646: /* original 02ee, guest PC 0x0c077646 */
if(!s->budget--) { s->failed_pc=0x0c077646u; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c077648;
P_0c077648: /* original 9390, guest PC 0x0c077648 */
if(!s->budget--) { s->failed_pc=0x0c077648u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07776cu,2);
goto P_0c07764a;
P_0c07764a: /* original 2238, guest PC 0x0c07764a */
if(!s->budget--) { s->failed_pc=0x0c07764au; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c07764c;
P_0c07764c: /* original 8902, guest PC 0x0c07764c */
if(!s->budget--) { s->failed_pc=0x0c07764cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c077654; }
goto P_0c07764e;
P_0c07764e: /* original e06c, guest PC 0x0c07764e */
if(!s->budget--) { s->failed_pc=0x0c07764eu; return 0; }
r[0]=0x0000006cu;
goto P_0c077650;
P_0c077650: /* original e20d, guest PC 0x0c077650 */
if(!s->budget--) { s->failed_pc=0x0c077650u; return 0; }
r[2]=0x0000000du;
goto P_0c077652;
P_0c077652: /* original 0f26, guest PC 0x0c077652 */
if(!s->budget--) { s->failed_pc=0x0c077652u; return 0; }
write(ram,r[15]+r[0],r[2],4);
goto P_0c077654;
P_0c077654: /* original e06c, guest PC 0x0c077654 */
if(!s->budget--) { s->failed_pc=0x0c077654u; return 0; }
r[0]=0x0000006cu;
goto P_0c077656;
P_0c077656: /* original 51f6, guest PC 0x0c077656 */
if(!s->budget--) { s->failed_pc=0x0c077656u; return 0; }
r[1]=read(ram,r[15]+24,4);
goto P_0c077658;
P_0c077658: /* original 03fe, guest PC 0x0c077658 */
if(!s->budget--) { s->failed_pc=0x0c077658u; return 0; }
r[3]=read(ram,r[15]+r[0],4);
goto P_0c07765a;
P_0c07765a: /* original 3136, guest PC 0x0c07765a */
if(!s->budget--) { s->failed_pc=0x0c07765au; return 0; }
r[17]=(r[17]&~1u)|((r[1]>r[3])!=0);
goto P_0c07765c;
P_0c07765c: /* original 8b00, guest PC 0x0c07765c */
if(!s->budget--) { s->failed_pc=0x0c07765cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c077660; }
goto P_0c07765e;
P_0c07765e: /* original 1f36, guest PC 0x0c07765e */
if(!s->budget--) { s->failed_pc=0x0c07765eu; return 0; }
write(ram,r[15]+24,r[3],4);
goto P_0c077660;
P_0c077660: /* original 52f8, guest PC 0x0c077660 */
if(!s->budget--) { s->failed_pc=0x0c077660u; return 0; }
r[2]=read(ram,r[15]+32,4);
goto P_0c077662;
P_0c077662: /* original 53f6, guest PC 0x0c077662 */
if(!s->budget--) { s->failed_pc=0x0c077662u; return 0; }
r[3]=read(ram,r[15]+24,4);
goto P_0c077664;
P_0c077664: /* original 3238, guest PC 0x0c077664 */
if(!s->budget--) { s->failed_pc=0x0c077664u; return 0; }
r[2]-=r[3];
goto P_0c077666;
P_0c077666: /* original 6023, guest PC 0x0c077666 */
if(!s->budget--) { s->failed_pc=0x0c077666u; return 0; }
r[0]=r[2];
goto P_0c077668;
P_0c077668: /* original c93f, guest PC 0x0c077668 */
if(!s->budget--) { s->failed_pc=0x0c077668u; return 0; }
r[0]&=63u;
goto P_0c07766a;
P_0c07766a: /* original 6303, guest PC 0x0c07766a */
if(!s->budget--) { s->failed_pc=0x0c07766au; return 0; }
r[3]=r[0];
goto P_0c07766c;
P_0c07766c: /* original 1f07, guest PC 0x0c07766c */
if(!s->budget--) { s->failed_pc=0x0c07766cu; return 0; }
write(ram,r[15]+28,r[0],4);
goto P_0c07766e;
P_0c07766e: /* original 907e, guest PC 0x0c07766e */
if(!s->budget--) { s->failed_pc=0x0c07766eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07776eu,2);
goto P_0c077670;
P_0c077670: /* original 0e34, guest PC 0x0c077670 */
if(!s->budget--) { s->failed_pc=0x0c077670u; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c077672;
P_0c077672: /* original 9079, guest PC 0x0c077672 */
if(!s->budget--) { s->failed_pc=0x0c077672u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077768u,2);
goto P_0c077674;
P_0c077674: /* original 61f3, guest PC 0x0c077674 */
if(!s->budget--) { s->failed_pc=0x0c077674u; return 0; }
r[1]=r[15];
goto P_0c077676;
P_0c077676: /* original 716c, guest PC 0x0c077676 */
if(!s->budget--) { s->failed_pc=0x0c077676u; return 0; }
r[1]+=0x0000006cu;
goto P_0c077678;
P_0c077678: /* original 02ec, guest PC 0x0c077678 */
if(!s->budget--) { s->failed_pc=0x0c077678u; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c07767a;
P_0c07767a: /* original 622c, guest PC 0x0c07767a */
if(!s->budget--) { s->failed_pc=0x0c07767au; return 0; }
r[2]=r[2]&255u;
goto P_0c07767c;
P_0c07767c: /* original 1f27, guest PC 0x0c07767c */
if(!s->budget--) { s->failed_pc=0x0c07767cu; return 0; }
write(ram,r[15]+28,r[2],4);
goto P_0c07767e;
P_0c07767e: /* original 9076, guest PC 0x0c07767e */
if(!s->budget--) { s->failed_pc=0x0c07767eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07776eu,2);
goto P_0c077680;
P_0c077680: /* original 03ec, guest PC 0x0c077680 */
if(!s->budget--) { s->failed_pc=0x0c077680u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c077682;
P_0c077682: /* original 633c, guest PC 0x0c077682 */
if(!s->budget--) { s->failed_pc=0x0c077682u; return 0; }
r[3]=r[3]&255u;
goto P_0c077684;
P_0c077684: /* original 6233, guest PC 0x0c077684 */
if(!s->budget--) { s->failed_pc=0x0c077684u; return 0; }
r[2]=r[3];
goto P_0c077686;
P_0c077686: /* original 7201, guest PC 0x0c077686 */
if(!s->budget--) { s->failed_pc=0x0c077686u; return 0; }
r[2]+=0x00000001u;
goto P_0c077688;
P_0c077688: /* original 6023, guest PC 0x0c077688 */
if(!s->budget--) { s->failed_pc=0x0c077688u; return 0; }
r[0]=r[2];
goto P_0c07768a;
P_0c07768a: /* original c93f, guest PC 0x0c07768a */
if(!s->budget--) { s->failed_pc=0x0c07768au; return 0; }
r[0]&=63u;
goto P_0c07768c;
P_0c07768c: /* original 2102, guest PC 0x0c07768c */
if(!s->budget--) { s->failed_pc=0x0c07768cu; return 0; }
write(ram,r[1],r[0],4);
goto P_0c07768e;
P_0c07768e: /* original 53f7, guest PC 0x0c07768e */
if(!s->budget--) { s->failed_pc=0x0c07768eu; return 0; }
r[3]=read(ram,r[15]+28,4);
goto P_0c077690;
P_0c077690: /* original 3030, guest PC 0x0c077690 */
if(!s->budget--) { s->failed_pc=0x0c077690u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==r[3])!=0);
goto P_0c077692;
P_0c077692: /* original 8945, guest PC 0x0c077692 */
if(!s->budget--) { s->failed_pc=0x0c077692u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c077720; }
goto P_0c077694;
P_0c077694: /* original 906b, guest PC 0x0c077694 */
if(!s->budget--) { s->failed_pc=0x0c077694u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07776eu,2);
goto P_0c077696;
P_0c077696: /* original 01ec, guest PC 0x0c077696 */
if(!s->budget--) { s->failed_pc=0x0c077696u; return 0; }
r[1]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c077698;
P_0c077698: /* original 611c, guest PC 0x0c077698 */
if(!s->budget--) { s->failed_pc=0x0c077698u; return 0; }
r[1]=r[1]&255u;
goto P_0c07769a;
P_0c07769a: /* original 4108, guest PC 0x0c07769a */
if(!s->budget--) { s->failed_pc=0x0c07769au; return 0; }
r[1]<<=2;
goto P_0c07769c;
P_0c07769c: /* original 6313, guest PC 0x0c07769c */
if(!s->budget--) { s->failed_pc=0x0c07769cu; return 0; }
r[3]=r[1];
goto P_0c07769e;
P_0c07769e: /* original 1f15, guest PC 0x0c07769e */
if(!s->budget--) { s->failed_pc=0x0c07769eu; return 0; }
write(ram,r[15]+20,r[1],4);
goto P_0c0776a0;
P_0c0776a0: /* original 9266, guest PC 0x0c0776a0 */
if(!s->budget--) { s->failed_pc=0x0c0776a0u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077770u,2);
goto P_0c0776a2;
P_0c0776a2: /* original 32ec, guest PC 0x0c0776a2 */
if(!s->budget--) { s->failed_pc=0x0c0776a2u; return 0; }
r[2]+=r[14];
goto P_0c0776a4;
P_0c0776a4: /* original 323c, guest PC 0x0c0776a4 */
if(!s->budget--) { s->failed_pc=0x0c0776a4u; return 0; }
r[2]+=r[3];
goto P_0c0776a6;
P_0c0776a6: /* original 6120, guest PC 0x0c0776a6 */
if(!s->budget--) { s->failed_pc=0x0c0776a6u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[2],1);
r[1]=tmp;
goto P_0c0776a8;
P_0c0776a8: /* original 611c, guest PC 0x0c0776a8 */
if(!s->budget--) { s->failed_pc=0x0c0776a8u; return 0; }
r[1]=r[1]&255u;
goto P_0c0776aa;
P_0c0776aa: /* original 1f11, guest PC 0x0c0776aa */
if(!s->budget--) { s->failed_pc=0x0c0776aau; return 0; }
write(ram,r[15]+4,r[1],4);
goto P_0c0776ac;
P_0c0776ac: /* original 61f3, guest PC 0x0c0776ac */
if(!s->budget--) { s->failed_pc=0x0c0776acu; return 0; }
r[1]=r[15];
goto P_0c0776ae;
P_0c0776ae: /* original 925f, guest PC 0x0c0776ae */
if(!s->budget--) { s->failed_pc=0x0c0776aeu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077770u,2);
goto P_0c0776b0;
P_0c0776b0: /* original 7150, guest PC 0x0c0776b0 */
if(!s->budget--) { s->failed_pc=0x0c0776b0u; return 0; }
r[1]+=0x00000050u;
goto P_0c0776b2;
P_0c0776b2: /* original 53f5, guest PC 0x0c0776b2 */
if(!s->budget--) { s->failed_pc=0x0c0776b2u; return 0; }
r[3]=read(ram,r[15]+20,4);
goto P_0c0776b4;
P_0c0776b4: /* original 32ec, guest PC 0x0c0776b4 */
if(!s->budget--) { s->failed_pc=0x0c0776b4u; return 0; }
r[2]+=r[14];
goto P_0c0776b6;
P_0c0776b6: /* original 323c, guest PC 0x0c0776b6 */
if(!s->budget--) { s->failed_pc=0x0c0776b6u; return 0; }
r[2]+=r[3];
goto P_0c0776b8;
P_0c0776b8: /* original 8422, guest PC 0x0c0776b8 */
if(!s->budget--) { s->failed_pc=0x0c0776b8u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[2]+2,1);
goto P_0c0776ba;
P_0c0776ba: /* original 600c, guest PC 0x0c0776ba */
if(!s->budget--) { s->failed_pc=0x0c0776bau; return 0; }
r[0]=r[0]&255u;
goto P_0c0776bc;
P_0c0776bc: /* original 2102, guest PC 0x0c0776bc */
if(!s->budget--) { s->failed_pc=0x0c0776bcu; return 0; }
write(ram,r[1],r[0],4);
goto P_0c0776be;
P_0c0776be: /* original 9257, guest PC 0x0c0776be */
if(!s->budget--) { s->failed_pc=0x0c0776beu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077770u,2);
goto P_0c0776c0;
P_0c0776c0: /* original 53f5, guest PC 0x0c0776c0 */
if(!s->budget--) { s->failed_pc=0x0c0776c0u; return 0; }
r[3]=read(ram,r[15]+20,4);
goto P_0c0776c2;
P_0c0776c2: /* original 32ec, guest PC 0x0c0776c2 */
if(!s->budget--) { s->failed_pc=0x0c0776c2u; return 0; }
r[2]+=r[14];
goto P_0c0776c4;
P_0c0776c4: /* original 323c, guest PC 0x0c0776c4 */
if(!s->budget--) { s->failed_pc=0x0c0776c4u; return 0; }
r[2]+=r[3];
goto P_0c0776c6;
P_0c0776c6: /* original 8423, guest PC 0x0c0776c6 */
if(!s->budget--) { s->failed_pc=0x0c0776c6u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[2]+3,1);
goto P_0c0776c8;
P_0c0776c8: /* original 600c, guest PC 0x0c0776c8 */
if(!s->budget--) { s->failed_pc=0x0c0776c8u; return 0; }
r[0]=r[0]&255u;
goto P_0c0776ca;
P_0c0776ca: /* original 1f0f, guest PC 0x0c0776ca */
if(!s->budget--) { s->failed_pc=0x0c0776cau; return 0; }
write(ram,r[15]+60,r[0],4);
goto P_0c0776cc;
P_0c0776cc: /* original 9051, guest PC 0x0c0776cc */
if(!s->budget--) { s->failed_pc=0x0c0776ccu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077772u,2);
goto P_0c0776ce;
P_0c0776ce: /* original d32b, guest PC 0x0c0776ce */
if(!s->budget--) { s->failed_pc=0x0c0776ceu; return 0; }
r[3]=read(ram,0x0c07777cu,4);
goto P_0c0776d0;
P_0c0776d0: /* original 02fe, guest PC 0x0c0776d0 */
if(!s->budget--) { s->failed_pc=0x0c0776d0u; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c0776d2;
P_0c0776d2: /* original 5121, guest PC 0x0c0776d2 */
if(!s->budget--) { s->failed_pc=0x0c0776d2u; return 0; }
r[1]=read(ram,r[2]+4,4);
goto P_0c0776d4;
P_0c0776d4: /* original 2138, guest PC 0x0c0776d4 */
if(!s->budget--) { s->failed_pc=0x0c0776d4u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[3])==0)!=0);
goto P_0c0776d6;
P_0c0776d6: /* original 890b, guest PC 0x0c0776d6 */
if(!s->budget--) { s->failed_pc=0x0c0776d6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0776f0; }
goto P_0c0776d8;
P_0c0776d8: /* original 50f1, guest PC 0x0c0776d8 */
if(!s->budget--) { s->failed_pc=0x0c0776d8u; return 0; }
r[0]=read(ram,r[15]+4,4);
goto P_0c0776da;
P_0c0776da: /* original 61f3, guest PC 0x0c0776da */
if(!s->budget--) { s->failed_pc=0x0c0776dau; return 0; }
r[1]=r[15];
goto P_0c0776dc;
P_0c0776dc: /* original 7150, guest PC 0x0c0776dc */
if(!s->budget--) { s->failed_pc=0x0c0776dcu; return 0; }
r[1]+=0x00000050u;
goto P_0c0776de;
P_0c0776de: /* original c910, guest PC 0x0c0776de */
if(!s->budget--) { s->failed_pc=0x0c0776deu; return 0; }
r[0]&=16u;
goto P_0c0776e0;
P_0c0776e0: /* original 1f01, guest PC 0x0c0776e0 */
if(!s->budget--) { s->failed_pc=0x0c0776e0u; return 0; }
write(ram,r[15]+4,r[0],4);
goto P_0c0776e2;
P_0c0776e2: /* original e050, guest PC 0x0c0776e2 */
if(!s->budget--) { s->failed_pc=0x0c0776e2u; return 0; }
r[0]=0x00000050u;
goto P_0c0776e4;
P_0c0776e4: /* original 00fe, guest PC 0x0c0776e4 */
if(!s->budget--) { s->failed_pc=0x0c0776e4u; return 0; }
r[0]=read(ram,r[15]+r[0],4);
goto P_0c0776e6;
P_0c0776e6: /* original c910, guest PC 0x0c0776e6 */
if(!s->budget--) { s->failed_pc=0x0c0776e6u; return 0; }
r[0]&=16u;
goto P_0c0776e8;
P_0c0776e8: /* original 2102, guest PC 0x0c0776e8 */
if(!s->budget--) { s->failed_pc=0x0c0776e8u; return 0; }
write(ram,r[1],r[0],4);
goto P_0c0776ea;
P_0c0776ea: /* original 50ff, guest PC 0x0c0776ea */
if(!s->budget--) { s->failed_pc=0x0c0776eau; return 0; }
r[0]=read(ram,r[15]+60,4);
goto P_0c0776ec;
P_0c0776ec: /* original c910, guest PC 0x0c0776ec */
if(!s->budget--) { s->failed_pc=0x0c0776ecu; return 0; }
r[0]&=16u;
goto P_0c0776ee;
P_0c0776ee: /* original 1f0f, guest PC 0x0c0776ee */
if(!s->budget--) { s->failed_pc=0x0c0776eeu; return 0; }
write(ram,r[15]+60,r[0],4);
goto P_0c0776f0;
P_0c0776f0: /* original 53f1, guest PC 0x0c0776f0 */
if(!s->budget--) { s->failed_pc=0x0c0776f0u; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c0776f2;
P_0c0776f2: /* original 66d3, guest PC 0x0c0776f2 */
if(!s->budget--) { s->failed_pc=0x0c0776f2u; return 0; }
r[6]=r[13];
goto P_0c0776f4;
P_0c0776f4: /* original 65e3, guest PC 0x0c0776f4 */
if(!s->budget--) { s->failed_pc=0x0c0776f4u; return 0; }
r[5]=r[14];
goto P_0c0776f6;
P_0c0776f6: /* original e701, guest PC 0x0c0776f6 */
if(!s->budget--) { s->failed_pc=0x0c0776f6u; return 0; }
r[7]=0x00000001u;
goto P_0c0776f8;
P_0c0776f8: /* original 2f36, guest PC 0x0c0776f8 */
if(!s->budget--) { s->failed_pc=0x0c0776f8u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0776fa;
P_0c0776fa: /* original 903a, guest PC 0x0c0776fa */
if(!s->budget--) { s->failed_pc=0x0c0776fau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077772u,2);
goto P_0c0776fc;
P_0c0776fc: /* original 02fe, guest PC 0x0c0776fc */
if(!s->budget--) { s->failed_pc=0x0c0776fcu; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c0776fe;
P_0c0776fe: /* original e058, guest PC 0x0c0776fe */
if(!s->budget--) { s->failed_pc=0x0c0776feu; return 0; }
r[0]=0x00000058u;
goto P_0c077700;
P_0c077700: /* original 2f26, guest PC 0x0c077700 */
if(!s->budget--) { s->failed_pc=0x0c077700u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c077702;
P_0c077702: /* original 03fe, guest PC 0x0c077702 */
if(!s->budget--) { s->failed_pc=0x0c077702u; return 0; }
r[3]=read(ram,r[15]+r[0],4);
goto P_0c077704;
P_0c077704: /* original 2f36, guest PC 0x0c077704 */
if(!s->budget--) { s->failed_pc=0x0c077704u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c077706;
P_0c077706: /* original b49d, guest PC 0x0c077706 */
if(!s->budget--) { s->failed_pc=0x0c077706u; return 0; }
target=0x0c078044u; r[16]=0x8c07770au;
r[4]=r[12];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07770au) { target=s->pc; goto dispatch; }
goto P_0c07770a;
P_0c077708: /* original 64c3, guest PC 0x0c077708 */
if(!s->budget--) { s->failed_pc=0x0c077708u; return 0; }
r[4]=r[12];
goto P_0c07770a;
P_0c07770a: /* original 7f0c, guest PC 0x0c07770a */
if(!s->budget--) { s->failed_pc=0x0c07770au; return 0; }
r[15]+=0x0000000cu;
goto P_0c07770c;
P_0c07770c: /* original 61f3, guest PC 0x0c07770c */
if(!s->budget--) { s->failed_pc=0x0c07770cu; return 0; }
r[1]=r[15];
goto P_0c07770e;
P_0c07770e: /* original 7150, guest PC 0x0c07770e */
if(!s->budget--) { s->failed_pc=0x0c07770eu; return 0; }
r[1]+=0x00000050u;
goto P_0c077710;
P_0c077710: /* original 2102, guest PC 0x0c077710 */
if(!s->budget--) { s->failed_pc=0x0c077710u; return 0; }
write(ram,r[1],r[0],4);
goto P_0c077712;
P_0c077712: /* original 902c, guest PC 0x0c077712 */
if(!s->budget--) { s->failed_pc=0x0c077712u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07776eu,2);
goto P_0c077714;
P_0c077714: /* original 03ec, guest PC 0x0c077714 */
if(!s->budget--) { s->failed_pc=0x0c077714u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c077716;
P_0c077716: /* original 633c, guest PC 0x0c077716 */
if(!s->budget--) { s->failed_pc=0x0c077716u; return 0; }
r[3]=r[3]&255u;
goto P_0c077718;
P_0c077718: /* original 7301, guest PC 0x0c077718 */
if(!s->budget--) { s->failed_pc=0x0c077718u; return 0; }
r[3]+=0x00000001u;
goto P_0c07771a;
P_0c07771a: /* original 6033, guest PC 0x0c07771a */
if(!s->budget--) { s->failed_pc=0x0c07771au; return 0; }
r[0]=r[3];
goto P_0c07771c;
P_0c07771c: /* original c93f, guest PC 0x0c07771c */
if(!s->budget--) { s->failed_pc=0x0c07771cu; return 0; }
r[0]&=63u;
goto P_0c07771e;
P_0c07771e: /* original 1f07, guest PC 0x0c07771e */
if(!s->budget--) { s->failed_pc=0x0c07771eu; return 0; }
write(ram,r[15]+28,r[0],4);
goto P_0c077720;
P_0c077720: /* original 9025, guest PC 0x0c077720 */
if(!s->budget--) { s->failed_pc=0x0c077720u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07776eu,2);
goto P_0c077722;
P_0c077722: /* original 53f7, guest PC 0x0c077722 */
if(!s->budget--) { s->failed_pc=0x0c077722u; return 0; }
r[3]=read(ram,r[15]+28,4);
goto P_0c077724;
P_0c077724: /* original 0e34, guest PC 0x0c077724 */
if(!s->budget--) { s->failed_pc=0x0c077724u; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c077726;
P_0c077726: /* original 70ff, guest PC 0x0c077726 */
if(!s->budget--) { s->failed_pc=0x0c077726u; return 0; }
r[0]+=0xffffffffu;
goto P_0c077728;
P_0c077728: /* original 02ec, guest PC 0x0c077728 */
if(!s->budget--) { s->failed_pc=0x0c077728u; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c07772a;
P_0c07772a: /* original e06c, guest PC 0x0c07772a */
if(!s->budget--) { s->failed_pc=0x0c07772au; return 0; }
r[0]=0x0000006cu;
goto P_0c07772c;
P_0c07772c: /* original 622c, guest PC 0x0c07772c */
if(!s->budget--) { s->failed_pc=0x0c07772cu; return 0; }
r[2]=r[2]&255u;
goto P_0c07772e;
P_0c07772e: /* original 1f28, guest PC 0x0c07772e */
if(!s->budget--) { s->failed_pc=0x0c07772eu; return 0; }
write(ram,r[15]+32,r[2],4);
goto P_0c077730;
P_0c077730: /* original 53f7, guest PC 0x0c077730 */
if(!s->budget--) { s->failed_pc=0x0c077730u; return 0; }
r[3]=read(ram,r[15]+28,4);
goto P_0c077732;
P_0c077732: /* original 3238, guest PC 0x0c077732 */
if(!s->budget--) { s->failed_pc=0x0c077732u; return 0; }
r[2]-=r[3];
goto P_0c077734;
P_0c077734: /* original 1f26, guest PC 0x0c077734 */
if(!s->budget--) { s->failed_pc=0x0c077734u; return 0; }
write(ram,r[15]+24,r[2],4);
goto P_0c077736;
P_0c077736: /* original e20b, guest PC 0x0c077736 */
if(!s->budget--) { s->failed_pc=0x0c077736u; return 0; }
r[2]=0x0000000bu;
goto P_0c077738;
P_0c077738: /* original 0f26, guest PC 0x0c077738 */
if(!s->budget--) { s->failed_pc=0x0c077738u; return 0; }
write(ram,r[15]+r[0],r[2],4);
goto P_0c07773a;
P_0c07773a: /* original e04c, guest PC 0x0c07773a */
if(!s->budget--) { s->failed_pc=0x0c07773au; return 0; }
r[0]=0x0000004cu;
goto P_0c07773c;
P_0c07773c: /* original 01ee, guest PC 0x0c07773c */
if(!s->budget--) { s->failed_pc=0x0c07773cu; return 0; }
r[1]=read(ram,r[14]+r[0],4);
goto P_0c07773e;
P_0c07773e: /* original 9315, guest PC 0x0c07773e */
if(!s->budget--) { s->failed_pc=0x0c07773eu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07776cu,2);
goto P_0c077740;
P_0c077740: /* original 2138, guest PC 0x0c077740 */
if(!s->budget--) { s->failed_pc=0x0c077740u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[3])==0)!=0);
goto P_0c077742;
P_0c077742: /* original 8902, guest PC 0x0c077742 */
if(!s->budget--) { s->failed_pc=0x0c077742u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07774a; }
goto P_0c077744;
P_0c077744: /* original e06c, guest PC 0x0c077744 */
if(!s->budget--) { s->failed_pc=0x0c077744u; return 0; }
r[0]=0x0000006cu;
goto P_0c077746;
P_0c077746: /* original e20c, guest PC 0x0c077746 */
if(!s->budget--) { s->failed_pc=0x0c077746u; return 0; }
r[2]=0x0000000cu;
goto P_0c077748;
P_0c077748: /* original 0f26, guest PC 0x0c077748 */
if(!s->budget--) { s->failed_pc=0x0c077748u; return 0; }
write(ram,r[15]+r[0],r[2],4);
goto P_0c07774a;
P_0c07774a: /* original e06c, guest PC 0x0c07774a */
if(!s->budget--) { s->failed_pc=0x0c07774au; return 0; }
r[0]=0x0000006cu;
goto P_0c07774c;
P_0c07774c: /* original 51f6, guest PC 0x0c07774c */
if(!s->budget--) { s->failed_pc=0x0c07774cu; return 0; }
r[1]=read(ram,r[15]+24,4);
goto P_0c07774e;
P_0c07774e: /* original 03fe, guest PC 0x0c07774e */
if(!s->budget--) { s->failed_pc=0x0c07774eu; return 0; }
r[3]=read(ram,r[15]+r[0],4);
goto P_0c077750;
P_0c077750: /* original 3136, guest PC 0x0c077750 */
if(!s->budget--) { s->failed_pc=0x0c077750u; return 0; }
r[17]=(r[17]&~1u)|((r[1]>r[3])!=0);
goto P_0c077752;
P_0c077752: /* original 8d06, guest PC 0x0c077752 */
if(!s->budget--) { s->failed_pc=0x0c077752u; return 0; }
cond=r[17]&1u;
r[1]=0x00000000u;
if(cond) { goto P_0c077762; }
goto P_0c077756;
P_0c077754: /* original e100, guest PC 0x0c077754 */
if(!s->budget--) { s->failed_pc=0x0c077754u; return 0; }
r[1]=0x00000000u;
goto P_0c077756;
P_0c077756: /* original 9006, guest PC 0x0c077756 */
if(!s->budget--) { s->failed_pc=0x0c077756u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077766u,2);
goto P_0c077758;
P_0c077758: /* original d309, guest PC 0x0c077758 */
if(!s->budget--) { s->failed_pc=0x0c077758u; return 0; }
r[3]=read(ram,0x0c077780u,4);
goto P_0c07775a;
P_0c07775a: /* original 02fe, guest PC 0x0c07775a */
if(!s->budget--) { s->failed_pc=0x0c07775au; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c07775c;
P_0c07775c: /* original 9003, guest PC 0x0c07775c */
if(!s->budget--) { s->failed_pc=0x0c07775cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077766u,2);
goto P_0c07775e;
P_0c07775e: /* original 2239, guest PC 0x0c07775e */
if(!s->budget--) { s->failed_pc=0x0c07775eu; return 0; }
r[2]&=r[3];
goto P_0c077760;
P_0c077760: /* original 0f26, guest PC 0x0c077760 */
if(!s->budget--) { s->failed_pc=0x0c077760u; return 0; }
write(ram,r[15]+r[0],r[2],4);
goto P_0c077762;
P_0c077762: /* original a00f, guest PC 0x0c077762 */
if(!s->budget--) { s->failed_pc=0x0c077762u; return 0; }
goto P_0c077784;
P_0c077764: /* original 0009, guest PC 0x0c077764 */
if(!s->budget--) { s->failed_pc=0x0c077764u; return 0; }
return vf3_matrix_family(0x0c077766u,s,ram);
P_0c077784: /* original 62f3, guest PC 0x0c077784 */
if(!s->budget--) { s->failed_pc=0x0c077784u; return 0; }
r[2]=r[15];
goto P_0c077786;
P_0c077786: /* original e078, guest PC 0x0c077786 */
if(!s->budget--) { s->failed_pc=0x0c077786u; return 0; }
r[0]=0x00000078u;
goto P_0c077788;
P_0c077788: /* original 7250, guest PC 0x0c077788 */
if(!s->budget--) { s->failed_pc=0x0c077788u; return 0; }
r[2]+=0x00000050u;
goto P_0c07778a;
P_0c07778a: /* original 0f16, guest PC 0x0c07778a */
if(!s->budget--) { s->failed_pc=0x0c07778au; return 0; }
write(ram,r[15]+r[0],r[1],4);
goto P_0c07778c;
P_0c07778c: /* original 6022, guest PC 0x0c07778c */
if(!s->budget--) { s->failed_pc=0x0c07778cu; return 0; }
tmp=read(ram,r[2],4);
r[0]=tmp;
goto P_0c07778e;
P_0c07778e: /* original 6313, guest PC 0x0c07778e */
if(!s->budget--) { s->failed_pc=0x0c07778eu; return 0; }
r[3]=r[1];
goto P_0c077790;
P_0c077790: /* original c90b, guest PC 0x0c077790 */
if(!s->budget--) { s->failed_pc=0x0c077790u; return 0; }
r[0]&=11u;
goto P_0c077792;
P_0c077792: /* original 230b, guest PC 0x0c077792 */
if(!s->budget--) { s->failed_pc=0x0c077792u; return 0; }
r[3]|=r[0];
goto P_0c077794;
P_0c077794: /* original e078, guest PC 0x0c077794 */
if(!s->budget--) { s->failed_pc=0x0c077794u; return 0; }
r[0]=0x00000078u;
goto P_0c077796;
P_0c077796: /* original 0f36, guest PC 0x0c077796 */
if(!s->budget--) { s->failed_pc=0x0c077796u; return 0; }
write(ram,r[15]+r[0],r[3],4);
goto P_0c077798;
P_0c077798: /* original 9278, guest PC 0x0c077798 */
if(!s->budget--) { s->failed_pc=0x0c077798u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07788cu,2);
goto P_0c07779a;
P_0c07779a: /* original 32fc, guest PC 0x0c07779a */
if(!s->budget--) { s->failed_pc=0x0c07779au; return 0; }
r[2]+=r[15];
goto P_0c07779c;
P_0c07779c: /* original 6022, guest PC 0x0c07779c */
if(!s->budget--) { s->failed_pc=0x0c07779cu; return 0; }
tmp=read(ram,r[2],4);
r[0]=tmp;
goto P_0c07779e;
P_0c07779e: /* original c840, guest PC 0x0c07779e */
if(!s->budget--) { s->failed_pc=0x0c07779eu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&64u)==0)!=0);
goto P_0c0777a0;
P_0c0777a0: /* original 8b08, guest PC 0x0c0777a0 */
if(!s->budget--) { s->failed_pc=0x0c0777a0u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0777b4; }
goto P_0c0777a2;
P_0c0777a2: /* original 9173, guest PC 0x0c0777a2 */
if(!s->budget--) { s->failed_pc=0x0c0777a2u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07788cu,2);
goto P_0c0777a4;
P_0c0777a4: /* original 31fc, guest PC 0x0c0777a4 */
if(!s->budget--) { s->failed_pc=0x0c0777a4u; return 0; }
r[1]+=r[15];
goto P_0c0777a6;
P_0c0777a6: /* original 6012, guest PC 0x0c0777a6 */
if(!s->budget--) { s->failed_pc=0x0c0777a6u; return 0; }
tmp=read(ram,r[1],4);
r[0]=tmp;
goto P_0c0777a8;
P_0c0777a8: /* original c820, guest PC 0x0c0777a8 */
if(!s->budget--) { s->failed_pc=0x0c0777a8u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&32u)==0)!=0);
goto P_0c0777aa;
P_0c0777aa: /* original 8b03, guest PC 0x0c0777aa */
if(!s->budget--) { s->failed_pc=0x0c0777aau; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0777b4; }
goto P_0c0777ac;
P_0c0777ac: /* original e078, guest PC 0x0c0777ac */
if(!s->budget--) { s->failed_pc=0x0c0777acu; return 0; }
r[0]=0x00000078u;
goto P_0c0777ae;
P_0c0777ae: /* original 03fe, guest PC 0x0c0777ae */
if(!s->budget--) { s->failed_pc=0x0c0777aeu; return 0; }
r[3]=read(ram,r[15]+r[0],4);
goto P_0c0777b0;
P_0c0777b0: /* original 2338, guest PC 0x0c0777b0 */
if(!s->budget--) { s->failed_pc=0x0c0777b0u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0777b2;
P_0c0777b2: /* original 8914, guest PC 0x0c0777b2 */
if(!s->budget--) { s->failed_pc=0x0c0777b2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0777de; }
goto P_0c0777b4;
P_0c0777b4: /* original 62f3, guest PC 0x0c0777b4 */
if(!s->budget--) { s->failed_pc=0x0c0777b4u; return 0; }
r[2]=r[15];
goto P_0c0777b6;
P_0c0777b6: /* original 61f3, guest PC 0x0c0777b6 */
if(!s->budget--) { s->failed_pc=0x0c0777b6u; return 0; }
r[1]=r[15];
goto P_0c0777b8;
P_0c0777b8: /* original 7250, guest PC 0x0c0777b8 */
if(!s->budget--) { s->failed_pc=0x0c0777b8u; return 0; }
r[2]+=0x00000050u;
goto P_0c0777ba;
P_0c0777ba: /* original 7178, guest PC 0x0c0777ba */
if(!s->budget--) { s->failed_pc=0x0c0777bau; return 0; }
r[1]+=0x00000078u;
goto P_0c0777bc;
P_0c0777bc: /* original 6022, guest PC 0x0c0777bc */
if(!s->budget--) { s->failed_pc=0x0c0777bcu; return 0; }
tmp=read(ram,r[2],4);
r[0]=tmp;
goto P_0c0777be;
P_0c0777be: /* original 6312, guest PC 0x0c0777be */
if(!s->budget--) { s->failed_pc=0x0c0777beu; return 0; }
tmp=read(ram,r[1],4);
r[3]=tmp;
goto P_0c0777c0;
P_0c0777c0: /* original c904, guest PC 0x0c0777c0 */
if(!s->budget--) { s->failed_pc=0x0c0777c0u; return 0; }
r[0]&=4u;
goto P_0c0777c2;
P_0c0777c2: /* original 230b, guest PC 0x0c0777c2 */
if(!s->budget--) { s->failed_pc=0x0c0777c2u; return 0; }
r[3]|=r[0];
goto P_0c0777c4;
P_0c0777c4: /* original e078, guest PC 0x0c0777c4 */
if(!s->budget--) { s->failed_pc=0x0c0777c4u; return 0; }
r[0]=0x00000078u;
goto P_0c0777c6;
P_0c0777c6: /* original 0f36, guest PC 0x0c0777c6 */
if(!s->budget--) { s->failed_pc=0x0c0777c6u; return 0; }
write(ram,r[15]+r[0],r[3],4);
goto P_0c0777c8;
P_0c0777c8: /* original e050, guest PC 0x0c0777c8 */
if(!s->budget--) { s->failed_pc=0x0c0777c8u; return 0; }
r[0]=0x00000050u;
goto P_0c0777ca;
P_0c0777ca: /* original 01fe, guest PC 0x0c0777ca */
if(!s->budget--) { s->failed_pc=0x0c0777cau; return 0; }
r[1]=read(ram,r[15]+r[0],4);
goto P_0c0777cc;
P_0c0777cc: /* original 6033, guest PC 0x0c0777cc */
if(!s->budget--) { s->failed_pc=0x0c0777ccu; return 0; }
r[0]=r[3];
goto P_0c0777ce;
P_0c0777ce: /* original 925e, guest PC 0x0c0777ce */
if(!s->budget--) { s->failed_pc=0x0c0777ceu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07788eu,2);
goto P_0c0777d0;
P_0c0777d0: /* original 2129, guest PC 0x0c0777d0 */
if(!s->budget--) { s->failed_pc=0x0c0777d0u; return 0; }
r[1]&=r[2];
goto P_0c0777d2;
P_0c0777d2: /* original 4109, guest PC 0x0c0777d2 */
if(!s->budget--) { s->failed_pc=0x0c0777d2u; return 0; }
r[1]>>=2;
goto P_0c0777d4;
P_0c0777d4: /* original 4101, guest PC 0x0c0777d4 */
if(!s->budget--) { s->failed_pc=0x0c0777d4u; return 0; }
r[17]=(r[17]&~1u)|((r[1]&1)!=0);
r[1]>>=1;
goto P_0c0777d6;
P_0c0777d6: /* original 201b, guest PC 0x0c0777d6 */
if(!s->budget--) { s->failed_pc=0x0c0777d6u; return 0; }
r[0]|=r[1];
goto P_0c0777d8;
P_0c0777d8: /* original 61f3, guest PC 0x0c0777d8 */
if(!s->budget--) { s->failed_pc=0x0c0777d8u; return 0; }
r[1]=r[15];
goto P_0c0777da;
P_0c0777da: /* original 7178, guest PC 0x0c0777da */
if(!s->budget--) { s->failed_pc=0x0c0777dau; return 0; }
r[1]+=0x00000078u;
goto P_0c0777dc;
P_0c0777dc: /* original 2102, guest PC 0x0c0777dc */
if(!s->budget--) { s->failed_pc=0x0c0777dcu; return 0; }
write(ram,r[1],r[0],4);
goto P_0c0777de;
P_0c0777de: /* original e06c, guest PC 0x0c0777de */
if(!s->budget--) { s->failed_pc=0x0c0777deu; return 0; }
r[0]=0x0000006cu;
goto P_0c0777e0;
P_0c0777e0: /* original e300, guest PC 0x0c0777e0 */
if(!s->budget--) { s->failed_pc=0x0c0777e0u; return 0; }
r[3]=0x00000000u;
goto P_0c0777e2;
P_0c0777e2: /* original 0f36, guest PC 0x0c0777e2 */
if(!s->budget--) { s->failed_pc=0x0c0777e2u; return 0; }
write(ram,r[15]+r[0],r[3],4);
goto P_0c0777e4;
P_0c0777e4: /* original e078, guest PC 0x0c0777e4 */
if(!s->budget--) { s->failed_pc=0x0c0777e4u; return 0; }
r[0]=0x00000078u;
goto P_0c0777e6;
P_0c0777e6: /* original 00fe, guest PC 0x0c0777e6 */
if(!s->budget--) { s->failed_pc=0x0c0777e6u; return 0; }
r[0]=read(ram,r[15]+r[0],4);
goto P_0c0777e8;
P_0c0777e8: /* original 8802, guest PC 0x0c0777e8 */
if(!s->budget--) { s->failed_pc=0x0c0777e8u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c0777ea;
P_0c0777ea: /* original 8b06, guest PC 0x0c0777ea */
if(!s->budget--) { s->failed_pc=0x0c0777eau; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0777fa; }
goto P_0c0777ec;
P_0c0777ec: /* original 9050, guest PC 0x0c0777ec */
if(!s->budget--) { s->failed_pc=0x0c0777ecu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077890u,2);
goto P_0c0777ee;
P_0c0777ee: /* original 02ec, guest PC 0x0c0777ee */
if(!s->budget--) { s->failed_pc=0x0c0777eeu; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0777f0;
P_0c0777f0: /* original 2228, guest PC 0x0c0777f0 */
if(!s->budget--) { s->failed_pc=0x0c0777f0u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c0777f2;
P_0c0777f2: /* original 8902, guest PC 0x0c0777f2 */
if(!s->budget--) { s->failed_pc=0x0c0777f2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0777fa; }
goto P_0c0777f4;
P_0c0777f4: /* original e06c, guest PC 0x0c0777f4 */
if(!s->budget--) { s->failed_pc=0x0c0777f4u; return 0; }
r[0]=0x0000006cu;
goto P_0c0777f6;
P_0c0777f6: /* original e301, guest PC 0x0c0777f6 */
if(!s->budget--) { s->failed_pc=0x0c0777f6u; return 0; }
r[3]=0x00000001u;
goto P_0c0777f8;
P_0c0777f8: /* original 0f36, guest PC 0x0c0777f8 */
if(!s->budget--) { s->failed_pc=0x0c0777f8u; return 0; }
write(ram,r[15]+r[0],r[3],4);
goto P_0c0777fa;
P_0c0777fa: /* original e06c, guest PC 0x0c0777fa */
if(!s->budget--) { s->failed_pc=0x0c0777fau; return 0; }
r[0]=0x0000006cu;
goto P_0c0777fc;
P_0c0777fc: /* original 02fc, guest PC 0x0c0777fc */
if(!s->budget--) { s->failed_pc=0x0c0777fcu; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[15]+r[0],1);
goto P_0c0777fe;
P_0c0777fe: /* original e01b, guest PC 0x0c0777fe */
if(!s->budget--) { s->failed_pc=0x0c0777feu; return 0; }
r[0]=0x0000001bu;
goto P_0c077800;
P_0c077800: /* original 0c24, guest PC 0x0c077800 */
if(!s->budget--) { s->failed_pc=0x0c077800u; return 0; }
write(ram,r[12]+r[0],r[2],1);
goto P_0c077802;
P_0c077802: /* original 9043, guest PC 0x0c077802 */
if(!s->budget--) { s->failed_pc=0x0c077802u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07788cu,2);
goto P_0c077804;
P_0c077804: /* original d325, guest PC 0x0c077804 */
if(!s->budget--) { s->failed_pc=0x0c077804u; return 0; }
r[3]=read(ram,0x0c07789cu,4);
goto P_0c077806;
P_0c077806: /* original 01fe, guest PC 0x0c077806 */
if(!s->budget--) { s->failed_pc=0x0c077806u; return 0; }
r[1]=read(ram,r[15]+r[0],4);
goto P_0c077808;
P_0c077808: /* original 2138, guest PC 0x0c077808 */
if(!s->budget--) { s->failed_pc=0x0c077808u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[3])==0)!=0);
goto P_0c07780a;
P_0c07780a: /* original 8901, guest PC 0x0c07780a */
if(!s->budget--) { s->failed_pc=0x0c07780au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c077810; }
goto P_0c07780c;
P_0c07780c: /* original a089, guest PC 0x0c07780c */
if(!s->budget--) { s->failed_pc=0x0c07780cu; return 0; }
goto P_0c077922;
P_0c07780e: /* original 0009, guest PC 0x0c07780e */
if(!s->budget--) { s->failed_pc=0x0c07780eu; return 0; }
goto P_0c077810;
P_0c077810: /* original 923c, guest PC 0x0c077810 */
if(!s->budget--) { s->failed_pc=0x0c077810u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07788cu,2);
goto P_0c077812;
P_0c077812: /* original 32fc, guest PC 0x0c077812 */
if(!s->budget--) { s->failed_pc=0x0c077812u; return 0; }
r[2]+=r[15];
goto P_0c077814;
P_0c077814: /* original 6022, guest PC 0x0c077814 */
if(!s->budget--) { s->failed_pc=0x0c077814u; return 0; }
tmp=read(ram,r[2],4);
r[0]=tmp;
goto P_0c077816;
P_0c077816: /* original c860, guest PC 0x0c077816 */
if(!s->budget--) { s->failed_pc=0x0c077816u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&96u)==0)!=0);
goto P_0c077818;
P_0c077818: /* original 8901, guest PC 0x0c077818 */
if(!s->budget--) { s->failed_pc=0x0c077818u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07781e; }
goto P_0c07781a;
P_0c07781a: /* original a1a0, guest PC 0x0c07781a */
if(!s->budget--) { s->failed_pc=0x0c07781au; return 0; }
goto P_0c077b5e;
P_0c07781c: /* original 0009, guest PC 0x0c07781c */
if(!s->budget--) { s->failed_pc=0x0c07781cu; return 0; }
goto P_0c07781e;
P_0c07781e: /* original 9038, guest PC 0x0c07781e */
if(!s->budget--) { s->failed_pc=0x0c07781eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077892u,2);
goto P_0c077820;
P_0c077820: /* original d21f, guest PC 0x0c077820 */
if(!s->budget--) { s->failed_pc=0x0c077820u; return 0; }
r[2]=read(ram,0x0c0778a0u,4);
goto P_0c077822;
P_0c077822: /* original 01fe, guest PC 0x0c077822 */
if(!s->budget--) { s->failed_pc=0x0c077822u; return 0; }
r[1]=read(ram,r[15]+r[0],4);
goto P_0c077824;
P_0c077824: /* original 2128, guest PC 0x0c077824 */
if(!s->budget--) { s->failed_pc=0x0c077824u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[2])==0)!=0);
goto P_0c077826;
P_0c077826: /* original 8901, guest PC 0x0c077826 */
if(!s->budget--) { s->failed_pc=0x0c077826u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07782c; }
goto P_0c077828;
P_0c077828: /* original a199, guest PC 0x0c077828 */
if(!s->budget--) { s->failed_pc=0x0c077828u; return 0; }
goto P_0c077b5e;
P_0c07782a: /* original 0009, guest PC 0x0c07782a */
if(!s->budget--) { s->failed_pc=0x0c07782au; return 0; }
goto P_0c07782c;
P_0c07782c: /* original 50f1, guest PC 0x0c07782c */
if(!s->budget--) { s->failed_pc=0x0c07782cu; return 0; }
r[0]=read(ram,r[15]+4,4);
goto P_0c07782e;
P_0c07782e: /* original c820, guest PC 0x0c07782e */
if(!s->budget--) { s->failed_pc=0x0c07782eu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&32u)==0)!=0);
goto P_0c077830;
P_0c077830: /* original 8b01, guest PC 0x0c077830 */
if(!s->budget--) { s->failed_pc=0x0c077830u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c077836; }
goto P_0c077832;
P_0c077832: /* original a194, guest PC 0x0c077832 */
if(!s->budget--) { s->failed_pc=0x0c077832u; return 0; }
goto P_0c077b5e;
P_0c077834: /* original 0009, guest PC 0x0c077834 */
if(!s->budget--) { s->failed_pc=0x0c077834u; return 0; }
goto P_0c077836;
P_0c077836: /* original 50f1, guest PC 0x0c077836 */
if(!s->budget--) { s->failed_pc=0x0c077836u; return 0; }
r[0]=read(ram,r[15]+4,4);
goto P_0c077838;
P_0c077838: /* original c80f, guest PC 0x0c077838 */
if(!s->budget--) { s->failed_pc=0x0c077838u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&15u)==0)!=0);
goto P_0c07783a;
P_0c07783a: /* original 8901, guest PC 0x0c07783a */
if(!s->budget--) { s->failed_pc=0x0c07783au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c077840; }
goto P_0c07783c;
P_0c07783c: /* original a18f, guest PC 0x0c07783c */
if(!s->budget--) { s->failed_pc=0x0c07783cu; return 0; }
goto P_0c077b5e;
P_0c07783e: /* original 0009, guest PC 0x0c07783e */
if(!s->budget--) { s->failed_pc=0x0c07783eu; return 0; }
goto P_0c077840;
P_0c077840: /* original 9028, guest PC 0x0c077840 */
if(!s->budget--) { s->failed_pc=0x0c077840u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077894u,2);
goto P_0c077842;
P_0c077842: /* original 61f3, guest PC 0x0c077842 */
if(!s->budget--) { s->failed_pc=0x0c077842u; return 0; }
r[1]=r[15];
goto P_0c077844;
P_0c077844: /* original 7168, guest PC 0x0c077844 */
if(!s->budget--) { s->failed_pc=0x0c077844u; return 0; }
r[1]+=0x00000068u;
goto P_0c077846;
P_0c077846: /* original 02ec, guest PC 0x0c077846 */
if(!s->budget--) { s->failed_pc=0x0c077846u; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c077848;
P_0c077848: /* original 622c, guest PC 0x0c077848 */
if(!s->budget--) { s->failed_pc=0x0c077848u; return 0; }
r[2]=r[2]&255u;
goto P_0c07784a;
P_0c07784a: /* original 72fe, guest PC 0x0c07784a */
if(!s->budget--) { s->failed_pc=0x0c07784au; return 0; }
r[2]+=0xfffffffeu;
goto P_0c07784c;
P_0c07784c: /* original 6023, guest PC 0x0c07784c */
if(!s->budget--) { s->failed_pc=0x0c07784cu; return 0; }
r[0]=r[2];
goto P_0c07784e;
P_0c07784e: /* original c93f, guest PC 0x0c07784e */
if(!s->budget--) { s->failed_pc=0x0c07784eu; return 0; }
r[0]&=63u;
goto P_0c077850;
P_0c077850: /* original 2102, guest PC 0x0c077850 */
if(!s->budget--) { s->failed_pc=0x0c077850u; return 0; }
write(ram,r[1],r[0],4);
goto P_0c077852;
P_0c077852: /* original 61f3, guest PC 0x0c077852 */
if(!s->budget--) { s->failed_pc=0x0c077852u; return 0; }
r[1]=r[15];
goto P_0c077854;
P_0c077854: /* original 7160, guest PC 0x0c077854 */
if(!s->budget--) { s->failed_pc=0x0c077854u; return 0; }
r[1]+=0x00000060u;
goto P_0c077856;
P_0c077856: /* original 4008, guest PC 0x0c077856 */
if(!s->budget--) { s->failed_pc=0x0c077856u; return 0; }
r[0]<<=2;
goto P_0c077858;
P_0c077858: /* original 2102, guest PC 0x0c077858 */
if(!s->budget--) { s->failed_pc=0x0c077858u; return 0; }
write(ram,r[1],r[0],4);
goto P_0c07785a;
P_0c07785a: /* original 901c, guest PC 0x0c07785a */
if(!s->budget--) { s->failed_pc=0x0c07785au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077896u,2);
goto P_0c07785c;
P_0c07785c: /* original 03ec, guest PC 0x0c07785c */
if(!s->budget--) { s->failed_pc=0x0c07785cu; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c07785e;
P_0c07785e: /* original e05c, guest PC 0x0c07785e */
if(!s->budget--) { s->failed_pc=0x0c07785eu; return 0; }
r[0]=0x0000005cu;
goto P_0c077860;
P_0c077860: /* original 633c, guest PC 0x0c077860 */
if(!s->budget--) { s->failed_pc=0x0c077860u; return 0; }
r[3]=r[3]&255u;
goto P_0c077862;
P_0c077862: /* original 0f36, guest PC 0x0c077862 */
if(!s->budget--) { s->failed_pc=0x0c077862u; return 0; }
write(ram,r[15]+r[0],r[3],4);
goto P_0c077864;
P_0c077864: /* original e068, guest PC 0x0c077864 */
if(!s->budget--) { s->failed_pc=0x0c077864u; return 0; }
r[0]=0x00000068u;
goto P_0c077866;
P_0c077866: /* original 02fe, guest PC 0x0c077866 */
if(!s->budget--) { s->failed_pc=0x0c077866u; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c077868;
P_0c077868: /* original 3230, guest PC 0x0c077868 */
if(!s->budget--) { s->failed_pc=0x0c077868u; return 0; }
r[17]=(r[17]&~1u)|((r[2]==r[3])!=0);
goto P_0c07786a;
P_0c07786a: /* original 8b01, guest PC 0x0c07786a */
if(!s->budget--) { s->failed_pc=0x0c07786au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c077870; }
goto P_0c07786c;
P_0c07786c: /* original a177, guest PC 0x0c07786c */
if(!s->budget--) { s->failed_pc=0x0c07786cu; return 0; }
goto P_0c077b5e;
P_0c07786e: /* original 0009, guest PC 0x0c07786e */
if(!s->budget--) { s->failed_pc=0x0c07786eu; return 0; }
goto P_0c077870;
P_0c077870: /* original e06c, guest PC 0x0c077870 */
if(!s->budget--) { s->failed_pc=0x0c077870u; return 0; }
r[0]=0x0000006cu;
goto P_0c077872;
P_0c077872: /* original e30c, guest PC 0x0c077872 */
if(!s->budget--) { s->failed_pc=0x0c077872u; return 0; }
r[3]=0x0000000cu;
goto P_0c077874;
P_0c077874: /* original 0f36, guest PC 0x0c077874 */
if(!s->budget--) { s->failed_pc=0x0c077874u; return 0; }
write(ram,r[15]+r[0],r[3],4);
goto P_0c077876;
P_0c077876: /* original e04c, guest PC 0x0c077876 */
if(!s->budget--) { s->failed_pc=0x0c077876u; return 0; }
r[0]=0x0000004cu;
goto P_0c077878;
P_0c077878: /* original 02ee, guest PC 0x0c077878 */
if(!s->budget--) { s->failed_pc=0x0c077878u; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c07787a;
P_0c07787a: /* original 930d, guest PC 0x0c07787a */
if(!s->budget--) { s->failed_pc=0x0c07787au; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077898u,2);
goto P_0c07787c;
P_0c07787c: /* original 2238, guest PC 0x0c07787c */
if(!s->budget--) { s->failed_pc=0x0c07787cu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c07787e;
P_0c07787e: /* original 8d03, guest PC 0x0c07787e */
if(!s->budget--) { s->failed_pc=0x0c07787eu; return 0; }
cond=r[17]&1u;
r[3]=0x00000000u;
if(cond) { goto P_0c077888; }
goto P_0c077882;
P_0c077880: /* original e300, guest PC 0x0c077880 */
if(!s->budget--) { s->failed_pc=0x0c077880u; return 0; }
r[3]=0x00000000u;
goto P_0c077882;
P_0c077882: /* original e06c, guest PC 0x0c077882 */
if(!s->budget--) { s->failed_pc=0x0c077882u; return 0; }
r[0]=0x0000006cu;
goto P_0c077884;
P_0c077884: /* original e206, guest PC 0x0c077884 */
if(!s->budget--) { s->failed_pc=0x0c077884u; return 0; }
r[2]=0x00000006u;
goto P_0c077886;
P_0c077886: /* original 0f26, guest PC 0x0c077886 */
if(!s->budget--) { s->failed_pc=0x0c077886u; return 0; }
write(ram,r[15]+r[0],r[2],4);
goto P_0c077888;
P_0c077888: /* original a02a, guest PC 0x0c077888 */
if(!s->budget--) { s->failed_pc=0x0c077888u; return 0; }
goto P_0c0778e0;
P_0c07788a: /* original 0009, guest PC 0x0c07788a */
if(!s->budget--) { s->failed_pc=0x0c07788au; return 0; }
return vf3_matrix_family(0x0c07788cu,s,ram);
P_0c0778a4: /* original e060, guest PC 0x0c0778a4 */
if(!s->budget--) { s->failed_pc=0x0c0778a4u; return 0; }
r[0]=0x00000060u;
goto P_0c0778a6;
P_0c0778a6: /* original 03fe, guest PC 0x0c0778a6 */
if(!s->budget--) { s->failed_pc=0x0c0778a6u; return 0; }
r[3]=read(ram,r[15]+r[0],4);
goto P_0c0778a8;
P_0c0778a8: /* original 906b, guest PC 0x0c0778a8 */
if(!s->budget--) { s->failed_pc=0x0c0778a8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077982u,2);
goto P_0c0778aa;
P_0c0778aa: /* original 30ec, guest PC 0x0c0778aa */
if(!s->budget--) { s->failed_pc=0x0c0778aau; return 0; }
r[0]+=r[14];
goto P_0c0778ac;
P_0c0778ac: /* original 003c, guest PC 0x0c0778ac */
if(!s->budget--) { s->failed_pc=0x0c0778acu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[3]+r[0],1);
goto P_0c0778ae;
P_0c0778ae: /* original 600c, guest PC 0x0c0778ae */
if(!s->budget--) { s->failed_pc=0x0c0778aeu; return 0; }
r[0]=r[0]&255u;
goto P_0c0778b0;
P_0c0778b0: /* original c810, guest PC 0x0c0778b0 */
if(!s->budget--) { s->failed_pc=0x0c0778b0u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&16u)==0)!=0);
goto P_0c0778b2;
P_0c0778b2: /* original 8b1d, guest PC 0x0c0778b2 */
if(!s->budget--) { s->failed_pc=0x0c0778b2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0778f0; }
goto P_0c0778b4;
P_0c0778b4: /* original e05c, guest PC 0x0c0778b4 */
if(!s->budget--) { s->failed_pc=0x0c0778b4u; return 0; }
r[0]=0x0000005cu;
goto P_0c0778b6;
P_0c0778b6: /* original 03fe, guest PC 0x0c0778b6 */
if(!s->budget--) { s->failed_pc=0x0c0778b6u; return 0; }
r[3]=read(ram,r[15]+r[0],4);
goto P_0c0778b8;
P_0c0778b8: /* original e068, guest PC 0x0c0778b8 */
if(!s->budget--) { s->failed_pc=0x0c0778b8u; return 0; }
r[0]=0x00000068u;
goto P_0c0778ba;
P_0c0778ba: /* original 02fe, guest PC 0x0c0778ba */
if(!s->budget--) { s->failed_pc=0x0c0778bau; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c0778bc;
P_0c0778bc: /* original 3230, guest PC 0x0c0778bc */
if(!s->budget--) { s->failed_pc=0x0c0778bcu; return 0; }
r[17]=(r[17]&~1u)|((r[2]==r[3])!=0);
goto P_0c0778be;
P_0c0778be: /* original 8b01, guest PC 0x0c0778be */
if(!s->budget--) { s->failed_pc=0x0c0778beu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0778c4; }
goto P_0c0778c0;
P_0c0778c0: /* original a14d, guest PC 0x0c0778c0 */
if(!s->budget--) { s->failed_pc=0x0c0778c0u; return 0; }
goto P_0c077b5e;
P_0c0778c2: /* original 0009, guest PC 0x0c0778c2 */
if(!s->budget--) { s->failed_pc=0x0c0778c2u; return 0; }
goto P_0c0778c4;
P_0c0778c4: /* original e068, guest PC 0x0c0778c4 */
if(!s->budget--) { s->failed_pc=0x0c0778c4u; return 0; }
r[0]=0x00000068u;
goto P_0c0778c6;
P_0c0778c6: /* original 62f3, guest PC 0x0c0778c6 */
if(!s->budget--) { s->failed_pc=0x0c0778c6u; return 0; }
r[2]=r[15];
goto P_0c0778c8;
P_0c0778c8: /* original 01fe, guest PC 0x0c0778c8 */
if(!s->budget--) { s->failed_pc=0x0c0778c8u; return 0; }
r[1]=read(ram,r[15]+r[0],4);
goto P_0c0778ca;
P_0c0778ca: /* original 7268, guest PC 0x0c0778ca */
if(!s->budget--) { s->failed_pc=0x0c0778cau; return 0; }
r[2]+=0x00000068u;
goto P_0c0778cc;
P_0c0778cc: /* original 71ff, guest PC 0x0c0778cc */
if(!s->budget--) { s->failed_pc=0x0c0778ccu; return 0; }
r[1]+=0xffffffffu;
goto P_0c0778ce;
P_0c0778ce: /* original 6013, guest PC 0x0c0778ce */
if(!s->budget--) { s->failed_pc=0x0c0778ceu; return 0; }
r[0]=r[1];
goto P_0c0778d0;
P_0c0778d0: /* original c93f, guest PC 0x0c0778d0 */
if(!s->budget--) { s->failed_pc=0x0c0778d0u; return 0; }
r[0]&=63u;
goto P_0c0778d2;
P_0c0778d2: /* original 61f3, guest PC 0x0c0778d2 */
if(!s->budget--) { s->failed_pc=0x0c0778d2u; return 0; }
r[1]=r[15];
goto P_0c0778d4;
P_0c0778d4: /* original 2202, guest PC 0x0c0778d4 */
if(!s->budget--) { s->failed_pc=0x0c0778d4u; return 0; }
write(ram,r[2],r[0],4);
goto P_0c0778d6;
P_0c0778d6: /* original 7160, guest PC 0x0c0778d6 */
if(!s->budget--) { s->failed_pc=0x0c0778d6u; return 0; }
r[1]+=0x00000060u;
goto P_0c0778d8;
P_0c0778d8: /* original 4008, guest PC 0x0c0778d8 */
if(!s->budget--) { s->failed_pc=0x0c0778d8u; return 0; }
r[0]<<=2;
goto P_0c0778da;
P_0c0778da: /* original 2102, guest PC 0x0c0778da */
if(!s->budget--) { s->failed_pc=0x0c0778dau; return 0; }
write(ram,r[1],r[0],4);
goto P_0c0778dc;
P_0c0778dc: /* original 53f3, guest PC 0x0c0778dc */
if(!s->budget--) { s->failed_pc=0x0c0778dcu; return 0; }
r[3]=read(ram,r[15]+12,4);
goto P_0c0778de;
P_0c0778de: /* original 7301, guest PC 0x0c0778de */
if(!s->budget--) { s->failed_pc=0x0c0778deu; return 0; }
r[3]+=0x00000001u;
goto P_0c0778e0;
P_0c0778e0: /* original e06c, guest PC 0x0c0778e0 */
if(!s->budget--) { s->failed_pc=0x0c0778e0u; return 0; }
r[0]=0x0000006cu;
goto P_0c0778e2;
P_0c0778e2: /* original 6133, guest PC 0x0c0778e2 */
if(!s->budget--) { s->failed_pc=0x0c0778e2u; return 0; }
r[1]=r[3];
goto P_0c0778e4;
P_0c0778e4: /* original 1f33, guest PC 0x0c0778e4 */
if(!s->budget--) { s->failed_pc=0x0c0778e4u; return 0; }
write(ram,r[15]+12,r[3],4);
goto P_0c0778e6;
P_0c0778e6: /* original 02fe, guest PC 0x0c0778e6 */
if(!s->budget--) { s->failed_pc=0x0c0778e6u; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c0778e8;
P_0c0778e8: /* original 3122, guest PC 0x0c0778e8 */
if(!s->budget--) { s->failed_pc=0x0c0778e8u; return 0; }
r[17]=(r[17]&~1u)|((r[1]>=r[2])!=0);
goto P_0c0778ea;
P_0c0778ea: /* original 8bdb, guest PC 0x0c0778ea */
if(!s->budget--) { s->failed_pc=0x0c0778eau; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0778a4; }
goto P_0c0778ec;
P_0c0778ec: /* original a137, guest PC 0x0c0778ec */
if(!s->budget--) { s->failed_pc=0x0c0778ecu; return 0; }
goto P_0c077b5e;
P_0c0778ee: /* original 0009, guest PC 0x0c0778ee */
if(!s->budget--) { s->failed_pc=0x0c0778eeu; return 0; }
goto P_0c0778f0;
P_0c0778f0: /* original d326, guest PC 0x0c0778f0 */
if(!s->budget--) { s->failed_pc=0x0c0778f0u; return 0; }
r[3]=read(ram,0x0c07798cu,4);
goto P_0c0778f2;
P_0c0778f2: /* original e044, guest PC 0x0c0778f2 */
if(!s->budget--) { s->failed_pc=0x0c0778f2u; return 0; }
r[0]=0x00000044u;
goto P_0c0778f4;
P_0c0778f4: /* original 1f3e, guest PC 0x0c0778f4 */
if(!s->budget--) { s->failed_pc=0x0c0778f4u; return 0; }
write(ram,r[15]+56,r[3],4);
goto P_0c0778f6;
P_0c0778f6: /* original 02fe, guest PC 0x0c0778f6 */
if(!s->budget--) { s->failed_pc=0x0c0778f6u; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c0778f8;
P_0c0778f8: /* original 53f1, guest PC 0x0c0778f8 */
if(!s->budget--) { s->failed_pc=0x0c0778f8u; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c0778fa;
P_0c0778fa: /* original 2238, guest PC 0x0c0778fa */
if(!s->budget--) { s->failed_pc=0x0c0778fau; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0778fc;
P_0c0778fc: /* original 8903, guest PC 0x0c0778fc */
if(!s->budget--) { s->failed_pc=0x0c0778fcu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c077906; }
goto P_0c0778fe;
P_0c0778fe: /* original 51fe, guest PC 0x0c0778fe */
if(!s->budget--) { s->failed_pc=0x0c0778feu; return 0; }
r[1]=read(ram,r[15]+56,4);
goto P_0c077900;
P_0c077900: /* original d223, guest PC 0x0c077900 */
if(!s->budget--) { s->failed_pc=0x0c077900u; return 0; }
r[2]=read(ram,0x0c077990u,4);
goto P_0c077902;
P_0c077902: /* original 212b, guest PC 0x0c077902 */
if(!s->budget--) { s->failed_pc=0x0c077902u; return 0; }
r[1]|=r[2];
goto P_0c077904;
P_0c077904: /* original 1f1e, guest PC 0x0c077904 */
if(!s->budget--) { s->failed_pc=0x0c077904u; return 0; }
write(ram,r[15]+56,r[1],4);
goto P_0c077906;
P_0c077906: /* original e040, guest PC 0x0c077906 */
if(!s->budget--) { s->failed_pc=0x0c077906u; return 0; }
r[0]=0x00000040u;
goto P_0c077908;
P_0c077908: /* original 53f1, guest PC 0x0c077908 */
if(!s->budget--) { s->failed_pc=0x0c077908u; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c07790a;
P_0c07790a: /* original 02fe, guest PC 0x0c07790a */
if(!s->budget--) { s->failed_pc=0x0c07790au; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c07790c;
P_0c07790c: /* original 2238, guest PC 0x0c07790c */
if(!s->budget--) { s->failed_pc=0x0c07790cu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c07790e;
P_0c07790e: /* original 8903, guest PC 0x0c07790e */
if(!s->budget--) { s->failed_pc=0x0c07790eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c077918; }
goto P_0c077910;
P_0c077910: /* original 51fe, guest PC 0x0c077910 */
if(!s->budget--) { s->failed_pc=0x0c077910u; return 0; }
r[1]=read(ram,r[15]+56,4);
goto P_0c077912;
P_0c077912: /* original d220, guest PC 0x0c077912 */
if(!s->budget--) { s->failed_pc=0x0c077912u; return 0; }
r[2]=read(ram,0x0c077994u,4);
goto P_0c077914;
P_0c077914: /* original 212b, guest PC 0x0c077914 */
if(!s->budget--) { s->failed_pc=0x0c077914u; return 0; }
r[1]|=r[2];
goto P_0c077916;
P_0c077916: /* original 1f1e, guest PC 0x0c077916 */
if(!s->budget--) { s->failed_pc=0x0c077916u; return 0; }
write(ram,r[15]+56,r[1],4);
goto P_0c077918;
P_0c077918: /* original 53fe, guest PC 0x0c077918 */
if(!s->budget--) { s->failed_pc=0x0c077918u; return 0; }
r[3]=read(ram,r[15]+56,4);
goto P_0c07791a;
P_0c07791a: /* original e200, guest PC 0x0c07791a */
if(!s->budget--) { s->failed_pc=0x0c07791au; return 0; }
r[2]=0x00000000u;
goto P_0c07791c;
P_0c07791c: /* original 1f3a, guest PC 0x0c07791c */
if(!s->budget--) { s->failed_pc=0x0c07791cu; return 0; }
write(ram,r[15]+40,r[3],4);
goto P_0c07791e;
P_0c07791e: /* original a070, guest PC 0x0c07791e */
if(!s->budget--) { s->failed_pc=0x0c07791eu; return 0; }
write(ram,r[15]+36,r[2],4);
goto P_0c077a02;
P_0c077920: /* original 1f29, guest PC 0x0c077920 */
if(!s->budget--) { s->failed_pc=0x0c077920u; return 0; }
write(ram,r[15]+36,r[2],4);
goto P_0c077922;
P_0c077922: /* original e100, guest PC 0x0c077922 */
if(!s->budget--) { s->failed_pc=0x0c077922u; return 0; }
r[1]=0x00000000u;
goto P_0c077924;
P_0c077924: /* original 1f1e, guest PC 0x0c077924 */
if(!s->budget--) { s->failed_pc=0x0c077924u; return 0; }
write(ram,r[15]+56,r[1],4);
goto P_0c077926;
P_0c077926: /* original 902d, guest PC 0x0c077926 */
if(!s->budget--) { s->failed_pc=0x0c077926u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077984u,2);
goto P_0c077928;
P_0c077928: /* original 02ee, guest PC 0x0c077928 */
if(!s->budget--) { s->failed_pc=0x0c077928u; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c07792a;
P_0c07792a: /* original 2228, guest PC 0x0c07792a */
if(!s->budget--) { s->failed_pc=0x0c07792au; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c07792c;
P_0c07792c: /* original 8934, guest PC 0x0c07792c */
if(!s->budget--) { s->failed_pc=0x0c07792cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c077998; }
goto P_0c07792e;
P_0c07792e: /* original e050, guest PC 0x0c07792e */
if(!s->budget--) { s->failed_pc=0x0c07792eu; return 0; }
r[0]=0x00000050u;
goto P_0c077930;
P_0c077930: /* original 66d3, guest PC 0x0c077930 */
if(!s->budget--) { s->failed_pc=0x0c077930u; return 0; }
r[6]=r[13];
goto P_0c077932;
P_0c077932: /* original 02fe, guest PC 0x0c077932 */
if(!s->budget--) { s->failed_pc=0x0c077932u; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c077934;
P_0c077934: /* original e04c, guest PC 0x0c077934 */
if(!s->budget--) { s->failed_pc=0x0c077934u; return 0; }
r[0]=0x0000004cu;
goto P_0c077936;
P_0c077936: /* original 2f26, guest PC 0x0c077936 */
if(!s->budget--) { s->failed_pc=0x0c077936u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c077938;
P_0c077938: /* original 51f2, guest PC 0x0c077938 */
if(!s->budget--) { s->failed_pc=0x0c077938u; return 0; }
r[1]=read(ram,r[15]+8,4);
goto P_0c07793a;
P_0c07793a: /* original 2f16, guest PC 0x0c07793a */
if(!s->budget--) { s->failed_pc=0x0c07793au; return 0; }
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07793c;
P_0c07793c: /* original 02fe, guest PC 0x0c07793c */
if(!s->budget--) { s->failed_pc=0x0c07793cu; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c07793e;
P_0c07793e: /* original e04c, guest PC 0x0c07793e */
if(!s->budget--) { s->failed_pc=0x0c07793eu; return 0; }
r[0]=0x0000004cu;
goto P_0c077940;
P_0c077940: /* original 2f26, guest PC 0x0c077940 */
if(!s->budget--) { s->failed_pc=0x0c077940u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c077942;
P_0c077942: /* original 01fe, guest PC 0x0c077942 */
if(!s->budget--) { s->failed_pc=0x0c077942u; return 0; }
r[1]=read(ram,r[15]+r[0],4);
goto P_0c077944;
P_0c077944: /* original 2f16, guest PC 0x0c077944 */
if(!s->budget--) { s->failed_pc=0x0c077944u; return 0; }
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c077946;
P_0c077946: /* original 901e, guest PC 0x0c077946 */
if(!s->budget--) { s->failed_pc=0x0c077946u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077986u,2);
goto P_0c077948;
P_0c077948: /* original 02fe, guest PC 0x0c077948 */
if(!s->budget--) { s->failed_pc=0x0c077948u; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c07794a;
P_0c07794a: /* original e05c, guest PC 0x0c07794a */
if(!s->budget--) { s->failed_pc=0x0c07794au; return 0; }
r[0]=0x0000005cu;
goto P_0c07794c;
P_0c07794c: /* original 2f26, guest PC 0x0c07794c */
if(!s->budget--) { s->failed_pc=0x0c07794cu; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07794e;
P_0c07794e: /* original 01fe, guest PC 0x0c07794e */
if(!s->budget--) { s->failed_pc=0x0c07794eu; return 0; }
r[1]=read(ram,r[15]+r[0],4);
goto P_0c077950;
P_0c077950: /* original 2f16, guest PC 0x0c077950 */
if(!s->budget--) { s->failed_pc=0x0c077950u; return 0; }
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c077952;
P_0c077952: /* original 9219, guest PC 0x0c077952 */
if(!s->budget--) { s->failed_pc=0x0c077952u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077988u,2);
goto P_0c077954;
P_0c077954: /* original 32fc, guest PC 0x0c077954 */
if(!s->budget--) { s->failed_pc=0x0c077954u; return 0; }
r[2]+=r[15];
goto P_0c077956;
P_0c077956: /* original 2f26, guest PC 0x0c077956 */
if(!s->budget--) { s->failed_pc=0x0c077956u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c077958;
P_0c077958: /* original 9016, guest PC 0x0c077958 */
if(!s->budget--) { s->failed_pc=0x0c077958u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077988u,2);
goto P_0c07795a;
P_0c07795a: /* original 01fe, guest PC 0x0c07795a */
if(!s->budget--) { s->failed_pc=0x0c07795au; return 0; }
r[1]=read(ram,r[15]+r[0],4);
goto P_0c07795c;
P_0c07795c: /* original 2f16, guest PC 0x0c07795c */
if(!s->budget--) { s->failed_pc=0x0c07795cu; return 0; }
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07795e;
P_0c07795e: /* original 9012, guest PC 0x0c07795e */
if(!s->budget--) { s->failed_pc=0x0c07795eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077986u,2);
goto P_0c077960;
P_0c077960: /* original 02fe, guest PC 0x0c077960 */
if(!s->budget--) { s->failed_pc=0x0c077960u; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c077962;
P_0c077962: /* original 2f26, guest PC 0x0c077962 */
if(!s->budget--) { s->failed_pc=0x0c077962u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c077964;
P_0c077964: /* original 9011, guest PC 0x0c077964 */
if(!s->budget--) { s->failed_pc=0x0c077964u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07798au,2);
goto P_0c077966;
P_0c077966: /* original 01fe, guest PC 0x0c077966 */
if(!s->budget--) { s->failed_pc=0x0c077966u; return 0; }
r[1]=read(ram,r[15]+r[0],4);
goto P_0c077968;
P_0c077968: /* original 2f16, guest PC 0x0c077968 */
if(!s->budget--) { s->failed_pc=0x0c077968u; return 0; }
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07796a;
P_0c07796a: /* original 970e, guest PC 0x0c07796a */
if(!s->budget--) { s->failed_pc=0x0c07796au; return 0; }
r[7]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07798au,2);
goto P_0c07796c;
P_0c07796c: /* original 37fc, guest PC 0x0c07796c */
if(!s->budget--) { s->failed_pc=0x0c07796cu; return 0; }
r[7]+=r[15];
goto P_0c07796e;
P_0c07796e: /* original 65e3, guest PC 0x0c07796e */
if(!s->budget--) { s->failed_pc=0x0c07796eu; return 0; }
r[5]=r[14];
goto P_0c077970;
P_0c077970: /* original b493, guest PC 0x0c077970 */
if(!s->budget--) { s->failed_pc=0x0c077970u; return 0; }
target=0x0c07829au; r[16]=0x8c077974u;
r[4]=r[12];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c077974u) { target=s->pc; goto dispatch; }
goto P_0c077974;
P_0c077972: /* original 64c3, guest PC 0x0c077972 */
if(!s->budget--) { s->failed_pc=0x0c077972u; return 0; }
r[4]=r[12];
goto P_0c077974;
P_0c077974: /* original 2008, guest PC 0x0c077974 */
if(!s->budget--) { s->failed_pc=0x0c077974u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c077976;
P_0c077976: /* original 8d02, guest PC 0x0c077976 */
if(!s->budget--) { s->failed_pc=0x0c077976u; return 0; }
cond=r[17]&1u;
r[15]+=0x00000028u;
if(cond) { goto P_0c07797e; }
goto P_0c07797a;
P_0c077978: /* original 7f28, guest PC 0x0c077978 */
if(!s->budget--) { s->failed_pc=0x0c077978u; return 0; }
r[15]+=0x00000028u;
goto P_0c07797a;
P_0c07797a: /* original a261, guest PC 0x0c07797a */
if(!s->budget--) { s->failed_pc=0x0c07797au; return 0; }
goto P_0c077e40;
P_0c07797c: /* original 0009, guest PC 0x0c07797c */
if(!s->budget--) { s->failed_pc=0x0c07797cu; return 0; }
goto P_0c07797e;
P_0c07797e: /* original a193, guest PC 0x0c07797e */
if(!s->budget--) { s->failed_pc=0x0c07797eu; return 0; }
goto P_0c077ca8;
P_0c077980: /* original 0009, guest PC 0x0c077980 */
if(!s->budget--) { s->failed_pc=0x0c077980u; return 0; }
return vf3_matrix_family(0x0c077982u,s,ram);
P_0c077998: /* original 908a, guest PC 0x0c077998 */
if(!s->budget--) { s->failed_pc=0x0c077998u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077ab0u,2);
goto P_0c07799a;
P_0c07799a: /* original d349, guest PC 0x0c07799a */
if(!s->budget--) { s->failed_pc=0x0c07799au; return 0; }
r[3]=read(ram,0x0c077ac0u,4);
goto P_0c07799c;
P_0c07799c: /* original 02fe, guest PC 0x0c07799c */
if(!s->budget--) { s->failed_pc=0x0c07799cu; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c07799e;
P_0c07799e: /* original 2238, guest PC 0x0c07799e */
if(!s->budget--) { s->failed_pc=0x0c07799eu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0779a0;
P_0c0779a0: /* original 8901, guest PC 0x0c0779a0 */
if(!s->budget--) { s->failed_pc=0x0c0779a0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0779a6; }
goto P_0c0779a2;
P_0c0779a2: /* original a249, guest PC 0x0c0779a2 */
if(!s->budget--) { s->failed_pc=0x0c0779a2u; return 0; }
goto P_0c077e38;
P_0c0779a4: /* original 0009, guest PC 0x0c0779a4 */
if(!s->budget--) { s->failed_pc=0x0c0779a4u; return 0; }
goto P_0c0779a6;
P_0c0779a6: /* original 52ee, guest PC 0x0c0779a6 */
if(!s->budget--) { s->failed_pc=0x0c0779a6u; return 0; }
r[2]=read(ram,r[14]+56,4);
goto P_0c0779a8;
P_0c0779a8: /* original d346, guest PC 0x0c0779a8 */
if(!s->budget--) { s->failed_pc=0x0c0779a8u; return 0; }
r[3]=read(ram,0x0c077ac4u,4);
goto P_0c0779aa;
P_0c0779aa: /* original 2239, guest PC 0x0c0779aa */
if(!s->budget--) { s->failed_pc=0x0c0779aau; return 0; }
r[2]&=r[3];
goto P_0c0779ac;
P_0c0779ac: /* original 1f2a, guest PC 0x0c0779ac */
if(!s->budget--) { s->failed_pc=0x0c0779acu; return 0; }
write(ram,r[15]+40,r[2],4);
goto P_0c0779ae;
P_0c0779ae: /* original 9080, guest PC 0x0c0779ae */
if(!s->budget--) { s->failed_pc=0x0c0779aeu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077ab2u,2);
goto P_0c0779b0;
P_0c0779b0: /* original 01ec, guest PC 0x0c0779b0 */
if(!s->budget--) { s->failed_pc=0x0c0779b0u; return 0; }
r[1]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0779b2;
P_0c0779b2: /* original e062, guest PC 0x0c0779b2 */
if(!s->budget--) { s->failed_pc=0x0c0779b2u; return 0; }
r[0]=0x00000062u;
goto P_0c0779b4;
P_0c0779b4: /* original 611c, guest PC 0x0c0779b4 */
if(!s->budget--) { s->failed_pc=0x0c0779b4u; return 0; }
r[1]=r[1]&255u;
goto P_0c0779b6;
P_0c0779b6: /* original 1f19, guest PC 0x0c0779b6 */
if(!s->budget--) { s->failed_pc=0x0c0779b6u; return 0; }
write(ram,r[15]+36,r[1],4);
goto P_0c0779b8;
P_0c0779b8: /* original 00ec, guest PC 0x0c0779b8 */
if(!s->budget--) { s->failed_pc=0x0c0779b8u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0779ba;
P_0c0779ba: /* original 600c, guest PC 0x0c0779ba */
if(!s->budget--) { s->failed_pc=0x0c0779bau; return 0; }
r[0]=r[0]&255u;
goto P_0c0779bc;
P_0c0779bc: /* original 8801, guest PC 0x0c0779bc */
if(!s->budget--) { s->failed_pc=0x0c0779bcu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c0779be;
P_0c0779be: /* original 8b01, guest PC 0x0c0779be */
if(!s->budget--) { s->failed_pc=0x0c0779beu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0779c4; }
goto P_0c0779c0;
P_0c0779c0: /* original a086, guest PC 0x0c0779c0 */
if(!s->budget--) { s->failed_pc=0x0c0779c0u; return 0; }
goto P_0c077ad0;
P_0c0779c2: /* original 0009, guest PC 0x0c0779c2 */
if(!s->budget--) { s->failed_pc=0x0c0779c2u; return 0; }
goto P_0c0779c4;
P_0c0779c4: /* original 50f9, guest PC 0x0c0779c4 */
if(!s->budget--) { s->failed_pc=0x0c0779c4u; return 0; }
r[0]=read(ram,r[15]+36,4);
goto P_0c0779c6;
P_0c0779c6: /* original c840, guest PC 0x0c0779c6 */
if(!s->budget--) { s->failed_pc=0x0c0779c6u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&64u)==0)!=0);
goto P_0c0779c8;
P_0c0779c8: /* original 8901, guest PC 0x0c0779c8 */
if(!s->budget--) { s->failed_pc=0x0c0779c8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0779ce; }
goto P_0c0779ca;
P_0c0779ca: /* original a0bd, guest PC 0x0c0779ca */
if(!s->budget--) { s->failed_pc=0x0c0779cau; return 0; }
goto P_0c077b48;
P_0c0779cc: /* original 0009, guest PC 0x0c0779cc */
if(!s->budget--) { s->failed_pc=0x0c0779ccu; return 0; }
goto P_0c0779ce;
P_0c0779ce: /* original e03e, guest PC 0x0c0779ce */
if(!s->budget--) { s->failed_pc=0x0c0779ceu; return 0; }
r[0]=0x0000003eu;
goto P_0c0779d0;
P_0c0779d0: /* original 03ed, guest PC 0x0c0779d0 */
if(!s->budget--) { s->failed_pc=0x0c0779d0u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0779d2;
P_0c0779d2: /* original 906f, guest PC 0x0c0779d2 */
if(!s->budget--) { s->failed_pc=0x0c0779d2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077ab4u,2);
goto P_0c0779d4;
P_0c0779d4: /* original 633d, guest PC 0x0c0779d4 */
if(!s->budget--) { s->failed_pc=0x0c0779d4u; return 0; }
r[3]=r[3]&65535u;
goto P_0c0779d6;
P_0c0779d6: /* original 02ed, guest PC 0x0c0779d6 */
if(!s->budget--) { s->failed_pc=0x0c0779d6u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0779d8;
P_0c0779d8: /* original 7301, guest PC 0x0c0779d8 */
if(!s->budget--) { s->failed_pc=0x0c0779d8u; return 0; }
r[3]+=0x00000001u;
goto P_0c0779da;
P_0c0779da: /* original 622d, guest PC 0x0c0779da */
if(!s->budget--) { s->failed_pc=0x0c0779dau; return 0; }
r[2]=r[2]&65535u;
goto P_0c0779dc;
P_0c0779dc: /* original 3323, guest PC 0x0c0779dc */
if(!s->budget--) { s->failed_pc=0x0c0779dcu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>=(int32_t)r[2])!=0);
goto P_0c0779de;
P_0c0779de: /* original 8b02, guest PC 0x0c0779de */
if(!s->budget--) { s->failed_pc=0x0c0779deu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0779e6; }
goto P_0c0779e0;
P_0c0779e0: /* original 50f9, guest PC 0x0c0779e0 */
if(!s->budget--) { s->failed_pc=0x0c0779e0u; return 0; }
r[0]=read(ram,r[15]+36,4);
goto P_0c0779e2;
P_0c0779e2: /* original cb80, guest PC 0x0c0779e2 */
if(!s->budget--) { s->failed_pc=0x0c0779e2u; return 0; }
r[0]|=128u;
goto P_0c0779e4;
P_0c0779e4: /* original 1f09, guest PC 0x0c0779e4 */
if(!s->budget--) { s->failed_pc=0x0c0779e4u; return 0; }
write(ram,r[15]+36,r[0],4);
goto P_0c0779e6;
P_0c0779e6: /* original 50f1, guest PC 0x0c0779e6 */
if(!s->budget--) { s->failed_pc=0x0c0779e6u; return 0; }
r[0]=read(ram,r[15]+4,4);
goto P_0c0779e8;
P_0c0779e8: /* original c820, guest PC 0x0c0779e8 */
if(!s->budget--) { s->failed_pc=0x0c0779e8u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&32u)==0)!=0);
goto P_0c0779ea;
P_0c0779ea: /* original 8b0a, guest PC 0x0c0779ea */
if(!s->budget--) { s->failed_pc=0x0c0779eau; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c077a02; }
goto P_0c0779ec;
P_0c0779ec: /* original 51fa, guest PC 0x0c0779ec */
if(!s->budget--) { s->failed_pc=0x0c0779ecu; return 0; }
r[1]=read(ram,r[15]+40,4);
goto P_0c0779ee;
P_0c0779ee: /* original d336, guest PC 0x0c0779ee */
if(!s->budget--) { s->failed_pc=0x0c0779eeu; return 0; }
r[3]=read(ram,0x0c077ac8u,4);
goto P_0c0779f0;
P_0c0779f0: /* original 2138, guest PC 0x0c0779f0 */
if(!s->budget--) { s->failed_pc=0x0c0779f0u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[3])==0)!=0);
goto P_0c0779f2;
P_0c0779f2: /* original 8b06, guest PC 0x0c0779f2 */
if(!s->budget--) { s->failed_pc=0x0c0779f2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c077a02; }
goto P_0c0779f4;
P_0c0779f4: /* original d235, guest PC 0x0c0779f4 */
if(!s->budget--) { s->failed_pc=0x0c0779f4u; return 0; }
r[2]=read(ram,0x0c077accu,4);
goto P_0c0779f6;
P_0c0779f6: /* original 6123, guest PC 0x0c0779f6 */
if(!s->budget--) { s->failed_pc=0x0c0779f6u; return 0; }
r[1]=r[2];
goto P_0c0779f8;
P_0c0779f8: /* original 1f2e, guest PC 0x0c0779f8 */
if(!s->budget--) { s->failed_pc=0x0c0779f8u; return 0; }
write(ram,r[15]+56,r[2],4);
goto P_0c0779fa;
P_0c0779fa: /* original 1f1a, guest PC 0x0c0779fa */
if(!s->budget--) { s->failed_pc=0x0c0779fau; return 0; }
write(ram,r[15]+40,r[1],4);
goto P_0c0779fc;
P_0c0779fc: /* original 50f9, guest PC 0x0c0779fc */
if(!s->budget--) { s->failed_pc=0x0c0779fcu; return 0; }
r[0]=read(ram,r[15]+36,4);
goto P_0c0779fe;
P_0c0779fe: /* original cb80, guest PC 0x0c0779fe */
if(!s->budget--) { s->failed_pc=0x0c0779feu; return 0; }
r[0]|=128u;
goto P_0c077a00;
P_0c077a00: /* original 1f09, guest PC 0x0c077a00 */
if(!s->budget--) { s->failed_pc=0x0c077a00u; return 0; }
write(ram,r[15]+36,r[0],4);
goto P_0c077a02;
P_0c077a02: /* original 50f9, guest PC 0x0c077a02 */
if(!s->budget--) { s->failed_pc=0x0c077a02u; return 0; }
r[0]=read(ram,r[15]+36,4);
goto P_0c077a04;
P_0c077a04: /* original c80f, guest PC 0x0c077a04 */
if(!s->budget--) { s->failed_pc=0x0c077a04u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&15u)==0)!=0);
goto P_0c077a06;
P_0c077a06: /* original 8b08, guest PC 0x0c077a06 */
if(!s->budget--) { s->failed_pc=0x0c077a06u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c077a1a; }
goto P_0c077a08;
P_0c077a08: /* original 61f3, guest PC 0x0c077a08 */
if(!s->budget--) { s->failed_pc=0x0c077a08u; return 0; }
r[1]=r[15];
goto P_0c077a0a;
P_0c077a0a: /* original 7178, guest PC 0x0c077a0a */
if(!s->budget--) { s->failed_pc=0x0c077a0au; return 0; }
r[1]+=0x00000078u;
goto P_0c077a0c;
P_0c077a0c: /* original 6012, guest PC 0x0c077a0c */
if(!s->budget--) { s->failed_pc=0x0c077a0cu; return 0; }
tmp=read(ram,r[1],4);
r[0]=tmp;
goto P_0c077a0e;
P_0c077a0e: /* original e3f0, guest PC 0x0c077a0e */
if(!s->budget--) { s->failed_pc=0x0c077a0eu; return 0; }
r[3]=0xfffffff0u;
goto P_0c077a10;
P_0c077a10: /* original 52f9, guest PC 0x0c077a10 */
if(!s->budget--) { s->failed_pc=0x0c077a10u; return 0; }
r[2]=read(ram,r[15]+36,4);
goto P_0c077a12;
P_0c077a12: /* original c90f, guest PC 0x0c077a12 */
if(!s->budget--) { s->failed_pc=0x0c077a12u; return 0; }
r[0]&=15u;
goto P_0c077a14;
P_0c077a14: /* original 2239, guest PC 0x0c077a14 */
if(!s->budget--) { s->failed_pc=0x0c077a14u; return 0; }
r[2]&=r[3];
goto P_0c077a16;
P_0c077a16: /* original 220b, guest PC 0x0c077a16 */
if(!s->budget--) { s->failed_pc=0x0c077a16u; return 0; }
r[2]|=r[0];
goto P_0c077a18;
P_0c077a18: /* original 1f29, guest PC 0x0c077a18 */
if(!s->budget--) { s->failed_pc=0x0c077a18u; return 0; }
write(ram,r[15]+36,r[2],4);
goto P_0c077a1a;
P_0c077a1a: /* original 50f9, guest PC 0x0c077a1a */
if(!s->budget--) { s->failed_pc=0x0c077a1au; return 0; }
r[0]=read(ram,r[15]+36,4);
goto P_0c077a1c;
P_0c077a1c: /* original 62f3, guest PC 0x0c077a1c */
if(!s->budget--) { s->failed_pc=0x0c077a1cu; return 0; }
r[2]=r[15];
goto P_0c077a1e;
P_0c077a1e: /* original 7278, guest PC 0x0c077a1e */
if(!s->budget--) { s->failed_pc=0x0c077a1eu; return 0; }
r[2]+=0x00000078u;
goto P_0c077a20;
P_0c077a20: /* original c90f, guest PC 0x0c077a20 */
if(!s->budget--) { s->failed_pc=0x0c077a20u; return 0; }
r[0]&=15u;
goto P_0c077a22;
P_0c077a22: /* original 2008, guest PC 0x0c077a22 */
if(!s->budget--) { s->failed_pc=0x0c077a22u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c077a24;
P_0c077a24: /* original 8f02, guest PC 0x0c077a24 */
if(!s->budget--) { s->failed_pc=0x0c077a24u; return 0; }
cond=r[17]&1u;
write(ram,r[2],r[0],4);
if(!cond) { goto P_0c077a2c; }
goto P_0c077a28;
P_0c077a26: /* original 2202, guest PC 0x0c077a26 */
if(!s->budget--) { s->failed_pc=0x0c077a26u; return 0; }
write(ram,r[2],r[0],4);
goto P_0c077a28;
P_0c077a28: /* original a08e, guest PC 0x0c077a28 */
if(!s->budget--) { s->failed_pc=0x0c077a28u; return 0; }
goto P_0c077b48;
P_0c077a2a: /* original 0009, guest PC 0x0c077a2a */
if(!s->budget--) { s->failed_pc=0x0c077a2au; return 0; }
goto P_0c077a2c;
P_0c077a2c: /* original 50f9, guest PC 0x0c077a2c */
if(!s->budget--) { s->failed_pc=0x0c077a2cu; return 0; }
r[0]=read(ram,r[15]+36,4);
goto P_0c077a2e;
P_0c077a2e: /* original c880, guest PC 0x0c077a2e */
if(!s->budget--) { s->failed_pc=0x0c077a2eu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&128u)==0)!=0);
goto P_0c077a30;
P_0c077a30: /* original 8b01, guest PC 0x0c077a30 */
if(!s->budget--) { s->failed_pc=0x0c077a30u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c077a36; }
goto P_0c077a32;
P_0c077a32: /* original a089, guest PC 0x0c077a32 */
if(!s->budget--) { s->failed_pc=0x0c077a32u; return 0; }
goto P_0c077b48;
P_0c077a34: /* original 0009, guest PC 0x0c077a34 */
if(!s->budget--) { s->failed_pc=0x0c077a34u; return 0; }
goto P_0c077a36;
P_0c077a36: /* original 52fa, guest PC 0x0c077a36 */
if(!s->budget--) { s->failed_pc=0x0c077a36u; return 0; }
r[2]=read(ram,r[15]+40,4);
goto P_0c077a38;
P_0c077a38: /* original d323, guest PC 0x0c077a38 */
if(!s->budget--) { s->failed_pc=0x0c077a38u; return 0; }
r[3]=read(ram,0x0c077ac8u,4);
goto P_0c077a3a;
P_0c077a3a: /* original 2238, guest PC 0x0c077a3a */
if(!s->budget--) { s->failed_pc=0x0c077a3au; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c077a3c;
P_0c077a3c: /* original 8902, guest PC 0x0c077a3c */
if(!s->budget--) { s->failed_pc=0x0c077a3cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c077a44; }
goto P_0c077a3e;
P_0c077a3e: /* original 923a, guest PC 0x0c077a3e */
if(!s->budget--) { s->failed_pc=0x0c077a3eu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077ab6u,2);
goto P_0c077a40;
P_0c077a40: /* original a001, guest PC 0x0c077a40 */
if(!s->budget--) { s->failed_pc=0x0c077a40u; return 0; }
goto P_0c077a46;
P_0c077a42: /* original 0009, guest PC 0x0c077a42 */
if(!s->budget--) { s->failed_pc=0x0c077a42u; return 0; }
goto P_0c077a44;
P_0c077a44: /* original 9238, guest PC 0x0c077a44 */
if(!s->budget--) { s->failed_pc=0x0c077a44u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077ab8u,2);
goto P_0c077a46;
P_0c077a46: /* original e078, guest PC 0x0c077a46 */
if(!s->budget--) { s->failed_pc=0x0c077a46u; return 0; }
r[0]=0x00000078u;
goto P_0c077a48;
P_0c077a48: /* original 01fe, guest PC 0x0c077a48 */
if(!s->budget--) { s->failed_pc=0x0c077a48u; return 0; }
r[1]=read(ram,r[15]+r[0],4);
goto P_0c077a4a;
P_0c077a4a: /* original e078, guest PC 0x0c077a4a */
if(!s->budget--) { s->failed_pc=0x0c077a4au; return 0; }
r[0]=0x00000078u;
goto P_0c077a4c;
P_0c077a4c: /* original 312c, guest PC 0x0c077a4c */
if(!s->budget--) { s->failed_pc=0x0c077a4cu; return 0; }
r[1]+=r[2];
goto P_0c077a4e;
P_0c077a4e: /* original 0f16, guest PC 0x0c077a4e */
if(!s->budget--) { s->failed_pc=0x0c077a4eu; return 0; }
write(ram,r[15]+r[0],r[1],4);
goto P_0c077a50;
P_0c077a50: /* original 50f9, guest PC 0x0c077a50 */
if(!s->budget--) { s->failed_pc=0x0c077a50u; return 0; }
r[0]=read(ram,r[15]+36,4);
goto P_0c077a52;
P_0c077a52: /* original cb40, guest PC 0x0c077a52 */
if(!s->budget--) { s->failed_pc=0x0c077a52u; return 0; }
r[0]|=64u;
goto P_0c077a54;
P_0c077a54: /* original 6203, guest PC 0x0c077a54 */
if(!s->budget--) { s->failed_pc=0x0c077a54u; return 0; }
r[2]=r[0];
goto P_0c077a56;
P_0c077a56: /* original 1f09, guest PC 0x0c077a56 */
if(!s->budget--) { s->failed_pc=0x0c077a56u; return 0; }
write(ram,r[15]+36,r[0],4);
goto P_0c077a58;
P_0c077a58: /* original 902b, guest PC 0x0c077a58 */
if(!s->budget--) { s->failed_pc=0x0c077a58u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077ab2u,2);
goto P_0c077a5a;
P_0c077a5a: /* original 0e24, guest PC 0x0c077a5a */
if(!s->budget--) { s->failed_pc=0x0c077a5au; return 0; }
write(ram,r[14]+r[0],r[2],1);
goto P_0c077a5c;
P_0c077a5c: /* original e050, guest PC 0x0c077a5c */
if(!s->budget--) { s->failed_pc=0x0c077a5cu; return 0; }
r[0]=0x00000050u;
goto P_0c077a5e;
P_0c077a5e: /* original 03fe, guest PC 0x0c077a5e */
if(!s->budget--) { s->failed_pc=0x0c077a5eu; return 0; }
r[3]=read(ram,r[15]+r[0],4);
goto P_0c077a60;
P_0c077a60: /* original e04c, guest PC 0x0c077a60 */
if(!s->budget--) { s->failed_pc=0x0c077a60u; return 0; }
r[0]=0x0000004cu;
goto P_0c077a62;
P_0c077a62: /* original 2f36, guest PC 0x0c077a62 */
if(!s->budget--) { s->failed_pc=0x0c077a62u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c077a64;
P_0c077a64: /* original 52f2, guest PC 0x0c077a64 */
if(!s->budget--) { s->failed_pc=0x0c077a64u; return 0; }
r[2]=read(ram,r[15]+8,4);
goto P_0c077a66;
P_0c077a66: /* original 2f26, guest PC 0x0c077a66 */
if(!s->budget--) { s->failed_pc=0x0c077a66u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c077a68;
P_0c077a68: /* original 03fe, guest PC 0x0c077a68 */
if(!s->budget--) { s->failed_pc=0x0c077a68u; return 0; }
r[3]=read(ram,r[15]+r[0],4);
goto P_0c077a6a;
P_0c077a6a: /* original e04c, guest PC 0x0c077a6a */
if(!s->budget--) { s->failed_pc=0x0c077a6au; return 0; }
r[0]=0x0000004cu;
goto P_0c077a6c;
P_0c077a6c: /* original 2f36, guest PC 0x0c077a6c */
if(!s->budget--) { s->failed_pc=0x0c077a6cu; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c077a6e;
P_0c077a6e: /* original 02fe, guest PC 0x0c077a6e */
if(!s->budget--) { s->failed_pc=0x0c077a6eu; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c077a70;
P_0c077a70: /* original 2f26, guest PC 0x0c077a70 */
if(!s->budget--) { s->failed_pc=0x0c077a70u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c077a72;
P_0c077a72: /* original 9022, guest PC 0x0c077a72 */
if(!s->budget--) { s->failed_pc=0x0c077a72u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077abau,2);
goto P_0c077a74;
P_0c077a74: /* original 03fe, guest PC 0x0c077a74 */
if(!s->budget--) { s->failed_pc=0x0c077a74u; return 0; }
r[3]=read(ram,r[15]+r[0],4);
goto P_0c077a76;
P_0c077a76: /* original e05c, guest PC 0x0c077a76 */
if(!s->budget--) { s->failed_pc=0x0c077a76u; return 0; }
r[0]=0x0000005cu;
goto P_0c077a78;
P_0c077a78: /* original 2f36, guest PC 0x0c077a78 */
if(!s->budget--) { s->failed_pc=0x0c077a78u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c077a7a;
P_0c077a7a: /* original 02fe, guest PC 0x0c077a7a */
if(!s->budget--) { s->failed_pc=0x0c077a7au; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c077a7c;
P_0c077a7c: /* original 2f26, guest PC 0x0c077a7c */
if(!s->budget--) { s->failed_pc=0x0c077a7cu; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c077a7e;
P_0c077a7e: /* original 931d, guest PC 0x0c077a7e */
if(!s->budget--) { s->failed_pc=0x0c077a7eu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077abcu,2);
goto P_0c077a80;
P_0c077a80: /* original 33fc, guest PC 0x0c077a80 */
if(!s->budget--) { s->failed_pc=0x0c077a80u; return 0; }
r[3]+=r[15];
goto P_0c077a82;
P_0c077a82: /* original 2f36, guest PC 0x0c077a82 */
if(!s->budget--) { s->failed_pc=0x0c077a82u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c077a84;
P_0c077a84: /* original 901a, guest PC 0x0c077a84 */
if(!s->budget--) { s->failed_pc=0x0c077a84u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077abcu,2);
goto P_0c077a86;
P_0c077a86: /* original 02fe, guest PC 0x0c077a86 */
if(!s->budget--) { s->failed_pc=0x0c077a86u; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c077a88;
P_0c077a88: /* original 65e3, guest PC 0x0c077a88 */
if(!s->budget--) { s->failed_pc=0x0c077a88u; return 0; }
r[5]=r[14];
goto P_0c077a8a;
P_0c077a8a: /* original 66d3, guest PC 0x0c077a8a */
if(!s->budget--) { s->failed_pc=0x0c077a8au; return 0; }
r[6]=r[13];
goto P_0c077a8c;
P_0c077a8c: /* original 2f26, guest PC 0x0c077a8c */
if(!s->budget--) { s->failed_pc=0x0c077a8cu; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c077a8e;
P_0c077a8e: /* original 9014, guest PC 0x0c077a8e */
if(!s->budget--) { s->failed_pc=0x0c077a8eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077abau,2);
goto P_0c077a90;
P_0c077a90: /* original 03fe, guest PC 0x0c077a90 */
if(!s->budget--) { s->failed_pc=0x0c077a90u; return 0; }
r[3]=read(ram,r[15]+r[0],4);
goto P_0c077a92;
P_0c077a92: /* original 2f36, guest PC 0x0c077a92 */
if(!s->budget--) { s->failed_pc=0x0c077a92u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c077a94;
P_0c077a94: /* original 9013, guest PC 0x0c077a94 */
if(!s->budget--) { s->failed_pc=0x0c077a94u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077abeu,2);
goto P_0c077a96;
P_0c077a96: /* original 02fe, guest PC 0x0c077a96 */
if(!s->budget--) { s->failed_pc=0x0c077a96u; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c077a98;
P_0c077a98: /* original 2f26, guest PC 0x0c077a98 */
if(!s->budget--) { s->failed_pc=0x0c077a98u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c077a9a;
P_0c077a9a: /* original 9710, guest PC 0x0c077a9a */
if(!s->budget--) { s->failed_pc=0x0c077a9au; return 0; }
r[7]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077abeu,2);
goto P_0c077a9c;
P_0c077a9c: /* original 37fc, guest PC 0x0c077a9c */
if(!s->budget--) { s->failed_pc=0x0c077a9cu; return 0; }
r[7]+=r[15];
goto P_0c077a9e;
P_0c077a9e: /* original b38c, guest PC 0x0c077a9e */
if(!s->budget--) { s->failed_pc=0x0c077a9eu; return 0; }
target=0x0c0781bau; r[16]=0x8c077aa2u;
r[4]=r[12];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c077aa2u) { target=s->pc; goto dispatch; }
goto P_0c077aa2;
P_0c077aa0: /* original 64c3, guest PC 0x0c077aa0 */
if(!s->budget--) { s->failed_pc=0x0c077aa0u; return 0; }
r[4]=r[12];
goto P_0c077aa2;
P_0c077aa2: /* original 2008, guest PC 0x0c077aa2 */
if(!s->budget--) { s->failed_pc=0x0c077aa2u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c077aa4;
P_0c077aa4: /* original 8d02, guest PC 0x0c077aa4 */
if(!s->budget--) { s->failed_pc=0x0c077aa4u; return 0; }
cond=r[17]&1u;
r[15]+=0x00000028u;
if(cond) { goto P_0c077aac; }
goto P_0c077aa8;
P_0c077aa6: /* original 7f28, guest PC 0x0c077aa6 */
if(!s->budget--) { s->failed_pc=0x0c077aa6u; return 0; }
r[15]+=0x00000028u;
goto P_0c077aa8;
P_0c077aa8: /* original a1ca, guest PC 0x0c077aa8 */
if(!s->budget--) { s->failed_pc=0x0c077aa8u; return 0; }
goto P_0c077e40;
P_0c077aaa: /* original 0009, guest PC 0x0c077aaa */
if(!s->budget--) { s->failed_pc=0x0c077aaau; return 0; }
goto P_0c077aac;
P_0c077aac: /* original a1b3, guest PC 0x0c077aac */
if(!s->budget--) { s->failed_pc=0x0c077aacu; return 0; }
goto P_0c077e16;
P_0c077aae: /* original 0009, guest PC 0x0c077aae */
if(!s->budget--) { s->failed_pc=0x0c077aaeu; return 0; }
return vf3_matrix_family(0x0c077ab0u,s,ram);
P_0c077ad0: /* original 61f3, guest PC 0x0c077ad0 */
if(!s->budget--) { s->failed_pc=0x0c077ad0u; return 0; }
r[1]=r[15];
goto P_0c077ad2;
P_0c077ad2: /* original 7178, guest PC 0x0c077ad2 */
if(!s->budget--) { s->failed_pc=0x0c077ad2u; return 0; }
r[1]+=0x00000078u;
goto P_0c077ad4;
P_0c077ad4: /* original 6012, guest PC 0x0c077ad4 */
if(!s->budget--) { s->failed_pc=0x0c077ad4u; return 0; }
tmp=read(ram,r[1],4);
r[0]=tmp;
goto P_0c077ad6;
P_0c077ad6: /* original c80f, guest PC 0x0c077ad6 */
if(!s->budget--) { s->failed_pc=0x0c077ad6u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&15u)==0)!=0);
goto P_0c077ad8;
P_0c077ad8: /* original 8936, guest PC 0x0c077ad8 */
if(!s->budget--) { s->failed_pc=0x0c077ad8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c077b48; }
goto P_0c077ada;
P_0c077ada: /* original 52fa, guest PC 0x0c077ada */
if(!s->budget--) { s->failed_pc=0x0c077adau; return 0; }
r[2]=read(ram,r[15]+40,4);
goto P_0c077adc;
P_0c077adc: /* original d334, guest PC 0x0c077adc */
if(!s->budget--) { s->failed_pc=0x0c077adcu; return 0; }
r[3]=read(ram,0x0c077bb0u,4);
goto P_0c077ade;
P_0c077ade: /* original 2238, guest PC 0x0c077ade */
if(!s->budget--) { s->failed_pc=0x0c077adeu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c077ae0;
P_0c077ae0: /* original 8b02, guest PC 0x0c077ae0 */
if(!s->budget--) { s->failed_pc=0x0c077ae0u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c077ae8; }
goto P_0c077ae2;
P_0c077ae2: /* original 925d, guest PC 0x0c077ae2 */
if(!s->budget--) { s->failed_pc=0x0c077ae2u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077ba0u,2);
goto P_0c077ae4;
P_0c077ae4: /* original a001, guest PC 0x0c077ae4 */
if(!s->budget--) { s->failed_pc=0x0c077ae4u; return 0; }
goto P_0c077aea;
P_0c077ae6: /* original 0009, guest PC 0x0c077ae6 */
if(!s->budget--) { s->failed_pc=0x0c077ae6u; return 0; }
goto P_0c077ae8;
P_0c077ae8: /* original 925b, guest PC 0x0c077ae8 */
if(!s->budget--) { s->failed_pc=0x0c077ae8u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077ba2u,2);
goto P_0c077aea;
P_0c077aea: /* original e078, guest PC 0x0c077aea */
if(!s->budget--) { s->failed_pc=0x0c077aeau; return 0; }
r[0]=0x00000078u;
goto P_0c077aec;
P_0c077aec: /* original 01fe, guest PC 0x0c077aec */
if(!s->budget--) { s->failed_pc=0x0c077aecu; return 0; }
r[1]=read(ram,r[15]+r[0],4);
goto P_0c077aee;
P_0c077aee: /* original e078, guest PC 0x0c077aee */
if(!s->budget--) { s->failed_pc=0x0c077aeeu; return 0; }
r[0]=0x00000078u;
goto P_0c077af0;
P_0c077af0: /* original 312c, guest PC 0x0c077af0 */
if(!s->budget--) { s->failed_pc=0x0c077af0u; return 0; }
r[1]+=r[2];
goto P_0c077af2;
P_0c077af2: /* original 0f16, guest PC 0x0c077af2 */
if(!s->budget--) { s->failed_pc=0x0c077af2u; return 0; }
write(ram,r[15]+r[0],r[1],4);
goto P_0c077af4;
P_0c077af4: /* original e050, guest PC 0x0c077af4 */
if(!s->budget--) { s->failed_pc=0x0c077af4u; return 0; }
r[0]=0x00000050u;
goto P_0c077af6;
P_0c077af6: /* original 03fe, guest PC 0x0c077af6 */
if(!s->budget--) { s->failed_pc=0x0c077af6u; return 0; }
r[3]=read(ram,r[15]+r[0],4);
goto P_0c077af8;
P_0c077af8: /* original e04c, guest PC 0x0c077af8 */
if(!s->budget--) { s->failed_pc=0x0c077af8u; return 0; }
r[0]=0x0000004cu;
goto P_0c077afa;
P_0c077afa: /* original 2f36, guest PC 0x0c077afa */
if(!s->budget--) { s->failed_pc=0x0c077afau; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c077afc;
P_0c077afc: /* original 52f2, guest PC 0x0c077afc */
if(!s->budget--) { s->failed_pc=0x0c077afcu; return 0; }
r[2]=read(ram,r[15]+8,4);
goto P_0c077afe;
P_0c077afe: /* original 2f26, guest PC 0x0c077afe */
if(!s->budget--) { s->failed_pc=0x0c077afeu; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c077b00;
P_0c077b00: /* original 03fe, guest PC 0x0c077b00 */
if(!s->budget--) { s->failed_pc=0x0c077b00u; return 0; }
r[3]=read(ram,r[15]+r[0],4);
goto P_0c077b02;
P_0c077b02: /* original e04c, guest PC 0x0c077b02 */
if(!s->budget--) { s->failed_pc=0x0c077b02u; return 0; }
r[0]=0x0000004cu;
goto P_0c077b04;
P_0c077b04: /* original 2f36, guest PC 0x0c077b04 */
if(!s->budget--) { s->failed_pc=0x0c077b04u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c077b06;
P_0c077b06: /* original 02fe, guest PC 0x0c077b06 */
if(!s->budget--) { s->failed_pc=0x0c077b06u; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c077b08;
P_0c077b08: /* original 2f26, guest PC 0x0c077b08 */
if(!s->budget--) { s->failed_pc=0x0c077b08u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c077b0a;
P_0c077b0a: /* original 904b, guest PC 0x0c077b0a */
if(!s->budget--) { s->failed_pc=0x0c077b0au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077ba4u,2);
goto P_0c077b0c;
P_0c077b0c: /* original 03fe, guest PC 0x0c077b0c */
if(!s->budget--) { s->failed_pc=0x0c077b0cu; return 0; }
r[3]=read(ram,r[15]+r[0],4);
goto P_0c077b0e;
P_0c077b0e: /* original e05c, guest PC 0x0c077b0e */
if(!s->budget--) { s->failed_pc=0x0c077b0eu; return 0; }
r[0]=0x0000005cu;
goto P_0c077b10;
P_0c077b10: /* original 2f36, guest PC 0x0c077b10 */
if(!s->budget--) { s->failed_pc=0x0c077b10u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c077b12;
P_0c077b12: /* original 02fe, guest PC 0x0c077b12 */
if(!s->budget--) { s->failed_pc=0x0c077b12u; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c077b14;
P_0c077b14: /* original 2f26, guest PC 0x0c077b14 */
if(!s->budget--) { s->failed_pc=0x0c077b14u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c077b16;
P_0c077b16: /* original 9346, guest PC 0x0c077b16 */
if(!s->budget--) { s->failed_pc=0x0c077b16u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077ba6u,2);
goto P_0c077b18;
P_0c077b18: /* original 33fc, guest PC 0x0c077b18 */
if(!s->budget--) { s->failed_pc=0x0c077b18u; return 0; }
r[3]+=r[15];
goto P_0c077b1a;
P_0c077b1a: /* original 2f36, guest PC 0x0c077b1a */
if(!s->budget--) { s->failed_pc=0x0c077b1au; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c077b1c;
P_0c077b1c: /* original 9043, guest PC 0x0c077b1c */
if(!s->budget--) { s->failed_pc=0x0c077b1cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077ba6u,2);
goto P_0c077b1e;
P_0c077b1e: /* original 02fe, guest PC 0x0c077b1e */
if(!s->budget--) { s->failed_pc=0x0c077b1eu; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c077b20;
P_0c077b20: /* original 2f26, guest PC 0x0c077b20 */
if(!s->budget--) { s->failed_pc=0x0c077b20u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c077b22;
P_0c077b22: /* original 903f, guest PC 0x0c077b22 */
if(!s->budget--) { s->failed_pc=0x0c077b22u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077ba4u,2);
goto P_0c077b24;
P_0c077b24: /* original 03fe, guest PC 0x0c077b24 */
if(!s->budget--) { s->failed_pc=0x0c077b24u; return 0; }
r[3]=read(ram,r[15]+r[0],4);
goto P_0c077b26;
P_0c077b26: /* original 2f36, guest PC 0x0c077b26 */
if(!s->budget--) { s->failed_pc=0x0c077b26u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c077b28;
P_0c077b28: /* original 903e, guest PC 0x0c077b28 */
if(!s->budget--) { s->failed_pc=0x0c077b28u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077ba8u,2);
goto P_0c077b2a;
P_0c077b2a: /* original 02fe, guest PC 0x0c077b2a */
if(!s->budget--) { s->failed_pc=0x0c077b2au; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c077b2c;
P_0c077b2c: /* original 65e3, guest PC 0x0c077b2c */
if(!s->budget--) { s->failed_pc=0x0c077b2cu; return 0; }
r[5]=r[14];
goto P_0c077b2e;
P_0c077b2e: /* original 66d3, guest PC 0x0c077b2e */
if(!s->budget--) { s->failed_pc=0x0c077b2eu; return 0; }
r[6]=r[13];
goto P_0c077b30;
P_0c077b30: /* original 2f26, guest PC 0x0c077b30 */
if(!s->budget--) { s->failed_pc=0x0c077b30u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c077b32;
P_0c077b32: /* original 9739, guest PC 0x0c077b32 */
if(!s->budget--) { s->failed_pc=0x0c077b32u; return 0; }
r[7]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077ba8u,2);
goto P_0c077b34;
P_0c077b34: /* original 37fc, guest PC 0x0c077b34 */
if(!s->budget--) { s->failed_pc=0x0c077b34u; return 0; }
r[7]+=r[15];
goto P_0c077b36;
P_0c077b36: /* original b340, guest PC 0x0c077b36 */
if(!s->budget--) { s->failed_pc=0x0c077b36u; return 0; }
target=0x0c0781bau; r[16]=0x8c077b3au;
r[4]=r[12];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c077b3au) { target=s->pc; goto dispatch; }
goto P_0c077b3a;
P_0c077b38: /* original 64c3, guest PC 0x0c077b38 */
if(!s->budget--) { s->failed_pc=0x0c077b38u; return 0; }
r[4]=r[12];
goto P_0c077b3a;
P_0c077b3a: /* original 2008, guest PC 0x0c077b3a */
if(!s->budget--) { s->failed_pc=0x0c077b3au; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c077b3c;
P_0c077b3c: /* original 8d02, guest PC 0x0c077b3c */
if(!s->budget--) { s->failed_pc=0x0c077b3cu; return 0; }
cond=r[17]&1u;
r[15]+=0x00000028u;
if(cond) { goto P_0c077b44; }
goto P_0c077b40;
P_0c077b3e: /* original 7f28, guest PC 0x0c077b3e */
if(!s->budget--) { s->failed_pc=0x0c077b3eu; return 0; }
r[15]+=0x00000028u;
goto P_0c077b40;
P_0c077b40: /* original a17e, guest PC 0x0c077b40 */
if(!s->budget--) { s->failed_pc=0x0c077b40u; return 0; }
goto P_0c077e40;
P_0c077b42: /* original 0009, guest PC 0x0c077b42 */
if(!s->budget--) { s->failed_pc=0x0c077b42u; return 0; }
goto P_0c077b44;
P_0c077b44: /* original a167, guest PC 0x0c077b44 */
if(!s->budget--) { s->failed_pc=0x0c077b44u; return 0; }
goto P_0c077e16;
P_0c077b46: /* original 0009, guest PC 0x0c077b46 */
if(!s->budget--) { s->failed_pc=0x0c077b46u; return 0; }
goto P_0c077b48;
P_0c077b48: /* original 902f, guest PC 0x0c077b48 */
if(!s->budget--) { s->failed_pc=0x0c077b48u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077baau,2);
goto P_0c077b4a;
P_0c077b4a: /* original 53f9, guest PC 0x0c077b4a */
if(!s->budget--) { s->failed_pc=0x0c077b4au; return 0; }
r[3]=read(ram,r[15]+36,4);
goto P_0c077b4c;
P_0c077b4c: /* original 0e34, guest PC 0x0c077b4c */
if(!s->budget--) { s->failed_pc=0x0c077b4cu; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c077b4e;
P_0c077b4e: /* original 52fe, guest PC 0x0c077b4e */
if(!s->budget--) { s->failed_pc=0x0c077b4eu; return 0; }
r[2]=read(ram,r[15]+56,4);
goto P_0c077b50;
P_0c077b50: /* original 2228, guest PC 0x0c077b50 */
if(!s->budget--) { s->failed_pc=0x0c077b50u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c077b52;
P_0c077b52: /* original 8b01, guest PC 0x0c077b52 */
if(!s->budget--) { s->failed_pc=0x0c077b52u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c077b58; }
goto P_0c077b54;
P_0c077b54: /* original a0a8, guest PC 0x0c077b54 */
if(!s->budget--) { s->failed_pc=0x0c077b54u; return 0; }
goto P_0c077ca8;
P_0c077b56: /* original 0009, guest PC 0x0c077b56 */
if(!s->budget--) { s->failed_pc=0x0c077b56u; return 0; }
goto P_0c077b58;
P_0c077b58: /* original 51fe, guest PC 0x0c077b58 */
if(!s->budget--) { s->failed_pc=0x0c077b58u; return 0; }
r[1]=read(ram,r[15]+56,4);
goto P_0c077b5a;
P_0c077b5a: /* original a15c, guest PC 0x0c077b5a */
if(!s->budget--) { s->failed_pc=0x0c077b5au; return 0; }
write(ram,r[14]+48,r[1],4);
goto P_0c077e16;
P_0c077b5c: /* original 1e1c, guest PC 0x0c077b5c */
if(!s->budget--) { s->failed_pc=0x0c077b5cu; return 0; }
write(ram,r[14]+48,r[1],4);
goto P_0c077b5e;
P_0c077b5e: /* original e078, guest PC 0x0c077b5e */
if(!s->budget--) { s->failed_pc=0x0c077b5eu; return 0; }
r[0]=0x00000078u;
goto P_0c077b60;
P_0c077b60: /* original 02fe, guest PC 0x0c077b60 */
if(!s->budget--) { s->failed_pc=0x0c077b60u; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c077b62;
P_0c077b62: /* original 2228, guest PC 0x0c077b62 */
if(!s->budget--) { s->failed_pc=0x0c077b62u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c077b64;
P_0c077b64: /* original 8965, guest PC 0x0c077b64 */
if(!s->budget--) { s->failed_pc=0x0c077b64u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c077c32; }
goto P_0c077b66;
P_0c077b66: /* original e04c, guest PC 0x0c077b66 */
if(!s->budget--) { s->failed_pc=0x0c077b66u; return 0; }
r[0]=0x0000004cu;
goto P_0c077b68;
P_0c077b68: /* original 03ee, guest PC 0x0c077b68 */
if(!s->budget--) { s->failed_pc=0x0c077b68u; return 0; }
r[3]=read(ram,r[14]+r[0],4);
goto P_0c077b6a;
P_0c077b6a: /* original e06c, guest PC 0x0c077b6a */
if(!s->budget--) { s->failed_pc=0x0c077b6au; return 0; }
r[0]=0x0000006cu;
goto P_0c077b6c;
P_0c077b6c: /* original 0f36, guest PC 0x0c077b6c */
if(!s->budget--) { s->failed_pc=0x0c077b6cu; return 0; }
write(ram,r[15]+r[0],r[3],4);
goto P_0c077b6e;
P_0c077b6e: /* original e06c, guest PC 0x0c077b6e */
if(!s->budget--) { s->failed_pc=0x0c077b6eu; return 0; }
r[0]=0x0000006cu;
goto P_0c077b70;
P_0c077b70: /* original 02fe, guest PC 0x0c077b70 */
if(!s->budget--) { s->failed_pc=0x0c077b70u; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c077b72;
P_0c077b72: /* original d310, guest PC 0x0c077b72 */
if(!s->budget--) { s->failed_pc=0x0c077b72u; return 0; }
r[3]=read(ram,0x0c077bb4u,4);
goto P_0c077b74;
P_0c077b74: /* original 2238, guest PC 0x0c077b74 */
if(!s->budget--) { s->failed_pc=0x0c077b74u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c077b76;
P_0c077b76: /* original 8906, guest PC 0x0c077b76 */
if(!s->budget--) { s->failed_pc=0x0c077b76u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c077b86; }
goto P_0c077b78;
P_0c077b78: /* original e078, guest PC 0x0c077b78 */
if(!s->budget--) { s->failed_pc=0x0c077b78u; return 0; }
r[0]=0x00000078u;
goto P_0c077b7a;
P_0c077b7a: /* original 9217, guest PC 0x0c077b7a */
if(!s->budget--) { s->failed_pc=0x0c077b7au; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077bacu,2);
goto P_0c077b7c;
P_0c077b7c: /* original 01fe, guest PC 0x0c077b7c */
if(!s->budget--) { s->failed_pc=0x0c077b7cu; return 0; }
r[1]=read(ram,r[15]+r[0],4);
goto P_0c077b7e;
P_0c077b7e: /* original e078, guest PC 0x0c077b7e */
if(!s->budget--) { s->failed_pc=0x0c077b7eu; return 0; }
r[0]=0x00000078u;
goto P_0c077b80;
P_0c077b80: /* original 312c, guest PC 0x0c077b80 */
if(!s->budget--) { s->failed_pc=0x0c077b80u; return 0; }
r[1]+=r[2];
goto P_0c077b82;
P_0c077b82: /* original a027, guest PC 0x0c077b82 */
if(!s->budget--) { s->failed_pc=0x0c077b82u; return 0; }
write(ram,r[15]+r[0],r[1],4);
goto P_0c077bd4;
P_0c077b84: /* original 0f16, guest PC 0x0c077b84 */
if(!s->budget--) { s->failed_pc=0x0c077b84u; return 0; }
write(ram,r[15]+r[0],r[1],4);
goto P_0c077b86;
P_0c077b86: /* original e06c, guest PC 0x0c077b86 */
if(!s->budget--) { s->failed_pc=0x0c077b86u; return 0; }
r[0]=0x0000006cu;
goto P_0c077b88;
P_0c077b88: /* original d20b, guest PC 0x0c077b88 */
if(!s->budget--) { s->failed_pc=0x0c077b88u; return 0; }
r[2]=read(ram,0x0c077bb8u,4);
goto P_0c077b8a;
P_0c077b8a: /* original 01fe, guest PC 0x0c077b8a */
if(!s->budget--) { s->failed_pc=0x0c077b8au; return 0; }
r[1]=read(ram,r[15]+r[0],4);
goto P_0c077b8c;
P_0c077b8c: /* original 2128, guest PC 0x0c077b8c */
if(!s->budget--) { s->failed_pc=0x0c077b8cu; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[2])==0)!=0);
goto P_0c077b8e;
P_0c077b8e: /* original 8915, guest PC 0x0c077b8e */
if(!s->budget--) { s->failed_pc=0x0c077b8eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c077bbc; }
goto P_0c077b90;
P_0c077b90: /* original e078, guest PC 0x0c077b90 */
if(!s->budget--) { s->failed_pc=0x0c077b90u; return 0; }
r[0]=0x00000078u;
goto P_0c077b92;
P_0c077b92: /* original 910c, guest PC 0x0c077b92 */
if(!s->budget--) { s->failed_pc=0x0c077b92u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077baeu,2);
goto P_0c077b94;
P_0c077b94: /* original 00fe, guest PC 0x0c077b94 */
if(!s->budget--) { s->failed_pc=0x0c077b94u; return 0; }
r[0]=read(ram,r[15]+r[0],4);
goto P_0c077b96;
P_0c077b96: /* original 63f3, guest PC 0x0c077b96 */
if(!s->budget--) { s->failed_pc=0x0c077b96u; return 0; }
r[3]=r[15];
goto P_0c077b98;
P_0c077b98: /* original 7378, guest PC 0x0c077b98 */
if(!s->budget--) { s->failed_pc=0x0c077b98u; return 0; }
r[3]+=0x00000078u;
goto P_0c077b9a;
P_0c077b9a: /* original 301c, guest PC 0x0c077b9a */
if(!s->budget--) { s->failed_pc=0x0c077b9au; return 0; }
r[0]+=r[1];
goto P_0c077b9c;
P_0c077b9c: /* original a01a, guest PC 0x0c077b9c */
if(!s->budget--) { s->failed_pc=0x0c077b9cu; return 0; }
write(ram,r[3],r[0],4);
goto P_0c077bd4;
P_0c077b9e: /* original 2302, guest PC 0x0c077b9e */
if(!s->budget--) { s->failed_pc=0x0c077b9eu; return 0; }
write(ram,r[3],r[0],4);
return vf3_matrix_family(0x0c077ba0u,s,ram);
P_0c077bbc: /* original 909b, guest PC 0x0c077bbc */
if(!s->budget--) { s->failed_pc=0x0c077bbcu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077cf6u,2);
goto P_0c077bbe;
P_0c077bbe: /* original d153, guest PC 0x0c077bbe */
if(!s->budget--) { s->failed_pc=0x0c077bbeu; return 0; }
r[1]=read(ram,0x0c077d0cu,4);
goto P_0c077bc0;
P_0c077bc0: /* original 00fe, guest PC 0x0c077bc0 */
if(!s->budget--) { s->failed_pc=0x0c077bc0u; return 0; }
r[0]=read(ram,r[15]+r[0],4);
goto P_0c077bc2;
P_0c077bc2: /* original 2018, guest PC 0x0c077bc2 */
if(!s->budget--) { s->failed_pc=0x0c077bc2u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[1])==0)!=0);
goto P_0c077bc4;
P_0c077bc4: /* original 8906, guest PC 0x0c077bc4 */
if(!s->budget--) { s->failed_pc=0x0c077bc4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c077bd4; }
goto P_0c077bc6;
P_0c077bc6: /* original e078, guest PC 0x0c077bc6 */
if(!s->budget--) { s->failed_pc=0x0c077bc6u; return 0; }
r[0]=0x00000078u;
goto P_0c077bc8;
P_0c077bc8: /* original 9396, guest PC 0x0c077bc8 */
if(!s->budget--) { s->failed_pc=0x0c077bc8u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077cf8u,2);
goto P_0c077bca;
P_0c077bca: /* original 00fe, guest PC 0x0c077bca */
if(!s->budget--) { s->failed_pc=0x0c077bcau; return 0; }
r[0]=read(ram,r[15]+r[0],4);
goto P_0c077bcc;
P_0c077bcc: /* original 62f3, guest PC 0x0c077bcc */
if(!s->budget--) { s->failed_pc=0x0c077bccu; return 0; }
r[2]=r[15];
goto P_0c077bce;
P_0c077bce: /* original 7278, guest PC 0x0c077bce */
if(!s->budget--) { s->failed_pc=0x0c077bceu; return 0; }
r[2]+=0x00000078u;
goto P_0c077bd0;
P_0c077bd0: /* original 303c, guest PC 0x0c077bd0 */
if(!s->budget--) { s->failed_pc=0x0c077bd0u; return 0; }
r[0]+=r[3];
goto P_0c077bd2;
P_0c077bd2: /* original 2202, guest PC 0x0c077bd2 */
if(!s->budget--) { s->failed_pc=0x0c077bd2u; return 0; }
write(ram,r[2],r[0],4);
goto P_0c077bd4;
P_0c077bd4: /* original e050, guest PC 0x0c077bd4 */
if(!s->budget--) { s->failed_pc=0x0c077bd4u; return 0; }
r[0]=0x00000050u;
goto P_0c077bd6;
P_0c077bd6: /* original 66d3, guest PC 0x0c077bd6 */
if(!s->budget--) { s->failed_pc=0x0c077bd6u; return 0; }
r[6]=r[13];
goto P_0c077bd8;
P_0c077bd8: /* original 01fe, guest PC 0x0c077bd8 */
if(!s->budget--) { s->failed_pc=0x0c077bd8u; return 0; }
r[1]=read(ram,r[15]+r[0],4);
goto P_0c077bda;
P_0c077bda: /* original e04c, guest PC 0x0c077bda */
if(!s->budget--) { s->failed_pc=0x0c077bdau; return 0; }
r[0]=0x0000004cu;
goto P_0c077bdc;
P_0c077bdc: /* original 2f16, guest PC 0x0c077bdc */
if(!s->budget--) { s->failed_pc=0x0c077bdcu; return 0; }
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c077bde;
P_0c077bde: /* original 53f2, guest PC 0x0c077bde */
if(!s->budget--) { s->failed_pc=0x0c077bdeu; return 0; }
r[3]=read(ram,r[15]+8,4);
goto P_0c077be0;
P_0c077be0: /* original 2f36, guest PC 0x0c077be0 */
if(!s->budget--) { s->failed_pc=0x0c077be0u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c077be2;
P_0c077be2: /* original 02fe, guest PC 0x0c077be2 */
if(!s->budget--) { s->failed_pc=0x0c077be2u; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c077be4;
P_0c077be4: /* original e04c, guest PC 0x0c077be4 */
if(!s->budget--) { s->failed_pc=0x0c077be4u; return 0; }
r[0]=0x0000004cu;
goto P_0c077be6;
P_0c077be6: /* original 2f26, guest PC 0x0c077be6 */
if(!s->budget--) { s->failed_pc=0x0c077be6u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c077be8;
P_0c077be8: /* original 03fe, guest PC 0x0c077be8 */
if(!s->budget--) { s->failed_pc=0x0c077be8u; return 0; }
r[3]=read(ram,r[15]+r[0],4);
goto P_0c077bea;
P_0c077bea: /* original 2f36, guest PC 0x0c077bea */
if(!s->budget--) { s->failed_pc=0x0c077beau; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c077bec;
P_0c077bec: /* original 9085, guest PC 0x0c077bec */
if(!s->budget--) { s->failed_pc=0x0c077becu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077cfau,2);
goto P_0c077bee;
P_0c077bee: /* original 02fe, guest PC 0x0c077bee */
if(!s->budget--) { s->failed_pc=0x0c077beeu; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c077bf0;
P_0c077bf0: /* original e05c, guest PC 0x0c077bf0 */
if(!s->budget--) { s->failed_pc=0x0c077bf0u; return 0; }
r[0]=0x0000005cu;
goto P_0c077bf2;
P_0c077bf2: /* original 2f26, guest PC 0x0c077bf2 */
if(!s->budget--) { s->failed_pc=0x0c077bf2u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c077bf4;
P_0c077bf4: /* original 03fe, guest PC 0x0c077bf4 */
if(!s->budget--) { s->failed_pc=0x0c077bf4u; return 0; }
r[3]=read(ram,r[15]+r[0],4);
goto P_0c077bf6;
P_0c077bf6: /* original 2f36, guest PC 0x0c077bf6 */
if(!s->budget--) { s->failed_pc=0x0c077bf6u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c077bf8;
P_0c077bf8: /* original 9280, guest PC 0x0c077bf8 */
if(!s->budget--) { s->failed_pc=0x0c077bf8u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077cfcu,2);
goto P_0c077bfa;
P_0c077bfa: /* original 32fc, guest PC 0x0c077bfa */
if(!s->budget--) { s->failed_pc=0x0c077bfau; return 0; }
r[2]+=r[15];
goto P_0c077bfc;
P_0c077bfc: /* original 2f26, guest PC 0x0c077bfc */
if(!s->budget--) { s->failed_pc=0x0c077bfcu; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c077bfe;
P_0c077bfe: /* original 907d, guest PC 0x0c077bfe */
if(!s->budget--) { s->failed_pc=0x0c077bfeu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077cfcu,2);
goto P_0c077c00;
P_0c077c00: /* original 03fe, guest PC 0x0c077c00 */
if(!s->budget--) { s->failed_pc=0x0c077c00u; return 0; }
r[3]=read(ram,r[15]+r[0],4);
goto P_0c077c02;
P_0c077c02: /* original 2f36, guest PC 0x0c077c02 */
if(!s->budget--) { s->failed_pc=0x0c077c02u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c077c04;
P_0c077c04: /* original 9079, guest PC 0x0c077c04 */
if(!s->budget--) { s->failed_pc=0x0c077c04u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077cfau,2);
goto P_0c077c06;
P_0c077c06: /* original 02fe, guest PC 0x0c077c06 */
if(!s->budget--) { s->failed_pc=0x0c077c06u; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c077c08;
P_0c077c08: /* original 2f26, guest PC 0x0c077c08 */
if(!s->budget--) { s->failed_pc=0x0c077c08u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c077c0a;
P_0c077c0a: /* original 9078, guest PC 0x0c077c0a */
if(!s->budget--) { s->failed_pc=0x0c077c0au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077cfeu,2);
goto P_0c077c0c;
P_0c077c0c: /* original 03fe, guest PC 0x0c077c0c */
if(!s->budget--) { s->failed_pc=0x0c077c0cu; return 0; }
r[3]=read(ram,r[15]+r[0],4);
goto P_0c077c0e;
P_0c077c0e: /* original 2f36, guest PC 0x0c077c0e */
if(!s->budget--) { s->failed_pc=0x0c077c0eu; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c077c10;
P_0c077c10: /* original 9775, guest PC 0x0c077c10 */
if(!s->budget--) { s->failed_pc=0x0c077c10u; return 0; }
r[7]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077cfeu,2);
goto P_0c077c12;
P_0c077c12: /* original 37fc, guest PC 0x0c077c12 */
if(!s->budget--) { s->failed_pc=0x0c077c12u; return 0; }
r[7]+=r[15];
goto P_0c077c14;
P_0c077c14: /* original 65e3, guest PC 0x0c077c14 */
if(!s->budget--) { s->failed_pc=0x0c077c14u; return 0; }
r[5]=r[14];
goto P_0c077c16;
P_0c077c16: /* original b2d0, guest PC 0x0c077c16 */
if(!s->budget--) { s->failed_pc=0x0c077c16u; return 0; }
target=0x0c0781bau; r[16]=0x8c077c1au;
r[4]=r[12];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c077c1au) { target=s->pc; goto dispatch; }
goto P_0c077c1a;
P_0c077c18: /* original 64c3, guest PC 0x0c077c18 */
if(!s->budget--) { s->failed_pc=0x0c077c18u; return 0; }
r[4]=r[12];
goto P_0c077c1a;
P_0c077c1a: /* original 2008, guest PC 0x0c077c1a */
if(!s->budget--) { s->failed_pc=0x0c077c1au; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c077c1c;
P_0c077c1c: /* original 8d02, guest PC 0x0c077c1c */
if(!s->budget--) { s->failed_pc=0x0c077c1cu; return 0; }
cond=r[17]&1u;
r[15]+=0x00000028u;
if(cond) { goto P_0c077c24; }
goto P_0c077c20;
P_0c077c1e: /* original 7f28, guest PC 0x0c077c1e */
if(!s->budget--) { s->failed_pc=0x0c077c1eu; return 0; }
r[15]+=0x00000028u;
goto P_0c077c20;
P_0c077c20: /* original a10e, guest PC 0x0c077c20 */
if(!s->budget--) { s->failed_pc=0x0c077c20u; return 0; }
goto P_0c077e40;
P_0c077c22: /* original 0009, guest PC 0x0c077c22 */
if(!s->budget--) { s->failed_pc=0x0c077c22u; return 0; }
goto P_0c077c24;
P_0c077c24: /* original e074, guest PC 0x0c077c24 */
if(!s->budget--) { s->failed_pc=0x0c077c24u; return 0; }
r[0]=0x00000074u;
goto P_0c077c26;
P_0c077c26: /* original d33a, guest PC 0x0c077c26 */
if(!s->budget--) { s->failed_pc=0x0c077c26u; return 0; }
r[3]=read(ram,0x0c077d10u,4);
goto P_0c077c28;
P_0c077c28: /* original 02fe, guest PC 0x0c077c28 */
if(!s->budget--) { s->failed_pc=0x0c077c28u; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c077c2a;
P_0c077c2a: /* original 2238, guest PC 0x0c077c2a */
if(!s->budget--) { s->failed_pc=0x0c077c2au; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c077c2c;
P_0c077c2c: /* original 8901, guest PC 0x0c077c2c */
if(!s->budget--) { s->failed_pc=0x0c077c2cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c077c32; }
goto P_0c077c2e;
P_0c077c2e: /* original a103, guest PC 0x0c077c2e */
if(!s->budget--) { s->failed_pc=0x0c077c2eu; return 0; }
goto P_0c077e38;
P_0c077c30: /* original 0009, guest PC 0x0c077c30 */
if(!s->budget--) { s->failed_pc=0x0c077c30u; return 0; }
goto P_0c077c32;
P_0c077c32: /* original 9065, guest PC 0x0c077c32 */
if(!s->budget--) { s->failed_pc=0x0c077c32u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077d00u,2);
goto P_0c077c34;
P_0c077c34: /* original d337, guest PC 0x0c077c34 */
if(!s->budget--) { s->failed_pc=0x0c077c34u; return 0; }
r[3]=read(ram,0x0c077d14u,4);
goto P_0c077c36;
P_0c077c36: /* original 01fe, guest PC 0x0c077c36 */
if(!s->budget--) { s->failed_pc=0x0c077c36u; return 0; }
r[1]=read(ram,r[15]+r[0],4);
goto P_0c077c38;
P_0c077c38: /* original 2138, guest PC 0x0c077c38 */
if(!s->budget--) { s->failed_pc=0x0c077c38u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[3])==0)!=0);
goto P_0c077c3a;
P_0c077c3a: /* original 8b35, guest PC 0x0c077c3a */
if(!s->budget--) { s->failed_pc=0x0c077c3au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c077ca8; }
goto P_0c077c3c;
P_0c077c3c: /* original 9060, guest PC 0x0c077c3c */
if(!s->budget--) { s->failed_pc=0x0c077c3cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077d00u,2);
goto P_0c077c3e;
P_0c077c3e: /* original d233, guest PC 0x0c077c3e */
if(!s->budget--) { s->failed_pc=0x0c077c3eu; return 0; }
r[2]=read(ram,0x0c077d0cu,4);
goto P_0c077c40;
P_0c077c40: /* original 01fe, guest PC 0x0c077c40 */
if(!s->budget--) { s->failed_pc=0x0c077c40u; return 0; }
r[1]=read(ram,r[15]+r[0],4);
goto P_0c077c42;
P_0c077c42: /* original 2128, guest PC 0x0c077c42 */
if(!s->budget--) { s->failed_pc=0x0c077c42u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[2])==0)!=0);
goto P_0c077c44;
P_0c077c44: /* original 8b30, guest PC 0x0c077c44 */
if(!s->budget--) { s->failed_pc=0x0c077c44u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c077ca8; }
goto P_0c077c46;
P_0c077c46: /* original e050, guest PC 0x0c077c46 */
if(!s->budget--) { s->failed_pc=0x0c077c46u; return 0; }
r[0]=0x00000050u;
goto P_0c077c48;
P_0c077c48: /* original 51ff, guest PC 0x0c077c48 */
if(!s->budget--) { s->failed_pc=0x0c077c48u; return 0; }
r[1]=read(ram,r[15]+60,4);
goto P_0c077c4a;
P_0c077c4a: /* original 00fe, guest PC 0x0c077c4a */
if(!s->budget--) { s->failed_pc=0x0c077c4au; return 0; }
r[0]=read(ram,r[15]+r[0],4);
goto P_0c077c4c;
P_0c077c4c: /* original 201b, guest PC 0x0c077c4c */
if(!s->budget--) { s->failed_pc=0x0c077c4cu; return 0; }
r[0]|=r[1];
goto P_0c077c4e;
P_0c077c4e: /* original c8f0, guest PC 0x0c077c4e */
if(!s->budget--) { s->failed_pc=0x0c077c4eu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&240u)==0)!=0);
goto P_0c077c50;
P_0c077c50: /* original 892a, guest PC 0x0c077c50 */
if(!s->budget--) { s->failed_pc=0x0c077c50u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c077ca8; }
goto P_0c077c52;
P_0c077c52: /* original e078, guest PC 0x0c077c52 */
if(!s->budget--) { s->failed_pc=0x0c077c52u; return 0; }
r[0]=0x00000078u;
goto P_0c077c54;
P_0c077c54: /* original e200, guest PC 0x0c077c54 */
if(!s->budget--) { s->failed_pc=0x0c077c54u; return 0; }
r[2]=0x00000000u;
goto P_0c077c56;
P_0c077c56: /* original 0f26, guest PC 0x0c077c56 */
if(!s->budget--) { s->failed_pc=0x0c077c56u; return 0; }
write(ram,r[15]+r[0],r[2],4);
goto P_0c077c58;
P_0c077c58: /* original e050, guest PC 0x0c077c58 */
if(!s->budget--) { s->failed_pc=0x0c077c58u; return 0; }
r[0]=0x00000050u;
goto P_0c077c5a;
P_0c077c5a: /* original 03fe, guest PC 0x0c077c5a */
if(!s->budget--) { s->failed_pc=0x0c077c5au; return 0; }
r[3]=read(ram,r[15]+r[0],4);
goto P_0c077c5c;
P_0c077c5c: /* original e04c, guest PC 0x0c077c5c */
if(!s->budget--) { s->failed_pc=0x0c077c5cu; return 0; }
r[0]=0x0000004cu;
goto P_0c077c5e;
P_0c077c5e: /* original 2f36, guest PC 0x0c077c5e */
if(!s->budget--) { s->failed_pc=0x0c077c5eu; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c077c60;
P_0c077c60: /* original 52f2, guest PC 0x0c077c60 */
if(!s->budget--) { s->failed_pc=0x0c077c60u; return 0; }
r[2]=read(ram,r[15]+8,4);
goto P_0c077c62;
P_0c077c62: /* original 2f26, guest PC 0x0c077c62 */
if(!s->budget--) { s->failed_pc=0x0c077c62u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c077c64;
P_0c077c64: /* original 03fe, guest PC 0x0c077c64 */
if(!s->budget--) { s->failed_pc=0x0c077c64u; return 0; }
r[3]=read(ram,r[15]+r[0],4);
goto P_0c077c66;
P_0c077c66: /* original e04c, guest PC 0x0c077c66 */
if(!s->budget--) { s->failed_pc=0x0c077c66u; return 0; }
r[0]=0x0000004cu;
goto P_0c077c68;
P_0c077c68: /* original 2f36, guest PC 0x0c077c68 */
if(!s->budget--) { s->failed_pc=0x0c077c68u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c077c6a;
P_0c077c6a: /* original 02fe, guest PC 0x0c077c6a */
if(!s->budget--) { s->failed_pc=0x0c077c6au; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c077c6c;
P_0c077c6c: /* original 2f26, guest PC 0x0c077c6c */
if(!s->budget--) { s->failed_pc=0x0c077c6cu; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c077c6e;
P_0c077c6e: /* original 9044, guest PC 0x0c077c6e */
if(!s->budget--) { s->failed_pc=0x0c077c6eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077cfau,2);
goto P_0c077c70;
P_0c077c70: /* original 03fe, guest PC 0x0c077c70 */
if(!s->budget--) { s->failed_pc=0x0c077c70u; return 0; }
r[3]=read(ram,r[15]+r[0],4);
goto P_0c077c72;
P_0c077c72: /* original e05c, guest PC 0x0c077c72 */
if(!s->budget--) { s->failed_pc=0x0c077c72u; return 0; }
r[0]=0x0000005cu;
goto P_0c077c74;
P_0c077c74: /* original 2f36, guest PC 0x0c077c74 */
if(!s->budget--) { s->failed_pc=0x0c077c74u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c077c76;
P_0c077c76: /* original 02fe, guest PC 0x0c077c76 */
if(!s->budget--) { s->failed_pc=0x0c077c76u; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c077c78;
P_0c077c78: /* original 2f26, guest PC 0x0c077c78 */
if(!s->budget--) { s->failed_pc=0x0c077c78u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c077c7a;
P_0c077c7a: /* original 933f, guest PC 0x0c077c7a */
if(!s->budget--) { s->failed_pc=0x0c077c7au; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077cfcu,2);
goto P_0c077c7c;
P_0c077c7c: /* original 33fc, guest PC 0x0c077c7c */
if(!s->budget--) { s->failed_pc=0x0c077c7cu; return 0; }
r[3]+=r[15];
goto P_0c077c7e;
P_0c077c7e: /* original 2f36, guest PC 0x0c077c7e */
if(!s->budget--) { s->failed_pc=0x0c077c7eu; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c077c80;
P_0c077c80: /* original 903c, guest PC 0x0c077c80 */
if(!s->budget--) { s->failed_pc=0x0c077c80u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077cfcu,2);
goto P_0c077c82;
P_0c077c82: /* original 02fe, guest PC 0x0c077c82 */
if(!s->budget--) { s->failed_pc=0x0c077c82u; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c077c84;
P_0c077c84: /* original 2f26, guest PC 0x0c077c84 */
if(!s->budget--) { s->failed_pc=0x0c077c84u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c077c86;
P_0c077c86: /* original 9038, guest PC 0x0c077c86 */
if(!s->budget--) { s->failed_pc=0x0c077c86u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077cfau,2);
goto P_0c077c88;
P_0c077c88: /* original 03fe, guest PC 0x0c077c88 */
if(!s->budget--) { s->failed_pc=0x0c077c88u; return 0; }
r[3]=read(ram,r[15]+r[0],4);
goto P_0c077c8a;
P_0c077c8a: /* original 2f36, guest PC 0x0c077c8a */
if(!s->budget--) { s->failed_pc=0x0c077c8au; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c077c8c;
P_0c077c8c: /* original 9037, guest PC 0x0c077c8c */
if(!s->budget--) { s->failed_pc=0x0c077c8cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077cfeu,2);
goto P_0c077c8e;
P_0c077c8e: /* original 02fe, guest PC 0x0c077c8e */
if(!s->budget--) { s->failed_pc=0x0c077c8eu; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c077c90;
P_0c077c90: /* original 2f26, guest PC 0x0c077c90 */
if(!s->budget--) { s->failed_pc=0x0c077c90u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c077c92;
P_0c077c92: /* original 9734, guest PC 0x0c077c92 */
if(!s->budget--) { s->failed_pc=0x0c077c92u; return 0; }
r[7]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077cfeu,2);
goto P_0c077c94;
P_0c077c94: /* original 65e3, guest PC 0x0c077c94 */
if(!s->budget--) { s->failed_pc=0x0c077c94u; return 0; }
r[5]=r[14];
goto P_0c077c96;
P_0c077c96: /* original 66d3, guest PC 0x0c077c96 */
if(!s->budget--) { s->failed_pc=0x0c077c96u; return 0; }
r[6]=r[13];
goto P_0c077c98;
P_0c077c98: /* original 37fc, guest PC 0x0c077c98 */
if(!s->budget--) { s->failed_pc=0x0c077c98u; return 0; }
r[7]+=r[15];
goto P_0c077c9a;
P_0c077c9a: /* original b269, guest PC 0x0c077c9a */
if(!s->budget--) { s->failed_pc=0x0c077c9au; return 0; }
target=0x0c078170u; r[16]=0x8c077c9eu;
r[4]=r[12];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c077c9eu) { target=s->pc; goto dispatch; }
goto P_0c077c9e;
P_0c077c9c: /* original 64c3, guest PC 0x0c077c9c */
if(!s->budget--) { s->failed_pc=0x0c077c9cu; return 0; }
r[4]=r[12];
goto P_0c077c9e;
P_0c077c9e: /* original 2008, guest PC 0x0c077c9e */
if(!s->budget--) { s->failed_pc=0x0c077c9eu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c077ca0;
P_0c077ca0: /* original 8d02, guest PC 0x0c077ca0 */
if(!s->budget--) { s->failed_pc=0x0c077ca0u; return 0; }
cond=r[17]&1u;
r[15]+=0x00000028u;
if(cond) { goto P_0c077ca8; }
goto P_0c077ca4;
P_0c077ca2: /* original 7f28, guest PC 0x0c077ca2 */
if(!s->budget--) { s->failed_pc=0x0c077ca2u; return 0; }
r[15]+=0x00000028u;
goto P_0c077ca4;
P_0c077ca4: /* original a0cc, guest PC 0x0c077ca4 */
if(!s->budget--) { s->failed_pc=0x0c077ca4u; return 0; }
goto P_0c077e40;
P_0c077ca6: /* original 0009, guest PC 0x0c077ca6 */
if(!s->budget--) { s->failed_pc=0x0c077ca6u; return 0; }
goto P_0c077ca8;
P_0c077ca8: /* original 902b, guest PC 0x0c077ca8 */
if(!s->budget--) { s->failed_pc=0x0c077ca8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077d02u,2);
goto P_0c077caa;
P_0c077caa: /* original 02ec, guest PC 0x0c077caa */
if(!s->budget--) { s->failed_pc=0x0c077caau; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c077cac;
P_0c077cac: /* original 70ff, guest PC 0x0c077cac */
if(!s->budget--) { s->failed_pc=0x0c077cacu; return 0; }
r[0]+=0xffffffffu;
goto P_0c077cae;
P_0c077cae: /* original 03ec, guest PC 0x0c077cae */
if(!s->budget--) { s->failed_pc=0x0c077caeu; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c077cb0;
P_0c077cb0: /* original 3230, guest PC 0x0c077cb0 */
if(!s->budget--) { s->failed_pc=0x0c077cb0u; return 0; }
r[17]=(r[17]&~1u)|((r[2]==r[3])!=0);
goto P_0c077cb2;
P_0c077cb2: /* original 8901, guest PC 0x0c077cb2 */
if(!s->budget--) { s->failed_pc=0x0c077cb2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c077cb8; }
goto P_0c077cb4;
P_0c077cb4: /* original acee, guest PC 0x0c077cb4 */
if(!s->budget--) { s->failed_pc=0x0c077cb4u; return 0; }
goto P_0c077694;
P_0c077cb6: /* original 0009, guest PC 0x0c077cb6 */
if(!s->budget--) { s->failed_pc=0x0c077cb6u; return 0; }
goto P_0c077cb8;
P_0c077cb8: /* original 9024, guest PC 0x0c077cb8 */
if(!s->budget--) { s->failed_pc=0x0c077cb8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077d04u,2);
goto P_0c077cba;
P_0c077cba: /* original 03ec, guest PC 0x0c077cba */
if(!s->budget--) { s->failed_pc=0x0c077cbau; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c077cbc;
P_0c077cbc: /* original 2338, guest PC 0x0c077cbc */
if(!s->budget--) { s->failed_pc=0x0c077cbcu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c077cbe;
P_0c077cbe: /* original 8903, guest PC 0x0c077cbe */
if(!s->budget--) { s->failed_pc=0x0c077cbeu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c077cc8; }
goto P_0c077cc0;
P_0c077cc0: /* original 9021, guest PC 0x0c077cc0 */
if(!s->budget--) { s->failed_pc=0x0c077cc0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077d06u,2);
goto P_0c077cc2;
P_0c077cc2: /* original 03ec, guest PC 0x0c077cc2 */
if(!s->budget--) { s->failed_pc=0x0c077cc2u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c077cc4;
P_0c077cc4: /* original 70ce, guest PC 0x0c077cc4 */
if(!s->budget--) { s->failed_pc=0x0c077cc4u; return 0; }
r[0]+=0xffffffceu;
goto P_0c077cc6;
P_0c077cc6: /* original 0e34, guest PC 0x0c077cc6 */
if(!s->budget--) { s->failed_pc=0x0c077cc6u; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c077cc8;
P_0c077cc8: /* original 901a, guest PC 0x0c077cc8 */
if(!s->budget--) { s->failed_pc=0x0c077cc8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077d00u,2);
goto P_0c077cca;
P_0c077cca: /* original d312, guest PC 0x0c077cca */
if(!s->budget--) { s->failed_pc=0x0c077ccau; return 0; }
r[3]=read(ram,0x0c077d14u,4);
goto P_0c077ccc;
P_0c077ccc: /* original 02fe, guest PC 0x0c077ccc */
if(!s->budget--) { s->failed_pc=0x0c077cccu; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c077cce;
P_0c077cce: /* original 2238, guest PC 0x0c077cce */
if(!s->budget--) { s->failed_pc=0x0c077cceu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c077cd0;
P_0c077cd0: /* original 8901, guest PC 0x0c077cd0 */
if(!s->budget--) { s->failed_pc=0x0c077cd0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c077cd6; }
goto P_0c077cd2;
P_0c077cd2: /* original a0b1, guest PC 0x0c077cd2 */
if(!s->budget--) { s->failed_pc=0x0c077cd2u; return 0; }
goto P_0c077e38;
P_0c077cd4: /* original 0009, guest PC 0x0c077cd4 */
if(!s->budget--) { s->failed_pc=0x0c077cd4u; return 0; }
goto P_0c077cd6;
P_0c077cd6: /* original 9017, guest PC 0x0c077cd6 */
if(!s->budget--) { s->failed_pc=0x0c077cd6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077d08u,2);
goto P_0c077cd8;
P_0c077cd8: /* original d30f, guest PC 0x0c077cd8 */
if(!s->budget--) { s->failed_pc=0x0c077cd8u; return 0; }
r[3]=read(ram,0x0c077d18u,4);
goto P_0c077cda;
P_0c077cda: /* original 01fe, guest PC 0x0c077cda */
if(!s->budget--) { s->failed_pc=0x0c077cdau; return 0; }
r[1]=read(ram,r[15]+r[0],4);
goto P_0c077cdc;
P_0c077cdc: /* original 2138, guest PC 0x0c077cdc */
if(!s->budget--) { s->failed_pc=0x0c077cdcu; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[3])==0)!=0);
goto P_0c077cde;
P_0c077cde: /* original 8901, guest PC 0x0c077cde */
if(!s->budget--) { s->failed_pc=0x0c077cdeu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c077ce4; }
goto P_0c077ce0;
P_0c077ce0: /* original a0aa, guest PC 0x0c077ce0 */
if(!s->budget--) { s->failed_pc=0x0c077ce0u; return 0; }
goto P_0c077e38;
P_0c077ce2: /* original 0009, guest PC 0x0c077ce2 */
if(!s->budget--) { s->failed_pc=0x0c077ce2u; return 0; }
goto P_0c077ce4;
P_0c077ce4: /* original 50f1, guest PC 0x0c077ce4 */
if(!s->budget--) { s->failed_pc=0x0c077ce4u; return 0; }
r[0]=read(ram,r[15]+4,4);
goto P_0c077ce6;
P_0c077ce6: /* original c8f0, guest PC 0x0c077ce6 */
if(!s->budget--) { s->failed_pc=0x0c077ce6u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&240u)==0)!=0);
goto P_0c077ce8;
P_0c077ce8: /* original 8924, guest PC 0x0c077ce8 */
if(!s->budget--) { s->failed_pc=0x0c077ce8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c077d34; }
goto P_0c077cea;
P_0c077cea: /* original 910d, guest PC 0x0c077cea */
if(!s->budget--) { s->failed_pc=0x0c077ceau; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077d08u,2);
goto P_0c077cec;
P_0c077cec: /* original 31fc, guest PC 0x0c077cec */
if(!s->budget--) { s->failed_pc=0x0c077cecu; return 0; }
r[1]+=r[15];
goto P_0c077cee;
P_0c077cee: /* original 6012, guest PC 0x0c077cee */
if(!s->budget--) { s->failed_pc=0x0c077ceeu; return 0; }
tmp=read(ram,r[1],4);
r[0]=tmp;
goto P_0c077cf0;
P_0c077cf0: /* original c820, guest PC 0x0c077cf0 */
if(!s->budget--) { s->failed_pc=0x0c077cf0u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&32u)==0)!=0);
goto P_0c077cf2;
P_0c077cf2: /* original a013, guest PC 0x0c077cf2 */
if(!s->budget--) { s->failed_pc=0x0c077cf2u; return 0; }
goto P_0c077d1c;
P_0c077cf4: /* original 0009, guest PC 0x0c077cf4 */
if(!s->budget--) { s->failed_pc=0x0c077cf4u; return 0; }
return vf3_matrix_family(0x0c077cf6u,s,ram);
P_0c077d1c: /* original 8903, guest PC 0x0c077d1c */
if(!s->budget--) { s->failed_pc=0x0c077d1cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c077d26; }
goto P_0c077d1e;
P_0c077d1e: /* original d331, guest PC 0x0c077d1e */
if(!s->budget--) { s->failed_pc=0x0c077d1eu; return 0; }
r[3]=read(ram,0x0c077de4u,4);
goto P_0c077d20;
P_0c077d20: /* original 6232, guest PC 0x0c077d20 */
if(!s->budget--) { s->failed_pc=0x0c077d20u; return 0; }
tmp=read(ram,r[3],4);
r[2]=tmp;
goto P_0c077d22;
P_0c077d22: /* original a078, guest PC 0x0c077d22 */
if(!s->budget--) { s->failed_pc=0x0c077d22u; return 0; }
write(ram,r[14]+48,r[2],4);
goto P_0c077e16;
P_0c077d24: /* original 1e2c, guest PC 0x0c077d24 */
if(!s->budget--) { s->failed_pc=0x0c077d24u; return 0; }
write(ram,r[14]+48,r[2],4);
goto P_0c077d26;
P_0c077d26: /* original 9159, guest PC 0x0c077d26 */
if(!s->budget--) { s->failed_pc=0x0c077d26u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077ddcu,2);
goto P_0c077d28;
P_0c077d28: /* original 31fc, guest PC 0x0c077d28 */
if(!s->budget--) { s->failed_pc=0x0c077d28u; return 0; }
r[1]+=r[15];
goto P_0c077d2a;
P_0c077d2a: /* original 6012, guest PC 0x0c077d2a */
if(!s->budget--) { s->failed_pc=0x0c077d2au; return 0; }
tmp=read(ram,r[1],4);
r[0]=tmp;
goto P_0c077d2c;
P_0c077d2c: /* original c840, guest PC 0x0c077d2c */
if(!s->budget--) { s->failed_pc=0x0c077d2cu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&64u)==0)!=0);
goto P_0c077d2e;
P_0c077d2e: /* original 8901, guest PC 0x0c077d2e */
if(!s->budget--) { s->failed_pc=0x0c077d2eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c077d34; }
goto P_0c077d30;
P_0c077d30: /* original a082, guest PC 0x0c077d30 */
if(!s->budget--) { s->failed_pc=0x0c077d30u; return 0; }
goto P_0c077e38;
P_0c077d32: /* original 0009, guest PC 0x0c077d32 */
if(!s->budget--) { s->failed_pc=0x0c077d32u; return 0; }
goto P_0c077d34;
P_0c077d34: /* original 63e3, guest PC 0x0c077d34 */
if(!s->budget--) { s->failed_pc=0x0c077d34u; return 0; }
r[3]=r[14];
goto P_0c077d36;
P_0c077d36: /* original 7338, guest PC 0x0c077d36 */
if(!s->budget--) { s->failed_pc=0x0c077d36u; return 0; }
r[3]+=0x00000038u;
goto P_0c077d38;
P_0c077d38: /* original 8433, guest PC 0x0c077d38 */
if(!s->budget--) { s->failed_pc=0x0c077d38u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[3]+3,1);
goto P_0c077d3a;
P_0c077d3a: /* original 600c, guest PC 0x0c077d3a */
if(!s->budget--) { s->failed_pc=0x0c077d3au; return 0; }
r[0]=r[0]&255u;
goto P_0c077d3c;
P_0c077d3c: /* original 1f04, guest PC 0x0c077d3c */
if(!s->budget--) { s->failed_pc=0x0c077d3cu; return 0; }
write(ram,r[15]+16,r[0],4);
goto P_0c077d3e;
P_0c077d3e: /* original 50f1, guest PC 0x0c077d3e */
if(!s->budget--) { s->failed_pc=0x0c077d3eu; return 0; }
r[0]=read(ram,r[15]+4,4);
goto P_0c077d40;
P_0c077d40: /* original c810, guest PC 0x0c077d40 */
if(!s->budget--) { s->failed_pc=0x0c077d40u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&16u)==0)!=0);
goto P_0c077d42;
P_0c077d42: /* original 8b30, guest PC 0x0c077d42 */
if(!s->budget--) { s->failed_pc=0x0c077d42u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c077da6; }
goto P_0c077d44;
P_0c077d44: /* original e044, guest PC 0x0c077d44 */
if(!s->budget--) { s->failed_pc=0x0c077d44u; return 0; }
r[0]=0x00000044u;
goto P_0c077d46;
P_0c077d46: /* original 53f1, guest PC 0x0c077d46 */
if(!s->budget--) { s->failed_pc=0x0c077d46u; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c077d48;
P_0c077d48: /* original 01fe, guest PC 0x0c077d48 */
if(!s->budget--) { s->failed_pc=0x0c077d48u; return 0; }
r[1]=read(ram,r[15]+r[0],4);
goto P_0c077d4a;
P_0c077d4a: /* original 2138, guest PC 0x0c077d4a */
if(!s->budget--) { s->failed_pc=0x0c077d4au; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[3])==0)!=0);
goto P_0c077d4c;
P_0c077d4c: /* original 890a, guest PC 0x0c077d4c */
if(!s->budget--) { s->failed_pc=0x0c077d4cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c077d64; }
goto P_0c077d4e;
P_0c077d4e: /* original 50f4, guest PC 0x0c077d4e */
if(!s->budget--) { s->failed_pc=0x0c077d4eu; return 0; }
r[0]=read(ram,r[15]+16,4);
goto P_0c077d50;
P_0c077d50: /* original 8810, guest PC 0x0c077d50 */
if(!s->budget--) { s->failed_pc=0x0c077d50u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000010u)!=0);
goto P_0c077d52;
P_0c077d52: /* original 8971, guest PC 0x0c077d52 */
if(!s->budget--) { s->failed_pc=0x0c077d52u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c077e38; }
goto P_0c077d54;
P_0c077d54: /* original e04c, guest PC 0x0c077d54 */
if(!s->budget--) { s->failed_pc=0x0c077d54u; return 0; }
r[0]=0x0000004cu;
goto P_0c077d56;
P_0c077d56: /* original d324, guest PC 0x0c077d56 */
if(!s->budget--) { s->failed_pc=0x0c077d56u; return 0; }
r[3]=read(ram,0x0c077de8u,4);
goto P_0c077d58;
P_0c077d58: /* original 02ee, guest PC 0x0c077d58 */
if(!s->budget--) { s->failed_pc=0x0c077d58u; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c077d5a;
P_0c077d5a: /* original 2238, guest PC 0x0c077d5a */
if(!s->budget--) { s->failed_pc=0x0c077d5au; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c077d5c;
P_0c077d5c: /* original 8b6c, guest PC 0x0c077d5c */
if(!s->budget--) { s->failed_pc=0x0c077d5cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c077e38; }
goto P_0c077d5e;
P_0c077d5e: /* original d123, guest PC 0x0c077d5e */
if(!s->budget--) { s->failed_pc=0x0c077d5eu; return 0; }
r[1]=read(ram,0x0c077decu,4);
goto P_0c077d60;
P_0c077d60: /* original a051, guest PC 0x0c077d60 */
if(!s->budget--) { s->failed_pc=0x0c077d60u; return 0; }
goto P_0c077e06;
P_0c077d62: /* original 0009, guest PC 0x0c077d62 */
if(!s->budget--) { s->failed_pc=0x0c077d62u; return 0; }
goto P_0c077d64;
P_0c077d64: /* original e040, guest PC 0x0c077d64 */
if(!s->budget--) { s->failed_pc=0x0c077d64u; return 0; }
r[0]=0x00000040u;
goto P_0c077d66;
P_0c077d66: /* original 53f1, guest PC 0x0c077d66 */
if(!s->budget--) { s->failed_pc=0x0c077d66u; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c077d68;
P_0c077d68: /* original 02fe, guest PC 0x0c077d68 */
if(!s->budget--) { s->failed_pc=0x0c077d68u; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c077d6a;
P_0c077d6a: /* original 2238, guest PC 0x0c077d6a */
if(!s->budget--) { s->failed_pc=0x0c077d6au; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c077d6c;
P_0c077d6c: /* original 8915, guest PC 0x0c077d6c */
if(!s->budget--) { s->failed_pc=0x0c077d6cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c077d9a; }
goto P_0c077d6e;
P_0c077d6e: /* original 50f4, guest PC 0x0c077d6e */
if(!s->budget--) { s->failed_pc=0x0c077d6eu; return 0; }
r[0]=read(ram,r[15]+16,4);
goto P_0c077d70;
P_0c077d70: /* original 8811, guest PC 0x0c077d70 */
if(!s->budget--) { s->failed_pc=0x0c077d70u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000011u)!=0);
goto P_0c077d72;
P_0c077d72: /* original 8961, guest PC 0x0c077d72 */
if(!s->budget--) { s->failed_pc=0x0c077d72u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c077e38; }
goto P_0c077d74;
P_0c077d74: /* original e048, guest PC 0x0c077d74 */
if(!s->budget--) { s->failed_pc=0x0c077d74u; return 0; }
r[0]=0x00000048u;
goto P_0c077d76;
P_0c077d76: /* original d31e, guest PC 0x0c077d76 */
if(!s->budget--) { s->failed_pc=0x0c077d76u; return 0; }
r[3]=read(ram,0x0c077df0u,4);
goto P_0c077d78;
P_0c077d78: /* original 02fe, guest PC 0x0c077d78 */
if(!s->budget--) { s->failed_pc=0x0c077d78u; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c077d7a;
P_0c077d7a: /* original 2238, guest PC 0x0c077d7a */
if(!s->budget--) { s->failed_pc=0x0c077d7au; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c077d7c;
P_0c077d7c: /* original 8b02, guest PC 0x0c077d7c */
if(!s->budget--) { s->failed_pc=0x0c077d7cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c077d84; }
goto P_0c077d7e;
P_0c077d7e: /* original d21d, guest PC 0x0c077d7e */
if(!s->budget--) { s->failed_pc=0x0c077d7eu; return 0; }
r[2]=read(ram,0x0c077df4u,4);
goto P_0c077d80;
P_0c077d80: /* original a02a, guest PC 0x0c077d80 */
if(!s->budget--) { s->failed_pc=0x0c077d80u; return 0; }
goto P_0c077dd8;
P_0c077d82: /* original 0009, guest PC 0x0c077d82 */
if(!s->budget--) { s->failed_pc=0x0c077d82u; return 0; }
goto P_0c077d84;
P_0c077d84: /* original e061, guest PC 0x0c077d84 */
if(!s->budget--) { s->failed_pc=0x0c077d84u; return 0; }
r[0]=0x00000061u;
goto P_0c077d86;
P_0c077d86: /* original 00ec, guest PC 0x0c077d86 */
if(!s->budget--) { s->failed_pc=0x0c077d86u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c077d88;
P_0c077d88: /* original 600c, guest PC 0x0c077d88 */
if(!s->budget--) { s->failed_pc=0x0c077d88u; return 0; }
r[0]=r[0]&255u;
goto P_0c077d8a;
P_0c077d8a: /* original 880c, guest PC 0x0c077d8a */
if(!s->budget--) { s->failed_pc=0x0c077d8au; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000cu)!=0);
goto P_0c077d8c;
P_0c077d8c: /* original 8b02, guest PC 0x0c077d8c */
if(!s->budget--) { s->failed_pc=0x0c077d8cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c077d94; }
goto P_0c077d8e;
P_0c077d8e: /* original 9226, guest PC 0x0c077d8e */
if(!s->budget--) { s->failed_pc=0x0c077d8eu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077ddeu,2);
goto P_0c077d90;
P_0c077d90: /* original a022, guest PC 0x0c077d90 */
if(!s->budget--) { s->failed_pc=0x0c077d90u; return 0; }
goto P_0c077dd8;
P_0c077d92: /* original 0009, guest PC 0x0c077d92 */
if(!s->budget--) { s->failed_pc=0x0c077d92u; return 0; }
goto P_0c077d94;
P_0c077d94: /* original 9124, guest PC 0x0c077d94 */
if(!s->budget--) { s->failed_pc=0x0c077d94u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077de0u,2);
goto P_0c077d96;
P_0c077d96: /* original a036, guest PC 0x0c077d96 */
if(!s->budget--) { s->failed_pc=0x0c077d96u; return 0; }
goto P_0c077e06;
P_0c077d98: /* original 0009, guest PC 0x0c077d98 */
if(!s->budget--) { s->failed_pc=0x0c077d98u; return 0; }
goto P_0c077d9a;
P_0c077d9a: /* original 50f4, guest PC 0x0c077d9a */
if(!s->budget--) { s->failed_pc=0x0c077d9au; return 0; }
r[0]=read(ram,r[15]+16,4);
goto P_0c077d9c;
P_0c077d9c: /* original 8811, guest PC 0x0c077d9c */
if(!s->budget--) { s->failed_pc=0x0c077d9cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000011u)!=0);
goto P_0c077d9e;
P_0c077d9e: /* original 894b, guest PC 0x0c077d9e */
if(!s->budget--) { s->failed_pc=0x0c077d9eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c077e38; }
goto P_0c077da0;
P_0c077da0: /* original d315, guest PC 0x0c077da0 */
if(!s->budget--) { s->failed_pc=0x0c077da0u; return 0; }
r[3]=read(ram,0x0c077df8u,4);
goto P_0c077da2;
P_0c077da2: /* original a009, guest PC 0x0c077da2 */
if(!s->budget--) { s->failed_pc=0x0c077da2u; return 0; }
goto P_0c077db8;
P_0c077da4: /* original 0009, guest PC 0x0c077da4 */
if(!s->budget--) { s->failed_pc=0x0c077da4u; return 0; }
goto P_0c077da6;
P_0c077da6: /* original e044, guest PC 0x0c077da6 */
if(!s->budget--) { s->failed_pc=0x0c077da6u; return 0; }
r[0]=0x00000044u;
goto P_0c077da8;
P_0c077da8: /* original 53f1, guest PC 0x0c077da8 */
if(!s->budget--) { s->failed_pc=0x0c077da8u; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c077daa;
P_0c077daa: /* original 02fe, guest PC 0x0c077daa */
if(!s->budget--) { s->failed_pc=0x0c077daau; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c077dac;
P_0c077dac: /* original 2238, guest PC 0x0c077dac */
if(!s->budget--) { s->failed_pc=0x0c077dacu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c077dae;
P_0c077dae: /* original 8905, guest PC 0x0c077dae */
if(!s->budget--) { s->failed_pc=0x0c077daeu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c077dbc; }
goto P_0c077db0;
P_0c077db0: /* original 50f4, guest PC 0x0c077db0 */
if(!s->budget--) { s->failed_pc=0x0c077db0u; return 0; }
r[0]=read(ram,r[15]+16,4);
goto P_0c077db2;
P_0c077db2: /* original 8812, guest PC 0x0c077db2 */
if(!s->budget--) { s->failed_pc=0x0c077db2u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000012u)!=0);
goto P_0c077db4;
P_0c077db4: /* original 8940, guest PC 0x0c077db4 */
if(!s->budget--) { s->failed_pc=0x0c077db4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c077e38; }
goto P_0c077db6;
P_0c077db6: /* original d311, guest PC 0x0c077db6 */
if(!s->budget--) { s->failed_pc=0x0c077db6u; return 0; }
r[3]=read(ram,0x0c077dfcu,4);
goto P_0c077db8;
P_0c077db8: /* original a026, guest PC 0x0c077db8 */
if(!s->budget--) { s->failed_pc=0x0c077db8u; return 0; }
write(ram,r[15]+56,r[3],4);
goto P_0c077e08;
P_0c077dba: /* original 1f3e, guest PC 0x0c077dba */
if(!s->budget--) { s->failed_pc=0x0c077dbau; return 0; }
write(ram,r[15]+56,r[3],4);
goto P_0c077dbc;
P_0c077dbc: /* original e040, guest PC 0x0c077dbc */
if(!s->budget--) { s->failed_pc=0x0c077dbcu; return 0; }
r[0]=0x00000040u;
goto P_0c077dbe;
P_0c077dbe: /* original 53f1, guest PC 0x0c077dbe */
if(!s->budget--) { s->failed_pc=0x0c077dbeu; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c077dc0;
P_0c077dc0: /* original 02fe, guest PC 0x0c077dc0 */
if(!s->budget--) { s->failed_pc=0x0c077dc0u; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c077dc2;
P_0c077dc2: /* original 2238, guest PC 0x0c077dc2 */
if(!s->budget--) { s->failed_pc=0x0c077dc2u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c077dc4;
P_0c077dc4: /* original 891e, guest PC 0x0c077dc4 */
if(!s->budget--) { s->failed_pc=0x0c077dc4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c077e04; }
goto P_0c077dc6;
P_0c077dc6: /* original 50f4, guest PC 0x0c077dc6 */
if(!s->budget--) { s->failed_pc=0x0c077dc6u; return 0; }
r[0]=read(ram,r[15]+16,4);
goto P_0c077dc8;
P_0c077dc8: /* original 8813, guest PC 0x0c077dc8 */
if(!s->budget--) { s->failed_pc=0x0c077dc8u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000013u)!=0);
goto P_0c077dca;
P_0c077dca: /* original 8935, guest PC 0x0c077dca */
if(!s->budget--) { s->failed_pc=0x0c077dcau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c077e38; }
goto P_0c077dcc;
P_0c077dcc: /* original e048, guest PC 0x0c077dcc */
if(!s->budget--) { s->failed_pc=0x0c077dccu; return 0; }
r[0]=0x00000048u;
goto P_0c077dce;
P_0c077dce: /* original d308, guest PC 0x0c077dce */
if(!s->budget--) { s->failed_pc=0x0c077dceu; return 0; }
r[3]=read(ram,0x0c077df0u,4);
goto P_0c077dd0;
P_0c077dd0: /* original 02fe, guest PC 0x0c077dd0 */
if(!s->budget--) { s->failed_pc=0x0c077dd0u; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c077dd2;
P_0c077dd2: /* original 2238, guest PC 0x0c077dd2 */
if(!s->budget--) { s->failed_pc=0x0c077dd2u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c077dd4;
P_0c077dd4: /* original 8bd6, guest PC 0x0c077dd4 */
if(!s->budget--) { s->failed_pc=0x0c077dd4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c077d84; }
goto P_0c077dd6;
P_0c077dd6: /* original d20a, guest PC 0x0c077dd6 */
if(!s->budget--) { s->failed_pc=0x0c077dd6u; return 0; }
r[2]=read(ram,0x0c077e00u,4);
goto P_0c077dd8;
P_0c077dd8: /* original a016, guest PC 0x0c077dd8 */
if(!s->budget--) { s->failed_pc=0x0c077dd8u; return 0; }
write(ram,r[15]+56,r[2],4);
goto P_0c077e08;
P_0c077dda: /* original 1f2e, guest PC 0x0c077dda */
if(!s->budget--) { s->failed_pc=0x0c077ddau; return 0; }
write(ram,r[15]+56,r[2],4);
return vf3_matrix_family(0x0c077ddcu,s,ram);
P_0c077e04: /* original d13d, guest PC 0x0c077e04 */
if(!s->budget--) { s->failed_pc=0x0c077e04u; return 0; }
r[1]=read(ram,0x0c077efcu,4);
goto P_0c077e06;
P_0c077e06: /* original 1f1e, guest PC 0x0c077e06 */
if(!s->budget--) { s->failed_pc=0x0c077e06u; return 0; }
write(ram,r[15]+56,r[1],4);
goto P_0c077e08;
P_0c077e08: /* original 53fe, guest PC 0x0c077e08 */
if(!s->budget--) { s->failed_pc=0x0c077e08u; return 0; }
r[3]=read(ram,r[15]+56,4);
goto P_0c077e0a;
P_0c077e0a: /* original a015, guest PC 0x0c077e0a */
if(!s->budget--) { s->failed_pc=0x0c077e0au; return 0; }
write(ram,r[14]+48,r[3],4);
goto P_0c077e38;
P_0c077e0c: /* original 1e3c, guest PC 0x0c077e0c */
if(!s->budget--) { s->failed_pc=0x0c077e0cu; return 0; }
write(ram,r[14]+48,r[3],4);
goto P_0c077e0e;
P_0c077e0e: /* original 906c, guest PC 0x0c077e0e */
if(!s->budget--) { s->failed_pc=0x0c077e0eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077eeau,2);
goto P_0c077e10;
P_0c077e10: /* original 01ec, guest PC 0x0c077e10 */
if(!s->budget--) { s->failed_pc=0x0c077e10u; return 0; }
r[1]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c077e12;
P_0c077e12: /* original 7001, guest PC 0x0c077e12 */
if(!s->budget--) { s->failed_pc=0x0c077e12u; return 0; }
r[0]+=0x00000001u;
goto P_0c077e14;
P_0c077e14: /* original 0e14, guest PC 0x0c077e14 */
if(!s->budget--) { s->failed_pc=0x0c077e14u; return 0; }
write(ram,r[14]+r[0],r[1],1);
goto P_0c077e16;
P_0c077e16: /* original 9069, guest PC 0x0c077e16 */
if(!s->budget--) { s->failed_pc=0x0c077e16u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077eecu,2);
goto P_0c077e18;
P_0c077e18: /* original 03ec, guest PC 0x0c077e18 */
if(!s->budget--) { s->failed_pc=0x0c077e18u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c077e1a;
P_0c077e1a: /* original 7001, guest PC 0x0c077e1a */
if(!s->budget--) { s->failed_pc=0x0c077e1au; return 0; }
r[0]+=0x00000001u;
goto P_0c077e1c;
P_0c077e1c: /* original 0e34, guest PC 0x0c077e1c */
if(!s->budget--) { s->failed_pc=0x0c077e1cu; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c077e1e;
P_0c077e1e: /* original 70ff, guest PC 0x0c077e1e */
if(!s->budget--) { s->failed_pc=0x0c077e1eu; return 0; }
r[0]+=0xffffffffu;
goto P_0c077e20;
P_0c077e20: /* original 02ec, guest PC 0x0c077e20 */
if(!s->budget--) { s->failed_pc=0x0c077e20u; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c077e22;
P_0c077e22: /* original e06c, guest PC 0x0c077e22 */
if(!s->budget--) { s->failed_pc=0x0c077e22u; return 0; }
r[0]=0x0000006cu;
goto P_0c077e24;
P_0c077e24: /* original 622c, guest PC 0x0c077e24 */
if(!s->budget--) { s->failed_pc=0x0c077e24u; return 0; }
r[2]=r[2]&255u;
goto P_0c077e26;
P_0c077e26: /* original 0f26, guest PC 0x0c077e26 */
if(!s->budget--) { s->failed_pc=0x0c077e26u; return 0; }
write(ram,r[15]+r[0],r[2],4);
goto P_0c077e28;
P_0c077e28: /* original e06c, guest PC 0x0c077e28 */
if(!s->budget--) { s->failed_pc=0x0c077e28u; return 0; }
r[0]=0x0000006cu;
goto P_0c077e2a;
P_0c077e2a: /* original 03fc, guest PC 0x0c077e2a */
if(!s->budget--) { s->failed_pc=0x0c077e2au; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[15]+r[0],1);
goto P_0c077e2c;
P_0c077e2c: /* original 905f, guest PC 0x0c077e2c */
if(!s->budget--) { s->failed_pc=0x0c077e2cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077eeeu,2);
goto P_0c077e2e;
P_0c077e2e: /* original 0e34, guest PC 0x0c077e2e */
if(!s->budget--) { s->failed_pc=0x0c077e2eu; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c077e30;
P_0c077e30: /* original e06c, guest PC 0x0c077e30 */
if(!s->budget--) { s->failed_pc=0x0c077e30u; return 0; }
r[0]=0x0000006cu;
goto P_0c077e32;
P_0c077e32: /* original 02fc, guest PC 0x0c077e32 */
if(!s->budget--) { s->failed_pc=0x0c077e32u; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[15]+r[0],1);
goto P_0c077e34;
P_0c077e34: /* original 905c, guest PC 0x0c077e34 */
if(!s->budget--) { s->failed_pc=0x0c077e34u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077ef0u,2);
goto P_0c077e36;
P_0c077e36: /* original 0e24, guest PC 0x0c077e36 */
if(!s->budget--) { s->failed_pc=0x0c077e36u; return 0; }
write(ram,r[14]+r[0],r[2],1);
goto P_0c077e38;
P_0c077e38: /* original 905b, guest PC 0x0c077e38 */
if(!s->budget--) { s->failed_pc=0x0c077e38u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077ef2u,2);
goto P_0c077e3a;
P_0c077e3a: /* original 03fe, guest PC 0x0c077e3a */
if(!s->budget--) { s->failed_pc=0x0c077e3au; return 0; }
r[3]=read(ram,r[15]+r[0],4);
goto P_0c077e3c;
P_0c077e3c: /* original 905a, guest PC 0x0c077e3c */
if(!s->budget--) { s->failed_pc=0x0c077e3cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077ef4u,2);
goto P_0c077e3e;
P_0c077e3e: /* original 0e36, guest PC 0x0c077e3e */
if(!s->budget--) { s->failed_pc=0x0c077e3eu; return 0; }
write(ram,r[14]+r[0],r[3],4);
goto P_0c077e40;
P_0c077e40: /* original 9159, guest PC 0x0c077e40 */
if(!s->budget--) { s->failed_pc=0x0c077e40u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077ef6u,2);
goto P_0c077e42;
P_0c077e42: /* original 3f1c, guest PC 0x0c077e42 */
if(!s->budget--) { s->failed_pc=0x0c077e42u; return 0; }
r[15]+=r[1];
goto P_0c077e44;
P_0c077e44: /* original 4f26, guest PC 0x0c077e44 */
if(!s->budget--) { s->failed_pc=0x0c077e44u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c077e46;
P_0c077e46: /* original 6cf6, guest PC 0x0c077e46 */
if(!s->budget--) { s->failed_pc=0x0c077e46u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c077e48;
P_0c077e48: /* original 6df6, guest PC 0x0c077e48 */
if(!s->budget--) { s->failed_pc=0x0c077e48u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c077e4a;
P_0c077e4a: /* original 000b, guest PC 0x0c077e4a */
if(!s->budget--) { s->failed_pc=0x0c077e4au; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c077e4c: /* original 6ef6, guest PC 0x0c077e4c */
if(!s->budget--) { s->failed_pc=0x0c077e4cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c077e4eu,s,ram);
P_0c0786d4: /* original a37c, guest PC 0x0c0786d4 */
if(!s->budget--) { s->failed_pc=0x0c0786d4u; return 0; }
goto P_0c078dd0;
P_0c0786d6: /* original 0009, guest PC 0x0c0786d6 */
if(!s->budget--) { s->failed_pc=0x0c0786d6u; return 0; }
return vf3_matrix_family(0x0c0786d8u,s,ram);
P_0c07873c: /* original a691, guest PC 0x0c07873c */
if(!s->budget--) { s->failed_pc=0x0c07873cu; return 0; }
goto P_0c079462;
P_0c07873e: /* original 0009, guest PC 0x0c07873e */
if(!s->budget--) { s->failed_pc=0x0c07873eu; return 0; }
return vf3_matrix_family(0x0c078740u,s,ram);
P_0c078858: /* original d24c, guest PC 0x0c078858 */
if(!s->budget--) { s->failed_pc=0x0c078858u; return 0; }
r[2]=read(ram,0x0c07898cu,4);
goto P_0c07885a;
P_0c07885a: /* original 422b, guest PC 0x0c07885a */
if(!s->budget--) { s->failed_pc=0x0c07885au; return 0; }
target=r[2];
switch(target&0x1fffffffu) {
case 0x0c079f96u: goto P_0c079f96;
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
P_0c07885c: /* original 0009, guest PC 0x0c07885c */
if(!s->budget--) { s->failed_pc=0x0c07885cu; return 0; }
return vf3_matrix_family(0x0c07885eu,s,ram);
P_0c0788a6: /* original d246, guest PC 0x0c0788a6 */
if(!s->budget--) { s->failed_pc=0x0c0788a6u; return 0; }
r[2]=read(ram,0x0c0789c0u,4);
goto P_0c0788a8;
P_0c0788a8: /* original 422b, guest PC 0x0c0788a8 */
if(!s->budget--) { s->failed_pc=0x0c0788a8u; return 0; }
target=r[2];
switch(target&0x1fffffffu) {
case 0x0c07a4d8u: goto P_0c07a4d8;
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
P_0c0788aa: /* original 0009, guest PC 0x0c0788aa */
if(!s->budget--) { s->failed_pc=0x0c0788aau; return 0; }
return vf3_matrix_family(0x0c0788acu,s,ram);
P_0c078dd0: /* original 9022, guest PC 0x0c078dd0 */
if(!s->budget--) { s->failed_pc=0x0c078dd0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c078e18u,2);
goto P_0c078dd2;
P_0c078dd2: /* original d215, guest PC 0x0c078dd2 */
if(!s->budget--) { s->failed_pc=0x0c078dd2u; return 0; }
r[2]=read(ram,0x0c078e28u,4);
goto P_0c078dd4;
P_0c078dd4: /* original 01fe, guest PC 0x0c078dd4 */
if(!s->budget--) { s->failed_pc=0x0c078dd4u; return 0; }
r[1]=read(ram,r[15]+r[0],4);
goto P_0c078dd6;
P_0c078dd6: /* original 901f, guest PC 0x0c078dd6 */
if(!s->budget--) { s->failed_pc=0x0c078dd6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c078e18u,2);
goto P_0c078dd8;
P_0c078dd8: /* original 7104, guest PC 0x0c078dd8 */
if(!s->budget--) { s->failed_pc=0x0c078dd8u; return 0; }
r[1]+=0x00000004u;
goto P_0c078dda;
P_0c078dda: /* original 6310, guest PC 0x0c078dda */
if(!s->budget--) { s->failed_pc=0x0c078ddau; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[1],1);
r[3]=tmp;
goto P_0c078ddc;
P_0c078ddc: /* original 01fe, guest PC 0x0c078ddc */
if(!s->budget--) { s->failed_pc=0x0c078ddcu; return 0; }
r[1]=read(ram,r[15]+r[0],4);
goto P_0c078dde;
P_0c078dde: /* original d013, guest PC 0x0c078dde */
if(!s->budget--) { s->failed_pc=0x0c078ddeu; return 0; }
r[0]=read(ram,0x0c078e2cu,4);
goto P_0c078de0;
P_0c078de0: /* original 633c, guest PC 0x0c078de0 */
if(!s->budget--) { s->failed_pc=0x0c078de0u; return 0; }
r[3]=r[3]&255u;
goto P_0c078de2;
P_0c078de2: /* original 7103, guest PC 0x0c078de2 */
if(!s->budget--) { s->failed_pc=0x0c078de2u; return 0; }
r[1]+=0x00000003u;
goto P_0c078de4;
P_0c078de4: /* original 6110, guest PC 0x0c078de4 */
if(!s->budget--) { s->failed_pc=0x0c078de4u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[1],1);
r[1]=tmp;
goto P_0c078de6;
P_0c078de6: /* original 4328, guest PC 0x0c078de6 */
if(!s->budget--) { s->failed_pc=0x0c078de6u; return 0; }
r[3]<<=16;
goto P_0c078de8;
P_0c078de8: /* original 4318, guest PC 0x0c078de8 */
if(!s->budget--) { s->failed_pc=0x0c078de8u; return 0; }
r[3]<<=8;
goto P_0c078dea;
P_0c078dea: /* original 611c, guest PC 0x0c078dea */
if(!s->budget--) { s->failed_pc=0x0c078deau; return 0; }
r[1]=r[1]&255u;
goto P_0c078dec;
P_0c078dec: /* original 4128, guest PC 0x0c078dec */
if(!s->budget--) { s->failed_pc=0x0c078decu; return 0; }
r[1]<<=16;
goto P_0c078dee;
P_0c078dee: /* original 2109, guest PC 0x0c078dee */
if(!s->budget--) { s->failed_pc=0x0c078deeu; return 0; }
r[1]&=r[0];
goto P_0c078df0;
P_0c078df0: /* original 9012, guest PC 0x0c078df0 */
if(!s->budget--) { s->failed_pc=0x0c078df0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c078e18u,2);
goto P_0c078df2;
P_0c078df2: /* original 2329, guest PC 0x0c078df2 */
if(!s->budget--) { s->failed_pc=0x0c078df2u; return 0; }
r[3]&=r[2];
goto P_0c078df4;
P_0c078df4: /* original 231b, guest PC 0x0c078df4 */
if(!s->budget--) { s->failed_pc=0x0c078df4u; return 0; }
r[3]|=r[1];
goto P_0c078df6;
P_0c078df6: /* original 01fe, guest PC 0x0c078df6 */
if(!s->budget--) { s->failed_pc=0x0c078df6u; return 0; }
r[1]=read(ram,r[15]+r[0],4);
goto P_0c078df8;
P_0c078df8: /* original d00a, guest PC 0x0c078df8 */
if(!s->budget--) { s->failed_pc=0x0c078df8u; return 0; }
r[0]=read(ram,0x0c078e24u,4);
goto P_0c078dfa;
P_0c078dfa: /* original 7102, guest PC 0x0c078dfa */
if(!s->budget--) { s->failed_pc=0x0c078dfau; return 0; }
r[1]+=0x00000002u;
goto P_0c078dfc;
P_0c078dfc: /* original 6110, guest PC 0x0c078dfc */
if(!s->budget--) { s->failed_pc=0x0c078dfcu; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[1],1);
r[1]=tmp;
goto P_0c078dfe;
P_0c078dfe: /* original 611c, guest PC 0x0c078dfe */
if(!s->budget--) { s->failed_pc=0x0c078dfeu; return 0; }
r[1]=r[1]&255u;
goto P_0c078e00;
P_0c078e00: /* original 4118, guest PC 0x0c078e00 */
if(!s->budget--) { s->failed_pc=0x0c078e00u; return 0; }
r[1]<<=8;
goto P_0c078e02;
P_0c078e02: /* original 2109, guest PC 0x0c078e02 */
if(!s->budget--) { s->failed_pc=0x0c078e02u; return 0; }
r[1]&=r[0];
goto P_0c078e04;
P_0c078e04: /* original 9008, guest PC 0x0c078e04 */
if(!s->budget--) { s->failed_pc=0x0c078e04u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c078e18u,2);
goto P_0c078e06;
P_0c078e06: /* original 231b, guest PC 0x0c078e06 */
if(!s->budget--) { s->failed_pc=0x0c078e06u; return 0; }
r[3]|=r[1];
goto P_0c078e08;
P_0c078e08: /* original 01fe, guest PC 0x0c078e08 */
if(!s->budget--) { s->failed_pc=0x0c078e08u; return 0; }
r[1]=read(ram,r[15]+r[0],4);
goto P_0c078e0a;
P_0c078e0a: /* original 7101, guest PC 0x0c078e0a */
if(!s->budget--) { s->failed_pc=0x0c078e0au; return 0; }
r[1]+=0x00000001u;
goto P_0c078e0c;
P_0c078e0c: /* original 6110, guest PC 0x0c078e0c */
if(!s->budget--) { s->failed_pc=0x0c078e0cu; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[1],1);
r[1]=tmp;
goto P_0c078e0e;
P_0c078e0e: /* original 611c, guest PC 0x0c078e0e */
if(!s->budget--) { s->failed_pc=0x0c078e0eu; return 0; }
r[1]=r[1]&255u;
goto P_0c078e10;
P_0c078e10: /* original 231b, guest PC 0x0c078e10 */
if(!s->budget--) { s->failed_pc=0x0c078e10u; return 0; }
r[3]|=r[1];
goto P_0c078e12;
P_0c078e12: /* original d109, guest PC 0x0c078e12 */
if(!s->budget--) { s->failed_pc=0x0c078e12u; return 0; }
r[1]=read(ram,0x0c078e38u,4);
goto P_0c078e14;
P_0c078e14: /* original 412b, guest PC 0x0c078e14 */
if(!s->budget--) { s->failed_pc=0x0c078e14u; return 0; }
target=r[1];
switch(target&0x1fffffffu) {
case 0x0c07a336u: goto P_0c07a336;
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
P_0c078e16: /* original 0009, guest PC 0x0c078e16 */
if(!s->budget--) { s->failed_pc=0x0c078e16u; return 0; }
return vf3_matrix_family(0x0c078e18u,s,ram);
P_0c079462: /* original 905e, guest PC 0x0c079462 */
if(!s->budget--) { s->failed_pc=0x0c079462u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c079522u,2);
goto P_0c079464;
P_0c079464: /* original d231, guest PC 0x0c079464 */
if(!s->budget--) { s->failed_pc=0x0c079464u; return 0; }
r[2]=read(ram,0x0c07952cu,4);
goto P_0c079466;
P_0c079466: /* original 01fe, guest PC 0x0c079466 */
if(!s->budget--) { s->failed_pc=0x0c079466u; return 0; }
r[1]=read(ram,r[15]+r[0],4);
goto P_0c079468;
P_0c079468: /* original 7101, guest PC 0x0c079468 */
if(!s->budget--) { s->failed_pc=0x0c079468u; return 0; }
r[1]+=0x00000001u;
goto P_0c07946a;
P_0c07946a: /* original 6310, guest PC 0x0c07946a */
if(!s->budget--) { s->failed_pc=0x0c07946au; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[1],1);
r[3]=tmp;
goto P_0c07946c;
P_0c07946c: /* original 633c, guest PC 0x0c07946c */
if(!s->budget--) { s->failed_pc=0x0c07946cu; return 0; }
r[3]=r[3]&255u;
goto P_0c07946e;
P_0c07946e: /* original 633b, guest PC 0x0c07946e */
if(!s->budget--) { s->failed_pc=0x0c07946eu; return 0; }
r[3]=0u-r[3];
goto P_0c079470;
P_0c079470: /* original 423d, guest PC 0x0c079470 */
if(!s->budget--) { s->failed_pc=0x0c079470u; return 0; }
r[2]=(r[3]&0x80000000u)?((r[3]&31u)?r[2]>>((-r[3])&31u):0):r[2]<<(r[3]&31u);
goto P_0c079472;
P_0c079472: /* original 6323, guest PC 0x0c079472 */
if(!s->budget--) { s->failed_pc=0x0c079472u; return 0; }
r[3]=r[2];
goto P_0c079474;
P_0c079474: /* original 1f23, guest PC 0x0c079474 */
if(!s->budget--) { s->failed_pc=0x0c079474u; return 0; }
write(ram,r[15]+12,r[2],4);
goto P_0c079476;
P_0c079476: /* original 9056, guest PC 0x0c079476 */
if(!s->budget--) { s->failed_pc=0x0c079476u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c079526u,2);
goto P_0c079478;
P_0c079478: /* original 01fe, guest PC 0x0c079478 */
if(!s->budget--) { s->failed_pc=0x0c079478u; return 0; }
r[1]=read(ram,r[15]+r[0],4);
goto P_0c07947a;
P_0c07947a: /* original 2138, guest PC 0x0c07947a */
if(!s->budget--) { s->failed_pc=0x0c07947au; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[3])==0)!=0);
goto P_0c07947c;
P_0c07947c: /* original 8902, guest PC 0x0c07947c */
if(!s->budget--) { s->failed_pc=0x0c07947cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c079484; }
goto P_0c07947e;
P_0c07947e: /* original d22c, guest PC 0x0c07947e */
if(!s->budget--) { s->failed_pc=0x0c07947eu; return 0; }
r[2]=read(ram,0x0c079530u,4);
goto P_0c079480;
P_0c079480: /* original 422b, guest PC 0x0c079480 */
if(!s->budget--) { s->failed_pc=0x0c079480u; return 0; }
target=r[2];
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
P_0c079482: /* original 0009, guest PC 0x0c079482 */
if(!s->budget--) { s->failed_pc=0x0c079482u; return 0; }
goto P_0c079484;
P_0c079484: /* original 904d, guest PC 0x0c079484 */
if(!s->budget--) { s->failed_pc=0x0c079484u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c079522u,2);
goto P_0c079486;
P_0c079486: /* original 03fe, guest PC 0x0c079486 */
if(!s->budget--) { s->failed_pc=0x0c079486u; return 0; }
r[3]=read(ram,r[15]+r[0],4);
goto P_0c079488;
P_0c079488: /* original a755, guest PC 0x0c079488 */
if(!s->budget--) { s->failed_pc=0x0c079488u; return 0; }
r[3]+=0x00000002u;
goto P_0c07a336;
P_0c07948a: /* original 7302, guest PC 0x0c07948a */
if(!s->budget--) { s->failed_pc=0x0c07948au; return 0; }
r[3]+=0x00000002u;
return vf3_matrix_family(0x0c07948cu,s,ram);
P_0c079f96: /* original 9085, guest PC 0x0c079f96 */
if(!s->budget--) { s->failed_pc=0x0c079f96u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07a0a4u,2);
goto P_0c079f98;
P_0c079f98: /* original 01fe, guest PC 0x0c079f98 */
if(!s->budget--) { s->failed_pc=0x0c079f98u; return 0; }
r[1]=read(ram,r[15]+r[0],4);
goto P_0c079f9a;
P_0c079f9a: /* original e04c, guest PC 0x0c079f9a */
if(!s->budget--) { s->failed_pc=0x0c079f9au; return 0; }
r[0]=0x0000004cu;
goto P_0c079f9c;
P_0c079f9c: /* original 7101, guest PC 0x0c079f9c */
if(!s->budget--) { s->failed_pc=0x0c079f9cu; return 0; }
r[1]+=0x00000001u;
goto P_0c079f9e;
P_0c079f9e: /* original 6310, guest PC 0x0c079f9e */
if(!s->budget--) { s->failed_pc=0x0c079f9eu; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[1],1);
r[3]=tmp;
goto P_0c079fa0;
P_0c079fa0: /* original 633c, guest PC 0x0c079fa0 */
if(!s->budget--) { s->failed_pc=0x0c079fa0u; return 0; }
r[3]=r[3]&255u;
goto P_0c079fa2;
P_0c079fa2: /* original 1f33, guest PC 0x0c079fa2 */
if(!s->budget--) { s->failed_pc=0x0c079fa2u; return 0; }
write(ram,r[15]+12,r[3],4);
goto P_0c079fa4;
P_0c079fa4: /* original 02ee, guest PC 0x0c079fa4 */
if(!s->budget--) { s->failed_pc=0x0c079fa4u; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c079fa6;
P_0c079fa6: /* original 1f22, guest PC 0x0c079fa6 */
if(!s->budget--) { s->failed_pc=0x0c079fa6u; return 0; }
write(ram,r[15]+8,r[2],4);
goto P_0c079fa8;
P_0c079fa8: /* original 53f3, guest PC 0x0c079fa8 */
if(!s->budget--) { s->failed_pc=0x0c079fa8u; return 0; }
r[3]=read(ram,r[15]+12,4);
goto P_0c079faa;
P_0c079faa: /* original d13f, guest PC 0x0c079faa */
if(!s->budget--) { s->failed_pc=0x0c079faau; return 0; }
r[1]=read(ram,0x0c07a0a8u,4);
goto P_0c079fac;
P_0c079fac: /* original 633b, guest PC 0x0c079fac */
if(!s->budget--) { s->failed_pc=0x0c079facu; return 0; }
r[3]=0u-r[3];
goto P_0c079fae;
P_0c079fae: /* original 413d, guest PC 0x0c079fae */
if(!s->budget--) { s->failed_pc=0x0c079faeu; return 0; }
r[1]=(r[3]&0x80000000u)?((r[3]&31u)?r[1]>>((-r[3])&31u):0):r[1]<<(r[3]&31u);
goto P_0c079fb0;
P_0c079fb0: /* original 1f13, guest PC 0x0c079fb0 */
if(!s->budget--) { s->failed_pc=0x0c079fb0u; return 0; }
write(ram,r[15]+12,r[1],4);
goto P_0c079fb2;
P_0c079fb2: /* original 53f2, guest PC 0x0c079fb2 */
if(!s->budget--) { s->failed_pc=0x0c079fb2u; return 0; }
r[3]=read(ram,r[15]+8,4);
goto P_0c079fb4;
P_0c079fb4: /* original 2138, guest PC 0x0c079fb4 */
if(!s->budget--) { s->failed_pc=0x0c079fb4u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[3])==0)!=0);
goto P_0c079fb6;
P_0c079fb6: /* original 8901, guest PC 0x0c079fb6 */
if(!s->budget--) { s->failed_pc=0x0c079fb6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c079fbc; }
goto P_0c079fb8;
P_0c079fb8: /* original a384, guest PC 0x0c079fb8 */
if(!s->budget--) { s->failed_pc=0x0c079fb8u; return 0; }
goto P_0c07a6c4;
P_0c079fba: /* original 0009, guest PC 0x0c079fba */
if(!s->budget--) { s->failed_pc=0x0c079fbau; return 0; }
goto P_0c079fbc;
P_0c079fbc: /* original 9072, guest PC 0x0c079fbc */
if(!s->budget--) { s->failed_pc=0x0c079fbcu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07a0a4u,2);
goto P_0c079fbe;
P_0c079fbe: /* original 02fe, guest PC 0x0c079fbe */
if(!s->budget--) { s->failed_pc=0x0c079fbeu; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c079fc0;
P_0c079fc0: /* original a2a7, guest PC 0x0c079fc0 */
if(!s->budget--) { s->failed_pc=0x0c079fc0u; return 0; }
r[2]+=0x00000002u;
goto P_0c07a512;
P_0c079fc2: /* original 7202, guest PC 0x0c079fc2 */
if(!s->budget--) { s->failed_pc=0x0c079fc2u; return 0; }
r[2]+=0x00000002u;
return vf3_matrix_family(0x0c079fc4u,s,ram);
P_0c07a336: /* original d209, guest PC 0x0c07a336 */
if(!s->budget--) { s->failed_pc=0x0c07a336u; return 0; }
r[2]=read(ram,0x0c07a35cu,4);
goto P_0c07a338;
P_0c07a338: /* original 9001, guest PC 0x0c07a338 */
if(!s->budget--) { s->failed_pc=0x0c07a338u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07a33eu,2);
goto P_0c07a33a;
P_0c07a33a: /* original 422b, guest PC 0x0c07a33a */
if(!s->budget--) { s->failed_pc=0x0c07a33au; return 0; }
target=r[2];
write(ram,r[15]+r[0],r[3],4);
switch(target&0x1fffffffu) {
case 0x0c078376u: return vf3_matrix_family(0x0c078376u,s,ram);
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
P_0c07a33c: /* original 0f36, guest PC 0x0c07a33c */
if(!s->budget--) { s->failed_pc=0x0c07a33cu; return 0; }
write(ram,r[15]+r[0],r[3],4);
return vf3_matrix_family(0x0c07a33eu,s,ram);
P_0c07a4d8: /* original 9068, guest PC 0x0c07a4d8 */
if(!s->budget--) { s->failed_pc=0x0c07a4d8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07a5acu,2);
goto P_0c07a4da;
P_0c07a4da: /* original d236, guest PC 0x0c07a4da */
if(!s->budget--) { s->failed_pc=0x0c07a4dau; return 0; }
r[2]=read(ram,0x0c07a5b4u,4);
goto P_0c07a4dc;
P_0c07a4dc: /* original 01fe, guest PC 0x0c07a4dc */
if(!s->budget--) { s->failed_pc=0x0c07a4dcu; return 0; }
r[1]=read(ram,r[15]+r[0],4);
goto P_0c07a4de;
P_0c07a4de: /* original 9065, guest PC 0x0c07a4de */
if(!s->budget--) { s->failed_pc=0x0c07a4deu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07a5acu,2);
goto P_0c07a4e0;
P_0c07a4e0: /* original 7102, guest PC 0x0c07a4e0 */
if(!s->budget--) { s->failed_pc=0x0c07a4e0u; return 0; }
r[1]+=0x00000002u;
goto P_0c07a4e2;
P_0c07a4e2: /* original 6310, guest PC 0x0c07a4e2 */
if(!s->budget--) { s->failed_pc=0x0c07a4e2u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[1],1);
r[3]=tmp;
goto P_0c07a4e4;
P_0c07a4e4: /* original 01fe, guest PC 0x0c07a4e4 */
if(!s->budget--) { s->failed_pc=0x0c07a4e4u; return 0; }
r[1]=read(ram,r[15]+r[0],4);
goto P_0c07a4e6;
P_0c07a4e6: /* original e050, guest PC 0x0c07a4e6 */
if(!s->budget--) { s->failed_pc=0x0c07a4e6u; return 0; }
r[0]=0x00000050u;
goto P_0c07a4e8;
P_0c07a4e8: /* original 633c, guest PC 0x0c07a4e8 */
if(!s->budget--) { s->failed_pc=0x0c07a4e8u; return 0; }
r[3]=r[3]&255u;
goto P_0c07a4ea;
P_0c07a4ea: /* original 7101, guest PC 0x0c07a4ea */
if(!s->budget--) { s->failed_pc=0x0c07a4eau; return 0; }
r[1]+=0x00000001u;
goto P_0c07a4ec;
P_0c07a4ec: /* original 6110, guest PC 0x0c07a4ec */
if(!s->budget--) { s->failed_pc=0x0c07a4ecu; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[1],1);
r[1]=tmp;
goto P_0c07a4ee;
P_0c07a4ee: /* original 4318, guest PC 0x0c07a4ee */
if(!s->budget--) { s->failed_pc=0x0c07a4eeu; return 0; }
r[3]<<=8;
goto P_0c07a4f0;
P_0c07a4f0: /* original 2329, guest PC 0x0c07a4f0 */
if(!s->budget--) { s->failed_pc=0x0c07a4f0u; return 0; }
r[3]&=r[2];
goto P_0c07a4f2;
P_0c07a4f2: /* original 611c, guest PC 0x0c07a4f2 */
if(!s->budget--) { s->failed_pc=0x0c07a4f2u; return 0; }
r[1]=r[1]&255u;
goto P_0c07a4f4;
P_0c07a4f4: /* original 231b, guest PC 0x0c07a4f4 */
if(!s->budget--) { s->failed_pc=0x0c07a4f4u; return 0; }
r[3]|=r[1];
goto P_0c07a4f6;
P_0c07a4f6: /* original 0f36, guest PC 0x0c07a4f6 */
if(!s->budget--) { s->failed_pc=0x0c07a4f6u; return 0; }
write(ram,r[15]+r[0],r[3],4);
goto P_0c07a4f8;
P_0c07a4f8: /* original 9059, guest PC 0x0c07a4f8 */
if(!s->budget--) { s->failed_pc=0x0c07a4f8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07a5aeu,2);
goto P_0c07a4fa;
P_0c07a4fa: /* original 01ed, guest PC 0x0c07a4fa */
if(!s->budget--) { s->failed_pc=0x0c07a4fau; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c07a4fc;
P_0c07a4fc: /* original e04c, guest PC 0x0c07a4fc */
if(!s->budget--) { s->failed_pc=0x0c07a4fcu; return 0; }
r[0]=0x0000004cu;
goto P_0c07a4fe;
P_0c07a4fe: /* original 0f16, guest PC 0x0c07a4fe */
if(!s->budget--) { s->failed_pc=0x0c07a4feu; return 0; }
write(ram,r[15]+r[0],r[1],4);
goto P_0c07a500;
P_0c07a500: /* original e050, guest PC 0x0c07a500 */
if(!s->budget--) { s->failed_pc=0x0c07a500u; return 0; }
r[0]=0x00000050u;
goto P_0c07a502;
P_0c07a502: /* original 03fe, guest PC 0x0c07a502 */
if(!s->budget--) { s->failed_pc=0x0c07a502u; return 0; }
r[3]=read(ram,r[15]+r[0],4);
goto P_0c07a504;
P_0c07a504: /* original 3310, guest PC 0x0c07a504 */
if(!s->budget--) { s->failed_pc=0x0c07a504u; return 0; }
r[17]=(r[17]&~1u)|((r[3]==r[1])!=0);
goto P_0c07a506;
P_0c07a506: /* original 8901, guest PC 0x0c07a506 */
if(!s->budget--) { s->failed_pc=0x0c07a506u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07a50c; }
goto P_0c07a508;
P_0c07a508: /* original a0dc, guest PC 0x0c07a508 */
if(!s->budget--) { s->failed_pc=0x0c07a508u; return 0; }
goto P_0c07a6c4;
P_0c07a50a: /* original 0009, guest PC 0x0c07a50a */
if(!s->budget--) { s->failed_pc=0x0c07a50au; return 0; }
goto P_0c07a50c;
P_0c07a50c: /* original 904e, guest PC 0x0c07a50c */
if(!s->budget--) { s->failed_pc=0x0c07a50cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07a5acu,2);
goto P_0c07a50e;
P_0c07a50e: /* original 02fe, guest PC 0x0c07a50e */
if(!s->budget--) { s->failed_pc=0x0c07a50eu; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c07a510;
P_0c07a510: /* original 7203, guest PC 0x0c07a510 */
if(!s->budget--) { s->failed_pc=0x0c07a510u; return 0; }
r[2]+=0x00000003u;
goto P_0c07a512;
P_0c07a512: /* original d329, guest PC 0x0c07a512 */
if(!s->budget--) { s->failed_pc=0x0c07a512u; return 0; }
r[3]=read(ram,0x0c07a5b8u,4);
goto P_0c07a514;
P_0c07a514: /* original 904a, guest PC 0x0c07a514 */
if(!s->budget--) { s->failed_pc=0x0c07a514u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07a5acu,2);
goto P_0c07a516;
P_0c07a516: /* original 432b, guest PC 0x0c07a516 */
if(!s->budget--) { s->failed_pc=0x0c07a516u; return 0; }
target=r[3];
write(ram,r[15]+r[0],r[2],4);
switch(target&0x1fffffffu) {
case 0x0c078376u: return vf3_matrix_family(0x0c078376u,s,ram);
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
P_0c07a518: /* original 0f26, guest PC 0x0c07a518 */
if(!s->budget--) { s->failed_pc=0x0c07a518u; return 0; }
write(ram,r[15]+r[0],r[2],4);
return vf3_matrix_family(0x0c07a51au,s,ram);
P_0c07a6c4: /* original e068, guest PC 0x0c07a6c4 */
if(!s->budget--) { s->failed_pc=0x0c07a6c4u; return 0; }
r[0]=0x00000068u;
goto P_0c07a6c6;
P_0c07a6c6: /* original 53c5, guest PC 0x0c07a6c6 */
if(!s->budget--) { s->failed_pc=0x0c07a6c6u; return 0; }
r[3]=read(ram,r[12]+20,4);
goto P_0c07a6c8;
P_0c07a6c8: /* original 6233, guest PC 0x0c07a6c8 */
if(!s->budget--) { s->failed_pc=0x0c07a6c8u; return 0; }
r[2]=r[3];
goto P_0c07a6ca;
P_0c07a6ca: /* original 1f3d, guest PC 0x0c07a6ca */
if(!s->budget--) { s->failed_pc=0x0c07a6cau; return 0; }
write(ram,r[15]+52,r[3],4);
goto P_0c07a6cc;
P_0c07a6cc: /* original 01fe, guest PC 0x0c07a6cc */
if(!s->budget--) { s->failed_pc=0x0c07a6ccu; return 0; }
r[1]=read(ram,r[15]+r[0],4);
goto P_0c07a6ce;
P_0c07a6ce: /* original 3122, guest PC 0x0c07a6ce */
if(!s->budget--) { s->failed_pc=0x0c07a6ceu; return 0; }
r[17]=(r[17]&~1u)|((r[1]>=r[2])!=0);
goto P_0c07a6d0;
P_0c07a6d0: /* original 893d, guest PC 0x0c07a6d0 */
if(!s->budget--) { s->failed_pc=0x0c07a6d0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07a74e; }
goto P_0c07a6d2;
P_0c07a6d2: /* original e068, guest PC 0x0c07a6d2 */
if(!s->budget--) { s->failed_pc=0x0c07a6d2u; return 0; }
r[0]=0x00000068u;
goto P_0c07a6d4;
P_0c07a6d4: /* original 03fe, guest PC 0x0c07a6d4 */
if(!s->budget--) { s->failed_pc=0x0c07a6d4u; return 0; }
r[3]=read(ram,r[15]+r[0],4);
goto P_0c07a6d6;
P_0c07a6d6: /* original 731e, guest PC 0x0c07a6d6 */
if(!s->budget--) { s->failed_pc=0x0c07a6d6u; return 0; }
r[3]+=0x0000001eu;
goto P_0c07a6d8;
P_0c07a6d8: /* original 6231, guest PC 0x0c07a6d8 */
if(!s->budget--) { s->failed_pc=0x0c07a6d8u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[3],2);
r[2]=tmp;
goto P_0c07a6da;
P_0c07a6da: /* original 622d, guest PC 0x0c07a6da */
if(!s->budget--) { s->failed_pc=0x0c07a6dau; return 0; }
r[2]=r[2]&65535u;
goto P_0c07a6dc;
P_0c07a6dc: /* original 2228, guest PC 0x0c07a6dc */
if(!s->budget--) { s->failed_pc=0x0c07a6dcu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c07a6de;
P_0c07a6de: /* original 8f29, guest PC 0x0c07a6de */
if(!s->budget--) { s->failed_pc=0x0c07a6deu; return 0; }
cond=r[17]&1u;
write(ram,r[15]+52,r[2],4);
if(!cond) { goto P_0c07a734; }
goto P_0c07a6e2;
P_0c07a6e0: /* original 1f2d, guest PC 0x0c07a6e0 */
if(!s->budget--) { s->failed_pc=0x0c07a6e0u; return 0; }
write(ram,r[15]+52,r[2],4);
goto P_0c07a6e2;
P_0c07a6e2: /* original e068, guest PC 0x0c07a6e2 */
if(!s->budget--) { s->failed_pc=0x0c07a6e2u; return 0; }
r[0]=0x00000068u;
goto P_0c07a6e4;
P_0c07a6e4: /* original 03fe, guest PC 0x0c07a6e4 */
if(!s->budget--) { s->failed_pc=0x0c07a6e4u; return 0; }
r[3]=read(ram,r[15]+r[0],4);
goto P_0c07a6e6;
P_0c07a6e6: /* original 9054, guest PC 0x0c07a6e6 */
if(!s->budget--) { s->failed_pc=0x0c07a6e6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07a792u,2);
goto P_0c07a6e8;
P_0c07a6e8: /* original 7304, guest PC 0x0c07a6e8 */
if(!s->budget--) { s->failed_pc=0x0c07a6e8u; return 0; }
r[3]+=0x00000004u;
goto P_0c07a6ea;
P_0c07a6ea: /* original 6232, guest PC 0x0c07a6ea */
if(!s->budget--) { s->failed_pc=0x0c07a6eau; return 0; }
tmp=read(ram,r[3],4);
r[2]=tmp;
goto P_0c07a6ec;
P_0c07a6ec: /* original 0f26, guest PC 0x0c07a6ec */
if(!s->budget--) { s->failed_pc=0x0c07a6ecu; return 0; }
write(ram,r[15]+r[0],r[2],4);
goto P_0c07a6ee;
P_0c07a6ee: /* original e068, guest PC 0x0c07a6ee */
if(!s->budget--) { s->failed_pc=0x0c07a6eeu; return 0; }
r[0]=0x00000068u;
goto P_0c07a6f0;
P_0c07a6f0: /* original 03fe, guest PC 0x0c07a6f0 */
if(!s->budget--) { s->failed_pc=0x0c07a6f0u; return 0; }
r[3]=read(ram,r[15]+r[0],4);
goto P_0c07a6f2;
P_0c07a6f2: /* original 904d, guest PC 0x0c07a6f2 */
if(!s->budget--) { s->failed_pc=0x0c07a6f2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07a790u,2);
goto P_0c07a6f4;
P_0c07a6f4: /* original 6232, guest PC 0x0c07a6f4 */
if(!s->budget--) { s->failed_pc=0x0c07a6f4u; return 0; }
tmp=read(ram,r[3],4);
r[2]=tmp;
goto P_0c07a6f6;
P_0c07a6f6: /* original 0f26, guest PC 0x0c07a6f6 */
if(!s->budget--) { s->failed_pc=0x0c07a6f6u; return 0; }
write(ram,r[15]+r[0],r[2],4);
goto P_0c07a6f8;
P_0c07a6f8: /* original e068, guest PC 0x0c07a6f8 */
if(!s->budget--) { s->failed_pc=0x0c07a6f8u; return 0; }
r[0]=0x00000068u;
goto P_0c07a6fa;
P_0c07a6fa: /* original 03fe, guest PC 0x0c07a6fa */
if(!s->budget--) { s->failed_pc=0x0c07a6fau; return 0; }
r[3]=read(ram,r[15]+r[0],4);
goto P_0c07a6fc;
P_0c07a6fc: /* original e058, guest PC 0x0c07a6fc */
if(!s->budget--) { s->failed_pc=0x0c07a6fcu; return 0; }
r[0]=0x00000058u;
goto P_0c07a6fe;
P_0c07a6fe: /* original 7308, guest PC 0x0c07a6fe */
if(!s->budget--) { s->failed_pc=0x0c07a6feu; return 0; }
r[3]+=0x00000008u;
goto P_0c07a700;
P_0c07a700: /* original 6232, guest PC 0x0c07a700 */
if(!s->budget--) { s->failed_pc=0x0c07a700u; return 0; }
tmp=read(ram,r[3],4);
r[2]=tmp;
goto P_0c07a702;
P_0c07a702: /* original 0f26, guest PC 0x0c07a702 */
if(!s->budget--) { s->failed_pc=0x0c07a702u; return 0; }
write(ram,r[15]+r[0],r[2],4);
goto P_0c07a704;
P_0c07a704: /* original e068, guest PC 0x0c07a704 */
if(!s->budget--) { s->failed_pc=0x0c07a704u; return 0; }
r[0]=0x00000068u;
goto P_0c07a706;
P_0c07a706: /* original 03fe, guest PC 0x0c07a706 */
if(!s->budget--) { s->failed_pc=0x0c07a706u; return 0; }
r[3]=read(ram,r[15]+r[0],4);
goto P_0c07a708;
P_0c07a708: /* original e064, guest PC 0x0c07a708 */
if(!s->budget--) { s->failed_pc=0x0c07a708u; return 0; }
r[0]=0x00000064u;
goto P_0c07a70a;
P_0c07a70a: /* original 730c, guest PC 0x0c07a70a */
if(!s->budget--) { s->failed_pc=0x0c07a70au; return 0; }
r[3]+=0x0000000cu;
goto P_0c07a70c;
P_0c07a70c: /* original 6232, guest PC 0x0c07a70c */
if(!s->budget--) { s->failed_pc=0x0c07a70cu; return 0; }
tmp=read(ram,r[3],4);
r[2]=tmp;
goto P_0c07a70e;
P_0c07a70e: /* original 0f26, guest PC 0x0c07a70e */
if(!s->budget--) { s->failed_pc=0x0c07a70eu; return 0; }
write(ram,r[15]+r[0],r[2],4);
goto P_0c07a710;
P_0c07a710: /* original e068, guest PC 0x0c07a710 */
if(!s->budget--) { s->failed_pc=0x0c07a710u; return 0; }
r[0]=0x00000068u;
goto P_0c07a712;
P_0c07a712: /* original 03fe, guest PC 0x0c07a712 */
if(!s->budget--) { s->failed_pc=0x0c07a712u; return 0; }
r[3]=read(ram,r[15]+r[0],4);
goto P_0c07a714;
P_0c07a714: /* original e054, guest PC 0x0c07a714 */
if(!s->budget--) { s->failed_pc=0x0c07a714u; return 0; }
r[0]=0x00000054u;
goto P_0c07a716;
P_0c07a716: /* original 7310, guest PC 0x0c07a716 */
if(!s->budget--) { s->failed_pc=0x0c07a716u; return 0; }
r[3]+=0x00000010u;
goto P_0c07a718;
P_0c07a718: /* original 6232, guest PC 0x0c07a718 */
if(!s->budget--) { s->failed_pc=0x0c07a718u; return 0; }
tmp=read(ram,r[3],4);
r[2]=tmp;
goto P_0c07a71a;
P_0c07a71a: /* original 0f26, guest PC 0x0c07a71a */
if(!s->budget--) { s->failed_pc=0x0c07a71au; return 0; }
write(ram,r[15]+r[0],r[2],4);
goto P_0c07a71c;
P_0c07a71c: /* original e068, guest PC 0x0c07a71c */
if(!s->budget--) { s->failed_pc=0x0c07a71cu; return 0; }
r[0]=0x00000068u;
goto P_0c07a71e;
P_0c07a71e: /* original 03fe, guest PC 0x0c07a71e */
if(!s->budget--) { s->failed_pc=0x0c07a71eu; return 0; }
r[3]=read(ram,r[15]+r[0],4);
goto P_0c07a720;
P_0c07a720: /* original 7314, guest PC 0x0c07a720 */
if(!s->budget--) { s->failed_pc=0x0c07a720u; return 0; }
r[3]+=0x00000014u;
goto P_0c07a722;
P_0c07a722: /* original 6232, guest PC 0x0c07a722 */
if(!s->budget--) { s->failed_pc=0x0c07a722u; return 0; }
tmp=read(ram,r[3],4);
r[2]=tmp;
goto P_0c07a724;
P_0c07a724: /* original e05c, guest PC 0x0c07a724 */
if(!s->budget--) { s->failed_pc=0x0c07a724u; return 0; }
r[0]=0x0000005cu;
goto P_0c07a726;
P_0c07a726: /* original 0f26, guest PC 0x0c07a726 */
if(!s->budget--) { s->failed_pc=0x0c07a726u; return 0; }
write(ram,r[15]+r[0],r[2],4);
goto P_0c07a728;
P_0c07a728: /* original e068, guest PC 0x0c07a728 */
if(!s->budget--) { s->failed_pc=0x0c07a728u; return 0; }
r[0]=0x00000068u;
goto P_0c07a72a;
P_0c07a72a: /* original 03fe, guest PC 0x0c07a72a */
if(!s->budget--) { s->failed_pc=0x0c07a72au; return 0; }
r[3]=read(ram,r[15]+r[0],4);
goto P_0c07a72c;
P_0c07a72c: /* original e060, guest PC 0x0c07a72c */
if(!s->budget--) { s->failed_pc=0x0c07a72cu; return 0; }
r[0]=0x00000060u;
goto P_0c07a72e;
P_0c07a72e: /* original 731c, guest PC 0x0c07a72e */
if(!s->budget--) { s->failed_pc=0x0c07a72eu; return 0; }
r[3]+=0x0000001cu;
goto P_0c07a730;
P_0c07a730: /* original 6232, guest PC 0x0c07a730 */
if(!s->budget--) { s->failed_pc=0x0c07a730u; return 0; }
tmp=read(ram,r[3],4);
r[2]=tmp;
goto P_0c07a732;
P_0c07a732: /* original 0f26, guest PC 0x0c07a732 */
if(!s->budget--) { s->failed_pc=0x0c07a732u; return 0; }
write(ram,r[15]+r[0],r[2],4);
goto P_0c07a734;
P_0c07a734: /* original e068, guest PC 0x0c07a734 */
if(!s->budget--) { s->failed_pc=0x0c07a734u; return 0; }
r[0]=0x00000068u;
goto P_0c07a736;
P_0c07a736: /* original 03fe, guest PC 0x0c07a736 */
if(!s->budget--) { s->failed_pc=0x0c07a736u; return 0; }
r[3]=read(ram,r[15]+r[0],4);
goto P_0c07a738;
P_0c07a738: /* original 902c, guest PC 0x0c07a738 */
if(!s->budget--) { s->failed_pc=0x0c07a738u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07a794u,2);
goto P_0c07a73a;
P_0c07a73a: /* original 7318, guest PC 0x0c07a73a */
if(!s->budget--) { s->failed_pc=0x0c07a73au; return 0; }
r[3]+=0x00000018u;
goto P_0c07a73c;
P_0c07a73c: /* original 6232, guest PC 0x0c07a73c */
if(!s->budget--) { s->failed_pc=0x0c07a73cu; return 0; }
tmp=read(ram,r[3],4);
r[2]=tmp;
goto P_0c07a73e;
P_0c07a73e: /* original 0f26, guest PC 0x0c07a73e */
if(!s->budget--) { s->failed_pc=0x0c07a73eu; return 0; }
write(ram,r[15]+r[0],r[2],4);
goto P_0c07a740;
P_0c07a740: /* original e068, guest PC 0x0c07a740 */
if(!s->budget--) { s->failed_pc=0x0c07a740u; return 0; }
r[0]=0x00000068u;
goto P_0c07a742;
P_0c07a742: /* original 03fe, guest PC 0x0c07a742 */
if(!s->budget--) { s->failed_pc=0x0c07a742u; return 0; }
r[3]=read(ram,r[15]+r[0],4);
goto P_0c07a744;
P_0c07a744: /* original e068, guest PC 0x0c07a744 */
if(!s->budget--) { s->failed_pc=0x0c07a744u; return 0; }
r[0]=0x00000068u;
goto P_0c07a746;
P_0c07a746: /* original d217, guest PC 0x0c07a746 */
if(!s->budget--) { s->failed_pc=0x0c07a746u; return 0; }
r[2]=read(ram,0x0c07a7a4u,4);
goto P_0c07a748;
P_0c07a748: /* original 7320, guest PC 0x0c07a748 */
if(!s->budget--) { s->failed_pc=0x0c07a748u; return 0; }
r[3]+=0x00000020u;
goto P_0c07a74a;
P_0c07a74a: /* original 422b, guest PC 0x0c07a74a */
if(!s->budget--) { s->failed_pc=0x0c07a74au; return 0; }
target=r[2];
write(ram,r[15]+r[0],r[3],4);
switch(target&0x1fffffffu) {
case 0x0c078376u: return vf3_matrix_family(0x0c078376u,s,ram);
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
P_0c07a74c: /* original 0f36, guest PC 0x0c07a74c */
if(!s->budget--) { s->failed_pc=0x0c07a74cu; return 0; }
write(ram,r[15]+r[0],r[3],4);
goto P_0c07a74e;
P_0c07a74e: /* original 9022, guest PC 0x0c07a74e */
if(!s->budget--) { s->failed_pc=0x0c07a74eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07a796u,2);
goto P_0c07a750;
P_0c07a750: /* original e300, guest PC 0x0c07a750 */
if(!s->budget--) { s->failed_pc=0x0c07a750u; return 0; }
r[3]=0x00000000u;
goto P_0c07a752;
P_0c07a752: /* original 01fe, guest PC 0x0c07a752 */
if(!s->budget--) { s->failed_pc=0x0c07a752u; return 0; }
r[1]=read(ram,r[15]+r[0],4);
goto P_0c07a754;
P_0c07a754: /* original 2132, guest PC 0x0c07a754 */
if(!s->budget--) { s->failed_pc=0x0c07a754u; return 0; }
write(ram,r[1],r[3],4);
goto P_0c07a756;
P_0c07a756: /* original a014, guest PC 0x0c07a756 */
if(!s->budget--) { s->failed_pc=0x0c07a756u; return 0; }
r[0]=0x00000000u;
goto P_0c07a782;
P_0c07a758: /* original e000, guest PC 0x0c07a758 */
if(!s->budget--) { s->failed_pc=0x0c07a758u; return 0; }
r[0]=0x00000000u;
return vf3_matrix_family(0x0c07a75au,s,ram);
P_0c07a782: /* original 910e, guest PC 0x0c07a782 */
if(!s->budget--) { s->failed_pc=0x0c07a782u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07a7a2u,2);
goto P_0c07a784;
P_0c07a784: /* original 3f1c, guest PC 0x0c07a784 */
if(!s->budget--) { s->failed_pc=0x0c07a784u; return 0; }
r[15]+=r[1];
goto P_0c07a786;
P_0c07a786: /* original 4f26, guest PC 0x0c07a786 */
if(!s->budget--) { s->failed_pc=0x0c07a786u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c07a788;
P_0c07a788: /* original 6cf6, guest PC 0x0c07a788 */
if(!s->budget--) { s->failed_pc=0x0c07a788u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c07a78a;
P_0c07a78a: /* original 6df6, guest PC 0x0c07a78a */
if(!s->budget--) { s->failed_pc=0x0c07a78au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c07a78c;
P_0c07a78c: /* original 000b, guest PC 0x0c07a78c */
if(!s->budget--) { s->failed_pc=0x0c07a78cu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c07a78e: /* original 6ef6, guest PC 0x0c07a78e */
if(!s->budget--) { s->failed_pc=0x0c07a78eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c07a790u,s,ram);
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
r[16]=0x8c07b9bau;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07b9bau) { target=s->pc; goto dispatch; }
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
r[16]=0x8c07b9ecu;
r[4]=r[12];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07b9ecu) { target=s->pc; goto dispatch; }
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
switch(target&0x1fffffffu) {
case 0x0c07c820u: return vf3_matrix_family(0x0c07c820u,s,ram);
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
P_0c07ba08: /* original 6ef6, guest PC 0x0c07ba08 */
if(!s->budget--) { s->failed_pc=0x0c07ba08u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c07ba0au,s,ram);
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
r[16]=0x8c07ba66u;
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
r[16]=0x8c07ba72u;
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
r[16]=0x8c07ba80u;
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
r[16]=0x8c07ba8eu;
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
r[16]=0x8c07ba9au;
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
r[16]=0x8c07bae8u;
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
r[16]=0x8c07bbb0u;
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
r[16]=0x8c07bbd6u;
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
r[16]=0x8c07bbeeu;
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
r[16]=0x8c07bbfcu;
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
r[16]=0x8c07bc14u;
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
r[16]=0x8c07bc26u;
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
r[16]=0x8c07bc34u;
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
r[16]=0x8c07bc4cu;
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
r[16]=0x8c07bc5au;
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
r[16]=0x8c07bc80u;
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
r[16]=0x8c07bca0u;
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
r[16]=0x8c07bd7cu;
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
r[16]=0x8c07bda6u;
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
r[16]=0x8c07bdd8u;
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
r[16]=0x8c07be0au;
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
r[16]=0x8c07be24u;
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
r[16]=0x8c07be66u;
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
r[16]=0x8c07bec8u;
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
r[16]=0x8c07bef4u;
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
r[16]=0x8c07bf2eu;
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
r[16]=0x8c07bf6au;
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
r[16]=0x8c07bf8au;
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
r[16]=0x8c07bfc2u;
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
r[16]=0x8c07c008u;
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
r[16]=0x8c07c01cu;
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
r[16]=0x8c07c030u;
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
r[16]=0x8c07c060u;
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
r[16]=0x8c07c06eu;
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
r[16]=0x8c07c09au;
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
r[16]=0x8c07c0b8u;
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
r[16]=0x8c07c0d2u;
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
r[16]=0x8c07c158u;
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
r[16]=0x8c07c184u;
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
r[16]=0x8c07c1c8u;
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
r[16]=0x8c07c1e6u;
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
r[16]=0x8c07c21cu;
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
r[16]=0x8c07c268u;
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
r[16]=0x8c07c27cu;
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
r[16]=0x8c07c290u;
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
r[16]=0x8c07c2a4u;
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
r[16]=0x8c07c2b2u;
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
r[16]=0x8c07c2dcu;
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
r[16]=0x8c07c2e6u;
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
r[16]=0x8c07c2f2u;
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
r[16]=0x8c07c300u;
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
P_0c07c8ca: /* original 2fe6, guest PC 0x0c07c8ca */
if(!s->budget--) { s->failed_pc=0x0c07c8cau; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07c8cc;
P_0c07c8cc: /* original 4f22, guest PC 0x0c07c8cc */
if(!s->budget--) { s->failed_pc=0x0c07c8ccu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c07c8ce;
P_0c07c8ce: /* original 7ffc, guest PC 0x0c07c8ce */
if(!s->budget--) { s->failed_pc=0x0c07c8ceu; return 0; }
r[15]+=0xfffffffcu;
goto P_0c07c8d0;
P_0c07c8d0: /* original bfd0, guest PC 0x0c07c8d0 */
if(!s->budget--) { s->failed_pc=0x0c07c8d0u; return 0; }
target=0x0c07c874u; r[16]=0x8c07c8d4u;
write(ram,r[15],r[4],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07c8d4u) { target=s->pc; goto dispatch; }
goto P_0c07c8d4;
P_0c07c8d2: /* original 2f42, guest PC 0x0c07c8d2 */
if(!s->budget--) { s->failed_pc=0x0c07c8d2u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c07c8d4;
P_0c07c8d4: /* original d321, guest PC 0x0c07c8d4 */
if(!s->budget--) { s->failed_pc=0x0c07c8d4u; return 0; }
r[3]=read(ram,0x0c07c95cu,4);
goto P_0c07c8d6;
P_0c07c8d6: /* original e200, guest PC 0x0c07c8d6 */
if(!s->budget--) { s->failed_pc=0x0c07c8d6u; return 0; }
r[2]=0x00000000u;
goto P_0c07c8d8;
P_0c07c8d8: /* original de1c, guest PC 0x0c07c8d8 */
if(!s->budget--) { s->failed_pc=0x0c07c8d8u; return 0; }
r[14]=read(ram,0x0c07c94cu,4);
goto P_0c07c8da;
P_0c07c8da: /* original 2320, guest PC 0x0c07c8da */
if(!s->budget--) { s->failed_pc=0x0c07c8dau; return 0; }
write(ram,r[3],r[2],1);
goto P_0c07c8dc;
P_0c07c8dc: /* original d220, guest PC 0x0c07c8dc */
if(!s->budget--) { s->failed_pc=0x0c07c8dcu; return 0; }
r[2]=read(ram,0x0c07c960u,4);
goto P_0c07c8de;
P_0c07c8de: /* original 9531, guest PC 0x0c07c8de */
if(!s->budget--) { s->failed_pc=0x0c07c8deu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07c944u,2);
goto P_0c07c8e0;
P_0c07c8e0: /* original 420b, guest PC 0x0c07c8e0 */
if(!s->budget--) { s->failed_pc=0x0c07c8e0u; return 0; }
target=r[2];
r[16]=0x8c07c8e4u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07c8e4u) { target=s->pc; goto dispatch; }
goto P_0c07c8e4;
P_0c07c8e2: /* original 64e3, guest PC 0x0c07c8e2 */
if(!s->budget--) { s->failed_pc=0x0c07c8e2u; return 0; }
r[4]=r[14];
goto P_0c07c8e4;
P_0c07c8e4: /* original d31f, guest PC 0x0c07c8e4 */
if(!s->budget--) { s->failed_pc=0x0c07c8e4u; return 0; }
r[3]=read(ram,0x0c07c964u,4);
goto P_0c07c8e6;
P_0c07c8e6: /* original 430b, guest PC 0x0c07c8e6 */
if(!s->budget--) { s->failed_pc=0x0c07c8e6u; return 0; }
target=r[3];
r[16]=0x8c07c8eau;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07c8eau) { target=s->pc; goto dispatch; }
goto P_0c07c8ea;
P_0c07c8e8: /* original 0009, guest PC 0x0c07c8e8 */
if(!s->budget--) { s->failed_pc=0x0c07c8e8u; return 0; }
goto P_0c07c8ea;
P_0c07c8ea: /* original d21d, guest PC 0x0c07c8ea */
if(!s->budget--) { s->failed_pc=0x0c07c8eau; return 0; }
r[2]=read(ram,0x0c07c960u,4);
goto P_0c07c8ec;
P_0c07c8ec: /* original 952b, guest PC 0x0c07c8ec */
if(!s->budget--) { s->failed_pc=0x0c07c8ecu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07c946u,2);
goto P_0c07c8ee;
P_0c07c8ee: /* original 420b, guest PC 0x0c07c8ee */
if(!s->budget--) { s->failed_pc=0x0c07c8eeu; return 0; }
target=r[2];
r[16]=0x8c07c8f2u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07c8f2u) { target=s->pc; goto dispatch; }
goto P_0c07c8f2;
P_0c07c8f0: /* original 64e3, guest PC 0x0c07c8f0 */
if(!s->budget--) { s->failed_pc=0x0c07c8f0u; return 0; }
r[4]=r[14];
goto P_0c07c8f2;
P_0c07c8f2: /* original 64f2, guest PC 0x0c07c8f2 */
if(!s->budget--) { s->failed_pc=0x0c07c8f2u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c07c8f4;
P_0c07c8f4: /* original 7f04, guest PC 0x0c07c8f4 */
if(!s->budget--) { s->failed_pc=0x0c07c8f4u; return 0; }
r[15]+=0x00000004u;
goto P_0c07c8f6;
P_0c07c8f6: /* original 4f26, guest PC 0x0c07c8f6 */
if(!s->budget--) { s->failed_pc=0x0c07c8f6u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c07c8f8;
P_0c07c8f8: /* original a06c, guest PC 0x0c07c8f8 */
if(!s->budget--) { s->failed_pc=0x0c07c8f8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c07c9d4;
P_0c07c8fa: /* original 6ef6, guest PC 0x0c07c8fa */
if(!s->budget--) { s->failed_pc=0x0c07c8fau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c07c8fc;
P_0c07c8fc: /* original 2fe6, guest PC 0x0c07c8fc */
if(!s->budget--) { s->failed_pc=0x0c07c8fcu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07c8fe;
P_0c07c8fe: /* original 4f22, guest PC 0x0c07c8fe */
if(!s->budget--) { s->failed_pc=0x0c07c8feu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c07c900;
P_0c07c900: /* original 7ffc, guest PC 0x0c07c900 */
if(!s->budget--) { s->failed_pc=0x0c07c900u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c07c902;
P_0c07c902: /* original bfb7, guest PC 0x0c07c902 */
if(!s->budget--) { s->failed_pc=0x0c07c902u; return 0; }
target=0x0c07c874u; r[16]=0x8c07c906u;
write(ram,r[15],r[4],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07c906u) { target=s->pc; goto dispatch; }
goto P_0c07c906;
P_0c07c904: /* original 2f42, guest PC 0x0c07c904 */
if(!s->budget--) { s->failed_pc=0x0c07c904u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c07c906;
P_0c07c906: /* original d315, guest PC 0x0c07c906 */
if(!s->budget--) { s->failed_pc=0x0c07c906u; return 0; }
r[3]=read(ram,0x0c07c95cu,4);
goto P_0c07c908;
P_0c07c908: /* original e206, guest PC 0x0c07c908 */
if(!s->budget--) { s->failed_pc=0x0c07c908u; return 0; }
r[2]=0x00000006u;
goto P_0c07c90a;
P_0c07c90a: /* original de10, guest PC 0x0c07c90a */
if(!s->budget--) { s->failed_pc=0x0c07c90au; return 0; }
r[14]=read(ram,0x0c07c94cu,4);
goto P_0c07c90c;
P_0c07c90c: /* original 2320, guest PC 0x0c07c90c */
if(!s->budget--) { s->failed_pc=0x0c07c90cu; return 0; }
write(ram,r[3],r[2],1);
goto P_0c07c90e;
P_0c07c90e: /* original d214, guest PC 0x0c07c90e */
if(!s->budget--) { s->failed_pc=0x0c07c90eu; return 0; }
r[2]=read(ram,0x0c07c960u,4);
goto P_0c07c910;
P_0c07c910: /* original 9518, guest PC 0x0c07c910 */
if(!s->budget--) { s->failed_pc=0x0c07c910u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07c944u,2);
goto P_0c07c912;
P_0c07c912: /* original 420b, guest PC 0x0c07c912 */
if(!s->budget--) { s->failed_pc=0x0c07c912u; return 0; }
target=r[2];
r[16]=0x8c07c916u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07c916u) { target=s->pc; goto dispatch; }
goto P_0c07c916;
P_0c07c914: /* original 64e3, guest PC 0x0c07c914 */
if(!s->budget--) { s->failed_pc=0x0c07c914u; return 0; }
r[4]=r[14];
goto P_0c07c916;
P_0c07c916: /* original d313, guest PC 0x0c07c916 */
if(!s->budget--) { s->failed_pc=0x0c07c916u; return 0; }
r[3]=read(ram,0x0c07c964u,4);
goto P_0c07c918;
P_0c07c918: /* original 430b, guest PC 0x0c07c918 */
if(!s->budget--) { s->failed_pc=0x0c07c918u; return 0; }
target=r[3];
r[16]=0x8c07c91cu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07c91cu) { target=s->pc; goto dispatch; }
goto P_0c07c91c;
P_0c07c91a: /* original 0009, guest PC 0x0c07c91a */
if(!s->budget--) { s->failed_pc=0x0c07c91au; return 0; }
goto P_0c07c91c;
P_0c07c91c: /* original d210, guest PC 0x0c07c91c */
if(!s->budget--) { s->failed_pc=0x0c07c91cu; return 0; }
r[2]=read(ram,0x0c07c960u,4);
goto P_0c07c91e;
P_0c07c91e: /* original 9512, guest PC 0x0c07c91e */
if(!s->budget--) { s->failed_pc=0x0c07c91eu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07c946u,2);
goto P_0c07c920;
P_0c07c920: /* original 420b, guest PC 0x0c07c920 */
if(!s->budget--) { s->failed_pc=0x0c07c920u; return 0; }
target=r[2];
r[16]=0x8c07c924u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07c924u) { target=s->pc; goto dispatch; }
goto P_0c07c924;
P_0c07c922: /* original 64e3, guest PC 0x0c07c922 */
if(!s->budget--) { s->failed_pc=0x0c07c922u; return 0; }
r[4]=r[14];
goto P_0c07c924;
P_0c07c924: /* original 64f2, guest PC 0x0c07c924 */
if(!s->budget--) { s->failed_pc=0x0c07c924u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c07c926;
P_0c07c926: /* original 7f04, guest PC 0x0c07c926 */
if(!s->budget--) { s->failed_pc=0x0c07c926u; return 0; }
r[15]+=0x00000004u;
goto P_0c07c928;
P_0c07c928: /* original 4f26, guest PC 0x0c07c928 */
if(!s->budget--) { s->failed_pc=0x0c07c928u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c07c92a;
P_0c07c92a: /* original a053, guest PC 0x0c07c92a */
if(!s->budget--) { s->failed_pc=0x0c07c92au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c07c9d4;
P_0c07c92c: /* original 6ef6, guest PC 0x0c07c92c */
if(!s->budget--) { s->failed_pc=0x0c07c92cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c07c92eu,s,ram);
P_0c07c968: /* original 2fe6, guest PC 0x0c07c968 */
if(!s->budget--) { s->failed_pc=0x0c07c968u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07c96a;
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
target=0x0c07c874u; r[16]=0x8c07c972u;
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
r[16]=0x8c07c982u;
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
r[16]=0x8c07c988u;
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
r[16]=0x8c07c990u;
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
target=0x0c07c9e6u; r[16]=0x8c07c9dcu;
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
P_0c08944c: /* original 2fe6, guest PC 0x0c08944c */
if(!s->budget--) { s->failed_pc=0x0c08944cu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08944e;
P_0c08944e: /* original 6e43, guest PC 0x0c08944e */
if(!s->budget--) { s->failed_pc=0x0c08944eu; return 0; }
r[14]=r[4];
goto P_0c089450;
P_0c089450: /* original 2fd6, guest PC 0x0c089450 */
if(!s->budget--) { s->failed_pc=0x0c089450u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c089452;
P_0c089452: /* original d125, guest PC 0x0c089452 */
if(!s->budget--) { s->failed_pc=0x0c089452u; return 0; }
r[1]=read(ram,0x0c0894e8u,4);
goto P_0c089454;
P_0c089454: /* original d323, guest PC 0x0c089454 */
if(!s->budget--) { s->failed_pc=0x0c089454u; return 0; }
r[3]=read(ram,0x0c0894e4u,4);
goto P_0c089456;
P_0c089456: /* original 4f22, guest PC 0x0c089456 */
if(!s->budget--) { s->failed_pc=0x0c089456u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c089458;
P_0c089458: /* original 6212, guest PC 0x0c089458 */
if(!s->budget--) { s->failed_pc=0x0c089458u; return 0; }
tmp=read(ram,r[1],4);
r[2]=tmp;
goto P_0c08945a;
P_0c08945a: /* original d521, guest PC 0x0c08945a */
if(!s->budget--) { s->failed_pc=0x0c08945au; return 0; }
r[5]=read(ram,0x0c0894e0u,4);
goto P_0c08945c;
P_0c08945c: /* original 2238, guest PC 0x0c08945c */
if(!s->budget--) { s->failed_pc=0x0c08945cu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c08945e;
P_0c08945e: /* original 8f1d, guest PC 0x0c08945e */
if(!s->budget--) { s->failed_pc=0x0c08945eu; return 0; }
cond=r[17]&1u;
r[7]=0x00000001u;
if(!cond) { goto P_0c08949c; }
goto P_0c089462;
P_0c089460: /* original e701, guest PC 0x0c089460 */
if(!s->budget--) { s->failed_pc=0x0c089460u; return 0; }
r[7]=0x00000001u;
goto P_0c089462;
P_0c089462: /* original e01c, guest PC 0x0c089462 */
if(!s->budget--) { s->failed_pc=0x0c089462u; return 0; }
r[0]=0x0000001cu;
goto P_0c089464;
P_0c089464: /* original 0d5c, guest PC 0x0c089464 */
if(!s->budget--) { s->failed_pc=0x0c089464u; return 0; }
r[13]=(uint32_t)(int32_t)(int8_t)read(ram,r[5]+r[0],1);
goto P_0c089466;
P_0c089466: /* original e010, guest PC 0x0c089466 */
if(!s->budget--) { s->failed_pc=0x0c089466u; return 0; }
r[0]=0x00000010u;
goto P_0c089468;
P_0c089468: /* original 04ec, guest PC 0x0c089468 */
if(!s->budget--) { s->failed_pc=0x0c089468u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c08946a;
P_0c08946a: /* original 85ec, guest PC 0x0c08946a */
if(!s->budget--) { s->failed_pc=0x0c08946au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+24,2);
goto P_0c08946c;
P_0c08946c: /* original 8801, guest PC 0x0c08946c */
if(!s->budget--) { s->failed_pc=0x0c08946cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c08946e;
P_0c08946e: /* original 8f03, guest PC 0x0c08946e */
if(!s->budget--) { s->failed_pc=0x0c08946eu; return 0; }
cond=r[17]&1u;
r[13]=r[13]&255u;
if(!cond) { goto P_0c089478; }
goto P_0c089472;
P_0c089470: /* original 6ddc, guest PC 0x0c089470 */
if(!s->budget--) { s->failed_pc=0x0c089470u; return 0; }
r[13]=r[13]&255u;
goto P_0c089472;
P_0c089472: /* original e000, guest PC 0x0c089472 */
if(!s->budget--) { s->failed_pc=0x0c089472u; return 0; }
r[0]=0x00000000u;
goto P_0c089474;
P_0c089474: /* original a022, guest PC 0x0c089474 */
if(!s->budget--) { s->failed_pc=0x0c089474u; return 0; }
write(ram,r[14]+24,r[0],2);
goto P_0c0894bc;
P_0c089476: /* original 81ec, guest PC 0x0c089476 */
if(!s->budget--) { s->failed_pc=0x0c089476u; return 0; }
write(ram,r[14]+24,r[0],2);
goto P_0c089478;
P_0c089478: /* original 922e, guest PC 0x0c089478 */
if(!s->budget--) { s->failed_pc=0x0c089478u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0894d8u,2);
goto P_0c08947a;
P_0c08947a: /* original 6652, guest PC 0x0c08947a */
if(!s->budget--) { s->failed_pc=0x0c08947au; return 0; }
tmp=read(ram,r[5],4);
r[6]=tmp;
goto P_0c08947c;
P_0c08947c: /* original 2268, guest PC 0x0c08947c */
if(!s->budget--) { s->failed_pc=0x0c08947cu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[6])==0)!=0);
goto P_0c08947e;
P_0c08947e: /* original 8b13, guest PC 0x0c08947e */
if(!s->budget--) { s->failed_pc=0x0c08947eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0894a8; }
goto P_0c089480;
P_0c089480: /* original d31a, guest PC 0x0c089480 */
if(!s->budget--) { s->failed_pc=0x0c089480u; return 0; }
r[3]=read(ram,0x0c0894ecu,4);
goto P_0c089482;
P_0c089482: /* original 2638, guest PC 0x0c089482 */
if(!s->budget--) { s->failed_pc=0x0c089482u; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[3])==0)!=0);
goto P_0c089484;
P_0c089484: /* original 8924, guest PC 0x0c089484 */
if(!s->budget--) { s->failed_pc=0x0c089484u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0894d0; }
goto P_0c089486;
P_0c089486: /* original 8459, guest PC 0x0c089486 */
if(!s->budget--) { s->failed_pc=0x0c089486u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[5]+9,1);
goto P_0c089488;
P_0c089488: /* original 600c, guest PC 0x0c089488 */
if(!s->budget--) { s->failed_pc=0x0c089488u; return 0; }
r[0]=r[0]&255u;
goto P_0c08948a;
P_0c08948a: /* original 8804, guest PC 0x0c08948a */
if(!s->budget--) { s->failed_pc=0x0c08948au; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000004u)!=0);
goto P_0c08948c;
P_0c08948c: /* original 8d11, guest PC 0x0c08948c */
if(!s->budget--) { s->failed_pc=0x0c08948cu; return 0; }
cond=r[17]&1u;
r[6]=r[0];
if(cond) { goto P_0c0894b2; }
goto P_0c089490;
P_0c08948e: /* original 6603, guest PC 0x0c08948e */
if(!s->budget--) { s->failed_pc=0x0c08948eu; return 0; }
r[6]=r[0];
goto P_0c089490;
P_0c089490: /* original d317, guest PC 0x0c089490 */
if(!s->budget--) { s->failed_pc=0x0c089490u; return 0; }
r[3]=read(ram,0x0c0894f0u,4);
goto P_0c089492;
P_0c089492: /* original 5451, guest PC 0x0c089492 */
if(!s->budget--) { s->failed_pc=0x0c089492u; return 0; }
r[4]=read(ram,r[5]+4,4);
goto P_0c089494;
P_0c089494: /* original 2438, guest PC 0x0c089494 */
if(!s->budget--) { s->failed_pc=0x0c089494u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[3])==0)!=0);
goto P_0c089496;
P_0c089496: /* original 8b1b, guest PC 0x0c089496 */
if(!s->budget--) { s->failed_pc=0x0c089496u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0894d0; }
goto P_0c089498;
P_0c089498: /* original a013, guest PC 0x0c089498 */
if(!s->budget--) { s->failed_pc=0x0c089498u; return 0; }
goto P_0c0894c2;
P_0c08949a: /* original 0009, guest PC 0x0c08949a */
if(!s->budget--) { s->failed_pc=0x0c08949au; return 0; }
goto P_0c08949c;
P_0c08949c: /* original 6073, guest PC 0x0c08949c */
if(!s->budget--) { s->failed_pc=0x0c08949cu; return 0; }
r[0]=r[7];
goto P_0c08949e;
P_0c08949e: /* original 81ec, guest PC 0x0c08949e */
if(!s->budget--) { s->failed_pc=0x0c08949eu; return 0; }
write(ram,r[14]+24,r[0],2);
goto P_0c0894a0;
P_0c0894a0: /* original e01c, guest PC 0x0c0894a0 */
if(!s->budget--) { s->failed_pc=0x0c0894a0u; return 0; }
r[0]=0x0000001cu;
goto P_0c0894a2;
P_0c0894a2: /* original 045c, guest PC 0x0c0894a2 */
if(!s->budget--) { s->failed_pc=0x0c0894a2u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[5]+r[0],1);
goto P_0c0894a4;
P_0c0894a4: /* original a005, guest PC 0x0c0894a4 */
if(!s->budget--) { s->failed_pc=0x0c0894a4u; return 0; }
r[4]=r[4]&255u;
goto P_0c0894b2;
P_0c0894a6: /* original 644c, guest PC 0x0c0894a6 */
if(!s->budget--) { s->failed_pc=0x0c0894a6u; return 0; }
r[4]=r[4]&255u;
goto P_0c0894a8;
P_0c0894a8: /* original 3d40, guest PC 0x0c0894a8 */
if(!s->budget--) { s->failed_pc=0x0c0894a8u; return 0; }
r[17]=(r[17]&~1u)|((r[13]==r[4])!=0);
goto P_0c0894aa;
P_0c0894aa: /* original 890a, guest PC 0x0c0894aa */
if(!s->budget--) { s->failed_pc=0x0c0894aau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0894c2; }
goto P_0c0894ac;
P_0c0894ac: /* original e010, guest PC 0x0c0894ac */
if(!s->budget--) { s->failed_pc=0x0c0894acu; return 0; }
r[0]=0x00000010u;
goto P_0c0894ae;
P_0c0894ae: /* original 0ed4, guest PC 0x0c0894ae */
if(!s->budget--) { s->failed_pc=0x0c0894aeu; return 0; }
write(ram,r[14]+r[0],r[13],1);
goto P_0c0894b0;
P_0c0894b0: /* original 2e72, guest PC 0x0c0894b0 */
if(!s->budget--) { s->failed_pc=0x0c0894b0u; return 0; }
write(ram,r[14],r[7],4);
goto P_0c0894b2;
P_0c0894b2: /* original b01f, guest PC 0x0c0894b2 */
if(!s->budget--) { s->failed_pc=0x0c0894b2u; return 0; }
target=0x0c0894f4u; r[16]=0x8c0894b6u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0894b6u) { target=s->pc; goto dispatch; }
goto P_0c0894b6;
P_0c0894b4: /* original 0009, guest PC 0x0c0894b4 */
if(!s->budget--) { s->failed_pc=0x0c0894b4u; return 0; }
goto P_0c0894b6;
P_0c0894b6: /* original 85ec, guest PC 0x0c0894b6 */
if(!s->budget--) { s->failed_pc=0x0c0894b6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+24,2);
goto P_0c0894b8;
P_0c0894b8: /* original 8801, guest PC 0x0c0894b8 */
if(!s->budget--) { s->failed_pc=0x0c0894b8u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c0894ba;
P_0c0894ba: /* original 8909, guest PC 0x0c0894ba */
if(!s->budget--) { s->failed_pc=0x0c0894bau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0894d0; }
goto P_0c0894bc;
P_0c0894bc: /* original 65e3, guest PC 0x0c0894bc */
if(!s->budget--) { s->failed_pc=0x0c0894bcu; return 0; }
r[5]=r[14];
goto P_0c0894be;
P_0c0894be: /* original b064, guest PC 0x0c0894be */
if(!s->budget--) { s->failed_pc=0x0c0894beu; return 0; }
target=0x0c08958au; r[16]=0x8c0894c2u;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0894c2u) { target=s->pc; goto dispatch; }
goto P_0c0894c2;
P_0c0894c0: /* original 64d3, guest PC 0x0c0894c0 */
if(!s->budget--) { s->failed_pc=0x0c0894c0u; return 0; }
r[4]=r[13];
goto P_0c0894c2;
P_0c0894c2: /* original b0a9, guest PC 0x0c0894c2 */
if(!s->budget--) { s->failed_pc=0x0c0894c2u; return 0; }
target=0x0c089618u; r[16]=0x8c0894c6u;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0894c6u) { target=s->pc; goto dispatch; }
goto P_0c0894c6;
P_0c0894c4: /* original 64d3, guest PC 0x0c0894c4 */
if(!s->budget--) { s->failed_pc=0x0c0894c4u; return 0; }
r[4]=r[13];
goto P_0c0894c6;
P_0c0894c6: /* original b0ef, guest PC 0x0c0894c6 */
if(!s->budget--) { s->failed_pc=0x0c0894c6u; return 0; }
target=0x0c0896a8u; r[16]=0x8c0894cau;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0894cau) { target=s->pc; goto dispatch; }
goto P_0c0894ca;
P_0c0894c8: /* original 64d3, guest PC 0x0c0894c8 */
if(!s->budget--) { s->failed_pc=0x0c0894c8u; return 0; }
r[4]=r[13];
goto P_0c0894ca;
P_0c0894ca: /* original 65e3, guest PC 0x0c0894ca */
if(!s->budget--) { s->failed_pc=0x0c0894cau; return 0; }
r[5]=r[14];
goto P_0c0894cc;
P_0c0894cc: /* original b0fb, guest PC 0x0c0894cc */
if(!s->budget--) { s->failed_pc=0x0c0894ccu; return 0; }
target=0x0c0896c6u; r[16]=0x8c0894d0u;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0894d0u) { target=s->pc; goto dispatch; }
goto P_0c0894d0;
P_0c0894ce: /* original 64d3, guest PC 0x0c0894ce */
if(!s->budget--) { s->failed_pc=0x0c0894ceu; return 0; }
r[4]=r[13];
goto P_0c0894d0;
P_0c0894d0: /* original 4f26, guest PC 0x0c0894d0 */
if(!s->budget--) { s->failed_pc=0x0c0894d0u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0894d2;
P_0c0894d2: /* original 6df6, guest PC 0x0c0894d2 */
if(!s->budget--) { s->failed_pc=0x0c0894d2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0894d4;
P_0c0894d4: /* original 000b, guest PC 0x0c0894d4 */
if(!s->budget--) { s->failed_pc=0x0c0894d4u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0894d6: /* original 6ef6, guest PC 0x0c0894d6 */
if(!s->budget--) { s->failed_pc=0x0c0894d6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0894d8u,s,ram);
P_0c08b7ea: /* original 2fe6, guest PC 0x0c08b7ea */
if(!s->budget--) { s->failed_pc=0x0c08b7eau; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08b7ec;
P_0c08b7ec: /* original 6e43, guest PC 0x0c08b7ec */
if(!s->budget--) { s->failed_pc=0x0c08b7ecu; return 0; }
r[14]=r[4];
goto P_0c08b7ee;
P_0c08b7ee: /* original 4f22, guest PC 0x0c08b7ee */
if(!s->budget--) { s->failed_pc=0x0c08b7eeu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c08b7f0;
P_0c08b7f0: /* original e04c, guest PC 0x0c08b7f0 */
if(!s->budget--) { s->failed_pc=0x0c08b7f0u; return 0; }
r[0]=0x0000004cu;
goto P_0c08b7f2;
P_0c08b7f2: /* original 7fac, guest PC 0x0c08b7f2 */
if(!s->budget--) { s->failed_pc=0x0c08b7f2u; return 0; }
r[15]+=0xffffffacu;
goto P_0c08b7f4;
P_0c08b7f4: /* original 2fe2, guest PC 0x0c08b7f4 */
if(!s->budget--) { s->failed_pc=0x0c08b7f4u; return 0; }
write(ram,r[15],r[14],4);
goto P_0c08b7f6;
P_0c08b7f6: /* original d426, guest PC 0x0c08b7f6 */
if(!s->budget--) { s->failed_pc=0x0c08b7f6u; return 0; }
r[4]=read(ram,0x0c08b890u,4);
goto P_0c08b7f8;
P_0c08b7f8: /* original 5344, guest PC 0x0c08b7f8 */
if(!s->budget--) { s->failed_pc=0x0c08b7f8u; return 0; }
r[3]=read(ram,r[4]+16,4);
goto P_0c08b7fa;
P_0c08b7fa: /* original 0f36, guest PC 0x0c08b7fa */
if(!s->budget--) { s->failed_pc=0x0c08b7fau; return 0; }
write(ram,r[15]+r[0],r[3],4);
goto P_0c08b7fc;
P_0c08b7fc: /* original e050, guest PC 0x0c08b7fc */
if(!s->budget--) { s->failed_pc=0x0c08b7fcu; return 0; }
r[0]=0x00000050u;
goto P_0c08b7fe;
P_0c08b7fe: /* original 5245, guest PC 0x0c08b7fe */
if(!s->budget--) { s->failed_pc=0x0c08b7feu; return 0; }
r[2]=read(ram,r[4]+20,4);
goto P_0c08b800;
P_0c08b800: /* original 0f26, guest PC 0x0c08b800 */
if(!s->budget--) { s->failed_pc=0x0c08b800u; return 0; }
write(ram,r[15]+r[0],r[2],4);
goto P_0c08b802;
P_0c08b802: /* original 544a, guest PC 0x0c08b802 */
if(!s->budget--) { s->failed_pc=0x0c08b802u; return 0; }
r[4]=read(ram,r[4]+40,4);
goto P_0c08b804;
P_0c08b804: /* original 6042, guest PC 0x0c08b804 */
if(!s->budget--) { s->failed_pc=0x0c08b804u; return 0; }
tmp=read(ram,r[4],4);
r[0]=tmp;
goto P_0c08b806;
P_0c08b806: /* original c802, guest PC 0x0c08b806 */
if(!s->budget--) { s->failed_pc=0x0c08b806u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&2u)==0)!=0);
goto P_0c08b808;
P_0c08b808: /* original 8b0f, guest PC 0x0c08b808 */
if(!s->budget--) { s->failed_pc=0x0c08b808u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c08b82a; }
goto P_0c08b80a;
P_0c08b80a: /* original d123, guest PC 0x0c08b80a */
if(!s->budget--) { s->failed_pc=0x0c08b80au; return 0; }
r[1]=read(ram,0x0c08b898u,4);
goto P_0c08b80c;
P_0c08b80c: /* original d321, guest PC 0x0c08b80c */
if(!s->budget--) { s->failed_pc=0x0c08b80cu; return 0; }
r[3]=read(ram,0x0c08b894u,4);
goto P_0c08b80e;
P_0c08b80e: /* original 6212, guest PC 0x0c08b80e */
if(!s->budget--) { s->failed_pc=0x0c08b80eu; return 0; }
tmp=read(ram,r[1],4);
r[2]=tmp;
goto P_0c08b810;
P_0c08b810: /* original 2238, guest PC 0x0c08b810 */
if(!s->budget--) { s->failed_pc=0x0c08b810u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c08b812;
P_0c08b812: /* original 8b0a, guest PC 0x0c08b812 */
if(!s->budget--) { s->failed_pc=0x0c08b812u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c08b82a; }
goto P_0c08b814;
P_0c08b814: /* original 65f3, guest PC 0x0c08b814 */
if(!s->budget--) { s->failed_pc=0x0c08b814u; return 0; }
r[5]=r[15];
goto P_0c08b816;
P_0c08b816: /* original 7504, guest PC 0x0c08b816 */
if(!s->budget--) { s->failed_pc=0x0c08b816u; return 0; }
r[5]+=0x00000004u;
goto P_0c08b818;
P_0c08b818: /* original b040, guest PC 0x0c08b818 */
if(!s->budget--) { s->failed_pc=0x0c08b818u; return 0; }
target=0x0c08b89cu; r[16]=0x8c08b81cu;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08b81cu) { target=s->pc; goto dispatch; }
goto P_0c08b81c;
P_0c08b81a: /* original 64e3, guest PC 0x0c08b81a */
if(!s->budget--) { s->failed_pc=0x0c08b81au; return 0; }
r[4]=r[14];
goto P_0c08b81c;
P_0c08b81c: /* original 65f3, guest PC 0x0c08b81c */
if(!s->budget--) { s->failed_pc=0x0c08b81cu; return 0; }
r[5]=r[15];
goto P_0c08b81e;
P_0c08b81e: /* original 7504, guest PC 0x0c08b81e */
if(!s->budget--) { s->failed_pc=0x0c08b81eu; return 0; }
r[5]+=0x00000004u;
goto P_0c08b820;
P_0c08b820: /* original b178, guest PC 0x0c08b820 */
if(!s->budget--) { s->failed_pc=0x0c08b820u; return 0; }
target=0x0c08bb14u; r[16]=0x8c08b824u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08b824u) { target=s->pc; goto dispatch; }
goto P_0c08b824;
P_0c08b822: /* original 64e3, guest PC 0x0c08b822 */
if(!s->budget--) { s->failed_pc=0x0c08b822u; return 0; }
r[4]=r[14];
goto P_0c08b824;
P_0c08b824: /* original 52f1, guest PC 0x0c08b824 */
if(!s->budget--) { s->failed_pc=0x0c08b824u; return 0; }
r[2]=read(ram,r[15]+4,4);
goto P_0c08b826;
P_0c08b826: /* original 63f2, guest PC 0x0c08b826 */
if(!s->budget--) { s->failed_pc=0x0c08b826u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c08b828;
P_0c08b828: /* original 1324, guest PC 0x0c08b828 */
if(!s->budget--) { s->failed_pc=0x0c08b828u; return 0; }
write(ram,r[3]+16,r[2],4);
goto P_0c08b82a;
P_0c08b82a: /* original 7f54, guest PC 0x0c08b82a */
if(!s->budget--) { s->failed_pc=0x0c08b82au; return 0; }
r[15]+=0x00000054u;
goto P_0c08b82c;
P_0c08b82c: /* original 4f26, guest PC 0x0c08b82c */
if(!s->budget--) { s->failed_pc=0x0c08b82cu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c08b82e;
P_0c08b82e: /* original 000b, guest PC 0x0c08b82e */
if(!s->budget--) { s->failed_pc=0x0c08b82eu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c08b830: /* original 6ef6, guest PC 0x0c08b830 */
if(!s->budget--) { s->failed_pc=0x0c08b830u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c08b832;
P_0c08b832: /* original 2fe6, guest PC 0x0c08b832 */
if(!s->budget--) { s->failed_pc=0x0c08b832u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08b834;
P_0c08b834: /* original 6e43, guest PC 0x0c08b834 */
if(!s->budget--) { s->failed_pc=0x0c08b834u; return 0; }
r[14]=r[4];
goto P_0c08b836;
P_0c08b836: /* original 4f22, guest PC 0x0c08b836 */
if(!s->budget--) { s->failed_pc=0x0c08b836u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c08b838;
P_0c08b838: /* original e04c, guest PC 0x0c08b838 */
if(!s->budget--) { s->failed_pc=0x0c08b838u; return 0; }
r[0]=0x0000004cu;
goto P_0c08b83a;
P_0c08b83a: /* original 7fac, guest PC 0x0c08b83a */
if(!s->budget--) { s->failed_pc=0x0c08b83au; return 0; }
r[15]+=0xffffffacu;
goto P_0c08b83c;
P_0c08b83c: /* original 2fe2, guest PC 0x0c08b83c */
if(!s->budget--) { s->failed_pc=0x0c08b83cu; return 0; }
write(ram,r[15],r[14],4);
goto P_0c08b83e;
P_0c08b83e: /* original d414, guest PC 0x0c08b83e */
if(!s->budget--) { s->failed_pc=0x0c08b83eu; return 0; }
r[4]=read(ram,0x0c08b890u,4);
goto P_0c08b840;
P_0c08b840: /* original 5345, guest PC 0x0c08b840 */
if(!s->budget--) { s->failed_pc=0x0c08b840u; return 0; }
r[3]=read(ram,r[4]+20,4);
goto P_0c08b842;
P_0c08b842: /* original 0f36, guest PC 0x0c08b842 */
if(!s->budget--) { s->failed_pc=0x0c08b842u; return 0; }
write(ram,r[15]+r[0],r[3],4);
goto P_0c08b844;
P_0c08b844: /* original e302, guest PC 0x0c08b844 */
if(!s->budget--) { s->failed_pc=0x0c08b844u; return 0; }
r[3]=0x00000002u;
goto P_0c08b846;
P_0c08b846: /* original 5244, guest PC 0x0c08b846 */
if(!s->budget--) { s->failed_pc=0x0c08b846u; return 0; }
r[2]=read(ram,r[4]+16,4);
goto P_0c08b848;
P_0c08b848: /* original e050, guest PC 0x0c08b848 */
if(!s->budget--) { s->failed_pc=0x0c08b848u; return 0; }
r[0]=0x00000050u;
goto P_0c08b84a;
P_0c08b84a: /* original 0f26, guest PC 0x0c08b84a */
if(!s->budget--) { s->failed_pc=0x0c08b84au; return 0; }
write(ram,r[15]+r[0],r[2],4);
goto P_0c08b84c;
P_0c08b84c: /* original 554b, guest PC 0x0c08b84c */
if(!s->budget--) { s->failed_pc=0x0c08b84cu; return 0; }
r[5]=read(ram,r[4]+44,4);
goto P_0c08b84e;
P_0c08b84e: /* original 6552, guest PC 0x0c08b84e */
if(!s->budget--) { s->failed_pc=0x0c08b84eu; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c08b850;
P_0c08b850: /* original 2538, guest PC 0x0c08b850 */
if(!s->budget--) { s->failed_pc=0x0c08b850u; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[3])==0)!=0);
goto P_0c08b852;
P_0c08b852: /* original 8b16, guest PC 0x0c08b852 */
if(!s->budget--) { s->failed_pc=0x0c08b852u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c08b882; }
goto P_0c08b854;
P_0c08b854: /* original d110, guest PC 0x0c08b854 */
if(!s->budget--) { s->failed_pc=0x0c08b854u; return 0; }
r[1]=read(ram,0x0c08b898u,4);
goto P_0c08b856;
P_0c08b856: /* original d30f, guest PC 0x0c08b856 */
if(!s->budget--) { s->failed_pc=0x0c08b856u; return 0; }
r[3]=read(ram,0x0c08b894u,4);
goto P_0c08b858;
P_0c08b858: /* original 6212, guest PC 0x0c08b858 */
if(!s->budget--) { s->failed_pc=0x0c08b858u; return 0; }
tmp=read(ram,r[1],4);
r[2]=tmp;
goto P_0c08b85a;
P_0c08b85a: /* original 2238, guest PC 0x0c08b85a */
if(!s->budget--) { s->failed_pc=0x0c08b85au; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c08b85c;
P_0c08b85c: /* original 8b11, guest PC 0x0c08b85c */
if(!s->budget--) { s->failed_pc=0x0c08b85cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c08b882; }
goto P_0c08b85e;
P_0c08b85e: /* original 61f3, guest PC 0x0c08b85e */
if(!s->budget--) { s->failed_pc=0x0c08b85eu; return 0; }
r[1]=r[15];
goto P_0c08b860;
P_0c08b860: /* original 5045, guest PC 0x0c08b860 */
if(!s->budget--) { s->failed_pc=0x0c08b860u; return 0; }
r[0]=read(ram,r[4]+20,4);
goto P_0c08b862;
P_0c08b862: /* original 714c, guest PC 0x0c08b862 */
if(!s->budget--) { s->failed_pc=0x0c08b862u; return 0; }
r[1]+=0x0000004cu;
goto P_0c08b864;
P_0c08b864: /* original 65f3, guest PC 0x0c08b864 */
if(!s->budget--) { s->failed_pc=0x0c08b864u; return 0; }
r[5]=r[15];
goto P_0c08b866;
P_0c08b866: /* original 2102, guest PC 0x0c08b866 */
if(!s->budget--) { s->failed_pc=0x0c08b866u; return 0; }
write(ram,r[1],r[0],4);
goto P_0c08b868;
P_0c08b868: /* original e050, guest PC 0x0c08b868 */
if(!s->budget--) { s->failed_pc=0x0c08b868u; return 0; }
r[0]=0x00000050u;
goto P_0c08b86a;
P_0c08b86a: /* original 5344, guest PC 0x0c08b86a */
if(!s->budget--) { s->failed_pc=0x0c08b86au; return 0; }
r[3]=read(ram,r[4]+16,4);
goto P_0c08b86c;
P_0c08b86c: /* original 7504, guest PC 0x0c08b86c */
if(!s->budget--) { s->failed_pc=0x0c08b86cu; return 0; }
r[5]+=0x00000004u;
goto P_0c08b86e;
P_0c08b86e: /* original 0f36, guest PC 0x0c08b86e */
if(!s->budget--) { s->failed_pc=0x0c08b86eu; return 0; }
write(ram,r[15]+r[0],r[3],4);
goto P_0c08b870;
P_0c08b870: /* original b014, guest PC 0x0c08b870 */
if(!s->budget--) { s->failed_pc=0x0c08b870u; return 0; }
target=0x0c08b89cu; r[16]=0x8c08b874u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08b874u) { target=s->pc; goto dispatch; }
goto P_0c08b874;
P_0c08b872: /* original 64e3, guest PC 0x0c08b872 */
if(!s->budget--) { s->failed_pc=0x0c08b872u; return 0; }
r[4]=r[14];
goto P_0c08b874;
P_0c08b874: /* original 65f3, guest PC 0x0c08b874 */
if(!s->budget--) { s->failed_pc=0x0c08b874u; return 0; }
r[5]=r[15];
goto P_0c08b876;
P_0c08b876: /* original 7504, guest PC 0x0c08b876 */
if(!s->budget--) { s->failed_pc=0x0c08b876u; return 0; }
r[5]+=0x00000004u;
goto P_0c08b878;
P_0c08b878: /* original b14c, guest PC 0x0c08b878 */
if(!s->budget--) { s->failed_pc=0x0c08b878u; return 0; }
target=0x0c08bb14u; r[16]=0x8c08b87cu;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08b87cu) { target=s->pc; goto dispatch; }
goto P_0c08b87c;
P_0c08b87a: /* original 64e3, guest PC 0x0c08b87a */
if(!s->budget--) { s->failed_pc=0x0c08b87au; return 0; }
r[4]=r[14];
goto P_0c08b87c;
P_0c08b87c: /* original 52f1, guest PC 0x0c08b87c */
if(!s->budget--) { s->failed_pc=0x0c08b87cu; return 0; }
r[2]=read(ram,r[15]+4,4);
goto P_0c08b87e;
P_0c08b87e: /* original 63f2, guest PC 0x0c08b87e */
if(!s->budget--) { s->failed_pc=0x0c08b87eu; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c08b880;
P_0c08b880: /* original 1324, guest PC 0x0c08b880 */
if(!s->budget--) { s->failed_pc=0x0c08b880u; return 0; }
write(ram,r[3]+16,r[2],4);
goto P_0c08b882;
P_0c08b882: /* original 7f54, guest PC 0x0c08b882 */
if(!s->budget--) { s->failed_pc=0x0c08b882u; return 0; }
r[15]+=0x00000054u;
goto P_0c08b884;
P_0c08b884: /* original 4f26, guest PC 0x0c08b884 */
if(!s->budget--) { s->failed_pc=0x0c08b884u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c08b886;
P_0c08b886: /* original 000b, guest PC 0x0c08b886 */
if(!s->budget--) { s->failed_pc=0x0c08b886u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c08b888: /* original 6ef6, guest PC 0x0c08b888 */
if(!s->budget--) { s->failed_pc=0x0c08b888u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c08b88au,s,ram);
P_0c091c20: /* original 2fe6, guest PC 0x0c091c20 */
if(!s->budget--) { s->failed_pc=0x0c091c20u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c091c22;
P_0c091c22: /* original 2fd6, guest PC 0x0c091c22 */
if(!s->budget--) { s->failed_pc=0x0c091c22u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c091c24;
P_0c091c24: /* original 6d53, guest PC 0x0c091c24 */
if(!s->budget--) { s->failed_pc=0x0c091c24u; return 0; }
r[13]=r[5];
goto P_0c091c26;
P_0c091c26: /* original 2fc6, guest PC 0x0c091c26 */
if(!s->budget--) { s->failed_pc=0x0c091c26u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c091c28;
P_0c091c28: /* original 7d68, guest PC 0x0c091c28 */
if(!s->budget--) { s->failed_pc=0x0c091c28u; return 0; }
r[13]+=0x00000068u;
goto P_0c091c2a;
P_0c091c2a: /* original 2fb6, guest PC 0x0c091c2a */
if(!s->budget--) { s->failed_pc=0x0c091c2au; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c091c2c;
P_0c091c2c: /* original 6b73, guest PC 0x0c091c2c */
if(!s->budget--) { s->failed_pc=0x0c091c2cu; return 0; }
r[11]=r[7];
goto P_0c091c2e;
P_0c091c2e: /* original 2fa6, guest PC 0x0c091c2e */
if(!s->budget--) { s->failed_pc=0x0c091c2eu; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c091c30;
P_0c091c30: /* original 2f96, guest PC 0x0c091c30 */
if(!s->budget--) { s->failed_pc=0x0c091c30u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c091c32;
P_0c091c32: /* original 2f86, guest PC 0x0c091c32 */
if(!s->budget--) { s->failed_pc=0x0c091c32u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c091c34;
P_0c091c34: /* original fffb, guest PC 0x0c091c34 */
if(!s->budget--) { s->failed_pc=0x0c091c34u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c091c36;
P_0c091c36: /* original ffeb, guest PC 0x0c091c36 */
if(!s->budget--) { s->failed_pc=0x0c091c36u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,14,r[15]);
goto P_0c091c38;
P_0c091c38: /* original ffdb, guest PC 0x0c091c38 */
if(!s->budget--) { s->failed_pc=0x0c091c38u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,13,r[15]);
goto P_0c091c3a;
P_0c091c3a: /* original 4f22, guest PC 0x0c091c3a */
if(!s->budget--) { s->failed_pc=0x0c091c3au; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c091c3c;
P_0c091c3c: /* original 7fe0, guest PC 0x0c091c3c */
if(!s->budget--) { s->failed_pc=0x0c091c3cu; return 0; }
r[15]+=0xffffffe0u;
goto P_0c091c3e;
P_0c091c3e: /* original 1f65, guest PC 0x0c091c3e */
if(!s->budget--) { s->failed_pc=0x0c091c3eu; return 0; }
write(ram,r[15]+20,r[6],4);
goto P_0c091c40;
P_0c091c40: /* original 9094, guest PC 0x0c091c40 */
if(!s->budget--) { s->failed_pc=0x0c091c40u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c091d6cu,2);
goto P_0c091c42;
P_0c091c42: /* original 0c5e, guest PC 0x0c091c42 */
if(!s->budget--) { s->failed_pc=0x0c091c42u; return 0; }
r[12]=read(ram,r[5]+r[0],4);
goto P_0c091c44;
P_0c091c44: /* original 7004, guest PC 0x0c091c44 */
if(!s->budget--) { s->failed_pc=0x0c091c44u; return 0; }
r[0]+=0x00000004u;
goto P_0c091c46;
P_0c091c46: /* original 045e, guest PC 0x0c091c46 */
if(!s->budget--) { s->failed_pc=0x0c091c46u; return 0; }
r[4]=read(ram,r[5]+r[0],4);
goto P_0c091c48;
P_0c091c48: /* original 63c1, guest PC 0x0c091c48 */
if(!s->budget--) { s->failed_pc=0x0c091c48u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[12],2);
r[3]=tmp;
goto P_0c091c4a;
P_0c091c4a: /* original 6943, guest PC 0x0c091c4a */
if(!s->budget--) { s->failed_pc=0x0c091c4au; return 0; }
r[9]=r[4];
goto P_0c091c4c;
P_0c091c4c: /* original 793c, guest PC 0x0c091c4c */
if(!s->budget--) { s->failed_pc=0x0c091c4cu; return 0; }
r[9]+=0x0000003cu;
goto P_0c091c4e;
P_0c091c4e: /* original 2f31, guest PC 0x0c091c4e */
if(!s->budget--) { s->failed_pc=0x0c091c4eu; return 0; }
write(ram,r[15],r[3],2);
goto P_0c091c50;
P_0c091c50: /* original 6a43, guest PC 0x0c091c50 */
if(!s->budget--) { s->failed_pc=0x0c091c50u; return 0; }
r[10]=r[4];
goto P_0c091c52;
P_0c091c52: /* original d347, guest PC 0x0c091c52 */
if(!s->budget--) { s->failed_pc=0x0c091c52u; return 0; }
r[3]=read(ram,0x0c091d70u,4);
goto P_0c091c54;
P_0c091c54: /* original 430b, guest PC 0x0c091c54 */
if(!s->budget--) { s->failed_pc=0x0c091c54u; return 0; }
target=r[3];
r[16]=0x8c091c58u;
r[4]=read(ram,r[15]+20,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c091c58u) { target=s->pc; goto dispatch; }
goto P_0c091c58;
P_0c091c56: /* original 54f5, guest PC 0x0c091c56 */
if(!s->budget--) { s->failed_pc=0x0c091c56u; return 0; }
r[4]=read(ram,r[15]+20,4);
goto P_0c091c58;
P_0c091c58: /* original d246, guest PC 0x0c091c58 */
if(!s->budget--) { s->failed_pc=0x0c091c58u; return 0; }
r[2]=read(ram,0x0c091d74u,4);
goto P_0c091c5a;
P_0c091c5a: /* original 420b, guest PC 0x0c091c5a */
if(!s->budget--) { s->failed_pc=0x0c091c5au; return 0; }
target=r[2];
r[16]=0x8c091c5eu;
r[4]=0x00000000u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c091c5eu) { target=s->pc; goto dispatch; }
goto P_0c091c5e;
P_0c091c5c: /* original e400, guest PC 0x0c091c5c */
if(!s->budget--) { s->failed_pc=0x0c091c5cu; return 0; }
r[4]=0x00000000u;
goto P_0c091c5e;
P_0c091c5e: /* original 2bb8, guest PC 0x0c091c5e */
if(!s->budget--) { s->failed_pc=0x0c091c5eu; return 0; }
r[17]=(r[17]&~1u)|(((r[11]&r[11])==0)!=0);
goto P_0c091c60;
P_0c091c60: /* original 8b02, guest PC 0x0c091c60 */
if(!s->budget--) { s->failed_pc=0x0c091c60u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c091c68; }
goto P_0c091c62;
P_0c091c62: /* original d245, guest PC 0x0c091c62 */
if(!s->budget--) { s->failed_pc=0x0c091c62u; return 0; }
r[2]=read(ram,0x0c091d78u,4);
goto P_0c091c64;
P_0c091c64: /* original 420b, guest PC 0x0c091c64 */
if(!s->budget--) { s->failed_pc=0x0c091c64u; return 0; }
target=r[2];
r[16]=0x8c091c68u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c091c68u) { target=s->pc; goto dispatch; }
goto P_0c091c68;
P_0c091c66: /* original 0009, guest PC 0x0c091c66 */
if(!s->budget--) { s->failed_pc=0x0c091c66u; return 0; }
goto P_0c091c68;
P_0c091c68: /* original d344, guest PC 0x0c091c68 */
if(!s->budget--) { s->failed_pc=0x0c091c68u; return 0; }
r[3]=read(ram,0x0c091d7cu,4);
goto P_0c091c6a;
P_0c091c6a: /* original 430b, guest PC 0x0c091c6a */
if(!s->budget--) { s->failed_pc=0x0c091c6au; return 0; }
target=r[3];
r[16]=0x8c091c6eu;
r[4]=0x00000001u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c091c6eu) { target=s->pc; goto dispatch; }
goto P_0c091c6e;
P_0c091c6c: /* original e401, guest PC 0x0c091c6c */
if(!s->budget--) { s->failed_pc=0x0c091c6cu; return 0; }
r[4]=0x00000001u;
goto P_0c091c6e;
P_0c091c6e: /* original 64f1, guest PC 0x0c091c6e */
if(!s->budget--) { s->failed_pc=0x0c091c6eu; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[15],2);
r[4]=tmp;
goto P_0c091c70;
P_0c091c70: /* original d843, guest PC 0x0c091c70 */
if(!s->budget--) { s->failed_pc=0x0c091c70u; return 0; }
r[8]=read(ram,0x0c091d80u,4);
goto P_0c091c72;
P_0c091c72: /* original 480b, guest PC 0x0c091c72 */
if(!s->budget--) { s->failed_pc=0x0c091c72u; return 0; }
target=r[8];
r[16]=0x8c091c76u;
r[4]=r[4]&65535u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c091c76u) { target=s->pc; goto dispatch; }
goto P_0c091c76;
P_0c091c74: /* original 644d, guest PC 0x0c091c74 */
if(!s->budget--) { s->failed_pc=0x0c091c74u; return 0; }
r[4]=r[4]&65535u;
goto P_0c091c76;
P_0c091c76: /* original d33f, guest PC 0x0c091c76 */
if(!s->budget--) { s->failed_pc=0x0c091c76u; return 0; }
r[3]=read(ram,0x0c091d74u,4);
goto P_0c091c78;
P_0c091c78: /* original 6ec3, guest PC 0x0c091c78 */
if(!s->budget--) { s->failed_pc=0x0c091c78u; return 0; }
r[14]=r[12];
goto P_0c091c7a;
P_0c091c7a: /* original 7e02, guest PC 0x0c091c7a */
if(!s->budget--) { s->failed_pc=0x0c091c7au; return 0; }
r[14]+=0x00000002u;
goto P_0c091c7c;
P_0c091c7c: /* original 430b, guest PC 0x0c091c7c */
if(!s->budget--) { s->failed_pc=0x0c091c7cu; return 0; }
target=r[3];
r[16]=0x8c091c80u;
r[4]=0x00000000u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c091c80u) { target=s->pc; goto dispatch; }
goto P_0c091c80;
P_0c091c7e: /* original e400, guest PC 0x0c091c7e */
if(!s->budget--) { s->failed_pc=0x0c091c7eu; return 0; }
r[4]=0x00000000u;
goto P_0c091c80;
P_0c091c80: /* original e200, guest PC 0x0c091c80 */
if(!s->budget--) { s->failed_pc=0x0c091c80u; return 0; }
r[2]=0x00000000u;
goto P_0c091c82;
P_0c091c82: /* original 2f22, guest PC 0x0c091c82 */
if(!s->budget--) { s->failed_pc=0x0c091c82u; return 0; }
write(ram,r[15],r[2],4);
goto P_0c091c84;
P_0c091c84: /* original d33f, guest PC 0x0c091c84 */
if(!s->budget--) { s->failed_pc=0x0c091c84u; return 0; }
r[3]=read(ram,0x0c091d84u,4);
goto P_0c091c86;
P_0c091c86: /* original ff8d, guest PC 0x0c091c86 */
if(!s->budget--) { s->failed_pc=0x0c091c86u; return 0; }
fr[15]=0;
goto P_0c091c88;
P_0c091c88: /* original 1f35, guest PC 0x0c091c88 */
if(!s->budget--) { s->failed_pc=0x0c091c88u; return 0; }
write(ram,r[15]+20,r[3],4);
goto P_0c091c8a;
P_0c091c8a: /* original 60d1, guest PC 0x0c091c8a */
if(!s->budget--) { s->failed_pc=0x0c091c8au; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[13],2);
r[0]=tmp;
goto P_0c091c8c;
P_0c091c8c: /* original 2bb8, guest PC 0x0c091c8c */
if(!s->budget--) { s->failed_pc=0x0c091c8cu; return 0; }
r[17]=(r[17]&~1u)|(((r[11]&r[11])==0)!=0);
goto P_0c091c8e;
P_0c091c8e: /* original 81f4, guest PC 0x0c091c8e */
if(!s->budget--) { s->failed_pc=0x0c091c8eu; return 0; }
write(ram,r[15]+8,r[0],2);
goto P_0c091c90;
P_0c091c90: /* original 85d1, guest PC 0x0c091c90 */
if(!s->budget--) { s->failed_pc=0x0c091c90u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[13]+2,2);
goto P_0c091c92;
P_0c091c92: /* original 81fe, guest PC 0x0c091c92 */
if(!s->budget--) { s->failed_pc=0x0c091c92u; return 0; }
write(ram,r[15]+28,r[0],2);
goto P_0c091c94;
P_0c091c94: /* original 85d2, guest PC 0x0c091c94 */
if(!s->budget--) { s->failed_pc=0x0c091c94u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[13]+4,2);
goto P_0c091c96;
P_0c091c96: /* original 81f6, guest PC 0x0c091c96 */
if(!s->budget--) { s->failed_pc=0x0c091c96u; return 0; }
write(ram,r[15]+12,r[0],2);
goto P_0c091c98;
P_0c091c98: /* original 85d3, guest PC 0x0c091c98 */
if(!s->budget--) { s->failed_pc=0x0c091c98u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[13]+6,2);
goto P_0c091c9a;
P_0c091c9a: /* original 81f2, guest PC 0x0c091c9a */
if(!s->budget--) { s->failed_pc=0x0c091c9au; return 0; }
write(ram,r[15]+4,r[0],2);
goto P_0c091c9c;
P_0c091c9c: /* original 85d4, guest PC 0x0c091c9c */
if(!s->budget--) { s->failed_pc=0x0c091c9cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[13]+8,2);
goto P_0c091c9e;
P_0c091c9e: /* original 81f8, guest PC 0x0c091c9e */
if(!s->budget--) { s->failed_pc=0x0c091c9eu; return 0; }
write(ram,r[15]+16,r[0],2);
goto P_0c091ca0;
P_0c091ca0: /* original f4a9, guest PC 0x0c091ca0 */
if(!s->budget--) { s->failed_pc=0x0c091ca0u; return 0; }
vf3_matrix_load(s,ram,4,r[10]);
r[10]+=(r[18]&0x100000u)?8:4;
goto P_0c091ca2;
P_0c091ca2: /* original fd99, guest PC 0x0c091ca2 */
if(!s->budget--) { s->failed_pc=0x0c091ca2u; return 0; }
vf3_matrix_load(s,ram,13,r[9]);
r[9]+=(r[18]&0x100000u)?8:4;
goto P_0c091ca4;
P_0c091ca4: /* original f5a9, guest PC 0x0c091ca4 */
if(!s->budget--) { s->failed_pc=0x0c091ca4u; return 0; }
vf3_matrix_load(s,ram,5,r[10]);
r[10]+=(r[18]&0x100000u)?8:4;
goto P_0c091ca6;
P_0c091ca6: /* original f6a9, guest PC 0x0c091ca6 */
if(!s->budget--) { s->failed_pc=0x0c091ca6u; return 0; }
vf3_matrix_load(s,ram,6,r[10]);
r[10]+=(r[18]&0x100000u)?8:4;
goto P_0c091ca8;
P_0c091ca8: /* original 8f0d, guest PC 0x0c091ca8 */
if(!s->budget--) { s->failed_pc=0x0c091ca8u; return 0; }
cond=r[17]&1u;
vf3_matrix_load(s,ram,14,r[9]);
r[9]+=(r[18]&0x100000u)?8:4;
if(!cond) { goto P_0c091cc6; }
goto P_0c091cac;
P_0c091caa: /* original fe99, guest PC 0x0c091caa */
if(!s->budget--) { s->failed_pc=0x0c091caau; return 0; }
vf3_matrix_load(s,ram,14,r[9]);
r[9]+=(r[18]&0x100000u)?8:4;
goto P_0c091cac;
P_0c091cac: /* original 85f4, guest PC 0x0c091cac */
if(!s->budget--) { s->failed_pc=0x0c091cacu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+8,2);
goto P_0c091cae;
P_0c091cae: /* original 600b, guest PC 0x0c091cae */
if(!s->budget--) { s->failed_pc=0x0c091caeu; return 0; }
r[0]=0u-r[0];
goto P_0c091cb0;
P_0c091cb0: /* original 81f4, guest PC 0x0c091cb0 */
if(!s->budget--) { s->failed_pc=0x0c091cb0u; return 0; }
write(ram,r[15]+8,r[0],2);
goto P_0c091cb2;
P_0c091cb2: /* original 85f6, guest PC 0x0c091cb2 */
if(!s->budget--) { s->failed_pc=0x0c091cb2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+12,2);
goto P_0c091cb4;
P_0c091cb4: /* original 600b, guest PC 0x0c091cb4 */
if(!s->budget--) { s->failed_pc=0x0c091cb4u; return 0; }
r[0]=0u-r[0];
goto P_0c091cb6;
P_0c091cb6: /* original 81f6, guest PC 0x0c091cb6 */
if(!s->budget--) { s->failed_pc=0x0c091cb6u; return 0; }
write(ram,r[15]+12,r[0],2);
goto P_0c091cb8;
P_0c091cb8: /* original 85f2, guest PC 0x0c091cb8 */
if(!s->budget--) { s->failed_pc=0x0c091cb8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+4,2);
goto P_0c091cba;
P_0c091cba: /* original 600b, guest PC 0x0c091cba */
if(!s->budget--) { s->failed_pc=0x0c091cbau; return 0; }
r[0]=0u-r[0];
goto P_0c091cbc;
P_0c091cbc: /* original 81f2, guest PC 0x0c091cbc */
if(!s->budget--) { s->failed_pc=0x0c091cbcu; return 0; }
write(ram,r[15]+4,r[0],2);
goto P_0c091cbe;
P_0c091cbe: /* original 85f8, guest PC 0x0c091cbe */
if(!s->budget--) { s->failed_pc=0x0c091cbeu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+16,2);
goto P_0c091cc0;
P_0c091cc0: /* original 600b, guest PC 0x0c091cc0 */
if(!s->budget--) { s->failed_pc=0x0c091cc0u; return 0; }
r[0]=0u-r[0];
goto P_0c091cc2;
P_0c091cc2: /* original 81f8, guest PC 0x0c091cc2 */
if(!s->budget--) { s->failed_pc=0x0c091cc2u; return 0; }
write(ram,r[15]+16,r[0],2);
goto P_0c091cc4;
P_0c091cc4: /* original f64d, guest PC 0x0c091cc4 */
if(!s->budget--) { s->failed_pc=0x0c091cc4u; return 0; }
fr[6]^=0x80000000u;
goto P_0c091cc6;
P_0c091cc6: /* original 63f2, guest PC 0x0c091cc6 */
if(!s->budget--) { s->failed_pc=0x0c091cc6u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c091cc8;
P_0c091cc8: /* original 2338, guest PC 0x0c091cc8 */
if(!s->budget--) { s->failed_pc=0x0c091cc8u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c091cca;
P_0c091cca: /* original 8d03, guest PC 0x0c091cca */
if(!s->budget--) { s->failed_pc=0x0c091ccau; return 0; }
cond=r[17]&1u;
fr[6]^=0x80000000u;
if(cond) { goto P_0c091cd4; }
goto P_0c091cce;
P_0c091ccc: /* original f64d, guest PC 0x0c091ccc */
if(!s->budget--) { s->failed_pc=0x0c091cccu; return 0; }
fr[6]^=0x80000000u;
goto P_0c091cce;
P_0c091cce: /* original d32e, guest PC 0x0c091cce */
if(!s->budget--) { s->failed_pc=0x0c091cceu; return 0; }
r[3]=read(ram,0x0c091d88u,4);
goto P_0c091cd0;
P_0c091cd0: /* original 430b, guest PC 0x0c091cd0 */
if(!s->budget--) { s->failed_pc=0x0c091cd0u; return 0; }
target=r[3];
r[16]=0x8c091cd4u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c091cd4u) { target=s->pc; goto dispatch; }
goto P_0c091cd4;
P_0c091cd2: /* original 0009, guest PC 0x0c091cd2 */
if(!s->budget--) { s->failed_pc=0x0c091cd2u; return 0; }
goto P_0c091cd4;
P_0c091cd4: /* original 60e5, guest PC 0x0c091cd4 */
if(!s->budget--) { s->failed_pc=0x0c091cd4u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[14],2);
r[14]+=2;
r[0]=tmp;
goto P_0c091cd6;
P_0c091cd6: /* original 81fc, guest PC 0x0c091cd6 */
if(!s->budget--) { s->failed_pc=0x0c091cd6u; return 0; }
write(ram,r[15]+24,r[0],2);
goto P_0c091cd8;
P_0c091cd8: /* original d32c, guest PC 0x0c091cd8 */
if(!s->budget--) { s->failed_pc=0x0c091cd8u; return 0; }
r[3]=read(ram,0x0c091d8cu,4);
goto P_0c091cda;
P_0c091cda: /* original 85fe, guest PC 0x0c091cda */
if(!s->budget--) { s->failed_pc=0x0c091cdau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+28,2);
goto P_0c091cdc;
P_0c091cdc: /* original 430b, guest PC 0x0c091cdc */
if(!s->budget--) { s->failed_pc=0x0c091cdcu; return 0; }
target=r[3];
r[16]=0x8c091ce0u;
r[4]=r[0];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c091ce0u) { target=s->pc; goto dispatch; }
goto P_0c091ce0;
P_0c091cde: /* original 6403, guest PC 0x0c091cde */
if(!s->budget--) { s->failed_pc=0x0c091cdeu; return 0; }
r[4]=r[0];
goto P_0c091ce0;
P_0c091ce0: /* original d32b, guest PC 0x0c091ce0 */
if(!s->budget--) { s->failed_pc=0x0c091ce0u; return 0; }
r[3]=read(ram,0x0c091d90u,4);
goto P_0c091ce2;
P_0c091ce2: /* original 85f4, guest PC 0x0c091ce2 */
if(!s->budget--) { s->failed_pc=0x0c091ce2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+8,2);
goto P_0c091ce4;
P_0c091ce4: /* original 430b, guest PC 0x0c091ce4 */
if(!s->budget--) { s->failed_pc=0x0c091ce4u; return 0; }
target=r[3];
r[16]=0x8c091ce8u;
r[4]=r[0];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c091ce8u) { target=s->pc; goto dispatch; }
goto P_0c091ce8;
P_0c091ce6: /* original 6403, guest PC 0x0c091ce6 */
if(!s->budget--) { s->failed_pc=0x0c091ce6u; return 0; }
r[4]=r[0];
goto P_0c091ce8;
P_0c091ce8: /* original d32a, guest PC 0x0c091ce8 */
if(!s->budget--) { s->failed_pc=0x0c091ce8u; return 0; }
r[3]=read(ram,0x0c091d94u,4);
goto P_0c091cea;
P_0c091cea: /* original 85f6, guest PC 0x0c091cea */
if(!s->budget--) { s->failed_pc=0x0c091ceau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+12,2);
goto P_0c091cec;
P_0c091cec: /* original 430b, guest PC 0x0c091cec */
if(!s->budget--) { s->failed_pc=0x0c091cecu; return 0; }
target=r[3];
r[16]=0x8c091cf0u;
r[4]=r[0];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c091cf0u) { target=s->pc; goto dispatch; }
goto P_0c091cf0;
P_0c091cee: /* original 6403, guest PC 0x0c091cee */
if(!s->budget--) { s->failed_pc=0x0c091ceeu; return 0; }
r[4]=r[0];
goto P_0c091cf0;
P_0c091cf0: /* original 85fc, guest PC 0x0c091cf0 */
if(!s->budget--) { s->failed_pc=0x0c091cf0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+24,2);
goto P_0c091cf2;
P_0c091cf2: /* original 6403, guest PC 0x0c091cf2 */
if(!s->budget--) { s->failed_pc=0x0c091cf2u; return 0; }
r[4]=r[0];
goto P_0c091cf4;
P_0c091cf4: /* original 480b, guest PC 0x0c091cf4 */
if(!s->budget--) { s->failed_pc=0x0c091cf4u; return 0; }
target=r[8];
r[16]=0x8c091cf8u;
r[4]=r[4]&65535u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c091cf8u) { target=s->pc; goto dispatch; }
goto P_0c091cf8;
P_0c091cf6: /* original 644d, guest PC 0x0c091cf6 */
if(!s->budget--) { s->failed_pc=0x0c091cf6u; return 0; }
r[4]=r[4]&65535u;
goto P_0c091cf8;
P_0c091cf8: /* original 60e5, guest PC 0x0c091cf8 */
if(!s->budget--) { s->failed_pc=0x0c091cf8u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[14],2);
r[14]+=2;
r[0]=tmp;
goto P_0c091cfa;
P_0c091cfa: /* original 81f4, guest PC 0x0c091cfa */
if(!s->budget--) { s->failed_pc=0x0c091cfau; return 0; }
write(ram,r[15]+8,r[0],2);
goto P_0c091cfc;
P_0c091cfc: /* original d322, guest PC 0x0c091cfc */
if(!s->budget--) { s->failed_pc=0x0c091cfcu; return 0; }
r[3]=read(ram,0x0c091d88u,4);
goto P_0c091cfe;
P_0c091cfe: /* original f5fc, guest PC 0x0c091cfe */
if(!s->budget--) { s->failed_pc=0x0c091cfeu; return 0; }
vf3_matrix_move(s,5,15);
goto P_0c091d00;
P_0c091d00: /* original f6fc, guest PC 0x0c091d00 */
if(!s->budget--) { s->failed_pc=0x0c091d00u; return 0; }
vf3_matrix_move(s,6,15);
goto P_0c091d02;
P_0c091d02: /* original 430b, guest PC 0x0c091d02 */
if(!s->budget--) { s->failed_pc=0x0c091d02u; return 0; }
target=r[3];
r[16]=0x8c091d06u;
vf3_matrix_move(s,4,13);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c091d06u) { target=s->pc; goto dispatch; }
goto P_0c091d06;
P_0c091d04: /* original f4dc, guest PC 0x0c091d04 */
if(!s->budget--) { s->failed_pc=0x0c091d04u; return 0; }
vf3_matrix_move(s,4,13);
goto P_0c091d06;
P_0c091d06: /* original d323, guest PC 0x0c091d06 */
if(!s->budget--) { s->failed_pc=0x0c091d06u; return 0; }
r[3]=read(ram,0x0c091d94u,4);
goto P_0c091d08;
P_0c091d08: /* original 85f2, guest PC 0x0c091d08 */
if(!s->budget--) { s->failed_pc=0x0c091d08u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+4,2);
goto P_0c091d0a;
P_0c091d0a: /* original 430b, guest PC 0x0c091d0a */
if(!s->budget--) { s->failed_pc=0x0c091d0au; return 0; }
target=r[3];
r[16]=0x8c091d0eu;
r[4]=r[0];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c091d0eu) { target=s->pc; goto dispatch; }
goto P_0c091d0e;
P_0c091d0c: /* original 6403, guest PC 0x0c091d0c */
if(!s->budget--) { s->failed_pc=0x0c091d0cu; return 0; }
r[4]=r[0];
goto P_0c091d0e;
P_0c091d0e: /* original 85f4, guest PC 0x0c091d0e */
if(!s->budget--) { s->failed_pc=0x0c091d0eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+8,2);
goto P_0c091d10;
P_0c091d10: /* original 6403, guest PC 0x0c091d10 */
if(!s->budget--) { s->failed_pc=0x0c091d10u; return 0; }
r[4]=r[0];
goto P_0c091d12;
P_0c091d12: /* original 480b, guest PC 0x0c091d12 */
if(!s->budget--) { s->failed_pc=0x0c091d12u; return 0; }
target=r[8];
r[16]=0x8c091d16u;
r[4]=r[4]&65535u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c091d16u) { target=s->pc; goto dispatch; }
goto P_0c091d16;
P_0c091d14: /* original 644d, guest PC 0x0c091d14 */
if(!s->budget--) { s->failed_pc=0x0c091d14u; return 0; }
r[4]=r[4]&65535u;
goto P_0c091d16;
P_0c091d16: /* original 60e5, guest PC 0x0c091d16 */
if(!s->budget--) { s->failed_pc=0x0c091d16u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[14],2);
r[14]+=2;
r[0]=tmp;
goto P_0c091d18;
P_0c091d18: /* original 81f2, guest PC 0x0c091d18 */
if(!s->budget--) { s->failed_pc=0x0c091d18u; return 0; }
write(ram,r[15]+4,r[0],2);
goto P_0c091d1a;
P_0c091d1a: /* original d31b, guest PC 0x0c091d1a */
if(!s->budget--) { s->failed_pc=0x0c091d1au; return 0; }
r[3]=read(ram,0x0c091d88u,4);
goto P_0c091d1c;
P_0c091d1c: /* original f5fc, guest PC 0x0c091d1c */
if(!s->budget--) { s->failed_pc=0x0c091d1cu; return 0; }
vf3_matrix_move(s,5,15);
goto P_0c091d1e;
P_0c091d1e: /* original f6fc, guest PC 0x0c091d1e */
if(!s->budget--) { s->failed_pc=0x0c091d1eu; return 0; }
vf3_matrix_move(s,6,15);
goto P_0c091d20;
P_0c091d20: /* original 430b, guest PC 0x0c091d20 */
if(!s->budget--) { s->failed_pc=0x0c091d20u; return 0; }
target=r[3];
r[16]=0x8c091d24u;
vf3_matrix_move(s,4,14);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c091d24u) { target=s->pc; goto dispatch; }
goto P_0c091d24;
P_0c091d22: /* original f4ec, guest PC 0x0c091d22 */
if(!s->budget--) { s->failed_pc=0x0c091d22u; return 0; }
vf3_matrix_move(s,4,14);
goto P_0c091d24;
P_0c091d24: /* original d31b, guest PC 0x0c091d24 */
if(!s->budget--) { s->failed_pc=0x0c091d24u; return 0; }
r[3]=read(ram,0x0c091d94u,4);
goto P_0c091d26;
P_0c091d26: /* original 85f8, guest PC 0x0c091d26 */
if(!s->budget--) { s->failed_pc=0x0c091d26u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+16,2);
goto P_0c091d28;
P_0c091d28: /* original 430b, guest PC 0x0c091d28 */
if(!s->budget--) { s->failed_pc=0x0c091d28u; return 0; }
target=r[3];
r[16]=0x8c091d2cu;
r[4]=r[0];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c091d2cu) { target=s->pc; goto dispatch; }
goto P_0c091d2c;
P_0c091d2a: /* original 6403, guest PC 0x0c091d2a */
if(!s->budget--) { s->failed_pc=0x0c091d2au; return 0; }
r[4]=r[0];
goto P_0c091d2c;
P_0c091d2c: /* original 85f2, guest PC 0x0c091d2c */
if(!s->budget--) { s->failed_pc=0x0c091d2cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+4,2);
goto P_0c091d2e;
P_0c091d2e: /* original 6403, guest PC 0x0c091d2e */
if(!s->budget--) { s->failed_pc=0x0c091d2eu; return 0; }
r[4]=r[0];
goto P_0c091d30;
P_0c091d30: /* original 480b, guest PC 0x0c091d30 */
if(!s->budget--) { s->failed_pc=0x0c091d30u; return 0; }
target=r[8];
r[16]=0x8c091d34u;
r[4]=r[4]&65535u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c091d34u) { target=s->pc; goto dispatch; }
goto P_0c091d34;
P_0c091d32: /* original 644d, guest PC 0x0c091d32 */
if(!s->budget--) { s->failed_pc=0x0c091d32u; return 0; }
r[4]=r[4]&65535u;
goto P_0c091d34;
P_0c091d34: /* original 54f5, guest PC 0x0c091d34 */
if(!s->budget--) { s->failed_pc=0x0c091d34u; return 0; }
r[4]=read(ram,r[15]+20,4);
goto P_0c091d36;
P_0c091d36: /* original fbfd, guest PC 0x0c091d36 */
if(!s->budget--) { s->failed_pc=0x0c091d36u; return 0; }
vf3_matrix_swap(s);
goto P_0c091d38;
P_0c091d38: /* original 63f2, guest PC 0x0c091d38 */
if(!s->budget--) { s->failed_pc=0x0c091d38u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c091d3a;
P_0c091d3a: /* original e205, guest PC 0x0c091d3a */
if(!s->budget--) { s->failed_pc=0x0c091d3au; return 0; }
r[2]=0x00000005u;
goto P_0c091d3c;
P_0c091d3c: /* original 5442, guest PC 0x0c091d3c */
if(!s->budget--) { s->failed_pc=0x0c091d3cu; return 0; }
r[4]=read(ram,r[4]+8,4);
goto P_0c091d3e;
P_0c091d3e: /* original 7d0a, guest PC 0x0c091d3e */
if(!s->budget--) { s->failed_pc=0x0c091d3eu; return 0; }
r[13]+=0x0000000au;
goto P_0c091d40;
P_0c091d40: /* original 7301, guest PC 0x0c091d40 */
if(!s->budget--) { s->failed_pc=0x0c091d40u; return 0; }
r[3]+=0x00000001u;
goto P_0c091d42;
P_0c091d42: /* original 74c0, guest PC 0x0c091d42 */
if(!s->budget--) { s->failed_pc=0x0c091d42u; return 0; }
r[4]+=0xffffffc0u;
goto P_0c091d44;
P_0c091d44: /* original 3323, guest PC 0x0c091d44 */
if(!s->budget--) { s->failed_pc=0x0c091d44u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>=(int32_t)r[2])!=0);
goto P_0c091d46;
P_0c091d46: /* original f049, guest PC 0x0c091d46 */
if(!s->budget--) { s->failed_pc=0x0c091d46u; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c091d48;
P_0c091d48: /* original f149, guest PC 0x0c091d48 */
if(!s->budget--) { s->failed_pc=0x0c091d48u; return 0; }
vf3_matrix_load(s,ram,1,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c091d4a;
P_0c091d4a: /* original f249, guest PC 0x0c091d4a */
if(!s->budget--) { s->failed_pc=0x0c091d4au; return 0; }
vf3_matrix_load(s,ram,2,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c091d4c;
P_0c091d4c: /* original f349, guest PC 0x0c091d4c */
if(!s->budget--) { s->failed_pc=0x0c091d4cu; return 0; }
vf3_matrix_load(s,ram,3,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c091d4e;
P_0c091d4e: /* original f449, guest PC 0x0c091d4e */
if(!s->budget--) { s->failed_pc=0x0c091d4eu; return 0; }
vf3_matrix_load(s,ram,4,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c091d50;
P_0c091d50: /* original f549, guest PC 0x0c091d50 */
if(!s->budget--) { s->failed_pc=0x0c091d50u; return 0; }
vf3_matrix_load(s,ram,5,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c091d52;
P_0c091d52: /* original f649, guest PC 0x0c091d52 */
if(!s->budget--) { s->failed_pc=0x0c091d52u; return 0; }
vf3_matrix_load(s,ram,6,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c091d54;
P_0c091d54: /* original f749, guest PC 0x0c091d54 */
if(!s->budget--) { s->failed_pc=0x0c091d54u; return 0; }
vf3_matrix_load(s,ram,7,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c091d56;
P_0c091d56: /* original f849, guest PC 0x0c091d56 */
if(!s->budget--) { s->failed_pc=0x0c091d56u; return 0; }
vf3_matrix_load(s,ram,8,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c091d58;
P_0c091d58: /* original f949, guest PC 0x0c091d58 */
if(!s->budget--) { s->failed_pc=0x0c091d58u; return 0; }
vf3_matrix_load(s,ram,9,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c091d5a;
P_0c091d5a: /* original fa49, guest PC 0x0c091d5a */
if(!s->budget--) { s->failed_pc=0x0c091d5au; return 0; }
vf3_matrix_load(s,ram,10,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c091d5c;
P_0c091d5c: /* original fb49, guest PC 0x0c091d5c */
if(!s->budget--) { s->failed_pc=0x0c091d5cu; return 0; }
vf3_matrix_load(s,ram,11,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c091d5e;
P_0c091d5e: /* original fc49, guest PC 0x0c091d5e */
if(!s->budget--) { s->failed_pc=0x0c091d5eu; return 0; }
vf3_matrix_load(s,ram,12,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c091d60;
P_0c091d60: /* original fd49, guest PC 0x0c091d60 */
if(!s->budget--) { s->failed_pc=0x0c091d60u; return 0; }
vf3_matrix_load(s,ram,13,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c091d62;
P_0c091d62: /* original fe49, guest PC 0x0c091d62 */
if(!s->budget--) { s->failed_pc=0x0c091d62u; return 0; }
vf3_matrix_load(s,ram,14,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c091d64;
P_0c091d64: /* original ff49, guest PC 0x0c091d64 */
if(!s->budget--) { s->failed_pc=0x0c091d64u; return 0; }
vf3_matrix_load(s,ram,15,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c091d66;
P_0c091d66: /* original fbfd, guest PC 0x0c091d66 */
if(!s->budget--) { s->failed_pc=0x0c091d66u; return 0; }
vf3_matrix_swap(s);
goto P_0c091d68;
P_0c091d68: /* original a016, guest PC 0x0c091d68 */
if(!s->budget--) { s->failed_pc=0x0c091d68u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c091d98;
P_0c091d6a: /* original 2f32, guest PC 0x0c091d6a */
if(!s->budget--) { s->failed_pc=0x0c091d6au; return 0; }
write(ram,r[15],r[3],4);
return vf3_matrix_family(0x0c091d6cu,s,ram);
P_0c091d98: /* original 8d02, guest PC 0x0c091d98 */
if(!s->budget--) { s->failed_pc=0x0c091d98u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c091da0; }
goto P_0c091d9c;
P_0c091d9a: /* original 0009, guest PC 0x0c091d9a */
if(!s->budget--) { s->failed_pc=0x0c091d9au; return 0; }
goto P_0c091d9c;
P_0c091d9c: /* original af75, guest PC 0x0c091d9c */
if(!s->budget--) { s->failed_pc=0x0c091d9cu; return 0; }
goto P_0c091c8a;
P_0c091d9e: /* original 0009, guest PC 0x0c091d9e */
if(!s->budget--) { s->failed_pc=0x0c091d9eu; return 0; }
goto P_0c091da0;
P_0c091da0: /* original 7f20, guest PC 0x0c091da0 */
if(!s->budget--) { s->failed_pc=0x0c091da0u; return 0; }
r[15]+=0x00000020u;
goto P_0c091da2;
P_0c091da2: /* original d332, guest PC 0x0c091da2 */
if(!s->budget--) { s->failed_pc=0x0c091da2u; return 0; }
r[3]=read(ram,0x0c091e6cu,4);
goto P_0c091da4;
P_0c091da4: /* original 4f26, guest PC 0x0c091da4 */
if(!s->budget--) { s->failed_pc=0x0c091da4u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c091da6;
P_0c091da6: /* original e401, guest PC 0x0c091da6 */
if(!s->budget--) { s->failed_pc=0x0c091da6u; return 0; }
r[4]=0x00000001u;
goto P_0c091da8;
P_0c091da8: /* original fdf9, guest PC 0x0c091da8 */
if(!s->budget--) { s->failed_pc=0x0c091da8u; return 0; }
vf3_matrix_load(s,ram,13,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c091daa;
P_0c091daa: /* original fef9, guest PC 0x0c091daa */
if(!s->budget--) { s->failed_pc=0x0c091daau; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c091dac;
P_0c091dac: /* original fff9, guest PC 0x0c091dac */
if(!s->budget--) { s->failed_pc=0x0c091dacu; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c091dae;
P_0c091dae: /* original 68f6, guest PC 0x0c091dae */
if(!s->budget--) { s->failed_pc=0x0c091daeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c091db0;
P_0c091db0: /* original 69f6, guest PC 0x0c091db0 */
if(!s->budget--) { s->failed_pc=0x0c091db0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c091db2;
P_0c091db2: /* original 6af6, guest PC 0x0c091db2 */
if(!s->budget--) { s->failed_pc=0x0c091db2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c091db4;
P_0c091db4: /* original 6bf6, guest PC 0x0c091db4 */
if(!s->budget--) { s->failed_pc=0x0c091db4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c091db6;
P_0c091db6: /* original 6cf6, guest PC 0x0c091db6 */
if(!s->budget--) { s->failed_pc=0x0c091db6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c091db8;
P_0c091db8: /* original 6df6, guest PC 0x0c091db8 */
if(!s->budget--) { s->failed_pc=0x0c091db8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c091dba;
P_0c091dba: /* original 432b, guest PC 0x0c091dba */
if(!s->budget--) { s->failed_pc=0x0c091dbau; return 0; }
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
P_0c091dbc: /* original 6ef6, guest PC 0x0c091dbc */
if(!s->budget--) { s->failed_pc=0x0c091dbcu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c091dbeu,s,ram);
P_0c092268: /* original 2fe6, guest PC 0x0c092268 */
if(!s->budget--) { s->failed_pc=0x0c092268u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09226a;
P_0c09226a: /* original e030, guest PC 0x0c09226a */
if(!s->budget--) { s->failed_pc=0x0c09226au; return 0; }
r[0]=0x00000030u;
goto P_0c09226c;
P_0c09226c: /* original 6e43, guest PC 0x0c09226c */
if(!s->budget--) { s->failed_pc=0x0c09226cu; return 0; }
r[14]=r[4];
goto P_0c09226e;
P_0c09226e: /* original 03ed, guest PC 0x0c09226e */
if(!s->budget--) { s->failed_pc=0x0c09226eu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c092270;
P_0c092270: /* original 4f22, guest PC 0x0c092270 */
if(!s->budget--) { s->failed_pc=0x0c092270u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c092272;
P_0c092272: /* original 7301, guest PC 0x0c092272 */
if(!s->budget--) { s->failed_pc=0x0c092272u; return 0; }
r[3]+=0x00000001u;
goto P_0c092274;
P_0c092274: /* original 0e35, guest PC 0x0c092274 */
if(!s->budget--) { s->failed_pc=0x0c092274u; return 0; }
write(ram,r[14]+r[0],r[3],2);
goto P_0c092276;
P_0c092276: /* original d121, guest PC 0x0c092276 */
if(!s->budget--) { s->failed_pc=0x0c092276u; return 0; }
r[1]=read(ram,0x0c0922fcu,4);
goto P_0c092278;
P_0c092278: /* original d31f, guest PC 0x0c092278 */
if(!s->budget--) { s->failed_pc=0x0c092278u; return 0; }
r[3]=read(ram,0x0c0922f8u,4);
goto P_0c09227a;
P_0c09227a: /* original 6212, guest PC 0x0c09227a */
if(!s->budget--) { s->failed_pc=0x0c09227au; return 0; }
tmp=read(ram,r[1],4);
r[2]=tmp;
goto P_0c09227c;
P_0c09227c: /* original 2238, guest PC 0x0c09227c */
if(!s->budget--) { s->failed_pc=0x0c09227cu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c09227e;
P_0c09227e: /* original 8b06, guest PC 0x0c09227e */
if(!s->budget--) { s->failed_pc=0x0c09227eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09228e; }
goto P_0c092280;
P_0c092280: /* original b008, guest PC 0x0c092280 */
if(!s->budget--) { s->failed_pc=0x0c092280u; return 0; }
target=0x0c092294u; r[16]=0x8c092284u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c092284u) { target=s->pc; goto dispatch; }
goto P_0c092284;
P_0c092282: /* original 64e3, guest PC 0x0c092282 */
if(!s->budget--) { s->failed_pc=0x0c092282u; return 0; }
r[4]=r[14];
goto P_0c092284;
P_0c092284: /* original b11a, guest PC 0x0c092284 */
if(!s->budget--) { s->failed_pc=0x0c092284u; return 0; }
target=0x0c0924bcu; r[16]=0x8c092288u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c092288u) { target=s->pc; goto dispatch; }
goto P_0c092288;
P_0c092286: /* original 64e3, guest PC 0x0c092286 */
if(!s->budget--) { s->failed_pc=0x0c092286u; return 0; }
r[4]=r[14];
goto P_0c092288;
P_0c092288: /* original d31d, guest PC 0x0c092288 */
if(!s->budget--) { s->failed_pc=0x0c092288u; return 0; }
r[3]=read(ram,0x0c092300u,4);
goto P_0c09228a;
P_0c09228a: /* original 430b, guest PC 0x0c09228a */
if(!s->budget--) { s->failed_pc=0x0c09228au; return 0; }
target=r[3];
r[16]=0x8c09228eu;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09228eu) { target=s->pc; goto dispatch; }
goto P_0c09228e;
P_0c09228c: /* original 64e3, guest PC 0x0c09228c */
if(!s->budget--) { s->failed_pc=0x0c09228cu; return 0; }
r[4]=r[14];
goto P_0c09228e;
P_0c09228e: /* original 4f26, guest PC 0x0c09228e */
if(!s->budget--) { s->failed_pc=0x0c09228eu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c092290;
P_0c092290: /* original 000b, guest PC 0x0c092290 */
if(!s->budget--) { s->failed_pc=0x0c092290u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c092292: /* original 6ef6, guest PC 0x0c092292 */
if(!s->budget--) { s->failed_pc=0x0c092292u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c092294u,s,ram);
P_0c0a80b0: /* original 2fe6, guest PC 0x0c0a80b0 */
if(!s->budget--) { s->failed_pc=0x0c0a80b0u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a80b2;
P_0c0a80b2: /* original 2fd6, guest PC 0x0c0a80b2 */
if(!s->budget--) { s->failed_pc=0x0c0a80b2u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a80b4;
P_0c0a80b4: /* original 6d43, guest PC 0x0c0a80b4 */
if(!s->budget--) { s->failed_pc=0x0c0a80b4u; return 0; }
r[13]=r[4];
goto P_0c0a80b6;
P_0c0a80b6: /* original 2fc6, guest PC 0x0c0a80b6 */
if(!s->budget--) { s->failed_pc=0x0c0a80b6u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a80b8;
P_0c0a80b8: /* original 4f22, guest PC 0x0c0a80b8 */
if(!s->budget--) { s->failed_pc=0x0c0a80b8u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0a80ba;
P_0c0a80ba: /* original 62d2, guest PC 0x0c0a80ba */
if(!s->budget--) { s->failed_pc=0x0c0a80bau; return 0; }
tmp=read(ram,r[13],4);
r[2]=tmp;
goto P_0c0a80bc;
P_0c0a80bc: /* original d32d, guest PC 0x0c0a80bc */
if(!s->budget--) { s->failed_pc=0x0c0a80bcu; return 0; }
r[3]=read(ram,0x0c0a8174u,4);
goto P_0c0a80be;
P_0c0a80be: /* original 4f12, guest PC 0x0c0a80be */
if(!s->budget--) { s->failed_pc=0x0c0a80beu; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c0a80c0;
P_0c0a80c0: /* original 2238, guest PC 0x0c0a80c0 */
if(!s->budget--) { s->failed_pc=0x0c0a80c0u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0a80c2;
P_0c0a80c2: /* original 8901, guest PC 0x0c0a80c2 */
if(!s->budget--) { s->failed_pc=0x0c0a80c2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a80c8; }
goto P_0c0a80c4;
P_0c0a80c4: /* original b0fc, guest PC 0x0c0a80c4 */
if(!s->budget--) { s->failed_pc=0x0c0a80c4u; return 0; }
target=0x0c0a82c0u; r[16]=0x8c0a80c8u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a80c8u) { target=s->pc; goto dispatch; }
goto P_0c0a80c8;
P_0c0a80c6: /* original 0009, guest PC 0x0c0a80c6 */
if(!s->budget--) { s->failed_pc=0x0c0a80c6u; return 0; }
goto P_0c0a80c8;
P_0c0a80c8: /* original 62d2, guest PC 0x0c0a80c8 */
if(!s->budget--) { s->failed_pc=0x0c0a80c8u; return 0; }
tmp=read(ram,r[13],4);
r[2]=tmp;
goto P_0c0a80ca;
P_0c0a80ca: /* original d32c, guest PC 0x0c0a80ca */
if(!s->budget--) { s->failed_pc=0x0c0a80cau; return 0; }
r[3]=read(ram,0x0c0a817cu,4);
goto P_0c0a80cc;
P_0c0a80cc: /* original dc2a, guest PC 0x0c0a80cc */
if(!s->budget--) { s->failed_pc=0x0c0a80ccu; return 0; }
r[12]=read(ram,0x0c0a8178u,4);
goto P_0c0a80ce;
P_0c0a80ce: /* original 2238, guest PC 0x0c0a80ce */
if(!s->budget--) { s->failed_pc=0x0c0a80ceu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0a80d0;
P_0c0a80d0: /* original 892d, guest PC 0x0c0a80d0 */
if(!s->budget--) { s->failed_pc=0x0c0a80d0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a812e; }
goto P_0c0a80d2;
P_0c0a80d2: /* original 85db, guest PC 0x0c0a80d2 */
if(!s->budget--) { s->failed_pc=0x0c0a80d2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[13]+22,2);
goto P_0c0a80d4;
P_0c0a80d4: /* original ee34, guest PC 0x0c0a80d4 */
if(!s->budget--) { s->failed_pc=0x0c0a80d4u; return 0; }
r[14]=0x00000034u;
goto P_0c0a80d6;
P_0c0a80d6: /* original 62d3, guest PC 0x0c0a80d6 */
if(!s->budget--) { s->failed_pc=0x0c0a80d6u; return 0; }
r[2]=r[13];
goto P_0c0a80d8;
P_0c0a80d8: /* original d129, guest PC 0x0c0a80d8 */
if(!s->budget--) { s->failed_pc=0x0c0a80d8u; return 0; }
r[1]=read(ram,0x0c0a8180u,4);
goto P_0c0a80da;
P_0c0a80da: /* original 20ef, guest PC 0x0c0a80da */
if(!s->budget--) { s->failed_pc=0x0c0a80dau; return 0; }
r[19]=(uint32_t)((int32_t)(int16_t)r[0]*(int32_t)(int16_t)r[14]);
goto P_0c0a80dc;
P_0c0a80dc: /* original 721c, guest PC 0x0c0a80dc */
if(!s->budget--) { s->failed_pc=0x0c0a80dcu; return 0; }
r[2]+=0x0000001cu;
goto P_0c0a80de;
P_0c0a80de: /* original 0e1a, guest PC 0x0c0a80de */
if(!s->budget--) { s->failed_pc=0x0c0a80deu; return 0; }
r[14]=r[19];
goto P_0c0a80e0;
P_0c0a80e0: /* original 6eef, guest PC 0x0c0a80e0 */
if(!s->budget--) { s->failed_pc=0x0c0a80e0u; return 0; }
r[14]=(uint32_t)(int32_t)(int16_t)r[14];
goto P_0c0a80e2;
P_0c0a80e2: /* original 3e2c, guest PC 0x0c0a80e2 */
if(!s->budget--) { s->failed_pc=0x0c0a80e2u; return 0; }
r[14]+=r[2];
goto P_0c0a80e4;
P_0c0a80e4: /* original 410b, guest PC 0x0c0a80e4 */
if(!s->budget--) { s->failed_pc=0x0c0a80e4u; return 0; }
target=r[1];
r[16]=0x8c0a80e8u;
r[4]=read(ram,r[14]+12,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a80e8u) { target=s->pc; goto dispatch; }
goto P_0c0a80e8;
P_0c0a80e6: /* original 54e3, guest PC 0x0c0a80e6 */
if(!s->budget--) { s->failed_pc=0x0c0a80e6u; return 0; }
r[4]=read(ram,r[14]+12,4);
goto P_0c0a80e8;
P_0c0a80e8: /* original 8801, guest PC 0x0c0a80e8 */
if(!s->budget--) { s->failed_pc=0x0c0a80e8u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c0a80ea;
P_0c0a80ea: /* original 8d0b, guest PC 0x0c0a80ea */
if(!s->budget--) { s->failed_pc=0x0c0a80eau; return 0; }
cond=r[17]&1u;
r[4]=r[0];
if(cond) { goto P_0c0a8104; }
goto P_0c0a80ee;
P_0c0a80ec: /* original 6403, guest PC 0x0c0a80ec */
if(!s->budget--) { s->failed_pc=0x0c0a80ecu; return 0; }
r[4]=r[0];
goto P_0c0a80ee;
P_0c0a80ee: /* original 2448, guest PC 0x0c0a80ee */
if(!s->budget--) { s->failed_pc=0x0c0a80eeu; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c0a80f0;
P_0c0a80f0: /* original 8908, guest PC 0x0c0a80f0 */
if(!s->budget--) { s->failed_pc=0x0c0a80f0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a8104; }
goto P_0c0a80f2;
P_0c0a80f2: /* original 6043, guest PC 0x0c0a80f2 */
if(!s->budget--) { s->failed_pc=0x0c0a80f2u; return 0; }
r[0]=r[4];
goto P_0c0a80f4;
P_0c0a80f4: /* original 8805, guest PC 0x0c0a80f4 */
if(!s->budget--) { s->failed_pc=0x0c0a80f4u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000005u)!=0);
goto P_0c0a80f6;
P_0c0a80f6: /* original 8905, guest PC 0x0c0a80f6 */
if(!s->budget--) { s->failed_pc=0x0c0a80f6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a8104; }
goto P_0c0a80f8;
P_0c0a80f8: /* original 6043, guest PC 0x0c0a80f8 */
if(!s->budget--) { s->failed_pc=0x0c0a80f8u; return 0; }
r[0]=r[4];
goto P_0c0a80fa;
P_0c0a80fa: /* original 8802, guest PC 0x0c0a80fa */
if(!s->budget--) { s->failed_pc=0x0c0a80fau; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c0a80fc;
P_0c0a80fc: /* original 8971, guest PC 0x0c0a80fc */
if(!s->budget--) { s->failed_pc=0x0c0a80fcu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a81e2; }
goto P_0c0a80fe;
P_0c0a80fe: /* original e574, guest PC 0x0c0a80fe */
if(!s->budget--) { s->failed_pc=0x0c0a80feu; return 0; }
r[5]=0x00000074u;
goto P_0c0a8100;
P_0c0a8100: /* original 4c0b, guest PC 0x0c0a8100 */
if(!s->budget--) { s->failed_pc=0x0c0a8100u; return 0; }
target=r[12];
r[16]=0x8c0a8104u;
r[4]=0x00000001u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a8104u) { target=s->pc; goto dispatch; }
goto P_0c0a8104;
P_0c0a8102: /* original e401, guest PC 0x0c0a8102 */
if(!s->budget--) { s->failed_pc=0x0c0a8102u; return 0; }
r[4]=0x00000001u;
goto P_0c0a8104;
P_0c0a8104: /* original d21f, guest PC 0x0c0a8104 */
if(!s->budget--) { s->failed_pc=0x0c0a8104u; return 0; }
r[2]=read(ram,0x0c0a8184u,4);
goto P_0c0a8106;
P_0c0a8106: /* original 420b, guest PC 0x0c0a8106 */
if(!s->budget--) { s->failed_pc=0x0c0a8106u; return 0; }
target=r[2];
r[16]=0x8c0a810au;
r[4]=read(ram,r[14]+12,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a810au) { target=s->pc; goto dispatch; }
goto P_0c0a810a;
P_0c0a8108: /* original 54e3, guest PC 0x0c0a8108 */
if(!s->budget--) { s->failed_pc=0x0c0a8108u; return 0; }
r[4]=read(ram,r[14]+12,4);
goto P_0c0a810a;
P_0c0a810a: /* original 63e2, guest PC 0x0c0a810a */
if(!s->budget--) { s->failed_pc=0x0c0a810au; return 0; }
tmp=read(ram,r[14],4);
r[3]=tmp;
goto P_0c0a810c;
P_0c0a810c: /* original 2338, guest PC 0x0c0a810c */
if(!s->budget--) { s->failed_pc=0x0c0a810cu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0a810e;
P_0c0a810e: /* original 8902, guest PC 0x0c0a810e */
if(!s->budget--) { s->failed_pc=0x0c0a810eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a8116; }
goto P_0c0a8110;
P_0c0a8110: /* original 52e2, guest PC 0x0c0a8110 */
if(!s->budget--) { s->failed_pc=0x0c0a8110u; return 0; }
r[2]=read(ram,r[14]+8,4);
goto P_0c0a8112;
P_0c0a8112: /* original 63e2, guest PC 0x0c0a8112 */
if(!s->budget--) { s->failed_pc=0x0c0a8112u; return 0; }
tmp=read(ram,r[14],4);
r[3]=tmp;
goto P_0c0a8114;
P_0c0a8114: /* original 2322, guest PC 0x0c0a8114 */
if(!s->budget--) { s->failed_pc=0x0c0a8114u; return 0; }
write(ram,r[3],r[2],4);
goto P_0c0a8116;
P_0c0a8116: /* original 51e5, guest PC 0x0c0a8116 */
if(!s->budget--) { s->failed_pc=0x0c0a8116u; return 0; }
r[1]=read(ram,r[14]+20,4);
goto P_0c0a8118;
P_0c0a8118: /* original 2118, guest PC 0x0c0a8118 */
if(!s->budget--) { s->failed_pc=0x0c0a8118u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[1])==0)!=0);
goto P_0c0a811a;
P_0c0a811a: /* original 8904, guest PC 0x0c0a811a */
if(!s->budget--) { s->failed_pc=0x0c0a811au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a8126; }
goto P_0c0a811c;
P_0c0a811c: /* original 53e5, guest PC 0x0c0a811c */
if(!s->budget--) { s->failed_pc=0x0c0a811cu; return 0; }
r[3]=read(ram,r[14]+20,4);
goto P_0c0a811e;
P_0c0a811e: /* original e500, guest PC 0x0c0a811e */
if(!s->budget--) { s->failed_pc=0x0c0a811eu; return 0; }
r[5]=0x00000000u;
goto P_0c0a8120;
P_0c0a8120: /* original 430b, guest PC 0x0c0a8120 */
if(!s->budget--) { s->failed_pc=0x0c0a8120u; return 0; }
target=r[3];
r[16]=0x8c0a8124u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a8124u) { target=s->pc; goto dispatch; }
goto P_0c0a8124;
P_0c0a8122: /* original 64e3, guest PC 0x0c0a8122 */
if(!s->budget--) { s->failed_pc=0x0c0a8122u; return 0; }
r[4]=r[14];
goto P_0c0a8124;
P_0c0a8124: /* original 2008, guest PC 0x0c0a8124 */
if(!s->budget--) { s->failed_pc=0x0c0a8124u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c0a8126;
P_0c0a8126: /* original 62d2, guest PC 0x0c0a8126 */
if(!s->budget--) { s->failed_pc=0x0c0a8126u; return 0; }
tmp=read(ram,r[13],4);
r[2]=tmp;
goto P_0c0a8128;
P_0c0a8128: /* original d317, guest PC 0x0c0a8128 */
if(!s->budget--) { s->failed_pc=0x0c0a8128u; return 0; }
r[3]=read(ram,0x0c0a8188u,4);
goto P_0c0a812a;
P_0c0a812a: /* original 2239, guest PC 0x0c0a812a */
if(!s->budget--) { s->failed_pc=0x0c0a812au; return 0; }
r[2]&=r[3];
goto P_0c0a812c;
P_0c0a812c: /* original 2d22, guest PC 0x0c0a812c */
if(!s->budget--) { s->failed_pc=0x0c0a812cu; return 0; }
write(ram,r[13],r[2],4);
goto P_0c0a812e;
P_0c0a812e: /* original 85db, guest PC 0x0c0a812e */
if(!s->budget--) { s->failed_pc=0x0c0a812eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[13]+22,2);
goto P_0c0a8130;
P_0c0a8130: /* original 6303, guest PC 0x0c0a8130 */
if(!s->budget--) { s->failed_pc=0x0c0a8130u; return 0; }
r[3]=r[0];
goto P_0c0a8132;
P_0c0a8132: /* original 85dd, guest PC 0x0c0a8132 */
if(!s->budget--) { s->failed_pc=0x0c0a8132u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[13]+26,2);
goto P_0c0a8134;
P_0c0a8134: /* original 3300, guest PC 0x0c0a8134 */
if(!s->budget--) { s->failed_pc=0x0c0a8134u; return 0; }
r[17]=(r[17]&~1u)|((r[3]==r[0])!=0);
goto P_0c0a8136;
P_0c0a8136: /* original 8954, guest PC 0x0c0a8136 */
if(!s->budget--) { s->failed_pc=0x0c0a8136u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a81e2; }
goto P_0c0a8138;
P_0c0a8138: /* original 85db, guest PC 0x0c0a8138 */
if(!s->budget--) { s->failed_pc=0x0c0a8138u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[13]+22,2);
goto P_0c0a813a;
P_0c0a813a: /* original ee34, guest PC 0x0c0a813a */
if(!s->budget--) { s->failed_pc=0x0c0a813au; return 0; }
r[14]=0x00000034u;
goto P_0c0a813c;
P_0c0a813c: /* original 63d3, guest PC 0x0c0a813c */
if(!s->budget--) { s->failed_pc=0x0c0a813cu; return 0; }
r[3]=r[13];
goto P_0c0a813e;
P_0c0a813e: /* original 731c, guest PC 0x0c0a813e */
if(!s->budget--) { s->failed_pc=0x0c0a813eu; return 0; }
r[3]+=0x0000001cu;
goto P_0c0a8140;
P_0c0a8140: /* original 7001, guest PC 0x0c0a8140 */
if(!s->budget--) { s->failed_pc=0x0c0a8140u; return 0; }
r[0]+=0x00000001u;
goto P_0c0a8142;
P_0c0a8142: /* original c91f, guest PC 0x0c0a8142 */
if(!s->budget--) { s->failed_pc=0x0c0a8142u; return 0; }
r[0]&=31u;
goto P_0c0a8144;
P_0c0a8144: /* original 81db, guest PC 0x0c0a8144 */
if(!s->budget--) { s->failed_pc=0x0c0a8144u; return 0; }
write(ram,r[13]+22,r[0],2);
goto P_0c0a8146;
P_0c0a8146: /* original 85db, guest PC 0x0c0a8146 */
if(!s->budget--) { s->failed_pc=0x0c0a8146u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[13]+22,2);
goto P_0c0a8148;
P_0c0a8148: /* original 20ef, guest PC 0x0c0a8148 */
if(!s->budget--) { s->failed_pc=0x0c0a8148u; return 0; }
r[19]=(uint32_t)((int32_t)(int16_t)r[0]*(int32_t)(int16_t)r[14]);
goto P_0c0a814a;
P_0c0a814a: /* original e030, guest PC 0x0c0a814a */
if(!s->budget--) { s->failed_pc=0x0c0a814au; return 0; }
r[0]=0x00000030u;
goto P_0c0a814c;
P_0c0a814c: /* original 0e1a, guest PC 0x0c0a814c */
if(!s->budget--) { s->failed_pc=0x0c0a814cu; return 0; }
r[14]=r[19];
goto P_0c0a814e;
P_0c0a814e: /* original 6eef, guest PC 0x0c0a814e */
if(!s->budget--) { s->failed_pc=0x0c0a814eu; return 0; }
r[14]=(uint32_t)(int32_t)(int16_t)r[14];
goto P_0c0a8150;
P_0c0a8150: /* original 3e3c, guest PC 0x0c0a8150 */
if(!s->budget--) { s->failed_pc=0x0c0a8150u; return 0; }
r[14]+=r[3];
goto P_0c0a8152;
P_0c0a8152: /* original 55e1, guest PC 0x0c0a8152 */
if(!s->budget--) { s->failed_pc=0x0c0a8152u; return 0; }
r[5]=read(ram,r[14]+4,4);
goto P_0c0a8154;
P_0c0a8154: /* original beff, guest PC 0x0c0a8154 */
if(!s->budget--) { s->failed_pc=0x0c0a8154u; return 0; }
target=0x0c0a7f56u; r[16]=0x8c0a8158u;
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a8158u) { target=s->pc; goto dispatch; }
goto P_0c0a8158;
P_0c0a8156: /* original 04ed, guest PC 0x0c0a8156 */
if(!s->budget--) { s->failed_pc=0x0c0a8156u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0a8158;
P_0c0a8158: /* original 2008, guest PC 0x0c0a8158 */
if(!s->budget--) { s->failed_pc=0x0c0a8158u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c0a815a;
P_0c0a815a: /* original 8917, guest PC 0x0c0a815a */
if(!s->budget--) { s->failed_pc=0x0c0a815au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a818c; }
goto P_0c0a815c;
P_0c0a815c: /* original 53e5, guest PC 0x0c0a815c */
if(!s->budget--) { s->failed_pc=0x0c0a815cu; return 0; }
r[3]=read(ram,r[14]+20,4);
goto P_0c0a815e;
P_0c0a815e: /* original 2338, guest PC 0x0c0a815e */
if(!s->budget--) { s->failed_pc=0x0c0a815eu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0a8160;
P_0c0a8160: /* original 8904, guest PC 0x0c0a8160 */
if(!s->budget--) { s->failed_pc=0x0c0a8160u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a816c; }
goto P_0c0a8162;
P_0c0a8162: /* original 53e5, guest PC 0x0c0a8162 */
if(!s->budget--) { s->failed_pc=0x0c0a8162u; return 0; }
r[3]=read(ram,r[14]+20,4);
goto P_0c0a8164;
P_0c0a8164: /* original e500, guest PC 0x0c0a8164 */
if(!s->budget--) { s->failed_pc=0x0c0a8164u; return 0; }
r[5]=0x00000000u;
goto P_0c0a8166;
P_0c0a8166: /* original 430b, guest PC 0x0c0a8166 */
if(!s->budget--) { s->failed_pc=0x0c0a8166u; return 0; }
target=r[3];
r[16]=0x8c0a816au;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a816au) { target=s->pc; goto dispatch; }
goto P_0c0a816a;
P_0c0a8168: /* original 64e3, guest PC 0x0c0a8168 */
if(!s->budget--) { s->failed_pc=0x0c0a8168u; return 0; }
r[4]=r[14];
goto P_0c0a816a;
P_0c0a816a: /* original 2008, guest PC 0x0c0a816a */
if(!s->budget--) { s->failed_pc=0x0c0a816au; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c0a816c;
P_0c0a816c: /* original 62d2, guest PC 0x0c0a816c */
if(!s->budget--) { s->failed_pc=0x0c0a816cu; return 0; }
tmp=read(ram,r[13],4);
r[2]=tmp;
goto P_0c0a816e;
P_0c0a816e: /* original d306, guest PC 0x0c0a816e */
if(!s->budget--) { s->failed_pc=0x0c0a816eu; return 0; }
r[3]=read(ram,0x0c0a8188u,4);
goto P_0c0a8170;
P_0c0a8170: /* original a030, guest PC 0x0c0a8170 */
if(!s->budget--) { s->failed_pc=0x0c0a8170u; return 0; }
r[2]&=r[3];
goto P_0c0a81d4;
P_0c0a8172: /* original 2239, guest PC 0x0c0a8172 */
if(!s->budget--) { s->failed_pc=0x0c0a8172u; return 0; }
r[2]&=r[3];
return vf3_matrix_family(0x0c0a8174u,s,ram);
P_0c0a818c: /* original d345, guest PC 0x0c0a818c */
if(!s->budget--) { s->failed_pc=0x0c0a818cu; return 0; }
r[3]=read(ram,0x0c0a82a4u,4);
goto P_0c0a818e;
P_0c0a818e: /* original e500, guest PC 0x0c0a818e */
if(!s->budget--) { s->failed_pc=0x0c0a818eu; return 0; }
r[5]=0x00000000u;
goto P_0c0a8190;
P_0c0a8190: /* original 430b, guest PC 0x0c0a8190 */
if(!s->budget--) { s->failed_pc=0x0c0a8190u; return 0; }
target=r[3];
r[16]=0x8c0a8194u;
r[4]=read(ram,r[14]+16,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a8194u) { target=s->pc; goto dispatch; }
goto P_0c0a8194;
P_0c0a8192: /* original 54e4, guest PC 0x0c0a8192 */
if(!s->budget--) { s->failed_pc=0x0c0a8192u; return 0; }
r[4]=read(ram,r[14]+16,4);
goto P_0c0a8194;
P_0c0a8194: /* original 6203, guest PC 0x0c0a8194 */
if(!s->budget--) { s->failed_pc=0x0c0a8194u; return 0; }
r[2]=r[0];
goto P_0c0a8196;
P_0c0a8196: /* original 2228, guest PC 0x0c0a8196 */
if(!s->budget--) { s->failed_pc=0x0c0a8196u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c0a8198;
P_0c0a8198: /* original 8d20, guest PC 0x0c0a8198 */
if(!s->budget--) { s->failed_pc=0x0c0a8198u; return 0; }
cond=r[17]&1u;
write(ram,r[14]+12,r[0],4);
if(cond) { goto P_0c0a81dc; }
goto P_0c0a819c;
P_0c0a819a: /* original 1e03, guest PC 0x0c0a819a */
if(!s->budget--) { s->failed_pc=0x0c0a819au; return 0; }
write(ram,r[14]+12,r[0],4);
goto P_0c0a819c;
P_0c0a819c: /* original d342, guest PC 0x0c0a819c */
if(!s->budget--) { s->failed_pc=0x0c0a819cu; return 0; }
r[3]=read(ram,0x0c0a82a8u,4);
goto P_0c0a819e;
P_0c0a819e: /* original 65e3, guest PC 0x0c0a819e */
if(!s->budget--) { s->failed_pc=0x0c0a819eu; return 0; }
r[5]=r[14];
goto P_0c0a81a0;
P_0c0a81a0: /* original 7508, guest PC 0x0c0a81a0 */
if(!s->budget--) { s->failed_pc=0x0c0a81a0u; return 0; }
r[5]+=0x00000008u;
goto P_0c0a81a2;
P_0c0a81a2: /* original 430b, guest PC 0x0c0a81a2 */
if(!s->budget--) { s->failed_pc=0x0c0a81a2u; return 0; }
target=r[3];
r[16]=0x8c0a81a6u;
r[4]=read(ram,r[14]+12,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a81a6u) { target=s->pc; goto dispatch; }
goto P_0c0a81a6;
P_0c0a81a4: /* original 54e3, guest PC 0x0c0a81a4 */
if(!s->budget--) { s->failed_pc=0x0c0a81a4u; return 0; }
r[4]=read(ram,r[14]+12,4);
goto P_0c0a81a6;
P_0c0a81a6: /* original 52e2, guest PC 0x0c0a81a6 */
if(!s->budget--) { s->failed_pc=0x0c0a81a6u; return 0; }
r[2]=read(ram,r[14]+8,4);
goto P_0c0a81a8;
P_0c0a81a8: /* original 9378, guest PC 0x0c0a81a8 */
if(!s->budget--) { s->failed_pc=0x0c0a81a8u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a829cu,2);
goto P_0c0a81aa;
P_0c0a81aa: /* original 9178, guest PC 0x0c0a81aa */
if(!s->budget--) { s->failed_pc=0x0c0a81aau; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a829eu,2);
goto P_0c0a81ac;
P_0c0a81ac: /* original 323c, guest PC 0x0c0a81ac */
if(!s->budget--) { s->failed_pc=0x0c0a81acu; return 0; }
r[2]+=r[3];
goto P_0c0a81ae;
P_0c0a81ae: /* original 2219, guest PC 0x0c0a81ae */
if(!s->budget--) { s->failed_pc=0x0c0a81aeu; return 0; }
r[2]&=r[1];
goto P_0c0a81b0;
P_0c0a81b0: /* original 6523, guest PC 0x0c0a81b0 */
if(!s->budget--) { s->failed_pc=0x0c0a81b0u; return 0; }
r[5]=r[2];
goto P_0c0a81b2;
P_0c0a81b2: /* original 4519, guest PC 0x0c0a81b2 */
if(!s->budget--) { s->failed_pc=0x0c0a81b2u; return 0; }
r[5]>>=8;
goto P_0c0a81b4;
P_0c0a81b4: /* original 1e22, guest PC 0x0c0a81b4 */
if(!s->budget--) { s->failed_pc=0x0c0a81b4u; return 0; }
write(ram,r[14]+8,r[2],4);
goto P_0c0a81b6;
P_0c0a81b6: /* original 4509, guest PC 0x0c0a81b6 */
if(!s->budget--) { s->failed_pc=0x0c0a81b6u; return 0; }
r[5]>>=2;
goto P_0c0a81b8;
P_0c0a81b8: /* original d23c, guest PC 0x0c0a81b8 */
if(!s->budget--) { s->failed_pc=0x0c0a81b8u; return 0; }
r[2]=read(ram,0x0c0a82acu,4);
goto P_0c0a81ba;
P_0c0a81ba: /* original 4501, guest PC 0x0c0a81ba */
if(!s->budget--) { s->failed_pc=0x0c0a81bau; return 0; }
r[17]=(r[17]&~1u)|((r[5]&1)!=0);
r[5]>>=1;
goto P_0c0a81bc;
P_0c0a81bc: /* original 56e1, guest PC 0x0c0a81bc */
if(!s->budget--) { s->failed_pc=0x0c0a81bcu; return 0; }
r[6]=read(ram,r[14]+4,4);
goto P_0c0a81be;
P_0c0a81be: /* original 420b, guest PC 0x0c0a81be */
if(!s->budget--) { s->failed_pc=0x0c0a81beu; return 0; }
target=r[2];
r[16]=0x8c0a81c2u;
r[4]=read(ram,r[14]+12,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a81c2u) { target=s->pc; goto dispatch; }
goto P_0c0a81c2;
P_0c0a81c0: /* original 54e3, guest PC 0x0c0a81c0 */
if(!s->budget--) { s->failed_pc=0x0c0a81c0u; return 0; }
r[4]=read(ram,r[14]+12,4);
goto P_0c0a81c2;
P_0c0a81c2: /* original 6403, guest PC 0x0c0a81c2 */
if(!s->budget--) { s->failed_pc=0x0c0a81c2u; return 0; }
r[4]=r[0];
goto P_0c0a81c4;
P_0c0a81c4: /* original 4415, guest PC 0x0c0a81c4 */
if(!s->budget--) { s->failed_pc=0x0c0a81c4u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>0)!=0);
goto P_0c0a81c6;
P_0c0a81c6: /* original 8902, guest PC 0x0c0a81c6 */
if(!s->budget--) { s->failed_pc=0x0c0a81c6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a81ce; }
goto P_0c0a81c8;
P_0c0a81c8: /* original e576, guest PC 0x0c0a81c8 */
if(!s->budget--) { s->failed_pc=0x0c0a81c8u; return 0; }
r[5]=0x00000076u;
goto P_0c0a81ca;
P_0c0a81ca: /* original 4c0b, guest PC 0x0c0a81ca */
if(!s->budget--) { s->failed_pc=0x0c0a81cau; return 0; }
target=r[12];
r[16]=0x8c0a81ceu;
r[4]=0x00000001u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a81ceu) { target=s->pc; goto dispatch; }
goto P_0c0a81ce;
P_0c0a81cc: /* original e401, guest PC 0x0c0a81cc */
if(!s->budget--) { s->failed_pc=0x0c0a81ccu; return 0; }
r[4]=0x00000001u;
goto P_0c0a81ce;
P_0c0a81ce: /* original 62d2, guest PC 0x0c0a81ce */
if(!s->budget--) { s->failed_pc=0x0c0a81ceu; return 0; }
tmp=read(ram,r[13],4);
r[2]=tmp;
goto P_0c0a81d0;
P_0c0a81d0: /* original d337, guest PC 0x0c0a81d0 */
if(!s->budget--) { s->failed_pc=0x0c0a81d0u; return 0; }
r[3]=read(ram,0x0c0a82b0u,4);
goto P_0c0a81d2;
P_0c0a81d2: /* original 223b, guest PC 0x0c0a81d2 */
if(!s->budget--) { s->failed_pc=0x0c0a81d2u; return 0; }
r[2]|=r[3];
goto P_0c0a81d4;
P_0c0a81d4: /* original e000, guest PC 0x0c0a81d4 */
if(!s->budget--) { s->failed_pc=0x0c0a81d4u; return 0; }
r[0]=0x00000000u;
goto P_0c0a81d6;
P_0c0a81d6: /* original 2d22, guest PC 0x0c0a81d6 */
if(!s->budget--) { s->failed_pc=0x0c0a81d6u; return 0; }
write(ram,r[13],r[2],4);
goto P_0c0a81d8;
P_0c0a81d8: /* original a003, guest PC 0x0c0a81d8 */
if(!s->budget--) { s->failed_pc=0x0c0a81d8u; return 0; }
write(ram,r[13]+20,r[0],2);
goto P_0c0a81e2;
P_0c0a81da: /* original 81da, guest PC 0x0c0a81da */
if(!s->budget--) { s->failed_pc=0x0c0a81dau; return 0; }
write(ram,r[13]+20,r[0],2);
goto P_0c0a81dc;
P_0c0a81dc: /* original e578, guest PC 0x0c0a81dc */
if(!s->budget--) { s->failed_pc=0x0c0a81dcu; return 0; }
r[5]=0x00000078u;
goto P_0c0a81de;
P_0c0a81de: /* original 4c0b, guest PC 0x0c0a81de */
if(!s->budget--) { s->failed_pc=0x0c0a81deu; return 0; }
target=r[12];
r[16]=0x8c0a81e2u;
r[4]=0x00000001u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a81e2u) { target=s->pc; goto dispatch; }
goto P_0c0a81e2;
P_0c0a81e0: /* original e401, guest PC 0x0c0a81e0 */
if(!s->budget--) { s->failed_pc=0x0c0a81e0u; return 0; }
r[4]=0x00000001u;
goto P_0c0a81e2;
P_0c0a81e2: /* original 4f16, guest PC 0x0c0a81e2 */
if(!s->budget--) { s->failed_pc=0x0c0a81e2u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a81e4;
P_0c0a81e4: /* original 4f26, guest PC 0x0c0a81e4 */
if(!s->budget--) { s->failed_pc=0x0c0a81e4u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a81e6;
P_0c0a81e6: /* original 6cf6, guest PC 0x0c0a81e6 */
if(!s->budget--) { s->failed_pc=0x0c0a81e6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0a81e8;
P_0c0a81e8: /* original 6df6, guest PC 0x0c0a81e8 */
if(!s->budget--) { s->failed_pc=0x0c0a81e8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0a81ea;
P_0c0a81ea: /* original 000b, guest PC 0x0c0a81ea */
if(!s->budget--) { s->failed_pc=0x0c0a81eau; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0a81ec: /* original 6ef6, guest PC 0x0c0a81ec */
if(!s->budget--) { s->failed_pc=0x0c0a81ecu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0a81eeu,s,ram);
P_0c0c2b60: /* original d535, guest PC 0x0c0c2b60 */
if(!s->budget--) { s->failed_pc=0x0c0c2b60u; return 0; }
r[5]=read(ram,0x0c0c2c38u,4);
goto P_0c0c2b62;
P_0c0c2b62: /* original d436, guest PC 0x0c0c2b62 */
if(!s->budget--) { s->failed_pc=0x0c0c2b62u; return 0; }
r[4]=read(ram,0x0c0c2c3cu,4);
goto P_0c0c2b64;
P_0c0c2b64: /* original 6352, guest PC 0x0c0c2b64 */
if(!s->budget--) { s->failed_pc=0x0c0c2b64u; return 0; }
tmp=read(ram,r[5],4);
r[3]=tmp;
goto P_0c0c2b66;
P_0c0c2b66: /* original 4f22, guest PC 0x0c0c2b66 */
if(!s->budget--) { s->failed_pc=0x0c0c2b66u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0c2b68;
P_0c0c2b68: /* original 2348, guest PC 0x0c0c2b68 */
if(!s->budget--) { s->failed_pc=0x0c0c2b68u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[4])==0)!=0);
goto P_0c0c2b6a;
P_0c0c2b6a: /* original 8902, guest PC 0x0c0c2b6a */
if(!s->budget--) { s->failed_pc=0x0c0c2b6au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c2b72; }
goto P_0c0c2b6c;
P_0c0c2b6c: /* original 5151, guest PC 0x0c0c2b6c */
if(!s->budget--) { s->failed_pc=0x0c0c2b6cu; return 0; }
r[1]=read(ram,r[5]+4,4);
goto P_0c0c2b6e;
P_0c0c2b6e: /* original 2418, guest PC 0x0c0c2b6e */
if(!s->budget--) { s->failed_pc=0x0c0c2b6eu; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[1])==0)!=0);
goto P_0c0c2b70;
P_0c0c2b70: /* original 8b03, guest PC 0x0c0c2b70 */
if(!s->budget--) { s->failed_pc=0x0c0c2b70u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c2b7a; }
goto P_0c0c2b72;
P_0c0c2b72: /* original d334, guest PC 0x0c0c2b72 */
if(!s->budget--) { s->failed_pc=0x0c0c2b72u; return 0; }
r[3]=read(ram,0x0c0c2c44u,4);
goto P_0c0c2b74;
P_0c0c2b74: /* original d432, guest PC 0x0c0c2b74 */
if(!s->budget--) { s->failed_pc=0x0c0c2b74u; return 0; }
r[4]=read(ram,0x0c0c2c40u,4);
goto P_0c0c2b76;
P_0c0c2b76: /* original 430b, guest PC 0x0c0c2b76 */
if(!s->budget--) { s->failed_pc=0x0c0c2b76u; return 0; }
target=r[3];
r[16]=0x8c0c2b7au;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c2b7au) { target=s->pc; goto dispatch; }
goto P_0c0c2b7a;
P_0c0c2b78: /* original 0009, guest PC 0x0c0c2b78 */
if(!s->budget--) { s->failed_pc=0x0c0c2b78u; return 0; }
goto P_0c0c2b7a;
P_0c0c2b7a: /* original 4f26, guest PC 0x0c0c2b7a */
if(!s->budget--) { s->failed_pc=0x0c0c2b7au; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c2b7c;
P_0c0c2b7c: /* original 000b, guest PC 0x0c0c2b7c */
if(!s->budget--) { s->failed_pc=0x0c0c2b7cu; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c0c2b7e: /* original 0009, guest PC 0x0c0c2b7e */
if(!s->budget--) { s->failed_pc=0x0c0c2b7eu; return 0; }
return vf3_matrix_family(0x0c0c2b80u,s,ram);
unsupported: s->failed_pc=target; return 0;
}
static const uint32_t owned_pcs[]={
0x0c06f3bau,0x0c06f3bcu,0x0c06f3beu,0x0c06f3c0u,0x0c06f3c2u,0x0c06f3c4u,0x0c06f3c6u,0x0c06f3c8u,0x0c06f3cau,0x0c06f3ccu,0x0c06f3ceu,0x0c06f3d0u,0x0c06f3d2u,0x0c06f3d4u,0x0c06f3d6u,0x0c06f3d8u,
0x0c06f3dau,0x0c06f3dcu,0x0c06f3deu,0x0c06f3e0u,0x0c06f3e2u,0x0c06f3e4u,0x0c06f3e6u,0x0c06f3e8u,0x0c06f3eau,0x0c06f3ecu,0x0c06f3eeu,0x0c06f3f0u,0x0c06f3f2u,0x0c06f3f4u,0x0c06f3f6u,0x0c06f3f8u,
0x0c06f3fau,0x0c06f3fcu,0x0c06f3feu,0x0c06f400u,0x0c06f402u,0x0c06f404u,0x0c06f406u,0x0c06f408u,0x0c06f40au,0x0c06f40cu,0x0c06f40eu,0x0c06f410u,0x0c06f412u,0x0c06f414u,0x0c06f416u,0x0c06f418u,
0x0c06f41au,0x0c06f41cu,0x0c06f41eu,0x0c06f420u,0x0c06f422u,0x0c06f424u,0x0c06f426u,0x0c06f428u,0x0c06f42au,0x0c06f42cu,0x0c06f42eu,0x0c06f430u,0x0c06f432u,0x0c06f434u,0x0c06f436u,0x0c06f438u,
0x0c06f43au,0x0c06f43cu,0x0c06f43eu,0x0c06f440u,0x0c06f442u,0x0c06f444u,0x0c06f446u,0x0c06f448u,0x0c06f44au,0x0c06f44cu,0x0c06f44eu,0x0c072b40u,0x0c072b42u,0x0c072b44u,0x0c072b46u,0x0c072b48u,
0x0c072b4au,0x0c072b4cu,0x0c072b4eu,0x0c072b50u,0x0c072b52u,0x0c072b54u,0x0c072b56u,0x0c072b58u,0x0c072b5au,0x0c072b5cu,0x0c072b5eu,0x0c072b60u,0x0c072b62u,0x0c072b64u,0x0c072b66u,0x0c072b68u,
0x0c072b6au,0x0c072b6cu,0x0c072b6eu,0x0c072b70u,0x0c072b72u,0x0c072b74u,0x0c072b76u,0x0c072b78u,0x0c072b7au,0x0c072b7cu,0x0c072b7eu,0x0c072b80u,0x0c072b82u,0x0c072b84u,0x0c072b86u,0x0c072b88u,
0x0c072b8au,0x0c072b8cu,0x0c072b8eu,0x0c072b90u,0x0c072b92u,0x0c072b94u,0x0c072b96u,0x0c072b98u,0x0c072b9au,0x0c072b9cu,0x0c072b9eu,0x0c072ba0u,0x0c072ba2u,0x0c072ba4u,0x0c072ba6u,0x0c072ba8u,
0x0c072baau,0x0c072bacu,0x0c072baeu,0x0c072bb0u,0x0c072bb2u,0x0c072bb4u,0x0c072bb6u,0x0c072bb8u,0x0c072bbau,0x0c072bd0u,0x0c072bd2u,0x0c072bd4u,0x0c072bd6u,0x0c072bd8u,0x0c072bdau,0x0c072bdcu,
0x0c072bdeu,0x0c072be0u,0x0c072be2u,0x0c072be4u,0x0c072be6u,0x0c072be8u,0x0c072beau,0x0c072becu,0x0c072beeu,0x0c072bf0u,0x0c072bf2u,0x0c072bf4u,0x0c072bf6u,0x0c072bf8u,0x0c072bfau,0x0c072bfcu,
0x0c072bfeu,0x0c072c00u,0x0c072c02u,0x0c072c04u,0x0c072c06u,0x0c072c08u,0x0c072c0au,0x0c072c0cu,0x0c072c0eu,0x0c072c10u,0x0c072c12u,0x0c072c14u,0x0c072c16u,0x0c072c18u,0x0c072c1au,0x0c072c1cu,
0x0c072c1eu,0x0c072c20u,0x0c072c22u,0x0c072c24u,0x0c072c26u,0x0c072c28u,0x0c072c2au,0x0c072c2cu,0x0c072c2eu,0x0c072c30u,0x0c072c32u,0x0c072c34u,0x0c072c36u,0x0c072c38u,0x0c072c3au,0x0c072c3cu,
0x0c072c3eu,0x0c072c40u,0x0c072c42u,0x0c072c44u,0x0c072c46u,0x0c072c48u,0x0c072c4au,0x0c072c4cu,0x0c072c4eu,0x0c072c6cu,0x0c072c6eu,0x0c072c70u,0x0c072c72u,0x0c072c74u,0x0c072c76u,0x0c072c78u,
0x0c072c7au,0x0c072c7cu,0x0c072c7eu,0x0c072c80u,0x0c072c82u,0x0c072c84u,0x0c072c86u,0x0c072c88u,0x0c072c8au,0x0c072c8cu,0x0c072c8eu,0x0c072c90u,0x0c072c92u,0x0c072c94u,0x0c072c96u,0x0c072c98u,
0x0c072c9au,0x0c072c9cu,0x0c072c9eu,0x0c072ca0u,0x0c072ca2u,0x0c072ca4u,0x0c072ca6u,0x0c072ca8u,0x0c072caau,0x0c072cacu,0x0c072caeu,0x0c072cb0u,0x0c072cb2u,0x0c072cb4u,0x0c072cb6u,0x0c072cb8u,
0x0c072cbau,0x0c072cbcu,0x0c072cbeu,0x0c072cc0u,0x0c072cc2u,0x0c072cc4u,0x0c072cc6u,0x0c072cc8u,0x0c072ccau,0x0c072cccu,0x0c072cceu,0x0c072cd0u,0x0c072cd2u,0x0c072cd4u,0x0c072cd6u,0x0c072cd8u,
0x0c072cdau,0x0c072cdcu,0x0c072cdeu,0x0c072ce0u,0x0c072ce2u,0x0c072ce4u,0x0c072ce6u,0x0c072ce8u,0x0c072ceau,0x0c072cecu,0x0c072ceeu,0x0c072cf0u,0x0c072cf2u,0x0c072cf4u,0x0c072cf6u,0x0c072cf8u,
0x0c072cfau,0x0c0738eau,0x0c0738ecu,0x0c0738eeu,0x0c0738f0u,0x0c0738f2u,0x0c0738f4u,0x0c0738f6u,0x0c0738f8u,0x0c0738fau,0x0c0738fcu,0x0c0738feu,0x0c073900u,0x0c073902u,0x0c073904u,0x0c073906u,
0x0c073908u,0x0c07390au,0x0c07390cu,0x0c07390eu,0x0c073910u,0x0c073912u,0x0c073914u,0x0c073916u,0x0c073918u,0x0c07391au,0x0c07391cu,0x0c07391eu,0x0c073920u,0x0c073922u,0x0c073924u,0x0c073926u,
0x0c073928u,0x0c07392au,0x0c07392cu,0x0c07392eu,0x0c073930u,0x0c073932u,0x0c073934u,0x0c073936u,0x0c073938u,0x0c07393au,0x0c07393cu,0x0c07393eu,0x0c073940u,0x0c073942u,0x0c073944u,0x0c073946u,
0x0c073948u,0x0c07394au,0x0c07394cu,0x0c07394eu,0x0c073984u,0x0c073986u,0x0c073988u,0x0c07398au,0x0c07398cu,0x0c07398eu,0x0c073990u,0x0c073992u,0x0c073994u,0x0c073996u,0x0c073998u,0x0c07399au,
0x0c07399cu,0x0c07399eu,0x0c0739a0u,0x0c0739a2u,0x0c0739a4u,0x0c0739a6u,0x0c0739a8u,0x0c0739aau,0x0c0739acu,0x0c0739aeu,0x0c0739b0u,0x0c0739b2u,0x0c0739b4u,0x0c0739b6u,0x0c0739b8u,0x0c0739bau,
0x0c0739bcu,0x0c0739beu,0x0c0739c0u,0x0c0739c2u,0x0c0739c4u,0x0c0739c6u,0x0c0739c8u,0x0c0739cau,0x0c0739ccu,0x0c0739ceu,0x0c0739d0u,0x0c0739d2u,0x0c0739d4u,0x0c0739d6u,0x0c0739d8u,0x0c0739dau,
0x0c0739dcu,0x0c0739deu,0x0c0739e0u,0x0c0739e2u,0x0c0739e4u,0x0c0739e6u,0x0c0739e8u,0x0c0739eau,0x0c0739ecu,0x0c0739eeu,0x0c0739f0u,0x0c0739f2u,0x0c0739f4u,0x0c0739f6u,0x0c0739f8u,0x0c0739fau,
0x0c0739fcu,0x0c0739feu,0x0c073a00u,0x0c073a02u,0x0c073a04u,0x0c073a06u,0x0c073a08u,0x0c073a0au,0x0c073a0cu,0x0c073a0eu,0x0c073a10u,0x0c073a12u,0x0c073a14u,0x0c073a16u,0x0c073a18u,0x0c073a1au,
0x0c073a1cu,0x0c073a1eu,0x0c073a20u,0x0c073a22u,0x0c073a24u,0x0c073a26u,0x0c073a28u,0x0c073a2au,0x0c073a2cu,0x0c073a2eu,0x0c073a30u,0x0c073a32u,0x0c073a34u,0x0c073a36u,0x0c073a38u,0x0c073a3au,
0x0c073a3cu,0x0c073a3eu,0x0c073a40u,0x0c073a42u,0x0c073a44u,0x0c073a46u,0x0c073a48u,0x0c073a4au,0x0c073a4cu,0x0c073a4eu,0x0c073a50u,0x0c073a52u,0x0c073a54u,0x0c073a56u,0x0c073a58u,0x0c073a5au,
0x0c073a5cu,0x0c073a5eu,0x0c073a60u,0x0c073a62u,0x0c073a64u,0x0c073a66u,0x0c073a68u,0x0c073a6au,0x0c073a6cu,0x0c073a6eu,0x0c073a70u,0x0c073a72u,0x0c073a74u,0x0c073a76u,0x0c073a78u,0x0c073a7au,
0x0c073a7cu,0x0c073a7eu,0x0c076b92u,0x0c076b94u,0x0c076b96u,0x0c076b98u,0x0c076b9au,0x0c076b9cu,0x0c076b9eu,0x0c076ba0u,0x0c076ba2u,0x0c076ba4u,0x0c076ba6u,0x0c076ba8u,0x0c076baau,0x0c076bacu,
0x0c076baeu,0x0c076bb0u,0x0c076bb2u,0x0c076bb4u,0x0c076bb6u,0x0c076bb8u,0x0c076bbau,0x0c076bbcu,0x0c076bbeu,0x0c076bc0u,0x0c076bc2u,0x0c076bc4u,0x0c076bc6u,0x0c076bc8u,0x0c076bcau,0x0c076bccu,
0x0c076bceu,0x0c076bd0u,0x0c076bd2u,0x0c076bd4u,0x0c076bd6u,0x0c076bd8u,0x0c076bdau,0x0c076bdcu,0x0c076bdeu,0x0c076be0u,0x0c076be2u,0x0c076be4u,0x0c076be6u,0x0c076be8u,0x0c076beau,0x0c076becu,
0x0c076beeu,0x0c076bf0u,0x0c076bf2u,0x0c076bf4u,0x0c076bf6u,0x0c076bf8u,0x0c076bfau,0x0c076bfcu,0x0c076bfeu,0x0c076c00u,0x0c076c02u,0x0c076c04u,0x0c076c06u,0x0c076c08u,0x0c076c0au,0x0c076c0cu,
0x0c076c0eu,0x0c076c10u,0x0c076c12u,0x0c076c14u,0x0c076c16u,0x0c076c18u,0x0c076c1au,0x0c076c1cu,0x0c076c1eu,0x0c076c20u,0x0c076c22u,0x0c076c24u,0x0c076c26u,0x0c076c28u,0x0c076c2au,0x0c076c2cu,
0x0c076c2eu,0x0c076c30u,0x0c076c32u,0x0c076c34u,0x0c076c36u,0x0c076c38u,0x0c076c3au,0x0c076c3cu,0x0c076c3eu,0x0c076c40u,0x0c076c42u,0x0c076c44u,0x0c076c46u,0x0c076c48u,0x0c076c4au,0x0c076c4cu,
0x0c076c4eu,0x0c076c50u,0x0c076c52u,0x0c076c54u,0x0c076c56u,0x0c076c58u,0x0c076c5au,0x0c076c5cu,0x0c076c5eu,0x0c076c60u,0x0c076c62u,0x0c076c64u,0x0c076c66u,0x0c076c68u,0x0c076c6au,0x0c076c6cu,
0x0c076c6eu,0x0c076c70u,0x0c076c72u,0x0c076c74u,0x0c076c76u,0x0c076c78u,0x0c076c7au,0x0c076c7cu,0x0c076c7eu,0x0c076c80u,0x0c076c82u,0x0c076c84u,0x0c076c86u,0x0c076c88u,0x0c076c8au,0x0c076c8cu,
0x0c076c8eu,0x0c076c90u,0x0c076c92u,0x0c076c94u,0x0c076c96u,0x0c076c98u,0x0c076c9au,0x0c076c9cu,0x0c076c9eu,0x0c076cd8u,0x0c076cdau,0x0c076cdcu,0x0c076cdeu,0x0c076ce0u,0x0c076ce2u,0x0c076ce4u,
0x0c076ce6u,0x0c076ce8u,0x0c076ceau,0x0c076cecu,0x0c076ceeu,0x0c076cf0u,0x0c076cf2u,0x0c076cf4u,0x0c076cf6u,0x0c076cf8u,0x0c076cfau,0x0c076cfcu,0x0c076cfeu,0x0c076d00u,0x0c076d02u,0x0c076d04u,
0x0c076d06u,0x0c076d08u,0x0c076d0au,0x0c076d0cu,0x0c076d0eu,0x0c076d10u,0x0c076d12u,0x0c076d14u,0x0c076d16u,0x0c076d18u,0x0c076d1au,0x0c076d1cu,0x0c076d1eu,0x0c076d20u,0x0c076d22u,0x0c076d24u,
0x0c076d26u,0x0c076d28u,0x0c076d2au,0x0c076d2cu,0x0c076d2eu,0x0c076d30u,0x0c076d32u,0x0c076d34u,0x0c076d36u,0x0c076d38u,0x0c076d3au,0x0c076d3cu,0x0c076d3eu,0x0c076d40u,0x0c076d42u,0x0c076d44u,
0x0c076d46u,0x0c076d48u,0x0c076d4au,0x0c076d4cu,0x0c076d4eu,0x0c076d50u,0x0c076d52u,0x0c076d54u,0x0c076d56u,0x0c076d58u,0x0c076d5au,0x0c076d5cu,0x0c076d5eu,0x0c076d60u,0x0c076d62u,0x0c076d64u,
0x0c076d66u,0x0c076d68u,0x0c076d6au,0x0c076d6cu,0x0c076d6eu,0x0c076d70u,0x0c076d72u,0x0c076d74u,0x0c076d76u,0x0c076d78u,0x0c076d7au,0x0c076d7cu,0x0c076d7eu,0x0c076d80u,0x0c076d82u,0x0c076d84u,
0x0c076d86u,0x0c076d88u,0x0c076d8au,0x0c076d8cu,0x0c076d8eu,0x0c076d90u,0x0c076d92u,0x0c076d94u,0x0c076d96u,0x0c076d98u,0x0c076d9au,0x0c076d9cu,0x0c076d9eu,0x0c076da0u,0x0c076da2u,0x0c076da4u,
0x0c076da6u,0x0c076da8u,0x0c076de0u,0x0c076de2u,0x0c076de4u,0x0c076de6u,0x0c076de8u,0x0c076deau,0x0c076decu,0x0c076deeu,0x0c076df0u,0x0c076df2u,0x0c076df4u,0x0c076df6u,0x0c076df8u,0x0c076dfau,
0x0c076dfcu,0x0c076dfeu,0x0c076e00u,0x0c076e02u,0x0c076e04u,0x0c076e06u,0x0c076e08u,0x0c076e0au,0x0c076e0cu,0x0c076e0eu,0x0c076e10u,0x0c076e12u,0x0c076e14u,0x0c076e16u,0x0c076e18u,0x0c076e1au,
0x0c076e1cu,0x0c076e1eu,0x0c076e20u,0x0c076e22u,0x0c076e24u,0x0c076e26u,0x0c076e28u,0x0c076e2au,0x0c076e2cu,0x0c076e2eu,0x0c076e30u,0x0c076e32u,0x0c076e34u,0x0c076e36u,0x0c076e38u,0x0c076e3au,
0x0c076e3cu,0x0c076e3eu,0x0c076e40u,0x0c076e42u,0x0c076e44u,0x0c076e46u,0x0c076e48u,0x0c076e4au,0x0c076e4cu,0x0c076e4eu,0x0c076e50u,0x0c076e52u,0x0c076e54u,0x0c076e56u,0x0c076e58u,0x0c076e5au,
0x0c076e5cu,0x0c076e5eu,0x0c076e60u,0x0c076e62u,0x0c076e64u,0x0c076e66u,0x0c076e68u,0x0c076e6au,0x0c076e6cu,0x0c076e6eu,0x0c076e70u,0x0c076e72u,0x0c076e74u,0x0c076e76u,0x0c076e78u,0x0c076e7au,
0x0c076e7cu,0x0c076e7eu,0x0c076e80u,0x0c076e82u,0x0c076e84u,0x0c076e86u,0x0c076e88u,0x0c076e8au,0x0c076e8cu,0x0c076e8eu,0x0c076e90u,0x0c076e92u,0x0c076e94u,0x0c076e96u,0x0c076e98u,0x0c076e9au,
0x0c076e9cu,0x0c076e9eu,0x0c076ea0u,0x0c076ea2u,0x0c076ea4u,0x0c076ea6u,0x0c076ea8u,0x0c076eaau,0x0c076eacu,0x0c076eaeu,0x0c076eb0u,0x0c076eb2u,0x0c076eb4u,0x0c076eb6u,0x0c076eb8u,0x0c076ebau,
0x0c076ef4u,0x0c076ef6u,0x0c076ef8u,0x0c076efau,0x0c076efcu,0x0c076efeu,0x0c076f00u,0x0c076f02u,0x0c076f04u,0x0c076f06u,0x0c076f08u,0x0c076f0au,0x0c076f0cu,0x0c076f0eu,0x0c076f10u,0x0c076f12u,
0x0c076f14u,0x0c076f16u,0x0c076f18u,0x0c076f1au,0x0c076f1cu,0x0c076f1eu,0x0c076f20u,0x0c076f22u,0x0c076f24u,0x0c076f26u,0x0c076f28u,0x0c076f2au,0x0c076f2cu,0x0c076f2eu,0x0c076f30u,0x0c076f32u,
0x0c076f34u,0x0c076f36u,0x0c076f38u,0x0c076f3au,0x0c076f3cu,0x0c076f3eu,0x0c076f40u,0x0c076f42u,0x0c076f44u,0x0c076f46u,0x0c076f48u,0x0c076f4au,0x0c076f4cu,0x0c076f4eu,0x0c076f50u,0x0c076f52u,
0x0c076f54u,0x0c076f56u,0x0c076f58u,0x0c076f5au,0x0c076f5cu,0x0c076f5eu,0x0c076f60u,0x0c076f62u,0x0c076f64u,0x0c076f66u,0x0c076f68u,0x0c076f6au,0x0c076f6cu,0x0c076f6eu,0x0c076f70u,0x0c076f72u,
0x0c076f74u,0x0c076f76u,0x0c076f78u,0x0c076f7au,0x0c076f7cu,0x0c076f7eu,0x0c076f80u,0x0c076f82u,0x0c076f84u,0x0c076f86u,0x0c076f88u,0x0c076f8au,0x0c076f8cu,0x0c076f8eu,0x0c076f90u,0x0c076f92u,
0x0c076f94u,0x0c076f96u,0x0c076f98u,0x0c076f9au,0x0c076f9cu,0x0c076f9eu,0x0c076fa0u,0x0c076fa2u,0x0c076fa4u,0x0c076fa6u,0x0c076fa8u,0x0c076faau,0x0c076facu,0x0c076faeu,0x0c076fb0u,0x0c076fb2u,
0x0c076fb4u,0x0c076fb6u,0x0c076fb8u,0x0c076fbau,0x0c076fbcu,0x0c076fbeu,0x0c076fc0u,0x0c076fc2u,0x0c076fc4u,0x0c076fc6u,0x0c076fc8u,0x0c076fcau,0x0c076fccu,0x0c076fceu,0x0c076fd0u,0x0c076fd2u,
0x0c076fd4u,0x0c076fd6u,0x0c076fd8u,0x0c076fdau,0x0c076fdcu,0x0c076fdeu,0x0c076fe0u,0x0c076fe2u,0x0c076fe4u,0x0c076fe6u,0x0c076fe8u,0x0c076feau,0x0c076fecu,0x0c076feeu,0x0c076ff0u,0x0c076ff2u,
0x0c076ff4u,0x0c076ff6u,0x0c076ff8u,0x0c076ffau,0x0c076ffcu,0x0c076ffeu,0x0c077000u,0x0c077002u,0x0c077004u,0x0c077006u,0x0c077008u,0x0c07700au,0x0c07700cu,0x0c07700eu,0x0c077010u,0x0c077012u,
0x0c077014u,0x0c077016u,0x0c077018u,0x0c07701au,0x0c07701cu,0x0c07701eu,0x0c077020u,0x0c077022u,0x0c077024u,0x0c077026u,0x0c077028u,0x0c07702au,0x0c07702cu,0x0c07702eu,0x0c077030u,0x0c077032u,
0x0c077034u,0x0c077036u,0x0c077038u,0x0c07703au,0x0c07703cu,0x0c07703eu,0x0c077040u,0x0c077042u,0x0c077044u,0x0c077046u,0x0c077048u,0x0c07704au,0x0c07704cu,0x0c07704eu,0x0c077050u,0x0c077052u,
0x0c077054u,0x0c077056u,0x0c077058u,0x0c07705au,0x0c07705cu,0x0c07705eu,0x0c077080u,0x0c077082u,0x0c077084u,0x0c077086u,0x0c077088u,0x0c07708au,0x0c07708cu,0x0c07708eu,0x0c077090u,0x0c077092u,
0x0c077094u,0x0c077096u,0x0c077098u,0x0c07709au,0x0c07709cu,0x0c07709eu,0x0c0770a0u,0x0c0770a2u,0x0c0770a4u,0x0c0770a6u,0x0c0770a8u,0x0c0770aau,0x0c0770acu,0x0c0770aeu,0x0c0770b0u,0x0c0770b2u,
0x0c0770b4u,0x0c0770b6u,0x0c0770b8u,0x0c0770bau,0x0c0770bcu,0x0c0770beu,0x0c0770c0u,0x0c0770c2u,0x0c0770c4u,0x0c0770c6u,0x0c0770c8u,0x0c0770cau,0x0c0770ccu,0x0c0770ceu,0x0c0770d0u,0x0c0770d2u,
0x0c0770d4u,0x0c0770d6u,0x0c0770d8u,0x0c0770dau,0x0c0770dcu,0x0c0770deu,0x0c0770e0u,0x0c0770e2u,0x0c0770e4u,0x0c0770e6u,0x0c0770e8u,0x0c0770eau,0x0c0770ecu,0x0c0770eeu,0x0c0770f0u,0x0c0770f2u,
0x0c0770f4u,0x0c0770f6u,0x0c0770f8u,0x0c0770fau,0x0c0770fcu,0x0c0770feu,0x0c077100u,0x0c077102u,0x0c077104u,0x0c077106u,0x0c077108u,0x0c07710au,0x0c07710cu,0x0c07710eu,0x0c077110u,0x0c077112u,
0x0c077114u,0x0c077116u,0x0c077118u,0x0c07711au,0x0c07711cu,0x0c07711eu,0x0c077120u,0x0c077122u,0x0c077124u,0x0c077126u,0x0c077128u,0x0c07712au,0x0c07712cu,0x0c07712eu,0x0c077130u,0x0c077132u,
0x0c077134u,0x0c077136u,0x0c077138u,0x0c07713au,0x0c07713cu,0x0c07713eu,0x0c077140u,0x0c077142u,0x0c077144u,0x0c077146u,0x0c077148u,0x0c07714au,0x0c07714cu,0x0c07714eu,0x0c077150u,0x0c077152u,
0x0c077154u,0x0c077156u,0x0c077158u,0x0c07715au,0x0c07715cu,0x0c07715eu,0x0c077160u,0x0c077162u,0x0c077164u,0x0c077166u,0x0c077168u,0x0c07716au,0x0c07716cu,0x0c07716eu,0x0c077170u,0x0c077172u,
0x0c077174u,0x0c077176u,0x0c077178u,0x0c07717au,0x0c07717cu,0x0c07717eu,0x0c077180u,0x0c077182u,0x0c077184u,0x0c077186u,0x0c077188u,0x0c07718au,0x0c07718cu,0x0c07718eu,0x0c077190u,0x0c0771acu,
0x0c0771aeu,0x0c0771b0u,0x0c0771b2u,0x0c0771b4u,0x0c0771b6u,0x0c0771b8u,0x0c0771bau,0x0c0771bcu,0x0c0771beu,0x0c0771c0u,0x0c0771c2u,0x0c0771c4u,0x0c0771c6u,0x0c0771c8u,0x0c0771cau,0x0c0771ccu,
0x0c0771ceu,0x0c0771d0u,0x0c0771d2u,0x0c0771d4u,0x0c0771d6u,0x0c0771d8u,0x0c0771dau,0x0c0771dcu,0x0c0771deu,0x0c0771e0u,0x0c0771e2u,0x0c0771e4u,0x0c0771e6u,0x0c0771e8u,0x0c0771eau,0x0c0771ecu,
0x0c0771eeu,0x0c0771f0u,0x0c0771f2u,0x0c0771f4u,0x0c0771f6u,0x0c0771f8u,0x0c0771fau,0x0c0771fcu,0x0c0771feu,0x0c077200u,0x0c077202u,0x0c077204u,0x0c077206u,0x0c077208u,0x0c07720au,0x0c07720cu,
0x0c07720eu,0x0c077210u,0x0c077212u,0x0c077214u,0x0c077216u,0x0c077218u,0x0c07721au,0x0c07721cu,0x0c07721eu,0x0c077220u,0x0c077222u,0x0c077224u,0x0c077226u,0x0c077228u,0x0c07722au,0x0c07722cu,
0x0c07722eu,0x0c077230u,0x0c077232u,0x0c077234u,0x0c077236u,0x0c077238u,0x0c07723au,0x0c07723cu,0x0c07723eu,0x0c077240u,0x0c077242u,0x0c077244u,0x0c077246u,0x0c077248u,0x0c07724au,0x0c07724cu,
0x0c07724eu,0x0c077250u,0x0c077252u,0x0c077254u,0x0c077256u,0x0c077258u,0x0c07725au,0x0c07725cu,0x0c07725eu,0x0c077260u,0x0c077262u,0x0c077264u,0x0c077266u,0x0c077268u,0x0c07726au,0x0c07726cu,
0x0c07726eu,0x0c077270u,0x0c077272u,0x0c077274u,0x0c077276u,0x0c077278u,0x0c07727au,0x0c07727cu,0x0c07727eu,0x0c077280u,0x0c077282u,0x0c077284u,0x0c077286u,0x0c077288u,0x0c07728au,0x0c0772a0u,
0x0c0772a2u,0x0c0772a4u,0x0c0772a6u,0x0c0772a8u,0x0c0772aau,0x0c0772acu,0x0c0772aeu,0x0c0772b0u,0x0c0772b2u,0x0c0772b4u,0x0c0772b6u,0x0c0772b8u,0x0c0772bau,0x0c0772bcu,0x0c0772beu,0x0c0772c0u,
0x0c0772c2u,0x0c0772c4u,0x0c0772c6u,0x0c0772c8u,0x0c0772cau,0x0c0772ccu,0x0c0772ceu,0x0c0772d0u,0x0c0772d2u,0x0c0772d4u,0x0c0772d6u,0x0c0772d8u,0x0c0772dau,0x0c0772dcu,0x0c0772deu,0x0c0772e0u,
0x0c0772e2u,0x0c0772e4u,0x0c0772e6u,0x0c0772e8u,0x0c0772eau,0x0c0772ecu,0x0c0772eeu,0x0c0772f0u,0x0c0772f2u,0x0c0772f4u,0x0c0772f6u,0x0c0772f8u,0x0c0772fau,0x0c0772fcu,0x0c0772feu,0x0c077300u,
0x0c077302u,0x0c077304u,0x0c077306u,0x0c077308u,0x0c07730au,0x0c07730cu,0x0c07730eu,0x0c077310u,0x0c077312u,0x0c077314u,0x0c077316u,0x0c077318u,0x0c07731au,0x0c07731cu,0x0c07731eu,0x0c077320u,
0x0c077322u,0x0c077324u,0x0c077326u,0x0c077328u,0x0c07732au,0x0c07732cu,0x0c07732eu,0x0c077330u,0x0c077332u,0x0c077334u,0x0c077336u,0x0c077338u,0x0c07733au,0x0c07733cu,0x0c07734cu,0x0c07734eu,
0x0c077350u,0x0c077352u,0x0c077354u,0x0c077356u,0x0c077358u,0x0c07735au,0x0c07735cu,0x0c07735eu,0x0c077360u,0x0c077362u,0x0c077364u,0x0c077366u,0x0c077368u,0x0c07736au,0x0c07736cu,0x0c07736eu,
0x0c077370u,0x0c077372u,0x0c077374u,0x0c077376u,0x0c077378u,0x0c07737au,0x0c07737cu,0x0c07737eu,0x0c077380u,0x0c077382u,0x0c077384u,0x0c077386u,0x0c077388u,0x0c07738au,0x0c07738cu,0x0c07738eu,
0x0c077390u,0x0c077392u,0x0c077394u,0x0c077396u,0x0c077398u,0x0c07739au,0x0c07739cu,0x0c07739eu,0x0c0773a0u,0x0c0773a2u,0x0c0773a4u,0x0c0773a6u,0x0c0773a8u,0x0c0773aau,0x0c0773acu,0x0c0773aeu,
0x0c0773b0u,0x0c0773b2u,0x0c0773b4u,0x0c0773b6u,0x0c0773b8u,0x0c0773bau,0x0c0773bcu,0x0c0773beu,0x0c0773c0u,0x0c0773c2u,0x0c0773c4u,0x0c0773c6u,0x0c0773c8u,0x0c0773cau,0x0c0773ccu,0x0c0773ceu,
0x0c0773d0u,0x0c0773d2u,0x0c0773d4u,0x0c0773d6u,0x0c0773d8u,0x0c0773dau,0x0c0773dcu,0x0c0773deu,0x0c0773e0u,0x0c0773e2u,0x0c0773e4u,0x0c0773e6u,0x0c0773e8u,0x0c0773eau,0x0c0773ecu,0x0c0773eeu,
0x0c0773f0u,0x0c0773f2u,0x0c0773f4u,0x0c0773f6u,0x0c0773f8u,0x0c0773fau,0x0c0773fcu,0x0c0773feu,0x0c077400u,0x0c077402u,0x0c077404u,0x0c077406u,0x0c077408u,0x0c07740au,0x0c07740cu,0x0c07740eu,
0x0c077410u,0x0c077412u,0x0c077414u,0x0c077416u,0x0c077418u,0x0c07741au,0x0c07741cu,0x0c07741eu,0x0c077420u,0x0c077422u,0x0c077424u,0x0c077426u,0x0c077428u,0x0c07742au,0x0c07742cu,0x0c07742eu,
0x0c077430u,0x0c077432u,0x0c077434u,0x0c077436u,0x0c077438u,0x0c07743au,0x0c07743cu,0x0c07743eu,0x0c077440u,0x0c077442u,0x0c077444u,0x0c077446u,0x0c077448u,0x0c07744au,0x0c07744cu,0x0c07746cu,
0x0c07746eu,0x0c077470u,0x0c077472u,0x0c077474u,0x0c077476u,0x0c077478u,0x0c07747au,0x0c07747cu,0x0c07747eu,0x0c077480u,0x0c077482u,0x0c077484u,0x0c077486u,0x0c077488u,0x0c07748au,0x0c07748cu,
0x0c07748eu,0x0c077490u,0x0c077492u,0x0c077494u,0x0c077496u,0x0c077498u,0x0c07749au,0x0c07749cu,0x0c07749eu,0x0c0774a0u,0x0c0774a2u,0x0c0774a4u,0x0c0774a6u,0x0c0774a8u,0x0c0774aau,0x0c0774acu,
0x0c0774aeu,0x0c0774b0u,0x0c0774b2u,0x0c0774b4u,0x0c0774b6u,0x0c0774b8u,0x0c0774bau,0x0c0774bcu,0x0c0774beu,0x0c0774c0u,0x0c0774c2u,0x0c0774c4u,0x0c0774c6u,0x0c0774c8u,0x0c0774cau,0x0c0774ccu,
0x0c0774ceu,0x0c0774d0u,0x0c0774d2u,0x0c0774d4u,0x0c0774d6u,0x0c0774d8u,0x0c0774dau,0x0c0774dcu,0x0c0774deu,0x0c0774e0u,0x0c0774e2u,0x0c0774e4u,0x0c0774e6u,0x0c0774e8u,0x0c0774eau,0x0c0774ecu,
0x0c0774eeu,0x0c0774f0u,0x0c0774f2u,0x0c0774f4u,0x0c0774f6u,0x0c0774f8u,0x0c0774fau,0x0c0774fcu,0x0c0774feu,0x0c077500u,0x0c077502u,0x0c077504u,0x0c077506u,0x0c077508u,0x0c07750au,0x0c07750cu,
0x0c07750eu,0x0c077510u,0x0c077512u,0x0c077514u,0x0c077516u,0x0c077518u,0x0c07751au,0x0c07751cu,0x0c07751eu,0x0c077520u,0x0c077522u,0x0c077524u,0x0c077526u,0x0c077528u,0x0c07752au,0x0c07752cu,
0x0c07752eu,0x0c077530u,0x0c077532u,0x0c077534u,0x0c077536u,0x0c077538u,0x0c07753au,0x0c07753cu,0x0c07753eu,0x0c077540u,0x0c077542u,0x0c077544u,0x0c077546u,0x0c077548u,0x0c07754au,0x0c07754cu,
0x0c07754eu,0x0c077550u,0x0c077552u,0x0c077554u,0x0c077556u,0x0c077558u,0x0c07755au,0x0c07755cu,0x0c07755eu,0x0c077560u,0x0c077562u,0x0c077564u,0x0c077566u,0x0c077568u,0x0c07756au,0x0c077584u,
0x0c077586u,0x0c077588u,0x0c07758au,0x0c07758cu,0x0c07758eu,0x0c077590u,0x0c077592u,0x0c077594u,0x0c077596u,0x0c077598u,0x0c07759au,0x0c07759cu,0x0c07759eu,0x0c0775a0u,0x0c0775a2u,0x0c0775a4u,
0x0c0775a6u,0x0c0775a8u,0x0c0775aau,0x0c0775acu,0x0c0775aeu,0x0c0775b0u,0x0c0775b2u,0x0c0775b4u,0x0c0775b6u,0x0c0775b8u,0x0c0775bau,0x0c0775bcu,0x0c0775beu,0x0c0775c0u,0x0c0775c2u,0x0c0775c4u,
0x0c0775c6u,0x0c0775c8u,0x0c0775cau,0x0c0775ccu,0x0c0775ceu,0x0c0775d0u,0x0c0775d2u,0x0c0775d4u,0x0c0775d6u,0x0c0775d8u,0x0c0775dau,0x0c0775dcu,0x0c0775deu,0x0c0775e0u,0x0c0775e2u,0x0c0775e4u,
0x0c0775e6u,0x0c0775e8u,0x0c0775eau,0x0c0775ecu,0x0c0775eeu,0x0c0775f0u,0x0c0775f2u,0x0c0775f4u,0x0c0775f6u,0x0c0775f8u,0x0c0775fau,0x0c0775fcu,0x0c077614u,0x0c077616u,0x0c077618u,0x0c07761au,
0x0c07761cu,0x0c07761eu,0x0c077620u,0x0c077622u,0x0c077624u,0x0c077626u,0x0c077628u,0x0c07762au,0x0c07762cu,0x0c07762eu,0x0c077630u,0x0c077632u,0x0c077634u,0x0c077636u,0x0c077638u,0x0c07763au,
0x0c07763cu,0x0c07763eu,0x0c077640u,0x0c077642u,0x0c077644u,0x0c077646u,0x0c077648u,0x0c07764au,0x0c07764cu,0x0c07764eu,0x0c077650u,0x0c077652u,0x0c077654u,0x0c077656u,0x0c077658u,0x0c07765au,
0x0c07765cu,0x0c07765eu,0x0c077660u,0x0c077662u,0x0c077664u,0x0c077666u,0x0c077668u,0x0c07766au,0x0c07766cu,0x0c07766eu,0x0c077670u,0x0c077672u,0x0c077674u,0x0c077676u,0x0c077678u,0x0c07767au,
0x0c07767cu,0x0c07767eu,0x0c077680u,0x0c077682u,0x0c077684u,0x0c077686u,0x0c077688u,0x0c07768au,0x0c07768cu,0x0c07768eu,0x0c077690u,0x0c077692u,0x0c077694u,0x0c077696u,0x0c077698u,0x0c07769au,
0x0c07769cu,0x0c07769eu,0x0c0776a0u,0x0c0776a2u,0x0c0776a4u,0x0c0776a6u,0x0c0776a8u,0x0c0776aau,0x0c0776acu,0x0c0776aeu,0x0c0776b0u,0x0c0776b2u,0x0c0776b4u,0x0c0776b6u,0x0c0776b8u,0x0c0776bau,
0x0c0776bcu,0x0c0776beu,0x0c0776c0u,0x0c0776c2u,0x0c0776c4u,0x0c0776c6u,0x0c0776c8u,0x0c0776cau,0x0c0776ccu,0x0c0776ceu,0x0c0776d0u,0x0c0776d2u,0x0c0776d4u,0x0c0776d6u,0x0c0776d8u,0x0c0776dau,
0x0c0776dcu,0x0c0776deu,0x0c0776e0u,0x0c0776e2u,0x0c0776e4u,0x0c0776e6u,0x0c0776e8u,0x0c0776eau,0x0c0776ecu,0x0c0776eeu,0x0c0776f0u,0x0c0776f2u,0x0c0776f4u,0x0c0776f6u,0x0c0776f8u,0x0c0776fau,
0x0c0776fcu,0x0c0776feu,0x0c077700u,0x0c077702u,0x0c077704u,0x0c077706u,0x0c077708u,0x0c07770au,0x0c07770cu,0x0c07770eu,0x0c077710u,0x0c077712u,0x0c077714u,0x0c077716u,0x0c077718u,0x0c07771au,
0x0c07771cu,0x0c07771eu,0x0c077720u,0x0c077722u,0x0c077724u,0x0c077726u,0x0c077728u,0x0c07772au,0x0c07772cu,0x0c07772eu,0x0c077730u,0x0c077732u,0x0c077734u,0x0c077736u,0x0c077738u,0x0c07773au,
0x0c07773cu,0x0c07773eu,0x0c077740u,0x0c077742u,0x0c077744u,0x0c077746u,0x0c077748u,0x0c07774au,0x0c07774cu,0x0c07774eu,0x0c077750u,0x0c077752u,0x0c077754u,0x0c077756u,0x0c077758u,0x0c07775au,
0x0c07775cu,0x0c07775eu,0x0c077760u,0x0c077762u,0x0c077764u,0x0c077784u,0x0c077786u,0x0c077788u,0x0c07778au,0x0c07778cu,0x0c07778eu,0x0c077790u,0x0c077792u,0x0c077794u,0x0c077796u,0x0c077798u,
0x0c07779au,0x0c07779cu,0x0c07779eu,0x0c0777a0u,0x0c0777a2u,0x0c0777a4u,0x0c0777a6u,0x0c0777a8u,0x0c0777aau,0x0c0777acu,0x0c0777aeu,0x0c0777b0u,0x0c0777b2u,0x0c0777b4u,0x0c0777b6u,0x0c0777b8u,
0x0c0777bau,0x0c0777bcu,0x0c0777beu,0x0c0777c0u,0x0c0777c2u,0x0c0777c4u,0x0c0777c6u,0x0c0777c8u,0x0c0777cau,0x0c0777ccu,0x0c0777ceu,0x0c0777d0u,0x0c0777d2u,0x0c0777d4u,0x0c0777d6u,0x0c0777d8u,
0x0c0777dau,0x0c0777dcu,0x0c0777deu,0x0c0777e0u,0x0c0777e2u,0x0c0777e4u,0x0c0777e6u,0x0c0777e8u,0x0c0777eau,0x0c0777ecu,0x0c0777eeu,0x0c0777f0u,0x0c0777f2u,0x0c0777f4u,0x0c0777f6u,0x0c0777f8u,
0x0c0777fau,0x0c0777fcu,0x0c0777feu,0x0c077800u,0x0c077802u,0x0c077804u,0x0c077806u,0x0c077808u,0x0c07780au,0x0c07780cu,0x0c07780eu,0x0c077810u,0x0c077812u,0x0c077814u,0x0c077816u,0x0c077818u,
0x0c07781au,0x0c07781cu,0x0c07781eu,0x0c077820u,0x0c077822u,0x0c077824u,0x0c077826u,0x0c077828u,0x0c07782au,0x0c07782cu,0x0c07782eu,0x0c077830u,0x0c077832u,0x0c077834u,0x0c077836u,0x0c077838u,
0x0c07783au,0x0c07783cu,0x0c07783eu,0x0c077840u,0x0c077842u,0x0c077844u,0x0c077846u,0x0c077848u,0x0c07784au,0x0c07784cu,0x0c07784eu,0x0c077850u,0x0c077852u,0x0c077854u,0x0c077856u,0x0c077858u,
0x0c07785au,0x0c07785cu,0x0c07785eu,0x0c077860u,0x0c077862u,0x0c077864u,0x0c077866u,0x0c077868u,0x0c07786au,0x0c07786cu,0x0c07786eu,0x0c077870u,0x0c077872u,0x0c077874u,0x0c077876u,0x0c077878u,
0x0c07787au,0x0c07787cu,0x0c07787eu,0x0c077880u,0x0c077882u,0x0c077884u,0x0c077886u,0x0c077888u,0x0c07788au,0x0c0778a4u,0x0c0778a6u,0x0c0778a8u,0x0c0778aau,0x0c0778acu,0x0c0778aeu,0x0c0778b0u,
0x0c0778b2u,0x0c0778b4u,0x0c0778b6u,0x0c0778b8u,0x0c0778bau,0x0c0778bcu,0x0c0778beu,0x0c0778c0u,0x0c0778c2u,0x0c0778c4u,0x0c0778c6u,0x0c0778c8u,0x0c0778cau,0x0c0778ccu,0x0c0778ceu,0x0c0778d0u,
0x0c0778d2u,0x0c0778d4u,0x0c0778d6u,0x0c0778d8u,0x0c0778dau,0x0c0778dcu,0x0c0778deu,0x0c0778e0u,0x0c0778e2u,0x0c0778e4u,0x0c0778e6u,0x0c0778e8u,0x0c0778eau,0x0c0778ecu,0x0c0778eeu,0x0c0778f0u,
0x0c0778f2u,0x0c0778f4u,0x0c0778f6u,0x0c0778f8u,0x0c0778fau,0x0c0778fcu,0x0c0778feu,0x0c077900u,0x0c077902u,0x0c077904u,0x0c077906u,0x0c077908u,0x0c07790au,0x0c07790cu,0x0c07790eu,0x0c077910u,
0x0c077912u,0x0c077914u,0x0c077916u,0x0c077918u,0x0c07791au,0x0c07791cu,0x0c07791eu,0x0c077920u,0x0c077922u,0x0c077924u,0x0c077926u,0x0c077928u,0x0c07792au,0x0c07792cu,0x0c07792eu,0x0c077930u,
0x0c077932u,0x0c077934u,0x0c077936u,0x0c077938u,0x0c07793au,0x0c07793cu,0x0c07793eu,0x0c077940u,0x0c077942u,0x0c077944u,0x0c077946u,0x0c077948u,0x0c07794au,0x0c07794cu,0x0c07794eu,0x0c077950u,
0x0c077952u,0x0c077954u,0x0c077956u,0x0c077958u,0x0c07795au,0x0c07795cu,0x0c07795eu,0x0c077960u,0x0c077962u,0x0c077964u,0x0c077966u,0x0c077968u,0x0c07796au,0x0c07796cu,0x0c07796eu,0x0c077970u,
0x0c077972u,0x0c077974u,0x0c077976u,0x0c077978u,0x0c07797au,0x0c07797cu,0x0c07797eu,0x0c077980u,0x0c077998u,0x0c07799au,0x0c07799cu,0x0c07799eu,0x0c0779a0u,0x0c0779a2u,0x0c0779a4u,0x0c0779a6u,
0x0c0779a8u,0x0c0779aau,0x0c0779acu,0x0c0779aeu,0x0c0779b0u,0x0c0779b2u,0x0c0779b4u,0x0c0779b6u,0x0c0779b8u,0x0c0779bau,0x0c0779bcu,0x0c0779beu,0x0c0779c0u,0x0c0779c2u,0x0c0779c4u,0x0c0779c6u,
0x0c0779c8u,0x0c0779cau,0x0c0779ccu,0x0c0779ceu,0x0c0779d0u,0x0c0779d2u,0x0c0779d4u,0x0c0779d6u,0x0c0779d8u,0x0c0779dau,0x0c0779dcu,0x0c0779deu,0x0c0779e0u,0x0c0779e2u,0x0c0779e4u,0x0c0779e6u,
0x0c0779e8u,0x0c0779eau,0x0c0779ecu,0x0c0779eeu,0x0c0779f0u,0x0c0779f2u,0x0c0779f4u,0x0c0779f6u,0x0c0779f8u,0x0c0779fau,0x0c0779fcu,0x0c0779feu,0x0c077a00u,0x0c077a02u,0x0c077a04u,0x0c077a06u,
0x0c077a08u,0x0c077a0au,0x0c077a0cu,0x0c077a0eu,0x0c077a10u,0x0c077a12u,0x0c077a14u,0x0c077a16u,0x0c077a18u,0x0c077a1au,0x0c077a1cu,0x0c077a1eu,0x0c077a20u,0x0c077a22u,0x0c077a24u,0x0c077a26u,
0x0c077a28u,0x0c077a2au,0x0c077a2cu,0x0c077a2eu,0x0c077a30u,0x0c077a32u,0x0c077a34u,0x0c077a36u,0x0c077a38u,0x0c077a3au,0x0c077a3cu,0x0c077a3eu,0x0c077a40u,0x0c077a42u,0x0c077a44u,0x0c077a46u,
0x0c077a48u,0x0c077a4au,0x0c077a4cu,0x0c077a4eu,0x0c077a50u,0x0c077a52u,0x0c077a54u,0x0c077a56u,0x0c077a58u,0x0c077a5au,0x0c077a5cu,0x0c077a5eu,0x0c077a60u,0x0c077a62u,0x0c077a64u,0x0c077a66u,
0x0c077a68u,0x0c077a6au,0x0c077a6cu,0x0c077a6eu,0x0c077a70u,0x0c077a72u,0x0c077a74u,0x0c077a76u,0x0c077a78u,0x0c077a7au,0x0c077a7cu,0x0c077a7eu,0x0c077a80u,0x0c077a82u,0x0c077a84u,0x0c077a86u,
0x0c077a88u,0x0c077a8au,0x0c077a8cu,0x0c077a8eu,0x0c077a90u,0x0c077a92u,0x0c077a94u,0x0c077a96u,0x0c077a98u,0x0c077a9au,0x0c077a9cu,0x0c077a9eu,0x0c077aa0u,0x0c077aa2u,0x0c077aa4u,0x0c077aa6u,
0x0c077aa8u,0x0c077aaau,0x0c077aacu,0x0c077aaeu,0x0c077ad0u,0x0c077ad2u,0x0c077ad4u,0x0c077ad6u,0x0c077ad8u,0x0c077adau,0x0c077adcu,0x0c077adeu,0x0c077ae0u,0x0c077ae2u,0x0c077ae4u,0x0c077ae6u,
0x0c077ae8u,0x0c077aeau,0x0c077aecu,0x0c077aeeu,0x0c077af0u,0x0c077af2u,0x0c077af4u,0x0c077af6u,0x0c077af8u,0x0c077afau,0x0c077afcu,0x0c077afeu,0x0c077b00u,0x0c077b02u,0x0c077b04u,0x0c077b06u,
0x0c077b08u,0x0c077b0au,0x0c077b0cu,0x0c077b0eu,0x0c077b10u,0x0c077b12u,0x0c077b14u,0x0c077b16u,0x0c077b18u,0x0c077b1au,0x0c077b1cu,0x0c077b1eu,0x0c077b20u,0x0c077b22u,0x0c077b24u,0x0c077b26u,
0x0c077b28u,0x0c077b2au,0x0c077b2cu,0x0c077b2eu,0x0c077b30u,0x0c077b32u,0x0c077b34u,0x0c077b36u,0x0c077b38u,0x0c077b3au,0x0c077b3cu,0x0c077b3eu,0x0c077b40u,0x0c077b42u,0x0c077b44u,0x0c077b46u,
0x0c077b48u,0x0c077b4au,0x0c077b4cu,0x0c077b4eu,0x0c077b50u,0x0c077b52u,0x0c077b54u,0x0c077b56u,0x0c077b58u,0x0c077b5au,0x0c077b5cu,0x0c077b5eu,0x0c077b60u,0x0c077b62u,0x0c077b64u,0x0c077b66u,
0x0c077b68u,0x0c077b6au,0x0c077b6cu,0x0c077b6eu,0x0c077b70u,0x0c077b72u,0x0c077b74u,0x0c077b76u,0x0c077b78u,0x0c077b7au,0x0c077b7cu,0x0c077b7eu,0x0c077b80u,0x0c077b82u,0x0c077b84u,0x0c077b86u,
0x0c077b88u,0x0c077b8au,0x0c077b8cu,0x0c077b8eu,0x0c077b90u,0x0c077b92u,0x0c077b94u,0x0c077b96u,0x0c077b98u,0x0c077b9au,0x0c077b9cu,0x0c077b9eu,0x0c077bbcu,0x0c077bbeu,0x0c077bc0u,0x0c077bc2u,
0x0c077bc4u,0x0c077bc6u,0x0c077bc8u,0x0c077bcau,0x0c077bccu,0x0c077bceu,0x0c077bd0u,0x0c077bd2u,0x0c077bd4u,0x0c077bd6u,0x0c077bd8u,0x0c077bdau,0x0c077bdcu,0x0c077bdeu,0x0c077be0u,0x0c077be2u,
0x0c077be4u,0x0c077be6u,0x0c077be8u,0x0c077beau,0x0c077becu,0x0c077beeu,0x0c077bf0u,0x0c077bf2u,0x0c077bf4u,0x0c077bf6u,0x0c077bf8u,0x0c077bfau,0x0c077bfcu,0x0c077bfeu,0x0c077c00u,0x0c077c02u,
0x0c077c04u,0x0c077c06u,0x0c077c08u,0x0c077c0au,0x0c077c0cu,0x0c077c0eu,0x0c077c10u,0x0c077c12u,0x0c077c14u,0x0c077c16u,0x0c077c18u,0x0c077c1au,0x0c077c1cu,0x0c077c1eu,0x0c077c20u,0x0c077c22u,
0x0c077c24u,0x0c077c26u,0x0c077c28u,0x0c077c2au,0x0c077c2cu,0x0c077c2eu,0x0c077c30u,0x0c077c32u,0x0c077c34u,0x0c077c36u,0x0c077c38u,0x0c077c3au,0x0c077c3cu,0x0c077c3eu,0x0c077c40u,0x0c077c42u,
0x0c077c44u,0x0c077c46u,0x0c077c48u,0x0c077c4au,0x0c077c4cu,0x0c077c4eu,0x0c077c50u,0x0c077c52u,0x0c077c54u,0x0c077c56u,0x0c077c58u,0x0c077c5au,0x0c077c5cu,0x0c077c5eu,0x0c077c60u,0x0c077c62u,
0x0c077c64u,0x0c077c66u,0x0c077c68u,0x0c077c6au,0x0c077c6cu,0x0c077c6eu,0x0c077c70u,0x0c077c72u,0x0c077c74u,0x0c077c76u,0x0c077c78u,0x0c077c7au,0x0c077c7cu,0x0c077c7eu,0x0c077c80u,0x0c077c82u,
0x0c077c84u,0x0c077c86u,0x0c077c88u,0x0c077c8au,0x0c077c8cu,0x0c077c8eu,0x0c077c90u,0x0c077c92u,0x0c077c94u,0x0c077c96u,0x0c077c98u,0x0c077c9au,0x0c077c9cu,0x0c077c9eu,0x0c077ca0u,0x0c077ca2u,
0x0c077ca4u,0x0c077ca6u,0x0c077ca8u,0x0c077caau,0x0c077cacu,0x0c077caeu,0x0c077cb0u,0x0c077cb2u,0x0c077cb4u,0x0c077cb6u,0x0c077cb8u,0x0c077cbau,0x0c077cbcu,0x0c077cbeu,0x0c077cc0u,0x0c077cc2u,
0x0c077cc4u,0x0c077cc6u,0x0c077cc8u,0x0c077ccau,0x0c077cccu,0x0c077cceu,0x0c077cd0u,0x0c077cd2u,0x0c077cd4u,0x0c077cd6u,0x0c077cd8u,0x0c077cdau,0x0c077cdcu,0x0c077cdeu,0x0c077ce0u,0x0c077ce2u,
0x0c077ce4u,0x0c077ce6u,0x0c077ce8u,0x0c077ceau,0x0c077cecu,0x0c077ceeu,0x0c077cf0u,0x0c077cf2u,0x0c077cf4u,0x0c077d1cu,0x0c077d1eu,0x0c077d20u,0x0c077d22u,0x0c077d24u,0x0c077d26u,0x0c077d28u,
0x0c077d2au,0x0c077d2cu,0x0c077d2eu,0x0c077d30u,0x0c077d32u,0x0c077d34u,0x0c077d36u,0x0c077d38u,0x0c077d3au,0x0c077d3cu,0x0c077d3eu,0x0c077d40u,0x0c077d42u,0x0c077d44u,0x0c077d46u,0x0c077d48u,
0x0c077d4au,0x0c077d4cu,0x0c077d4eu,0x0c077d50u,0x0c077d52u,0x0c077d54u,0x0c077d56u,0x0c077d58u,0x0c077d5au,0x0c077d5cu,0x0c077d5eu,0x0c077d60u,0x0c077d62u,0x0c077d64u,0x0c077d66u,0x0c077d68u,
0x0c077d6au,0x0c077d6cu,0x0c077d6eu,0x0c077d70u,0x0c077d72u,0x0c077d74u,0x0c077d76u,0x0c077d78u,0x0c077d7au,0x0c077d7cu,0x0c077d7eu,0x0c077d80u,0x0c077d82u,0x0c077d84u,0x0c077d86u,0x0c077d88u,
0x0c077d8au,0x0c077d8cu,0x0c077d8eu,0x0c077d90u,0x0c077d92u,0x0c077d94u,0x0c077d96u,0x0c077d98u,0x0c077d9au,0x0c077d9cu,0x0c077d9eu,0x0c077da0u,0x0c077da2u,0x0c077da4u,0x0c077da6u,0x0c077da8u,
0x0c077daau,0x0c077dacu,0x0c077daeu,0x0c077db0u,0x0c077db2u,0x0c077db4u,0x0c077db6u,0x0c077db8u,0x0c077dbau,0x0c077dbcu,0x0c077dbeu,0x0c077dc0u,0x0c077dc2u,0x0c077dc4u,0x0c077dc6u,0x0c077dc8u,
0x0c077dcau,0x0c077dccu,0x0c077dceu,0x0c077dd0u,0x0c077dd2u,0x0c077dd4u,0x0c077dd6u,0x0c077dd8u,0x0c077ddau,0x0c077e04u,0x0c077e06u,0x0c077e08u,0x0c077e0au,0x0c077e0cu,0x0c077e0eu,0x0c077e10u,
0x0c077e12u,0x0c077e14u,0x0c077e16u,0x0c077e18u,0x0c077e1au,0x0c077e1cu,0x0c077e1eu,0x0c077e20u,0x0c077e22u,0x0c077e24u,0x0c077e26u,0x0c077e28u,0x0c077e2au,0x0c077e2cu,0x0c077e2eu,0x0c077e30u,
0x0c077e32u,0x0c077e34u,0x0c077e36u,0x0c077e38u,0x0c077e3au,0x0c077e3cu,0x0c077e3eu,0x0c077e40u,0x0c077e42u,0x0c077e44u,0x0c077e46u,0x0c077e48u,0x0c077e4au,0x0c077e4cu,0x0c0786d4u,0x0c0786d6u,
0x0c07873cu,0x0c07873eu,0x0c078858u,0x0c07885au,0x0c07885cu,0x0c0788a6u,0x0c0788a8u,0x0c0788aau,0x0c078dd0u,0x0c078dd2u,0x0c078dd4u,0x0c078dd6u,0x0c078dd8u,0x0c078ddau,0x0c078ddcu,0x0c078ddeu,
0x0c078de0u,0x0c078de2u,0x0c078de4u,0x0c078de6u,0x0c078de8u,0x0c078deau,0x0c078decu,0x0c078deeu,0x0c078df0u,0x0c078df2u,0x0c078df4u,0x0c078df6u,0x0c078df8u,0x0c078dfau,0x0c078dfcu,0x0c078dfeu,
0x0c078e00u,0x0c078e02u,0x0c078e04u,0x0c078e06u,0x0c078e08u,0x0c078e0au,0x0c078e0cu,0x0c078e0eu,0x0c078e10u,0x0c078e12u,0x0c078e14u,0x0c078e16u,0x0c079462u,0x0c079464u,0x0c079466u,0x0c079468u,
0x0c07946au,0x0c07946cu,0x0c07946eu,0x0c079470u,0x0c079472u,0x0c079474u,0x0c079476u,0x0c079478u,0x0c07947au,0x0c07947cu,0x0c07947eu,0x0c079480u,0x0c079482u,0x0c079484u,0x0c079486u,0x0c079488u,
0x0c07948au,0x0c079f96u,0x0c079f98u,0x0c079f9au,0x0c079f9cu,0x0c079f9eu,0x0c079fa0u,0x0c079fa2u,0x0c079fa4u,0x0c079fa6u,0x0c079fa8u,0x0c079faau,0x0c079facu,0x0c079faeu,0x0c079fb0u,0x0c079fb2u,
0x0c079fb4u,0x0c079fb6u,0x0c079fb8u,0x0c079fbau,0x0c079fbcu,0x0c079fbeu,0x0c079fc0u,0x0c079fc2u,0x0c07a336u,0x0c07a338u,0x0c07a33au,0x0c07a33cu,0x0c07a4d8u,0x0c07a4dau,0x0c07a4dcu,0x0c07a4deu,
0x0c07a4e0u,0x0c07a4e2u,0x0c07a4e4u,0x0c07a4e6u,0x0c07a4e8u,0x0c07a4eau,0x0c07a4ecu,0x0c07a4eeu,0x0c07a4f0u,0x0c07a4f2u,0x0c07a4f4u,0x0c07a4f6u,0x0c07a4f8u,0x0c07a4fau,0x0c07a4fcu,0x0c07a4feu,
0x0c07a500u,0x0c07a502u,0x0c07a504u,0x0c07a506u,0x0c07a508u,0x0c07a50au,0x0c07a50cu,0x0c07a50eu,0x0c07a510u,0x0c07a512u,0x0c07a514u,0x0c07a516u,0x0c07a518u,0x0c07a6c4u,0x0c07a6c6u,0x0c07a6c8u,
0x0c07a6cau,0x0c07a6ccu,0x0c07a6ceu,0x0c07a6d0u,0x0c07a6d2u,0x0c07a6d4u,0x0c07a6d6u,0x0c07a6d8u,0x0c07a6dau,0x0c07a6dcu,0x0c07a6deu,0x0c07a6e0u,0x0c07a6e2u,0x0c07a6e4u,0x0c07a6e6u,0x0c07a6e8u,
0x0c07a6eau,0x0c07a6ecu,0x0c07a6eeu,0x0c07a6f0u,0x0c07a6f2u,0x0c07a6f4u,0x0c07a6f6u,0x0c07a6f8u,0x0c07a6fau,0x0c07a6fcu,0x0c07a6feu,0x0c07a700u,0x0c07a702u,0x0c07a704u,0x0c07a706u,0x0c07a708u,
0x0c07a70au,0x0c07a70cu,0x0c07a70eu,0x0c07a710u,0x0c07a712u,0x0c07a714u,0x0c07a716u,0x0c07a718u,0x0c07a71au,0x0c07a71cu,0x0c07a71eu,0x0c07a720u,0x0c07a722u,0x0c07a724u,0x0c07a726u,0x0c07a728u,
0x0c07a72au,0x0c07a72cu,0x0c07a72eu,0x0c07a730u,0x0c07a732u,0x0c07a734u,0x0c07a736u,0x0c07a738u,0x0c07a73au,0x0c07a73cu,0x0c07a73eu,0x0c07a740u,0x0c07a742u,0x0c07a744u,0x0c07a746u,0x0c07a748u,
0x0c07a74au,0x0c07a74cu,0x0c07a74eu,0x0c07a750u,0x0c07a752u,0x0c07a754u,0x0c07a756u,0x0c07a758u,0x0c07a782u,0x0c07a784u,0x0c07a786u,0x0c07a788u,0x0c07a78au,0x0c07a78cu,0x0c07a78eu,0x0c07b9a4u,
0x0c07b9a6u,0x0c07b9a8u,0x0c07b9aau,0x0c07b9acu,0x0c07b9aeu,0x0c07b9b0u,0x0c07b9b2u,0x0c07b9b4u,0x0c07b9b6u,0x0c07b9b8u,0x0c07b9bau,0x0c07b9bcu,0x0c07b9beu,0x0c07b9c0u,0x0c07b9c2u,0x0c07b9c4u,
0x0c07b9c6u,0x0c07b9c8u,0x0c07b9cau,0x0c07b9ccu,0x0c07b9ceu,0x0c07b9d0u,0x0c07b9d2u,0x0c07b9d4u,0x0c07b9d6u,0x0c07b9d8u,0x0c07b9dau,0x0c07b9dcu,0x0c07b9deu,0x0c07b9e0u,0x0c07b9e2u,0x0c07b9e4u,
0x0c07b9e6u,0x0c07b9e8u,0x0c07b9eau,0x0c07b9ecu,0x0c07b9eeu,0x0c07b9f0u,0x0c07b9f2u,0x0c07b9f4u,0x0c07b9f6u,0x0c07b9f8u,0x0c07b9fau,0x0c07b9fcu,0x0c07b9feu,0x0c07ba00u,0x0c07ba02u,0x0c07ba04u,
0x0c07ba06u,0x0c07ba08u,0x0c07ba28u,0x0c07ba2au,0x0c07ba2cu,0x0c07ba2eu,0x0c07ba30u,0x0c07ba32u,0x0c07ba34u,0x0c07ba36u,0x0c07ba38u,0x0c07ba3au,0x0c07ba3cu,0x0c07ba3eu,0x0c07ba40u,0x0c07ba42u,
0x0c07ba44u,0x0c07ba46u,0x0c07ba48u,0x0c07ba4au,0x0c07ba4cu,0x0c07ba4eu,0x0c07ba50u,0x0c07ba52u,0x0c07ba54u,0x0c07ba56u,0x0c07ba58u,0x0c07ba5au,0x0c07ba5cu,0x0c07ba5eu,0x0c07ba60u,0x0c07ba62u,
0x0c07ba64u,0x0c07ba66u,0x0c07ba68u,0x0c07ba6au,0x0c07ba6cu,0x0c07ba6eu,0x0c07ba70u,0x0c07ba72u,0x0c07ba74u,0x0c07ba76u,0x0c07ba78u,0x0c07ba7au,0x0c07ba7cu,0x0c07ba7eu,0x0c07ba80u,0x0c07ba82u,
0x0c07ba84u,0x0c07ba86u,0x0c07ba88u,0x0c07ba8au,0x0c07ba8cu,0x0c07ba8eu,0x0c07ba90u,0x0c07ba92u,0x0c07ba94u,0x0c07ba96u,0x0c07ba98u,0x0c07ba9au,0x0c07ba9cu,0x0c07ba9eu,0x0c07baa0u,0x0c07baa2u,
0x0c07baa4u,0x0c07baa6u,0x0c07baa8u,0x0c07baaau,0x0c07baacu,0x0c07baaeu,0x0c07bab0u,0x0c07bab2u,0x0c07bab4u,0x0c07bab6u,0x0c07bab8u,0x0c07babau,0x0c07babcu,0x0c07babeu,0x0c07bac0u,0x0c07bac2u,
0x0c07bac4u,0x0c07bac6u,0x0c07bac8u,0x0c07bacau,0x0c07baccu,0x0c07baceu,0x0c07bad0u,0x0c07bad2u,0x0c07bad4u,0x0c07bad6u,0x0c07bad8u,0x0c07badau,0x0c07badcu,0x0c07badeu,0x0c07bae0u,0x0c07bae2u,
0x0c07bae4u,0x0c07bae6u,0x0c07bae8u,0x0c07baeau,0x0c07baecu,0x0c07baeeu,0x0c07baf0u,0x0c07baf2u,0x0c07baf4u,0x0c07baf6u,0x0c07baf8u,0x0c07bafau,0x0c07bafcu,0x0c07bafeu,0x0c07bb00u,0x0c07bb02u,
0x0c07bb04u,0x0c07bb06u,0x0c07bb08u,0x0c07bb0au,0x0c07bb0cu,0x0c07bb0eu,0x0c07bb10u,0x0c07bb12u,0x0c07bb14u,0x0c07bb16u,0x0c07bb18u,0x0c07bb1au,0x0c07bb1cu,0x0c07bb1eu,0x0c07bb20u,0x0c07bb22u,
0x0c07bb24u,0x0c07bb26u,0x0c07bb28u,0x0c07bb2au,0x0c07bb2cu,0x0c07bb2eu,0x0c07bb30u,0x0c07bb32u,0x0c07bb34u,0x0c07bb36u,0x0c07bb38u,0x0c07bb3au,0x0c07bb3cu,0x0c07bb3eu,0x0c07bb40u,0x0c07bb42u,
0x0c07bb44u,0x0c07bb46u,0x0c07bba0u,0x0c07bba2u,0x0c07bba4u,0x0c07bba6u,0x0c07bba8u,0x0c07bbaau,0x0c07bbacu,0x0c07bbaeu,0x0c07bbb0u,0x0c07bbb2u,0x0c07bbb4u,0x0c07bbb6u,0x0c07bbb8u,0x0c07bbbau,
0x0c07bbbcu,0x0c07bbbeu,0x0c07bbc0u,0x0c07bbc2u,0x0c07bbc4u,0x0c07bbc6u,0x0c07bbc8u,0x0c07bbcau,0x0c07bbccu,0x0c07bbceu,0x0c07bbd0u,0x0c07bbd2u,0x0c07bbd4u,0x0c07bbd6u,0x0c07bbd8u,0x0c07bbdau,
0x0c07bbdcu,0x0c07bbdeu,0x0c07bbe0u,0x0c07bbe2u,0x0c07bbe4u,0x0c07bbe6u,0x0c07bbe8u,0x0c07bbeau,0x0c07bbecu,0x0c07bbeeu,0x0c07bbf0u,0x0c07bbf2u,0x0c07bbf4u,0x0c07bbf6u,0x0c07bbf8u,0x0c07bbfau,
0x0c07bbfcu,0x0c07bbfeu,0x0c07bc00u,0x0c07bc02u,0x0c07bc04u,0x0c07bc06u,0x0c07bc08u,0x0c07bc0au,0x0c07bc0cu,0x0c07bc0eu,0x0c07bc10u,0x0c07bc12u,0x0c07bc14u,0x0c07bc16u,0x0c07bc18u,0x0c07bc1au,
0x0c07bc1cu,0x0c07bc1eu,0x0c07bc20u,0x0c07bc22u,0x0c07bc24u,0x0c07bc26u,0x0c07bc28u,0x0c07bc2au,0x0c07bc2cu,0x0c07bc2eu,0x0c07bc30u,0x0c07bc32u,0x0c07bc34u,0x0c07bc36u,0x0c07bc38u,0x0c07bc3au,
0x0c07bc3cu,0x0c07bc3eu,0x0c07bc40u,0x0c07bc42u,0x0c07bc44u,0x0c07bc46u,0x0c07bc48u,0x0c07bc4au,0x0c07bc4cu,0x0c07bc4eu,0x0c07bc50u,0x0c07bc52u,0x0c07bc54u,0x0c07bc56u,0x0c07bc58u,0x0c07bc5au,
0x0c07bc5cu,0x0c07bc5eu,0x0c07bc60u,0x0c07bc62u,0x0c07bc64u,0x0c07bc66u,0x0c07bc68u,0x0c07bc6au,0x0c07bc6cu,0x0c07bc6eu,0x0c07bc70u,0x0c07bc72u,0x0c07bc74u,0x0c07bc76u,0x0c07bc78u,0x0c07bc7au,
0x0c07bc7cu,0x0c07bc7eu,0x0c07bc80u,0x0c07bc82u,0x0c07bc84u,0x0c07bc86u,0x0c07bc88u,0x0c07bc8au,0x0c07bc8cu,0x0c07bc8eu,0x0c07bc90u,0x0c07bc92u,0x0c07bc94u,0x0c07bc96u,0x0c07bc98u,0x0c07bc9au,
0x0c07bc9cu,0x0c07bc9eu,0x0c07bca0u,0x0c07bca2u,0x0c07bca4u,0x0c07bca6u,0x0c07bca8u,0x0c07bcaau,0x0c07bcacu,0x0c07bcaeu,0x0c07bcb0u,0x0c07bcb2u,0x0c07bcb4u,0x0c07bcb6u,0x0c07bcb8u,0x0c07bcbau,
0x0c07bcbcu,0x0c07bcbeu,0x0c07bcc0u,0x0c07bcc2u,0x0c07bcc4u,0x0c07bcc6u,0x0c07bcc8u,0x0c07bccau,0x0c07bcccu,0x0c07bcceu,0x0c07bcd0u,0x0c07bcd2u,0x0c07bcd4u,0x0c07bcd6u,0x0c07bcd8u,0x0c07bcdau,
0x0c07bcdcu,0x0c07bcdeu,0x0c07bce0u,0x0c07bce2u,0x0c07bce4u,0x0c07bce6u,0x0c07bce8u,0x0c07bceau,0x0c07bcecu,0x0c07bceeu,0x0c07bcf0u,0x0c07bcf2u,0x0c07bcf4u,0x0c07bcf6u,0x0c07bcf8u,0x0c07bd14u,
0x0c07bd16u,0x0c07bd18u,0x0c07bd1au,0x0c07bd1cu,0x0c07bd1eu,0x0c07bd20u,0x0c07bd22u,0x0c07bd24u,0x0c07bd26u,0x0c07bd28u,0x0c07bd2au,0x0c07bd2cu,0x0c07bd2eu,0x0c07bd30u,0x0c07bd32u,0x0c07bd34u,
0x0c07bd36u,0x0c07bd38u,0x0c07bd3au,0x0c07bd3cu,0x0c07bd3eu,0x0c07bd40u,0x0c07bd42u,0x0c07bd44u,0x0c07bd46u,0x0c07bd48u,0x0c07bd4au,0x0c07bd4cu,0x0c07bd4eu,0x0c07bd50u,0x0c07bd52u,0x0c07bd54u,
0x0c07bd56u,0x0c07bd58u,0x0c07bd5au,0x0c07bd5cu,0x0c07bd5eu,0x0c07bd60u,0x0c07bd62u,0x0c07bd64u,0x0c07bd66u,0x0c07bd68u,0x0c07bd6au,0x0c07bd6cu,0x0c07bd6eu,0x0c07bd70u,0x0c07bd72u,0x0c07bd74u,
0x0c07bd76u,0x0c07bd78u,0x0c07bd7au,0x0c07bd7cu,0x0c07bd7eu,0x0c07bd80u,0x0c07bd82u,0x0c07bd84u,0x0c07bd86u,0x0c07bd88u,0x0c07bd8au,0x0c07bd8cu,0x0c07bd8eu,0x0c07bd90u,0x0c07bd92u,0x0c07bd94u,
0x0c07bd96u,0x0c07bd98u,0x0c07bd9au,0x0c07bd9cu,0x0c07bd9eu,0x0c07bda0u,0x0c07bda2u,0x0c07bda4u,0x0c07bda6u,0x0c07bda8u,0x0c07bdaau,0x0c07bdacu,0x0c07bdaeu,0x0c07bdb0u,0x0c07bdb2u,0x0c07bdb4u,
0x0c07bdb6u,0x0c07bdb8u,0x0c07bdbau,0x0c07bdbcu,0x0c07bdbeu,0x0c07bdc0u,0x0c07bdc2u,0x0c07bdc4u,0x0c07bdc6u,0x0c07bdc8u,0x0c07bdcau,0x0c07bdccu,0x0c07bdceu,0x0c07bdd0u,0x0c07bdd2u,0x0c07bdd4u,
0x0c07bdd6u,0x0c07bdd8u,0x0c07bddau,0x0c07bddcu,0x0c07bddeu,0x0c07bde0u,0x0c07bde2u,0x0c07bde4u,0x0c07bde6u,0x0c07bde8u,0x0c07bdeau,0x0c07bdecu,0x0c07bdeeu,0x0c07bdf0u,0x0c07bdf2u,0x0c07bdf4u,
0x0c07bdf6u,0x0c07bdf8u,0x0c07bdfau,0x0c07bdfcu,0x0c07bdfeu,0x0c07be00u,0x0c07be02u,0x0c07be04u,0x0c07be06u,0x0c07be08u,0x0c07be0au,0x0c07be0cu,0x0c07be0eu,0x0c07be10u,0x0c07be12u,0x0c07be14u,
0x0c07be16u,0x0c07be18u,0x0c07be1au,0x0c07be1cu,0x0c07be1eu,0x0c07be20u,0x0c07be22u,0x0c07be24u,0x0c07be26u,0x0c07be28u,0x0c07be2au,0x0c07be2cu,0x0c07be2eu,0x0c07be30u,0x0c07be32u,0x0c07be34u,
0x0c07be36u,0x0c07be38u,0x0c07be3au,0x0c07be3cu,0x0c07be3eu,0x0c07be40u,0x0c07be42u,0x0c07be44u,0x0c07be46u,0x0c07be48u,0x0c07be4au,0x0c07be4cu,0x0c07be4eu,0x0c07be50u,0x0c07be52u,0x0c07be54u,
0x0c07be56u,0x0c07be58u,0x0c07be5au,0x0c07be5cu,0x0c07be5eu,0x0c07be60u,0x0c07be62u,0x0c07be64u,0x0c07be66u,0x0c07be68u,0x0c07be6au,0x0c07be6cu,0x0c07be6eu,0x0c07be70u,0x0c07be72u,0x0c07be74u,
0x0c07be76u,0x0c07be78u,0x0c07be7au,0x0c07be7cu,0x0c07be7eu,0x0c07be80u,0x0c07be82u,0x0c07be84u,0x0c07be86u,0x0c07be88u,0x0c07be8au,0x0c07be8cu,0x0c07be8eu,0x0c07be90u,0x0c07be92u,0x0c07be94u,
0x0c07be96u,0x0c07be98u,0x0c07be9au,0x0c07beb0u,0x0c07beb2u,0x0c07beb4u,0x0c07beb6u,0x0c07beb8u,0x0c07bebau,0x0c07bebcu,0x0c07bebeu,0x0c07bec0u,0x0c07bec2u,0x0c07bec4u,0x0c07bec6u,0x0c07bec8u,
0x0c07becau,0x0c07beccu,0x0c07beceu,0x0c07bed0u,0x0c07bed2u,0x0c07bed4u,0x0c07bed6u,0x0c07bed8u,0x0c07bedau,0x0c07bedcu,0x0c07bedeu,0x0c07bee0u,0x0c07bee2u,0x0c07bee4u,0x0c07bee6u,0x0c07bee8u,
0x0c07beeau,0x0c07beecu,0x0c07beeeu,0x0c07bef0u,0x0c07bef2u,0x0c07bef4u,0x0c07bef6u,0x0c07bef8u,0x0c07befau,0x0c07befcu,0x0c07befeu,0x0c07bf00u,0x0c07bf02u,0x0c07bf04u,0x0c07bf06u,0x0c07bf08u,
0x0c07bf0au,0x0c07bf0cu,0x0c07bf0eu,0x0c07bf10u,0x0c07bf12u,0x0c07bf14u,0x0c07bf16u,0x0c07bf18u,0x0c07bf1au,0x0c07bf1cu,0x0c07bf1eu,0x0c07bf20u,0x0c07bf22u,0x0c07bf24u,0x0c07bf26u,0x0c07bf28u,
0x0c07bf2au,0x0c07bf2cu,0x0c07bf2eu,0x0c07bf30u,0x0c07bf32u,0x0c07bf34u,0x0c07bf36u,0x0c07bf38u,0x0c07bf3au,0x0c07bf3cu,0x0c07bf3eu,0x0c07bf40u,0x0c07bf42u,0x0c07bf44u,0x0c07bf46u,0x0c07bf48u,
0x0c07bf4au,0x0c07bf4cu,0x0c07bf4eu,0x0c07bf50u,0x0c07bf52u,0x0c07bf54u,0x0c07bf56u,0x0c07bf58u,0x0c07bf5au,0x0c07bf5cu,0x0c07bf5eu,0x0c07bf60u,0x0c07bf62u,0x0c07bf64u,0x0c07bf66u,0x0c07bf68u,
0x0c07bf6au,0x0c07bf6cu,0x0c07bf6eu,0x0c07bf70u,0x0c07bf72u,0x0c07bf74u,0x0c07bf76u,0x0c07bf78u,0x0c07bf7au,0x0c07bf7cu,0x0c07bf7eu,0x0c07bf80u,0x0c07bf82u,0x0c07bf84u,0x0c07bf86u,0x0c07bf88u,
0x0c07bf8au,0x0c07bf8cu,0x0c07bf8eu,0x0c07bf90u,0x0c07bf92u,0x0c07bf94u,0x0c07bf96u,0x0c07bf98u,0x0c07bf9au,0x0c07bf9cu,0x0c07bf9eu,0x0c07bfa0u,0x0c07bfa2u,0x0c07bfa4u,0x0c07bfa6u,0x0c07bfa8u,
0x0c07bfaau,0x0c07bfacu,0x0c07bfaeu,0x0c07bfb0u,0x0c07bfb2u,0x0c07bfb4u,0x0c07bfb6u,0x0c07bfb8u,0x0c07bfbau,0x0c07bfbcu,0x0c07bfbeu,0x0c07bfc0u,0x0c07bfc2u,0x0c07bfc4u,0x0c07bfc6u,0x0c07bfc8u,
0x0c07bfcau,0x0c07bfccu,0x0c07bfceu,0x0c07bfd0u,0x0c07bfd2u,0x0c07bfd4u,0x0c07bfd6u,0x0c07bfd8u,0x0c07bfdau,0x0c07bfdcu,0x0c07bfdeu,0x0c07bfe0u,0x0c07bfe2u,0x0c07bfe4u,0x0c07bfe6u,0x0c07bfe8u,
0x0c07bfeau,0x0c07bfecu,0x0c07bfeeu,0x0c07bff0u,0x0c07bff2u,0x0c07bff4u,0x0c07bff6u,0x0c07bff8u,0x0c07bffau,0x0c07bffcu,0x0c07bffeu,0x0c07c000u,0x0c07c002u,0x0c07c004u,0x0c07c006u,0x0c07c008u,
0x0c07c00au,0x0c07c00cu,0x0c07c00eu,0x0c07c010u,0x0c07c012u,0x0c07c014u,0x0c07c016u,0x0c07c018u,0x0c07c01au,0x0c07c01cu,0x0c07c01eu,0x0c07c020u,0x0c07c022u,0x0c07c024u,0x0c07c026u,0x0c07c028u,
0x0c07c02au,0x0c07c02cu,0x0c07c02eu,0x0c07c030u,0x0c07c032u,0x0c07c034u,0x0c07c036u,0x0c07c038u,0x0c07c03au,0x0c07c03cu,0x0c07c03eu,0x0c07c040u,0x0c07c042u,0x0c07c05cu,0x0c07c05eu,0x0c07c060u,
0x0c07c062u,0x0c07c064u,0x0c07c066u,0x0c07c068u,0x0c07c06au,0x0c07c06cu,0x0c07c06eu,0x0c07c070u,0x0c07c072u,0x0c07c074u,0x0c07c076u,0x0c07c078u,0x0c07c07au,0x0c07c07cu,0x0c07c07eu,0x0c07c080u,
0x0c07c082u,0x0c07c084u,0x0c07c086u,0x0c07c088u,0x0c07c08au,0x0c07c08cu,0x0c07c08eu,0x0c07c090u,0x0c07c092u,0x0c07c094u,0x0c07c096u,0x0c07c098u,0x0c07c09au,0x0c07c09cu,0x0c07c09eu,0x0c07c0a0u,
0x0c07c0a2u,0x0c07c0a4u,0x0c07c0a6u,0x0c07c0a8u,0x0c07c0aau,0x0c07c0acu,0x0c07c0aeu,0x0c07c0b0u,0x0c07c0b2u,0x0c07c0b4u,0x0c07c0b6u,0x0c07c0b8u,0x0c07c0bau,0x0c07c0bcu,0x0c07c0beu,0x0c07c0c0u,
0x0c07c0c2u,0x0c07c0c4u,0x0c07c0c6u,0x0c07c0c8u,0x0c07c0cau,0x0c07c0ccu,0x0c07c0ceu,0x0c07c0d0u,0x0c07c0d2u,0x0c07c0d4u,0x0c07c0d6u,0x0c07c0d8u,0x0c07c0dau,0x0c07c0dcu,0x0c07c0deu,0x0c07c0e0u,
0x0c07c0e2u,0x0c07c0e4u,0x0c07c0e6u,0x0c07c0e8u,0x0c07c0eau,0x0c07c0ecu,0x0c07c0eeu,0x0c07c0f0u,0x0c07c0f2u,0x0c07c0f4u,0x0c07c0f6u,0x0c07c0f8u,0x0c07c0fau,0x0c07c0fcu,0x0c07c0feu,0x0c07c100u,
0x0c07c102u,0x0c07c12cu,0x0c07c12eu,0x0c07c130u,0x0c07c132u,0x0c07c134u,0x0c07c136u,0x0c07c138u,0x0c07c13au,0x0c07c13cu,0x0c07c13eu,0x0c07c140u,0x0c07c142u,0x0c07c144u,0x0c07c146u,0x0c07c148u,
0x0c07c14au,0x0c07c14cu,0x0c07c14eu,0x0c07c150u,0x0c07c152u,0x0c07c154u,0x0c07c156u,0x0c07c158u,0x0c07c15au,0x0c07c15cu,0x0c07c15eu,0x0c07c160u,0x0c07c162u,0x0c07c164u,0x0c07c166u,0x0c07c168u,
0x0c07c16au,0x0c07c16cu,0x0c07c16eu,0x0c07c170u,0x0c07c172u,0x0c07c174u,0x0c07c176u,0x0c07c178u,0x0c07c17au,0x0c07c17cu,0x0c07c17eu,0x0c07c180u,0x0c07c182u,0x0c07c184u,0x0c07c186u,0x0c07c188u,
0x0c07c18au,0x0c07c18cu,0x0c07c18eu,0x0c07c190u,0x0c07c192u,0x0c07c194u,0x0c07c196u,0x0c07c198u,0x0c07c19au,0x0c07c19cu,0x0c07c19eu,0x0c07c1a0u,0x0c07c1a2u,0x0c07c1a4u,0x0c07c1a6u,0x0c07c1a8u,
0x0c07c1aau,0x0c07c1acu,0x0c07c1aeu,0x0c07c1b0u,0x0c07c1b2u,0x0c07c1b4u,0x0c07c1b6u,0x0c07c1b8u,0x0c07c1bau,0x0c07c1bcu,0x0c07c1beu,0x0c07c1c0u,0x0c07c1c2u,0x0c07c1c4u,0x0c07c1c6u,0x0c07c1c8u,
0x0c07c1cau,0x0c07c1ccu,0x0c07c1ceu,0x0c07c1d0u,0x0c07c1d2u,0x0c07c1d4u,0x0c07c1d6u,0x0c07c1d8u,0x0c07c1dau,0x0c07c1dcu,0x0c07c1deu,0x0c07c1e0u,0x0c07c1e2u,0x0c07c1e4u,0x0c07c1e6u,0x0c07c1e8u,
0x0c07c1eau,0x0c07c1ecu,0x0c07c1eeu,0x0c07c1f0u,0x0c07c1f2u,0x0c07c1f4u,0x0c07c1f6u,0x0c07c1f8u,0x0c07c1fau,0x0c07c1fcu,0x0c07c1feu,0x0c07c200u,0x0c07c202u,0x0c07c204u,0x0c07c206u,0x0c07c208u,
0x0c07c20au,0x0c07c20cu,0x0c07c20eu,0x0c07c210u,0x0c07c212u,0x0c07c214u,0x0c07c216u,0x0c07c218u,0x0c07c21au,0x0c07c21cu,0x0c07c21eu,0x0c07c220u,0x0c07c222u,0x0c07c224u,0x0c07c226u,0x0c07c228u,
0x0c07c22au,0x0c07c22cu,0x0c07c22eu,0x0c07c230u,0x0c07c232u,0x0c07c234u,0x0c07c236u,0x0c07c238u,0x0c07c23au,0x0c07c23cu,0x0c07c23eu,0x0c07c240u,0x0c07c242u,0x0c07c244u,0x0c07c246u,0x0c07c248u,
0x0c07c24au,0x0c07c24cu,0x0c07c24eu,0x0c07c250u,0x0c07c252u,0x0c07c254u,0x0c07c256u,0x0c07c258u,0x0c07c25au,0x0c07c25cu,0x0c07c25eu,0x0c07c260u,0x0c07c262u,0x0c07c264u,0x0c07c266u,0x0c07c268u,
0x0c07c26au,0x0c07c26cu,0x0c07c26eu,0x0c07c270u,0x0c07c272u,0x0c07c274u,0x0c07c276u,0x0c07c278u,0x0c07c27au,0x0c07c27cu,0x0c07c27eu,0x0c07c280u,0x0c07c282u,0x0c07c284u,0x0c07c286u,0x0c07c288u,
0x0c07c28au,0x0c07c28cu,0x0c07c28eu,0x0c07c290u,0x0c07c292u,0x0c07c294u,0x0c07c296u,0x0c07c298u,0x0c07c29au,0x0c07c29cu,0x0c07c29eu,0x0c07c2a0u,0x0c07c2a2u,0x0c07c2a4u,0x0c07c2a6u,0x0c07c2a8u,
0x0c07c2aau,0x0c07c2acu,0x0c07c2aeu,0x0c07c2b0u,0x0c07c2b2u,0x0c07c2b4u,0x0c07c2d0u,0x0c07c2d2u,0x0c07c2d4u,0x0c07c2d6u,0x0c07c2d8u,0x0c07c2dau,0x0c07c2dcu,0x0c07c2deu,0x0c07c2e0u,0x0c07c2e2u,
0x0c07c2e4u,0x0c07c2e6u,0x0c07c2e8u,0x0c07c2eau,0x0c07c2ecu,0x0c07c2eeu,0x0c07c2f0u,0x0c07c2f2u,0x0c07c2f4u,0x0c07c2f6u,0x0c07c2f8u,0x0c07c2fau,0x0c07c2fcu,0x0c07c2feu,0x0c07c300u,0x0c07c302u,
0x0c07c304u,0x0c07c306u,0x0c07c308u,0x0c07c30au,0x0c07c30cu,0x0c07c30eu,0x0c07c310u,0x0c07c312u,0x0c07c314u,0x0c07c316u,0x0c07c318u,0x0c07c31au,0x0c07c31cu,0x0c07c31eu,0x0c07c320u,0x0c07c322u,
0x0c07c324u,0x0c07c326u,0x0c07c328u,0x0c07c32au,0x0c07c32cu,0x0c07c32eu,0x0c07c330u,0x0c07c332u,0x0c07c8cau,0x0c07c8ccu,0x0c07c8ceu,0x0c07c8d0u,0x0c07c8d2u,0x0c07c8d4u,0x0c07c8d6u,0x0c07c8d8u,
0x0c07c8dau,0x0c07c8dcu,0x0c07c8deu,0x0c07c8e0u,0x0c07c8e2u,0x0c07c8e4u,0x0c07c8e6u,0x0c07c8e8u,0x0c07c8eau,0x0c07c8ecu,0x0c07c8eeu,0x0c07c8f0u,0x0c07c8f2u,0x0c07c8f4u,0x0c07c8f6u,0x0c07c8f8u,
0x0c07c8fau,0x0c07c8fcu,0x0c07c8feu,0x0c07c900u,0x0c07c902u,0x0c07c904u,0x0c07c906u,0x0c07c908u,0x0c07c90au,0x0c07c90cu,0x0c07c90eu,0x0c07c910u,0x0c07c912u,0x0c07c914u,0x0c07c916u,0x0c07c918u,
0x0c07c91au,0x0c07c91cu,0x0c07c91eu,0x0c07c920u,0x0c07c922u,0x0c07c924u,0x0c07c926u,0x0c07c928u,0x0c07c92au,0x0c07c92cu,0x0c07c968u,0x0c07c96au,0x0c07c96cu,0x0c07c96eu,0x0c07c970u,0x0c07c972u,
0x0c07c974u,0x0c07c976u,0x0c07c978u,0x0c07c97au,0x0c07c97cu,0x0c07c97eu,0x0c07c980u,0x0c07c982u,0x0c07c984u,0x0c07c986u,0x0c07c988u,0x0c07c98au,0x0c07c98cu,0x0c07c98eu,0x0c07c990u,0x0c07c992u,
0x0c07c994u,0x0c07c996u,0x0c07c998u,0x0c07c9d4u,0x0c07c9d6u,0x0c07c9d8u,0x0c07c9dau,0x0c07c9dcu,0x0c07c9deu,0x0c07c9e0u,0x0c07c9e2u,0x0c07c9e4u,0x0c08944cu,0x0c08944eu,0x0c089450u,0x0c089452u,
0x0c089454u,0x0c089456u,0x0c089458u,0x0c08945au,0x0c08945cu,0x0c08945eu,0x0c089460u,0x0c089462u,0x0c089464u,0x0c089466u,0x0c089468u,0x0c08946au,0x0c08946cu,0x0c08946eu,0x0c089470u,0x0c089472u,
0x0c089474u,0x0c089476u,0x0c089478u,0x0c08947au,0x0c08947cu,0x0c08947eu,0x0c089480u,0x0c089482u,0x0c089484u,0x0c089486u,0x0c089488u,0x0c08948au,0x0c08948cu,0x0c08948eu,0x0c089490u,0x0c089492u,
0x0c089494u,0x0c089496u,0x0c089498u,0x0c08949au,0x0c08949cu,0x0c08949eu,0x0c0894a0u,0x0c0894a2u,0x0c0894a4u,0x0c0894a6u,0x0c0894a8u,0x0c0894aau,0x0c0894acu,0x0c0894aeu,0x0c0894b0u,0x0c0894b2u,
0x0c0894b4u,0x0c0894b6u,0x0c0894b8u,0x0c0894bau,0x0c0894bcu,0x0c0894beu,0x0c0894c0u,0x0c0894c2u,0x0c0894c4u,0x0c0894c6u,0x0c0894c8u,0x0c0894cau,0x0c0894ccu,0x0c0894ceu,0x0c0894d0u,0x0c0894d2u,
0x0c0894d4u,0x0c0894d6u,0x0c08b7eau,0x0c08b7ecu,0x0c08b7eeu,0x0c08b7f0u,0x0c08b7f2u,0x0c08b7f4u,0x0c08b7f6u,0x0c08b7f8u,0x0c08b7fau,0x0c08b7fcu,0x0c08b7feu,0x0c08b800u,0x0c08b802u,0x0c08b804u,
0x0c08b806u,0x0c08b808u,0x0c08b80au,0x0c08b80cu,0x0c08b80eu,0x0c08b810u,0x0c08b812u,0x0c08b814u,0x0c08b816u,0x0c08b818u,0x0c08b81au,0x0c08b81cu,0x0c08b81eu,0x0c08b820u,0x0c08b822u,0x0c08b824u,
0x0c08b826u,0x0c08b828u,0x0c08b82au,0x0c08b82cu,0x0c08b82eu,0x0c08b830u,0x0c08b832u,0x0c08b834u,0x0c08b836u,0x0c08b838u,0x0c08b83au,0x0c08b83cu,0x0c08b83eu,0x0c08b840u,0x0c08b842u,0x0c08b844u,
0x0c08b846u,0x0c08b848u,0x0c08b84au,0x0c08b84cu,0x0c08b84eu,0x0c08b850u,0x0c08b852u,0x0c08b854u,0x0c08b856u,0x0c08b858u,0x0c08b85au,0x0c08b85cu,0x0c08b85eu,0x0c08b860u,0x0c08b862u,0x0c08b864u,
0x0c08b866u,0x0c08b868u,0x0c08b86au,0x0c08b86cu,0x0c08b86eu,0x0c08b870u,0x0c08b872u,0x0c08b874u,0x0c08b876u,0x0c08b878u,0x0c08b87au,0x0c08b87cu,0x0c08b87eu,0x0c08b880u,0x0c08b882u,0x0c08b884u,
0x0c08b886u,0x0c08b888u,0x0c091c20u,0x0c091c22u,0x0c091c24u,0x0c091c26u,0x0c091c28u,0x0c091c2au,0x0c091c2cu,0x0c091c2eu,0x0c091c30u,0x0c091c32u,0x0c091c34u,0x0c091c36u,0x0c091c38u,0x0c091c3au,
0x0c091c3cu,0x0c091c3eu,0x0c091c40u,0x0c091c42u,0x0c091c44u,0x0c091c46u,0x0c091c48u,0x0c091c4au,0x0c091c4cu,0x0c091c4eu,0x0c091c50u,0x0c091c52u,0x0c091c54u,0x0c091c56u,0x0c091c58u,0x0c091c5au,
0x0c091c5cu,0x0c091c5eu,0x0c091c60u,0x0c091c62u,0x0c091c64u,0x0c091c66u,0x0c091c68u,0x0c091c6au,0x0c091c6cu,0x0c091c6eu,0x0c091c70u,0x0c091c72u,0x0c091c74u,0x0c091c76u,0x0c091c78u,0x0c091c7au,
0x0c091c7cu,0x0c091c7eu,0x0c091c80u,0x0c091c82u,0x0c091c84u,0x0c091c86u,0x0c091c88u,0x0c091c8au,0x0c091c8cu,0x0c091c8eu,0x0c091c90u,0x0c091c92u,0x0c091c94u,0x0c091c96u,0x0c091c98u,0x0c091c9au,
0x0c091c9cu,0x0c091c9eu,0x0c091ca0u,0x0c091ca2u,0x0c091ca4u,0x0c091ca6u,0x0c091ca8u,0x0c091caau,0x0c091cacu,0x0c091caeu,0x0c091cb0u,0x0c091cb2u,0x0c091cb4u,0x0c091cb6u,0x0c091cb8u,0x0c091cbau,
0x0c091cbcu,0x0c091cbeu,0x0c091cc0u,0x0c091cc2u,0x0c091cc4u,0x0c091cc6u,0x0c091cc8u,0x0c091ccau,0x0c091cccu,0x0c091cceu,0x0c091cd0u,0x0c091cd2u,0x0c091cd4u,0x0c091cd6u,0x0c091cd8u,0x0c091cdau,
0x0c091cdcu,0x0c091cdeu,0x0c091ce0u,0x0c091ce2u,0x0c091ce4u,0x0c091ce6u,0x0c091ce8u,0x0c091ceau,0x0c091cecu,0x0c091ceeu,0x0c091cf0u,0x0c091cf2u,0x0c091cf4u,0x0c091cf6u,0x0c091cf8u,0x0c091cfau,
0x0c091cfcu,0x0c091cfeu,0x0c091d00u,0x0c091d02u,0x0c091d04u,0x0c091d06u,0x0c091d08u,0x0c091d0au,0x0c091d0cu,0x0c091d0eu,0x0c091d10u,0x0c091d12u,0x0c091d14u,0x0c091d16u,0x0c091d18u,0x0c091d1au,
0x0c091d1cu,0x0c091d1eu,0x0c091d20u,0x0c091d22u,0x0c091d24u,0x0c091d26u,0x0c091d28u,0x0c091d2au,0x0c091d2cu,0x0c091d2eu,0x0c091d30u,0x0c091d32u,0x0c091d34u,0x0c091d36u,0x0c091d38u,0x0c091d3au,
0x0c091d3cu,0x0c091d3eu,0x0c091d40u,0x0c091d42u,0x0c091d44u,0x0c091d46u,0x0c091d48u,0x0c091d4au,0x0c091d4cu,0x0c091d4eu,0x0c091d50u,0x0c091d52u,0x0c091d54u,0x0c091d56u,0x0c091d58u,0x0c091d5au,
0x0c091d5cu,0x0c091d5eu,0x0c091d60u,0x0c091d62u,0x0c091d64u,0x0c091d66u,0x0c091d68u,0x0c091d6au,0x0c091d98u,0x0c091d9au,0x0c091d9cu,0x0c091d9eu,0x0c091da0u,0x0c091da2u,0x0c091da4u,0x0c091da6u,
0x0c091da8u,0x0c091daau,0x0c091dacu,0x0c091daeu,0x0c091db0u,0x0c091db2u,0x0c091db4u,0x0c091db6u,0x0c091db8u,0x0c091dbau,0x0c091dbcu,0x0c092268u,0x0c09226au,0x0c09226cu,0x0c09226eu,0x0c092270u,
0x0c092272u,0x0c092274u,0x0c092276u,0x0c092278u,0x0c09227au,0x0c09227cu,0x0c09227eu,0x0c092280u,0x0c092282u,0x0c092284u,0x0c092286u,0x0c092288u,0x0c09228au,0x0c09228cu,0x0c09228eu,0x0c092290u,
0x0c092292u,0x0c0a80b0u,0x0c0a80b2u,0x0c0a80b4u,0x0c0a80b6u,0x0c0a80b8u,0x0c0a80bau,0x0c0a80bcu,0x0c0a80beu,0x0c0a80c0u,0x0c0a80c2u,0x0c0a80c4u,0x0c0a80c6u,0x0c0a80c8u,0x0c0a80cau,0x0c0a80ccu,
0x0c0a80ceu,0x0c0a80d0u,0x0c0a80d2u,0x0c0a80d4u,0x0c0a80d6u,0x0c0a80d8u,0x0c0a80dau,0x0c0a80dcu,0x0c0a80deu,0x0c0a80e0u,0x0c0a80e2u,0x0c0a80e4u,0x0c0a80e6u,0x0c0a80e8u,0x0c0a80eau,0x0c0a80ecu,
0x0c0a80eeu,0x0c0a80f0u,0x0c0a80f2u,0x0c0a80f4u,0x0c0a80f6u,0x0c0a80f8u,0x0c0a80fau,0x0c0a80fcu,0x0c0a80feu,0x0c0a8100u,0x0c0a8102u,0x0c0a8104u,0x0c0a8106u,0x0c0a8108u,0x0c0a810au,0x0c0a810cu,
0x0c0a810eu,0x0c0a8110u,0x0c0a8112u,0x0c0a8114u,0x0c0a8116u,0x0c0a8118u,0x0c0a811au,0x0c0a811cu,0x0c0a811eu,0x0c0a8120u,0x0c0a8122u,0x0c0a8124u,0x0c0a8126u,0x0c0a8128u,0x0c0a812au,0x0c0a812cu,
0x0c0a812eu,0x0c0a8130u,0x0c0a8132u,0x0c0a8134u,0x0c0a8136u,0x0c0a8138u,0x0c0a813au,0x0c0a813cu,0x0c0a813eu,0x0c0a8140u,0x0c0a8142u,0x0c0a8144u,0x0c0a8146u,0x0c0a8148u,0x0c0a814au,0x0c0a814cu,
0x0c0a814eu,0x0c0a8150u,0x0c0a8152u,0x0c0a8154u,0x0c0a8156u,0x0c0a8158u,0x0c0a815au,0x0c0a815cu,0x0c0a815eu,0x0c0a8160u,0x0c0a8162u,0x0c0a8164u,0x0c0a8166u,0x0c0a8168u,0x0c0a816au,0x0c0a816cu,
0x0c0a816eu,0x0c0a8170u,0x0c0a8172u,0x0c0a818cu,0x0c0a818eu,0x0c0a8190u,0x0c0a8192u,0x0c0a8194u,0x0c0a8196u,0x0c0a8198u,0x0c0a819au,0x0c0a819cu,0x0c0a819eu,0x0c0a81a0u,0x0c0a81a2u,0x0c0a81a4u,
0x0c0a81a6u,0x0c0a81a8u,0x0c0a81aau,0x0c0a81acu,0x0c0a81aeu,0x0c0a81b0u,0x0c0a81b2u,0x0c0a81b4u,0x0c0a81b6u,0x0c0a81b8u,0x0c0a81bau,0x0c0a81bcu,0x0c0a81beu,0x0c0a81c0u,0x0c0a81c2u,0x0c0a81c4u,
0x0c0a81c6u,0x0c0a81c8u,0x0c0a81cau,0x0c0a81ccu,0x0c0a81ceu,0x0c0a81d0u,0x0c0a81d2u,0x0c0a81d4u,0x0c0a81d6u,0x0c0a81d8u,0x0c0a81dau,0x0c0a81dcu,0x0c0a81deu,0x0c0a81e0u,0x0c0a81e2u,0x0c0a81e4u,
0x0c0a81e6u,0x0c0a81e8u,0x0c0a81eau,0x0c0a81ecu,0x0c0c2b60u,0x0c0c2b62u,0x0c0c2b64u,0x0c0c2b66u,0x0c0c2b68u,0x0c0c2b6au,0x0c0c2b6cu,0x0c0c2b6eu,0x0c0c2b70u,0x0c0c2b72u,0x0c0c2b74u,0x0c0c2b76u,
0x0c0c2b78u,0x0c0c2b7au,0x0c0c2b7cu,0x0c0c2b7eu,
};
int vf3_tickgap_adapter_contains(uint32_t pc) {
pc&=0x1fffffffu; unsigned lo=0,hi=sizeof(owned_pcs)/sizeof(owned_pcs[0]);
while(lo<hi) { unsigned mid=lo+(hi-lo)/2; if(owned_pcs[mid]<pc) lo=mid+1; else hi=mid; }
return lo<sizeof(owned_pcs)/sizeof(owned_pcs[0]) && owned_pcs[lo]==pc;
}
