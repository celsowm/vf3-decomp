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
int vf3_away_batch227_adapter_1(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c0b5882u: goto P_0c0b5882;
case 0x0c0b5884u: goto P_0c0b5884;
case 0x0c0b5886u: goto P_0c0b5886;
case 0x0c0b5888u: goto P_0c0b5888;
case 0x0c0b588au: goto P_0c0b588a;
case 0x0c0b588cu: goto P_0c0b588c;
case 0x0c0b588eu: goto P_0c0b588e;
case 0x0c0b5890u: goto P_0c0b5890;
case 0x0c0b5892u: goto P_0c0b5892;
case 0x0c0b5894u: goto P_0c0b5894;
case 0x0c0b5896u: goto P_0c0b5896;
case 0x0c0b5898u: goto P_0c0b5898;
case 0x0c0b589au: goto P_0c0b589a;
case 0x0c0b589cu: goto P_0c0b589c;
case 0x0c0b589eu: goto P_0c0b589e;
case 0x0c0b58a0u: goto P_0c0b58a0;
case 0x0c0b58a2u: goto P_0c0b58a2;
case 0x0c0b58a4u: goto P_0c0b58a4;
case 0x0c0b58a6u: goto P_0c0b58a6;
case 0x0c0b58a8u: goto P_0c0b58a8;
case 0x0c0b58aau: goto P_0c0b58aa;
case 0x0c0b58acu: goto P_0c0b58ac;
case 0x0c0b58aeu: goto P_0c0b58ae;
case 0x0c0b58b0u: goto P_0c0b58b0;
case 0x0c0b58b2u: goto P_0c0b58b2;
case 0x0c0b58b4u: goto P_0c0b58b4;
case 0x0c0b58b6u: goto P_0c0b58b6;
case 0x0c0b58b8u: goto P_0c0b58b8;
case 0x0c0b58bau: goto P_0c0b58ba;
case 0x0c0b58bcu: goto P_0c0b58bc;
case 0x0c0b58beu: goto P_0c0b58be;
case 0x0c0b58c0u: goto P_0c0b58c0;
case 0x0c0b58c2u: goto P_0c0b58c2;
case 0x0c0b58c4u: goto P_0c0b58c4;
case 0x0c0b58c6u: goto P_0c0b58c6;
case 0x0c0b58c8u: goto P_0c0b58c8;
case 0x0c0b58cau: goto P_0c0b58ca;
case 0x0c0b58ccu: goto P_0c0b58cc;
case 0x0c0b58ceu: goto P_0c0b58ce;
case 0x0c0b58d0u: goto P_0c0b58d0;
case 0x0c0b58d2u: goto P_0c0b58d2;
case 0x0c0b58d4u: goto P_0c0b58d4;
case 0x0c0b58d6u: goto P_0c0b58d6;
case 0x0c0b58d8u: goto P_0c0b58d8;
case 0x0c0b58dau: goto P_0c0b58da;
case 0x0c0b58dcu: goto P_0c0b58dc;
case 0x0c0b58deu: goto P_0c0b58de;
case 0x0c0b58e0u: goto P_0c0b58e0;
case 0x0c0b58e2u: goto P_0c0b58e2;
case 0x0c0b58e4u: goto P_0c0b58e4;
case 0x0c0b58e6u: goto P_0c0b58e6;
case 0x0c0b58e8u: goto P_0c0b58e8;
case 0x0c0b58eau: goto P_0c0b58ea;
case 0x0c0b58ecu: goto P_0c0b58ec;
case 0x0c0b58eeu: goto P_0c0b58ee;
case 0x0c0b58f0u: goto P_0c0b58f0;
case 0x0c0b58f2u: goto P_0c0b58f2;
case 0x0c0b58f4u: goto P_0c0b58f4;
case 0x0c0b58f6u: goto P_0c0b58f6;
case 0x0c0b58f8u: goto P_0c0b58f8;
case 0x0c0b58fau: goto P_0c0b58fa;
case 0x0c0b58fcu: goto P_0c0b58fc;
case 0x0c0b58feu: goto P_0c0b58fe;
case 0x0c0b5900u: goto P_0c0b5900;
case 0x0c0b5902u: goto P_0c0b5902;
case 0x0c0b5904u: goto P_0c0b5904;
case 0x0c0b5906u: goto P_0c0b5906;
case 0x0c0b5908u: goto P_0c0b5908;
case 0x0c0b590au: goto P_0c0b590a;
case 0x0c0b590cu: goto P_0c0b590c;
case 0x0c0b590eu: goto P_0c0b590e;
case 0x0c0b5910u: goto P_0c0b5910;
case 0x0c0b5912u: goto P_0c0b5912;
case 0x0c0b5914u: goto P_0c0b5914;
case 0x0c0b5916u: goto P_0c0b5916;
case 0x0c0b5918u: goto P_0c0b5918;
case 0x0c0b591au: goto P_0c0b591a;
case 0x0c0b591cu: goto P_0c0b591c;
case 0x0c0b591eu: goto P_0c0b591e;
case 0x0c0b5920u: goto P_0c0b5920;
case 0x0c0b5922u: goto P_0c0b5922;
case 0x0c0b5924u: goto P_0c0b5924;
case 0x0c0b5926u: goto P_0c0b5926;
case 0x0c0b5928u: goto P_0c0b5928;
case 0x0c0b592au: goto P_0c0b592a;
case 0x0c0b592cu: goto P_0c0b592c;
case 0x0c0b592eu: goto P_0c0b592e;
case 0x0c0b5930u: goto P_0c0b5930;
case 0x0c0b5932u: goto P_0c0b5932;
case 0x0c0b5934u: goto P_0c0b5934;
case 0x0c0b5936u: goto P_0c0b5936;
case 0x0c0b5938u: goto P_0c0b5938;
case 0x0c0b593au: goto P_0c0b593a;
case 0x0c0b593cu: goto P_0c0b593c;
case 0x0c0b593eu: goto P_0c0b593e;
case 0x0c0b5940u: goto P_0c0b5940;
case 0x0c0b5942u: goto P_0c0b5942;
case 0x0c0b5944u: goto P_0c0b5944;
case 0x0c0b5946u: goto P_0c0b5946;
case 0x0c0b5948u: goto P_0c0b5948;
case 0x0c0b594au: goto P_0c0b594a;
case 0x0c0b594cu: goto P_0c0b594c;
case 0x0c0b594eu: goto P_0c0b594e;
case 0x0c0b5950u: goto P_0c0b5950;
case 0x0c0b5952u: goto P_0c0b5952;
case 0x0c0b5954u: goto P_0c0b5954;
case 0x0c0b5956u: goto P_0c0b5956;
case 0x0c0b5958u: goto P_0c0b5958;
case 0x0c0b595au: goto P_0c0b595a;
case 0x0c0b595cu: goto P_0c0b595c;
case 0x0c0b595eu: goto P_0c0b595e;
case 0x0c0b5960u: goto P_0c0b5960;
case 0x0c0b5962u: goto P_0c0b5962;
case 0x0c0b5964u: goto P_0c0b5964;
case 0x0c0b5966u: goto P_0c0b5966;
case 0x0c0b5968u: goto P_0c0b5968;
case 0x0c0b596au: goto P_0c0b596a;
case 0x0c0b596cu: goto P_0c0b596c;
case 0x0c0b596eu: goto P_0c0b596e;
case 0x0c0b5970u: goto P_0c0b5970;
case 0x0c0b5972u: goto P_0c0b5972;
case 0x0c0b5974u: goto P_0c0b5974;
case 0x0c0b5976u: goto P_0c0b5976;
case 0x0c0b5978u: goto P_0c0b5978;
case 0x0c0b597au: goto P_0c0b597a;
case 0x0c0b597cu: goto P_0c0b597c;
case 0x0c0b597eu: goto P_0c0b597e;
case 0x0c0b5980u: goto P_0c0b5980;
case 0x0c0b5982u: goto P_0c0b5982;
case 0x0c0b5984u: goto P_0c0b5984;
case 0x0c0b5986u: goto P_0c0b5986;
case 0x0c0b5988u: goto P_0c0b5988;
case 0x0c0b598au: goto P_0c0b598a;
case 0x0c0b598cu: goto P_0c0b598c;
case 0x0c0b598eu: goto P_0c0b598e;
case 0x0c0b5990u: goto P_0c0b5990;
case 0x0c0b5992u: goto P_0c0b5992;
case 0x0c0b5994u: goto P_0c0b5994;
case 0x0c0b5996u: goto P_0c0b5996;
case 0x0c0b5998u: goto P_0c0b5998;
case 0x0c0b599au: goto P_0c0b599a;
case 0x0c0b599cu: goto P_0c0b599c;
case 0x0c0b599eu: goto P_0c0b599e;
case 0x0c0b59a0u: goto P_0c0b59a0;
case 0x0c0b59a2u: goto P_0c0b59a2;
case 0x0c0b59a4u: goto P_0c0b59a4;
case 0x0c0b59a6u: goto P_0c0b59a6;
case 0x0c0b59a8u: goto P_0c0b59a8;
case 0x0c0b59aau: goto P_0c0b59aa;
case 0x0c0b59acu: goto P_0c0b59ac;
case 0x0c0b59aeu: goto P_0c0b59ae;
case 0x0c0b59b0u: goto P_0c0b59b0;
case 0x0c0b59b2u: goto P_0c0b59b2;
case 0x0c0b59b4u: goto P_0c0b59b4;
case 0x0c0b59b6u: goto P_0c0b59b6;
case 0x0c0b59b8u: goto P_0c0b59b8;
case 0x0c0b59bau: goto P_0c0b59ba;
case 0x0c0b59bcu: goto P_0c0b59bc;
case 0x0c0b59beu: goto P_0c0b59be;
case 0x0c0b59c0u: goto P_0c0b59c0;
case 0x0c0b59c2u: goto P_0c0b59c2;
case 0x0c0b59c4u: goto P_0c0b59c4;
case 0x0c0b59c6u: goto P_0c0b59c6;
case 0x0c0b59c8u: goto P_0c0b59c8;
case 0x0c0b59cau: goto P_0c0b59ca;
case 0x0c0b59ccu: goto P_0c0b59cc;
case 0x0c0b59ceu: goto P_0c0b59ce;
case 0x0c0b59d0u: goto P_0c0b59d0;
case 0x0c0b59d2u: goto P_0c0b59d2;
case 0x0c0b59d4u: goto P_0c0b59d4;
case 0x0c0b59d6u: goto P_0c0b59d6;
case 0x0c0b59d8u: goto P_0c0b59d8;
case 0x0c0b59dau: goto P_0c0b59da;
case 0x0c0b59dcu: goto P_0c0b59dc;
case 0x0c0b59deu: goto P_0c0b59de;
case 0x0c0b59e0u: goto P_0c0b59e0;
case 0x0c0b59e2u: goto P_0c0b59e2;
case 0x0c0b59e4u: goto P_0c0b59e4;
case 0x0c0b5a54u: goto P_0c0b5a54;
case 0x0c0b5a56u: goto P_0c0b5a56;
case 0x0c0b5a58u: goto P_0c0b5a58;
case 0x0c0b5a5au: goto P_0c0b5a5a;
case 0x0c0b5a5cu: goto P_0c0b5a5c;
case 0x0c0b5a5eu: goto P_0c0b5a5e;
case 0x0c0b5a60u: goto P_0c0b5a60;
case 0x0c0b5a62u: goto P_0c0b5a62;
case 0x0c0b5a64u: goto P_0c0b5a64;
case 0x0c0b5a66u: goto P_0c0b5a66;
case 0x0c0b5a68u: goto P_0c0b5a68;
case 0x0c0b5a6au: goto P_0c0b5a6a;
case 0x0c0b5a6cu: goto P_0c0b5a6c;
case 0x0c0b5a6eu: goto P_0c0b5a6e;
case 0x0c0b5a70u: goto P_0c0b5a70;
case 0x0c0b5a72u: goto P_0c0b5a72;
case 0x0c0b5a74u: goto P_0c0b5a74;
case 0x0c0b5a76u: goto P_0c0b5a76;
case 0x0c0b5a78u: goto P_0c0b5a78;
case 0x0c0b5a7au: goto P_0c0b5a7a;
case 0x0c0b5a7cu: goto P_0c0b5a7c;
case 0x0c0b5a7eu: goto P_0c0b5a7e;
case 0x0c0b5a80u: goto P_0c0b5a80;
case 0x0c0b5a82u: goto P_0c0b5a82;
case 0x0c0b5a84u: goto P_0c0b5a84;
case 0x0c0b5a86u: goto P_0c0b5a86;
case 0x0c0b5a88u: goto P_0c0b5a88;
case 0x0c0b5a8au: goto P_0c0b5a8a;
case 0x0c0b5a8cu: goto P_0c0b5a8c;
case 0x0c0b5a8eu: goto P_0c0b5a8e;
case 0x0c0b5a90u: goto P_0c0b5a90;
case 0x0c0b5a92u: goto P_0c0b5a92;
case 0x0c0b5a94u: goto P_0c0b5a94;
case 0x0c0b5a96u: goto P_0c0b5a96;
case 0x0c0b5a98u: goto P_0c0b5a98;
case 0x0c0b5a9au: goto P_0c0b5a9a;
case 0x0c0b5a9cu: goto P_0c0b5a9c;
case 0x0c0b5a9eu: goto P_0c0b5a9e;
case 0x0c0b5aa0u: goto P_0c0b5aa0;
case 0x0c0b5aa2u: goto P_0c0b5aa2;
case 0x0c0b5aa4u: goto P_0c0b5aa4;
case 0x0c0b5aa6u: goto P_0c0b5aa6;
case 0x0c0b5aa8u: goto P_0c0b5aa8;
case 0x0c0b5aaau: goto P_0c0b5aaa;
case 0x0c0b5aacu: goto P_0c0b5aac;
case 0x0c0b5aaeu: goto P_0c0b5aae;
case 0x0c0b5ab0u: goto P_0c0b5ab0;
case 0x0c0b5ab2u: goto P_0c0b5ab2;
case 0x0c0b5ab4u: goto P_0c0b5ab4;
case 0x0c0b5ab6u: goto P_0c0b5ab6;
case 0x0c0b5ab8u: goto P_0c0b5ab8;
case 0x0c0b5abau: goto P_0c0b5aba;
case 0x0c0b5abcu: goto P_0c0b5abc;
case 0x0c0b5abeu: goto P_0c0b5abe;
case 0x0c0b5ac0u: goto P_0c0b5ac0;
case 0x0c0b5ac2u: goto P_0c0b5ac2;
case 0x0c0b5ac4u: goto P_0c0b5ac4;
case 0x0c0b5ac6u: goto P_0c0b5ac6;
case 0x0c0b5ac8u: goto P_0c0b5ac8;
case 0x0c0b5acau: goto P_0c0b5aca;
case 0x0c0b5accu: goto P_0c0b5acc;
case 0x0c0b5aceu: goto P_0c0b5ace;
case 0x0c0b5ad0u: goto P_0c0b5ad0;
case 0x0c0b5ad2u: goto P_0c0b5ad2;
case 0x0c0b5ad4u: goto P_0c0b5ad4;
case 0x0c0b5ad6u: goto P_0c0b5ad6;
case 0x0c0b5ad8u: goto P_0c0b5ad8;
case 0x0c0b5adau: goto P_0c0b5ada;
case 0x0c0b5adcu: goto P_0c0b5adc;
case 0x0c0b5adeu: goto P_0c0b5ade;
case 0x0c0b5ae0u: goto P_0c0b5ae0;
case 0x0c0b5ae2u: goto P_0c0b5ae2;
case 0x0c0b5ae4u: goto P_0c0b5ae4;
case 0x0c0b5ae6u: goto P_0c0b5ae6;
case 0x0c0b5ae8u: goto P_0c0b5ae8;
case 0x0c0b5aeau: goto P_0c0b5aea;
case 0x0c0b5aecu: goto P_0c0b5aec;
case 0x0c0b5aeeu: goto P_0c0b5aee;
case 0x0c0b5af0u: goto P_0c0b5af0;
case 0x0c0b5af2u: goto P_0c0b5af2;
case 0x0c0b5af4u: goto P_0c0b5af4;
case 0x0c0b5af6u: goto P_0c0b5af6;
case 0x0c0b5af8u: goto P_0c0b5af8;
case 0x0c0b5afau: goto P_0c0b5afa;
case 0x0c0b5afcu: goto P_0c0b5afc;
case 0x0c0b5afeu: goto P_0c0b5afe;
case 0x0c0b5b00u: goto P_0c0b5b00;
case 0x0c0b5b02u: goto P_0c0b5b02;
case 0x0c0b5b04u: goto P_0c0b5b04;
case 0x0c0b5b06u: goto P_0c0b5b06;
case 0x0c0b5b08u: goto P_0c0b5b08;
case 0x0c0b5b0au: goto P_0c0b5b0a;
case 0x0c0b5b0cu: goto P_0c0b5b0c;
case 0x0c0b5b0eu: goto P_0c0b5b0e;
case 0x0c0b5b10u: goto P_0c0b5b10;
case 0x0c0b5b12u: goto P_0c0b5b12;
case 0x0c0b5b14u: goto P_0c0b5b14;
case 0x0c0b5b16u: goto P_0c0b5b16;
case 0x0c0b5b18u: goto P_0c0b5b18;
case 0x0c0b5b1au: goto P_0c0b5b1a;
case 0x0c0b5b1cu: goto P_0c0b5b1c;
case 0x0c0b5b1eu: goto P_0c0b5b1e;
case 0x0c0b5b20u: goto P_0c0b5b20;
case 0x0c0b5b22u: goto P_0c0b5b22;
case 0x0c0b5b24u: goto P_0c0b5b24;
case 0x0c0b5b26u: goto P_0c0b5b26;
case 0x0c0b5b28u: goto P_0c0b5b28;
case 0x0c0b5b2au: goto P_0c0b5b2a;
case 0x0c0b5b2cu: goto P_0c0b5b2c;
case 0x0c0b5b2eu: goto P_0c0b5b2e;
case 0x0c0b5b30u: goto P_0c0b5b30;
case 0x0c0b5b32u: goto P_0c0b5b32;
case 0x0c0b5b34u: goto P_0c0b5b34;
case 0x0c0b5b36u: goto P_0c0b5b36;
case 0x0c0b5b38u: goto P_0c0b5b38;
case 0x0c0b5b3au: goto P_0c0b5b3a;
case 0x0c0b5b3cu: goto P_0c0b5b3c;
case 0x0c0b5b3eu: goto P_0c0b5b3e;
case 0x0c0b5b40u: goto P_0c0b5b40;
case 0x0c0b5b42u: goto P_0c0b5b42;
case 0x0c0b5b44u: goto P_0c0b5b44;
case 0x0c0b5b46u: goto P_0c0b5b46;
case 0x0c0b5b48u: goto P_0c0b5b48;
case 0x0c0b5b4au: goto P_0c0b5b4a;
case 0x0c0b5b4cu: goto P_0c0b5b4c;
case 0x0c0b5b4eu: goto P_0c0b5b4e;
case 0x0c0b5b50u: goto P_0c0b5b50;
case 0x0c0b5b52u: goto P_0c0b5b52;
case 0x0c0b5b54u: goto P_0c0b5b54;
case 0x0c0b5b56u: goto P_0c0b5b56;
case 0x0c0b5b58u: goto P_0c0b5b58;
case 0x0c0b5b5au: goto P_0c0b5b5a;
case 0x0c0b5b5cu: goto P_0c0b5b5c;
case 0x0c0b5b5eu: goto P_0c0b5b5e;
case 0x0c0b5b60u: goto P_0c0b5b60;
case 0x0c0b5b62u: goto P_0c0b5b62;
case 0x0c0b5b64u: goto P_0c0b5b64;
case 0x0c0b5b66u: goto P_0c0b5b66;
case 0x0c0b5b68u: goto P_0c0b5b68;
case 0x0c0b5b6au: goto P_0c0b5b6a;
case 0x0c0b5b6cu: goto P_0c0b5b6c;
case 0x0c0b5b6eu: goto P_0c0b5b6e;
case 0x0c0b5b70u: goto P_0c0b5b70;
case 0x0c0b5b72u: goto P_0c0b5b72;
case 0x0c0b5b74u: goto P_0c0b5b74;
case 0x0c0b5b76u: goto P_0c0b5b76;
case 0x0c0b5b78u: goto P_0c0b5b78;
case 0x0c0b5b7au: goto P_0c0b5b7a;
case 0x0c0b5b7cu: goto P_0c0b5b7c;
case 0x0c0b5b7eu: goto P_0c0b5b7e;
case 0x0c0b5b80u: goto P_0c0b5b80;
case 0x0c0b5b82u: goto P_0c0b5b82;
case 0x0c0b5b84u: goto P_0c0b5b84;
case 0x0c0b5b86u: goto P_0c0b5b86;
case 0x0c0b5b88u: goto P_0c0b5b88;
case 0x0c0b5b8au: goto P_0c0b5b8a;
case 0x0c0b5b8cu: goto P_0c0b5b8c;
case 0x0c0b5b8eu: goto P_0c0b5b8e;
case 0x0c0b5b90u: goto P_0c0b5b90;
case 0x0c0b5b92u: goto P_0c0b5b92;
case 0x0c0b5b94u: goto P_0c0b5b94;
case 0x0c0b5b96u: goto P_0c0b5b96;
case 0x0c0b5b98u: goto P_0c0b5b98;
case 0x0c0b5b9au: goto P_0c0b5b9a;
case 0x0c0b5b9cu: goto P_0c0b5b9c;
case 0x0c0b5b9eu: goto P_0c0b5b9e;
case 0x0c0b5ba0u: goto P_0c0b5ba0;
case 0x0c0b5ba2u: goto P_0c0b5ba2;
case 0x0c0b5ba4u: goto P_0c0b5ba4;
case 0x0c0b5ba6u: goto P_0c0b5ba6;
case 0x0c0b5ba8u: goto P_0c0b5ba8;
case 0x0c0b5baau: goto P_0c0b5baa;
case 0x0c0b5bacu: goto P_0c0b5bac;
case 0x0c0b5c26u: goto P_0c0b5c26;
case 0x0c0b5c28u: goto P_0c0b5c28;
case 0x0c0b5c2au: goto P_0c0b5c2a;
case 0x0c0b5c2cu: goto P_0c0b5c2c;
case 0x0c0b5c2eu: goto P_0c0b5c2e;
case 0x0c0b5c30u: goto P_0c0b5c30;
case 0x0c0b5c32u: goto P_0c0b5c32;
case 0x0c0b5c34u: goto P_0c0b5c34;
case 0x0c0b5c36u: goto P_0c0b5c36;
case 0x0c0b5c38u: goto P_0c0b5c38;
case 0x0c0b5c3au: goto P_0c0b5c3a;
case 0x0c0b5c3cu: goto P_0c0b5c3c;
case 0x0c0b5c3eu: goto P_0c0b5c3e;
case 0x0c0b5c40u: goto P_0c0b5c40;
case 0x0c0b5c42u: goto P_0c0b5c42;
case 0x0c0b5c44u: goto P_0c0b5c44;
case 0x0c0b5c46u: goto P_0c0b5c46;
case 0x0c0b5c48u: goto P_0c0b5c48;
case 0x0c0b5c4au: goto P_0c0b5c4a;
case 0x0c0b5c4cu: goto P_0c0b5c4c;
case 0x0c0b5c4eu: goto P_0c0b5c4e;
case 0x0c0b5c50u: goto P_0c0b5c50;
case 0x0c0b5c52u: goto P_0c0b5c52;
case 0x0c0b5c54u: goto P_0c0b5c54;
case 0x0c0b5c56u: goto P_0c0b5c56;
case 0x0c0b5c58u: goto P_0c0b5c58;
case 0x0c0b5c5au: goto P_0c0b5c5a;
case 0x0c0b5c5cu: goto P_0c0b5c5c;
case 0x0c0b5c5eu: goto P_0c0b5c5e;
case 0x0c0b5c60u: goto P_0c0b5c60;
case 0x0c0b5c62u: goto P_0c0b5c62;
case 0x0c0b5c64u: goto P_0c0b5c64;
case 0x0c0b5c66u: goto P_0c0b5c66;
case 0x0c0b5c68u: goto P_0c0b5c68;
case 0x0c0b5c6au: goto P_0c0b5c6a;
case 0x0c0b5c6cu: goto P_0c0b5c6c;
case 0x0c0b5c6eu: goto P_0c0b5c6e;
case 0x0c0b5c70u: goto P_0c0b5c70;
case 0x0c0b5c72u: goto P_0c0b5c72;
case 0x0c0b5c74u: goto P_0c0b5c74;
case 0x0c0b5c76u: goto P_0c0b5c76;
case 0x0c0b5c78u: goto P_0c0b5c78;
case 0x0c0b5c7au: goto P_0c0b5c7a;
case 0x0c0b5c7cu: goto P_0c0b5c7c;
case 0x0c0b5c7eu: goto P_0c0b5c7e;
case 0x0c0b5c80u: goto P_0c0b5c80;
case 0x0c0b5c82u: goto P_0c0b5c82;
case 0x0c0b5c84u: goto P_0c0b5c84;
case 0x0c0b5c86u: goto P_0c0b5c86;
case 0x0c0b5c88u: goto P_0c0b5c88;
case 0x0c0b5c8au: goto P_0c0b5c8a;
case 0x0c0b5c8cu: goto P_0c0b5c8c;
default: return vf3_matrix_family(target,s,ram);
}
P_0c0b5882: /* original 2fe6, guest PC 0x0c0b5882 */
if(!s->budget--) { s->failed_pc=0x0c0b5882u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0b5884;
P_0c0b5884: /* original 2fd6, guest PC 0x0c0b5884 */
if(!s->budget--) { s->failed_pc=0x0c0b5884u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0b5886;
P_0c0b5886: /* original 2fc6, guest PC 0x0c0b5886 */
if(!s->budget--) { s->failed_pc=0x0c0b5886u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0b5888;
P_0c0b5888: /* original 2fb6, guest PC 0x0c0b5888 */
if(!s->budget--) { s->failed_pc=0x0c0b5888u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0b588a;
P_0c0b588a: /* original 2fa6, guest PC 0x0c0b588a */
if(!s->budget--) { s->failed_pc=0x0c0b588au; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0b588c;
P_0c0b588c: /* original 2f96, guest PC 0x0c0b588c */
if(!s->budget--) { s->failed_pc=0x0c0b588cu; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0b588e;
P_0c0b588e: /* original 4f22, guest PC 0x0c0b588e */
if(!s->budget--) { s->failed_pc=0x0c0b588eu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0b5890;
P_0c0b5890: /* original 5d44, guest PC 0x0c0b5890 */
if(!s->budget--) { s->failed_pc=0x0c0b5890u; return 0; }
r[13]=read(ram,r[4]+16,4);
goto P_0c0b5892;
P_0c0b5892: /* original 94a8, guest PC 0x0c0b5892 */
if(!s->budget--) { s->failed_pc=0x0c0b5892u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b59e6u,2);
goto P_0c0b5894;
P_0c0b5894: /* original de6e, guest PC 0x0c0b5894 */
if(!s->budget--) { s->failed_pc=0x0c0b5894u; return 0; }
r[14]=read(ram,0x0c0b5a50u,4);
goto P_0c0b5896;
P_0c0b5896: /* original 7ff8, guest PC 0x0c0b5896 */
if(!s->budget--) { s->failed_pc=0x0c0b5896u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c0b5898;
P_0c0b5898: /* original 4e0b, guest PC 0x0c0b5898 */
if(!s->budget--) { s->failed_pc=0x0c0b5898u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b589cu;
tmp=read(ram,r[13],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b589cu) { target=s->pc; goto dispatch; }
goto P_0c0b589c;
P_0c0b589a: /* original 65d2, guest PC 0x0c0b589a */
if(!s->budget--) { s->failed_pc=0x0c0b589au; return 0; }
tmp=read(ram,r[13],4);
r[5]=tmp;
goto P_0c0b589c;
P_0c0b589c: /* original 94a4, guest PC 0x0c0b589c */
if(!s->budget--) { s->failed_pc=0x0c0b589cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b59e8u,2);
goto P_0c0b589e;
P_0c0b589e: /* original 4e0b, guest PC 0x0c0b589e */
if(!s->budget--) { s->failed_pc=0x0c0b589eu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b58a2u;
r[5]=read(ram,r[13]+4,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b58a2u) { target=s->pc; goto dispatch; }
goto P_0c0b58a2;
P_0c0b58a0: /* original 55d1, guest PC 0x0c0b58a0 */
if(!s->budget--) { s->failed_pc=0x0c0b58a0u; return 0; }
r[5]=read(ram,r[13]+4,4);
goto P_0c0b58a2;
P_0c0b58a2: /* original 94a2, guest PC 0x0c0b58a2 */
if(!s->budget--) { s->failed_pc=0x0c0b58a2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b59eau,2);
goto P_0c0b58a4;
P_0c0b58a4: /* original 4e0b, guest PC 0x0c0b58a4 */
if(!s->budget--) { s->failed_pc=0x0c0b58a4u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b58a8u;
r[5]=read(ram,r[13]+8,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b58a8u) { target=s->pc; goto dispatch; }
goto P_0c0b58a8;
P_0c0b58a6: /* original 55d2, guest PC 0x0c0b58a6 */
if(!s->budget--) { s->failed_pc=0x0c0b58a6u; return 0; }
r[5]=read(ram,r[13]+8,4);
goto P_0c0b58a8;
P_0c0b58a8: /* original 94a0, guest PC 0x0c0b58a8 */
if(!s->budget--) { s->failed_pc=0x0c0b58a8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b59ecu,2);
goto P_0c0b58aa;
P_0c0b58aa: /* original 4e0b, guest PC 0x0c0b58aa */
if(!s->budget--) { s->failed_pc=0x0c0b58aau; return 0; }
target=r[14];
r[16]=code_base|0x0c0b58aeu;
r[5]=read(ram,r[13]+12,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b58aeu) { target=s->pc; goto dispatch; }
goto P_0c0b58ae;
P_0c0b58ac: /* original 55d3, guest PC 0x0c0b58ac */
if(!s->budget--) { s->failed_pc=0x0c0b58acu; return 0; }
r[5]=read(ram,r[13]+12,4);
goto P_0c0b58ae;
P_0c0b58ae: /* original 949e, guest PC 0x0c0b58ae */
if(!s->budget--) { s->failed_pc=0x0c0b58aeu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b59eeu,2);
goto P_0c0b58b0;
P_0c0b58b0: /* original 4e0b, guest PC 0x0c0b58b0 */
if(!s->budget--) { s->failed_pc=0x0c0b58b0u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b58b4u;
r[5]=read(ram,r[13]+16,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b58b4u) { target=s->pc; goto dispatch; }
goto P_0c0b58b4;
P_0c0b58b2: /* original 55d4, guest PC 0x0c0b58b2 */
if(!s->budget--) { s->failed_pc=0x0c0b58b2u; return 0; }
r[5]=read(ram,r[13]+16,4);
goto P_0c0b58b4;
P_0c0b58b4: /* original 949c, guest PC 0x0c0b58b4 */
if(!s->budget--) { s->failed_pc=0x0c0b58b4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b59f0u,2);
goto P_0c0b58b6;
P_0c0b58b6: /* original 4e0b, guest PC 0x0c0b58b6 */
if(!s->budget--) { s->failed_pc=0x0c0b58b6u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b58bau;
r[5]=read(ram,r[13]+20,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b58bau) { target=s->pc; goto dispatch; }
goto P_0c0b58ba;
P_0c0b58b8: /* original 55d5, guest PC 0x0c0b58b8 */
if(!s->budget--) { s->failed_pc=0x0c0b58b8u; return 0; }
r[5]=read(ram,r[13]+20,4);
goto P_0c0b58ba;
P_0c0b58ba: /* original 949a, guest PC 0x0c0b58ba */
if(!s->budget--) { s->failed_pc=0x0c0b58bau; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b59f2u,2);
goto P_0c0b58bc;
P_0c0b58bc: /* original 4e0b, guest PC 0x0c0b58bc */
if(!s->budget--) { s->failed_pc=0x0c0b58bcu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b58c0u;
r[5]=read(ram,r[13]+24,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b58c0u) { target=s->pc; goto dispatch; }
goto P_0c0b58c0;
P_0c0b58be: /* original 55d6, guest PC 0x0c0b58be */
if(!s->budget--) { s->failed_pc=0x0c0b58beu; return 0; }
r[5]=read(ram,r[13]+24,4);
goto P_0c0b58c0;
P_0c0b58c0: /* original 9498, guest PC 0x0c0b58c0 */
if(!s->budget--) { s->failed_pc=0x0c0b58c0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b59f4u,2);
goto P_0c0b58c2;
P_0c0b58c2: /* original 4e0b, guest PC 0x0c0b58c2 */
if(!s->budget--) { s->failed_pc=0x0c0b58c2u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b58c6u;
r[5]=read(ram,r[13]+28,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b58c6u) { target=s->pc; goto dispatch; }
goto P_0c0b58c6;
P_0c0b58c4: /* original 55d7, guest PC 0x0c0b58c4 */
if(!s->budget--) { s->failed_pc=0x0c0b58c4u; return 0; }
r[5]=read(ram,r[13]+28,4);
goto P_0c0b58c6;
P_0c0b58c6: /* original 9496, guest PC 0x0c0b58c6 */
if(!s->budget--) { s->failed_pc=0x0c0b58c6u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b59f6u,2);
goto P_0c0b58c8;
P_0c0b58c8: /* original 4e0b, guest PC 0x0c0b58c8 */
if(!s->budget--) { s->failed_pc=0x0c0b58c8u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b58ccu;
r[5]=read(ram,r[13]+32,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b58ccu) { target=s->pc; goto dispatch; }
goto P_0c0b58cc;
P_0c0b58ca: /* original 55d8, guest PC 0x0c0b58ca */
if(!s->budget--) { s->failed_pc=0x0c0b58cau; return 0; }
r[5]=read(ram,r[13]+32,4);
goto P_0c0b58cc;
P_0c0b58cc: /* original 9494, guest PC 0x0c0b58cc */
if(!s->budget--) { s->failed_pc=0x0c0b58ccu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b59f8u,2);
goto P_0c0b58ce;
P_0c0b58ce: /* original 4e0b, guest PC 0x0c0b58ce */
if(!s->budget--) { s->failed_pc=0x0c0b58ceu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b58d2u;
r[5]=read(ram,r[13]+36,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b58d2u) { target=s->pc; goto dispatch; }
goto P_0c0b58d2;
P_0c0b58d0: /* original 55d9, guest PC 0x0c0b58d0 */
if(!s->budget--) { s->failed_pc=0x0c0b58d0u; return 0; }
r[5]=read(ram,r[13]+36,4);
goto P_0c0b58d2;
P_0c0b58d2: /* original 9492, guest PC 0x0c0b58d2 */
if(!s->budget--) { s->failed_pc=0x0c0b58d2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b59fau,2);
goto P_0c0b58d4;
P_0c0b58d4: /* original 4e0b, guest PC 0x0c0b58d4 */
if(!s->budget--) { s->failed_pc=0x0c0b58d4u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b58d8u;
r[5]=read(ram,r[13]+40,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b58d8u) { target=s->pc; goto dispatch; }
goto P_0c0b58d8;
P_0c0b58d6: /* original 55da, guest PC 0x0c0b58d6 */
if(!s->budget--) { s->failed_pc=0x0c0b58d6u; return 0; }
r[5]=read(ram,r[13]+40,4);
goto P_0c0b58d8;
P_0c0b58d8: /* original 9490, guest PC 0x0c0b58d8 */
if(!s->budget--) { s->failed_pc=0x0c0b58d8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b59fcu,2);
goto P_0c0b58da;
P_0c0b58da: /* original 4e0b, guest PC 0x0c0b58da */
if(!s->budget--) { s->failed_pc=0x0c0b58dau; return 0; }
target=r[14];
r[16]=code_base|0x0c0b58deu;
r[5]=read(ram,r[13]+44,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b58deu) { target=s->pc; goto dispatch; }
goto P_0c0b58de;
P_0c0b58dc: /* original 55db, guest PC 0x0c0b58dc */
if(!s->budget--) { s->failed_pc=0x0c0b58dcu; return 0; }
r[5]=read(ram,r[13]+44,4);
goto P_0c0b58de;
P_0c0b58de: /* original 948e, guest PC 0x0c0b58de */
if(!s->budget--) { s->failed_pc=0x0c0b58deu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b59feu,2);
goto P_0c0b58e0;
P_0c0b58e0: /* original 4e0b, guest PC 0x0c0b58e0 */
if(!s->budget--) { s->failed_pc=0x0c0b58e0u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b58e4u;
r[5]=read(ram,r[13]+48,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b58e4u) { target=s->pc; goto dispatch; }
goto P_0c0b58e4;
P_0c0b58e2: /* original 55dc, guest PC 0x0c0b58e2 */
if(!s->budget--) { s->failed_pc=0x0c0b58e2u; return 0; }
r[5]=read(ram,r[13]+48,4);
goto P_0c0b58e4;
P_0c0b58e4: /* original 948c, guest PC 0x0c0b58e4 */
if(!s->budget--) { s->failed_pc=0x0c0b58e4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5a00u,2);
goto P_0c0b58e6;
P_0c0b58e6: /* original 4e0b, guest PC 0x0c0b58e6 */
if(!s->budget--) { s->failed_pc=0x0c0b58e6u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b58eau;
r[5]=read(ram,r[13]+52,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b58eau) { target=s->pc; goto dispatch; }
goto P_0c0b58ea;
P_0c0b58e8: /* original 55dd, guest PC 0x0c0b58e8 */
if(!s->budget--) { s->failed_pc=0x0c0b58e8u; return 0; }
r[5]=read(ram,r[13]+52,4);
goto P_0c0b58ea;
P_0c0b58ea: /* original 948a, guest PC 0x0c0b58ea */
if(!s->budget--) { s->failed_pc=0x0c0b58eau; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5a02u,2);
goto P_0c0b58ec;
P_0c0b58ec: /* original 4e0b, guest PC 0x0c0b58ec */
if(!s->budget--) { s->failed_pc=0x0c0b58ecu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b58f0u;
r[5]=read(ram,r[13]+56,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b58f0u) { target=s->pc; goto dispatch; }
goto P_0c0b58f0;
P_0c0b58ee: /* original 55de, guest PC 0x0c0b58ee */
if(!s->budget--) { s->failed_pc=0x0c0b58eeu; return 0; }
r[5]=read(ram,r[13]+56,4);
goto P_0c0b58f0;
P_0c0b58f0: /* original 9488, guest PC 0x0c0b58f0 */
if(!s->budget--) { s->failed_pc=0x0c0b58f0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5a04u,2);
goto P_0c0b58f2;
P_0c0b58f2: /* original 4e0b, guest PC 0x0c0b58f2 */
if(!s->budget--) { s->failed_pc=0x0c0b58f2u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b58f6u;
r[5]=read(ram,r[13]+60,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b58f6u) { target=s->pc; goto dispatch; }
goto P_0c0b58f6;
P_0c0b58f4: /* original 55df, guest PC 0x0c0b58f4 */
if(!s->budget--) { s->failed_pc=0x0c0b58f4u; return 0; }
r[5]=read(ram,r[13]+60,4);
goto P_0c0b58f6;
P_0c0b58f6: /* original 9486, guest PC 0x0c0b58f6 */
if(!s->budget--) { s->failed_pc=0x0c0b58f6u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5a06u,2);
goto P_0c0b58f8;
P_0c0b58f8: /* original e040, guest PC 0x0c0b58f8 */
if(!s->budget--) { s->failed_pc=0x0c0b58f8u; return 0; }
r[0]=0x00000040u;
goto P_0c0b58fa;
P_0c0b58fa: /* original 4e0b, guest PC 0x0c0b58fa */
if(!s->budget--) { s->failed_pc=0x0c0b58fau; return 0; }
target=r[14];
r[16]=code_base|0x0c0b58feu;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b58feu) { target=s->pc; goto dispatch; }
goto P_0c0b58fe;
P_0c0b58fc: /* original 05de, guest PC 0x0c0b58fc */
if(!s->budget--) { s->failed_pc=0x0c0b58fcu; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b58fe;
P_0c0b58fe: /* original 9483, guest PC 0x0c0b58fe */
if(!s->budget--) { s->failed_pc=0x0c0b58feu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5a08u,2);
goto P_0c0b5900;
P_0c0b5900: /* original e044, guest PC 0x0c0b5900 */
if(!s->budget--) { s->failed_pc=0x0c0b5900u; return 0; }
r[0]=0x00000044u;
goto P_0c0b5902;
P_0c0b5902: /* original 4e0b, guest PC 0x0c0b5902 */
if(!s->budget--) { s->failed_pc=0x0c0b5902u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b5906u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b5906u) { target=s->pc; goto dispatch; }
goto P_0c0b5906;
P_0c0b5904: /* original 05de, guest PC 0x0c0b5904 */
if(!s->budget--) { s->failed_pc=0x0c0b5904u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b5906;
P_0c0b5906: /* original 9480, guest PC 0x0c0b5906 */
if(!s->budget--) { s->failed_pc=0x0c0b5906u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5a0au,2);
goto P_0c0b5908;
P_0c0b5908: /* original e048, guest PC 0x0c0b5908 */
if(!s->budget--) { s->failed_pc=0x0c0b5908u; return 0; }
r[0]=0x00000048u;
goto P_0c0b590a;
P_0c0b590a: /* original 4e0b, guest PC 0x0c0b590a */
if(!s->budget--) { s->failed_pc=0x0c0b590au; return 0; }
target=r[14];
r[16]=code_base|0x0c0b590eu;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b590eu) { target=s->pc; goto dispatch; }
goto P_0c0b590e;
P_0c0b590c: /* original 05de, guest PC 0x0c0b590c */
if(!s->budget--) { s->failed_pc=0x0c0b590cu; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b590e;
P_0c0b590e: /* original 947d, guest PC 0x0c0b590e */
if(!s->budget--) { s->failed_pc=0x0c0b590eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5a0cu,2);
goto P_0c0b5910;
P_0c0b5910: /* original e04c, guest PC 0x0c0b5910 */
if(!s->budget--) { s->failed_pc=0x0c0b5910u; return 0; }
r[0]=0x0000004cu;
goto P_0c0b5912;
P_0c0b5912: /* original 4e0b, guest PC 0x0c0b5912 */
if(!s->budget--) { s->failed_pc=0x0c0b5912u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b5916u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b5916u) { target=s->pc; goto dispatch; }
goto P_0c0b5916;
P_0c0b5914: /* original 05de, guest PC 0x0c0b5914 */
if(!s->budget--) { s->failed_pc=0x0c0b5914u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b5916;
P_0c0b5916: /* original 947a, guest PC 0x0c0b5916 */
if(!s->budget--) { s->failed_pc=0x0c0b5916u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5a0eu,2);
goto P_0c0b5918;
P_0c0b5918: /* original e050, guest PC 0x0c0b5918 */
if(!s->budget--) { s->failed_pc=0x0c0b5918u; return 0; }
r[0]=0x00000050u;
goto P_0c0b591a;
P_0c0b591a: /* original 4e0b, guest PC 0x0c0b591a */
if(!s->budget--) { s->failed_pc=0x0c0b591au; return 0; }
target=r[14];
r[16]=code_base|0x0c0b591eu;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b591eu) { target=s->pc; goto dispatch; }
goto P_0c0b591e;
P_0c0b591c: /* original 05de, guest PC 0x0c0b591c */
if(!s->budget--) { s->failed_pc=0x0c0b591cu; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b591e;
P_0c0b591e: /* original 9477, guest PC 0x0c0b591e */
if(!s->budget--) { s->failed_pc=0x0c0b591eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5a10u,2);
goto P_0c0b5920;
P_0c0b5920: /* original e054, guest PC 0x0c0b5920 */
if(!s->budget--) { s->failed_pc=0x0c0b5920u; return 0; }
r[0]=0x00000054u;
goto P_0c0b5922;
P_0c0b5922: /* original 4e0b, guest PC 0x0c0b5922 */
if(!s->budget--) { s->failed_pc=0x0c0b5922u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b5926u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b5926u) { target=s->pc; goto dispatch; }
goto P_0c0b5926;
P_0c0b5924: /* original 05de, guest PC 0x0c0b5924 */
if(!s->budget--) { s->failed_pc=0x0c0b5924u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b5926;
P_0c0b5926: /* original 9474, guest PC 0x0c0b5926 */
if(!s->budget--) { s->failed_pc=0x0c0b5926u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5a12u,2);
goto P_0c0b5928;
P_0c0b5928: /* original e058, guest PC 0x0c0b5928 */
if(!s->budget--) { s->failed_pc=0x0c0b5928u; return 0; }
r[0]=0x00000058u;
goto P_0c0b592a;
P_0c0b592a: /* original 4e0b, guest PC 0x0c0b592a */
if(!s->budget--) { s->failed_pc=0x0c0b592au; return 0; }
target=r[14];
r[16]=code_base|0x0c0b592eu;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b592eu) { target=s->pc; goto dispatch; }
goto P_0c0b592e;
P_0c0b592c: /* original 05de, guest PC 0x0c0b592c */
if(!s->budget--) { s->failed_pc=0x0c0b592cu; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b592e;
P_0c0b592e: /* original 9471, guest PC 0x0c0b592e */
if(!s->budget--) { s->failed_pc=0x0c0b592eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5a14u,2);
goto P_0c0b5930;
P_0c0b5930: /* original e05c, guest PC 0x0c0b5930 */
if(!s->budget--) { s->failed_pc=0x0c0b5930u; return 0; }
r[0]=0x0000005cu;
goto P_0c0b5932;
P_0c0b5932: /* original 4e0b, guest PC 0x0c0b5932 */
if(!s->budget--) { s->failed_pc=0x0c0b5932u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b5936u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b5936u) { target=s->pc; goto dispatch; }
goto P_0c0b5936;
P_0c0b5934: /* original 05de, guest PC 0x0c0b5934 */
if(!s->budget--) { s->failed_pc=0x0c0b5934u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b5936;
P_0c0b5936: /* original 946e, guest PC 0x0c0b5936 */
if(!s->budget--) { s->failed_pc=0x0c0b5936u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5a16u,2);
goto P_0c0b5938;
P_0c0b5938: /* original e060, guest PC 0x0c0b5938 */
if(!s->budget--) { s->failed_pc=0x0c0b5938u; return 0; }
r[0]=0x00000060u;
goto P_0c0b593a;
P_0c0b593a: /* original 4e0b, guest PC 0x0c0b593a */
if(!s->budget--) { s->failed_pc=0x0c0b593au; return 0; }
target=r[14];
r[16]=code_base|0x0c0b593eu;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b593eu) { target=s->pc; goto dispatch; }
goto P_0c0b593e;
P_0c0b593c: /* original 05de, guest PC 0x0c0b593c */
if(!s->budget--) { s->failed_pc=0x0c0b593cu; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b593e;
P_0c0b593e: /* original 946b, guest PC 0x0c0b593e */
if(!s->budget--) { s->failed_pc=0x0c0b593eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5a18u,2);
goto P_0c0b5940;
P_0c0b5940: /* original e064, guest PC 0x0c0b5940 */
if(!s->budget--) { s->failed_pc=0x0c0b5940u; return 0; }
r[0]=0x00000064u;
goto P_0c0b5942;
P_0c0b5942: /* original 4e0b, guest PC 0x0c0b5942 */
if(!s->budget--) { s->failed_pc=0x0c0b5942u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b5946u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b5946u) { target=s->pc; goto dispatch; }
goto P_0c0b5946;
P_0c0b5944: /* original 05de, guest PC 0x0c0b5944 */
if(!s->budget--) { s->failed_pc=0x0c0b5944u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b5946;
P_0c0b5946: /* original 9468, guest PC 0x0c0b5946 */
if(!s->budget--) { s->failed_pc=0x0c0b5946u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5a1au,2);
goto P_0c0b5948;
P_0c0b5948: /* original e068, guest PC 0x0c0b5948 */
if(!s->budget--) { s->failed_pc=0x0c0b5948u; return 0; }
r[0]=0x00000068u;
goto P_0c0b594a;
P_0c0b594a: /* original 4e0b, guest PC 0x0c0b594a */
if(!s->budget--) { s->failed_pc=0x0c0b594au; return 0; }
target=r[14];
r[16]=code_base|0x0c0b594eu;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b594eu) { target=s->pc; goto dispatch; }
goto P_0c0b594e;
P_0c0b594c: /* original 05de, guest PC 0x0c0b594c */
if(!s->budget--) { s->failed_pc=0x0c0b594cu; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b594e;
P_0c0b594e: /* original 9465, guest PC 0x0c0b594e */
if(!s->budget--) { s->failed_pc=0x0c0b594eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5a1cu,2);
goto P_0c0b5950;
P_0c0b5950: /* original e06c, guest PC 0x0c0b5950 */
if(!s->budget--) { s->failed_pc=0x0c0b5950u; return 0; }
r[0]=0x0000006cu;
goto P_0c0b5952;
P_0c0b5952: /* original 4e0b, guest PC 0x0c0b5952 */
if(!s->budget--) { s->failed_pc=0x0c0b5952u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b5956u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b5956u) { target=s->pc; goto dispatch; }
goto P_0c0b5956;
P_0c0b5954: /* original 05de, guest PC 0x0c0b5954 */
if(!s->budget--) { s->failed_pc=0x0c0b5954u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b5956;
P_0c0b5956: /* original 9462, guest PC 0x0c0b5956 */
if(!s->budget--) { s->failed_pc=0x0c0b5956u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5a1eu,2);
goto P_0c0b5958;
P_0c0b5958: /* original e070, guest PC 0x0c0b5958 */
if(!s->budget--) { s->failed_pc=0x0c0b5958u; return 0; }
r[0]=0x00000070u;
goto P_0c0b595a;
P_0c0b595a: /* original 4e0b, guest PC 0x0c0b595a */
if(!s->budget--) { s->failed_pc=0x0c0b595au; return 0; }
target=r[14];
r[16]=code_base|0x0c0b595eu;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b595eu) { target=s->pc; goto dispatch; }
goto P_0c0b595e;
P_0c0b595c: /* original 05de, guest PC 0x0c0b595c */
if(!s->budget--) { s->failed_pc=0x0c0b595cu; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b595e;
P_0c0b595e: /* original 945f, guest PC 0x0c0b595e */
if(!s->budget--) { s->failed_pc=0x0c0b595eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5a20u,2);
goto P_0c0b5960;
P_0c0b5960: /* original e074, guest PC 0x0c0b5960 */
if(!s->budget--) { s->failed_pc=0x0c0b5960u; return 0; }
r[0]=0x00000074u;
goto P_0c0b5962;
P_0c0b5962: /* original 4e0b, guest PC 0x0c0b5962 */
if(!s->budget--) { s->failed_pc=0x0c0b5962u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b5966u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b5966u) { target=s->pc; goto dispatch; }
goto P_0c0b5966;
P_0c0b5964: /* original 05de, guest PC 0x0c0b5964 */
if(!s->budget--) { s->failed_pc=0x0c0b5964u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b5966;
P_0c0b5966: /* original 945c, guest PC 0x0c0b5966 */
if(!s->budget--) { s->failed_pc=0x0c0b5966u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5a22u,2);
goto P_0c0b5968;
P_0c0b5968: /* original e078, guest PC 0x0c0b5968 */
if(!s->budget--) { s->failed_pc=0x0c0b5968u; return 0; }
r[0]=0x00000078u;
goto P_0c0b596a;
P_0c0b596a: /* original 4e0b, guest PC 0x0c0b596a */
if(!s->budget--) { s->failed_pc=0x0c0b596au; return 0; }
target=r[14];
r[16]=code_base|0x0c0b596eu;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b596eu) { target=s->pc; goto dispatch; }
goto P_0c0b596e;
P_0c0b596c: /* original 05de, guest PC 0x0c0b596c */
if(!s->budget--) { s->failed_pc=0x0c0b596cu; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b596e;
P_0c0b596e: /* original 9459, guest PC 0x0c0b596e */
if(!s->budget--) { s->failed_pc=0x0c0b596eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5a24u,2);
goto P_0c0b5970;
P_0c0b5970: /* original e07c, guest PC 0x0c0b5970 */
if(!s->budget--) { s->failed_pc=0x0c0b5970u; return 0; }
r[0]=0x0000007cu;
goto P_0c0b5972;
P_0c0b5972: /* original 4e0b, guest PC 0x0c0b5972 */
if(!s->budget--) { s->failed_pc=0x0c0b5972u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b5976u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b5976u) { target=s->pc; goto dispatch; }
goto P_0c0b5976;
P_0c0b5974: /* original 05de, guest PC 0x0c0b5974 */
if(!s->budget--) { s->failed_pc=0x0c0b5974u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b5976;
P_0c0b5976: /* original 9457, guest PC 0x0c0b5976 */
if(!s->budget--) { s->failed_pc=0x0c0b5976u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5a28u,2);
goto P_0c0b5978;
P_0c0b5978: /* original 9055, guest PC 0x0c0b5978 */
if(!s->budget--) { s->failed_pc=0x0c0b5978u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5a26u,2);
goto P_0c0b597a;
P_0c0b597a: /* original 4e0b, guest PC 0x0c0b597a */
if(!s->budget--) { s->failed_pc=0x0c0b597au; return 0; }
target=r[14];
r[16]=code_base|0x0c0b597eu;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b597eu) { target=s->pc; goto dispatch; }
goto P_0c0b597e;
P_0c0b597c: /* original 05de, guest PC 0x0c0b597c */
if(!s->budget--) { s->failed_pc=0x0c0b597cu; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b597e;
P_0c0b597e: /* original 9554, guest PC 0x0c0b597e */
if(!s->budget--) { s->failed_pc=0x0c0b597eu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5a2au,2);
goto P_0c0b5980;
P_0c0b5980: /* original 35dc, guest PC 0x0c0b5980 */
if(!s->budget--) { s->failed_pc=0x0c0b5980u; return 0; }
r[5]+=r[13];
goto P_0c0b5982;
P_0c0b5982: /* original 2f52, guest PC 0x0c0b5982 */
if(!s->budget--) { s->failed_pc=0x0c0b5982u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0b5984;
P_0c0b5984: /* original 9452, guest PC 0x0c0b5984 */
if(!s->budget--) { s->failed_pc=0x0c0b5984u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5a2cu,2);
goto P_0c0b5986;
P_0c0b5986: /* original 4e0b, guest PC 0x0c0b5986 */
if(!s->budget--) { s->failed_pc=0x0c0b5986u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b598au;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b598au) { target=s->pc; goto dispatch; }
goto P_0c0b598a;
P_0c0b5988: /* original 6552, guest PC 0x0c0b5988 */
if(!s->budget--) { s->failed_pc=0x0c0b5988u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b598a;
P_0c0b598a: /* original 9550, guest PC 0x0c0b598a */
if(!s->budget--) { s->failed_pc=0x0c0b598au; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5a2eu,2);
goto P_0c0b598c;
P_0c0b598c: /* original 35dc, guest PC 0x0c0b598c */
if(!s->budget--) { s->failed_pc=0x0c0b598cu; return 0; }
r[5]+=r[13];
goto P_0c0b598e;
P_0c0b598e: /* original 1f51, guest PC 0x0c0b598e */
if(!s->budget--) { s->failed_pc=0x0c0b598eu; return 0; }
write(ram,r[15]+4,r[5],4);
goto P_0c0b5990;
P_0c0b5990: /* original 944e, guest PC 0x0c0b5990 */
if(!s->budget--) { s->failed_pc=0x0c0b5990u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5a30u,2);
goto P_0c0b5992;
P_0c0b5992: /* original 4e0b, guest PC 0x0c0b5992 */
if(!s->budget--) { s->failed_pc=0x0c0b5992u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b5996u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b5996u) { target=s->pc; goto dispatch; }
goto P_0c0b5996;
P_0c0b5994: /* original 6552, guest PC 0x0c0b5994 */
if(!s->budget--) { s->failed_pc=0x0c0b5994u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b5996;
P_0c0b5996: /* original 944d, guest PC 0x0c0b5996 */
if(!s->budget--) { s->failed_pc=0x0c0b5996u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5a34u,2);
goto P_0c0b5998;
P_0c0b5998: /* original 904b, guest PC 0x0c0b5998 */
if(!s->budget--) { s->failed_pc=0x0c0b5998u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5a32u,2);
goto P_0c0b599a;
P_0c0b599a: /* original 4e0b, guest PC 0x0c0b599a */
if(!s->budget--) { s->failed_pc=0x0c0b599au; return 0; }
target=r[14];
r[16]=code_base|0x0c0b599eu;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b599eu) { target=s->pc; goto dispatch; }
goto P_0c0b599e;
P_0c0b599c: /* original 05de, guest PC 0x0c0b599c */
if(!s->budget--) { s->failed_pc=0x0c0b599cu; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b599e;
P_0c0b599e: /* original 944b, guest PC 0x0c0b599e */
if(!s->budget--) { s->failed_pc=0x0c0b599eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5a38u,2);
goto P_0c0b59a0;
P_0c0b59a0: /* original 9049, guest PC 0x0c0b59a0 */
if(!s->budget--) { s->failed_pc=0x0c0b59a0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5a36u,2);
goto P_0c0b59a2;
P_0c0b59a2: /* original 4e0b, guest PC 0x0c0b59a2 */
if(!s->budget--) { s->failed_pc=0x0c0b59a2u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b59a6u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b59a6u) { target=s->pc; goto dispatch; }
goto P_0c0b59a6;
P_0c0b59a4: /* original 05de, guest PC 0x0c0b59a4 */
if(!s->budget--) { s->failed_pc=0x0c0b59a4u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b59a6;
P_0c0b59a6: /* original 9948, guest PC 0x0c0b59a6 */
if(!s->budget--) { s->failed_pc=0x0c0b59a6u; return 0; }
r[9]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5a3au,2);
goto P_0c0b59a8;
P_0c0b59a8: /* original 9448, guest PC 0x0c0b59a8 */
if(!s->budget--) { s->failed_pc=0x0c0b59a8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5a3cu,2);
goto P_0c0b59aa;
P_0c0b59aa: /* original 39dc, guest PC 0x0c0b59aa */
if(!s->budget--) { s->failed_pc=0x0c0b59aau; return 0; }
r[9]+=r[13];
goto P_0c0b59ac;
P_0c0b59ac: /* original 4e0b, guest PC 0x0c0b59ac */
if(!s->budget--) { s->failed_pc=0x0c0b59acu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b59b0u;
tmp=read(ram,r[9],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b59b0u) { target=s->pc; goto dispatch; }
goto P_0c0b59b0;
P_0c0b59ae: /* original 6592, guest PC 0x0c0b59ae */
if(!s->budget--) { s->failed_pc=0x0c0b59aeu; return 0; }
tmp=read(ram,r[9],4);
r[5]=tmp;
goto P_0c0b59b0;
P_0c0b59b0: /* original 9445, guest PC 0x0c0b59b0 */
if(!s->budget--) { s->failed_pc=0x0c0b59b0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5a3eu,2);
goto P_0c0b59b2;
P_0c0b59b2: /* original 4e0b, guest PC 0x0c0b59b2 */
if(!s->budget--) { s->failed_pc=0x0c0b59b2u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b59b6u;
tmp=read(ram,r[9],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b59b6u) { target=s->pc; goto dispatch; }
goto P_0c0b59b6;
P_0c0b59b4: /* original 6592, guest PC 0x0c0b59b4 */
if(!s->budget--) { s->failed_pc=0x0c0b59b4u; return 0; }
tmp=read(ram,r[9],4);
r[5]=tmp;
goto P_0c0b59b6;
P_0c0b59b6: /* original 9443, guest PC 0x0c0b59b6 */
if(!s->budget--) { s->failed_pc=0x0c0b59b6u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5a40u,2);
goto P_0c0b59b8;
P_0c0b59b8: /* original 4e0b, guest PC 0x0c0b59b8 */
if(!s->budget--) { s->failed_pc=0x0c0b59b8u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b59bcu;
tmp=read(ram,r[9],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b59bcu) { target=s->pc; goto dispatch; }
goto P_0c0b59bc;
P_0c0b59ba: /* original 6592, guest PC 0x0c0b59ba */
if(!s->budget--) { s->failed_pc=0x0c0b59bau; return 0; }
tmp=read(ram,r[9],4);
r[5]=tmp;
goto P_0c0b59bc;
P_0c0b59bc: /* original 9441, guest PC 0x0c0b59bc */
if(!s->budget--) { s->failed_pc=0x0c0b59bcu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5a42u,2);
goto P_0c0b59be;
P_0c0b59be: /* original 4e0b, guest PC 0x0c0b59be */
if(!s->budget--) { s->failed_pc=0x0c0b59beu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b59c2u;
tmp=read(ram,r[9],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b59c2u) { target=s->pc; goto dispatch; }
goto P_0c0b59c2;
P_0c0b59c0: /* original 6592, guest PC 0x0c0b59c0 */
if(!s->budget--) { s->failed_pc=0x0c0b59c0u; return 0; }
tmp=read(ram,r[9],4);
r[5]=tmp;
goto P_0c0b59c2;
P_0c0b59c2: /* original 9c3f, guest PC 0x0c0b59c2 */
if(!s->budget--) { s->failed_pc=0x0c0b59c2u; return 0; }
r[12]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5a44u,2);
goto P_0c0b59c4;
P_0c0b59c4: /* original 943f, guest PC 0x0c0b59c4 */
if(!s->budget--) { s->failed_pc=0x0c0b59c4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5a46u,2);
goto P_0c0b59c6;
P_0c0b59c6: /* original 3cdc, guest PC 0x0c0b59c6 */
if(!s->budget--) { s->failed_pc=0x0c0b59c6u; return 0; }
r[12]+=r[13];
goto P_0c0b59c8;
P_0c0b59c8: /* original 4e0b, guest PC 0x0c0b59c8 */
if(!s->budget--) { s->failed_pc=0x0c0b59c8u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b59ccu;
tmp=read(ram,r[12],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b59ccu) { target=s->pc; goto dispatch; }
goto P_0c0b59cc;
P_0c0b59ca: /* original 65c2, guest PC 0x0c0b59ca */
if(!s->budget--) { s->failed_pc=0x0c0b59cau; return 0; }
tmp=read(ram,r[12],4);
r[5]=tmp;
goto P_0c0b59cc;
P_0c0b59cc: /* original 943c, guest PC 0x0c0b59cc */
if(!s->budget--) { s->failed_pc=0x0c0b59ccu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5a48u,2);
goto P_0c0b59ce;
P_0c0b59ce: /* original 4e0b, guest PC 0x0c0b59ce */
if(!s->budget--) { s->failed_pc=0x0c0b59ceu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b59d2u;
tmp=read(ram,r[12],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b59d2u) { target=s->pc; goto dispatch; }
goto P_0c0b59d2;
P_0c0b59d0: /* original 65c2, guest PC 0x0c0b59d0 */
if(!s->budget--) { s->failed_pc=0x0c0b59d0u; return 0; }
tmp=read(ram,r[12],4);
r[5]=tmp;
goto P_0c0b59d2;
P_0c0b59d2: /* original 943a, guest PC 0x0c0b59d2 */
if(!s->budget--) { s->failed_pc=0x0c0b59d2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5a4au,2);
goto P_0c0b59d4;
P_0c0b59d4: /* original 4e0b, guest PC 0x0c0b59d4 */
if(!s->budget--) { s->failed_pc=0x0c0b59d4u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b59d8u;
tmp=read(ram,r[12],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b59d8u) { target=s->pc; goto dispatch; }
goto P_0c0b59d8;
P_0c0b59d6: /* original 65c2, guest PC 0x0c0b59d6 */
if(!s->budget--) { s->failed_pc=0x0c0b59d6u; return 0; }
tmp=read(ram,r[12],4);
r[5]=tmp;
goto P_0c0b59d8;
P_0c0b59d8: /* original 9438, guest PC 0x0c0b59d8 */
if(!s->budget--) { s->failed_pc=0x0c0b59d8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5a4cu,2);
goto P_0c0b59da;
P_0c0b59da: /* original 4e0b, guest PC 0x0c0b59da */
if(!s->budget--) { s->failed_pc=0x0c0b59dau; return 0; }
target=r[14];
r[16]=code_base|0x0c0b59deu;
tmp=read(ram,r[12],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b59deu) { target=s->pc; goto dispatch; }
goto P_0c0b59de;
P_0c0b59dc: /* original 65c2, guest PC 0x0c0b59dc */
if(!s->budget--) { s->failed_pc=0x0c0b59dcu; return 0; }
tmp=read(ram,r[12],4);
r[5]=tmp;
goto P_0c0b59de;
P_0c0b59de: /* original 9b36, guest PC 0x0c0b59de */
if(!s->budget--) { s->failed_pc=0x0c0b59deu; return 0; }
r[11]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5a4eu,2);
goto P_0c0b59e0;
P_0c0b59e0: /* original 3bdc, guest PC 0x0c0b59e0 */
if(!s->budget--) { s->failed_pc=0x0c0b59e0u; return 0; }
r[11]+=r[13];
goto P_0c0b59e2;
P_0c0b59e2: /* original a037, guest PC 0x0c0b59e2 */
if(!s->budget--) { s->failed_pc=0x0c0b59e2u; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
goto P_0c0b5a54;
P_0c0b59e4: /* original 65b2, guest PC 0x0c0b59e4 */
if(!s->budget--) { s->failed_pc=0x0c0b59e4u; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
if(!vf3_matrix_family(0x0c0b59e6u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0b59e6u; return 0; } return 1;
P_0c0b5a54: /* original 94ab, guest PC 0x0c0b5a54 */
if(!s->budget--) { s->failed_pc=0x0c0b5a54u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5baeu,2);
goto P_0c0b5a56;
P_0c0b5a56: /* original 4e0b, guest PC 0x0c0b5a56 */
if(!s->budget--) { s->failed_pc=0x0c0b5a56u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b5a5au;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b5a5au) { target=s->pc; goto dispatch; }
goto P_0c0b5a5a;
P_0c0b5a58: /* original 0009, guest PC 0x0c0b5a58 */
if(!s->budget--) { s->failed_pc=0x0c0b5a58u; return 0; }
goto P_0c0b5a5a;
P_0c0b5a5a: /* original 94a9, guest PC 0x0c0b5a5a */
if(!s->budget--) { s->failed_pc=0x0c0b5a5au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5bb0u,2);
goto P_0c0b5a5c;
P_0c0b5a5c: /* original 4e0b, guest PC 0x0c0b5a5c */
if(!s->budget--) { s->failed_pc=0x0c0b5a5cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b5a60u;
tmp=read(ram,r[11],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b5a60u) { target=s->pc; goto dispatch; }
goto P_0c0b5a60;
P_0c0b5a5e: /* original 65b2, guest PC 0x0c0b5a5e */
if(!s->budget--) { s->failed_pc=0x0c0b5a5eu; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
goto P_0c0b5a60;
P_0c0b5a60: /* original 94a7, guest PC 0x0c0b5a60 */
if(!s->budget--) { s->failed_pc=0x0c0b5a60u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5bb2u,2);
goto P_0c0b5a62;
P_0c0b5a62: /* original 4e0b, guest PC 0x0c0b5a62 */
if(!s->budget--) { s->failed_pc=0x0c0b5a62u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b5a66u;
tmp=read(ram,r[11],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b5a66u) { target=s->pc; goto dispatch; }
goto P_0c0b5a66;
P_0c0b5a64: /* original 65b2, guest PC 0x0c0b5a64 */
if(!s->budget--) { s->failed_pc=0x0c0b5a64u; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
goto P_0c0b5a66;
P_0c0b5a66: /* original 94a5, guest PC 0x0c0b5a66 */
if(!s->budget--) { s->failed_pc=0x0c0b5a66u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5bb4u,2);
goto P_0c0b5a68;
P_0c0b5a68: /* original 4e0b, guest PC 0x0c0b5a68 */
if(!s->budget--) { s->failed_pc=0x0c0b5a68u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b5a6cu;
tmp=read(ram,r[11],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b5a6cu) { target=s->pc; goto dispatch; }
goto P_0c0b5a6c;
P_0c0b5a6a: /* original 65b2, guest PC 0x0c0b5a6a */
if(!s->budget--) { s->failed_pc=0x0c0b5a6au; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
goto P_0c0b5a6c;
P_0c0b5a6c: /* original 9aa3, guest PC 0x0c0b5a6c */
if(!s->budget--) { s->failed_pc=0x0c0b5a6cu; return 0; }
r[10]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5bb6u,2);
goto P_0c0b5a6e;
P_0c0b5a6e: /* original 94a3, guest PC 0x0c0b5a6e */
if(!s->budget--) { s->failed_pc=0x0c0b5a6eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5bb8u,2);
goto P_0c0b5a70;
P_0c0b5a70: /* original 3adc, guest PC 0x0c0b5a70 */
if(!s->budget--) { s->failed_pc=0x0c0b5a70u; return 0; }
r[10]+=r[13];
goto P_0c0b5a72;
P_0c0b5a72: /* original 4e0b, guest PC 0x0c0b5a72 */
if(!s->budget--) { s->failed_pc=0x0c0b5a72u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b5a76u;
tmp=read(ram,r[10],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b5a76u) { target=s->pc; goto dispatch; }
goto P_0c0b5a76;
P_0c0b5a74: /* original 65a2, guest PC 0x0c0b5a74 */
if(!s->budget--) { s->failed_pc=0x0c0b5a74u; return 0; }
tmp=read(ram,r[10],4);
r[5]=tmp;
goto P_0c0b5a76;
P_0c0b5a76: /* original 94a0, guest PC 0x0c0b5a76 */
if(!s->budget--) { s->failed_pc=0x0c0b5a76u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5bbau,2);
goto P_0c0b5a78;
P_0c0b5a78: /* original 4e0b, guest PC 0x0c0b5a78 */
if(!s->budget--) { s->failed_pc=0x0c0b5a78u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b5a7cu;
tmp=read(ram,r[10],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b5a7cu) { target=s->pc; goto dispatch; }
goto P_0c0b5a7c;
P_0c0b5a7a: /* original 65a2, guest PC 0x0c0b5a7a */
if(!s->budget--) { s->failed_pc=0x0c0b5a7au; return 0; }
tmp=read(ram,r[10],4);
r[5]=tmp;
goto P_0c0b5a7c;
P_0c0b5a7c: /* original 949e, guest PC 0x0c0b5a7c */
if(!s->budget--) { s->failed_pc=0x0c0b5a7cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5bbcu,2);
goto P_0c0b5a7e;
P_0c0b5a7e: /* original 4e0b, guest PC 0x0c0b5a7e */
if(!s->budget--) { s->failed_pc=0x0c0b5a7eu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b5a82u;
tmp=read(ram,r[10],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b5a82u) { target=s->pc; goto dispatch; }
goto P_0c0b5a82;
P_0c0b5a80: /* original 65a2, guest PC 0x0c0b5a80 */
if(!s->budget--) { s->failed_pc=0x0c0b5a80u; return 0; }
tmp=read(ram,r[10],4);
r[5]=tmp;
goto P_0c0b5a82;
P_0c0b5a82: /* original 949c, guest PC 0x0c0b5a82 */
if(!s->budget--) { s->failed_pc=0x0c0b5a82u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5bbeu,2);
goto P_0c0b5a84;
P_0c0b5a84: /* original 4e0b, guest PC 0x0c0b5a84 */
if(!s->budget--) { s->failed_pc=0x0c0b5a84u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b5a88u;
tmp=read(ram,r[10],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b5a88u) { target=s->pc; goto dispatch; }
goto P_0c0b5a88;
P_0c0b5a86: /* original 65a2, guest PC 0x0c0b5a86 */
if(!s->budget--) { s->failed_pc=0x0c0b5a86u; return 0; }
tmp=read(ram,r[10],4);
r[5]=tmp;
goto P_0c0b5a88;
P_0c0b5a88: /* original 949a, guest PC 0x0c0b5a88 */
if(!s->budget--) { s->failed_pc=0x0c0b5a88u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5bc0u,2);
goto P_0c0b5a8a;
P_0c0b5a8a: /* original 65f2, guest PC 0x0c0b5a8a */
if(!s->budget--) { s->failed_pc=0x0c0b5a8au; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0b5a8c;
P_0c0b5a8c: /* original 4e0b, guest PC 0x0c0b5a8c */
if(!s->budget--) { s->failed_pc=0x0c0b5a8cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b5a90u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b5a90u) { target=s->pc; goto dispatch; }
goto P_0c0b5a90;
P_0c0b5a8e: /* original 6552, guest PC 0x0c0b5a8e */
if(!s->budget--) { s->failed_pc=0x0c0b5a8eu; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b5a90;
P_0c0b5a90: /* original 9497, guest PC 0x0c0b5a90 */
if(!s->budget--) { s->failed_pc=0x0c0b5a90u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5bc2u,2);
goto P_0c0b5a92;
P_0c0b5a92: /* original 55f1, guest PC 0x0c0b5a92 */
if(!s->budget--) { s->failed_pc=0x0c0b5a92u; return 0; }
r[5]=read(ram,r[15]+4,4);
goto P_0c0b5a94;
P_0c0b5a94: /* original 4e0b, guest PC 0x0c0b5a94 */
if(!s->budget--) { s->failed_pc=0x0c0b5a94u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b5a98u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b5a98u) { target=s->pc; goto dispatch; }
goto P_0c0b5a98;
P_0c0b5a96: /* original 6552, guest PC 0x0c0b5a96 */
if(!s->budget--) { s->failed_pc=0x0c0b5a96u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b5a98;
P_0c0b5a98: /* original 9494, guest PC 0x0c0b5a98 */
if(!s->budget--) { s->failed_pc=0x0c0b5a98u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5bc4u,2);
goto P_0c0b5a9a;
P_0c0b5a9a: /* original 4e0b, guest PC 0x0c0b5a9a */
if(!s->budget--) { s->failed_pc=0x0c0b5a9au; return 0; }
target=r[14];
r[16]=code_base|0x0c0b5a9eu;
tmp=read(ram,r[9],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b5a9eu) { target=s->pc; goto dispatch; }
goto P_0c0b5a9e;
P_0c0b5a9c: /* original 6592, guest PC 0x0c0b5a9c */
if(!s->budget--) { s->failed_pc=0x0c0b5a9cu; return 0; }
tmp=read(ram,r[9],4);
r[5]=tmp;
goto P_0c0b5a9e;
P_0c0b5a9e: /* original 9492, guest PC 0x0c0b5a9e */
if(!s->budget--) { s->failed_pc=0x0c0b5a9eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5bc6u,2);
goto P_0c0b5aa0;
P_0c0b5aa0: /* original 4e0b, guest PC 0x0c0b5aa0 */
if(!s->budget--) { s->failed_pc=0x0c0b5aa0u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b5aa4u;
tmp=read(ram,r[9],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b5aa4u) { target=s->pc; goto dispatch; }
goto P_0c0b5aa4;
P_0c0b5aa2: /* original 6592, guest PC 0x0c0b5aa2 */
if(!s->budget--) { s->failed_pc=0x0c0b5aa2u; return 0; }
tmp=read(ram,r[9],4);
r[5]=tmp;
goto P_0c0b5aa4;
P_0c0b5aa4: /* original 9490, guest PC 0x0c0b5aa4 */
if(!s->budget--) { s->failed_pc=0x0c0b5aa4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5bc8u,2);
goto P_0c0b5aa6;
P_0c0b5aa6: /* original 4e0b, guest PC 0x0c0b5aa6 */
if(!s->budget--) { s->failed_pc=0x0c0b5aa6u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b5aaau;
tmp=read(ram,r[9],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b5aaau) { target=s->pc; goto dispatch; }
goto P_0c0b5aaa;
P_0c0b5aa8: /* original 6592, guest PC 0x0c0b5aa8 */
if(!s->budget--) { s->failed_pc=0x0c0b5aa8u; return 0; }
tmp=read(ram,r[9],4);
r[5]=tmp;
goto P_0c0b5aaa;
P_0c0b5aaa: /* original 948e, guest PC 0x0c0b5aaa */
if(!s->budget--) { s->failed_pc=0x0c0b5aaau; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5bcau,2);
goto P_0c0b5aac;
P_0c0b5aac: /* original 4e0b, guest PC 0x0c0b5aac */
if(!s->budget--) { s->failed_pc=0x0c0b5aacu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b5ab0u;
tmp=read(ram,r[9],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b5ab0u) { target=s->pc; goto dispatch; }
goto P_0c0b5ab0;
P_0c0b5aae: /* original 6592, guest PC 0x0c0b5aae */
if(!s->budget--) { s->failed_pc=0x0c0b5aaeu; return 0; }
tmp=read(ram,r[9],4);
r[5]=tmp;
goto P_0c0b5ab0;
P_0c0b5ab0: /* original 948c, guest PC 0x0c0b5ab0 */
if(!s->budget--) { s->failed_pc=0x0c0b5ab0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5bccu,2);
goto P_0c0b5ab2;
P_0c0b5ab2: /* original 4e0b, guest PC 0x0c0b5ab2 */
if(!s->budget--) { s->failed_pc=0x0c0b5ab2u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b5ab6u;
tmp=read(ram,r[12],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b5ab6u) { target=s->pc; goto dispatch; }
goto P_0c0b5ab6;
P_0c0b5ab4: /* original 65c2, guest PC 0x0c0b5ab4 */
if(!s->budget--) { s->failed_pc=0x0c0b5ab4u; return 0; }
tmp=read(ram,r[12],4);
r[5]=tmp;
goto P_0c0b5ab6;
P_0c0b5ab6: /* original 948a, guest PC 0x0c0b5ab6 */
if(!s->budget--) { s->failed_pc=0x0c0b5ab6u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5bceu,2);
goto P_0c0b5ab8;
P_0c0b5ab8: /* original 4e0b, guest PC 0x0c0b5ab8 */
if(!s->budget--) { s->failed_pc=0x0c0b5ab8u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b5abcu;
tmp=read(ram,r[12],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b5abcu) { target=s->pc; goto dispatch; }
goto P_0c0b5abc;
P_0c0b5aba: /* original 65c2, guest PC 0x0c0b5aba */
if(!s->budget--) { s->failed_pc=0x0c0b5abau; return 0; }
tmp=read(ram,r[12],4);
r[5]=tmp;
goto P_0c0b5abc;
P_0c0b5abc: /* original 9488, guest PC 0x0c0b5abc */
if(!s->budget--) { s->failed_pc=0x0c0b5abcu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5bd0u,2);
goto P_0c0b5abe;
P_0c0b5abe: /* original 4e0b, guest PC 0x0c0b5abe */
if(!s->budget--) { s->failed_pc=0x0c0b5abeu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b5ac2u;
tmp=read(ram,r[12],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b5ac2u) { target=s->pc; goto dispatch; }
goto P_0c0b5ac2;
P_0c0b5ac0: /* original 65c2, guest PC 0x0c0b5ac0 */
if(!s->budget--) { s->failed_pc=0x0c0b5ac0u; return 0; }
tmp=read(ram,r[12],4);
r[5]=tmp;
goto P_0c0b5ac2;
P_0c0b5ac2: /* original 9486, guest PC 0x0c0b5ac2 */
if(!s->budget--) { s->failed_pc=0x0c0b5ac2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5bd2u,2);
goto P_0c0b5ac4;
P_0c0b5ac4: /* original 4e0b, guest PC 0x0c0b5ac4 */
if(!s->budget--) { s->failed_pc=0x0c0b5ac4u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b5ac8u;
tmp=read(ram,r[12],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b5ac8u) { target=s->pc; goto dispatch; }
goto P_0c0b5ac8;
P_0c0b5ac6: /* original 65c2, guest PC 0x0c0b5ac6 */
if(!s->budget--) { s->failed_pc=0x0c0b5ac6u; return 0; }
tmp=read(ram,r[12],4);
r[5]=tmp;
goto P_0c0b5ac8;
P_0c0b5ac8: /* original 9484, guest PC 0x0c0b5ac8 */
if(!s->budget--) { s->failed_pc=0x0c0b5ac8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5bd4u,2);
goto P_0c0b5aca;
P_0c0b5aca: /* original 4e0b, guest PC 0x0c0b5aca */
if(!s->budget--) { s->failed_pc=0x0c0b5acau; return 0; }
target=r[14];
r[16]=code_base|0x0c0b5aceu;
tmp=read(ram,r[11],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b5aceu) { target=s->pc; goto dispatch; }
goto P_0c0b5ace;
P_0c0b5acc: /* original 65b2, guest PC 0x0c0b5acc */
if(!s->budget--) { s->failed_pc=0x0c0b5accu; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
goto P_0c0b5ace;
P_0c0b5ace: /* original 9482, guest PC 0x0c0b5ace */
if(!s->budget--) { s->failed_pc=0x0c0b5aceu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5bd6u,2);
goto P_0c0b5ad0;
P_0c0b5ad0: /* original 4e0b, guest PC 0x0c0b5ad0 */
if(!s->budget--) { s->failed_pc=0x0c0b5ad0u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b5ad4u;
tmp=read(ram,r[11],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b5ad4u) { target=s->pc; goto dispatch; }
goto P_0c0b5ad4;
P_0c0b5ad2: /* original 65b2, guest PC 0x0c0b5ad2 */
if(!s->budget--) { s->failed_pc=0x0c0b5ad2u; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
goto P_0c0b5ad4;
P_0c0b5ad4: /* original 9480, guest PC 0x0c0b5ad4 */
if(!s->budget--) { s->failed_pc=0x0c0b5ad4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5bd8u,2);
goto P_0c0b5ad6;
P_0c0b5ad6: /* original 4e0b, guest PC 0x0c0b5ad6 */
if(!s->budget--) { s->failed_pc=0x0c0b5ad6u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b5adau;
tmp=read(ram,r[11],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b5adau) { target=s->pc; goto dispatch; }
goto P_0c0b5ada;
P_0c0b5ad8: /* original 65b2, guest PC 0x0c0b5ad8 */
if(!s->budget--) { s->failed_pc=0x0c0b5ad8u; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
goto P_0c0b5ada;
P_0c0b5ada: /* original 947e, guest PC 0x0c0b5ada */
if(!s->budget--) { s->failed_pc=0x0c0b5adau; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5bdau,2);
goto P_0c0b5adc;
P_0c0b5adc: /* original 4e0b, guest PC 0x0c0b5adc */
if(!s->budget--) { s->failed_pc=0x0c0b5adcu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b5ae0u;
tmp=read(ram,r[11],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b5ae0u) { target=s->pc; goto dispatch; }
goto P_0c0b5ae0;
P_0c0b5ade: /* original 65b2, guest PC 0x0c0b5ade */
if(!s->budget--) { s->failed_pc=0x0c0b5adeu; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
goto P_0c0b5ae0;
P_0c0b5ae0: /* original 947c, guest PC 0x0c0b5ae0 */
if(!s->budget--) { s->failed_pc=0x0c0b5ae0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5bdcu,2);
goto P_0c0b5ae2;
P_0c0b5ae2: /* original 4e0b, guest PC 0x0c0b5ae2 */
if(!s->budget--) { s->failed_pc=0x0c0b5ae2u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b5ae6u;
tmp=read(ram,r[10],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b5ae6u) { target=s->pc; goto dispatch; }
goto P_0c0b5ae6;
P_0c0b5ae4: /* original 65a2, guest PC 0x0c0b5ae4 */
if(!s->budget--) { s->failed_pc=0x0c0b5ae4u; return 0; }
tmp=read(ram,r[10],4);
r[5]=tmp;
goto P_0c0b5ae6;
P_0c0b5ae6: /* original 947a, guest PC 0x0c0b5ae6 */
if(!s->budget--) { s->failed_pc=0x0c0b5ae6u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5bdeu,2);
goto P_0c0b5ae8;
P_0c0b5ae8: /* original 4e0b, guest PC 0x0c0b5ae8 */
if(!s->budget--) { s->failed_pc=0x0c0b5ae8u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b5aecu;
tmp=read(ram,r[10],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b5aecu) { target=s->pc; goto dispatch; }
goto P_0c0b5aec;
P_0c0b5aea: /* original 65a2, guest PC 0x0c0b5aea */
if(!s->budget--) { s->failed_pc=0x0c0b5aeau; return 0; }
tmp=read(ram,r[10],4);
r[5]=tmp;
goto P_0c0b5aec;
P_0c0b5aec: /* original 9478, guest PC 0x0c0b5aec */
if(!s->budget--) { s->failed_pc=0x0c0b5aecu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5be0u,2);
goto P_0c0b5aee;
P_0c0b5aee: /* original 4e0b, guest PC 0x0c0b5aee */
if(!s->budget--) { s->failed_pc=0x0c0b5aeeu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b5af2u;
tmp=read(ram,r[10],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b5af2u) { target=s->pc; goto dispatch; }
goto P_0c0b5af2;
P_0c0b5af0: /* original 65a2, guest PC 0x0c0b5af0 */
if(!s->budget--) { s->failed_pc=0x0c0b5af0u; return 0; }
tmp=read(ram,r[10],4);
r[5]=tmp;
goto P_0c0b5af2;
P_0c0b5af2: /* original 9476, guest PC 0x0c0b5af2 */
if(!s->budget--) { s->failed_pc=0x0c0b5af2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5be2u,2);
goto P_0c0b5af4;
P_0c0b5af4: /* original 4e0b, guest PC 0x0c0b5af4 */
if(!s->budget--) { s->failed_pc=0x0c0b5af4u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b5af8u;
tmp=read(ram,r[10],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b5af8u) { target=s->pc; goto dispatch; }
goto P_0c0b5af8;
P_0c0b5af6: /* original 65a2, guest PC 0x0c0b5af6 */
if(!s->budget--) { s->failed_pc=0x0c0b5af6u; return 0; }
tmp=read(ram,r[10],4);
r[5]=tmp;
goto P_0c0b5af8;
P_0c0b5af8: /* original 9574, guest PC 0x0c0b5af8 */
if(!s->budget--) { s->failed_pc=0x0c0b5af8u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5be4u,2);
goto P_0c0b5afa;
P_0c0b5afa: /* original 35dc, guest PC 0x0c0b5afa */
if(!s->budget--) { s->failed_pc=0x0c0b5afau; return 0; }
r[5]+=r[13];
goto P_0c0b5afc;
P_0c0b5afc: /* original 2f52, guest PC 0x0c0b5afc */
if(!s->budget--) { s->failed_pc=0x0c0b5afcu; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0b5afe;
P_0c0b5afe: /* original 9472, guest PC 0x0c0b5afe */
if(!s->budget--) { s->failed_pc=0x0c0b5afeu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5be6u,2);
goto P_0c0b5b00;
P_0c0b5b00: /* original 4e0b, guest PC 0x0c0b5b00 */
if(!s->budget--) { s->failed_pc=0x0c0b5b00u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b5b04u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b5b04u) { target=s->pc; goto dispatch; }
goto P_0c0b5b04;
P_0c0b5b02: /* original 6552, guest PC 0x0c0b5b02 */
if(!s->budget--) { s->failed_pc=0x0c0b5b02u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b5b04;
P_0c0b5b04: /* original 9470, guest PC 0x0c0b5b04 */
if(!s->budget--) { s->failed_pc=0x0c0b5b04u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5be8u,2);
goto P_0c0b5b06;
P_0c0b5b06: /* original 65f2, guest PC 0x0c0b5b06 */
if(!s->budget--) { s->failed_pc=0x0c0b5b06u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0b5b08;
P_0c0b5b08: /* original 4e0b, guest PC 0x0c0b5b08 */
if(!s->budget--) { s->failed_pc=0x0c0b5b08u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b5b0cu;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b5b0cu) { target=s->pc; goto dispatch; }
goto P_0c0b5b0c;
P_0c0b5b0a: /* original 6552, guest PC 0x0c0b5b0a */
if(!s->budget--) { s->failed_pc=0x0c0b5b0au; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b5b0c;
P_0c0b5b0c: /* original 956d, guest PC 0x0c0b5b0c */
if(!s->budget--) { s->failed_pc=0x0c0b5b0cu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5beau,2);
goto P_0c0b5b0e;
P_0c0b5b0e: /* original 35dc, guest PC 0x0c0b5b0e */
if(!s->budget--) { s->failed_pc=0x0c0b5b0eu; return 0; }
r[5]+=r[13];
goto P_0c0b5b10;
P_0c0b5b10: /* original 2f52, guest PC 0x0c0b5b10 */
if(!s->budget--) { s->failed_pc=0x0c0b5b10u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0b5b12;
P_0c0b5b12: /* original 946b, guest PC 0x0c0b5b12 */
if(!s->budget--) { s->failed_pc=0x0c0b5b12u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5becu,2);
goto P_0c0b5b14;
P_0c0b5b14: /* original 4e0b, guest PC 0x0c0b5b14 */
if(!s->budget--) { s->failed_pc=0x0c0b5b14u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b5b18u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b5b18u) { target=s->pc; goto dispatch; }
goto P_0c0b5b18;
P_0c0b5b16: /* original 6552, guest PC 0x0c0b5b16 */
if(!s->budget--) { s->failed_pc=0x0c0b5b16u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b5b18;
P_0c0b5b18: /* original 9469, guest PC 0x0c0b5b18 */
if(!s->budget--) { s->failed_pc=0x0c0b5b18u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5beeu,2);
goto P_0c0b5b1a;
P_0c0b5b1a: /* original 65f2, guest PC 0x0c0b5b1a */
if(!s->budget--) { s->failed_pc=0x0c0b5b1au; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0b5b1c;
P_0c0b5b1c: /* original 4e0b, guest PC 0x0c0b5b1c */
if(!s->budget--) { s->failed_pc=0x0c0b5b1cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b5b20u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b5b20u) { target=s->pc; goto dispatch; }
goto P_0c0b5b20;
P_0c0b5b1e: /* original 6552, guest PC 0x0c0b5b1e */
if(!s->budget--) { s->failed_pc=0x0c0b5b1eu; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b5b20;
P_0c0b5b20: /* original 9467, guest PC 0x0c0b5b20 */
if(!s->budget--) { s->failed_pc=0x0c0b5b20u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5bf2u,2);
goto P_0c0b5b22;
P_0c0b5b22: /* original 9065, guest PC 0x0c0b5b22 */
if(!s->budget--) { s->failed_pc=0x0c0b5b22u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5bf0u,2);
goto P_0c0b5b24;
P_0c0b5b24: /* original 4e0b, guest PC 0x0c0b5b24 */
if(!s->budget--) { s->failed_pc=0x0c0b5b24u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b5b28u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b5b28u) { target=s->pc; goto dispatch; }
goto P_0c0b5b28;
P_0c0b5b26: /* original 05de, guest PC 0x0c0b5b26 */
if(!s->budget--) { s->failed_pc=0x0c0b5b26u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b5b28;
P_0c0b5b28: /* original 9564, guest PC 0x0c0b5b28 */
if(!s->budget--) { s->failed_pc=0x0c0b5b28u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5bf4u,2);
goto P_0c0b5b2a;
P_0c0b5b2a: /* original 35dc, guest PC 0x0c0b5b2a */
if(!s->budget--) { s->failed_pc=0x0c0b5b2au; return 0; }
r[5]+=r[13];
goto P_0c0b5b2c;
P_0c0b5b2c: /* original 2f52, guest PC 0x0c0b5b2c */
if(!s->budget--) { s->failed_pc=0x0c0b5b2cu; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0b5b2e;
P_0c0b5b2e: /* original 9462, guest PC 0x0c0b5b2e */
if(!s->budget--) { s->failed_pc=0x0c0b5b2eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5bf6u,2);
goto P_0c0b5b30;
P_0c0b5b30: /* original 4e0b, guest PC 0x0c0b5b30 */
if(!s->budget--) { s->failed_pc=0x0c0b5b30u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b5b34u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b5b34u) { target=s->pc; goto dispatch; }
goto P_0c0b5b34;
P_0c0b5b32: /* original 6552, guest PC 0x0c0b5b32 */
if(!s->budget--) { s->failed_pc=0x0c0b5b32u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b5b34;
P_0c0b5b34: /* original 9460, guest PC 0x0c0b5b34 */
if(!s->budget--) { s->failed_pc=0x0c0b5b34u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5bf8u,2);
goto P_0c0b5b36;
P_0c0b5b36: /* original 65f2, guest PC 0x0c0b5b36 */
if(!s->budget--) { s->failed_pc=0x0c0b5b36u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0b5b38;
P_0c0b5b38: /* original 4e0b, guest PC 0x0c0b5b38 */
if(!s->budget--) { s->failed_pc=0x0c0b5b38u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b5b3cu;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b5b3cu) { target=s->pc; goto dispatch; }
goto P_0c0b5b3c;
P_0c0b5b3a: /* original 6552, guest PC 0x0c0b5b3a */
if(!s->budget--) { s->failed_pc=0x0c0b5b3au; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b5b3c;
P_0c0b5b3c: /* original 945e, guest PC 0x0c0b5b3c */
if(!s->budget--) { s->failed_pc=0x0c0b5b3cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5bfcu,2);
goto P_0c0b5b3e;
P_0c0b5b3e: /* original 905c, guest PC 0x0c0b5b3e */
if(!s->budget--) { s->failed_pc=0x0c0b5b3eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5bfau,2);
goto P_0c0b5b40;
P_0c0b5b40: /* original 4e0b, guest PC 0x0c0b5b40 */
if(!s->budget--) { s->failed_pc=0x0c0b5b40u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b5b44u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b5b44u) { target=s->pc; goto dispatch; }
goto P_0c0b5b44;
P_0c0b5b42: /* original 05de, guest PC 0x0c0b5b42 */
if(!s->budget--) { s->failed_pc=0x0c0b5b42u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b5b44;
P_0c0b5b44: /* original 955b, guest PC 0x0c0b5b44 */
if(!s->budget--) { s->failed_pc=0x0c0b5b44u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5bfeu,2);
goto P_0c0b5b46;
P_0c0b5b46: /* original 35dc, guest PC 0x0c0b5b46 */
if(!s->budget--) { s->failed_pc=0x0c0b5b46u; return 0; }
r[5]+=r[13];
goto P_0c0b5b48;
P_0c0b5b48: /* original 2f52, guest PC 0x0c0b5b48 */
if(!s->budget--) { s->failed_pc=0x0c0b5b48u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0b5b4a;
P_0c0b5b4a: /* original 9459, guest PC 0x0c0b5b4a */
if(!s->budget--) { s->failed_pc=0x0c0b5b4au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5c00u,2);
goto P_0c0b5b4c;
P_0c0b5b4c: /* original 4e0b, guest PC 0x0c0b5b4c */
if(!s->budget--) { s->failed_pc=0x0c0b5b4cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b5b50u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b5b50u) { target=s->pc; goto dispatch; }
goto P_0c0b5b50;
P_0c0b5b4e: /* original 6552, guest PC 0x0c0b5b4e */
if(!s->budget--) { s->failed_pc=0x0c0b5b4eu; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b5b50;
P_0c0b5b50: /* original 9457, guest PC 0x0c0b5b50 */
if(!s->budget--) { s->failed_pc=0x0c0b5b50u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5c02u,2);
goto P_0c0b5b52;
P_0c0b5b52: /* original 65f2, guest PC 0x0c0b5b52 */
if(!s->budget--) { s->failed_pc=0x0c0b5b52u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0b5b54;
P_0c0b5b54: /* original 4e0b, guest PC 0x0c0b5b54 */
if(!s->budget--) { s->failed_pc=0x0c0b5b54u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b5b58u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b5b58u) { target=s->pc; goto dispatch; }
goto P_0c0b5b58;
P_0c0b5b56: /* original 6552, guest PC 0x0c0b5b56 */
if(!s->budget--) { s->failed_pc=0x0c0b5b56u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b5b58;
P_0c0b5b58: /* original 9455, guest PC 0x0c0b5b58 */
if(!s->budget--) { s->failed_pc=0x0c0b5b58u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5c06u,2);
goto P_0c0b5b5a;
P_0c0b5b5a: /* original 9053, guest PC 0x0c0b5b5a */
if(!s->budget--) { s->failed_pc=0x0c0b5b5au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5c04u,2);
goto P_0c0b5b5c;
P_0c0b5b5c: /* original 4e0b, guest PC 0x0c0b5b5c */
if(!s->budget--) { s->failed_pc=0x0c0b5b5cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b5b60u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b5b60u) { target=s->pc; goto dispatch; }
goto P_0c0b5b60;
P_0c0b5b5e: /* original 05de, guest PC 0x0c0b5b5e */
if(!s->budget--) { s->failed_pc=0x0c0b5b5eu; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b5b60;
P_0c0b5b60: /* original 9552, guest PC 0x0c0b5b60 */
if(!s->budget--) { s->failed_pc=0x0c0b5b60u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5c08u,2);
goto P_0c0b5b62;
P_0c0b5b62: /* original 35dc, guest PC 0x0c0b5b62 */
if(!s->budget--) { s->failed_pc=0x0c0b5b62u; return 0; }
r[5]+=r[13];
goto P_0c0b5b64;
P_0c0b5b64: /* original 2f52, guest PC 0x0c0b5b64 */
if(!s->budget--) { s->failed_pc=0x0c0b5b64u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0b5b66;
P_0c0b5b66: /* original 9450, guest PC 0x0c0b5b66 */
if(!s->budget--) { s->failed_pc=0x0c0b5b66u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5c0au,2);
goto P_0c0b5b68;
P_0c0b5b68: /* original 4e0b, guest PC 0x0c0b5b68 */
if(!s->budget--) { s->failed_pc=0x0c0b5b68u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b5b6cu;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b5b6cu) { target=s->pc; goto dispatch; }
goto P_0c0b5b6c;
P_0c0b5b6a: /* original 6552, guest PC 0x0c0b5b6a */
if(!s->budget--) { s->failed_pc=0x0c0b5b6au; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b5b6c;
P_0c0b5b6c: /* original 944e, guest PC 0x0c0b5b6c */
if(!s->budget--) { s->failed_pc=0x0c0b5b6cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5c0cu,2);
goto P_0c0b5b6e;
P_0c0b5b6e: /* original 65f2, guest PC 0x0c0b5b6e */
if(!s->budget--) { s->failed_pc=0x0c0b5b6eu; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0b5b70;
P_0c0b5b70: /* original 4e0b, guest PC 0x0c0b5b70 */
if(!s->budget--) { s->failed_pc=0x0c0b5b70u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b5b74u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b5b74u) { target=s->pc; goto dispatch; }
goto P_0c0b5b74;
P_0c0b5b72: /* original 6552, guest PC 0x0c0b5b72 */
if(!s->budget--) { s->failed_pc=0x0c0b5b72u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b5b74;
P_0c0b5b74: /* original 954b, guest PC 0x0c0b5b74 */
if(!s->budget--) { s->failed_pc=0x0c0b5b74u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5c0eu,2);
goto P_0c0b5b76;
P_0c0b5b76: /* original 35dc, guest PC 0x0c0b5b76 */
if(!s->budget--) { s->failed_pc=0x0c0b5b76u; return 0; }
r[5]+=r[13];
goto P_0c0b5b78;
P_0c0b5b78: /* original 2f52, guest PC 0x0c0b5b78 */
if(!s->budget--) { s->failed_pc=0x0c0b5b78u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0b5b7a;
P_0c0b5b7a: /* original 9449, guest PC 0x0c0b5b7a */
if(!s->budget--) { s->failed_pc=0x0c0b5b7au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5c10u,2);
goto P_0c0b5b7c;
P_0c0b5b7c: /* original 4e0b, guest PC 0x0c0b5b7c */
if(!s->budget--) { s->failed_pc=0x0c0b5b7cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b5b80u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b5b80u) { target=s->pc; goto dispatch; }
goto P_0c0b5b80;
P_0c0b5b7e: /* original 6552, guest PC 0x0c0b5b7e */
if(!s->budget--) { s->failed_pc=0x0c0b5b7eu; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b5b80;
P_0c0b5b80: /* original 9447, guest PC 0x0c0b5b80 */
if(!s->budget--) { s->failed_pc=0x0c0b5b80u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5c12u,2);
goto P_0c0b5b82;
P_0c0b5b82: /* original 65f2, guest PC 0x0c0b5b82 */
if(!s->budget--) { s->failed_pc=0x0c0b5b82u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0b5b84;
P_0c0b5b84: /* original 4e0b, guest PC 0x0c0b5b84 */
if(!s->budget--) { s->failed_pc=0x0c0b5b84u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b5b88u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b5b88u) { target=s->pc; goto dispatch; }
goto P_0c0b5b88;
P_0c0b5b86: /* original 6552, guest PC 0x0c0b5b86 */
if(!s->budget--) { s->failed_pc=0x0c0b5b86u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b5b88;
P_0c0b5b88: /* original 9445, guest PC 0x0c0b5b88 */
if(!s->budget--) { s->failed_pc=0x0c0b5b88u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5c16u,2);
goto P_0c0b5b8a;
P_0c0b5b8a: /* original 9043, guest PC 0x0c0b5b8a */
if(!s->budget--) { s->failed_pc=0x0c0b5b8au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5c14u,2);
goto P_0c0b5b8c;
P_0c0b5b8c: /* original 4e0b, guest PC 0x0c0b5b8c */
if(!s->budget--) { s->failed_pc=0x0c0b5b8cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b5b90u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b5b90u) { target=s->pc; goto dispatch; }
goto P_0c0b5b90;
P_0c0b5b8e: /* original 05de, guest PC 0x0c0b5b8e */
if(!s->budget--) { s->failed_pc=0x0c0b5b8eu; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b5b90;
P_0c0b5b90: /* original 9443, guest PC 0x0c0b5b90 */
if(!s->budget--) { s->failed_pc=0x0c0b5b90u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5c1au,2);
goto P_0c0b5b92;
P_0c0b5b92: /* original 9041, guest PC 0x0c0b5b92 */
if(!s->budget--) { s->failed_pc=0x0c0b5b92u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5c18u,2);
goto P_0c0b5b94;
P_0c0b5b94: /* original 4e0b, guest PC 0x0c0b5b94 */
if(!s->budget--) { s->failed_pc=0x0c0b5b94u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b5b98u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b5b98u) { target=s->pc; goto dispatch; }
goto P_0c0b5b98;
P_0c0b5b96: /* original 05de, guest PC 0x0c0b5b96 */
if(!s->budget--) { s->failed_pc=0x0c0b5b96u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b5b98;
P_0c0b5b98: /* original 9441, guest PC 0x0c0b5b98 */
if(!s->budget--) { s->failed_pc=0x0c0b5b98u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5c1eu,2);
goto P_0c0b5b9a;
P_0c0b5b9a: /* original 903f, guest PC 0x0c0b5b9a */
if(!s->budget--) { s->failed_pc=0x0c0b5b9au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5c1cu,2);
goto P_0c0b5b9c;
P_0c0b5b9c: /* original 4e0b, guest PC 0x0c0b5b9c */
if(!s->budget--) { s->failed_pc=0x0c0b5b9cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b5ba0u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b5ba0u) { target=s->pc; goto dispatch; }
goto P_0c0b5ba0;
P_0c0b5b9e: /* original 05de, guest PC 0x0c0b5b9e */
if(!s->budget--) { s->failed_pc=0x0c0b5b9eu; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b5ba0;
P_0c0b5ba0: /* original 943f, guest PC 0x0c0b5ba0 */
if(!s->budget--) { s->failed_pc=0x0c0b5ba0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5c22u,2);
goto P_0c0b5ba2;
P_0c0b5ba2: /* original 903d, guest PC 0x0c0b5ba2 */
if(!s->budget--) { s->failed_pc=0x0c0b5ba2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5c20u,2);
goto P_0c0b5ba4;
P_0c0b5ba4: /* original 4e0b, guest PC 0x0c0b5ba4 */
if(!s->budget--) { s->failed_pc=0x0c0b5ba4u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b5ba8u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b5ba8u) { target=s->pc; goto dispatch; }
goto P_0c0b5ba8;
P_0c0b5ba6: /* original 05de, guest PC 0x0c0b5ba6 */
if(!s->budget--) { s->failed_pc=0x0c0b5ba6u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b5ba8;
P_0c0b5ba8: /* original 903c, guest PC 0x0c0b5ba8 */
if(!s->budget--) { s->failed_pc=0x0c0b5ba8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5c24u,2);
goto P_0c0b5baa;
P_0c0b5baa: /* original a03c, guest PC 0x0c0b5baa */
if(!s->budget--) { s->failed_pc=0x0c0b5baau; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b5c26;
P_0c0b5bac: /* original 05de, guest PC 0x0c0b5bac */
if(!s->budget--) { s->failed_pc=0x0c0b5bacu; return 0; }
r[5]=read(ram,r[13]+r[0],4);
if(!vf3_matrix_family(0x0c0b5baeu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0b5baeu; return 0; } return 1;
P_0c0b5c26: /* original 9432, guest PC 0x0c0b5c26 */
if(!s->budget--) { s->failed_pc=0x0c0b5c26u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5c8eu,2);
goto P_0c0b5c28;
P_0c0b5c28: /* original 4e0b, guest PC 0x0c0b5c28 */
if(!s->budget--) { s->failed_pc=0x0c0b5c28u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b5c2cu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b5c2cu) { target=s->pc; goto dispatch; }
goto P_0c0b5c2c;
P_0c0b5c2a: /* original 0009, guest PC 0x0c0b5c2a */
if(!s->budget--) { s->failed_pc=0x0c0b5c2au; return 0; }
goto P_0c0b5c2c;
P_0c0b5c2c: /* original 9431, guest PC 0x0c0b5c2c */
if(!s->budget--) { s->failed_pc=0x0c0b5c2cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5c92u,2);
goto P_0c0b5c2e;
P_0c0b5c2e: /* original 902f, guest PC 0x0c0b5c2e */
if(!s->budget--) { s->failed_pc=0x0c0b5c2eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5c90u,2);
goto P_0c0b5c30;
P_0c0b5c30: /* original 4e0b, guest PC 0x0c0b5c30 */
if(!s->budget--) { s->failed_pc=0x0c0b5c30u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b5c34u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b5c34u) { target=s->pc; goto dispatch; }
goto P_0c0b5c34;
P_0c0b5c32: /* original 05de, guest PC 0x0c0b5c32 */
if(!s->budget--) { s->failed_pc=0x0c0b5c32u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b5c34;
P_0c0b5c34: /* original 942f, guest PC 0x0c0b5c34 */
if(!s->budget--) { s->failed_pc=0x0c0b5c34u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5c96u,2);
goto P_0c0b5c36;
P_0c0b5c36: /* original 902d, guest PC 0x0c0b5c36 */
if(!s->budget--) { s->failed_pc=0x0c0b5c36u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5c94u,2);
goto P_0c0b5c38;
P_0c0b5c38: /* original 4e0b, guest PC 0x0c0b5c38 */
if(!s->budget--) { s->failed_pc=0x0c0b5c38u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b5c3cu;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b5c3cu) { target=s->pc; goto dispatch; }
goto P_0c0b5c3c;
P_0c0b5c3a: /* original 05de, guest PC 0x0c0b5c3a */
if(!s->budget--) { s->failed_pc=0x0c0b5c3au; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b5c3c;
P_0c0b5c3c: /* original 942d, guest PC 0x0c0b5c3c */
if(!s->budget--) { s->failed_pc=0x0c0b5c3cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5c9au,2);
goto P_0c0b5c3e;
P_0c0b5c3e: /* original 902b, guest PC 0x0c0b5c3e */
if(!s->budget--) { s->failed_pc=0x0c0b5c3eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5c98u,2);
goto P_0c0b5c40;
P_0c0b5c40: /* original 4e0b, guest PC 0x0c0b5c40 */
if(!s->budget--) { s->failed_pc=0x0c0b5c40u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b5c44u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b5c44u) { target=s->pc; goto dispatch; }
goto P_0c0b5c44;
P_0c0b5c42: /* original 05de, guest PC 0x0c0b5c42 */
if(!s->budget--) { s->failed_pc=0x0c0b5c42u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b5c44;
P_0c0b5c44: /* original 942b, guest PC 0x0c0b5c44 */
if(!s->budget--) { s->failed_pc=0x0c0b5c44u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5c9eu,2);
goto P_0c0b5c46;
P_0c0b5c46: /* original 9029, guest PC 0x0c0b5c46 */
if(!s->budget--) { s->failed_pc=0x0c0b5c46u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5c9cu,2);
goto P_0c0b5c48;
P_0c0b5c48: /* original 4e0b, guest PC 0x0c0b5c48 */
if(!s->budget--) { s->failed_pc=0x0c0b5c48u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b5c4cu;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b5c4cu) { target=s->pc; goto dispatch; }
goto P_0c0b5c4c;
P_0c0b5c4a: /* original 05de, guest PC 0x0c0b5c4a */
if(!s->budget--) { s->failed_pc=0x0c0b5c4au; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b5c4c;
P_0c0b5c4c: /* original 9429, guest PC 0x0c0b5c4c */
if(!s->budget--) { s->failed_pc=0x0c0b5c4cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5ca2u,2);
goto P_0c0b5c4e;
P_0c0b5c4e: /* original 9027, guest PC 0x0c0b5c4e */
if(!s->budget--) { s->failed_pc=0x0c0b5c4eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5ca0u,2);
goto P_0c0b5c50;
P_0c0b5c50: /* original 4e0b, guest PC 0x0c0b5c50 */
if(!s->budget--) { s->failed_pc=0x0c0b5c50u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b5c54u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b5c54u) { target=s->pc; goto dispatch; }
goto P_0c0b5c54;
P_0c0b5c52: /* original 05de, guest PC 0x0c0b5c52 */
if(!s->budget--) { s->failed_pc=0x0c0b5c52u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b5c54;
P_0c0b5c54: /* original 9427, guest PC 0x0c0b5c54 */
if(!s->budget--) { s->failed_pc=0x0c0b5c54u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5ca6u,2);
goto P_0c0b5c56;
P_0c0b5c56: /* original 9025, guest PC 0x0c0b5c56 */
if(!s->budget--) { s->failed_pc=0x0c0b5c56u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5ca4u,2);
goto P_0c0b5c58;
P_0c0b5c58: /* original 4e0b, guest PC 0x0c0b5c58 */
if(!s->budget--) { s->failed_pc=0x0c0b5c58u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b5c5cu;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b5c5cu) { target=s->pc; goto dispatch; }
goto P_0c0b5c5c;
P_0c0b5c5a: /* original 05de, guest PC 0x0c0b5c5a */
if(!s->budget--) { s->failed_pc=0x0c0b5c5au; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b5c5c;
P_0c0b5c5c: /* original 9425, guest PC 0x0c0b5c5c */
if(!s->budget--) { s->failed_pc=0x0c0b5c5cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5caau,2);
goto P_0c0b5c5e;
P_0c0b5c5e: /* original 9023, guest PC 0x0c0b5c5e */
if(!s->budget--) { s->failed_pc=0x0c0b5c5eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5ca8u,2);
goto P_0c0b5c60;
P_0c0b5c60: /* original 4e0b, guest PC 0x0c0b5c60 */
if(!s->budget--) { s->failed_pc=0x0c0b5c60u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b5c64u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b5c64u) { target=s->pc; goto dispatch; }
goto P_0c0b5c64;
P_0c0b5c62: /* original 05de, guest PC 0x0c0b5c62 */
if(!s->budget--) { s->failed_pc=0x0c0b5c62u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b5c64;
P_0c0b5c64: /* original 9423, guest PC 0x0c0b5c64 */
if(!s->budget--) { s->failed_pc=0x0c0b5c64u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5caeu,2);
goto P_0c0b5c66;
P_0c0b5c66: /* original 9021, guest PC 0x0c0b5c66 */
if(!s->budget--) { s->failed_pc=0x0c0b5c66u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5cacu,2);
goto P_0c0b5c68;
P_0c0b5c68: /* original 4e0b, guest PC 0x0c0b5c68 */
if(!s->budget--) { s->failed_pc=0x0c0b5c68u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b5c6cu;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b5c6cu) { target=s->pc; goto dispatch; }
goto P_0c0b5c6c;
P_0c0b5c6a: /* original 05de, guest PC 0x0c0b5c6a */
if(!s->budget--) { s->failed_pc=0x0c0b5c6au; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b5c6c;
P_0c0b5c6c: /* original 9421, guest PC 0x0c0b5c6c */
if(!s->budget--) { s->failed_pc=0x0c0b5c6cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5cb2u,2);
goto P_0c0b5c6e;
P_0c0b5c6e: /* original 901f, guest PC 0x0c0b5c6e */
if(!s->budget--) { s->failed_pc=0x0c0b5c6eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5cb0u,2);
goto P_0c0b5c70;
P_0c0b5c70: /* original 4e0b, guest PC 0x0c0b5c70 */
if(!s->budget--) { s->failed_pc=0x0c0b5c70u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b5c74u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b5c74u) { target=s->pc; goto dispatch; }
goto P_0c0b5c74;
P_0c0b5c72: /* original 05de, guest PC 0x0c0b5c72 */
if(!s->budget--) { s->failed_pc=0x0c0b5c72u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b5c74;
P_0c0b5c74: /* original 941f, guest PC 0x0c0b5c74 */
if(!s->budget--) { s->failed_pc=0x0c0b5c74u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5cb6u,2);
goto P_0c0b5c76;
P_0c0b5c76: /* original 901d, guest PC 0x0c0b5c76 */
if(!s->budget--) { s->failed_pc=0x0c0b5c76u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5cb4u,2);
goto P_0c0b5c78;
P_0c0b5c78: /* original 4e0b, guest PC 0x0c0b5c78 */
if(!s->budget--) { s->failed_pc=0x0c0b5c78u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b5c7cu;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b5c7cu) { target=s->pc; goto dispatch; }
goto P_0c0b5c7c;
P_0c0b5c7a: /* original 05de, guest PC 0x0c0b5c7a */
if(!s->budget--) { s->failed_pc=0x0c0b5c7au; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b5c7c;
P_0c0b5c7c: /* original 7f08, guest PC 0x0c0b5c7c */
if(!s->budget--) { s->failed_pc=0x0c0b5c7cu; return 0; }
r[15]+=0x00000008u;
goto P_0c0b5c7e;
P_0c0b5c7e: /* original 4f26, guest PC 0x0c0b5c7e */
if(!s->budget--) { s->failed_pc=0x0c0b5c7eu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0b5c80;
P_0c0b5c80: /* original 69f6, guest PC 0x0c0b5c80 */
if(!s->budget--) { s->failed_pc=0x0c0b5c80u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0b5c82;
P_0c0b5c82: /* original 6af6, guest PC 0x0c0b5c82 */
if(!s->budget--) { s->failed_pc=0x0c0b5c82u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0b5c84;
P_0c0b5c84: /* original 6bf6, guest PC 0x0c0b5c84 */
if(!s->budget--) { s->failed_pc=0x0c0b5c84u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0b5c86;
P_0c0b5c86: /* original 6cf6, guest PC 0x0c0b5c86 */
if(!s->budget--) { s->failed_pc=0x0c0b5c86u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0b5c88;
P_0c0b5c88: /* original 6df6, guest PC 0x0c0b5c88 */
if(!s->budget--) { s->failed_pc=0x0c0b5c88u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0b5c8a;
P_0c0b5c8a: /* original 000b, guest PC 0x0c0b5c8a */
if(!s->budget--) { s->failed_pc=0x0c0b5c8au; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0b5c8c: /* original 6ef6, guest PC 0x0c0b5c8c */
if(!s->budget--) { s->failed_pc=0x0c0b5c8cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0b5c8eu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0b5c8eu; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
