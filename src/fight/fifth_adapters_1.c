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
int vf3_fifth_adapter_1(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c06ef4au: goto P_0c06ef4a;
case 0x0c06ef4cu: goto P_0c06ef4c;
case 0x0c06ef4eu: goto P_0c06ef4e;
case 0x0c06ef50u: goto P_0c06ef50;
case 0x0c06ef52u: goto P_0c06ef52;
case 0x0c06ef54u: goto P_0c06ef54;
case 0x0c06ef56u: goto P_0c06ef56;
case 0x0c06ef58u: goto P_0c06ef58;
case 0x0c06ef5au: goto P_0c06ef5a;
case 0x0c06ef5cu: goto P_0c06ef5c;
case 0x0c06ef5eu: goto P_0c06ef5e;
case 0x0c06ef60u: goto P_0c06ef60;
case 0x0c06ef62u: goto P_0c06ef62;
case 0x0c06ef64u: goto P_0c06ef64;
case 0x0c06ef66u: goto P_0c06ef66;
case 0x0c06ef68u: goto P_0c06ef68;
case 0x0c06ef6au: goto P_0c06ef6a;
case 0x0c06ef6cu: goto P_0c06ef6c;
case 0x0c06ef6eu: goto P_0c06ef6e;
case 0x0c06ef70u: goto P_0c06ef70;
case 0x0c06ef72u: goto P_0c06ef72;
case 0x0c06ef74u: goto P_0c06ef74;
case 0x0c06ef76u: goto P_0c06ef76;
case 0x0c06ef78u: goto P_0c06ef78;
case 0x0c06ef7au: goto P_0c06ef7a;
case 0x0c06ef7cu: goto P_0c06ef7c;
case 0x0c06ef7eu: goto P_0c06ef7e;
case 0x0c06ef80u: goto P_0c06ef80;
case 0x0c06ef82u: goto P_0c06ef82;
case 0x0c06ef84u: goto P_0c06ef84;
case 0x0c06ef86u: goto P_0c06ef86;
case 0x0c06ef88u: goto P_0c06ef88;
case 0x0c06ef8au: goto P_0c06ef8a;
case 0x0c06ef8cu: goto P_0c06ef8c;
case 0x0c06ef8eu: goto P_0c06ef8e;
case 0x0c06ef90u: goto P_0c06ef90;
case 0x0c06ef92u: goto P_0c06ef92;
case 0x0c06ef94u: goto P_0c06ef94;
case 0x0c06ef96u: goto P_0c06ef96;
case 0x0c06ef98u: goto P_0c06ef98;
case 0x0c06ef9au: goto P_0c06ef9a;
case 0x0c06ef9cu: goto P_0c06ef9c;
case 0x0c06ef9eu: goto P_0c06ef9e;
case 0x0c06efa0u: goto P_0c06efa0;
case 0x0c06efa2u: goto P_0c06efa2;
case 0x0c06efa4u: goto P_0c06efa4;
case 0x0c06efa6u: goto P_0c06efa6;
case 0x0c06efa8u: goto P_0c06efa8;
case 0x0c06efaau: goto P_0c06efaa;
case 0x0c06efacu: goto P_0c06efac;
case 0x0c06efaeu: goto P_0c06efae;
case 0x0c06efb0u: goto P_0c06efb0;
case 0x0c06efb2u: goto P_0c06efb2;
case 0x0c06efb4u: goto P_0c06efb4;
case 0x0c06efb6u: goto P_0c06efb6;
case 0x0c06efb8u: goto P_0c06efb8;
case 0x0c06efbau: goto P_0c06efba;
case 0x0c06efbcu: goto P_0c06efbc;
case 0x0c06efbeu: goto P_0c06efbe;
case 0x0c06efc0u: goto P_0c06efc0;
case 0x0c06efc2u: goto P_0c06efc2;
case 0x0c06efc4u: goto P_0c06efc4;
case 0x0c06efc6u: goto P_0c06efc6;
case 0x0c06efc8u: goto P_0c06efc8;
case 0x0c06efcau: goto P_0c06efca;
case 0x0c06efccu: goto P_0c06efcc;
case 0x0c06efceu: goto P_0c06efce;
case 0x0c06efd0u: goto P_0c06efd0;
case 0x0c06efd2u: goto P_0c06efd2;
case 0x0c06efd4u: goto P_0c06efd4;
case 0x0c06efd6u: goto P_0c06efd6;
case 0x0c06efd8u: goto P_0c06efd8;
case 0x0c06efdau: goto P_0c06efda;
case 0x0c06efdcu: goto P_0c06efdc;
case 0x0c06efdeu: goto P_0c06efde;
case 0x0c06efe0u: goto P_0c06efe0;
case 0x0c06efe2u: goto P_0c06efe2;
case 0x0c06efe4u: goto P_0c06efe4;
case 0x0c06efe6u: goto P_0c06efe6;
case 0x0c06efe8u: goto P_0c06efe8;
case 0x0c06efeau: goto P_0c06efea;
case 0x0c06efecu: goto P_0c06efec;
case 0x0c06efeeu: goto P_0c06efee;
case 0x0c06eff0u: goto P_0c06eff0;
case 0x0c06eff2u: goto P_0c06eff2;
case 0x0c06eff4u: goto P_0c06eff4;
case 0x0c06eff6u: goto P_0c06eff6;
case 0x0c06eff8u: goto P_0c06eff8;
case 0x0c06effau: goto P_0c06effa;
case 0x0c06effcu: goto P_0c06effc;
case 0x0c06effeu: goto P_0c06effe;
case 0x0c06f000u: goto P_0c06f000;
case 0x0c06f002u: goto P_0c06f002;
case 0x0c06f004u: goto P_0c06f004;
case 0x0c06f006u: goto P_0c06f006;
case 0x0c06f008u: goto P_0c06f008;
case 0x0c06f00au: goto P_0c06f00a;
case 0x0c06f00cu: goto P_0c06f00c;
case 0x0c06f00eu: goto P_0c06f00e;
case 0x0c06f010u: goto P_0c06f010;
case 0x0c06f012u: goto P_0c06f012;
case 0x0c06f014u: goto P_0c06f014;
case 0x0c06f016u: goto P_0c06f016;
case 0x0c06f018u: goto P_0c06f018;
case 0x0c06f01au: goto P_0c06f01a;
case 0x0c06f01cu: goto P_0c06f01c;
case 0x0c06f01eu: goto P_0c06f01e;
case 0x0c06f020u: goto P_0c06f020;
case 0x0c06f022u: goto P_0c06f022;
case 0x0c06f024u: goto P_0c06f024;
case 0x0c06f026u: goto P_0c06f026;
case 0x0c06f028u: goto P_0c06f028;
case 0x0c06f02au: goto P_0c06f02a;
case 0x0c06f02cu: goto P_0c06f02c;
case 0x0c06f02eu: goto P_0c06f02e;
case 0x0c06f030u: goto P_0c06f030;
case 0x0c06f032u: goto P_0c06f032;
case 0x0c06f034u: goto P_0c06f034;
case 0x0c06f036u: goto P_0c06f036;
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
case 0x0c074930u: goto P_0c074930;
case 0x0c074932u: goto P_0c074932;
case 0x0c074934u: goto P_0c074934;
case 0x0c074936u: goto P_0c074936;
case 0x0c074938u: goto P_0c074938;
case 0x0c07493au: goto P_0c07493a;
case 0x0c07493cu: goto P_0c07493c;
case 0x0c07493eu: goto P_0c07493e;
case 0x0c074940u: goto P_0c074940;
case 0x0c074942u: goto P_0c074942;
case 0x0c074944u: goto P_0c074944;
case 0x0c074946u: goto P_0c074946;
case 0x0c074948u: goto P_0c074948;
case 0x0c07494au: goto P_0c07494a;
case 0x0c07494cu: goto P_0c07494c;
case 0x0c07494eu: goto P_0c07494e;
case 0x0c074950u: goto P_0c074950;
case 0x0c074952u: goto P_0c074952;
case 0x0c074954u: goto P_0c074954;
case 0x0c074956u: goto P_0c074956;
case 0x0c074958u: goto P_0c074958;
case 0x0c07495au: goto P_0c07495a;
case 0x0c07495cu: goto P_0c07495c;
case 0x0c07495eu: goto P_0c07495e;
case 0x0c074960u: goto P_0c074960;
case 0x0c074962u: goto P_0c074962;
case 0x0c074964u: goto P_0c074964;
case 0x0c074966u: goto P_0c074966;
case 0x0c074968u: goto P_0c074968;
case 0x0c07496au: goto P_0c07496a;
case 0x0c07496cu: goto P_0c07496c;
case 0x0c07496eu: goto P_0c07496e;
case 0x0c074970u: goto P_0c074970;
case 0x0c074972u: goto P_0c074972;
case 0x0c074974u: goto P_0c074974;
case 0x0c074976u: goto P_0c074976;
case 0x0c074978u: goto P_0c074978;
case 0x0c07497au: goto P_0c07497a;
case 0x0c07497cu: goto P_0c07497c;
case 0x0c07497eu: goto P_0c07497e;
case 0x0c074980u: goto P_0c074980;
case 0x0c074982u: goto P_0c074982;
case 0x0c074984u: goto P_0c074984;
case 0x0c074986u: goto P_0c074986;
case 0x0c074988u: goto P_0c074988;
case 0x0c07498au: goto P_0c07498a;
case 0x0c07498cu: goto P_0c07498c;
case 0x0c07498eu: goto P_0c07498e;
case 0x0c074990u: goto P_0c074990;
case 0x0c074992u: goto P_0c074992;
case 0x0c074994u: goto P_0c074994;
case 0x0c074996u: goto P_0c074996;
case 0x0c074998u: goto P_0c074998;
case 0x0c07499au: goto P_0c07499a;
case 0x0c07499cu: goto P_0c07499c;
case 0x0c07499eu: goto P_0c07499e;
case 0x0c0749ccu: goto P_0c0749cc;
case 0x0c0749ceu: goto P_0c0749ce;
case 0x0c0749d0u: goto P_0c0749d0;
case 0x0c0749d2u: goto P_0c0749d2;
case 0x0c0749d4u: goto P_0c0749d4;
case 0x0c0749d6u: goto P_0c0749d6;
case 0x0c0749d8u: goto P_0c0749d8;
case 0x0c0749dau: goto P_0c0749da;
case 0x0c0749dcu: goto P_0c0749dc;
case 0x0c0749deu: goto P_0c0749de;
case 0x0c0749e0u: goto P_0c0749e0;
case 0x0c0749e2u: goto P_0c0749e2;
case 0x0c0749e4u: goto P_0c0749e4;
case 0x0c0749e6u: goto P_0c0749e6;
case 0x0c0749e8u: goto P_0c0749e8;
case 0x0c0749eau: goto P_0c0749ea;
case 0x0c0749ecu: goto P_0c0749ec;
case 0x0c0749eeu: goto P_0c0749ee;
case 0x0c0749f0u: goto P_0c0749f0;
case 0x0c0749f2u: goto P_0c0749f2;
case 0x0c0749f4u: goto P_0c0749f4;
case 0x0c0749f6u: goto P_0c0749f6;
case 0x0c0749f8u: goto P_0c0749f8;
case 0x0c0749fau: goto P_0c0749fa;
case 0x0c0749fcu: goto P_0c0749fc;
case 0x0c0749feu: goto P_0c0749fe;
case 0x0c074a00u: goto P_0c074a00;
case 0x0c074a02u: goto P_0c074a02;
case 0x0c074a04u: goto P_0c074a04;
case 0x0c074a06u: goto P_0c074a06;
case 0x0c074a08u: goto P_0c074a08;
case 0x0c074a0au: goto P_0c074a0a;
case 0x0c074a0cu: goto P_0c074a0c;
case 0x0c074a0eu: goto P_0c074a0e;
case 0x0c074a10u: goto P_0c074a10;
case 0x0c074a12u: goto P_0c074a12;
case 0x0c074a14u: goto P_0c074a14;
case 0x0c074a16u: goto P_0c074a16;
case 0x0c074a18u: goto P_0c074a18;
case 0x0c074a1au: goto P_0c074a1a;
case 0x0c074a1cu: goto P_0c074a1c;
case 0x0c074a1eu: goto P_0c074a1e;
case 0x0c074a20u: goto P_0c074a20;
case 0x0c074a22u: goto P_0c074a22;
case 0x0c074a24u: goto P_0c074a24;
case 0x0c074a26u: goto P_0c074a26;
case 0x0c074a28u: goto P_0c074a28;
case 0x0c074a2au: goto P_0c074a2a;
case 0x0c074a2cu: goto P_0c074a2c;
case 0x0c074b0eu: goto P_0c074b0e;
case 0x0c074b10u: goto P_0c074b10;
case 0x0c074b12u: goto P_0c074b12;
case 0x0c074b14u: goto P_0c074b14;
case 0x0c074b16u: goto P_0c074b16;
case 0x0c074b18u: goto P_0c074b18;
case 0x0c074b1au: goto P_0c074b1a;
case 0x0c074b1cu: goto P_0c074b1c;
case 0x0c074b1eu: goto P_0c074b1e;
case 0x0c074b20u: goto P_0c074b20;
case 0x0c074b22u: goto P_0c074b22;
case 0x0c074b24u: goto P_0c074b24;
case 0x0c074b26u: goto P_0c074b26;
case 0x0c074b28u: goto P_0c074b28;
case 0x0c074b2au: goto P_0c074b2a;
case 0x0c074b2cu: goto P_0c074b2c;
case 0x0c074b2eu: goto P_0c074b2e;
case 0x0c074b30u: goto P_0c074b30;
case 0x0c074b32u: goto P_0c074b32;
case 0x0c074b34u: goto P_0c074b34;
case 0x0c074b36u: goto P_0c074b36;
case 0x0c074b38u: goto P_0c074b38;
case 0x0c074b3au: goto P_0c074b3a;
case 0x0c074b3cu: goto P_0c074b3c;
case 0x0c074b3eu: goto P_0c074b3e;
case 0x0c074b40u: goto P_0c074b40;
case 0x0c074b42u: goto P_0c074b42;
case 0x0c074b44u: goto P_0c074b44;
case 0x0c074b46u: goto P_0c074b46;
case 0x0c074b48u: goto P_0c074b48;
case 0x0c074b4au: goto P_0c074b4a;
case 0x0c074b4cu: goto P_0c074b4c;
case 0x0c074b4eu: goto P_0c074b4e;
case 0x0c074b50u: goto P_0c074b50;
case 0x0c074b52u: goto P_0c074b52;
case 0x0c074b54u: goto P_0c074b54;
case 0x0c074b56u: goto P_0c074b56;
case 0x0c074b58u: goto P_0c074b58;
case 0x0c074b5au: goto P_0c074b5a;
case 0x0c074b5cu: goto P_0c074b5c;
case 0x0c074b5eu: goto P_0c074b5e;
case 0x0c074b60u: goto P_0c074b60;
case 0x0c074b62u: goto P_0c074b62;
case 0x0c074b64u: goto P_0c074b64;
case 0x0c074b66u: goto P_0c074b66;
case 0x0c074b68u: goto P_0c074b68;
case 0x0c074b6au: goto P_0c074b6a;
case 0x0c074b6cu: goto P_0c074b6c;
case 0x0c074b6eu: goto P_0c074b6e;
case 0x0c074b70u: goto P_0c074b70;
case 0x0c074b72u: goto P_0c074b72;
case 0x0c074b74u: goto P_0c074b74;
case 0x0c074b76u: goto P_0c074b76;
case 0x0c074b78u: goto P_0c074b78;
case 0x0c074b7au: goto P_0c074b7a;
case 0x0c074b7cu: goto P_0c074b7c;
case 0x0c074b7eu: goto P_0c074b7e;
case 0x0c074b80u: goto P_0c074b80;
case 0x0c074b82u: goto P_0c074b82;
case 0x0c074b84u: goto P_0c074b84;
case 0x0c074b86u: goto P_0c074b86;
case 0x0c074b88u: goto P_0c074b88;
case 0x0c074b8au: goto P_0c074b8a;
case 0x0c074b8cu: goto P_0c074b8c;
case 0x0c074b8eu: goto P_0c074b8e;
case 0x0c074b90u: goto P_0c074b90;
case 0x0c074b92u: goto P_0c074b92;
case 0x0c074b94u: goto P_0c074b94;
case 0x0c074b96u: goto P_0c074b96;
case 0x0c074b98u: goto P_0c074b98;
case 0x0c074b9au: goto P_0c074b9a;
case 0x0c074b9cu: goto P_0c074b9c;
case 0x0c074b9eu: goto P_0c074b9e;
case 0x0c074ba0u: goto P_0c074ba0;
case 0x0c074ba2u: goto P_0c074ba2;
case 0x0c074ba4u: goto P_0c074ba4;
case 0x0c074ba6u: goto P_0c074ba6;
case 0x0c074ba8u: goto P_0c074ba8;
case 0x0c074baau: goto P_0c074baa;
case 0x0c074bacu: goto P_0c074bac;
case 0x0c074baeu: goto P_0c074bae;
case 0x0c074bb0u: goto P_0c074bb0;
case 0x0c074bb2u: goto P_0c074bb2;
case 0x0c074bb4u: goto P_0c074bb4;
case 0x0c074bb6u: goto P_0c074bb6;
case 0x0c074bb8u: goto P_0c074bb8;
case 0x0c074bbau: goto P_0c074bba;
case 0x0c074bbcu: goto P_0c074bbc;
case 0x0c074bbeu: goto P_0c074bbe;
case 0x0c074bc0u: goto P_0c074bc0;
case 0x0c074bc2u: goto P_0c074bc2;
case 0x0c074bc4u: goto P_0c074bc4;
case 0x0c074bc6u: goto P_0c074bc6;
case 0x0c074bc8u: goto P_0c074bc8;
case 0x0c074bcau: goto P_0c074bca;
case 0x0c074bccu: goto P_0c074bcc;
case 0x0c074bf8u: goto P_0c074bf8;
case 0x0c074bfau: goto P_0c074bfa;
case 0x0c074bfcu: goto P_0c074bfc;
case 0x0c074bfeu: goto P_0c074bfe;
case 0x0c074c00u: goto P_0c074c00;
case 0x0c074c02u: goto P_0c074c02;
case 0x0c074c04u: goto P_0c074c04;
case 0x0c074c06u: goto P_0c074c06;
case 0x0c074c08u: goto P_0c074c08;
case 0x0c074c0au: goto P_0c074c0a;
case 0x0c074c0cu: goto P_0c074c0c;
case 0x0c074c0eu: goto P_0c074c0e;
case 0x0c074c10u: goto P_0c074c10;
case 0x0c074c12u: goto P_0c074c12;
case 0x0c074c14u: goto P_0c074c14;
case 0x0c074c16u: goto P_0c074c16;
case 0x0c074c18u: goto P_0c074c18;
case 0x0c074c1au: goto P_0c074c1a;
case 0x0c074c1cu: goto P_0c074c1c;
case 0x0c074c1eu: goto P_0c074c1e;
case 0x0c074c20u: goto P_0c074c20;
case 0x0c074c22u: goto P_0c074c22;
case 0x0c074c24u: goto P_0c074c24;
case 0x0c074c26u: goto P_0c074c26;
case 0x0c074c28u: goto P_0c074c28;
case 0x0c074c2au: goto P_0c074c2a;
case 0x0c074c2cu: goto P_0c074c2c;
case 0x0c074c2eu: goto P_0c074c2e;
case 0x0c074c30u: goto P_0c074c30;
case 0x0c074c32u: goto P_0c074c32;
case 0x0c074c34u: goto P_0c074c34;
case 0x0c074c36u: goto P_0c074c36;
case 0x0c074c38u: goto P_0c074c38;
case 0x0c074c3au: goto P_0c074c3a;
case 0x0c074c3cu: goto P_0c074c3c;
case 0x0c074c3eu: goto P_0c074c3e;
case 0x0c074c40u: goto P_0c074c40;
case 0x0c074c42u: goto P_0c074c42;
case 0x0c074c44u: goto P_0c074c44;
case 0x0c074c46u: goto P_0c074c46;
case 0x0c074c48u: goto P_0c074c48;
case 0x0c074c4au: goto P_0c074c4a;
case 0x0c074c4cu: goto P_0c074c4c;
case 0x0c074c4eu: goto P_0c074c4e;
case 0x0c074c50u: goto P_0c074c50;
case 0x0c074c52u: goto P_0c074c52;
case 0x0c074c54u: goto P_0c074c54;
case 0x0c074c56u: goto P_0c074c56;
case 0x0c074c58u: goto P_0c074c58;
case 0x0c074c5au: goto P_0c074c5a;
case 0x0c074c5cu: goto P_0c074c5c;
case 0x0c074c5eu: goto P_0c074c5e;
case 0x0c074c60u: goto P_0c074c60;
case 0x0c074c62u: goto P_0c074c62;
case 0x0c074c64u: goto P_0c074c64;
case 0x0c074c66u: goto P_0c074c66;
case 0x0c074c68u: goto P_0c074c68;
case 0x0c074c6au: goto P_0c074c6a;
case 0x0c074c6cu: goto P_0c074c6c;
case 0x0c074c6eu: goto P_0c074c6e;
case 0x0c074c70u: goto P_0c074c70;
case 0x0c074c72u: goto P_0c074c72;
case 0x0c074c74u: goto P_0c074c74;
case 0x0c074c76u: goto P_0c074c76;
case 0x0c074c78u: goto P_0c074c78;
case 0x0c074c7au: goto P_0c074c7a;
case 0x0c074c7cu: goto P_0c074c7c;
case 0x0c074c7eu: goto P_0c074c7e;
case 0x0c074c80u: goto P_0c074c80;
case 0x0c074c82u: goto P_0c074c82;
case 0x0c074c84u: goto P_0c074c84;
case 0x0c074c86u: goto P_0c074c86;
case 0x0c074c88u: goto P_0c074c88;
case 0x0c074c8au: goto P_0c074c8a;
case 0x0c074c8cu: goto P_0c074c8c;
case 0x0c074c8eu: goto P_0c074c8e;
case 0x0c074c90u: goto P_0c074c90;
case 0x0c074c92u: goto P_0c074c92;
case 0x0c074c94u: goto P_0c074c94;
case 0x0c074c96u: goto P_0c074c96;
case 0x0c074c98u: goto P_0c074c98;
case 0x0c074c9au: goto P_0c074c9a;
case 0x0c074c9cu: goto P_0c074c9c;
case 0x0c074c9eu: goto P_0c074c9e;
case 0x0c074ca0u: goto P_0c074ca0;
case 0x0c074ca2u: goto P_0c074ca2;
case 0x0c074ca4u: goto P_0c074ca4;
case 0x0c074ca6u: goto P_0c074ca6;
case 0x0c074ca8u: goto P_0c074ca8;
case 0x0c074caau: goto P_0c074caa;
case 0x0c074cacu: goto P_0c074cac;
case 0x0c074caeu: goto P_0c074cae;
case 0x0c074cb0u: goto P_0c074cb0;
case 0x0c074cb2u: goto P_0c074cb2;
case 0x0c074cb4u: goto P_0c074cb4;
case 0x0c074cb6u: goto P_0c074cb6;
case 0x0c074cb8u: goto P_0c074cb8;
case 0x0c074cbau: goto P_0c074cba;
case 0x0c074cbcu: goto P_0c074cbc;
case 0x0c074cd4u: goto P_0c074cd4;
case 0x0c074cd6u: goto P_0c074cd6;
case 0x0c074cd8u: goto P_0c074cd8;
case 0x0c074cdau: goto P_0c074cda;
case 0x0c074cdcu: goto P_0c074cdc;
case 0x0c074cdeu: goto P_0c074cde;
case 0x0c074ce0u: goto P_0c074ce0;
case 0x0c074ce2u: goto P_0c074ce2;
case 0x0c074ce4u: goto P_0c074ce4;
case 0x0c074ce6u: goto P_0c074ce6;
case 0x0c074ce8u: goto P_0c074ce8;
case 0x0c074ceau: goto P_0c074cea;
case 0x0c074cecu: goto P_0c074cec;
case 0x0c074ceeu: goto P_0c074cee;
case 0x0c074cf0u: goto P_0c074cf0;
case 0x0c074cf2u: goto P_0c074cf2;
case 0x0c074cf4u: goto P_0c074cf4;
case 0x0c074cf6u: goto P_0c074cf6;
case 0x0c074cf8u: goto P_0c074cf8;
case 0x0c074cfau: goto P_0c074cfa;
case 0x0c074cfcu: goto P_0c074cfc;
case 0x0c074cfeu: goto P_0c074cfe;
case 0x0c074d00u: goto P_0c074d00;
case 0x0c074d02u: goto P_0c074d02;
case 0x0c074d04u: goto P_0c074d04;
case 0x0c074d06u: goto P_0c074d06;
case 0x0c074d08u: goto P_0c074d08;
case 0x0c074d0au: goto P_0c074d0a;
case 0x0c074d0cu: goto P_0c074d0c;
case 0x0c074d0eu: goto P_0c074d0e;
case 0x0c074d10u: goto P_0c074d10;
case 0x0c074d12u: goto P_0c074d12;
case 0x0c074d14u: goto P_0c074d14;
case 0x0c074d16u: goto P_0c074d16;
case 0x0c074d18u: goto P_0c074d18;
case 0x0c074d1au: goto P_0c074d1a;
case 0x0c074d1cu: goto P_0c074d1c;
case 0x0c074d1eu: goto P_0c074d1e;
case 0x0c074d20u: goto P_0c074d20;
case 0x0c074d22u: goto P_0c074d22;
case 0x0c074d24u: goto P_0c074d24;
case 0x0c074d26u: goto P_0c074d26;
case 0x0c074d28u: goto P_0c074d28;
case 0x0c074d2au: goto P_0c074d2a;
case 0x0c074d2cu: goto P_0c074d2c;
case 0x0c074d2eu: goto P_0c074d2e;
case 0x0c074d30u: goto P_0c074d30;
case 0x0c074d32u: goto P_0c074d32;
case 0x0c074d34u: goto P_0c074d34;
case 0x0c074d36u: goto P_0c074d36;
case 0x0c074d38u: goto P_0c074d38;
case 0x0c074d3au: goto P_0c074d3a;
case 0x0c074d3cu: goto P_0c074d3c;
case 0x0c074d3eu: goto P_0c074d3e;
case 0x0c074d40u: goto P_0c074d40;
case 0x0c074d42u: goto P_0c074d42;
case 0x0c074d44u: goto P_0c074d44;
case 0x0c074d46u: goto P_0c074d46;
case 0x0c074d48u: goto P_0c074d48;
case 0x0c074d4au: goto P_0c074d4a;
case 0x0c074d4cu: goto P_0c074d4c;
case 0x0c074d4eu: goto P_0c074d4e;
case 0x0c074d50u: goto P_0c074d50;
case 0x0c074d52u: goto P_0c074d52;
case 0x0c074d54u: goto P_0c074d54;
case 0x0c074d56u: goto P_0c074d56;
case 0x0c074d58u: goto P_0c074d58;
case 0x0c074d5au: goto P_0c074d5a;
case 0x0c074d5cu: goto P_0c074d5c;
case 0x0c074d5eu: goto P_0c074d5e;
case 0x0c074d60u: goto P_0c074d60;
case 0x0c074d62u: goto P_0c074d62;
case 0x0c074d64u: goto P_0c074d64;
case 0x0c074d66u: goto P_0c074d66;
case 0x0c074d68u: goto P_0c074d68;
case 0x0c074d6au: goto P_0c074d6a;
case 0x0c074d6cu: goto P_0c074d6c;
case 0x0c074d6eu: goto P_0c074d6e;
case 0x0c074d70u: goto P_0c074d70;
case 0x0c074d72u: goto P_0c074d72;
case 0x0c074d74u: goto P_0c074d74;
case 0x0c074d76u: goto P_0c074d76;
case 0x0c074d78u: goto P_0c074d78;
case 0x0c074d7au: goto P_0c074d7a;
case 0x0c074d7cu: goto P_0c074d7c;
case 0x0c074d7eu: goto P_0c074d7e;
case 0x0c074d80u: goto P_0c074d80;
case 0x0c074d82u: goto P_0c074d82;
case 0x0c074d84u: goto P_0c074d84;
case 0x0c074d86u: goto P_0c074d86;
case 0x0c074d88u: goto P_0c074d88;
case 0x0c074d8au: goto P_0c074d8a;
case 0x0c074d8cu: goto P_0c074d8c;
case 0x0c074d8eu: goto P_0c074d8e;
case 0x0c074d90u: goto P_0c074d90;
case 0x0c074db0u: goto P_0c074db0;
case 0x0c074db2u: goto P_0c074db2;
case 0x0c074db4u: goto P_0c074db4;
case 0x0c074db6u: goto P_0c074db6;
case 0x0c074db8u: goto P_0c074db8;
case 0x0c074dbau: goto P_0c074dba;
case 0x0c074dbcu: goto P_0c074dbc;
case 0x0c074dbeu: goto P_0c074dbe;
case 0x0c074dc0u: goto P_0c074dc0;
case 0x0c074dc2u: goto P_0c074dc2;
case 0x0c074dc4u: goto P_0c074dc4;
case 0x0c074dc6u: goto P_0c074dc6;
case 0x0c074dc8u: goto P_0c074dc8;
case 0x0c074dcau: goto P_0c074dca;
case 0x0c074dccu: goto P_0c074dcc;
case 0x0c074dceu: goto P_0c074dce;
case 0x0c074dd0u: goto P_0c074dd0;
case 0x0c074dd2u: goto P_0c074dd2;
case 0x0c074dd4u: goto P_0c074dd4;
case 0x0c074dd6u: goto P_0c074dd6;
case 0x0c074dd8u: goto P_0c074dd8;
case 0x0c074ddau: goto P_0c074dda;
case 0x0c074ddcu: goto P_0c074ddc;
case 0x0c074ddeu: goto P_0c074dde;
case 0x0c074de0u: goto P_0c074de0;
case 0x0c074de2u: goto P_0c074de2;
case 0x0c074de4u: goto P_0c074de4;
case 0x0c074de6u: goto P_0c074de6;
case 0x0c074de8u: goto P_0c074de8;
case 0x0c074deau: goto P_0c074dea;
case 0x0c074decu: goto P_0c074dec;
case 0x0c074deeu: goto P_0c074dee;
case 0x0c074df0u: goto P_0c074df0;
case 0x0c074df2u: goto P_0c074df2;
case 0x0c074df4u: goto P_0c074df4;
case 0x0c074df6u: goto P_0c074df6;
case 0x0c074df8u: goto P_0c074df8;
case 0x0c074dfau: goto P_0c074dfa;
case 0x0c074dfcu: goto P_0c074dfc;
case 0x0c074dfeu: goto P_0c074dfe;
case 0x0c074e00u: goto P_0c074e00;
case 0x0c074e02u: goto P_0c074e02;
case 0x0c074e04u: goto P_0c074e04;
case 0x0c074e06u: goto P_0c074e06;
case 0x0c074e08u: goto P_0c074e08;
case 0x0c074e0au: goto P_0c074e0a;
case 0x0c074e0cu: goto P_0c074e0c;
case 0x0c074e0eu: goto P_0c074e0e;
case 0x0c074e10u: goto P_0c074e10;
case 0x0c074e12u: goto P_0c074e12;
case 0x0c074e14u: goto P_0c074e14;
case 0x0c074e16u: goto P_0c074e16;
case 0x0c074e18u: goto P_0c074e18;
case 0x0c074e1au: goto P_0c074e1a;
case 0x0c0750beu: goto P_0c0750be;
case 0x0c0750c0u: goto P_0c0750c0;
case 0x0c0750c2u: goto P_0c0750c2;
case 0x0c0750c4u: goto P_0c0750c4;
case 0x0c0750c6u: goto P_0c0750c6;
case 0x0c0750c8u: goto P_0c0750c8;
case 0x0c0750cau: goto P_0c0750ca;
case 0x0c0750ccu: goto P_0c0750cc;
case 0x0c0750ceu: goto P_0c0750ce;
case 0x0c0750d0u: goto P_0c0750d0;
case 0x0c0750d2u: goto P_0c0750d2;
case 0x0c0750d4u: goto P_0c0750d4;
case 0x0c0750d6u: goto P_0c0750d6;
case 0x0c0750d8u: goto P_0c0750d8;
case 0x0c0750dau: goto P_0c0750da;
case 0x0c0750dcu: goto P_0c0750dc;
case 0x0c0750deu: goto P_0c0750de;
case 0x0c0750e0u: goto P_0c0750e0;
case 0x0c0750e2u: goto P_0c0750e2;
case 0x0c0750e4u: goto P_0c0750e4;
case 0x0c0750e6u: goto P_0c0750e6;
case 0x0c0750e8u: goto P_0c0750e8;
case 0x0c0750eau: goto P_0c0750ea;
case 0x0c0750ecu: goto P_0c0750ec;
case 0x0c0750eeu: goto P_0c0750ee;
case 0x0c0750f0u: goto P_0c0750f0;
case 0x0c0750f2u: goto P_0c0750f2;
case 0x0c0750f4u: goto P_0c0750f4;
case 0x0c0750f6u: goto P_0c0750f6;
case 0x0c0750f8u: goto P_0c0750f8;
case 0x0c0750fau: goto P_0c0750fa;
case 0x0c0750fcu: goto P_0c0750fc;
case 0x0c0750feu: goto P_0c0750fe;
case 0x0c075100u: goto P_0c075100;
case 0x0c075102u: goto P_0c075102;
case 0x0c075104u: goto P_0c075104;
case 0x0c075106u: goto P_0c075106;
case 0x0c075108u: goto P_0c075108;
case 0x0c07510au: goto P_0c07510a;
case 0x0c07510cu: goto P_0c07510c;
case 0x0c07510eu: goto P_0c07510e;
case 0x0c075110u: goto P_0c075110;
case 0x0c075112u: goto P_0c075112;
case 0x0c075114u: goto P_0c075114;
case 0x0c075116u: goto P_0c075116;
case 0x0c075118u: goto P_0c075118;
case 0x0c07511au: goto P_0c07511a;
case 0x0c07511cu: goto P_0c07511c;
case 0x0c07511eu: goto P_0c07511e;
case 0x0c075120u: goto P_0c075120;
case 0x0c075122u: goto P_0c075122;
case 0x0c075124u: goto P_0c075124;
case 0x0c07513cu: goto P_0c07513c;
case 0x0c07513eu: goto P_0c07513e;
case 0x0c075140u: goto P_0c075140;
case 0x0c075142u: goto P_0c075142;
case 0x0c075144u: goto P_0c075144;
case 0x0c075146u: goto P_0c075146;
case 0x0c075148u: goto P_0c075148;
case 0x0c07514au: goto P_0c07514a;
case 0x0c07514cu: goto P_0c07514c;
case 0x0c07514eu: goto P_0c07514e;
case 0x0c075150u: goto P_0c075150;
case 0x0c075152u: goto P_0c075152;
case 0x0c075154u: goto P_0c075154;
case 0x0c075156u: goto P_0c075156;
case 0x0c075158u: goto P_0c075158;
case 0x0c07515au: goto P_0c07515a;
case 0x0c07515cu: goto P_0c07515c;
case 0x0c07515eu: goto P_0c07515e;
case 0x0c075160u: goto P_0c075160;
case 0x0c075162u: goto P_0c075162;
case 0x0c075164u: goto P_0c075164;
case 0x0c075166u: goto P_0c075166;
case 0x0c075168u: goto P_0c075168;
case 0x0c07516au: goto P_0c07516a;
case 0x0c07516cu: goto P_0c07516c;
case 0x0c07516eu: goto P_0c07516e;
case 0x0c075170u: goto P_0c075170;
case 0x0c075172u: goto P_0c075172;
case 0x0c075174u: goto P_0c075174;
case 0x0c075176u: goto P_0c075176;
case 0x0c075178u: goto P_0c075178;
case 0x0c07517au: goto P_0c07517a;
case 0x0c07517cu: goto P_0c07517c;
case 0x0c07517eu: goto P_0c07517e;
case 0x0c075180u: goto P_0c075180;
case 0x0c075182u: goto P_0c075182;
case 0x0c075184u: goto P_0c075184;
case 0x0c075186u: goto P_0c075186;
case 0x0c075188u: goto P_0c075188;
case 0x0c07518au: goto P_0c07518a;
case 0x0c07518cu: goto P_0c07518c;
case 0x0c07518eu: goto P_0c07518e;
case 0x0c075190u: goto P_0c075190;
case 0x0c075192u: goto P_0c075192;
case 0x0c075194u: goto P_0c075194;
case 0x0c075196u: goto P_0c075196;
case 0x0c075198u: goto P_0c075198;
case 0x0c07519au: goto P_0c07519a;
case 0x0c07519cu: goto P_0c07519c;
case 0x0c07519eu: goto P_0c07519e;
case 0x0c0751a0u: goto P_0c0751a0;
case 0x0c0751a2u: goto P_0c0751a2;
case 0x0c0751a4u: goto P_0c0751a4;
case 0x0c0751a6u: goto P_0c0751a6;
case 0x0c0751a8u: goto P_0c0751a8;
case 0x0c0751aau: goto P_0c0751aa;
case 0x0c0751acu: goto P_0c0751ac;
case 0x0c0751aeu: goto P_0c0751ae;
case 0x0c0751b0u: goto P_0c0751b0;
case 0x0c0751b2u: goto P_0c0751b2;
case 0x0c0751b4u: goto P_0c0751b4;
case 0x0c0751b6u: goto P_0c0751b6;
case 0x0c0751b8u: goto P_0c0751b8;
case 0x0c0751bau: goto P_0c0751ba;
case 0x0c0751bcu: goto P_0c0751bc;
case 0x0c0751beu: goto P_0c0751be;
case 0x0c0751c0u: goto P_0c0751c0;
case 0x0c0751c2u: goto P_0c0751c2;
case 0x0c0751c4u: goto P_0c0751c4;
case 0x0c0751c6u: goto P_0c0751c6;
case 0x0c0751c8u: goto P_0c0751c8;
case 0x0c0751cau: goto P_0c0751ca;
case 0x0c0751ccu: goto P_0c0751cc;
case 0x0c0751ceu: goto P_0c0751ce;
case 0x0c0751d0u: goto P_0c0751d0;
case 0x0c0751d2u: goto P_0c0751d2;
case 0x0c0751d4u: goto P_0c0751d4;
case 0x0c0751d6u: goto P_0c0751d6;
case 0x0c0751d8u: goto P_0c0751d8;
case 0x0c0751dau: goto P_0c0751da;
case 0x0c0751dcu: goto P_0c0751dc;
case 0x0c0751deu: goto P_0c0751de;
case 0x0c0751e0u: goto P_0c0751e0;
case 0x0c0751e2u: goto P_0c0751e2;
case 0x0c0751e4u: goto P_0c0751e4;
case 0x0c0751e6u: goto P_0c0751e6;
case 0x0c0751e8u: goto P_0c0751e8;
case 0x0c0751eau: goto P_0c0751ea;
case 0x0c0751ecu: goto P_0c0751ec;
case 0x0c0751eeu: goto P_0c0751ee;
case 0x0c0751f0u: goto P_0c0751f0;
case 0x0c0751f2u: goto P_0c0751f2;
case 0x0c0751f4u: goto P_0c0751f4;
case 0x0c0751f6u: goto P_0c0751f6;
case 0x0c0751f8u: goto P_0c0751f8;
case 0x0c075220u: goto P_0c075220;
case 0x0c075222u: goto P_0c075222;
case 0x0c075224u: goto P_0c075224;
case 0x0c075226u: goto P_0c075226;
case 0x0c075228u: goto P_0c075228;
case 0x0c07522au: goto P_0c07522a;
case 0x0c07522cu: goto P_0c07522c;
case 0x0c07522eu: goto P_0c07522e;
case 0x0c075230u: goto P_0c075230;
case 0x0c075232u: goto P_0c075232;
case 0x0c075234u: goto P_0c075234;
case 0x0c075236u: goto P_0c075236;
case 0x0c075238u: goto P_0c075238;
case 0x0c07523au: goto P_0c07523a;
case 0x0c07523cu: goto P_0c07523c;
case 0x0c07523eu: goto P_0c07523e;
case 0x0c075240u: goto P_0c075240;
case 0x0c075242u: goto P_0c075242;
case 0x0c075244u: goto P_0c075244;
case 0x0c075246u: goto P_0c075246;
case 0x0c075248u: goto P_0c075248;
case 0x0c07524au: goto P_0c07524a;
case 0x0c07524cu: goto P_0c07524c;
case 0x0c07524eu: goto P_0c07524e;
case 0x0c075250u: goto P_0c075250;
case 0x0c075252u: goto P_0c075252;
case 0x0c075254u: goto P_0c075254;
case 0x0c075256u: goto P_0c075256;
case 0x0c075258u: goto P_0c075258;
case 0x0c07525au: goto P_0c07525a;
case 0x0c07525cu: goto P_0c07525c;
case 0x0c07525eu: goto P_0c07525e;
case 0x0c075260u: goto P_0c075260;
case 0x0c075262u: goto P_0c075262;
case 0x0c075264u: goto P_0c075264;
case 0x0c075266u: goto P_0c075266;
case 0x0c075268u: goto P_0c075268;
case 0x0c07526au: goto P_0c07526a;
case 0x0c07526cu: goto P_0c07526c;
case 0x0c07526eu: goto P_0c07526e;
case 0x0c075270u: goto P_0c075270;
case 0x0c075272u: goto P_0c075272;
case 0x0c075274u: goto P_0c075274;
case 0x0c075276u: goto P_0c075276;
case 0x0c075278u: goto P_0c075278;
case 0x0c07527au: goto P_0c07527a;
case 0x0c07527cu: goto P_0c07527c;
case 0x0c07527eu: goto P_0c07527e;
case 0x0c075280u: goto P_0c075280;
case 0x0c075282u: goto P_0c075282;
case 0x0c075284u: goto P_0c075284;
case 0x0c075286u: goto P_0c075286;
case 0x0c075288u: goto P_0c075288;
case 0x0c07528au: goto P_0c07528a;
case 0x0c07528cu: goto P_0c07528c;
case 0x0c07528eu: goto P_0c07528e;
case 0x0c075290u: goto P_0c075290;
case 0x0c075292u: goto P_0c075292;
case 0x0c075294u: goto P_0c075294;
case 0x0c075296u: goto P_0c075296;
case 0x0c075298u: goto P_0c075298;
case 0x0c07529au: goto P_0c07529a;
case 0x0c07529cu: goto P_0c07529c;
case 0x0c07529eu: goto P_0c07529e;
case 0x0c0752a0u: goto P_0c0752a0;
case 0x0c0752a2u: goto P_0c0752a2;
case 0x0c0752a4u: goto P_0c0752a4;
case 0x0c0752a6u: goto P_0c0752a6;
case 0x0c0752a8u: goto P_0c0752a8;
case 0x0c0752aau: goto P_0c0752aa;
case 0x0c0752acu: goto P_0c0752ac;
case 0x0c0752aeu: goto P_0c0752ae;
case 0x0c0752b0u: goto P_0c0752b0;
case 0x0c0752b2u: goto P_0c0752b2;
case 0x0c0752b4u: goto P_0c0752b4;
case 0x0c0752b6u: goto P_0c0752b6;
case 0x0c0752b8u: goto P_0c0752b8;
case 0x0c0752bau: goto P_0c0752ba;
case 0x0c0752bcu: goto P_0c0752bc;
case 0x0c0752beu: goto P_0c0752be;
case 0x0c0752c0u: goto P_0c0752c0;
case 0x0c0752c2u: goto P_0c0752c2;
case 0x0c0752c4u: goto P_0c0752c4;
case 0x0c0752c6u: goto P_0c0752c6;
case 0x0c0752c8u: goto P_0c0752c8;
case 0x0c0752cau: goto P_0c0752ca;
case 0x0c0752ccu: goto P_0c0752cc;
case 0x0c0752ceu: goto P_0c0752ce;
case 0x0c0752d0u: goto P_0c0752d0;
case 0x0c0752d2u: goto P_0c0752d2;
case 0x0c0752d4u: goto P_0c0752d4;
case 0x0c0752d6u: goto P_0c0752d6;
case 0x0c0752d8u: goto P_0c0752d8;
case 0x0c0752dau: goto P_0c0752da;
case 0x0c0752dcu: goto P_0c0752dc;
case 0x0c0752deu: goto P_0c0752de;
case 0x0c0752e0u: goto P_0c0752e0;
case 0x0c0752e2u: goto P_0c0752e2;
case 0x0c0752e4u: goto P_0c0752e4;
case 0x0c0752e6u: goto P_0c0752e6;
case 0x0c0752e8u: goto P_0c0752e8;
case 0x0c0752eau: goto P_0c0752ea;
case 0x0c0752ecu: goto P_0c0752ec;
case 0x0c0752eeu: goto P_0c0752ee;
case 0x0c0752f0u: goto P_0c0752f0;
case 0x0c0752f2u: goto P_0c0752f2;
case 0x0c0752f4u: goto P_0c0752f4;
case 0x0c0752f6u: goto P_0c0752f6;
case 0x0c0752f8u: goto P_0c0752f8;
case 0x0c0752fau: goto P_0c0752fa;
case 0x0c0752fcu: goto P_0c0752fc;
case 0x0c0752feu: goto P_0c0752fe;
case 0x0c075300u: goto P_0c075300;
case 0x0c075302u: goto P_0c075302;
case 0x0c075304u: goto P_0c075304;
case 0x0c075306u: goto P_0c075306;
case 0x0c075308u: goto P_0c075308;
case 0x0c07530au: goto P_0c07530a;
case 0x0c07530cu: goto P_0c07530c;
case 0x0c07530eu: goto P_0c07530e;
case 0x0c075310u: goto P_0c075310;
case 0x0c075312u: goto P_0c075312;
case 0x0c075314u: goto P_0c075314;
case 0x0c075316u: goto P_0c075316;
case 0x0c075318u: goto P_0c075318;
case 0x0c07531au: goto P_0c07531a;
case 0x0c07531cu: goto P_0c07531c;
case 0x0c07531eu: goto P_0c07531e;
case 0x0c075320u: goto P_0c075320;
case 0x0c075322u: goto P_0c075322;
case 0x0c075324u: goto P_0c075324;
case 0x0c075326u: goto P_0c075326;
case 0x0c075328u: goto P_0c075328;
case 0x0c07532au: goto P_0c07532a;
case 0x0c07532cu: goto P_0c07532c;
case 0x0c07532eu: goto P_0c07532e;
case 0x0c075330u: goto P_0c075330;
case 0x0c075332u: goto P_0c075332;
case 0x0c075334u: goto P_0c075334;
case 0x0c075336u: goto P_0c075336;
case 0x0c075338u: goto P_0c075338;
case 0x0c07533au: goto P_0c07533a;
case 0x0c07533cu: goto P_0c07533c;
case 0x0c07533eu: goto P_0c07533e;
case 0x0c075340u: goto P_0c075340;
case 0x0c075342u: goto P_0c075342;
case 0x0c075344u: goto P_0c075344;
case 0x0c075346u: goto P_0c075346;
case 0x0c075348u: goto P_0c075348;
case 0x0c07534au: goto P_0c07534a;
case 0x0c07534cu: goto P_0c07534c;
case 0x0c07534eu: goto P_0c07534e;
case 0x0c075350u: goto P_0c075350;
case 0x0c075352u: goto P_0c075352;
case 0x0c075354u: goto P_0c075354;
case 0x0c075356u: goto P_0c075356;
case 0x0c075358u: goto P_0c075358;
case 0x0c07535au: goto P_0c07535a;
case 0x0c07535cu: goto P_0c07535c;
case 0x0c07535eu: goto P_0c07535e;
case 0x0c075360u: goto P_0c075360;
case 0x0c075362u: goto P_0c075362;
case 0x0c075364u: goto P_0c075364;
case 0x0c075366u: goto P_0c075366;
case 0x0c0753acu: goto P_0c0753ac;
case 0x0c0753aeu: goto P_0c0753ae;
case 0x0c0753b0u: goto P_0c0753b0;
case 0x0c0753b2u: goto P_0c0753b2;
case 0x0c0753b4u: goto P_0c0753b4;
case 0x0c0753b6u: goto P_0c0753b6;
case 0x0c0753b8u: goto P_0c0753b8;
case 0x0c0753bau: goto P_0c0753ba;
case 0x0c0753bcu: goto P_0c0753bc;
case 0x0c0753beu: goto P_0c0753be;
case 0x0c0753c0u: goto P_0c0753c0;
case 0x0c0753c2u: goto P_0c0753c2;
case 0x0c0753c4u: goto P_0c0753c4;
case 0x0c0753c6u: goto P_0c0753c6;
case 0x0c0753c8u: goto P_0c0753c8;
case 0x0c0753cau: goto P_0c0753ca;
case 0x0c0753ccu: goto P_0c0753cc;
case 0x0c0753ceu: goto P_0c0753ce;
case 0x0c0753d0u: goto P_0c0753d0;
case 0x0c0753d2u: goto P_0c0753d2;
case 0x0c0753d4u: goto P_0c0753d4;
case 0x0c0753d6u: goto P_0c0753d6;
case 0x0c0753d8u: goto P_0c0753d8;
case 0x0c0753dau: goto P_0c0753da;
case 0x0c0753dcu: goto P_0c0753dc;
case 0x0c0753deu: goto P_0c0753de;
case 0x0c0753e0u: goto P_0c0753e0;
case 0x0c0753e2u: goto P_0c0753e2;
case 0x0c0753e4u: goto P_0c0753e4;
case 0x0c0753e6u: goto P_0c0753e6;
case 0x0c0753e8u: goto P_0c0753e8;
case 0x0c0753eau: goto P_0c0753ea;
case 0x0c0753ecu: goto P_0c0753ec;
case 0x0c0753eeu: goto P_0c0753ee;
case 0x0c0753f0u: goto P_0c0753f0;
case 0x0c0753f2u: goto P_0c0753f2;
case 0x0c0753f4u: goto P_0c0753f4;
case 0x0c0753f6u: goto P_0c0753f6;
case 0x0c0753f8u: goto P_0c0753f8;
case 0x0c0753fau: goto P_0c0753fa;
case 0x0c0753fcu: goto P_0c0753fc;
case 0x0c0753feu: goto P_0c0753fe;
case 0x0c075400u: goto P_0c075400;
case 0x0c075402u: goto P_0c075402;
case 0x0c075404u: goto P_0c075404;
case 0x0c075406u: goto P_0c075406;
case 0x0c075408u: goto P_0c075408;
case 0x0c07540au: goto P_0c07540a;
case 0x0c07540cu: goto P_0c07540c;
case 0x0c07540eu: goto P_0c07540e;
case 0x0c075410u: goto P_0c075410;
case 0x0c075412u: goto P_0c075412;
case 0x0c075414u: goto P_0c075414;
case 0x0c075416u: goto P_0c075416;
case 0x0c075418u: goto P_0c075418;
case 0x0c07541au: goto P_0c07541a;
case 0x0c07541cu: goto P_0c07541c;
case 0x0c07541eu: goto P_0c07541e;
case 0x0c075420u: goto P_0c075420;
case 0x0c075422u: goto P_0c075422;
case 0x0c075424u: goto P_0c075424;
case 0x0c075426u: goto P_0c075426;
case 0x0c075428u: goto P_0c075428;
case 0x0c07542au: goto P_0c07542a;
case 0x0c07542cu: goto P_0c07542c;
case 0x0c07542eu: goto P_0c07542e;
case 0x0c075430u: goto P_0c075430;
case 0x0c075432u: goto P_0c075432;
case 0x0c075434u: goto P_0c075434;
case 0x0c075436u: goto P_0c075436;
case 0x0c075438u: goto P_0c075438;
case 0x0c07543au: goto P_0c07543a;
case 0x0c07543cu: goto P_0c07543c;
case 0x0c07543eu: goto P_0c07543e;
case 0x0c075440u: goto P_0c075440;
case 0x0c075442u: goto P_0c075442;
case 0x0c075444u: goto P_0c075444;
case 0x0c075446u: goto P_0c075446;
case 0x0c075448u: goto P_0c075448;
case 0x0c07544au: goto P_0c07544a;
case 0x0c07544cu: goto P_0c07544c;
case 0x0c07544eu: goto P_0c07544e;
case 0x0c075450u: goto P_0c075450;
case 0x0c075452u: goto P_0c075452;
case 0x0c075454u: goto P_0c075454;
case 0x0c075456u: goto P_0c075456;
case 0x0c075458u: goto P_0c075458;
case 0x0c07545au: goto P_0c07545a;
case 0x0c07545cu: goto P_0c07545c;
case 0x0c075484u: goto P_0c075484;
case 0x0c075486u: goto P_0c075486;
case 0x0c075488u: goto P_0c075488;
case 0x0c07548au: goto P_0c07548a;
case 0x0c07548cu: goto P_0c07548c;
case 0x0c07548eu: goto P_0c07548e;
case 0x0c075490u: goto P_0c075490;
case 0x0c075492u: goto P_0c075492;
case 0x0c075494u: goto P_0c075494;
case 0x0c075496u: goto P_0c075496;
case 0x0c075498u: goto P_0c075498;
case 0x0c07549au: goto P_0c07549a;
case 0x0c07549cu: goto P_0c07549c;
case 0x0c07549eu: goto P_0c07549e;
case 0x0c0754a0u: goto P_0c0754a0;
case 0x0c0754a2u: goto P_0c0754a2;
case 0x0c0754a4u: goto P_0c0754a4;
case 0x0c0754a6u: goto P_0c0754a6;
case 0x0c0754a8u: goto P_0c0754a8;
case 0x0c0754aau: goto P_0c0754aa;
case 0x0c0754acu: goto P_0c0754ac;
case 0x0c0754aeu: goto P_0c0754ae;
case 0x0c0754b0u: goto P_0c0754b0;
case 0x0c0754b2u: goto P_0c0754b2;
case 0x0c0754b4u: goto P_0c0754b4;
case 0x0c0754b6u: goto P_0c0754b6;
case 0x0c0754b8u: goto P_0c0754b8;
case 0x0c0754bau: goto P_0c0754ba;
case 0x0c0754bcu: goto P_0c0754bc;
case 0x0c0754beu: goto P_0c0754be;
case 0x0c0754c0u: goto P_0c0754c0;
case 0x0c0754c2u: goto P_0c0754c2;
case 0x0c0754c4u: goto P_0c0754c4;
case 0x0c0754c6u: goto P_0c0754c6;
case 0x0c0754c8u: goto P_0c0754c8;
case 0x0c0754cau: goto P_0c0754ca;
case 0x0c0754ccu: goto P_0c0754cc;
case 0x0c0754ceu: goto P_0c0754ce;
case 0x0c0754d0u: goto P_0c0754d0;
case 0x0c0754d2u: goto P_0c0754d2;
case 0x0c0754d4u: goto P_0c0754d4;
case 0x0c0754d6u: goto P_0c0754d6;
case 0x0c0754d8u: goto P_0c0754d8;
case 0x0c0754dau: goto P_0c0754da;
case 0x0c0754dcu: goto P_0c0754dc;
case 0x0c0754deu: goto P_0c0754de;
case 0x0c0754e0u: goto P_0c0754e0;
case 0x0c0754e2u: goto P_0c0754e2;
case 0x0c0754e4u: goto P_0c0754e4;
case 0x0c0754e6u: goto P_0c0754e6;
case 0x0c0754e8u: goto P_0c0754e8;
case 0x0c0754eau: goto P_0c0754ea;
case 0x0c0754ecu: goto P_0c0754ec;
case 0x0c0754eeu: goto P_0c0754ee;
case 0x0c0754f0u: goto P_0c0754f0;
case 0x0c0754f2u: goto P_0c0754f2;
case 0x0c0754f4u: goto P_0c0754f4;
case 0x0c0754f6u: goto P_0c0754f6;
case 0x0c0754f8u: goto P_0c0754f8;
case 0x0c0754fau: goto P_0c0754fa;
case 0x0c0754fcu: goto P_0c0754fc;
case 0x0c0754feu: goto P_0c0754fe;
case 0x0c075500u: goto P_0c075500;
case 0x0c075502u: goto P_0c075502;
case 0x0c075504u: goto P_0c075504;
case 0x0c075506u: goto P_0c075506;
case 0x0c075508u: goto P_0c075508;
case 0x0c07550au: goto P_0c07550a;
case 0x0c07550cu: goto P_0c07550c;
case 0x0c07550eu: goto P_0c07550e;
case 0x0c075510u: goto P_0c075510;
case 0x0c075512u: goto P_0c075512;
case 0x0c075514u: goto P_0c075514;
case 0x0c075516u: goto P_0c075516;
case 0x0c075518u: goto P_0c075518;
case 0x0c07551au: goto P_0c07551a;
case 0x0c07551cu: goto P_0c07551c;
case 0x0c07551eu: goto P_0c07551e;
case 0x0c075520u: goto P_0c075520;
case 0x0c075522u: goto P_0c075522;
case 0x0c075524u: goto P_0c075524;
case 0x0c075526u: goto P_0c075526;
case 0x0c075528u: goto P_0c075528;
case 0x0c07552au: goto P_0c07552a;
case 0x0c07552cu: goto P_0c07552c;
case 0x0c07552eu: goto P_0c07552e;
case 0x0c075530u: goto P_0c075530;
case 0x0c075532u: goto P_0c075532;
case 0x0c075534u: goto P_0c075534;
case 0x0c075536u: goto P_0c075536;
case 0x0c075538u: goto P_0c075538;
case 0x0c07553au: goto P_0c07553a;
case 0x0c07553cu: goto P_0c07553c;
case 0x0c07553eu: goto P_0c07553e;
case 0x0c075540u: goto P_0c075540;
case 0x0c075542u: goto P_0c075542;
case 0x0c075544u: goto P_0c075544;
case 0x0c075546u: goto P_0c075546;
case 0x0c075548u: goto P_0c075548;
case 0x0c07554au: goto P_0c07554a;
case 0x0c07554cu: goto P_0c07554c;
case 0x0c07554eu: goto P_0c07554e;
case 0x0c075550u: goto P_0c075550;
case 0x0c075552u: goto P_0c075552;
case 0x0c075554u: goto P_0c075554;
case 0x0c075556u: goto P_0c075556;
case 0x0c075558u: goto P_0c075558;
case 0x0c07555au: goto P_0c07555a;
case 0x0c07555cu: goto P_0c07555c;
case 0x0c07555eu: goto P_0c07555e;
case 0x0c075560u: goto P_0c075560;
case 0x0c075562u: goto P_0c075562;
case 0x0c075564u: goto P_0c075564;
case 0x0c075566u: goto P_0c075566;
case 0x0c075568u: goto P_0c075568;
case 0x0c07556au: goto P_0c07556a;
case 0x0c07556cu: goto P_0c07556c;
case 0x0c07556eu: goto P_0c07556e;
case 0x0c075570u: goto P_0c075570;
case 0x0c075572u: goto P_0c075572;
case 0x0c075574u: goto P_0c075574;
case 0x0c075576u: goto P_0c075576;
case 0x0c075578u: goto P_0c075578;
case 0x0c07557au: goto P_0c07557a;
case 0x0c07557cu: goto P_0c07557c;
case 0x0c07557eu: goto P_0c07557e;
case 0x0c075580u: goto P_0c075580;
case 0x0c075582u: goto P_0c075582;
case 0x0c075584u: goto P_0c075584;
case 0x0c075586u: goto P_0c075586;
case 0x0c075588u: goto P_0c075588;
case 0x0c0755c8u: goto P_0c0755c8;
case 0x0c0755cau: goto P_0c0755ca;
case 0x0c0755ccu: goto P_0c0755cc;
case 0x0c0755ceu: goto P_0c0755ce;
case 0x0c0755d0u: goto P_0c0755d0;
case 0x0c0755d2u: goto P_0c0755d2;
case 0x0c0755d4u: goto P_0c0755d4;
case 0x0c0755d6u: goto P_0c0755d6;
case 0x0c0755d8u: goto P_0c0755d8;
case 0x0c0755dau: goto P_0c0755da;
case 0x0c0755dcu: goto P_0c0755dc;
case 0x0c0755deu: goto P_0c0755de;
case 0x0c0755e0u: goto P_0c0755e0;
case 0x0c0755e2u: goto P_0c0755e2;
case 0x0c0755e4u: goto P_0c0755e4;
case 0x0c0755e6u: goto P_0c0755e6;
case 0x0c0755e8u: goto P_0c0755e8;
case 0x0c0755eau: goto P_0c0755ea;
case 0x0c0755ecu: goto P_0c0755ec;
case 0x0c0755eeu: goto P_0c0755ee;
case 0x0c0755f0u: goto P_0c0755f0;
case 0x0c0755f2u: goto P_0c0755f2;
case 0x0c0755f4u: goto P_0c0755f4;
case 0x0c0755f6u: goto P_0c0755f6;
case 0x0c0755f8u: goto P_0c0755f8;
case 0x0c0755fau: goto P_0c0755fa;
case 0x0c0755fcu: goto P_0c0755fc;
case 0x0c0755feu: goto P_0c0755fe;
case 0x0c075600u: goto P_0c075600;
case 0x0c075602u: goto P_0c075602;
case 0x0c075604u: goto P_0c075604;
case 0x0c075606u: goto P_0c075606;
case 0x0c075608u: goto P_0c075608;
case 0x0c07560au: goto P_0c07560a;
case 0x0c07560cu: goto P_0c07560c;
case 0x0c07560eu: goto P_0c07560e;
case 0x0c075610u: goto P_0c075610;
case 0x0c075612u: goto P_0c075612;
case 0x0c075614u: goto P_0c075614;
case 0x0c075616u: goto P_0c075616;
case 0x0c075618u: goto P_0c075618;
case 0x0c07561au: goto P_0c07561a;
case 0x0c07561cu: goto P_0c07561c;
case 0x0c07561eu: goto P_0c07561e;
case 0x0c075620u: goto P_0c075620;
case 0x0c075622u: goto P_0c075622;
case 0x0c075624u: goto P_0c075624;
case 0x0c075626u: goto P_0c075626;
case 0x0c075628u: goto P_0c075628;
case 0x0c07562au: goto P_0c07562a;
case 0x0c07562cu: goto P_0c07562c;
case 0x0c07562eu: goto P_0c07562e;
case 0x0c075630u: goto P_0c075630;
case 0x0c075632u: goto P_0c075632;
case 0x0c075634u: goto P_0c075634;
case 0x0c075636u: goto P_0c075636;
case 0x0c075638u: goto P_0c075638;
case 0x0c07563au: goto P_0c07563a;
case 0x0c07563cu: goto P_0c07563c;
case 0x0c07563eu: goto P_0c07563e;
case 0x0c075640u: goto P_0c075640;
case 0x0c075642u: goto P_0c075642;
case 0x0c075644u: goto P_0c075644;
case 0x0c075646u: goto P_0c075646;
case 0x0c075648u: goto P_0c075648;
case 0x0c07564au: goto P_0c07564a;
case 0x0c07564cu: goto P_0c07564c;
case 0x0c07564eu: goto P_0c07564e;
case 0x0c075650u: goto P_0c075650;
case 0x0c075652u: goto P_0c075652;
case 0x0c075654u: goto P_0c075654;
case 0x0c075656u: goto P_0c075656;
case 0x0c075658u: goto P_0c075658;
case 0x0c07565au: goto P_0c07565a;
case 0x0c07565cu: goto P_0c07565c;
case 0x0c07565eu: goto P_0c07565e;
case 0x0c075660u: goto P_0c075660;
case 0x0c075662u: goto P_0c075662;
case 0x0c075664u: goto P_0c075664;
case 0x0c075666u: goto P_0c075666;
case 0x0c075668u: goto P_0c075668;
case 0x0c07566au: goto P_0c07566a;
case 0x0c07566cu: goto P_0c07566c;
case 0x0c07566eu: goto P_0c07566e;
case 0x0c075670u: goto P_0c075670;
case 0x0c075672u: goto P_0c075672;
case 0x0c075674u: goto P_0c075674;
case 0x0c075676u: goto P_0c075676;
case 0x0c075678u: goto P_0c075678;
case 0x0c07567au: goto P_0c07567a;
case 0x0c07567cu: goto P_0c07567c;
case 0x0c07567eu: goto P_0c07567e;
case 0x0c075680u: goto P_0c075680;
case 0x0c075682u: goto P_0c075682;
case 0x0c075684u: goto P_0c075684;
case 0x0c075686u: goto P_0c075686;
case 0x0c075688u: goto P_0c075688;
case 0x0c07568au: goto P_0c07568a;
case 0x0c07568cu: goto P_0c07568c;
case 0x0c07568eu: goto P_0c07568e;
case 0x0c075690u: goto P_0c075690;
case 0x0c075692u: goto P_0c075692;
case 0x0c075694u: goto P_0c075694;
case 0x0c075696u: goto P_0c075696;
case 0x0c075698u: goto P_0c075698;
case 0x0c07569au: goto P_0c07569a;
case 0x0c07569cu: goto P_0c07569c;
case 0x0c07569eu: goto P_0c07569e;
case 0x0c0756a0u: goto P_0c0756a0;
case 0x0c0756a2u: goto P_0c0756a2;
case 0x0c0756a4u: goto P_0c0756a4;
case 0x0c0756a6u: goto P_0c0756a6;
case 0x0c0756a8u: goto P_0c0756a8;
case 0x0c0756aau: goto P_0c0756aa;
case 0x0c0756acu: goto P_0c0756ac;
case 0x0c0756aeu: goto P_0c0756ae;
case 0x0c0756b0u: goto P_0c0756b0;
case 0x0c0756b2u: goto P_0c0756b2;
case 0x0c0756b4u: goto P_0c0756b4;
case 0x0c0756b6u: goto P_0c0756b6;
case 0x0c0756b8u: goto P_0c0756b8;
case 0x0c0756bau: goto P_0c0756ba;
case 0x0c0756bcu: goto P_0c0756bc;
case 0x0c0756beu: goto P_0c0756be;
case 0x0c0756c0u: goto P_0c0756c0;
case 0x0c0756c2u: goto P_0c0756c2;
case 0x0c0756fcu: goto P_0c0756fc;
case 0x0c0756feu: goto P_0c0756fe;
case 0x0c075700u: goto P_0c075700;
case 0x0c075702u: goto P_0c075702;
case 0x0c075704u: goto P_0c075704;
case 0x0c075706u: goto P_0c075706;
case 0x0c075708u: goto P_0c075708;
case 0x0c07570au: goto P_0c07570a;
case 0x0c07570cu: goto P_0c07570c;
case 0x0c07570eu: goto P_0c07570e;
case 0x0c075710u: goto P_0c075710;
case 0x0c075712u: goto P_0c075712;
case 0x0c075714u: goto P_0c075714;
case 0x0c075716u: goto P_0c075716;
case 0x0c075718u: goto P_0c075718;
case 0x0c07571au: goto P_0c07571a;
case 0x0c07571cu: goto P_0c07571c;
case 0x0c07571eu: goto P_0c07571e;
case 0x0c075720u: goto P_0c075720;
case 0x0c075722u: goto P_0c075722;
case 0x0c075724u: goto P_0c075724;
case 0x0c075726u: goto P_0c075726;
case 0x0c075728u: goto P_0c075728;
case 0x0c07572au: goto P_0c07572a;
case 0x0c07572cu: goto P_0c07572c;
case 0x0c07572eu: goto P_0c07572e;
case 0x0c075730u: goto P_0c075730;
case 0x0c075732u: goto P_0c075732;
case 0x0c075734u: goto P_0c075734;
case 0x0c075736u: goto P_0c075736;
case 0x0c075738u: goto P_0c075738;
case 0x0c07573au: goto P_0c07573a;
case 0x0c07573cu: goto P_0c07573c;
case 0x0c07573eu: goto P_0c07573e;
case 0x0c075740u: goto P_0c075740;
case 0x0c075742u: goto P_0c075742;
case 0x0c075744u: goto P_0c075744;
case 0x0c075746u: goto P_0c075746;
case 0x0c075748u: goto P_0c075748;
case 0x0c07574au: goto P_0c07574a;
case 0x0c07574cu: goto P_0c07574c;
case 0x0c07574eu: goto P_0c07574e;
case 0x0c075750u: goto P_0c075750;
case 0x0c075752u: goto P_0c075752;
case 0x0c075754u: goto P_0c075754;
case 0x0c075756u: goto P_0c075756;
case 0x0c075758u: goto P_0c075758;
case 0x0c07575au: goto P_0c07575a;
case 0x0c07575cu: goto P_0c07575c;
case 0x0c07575eu: goto P_0c07575e;
case 0x0c075760u: goto P_0c075760;
case 0x0c075762u: goto P_0c075762;
case 0x0c075764u: goto P_0c075764;
case 0x0c075766u: goto P_0c075766;
case 0x0c075768u: goto P_0c075768;
case 0x0c07576au: goto P_0c07576a;
case 0x0c07576cu: goto P_0c07576c;
case 0x0c07576eu: goto P_0c07576e;
case 0x0c075790u: goto P_0c075790;
case 0x0c075792u: goto P_0c075792;
case 0x0c075794u: goto P_0c075794;
case 0x0c075796u: goto P_0c075796;
case 0x0c075798u: goto P_0c075798;
case 0x0c07579au: goto P_0c07579a;
case 0x0c07579cu: goto P_0c07579c;
case 0x0c07579eu: goto P_0c07579e;
case 0x0c0757a0u: goto P_0c0757a0;
case 0x0c0757a2u: goto P_0c0757a2;
case 0x0c0757a4u: goto P_0c0757a4;
case 0x0c0757a6u: goto P_0c0757a6;
case 0x0c0757a8u: goto P_0c0757a8;
case 0x0c0757aau: goto P_0c0757aa;
case 0x0c0757acu: goto P_0c0757ac;
case 0x0c0757aeu: goto P_0c0757ae;
case 0x0c0757b0u: goto P_0c0757b0;
case 0x0c0757b2u: goto P_0c0757b2;
case 0x0c0757b4u: goto P_0c0757b4;
case 0x0c0757b6u: goto P_0c0757b6;
case 0x0c0757b8u: goto P_0c0757b8;
case 0x0c0757bau: goto P_0c0757ba;
case 0x0c0757bcu: goto P_0c0757bc;
case 0x0c0757beu: goto P_0c0757be;
case 0x0c0757c0u: goto P_0c0757c0;
case 0x0c0757c2u: goto P_0c0757c2;
case 0x0c0757c4u: goto P_0c0757c4;
case 0x0c0757c6u: goto P_0c0757c6;
case 0x0c0757c8u: goto P_0c0757c8;
case 0x0c0757cau: goto P_0c0757ca;
case 0x0c0757ccu: goto P_0c0757cc;
case 0x0c0757ceu: goto P_0c0757ce;
case 0x0c0757d0u: goto P_0c0757d0;
case 0x0c0757d2u: goto P_0c0757d2;
case 0x0c0757d4u: goto P_0c0757d4;
case 0x0c0757d6u: goto P_0c0757d6;
case 0x0c0757d8u: goto P_0c0757d8;
case 0x0c0757dau: goto P_0c0757da;
case 0x0c0757dcu: goto P_0c0757dc;
case 0x0c0757deu: goto P_0c0757de;
case 0x0c0757e0u: goto P_0c0757e0;
case 0x0c0757e2u: goto P_0c0757e2;
case 0x0c0757e4u: goto P_0c0757e4;
case 0x0c0757e6u: goto P_0c0757e6;
case 0x0c0757e8u: goto P_0c0757e8;
case 0x0c0757eau: goto P_0c0757ea;
case 0x0c0757ecu: goto P_0c0757ec;
case 0x0c0757eeu: goto P_0c0757ee;
case 0x0c0757f0u: goto P_0c0757f0;
case 0x0c0757f2u: goto P_0c0757f2;
case 0x0c0757f4u: goto P_0c0757f4;
case 0x0c0757f6u: goto P_0c0757f6;
case 0x0c0757f8u: goto P_0c0757f8;
case 0x0c0757fau: goto P_0c0757fa;
case 0x0c0757fcu: goto P_0c0757fc;
case 0x0c0757feu: goto P_0c0757fe;
case 0x0c075800u: goto P_0c075800;
case 0x0c075802u: goto P_0c075802;
case 0x0c075804u: goto P_0c075804;
case 0x0c075806u: goto P_0c075806;
case 0x0c075808u: goto P_0c075808;
case 0x0c07580au: goto P_0c07580a;
case 0x0c07580cu: goto P_0c07580c;
case 0x0c07580eu: goto P_0c07580e;
case 0x0c075810u: goto P_0c075810;
case 0x0c075812u: goto P_0c075812;
case 0x0c075814u: goto P_0c075814;
case 0x0c075816u: goto P_0c075816;
case 0x0c075818u: goto P_0c075818;
case 0x0c07581au: goto P_0c07581a;
case 0x0c07581cu: goto P_0c07581c;
case 0x0c07581eu: goto P_0c07581e;
case 0x0c075820u: goto P_0c075820;
case 0x0c075822u: goto P_0c075822;
case 0x0c075824u: goto P_0c075824;
case 0x0c075826u: goto P_0c075826;
case 0x0c075828u: goto P_0c075828;
case 0x0c07582au: goto P_0c07582a;
case 0x0c07582cu: goto P_0c07582c;
case 0x0c07582eu: goto P_0c07582e;
case 0x0c075830u: goto P_0c075830;
case 0x0c075832u: goto P_0c075832;
case 0x0c075834u: goto P_0c075834;
case 0x0c075836u: goto P_0c075836;
case 0x0c075838u: goto P_0c075838;
case 0x0c07583au: goto P_0c07583a;
case 0x0c07583cu: goto P_0c07583c;
case 0x0c07583eu: goto P_0c07583e;
case 0x0c075840u: goto P_0c075840;
case 0x0c075842u: goto P_0c075842;
case 0x0c075844u: goto P_0c075844;
case 0x0c075846u: goto P_0c075846;
case 0x0c075848u: goto P_0c075848;
case 0x0c07584au: goto P_0c07584a;
case 0x0c07584cu: goto P_0c07584c;
case 0x0c07584eu: goto P_0c07584e;
case 0x0c075850u: goto P_0c075850;
case 0x0c075852u: goto P_0c075852;
case 0x0c075854u: goto P_0c075854;
case 0x0c075856u: goto P_0c075856;
case 0x0c075858u: goto P_0c075858;
case 0x0c07585au: goto P_0c07585a;
case 0x0c07585cu: goto P_0c07585c;
case 0x0c07585eu: goto P_0c07585e;
case 0x0c075860u: goto P_0c075860;
case 0x0c075862u: goto P_0c075862;
case 0x0c075864u: goto P_0c075864;
case 0x0c075866u: goto P_0c075866;
case 0x0c075868u: goto P_0c075868;
case 0x0c07586au: goto P_0c07586a;
case 0x0c07586cu: goto P_0c07586c;
case 0x0c07586eu: goto P_0c07586e;
case 0x0c075870u: goto P_0c075870;
case 0x0c075872u: goto P_0c075872;
case 0x0c075874u: goto P_0c075874;
case 0x0c075876u: goto P_0c075876;
case 0x0c075878u: goto P_0c075878;
case 0x0c07587au: goto P_0c07587a;
case 0x0c07587cu: goto P_0c07587c;
case 0x0c07587eu: goto P_0c07587e;
case 0x0c075880u: goto P_0c075880;
case 0x0c075882u: goto P_0c075882;
case 0x0c075884u: goto P_0c075884;
case 0x0c075886u: goto P_0c075886;
case 0x0c075888u: goto P_0c075888;
case 0x0c07588au: goto P_0c07588a;
case 0x0c07588cu: goto P_0c07588c;
case 0x0c07588eu: goto P_0c07588e;
case 0x0c075890u: goto P_0c075890;
case 0x0c075892u: goto P_0c075892;
case 0x0c075894u: goto P_0c075894;
case 0x0c075896u: goto P_0c075896;
case 0x0c075898u: goto P_0c075898;
case 0x0c07589au: goto P_0c07589a;
case 0x0c07589cu: goto P_0c07589c;
case 0x0c07589eu: goto P_0c07589e;
case 0x0c0758a0u: goto P_0c0758a0;
case 0x0c0758a2u: goto P_0c0758a2;
case 0x0c0758a4u: goto P_0c0758a4;
case 0x0c0758a6u: goto P_0c0758a6;
case 0x0c0758a8u: goto P_0c0758a8;
case 0x0c0758dcu: goto P_0c0758dc;
case 0x0c0758deu: goto P_0c0758de;
case 0x0c0758e0u: goto P_0c0758e0;
case 0x0c0758e2u: goto P_0c0758e2;
case 0x0c0758e4u: goto P_0c0758e4;
case 0x0c0758e6u: goto P_0c0758e6;
case 0x0c0758e8u: goto P_0c0758e8;
case 0x0c0758eau: goto P_0c0758ea;
case 0x0c0758ecu: goto P_0c0758ec;
case 0x0c0758eeu: goto P_0c0758ee;
case 0x0c0758f0u: goto P_0c0758f0;
case 0x0c0758f2u: goto P_0c0758f2;
case 0x0c0758f4u: goto P_0c0758f4;
case 0x0c0758f6u: goto P_0c0758f6;
case 0x0c0758f8u: goto P_0c0758f8;
case 0x0c0758fau: goto P_0c0758fa;
case 0x0c0758fcu: goto P_0c0758fc;
case 0x0c0758feu: goto P_0c0758fe;
case 0x0c075900u: goto P_0c075900;
case 0x0c075902u: goto P_0c075902;
case 0x0c075904u: goto P_0c075904;
case 0x0c075906u: goto P_0c075906;
case 0x0c075908u: goto P_0c075908;
case 0x0c07590au: goto P_0c07590a;
case 0x0c07590cu: goto P_0c07590c;
case 0x0c07590eu: goto P_0c07590e;
case 0x0c075910u: goto P_0c075910;
case 0x0c075912u: goto P_0c075912;
case 0x0c075914u: goto P_0c075914;
case 0x0c075916u: goto P_0c075916;
case 0x0c075918u: goto P_0c075918;
case 0x0c07591au: goto P_0c07591a;
case 0x0c07591cu: goto P_0c07591c;
case 0x0c07591eu: goto P_0c07591e;
case 0x0c075920u: goto P_0c075920;
case 0x0c075922u: goto P_0c075922;
case 0x0c075924u: goto P_0c075924;
case 0x0c075926u: goto P_0c075926;
case 0x0c075928u: goto P_0c075928;
case 0x0c07592au: goto P_0c07592a;
case 0x0c07592cu: goto P_0c07592c;
case 0x0c07592eu: goto P_0c07592e;
case 0x0c075930u: goto P_0c075930;
case 0x0c075932u: goto P_0c075932;
case 0x0c075934u: goto P_0c075934;
case 0x0c075936u: goto P_0c075936;
case 0x0c075938u: goto P_0c075938;
case 0x0c07593au: goto P_0c07593a;
case 0x0c07593cu: goto P_0c07593c;
case 0x0c07593eu: goto P_0c07593e;
case 0x0c075940u: goto P_0c075940;
case 0x0c075942u: goto P_0c075942;
case 0x0c075944u: goto P_0c075944;
case 0x0c075946u: goto P_0c075946;
case 0x0c075948u: goto P_0c075948;
case 0x0c07594au: goto P_0c07594a;
case 0x0c07594cu: goto P_0c07594c;
case 0x0c07594eu: goto P_0c07594e;
case 0x0c075950u: goto P_0c075950;
case 0x0c075952u: goto P_0c075952;
case 0x0c075954u: goto P_0c075954;
case 0x0c075956u: goto P_0c075956;
case 0x0c075958u: goto P_0c075958;
case 0x0c07595au: goto P_0c07595a;
case 0x0c07595cu: goto P_0c07595c;
case 0x0c07595eu: goto P_0c07595e;
case 0x0c075960u: goto P_0c075960;
case 0x0c075962u: goto P_0c075962;
case 0x0c075964u: goto P_0c075964;
case 0x0c075966u: goto P_0c075966;
case 0x0c075968u: goto P_0c075968;
case 0x0c07596au: goto P_0c07596a;
case 0x0c07596cu: goto P_0c07596c;
case 0x0c07596eu: goto P_0c07596e;
case 0x0c075970u: goto P_0c075970;
case 0x0c075972u: goto P_0c075972;
case 0x0c075974u: goto P_0c075974;
case 0x0c075976u: goto P_0c075976;
case 0x0c075978u: goto P_0c075978;
case 0x0c07597au: goto P_0c07597a;
case 0x0c07597cu: goto P_0c07597c;
case 0x0c07597eu: goto P_0c07597e;
case 0x0c075980u: goto P_0c075980;
case 0x0c075982u: goto P_0c075982;
case 0x0c075984u: goto P_0c075984;
case 0x0c075986u: goto P_0c075986;
case 0x0c075988u: goto P_0c075988;
case 0x0c07598au: goto P_0c07598a;
case 0x0c07598cu: goto P_0c07598c;
case 0x0c07598eu: goto P_0c07598e;
case 0x0c075990u: goto P_0c075990;
case 0x0c075992u: goto P_0c075992;
case 0x0c075994u: goto P_0c075994;
case 0x0c075996u: goto P_0c075996;
case 0x0c075998u: goto P_0c075998;
case 0x0c07599au: goto P_0c07599a;
case 0x0c07599cu: goto P_0c07599c;
case 0x0c07599eu: goto P_0c07599e;
case 0x0c0759a0u: goto P_0c0759a0;
case 0x0c0759a2u: goto P_0c0759a2;
case 0x0c0759a4u: goto P_0c0759a4;
case 0x0c0759a6u: goto P_0c0759a6;
case 0x0c0759a8u: goto P_0c0759a8;
case 0x0c0759aau: goto P_0c0759aa;
case 0x0c0759acu: goto P_0c0759ac;
case 0x0c0759aeu: goto P_0c0759ae;
case 0x0c0759b0u: goto P_0c0759b0;
case 0x0c0759b2u: goto P_0c0759b2;
case 0x0c0759b4u: goto P_0c0759b4;
case 0x0c0759b6u: goto P_0c0759b6;
case 0x0c0759b8u: goto P_0c0759b8;
case 0x0c0759bau: goto P_0c0759ba;
case 0x0c0759bcu: goto P_0c0759bc;
case 0x0c0759beu: goto P_0c0759be;
case 0x0c0759c0u: goto P_0c0759c0;
case 0x0c0759c2u: goto P_0c0759c2;
case 0x0c0759c4u: goto P_0c0759c4;
case 0x0c0759c6u: goto P_0c0759c6;
case 0x0c0759c8u: goto P_0c0759c8;
case 0x0c0759cau: goto P_0c0759ca;
case 0x0c0759ccu: goto P_0c0759cc;
case 0x0c0759ceu: goto P_0c0759ce;
case 0x0c0759d0u: goto P_0c0759d0;
case 0x0c0759d2u: goto P_0c0759d2;
case 0x0c0759d4u: goto P_0c0759d4;
case 0x0c0759d6u: goto P_0c0759d6;
case 0x0c0759d8u: goto P_0c0759d8;
case 0x0c0759dau: goto P_0c0759da;
case 0x0c0759dcu: goto P_0c0759dc;
case 0x0c0759deu: goto P_0c0759de;
case 0x0c0759e0u: goto P_0c0759e0;
case 0x0c0759e2u: goto P_0c0759e2;
case 0x0c0759e4u: goto P_0c0759e4;
case 0x0c0759e6u: goto P_0c0759e6;
case 0x0c0759e8u: goto P_0c0759e8;
case 0x0c0759eau: goto P_0c0759ea;
case 0x0c0759ecu: goto P_0c0759ec;
case 0x0c0759eeu: goto P_0c0759ee;
case 0x0c075a24u: goto P_0c075a24;
case 0x0c075a26u: goto P_0c075a26;
case 0x0c075a28u: goto P_0c075a28;
case 0x0c075a2au: goto P_0c075a2a;
case 0x0c075a2cu: goto P_0c075a2c;
case 0x0c075a2eu: goto P_0c075a2e;
case 0x0c075a30u: goto P_0c075a30;
case 0x0c075a32u: goto P_0c075a32;
case 0x0c075a34u: goto P_0c075a34;
case 0x0c075a36u: goto P_0c075a36;
case 0x0c075a38u: goto P_0c075a38;
case 0x0c075a3au: goto P_0c075a3a;
case 0x0c075a3cu: goto P_0c075a3c;
case 0x0c075a3eu: goto P_0c075a3e;
case 0x0c075a40u: goto P_0c075a40;
case 0x0c075a42u: goto P_0c075a42;
case 0x0c075a44u: goto P_0c075a44;
case 0x0c075a46u: goto P_0c075a46;
case 0x0c075a48u: goto P_0c075a48;
case 0x0c075a4au: goto P_0c075a4a;
case 0x0c075a4cu: goto P_0c075a4c;
case 0x0c075a4eu: goto P_0c075a4e;
case 0x0c075a50u: goto P_0c075a50;
case 0x0c075a52u: goto P_0c075a52;
case 0x0c075a54u: goto P_0c075a54;
case 0x0c075a56u: goto P_0c075a56;
case 0x0c075a58u: goto P_0c075a58;
case 0x0c075a5au: goto P_0c075a5a;
case 0x0c075a5cu: goto P_0c075a5c;
case 0x0c075a5eu: goto P_0c075a5e;
case 0x0c075a60u: goto P_0c075a60;
case 0x0c075a62u: goto P_0c075a62;
case 0x0c075a64u: goto P_0c075a64;
case 0x0c075a66u: goto P_0c075a66;
case 0x0c075a68u: goto P_0c075a68;
case 0x0c075a6au: goto P_0c075a6a;
case 0x0c075a6cu: goto P_0c075a6c;
case 0x0c075a6eu: goto P_0c075a6e;
case 0x0c075a70u: goto P_0c075a70;
case 0x0c075a72u: goto P_0c075a72;
case 0x0c075a74u: goto P_0c075a74;
case 0x0c075a76u: goto P_0c075a76;
case 0x0c075a78u: goto P_0c075a78;
case 0x0c075a7au: goto P_0c075a7a;
case 0x0c075a7cu: goto P_0c075a7c;
case 0x0c075a7eu: goto P_0c075a7e;
case 0x0c075a80u: goto P_0c075a80;
case 0x0c075a82u: goto P_0c075a82;
case 0x0c075a84u: goto P_0c075a84;
case 0x0c075a86u: goto P_0c075a86;
case 0x0c075a88u: goto P_0c075a88;
case 0x0c075a8au: goto P_0c075a8a;
case 0x0c075a8cu: goto P_0c075a8c;
case 0x0c075a8eu: goto P_0c075a8e;
case 0x0c075a90u: goto P_0c075a90;
case 0x0c075a92u: goto P_0c075a92;
case 0x0c075a94u: goto P_0c075a94;
case 0x0c075a96u: goto P_0c075a96;
case 0x0c075a98u: goto P_0c075a98;
case 0x0c075a9au: goto P_0c075a9a;
case 0x0c075a9cu: goto P_0c075a9c;
case 0x0c075a9eu: goto P_0c075a9e;
case 0x0c075aa0u: goto P_0c075aa0;
case 0x0c075aa2u: goto P_0c075aa2;
case 0x0c075aa4u: goto P_0c075aa4;
case 0x0c075aa6u: goto P_0c075aa6;
case 0x0c075aa8u: goto P_0c075aa8;
case 0x0c075aaau: goto P_0c075aaa;
case 0x0c075aacu: goto P_0c075aac;
case 0x0c075aaeu: goto P_0c075aae;
case 0x0c075ab0u: goto P_0c075ab0;
case 0x0c075ab2u: goto P_0c075ab2;
case 0x0c075ab4u: goto P_0c075ab4;
case 0x0c075ab6u: goto P_0c075ab6;
case 0x0c075ab8u: goto P_0c075ab8;
case 0x0c075abau: goto P_0c075aba;
case 0x0c075abcu: goto P_0c075abc;
case 0x0c075abeu: goto P_0c075abe;
case 0x0c075ac0u: goto P_0c075ac0;
case 0x0c075ac2u: goto P_0c075ac2;
case 0x0c075ac4u: goto P_0c075ac4;
case 0x0c075ac6u: goto P_0c075ac6;
case 0x0c075ac8u: goto P_0c075ac8;
case 0x0c075acau: goto P_0c075aca;
case 0x0c075accu: goto P_0c075acc;
case 0x0c075aceu: goto P_0c075ace;
case 0x0c075ad0u: goto P_0c075ad0;
case 0x0c075ad2u: goto P_0c075ad2;
case 0x0c075ad4u: goto P_0c075ad4;
case 0x0c075ad6u: goto P_0c075ad6;
case 0x0c075ad8u: goto P_0c075ad8;
case 0x0c075adau: goto P_0c075ada;
case 0x0c075adcu: goto P_0c075adc;
case 0x0c075adeu: goto P_0c075ade;
case 0x0c075ae0u: goto P_0c075ae0;
case 0x0c075b0cu: goto P_0c075b0c;
case 0x0c075b0eu: goto P_0c075b0e;
case 0x0c075b10u: goto P_0c075b10;
case 0x0c075b12u: goto P_0c075b12;
case 0x0c075b14u: goto P_0c075b14;
case 0x0c075b16u: goto P_0c075b16;
case 0x0c075b18u: goto P_0c075b18;
case 0x0c075b1au: goto P_0c075b1a;
case 0x0c075b1cu: goto P_0c075b1c;
case 0x0c075b1eu: goto P_0c075b1e;
case 0x0c075b20u: goto P_0c075b20;
case 0x0c075b22u: goto P_0c075b22;
case 0x0c075b24u: goto P_0c075b24;
case 0x0c075b26u: goto P_0c075b26;
case 0x0c075b28u: goto P_0c075b28;
case 0x0c075b2au: goto P_0c075b2a;
case 0x0c075b2cu: goto P_0c075b2c;
case 0x0c075b2eu: goto P_0c075b2e;
case 0x0c075b30u: goto P_0c075b30;
case 0x0c075b32u: goto P_0c075b32;
case 0x0c075b34u: goto P_0c075b34;
case 0x0c075b36u: goto P_0c075b36;
case 0x0c075b38u: goto P_0c075b38;
case 0x0c075b3au: goto P_0c075b3a;
case 0x0c075b3cu: goto P_0c075b3c;
case 0x0c075b3eu: goto P_0c075b3e;
case 0x0c075b40u: goto P_0c075b40;
case 0x0c075b42u: goto P_0c075b42;
case 0x0c075b44u: goto P_0c075b44;
case 0x0c075b46u: goto P_0c075b46;
case 0x0c075b48u: goto P_0c075b48;
case 0x0c075b4au: goto P_0c075b4a;
case 0x0c075b4cu: goto P_0c075b4c;
case 0x0c075b4eu: goto P_0c075b4e;
case 0x0c075b50u: goto P_0c075b50;
case 0x0c075b52u: goto P_0c075b52;
case 0x0c075b54u: goto P_0c075b54;
case 0x0c075b56u: goto P_0c075b56;
case 0x0c075b58u: goto P_0c075b58;
case 0x0c075b5au: goto P_0c075b5a;
case 0x0c075b5cu: goto P_0c075b5c;
case 0x0c075b5eu: goto P_0c075b5e;
case 0x0c075b60u: goto P_0c075b60;
case 0x0c075b62u: goto P_0c075b62;
case 0x0c075b64u: goto P_0c075b64;
case 0x0c075b66u: goto P_0c075b66;
case 0x0c075b68u: goto P_0c075b68;
case 0x0c075b6au: goto P_0c075b6a;
case 0x0c075b6cu: goto P_0c075b6c;
case 0x0c075b6eu: goto P_0c075b6e;
case 0x0c075b70u: goto P_0c075b70;
case 0x0c075b72u: goto P_0c075b72;
case 0x0c075b74u: goto P_0c075b74;
case 0x0c075b76u: goto P_0c075b76;
case 0x0c075b78u: goto P_0c075b78;
case 0x0c075b7au: goto P_0c075b7a;
case 0x0c075b7cu: goto P_0c075b7c;
case 0x0c075b7eu: goto P_0c075b7e;
case 0x0c075b80u: goto P_0c075b80;
case 0x0c075b82u: goto P_0c075b82;
case 0x0c075b84u: goto P_0c075b84;
case 0x0c075b86u: goto P_0c075b86;
case 0x0c075b88u: goto P_0c075b88;
case 0x0c075b8au: goto P_0c075b8a;
case 0x0c075b8cu: goto P_0c075b8c;
case 0x0c075b8eu: goto P_0c075b8e;
case 0x0c075b90u: goto P_0c075b90;
case 0x0c075b92u: goto P_0c075b92;
case 0x0c075b94u: goto P_0c075b94;
case 0x0c075b96u: goto P_0c075b96;
case 0x0c075b98u: goto P_0c075b98;
case 0x0c075b9au: goto P_0c075b9a;
case 0x0c075b9cu: goto P_0c075b9c;
case 0x0c075b9eu: goto P_0c075b9e;
case 0x0c075ba0u: goto P_0c075ba0;
case 0x0c075ba2u: goto P_0c075ba2;
case 0x0c075ba4u: goto P_0c075ba4;
case 0x0c075ba6u: goto P_0c075ba6;
case 0x0c075ba8u: goto P_0c075ba8;
case 0x0c075baau: goto P_0c075baa;
case 0x0c075bacu: goto P_0c075bac;
case 0x0c075baeu: goto P_0c075bae;
case 0x0c075bb0u: goto P_0c075bb0;
case 0x0c075bb2u: goto P_0c075bb2;
case 0x0c075bb4u: goto P_0c075bb4;
case 0x0c075bb6u: goto P_0c075bb6;
case 0x0c075bb8u: goto P_0c075bb8;
case 0x0c075bbau: goto P_0c075bba;
case 0x0c075bbcu: goto P_0c075bbc;
case 0x0c075bbeu: goto P_0c075bbe;
case 0x0c075bc0u: goto P_0c075bc0;
case 0x0c075bc2u: goto P_0c075bc2;
case 0x0c075bc4u: goto P_0c075bc4;
case 0x0c075bc6u: goto P_0c075bc6;
case 0x0c075bc8u: goto P_0c075bc8;
case 0x0c075bcau: goto P_0c075bca;
case 0x0c075bccu: goto P_0c075bcc;
case 0x0c075bceu: goto P_0c075bce;
case 0x0c075bd0u: goto P_0c075bd0;
case 0x0c075bd2u: goto P_0c075bd2;
case 0x0c075bd4u: goto P_0c075bd4;
case 0x0c075bd6u: goto P_0c075bd6;
case 0x0c075bd8u: goto P_0c075bd8;
case 0x0c075bdau: goto P_0c075bda;
case 0x0c075bdcu: goto P_0c075bdc;
case 0x0c075bdeu: goto P_0c075bde;
case 0x0c075be0u: goto P_0c075be0;
case 0x0c075be2u: goto P_0c075be2;
case 0x0c075be4u: goto P_0c075be4;
case 0x0c075be6u: goto P_0c075be6;
case 0x0c075be8u: goto P_0c075be8;
case 0x0c075beau: goto P_0c075bea;
case 0x0c075becu: goto P_0c075bec;
case 0x0c075beeu: goto P_0c075bee;
case 0x0c075bf0u: goto P_0c075bf0;
case 0x0c075bf2u: goto P_0c075bf2;
case 0x0c075bf4u: goto P_0c075bf4;
case 0x0c075bf6u: goto P_0c075bf6;
case 0x0c075bf8u: goto P_0c075bf8;
case 0x0c075bfau: goto P_0c075bfa;
case 0x0c075bfcu: goto P_0c075bfc;
case 0x0c075bfeu: goto P_0c075bfe;
case 0x0c075c00u: goto P_0c075c00;
case 0x0c075c02u: goto P_0c075c02;
case 0x0c075c04u: goto P_0c075c04;
case 0x0c075c06u: goto P_0c075c06;
case 0x0c075c08u: goto P_0c075c08;
case 0x0c075c0au: goto P_0c075c0a;
case 0x0c075c0cu: goto P_0c075c0c;
case 0x0c075c0eu: goto P_0c075c0e;
case 0x0c075c44u: goto P_0c075c44;
case 0x0c075c46u: goto P_0c075c46;
case 0x0c075c48u: goto P_0c075c48;
case 0x0c075c4au: goto P_0c075c4a;
case 0x0c075c4cu: goto P_0c075c4c;
case 0x0c075c4eu: goto P_0c075c4e;
case 0x0c075c50u: goto P_0c075c50;
case 0x0c075c52u: goto P_0c075c52;
case 0x0c075c54u: goto P_0c075c54;
case 0x0c075c56u: goto P_0c075c56;
case 0x0c075c58u: goto P_0c075c58;
case 0x0c075c5au: goto P_0c075c5a;
case 0x0c075c5cu: goto P_0c075c5c;
case 0x0c075c5eu: goto P_0c075c5e;
case 0x0c075c60u: goto P_0c075c60;
case 0x0c075c62u: goto P_0c075c62;
case 0x0c075c64u: goto P_0c075c64;
case 0x0c075c66u: goto P_0c075c66;
case 0x0c075c68u: goto P_0c075c68;
case 0x0c075c6au: goto P_0c075c6a;
case 0x0c075c6cu: goto P_0c075c6c;
case 0x0c075c6eu: goto P_0c075c6e;
case 0x0c075c70u: goto P_0c075c70;
case 0x0c075c72u: goto P_0c075c72;
case 0x0c075c74u: goto P_0c075c74;
case 0x0c075c76u: goto P_0c075c76;
case 0x0c075c78u: goto P_0c075c78;
case 0x0c075c7au: goto P_0c075c7a;
case 0x0c075c7cu: goto P_0c075c7c;
case 0x0c075c7eu: goto P_0c075c7e;
case 0x0c075c80u: goto P_0c075c80;
case 0x0c075c82u: goto P_0c075c82;
case 0x0c075c84u: goto P_0c075c84;
case 0x0c075c86u: goto P_0c075c86;
case 0x0c075c88u: goto P_0c075c88;
case 0x0c075c8au: goto P_0c075c8a;
case 0x0c075c8cu: goto P_0c075c8c;
case 0x0c075c8eu: goto P_0c075c8e;
case 0x0c075c90u: goto P_0c075c90;
case 0x0c075c92u: goto P_0c075c92;
case 0x0c075c94u: goto P_0c075c94;
case 0x0c075c96u: goto P_0c075c96;
case 0x0c075c98u: goto P_0c075c98;
case 0x0c075c9au: goto P_0c075c9a;
case 0x0c075c9cu: goto P_0c075c9c;
case 0x0c075c9eu: goto P_0c075c9e;
case 0x0c075ca0u: goto P_0c075ca0;
case 0x0c075ca2u: goto P_0c075ca2;
case 0x0c075ca4u: goto P_0c075ca4;
case 0x0c075ca6u: goto P_0c075ca6;
case 0x0c075ca8u: goto P_0c075ca8;
case 0x0c075caau: goto P_0c075caa;
case 0x0c075cacu: goto P_0c075cac;
case 0x0c075caeu: goto P_0c075cae;
case 0x0c075cb0u: goto P_0c075cb0;
case 0x0c075cb2u: goto P_0c075cb2;
case 0x0c075cb4u: goto P_0c075cb4;
case 0x0c075cb6u: goto P_0c075cb6;
case 0x0c075cb8u: goto P_0c075cb8;
case 0x0c075cbau: goto P_0c075cba;
case 0x0c075cbcu: goto P_0c075cbc;
case 0x0c075cbeu: goto P_0c075cbe;
case 0x0c075cc0u: goto P_0c075cc0;
case 0x0c075cc2u: goto P_0c075cc2;
case 0x0c075cc4u: goto P_0c075cc4;
case 0x0c075cc6u: goto P_0c075cc6;
case 0x0c075cc8u: goto P_0c075cc8;
case 0x0c075ccau: goto P_0c075cca;
case 0x0c075ce4u: goto P_0c075ce4;
case 0x0c075ce6u: goto P_0c075ce6;
case 0x0c075ce8u: goto P_0c075ce8;
case 0x0c075ceau: goto P_0c075cea;
case 0x0c075cecu: goto P_0c075cec;
case 0x0c075ceeu: goto P_0c075cee;
case 0x0c075cf0u: goto P_0c075cf0;
case 0x0c075cf2u: goto P_0c075cf2;
case 0x0c075cf4u: goto P_0c075cf4;
case 0x0c075cf6u: goto P_0c075cf6;
case 0x0c075cf8u: goto P_0c075cf8;
case 0x0c075cfau: goto P_0c075cfa;
case 0x0c075cfcu: goto P_0c075cfc;
case 0x0c075cfeu: goto P_0c075cfe;
case 0x0c075d00u: goto P_0c075d00;
case 0x0c075d02u: goto P_0c075d02;
case 0x0c075d04u: goto P_0c075d04;
case 0x0c075d06u: goto P_0c075d06;
case 0x0c075d08u: goto P_0c075d08;
case 0x0c075d0au: goto P_0c075d0a;
case 0x0c075d0cu: goto P_0c075d0c;
case 0x0c075d0eu: goto P_0c075d0e;
case 0x0c075d10u: goto P_0c075d10;
case 0x0c075d12u: goto P_0c075d12;
case 0x0c075d14u: goto P_0c075d14;
case 0x0c075d16u: goto P_0c075d16;
case 0x0c075d18u: goto P_0c075d18;
case 0x0c075d1au: goto P_0c075d1a;
case 0x0c075d1cu: goto P_0c075d1c;
case 0x0c075d1eu: goto P_0c075d1e;
case 0x0c075d20u: goto P_0c075d20;
case 0x0c075d22u: goto P_0c075d22;
case 0x0c075d24u: goto P_0c075d24;
case 0x0c075d26u: goto P_0c075d26;
case 0x0c075d28u: goto P_0c075d28;
case 0x0c075d2au: goto P_0c075d2a;
case 0x0c075d2cu: goto P_0c075d2c;
case 0x0c075d2eu: goto P_0c075d2e;
case 0x0c075d30u: goto P_0c075d30;
case 0x0c075d32u: goto P_0c075d32;
case 0x0c075d34u: goto P_0c075d34;
case 0x0c075d36u: goto P_0c075d36;
case 0x0c075d38u: goto P_0c075d38;
case 0x0c075d3au: goto P_0c075d3a;
case 0x0c075d3cu: goto P_0c075d3c;
case 0x0c075d3eu: goto P_0c075d3e;
case 0x0c075d40u: goto P_0c075d40;
case 0x0c075d42u: goto P_0c075d42;
case 0x0c075d44u: goto P_0c075d44;
case 0x0c075d46u: goto P_0c075d46;
case 0x0c075d48u: goto P_0c075d48;
case 0x0c075d4au: goto P_0c075d4a;
case 0x0c075d4cu: goto P_0c075d4c;
case 0x0c075d4eu: goto P_0c075d4e;
case 0x0c075d50u: goto P_0c075d50;
case 0x0c075d52u: goto P_0c075d52;
case 0x0c075d54u: goto P_0c075d54;
case 0x0c075d56u: goto P_0c075d56;
case 0x0c075d58u: goto P_0c075d58;
case 0x0c075d5au: goto P_0c075d5a;
case 0x0c075d5cu: goto P_0c075d5c;
case 0x0c075d5eu: goto P_0c075d5e;
case 0x0c075d60u: goto P_0c075d60;
case 0x0c075d62u: goto P_0c075d62;
case 0x0c075d64u: goto P_0c075d64;
case 0x0c075d66u: goto P_0c075d66;
case 0x0c075d68u: goto P_0c075d68;
case 0x0c075d6au: goto P_0c075d6a;
case 0x0c075d6cu: goto P_0c075d6c;
case 0x0c075d6eu: goto P_0c075d6e;
case 0x0c075d70u: goto P_0c075d70;
case 0x0c075d72u: goto P_0c075d72;
case 0x0c075d74u: goto P_0c075d74;
case 0x0c075d76u: goto P_0c075d76;
case 0x0c075d78u: goto P_0c075d78;
case 0x0c075d7au: goto P_0c075d7a;
case 0x0c075d7cu: goto P_0c075d7c;
case 0x0c075d7eu: goto P_0c075d7e;
case 0x0c075d80u: goto P_0c075d80;
case 0x0c075d82u: goto P_0c075d82;
case 0x0c075d84u: goto P_0c075d84;
case 0x0c075d86u: goto P_0c075d86;
case 0x0c075d88u: goto P_0c075d88;
case 0x0c075d8au: goto P_0c075d8a;
case 0x0c075d8cu: goto P_0c075d8c;
case 0x0c075d8eu: goto P_0c075d8e;
case 0x0c075d90u: goto P_0c075d90;
case 0x0c075d92u: goto P_0c075d92;
case 0x0c075d94u: goto P_0c075d94;
case 0x0c075d96u: goto P_0c075d96;
case 0x0c075d98u: goto P_0c075d98;
case 0x0c075d9au: goto P_0c075d9a;
case 0x0c075d9cu: goto P_0c075d9c;
case 0x0c075d9eu: goto P_0c075d9e;
case 0x0c075da0u: goto P_0c075da0;
case 0x0c075da2u: goto P_0c075da2;
case 0x0c075da4u: goto P_0c075da4;
case 0x0c075da6u: goto P_0c075da6;
case 0x0c075da8u: goto P_0c075da8;
case 0x0c075daau: goto P_0c075daa;
case 0x0c075dacu: goto P_0c075dac;
case 0x0c075daeu: goto P_0c075dae;
case 0x0c075db0u: goto P_0c075db0;
case 0x0c075db2u: goto P_0c075db2;
case 0x0c075db4u: goto P_0c075db4;
case 0x0c075db6u: goto P_0c075db6;
case 0x0c075db8u: goto P_0c075db8;
case 0x0c075dbau: goto P_0c075dba;
case 0x0c075dbcu: goto P_0c075dbc;
case 0x0c075dbeu: goto P_0c075dbe;
case 0x0c075dc0u: goto P_0c075dc0;
case 0x0c075dc2u: goto P_0c075dc2;
case 0x0c075dc4u: goto P_0c075dc4;
case 0x0c075dc6u: goto P_0c075dc6;
case 0x0c075dc8u: goto P_0c075dc8;
case 0x0c075dcau: goto P_0c075dca;
case 0x0c075dccu: goto P_0c075dcc;
case 0x0c075dceu: goto P_0c075dce;
case 0x0c075dd0u: goto P_0c075dd0;
case 0x0c075dd2u: goto P_0c075dd2;
case 0x0c075dd4u: goto P_0c075dd4;
case 0x0c075dd6u: goto P_0c075dd6;
case 0x0c075dd8u: goto P_0c075dd8;
case 0x0c075ddau: goto P_0c075dda;
case 0x0c075ddcu: goto P_0c075ddc;
case 0x0c075ddeu: goto P_0c075dde;
case 0x0c075de0u: goto P_0c075de0;
case 0x0c075de2u: goto P_0c075de2;
case 0x0c075de4u: goto P_0c075de4;
case 0x0c075de6u: goto P_0c075de6;
case 0x0c075de8u: goto P_0c075de8;
case 0x0c075deau: goto P_0c075dea;
case 0x0c075decu: goto P_0c075dec;
case 0x0c075deeu: goto P_0c075dee;
case 0x0c075df0u: goto P_0c075df0;
case 0x0c075df2u: goto P_0c075df2;
case 0x0c075df4u: goto P_0c075df4;
case 0x0c075df6u: goto P_0c075df6;
case 0x0c075df8u: goto P_0c075df8;
case 0x0c075dfau: goto P_0c075dfa;
case 0x0c075dfcu: goto P_0c075dfc;
case 0x0c075dfeu: goto P_0c075dfe;
case 0x0c075e00u: goto P_0c075e00;
case 0x0c075e02u: goto P_0c075e02;
case 0x0c075e04u: goto P_0c075e04;
case 0x0c075e06u: goto P_0c075e06;
case 0x0c075e08u: goto P_0c075e08;
case 0x0c075e0au: goto P_0c075e0a;
case 0x0c075e0cu: goto P_0c075e0c;
case 0x0c075e0eu: goto P_0c075e0e;
case 0x0c075e2cu: goto P_0c075e2c;
case 0x0c075e2eu: goto P_0c075e2e;
case 0x0c075e30u: goto P_0c075e30;
case 0x0c075e32u: goto P_0c075e32;
case 0x0c075e34u: goto P_0c075e34;
case 0x0c075e36u: goto P_0c075e36;
case 0x0c075e38u: goto P_0c075e38;
case 0x0c075e3au: goto P_0c075e3a;
case 0x0c075e3cu: goto P_0c075e3c;
case 0x0c075e3eu: goto P_0c075e3e;
case 0x0c075e40u: goto P_0c075e40;
case 0x0c075e42u: goto P_0c075e42;
case 0x0c075e44u: goto P_0c075e44;
case 0x0c075e46u: goto P_0c075e46;
case 0x0c075e48u: goto P_0c075e48;
case 0x0c075e4au: goto P_0c075e4a;
case 0x0c075e4cu: goto P_0c075e4c;
case 0x0c075e4eu: goto P_0c075e4e;
case 0x0c075e50u: goto P_0c075e50;
case 0x0c075e52u: goto P_0c075e52;
case 0x0c075e54u: goto P_0c075e54;
case 0x0c075e56u: goto P_0c075e56;
case 0x0c075e58u: goto P_0c075e58;
case 0x0c075e5au: goto P_0c075e5a;
case 0x0c075e5cu: goto P_0c075e5c;
case 0x0c075e5eu: goto P_0c075e5e;
case 0x0c075e60u: goto P_0c075e60;
case 0x0c075e62u: goto P_0c075e62;
case 0x0c075e64u: goto P_0c075e64;
case 0x0c075e66u: goto P_0c075e66;
case 0x0c075e68u: goto P_0c075e68;
case 0x0c075e6au: goto P_0c075e6a;
case 0x0c075e6cu: goto P_0c075e6c;
case 0x0c075e6eu: goto P_0c075e6e;
case 0x0c075e70u: goto P_0c075e70;
case 0x0c075e72u: goto P_0c075e72;
case 0x0c075e74u: goto P_0c075e74;
case 0x0c075e76u: goto P_0c075e76;
case 0x0c075e78u: goto P_0c075e78;
case 0x0c075e7au: goto P_0c075e7a;
case 0x0c075e7cu: goto P_0c075e7c;
case 0x0c075e7eu: goto P_0c075e7e;
case 0x0c075e80u: goto P_0c075e80;
case 0x0c075e82u: goto P_0c075e82;
case 0x0c075e84u: goto P_0c075e84;
case 0x0c075e86u: goto P_0c075e86;
case 0x0c075e88u: goto P_0c075e88;
case 0x0c075e8au: goto P_0c075e8a;
case 0x0c075e8cu: goto P_0c075e8c;
case 0x0c075e8eu: goto P_0c075e8e;
case 0x0c075e90u: goto P_0c075e90;
case 0x0c075e92u: goto P_0c075e92;
case 0x0c075e94u: goto P_0c075e94;
case 0x0c075e96u: goto P_0c075e96;
case 0x0c075e98u: goto P_0c075e98;
case 0x0c075e9au: goto P_0c075e9a;
case 0x0c075e9cu: goto P_0c075e9c;
case 0x0c075e9eu: goto P_0c075e9e;
case 0x0c075ea0u: goto P_0c075ea0;
case 0x0c075ea2u: goto P_0c075ea2;
case 0x0c075ea4u: goto P_0c075ea4;
case 0x0c075ea6u: goto P_0c075ea6;
case 0x0c075ea8u: goto P_0c075ea8;
case 0x0c075eaau: goto P_0c075eaa;
case 0x0c075eacu: goto P_0c075eac;
case 0x0c075eaeu: goto P_0c075eae;
case 0x0c075eb0u: goto P_0c075eb0;
case 0x0c075eb2u: goto P_0c075eb2;
case 0x0c075eb4u: goto P_0c075eb4;
case 0x0c075eb6u: goto P_0c075eb6;
case 0x0c075eb8u: goto P_0c075eb8;
case 0x0c075ebau: goto P_0c075eba;
case 0x0c075ebcu: goto P_0c075ebc;
case 0x0c075ebeu: goto P_0c075ebe;
case 0x0c075ec0u: goto P_0c075ec0;
case 0x0c075ec2u: goto P_0c075ec2;
case 0x0c075ec4u: goto P_0c075ec4;
case 0x0c075ec6u: goto P_0c075ec6;
case 0x0c075ec8u: goto P_0c075ec8;
case 0x0c075ecau: goto P_0c075eca;
case 0x0c075eccu: goto P_0c075ecc;
case 0x0c075eceu: goto P_0c075ece;
case 0x0c075ed0u: goto P_0c075ed0;
case 0x0c075ed2u: goto P_0c075ed2;
case 0x0c075ed4u: goto P_0c075ed4;
case 0x0c075ed6u: goto P_0c075ed6;
case 0x0c075ed8u: goto P_0c075ed8;
case 0x0c075edau: goto P_0c075eda;
case 0x0c075edcu: goto P_0c075edc;
case 0x0c075edeu: goto P_0c075ede;
case 0x0c075ee0u: goto P_0c075ee0;
case 0x0c075ee2u: goto P_0c075ee2;
case 0x0c075ee4u: goto P_0c075ee4;
case 0x0c075ee6u: goto P_0c075ee6;
case 0x0c075ee8u: goto P_0c075ee8;
case 0x0c075eeau: goto P_0c075eea;
case 0x0c075eecu: goto P_0c075eec;
case 0x0c075eeeu: goto P_0c075eee;
case 0x0c075ef0u: goto P_0c075ef0;
case 0x0c075ef2u: goto P_0c075ef2;
case 0x0c075ef4u: goto P_0c075ef4;
case 0x0c075ef6u: goto P_0c075ef6;
case 0x0c075ef8u: goto P_0c075ef8;
case 0x0c075efau: goto P_0c075efa;
case 0x0c075efcu: goto P_0c075efc;
case 0x0c075efeu: goto P_0c075efe;
case 0x0c075f00u: goto P_0c075f00;
case 0x0c075f02u: goto P_0c075f02;
case 0x0c075f04u: goto P_0c075f04;
case 0x0c075f06u: goto P_0c075f06;
case 0x0c075f08u: goto P_0c075f08;
case 0x0c075f0au: goto P_0c075f0a;
case 0x0c075f0cu: goto P_0c075f0c;
case 0x0c075f0eu: goto P_0c075f0e;
case 0x0c075f30u: goto P_0c075f30;
case 0x0c075f32u: goto P_0c075f32;
case 0x0c075f34u: goto P_0c075f34;
case 0x0c075f36u: goto P_0c075f36;
case 0x0c075f38u: goto P_0c075f38;
case 0x0c075f3au: goto P_0c075f3a;
case 0x0c075f3cu: goto P_0c075f3c;
case 0x0c075f3eu: goto P_0c075f3e;
case 0x0c075f40u: goto P_0c075f40;
case 0x0c075f42u: goto P_0c075f42;
case 0x0c075f44u: goto P_0c075f44;
case 0x0c075f46u: goto P_0c075f46;
case 0x0c075f48u: goto P_0c075f48;
case 0x0c075f4au: goto P_0c075f4a;
case 0x0c075f4cu: goto P_0c075f4c;
case 0x0c075f4eu: goto P_0c075f4e;
case 0x0c075f50u: goto P_0c075f50;
case 0x0c075f52u: goto P_0c075f52;
case 0x0c075f54u: goto P_0c075f54;
case 0x0c075f56u: goto P_0c075f56;
case 0x0c075f58u: goto P_0c075f58;
case 0x0c075f5au: goto P_0c075f5a;
case 0x0c075f5cu: goto P_0c075f5c;
case 0x0c075f5eu: goto P_0c075f5e;
case 0x0c075f60u: goto P_0c075f60;
case 0x0c075f62u: goto P_0c075f62;
case 0x0c075f64u: goto P_0c075f64;
case 0x0c075f66u: goto P_0c075f66;
case 0x0c075f68u: goto P_0c075f68;
case 0x0c075f6au: goto P_0c075f6a;
case 0x0c075f6cu: goto P_0c075f6c;
case 0x0c075f6eu: goto P_0c075f6e;
case 0x0c075f70u: goto P_0c075f70;
case 0x0c075f72u: goto P_0c075f72;
case 0x0c075f74u: goto P_0c075f74;
case 0x0c075f76u: goto P_0c075f76;
case 0x0c075f78u: goto P_0c075f78;
case 0x0c075f7au: goto P_0c075f7a;
case 0x0c075f7cu: goto P_0c075f7c;
case 0x0c075f7eu: goto P_0c075f7e;
case 0x0c075f80u: goto P_0c075f80;
case 0x0c075f82u: goto P_0c075f82;
case 0x0c075f84u: goto P_0c075f84;
case 0x0c075f86u: goto P_0c075f86;
case 0x0c075f88u: goto P_0c075f88;
case 0x0c075f8au: goto P_0c075f8a;
case 0x0c075f8cu: goto P_0c075f8c;
case 0x0c075f8eu: goto P_0c075f8e;
case 0x0c075f90u: goto P_0c075f90;
case 0x0c075f92u: goto P_0c075f92;
case 0x0c075f94u: goto P_0c075f94;
case 0x0c075f96u: goto P_0c075f96;
case 0x0c075f98u: goto P_0c075f98;
case 0x0c075f9au: goto P_0c075f9a;
case 0x0c075f9cu: goto P_0c075f9c;
case 0x0c075f9eu: goto P_0c075f9e;
case 0x0c075fa0u: goto P_0c075fa0;
case 0x0c075fa2u: goto P_0c075fa2;
case 0x0c075fa4u: goto P_0c075fa4;
case 0x0c075fa6u: goto P_0c075fa6;
case 0x0c075fa8u: goto P_0c075fa8;
case 0x0c075faau: goto P_0c075faa;
case 0x0c075facu: goto P_0c075fac;
case 0x0c075faeu: goto P_0c075fae;
case 0x0c075fb0u: goto P_0c075fb0;
case 0x0c075fb2u: goto P_0c075fb2;
case 0x0c075fb4u: goto P_0c075fb4;
case 0x0c075fb6u: goto P_0c075fb6;
case 0x0c075fb8u: goto P_0c075fb8;
case 0x0c075fbau: goto P_0c075fba;
case 0x0c075fbcu: goto P_0c075fbc;
case 0x0c075fbeu: goto P_0c075fbe;
case 0x0c075fc0u: goto P_0c075fc0;
case 0x0c075fc2u: goto P_0c075fc2;
case 0x0c075fc4u: goto P_0c075fc4;
case 0x0c075fc6u: goto P_0c075fc6;
case 0x0c075fc8u: goto P_0c075fc8;
case 0x0c075fcau: goto P_0c075fca;
case 0x0c075fccu: goto P_0c075fcc;
case 0x0c075fceu: goto P_0c075fce;
case 0x0c075fd0u: goto P_0c075fd0;
case 0x0c075fd2u: goto P_0c075fd2;
case 0x0c075fd4u: goto P_0c075fd4;
case 0x0c075fd6u: goto P_0c075fd6;
case 0x0c075fd8u: goto P_0c075fd8;
case 0x0c075fdau: goto P_0c075fda;
case 0x0c075fdcu: goto P_0c075fdc;
case 0x0c075fdeu: goto P_0c075fde;
case 0x0c075fe0u: goto P_0c075fe0;
case 0x0c075fe2u: goto P_0c075fe2;
case 0x0c075fe4u: goto P_0c075fe4;
case 0x0c075fe6u: goto P_0c075fe6;
case 0x0c075fe8u: goto P_0c075fe8;
case 0x0c075feau: goto P_0c075fea;
case 0x0c075fecu: goto P_0c075fec;
case 0x0c075feeu: goto P_0c075fee;
case 0x0c075ff0u: goto P_0c075ff0;
case 0x0c075ff2u: goto P_0c075ff2;
case 0x0c075ff4u: goto P_0c075ff4;
case 0x0c075ff6u: goto P_0c075ff6;
case 0x0c075ff8u: goto P_0c075ff8;
case 0x0c075ffau: goto P_0c075ffa;
case 0x0c075ffcu: goto P_0c075ffc;
case 0x0c075ffeu: goto P_0c075ffe;
case 0x0c076000u: goto P_0c076000;
case 0x0c076002u: goto P_0c076002;
case 0x0c076004u: goto P_0c076004;
case 0x0c076024u: goto P_0c076024;
case 0x0c076026u: goto P_0c076026;
case 0x0c076028u: goto P_0c076028;
case 0x0c07602au: goto P_0c07602a;
case 0x0c07602cu: goto P_0c07602c;
case 0x0c07602eu: goto P_0c07602e;
case 0x0c076030u: goto P_0c076030;
case 0x0c076032u: goto P_0c076032;
case 0x0c076034u: goto P_0c076034;
case 0x0c076036u: goto P_0c076036;
case 0x0c076038u: goto P_0c076038;
case 0x0c07603au: goto P_0c07603a;
case 0x0c07603cu: goto P_0c07603c;
case 0x0c07603eu: goto P_0c07603e;
case 0x0c076040u: goto P_0c076040;
case 0x0c076042u: goto P_0c076042;
case 0x0c076044u: goto P_0c076044;
case 0x0c076046u: goto P_0c076046;
case 0x0c076048u: goto P_0c076048;
case 0x0c07604au: goto P_0c07604a;
case 0x0c07604cu: goto P_0c07604c;
case 0x0c07604eu: goto P_0c07604e;
case 0x0c076050u: goto P_0c076050;
case 0x0c076052u: goto P_0c076052;
case 0x0c076054u: goto P_0c076054;
case 0x0c076056u: goto P_0c076056;
case 0x0c076058u: goto P_0c076058;
case 0x0c07605au: goto P_0c07605a;
case 0x0c07605cu: goto P_0c07605c;
case 0x0c07605eu: goto P_0c07605e;
case 0x0c076060u: goto P_0c076060;
case 0x0c076062u: goto P_0c076062;
case 0x0c076064u: goto P_0c076064;
case 0x0c076066u: goto P_0c076066;
case 0x0c076068u: goto P_0c076068;
case 0x0c07606au: goto P_0c07606a;
case 0x0c07606cu: goto P_0c07606c;
case 0x0c07606eu: goto P_0c07606e;
case 0x0c076070u: goto P_0c076070;
case 0x0c076072u: goto P_0c076072;
case 0x0c076074u: goto P_0c076074;
case 0x0c076076u: goto P_0c076076;
case 0x0c076078u: goto P_0c076078;
case 0x0c07607au: goto P_0c07607a;
case 0x0c07607cu: goto P_0c07607c;
case 0x0c07607eu: goto P_0c07607e;
case 0x0c076080u: goto P_0c076080;
case 0x0c076082u: goto P_0c076082;
case 0x0c076084u: goto P_0c076084;
case 0x0c076086u: goto P_0c076086;
case 0x0c076088u: goto P_0c076088;
case 0x0c07608au: goto P_0c07608a;
case 0x0c07608cu: goto P_0c07608c;
case 0x0c07608eu: goto P_0c07608e;
case 0x0c076090u: goto P_0c076090;
case 0x0c076092u: goto P_0c076092;
case 0x0c076094u: goto P_0c076094;
case 0x0c076096u: goto P_0c076096;
case 0x0c076098u: goto P_0c076098;
case 0x0c07609au: goto P_0c07609a;
case 0x0c07609cu: goto P_0c07609c;
case 0x0c0760b4u: goto P_0c0760b4;
case 0x0c0760b6u: goto P_0c0760b6;
case 0x0c0760b8u: goto P_0c0760b8;
case 0x0c0760bau: goto P_0c0760ba;
case 0x0c0760bcu: goto P_0c0760bc;
case 0x0c0760beu: goto P_0c0760be;
case 0x0c0760c0u: goto P_0c0760c0;
case 0x0c0760c2u: goto P_0c0760c2;
case 0x0c0760c4u: goto P_0c0760c4;
case 0x0c0760c6u: goto P_0c0760c6;
case 0x0c0760c8u: goto P_0c0760c8;
case 0x0c0760cau: goto P_0c0760ca;
case 0x0c0760ccu: goto P_0c0760cc;
case 0x0c0760ceu: goto P_0c0760ce;
case 0x0c0760d0u: goto P_0c0760d0;
case 0x0c0760d2u: goto P_0c0760d2;
case 0x0c0760d4u: goto P_0c0760d4;
case 0x0c0760d6u: goto P_0c0760d6;
case 0x0c0760d8u: goto P_0c0760d8;
case 0x0c0760dau: goto P_0c0760da;
case 0x0c0760dcu: goto P_0c0760dc;
case 0x0c0760deu: goto P_0c0760de;
case 0x0c0760e0u: goto P_0c0760e0;
case 0x0c0760e2u: goto P_0c0760e2;
case 0x0c0760e4u: goto P_0c0760e4;
case 0x0c0760e6u: goto P_0c0760e6;
case 0x0c0760e8u: goto P_0c0760e8;
case 0x0c0760eau: goto P_0c0760ea;
case 0x0c0760ecu: goto P_0c0760ec;
case 0x0c0760eeu: goto P_0c0760ee;
case 0x0c0760f0u: goto P_0c0760f0;
case 0x0c0760f2u: goto P_0c0760f2;
case 0x0c0760f4u: goto P_0c0760f4;
case 0x0c0760f6u: goto P_0c0760f6;
case 0x0c0760f8u: goto P_0c0760f8;
case 0x0c0760fau: goto P_0c0760fa;
case 0x0c0760fcu: goto P_0c0760fc;
case 0x0c0760feu: goto P_0c0760fe;
case 0x0c076100u: goto P_0c076100;
case 0x0c076102u: goto P_0c076102;
case 0x0c076104u: goto P_0c076104;
case 0x0c076106u: goto P_0c076106;
case 0x0c076108u: goto P_0c076108;
case 0x0c07610au: goto P_0c07610a;
case 0x0c07610cu: goto P_0c07610c;
case 0x0c07610eu: goto P_0c07610e;
case 0x0c076110u: goto P_0c076110;
case 0x0c076112u: goto P_0c076112;
case 0x0c076114u: goto P_0c076114;
case 0x0c076116u: goto P_0c076116;
case 0x0c076118u: goto P_0c076118;
case 0x0c07611au: goto P_0c07611a;
case 0x0c07611cu: goto P_0c07611c;
case 0x0c07611eu: goto P_0c07611e;
case 0x0c076120u: goto P_0c076120;
case 0x0c076122u: goto P_0c076122;
case 0x0c076124u: goto P_0c076124;
case 0x0c076126u: goto P_0c076126;
case 0x0c076128u: goto P_0c076128;
case 0x0c07612au: goto P_0c07612a;
case 0x0c07612cu: goto P_0c07612c;
case 0x0c07612eu: goto P_0c07612e;
case 0x0c076130u: goto P_0c076130;
case 0x0c076132u: goto P_0c076132;
case 0x0c076134u: goto P_0c076134;
case 0x0c076136u: goto P_0c076136;
case 0x0c076138u: goto P_0c076138;
case 0x0c07613au: goto P_0c07613a;
case 0x0c07613cu: goto P_0c07613c;
case 0x0c07613eu: goto P_0c07613e;
case 0x0c076140u: goto P_0c076140;
case 0x0c076142u: goto P_0c076142;
case 0x0c076144u: goto P_0c076144;
case 0x0c076146u: goto P_0c076146;
case 0x0c076148u: goto P_0c076148;
case 0x0c07614au: goto P_0c07614a;
case 0x0c07614cu: goto P_0c07614c;
case 0x0c07614eu: goto P_0c07614e;
case 0x0c076150u: goto P_0c076150;
case 0x0c076152u: goto P_0c076152;
case 0x0c076154u: goto P_0c076154;
case 0x0c076156u: goto P_0c076156;
case 0x0c076158u: goto P_0c076158;
case 0x0c07615au: goto P_0c07615a;
case 0x0c07615cu: goto P_0c07615c;
case 0x0c07615eu: goto P_0c07615e;
case 0x0c076160u: goto P_0c076160;
case 0x0c076162u: goto P_0c076162;
case 0x0c076164u: goto P_0c076164;
case 0x0c076166u: goto P_0c076166;
case 0x0c076168u: goto P_0c076168;
case 0x0c07616au: goto P_0c07616a;
case 0x0c07616cu: goto P_0c07616c;
case 0x0c07616eu: goto P_0c07616e;
case 0x0c076170u: goto P_0c076170;
case 0x0c076172u: goto P_0c076172;
case 0x0c076174u: goto P_0c076174;
case 0x0c076176u: goto P_0c076176;
case 0x0c076178u: goto P_0c076178;
case 0x0c07617au: goto P_0c07617a;
case 0x0c07617cu: goto P_0c07617c;
case 0x0c07617eu: goto P_0c07617e;
case 0x0c076180u: goto P_0c076180;
case 0x0c076182u: goto P_0c076182;
case 0x0c076184u: goto P_0c076184;
case 0x0c076186u: goto P_0c076186;
case 0x0c076188u: goto P_0c076188;
case 0x0c07618au: goto P_0c07618a;
case 0x0c07618cu: goto P_0c07618c;
case 0x0c07618eu: goto P_0c07618e;
case 0x0c076190u: goto P_0c076190;
case 0x0c076192u: goto P_0c076192;
case 0x0c076194u: goto P_0c076194;
case 0x0c076196u: goto P_0c076196;
case 0x0c076198u: goto P_0c076198;
case 0x0c07619au: goto P_0c07619a;
case 0x0c07619cu: goto P_0c07619c;
case 0x0c07619eu: goto P_0c07619e;
case 0x0c0761a0u: goto P_0c0761a0;
case 0x0c0761a2u: goto P_0c0761a2;
case 0x0c0761a4u: goto P_0c0761a4;
case 0x0c0761a6u: goto P_0c0761a6;
case 0x0c0761a8u: goto P_0c0761a8;
case 0x0c0761aau: goto P_0c0761aa;
case 0x0c0761acu: goto P_0c0761ac;
case 0x0c0761aeu: goto P_0c0761ae;
case 0x0c0761b0u: goto P_0c0761b0;
case 0x0c0761b2u: goto P_0c0761b2;
case 0x0c0761b4u: goto P_0c0761b4;
case 0x0c0761b6u: goto P_0c0761b6;
case 0x0c0761b8u: goto P_0c0761b8;
case 0x0c0761bau: goto P_0c0761ba;
case 0x0c0761bcu: goto P_0c0761bc;
case 0x0c0761beu: goto P_0c0761be;
case 0x0c0761c0u: goto P_0c0761c0;
case 0x0c0761c2u: goto P_0c0761c2;
case 0x0c0761c4u: goto P_0c0761c4;
case 0x0c0761c6u: goto P_0c0761c6;
case 0x0c0761c8u: goto P_0c0761c8;
case 0x0c0761cau: goto P_0c0761ca;
case 0x0c0761ccu: goto P_0c0761cc;
case 0x0c0761ceu: goto P_0c0761ce;
case 0x0c0761d0u: goto P_0c0761d0;
case 0x0c0761d2u: goto P_0c0761d2;
case 0x0c0761d4u: goto P_0c0761d4;
case 0x0c0761d6u: goto P_0c0761d6;
case 0x0c0761d8u: goto P_0c0761d8;
case 0x0c0761dau: goto P_0c0761da;
case 0x0c0761dcu: goto P_0c0761dc;
case 0x0c0761deu: goto P_0c0761de;
case 0x0c0761e0u: goto P_0c0761e0;
case 0x0c0761e2u: goto P_0c0761e2;
case 0x0c0761e4u: goto P_0c0761e4;
case 0x0c07622cu: goto P_0c07622c;
case 0x0c07622eu: goto P_0c07622e;
case 0x0c076230u: goto P_0c076230;
case 0x0c076232u: goto P_0c076232;
case 0x0c076234u: goto P_0c076234;
case 0x0c076236u: goto P_0c076236;
case 0x0c076238u: goto P_0c076238;
case 0x0c07623au: goto P_0c07623a;
case 0x0c07623cu: goto P_0c07623c;
case 0x0c07623eu: goto P_0c07623e;
case 0x0c076240u: goto P_0c076240;
case 0x0c076242u: goto P_0c076242;
case 0x0c076244u: goto P_0c076244;
case 0x0c076246u: goto P_0c076246;
case 0x0c076248u: goto P_0c076248;
case 0x0c07624au: goto P_0c07624a;
case 0x0c07624cu: goto P_0c07624c;
case 0x0c07624eu: goto P_0c07624e;
case 0x0c076250u: goto P_0c076250;
case 0x0c076252u: goto P_0c076252;
case 0x0c076254u: goto P_0c076254;
case 0x0c076256u: goto P_0c076256;
case 0x0c076258u: goto P_0c076258;
case 0x0c07625au: goto P_0c07625a;
case 0x0c07625cu: goto P_0c07625c;
case 0x0c07625eu: goto P_0c07625e;
case 0x0c076260u: goto P_0c076260;
case 0x0c076262u: goto P_0c076262;
case 0x0c076264u: goto P_0c076264;
case 0x0c076266u: goto P_0c076266;
case 0x0c076268u: goto P_0c076268;
case 0x0c07626au: goto P_0c07626a;
case 0x0c07626cu: goto P_0c07626c;
case 0x0c07626eu: goto P_0c07626e;
case 0x0c076270u: goto P_0c076270;
case 0x0c076272u: goto P_0c076272;
case 0x0c076274u: goto P_0c076274;
case 0x0c076276u: goto P_0c076276;
case 0x0c076278u: goto P_0c076278;
case 0x0c07627au: goto P_0c07627a;
case 0x0c07627cu: goto P_0c07627c;
case 0x0c07627eu: goto P_0c07627e;
case 0x0c076280u: goto P_0c076280;
case 0x0c076282u: goto P_0c076282;
case 0x0c076284u: goto P_0c076284;
case 0x0c076286u: goto P_0c076286;
case 0x0c076288u: goto P_0c076288;
case 0x0c07628au: goto P_0c07628a;
case 0x0c07628cu: goto P_0c07628c;
case 0x0c07628eu: goto P_0c07628e;
case 0x0c076290u: goto P_0c076290;
case 0x0c076292u: goto P_0c076292;
case 0x0c076294u: goto P_0c076294;
case 0x0c076296u: goto P_0c076296;
case 0x0c076298u: goto P_0c076298;
case 0x0c07629au: goto P_0c07629a;
case 0x0c07629cu: goto P_0c07629c;
case 0x0c07629eu: goto P_0c07629e;
case 0x0c0762a0u: goto P_0c0762a0;
case 0x0c0762a2u: goto P_0c0762a2;
case 0x0c0762a4u: goto P_0c0762a4;
case 0x0c0762a6u: goto P_0c0762a6;
case 0x0c0762a8u: goto P_0c0762a8;
case 0x0c0762aau: goto P_0c0762aa;
case 0x0c0762acu: goto P_0c0762ac;
case 0x0c0762aeu: goto P_0c0762ae;
case 0x0c0762b0u: goto P_0c0762b0;
case 0x0c0762b2u: goto P_0c0762b2;
case 0x0c0762b4u: goto P_0c0762b4;
case 0x0c0762b6u: goto P_0c0762b6;
case 0x0c0762b8u: goto P_0c0762b8;
case 0x0c0762bau: goto P_0c0762ba;
case 0x0c0762bcu: goto P_0c0762bc;
case 0x0c0762beu: goto P_0c0762be;
case 0x0c0762c0u: goto P_0c0762c0;
case 0x0c0762c2u: goto P_0c0762c2;
case 0x0c0762c4u: goto P_0c0762c4;
case 0x0c0762c6u: goto P_0c0762c6;
case 0x0c0762c8u: goto P_0c0762c8;
case 0x0c0762cau: goto P_0c0762ca;
case 0x0c0762ccu: goto P_0c0762cc;
case 0x0c0762ceu: goto P_0c0762ce;
case 0x0c0762d0u: goto P_0c0762d0;
case 0x0c0762d2u: goto P_0c0762d2;
case 0x0c0762d4u: goto P_0c0762d4;
case 0x0c0762d6u: goto P_0c0762d6;
case 0x0c0762d8u: goto P_0c0762d8;
case 0x0c0762dau: goto P_0c0762da;
case 0x0c0762dcu: goto P_0c0762dc;
case 0x0c0762deu: goto P_0c0762de;
case 0x0c0762e0u: goto P_0c0762e0;
case 0x0c0762e2u: goto P_0c0762e2;
case 0x0c0762e4u: goto P_0c0762e4;
case 0x0c0762e6u: goto P_0c0762e6;
case 0x0c0762e8u: goto P_0c0762e8;
case 0x0c0762eau: goto P_0c0762ea;
case 0x0c0762ecu: goto P_0c0762ec;
case 0x0c0762eeu: goto P_0c0762ee;
case 0x0c0762f0u: goto P_0c0762f0;
case 0x0c0762f2u: goto P_0c0762f2;
case 0x0c0762f4u: goto P_0c0762f4;
case 0x0c0762f6u: goto P_0c0762f6;
case 0x0c0762f8u: goto P_0c0762f8;
case 0x0c0762fau: goto P_0c0762fa;
case 0x0c0762fcu: goto P_0c0762fc;
case 0x0c0762feu: goto P_0c0762fe;
case 0x0c076300u: goto P_0c076300;
case 0x0c076302u: goto P_0c076302;
case 0x0c076304u: goto P_0c076304;
case 0x0c076306u: goto P_0c076306;
case 0x0c076308u: goto P_0c076308;
case 0x0c07630au: goto P_0c07630a;
case 0x0c07630cu: goto P_0c07630c;
case 0x0c07630eu: goto P_0c07630e;
case 0x0c076310u: goto P_0c076310;
case 0x0c076312u: goto P_0c076312;
case 0x0c076314u: goto P_0c076314;
case 0x0c076316u: goto P_0c076316;
case 0x0c076318u: goto P_0c076318;
case 0x0c07631au: goto P_0c07631a;
case 0x0c07631cu: goto P_0c07631c;
case 0x0c07631eu: goto P_0c07631e;
case 0x0c076320u: goto P_0c076320;
case 0x0c076322u: goto P_0c076322;
case 0x0c076324u: goto P_0c076324;
case 0x0c076326u: goto P_0c076326;
case 0x0c076328u: goto P_0c076328;
case 0x0c07632au: goto P_0c07632a;
case 0x0c076354u: goto P_0c076354;
case 0x0c076356u: goto P_0c076356;
case 0x0c076358u: goto P_0c076358;
case 0x0c07635au: goto P_0c07635a;
case 0x0c07635cu: goto P_0c07635c;
case 0x0c07635eu: goto P_0c07635e;
case 0x0c076360u: goto P_0c076360;
case 0x0c076362u: goto P_0c076362;
case 0x0c076364u: goto P_0c076364;
case 0x0c076366u: goto P_0c076366;
case 0x0c076368u: goto P_0c076368;
case 0x0c07636au: goto P_0c07636a;
case 0x0c07636cu: goto P_0c07636c;
case 0x0c07636eu: goto P_0c07636e;
case 0x0c076370u: goto P_0c076370;
case 0x0c076372u: goto P_0c076372;
case 0x0c076374u: goto P_0c076374;
case 0x0c076376u: goto P_0c076376;
case 0x0c076378u: goto P_0c076378;
case 0x0c07637au: goto P_0c07637a;
case 0x0c07637cu: goto P_0c07637c;
case 0x0c07637eu: goto P_0c07637e;
case 0x0c076380u: goto P_0c076380;
case 0x0c076382u: goto P_0c076382;
case 0x0c076384u: goto P_0c076384;
case 0x0c076386u: goto P_0c076386;
case 0x0c076388u: goto P_0c076388;
case 0x0c07638au: goto P_0c07638a;
case 0x0c07638cu: goto P_0c07638c;
case 0x0c07638eu: goto P_0c07638e;
case 0x0c076390u: goto P_0c076390;
case 0x0c076392u: goto P_0c076392;
case 0x0c076394u: goto P_0c076394;
case 0x0c076396u: goto P_0c076396;
case 0x0c076398u: goto P_0c076398;
case 0x0c07639au: goto P_0c07639a;
case 0x0c07639cu: goto P_0c07639c;
case 0x0c07639eu: goto P_0c07639e;
case 0x0c0763a0u: goto P_0c0763a0;
case 0x0c0763a2u: goto P_0c0763a2;
case 0x0c0763a4u: goto P_0c0763a4;
case 0x0c0763a6u: goto P_0c0763a6;
case 0x0c0763a8u: goto P_0c0763a8;
case 0x0c0763aau: goto P_0c0763aa;
case 0x0c0763acu: goto P_0c0763ac;
case 0x0c0763aeu: goto P_0c0763ae;
case 0x0c0763b0u: goto P_0c0763b0;
case 0x0c0763b2u: goto P_0c0763b2;
case 0x0c0763b4u: goto P_0c0763b4;
case 0x0c0763b6u: goto P_0c0763b6;
case 0x0c0763b8u: goto P_0c0763b8;
case 0x0c0763bau: goto P_0c0763ba;
case 0x0c0763bcu: goto P_0c0763bc;
case 0x0c0763beu: goto P_0c0763be;
case 0x0c0763c0u: goto P_0c0763c0;
case 0x0c0763c2u: goto P_0c0763c2;
case 0x0c0763c4u: goto P_0c0763c4;
case 0x0c0763c6u: goto P_0c0763c6;
case 0x0c0763c8u: goto P_0c0763c8;
case 0x0c0763cau: goto P_0c0763ca;
case 0x0c0763ccu: goto P_0c0763cc;
case 0x0c0763ceu: goto P_0c0763ce;
case 0x0c0763d0u: goto P_0c0763d0;
case 0x0c0763d2u: goto P_0c0763d2;
case 0x0c0763d4u: goto P_0c0763d4;
case 0x0c0763d6u: goto P_0c0763d6;
case 0x0c0763d8u: goto P_0c0763d8;
case 0x0c0763dau: goto P_0c0763da;
case 0x0c0763dcu: goto P_0c0763dc;
case 0x0c0763deu: goto P_0c0763de;
case 0x0c0763e0u: goto P_0c0763e0;
case 0x0c0763e2u: goto P_0c0763e2;
case 0x0c0763e4u: goto P_0c0763e4;
case 0x0c0763e6u: goto P_0c0763e6;
case 0x0c0763e8u: goto P_0c0763e8;
case 0x0c0763eau: goto P_0c0763ea;
case 0x0c0763ecu: goto P_0c0763ec;
case 0x0c0763eeu: goto P_0c0763ee;
case 0x0c0763f0u: goto P_0c0763f0;
case 0x0c0763f2u: goto P_0c0763f2;
case 0x0c0763f4u: goto P_0c0763f4;
case 0x0c0763f6u: goto P_0c0763f6;
case 0x0c0763f8u: goto P_0c0763f8;
case 0x0c0763fau: goto P_0c0763fa;
case 0x0c0763fcu: goto P_0c0763fc;
case 0x0c0763feu: goto P_0c0763fe;
case 0x0c076400u: goto P_0c076400;
case 0x0c076402u: goto P_0c076402;
case 0x0c076404u: goto P_0c076404;
case 0x0c076406u: goto P_0c076406;
case 0x0c076408u: goto P_0c076408;
case 0x0c07640au: goto P_0c07640a;
case 0x0c07640cu: goto P_0c07640c;
case 0x0c07640eu: goto P_0c07640e;
case 0x0c076410u: goto P_0c076410;
case 0x0c076412u: goto P_0c076412;
case 0x0c076414u: goto P_0c076414;
case 0x0c076416u: goto P_0c076416;
case 0x0c076418u: goto P_0c076418;
case 0x0c07641au: goto P_0c07641a;
case 0x0c07641cu: goto P_0c07641c;
case 0x0c07641eu: goto P_0c07641e;
case 0x0c076420u: goto P_0c076420;
case 0x0c076422u: goto P_0c076422;
case 0x0c076424u: goto P_0c076424;
case 0x0c076426u: goto P_0c076426;
case 0x0c076428u: goto P_0c076428;
case 0x0c07642au: goto P_0c07642a;
case 0x0c07642cu: goto P_0c07642c;
case 0x0c07642eu: goto P_0c07642e;
case 0x0c076460u: goto P_0c076460;
case 0x0c076462u: goto P_0c076462;
case 0x0c076464u: goto P_0c076464;
case 0x0c076466u: goto P_0c076466;
case 0x0c076468u: goto P_0c076468;
case 0x0c07646au: goto P_0c07646a;
case 0x0c07646cu: goto P_0c07646c;
case 0x0c07646eu: goto P_0c07646e;
case 0x0c076470u: goto P_0c076470;
case 0x0c076472u: goto P_0c076472;
case 0x0c076474u: goto P_0c076474;
case 0x0c076476u: goto P_0c076476;
case 0x0c076478u: goto P_0c076478;
case 0x0c07647au: goto P_0c07647a;
case 0x0c07647cu: goto P_0c07647c;
case 0x0c07647eu: goto P_0c07647e;
case 0x0c076480u: goto P_0c076480;
case 0x0c076482u: goto P_0c076482;
case 0x0c076484u: goto P_0c076484;
case 0x0c076486u: goto P_0c076486;
case 0x0c076488u: goto P_0c076488;
case 0x0c07648au: goto P_0c07648a;
case 0x0c07648cu: goto P_0c07648c;
case 0x0c07648eu: goto P_0c07648e;
case 0x0c076490u: goto P_0c076490;
case 0x0c076492u: goto P_0c076492;
case 0x0c076494u: goto P_0c076494;
case 0x0c076496u: goto P_0c076496;
case 0x0c076498u: goto P_0c076498;
case 0x0c07649au: goto P_0c07649a;
case 0x0c07649cu: goto P_0c07649c;
case 0x0c07649eu: goto P_0c07649e;
case 0x0c0764a0u: goto P_0c0764a0;
case 0x0c0764a2u: goto P_0c0764a2;
case 0x0c0764a4u: goto P_0c0764a4;
case 0x0c0764a6u: goto P_0c0764a6;
case 0x0c0764a8u: goto P_0c0764a8;
case 0x0c0764aau: goto P_0c0764aa;
case 0x0c0764acu: goto P_0c0764ac;
case 0x0c0764aeu: goto P_0c0764ae;
case 0x0c0764b0u: goto P_0c0764b0;
case 0x0c0764b2u: goto P_0c0764b2;
case 0x0c0764b4u: goto P_0c0764b4;
case 0x0c0764b6u: goto P_0c0764b6;
case 0x0c0764b8u: goto P_0c0764b8;
case 0x0c0764bau: goto P_0c0764ba;
case 0x0c0764bcu: goto P_0c0764bc;
case 0x0c0764beu: goto P_0c0764be;
case 0x0c0764c0u: goto P_0c0764c0;
case 0x0c0764c2u: goto P_0c0764c2;
case 0x0c0764c4u: goto P_0c0764c4;
case 0x0c0764c6u: goto P_0c0764c6;
case 0x0c0764c8u: goto P_0c0764c8;
case 0x0c0764cau: goto P_0c0764ca;
case 0x0c0764ccu: goto P_0c0764cc;
case 0x0c0764ceu: goto P_0c0764ce;
case 0x0c0764d0u: goto P_0c0764d0;
case 0x0c0764d2u: goto P_0c0764d2;
case 0x0c0764d4u: goto P_0c0764d4;
case 0x0c0764d6u: goto P_0c0764d6;
case 0x0c0764d8u: goto P_0c0764d8;
case 0x0c0764dau: goto P_0c0764da;
case 0x0c0764dcu: goto P_0c0764dc;
case 0x0c0764deu: goto P_0c0764de;
case 0x0c0764e0u: goto P_0c0764e0;
case 0x0c0764e2u: goto P_0c0764e2;
case 0x0c0764e4u: goto P_0c0764e4;
case 0x0c0764e6u: goto P_0c0764e6;
case 0x0c0764e8u: goto P_0c0764e8;
case 0x0c0764eau: goto P_0c0764ea;
case 0x0c0764ecu: goto P_0c0764ec;
case 0x0c0764eeu: goto P_0c0764ee;
case 0x0c0764f0u: goto P_0c0764f0;
case 0x0c0764f2u: goto P_0c0764f2;
case 0x0c0764f4u: goto P_0c0764f4;
case 0x0c0764f6u: goto P_0c0764f6;
case 0x0c0764f8u: goto P_0c0764f8;
case 0x0c0764fau: goto P_0c0764fa;
case 0x0c0764fcu: goto P_0c0764fc;
case 0x0c0764feu: goto P_0c0764fe;
case 0x0c076500u: goto P_0c076500;
case 0x0c076502u: goto P_0c076502;
case 0x0c076504u: goto P_0c076504;
case 0x0c076506u: goto P_0c076506;
case 0x0c076508u: goto P_0c076508;
case 0x0c07650au: goto P_0c07650a;
case 0x0c07650cu: goto P_0c07650c;
case 0x0c07650eu: goto P_0c07650e;
case 0x0c076510u: goto P_0c076510;
case 0x0c076512u: goto P_0c076512;
case 0x0c076514u: goto P_0c076514;
case 0x0c076516u: goto P_0c076516;
case 0x0c076518u: goto P_0c076518;
case 0x0c07651au: goto P_0c07651a;
case 0x0c07651cu: goto P_0c07651c;
case 0x0c07651eu: goto P_0c07651e;
case 0x0c076520u: goto P_0c076520;
case 0x0c076522u: goto P_0c076522;
case 0x0c076524u: goto P_0c076524;
case 0x0c076526u: goto P_0c076526;
case 0x0c076528u: goto P_0c076528;
case 0x0c07652au: goto P_0c07652a;
case 0x0c07652cu: goto P_0c07652c;
case 0x0c07652eu: goto P_0c07652e;
case 0x0c076530u: goto P_0c076530;
case 0x0c076532u: goto P_0c076532;
case 0x0c076534u: goto P_0c076534;
case 0x0c076536u: goto P_0c076536;
case 0x0c076538u: goto P_0c076538;
case 0x0c07653au: goto P_0c07653a;
case 0x0c07653cu: goto P_0c07653c;
case 0x0c07653eu: goto P_0c07653e;
case 0x0c076540u: goto P_0c076540;
case 0x0c076542u: goto P_0c076542;
case 0x0c076544u: goto P_0c076544;
case 0x0c076546u: goto P_0c076546;
case 0x0c076548u: goto P_0c076548;
case 0x0c07654au: goto P_0c07654a;
case 0x0c07654cu: goto P_0c07654c;
case 0x0c07654eu: goto P_0c07654e;
case 0x0c076550u: goto P_0c076550;
case 0x0c076552u: goto P_0c076552;
case 0x0c076554u: goto P_0c076554;
case 0x0c076556u: goto P_0c076556;
case 0x0c076558u: goto P_0c076558;
case 0x0c07655au: goto P_0c07655a;
case 0x0c07655cu: goto P_0c07655c;
case 0x0c07655eu: goto P_0c07655e;
case 0x0c076560u: goto P_0c076560;
case 0x0c076562u: goto P_0c076562;
case 0x0c076564u: goto P_0c076564;
case 0x0c076566u: goto P_0c076566;
case 0x0c076568u: goto P_0c076568;
case 0x0c07656au: goto P_0c07656a;
case 0x0c07656cu: goto P_0c07656c;
case 0x0c07656eu: goto P_0c07656e;
case 0x0c076570u: goto P_0c076570;
case 0x0c076572u: goto P_0c076572;
case 0x0c076574u: goto P_0c076574;
case 0x0c076576u: goto P_0c076576;
case 0x0c076578u: goto P_0c076578;
case 0x0c07657au: goto P_0c07657a;
case 0x0c07657cu: goto P_0c07657c;
case 0x0c07657eu: goto P_0c07657e;
case 0x0c076580u: goto P_0c076580;
case 0x0c076582u: goto P_0c076582;
case 0x0c076584u: goto P_0c076584;
case 0x0c076586u: goto P_0c076586;
case 0x0c076588u: goto P_0c076588;
case 0x0c07658au: goto P_0c07658a;
case 0x0c07658cu: goto P_0c07658c;
case 0x0c07658eu: goto P_0c07658e;
case 0x0c076590u: goto P_0c076590;
case 0x0c076592u: goto P_0c076592;
case 0x0c076594u: goto P_0c076594;
case 0x0c076596u: goto P_0c076596;
case 0x0c076598u: goto P_0c076598;
case 0x0c07659au: goto P_0c07659a;
case 0x0c07659cu: goto P_0c07659c;
case 0x0c07659eu: goto P_0c07659e;
case 0x0c0765d4u: goto P_0c0765d4;
case 0x0c0765d6u: goto P_0c0765d6;
case 0x0c0765d8u: goto P_0c0765d8;
case 0x0c0765dau: goto P_0c0765da;
case 0x0c0765dcu: goto P_0c0765dc;
case 0x0c0765deu: goto P_0c0765de;
case 0x0c0765e0u: goto P_0c0765e0;
case 0x0c0765e2u: goto P_0c0765e2;
case 0x0c0765e4u: goto P_0c0765e4;
case 0x0c0765e6u: goto P_0c0765e6;
case 0x0c0765e8u: goto P_0c0765e8;
case 0x0c0765eau: goto P_0c0765ea;
case 0x0c0765ecu: goto P_0c0765ec;
case 0x0c0765eeu: goto P_0c0765ee;
case 0x0c0765f0u: goto P_0c0765f0;
case 0x0c0765f2u: goto P_0c0765f2;
case 0x0c0765f4u: goto P_0c0765f4;
case 0x0c0765f6u: goto P_0c0765f6;
case 0x0c0765f8u: goto P_0c0765f8;
case 0x0c0765fau: goto P_0c0765fa;
case 0x0c0765fcu: goto P_0c0765fc;
case 0x0c0765feu: goto P_0c0765fe;
case 0x0c076600u: goto P_0c076600;
case 0x0c076602u: goto P_0c076602;
case 0x0c076604u: goto P_0c076604;
case 0x0c076606u: goto P_0c076606;
case 0x0c076608u: goto P_0c076608;
case 0x0c07660au: goto P_0c07660a;
case 0x0c07660cu: goto P_0c07660c;
case 0x0c07660eu: goto P_0c07660e;
case 0x0c076610u: goto P_0c076610;
case 0x0c076612u: goto P_0c076612;
case 0x0c076614u: goto P_0c076614;
case 0x0c076616u: goto P_0c076616;
case 0x0c076618u: goto P_0c076618;
case 0x0c07661au: goto P_0c07661a;
case 0x0c07661cu: goto P_0c07661c;
case 0x0c07661eu: goto P_0c07661e;
case 0x0c076620u: goto P_0c076620;
case 0x0c076622u: goto P_0c076622;
case 0x0c076624u: goto P_0c076624;
case 0x0c076626u: goto P_0c076626;
case 0x0c076628u: goto P_0c076628;
case 0x0c07662au: goto P_0c07662a;
case 0x0c07662cu: goto P_0c07662c;
case 0x0c07662eu: goto P_0c07662e;
case 0x0c076630u: goto P_0c076630;
case 0x0c076632u: goto P_0c076632;
case 0x0c076634u: goto P_0c076634;
case 0x0c076636u: goto P_0c076636;
case 0x0c076638u: goto P_0c076638;
case 0x0c07663au: goto P_0c07663a;
case 0x0c07663cu: goto P_0c07663c;
case 0x0c07663eu: goto P_0c07663e;
case 0x0c076640u: goto P_0c076640;
case 0x0c076642u: goto P_0c076642;
case 0x0c076644u: goto P_0c076644;
case 0x0c076646u: goto P_0c076646;
case 0x0c076648u: goto P_0c076648;
case 0x0c07664au: goto P_0c07664a;
case 0x0c07664cu: goto P_0c07664c;
case 0x0c07664eu: goto P_0c07664e;
case 0x0c076650u: goto P_0c076650;
case 0x0c076652u: goto P_0c076652;
case 0x0c076654u: goto P_0c076654;
case 0x0c076656u: goto P_0c076656;
case 0x0c076658u: goto P_0c076658;
case 0x0c07665au: goto P_0c07665a;
case 0x0c07665cu: goto P_0c07665c;
case 0x0c07665eu: goto P_0c07665e;
case 0x0c076660u: goto P_0c076660;
case 0x0c076662u: goto P_0c076662;
case 0x0c076664u: goto P_0c076664;
case 0x0c076666u: goto P_0c076666;
case 0x0c076668u: goto P_0c076668;
case 0x0c07666au: goto P_0c07666a;
case 0x0c07666cu: goto P_0c07666c;
case 0x0c07666eu: goto P_0c07666e;
case 0x0c076670u: goto P_0c076670;
case 0x0c076672u: goto P_0c076672;
case 0x0c076674u: goto P_0c076674;
case 0x0c076676u: goto P_0c076676;
case 0x0c076678u: goto P_0c076678;
case 0x0c07667au: goto P_0c07667a;
case 0x0c07667cu: goto P_0c07667c;
case 0x0c07667eu: goto P_0c07667e;
case 0x0c076680u: goto P_0c076680;
case 0x0c076682u: goto P_0c076682;
case 0x0c076684u: goto P_0c076684;
case 0x0c076686u: goto P_0c076686;
case 0x0c076688u: goto P_0c076688;
case 0x0c07668au: goto P_0c07668a;
case 0x0c07668cu: goto P_0c07668c;
case 0x0c07668eu: goto P_0c07668e;
case 0x0c076690u: goto P_0c076690;
case 0x0c076692u: goto P_0c076692;
case 0x0c076694u: goto P_0c076694;
case 0x0c076696u: goto P_0c076696;
case 0x0c076698u: goto P_0c076698;
case 0x0c07669au: goto P_0c07669a;
case 0x0c07669cu: goto P_0c07669c;
case 0x0c07669eu: goto P_0c07669e;
case 0x0c0766a0u: goto P_0c0766a0;
case 0x0c0766a2u: goto P_0c0766a2;
case 0x0c0766a4u: goto P_0c0766a4;
case 0x0c0766a6u: goto P_0c0766a6;
case 0x0c0766a8u: goto P_0c0766a8;
case 0x0c0766aau: goto P_0c0766aa;
case 0x0c0766acu: goto P_0c0766ac;
case 0x0c0766aeu: goto P_0c0766ae;
case 0x0c0766b0u: goto P_0c0766b0;
case 0x0c0766b2u: goto P_0c0766b2;
case 0x0c0766b4u: goto P_0c0766b4;
case 0x0c0766b6u: goto P_0c0766b6;
case 0x0c0766b8u: goto P_0c0766b8;
case 0x0c0766bau: goto P_0c0766ba;
case 0x0c0766bcu: goto P_0c0766bc;
case 0x0c0766beu: goto P_0c0766be;
case 0x0c0766c0u: goto P_0c0766c0;
case 0x0c0766c2u: goto P_0c0766c2;
case 0x0c0766c4u: goto P_0c0766c4;
case 0x0c0766c6u: goto P_0c0766c6;
case 0x0c0766c8u: goto P_0c0766c8;
case 0x0c0766cau: goto P_0c0766ca;
case 0x0c0766ccu: goto P_0c0766cc;
case 0x0c0766ceu: goto P_0c0766ce;
case 0x0c0766d0u: goto P_0c0766d0;
case 0x0c0766d2u: goto P_0c0766d2;
case 0x0c0766d4u: goto P_0c0766d4;
case 0x0c0766d6u: goto P_0c0766d6;
case 0x0c0766d8u: goto P_0c0766d8;
case 0x0c0766dau: goto P_0c0766da;
case 0x0c0766dcu: goto P_0c0766dc;
case 0x0c0766deu: goto P_0c0766de;
case 0x0c0766e0u: goto P_0c0766e0;
case 0x0c0766e2u: goto P_0c0766e2;
case 0x0c0766e4u: goto P_0c0766e4;
case 0x0c0766e6u: goto P_0c0766e6;
case 0x0c0766e8u: goto P_0c0766e8;
case 0x0c0766eau: goto P_0c0766ea;
case 0x0c0766ecu: goto P_0c0766ec;
case 0x0c0766eeu: goto P_0c0766ee;
case 0x0c076714u: goto P_0c076714;
case 0x0c076716u: goto P_0c076716;
case 0x0c076718u: goto P_0c076718;
case 0x0c07671au: goto P_0c07671a;
case 0x0c07671cu: goto P_0c07671c;
case 0x0c07671eu: goto P_0c07671e;
case 0x0c076720u: goto P_0c076720;
case 0x0c076722u: goto P_0c076722;
case 0x0c076724u: goto P_0c076724;
case 0x0c076726u: goto P_0c076726;
case 0x0c076728u: goto P_0c076728;
case 0x0c07672au: goto P_0c07672a;
case 0x0c07672cu: goto P_0c07672c;
case 0x0c07672eu: goto P_0c07672e;
case 0x0c076730u: goto P_0c076730;
case 0x0c076732u: goto P_0c076732;
case 0x0c076734u: goto P_0c076734;
case 0x0c076736u: goto P_0c076736;
case 0x0c076738u: goto P_0c076738;
case 0x0c07673au: goto P_0c07673a;
case 0x0c07673cu: goto P_0c07673c;
case 0x0c07673eu: goto P_0c07673e;
case 0x0c076740u: goto P_0c076740;
case 0x0c076742u: goto P_0c076742;
case 0x0c076744u: goto P_0c076744;
case 0x0c076746u: goto P_0c076746;
case 0x0c076748u: goto P_0c076748;
case 0x0c07674au: goto P_0c07674a;
case 0x0c07674cu: goto P_0c07674c;
case 0x0c07674eu: goto P_0c07674e;
case 0x0c076750u: goto P_0c076750;
case 0x0c076752u: goto P_0c076752;
case 0x0c07675au: goto P_0c07675a;
case 0x0c07675cu: goto P_0c07675c;
case 0x0c07675eu: goto P_0c07675e;
case 0x0c076760u: goto P_0c076760;
case 0x0c076762u: goto P_0c076762;
case 0x0c076764u: goto P_0c076764;
case 0x0c076766u: goto P_0c076766;
case 0x0c076768u: goto P_0c076768;
case 0x0c07676au: goto P_0c07676a;
case 0x0c07676cu: goto P_0c07676c;
case 0x0c07676eu: goto P_0c07676e;
case 0x0c076770u: goto P_0c076770;
case 0x0c076772u: goto P_0c076772;
case 0x0c076774u: goto P_0c076774;
case 0x0c076776u: goto P_0c076776;
case 0x0c076778u: goto P_0c076778;
case 0x0c07677au: goto P_0c07677a;
case 0x0c07677cu: goto P_0c07677c;
case 0x0c07677eu: goto P_0c07677e;
case 0x0c076780u: goto P_0c076780;
case 0x0c076782u: goto P_0c076782;
case 0x0c076784u: goto P_0c076784;
case 0x0c076786u: goto P_0c076786;
case 0x0c076788u: goto P_0c076788;
case 0x0c07678au: goto P_0c07678a;
case 0x0c07678cu: goto P_0c07678c;
case 0x0c07678eu: goto P_0c07678e;
case 0x0c076790u: goto P_0c076790;
case 0x0c076792u: goto P_0c076792;
case 0x0c076794u: goto P_0c076794;
case 0x0c076796u: goto P_0c076796;
case 0x0c076798u: goto P_0c076798;
case 0x0c07679au: goto P_0c07679a;
case 0x0c07679cu: goto P_0c07679c;
case 0x0c07679eu: goto P_0c07679e;
case 0x0c0767a0u: goto P_0c0767a0;
case 0x0c0767a2u: goto P_0c0767a2;
case 0x0c0767a4u: goto P_0c0767a4;
case 0x0c0767a6u: goto P_0c0767a6;
case 0x0c0767a8u: goto P_0c0767a8;
case 0x0c0767aau: goto P_0c0767aa;
case 0x0c0767acu: goto P_0c0767ac;
case 0x0c0767aeu: goto P_0c0767ae;
case 0x0c0767b0u: goto P_0c0767b0;
case 0x0c0767b2u: goto P_0c0767b2;
case 0x0c0767b4u: goto P_0c0767b4;
case 0x0c0767b6u: goto P_0c0767b6;
case 0x0c0767b8u: goto P_0c0767b8;
case 0x0c0767bau: goto P_0c0767ba;
case 0x0c0767bcu: goto P_0c0767bc;
case 0x0c0767beu: goto P_0c0767be;
case 0x0c0767c0u: goto P_0c0767c0;
case 0x0c0767c2u: goto P_0c0767c2;
case 0x0c0767c4u: goto P_0c0767c4;
case 0x0c0767c6u: goto P_0c0767c6;
case 0x0c0767c8u: goto P_0c0767c8;
case 0x0c0767cau: goto P_0c0767ca;
case 0x0c0767ccu: goto P_0c0767cc;
case 0x0c0767ceu: goto P_0c0767ce;
case 0x0c0767d0u: goto P_0c0767d0;
case 0x0c0767d2u: goto P_0c0767d2;
case 0x0c0767d4u: goto P_0c0767d4;
case 0x0c0767d6u: goto P_0c0767d6;
case 0x0c0767d8u: goto P_0c0767d8;
case 0x0c0767dau: goto P_0c0767da;
case 0x0c0767dcu: goto P_0c0767dc;
case 0x0c0767deu: goto P_0c0767de;
case 0x0c0767e0u: goto P_0c0767e0;
case 0x0c0767e2u: goto P_0c0767e2;
case 0x0c0767e4u: goto P_0c0767e4;
case 0x0c0767e6u: goto P_0c0767e6;
case 0x0c0767e8u: goto P_0c0767e8;
case 0x0c0767eau: goto P_0c0767ea;
case 0x0c0767ecu: goto P_0c0767ec;
case 0x0c0767eeu: goto P_0c0767ee;
case 0x0c0767f0u: goto P_0c0767f0;
case 0x0c0767f2u: goto P_0c0767f2;
case 0x0c0767f4u: goto P_0c0767f4;
case 0x0c0767f6u: goto P_0c0767f6;
case 0x0c0767f8u: goto P_0c0767f8;
case 0x0c0767fau: goto P_0c0767fa;
case 0x0c0767fcu: goto P_0c0767fc;
case 0x0c0767feu: goto P_0c0767fe;
case 0x0c076800u: goto P_0c076800;
case 0x0c076802u: goto P_0c076802;
case 0x0c076804u: goto P_0c076804;
case 0x0c076806u: goto P_0c076806;
case 0x0c076808u: goto P_0c076808;
case 0x0c07680au: goto P_0c07680a;
case 0x0c07680cu: goto P_0c07680c;
case 0x0c07680eu: goto P_0c07680e;
case 0x0c076810u: goto P_0c076810;
case 0x0c076812u: goto P_0c076812;
case 0x0c076814u: goto P_0c076814;
case 0x0c076816u: goto P_0c076816;
case 0x0c076818u: goto P_0c076818;
case 0x0c07681au: goto P_0c07681a;
case 0x0c07681cu: goto P_0c07681c;
case 0x0c07681eu: goto P_0c07681e;
case 0x0c076820u: goto P_0c076820;
case 0x0c076822u: goto P_0c076822;
case 0x0c076824u: goto P_0c076824;
case 0x0c076826u: goto P_0c076826;
case 0x0c076828u: goto P_0c076828;
case 0x0c07682au: goto P_0c07682a;
case 0x0c07682cu: goto P_0c07682c;
case 0x0c07682eu: goto P_0c07682e;
case 0x0c076830u: goto P_0c076830;
case 0x0c076832u: goto P_0c076832;
case 0x0c076834u: goto P_0c076834;
case 0x0c076836u: goto P_0c076836;
case 0x0c076838u: goto P_0c076838;
case 0x0c07683au: goto P_0c07683a;
case 0x0c07683cu: goto P_0c07683c;
case 0x0c07683eu: goto P_0c07683e;
case 0x0c076840u: goto P_0c076840;
case 0x0c076842u: goto P_0c076842;
case 0x0c076844u: goto P_0c076844;
case 0x0c076846u: goto P_0c076846;
case 0x0c076848u: goto P_0c076848;
case 0x0c07684au: goto P_0c07684a;
case 0x0c07684cu: goto P_0c07684c;
case 0x0c07684eu: goto P_0c07684e;
case 0x0c076850u: goto P_0c076850;
case 0x0c076852u: goto P_0c076852;
case 0x0c076854u: goto P_0c076854;
case 0x0c076856u: goto P_0c076856;
case 0x0c076858u: goto P_0c076858;
case 0x0c07685au: goto P_0c07685a;
case 0x0c07685cu: goto P_0c07685c;
case 0x0c07685eu: goto P_0c07685e;
case 0x0c076860u: goto P_0c076860;
case 0x0c076862u: goto P_0c076862;
case 0x0c076864u: goto P_0c076864;
case 0x0c076866u: goto P_0c076866;
case 0x0c076868u: goto P_0c076868;
case 0x0c07686au: goto P_0c07686a;
case 0x0c07686cu: goto P_0c07686c;
case 0x0c07686eu: goto P_0c07686e;
case 0x0c076870u: goto P_0c076870;
case 0x0c076872u: goto P_0c076872;
case 0x0c076874u: goto P_0c076874;
case 0x0c076876u: goto P_0c076876;
case 0x0c076878u: goto P_0c076878;
case 0x0c07687au: goto P_0c07687a;
case 0x0c07687cu: goto P_0c07687c;
case 0x0c07687eu: goto P_0c07687e;
case 0x0c076880u: goto P_0c076880;
case 0x0c076882u: goto P_0c076882;
case 0x0c076884u: goto P_0c076884;
case 0x0c076886u: goto P_0c076886;
case 0x0c076888u: goto P_0c076888;
case 0x0c07688au: goto P_0c07688a;
case 0x0c07688cu: goto P_0c07688c;
case 0x0c07688eu: goto P_0c07688e;
case 0x0c0768c4u: goto P_0c0768c4;
case 0x0c0768c6u: goto P_0c0768c6;
case 0x0c0768c8u: goto P_0c0768c8;
case 0x0c0768cau: goto P_0c0768ca;
case 0x0c0768ccu: goto P_0c0768cc;
case 0x0c0768ceu: goto P_0c0768ce;
case 0x0c0768d0u: goto P_0c0768d0;
case 0x0c0768d2u: goto P_0c0768d2;
case 0x0c0768d4u: goto P_0c0768d4;
case 0x0c0768d6u: goto P_0c0768d6;
case 0x0c0768d8u: goto P_0c0768d8;
case 0x0c0768dau: goto P_0c0768da;
case 0x0c0768dcu: goto P_0c0768dc;
case 0x0c0768deu: goto P_0c0768de;
case 0x0c0768e0u: goto P_0c0768e0;
case 0x0c0768e2u: goto P_0c0768e2;
case 0x0c0768e4u: goto P_0c0768e4;
case 0x0c0768e6u: goto P_0c0768e6;
case 0x0c0768e8u: goto P_0c0768e8;
case 0x0c0768eau: goto P_0c0768ea;
case 0x0c0768ecu: goto P_0c0768ec;
case 0x0c0768eeu: goto P_0c0768ee;
case 0x0c0768f0u: goto P_0c0768f0;
case 0x0c0768f2u: goto P_0c0768f2;
case 0x0c0768f4u: goto P_0c0768f4;
case 0x0c0768f6u: goto P_0c0768f6;
case 0x0c0768f8u: goto P_0c0768f8;
case 0x0c0768fau: goto P_0c0768fa;
case 0x0c0768fcu: goto P_0c0768fc;
case 0x0c0768feu: goto P_0c0768fe;
case 0x0c076900u: goto P_0c076900;
case 0x0c076902u: goto P_0c076902;
case 0x0c076904u: goto P_0c076904;
case 0x0c076906u: goto P_0c076906;
case 0x0c076908u: goto P_0c076908;
case 0x0c07690au: goto P_0c07690a;
case 0x0c07690cu: goto P_0c07690c;
case 0x0c07690eu: goto P_0c07690e;
case 0x0c076910u: goto P_0c076910;
case 0x0c076912u: goto P_0c076912;
case 0x0c076914u: goto P_0c076914;
case 0x0c076916u: goto P_0c076916;
case 0x0c076918u: goto P_0c076918;
case 0x0c07691au: goto P_0c07691a;
case 0x0c07691cu: goto P_0c07691c;
case 0x0c07691eu: goto P_0c07691e;
case 0x0c076920u: goto P_0c076920;
case 0x0c076922u: goto P_0c076922;
case 0x0c076924u: goto P_0c076924;
case 0x0c076926u: goto P_0c076926;
case 0x0c076928u: goto P_0c076928;
case 0x0c07692au: goto P_0c07692a;
case 0x0c07692cu: goto P_0c07692c;
case 0x0c07692eu: goto P_0c07692e;
case 0x0c076930u: goto P_0c076930;
case 0x0c076932u: goto P_0c076932;
case 0x0c076934u: goto P_0c076934;
case 0x0c076936u: goto P_0c076936;
case 0x0c076938u: goto P_0c076938;
case 0x0c07693au: goto P_0c07693a;
case 0x0c07693cu: goto P_0c07693c;
case 0x0c07693eu: goto P_0c07693e;
case 0x0c076940u: goto P_0c076940;
default: return vf3_matrix_family(target,s,ram);
}
P_0c06ef4a: /* original 4f22, guest PC 0x0c06ef4a */
if(!s->budget--) { s->failed_pc=0x0c06ef4au; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c06ef4c;
P_0c06ef4c: /* original d33d, guest PC 0x0c06ef4c */
if(!s->budget--) { s->failed_pc=0x0c06ef4cu; return 0; }
r[3]=read(ram,0x0c06f044u,4);
goto P_0c06ef4e;
P_0c06ef4e: /* original dd3c, guest PC 0x0c06ef4e */
if(!s->budget--) { s->failed_pc=0x0c06ef4eu; return 0; }
r[13]=read(ram,0x0c06f040u,4);
goto P_0c06ef50;
P_0c06ef50: /* original 4f12, guest PC 0x0c06ef50 */
if(!s->budget--) { s->failed_pc=0x0c06ef50u; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c06ef52;
P_0c06ef52: /* original 430b, guest PC 0x0c06ef52 */
if(!s->budget--) { s->failed_pc=0x0c06ef52u; return 0; }
target=r[3];
r[16]=0x0c06ef56u;
r[14]=r[4];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c06ef56u) { target=s->pc; goto dispatch; }
goto P_0c06ef56;
P_0c06ef54: /* original 6e43, guest PC 0x0c06ef54 */
if(!s->budget--) { s->failed_pc=0x0c06ef54u; return 0; }
r[14]=r[4];
goto P_0c06ef56;
P_0c06ef56: /* original 2008, guest PC 0x0c06ef56 */
if(!s->budget--) { s->failed_pc=0x0c06ef56u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c06ef58;
P_0c06ef58: /* original 8964, guest PC 0x0c06ef58 */
if(!s->budget--) { s->failed_pc=0x0c06ef58u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c06f024; }
goto P_0c06ef5a;
P_0c06ef5a: /* original 84e4, guest PC 0x0c06ef5a */
if(!s->budget--) { s->failed_pc=0x0c06ef5au; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+4,1);
goto P_0c06ef5c;
P_0c06ef5c: /* original d43a, guest PC 0x0c06ef5c */
if(!s->budget--) { s->failed_pc=0x0c06ef5cu; return 0; }
r[4]=read(ram,0x0c06f048u,4);
goto P_0c06ef5e;
P_0c06ef5e: /* original 2008, guest PC 0x0c06ef5e */
if(!s->budget--) { s->failed_pc=0x0c06ef5eu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c06ef60;
P_0c06ef60: /* original 8b01, guest PC 0x0c06ef60 */
if(!s->budget--) { s->failed_pc=0x0c06ef60u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06ef66; }
goto P_0c06ef62;
P_0c06ef62: /* original a001, guest PC 0x0c06ef62 */
if(!s->budget--) { s->failed_pc=0x0c06ef62u; return 0; }
r[11]=read(ram,r[4]+16,4);
goto P_0c06ef68;
P_0c06ef64: /* original 5b44, guest PC 0x0c06ef64 */
if(!s->budget--) { s->failed_pc=0x0c06ef64u; return 0; }
r[11]=read(ram,r[4]+16,4);
goto P_0c06ef66;
P_0c06ef66: /* original 5b45, guest PC 0x0c06ef66 */
if(!s->budget--) { s->failed_pc=0x0c06ef66u; return 0; }
r[11]=read(ram,r[4]+20,4);
goto P_0c06ef68;
P_0c06ef68: /* original 62b2, guest PC 0x0c06ef68 */
if(!s->budget--) { s->failed_pc=0x0c06ef68u; return 0; }
tmp=read(ram,r[11],4);
r[2]=tmp;
goto P_0c06ef6a;
P_0c06ef6a: /* original d338, guest PC 0x0c06ef6a */
if(!s->budget--) { s->failed_pc=0x0c06ef6au; return 0; }
r[3]=read(ram,0x0c06f04cu,4);
goto P_0c06ef6c;
P_0c06ef6c: /* original 2238, guest PC 0x0c06ef6c */
if(!s->budget--) { s->failed_pc=0x0c06ef6cu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c06ef6e;
P_0c06ef6e: /* original 8b05, guest PC 0x0c06ef6e */
if(!s->budget--) { s->failed_pc=0x0c06ef6eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06ef7c; }
goto P_0c06ef70;
P_0c06ef70: /* original 61e2, guest PC 0x0c06ef70 */
if(!s->budget--) { s->failed_pc=0x0c06ef70u; return 0; }
tmp=read(ram,r[14],4);
r[1]=tmp;
goto P_0c06ef72;
P_0c06ef72: /* original d237, guest PC 0x0c06ef72 */
if(!s->budget--) { s->failed_pc=0x0c06ef72u; return 0; }
r[2]=read(ram,0x0c06f050u,4);
goto P_0c06ef74;
P_0c06ef74: /* original 2129, guest PC 0x0c06ef74 */
if(!s->budget--) { s->failed_pc=0x0c06ef74u; return 0; }
r[1]&=r[2];
goto P_0c06ef76;
P_0c06ef76: /* original 2e12, guest PC 0x0c06ef76 */
if(!s->budget--) { s->failed_pc=0x0c06ef76u; return 0; }
write(ram,r[14],r[1],4);
goto P_0c06ef78;
P_0c06ef78: /* original a054, guest PC 0x0c06ef78 */
if(!s->budget--) { s->failed_pc=0x0c06ef78u; return 0; }
goto P_0c06f024;
P_0c06ef7a: /* original 0009, guest PC 0x0c06ef7a */
if(!s->budget--) { s->failed_pc=0x0c06ef7au; return 0; }
goto P_0c06ef7c;
P_0c06ef7c: /* original d335, guest PC 0x0c06ef7c */
if(!s->budget--) { s->failed_pc=0x0c06ef7cu; return 0; }
r[3]=read(ram,0x0c06f054u,4);
goto P_0c06ef7e;
P_0c06ef7e: /* original e060, guest PC 0x0c06ef7e */
if(!s->budget--) { s->failed_pc=0x0c06ef7eu; return 0; }
r[0]=0x00000060u;
goto P_0c06ef80;
P_0c06ef80: /* original 1e33, guest PC 0x0c06ef80 */
if(!s->budget--) { s->failed_pc=0x0c06ef80u; return 0; }
write(ram,r[14]+12,r[3],4);
goto P_0c06ef82;
P_0c06ef82: /* original d335, guest PC 0x0c06ef82 */
if(!s->budget--) { s->failed_pc=0x0c06ef82u; return 0; }
r[3]=read(ram,0x0c06f058u,4);
goto P_0c06ef84;
P_0c06ef84: /* original 62e2, guest PC 0x0c06ef84 */
if(!s->budget--) { s->failed_pc=0x0c06ef84u; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c06ef86;
P_0c06ef86: /* original 223b, guest PC 0x0c06ef86 */
if(!s->budget--) { s->failed_pc=0x0c06ef86u; return 0; }
r[2]|=r[3];
goto P_0c06ef88;
P_0c06ef88: /* original 2e22, guest PC 0x0c06ef88 */
if(!s->budget--) { s->failed_pc=0x0c06ef88u; return 0; }
write(ram,r[14],r[2],4);
goto P_0c06ef8a;
P_0c06ef8a: /* original 04bc, guest PC 0x0c06ef8a */
if(!s->budget--) { s->failed_pc=0x0c06ef8au; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[11]+r[0],1);
goto P_0c06ef8c;
P_0c06ef8c: /* original 604c, guest PC 0x0c06ef8c */
if(!s->budget--) { s->failed_pc=0x0c06ef8cu; return 0; }
r[0]=r[4]&255u;
goto P_0c06ef8e;
P_0c06ef8e: /* original 880b, guest PC 0x0c06ef8e */
if(!s->budget--) { s->failed_pc=0x0c06ef8eu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000bu)!=0);
goto P_0c06ef90;
P_0c06ef90: /* original 8f06, guest PC 0x0c06ef90 */
if(!s->budget--) { s->failed_pc=0x0c06ef90u; return 0; }
cond=r[17]&1u;
r[4]=r[0];
if(!cond) { goto P_0c06efa0; }
goto P_0c06ef94;
P_0c06ef92: /* original 6403, guest PC 0x0c06ef92 */
if(!s->budget--) { s->failed_pc=0x0c06ef92u; return 0; }
r[4]=r[0];
goto P_0c06ef94;
P_0c06ef94: /* original 9050, guest PC 0x0c06ef94 */
if(!s->budget--) { s->failed_pc=0x0c06ef94u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06f038u,2);
goto P_0c06ef96;
P_0c06ef96: /* original 01dc, guest PC 0x0c06ef96 */
if(!s->budget--) { s->failed_pc=0x0c06ef96u; return 0; }
r[1]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+r[0],1);
goto P_0c06ef98;
P_0c06ef98: /* original 2118, guest PC 0x0c06ef98 */
if(!s->budget--) { s->failed_pc=0x0c06ef98u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[1])==0)!=0);
goto P_0c06ef9a;
P_0c06ef9a: /* original 8911, guest PC 0x0c06ef9a */
if(!s->budget--) { s->failed_pc=0x0c06ef9au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c06efc0; }
goto P_0c06ef9c;
P_0c06ef9c: /* original a010, guest PC 0x0c06ef9c */
if(!s->budget--) { s->failed_pc=0x0c06ef9cu; return 0; }
r[4]=0x0000001au;
goto P_0c06efc0;
P_0c06ef9e: /* original e41a, guest PC 0x0c06ef9e */
if(!s->budget--) { s->failed_pc=0x0c06ef9eu; return 0; }
r[4]=0x0000001au;
goto P_0c06efa0;
P_0c06efa0: /* original 6043, guest PC 0x0c06efa0 */
if(!s->budget--) { s->failed_pc=0x0c06efa0u; return 0; }
r[0]=r[4];
goto P_0c06efa2;
P_0c06efa2: /* original 8818, guest PC 0x0c06efa2 */
if(!s->budget--) { s->failed_pc=0x0c06efa2u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000018u)!=0);
goto P_0c06efa4;
P_0c06efa4: /* original 8b05, guest PC 0x0c06efa4 */
if(!s->budget--) { s->failed_pc=0x0c06efa4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06efb2; }
goto P_0c06efa6;
P_0c06efa6: /* original 9047, guest PC 0x0c06efa6 */
if(!s->budget--) { s->failed_pc=0x0c06efa6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06f038u,2);
goto P_0c06efa8;
P_0c06efa8: /* original 01dc, guest PC 0x0c06efa8 */
if(!s->budget--) { s->failed_pc=0x0c06efa8u; return 0; }
r[1]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+r[0],1);
goto P_0c06efaa;
P_0c06efaa: /* original 2118, guest PC 0x0c06efaa */
if(!s->budget--) { s->failed_pc=0x0c06efaau; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[1])==0)!=0);
goto P_0c06efac;
P_0c06efac: /* original 8908, guest PC 0x0c06efac */
if(!s->budget--) { s->failed_pc=0x0c06efacu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c06efc0; }
goto P_0c06efae;
P_0c06efae: /* original a007, guest PC 0x0c06efae */
if(!s->budget--) { s->failed_pc=0x0c06efaeu; return 0; }
r[4]=0x0000001bu;
goto P_0c06efc0;
P_0c06efb0: /* original e41b, guest PC 0x0c06efb0 */
if(!s->budget--) { s->failed_pc=0x0c06efb0u; return 0; }
r[4]=0x0000001bu;
goto P_0c06efb2;
P_0c06efb2: /* original 880c, guest PC 0x0c06efb2 */
if(!s->budget--) { s->failed_pc=0x0c06efb2u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000cu)!=0);
goto P_0c06efb4;
P_0c06efb4: /* original 8b04, guest PC 0x0c06efb4 */
if(!s->budget--) { s->failed_pc=0x0c06efb4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06efc0; }
goto P_0c06efb6;
P_0c06efb6: /* original 9040, guest PC 0x0c06efb6 */
if(!s->budget--) { s->failed_pc=0x0c06efb6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06f03au,2);
goto P_0c06efb8;
P_0c06efb8: /* original 01dc, guest PC 0x0c06efb8 */
if(!s->budget--) { s->failed_pc=0x0c06efb8u; return 0; }
r[1]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+r[0],1);
goto P_0c06efba;
P_0c06efba: /* original 2118, guest PC 0x0c06efba */
if(!s->budget--) { s->failed_pc=0x0c06efbau; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[1])==0)!=0);
goto P_0c06efbc;
P_0c06efbc: /* original 8900, guest PC 0x0c06efbc */
if(!s->budget--) { s->failed_pc=0x0c06efbcu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c06efc0; }
goto P_0c06efbe;
P_0c06efbe: /* original e41c, guest PC 0x0c06efbe */
if(!s->budget--) { s->failed_pc=0x0c06efbeu; return 0; }
r[4]=0x0000001cu;
goto P_0c06efc0;
P_0c06efc0: /* original d326, guest PC 0x0c06efc0 */
if(!s->budget--) { s->failed_pc=0x0c06efc0u; return 0; }
r[3]=read(ram,0x0c06f05cu,4);
goto P_0c06efc2;
P_0c06efc2: /* original 4400, guest PC 0x0c06efc2 */
if(!s->budget--) { s->failed_pc=0x0c06efc2u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c06efc4;
P_0c06efc4: /* original 4408, guest PC 0x0c06efc4 */
if(!s->budget--) { s->failed_pc=0x0c06efc4u; return 0; }
r[4]<<=2;
goto P_0c06efc6;
P_0c06efc6: /* original 343c, guest PC 0x0c06efc6 */
if(!s->budget--) { s->failed_pc=0x0c06efc6u; return 0; }
r[4]+=r[3];
goto P_0c06efc8;
P_0c06efc8: /* original 6c42, guest PC 0x0c06efc8 */
if(!s->budget--) { s->failed_pc=0x0c06efc8u; return 0; }
tmp=read(ram,r[4],4);
r[12]=tmp;
goto P_0c06efca;
P_0c06efca: /* original 2cc8, guest PC 0x0c06efca */
if(!s->budget--) { s->failed_pc=0x0c06efcau; return 0; }
r[17]=(r[17]&~1u)|(((r[12]&r[12])==0)!=0);
goto P_0c06efcc;
P_0c06efcc: /* original 892a, guest PC 0x0c06efcc */
if(!s->budget--) { s->failed_pc=0x0c06efccu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c06f024; }
goto P_0c06efce;
P_0c06efce: /* original 84b4, guest PC 0x0c06efce */
if(!s->budget--) { s->failed_pc=0x0c06efceu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[11]+4,1);
goto P_0c06efd0;
P_0c06efd0: /* original 9534, guest PC 0x0c06efd0 */
if(!s->budget--) { s->failed_pc=0x0c06efd0u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06f03cu,2);
goto P_0c06efd2;
P_0c06efd2: /* original 600c, guest PC 0x0c06efd2 */
if(!s->budget--) { s->failed_pc=0x0c06efd2u; return 0; }
r[0]=r[0]&255u;
goto P_0c06efd4;
P_0c06efd4: /* original d822, guest PC 0x0c06efd4 */
if(!s->budget--) { s->failed_pc=0x0c06efd4u; return 0; }
r[8]=read(ram,0x0c06f060u,4);
goto P_0c06efd6;
P_0c06efd6: /* original 205f, guest PC 0x0c06efd6 */
if(!s->budget--) { s->failed_pc=0x0c06efd6u; return 0; }
r[19]=(uint32_t)((int32_t)(int16_t)r[0]*(int32_t)(int16_t)r[5]);
goto P_0c06efd8;
P_0c06efd8: /* original da22, guest PC 0x0c06efd8 */
if(!s->budget--) { s->failed_pc=0x0c06efd8u; return 0; }
r[10]=read(ram,0x0c06f064u,4);
goto P_0c06efda;
P_0c06efda: /* original 5441, guest PC 0x0c06efda */
if(!s->budget--) { s->failed_pc=0x0c06efdau; return 0; }
r[4]=read(ram,r[4]+4,4);
goto P_0c06efdc;
P_0c06efdc: /* original 051a, guest PC 0x0c06efdc */
if(!s->budget--) { s->failed_pc=0x0c06efdcu; return 0; }
r[5]=r[19];
goto P_0c06efde;
P_0c06efde: /* original 1e44, guest PC 0x0c06efde */
if(!s->budget--) { s->failed_pc=0x0c06efdeu; return 0; }
write(ram,r[14]+16,r[4],4);
goto P_0c06efe0;
P_0c06efe0: /* original 655f, guest PC 0x0c06efe0 */
if(!s->budget--) { s->failed_pc=0x0c06efe0u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)r[5];
goto P_0c06efe2;
P_0c06efe2: /* original 3a5c, guest PC 0x0c06efe2 */
if(!s->budget--) { s->failed_pc=0x0c06efe2u; return 0; }
r[10]+=r[5];
goto P_0c06efe4;
P_0c06efe4: /* original 385c, guest PC 0x0c06efe4 */
if(!s->budget--) { s->failed_pc=0x0c06efe4u; return 0; }
r[8]+=r[5];
goto P_0c06efe6;
P_0c06efe6: /* original a01a, guest PC 0x0c06efe6 */
if(!s->budget--) { s->failed_pc=0x0c06efe6u; return 0; }
r[9]=0x00000000u;
goto P_0c06f01e;
P_0c06efe8: /* original e900, guest PC 0x0c06efe8 */
if(!s->budget--) { s->failed_pc=0x0c06efe8u; return 0; }
r[9]=0x00000000u;
goto P_0c06efea;
P_0c06efea: /* original 9d28, guest PC 0x0c06efea */
if(!s->budget--) { s->failed_pc=0x0c06efeau; return 0; }
r[13]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06f03eu,2);
goto P_0c06efec;
P_0c06efec: /* original 63e3, guest PC 0x0c06efec */
if(!s->budget--) { s->failed_pc=0x0c06efecu; return 0; }
r[3]=r[14];
goto P_0c06efee;
P_0c06efee: /* original 62c2, guest PC 0x0c06efee */
if(!s->budget--) { s->failed_pc=0x0c06efeeu; return 0; }
tmp=read(ram,r[12],4);
r[2]=tmp;
goto P_0c06eff0;
P_0c06eff0: /* original 7314, guest PC 0x0c06eff0 */
if(!s->budget--) { s->failed_pc=0x0c06eff0u; return 0; }
r[3]+=0x00000014u;
goto P_0c06eff2;
P_0c06eff2: /* original 29df, guest PC 0x0c06eff2 */
if(!s->budget--) { s->failed_pc=0x0c06eff2u; return 0; }
r[19]=(uint32_t)((int32_t)(int16_t)r[9]*(int32_t)(int16_t)r[13]);
goto P_0c06eff4;
P_0c06eff4: /* original e068, guest PC 0x0c06eff4 */
if(!s->budget--) { s->failed_pc=0x0c06eff4u; return 0; }
r[0]=0x00000068u;
goto P_0c06eff6;
P_0c06eff6: /* original 56c1, guest PC 0x0c06eff6 */
if(!s->budget--) { s->failed_pc=0x0c06eff6u; return 0; }
r[6]=read(ram,r[12]+4,4);
goto P_0c06eff8;
P_0c06eff8: /* original 6783, guest PC 0x0c06eff8 */
if(!s->budget--) { s->failed_pc=0x0c06eff8u; return 0; }
r[7]=r[8];
goto P_0c06effa;
P_0c06effa: /* original 0d1a, guest PC 0x0c06effa */
if(!s->budget--) { s->failed_pc=0x0c06effau; return 0; }
r[13]=r[19];
goto P_0c06effc;
P_0c06effc: /* original 6ddf, guest PC 0x0c06effc */
if(!s->budget--) { s->failed_pc=0x0c06effcu; return 0; }
r[13]=(uint32_t)(int32_t)(int16_t)r[13];
goto P_0c06effe;
P_0c06effe: /* original 3d3c, guest PC 0x0c06effe */
if(!s->budget--) { s->failed_pc=0x0c06effeu; return 0; }
r[13]+=r[3];
goto P_0c06f000;
P_0c06f000: /* original 65d3, guest PC 0x0c06f000 */
if(!s->budget--) { s->failed_pc=0x0c06f000u; return 0; }
r[5]=r[13];
goto P_0c06f002;
P_0c06f002: /* original 0d26, guest PC 0x0c06f002 */
if(!s->budget--) { s->failed_pc=0x0c06f002u; return 0; }
write(ram,r[13]+r[0],r[2],4);
goto P_0c06f004;
P_0c06f004: /* original b030, guest PC 0x0c06f004 */
if(!s->budget--) { s->failed_pc=0x0c06f004u; return 0; }
target=0x0c06f068u; r[16]=0x0c06f008u;
r[4]=r[11];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c06f008u) { target=s->pc; goto dispatch; }
goto P_0c06f008;
P_0c06f006: /* original 64b3, guest PC 0x0c06f006 */
if(!s->budget--) { s->failed_pc=0x0c06f006u; return 0; }
r[4]=r[11];
goto P_0c06f008;
P_0c06f008: /* original 1da2, guest PC 0x0c06f008 */
if(!s->budget--) { s->failed_pc=0x0c06f008u; return 0; }
write(ram,r[13]+8,r[10],4);
goto P_0c06f00a;
P_0c06f00a: /* original 7c0c, guest PC 0x0c06f00a */
if(!s->budget--) { s->failed_pc=0x0c06f00au; return 0; }
r[12]+=0x0000000cu;
goto P_0c06f00c;
P_0c06f00c: /* original 62d2, guest PC 0x0c06f00c */
if(!s->budget--) { s->failed_pc=0x0c06f00cu; return 0; }
tmp=read(ram,r[13],4);
r[2]=tmp;
goto P_0c06f00e;
P_0c06f00e: /* original 7901, guest PC 0x0c06f00e */
if(!s->budget--) { s->failed_pc=0x0c06f00eu; return 0; }
r[9]+=0x00000001u;
goto P_0c06f010;
P_0c06f010: /* original 6803, guest PC 0x0c06f010 */
if(!s->budget--) { s->failed_pc=0x0c06f010u; return 0; }
r[8]=r[0];
goto P_0c06f012;
P_0c06f012: /* original 6323, guest PC 0x0c06f012 */
if(!s->budget--) { s->failed_pc=0x0c06f012u; return 0; }
r[3]=r[2];
goto P_0c06f014;
P_0c06f014: /* original 4200, guest PC 0x0c06f014 */
if(!s->budget--) { s->failed_pc=0x0c06f014u; return 0; }
r[17]=(r[17]&~1u)|((r[2]>>31)!=0);
r[2]<<=1;
goto P_0c06f016;
P_0c06f016: /* original 323c, guest PC 0x0c06f016 */
if(!s->budget--) { s->failed_pc=0x0c06f016u; return 0; }
r[2]+=r[3];
goto P_0c06f018;
P_0c06f018: /* original 4208, guest PC 0x0c06f018 */
if(!s->budget--) { s->failed_pc=0x0c06f018u; return 0; }
r[2]<<=2;
goto P_0c06f01a;
P_0c06f01a: /* original 4200, guest PC 0x0c06f01a */
if(!s->budget--) { s->failed_pc=0x0c06f01au; return 0; }
r[17]=(r[17]&~1u)|((r[2]>>31)!=0);
r[2]<<=1;
goto P_0c06f01c;
P_0c06f01c: /* original 3a2c, guest PC 0x0c06f01c */
if(!s->budget--) { s->failed_pc=0x0c06f01cu; return 0; }
r[10]+=r[2];
goto P_0c06f01e;
P_0c06f01e: /* original 52e4, guest PC 0x0c06f01e */
if(!s->budget--) { s->failed_pc=0x0c06f01eu; return 0; }
r[2]=read(ram,r[14]+16,4);
goto P_0c06f020;
P_0c06f020: /* original 3923, guest PC 0x0c06f020 */
if(!s->budget--) { s->failed_pc=0x0c06f020u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[9]>=(int32_t)r[2])!=0);
goto P_0c06f022;
P_0c06f022: /* original 8be2, guest PC 0x0c06f022 */
if(!s->budget--) { s->failed_pc=0x0c06f022u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06efea; }
goto P_0c06f024;
P_0c06f024: /* original 4f16, guest PC 0x0c06f024 */
if(!s->budget--) { s->failed_pc=0x0c06f024u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c06f026;
P_0c06f026: /* original 4f26, guest PC 0x0c06f026 */
if(!s->budget--) { s->failed_pc=0x0c06f026u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c06f028;
P_0c06f028: /* original 68f6, guest PC 0x0c06f028 */
if(!s->budget--) { s->failed_pc=0x0c06f028u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c06f02a;
P_0c06f02a: /* original 69f6, guest PC 0x0c06f02a */
if(!s->budget--) { s->failed_pc=0x0c06f02au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c06f02c;
P_0c06f02c: /* original 6af6, guest PC 0x0c06f02c */
if(!s->budget--) { s->failed_pc=0x0c06f02cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c06f02e;
P_0c06f02e: /* original 6bf6, guest PC 0x0c06f02e */
if(!s->budget--) { s->failed_pc=0x0c06f02eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c06f030;
P_0c06f030: /* original 6cf6, guest PC 0x0c06f030 */
if(!s->budget--) { s->failed_pc=0x0c06f030u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c06f032;
P_0c06f032: /* original 6df6, guest PC 0x0c06f032 */
if(!s->budget--) { s->failed_pc=0x0c06f032u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c06f034;
P_0c06f034: /* original 000b, guest PC 0x0c06f034 */
if(!s->budget--) { s->failed_pc=0x0c06f034u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c06f036: /* original 6ef6, guest PC 0x0c06f036 */
if(!s->budget--) { s->failed_pc=0x0c06f036u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c06f038u,s,ram);
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
r[16]=0x0c072b64u;
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
r[16]=0x0c072bf4u;
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
r[16]=0x0c072c9au;
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
r[16]=0x0c072ca4u;
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
r[16]=0x0c072caeu;
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
r[16]=0x0c072cb4u;
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
target=0x0c073f82u; r[16]=0x0c073938u;
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
r[16]=0x0c07394cu;
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
r[16]=0x0c073996u;
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
target=0x0c074702u; r[16]=0x0c07399cu;
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
target=0x0c074702u; r[16]=0x0c0739a2u;
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
target=0x0c0747b2u; r[16]=0x0c0739a8u;
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
r[16]=0x0c0739b0u;
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
r[16]=0x0c0739b8u;
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
target=0x0c074800u; r[16]=0x0c0739beu;
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
r[16]=0x0c0739c6u;
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
r[16]=0x0c0739e6u;
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
target=0x0c0748c0u; r[16]=0x0c0739ecu;
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
target=0x0c074634u; r[16]=0x0c073a10u;
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
target=0x0c074592u; r[16]=0x0c073a18u;
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
target=0x0c073aacu; r[16]=0x0c073a24u;
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
target=0x0c07413eu; r[16]=0x0c073a2cu;
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
target=0x0c0748c0u; r[16]=0x0c073a32u;
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
r[16]=0x0c073a54u;
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
target=0x0c074702u; r[16]=0x0c073a5au;
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
target=0x0c074702u; r[16]=0x0c073a60u;
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
target=0x0c07482eu; r[16]=0x0c073a66u;
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
r[16]=0x0c073a6cu;
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
P_0c074930: /* original 2fe6, guest PC 0x0c074930 */
if(!s->budget--) { s->failed_pc=0x0c074930u; return 0; }
r[15]-=4; write(ram,r[15],r[14],4);
goto P_0c074932;
P_0c074932: /* original ee00, guest PC 0x0c074932 */
if(!s->budget--) { s->failed_pc=0x0c074932u; return 0; }
r[14]=0x00000000u;
goto P_0c074934;
P_0c074934: /* original 2fd6, guest PC 0x0c074934 */
if(!s->budget--) { s->failed_pc=0x0c074934u; return 0; }
r[15]-=4; write(ram,r[15],r[13],4);
goto P_0c074936;
P_0c074936: /* original 2fc6, guest PC 0x0c074936 */
if(!s->budget--) { s->failed_pc=0x0c074936u; return 0; }
r[15]-=4; write(ram,r[15],r[12],4);
goto P_0c074938;
P_0c074938: /* original 2fb6, guest PC 0x0c074938 */
if(!s->budget--) { s->failed_pc=0x0c074938u; return 0; }
r[15]-=4; write(ram,r[15],r[11],4);
goto P_0c07493a;
P_0c07493a: /* original 9034, guest PC 0x0c07493a */
if(!s->budget--) { s->failed_pc=0x0c07493au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0749a6u,2);
goto P_0c07493c;
P_0c07493c: /* original 7ffc, guest PC 0x0c07493c */
if(!s->budget--) { s->failed_pc=0x0c07493cu; return 0; }
r[15]+=0xfffffffcu;
goto P_0c07493e;
P_0c07493e: /* original 0d4c, guest PC 0x0c07493e */
if(!s->budget--) { s->failed_pc=0x0c07493eu; return 0; }
r[13]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c074940;
P_0c074940: /* original 60dc, guest PC 0x0c074940 */
if(!s->budget--) { s->failed_pc=0x0c074940u; return 0; }
r[0]=r[13]&255u;
goto P_0c074942;
P_0c074942: /* original 8800, guest PC 0x0c074942 */
if(!s->budget--) { s->failed_pc=0x0c074942u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000000u)!=0);
goto P_0c074944;
P_0c074944: /* original 8d13, guest PC 0x0c074944 */
if(!s->budget--) { s->failed_pc=0x0c074944u; return 0; }
cond=r[17]&1u;
r[13]=r[0];
if(cond) { goto P_0c07496e; }
goto P_0c074948;
P_0c074946: /* original 6d03, guest PC 0x0c074946 */
if(!s->budget--) { s->failed_pc=0x0c074946u; return 0; }
r[13]=r[0];
goto P_0c074948;
P_0c074948: /* original 8801, guest PC 0x0c074948 */
if(!s->budget--) { s->failed_pc=0x0c074948u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c07494a;
P_0c07494a: /* original 8916, guest PC 0x0c07494a */
if(!s->budget--) { s->failed_pc=0x0c07494au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07497a; }
goto P_0c07494c;
P_0c07494c: /* original 8802, guest PC 0x0c07494c */
if(!s->budget--) { s->failed_pc=0x0c07494cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c07494e;
P_0c07494e: /* original 8906, guest PC 0x0c07494e */
if(!s->budget--) { s->failed_pc=0x0c07494eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07495e; }
goto P_0c074950;
P_0c074950: /* original 8803, guest PC 0x0c074950 */
if(!s->budget--) { s->failed_pc=0x0c074950u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000003u)!=0);
goto P_0c074952;
P_0c074952: /* original 890f, guest PC 0x0c074952 */
if(!s->budget--) { s->failed_pc=0x0c074952u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c074974; }
goto P_0c074954;
P_0c074954: /* original 8805, guest PC 0x0c074954 */
if(!s->budget--) { s->failed_pc=0x0c074954u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000005u)!=0);
goto P_0c074956;
P_0c074956: /* original 8902, guest PC 0x0c074956 */
if(!s->budget--) { s->failed_pc=0x0c074956u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07495e; }
goto P_0c074958;
P_0c074958: /* original 60d3, guest PC 0x0c074958 */
if(!s->budget--) { s->failed_pc=0x0c074958u; return 0; }
r[0]=r[13];
goto P_0c07495a;
P_0c07495a: /* original 8806, guest PC 0x0c07495a */
if(!s->budget--) { s->failed_pc=0x0c07495au; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000006u)!=0);
goto P_0c07495c;
P_0c07495c: /* original 8b60, guest PC 0x0c07495c */
if(!s->budget--) { s->failed_pc=0x0c07495cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c074a20; }
goto P_0c07495e;
P_0c07495e: /* original e048, guest PC 0x0c07495e */
if(!s->budget--) { s->failed_pc=0x0c07495eu; return 0; }
r[0]=0x00000048u;
goto P_0c074960;
P_0c074960: /* original d314, guest PC 0x0c074960 */
if(!s->budget--) { s->failed_pc=0x0c074960u; return 0; }
r[3]=read(ram,0x0c0749b4u,4);
goto P_0c074962;
P_0c074962: /* original 0c5e, guest PC 0x0c074962 */
if(!s->budget--) { s->failed_pc=0x0c074962u; return 0; }
r[12]=read(ram,r[5]+r[0],4);
goto P_0c074964;
P_0c074964: /* original 23c8, guest PC 0x0c074964 */
if(!s->budget--) { s->failed_pc=0x0c074964u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[12])==0)!=0);
goto P_0c074966;
P_0c074966: /* original 895b, guest PC 0x0c074966 */
if(!s->budget--) { s->failed_pc=0x0c074966u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c074a20; }
goto P_0c074968;
P_0c074968: /* original dd13, guest PC 0x0c074968 */
if(!s->budget--) { s->failed_pc=0x0c074968u; return 0; }
r[13]=read(ram,0x0c0749b8u,4);
goto P_0c07496a;
P_0c07496a: /* original a00c, guest PC 0x0c07496a */
if(!s->budget--) { s->failed_pc=0x0c07496au; return 0; }
goto P_0c074986;
P_0c07496c: /* original 0009, guest PC 0x0c07496c */
if(!s->budget--) { s->failed_pc=0x0c07496cu; return 0; }
goto P_0c07496e;
P_0c07496e: /* original dd13, guest PC 0x0c07496e */
if(!s->budget--) { s->failed_pc=0x0c07496eu; return 0; }
r[13]=read(ram,0x0c0749bcu,4);
goto P_0c074970;
P_0c074970: /* original a009, guest PC 0x0c074970 */
if(!s->budget--) { s->failed_pc=0x0c074970u; return 0; }
goto P_0c074986;
P_0c074972: /* original 0009, guest PC 0x0c074972 */
if(!s->budget--) { s->failed_pc=0x0c074972u; return 0; }
goto P_0c074974;
P_0c074974: /* original dd12, guest PC 0x0c074974 */
if(!s->budget--) { s->failed_pc=0x0c074974u; return 0; }
r[13]=read(ram,0x0c0749c0u,4);
goto P_0c074976;
P_0c074976: /* original a006, guest PC 0x0c074976 */
if(!s->budget--) { s->failed_pc=0x0c074976u; return 0; }
goto P_0c074986;
P_0c074978: /* original 0009, guest PC 0x0c074978 */
if(!s->budget--) { s->failed_pc=0x0c074978u; return 0; }
goto P_0c07497a;
P_0c07497a: /* original 667c, guest PC 0x0c07497a */
if(!s->budget--) { s->failed_pc=0x0c07497au; return 0; }
r[6]=r[7]&255u;
goto P_0c07497c;
P_0c07497c: /* original dd11, guest PC 0x0c07497c */
if(!s->budget--) { s->failed_pc=0x0c07497cu; return 0; }
r[13]=read(ram,0x0c0749c4u,4);
goto P_0c07497e;
P_0c07497e: /* original 6063, guest PC 0x0c07497e */
if(!s->budget--) { s->failed_pc=0x0c07497eu; return 0; }
r[0]=r[6];
goto P_0c074980;
P_0c074980: /* original 880b, guest PC 0x0c074980 */
if(!s->budget--) { s->failed_pc=0x0c074980u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000bu)!=0);
goto P_0c074982;
P_0c074982: /* original 8b00, guest PC 0x0c074982 */
if(!s->budget--) { s->failed_pc=0x0c074982u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c074986; }
goto P_0c074984;
P_0c074984: /* original dd10, guest PC 0x0c074984 */
if(!s->budget--) { s->failed_pc=0x0c074984u; return 0; }
r[13]=read(ram,0x0c0749c8u,4);
goto P_0c074986;
P_0c074986: /* original 900f, guest PC 0x0c074986 */
if(!s->budget--) { s->failed_pc=0x0c074986u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0749a8u,2);
goto P_0c074988;
P_0c074988: /* original eb01, guest PC 0x0c074988 */
if(!s->budget--) { s->failed_pc=0x0c074988u; return 0; }
r[11]=0x00000001u;
goto P_0c07498a;
P_0c07498a: /* original 064e, guest PC 0x0c07498a */
if(!s->budget--) { s->failed_pc=0x0c07498au; return 0; }
r[6]=read(ram,r[4]+r[0],4);
goto P_0c07498c;
P_0c07498c: /* original 26b8, guest PC 0x0c07498c */
if(!s->budget--) { s->failed_pc=0x0c07498cu; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[11])==0)!=0);
goto P_0c07498e;
P_0c07498e: /* original 891e, guest PC 0x0c07498e */
if(!s->budget--) { s->failed_pc=0x0c07498eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0749ce; }
goto P_0c074990;
P_0c074990: /* original 900b, guest PC 0x0c074990 */
if(!s->budget--) { s->failed_pc=0x0c074990u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0749aau,2);
goto P_0c074992;
P_0c074992: /* original e31e, guest PC 0x0c074992 */
if(!s->budget--) { s->failed_pc=0x0c074992u; return 0; }
r[3]=0x0000001eu;
goto P_0c074994;
P_0c074994: /* original 064c, guest PC 0x0c074994 */
if(!s->budget--) { s->failed_pc=0x0c074994u; return 0; }
r[6]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c074996;
P_0c074996: /* original 666c, guest PC 0x0c074996 */
if(!s->budget--) { s->failed_pc=0x0c074996u; return 0; }
r[6]=r[6]&255u;
goto P_0c074998;
P_0c074998: /* original 3632, guest PC 0x0c074998 */
if(!s->budget--) { s->failed_pc=0x0c074998u; return 0; }
r[17]=(r[17]&~1u)|((r[6]>=r[3])!=0);
goto P_0c07499a;
P_0c07499a: /* original 8917, guest PC 0x0c07499a */
if(!s->budget--) { s->failed_pc=0x0c07499au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0749cc; }
goto P_0c07499c;
P_0c07499c: /* original a017, guest PC 0x0c07499c */
if(!s->budget--) { s->failed_pc=0x0c07499cu; return 0; }
r[14]=0x00000003u;
goto P_0c0749ce;
P_0c07499e: /* original ee03, guest PC 0x0c07499e */
if(!s->budget--) { s->failed_pc=0x0c07499eu; return 0; }
r[14]=0x00000003u;
return vf3_matrix_family(0x0c0749a0u,s,ram);
P_0c0749cc: /* original ee06, guest PC 0x0c0749cc */
if(!s->budget--) { s->failed_pc=0x0c0749ccu; return 0; }
r[14]=0x00000006u;
goto P_0c0749ce;
P_0c0749ce: /* original 6673, guest PC 0x0c0749ce */
if(!s->budget--) { s->failed_pc=0x0c0749ceu; return 0; }
r[6]=r[7];
goto P_0c0749d0;
P_0c0749d0: /* original d73f, guest PC 0x0c0749d0 */
if(!s->budget--) { s->failed_pc=0x0c0749d0u; return 0; }
r[7]=read(ram,0x0c074ad0u,4);
goto P_0c0749d2;
P_0c0749d2: /* original 6363, guest PC 0x0c0749d2 */
if(!s->budget--) { s->failed_pc=0x0c0749d2u; return 0; }
r[3]=r[6];
goto P_0c0749d4;
P_0c0749d4: /* original 2378, guest PC 0x0c0749d4 */
if(!s->budget--) { s->failed_pc=0x0c0749d4u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[7])==0)!=0);
goto P_0c0749d6;
P_0c0749d6: /* original 8b02, guest PC 0x0c0749d6 */
if(!s->budget--) { s->failed_pc=0x0c0749d6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0749de; }
goto P_0c0749d8;
P_0c0749d8: /* original d13e, guest PC 0x0c0749d8 */
if(!s->budget--) { s->failed_pc=0x0c0749d8u; return 0; }
r[1]=read(ram,0x0c074ad4u,4);
goto P_0c0749da;
P_0c0749da: /* original 2168, guest PC 0x0c0749da */
if(!s->budget--) { s->failed_pc=0x0c0749dau; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[6])==0)!=0);
goto P_0c0749dc;
P_0c0749dc: /* original 8914, guest PC 0x0c0749dc */
if(!s->budget--) { s->failed_pc=0x0c0749dcu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c074a08; }
goto P_0c0749de;
P_0c0749de: /* original 6442, guest PC 0x0c0749de */
if(!s->budget--) { s->failed_pc=0x0c0749deu; return 0; }
tmp=read(ram,r[4],4);
r[4]=tmp;
goto P_0c0749e0;
P_0c0749e0: /* original 6352, guest PC 0x0c0749e0 */
if(!s->budget--) { s->failed_pc=0x0c0749e0u; return 0; }
tmp=read(ram,r[5],4);
r[3]=tmp;
goto P_0c0749e2;
P_0c0749e2: /* original 243a, guest PC 0x0c0749e2 */
if(!s->budget--) { s->failed_pc=0x0c0749e2u; return 0; }
r[4]^=r[3];
goto P_0c0749e4;
P_0c0749e4: /* original 4429, guest PC 0x0c0749e4 */
if(!s->budget--) { s->failed_pc=0x0c0749e4u; return 0; }
r[4]>>=16;
goto P_0c0749e6;
P_0c0749e6: /* original 4419, guest PC 0x0c0749e6 */
if(!s->budget--) { s->failed_pc=0x0c0749e6u; return 0; }
r[4]>>=8;
goto P_0c0749e8;
P_0c0749e8: /* original 4401, guest PC 0x0c0749e8 */
if(!s->budget--) { s->failed_pc=0x0c0749e8u; return 0; }
r[17]=(r[17]&~1u)|((r[4]&1)!=0);
r[4]>>=1;
goto P_0c0749ea;
P_0c0749ea: /* original 2f42, guest PC 0x0c0749ea */
if(!s->budget--) { s->failed_pc=0x0c0749eau; return 0; }
write(ram,r[15],r[4],4);
goto P_0c0749ec;
P_0c0749ec: /* original 64c3, guest PC 0x0c0749ec */
if(!s->budget--) { s->failed_pc=0x0c0749ecu; return 0; }
r[4]=r[12];
goto P_0c0749ee;
P_0c0749ee: /* original 63f2, guest PC 0x0c0749ee */
if(!s->budget--) { s->failed_pc=0x0c0749eeu; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c0749f0;
P_0c0749f0: /* original 4419, guest PC 0x0c0749f0 */
if(!s->budget--) { s->failed_pc=0x0c0749f0u; return 0; }
r[4]>>=8;
goto P_0c0749f2;
P_0c0749f2: /* original 4409, guest PC 0x0c0749f2 */
if(!s->budget--) { s->failed_pc=0x0c0749f2u; return 0; }
r[4]>>=2;
goto P_0c0749f4;
P_0c0749f4: /* original 243a, guest PC 0x0c0749f4 */
if(!s->budget--) { s->failed_pc=0x0c0749f4u; return 0; }
r[4]^=r[3];
goto P_0c0749f6;
P_0c0749f6: /* original 24b8, guest PC 0x0c0749f6 */
if(!s->budget--) { s->failed_pc=0x0c0749f6u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[11])==0)!=0);
goto P_0c0749f8;
P_0c0749f8: /* original 8900, guest PC 0x0c0749f8 */
if(!s->budget--) { s->failed_pc=0x0c0749f8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0749fc; }
goto P_0c0749fa;
P_0c0749fa: /* original 6667, guest PC 0x0c0749fa */
if(!s->budget--) { s->failed_pc=0x0c0749fau; return 0; }
r[6]=~r[6];
goto P_0c0749fc;
P_0c0749fc: /* original 2678, guest PC 0x0c0749fc */
if(!s->budget--) { s->failed_pc=0x0c0749fcu; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[7])==0)!=0);
goto P_0c0749fe;
P_0c0749fe: /* original 8b01, guest PC 0x0c0749fe */
if(!s->budget--) { s->failed_pc=0x0c0749feu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c074a04; }
goto P_0c074a00;
P_0c074a00: /* original a001, guest PC 0x0c074a00 */
if(!s->budget--) { s->failed_pc=0x0c074a00u; return 0; }
r[4]=0x00000002u;
goto P_0c074a06;
P_0c074a02: /* original e402, guest PC 0x0c074a02 */
if(!s->budget--) { s->failed_pc=0x0c074a02u; return 0; }
r[4]=0x00000002u;
goto P_0c074a04;
P_0c074a04: /* original 64b3, guest PC 0x0c074a04 */
if(!s->budget--) { s->failed_pc=0x0c074a04u; return 0; }
r[4]=r[11];
goto P_0c074a06;
P_0c074a06: /* original 3e4c, guest PC 0x0c074a06 */
if(!s->budget--) { s->failed_pc=0x0c074a06u; return 0; }
r[14]+=r[4];
goto P_0c074a08;
P_0c074a08: /* original e061, guest PC 0x0c074a08 */
if(!s->budget--) { s->failed_pc=0x0c074a08u; return 0; }
r[0]=0x00000061u;
goto P_0c074a0a;
P_0c074a0a: /* original 045c, guest PC 0x0c074a0a */
if(!s->budget--) { s->failed_pc=0x0c074a0au; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[5]+r[0],1);
goto P_0c074a0c;
P_0c074a0c: /* original 604c, guest PC 0x0c074a0c */
if(!s->budget--) { s->failed_pc=0x0c074a0cu; return 0; }
r[0]=r[4]&255u;
goto P_0c074a0e;
P_0c074a0e: /* original 880c, guest PC 0x0c074a0e */
if(!s->budget--) { s->failed_pc=0x0c074a0eu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000cu)!=0);
goto P_0c074a10;
P_0c074a10: /* original 8f01, guest PC 0x0c074a10 */
if(!s->budget--) { s->failed_pc=0x0c074a10u; return 0; }
cond=r[17]&1u;
r[4]=r[0];
if(!cond) { goto P_0c074a16; }
goto P_0c074a14;
P_0c074a12: /* original 6403, guest PC 0x0c074a12 */
if(!s->budget--) { s->failed_pc=0x0c074a12u; return 0; }
r[4]=r[0];
goto P_0c074a14;
P_0c074a14: /* original 7e0c, guest PC 0x0c074a14 */
if(!s->budget--) { s->failed_pc=0x0c074a14u; return 0; }
r[14]+=0x0000000cu;
goto P_0c074a16;
P_0c074a16: /* original 66d3, guest PC 0x0c074a16 */
if(!s->budget--) { s->failed_pc=0x0c074a16u; return 0; }
r[6]=r[13];
goto P_0c074a18;
P_0c074a18: /* original 4e00, guest PC 0x0c074a18 */
if(!s->budget--) { s->failed_pc=0x0c074a18u; return 0; }
r[17]=(r[17]&~1u)|((r[14]>>31)!=0);
r[14]<<=1;
goto P_0c074a1a;
P_0c074a1a: /* original 36ec, guest PC 0x0c074a1a */
if(!s->budget--) { s->failed_pc=0x0c074a1au; return 0; }
r[6]+=r[14];
goto P_0c074a1c;
P_0c074a1c: /* original 6661, guest PC 0x0c074a1c */
if(!s->budget--) { s->failed_pc=0x0c074a1cu; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[6],2);
r[6]=tmp;
goto P_0c074a1e;
P_0c074a1e: /* original 666d, guest PC 0x0c074a1e */
if(!s->budget--) { s->failed_pc=0x0c074a1eu; return 0; }
r[6]=r[6]&65535u;
goto P_0c074a20;
P_0c074a20: /* original 7f04, guest PC 0x0c074a20 */
if(!s->budget--) { s->failed_pc=0x0c074a20u; return 0; }
r[15]+=0x00000004u;
goto P_0c074a22;
P_0c074a22: /* original 6063, guest PC 0x0c074a22 */
if(!s->budget--) { s->failed_pc=0x0c074a22u; return 0; }
r[0]=r[6];
goto P_0c074a24;
P_0c074a24: /* original 6bf6, guest PC 0x0c074a24 */
if(!s->budget--) { s->failed_pc=0x0c074a24u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c074a26;
P_0c074a26: /* original 6cf6, guest PC 0x0c074a26 */
if(!s->budget--) { s->failed_pc=0x0c074a26u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c074a28;
P_0c074a28: /* original 6df6, guest PC 0x0c074a28 */
if(!s->budget--) { s->failed_pc=0x0c074a28u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c074a2a;
P_0c074a2a: /* original 000b, guest PC 0x0c074a2a */
if(!s->budget--) { s->failed_pc=0x0c074a2au; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c074a2c: /* original 6ef6, guest PC 0x0c074a2c */
if(!s->budget--) { s->failed_pc=0x0c074a2cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c074a2eu,s,ram);
P_0c074b0e: /* original 4f22, guest PC 0x0c074b0e */
if(!s->budget--) { s->failed_pc=0x0c074b0eu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c074b10;
P_0c074b10: /* original 7ff8, guest PC 0x0c074b10 */
if(!s->budget--) { s->failed_pc=0x0c074b10u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c074b12;
P_0c074b12: /* original 1f71, guest PC 0x0c074b12 */
if(!s->budget--) { s->failed_pc=0x0c074b12u; return 0; }
write(ram,r[15]+4,r[7],4);
goto P_0c074b14;
P_0c074b14: /* original 5dfb, guest PC 0x0c074b14 */
if(!s->budget--) { s->failed_pc=0x0c074b14u; return 0; }
r[13]=read(ram,r[15]+44,4);
goto P_0c074b16;
P_0c074b16: /* original 50fa, guest PC 0x0c074b16 */
if(!s->budget--) { s->failed_pc=0x0c074b16u; return 0; }
r[0]=read(ram,r[15]+40,4);
goto P_0c074b18;
P_0c074b18: /* original d932, guest PC 0x0c074b18 */
if(!s->budget--) { s->failed_pc=0x0c074b18u; return 0; }
r[9]=read(ram,0x0c074be4u,4);
goto P_0c074b1a;
P_0c074b1a: /* original 6ee2, guest PC 0x0c074b1a */
if(!s->budget--) { s->failed_pc=0x0c074b1au; return 0; }
tmp=read(ram,r[14],4);
r[14]=tmp;
goto P_0c074b1c;
P_0c074b1c: /* original 88ff, guest PC 0x0c074b1c */
if(!s->budget--) { s->failed_pc=0x0c074b1cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c074b1e;
P_0c074b1e: /* original 6dd2, guest PC 0x0c074b1e */
if(!s->budget--) { s->failed_pc=0x0c074b1eu; return 0; }
tmp=read(ram,r[13],4);
r[13]=tmp;
goto P_0c074b20;
P_0c074b20: /* original 8f02, guest PC 0x0c074b20 */
if(!s->budget--) { s->failed_pc=0x0c074b20u; return 0; }
cond=r[17]&1u;
r[8]=0x00000000u;
if(!cond) { goto P_0c074b28; }
goto P_0c074b24;
P_0c074b22: /* original e800, guest PC 0x0c074b22 */
if(!s->budget--) { s->failed_pc=0x0c074b22u; return 0; }
r[8]=0x00000000u;
goto P_0c074b24;
P_0c074b24: /* original a0d6, guest PC 0x0c074b24 */
if(!s->budget--) { s->failed_pc=0x0c074b24u; return 0; }
goto P_0c074cd4;
P_0c074b26: /* original 0009, guest PC 0x0c074b26 */
if(!s->budget--) { s->failed_pc=0x0c074b26u; return 0; }
goto P_0c074b28;
P_0c074b28: /* original e048, guest PC 0x0c074b28 */
if(!s->budget--) { s->failed_pc=0x0c074b28u; return 0; }
r[0]=0x00000048u;
goto P_0c074b2a;
P_0c074b2a: /* original db2f, guest PC 0x0c074b2a */
if(!s->budget--) { s->failed_pc=0x0c074b2au; return 0; }
r[11]=read(ram,0x0c074be8u,4);
goto P_0c074b2c;
P_0c074b2c: /* original 0d5e, guest PC 0x0c074b2c */
if(!s->budget--) { s->failed_pc=0x0c074b2cu; return 0; }
r[13]=read(ram,r[5]+r[0],4);
goto P_0c074b2e;
P_0c074b2e: /* original 63d3, guest PC 0x0c074b2e */
if(!s->budget--) { s->failed_pc=0x0c074b2eu; return 0; }
r[3]=r[13];
goto P_0c074b30;
P_0c074b30: /* original 2398, guest PC 0x0c074b30 */
if(!s->budget--) { s->failed_pc=0x0c074b30u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[9])==0)!=0);
goto P_0c074b32;
P_0c074b32: /* original 8d1a, guest PC 0x0c074b32 */
if(!s->budget--) { s->failed_pc=0x0c074b32u; return 0; }
cond=r[17]&1u;
r[7]=r[6];
if(cond) { goto P_0c074b6a; }
goto P_0c074b36;
P_0c074b34: /* original 6763, guest PC 0x0c074b34 */
if(!s->budget--) { s->failed_pc=0x0c074b34u; return 0; }
r[7]=r[6];
goto P_0c074b36;
P_0c074b36: /* original e03e, guest PC 0x0c074b36 */
if(!s->budget--) { s->failed_pc=0x0c074b36u; return 0; }
r[0]=0x0000003eu;
goto P_0c074b38;
P_0c074b38: /* original 065d, guest PC 0x0c074b38 */
if(!s->budget--) { s->failed_pc=0x0c074b38u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,r[5]+r[0],2);
goto P_0c074b3a;
P_0c074b3a: /* original 904a, guest PC 0x0c074b3a */
if(!s->budget--) { s->failed_pc=0x0c074b3au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c074bd2u,2);
goto P_0c074b3c;
P_0c074b3c: /* original 666d, guest PC 0x0c074b3c */
if(!s->budget--) { s->failed_pc=0x0c074b3cu; return 0; }
r[6]=r[6]&65535u;
goto P_0c074b3e;
P_0c074b3e: /* original 035d, guest PC 0x0c074b3e */
if(!s->budget--) { s->failed_pc=0x0c074b3eu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[5]+r[0],2);
goto P_0c074b40;
P_0c074b40: /* original 4600, guest PC 0x0c074b40 */
if(!s->budget--) { s->failed_pc=0x0c074b40u; return 0; }
r[17]=(r[17]&~1u)|((r[6]>>31)!=0);
r[6]<<=1;
goto P_0c074b42;
P_0c074b42: /* original 633d, guest PC 0x0c074b42 */
if(!s->budget--) { s->failed_pc=0x0c074b42u; return 0; }
r[3]=r[3]&65535u;
goto P_0c074b44;
P_0c074b44: /* original 3636, guest PC 0x0c074b44 */
if(!s->budget--) { s->failed_pc=0x0c074b44u; return 0; }
r[17]=(r[17]&~1u)|((r[6]>r[3])!=0);
goto P_0c074b46;
P_0c074b46: /* original 8d10, guest PC 0x0c074b46 */
if(!s->budget--) { s->failed_pc=0x0c074b46u; return 0; }
cond=r[17]&1u;
write(ram,r[15],r[3],4);
if(cond) { goto P_0c074b6a; }
goto P_0c074b4a;
P_0c074b48: /* original 2f32, guest PC 0x0c074b48 */
if(!s->budget--) { s->failed_pc=0x0c074b48u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c074b4a;
P_0c074b4a: /* original 9043, guest PC 0x0c074b4a */
if(!s->budget--) { s->failed_pc=0x0c074b4au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c074bd4u,2);
goto P_0c074b4c;
P_0c074b4c: /* original 9343, guest PC 0x0c074b4c */
if(!s->budget--) { s->failed_pc=0x0c074b4cu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c074bd6u,2);
goto P_0c074b4e;
P_0c074b4e: /* original 065d, guest PC 0x0c074b4e */
if(!s->budget--) { s->failed_pc=0x0c074b4eu; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,r[5]+r[0],2);
goto P_0c074b50;
P_0c074b50: /* original 3637, guest PC 0x0c074b50 */
if(!s->budget--) { s->failed_pc=0x0c074b50u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[6]>(int32_t)r[3])!=0);
goto P_0c074b52;
P_0c074b52: /* original 8b02, guest PC 0x0c074b52 */
if(!s->budget--) { s->failed_pc=0x0c074b52u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c074b5a; }
goto P_0c074b54;
P_0c074b54: /* original 9240, guest PC 0x0c074b54 */
if(!s->budget--) { s->failed_pc=0x0c074b54u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c074bd8u,2);
goto P_0c074b56;
P_0c074b56: /* original 3623, guest PC 0x0c074b56 */
if(!s->budget--) { s->failed_pc=0x0c074b56u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[6]>=(int32_t)r[2])!=0);
goto P_0c074b58;
P_0c074b58: /* original 8b07, guest PC 0x0c074b58 */
if(!s->budget--) { s->failed_pc=0x0c074b58u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c074b6a; }
goto P_0c074b5a;
P_0c074b5a: /* original d324, guest PC 0x0c074b5a */
if(!s->budget--) { s->failed_pc=0x0c074b5au; return 0; }
r[3]=read(ram,0x0c074becu,4);
goto P_0c074b5c;
P_0c074b5c: /* original e048, guest PC 0x0c074b5c */
if(!s->budget--) { s->failed_pc=0x0c074b5cu; return 0; }
r[0]=0x00000048u;
goto P_0c074b5e;
P_0c074b5e: /* original 2d39, guest PC 0x0c074b5e */
if(!s->budget--) { s->failed_pc=0x0c074b5eu; return 0; }
r[13]&=r[3];
goto P_0c074b60;
P_0c074b60: /* original 05d6, guest PC 0x0c074b60 */
if(!s->budget--) { s->failed_pc=0x0c074b60u; return 0; }
write(ram,r[5]+r[0],r[13],4);
goto P_0c074b62;
P_0c074b62: /* original e050, guest PC 0x0c074b62 */
if(!s->budget--) { s->failed_pc=0x0c074b62u; return 0; }
r[0]=0x00000050u;
goto P_0c074b64;
P_0c074b64: /* original 025e, guest PC 0x0c074b64 */
if(!s->budget--) { s->failed_pc=0x0c074b64u; return 0; }
r[2]=read(ram,r[5]+r[0],4);
goto P_0c074b66;
P_0c074b66: /* original 22ba, guest PC 0x0c074b66 */
if(!s->budget--) { s->failed_pc=0x0c074b66u; return 0; }
r[2]^=r[11];
goto P_0c074b68;
P_0c074b68: /* original 0526, guest PC 0x0c074b68 */
if(!s->budget--) { s->failed_pc=0x0c074b68u; return 0; }
write(ram,r[5]+r[0],r[2],4);
goto P_0c074b6a;
P_0c074b6a: /* original e320, guest PC 0x0c074b6a */
if(!s->budget--) { s->failed_pc=0x0c074b6au; return 0; }
r[3]=0x00000020u;
goto P_0c074b6c;
P_0c074b6c: /* original 23d8, guest PC 0x0c074b6c */
if(!s->budget--) { s->failed_pc=0x0c074b6cu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[13])==0)!=0);
goto P_0c074b6e;
P_0c074b6e: /* original 891e, guest PC 0x0c074b6e */
if(!s->budget--) { s->failed_pc=0x0c074b6eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c074bae; }
goto P_0c074b70;
P_0c074b70: /* original 9033, guest PC 0x0c074b70 */
if(!s->budget--) { s->failed_pc=0x0c074b70u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c074bdau,2);
goto P_0c074b72;
P_0c074b72: /* original f28d, guest PC 0x0c074b72 */
if(!s->budget--) { s->failed_pc=0x0c074b72u; return 0; }
fr[2]=0;
goto P_0c074b74;
P_0c074b74: /* original 064d, guest PC 0x0c074b74 */
if(!s->budget--) { s->failed_pc=0x0c074b74u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c074b76;
P_0c074b76: /* original 854f, guest PC 0x0c074b76 */
if(!s->budget--) { s->failed_pc=0x0c074b76u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+30,2);
goto P_0c074b78;
P_0c074b78: /* original d71d, guest PC 0x0c074b78 */
if(!s->budget--) { s->failed_pc=0x0c074b78u; return 0; }
r[7]=read(ram,0x0c074bf0u,4);
goto P_0c074b7a;
P_0c074b7a: /* original 360c, guest PC 0x0c074b7a */
if(!s->budget--) { s->failed_pc=0x0c074b7au; return 0; }
r[6]+=r[0];
goto P_0c074b7c;
P_0c074b7c: /* original 902e, guest PC 0x0c074b7c */
if(!s->budget--) { s->failed_pc=0x0c074b7cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c074bdcu,2);
goto P_0c074b7e;
P_0c074b7e: /* original 035d, guest PC 0x0c074b7e */
if(!s->budget--) { s->failed_pc=0x0c074b7eu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[5]+r[0],2);
goto P_0c074b80;
P_0c074b80: /* original 902d, guest PC 0x0c074b80 */
if(!s->budget--) { s->failed_pc=0x0c074b80u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c074bdeu,2);
goto P_0c074b82;
P_0c074b82: /* original 3638, guest PC 0x0c074b82 */
if(!s->budget--) { s->failed_pc=0x0c074b82u; return 0; }
r[6]-=r[3];
goto P_0c074b84;
P_0c074b84: /* original 9328, guest PC 0x0c074b84 */
if(!s->budget--) { s->failed_pc=0x0c074b84u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c074bd8u,2);
goto P_0c074b86;
P_0c074b86: /* original 025d, guest PC 0x0c074b86 */
if(!s->budget--) { s->failed_pc=0x0c074b86u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[5]+r[0],2);
goto P_0c074b88;
P_0c074b88: /* original 363c, guest PC 0x0c074b88 */
if(!s->budget--) { s->failed_pc=0x0c074b88u; return 0; }
r[6]+=r[3];
goto P_0c074b8a;
P_0c074b8a: /* original 622d, guest PC 0x0c074b8a */
if(!s->budget--) { s->failed_pc=0x0c074b8au; return 0; }
r[2]=r[2]&65535u;
goto P_0c074b8c;
P_0c074b8c: /* original 425a, guest PC 0x0c074b8c */
if(!s->budget--) { s->failed_pc=0x0c074b8cu; return 0; }
r[53]=r[2];
goto P_0c074b8e;
P_0c074b8e: /* original 4628, guest PC 0x0c074b8e */
if(!s->budget--) { s->failed_pc=0x0c074b8eu; return 0; }
r[6]<<=16;
goto P_0c074b90;
P_0c074b90: /* original 6463, guest PC 0x0c074b90 */
if(!s->budget--) { s->failed_pc=0x0c074b90u; return 0; }
r[4]=r[6];
goto P_0c074b92;
P_0c074b92: /* original f32d, guest PC 0x0c074b92 */
if(!s->budget--) { s->failed_pc=0x0c074b92u; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c074b94;
P_0c074b94: /* original f235, guest PC 0x0c074b94 */
if(!s->budget--) { s->failed_pc=0x0c074b94u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[2])>as_float(fr[3]))!=0);
goto P_0c074b96;
P_0c074b96: /* original 8f04, guest PC 0x0c074b96 */
if(!s->budget--) { s->failed_pc=0x0c074b96u; return 0; }
cond=r[17]&1u;
r[4]&=r[11];
if(!cond) { goto P_0c074ba2; }
goto P_0c074b9a;
P_0c074b98: /* original 24b9, guest PC 0x0c074b98 */
if(!s->budget--) { s->failed_pc=0x0c074b98u; return 0; }
r[4]&=r[11];
goto P_0c074b9a;
P_0c074b9a: /* original 2448, guest PC 0x0c074b9a */
if(!s->budget--) { s->failed_pc=0x0c074b9au; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c074b9c;
P_0c074b9c: /* original 8b05, guest PC 0x0c074b9c */
if(!s->budget--) { s->failed_pc=0x0c074b9cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c074baa; }
goto P_0c074b9e;
P_0c074b9e: /* original a002, guest PC 0x0c074b9e */
if(!s->budget--) { s->failed_pc=0x0c074b9eu; return 0; }
goto P_0c074ba6;
P_0c074ba0: /* original 0009, guest PC 0x0c074ba0 */
if(!s->budget--) { s->failed_pc=0x0c074ba0u; return 0; }
goto P_0c074ba2;
P_0c074ba2: /* original 2448, guest PC 0x0c074ba2 */
if(!s->budget--) { s->failed_pc=0x0c074ba2u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c074ba4;
P_0c074ba4: /* original 8901, guest PC 0x0c074ba4 */
if(!s->budget--) { s->failed_pc=0x0c074ba4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c074baa; }
goto P_0c074ba6;
P_0c074ba6: /* original a12b, guest PC 0x0c074ba6 */
if(!s->budget--) { s->failed_pc=0x0c074ba6u; return 0; }
r[14]=read(ram,r[7]+4,4);
goto P_0c074e00;
P_0c074ba8: /* original 5e71, guest PC 0x0c074ba8 */
if(!s->budget--) { s->failed_pc=0x0c074ba8u; return 0; }
r[14]=read(ram,r[7]+4,4);
goto P_0c074baa;
P_0c074baa: /* original a129, guest PC 0x0c074baa */
if(!s->budget--) { s->failed_pc=0x0c074baau; return 0; }
tmp=read(ram,r[7],4);
r[14]=tmp;
goto P_0c074e00;
P_0c074bac: /* original 6e72, guest PC 0x0c074bac */
if(!s->budget--) { s->failed_pc=0x0c074bacu; return 0; }
tmp=read(ram,r[7],4);
r[14]=tmp;
goto P_0c074bae;
P_0c074bae: /* original e04c, guest PC 0x0c074bae */
if(!s->budget--) { s->failed_pc=0x0c074baeu; return 0; }
r[0]=0x0000004cu;
goto P_0c074bb0;
P_0c074bb0: /* original 9316, guest PC 0x0c074bb0 */
if(!s->budget--) { s->failed_pc=0x0c074bb0u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c074be0u,2);
goto P_0c074bb2;
P_0c074bb2: /* original 025e, guest PC 0x0c074bb2 */
if(!s->budget--) { s->failed_pc=0x0c074bb2u; return 0; }
r[2]=read(ram,r[5]+r[0],4);
goto P_0c074bb4;
P_0c074bb4: /* original 2238, guest PC 0x0c074bb4 */
if(!s->budget--) { s->failed_pc=0x0c074bb4u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c074bb6;
P_0c074bb6: /* original 891f, guest PC 0x0c074bb6 */
if(!s->budget--) { s->failed_pc=0x0c074bb6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c074bf8; }
goto P_0c074bb8;
P_0c074bb8: /* original e050, guest PC 0x0c074bb8 */
if(!s->budget--) { s->failed_pc=0x0c074bb8u; return 0; }
r[0]=0x00000050u;
goto P_0c074bba;
P_0c074bba: /* original 065e, guest PC 0x0c074bba */
if(!s->budget--) { s->failed_pc=0x0c074bbau; return 0; }
r[6]=read(ram,r[5]+r[0],4);
goto P_0c074bbc;
P_0c074bbc: /* original 26b8, guest PC 0x0c074bbc */
if(!s->budget--) { s->failed_pc=0x0c074bbcu; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[11])==0)!=0);
goto P_0c074bbe;
P_0c074bbe: /* original 8d01, guest PC 0x0c074bbe */
if(!s->budget--) { s->failed_pc=0x0c074bbeu; return 0; }
cond=r[17]&1u;
r[4]=r[8];
if(cond) { goto P_0c074bc4; }
goto P_0c074bc2;
P_0c074bc0: /* original 6483, guest PC 0x0c074bc0 */
if(!s->budget--) { s->failed_pc=0x0c074bc0u; return 0; }
r[4]=r[8];
goto P_0c074bc2;
P_0c074bc2: /* original 7401, guest PC 0x0c074bc2 */
if(!s->budget--) { s->failed_pc=0x0c074bc2u; return 0; }
r[4]+=0x00000001u;
goto P_0c074bc4;
P_0c074bc4: /* original d00b, guest PC 0x0c074bc4 */
if(!s->budget--) { s->failed_pc=0x0c074bc4u; return 0; }
r[0]=read(ram,0x0c074bf4u,4);
goto P_0c074bc6;
P_0c074bc6: /* original 6e43, guest PC 0x0c074bc6 */
if(!s->budget--) { s->failed_pc=0x0c074bc6u; return 0; }
r[14]=r[4];
goto P_0c074bc8;
P_0c074bc8: /* original 4e08, guest PC 0x0c074bc8 */
if(!s->budget--) { s->failed_pc=0x0c074bc8u; return 0; }
r[14]<<=2;
goto P_0c074bca;
P_0c074bca: /* original a119, guest PC 0x0c074bca */
if(!s->budget--) { s->failed_pc=0x0c074bcau; return 0; }
r[14]=read(ram,r[14]+r[0],4);
goto P_0c074e00;
P_0c074bcc: /* original 0eee, guest PC 0x0c074bcc */
if(!s->budget--) { s->failed_pc=0x0c074bccu; return 0; }
r[14]=read(ram,r[14]+r[0],4);
return vf3_matrix_family(0x0c074bceu,s,ram);
P_0c074bf8: /* original 9061, guest PC 0x0c074bf8 */
if(!s->budget--) { s->failed_pc=0x0c074bf8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c074cbeu,2);
goto P_0c074bfa;
P_0c074bfa: /* original 0a4e, guest PC 0x0c074bfa */
if(!s->budget--) { s->failed_pc=0x0c074bfau; return 0; }
r[10]=read(ram,r[4]+r[0],4);
goto P_0c074bfc;
P_0c074bfc: /* original e061, guest PC 0x0c074bfc */
if(!s->budget--) { s->failed_pc=0x0c074bfcu; return 0; }
r[0]=0x00000061u;
goto P_0c074bfe;
P_0c074bfe: /* original 035c, guest PC 0x0c074bfe */
if(!s->budget--) { s->failed_pc=0x0c074bfeu; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[5]+r[0],1);
goto P_0c074c00;
P_0c074c00: /* original 66ac, guest PC 0x0c074c00 */
if(!s->budget--) { s->failed_pc=0x0c074c00u; return 0; }
r[6]=r[10]&255u;
goto P_0c074c02;
P_0c074c02: /* original 633c, guest PC 0x0c074c02 */
if(!s->budget--) { s->failed_pc=0x0c074c02u; return 0; }
r[3]=r[3]&255u;
goto P_0c074c04;
P_0c074c04: /* original 6e63, guest PC 0x0c074c04 */
if(!s->budget--) { s->failed_pc=0x0c074c04u; return 0; }
r[14]=r[6];
goto P_0c074c06;
P_0c074c06: /* original 6033, guest PC 0x0c074c06 */
if(!s->budget--) { s->failed_pc=0x0c074c06u; return 0; }
r[0]=r[3];
goto P_0c074c08;
P_0c074c08: /* original 880c, guest PC 0x0c074c08 */
if(!s->budget--) { s->failed_pc=0x0c074c08u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000cu)!=0);
goto P_0c074c0a;
P_0c074c0a: /* original 2f32, guest PC 0x0c074c0a */
if(!s->budget--) { s->failed_pc=0x0c074c0au; return 0; }
write(ram,r[15],r[3],4);
goto P_0c074c0c;
P_0c074c0c: /* original 8f03, guest PC 0x0c074c0c */
if(!s->budget--) { s->failed_pc=0x0c074c0cu; return 0; }
cond=r[17]&1u;
r[14]<<=2;
if(!cond) { goto P_0c074c16; }
goto P_0c074c10;
P_0c074c0e: /* original 4e08, guest PC 0x0c074c0e */
if(!s->budget--) { s->failed_pc=0x0c074c0eu; return 0; }
r[14]<<=2;
goto P_0c074c10;
P_0c074c10: /* original d02b, guest PC 0x0c074c10 */
if(!s->budget--) { s->failed_pc=0x0c074c10u; return 0; }
r[0]=read(ram,0x0c074cc0u,4);
goto P_0c074c12;
P_0c074c12: /* original a001, guest PC 0x0c074c12 */
if(!s->budget--) { s->failed_pc=0x0c074c12u; return 0; }
goto P_0c074c18;
P_0c074c14: /* original 0009, guest PC 0x0c074c14 */
if(!s->budget--) { s->failed_pc=0x0c074c14u; return 0; }
goto P_0c074c16;
P_0c074c16: /* original d02b, guest PC 0x0c074c16 */
if(!s->budget--) { s->failed_pc=0x0c074c16u; return 0; }
r[0]=read(ram,0x0c074cc4u,4);
goto P_0c074c18;
P_0c074c18: /* original 02ee, guest PC 0x0c074c18 */
if(!s->budget--) { s->failed_pc=0x0c074c18u; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c074c1a;
P_0c074c1a: /* original 6073, guest PC 0x0c074c1a */
if(!s->budget--) { s->failed_pc=0x0c074c1au; return 0; }
r[0]=r[7];
goto P_0c074c1c;
P_0c074c1c: /* original 8805, guest PC 0x0c074c1c */
if(!s->budget--) { s->failed_pc=0x0c074c1cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000005u)!=0);
goto P_0c074c1e;
P_0c074c1e: /* original 8f06, guest PC 0x0c074c1e */
if(!s->budget--) { s->failed_pc=0x0c074c1eu; return 0; }
cond=r[17]&1u;
write(ram,r[15],r[2],4);
if(!cond) { goto P_0c074c2e; }
goto P_0c074c22;
P_0c074c20: /* original 2f22, guest PC 0x0c074c20 */
if(!s->budget--) { s->failed_pc=0x0c074c20u; return 0; }
write(ram,r[15],r[2],4);
goto P_0c074c22;
P_0c074c22: /* original d229, guest PC 0x0c074c22 */
if(!s->budget--) { s->failed_pc=0x0c074c22u; return 0; }
r[2]=read(ram,0x0c074cc8u,4);
goto P_0c074c24;
P_0c074c24: /* original 22d8, guest PC 0x0c074c24 */
if(!s->budget--) { s->failed_pc=0x0c074c24u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[13])==0)!=0);
goto P_0c074c26;
P_0c074c26: /* original 8d26, guest PC 0x0c074c26 */
if(!s->budget--) { s->failed_pc=0x0c074c26u; return 0; }
cond=r[17]&1u;
r[14]=0x00000028u;
if(cond) { goto P_0c074c76; }
goto P_0c074c2a;
P_0c074c28: /* original ee28, guest PC 0x0c074c28 */
if(!s->budget--) { s->failed_pc=0x0c074c28u; return 0; }
r[14]=0x00000028u;
goto P_0c074c2a;
P_0c074c2a: /* original a024, guest PC 0x0c074c2a */
if(!s->budget--) { s->failed_pc=0x0c074c2au; return 0; }
r[14]=0x0000002au;
goto P_0c074c76;
P_0c074c2c: /* original ee2a, guest PC 0x0c074c2c */
if(!s->budget--) { s->failed_pc=0x0c074c2cu; return 0; }
r[14]=0x0000002au;
goto P_0c074c2e;
P_0c074c2e: /* original 6073, guest PC 0x0c074c2e */
if(!s->budget--) { s->failed_pc=0x0c074c2eu; return 0; }
r[0]=r[7];
goto P_0c074c30;
P_0c074c30: /* original 8806, guest PC 0x0c074c30 */
if(!s->budget--) { s->failed_pc=0x0c074c30u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000006u)!=0);
goto P_0c074c32;
P_0c074c32: /* original 8f01, guest PC 0x0c074c32 */
if(!s->budget--) { s->failed_pc=0x0c074c32u; return 0; }
cond=r[17]&1u;
r[14]=r[8];
if(!cond) { goto P_0c074c38; }
goto P_0c074c36;
P_0c074c34: /* original 6e83, guest PC 0x0c074c34 */
if(!s->budget--) { s->failed_pc=0x0c074c34u; return 0; }
r[14]=r[8];
goto P_0c074c36;
P_0c074c36: /* original e702, guest PC 0x0c074c36 */
if(!s->budget--) { s->failed_pc=0x0c074c36u; return 0; }
r[7]=0x00000002u;
goto P_0c074c38;
P_0c074c38: /* original d224, guest PC 0x0c074c38 */
if(!s->budget--) { s->failed_pc=0x0c074c38u; return 0; }
r[2]=read(ram,0x0c074cccu,4);
goto P_0c074c3a;
P_0c074c3a: /* original 22d8, guest PC 0x0c074c3a */
if(!s->budget--) { s->failed_pc=0x0c074c3au; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[13])==0)!=0);
goto P_0c074c3c;
P_0c074c3c: /* original 8d01, guest PC 0x0c074c3c */
if(!s->budget--) { s->failed_pc=0x0c074c3cu; return 0; }
cond=r[17]&1u;
r[0]=r[10];
if(cond) { goto P_0c074c42; }
goto P_0c074c40;
P_0c074c3e: /* original 60a3, guest PC 0x0c074c3e */
if(!s->budget--) { s->failed_pc=0x0c074c3eu; return 0; }
r[0]=r[10];
goto P_0c074c40;
P_0c074c40: /* original ee04, guest PC 0x0c074c40 */
if(!s->budget--) { s->failed_pc=0x0c074c40u; return 0; }
r[14]=0x00000004u;
goto P_0c074c42;
P_0c074c42: /* original 6352, guest PC 0x0c074c42 */
if(!s->budget--) { s->failed_pc=0x0c074c42u; return 0; }
tmp=read(ram,r[5],4);
r[3]=tmp;
goto P_0c074c44;
P_0c074c44: /* original 4004, guest PC 0x0c074c44 */
if(!s->budget--) { s->failed_pc=0x0c074c44u; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]=(r[0]<<1)|(r[0]>>31);
goto P_0c074c46;
P_0c074c46: /* original 6642, guest PC 0x0c074c46 */
if(!s->budget--) { s->failed_pc=0x0c074c46u; return 0; }
tmp=read(ram,r[4],4);
r[6]=tmp;
goto P_0c074c48;
P_0c074c48: /* original c901, guest PC 0x0c074c48 */
if(!s->budget--) { s->failed_pc=0x0c074c48u; return 0; }
r[0]&=1u;
goto P_0c074c4a;
P_0c074c4a: /* original 6c03, guest PC 0x0c074c4a */
if(!s->budget--) { s->failed_pc=0x0c074c4au; return 0; }
r[12]=r[0];
goto P_0c074c4c;
P_0c074c4c: /* original e050, guest PC 0x0c074c4c */
if(!s->budget--) { s->failed_pc=0x0c074c4cu; return 0; }
r[0]=0x00000050u;
goto P_0c074c4e;
P_0c074c4e: /* original 263a, guest PC 0x0c074c4e */
if(!s->budget--) { s->failed_pc=0x0c074c4eu; return 0; }
r[6]^=r[3];
goto P_0c074c50;
P_0c074c50: /* original 035e, guest PC 0x0c074c50 */
if(!s->budget--) { s->failed_pc=0x0c074c50u; return 0; }
r[3]=read(ram,r[5]+r[0],4);
goto P_0c074c52;
P_0c074c52: /* original 4629, guest PC 0x0c074c52 */
if(!s->budget--) { s->failed_pc=0x0c074c52u; return 0; }
r[6]>>=16;
goto P_0c074c54;
P_0c074c54: /* original 4619, guest PC 0x0c074c54 */
if(!s->budget--) { s->failed_pc=0x0c074c54u; return 0; }
r[6]>>=8;
goto P_0c074c56;
P_0c074c56: /* original 4601, guest PC 0x0c074c56 */
if(!s->budget--) { s->failed_pc=0x0c074c56u; return 0; }
r[17]=(r[17]&~1u)|((r[6]&1)!=0);
r[6]>>=1;
goto P_0c074c58;
P_0c074c58: /* original 2c6a, guest PC 0x0c074c58 */
if(!s->budget--) { s->failed_pc=0x0c074c58u; return 0; }
r[12]^=r[6];
goto P_0c074c5a;
P_0c074c5a: /* original 66d3, guest PC 0x0c074c5a */
if(!s->budget--) { s->failed_pc=0x0c074c5au; return 0; }
r[6]=r[13];
goto P_0c074c5c;
P_0c074c5c: /* original 4619, guest PC 0x0c074c5c */
if(!s->budget--) { s->failed_pc=0x0c074c5cu; return 0; }
r[6]>>=8;
goto P_0c074c5e;
P_0c074c5e: /* original 4609, guest PC 0x0c074c5e */
if(!s->budget--) { s->failed_pc=0x0c074c5eu; return 0; }
r[6]>>=2;
goto P_0c074c60;
P_0c074c60: /* original 2c6a, guest PC 0x0c074c60 */
if(!s->budget--) { s->failed_pc=0x0c074c60u; return 0; }
r[12]^=r[6];
goto P_0c074c62;
P_0c074c62: /* original e201, guest PC 0x0c074c62 */
if(!s->budget--) { s->failed_pc=0x0c074c62u; return 0; }
r[2]=0x00000001u;
goto P_0c074c64;
P_0c074c64: /* original 23b8, guest PC 0x0c074c64 */
if(!s->budget--) { s->failed_pc=0x0c074c64u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[11])==0)!=0);
goto P_0c074c66;
P_0c074c66: /* original 2c29, guest PC 0x0c074c66 */
if(!s->budget--) { s->failed_pc=0x0c074c66u; return 0; }
r[12]&=r[2];
goto P_0c074c68;
P_0c074c68: /* original 8d01, guest PC 0x0c074c68 */
if(!s->budget--) { s->failed_pc=0x0c074c68u; return 0; }
cond=r[17]&1u;
r[14]+=r[12];
if(cond) { goto P_0c074c6e; }
goto P_0c074c6c;
P_0c074c6a: /* original 3ecc, guest PC 0x0c074c6a */
if(!s->budget--) { s->failed_pc=0x0c074c6au; return 0; }
r[14]+=r[12];
goto P_0c074c6c;
P_0c074c6c: /* original 7e02, guest PC 0x0c074c6c */
if(!s->budget--) { s->failed_pc=0x0c074c6cu; return 0; }
r[14]+=0x00000002u;
goto P_0c074c6e;
P_0c074c6e: /* original 6673, guest PC 0x0c074c6e */
if(!s->budget--) { s->failed_pc=0x0c074c6eu; return 0; }
r[6]=r[7];
goto P_0c074c70;
P_0c074c70: /* original 4608, guest PC 0x0c074c70 */
if(!s->budget--) { s->failed_pc=0x0c074c70u; return 0; }
r[6]<<=2;
goto P_0c074c72;
P_0c074c72: /* original 4600, guest PC 0x0c074c72 */
if(!s->budget--) { s->failed_pc=0x0c074c72u; return 0; }
r[17]=(r[17]&~1u)|((r[6]>>31)!=0);
r[6]<<=1;
goto P_0c074c74;
P_0c074c74: /* original 3e6c, guest PC 0x0c074c74 */
if(!s->budget--) { s->failed_pc=0x0c074c74u; return 0; }
r[14]+=r[6];
goto P_0c074c76;
P_0c074c76: /* original e340, guest PC 0x0c074c76 */
if(!s->budget--) { s->failed_pc=0x0c074c76u; return 0; }
r[3]=0x00000040u;
goto P_0c074c78;
P_0c074c78: /* original 66e3, guest PC 0x0c074c78 */
if(!s->budget--) { s->failed_pc=0x0c074c78u; return 0; }
r[6]=r[14];
goto P_0c074c7a;
P_0c074c7a: /* original 23d8, guest PC 0x0c074c7a */
if(!s->budget--) { s->failed_pc=0x0c074c7au; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[13])==0)!=0);
goto P_0c074c7c;
P_0c074c7c: /* original 8d03, guest PC 0x0c074c7c */
if(!s->budget--) { s->failed_pc=0x0c074c7cu; return 0; }
cond=r[17]&1u;
r[6]<<=2;
if(cond) { goto P_0c074c86; }
goto P_0c074c80;
P_0c074c7e: /* original 4608, guest PC 0x0c074c7e */
if(!s->budget--) { s->failed_pc=0x0c074c7eu; return 0; }
r[6]<<=2;
goto P_0c074c80;
P_0c074c80: /* original d013, guest PC 0x0c074c80 */
if(!s->budget--) { s->failed_pc=0x0c074c80u; return 0; }
r[0]=read(ram,0x0c074cd0u,4);
goto P_0c074c82;
P_0c074c82: /* original a0bd, guest PC 0x0c074c82 */
if(!s->budget--) { s->failed_pc=0x0c074c82u; return 0; }
r[14]=read(ram,r[6]+r[0],4);
goto P_0c074e00;
P_0c074c84: /* original 0e6e, guest PC 0x0c074c84 */
if(!s->budget--) { s->failed_pc=0x0c074c84u; return 0; }
r[14]=read(ram,r[6]+r[0],4);
goto P_0c074c86;
P_0c074c86: /* original 60f2, guest PC 0x0c074c86 */
if(!s->budget--) { s->failed_pc=0x0c074c86u; return 0; }
tmp=read(ram,r[15],4);
r[0]=tmp;
goto P_0c074c88;
P_0c074c88: /* original 0e6e, guest PC 0x0c074c88 */
if(!s->budget--) { s->failed_pc=0x0c074c88u; return 0; }
r[14]=read(ram,r[6]+r[0],4);
goto P_0c074c8a;
P_0c074c8a: /* original 6073, guest PC 0x0c074c8a */
if(!s->budget--) { s->failed_pc=0x0c074c8au; return 0; }
r[0]=r[7];
goto P_0c074c8c;
P_0c074c8c: /* original 8805, guest PC 0x0c074c8c */
if(!s->budget--) { s->failed_pc=0x0c074c8cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000005u)!=0);
goto P_0c074c8e;
P_0c074c8e: /* original 8b04, guest PC 0x0c074c8e */
if(!s->budget--) { s->failed_pc=0x0c074c8eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c074c9a; }
goto P_0c074c90;
P_0c074c90: /* original 67e3, guest PC 0x0c074c90 */
if(!s->budget--) { s->failed_pc=0x0c074c90u; return 0; }
r[7]=r[14];
goto P_0c074c92;
P_0c074c92: /* original bef6, guest PC 0x0c074c92 */
if(!s->budget--) { s->failed_pc=0x0c074c92u; return 0; }
target=0x0c074a82u; r[16]=0x0c074c96u;
r[6]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c074c96u) { target=s->pc; goto dispatch; }
goto P_0c074c96;
P_0c074c94: /* original 66d3, guest PC 0x0c074c94 */
if(!s->budget--) { s->failed_pc=0x0c074c94u; return 0; }
r[6]=r[13];
goto P_0c074c96;
P_0c074c96: /* original a0b3, guest PC 0x0c074c96 */
if(!s->budget--) { s->failed_pc=0x0c074c96u; return 0; }
r[14]=r[0];
goto P_0c074e00;
P_0c074c98: /* original 6e03, guest PC 0x0c074c98 */
if(!s->budget--) { s->failed_pc=0x0c074c98u; return 0; }
r[14]=r[0];
goto P_0c074c9a;
P_0c074c9a: /* original 8804, guest PC 0x0c074c9a */
if(!s->budget--) { s->failed_pc=0x0c074c9au; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000004u)!=0);
goto P_0c074c9c;
P_0c074c9c: /* original 8b08, guest PC 0x0c074c9c */
if(!s->budget--) { s->failed_pc=0x0c074c9cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c074cb0; }
goto P_0c074c9e;
P_0c074c9e: /* original e050, guest PC 0x0c074c9e */
if(!s->budget--) { s->failed_pc=0x0c074c9eu; return 0; }
r[0]=0x00000050u;
goto P_0c074ca0;
P_0c074ca0: /* original 025e, guest PC 0x0c074ca0 */
if(!s->budget--) { s->failed_pc=0x0c074ca0u; return 0; }
r[2]=read(ram,r[5]+r[0],4);
goto P_0c074ca2;
P_0c074ca2: /* original 2b28, guest PC 0x0c074ca2 */
if(!s->budget--) { s->failed_pc=0x0c074ca2u; return 0; }
r[17]=(r[17]&~1u)|(((r[11]&r[2])==0)!=0);
goto P_0c074ca4;
P_0c074ca4: /* original 8904, guest PC 0x0c074ca4 */
if(!s->budget--) { s->failed_pc=0x0c074ca4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c074cb0; }
goto P_0c074ca6;
P_0c074ca6: /* original 67e3, guest PC 0x0c074ca6 */
if(!s->budget--) { s->failed_pc=0x0c074ca6u; return 0; }
r[7]=r[14];
goto P_0c074ca8;
P_0c074ca8: /* original bf1e, guest PC 0x0c074ca8 */
if(!s->budget--) { s->failed_pc=0x0c074ca8u; return 0; }
target=0x0c074ae8u; r[16]=0x0c074cacu;
r[6]=r[10];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c074cacu) { target=s->pc; goto dispatch; }
goto P_0c074cac;
P_0c074caa: /* original 66a3, guest PC 0x0c074caa */
if(!s->budget--) { s->failed_pc=0x0c074caau; return 0; }
r[6]=r[10];
goto P_0c074cac;
P_0c074cac: /* original aff3, guest PC 0x0c074cac */
if(!s->budget--) { s->failed_pc=0x0c074cacu; return 0; }
goto P_0c074c96;
P_0c074cae: /* original 0009, guest PC 0x0c074cae */
if(!s->budget--) { s->failed_pc=0x0c074caeu; return 0; }
goto P_0c074cb0;
P_0c074cb0: /* original 2778, guest PC 0x0c074cb0 */
if(!s->budget--) { s->failed_pc=0x0c074cb0u; return 0; }
r[17]=(r[17]&~1u)|(((r[7]&r[7])==0)!=0);
goto P_0c074cb2;
P_0c074cb2: /* original 8b0f, guest PC 0x0c074cb2 */
if(!s->budget--) { s->failed_pc=0x0c074cb2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c074cd4; }
goto P_0c074cb4;
P_0c074cb4: /* original 67a3, guest PC 0x0c074cb4 */
if(!s->budget--) { s->failed_pc=0x0c074cb4u; return 0; }
r[7]=r[10];
goto P_0c074cb6;
P_0c074cb6: /* original be3b, guest PC 0x0c074cb6 */
if(!s->budget--) { s->failed_pc=0x0c074cb6u; return 0; }
target=0x0c074930u; r[16]=0x0c074cbau;
r[6]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c074cbau) { target=s->pc; goto dispatch; }
goto P_0c074cba;
P_0c074cb8: /* original 66e3, guest PC 0x0c074cb8 */
if(!s->budget--) { s->failed_pc=0x0c074cb8u; return 0; }
r[6]=r[14];
goto P_0c074cba;
P_0c074cba: /* original afec, guest PC 0x0c074cba */
if(!s->budget--) { s->failed_pc=0x0c074cbau; return 0; }
goto P_0c074c96;
P_0c074cbc: /* original 0009, guest PC 0x0c074cbc */
if(!s->budget--) { s->failed_pc=0x0c074cbcu; return 0; }
return vf3_matrix_family(0x0c074cbeu,s,ram);
P_0c074cd4: /* original 915d, guest PC 0x0c074cd4 */
if(!s->budget--) { s->failed_pc=0x0c074cd4u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c074d92u,2);
goto P_0c074cd6;
P_0c074cd6: /* original 60e3, guest PC 0x0c074cd6 */
if(!s->budget--) { s->failed_pc=0x0c074cd6u; return 0; }
r[0]=r[14];
goto P_0c074cd8;
P_0c074cd8: /* original 3010, guest PC 0x0c074cd8 */
if(!s->budget--) { s->failed_pc=0x0c074cd8u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==r[1])!=0);
goto P_0c074cda;
P_0c074cda: /* original 891b, guest PC 0x0c074cda */
if(!s->budget--) { s->failed_pc=0x0c074cdau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c074d14; }
goto P_0c074cdc;
P_0c074cdc: /* original 915a, guest PC 0x0c074cdc */
if(!s->budget--) { s->failed_pc=0x0c074cdcu; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c074d94u,2);
goto P_0c074cde;
P_0c074cde: /* original 3010, guest PC 0x0c074cde */
if(!s->budget--) { s->failed_pc=0x0c074cdeu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==r[1])!=0);
goto P_0c074ce0;
P_0c074ce0: /* original 891c, guest PC 0x0c074ce0 */
if(!s->budget--) { s->failed_pc=0x0c074ce0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c074d1c; }
goto P_0c074ce2;
P_0c074ce2: /* original 9158, guest PC 0x0c074ce2 */
if(!s->budget--) { s->failed_pc=0x0c074ce2u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c074d96u,2);
goto P_0c074ce4;
P_0c074ce4: /* original 3010, guest PC 0x0c074ce4 */
if(!s->budget--) { s->failed_pc=0x0c074ce4u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==r[1])!=0);
goto P_0c074ce6;
P_0c074ce6: /* original 8911, guest PC 0x0c074ce6 */
if(!s->budget--) { s->failed_pc=0x0c074ce6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c074d0c; }
goto P_0c074ce8;
P_0c074ce8: /* original 9156, guest PC 0x0c074ce8 */
if(!s->budget--) { s->failed_pc=0x0c074ce8u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c074d98u,2);
goto P_0c074cea;
P_0c074cea: /* original 3010, guest PC 0x0c074cea */
if(!s->budget--) { s->failed_pc=0x0c074ceau; return 0; }
r[17]=(r[17]&~1u)|((r[0]==r[1])!=0);
goto P_0c074cec;
P_0c074cec: /* original 8b01, guest PC 0x0c074cec */
if(!s->budget--) { s->failed_pc=0x0c074cecu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c074cf2; }
goto P_0c074cee;
P_0c074cee: /* original a087, guest PC 0x0c074cee */
if(!s->budget--) { s->failed_pc=0x0c074ceeu; return 0; }
goto P_0c074e00;
P_0c074cf0: /* original 0009, guest PC 0x0c074cf0 */
if(!s->budget--) { s->failed_pc=0x0c074cf0u; return 0; }
goto P_0c074cf2;
P_0c074cf2: /* original 9152, guest PC 0x0c074cf2 */
if(!s->budget--) { s->failed_pc=0x0c074cf2u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c074d9au,2);
goto P_0c074cf4;
P_0c074cf4: /* original 3010, guest PC 0x0c074cf4 */
if(!s->budget--) { s->failed_pc=0x0c074cf4u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==r[1])!=0);
goto P_0c074cf6;
P_0c074cf6: /* original 890d, guest PC 0x0c074cf6 */
if(!s->budget--) { s->failed_pc=0x0c074cf6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c074d14; }
goto P_0c074cf8;
P_0c074cf8: /* original 9150, guest PC 0x0c074cf8 */
if(!s->budget--) { s->failed_pc=0x0c074cf8u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c074d9cu,2);
goto P_0c074cfa;
P_0c074cfa: /* original 3010, guest PC 0x0c074cfa */
if(!s->budget--) { s->failed_pc=0x0c074cfau; return 0; }
r[17]=(r[17]&~1u)|((r[0]==r[1])!=0);
goto P_0c074cfc;
P_0c074cfc: /* original 8906, guest PC 0x0c074cfc */
if(!s->budget--) { s->failed_pc=0x0c074cfcu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c074d0c; }
goto P_0c074cfe;
P_0c074cfe: /* original 914e, guest PC 0x0c074cfe */
if(!s->budget--) { s->failed_pc=0x0c074cfeu; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c074d9eu,2);
goto P_0c074d00;
P_0c074d00: /* original 3010, guest PC 0x0c074d00 */
if(!s->budget--) { s->failed_pc=0x0c074d00u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==r[1])!=0);
goto P_0c074d02;
P_0c074d02: /* original 8b01, guest PC 0x0c074d02 */
if(!s->budget--) { s->failed_pc=0x0c074d02u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c074d08; }
goto P_0c074d04;
P_0c074d04: /* original a07c, guest PC 0x0c074d04 */
if(!s->budget--) { s->failed_pc=0x0c074d04u; return 0; }
goto P_0c074e00;
P_0c074d06: /* original 0009, guest PC 0x0c074d06 */
if(!s->budget--) { s->failed_pc=0x0c074d06u; return 0; }
goto P_0c074d08;
P_0c074d08: /* original a00c, guest PC 0x0c074d08 */
if(!s->budget--) { s->failed_pc=0x0c074d08u; return 0; }
goto P_0c074d24;
P_0c074d0a: /* original 0009, guest PC 0x0c074d0a */
if(!s->budget--) { s->failed_pc=0x0c074d0au; return 0; }
goto P_0c074d0c;
P_0c074d0c: /* original bead, guest PC 0x0c074d0c */
if(!s->budget--) { s->failed_pc=0x0c074d0cu; return 0; }
target=0x0c074a6au; r[16]=0x0c074d10u;
r[6]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c074d10u) { target=s->pc; goto dispatch; }
goto P_0c074d10;
P_0c074d0e: /* original 66e3, guest PC 0x0c074d0e */
if(!s->budget--) { s->failed_pc=0x0c074d0eu; return 0; }
r[6]=r[14];
goto P_0c074d10;
P_0c074d10: /* original afc1, guest PC 0x0c074d10 */
if(!s->budget--) { s->failed_pc=0x0c074d10u; return 0; }
goto P_0c074c96;
P_0c074d12: /* original 0009, guest PC 0x0c074d12 */
if(!s->budget--) { s->failed_pc=0x0c074d12u; return 0; }
goto P_0c074d14;
P_0c074d14: /* original be91, guest PC 0x0c074d14 */
if(!s->budget--) { s->failed_pc=0x0c074d14u; return 0; }
target=0x0c074a3au; r[16]=0x0c074d18u;
r[6]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c074d18u) { target=s->pc; goto dispatch; }
goto P_0c074d18;
P_0c074d16: /* original 66e3, guest PC 0x0c074d16 */
if(!s->budget--) { s->failed_pc=0x0c074d16u; return 0; }
r[6]=r[14];
goto P_0c074d18;
P_0c074d18: /* original afbd, guest PC 0x0c074d18 */
if(!s->budget--) { s->failed_pc=0x0c074d18u; return 0; }
goto P_0c074c96;
P_0c074d1a: /* original 0009, guest PC 0x0c074d1a */
if(!s->budget--) { s->failed_pc=0x0c074d1au; return 0; }
goto P_0c074d1c;
P_0c074d1c: /* original be99, guest PC 0x0c074d1c */
if(!s->budget--) { s->failed_pc=0x0c074d1cu; return 0; }
target=0x0c074a52u; r[16]=0x0c074d20u;
r[6]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c074d20u) { target=s->pc; goto dispatch; }
goto P_0c074d20;
P_0c074d1e: /* original 66e3, guest PC 0x0c074d1e */
if(!s->budget--) { s->failed_pc=0x0c074d1eu; return 0; }
r[6]=r[14];
goto P_0c074d20;
P_0c074d20: /* original afb9, guest PC 0x0c074d20 */
if(!s->budget--) { s->failed_pc=0x0c074d20u; return 0; }
goto P_0c074c96;
P_0c074d22: /* original 0009, guest PC 0x0c074d22 */
if(!s->budget--) { s->failed_pc=0x0c074d22u; return 0; }
goto P_0c074d24;
P_0c074d24: /* original e061, guest PC 0x0c074d24 */
if(!s->budget--) { s->failed_pc=0x0c074d24u; return 0; }
r[0]=0x00000061u;
goto P_0c074d26;
P_0c074d26: /* original 065c, guest PC 0x0c074d26 */
if(!s->budget--) { s->failed_pc=0x0c074d26u; return 0; }
r[6]=(uint32_t)(int32_t)(int8_t)read(ram,r[5]+r[0],1);
goto P_0c074d28;
P_0c074d28: /* original 606c, guest PC 0x0c074d28 */
if(!s->budget--) { s->failed_pc=0x0c074d28u; return 0; }
r[0]=r[6]&255u;
goto P_0c074d2a;
P_0c074d2a: /* original 880b, guest PC 0x0c074d2a */
if(!s->budget--) { s->failed_pc=0x0c074d2au; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000bu)!=0);
goto P_0c074d2c;
P_0c074d2c: /* original 8f0e, guest PC 0x0c074d2c */
if(!s->budget--) { s->failed_pc=0x0c074d2cu; return 0; }
cond=r[17]&1u;
r[6]=r[0];
if(!cond) { goto P_0c074d4c; }
goto P_0c074d30;
P_0c074d2e: /* original 6603, guest PC 0x0c074d2e */
if(!s->budget--) { s->failed_pc=0x0c074d2eu; return 0; }
r[6]=r[0];
goto P_0c074d30;
P_0c074d30: /* original 9236, guest PC 0x0c074d30 */
if(!s->budget--) { s->failed_pc=0x0c074d30u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c074da0u,2);
goto P_0c074d32;
P_0c074d32: /* original 3e20, guest PC 0x0c074d32 */
if(!s->budget--) { s->failed_pc=0x0c074d32u; return 0; }
r[17]=(r[17]&~1u)|((r[14]==r[2])!=0);
goto P_0c074d34;
P_0c074d34: /* original 8b03, guest PC 0x0c074d34 */
if(!s->budget--) { s->failed_pc=0x0c074d34u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c074d3e; }
goto P_0c074d36;
P_0c074d36: /* original be7a, guest PC 0x0c074d36 */
if(!s->budget--) { s->failed_pc=0x0c074d36u; return 0; }
target=0x0c074a2eu; r[16]=0x0c074d3au;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c074d3au) { target=s->pc; goto dispatch; }
goto P_0c074d3a;
P_0c074d38: /* original 0009, guest PC 0x0c074d38 */
if(!s->budget--) { s->failed_pc=0x0c074d38u; return 0; }
goto P_0c074d3a;
P_0c074d3a: /* original a061, guest PC 0x0c074d3a */
if(!s->budget--) { s->failed_pc=0x0c074d3au; return 0; }
r[14]=r[0];
goto P_0c074e00;
P_0c074d3c: /* original 6e03, guest PC 0x0c074d3c */
if(!s->budget--) { s->failed_pc=0x0c074d3cu; return 0; }
r[14]=r[0];
goto P_0c074d3e;
P_0c074d3e: /* original 9130, guest PC 0x0c074d3e */
if(!s->budget--) { s->failed_pc=0x0c074d3eu; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c074da2u,2);
goto P_0c074d40;
P_0c074d40: /* original 3e10, guest PC 0x0c074d40 */
if(!s->budget--) { s->failed_pc=0x0c074d40u; return 0; }
r[17]=(r[17]&~1u)|((r[14]==r[1])!=0);
goto P_0c074d42;
P_0c074d42: /* original 8b03, guest PC 0x0c074d42 */
if(!s->budget--) { s->failed_pc=0x0c074d42u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c074d4c; }
goto P_0c074d44;
P_0c074d44: /* original be76, guest PC 0x0c074d44 */
if(!s->budget--) { s->failed_pc=0x0c074d44u; return 0; }
target=0x0c074a34u; r[16]=0x0c074d48u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c074d48u) { target=s->pc; goto dispatch; }
goto P_0c074d48;
P_0c074d46: /* original 0009, guest PC 0x0c074d46 */
if(!s->budget--) { s->failed_pc=0x0c074d46u; return 0; }
goto P_0c074d48;
P_0c074d48: /* original a05a, guest PC 0x0c074d48 */
if(!s->budget--) { s->failed_pc=0x0c074d48u; return 0; }
r[14]=r[0];
goto P_0c074e00;
P_0c074d4a: /* original 6e03, guest PC 0x0c074d4a */
if(!s->budget--) { s->failed_pc=0x0c074d4au; return 0; }
r[14]=r[0];
goto P_0c074d4c;
P_0c074d4c: /* original e061, guest PC 0x0c074d4c */
if(!s->budget--) { s->failed_pc=0x0c074d4cu; return 0; }
r[0]=0x00000061u;
goto P_0c074d4e;
P_0c074d4e: /* original 065c, guest PC 0x0c074d4e */
if(!s->budget--) { s->failed_pc=0x0c074d4eu; return 0; }
r[6]=(uint32_t)(int32_t)(int8_t)read(ram,r[5]+r[0],1);
goto P_0c074d50;
P_0c074d50: /* original 606c, guest PC 0x0c074d50 */
if(!s->budget--) { s->failed_pc=0x0c074d50u; return 0; }
r[0]=r[6]&255u;
goto P_0c074d52;
P_0c074d52: /* original 880c, guest PC 0x0c074d52 */
if(!s->budget--) { s->failed_pc=0x0c074d52u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000cu)!=0);
goto P_0c074d54;
P_0c074d54: /* original 8d54, guest PC 0x0c074d54 */
if(!s->budget--) { s->failed_pc=0x0c074d54u; return 0; }
cond=r[17]&1u;
r[6]=r[0];
if(cond) { goto P_0c074e00; }
goto P_0c074d58;
P_0c074d56: /* original 6603, guest PC 0x0c074d56 */
if(!s->budget--) { s->failed_pc=0x0c074d56u; return 0; }
r[6]=r[0];
goto P_0c074d58;
P_0c074d58: /* original 6073, guest PC 0x0c074d58 */
if(!s->budget--) { s->failed_pc=0x0c074d58u; return 0; }
r[0]=r[7];
goto P_0c074d5a;
P_0c074d5a: /* original 8802, guest PC 0x0c074d5a */
if(!s->budget--) { s->failed_pc=0x0c074d5au; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c074d5c;
P_0c074d5c: /* original 8b50, guest PC 0x0c074d5c */
if(!s->budget--) { s->failed_pc=0x0c074d5cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c074e00; }
goto P_0c074d5e;
P_0c074d5e: /* original d313, guest PC 0x0c074d5e */
if(!s->budget--) { s->failed_pc=0x0c074d5eu; return 0; }
r[3]=read(ram,0x0c074dacu,4);
goto P_0c074d60;
P_0c074d60: /* original 23d8, guest PC 0x0c074d60 */
if(!s->budget--) { s->failed_pc=0x0c074d60u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[13])==0)!=0);
goto P_0c074d62;
P_0c074d62: /* original 8b4d, guest PC 0x0c074d62 */
if(!s->budget--) { s->failed_pc=0x0c074d62u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c074e00; }
goto P_0c074d64;
P_0c074d64: /* original e3f1, guest PC 0x0c074d64 */
if(!s->budget--) { s->failed_pc=0x0c074d64u; return 0; }
r[3]=0xfffffff1u;
goto P_0c074d66;
P_0c074d66: /* original e601, guest PC 0x0c074d66 */
if(!s->budget--) { s->failed_pc=0x0c074d66u; return 0; }
r[6]=0x00000001u;
goto P_0c074d68;
P_0c074d68: /* original 4c3d, guest PC 0x0c074d68 */
if(!s->budget--) { s->failed_pc=0x0c074d68u; return 0; }
r[12]=(r[3]&0x80000000u)?((r[3]&31u)?r[12]>>((-r[3])&31u):0):r[12]<<(r[3]&31u);
goto P_0c074d6a;
P_0c074d6a: /* original 26c9, guest PC 0x0c074d6a */
if(!s->budget--) { s->failed_pc=0x0c074d6au; return 0; }
r[6]&=r[12];
goto P_0c074d6c;
P_0c074d6c: /* original 2668, guest PC 0x0c074d6c */
if(!s->budget--) { s->failed_pc=0x0c074d6cu; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[6])==0)!=0);
goto P_0c074d6e;
P_0c074d6e: /* original 8947, guest PC 0x0c074d6e */
if(!s->budget--) { s->failed_pc=0x0c074d6eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c074e00; }
goto P_0c074d70;
P_0c074d70: /* original e06a, guest PC 0x0c074d70 */
if(!s->budget--) { s->failed_pc=0x0c074d70u; return 0; }
r[0]=0x0000006au;
goto P_0c074d72;
P_0c074d72: /* original 9318, guest PC 0x0c074d72 */
if(!s->budget--) { s->failed_pc=0x0c074d72u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c074da6u,2);
goto P_0c074d74;
P_0c074d74: /* original 065d, guest PC 0x0c074d74 */
if(!s->budget--) { s->failed_pc=0x0c074d74u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,r[5]+r[0],2);
goto P_0c074d76;
P_0c074d76: /* original 9015, guest PC 0x0c074d76 */
if(!s->budget--) { s->failed_pc=0x0c074d76u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c074da4u,2);
goto P_0c074d78;
P_0c074d78: /* original 075d, guest PC 0x0c074d78 */
if(!s->budget--) { s->failed_pc=0x0c074d78u; return 0; }
r[7]=(uint32_t)(int32_t)(int16_t)read(ram,r[5]+r[0],2);
goto P_0c074d7a;
P_0c074d7a: /* original 3768, guest PC 0x0c074d7a */
if(!s->budget--) { s->failed_pc=0x0c074d7au; return 0; }
r[7]-=r[6];
goto P_0c074d7c;
P_0c074d7c: /* original 667f, guest PC 0x0c074d7c */
if(!s->budget--) { s->failed_pc=0x0c074d7cu; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)r[7];
goto P_0c074d7e;
P_0c074d7e: /* original 3637, guest PC 0x0c074d7e */
if(!s->budget--) { s->failed_pc=0x0c074d7eu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[6]>(int32_t)r[3])!=0);
goto P_0c074d80;
P_0c074d80: /* original 8916, guest PC 0x0c074d80 */
if(!s->budget--) { s->failed_pc=0x0c074d80u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c074db0; }
goto P_0c074d82;
P_0c074d82: /* original 9211, guest PC 0x0c074d82 */
if(!s->budget--) { s->failed_pc=0x0c074d82u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c074da8u,2);
goto P_0c074d84;
P_0c074d84: /* original 3623, guest PC 0x0c074d84 */
if(!s->budget--) { s->failed_pc=0x0c074d84u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[6]>=(int32_t)r[2])!=0);
goto P_0c074d86;
P_0c074d86: /* original 893b, guest PC 0x0c074d86 */
if(!s->budget--) { s->failed_pc=0x0c074d86u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c074e00; }
goto P_0c074d88;
P_0c074d88: /* original 6352, guest PC 0x0c074d88 */
if(!s->budget--) { s->failed_pc=0x0c074d88u; return 0; }
tmp=read(ram,r[5],4);
r[3]=tmp;
goto P_0c074d8a;
P_0c074d8a: /* original 2938, guest PC 0x0c074d8a */
if(!s->budget--) { s->failed_pc=0x0c074d8au; return 0; }
r[17]=(r[17]&~1u)|(((r[9]&r[3])==0)!=0);
goto P_0c074d8c;
P_0c074d8c: /* original 8b13, guest PC 0x0c074d8c */
if(!s->budget--) { s->failed_pc=0x0c074d8cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c074db6; }
goto P_0c074d8e;
P_0c074d8e: /* original a013, guest PC 0x0c074d8e */
if(!s->budget--) { s->failed_pc=0x0c074d8eu; return 0; }
r[5]=0x00000002u;
goto P_0c074db8;
P_0c074d90: /* original e502, guest PC 0x0c074d90 */
if(!s->budget--) { s->failed_pc=0x0c074d90u; return 0; }
r[5]=0x00000002u;
return vf3_matrix_family(0x0c074d92u,s,ram);
P_0c074db0: /* original 6252, guest PC 0x0c074db0 */
if(!s->budget--) { s->failed_pc=0x0c074db0u; return 0; }
tmp=read(ram,r[5],4);
r[2]=tmp;
goto P_0c074db2;
P_0c074db2: /* original 2928, guest PC 0x0c074db2 */
if(!s->budget--) { s->failed_pc=0x0c074db2u; return 0; }
r[17]=(r[17]&~1u)|(((r[9]&r[2])==0)!=0);
goto P_0c074db4;
P_0c074db4: /* original 8beb, guest PC 0x0c074db4 */
if(!s->budget--) { s->failed_pc=0x0c074db4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c074d8e; }
goto P_0c074db6;
P_0c074db6: /* original 6583, guest PC 0x0c074db6 */
if(!s->budget--) { s->failed_pc=0x0c074db6u; return 0; }
r[5]=r[8];
goto P_0c074db8;
P_0c074db8: /* original 9053, guest PC 0x0c074db8 */
if(!s->budget--) { s->failed_pc=0x0c074db8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c074e62u,2);
goto P_0c074dba;
P_0c074dba: /* original 064e, guest PC 0x0c074dba */
if(!s->budget--) { s->failed_pc=0x0c074dbau; return 0; }
r[6]=read(ram,r[4]+r[0],4);
goto P_0c074dbc;
P_0c074dbc: /* original 70fd, guest PC 0x0c074dbc */
if(!s->budget--) { s->failed_pc=0x0c074dbcu; return 0; }
r[0]+=0xfffffffdu;
goto P_0c074dbe;
P_0c074dbe: /* original 676c, guest PC 0x0c074dbe */
if(!s->budget--) { s->failed_pc=0x0c074dbeu; return 0; }
r[7]=r[6]&255u;
goto P_0c074dc0;
P_0c074dc0: /* original 064c, guest PC 0x0c074dc0 */
if(!s->budget--) { s->failed_pc=0x0c074dc0u; return 0; }
r[6]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c074dc2;
P_0c074dc2: /* original 606c, guest PC 0x0c074dc2 */
if(!s->budget--) { s->failed_pc=0x0c074dc2u; return 0; }
r[0]=r[6]&255u;
goto P_0c074dc4;
P_0c074dc4: /* original 8801, guest PC 0x0c074dc4 */
if(!s->budget--) { s->failed_pc=0x0c074dc4u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c074dc6;
P_0c074dc6: /* original 8d07, guest PC 0x0c074dc6 */
if(!s->budget--) { s->failed_pc=0x0c074dc6u; return 0; }
cond=r[17]&1u;
r[6]=r[0];
if(cond) { goto P_0c074dd8; }
goto P_0c074dca;
P_0c074dc8: /* original 6603, guest PC 0x0c074dc8 */
if(!s->budget--) { s->failed_pc=0x0c074dc8u; return 0; }
r[6]=r[0];
goto P_0c074dca;
P_0c074dca: /* original 2668, guest PC 0x0c074dca */
if(!s->budget--) { s->failed_pc=0x0c074dcau; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[6])==0)!=0);
goto P_0c074dcc;
P_0c074dcc: /* original 8b18, guest PC 0x0c074dcc */
if(!s->budget--) { s->failed_pc=0x0c074dccu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c074e00; }
goto P_0c074dce;
P_0c074dce: /* original 2778, guest PC 0x0c074dce */
if(!s->budget--) { s->failed_pc=0x0c074dceu; return 0; }
r[17]=(r[17]&~1u)|(((r[7]&r[7])==0)!=0);
goto P_0c074dd0;
P_0c074dd0: /* original 8b16, guest PC 0x0c074dd0 */
if(!s->budget--) { s->failed_pc=0x0c074dd0u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c074e00; }
goto P_0c074dd2;
P_0c074dd2: /* original d424, guest PC 0x0c074dd2 */
if(!s->budget--) { s->failed_pc=0x0c074dd2u; return 0; }
r[4]=read(ram,0x0c074e64u,4);
goto P_0c074dd4;
P_0c074dd4: /* original a00a, guest PC 0x0c074dd4 */
if(!s->budget--) { s->failed_pc=0x0c074dd4u; return 0; }
goto P_0c074dec;
P_0c074dd6: /* original 0009, guest PC 0x0c074dd6 */
if(!s->budget--) { s->failed_pc=0x0c074dd6u; return 0; }
goto P_0c074dd8;
P_0c074dd8: /* original 6073, guest PC 0x0c074dd8 */
if(!s->budget--) { s->failed_pc=0x0c074dd8u; return 0; }
r[0]=r[7];
goto P_0c074dda;
P_0c074dda: /* original 8806, guest PC 0x0c074dda */
if(!s->budget--) { s->failed_pc=0x0c074ddau; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000006u)!=0);
goto P_0c074ddc;
P_0c074ddc: /* original 8905, guest PC 0x0c074ddc */
if(!s->budget--) { s->failed_pc=0x0c074ddcu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c074dea; }
goto P_0c074dde;
P_0c074dde: /* original 880f, guest PC 0x0c074dde */
if(!s->budget--) { s->failed_pc=0x0c074ddeu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000fu)!=0);
goto P_0c074de0;
P_0c074de0: /* original 8903, guest PC 0x0c074de0 */
if(!s->budget--) { s->failed_pc=0x0c074de0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c074dea; }
goto P_0c074de2;
P_0c074de2: /* original 881b, guest PC 0x0c074de2 */
if(!s->budget--) { s->failed_pc=0x0c074de2u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000001bu)!=0);
goto P_0c074de4;
P_0c074de4: /* original 8901, guest PC 0x0c074de4 */
if(!s->budget--) { s->failed_pc=0x0c074de4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c074dea; }
goto P_0c074de6;
P_0c074de6: /* original a00b, guest PC 0x0c074de6 */
if(!s->budget--) { s->failed_pc=0x0c074de6u; return 0; }
goto P_0c074e00;
P_0c074de8: /* original 0009, guest PC 0x0c074de8 */
if(!s->budget--) { s->failed_pc=0x0c074de8u; return 0; }
goto P_0c074dea;
P_0c074dea: /* original d41f, guest PC 0x0c074dea */
if(!s->budget--) { s->failed_pc=0x0c074deau; return 0; }
r[4]=read(ram,0x0c074e68u,4);
goto P_0c074dec;
P_0c074dec: /* original 6643, guest PC 0x0c074dec */
if(!s->budget--) { s->failed_pc=0x0c074decu; return 0; }
r[6]=r[4];
goto P_0c074dee;
P_0c074dee: /* original 365c, guest PC 0x0c074dee */
if(!s->budget--) { s->failed_pc=0x0c074deeu; return 0; }
r[6]+=r[5];
goto P_0c074df0;
P_0c074df0: /* original 8461, guest PC 0x0c074df0 */
if(!s->budget--) { s->failed_pc=0x0c074df0u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[6]+1,1);
goto P_0c074df2;
P_0c074df2: /* original de1e, guest PC 0x0c074df2 */
if(!s->budget--) { s->failed_pc=0x0c074df2u; return 0; }
r[14]=read(ram,0x0c074e6cu,4);
goto P_0c074df4;
P_0c074df4: /* original 6360, guest PC 0x0c074df4 */
if(!s->budget--) { s->failed_pc=0x0c074df4u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[6],1);
r[3]=tmp;
goto P_0c074df6;
P_0c074df6: /* original 600c, guest PC 0x0c074df6 */
if(!s->budget--) { s->failed_pc=0x0c074df6u; return 0; }
r[0]=r[0]&255u;
goto P_0c074df8;
P_0c074df8: /* original 4018, guest PC 0x0c074df8 */
if(!s->budget--) { s->failed_pc=0x0c074df8u; return 0; }
r[0]<<=8;
goto P_0c074dfa;
P_0c074dfa: /* original 633c, guest PC 0x0c074dfa */
if(!s->budget--) { s->failed_pc=0x0c074dfau; return 0; }
r[3]=r[3]&255u;
goto P_0c074dfc;
P_0c074dfc: /* original 2e09, guest PC 0x0c074dfc */
if(!s->budget--) { s->failed_pc=0x0c074dfcu; return 0; }
r[14]&=r[0];
goto P_0c074dfe;
P_0c074dfe: /* original 2e3b, guest PC 0x0c074dfe */
if(!s->budget--) { s->failed_pc=0x0c074dfeu; return 0; }
r[14]|=r[3];
goto P_0c074e00;
P_0c074e00: /* original 52fb, guest PC 0x0c074e00 */
if(!s->budget--) { s->failed_pc=0x0c074e00u; return 0; }
r[2]=read(ram,r[15]+44,4);
goto P_0c074e02;
P_0c074e02: /* original 22d2, guest PC 0x0c074e02 */
if(!s->budget--) { s->failed_pc=0x0c074e02u; return 0; }
write(ram,r[2],r[13],4);
goto P_0c074e04;
P_0c074e04: /* original 53f1, guest PC 0x0c074e04 */
if(!s->budget--) { s->failed_pc=0x0c074e04u; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c074e06;
P_0c074e06: /* original 7f08, guest PC 0x0c074e06 */
if(!s->budget--) { s->failed_pc=0x0c074e06u; return 0; }
r[15]+=0x00000008u;
goto P_0c074e08;
P_0c074e08: /* original 4f26, guest PC 0x0c074e08 */
if(!s->budget--) { s->failed_pc=0x0c074e08u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c074e0a;
P_0c074e0a: /* original 23e2, guest PC 0x0c074e0a */
if(!s->budget--) { s->failed_pc=0x0c074e0au; return 0; }
write(ram,r[3],r[14],4);
goto P_0c074e0c;
P_0c074e0c: /* original 68f6, guest PC 0x0c074e0c */
if(!s->budget--) { s->failed_pc=0x0c074e0cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c074e0e;
P_0c074e0e: /* original 69f6, guest PC 0x0c074e0e */
if(!s->budget--) { s->failed_pc=0x0c074e0eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c074e10;
P_0c074e10: /* original 6af6, guest PC 0x0c074e10 */
if(!s->budget--) { s->failed_pc=0x0c074e10u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c074e12;
P_0c074e12: /* original 6bf6, guest PC 0x0c074e12 */
if(!s->budget--) { s->failed_pc=0x0c074e12u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c074e14;
P_0c074e14: /* original 6cf6, guest PC 0x0c074e14 */
if(!s->budget--) { s->failed_pc=0x0c074e14u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c074e16;
P_0c074e16: /* original 6df6, guest PC 0x0c074e16 */
if(!s->budget--) { s->failed_pc=0x0c074e16u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c074e18;
P_0c074e18: /* original 000b, guest PC 0x0c074e18 */
if(!s->budget--) { s->failed_pc=0x0c074e18u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c074e1a: /* original 6ef6, guest PC 0x0c074e1a */
if(!s->budget--) { s->failed_pc=0x0c074e1au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c074e1cu,s,ram);
P_0c0750be: /* original 4f22, guest PC 0x0c0750be */
if(!s->budget--) { s->failed_pc=0x0c0750beu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0750c0;
P_0c0750c0: /* original 9033, guest PC 0x0c0750c0 */
if(!s->budget--) { s->failed_pc=0x0c0750c0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07512au,2);
goto P_0c0750c2;
P_0c0750c2: /* original 9333, guest PC 0x0c0750c2 */
if(!s->budget--) { s->failed_pc=0x0c0750c2u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07512cu,2);
goto P_0c0750c4;
P_0c0750c4: /* original 4f12, guest PC 0x0c0750c4 */
if(!s->budget--) { s->failed_pc=0x0c0750c4u; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c0750c6;
P_0c0750c6: /* original 3f0c, guest PC 0x0c0750c6 */
if(!s->budget--) { s->failed_pc=0x0c0750c6u; return 0; }
r[15]+=r[0];
goto P_0c0750c8;
P_0c0750c8: /* original 33fc, guest PC 0x0c0750c8 */
if(!s->budget--) { s->failed_pc=0x0c0750c8u; return 0; }
r[3]+=r[15];
goto P_0c0750ca;
P_0c0750ca: /* original 61f3, guest PC 0x0c0750ca */
if(!s->budget--) { s->failed_pc=0x0c0750cau; return 0; }
r[1]=r[15];
goto P_0c0750cc;
P_0c0750cc: /* original 2342, guest PC 0x0c0750cc */
if(!s->budget--) { s->failed_pc=0x0c0750ccu; return 0; }
write(ram,r[3],r[4],4);
goto P_0c0750ce;
P_0c0750ce: /* original 7148, guest PC 0x0c0750ce */
if(!s->budget--) { s->failed_pc=0x0c0750ceu; return 0; }
r[1]+=0x00000048u;
goto P_0c0750d0;
P_0c0750d0: /* original 922d, guest PC 0x0c0750d0 */
if(!s->budget--) { s->failed_pc=0x0c0750d0u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07512eu,2);
goto P_0c0750d2;
P_0c0750d2: /* original 32fc, guest PC 0x0c0750d2 */
if(!s->budget--) { s->failed_pc=0x0c0750d2u; return 0; }
r[2]+=r[15];
goto P_0c0750d4;
P_0c0750d4: /* original 2252, guest PC 0x0c0750d4 */
if(!s->budget--) { s->failed_pc=0x0c0750d4u; return 0; }
write(ram,r[2],r[5],4);
goto P_0c0750d6;
P_0c0750d6: /* original 9029, guest PC 0x0c0750d6 */
if(!s->budget--) { s->failed_pc=0x0c0750d6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07512cu,2);
goto P_0c0750d8;
P_0c0750d8: /* original 03fe, guest PC 0x0c0750d8 */
if(!s->budget--) { s->failed_pc=0x0c0750d8u; return 0; }
r[3]=read(ram,r[15]+r[0],4);
goto P_0c0750da;
P_0c0750da: /* original 9029, guest PC 0x0c0750da */
if(!s->budget--) { s->failed_pc=0x0c0750dau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c075130u,2);
goto P_0c0750dc;
P_0c0750dc: /* original 023e, guest PC 0x0c0750dc */
if(!s->budget--) { s->failed_pc=0x0c0750dcu; return 0; }
r[2]=read(ram,r[3]+r[0],4);
goto P_0c0750de;
P_0c0750de: /* original 7201, guest PC 0x0c0750de */
if(!s->budget--) { s->failed_pc=0x0c0750deu; return 0; }
r[2]+=0x00000001u;
goto P_0c0750e0;
P_0c0750e0: /* original 0326, guest PC 0x0c0750e0 */
if(!s->budget--) { s->failed_pc=0x0c0750e0u; return 0; }
write(ram,r[3]+r[0],r[2],4);
goto P_0c0750e2;
P_0c0750e2: /* original 9024, guest PC 0x0c0750e2 */
if(!s->budget--) { s->failed_pc=0x0c0750e2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07512eu,2);
goto P_0c0750e4;
P_0c0750e4: /* original 02fe, guest PC 0x0c0750e4 */
if(!s->budget--) { s->failed_pc=0x0c0750e4u; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c0750e6;
P_0c0750e6: /* original 7238, guest PC 0x0c0750e6 */
if(!s->budget--) { s->failed_pc=0x0c0750e6u; return 0; }
r[2]+=0x00000038u;
goto P_0c0750e8;
P_0c0750e8: /* original 8423, guest PC 0x0c0750e8 */
if(!s->budget--) { s->failed_pc=0x0c0750e8u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[2]+3,1);
goto P_0c0750ea;
P_0c0750ea: /* original 600c, guest PC 0x0c0750ea */
if(!s->budget--) { s->failed_pc=0x0c0750eau; return 0; }
r[0]=r[0]&255u;
goto P_0c0750ec;
P_0c0750ec: /* original 2102, guest PC 0x0c0750ec */
if(!s->budget--) { s->failed_pc=0x0c0750ecu; return 0; }
write(ram,r[1],r[0],4);
goto P_0c0750ee;
P_0c0750ee: /* original 61f3, guest PC 0x0c0750ee */
if(!s->budget--) { s->failed_pc=0x0c0750eeu; return 0; }
r[1]=r[15];
goto P_0c0750f0;
P_0c0750f0: /* original 901d, guest PC 0x0c0750f0 */
if(!s->budget--) { s->failed_pc=0x0c0750f0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07512eu,2);
goto P_0c0750f2;
P_0c0750f2: /* original 7144, guest PC 0x0c0750f2 */
if(!s->budget--) { s->failed_pc=0x0c0750f2u; return 0; }
r[1]+=0x00000044u;
goto P_0c0750f4;
P_0c0750f4: /* original 02fe, guest PC 0x0c0750f4 */
if(!s->budget--) { s->failed_pc=0x0c0750f4u; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c0750f6;
P_0c0750f6: /* original 7234, guest PC 0x0c0750f6 */
if(!s->budget--) { s->failed_pc=0x0c0750f6u; return 0; }
r[2]+=0x00000034u;
goto P_0c0750f8;
P_0c0750f8: /* original 8423, guest PC 0x0c0750f8 */
if(!s->budget--) { s->failed_pc=0x0c0750f8u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[2]+3,1);
goto P_0c0750fa;
P_0c0750fa: /* original 600c, guest PC 0x0c0750fa */
if(!s->budget--) { s->failed_pc=0x0c0750fau; return 0; }
r[0]=r[0]&255u;
goto P_0c0750fc;
P_0c0750fc: /* original 2102, guest PC 0x0c0750fc */
if(!s->budget--) { s->failed_pc=0x0c0750fcu; return 0; }
write(ram,r[1],r[0],4);
goto P_0c0750fe;
P_0c0750fe: /* original e048, guest PC 0x0c0750fe */
if(!s->budget--) { s->failed_pc=0x0c0750feu; return 0; }
r[0]=0x00000048u;
goto P_0c075100;
P_0c075100: /* original 00fe, guest PC 0x0c075100 */
if(!s->budget--) { s->failed_pc=0x0c075100u; return 0; }
r[0]=read(ram,r[15]+r[0],4);
goto P_0c075102;
P_0c075102: /* original 8814, guest PC 0x0c075102 */
if(!s->budget--) { s->failed_pc=0x0c075102u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000014u)!=0);
goto P_0c075104;
P_0c075104: /* original 8b1a, guest PC 0x0c075104 */
if(!s->budget--) { s->failed_pc=0x0c075104u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07513c; }
goto P_0c075106;
P_0c075106: /* original e044, guest PC 0x0c075106 */
if(!s->budget--) { s->failed_pc=0x0c075106u; return 0; }
r[0]=0x00000044u;
goto P_0c075108;
P_0c075108: /* original 00fe, guest PC 0x0c075108 */
if(!s->budget--) { s->failed_pc=0x0c075108u; return 0; }
r[0]=read(ram,r[15]+r[0],4);
goto P_0c07510a;
P_0c07510a: /* original 880c, guest PC 0x0c07510a */
if(!s->budget--) { s->failed_pc=0x0c07510au; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000cu)!=0);
goto P_0c07510c;
P_0c07510c: /* original 8916, guest PC 0x0c07510c */
if(!s->budget--) { s->failed_pc=0x0c07510cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07513c; }
goto P_0c07510e;
P_0c07510e: /* original 900e, guest PC 0x0c07510e */
if(!s->budget--) { s->failed_pc=0x0c07510eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07512eu,2);
goto P_0c075110;
P_0c075110: /* original d309, guest PC 0x0c075110 */
if(!s->budget--) { s->failed_pc=0x0c075110u; return 0; }
r[3]=read(ram,0x0c075138u,4);
goto P_0c075112;
P_0c075112: /* original 05fe, guest PC 0x0c075112 */
if(!s->budget--) { s->failed_pc=0x0c075112u; return 0; }
r[5]=read(ram,r[15]+r[0],4);
goto P_0c075114;
P_0c075114: /* original 900a, guest PC 0x0c075114 */
if(!s->budget--) { s->failed_pc=0x0c075114u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07512cu,2);
goto P_0c075116;
P_0c075116: /* original 430b, guest PC 0x0c075116 */
if(!s->budget--) { s->failed_pc=0x0c075116u; return 0; }
target=r[3];
r[16]=0x0c07511au;
r[4]=read(ram,r[15]+r[0],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07511au) { target=s->pc; goto dispatch; }
goto P_0c07511a;
P_0c075118: /* original 04fe, guest PC 0x0c075118 */
if(!s->budget--) { s->failed_pc=0x0c075118u; return 0; }
r[4]=read(ram,r[15]+r[0],4);
goto P_0c07511a;
P_0c07511a: /* original 910a, guest PC 0x0c07511a */
if(!s->budget--) { s->failed_pc=0x0c07511au; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c075132u,2);
goto P_0c07511c;
P_0c07511c: /* original 3f1c, guest PC 0x0c07511c */
if(!s->budget--) { s->failed_pc=0x0c07511cu; return 0; }
r[15]+=r[1];
goto P_0c07511e;
P_0c07511e: /* original 4f16, guest PC 0x0c07511e */
if(!s->budget--) { s->failed_pc=0x0c07511eu; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c075120;
P_0c075120: /* original 4f26, guest PC 0x0c075120 */
if(!s->budget--) { s->failed_pc=0x0c075120u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c075122;
P_0c075122: /* original 000b, guest PC 0x0c075122 */
if(!s->budget--) { s->failed_pc=0x0c075122u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c075124: /* original 0009, guest PC 0x0c075124 */
if(!s->budget--) { s->failed_pc=0x0c075124u; return 0; }
return vf3_matrix_family(0x0c075126u,s,ram);
P_0c07513c: /* original 905d, guest PC 0x0c07513c */
if(!s->budget--) { s->failed_pc=0x0c07513cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0751fau,2);
goto P_0c07513e;
P_0c07513e: /* original 03fe, guest PC 0x0c07513e */
if(!s->budget--) { s->failed_pc=0x0c07513eu; return 0; }
r[3]=read(ram,r[15]+r[0],4);
goto P_0c075140;
P_0c075140: /* original 905c, guest PC 0x0c075140 */
if(!s->budget--) { s->failed_pc=0x0c075140u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0751fcu,2);
goto P_0c075142;
P_0c075142: /* original 023c, guest PC 0x0c075142 */
if(!s->budget--) { s->failed_pc=0x0c075142u; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[3]+r[0],1);
goto P_0c075144;
P_0c075144: /* original e060, guest PC 0x0c075144 */
if(!s->budget--) { s->failed_pc=0x0c075144u; return 0; }
r[0]=0x00000060u;
goto P_0c075146;
P_0c075146: /* original 622c, guest PC 0x0c075146 */
if(!s->budget--) { s->failed_pc=0x0c075146u; return 0; }
r[2]=r[2]&255u;
goto P_0c075148;
P_0c075148: /* original 0f26, guest PC 0x0c075148 */
if(!s->budget--) { s->failed_pc=0x0c075148u; return 0; }
write(ram,r[15]+r[0],r[2],4);
goto P_0c07514a;
P_0c07514a: /* original 9058, guest PC 0x0c07514a */
if(!s->budget--) { s->failed_pc=0x0c07514au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0751feu,2);
goto P_0c07514c;
P_0c07514c: /* original 03fe, guest PC 0x0c07514c */
if(!s->budget--) { s->failed_pc=0x0c07514cu; return 0; }
r[3]=read(ram,r[15]+r[0],4);
goto P_0c07514e;
P_0c07514e: /* original e048, guest PC 0x0c07514e */
if(!s->budget--) { s->failed_pc=0x0c07514eu; return 0; }
r[0]=0x00000048u;
goto P_0c075150;
P_0c075150: /* original 023e, guest PC 0x0c075150 */
if(!s->budget--) { s->failed_pc=0x0c075150u; return 0; }
r[2]=read(ram,r[3]+r[0],4);
goto P_0c075152;
P_0c075152: /* original e05c, guest PC 0x0c075152 */
if(!s->budget--) { s->failed_pc=0x0c075152u; return 0; }
r[0]=0x0000005cu;
goto P_0c075154;
P_0c075154: /* original 0f26, guest PC 0x0c075154 */
if(!s->budget--) { s->failed_pc=0x0c075154u; return 0; }
write(ram,r[15]+r[0],r[2],4);
goto P_0c075156;
P_0c075156: /* original 9052, guest PC 0x0c075156 */
if(!s->budget--) { s->failed_pc=0x0c075156u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0751feu,2);
goto P_0c075158;
P_0c075158: /* original 03fe, guest PC 0x0c075158 */
if(!s->budget--) { s->failed_pc=0x0c075158u; return 0; }
r[3]=read(ram,r[15]+r[0],4);
goto P_0c07515a;
P_0c07515a: /* original e04c, guest PC 0x0c07515a */
if(!s->budget--) { s->failed_pc=0x0c07515au; return 0; }
r[0]=0x0000004cu;
goto P_0c07515c;
P_0c07515c: /* original 023e, guest PC 0x0c07515c */
if(!s->budget--) { s->failed_pc=0x0c07515cu; return 0; }
r[2]=read(ram,r[3]+r[0],4);
goto P_0c07515e;
P_0c07515e: /* original e06c, guest PC 0x0c07515e */
if(!s->budget--) { s->failed_pc=0x0c07515eu; return 0; }
r[0]=0x0000006cu;
goto P_0c075160;
P_0c075160: /* original 0f26, guest PC 0x0c075160 */
if(!s->budget--) { s->failed_pc=0x0c075160u; return 0; }
write(ram,r[15]+r[0],r[2],4);
goto P_0c075162;
P_0c075162: /* original 904a, guest PC 0x0c075162 */
if(!s->budget--) { s->failed_pc=0x0c075162u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0751fau,2);
goto P_0c075164;
P_0c075164: /* original 03fe, guest PC 0x0c075164 */
if(!s->budget--) { s->failed_pc=0x0c075164u; return 0; }
r[3]=read(ram,r[15]+r[0],4);
goto P_0c075166;
P_0c075166: /* original 904b, guest PC 0x0c075166 */
if(!s->budget--) { s->failed_pc=0x0c075166u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c075200u,2);
goto P_0c075168;
P_0c075168: /* original 023e, guest PC 0x0c075168 */
if(!s->budget--) { s->failed_pc=0x0c075168u; return 0; }
r[2]=read(ram,r[3]+r[0],4);
goto P_0c07516a;
P_0c07516a: /* original e070, guest PC 0x0c07516a */
if(!s->budget--) { s->failed_pc=0x0c07516au; return 0; }
r[0]=0x00000070u;
goto P_0c07516c;
P_0c07516c: /* original 0f26, guest PC 0x0c07516c */
if(!s->budget--) { s->failed_pc=0x0c07516cu; return 0; }
write(ram,r[15]+r[0],r[2],4);
goto P_0c07516e;
P_0c07516e: /* original e060, guest PC 0x0c07516e */
if(!s->budget--) { s->failed_pc=0x0c07516eu; return 0; }
r[0]=0x00000060u;
goto P_0c075170;
P_0c075170: /* original 01fe, guest PC 0x0c075170 */
if(!s->budget--) { s->failed_pc=0x0c075170u; return 0; }
r[1]=read(ram,r[15]+r[0],4);
goto P_0c075172;
P_0c075172: /* original 9346, guest PC 0x0c075172 */
if(!s->budget--) { s->failed_pc=0x0c075172u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c075202u,2);
goto P_0c075174;
P_0c075174: /* original 3130, guest PC 0x0c075174 */
if(!s->budget--) { s->failed_pc=0x0c075174u; return 0; }
r[17]=(r[17]&~1u)|((r[1]==r[3])!=0);
goto P_0c075176;
P_0c075176: /* original 8b02, guest PC 0x0c075176 */
if(!s->budget--) { s->failed_pc=0x0c075176u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07517e; }
goto P_0c075178;
P_0c075178: /* original d222, guest PC 0x0c075178 */
if(!s->budget--) { s->failed_pc=0x0c075178u; return 0; }
r[2]=read(ram,0x0c075204u,4);
goto P_0c07517a;
P_0c07517a: /* original 422b, guest PC 0x0c07517a */
if(!s->budget--) { s->failed_pc=0x0c07517au; return 0; }
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
P_0c07517c: /* original 0009, guest PC 0x0c07517c */
if(!s->budget--) { s->failed_pc=0x0c07517cu; return 0; }
goto P_0c07517e;
P_0c07517e: /* original e048, guest PC 0x0c07517e */
if(!s->budget--) { s->failed_pc=0x0c07517eu; return 0; }
r[0]=0x00000048u;
goto P_0c075180;
P_0c075180: /* original 00fe, guest PC 0x0c075180 */
if(!s->budget--) { s->failed_pc=0x0c075180u; return 0; }
r[0]=read(ram,r[15]+r[0],4);
goto P_0c075182;
P_0c075182: /* original 8818, guest PC 0x0c075182 */
if(!s->budget--) { s->failed_pc=0x0c075182u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000018u)!=0);
goto P_0c075184;
P_0c075184: /* original 8b02, guest PC 0x0c075184 */
if(!s->budget--) { s->failed_pc=0x0c075184u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07518c; }
goto P_0c075186;
P_0c075186: /* original d21f, guest PC 0x0c075186 */
if(!s->budget--) { s->failed_pc=0x0c075186u; return 0; }
r[2]=read(ram,0x0c075204u,4);
goto P_0c075188;
P_0c075188: /* original 422b, guest PC 0x0c075188 */
if(!s->budget--) { s->failed_pc=0x0c075188u; return 0; }
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
P_0c07518a: /* original 0009, guest PC 0x0c07518a */
if(!s->budget--) { s->failed_pc=0x0c07518au; return 0; }
goto P_0c07518c;
P_0c07518c: /* original e060, guest PC 0x0c07518c */
if(!s->budget--) { s->failed_pc=0x0c07518cu; return 0; }
r[0]=0x00000060u;
goto P_0c07518e;
P_0c07518e: /* original 02fe, guest PC 0x0c07518e */
if(!s->budget--) { s->failed_pc=0x0c07518eu; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c075190;
P_0c075190: /* original 2228, guest PC 0x0c075190 */
if(!s->budget--) { s->failed_pc=0x0c075190u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c075192;
P_0c075192: /* original 8b14, guest PC 0x0c075192 */
if(!s->budget--) { s->failed_pc=0x0c075192u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0751be; }
goto P_0c075194;
P_0c075194: /* original e05c, guest PC 0x0c075194 */
if(!s->budget--) { s->failed_pc=0x0c075194u; return 0; }
r[0]=0x0000005cu;
goto P_0c075196;
P_0c075196: /* original d31c, guest PC 0x0c075196 */
if(!s->budget--) { s->failed_pc=0x0c075196u; return 0; }
r[3]=read(ram,0x0c075208u,4);
goto P_0c075198;
P_0c075198: /* original 02fe, guest PC 0x0c075198 */
if(!s->budget--) { s->failed_pc=0x0c075198u; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c07519a;
P_0c07519a: /* original 2238, guest PC 0x0c07519a */
if(!s->budget--) { s->failed_pc=0x0c07519au; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c07519c;
P_0c07519c: /* original 890f, guest PC 0x0c07519c */
if(!s->budget--) { s->failed_pc=0x0c07519cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0751be; }
goto P_0c07519e;
P_0c07519e: /* original e05c, guest PC 0x0c07519e */
if(!s->budget--) { s->failed_pc=0x0c07519eu; return 0; }
r[0]=0x0000005cu;
goto P_0c0751a0;
P_0c0751a0: /* original d31a, guest PC 0x0c0751a0 */
if(!s->budget--) { s->failed_pc=0x0c0751a0u; return 0; }
r[3]=read(ram,0x0c07520cu,4);
goto P_0c0751a2;
P_0c0751a2: /* original 01fe, guest PC 0x0c0751a2 */
if(!s->budget--) { s->failed_pc=0x0c0751a2u; return 0; }
r[1]=read(ram,r[15]+r[0],4);
goto P_0c0751a4;
P_0c0751a4: /* original 2138, guest PC 0x0c0751a4 */
if(!s->budget--) { s->failed_pc=0x0c0751a4u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[3])==0)!=0);
goto P_0c0751a6;
P_0c0751a6: /* original 8b02, guest PC 0x0c0751a6 */
if(!s->budget--) { s->failed_pc=0x0c0751a6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0751ae; }
goto P_0c0751a8;
P_0c0751a8: /* original d216, guest PC 0x0c0751a8 */
if(!s->budget--) { s->failed_pc=0x0c0751a8u; return 0; }
r[2]=read(ram,0x0c075204u,4);
goto P_0c0751aa;
P_0c0751aa: /* original 422b, guest PC 0x0c0751aa */
if(!s->budget--) { s->failed_pc=0x0c0751aau; return 0; }
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
P_0c0751ac: /* original 0009, guest PC 0x0c0751ac */
if(!s->budget--) { s->failed_pc=0x0c0751acu; return 0; }
goto P_0c0751ae;
P_0c0751ae: /* original e05c, guest PC 0x0c0751ae */
if(!s->budget--) { s->failed_pc=0x0c0751aeu; return 0; }
r[0]=0x0000005cu;
goto P_0c0751b0;
P_0c0751b0: /* original d317, guest PC 0x0c0751b0 */
if(!s->budget--) { s->failed_pc=0x0c0751b0u; return 0; }
r[3]=read(ram,0x0c075210u,4);
goto P_0c0751b2;
P_0c0751b2: /* original 02fe, guest PC 0x0c0751b2 */
if(!s->budget--) { s->failed_pc=0x0c0751b2u; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c0751b4;
P_0c0751b4: /* original 2238, guest PC 0x0c0751b4 */
if(!s->budget--) { s->failed_pc=0x0c0751b4u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0751b6;
P_0c0751b6: /* original 8b02, guest PC 0x0c0751b6 */
if(!s->budget--) { s->failed_pc=0x0c0751b6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0751be; }
goto P_0c0751b8;
P_0c0751b8: /* original d112, guest PC 0x0c0751b8 */
if(!s->budget--) { s->failed_pc=0x0c0751b8u; return 0; }
r[1]=read(ram,0x0c075204u,4);
goto P_0c0751ba;
P_0c0751ba: /* original 412b, guest PC 0x0c0751ba */
if(!s->budget--) { s->failed_pc=0x0c0751bau; return 0; }
target=r[1];
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
P_0c0751bc: /* original 0009, guest PC 0x0c0751bc */
if(!s->budget--) { s->failed_pc=0x0c0751bcu; return 0; }
goto P_0c0751be;
P_0c0751be: /* original e05c, guest PC 0x0c0751be */
if(!s->budget--) { s->failed_pc=0x0c0751beu; return 0; }
r[0]=0x0000005cu;
goto P_0c0751c0;
P_0c0751c0: /* original d314, guest PC 0x0c0751c0 */
if(!s->budget--) { s->failed_pc=0x0c0751c0u; return 0; }
r[3]=read(ram,0x0c075214u,4);
goto P_0c0751c2;
P_0c0751c2: /* original 01fe, guest PC 0x0c0751c2 */
if(!s->budget--) { s->failed_pc=0x0c0751c2u; return 0; }
r[1]=read(ram,r[15]+r[0],4);
goto P_0c0751c4;
P_0c0751c4: /* original 2138, guest PC 0x0c0751c4 */
if(!s->budget--) { s->failed_pc=0x0c0751c4u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[3])==0)!=0);
goto P_0c0751c6;
P_0c0751c6: /* original 8b04, guest PC 0x0c0751c6 */
if(!s->budget--) { s->failed_pc=0x0c0751c6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0751d2; }
goto P_0c0751c8;
P_0c0751c8: /* original e05c, guest PC 0x0c0751c8 */
if(!s->budget--) { s->failed_pc=0x0c0751c8u; return 0; }
r[0]=0x0000005cu;
goto P_0c0751ca;
P_0c0751ca: /* original d213, guest PC 0x0c0751ca */
if(!s->budget--) { s->failed_pc=0x0c0751cau; return 0; }
r[2]=read(ram,0x0c075218u,4);
goto P_0c0751cc;
P_0c0751cc: /* original 01fe, guest PC 0x0c0751cc */
if(!s->budget--) { s->failed_pc=0x0c0751ccu; return 0; }
r[1]=read(ram,r[15]+r[0],4);
goto P_0c0751ce;
P_0c0751ce: /* original 2128, guest PC 0x0c0751ce */
if(!s->budget--) { s->failed_pc=0x0c0751ceu; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[2])==0)!=0);
goto P_0c0751d0;
P_0c0751d0: /* original 8939, guest PC 0x0c0751d0 */
if(!s->budget--) { s->failed_pc=0x0c0751d0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c075246; }
goto P_0c0751d2;
P_0c0751d2: /* original e06c, guest PC 0x0c0751d2 */
if(!s->budget--) { s->failed_pc=0x0c0751d2u; return 0; }
r[0]=0x0000006cu;
goto P_0c0751d4;
P_0c0751d4: /* original d311, guest PC 0x0c0751d4 */
if(!s->budget--) { s->failed_pc=0x0c0751d4u; return 0; }
r[3]=read(ram,0x0c07521cu,4);
goto P_0c0751d6;
P_0c0751d6: /* original 02fe, guest PC 0x0c0751d6 */
if(!s->budget--) { s->failed_pc=0x0c0751d6u; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c0751d8;
P_0c0751d8: /* original 2238, guest PC 0x0c0751d8 */
if(!s->budget--) { s->failed_pc=0x0c0751d8u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0751da;
P_0c0751da: /* original 8b34, guest PC 0x0c0751da */
if(!s->budget--) { s->failed_pc=0x0c0751dau; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c075246; }
goto P_0c0751dc;
P_0c0751dc: /* original 61f3, guest PC 0x0c0751dc */
if(!s->budget--) { s->failed_pc=0x0c0751dcu; return 0; }
r[1]=r[15];
goto P_0c0751de;
P_0c0751de: /* original 716c, guest PC 0x0c0751de */
if(!s->budget--) { s->failed_pc=0x0c0751deu; return 0; }
r[1]+=0x0000006cu;
goto P_0c0751e0;
P_0c0751e0: /* original 6012, guest PC 0x0c0751e0 */
if(!s->budget--) { s->failed_pc=0x0c0751e0u; return 0; }
tmp=read(ram,r[1],4);
r[0]=tmp;
goto P_0c0751e2;
P_0c0751e2: /* original c808, guest PC 0x0c0751e2 */
if(!s->budget--) { s->failed_pc=0x0c0751e2u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&8u)==0)!=0);
goto P_0c0751e4;
P_0c0751e4: /* original 891c, guest PC 0x0c0751e4 */
if(!s->budget--) { s->failed_pc=0x0c0751e4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c075220; }
goto P_0c0751e6;
P_0c0751e6: /* original 900a, guest PC 0x0c0751e6 */
if(!s->budget--) { s->failed_pc=0x0c0751e6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0751feu,2);
goto P_0c0751e8;
P_0c0751e8: /* original 02fe, guest PC 0x0c0751e8 */
if(!s->budget--) { s->failed_pc=0x0c0751e8u; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c0751ea;
P_0c0751ea: /* original e062, guest PC 0x0c0751ea */
if(!s->budget--) { s->failed_pc=0x0c0751eau; return 0; }
r[0]=0x00000062u;
goto P_0c0751ec;
P_0c0751ec: /* original 012c, guest PC 0x0c0751ec */
if(!s->budget--) { s->failed_pc=0x0c0751ecu; return 0; }
r[1]=(uint32_t)(int32_t)(int8_t)read(ram,r[2]+r[0],1);
goto P_0c0751ee;
P_0c0751ee: /* original e204, guest PC 0x0c0751ee */
if(!s->budget--) { s->failed_pc=0x0c0751eeu; return 0; }
r[2]=0x00000004u;
goto P_0c0751f0;
P_0c0751f0: /* original 611c, guest PC 0x0c0751f0 */
if(!s->budget--) { s->failed_pc=0x0c0751f0u; return 0; }
r[1]=r[1]&255u;
goto P_0c0751f2;
P_0c0751f2: /* original 3127, guest PC 0x0c0751f2 */
if(!s->budget--) { s->failed_pc=0x0c0751f2u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[1]>(int32_t)r[2])!=0);
goto P_0c0751f4;
P_0c0751f4: /* original 8b20, guest PC 0x0c0751f4 */
if(!s->budget--) { s->failed_pc=0x0c0751f4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c075238; }
goto P_0c0751f6;
P_0c0751f6: /* original a026, guest PC 0x0c0751f6 */
if(!s->budget--) { s->failed_pc=0x0c0751f6u; return 0; }
goto P_0c075246;
P_0c0751f8: /* original 0009, guest PC 0x0c0751f8 */
if(!s->budget--) { s->failed_pc=0x0c0751f8u; return 0; }
return vf3_matrix_family(0x0c0751fau,s,ram);
P_0c075220: /* original 90a2, guest PC 0x0c075220 */
if(!s->budget--) { s->failed_pc=0x0c075220u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c075368u,2);
goto P_0c075222;
P_0c075222: /* original d256, guest PC 0x0c075222 */
if(!s->budget--) { s->failed_pc=0x0c075222u; return 0; }
r[2]=read(ram,0x0c07537cu,4);
goto P_0c075224;
P_0c075224: /* original 03fe, guest PC 0x0c075224 */
if(!s->budget--) { s->failed_pc=0x0c075224u; return 0; }
r[3]=read(ram,r[15]+r[0],4);
goto P_0c075226;
P_0c075226: /* original 90a0, guest PC 0x0c075226 */
if(!s->budget--) { s->failed_pc=0x0c075226u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07536au,2);
goto P_0c075228;
P_0c075228: /* original 013e, guest PC 0x0c075228 */
if(!s->budget--) { s->failed_pc=0x0c075228u; return 0; }
r[1]=read(ram,r[3]+r[0],4);
goto P_0c07522a;
P_0c07522a: /* original 2128, guest PC 0x0c07522a */
if(!s->budget--) { s->failed_pc=0x0c07522au; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[2])==0)!=0);
goto P_0c07522c;
P_0c07522c: /* original 8904, guest PC 0x0c07522c */
if(!s->budget--) { s->failed_pc=0x0c07522cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c075238; }
goto P_0c07522e;
P_0c07522e: /* original e05c, guest PC 0x0c07522e */
if(!s->budget--) { s->failed_pc=0x0c07522eu; return 0; }
r[0]=0x0000005cu;
goto P_0c075230;
P_0c075230: /* original d353, guest PC 0x0c075230 */
if(!s->budget--) { s->failed_pc=0x0c075230u; return 0; }
r[3]=read(ram,0x0c075380u,4);
goto P_0c075232;
P_0c075232: /* original 02fe, guest PC 0x0c075232 */
if(!s->budget--) { s->failed_pc=0x0c075232u; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c075234;
P_0c075234: /* original 2238, guest PC 0x0c075234 */
if(!s->budget--) { s->failed_pc=0x0c075234u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c075236;
P_0c075236: /* original 8906, guest PC 0x0c075236 */
if(!s->budget--) { s->failed_pc=0x0c075236u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c075246; }
goto P_0c075238;
P_0c075238: /* original e060, guest PC 0x0c075238 */
if(!s->budget--) { s->failed_pc=0x0c075238u; return 0; }
r[0]=0x00000060u;
goto P_0c07523a;
P_0c07523a: /* original 00fe, guest PC 0x0c07523a */
if(!s->budget--) { s->failed_pc=0x0c07523au; return 0; }
r[0]=read(ram,r[15]+r[0],4);
goto P_0c07523c;
P_0c07523c: /* original 8804, guest PC 0x0c07523c */
if(!s->budget--) { s->failed_pc=0x0c07523cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000004u)!=0);
goto P_0c07523e;
P_0c07523e: /* original 8902, guest PC 0x0c07523e */
if(!s->budget--) { s->failed_pc=0x0c07523eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c075246; }
goto P_0c075240;
P_0c075240: /* original d350, guest PC 0x0c075240 */
if(!s->budget--) { s->failed_pc=0x0c075240u; return 0; }
r[3]=read(ram,0x0c075384u,4);
goto P_0c075242;
P_0c075242: /* original 432b, guest PC 0x0c075242 */
if(!s->budget--) { s->failed_pc=0x0c075242u; return 0; }
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
P_0c075244: /* original 0009, guest PC 0x0c075244 */
if(!s->budget--) { s->failed_pc=0x0c075244u; return 0; }
goto P_0c075246;
P_0c075246: /* original e06c, guest PC 0x0c075246 */
if(!s->budget--) { s->failed_pc=0x0c075246u; return 0; }
r[0]=0x0000006cu;
goto P_0c075248;
P_0c075248: /* original d34f, guest PC 0x0c075248 */
if(!s->budget--) { s->failed_pc=0x0c075248u; return 0; }
r[3]=read(ram,0x0c075388u,4);
goto P_0c07524a;
P_0c07524a: /* original 02fe, guest PC 0x0c07524a */
if(!s->budget--) { s->failed_pc=0x0c07524au; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c07524c;
P_0c07524c: /* original 2238, guest PC 0x0c07524c */
if(!s->budget--) { s->failed_pc=0x0c07524cu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c07524e;
P_0c07524e: /* original 8b01, guest PC 0x0c07524e */
if(!s->budget--) { s->failed_pc=0x0c07524eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c075254; }
goto P_0c075250;
P_0c075250: /* original a0dd, guest PC 0x0c075250 */
if(!s->budget--) { s->failed_pc=0x0c075250u; return 0; }
goto P_0c07540e;
P_0c075252: /* original 0009, guest PC 0x0c075252 */
if(!s->budget--) { s->failed_pc=0x0c075252u; return 0; }
goto P_0c075254;
P_0c075254: /* original 9088, guest PC 0x0c075254 */
if(!s->budget--) { s->failed_pc=0x0c075254u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c075368u,2);
goto P_0c075256;
P_0c075256: /* original d14d, guest PC 0x0c075256 */
if(!s->budget--) { s->failed_pc=0x0c075256u; return 0; }
r[1]=read(ram,0x0c07538cu,4);
goto P_0c075258;
P_0c075258: /* original 02fe, guest PC 0x0c075258 */
if(!s->budget--) { s->failed_pc=0x0c075258u; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c07525a;
P_0c07525a: /* original e050, guest PC 0x0c07525a */
if(!s->budget--) { s->failed_pc=0x0c07525au; return 0; }
r[0]=0x00000050u;
goto P_0c07525c;
P_0c07525c: /* original 022e, guest PC 0x0c07525c */
if(!s->budget--) { s->failed_pc=0x0c07525cu; return 0; }
r[2]=read(ram,r[2]+r[0],4);
goto P_0c07525e;
P_0c07525e: /* original 2218, guest PC 0x0c07525e */
if(!s->budget--) { s->failed_pc=0x0c07525eu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[1])==0)!=0);
goto P_0c075260;
P_0c075260: /* original 8b01, guest PC 0x0c075260 */
if(!s->budget--) { s->failed_pc=0x0c075260u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c075266; }
goto P_0c075262;
P_0c075262: /* original a0d4, guest PC 0x0c075262 */
if(!s->budget--) { s->failed_pc=0x0c075262u; return 0; }
goto P_0c07540e;
P_0c075264: /* original 0009, guest PC 0x0c075264 */
if(!s->budget--) { s->failed_pc=0x0c075264u; return 0; }
goto P_0c075266;
P_0c075266: /* original 9081, guest PC 0x0c075266 */
if(!s->budget--) { s->failed_pc=0x0c075266u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07536cu,2);
goto P_0c075268;
P_0c075268: /* original 03fe, guest PC 0x0c075268 */
if(!s->budget--) { s->failed_pc=0x0c075268u; return 0; }
r[3]=read(ram,r[15]+r[0],4);
goto P_0c07526a;
P_0c07526a: /* original 9080, guest PC 0x0c07526a */
if(!s->budget--) { s->failed_pc=0x0c07526au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07536eu,2);
goto P_0c07526c;
P_0c07526c: /* original 023e, guest PC 0x0c07526c */
if(!s->budget--) { s->failed_pc=0x0c07526cu; return 0; }
r[2]=read(ram,r[3]+r[0],4);
goto P_0c07526e;
P_0c07526e: /* original 6123, guest PC 0x0c07526e */
if(!s->budget--) { s->failed_pc=0x0c07526eu; return 0; }
r[1]=r[2];
goto P_0c075270;
P_0c075270: /* original 1f25, guest PC 0x0c075270 */
if(!s->budget--) { s->failed_pc=0x0c075270u; return 0; }
write(ram,r[15]+20,r[2],4);
goto P_0c075272;
P_0c075272: /* original d347, guest PC 0x0c075272 */
if(!s->budget--) { s->failed_pc=0x0c075272u; return 0; }
r[3]=read(ram,0x0c075390u,4);
goto P_0c075274;
P_0c075274: /* original 2138, guest PC 0x0c075274 */
if(!s->budget--) { s->failed_pc=0x0c075274u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[3])==0)!=0);
goto P_0c075276;
P_0c075276: /* original 8b05, guest PC 0x0c075276 */
if(!s->budget--) { s->failed_pc=0x0c075276u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c075284; }
goto P_0c075278;
P_0c075278: /* original 51f5, guest PC 0x0c075278 */
if(!s->budget--) { s->failed_pc=0x0c075278u; return 0; }
r[1]=read(ram,r[15]+20,4);
goto P_0c07527a;
P_0c07527a: /* original d244, guest PC 0x0c07527a */
if(!s->budget--) { s->failed_pc=0x0c07527au; return 0; }
r[2]=read(ram,0x0c07538cu,4);
goto P_0c07527c;
P_0c07527c: /* original 2128, guest PC 0x0c07527c */
if(!s->budget--) { s->failed_pc=0x0c07527cu; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[2])==0)!=0);
goto P_0c07527e;
P_0c07527e: /* original 8b01, guest PC 0x0c07527e */
if(!s->budget--) { s->failed_pc=0x0c07527eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c075284; }
goto P_0c075280;
P_0c075280: /* original a0c5, guest PC 0x0c075280 */
if(!s->budget--) { s->failed_pc=0x0c075280u; return 0; }
goto P_0c07540e;
P_0c075282: /* original 0009, guest PC 0x0c075282 */
if(!s->budget--) { s->failed_pc=0x0c075282u; return 0; }
goto P_0c075284;
P_0c075284: /* original 9070, guest PC 0x0c075284 */
if(!s->budget--) { s->failed_pc=0x0c075284u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c075368u,2);
goto P_0c075286;
P_0c075286: /* original e20c, guest PC 0x0c075286 */
if(!s->budget--) { s->failed_pc=0x0c075286u; return 0; }
r[2]=0x0000000cu;
goto P_0c075288;
P_0c075288: /* original 03fe, guest PC 0x0c075288 */
if(!s->budget--) { s->failed_pc=0x0c075288u; return 0; }
r[3]=read(ram,r[15]+r[0],4);
goto P_0c07528a;
P_0c07528a: /* original 9071, guest PC 0x0c07528a */
if(!s->budget--) { s->failed_pc=0x0c07528au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c075370u,2);
goto P_0c07528c;
P_0c07528c: /* original 0325, guest PC 0x0c07528c */
if(!s->budget--) { s->failed_pc=0x0c07528cu; return 0; }
write(ram,r[3]+r[0],r[2],2);
goto P_0c07528e;
P_0c07528e: /* original 906d, guest PC 0x0c07528e */
if(!s->budget--) { s->failed_pc=0x0c07528eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07536cu,2);
goto P_0c075290;
P_0c075290: /* original 03fe, guest PC 0x0c075290 */
if(!s->budget--) { s->failed_pc=0x0c075290u; return 0; }
r[3]=read(ram,r[15]+r[0],4);
goto P_0c075292;
P_0c075292: /* original 906e, guest PC 0x0c075292 */
if(!s->budget--) { s->failed_pc=0x0c075292u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c075372u,2);
goto P_0c075294;
P_0c075294: /* original 023c, guest PC 0x0c075294 */
if(!s->budget--) { s->failed_pc=0x0c075294u; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[3]+r[0],1);
goto P_0c075296;
P_0c075296: /* original 7216, guest PC 0x0c075296 */
if(!s->budget--) { s->failed_pc=0x0c075296u; return 0; }
r[2]+=0x00000016u;
goto P_0c075298;
P_0c075298: /* original 0324, guest PC 0x0c075298 */
if(!s->budget--) { s->failed_pc=0x0c075298u; return 0; }
write(ram,r[3]+r[0],r[2],1);
goto P_0c07529a;
P_0c07529a: /* original 9067, guest PC 0x0c07529a */
if(!s->budget--) { s->failed_pc=0x0c07529au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07536cu,2);
goto P_0c07529c;
P_0c07529c: /* original f29d, guest PC 0x0c07529c */
if(!s->budget--) { s->failed_pc=0x0c07529cu; return 0; }
fr[2]=0x3f800000u;
goto P_0c07529e;
P_0c07529e: /* original 03fe, guest PC 0x0c07529e */
if(!s->budget--) { s->failed_pc=0x0c07529eu; return 0; }
r[3]=read(ram,r[15]+r[0],4);
goto P_0c0752a0;
P_0c0752a0: /* original 9067, guest PC 0x0c0752a0 */
if(!s->budget--) { s->failed_pc=0x0c0752a0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c075372u,2);
goto P_0c0752a2;
P_0c0752a2: /* original 033c, guest PC 0x0c0752a2 */
if(!s->budget--) { s->failed_pc=0x0c0752a2u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[3]+r[0],1);
goto P_0c0752a4;
P_0c0752a4: /* original e030, guest PC 0x0c0752a4 */
if(!s->budget--) { s->failed_pc=0x0c0752a4u; return 0; }
r[0]=0x00000030u;
goto P_0c0752a6;
P_0c0752a6: /* original 633c, guest PC 0x0c0752a6 */
if(!s->budget--) { s->failed_pc=0x0c0752a6u; return 0; }
r[3]=r[3]&255u;
goto P_0c0752a8;
P_0c0752a8: /* original 435a, guest PC 0x0c0752a8 */
if(!s->budget--) { s->failed_pc=0x0c0752a8u; return 0; }
r[53]=r[3];
goto P_0c0752aa;
P_0c0752aa: /* original f32d, guest PC 0x0c0752aa */
if(!s->budget--) { s->failed_pc=0x0c0752aau; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c0752ac;
P_0c0752ac: /* original f233, guest PC 0x0c0752ac */
if(!s->budget--) { s->failed_pc=0x0c0752acu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'/');
goto P_0c0752ae;
P_0c0752ae: /* original ff27, guest PC 0x0c0752ae */
if(!s->budget--) { s->failed_pc=0x0c0752aeu; return 0; }
vf3_matrix_store(s,ram,2,r[15]+r[0]);
goto P_0c0752b0;
P_0c0752b0: /* original c738, guest PC 0x0c0752b0 */
if(!s->budget--) { s->failed_pc=0x0c0752b0u; return 0; }
r[0]=0x0c075394u;
goto P_0c0752b2;
P_0c0752b2: /* original f308, guest PC 0x0c0752b2 */
if(!s->budget--) { s->failed_pc=0x0c0752b2u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c0752b4;
P_0c0752b4: /* original e038, guest PC 0x0c0752b4 */
if(!s->budget--) { s->failed_pc=0x0c0752b4u; return 0; }
r[0]=0x00000038u;
goto P_0c0752b6;
P_0c0752b6: /* original ff37, guest PC 0x0c0752b6 */
if(!s->budget--) { s->failed_pc=0x0c0752b6u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0752b8;
P_0c0752b8: /* original c737, guest PC 0x0c0752b8 */
if(!s->budget--) { s->failed_pc=0x0c0752b8u; return 0; }
r[0]=0x0c075398u;
goto P_0c0752ba;
P_0c0752ba: /* original f308, guest PC 0x0c0752ba */
if(!s->budget--) { s->failed_pc=0x0c0752bau; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c0752bc;
P_0c0752bc: /* original e024, guest PC 0x0c0752bc */
if(!s->budget--) { s->failed_pc=0x0c0752bcu; return 0; }
r[0]=0x00000024u;
goto P_0c0752be;
P_0c0752be: /* original ff37, guest PC 0x0c0752be */
if(!s->budget--) { s->failed_pc=0x0c0752beu; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0752c0;
P_0c0752c0: /* original c736, guest PC 0x0c0752c0 */
if(!s->budget--) { s->failed_pc=0x0c0752c0u; return 0; }
r[0]=0x0c07539cu;
goto P_0c0752c2;
P_0c0752c2: /* original f308, guest PC 0x0c0752c2 */
if(!s->budget--) { s->failed_pc=0x0c0752c2u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c0752c4;
P_0c0752c4: /* original e034, guest PC 0x0c0752c4 */
if(!s->budget--) { s->failed_pc=0x0c0752c4u; return 0; }
r[0]=0x00000034u;
goto P_0c0752c6;
P_0c0752c6: /* original ff37, guest PC 0x0c0752c6 */
if(!s->budget--) { s->failed_pc=0x0c0752c6u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0752c8;
P_0c0752c8: /* original c732, guest PC 0x0c0752c8 */
if(!s->budget--) { s->failed_pc=0x0c0752c8u; return 0; }
r[0]=0x0c075394u;
goto P_0c0752ca;
P_0c0752ca: /* original f308, guest PC 0x0c0752ca */
if(!s->budget--) { s->failed_pc=0x0c0752cau; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c0752cc;
P_0c0752cc: /* original e02c, guest PC 0x0c0752cc */
if(!s->budget--) { s->failed_pc=0x0c0752ccu; return 0; }
r[0]=0x0000002cu;
goto P_0c0752ce;
P_0c0752ce: /* original e301, guest PC 0x0c0752ce */
if(!s->budget--) { s->failed_pc=0x0c0752ceu; return 0; }
r[3]=0x00000001u;
goto P_0c0752d0;
P_0c0752d0: /* original ff37, guest PC 0x0c0752d0 */
if(!s->budget--) { s->failed_pc=0x0c0752d0u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0752d2;
P_0c0752d2: /* original c733, guest PC 0x0c0752d2 */
if(!s->budget--) { s->failed_pc=0x0c0752d2u; return 0; }
r[0]=0x0c0753a0u;
goto P_0c0752d4;
P_0c0752d4: /* original f308, guest PC 0x0c0752d4 */
if(!s->budget--) { s->failed_pc=0x0c0752d4u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c0752d6;
P_0c0752d6: /* original e028, guest PC 0x0c0752d6 */
if(!s->budget--) { s->failed_pc=0x0c0752d6u; return 0; }
r[0]=0x00000028u;
goto P_0c0752d8;
P_0c0752d8: /* original ff37, guest PC 0x0c0752d8 */
if(!s->budget--) { s->failed_pc=0x0c0752d8u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0752da;
P_0c0752da: /* original 904b, guest PC 0x0c0752da */
if(!s->budget--) { s->failed_pc=0x0c0752dau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c075374u,2);
goto P_0c0752dc;
P_0c0752dc: /* original 0f36, guest PC 0x0c0752dc */
if(!s->budget--) { s->failed_pc=0x0c0752dcu; return 0; }
write(ram,r[15]+r[0],r[3],4);
goto P_0c0752de;
P_0c0752de: /* original 52f5, guest PC 0x0c0752de */
if(!s->budget--) { s->failed_pc=0x0c0752deu; return 0; }
r[2]=read(ram,r[15]+20,4);
goto P_0c0752e0;
P_0c0752e0: /* original d330, guest PC 0x0c0752e0 */
if(!s->budget--) { s->failed_pc=0x0c0752e0u; return 0; }
r[3]=read(ram,0x0c0753a4u,4);
goto P_0c0752e2;
P_0c0752e2: /* original 2238, guest PC 0x0c0752e2 */
if(!s->budget--) { s->failed_pc=0x0c0752e2u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0752e4;
P_0c0752e4: /* original 8b0c, guest PC 0x0c0752e4 */
if(!s->budget--) { s->failed_pc=0x0c0752e4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c075300; }
goto P_0c0752e6;
P_0c0752e6: /* original e038, guest PC 0x0c0752e6 */
if(!s->budget--) { s->failed_pc=0x0c0752e6u; return 0; }
r[0]=0x00000038u;
goto P_0c0752e8;
P_0c0752e8: /* original f3f6, guest PC 0x0c0752e8 */
if(!s->budget--) { s->failed_pc=0x0c0752e8u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0752ea;
P_0c0752ea: /* original e038, guest PC 0x0c0752ea */
if(!s->budget--) { s->failed_pc=0x0c0752eau; return 0; }
r[0]=0x00000038u;
goto P_0c0752ec;
P_0c0752ec: /* original e202, guest PC 0x0c0752ec */
if(!s->budget--) { s->failed_pc=0x0c0752ecu; return 0; }
r[2]=0x00000002u;
goto P_0c0752ee;
P_0c0752ee: /* original f34d, guest PC 0x0c0752ee */
if(!s->budget--) { s->failed_pc=0x0c0752eeu; return 0; }
fr[3]^=0x80000000u;
goto P_0c0752f0;
P_0c0752f0: /* original ff37, guest PC 0x0c0752f0 */
if(!s->budget--) { s->failed_pc=0x0c0752f0u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0752f2;
P_0c0752f2: /* original e02c, guest PC 0x0c0752f2 */
if(!s->budget--) { s->failed_pc=0x0c0752f2u; return 0; }
r[0]=0x0000002cu;
goto P_0c0752f4;
P_0c0752f4: /* original f1f6, guest PC 0x0c0752f4 */
if(!s->budget--) { s->failed_pc=0x0c0752f4u; return 0; }
vf3_matrix_load(s,ram,1,r[15]+r[0]);
goto P_0c0752f6;
P_0c0752f6: /* original e02c, guest PC 0x0c0752f6 */
if(!s->budget--) { s->failed_pc=0x0c0752f6u; return 0; }
r[0]=0x0000002cu;
goto P_0c0752f8;
P_0c0752f8: /* original f14d, guest PC 0x0c0752f8 */
if(!s->budget--) { s->failed_pc=0x0c0752f8u; return 0; }
fr[1]^=0x80000000u;
goto P_0c0752fa;
P_0c0752fa: /* original ff17, guest PC 0x0c0752fa */
if(!s->budget--) { s->failed_pc=0x0c0752fau; return 0; }
vf3_matrix_store(s,ram,1,r[15]+r[0]);
goto P_0c0752fc;
P_0c0752fc: /* original 903a, guest PC 0x0c0752fc */
if(!s->budget--) { s->failed_pc=0x0c0752fcu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c075374u,2);
goto P_0c0752fe;
P_0c0752fe: /* original 0f26, guest PC 0x0c0752fe */
if(!s->budget--) { s->failed_pc=0x0c0752feu; return 0; }
write(ram,r[15]+r[0],r[2],4);
goto P_0c075300;
P_0c075300: /* original 9034, guest PC 0x0c075300 */
if(!s->budget--) { s->failed_pc=0x0c075300u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07536cu,2);
goto P_0c075302;
P_0c075302: /* original 03fe, guest PC 0x0c075302 */
if(!s->budget--) { s->failed_pc=0x0c075302u; return 0; }
r[3]=read(ram,r[15]+r[0],4);
goto P_0c075304;
P_0c075304: /* original 9036, guest PC 0x0c075304 */
if(!s->budget--) { s->failed_pc=0x0c075304u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c075374u,2);
goto P_0c075306;
P_0c075306: /* original 02fc, guest PC 0x0c075306 */
if(!s->budget--) { s->failed_pc=0x0c075306u; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[15]+r[0],1);
goto P_0c075308;
P_0c075308: /* original 9035, guest PC 0x0c075308 */
if(!s->budget--) { s->failed_pc=0x0c075308u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c075376u,2);
goto P_0c07530a;
P_0c07530a: /* original 0324, guest PC 0x0c07530a */
if(!s->budget--) { s->failed_pc=0x0c07530au; return 0; }
write(ram,r[3]+r[0],r[2],1);
goto P_0c07530c;
P_0c07530c: /* original e030, guest PC 0x0c07530c */
if(!s->budget--) { s->failed_pc=0x0c07530cu; return 0; }
r[0]=0x00000030u;
goto P_0c07530e;
P_0c07530e: /* original f3f6, guest PC 0x0c07530e */
if(!s->budget--) { s->failed_pc=0x0c07530eu; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c075310;
P_0c075310: /* original e038, guest PC 0x0c075310 */
if(!s->budget--) { s->failed_pc=0x0c075310u; return 0; }
r[0]=0x00000038u;
goto P_0c075312;
P_0c075312: /* original f2f6, guest PC 0x0c075312 */
if(!s->budget--) { s->failed_pc=0x0c075312u; return 0; }
vf3_matrix_load(s,ram,2,r[15]+r[0]);
goto P_0c075314;
P_0c075314: /* original e038, guest PC 0x0c075314 */
if(!s->budget--) { s->failed_pc=0x0c075314u; return 0; }
r[0]=0x00000038u;
goto P_0c075316;
P_0c075316: /* original f232, guest PC 0x0c075316 */
if(!s->budget--) { s->failed_pc=0x0c075316u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c075318;
P_0c075318: /* original ff27, guest PC 0x0c075318 */
if(!s->budget--) { s->failed_pc=0x0c075318u; return 0; }
vf3_matrix_store(s,ram,2,r[15]+r[0]);
goto P_0c07531a;
P_0c07531a: /* original e034, guest PC 0x0c07531a */
if(!s->budget--) { s->failed_pc=0x0c07531au; return 0; }
r[0]=0x00000034u;
goto P_0c07531c;
P_0c07531c: /* original f1f6, guest PC 0x0c07531c */
if(!s->budget--) { s->failed_pc=0x0c07531cu; return 0; }
vf3_matrix_load(s,ram,1,r[15]+r[0]);
goto P_0c07531e;
P_0c07531e: /* original e034, guest PC 0x0c07531e */
if(!s->budget--) { s->failed_pc=0x0c07531eu; return 0; }
r[0]=0x00000034u;
goto P_0c075320;
P_0c075320: /* original f132, guest PC 0x0c075320 */
if(!s->budget--) { s->failed_pc=0x0c075320u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[3],r[18],'*');
goto P_0c075322;
P_0c075322: /* original ff17, guest PC 0x0c075322 */
if(!s->budget--) { s->failed_pc=0x0c075322u; return 0; }
vf3_matrix_store(s,ram,1,r[15]+r[0]);
goto P_0c075324;
P_0c075324: /* original e030, guest PC 0x0c075324 */
if(!s->budget--) { s->failed_pc=0x0c075324u; return 0; }
r[0]=0x00000030u;
goto P_0c075326;
P_0c075326: /* original f3f6, guest PC 0x0c075326 */
if(!s->budget--) { s->failed_pc=0x0c075326u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c075328;
P_0c075328: /* original e02c, guest PC 0x0c075328 */
if(!s->budget--) { s->failed_pc=0x0c075328u; return 0; }
r[0]=0x0000002cu;
goto P_0c07532a;
P_0c07532a: /* original f1f6, guest PC 0x0c07532a */
if(!s->budget--) { s->failed_pc=0x0c07532au; return 0; }
vf3_matrix_load(s,ram,1,r[15]+r[0]);
goto P_0c07532c;
P_0c07532c: /* original e02c, guest PC 0x0c07532c */
if(!s->budget--) { s->failed_pc=0x0c07532cu; return 0; }
r[0]=0x0000002cu;
goto P_0c07532e;
P_0c07532e: /* original f132, guest PC 0x0c07532e */
if(!s->budget--) { s->failed_pc=0x0c07532eu; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[3],r[18],'*');
goto P_0c075330;
P_0c075330: /* original ff17, guest PC 0x0c075330 */
if(!s->budget--) { s->failed_pc=0x0c075330u; return 0; }
vf3_matrix_store(s,ram,1,r[15]+r[0]);
goto P_0c075332;
P_0c075332: /* original e028, guest PC 0x0c075332 */
if(!s->budget--) { s->failed_pc=0x0c075332u; return 0; }
r[0]=0x00000028u;
goto P_0c075334;
P_0c075334: /* original f2f6, guest PC 0x0c075334 */
if(!s->budget--) { s->failed_pc=0x0c075334u; return 0; }
vf3_matrix_load(s,ram,2,r[15]+r[0]);
goto P_0c075336;
P_0c075336: /* original e028, guest PC 0x0c075336 */
if(!s->budget--) { s->failed_pc=0x0c075336u; return 0; }
r[0]=0x00000028u;
goto P_0c075338;
P_0c075338: /* original f232, guest PC 0x0c075338 */
if(!s->budget--) { s->failed_pc=0x0c075338u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c07533a;
P_0c07533a: /* original ff27, guest PC 0x0c07533a */
if(!s->budget--) { s->failed_pc=0x0c07533au; return 0; }
vf3_matrix_store(s,ram,2,r[15]+r[0]);
goto P_0c07533c;
P_0c07533c: /* original e030, guest PC 0x0c07533c */
if(!s->budget--) { s->failed_pc=0x0c07533cu; return 0; }
r[0]=0x00000030u;
goto P_0c07533e;
P_0c07533e: /* original f3f6, guest PC 0x0c07533e */
if(!s->budget--) { s->failed_pc=0x0c07533eu; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c075340;
P_0c075340: /* original e024, guest PC 0x0c075340 */
if(!s->budget--) { s->failed_pc=0x0c075340u; return 0; }
r[0]=0x00000024u;
goto P_0c075342;
P_0c075342: /* original 65f3, guest PC 0x0c075342 */
if(!s->budget--) { s->failed_pc=0x0c075342u; return 0; }
r[5]=r[15];
goto P_0c075344;
P_0c075344: /* original f2f6, guest PC 0x0c075344 */
if(!s->budget--) { s->failed_pc=0x0c075344u; return 0; }
vf3_matrix_load(s,ram,2,r[15]+r[0]);
goto P_0c075346;
P_0c075346: /* original e024, guest PC 0x0c075346 */
if(!s->budget--) { s->failed_pc=0x0c075346u; return 0; }
r[0]=0x00000024u;
goto P_0c075348;
P_0c075348: /* original 66f3, guest PC 0x0c075348 */
if(!s->budget--) { s->failed_pc=0x0c075348u; return 0; }
r[6]=r[15];
goto P_0c07534a;
P_0c07534a: /* original 7634, guest PC 0x0c07534a */
if(!s->budget--) { s->failed_pc=0x0c07534au; return 0; }
r[6]+=0x00000034u;
goto P_0c07534c;
P_0c07534c: /* original f232, guest PC 0x0c07534c */
if(!s->budget--) { s->failed_pc=0x0c07534cu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c07534e;
P_0c07534e: /* original 7538, guest PC 0x0c07534e */
if(!s->budget--) { s->failed_pc=0x0c07534eu; return 0; }
r[5]+=0x00000038u;
goto P_0c075350;
P_0c075350: /* original ff27, guest PC 0x0c075350 */
if(!s->budget--) { s->failed_pc=0x0c075350u; return 0; }
vf3_matrix_store(s,ram,2,r[15]+r[0]);
goto P_0c075352;
P_0c075352: /* original 900b, guest PC 0x0c075352 */
if(!s->budget--) { s->failed_pc=0x0c075352u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07536cu,2);
goto P_0c075354;
P_0c075354: /* original 9110, guest PC 0x0c075354 */
if(!s->budget--) { s->failed_pc=0x0c075354u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c075378u,2);
goto P_0c075356;
P_0c075356: /* original 00fe, guest PC 0x0c075356 */
if(!s->budget--) { s->failed_pc=0x0c075356u; return 0; }
r[0]=read(ram,r[15]+r[0],4);
goto P_0c075358;
P_0c075358: /* original 001d, guest PC 0x0c075358 */
if(!s->budget--) { s->failed_pc=0x0c075358u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[1]+r[0],2);
goto P_0c07535a;
P_0c07535a: /* original 81f9, guest PC 0x0c07535a */
if(!s->budget--) { s->failed_pc=0x0c07535au; return 0; }
write(ram,r[15]+18,r[0],2);
goto P_0c07535c;
P_0c07535c: /* original 85f9, guest PC 0x0c07535c */
if(!s->budget--) { s->failed_pc=0x0c07535cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+18,2);
goto P_0c07535e;
P_0c07535e: /* original d312, guest PC 0x0c07535e */
if(!s->budget--) { s->failed_pc=0x0c07535eu; return 0; }
r[3]=read(ram,0x0c0753a8u,4);
goto P_0c075360;
P_0c075360: /* original 430b, guest PC 0x0c075360 */
if(!s->budget--) { s->failed_pc=0x0c075360u; return 0; }
target=r[3];
r[16]=0x0c075364u;
r[4]=r[0];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c075364u) { target=s->pc; goto dispatch; }
goto P_0c075364;
P_0c075362: /* original 6403, guest PC 0x0c075362 */
if(!s->budget--) { s->failed_pc=0x0c075362u; return 0; }
r[4]=r[0];
goto P_0c075364;
P_0c075364: /* original a022, guest PC 0x0c075364 */
if(!s->budget--) { s->failed_pc=0x0c075364u; return 0; }
goto P_0c0753ac;
P_0c075366: /* original 0009, guest PC 0x0c075366 */
if(!s->budget--) { s->failed_pc=0x0c075366u; return 0; }
return vf3_matrix_family(0x0c075368u,s,ram);
P_0c0753ac: /* original 9057, guest PC 0x0c0753ac */
if(!s->budget--) { s->failed_pc=0x0c0753acu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07545eu,2);
goto P_0c0753ae;
P_0c0753ae: /* original 65f3, guest PC 0x0c0753ae */
if(!s->budget--) { s->failed_pc=0x0c0753aeu; return 0; }
r[5]=r[15];
goto P_0c0753b0;
P_0c0753b0: /* original 66f3, guest PC 0x0c0753b0 */
if(!s->budget--) { s->failed_pc=0x0c0753b0u; return 0; }
r[6]=r[15];
goto P_0c0753b2;
P_0c0753b2: /* original 7628, guest PC 0x0c0753b2 */
if(!s->budget--) { s->failed_pc=0x0c0753b2u; return 0; }
r[6]+=0x00000028u;
goto P_0c0753b4;
P_0c0753b4: /* original 02fe, guest PC 0x0c0753b4 */
if(!s->budget--) { s->failed_pc=0x0c0753b4u; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c0753b6;
P_0c0753b6: /* original e038, guest PC 0x0c0753b6 */
if(!s->budget--) { s->failed_pc=0x0c0753b6u; return 0; }
r[0]=0x00000038u;
goto P_0c0753b8;
P_0c0753b8: /* original f3f6, guest PC 0x0c0753b8 */
if(!s->budget--) { s->failed_pc=0x0c0753b8u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0753ba;
P_0c0753ba: /* original 752c, guest PC 0x0c0753ba */
if(!s->budget--) { s->failed_pc=0x0c0753bau; return 0; }
r[5]+=0x0000002cu;
goto P_0c0753bc;
P_0c0753bc: /* original 9050, guest PC 0x0c0753bc */
if(!s->budget--) { s->failed_pc=0x0c0753bcu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c075460u,2);
goto P_0c0753be;
P_0c0753be: /* original f237, guest PC 0x0c0753be */
if(!s->budget--) { s->failed_pc=0x0c0753beu; return 0; }
vf3_matrix_store(s,ram,3,r[2]+r[0]);
goto P_0c0753c0;
P_0c0753c0: /* original 904d, guest PC 0x0c0753c0 */
if(!s->budget--) { s->failed_pc=0x0c0753c0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07545eu,2);
goto P_0c0753c2;
P_0c0753c2: /* original 03fe, guest PC 0x0c0753c2 */
if(!s->budget--) { s->failed_pc=0x0c0753c2u; return 0; }
r[3]=read(ram,r[15]+r[0],4);
goto P_0c0753c4;
P_0c0753c4: /* original e034, guest PC 0x0c0753c4 */
if(!s->budget--) { s->failed_pc=0x0c0753c4u; return 0; }
r[0]=0x00000034u;
goto P_0c0753c6;
P_0c0753c6: /* original f3f6, guest PC 0x0c0753c6 */
if(!s->budget--) { s->failed_pc=0x0c0753c6u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0753c8;
P_0c0753c8: /* original 904b, guest PC 0x0c0753c8 */
if(!s->budget--) { s->failed_pc=0x0c0753c8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c075462u,2);
goto P_0c0753ca;
P_0c0753ca: /* original f337, guest PC 0x0c0753ca */
if(!s->budget--) { s->failed_pc=0x0c0753cau; return 0; }
vf3_matrix_store(s,ram,3,r[3]+r[0]);
goto P_0c0753cc;
P_0c0753cc: /* original 85f9, guest PC 0x0c0753cc */
if(!s->budget--) { s->failed_pc=0x0c0753ccu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+18,2);
goto P_0c0753ce;
P_0c0753ce: /* original d329, guest PC 0x0c0753ce */
if(!s->budget--) { s->failed_pc=0x0c0753ceu; return 0; }
r[3]=read(ram,0x0c075474u,4);
goto P_0c0753d0;
P_0c0753d0: /* original 430b, guest PC 0x0c0753d0 */
if(!s->budget--) { s->failed_pc=0x0c0753d0u; return 0; }
target=r[3];
r[16]=0x0c0753d4u;
r[4]=r[0];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0753d4u) { target=s->pc; goto dispatch; }
goto P_0c0753d4;
P_0c0753d2: /* original 6403, guest PC 0x0c0753d2 */
if(!s->budget--) { s->failed_pc=0x0c0753d2u; return 0; }
r[4]=r[0];
goto P_0c0753d4;
P_0c0753d4: /* original 9043, guest PC 0x0c0753d4 */
if(!s->budget--) { s->failed_pc=0x0c0753d4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07545eu,2);
goto P_0c0753d6;
P_0c0753d6: /* original 02fe, guest PC 0x0c0753d6 */
if(!s->budget--) { s->failed_pc=0x0c0753d6u; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c0753d8;
P_0c0753d8: /* original e02c, guest PC 0x0c0753d8 */
if(!s->budget--) { s->failed_pc=0x0c0753d8u; return 0; }
r[0]=0x0000002cu;
goto P_0c0753da;
P_0c0753da: /* original f3f6, guest PC 0x0c0753da */
if(!s->budget--) { s->failed_pc=0x0c0753dau; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0753dc;
P_0c0753dc: /* original 9042, guest PC 0x0c0753dc */
if(!s->budget--) { s->failed_pc=0x0c0753dcu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c075464u,2);
goto P_0c0753de;
P_0c0753de: /* original f237, guest PC 0x0c0753de */
if(!s->budget--) { s->failed_pc=0x0c0753deu; return 0; }
vf3_matrix_store(s,ram,3,r[2]+r[0]);
goto P_0c0753e0;
P_0c0753e0: /* original 903d, guest PC 0x0c0753e0 */
if(!s->budget--) { s->failed_pc=0x0c0753e0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07545eu,2);
goto P_0c0753e2;
P_0c0753e2: /* original 03fe, guest PC 0x0c0753e2 */
if(!s->budget--) { s->failed_pc=0x0c0753e2u; return 0; }
r[3]=read(ram,r[15]+r[0],4);
goto P_0c0753e4;
P_0c0753e4: /* original e028, guest PC 0x0c0753e4 */
if(!s->budget--) { s->failed_pc=0x0c0753e4u; return 0; }
r[0]=0x00000028u;
goto P_0c0753e6;
P_0c0753e6: /* original f3f6, guest PC 0x0c0753e6 */
if(!s->budget--) { s->failed_pc=0x0c0753e6u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0753e8;
P_0c0753e8: /* original 903d, guest PC 0x0c0753e8 */
if(!s->budget--) { s->failed_pc=0x0c0753e8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c075466u,2);
goto P_0c0753ea;
P_0c0753ea: /* original f337, guest PC 0x0c0753ea */
if(!s->budget--) { s->failed_pc=0x0c0753eau; return 0; }
vf3_matrix_store(s,ram,3,r[3]+r[0]);
goto P_0c0753ec;
P_0c0753ec: /* original 9037, guest PC 0x0c0753ec */
if(!s->budget--) { s->failed_pc=0x0c0753ecu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07545eu,2);
goto P_0c0753ee;
P_0c0753ee: /* original 03fe, guest PC 0x0c0753ee */
if(!s->budget--) { s->failed_pc=0x0c0753eeu; return 0; }
r[3]=read(ram,r[15]+r[0],4);
goto P_0c0753f0;
P_0c0753f0: /* original e024, guest PC 0x0c0753f0 */
if(!s->budget--) { s->failed_pc=0x0c0753f0u; return 0; }
r[0]=0x00000024u;
goto P_0c0753f2;
P_0c0753f2: /* original f3f6, guest PC 0x0c0753f2 */
if(!s->budget--) { s->failed_pc=0x0c0753f2u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0753f4;
P_0c0753f4: /* original 9038, guest PC 0x0c0753f4 */
if(!s->budget--) { s->failed_pc=0x0c0753f4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c075468u,2);
goto P_0c0753f6;
P_0c0753f6: /* original f337, guest PC 0x0c0753f6 */
if(!s->budget--) { s->failed_pc=0x0c0753f6u; return 0; }
vf3_matrix_store(s,ram,3,r[3]+r[0]);
goto P_0c0753f8;
P_0c0753f8: /* original 9031, guest PC 0x0c0753f8 */
if(!s->budget--) { s->failed_pc=0x0c0753f8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07545eu,2);
goto P_0c0753fa;
P_0c0753fa: /* original 9236, guest PC 0x0c0753fa */
if(!s->budget--) { s->failed_pc=0x0c0753fau; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07546au,2);
goto P_0c0753fc;
P_0c0753fc: /* original 03fe, guest PC 0x0c0753fc */
if(!s->budget--) { s->failed_pc=0x0c0753fcu; return 0; }
r[3]=read(ram,r[15]+r[0],4);
goto P_0c0753fe;
P_0c0753fe: /* original e042, guest PC 0x0c0753fe */
if(!s->budget--) { s->failed_pc=0x0c0753feu; return 0; }
r[0]=0x00000042u;
goto P_0c075400;
P_0c075400: /* original 0325, guest PC 0x0c075400 */
if(!s->budget--) { s->failed_pc=0x0c075400u; return 0; }
write(ram,r[3]+r[0],r[2],2);
goto P_0c075402;
P_0c075402: /* original 9133, guest PC 0x0c075402 */
if(!s->budget--) { s->failed_pc=0x0c075402u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07546cu,2);
goto P_0c075404;
P_0c075404: /* original 3f1c, guest PC 0x0c075404 */
if(!s->budget--) { s->failed_pc=0x0c075404u; return 0; }
r[15]+=r[1];
goto P_0c075406;
P_0c075406: /* original 4f16, guest PC 0x0c075406 */
if(!s->budget--) { s->failed_pc=0x0c075406u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c075408;
P_0c075408: /* original 4f26, guest PC 0x0c075408 */
if(!s->budget--) { s->failed_pc=0x0c075408u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c07540a;
P_0c07540a: /* original 000b, guest PC 0x0c07540a */
if(!s->budget--) { s->failed_pc=0x0c07540au; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c07540c: /* original 0009, guest PC 0x0c07540c */
if(!s->budget--) { s->failed_pc=0x0c07540cu; return 0; }
goto P_0c07540e;
P_0c07540e: /* original 9026, guest PC 0x0c07540e */
if(!s->budget--) { s->failed_pc=0x0c07540eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07545eu,2);
goto P_0c075410;
P_0c075410: /* original 01fe, guest PC 0x0c075410 */
if(!s->budget--) { s->failed_pc=0x0c075410u; return 0; }
r[1]=read(ram,r[15]+r[0],4);
goto P_0c075412;
P_0c075412: /* original 902c, guest PC 0x0c075412 */
if(!s->budget--) { s->failed_pc=0x0c075412u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07546eu,2);
goto P_0c075414;
P_0c075414: /* original 6213, guest PC 0x0c075414 */
if(!s->budget--) { s->failed_pc=0x0c075414u; return 0; }
r[2]=r[1];
goto P_0c075416;
P_0c075416: /* original 031d, guest PC 0x0c075416 */
if(!s->budget--) { s->failed_pc=0x0c075416u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[1]+r[0],2);
goto P_0c075418;
P_0c075418: /* original 852f, guest PC 0x0c075418 */
if(!s->budget--) { s->failed_pc=0x0c075418u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[2]+30,2);
goto P_0c07541a;
P_0c07541a: /* original 330c, guest PC 0x0c07541a */
if(!s->budget--) { s->failed_pc=0x0c07541au; return 0; }
r[3]+=r[0];
goto P_0c07541c;
P_0c07541c: /* original e058, guest PC 0x0c07541c */
if(!s->budget--) { s->failed_pc=0x0c07541cu; return 0; }
r[0]=0x00000058u;
goto P_0c07541e;
P_0c07541e: /* original 0f36, guest PC 0x0c07541e */
if(!s->budget--) { s->failed_pc=0x0c07541eu; return 0; }
write(ram,r[15]+r[0],r[3],4);
goto P_0c075420;
P_0c075420: /* original 9026, guest PC 0x0c075420 */
if(!s->budget--) { s->failed_pc=0x0c075420u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c075470u,2);
goto P_0c075422;
P_0c075422: /* original 02fe, guest PC 0x0c075422 */
if(!s->budget--) { s->failed_pc=0x0c075422u; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c075424;
P_0c075424: /* original 9025, guest PC 0x0c075424 */
if(!s->budget--) { s->failed_pc=0x0c075424u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c075472u,2);
goto P_0c075426;
P_0c075426: /* original 032c, guest PC 0x0c075426 */
if(!s->budget--) { s->failed_pc=0x0c075426u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[2]+r[0],1);
goto P_0c075428;
P_0c075428: /* original e068, guest PC 0x0c075428 */
if(!s->budget--) { s->failed_pc=0x0c075428u; return 0; }
r[0]=0x00000068u;
goto P_0c07542a;
P_0c07542a: /* original 633c, guest PC 0x0c07542a */
if(!s->budget--) { s->failed_pc=0x0c07542au; return 0; }
r[3]=r[3]&255u;
goto P_0c07542c;
P_0c07542c: /* original 0f36, guest PC 0x0c07542c */
if(!s->budget--) { s->failed_pc=0x0c07542cu; return 0; }
write(ram,r[15]+r[0],r[3],4);
goto P_0c07542e;
P_0c07542e: /* original 9016, guest PC 0x0c07542e */
if(!s->budget--) { s->failed_pc=0x0c07542eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07545eu,2);
goto P_0c075430;
P_0c075430: /* original 02fe, guest PC 0x0c075430 */
if(!s->budget--) { s->failed_pc=0x0c075430u; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c075432;
P_0c075432: /* original 901e, guest PC 0x0c075432 */
if(!s->budget--) { s->failed_pc=0x0c075432u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c075472u,2);
goto P_0c075434;
P_0c075434: /* original 032c, guest PC 0x0c075434 */
if(!s->budget--) { s->failed_pc=0x0c075434u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[2]+r[0],1);
goto P_0c075436;
P_0c075436: /* original e054, guest PC 0x0c075436 */
if(!s->budget--) { s->failed_pc=0x0c075436u; return 0; }
r[0]=0x00000054u;
goto P_0c075438;
P_0c075438: /* original 633c, guest PC 0x0c075438 */
if(!s->budget--) { s->failed_pc=0x0c075438u; return 0; }
r[3]=r[3]&255u;
goto P_0c07543a;
P_0c07543a: /* original 4311, guest PC 0x0c07543a */
if(!s->budget--) { s->failed_pc=0x0c07543au; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>=0)!=0);
goto P_0c07543c;
P_0c07543c: /* original 0f36, guest PC 0x0c07543c */
if(!s->budget--) { s->failed_pc=0x0c07543cu; return 0; }
write(ram,r[15]+r[0],r[3],4);
goto P_0c07543e;
P_0c07543e: /* original 435a, guest PC 0x0c07543e */
if(!s->budget--) { s->failed_pc=0x0c07543eu; return 0; }
r[53]=r[3];
goto P_0c075440;
P_0c075440: /* original 8d04, guest PC 0x0c075440 */
if(!s->budget--) { s->failed_pc=0x0c075440u; return 0; }
cond=r[17]&1u;
fr[3]=vf3_fpu_float(r[53],r[18]);
if(cond) { goto P_0c07544c; }
goto P_0c075444;
P_0c075442: /* original f32d, guest PC 0x0c075442 */
if(!s->budget--) { s->failed_pc=0x0c075442u; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c075444;
P_0c075444: /* original d20c, guest PC 0x0c075444 */
if(!s->budget--) { s->failed_pc=0x0c075444u; return 0; }
r[2]=read(ram,0x0c075478u,4);
goto P_0c075446;
P_0c075446: /* original 425a, guest PC 0x0c075446 */
if(!s->budget--) { s->failed_pc=0x0c075446u; return 0; }
r[53]=r[2];
goto P_0c075448;
P_0c075448: /* original f20d, guest PC 0x0c075448 */
if(!s->budget--) { s->failed_pc=0x0c075448u; return 0; }
fr[2]=r[53];
goto P_0c07544a;
P_0c07544a: /* original f320, guest PC 0x0c07544a */
if(!s->budget--) { s->failed_pc=0x0c07544au; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[2],r[18],'+');
goto P_0c07544c;
P_0c07544c: /* original c70b, guest PC 0x0c07544c */
if(!s->budget--) { s->failed_pc=0x0c07544cu; return 0; }
r[0]=0x0c07547cu;
goto P_0c07544e;
P_0c07544e: /* original f208, guest PC 0x0c07544e */
if(!s->budget--) { s->failed_pc=0x0c07544eu; return 0; }
vf3_matrix_load(s,ram,2,r[0]);
goto P_0c075450;
P_0c075450: /* original c70b, guest PC 0x0c075450 */
if(!s->budget--) { s->failed_pc=0x0c075450u; return 0; }
r[0]=0x0c075480u;
goto P_0c075452;
P_0c075452: /* original f322, guest PC 0x0c075452 */
if(!s->budget--) { s->failed_pc=0x0c075452u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[2],r[18],'*');
goto P_0c075454;
P_0c075454: /* original f208, guest PC 0x0c075454 */
if(!s->budget--) { s->failed_pc=0x0c075454u; return 0; }
vf3_matrix_load(s,ram,2,r[0]);
goto P_0c075456;
P_0c075456: /* original f235, guest PC 0x0c075456 */
if(!s->budget--) { s->failed_pc=0x0c075456u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[2])>as_float(fr[3]))!=0);
goto P_0c075458;
P_0c075458: /* original 8b14, guest PC 0x0c075458 */
if(!s->budget--) { s->failed_pc=0x0c075458u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c075484; }
goto P_0c07545a;
P_0c07545a: /* original a021, guest PC 0x0c07545a */
if(!s->budget--) { s->failed_pc=0x0c07545au; return 0; }
fr[3]=0;
goto P_0c0754a0;
P_0c07545c: /* original f38d, guest PC 0x0c07545c */
if(!s->budget--) { s->failed_pc=0x0c07545cu; return 0; }
fr[3]=0;
return vf3_matrix_family(0x0c07545eu,s,ram);
P_0c075484: /* original e054, guest PC 0x0c075484 */
if(!s->budget--) { s->failed_pc=0x0c075484u; return 0; }
r[0]=0x00000054u;
goto P_0c075486;
P_0c075486: /* original 02fe, guest PC 0x0c075486 */
if(!s->budget--) { s->failed_pc=0x0c075486u; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c075488;
P_0c075488: /* original 425a, guest PC 0x0c075488 */
if(!s->budget--) { s->failed_pc=0x0c075488u; return 0; }
r[53]=r[2];
goto P_0c07548a;
P_0c07548a: /* original 4211, guest PC 0x0c07548a */
if(!s->budget--) { s->failed_pc=0x0c07548au; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>=0)!=0);
goto P_0c07548c;
P_0c07548c: /* original 8d04, guest PC 0x0c07548c */
if(!s->budget--) { s->failed_pc=0x0c07548cu; return 0; }
cond=r[17]&1u;
fr[3]=vf3_fpu_float(r[53],r[18]);
if(cond) { goto P_0c075498; }
goto P_0c075490;
P_0c07548e: /* original f32d, guest PC 0x0c07548e */
if(!s->budget--) { s->failed_pc=0x0c07548eu; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c075490;
P_0c075490: /* original d341, guest PC 0x0c075490 */
if(!s->budget--) { s->failed_pc=0x0c075490u; return 0; }
r[3]=read(ram,0x0c075598u,4);
goto P_0c075492;
P_0c075492: /* original 435a, guest PC 0x0c075492 */
if(!s->budget--) { s->failed_pc=0x0c075492u; return 0; }
r[53]=r[3];
goto P_0c075494;
P_0c075494: /* original f20d, guest PC 0x0c075494 */
if(!s->budget--) { s->failed_pc=0x0c075494u; return 0; }
fr[2]=r[53];
goto P_0c075496;
P_0c075496: /* original f320, guest PC 0x0c075496 */
if(!s->budget--) { s->failed_pc=0x0c075496u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[2],r[18],'+');
goto P_0c075498;
P_0c075498: /* original c740, guest PC 0x0c075498 */
if(!s->budget--) { s->failed_pc=0x0c075498u; return 0; }
r[0]=0x0c07559cu;
goto P_0c07549a;
P_0c07549a: /* original f208, guest PC 0x0c07549a */
if(!s->budget--) { s->failed_pc=0x0c07549au; return 0; }
vf3_matrix_load(s,ram,2,r[0]);
goto P_0c07549c;
P_0c07549c: /* original f322, guest PC 0x0c07549c */
if(!s->budget--) { s->failed_pc=0x0c07549cu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[2],r[18],'*');
goto P_0c07549e;
P_0c07549e: /* original f36d, guest PC 0x0c07549e */
if(!s->budget--) { s->failed_pc=0x0c07549eu; return 0; }
fr[3]=vf3_fpu_sqrt(fr[3],r[18]);
goto P_0c0754a0;
P_0c0754a0: /* original c73f, guest PC 0x0c0754a0 */
if(!s->budget--) { s->failed_pc=0x0c0754a0u; return 0; }
r[0]=0x0c0755a0u;
goto P_0c0754a2;
P_0c0754a2: /* original f208, guest PC 0x0c0754a2 */
if(!s->budget--) { s->failed_pc=0x0c0754a2u; return 0; }
vf3_matrix_load(s,ram,2,r[0]);
goto P_0c0754a4;
P_0c0754a4: /* original e020, guest PC 0x0c0754a4 */
if(!s->budget--) { s->failed_pc=0x0c0754a4u; return 0; }
r[0]=0x00000020u;
goto P_0c0754a6;
P_0c0754a6: /* original f322, guest PC 0x0c0754a6 */
if(!s->budget--) { s->failed_pc=0x0c0754a6u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[2],r[18],'*');
goto P_0c0754a8;
P_0c0754a8: /* original ff37, guest PC 0x0c0754a8 */
if(!s->budget--) { s->failed_pc=0x0c0754a8u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0754aa;
P_0c0754aa: /* original 906e, guest PC 0x0c0754aa */
if(!s->budget--) { s->failed_pc=0x0c0754aau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07558au,2);
goto P_0c0754ac;
P_0c0754ac: /* original 03fe, guest PC 0x0c0754ac */
if(!s->budget--) { s->failed_pc=0x0c0754acu; return 0; }
r[3]=read(ram,r[15]+r[0],4);
goto P_0c0754ae;
P_0c0754ae: /* original 906d, guest PC 0x0c0754ae */
if(!s->budget--) { s->failed_pc=0x0c0754aeu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07558cu,2);
goto P_0c0754b0;
P_0c0754b0: /* original 023c, guest PC 0x0c0754b0 */
if(!s->budget--) { s->failed_pc=0x0c0754b0u; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[3]+r[0],1);
goto P_0c0754b2;
P_0c0754b2: /* original d33c, guest PC 0x0c0754b2 */
if(!s->budget--) { s->failed_pc=0x0c0754b2u; return 0; }
r[3]=read(ram,0x0c0755a4u,4);
goto P_0c0754b4;
P_0c0754b4: /* original 622c, guest PC 0x0c0754b4 */
if(!s->budget--) { s->failed_pc=0x0c0754b4u; return 0; }
r[2]=r[2]&255u;
goto P_0c0754b6;
P_0c0754b6: /* original 906a, guest PC 0x0c0754b6 */
if(!s->budget--) { s->failed_pc=0x0c0754b6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07558eu,2);
goto P_0c0754b8;
P_0c0754b8: /* original 4208, guest PC 0x0c0754b8 */
if(!s->budget--) { s->failed_pc=0x0c0754b8u; return 0; }
r[2]<<=2;
goto P_0c0754ba;
P_0c0754ba: /* original 4208, guest PC 0x0c0754ba */
if(!s->budget--) { s->failed_pc=0x0c0754bau; return 0; }
r[2]<<=2;
goto P_0c0754bc;
P_0c0754bc: /* original 4200, guest PC 0x0c0754bc */
if(!s->budget--) { s->failed_pc=0x0c0754bcu; return 0; }
r[17]=(r[17]&~1u)|((r[2]>>31)!=0);
r[2]<<=1;
goto P_0c0754be;
P_0c0754be: /* original 323c, guest PC 0x0c0754be */
if(!s->budget--) { s->failed_pc=0x0c0754beu; return 0; }
r[2]+=r[3];
goto P_0c0754c0;
P_0c0754c0: /* original 0f26, guest PC 0x0c0754c0 */
if(!s->budget--) { s->failed_pc=0x0c0754c0u; return 0; }
write(ram,r[15]+r[0],r[2],4);
goto P_0c0754c2;
P_0c0754c2: /* original e020, guest PC 0x0c0754c2 */
if(!s->budget--) { s->failed_pc=0x0c0754c2u; return 0; }
r[0]=0x00000020u;
goto P_0c0754c4;
P_0c0754c4: /* original f2f6, guest PC 0x0c0754c4 */
if(!s->budget--) { s->failed_pc=0x0c0754c4u; return 0; }
vf3_matrix_load(s,ram,2,r[15]+r[0]);
goto P_0c0754c6;
P_0c0754c6: /* original e020, guest PC 0x0c0754c6 */
if(!s->budget--) { s->failed_pc=0x0c0754c6u; return 0; }
r[0]=0x00000020u;
goto P_0c0754c8;
P_0c0754c8: /* original f328, guest PC 0x0c0754c8 */
if(!s->budget--) { s->failed_pc=0x0c0754c8u; return 0; }
vf3_matrix_load(s,ram,3,r[2]);
goto P_0c0754ca;
P_0c0754ca: /* original f232, guest PC 0x0c0754ca */
if(!s->budget--) { s->failed_pc=0x0c0754cau; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c0754cc;
P_0c0754cc: /* original ff27, guest PC 0x0c0754cc */
if(!s->budget--) { s->failed_pc=0x0c0754ccu; return 0; }
vf3_matrix_store(s,ram,2,r[15]+r[0]);
goto P_0c0754ce;
P_0c0754ce: /* original 905c, guest PC 0x0c0754ce */
if(!s->budget--) { s->failed_pc=0x0c0754ceu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07558au,2);
goto P_0c0754d0;
P_0c0754d0: /* original 02fe, guest PC 0x0c0754d0 */
if(!s->budget--) { s->failed_pc=0x0c0754d0u; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c0754d2;
P_0c0754d2: /* original e048, guest PC 0x0c0754d2 */
if(!s->budget--) { s->failed_pc=0x0c0754d2u; return 0; }
r[0]=0x00000048u;
goto P_0c0754d4;
P_0c0754d4: /* original 012e, guest PC 0x0c0754d4 */
if(!s->budget--) { s->failed_pc=0x0c0754d4u; return 0; }
r[1]=read(ram,r[2]+r[0],4);
goto P_0c0754d6;
P_0c0754d6: /* original e064, guest PC 0x0c0754d6 */
if(!s->budget--) { s->failed_pc=0x0c0754d6u; return 0; }
r[0]=0x00000064u;
goto P_0c0754d8;
P_0c0754d8: /* original 0f16, guest PC 0x0c0754d8 */
if(!s->budget--) { s->failed_pc=0x0c0754d8u; return 0; }
write(ram,r[15]+r[0],r[1],4);
goto P_0c0754da;
P_0c0754da: /* original d233, guest PC 0x0c0754da */
if(!s->budget--) { s->failed_pc=0x0c0754dau; return 0; }
r[2]=read(ram,0x0c0755a8u,4);
goto P_0c0754dc;
P_0c0754dc: /* original 2128, guest PC 0x0c0754dc */
if(!s->budget--) { s->failed_pc=0x0c0754dcu; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[2])==0)!=0);
goto P_0c0754de;
P_0c0754de: /* original 8920, guest PC 0x0c0754de */
if(!s->budget--) { s->failed_pc=0x0c0754deu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c075522; }
goto P_0c0754e0;
P_0c0754e0: /* original e064, guest PC 0x0c0754e0 */
if(!s->budget--) { s->failed_pc=0x0c0754e0u; return 0; }
r[0]=0x00000064u;
goto P_0c0754e2;
P_0c0754e2: /* original d132, guest PC 0x0c0754e2 */
if(!s->budget--) { s->failed_pc=0x0c0754e2u; return 0; }
r[1]=read(ram,0x0c0755acu,4);
goto P_0c0754e4;
P_0c0754e4: /* original 00fe, guest PC 0x0c0754e4 */
if(!s->budget--) { s->failed_pc=0x0c0754e4u; return 0; }
r[0]=read(ram,r[15]+r[0],4);
goto P_0c0754e6;
P_0c0754e6: /* original 2018, guest PC 0x0c0754e6 */
if(!s->budget--) { s->failed_pc=0x0c0754e6u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[1])==0)!=0);
goto P_0c0754e8;
P_0c0754e8: /* original 891b, guest PC 0x0c0754e8 */
if(!s->budget--) { s->failed_pc=0x0c0754e8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c075522; }
goto P_0c0754ea;
P_0c0754ea: /* original 904e, guest PC 0x0c0754ea */
if(!s->budget--) { s->failed_pc=0x0c0754eau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07558au,2);
goto P_0c0754ec;
P_0c0754ec: /* original 02fe, guest PC 0x0c0754ec */
if(!s->budget--) { s->failed_pc=0x0c0754ecu; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c0754ee;
P_0c0754ee: /* original 904f, guest PC 0x0c0754ee */
if(!s->budget--) { s->failed_pc=0x0c0754eeu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c075590u,2);
goto P_0c0754f0;
P_0c0754f0: /* original 032d, guest PC 0x0c0754f0 */
if(!s->budget--) { s->failed_pc=0x0c0754f0u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[2]+r[0],2);
goto P_0c0754f2;
P_0c0754f2: /* original e058, guest PC 0x0c0754f2 */
if(!s->budget--) { s->failed_pc=0x0c0754f2u; return 0; }
r[0]=0x00000058u;
goto P_0c0754f4;
P_0c0754f4: /* original 02fe, guest PC 0x0c0754f4 */
if(!s->budget--) { s->failed_pc=0x0c0754f4u; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c0754f6;
P_0c0754f6: /* original 3238, guest PC 0x0c0754f6 */
if(!s->budget--) { s->failed_pc=0x0c0754f6u; return 0; }
r[2]-=r[3];
goto P_0c0754f8;
P_0c0754f8: /* original 934b, guest PC 0x0c0754f8 */
if(!s->budget--) { s->failed_pc=0x0c0754f8u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c075592u,2);
goto P_0c0754fa;
P_0c0754fa: /* original 323c, guest PC 0x0c0754fa */
if(!s->budget--) { s->failed_pc=0x0c0754fau; return 0; }
r[2]+=r[3];
goto P_0c0754fc;
P_0c0754fc: /* original 622f, guest PC 0x0c0754fc */
if(!s->budget--) { s->failed_pc=0x0c0754fcu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)r[2];
goto P_0c0754fe;
P_0c0754fe: /* original 4211, guest PC 0x0c0754fe */
if(!s->budget--) { s->failed_pc=0x0c0754feu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>=0)!=0);
goto P_0c075500;
P_0c075500: /* original 8f0f, guest PC 0x0c075500 */
if(!s->budget--) { s->failed_pc=0x0c075500u; return 0; }
cond=r[17]&1u;
write(ram,r[15]+60,r[2],4);
if(!cond) { goto P_0c075522; }
goto P_0c075504;
P_0c075502: /* original 1f2f, guest PC 0x0c075502 */
if(!s->budget--) { s->failed_pc=0x0c075502u; return 0; }
write(ram,r[15]+60,r[2],4);
goto P_0c075504;
P_0c075504: /* original d22a, guest PC 0x0c075504 */
if(!s->budget--) { s->failed_pc=0x0c075504u; return 0; }
r[2]=read(ram,0x0c0755b0u,4);
goto P_0c075506;
P_0c075506: /* original e124, guest PC 0x0c075506 */
if(!s->budget--) { s->failed_pc=0x0c075506u; return 0; }
r[1]=0x00000024u;
goto P_0c075508;
P_0c075508: /* original 903f, guest PC 0x0c075508 */
if(!s->budget--) { s->failed_pc=0x0c075508u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07558au,2);
goto P_0c07550a;
P_0c07550a: /* original 425a, guest PC 0x0c07550a */
if(!s->budget--) { s->failed_pc=0x0c07550au; return 0; }
r[53]=r[2];
goto P_0c07550c;
P_0c07550c: /* original 00fe, guest PC 0x0c07550c */
if(!s->budget--) { s->failed_pc=0x0c07550cu; return 0; }
r[0]=read(ram,r[15]+r[0],4);
goto P_0c07550e;
P_0c07550e: /* original f216, guest PC 0x0c07550e */
if(!s->budget--) { s->failed_pc=0x0c07550eu; return 0; }
vf3_matrix_load(s,ram,2,r[1]+r[0]);
goto P_0c075510;
P_0c075510: /* original f30d, guest PC 0x0c075510 */
if(!s->budget--) { s->failed_pc=0x0c075510u; return 0; }
fr[3]=r[53];
goto P_0c075512;
P_0c075512: /* original f232, guest PC 0x0c075512 */
if(!s->budget--) { s->failed_pc=0x0c075512u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c075514;
P_0c075514: /* original f127, guest PC 0x0c075514 */
if(!s->budget--) { s->failed_pc=0x0c075514u; return 0; }
vf3_matrix_store(s,ram,2,r[1]+r[0]);
goto P_0c075516;
P_0c075516: /* original 9038, guest PC 0x0c075516 */
if(!s->budget--) { s->failed_pc=0x0c075516u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07558au,2);
goto P_0c075518;
P_0c075518: /* original 01fe, guest PC 0x0c075518 */
if(!s->budget--) { s->failed_pc=0x0c075518u; return 0; }
r[1]=read(ram,r[15]+r[0],4);
goto P_0c07551a;
P_0c07551a: /* original e02c, guest PC 0x0c07551a */
if(!s->budget--) { s->failed_pc=0x0c07551au; return 0; }
r[0]=0x0000002cu;
goto P_0c07551c;
P_0c07551c: /* original f216, guest PC 0x0c07551c */
if(!s->budget--) { s->failed_pc=0x0c07551cu; return 0; }
vf3_matrix_load(s,ram,2,r[1]+r[0]);
goto P_0c07551e;
P_0c07551e: /* original f232, guest PC 0x0c07551e */
if(!s->budget--) { s->failed_pc=0x0c07551eu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c075520;
P_0c075520: /* original f127, guest PC 0x0c075520 */
if(!s->budget--) { s->failed_pc=0x0c075520u; return 0; }
vf3_matrix_store(s,ram,2,r[1]+r[0]);
goto P_0c075522;
P_0c075522: /* original e05c, guest PC 0x0c075522 */
if(!s->budget--) { s->failed_pc=0x0c075522u; return 0; }
r[0]=0x0000005cu;
goto P_0c075524;
P_0c075524: /* original d323, guest PC 0x0c075524 */
if(!s->budget--) { s->failed_pc=0x0c075524u; return 0; }
r[3]=read(ram,0x0c0755b4u,4);
goto P_0c075526;
P_0c075526: /* original 02fe, guest PC 0x0c075526 */
if(!s->budget--) { s->failed_pc=0x0c075526u; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c075528;
P_0c075528: /* original 2238, guest PC 0x0c075528 */
if(!s->budget--) { s->failed_pc=0x0c075528u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c07552a;
P_0c07552a: /* original 8b01, guest PC 0x0c07552a */
if(!s->budget--) { s->failed_pc=0x0c07552au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c075530; }
goto P_0c07552c;
P_0c07552c: /* original a1d6, guest PC 0x0c07552c */
if(!s->budget--) { s->failed_pc=0x0c07552cu; return 0; }
goto P_0c0758dc;
P_0c07552e: /* original 0009, guest PC 0x0c07552e */
if(!s->budget--) { s->failed_pc=0x0c07552eu; return 0; }
goto P_0c075530;
P_0c075530: /* original 9030, guest PC 0x0c075530 */
if(!s->budget--) { s->failed_pc=0x0c075530u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c075594u,2);
goto P_0c075532;
P_0c075532: /* original d121, guest PC 0x0c075532 */
if(!s->budget--) { s->failed_pc=0x0c075532u; return 0; }
r[1]=read(ram,0x0c0755b8u,4);
goto P_0c075534;
P_0c075534: /* original 02fe, guest PC 0x0c075534 */
if(!s->budget--) { s->failed_pc=0x0c075534u; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c075536;
P_0c075536: /* original e050, guest PC 0x0c075536 */
if(!s->budget--) { s->failed_pc=0x0c075536u; return 0; }
r[0]=0x00000050u;
goto P_0c075538;
P_0c075538: /* original 022e, guest PC 0x0c075538 */
if(!s->budget--) { s->failed_pc=0x0c075538u; return 0; }
r[2]=read(ram,r[2]+r[0],4);
goto P_0c07553a;
P_0c07553a: /* original 2218, guest PC 0x0c07553a */
if(!s->budget--) { s->failed_pc=0x0c07553au; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[1])==0)!=0);
goto P_0c07553c;
P_0c07553c: /* original 8901, guest PC 0x0c07553c */
if(!s->budget--) { s->failed_pc=0x0c07553cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c075542; }
goto P_0c07553e;
P_0c07553e: /* original a1cd, guest PC 0x0c07553e */
if(!s->budget--) { s->failed_pc=0x0c07553eu; return 0; }
goto P_0c0758dc;
P_0c075540: /* original 0009, guest PC 0x0c075540 */
if(!s->budget--) { s->failed_pc=0x0c075540u; return 0; }
goto P_0c075542;
P_0c075542: /* original e05c, guest PC 0x0c075542 */
if(!s->budget--) { s->failed_pc=0x0c075542u; return 0; }
r[0]=0x0000005cu;
goto P_0c075544;
P_0c075544: /* original d31d, guest PC 0x0c075544 */
if(!s->budget--) { s->failed_pc=0x0c075544u; return 0; }
r[3]=read(ram,0x0c0755bcu,4);
goto P_0c075546;
P_0c075546: /* original 02fe, guest PC 0x0c075546 */
if(!s->budget--) { s->failed_pc=0x0c075546u; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c075548;
P_0c075548: /* original 2238, guest PC 0x0c075548 */
if(!s->budget--) { s->failed_pc=0x0c075548u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c07554a;
P_0c07554a: /* original 8b3d, guest PC 0x0c07554a */
if(!s->budget--) { s->failed_pc=0x0c07554au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0755c8; }
goto P_0c07554c;
P_0c07554c: /* original e060, guest PC 0x0c07554c */
if(!s->budget--) { s->failed_pc=0x0c07554cu; return 0; }
r[0]=0x00000060u;
goto P_0c07554e;
P_0c07554e: /* original 00fe, guest PC 0x0c07554e */
if(!s->budget--) { s->failed_pc=0x0c07554eu; return 0; }
r[0]=read(ram,r[15]+r[0],4);
goto P_0c075550;
P_0c075550: /* original 8805, guest PC 0x0c075550 */
if(!s->budget--) { s->failed_pc=0x0c075550u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000005u)!=0);
goto P_0c075552;
P_0c075552: /* original 8913, guest PC 0x0c075552 */
if(!s->budget--) { s->failed_pc=0x0c075552u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07557c; }
goto P_0c075554;
P_0c075554: /* original e060, guest PC 0x0c075554 */
if(!s->budget--) { s->failed_pc=0x0c075554u; return 0; }
r[0]=0x00000060u;
goto P_0c075556;
P_0c075556: /* original 00fe, guest PC 0x0c075556 */
if(!s->budget--) { s->failed_pc=0x0c075556u; return 0; }
r[0]=read(ram,r[15]+r[0],4);
goto P_0c075558;
P_0c075558: /* original 8806, guest PC 0x0c075558 */
if(!s->budget--) { s->failed_pc=0x0c075558u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000006u)!=0);
goto P_0c07555a;
P_0c07555a: /* original 890f, guest PC 0x0c07555a */
if(!s->budget--) { s->failed_pc=0x0c07555au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07557c; }
goto P_0c07555c;
P_0c07555c: /* original e060, guest PC 0x0c07555c */
if(!s->budget--) { s->failed_pc=0x0c07555cu; return 0; }
r[0]=0x00000060u;
goto P_0c07555e;
P_0c07555e: /* original 00fe, guest PC 0x0c07555e */
if(!s->budget--) { s->failed_pc=0x0c07555eu; return 0; }
r[0]=read(ram,r[15]+r[0],4);
goto P_0c075560;
P_0c075560: /* original 8802, guest PC 0x0c075560 */
if(!s->budget--) { s->failed_pc=0x0c075560u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c075562;
P_0c075562: /* original 890b, guest PC 0x0c075562 */
if(!s->budget--) { s->failed_pc=0x0c075562u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07557c; }
goto P_0c075564;
P_0c075564: /* original e070, guest PC 0x0c075564 */
if(!s->budget--) { s->failed_pc=0x0c075564u; return 0; }
r[0]=0x00000070u;
goto P_0c075566;
P_0c075566: /* original d316, guest PC 0x0c075566 */
if(!s->budget--) { s->failed_pc=0x0c075566u; return 0; }
r[3]=read(ram,0x0c0755c0u,4);
goto P_0c075568;
P_0c075568: /* original 02fe, guest PC 0x0c075568 */
if(!s->budget--) { s->failed_pc=0x0c075568u; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c07556a;
P_0c07556a: /* original 2238, guest PC 0x0c07556a */
if(!s->budget--) { s->failed_pc=0x0c07556au; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c07556c;
P_0c07556c: /* original 8b78, guest PC 0x0c07556c */
if(!s->budget--) { s->failed_pc=0x0c07556cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c075660; }
goto P_0c07556e;
P_0c07556e: /* original e070, guest PC 0x0c07556e */
if(!s->budget--) { s->failed_pc=0x0c07556eu; return 0; }
r[0]=0x00000070u;
goto P_0c075570;
P_0c075570: /* original d314, guest PC 0x0c075570 */
if(!s->budget--) { s->failed_pc=0x0c075570u; return 0; }
r[3]=read(ram,0x0c0755c4u,4);
goto P_0c075572;
P_0c075572: /* original 01fe, guest PC 0x0c075572 */
if(!s->budget--) { s->failed_pc=0x0c075572u; return 0; }
r[1]=read(ram,r[15]+r[0],4);
goto P_0c075574;
P_0c075574: /* original 2138, guest PC 0x0c075574 */
if(!s->budget--) { s->failed_pc=0x0c075574u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[3])==0)!=0);
goto P_0c075576;
P_0c075576: /* original 8b01, guest PC 0x0c075576 */
if(!s->budget--) { s->failed_pc=0x0c075576u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07557c; }
goto P_0c075578;
P_0c075578: /* original a10a, guest PC 0x0c075578 */
if(!s->budget--) { s->failed_pc=0x0c075578u; return 0; }
goto P_0c075790;
P_0c07557a: /* original 0009, guest PC 0x0c07557a */
if(!s->budget--) { s->failed_pc=0x0c07557au; return 0; }
goto P_0c07557c;
P_0c07557c: /* original e070, guest PC 0x0c07557c */
if(!s->budget--) { s->failed_pc=0x0c07557cu; return 0; }
r[0]=0x00000070u;
goto P_0c07557e;
P_0c07557e: /* original d30f, guest PC 0x0c07557e */
if(!s->budget--) { s->failed_pc=0x0c07557eu; return 0; }
r[3]=read(ram,0x0c0755bcu,4);
goto P_0c075580;
P_0c075580: /* original 02fe, guest PC 0x0c075580 */
if(!s->budget--) { s->failed_pc=0x0c075580u; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c075582;
P_0c075582: /* original 2238, guest PC 0x0c075582 */
if(!s->budget--) { s->failed_pc=0x0c075582u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c075584;
P_0c075584: /* original 8b4f, guest PC 0x0c075584 */
if(!s->budget--) { s->failed_pc=0x0c075584u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c075626; }
goto P_0c075586;
P_0c075586: /* original a1a9, guest PC 0x0c075586 */
if(!s->budget--) { s->failed_pc=0x0c075586u; return 0; }
goto P_0c0758dc;
P_0c075588: /* original 0009, guest PC 0x0c075588 */
if(!s->budget--) { s->failed_pc=0x0c075588u; return 0; }
return vf3_matrix_family(0x0c07558au,s,ram);
P_0c0755c8: /* original 907c, guest PC 0x0c0755c8 */
if(!s->budget--) { s->failed_pc=0x0c0755c8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0756c4u,2);
goto P_0c0755ca;
P_0c0755ca: /* original d343, guest PC 0x0c0755ca */
if(!s->budget--) { s->failed_pc=0x0c0755cau; return 0; }
r[3]=read(ram,0x0c0756d8u,4);
goto P_0c0755cc;
P_0c0755cc: /* original 01fe, guest PC 0x0c0755cc */
if(!s->budget--) { s->failed_pc=0x0c0755ccu; return 0; }
r[1]=read(ram,r[15]+r[0],4);
goto P_0c0755ce;
P_0c0755ce: /* original 907a, guest PC 0x0c0755ce */
if(!s->budget--) { s->failed_pc=0x0c0755ceu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0756c6u,2);
goto P_0c0755d0;
P_0c0755d0: /* original 021e, guest PC 0x0c0755d0 */
if(!s->budget--) { s->failed_pc=0x0c0755d0u; return 0; }
r[2]=read(ram,r[1]+r[0],4);
goto P_0c0755d2;
P_0c0755d2: /* original 2238, guest PC 0x0c0755d2 */
if(!s->budget--) { s->failed_pc=0x0c0755d2u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0755d4;
P_0c0755d4: /* original 8901, guest PC 0x0c0755d4 */
if(!s->budget--) { s->failed_pc=0x0c0755d4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0755da; }
goto P_0c0755d6;
P_0c0755d6: /* original a091, guest PC 0x0c0755d6 */
if(!s->budget--) { s->failed_pc=0x0c0755d6u; return 0; }
goto P_0c0756fc;
P_0c0755d8: /* original 0009, guest PC 0x0c0755d8 */
if(!s->budget--) { s->failed_pc=0x0c0755d8u; return 0; }
goto P_0c0755da;
P_0c0755da: /* original e060, guest PC 0x0c0755da */
if(!s->budget--) { s->failed_pc=0x0c0755dau; return 0; }
r[0]=0x00000060u;
goto P_0c0755dc;
P_0c0755dc: /* original 00fe, guest PC 0x0c0755dc */
if(!s->budget--) { s->failed_pc=0x0c0755dcu; return 0; }
r[0]=read(ram,r[15]+r[0],4);
goto P_0c0755de;
P_0c0755de: /* original 8805, guest PC 0x0c0755de */
if(!s->budget--) { s->failed_pc=0x0c0755deu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000005u)!=0);
goto P_0c0755e0;
P_0c0755e0: /* original 8907, guest PC 0x0c0755e0 */
if(!s->budget--) { s->failed_pc=0x0c0755e0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0755f2; }
goto P_0c0755e2;
P_0c0755e2: /* original e060, guest PC 0x0c0755e2 */
if(!s->budget--) { s->failed_pc=0x0c0755e2u; return 0; }
r[0]=0x00000060u;
goto P_0c0755e4;
P_0c0755e4: /* original 00fe, guest PC 0x0c0755e4 */
if(!s->budget--) { s->failed_pc=0x0c0755e4u; return 0; }
r[0]=read(ram,r[15]+r[0],4);
goto P_0c0755e6;
P_0c0755e6: /* original 8806, guest PC 0x0c0755e6 */
if(!s->budget--) { s->failed_pc=0x0c0755e6u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000006u)!=0);
goto P_0c0755e8;
P_0c0755e8: /* original 8903, guest PC 0x0c0755e8 */
if(!s->budget--) { s->failed_pc=0x0c0755e8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0755f2; }
goto P_0c0755ea;
P_0c0755ea: /* original e060, guest PC 0x0c0755ea */
if(!s->budget--) { s->failed_pc=0x0c0755eau; return 0; }
r[0]=0x00000060u;
goto P_0c0755ec;
P_0c0755ec: /* original 00fe, guest PC 0x0c0755ec */
if(!s->budget--) { s->failed_pc=0x0c0755ecu; return 0; }
r[0]=read(ram,r[15]+r[0],4);
goto P_0c0755ee;
P_0c0755ee: /* original 8802, guest PC 0x0c0755ee */
if(!s->budget--) { s->failed_pc=0x0c0755eeu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c0755f0;
P_0c0755f0: /* original 8b0d, guest PC 0x0c0755f0 */
if(!s->budget--) { s->failed_pc=0x0c0755f0u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07560e; }
goto P_0c0755f2;
P_0c0755f2: /* original e070, guest PC 0x0c0755f2 */
if(!s->budget--) { s->failed_pc=0x0c0755f2u; return 0; }
r[0]=0x00000070u;
goto P_0c0755f4;
P_0c0755f4: /* original d339, guest PC 0x0c0755f4 */
if(!s->budget--) { s->failed_pc=0x0c0755f4u; return 0; }
r[3]=read(ram,0x0c0756dcu,4);
goto P_0c0755f6;
P_0c0755f6: /* original 02fe, guest PC 0x0c0755f6 */
if(!s->budget--) { s->failed_pc=0x0c0755f6u; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c0755f8;
P_0c0755f8: /* original 2238, guest PC 0x0c0755f8 */
if(!s->budget--) { s->failed_pc=0x0c0755f8u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0755fa;
P_0c0755fa: /* original 8b01, guest PC 0x0c0755fa */
if(!s->budget--) { s->failed_pc=0x0c0755fau; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c075600; }
goto P_0c0755fc;
P_0c0755fc: /* original a0c8, guest PC 0x0c0755fc */
if(!s->budget--) { s->failed_pc=0x0c0755fcu; return 0; }
goto P_0c075790;
P_0c0755fe: /* original 0009, guest PC 0x0c0755fe */
if(!s->budget--) { s->failed_pc=0x0c0755feu; return 0; }
goto P_0c075600;
P_0c075600: /* original e070, guest PC 0x0c075600 */
if(!s->budget--) { s->failed_pc=0x0c075600u; return 0; }
r[0]=0x00000070u;
goto P_0c075602;
P_0c075602: /* original d337, guest PC 0x0c075602 */
if(!s->budget--) { s->failed_pc=0x0c075602u; return 0; }
r[3]=read(ram,0x0c0756e0u,4);
goto P_0c075604;
P_0c075604: /* original 01fe, guest PC 0x0c075604 */
if(!s->budget--) { s->failed_pc=0x0c075604u; return 0; }
r[1]=read(ram,r[15]+r[0],4);
goto P_0c075606;
P_0c075606: /* original 2138, guest PC 0x0c075606 */
if(!s->budget--) { s->failed_pc=0x0c075606u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[3])==0)!=0);
goto P_0c075608;
P_0c075608: /* original 8b0d, guest PC 0x0c075608 */
if(!s->budget--) { s->failed_pc=0x0c075608u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c075626; }
goto P_0c07560a;
P_0c07560a: /* original a167, guest PC 0x0c07560a */
if(!s->budget--) { s->failed_pc=0x0c07560au; return 0; }
goto P_0c0758dc;
P_0c07560c: /* original 0009, guest PC 0x0c07560c */
if(!s->budget--) { s->failed_pc=0x0c07560cu; return 0; }
goto P_0c07560e;
P_0c07560e: /* original e070, guest PC 0x0c07560e */
if(!s->budget--) { s->failed_pc=0x0c07560eu; return 0; }
r[0]=0x00000070u;
goto P_0c075610;
P_0c075610: /* original d334, guest PC 0x0c075610 */
if(!s->budget--) { s->failed_pc=0x0c075610u; return 0; }
r[3]=read(ram,0x0c0756e4u,4);
goto P_0c075612;
P_0c075612: /* original 02fe, guest PC 0x0c075612 */
if(!s->budget--) { s->failed_pc=0x0c075612u; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c075614;
P_0c075614: /* original 2238, guest PC 0x0c075614 */
if(!s->budget--) { s->failed_pc=0x0c075614u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c075616;
P_0c075616: /* original 8b23, guest PC 0x0c075616 */
if(!s->budget--) { s->failed_pc=0x0c075616u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c075660; }
goto P_0c075618;
P_0c075618: /* original e070, guest PC 0x0c075618 */
if(!s->budget--) { s->failed_pc=0x0c075618u; return 0; }
r[0]=0x00000070u;
goto P_0c07561a;
P_0c07561a: /* original d331, guest PC 0x0c07561a */
if(!s->budget--) { s->failed_pc=0x0c07561au; return 0; }
r[3]=read(ram,0x0c0756e0u,4);
goto P_0c07561c;
P_0c07561c: /* original 01fe, guest PC 0x0c07561c */
if(!s->budget--) { s->failed_pc=0x0c07561cu; return 0; }
r[1]=read(ram,r[15]+r[0],4);
goto P_0c07561e;
P_0c07561e: /* original 2138, guest PC 0x0c07561e */
if(!s->budget--) { s->failed_pc=0x0c07561eu; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[3])==0)!=0);
goto P_0c075620;
P_0c075620: /* original 8b01, guest PC 0x0c075620 */
if(!s->budget--) { s->failed_pc=0x0c075620u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c075626; }
goto P_0c075622;
P_0c075622: /* original a15b, guest PC 0x0c075622 */
if(!s->budget--) { s->failed_pc=0x0c075622u; return 0; }
goto P_0c0758dc;
P_0c075624: /* original 0009, guest PC 0x0c075624 */
if(!s->budget--) { s->failed_pc=0x0c075624u; return 0; }
goto P_0c075626;
P_0c075626: /* original e070, guest PC 0x0c075626 */
if(!s->budget--) { s->failed_pc=0x0c075626u; return 0; }
r[0]=0x00000070u;
goto P_0c075628;
P_0c075628: /* original d32c, guest PC 0x0c075628 */
if(!s->budget--) { s->failed_pc=0x0c075628u; return 0; }
r[3]=read(ram,0x0c0756dcu,4);
goto P_0c07562a;
P_0c07562a: /* original 02fe, guest PC 0x0c07562a */
if(!s->budget--) { s->failed_pc=0x0c07562au; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c07562c;
P_0c07562c: /* original 2238, guest PC 0x0c07562c */
if(!s->budget--) { s->failed_pc=0x0c07562cu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c07562e;
P_0c07562e: /* original 8904, guest PC 0x0c07562e */
if(!s->budget--) { s->failed_pc=0x0c07562eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07563a; }
goto P_0c075630;
P_0c075630: /* original e054, guest PC 0x0c075630 */
if(!s->budget--) { s->failed_pc=0x0c075630u; return 0; }
r[0]=0x00000054u;
goto P_0c075632;
P_0c075632: /* original 02fe, guest PC 0x0c075632 */
if(!s->budget--) { s->failed_pc=0x0c075632u; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c075634;
P_0c075634: /* original e054, guest PC 0x0c075634 */
if(!s->budget--) { s->failed_pc=0x0c075634u; return 0; }
r[0]=0x00000054u;
goto P_0c075636;
P_0c075636: /* original 4201, guest PC 0x0c075636 */
if(!s->budget--) { s->failed_pc=0x0c075636u; return 0; }
r[17]=(r[17]&~1u)|((r[2]&1)!=0);
r[2]>>=1;
goto P_0c075638;
P_0c075638: /* original 0f26, guest PC 0x0c075638 */
if(!s->budget--) { s->failed_pc=0x0c075638u; return 0; }
write(ram,r[15]+r[0],r[2],4);
goto P_0c07563a;
P_0c07563a: /* original c72b, guest PC 0x0c07563a */
if(!s->budget--) { s->failed_pc=0x0c07563au; return 0; }
r[0]=0x0c0756e8u;
goto P_0c07563c;
P_0c07563c: /* original f308, guest PC 0x0c07563c */
if(!s->budget--) { s->failed_pc=0x0c07563cu; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c07563e;
P_0c07563e: /* original e020, guest PC 0x0c07563e */
if(!s->budget--) { s->failed_pc=0x0c07563eu; return 0; }
r[0]=0x00000020u;
goto P_0c075640;
P_0c075640: /* original f2f6, guest PC 0x0c075640 */
if(!s->budget--) { s->failed_pc=0x0c075640u; return 0; }
vf3_matrix_load(s,ram,2,r[15]+r[0]);
goto P_0c075642;
P_0c075642: /* original e020, guest PC 0x0c075642 */
if(!s->budget--) { s->failed_pc=0x0c075642u; return 0; }
r[0]=0x00000020u;
goto P_0c075644;
P_0c075644: /* original e301, guest PC 0x0c075644 */
if(!s->budget--) { s->failed_pc=0x0c075644u; return 0; }
r[3]=0x00000001u;
goto P_0c075646;
P_0c075646: /* original f232, guest PC 0x0c075646 */
if(!s->budget--) { s->failed_pc=0x0c075646u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c075648;
P_0c075648: /* original ff27, guest PC 0x0c075648 */
if(!s->budget--) { s->failed_pc=0x0c075648u; return 0; }
vf3_matrix_store(s,ram,2,r[15]+r[0]);
goto P_0c07564a;
P_0c07564a: /* original e050, guest PC 0x0c07564a */
if(!s->budget--) { s->failed_pc=0x0c07564au; return 0; }
r[0]=0x00000050u;
goto P_0c07564c;
P_0c07564c: /* original 0f36, guest PC 0x0c07564c */
if(!s->budget--) { s->failed_pc=0x0c07564cu; return 0; }
write(ram,r[15]+r[0],r[3],4);
goto P_0c07564e;
P_0c07564e: /* original 9039, guest PC 0x0c07564e */
if(!s->budget--) { s->failed_pc=0x0c07564eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0756c4u,2);
goto P_0c075650;
P_0c075650: /* original 923b, guest PC 0x0c075650 */
if(!s->budget--) { s->failed_pc=0x0c075650u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0756cau,2);
goto P_0c075652;
P_0c075652: /* original 03fe, guest PC 0x0c075652 */
if(!s->budget--) { s->failed_pc=0x0c075652u; return 0; }
r[3]=read(ram,r[15]+r[0],4);
goto P_0c075654;
P_0c075654: /* original 9038, guest PC 0x0c075654 */
if(!s->budget--) { s->failed_pc=0x0c075654u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0756c8u,2);
goto P_0c075656;
P_0c075656: /* original 013e, guest PC 0x0c075656 */
if(!s->budget--) { s->failed_pc=0x0c075656u; return 0; }
r[1]=read(ram,r[3]+r[0],4);
goto P_0c075658;
P_0c075658: /* original 212b, guest PC 0x0c075658 */
if(!s->budget--) { s->failed_pc=0x0c075658u; return 0; }
r[1]|=r[2];
goto P_0c07565a;
P_0c07565a: /* original 0316, guest PC 0x0c07565a */
if(!s->budget--) { s->failed_pc=0x0c07565au; return 0; }
write(ram,r[3]+r[0],r[1],4);
goto P_0c07565c;
P_0c07565c: /* original a141, guest PC 0x0c07565c */
if(!s->budget--) { s->failed_pc=0x0c07565cu; return 0; }
goto P_0c0758e2;
P_0c07565e: /* original 0009, guest PC 0x0c07565e */
if(!s->budget--) { s->failed_pc=0x0c07565eu; return 0; }
goto P_0c075660;
P_0c075660: /* original d222, guest PC 0x0c075660 */
if(!s->budget--) { s->failed_pc=0x0c075660u; return 0; }
r[2]=read(ram,0x0c0756ecu,4);
goto P_0c075662;
P_0c075662: /* original 420b, guest PC 0x0c075662 */
if(!s->budget--) { s->failed_pc=0x0c075662u; return 0; }
target=r[2];
r[16]=0x0c075666u;
r[4]=0x00000063u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c075666u) { target=s->pc; goto dispatch; }
goto P_0c075666;
P_0c075664: /* original e463, guest PC 0x0c075664 */
if(!s->budget--) { s->failed_pc=0x0c075664u; return 0; }
r[4]=0x00000063u;
goto P_0c075666;
P_0c075666: /* original d322, guest PC 0x0c075666 */
if(!s->budget--) { s->failed_pc=0x0c075666u; return 0; }
r[3]=read(ram,0x0c0756f0u,4);
goto P_0c075668;
P_0c075668: /* original 430b, guest PC 0x0c075668 */
if(!s->budget--) { s->failed_pc=0x0c075668u; return 0; }
target=r[3];
r[16]=0x0c07566cu;
r[4]=0x00000063u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07566cu) { target=s->pc; goto dispatch; }
goto P_0c07566c;
P_0c07566a: /* original e463, guest PC 0x0c07566a */
if(!s->budget--) { s->failed_pc=0x0c07566au; return 0; }
r[4]=0x00000063u;
goto P_0c07566c;
P_0c07566c: /* original 902a, guest PC 0x0c07566c */
if(!s->budget--) { s->failed_pc=0x0c07566cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0756c4u,2);
goto P_0c07566e;
P_0c07566e: /* original e601, guest PC 0x0c07566e */
if(!s->budget--) { s->failed_pc=0x0c07566eu; return 0; }
r[6]=0x00000001u;
goto P_0c075670;
P_0c075670: /* original 922c, guest PC 0x0c075670 */
if(!s->budget--) { s->failed_pc=0x0c075670u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0756ccu,2);
goto P_0c075672;
P_0c075672: /* original 03fe, guest PC 0x0c075672 */
if(!s->budget--) { s->failed_pc=0x0c075672u; return 0; }
r[3]=read(ram,r[15]+r[0],4);
goto P_0c075674;
P_0c075674: /* original 9028, guest PC 0x0c075674 */
if(!s->budget--) { s->failed_pc=0x0c075674u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0756c8u,2);
goto P_0c075676;
P_0c075676: /* original 013e, guest PC 0x0c075676 */
if(!s->budget--) { s->failed_pc=0x0c075676u; return 0; }
r[1]=read(ram,r[3]+r[0],4);
goto P_0c075678;
P_0c075678: /* original 212b, guest PC 0x0c075678 */
if(!s->budget--) { s->failed_pc=0x0c075678u; return 0; }
r[1]|=r[2];
goto P_0c07567a;
P_0c07567a: /* original 0316, guest PC 0x0c07567a */
if(!s->budget--) { s->failed_pc=0x0c07567au; return 0; }
write(ram,r[3]+r[0],r[1],4);
goto P_0c07567c;
P_0c07567c: /* original 9022, guest PC 0x0c07567c */
if(!s->budget--) { s->failed_pc=0x0c07567cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0756c4u,2);
goto P_0c07567e;
P_0c07567e: /* original d11d, guest PC 0x0c07567e */
if(!s->budget--) { s->failed_pc=0x0c07567eu; return 0; }
r[1]=read(ram,0x0c0756f4u,4);
goto P_0c075680;
P_0c075680: /* original 03fe, guest PC 0x0c075680 */
if(!s->budget--) { s->failed_pc=0x0c075680u; return 0; }
r[3]=read(ram,r[15]+r[0],4);
goto P_0c075682;
P_0c075682: /* original e050, guest PC 0x0c075682 */
if(!s->budget--) { s->failed_pc=0x0c075682u; return 0; }
r[0]=0x00000050u;
goto P_0c075684;
P_0c075684: /* original 131c, guest PC 0x0c075684 */
if(!s->budget--) { s->failed_pc=0x0c075684u; return 0; }
write(ram,r[3]+48,r[1],4);
goto P_0c075686;
P_0c075686: /* original 61f3, guest PC 0x0c075686 */
if(!s->budget--) { s->failed_pc=0x0c075686u; return 0; }
r[1]=r[15];
goto P_0c075688;
P_0c075688: /* original e300, guest PC 0x0c075688 */
if(!s->budget--) { s->failed_pc=0x0c075688u; return 0; }
r[3]=0x00000000u;
goto P_0c07568a;
P_0c07568a: /* original 715c, guest PC 0x0c07568a */
if(!s->budget--) { s->failed_pc=0x0c07568au; return 0; }
r[1]+=0x0000005cu;
goto P_0c07568c;
P_0c07568c: /* original 0f36, guest PC 0x0c07568c */
if(!s->budget--) { s->failed_pc=0x0c07568cu; return 0; }
write(ram,r[15]+r[0],r[3],4);
goto P_0c07568e;
P_0c07568e: /* original 2f16, guest PC 0x0c07568e */
if(!s->budget--) { s->failed_pc=0x0c07568eu; return 0; }
r[15]-=4; write(ram,r[15],r[1],4);
goto P_0c075690;
P_0c075690: /* original 2f36, guest PC 0x0c075690 */
if(!s->budget--) { s->failed_pc=0x0c075690u; return 0; }
r[15]-=4; write(ram,r[15],r[3],4);
goto P_0c075692;
P_0c075692: /* original 901d, guest PC 0x0c075692 */
if(!s->budget--) { s->failed_pc=0x0c075692u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0756d0u,2);
goto P_0c075694;
P_0c075694: /* original 971b, guest PC 0x0c075694 */
if(!s->budget--) { s->failed_pc=0x0c075694u; return 0; }
r[7]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0756ceu,2);
goto P_0c075696;
P_0c075696: /* original 05fe, guest PC 0x0c075696 */
if(!s->budget--) { s->failed_pc=0x0c075696u; return 0; }
r[5]=read(ram,r[15]+r[0],4);
goto P_0c075698;
P_0c075698: /* original 901b, guest PC 0x0c075698 */
if(!s->budget--) { s->failed_pc=0x0c075698u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0756d2u,2);
goto P_0c07569a;
P_0c07569a: /* original 37fc, guest PC 0x0c07569a */
if(!s->budget--) { s->failed_pc=0x0c07569au; return 0; }
r[7]+=r[15];
goto P_0c07569c;
P_0c07569c: /* original ba2f, guest PC 0x0c07569c */
if(!s->budget--) { s->failed_pc=0x0c07569cu; return 0; }
target=0x0c074afeu; r[16]=0x0c0756a0u;
r[4]=read(ram,r[15]+r[0],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0756a0u) { target=s->pc; goto dispatch; }
goto P_0c0756a0;
P_0c07569e: /* original 04fe, guest PC 0x0c07569e */
if(!s->budget--) { s->failed_pc=0x0c07569eu; return 0; }
r[4]=read(ram,r[15]+r[0],4);
goto P_0c0756a0;
P_0c0756a0: /* original 9015, guest PC 0x0c0756a0 */
if(!s->budget--) { s->failed_pc=0x0c0756a0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0756ceu,2);
goto P_0c0756a2;
P_0c0756a2: /* original 7f08, guest PC 0x0c0756a2 */
if(!s->budget--) { s->failed_pc=0x0c0756a2u; return 0; }
r[15]+=0x00000008u;
goto P_0c0756a4;
P_0c0756a4: /* original d214, guest PC 0x0c0756a4 */
if(!s->budget--) { s->failed_pc=0x0c0756a4u; return 0; }
r[2]=read(ram,0x0c0756f8u,4);
goto P_0c0756a6;
P_0c0756a6: /* original 03fe, guest PC 0x0c0756a6 */
if(!s->budget--) { s->failed_pc=0x0c0756a6u; return 0; }
r[3]=read(ram,r[15]+r[0],4);
goto P_0c0756a8;
P_0c0756a8: /* original 9014, guest PC 0x0c0756a8 */
if(!s->budget--) { s->failed_pc=0x0c0756a8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0756d4u,2);
goto P_0c0756aa;
P_0c0756aa: /* original 01fe, guest PC 0x0c0756aa */
if(!s->budget--) { s->failed_pc=0x0c0756aau; return 0; }
r[1]=read(ram,r[15]+r[0],4);
goto P_0c0756ac;
P_0c0756ac: /* original 312c, guest PC 0x0c0756ac */
if(!s->budget--) { s->failed_pc=0x0c0756acu; return 0; }
r[1]+=r[2];
goto P_0c0756ae;
P_0c0756ae: /* original 131d, guest PC 0x0c0756ae */
if(!s->budget--) { s->failed_pc=0x0c0756aeu; return 0; }
write(ram,r[3]+52,r[1],4);
goto P_0c0756b0;
P_0c0756b0: /* original 900d, guest PC 0x0c0756b0 */
if(!s->budget--) { s->failed_pc=0x0c0756b0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0756ceu,2);
goto P_0c0756b2;
P_0c0756b2: /* original 03fe, guest PC 0x0c0756b2 */
if(!s->budget--) { s->failed_pc=0x0c0756b2u; return 0; }
r[3]=read(ram,r[15]+r[0],4);
goto P_0c0756b4;
P_0c0756b4: /* original 9006, guest PC 0x0c0756b4 */
if(!s->budget--) { s->failed_pc=0x0c0756b4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0756c4u,2);
goto P_0c0756b6;
P_0c0756b6: /* original 01fe, guest PC 0x0c0756b6 */
if(!s->budget--) { s->failed_pc=0x0c0756b6u; return 0; }
r[1]=read(ram,r[15]+r[0],4);
goto P_0c0756b8;
P_0c0756b8: /* original 900d, guest PC 0x0c0756b8 */
if(!s->budget--) { s->failed_pc=0x0c0756b8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0756d6u,2);
goto P_0c0756ba;
P_0c0756ba: /* original 011d, guest PC 0x0c0756ba */
if(!s->budget--) { s->failed_pc=0x0c0756bau; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,r[1]+r[0],2);
goto P_0c0756bc;
P_0c0756bc: /* original 7004, guest PC 0x0c0756bc */
if(!s->budget--) { s->failed_pc=0x0c0756bcu; return 0; }
r[0]+=0x00000004u;
goto P_0c0756be;
P_0c0756be: /* original 0315, guest PC 0x0c0756be */
if(!s->budget--) { s->failed_pc=0x0c0756beu; return 0; }
write(ram,r[3]+r[0],r[1],2);
goto P_0c0756c0;
P_0c0756c0: /* original a0a2, guest PC 0x0c0756c0 */
if(!s->budget--) { s->failed_pc=0x0c0756c0u; return 0; }
goto P_0c075808;
P_0c0756c2: /* original 0009, guest PC 0x0c0756c2 */
if(!s->budget--) { s->failed_pc=0x0c0756c2u; return 0; }
return vf3_matrix_family(0x0c0756c4u,s,ram);
P_0c0756fc: /* original 9038, guest PC 0x0c0756fc */
if(!s->budget--) { s->failed_pc=0x0c0756fcu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c075770u,2);
goto P_0c0756fe;
P_0c0756fe: /* original e505, guest PC 0x0c0756fe */
if(!s->budget--) { s->failed_pc=0x0c0756feu; return 0; }
r[5]=0x00000005u;
goto P_0c075700;
P_0c075700: /* original 02fe, guest PC 0x0c075700 */
if(!s->budget--) { s->failed_pc=0x0c075700u; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c075702;
P_0c075702: /* original 9036, guest PC 0x0c075702 */
if(!s->budget--) { s->failed_pc=0x0c075702u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c075772u,2);
goto P_0c075704;
P_0c075704: /* original 032e, guest PC 0x0c075704 */
if(!s->budget--) { s->failed_pc=0x0c075704u; return 0; }
r[3]=read(ram,r[2]+r[0],4);
goto P_0c075706;
P_0c075706: /* original 9035, guest PC 0x0c075706 */
if(!s->budget--) { s->failed_pc=0x0c075706u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c075774u,2);
goto P_0c075708;
P_0c075708: /* original 0f36, guest PC 0x0c075708 */
if(!s->budget--) { s->failed_pc=0x0c075708u; return 0; }
write(ram,r[15]+r[0],r[3],4);
goto P_0c07570a;
P_0c07570a: /* original 9034, guest PC 0x0c07570a */
if(!s->budget--) { s->failed_pc=0x0c07570au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c075776u,2);
goto P_0c07570c;
P_0c07570c: /* original 02fe, guest PC 0x0c07570c */
if(!s->budget--) { s->failed_pc=0x0c07570cu; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c07570e;
P_0c07570e: /* original 123d, guest PC 0x0c07570e */
if(!s->budget--) { s->failed_pc=0x0c07570eu; return 0; }
write(ram,r[2]+52,r[3],4);
goto P_0c075710;
P_0c075710: /* original d31b, guest PC 0x0c075710 */
if(!s->budget--) { s->failed_pc=0x0c075710u; return 0; }
r[3]=read(ram,0x0c075780u,4);
goto P_0c075712;
P_0c075712: /* original 902f, guest PC 0x0c075712 */
if(!s->budget--) { s->failed_pc=0x0c075712u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c075774u,2);
goto P_0c075714;
P_0c075714: /* original 430b, guest PC 0x0c075714 */
if(!s->budget--) { s->failed_pc=0x0c075714u; return 0; }
target=r[3];
r[16]=0x0c075718u;
r[4]=read(ram,r[15]+r[0],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c075718u) { target=s->pc; goto dispatch; }
goto P_0c075718;
P_0c075716: /* original 04fe, guest PC 0x0c075716 */
if(!s->budget--) { s->failed_pc=0x0c075716u; return 0; }
r[4]=read(ram,r[15]+r[0],4);
goto P_0c075718;
P_0c075718: /* original 912e, guest PC 0x0c075718 */
if(!s->budget--) { s->failed_pc=0x0c075718u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c075778u,2);
goto P_0c07571a;
P_0c07571a: /* original 2008, guest PC 0x0c07571a */
if(!s->budget--) { s->failed_pc=0x0c07571au; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c07571c;
P_0c07571c: /* original 31fc, guest PC 0x0c07571c */
if(!s->budget--) { s->failed_pc=0x0c07571cu; return 0; }
r[1]+=r[15];
goto P_0c07571e;
P_0c07571e: /* original 8f03, guest PC 0x0c07571e */
if(!s->budget--) { s->failed_pc=0x0c07571eu; return 0; }
cond=r[17]&1u;
write(ram,r[1],r[0],4);
if(!cond) { goto P_0c075728; }
goto P_0c075722;
P_0c075720: /* original 2102, guest PC 0x0c075720 */
if(!s->budget--) { s->failed_pc=0x0c075720u; return 0; }
write(ram,r[1],r[0],4);
goto P_0c075722;
P_0c075722: /* original d318, guest PC 0x0c075722 */
if(!s->budget--) { s->failed_pc=0x0c075722u; return 0; }
r[3]=read(ram,0x0c075784u,4);
goto P_0c075724;
P_0c075724: /* original 432b, guest PC 0x0c075724 */
if(!s->budget--) { s->failed_pc=0x0c075724u; return 0; }
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
P_0c075726: /* original 0009, guest PC 0x0c075726 */
if(!s->budget--) { s->failed_pc=0x0c075726u; return 0; }
goto P_0c075728;
P_0c075728: /* original 9126, guest PC 0x0c075728 */
if(!s->budget--) { s->failed_pc=0x0c075728u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c075778u,2);
goto P_0c07572a;
P_0c07572a: /* original 8402, guest PC 0x0c07572a */
if(!s->budget--) { s->failed_pc=0x0c07572au; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[0]+2,1);
goto P_0c07572c;
P_0c07572c: /* original 31fc, guest PC 0x0c07572c */
if(!s->budget--) { s->failed_pc=0x0c07572cu; return 0; }
r[1]+=r[15];
goto P_0c07572e;
P_0c07572e: /* original d316, guest PC 0x0c07572e */
if(!s->budget--) { s->failed_pc=0x0c07572eu; return 0; }
r[3]=read(ram,0x0c075788u,4);
goto P_0c075730;
P_0c075730: /* original 6212, guest PC 0x0c075730 */
if(!s->budget--) { s->failed_pc=0x0c075730u; return 0; }
tmp=read(ram,r[1],4);
r[2]=tmp;
goto P_0c075732;
P_0c075732: /* original 600c, guest PC 0x0c075732 */
if(!s->budget--) { s->failed_pc=0x0c075732u; return 0; }
r[0]=r[0]&255u;
goto P_0c075734;
P_0c075734: /* original 4018, guest PC 0x0c075734 */
if(!s->budget--) { s->failed_pc=0x0c075734u; return 0; }
r[0]<<=8;
goto P_0c075736;
P_0c075736: /* original 911d, guest PC 0x0c075736 */
if(!s->budget--) { s->failed_pc=0x0c075736u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c075774u,2);
goto P_0c075738;
P_0c075738: /* original 7201, guest PC 0x0c075738 */
if(!s->budget--) { s->failed_pc=0x0c075738u; return 0; }
r[2]+=0x00000001u;
goto P_0c07573a;
P_0c07573a: /* original 2039, guest PC 0x0c07573a */
if(!s->budget--) { s->failed_pc=0x0c07573au; return 0; }
r[0]&=r[3];
goto P_0c07573c;
P_0c07573c: /* original 6320, guest PC 0x0c07573c */
if(!s->budget--) { s->failed_pc=0x0c07573cu; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[2],1);
r[3]=tmp;
goto P_0c07573e;
P_0c07573e: /* original 31fc, guest PC 0x0c07573e */
if(!s->budget--) { s->failed_pc=0x0c07573eu; return 0; }
r[1]+=r[15];
goto P_0c075740;
P_0c075740: /* original 633c, guest PC 0x0c075740 */
if(!s->budget--) { s->failed_pc=0x0c075740u; return 0; }
r[3]=r[3]&255u;
goto P_0c075742;
P_0c075742: /* original 203b, guest PC 0x0c075742 */
if(!s->budget--) { s->failed_pc=0x0c075742u; return 0; }
r[0]|=r[3];
goto P_0c075744;
P_0c075744: /* original 2102, guest PC 0x0c075744 */
if(!s->budget--) { s->failed_pc=0x0c075744u; return 0; }
write(ram,r[1],r[0],4);
goto P_0c075746;
P_0c075746: /* original 9013, guest PC 0x0c075746 */
if(!s->budget--) { s->failed_pc=0x0c075746u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c075770u,2);
goto P_0c075748;
P_0c075748: /* original d210, guest PC 0x0c075748 */
if(!s->budget--) { s->failed_pc=0x0c075748u; return 0; }
r[2]=read(ram,0x0c07578cu,4);
goto P_0c07574a;
P_0c07574a: /* original 03fe, guest PC 0x0c07574a */
if(!s->budget--) { s->failed_pc=0x0c07574au; return 0; }
r[3]=read(ram,r[15]+r[0],4);
goto P_0c07574c;
P_0c07574c: /* original 9012, guest PC 0x0c07574c */
if(!s->budget--) { s->failed_pc=0x0c07574cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c075774u,2);
goto P_0c07574e;
P_0c07574e: /* original 01fe, guest PC 0x0c07574e */
if(!s->budget--) { s->failed_pc=0x0c07574eu; return 0; }
r[1]=read(ram,r[15]+r[0],4);
goto P_0c075750;
P_0c075750: /* original 312c, guest PC 0x0c075750 */
if(!s->budget--) { s->failed_pc=0x0c075750u; return 0; }
r[1]+=r[2];
goto P_0c075752;
P_0c075752: /* original 131d, guest PC 0x0c075752 */
if(!s->budget--) { s->failed_pc=0x0c075752u; return 0; }
write(ram,r[3]+52,r[1],4);
goto P_0c075754;
P_0c075754: /* original 900c, guest PC 0x0c075754 */
if(!s->budget--) { s->failed_pc=0x0c075754u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c075770u,2);
goto P_0c075756;
P_0c075756: /* original 03fe, guest PC 0x0c075756 */
if(!s->budget--) { s->failed_pc=0x0c075756u; return 0; }
r[3]=read(ram,r[15]+r[0],4);
goto P_0c075758;
P_0c075758: /* original 900e, guest PC 0x0c075758 */
if(!s->budget--) { s->failed_pc=0x0c075758u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c075778u,2);
goto P_0c07575a;
P_0c07575a: /* original 01fe, guest PC 0x0c07575a */
if(!s->budget--) { s->failed_pc=0x0c07575au; return 0; }
r[1]=read(ram,r[15]+r[0],4);
goto P_0c07575c;
P_0c07575c: /* original 900d, guest PC 0x0c07575c */
if(!s->budget--) { s->failed_pc=0x0c07575cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07577au,2);
goto P_0c07575e;
P_0c07575e: /* original 7103, guest PC 0x0c07575e */
if(!s->budget--) { s->failed_pc=0x0c07575eu; return 0; }
r[1]+=0x00000003u;
goto P_0c075760;
P_0c075760: /* original 6110, guest PC 0x0c075760 */
if(!s->budget--) { s->failed_pc=0x0c075760u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[1],1);
r[1]=tmp;
goto P_0c075762;
P_0c075762: /* original 0314, guest PC 0x0c075762 */
if(!s->budget--) { s->failed_pc=0x0c075762u; return 0; }
write(ram,r[3]+r[0],r[1],1);
goto P_0c075764;
P_0c075764: /* original 910a, guest PC 0x0c075764 */
if(!s->budget--) { s->failed_pc=0x0c075764u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07577cu,2);
goto P_0c075766;
P_0c075766: /* original 3f1c, guest PC 0x0c075766 */
if(!s->budget--) { s->failed_pc=0x0c075766u; return 0; }
r[15]+=r[1];
goto P_0c075768;
P_0c075768: /* original 4f16, guest PC 0x0c075768 */
if(!s->budget--) { s->failed_pc=0x0c075768u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c07576a;
P_0c07576a: /* original 4f26, guest PC 0x0c07576a */
if(!s->budget--) { s->failed_pc=0x0c07576au; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c07576c;
P_0c07576c: /* original 000b, guest PC 0x0c07576c */
if(!s->budget--) { s->failed_pc=0x0c07576cu; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c07576e: /* original 0009, guest PC 0x0c07576e */
if(!s->budget--) { s->failed_pc=0x0c07576eu; return 0; }
return vf3_matrix_family(0x0c075770u,s,ram);
P_0c075790: /* original 908b, guest PC 0x0c075790 */
if(!s->budget--) { s->failed_pc=0x0c075790u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0758aau,2);
goto P_0c075792;
P_0c075792: /* original 02fe, guest PC 0x0c075792 */
if(!s->budget--) { s->failed_pc=0x0c075792u; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c075794;
P_0c075794: /* original 908a, guest PC 0x0c075794 */
if(!s->budget--) { s->failed_pc=0x0c075794u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0758acu,2);
goto P_0c075796;
P_0c075796: /* original 032e, guest PC 0x0c075796 */
if(!s->budget--) { s->failed_pc=0x0c075796u; return 0; }
r[3]=read(ram,r[2]+r[0],4);
goto P_0c075798;
P_0c075798: /* original 73ff, guest PC 0x0c075798 */
if(!s->budget--) { s->failed_pc=0x0c075798u; return 0; }
r[3]+=0xffffffffu;
goto P_0c07579a;
P_0c07579a: /* original 0236, guest PC 0x0c07579a */
if(!s->budget--) { s->failed_pc=0x0c07579au; return 0; }
write(ram,r[2]+r[0],r[3],4);
goto P_0c07579c;
P_0c07579c: /* original 9085, guest PC 0x0c07579c */
if(!s->budget--) { s->failed_pc=0x0c07579cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0758aau,2);
goto P_0c07579e;
P_0c07579e: /* original 02fe, guest PC 0x0c07579e */
if(!s->budget--) { s->failed_pc=0x0c07579eu; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c0757a0;
P_0c0757a0: /* original 9085, guest PC 0x0c0757a0 */
if(!s->budget--) { s->failed_pc=0x0c0757a0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0758aeu,2);
goto P_0c0757a2;
P_0c0757a2: /* original 032e, guest PC 0x0c0757a2 */
if(!s->budget--) { s->failed_pc=0x0c0757a2u; return 0; }
r[3]=read(ram,r[2]+r[0],4);
goto P_0c0757a4;
P_0c0757a4: /* original 7301, guest PC 0x0c0757a4 */
if(!s->budget--) { s->failed_pc=0x0c0757a4u; return 0; }
r[3]+=0x00000001u;
goto P_0c0757a6;
P_0c0757a6: /* original 0236, guest PC 0x0c0757a6 */
if(!s->budget--) { s->failed_pc=0x0c0757a6u; return 0; }
write(ram,r[2]+r[0],r[3],4);
goto P_0c0757a8;
P_0c0757a8: /* original d247, guest PC 0x0c0757a8 */
if(!s->budget--) { s->failed_pc=0x0c0757a8u; return 0; }
r[2]=read(ram,0x0c0758c8u,4);
goto P_0c0757aa;
P_0c0757aa: /* original 420b, guest PC 0x0c0757aa */
if(!s->budget--) { s->failed_pc=0x0c0757aau; return 0; }
target=r[2];
r[16]=0x0c0757aeu;
r[4]=0x00000063u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0757aeu) { target=s->pc; goto dispatch; }
goto P_0c0757ae;
P_0c0757ac: /* original e463, guest PC 0x0c0757ac */
if(!s->budget--) { s->failed_pc=0x0c0757acu; return 0; }
r[4]=0x00000063u;
goto P_0c0757ae;
P_0c0757ae: /* original d347, guest PC 0x0c0757ae */
if(!s->budget--) { s->failed_pc=0x0c0757aeu; return 0; }
r[3]=read(ram,0x0c0758ccu,4);
goto P_0c0757b0;
P_0c0757b0: /* original 430b, guest PC 0x0c0757b0 */
if(!s->budget--) { s->failed_pc=0x0c0757b0u; return 0; }
target=r[3];
r[16]=0x0c0757b4u;
r[4]=0x00000063u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0757b4u) { target=s->pc; goto dispatch; }
goto P_0c0757b4;
P_0c0757b2: /* original e463, guest PC 0x0c0757b2 */
if(!s->budget--) { s->failed_pc=0x0c0757b2u; return 0; }
r[4]=0x00000063u;
goto P_0c0757b4;
P_0c0757b4: /* original 9079, guest PC 0x0c0757b4 */
if(!s->budget--) { s->failed_pc=0x0c0757b4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0758aau,2);
goto P_0c0757b6;
P_0c0757b6: /* original e201, guest PC 0x0c0757b6 */
if(!s->budget--) { s->failed_pc=0x0c0757b6u; return 0; }
r[2]=0x00000001u;
goto P_0c0757b8;
P_0c0757b8: /* original 03fe, guest PC 0x0c0757b8 */
if(!s->budget--) { s->failed_pc=0x0c0757b8u; return 0; }
r[3]=read(ram,r[15]+r[0],4);
goto P_0c0757ba;
P_0c0757ba: /* original 9079, guest PC 0x0c0757ba */
if(!s->budget--) { s->failed_pc=0x0c0757bau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0758b0u,2);
goto P_0c0757bc;
P_0c0757bc: /* original 013e, guest PC 0x0c0757bc */
if(!s->budget--) { s->failed_pc=0x0c0757bcu; return 0; }
r[1]=read(ram,r[3]+r[0],4);
goto P_0c0757be;
P_0c0757be: /* original 212b, guest PC 0x0c0757be */
if(!s->budget--) { s->failed_pc=0x0c0757beu; return 0; }
r[1]|=r[2];
goto P_0c0757c0;
P_0c0757c0: /* original 0316, guest PC 0x0c0757c0 */
if(!s->budget--) { s->failed_pc=0x0c0757c0u; return 0; }
write(ram,r[3]+r[0],r[1],4);
goto P_0c0757c2;
P_0c0757c2: /* original 9072, guest PC 0x0c0757c2 */
if(!s->budget--) { s->failed_pc=0x0c0757c2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0758aau,2);
goto P_0c0757c4;
P_0c0757c4: /* original d142, guest PC 0x0c0757c4 */
if(!s->budget--) { s->failed_pc=0x0c0757c4u; return 0; }
r[1]=read(ram,0x0c0758d0u,4);
goto P_0c0757c6;
P_0c0757c6: /* original 03fe, guest PC 0x0c0757c6 */
if(!s->budget--) { s->failed_pc=0x0c0757c6u; return 0; }
r[3]=read(ram,r[15]+r[0],4);
goto P_0c0757c8;
P_0c0757c8: /* original e050, guest PC 0x0c0757c8 */
if(!s->budget--) { s->failed_pc=0x0c0757c8u; return 0; }
r[0]=0x00000050u;
goto P_0c0757ca;
P_0c0757ca: /* original 131c, guest PC 0x0c0757ca */
if(!s->budget--) { s->failed_pc=0x0c0757cau; return 0; }
write(ram,r[3]+48,r[1],4);
goto P_0c0757cc;
P_0c0757cc: /* original 61f3, guest PC 0x0c0757cc */
if(!s->budget--) { s->failed_pc=0x0c0757ccu; return 0; }
r[1]=r[15];
goto P_0c0757ce;
P_0c0757ce: /* original e300, guest PC 0x0c0757ce */
if(!s->budget--) { s->failed_pc=0x0c0757ceu; return 0; }
r[3]=0x00000000u;
goto P_0c0757d0;
P_0c0757d0: /* original 715c, guest PC 0x0c0757d0 */
if(!s->budget--) { s->failed_pc=0x0c0757d0u; return 0; }
r[1]+=0x0000005cu;
goto P_0c0757d2;
P_0c0757d2: /* original 0f36, guest PC 0x0c0757d2 */
if(!s->budget--) { s->failed_pc=0x0c0757d2u; return 0; }
write(ram,r[15]+r[0],r[3],4);
goto P_0c0757d4;
P_0c0757d4: /* original 2f16, guest PC 0x0c0757d4 */
if(!s->budget--) { s->failed_pc=0x0c0757d4u; return 0; }
r[15]-=4; write(ram,r[15],r[1],4);
goto P_0c0757d6;
P_0c0757d6: /* original 6633, guest PC 0x0c0757d6 */
if(!s->budget--) { s->failed_pc=0x0c0757d6u; return 0; }
r[6]=r[3];
goto P_0c0757d8;
P_0c0757d8: /* original 2f36, guest PC 0x0c0757d8 */
if(!s->budget--) { s->failed_pc=0x0c0757d8u; return 0; }
r[15]-=4; write(ram,r[15],r[3],4);
goto P_0c0757da;
P_0c0757da: /* original 906b, guest PC 0x0c0757da */
if(!s->budget--) { s->failed_pc=0x0c0757dau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0758b4u,2);
goto P_0c0757dc;
P_0c0757dc: /* original 9769, guest PC 0x0c0757dc */
if(!s->budget--) { s->failed_pc=0x0c0757dcu; return 0; }
r[7]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0758b2u,2);
goto P_0c0757de;
P_0c0757de: /* original 05fe, guest PC 0x0c0757de */
if(!s->budget--) { s->failed_pc=0x0c0757deu; return 0; }
r[5]=read(ram,r[15]+r[0],4);
goto P_0c0757e0;
P_0c0757e0: /* original 9069, guest PC 0x0c0757e0 */
if(!s->budget--) { s->failed_pc=0x0c0757e0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0758b6u,2);
goto P_0c0757e2;
P_0c0757e2: /* original 37fc, guest PC 0x0c0757e2 */
if(!s->budget--) { s->failed_pc=0x0c0757e2u; return 0; }
r[7]+=r[15];
goto P_0c0757e4;
P_0c0757e4: /* original b98b, guest PC 0x0c0757e4 */
if(!s->budget--) { s->failed_pc=0x0c0757e4u; return 0; }
target=0x0c074afeu; r[16]=0x0c0757e8u;
r[4]=read(ram,r[15]+r[0],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0757e8u) { target=s->pc; goto dispatch; }
goto P_0c0757e8;
P_0c0757e6: /* original 04fe, guest PC 0x0c0757e6 */
if(!s->budget--) { s->failed_pc=0x0c0757e6u; return 0; }
r[4]=read(ram,r[15]+r[0],4);
goto P_0c0757e8;
P_0c0757e8: /* original 9063, guest PC 0x0c0757e8 */
if(!s->budget--) { s->failed_pc=0x0c0757e8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0758b2u,2);
goto P_0c0757ea;
P_0c0757ea: /* original 7f08, guest PC 0x0c0757ea */
if(!s->budget--) { s->failed_pc=0x0c0757eau; return 0; }
r[15]+=0x00000008u;
goto P_0c0757ec;
P_0c0757ec: /* original d239, guest PC 0x0c0757ec */
if(!s->budget--) { s->failed_pc=0x0c0757ecu; return 0; }
r[2]=read(ram,0x0c0758d4u,4);
goto P_0c0757ee;
P_0c0757ee: /* original 03fe, guest PC 0x0c0757ee */
if(!s->budget--) { s->failed_pc=0x0c0757eeu; return 0; }
r[3]=read(ram,r[15]+r[0],4);
goto P_0c0757f0;
P_0c0757f0: /* original 9062, guest PC 0x0c0757f0 */
if(!s->budget--) { s->failed_pc=0x0c0757f0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0758b8u,2);
goto P_0c0757f2;
P_0c0757f2: /* original 01fe, guest PC 0x0c0757f2 */
if(!s->budget--) { s->failed_pc=0x0c0757f2u; return 0; }
r[1]=read(ram,r[15]+r[0],4);
goto P_0c0757f4;
P_0c0757f4: /* original 312c, guest PC 0x0c0757f4 */
if(!s->budget--) { s->failed_pc=0x0c0757f4u; return 0; }
r[1]+=r[2];
goto P_0c0757f6;
P_0c0757f6: /* original 131d, guest PC 0x0c0757f6 */
if(!s->budget--) { s->failed_pc=0x0c0757f6u; return 0; }
write(ram,r[3]+52,r[1],4);
goto P_0c0757f8;
P_0c0757f8: /* original 905b, guest PC 0x0c0757f8 */
if(!s->budget--) { s->failed_pc=0x0c0757f8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0758b2u,2);
goto P_0c0757fa;
P_0c0757fa: /* original 03fe, guest PC 0x0c0757fa */
if(!s->budget--) { s->failed_pc=0x0c0757fau; return 0; }
r[3]=read(ram,r[15]+r[0],4);
goto P_0c0757fc;
P_0c0757fc: /* original 9055, guest PC 0x0c0757fc */
if(!s->budget--) { s->failed_pc=0x0c0757fcu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0758aau,2);
goto P_0c0757fe;
P_0c0757fe: /* original 01fe, guest PC 0x0c0757fe */
if(!s->budget--) { s->failed_pc=0x0c0757feu; return 0; }
r[1]=read(ram,r[15]+r[0],4);
goto P_0c075800;
P_0c075800: /* original 905b, guest PC 0x0c075800 */
if(!s->budget--) { s->failed_pc=0x0c075800u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0758bau,2);
goto P_0c075802;
P_0c075802: /* original 011d, guest PC 0x0c075802 */
if(!s->budget--) { s->failed_pc=0x0c075802u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,r[1]+r[0],2);
goto P_0c075804;
P_0c075804: /* original 7004, guest PC 0x0c075804 */
if(!s->budget--) { s->failed_pc=0x0c075804u; return 0; }
r[0]+=0x00000004u;
goto P_0c075806;
P_0c075806: /* original 0315, guest PC 0x0c075806 */
if(!s->budget--) { s->failed_pc=0x0c075806u; return 0; }
write(ram,r[3]+r[0],r[1],2);
goto P_0c075808;
P_0c075808: /* original 904f, guest PC 0x0c075808 */
if(!s->budget--) { s->failed_pc=0x0c075808u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0758aau,2);
goto P_0c07580a;
P_0c07580a: /* original 9157, guest PC 0x0c07580a */
if(!s->budget--) { s->failed_pc=0x0c07580au; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0758bcu,2);
goto P_0c07580c;
P_0c07580c: /* original 00fe, guest PC 0x0c07580c */
if(!s->budget--) { s->failed_pc=0x0c07580cu; return 0; }
r[0]=read(ram,r[15]+r[0],4);
goto P_0c07580e;
P_0c07580e: /* original 001d, guest PC 0x0c07580e */
if(!s->budget--) { s->failed_pc=0x0c07580eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[1]+r[0],2);
goto P_0c075810;
P_0c075810: /* original c802, guest PC 0x0c075810 */
if(!s->budget--) { s->failed_pc=0x0c075810u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&2u)==0)!=0);
goto P_0c075812;
P_0c075812: /* original 890d, guest PC 0x0c075812 */
if(!s->budget--) { s->failed_pc=0x0c075812u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c075830; }
goto P_0c075814;
P_0c075814: /* original 9049, guest PC 0x0c075814 */
if(!s->budget--) { s->failed_pc=0x0c075814u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0758aau,2);
goto P_0c075816;
P_0c075816: /* original 02fe, guest PC 0x0c075816 */
if(!s->budget--) { s->failed_pc=0x0c075816u; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c075818;
P_0c075818: /* original 9051, guest PC 0x0c075818 */
if(!s->budget--) { s->failed_pc=0x0c075818u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0758beu,2);
goto P_0c07581a;
P_0c07581a: /* original 6323, guest PC 0x0c07581a */
if(!s->budget--) { s->failed_pc=0x0c07581au; return 0; }
r[3]=r[2];
goto P_0c07581c;
P_0c07581c: /* original 033e, guest PC 0x0c07581c */
if(!s->budget--) { s->failed_pc=0x0c07581cu; return 0; }
r[3]=read(ram,r[3]+r[0],4);
goto P_0c07581e;
P_0c07581e: /* original 70f4, guest PC 0x0c07581e */
if(!s->budget--) { s->failed_pc=0x0c07581eu; return 0; }
r[0]+=0xfffffff4u;
goto P_0c075820;
P_0c075820: /* original 0236, guest PC 0x0c075820 */
if(!s->budget--) { s->failed_pc=0x0c075820u; return 0; }
write(ram,r[2]+r[0],r[3],4);
goto P_0c075822;
P_0c075822: /* original 9042, guest PC 0x0c075822 */
if(!s->budget--) { s->failed_pc=0x0c075822u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0758aau,2);
goto P_0c075824;
P_0c075824: /* original 02fe, guest PC 0x0c075824 */
if(!s->budget--) { s->failed_pc=0x0c075824u; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c075826;
P_0c075826: /* original 904b, guest PC 0x0c075826 */
if(!s->budget--) { s->failed_pc=0x0c075826u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0758c0u,2);
goto P_0c075828;
P_0c075828: /* original 6323, guest PC 0x0c075828 */
if(!s->budget--) { s->failed_pc=0x0c075828u; return 0; }
r[3]=r[2];
goto P_0c07582a;
P_0c07582a: /* original 033d, guest PC 0x0c07582a */
if(!s->budget--) { s->failed_pc=0x0c07582au; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[3]+r[0],2);
goto P_0c07582c;
P_0c07582c: /* original 70fa, guest PC 0x0c07582c */
if(!s->budget--) { s->failed_pc=0x0c07582cu; return 0; }
r[0]+=0xfffffffau;
goto P_0c07582e;
P_0c07582e: /* original 0235, guest PC 0x0c07582e */
if(!s->budget--) { s->failed_pc=0x0c07582eu; return 0; }
write(ram,r[2]+r[0],r[3],2);
goto P_0c075830;
P_0c075830: /* original 903b, guest PC 0x0c075830 */
if(!s->budget--) { s->failed_pc=0x0c075830u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0758aau,2);
goto P_0c075832;
P_0c075832: /* original 02fe, guest PC 0x0c075832 */
if(!s->budget--) { s->failed_pc=0x0c075832u; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c075834;
P_0c075834: /* original 9045, guest PC 0x0c075834 */
if(!s->budget--) { s->failed_pc=0x0c075834u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0758c2u,2);
goto P_0c075836;
P_0c075836: /* original 032c, guest PC 0x0c075836 */
if(!s->budget--) { s->failed_pc=0x0c075836u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[2]+r[0],1);
goto P_0c075838;
P_0c075838: /* original 903e, guest PC 0x0c075838 */
if(!s->budget--) { s->failed_pc=0x0c075838u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0758b8u,2);
goto P_0c07583a;
P_0c07583a: /* original 633c, guest PC 0x0c07583a */
if(!s->budget--) { s->failed_pc=0x0c07583au; return 0; }
r[3]=r[3]&255u;
goto P_0c07583c;
P_0c07583c: /* original 2338, guest PC 0x0c07583c */
if(!s->budget--) { s->failed_pc=0x0c07583cu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c07583e;
P_0c07583e: /* original 8f10, guest PC 0x0c07583e */
if(!s->budget--) { s->failed_pc=0x0c07583eu; return 0; }
cond=r[17]&1u;
write(ram,r[15]+r[0],r[3],4);
if(!cond) { goto P_0c075862; }
goto P_0c075842;
P_0c075840: /* original 0f36, guest PC 0x0c075840 */
if(!s->budget--) { s->failed_pc=0x0c075840u; return 0; }
write(ram,r[15]+r[0],r[3],4);
goto P_0c075842;
P_0c075842: /* original e054, guest PC 0x0c075842 */
if(!s->budget--) { s->failed_pc=0x0c075842u; return 0; }
r[0]=0x00000054u;
goto P_0c075844;
P_0c075844: /* original d224, guest PC 0x0c075844 */
if(!s->budget--) { s->failed_pc=0x0c075844u; return 0; }
r[2]=read(ram,0x0c0758d8u,4);
goto P_0c075846;
P_0c075846: /* original 01fe, guest PC 0x0c075846 */
if(!s->budget--) { s->failed_pc=0x0c075846u; return 0; }
r[1]=read(ram,r[15]+r[0],4);
goto P_0c075848;
P_0c075848: /* original 420b, guest PC 0x0c075848 */
if(!s->budget--) { s->failed_pc=0x0c075848u; return 0; }
target=r[2];
r[16]=0x0c07584cu;
r[0]=0x00000003u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07584cu) { target=s->pc; goto dispatch; }
goto P_0c07584c;
P_0c07584a: /* original e003, guest PC 0x0c07584a */
if(!s->budget--) { s->failed_pc=0x0c07584au; return 0; }
r[0]=0x00000003u;
goto P_0c07584c;
P_0c07584c: /* original 9134, guest PC 0x0c07584c */
if(!s->budget--) { s->failed_pc=0x0c07584cu; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0758b8u,2);
goto P_0c07584e;
P_0c07584e: /* original 4000, guest PC 0x0c07584e */
if(!s->budget--) { s->failed_pc=0x0c07584eu; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c075850;
P_0c075850: /* original e318, guest PC 0x0c075850 */
if(!s->budget--) { s->failed_pc=0x0c075850u; return 0; }
r[3]=0x00000018u;
goto P_0c075852;
P_0c075852: /* original 7006, guest PC 0x0c075852 */
if(!s->budget--) { s->failed_pc=0x0c075852u; return 0; }
r[0]+=0x00000006u;
goto P_0c075854;
P_0c075854: /* original 3036, guest PC 0x0c075854 */
if(!s->budget--) { s->failed_pc=0x0c075854u; return 0; }
r[17]=(r[17]&~1u)|((r[0]>r[3])!=0);
goto P_0c075856;
P_0c075856: /* original 31fc, guest PC 0x0c075856 */
if(!s->budget--) { s->failed_pc=0x0c075856u; return 0; }
r[1]+=r[15];
goto P_0c075858;
P_0c075858: /* original 8f03, guest PC 0x0c075858 */
if(!s->budget--) { s->failed_pc=0x0c075858u; return 0; }
cond=r[17]&1u;
write(ram,r[1],r[0],4);
if(!cond) { goto P_0c075862; }
goto P_0c07585c;
P_0c07585a: /* original 2102, guest PC 0x0c07585a */
if(!s->budget--) { s->failed_pc=0x0c07585au; return 0; }
write(ram,r[1],r[0],4);
goto P_0c07585c;
P_0c07585c: /* original 902c, guest PC 0x0c07585c */
if(!s->budget--) { s->failed_pc=0x0c07585cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0758b8u,2);
goto P_0c07585e;
P_0c07585e: /* original e118, guest PC 0x0c07585e */
if(!s->budget--) { s->failed_pc=0x0c07585eu; return 0; }
r[1]=0x00000018u;
goto P_0c075860;
P_0c075860: /* original 0f16, guest PC 0x0c075860 */
if(!s->budget--) { s->failed_pc=0x0c075860u; return 0; }
write(ram,r[15]+r[0],r[1],4);
goto P_0c075862;
P_0c075862: /* original 9026, guest PC 0x0c075862 */
if(!s->budget--) { s->failed_pc=0x0c075862u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0758b2u,2);
goto P_0c075864;
P_0c075864: /* original 03fe, guest PC 0x0c075864 */
if(!s->budget--) { s->failed_pc=0x0c075864u; return 0; }
r[3]=read(ram,r[15]+r[0],4);
goto P_0c075866;
P_0c075866: /* original 9027, guest PC 0x0c075866 */
if(!s->budget--) { s->failed_pc=0x0c075866u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0758b8u,2);
goto P_0c075868;
P_0c075868: /* original 02fd, guest PC 0x0c075868 */
if(!s->budget--) { s->failed_pc=0x0c075868u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+r[0],2);
goto P_0c07586a;
P_0c07586a: /* original e066, guest PC 0x0c07586a */
if(!s->budget--) { s->failed_pc=0x0c07586au; return 0; }
r[0]=0x00000066u;
goto P_0c07586c;
P_0c07586c: /* original 0325, guest PC 0x0c07586c */
if(!s->budget--) { s->failed_pc=0x0c07586cu; return 0; }
write(ram,r[3]+r[0],r[2],2);
goto P_0c07586e;
P_0c07586e: /* original e21e, guest PC 0x0c07586e */
if(!s->budget--) { s->failed_pc=0x0c07586eu; return 0; }
r[2]=0x0000001eu;
goto P_0c075870;
P_0c075870: /* original 9022, guest PC 0x0c075870 */
if(!s->budget--) { s->failed_pc=0x0c075870u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0758b8u,2);
goto P_0c075872;
P_0c075872: /* original 03fe, guest PC 0x0c075872 */
if(!s->budget--) { s->failed_pc=0x0c075872u; return 0; }
r[3]=read(ram,r[15]+r[0],4);
goto P_0c075874;
P_0c075874: /* original 9020, guest PC 0x0c075874 */
if(!s->budget--) { s->failed_pc=0x0c075874u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0758b8u,2);
goto P_0c075876;
P_0c075876: /* original 7308, guest PC 0x0c075876 */
if(!s->budget--) { s->failed_pc=0x0c075876u; return 0; }
r[3]+=0x00000008u;
goto P_0c075878;
P_0c075878: /* original 3326, guest PC 0x0c075878 */
if(!s->budget--) { s->failed_pc=0x0c075878u; return 0; }
r[17]=(r[17]&~1u)|((r[3]>r[2])!=0);
goto P_0c07587a;
P_0c07587a: /* original 8f04, guest PC 0x0c07587a */
if(!s->budget--) { s->failed_pc=0x0c07587au; return 0; }
cond=r[17]&1u;
write(ram,r[15]+r[0],r[3],4);
if(!cond) { goto P_0c075886; }
goto P_0c07587e;
P_0c07587c: /* original 0f36, guest PC 0x0c07587c */
if(!s->budget--) { s->failed_pc=0x0c07587cu; return 0; }
write(ram,r[15]+r[0],r[3],4);
goto P_0c07587e;
P_0c07587e: /* original 911b, guest PC 0x0c07587e */
if(!s->budget--) { s->failed_pc=0x0c07587eu; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0758b8u,2);
goto P_0c075880;
P_0c075880: /* original e01e, guest PC 0x0c075880 */
if(!s->budget--) { s->failed_pc=0x0c075880u; return 0; }
r[0]=0x0000001eu;
goto P_0c075882;
P_0c075882: /* original 31fc, guest PC 0x0c075882 */
if(!s->budget--) { s->failed_pc=0x0c075882u; return 0; }
r[1]+=r[15];
goto P_0c075884;
P_0c075884: /* original 2102, guest PC 0x0c075884 */
if(!s->budget--) { s->failed_pc=0x0c075884u; return 0; }
write(ram,r[1],r[0],4);
goto P_0c075886;
P_0c075886: /* original 9014, guest PC 0x0c075886 */
if(!s->budget--) { s->failed_pc=0x0c075886u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0758b2u,2);
goto P_0c075888;
P_0c075888: /* original 03fe, guest PC 0x0c075888 */
if(!s->budget--) { s->failed_pc=0x0c075888u; return 0; }
r[3]=read(ram,r[15]+r[0],4);
goto P_0c07588a;
P_0c07588a: /* original 9015, guest PC 0x0c07588a */
if(!s->budget--) { s->failed_pc=0x0c07588au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0758b8u,2);
goto P_0c07588c;
P_0c07588c: /* original 02fc, guest PC 0x0c07588c */
if(!s->budget--) { s->failed_pc=0x0c07588cu; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[15]+r[0],1);
goto P_0c07588e;
P_0c07588e: /* original 9019, guest PC 0x0c07588e */
if(!s->budget--) { s->failed_pc=0x0c07588eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0758c4u,2);
goto P_0c075890;
P_0c075890: /* original 0324, guest PC 0x0c075890 */
if(!s->budget--) { s->failed_pc=0x0c075890u; return 0; }
write(ram,r[3]+r[0],r[2],1);
goto P_0c075892;
P_0c075892: /* original 900a, guest PC 0x0c075892 */
if(!s->budget--) { s->failed_pc=0x0c075892u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0758aau,2);
goto P_0c075894;
P_0c075894: /* original 03fe, guest PC 0x0c075894 */
if(!s->budget--) { s->failed_pc=0x0c075894u; return 0; }
r[3]=read(ram,r[15]+r[0],4);
goto P_0c075896;
P_0c075896: /* original 900f, guest PC 0x0c075896 */
if(!s->budget--) { s->failed_pc=0x0c075896u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0758b8u,2);
goto P_0c075898;
P_0c075898: /* original 02fc, guest PC 0x0c075898 */
if(!s->budget--) { s->failed_pc=0x0c075898u; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[15]+r[0],1);
goto P_0c07589a;
P_0c07589a: /* original 9013, guest PC 0x0c07589a */
if(!s->budget--) { s->failed_pc=0x0c07589au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0758c4u,2);
goto P_0c07589c;
P_0c07589c: /* original 0324, guest PC 0x0c07589c */
if(!s->budget--) { s->failed_pc=0x0c07589cu; return 0; }
write(ram,r[3]+r[0],r[2],1);
goto P_0c07589e;
P_0c07589e: /* original e054, guest PC 0x0c07589e */
if(!s->budget--) { s->failed_pc=0x0c07589eu; return 0; }
r[0]=0x00000054u;
goto P_0c0758a0;
P_0c0758a0: /* original e300, guest PC 0x0c0758a0 */
if(!s->budget--) { s->failed_pc=0x0c0758a0u; return 0; }
r[3]=0x00000000u;
goto P_0c0758a2;
P_0c0758a2: /* original 6233, guest PC 0x0c0758a2 */
if(!s->budget--) { s->failed_pc=0x0c0758a2u; return 0; }
r[2]=r[3];
goto P_0c0758a4;
P_0c0758a4: /* original 0f36, guest PC 0x0c0758a4 */
if(!s->budget--) { s->failed_pc=0x0c0758a4u; return 0; }
write(ram,r[15]+r[0],r[3],4);
goto P_0c0758a6;
P_0c0758a6: /* original a50b, guest PC 0x0c0758a6 */
if(!s->budget--) { s->failed_pc=0x0c0758a6u; return 0; }
goto P_0c0762c0;
P_0c0758a8: /* original 0009, guest PC 0x0c0758a8 */
if(!s->budget--) { s->failed_pc=0x0c0758a8u; return 0; }
return vf3_matrix_family(0x0c0758aau,s,ram);
P_0c0758dc: /* original e050, guest PC 0x0c0758dc */
if(!s->budget--) { s->failed_pc=0x0c0758dcu; return 0; }
r[0]=0x00000050u;
goto P_0c0758de;
P_0c0758de: /* original e102, guest PC 0x0c0758de */
if(!s->budget--) { s->failed_pc=0x0c0758deu; return 0; }
r[1]=0x00000002u;
goto P_0c0758e0;
P_0c0758e0: /* original 0f16, guest PC 0x0c0758e0 */
if(!s->budget--) { s->failed_pc=0x0c0758e0u; return 0; }
write(ram,r[15]+r[0],r[1],4);
goto P_0c0758e2;
P_0c0758e2: /* original 9085, guest PC 0x0c0758e2 */
if(!s->budget--) { s->failed_pc=0x0c0758e2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0759f0u,2);
goto P_0c0758e4;
P_0c0758e4: /* original e202, guest PC 0x0c0758e4 */
if(!s->budget--) { s->failed_pc=0x0c0758e4u; return 0; }
r[2]=0x00000002u;
goto P_0c0758e6;
P_0c0758e6: /* original 03fe, guest PC 0x0c0758e6 */
if(!s->budget--) { s->failed_pc=0x0c0758e6u; return 0; }
r[3]=read(ram,r[15]+r[0],4);
goto P_0c0758e8;
P_0c0758e8: /* original 9083, guest PC 0x0c0758e8 */
if(!s->budget--) { s->failed_pc=0x0c0758e8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0759f2u,2);
goto P_0c0758ea;
P_0c0758ea: /* original 013e, guest PC 0x0c0758ea */
if(!s->budget--) { s->failed_pc=0x0c0758eau; return 0; }
r[1]=read(ram,r[3]+r[0],4);
goto P_0c0758ec;
P_0c0758ec: /* original 212b, guest PC 0x0c0758ec */
if(!s->budget--) { s->failed_pc=0x0c0758ecu; return 0; }
r[1]|=r[2];
goto P_0c0758ee;
P_0c0758ee: /* original 0316, guest PC 0x0c0758ee */
if(!s->budget--) { s->failed_pc=0x0c0758eeu; return 0; }
write(ram,r[3]+r[0],r[1],4);
goto P_0c0758f0;
P_0c0758f0: /* original 9080, guest PC 0x0c0758f0 */
if(!s->budget--) { s->failed_pc=0x0c0758f0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0759f4u,2);
goto P_0c0758f2;
P_0c0758f2: /* original 03fe, guest PC 0x0c0758f2 */
if(!s->budget--) { s->failed_pc=0x0c0758f2u; return 0; }
r[3]=read(ram,r[15]+r[0],4);
goto P_0c0758f4;
P_0c0758f4: /* original 907f, guest PC 0x0c0758f4 */
if(!s->budget--) { s->failed_pc=0x0c0758f4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0759f6u,2);
goto P_0c0758f6;
P_0c0758f6: /* original 013c, guest PC 0x0c0758f6 */
if(!s->budget--) { s->failed_pc=0x0c0758f6u; return 0; }
r[1]=(uint32_t)(int32_t)(int8_t)read(ram,r[3]+r[0],1);
goto P_0c0758f8;
P_0c0758f8: /* original 7101, guest PC 0x0c0758f8 */
if(!s->budget--) { s->failed_pc=0x0c0758f8u; return 0; }
r[1]+=0x00000001u;
goto P_0c0758fa;
P_0c0758fa: /* original 0314, guest PC 0x0c0758fa */
if(!s->budget--) { s->failed_pc=0x0c0758fau; return 0; }
write(ram,r[3]+r[0],r[1],1);
goto P_0c0758fc;
P_0c0758fc: /* original 9078, guest PC 0x0c0758fc */
if(!s->budget--) { s->failed_pc=0x0c0758fcu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0759f0u,2);
goto P_0c0758fe;
P_0c0758fe: /* original d144, guest PC 0x0c0758fe */
if(!s->budget--) { s->failed_pc=0x0c0758feu; return 0; }
r[1]=read(ram,0x0c075a10u,4);
goto P_0c075900;
P_0c075900: /* original 03fe, guest PC 0x0c075900 */
if(!s->budget--) { s->failed_pc=0x0c075900u; return 0; }
r[3]=read(ram,r[15]+r[0],4);
goto P_0c075902;
P_0c075902: /* original 131c, guest PC 0x0c075902 */
if(!s->budget--) { s->failed_pc=0x0c075902u; return 0; }
write(ram,r[3]+48,r[1],4);
goto P_0c075904;
P_0c075904: /* original 9074, guest PC 0x0c075904 */
if(!s->budget--) { s->failed_pc=0x0c075904u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0759f0u,2);
goto P_0c075906;
P_0c075906: /* original 9177, guest PC 0x0c075906 */
if(!s->budget--) { s->failed_pc=0x0c075906u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0759f8u,2);
goto P_0c075908;
P_0c075908: /* original 00fe, guest PC 0x0c075908 */
if(!s->budget--) { s->failed_pc=0x0c075908u; return 0; }
r[0]=read(ram,r[15]+r[0],4);
goto P_0c07590a;
P_0c07590a: /* original 001d, guest PC 0x0c07590a */
if(!s->budget--) { s->failed_pc=0x0c07590au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[1]+r[0],2);
goto P_0c07590c;
P_0c07590c: /* original c801, guest PC 0x0c07590c */
if(!s->budget--) { s->failed_pc=0x0c07590cu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&1u)==0)!=0);
goto P_0c07590e;
P_0c07590e: /* original 890e, guest PC 0x0c07590e */
if(!s->budget--) { s->failed_pc=0x0c07590eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07592e; }
goto P_0c075910;
P_0c075910: /* original 906e, guest PC 0x0c075910 */
if(!s->budget--) { s->failed_pc=0x0c075910u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0759f0u,2);
goto P_0c075912;
P_0c075912: /* original 9272, guest PC 0x0c075912 */
if(!s->budget--) { s->failed_pc=0x0c075912u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0759fau,2);
goto P_0c075914;
P_0c075914: /* original 03fe, guest PC 0x0c075914 */
if(!s->budget--) { s->failed_pc=0x0c075914u; return 0; }
r[3]=read(ram,r[15]+r[0],4);
goto P_0c075916;
P_0c075916: /* original 9171, guest PC 0x0c075916 */
if(!s->budget--) { s->failed_pc=0x0c075916u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0759fcu,2);
goto P_0c075918;
P_0c075918: /* original 6033, guest PC 0x0c075918 */
if(!s->budget--) { s->failed_pc=0x0c075918u; return 0; }
r[0]=r[3];
goto P_0c07591a;
P_0c07591a: /* original 002e, guest PC 0x0c07591a */
if(!s->budget--) { s->failed_pc=0x0c07591au; return 0; }
r[0]=read(ram,r[2]+r[0],4);
goto P_0c07591c;
P_0c07591c: /* original 313c, guest PC 0x0c07591c */
if(!s->budget--) { s->failed_pc=0x0c07591cu; return 0; }
r[1]+=r[3];
goto P_0c07591e;
P_0c07591e: /* original 2102, guest PC 0x0c07591e */
if(!s->budget--) { s->failed_pc=0x0c07591eu; return 0; }
write(ram,r[1],r[0],4);
goto P_0c075920;
P_0c075920: /* original 9066, guest PC 0x0c075920 */
if(!s->budget--) { s->failed_pc=0x0c075920u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0759f0u,2);
goto P_0c075922;
P_0c075922: /* original 03fe, guest PC 0x0c075922 */
if(!s->budget--) { s->failed_pc=0x0c075922u; return 0; }
r[3]=read(ram,r[15]+r[0],4);
goto P_0c075924;
P_0c075924: /* original 906b, guest PC 0x0c075924 */
if(!s->budget--) { s->failed_pc=0x0c075924u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0759feu,2);
goto P_0c075926;
P_0c075926: /* original 6133, guest PC 0x0c075926 */
if(!s->budget--) { s->failed_pc=0x0c075926u; return 0; }
r[1]=r[3];
goto P_0c075928;
P_0c075928: /* original 011d, guest PC 0x0c075928 */
if(!s->budget--) { s->failed_pc=0x0c075928u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,r[1]+r[0],2);
goto P_0c07592a;
P_0c07592a: /* original 70fa, guest PC 0x0c07592a */
if(!s->budget--) { s->failed_pc=0x0c07592au; return 0; }
r[0]+=0xfffffffau;
goto P_0c07592c;
P_0c07592c: /* original 0315, guest PC 0x0c07592c */
if(!s->budget--) { s->failed_pc=0x0c07592cu; return 0; }
write(ram,r[3]+r[0],r[1],2);
goto P_0c07592e;
P_0c07592e: /* original 9061, guest PC 0x0c07592e */
if(!s->budget--) { s->failed_pc=0x0c07592eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0759f4u,2);
goto P_0c075930;
P_0c075930: /* original 03fe, guest PC 0x0c075930 */
if(!s->budget--) { s->failed_pc=0x0c075930u; return 0; }
r[3]=read(ram,r[15]+r[0],4);
goto P_0c075932;
P_0c075932: /* original 9065, guest PC 0x0c075932 */
if(!s->budget--) { s->failed_pc=0x0c075932u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c075a00u,2);
goto P_0c075934;
P_0c075934: /* original 023e, guest PC 0x0c075934 */
if(!s->budget--) { s->failed_pc=0x0c075934u; return 0; }
r[2]=read(ram,r[3]+r[0],4);
goto P_0c075936;
P_0c075936: /* original 9064, guest PC 0x0c075936 */
if(!s->budget--) { s->failed_pc=0x0c075936u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c075a02u,2);
goto P_0c075938;
P_0c075938: /* original 0f26, guest PC 0x0c075938 */
if(!s->budget--) { s->failed_pc=0x0c075938u; return 0; }
write(ram,r[15]+r[0],r[2],4);
goto P_0c07593a;
P_0c07593a: /* original 9059, guest PC 0x0c07593a */
if(!s->budget--) { s->failed_pc=0x0c07593au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0759f0u,2);
goto P_0c07593c;
P_0c07593c: /* original 03fe, guest PC 0x0c07593c */
if(!s->budget--) { s->failed_pc=0x0c07593cu; return 0; }
r[3]=read(ram,r[15]+r[0],4);
goto P_0c07593e;
P_0c07593e: /* original 9058, guest PC 0x0c07593e */
if(!s->budget--) { s->failed_pc=0x0c07593eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0759f2u,2);
goto P_0c075940;
P_0c075940: /* original 023e, guest PC 0x0c075940 */
if(!s->budget--) { s->failed_pc=0x0c075940u; return 0; }
r[2]=read(ram,r[3]+r[0],4);
goto P_0c075942;
P_0c075942: /* original e04c, guest PC 0x0c075942 */
if(!s->budget--) { s->failed_pc=0x0c075942u; return 0; }
r[0]=0x0000004cu;
goto P_0c075944;
P_0c075944: /* original 0f26, guest PC 0x0c075944 */
if(!s->budget--) { s->failed_pc=0x0c075944u; return 0; }
write(ram,r[15]+r[0],r[2],4);
goto P_0c075946;
P_0c075946: /* original e054, guest PC 0x0c075946 */
if(!s->budget--) { s->failed_pc=0x0c075946u; return 0; }
r[0]=0x00000054u;
goto P_0c075948;
P_0c075948: /* original 03fe, guest PC 0x0c075948 */
if(!s->budget--) { s->failed_pc=0x0c075948u; return 0; }
r[3]=read(ram,r[15]+r[0],4);
goto P_0c07594a;
P_0c07594a: /* original e200, guest PC 0x0c07594a */
if(!s->budget--) { s->failed_pc=0x0c07594au; return 0; }
r[2]=0x00000000u;
goto P_0c07594c;
P_0c07594c: /* original 905a, guest PC 0x0c07594c */
if(!s->budget--) { s->failed_pc=0x0c07594cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c075a04u,2);
goto P_0c07594e;
P_0c07594e: /* original 0f36, guest PC 0x0c07594e */
if(!s->budget--) { s->failed_pc=0x0c07594eu; return 0; }
write(ram,r[15]+r[0],r[3],4);
goto P_0c075950;
P_0c075950: /* original 9059, guest PC 0x0c075950 */
if(!s->budget--) { s->failed_pc=0x0c075950u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c075a06u,2);
goto P_0c075952;
P_0c075952: /* original 0f26, guest PC 0x0c075952 */
if(!s->budget--) { s->failed_pc=0x0c075952u; return 0; }
write(ram,r[15]+r[0],r[2],4);
goto P_0c075954;
P_0c075954: /* original 904c, guest PC 0x0c075954 */
if(!s->budget--) { s->failed_pc=0x0c075954u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0759f0u,2);
goto P_0c075956;
P_0c075956: /* original 9257, guest PC 0x0c075956 */
if(!s->budget--) { s->failed_pc=0x0c075956u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c075a08u,2);
goto P_0c075958;
P_0c075958: /* original 03fe, guest PC 0x0c075958 */
if(!s->budget--) { s->failed_pc=0x0c075958u; return 0; }
r[3]=read(ram,r[15]+r[0],4);
goto P_0c07595a;
P_0c07595a: /* original e04c, guest PC 0x0c07595a */
if(!s->budget--) { s->failed_pc=0x0c07595au; return 0; }
r[0]=0x0000004cu;
goto P_0c07595c;
P_0c07595c: /* original 013e, guest PC 0x0c07595c */
if(!s->budget--) { s->failed_pc=0x0c07595cu; return 0; }
r[1]=read(ram,r[3]+r[0],4);
goto P_0c07595e;
P_0c07595e: /* original 2128, guest PC 0x0c07595e */
if(!s->budget--) { s->failed_pc=0x0c07595eu; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[2])==0)!=0);
goto P_0c075960;
P_0c075960: /* original 8b77, guest PC 0x0c075960 */
if(!s->budget--) { s->failed_pc=0x0c075960u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c075a52; }
goto P_0c075962;
P_0c075962: /* original 63f3, guest PC 0x0c075962 */
if(!s->budget--) { s->failed_pc=0x0c075962u; return 0; }
r[3]=r[15];
goto P_0c075964;
P_0c075964: /* original 736c, guest PC 0x0c075964 */
if(!s->budget--) { s->failed_pc=0x0c075964u; return 0; }
r[3]+=0x0000006cu;
goto P_0c075966;
P_0c075966: /* original 6032, guest PC 0x0c075966 */
if(!s->budget--) { s->failed_pc=0x0c075966u; return 0; }
tmp=read(ram,r[3],4);
r[0]=tmp;
goto P_0c075968;
P_0c075968: /* original c804, guest PC 0x0c075968 */
if(!s->budget--) { s->failed_pc=0x0c075968u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&4u)==0)!=0);
goto P_0c07596a;
P_0c07596a: /* original 8b29, guest PC 0x0c07596a */
if(!s->budget--) { s->failed_pc=0x0c07596au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0759c0; }
goto P_0c07596c;
P_0c07596c: /* original e06c, guest PC 0x0c07596c */
if(!s->budget--) { s->failed_pc=0x0c07596cu; return 0; }
r[0]=0x0000006cu;
goto P_0c07596e;
P_0c07596e: /* original 934b, guest PC 0x0c07596e */
if(!s->budget--) { s->failed_pc=0x0c07596eu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c075a08u,2);
goto P_0c075970;
P_0c075970: /* original 02fe, guest PC 0x0c075970 */
if(!s->budget--) { s->failed_pc=0x0c075970u; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c075972;
P_0c075972: /* original 2238, guest PC 0x0c075972 */
if(!s->budget--) { s->failed_pc=0x0c075972u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c075974;
P_0c075974: /* original 8b6d, guest PC 0x0c075974 */
if(!s->budget--) { s->failed_pc=0x0c075974u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c075a52; }
goto P_0c075976;
P_0c075976: /* original 903d, guest PC 0x0c075976 */
if(!s->budget--) { s->failed_pc=0x0c075976u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0759f4u,2);
goto P_0c075978;
P_0c075978: /* original d326, guest PC 0x0c075978 */
if(!s->budget--) { s->failed_pc=0x0c075978u; return 0; }
r[3]=read(ram,0x0c075a14u,4);
goto P_0c07597a;
P_0c07597a: /* original 01fe, guest PC 0x0c07597a */
if(!s->budget--) { s->failed_pc=0x0c07597au; return 0; }
r[1]=read(ram,r[15]+r[0],4);
goto P_0c07597c;
P_0c07597c: /* original 9045, guest PC 0x0c07597c */
if(!s->budget--) { s->failed_pc=0x0c07597cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c075a0au,2);
goto P_0c07597e;
P_0c07597e: /* original 021e, guest PC 0x0c07597e */
if(!s->budget--) { s->failed_pc=0x0c07597eu; return 0; }
r[2]=read(ram,r[1]+r[0],4);
goto P_0c075980;
P_0c075980: /* original 2238, guest PC 0x0c075980 */
if(!s->budget--) { s->failed_pc=0x0c075980u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c075982;
P_0c075982: /* original 8966, guest PC 0x0c075982 */
if(!s->budget--) { s->failed_pc=0x0c075982u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c075a52; }
goto P_0c075984;
P_0c075984: /* original e05c, guest PC 0x0c075984 */
if(!s->budget--) { s->failed_pc=0x0c075984u; return 0; }
r[0]=0x0000005cu;
goto P_0c075986;
P_0c075986: /* original d324, guest PC 0x0c075986 */
if(!s->budget--) { s->failed_pc=0x0c075986u; return 0; }
r[3]=read(ram,0x0c075a18u,4);
goto P_0c075988;
P_0c075988: /* original 01fe, guest PC 0x0c075988 */
if(!s->budget--) { s->failed_pc=0x0c075988u; return 0; }
r[1]=read(ram,r[15]+r[0],4);
goto P_0c07598a;
P_0c07598a: /* original 2138, guest PC 0x0c07598a */
if(!s->budget--) { s->failed_pc=0x0c07598au; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[3])==0)!=0);
goto P_0c07598c;
P_0c07598c: /* original 8913, guest PC 0x0c07598c */
if(!s->budget--) { s->failed_pc=0x0c07598cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0759b6; }
goto P_0c07598e;
P_0c07598e: /* original e050, guest PC 0x0c07598e */
if(!s->budget--) { s->failed_pc=0x0c07598eu; return 0; }
r[0]=0x00000050u;
goto P_0c075990;
P_0c075990: /* original 61f3, guest PC 0x0c075990 */
if(!s->budget--) { s->failed_pc=0x0c075990u; return 0; }
r[1]=r[15];
goto P_0c075992;
P_0c075992: /* original e203, guest PC 0x0c075992 */
if(!s->budget--) { s->failed_pc=0x0c075992u; return 0; }
r[2]=0x00000003u;
goto P_0c075994;
P_0c075994: /* original 0f26, guest PC 0x0c075994 */
if(!s->budget--) { s->failed_pc=0x0c075994u; return 0; }
write(ram,r[15]+r[0],r[2],4);
goto P_0c075996;
P_0c075996: /* original e04c, guest PC 0x0c075996 */
if(!s->budget--) { s->failed_pc=0x0c075996u; return 0; }
r[0]=0x0000004cu;
goto P_0c075998;
P_0c075998: /* original 00fe, guest PC 0x0c075998 */
if(!s->budget--) { s->failed_pc=0x0c075998u; return 0; }
r[0]=read(ram,r[15]+r[0],4);
goto P_0c07599a;
P_0c07599a: /* original 714c, guest PC 0x0c07599a */
if(!s->budget--) { s->failed_pc=0x0c07599au; return 0; }
r[1]+=0x0000004cu;
goto P_0c07599c;
P_0c07599c: /* original cb04, guest PC 0x0c07599c */
if(!s->budget--) { s->failed_pc=0x0c07599cu; return 0; }
r[0]|=4u;
goto P_0c07599e;
P_0c07599e: /* original 2102, guest PC 0x0c07599e */
if(!s->budget--) { s->failed_pc=0x0c07599eu; return 0; }
write(ram,r[1],r[0],4);
goto P_0c0759a0;
P_0c0759a0: /* original e068, guest PC 0x0c0759a0 */
if(!s->budget--) { s->failed_pc=0x0c0759a0u; return 0; }
r[0]=0x00000068u;
goto P_0c0759a2;
P_0c0759a2: /* original 02fe, guest PC 0x0c0759a2 */
if(!s->budget--) { s->failed_pc=0x0c0759a2u; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c0759a4;
P_0c0759a4: /* original 902f, guest PC 0x0c0759a4 */
if(!s->budget--) { s->failed_pc=0x0c0759a4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c075a06u,2);
goto P_0c0759a6;
P_0c0759a6: /* original 4201, guest PC 0x0c0759a6 */
if(!s->budget--) { s->failed_pc=0x0c0759a6u; return 0; }
r[17]=(r[17]&~1u)|((r[2]&1)!=0);
r[2]>>=1;
goto P_0c0759a8;
P_0c0759a8: /* original 0f26, guest PC 0x0c0759a8 */
if(!s->budget--) { s->failed_pc=0x0c0759a8u; return 0; }
write(ram,r[15]+r[0],r[2],4);
goto P_0c0759aa;
P_0c0759aa: /* original 9021, guest PC 0x0c0759aa */
if(!s->budget--) { s->failed_pc=0x0c0759aau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0759f0u,2);
goto P_0c0759ac;
P_0c0759ac: /* original d21b, guest PC 0x0c0759ac */
if(!s->budget--) { s->failed_pc=0x0c0759acu; return 0; }
r[2]=read(ram,0x0c075a1cu,4);
goto P_0c0759ae;
P_0c0759ae: /* original 01fe, guest PC 0x0c0759ae */
if(!s->budget--) { s->failed_pc=0x0c0759aeu; return 0; }
r[1]=read(ram,r[15]+r[0],4);
goto P_0c0759b0;
P_0c0759b0: /* original 112c, guest PC 0x0c0759b0 */
if(!s->budget--) { s->failed_pc=0x0c0759b0u; return 0; }
write(ram,r[1]+48,r[2],4);
goto P_0c0759b2;
P_0c0759b2: /* original a04e, guest PC 0x0c0759b2 */
if(!s->budget--) { s->failed_pc=0x0c0759b2u; return 0; }
goto P_0c075a52;
P_0c0759b4: /* original 0009, guest PC 0x0c0759b4 */
if(!s->budget--) { s->failed_pc=0x0c0759b4u; return 0; }
goto P_0c0759b6;
P_0c0759b6: /* original e05c, guest PC 0x0c0759b6 */
if(!s->budget--) { s->failed_pc=0x0c0759b6u; return 0; }
r[0]=0x0000005cu;
goto P_0c0759b8;
P_0c0759b8: /* original d319, guest PC 0x0c0759b8 */
if(!s->budget--) { s->failed_pc=0x0c0759b8u; return 0; }
r[3]=read(ram,0x0c075a20u,4);
goto P_0c0759ba;
P_0c0759ba: /* original 01fe, guest PC 0x0c0759ba */
if(!s->budget--) { s->failed_pc=0x0c0759bau; return 0; }
r[1]=read(ram,r[15]+r[0],4);
goto P_0c0759bc;
P_0c0759bc: /* original 2138, guest PC 0x0c0759bc */
if(!s->budget--) { s->failed_pc=0x0c0759bcu; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[3])==0)!=0);
goto P_0c0759be;
P_0c0759be: /* original 8931, guest PC 0x0c0759be */
if(!s->budget--) { s->failed_pc=0x0c0759beu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c075a24; }
goto P_0c0759c0;
P_0c0759c0: /* original 9018, guest PC 0x0c0759c0 */
if(!s->budget--) { s->failed_pc=0x0c0759c0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0759f4u,2);
goto P_0c0759c2;
P_0c0759c2: /* original 03fe, guest PC 0x0c0759c2 */
if(!s->budget--) { s->failed_pc=0x0c0759c2u; return 0; }
r[3]=read(ram,r[15]+r[0],4);
goto P_0c0759c4;
P_0c0759c4: /* original e03e, guest PC 0x0c0759c4 */
if(!s->budget--) { s->failed_pc=0x0c0759c4u; return 0; }
r[0]=0x0000003eu;
goto P_0c0759c6;
P_0c0759c6: /* original 023d, guest PC 0x0c0759c6 */
if(!s->budget--) { s->failed_pc=0x0c0759c6u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[3]+r[0],2);
goto P_0c0759c8;
P_0c0759c8: /* original 9020, guest PC 0x0c0759c8 */
if(!s->budget--) { s->failed_pc=0x0c0759c8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c075a0cu,2);
goto P_0c0759ca;
P_0c0759ca: /* original 013d, guest PC 0x0c0759ca */
if(!s->budget--) { s->failed_pc=0x0c0759cau; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,r[3]+r[0],2);
goto P_0c0759cc;
P_0c0759cc: /* original 3216, guest PC 0x0c0759cc */
if(!s->budget--) { s->failed_pc=0x0c0759ccu; return 0; }
r[17]=(r[17]&~1u)|((r[2]>r[1])!=0);
goto P_0c0759ce;
P_0c0759ce: /* original 8929, guest PC 0x0c0759ce */
if(!s->budget--) { s->failed_pc=0x0c0759ceu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c075a24; }
goto P_0c0759d0;
P_0c0759d0: /* original e050, guest PC 0x0c0759d0 */
if(!s->budget--) { s->failed_pc=0x0c0759d0u; return 0; }
r[0]=0x00000050u;
goto P_0c0759d2;
P_0c0759d2: /* original e222, guest PC 0x0c0759d2 */
if(!s->budget--) { s->failed_pc=0x0c0759d2u; return 0; }
r[2]=0x00000022u;
goto P_0c0759d4;
P_0c0759d4: /* original 0f26, guest PC 0x0c0759d4 */
if(!s->budget--) { s->failed_pc=0x0c0759d4u; return 0; }
write(ram,r[15]+r[0],r[2],4);
goto P_0c0759d6;
P_0c0759d6: /* original e04c, guest PC 0x0c0759d6 */
if(!s->budget--) { s->failed_pc=0x0c0759d6u; return 0; }
r[0]=0x0000004cu;
goto P_0c0759d8;
P_0c0759d8: /* original 01fe, guest PC 0x0c0759d8 */
if(!s->budget--) { s->failed_pc=0x0c0759d8u; return 0; }
r[1]=read(ram,r[15]+r[0],4);
goto P_0c0759da;
P_0c0759da: /* original e04c, guest PC 0x0c0759da */
if(!s->budget--) { s->failed_pc=0x0c0759dau; return 0; }
r[0]=0x0000004cu;
goto P_0c0759dc;
P_0c0759dc: /* original 9317, guest PC 0x0c0759dc */
if(!s->budget--) { s->failed_pc=0x0c0759dcu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c075a0eu,2);
goto P_0c0759de;
P_0c0759de: /* original 213b, guest PC 0x0c0759de */
if(!s->budget--) { s->failed_pc=0x0c0759deu; return 0; }
r[1]|=r[3];
goto P_0c0759e0;
P_0c0759e0: /* original 0f16, guest PC 0x0c0759e0 */
if(!s->budget--) { s->failed_pc=0x0c0759e0u; return 0; }
write(ram,r[15]+r[0],r[1],4);
goto P_0c0759e2;
P_0c0759e2: /* original e068, guest PC 0x0c0759e2 */
if(!s->budget--) { s->failed_pc=0x0c0759e2u; return 0; }
r[0]=0x00000068u;
goto P_0c0759e4;
P_0c0759e4: /* original 02fe, guest PC 0x0c0759e4 */
if(!s->budget--) { s->failed_pc=0x0c0759e4u; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c0759e6;
P_0c0759e6: /* original 900e, guest PC 0x0c0759e6 */
if(!s->budget--) { s->failed_pc=0x0c0759e6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c075a06u,2);
goto P_0c0759e8;
P_0c0759e8: /* original 4209, guest PC 0x0c0759e8 */
if(!s->budget--) { s->failed_pc=0x0c0759e8u; return 0; }
r[2]>>=2;
goto P_0c0759ea;
P_0c0759ea: /* original 4201, guest PC 0x0c0759ea */
if(!s->budget--) { s->failed_pc=0x0c0759eau; return 0; }
r[17]=(r[17]&~1u)|((r[2]&1)!=0);
r[2]>>=1;
goto P_0c0759ec;
P_0c0759ec: /* original a031, guest PC 0x0c0759ec */
if(!s->budget--) { s->failed_pc=0x0c0759ecu; return 0; }
write(ram,r[15]+r[0],r[2],4);
goto P_0c075a52;
P_0c0759ee: /* original 0f26, guest PC 0x0c0759ee */
if(!s->budget--) { s->failed_pc=0x0c0759eeu; return 0; }
write(ram,r[15]+r[0],r[2],4);
return vf3_matrix_family(0x0c0759f0u,s,ram);
P_0c075a24: /* original e05c, guest PC 0x0c075a24 */
if(!s->budget--) { s->failed_pc=0x0c075a24u; return 0; }
r[0]=0x0000005cu;
goto P_0c075a26;
P_0c075a26: /* original d332, guest PC 0x0c075a26 */
if(!s->budget--) { s->failed_pc=0x0c075a26u; return 0; }
r[3]=read(ram,0x0c075af0u,4);
goto P_0c075a28;
P_0c075a28: /* original 01fe, guest PC 0x0c075a28 */
if(!s->budget--) { s->failed_pc=0x0c075a28u; return 0; }
r[1]=read(ram,r[15]+r[0],4);
goto P_0c075a2a;
P_0c075a2a: /* original 2138, guest PC 0x0c075a2a */
if(!s->budget--) { s->failed_pc=0x0c075a2au; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[3])==0)!=0);
goto P_0c075a2c;
P_0c075a2c: /* original 8911, guest PC 0x0c075a2c */
if(!s->budget--) { s->failed_pc=0x0c075a2cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c075a52; }
goto P_0c075a2e;
P_0c075a2e: /* original e050, guest PC 0x0c075a2e */
if(!s->budget--) { s->failed_pc=0x0c075a2eu; return 0; }
r[0]=0x00000050u;
goto P_0c075a30;
P_0c075a30: /* original 61f3, guest PC 0x0c075a30 */
if(!s->budget--) { s->failed_pc=0x0c075a30u; return 0; }
r[1]=r[15];
goto P_0c075a32;
P_0c075a32: /* original e203, guest PC 0x0c075a32 */
if(!s->budget--) { s->failed_pc=0x0c075a32u; return 0; }
r[2]=0x00000003u;
goto P_0c075a34;
P_0c075a34: /* original 0f26, guest PC 0x0c075a34 */
if(!s->budget--) { s->failed_pc=0x0c075a34u; return 0; }
write(ram,r[15]+r[0],r[2],4);
goto P_0c075a36;
P_0c075a36: /* original e04c, guest PC 0x0c075a36 */
if(!s->budget--) { s->failed_pc=0x0c075a36u; return 0; }
r[0]=0x0000004cu;
goto P_0c075a38;
P_0c075a38: /* original 00fe, guest PC 0x0c075a38 */
if(!s->budget--) { s->failed_pc=0x0c075a38u; return 0; }
r[0]=read(ram,r[15]+r[0],4);
goto P_0c075a3a;
P_0c075a3a: /* original 714c, guest PC 0x0c075a3a */
if(!s->budget--) { s->failed_pc=0x0c075a3au; return 0; }
r[1]+=0x0000004cu;
goto P_0c075a3c;
P_0c075a3c: /* original cb04, guest PC 0x0c075a3c */
if(!s->budget--) { s->failed_pc=0x0c075a3cu; return 0; }
r[0]|=4u;
goto P_0c075a3e;
P_0c075a3e: /* original 2102, guest PC 0x0c075a3e */
if(!s->budget--) { s->failed_pc=0x0c075a3eu; return 0; }
write(ram,r[1],r[0],4);
goto P_0c075a40;
P_0c075a40: /* original e068, guest PC 0x0c075a40 */
if(!s->budget--) { s->failed_pc=0x0c075a40u; return 0; }
r[0]=0x00000068u;
goto P_0c075a42;
P_0c075a42: /* original 02fe, guest PC 0x0c075a42 */
if(!s->budget--) { s->failed_pc=0x0c075a42u; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c075a44;
P_0c075a44: /* original 904d, guest PC 0x0c075a44 */
if(!s->budget--) { s->failed_pc=0x0c075a44u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c075ae2u,2);
goto P_0c075a46;
P_0c075a46: /* original 4201, guest PC 0x0c075a46 */
if(!s->budget--) { s->failed_pc=0x0c075a46u; return 0; }
r[17]=(r[17]&~1u)|((r[2]&1)!=0);
r[2]>>=1;
goto P_0c075a48;
P_0c075a48: /* original 0f26, guest PC 0x0c075a48 */
if(!s->budget--) { s->failed_pc=0x0c075a48u; return 0; }
write(ram,r[15]+r[0],r[2],4);
goto P_0c075a4a;
P_0c075a4a: /* original 904b, guest PC 0x0c075a4a */
if(!s->budget--) { s->failed_pc=0x0c075a4au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c075ae4u,2);
goto P_0c075a4c;
P_0c075a4c: /* original d229, guest PC 0x0c075a4c */
if(!s->budget--) { s->failed_pc=0x0c075a4cu; return 0; }
r[2]=read(ram,0x0c075af4u,4);
goto P_0c075a4e;
P_0c075a4e: /* original 01fe, guest PC 0x0c075a4e */
if(!s->budget--) { s->failed_pc=0x0c075a4eu; return 0; }
r[1]=read(ram,r[15]+r[0],4);
goto P_0c075a50;
P_0c075a50: /* original 112c, guest PC 0x0c075a50 */
if(!s->budget--) { s->failed_pc=0x0c075a50u; return 0; }
write(ram,r[1]+48,r[2],4);
goto P_0c075a52;
P_0c075a52: /* original e05c, guest PC 0x0c075a52 */
if(!s->budget--) { s->failed_pc=0x0c075a52u; return 0; }
r[0]=0x0000005cu;
goto P_0c075a54;
P_0c075a54: /* original d328, guest PC 0x0c075a54 */
if(!s->budget--) { s->failed_pc=0x0c075a54u; return 0; }
r[3]=read(ram,0x0c075af8u,4);
goto P_0c075a56;
P_0c075a56: /* original 01fe, guest PC 0x0c075a56 */
if(!s->budget--) { s->failed_pc=0x0c075a56u; return 0; }
r[1]=read(ram,r[15]+r[0],4);
goto P_0c075a58;
P_0c075a58: /* original 2138, guest PC 0x0c075a58 */
if(!s->budget--) { s->failed_pc=0x0c075a58u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[3])==0)!=0);
goto P_0c075a5a;
P_0c075a5a: /* original 8917, guest PC 0x0c075a5a */
if(!s->budget--) { s->failed_pc=0x0c075a5au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c075a8c; }
goto P_0c075a5c;
P_0c075a5c: /* original 9043, guest PC 0x0c075a5c */
if(!s->budget--) { s->failed_pc=0x0c075a5cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c075ae6u,2);
goto P_0c075a5e;
P_0c075a5e: /* original 02fe, guest PC 0x0c075a5e */
if(!s->budget--) { s->failed_pc=0x0c075a5eu; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c075a60;
P_0c075a60: /* original 9042, guest PC 0x0c075a60 */
if(!s->budget--) { s->failed_pc=0x0c075a60u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c075ae8u,2);
goto P_0c075a62;
P_0c075a62: /* original 012c, guest PC 0x0c075a62 */
if(!s->budget--) { s->failed_pc=0x0c075a62u; return 0; }
r[1]=(uint32_t)(int32_t)(int8_t)read(ram,r[2]+r[0],1);
goto P_0c075a64;
P_0c075a64: /* original e201, guest PC 0x0c075a64 */
if(!s->budget--) { s->failed_pc=0x0c075a64u; return 0; }
r[2]=0x00000001u;
goto P_0c075a66;
P_0c075a66: /* original 611c, guest PC 0x0c075a66 */
if(!s->budget--) { s->failed_pc=0x0c075a66u; return 0; }
r[1]=r[1]&255u;
goto P_0c075a68;
P_0c075a68: /* original 3127, guest PC 0x0c075a68 */
if(!s->budget--) { s->failed_pc=0x0c075a68u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[1]>(int32_t)r[2])!=0);
goto P_0c075a6a;
P_0c075a6a: /* original 8b0f, guest PC 0x0c075a6a */
if(!s->budget--) { s->failed_pc=0x0c075a6au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c075a8c; }
goto P_0c075a6c;
P_0c075a6c: /* original e04c, guest PC 0x0c075a6c */
if(!s->budget--) { s->failed_pc=0x0c075a6cu; return 0; }
r[0]=0x0000004cu;
goto P_0c075a6e;
P_0c075a6e: /* original d323, guest PC 0x0c075a6e */
if(!s->budget--) { s->failed_pc=0x0c075a6eu; return 0; }
r[3]=read(ram,0x0c075afcu,4);
goto P_0c075a70;
P_0c075a70: /* original 01fe, guest PC 0x0c075a70 */
if(!s->budget--) { s->failed_pc=0x0c075a70u; return 0; }
r[1]=read(ram,r[15]+r[0],4);
goto P_0c075a72;
P_0c075a72: /* original e04c, guest PC 0x0c075a72 */
if(!s->budget--) { s->failed_pc=0x0c075a72u; return 0; }
r[0]=0x0000004cu;
goto P_0c075a74;
P_0c075a74: /* original 213b, guest PC 0x0c075a74 */
if(!s->budget--) { s->failed_pc=0x0c075a74u; return 0; }
r[1]|=r[3];
goto P_0c075a76;
P_0c075a76: /* original 0f16, guest PC 0x0c075a76 */
if(!s->budget--) { s->failed_pc=0x0c075a76u; return 0; }
write(ram,r[15]+r[0],r[1],4);
goto P_0c075a78;
P_0c075a78: /* original e054, guest PC 0x0c075a78 */
if(!s->budget--) { s->failed_pc=0x0c075a78u; return 0; }
r[0]=0x00000054u;
goto P_0c075a7a;
P_0c075a7a: /* original 02fe, guest PC 0x0c075a7a */
if(!s->budget--) { s->failed_pc=0x0c075a7au; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c075a7c;
P_0c075a7c: /* original 9035, guest PC 0x0c075a7c */
if(!s->budget--) { s->failed_pc=0x0c075a7cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c075aeau,2);
goto P_0c075a7e;
P_0c075a7e: /* original 4209, guest PC 0x0c075a7e */
if(!s->budget--) { s->failed_pc=0x0c075a7eu; return 0; }
r[2]>>=2;
goto P_0c075a80;
P_0c075a80: /* original 0f26, guest PC 0x0c075a80 */
if(!s->budget--) { s->failed_pc=0x0c075a80u; return 0; }
write(ram,r[15]+r[0],r[2],4);
goto P_0c075a82;
P_0c075a82: /* original e054, guest PC 0x0c075a82 */
if(!s->budget--) { s->failed_pc=0x0c075a82u; return 0; }
r[0]=0x00000054u;
goto P_0c075a84;
P_0c075a84: /* original 03fe, guest PC 0x0c075a84 */
if(!s->budget--) { s->failed_pc=0x0c075a84u; return 0; }
r[3]=read(ram,r[15]+r[0],4);
goto P_0c075a86;
P_0c075a86: /* original 3328, guest PC 0x0c075a86 */
if(!s->budget--) { s->failed_pc=0x0c075a86u; return 0; }
r[3]-=r[2];
goto P_0c075a88;
P_0c075a88: /* original a09e, guest PC 0x0c075a88 */
if(!s->budget--) { s->failed_pc=0x0c075a88u; return 0; }
goto P_0c075bc8;
P_0c075a8a: /* original 0009, guest PC 0x0c075a8a */
if(!s->budget--) { s->failed_pc=0x0c075a8au; return 0; }
goto P_0c075a8c;
P_0c075a8c: /* original e05c, guest PC 0x0c075a8c */
if(!s->budget--) { s->failed_pc=0x0c075a8cu; return 0; }
r[0]=0x0000005cu;
goto P_0c075a8e;
P_0c075a8e: /* original d31c, guest PC 0x0c075a8e */
if(!s->budget--) { s->failed_pc=0x0c075a8eu; return 0; }
r[3]=read(ram,0x0c075b00u,4);
goto P_0c075a90;
P_0c075a90: /* original 02fe, guest PC 0x0c075a90 */
if(!s->budget--) { s->failed_pc=0x0c075a90u; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c075a92;
P_0c075a92: /* original 2238, guest PC 0x0c075a92 */
if(!s->budget--) { s->failed_pc=0x0c075a92u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c075a94;
P_0c075a94: /* original 893a, guest PC 0x0c075a94 */
if(!s->budget--) { s->failed_pc=0x0c075a94u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c075b0c; }
goto P_0c075a96;
P_0c075a96: /* original e05c, guest PC 0x0c075a96 */
if(!s->budget--) { s->failed_pc=0x0c075a96u; return 0; }
r[0]=0x0000005cu;
goto P_0c075a98;
P_0c075a98: /* original d21a, guest PC 0x0c075a98 */
if(!s->budget--) { s->failed_pc=0x0c075a98u; return 0; }
r[2]=read(ram,0x0c075b04u,4);
goto P_0c075a9a;
P_0c075a9a: /* original 01fe, guest PC 0x0c075a9a */
if(!s->budget--) { s->failed_pc=0x0c075a9au; return 0; }
r[1]=read(ram,r[15]+r[0],4);
goto P_0c075a9c;
P_0c075a9c: /* original 2128, guest PC 0x0c075a9c */
if(!s->budget--) { s->failed_pc=0x0c075a9cu; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[2])==0)!=0);
goto P_0c075a9e;
P_0c075a9e: /* original 8b35, guest PC 0x0c075a9e */
if(!s->budget--) { s->failed_pc=0x0c075a9eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c075b0c; }
goto P_0c075aa0;
P_0c075aa0: /* original 9021, guest PC 0x0c075aa0 */
if(!s->budget--) { s->failed_pc=0x0c075aa0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c075ae6u,2);
goto P_0c075aa2;
P_0c075aa2: /* original 01fe, guest PC 0x0c075aa2 */
if(!s->budget--) { s->failed_pc=0x0c075aa2u; return 0; }
r[1]=read(ram,r[15]+r[0],4);
goto P_0c075aa4;
P_0c075aa4: /* original 9022, guest PC 0x0c075aa4 */
if(!s->budget--) { s->failed_pc=0x0c075aa4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c075aecu,2);
goto P_0c075aa6;
P_0c075aa6: /* original 011e, guest PC 0x0c075aa6 */
if(!s->budget--) { s->failed_pc=0x0c075aa6u; return 0; }
r[1]=read(ram,r[1]+r[0],4);
goto P_0c075aa8;
P_0c075aa8: /* original 2118, guest PC 0x0c075aa8 */
if(!s->budget--) { s->failed_pc=0x0c075aa8u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[1])==0)!=0);
goto P_0c075aaa;
P_0c075aaa: /* original 892f, guest PC 0x0c075aaa */
if(!s->budget--) { s->failed_pc=0x0c075aaau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c075b0c; }
goto P_0c075aac;
P_0c075aac: /* original e060, guest PC 0x0c075aac */
if(!s->budget--) { s->failed_pc=0x0c075aacu; return 0; }
r[0]=0x00000060u;
goto P_0c075aae;
P_0c075aae: /* original 00fe, guest PC 0x0c075aae */
if(!s->budget--) { s->failed_pc=0x0c075aaeu; return 0; }
r[0]=read(ram,r[15]+r[0],4);
goto P_0c075ab0;
P_0c075ab0: /* original 8804, guest PC 0x0c075ab0 */
if(!s->budget--) { s->failed_pc=0x0c075ab0u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000004u)!=0);
goto P_0c075ab2;
P_0c075ab2: /* original 8b06, guest PC 0x0c075ab2 */
if(!s->budget--) { s->failed_pc=0x0c075ab2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c075ac2; }
goto P_0c075ab4;
P_0c075ab4: /* original 9016, guest PC 0x0c075ab4 */
if(!s->budget--) { s->failed_pc=0x0c075ab4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c075ae4u,2);
goto P_0c075ab6;
P_0c075ab6: /* original d311, guest PC 0x0c075ab6 */
if(!s->budget--) { s->failed_pc=0x0c075ab6u; return 0; }
r[3]=read(ram,0x0c075afcu,4);
goto P_0c075ab8;
P_0c075ab8: /* original 02fe, guest PC 0x0c075ab8 */
if(!s->budget--) { s->failed_pc=0x0c075ab8u; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c075aba;
P_0c075aba: /* original 9018, guest PC 0x0c075aba */
if(!s->budget--) { s->failed_pc=0x0c075abau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c075aeeu,2);
goto P_0c075abc;
P_0c075abc: /* original 012e, guest PC 0x0c075abc */
if(!s->budget--) { s->failed_pc=0x0c075abcu; return 0; }
r[1]=read(ram,r[2]+r[0],4);
goto P_0c075abe;
P_0c075abe: /* original 2138, guest PC 0x0c075abe */
if(!s->budget--) { s->failed_pc=0x0c075abeu; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[3])==0)!=0);
goto P_0c075ac0;
P_0c075ac0: /* original 8924, guest PC 0x0c075ac0 */
if(!s->budget--) { s->failed_pc=0x0c075ac0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c075b0c; }
goto P_0c075ac2;
P_0c075ac2: /* original e04c, guest PC 0x0c075ac2 */
if(!s->budget--) { s->failed_pc=0x0c075ac2u; return 0; }
r[0]=0x0000004cu;
goto P_0c075ac4;
P_0c075ac4: /* original d310, guest PC 0x0c075ac4 */
if(!s->budget--) { s->failed_pc=0x0c075ac4u; return 0; }
r[3]=read(ram,0x0c075b08u,4);
goto P_0c075ac6;
P_0c075ac6: /* original 02fe, guest PC 0x0c075ac6 */
if(!s->budget--) { s->failed_pc=0x0c075ac6u; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c075ac8;
P_0c075ac8: /* original e04c, guest PC 0x0c075ac8 */
if(!s->budget--) { s->failed_pc=0x0c075ac8u; return 0; }
r[0]=0x0000004cu;
goto P_0c075aca;
P_0c075aca: /* original 223b, guest PC 0x0c075aca */
if(!s->budget--) { s->failed_pc=0x0c075acau; return 0; }
r[2]|=r[3];
goto P_0c075acc;
P_0c075acc: /* original 0f26, guest PC 0x0c075acc */
if(!s->budget--) { s->failed_pc=0x0c075accu; return 0; }
write(ram,r[15]+r[0],r[2],4);
goto P_0c075ace;
P_0c075ace: /* original e054, guest PC 0x0c075ace */
if(!s->budget--) { s->failed_pc=0x0c075aceu; return 0; }
r[0]=0x00000054u;
goto P_0c075ad0;
P_0c075ad0: /* original 01fe, guest PC 0x0c075ad0 */
if(!s->budget--) { s->failed_pc=0x0c075ad0u; return 0; }
r[1]=read(ram,r[15]+r[0],4);
goto P_0c075ad2;
P_0c075ad2: /* original 900a, guest PC 0x0c075ad2 */
if(!s->budget--) { s->failed_pc=0x0c075ad2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c075aeau,2);
goto P_0c075ad4;
P_0c075ad4: /* original 4109, guest PC 0x0c075ad4 */
if(!s->budget--) { s->failed_pc=0x0c075ad4u; return 0; }
r[1]>>=2;
goto P_0c075ad6;
P_0c075ad6: /* original 0f16, guest PC 0x0c075ad6 */
if(!s->budget--) { s->failed_pc=0x0c075ad6u; return 0; }
write(ram,r[15]+r[0],r[1],4);
goto P_0c075ad8;
P_0c075ad8: /* original e054, guest PC 0x0c075ad8 */
if(!s->budget--) { s->failed_pc=0x0c075ad8u; return 0; }
r[0]=0x00000054u;
goto P_0c075ada;
P_0c075ada: /* original 03fe, guest PC 0x0c075ada */
if(!s->budget--) { s->failed_pc=0x0c075adau; return 0; }
r[3]=read(ram,r[15]+r[0],4);
goto P_0c075adc;
P_0c075adc: /* original 3318, guest PC 0x0c075adc */
if(!s->budget--) { s->failed_pc=0x0c075adcu; return 0; }
r[3]-=r[1];
goto P_0c075ade;
P_0c075ade: /* original a073, guest PC 0x0c075ade */
if(!s->budget--) { s->failed_pc=0x0c075adeu; return 0; }
goto P_0c075bc8;
P_0c075ae0: /* original 0009, guest PC 0x0c075ae0 */
if(!s->budget--) { s->failed_pc=0x0c075ae0u; return 0; }
return vf3_matrix_family(0x0c075ae2u,s,ram);
P_0c075b0c: /* original 9080, guest PC 0x0c075b0c */
if(!s->budget--) { s->failed_pc=0x0c075b0cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c075c10u,2);
goto P_0c075b0e;
P_0c075b0e: /* original 9380, guest PC 0x0c075b0e */
if(!s->budget--) { s->failed_pc=0x0c075b0eu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c075c12u,2);
goto P_0c075b10;
P_0c075b10: /* original 02fe, guest PC 0x0c075b10 */
if(!s->budget--) { s->failed_pc=0x0c075b10u; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c075b12;
P_0c075b12: /* original e04c, guest PC 0x0c075b12 */
if(!s->budget--) { s->failed_pc=0x0c075b12u; return 0; }
r[0]=0x0000004cu;
goto P_0c075b14;
P_0c075b14: /* original 012e, guest PC 0x0c075b14 */
if(!s->budget--) { s->failed_pc=0x0c075b14u; return 0; }
r[1]=read(ram,r[2]+r[0],4);
goto P_0c075b16;
P_0c075b16: /* original 2138, guest PC 0x0c075b16 */
if(!s->budget--) { s->failed_pc=0x0c075b16u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[3])==0)!=0);
goto P_0c075b18;
P_0c075b18: /* original 8901, guest PC 0x0c075b18 */
if(!s->budget--) { s->failed_pc=0x0c075b18u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c075b1e; }
goto P_0c075b1a;
P_0c075b1a: /* original a0bb, guest PC 0x0c075b1a */
if(!s->budget--) { s->failed_pc=0x0c075b1au; return 0; }
goto P_0c075c94;
P_0c075b1c: /* original 0009, guest PC 0x0c075b1c */
if(!s->budget--) { s->failed_pc=0x0c075b1cu; return 0; }
goto P_0c075b1e;
P_0c075b1e: /* original e060, guest PC 0x0c075b1e */
if(!s->budget--) { s->failed_pc=0x0c075b1eu; return 0; }
r[0]=0x00000060u;
goto P_0c075b20;
P_0c075b20: /* original 00fe, guest PC 0x0c075b20 */
if(!s->budget--) { s->failed_pc=0x0c075b20u; return 0; }
r[0]=read(ram,r[15]+r[0],4);
goto P_0c075b22;
P_0c075b22: /* original 8804, guest PC 0x0c075b22 */
if(!s->budget--) { s->failed_pc=0x0c075b22u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000004u)!=0);
goto P_0c075b24;
P_0c075b24: /* original 8b27, guest PC 0x0c075b24 */
if(!s->budget--) { s->failed_pc=0x0c075b24u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c075b76; }
goto P_0c075b26;
P_0c075b26: /* original 9073, guest PC 0x0c075b26 */
if(!s->budget--) { s->failed_pc=0x0c075b26u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c075c10u,2);
goto P_0c075b28;
P_0c075b28: /* original d33e, guest PC 0x0c075b28 */
if(!s->budget--) { s->failed_pc=0x0c075b28u; return 0; }
r[3]=read(ram,0x0c075c24u,4);
goto P_0c075b2a;
P_0c075b2a: /* original 02fe, guest PC 0x0c075b2a */
if(!s->budget--) { s->failed_pc=0x0c075b2au; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c075b2c;
P_0c075b2c: /* original 9072, guest PC 0x0c075b2c */
if(!s->budget--) { s->failed_pc=0x0c075b2cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c075c14u,2);
goto P_0c075b2e;
P_0c075b2e: /* original 012e, guest PC 0x0c075b2e */
if(!s->budget--) { s->failed_pc=0x0c075b2eu; return 0; }
r[1]=read(ram,r[2]+r[0],4);
goto P_0c075b30;
P_0c075b30: /* original 2138, guest PC 0x0c075b30 */
if(!s->budget--) { s->failed_pc=0x0c075b30u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[3])==0)!=0);
goto P_0c075b32;
P_0c075b32: /* original 8b01, guest PC 0x0c075b32 */
if(!s->budget--) { s->failed_pc=0x0c075b32u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c075b38; }
goto P_0c075b34;
P_0c075b34: /* original a0ae, guest PC 0x0c075b34 */
if(!s->budget--) { s->failed_pc=0x0c075b34u; return 0; }
goto P_0c075c94;
P_0c075b36: /* original 0009, guest PC 0x0c075b36 */
if(!s->budget--) { s->failed_pc=0x0c075b36u; return 0; }
goto P_0c075b38;
P_0c075b38: /* original e05c, guest PC 0x0c075b38 */
if(!s->budget--) { s->failed_pc=0x0c075b38u; return 0; }
r[0]=0x0000005cu;
goto P_0c075b3a;
P_0c075b3a: /* original d33b, guest PC 0x0c075b3a */
if(!s->budget--) { s->failed_pc=0x0c075b3au; return 0; }
r[3]=read(ram,0x0c075c28u,4);
goto P_0c075b3c;
P_0c075b3c: /* original 02fe, guest PC 0x0c075b3c */
if(!s->budget--) { s->failed_pc=0x0c075b3cu; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c075b3e;
P_0c075b3e: /* original 2238, guest PC 0x0c075b3e */
if(!s->budget--) { s->failed_pc=0x0c075b3eu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c075b40;
P_0c075b40: /* original 8919, guest PC 0x0c075b40 */
if(!s->budget--) { s->failed_pc=0x0c075b40u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c075b76; }
goto P_0c075b42;
P_0c075b42: /* original 9068, guest PC 0x0c075b42 */
if(!s->budget--) { s->failed_pc=0x0c075b42u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c075c16u,2);
goto P_0c075b44;
P_0c075b44: /* original d239, guest PC 0x0c075b44 */
if(!s->budget--) { s->failed_pc=0x0c075b44u; return 0; }
r[2]=read(ram,0x0c075c2cu,4);
goto P_0c075b46;
P_0c075b46: /* original 01fe, guest PC 0x0c075b46 */
if(!s->budget--) { s->failed_pc=0x0c075b46u; return 0; }
r[1]=read(ram,r[15]+r[0],4);
goto P_0c075b48;
P_0c075b48: /* original 9066, guest PC 0x0c075b48 */
if(!s->budget--) { s->failed_pc=0x0c075b48u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c075c18u,2);
goto P_0c075b4a;
P_0c075b4a: /* original 2129, guest PC 0x0c075b4a */
if(!s->budget--) { s->failed_pc=0x0c075b4au; return 0; }
r[1]&=r[2];
goto P_0c075b4c;
P_0c075b4c: /* original 2118, guest PC 0x0c075b4c */
if(!s->budget--) { s->failed_pc=0x0c075b4cu; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[1])==0)!=0);
goto P_0c075b4e;
P_0c075b4e: /* original 8d02, guest PC 0x0c075b4e */
if(!s->budget--) { s->failed_pc=0x0c075b4eu; return 0; }
cond=r[17]&1u;
write(ram,r[15]+r[0],r[1],4);
if(cond) { goto P_0c075b56; }
goto P_0c075b52;
P_0c075b50: /* original 0f16, guest PC 0x0c075b50 */
if(!s->budget--) { s->failed_pc=0x0c075b50u; return 0; }
write(ram,r[15]+r[0],r[1],4);
goto P_0c075b52;
P_0c075b52: /* original a09f, guest PC 0x0c075b52 */
if(!s->budget--) { s->failed_pc=0x0c075b52u; return 0; }
goto P_0c075c94;
P_0c075b54: /* original 0009, guest PC 0x0c075b54 */
if(!s->budget--) { s->failed_pc=0x0c075b54u; return 0; }
goto P_0c075b56;
P_0c075b56: /* original e04c, guest PC 0x0c075b56 */
if(!s->budget--) { s->failed_pc=0x0c075b56u; return 0; }
r[0]=0x0000004cu;
goto P_0c075b58;
P_0c075b58: /* original d335, guest PC 0x0c075b58 */
if(!s->budget--) { s->failed_pc=0x0c075b58u; return 0; }
r[3]=read(ram,0x0c075c30u,4);
goto P_0c075b5a;
P_0c075b5a: /* original 02fe, guest PC 0x0c075b5a */
if(!s->budget--) { s->failed_pc=0x0c075b5au; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c075b5c;
P_0c075b5c: /* original e04c, guest PC 0x0c075b5c */
if(!s->budget--) { s->failed_pc=0x0c075b5cu; return 0; }
r[0]=0x0000004cu;
goto P_0c075b5e;
P_0c075b5e: /* original 223b, guest PC 0x0c075b5e */
if(!s->budget--) { s->failed_pc=0x0c075b5eu; return 0; }
r[2]|=r[3];
goto P_0c075b60;
P_0c075b60: /* original 0f26, guest PC 0x0c075b60 */
if(!s->budget--) { s->failed_pc=0x0c075b60u; return 0; }
write(ram,r[15]+r[0],r[2],4);
goto P_0c075b62;
P_0c075b62: /* original e054, guest PC 0x0c075b62 */
if(!s->budget--) { s->failed_pc=0x0c075b62u; return 0; }
r[0]=0x00000054u;
goto P_0c075b64;
P_0c075b64: /* original 01fe, guest PC 0x0c075b64 */
if(!s->budget--) { s->failed_pc=0x0c075b64u; return 0; }
r[1]=read(ram,r[15]+r[0],4);
goto P_0c075b66;
P_0c075b66: /* original 9058, guest PC 0x0c075b66 */
if(!s->budget--) { s->failed_pc=0x0c075b66u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c075c1au,2);
goto P_0c075b68;
P_0c075b68: /* original 4109, guest PC 0x0c075b68 */
if(!s->budget--) { s->failed_pc=0x0c075b68u; return 0; }
r[1]>>=2;
goto P_0c075b6a;
P_0c075b6a: /* original 0f16, guest PC 0x0c075b6a */
if(!s->budget--) { s->failed_pc=0x0c075b6au; return 0; }
write(ram,r[15]+r[0],r[1],4);
goto P_0c075b6c;
P_0c075b6c: /* original e054, guest PC 0x0c075b6c */
if(!s->budget--) { s->failed_pc=0x0c075b6cu; return 0; }
r[0]=0x00000054u;
goto P_0c075b6e;
P_0c075b6e: /* original 03fe, guest PC 0x0c075b6e */
if(!s->budget--) { s->failed_pc=0x0c075b6eu; return 0; }
r[3]=read(ram,r[15]+r[0],4);
goto P_0c075b70;
P_0c075b70: /* original 3318, guest PC 0x0c075b70 */
if(!s->budget--) { s->failed_pc=0x0c075b70u; return 0; }
r[3]-=r[1];
goto P_0c075b72;
P_0c075b72: /* original a029, guest PC 0x0c075b72 */
if(!s->budget--) { s->failed_pc=0x0c075b72u; return 0; }
goto P_0c075bc8;
P_0c075b74: /* original 0009, guest PC 0x0c075b74 */
if(!s->budget--) { s->failed_pc=0x0c075b74u; return 0; }
goto P_0c075b76;
P_0c075b76: /* original 9051, guest PC 0x0c075b76 */
if(!s->budget--) { s->failed_pc=0x0c075b76u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c075c1cu,2);
goto P_0c075b78;
P_0c075b78: /* original 02fe, guest PC 0x0c075b78 */
if(!s->budget--) { s->failed_pc=0x0c075b78u; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c075b7a;
P_0c075b7a: /* original 9050, guest PC 0x0c075b7a */
if(!s->budget--) { s->failed_pc=0x0c075b7au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c075c1eu,2);
goto P_0c075b7c;
P_0c075b7c: /* original 032c, guest PC 0x0c075b7c */
if(!s->budget--) { s->failed_pc=0x0c075b7cu; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[2]+r[0],1);
goto P_0c075b7e;
P_0c075b7e: /* original e201, guest PC 0x0c075b7e */
if(!s->budget--) { s->failed_pc=0x0c075b7eu; return 0; }
r[2]=0x00000001u;
goto P_0c075b80;
P_0c075b80: /* original 633c, guest PC 0x0c075b80 */
if(!s->budget--) { s->failed_pc=0x0c075b80u; return 0; }
r[3]=r[3]&255u;
goto P_0c075b82;
P_0c075b82: /* original 3327, guest PC 0x0c075b82 */
if(!s->budget--) { s->failed_pc=0x0c075b82u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>(int32_t)r[2])!=0);
goto P_0c075b84;
P_0c075b84: /* original 8b01, guest PC 0x0c075b84 */
if(!s->budget--) { s->failed_pc=0x0c075b84u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c075b8a; }
goto P_0c075b86;
P_0c075b86: /* original a085, guest PC 0x0c075b86 */
if(!s->budget--) { s->failed_pc=0x0c075b86u; return 0; }
goto P_0c075c94;
P_0c075b88: /* original 0009, guest PC 0x0c075b88 */
if(!s->budget--) { s->failed_pc=0x0c075b88u; return 0; }
goto P_0c075b8a;
P_0c075b8a: /* original e05c, guest PC 0x0c075b8a */
if(!s->budget--) { s->failed_pc=0x0c075b8au; return 0; }
r[0]=0x0000005cu;
goto P_0c075b8c;
P_0c075b8c: /* original d329, guest PC 0x0c075b8c */
if(!s->budget--) { s->failed_pc=0x0c075b8cu; return 0; }
r[3]=read(ram,0x0c075c34u,4);
goto P_0c075b8e;
P_0c075b8e: /* original 01fe, guest PC 0x0c075b8e */
if(!s->budget--) { s->failed_pc=0x0c075b8eu; return 0; }
r[1]=read(ram,r[15]+r[0],4);
goto P_0c075b90;
P_0c075b90: /* original 2138, guest PC 0x0c075b90 */
if(!s->budget--) { s->failed_pc=0x0c075b90u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[3])==0)!=0);
goto P_0c075b92;
P_0c075b92: /* original 8b1c, guest PC 0x0c075b92 */
if(!s->budget--) { s->failed_pc=0x0c075b92u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c075bce; }
goto P_0c075b94;
P_0c075b94: /* original 9040, guest PC 0x0c075b94 */
if(!s->budget--) { s->failed_pc=0x0c075b94u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c075c18u,2);
goto P_0c075b96;
P_0c075b96: /* original d228, guest PC 0x0c075b96 */
if(!s->budget--) { s->failed_pc=0x0c075b96u; return 0; }
r[2]=read(ram,0x0c075c38u,4);
goto P_0c075b98;
P_0c075b98: /* original 0f26, guest PC 0x0c075b98 */
if(!s->budget--) { s->failed_pc=0x0c075b98u; return 0; }
write(ram,r[15]+r[0],r[2],4);
goto P_0c075b9a;
P_0c075b9a: /* original 903c, guest PC 0x0c075b9a */
if(!s->budget--) { s->failed_pc=0x0c075b9au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c075c16u,2);
goto P_0c075b9c;
P_0c075b9c: /* original 02fe, guest PC 0x0c075b9c */
if(!s->budget--) { s->failed_pc=0x0c075b9cu; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c075b9e;
P_0c075b9e: /* original 903b, guest PC 0x0c075b9e */
if(!s->budget--) { s->failed_pc=0x0c075b9eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c075c18u,2);
goto P_0c075ba0;
P_0c075ba0: /* original 01fe, guest PC 0x0c075ba0 */
if(!s->budget--) { s->failed_pc=0x0c075ba0u; return 0; }
r[1]=read(ram,r[15]+r[0],4);
goto P_0c075ba2;
P_0c075ba2: /* original 9039, guest PC 0x0c075ba2 */
if(!s->budget--) { s->failed_pc=0x0c075ba2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c075c18u,2);
goto P_0c075ba4;
P_0c075ba4: /* original 2129, guest PC 0x0c075ba4 */
if(!s->budget--) { s->failed_pc=0x0c075ba4u; return 0; }
r[1]&=r[2];
goto P_0c075ba6;
P_0c075ba6: /* original 2118, guest PC 0x0c075ba6 */
if(!s->budget--) { s->failed_pc=0x0c075ba6u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[1])==0)!=0);
goto P_0c075ba8;
P_0c075ba8: /* original 8f11, guest PC 0x0c075ba8 */
if(!s->budget--) { s->failed_pc=0x0c075ba8u; return 0; }
cond=r[17]&1u;
write(ram,r[15]+r[0],r[1],4);
if(!cond) { goto P_0c075bce; }
goto P_0c075bac;
P_0c075baa: /* original 0f16, guest PC 0x0c075baa */
if(!s->budget--) { s->failed_pc=0x0c075baau; return 0; }
write(ram,r[15]+r[0],r[1],4);
goto P_0c075bac;
P_0c075bac: /* original e04c, guest PC 0x0c075bac */
if(!s->budget--) { s->failed_pc=0x0c075bacu; return 0; }
r[0]=0x0000004cu;
goto P_0c075bae;
P_0c075bae: /* original 62f3, guest PC 0x0c075bae */
if(!s->budget--) { s->failed_pc=0x0c075baeu; return 0; }
r[2]=r[15];
goto P_0c075bb0;
P_0c075bb0: /* original 00fe, guest PC 0x0c075bb0 */
if(!s->budget--) { s->failed_pc=0x0c075bb0u; return 0; }
r[0]=read(ram,r[15]+r[0],4);
goto P_0c075bb2;
P_0c075bb2: /* original 724c, guest PC 0x0c075bb2 */
if(!s->budget--) { s->failed_pc=0x0c075bb2u; return 0; }
r[2]+=0x0000004cu;
goto P_0c075bb4;
P_0c075bb4: /* original cb20, guest PC 0x0c075bb4 */
if(!s->budget--) { s->failed_pc=0x0c075bb4u; return 0; }
r[0]|=32u;
goto P_0c075bb6;
P_0c075bb6: /* original 2202, guest PC 0x0c075bb6 */
if(!s->budget--) { s->failed_pc=0x0c075bb6u; return 0; }
write(ram,r[2],r[0],4);
goto P_0c075bb8;
P_0c075bb8: /* original e054, guest PC 0x0c075bb8 */
if(!s->budget--) { s->failed_pc=0x0c075bb8u; return 0; }
r[0]=0x00000054u;
goto P_0c075bba;
P_0c075bba: /* original 03fe, guest PC 0x0c075bba */
if(!s->budget--) { s->failed_pc=0x0c075bbau; return 0; }
r[3]=read(ram,r[15]+r[0],4);
goto P_0c075bbc;
P_0c075bbc: /* original 902d, guest PC 0x0c075bbc */
if(!s->budget--) { s->failed_pc=0x0c075bbcu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c075c1au,2);
goto P_0c075bbe;
P_0c075bbe: /* original 4309, guest PC 0x0c075bbe */
if(!s->budget--) { s->failed_pc=0x0c075bbeu; return 0; }
r[3]>>=2;
goto P_0c075bc0;
P_0c075bc0: /* original 0f36, guest PC 0x0c075bc0 */
if(!s->budget--) { s->failed_pc=0x0c075bc0u; return 0; }
write(ram,r[15]+r[0],r[3],4);
goto P_0c075bc2;
P_0c075bc2: /* original e054, guest PC 0x0c075bc2 */
if(!s->budget--) { s->failed_pc=0x0c075bc2u; return 0; }
r[0]=0x00000054u;
goto P_0c075bc4;
P_0c075bc4: /* original 02fe, guest PC 0x0c075bc4 */
if(!s->budget--) { s->failed_pc=0x0c075bc4u; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c075bc6;
P_0c075bc6: /* original 332c, guest PC 0x0c075bc6 */
if(!s->budget--) { s->failed_pc=0x0c075bc6u; return 0; }
r[3]+=r[2];
goto P_0c075bc8;
P_0c075bc8: /* original 9027, guest PC 0x0c075bc8 */
if(!s->budget--) { s->failed_pc=0x0c075bc8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c075c1au,2);
goto P_0c075bca;
P_0c075bca: /* original a063, guest PC 0x0c075bca */
if(!s->budget--) { s->failed_pc=0x0c075bcau; return 0; }
write(ram,r[15]+r[0],r[3],4);
goto P_0c075c94;
P_0c075bcc: /* original 0f36, guest PC 0x0c075bcc */
if(!s->budget--) { s->failed_pc=0x0c075bccu; return 0; }
write(ram,r[15]+r[0],r[3],4);
goto P_0c075bce;
P_0c075bce: /* original 9025, guest PC 0x0c075bce */
if(!s->budget--) { s->failed_pc=0x0c075bceu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c075c1cu,2);
goto P_0c075bd0;
P_0c075bd0: /* original 9326, guest PC 0x0c075bd0 */
if(!s->budget--) { s->failed_pc=0x0c075bd0u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c075c20u,2);
goto P_0c075bd2;
P_0c075bd2: /* original 01fe, guest PC 0x0c075bd2 */
if(!s->budget--) { s->failed_pc=0x0c075bd2u; return 0; }
r[1]=read(ram,r[15]+r[0],4);
goto P_0c075bd4;
P_0c075bd4: /* original e04c, guest PC 0x0c075bd4 */
if(!s->budget--) { s->failed_pc=0x0c075bd4u; return 0; }
r[0]=0x0000004cu;
goto P_0c075bd6;
P_0c075bd6: /* original 021e, guest PC 0x0c075bd6 */
if(!s->budget--) { s->failed_pc=0x0c075bd6u; return 0; }
r[2]=read(ram,r[1]+r[0],4);
goto P_0c075bd8;
P_0c075bd8: /* original 2238, guest PC 0x0c075bd8 */
if(!s->budget--) { s->failed_pc=0x0c075bd8u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c075bda;
P_0c075bda: /* original 8b09, guest PC 0x0c075bda */
if(!s->budget--) { s->failed_pc=0x0c075bdau; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c075bf0; }
goto P_0c075bdc;
P_0c075bdc: /* original 61f3, guest PC 0x0c075bdc */
if(!s->budget--) { s->failed_pc=0x0c075bdcu; return 0; }
r[1]=r[15];
goto P_0c075bde;
P_0c075bde: /* original 715c, guest PC 0x0c075bde */
if(!s->budget--) { s->failed_pc=0x0c075bdeu; return 0; }
r[1]+=0x0000005cu;
goto P_0c075be0;
P_0c075be0: /* original 6012, guest PC 0x0c075be0 */
if(!s->budget--) { s->failed_pc=0x0c075be0u; return 0; }
tmp=read(ram,r[1],4);
r[0]=tmp;
goto P_0c075be2;
P_0c075be2: /* original c808, guest PC 0x0c075be2 */
if(!s->budget--) { s->failed_pc=0x0c075be2u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&8u)==0)!=0);
goto P_0c075be4;
P_0c075be4: /* original 892e, guest PC 0x0c075be4 */
if(!s->budget--) { s->failed_pc=0x0c075be4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c075c44; }
goto P_0c075be6;
P_0c075be6: /* original e05c, guest PC 0x0c075be6 */
if(!s->budget--) { s->failed_pc=0x0c075be6u; return 0; }
r[0]=0x0000005cu;
goto P_0c075be8;
P_0c075be8: /* original d214, guest PC 0x0c075be8 */
if(!s->budget--) { s->failed_pc=0x0c075be8u; return 0; }
r[2]=read(ram,0x0c075c3cu,4);
goto P_0c075bea;
P_0c075bea: /* original 01fe, guest PC 0x0c075bea */
if(!s->budget--) { s->failed_pc=0x0c075beau; return 0; }
r[1]=read(ram,r[15]+r[0],4);
goto P_0c075bec;
P_0c075bec: /* original 2128, guest PC 0x0c075bec */
if(!s->budget--) { s->failed_pc=0x0c075becu; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[2])==0)!=0);
goto P_0c075bee;
P_0c075bee: /* original 8b29, guest PC 0x0c075bee */
if(!s->budget--) { s->failed_pc=0x0c075beeu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c075c44; }
goto P_0c075bf0;
P_0c075bf0: /* original e04c, guest PC 0x0c075bf0 */
if(!s->budget--) { s->failed_pc=0x0c075bf0u; return 0; }
r[0]=0x0000004cu;
goto P_0c075bf2;
P_0c075bf2: /* original d313, guest PC 0x0c075bf2 */
if(!s->budget--) { s->failed_pc=0x0c075bf2u; return 0; }
r[3]=read(ram,0x0c075c40u,4);
goto P_0c075bf4;
P_0c075bf4: /* original 02fe, guest PC 0x0c075bf4 */
if(!s->budget--) { s->failed_pc=0x0c075bf4u; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c075bf6;
P_0c075bf6: /* original e04c, guest PC 0x0c075bf6 */
if(!s->budget--) { s->failed_pc=0x0c075bf6u; return 0; }
r[0]=0x0000004cu;
goto P_0c075bf8;
P_0c075bf8: /* original 223b, guest PC 0x0c075bf8 */
if(!s->budget--) { s->failed_pc=0x0c075bf8u; return 0; }
r[2]|=r[3];
goto P_0c075bfa;
P_0c075bfa: /* original 0f26, guest PC 0x0c075bfa */
if(!s->budget--) { s->failed_pc=0x0c075bfau; return 0; }
write(ram,r[15]+r[0],r[2],4);
goto P_0c075bfc;
P_0c075bfc: /* original e054, guest PC 0x0c075bfc */
if(!s->budget--) { s->failed_pc=0x0c075bfcu; return 0; }
r[0]=0x00000054u;
goto P_0c075bfe;
P_0c075bfe: /* original 01fe, guest PC 0x0c075bfe */
if(!s->budget--) { s->failed_pc=0x0c075bfeu; return 0; }
r[1]=read(ram,r[15]+r[0],4);
goto P_0c075c00;
P_0c075c00: /* original 900b, guest PC 0x0c075c00 */
if(!s->budget--) { s->failed_pc=0x0c075c00u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c075c1au,2);
goto P_0c075c02;
P_0c075c02: /* original 4109, guest PC 0x0c075c02 */
if(!s->budget--) { s->failed_pc=0x0c075c02u; return 0; }
r[1]>>=2;
goto P_0c075c04;
P_0c075c04: /* original 0f16, guest PC 0x0c075c04 */
if(!s->budget--) { s->failed_pc=0x0c075c04u; return 0; }
write(ram,r[15]+r[0],r[1],4);
goto P_0c075c06;
P_0c075c06: /* original e054, guest PC 0x0c075c06 */
if(!s->budget--) { s->failed_pc=0x0c075c06u; return 0; }
r[0]=0x00000054u;
goto P_0c075c08;
P_0c075c08: /* original 03fe, guest PC 0x0c075c08 */
if(!s->budget--) { s->failed_pc=0x0c075c08u; return 0; }
r[3]=read(ram,r[15]+r[0],4);
goto P_0c075c0a;
P_0c075c0a: /* original 313c, guest PC 0x0c075c0a */
if(!s->budget--) { s->failed_pc=0x0c075c0au; return 0; }
r[1]+=r[3];
goto P_0c075c0c;
P_0c075c0c: /* original a040, guest PC 0x0c075c0c */
if(!s->budget--) { s->failed_pc=0x0c075c0cu; return 0; }
goto P_0c075c90;
P_0c075c0e: /* original 0009, guest PC 0x0c075c0e */
if(!s->budget--) { s->failed_pc=0x0c075c0eu; return 0; }
return vf3_matrix_family(0x0c075c10u,s,ram);
P_0c075c44: /* original e05c, guest PC 0x0c075c44 */
if(!s->budget--) { s->failed_pc=0x0c075c44u; return 0; }
r[0]=0x0000005cu;
goto P_0c075c46;
P_0c075c46: /* original d323, guest PC 0x0c075c46 */
if(!s->budget--) { s->failed_pc=0x0c075c46u; return 0; }
r[3]=read(ram,0x0c075cd4u,4);
goto P_0c075c48;
P_0c075c48: /* original 02fe, guest PC 0x0c075c48 */
if(!s->budget--) { s->failed_pc=0x0c075c48u; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c075c4a;
P_0c075c4a: /* original 2238, guest PC 0x0c075c4a */
if(!s->budget--) { s->failed_pc=0x0c075c4au; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c075c4c;
P_0c075c4c: /* original 8922, guest PC 0x0c075c4c */
if(!s->budget--) { s->failed_pc=0x0c075c4cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c075c94; }
goto P_0c075c4e;
P_0c075c4e: /* original e05c, guest PC 0x0c075c4e */
if(!s->budget--) { s->failed_pc=0x0c075c4eu; return 0; }
r[0]=0x0000005cu;
goto P_0c075c50;
P_0c075c50: /* original d321, guest PC 0x0c075c50 */
if(!s->budget--) { s->failed_pc=0x0c075c50u; return 0; }
r[3]=read(ram,0x0c075cd8u,4);
goto P_0c075c52;
P_0c075c52: /* original 01fe, guest PC 0x0c075c52 */
if(!s->budget--) { s->failed_pc=0x0c075c52u; return 0; }
r[1]=read(ram,r[15]+r[0],4);
goto P_0c075c54;
P_0c075c54: /* original 2138, guest PC 0x0c075c54 */
if(!s->budget--) { s->failed_pc=0x0c075c54u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[3])==0)!=0);
goto P_0c075c56;
P_0c075c56: /* original 8b1d, guest PC 0x0c075c56 */
if(!s->budget--) { s->failed_pc=0x0c075c56u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c075c94; }
goto P_0c075c58;
P_0c075c58: /* original e05c, guest PC 0x0c075c58 */
if(!s->budget--) { s->failed_pc=0x0c075c58u; return 0; }
r[0]=0x0000005cu;
goto P_0c075c5a;
P_0c075c5a: /* original d320, guest PC 0x0c075c5a */
if(!s->budget--) { s->failed_pc=0x0c075c5au; return 0; }
r[3]=read(ram,0x0c075cdcu,4);
goto P_0c075c5c;
P_0c075c5c: /* original 02fe, guest PC 0x0c075c5c */
if(!s->budget--) { s->failed_pc=0x0c075c5cu; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c075c5e;
P_0c075c5e: /* original 2238, guest PC 0x0c075c5e */
if(!s->budget--) { s->failed_pc=0x0c075c5eu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c075c60;
P_0c075c60: /* original 8b18, guest PC 0x0c075c60 */
if(!s->budget--) { s->failed_pc=0x0c075c60u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c075c94; }
goto P_0c075c62;
P_0c075c62: /* original e060, guest PC 0x0c075c62 */
if(!s->budget--) { s->failed_pc=0x0c075c62u; return 0; }
r[0]=0x00000060u;
goto P_0c075c64;
P_0c075c64: /* original 00fe, guest PC 0x0c075c64 */
if(!s->budget--) { s->failed_pc=0x0c075c64u; return 0; }
r[0]=read(ram,r[15]+r[0],4);
goto P_0c075c66;
P_0c075c66: /* original 8801, guest PC 0x0c075c66 */
if(!s->budget--) { s->failed_pc=0x0c075c66u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c075c68;
P_0c075c68: /* original 8903, guest PC 0x0c075c68 */
if(!s->budget--) { s->failed_pc=0x0c075c68u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c075c72; }
goto P_0c075c6a;
P_0c075c6a: /* original e060, guest PC 0x0c075c6a */
if(!s->budget--) { s->failed_pc=0x0c075c6au; return 0; }
r[0]=0x00000060u;
goto P_0c075c6c;
P_0c075c6c: /* original 00fe, guest PC 0x0c075c6c */
if(!s->budget--) { s->failed_pc=0x0c075c6cu; return 0; }
r[0]=read(ram,r[15]+r[0],4);
goto P_0c075c6e;
P_0c075c6e: /* original 8803, guest PC 0x0c075c6e */
if(!s->budget--) { s->failed_pc=0x0c075c6eu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000003u)!=0);
goto P_0c075c70;
P_0c075c70: /* original 8b10, guest PC 0x0c075c70 */
if(!s->budget--) { s->failed_pc=0x0c075c70u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c075c94; }
goto P_0c075c72;
P_0c075c72: /* original e04c, guest PC 0x0c075c72 */
if(!s->budget--) { s->failed_pc=0x0c075c72u; return 0; }
r[0]=0x0000004cu;
goto P_0c075c74;
P_0c075c74: /* original d318, guest PC 0x0c075c74 */
if(!s->budget--) { s->failed_pc=0x0c075c74u; return 0; }
r[3]=read(ram,0x0c075cd8u,4);
goto P_0c075c76;
P_0c075c76: /* original 02fe, guest PC 0x0c075c76 */
if(!s->budget--) { s->failed_pc=0x0c075c76u; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c075c78;
P_0c075c78: /* original e04c, guest PC 0x0c075c78 */
if(!s->budget--) { s->failed_pc=0x0c075c78u; return 0; }
r[0]=0x0000004cu;
goto P_0c075c7a;
P_0c075c7a: /* original 223b, guest PC 0x0c075c7a */
if(!s->budget--) { s->failed_pc=0x0c075c7au; return 0; }
r[2]|=r[3];
goto P_0c075c7c;
P_0c075c7c: /* original 0f26, guest PC 0x0c075c7c */
if(!s->budget--) { s->failed_pc=0x0c075c7cu; return 0; }
write(ram,r[15]+r[0],r[2],4);
goto P_0c075c7e;
P_0c075c7e: /* original e054, guest PC 0x0c075c7e */
if(!s->budget--) { s->failed_pc=0x0c075c7eu; return 0; }
r[0]=0x00000054u;
goto P_0c075c80;
P_0c075c80: /* original 01fe, guest PC 0x0c075c80 */
if(!s->budget--) { s->failed_pc=0x0c075c80u; return 0; }
r[1]=read(ram,r[15]+r[0],4);
goto P_0c075c82;
P_0c075c82: /* original 9023, guest PC 0x0c075c82 */
if(!s->budget--) { s->failed_pc=0x0c075c82u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c075cccu,2);
goto P_0c075c84;
P_0c075c84: /* original 4109, guest PC 0x0c075c84 */
if(!s->budget--) { s->failed_pc=0x0c075c84u; return 0; }
r[1]>>=2;
goto P_0c075c86;
P_0c075c86: /* original 4101, guest PC 0x0c075c86 */
if(!s->budget--) { s->failed_pc=0x0c075c86u; return 0; }
r[17]=(r[17]&~1u)|((r[1]&1)!=0);
r[1]>>=1;
goto P_0c075c88;
P_0c075c88: /* original 0f16, guest PC 0x0c075c88 */
if(!s->budget--) { s->failed_pc=0x0c075c88u; return 0; }
write(ram,r[15]+r[0],r[1],4);
goto P_0c075c8a;
P_0c075c8a: /* original e054, guest PC 0x0c075c8a */
if(!s->budget--) { s->failed_pc=0x0c075c8au; return 0; }
r[0]=0x00000054u;
goto P_0c075c8c;
P_0c075c8c: /* original 03fe, guest PC 0x0c075c8c */
if(!s->budget--) { s->failed_pc=0x0c075c8cu; return 0; }
r[3]=read(ram,r[15]+r[0],4);
goto P_0c075c8e;
P_0c075c8e: /* original 313c, guest PC 0x0c075c8e */
if(!s->budget--) { s->failed_pc=0x0c075c8eu; return 0; }
r[1]+=r[3];
goto P_0c075c90;
P_0c075c90: /* original 901c, guest PC 0x0c075c90 */
if(!s->budget--) { s->failed_pc=0x0c075c90u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c075cccu,2);
goto P_0c075c92;
P_0c075c92: /* original 0f16, guest PC 0x0c075c92 */
if(!s->budget--) { s->failed_pc=0x0c075c92u; return 0; }
write(ram,r[15]+r[0],r[1],4);
goto P_0c075c94;
P_0c075c94: /* original e05c, guest PC 0x0c075c94 */
if(!s->budget--) { s->failed_pc=0x0c075c94u; return 0; }
r[0]=0x0000005cu;
goto P_0c075c96;
P_0c075c96: /* original d312, guest PC 0x0c075c96 */
if(!s->budget--) { s->failed_pc=0x0c075c96u; return 0; }
r[3]=read(ram,0x0c075ce0u,4);
goto P_0c075c98;
P_0c075c98: /* original 02fe, guest PC 0x0c075c98 */
if(!s->budget--) { s->failed_pc=0x0c075c98u; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c075c9a;
P_0c075c9a: /* original 2238, guest PC 0x0c075c9a */
if(!s->budget--) { s->failed_pc=0x0c075c9au; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c075c9c;
P_0c075c9c: /* original 894d, guest PC 0x0c075c9c */
if(!s->budget--) { s->failed_pc=0x0c075c9cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c075d3a; }
goto P_0c075c9e;
P_0c075c9e: /* original 9016, guest PC 0x0c075c9e */
if(!s->budget--) { s->failed_pc=0x0c075c9eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c075cceu,2);
goto P_0c075ca0;
P_0c075ca0: /* original 02fe, guest PC 0x0c075ca0 */
if(!s->budget--) { s->failed_pc=0x0c075ca0u; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c075ca2;
P_0c075ca2: /* original 9015, guest PC 0x0c075ca2 */
if(!s->budget--) { s->failed_pc=0x0c075ca2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c075cd0u,2);
goto P_0c075ca4;
P_0c075ca4: /* original 012c, guest PC 0x0c075ca4 */
if(!s->budget--) { s->failed_pc=0x0c075ca4u; return 0; }
r[1]=(uint32_t)(int32_t)(int8_t)read(ram,r[2]+r[0],1);
goto P_0c075ca6;
P_0c075ca6: /* original e204, guest PC 0x0c075ca6 */
if(!s->budget--) { s->failed_pc=0x0c075ca6u; return 0; }
r[2]=0x00000004u;
goto P_0c075ca8;
P_0c075ca8: /* original 9013, guest PC 0x0c075ca8 */
if(!s->budget--) { s->failed_pc=0x0c075ca8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c075cd2u,2);
goto P_0c075caa;
P_0c075caa: /* original 611c, guest PC 0x0c075caa */
if(!s->budget--) { s->failed_pc=0x0c075caau; return 0; }
r[1]=r[1]&255u;
goto P_0c075cac;
P_0c075cac: /* original 3126, guest PC 0x0c075cac */
if(!s->budget--) { s->failed_pc=0x0c075cacu; return 0; }
r[17]=(r[17]&~1u)|((r[1]>r[2])!=0);
goto P_0c075cae;
P_0c075cae: /* original 0f16, guest PC 0x0c075cae */
if(!s->budget--) { s->failed_pc=0x0c075caeu; return 0; }
write(ram,r[15]+r[0],r[1],4);
goto P_0c075cb0;
P_0c075cb0: /* original 8b18, guest PC 0x0c075cb0 */
if(!s->budget--) { s->failed_pc=0x0c075cb0u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c075ce4; }
goto P_0c075cb2;
P_0c075cb2: /* original 900b, guest PC 0x0c075cb2 */
if(!s->budget--) { s->failed_pc=0x0c075cb2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c075cccu,2);
goto P_0c075cb4;
P_0c075cb4: /* original 02fe, guest PC 0x0c075cb4 */
if(!s->budget--) { s->failed_pc=0x0c075cb4u; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c075cb6;
P_0c075cb6: /* original 900c, guest PC 0x0c075cb6 */
if(!s->budget--) { s->failed_pc=0x0c075cb6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c075cd2u,2);
goto P_0c075cb8;
P_0c075cb8: /* original 4221, guest PC 0x0c075cb8 */
if(!s->budget--) { s->failed_pc=0x0c075cb8u; return 0; }
r[17]=(r[17]&~1u)|((r[2]&1)!=0);
r[2]=(uint32_t)((int32_t)r[2]>>1);
goto P_0c075cba;
P_0c075cba: /* original 4221, guest PC 0x0c075cba */
if(!s->budget--) { s->failed_pc=0x0c075cbau; return 0; }
r[17]=(r[17]&~1u)|((r[2]&1)!=0);
r[2]=(uint32_t)((int32_t)r[2]>>1);
goto P_0c075cbc;
P_0c075cbc: /* original 0f26, guest PC 0x0c075cbc */
if(!s->budget--) { s->failed_pc=0x0c075cbcu; return 0; }
write(ram,r[15]+r[0],r[2],4);
goto P_0c075cbe;
P_0c075cbe: /* original 9005, guest PC 0x0c075cbe */
if(!s->budget--) { s->failed_pc=0x0c075cbeu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c075cccu,2);
goto P_0c075cc0;
P_0c075cc0: /* original 01fe, guest PC 0x0c075cc0 */
if(!s->budget--) { s->failed_pc=0x0c075cc0u; return 0; }
r[1]=read(ram,r[15]+r[0],4);
goto P_0c075cc2;
P_0c075cc2: /* original 9003, guest PC 0x0c075cc2 */
if(!s->budget--) { s->failed_pc=0x0c075cc2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c075cccu,2);
goto P_0c075cc4;
P_0c075cc4: /* original 3128, guest PC 0x0c075cc4 */
if(!s->budget--) { s->failed_pc=0x0c075cc4u; return 0; }
r[1]-=r[2];
goto P_0c075cc6;
P_0c075cc6: /* original 0f16, guest PC 0x0c075cc6 */
if(!s->budget--) { s->failed_pc=0x0c075cc6u; return 0; }
write(ram,r[15]+r[0],r[1],4);
goto P_0c075cc8;
P_0c075cc8: /* original a01b, guest PC 0x0c075cc8 */
if(!s->budget--) { s->failed_pc=0x0c075cc8u; return 0; }
goto P_0c075d02;
P_0c075cca: /* original 0009, guest PC 0x0c075cca */
if(!s->budget--) { s->failed_pc=0x0c075ccau; return 0; }
return vf3_matrix_family(0x0c075cccu,s,ram);
P_0c075ce4: /* original e203, guest PC 0x0c075ce4 */
if(!s->budget--) { s->failed_pc=0x0c075ce4u; return 0; }
r[2]=0x00000003u;
goto P_0c075ce6;
P_0c075ce6: /* original 3126, guest PC 0x0c075ce6 */
if(!s->budget--) { s->failed_pc=0x0c075ce6u; return 0; }
r[17]=(r[17]&~1u)|((r[1]>r[2])!=0);
goto P_0c075ce8;
P_0c075ce8: /* original 8b0b, guest PC 0x0c075ce8 */
if(!s->budget--) { s->failed_pc=0x0c075ce8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c075d02; }
goto P_0c075cea;
P_0c075cea: /* original 9091, guest PC 0x0c075cea */
if(!s->budget--) { s->failed_pc=0x0c075ceau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c075e10u,2);
goto P_0c075cec;
P_0c075cec: /* original 02fe, guest PC 0x0c075cec */
if(!s->budget--) { s->failed_pc=0x0c075cecu; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c075cee;
P_0c075cee: /* original 9090, guest PC 0x0c075cee */
if(!s->budget--) { s->failed_pc=0x0c075ceeu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c075e12u,2);
goto P_0c075cf0;
P_0c075cf0: /* original 4221, guest PC 0x0c075cf0 */
if(!s->budget--) { s->failed_pc=0x0c075cf0u; return 0; }
r[17]=(r[17]&~1u)|((r[2]&1)!=0);
r[2]=(uint32_t)((int32_t)r[2]>>1);
goto P_0c075cf2;
P_0c075cf2: /* original 4221, guest PC 0x0c075cf2 */
if(!s->budget--) { s->failed_pc=0x0c075cf2u; return 0; }
r[17]=(r[17]&~1u)|((r[2]&1)!=0);
r[2]=(uint32_t)((int32_t)r[2]>>1);
goto P_0c075cf4;
P_0c075cf4: /* original 4221, guest PC 0x0c075cf4 */
if(!s->budget--) { s->failed_pc=0x0c075cf4u; return 0; }
r[17]=(r[17]&~1u)|((r[2]&1)!=0);
r[2]=(uint32_t)((int32_t)r[2]>>1);
goto P_0c075cf6;
P_0c075cf6: /* original 0f26, guest PC 0x0c075cf6 */
if(!s->budget--) { s->failed_pc=0x0c075cf6u; return 0; }
write(ram,r[15]+r[0],r[2],4);
goto P_0c075cf8;
P_0c075cf8: /* original 908a, guest PC 0x0c075cf8 */
if(!s->budget--) { s->failed_pc=0x0c075cf8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c075e10u,2);
goto P_0c075cfa;
P_0c075cfa: /* original 01fe, guest PC 0x0c075cfa */
if(!s->budget--) { s->failed_pc=0x0c075cfau; return 0; }
r[1]=read(ram,r[15]+r[0],4);
goto P_0c075cfc;
P_0c075cfc: /* original 9088, guest PC 0x0c075cfc */
if(!s->budget--) { s->failed_pc=0x0c075cfcu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c075e10u,2);
goto P_0c075cfe;
P_0c075cfe: /* original 3128, guest PC 0x0c075cfe */
if(!s->budget--) { s->failed_pc=0x0c075cfeu; return 0; }
r[1]-=r[2];
goto P_0c075d00;
P_0c075d00: /* original 0f16, guest PC 0x0c075d00 */
if(!s->budget--) { s->failed_pc=0x0c075d00u; return 0; }
write(ram,r[15]+r[0],r[1],4);
goto P_0c075d02;
P_0c075d02: /* original 9087, guest PC 0x0c075d02 */
if(!s->budget--) { s->failed_pc=0x0c075d02u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c075e14u,2);
goto P_0c075d04;
P_0c075d04: /* original 03fe, guest PC 0x0c075d04 */
if(!s->budget--) { s->failed_pc=0x0c075d04u; return 0; }
r[3]=read(ram,r[15]+r[0],4);
goto P_0c075d06;
P_0c075d06: /* original 9086, guest PC 0x0c075d06 */
if(!s->budget--) { s->failed_pc=0x0c075d06u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c075e16u,2);
goto P_0c075d08;
P_0c075d08: /* original 023c, guest PC 0x0c075d08 */
if(!s->budget--) { s->failed_pc=0x0c075d08u; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[3]+r[0],1);
goto P_0c075d0a;
P_0c075d0a: /* original e301, guest PC 0x0c075d0a */
if(!s->budget--) { s->failed_pc=0x0c075d0au; return 0; }
r[3]=0x00000001u;
goto P_0c075d0c;
P_0c075d0c: /* original 622c, guest PC 0x0c075d0c */
if(!s->budget--) { s->failed_pc=0x0c075d0cu; return 0; }
r[2]=r[2]&255u;
goto P_0c075d0e;
P_0c075d0e: /* original 3237, guest PC 0x0c075d0e */
if(!s->budget--) { s->failed_pc=0x0c075d0eu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>(int32_t)r[3])!=0);
goto P_0c075d10;
P_0c075d10: /* original 8b13, guest PC 0x0c075d10 */
if(!s->budget--) { s->failed_pc=0x0c075d10u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c075d3a; }
goto P_0c075d12;
P_0c075d12: /* original 9081, guest PC 0x0c075d12 */
if(!s->budget--) { s->failed_pc=0x0c075d12u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c075e18u,2);
goto P_0c075d14;
P_0c075d14: /* original 01fe, guest PC 0x0c075d14 */
if(!s->budget--) { s->failed_pc=0x0c075d14u; return 0; }
r[1]=read(ram,r[15]+r[0],4);
goto P_0c075d16;
P_0c075d16: /* original e03c, guest PC 0x0c075d16 */
if(!s->budget--) { s->failed_pc=0x0c075d16u; return 0; }
r[0]=0x0000003cu;
goto P_0c075d18;
P_0c075d18: /* original 021d, guest PC 0x0c075d18 */
if(!s->budget--) { s->failed_pc=0x0c075d18u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[1]+r[0],2);
goto P_0c075d1a;
P_0c075d1a: /* original 907e, guest PC 0x0c075d1a */
if(!s->budget--) { s->failed_pc=0x0c075d1au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c075e1au,2);
goto P_0c075d1c;
P_0c075d1c: /* original 622d, guest PC 0x0c075d1c */
if(!s->budget--) { s->failed_pc=0x0c075d1cu; return 0; }
r[2]=r[2]&65535u;
goto P_0c075d1e;
P_0c075d1e: /* original 011d, guest PC 0x0c075d1e */
if(!s->budget--) { s->failed_pc=0x0c075d1eu; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,r[1]+r[0],2);
goto P_0c075d20;
P_0c075d20: /* original 3210, guest PC 0x0c075d20 */
if(!s->budget--) { s->failed_pc=0x0c075d20u; return 0; }
r[17]=(r[17]&~1u)|((r[2]==r[1])!=0);
goto P_0c075d22;
P_0c075d22: /* original 8b0a, guest PC 0x0c075d22 */
if(!s->budget--) { s->failed_pc=0x0c075d22u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c075d3a; }
goto P_0c075d24;
P_0c075d24: /* original 9074, guest PC 0x0c075d24 */
if(!s->budget--) { s->failed_pc=0x0c075d24u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c075e10u,2);
goto P_0c075d26;
P_0c075d26: /* original 01fe, guest PC 0x0c075d26 */
if(!s->budget--) { s->failed_pc=0x0c075d26u; return 0; }
r[1]=read(ram,r[15]+r[0],4);
goto P_0c075d28;
P_0c075d28: /* original 9073, guest PC 0x0c075d28 */
if(!s->budget--) { s->failed_pc=0x0c075d28u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c075e12u,2);
goto P_0c075d2a;
P_0c075d2a: /* original 4121, guest PC 0x0c075d2a */
if(!s->budget--) { s->failed_pc=0x0c075d2au; return 0; }
r[17]=(r[17]&~1u)|((r[1]&1)!=0);
r[1]=(uint32_t)((int32_t)r[1]>>1);
goto P_0c075d2c;
P_0c075d2c: /* original 4121, guest PC 0x0c075d2c */
if(!s->budget--) { s->failed_pc=0x0c075d2cu; return 0; }
r[17]=(r[17]&~1u)|((r[1]&1)!=0);
r[1]=(uint32_t)((int32_t)r[1]>>1);
goto P_0c075d2e;
P_0c075d2e: /* original 0f16, guest PC 0x0c075d2e */
if(!s->budget--) { s->failed_pc=0x0c075d2eu; return 0; }
write(ram,r[15]+r[0],r[1],4);
goto P_0c075d30;
P_0c075d30: /* original 906e, guest PC 0x0c075d30 */
if(!s->budget--) { s->failed_pc=0x0c075d30u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c075e10u,2);
goto P_0c075d32;
P_0c075d32: /* original 02fe, guest PC 0x0c075d32 */
if(!s->budget--) { s->failed_pc=0x0c075d32u; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c075d34;
P_0c075d34: /* original 906c, guest PC 0x0c075d34 */
if(!s->budget--) { s->failed_pc=0x0c075d34u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c075e10u,2);
goto P_0c075d36;
P_0c075d36: /* original 3218, guest PC 0x0c075d36 */
if(!s->budget--) { s->failed_pc=0x0c075d36u; return 0; }
r[2]-=r[1];
goto P_0c075d38;
P_0c075d38: /* original 0f26, guest PC 0x0c075d38 */
if(!s->budget--) { s->failed_pc=0x0c075d38u; return 0; }
write(ram,r[15]+r[0],r[2],4);
goto P_0c075d3a;
P_0c075d3a: /* original 906d, guest PC 0x0c075d3a */
if(!s->budget--) { s->failed_pc=0x0c075d3au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c075e18u,2);
goto P_0c075d3c;
P_0c075d3c: /* original 03fe, guest PC 0x0c075d3c */
if(!s->budget--) { s->failed_pc=0x0c075d3cu; return 0; }
r[3]=read(ram,r[15]+r[0],4);
goto P_0c075d3e;
P_0c075d3e: /* original e03c, guest PC 0x0c075d3e */
if(!s->budget--) { s->failed_pc=0x0c075d3eu; return 0; }
r[0]=0x0000003cu;
goto P_0c075d40;
P_0c075d40: /* original 6233, guest PC 0x0c075d40 */
if(!s->budget--) { s->failed_pc=0x0c075d40u; return 0; }
r[2]=r[3];
goto P_0c075d42;
P_0c075d42: /* original 012d, guest PC 0x0c075d42 */
if(!s->budget--) { s->failed_pc=0x0c075d42u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,r[2]+r[0],2);
goto P_0c075d44;
P_0c075d44: /* original 9069, guest PC 0x0c075d44 */
if(!s->budget--) { s->failed_pc=0x0c075d44u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c075e1au,2);
goto P_0c075d46;
P_0c075d46: /* original 0315, guest PC 0x0c075d46 */
if(!s->budget--) { s->failed_pc=0x0c075d46u; return 0; }
write(ram,r[3]+r[0],r[1],2);
goto P_0c075d48;
P_0c075d48: /* original 9068, guest PC 0x0c075d48 */
if(!s->budget--) { s->failed_pc=0x0c075d48u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c075e1cu,2);
goto P_0c075d4a;
P_0c075d4a: /* original 03fe, guest PC 0x0c075d4a */
if(!s->budget--) { s->failed_pc=0x0c075d4au; return 0; }
r[3]=read(ram,r[15]+r[0],4);
goto P_0c075d4c;
P_0c075d4c: /* original 9060, guest PC 0x0c075d4c */
if(!s->budget--) { s->failed_pc=0x0c075d4cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c075e10u,2);
goto P_0c075d4e;
P_0c075d4e: /* original 02fe, guest PC 0x0c075d4e */
if(!s->budget--) { s->failed_pc=0x0c075d4eu; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c075d50;
P_0c075d50: /* original 905e, guest PC 0x0c075d50 */
if(!s->budget--) { s->failed_pc=0x0c075d50u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c075e10u,2);
goto P_0c075d52;
P_0c075d52: /* original 323c, guest PC 0x0c075d52 */
if(!s->budget--) { s->failed_pc=0x0c075d52u; return 0; }
r[2]+=r[3];
goto P_0c075d54;
P_0c075d54: /* original 0f26, guest PC 0x0c075d54 */
if(!s->budget--) { s->failed_pc=0x0c075d54u; return 0; }
write(ram,r[15]+r[0],r[2],4);
goto P_0c075d56;
P_0c075d56: /* original e054, guest PC 0x0c075d56 */
if(!s->budget--) { s->failed_pc=0x0c075d56u; return 0; }
r[0]=0x00000054u;
goto P_0c075d58;
P_0c075d58: /* original 01fe, guest PC 0x0c075d58 */
if(!s->budget--) { s->failed_pc=0x0c075d58u; return 0; }
r[1]=read(ram,r[15]+r[0],4);
goto P_0c075d5a;
P_0c075d5a: /* original e054, guest PC 0x0c075d5a */
if(!s->budget--) { s->failed_pc=0x0c075d5au; return 0; }
r[0]=0x00000054u;
goto P_0c075d5c;
P_0c075d5c: /* original 00fe, guest PC 0x0c075d5c */
if(!s->budget--) { s->failed_pc=0x0c075d5cu; return 0; }
r[0]=read(ram,r[15]+r[0],4);
goto P_0c075d5e;
P_0c075d5e: /* original 4101, guest PC 0x0c075d5e */
if(!s->budget--) { s->failed_pc=0x0c075d5eu; return 0; }
r[17]=(r[17]&~1u)|((r[1]&1)!=0);
r[1]>>=1;
goto P_0c075d60;
P_0c075d60: /* original 310c, guest PC 0x0c075d60 */
if(!s->budget--) { s->failed_pc=0x0c075d60u; return 0; }
r[1]+=r[0];
goto P_0c075d62;
P_0c075d62: /* original 905b, guest PC 0x0c075d62 */
if(!s->budget--) { s->failed_pc=0x0c075d62u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c075e1cu,2);
goto P_0c075d64;
P_0c075d64: /* original 3217, guest PC 0x0c075d64 */
if(!s->budget--) { s->failed_pc=0x0c075d64u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>(int32_t)r[1])!=0);
goto P_0c075d66;
P_0c075d66: /* original 8f02, guest PC 0x0c075d66 */
if(!s->budget--) { s->failed_pc=0x0c075d66u; return 0; }
cond=r[17]&1u;
write(ram,r[15]+r[0],r[1],4);
if(!cond) { goto P_0c075d6e; }
goto P_0c075d6a;
P_0c075d68: /* original 0f16, guest PC 0x0c075d68 */
if(!s->budget--) { s->failed_pc=0x0c075d68u; return 0; }
write(ram,r[15]+r[0],r[1],4);
goto P_0c075d6a;
P_0c075d6a: /* original 9051, guest PC 0x0c075d6a */
if(!s->budget--) { s->failed_pc=0x0c075d6au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c075e10u,2);
goto P_0c075d6c;
P_0c075d6c: /* original 0f16, guest PC 0x0c075d6c */
if(!s->budget--) { s->failed_pc=0x0c075d6cu; return 0; }
write(ram,r[15]+r[0],r[1],4);
goto P_0c075d6e;
P_0c075d6e: /* original 904f, guest PC 0x0c075d6e */
if(!s->budget--) { s->failed_pc=0x0c075d6eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c075e10u,2);
goto P_0c075d70;
P_0c075d70: /* original 03fe, guest PC 0x0c075d70 */
if(!s->budget--) { s->failed_pc=0x0c075d70u; return 0; }
r[3]=read(ram,r[15]+r[0],4);
goto P_0c075d72;
P_0c075d72: /* original e054, guest PC 0x0c075d72 */
if(!s->budget--) { s->failed_pc=0x0c075d72u; return 0; }
r[0]=0x00000054u;
goto P_0c075d74;
P_0c075d74: /* original 0f36, guest PC 0x0c075d74 */
if(!s->budget--) { s->failed_pc=0x0c075d74u; return 0; }
write(ram,r[15]+r[0],r[3],4);
goto P_0c075d76;
P_0c075d76: /* original 904f, guest PC 0x0c075d76 */
if(!s->budget--) { s->failed_pc=0x0c075d76u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c075e18u,2);
goto P_0c075d78;
P_0c075d78: /* original 02fe, guest PC 0x0c075d78 */
if(!s->budget--) { s->failed_pc=0x0c075d78u; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c075d7a;
P_0c075d7a: /* original e04c, guest PC 0x0c075d7a */
if(!s->budget--) { s->failed_pc=0x0c075d7au; return 0; }
r[0]=0x0000004cu;
goto P_0c075d7c;
P_0c075d7c: /* original 03fe, guest PC 0x0c075d7c */
if(!s->budget--) { s->failed_pc=0x0c075d7cu; return 0; }
r[3]=read(ram,r[15]+r[0],4);
goto P_0c075d7e;
P_0c075d7e: /* original 904e, guest PC 0x0c075d7e */
if(!s->budget--) { s->failed_pc=0x0c075d7eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c075e1eu,2);
goto P_0c075d80;
P_0c075d80: /* original 0236, guest PC 0x0c075d80 */
if(!s->budget--) { s->failed_pc=0x0c075d80u; return 0; }
write(ram,r[2]+r[0],r[3],4);
goto P_0c075d82;
P_0c075d82: /* original 9049, guest PC 0x0c075d82 */
if(!s->budget--) { s->failed_pc=0x0c075d82u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c075e18u,2);
goto P_0c075d84;
P_0c075d84: /* original 02fe, guest PC 0x0c075d84 */
if(!s->budget--) { s->failed_pc=0x0c075d84u; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c075d86;
P_0c075d86: /* original 904b, guest PC 0x0c075d86 */
if(!s->budget--) { s->failed_pc=0x0c075d86u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c075e20u,2);
goto P_0c075d88;
P_0c075d88: /* original 032d, guest PC 0x0c075d88 */
if(!s->budget--) { s->failed_pc=0x0c075d88u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[2]+r[0],2);
goto P_0c075d8a;
P_0c075d8a: /* original 4315, guest PC 0x0c075d8a */
if(!s->budget--) { s->failed_pc=0x0c075d8au; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>0)!=0);
goto P_0c075d8c;
P_0c075d8c: /* original 8b0c, guest PC 0x0c075d8c */
if(!s->budget--) { s->failed_pc=0x0c075d8cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c075da8; }
goto P_0c075d8e;
P_0c075d8e: /* original 9041, guest PC 0x0c075d8e */
if(!s->budget--) { s->failed_pc=0x0c075d8eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c075e14u,2);
goto P_0c075d90;
P_0c075d90: /* original 02fe, guest PC 0x0c075d90 */
if(!s->budget--) { s->failed_pc=0x0c075d90u; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c075d92;
P_0c075d92: /* original 9040, guest PC 0x0c075d92 */
if(!s->budget--) { s->failed_pc=0x0c075d92u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c075e16u,2);
goto P_0c075d94;
P_0c075d94: /* original 032c, guest PC 0x0c075d94 */
if(!s->budget--) { s->failed_pc=0x0c075d94u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[2]+r[0],1);
goto P_0c075d96;
P_0c075d96: /* original e201, guest PC 0x0c075d96 */
if(!s->budget--) { s->failed_pc=0x0c075d96u; return 0; }
r[2]=0x00000001u;
goto P_0c075d98;
P_0c075d98: /* original 633c, guest PC 0x0c075d98 */
if(!s->budget--) { s->failed_pc=0x0c075d98u; return 0; }
r[3]=r[3]&255u;
goto P_0c075d9a;
P_0c075d9a: /* original 3327, guest PC 0x0c075d9a */
if(!s->budget--) { s->failed_pc=0x0c075d9au; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>(int32_t)r[2])!=0);
goto P_0c075d9c;
P_0c075d9c: /* original 8b04, guest PC 0x0c075d9c */
if(!s->budget--) { s->failed_pc=0x0c075d9cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c075da8; }
goto P_0c075d9e;
P_0c075d9e: /* original e054, guest PC 0x0c075d9e */
if(!s->budget--) { s->failed_pc=0x0c075d9eu; return 0; }
r[0]=0x00000054u;
goto P_0c075da0;
P_0c075da0: /* original 01fe, guest PC 0x0c075da0 */
if(!s->budget--) { s->failed_pc=0x0c075da0u; return 0; }
r[1]=read(ram,r[15]+r[0],4);
goto P_0c075da2;
P_0c075da2: /* original e054, guest PC 0x0c075da2 */
if(!s->budget--) { s->failed_pc=0x0c075da2u; return 0; }
r[0]=0x00000054u;
goto P_0c075da4;
P_0c075da4: /* original 4101, guest PC 0x0c075da4 */
if(!s->budget--) { s->failed_pc=0x0c075da4u; return 0; }
r[17]=(r[17]&~1u)|((r[1]&1)!=0);
r[1]>>=1;
goto P_0c075da6;
P_0c075da6: /* original 0f16, guest PC 0x0c075da6 */
if(!s->budget--) { s->failed_pc=0x0c075da6u; return 0; }
write(ram,r[15]+r[0],r[1],4);
goto P_0c075da8;
P_0c075da8: /* original 9034, guest PC 0x0c075da8 */
if(!s->budget--) { s->failed_pc=0x0c075da8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c075e14u,2);
goto P_0c075daa;
P_0c075daa: /* original 03fe, guest PC 0x0c075daa */
if(!s->budget--) { s->failed_pc=0x0c075daau; return 0; }
r[3]=read(ram,r[15]+r[0],4);
goto P_0c075dac;
P_0c075dac: /* original e054, guest PC 0x0c075dac */
if(!s->budget--) { s->failed_pc=0x0c075dacu; return 0; }
r[0]=0x00000054u;
goto P_0c075dae;
P_0c075dae: /* original 02fd, guest PC 0x0c075dae */
if(!s->budget--) { s->failed_pc=0x0c075daeu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+r[0],2);
goto P_0c075db0;
P_0c075db0: /* original 9037, guest PC 0x0c075db0 */
if(!s->budget--) { s->failed_pc=0x0c075db0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c075e22u,2);
goto P_0c075db2;
P_0c075db2: /* original 0325, guest PC 0x0c075db2 */
if(!s->budget--) { s->failed_pc=0x0c075db2u; return 0; }
write(ram,r[3]+r[0],r[2],2);
goto P_0c075db4;
P_0c075db4: /* original e054, guest PC 0x0c075db4 */
if(!s->budget--) { s->failed_pc=0x0c075db4u; return 0; }
r[0]=0x00000054u;
goto P_0c075db6;
P_0c075db6: /* original 03fe, guest PC 0x0c075db6 */
if(!s->budget--) { s->failed_pc=0x0c075db6u; return 0; }
r[3]=read(ram,r[15]+r[0],4);
goto P_0c075db8;
P_0c075db8: /* original 2338, guest PC 0x0c075db8 */
if(!s->budget--) { s->failed_pc=0x0c075db8u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c075dba;
P_0c075dba: /* original 8b01, guest PC 0x0c075dba */
if(!s->budget--) { s->failed_pc=0x0c075dbau; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c075dc0; }
goto P_0c075dbc;
P_0c075dbc: /* original a185, guest PC 0x0c075dbc */
if(!s->budget--) { s->failed_pc=0x0c075dbcu; return 0; }
goto P_0c0760ca;
P_0c075dbe: /* original 0009, guest PC 0x0c075dbe */
if(!s->budget--) { s->failed_pc=0x0c075dbeu; return 0; }
goto P_0c075dc0;
P_0c075dc0: /* original 902a, guest PC 0x0c075dc0 */
if(!s->budget--) { s->failed_pc=0x0c075dc0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c075e18u,2);
goto P_0c075dc2;
P_0c075dc2: /* original 922f, guest PC 0x0c075dc2 */
if(!s->budget--) { s->failed_pc=0x0c075dc2u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c075e24u,2);
goto P_0c075dc4;
P_0c075dc4: /* original 03fe, guest PC 0x0c075dc4 */
if(!s->budget--) { s->failed_pc=0x0c075dc4u; return 0; }
r[3]=read(ram,r[15]+r[0],4);
goto P_0c075dc6;
P_0c075dc6: /* original e048, guest PC 0x0c075dc6 */
if(!s->budget--) { s->failed_pc=0x0c075dc6u; return 0; }
r[0]=0x00000048u;
goto P_0c075dc8;
P_0c075dc8: /* original 013e, guest PC 0x0c075dc8 */
if(!s->budget--) { s->failed_pc=0x0c075dc8u; return 0; }
r[1]=read(ram,r[3]+r[0],4);
goto P_0c075dca;
P_0c075dca: /* original 2128, guest PC 0x0c075dca */
if(!s->budget--) { s->failed_pc=0x0c075dcau; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[2])==0)!=0);
goto P_0c075dcc;
P_0c075dcc: /* original 8901, guest PC 0x0c075dcc */
if(!s->budget--) { s->failed_pc=0x0c075dccu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c075dd2; }
goto P_0c075dce;
P_0c075dce: /* original a17c, guest PC 0x0c075dce */
if(!s->budget--) { s->failed_pc=0x0c075dceu; return 0; }
goto P_0c0760ca;
P_0c075dd0: /* original 0009, guest PC 0x0c075dd0 */
if(!s->budget--) { s->failed_pc=0x0c075dd0u; return 0; }
goto P_0c075dd2;
P_0c075dd2: /* original 9021, guest PC 0x0c075dd2 */
if(!s->budget--) { s->failed_pc=0x0c075dd2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c075e18u,2);
goto P_0c075dd4;
P_0c075dd4: /* original 03fe, guest PC 0x0c075dd4 */
if(!s->budget--) { s->failed_pc=0x0c075dd4u; return 0; }
r[3]=read(ram,r[15]+r[0],4);
goto P_0c075dd6;
P_0c075dd6: /* original 9026, guest PC 0x0c075dd6 */
if(!s->budget--) { s->failed_pc=0x0c075dd6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c075e26u,2);
goto P_0c075dd8;
P_0c075dd8: /* original 023c, guest PC 0x0c075dd8 */
if(!s->budget--) { s->failed_pc=0x0c075dd8u; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[3]+r[0],1);
goto P_0c075dda;
P_0c075dda: /* original 901a, guest PC 0x0c075dda */
if(!s->budget--) { s->failed_pc=0x0c075ddau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c075e12u,2);
goto P_0c075ddc;
P_0c075ddc: /* original 622c, guest PC 0x0c075ddc */
if(!s->budget--) { s->failed_pc=0x0c075ddcu; return 0; }
r[2]=r[2]&255u;
goto P_0c075dde;
P_0c075dde: /* original 2228, guest PC 0x0c075dde */
if(!s->budget--) { s->failed_pc=0x0c075ddeu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c075de0;
P_0c075de0: /* original 8d64, guest PC 0x0c075de0 */
if(!s->budget--) { s->failed_pc=0x0c075de0u; return 0; }
cond=r[17]&1u;
write(ram,r[15]+r[0],r[2],4);
if(cond) { goto P_0c075eac; }
goto P_0c075de4;
P_0c075de2: /* original 0f26, guest PC 0x0c075de2 */
if(!s->budget--) { s->failed_pc=0x0c075de2u; return 0; }
write(ram,r[15]+r[0],r[2],4);
goto P_0c075de4;
P_0c075de4: /* original 6023, guest PC 0x0c075de4 */
if(!s->budget--) { s->failed_pc=0x0c075de4u; return 0; }
r[0]=r[2];
goto P_0c075de6;
P_0c075de6: /* original 8831, guest PC 0x0c075de6 */
if(!s->budget--) { s->failed_pc=0x0c075de6u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000031u)!=0);
goto P_0c075de8;
P_0c075de8: /* original 8908, guest PC 0x0c075de8 */
if(!s->budget--) { s->failed_pc=0x0c075de8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c075dfc; }
goto P_0c075dea;
P_0c075dea: /* original 6023, guest PC 0x0c075dea */
if(!s->budget--) { s->failed_pc=0x0c075deau; return 0; }
r[0]=r[2];
goto P_0c075dec;
P_0c075dec: /* original 8835, guest PC 0x0c075dec */
if(!s->budget--) { s->failed_pc=0x0c075decu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000035u)!=0);
goto P_0c075dee;
P_0c075dee: /* original 8905, guest PC 0x0c075dee */
if(!s->budget--) { s->failed_pc=0x0c075deeu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c075dfc; }
goto P_0c075df0;
P_0c075df0: /* original 6023, guest PC 0x0c075df0 */
if(!s->budget--) { s->failed_pc=0x0c075df0u; return 0; }
r[0]=r[2];
goto P_0c075df2;
P_0c075df2: /* original 8839, guest PC 0x0c075df2 */
if(!s->budget--) { s->failed_pc=0x0c075df2u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000039u)!=0);
goto P_0c075df4;
P_0c075df4: /* original 8902, guest PC 0x0c075df4 */
if(!s->budget--) { s->failed_pc=0x0c075df4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c075dfc; }
goto P_0c075df6;
P_0c075df6: /* original 6023, guest PC 0x0c075df6 */
if(!s->budget--) { s->failed_pc=0x0c075df6u; return 0; }
r[0]=r[2];
goto P_0c075df8;
P_0c075df8: /* original 882d, guest PC 0x0c075df8 */
if(!s->budget--) { s->failed_pc=0x0c075df8u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000002du)!=0);
goto P_0c075dfa;
P_0c075dfa: /* original 8b1c, guest PC 0x0c075dfa */
if(!s->budget--) { s->failed_pc=0x0c075dfau; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c075e36; }
goto P_0c075dfc;
P_0c075dfc: /* original e054, guest PC 0x0c075dfc */
if(!s->budget--) { s->failed_pc=0x0c075dfcu; return 0; }
r[0]=0x00000054u;
goto P_0c075dfe;
P_0c075dfe: /* original 03fe, guest PC 0x0c075dfe */
if(!s->budget--) { s->failed_pc=0x0c075dfeu; return 0; }
r[3]=read(ram,r[15]+r[0],4);
goto P_0c075e00;
P_0c075e00: /* original e223, guest PC 0x0c075e00 */
if(!s->budget--) { s->failed_pc=0x0c075e00u; return 0; }
r[2]=0x00000023u;
goto P_0c075e02;
P_0c075e02: /* original 3322, guest PC 0x0c075e02 */
if(!s->budget--) { s->failed_pc=0x0c075e02u; return 0; }
r[17]=(r[17]&~1u)|((r[3]>=r[2])!=0);
goto P_0c075e04;
P_0c075e04: /* original 8b17, guest PC 0x0c075e04 */
if(!s->budget--) { s->failed_pc=0x0c075e04u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c075e36; }
goto P_0c075e06;
P_0c075e06: /* original d308, guest PC 0x0c075e06 */
if(!s->budget--) { s->failed_pc=0x0c075e06u; return 0; }
r[3]=read(ram,0x0c075e28u,4);
goto P_0c075e08;
P_0c075e08: /* original 430b, guest PC 0x0c075e08 */
if(!s->budget--) { s->failed_pc=0x0c075e08u; return 0; }
target=r[3];
r[16]=0x0c075e0cu;
r[4]=0x0000003cu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c075e0cu) { target=s->pc; goto dispatch; }
goto P_0c075e0c;
P_0c075e0a: /* original e43c, guest PC 0x0c075e0a */
if(!s->budget--) { s->failed_pc=0x0c075e0au; return 0; }
r[4]=0x0000003cu;
goto P_0c075e0c;
P_0c075e0c: /* original a00e, guest PC 0x0c075e0c */
if(!s->budget--) { s->failed_pc=0x0c075e0cu; return 0; }
r[4]=0x0000003cu;
goto P_0c075e2c;
P_0c075e0e: /* original e43c, guest PC 0x0c075e0e */
if(!s->budget--) { s->failed_pc=0x0c075e0eu; return 0; }
r[4]=0x0000003cu;
return vf3_matrix_family(0x0c075e10u,s,ram);
P_0c075e2c: /* original d23c, guest PC 0x0c075e2c */
if(!s->budget--) { s->failed_pc=0x0c075e2cu; return 0; }
r[2]=read(ram,0x0c075f20u,4);
goto P_0c075e2e;
P_0c075e2e: /* original 420b, guest PC 0x0c075e2e */
if(!s->budget--) { s->failed_pc=0x0c075e2eu; return 0; }
target=r[2];
r[16]=0x0c075e32u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c075e32u) { target=s->pc; goto dispatch; }
goto P_0c075e32;
P_0c075e30: /* original 0009, guest PC 0x0c075e30 */
if(!s->budget--) { s->failed_pc=0x0c075e30u; return 0; }
goto P_0c075e32;
P_0c075e32: /* original a14a, guest PC 0x0c075e32 */
if(!s->budget--) { s->failed_pc=0x0c075e32u; return 0; }
goto P_0c0760ca;
P_0c075e34: /* original 0009, guest PC 0x0c075e34 */
if(!s->budget--) { s->failed_pc=0x0c075e34u; return 0; }
goto P_0c075e36;
P_0c075e36: /* original 906b, guest PC 0x0c075e36 */
if(!s->budget--) { s->failed_pc=0x0c075e36u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c075f10u,2);
goto P_0c075e38;
P_0c075e38: /* original 02fe, guest PC 0x0c075e38 */
if(!s->budget--) { s->failed_pc=0x0c075e38u; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c075e3a;
P_0c075e3a: /* original 9069, guest PC 0x0c075e3a */
if(!s->budget--) { s->failed_pc=0x0c075e3au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c075f10u,2);
goto P_0c075e3c;
P_0c075e3c: /* original 72ff, guest PC 0x0c075e3c */
if(!s->budget--) { s->failed_pc=0x0c075e3cu; return 0; }
r[2]+=0xffffffffu;
goto P_0c075e3e;
P_0c075e3e: /* original 0f26, guest PC 0x0c075e3e */
if(!s->budget--) { s->failed_pc=0x0c075e3eu; return 0; }
write(ram,r[15]+r[0],r[2],4);
goto P_0c075e40;
P_0c075e40: /* original 4209, guest PC 0x0c075e40 */
if(!s->budget--) { s->failed_pc=0x0c075e40u; return 0; }
r[2]>>=2;
goto P_0c075e42;
P_0c075e42: /* original d038, guest PC 0x0c075e42 */
if(!s->budget--) { s->failed_pc=0x0c075e42u; return 0; }
r[0]=read(ram,0x0c075f24u,4);
goto P_0c075e44;
P_0c075e44: /* original 4208, guest PC 0x0c075e44 */
if(!s->budget--) { s->failed_pc=0x0c075e44u; return 0; }
r[2]<<=2;
goto P_0c075e46;
P_0c075e46: /* original 032e, guest PC 0x0c075e46 */
if(!s->budget--) { s->failed_pc=0x0c075e46u; return 0; }
r[3]=read(ram,r[2]+r[0],4);
goto P_0c075e48;
P_0c075e48: /* original e040, guest PC 0x0c075e48 */
if(!s->budget--) { s->failed_pc=0x0c075e48u; return 0; }
r[0]=0x00000040u;
goto P_0c075e4a;
P_0c075e4a: /* original 73fc, guest PC 0x0c075e4a */
if(!s->budget--) { s->failed_pc=0x0c075e4au; return 0; }
r[3]+=0xfffffffcu;
goto P_0c075e4c;
P_0c075e4c: /* original 0f36, guest PC 0x0c075e4c */
if(!s->budget--) { s->failed_pc=0x0c075e4cu; return 0; }
write(ram,r[15]+r[0],r[3],4);
goto P_0c075e4e;
P_0c075e4e: /* original e040, guest PC 0x0c075e4e */
if(!s->budget--) { s->failed_pc=0x0c075e4eu; return 0; }
r[0]=0x00000040u;
goto P_0c075e50;
P_0c075e50: /* original 01fe, guest PC 0x0c075e50 */
if(!s->budget--) { s->failed_pc=0x0c075e50u; return 0; }
r[1]=read(ram,r[15]+r[0],4);
goto P_0c075e52;
P_0c075e52: /* original e040, guest PC 0x0c075e52 */
if(!s->budget--) { s->failed_pc=0x0c075e52u; return 0; }
r[0]=0x00000040u;
goto P_0c075e54;
P_0c075e54: /* original 7104, guest PC 0x0c075e54 */
if(!s->budget--) { s->failed_pc=0x0c075e54u; return 0; }
r[1]+=0x00000004u;
goto P_0c075e56;
P_0c075e56: /* original 0f16, guest PC 0x0c075e56 */
if(!s->budget--) { s->failed_pc=0x0c075e56u; return 0; }
write(ram,r[15]+r[0],r[1],4);
goto P_0c075e58;
P_0c075e58: /* original 6312, guest PC 0x0c075e58 */
if(!s->budget--) { s->failed_pc=0x0c075e58u; return 0; }
tmp=read(ram,r[1],4);
r[3]=tmp;
goto P_0c075e5a;
P_0c075e5a: /* original 9059, guest PC 0x0c075e5a */
if(!s->budget--) { s->failed_pc=0x0c075e5au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c075f10u,2);
goto P_0c075e5c;
P_0c075e5c: /* original 6233, guest PC 0x0c075e5c */
if(!s->budget--) { s->failed_pc=0x0c075e5cu; return 0; }
r[2]=r[3];
goto P_0c075e5e;
P_0c075e5e: /* original 2228, guest PC 0x0c075e5e */
if(!s->budget--) { s->failed_pc=0x0c075e5eu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c075e60;
P_0c075e60: /* original 8d0a, guest PC 0x0c075e60 */
if(!s->budget--) { s->failed_pc=0x0c075e60u; return 0; }
cond=r[17]&1u;
write(ram,r[15]+r[0],r[3],4);
if(cond) { goto P_0c075e78; }
goto P_0c075e64;
P_0c075e62: /* original 0f36, guest PC 0x0c075e62 */
if(!s->budget--) { s->failed_pc=0x0c075e62u; return 0; }
write(ram,r[15]+r[0],r[3],4);
goto P_0c075e64;
P_0c075e64: /* original d330, guest PC 0x0c075e64 */
if(!s->budget--) { s->failed_pc=0x0c075e64u; return 0; }
r[3]=read(ram,0x0c075f28u,4);
goto P_0c075e66;
P_0c075e66: /* original 9053, guest PC 0x0c075e66 */
if(!s->budget--) { s->failed_pc=0x0c075e66u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c075f10u,2);
goto P_0c075e68;
P_0c075e68: /* original 430b, guest PC 0x0c075e68 */
if(!s->budget--) { s->failed_pc=0x0c075e68u; return 0; }
target=r[3];
r[16]=0x0c075e6cu;
r[4]=read(ram,r[15]+r[0],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c075e6cu) { target=s->pc; goto dispatch; }
goto P_0c075e6c;
P_0c075e6a: /* original 04fe, guest PC 0x0c075e6a */
if(!s->budget--) { s->failed_pc=0x0c075e6au; return 0; }
r[4]=read(ram,r[15]+r[0],4);
goto P_0c075e6c;
P_0c075e6c: /* original d32c, guest PC 0x0c075e6c */
if(!s->budget--) { s->failed_pc=0x0c075e6cu; return 0; }
r[3]=read(ram,0x0c075f20u,4);
goto P_0c075e6e;
P_0c075e6e: /* original 904f, guest PC 0x0c075e6e */
if(!s->budget--) { s->failed_pc=0x0c075e6eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c075f10u,2);
goto P_0c075e70;
P_0c075e70: /* original 430b, guest PC 0x0c075e70 */
if(!s->budget--) { s->failed_pc=0x0c075e70u; return 0; }
target=r[3];
r[16]=0x0c075e74u;
r[4]=read(ram,r[15]+r[0],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c075e74u) { target=s->pc; goto dispatch; }
goto P_0c075e74;
P_0c075e72: /* original 04fe, guest PC 0x0c075e72 */
if(!s->budget--) { s->failed_pc=0x0c075e72u; return 0; }
r[4]=read(ram,r[15]+r[0],4);
goto P_0c075e74;
P_0c075e74: /* original afeb, guest PC 0x0c075e74 */
if(!s->budget--) { s->failed_pc=0x0c075e74u; return 0; }
goto P_0c075e4e;
P_0c075e76: /* original 0009, guest PC 0x0c075e76 */
if(!s->budget--) { s->failed_pc=0x0c075e76u; return 0; }
goto P_0c075e78;
P_0c075e78: /* original 904b, guest PC 0x0c075e78 */
if(!s->budget--) { s->failed_pc=0x0c075e78u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c075f12u,2);
goto P_0c075e7a;
P_0c075e7a: /* original 03fe, guest PC 0x0c075e7a */
if(!s->budget--) { s->failed_pc=0x0c075e7au; return 0; }
r[3]=read(ram,r[15]+r[0],4);
goto P_0c075e7c;
P_0c075e7c: /* original 904a, guest PC 0x0c075e7c */
if(!s->budget--) { s->failed_pc=0x0c075e7cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c075f14u,2);
goto P_0c075e7e;
P_0c075e7e: /* original 023c, guest PC 0x0c075e7e */
if(!s->budget--) { s->failed_pc=0x0c075e7eu; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[3]+r[0],1);
goto P_0c075e80;
P_0c075e80: /* original e017, guest PC 0x0c075e80 */
if(!s->budget--) { s->failed_pc=0x0c075e80u; return 0; }
r[0]=0x00000017u;
goto P_0c075e82;
P_0c075e82: /* original 0f24, guest PC 0x0c075e82 */
if(!s->budget--) { s->failed_pc=0x0c075e82u; return 0; }
write(ram,r[15]+r[0],r[2],1);
goto P_0c075e84;
P_0c075e84: /* original 9047, guest PC 0x0c075e84 */
if(!s->budget--) { s->failed_pc=0x0c075e84u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c075f16u,2);
goto P_0c075e86;
P_0c075e86: /* original 03fe, guest PC 0x0c075e86 */
if(!s->budget--) { s->failed_pc=0x0c075e86u; return 0; }
r[3]=read(ram,r[15]+r[0],4);
goto P_0c075e88;
P_0c075e88: /* original e061, guest PC 0x0c075e88 */
if(!s->budget--) { s->failed_pc=0x0c075e88u; return 0; }
r[0]=0x00000061u;
goto P_0c075e8a;
P_0c075e8a: /* original 023c, guest PC 0x0c075e8a */
if(!s->budget--) { s->failed_pc=0x0c075e8au; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[3]+r[0],1);
goto P_0c075e8c;
P_0c075e8c: /* original e016, guest PC 0x0c075e8c */
if(!s->budget--) { s->failed_pc=0x0c075e8cu; return 0; }
r[0]=0x00000016u;
goto P_0c075e8e;
P_0c075e8e: /* original 0f24, guest PC 0x0c075e8e */
if(!s->budget--) { s->failed_pc=0x0c075e8eu; return 0; }
write(ram,r[15]+r[0],r[2],1);
goto P_0c075e90;
P_0c075e90: /* original e017, guest PC 0x0c075e90 */
if(!s->budget--) { s->failed_pc=0x0c075e90u; return 0; }
r[0]=0x00000017u;
goto P_0c075e92;
P_0c075e92: /* original 00fc, guest PC 0x0c075e92 */
if(!s->budget--) { s->failed_pc=0x0c075e92u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[15]+r[0],1);
goto P_0c075e94;
P_0c075e94: /* original 600c, guest PC 0x0c075e94 */
if(!s->budget--) { s->failed_pc=0x0c075e94u; return 0; }
r[0]=r[0]&255u;
goto P_0c075e96;
P_0c075e96: /* original 8804, guest PC 0x0c075e96 */
if(!s->budget--) { s->failed_pc=0x0c075e96u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000004u)!=0);
goto P_0c075e98;
P_0c075e98: /* original 8901, guest PC 0x0c075e98 */
if(!s->budget--) { s->failed_pc=0x0c075e98u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c075e9e; }
goto P_0c075e9a;
P_0c075e9a: /* original a0e8, guest PC 0x0c075e9a */
if(!s->budget--) { s->failed_pc=0x0c075e9au; return 0; }
goto P_0c07606e;
P_0c075e9c: /* original 0009, guest PC 0x0c075e9c */
if(!s->budget--) { s->failed_pc=0x0c075e9cu; return 0; }
goto P_0c075e9e;
P_0c075e9e: /* original e016, guest PC 0x0c075e9e */
if(!s->budget--) { s->failed_pc=0x0c075e9eu; return 0; }
r[0]=0x00000016u;
goto P_0c075ea0;
P_0c075ea0: /* original 00fc, guest PC 0x0c075ea0 */
if(!s->budget--) { s->failed_pc=0x0c075ea0u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[15]+r[0],1);
goto P_0c075ea2;
P_0c075ea2: /* original 600c, guest PC 0x0c075ea2 */
if(!s->budget--) { s->failed_pc=0x0c075ea2u; return 0; }
r[0]=r[0]&255u;
goto P_0c075ea4;
P_0c075ea4: /* original 8809, guest PC 0x0c075ea4 */
if(!s->budget--) { s->failed_pc=0x0c075ea4u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000009u)!=0);
goto P_0c075ea6;
P_0c075ea6: /* original 8b01, guest PC 0x0c075ea6 */
if(!s->budget--) { s->failed_pc=0x0c075ea6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c075eac; }
goto P_0c075ea8;
P_0c075ea8: /* original a0e8, guest PC 0x0c075ea8 */
if(!s->budget--) { s->failed_pc=0x0c075ea8u; return 0; }
goto P_0c07607c;
P_0c075eaa: /* original 0009, guest PC 0x0c075eaa */
if(!s->budget--) { s->failed_pc=0x0c075eaau; return 0; }
goto P_0c075eac;
P_0c075eac: /* original e078, guest PC 0x0c075eac */
if(!s->budget--) { s->failed_pc=0x0c075eacu; return 0; }
r[0]=0x00000078u;
goto P_0c075eae;
P_0c075eae: /* original e300, guest PC 0x0c075eae */
if(!s->budget--) { s->failed_pc=0x0c075eaeu; return 0; }
r[3]=0x00000000u;
goto P_0c075eb0;
P_0c075eb0: /* original 0f36, guest PC 0x0c075eb0 */
if(!s->budget--) { s->failed_pc=0x0c075eb0u; return 0; }
write(ram,r[15]+r[0],r[3],4);
goto P_0c075eb2;
P_0c075eb2: /* original e054, guest PC 0x0c075eb2 */
if(!s->budget--) { s->failed_pc=0x0c075eb2u; return 0; }
r[0]=0x00000054u;
goto P_0c075eb4;
P_0c075eb4: /* original 01fe, guest PC 0x0c075eb4 */
if(!s->budget--) { s->failed_pc=0x0c075eb4u; return 0; }
r[1]=read(ram,r[15]+r[0],4);
goto P_0c075eb6;
P_0c075eb6: /* original e214, guest PC 0x0c075eb6 */
if(!s->budget--) { s->failed_pc=0x0c075eb6u; return 0; }
r[2]=0x00000014u;
goto P_0c075eb8;
P_0c075eb8: /* original 3122, guest PC 0x0c075eb8 */
if(!s->budget--) { s->failed_pc=0x0c075eb8u; return 0; }
r[17]=(r[17]&~1u)|((r[1]>=r[2])!=0);
goto P_0c075eba;
P_0c075eba: /* original 8b0e, guest PC 0x0c075eba */
if(!s->budget--) { s->failed_pc=0x0c075ebau; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c075eda; }
goto P_0c075ebc;
P_0c075ebc: /* original e078, guest PC 0x0c075ebc */
if(!s->budget--) { s->failed_pc=0x0c075ebcu; return 0; }
r[0]=0x00000078u;
goto P_0c075ebe;
P_0c075ebe: /* original 03fe, guest PC 0x0c075ebe */
if(!s->budget--) { s->failed_pc=0x0c075ebeu; return 0; }
r[3]=read(ram,r[15]+r[0],4);
goto P_0c075ec0;
P_0c075ec0: /* original e078, guest PC 0x0c075ec0 */
if(!s->budget--) { s->failed_pc=0x0c075ec0u; return 0; }
r[0]=0x00000078u;
goto P_0c075ec2;
P_0c075ec2: /* original e123, guest PC 0x0c075ec2 */
if(!s->budget--) { s->failed_pc=0x0c075ec2u; return 0; }
r[1]=0x00000023u;
goto P_0c075ec4;
P_0c075ec4: /* original 7301, guest PC 0x0c075ec4 */
if(!s->budget--) { s->failed_pc=0x0c075ec4u; return 0; }
r[3]+=0x00000001u;
goto P_0c075ec6;
P_0c075ec6: /* original 0f36, guest PC 0x0c075ec6 */
if(!s->budget--) { s->failed_pc=0x0c075ec6u; return 0; }
write(ram,r[15]+r[0],r[3],4);
goto P_0c075ec8;
P_0c075ec8: /* original e054, guest PC 0x0c075ec8 */
if(!s->budget--) { s->failed_pc=0x0c075ec8u; return 0; }
r[0]=0x00000054u;
goto P_0c075eca;
P_0c075eca: /* original 00fe, guest PC 0x0c075eca */
if(!s->budget--) { s->failed_pc=0x0c075ecau; return 0; }
r[0]=read(ram,r[15]+r[0],4);
goto P_0c075ecc;
P_0c075ecc: /* original 3012, guest PC 0x0c075ecc */
if(!s->budget--) { s->failed_pc=0x0c075eccu; return 0; }
r[17]=(r[17]&~1u)|((r[0]>=r[1])!=0);
goto P_0c075ece;
P_0c075ece: /* original 8b04, guest PC 0x0c075ece */
if(!s->budget--) { s->failed_pc=0x0c075eceu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c075eda; }
goto P_0c075ed0;
P_0c075ed0: /* original e078, guest PC 0x0c075ed0 */
if(!s->budget--) { s->failed_pc=0x0c075ed0u; return 0; }
r[0]=0x00000078u;
goto P_0c075ed2;
P_0c075ed2: /* original 02fe, guest PC 0x0c075ed2 */
if(!s->budget--) { s->failed_pc=0x0c075ed2u; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c075ed4;
P_0c075ed4: /* original e078, guest PC 0x0c075ed4 */
if(!s->budget--) { s->failed_pc=0x0c075ed4u; return 0; }
r[0]=0x00000078u;
goto P_0c075ed6;
P_0c075ed6: /* original 7201, guest PC 0x0c075ed6 */
if(!s->budget--) { s->failed_pc=0x0c075ed6u; return 0; }
r[2]+=0x00000001u;
goto P_0c075ed8;
P_0c075ed8: /* original 0f26, guest PC 0x0c075ed8 */
if(!s->budget--) { s->failed_pc=0x0c075ed8u; return 0; }
write(ram,r[15]+r[0],r[2],4);
goto P_0c075eda;
P_0c075eda: /* original 901a, guest PC 0x0c075eda */
if(!s->budget--) { s->failed_pc=0x0c075edau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c075f12u,2);
goto P_0c075edc;
P_0c075edc: /* original 03fe, guest PC 0x0c075edc */
if(!s->budget--) { s->failed_pc=0x0c075edcu; return 0; }
r[3]=read(ram,r[15]+r[0],4);
goto P_0c075ede;
P_0c075ede: /* original e060, guest PC 0x0c075ede */
if(!s->budget--) { s->failed_pc=0x0c075edeu; return 0; }
r[0]=0x00000060u;
goto P_0c075ee0;
P_0c075ee0: /* original 023c, guest PC 0x0c075ee0 */
if(!s->budget--) { s->failed_pc=0x0c075ee0u; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[3]+r[0],1);
goto P_0c075ee2;
P_0c075ee2: /* original e300, guest PC 0x0c075ee2 */
if(!s->budget--) { s->failed_pc=0x0c075ee2u; return 0; }
r[3]=0x00000000u;
goto P_0c075ee4;
P_0c075ee4: /* original 9018, guest PC 0x0c075ee4 */
if(!s->budget--) { s->failed_pc=0x0c075ee4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c075f18u,2);
goto P_0c075ee6;
P_0c075ee6: /* original 622c, guest PC 0x0c075ee6 */
if(!s->budget--) { s->failed_pc=0x0c075ee6u; return 0; }
r[2]=r[2]&255u;
goto P_0c075ee8;
P_0c075ee8: /* original 0f26, guest PC 0x0c075ee8 */
if(!s->budget--) { s->failed_pc=0x0c075ee8u; return 0; }
write(ram,r[15]+r[0],r[2],4);
goto P_0c075eea;
P_0c075eea: /* original 9016, guest PC 0x0c075eea */
if(!s->budget--) { s->failed_pc=0x0c075eeau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c075f1au,2);
goto P_0c075eec;
P_0c075eec: /* original 0f36, guest PC 0x0c075eec */
if(!s->budget--) { s->failed_pc=0x0c075eecu; return 0; }
write(ram,r[15]+r[0],r[3],4);
goto P_0c075eee;
P_0c075eee: /* original 9010, guest PC 0x0c075eee */
if(!s->budget--) { s->failed_pc=0x0c075eeeu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c075f12u,2);
goto P_0c075ef0;
P_0c075ef0: /* original 01fe, guest PC 0x0c075ef0 */
if(!s->budget--) { s->failed_pc=0x0c075ef0u; return 0; }
r[1]=read(ram,r[15]+r[0],4);
goto P_0c075ef2;
P_0c075ef2: /* original 9013, guest PC 0x0c075ef2 */
if(!s->budget--) { s->failed_pc=0x0c075ef2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c075f1cu,2);
goto P_0c075ef4;
P_0c075ef4: /* original 031c, guest PC 0x0c075ef4 */
if(!s->budget--) { s->failed_pc=0x0c075ef4u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[1]+r[0],1);
goto P_0c075ef6;
P_0c075ef6: /* original 900b, guest PC 0x0c075ef6 */
if(!s->budget--) { s->failed_pc=0x0c075ef6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c075f10u,2);
goto P_0c075ef8;
P_0c075ef8: /* original 633c, guest PC 0x0c075ef8 */
if(!s->budget--) { s->failed_pc=0x0c075ef8u; return 0; }
r[3]=r[3]&255u;
goto P_0c075efa;
P_0c075efa: /* original 0f36, guest PC 0x0c075efa */
if(!s->budget--) { s->failed_pc=0x0c075efau; return 0; }
write(ram,r[15]+r[0],r[3],4);
goto P_0c075efc;
P_0c075efc: /* original 6033, guest PC 0x0c075efc */
if(!s->budget--) { s->failed_pc=0x0c075efcu; return 0; }
r[0]=r[3];
goto P_0c075efe;
P_0c075efe: /* original 8805, guest PC 0x0c075efe */
if(!s->budget--) { s->failed_pc=0x0c075efeu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000005u)!=0);
goto P_0c075f00;
P_0c075f00: /* original 8902, guest PC 0x0c075f00 */
if(!s->budget--) { s->failed_pc=0x0c075f00u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c075f08; }
goto P_0c075f02;
P_0c075f02: /* original 6033, guest PC 0x0c075f02 */
if(!s->budget--) { s->failed_pc=0x0c075f02u; return 0; }
r[0]=r[3];
goto P_0c075f04;
P_0c075f04: /* original 8806, guest PC 0x0c075f04 */
if(!s->budget--) { s->failed_pc=0x0c075f04u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000006u)!=0);
goto P_0c075f06;
P_0c075f06: /* original 8b13, guest PC 0x0c075f06 */
if(!s->budget--) { s->failed_pc=0x0c075f06u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c075f30; }
goto P_0c075f08;
P_0c075f08: /* original d308, guest PC 0x0c075f08 */
if(!s->budget--) { s->failed_pc=0x0c075f08u; return 0; }
r[3]=read(ram,0x0c075f2cu,4);
goto P_0c075f0a;
P_0c075f0a: /* original e07c, guest PC 0x0c075f0a */
if(!s->budget--) { s->failed_pc=0x0c075f0au; return 0; }
r[0]=0x0000007cu;
goto P_0c075f0c;
P_0c075f0c: /* original a013, guest PC 0x0c075f0c */
if(!s->budget--) { s->failed_pc=0x0c075f0cu; return 0; }
write(ram,r[15]+r[0],r[3],4);
goto P_0c075f36;
P_0c075f0e: /* original 0f36, guest PC 0x0c075f0e */
if(!s->budget--) { s->failed_pc=0x0c075f0eu; return 0; }
write(ram,r[15]+r[0],r[3],4);
return vf3_matrix_family(0x0c075f10u,s,ram);
P_0c075f30: /* original d138, guest PC 0x0c075f30 */
if(!s->budget--) { s->failed_pc=0x0c075f30u; return 0; }
r[1]=read(ram,0x0c076014u,4);
goto P_0c075f32;
P_0c075f32: /* original e07c, guest PC 0x0c075f32 */
if(!s->budget--) { s->failed_pc=0x0c075f32u; return 0; }
r[0]=0x0000007cu;
goto P_0c075f34;
P_0c075f34: /* original 0f16, guest PC 0x0c075f34 */
if(!s->budget--) { s->failed_pc=0x0c075f34u; return 0; }
write(ram,r[15]+r[0],r[1],4);
goto P_0c075f36;
P_0c075f36: /* original 9066, guest PC 0x0c075f36 */
if(!s->budget--) { s->failed_pc=0x0c075f36u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c076006u,2);
goto P_0c075f38;
P_0c075f38: /* original 03fe, guest PC 0x0c075f38 */
if(!s->budget--) { s->failed_pc=0x0c075f38u; return 0; }
r[3]=read(ram,r[15]+r[0],4);
goto P_0c075f3a;
P_0c075f3a: /* original e07c, guest PC 0x0c075f3a */
if(!s->budget--) { s->failed_pc=0x0c075f3au; return 0; }
r[0]=0x0000007cu;
goto P_0c075f3c;
P_0c075f3c: /* original 02fe, guest PC 0x0c075f3c */
if(!s->budget--) { s->failed_pc=0x0c075f3cu; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c075f3e;
P_0c075f3e: /* original 9063, guest PC 0x0c075f3e */
if(!s->budget--) { s->failed_pc=0x0c075f3eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c076008u,2);
goto P_0c075f40;
P_0c075f40: /* original 323c, guest PC 0x0c075f40 */
if(!s->budget--) { s->failed_pc=0x0c075f40u; return 0; }
r[2]+=r[3];
goto P_0c075f42;
P_0c075f42: /* original 6120, guest PC 0x0c075f42 */
if(!s->budget--) { s->failed_pc=0x0c075f42u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[2],1);
r[1]=tmp;
goto P_0c075f44;
P_0c075f44: /* original 611c, guest PC 0x0c075f44 */
if(!s->budget--) { s->failed_pc=0x0c075f44u; return 0; }
r[1]=r[1]&255u;
goto P_0c075f46;
P_0c075f46: /* original 2118, guest PC 0x0c075f46 */
if(!s->budget--) { s->failed_pc=0x0c075f46u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[1])==0)!=0);
goto P_0c075f48;
P_0c075f48: /* original 8d0e, guest PC 0x0c075f48 */
if(!s->budget--) { s->failed_pc=0x0c075f48u; return 0; }
cond=r[17]&1u;
write(ram,r[15]+r[0],r[1],4);
if(cond) { goto P_0c075f68; }
goto P_0c075f4c;
P_0c075f4a: /* original 0f16, guest PC 0x0c075f4a */
if(!s->budget--) { s->failed_pc=0x0c075f4au; return 0; }
write(ram,r[15]+r[0],r[1],4);
goto P_0c075f4c;
P_0c075f4c: /* original 905d, guest PC 0x0c075f4c */
if(!s->budget--) { s->failed_pc=0x0c075f4cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07600au,2);
goto P_0c075f4e;
P_0c075f4e: /* original 02fe, guest PC 0x0c075f4e */
if(!s->budget--) { s->failed_pc=0x0c075f4eu; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c075f50;
P_0c075f50: /* original 905b, guest PC 0x0c075f50 */
if(!s->budget--) { s->failed_pc=0x0c075f50u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07600au,2);
goto P_0c075f52;
P_0c075f52: /* original 720c, guest PC 0x0c075f52 */
if(!s->budget--) { s->failed_pc=0x0c075f52u; return 0; }
r[2]+=0x0000000cu;
goto P_0c075f54;
P_0c075f54: /* original 0f26, guest PC 0x0c075f54 */
if(!s->budget--) { s->failed_pc=0x0c075f54u; return 0; }
write(ram,r[15]+r[0],r[2],4);
goto P_0c075f56;
P_0c075f56: /* original 6013, guest PC 0x0c075f56 */
if(!s->budget--) { s->failed_pc=0x0c075f56u; return 0; }
r[0]=r[1];
goto P_0c075f58;
P_0c075f58: /* original 8801, guest PC 0x0c075f58 */
if(!s->budget--) { s->failed_pc=0x0c075f58u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c075f5a;
P_0c075f5a: /* original 8905, guest PC 0x0c075f5a */
if(!s->budget--) { s->failed_pc=0x0c075f5au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c075f68; }
goto P_0c075f5c;
P_0c075f5c: /* original 9055, guest PC 0x0c075f5c */
if(!s->budget--) { s->failed_pc=0x0c075f5cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07600au,2);
goto P_0c075f5e;
P_0c075f5e: /* original 9354, guest PC 0x0c075f5e */
if(!s->budget--) { s->failed_pc=0x0c075f5eu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07600au,2);
goto P_0c075f60;
P_0c075f60: /* original 00fe, guest PC 0x0c075f60 */
if(!s->budget--) { s->failed_pc=0x0c075f60u; return 0; }
r[0]=read(ram,r[15]+r[0],4);
goto P_0c075f62;
P_0c075f62: /* original 33fc, guest PC 0x0c075f62 */
if(!s->budget--) { s->failed_pc=0x0c075f62u; return 0; }
r[3]+=r[15];
goto P_0c075f64;
P_0c075f64: /* original 700c, guest PC 0x0c075f64 */
if(!s->budget--) { s->failed_pc=0x0c075f64u; return 0; }
r[0]+=0x0000000cu;
goto P_0c075f66;
P_0c075f66: /* original 2302, guest PC 0x0c075f66 */
if(!s->budget--) { s->failed_pc=0x0c075f66u; return 0; }
write(ram,r[3],r[0],4);
goto P_0c075f68;
P_0c075f68: /* original 904f, guest PC 0x0c075f68 */
if(!s->budget--) { s->failed_pc=0x0c075f68u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07600au,2);
goto P_0c075f6a;
P_0c075f6a: /* original 03fe, guest PC 0x0c075f6a */
if(!s->budget--) { s->failed_pc=0x0c075f6au; return 0; }
r[3]=read(ram,r[15]+r[0],4);
goto P_0c075f6c;
P_0c075f6c: /* original e078, guest PC 0x0c075f6c */
if(!s->budget--) { s->failed_pc=0x0c075f6cu; return 0; }
r[0]=0x00000078u;
goto P_0c075f6e;
P_0c075f6e: /* original 02fe, guest PC 0x0c075f6e */
if(!s->budget--) { s->failed_pc=0x0c075f6eu; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c075f70;
P_0c075f70: /* original e078, guest PC 0x0c075f70 */
if(!s->budget--) { s->failed_pc=0x0c075f70u; return 0; }
r[0]=0x00000078u;
goto P_0c075f72;
P_0c075f72: /* original 323c, guest PC 0x0c075f72 */
if(!s->budget--) { s->failed_pc=0x0c075f72u; return 0; }
r[2]+=r[3];
goto P_0c075f74;
P_0c075f74: /* original 0f26, guest PC 0x0c075f74 */
if(!s->budget--) { s->failed_pc=0x0c075f74u; return 0; }
write(ram,r[15]+r[0],r[2],4);
goto P_0c075f76;
P_0c075f76: /* original 9049, guest PC 0x0c075f76 */
if(!s->budget--) { s->failed_pc=0x0c075f76u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07600cu,2);
goto P_0c075f78;
P_0c075f78: /* original 9149, guest PC 0x0c075f78 */
if(!s->budget--) { s->failed_pc=0x0c075f78u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07600eu,2);
goto P_0c075f7a;
P_0c075f7a: /* original 00fe, guest PC 0x0c075f7a */
if(!s->budget--) { s->failed_pc=0x0c075f7au; return 0; }
r[0]=read(ram,r[15]+r[0],4);
goto P_0c075f7c;
P_0c075f7c: /* original 001c, guest PC 0x0c075f7c */
if(!s->budget--) { s->failed_pc=0x0c075f7cu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[1]+r[0],1);
goto P_0c075f7e;
P_0c075f7e: /* original 600c, guest PC 0x0c075f7e */
if(!s->budget--) { s->failed_pc=0x0c075f7eu; return 0; }
r[0]=r[0]&255u;
goto P_0c075f80;
P_0c075f80: /* original 8805, guest PC 0x0c075f80 */
if(!s->budget--) { s->failed_pc=0x0c075f80u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000005u)!=0);
goto P_0c075f82;
P_0c075f82: /* original 8906, guest PC 0x0c075f82 */
if(!s->budget--) { s->failed_pc=0x0c075f82u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c075f92; }
goto P_0c075f84;
P_0c075f84: /* original 9042, guest PC 0x0c075f84 */
if(!s->budget--) { s->failed_pc=0x0c075f84u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07600cu,2);
goto P_0c075f86;
P_0c075f86: /* original 9242, guest PC 0x0c075f86 */
if(!s->budget--) { s->failed_pc=0x0c075f86u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07600eu,2);
goto P_0c075f88;
P_0c075f88: /* original 00fe, guest PC 0x0c075f88 */
if(!s->budget--) { s->failed_pc=0x0c075f88u; return 0; }
r[0]=read(ram,r[15]+r[0],4);
goto P_0c075f8a;
P_0c075f8a: /* original 002c, guest PC 0x0c075f8a */
if(!s->budget--) { s->failed_pc=0x0c075f8au; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[2]+r[0],1);
goto P_0c075f8c;
P_0c075f8c: /* original 600c, guest PC 0x0c075f8c */
if(!s->budget--) { s->failed_pc=0x0c075f8cu; return 0; }
r[0]=r[0]&255u;
goto P_0c075f8e;
P_0c075f8e: /* original 8806, guest PC 0x0c075f8e */
if(!s->budget--) { s->failed_pc=0x0c075f8eu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000006u)!=0);
goto P_0c075f90;
P_0c075f90: /* original 8b06, guest PC 0x0c075f90 */
if(!s->budget--) { s->failed_pc=0x0c075f90u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c075fa0; }
goto P_0c075f92;
P_0c075f92: /* original e078, guest PC 0x0c075f92 */
if(!s->budget--) { s->failed_pc=0x0c075f92u; return 0; }
r[0]=0x00000078u;
goto P_0c075f94;
P_0c075f94: /* original 02fe, guest PC 0x0c075f94 */
if(!s->budget--) { s->failed_pc=0x0c075f94u; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c075f96;
P_0c075f96: /* original d020, guest PC 0x0c075f96 */
if(!s->budget--) { s->failed_pc=0x0c075f96u; return 0; }
r[0]=read(ram,0x0c076018u,4);
goto P_0c075f98;
P_0c075f98: /* original 4208, guest PC 0x0c075f98 */
if(!s->budget--) { s->failed_pc=0x0c075f98u; return 0; }
r[2]<<=2;
goto P_0c075f9a;
P_0c075f9a: /* original 032e, guest PC 0x0c075f9a */
if(!s->budget--) { s->failed_pc=0x0c075f9au; return 0; }
r[3]=read(ram,r[2]+r[0],4);
goto P_0c075f9c;
P_0c075f9c: /* original a005, guest PC 0x0c075f9c */
if(!s->budget--) { s->failed_pc=0x0c075f9cu; return 0; }
goto P_0c075faa;
P_0c075f9e: /* original 0009, guest PC 0x0c075f9e */
if(!s->budget--) { s->failed_pc=0x0c075f9eu; return 0; }
goto P_0c075fa0;
P_0c075fa0: /* original e078, guest PC 0x0c075fa0 */
if(!s->budget--) { s->failed_pc=0x0c075fa0u; return 0; }
r[0]=0x00000078u;
goto P_0c075fa2;
P_0c075fa2: /* original 01fe, guest PC 0x0c075fa2 */
if(!s->budget--) { s->failed_pc=0x0c075fa2u; return 0; }
r[1]=read(ram,r[15]+r[0],4);
goto P_0c075fa4;
P_0c075fa4: /* original d01d, guest PC 0x0c075fa4 */
if(!s->budget--) { s->failed_pc=0x0c075fa4u; return 0; }
r[0]=read(ram,0x0c07601cu,4);
goto P_0c075fa6;
P_0c075fa6: /* original 4108, guest PC 0x0c075fa6 */
if(!s->budget--) { s->failed_pc=0x0c075fa6u; return 0; }
r[1]<<=2;
goto P_0c075fa8;
P_0c075fa8: /* original 031e, guest PC 0x0c075fa8 */
if(!s->budget--) { s->failed_pc=0x0c075fa8u; return 0; }
r[3]=read(ram,r[1]+r[0],4);
goto P_0c075faa;
P_0c075faa: /* original 902d, guest PC 0x0c075faa */
if(!s->budget--) { s->failed_pc=0x0c075faau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c076008u,2);
goto P_0c075fac;
P_0c075fac: /* original 0f36, guest PC 0x0c075fac */
if(!s->budget--) { s->failed_pc=0x0c075facu; return 0; }
write(ram,r[15]+r[0],r[3],4);
goto P_0c075fae;
P_0c075fae: /* original 902d, guest PC 0x0c075fae */
if(!s->budget--) { s->failed_pc=0x0c075faeu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07600cu,2);
goto P_0c075fb0;
P_0c075fb0: /* original 02fe, guest PC 0x0c075fb0 */
if(!s->budget--) { s->failed_pc=0x0c075fb0u; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c075fb2;
P_0c075fb2: /* original 902d, guest PC 0x0c075fb2 */
if(!s->budget--) { s->failed_pc=0x0c075fb2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c076010u,2);
goto P_0c075fb4;
P_0c075fb4: /* original 032e, guest PC 0x0c075fb4 */
if(!s->budget--) { s->failed_pc=0x0c075fb4u; return 0; }
r[3]=read(ram,r[2]+r[0],4);
goto P_0c075fb6;
P_0c075fb6: /* original 1f35, guest PC 0x0c075fb6 */
if(!s->budget--) { s->failed_pc=0x0c075fb6u; return 0; }
write(ram,r[15]+20,r[3],4);
goto P_0c075fb8;
P_0c075fb8: /* original 52f5, guest PC 0x0c075fb8 */
if(!s->budget--) { s->failed_pc=0x0c075fb8u; return 0; }
r[2]=read(ram,r[15]+20,4);
goto P_0c075fba;
P_0c075fba: /* original d319, guest PC 0x0c075fba */
if(!s->budget--) { s->failed_pc=0x0c075fbau; return 0; }
r[3]=read(ram,0x0c076020u,4);
goto P_0c075fbc;
P_0c075fbc: /* original 2238, guest PC 0x0c075fbc */
if(!s->budget--) { s->failed_pc=0x0c075fbcu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c075fbe;
P_0c075fbe: /* original 8b0c, guest PC 0x0c075fbe */
if(!s->budget--) { s->failed_pc=0x0c075fbeu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c075fda; }
goto P_0c075fc0;
P_0c075fc0: /* original 9027, guest PC 0x0c075fc0 */
if(!s->budget--) { s->failed_pc=0x0c075fc0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c076012u,2);
goto P_0c075fc2;
P_0c075fc2: /* original e200, guest PC 0x0c075fc2 */
if(!s->budget--) { s->failed_pc=0x0c075fc2u; return 0; }
r[2]=0x00000000u;
goto P_0c075fc4;
P_0c075fc4: /* original 01fe, guest PC 0x0c075fc4 */
if(!s->budget--) { s->failed_pc=0x0c075fc4u; return 0; }
r[1]=read(ram,r[15]+r[0],4);
goto P_0c075fc6;
P_0c075fc6: /* original e046, guest PC 0x0c075fc6 */
if(!s->budget--) { s->failed_pc=0x0c075fc6u; return 0; }
r[0]=0x00000046u;
goto P_0c075fc8;
P_0c075fc8: /* original 031d, guest PC 0x0c075fc8 */
if(!s->budget--) { s->failed_pc=0x0c075fc8u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[1]+r[0],2);
goto P_0c075fca;
P_0c075fca: /* original 633d, guest PC 0x0c075fca */
if(!s->budget--) { s->failed_pc=0x0c075fcau; return 0; }
r[3]=r[3]&65535u;
goto P_0c075fcc;
P_0c075fcc: /* original 3326, guest PC 0x0c075fcc */
if(!s->budget--) { s->failed_pc=0x0c075fccu; return 0; }
r[17]=(r[17]&~1u)|((r[3]>r[2])!=0);
goto P_0c075fce;
P_0c075fce: /* original 8f46, guest PC 0x0c075fce */
if(!s->budget--) { s->failed_pc=0x0c075fceu; return 0; }
cond=r[17]&1u;
write(ram,r[15]+20,r[3],4);
if(!cond) { goto P_0c07605e; }
goto P_0c075fd2;
P_0c075fd0: /* original 1f35, guest PC 0x0c075fd0 */
if(!s->budget--) { s->failed_pc=0x0c075fd0u; return 0; }
write(ram,r[15]+20,r[3],4);
goto P_0c075fd2;
P_0c075fd2: /* original e054, guest PC 0x0c075fd2 */
if(!s->budget--) { s->failed_pc=0x0c075fd2u; return 0; }
r[0]=0x00000054u;
goto P_0c075fd4;
P_0c075fd4: /* original 00fe, guest PC 0x0c075fd4 */
if(!s->budget--) { s->failed_pc=0x0c075fd4u; return 0; }
r[0]=read(ram,r[15]+r[0],4);
goto P_0c075fd6;
P_0c075fd6: /* original 3032, guest PC 0x0c075fd6 */
if(!s->budget--) { s->failed_pc=0x0c075fd6u; return 0; }
r[17]=(r[17]&~1u)|((r[0]>=r[3])!=0);
goto P_0c075fd8;
P_0c075fd8: /* original 8b41, guest PC 0x0c075fd8 */
if(!s->budget--) { s->failed_pc=0x0c075fd8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07605e; }
goto P_0c075fda;
P_0c075fda: /* original 9017, guest PC 0x0c075fda */
if(!s->budget--) { s->failed_pc=0x0c075fdau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07600cu,2);
goto P_0c075fdc;
P_0c075fdc: /* original 02fe, guest PC 0x0c075fdc */
if(!s->budget--) { s->failed_pc=0x0c075fdcu; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c075fde;
P_0c075fde: /* original 9016, guest PC 0x0c075fde */
if(!s->budget--) { s->failed_pc=0x0c075fdeu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07600eu,2);
goto P_0c075fe0;
P_0c075fe0: /* original 032c, guest PC 0x0c075fe0 */
if(!s->budget--) { s->failed_pc=0x0c075fe0u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[2]+r[0],1);
goto P_0c075fe2;
P_0c075fe2: /* original 633c, guest PC 0x0c075fe2 */
if(!s->budget--) { s->failed_pc=0x0c075fe2u; return 0; }
r[3]=r[3]&255u;
goto P_0c075fe4;
P_0c075fe4: /* original 6033, guest PC 0x0c075fe4 */
if(!s->budget--) { s->failed_pc=0x0c075fe4u; return 0; }
r[0]=r[3];
goto P_0c075fe6;
P_0c075fe6: /* original 8805, guest PC 0x0c075fe6 */
if(!s->budget--) { s->failed_pc=0x0c075fe6u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000005u)!=0);
goto P_0c075fe8;
P_0c075fe8: /* original 1f35, guest PC 0x0c075fe8 */
if(!s->budget--) { s->failed_pc=0x0c075fe8u; return 0; }
write(ram,r[15]+20,r[3],4);
goto P_0c075fea;
P_0c075fea: /* original 8908, guest PC 0x0c075fea */
if(!s->budget--) { s->failed_pc=0x0c075feau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c075ffe; }
goto P_0c075fec;
P_0c075fec: /* original 6033, guest PC 0x0c075fec */
if(!s->budget--) { s->failed_pc=0x0c075fecu; return 0; }
r[0]=r[3];
goto P_0c075fee;
P_0c075fee: /* original 8806, guest PC 0x0c075fee */
if(!s->budget--) { s->failed_pc=0x0c075feeu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000006u)!=0);
goto P_0c075ff0;
P_0c075ff0: /* original 8905, guest PC 0x0c075ff0 */
if(!s->budget--) { s->failed_pc=0x0c075ff0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c075ffe; }
goto P_0c075ff2;
P_0c075ff2: /* original 6033, guest PC 0x0c075ff2 */
if(!s->budget--) { s->failed_pc=0x0c075ff2u; return 0; }
r[0]=r[3];
goto P_0c075ff4;
P_0c075ff4: /* original 881a, guest PC 0x0c075ff4 */
if(!s->budget--) { s->failed_pc=0x0c075ff4u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000001au)!=0);
goto P_0c075ff6;
P_0c075ff6: /* original 8902, guest PC 0x0c075ff6 */
if(!s->budget--) { s->failed_pc=0x0c075ff6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c075ffe; }
goto P_0c075ff8;
P_0c075ff8: /* original 6033, guest PC 0x0c075ff8 */
if(!s->budget--) { s->failed_pc=0x0c075ff8u; return 0; }
r[0]=r[3];
goto P_0c075ffa;
P_0c075ffa: /* original 881b, guest PC 0x0c075ffa */
if(!s->budget--) { s->failed_pc=0x0c075ffau; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000001bu)!=0);
goto P_0c075ffc;
P_0c075ffc: /* original 8b12, guest PC 0x0c075ffc */
if(!s->budget--) { s->failed_pc=0x0c075ffcu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c076024; }
goto P_0c075ffe;
P_0c075ffe: /* original 9003, guest PC 0x0c075ffe */
if(!s->budget--) { s->failed_pc=0x0c075ffeu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c076008u,2);
goto P_0c076000;
P_0c076000: /* original e33f, guest PC 0x0c076000 */
if(!s->budget--) { s->failed_pc=0x0c076000u; return 0; }
r[3]=0x0000003fu;
goto P_0c076002;
P_0c076002: /* original a02c, guest PC 0x0c076002 */
if(!s->budget--) { s->failed_pc=0x0c076002u; return 0; }
write(ram,r[15]+r[0],r[3],4);
goto P_0c07605e;
P_0c076004: /* original 0f36, guest PC 0x0c076004 */
if(!s->budget--) { s->failed_pc=0x0c076004u; return 0; }
write(ram,r[15]+r[0],r[3],4);
return vf3_matrix_family(0x0c076006u,s,ram);
P_0c076024: /* original 50f5, guest PC 0x0c076024 */
if(!s->budget--) { s->failed_pc=0x0c076024u; return 0; }
r[0]=read(ram,r[15]+20,4);
goto P_0c076026;
P_0c076026: /* original 8809, guest PC 0x0c076026 */
if(!s->budget--) { s->failed_pc=0x0c076026u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000009u)!=0);
goto P_0c076028;
P_0c076028: /* original 8908, guest PC 0x0c076028 */
if(!s->budget--) { s->failed_pc=0x0c076028u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07603c; }
goto P_0c07602a;
P_0c07602a: /* original 50f5, guest PC 0x0c07602a */
if(!s->budget--) { s->failed_pc=0x0c07602au; return 0; }
r[0]=read(ram,r[15]+20,4);
goto P_0c07602c;
P_0c07602c: /* original 880a, guest PC 0x0c07602c */
if(!s->budget--) { s->failed_pc=0x0c07602cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000au)!=0);
goto P_0c07602e;
P_0c07602e: /* original 8905, guest PC 0x0c07602e */
if(!s->budget--) { s->failed_pc=0x0c07602eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07603c; }
goto P_0c076030;
P_0c076030: /* original 50f5, guest PC 0x0c076030 */
if(!s->budget--) { s->failed_pc=0x0c076030u; return 0; }
r[0]=read(ram,r[15]+20,4);
goto P_0c076032;
P_0c076032: /* original 880e, guest PC 0x0c076032 */
if(!s->budget--) { s->failed_pc=0x0c076032u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000eu)!=0);
goto P_0c076034;
P_0c076034: /* original 8902, guest PC 0x0c076034 */
if(!s->budget--) { s->failed_pc=0x0c076034u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07603c; }
goto P_0c076036;
P_0c076036: /* original 50f5, guest PC 0x0c076036 */
if(!s->budget--) { s->failed_pc=0x0c076036u; return 0; }
r[0]=read(ram,r[15]+20,4);
goto P_0c076038;
P_0c076038: /* original 880f, guest PC 0x0c076038 */
if(!s->budget--) { s->failed_pc=0x0c076038u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000fu)!=0);
goto P_0c07603a;
P_0c07603a: /* original 8b10, guest PC 0x0c07603a */
if(!s->budget--) { s->failed_pc=0x0c07603au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07605e; }
goto P_0c07603c;
P_0c07603c: /* original e070, guest PC 0x0c07603c */
if(!s->budget--) { s->failed_pc=0x0c07603cu; return 0; }
r[0]=0x00000070u;
goto P_0c07603e;
P_0c07603e: /* original d31a, guest PC 0x0c07603e */
if(!s->budget--) { s->failed_pc=0x0c07603eu; return 0; }
r[3]=read(ram,0x0c0760a8u,4);
goto P_0c076040;
P_0c076040: /* original 02fe, guest PC 0x0c076040 */
if(!s->budget--) { s->failed_pc=0x0c076040u; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c076042;
P_0c076042: /* original 2238, guest PC 0x0c076042 */
if(!s->budget--) { s->failed_pc=0x0c076042u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c076044;
P_0c076044: /* original 8903, guest PC 0x0c076044 */
if(!s->budget--) { s->failed_pc=0x0c076044u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07604e; }
goto P_0c076046;
P_0c076046: /* original 902a, guest PC 0x0c076046 */
if(!s->budget--) { s->failed_pc=0x0c076046u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07609eu,2);
goto P_0c076048;
P_0c076048: /* original e268, guest PC 0x0c076048 */
if(!s->budget--) { s->failed_pc=0x0c076048u; return 0; }
r[2]=0x00000068u;
goto P_0c07604a;
P_0c07604a: /* original a008, guest PC 0x0c07604a */
if(!s->budget--) { s->failed_pc=0x0c07604au; return 0; }
write(ram,r[15]+r[0],r[2],4);
goto P_0c07605e;
P_0c07604c: /* original 0f26, guest PC 0x0c07604c */
if(!s->budget--) { s->failed_pc=0x0c07604cu; return 0; }
write(ram,r[15]+r[0],r[2],4);
goto P_0c07604e;
P_0c07604e: /* original e054, guest PC 0x0c07604e */
if(!s->budget--) { s->failed_pc=0x0c07604eu; return 0; }
r[0]=0x00000054u;
goto P_0c076050;
P_0c076050: /* original 01fe, guest PC 0x0c076050 */
if(!s->budget--) { s->failed_pc=0x0c076050u; return 0; }
r[1]=read(ram,r[15]+r[0],4);
goto P_0c076052;
P_0c076052: /* original e21e, guest PC 0x0c076052 */
if(!s->budget--) { s->failed_pc=0x0c076052u; return 0; }
r[2]=0x0000001eu;
goto P_0c076054;
P_0c076054: /* original 3122, guest PC 0x0c076054 */
if(!s->budget--) { s->failed_pc=0x0c076054u; return 0; }
r[17]=(r[17]&~1u)|((r[1]>=r[2])!=0);
goto P_0c076056;
P_0c076056: /* original 8902, guest PC 0x0c076056 */
if(!s->budget--) { s->failed_pc=0x0c076056u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07605e; }
goto P_0c076058;
P_0c076058: /* original 9021, guest PC 0x0c076058 */
if(!s->budget--) { s->failed_pc=0x0c076058u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07609eu,2);
goto P_0c07605a;
P_0c07605a: /* original e169, guest PC 0x0c07605a */
if(!s->budget--) { s->failed_pc=0x0c07605au; return 0; }
r[1]=0x00000069u;
goto P_0c07605c;
P_0c07605c: /* original 0f16, guest PC 0x0c07605c */
if(!s->budget--) { s->failed_pc=0x0c07605cu; return 0; }
write(ram,r[15]+r[0],r[1],4);
goto P_0c07605e;
P_0c07605e: /* original d313, guest PC 0x0c07605e */
if(!s->budget--) { s->failed_pc=0x0c07605eu; return 0; }
r[3]=read(ram,0x0c0760acu,4);
goto P_0c076060;
P_0c076060: /* original 901d, guest PC 0x0c076060 */
if(!s->budget--) { s->failed_pc=0x0c076060u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07609eu,2);
goto P_0c076062;
P_0c076062: /* original 430b, guest PC 0x0c076062 */
if(!s->budget--) { s->failed_pc=0x0c076062u; return 0; }
target=r[3];
r[16]=0x0c076066u;
r[4]=read(ram,r[15]+r[0],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c076066u) { target=s->pc; goto dispatch; }
goto P_0c076066;
P_0c076064: /* original 04fe, guest PC 0x0c076064 */
if(!s->budget--) { s->failed_pc=0x0c076064u; return 0; }
r[4]=read(ram,r[15]+r[0],4);
goto P_0c076066;
P_0c076066: /* original d312, guest PC 0x0c076066 */
if(!s->budget--) { s->failed_pc=0x0c076066u; return 0; }
r[3]=read(ram,0x0c0760b0u,4);
goto P_0c076068;
P_0c076068: /* original 9019, guest PC 0x0c076068 */
if(!s->budget--) { s->failed_pc=0x0c076068u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07609eu,2);
goto P_0c07606a;
P_0c07606a: /* original 430b, guest PC 0x0c07606a */
if(!s->budget--) { s->failed_pc=0x0c07606au; return 0; }
target=r[3];
r[16]=0x0c07606eu;
r[4]=read(ram,r[15]+r[0],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07606eu) { target=s->pc; goto dispatch; }
goto P_0c07606e;
P_0c07606c: /* original 04fe, guest PC 0x0c07606c */
if(!s->budget--) { s->failed_pc=0x0c07606cu; return 0; }
r[4]=read(ram,r[15]+r[0],4);
goto P_0c07606e;
P_0c07606e: /* original 9017, guest PC 0x0c07606e */
if(!s->budget--) { s->failed_pc=0x0c07606eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0760a0u,2);
goto P_0c076070;
P_0c076070: /* original e161, guest PC 0x0c076070 */
if(!s->budget--) { s->failed_pc=0x0c076070u; return 0; }
r[1]=0x00000061u;
goto P_0c076072;
P_0c076072: /* original 00fe, guest PC 0x0c076072 */
if(!s->budget--) { s->failed_pc=0x0c076072u; return 0; }
r[0]=read(ram,r[15]+r[0],4);
goto P_0c076074;
P_0c076074: /* original 001c, guest PC 0x0c076074 */
if(!s->budget--) { s->failed_pc=0x0c076074u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[1]+r[0],1);
goto P_0c076076;
P_0c076076: /* original 600c, guest PC 0x0c076076 */
if(!s->budget--) { s->failed_pc=0x0c076076u; return 0; }
r[0]=r[0]&255u;
goto P_0c076078;
P_0c076078: /* original 8809, guest PC 0x0c076078 */
if(!s->budget--) { s->failed_pc=0x0c076078u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000009u)!=0);
goto P_0c07607a;
P_0c07607a: /* original 8b26, guest PC 0x0c07607a */
if(!s->budget--) { s->failed_pc=0x0c07607au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0760ca; }
goto P_0c07607c;
P_0c07607c: /* original 9011, guest PC 0x0c07607c */
if(!s->budget--) { s->failed_pc=0x0c07607cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0760a2u,2);
goto P_0c07607e;
P_0c07607e: /* original 02fe, guest PC 0x0c07607e */
if(!s->budget--) { s->failed_pc=0x0c07607eu; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c076080;
P_0c076080: /* original 9010, guest PC 0x0c076080 */
if(!s->budget--) { s->failed_pc=0x0c076080u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0760a4u,2);
goto P_0c076082;
P_0c076082: /* original 032c, guest PC 0x0c076082 */
if(!s->budget--) { s->failed_pc=0x0c076082u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[2]+r[0],1);
goto P_0c076084;
P_0c076084: /* original 900b, guest PC 0x0c076084 */
if(!s->budget--) { s->failed_pc=0x0c076084u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07609eu,2);
goto P_0c076086;
P_0c076086: /* original 633c, guest PC 0x0c076086 */
if(!s->budget--) { s->failed_pc=0x0c076086u; return 0; }
r[3]=r[3]&255u;
goto P_0c076088;
P_0c076088: /* original 0f36, guest PC 0x0c076088 */
if(!s->budget--) { s->failed_pc=0x0c076088u; return 0; }
write(ram,r[15]+r[0],r[3],4);
goto P_0c07608a;
P_0c07608a: /* original 6033, guest PC 0x0c07608a */
if(!s->budget--) { s->failed_pc=0x0c07608au; return 0; }
r[0]=r[3];
goto P_0c07608c;
P_0c07608c: /* original 8805, guest PC 0x0c07608c */
if(!s->budget--) { s->failed_pc=0x0c07608cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000005u)!=0);
goto P_0c07608e;
P_0c07608e: /* original 8902, guest PC 0x0c07608e */
if(!s->budget--) { s->failed_pc=0x0c07608eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c076096; }
goto P_0c076090;
P_0c076090: /* original 6033, guest PC 0x0c076090 */
if(!s->budget--) { s->failed_pc=0x0c076090u; return 0; }
r[0]=r[3];
goto P_0c076092;
P_0c076092: /* original 8806, guest PC 0x0c076092 */
if(!s->budget--) { s->failed_pc=0x0c076092u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000006u)!=0);
goto P_0c076094;
P_0c076094: /* original 8b0e, guest PC 0x0c076094 */
if(!s->budget--) { s->failed_pc=0x0c076094u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0760b4; }
goto P_0c076096;
P_0c076096: /* original e078, guest PC 0x0c076096 */
if(!s->budget--) { s->failed_pc=0x0c076096u; return 0; }
r[0]=0x00000078u;
goto P_0c076098;
P_0c076098: /* original e365, guest PC 0x0c076098 */
if(!s->budget--) { s->failed_pc=0x0c076098u; return 0; }
r[3]=0x00000065u;
goto P_0c07609a;
P_0c07609a: /* original a00e, guest PC 0x0c07609a */
if(!s->budget--) { s->failed_pc=0x0c07609au; return 0; }
write(ram,r[15]+r[0],r[3],4);
goto P_0c0760ba;
P_0c07609c: /* original 0f36, guest PC 0x0c07609c */
if(!s->budget--) { s->failed_pc=0x0c07609cu; return 0; }
write(ram,r[15]+r[0],r[3],4);
return vf3_matrix_family(0x0c07609eu,s,ram);
P_0c0760b4: /* original e078, guest PC 0x0c0760b4 */
if(!s->budget--) { s->failed_pc=0x0c0760b4u; return 0; }
r[0]=0x00000078u;
goto P_0c0760b6;
P_0c0760b6: /* original e166, guest PC 0x0c0760b6 */
if(!s->budget--) { s->failed_pc=0x0c0760b6u; return 0; }
r[1]=0x00000066u;
goto P_0c0760b8;
P_0c0760b8: /* original 0f16, guest PC 0x0c0760b8 */
if(!s->budget--) { s->failed_pc=0x0c0760b8u; return 0; }
write(ram,r[15]+r[0],r[1],4);
goto P_0c0760ba;
P_0c0760ba: /* original d350, guest PC 0x0c0760ba */
if(!s->budget--) { s->failed_pc=0x0c0760bau; return 0; }
r[3]=read(ram,0x0c0761fcu,4);
goto P_0c0760bc;
P_0c0760bc: /* original e078, guest PC 0x0c0760bc */
if(!s->budget--) { s->failed_pc=0x0c0760bcu; return 0; }
r[0]=0x00000078u;
goto P_0c0760be;
P_0c0760be: /* original 430b, guest PC 0x0c0760be */
if(!s->budget--) { s->failed_pc=0x0c0760beu; return 0; }
target=r[3];
r[16]=0x0c0760c2u;
r[4]=read(ram,r[15]+r[0],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0760c2u) { target=s->pc; goto dispatch; }
goto P_0c0760c2;
P_0c0760c0: /* original 04fe, guest PC 0x0c0760c0 */
if(!s->budget--) { s->failed_pc=0x0c0760c0u; return 0; }
r[4]=read(ram,r[15]+r[0],4);
goto P_0c0760c2;
P_0c0760c2: /* original d34f, guest PC 0x0c0760c2 */
if(!s->budget--) { s->failed_pc=0x0c0760c2u; return 0; }
r[3]=read(ram,0x0c076200u,4);
goto P_0c0760c4;
P_0c0760c4: /* original e078, guest PC 0x0c0760c4 */
if(!s->budget--) { s->failed_pc=0x0c0760c4u; return 0; }
r[0]=0x00000078u;
goto P_0c0760c6;
P_0c0760c6: /* original 430b, guest PC 0x0c0760c6 */
if(!s->budget--) { s->failed_pc=0x0c0760c6u; return 0; }
target=r[3];
r[16]=0x0c0760cau;
r[4]=read(ram,r[15]+r[0],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0760cau) { target=s->pc; goto dispatch; }
goto P_0c0760ca;
P_0c0760c8: /* original 04fe, guest PC 0x0c0760c8 */
if(!s->budget--) { s->failed_pc=0x0c0760c8u; return 0; }
r[4]=read(ram,r[15]+r[0],4);
goto P_0c0760ca;
P_0c0760ca: /* original 908c, guest PC 0x0c0760ca */
if(!s->budget--) { s->failed_pc=0x0c0760cau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0761e6u,2);
goto P_0c0760cc;
P_0c0760cc: /* original 02fe, guest PC 0x0c0760cc */
if(!s->budget--) { s->failed_pc=0x0c0760ccu; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c0760ce;
P_0c0760ce: /* original e048, guest PC 0x0c0760ce */
if(!s->budget--) { s->failed_pc=0x0c0760ceu; return 0; }
r[0]=0x00000048u;
goto P_0c0760d0;
P_0c0760d0: /* original 032e, guest PC 0x0c0760d0 */
if(!s->budget--) { s->failed_pc=0x0c0760d0u; return 0; }
r[3]=read(ram,r[2]+r[0],4);
goto P_0c0760d2;
P_0c0760d2: /* original e05c, guest PC 0x0c0760d2 */
if(!s->budget--) { s->failed_pc=0x0c0760d2u; return 0; }
r[0]=0x0000005cu;
goto P_0c0760d4;
P_0c0760d4: /* original 0f36, guest PC 0x0c0760d4 */
if(!s->budget--) { s->failed_pc=0x0c0760d4u; return 0; }
write(ram,r[15]+r[0],r[3],4);
goto P_0c0760d6;
P_0c0760d6: /* original 9086, guest PC 0x0c0760d6 */
if(!s->budget--) { s->failed_pc=0x0c0760d6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0761e6u,2);
goto P_0c0760d8;
P_0c0760d8: /* original 02fe, guest PC 0x0c0760d8 */
if(!s->budget--) { s->failed_pc=0x0c0760d8u; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c0760da;
P_0c0760da: /* original e04c, guest PC 0x0c0760da */
if(!s->budget--) { s->failed_pc=0x0c0760dau; return 0; }
r[0]=0x0000004cu;
goto P_0c0760dc;
P_0c0760dc: /* original 032e, guest PC 0x0c0760dc */
if(!s->budget--) { s->failed_pc=0x0c0760dcu; return 0; }
r[3]=read(ram,r[2]+r[0],4);
goto P_0c0760de;
P_0c0760de: /* original e06c, guest PC 0x0c0760de */
if(!s->budget--) { s->failed_pc=0x0c0760deu; return 0; }
r[0]=0x0000006cu;
goto P_0c0760e0;
P_0c0760e0: /* original 0f36, guest PC 0x0c0760e0 */
if(!s->budget--) { s->failed_pc=0x0c0760e0u; return 0; }
write(ram,r[15]+r[0],r[3],4);
goto P_0c0760e2;
P_0c0760e2: /* original 9081, guest PC 0x0c0760e2 */
if(!s->budget--) { s->failed_pc=0x0c0760e2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0761e8u,2);
goto P_0c0760e4;
P_0c0760e4: /* original 02fe, guest PC 0x0c0760e4 */
if(!s->budget--) { s->failed_pc=0x0c0760e4u; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c0760e6;
P_0c0760e6: /* original 9080, guest PC 0x0c0760e6 */
if(!s->budget--) { s->failed_pc=0x0c0760e6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0761eau,2);
goto P_0c0760e8;
P_0c0760e8: /* original 032e, guest PC 0x0c0760e8 */
if(!s->budget--) { s->failed_pc=0x0c0760e8u; return 0; }
r[3]=read(ram,r[2]+r[0],4);
goto P_0c0760ea;
P_0c0760ea: /* original e070, guest PC 0x0c0760ea */
if(!s->budget--) { s->failed_pc=0x0c0760eau; return 0; }
r[0]=0x00000070u;
goto P_0c0760ec;
P_0c0760ec: /* original 0f36, guest PC 0x0c0760ec */
if(!s->budget--) { s->failed_pc=0x0c0760ecu; return 0; }
write(ram,r[15]+r[0],r[3],4);
goto P_0c0760ee;
P_0c0760ee: /* original e05c, guest PC 0x0c0760ee */
if(!s->budget--) { s->failed_pc=0x0c0760eeu; return 0; }
r[0]=0x0000005cu;
goto P_0c0760f0;
P_0c0760f0: /* original 02fe, guest PC 0x0c0760f0 */
if(!s->budget--) { s->failed_pc=0x0c0760f0u; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c0760f2;
P_0c0760f2: /* original d344, guest PC 0x0c0760f2 */
if(!s->budget--) { s->failed_pc=0x0c0760f2u; return 0; }
r[3]=read(ram,0x0c076204u,4);
goto P_0c0760f4;
P_0c0760f4: /* original 2238, guest PC 0x0c0760f4 */
if(!s->budget--) { s->failed_pc=0x0c0760f4u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0760f6;
P_0c0760f6: /* original 8901, guest PC 0x0c0760f6 */
if(!s->budget--) { s->failed_pc=0x0c0760f6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0760fc; }
goto P_0c0760f8;
P_0c0760f8: /* original a0e5, guest PC 0x0c0760f8 */
if(!s->budget--) { s->failed_pc=0x0c0760f8u; return 0; }
goto P_0c0762c6;
P_0c0760fa: /* original 0009, guest PC 0x0c0760fa */
if(!s->budget--) { s->failed_pc=0x0c0760fau; return 0; }
goto P_0c0760fc;
P_0c0760fc: /* original e05c, guest PC 0x0c0760fc */
if(!s->budget--) { s->failed_pc=0x0c0760fcu; return 0; }
r[0]=0x0000005cu;
goto P_0c0760fe;
P_0c0760fe: /* original d342, guest PC 0x0c0760fe */
if(!s->budget--) { s->failed_pc=0x0c0760feu; return 0; }
r[3]=read(ram,0x0c076208u,4);
goto P_0c076100;
P_0c076100: /* original 01fe, guest PC 0x0c076100 */
if(!s->budget--) { s->failed_pc=0x0c076100u; return 0; }
r[1]=read(ram,r[15]+r[0],4);
goto P_0c076102;
P_0c076102: /* original 2138, guest PC 0x0c076102 */
if(!s->budget--) { s->failed_pc=0x0c076102u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[3])==0)!=0);
goto P_0c076104;
P_0c076104: /* original 8901, guest PC 0x0c076104 */
if(!s->budget--) { s->failed_pc=0x0c076104u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07610a; }
goto P_0c076106;
P_0c076106: /* original a125, guest PC 0x0c076106 */
if(!s->budget--) { s->failed_pc=0x0c076106u; return 0; }
goto P_0c076354;
P_0c076108: /* original 0009, guest PC 0x0c076108 */
if(!s->budget--) { s->failed_pc=0x0c076108u; return 0; }
goto P_0c07610a;
P_0c07610a: /* original e06c, guest PC 0x0c07610a */
if(!s->budget--) { s->failed_pc=0x0c07610au; return 0; }
r[0]=0x0000006cu;
goto P_0c07610c;
P_0c07610c: /* original d33f, guest PC 0x0c07610c */
if(!s->budget--) { s->failed_pc=0x0c07610cu; return 0; }
r[3]=read(ram,0x0c07620cu,4);
goto P_0c07610e;
P_0c07610e: /* original 02fe, guest PC 0x0c07610e */
if(!s->budget--) { s->failed_pc=0x0c07610eu; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c076110;
P_0c076110: /* original 2238, guest PC 0x0c076110 */
if(!s->budget--) { s->failed_pc=0x0c076110u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c076112;
P_0c076112: /* original 8901, guest PC 0x0c076112 */
if(!s->budget--) { s->failed_pc=0x0c076112u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c076118; }
goto P_0c076114;
P_0c076114: /* original a421, guest PC 0x0c076114 */
if(!s->budget--) { s->failed_pc=0x0c076114u; return 0; }
return vf3_matrix_family(0x0c07695au,s,ram);
P_0c076116: /* original 0009, guest PC 0x0c076116 */
if(!s->budget--) { s->failed_pc=0x0c076116u; return 0; }
goto P_0c076118;
P_0c076118: /* original e05c, guest PC 0x0c076118 */
if(!s->budget--) { s->failed_pc=0x0c076118u; return 0; }
r[0]=0x0000005cu;
goto P_0c07611a;
P_0c07611a: /* original d33d, guest PC 0x0c07611a */
if(!s->budget--) { s->failed_pc=0x0c07611au; return 0; }
r[3]=read(ram,0x0c076210u,4);
goto P_0c07611c;
P_0c07611c: /* original 01fe, guest PC 0x0c07611c */
if(!s->budget--) { s->failed_pc=0x0c07611cu; return 0; }
r[1]=read(ram,r[15]+r[0],4);
goto P_0c07611e;
P_0c07611e: /* original 2138, guest PC 0x0c07611e */
if(!s->budget--) { s->failed_pc=0x0c07611eu; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[3])==0)!=0);
goto P_0c076120;
P_0c076120: /* original 8901, guest PC 0x0c076120 */
if(!s->budget--) { s->failed_pc=0x0c076120u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c076126; }
goto P_0c076122;
P_0c076122: /* original a11d, guest PC 0x0c076122 */
if(!s->budget--) { s->failed_pc=0x0c076122u; return 0; }
goto P_0c076360;
P_0c076124: /* original 0009, guest PC 0x0c076124 */
if(!s->budget--) { s->failed_pc=0x0c076124u; return 0; }
goto P_0c076126;
P_0c076126: /* original e070, guest PC 0x0c076126 */
if(!s->budget--) { s->failed_pc=0x0c076126u; return 0; }
r[0]=0x00000070u;
goto P_0c076128;
P_0c076128: /* original d23a, guest PC 0x0c076128 */
if(!s->budget--) { s->failed_pc=0x0c076128u; return 0; }
r[2]=read(ram,0x0c076214u,4);
goto P_0c07612a;
P_0c07612a: /* original 01fe, guest PC 0x0c07612a */
if(!s->budget--) { s->failed_pc=0x0c07612au; return 0; }
r[1]=read(ram,r[15]+r[0],4);
goto P_0c07612c;
P_0c07612c: /* original 2128, guest PC 0x0c07612c */
if(!s->budget--) { s->failed_pc=0x0c07612cu; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[2])==0)!=0);
goto P_0c07612e;
P_0c07612e: /* original 8901, guest PC 0x0c07612e */
if(!s->budget--) { s->failed_pc=0x0c07612eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c076134; }
goto P_0c076130;
P_0c076130: /* original a116, guest PC 0x0c076130 */
if(!s->budget--) { s->failed_pc=0x0c076130u; return 0; }
goto P_0c076360;
P_0c076132: /* original 0009, guest PC 0x0c076132 */
if(!s->budget--) { s->failed_pc=0x0c076132u; return 0; }
goto P_0c076134;
P_0c076134: /* original e06c, guest PC 0x0c076134 */
if(!s->budget--) { s->failed_pc=0x0c076134u; return 0; }
r[0]=0x0000006cu;
goto P_0c076136;
P_0c076136: /* original 9159, guest PC 0x0c076136 */
if(!s->budget--) { s->failed_pc=0x0c076136u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0761ecu,2);
goto P_0c076138;
P_0c076138: /* original 00fe, guest PC 0x0c076138 */
if(!s->budget--) { s->failed_pc=0x0c076138u; return 0; }
r[0]=read(ram,r[15]+r[0],4);
goto P_0c07613a;
P_0c07613a: /* original 2018, guest PC 0x0c07613a */
if(!s->budget--) { s->failed_pc=0x0c07613au; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[1])==0)!=0);
goto P_0c07613c;
P_0c07613c: /* original 8901, guest PC 0x0c07613c */
if(!s->budget--) { s->failed_pc=0x0c07613cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c076142; }
goto P_0c07613e;
P_0c07613e: /* original a10f, guest PC 0x0c07613e */
if(!s->budget--) { s->failed_pc=0x0c07613eu; return 0; }
goto P_0c076360;
P_0c076140: /* original 0009, guest PC 0x0c076140 */
if(!s->budget--) { s->failed_pc=0x0c076140u; return 0; }
goto P_0c076142;
P_0c076142: /* original e070, guest PC 0x0c076142 */
if(!s->budget--) { s->failed_pc=0x0c076142u; return 0; }
r[0]=0x00000070u;
goto P_0c076144;
P_0c076144: /* original d334, guest PC 0x0c076144 */
if(!s->budget--) { s->failed_pc=0x0c076144u; return 0; }
r[3]=read(ram,0x0c076218u,4);
goto P_0c076146;
P_0c076146: /* original 02fe, guest PC 0x0c076146 */
if(!s->budget--) { s->failed_pc=0x0c076146u; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c076148;
P_0c076148: /* original 2238, guest PC 0x0c076148 */
if(!s->budget--) { s->failed_pc=0x0c076148u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c07614a;
P_0c07614a: /* original 8b25, guest PC 0x0c07614a */
if(!s->budget--) { s->failed_pc=0x0c07614au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c076198; }
goto P_0c07614c;
P_0c07614c: /* original 904f, guest PC 0x0c07614c */
if(!s->budget--) { s->failed_pc=0x0c07614cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0761eeu,2);
goto P_0c07614e;
P_0c07614e: /* original e21e, guest PC 0x0c07614e */
if(!s->budget--) { s->failed_pc=0x0c07614eu; return 0; }
r[2]=0x0000001eu;
goto P_0c076150;
P_0c076150: /* original 6123, guest PC 0x0c076150 */
if(!s->budget--) { s->failed_pc=0x0c076150u; return 0; }
r[1]=r[2];
goto P_0c076152;
P_0c076152: /* original 0f26, guest PC 0x0c076152 */
if(!s->budget--) { s->failed_pc=0x0c076152u; return 0; }
write(ram,r[15]+r[0],r[2],4);
goto P_0c076154;
P_0c076154: /* original e054, guest PC 0x0c076154 */
if(!s->budget--) { s->failed_pc=0x0c076154u; return 0; }
r[0]=0x00000054u;
goto P_0c076156;
P_0c076156: /* original 02fe, guest PC 0x0c076156 */
if(!s->budget--) { s->failed_pc=0x0c076156u; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c076158;
P_0c076158: /* original 3212, guest PC 0x0c076158 */
if(!s->budget--) { s->failed_pc=0x0c076158u; return 0; }
r[17]=(r[17]&~1u)|((r[2]>=r[1])!=0);
goto P_0c07615a;
P_0c07615a: /* original 8b01, guest PC 0x0c07615a */
if(!s->budget--) { s->failed_pc=0x0c07615au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c076160; }
goto P_0c07615c;
P_0c07615c: /* original a100, guest PC 0x0c07615c */
if(!s->budget--) { s->failed_pc=0x0c07615cu; return 0; }
goto P_0c076360;
P_0c07615e: /* original 0009, guest PC 0x0c07615e */
if(!s->budget--) { s->failed_pc=0x0c07615eu; return 0; }
goto P_0c076160;
P_0c076160: /* original e070, guest PC 0x0c076160 */
if(!s->budget--) { s->failed_pc=0x0c076160u; return 0; }
r[0]=0x00000070u;
goto P_0c076162;
P_0c076162: /* original d32e, guest PC 0x0c076162 */
if(!s->budget--) { s->failed_pc=0x0c076162u; return 0; }
r[3]=read(ram,0x0c07621cu,4);
goto P_0c076164;
P_0c076164: /* original 02fe, guest PC 0x0c076164 */
if(!s->budget--) { s->failed_pc=0x0c076164u; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c076166;
P_0c076166: /* original 2238, guest PC 0x0c076166 */
if(!s->budget--) { s->failed_pc=0x0c076166u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c076168;
P_0c076168: /* original 8906, guest PC 0x0c076168 */
if(!s->budget--) { s->failed_pc=0x0c076168u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c076178; }
goto P_0c07616a;
P_0c07616a: /* original e05c, guest PC 0x0c07616a */
if(!s->budget--) { s->failed_pc=0x0c07616au; return 0; }
r[0]=0x0000005cu;
goto P_0c07616c;
P_0c07616c: /* original d22c, guest PC 0x0c07616c */
if(!s->budget--) { s->failed_pc=0x0c07616cu; return 0; }
r[2]=read(ram,0x0c076220u,4);
goto P_0c07616e;
P_0c07616e: /* original 01fe, guest PC 0x0c07616e */
if(!s->budget--) { s->failed_pc=0x0c07616eu; return 0; }
r[1]=read(ram,r[15]+r[0],4);
goto P_0c076170;
P_0c076170: /* original 2128, guest PC 0x0c076170 */
if(!s->budget--) { s->failed_pc=0x0c076170u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[2])==0)!=0);
goto P_0c076172;
P_0c076172: /* original 8b01, guest PC 0x0c076172 */
if(!s->budget--) { s->failed_pc=0x0c076172u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c076178; }
goto P_0c076174;
P_0c076174: /* original a0f4, guest PC 0x0c076174 */
if(!s->budget--) { s->failed_pc=0x0c076174u; return 0; }
goto P_0c076360;
P_0c076176: /* original 0009, guest PC 0x0c076176 */
if(!s->budget--) { s->failed_pc=0x0c076176u; return 0; }
goto P_0c076178;
P_0c076178: /* original e060, guest PC 0x0c076178 */
if(!s->budget--) { s->failed_pc=0x0c076178u; return 0; }
r[0]=0x00000060u;
goto P_0c07617a;
P_0c07617a: /* original 00fe, guest PC 0x0c07617a */
if(!s->budget--) { s->failed_pc=0x0c07617au; return 0; }
r[0]=read(ram,r[15]+r[0],4);
goto P_0c07617c;
P_0c07617c: /* original 8801, guest PC 0x0c07617c */
if(!s->budget--) { s->failed_pc=0x0c07617cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c07617e;
P_0c07617e: /* original 8b0b, guest PC 0x0c07617e */
if(!s->budget--) { s->failed_pc=0x0c07617eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c076198; }
goto P_0c076180;
P_0c076180: /* original e05c, guest PC 0x0c076180 */
if(!s->budget--) { s->failed_pc=0x0c076180u; return 0; }
r[0]=0x0000005cu;
goto P_0c076182;
P_0c076182: /* original 9335, guest PC 0x0c076182 */
if(!s->budget--) { s->failed_pc=0x0c076182u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0761f0u,2);
goto P_0c076184;
P_0c076184: /* original 02fe, guest PC 0x0c076184 */
if(!s->budget--) { s->failed_pc=0x0c076184u; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c076186;
P_0c076186: /* original 2238, guest PC 0x0c076186 */
if(!s->budget--) { s->failed_pc=0x0c076186u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c076188;
P_0c076188: /* original 8b06, guest PC 0x0c076188 */
if(!s->budget--) { s->failed_pc=0x0c076188u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c076198; }
goto P_0c07618a;
P_0c07618a: /* original 61f3, guest PC 0x0c07618a */
if(!s->budget--) { s->failed_pc=0x0c07618au; return 0; }
r[1]=r[15];
goto P_0c07618c;
P_0c07618c: /* original 715c, guest PC 0x0c07618c */
if(!s->budget--) { s->failed_pc=0x0c07618cu; return 0; }
r[1]+=0x0000005cu;
goto P_0c07618e;
P_0c07618e: /* original 6012, guest PC 0x0c07618e */
if(!s->budget--) { s->failed_pc=0x0c07618eu; return 0; }
tmp=read(ram,r[1],4);
r[0]=tmp;
goto P_0c076190;
P_0c076190: /* original c880, guest PC 0x0c076190 */
if(!s->budget--) { s->failed_pc=0x0c076190u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&128u)==0)!=0);
goto P_0c076192;
P_0c076192: /* original 8901, guest PC 0x0c076192 */
if(!s->budget--) { s->failed_pc=0x0c076192u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c076198; }
goto P_0c076194;
P_0c076194: /* original a0e4, guest PC 0x0c076194 */
if(!s->budget--) { s->failed_pc=0x0c076194u; return 0; }
goto P_0c076360;
P_0c076196: /* original 0009, guest PC 0x0c076196 */
if(!s->budget--) { s->failed_pc=0x0c076196u; return 0; }
goto P_0c076198;
P_0c076198: /* original 9025, guest PC 0x0c076198 */
if(!s->budget--) { s->failed_pc=0x0c076198u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0761e6u,2);
goto P_0c07619a;
P_0c07619a: /* original 03fe, guest PC 0x0c07619a */
if(!s->budget--) { s->failed_pc=0x0c07619au; return 0; }
r[3]=read(ram,r[15]+r[0],4);
goto P_0c07619c;
P_0c07619c: /* original e046, guest PC 0x0c07619c */
if(!s->budget--) { s->failed_pc=0x0c07619cu; return 0; }
r[0]=0x00000046u;
goto P_0c07619e;
P_0c07619e: /* original 023d, guest PC 0x0c07619e */
if(!s->budget--) { s->failed_pc=0x0c07619eu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[3]+r[0],2);
goto P_0c0761a0;
P_0c0761a0: /* original e054, guest PC 0x0c0761a0 */
if(!s->budget--) { s->failed_pc=0x0c0761a0u; return 0; }
r[0]=0x00000054u;
goto P_0c0761a2;
P_0c0761a2: /* original 03fe, guest PC 0x0c0761a2 */
if(!s->budget--) { s->failed_pc=0x0c0761a2u; return 0; }
r[3]=read(ram,r[15]+r[0],4);
goto P_0c0761a4;
P_0c0761a4: /* original 622d, guest PC 0x0c0761a4 */
if(!s->budget--) { s->failed_pc=0x0c0761a4u; return 0; }
r[2]=r[2]&65535u;
goto P_0c0761a6;
P_0c0761a6: /* original 3236, guest PC 0x0c0761a6 */
if(!s->budget--) { s->failed_pc=0x0c0761a6u; return 0; }
r[17]=(r[17]&~1u)|((r[2]>r[3])!=0);
goto P_0c0761a8;
P_0c0761a8: /* original 8901, guest PC 0x0c0761a8 */
if(!s->budget--) { s->failed_pc=0x0c0761a8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0761ae; }
goto P_0c0761aa;
P_0c0761aa: /* original a0d9, guest PC 0x0c0761aa */
if(!s->budget--) { s->failed_pc=0x0c0761aau; return 0; }
goto P_0c076360;
P_0c0761ac: /* original 0009, guest PC 0x0c0761ac */
if(!s->budget--) { s->failed_pc=0x0c0761acu; return 0; }
goto P_0c0761ae;
P_0c0761ae: /* original 62f3, guest PC 0x0c0761ae */
if(!s->budget--) { s->failed_pc=0x0c0761aeu; return 0; }
r[2]=r[15];
goto P_0c0761b0;
P_0c0761b0: /* original 725c, guest PC 0x0c0761b0 */
if(!s->budget--) { s->failed_pc=0x0c0761b0u; return 0; }
r[2]+=0x0000005cu;
goto P_0c0761b2;
P_0c0761b2: /* original e300, guest PC 0x0c0761b2 */
if(!s->budget--) { s->failed_pc=0x0c0761b2u; return 0; }
r[3]=0x00000000u;
goto P_0c0761b4;
P_0c0761b4: /* original 2f26, guest PC 0x0c0761b4 */
if(!s->budget--) { s->failed_pc=0x0c0761b4u; return 0; }
r[15]-=4; write(ram,r[15],r[2],4);
goto P_0c0761b6;
P_0c0761b6: /* original 2f36, guest PC 0x0c0761b6 */
if(!s->budget--) { s->failed_pc=0x0c0761b6u; return 0; }
r[15]-=4; write(ram,r[15],r[3],4);
goto P_0c0761b8;
P_0c0761b8: /* original 61f3, guest PC 0x0c0761b8 */
if(!s->budget--) { s->failed_pc=0x0c0761b8u; return 0; }
r[1]=r[15];
goto P_0c0761ba;
P_0c0761ba: /* original 7158, guest PC 0x0c0761ba */
if(!s->budget--) { s->failed_pc=0x0c0761bau; return 0; }
r[1]+=0x00000058u;
goto P_0c0761bc;
P_0c0761bc: /* original 6012, guest PC 0x0c0761bc */
if(!s->budget--) { s->failed_pc=0x0c0761bcu; return 0; }
tmp=read(ram,r[1],4);
r[0]=tmp;
goto P_0c0761be;
P_0c0761be: /* original 9718, guest PC 0x0c0761be */
if(!s->budget--) { s->failed_pc=0x0c0761beu; return 0; }
r[7]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0761f2u,2);
goto P_0c0761c0;
P_0c0761c0: /* original c91f, guest PC 0x0c0761c0 */
if(!s->budget--) { s->failed_pc=0x0c0761c0u; return 0; }
r[0]&=31u;
goto P_0c0761c2;
P_0c0761c2: /* original d218, guest PC 0x0c0761c2 */
if(!s->budget--) { s->failed_pc=0x0c0761c2u; return 0; }
r[2]=read(ram,0x0c076224u,4);
goto P_0c0761c4;
P_0c0761c4: /* original 6603, guest PC 0x0c0761c4 */
if(!s->budget--) { s->failed_pc=0x0c0761c4u; return 0; }
r[6]=r[0];
goto P_0c0761c6;
P_0c0761c6: /* original 9015, guest PC 0x0c0761c6 */
if(!s->budget--) { s->failed_pc=0x0c0761c6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0761f4u,2);
goto P_0c0761c8;
P_0c0761c8: /* original 37fc, guest PC 0x0c0761c8 */
if(!s->budget--) { s->failed_pc=0x0c0761c8u; return 0; }
r[7]+=r[15];
goto P_0c0761ca;
P_0c0761ca: /* original 05fe, guest PC 0x0c0761ca */
if(!s->budget--) { s->failed_pc=0x0c0761cau; return 0; }
r[5]=read(ram,r[15]+r[0],4);
goto P_0c0761cc;
P_0c0761cc: /* original 9013, guest PC 0x0c0761cc */
if(!s->budget--) { s->failed_pc=0x0c0761ccu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0761f6u,2);
goto P_0c0761ce;
P_0c0761ce: /* original 420b, guest PC 0x0c0761ce */
if(!s->budget--) { s->failed_pc=0x0c0761ceu; return 0; }
target=r[2];
r[16]=0x0c0761d2u;
r[4]=read(ram,r[15]+r[0],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0761d2u) { target=s->pc; goto dispatch; }
goto P_0c0761d2;
P_0c0761d0: /* original 04fe, guest PC 0x0c0761d0 */
if(!s->budget--) { s->failed_pc=0x0c0761d0u; return 0; }
r[4]=read(ram,r[15]+r[0],4);
goto P_0c0761d2;
P_0c0761d2: /* original 9008, guest PC 0x0c0761d2 */
if(!s->budget--) { s->failed_pc=0x0c0761d2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0761e6u,2);
goto P_0c0761d4;
P_0c0761d4: /* original 7f08, guest PC 0x0c0761d4 */
if(!s->budget--) { s->failed_pc=0x0c0761d4u; return 0; }
r[15]+=0x00000008u;
goto P_0c0761d6;
P_0c0761d6: /* original d214, guest PC 0x0c0761d6 */
if(!s->budget--) { s->failed_pc=0x0c0761d6u; return 0; }
r[2]=read(ram,0x0c076228u,4);
goto P_0c0761d8;
P_0c0761d8: /* original 03fe, guest PC 0x0c0761d8 */
if(!s->budget--) { s->failed_pc=0x0c0761d8u; return 0; }
r[3]=read(ram,r[15]+r[0],4);
goto P_0c0761da;
P_0c0761da: /* original 900d, guest PC 0x0c0761da */
if(!s->budget--) { s->failed_pc=0x0c0761dau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0761f8u,2);
goto P_0c0761dc;
P_0c0761dc: /* original 01fe, guest PC 0x0c0761dc */
if(!s->budget--) { s->failed_pc=0x0c0761dcu; return 0; }
r[1]=read(ram,r[15]+r[0],4);
goto P_0c0761de;
P_0c0761de: /* original 312c, guest PC 0x0c0761de */
if(!s->budget--) { s->failed_pc=0x0c0761deu; return 0; }
r[1]+=r[2];
goto P_0c0761e0;
P_0c0761e0: /* original 131d, guest PC 0x0c0761e0 */
if(!s->budget--) { s->failed_pc=0x0c0761e0u; return 0; }
write(ram,r[3]+52,r[1],4);
goto P_0c0761e2;
P_0c0761e2: /* original a023, guest PC 0x0c0761e2 */
if(!s->budget--) { s->failed_pc=0x0c0761e2u; return 0; }
goto P_0c07622c;
P_0c0761e4: /* original 0009, guest PC 0x0c0761e4 */
if(!s->budget--) { s->failed_pc=0x0c0761e4u; return 0; }
return vf3_matrix_family(0x0c0761e6u,s,ram);
P_0c07622c: /* original e050, guest PC 0x0c07622c */
if(!s->budget--) { s->failed_pc=0x0c07622cu; return 0; }
r[0]=0x00000050u;
goto P_0c07622e;
P_0c07622e: /* original 00fe, guest PC 0x0c07622e */
if(!s->budget--) { s->failed_pc=0x0c07622eu; return 0; }
r[0]=read(ram,r[15]+r[0],4);
goto P_0c076230;
P_0c076230: /* original 8803, guest PC 0x0c076230 */
if(!s->budget--) { s->failed_pc=0x0c076230u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000003u)!=0);
goto P_0c076232;
P_0c076232: /* original 8b07, guest PC 0x0c076232 */
if(!s->budget--) { s->failed_pc=0x0c076232u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c076244; }
goto P_0c076234;
P_0c076234: /* original 907a, guest PC 0x0c076234 */
if(!s->budget--) { s->failed_pc=0x0c076234u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07632cu,2);
goto P_0c076236;
P_0c076236: /* original 01fe, guest PC 0x0c076236 */
if(!s->budget--) { s->failed_pc=0x0c076236u; return 0; }
r[1]=read(ram,r[15]+r[0],4);
goto P_0c076238;
P_0c076238: /* original 9079, guest PC 0x0c076238 */
if(!s->budget--) { s->failed_pc=0x0c076238u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07632eu,2);
goto P_0c07623a;
P_0c07623a: /* original 031c, guest PC 0x0c07623a */
if(!s->budget--) { s->failed_pc=0x0c07623au; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[1]+r[0],1);
goto P_0c07623c;
P_0c07623c: /* original 9078, guest PC 0x0c07623c */
if(!s->budget--) { s->failed_pc=0x0c07623cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c076330u,2);
goto P_0c07623e;
P_0c07623e: /* original 633c, guest PC 0x0c07623e */
if(!s->budget--) { s->failed_pc=0x0c07623eu; return 0; }
r[3]=r[3]&255u;
goto P_0c076240;
P_0c076240: /* original a007, guest PC 0x0c076240 */
if(!s->budget--) { s->failed_pc=0x0c076240u; return 0; }
write(ram,r[15]+r[0],r[3],4);
goto P_0c076252;
P_0c076242: /* original 0f36, guest PC 0x0c076242 */
if(!s->budget--) { s->failed_pc=0x0c076242u; return 0; }
write(ram,r[15]+r[0],r[3],4);
goto P_0c076244;
P_0c076244: /* original 9072, guest PC 0x0c076244 */
if(!s->budget--) { s->failed_pc=0x0c076244u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07632cu,2);
goto P_0c076246;
P_0c076246: /* original 03fe, guest PC 0x0c076246 */
if(!s->budget--) { s->failed_pc=0x0c076246u; return 0; }
r[3]=read(ram,r[15]+r[0],4);
goto P_0c076248;
P_0c076248: /* original 9073, guest PC 0x0c076248 */
if(!s->budget--) { s->failed_pc=0x0c076248u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c076332u,2);
goto P_0c07624a;
P_0c07624a: /* original 013c, guest PC 0x0c07624a */
if(!s->budget--) { s->failed_pc=0x0c07624au; return 0; }
r[1]=(uint32_t)(int32_t)(int8_t)read(ram,r[3]+r[0],1);
goto P_0c07624c;
P_0c07624c: /* original 9070, guest PC 0x0c07624c */
if(!s->budget--) { s->failed_pc=0x0c07624cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c076330u,2);
goto P_0c07624e;
P_0c07624e: /* original 611c, guest PC 0x0c07624e */
if(!s->budget--) { s->failed_pc=0x0c07624eu; return 0; }
r[1]=r[1]&255u;
goto P_0c076250;
P_0c076250: /* original 0f16, guest PC 0x0c076250 */
if(!s->budget--) { s->failed_pc=0x0c076250u; return 0; }
write(ram,r[15]+r[0],r[1],4);
goto P_0c076252;
P_0c076252: /* original 906d, guest PC 0x0c076252 */
if(!s->budget--) { s->failed_pc=0x0c076252u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c076330u,2);
goto P_0c076254;
P_0c076254: /* original 03fe, guest PC 0x0c076254 */
if(!s->budget--) { s->failed_pc=0x0c076254u; return 0; }
r[3]=read(ram,r[15]+r[0],4);
goto P_0c076256;
P_0c076256: /* original 2338, guest PC 0x0c076256 */
if(!s->budget--) { s->failed_pc=0x0c076256u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c076258;
P_0c076258: /* original 8b0c, guest PC 0x0c076258 */
if(!s->budget--) { s->failed_pc=0x0c076258u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c076274; }
goto P_0c07625a;
P_0c07625a: /* original e054, guest PC 0x0c07625a */
if(!s->budget--) { s->failed_pc=0x0c07625au; return 0; }
r[0]=0x00000054u;
goto P_0c07625c;
P_0c07625c: /* original 03fe, guest PC 0x0c07625c */
if(!s->budget--) { s->failed_pc=0x0c07625cu; return 0; }
r[3]=read(ram,r[15]+r[0],4);
goto P_0c07625e;
P_0c07625e: /* original 9067, guest PC 0x0c07625e */
if(!s->budget--) { s->failed_pc=0x0c07625eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c076330u,2);
goto P_0c076260;
P_0c076260: /* original 4308, guest PC 0x0c076260 */
if(!s->budget--) { s->failed_pc=0x0c076260u; return 0; }
r[3]<<=2;
goto P_0c076262;
P_0c076262: /* original 0f36, guest PC 0x0c076262 */
if(!s->budget--) { s->failed_pc=0x0c076262u; return 0; }
write(ram,r[15]+r[0],r[3],4);
goto P_0c076264;
P_0c076264: /* original e005, guest PC 0x0c076264 */
if(!s->budget--) { s->failed_pc=0x0c076264u; return 0; }
r[0]=0x00000005u;
goto P_0c076266;
P_0c076266: /* original d238, guest PC 0x0c076266 */
if(!s->budget--) { s->failed_pc=0x0c076266u; return 0; }
r[2]=read(ram,0x0c076348u,4);
goto P_0c076268;
P_0c076268: /* original 420b, guest PC 0x0c076268 */
if(!s->budget--) { s->failed_pc=0x0c076268u; return 0; }
target=r[2];
r[16]=0x0c07626cu;
r[1]=r[3];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07626cu) { target=s->pc; goto dispatch; }
goto P_0c07626c;
P_0c07626a: /* original 6133, guest PC 0x0c07626a */
if(!s->budget--) { s->failed_pc=0x0c07626au; return 0; }
r[1]=r[3];
goto P_0c07626c;
P_0c07626c: /* original 6303, guest PC 0x0c07626c */
if(!s->budget--) { s->failed_pc=0x0c07626cu; return 0; }
r[3]=r[0];
goto P_0c07626e;
P_0c07626e: /* original 905f, guest PC 0x0c07626e */
if(!s->budget--) { s->failed_pc=0x0c07626eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c076330u,2);
goto P_0c076270;
P_0c076270: /* original 7306, guest PC 0x0c076270 */
if(!s->budget--) { s->failed_pc=0x0c076270u; return 0; }
r[3]+=0x00000006u;
goto P_0c076272;
P_0c076272: /* original 0f36, guest PC 0x0c076272 */
if(!s->budget--) { s->failed_pc=0x0c076272u; return 0; }
write(ram,r[15]+r[0],r[3],4);
goto P_0c076274;
P_0c076274: /* original 905e, guest PC 0x0c076274 */
if(!s->budget--) { s->failed_pc=0x0c076274u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c076334u,2);
goto P_0c076276;
P_0c076276: /* original 02fe, guest PC 0x0c076276 */
if(!s->budget--) { s->failed_pc=0x0c076276u; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c076278;
P_0c076278: /* original 905a, guest PC 0x0c076278 */
if(!s->budget--) { s->failed_pc=0x0c076278u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c076330u,2);
goto P_0c07627a;
P_0c07627a: /* original 03fd, guest PC 0x0c07627a */
if(!s->budget--) { s->failed_pc=0x0c07627au; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+r[0],2);
goto P_0c07627c;
P_0c07627c: /* original e066, guest PC 0x0c07627c */
if(!s->budget--) { s->failed_pc=0x0c07627cu; return 0; }
r[0]=0x00000066u;
goto P_0c07627e;
P_0c07627e: /* original 0235, guest PC 0x0c07627e */
if(!s->budget--) { s->failed_pc=0x0c07627eu; return 0; }
write(ram,r[2]+r[0],r[3],2);
goto P_0c076280;
P_0c076280: /* original 9056, guest PC 0x0c076280 */
if(!s->budget--) { s->failed_pc=0x0c076280u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c076330u,2);
goto P_0c076282;
P_0c076282: /* original 02fe, guest PC 0x0c076282 */
if(!s->budget--) { s->failed_pc=0x0c076282u; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c076284;
P_0c076284: /* original 9057, guest PC 0x0c076284 */
if(!s->budget--) { s->failed_pc=0x0c076284u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c076336u,2);
goto P_0c076286;
P_0c076286: /* original 7208, guest PC 0x0c076286 */
if(!s->budget--) { s->failed_pc=0x0c076286u; return 0; }
r[2]+=0x00000008u;
goto P_0c076288;
P_0c076288: /* original 0f26, guest PC 0x0c076288 */
if(!s->budget--) { s->failed_pc=0x0c076288u; return 0; }
write(ram,r[15]+r[0],r[2],4);
goto P_0c07628a;
P_0c07628a: /* original e050, guest PC 0x0c07628a */
if(!s->budget--) { s->failed_pc=0x0c07628au; return 0; }
r[0]=0x00000050u;
goto P_0c07628c;
P_0c07628c: /* original 00fe, guest PC 0x0c07628c */
if(!s->budget--) { s->failed_pc=0x0c07628cu; return 0; }
r[0]=read(ram,r[15]+r[0],4);
goto P_0c07628e;
P_0c07628e: /* original 8803, guest PC 0x0c07628e */
if(!s->budget--) { s->failed_pc=0x0c07628eu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000003u)!=0);
goto P_0c076290;
P_0c076290: /* original 8b04, guest PC 0x0c076290 */
if(!s->budget--) { s->failed_pc=0x0c076290u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07629c; }
goto P_0c076292;
P_0c076292: /* original 904d, guest PC 0x0c076292 */
if(!s->budget--) { s->failed_pc=0x0c076292u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c076330u,2);
goto P_0c076294;
P_0c076294: /* original 01fe, guest PC 0x0c076294 */
if(!s->budget--) { s->failed_pc=0x0c076294u; return 0; }
r[1]=read(ram,r[15]+r[0],4);
goto P_0c076296;
P_0c076296: /* original 904e, guest PC 0x0c076296 */
if(!s->budget--) { s->failed_pc=0x0c076296u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c076336u,2);
goto P_0c076298;
P_0c076298: /* original 71ff, guest PC 0x0c076298 */
if(!s->budget--) { s->failed_pc=0x0c076298u; return 0; }
r[1]+=0xffffffffu;
goto P_0c07629a;
P_0c07629a: /* original 0f16, guest PC 0x0c07629a */
if(!s->budget--) { s->failed_pc=0x0c07629au; return 0; }
write(ram,r[15]+r[0],r[1],4);
goto P_0c07629c;
P_0c07629c: /* original 904b, guest PC 0x0c07629c */
if(!s->budget--) { s->failed_pc=0x0c07629cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c076336u,2);
goto P_0c07629e;
P_0c07629e: /* original 03fe, guest PC 0x0c07629e */
if(!s->budget--) { s->failed_pc=0x0c07629eu; return 0; }
r[3]=read(ram,r[15]+r[0],4);
goto P_0c0762a0;
P_0c0762a0: /* original 9049, guest PC 0x0c0762a0 */
if(!s->budget--) { s->failed_pc=0x0c0762a0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c076336u,2);
goto P_0c0762a2;
P_0c0762a2: /* original 7301, guest PC 0x0c0762a2 */
if(!s->budget--) { s->failed_pc=0x0c0762a2u; return 0; }
r[3]+=0x00000001u;
goto P_0c0762a4;
P_0c0762a4: /* original 0f36, guest PC 0x0c0762a4 */
if(!s->budget--) { s->failed_pc=0x0c0762a4u; return 0; }
write(ram,r[15]+r[0],r[3],4);
goto P_0c0762a6;
P_0c0762a6: /* original 9045, guest PC 0x0c0762a6 */
if(!s->budget--) { s->failed_pc=0x0c0762a6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c076334u,2);
goto P_0c0762a8;
P_0c0762a8: /* original 02fe, guest PC 0x0c0762a8 */
if(!s->budget--) { s->failed_pc=0x0c0762a8u; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c0762aa;
P_0c0762aa: /* original 9044, guest PC 0x0c0762aa */
if(!s->budget--) { s->failed_pc=0x0c0762aau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c076336u,2);
goto P_0c0762ac;
P_0c0762ac: /* original 03fc, guest PC 0x0c0762ac */
if(!s->budget--) { s->failed_pc=0x0c0762acu; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[15]+r[0],1);
goto P_0c0762ae;
P_0c0762ae: /* original 9043, guest PC 0x0c0762ae */
if(!s->budget--) { s->failed_pc=0x0c0762aeu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c076338u,2);
goto P_0c0762b0;
P_0c0762b0: /* original 0234, guest PC 0x0c0762b0 */
if(!s->budget--) { s->failed_pc=0x0c0762b0u; return 0; }
write(ram,r[2]+r[0],r[3],1);
goto P_0c0762b2;
P_0c0762b2: /* original 903b, guest PC 0x0c0762b2 */
if(!s->budget--) { s->failed_pc=0x0c0762b2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07632cu,2);
goto P_0c0762b4;
P_0c0762b4: /* original 02fe, guest PC 0x0c0762b4 */
if(!s->budget--) { s->failed_pc=0x0c0762b4u; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c0762b6;
P_0c0762b6: /* original 903e, guest PC 0x0c0762b6 */
if(!s->budget--) { s->failed_pc=0x0c0762b6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c076336u,2);
goto P_0c0762b8;
P_0c0762b8: /* original 03fc, guest PC 0x0c0762b8 */
if(!s->budget--) { s->failed_pc=0x0c0762b8u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[15]+r[0],1);
goto P_0c0762ba;
P_0c0762ba: /* original 903d, guest PC 0x0c0762ba */
if(!s->budget--) { s->failed_pc=0x0c0762bau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c076338u,2);
goto P_0c0762bc;
P_0c0762bc: /* original 0234, guest PC 0x0c0762bc */
if(!s->budget--) { s->failed_pc=0x0c0762bcu; return 0; }
write(ram,r[2]+r[0],r[3],1);
goto P_0c0762be;
P_0c0762be: /* original e200, guest PC 0x0c0762be */
if(!s->budget--) { s->failed_pc=0x0c0762beu; return 0; }
r[2]=0x00000000u;
goto P_0c0762c0;
P_0c0762c0: /* original e074, guest PC 0x0c0762c0 */
if(!s->budget--) { s->failed_pc=0x0c0762c0u; return 0; }
r[0]=0x00000074u;
goto P_0c0762c2;
P_0c0762c2: /* original a1f8, guest PC 0x0c0762c2 */
if(!s->budget--) { s->failed_pc=0x0c0762c2u; return 0; }
write(ram,r[15]+r[0],r[2],4);
goto P_0c0766b6;
P_0c0762c4: /* original 0f26, guest PC 0x0c0762c4 */
if(!s->budget--) { s->failed_pc=0x0c0762c4u; return 0; }
write(ram,r[15]+r[0],r[2],4);
goto P_0c0762c6;
P_0c0762c6: /* original 9031, guest PC 0x0c0762c6 */
if(!s->budget--) { s->failed_pc=0x0c0762c6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07632cu,2);
goto P_0c0762c8;
P_0c0762c8: /* original 9337, guest PC 0x0c0762c8 */
if(!s->budget--) { s->failed_pc=0x0c0762c8u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07633au,2);
goto P_0c0762ca;
P_0c0762ca: /* original 01fe, guest PC 0x0c0762ca */
if(!s->budget--) { s->failed_pc=0x0c0762cau; return 0; }
r[1]=read(ram,r[15]+r[0],4);
goto P_0c0762cc;
P_0c0762cc: /* original e048, guest PC 0x0c0762cc */
if(!s->budget--) { s->failed_pc=0x0c0762ccu; return 0; }
r[0]=0x00000048u;
goto P_0c0762ce;
P_0c0762ce: /* original 021e, guest PC 0x0c0762ce */
if(!s->budget--) { s->failed_pc=0x0c0762ceu; return 0; }
r[2]=read(ram,r[1]+r[0],4);
goto P_0c0762d0;
P_0c0762d0: /* original 2238, guest PC 0x0c0762d0 */
if(!s->budget--) { s->failed_pc=0x0c0762d0u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0762d2;
P_0c0762d2: /* original 8945, guest PC 0x0c0762d2 */
if(!s->budget--) { s->failed_pc=0x0c0762d2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c076360; }
goto P_0c0762d4;
P_0c0762d4: /* original 902a, guest PC 0x0c0762d4 */
if(!s->budget--) { s->failed_pc=0x0c0762d4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07632cu,2);
goto P_0c0762d6;
P_0c0762d6: /* original e208, guest PC 0x0c0762d6 */
if(!s->budget--) { s->failed_pc=0x0c0762d6u; return 0; }
r[2]=0x00000008u;
goto P_0c0762d8;
P_0c0762d8: /* original e605, guest PC 0x0c0762d8 */
if(!s->budget--) { s->failed_pc=0x0c0762d8u; return 0; }
r[6]=0x00000005u;
goto P_0c0762da;
P_0c0762da: /* original 03fe, guest PC 0x0c0762da */
if(!s->budget--) { s->failed_pc=0x0c0762dau; return 0; }
r[3]=read(ram,r[15]+r[0],4);
goto P_0c0762dc;
P_0c0762dc: /* original 902e, guest PC 0x0c0762dc */
if(!s->budget--) { s->failed_pc=0x0c0762dcu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07633cu,2);
goto P_0c0762de;
P_0c0762de: /* original 013e, guest PC 0x0c0762de */
if(!s->budget--) { s->failed_pc=0x0c0762deu; return 0; }
r[1]=read(ram,r[3]+r[0],4);
goto P_0c0762e0;
P_0c0762e0: /* original 212b, guest PC 0x0c0762e0 */
if(!s->budget--) { s->failed_pc=0x0c0762e0u; return 0; }
r[1]|=r[2];
goto P_0c0762e2;
P_0c0762e2: /* original 0316, guest PC 0x0c0762e2 */
if(!s->budget--) { s->failed_pc=0x0c0762e2u; return 0; }
write(ram,r[3]+r[0],r[1],4);
goto P_0c0762e4;
P_0c0762e4: /* original 63f3, guest PC 0x0c0762e4 */
if(!s->budget--) { s->failed_pc=0x0c0762e4u; return 0; }
r[3]=r[15];
goto P_0c0762e6;
P_0c0762e6: /* original 735c, guest PC 0x0c0762e6 */
if(!s->budget--) { s->failed_pc=0x0c0762e6u; return 0; }
r[3]+=0x0000005cu;
goto P_0c0762e8;
P_0c0762e8: /* original e100, guest PC 0x0c0762e8 */
if(!s->budget--) { s->failed_pc=0x0c0762e8u; return 0; }
r[1]=0x00000000u;
goto P_0c0762ea;
P_0c0762ea: /* original 2f36, guest PC 0x0c0762ea */
if(!s->budget--) { s->failed_pc=0x0c0762eau; return 0; }
r[15]-=4; write(ram,r[15],r[3],4);
goto P_0c0762ec;
P_0c0762ec: /* original 2f16, guest PC 0x0c0762ec */
if(!s->budget--) { s->failed_pc=0x0c0762ecu; return 0; }
r[15]-=4; write(ram,r[15],r[1],4);
goto P_0c0762ee;
P_0c0762ee: /* original 9027, guest PC 0x0c0762ee */
if(!s->budget--) { s->failed_pc=0x0c0762eeu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c076340u,2);
goto P_0c0762f0;
P_0c0762f0: /* original 9725, guest PC 0x0c0762f0 */
if(!s->budget--) { s->failed_pc=0x0c0762f0u; return 0; }
r[7]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07633eu,2);
goto P_0c0762f2;
P_0c0762f2: /* original 05fe, guest PC 0x0c0762f2 */
if(!s->budget--) { s->failed_pc=0x0c0762f2u; return 0; }
r[5]=read(ram,r[15]+r[0],4);
goto P_0c0762f4;
P_0c0762f4: /* original d315, guest PC 0x0c0762f4 */
if(!s->budget--) { s->failed_pc=0x0c0762f4u; return 0; }
r[3]=read(ram,0x0c07634cu,4);
goto P_0c0762f6;
P_0c0762f6: /* original 37fc, guest PC 0x0c0762f6 */
if(!s->budget--) { s->failed_pc=0x0c0762f6u; return 0; }
r[7]+=r[15];
goto P_0c0762f8;
P_0c0762f8: /* original 9023, guest PC 0x0c0762f8 */
if(!s->budget--) { s->failed_pc=0x0c0762f8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c076342u,2);
goto P_0c0762fa;
P_0c0762fa: /* original 430b, guest PC 0x0c0762fa */
if(!s->budget--) { s->failed_pc=0x0c0762fau; return 0; }
target=r[3];
r[16]=0x0c0762feu;
r[4]=read(ram,r[15]+r[0],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0762feu) { target=s->pc; goto dispatch; }
goto P_0c0762fe;
P_0c0762fc: /* original 04fe, guest PC 0x0c0762fc */
if(!s->budget--) { s->failed_pc=0x0c0762fcu; return 0; }
r[4]=read(ram,r[15]+r[0],4);
goto P_0c0762fe;
P_0c0762fe: /* original 9019, guest PC 0x0c0762fe */
if(!s->budget--) { s->failed_pc=0x0c0762feu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c076334u,2);
goto P_0c076300;
P_0c076300: /* original 7f08, guest PC 0x0c076300 */
if(!s->budget--) { s->failed_pc=0x0c076300u; return 0; }
r[15]+=0x00000008u;
goto P_0c076302;
P_0c076302: /* original d313, guest PC 0x0c076302 */
if(!s->budget--) { s->failed_pc=0x0c076302u; return 0; }
r[3]=read(ram,0x0c076350u,4);
goto P_0c076304;
P_0c076304: /* original 02fe, guest PC 0x0c076304 */
if(!s->budget--) { s->failed_pc=0x0c076304u; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c076306;
P_0c076306: /* original 901d, guest PC 0x0c076306 */
if(!s->budget--) { s->failed_pc=0x0c076306u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c076344u,2);
goto P_0c076308;
P_0c076308: /* original 01fe, guest PC 0x0c076308 */
if(!s->budget--) { s->failed_pc=0x0c076308u; return 0; }
r[1]=read(ram,r[15]+r[0],4);
goto P_0c07630a;
P_0c07630a: /* original e054, guest PC 0x0c07630a */
if(!s->budget--) { s->failed_pc=0x0c07630au; return 0; }
r[0]=0x00000054u;
goto P_0c07630c;
P_0c07630c: /* original 313c, guest PC 0x0c07630c */
if(!s->budget--) { s->failed_pc=0x0c07630cu; return 0; }
r[1]+=r[3];
goto P_0c07630e;
P_0c07630e: /* original 121d, guest PC 0x0c07630e */
if(!s->budget--) { s->failed_pc=0x0c07630eu; return 0; }
write(ram,r[2]+52,r[1],4);
goto P_0c076310;
P_0c076310: /* original 02fe, guest PC 0x0c076310 */
if(!s->budget--) { s->failed_pc=0x0c076310u; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c076312;
P_0c076312: /* original 72f2, guest PC 0x0c076312 */
if(!s->budget--) { s->failed_pc=0x0c076312u; return 0; }
r[2]+=0xfffffff2u;
goto P_0c076314;
P_0c076314: /* original 4211, guest PC 0x0c076314 */
if(!s->budget--) { s->failed_pc=0x0c076314u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>=0)!=0);
goto P_0c076316;
P_0c076316: /* original 8d02, guest PC 0x0c076316 */
if(!s->budget--) { s->failed_pc=0x0c076316u; return 0; }
cond=r[17]&1u;
write(ram,r[15]+60,r[2],4);
if(cond) { goto P_0c07631e; }
goto P_0c07631a;
P_0c076318: /* original 1f2f, guest PC 0x0c076318 */
if(!s->budget--) { s->failed_pc=0x0c076318u; return 0; }
write(ram,r[15]+60,r[2],4);
goto P_0c07631a;
P_0c07631a: /* original e000, guest PC 0x0c07631a */
if(!s->budget--) { s->failed_pc=0x0c07631au; return 0; }
r[0]=0x00000000u;
goto P_0c07631c;
P_0c07631c: /* original 1f0f, guest PC 0x0c07631c */
if(!s->budget--) { s->failed_pc=0x0c07631cu; return 0; }
write(ram,r[15]+60,r[0],4);
goto P_0c07631e;
P_0c07631e: /* original 9009, guest PC 0x0c07631e */
if(!s->budget--) { s->failed_pc=0x0c07631eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c076334u,2);
goto P_0c076320;
P_0c076320: /* original 52ff, guest PC 0x0c076320 */
if(!s->budget--) { s->failed_pc=0x0c076320u; return 0; }
r[2]=read(ram,r[15]+60,4);
goto P_0c076322;
P_0c076322: /* original 03fe, guest PC 0x0c076322 */
if(!s->budget--) { s->failed_pc=0x0c076322u; return 0; }
r[3]=read(ram,r[15]+r[0],4);
goto P_0c076324;
P_0c076324: /* original e066, guest PC 0x0c076324 */
if(!s->budget--) { s->failed_pc=0x0c076324u; return 0; }
r[0]=0x00000066u;
goto P_0c076326;
P_0c076326: /* original 0325, guest PC 0x0c076326 */
if(!s->budget--) { s->failed_pc=0x0c076326u; return 0; }
write(ram,r[3]+r[0],r[2],2);
goto P_0c076328;
P_0c076328: /* original a239, guest PC 0x0c076328 */
if(!s->budget--) { s->failed_pc=0x0c076328u; return 0; }
goto P_0c07679e;
P_0c07632a: /* original 0009, guest PC 0x0c07632a */
if(!s->budget--) { s->failed_pc=0x0c07632au; return 0; }
return vf3_matrix_family(0x0c07632cu,s,ram);
P_0c076354: /* original 906c, guest PC 0x0c076354 */
if(!s->budget--) { s->failed_pc=0x0c076354u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c076430u,2);
goto P_0c076356;
P_0c076356: /* original 01fe, guest PC 0x0c076356 */
if(!s->budget--) { s->failed_pc=0x0c076356u; return 0; }
r[1]=read(ram,r[15]+r[0],4);
goto P_0c076358;
P_0c076358: /* original 906b, guest PC 0x0c076358 */
if(!s->budget--) { s->failed_pc=0x0c076358u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c076432u,2);
goto P_0c07635a;
P_0c07635a: /* original 031c, guest PC 0x0c07635a */
if(!s->budget--) { s->failed_pc=0x0c07635au; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[1]+r[0],1);
goto P_0c07635c;
P_0c07635c: /* original 7301, guest PC 0x0c07635c */
if(!s->budget--) { s->failed_pc=0x0c07635cu; return 0; }
r[3]+=0x00000001u;
goto P_0c07635e;
P_0c07635e: /* original 0134, guest PC 0x0c07635e */
if(!s->budget--) { s->failed_pc=0x0c07635eu; return 0; }
write(ram,r[1]+r[0],r[3],1);
goto P_0c076360;
P_0c076360: /* original 9066, guest PC 0x0c076360 */
if(!s->budget--) { s->failed_pc=0x0c076360u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c076430u,2);
goto P_0c076362;
P_0c076362: /* original 02fe, guest PC 0x0c076362 */
if(!s->budget--) { s->failed_pc=0x0c076362u; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c076364;
P_0c076364: /* original e060, guest PC 0x0c076364 */
if(!s->budget--) { s->failed_pc=0x0c076364u; return 0; }
r[0]=0x00000060u;
goto P_0c076366;
P_0c076366: /* original 032c, guest PC 0x0c076366 */
if(!s->budget--) { s->failed_pc=0x0c076366u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[2]+r[0],1);
goto P_0c076368;
P_0c076368: /* original d038, guest PC 0x0c076368 */
if(!s->budget--) { s->failed_pc=0x0c076368u; return 0; }
r[0]=read(ram,0x0c07644cu,4);
goto P_0c07636a;
P_0c07636a: /* original 633c, guest PC 0x0c07636a */
if(!s->budget--) { s->failed_pc=0x0c07636au; return 0; }
r[3]=r[3]&255u;
goto P_0c07636c;
P_0c07636c: /* original 023c, guest PC 0x0c07636c */
if(!s->budget--) { s->failed_pc=0x0c07636cu; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[3]+r[0],1);
goto P_0c07636e;
P_0c07636e: /* original 2228, guest PC 0x0c07636e */
if(!s->budget--) { s->failed_pc=0x0c07636eu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c076370;
P_0c076370: /* original 8906, guest PC 0x0c076370 */
if(!s->budget--) { s->failed_pc=0x0c076370u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c076380; }
goto P_0c076372;
P_0c076372: /* original 905d, guest PC 0x0c076372 */
if(!s->budget--) { s->failed_pc=0x0c076372u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c076430u,2);
goto P_0c076374;
P_0c076374: /* original e201, guest PC 0x0c076374 */
if(!s->budget--) { s->failed_pc=0x0c076374u; return 0; }
r[2]=0x00000001u;
goto P_0c076376;
P_0c076376: /* original 03fe, guest PC 0x0c076376 */
if(!s->budget--) { s->failed_pc=0x0c076376u; return 0; }
r[3]=read(ram,r[15]+r[0],4);
goto P_0c076378;
P_0c076378: /* original 905c, guest PC 0x0c076378 */
if(!s->budget--) { s->failed_pc=0x0c076378u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c076434u,2);
goto P_0c07637a;
P_0c07637a: /* original 013e, guest PC 0x0c07637a */
if(!s->budget--) { s->failed_pc=0x0c07637au; return 0; }
r[1]=read(ram,r[3]+r[0],4);
goto P_0c07637c;
P_0c07637c: /* original 212b, guest PC 0x0c07637c */
if(!s->budget--) { s->failed_pc=0x0c07637cu; return 0; }
r[1]|=r[2];
goto P_0c07637e;
P_0c07637e: /* original 0316, guest PC 0x0c07637e */
if(!s->budget--) { s->failed_pc=0x0c07637eu; return 0; }
write(ram,r[3]+r[0],r[1],4);
goto P_0c076380;
P_0c076380: /* original 9059, guest PC 0x0c076380 */
if(!s->budget--) { s->failed_pc=0x0c076380u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c076436u,2);
goto P_0c076382;
P_0c076382: /* original e208, guest PC 0x0c076382 */
if(!s->budget--) { s->failed_pc=0x0c076382u; return 0; }
r[2]=0x00000008u;
goto P_0c076384;
P_0c076384: /* original 03fe, guest PC 0x0c076384 */
if(!s->budget--) { s->failed_pc=0x0c076384u; return 0; }
r[3]=read(ram,r[15]+r[0],4);
goto P_0c076386;
P_0c076386: /* original 9057, guest PC 0x0c076386 */
if(!s->budget--) { s->failed_pc=0x0c076386u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c076438u,2);
goto P_0c076388;
P_0c076388: /* original 013e, guest PC 0x0c076388 */
if(!s->budget--) { s->failed_pc=0x0c076388u; return 0; }
r[1]=read(ram,r[3]+r[0],4);
goto P_0c07638a;
P_0c07638a: /* original 212b, guest PC 0x0c07638a */
if(!s->budget--) { s->failed_pc=0x0c07638au; return 0; }
r[1]|=r[2];
goto P_0c07638c;
P_0c07638c: /* original 0316, guest PC 0x0c07638c */
if(!s->budget--) { s->failed_pc=0x0c07638cu; return 0; }
write(ram,r[3]+r[0],r[1],4);
goto P_0c07638e;
P_0c07638e: /* original 9052, guest PC 0x0c07638e */
if(!s->budget--) { s->failed_pc=0x0c07638eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c076436u,2);
goto P_0c076390;
P_0c076390: /* original 03fe, guest PC 0x0c076390 */
if(!s->budget--) { s->failed_pc=0x0c076390u; return 0; }
r[3]=read(ram,r[15]+r[0],4);
goto P_0c076392;
P_0c076392: /* original e048, guest PC 0x0c076392 */
if(!s->budget--) { s->failed_pc=0x0c076392u; return 0; }
r[0]=0x00000048u;
goto P_0c076394;
P_0c076394: /* original 013e, guest PC 0x0c076394 */
if(!s->budget--) { s->failed_pc=0x0c076394u; return 0; }
r[1]=read(ram,r[3]+r[0],4);
goto P_0c076396;
P_0c076396: /* original 9050, guest PC 0x0c076396 */
if(!s->budget--) { s->failed_pc=0x0c076396u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07643au,2);
goto P_0c076398;
P_0c076398: /* original 0f16, guest PC 0x0c076398 */
if(!s->budget--) { s->failed_pc=0x0c076398u; return 0; }
write(ram,r[15]+r[0],r[1],4);
goto P_0c07639a;
P_0c07639a: /* original 934f, guest PC 0x0c07639a */
if(!s->budget--) { s->failed_pc=0x0c07639au; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07643cu,2);
goto P_0c07639c;
P_0c07639c: /* original 2138, guest PC 0x0c07639c */
if(!s->budget--) { s->failed_pc=0x0c07639cu; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[3])==0)!=0);
goto P_0c07639e;
P_0c07639e: /* original 8909, guest PC 0x0c07639e */
if(!s->budget--) { s->failed_pc=0x0c07639eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0763b4; }
goto P_0c0763a0;
P_0c0763a0: /* original 904b, guest PC 0x0c0763a0 */
if(!s->budget--) { s->failed_pc=0x0c0763a0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07643au,2);
goto P_0c0763a2;
P_0c0763a2: /* original d12b, guest PC 0x0c0763a2 */
if(!s->budget--) { s->failed_pc=0x0c0763a2u; return 0; }
r[1]=read(ram,0x0c076450u,4);
goto P_0c0763a4;
P_0c0763a4: /* original 00fe, guest PC 0x0c0763a4 */
if(!s->budget--) { s->failed_pc=0x0c0763a4u; return 0; }
r[0]=read(ram,r[15]+r[0],4);
goto P_0c0763a6;
P_0c0763a6: /* original 2018, guest PC 0x0c0763a6 */
if(!s->budget--) { s->failed_pc=0x0c0763a6u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[1])==0)!=0);
goto P_0c0763a8;
P_0c0763a8: /* original 8b04, guest PC 0x0c0763a8 */
if(!s->budget--) { s->failed_pc=0x0c0763a8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0763b4; }
goto P_0c0763aa;
P_0c0763aa: /* original 9046, guest PC 0x0c0763aa */
if(!s->budget--) { s->failed_pc=0x0c0763aau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07643au,2);
goto P_0c0763ac;
P_0c0763ac: /* original d329, guest PC 0x0c0763ac */
if(!s->budget--) { s->failed_pc=0x0c0763acu; return 0; }
r[3]=read(ram,0x0c076454u,4);
goto P_0c0763ae;
P_0c0763ae: /* original 02fe, guest PC 0x0c0763ae */
if(!s->budget--) { s->failed_pc=0x0c0763aeu; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c0763b0;
P_0c0763b0: /* original 2238, guest PC 0x0c0763b0 */
if(!s->budget--) { s->failed_pc=0x0c0763b0u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0763b2;
P_0c0763b2: /* original 8b88, guest PC 0x0c0763b2 */
if(!s->budget--) { s->failed_pc=0x0c0763b2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0762c6; }
goto P_0c0763b4;
P_0c0763b4: /* original 61f3, guest PC 0x0c0763b4 */
if(!s->budget--) { s->failed_pc=0x0c0763b4u; return 0; }
r[1]=r[15];
goto P_0c0763b6;
P_0c0763b6: /* original 715c, guest PC 0x0c0763b6 */
if(!s->budget--) { s->failed_pc=0x0c0763b6u; return 0; }
r[1]+=0x0000005cu;
goto P_0c0763b8;
P_0c0763b8: /* original e300, guest PC 0x0c0763b8 */
if(!s->budget--) { s->failed_pc=0x0c0763b8u; return 0; }
r[3]=0x00000000u;
goto P_0c0763ba;
P_0c0763ba: /* original 2f16, guest PC 0x0c0763ba */
if(!s->budget--) { s->failed_pc=0x0c0763bau; return 0; }
r[15]-=4; write(ram,r[15],r[1],4);
goto P_0c0763bc;
P_0c0763bc: /* original 2f36, guest PC 0x0c0763bc */
if(!s->budget--) { s->failed_pc=0x0c0763bcu; return 0; }
r[15]-=4; write(ram,r[15],r[3],4);
goto P_0c0763be;
P_0c0763be: /* original e604, guest PC 0x0c0763be */
if(!s->budget--) { s->failed_pc=0x0c0763beu; return 0; }
r[6]=0x00000004u;
goto P_0c0763c0;
P_0c0763c0: /* original 903e, guest PC 0x0c0763c0 */
if(!s->budget--) { s->failed_pc=0x0c0763c0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c076440u,2);
goto P_0c0763c2;
P_0c0763c2: /* original 973c, guest PC 0x0c0763c2 */
if(!s->budget--) { s->failed_pc=0x0c0763c2u; return 0; }
r[7]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07643eu,2);
goto P_0c0763c4;
P_0c0763c4: /* original 05fe, guest PC 0x0c0763c4 */
if(!s->budget--) { s->failed_pc=0x0c0763c4u; return 0; }
r[5]=read(ram,r[15]+r[0],4);
goto P_0c0763c6;
P_0c0763c6: /* original 903c, guest PC 0x0c0763c6 */
if(!s->budget--) { s->failed_pc=0x0c0763c6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c076442u,2);
goto P_0c0763c8;
P_0c0763c8: /* original 37fc, guest PC 0x0c0763c8 */
if(!s->budget--) { s->failed_pc=0x0c0763c8u; return 0; }
r[7]+=r[15];
goto P_0c0763ca;
P_0c0763ca: /* original d223, guest PC 0x0c0763ca */
if(!s->budget--) { s->failed_pc=0x0c0763cau; return 0; }
r[2]=read(ram,0x0c076458u,4);
goto P_0c0763cc;
P_0c0763cc: /* original 420b, guest PC 0x0c0763cc */
if(!s->budget--) { s->failed_pc=0x0c0763ccu; return 0; }
target=r[2];
r[16]=0x0c0763d0u;
r[4]=read(ram,r[15]+r[0],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0763d0u) { target=s->pc; goto dispatch; }
goto P_0c0763d0;
P_0c0763ce: /* original 04fe, guest PC 0x0c0763ce */
if(!s->budget--) { s->failed_pc=0x0c0763ceu; return 0; }
r[4]=read(ram,r[15]+r[0],4);
goto P_0c0763d0;
P_0c0763d0: /* original 902e, guest PC 0x0c0763d0 */
if(!s->budget--) { s->failed_pc=0x0c0763d0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c076430u,2);
goto P_0c0763d2;
P_0c0763d2: /* original 7f08, guest PC 0x0c0763d2 */
if(!s->budget--) { s->failed_pc=0x0c0763d2u; return 0; }
r[15]+=0x00000008u;
goto P_0c0763d4;
P_0c0763d4: /* original 03fe, guest PC 0x0c0763d4 */
if(!s->budget--) { s->failed_pc=0x0c0763d4u; return 0; }
r[3]=read(ram,r[15]+r[0],4);
goto P_0c0763d6;
P_0c0763d6: /* original e048, guest PC 0x0c0763d6 */
if(!s->budget--) { s->failed_pc=0x0c0763d6u; return 0; }
r[0]=0x00000048u;
goto P_0c0763d8;
P_0c0763d8: /* original 023e, guest PC 0x0c0763d8 */
if(!s->budget--) { s->failed_pc=0x0c0763d8u; return 0; }
r[2]=read(ram,r[3]+r[0],4);
goto P_0c0763da;
P_0c0763da: /* original 902e, guest PC 0x0c0763da */
if(!s->budget--) { s->failed_pc=0x0c0763dau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07643au,2);
goto P_0c0763dc;
P_0c0763dc: /* original 6123, guest PC 0x0c0763dc */
if(!s->budget--) { s->failed_pc=0x0c0763dcu; return 0; }
r[1]=r[2];
goto P_0c0763de;
P_0c0763de: /* original 0f26, guest PC 0x0c0763de */
if(!s->budget--) { s->failed_pc=0x0c0763deu; return 0; }
write(ram,r[15]+r[0],r[2],4);
goto P_0c0763e0;
P_0c0763e0: /* original d31b, guest PC 0x0c0763e0 */
if(!s->budget--) { s->failed_pc=0x0c0763e0u; return 0; }
r[3]=read(ram,0x0c076450u,4);
goto P_0c0763e2;
P_0c0763e2: /* original 2138, guest PC 0x0c0763e2 */
if(!s->budget--) { s->failed_pc=0x0c0763e2u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[3])==0)!=0);
goto P_0c0763e4;
P_0c0763e4: /* original 8b04, guest PC 0x0c0763e4 */
if(!s->budget--) { s->failed_pc=0x0c0763e4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0763f0; }
goto P_0c0763e6;
P_0c0763e6: /* original 9028, guest PC 0x0c0763e6 */
if(!s->budget--) { s->failed_pc=0x0c0763e6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07643au,2);
goto P_0c0763e8;
P_0c0763e8: /* original d31c, guest PC 0x0c0763e8 */
if(!s->budget--) { s->failed_pc=0x0c0763e8u; return 0; }
r[3]=read(ram,0x0c07645cu,4);
goto P_0c0763ea;
P_0c0763ea: /* original 02fe, guest PC 0x0c0763ea */
if(!s->budget--) { s->failed_pc=0x0c0763eau; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c0763ec;
P_0c0763ec: /* original 2238, guest PC 0x0c0763ec */
if(!s->budget--) { s->failed_pc=0x0c0763ecu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0763ee;
P_0c0763ee: /* original 893a, guest PC 0x0c0763ee */
if(!s->budget--) { s->failed_pc=0x0c0763eeu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c076466; }
goto P_0c0763f0;
P_0c0763f0: /* original 901e, guest PC 0x0c0763f0 */
if(!s->budget--) { s->failed_pc=0x0c0763f0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c076430u,2);
goto P_0c0763f2;
P_0c0763f2: /* original e161, guest PC 0x0c0763f2 */
if(!s->budget--) { s->failed_pc=0x0c0763f2u; return 0; }
r[1]=0x00000061u;
goto P_0c0763f4;
P_0c0763f4: /* original 00fe, guest PC 0x0c0763f4 */
if(!s->budget--) { s->failed_pc=0x0c0763f4u; return 0; }
r[0]=read(ram,r[15]+r[0],4);
goto P_0c0763f6;
P_0c0763f6: /* original 001c, guest PC 0x0c0763f6 */
if(!s->budget--) { s->failed_pc=0x0c0763f6u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[1]+r[0],1);
goto P_0c0763f8;
P_0c0763f8: /* original 600c, guest PC 0x0c0763f8 */
if(!s->budget--) { s->failed_pc=0x0c0763f8u; return 0; }
r[0]=r[0]&255u;
goto P_0c0763fa;
P_0c0763fa: /* original 880c, guest PC 0x0c0763fa */
if(!s->budget--) { s->failed_pc=0x0c0763fau; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000cu)!=0);
goto P_0c0763fc;
P_0c0763fc: /* original 8b03, guest PC 0x0c0763fc */
if(!s->budget--) { s->failed_pc=0x0c0763fcu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c076406; }
goto P_0c0763fe;
P_0c0763fe: /* original 9022, guest PC 0x0c0763fe */
if(!s->budget--) { s->failed_pc=0x0c0763feu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c076446u,2);
goto P_0c076400;
P_0c076400: /* original 9220, guest PC 0x0c076400 */
if(!s->budget--) { s->failed_pc=0x0c076400u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c076444u,2);
goto P_0c076402;
P_0c076402: /* original a003, guest PC 0x0c076402 */
if(!s->budget--) { s->failed_pc=0x0c076402u; return 0; }
write(ram,r[15]+r[0],r[2],4);
goto P_0c07640c;
P_0c076404: /* original 0f26, guest PC 0x0c076404 */
if(!s->budget--) { s->failed_pc=0x0c076404u; return 0; }
write(ram,r[15]+r[0],r[2],4);
goto P_0c076406;
P_0c076406: /* original 901e, guest PC 0x0c076406 */
if(!s->budget--) { s->failed_pc=0x0c076406u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c076446u,2);
goto P_0c076408;
P_0c076408: /* original 931e, guest PC 0x0c076408 */
if(!s->budget--) { s->failed_pc=0x0c076408u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c076448u,2);
goto P_0c07640a;
P_0c07640a: /* original 0f36, guest PC 0x0c07640a */
if(!s->budget--) { s->failed_pc=0x0c07640au; return 0; }
write(ram,r[15]+r[0],r[3],4);
goto P_0c07640c;
P_0c07640c: /* original 9010, guest PC 0x0c07640c */
if(!s->budget--) { s->failed_pc=0x0c07640cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c076430u,2);
goto P_0c07640e;
P_0c07640e: /* original d311, guest PC 0x0c07640e */
if(!s->budget--) { s->failed_pc=0x0c07640eu; return 0; }
r[3]=read(ram,0x0c076454u,4);
goto P_0c076410;
P_0c076410: /* original 02fe, guest PC 0x0c076410 */
if(!s->budget--) { s->failed_pc=0x0c076410u; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c076412;
P_0c076412: /* original e048, guest PC 0x0c076412 */
if(!s->budget--) { s->failed_pc=0x0c076412u; return 0; }
r[0]=0x00000048u;
goto P_0c076414;
P_0c076414: /* original 012e, guest PC 0x0c076414 */
if(!s->budget--) { s->failed_pc=0x0c076414u; return 0; }
r[1]=read(ram,r[2]+r[0],4);
goto P_0c076416;
P_0c076416: /* original 2138, guest PC 0x0c076416 */
if(!s->budget--) { s->failed_pc=0x0c076416u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[3])==0)!=0);
goto P_0c076418;
P_0c076418: /* original 8925, guest PC 0x0c076418 */
if(!s->budget--) { s->failed_pc=0x0c076418u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c076466; }
goto P_0c07641a;
P_0c07641a: /* original 9009, guest PC 0x0c07641a */
if(!s->budget--) { s->failed_pc=0x0c07641au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c076430u,2);
goto P_0c07641c;
P_0c07641c: /* original e161, guest PC 0x0c07641c */
if(!s->budget--) { s->failed_pc=0x0c07641cu; return 0; }
r[1]=0x00000061u;
goto P_0c07641e;
P_0c07641e: /* original 00fe, guest PC 0x0c07641e */
if(!s->budget--) { s->failed_pc=0x0c07641eu; return 0; }
r[0]=read(ram,r[15]+r[0],4);
goto P_0c076420;
P_0c076420: /* original 001c, guest PC 0x0c076420 */
if(!s->budget--) { s->failed_pc=0x0c076420u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[1]+r[0],1);
goto P_0c076422;
P_0c076422: /* original 600c, guest PC 0x0c076422 */
if(!s->budget--) { s->failed_pc=0x0c076422u; return 0; }
r[0]=r[0]&255u;
goto P_0c076424;
P_0c076424: /* original 880c, guest PC 0x0c076424 */
if(!s->budget--) { s->failed_pc=0x0c076424u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000cu)!=0);
goto P_0c076426;
P_0c076426: /* original 8b1b, guest PC 0x0c076426 */
if(!s->budget--) { s->failed_pc=0x0c076426u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c076460; }
goto P_0c076428;
P_0c076428: /* original 900d, guest PC 0x0c076428 */
if(!s->budget--) { s->failed_pc=0x0c076428u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c076446u,2);
goto P_0c07642a;
P_0c07642a: /* original 920e, guest PC 0x0c07642a */
if(!s->budget--) { s->failed_pc=0x0c07642au; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07644au,2);
goto P_0c07642c;
P_0c07642c: /* original a01b, guest PC 0x0c07642c */
if(!s->budget--) { s->failed_pc=0x0c07642cu; return 0; }
write(ram,r[15]+r[0],r[2],4);
goto P_0c076466;
P_0c07642e: /* original 0f26, guest PC 0x0c07642e */
if(!s->budget--) { s->failed_pc=0x0c07642eu; return 0; }
write(ram,r[15]+r[0],r[2],4);
return vf3_matrix_family(0x0c076430u,s,ram);
P_0c076460: /* original 909f, guest PC 0x0c076460 */
if(!s->budget--) { s->failed_pc=0x0c076460u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0765a2u,2);
goto P_0c076462;
P_0c076462: /* original 939d, guest PC 0x0c076462 */
if(!s->budget--) { s->failed_pc=0x0c076462u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0765a0u,2);
goto P_0c076464;
P_0c076464: /* original 0f36, guest PC 0x0c076464 */
if(!s->budget--) { s->failed_pc=0x0c076464u; return 0; }
write(ram,r[15]+r[0],r[3],4);
goto P_0c076466;
P_0c076466: /* original 61f3, guest PC 0x0c076466 */
if(!s->budget--) { s->failed_pc=0x0c076466u; return 0; }
r[1]=r[15];
goto P_0c076468;
P_0c076468: /* original 715c, guest PC 0x0c076468 */
if(!s->budget--) { s->failed_pc=0x0c076468u; return 0; }
r[1]+=0x0000005cu;
goto P_0c07646a;
P_0c07646a: /* original e3ff, guest PC 0x0c07646a */
if(!s->budget--) { s->failed_pc=0x0c07646au; return 0; }
r[3]=0xffffffffu;
goto P_0c07646c;
P_0c07646c: /* original 2f16, guest PC 0x0c07646c */
if(!s->budget--) { s->failed_pc=0x0c07646cu; return 0; }
r[15]-=4; write(ram,r[15],r[1],4);
goto P_0c07646e;
P_0c07646e: /* original 2f36, guest PC 0x0c07646e */
if(!s->budget--) { s->failed_pc=0x0c07646eu; return 0; }
r[15]-=4; write(ram,r[15],r[3],4);
goto P_0c076470;
P_0c076470: /* original 9099, guest PC 0x0c076470 */
if(!s->budget--) { s->failed_pc=0x0c076470u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0765a6u,2);
goto P_0c076472;
P_0c076472: /* original 9797, guest PC 0x0c076472 */
if(!s->budget--) { s->failed_pc=0x0c076472u; return 0; }
r[7]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0765a4u,2);
goto P_0c076474;
P_0c076474: /* original 06fe, guest PC 0x0c076474 */
if(!s->budget--) { s->failed_pc=0x0c076474u; return 0; }
r[6]=read(ram,r[15]+r[0],4);
goto P_0c076476;
P_0c076476: /* original 9097, guest PC 0x0c076476 */
if(!s->budget--) { s->failed_pc=0x0c076476u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0765a8u,2);
goto P_0c076478;
P_0c076478: /* original 37fc, guest PC 0x0c076478 */
if(!s->budget--) { s->failed_pc=0x0c076478u; return 0; }
r[7]+=r[15];
goto P_0c07647a;
P_0c07647a: /* original d24f, guest PC 0x0c07647a */
if(!s->budget--) { s->failed_pc=0x0c07647au; return 0; }
r[2]=read(ram,0x0c0765b8u,4);
goto P_0c07647c;
P_0c07647c: /* original 05fe, guest PC 0x0c07647c */
if(!s->budget--) { s->failed_pc=0x0c07647cu; return 0; }
r[5]=read(ram,r[15]+r[0],4);
goto P_0c07647e;
P_0c07647e: /* original 9094, guest PC 0x0c07647e */
if(!s->budget--) { s->failed_pc=0x0c07647eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0765aau,2);
goto P_0c076480;
P_0c076480: /* original 420b, guest PC 0x0c076480 */
if(!s->budget--) { s->failed_pc=0x0c076480u; return 0; }
target=r[2];
r[16]=0x0c076484u;
r[4]=read(ram,r[15]+r[0],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c076484u) { target=s->pc; goto dispatch; }
goto P_0c076484;
P_0c076482: /* original 04fe, guest PC 0x0c076482 */
if(!s->budget--) { s->failed_pc=0x0c076482u; return 0; }
r[4]=read(ram,r[15]+r[0],4);
goto P_0c076484;
P_0c076484: /* original 908d, guest PC 0x0c076484 */
if(!s->budget--) { s->failed_pc=0x0c076484u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0765a2u,2);
goto P_0c076486;
P_0c076486: /* original 7f08, guest PC 0x0c076486 */
if(!s->budget--) { s->failed_pc=0x0c076486u; return 0; }
r[15]+=0x00000008u;
goto P_0c076488;
P_0c076488: /* original 9390, guest PC 0x0c076488 */
if(!s->budget--) { s->failed_pc=0x0c076488u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0765acu,2);
goto P_0c07648a;
P_0c07648a: /* original 02fe, guest PC 0x0c07648a */
if(!s->budget--) { s->failed_pc=0x0c07648au; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c07648c;
P_0c07648c: /* original 3230, guest PC 0x0c07648c */
if(!s->budget--) { s->failed_pc=0x0c07648cu; return 0; }
r[17]=(r[17]&~1u)|((r[2]==r[3])!=0);
goto P_0c07648e;
P_0c07648e: /* original 8b0b, guest PC 0x0c07648e */
if(!s->budget--) { s->failed_pc=0x0c07648eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0764a8; }
goto P_0c076490;
P_0c076490: /* original 9089, guest PC 0x0c076490 */
if(!s->budget--) { s->failed_pc=0x0c076490u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0765a6u,2);
goto P_0c076492;
P_0c076492: /* original 02fe, guest PC 0x0c076492 */
if(!s->budget--) { s->failed_pc=0x0c076492u; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c076494;
P_0c076494: /* original e046, guest PC 0x0c076494 */
if(!s->budget--) { s->failed_pc=0x0c076494u; return 0; }
r[0]=0x00000046u;
goto P_0c076496;
P_0c076496: /* original 012d, guest PC 0x0c076496 */
if(!s->budget--) { s->failed_pc=0x0c076496u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,r[2]+r[0],2);
goto P_0c076498;
P_0c076498: /* original e054, guest PC 0x0c076498 */
if(!s->budget--) { s->failed_pc=0x0c076498u; return 0; }
r[0]=0x00000054u;
goto P_0c07649a;
P_0c07649a: /* original 02fe, guest PC 0x0c07649a */
if(!s->budget--) { s->failed_pc=0x0c07649au; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c07649c;
P_0c07649c: /* original 611d, guest PC 0x0c07649c */
if(!s->budget--) { s->failed_pc=0x0c07649cu; return 0; }
r[1]=r[1]&65535u;
goto P_0c07649e;
P_0c07649e: /* original 3126, guest PC 0x0c07649e */
if(!s->budget--) { s->failed_pc=0x0c07649eu; return 0; }
r[17]=(r[17]&~1u)|((r[1]>r[2])!=0);
goto P_0c0764a0;
P_0c0764a0: /* original 8902, guest PC 0x0c0764a0 */
if(!s->budget--) { s->failed_pc=0x0c0764a0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0764a8; }
goto P_0c0764a2;
P_0c0764a2: /* original 907e, guest PC 0x0c0764a2 */
if(!s->budget--) { s->failed_pc=0x0c0764a2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0765a2u,2);
goto P_0c0764a4;
P_0c0764a4: /* original 9283, guest PC 0x0c0764a4 */
if(!s->budget--) { s->failed_pc=0x0c0764a4u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0765aeu,2);
goto P_0c0764a6;
P_0c0764a6: /* original 0f26, guest PC 0x0c0764a6 */
if(!s->budget--) { s->failed_pc=0x0c0764a6u; return 0; }
write(ram,r[15]+r[0],r[2],4);
goto P_0c0764a8;
P_0c0764a8: /* original 907b, guest PC 0x0c0764a8 */
if(!s->budget--) { s->failed_pc=0x0c0764a8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0765a2u,2);
goto P_0c0764aa;
P_0c0764aa: /* original d344, guest PC 0x0c0764aa */
if(!s->budget--) { s->failed_pc=0x0c0764aau; return 0; }
r[3]=read(ram,0x0c0765bcu,4);
goto P_0c0764ac;
P_0c0764ac: /* original 01fe, guest PC 0x0c0764ac */
if(!s->budget--) { s->failed_pc=0x0c0764acu; return 0; }
r[1]=read(ram,r[15]+r[0],4);
goto P_0c0764ae;
P_0c0764ae: /* original 9078, guest PC 0x0c0764ae */
if(!s->budget--) { s->failed_pc=0x0c0764aeu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0765a2u,2);
goto P_0c0764b0;
P_0c0764b0: /* original 313c, guest PC 0x0c0764b0 */
if(!s->budget--) { s->failed_pc=0x0c0764b0u; return 0; }
r[1]+=r[3];
goto P_0c0764b2;
P_0c0764b2: /* original 0f16, guest PC 0x0c0764b2 */
if(!s->budget--) { s->failed_pc=0x0c0764b2u; return 0; }
write(ram,r[15]+r[0],r[1],4);
goto P_0c0764b4;
P_0c0764b4: /* original 9077, guest PC 0x0c0764b4 */
if(!s->budget--) { s->failed_pc=0x0c0764b4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0765a6u,2);
goto P_0c0764b6;
P_0c0764b6: /* original 02fe, guest PC 0x0c0764b6 */
if(!s->budget--) { s->failed_pc=0x0c0764b6u; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c0764b8;
P_0c0764b8: /* original e054, guest PC 0x0c0764b8 */
if(!s->budget--) { s->failed_pc=0x0c0764b8u; return 0; }
r[0]=0x00000054u;
goto P_0c0764ba;
P_0c0764ba: /* original 121d, guest PC 0x0c0764ba */
if(!s->budget--) { s->failed_pc=0x0c0764bau; return 0; }
write(ram,r[2]+52,r[1],4);
goto P_0c0764bc;
P_0c0764bc: /* original 02fe, guest PC 0x0c0764bc */
if(!s->budget--) { s->failed_pc=0x0c0764bcu; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c0764be;
P_0c0764be: /* original 72ea, guest PC 0x0c0764be */
if(!s->budget--) { s->failed_pc=0x0c0764beu; return 0; }
r[2]+=0xffffffeau;
goto P_0c0764c0;
P_0c0764c0: /* original 4211, guest PC 0x0c0764c0 */
if(!s->budget--) { s->failed_pc=0x0c0764c0u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>=0)!=0);
goto P_0c0764c2;
P_0c0764c2: /* original 8d02, guest PC 0x0c0764c2 */
if(!s->budget--) { s->failed_pc=0x0c0764c2u; return 0; }
cond=r[17]&1u;
write(ram,r[15]+60,r[2],4);
if(cond) { goto P_0c0764ca; }
goto P_0c0764c6;
P_0c0764c4: /* original 1f2f, guest PC 0x0c0764c4 */
if(!s->budget--) { s->failed_pc=0x0c0764c4u; return 0; }
write(ram,r[15]+60,r[2],4);
goto P_0c0764c6;
P_0c0764c6: /* original e000, guest PC 0x0c0764c6 */
if(!s->budget--) { s->failed_pc=0x0c0764c6u; return 0; }
r[0]=0x00000000u;
goto P_0c0764c8;
P_0c0764c8: /* original 1f0f, guest PC 0x0c0764c8 */
if(!s->budget--) { s->failed_pc=0x0c0764c8u; return 0; }
write(ram,r[15]+60,r[0],4);
goto P_0c0764ca;
P_0c0764ca: /* original 906c, guest PC 0x0c0764ca */
if(!s->budget--) { s->failed_pc=0x0c0764cau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0765a6u,2);
goto P_0c0764cc;
P_0c0764cc: /* original e511, guest PC 0x0c0764cc */
if(!s->budget--) { s->failed_pc=0x0c0764ccu; return 0; }
r[5]=0x00000011u;
goto P_0c0764ce;
P_0c0764ce: /* original 52ff, guest PC 0x0c0764ce */
if(!s->budget--) { s->failed_pc=0x0c0764ceu; return 0; }
r[2]=read(ram,r[15]+60,4);
goto P_0c0764d0;
P_0c0764d0: /* original 03fe, guest PC 0x0c0764d0 */
if(!s->budget--) { s->failed_pc=0x0c0764d0u; return 0; }
r[3]=read(ram,r[15]+r[0],4);
goto P_0c0764d2;
P_0c0764d2: /* original e066, guest PC 0x0c0764d2 */
if(!s->budget--) { s->failed_pc=0x0c0764d2u; return 0; }
r[0]=0x00000066u;
goto P_0c0764d4;
P_0c0764d4: /* original 0325, guest PC 0x0c0764d4 */
if(!s->budget--) { s->failed_pc=0x0c0764d4u; return 0; }
write(ram,r[3]+r[0],r[2],2);
goto P_0c0764d6;
P_0c0764d6: /* original 9064, guest PC 0x0c0764d6 */
if(!s->budget--) { s->failed_pc=0x0c0764d6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0765a2u,2);
goto P_0c0764d8;
P_0c0764d8: /* original d339, guest PC 0x0c0764d8 */
if(!s->budget--) { s->failed_pc=0x0c0764d8u; return 0; }
r[3]=read(ram,0x0c0765c0u,4);
goto P_0c0764da;
P_0c0764da: /* original 430b, guest PC 0x0c0764da */
if(!s->budget--) { s->failed_pc=0x0c0764dau; return 0; }
target=r[3];
r[16]=0x0c0764deu;
r[4]=read(ram,r[15]+r[0],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0764deu) { target=s->pc; goto dispatch; }
goto P_0c0764de;
P_0c0764dc: /* original 04fe, guest PC 0x0c0764dc */
if(!s->budget--) { s->failed_pc=0x0c0764dcu; return 0; }
r[4]=read(ram,r[15]+r[0],4);
goto P_0c0764de;
P_0c0764de: /* original 9167, guest PC 0x0c0764de */
if(!s->budget--) { s->failed_pc=0x0c0764deu; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0765b0u,2);
goto P_0c0764e0;
P_0c0764e0: /* original 2008, guest PC 0x0c0764e0 */
if(!s->budget--) { s->failed_pc=0x0c0764e0u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c0764e2;
P_0c0764e2: /* original 31fc, guest PC 0x0c0764e2 */
if(!s->budget--) { s->failed_pc=0x0c0764e2u; return 0; }
r[1]+=r[15];
goto P_0c0764e4;
P_0c0764e4: /* original 8d40, guest PC 0x0c0764e4 */
if(!s->budget--) { s->failed_pc=0x0c0764e4u; return 0; }
cond=r[17]&1u;
write(ram,r[1],r[0],4);
if(cond) { goto P_0c076568; }
goto P_0c0764e8;
P_0c0764e6: /* original 2102, guest PC 0x0c0764e6 */
if(!s->budget--) { s->failed_pc=0x0c0764e6u; return 0; }
write(ram,r[1],r[0],4);
goto P_0c0764e8;
P_0c0764e8: /* original 9162, guest PC 0x0c0764e8 */
if(!s->budget--) { s->failed_pc=0x0c0764e8u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0765b0u,2);
goto P_0c0764ea;
P_0c0764ea: /* original 8402, guest PC 0x0c0764ea */
if(!s->budget--) { s->failed_pc=0x0c0764eau; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[0]+2,1);
goto P_0c0764ec;
P_0c0764ec: /* original 31fc, guest PC 0x0c0764ec */
if(!s->budget--) { s->failed_pc=0x0c0764ecu; return 0; }
r[1]+=r[15];
goto P_0c0764ee;
P_0c0764ee: /* original d335, guest PC 0x0c0764ee */
if(!s->budget--) { s->failed_pc=0x0c0764eeu; return 0; }
r[3]=read(ram,0x0c0765c4u,4);
goto P_0c0764f0;
P_0c0764f0: /* original 6212, guest PC 0x0c0764f0 */
if(!s->budget--) { s->failed_pc=0x0c0764f0u; return 0; }
tmp=read(ram,r[1],4);
r[2]=tmp;
goto P_0c0764f2;
P_0c0764f2: /* original 600c, guest PC 0x0c0764f2 */
if(!s->budget--) { s->failed_pc=0x0c0764f2u; return 0; }
r[0]=r[0]&255u;
goto P_0c0764f4;
P_0c0764f4: /* original 4018, guest PC 0x0c0764f4 */
if(!s->budget--) { s->failed_pc=0x0c0764f4u; return 0; }
r[0]<<=8;
goto P_0c0764f6;
P_0c0764f6: /* original 61f3, guest PC 0x0c0764f6 */
if(!s->budget--) { s->failed_pc=0x0c0764f6u; return 0; }
r[1]=r[15];
goto P_0c0764f8;
P_0c0764f8: /* original 7201, guest PC 0x0c0764f8 */
if(!s->budget--) { s->failed_pc=0x0c0764f8u; return 0; }
r[2]+=0x00000001u;
goto P_0c0764fa;
P_0c0764fa: /* original 2039, guest PC 0x0c0764fa */
if(!s->budget--) { s->failed_pc=0x0c0764fau; return 0; }
r[0]&=r[3];
goto P_0c0764fc;
P_0c0764fc: /* original 6320, guest PC 0x0c0764fc */
if(!s->budget--) { s->failed_pc=0x0c0764fcu; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[2],1);
r[3]=tmp;
goto P_0c0764fe;
P_0c0764fe: /* original 7174, guest PC 0x0c0764fe */
if(!s->budget--) { s->failed_pc=0x0c0764feu; return 0; }
r[1]+=0x00000074u;
goto P_0c076500;
P_0c076500: /* original 633c, guest PC 0x0c076500 */
if(!s->budget--) { s->failed_pc=0x0c076500u; return 0; }
r[3]=r[3]&255u;
goto P_0c076502;
P_0c076502: /* original 203b, guest PC 0x0c076502 */
if(!s->budget--) { s->failed_pc=0x0c076502u; return 0; }
r[0]|=r[3];
goto P_0c076504;
P_0c076504: /* original 63f3, guest PC 0x0c076504 */
if(!s->budget--) { s->failed_pc=0x0c076504u; return 0; }
r[3]=r[15];
goto P_0c076506;
P_0c076506: /* original 2102, guest PC 0x0c076506 */
if(!s->budget--) { s->failed_pc=0x0c076506u; return 0; }
write(ram,r[1],r[0],4);
goto P_0c076508;
P_0c076508: /* original 7310, guest PC 0x0c076508 */
if(!s->budget--) { s->failed_pc=0x0c076508u; return 0; }
r[3]+=0x00000010u;
goto P_0c07650a;
P_0c07650a: /* original 6233, guest PC 0x0c07650a */
if(!s->budget--) { s->failed_pc=0x0c07650au; return 0; }
r[2]=r[3];
goto P_0c07650c;
P_0c07650c: /* original 1f33, guest PC 0x0c07650c */
if(!s->budget--) { s->failed_pc=0x0c07650cu; return 0; }
write(ram,r[15]+12,r[3],4);
goto P_0c07650e;
P_0c07650e: /* original 904f, guest PC 0x0c07650e */
if(!s->budget--) { s->failed_pc=0x0c07650eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0765b0u,2);
goto P_0c076510;
P_0c076510: /* original 914e, guest PC 0x0c076510 */
if(!s->budget--) { s->failed_pc=0x0c076510u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0765b0u,2);
goto P_0c076512;
P_0c076512: /* original 03fe, guest PC 0x0c076512 */
if(!s->budget--) { s->failed_pc=0x0c076512u; return 0; }
r[3]=read(ram,r[15]+r[0],4);
goto P_0c076514;
P_0c076514: /* original 31fc, guest PC 0x0c076514 */
if(!s->budget--) { s->failed_pc=0x0c076514u; return 0; }
r[1]+=r[15];
goto P_0c076516;
P_0c076516: /* original 7303, guest PC 0x0c076516 */
if(!s->budget--) { s->failed_pc=0x0c076516u; return 0; }
r[3]+=0x00000003u;
goto P_0c076518;
P_0c076518: /* original 6112, guest PC 0x0c076518 */
if(!s->budget--) { s->failed_pc=0x0c076518u; return 0; }
tmp=read(ram,r[1],4);
r[1]=tmp;
goto P_0c07651a;
P_0c07651a: /* original 8433, guest PC 0x0c07651a */
if(!s->budget--) { s->failed_pc=0x0c07651au; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[3]+3,1);
goto P_0c07651c;
P_0c07651c: /* original d32a, guest PC 0x0c07651c */
if(!s->budget--) { s->failed_pc=0x0c07651cu; return 0; }
r[3]=read(ram,0x0c0765c8u,4);
goto P_0c07651e;
P_0c07651e: /* original 600c, guest PC 0x0c07651e */
if(!s->budget--) { s->failed_pc=0x0c07651eu; return 0; }
r[0]=r[0]&255u;
goto P_0c076520;
P_0c076520: /* original 4028, guest PC 0x0c076520 */
if(!s->budget--) { s->failed_pc=0x0c076520u; return 0; }
r[0]<<=16;
goto P_0c076522;
P_0c076522: /* original 4018, guest PC 0x0c076522 */
if(!s->budget--) { s->failed_pc=0x0c076522u; return 0; }
r[0]<<=8;
goto P_0c076524;
P_0c076524: /* original 2039, guest PC 0x0c076524 */
if(!s->budget--) { s->failed_pc=0x0c076524u; return 0; }
r[0]&=r[3];
goto P_0c076526;
P_0c076526: /* original 6303, guest PC 0x0c076526 */
if(!s->budget--) { s->failed_pc=0x0c076526u; return 0; }
r[3]=r[0];
goto P_0c076528;
P_0c076528: /* original 7103, guest PC 0x0c076528 */
if(!s->budget--) { s->failed_pc=0x0c076528u; return 0; }
r[1]+=0x00000003u;
goto P_0c07652a;
P_0c07652a: /* original 8412, guest PC 0x0c07652a */
if(!s->budget--) { s->failed_pc=0x0c07652au; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[1]+2,1);
goto P_0c07652c;
P_0c07652c: /* original d127, guest PC 0x0c07652c */
if(!s->budget--) { s->failed_pc=0x0c07652cu; return 0; }
r[1]=read(ram,0x0c0765ccu,4);
goto P_0c07652e;
P_0c07652e: /* original 600c, guest PC 0x0c07652e */
if(!s->budget--) { s->failed_pc=0x0c07652eu; return 0; }
r[0]=r[0]&255u;
goto P_0c076530;
P_0c076530: /* original 4028, guest PC 0x0c076530 */
if(!s->budget--) { s->failed_pc=0x0c076530u; return 0; }
r[0]<<=16;
goto P_0c076532;
P_0c076532: /* original 2019, guest PC 0x0c076532 */
if(!s->budget--) { s->failed_pc=0x0c076532u; return 0; }
r[0]&=r[1];
goto P_0c076534;
P_0c076534: /* original 230b, guest PC 0x0c076534 */
if(!s->budget--) { s->failed_pc=0x0c076534u; return 0; }
r[3]|=r[0];
goto P_0c076536;
P_0c076536: /* original 903b, guest PC 0x0c076536 */
if(!s->budget--) { s->failed_pc=0x0c076536u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0765b0u,2);
goto P_0c076538;
P_0c076538: /* original 4119, guest PC 0x0c076538 */
if(!s->budget--) { s->failed_pc=0x0c076538u; return 0; }
r[1]>>=8;
goto P_0c07653a;
P_0c07653a: /* original 00fe, guest PC 0x0c07653a */
if(!s->budget--) { s->failed_pc=0x0c07653au; return 0; }
r[0]=read(ram,r[15]+r[0],4);
goto P_0c07653c;
P_0c07653c: /* original 7003, guest PC 0x0c07653c */
if(!s->budget--) { s->failed_pc=0x0c07653cu; return 0; }
r[0]+=0x00000003u;
goto P_0c07653e;
P_0c07653e: /* original 8401, guest PC 0x0c07653e */
if(!s->budget--) { s->failed_pc=0x0c07653eu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[0]+1,1);
goto P_0c076540;
P_0c076540: /* original 600c, guest PC 0x0c076540 */
if(!s->budget--) { s->failed_pc=0x0c076540u; return 0; }
r[0]=r[0]&255u;
goto P_0c076542;
P_0c076542: /* original 4018, guest PC 0x0c076542 */
if(!s->budget--) { s->failed_pc=0x0c076542u; return 0; }
r[0]<<=8;
goto P_0c076544;
P_0c076544: /* original 2019, guest PC 0x0c076544 */
if(!s->budget--) { s->failed_pc=0x0c076544u; return 0; }
r[0]&=r[1];
goto P_0c076546;
P_0c076546: /* original 230b, guest PC 0x0c076546 */
if(!s->budget--) { s->failed_pc=0x0c076546u; return 0; }
r[3]|=r[0];
goto P_0c076548;
P_0c076548: /* original 9032, guest PC 0x0c076548 */
if(!s->budget--) { s->failed_pc=0x0c076548u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0765b0u,2);
goto P_0c07654a;
P_0c07654a: /* original 00fe, guest PC 0x0c07654a */
if(!s->budget--) { s->failed_pc=0x0c07654au; return 0; }
r[0]=read(ram,r[15]+r[0],4);
goto P_0c07654c;
P_0c07654c: /* original 8403, guest PC 0x0c07654c */
if(!s->budget--) { s->failed_pc=0x0c07654cu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[0]+3,1);
goto P_0c07654e;
P_0c07654e: /* original 600c, guest PC 0x0c07654e */
if(!s->budget--) { s->failed_pc=0x0c07654eu; return 0; }
r[0]=r[0]&255u;
goto P_0c076550;
P_0c076550: /* original 230b, guest PC 0x0c076550 */
if(!s->budget--) { s->failed_pc=0x0c076550u; return 0; }
r[3]|=r[0];
goto P_0c076552;
P_0c076552: /* original 2232, guest PC 0x0c076552 */
if(!s->budget--) { s->failed_pc=0x0c076552u; return 0; }
write(ram,r[2],r[3],4);
goto P_0c076554;
P_0c076554: /* original e01c, guest PC 0x0c076554 */
if(!s->budget--) { s->failed_pc=0x0c076554u; return 0; }
r[0]=0x0000001cu;
goto P_0c076556;
P_0c076556: /* original 52f3, guest PC 0x0c076556 */
if(!s->budget--) { s->failed_pc=0x0c076556u; return 0; }
r[2]=read(ram,r[15]+12,4);
goto P_0c076558;
P_0c076558: /* original f328, guest PC 0x0c076558 */
if(!s->budget--) { s->failed_pc=0x0c076558u; return 0; }
vf3_matrix_load(s,ram,3,r[2]);
goto P_0c07655a;
P_0c07655a: /* original ff37, guest PC 0x0c07655a */
if(!s->budget--) { s->failed_pc=0x0c07655au; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c07655c;
P_0c07655c: /* original e020, guest PC 0x0c07655c */
if(!s->budget--) { s->failed_pc=0x0c07655cu; return 0; }
r[0]=0x00000020u;
goto P_0c07655e;
P_0c07655e: /* original f2f6, guest PC 0x0c07655e */
if(!s->budget--) { s->failed_pc=0x0c07655eu; return 0; }
vf3_matrix_load(s,ram,2,r[15]+r[0]);
goto P_0c076560;
P_0c076560: /* original e020, guest PC 0x0c076560 */
if(!s->budget--) { s->failed_pc=0x0c076560u; return 0; }
r[0]=0x00000020u;
goto P_0c076562;
P_0c076562: /* original f232, guest PC 0x0c076562 */
if(!s->budget--) { s->failed_pc=0x0c076562u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c076564;
P_0c076564: /* original a0a7, guest PC 0x0c076564 */
if(!s->budget--) { s->failed_pc=0x0c076564u; return 0; }
vf3_matrix_store(s,ram,2,r[15]+r[0]);
goto P_0c0766b6;
P_0c076566: /* original ff27, guest PC 0x0c076566 */
if(!s->budget--) { s->failed_pc=0x0c076566u; return 0; }
vf3_matrix_store(s,ram,2,r[15]+r[0]);
goto P_0c076568;
P_0c076568: /* original 901d, guest PC 0x0c076568 */
if(!s->budget--) { s->failed_pc=0x0c076568u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0765a6u,2);
goto P_0c07656a;
P_0c07656a: /* original 02fe, guest PC 0x0c07656a */
if(!s->budget--) { s->failed_pc=0x0c07656au; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c07656c;
P_0c07656c: /* original e048, guest PC 0x0c07656c */
if(!s->budget--) { s->failed_pc=0x0c07656cu; return 0; }
r[0]=0x00000048u;
goto P_0c07656e;
P_0c07656e: /* original 032e, guest PC 0x0c07656e */
if(!s->budget--) { s->failed_pc=0x0c07656eu; return 0; }
r[3]=read(ram,r[2]+r[0],4);
goto P_0c076570;
P_0c076570: /* original 901f, guest PC 0x0c076570 */
if(!s->budget--) { s->failed_pc=0x0c076570u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0765b2u,2);
goto P_0c076572;
P_0c076572: /* original 0f36, guest PC 0x0c076572 */
if(!s->budget--) { s->failed_pc=0x0c076572u; return 0; }
write(ram,r[15]+r[0],r[3],4);
goto P_0c076574;
P_0c076574: /* original 901d, guest PC 0x0c076574 */
if(!s->budget--) { s->failed_pc=0x0c076574u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0765b2u,2);
goto P_0c076576;
P_0c076576: /* original d316, guest PC 0x0c076576 */
if(!s->budget--) { s->failed_pc=0x0c076576u; return 0; }
r[3]=read(ram,0x0c0765d0u,4);
goto P_0c076578;
P_0c076578: /* original 02fe, guest PC 0x0c076578 */
if(!s->budget--) { s->failed_pc=0x0c076578u; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c07657a;
P_0c07657a: /* original 2238, guest PC 0x0c07657a */
if(!s->budget--) { s->failed_pc=0x0c07657au; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c07657c;
P_0c07657c: /* original 892a, guest PC 0x0c07657c */
if(!s->budget--) { s->failed_pc=0x0c07657cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0765d4; }
goto P_0c07657e;
P_0c07657e: /* original 9019, guest PC 0x0c07657e */
if(!s->budget--) { s->failed_pc=0x0c07657eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0765b4u,2);
goto P_0c076580;
P_0c076580: /* original 61f3, guest PC 0x0c076580 */
if(!s->budget--) { s->failed_pc=0x0c076580u; return 0; }
r[1]=r[15];
goto P_0c076582;
P_0c076582: /* original 7174, guest PC 0x0c076582 */
if(!s->budget--) { s->failed_pc=0x0c076582u; return 0; }
r[1]+=0x00000074u;
goto P_0c076584;
P_0c076584: /* original 02fe, guest PC 0x0c076584 */
if(!s->budget--) { s->failed_pc=0x0c076584u; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c076586;
P_0c076586: /* original 852e, guest PC 0x0c076586 */
if(!s->budget--) { s->failed_pc=0x0c076586u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[2]+28,2);
goto P_0c076588;
P_0c076588: /* original 600d, guest PC 0x0c076588 */
if(!s->budget--) { s->failed_pc=0x0c076588u; return 0; }
r[0]=r[0]&65535u;
goto P_0c07658a;
P_0c07658a: /* original 2102, guest PC 0x0c07658a */
if(!s->budget--) { s->failed_pc=0x0c07658au; return 0; }
write(ram,r[1],r[0],4);
goto P_0c07658c;
P_0c07658c: /* original 9012, guest PC 0x0c07658c */
if(!s->budget--) { s->failed_pc=0x0c07658cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0765b4u,2);
goto P_0c07658e;
P_0c07658e: /* original 02fe, guest PC 0x0c07658e */
if(!s->budget--) { s->failed_pc=0x0c07658eu; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c076590;
P_0c076590: /* original e010, guest PC 0x0c076590 */
if(!s->budget--) { s->failed_pc=0x0c076590u; return 0; }
r[0]=0x00000010u;
goto P_0c076592;
P_0c076592: /* original f326, guest PC 0x0c076592 */
if(!s->budget--) { s->failed_pc=0x0c076592u; return 0; }
vf3_matrix_load(s,ram,3,r[2]+r[0]);
goto P_0c076594;
P_0c076594: /* original e020, guest PC 0x0c076594 */
if(!s->budget--) { s->failed_pc=0x0c076594u; return 0; }
r[0]=0x00000020u;
goto P_0c076596;
P_0c076596: /* original f2f6, guest PC 0x0c076596 */
if(!s->budget--) { s->failed_pc=0x0c076596u; return 0; }
vf3_matrix_load(s,ram,2,r[15]+r[0]);
goto P_0c076598;
P_0c076598: /* original e020, guest PC 0x0c076598 */
if(!s->budget--) { s->failed_pc=0x0c076598u; return 0; }
r[0]=0x00000020u;
goto P_0c07659a;
P_0c07659a: /* original f232, guest PC 0x0c07659a */
if(!s->budget--) { s->failed_pc=0x0c07659au; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c07659c;
P_0c07659c: /* original a03b, guest PC 0x0c07659c */
if(!s->budget--) { s->failed_pc=0x0c07659cu; return 0; }
vf3_matrix_store(s,ram,2,r[15]+r[0]);
goto P_0c076616;
P_0c07659e: /* original ff27, guest PC 0x0c07659e */
if(!s->budget--) { s->failed_pc=0x0c07659eu; return 0; }
vf3_matrix_store(s,ram,2,r[15]+r[0]);
return vf3_matrix_family(0x0c0765a0u,s,ram);
P_0c0765d4: /* original e050, guest PC 0x0c0765d4 */
if(!s->budget--) { s->failed_pc=0x0c0765d4u; return 0; }
r[0]=0x00000050u;
goto P_0c0765d6;
P_0c0765d6: /* original 00fe, guest PC 0x0c0765d6 */
if(!s->budget--) { s->failed_pc=0x0c0765d6u; return 0; }
r[0]=read(ram,r[15]+r[0],4);
goto P_0c0765d8;
P_0c0765d8: /* original 8803, guest PC 0x0c0765d8 */
if(!s->budget--) { s->failed_pc=0x0c0765d8u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000003u)!=0);
goto P_0c0765da;
P_0c0765da: /* original 8b0c, guest PC 0x0c0765da */
if(!s->budget--) { s->failed_pc=0x0c0765dau; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0765f6; }
goto P_0c0765dc;
P_0c0765dc: /* original 9088, guest PC 0x0c0765dc */
if(!s->budget--) { s->failed_pc=0x0c0765dcu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0766f0u,2);
goto P_0c0765de;
P_0c0765de: /* original 01fe, guest PC 0x0c0765de */
if(!s->budget--) { s->failed_pc=0x0c0765deu; return 0; }
r[1]=read(ram,r[15]+r[0],4);
goto P_0c0765e0;
P_0c0765e0: /* original 851d, guest PC 0x0c0765e0 */
if(!s->budget--) { s->failed_pc=0x0c0765e0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[1]+26,2);
goto P_0c0765e2;
P_0c0765e2: /* original 61f3, guest PC 0x0c0765e2 */
if(!s->budget--) { s->failed_pc=0x0c0765e2u; return 0; }
r[1]=r[15];
goto P_0c0765e4;
P_0c0765e4: /* original 7174, guest PC 0x0c0765e4 */
if(!s->budget--) { s->failed_pc=0x0c0765e4u; return 0; }
r[1]+=0x00000074u;
goto P_0c0765e6;
P_0c0765e6: /* original 600d, guest PC 0x0c0765e6 */
if(!s->budget--) { s->failed_pc=0x0c0765e6u; return 0; }
r[0]=r[0]&65535u;
goto P_0c0765e8;
P_0c0765e8: /* original 2102, guest PC 0x0c0765e8 */
if(!s->budget--) { s->failed_pc=0x0c0765e8u; return 0; }
write(ram,r[1],r[0],4);
goto P_0c0765ea;
P_0c0765ea: /* original 9081, guest PC 0x0c0765ea */
if(!s->budget--) { s->failed_pc=0x0c0765eau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0766f0u,2);
goto P_0c0765ec;
P_0c0765ec: /* original 02fe, guest PC 0x0c0765ec */
if(!s->budget--) { s->failed_pc=0x0c0765ecu; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c0765ee;
P_0c0765ee: /* original e00c, guest PC 0x0c0765ee */
if(!s->budget--) { s->failed_pc=0x0c0765eeu; return 0; }
r[0]=0x0000000cu;
goto P_0c0765f0;
P_0c0765f0: /* original f326, guest PC 0x0c0765f0 */
if(!s->budget--) { s->failed_pc=0x0c0765f0u; return 0; }
vf3_matrix_load(s,ram,3,r[2]+r[0]);
goto P_0c0765f2;
P_0c0765f2: /* original a00b, guest PC 0x0c0765f2 */
if(!s->budget--) { s->failed_pc=0x0c0765f2u; return 0; }
goto P_0c07660c;
P_0c0765f4: /* original 0009, guest PC 0x0c0765f4 */
if(!s->budget--) { s->failed_pc=0x0c0765f4u; return 0; }
goto P_0c0765f6;
P_0c0765f6: /* original 907b, guest PC 0x0c0765f6 */
if(!s->budget--) { s->failed_pc=0x0c0765f6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0766f0u,2);
goto P_0c0765f8;
P_0c0765f8: /* original 01fe, guest PC 0x0c0765f8 */
if(!s->budget--) { s->failed_pc=0x0c0765f8u; return 0; }
r[1]=read(ram,r[15]+r[0],4);
goto P_0c0765fa;
P_0c0765fa: /* original 851c, guest PC 0x0c0765fa */
if(!s->budget--) { s->failed_pc=0x0c0765fau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[1]+24,2);
goto P_0c0765fc;
P_0c0765fc: /* original 61f3, guest PC 0x0c0765fc */
if(!s->budget--) { s->failed_pc=0x0c0765fcu; return 0; }
r[1]=r[15];
goto P_0c0765fe;
P_0c0765fe: /* original 7174, guest PC 0x0c0765fe */
if(!s->budget--) { s->failed_pc=0x0c0765feu; return 0; }
r[1]+=0x00000074u;
goto P_0c076600;
P_0c076600: /* original 600d, guest PC 0x0c076600 */
if(!s->budget--) { s->failed_pc=0x0c076600u; return 0; }
r[0]=r[0]&65535u;
goto P_0c076602;
P_0c076602: /* original 2102, guest PC 0x0c076602 */
if(!s->budget--) { s->failed_pc=0x0c076602u; return 0; }
write(ram,r[1],r[0],4);
goto P_0c076604;
P_0c076604: /* original 9074, guest PC 0x0c076604 */
if(!s->budget--) { s->failed_pc=0x0c076604u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0766f0u,2);
goto P_0c076606;
P_0c076606: /* original 02fe, guest PC 0x0c076606 */
if(!s->budget--) { s->failed_pc=0x0c076606u; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c076608;
P_0c076608: /* original e008, guest PC 0x0c076608 */
if(!s->budget--) { s->failed_pc=0x0c076608u; return 0; }
r[0]=0x00000008u;
goto P_0c07660a;
P_0c07660a: /* original f326, guest PC 0x0c07660a */
if(!s->budget--) { s->failed_pc=0x0c07660au; return 0; }
vf3_matrix_load(s,ram,3,r[2]+r[0]);
goto P_0c07660c;
P_0c07660c: /* original e020, guest PC 0x0c07660c */
if(!s->budget--) { s->failed_pc=0x0c07660cu; return 0; }
r[0]=0x00000020u;
goto P_0c07660e;
P_0c07660e: /* original f2f6, guest PC 0x0c07660e */
if(!s->budget--) { s->failed_pc=0x0c07660eu; return 0; }
vf3_matrix_load(s,ram,2,r[15]+r[0]);
goto P_0c076610;
P_0c076610: /* original e020, guest PC 0x0c076610 */
if(!s->budget--) { s->failed_pc=0x0c076610u; return 0; }
r[0]=0x00000020u;
goto P_0c076612;
P_0c076612: /* original f232, guest PC 0x0c076612 */
if(!s->budget--) { s->failed_pc=0x0c076612u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c076614;
P_0c076614: /* original ff27, guest PC 0x0c076614 */
if(!s->budget--) { s->failed_pc=0x0c076614u; return 0; }
vf3_matrix_store(s,ram,2,r[15]+r[0]);
goto P_0c076616;
P_0c076616: /* original 906c, guest PC 0x0c076616 */
if(!s->budget--) { s->failed_pc=0x0c076616u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0766f2u,2);
goto P_0c076618;
P_0c076618: /* original e301, guest PC 0x0c076618 */
if(!s->budget--) { s->failed_pc=0x0c076618u; return 0; }
r[3]=0x00000001u;
goto P_0c07661a;
P_0c07661a: /* original 0f36, guest PC 0x0c07661a */
if(!s->budget--) { s->failed_pc=0x0c07661au; return 0; }
write(ram,r[15]+r[0],r[3],4);
goto P_0c07661c;
P_0c07661c: /* original 906a, guest PC 0x0c07661c */
if(!s->budget--) { s->failed_pc=0x0c07661cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0766f4u,2);
goto P_0c07661e;
P_0c07661e: /* original 02fe, guest PC 0x0c07661e */
if(!s->budget--) { s->failed_pc=0x0c07661eu; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c076620;
P_0c076620: /* original 9069, guest PC 0x0c076620 */
if(!s->budget--) { s->failed_pc=0x0c076620u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0766f6u,2);
goto P_0c076622;
P_0c076622: /* original 032c, guest PC 0x0c076622 */
if(!s->budget--) { s->failed_pc=0x0c076622u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[2]+r[0],1);
goto P_0c076624;
P_0c076624: /* original 9068, guest PC 0x0c076624 */
if(!s->budget--) { s->failed_pc=0x0c076624u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0766f8u,2);
goto P_0c076626;
P_0c076626: /* original 633c, guest PC 0x0c076626 */
if(!s->budget--) { s->failed_pc=0x0c076626u; return 0; }
r[3]=r[3]&255u;
goto P_0c076628;
P_0c076628: /* original 0f36, guest PC 0x0c076628 */
if(!s->budget--) { s->failed_pc=0x0c076628u; return 0; }
write(ram,r[15]+r[0],r[3],4);
goto P_0c07662a;
P_0c07662a: /* original 9062, guest PC 0x0c07662a */
if(!s->budget--) { s->failed_pc=0x0c07662au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0766f2u,2);
goto P_0c07662c;
P_0c07662c: /* original 02fe, guest PC 0x0c07662c */
if(!s->budget--) { s->failed_pc=0x0c07662cu; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c07662e;
P_0c07662e: /* original 3326, guest PC 0x0c07662e */
if(!s->budget--) { s->failed_pc=0x0c07662eu; return 0; }
r[17]=(r[17]&~1u)|((r[3]>r[2])!=0);
goto P_0c076630;
P_0c076630: /* original 8b3a, guest PC 0x0c076630 */
if(!s->budget--) { s->failed_pc=0x0c076630u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0766a8; }
goto P_0c076632;
P_0c076632: /* original 905e, guest PC 0x0c076632 */
if(!s->budget--) { s->failed_pc=0x0c076632u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0766f2u,2);
goto P_0c076634;
P_0c076634: /* original 02fe, guest PC 0x0c076634 */
if(!s->budget--) { s->failed_pc=0x0c076634u; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c076636;
P_0c076636: /* original 905f, guest PC 0x0c076636 */
if(!s->budget--) { s->failed_pc=0x0c076636u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0766f8u,2);
goto P_0c076638;
P_0c076638: /* original 01fe, guest PC 0x0c076638 */
if(!s->budget--) { s->failed_pc=0x0c076638u; return 0; }
r[1]=read(ram,r[15]+r[0],4);
goto P_0c07663a;
P_0c07663a: /* original 905d, guest PC 0x0c07663a */
if(!s->budget--) { s->failed_pc=0x0c07663au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0766f8u,2);
goto P_0c07663c;
P_0c07663c: /* original 3128, guest PC 0x0c07663c */
if(!s->budget--) { s->failed_pc=0x0c07663cu; return 0; }
r[1]-=r[2];
goto P_0c07663e;
P_0c07663e: /* original 0f16, guest PC 0x0c07663e */
if(!s->budget--) { s->failed_pc=0x0c07663eu; return 0; }
write(ram,r[15]+r[0],r[1],4);
goto P_0c076640;
P_0c076640: /* original 905b, guest PC 0x0c076640 */
if(!s->budget--) { s->failed_pc=0x0c076640u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0766fau,2);
goto P_0c076642;
P_0c076642: /* original 03fe, guest PC 0x0c076642 */
if(!s->budget--) { s->failed_pc=0x0c076642u; return 0; }
r[3]=read(ram,r[15]+r[0],4);
goto P_0c076644;
P_0c076644: /* original e03c, guest PC 0x0c076644 */
if(!s->budget--) { s->failed_pc=0x0c076644u; return 0; }
r[0]=0x0000003cu;
goto P_0c076646;
P_0c076646: /* original 023d, guest PC 0x0c076646 */
if(!s->budget--) { s->failed_pc=0x0c076646u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[3]+r[0],2);
goto P_0c076648;
P_0c076648: /* original 9058, guest PC 0x0c076648 */
if(!s->budget--) { s->failed_pc=0x0c076648u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0766fcu,2);
goto P_0c07664a;
P_0c07664a: /* original 622d, guest PC 0x0c07664a */
if(!s->budget--) { s->failed_pc=0x0c07664au; return 0; }
r[2]=r[2]&65535u;
goto P_0c07664c;
P_0c07664c: /* original 013d, guest PC 0x0c07664c */
if(!s->budget--) { s->failed_pc=0x0c07664cu; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,r[3]+r[0],2);
goto P_0c07664e;
P_0c07664e: /* original 3210, guest PC 0x0c07664e */
if(!s->budget--) { s->failed_pc=0x0c07664eu; return 0; }
r[17]=(r[17]&~1u)|((r[2]==r[1])!=0);
goto P_0c076650;
P_0c076650: /* original 8b07, guest PC 0x0c076650 */
if(!s->budget--) { s->failed_pc=0x0c076650u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c076662; }
goto P_0c076652;
P_0c076652: /* original 9051, guest PC 0x0c076652 */
if(!s->budget--) { s->failed_pc=0x0c076652u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0766f8u,2);
goto P_0c076654;
P_0c076654: /* original 9353, guest PC 0x0c076654 */
if(!s->budget--) { s->failed_pc=0x0c076654u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0766feu,2);
goto P_0c076656;
P_0c076656: /* original 02fe, guest PC 0x0c076656 */
if(!s->budget--) { s->failed_pc=0x0c076656u; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c076658;
P_0c076658: /* original 904e, guest PC 0x0c076658 */
if(!s->budget--) { s->failed_pc=0x0c076658u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0766f8u,2);
goto P_0c07665a;
P_0c07665a: /* original 0237, guest PC 0x0c07665a */
if(!s->budget--) { s->failed_pc=0x0c07665au; return 0; }
r[19]=r[2]*r[3];
goto P_0c07665c;
P_0c07665c: /* original 021a, guest PC 0x0c07665c */
if(!s->budget--) { s->failed_pc=0x0c07665cu; return 0; }
r[2]=r[19];
goto P_0c07665e;
P_0c07665e: /* original a009, guest PC 0x0c07665e */
if(!s->budget--) { s->failed_pc=0x0c07665eu; return 0; }
write(ram,r[15]+r[0],r[2],4);
goto P_0c076674;
P_0c076660: /* original 0f26, guest PC 0x0c076660 */
if(!s->budget--) { s->failed_pc=0x0c076660u; return 0; }
write(ram,r[15]+r[0],r[2],4);
goto P_0c076662;
P_0c076662: /* original 9049, guest PC 0x0c076662 */
if(!s->budget--) { s->failed_pc=0x0c076662u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0766f8u,2);
goto P_0c076664;
P_0c076664: /* original 03fe, guest PC 0x0c076664 */
if(!s->budget--) { s->failed_pc=0x0c076664u; return 0; }
r[3]=read(ram,r[15]+r[0],4);
goto P_0c076666;
P_0c076666: /* original 9047, guest PC 0x0c076666 */
if(!s->budget--) { s->failed_pc=0x0c076666u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0766f8u,2);
goto P_0c076668;
P_0c076668: /* original 6233, guest PC 0x0c076668 */
if(!s->budget--) { s->failed_pc=0x0c076668u; return 0; }
r[2]=r[3];
goto P_0c07666a;
P_0c07666a: /* original 4300, guest PC 0x0c07666a */
if(!s->budget--) { s->failed_pc=0x0c07666au; return 0; }
r[17]=(r[17]&~1u)|((r[3]>>31)!=0);
r[3]<<=1;
goto P_0c07666c;
P_0c07666c: /* original 332c, guest PC 0x0c07666c */
if(!s->budget--) { s->failed_pc=0x0c07666cu; return 0; }
r[3]+=r[2];
goto P_0c07666e;
P_0c07666e: /* original 4318, guest PC 0x0c07666e */
if(!s->budget--) { s->failed_pc=0x0c07666eu; return 0; }
r[3]<<=8;
goto P_0c076670;
P_0c076670: /* original 4300, guest PC 0x0c076670 */
if(!s->budget--) { s->failed_pc=0x0c076670u; return 0; }
r[17]=(r[17]&~1u)|((r[3]>>31)!=0);
r[3]<<=1;
goto P_0c076672;
P_0c076672: /* original 0f36, guest PC 0x0c076672 */
if(!s->budget--) { s->failed_pc=0x0c076672u; return 0; }
write(ram,r[15]+r[0],r[3],4);
goto P_0c076674;
P_0c076674: /* original e074, guest PC 0x0c076674 */
if(!s->budget--) { s->failed_pc=0x0c076674u; return 0; }
r[0]=0x00000074u;
goto P_0c076676;
P_0c076676: /* original 9143, guest PC 0x0c076676 */
if(!s->budget--) { s->failed_pc=0x0c076676u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c076700u,2);
goto P_0c076678;
P_0c076678: /* original 03fe, guest PC 0x0c076678 */
if(!s->budget--) { s->failed_pc=0x0c076678u; return 0; }
r[3]=read(ram,r[15]+r[0],4);
goto P_0c07667a;
P_0c07667a: /* original 3313, guest PC 0x0c07667a */
if(!s->budget--) { s->failed_pc=0x0c07667au; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>=(int32_t)r[1])!=0);
goto P_0c07667c;
P_0c07667c: /* original 8903, guest PC 0x0c07667c */
if(!s->budget--) { s->failed_pc=0x0c07667cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c076686; }
goto P_0c07667e;
P_0c07667e: /* original 9038, guest PC 0x0c07667e */
if(!s->budget--) { s->failed_pc=0x0c07667eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0766f2u,2);
goto P_0c076680;
P_0c076680: /* original e300, guest PC 0x0c076680 */
if(!s->budget--) { s->failed_pc=0x0c076680u; return 0; }
r[3]=0x00000000u;
goto P_0c076682;
P_0c076682: /* original a002, guest PC 0x0c076682 */
if(!s->budget--) { s->failed_pc=0x0c076682u; return 0; }
write(ram,r[15]+r[0],r[3],4);
goto P_0c07668a;
P_0c076684: /* original 0f36, guest PC 0x0c076684 */
if(!s->budget--) { s->failed_pc=0x0c076684u; return 0; }
write(ram,r[15]+r[0],r[3],4);
goto P_0c076686;
P_0c076686: /* original 9034, guest PC 0x0c076686 */
if(!s->budget--) { s->failed_pc=0x0c076686u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0766f2u,2);
goto P_0c076688;
P_0c076688: /* original 0f16, guest PC 0x0c076688 */
if(!s->budget--) { s->failed_pc=0x0c076688u; return 0; }
write(ram,r[15]+r[0],r[1],4);
goto P_0c07668a;
P_0c07668a: /* original 9035, guest PC 0x0c07668a */
if(!s->budget--) { s->failed_pc=0x0c07668au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0766f8u,2);
goto P_0c07668c;
P_0c07668c: /* original 03fe, guest PC 0x0c07668c */
if(!s->budget--) { s->failed_pc=0x0c07668cu; return 0; }
r[3]=read(ram,r[15]+r[0],4);
goto P_0c07668e;
P_0c07668e: /* original e074, guest PC 0x0c07668e */
if(!s->budget--) { s->failed_pc=0x0c07668eu; return 0; }
r[0]=0x00000074u;
goto P_0c076690;
P_0c076690: /* original 02fe, guest PC 0x0c076690 */
if(!s->budget--) { s->failed_pc=0x0c076690u; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c076692;
P_0c076692: /* original e074, guest PC 0x0c076692 */
if(!s->budget--) { s->failed_pc=0x0c076692u; return 0; }
r[0]=0x00000074u;
goto P_0c076694;
P_0c076694: /* original 3238, guest PC 0x0c076694 */
if(!s->budget--) { s->failed_pc=0x0c076694u; return 0; }
r[2]-=r[3];
goto P_0c076696;
P_0c076696: /* original 0f26, guest PC 0x0c076696 */
if(!s->budget--) { s->failed_pc=0x0c076696u; return 0; }
write(ram,r[15]+r[0],r[2],4);
goto P_0c076698;
P_0c076698: /* original 902b, guest PC 0x0c076698 */
if(!s->budget--) { s->failed_pc=0x0c076698u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0766f2u,2);
goto P_0c07669a;
P_0c07669a: /* original 01fe, guest PC 0x0c07669a */
if(!s->budget--) { s->failed_pc=0x0c07669au; return 0; }
r[1]=read(ram,r[15]+r[0],4);
goto P_0c07669c;
P_0c07669c: /* original 3212, guest PC 0x0c07669c */
if(!s->budget--) { s->failed_pc=0x0c07669cu; return 0; }
r[17]=(r[17]&~1u)|((r[2]>=r[1])!=0);
goto P_0c07669e;
P_0c07669e: /* original 8903, guest PC 0x0c07669e */
if(!s->budget--) { s->failed_pc=0x0c07669eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0766a8; }
goto P_0c0766a0;
P_0c0766a0: /* original 9027, guest PC 0x0c0766a0 */
if(!s->budget--) { s->failed_pc=0x0c0766a0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0766f2u,2);
goto P_0c0766a2;
P_0c0766a2: /* original 01fe, guest PC 0x0c0766a2 */
if(!s->budget--) { s->failed_pc=0x0c0766a2u; return 0; }
r[1]=read(ram,r[15]+r[0],4);
goto P_0c0766a4;
P_0c0766a4: /* original e074, guest PC 0x0c0766a4 */
if(!s->budget--) { s->failed_pc=0x0c0766a4u; return 0; }
r[0]=0x00000074u;
goto P_0c0766a6;
P_0c0766a6: /* original 0f16, guest PC 0x0c0766a6 */
if(!s->budget--) { s->failed_pc=0x0c0766a6u; return 0; }
write(ram,r[15]+r[0],r[1],4);
goto P_0c0766a8;
P_0c0766a8: /* original e074, guest PC 0x0c0766a8 */
if(!s->budget--) { s->failed_pc=0x0c0766a8u; return 0; }
r[0]=0x00000074u;
goto P_0c0766aa;
P_0c0766aa: /* original 932a, guest PC 0x0c0766aa */
if(!s->budget--) { s->failed_pc=0x0c0766aau; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c076702u,2);
goto P_0c0766ac;
P_0c0766ac: /* original 02fe, guest PC 0x0c0766ac */
if(!s->budget--) { s->failed_pc=0x0c0766acu; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c0766ae;
P_0c0766ae: /* original 3237, guest PC 0x0c0766ae */
if(!s->budget--) { s->failed_pc=0x0c0766aeu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>(int32_t)r[3])!=0);
goto P_0c0766b0;
P_0c0766b0: /* original 8b01, guest PC 0x0c0766b0 */
if(!s->budget--) { s->failed_pc=0x0c0766b0u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0766b6; }
goto P_0c0766b2;
P_0c0766b2: /* original e074, guest PC 0x0c0766b2 */
if(!s->budget--) { s->failed_pc=0x0c0766b2u; return 0; }
r[0]=0x00000074u;
goto P_0c0766b4;
P_0c0766b4: /* original 0f36, guest PC 0x0c0766b4 */
if(!s->budget--) { s->failed_pc=0x0c0766b4u; return 0; }
write(ram,r[15]+r[0],r[3],4);
goto P_0c0766b6;
P_0c0766b6: /* original e074, guest PC 0x0c0766b6 */
if(!s->budget--) { s->failed_pc=0x0c0766b6u; return 0; }
r[0]=0x00000074u;
goto P_0c0766b8;
P_0c0766b8: /* original 63f3, guest PC 0x0c0766b8 */
if(!s->budget--) { s->failed_pc=0x0c0766b8u; return 0; }
r[3]=r[15];
goto P_0c0766ba;
P_0c0766ba: /* original 01fe, guest PC 0x0c0766ba */
if(!s->budget--) { s->failed_pc=0x0c0766bau; return 0; }
r[1]=read(ram,r[15]+r[0],4);
goto P_0c0766bc;
P_0c0766bc: /* original 7314, guest PC 0x0c0766bc */
if(!s->budget--) { s->failed_pc=0x0c0766bcu; return 0; }
r[3]+=0x00000014u;
goto P_0c0766be;
P_0c0766be: /* original 62f3, guest PC 0x0c0766be */
if(!s->budget--) { s->failed_pc=0x0c0766beu; return 0; }
r[2]=r[15];
goto P_0c0766c0;
P_0c0766c0: /* original 720c, guest PC 0x0c0766c0 */
if(!s->budget--) { s->failed_pc=0x0c0766c0u; return 0; }
r[2]+=0x0000000cu;
goto P_0c0766c2;
P_0c0766c2: /* original 415a, guest PC 0x0c0766c2 */
if(!s->budget--) { s->failed_pc=0x0c0766c2u; return 0; }
r[53]=r[1];
goto P_0c0766c4;
P_0c0766c4: /* original f0fd, guest PC 0x0c0766c4 */
if(!s->budget--) { s->failed_pc=0x0c0766c4u; return 0; }
vf3_fpu_fsca(r[53],fr+0);
goto P_0c0766c6;
P_0c0766c6: /* original f30a, guest PC 0x0c0766c6 */
if(!s->budget--) { s->failed_pc=0x0c0766c6u; return 0; }
vf3_matrix_store(s,ram,0,r[3]);
goto P_0c0766c8;
P_0c0766c8: /* original f21a, guest PC 0x0c0766c8 */
if(!s->budget--) { s->failed_pc=0x0c0766c8u; return 0; }
vf3_matrix_store(s,ram,1,r[2]);
goto P_0c0766ca;
P_0c0766ca: /* original 9013, guest PC 0x0c0766ca */
if(!s->budget--) { s->failed_pc=0x0c0766cau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0766f4u,2);
goto P_0c0766cc;
P_0c0766cc: /* original 03fe, guest PC 0x0c0766cc */
if(!s->budget--) { s->failed_pc=0x0c0766ccu; return 0; }
r[3]=read(ram,r[15]+r[0],4);
goto P_0c0766ce;
P_0c0766ce: /* original c70e, guest PC 0x0c0766ce */
if(!s->budget--) { s->failed_pc=0x0c0766ceu; return 0; }
r[0]=0x0c076708u;
goto P_0c0766d0;
P_0c0766d0: /* original f308, guest PC 0x0c0766d0 */
if(!s->budget--) { s->failed_pc=0x0c0766d0u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c0766d2;
P_0c0766d2: /* original c70e, guest PC 0x0c0766d2 */
if(!s->budget--) { s->failed_pc=0x0c0766d2u; return 0; }
r[0]=0x0c07670cu;
goto P_0c0766d4;
P_0c0766d4: /* original f008, guest PC 0x0c0766d4 */
if(!s->budget--) { s->failed_pc=0x0c0766d4u; return 0; }
vf3_matrix_load(s,ram,0,r[0]);
goto P_0c0766d6;
P_0c0766d6: /* original 9015, guest PC 0x0c0766d6 */
if(!s->budget--) { s->failed_pc=0x0c0766d6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c076704u,2);
goto P_0c0766d8;
P_0c0766d8: /* original f236, guest PC 0x0c0766d8 */
if(!s->budget--) { s->failed_pc=0x0c0766d8u; return 0; }
vf3_matrix_load(s,ram,2,r[3]+r[0]);
goto P_0c0766da;
P_0c0766da: /* original e020, guest PC 0x0c0766da */
if(!s->budget--) { s->failed_pc=0x0c0766dau; return 0; }
r[0]=0x00000020u;
goto P_0c0766dc;
P_0c0766dc: /* original f32e, guest PC 0x0c0766dc */
if(!s->budget--) { s->failed_pc=0x0c0766dcu; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[2],fr[3],r[18]);
goto P_0c0766de;
P_0c0766de: /* original f2f6, guest PC 0x0c0766de */
if(!s->budget--) { s->failed_pc=0x0c0766deu; return 0; }
vf3_matrix_load(s,ram,2,r[15]+r[0]);
goto P_0c0766e0;
P_0c0766e0: /* original c70b, guest PC 0x0c0766e0 */
if(!s->budget--) { s->failed_pc=0x0c0766e0u; return 0; }
r[0]=0x0c076710u;
goto P_0c0766e2;
P_0c0766e2: /* original f233, guest PC 0x0c0766e2 */
if(!s->budget--) { s->failed_pc=0x0c0766e2u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'/');
goto P_0c0766e4;
P_0c0766e4: /* original ff2a, guest PC 0x0c0766e4 */
if(!s->budget--) { s->failed_pc=0x0c0766e4u; return 0; }
vf3_matrix_store(s,ram,2,r[15]);
goto P_0c0766e6;
P_0c0766e6: /* original f108, guest PC 0x0c0766e6 */
if(!s->budget--) { s->failed_pc=0x0c0766e6u; return 0; }
vf3_matrix_load(s,ram,1,r[0]);
goto P_0c0766e8;
P_0c0766e8: /* original f125, guest PC 0x0c0766e8 */
if(!s->budget--) { s->failed_pc=0x0c0766e8u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[1])>as_float(fr[2]))!=0);
goto P_0c0766ea;
P_0c0766ea: /* original 8b13, guest PC 0x0c0766ea */
if(!s->budget--) { s->failed_pc=0x0c0766eau; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c076714; }
goto P_0c0766ec;
P_0c0766ec: /* original a014, guest PC 0x0c0766ec */
if(!s->budget--) { s->failed_pc=0x0c0766ecu; return 0; }
fr[3]=0;
goto P_0c076718;
P_0c0766ee: /* original f38d, guest PC 0x0c0766ee */
if(!s->budget--) { s->failed_pc=0x0c0766eeu; return 0; }
fr[3]=0;
return vf3_matrix_family(0x0c0766f0u,s,ram);
P_0c076714: /* original f3f8, guest PC 0x0c076714 */
if(!s->budget--) { s->failed_pc=0x0c076714u; return 0; }
vf3_matrix_load(s,ram,3,r[15]);
goto P_0c076716;
P_0c076716: /* original f36d, guest PC 0x0c076716 */
if(!s->budget--) { s->failed_pc=0x0c076716u; return 0; }
fr[3]=vf3_fpu_sqrt(fr[3],r[18]);
goto P_0c076718;
P_0c076718: /* original e014, guest PC 0x0c076718 */
if(!s->budget--) { s->failed_pc=0x0c076718u; return 0; }
r[0]=0x00000014u;
goto P_0c07671a;
P_0c07671a: /* original 63f3, guest PC 0x0c07671a */
if(!s->budget--) { s->failed_pc=0x0c07671au; return 0; }
r[3]=r[15];
goto P_0c07671c;
P_0c07671c: /* original 7308, guest PC 0x0c07671c */
if(!s->budget--) { s->failed_pc=0x0c07671cu; return 0; }
r[3]+=0x00000008u;
goto P_0c07671e;
P_0c07671e: /* original ff3a, guest PC 0x0c07671e */
if(!s->budget--) { s->failed_pc=0x0c07671eu; return 0; }
vf3_matrix_store(s,ram,3,r[15]);
goto P_0c076720;
P_0c076720: /* original f2f6, guest PC 0x0c076720 */
if(!s->budget--) { s->failed_pc=0x0c076720u; return 0; }
vf3_matrix_load(s,ram,2,r[15]+r[0]);
goto P_0c076722;
P_0c076722: /* original e004, guest PC 0x0c076722 */
if(!s->budget--) { s->failed_pc=0x0c076722u; return 0; }
r[0]=0x00000004u;
goto P_0c076724;
P_0c076724: /* original 62f3, guest PC 0x0c076724 */
if(!s->budget--) { s->failed_pc=0x0c076724u; return 0; }
r[2]=r[15];
goto P_0c076726;
P_0c076726: /* original 7210, guest PC 0x0c076726 */
if(!s->budget--) { s->failed_pc=0x0c076726u; return 0; }
r[2]+=0x00000010u;
goto P_0c076728;
P_0c076728: /* original f232, guest PC 0x0c076728 */
if(!s->budget--) { s->failed_pc=0x0c076728u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c07672a;
P_0c07672a: /* original ff27, guest PC 0x0c07672a */
if(!s->budget--) { s->failed_pc=0x0c07672au; return 0; }
vf3_matrix_store(s,ram,2,r[15]+r[0]);
goto P_0c07672c;
P_0c07672c: /* original e058, guest PC 0x0c07672c */
if(!s->budget--) { s->failed_pc=0x0c07672cu; return 0; }
r[0]=0x00000058u;
goto P_0c07672e;
P_0c07672e: /* original 01fe, guest PC 0x0c07672e */
if(!s->budget--) { s->failed_pc=0x0c07672eu; return 0; }
r[1]=read(ram,r[15]+r[0],4);
goto P_0c076730;
P_0c076730: /* original 415a, guest PC 0x0c076730 */
if(!s->budget--) { s->failed_pc=0x0c076730u; return 0; }
r[53]=r[1];
goto P_0c076732;
P_0c076732: /* original f0fd, guest PC 0x0c076732 */
if(!s->budget--) { s->failed_pc=0x0c076732u; return 0; }
vf3_fpu_fsca(r[53],fr+0);
goto P_0c076734;
P_0c076734: /* original f20a, guest PC 0x0c076734 */
if(!s->budget--) { s->failed_pc=0x0c076734u; return 0; }
vf3_matrix_store(s,ram,0,r[2]);
goto P_0c076736;
P_0c076736: /* original f31a, guest PC 0x0c076736 */
if(!s->budget--) { s->failed_pc=0x0c076736u; return 0; }
vf3_matrix_store(s,ram,1,r[3]);
goto P_0c076738;
P_0c076738: /* original 900c, guest PC 0x0c076738 */
if(!s->budget--) { s->failed_pc=0x0c076738u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c076754u,2);
goto P_0c07673a;
P_0c07673a: /* original f38d, guest PC 0x0c07673a */
if(!s->budget--) { s->failed_pc=0x0c07673au; return 0; }
fr[3]=0;
goto P_0c07673c;
P_0c07673c: /* original 03fe, guest PC 0x0c07673c */
if(!s->budget--) { s->failed_pc=0x0c07673cu; return 0; }
r[3]=read(ram,r[15]+r[0],4);
goto P_0c07673e;
P_0c07673e: /* original 900a, guest PC 0x0c07673e */
if(!s->budget--) { s->failed_pc=0x0c07673eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c076756u,2);
goto P_0c076740;
P_0c076740: /* original f236, guest PC 0x0c076740 */
if(!s->budget--) { s->failed_pc=0x0c076740u; return 0; }
vf3_matrix_load(s,ram,2,r[3]+r[0]);
goto P_0c076742;
P_0c076742: /* original f234, guest PC 0x0c076742 */
if(!s->budget--) { s->failed_pc=0x0c076742u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[2])==as_float(fr[3]))!=0);
goto P_0c076744;
P_0c076744: /* original 8b09, guest PC 0x0c076744 */
if(!s->budget--) { s->failed_pc=0x0c076744u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07675a; }
goto P_0c076746;
P_0c076746: /* original 9005, guest PC 0x0c076746 */
if(!s->budget--) { s->failed_pc=0x0c076746u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c076754u,2);
goto P_0c076748;
P_0c076748: /* original 02fe, guest PC 0x0c076748 */
if(!s->budget--) { s->failed_pc=0x0c076748u; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c07674a;
P_0c07674a: /* original e004, guest PC 0x0c07674a */
if(!s->budget--) { s->failed_pc=0x0c07674au; return 0; }
r[0]=0x00000004u;
goto P_0c07674c;
P_0c07674c: /* original f2f6, guest PC 0x0c07674c */
if(!s->budget--) { s->failed_pc=0x0c07674cu; return 0; }
vf3_matrix_load(s,ram,2,r[15]+r[0]);
goto P_0c07674e;
P_0c07674e: /* original 9003, guest PC 0x0c07674e */
if(!s->budget--) { s->failed_pc=0x0c07674eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c076758u,2);
goto P_0c076750;
P_0c076750: /* original a00d, guest PC 0x0c076750 */
if(!s->budget--) { s->failed_pc=0x0c076750u; return 0; }
vf3_matrix_store(s,ram,2,r[2]+r[0]);
goto P_0c07676e;
P_0c076752: /* original f227, guest PC 0x0c076752 */
if(!s->budget--) { s->failed_pc=0x0c076752u; return 0; }
vf3_matrix_store(s,ram,2,r[2]+r[0]);
return vf3_matrix_family(0x0c076754u,s,ram);
P_0c07675a: /* original 9099, guest PC 0x0c07675a */
if(!s->budget--) { s->failed_pc=0x0c07675au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c076890u,2);
goto P_0c07675c;
P_0c07675c: /* original 02fe, guest PC 0x0c07675c */
if(!s->budget--) { s->failed_pc=0x0c07675cu; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c07675e;
P_0c07675e: /* original 9098, guest PC 0x0c07675e */
if(!s->budget--) { s->failed_pc=0x0c07675eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c076892u,2);
goto P_0c076760;
P_0c076760: /* original 6323, guest PC 0x0c076760 */
if(!s->budget--) { s->failed_pc=0x0c076760u; return 0; }
r[3]=r[2];
goto P_0c076762;
P_0c076762: /* original f236, guest PC 0x0c076762 */
if(!s->budget--) { s->failed_pc=0x0c076762u; return 0; }
vf3_matrix_load(s,ram,2,r[3]+r[0]);
goto P_0c076764;
P_0c076764: /* original e004, guest PC 0x0c076764 */
if(!s->budget--) { s->failed_pc=0x0c076764u; return 0; }
r[0]=0x00000004u;
goto P_0c076766;
P_0c076766: /* original f1f6, guest PC 0x0c076766 */
if(!s->budget--) { s->failed_pc=0x0c076766u; return 0; }
vf3_matrix_load(s,ram,1,r[15]+r[0]);
goto P_0c076768;
P_0c076768: /* original 9094, guest PC 0x0c076768 */
if(!s->budget--) { s->failed_pc=0x0c076768u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c076894u,2);
goto P_0c07676a;
P_0c07676a: /* original f122, guest PC 0x0c07676a */
if(!s->budget--) { s->failed_pc=0x0c07676au; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[2],r[18],'*');
goto P_0c07676c;
P_0c07676c: /* original f217, guest PC 0x0c07676c */
if(!s->budget--) { s->failed_pc=0x0c07676cu; return 0; }
vf3_matrix_store(s,ram,1,r[2]+r[0]);
goto P_0c07676e;
P_0c07676e: /* original 908f, guest PC 0x0c07676e */
if(!s->budget--) { s->failed_pc=0x0c07676eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c076890u,2);
goto P_0c076770;
P_0c076770: /* original f1f8, guest PC 0x0c076770 */
if(!s->budget--) { s->failed_pc=0x0c076770u; return 0; }
vf3_matrix_load(s,ram,1,r[15]);
goto P_0c076772;
P_0c076772: /* original 03fe, guest PC 0x0c076772 */
if(!s->budget--) { s->failed_pc=0x0c076772u; return 0; }
r[3]=read(ram,r[15]+r[0],4);
goto P_0c076774;
P_0c076774: /* original e00c, guest PC 0x0c076774 */
if(!s->budget--) { s->failed_pc=0x0c076774u; return 0; }
r[0]=0x0000000cu;
goto P_0c076776;
P_0c076776: /* original f3f6, guest PC 0x0c076776 */
if(!s->budget--) { s->failed_pc=0x0c076776u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c076778;
P_0c076778: /* original e010, guest PC 0x0c076778 */
if(!s->budget--) { s->failed_pc=0x0c076778u; return 0; }
r[0]=0x00000010u;
goto P_0c07677a;
P_0c07677a: /* original f2f6, guest PC 0x0c07677a */
if(!s->budget--) { s->failed_pc=0x0c07677au; return 0; }
vf3_matrix_load(s,ram,2,r[15]+r[0]);
goto P_0c07677c;
P_0c07677c: /* original 908b, guest PC 0x0c07677c */
if(!s->budget--) { s->failed_pc=0x0c07677cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c076896u,2);
goto P_0c07677e;
P_0c07677e: /* original f232, guest PC 0x0c07677e */
if(!s->budget--) { s->failed_pc=0x0c07677eu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c076780;
P_0c076780: /* original f212, guest PC 0x0c076780 */
if(!s->budget--) { s->failed_pc=0x0c076780u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[1],r[18],'*');
goto P_0c076782;
P_0c076782: /* original f24d, guest PC 0x0c076782 */
if(!s->budget--) { s->failed_pc=0x0c076782u; return 0; }
fr[2]^=0x80000000u;
goto P_0c076784;
P_0c076784: /* original f327, guest PC 0x0c076784 */
if(!s->budget--) { s->failed_pc=0x0c076784u; return 0; }
vf3_matrix_store(s,ram,2,r[3]+r[0]);
goto P_0c076786;
P_0c076786: /* original 9083, guest PC 0x0c076786 */
if(!s->budget--) { s->failed_pc=0x0c076786u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c076890u,2);
goto P_0c076788;
P_0c076788: /* original f1f8, guest PC 0x0c076788 */
if(!s->budget--) { s->failed_pc=0x0c076788u; return 0; }
vf3_matrix_load(s,ram,1,r[15]);
goto P_0c07678a;
P_0c07678a: /* original 03fe, guest PC 0x0c07678a */
if(!s->budget--) { s->failed_pc=0x0c07678au; return 0; }
r[3]=read(ram,r[15]+r[0],4);
goto P_0c07678c;
P_0c07678c: /* original e008, guest PC 0x0c07678c */
if(!s->budget--) { s->failed_pc=0x0c07678cu; return 0; }
r[0]=0x00000008u;
goto P_0c07678e;
P_0c07678e: /* original f3f6, guest PC 0x0c07678e */
if(!s->budget--) { s->failed_pc=0x0c07678eu; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c076790;
P_0c076790: /* original e00c, guest PC 0x0c076790 */
if(!s->budget--) { s->failed_pc=0x0c076790u; return 0; }
r[0]=0x0000000cu;
goto P_0c076792;
P_0c076792: /* original f2f6, guest PC 0x0c076792 */
if(!s->budget--) { s->failed_pc=0x0c076792u; return 0; }
vf3_matrix_load(s,ram,2,r[15]+r[0]);
goto P_0c076794;
P_0c076794: /* original 9080, guest PC 0x0c076794 */
if(!s->budget--) { s->failed_pc=0x0c076794u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c076898u,2);
goto P_0c076796;
P_0c076796: /* original f232, guest PC 0x0c076796 */
if(!s->budget--) { s->failed_pc=0x0c076796u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c076798;
P_0c076798: /* original f212, guest PC 0x0c076798 */
if(!s->budget--) { s->failed_pc=0x0c076798u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[1],r[18],'*');
goto P_0c07679a;
P_0c07679a: /* original f24d, guest PC 0x0c07679a */
if(!s->budget--) { s->failed_pc=0x0c07679au; return 0; }
fr[2]^=0x80000000u;
goto P_0c07679c;
P_0c07679c: /* original f327, guest PC 0x0c07679c */
if(!s->budget--) { s->failed_pc=0x0c07679cu; return 0; }
vf3_matrix_store(s,ram,2,r[3]+r[0]);
goto P_0c07679e;
P_0c07679e: /* original 907c, guest PC 0x0c07679e */
if(!s->budget--) { s->failed_pc=0x0c07679eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07689au,2);
goto P_0c0767a0;
P_0c0767a0: /* original 917c, guest PC 0x0c0767a0 */
if(!s->budget--) { s->failed_pc=0x0c0767a0u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07689cu,2);
goto P_0c0767a2;
P_0c0767a2: /* original 00fe, guest PC 0x0c0767a2 */
if(!s->budget--) { s->failed_pc=0x0c0767a2u; return 0; }
r[0]=read(ram,r[15]+r[0],4);
goto P_0c0767a4;
P_0c0767a4: /* original 001e, guest PC 0x0c0767a4 */
if(!s->budget--) { s->failed_pc=0x0c0767a4u; return 0; }
r[0]=read(ram,r[1]+r[0],4);
goto P_0c0767a6;
P_0c0767a6: /* original c802, guest PC 0x0c0767a6 */
if(!s->budget--) { s->failed_pc=0x0c0767a6u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&2u)==0)!=0);
goto P_0c0767a8;
P_0c0767a8: /* original 8b01, guest PC 0x0c0767a8 */
if(!s->budget--) { s->failed_pc=0x0c0767a8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0767ae; }
goto P_0c0767aa;
P_0c0767aa: /* original a0a8, guest PC 0x0c0767aa */
if(!s->budget--) { s->failed_pc=0x0c0767aau; return 0; }
goto P_0c0768fe;
P_0c0767ac: /* original 0009, guest PC 0x0c0767ac */
if(!s->budget--) { s->failed_pc=0x0c0767acu; return 0; }
goto P_0c0767ae;
P_0c0767ae: /* original e054, guest PC 0x0c0767ae */
if(!s->budget--) { s->failed_pc=0x0c0767aeu; return 0; }
r[0]=0x00000054u;
goto P_0c0767b0;
P_0c0767b0: /* original 03fe, guest PC 0x0c0767b0 */
if(!s->budget--) { s->failed_pc=0x0c0767b0u; return 0; }
r[3]=read(ram,r[15]+r[0],4);
goto P_0c0767b2;
P_0c0767b2: /* original 9074, guest PC 0x0c0767b2 */
if(!s->budget--) { s->failed_pc=0x0c0767b2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07689eu,2);
goto P_0c0767b4;
P_0c0767b4: /* original 0f36, guest PC 0x0c0767b4 */
if(!s->budget--) { s->failed_pc=0x0c0767b4u; return 0; }
write(ram,r[15]+r[0],r[3],4);
goto P_0c0767b6;
P_0c0767b6: /* original 906b, guest PC 0x0c0767b6 */
if(!s->budget--) { s->failed_pc=0x0c0767b6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c076890u,2);
goto P_0c0767b8;
P_0c0767b8: /* original 02fe, guest PC 0x0c0767b8 */
if(!s->budget--) { s->failed_pc=0x0c0767b8u; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c0767ba;
P_0c0767ba: /* original 9071, guest PC 0x0c0767ba */
if(!s->budget--) { s->failed_pc=0x0c0767bau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0768a0u,2);
goto P_0c0767bc;
P_0c0767bc: /* original 032c, guest PC 0x0c0767bc */
if(!s->budget--) { s->failed_pc=0x0c0767bcu; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[2]+r[0],1);
goto P_0c0767be;
P_0c0767be: /* original e201, guest PC 0x0c0767be */
if(!s->budget--) { s->failed_pc=0x0c0767beu; return 0; }
r[2]=0x00000001u;
goto P_0c0767c0;
P_0c0767c0: /* original 633c, guest PC 0x0c0767c0 */
if(!s->budget--) { s->failed_pc=0x0c0767c0u; return 0; }
r[3]=r[3]&255u;
goto P_0c0767c2;
P_0c0767c2: /* original 3327, guest PC 0x0c0767c2 */
if(!s->budget--) { s->failed_pc=0x0c0767c2u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>(int32_t)r[2])!=0);
goto P_0c0767c4;
P_0c0767c4: /* original 891d, guest PC 0x0c0767c4 */
if(!s->budget--) { s->failed_pc=0x0c0767c4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c076802; }
goto P_0c0767c6;
P_0c0767c6: /* original 9063, guest PC 0x0c0767c6 */
if(!s->budget--) { s->failed_pc=0x0c0767c6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c076890u,2);
goto P_0c0767c8;
P_0c0767c8: /* original 01fe, guest PC 0x0c0767c8 */
if(!s->budget--) { s->failed_pc=0x0c0767c8u; return 0; }
r[1]=read(ram,r[15]+r[0],4);
goto P_0c0767ca;
P_0c0767ca: /* original 906a, guest PC 0x0c0767ca */
if(!s->budget--) { s->failed_pc=0x0c0767cau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0768a2u,2);
goto P_0c0767cc;
P_0c0767cc: /* original 031c, guest PC 0x0c0767cc */
if(!s->budget--) { s->failed_pc=0x0c0767ccu; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[1]+r[0],1);
goto P_0c0767ce;
P_0c0767ce: /* original 633c, guest PC 0x0c0767ce */
if(!s->budget--) { s->failed_pc=0x0c0767ceu; return 0; }
r[3]=r[3]&255u;
goto P_0c0767d0;
P_0c0767d0: /* original 3323, guest PC 0x0c0767d0 */
if(!s->budget--) { s->failed_pc=0x0c0767d0u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>=(int32_t)r[2])!=0);
goto P_0c0767d2;
P_0c0767d2: /* original 8916, guest PC 0x0c0767d2 */
if(!s->budget--) { s->failed_pc=0x0c0767d2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c076802; }
goto P_0c0767d4;
P_0c0767d4: /* original 905c, guest PC 0x0c0767d4 */
if(!s->budget--) { s->failed_pc=0x0c0767d4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c076890u,2);
goto P_0c0767d6;
P_0c0767d6: /* original 03fe, guest PC 0x0c0767d6 */
if(!s->budget--) { s->failed_pc=0x0c0767d6u; return 0; }
r[3]=read(ram,r[15]+r[0],4);
goto P_0c0767d8;
P_0c0767d8: /* original 9062, guest PC 0x0c0767d8 */
if(!s->budget--) { s->failed_pc=0x0c0767d8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0768a0u,2);
goto P_0c0767da;
P_0c0767da: /* original 023c, guest PC 0x0c0767da */
if(!s->budget--) { s->failed_pc=0x0c0767dau; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[3]+r[0],1);
goto P_0c0767dc;
P_0c0767dc: /* original e301, guest PC 0x0c0767dc */
if(!s->budget--) { s->failed_pc=0x0c0767dcu; return 0; }
r[3]=0x00000001u;
goto P_0c0767de;
P_0c0767de: /* original 622c, guest PC 0x0c0767de */
if(!s->budget--) { s->failed_pc=0x0c0767deu; return 0; }
r[2]=r[2]&255u;
goto P_0c0767e0;
P_0c0767e0: /* original 3233, guest PC 0x0c0767e0 */
if(!s->budget--) { s->failed_pc=0x0c0767e0u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>=(int32_t)r[3])!=0);
goto P_0c0767e2;
P_0c0767e2: /* original 8b18, guest PC 0x0c0767e2 */
if(!s->budget--) { s->failed_pc=0x0c0767e2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c076816; }
goto P_0c0767e4;
P_0c0767e4: /* original 9054, guest PC 0x0c0767e4 */
if(!s->budget--) { s->failed_pc=0x0c0767e4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c076890u,2);
goto P_0c0767e6;
P_0c0767e6: /* original 01fe, guest PC 0x0c0767e6 */
if(!s->budget--) { s->failed_pc=0x0c0767e6u; return 0; }
r[1]=read(ram,r[15]+r[0],4);
goto P_0c0767e8;
P_0c0767e8: /* original 905c, guest PC 0x0c0767e8 */
if(!s->budget--) { s->failed_pc=0x0c0767e8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0768a4u,2);
goto P_0c0767ea;
P_0c0767ea: /* original 021c, guest PC 0x0c0767ea */
if(!s->budget--) { s->failed_pc=0x0c0767eau; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[1]+r[0],1);
goto P_0c0767ec;
P_0c0767ec: /* original 622c, guest PC 0x0c0767ec */
if(!s->budget--) { s->failed_pc=0x0c0767ecu; return 0; }
r[2]=r[2]&255u;
goto P_0c0767ee;
P_0c0767ee: /* original 3233, guest PC 0x0c0767ee */
if(!s->budget--) { s->failed_pc=0x0c0767eeu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>=(int32_t)r[3])!=0);
goto P_0c0767f0;
P_0c0767f0: /* original 8b11, guest PC 0x0c0767f0 */
if(!s->budget--) { s->failed_pc=0x0c0767f0u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c076816; }
goto P_0c0767f2;
P_0c0767f2: /* original 904d, guest PC 0x0c0767f2 */
if(!s->budget--) { s->failed_pc=0x0c0767f2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c076890u,2);
goto P_0c0767f4;
P_0c0767f4: /* original 01fe, guest PC 0x0c0767f4 */
if(!s->budget--) { s->failed_pc=0x0c0767f4u; return 0; }
r[1]=read(ram,r[15]+r[0],4);
goto P_0c0767f6;
P_0c0767f6: /* original 9053, guest PC 0x0c0767f6 */
if(!s->budget--) { s->failed_pc=0x0c0767f6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0768a0u,2);
goto P_0c0767f8;
P_0c0767f8: /* original 021c, guest PC 0x0c0767f8 */
if(!s->budget--) { s->failed_pc=0x0c0767f8u; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[1]+r[0],1);
goto P_0c0767fa;
P_0c0767fa: /* original 7001, guest PC 0x0c0767fa */
if(!s->budget--) { s->failed_pc=0x0c0767fau; return 0; }
r[0]+=0x00000001u;
goto P_0c0767fc;
P_0c0767fc: /* original 011c, guest PC 0x0c0767fc */
if(!s->budget--) { s->failed_pc=0x0c0767fcu; return 0; }
r[1]=(uint32_t)(int32_t)(int8_t)read(ram,r[1]+r[0],1);
goto P_0c0767fe;
P_0c0767fe: /* original 3210, guest PC 0x0c0767fe */
if(!s->budget--) { s->failed_pc=0x0c0767feu; return 0; }
r[17]=(r[17]&~1u)|((r[2]==r[1])!=0);
goto P_0c076800;
P_0c076800: /* original 8909, guest PC 0x0c076800 */
if(!s->budget--) { s->failed_pc=0x0c076800u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c076816; }
goto P_0c076802;
P_0c076802: /* original 904a, guest PC 0x0c076802 */
if(!s->budget--) { s->failed_pc=0x0c076802u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07689au,2);
goto P_0c076804;
P_0c076804: /* original 02fe, guest PC 0x0c076804 */
if(!s->budget--) { s->failed_pc=0x0c076804u; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c076806;
P_0c076806: /* original 904e, guest PC 0x0c076806 */
if(!s->budget--) { s->failed_pc=0x0c076806u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0768a6u,2);
goto P_0c076808;
P_0c076808: /* original 032d, guest PC 0x0c076808 */
if(!s->budget--) { s->failed_pc=0x0c076808u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[2]+r[0],2);
goto P_0c07680a;
P_0c07680a: /* original e054, guest PC 0x0c07680a */
if(!s->budget--) { s->failed_pc=0x0c07680au; return 0; }
r[0]=0x00000054u;
goto P_0c07680c;
P_0c07680c: /* original 02fe, guest PC 0x0c07680c */
if(!s->budget--) { s->failed_pc=0x0c07680cu; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c07680e;
P_0c07680e: /* original 9046, guest PC 0x0c07680e */
if(!s->budget--) { s->failed_pc=0x0c07680eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07689eu,2);
goto P_0c076810;
P_0c076810: /* original 633d, guest PC 0x0c076810 */
if(!s->budget--) { s->failed_pc=0x0c076810u; return 0; }
r[3]=r[3]&65535u;
goto P_0c076812;
P_0c076812: /* original 332c, guest PC 0x0c076812 */
if(!s->budget--) { s->failed_pc=0x0c076812u; return 0; }
r[3]+=r[2];
goto P_0c076814;
P_0c076814: /* original 0f36, guest PC 0x0c076814 */
if(!s->budget--) { s->failed_pc=0x0c076814u; return 0; }
write(ram,r[15]+r[0],r[3],4);
goto P_0c076816;
P_0c076816: /* original 9040, guest PC 0x0c076816 */
if(!s->budget--) { s->failed_pc=0x0c076816u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07689au,2);
goto P_0c076818;
P_0c076818: /* original 02fe, guest PC 0x0c076818 */
if(!s->budget--) { s->failed_pc=0x0c076818u; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c07681a;
P_0c07681a: /* original 9040, guest PC 0x0c07681a */
if(!s->budget--) { s->failed_pc=0x0c07681au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07689eu,2);
goto P_0c07681c;
P_0c07681c: /* original 03fd, guest PC 0x0c07681c */
if(!s->budget--) { s->failed_pc=0x0c07681cu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+r[0],2);
goto P_0c07681e;
P_0c07681e: /* original 9042, guest PC 0x0c07681e */
if(!s->budget--) { s->failed_pc=0x0c07681eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0768a6u,2);
goto P_0c076820;
P_0c076820: /* original 0235, guest PC 0x0c076820 */
if(!s->budget--) { s->failed_pc=0x0c076820u; return 0; }
write(ram,r[2]+r[0],r[3],2);
goto P_0c076822;
P_0c076822: /* original d122, guest PC 0x0c076822 */
if(!s->budget--) { s->failed_pc=0x0c076822u; return 0; }
r[1]=read(ram,0x0c0768acu,4);
goto P_0c076824;
P_0c076824: /* original 9340, guest PC 0x0c076824 */
if(!s->budget--) { s->failed_pc=0x0c076824u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0768a8u,2);
goto P_0c076826;
P_0c076826: /* original 6212, guest PC 0x0c076826 */
if(!s->budget--) { s->failed_pc=0x0c076826u; return 0; }
tmp=read(ram,r[1],4);
r[2]=tmp;
goto P_0c076828;
P_0c076828: /* original 2238, guest PC 0x0c076828 */
if(!s->budget--) { s->failed_pc=0x0c076828u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c07682a;
P_0c07682a: /* original 8b09, guest PC 0x0c07682a */
if(!s->budget--) { s->failed_pc=0x0c07682au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c076840; }
goto P_0c07682c;
P_0c07682c: /* original d21f, guest PC 0x0c07682c */
if(!s->budget--) { s->failed_pc=0x0c07682cu; return 0; }
r[2]=read(ram,0x0c0768acu,4);
goto P_0c07682e;
P_0c07682e: /* original d320, guest PC 0x0c07682e */
if(!s->budget--) { s->failed_pc=0x0c07682eu; return 0; }
r[3]=read(ram,0x0c0768b0u,4);
goto P_0c076830;
P_0c076830: /* original 6022, guest PC 0x0c076830 */
if(!s->budget--) { s->failed_pc=0x0c076830u; return 0; }
tmp=read(ram,r[2],4);
r[0]=tmp;
goto P_0c076832;
P_0c076832: /* original 2038, guest PC 0x0c076832 */
if(!s->budget--) { s->failed_pc=0x0c076832u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[3])==0)!=0);
goto P_0c076834;
P_0c076834: /* original 8963, guest PC 0x0c076834 */
if(!s->budget--) { s->failed_pc=0x0c076834u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0768fe; }
goto P_0c076836;
P_0c076836: /* original d220, guest PC 0x0c076836 */
if(!s->budget--) { s->failed_pc=0x0c076836u; return 0; }
r[2]=read(ram,0x0c0768b8u,4);
goto P_0c076838;
P_0c076838: /* original d31e, guest PC 0x0c076838 */
if(!s->budget--) { s->failed_pc=0x0c076838u; return 0; }
r[3]=read(ram,0x0c0768b4u,4);
goto P_0c07683a;
P_0c07683a: /* original 6122, guest PC 0x0c07683a */
if(!s->budget--) { s->failed_pc=0x0c07683au; return 0; }
tmp=read(ram,r[2],4);
r[1]=tmp;
goto P_0c07683c;
P_0c07683c: /* original 2138, guest PC 0x0c07683c */
if(!s->budget--) { s->failed_pc=0x0c07683cu; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[3])==0)!=0);
goto P_0c07683e;
P_0c07683e: /* original 895e, guest PC 0x0c07683e */
if(!s->budget--) { s->failed_pc=0x0c07683eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0768fe; }
goto P_0c076840;
P_0c076840: /* original d31e, guest PC 0x0c076840 */
if(!s->budget--) { s->failed_pc=0x0c076840u; return 0; }
r[3]=read(ram,0x0c0768bcu,4);
goto P_0c076842;
P_0c076842: /* original 6030, guest PC 0x0c076842 */
if(!s->budget--) { s->failed_pc=0x0c076842u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[3],1);
r[0]=tmp;
goto P_0c076844;
P_0c076844: /* original 600c, guest PC 0x0c076844 */
if(!s->budget--) { s->failed_pc=0x0c076844u; return 0; }
r[0]=r[0]&255u;
goto P_0c076846;
P_0c076846: /* original 8803, guest PC 0x0c076846 */
if(!s->budget--) { s->failed_pc=0x0c076846u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000003u)!=0);
goto P_0c076848;
P_0c076848: /* original 8b59, guest PC 0x0c076848 */
if(!s->budget--) { s->failed_pc=0x0c076848u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0768fe; }
goto P_0c07684a;
P_0c07684a: /* original d11d, guest PC 0x0c07684a */
if(!s->budget--) { s->failed_pc=0x0c07684au; return 0; }
r[1]=read(ram,0x0c0768c0u,4);
goto P_0c07684c;
P_0c07684c: /* original 1f15, guest PC 0x0c07684c */
if(!s->budget--) { s->failed_pc=0x0c07684cu; return 0; }
write(ram,r[15]+20,r[1],4);
goto P_0c07684e;
P_0c07684e: /* original 9024, guest PC 0x0c07684e */
if(!s->budget--) { s->failed_pc=0x0c07684eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07689au,2);
goto P_0c076850;
P_0c076850: /* original 02fe, guest PC 0x0c076850 */
if(!s->budget--) { s->failed_pc=0x0c076850u; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c076852;
P_0c076852: /* original e061, guest PC 0x0c076852 */
if(!s->budget--) { s->failed_pc=0x0c076852u; return 0; }
r[0]=0x00000061u;
goto P_0c076854;
P_0c076854: /* original 012c, guest PC 0x0c076854 */
if(!s->budget--) { s->failed_pc=0x0c076854u; return 0; }
r[1]=(uint32_t)(int32_t)(int8_t)read(ram,r[2]+r[0],1);
goto P_0c076856;
P_0c076856: /* original 611c, guest PC 0x0c076856 */
if(!s->budget--) { s->failed_pc=0x0c076856u; return 0; }
r[1]=r[1]&255u;
goto P_0c076858;
P_0c076858: /* original 6213, guest PC 0x0c076858 */
if(!s->budget--) { s->failed_pc=0x0c076858u; return 0; }
r[2]=r[1];
goto P_0c07685a;
P_0c07685a: /* original 1f14, guest PC 0x0c07685a */
if(!s->budget--) { s->failed_pc=0x0c07685au; return 0; }
write(ram,r[15]+16,r[1],4);
goto P_0c07685c;
P_0c07685c: /* original 9125, guest PC 0x0c07685c */
if(!s->budget--) { s->failed_pc=0x0c07685cu; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0768aau,2);
goto P_0c07685e;
P_0c07685e: /* original 4208, guest PC 0x0c07685e */
if(!s->budget--) { s->failed_pc=0x0c07685eu; return 0; }
r[2]<<=2;
goto P_0c076860;
P_0c076860: /* original 50f5, guest PC 0x0c076860 */
if(!s->budget--) { s->failed_pc=0x0c076860u; return 0; }
r[0]=read(ram,r[15]+20,4);
goto P_0c076862;
P_0c076862: /* original 301c, guest PC 0x0c076862 */
if(!s->budget--) { s->failed_pc=0x0c076862u; return 0; }
r[0]+=r[1];
goto P_0c076864;
P_0c076864: /* original 320c, guest PC 0x0c076864 */
if(!s->budget--) { s->failed_pc=0x0c076864u; return 0; }
r[2]+=r[0];
goto P_0c076866;
P_0c076866: /* original 901a, guest PC 0x0c076866 */
if(!s->budget--) { s->failed_pc=0x0c076866u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07689eu,2);
goto P_0c076868;
P_0c076868: /* original 6222, guest PC 0x0c076868 */
if(!s->budget--) { s->failed_pc=0x0c076868u; return 0; }
tmp=read(ram,r[2],4);
r[2]=tmp;
goto P_0c07686a;
P_0c07686a: /* original 00fe, guest PC 0x0c07686a */
if(!s->budget--) { s->failed_pc=0x0c07686au; return 0; }
r[0]=read(ram,r[15]+r[0],4);
goto P_0c07686c;
P_0c07686c: /* original 3202, guest PC 0x0c07686c */
if(!s->budget--) { s->failed_pc=0x0c07686cu; return 0; }
r[17]=(r[17]&~1u)|((r[2]>=r[0])!=0);
goto P_0c07686e;
P_0c07686e: /* original 8908, guest PC 0x0c07686e */
if(!s->budget--) { s->failed_pc=0x0c07686eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c076882; }
goto P_0c076870;
P_0c076870: /* original 921b, guest PC 0x0c076870 */
if(!s->budget--) { s->failed_pc=0x0c076870u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0768aau,2);
goto P_0c076872;
P_0c076872: /* original 53f4, guest PC 0x0c076872 */
if(!s->budget--) { s->failed_pc=0x0c076872u; return 0; }
r[3]=read(ram,r[15]+16,4);
goto P_0c076874;
P_0c076874: /* original 50f5, guest PC 0x0c076874 */
if(!s->budget--) { s->failed_pc=0x0c076874u; return 0; }
r[0]=read(ram,r[15]+20,4);
goto P_0c076876;
P_0c076876: /* original 4308, guest PC 0x0c076876 */
if(!s->budget--) { s->failed_pc=0x0c076876u; return 0; }
r[3]<<=2;
goto P_0c076878;
P_0c076878: /* original 302c, guest PC 0x0c076878 */
if(!s->budget--) { s->failed_pc=0x0c076878u; return 0; }
r[0]+=r[2];
goto P_0c07687a;
P_0c07687a: /* original 330c, guest PC 0x0c07687a */
if(!s->budget--) { s->failed_pc=0x0c07687au; return 0; }
r[3]+=r[0];
goto P_0c07687c;
P_0c07687c: /* original 900f, guest PC 0x0c07687c */
if(!s->budget--) { s->failed_pc=0x0c07687cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07689eu,2);
goto P_0c07687e;
P_0c07687e: /* original 00fe, guest PC 0x0c07687e */
if(!s->budget--) { s->failed_pc=0x0c07687eu; return 0; }
r[0]=read(ram,r[15]+r[0],4);
goto P_0c076880;
P_0c076880: /* original 2302, guest PC 0x0c076880 */
if(!s->budget--) { s->failed_pc=0x0c076880u; return 0; }
write(ram,r[3],r[0],4);
goto P_0c076882;
P_0c076882: /* original 9005, guest PC 0x0c076882 */
if(!s->budget--) { s->failed_pc=0x0c076882u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c076890u,2);
goto P_0c076884;
P_0c076884: /* original 03fe, guest PC 0x0c076884 */
if(!s->budget--) { s->failed_pc=0x0c076884u; return 0; }
r[3]=read(ram,r[15]+r[0],4);
goto P_0c076886;
P_0c076886: /* original 900b, guest PC 0x0c076886 */
if(!s->budget--) { s->failed_pc=0x0c076886u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0768a0u,2);
goto P_0c076888;
P_0c076888: /* original 023c, guest PC 0x0c076888 */
if(!s->budget--) { s->failed_pc=0x0c076888u; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[3]+r[0],1);
goto P_0c07688a;
P_0c07688a: /* original 622c, guest PC 0x0c07688a */
if(!s->budget--) { s->failed_pc=0x0c07688au; return 0; }
r[2]=r[2]&255u;
goto P_0c07688c;
P_0c07688c: /* original a01a, guest PC 0x0c07688c */
if(!s->budget--) { s->failed_pc=0x0c07688cu; return 0; }
goto P_0c0768c4;
P_0c07688e: /* original 0009, guest PC 0x0c07688e */
if(!s->budget--) { s->failed_pc=0x0c07688eu; return 0; }
return vf3_matrix_family(0x0c076890u,s,ram);
P_0c0768c4: /* original 908a, guest PC 0x0c0768c4 */
if(!s->budget--) { s->failed_pc=0x0c0768c4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0769dcu,2);
goto P_0c0768c6;
P_0c0768c6: /* original 013c, guest PC 0x0c0768c6 */
if(!s->budget--) { s->failed_pc=0x0c0768c6u; return 0; }
r[1]=(uint32_t)(int32_t)(int8_t)read(ram,r[3]+r[0],1);
goto P_0c0768c8;
P_0c0768c8: /* original 9089, guest PC 0x0c0768c8 */
if(!s->budget--) { s->failed_pc=0x0c0768c8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0769deu,2);
goto P_0c0768ca;
P_0c0768ca: /* original 611c, guest PC 0x0c0768ca */
if(!s->budget--) { s->failed_pc=0x0c0768cau; return 0; }
r[1]=r[1]&255u;
goto P_0c0768cc;
P_0c0768cc: /* original 321c, guest PC 0x0c0768cc */
if(!s->budget--) { s->failed_pc=0x0c0768ccu; return 0; }
r[2]+=r[1];
goto P_0c0768ce;
P_0c0768ce: /* original 0f26, guest PC 0x0c0768ce */
if(!s->budget--) { s->failed_pc=0x0c0768ceu; return 0; }
write(ram,r[15]+r[0],r[2],4);
goto P_0c0768d0;
P_0c0768d0: /* original 9286, guest PC 0x0c0768d0 */
if(!s->budget--) { s->failed_pc=0x0c0768d0u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0769e0u,2);
goto P_0c0768d2;
P_0c0768d2: /* original 53f4, guest PC 0x0c0768d2 */
if(!s->budget--) { s->failed_pc=0x0c0768d2u; return 0; }
r[3]=read(ram,r[15]+16,4);
goto P_0c0768d4;
P_0c0768d4: /* original 50f5, guest PC 0x0c0768d4 */
if(!s->budget--) { s->failed_pc=0x0c0768d4u; return 0; }
r[0]=read(ram,r[15]+20,4);
goto P_0c0768d6;
P_0c0768d6: /* original 4308, guest PC 0x0c0768d6 */
if(!s->budget--) { s->failed_pc=0x0c0768d6u; return 0; }
r[3]<<=2;
goto P_0c0768d8;
P_0c0768d8: /* original 320c, guest PC 0x0c0768d8 */
if(!s->budget--) { s->failed_pc=0x0c0768d8u; return 0; }
r[2]+=r[0];
goto P_0c0768da;
P_0c0768da: /* original 9082, guest PC 0x0c0768da */
if(!s->budget--) { s->failed_pc=0x0c0768dau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0769e2u,2);
goto P_0c0768dc;
P_0c0768dc: /* original 332c, guest PC 0x0c0768dc */
if(!s->budget--) { s->failed_pc=0x0c0768dcu; return 0; }
r[3]+=r[2];
goto P_0c0768de;
P_0c0768de: /* original 6132, guest PC 0x0c0768de */
if(!s->budget--) { s->failed_pc=0x0c0768deu; return 0; }
tmp=read(ram,r[3],4);
r[1]=tmp;
goto P_0c0768e0;
P_0c0768e0: /* original 0f16, guest PC 0x0c0768e0 */
if(!s->budget--) { s->failed_pc=0x0c0768e0u; return 0; }
write(ram,r[15]+r[0],r[1],4);
goto P_0c0768e2;
P_0c0768e2: /* original 6213, guest PC 0x0c0768e2 */
if(!s->budget--) { s->failed_pc=0x0c0768e2u; return 0; }
r[2]=r[1];
goto P_0c0768e4;
P_0c0768e4: /* original 907b, guest PC 0x0c0768e4 */
if(!s->budget--) { s->failed_pc=0x0c0768e4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0769deu,2);
goto P_0c0768e6;
P_0c0768e6: /* original 03fe, guest PC 0x0c0768e6 */
if(!s->budget--) { s->failed_pc=0x0c0768e6u; return 0; }
r[3]=read(ram,r[15]+r[0],4);
goto P_0c0768e8;
P_0c0768e8: /* original 3232, guest PC 0x0c0768e8 */
if(!s->budget--) { s->failed_pc=0x0c0768e8u; return 0; }
r[17]=(r[17]&~1u)|((r[2]>=r[3])!=0);
goto P_0c0768ea;
P_0c0768ea: /* original 8908, guest PC 0x0c0768ea */
if(!s->budget--) { s->failed_pc=0x0c0768eau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0768fe; }
goto P_0c0768ec;
P_0c0768ec: /* original 9278, guest PC 0x0c0768ec */
if(!s->budget--) { s->failed_pc=0x0c0768ecu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0769e0u,2);
goto P_0c0768ee;
P_0c0768ee: /* original 50f5, guest PC 0x0c0768ee */
if(!s->budget--) { s->failed_pc=0x0c0768eeu; return 0; }
r[0]=read(ram,r[15]+20,4);
goto P_0c0768f0;
P_0c0768f0: /* original 53f4, guest PC 0x0c0768f0 */
if(!s->budget--) { s->failed_pc=0x0c0768f0u; return 0; }
r[3]=read(ram,r[15]+16,4);
goto P_0c0768f2;
P_0c0768f2: /* original 320c, guest PC 0x0c0768f2 */
if(!s->budget--) { s->failed_pc=0x0c0768f2u; return 0; }
r[2]+=r[0];
goto P_0c0768f4;
P_0c0768f4: /* original 9073, guest PC 0x0c0768f4 */
if(!s->budget--) { s->failed_pc=0x0c0768f4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0769deu,2);
goto P_0c0768f6;
P_0c0768f6: /* original 4308, guest PC 0x0c0768f6 */
if(!s->budget--) { s->failed_pc=0x0c0768f6u; return 0; }
r[3]<<=2;
goto P_0c0768f8;
P_0c0768f8: /* original 01fe, guest PC 0x0c0768f8 */
if(!s->budget--) { s->failed_pc=0x0c0768f8u; return 0; }
r[1]=read(ram,r[15]+r[0],4);
goto P_0c0768fa;
P_0c0768fa: /* original 332c, guest PC 0x0c0768fa */
if(!s->budget--) { s->failed_pc=0x0c0768fau; return 0; }
r[3]+=r[2];
goto P_0c0768fc;
P_0c0768fc: /* original 2312, guest PC 0x0c0768fc */
if(!s->budget--) { s->failed_pc=0x0c0768fcu; return 0; }
write(ram,r[3],r[1],4);
goto P_0c0768fe;
P_0c0768fe: /* original d23c, guest PC 0x0c0768fe */
if(!s->budget--) { s->failed_pc=0x0c0768feu; return 0; }
r[2]=read(ram,0x0c0769f0u,4);
goto P_0c076900;
P_0c076900: /* original 6322, guest PC 0x0c076900 */
if(!s->budget--) { s->failed_pc=0x0c076900u; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c076902;
P_0c076902: /* original 4315, guest PC 0x0c076902 */
if(!s->budget--) { s->failed_pc=0x0c076902u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>0)!=0);
goto P_0c076904;
P_0c076904: /* original 8b59, guest PC 0x0c076904 */
if(!s->budget--) { s->failed_pc=0x0c076904u; return 0; }
cond=r[17]&1u;
if(!cond) { return vf3_matrix_family(0x0c0769bau,s,ram); }
goto P_0c076906;
P_0c076906: /* original 906d, guest PC 0x0c076906 */
if(!s->budget--) { s->failed_pc=0x0c076906u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0769e4u,2);
goto P_0c076908;
P_0c076908: /* original e146, guest PC 0x0c076908 */
if(!s->budget--) { s->failed_pc=0x0c076908u; return 0; }
r[1]=0x00000046u;
goto P_0c07690a;
P_0c07690a: /* original 00fe, guest PC 0x0c07690a */
if(!s->budget--) { s->failed_pc=0x0c07690au; return 0; }
r[0]=read(ram,r[15]+r[0],4);
goto P_0c07690c;
P_0c07690c: /* original 031d, guest PC 0x0c07690c */
if(!s->budget--) { s->failed_pc=0x0c07690cu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[1]+r[0],2);
goto P_0c07690e;
P_0c07690e: /* original e054, guest PC 0x0c07690e */
if(!s->budget--) { s->failed_pc=0x0c07690eu; return 0; }
r[0]=0x00000054u;
goto P_0c076910;
P_0c076910: /* original 00fe, guest PC 0x0c076910 */
if(!s->budget--) { s->failed_pc=0x0c076910u; return 0; }
r[0]=read(ram,r[15]+r[0],4);
goto P_0c076912;
P_0c076912: /* original 633d, guest PC 0x0c076912 */
if(!s->budget--) { s->failed_pc=0x0c076912u; return 0; }
r[3]=r[3]&65535u;
goto P_0c076914;
P_0c076914: /* original 3306, guest PC 0x0c076914 */
if(!s->budget--) { s->failed_pc=0x0c076914u; return 0; }
r[17]=(r[17]&~1u)|((r[3]>r[0])!=0);
goto P_0c076916;
P_0c076916: /* original 8906, guest PC 0x0c076916 */
if(!s->budget--) { s->failed_pc=0x0c076916u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c076926; }
goto P_0c076918;
P_0c076918: /* original 9065, guest PC 0x0c076918 */
if(!s->budget--) { s->failed_pc=0x0c076918u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0769e6u,2);
goto P_0c07691a;
P_0c07691a: /* original e210, guest PC 0x0c07691a */
if(!s->budget--) { s->failed_pc=0x0c07691au; return 0; }
r[2]=0x00000010u;
goto P_0c07691c;
P_0c07691c: /* original 03fe, guest PC 0x0c07691c */
if(!s->budget--) { s->failed_pc=0x0c07691cu; return 0; }
r[3]=read(ram,r[15]+r[0],4);
goto P_0c07691e;
P_0c07691e: /* original 9063, guest PC 0x0c07691e */
if(!s->budget--) { s->failed_pc=0x0c07691eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0769e8u,2);
goto P_0c076920;
P_0c076920: /* original 013e, guest PC 0x0c076920 */
if(!s->budget--) { s->failed_pc=0x0c076920u; return 0; }
r[1]=read(ram,r[3]+r[0],4);
goto P_0c076922;
P_0c076922: /* original 212b, guest PC 0x0c076922 */
if(!s->budget--) { s->failed_pc=0x0c076922u; return 0; }
r[1]|=r[2];
goto P_0c076924;
P_0c076924: /* original 0316, guest PC 0x0c076924 */
if(!s->budget--) { s->failed_pc=0x0c076924u; return 0; }
write(ram,r[3]+r[0],r[1],4);
goto P_0c076926;
P_0c076926: /* original e054, guest PC 0x0c076926 */
if(!s->budget--) { s->failed_pc=0x0c076926u; return 0; }
r[0]=0x00000054u;
goto P_0c076928;
P_0c076928: /* original d332, guest PC 0x0c076928 */
if(!s->budget--) { s->failed_pc=0x0c076928u; return 0; }
r[3]=read(ram,0x0c0769f4u,4);
goto P_0c07692a;
P_0c07692a: /* original 06fe, guest PC 0x0c07692a */
if(!s->budget--) { s->failed_pc=0x0c07692au; return 0; }
r[6]=read(ram,r[15]+r[0],4);
goto P_0c07692c;
P_0c07692c: /* original 905b, guest PC 0x0c07692c */
if(!s->budget--) { s->failed_pc=0x0c07692cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0769e6u,2);
goto P_0c07692e;
P_0c07692e: /* original 05fe, guest PC 0x0c07692e */
if(!s->budget--) { s->failed_pc=0x0c07692eu; return 0; }
r[5]=read(ram,r[15]+r[0],4);
goto P_0c076930;
P_0c076930: /* original 9058, guest PC 0x0c076930 */
if(!s->budget--) { s->failed_pc=0x0c076930u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0769e4u,2);
goto P_0c076932;
P_0c076932: /* original 430b, guest PC 0x0c076932 */
if(!s->budget--) { s->failed_pc=0x0c076932u; return 0; }
target=r[3];
r[16]=0x0c076936u;
r[4]=read(ram,r[15]+r[0],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c076936u) { target=s->pc; goto dispatch; }
goto P_0c076936;
P_0c076934: /* original 04fe, guest PC 0x0c076934 */
if(!s->budget--) { s->failed_pc=0x0c076934u; return 0; }
r[4]=read(ram,r[15]+r[0],4);
goto P_0c076936;
P_0c076936: /* original 9158, guest PC 0x0c076936 */
if(!s->budget--) { s->failed_pc=0x0c076936u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0769eau,2);
goto P_0c076938;
P_0c076938: /* original 3f1c, guest PC 0x0c076938 */
if(!s->budget--) { s->failed_pc=0x0c076938u; return 0; }
r[15]+=r[1];
goto P_0c07693a;
P_0c07693a: /* original 4f16, guest PC 0x0c07693a */
if(!s->budget--) { s->failed_pc=0x0c07693au; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c07693c;
P_0c07693c: /* original 4f26, guest PC 0x0c07693c */
if(!s->budget--) { s->failed_pc=0x0c07693cu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c07693e;
P_0c07693e: /* original 000b, guest PC 0x0c07693e */
if(!s->budget--) { s->failed_pc=0x0c07693eu; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c076940: /* original 0009, guest PC 0x0c076940 */
if(!s->budget--) { s->failed_pc=0x0c076940u; return 0; }
return vf3_matrix_family(0x0c076942u,s,ram);
unsupported: s->failed_pc=target; return 0;
}
