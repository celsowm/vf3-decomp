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
int vf3_away_batch107_adapter_0(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c042c1eu: goto P_0c042c1e;
case 0x0c042c20u: goto P_0c042c20;
case 0x0c042c22u: goto P_0c042c22;
case 0x0c042c24u: goto P_0c042c24;
case 0x0c042c26u: goto P_0c042c26;
case 0x0c042c28u: goto P_0c042c28;
case 0x0c042c2au: goto P_0c042c2a;
case 0x0c042c2cu: goto P_0c042c2c;
case 0x0c042c2eu: goto P_0c042c2e;
case 0x0c042c30u: goto P_0c042c30;
case 0x0c042c32u: goto P_0c042c32;
case 0x0c042c34u: goto P_0c042c34;
case 0x0c042c36u: goto P_0c042c36;
case 0x0c042c38u: goto P_0c042c38;
case 0x0c042c3au: goto P_0c042c3a;
case 0x0c042c3cu: goto P_0c042c3c;
case 0x0c042c3eu: goto P_0c042c3e;
case 0x0c042c40u: goto P_0c042c40;
case 0x0c042c42u: goto P_0c042c42;
case 0x0c042c44u: goto P_0c042c44;
case 0x0c042c46u: goto P_0c042c46;
case 0x0c042c48u: goto P_0c042c48;
case 0x0c042c4au: goto P_0c042c4a;
case 0x0c042c4cu: goto P_0c042c4c;
case 0x0c042c4eu: goto P_0c042c4e;
case 0x0c042c50u: goto P_0c042c50;
case 0x0c042c52u: goto P_0c042c52;
case 0x0c042c54u: goto P_0c042c54;
case 0x0c042c56u: goto P_0c042c56;
case 0x0c042c58u: goto P_0c042c58;
case 0x0c042c5au: goto P_0c042c5a;
case 0x0c042c5cu: goto P_0c042c5c;
case 0x0c042c5eu: goto P_0c042c5e;
case 0x0c042c60u: goto P_0c042c60;
case 0x0c042c62u: goto P_0c042c62;
case 0x0c042c64u: goto P_0c042c64;
case 0x0c042c66u: goto P_0c042c66;
case 0x0c042c68u: goto P_0c042c68;
case 0x0c042c6au: goto P_0c042c6a;
case 0x0c042c6cu: goto P_0c042c6c;
case 0x0c042c6eu: goto P_0c042c6e;
case 0x0c042c70u: goto P_0c042c70;
case 0x0c042c72u: goto P_0c042c72;
case 0x0c042c74u: goto P_0c042c74;
case 0x0c042c76u: goto P_0c042c76;
case 0x0c042c78u: goto P_0c042c78;
case 0x0c042c7au: goto P_0c042c7a;
case 0x0c042c7cu: goto P_0c042c7c;
case 0x0c042c7eu: goto P_0c042c7e;
case 0x0c042c80u: goto P_0c042c80;
case 0x0c042c82u: goto P_0c042c82;
case 0x0c042c84u: goto P_0c042c84;
case 0x0c042c86u: goto P_0c042c86;
case 0x0c042c88u: goto P_0c042c88;
case 0x0c042c8au: goto P_0c042c8a;
case 0x0c042c8cu: goto P_0c042c8c;
case 0x0c042c8eu: goto P_0c042c8e;
case 0x0c042c90u: goto P_0c042c90;
case 0x0c042c92u: goto P_0c042c92;
case 0x0c042c94u: goto P_0c042c94;
case 0x0c042c96u: goto P_0c042c96;
case 0x0c042c98u: goto P_0c042c98;
case 0x0c042c9au: goto P_0c042c9a;
case 0x0c042c9cu: goto P_0c042c9c;
case 0x0c042c9eu: goto P_0c042c9e;
case 0x0c042ca0u: goto P_0c042ca0;
case 0x0c042ca2u: goto P_0c042ca2;
case 0x0c042ca4u: goto P_0c042ca4;
case 0x0c042ca6u: goto P_0c042ca6;
case 0x0c042ca8u: goto P_0c042ca8;
case 0x0c042caau: goto P_0c042caa;
case 0x0c042cacu: goto P_0c042cac;
case 0x0c042caeu: goto P_0c042cae;
case 0x0c042cb0u: goto P_0c042cb0;
case 0x0c042cb2u: goto P_0c042cb2;
case 0x0c042cb4u: goto P_0c042cb4;
case 0x0c042cb6u: goto P_0c042cb6;
case 0x0c042cb8u: goto P_0c042cb8;
case 0x0c042cbau: goto P_0c042cba;
case 0x0c042cbcu: goto P_0c042cbc;
case 0x0c042cbeu: goto P_0c042cbe;
case 0x0c042cc0u: goto P_0c042cc0;
case 0x0c042cc2u: goto P_0c042cc2;
case 0x0c042cc4u: goto P_0c042cc4;
case 0x0c042cc6u: goto P_0c042cc6;
case 0x0c042cc8u: goto P_0c042cc8;
case 0x0c042ccau: goto P_0c042cca;
case 0x0c091eb8u: goto P_0c091eb8;
case 0x0c091ebau: goto P_0c091eba;
case 0x0c091ebcu: goto P_0c091ebc;
case 0x0c091ebeu: goto P_0c091ebe;
case 0x0c091ec0u: goto P_0c091ec0;
case 0x0c091ec2u: goto P_0c091ec2;
case 0x0c091ec4u: goto P_0c091ec4;
case 0x0c091ec6u: goto P_0c091ec6;
case 0x0c091ec8u: goto P_0c091ec8;
case 0x0c091ecau: goto P_0c091eca;
case 0x0c091eccu: goto P_0c091ecc;
case 0x0c091eceu: goto P_0c091ece;
case 0x0c091ed0u: goto P_0c091ed0;
case 0x0c091ed2u: goto P_0c091ed2;
case 0x0c091ed4u: goto P_0c091ed4;
case 0x0c091ed6u: goto P_0c091ed6;
case 0x0c091ed8u: goto P_0c091ed8;
case 0x0c091edau: goto P_0c091eda;
case 0x0c091edcu: goto P_0c091edc;
case 0x0c091edeu: goto P_0c091ede;
case 0x0c091ee0u: goto P_0c091ee0;
case 0x0c091ee2u: goto P_0c091ee2;
case 0x0c091ee4u: goto P_0c091ee4;
case 0x0c091ee6u: goto P_0c091ee6;
case 0x0c091ee8u: goto P_0c091ee8;
case 0x0c091eeau: goto P_0c091eea;
case 0x0c091eecu: goto P_0c091eec;
case 0x0c091eeeu: goto P_0c091eee;
case 0x0c091ef0u: goto P_0c091ef0;
case 0x0c091ef2u: goto P_0c091ef2;
case 0x0c091ef4u: goto P_0c091ef4;
case 0x0c091ef6u: goto P_0c091ef6;
case 0x0c091ef8u: goto P_0c091ef8;
case 0x0c091efau: goto P_0c091efa;
case 0x0c091efcu: goto P_0c091efc;
case 0x0c091efeu: goto P_0c091efe;
case 0x0c091f00u: goto P_0c091f00;
case 0x0c091f02u: goto P_0c091f02;
case 0x0c091f04u: goto P_0c091f04;
case 0x0c091f06u: goto P_0c091f06;
case 0x0c091f08u: goto P_0c091f08;
case 0x0c091f0au: goto P_0c091f0a;
case 0x0c091f0cu: goto P_0c091f0c;
case 0x0c091f0eu: goto P_0c091f0e;
case 0x0c091f10u: goto P_0c091f10;
case 0x0c091f12u: goto P_0c091f12;
case 0x0c091f14u: goto P_0c091f14;
case 0x0c091f16u: goto P_0c091f16;
case 0x0c091f18u: goto P_0c091f18;
case 0x0c091f1au: goto P_0c091f1a;
case 0x0c091f1cu: goto P_0c091f1c;
case 0x0c091f1eu: goto P_0c091f1e;
case 0x0c091f20u: goto P_0c091f20;
case 0x0c091f22u: goto P_0c091f22;
case 0x0c091f24u: goto P_0c091f24;
case 0x0c091f26u: goto P_0c091f26;
case 0x0c091f28u: goto P_0c091f28;
case 0x0c091f2au: goto P_0c091f2a;
case 0x0c091f2cu: goto P_0c091f2c;
case 0x0c091f2eu: goto P_0c091f2e;
case 0x0c091f30u: goto P_0c091f30;
case 0x0c091f32u: goto P_0c091f32;
case 0x0c091f34u: goto P_0c091f34;
case 0x0c091f50u: goto P_0c091f50;
case 0x0c091f52u: goto P_0c091f52;
case 0x0c091f54u: goto P_0c091f54;
case 0x0c091f56u: goto P_0c091f56;
case 0x0c091f58u: goto P_0c091f58;
case 0x0c091f5au: goto P_0c091f5a;
case 0x0c091f5cu: goto P_0c091f5c;
case 0x0c091f5eu: goto P_0c091f5e;
case 0x0c091f60u: goto P_0c091f60;
case 0x0c091f62u: goto P_0c091f62;
case 0x0c091f64u: goto P_0c091f64;
case 0x0c091f66u: goto P_0c091f66;
case 0x0c091f68u: goto P_0c091f68;
case 0x0c091f6au: goto P_0c091f6a;
case 0x0c091f6cu: goto P_0c091f6c;
case 0x0c091f6eu: goto P_0c091f6e;
case 0x0c091f70u: goto P_0c091f70;
case 0x0c091f72u: goto P_0c091f72;
case 0x0c091f74u: goto P_0c091f74;
case 0x0c091f76u: goto P_0c091f76;
case 0x0c091f78u: goto P_0c091f78;
case 0x0c091f7au: goto P_0c091f7a;
case 0x0c091f7cu: goto P_0c091f7c;
case 0x0c091f7eu: goto P_0c091f7e;
case 0x0c091f80u: goto P_0c091f80;
case 0x0c091f82u: goto P_0c091f82;
case 0x0c091f84u: goto P_0c091f84;
case 0x0c091f86u: goto P_0c091f86;
case 0x0c091f88u: goto P_0c091f88;
case 0x0c091f8au: goto P_0c091f8a;
case 0x0c091f8cu: goto P_0c091f8c;
case 0x0c091f8eu: goto P_0c091f8e;
case 0x0c091f90u: goto P_0c091f90;
case 0x0c091f92u: goto P_0c091f92;
case 0x0c091f94u: goto P_0c091f94;
case 0x0c091f96u: goto P_0c091f96;
case 0x0c091f98u: goto P_0c091f98;
case 0x0c091f9au: goto P_0c091f9a;
case 0x0c091f9cu: goto P_0c091f9c;
case 0x0c091f9eu: goto P_0c091f9e;
case 0x0c091fa0u: goto P_0c091fa0;
case 0x0c091fa2u: goto P_0c091fa2;
case 0x0c091fa4u: goto P_0c091fa4;
case 0x0c091fa6u: goto P_0c091fa6;
case 0x0c091fa8u: goto P_0c091fa8;
case 0x0c091faau: goto P_0c091faa;
case 0x0c091facu: goto P_0c091fac;
case 0x0c091faeu: goto P_0c091fae;
case 0x0c091fb0u: goto P_0c091fb0;
case 0x0c091fb2u: goto P_0c091fb2;
case 0x0c091fb4u: goto P_0c091fb4;
case 0x0c091fb6u: goto P_0c091fb6;
case 0x0c091fb8u: goto P_0c091fb8;
case 0x0c091fbau: goto P_0c091fba;
case 0x0c091fbcu: goto P_0c091fbc;
case 0x0c091fbeu: goto P_0c091fbe;
case 0x0c091fc0u: goto P_0c091fc0;
case 0x0c091fc2u: goto P_0c091fc2;
case 0x0c091fc4u: goto P_0c091fc4;
case 0x0c091fc6u: goto P_0c091fc6;
case 0x0c091fc8u: goto P_0c091fc8;
case 0x0c091fcau: goto P_0c091fca;
case 0x0c091fccu: goto P_0c091fcc;
case 0x0c091fceu: goto P_0c091fce;
case 0x0c091fd0u: goto P_0c091fd0;
case 0x0c091fd2u: goto P_0c091fd2;
case 0x0c091fd4u: goto P_0c091fd4;
case 0x0c091fd6u: goto P_0c091fd6;
case 0x0c091fd8u: goto P_0c091fd8;
case 0x0c091fdau: goto P_0c091fda;
case 0x0c091fdcu: goto P_0c091fdc;
case 0x0c091fdeu: goto P_0c091fde;
case 0x0c091fe0u: goto P_0c091fe0;
case 0x0c091fe2u: goto P_0c091fe2;
case 0x0c091fe4u: goto P_0c091fe4;
case 0x0c091fe6u: goto P_0c091fe6;
case 0x0c091fe8u: goto P_0c091fe8;
case 0x0c091feau: goto P_0c091fea;
case 0x0c091fecu: goto P_0c091fec;
case 0x0c091feeu: goto P_0c091fee;
case 0x0c091ff0u: goto P_0c091ff0;
case 0x0c091ff2u: goto P_0c091ff2;
case 0x0c091ff4u: goto P_0c091ff4;
case 0x0c091ff6u: goto P_0c091ff6;
case 0x0c091ff8u: goto P_0c091ff8;
case 0x0c091ffau: goto P_0c091ffa;
case 0x0c091ffcu: goto P_0c091ffc;
case 0x0c091ffeu: goto P_0c091ffe;
case 0x0c092000u: goto P_0c092000;
case 0x0c092002u: goto P_0c092002;
case 0x0c092004u: goto P_0c092004;
case 0x0c092006u: goto P_0c092006;
case 0x0c092008u: goto P_0c092008;
case 0x0c09200au: goto P_0c09200a;
case 0x0c09200cu: goto P_0c09200c;
case 0x0c09200eu: goto P_0c09200e;
case 0x0c092010u: goto P_0c092010;
case 0x0c092012u: goto P_0c092012;
case 0x0c092014u: goto P_0c092014;
case 0x0c092016u: goto P_0c092016;
case 0x0c092018u: goto P_0c092018;
case 0x0c09201au: goto P_0c09201a;
case 0x0c09201cu: goto P_0c09201c;
case 0x0c09201eu: goto P_0c09201e;
case 0x0c092020u: goto P_0c092020;
case 0x0c092022u: goto P_0c092022;
case 0x0c092024u: goto P_0c092024;
case 0x0c092026u: goto P_0c092026;
case 0x0c092028u: goto P_0c092028;
case 0x0c092070u: goto P_0c092070;
case 0x0c092072u: goto P_0c092072;
case 0x0c092074u: goto P_0c092074;
case 0x0c092076u: goto P_0c092076;
case 0x0c092078u: goto P_0c092078;
case 0x0c09207au: goto P_0c09207a;
case 0x0c09207cu: goto P_0c09207c;
case 0x0c09207eu: goto P_0c09207e;
case 0x0c092080u: goto P_0c092080;
case 0x0c092082u: goto P_0c092082;
case 0x0c092084u: goto P_0c092084;
case 0x0c092086u: goto P_0c092086;
case 0x0c092088u: goto P_0c092088;
case 0x0c09208au: goto P_0c09208a;
case 0x0c09208cu: goto P_0c09208c;
case 0x0c09208eu: goto P_0c09208e;
case 0x0c092090u: goto P_0c092090;
case 0x0c092092u: goto P_0c092092;
case 0x0c092094u: goto P_0c092094;
case 0x0c092096u: goto P_0c092096;
case 0x0c092098u: goto P_0c092098;
case 0x0c09209au: goto P_0c09209a;
case 0x0c09209cu: goto P_0c09209c;
case 0x0c09209eu: goto P_0c09209e;
case 0x0c0920a0u: goto P_0c0920a0;
case 0x0c0920a2u: goto P_0c0920a2;
case 0x0c0920a4u: goto P_0c0920a4;
case 0x0c0920a6u: goto P_0c0920a6;
case 0x0c0920a8u: goto P_0c0920a8;
case 0x0c0920aau: goto P_0c0920aa;
case 0x0c0920acu: goto P_0c0920ac;
case 0x0c0920aeu: goto P_0c0920ae;
case 0x0c0920b0u: goto P_0c0920b0;
case 0x0c0920b2u: goto P_0c0920b2;
case 0x0c0920b4u: goto P_0c0920b4;
case 0x0c0920b6u: goto P_0c0920b6;
case 0x0c0920b8u: goto P_0c0920b8;
case 0x0c0920bau: goto P_0c0920ba;
case 0x0c0920bcu: goto P_0c0920bc;
case 0x0c0920beu: goto P_0c0920be;
case 0x0c0920c0u: goto P_0c0920c0;
case 0x0c0920c2u: goto P_0c0920c2;
case 0x0c0920c4u: goto P_0c0920c4;
case 0x0c0920c6u: goto P_0c0920c6;
case 0x0c0920c8u: goto P_0c0920c8;
case 0x0c0920cau: goto P_0c0920ca;
case 0x0c0920ccu: goto P_0c0920cc;
case 0x0c0920ceu: goto P_0c0920ce;
case 0x0c0920d0u: goto P_0c0920d0;
case 0x0c0920d2u: goto P_0c0920d2;
case 0x0c0920d4u: goto P_0c0920d4;
case 0x0c0920d6u: goto P_0c0920d6;
case 0x0c0920d8u: goto P_0c0920d8;
case 0x0c0920dau: goto P_0c0920da;
case 0x0c0920dcu: goto P_0c0920dc;
case 0x0c0920deu: goto P_0c0920de;
case 0x0c0920e0u: goto P_0c0920e0;
case 0x0c0920e2u: goto P_0c0920e2;
case 0x0c0920e4u: goto P_0c0920e4;
case 0x0c0920e6u: goto P_0c0920e6;
case 0x0c0920e8u: goto P_0c0920e8;
case 0x0c0920eau: goto P_0c0920ea;
case 0x0c0920ecu: goto P_0c0920ec;
case 0x0c0920eeu: goto P_0c0920ee;
case 0x0c0920f0u: goto P_0c0920f0;
case 0x0c0920f2u: goto P_0c0920f2;
case 0x0c0920f4u: goto P_0c0920f4;
case 0x0c0920f6u: goto P_0c0920f6;
case 0x0c0920f8u: goto P_0c0920f8;
case 0x0c0920fau: goto P_0c0920fa;
case 0x0c0920fcu: goto P_0c0920fc;
case 0x0c0920feu: goto P_0c0920fe;
case 0x0c092100u: goto P_0c092100;
case 0x0c092102u: goto P_0c092102;
case 0x0c092104u: goto P_0c092104;
case 0x0c092106u: goto P_0c092106;
case 0x0c092108u: goto P_0c092108;
case 0x0c09210au: goto P_0c09210a;
case 0x0c09210cu: goto P_0c09210c;
case 0x0c09210eu: goto P_0c09210e;
case 0x0c092110u: goto P_0c092110;
case 0x0c092112u: goto P_0c092112;
case 0x0c092114u: goto P_0c092114;
case 0x0c092116u: goto P_0c092116;
case 0x0c092118u: goto P_0c092118;
case 0x0c09211au: goto P_0c09211a;
case 0x0c09211cu: goto P_0c09211c;
case 0x0c09211eu: goto P_0c09211e;
case 0x0c092120u: goto P_0c092120;
case 0x0c092122u: goto P_0c092122;
case 0x0c092124u: goto P_0c092124;
case 0x0c092126u: goto P_0c092126;
case 0x0c092128u: goto P_0c092128;
case 0x0c09212au: goto P_0c09212a;
case 0x0c09212cu: goto P_0c09212c;
case 0x0c09212eu: goto P_0c09212e;
case 0x0c092130u: goto P_0c092130;
case 0x0c092132u: goto P_0c092132;
case 0x0c092134u: goto P_0c092134;
case 0x0c092136u: goto P_0c092136;
case 0x0c092138u: goto P_0c092138;
case 0x0c09213au: goto P_0c09213a;
case 0x0c09213cu: goto P_0c09213c;
case 0x0c09213eu: goto P_0c09213e;
case 0x0c092140u: goto P_0c092140;
case 0x0c092142u: goto P_0c092142;
case 0x0c092144u: goto P_0c092144;
case 0x0c092146u: goto P_0c092146;
case 0x0c092148u: goto P_0c092148;
case 0x0c09214au: goto P_0c09214a;
case 0x0c09214cu: goto P_0c09214c;
case 0x0c09214eu: goto P_0c09214e;
case 0x0c092150u: goto P_0c092150;
case 0x0c092152u: goto P_0c092152;
case 0x0c092154u: goto P_0c092154;
case 0x0c092156u: goto P_0c092156;
case 0x0c092158u: goto P_0c092158;
case 0x0c09215au: goto P_0c09215a;
case 0x0c092180u: goto P_0c092180;
case 0x0c092182u: goto P_0c092182;
case 0x0c092184u: goto P_0c092184;
case 0x0c092186u: goto P_0c092186;
case 0x0c092188u: goto P_0c092188;
case 0x0c09218au: goto P_0c09218a;
case 0x0c09218cu: goto P_0c09218c;
case 0x0c09218eu: goto P_0c09218e;
case 0x0c092190u: goto P_0c092190;
case 0x0c092192u: goto P_0c092192;
case 0x0c092194u: goto P_0c092194;
case 0x0c092196u: goto P_0c092196;
case 0x0c092198u: goto P_0c092198;
case 0x0c09219au: goto P_0c09219a;
case 0x0c09219cu: goto P_0c09219c;
case 0x0c09219eu: goto P_0c09219e;
case 0x0c0921a0u: goto P_0c0921a0;
case 0x0c0921a2u: goto P_0c0921a2;
case 0x0c0921a4u: goto P_0c0921a4;
case 0x0c0921a6u: goto P_0c0921a6;
case 0x0c0921a8u: goto P_0c0921a8;
case 0x0c0921aau: goto P_0c0921aa;
case 0x0c0921acu: goto P_0c0921ac;
case 0x0c0921aeu: goto P_0c0921ae;
case 0x0c0921b0u: goto P_0c0921b0;
case 0x0c0921b2u: goto P_0c0921b2;
case 0x0c0921b4u: goto P_0c0921b4;
case 0x0c0921b6u: goto P_0c0921b6;
case 0x0c0921b8u: goto P_0c0921b8;
case 0x0c0921bau: goto P_0c0921ba;
case 0x0c0921bcu: goto P_0c0921bc;
case 0x0c0921beu: goto P_0c0921be;
case 0x0c0921c0u: goto P_0c0921c0;
case 0x0c0921c2u: goto P_0c0921c2;
case 0x0c0921c4u: goto P_0c0921c4;
case 0x0c0921c6u: goto P_0c0921c6;
case 0x0c0921c8u: goto P_0c0921c8;
case 0x0c0921cau: goto P_0c0921ca;
case 0x0c0921ccu: goto P_0c0921cc;
case 0x0c0921ceu: goto P_0c0921ce;
case 0x0c0921d0u: goto P_0c0921d0;
case 0x0c0921d2u: goto P_0c0921d2;
case 0x0c0921d4u: goto P_0c0921d4;
case 0x0c0921d6u: goto P_0c0921d6;
case 0x0c0921d8u: goto P_0c0921d8;
case 0x0c0921dau: goto P_0c0921da;
case 0x0c0921dcu: goto P_0c0921dc;
case 0x0c0921deu: goto P_0c0921de;
case 0x0c0921e0u: goto P_0c0921e0;
case 0x0c0921e2u: goto P_0c0921e2;
case 0x0c0921e4u: goto P_0c0921e4;
case 0x0c0921e6u: goto P_0c0921e6;
case 0x0c0921e8u: goto P_0c0921e8;
case 0x0c0921eau: goto P_0c0921ea;
case 0x0c0921ecu: goto P_0c0921ec;
case 0x0c0921eeu: goto P_0c0921ee;
case 0x0c0921f0u: goto P_0c0921f0;
case 0x0c0921f2u: goto P_0c0921f2;
case 0x0c0921f4u: goto P_0c0921f4;
case 0x0c0921f6u: goto P_0c0921f6;
case 0x0c0921f8u: goto P_0c0921f8;
case 0x0c0921fau: goto P_0c0921fa;
case 0x0c0921fcu: goto P_0c0921fc;
case 0x0c0921feu: goto P_0c0921fe;
default: return vf3_matrix_family(target,s,ram);
}
P_0c042c1e: /* original 4f22, guest PC 0x0c042c1e */
if(!s->budget--) { s->failed_pc=0x0c042c1eu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c042c20;
P_0c042c20: /* original 2008, guest PC 0x0c042c20 */
if(!s->budget--) { s->failed_pc=0x0c042c20u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c042c22;
P_0c042c22: /* original 2f26, guest PC 0x0c042c22 */
if(!s->budget--) { s->failed_pc=0x0c042c22u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c042c24;
P_0c042c24: /* original 8d4c, guest PC 0x0c042c24 */
if(!s->budget--) { s->failed_pc=0x0c042c24u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c042cc0; }
goto P_0c042c28;
P_0c042c26: /* original 0009, guest PC 0x0c042c26 */
if(!s->budget--) { s->failed_pc=0x0c042c26u; return 0; }
goto P_0c042c28;
P_0c042c28: /* original 2f36, guest PC 0x0c042c28 */
if(!s->budget--) { s->failed_pc=0x0c042c28u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c042c2a;
P_0c042c2a: /* original e200, guest PC 0x0c042c2a */
if(!s->budget--) { s->failed_pc=0x0c042c2au; return 0; }
r[2]=0x00000000u;
goto P_0c042c2c;
P_0c042c2c: /* original 2127, guest PC 0x0c042c2c */
if(!s->budget--) { s->failed_pc=0x0c042c2cu; return 0; }
r[17]=(r[17]&~0x301u)|((r[1]>>31)<<8)|((r[2]>>31)<<9)|(((r[1]^r[2])>>31)&1u);
goto P_0c042c2e;
P_0c042c2e: /* original 333a, guest PC 0x0c042c2e */
if(!s->budget--) { s->failed_pc=0x0c042c2eu; return 0; }
wide=(uint64_t)r[3]-r[3]-(r[17]&1u); r[3]=(uint32_t)wide;
r[17]=(r[17]&~1u)|((wide>>32)!=0);
goto P_0c042c30;
P_0c042c30: /* original 312a, guest PC 0x0c042c30 */
if(!s->budget--) { s->failed_pc=0x0c042c30u; return 0; }
wide=(uint64_t)r[1]-r[2]-(r[17]&1u); r[1]=(uint32_t)wide;
r[17]=(r[17]&~1u)|((wide>>32)!=0);
goto P_0c042c32;
P_0c042c32: /* original 2307, guest PC 0x0c042c32 */
if(!s->budget--) { s->failed_pc=0x0c042c32u; return 0; }
r[17]=(r[17]&~0x301u)|((r[3]>>31)<<8)|((r[0]>>31)<<9)|(((r[3]^r[0])>>31)&1u);
goto P_0c042c34;
P_0c042c34: /* original 4124, guest PC 0x0c042c34 */
if(!s->budget--) { s->failed_pc=0x0c042c34u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c36;
P_0c042c36: /* original 3304, guest PC 0x0c042c36 */
if(!s->budget--) { s->failed_pc=0x0c042c36u; return 0; }
divide_step(s,3,0);
goto P_0c042c38;
P_0c042c38: /* original 4124, guest PC 0x0c042c38 */
if(!s->budget--) { s->failed_pc=0x0c042c38u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c3a;
P_0c042c3a: /* original 3304, guest PC 0x0c042c3a */
if(!s->budget--) { s->failed_pc=0x0c042c3au; return 0; }
divide_step(s,3,0);
goto P_0c042c3c;
P_0c042c3c: /* original 4124, guest PC 0x0c042c3c */
if(!s->budget--) { s->failed_pc=0x0c042c3cu; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c3e;
P_0c042c3e: /* original 3304, guest PC 0x0c042c3e */
if(!s->budget--) { s->failed_pc=0x0c042c3eu; return 0; }
divide_step(s,3,0);
goto P_0c042c40;
P_0c042c40: /* original 4124, guest PC 0x0c042c40 */
if(!s->budget--) { s->failed_pc=0x0c042c40u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c42;
P_0c042c42: /* original 3304, guest PC 0x0c042c42 */
if(!s->budget--) { s->failed_pc=0x0c042c42u; return 0; }
divide_step(s,3,0);
goto P_0c042c44;
P_0c042c44: /* original 4124, guest PC 0x0c042c44 */
if(!s->budget--) { s->failed_pc=0x0c042c44u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c46;
P_0c042c46: /* original 3304, guest PC 0x0c042c46 */
if(!s->budget--) { s->failed_pc=0x0c042c46u; return 0; }
divide_step(s,3,0);
goto P_0c042c48;
P_0c042c48: /* original 4124, guest PC 0x0c042c48 */
if(!s->budget--) { s->failed_pc=0x0c042c48u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c4a;
P_0c042c4a: /* original 3304, guest PC 0x0c042c4a */
if(!s->budget--) { s->failed_pc=0x0c042c4au; return 0; }
divide_step(s,3,0);
goto P_0c042c4c;
P_0c042c4c: /* original 4124, guest PC 0x0c042c4c */
if(!s->budget--) { s->failed_pc=0x0c042c4cu; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c4e;
P_0c042c4e: /* original 3304, guest PC 0x0c042c4e */
if(!s->budget--) { s->failed_pc=0x0c042c4eu; return 0; }
divide_step(s,3,0);
goto P_0c042c50;
P_0c042c50: /* original 4124, guest PC 0x0c042c50 */
if(!s->budget--) { s->failed_pc=0x0c042c50u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c52;
P_0c042c52: /* original 3304, guest PC 0x0c042c52 */
if(!s->budget--) { s->failed_pc=0x0c042c52u; return 0; }
divide_step(s,3,0);
goto P_0c042c54;
P_0c042c54: /* original 4124, guest PC 0x0c042c54 */
if(!s->budget--) { s->failed_pc=0x0c042c54u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c56;
P_0c042c56: /* original 3304, guest PC 0x0c042c56 */
if(!s->budget--) { s->failed_pc=0x0c042c56u; return 0; }
divide_step(s,3,0);
goto P_0c042c58;
P_0c042c58: /* original 4124, guest PC 0x0c042c58 */
if(!s->budget--) { s->failed_pc=0x0c042c58u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c5a;
P_0c042c5a: /* original 3304, guest PC 0x0c042c5a */
if(!s->budget--) { s->failed_pc=0x0c042c5au; return 0; }
divide_step(s,3,0);
goto P_0c042c5c;
P_0c042c5c: /* original 4124, guest PC 0x0c042c5c */
if(!s->budget--) { s->failed_pc=0x0c042c5cu; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c5e;
P_0c042c5e: /* original 3304, guest PC 0x0c042c5e */
if(!s->budget--) { s->failed_pc=0x0c042c5eu; return 0; }
divide_step(s,3,0);
goto P_0c042c60;
P_0c042c60: /* original 4124, guest PC 0x0c042c60 */
if(!s->budget--) { s->failed_pc=0x0c042c60u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c62;
P_0c042c62: /* original 3304, guest PC 0x0c042c62 */
if(!s->budget--) { s->failed_pc=0x0c042c62u; return 0; }
divide_step(s,3,0);
goto P_0c042c64;
P_0c042c64: /* original 4124, guest PC 0x0c042c64 */
if(!s->budget--) { s->failed_pc=0x0c042c64u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c66;
P_0c042c66: /* original 3304, guest PC 0x0c042c66 */
if(!s->budget--) { s->failed_pc=0x0c042c66u; return 0; }
divide_step(s,3,0);
goto P_0c042c68;
P_0c042c68: /* original 4124, guest PC 0x0c042c68 */
if(!s->budget--) { s->failed_pc=0x0c042c68u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c6a;
P_0c042c6a: /* original 3304, guest PC 0x0c042c6a */
if(!s->budget--) { s->failed_pc=0x0c042c6au; return 0; }
divide_step(s,3,0);
goto P_0c042c6c;
P_0c042c6c: /* original 4124, guest PC 0x0c042c6c */
if(!s->budget--) { s->failed_pc=0x0c042c6cu; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c6e;
P_0c042c6e: /* original 3304, guest PC 0x0c042c6e */
if(!s->budget--) { s->failed_pc=0x0c042c6eu; return 0; }
divide_step(s,3,0);
goto P_0c042c70;
P_0c042c70: /* original 4124, guest PC 0x0c042c70 */
if(!s->budget--) { s->failed_pc=0x0c042c70u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c72;
P_0c042c72: /* original 3304, guest PC 0x0c042c72 */
if(!s->budget--) { s->failed_pc=0x0c042c72u; return 0; }
divide_step(s,3,0);
goto P_0c042c74;
P_0c042c74: /* original 4124, guest PC 0x0c042c74 */
if(!s->budget--) { s->failed_pc=0x0c042c74u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c76;
P_0c042c76: /* original 3304, guest PC 0x0c042c76 */
if(!s->budget--) { s->failed_pc=0x0c042c76u; return 0; }
divide_step(s,3,0);
goto P_0c042c78;
P_0c042c78: /* original 4124, guest PC 0x0c042c78 */
if(!s->budget--) { s->failed_pc=0x0c042c78u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c7a;
P_0c042c7a: /* original 3304, guest PC 0x0c042c7a */
if(!s->budget--) { s->failed_pc=0x0c042c7au; return 0; }
divide_step(s,3,0);
goto P_0c042c7c;
P_0c042c7c: /* original 4124, guest PC 0x0c042c7c */
if(!s->budget--) { s->failed_pc=0x0c042c7cu; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c7e;
P_0c042c7e: /* original 3304, guest PC 0x0c042c7e */
if(!s->budget--) { s->failed_pc=0x0c042c7eu; return 0; }
divide_step(s,3,0);
goto P_0c042c80;
P_0c042c80: /* original 4124, guest PC 0x0c042c80 */
if(!s->budget--) { s->failed_pc=0x0c042c80u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c82;
P_0c042c82: /* original 3304, guest PC 0x0c042c82 */
if(!s->budget--) { s->failed_pc=0x0c042c82u; return 0; }
divide_step(s,3,0);
goto P_0c042c84;
P_0c042c84: /* original 4124, guest PC 0x0c042c84 */
if(!s->budget--) { s->failed_pc=0x0c042c84u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c86;
P_0c042c86: /* original 3304, guest PC 0x0c042c86 */
if(!s->budget--) { s->failed_pc=0x0c042c86u; return 0; }
divide_step(s,3,0);
goto P_0c042c88;
P_0c042c88: /* original 4124, guest PC 0x0c042c88 */
if(!s->budget--) { s->failed_pc=0x0c042c88u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c8a;
P_0c042c8a: /* original 3304, guest PC 0x0c042c8a */
if(!s->budget--) { s->failed_pc=0x0c042c8au; return 0; }
divide_step(s,3,0);
goto P_0c042c8c;
P_0c042c8c: /* original 4124, guest PC 0x0c042c8c */
if(!s->budget--) { s->failed_pc=0x0c042c8cu; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c8e;
P_0c042c8e: /* original 3304, guest PC 0x0c042c8e */
if(!s->budget--) { s->failed_pc=0x0c042c8eu; return 0; }
divide_step(s,3,0);
goto P_0c042c90;
P_0c042c90: /* original 4124, guest PC 0x0c042c90 */
if(!s->budget--) { s->failed_pc=0x0c042c90u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c92;
P_0c042c92: /* original 3304, guest PC 0x0c042c92 */
if(!s->budget--) { s->failed_pc=0x0c042c92u; return 0; }
divide_step(s,3,0);
goto P_0c042c94;
P_0c042c94: /* original 4124, guest PC 0x0c042c94 */
if(!s->budget--) { s->failed_pc=0x0c042c94u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c96;
P_0c042c96: /* original 3304, guest PC 0x0c042c96 */
if(!s->budget--) { s->failed_pc=0x0c042c96u; return 0; }
divide_step(s,3,0);
goto P_0c042c98;
P_0c042c98: /* original 4124, guest PC 0x0c042c98 */
if(!s->budget--) { s->failed_pc=0x0c042c98u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c9a;
P_0c042c9a: /* original 3304, guest PC 0x0c042c9a */
if(!s->budget--) { s->failed_pc=0x0c042c9au; return 0; }
divide_step(s,3,0);
goto P_0c042c9c;
P_0c042c9c: /* original 4124, guest PC 0x0c042c9c */
if(!s->budget--) { s->failed_pc=0x0c042c9cu; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c9e;
P_0c042c9e: /* original 3304, guest PC 0x0c042c9e */
if(!s->budget--) { s->failed_pc=0x0c042c9eu; return 0; }
divide_step(s,3,0);
goto P_0c042ca0;
P_0c042ca0: /* original 4124, guest PC 0x0c042ca0 */
if(!s->budget--) { s->failed_pc=0x0c042ca0u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042ca2;
P_0c042ca2: /* original 3304, guest PC 0x0c042ca2 */
if(!s->budget--) { s->failed_pc=0x0c042ca2u; return 0; }
divide_step(s,3,0);
goto P_0c042ca4;
P_0c042ca4: /* original 4124, guest PC 0x0c042ca4 */
if(!s->budget--) { s->failed_pc=0x0c042ca4u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042ca6;
P_0c042ca6: /* original 3304, guest PC 0x0c042ca6 */
if(!s->budget--) { s->failed_pc=0x0c042ca6u; return 0; }
divide_step(s,3,0);
goto P_0c042ca8;
P_0c042ca8: /* original 4124, guest PC 0x0c042ca8 */
if(!s->budget--) { s->failed_pc=0x0c042ca8u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042caa;
P_0c042caa: /* original 3304, guest PC 0x0c042caa */
if(!s->budget--) { s->failed_pc=0x0c042caau; return 0; }
divide_step(s,3,0);
goto P_0c042cac;
P_0c042cac: /* original 4124, guest PC 0x0c042cac */
if(!s->budget--) { s->failed_pc=0x0c042cacu; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042cae;
P_0c042cae: /* original 3304, guest PC 0x0c042cae */
if(!s->budget--) { s->failed_pc=0x0c042caeu; return 0; }
divide_step(s,3,0);
goto P_0c042cb0;
P_0c042cb0: /* original 4124, guest PC 0x0c042cb0 */
if(!s->budget--) { s->failed_pc=0x0c042cb0u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042cb2;
P_0c042cb2: /* original 3304, guest PC 0x0c042cb2 */
if(!s->budget--) { s->failed_pc=0x0c042cb2u; return 0; }
divide_step(s,3,0);
goto P_0c042cb4;
P_0c042cb4: /* original 4124, guest PC 0x0c042cb4 */
if(!s->budget--) { s->failed_pc=0x0c042cb4u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042cb6;
P_0c042cb6: /* original 312e, guest PC 0x0c042cb6 */
if(!s->budget--) { s->failed_pc=0x0c042cb6u; return 0; }
wide=(uint64_t)r[1]+r[2]+(r[17]&1u); r[1]=(uint32_t)wide;
r[17]=(r[17]&~1u)|((wide>>32)!=0);
goto P_0c042cb8;
P_0c042cb8: /* original 6013, guest PC 0x0c042cb8 */
if(!s->budget--) { s->failed_pc=0x0c042cb8u; return 0; }
r[0]=r[1];
goto P_0c042cba;
P_0c042cba: /* original 63f6, guest PC 0x0c042cba */
if(!s->budget--) { s->failed_pc=0x0c042cbau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[3]=tmp;
goto P_0c042cbc;
P_0c042cbc: /* original 000b, guest PC 0x0c042cbc */
if(!s->budget--) { s->failed_pc=0x0c042cbcu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[2]=tmp;
s->pc=target; return ram->oob==0;
P_0c042cbe: /* original 62f6, guest PC 0x0c042cbe */
if(!s->budget--) { s->failed_pc=0x0c042cbeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[2]=tmp;
goto P_0c042cc0;
P_0c042cc0: /* original d102, guest PC 0x0c042cc0 */
if(!s->budget--) { s->failed_pc=0x0c042cc0u; return 0; }
r[1]=read(ram,0x0c042cccu,4);
goto P_0c042cc2;
P_0c042cc2: /* original d203, guest PC 0x0c042cc2 */
if(!s->budget--) { s->failed_pc=0x0c042cc2u; return 0; }
r[2]=read(ram,0x0c042cd0u,4);
goto P_0c042cc4;
P_0c042cc4: /* original e000, guest PC 0x0c042cc4 */
if(!s->budget--) { s->failed_pc=0x0c042cc4u; return 0; }
r[0]=0x00000000u;
goto P_0c042cc6;
P_0c042cc6: /* original 2122, guest PC 0x0c042cc6 */
if(!s->budget--) { s->failed_pc=0x0c042cc6u; return 0; }
write(ram,r[1],r[2],4);
goto P_0c042cc8;
P_0c042cc8: /* original 000b, guest PC 0x0c042cc8 */
if(!s->budget--) { s->failed_pc=0x0c042cc8u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[2]=tmp;
s->pc=target; return ram->oob==0;
P_0c042cca: /* original 62f6, guest PC 0x0c042cca */
if(!s->budget--) { s->failed_pc=0x0c042ccau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[2]=tmp;
if(!vf3_matrix_family(0x0c042cccu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c042cccu; return 0; } return 1;
P_0c091eb8: /* original 2fd6, guest PC 0x0c091eb8 */
if(!s->budget--) { s->failed_pc=0x0c091eb8u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c091eba;
P_0c091eba: /* original 2fc6, guest PC 0x0c091eba */
if(!s->budget--) { s->failed_pc=0x0c091ebau; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c091ebc;
P_0c091ebc: /* original d123, guest PC 0x0c091ebc */
if(!s->budget--) { s->failed_pc=0x0c091ebcu; return 0; }
r[1]=read(ram,0x0c091f4cu,4);
goto P_0c091ebe;
P_0c091ebe: /* original 7ffc, guest PC 0x0c091ebe */
if(!s->budget--) { s->failed_pc=0x0c091ebeu; return 0; }
r[15]+=0xfffffffcu;
goto P_0c091ec0;
P_0c091ec0: /* original d321, guest PC 0x0c091ec0 */
if(!s->budget--) { s->failed_pc=0x0c091ec0u; return 0; }
r[3]=read(ram,0x0c091f48u,4);
goto P_0c091ec2;
P_0c091ec2: /* original 6212, guest PC 0x0c091ec2 */
if(!s->budget--) { s->failed_pc=0x0c091ec2u; return 0; }
tmp=read(ram,r[1],4);
r[2]=tmp;
goto P_0c091ec4;
P_0c091ec4: /* original 2238, guest PC 0x0c091ec4 */
if(!s->budget--) { s->failed_pc=0x0c091ec4u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c091ec6;
P_0c091ec6: /* original 8b32, guest PC 0x0c091ec6 */
if(!s->budget--) { s->failed_pc=0x0c091ec6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c091f2e; }
goto P_0c091ec8;
P_0c091ec8: /* original d61d, guest PC 0x0c091ec8 */
if(!s->budget--) { s->failed_pc=0x0c091ec8u; return 0; }
r[6]=read(ram,0x0c091f40u,4);
goto P_0c091eca;
P_0c091eca: /* original 6043, guest PC 0x0c091eca */
if(!s->budget--) { s->failed_pc=0x0c091ecau; return 0; }
r[0]=r[4];
goto P_0c091ecc;
P_0c091ecc: /* original 8801, guest PC 0x0c091ecc */
if(!s->budget--) { s->failed_pc=0x0c091eccu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c091ece;
P_0c091ece: /* original 5564, guest PC 0x0c091ece */
if(!s->budget--) { s->failed_pc=0x0c091eceu; return 0; }
r[5]=read(ram,r[6]+16,4);
goto P_0c091ed0;
P_0c091ed0: /* original 8d01, guest PC 0x0c091ed0 */
if(!s->budget--) { s->failed_pc=0x0c091ed0u; return 0; }
cond=r[17]&1u;
r[6]=read(ram,r[6]+20,4);
if(cond) { goto P_0c091ed6; }
goto P_0c091ed4;
P_0c091ed2: /* original 5665, guest PC 0x0c091ed2 */
if(!s->budget--) { s->failed_pc=0x0c091ed2u; return 0; }
r[6]=read(ram,r[6]+20,4);
goto P_0c091ed4;
P_0c091ed4: /* original 6563, guest PC 0x0c091ed4 */
if(!s->budget--) { s->failed_pc=0x0c091ed4u; return 0; }
r[5]=r[6];
goto P_0c091ed6;
P_0c091ed6: /* original 8454, guest PC 0x0c091ed6 */
if(!s->budget--) { s->failed_pc=0x0c091ed6u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[5]+4,1);
goto P_0c091ed8;
P_0c091ed8: /* original d61a, guest PC 0x0c091ed8 */
if(!s->budget--) { s->failed_pc=0x0c091ed8u; return 0; }
r[6]=read(ram,0x0c091f44u,4);
goto P_0c091eda;
P_0c091eda: /* original 600c, guest PC 0x0c091eda */
if(!s->budget--) { s->failed_pc=0x0c091edau; return 0; }
r[0]=r[0]&255u;
goto P_0c091edc;
P_0c091edc: /* original 6303, guest PC 0x0c091edc */
if(!s->budget--) { s->failed_pc=0x0c091edcu; return 0; }
r[3]=r[0];
goto P_0c091ede;
P_0c091ede: /* original 4000, guest PC 0x0c091ede */
if(!s->budget--) { s->failed_pc=0x0c091edeu; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c091ee0;
P_0c091ee0: /* original 303c, guest PC 0x0c091ee0 */
if(!s->budget--) { s->failed_pc=0x0c091ee0u; return 0; }
r[0]+=r[3];
goto P_0c091ee2;
P_0c091ee2: /* original 4008, guest PC 0x0c091ee2 */
if(!s->budget--) { s->failed_pc=0x0c091ee2u; return 0; }
r[0]<<=2;
goto P_0c091ee4;
P_0c091ee4: /* original 4008, guest PC 0x0c091ee4 */
if(!s->budget--) { s->failed_pc=0x0c091ee4u; return 0; }
r[0]<<=2;
goto P_0c091ee6;
P_0c091ee6: /* original 4000, guest PC 0x0c091ee6 */
if(!s->budget--) { s->failed_pc=0x0c091ee6u; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c091ee8;
P_0c091ee8: /* original 360c, guest PC 0x0c091ee8 */
if(!s->budget--) { s->failed_pc=0x0c091ee8u; return 0; }
r[6]+=r[0];
goto P_0c091eea;
P_0c091eea: /* original 9026, guest PC 0x0c091eea */
if(!s->budget--) { s->failed_pc=0x0c091eeau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c091f3au,2);
goto P_0c091eec;
P_0c091eec: /* original 6d63, guest PC 0x0c091eec */
if(!s->budget--) { s->failed_pc=0x0c091eecu; return 0; }
r[13]=r[6];
goto P_0c091eee;
P_0c091eee: /* original 7d20, guest PC 0x0c091eee */
if(!s->budget--) { s->failed_pc=0x0c091eeeu; return 0; }
r[13]+=0x00000020u;
goto P_0c091ef0;
P_0c091ef0: /* original 045d, guest PC 0x0c091ef0 */
if(!s->budget--) { s->failed_pc=0x0c091ef0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[5]+r[0],2);
goto P_0c091ef2;
P_0c091ef2: /* original 9023, guest PC 0x0c091ef2 */
if(!s->budget--) { s->failed_pc=0x0c091ef2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c091f3cu,2);
goto P_0c091ef4;
P_0c091ef4: /* original 6743, guest PC 0x0c091ef4 */
if(!s->budget--) { s->failed_pc=0x0c091ef4u; return 0; }
r[7]=r[4];
goto P_0c091ef6;
P_0c091ef6: /* original 0545, guest PC 0x0c091ef6 */
if(!s->budget--) { s->failed_pc=0x0c091ef6u; return 0; }
write(ram,r[5]+r[0],r[4],2);
goto P_0c091ef8;
P_0c091ef8: /* original 9021, guest PC 0x0c091ef8 */
if(!s->budget--) { s->failed_pc=0x0c091ef8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c091f3eu,2);
goto P_0c091efa;
P_0c091efa: /* original 0c5c, guest PC 0x0c091efa */
if(!s->budget--) { s->failed_pc=0x0c091efau; return 0; }
r[12]=(uint32_t)(int32_t)(int8_t)read(ram,r[5]+r[0],1);
goto P_0c091efc;
P_0c091efc: /* original 6063, guest PC 0x0c091efc */
if(!s->budget--) { s->failed_pc=0x0c091efcu; return 0; }
r[0]=r[6];
goto P_0c091efe;
P_0c091efe: /* original 034c, guest PC 0x0c091efe */
if(!s->budget--) { s->failed_pc=0x0c091efeu; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c091f00;
P_0c091f00: /* original 6073, guest PC 0x0c091f00 */
if(!s->budget--) { s->failed_pc=0x0c091f00u; return 0; }
r[0]=r[7];
goto P_0c091f02;
P_0c091f02: /* original 4000, guest PC 0x0c091f02 */
if(!s->budget--) { s->failed_pc=0x0c091f02u; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c091f04;
P_0c091f04: /* original 633c, guest PC 0x0c091f04 */
if(!s->budget--) { s->failed_pc=0x0c091f04u; return 0; }
r[3]=r[3]&255u;
goto P_0c091f06;
P_0c091f06: /* original 2f31, guest PC 0x0c091f06 */
if(!s->budget--) { s->failed_pc=0x0c091f06u; return 0; }
write(ram,r[15],r[3],2);
goto P_0c091f08;
P_0c091f08: /* original 6ccc, guest PC 0x0c091f08 */
if(!s->budget--) { s->failed_pc=0x0c091f08u; return 0; }
r[12]=r[12]&255u;
goto P_0c091f0a;
P_0c091f0a: /* original 633d, guest PC 0x0c091f0a */
if(!s->budget--) { s->failed_pc=0x0c091f0au; return 0; }
r[3]=r[3]&65535u;
goto P_0c091f0c;
P_0c091f0c: /* original 01dd, guest PC 0x0c091f0c */
if(!s->budget--) { s->failed_pc=0x0c091f0cu; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,r[13]+r[0],2);
goto P_0c091f0e;
P_0c091f0e: /* original 62cd, guest PC 0x0c091f0e */
if(!s->budget--) { s->failed_pc=0x0c091f0eu; return 0; }
r[2]=r[12]&65535u;
goto P_0c091f10;
P_0c091f10: /* original 3230, guest PC 0x0c091f10 */
if(!s->budget--) { s->failed_pc=0x0c091f10u; return 0; }
r[17]=(r[17]&~1u)|((r[2]==r[3])!=0);
goto P_0c091f12;
P_0c091f12: /* original 8d09, guest PC 0x0c091f12 */
if(!s->budget--) { s->failed_pc=0x0c091f12u; return 0; }
cond=r[17]&1u;
r[1]+=0x00000001u;
if(cond) { goto P_0c091f28; }
goto P_0c091f16;
P_0c091f14: /* original 7101, guest PC 0x0c091f14 */
if(!s->budget--) { s->failed_pc=0x0c091f14u; return 0; }
r[1]+=0x00000001u;
goto P_0c091f16;
P_0c091f16: /* original 9010, guest PC 0x0c091f16 */
if(!s->budget--) { s->failed_pc=0x0c091f16u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c091f3au,2);
goto P_0c091f18;
P_0c091f18: /* original e31f, guest PC 0x0c091f18 */
if(!s->budget--) { s->failed_pc=0x0c091f18u; return 0; }
r[3]=0x0000001fu;
goto P_0c091f1a;
P_0c091f1a: /* original 7401, guest PC 0x0c091f1a */
if(!s->budget--) { s->failed_pc=0x0c091f1au; return 0; }
r[4]+=0x00000001u;
goto P_0c091f1c;
P_0c091f1c: /* original 2439, guest PC 0x0c091f1c */
if(!s->budget--) { s->failed_pc=0x0c091f1cu; return 0; }
r[4]&=r[3];
goto P_0c091f1e;
P_0c091f1e: /* original 0545, guest PC 0x0c091f1e */
if(!s->budget--) { s->failed_pc=0x0c091f1eu; return 0; }
write(ram,r[5]+r[0],r[4],2);
goto P_0c091f20;
P_0c091f20: /* original 6063, guest PC 0x0c091f20 */
if(!s->budget--) { s->failed_pc=0x0c091f20u; return 0; }
r[0]=r[6];
goto P_0c091f22;
P_0c091f22: /* original 04c4, guest PC 0x0c091f22 */
if(!s->budget--) { s->failed_pc=0x0c091f22u; return 0; }
write(ram,r[4]+r[0],r[12],1);
goto P_0c091f24;
P_0c091f24: /* original 6743, guest PC 0x0c091f24 */
if(!s->budget--) { s->failed_pc=0x0c091f24u; return 0; }
r[7]=r[4];
goto P_0c091f26;
P_0c091f26: /* original e101, guest PC 0x0c091f26 */
if(!s->budget--) { s->failed_pc=0x0c091f26u; return 0; }
r[1]=0x00000001u;
goto P_0c091f28;
P_0c091f28: /* original 6073, guest PC 0x0c091f28 */
if(!s->budget--) { s->failed_pc=0x0c091f28u; return 0; }
r[0]=r[7];
goto P_0c091f2a;
P_0c091f2a: /* original 4000, guest PC 0x0c091f2a */
if(!s->budget--) { s->failed_pc=0x0c091f2au; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c091f2c;
P_0c091f2c: /* original 0d15, guest PC 0x0c091f2c */
if(!s->budget--) { s->failed_pc=0x0c091f2cu; return 0; }
write(ram,r[13]+r[0],r[1],2);
goto P_0c091f2e;
P_0c091f2e: /* original 7f04, guest PC 0x0c091f2e */
if(!s->budget--) { s->failed_pc=0x0c091f2eu; return 0; }
r[15]+=0x00000004u;
goto P_0c091f30;
P_0c091f30: /* original 6cf6, guest PC 0x0c091f30 */
if(!s->budget--) { s->failed_pc=0x0c091f30u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c091f32;
P_0c091f32: /* original 000b, guest PC 0x0c091f32 */
if(!s->budget--) { s->failed_pc=0x0c091f32u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
s->pc=target; return ram->oob==0;
P_0c091f34: /* original 6df6, guest PC 0x0c091f34 */
if(!s->budget--) { s->failed_pc=0x0c091f34u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
if(!vf3_matrix_family(0x0c091f36u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c091f36u; return 0; } return 1;
P_0c091f50: /* original 2fe6, guest PC 0x0c091f50 */
if(!s->budget--) { s->failed_pc=0x0c091f50u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c091f52;
P_0c091f52: /* original 2fd6, guest PC 0x0c091f52 */
if(!s->budget--) { s->failed_pc=0x0c091f52u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c091f54;
P_0c091f54: /* original 2fc6, guest PC 0x0c091f54 */
if(!s->budget--) { s->failed_pc=0x0c091f54u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c091f56;
P_0c091f56: /* original 2fb6, guest PC 0x0c091f56 */
if(!s->budget--) { s->failed_pc=0x0c091f56u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c091f58;
P_0c091f58: /* original 2fa6, guest PC 0x0c091f58 */
if(!s->budget--) { s->failed_pc=0x0c091f58u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c091f5a;
P_0c091f5a: /* original 2f96, guest PC 0x0c091f5a */
if(!s->budget--) { s->failed_pc=0x0c091f5au; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c091f5c;
P_0c091f5c: /* original 2f86, guest PC 0x0c091f5c */
if(!s->budget--) { s->failed_pc=0x0c091f5cu; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c091f5e;
P_0c091f5e: /* original e80f, guest PC 0x0c091f5e */
if(!s->budget--) { s->failed_pc=0x0c091f5eu; return 0; }
r[8]=0x0000000fu;
goto P_0c091f60;
P_0c091f60: /* original 4f22, guest PC 0x0c091f60 */
if(!s->budget--) { s->failed_pc=0x0c091f60u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c091f62;
P_0c091f62: /* original d138, guest PC 0x0c091f62 */
if(!s->budget--) { s->failed_pc=0x0c091f62u; return 0; }
r[1]=read(ram,0x0c092044u,4);
goto P_0c091f64;
P_0c091f64: /* original d336, guest PC 0x0c091f64 */
if(!s->budget--) { s->failed_pc=0x0c091f64u; return 0; }
r[3]=read(ram,0x0c092040u,4);
goto P_0c091f66;
P_0c091f66: /* original 4f12, guest PC 0x0c091f66 */
if(!s->budget--) { s->failed_pc=0x0c091f66u; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c091f68;
P_0c091f68: /* original 6212, guest PC 0x0c091f68 */
if(!s->budget--) { s->failed_pc=0x0c091f68u; return 0; }
tmp=read(ram,r[1],4);
r[2]=tmp;
goto P_0c091f6a;
P_0c091f6a: /* original de34, guest PC 0x0c091f6a */
if(!s->budget--) { s->failed_pc=0x0c091f6au; return 0; }
r[14]=read(ram,0x0c09203cu,4);
goto P_0c091f6c;
P_0c091f6c: /* original d931, guest PC 0x0c091f6c */
if(!s->budget--) { s->failed_pc=0x0c091f6cu; return 0; }
r[9]=read(ram,0x0c092034u,4);
goto P_0c091f6e;
P_0c091f6e: /* original 2238, guest PC 0x0c091f6e */
if(!s->budget--) { s->failed_pc=0x0c091f6eu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c091f70;
P_0c091f70: /* original dc31, guest PC 0x0c091f70 */
if(!s->budget--) { s->failed_pc=0x0c091f70u; return 0; }
r[12]=read(ram,0x0c092038u,4);
goto P_0c091f72;
P_0c091f72: /* original 7ff4, guest PC 0x0c091f72 */
if(!s->budget--) { s->failed_pc=0x0c091f72u; return 0; }
r[15]+=0xfffffff4u;
goto P_0c091f74;
P_0c091f74: /* original 8d02, guest PC 0x0c091f74 */
if(!s->budget--) { s->failed_pc=0x0c091f74u; return 0; }
cond=r[17]&1u;
r[13]=0x00000000u;
if(cond) { goto P_0c091f7c; }
goto P_0c091f78;
P_0c091f76: /* original ed00, guest PC 0x0c091f76 */
if(!s->budget--) { s->failed_pc=0x0c091f76u; return 0; }
r[13]=0x00000000u;
goto P_0c091f78;
P_0c091f78: /* original a137, guest PC 0x0c091f78 */
if(!s->budget--) { s->failed_pc=0x0c091f78u; return 0; }
goto P_0c0921ea;
P_0c091f7a: /* original 0009, guest PC 0x0c091f7a */
if(!s->budget--) { s->failed_pc=0x0c091f7au; return 0; }
goto P_0c091f7c;
P_0c091f7c: /* original d632, guest PC 0x0c091f7c */
if(!s->budget--) { s->failed_pc=0x0c091f7cu; return 0; }
r[6]=read(ram,0x0c092048u,4);
goto P_0c091f7e;
P_0c091f7e: /* original 6043, guest PC 0x0c091f7e */
if(!s->budget--) { s->failed_pc=0x0c091f7eu; return 0; }
r[0]=r[4];
goto P_0c091f80;
P_0c091f80: /* original 8801, guest PC 0x0c091f80 */
if(!s->budget--) { s->failed_pc=0x0c091f80u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c091f82;
P_0c091f82: /* original 5564, guest PC 0x0c091f82 */
if(!s->budget--) { s->failed_pc=0x0c091f82u; return 0; }
r[5]=read(ram,r[6]+16,4);
goto P_0c091f84;
P_0c091f84: /* original 8d01, guest PC 0x0c091f84 */
if(!s->budget--) { s->failed_pc=0x0c091f84u; return 0; }
cond=r[17]&1u;
r[6]=read(ram,r[6]+20,4);
if(cond) { goto P_0c091f8a; }
goto P_0c091f88;
P_0c091f86: /* original 5665, guest PC 0x0c091f86 */
if(!s->budget--) { s->failed_pc=0x0c091f86u; return 0; }
r[6]=read(ram,r[6]+20,4);
goto P_0c091f88;
P_0c091f88: /* original 6563, guest PC 0x0c091f88 */
if(!s->budget--) { s->failed_pc=0x0c091f88u; return 0; }
r[5]=r[6];
goto P_0c091f8a;
P_0c091f8a: /* original 8454, guest PC 0x0c091f8a */
if(!s->budget--) { s->failed_pc=0x0c091f8au; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[5]+4,1);
goto P_0c091f8c;
P_0c091f8c: /* original da2f, guest PC 0x0c091f8c */
if(!s->budget--) { s->failed_pc=0x0c091f8cu; return 0; }
r[10]=read(ram,0x0c09204cu,4);
goto P_0c091f8e;
P_0c091f8e: /* original 640c, guest PC 0x0c091f8e */
if(!s->budget--) { s->failed_pc=0x0c091f8eu; return 0; }
r[4]=r[0]&255u;
goto P_0c091f90;
P_0c091f90: /* original 6343, guest PC 0x0c091f90 */
if(!s->budget--) { s->failed_pc=0x0c091f90u; return 0; }
r[3]=r[4];
goto P_0c091f92;
P_0c091f92: /* original 4300, guest PC 0x0c091f92 */
if(!s->budget--) { s->failed_pc=0x0c091f92u; return 0; }
r[17]=(r[17]&~1u)|((r[3]>>31)!=0);
r[3]<<=1;
goto P_0c091f94;
P_0c091f94: /* original 6243, guest PC 0x0c091f94 */
if(!s->budget--) { s->failed_pc=0x0c091f94u; return 0; }
r[2]=r[4];
goto P_0c091f96;
P_0c091f96: /* original 332c, guest PC 0x0c091f96 */
if(!s->budget--) { s->failed_pc=0x0c091f96u; return 0; }
r[3]+=r[2];
goto P_0c091f98;
P_0c091f98: /* original 4308, guest PC 0x0c091f98 */
if(!s->budget--) { s->failed_pc=0x0c091f98u; return 0; }
r[3]<<=2;
goto P_0c091f9a;
P_0c091f9a: /* original 6b43, guest PC 0x0c091f9a */
if(!s->budget--) { s->failed_pc=0x0c091f9au; return 0; }
r[11]=r[4];
goto P_0c091f9c;
P_0c091f9c: /* original 4308, guest PC 0x0c091f9c */
if(!s->budget--) { s->failed_pc=0x0c091f9cu; return 0; }
r[3]<<=2;
goto P_0c091f9e;
P_0c091f9e: /* original 4300, guest PC 0x0c091f9e */
if(!s->budget--) { s->failed_pc=0x0c091f9eu; return 0; }
r[17]=(r[17]&~1u)|((r[3]>>31)!=0);
r[3]<<=1;
goto P_0c091fa0;
P_0c091fa0: /* original 3a3c, guest PC 0x0c091fa0 */
if(!s->budget--) { s->failed_pc=0x0c091fa0u; return 0; }
r[10]+=r[3];
goto P_0c091fa2;
P_0c091fa2: /* original 63a3, guest PC 0x0c091fa2 */
if(!s->budget--) { s->failed_pc=0x0c091fa2u; return 0; }
r[3]=r[10];
goto P_0c091fa4;
P_0c091fa4: /* original 7320, guest PC 0x0c091fa4 */
if(!s->budget--) { s->failed_pc=0x0c091fa4u; return 0; }
r[3]+=0x00000020u;
goto P_0c091fa6;
P_0c091fa6: /* original 1f32, guest PC 0x0c091fa6 */
if(!s->budget--) { s->failed_pc=0x0c091fa6u; return 0; }
write(ram,r[15]+8,r[3],4);
goto P_0c091fa8;
P_0c091fa8: /* original e32a, guest PC 0x0c091fa8 */
if(!s->budget--) { s->failed_pc=0x0c091fa8u; return 0; }
r[3]=0x0000002au;
goto P_0c091faa;
P_0c091faa: /* original 903e, guest PC 0x0c091faa */
if(!s->budget--) { s->failed_pc=0x0c091faau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09202au,2);
goto P_0c091fac;
P_0c091fac: /* original 0b37, guest PC 0x0c091fac */
if(!s->budget--) { s->failed_pc=0x0c091facu; return 0; }
r[19]=r[11]*r[3];
goto P_0c091fae;
P_0c091fae: /* original 025d, guest PC 0x0c091fae */
if(!s->budget--) { s->failed_pc=0x0c091faeu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[5]+r[0],2);
goto P_0c091fb0;
P_0c091fb0: /* original 2f22, guest PC 0x0c091fb0 */
if(!s->budget--) { s->failed_pc=0x0c091fb0u; return 0; }
write(ram,r[15],r[2],4);
goto P_0c091fb2;
P_0c091fb2: /* original 903b, guest PC 0x0c091fb2 */
if(!s->budget--) { s->failed_pc=0x0c091fb2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09202cu,2);
goto P_0c091fb4;
P_0c091fb4: /* original 0b1a, guest PC 0x0c091fb4 */
if(!s->budget--) { s->failed_pc=0x0c091fb4u; return 0; }
r[11]=r[19];
goto P_0c091fb6;
P_0c091fb6: /* original 045d, guest PC 0x0c091fb6 */
if(!s->budget--) { s->failed_pc=0x0c091fb6u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[5]+r[0],2);
goto P_0c091fb8;
P_0c091fb8: /* original d125, guest PC 0x0c091fb8 */
if(!s->budget--) { s->failed_pc=0x0c091fb8u; return 0; }
r[1]=read(ram,0x0c092050u,4);
goto P_0c091fba;
P_0c091fba: /* original 3248, guest PC 0x0c091fba */
if(!s->budget--) { s->failed_pc=0x0c091fbau; return 0; }
r[2]-=r[4];
goto P_0c091fbc;
P_0c091fbc: /* original 6612, guest PC 0x0c091fbc */
if(!s->budget--) { s->failed_pc=0x0c091fbcu; return 0; }
tmp=read(ram,r[1],4);
r[6]=tmp;
goto P_0c091fbe;
P_0c091fbe: /* original 6423, guest PC 0x0c091fbe */
if(!s->budget--) { s->failed_pc=0x0c091fbeu; return 0; }
r[4]=r[2];
goto P_0c091fc0;
P_0c091fc0: /* original e204, guest PC 0x0c091fc0 */
if(!s->budget--) { s->failed_pc=0x0c091fc0u; return 0; }
r[2]=0x00000004u;
goto P_0c091fc2;
P_0c091fc2: /* original 7b02, guest PC 0x0c091fc2 */
if(!s->budget--) { s->failed_pc=0x0c091fc2u; return 0; }
r[11]+=0x00000002u;
goto P_0c091fc4;
P_0c091fc4: /* original 2628, guest PC 0x0c091fc4 */
if(!s->budget--) { s->failed_pc=0x0c091fc4u; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[2])==0)!=0);
goto P_0c091fc6;
P_0c091fc6: /* original 65b3, guest PC 0x0c091fc6 */
if(!s->budget--) { s->failed_pc=0x0c091fc6u; return 0; }
r[5]=r[11];
goto P_0c091fc8;
P_0c091fc8: /* original 8d20, guest PC 0x0c091fc8 */
if(!s->budget--) { s->failed_pc=0x0c091fc8u; return 0; }
cond=r[17]&1u;
r[5]+=0xffffffd4u;
if(cond) { goto P_0c09200c; }
goto P_0c091fcc;
P_0c091fca: /* original 75d4, guest PC 0x0c091fca */
if(!s->budget--) { s->failed_pc=0x0c091fcau; return 0; }
r[5]+=0xffffffd4u;
goto P_0c091fcc;
P_0c091fcc: /* original 2558, guest PC 0x0c091fcc */
if(!s->budget--) { s->failed_pc=0x0c091fccu; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[5])==0)!=0);
goto P_0c091fce;
P_0c091fce: /* original 890c, guest PC 0x0c091fce */
if(!s->budget--) { s->failed_pc=0x0c091fceu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c091fea; }
goto P_0c091fd0;
P_0c091fd0: /* original 2448, guest PC 0x0c091fd0 */
if(!s->budget--) { s->failed_pc=0x0c091fd0u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c091fd2;
P_0c091fd2: /* original 895c, guest PC 0x0c091fd2 */
if(!s->budget--) { s->failed_pc=0x0c091fd2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09208e; }
goto P_0c091fd4;
P_0c091fd4: /* original e320, guest PC 0x0c091fd4 */
if(!s->budget--) { s->failed_pc=0x0c091fd4u; return 0; }
r[3]=0x00000020u;
goto P_0c091fd6;
P_0c091fd6: /* original e610, guest PC 0x0c091fd6 */
if(!s->budget--) { s->failed_pc=0x0c091fd6u; return 0; }
r[6]=0x00000010u;
goto P_0c091fd8;
P_0c091fd8: /* original 2f36, guest PC 0x0c091fd8 */
if(!s->budget--) { s->failed_pc=0x0c091fd8u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c091fda;
P_0c091fda: /* original 9528, guest PC 0x0c091fda */
if(!s->budget--) { s->failed_pc=0x0c091fdau; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09202eu,2);
goto P_0c091fdc;
P_0c091fdc: /* original e702, guest PC 0x0c091fdc */
if(!s->budget--) { s->failed_pc=0x0c091fdcu; return 0; }
r[7]=0x00000002u;
goto P_0c091fde;
P_0c091fde: /* original 490b, guest PC 0x0c091fde */
if(!s->budget--) { s->failed_pc=0x0c091fdeu; return 0; }
target=r[9];
r[16]=code_base|0x0c091fe2u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c091fe2u) { target=s->pc; goto dispatch; }
goto P_0c091fe2;
P_0c091fe0: /* original 64e3, guest PC 0x0c091fe0 */
if(!s->budget--) { s->failed_pc=0x0c091fe0u; return 0; }
r[4]=r[14];
goto P_0c091fe2;
P_0c091fe2: /* original d51d, guest PC 0x0c091fe2 */
if(!s->budget--) { s->failed_pc=0x0c091fe2u; return 0; }
r[5]=read(ram,0x0c092058u,4);
goto P_0c091fe4;
P_0c091fe4: /* original d61b, guest PC 0x0c091fe4 */
if(!s->budget--) { s->failed_pc=0x0c091fe4u; return 0; }
r[6]=read(ram,0x0c092054u,4);
goto P_0c091fe6;
P_0c091fe6: /* original a04f, guest PC 0x0c091fe6 */
if(!s->budget--) { s->failed_pc=0x0c091fe6u; return 0; }
r[15]+=0x00000004u;
goto P_0c092088;
P_0c091fe8: /* original 7f04, guest PC 0x0c091fe8 */
if(!s->budget--) { s->failed_pc=0x0c091fe8u; return 0; }
r[15]+=0x00000004u;
goto P_0c091fea;
P_0c091fea: /* original 2448, guest PC 0x0c091fea */
if(!s->budget--) { s->failed_pc=0x0c091feau; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c091fec;
P_0c091fec: /* original 894f, guest PC 0x0c091fec */
if(!s->budget--) { s->failed_pc=0x0c091fecu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09208e; }
goto P_0c091fee;
P_0c091fee: /* original e320, guest PC 0x0c091fee */
if(!s->budget--) { s->failed_pc=0x0c091feeu; return 0; }
r[3]=0x00000020u;
goto P_0c091ff0;
P_0c091ff0: /* original e610, guest PC 0x0c091ff0 */
if(!s->budget--) { s->failed_pc=0x0c091ff0u; return 0; }
r[6]=0x00000010u;
goto P_0c091ff2;
P_0c091ff2: /* original 2f36, guest PC 0x0c091ff2 */
if(!s->budget--) { s->failed_pc=0x0c091ff2u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c091ff4;
P_0c091ff4: /* original 951c, guest PC 0x0c091ff4 */
if(!s->budget--) { s->failed_pc=0x0c091ff4u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c092030u,2);
goto P_0c091ff6;
P_0c091ff6: /* original e702, guest PC 0x0c091ff6 */
if(!s->budget--) { s->failed_pc=0x0c091ff6u; return 0; }
r[7]=0x00000002u;
goto P_0c091ff8;
P_0c091ff8: /* original 490b, guest PC 0x0c091ff8 */
if(!s->budget--) { s->failed_pc=0x0c091ff8u; return 0; }
target=r[9];
r[16]=code_base|0x0c091ffcu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c091ffcu) { target=s->pc; goto dispatch; }
goto P_0c091ffc;
P_0c091ffa: /* original 64e3, guest PC 0x0c091ffa */
if(!s->budget--) { s->failed_pc=0x0c091ffau; return 0; }
r[4]=r[14];
goto P_0c091ffc;
P_0c091ffc: /* original d518, guest PC 0x0c091ffc */
if(!s->budget--) { s->failed_pc=0x0c091ffcu; return 0; }
r[5]=read(ram,0x0c092060u,4);
goto P_0c091ffe;
P_0c091ffe: /* original 7f04, guest PC 0x0c091ffe */
if(!s->budget--) { s->failed_pc=0x0c091ffeu; return 0; }
r[15]+=0x00000004u;
goto P_0c092000;
P_0c092000: /* original d616, guest PC 0x0c092000 */
if(!s->budget--) { s->failed_pc=0x0c092000u; return 0; }
r[6]=read(ram,0x0c09205cu,4);
goto P_0c092002;
P_0c092002: /* original d218, guest PC 0x0c092002 */
if(!s->budget--) { s->failed_pc=0x0c092002u; return 0; }
r[2]=read(ram,0x0c092064u,4);
goto P_0c092004;
P_0c092004: /* original 420b, guest PC 0x0c092004 */
if(!s->budget--) { s->failed_pc=0x0c092004u; return 0; }
target=r[2];
r[16]=code_base|0x0c092008u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c092008u) { target=s->pc; goto dispatch; }
goto P_0c092008;
P_0c092006: /* original 64e3, guest PC 0x0c092006 */
if(!s->budget--) { s->failed_pc=0x0c092006u; return 0; }
r[4]=r[14];
goto P_0c092008;
P_0c092008: /* original a041, guest PC 0x0c092008 */
if(!s->budget--) { s->failed_pc=0x0c092008u; return 0; }
goto P_0c09208e;
P_0c09200a: /* original 0009, guest PC 0x0c09200a */
if(!s->budget--) { s->failed_pc=0x0c09200au; return 0; }
goto P_0c09200c;
P_0c09200c: /* original 2558, guest PC 0x0c09200c */
if(!s->budget--) { s->failed_pc=0x0c09200cu; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[5])==0)!=0);
goto P_0c09200e;
P_0c09200e: /* original 892f, guest PC 0x0c09200e */
if(!s->budget--) { s->failed_pc=0x0c09200eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c092070; }
goto P_0c092010;
P_0c092010: /* original 2448, guest PC 0x0c092010 */
if(!s->budget--) { s->failed_pc=0x0c092010u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c092012;
P_0c092012: /* original 893c, guest PC 0x0c092012 */
if(!s->budget--) { s->failed_pc=0x0c092012u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09208e; }
goto P_0c092014;
P_0c092014: /* original e320, guest PC 0x0c092014 */
if(!s->budget--) { s->failed_pc=0x0c092014u; return 0; }
r[3]=0x00000020u;
goto P_0c092016;
P_0c092016: /* original e610, guest PC 0x0c092016 */
if(!s->budget--) { s->failed_pc=0x0c092016u; return 0; }
r[6]=0x00000010u;
goto P_0c092018;
P_0c092018: /* original 2f36, guest PC 0x0c092018 */
if(!s->budget--) { s->failed_pc=0x0c092018u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09201a;
P_0c09201a: /* original 950a, guest PC 0x0c09201a */
if(!s->budget--) { s->failed_pc=0x0c09201au; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c092032u,2);
goto P_0c09201c;
P_0c09201c: /* original e702, guest PC 0x0c09201c */
if(!s->budget--) { s->failed_pc=0x0c09201cu; return 0; }
r[7]=0x00000002u;
goto P_0c09201e;
P_0c09201e: /* original 490b, guest PC 0x0c09201e */
if(!s->budget--) { s->failed_pc=0x0c09201eu; return 0; }
target=r[9];
r[16]=code_base|0x0c092022u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c092022u) { target=s->pc; goto dispatch; }
goto P_0c092022;
P_0c092020: /* original 64e3, guest PC 0x0c092020 */
if(!s->budget--) { s->failed_pc=0x0c092020u; return 0; }
r[4]=r[14];
goto P_0c092022;
P_0c092022: /* original d512, guest PC 0x0c092022 */
if(!s->budget--) { s->failed_pc=0x0c092022u; return 0; }
r[5]=read(ram,0x0c09206cu,4);
goto P_0c092024;
P_0c092024: /* original d610, guest PC 0x0c092024 */
if(!s->budget--) { s->failed_pc=0x0c092024u; return 0; }
r[6]=read(ram,0x0c092068u,4);
goto P_0c092026;
P_0c092026: /* original afec, guest PC 0x0c092026 */
if(!s->budget--) { s->failed_pc=0x0c092026u; return 0; }
r[15]+=0x00000004u;
goto P_0c092002;
P_0c092028: /* original 7f04, guest PC 0x0c092028 */
if(!s->budget--) { s->failed_pc=0x0c092028u; return 0; }
r[15]+=0x00000004u;
if(!vf3_matrix_family(0x0c09202au,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c09202au; return 0; } return 1;
P_0c092070: /* original 2448, guest PC 0x0c092070 */
if(!s->budget--) { s->failed_pc=0x0c092070u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c092072;
P_0c092072: /* original 890c, guest PC 0x0c092072 */
if(!s->budget--) { s->failed_pc=0x0c092072u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09208e; }
goto P_0c092074;
P_0c092074: /* original e320, guest PC 0x0c092074 */
if(!s->budget--) { s->failed_pc=0x0c092074u; return 0; }
r[3]=0x00000020u;
goto P_0c092076;
P_0c092076: /* original e610, guest PC 0x0c092076 */
if(!s->budget--) { s->failed_pc=0x0c092076u; return 0; }
r[6]=0x00000010u;
goto P_0c092078;
P_0c092078: /* original 2f36, guest PC 0x0c092078 */
if(!s->budget--) { s->failed_pc=0x0c092078u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09207a;
P_0c09207a: /* original 956f, guest PC 0x0c09207a */
if(!s->budget--) { s->failed_pc=0x0c09207au; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09215cu,2);
goto P_0c09207c;
P_0c09207c: /* original e702, guest PC 0x0c09207c */
if(!s->budget--) { s->failed_pc=0x0c09207cu; return 0; }
r[7]=0x00000002u;
goto P_0c09207e;
P_0c09207e: /* original 490b, guest PC 0x0c09207e */
if(!s->budget--) { s->failed_pc=0x0c09207eu; return 0; }
target=r[9];
r[16]=code_base|0x0c092082u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c092082u) { target=s->pc; goto dispatch; }
goto P_0c092082;
P_0c092080: /* original 64e3, guest PC 0x0c092080 */
if(!s->budget--) { s->failed_pc=0x0c092080u; return 0; }
r[4]=r[14];
goto P_0c092082;
P_0c092082: /* original d53a, guest PC 0x0c092082 */
if(!s->budget--) { s->failed_pc=0x0c092082u; return 0; }
r[5]=read(ram,0x0c09216cu,4);
goto P_0c092084;
P_0c092084: /* original 7f04, guest PC 0x0c092084 */
if(!s->budget--) { s->failed_pc=0x0c092084u; return 0; }
r[15]+=0x00000004u;
goto P_0c092086;
P_0c092086: /* original d638, guest PC 0x0c092086 */
if(!s->budget--) { s->failed_pc=0x0c092086u; return 0; }
r[6]=read(ram,0x0c092168u,4);
goto P_0c092088;
P_0c092088: /* original d239, guest PC 0x0c092088 */
if(!s->budget--) { s->failed_pc=0x0c092088u; return 0; }
r[2]=read(ram,0x0c092170u,4);
goto P_0c09208a;
P_0c09208a: /* original 420b, guest PC 0x0c09208a */
if(!s->budget--) { s->failed_pc=0x0c09208au; return 0; }
target=r[2];
r[16]=code_base|0x0c09208eu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09208eu) { target=s->pc; goto dispatch; }
goto P_0c09208e;
P_0c09208c: /* original 64e3, guest PC 0x0c09208c */
if(!s->budget--) { s->failed_pc=0x0c09208cu; return 0; }
r[4]=r[14];
goto P_0c09208e;
P_0c09208e: /* original 9266, guest PC 0x0c09208e */
if(!s->budget--) { s->failed_pc=0x0c09208eu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09215eu,2);
goto P_0c092090;
P_0c092090: /* original 4b00, guest PC 0x0c092090 */
if(!s->budget--) { s->failed_pc=0x0c092090u; return 0; }
r[17]=(r[17]&~1u)|((r[11]>>31)!=0);
r[11]<<=1;
goto P_0c092092;
P_0c092092: /* original e320, guest PC 0x0c092092 */
if(!s->budget--) { s->failed_pc=0x0c092092u; return 0; }
r[3]=0x00000020u;
goto P_0c092094;
P_0c092094: /* original 2b2b, guest PC 0x0c092094 */
if(!s->budget--) { s->failed_pc=0x0c092094u; return 0; }
r[11]|=r[2];
goto P_0c092096;
P_0c092096: /* original 1fb1, guest PC 0x0c092096 */
if(!s->budget--) { s->failed_pc=0x0c092096u; return 0; }
write(ram,r[15]+4,r[11],4);
goto P_0c092098;
P_0c092098: /* original e60a, guest PC 0x0c092098 */
if(!s->budget--) { s->failed_pc=0x0c092098u; return 0; }
r[6]=0x0000000au;
goto P_0c09209a;
P_0c09209a: /* original 2f36, guest PC 0x0c09209a */
if(!s->budget--) { s->failed_pc=0x0c09209au; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09209c;
P_0c09209c: /* original e702, guest PC 0x0c09209c */
if(!s->budget--) { s->failed_pc=0x0c09209cu; return 0; }
r[7]=0x00000002u;
goto P_0c09209e;
P_0c09209e: /* original 55f2, guest PC 0x0c09209e */
if(!s->budget--) { s->failed_pc=0x0c09209eu; return 0; }
r[5]=read(ram,r[15]+8,4);
goto P_0c0920a0;
P_0c0920a0: /* original 490b, guest PC 0x0c0920a0 */
if(!s->budget--) { s->failed_pc=0x0c0920a0u; return 0; }
target=r[9];
r[16]=code_base|0x0c0920a4u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0920a4u) { target=s->pc; goto dispatch; }
goto P_0c0920a4;
P_0c0920a2: /* original 64e3, guest PC 0x0c0920a2 */
if(!s->budget--) { s->failed_pc=0x0c0920a2u; return 0; }
r[4]=r[14];
goto P_0c0920a4;
P_0c0920a4: /* original 7f04, guest PC 0x0c0920a4 */
if(!s->budget--) { s->failed_pc=0x0c0920a4u; return 0; }
r[15]+=0x00000004u;
goto P_0c0920a6;
P_0c0920a6: /* original 60f2, guest PC 0x0c0920a6 */
if(!s->budget--) { s->failed_pc=0x0c0920a6u; return 0; }
tmp=read(ram,r[15],4);
r[0]=tmp;
goto P_0c0920a8;
P_0c0920a8: /* original e2fc, guest PC 0x0c0920a8 */
if(!s->budget--) { s->failed_pc=0x0c0920a8u; return 0; }
r[2]=0xfffffffcu;
goto P_0c0920aa;
P_0c0920aa: /* original c91f, guest PC 0x0c0920aa */
if(!s->budget--) { s->failed_pc=0x0c0920aau; return 0; }
r[0]&=31u;
goto P_0c0920ac;
P_0c0920ac: /* original 2f02, guest PC 0x0c0920ac */
if(!s->budget--) { s->failed_pc=0x0c0920acu; return 0; }
write(ram,r[15],r[0],4);
goto P_0c0920ae;
P_0c0920ae: /* original 53f2, guest PC 0x0c0920ae */
if(!s->budget--) { s->failed_pc=0x0c0920aeu; return 0; }
r[3]=read(ram,r[15]+8,4);
goto P_0c0920b0;
P_0c0920b0: /* original 05ac, guest PC 0x0c0920b0 */
if(!s->budget--) { s->failed_pc=0x0c0920b0u; return 0; }
r[5]=(uint32_t)(int32_t)(int8_t)read(ram,r[10]+r[0],1);
goto P_0c0920b2;
P_0c0920b2: /* original 4000, guest PC 0x0c0920b2 */
if(!s->budget--) { s->failed_pc=0x0c0920b2u; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c0920b4;
P_0c0920b4: /* original 003d, guest PC 0x0c0920b4 */
if(!s->budget--) { s->failed_pc=0x0c0920b4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[3]+r[0],2);
goto P_0c0920b6;
P_0c0920b6: /* original 655c, guest PC 0x0c0920b6 */
if(!s->budget--) { s->failed_pc=0x0c0920b6u; return 0; }
r[5]=r[5]&255u;
goto P_0c0920b8;
P_0c0920b8: /* original 675d, guest PC 0x0c0920b8 */
if(!s->budget--) { s->failed_pc=0x0c0920b8u; return 0; }
r[7]=r[5]&65535u;
goto P_0c0920ba;
P_0c0920ba: /* original 81f4, guest PC 0x0c0920ba */
if(!s->budget--) { s->failed_pc=0x0c0920bau; return 0; }
write(ram,r[15]+8,r[0],2);
goto P_0c0920bc;
P_0c0920bc: /* original 5bf1, guest PC 0x0c0920bc */
if(!s->budget--) { s->failed_pc=0x0c0920bcu; return 0; }
r[11]=read(ram,r[15]+4,4);
goto P_0c0920be;
P_0c0920be: /* original 2f72, guest PC 0x0c0920be */
if(!s->budget--) { s->failed_pc=0x0c0920beu; return 0; }
write(ram,r[15],r[7],4);
goto P_0c0920c0;
P_0c0920c0: /* original 472c, guest PC 0x0c0920c0 */
if(!s->budget--) { s->failed_pc=0x0c0920c0u; return 0; }
r[7]=(r[2]&0x80000000u)?((r[2]&31u)?(uint32_t)((int32_t)r[7]>>((-r[2])&31u)):((int32_t)r[7]<0?0xffffffffu:0)):r[7]<<(r[2]&31u);
goto P_0c0920c2;
P_0c0920c2: /* original d02c, guest PC 0x0c0920c2 */
if(!s->budget--) { s->failed_pc=0x0c0920c2u; return 0; }
r[0]=read(ram,0x0c092174u,4);
goto P_0c0920c4;
P_0c0920c4: /* original 2789, guest PC 0x0c0920c4 */
if(!s->budget--) { s->failed_pc=0x0c0920c4u; return 0; }
r[7]&=r[8];
goto P_0c0920c6;
P_0c0920c6: /* original 924b, guest PC 0x0c0920c6 */
if(!s->budget--) { s->failed_pc=0x0c0920c6u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c092160u,2);
goto P_0c0920c8;
P_0c0920c8: /* original 077c, guest PC 0x0c0920c8 */
if(!s->budget--) { s->failed_pc=0x0c0920c8u; return 0; }
r[7]=(uint32_t)(int32_t)(int8_t)read(ram,r[7]+r[0],1);
goto P_0c0920ca;
P_0c0920ca: /* original 9a4a, guest PC 0x0c0920ca */
if(!s->budget--) { s->failed_pc=0x0c0920cau; return 0; }
r[10]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c092162u,2);
goto P_0c0920cc;
P_0c0920cc: /* original 4728, guest PC 0x0c0920cc */
if(!s->budget--) { s->failed_pc=0x0c0920ccu; return 0; }
r[7]<<=16;
goto P_0c0920ce;
P_0c0920ce: /* original 4718, guest PC 0x0c0920ce */
if(!s->budget--) { s->failed_pc=0x0c0920ceu; return 0; }
r[7]<<=8;
goto P_0c0920d0;
P_0c0920d0: /* original 6473, guest PC 0x0c0920d0 */
if(!s->budget--) { s->failed_pc=0x0c0920d0u; return 0; }
r[4]=r[7];
goto P_0c0920d2;
P_0c0920d2: /* original 2448, guest PC 0x0c0920d2 */
if(!s->budget--) { s->failed_pc=0x0c0920d2u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c0920d4;
P_0c0920d4: /* original 8d06, guest PC 0x0c0920d4 */
if(!s->budget--) { s->failed_pc=0x0c0920d4u; return 0; }
cond=r[17]&1u;
r[7]|=r[2];
if(cond) { goto P_0c0920e4; }
goto P_0c0920d8;
P_0c0920d6: /* original 272b, guest PC 0x0c0920d6 */
if(!s->budget--) { s->failed_pc=0x0c0920d6u; return 0; }
r[7]|=r[2];
goto P_0c0920d8;
P_0c0920d8: /* original 65a3, guest PC 0x0c0920d8 */
if(!s->budget--) { s->failed_pc=0x0c0920d8u; return 0; }
r[5]=r[10];
goto P_0c0920da;
P_0c0920da: /* original 66e3, guest PC 0x0c0920da */
if(!s->budget--) { s->failed_pc=0x0c0920dau; return 0; }
r[6]=r[14];
goto P_0c0920dc;
P_0c0920dc: /* original 2fd6, guest PC 0x0c0920dc */
if(!s->budget--) { s->failed_pc=0x0c0920dcu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0920de;
P_0c0920de: /* original 4c0b, guest PC 0x0c0920de */
if(!s->budget--) { s->failed_pc=0x0c0920deu; return 0; }
target=r[12];
r[16]=code_base|0x0c0920e2u;
r[4]=r[11];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0920e2u) { target=s->pc; goto dispatch; }
goto P_0c0920e2;
P_0c0920e0: /* original 64b3, guest PC 0x0c0920e0 */
if(!s->budget--) { s->failed_pc=0x0c0920e0u; return 0; }
r[4]=r[11];
goto P_0c0920e2;
P_0c0920e2: /* original 7f04, guest PC 0x0c0920e2 */
if(!s->budget--) { s->failed_pc=0x0c0920e2u; return 0; }
r[15]+=0x00000004u;
goto P_0c0920e4;
P_0c0920e4: /* original 60f2, guest PC 0x0c0920e4 */
if(!s->budget--) { s->failed_pc=0x0c0920e4u; return 0; }
tmp=read(ram,r[15],4);
r[0]=tmp;
goto P_0c0920e6;
P_0c0920e6: /* original e478, guest PC 0x0c0920e6 */
if(!s->budget--) { s->failed_pc=0x0c0920e6u; return 0; }
r[4]=0x00000078u;
goto P_0c0920e8;
P_0c0920e8: /* original d323, guest PC 0x0c0920e8 */
if(!s->budget--) { s->failed_pc=0x0c0920e8u; return 0; }
r[3]=read(ram,0x0c092178u,4);
goto P_0c0920ea;
P_0c0920ea: /* original e204, guest PC 0x0c0920ea */
if(!s->budget--) { s->failed_pc=0x0c0920eau; return 0; }
r[2]=0x00000004u;
goto P_0c0920ec;
P_0c0920ec: /* original 4008, guest PC 0x0c0920ec */
if(!s->budget--) { s->failed_pc=0x0c0920ecu; return 0; }
r[0]<<=2;
goto P_0c0920ee;
P_0c0920ee: /* original 4000, guest PC 0x0c0920ee */
if(!s->budget--) { s->failed_pc=0x0c0920eeu; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c0920f0;
P_0c0920f0: /* original 2409, guest PC 0x0c0920f0 */
if(!s->budget--) { s->failed_pc=0x0c0920f0u; return 0; }
r[4]&=r[0];
goto P_0c0920f2;
P_0c0920f2: /* original 4421, guest PC 0x0c0920f2 */
if(!s->budget--) { s->failed_pc=0x0c0920f2u; return 0; }
r[17]=(r[17]&~1u)|((r[4]&1)!=0);
r[4]=(uint32_t)((int32_t)r[4]>>1);
goto P_0c0920f4;
P_0c0920f4: /* original 4400, guest PC 0x0c0920f4 */
if(!s->budget--) { s->failed_pc=0x0c0920f4u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c0920f6;
P_0c0920f6: /* original 343c, guest PC 0x0c0920f6 */
if(!s->budget--) { s->failed_pc=0x0c0920f6u; return 0; }
r[4]+=r[3];
goto P_0c0920f8;
P_0c0920f8: /* original 1f41, guest PC 0x0c0920f8 */
if(!s->budget--) { s->failed_pc=0x0c0920f8u; return 0; }
write(ram,r[15]+4,r[4],4);
goto P_0c0920fa;
P_0c0920fa: /* original a015, guest PC 0x0c0920fa */
if(!s->budget--) { s->failed_pc=0x0c0920fau; return 0; }
write(ram,r[15],r[2],4);
goto P_0c092128;
P_0c0920fc: /* original 2f22, guest PC 0x0c0920fc */
if(!s->budget--) { s->failed_pc=0x0c0920fcu; return 0; }
write(ram,r[15],r[2],4);
goto P_0c0920fe;
P_0c0920fe: /* original 57f1, guest PC 0x0c0920fe */
if(!s->budget--) { s->failed_pc=0x0c0920feu; return 0; }
r[7]=read(ram,r[15]+4,4);
goto P_0c092100;
P_0c092100: /* original 6b43, guest PC 0x0c092100 */
if(!s->budget--) { s->failed_pc=0x0c092100u; return 0; }
r[11]=r[4];
goto P_0c092102;
P_0c092102: /* original 7702, guest PC 0x0c092102 */
if(!s->budget--) { s->failed_pc=0x0c092102u; return 0; }
r[7]+=0x00000002u;
goto P_0c092104;
P_0c092104: /* original 1f71, guest PC 0x0c092104 */
if(!s->budget--) { s->failed_pc=0x0c092104u; return 0; }
write(ram,r[15]+4,r[7],4);
goto P_0c092106;
P_0c092106: /* original 77fe, guest PC 0x0c092106 */
if(!s->budget--) { s->failed_pc=0x0c092106u; return 0; }
r[7]+=0xfffffffeu;
goto P_0c092108;
P_0c092108: /* original 6771, guest PC 0x0c092108 */
if(!s->budget--) { s->failed_pc=0x0c092108u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[7],2);
r[7]=tmp;
goto P_0c09210a;
P_0c09210a: /* original 9329, guest PC 0x0c09210a */
if(!s->budget--) { s->failed_pc=0x0c09210au; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c092160u,2);
goto P_0c09210c;
P_0c09210c: /* original 4728, guest PC 0x0c09210c */
if(!s->budget--) { s->failed_pc=0x0c09210cu; return 0; }
r[7]<<=16;
goto P_0c09210e;
P_0c09210e: /* original 6473, guest PC 0x0c09210e */
if(!s->budget--) { s->failed_pc=0x0c09210eu; return 0; }
r[4]=r[7];
goto P_0c092110;
P_0c092110: /* original 2448, guest PC 0x0c092110 */
if(!s->budget--) { s->failed_pc=0x0c092110u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c092112;
P_0c092112: /* original 8d06, guest PC 0x0c092112 */
if(!s->budget--) { s->failed_pc=0x0c092112u; return 0; }
cond=r[17]&1u;
r[7]|=r[3];
if(cond) { goto P_0c092122; }
goto P_0c092116;
P_0c092114: /* original 273b, guest PC 0x0c092114 */
if(!s->budget--) { s->failed_pc=0x0c092114u; return 0; }
r[7]|=r[3];
goto P_0c092116;
P_0c092116: /* original 65a3, guest PC 0x0c092116 */
if(!s->budget--) { s->failed_pc=0x0c092116u; return 0; }
r[5]=r[10];
goto P_0c092118;
P_0c092118: /* original 66e3, guest PC 0x0c092118 */
if(!s->budget--) { s->failed_pc=0x0c092118u; return 0; }
r[6]=r[14];
goto P_0c09211a;
P_0c09211a: /* original 2fd6, guest PC 0x0c09211a */
if(!s->budget--) { s->failed_pc=0x0c09211au; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09211c;
P_0c09211c: /* original 4c0b, guest PC 0x0c09211c */
if(!s->budget--) { s->failed_pc=0x0c09211cu; return 0; }
target=r[12];
r[16]=code_base|0x0c092120u;
r[4]=r[11];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c092120u) { target=s->pc; goto dispatch; }
goto P_0c092120;
P_0c09211e: /* original 64b3, guest PC 0x0c09211e */
if(!s->budget--) { s->failed_pc=0x0c09211eu; return 0; }
r[4]=r[11];
goto P_0c092120;
P_0c092120: /* original 7f04, guest PC 0x0c092120 */
if(!s->budget--) { s->failed_pc=0x0c092120u; return 0; }
r[15]+=0x00000004u;
goto P_0c092122;
P_0c092122: /* original 63f2, guest PC 0x0c092122 */
if(!s->budget--) { s->failed_pc=0x0c092122u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c092124;
P_0c092124: /* original 73ff, guest PC 0x0c092124 */
if(!s->budget--) { s->failed_pc=0x0c092124u; return 0; }
r[3]+=0xffffffffu;
goto P_0c092126;
P_0c092126: /* original 2f32, guest PC 0x0c092126 */
if(!s->budget--) { s->failed_pc=0x0c092126u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c092128;
P_0c092128: /* original 63f2, guest PC 0x0c092128 */
if(!s->budget--) { s->failed_pc=0x0c092128u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c09212a;
P_0c09212a: /* original 64b3, guest PC 0x0c09212a */
if(!s->budget--) { s->failed_pc=0x0c09212au; return 0; }
r[4]=r[11];
goto P_0c09212c;
P_0c09212c: /* original 4315, guest PC 0x0c09212c */
if(!s->budget--) { s->failed_pc=0x0c09212cu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>0)!=0);
goto P_0c09212e;
P_0c09212e: /* original 8de6, guest PC 0x0c09212e */
if(!s->budget--) { s->failed_pc=0x0c09212eu; return 0; }
cond=r[17]&1u;
r[4]+=0x00000004u;
if(cond) { goto P_0c0920fe; }
goto P_0c092132;
P_0c092130: /* original 7404, guest PC 0x0c092130 */
if(!s->budget--) { s->failed_pc=0x0c092130u; return 0; }
r[4]+=0x00000004u;
goto P_0c092132;
P_0c092132: /* original 1fd1, guest PC 0x0c092132 */
if(!s->budget--) { s->failed_pc=0x0c092132u; return 0; }
write(ram,r[15]+4,r[13],4);
goto P_0c092134;
P_0c092134: /* original 66e3, guest PC 0x0c092134 */
if(!s->budget--) { s->failed_pc=0x0c092134u; return 0; }
r[6]=r[14];
goto P_0c092136;
P_0c092136: /* original d711, guest PC 0x0c092136 */
if(!s->budget--) { s->failed_pc=0x0c092136u; return 0; }
r[7]=read(ram,0x0c09217cu,4);
goto P_0c092138;
P_0c092138: /* original e500, guest PC 0x0c092138 */
if(!s->budget--) { s->failed_pc=0x0c092138u; return 0; }
r[5]=0x00000000u;
goto P_0c09213a;
P_0c09213a: /* original 6a43, guest PC 0x0c09213a */
if(!s->budget--) { s->failed_pc=0x0c09213au; return 0; }
r[10]=r[4];
goto P_0c09213c;
P_0c09213c: /* original 2fd6, guest PC 0x0c09213c */
if(!s->budget--) { s->failed_pc=0x0c09213cu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09213e;
P_0c09213e: /* original 4c0b, guest PC 0x0c09213e */
if(!s->budget--) { s->failed_pc=0x0c09213eu; return 0; }
target=r[12];
r[16]=code_base|0x0c092142u;
r[4]=r[10];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c092142u) { target=s->pc; goto dispatch; }
goto P_0c092142;
P_0c092140: /* original 64a3, guest PC 0x0c092140 */
if(!s->budget--) { s->failed_pc=0x0c092140u; return 0; }
r[4]=r[10];
goto P_0c092142;
P_0c092142: /* original 85f6, guest PC 0x0c092142 */
if(!s->budget--) { s->failed_pc=0x0c092142u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+12,2);
goto P_0c092144;
P_0c092144: /* original 7a02, guest PC 0x0c092144 */
if(!s->budget--) { s->failed_pc=0x0c092144u; return 0; }
r[10]+=0x00000002u;
goto P_0c092146;
P_0c092146: /* original e605, guest PC 0x0c092146 */
if(!s->budget--) { s->failed_pc=0x0c092146u; return 0; }
r[6]=0x00000005u;
goto P_0c092148;
P_0c092148: /* original 65a3, guest PC 0x0c092148 */
if(!s->budget--) { s->failed_pc=0x0c092148u; return 0; }
r[5]=r[10];
goto P_0c09214a;
P_0c09214a: /* original 81f2, guest PC 0x0c09214a */
if(!s->budget--) { s->failed_pc=0x0c09214au; return 0; }
write(ram,r[15]+4,r[0],2);
goto P_0c09214c;
P_0c09214c: /* original e702, guest PC 0x0c09214c */
if(!s->budget--) { s->failed_pc=0x0c09214cu; return 0; }
r[7]=0x00000002u;
goto P_0c09214e;
P_0c09214e: /* original 9b09, guest PC 0x0c09214e */
if(!s->budget--) { s->failed_pc=0x0c09214eu; return 0; }
r[11]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c092164u,2);
goto P_0c092150;
P_0c092150: /* original 2fd6, guest PC 0x0c092150 */
if(!s->budget--) { s->failed_pc=0x0c092150u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c092152;
P_0c092152: /* original 490b, guest PC 0x0c092152 */
if(!s->budget--) { s->failed_pc=0x0c092152u; return 0; }
target=r[9];
r[16]=code_base|0x0c092156u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c092156u) { target=s->pc; goto dispatch; }
goto P_0c092156;
P_0c092154: /* original 64e3, guest PC 0x0c092154 */
if(!s->budget--) { s->failed_pc=0x0c092154u; return 0; }
r[4]=r[14];
goto P_0c092156;
P_0c092156: /* original 7f08, guest PC 0x0c092156 */
if(!s->budget--) { s->failed_pc=0x0c092156u; return 0; }
r[15]+=0x00000008u;
goto P_0c092158;
P_0c092158: /* original a043, guest PC 0x0c092158 */
if(!s->budget--) { s->failed_pc=0x0c092158u; return 0; }
r[3]=0x00000005u;
goto P_0c0921e2;
P_0c09215a: /* original e305, guest PC 0x0c09215a */
if(!s->budget--) { s->failed_pc=0x0c09215au; return 0; }
r[3]=0x00000005u;
if(!vf3_matrix_family(0x0c09215cu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c09215cu; return 0; } return 1;
P_0c092180: /* original 61f1, guest PC 0x0c092180 */
if(!s->budget--) { s->failed_pc=0x0c092180u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[15],2);
r[1]=tmp;
goto P_0c092182;
P_0c092182: /* original d320, guest PC 0x0c092182 */
if(!s->budget--) { s->failed_pc=0x0c092182u; return 0; }
r[3]=read(ram,0x0c092204u,4);
goto P_0c092184;
P_0c092184: /* original 611d, guest PC 0x0c092184 */
if(!s->budget--) { s->failed_pc=0x0c092184u; return 0; }
r[1]=r[1]&65535u;
goto P_0c092186;
P_0c092186: /* original 430b, guest PC 0x0c092186 */
if(!s->budget--) { s->failed_pc=0x0c092186u; return 0; }
target=r[3];
r[16]=code_base|0x0c09218au;
r[0]=r[11];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09218au) { target=s->pc; goto dispatch; }
goto P_0c09218a;
P_0c092188: /* original 60b3, guest PC 0x0c092188 */
if(!s->budget--) { s->failed_pc=0x0c092188u; return 0; }
r[0]=r[11];
goto P_0c09218a;
P_0c09218a: /* original 6403, guest PC 0x0c09218a */
if(!s->budget--) { s->failed_pc=0x0c09218au; return 0; }
r[4]=r[0];
goto P_0c09218c;
P_0c09218c: /* original 63f1, guest PC 0x0c09218c */
if(!s->budget--) { s->failed_pc=0x0c09218cu; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[15],2);
r[3]=tmp;
goto P_0c09218e;
P_0c09218e: /* original 24be, guest PC 0x0c09218e */
if(!s->budget--) { s->failed_pc=0x0c09218eu; return 0; }
r[19]=(r[4]&65535u)*(r[11]&65535u);
goto P_0c092190;
P_0c092190: /* original 61b3, guest PC 0x0c092190 */
if(!s->budget--) { s->failed_pc=0x0c092190u; return 0; }
r[1]=r[11];
goto P_0c092192;
P_0c092192: /* original e50a, guest PC 0x0c092192 */
if(!s->budget--) { s->failed_pc=0x0c092192u; return 0; }
r[5]=0x0000000au;
goto P_0c092194;
P_0c092194: /* original 021a, guest PC 0x0c092194 */
if(!s->budget--) { s->failed_pc=0x0c092194u; return 0; }
r[2]=r[19];
goto P_0c092196;
P_0c092196: /* original 3328, guest PC 0x0c092196 */
if(!s->budget--) { s->failed_pc=0x0c092196u; return 0; }
r[3]-=r[2];
goto P_0c092198;
P_0c092198: /* original 2f31, guest PC 0x0c092198 */
if(!s->budget--) { s->failed_pc=0x0c092198u; return 0; }
write(ram,r[15],r[3],2);
goto P_0c09219a;
P_0c09219a: /* original d21a, guest PC 0x0c09219a */
if(!s->budget--) { s->failed_pc=0x0c09219au; return 0; }
r[2]=read(ram,0x0c092204u,4);
goto P_0c09219c;
P_0c09219c: /* original 420b, guest PC 0x0c09219c */
if(!s->budget--) { s->failed_pc=0x0c09219cu; return 0; }
target=r[2];
r[16]=code_base|0x0c0921a0u;
r[0]=r[5];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0921a0u) { target=s->pc; goto dispatch; }
goto P_0c0921a0;
P_0c09219e: /* original 6053, guest PC 0x0c09219e */
if(!s->budget--) { s->failed_pc=0x0c09219eu; return 0; }
r[0]=r[5];
goto P_0c0921a0;
P_0c0921a0: /* original 2448, guest PC 0x0c0921a0 */
if(!s->budget--) { s->failed_pc=0x0c0921a0u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c0921a2;
P_0c0921a2: /* original 8f03, guest PC 0x0c0921a2 */
if(!s->budget--) { s->failed_pc=0x0c0921a2u; return 0; }
cond=r[17]&1u;
r[11]=r[0];
if(!cond) { goto P_0c0921ac; }
goto P_0c0921a6;
P_0c0921a4: /* original 6b03, guest PC 0x0c0921a4 */
if(!s->budget--) { s->failed_pc=0x0c0921a4u; return 0; }
r[11]=r[0];
goto P_0c0921a6;
P_0c0921a6: /* original 52f1, guest PC 0x0c0921a6 */
if(!s->budget--) { s->failed_pc=0x0c0921a6u; return 0; }
r[2]=read(ram,r[15]+4,4);
goto P_0c0921a8;
P_0c0921a8: /* original 2228, guest PC 0x0c0921a8 */
if(!s->budget--) { s->failed_pc=0x0c0921a8u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c0921aa;
P_0c0921aa: /* original 8917, guest PC 0x0c0921aa */
if(!s->budget--) { s->failed_pc=0x0c0921aau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0921dc; }
goto P_0c0921ac;
P_0c0921ac: /* original e501, guest PC 0x0c0921ac */
if(!s->budget--) { s->failed_pc=0x0c0921acu; return 0; }
r[5]=0x00000001u;
goto P_0c0921ae;
P_0c0921ae: /* original 1f51, guest PC 0x0c0921ae */
if(!s->budget--) { s->failed_pc=0x0c0921aeu; return 0; }
write(ram,r[15]+4,r[5],4);
goto P_0c0921b0;
P_0c0921b0: /* original 7430, guest PC 0x0c0921b0 */
if(!s->budget--) { s->failed_pc=0x0c0921b0u; return 0; }
r[4]+=0x00000030u;
goto P_0c0921b2;
P_0c0921b2: /* original 9525, guest PC 0x0c0921b2 */
if(!s->budget--) { s->failed_pc=0x0c0921b2u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c092200u,2);
goto P_0c0921b4;
P_0c0921b4: /* original 6643, guest PC 0x0c0921b4 */
if(!s->budget--) { s->failed_pc=0x0c0921b4u; return 0; }
r[6]=r[4];
goto P_0c0921b6;
P_0c0921b6: /* original 2689, guest PC 0x0c0921b6 */
if(!s->budget--) { s->failed_pc=0x0c0921b6u; return 0; }
r[6]&=r[8];
goto P_0c0921b8;
P_0c0921b8: /* original 2459, guest PC 0x0c0921b8 */
if(!s->budget--) { s->failed_pc=0x0c0921b8u; return 0; }
r[4]&=r[5];
goto P_0c0921ba;
P_0c0921ba: /* original 6543, guest PC 0x0c0921ba */
if(!s->budget--) { s->failed_pc=0x0c0921bau; return 0; }
r[5]=r[4];
goto P_0c0921bc;
P_0c0921bc: /* original 4521, guest PC 0x0c0921bc */
if(!s->budget--) { s->failed_pc=0x0c0921bcu; return 0; }
r[17]=(r[17]&~1u)|((r[5]&1)!=0);
r[5]=(uint32_t)((int32_t)r[5]>>1);
goto P_0c0921be;
P_0c0921be: /* original 4628, guest PC 0x0c0921be */
if(!s->budget--) { s->failed_pc=0x0c0921beu; return 0; }
r[6]<<=16;
goto P_0c0921c0;
P_0c0921c0: /* original 941f, guest PC 0x0c0921c0 */
if(!s->budget--) { s->failed_pc=0x0c0921c0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c092202u,2);
goto P_0c0921c2;
P_0c0921c2: /* original 4521, guest PC 0x0c0921c2 */
if(!s->budget--) { s->failed_pc=0x0c0921c2u; return 0; }
r[17]=(r[17]&~1u)|((r[5]&1)!=0);
r[5]=(uint32_t)((int32_t)r[5]>>1);
goto P_0c0921c4;
P_0c0921c4: /* original 2fd6, guest PC 0x0c0921c4 */
if(!s->budget--) { s->failed_pc=0x0c0921c4u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0921c6;
P_0c0921c6: /* original 4618, guest PC 0x0c0921c6 */
if(!s->budget--) { s->failed_pc=0x0c0921c6u; return 0; }
r[6]<<=8;
goto P_0c0921c8;
P_0c0921c8: /* original 4521, guest PC 0x0c0921c8 */
if(!s->budget--) { s->failed_pc=0x0c0921c8u; return 0; }
r[17]=(r[17]&~1u)|((r[5]&1)!=0);
r[5]=(uint32_t)((int32_t)r[5]>>1);
goto P_0c0921ca;
P_0c0921ca: /* original 6763, guest PC 0x0c0921ca */
if(!s->budget--) { s->failed_pc=0x0c0921cau; return 0; }
r[7]=r[6];
goto P_0c0921cc;
P_0c0921cc: /* original 4528, guest PC 0x0c0921cc */
if(!s->budget--) { s->failed_pc=0x0c0921ccu; return 0; }
r[5]<<=16;
goto P_0c0921ce;
P_0c0921ce: /* original 66e3, guest PC 0x0c0921ce */
if(!s->budget--) { s->failed_pc=0x0c0921ceu; return 0; }
r[6]=r[14];
goto P_0c0921d0;
P_0c0921d0: /* original 275b, guest PC 0x0c0921d0 */
if(!s->budget--) { s->failed_pc=0x0c0921d0u; return 0; }
r[7]|=r[5];
goto P_0c0921d2;
P_0c0921d2: /* original e500, guest PC 0x0c0921d2 */
if(!s->budget--) { s->failed_pc=0x0c0921d2u; return 0; }
r[5]=0x00000000u;
goto P_0c0921d4;
P_0c0921d4: /* original 274b, guest PC 0x0c0921d4 */
if(!s->budget--) { s->failed_pc=0x0c0921d4u; return 0; }
r[7]|=r[4];
goto P_0c0921d6;
P_0c0921d6: /* original 4c0b, guest PC 0x0c0921d6 */
if(!s->budget--) { s->failed_pc=0x0c0921d6u; return 0; }
target=r[12];
r[16]=code_base|0x0c0921dau;
r[4]=r[10];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0921dau) { target=s->pc; goto dispatch; }
goto P_0c0921da;
P_0c0921d8: /* original 64a3, guest PC 0x0c0921d8 */
if(!s->budget--) { s->failed_pc=0x0c0921d8u; return 0; }
r[4]=r[10];
goto P_0c0921da;
P_0c0921da: /* original 7f04, guest PC 0x0c0921da */
if(!s->budget--) { s->failed_pc=0x0c0921dau; return 0; }
r[15]+=0x00000004u;
goto P_0c0921dc;
P_0c0921dc: /* original 53f2, guest PC 0x0c0921dc */
if(!s->budget--) { s->failed_pc=0x0c0921dcu; return 0; }
r[3]=read(ram,r[15]+8,4);
goto P_0c0921de;
P_0c0921de: /* original 7a02, guest PC 0x0c0921de */
if(!s->budget--) { s->failed_pc=0x0c0921deu; return 0; }
r[10]+=0x00000002u;
goto P_0c0921e0;
P_0c0921e0: /* original 73ff, guest PC 0x0c0921e0 */
if(!s->budget--) { s->failed_pc=0x0c0921e0u; return 0; }
r[3]+=0xffffffffu;
goto P_0c0921e2;
P_0c0921e2: /* original 6233, guest PC 0x0c0921e2 */
if(!s->budget--) { s->failed_pc=0x0c0921e2u; return 0; }
r[2]=r[3];
goto P_0c0921e4;
P_0c0921e4: /* original 4215, guest PC 0x0c0921e4 */
if(!s->budget--) { s->failed_pc=0x0c0921e4u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>0)!=0);
goto P_0c0921e6;
P_0c0921e6: /* original 1f32, guest PC 0x0c0921e6 */
if(!s->budget--) { s->failed_pc=0x0c0921e6u; return 0; }
write(ram,r[15]+8,r[3],4);
goto P_0c0921e8;
P_0c0921e8: /* original 89ca, guest PC 0x0c0921e8 */
if(!s->budget--) { s->failed_pc=0x0c0921e8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c092180; }
goto P_0c0921ea;
P_0c0921ea: /* original 7f0c, guest PC 0x0c0921ea */
if(!s->budget--) { s->failed_pc=0x0c0921eau; return 0; }
r[15]+=0x0000000cu;
goto P_0c0921ec;
P_0c0921ec: /* original 4f16, guest PC 0x0c0921ec */
if(!s->budget--) { s->failed_pc=0x0c0921ecu; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c0921ee;
P_0c0921ee: /* original 4f26, guest PC 0x0c0921ee */
if(!s->budget--) { s->failed_pc=0x0c0921eeu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0921f0;
P_0c0921f0: /* original 68f6, guest PC 0x0c0921f0 */
if(!s->budget--) { s->failed_pc=0x0c0921f0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c0921f2;
P_0c0921f2: /* original 69f6, guest PC 0x0c0921f2 */
if(!s->budget--) { s->failed_pc=0x0c0921f2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0921f4;
P_0c0921f4: /* original 6af6, guest PC 0x0c0921f4 */
if(!s->budget--) { s->failed_pc=0x0c0921f4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0921f6;
P_0c0921f6: /* original 6bf6, guest PC 0x0c0921f6 */
if(!s->budget--) { s->failed_pc=0x0c0921f6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0921f8;
P_0c0921f8: /* original 6cf6, guest PC 0x0c0921f8 */
if(!s->budget--) { s->failed_pc=0x0c0921f8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0921fa;
P_0c0921fa: /* original 6df6, guest PC 0x0c0921fa */
if(!s->budget--) { s->failed_pc=0x0c0921fau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0921fc;
P_0c0921fc: /* original 000b, guest PC 0x0c0921fc */
if(!s->budget--) { s->failed_pc=0x0c0921fcu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0921fe: /* original 6ef6, guest PC 0x0c0921fe */
if(!s->budget--) { s->failed_pc=0x0c0921feu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c092200u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c092200u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
