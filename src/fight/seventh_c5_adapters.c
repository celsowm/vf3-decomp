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
int vf3_seventh_c5_adapter(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c03b304u: goto P_0c03b304;
case 0x0c03b306u: goto P_0c03b306;
case 0x0c03b308u: goto P_0c03b308;
case 0x0c03b30au: goto P_0c03b30a;
case 0x0c03b30cu: goto P_0c03b30c;
case 0x0c03b30eu: goto P_0c03b30e;
case 0x0c03b310u: goto P_0c03b310;
case 0x0c03b312u: goto P_0c03b312;
case 0x0c03b314u: goto P_0c03b314;
case 0x0c03b316u: goto P_0c03b316;
case 0x0c03b318u: goto P_0c03b318;
case 0x0c03b31au: goto P_0c03b31a;
case 0x0c03b31cu: goto P_0c03b31c;
case 0x0c03b31eu: goto P_0c03b31e;
case 0x0c03b320u: goto P_0c03b320;
case 0x0c03b322u: goto P_0c03b322;
case 0x0c03b324u: goto P_0c03b324;
case 0x0c03b326u: goto P_0c03b326;
case 0x0c03b328u: goto P_0c03b328;
case 0x0c03b32au: goto P_0c03b32a;
case 0x0c03b32cu: goto P_0c03b32c;
case 0x0c03b32eu: goto P_0c03b32e;
case 0x0c03b330u: goto P_0c03b330;
case 0x0c03b332u: goto P_0c03b332;
case 0x0c03b334u: goto P_0c03b334;
case 0x0c03b336u: goto P_0c03b336;
case 0x0c03b338u: goto P_0c03b338;
case 0x0c040378u: goto P_0c040378;
case 0x0c04037au: goto P_0c04037a;
case 0x0c04037cu: goto P_0c04037c;
case 0x0c04037eu: goto P_0c04037e;
case 0x0c040380u: goto P_0c040380;
case 0x0c040382u: goto P_0c040382;
case 0x0c040384u: goto P_0c040384;
case 0x0c040386u: goto P_0c040386;
case 0x0c040388u: goto P_0c040388;
case 0x0c04038au: goto P_0c04038a;
case 0x0c04038cu: goto P_0c04038c;
case 0x0c04038eu: goto P_0c04038e;
case 0x0c040390u: goto P_0c040390;
case 0x0c040392u: goto P_0c040392;
case 0x0c040394u: goto P_0c040394;
case 0x0c040396u: goto P_0c040396;
case 0x0c040398u: goto P_0c040398;
case 0x0c04039au: goto P_0c04039a;
case 0x0c04039cu: goto P_0c04039c;
case 0x0c04039eu: goto P_0c04039e;
case 0x0c0403a0u: goto P_0c0403a0;
case 0x0c0403a2u: goto P_0c0403a2;
case 0x0c0403a4u: goto P_0c0403a4;
case 0x0c0403a6u: goto P_0c0403a6;
case 0x0c0403a8u: goto P_0c0403a8;
case 0x0c0403aau: goto P_0c0403aa;
case 0x0c0403acu: goto P_0c0403ac;
case 0x0c0403aeu: goto P_0c0403ae;
case 0x0c0403b0u: goto P_0c0403b0;
case 0x0c0403b2u: goto P_0c0403b2;
case 0x0c0403b4u: goto P_0c0403b4;
case 0x0c05e1b2u: goto P_0c05e1b2;
case 0x0c05e1b4u: goto P_0c05e1b4;
case 0x0c05e1b6u: goto P_0c05e1b6;
case 0x0c05e1b8u: goto P_0c05e1b8;
case 0x0c05e1bau: goto P_0c05e1ba;
case 0x0c05e1bcu: goto P_0c05e1bc;
case 0x0c05e1beu: goto P_0c05e1be;
case 0x0c05e1c0u: goto P_0c05e1c0;
case 0x0c060d14u: goto P_0c060d14;
case 0x0c060d16u: goto P_0c060d16;
case 0x0c060d18u: goto P_0c060d18;
case 0x0c060d1au: goto P_0c060d1a;
case 0x0c060d1cu: goto P_0c060d1c;
case 0x0c066dc4u: goto P_0c066dc4;
case 0x0c066dc6u: goto P_0c066dc6;
case 0x0c066dc8u: goto P_0c066dc8;
case 0x0c066dcau: goto P_0c066dca;
case 0x0c066dccu: goto P_0c066dcc;
case 0x0c066dceu: goto P_0c066dce;
case 0x0c066dd0u: goto P_0c066dd0;
case 0x0c066dd2u: goto P_0c066dd2;
case 0x0c066dd4u: goto P_0c066dd4;
case 0x0c066dd6u: goto P_0c066dd6;
case 0x0c066dd8u: goto P_0c066dd8;
case 0x0c066ddau: goto P_0c066dda;
case 0x0c066ddcu: goto P_0c066ddc;
case 0x0c066ddeu: goto P_0c066dde;
case 0x0c066de0u: goto P_0c066de0;
case 0x0c066de2u: goto P_0c066de2;
case 0x0c066de4u: goto P_0c066de4;
case 0x0c066de6u: goto P_0c066de6;
case 0x0c066de8u: goto P_0c066de8;
case 0x0c066deau: goto P_0c066dea;
case 0x0c066decu: goto P_0c066dec;
case 0x0c066deeu: goto P_0c066dee;
case 0x0c066df0u: goto P_0c066df0;
case 0x0c066df2u: goto P_0c066df2;
case 0x0c066df4u: goto P_0c066df4;
case 0x0c066df6u: goto P_0c066df6;
case 0x0c066df8u: goto P_0c066df8;
case 0x0c066dfau: goto P_0c066dfa;
case 0x0c066dfcu: goto P_0c066dfc;
case 0x0c066dfeu: goto P_0c066dfe;
case 0x0c066e00u: goto P_0c066e00;
case 0x0c066e02u: goto P_0c066e02;
case 0x0c066e04u: goto P_0c066e04;
case 0x0c066e06u: goto P_0c066e06;
case 0x0c066e08u: goto P_0c066e08;
case 0x0c066e0au: goto P_0c066e0a;
case 0x0c066e0cu: goto P_0c066e0c;
case 0x0c066e0eu: goto P_0c066e0e;
case 0x0c066e10u: goto P_0c066e10;
case 0x0c066e12u: goto P_0c066e12;
case 0x0c066e14u: goto P_0c066e14;
case 0x0c066e16u: goto P_0c066e16;
case 0x0c066e18u: goto P_0c066e18;
case 0x0c066e1au: goto P_0c066e1a;
case 0x0c066e1cu: goto P_0c066e1c;
case 0x0c066e1eu: goto P_0c066e1e;
case 0x0c066e20u: goto P_0c066e20;
case 0x0c066e22u: goto P_0c066e22;
case 0x0c066e24u: goto P_0c066e24;
case 0x0c066e26u: goto P_0c066e26;
case 0x0c066e28u: goto P_0c066e28;
case 0x0c066e2au: goto P_0c066e2a;
case 0x0c066e2cu: goto P_0c066e2c;
case 0x0c066e2eu: goto P_0c066e2e;
case 0x0c066e30u: goto P_0c066e30;
case 0x0c066e32u: goto P_0c066e32;
case 0x0c066e34u: goto P_0c066e34;
case 0x0c066e36u: goto P_0c066e36;
case 0x0c066e38u: goto P_0c066e38;
case 0x0c066e3au: goto P_0c066e3a;
case 0x0c066e3cu: goto P_0c066e3c;
case 0x0c066e3eu: goto P_0c066e3e;
case 0x0c066e40u: goto P_0c066e40;
case 0x0c066e42u: goto P_0c066e42;
case 0x0c066e44u: goto P_0c066e44;
case 0x0c066e46u: goto P_0c066e46;
case 0x0c066e78u: goto P_0c066e78;
case 0x0c066e7au: goto P_0c066e7a;
case 0x0c066e7cu: goto P_0c066e7c;
case 0x0c066e7eu: goto P_0c066e7e;
case 0x0c066e80u: goto P_0c066e80;
case 0x0c066e82u: goto P_0c066e82;
case 0x0c066e84u: goto P_0c066e84;
case 0x0c066e86u: goto P_0c066e86;
case 0x0c066e88u: goto P_0c066e88;
case 0x0c066e8au: goto P_0c066e8a;
case 0x0c066e8cu: goto P_0c066e8c;
case 0x0c066e8eu: goto P_0c066e8e;
case 0x0c066e90u: goto P_0c066e90;
case 0x0c066e92u: goto P_0c066e92;
case 0x0c066e94u: goto P_0c066e94;
case 0x0c066e96u: goto P_0c066e96;
case 0x0c066e98u: goto P_0c066e98;
case 0x0c066e9au: goto P_0c066e9a;
case 0x0c066e9cu: goto P_0c066e9c;
case 0x0c066e9eu: goto P_0c066e9e;
case 0x0c066ea0u: goto P_0c066ea0;
case 0x0c066ea2u: goto P_0c066ea2;
case 0x0c066ea4u: goto P_0c066ea4;
case 0x0c066ea6u: goto P_0c066ea6;
case 0x0c066ea8u: goto P_0c066ea8;
case 0x0c066eaau: goto P_0c066eaa;
case 0x0c066eacu: goto P_0c066eac;
case 0x0c066eaeu: goto P_0c066eae;
case 0x0c066eb0u: goto P_0c066eb0;
case 0x0c066eb2u: goto P_0c066eb2;
case 0x0c066eb4u: goto P_0c066eb4;
case 0x0c066eb6u: goto P_0c066eb6;
case 0x0c066eb8u: goto P_0c066eb8;
case 0x0c066ebau: goto P_0c066eba;
case 0x0c066ebcu: goto P_0c066ebc;
case 0x0c066ebeu: goto P_0c066ebe;
case 0x0c066ec0u: goto P_0c066ec0;
case 0x0c066ec2u: goto P_0c066ec2;
case 0x0c066ec4u: goto P_0c066ec4;
case 0x0c066ec6u: goto P_0c066ec6;
case 0x0c066ec8u: goto P_0c066ec8;
case 0x0c066ecau: goto P_0c066eca;
case 0x0c066eccu: goto P_0c066ecc;
case 0x0c066eceu: goto P_0c066ece;
case 0x0c066ed0u: goto P_0c066ed0;
case 0x0c066ed2u: goto P_0c066ed2;
case 0x0c066ed4u: goto P_0c066ed4;
case 0x0c066ed6u: goto P_0c066ed6;
case 0x0c066ed8u: goto P_0c066ed8;
case 0x0c066edau: goto P_0c066eda;
case 0x0c066edcu: goto P_0c066edc;
case 0x0c066edeu: goto P_0c066ede;
case 0x0c066ee0u: goto P_0c066ee0;
case 0x0c066ee2u: goto P_0c066ee2;
case 0x0c066ee4u: goto P_0c066ee4;
case 0x0c066ee6u: goto P_0c066ee6;
case 0x0c066ee8u: goto P_0c066ee8;
case 0x0c066eeau: goto P_0c066eea;
case 0x0c066eecu: goto P_0c066eec;
case 0x0c066eeeu: goto P_0c066eee;
case 0x0c066ef0u: goto P_0c066ef0;
case 0x0c066ef2u: goto P_0c066ef2;
case 0x0c066ef4u: goto P_0c066ef4;
case 0x0c066ef6u: goto P_0c066ef6;
case 0x0c066ef8u: goto P_0c066ef8;
case 0x0c066efau: goto P_0c066efa;
case 0x0c066efcu: goto P_0c066efc;
case 0x0c066efeu: goto P_0c066efe;
case 0x0c066f00u: goto P_0c066f00;
case 0x0c066f02u: goto P_0c066f02;
case 0x0c066f04u: goto P_0c066f04;
case 0x0c066f06u: goto P_0c066f06;
case 0x0c066f08u: goto P_0c066f08;
case 0x0c066f0au: goto P_0c066f0a;
case 0x0c066f0cu: goto P_0c066f0c;
case 0x0c066f0eu: goto P_0c066f0e;
case 0x0c066f10u: goto P_0c066f10;
case 0x0c066f12u: goto P_0c066f12;
case 0x0c066f14u: goto P_0c066f14;
case 0x0c066f16u: goto P_0c066f16;
case 0x0c066f18u: goto P_0c066f18;
case 0x0c066f1au: goto P_0c066f1a;
case 0x0c066f1cu: goto P_0c066f1c;
case 0x0c066f1eu: goto P_0c066f1e;
case 0x0c066f20u: goto P_0c066f20;
case 0x0c066f22u: goto P_0c066f22;
case 0x0c066f24u: goto P_0c066f24;
case 0x0c066f26u: goto P_0c066f26;
case 0x0c066f28u: goto P_0c066f28;
case 0x0c066f2au: goto P_0c066f2a;
case 0x0c066f2cu: goto P_0c066f2c;
case 0x0c066f2eu: goto P_0c066f2e;
case 0x0c066f30u: goto P_0c066f30;
case 0x0c066f32u: goto P_0c066f32;
case 0x0c066f34u: goto P_0c066f34;
case 0x0c066f36u: goto P_0c066f36;
case 0x0c066f38u: goto P_0c066f38;
case 0x0c066f3au: goto P_0c066f3a;
case 0x0c066f3cu: goto P_0c066f3c;
case 0x0c066f3eu: goto P_0c066f3e;
case 0x0c066f40u: goto P_0c066f40;
case 0x0c066f42u: goto P_0c066f42;
case 0x0c066f44u: goto P_0c066f44;
case 0x0c066f46u: goto P_0c066f46;
case 0x0c066f48u: goto P_0c066f48;
case 0x0c066f4au: goto P_0c066f4a;
case 0x0c066f4cu: goto P_0c066f4c;
case 0x0c066f4eu: goto P_0c066f4e;
case 0x0c066f50u: goto P_0c066f50;
case 0x0c066f52u: goto P_0c066f52;
case 0x0c066f54u: goto P_0c066f54;
case 0x0c066f56u: goto P_0c066f56;
case 0x0c066f58u: goto P_0c066f58;
case 0x0c066f5au: goto P_0c066f5a;
case 0x0c066f5cu: goto P_0c066f5c;
case 0x0c066f5eu: goto P_0c066f5e;
case 0x0c066f60u: goto P_0c066f60;
case 0x0c066f62u: goto P_0c066f62;
case 0x0c066f64u: goto P_0c066f64;
case 0x0c066f66u: goto P_0c066f66;
case 0x0c066f68u: goto P_0c066f68;
case 0x0c066f6au: goto P_0c066f6a;
case 0x0c066f6cu: goto P_0c066f6c;
case 0x0c066f6eu: goto P_0c066f6e;
case 0x0c066f70u: goto P_0c066f70;
case 0x0c066f72u: goto P_0c066f72;
case 0x0c066f74u: goto P_0c066f74;
case 0x0c066f76u: goto P_0c066f76;
case 0x0c066f78u: goto P_0c066f78;
case 0x0c066f7au: goto P_0c066f7a;
case 0x0c066f7cu: goto P_0c066f7c;
case 0x0c066f7eu: goto P_0c066f7e;
case 0x0c066f80u: goto P_0c066f80;
case 0x0c066f82u: goto P_0c066f82;
case 0x0c066f84u: goto P_0c066f84;
case 0x0c066f86u: goto P_0c066f86;
case 0x0c066f88u: goto P_0c066f88;
case 0x0c066f8au: goto P_0c066f8a;
case 0x0c066f8cu: goto P_0c066f8c;
case 0x0c066f8eu: goto P_0c066f8e;
case 0x0c066f90u: goto P_0c066f90;
case 0x0c066f92u: goto P_0c066f92;
case 0x0c066f94u: goto P_0c066f94;
case 0x0c066f96u: goto P_0c066f96;
case 0x0c066f98u: goto P_0c066f98;
case 0x0c066f9au: goto P_0c066f9a;
case 0x0c066f9cu: goto P_0c066f9c;
case 0x0c066f9eu: goto P_0c066f9e;
case 0x0c066fa0u: goto P_0c066fa0;
case 0x0c066fa2u: goto P_0c066fa2;
case 0x0c066fa4u: goto P_0c066fa4;
case 0x0c066fa6u: goto P_0c066fa6;
case 0x0c066fa8u: goto P_0c066fa8;
case 0x0c066faau: goto P_0c066faa;
case 0x0c066facu: goto P_0c066fac;
case 0x0c066faeu: goto P_0c066fae;
case 0x0c066fb0u: goto P_0c066fb0;
case 0x0c066fb2u: goto P_0c066fb2;
case 0x0c066fb4u: goto P_0c066fb4;
case 0x0c066fd8u: goto P_0c066fd8;
case 0x0c066fdau: goto P_0c066fda;
case 0x0c066fdcu: goto P_0c066fdc;
case 0x0c066fdeu: goto P_0c066fde;
case 0x0c066fe0u: goto P_0c066fe0;
case 0x0c066fe2u: goto P_0c066fe2;
case 0x0c066fe4u: goto P_0c066fe4;
case 0x0c066fe6u: goto P_0c066fe6;
case 0x0c066fe8u: goto P_0c066fe8;
case 0x0c066feau: goto P_0c066fea;
case 0x0c066fecu: goto P_0c066fec;
case 0x0c066feeu: goto P_0c066fee;
case 0x0c066ff0u: goto P_0c066ff0;
case 0x0c066ff2u: goto P_0c066ff2;
case 0x0c066ff4u: goto P_0c066ff4;
case 0x0c066ff6u: goto P_0c066ff6;
case 0x0c066ff8u: goto P_0c066ff8;
case 0x0c066ffau: goto P_0c066ffa;
case 0x0c066ffcu: goto P_0c066ffc;
case 0x0c066ffeu: goto P_0c066ffe;
case 0x0c067000u: goto P_0c067000;
case 0x0c067002u: goto P_0c067002;
case 0x0c067004u: goto P_0c067004;
case 0x0c067006u: goto P_0c067006;
case 0x0c067008u: goto P_0c067008;
case 0x0c06700au: goto P_0c06700a;
case 0x0c06700cu: goto P_0c06700c;
case 0x0c06700eu: goto P_0c06700e;
case 0x0c067010u: goto P_0c067010;
case 0x0c067012u: goto P_0c067012;
case 0x0c067014u: goto P_0c067014;
case 0x0c067016u: goto P_0c067016;
case 0x0c067018u: goto P_0c067018;
case 0x0c06701au: goto P_0c06701a;
case 0x0c06701cu: goto P_0c06701c;
case 0x0c06701eu: goto P_0c06701e;
case 0x0c067020u: goto P_0c067020;
case 0x0c067022u: goto P_0c067022;
case 0x0c067024u: goto P_0c067024;
case 0x0c067026u: goto P_0c067026;
case 0x0c067028u: goto P_0c067028;
case 0x0c06702au: goto P_0c06702a;
case 0x0c06702cu: goto P_0c06702c;
case 0x0c06702eu: goto P_0c06702e;
case 0x0c067030u: goto P_0c067030;
case 0x0c067032u: goto P_0c067032;
case 0x0c067034u: goto P_0c067034;
case 0x0c067036u: goto P_0c067036;
case 0x0c067038u: goto P_0c067038;
case 0x0c06703au: goto P_0c06703a;
case 0x0c06703cu: goto P_0c06703c;
case 0x0c06703eu: goto P_0c06703e;
case 0x0c067040u: goto P_0c067040;
case 0x0c067042u: goto P_0c067042;
case 0x0c067044u: goto P_0c067044;
case 0x0c067046u: goto P_0c067046;
case 0x0c067048u: goto P_0c067048;
case 0x0c06704au: goto P_0c06704a;
case 0x0c06704cu: goto P_0c06704c;
case 0x0c06704eu: goto P_0c06704e;
case 0x0c067050u: goto P_0c067050;
case 0x0c067052u: goto P_0c067052;
case 0x0c067054u: goto P_0c067054;
case 0x0c067056u: goto P_0c067056;
case 0x0c067058u: goto P_0c067058;
case 0x0c06705au: goto P_0c06705a;
case 0x0c06705cu: goto P_0c06705c;
case 0x0c06705eu: goto P_0c06705e;
case 0x0c067060u: goto P_0c067060;
case 0x0c067062u: goto P_0c067062;
case 0x0c067064u: goto P_0c067064;
case 0x0c067066u: goto P_0c067066;
case 0x0c067068u: goto P_0c067068;
case 0x0c06706au: goto P_0c06706a;
case 0x0c06706cu: goto P_0c06706c;
case 0x0c06706eu: goto P_0c06706e;
case 0x0c067070u: goto P_0c067070;
case 0x0c067072u: goto P_0c067072;
case 0x0c067074u: goto P_0c067074;
case 0x0c067076u: goto P_0c067076;
case 0x0c067078u: goto P_0c067078;
case 0x0c06707au: goto P_0c06707a;
case 0x0c06707cu: goto P_0c06707c;
case 0x0c06707eu: goto P_0c06707e;
case 0x0c067080u: goto P_0c067080;
case 0x0c067082u: goto P_0c067082;
case 0x0c067084u: goto P_0c067084;
case 0x0c067086u: goto P_0c067086;
case 0x0c067088u: goto P_0c067088;
case 0x0c06708au: goto P_0c06708a;
case 0x0c06708cu: goto P_0c06708c;
case 0x0c06708eu: goto P_0c06708e;
case 0x0c067090u: goto P_0c067090;
case 0x0c067092u: goto P_0c067092;
case 0x0c067094u: goto P_0c067094;
case 0x0c067096u: goto P_0c067096;
case 0x0c067098u: goto P_0c067098;
case 0x0c06709au: goto P_0c06709a;
case 0x0c06709cu: goto P_0c06709c;
case 0x0c06709eu: goto P_0c06709e;
case 0x0c0670a0u: goto P_0c0670a0;
case 0x0c0670a2u: goto P_0c0670a2;
case 0x0c0670a4u: goto P_0c0670a4;
case 0x0c0670a6u: goto P_0c0670a6;
case 0x0c0670a8u: goto P_0c0670a8;
case 0x0c0670aau: goto P_0c0670aa;
case 0x0c0670acu: goto P_0c0670ac;
case 0x0c0670aeu: goto P_0c0670ae;
case 0x0c0670b0u: goto P_0c0670b0;
case 0x0c0670b2u: goto P_0c0670b2;
case 0x0c0670b4u: goto P_0c0670b4;
case 0x0c0670b6u: goto P_0c0670b6;
case 0x0c0670b8u: goto P_0c0670b8;
case 0x0c0670bau: goto P_0c0670ba;
case 0x0c0670bcu: goto P_0c0670bc;
case 0x0c0670beu: goto P_0c0670be;
case 0x0c0670c0u: goto P_0c0670c0;
case 0x0c0670c2u: goto P_0c0670c2;
case 0x0c0670d8u: goto P_0c0670d8;
case 0x0c0670dau: goto P_0c0670da;
case 0x0c0670dcu: goto P_0c0670dc;
case 0x0c0670deu: goto P_0c0670de;
case 0x0c0670e0u: goto P_0c0670e0;
case 0x0c0670e2u: goto P_0c0670e2;
case 0x0c0670e4u: goto P_0c0670e4;
case 0x0c0670e6u: goto P_0c0670e6;
case 0x0c0670e8u: goto P_0c0670e8;
case 0x0c0670eau: goto P_0c0670ea;
case 0x0c0670ecu: goto P_0c0670ec;
case 0x0c0670eeu: goto P_0c0670ee;
case 0x0c0670f0u: goto P_0c0670f0;
case 0x0c0670f2u: goto P_0c0670f2;
case 0x0c0670f4u: goto P_0c0670f4;
case 0x0c0670f6u: goto P_0c0670f6;
case 0x0c0670f8u: goto P_0c0670f8;
case 0x0c0670fau: goto P_0c0670fa;
case 0x0c0670fcu: goto P_0c0670fc;
case 0x0c0670feu: goto P_0c0670fe;
case 0x0c067100u: goto P_0c067100;
case 0x0c067102u: goto P_0c067102;
case 0x0c067104u: goto P_0c067104;
case 0x0c067106u: goto P_0c067106;
case 0x0c067108u: goto P_0c067108;
case 0x0c06710au: goto P_0c06710a;
case 0x0c06710cu: goto P_0c06710c;
case 0x0c06710eu: goto P_0c06710e;
case 0x0c067110u: goto P_0c067110;
case 0x0c067112u: goto P_0c067112;
case 0x0c067114u: goto P_0c067114;
case 0x0c067116u: goto P_0c067116;
case 0x0c067118u: goto P_0c067118;
case 0x0c06711au: goto P_0c06711a;
case 0x0c06711cu: goto P_0c06711c;
case 0x0c06711eu: goto P_0c06711e;
case 0x0c067120u: goto P_0c067120;
case 0x0c067122u: goto P_0c067122;
case 0x0c067124u: goto P_0c067124;
case 0x0c067126u: goto P_0c067126;
case 0x0c067128u: goto P_0c067128;
case 0x0c06712au: goto P_0c06712a;
case 0x0c06712cu: goto P_0c06712c;
case 0x0c06712eu: goto P_0c06712e;
case 0x0c067130u: goto P_0c067130;
case 0x0c067132u: goto P_0c067132;
case 0x0c067134u: goto P_0c067134;
case 0x0c067136u: goto P_0c067136;
case 0x0c067138u: goto P_0c067138;
case 0x0c06713au: goto P_0c06713a;
case 0x0c06713cu: goto P_0c06713c;
case 0x0c06713eu: goto P_0c06713e;
case 0x0c067140u: goto P_0c067140;
case 0x0c067142u: goto P_0c067142;
case 0x0c067144u: goto P_0c067144;
case 0x0c067146u: goto P_0c067146;
case 0x0c067148u: goto P_0c067148;
case 0x0c06714au: goto P_0c06714a;
case 0x0c06714cu: goto P_0c06714c;
case 0x0c06714eu: goto P_0c06714e;
case 0x0c067150u: goto P_0c067150;
case 0x0c067152u: goto P_0c067152;
case 0x0c067154u: goto P_0c067154;
case 0x0c067156u: goto P_0c067156;
case 0x0c067158u: goto P_0c067158;
case 0x0c06715au: goto P_0c06715a;
case 0x0c06715cu: goto P_0c06715c;
case 0x0c06715eu: goto P_0c06715e;
case 0x0c067160u: goto P_0c067160;
case 0x0c067162u: goto P_0c067162;
case 0x0c067164u: goto P_0c067164;
case 0x0c067166u: goto P_0c067166;
case 0x0c067168u: goto P_0c067168;
case 0x0c06716au: goto P_0c06716a;
case 0x0c06716cu: goto P_0c06716c;
case 0x0c06716eu: goto P_0c06716e;
case 0x0c067170u: goto P_0c067170;
case 0x0c067172u: goto P_0c067172;
case 0x0c067174u: goto P_0c067174;
case 0x0c067176u: goto P_0c067176;
case 0x0c067178u: goto P_0c067178;
case 0x0c06717au: goto P_0c06717a;
case 0x0c06717cu: goto P_0c06717c;
case 0x0c06717eu: goto P_0c06717e;
case 0x0c067180u: goto P_0c067180;
case 0x0c067182u: goto P_0c067182;
case 0x0c067184u: goto P_0c067184;
case 0x0c067186u: goto P_0c067186;
case 0x0c067188u: goto P_0c067188;
case 0x0c06718au: goto P_0c06718a;
case 0x0c06718cu: goto P_0c06718c;
case 0x0c06718eu: goto P_0c06718e;
case 0x0c067190u: goto P_0c067190;
case 0x0c067192u: goto P_0c067192;
case 0x0c067194u: goto P_0c067194;
case 0x0c067196u: goto P_0c067196;
case 0x0c067198u: goto P_0c067198;
case 0x0c06719au: goto P_0c06719a;
case 0x0c06719cu: goto P_0c06719c;
case 0x0c06719eu: goto P_0c06719e;
case 0x0c0671a0u: goto P_0c0671a0;
case 0x0c0671a2u: goto P_0c0671a2;
case 0x0c0671a4u: goto P_0c0671a4;
case 0x0c0671a6u: goto P_0c0671a6;
case 0x0c0671a8u: goto P_0c0671a8;
case 0x0c0671aau: goto P_0c0671aa;
case 0x0c0671acu: goto P_0c0671ac;
case 0x0c0671d8u: goto P_0c0671d8;
case 0x0c0671dau: goto P_0c0671da;
case 0x0c0671dcu: goto P_0c0671dc;
case 0x0c0671deu: goto P_0c0671de;
case 0x0c0671e0u: goto P_0c0671e0;
case 0x0c0671e2u: goto P_0c0671e2;
case 0x0c0671e4u: goto P_0c0671e4;
case 0x0c0671e6u: goto P_0c0671e6;
case 0x0c0671e8u: goto P_0c0671e8;
case 0x0c0671eau: goto P_0c0671ea;
case 0x0c0671ecu: goto P_0c0671ec;
case 0x0c0671eeu: goto P_0c0671ee;
case 0x0c0671f0u: goto P_0c0671f0;
case 0x0c0671f2u: goto P_0c0671f2;
case 0x0c0671f4u: goto P_0c0671f4;
case 0x0c0671f6u: goto P_0c0671f6;
case 0x0c0671f8u: goto P_0c0671f8;
case 0x0c0671fau: goto P_0c0671fa;
case 0x0c0671fcu: goto P_0c0671fc;
case 0x0c0671feu: goto P_0c0671fe;
case 0x0c067200u: goto P_0c067200;
case 0x0c067202u: goto P_0c067202;
case 0x0c067204u: goto P_0c067204;
case 0x0c067206u: goto P_0c067206;
case 0x0c067208u: goto P_0c067208;
case 0x0c06720au: goto P_0c06720a;
case 0x0c06720cu: goto P_0c06720c;
case 0x0c06720eu: goto P_0c06720e;
case 0x0c067210u: goto P_0c067210;
case 0x0c067212u: goto P_0c067212;
case 0x0c067214u: goto P_0c067214;
case 0x0c067216u: goto P_0c067216;
case 0x0c067218u: goto P_0c067218;
case 0x0c06721au: goto P_0c06721a;
case 0x0c06721cu: goto P_0c06721c;
case 0x0c06721eu: goto P_0c06721e;
case 0x0c067220u: goto P_0c067220;
case 0x0c067222u: goto P_0c067222;
case 0x0c067224u: goto P_0c067224;
case 0x0c067226u: goto P_0c067226;
case 0x0c067228u: goto P_0c067228;
case 0x0c06722au: goto P_0c06722a;
case 0x0c06722cu: goto P_0c06722c;
case 0x0c06722eu: goto P_0c06722e;
case 0x0c067230u: goto P_0c067230;
case 0x0c067232u: goto P_0c067232;
case 0x0c067234u: goto P_0c067234;
case 0x0c067236u: goto P_0c067236;
case 0x0c067238u: goto P_0c067238;
case 0x0c06723au: goto P_0c06723a;
case 0x0c06723cu: goto P_0c06723c;
case 0x0c06723eu: goto P_0c06723e;
case 0x0c067240u: goto P_0c067240;
case 0x0c067242u: goto P_0c067242;
case 0x0c067244u: goto P_0c067244;
case 0x0c067246u: goto P_0c067246;
case 0x0c067248u: goto P_0c067248;
case 0x0c06724au: goto P_0c06724a;
case 0x0c06724cu: goto P_0c06724c;
case 0x0c06724eu: goto P_0c06724e;
case 0x0c067250u: goto P_0c067250;
case 0x0c067252u: goto P_0c067252;
case 0x0c067254u: goto P_0c067254;
case 0x0c067256u: goto P_0c067256;
case 0x0c067258u: goto P_0c067258;
case 0x0c06725au: goto P_0c06725a;
case 0x0c06725cu: goto P_0c06725c;
case 0x0c06725eu: goto P_0c06725e;
case 0x0c067260u: goto P_0c067260;
case 0x0c067262u: goto P_0c067262;
case 0x0c067264u: goto P_0c067264;
case 0x0c067266u: goto P_0c067266;
case 0x0c067268u: goto P_0c067268;
case 0x0c06726au: goto P_0c06726a;
case 0x0c06726cu: goto P_0c06726c;
case 0x0c06726eu: goto P_0c06726e;
case 0x0c067270u: goto P_0c067270;
case 0x0c067272u: goto P_0c067272;
case 0x0c067274u: goto P_0c067274;
case 0x0c067276u: goto P_0c067276;
case 0x0c067278u: goto P_0c067278;
case 0x0c06727au: goto P_0c06727a;
case 0x0c06727cu: goto P_0c06727c;
case 0x0c06727eu: goto P_0c06727e;
case 0x0c067280u: goto P_0c067280;
case 0x0c067282u: goto P_0c067282;
case 0x0c067284u: goto P_0c067284;
case 0x0c067286u: goto P_0c067286;
case 0x0c067288u: goto P_0c067288;
case 0x0c06728au: goto P_0c06728a;
case 0x0c06728cu: goto P_0c06728c;
case 0x0c06728eu: goto P_0c06728e;
case 0x0c067290u: goto P_0c067290;
case 0x0c067292u: goto P_0c067292;
case 0x0c067294u: goto P_0c067294;
case 0x0c067296u: goto P_0c067296;
case 0x0c067298u: goto P_0c067298;
case 0x0c06729au: goto P_0c06729a;
case 0x0c06729cu: goto P_0c06729c;
case 0x0c06729eu: goto P_0c06729e;
case 0x0c0672a0u: goto P_0c0672a0;
case 0x0c0672a2u: goto P_0c0672a2;
case 0x0c0672c0u: goto P_0c0672c0;
case 0x0c0672c2u: goto P_0c0672c2;
case 0x0c0672c4u: goto P_0c0672c4;
case 0x0c0672c6u: goto P_0c0672c6;
case 0x0c0672c8u: goto P_0c0672c8;
case 0x0c0672cau: goto P_0c0672ca;
case 0x0c0672ccu: goto P_0c0672cc;
case 0x0c0672ceu: goto P_0c0672ce;
case 0x0c0672d0u: goto P_0c0672d0;
case 0x0c0672d2u: goto P_0c0672d2;
case 0x0c0672d4u: goto P_0c0672d4;
case 0x0c0672d6u: goto P_0c0672d6;
case 0x0c0672d8u: goto P_0c0672d8;
case 0x0c0672dau: goto P_0c0672da;
case 0x0c0672dcu: goto P_0c0672dc;
case 0x0c0672deu: goto P_0c0672de;
case 0x0c0672e0u: goto P_0c0672e0;
case 0x0c0672e2u: goto P_0c0672e2;
case 0x0c0672e4u: goto P_0c0672e4;
case 0x0c0672e6u: goto P_0c0672e6;
case 0x0c0672e8u: goto P_0c0672e8;
case 0x0c0672eau: goto P_0c0672ea;
case 0x0c0672ecu: goto P_0c0672ec;
case 0x0c0672eeu: goto P_0c0672ee;
case 0x0c0672f0u: goto P_0c0672f0;
case 0x0c0672f2u: goto P_0c0672f2;
case 0x0c0672f4u: goto P_0c0672f4;
case 0x0c0672f6u: goto P_0c0672f6;
case 0x0c0672f8u: goto P_0c0672f8;
case 0x0c0672fau: goto P_0c0672fa;
case 0x0c0672fcu: goto P_0c0672fc;
case 0x0c0672feu: goto P_0c0672fe;
case 0x0c067300u: goto P_0c067300;
case 0x0c067302u: goto P_0c067302;
case 0x0c067304u: goto P_0c067304;
case 0x0c067306u: goto P_0c067306;
case 0x0c067308u: goto P_0c067308;
case 0x0c06730au: goto P_0c06730a;
case 0x0c06730cu: goto P_0c06730c;
case 0x0c06730eu: goto P_0c06730e;
case 0x0c067310u: goto P_0c067310;
case 0x0c067312u: goto P_0c067312;
case 0x0c067314u: goto P_0c067314;
case 0x0c067316u: goto P_0c067316;
case 0x0c067318u: goto P_0c067318;
case 0x0c06731au: goto P_0c06731a;
case 0x0c06731cu: goto P_0c06731c;
case 0x0c06731eu: goto P_0c06731e;
case 0x0c067320u: goto P_0c067320;
case 0x0c067322u: goto P_0c067322;
case 0x0c067324u: goto P_0c067324;
case 0x0c067326u: goto P_0c067326;
case 0x0c067328u: goto P_0c067328;
case 0x0c06732au: goto P_0c06732a;
case 0x0c06732cu: goto P_0c06732c;
case 0x0c06732eu: goto P_0c06732e;
case 0x0c067330u: goto P_0c067330;
case 0x0c067332u: goto P_0c067332;
case 0x0c067334u: goto P_0c067334;
case 0x0c067336u: goto P_0c067336;
case 0x0c067338u: goto P_0c067338;
case 0x0c06733au: goto P_0c06733a;
case 0x0c06733cu: goto P_0c06733c;
case 0x0c06733eu: goto P_0c06733e;
case 0x0c067340u: goto P_0c067340;
case 0x0c067342u: goto P_0c067342;
case 0x0c067344u: goto P_0c067344;
case 0x0c067346u: goto P_0c067346;
case 0x0c067348u: goto P_0c067348;
case 0x0c06734au: goto P_0c06734a;
case 0x0c06734cu: goto P_0c06734c;
case 0x0c06734eu: goto P_0c06734e;
case 0x0c067350u: goto P_0c067350;
case 0x0c067352u: goto P_0c067352;
case 0x0c067354u: goto P_0c067354;
case 0x0c067356u: goto P_0c067356;
case 0x0c067358u: goto P_0c067358;
case 0x0c06735au: goto P_0c06735a;
case 0x0c06735cu: goto P_0c06735c;
case 0x0c06735eu: goto P_0c06735e;
case 0x0c067360u: goto P_0c067360;
case 0x0c067362u: goto P_0c067362;
case 0x0c067364u: goto P_0c067364;
case 0x0c067366u: goto P_0c067366;
case 0x0c0673a8u: goto P_0c0673a8;
case 0x0c0673aau: goto P_0c0673aa;
case 0x0c0673acu: goto P_0c0673ac;
case 0x0c0673aeu: goto P_0c0673ae;
case 0x0c0673b0u: goto P_0c0673b0;
case 0x0c0673b2u: goto P_0c0673b2;
case 0x0c0673b4u: goto P_0c0673b4;
case 0x0c0673b6u: goto P_0c0673b6;
case 0x0c0673b8u: goto P_0c0673b8;
case 0x0c0673bau: goto P_0c0673ba;
case 0x0c0673bcu: goto P_0c0673bc;
case 0x0c0673beu: goto P_0c0673be;
case 0x0c0673c0u: goto P_0c0673c0;
case 0x0c0673c2u: goto P_0c0673c2;
case 0x0c0673c4u: goto P_0c0673c4;
case 0x0c0673c6u: goto P_0c0673c6;
case 0x0c0673c8u: goto P_0c0673c8;
case 0x0c0673cau: goto P_0c0673ca;
case 0x0c0673ccu: goto P_0c0673cc;
case 0x0c0673ceu: goto P_0c0673ce;
case 0x0c0673d0u: goto P_0c0673d0;
case 0x0c0673d2u: goto P_0c0673d2;
case 0x0c0673d4u: goto P_0c0673d4;
case 0x0c0673d6u: goto P_0c0673d6;
case 0x0c0673d8u: goto P_0c0673d8;
case 0x0c0673dau: goto P_0c0673da;
case 0x0c0673dcu: goto P_0c0673dc;
case 0x0c0673deu: goto P_0c0673de;
case 0x0c0673e0u: goto P_0c0673e0;
case 0x0c0673e2u: goto P_0c0673e2;
case 0x0c0673e4u: goto P_0c0673e4;
case 0x0c0673e6u: goto P_0c0673e6;
case 0x0c0673e8u: goto P_0c0673e8;
case 0x0c0673eau: goto P_0c0673ea;
case 0x0c0673ecu: goto P_0c0673ec;
case 0x0c0673eeu: goto P_0c0673ee;
case 0x0c0673f0u: goto P_0c0673f0;
case 0x0c0673f2u: goto P_0c0673f2;
case 0x0c0673f4u: goto P_0c0673f4;
case 0x0c0673f6u: goto P_0c0673f6;
case 0x0c0673f8u: goto P_0c0673f8;
case 0x0c0673fau: goto P_0c0673fa;
case 0x0c0673fcu: goto P_0c0673fc;
case 0x0c0673feu: goto P_0c0673fe;
case 0x0c067400u: goto P_0c067400;
case 0x0c067402u: goto P_0c067402;
case 0x0c067404u: goto P_0c067404;
case 0x0c067406u: goto P_0c067406;
case 0x0c067408u: goto P_0c067408;
case 0x0c06740au: goto P_0c06740a;
case 0x0c06740cu: goto P_0c06740c;
case 0x0c06740eu: goto P_0c06740e;
case 0x0c067410u: goto P_0c067410;
case 0x0c067412u: goto P_0c067412;
case 0x0c067414u: goto P_0c067414;
case 0x0c067416u: goto P_0c067416;
case 0x0c067418u: goto P_0c067418;
case 0x0c06741au: goto P_0c06741a;
case 0x0c06741cu: goto P_0c06741c;
case 0x0c06741eu: goto P_0c06741e;
case 0x0c067420u: goto P_0c067420;
case 0x0c067422u: goto P_0c067422;
case 0x0c067424u: goto P_0c067424;
case 0x0c067426u: goto P_0c067426;
case 0x0c067428u: goto P_0c067428;
case 0x0c06742au: goto P_0c06742a;
case 0x0c06742cu: goto P_0c06742c;
case 0x0c06742eu: goto P_0c06742e;
case 0x0c067430u: goto P_0c067430;
case 0x0c067432u: goto P_0c067432;
case 0x0c067434u: goto P_0c067434;
case 0x0c067436u: goto P_0c067436;
case 0x0c067438u: goto P_0c067438;
case 0x0c06743au: goto P_0c06743a;
case 0x0c06743cu: goto P_0c06743c;
case 0x0c06743eu: goto P_0c06743e;
case 0x0c067440u: goto P_0c067440;
case 0x0c067468u: goto P_0c067468;
case 0x0c06746au: goto P_0c06746a;
case 0x0c06746cu: goto P_0c06746c;
case 0x0c06746eu: goto P_0c06746e;
case 0x0c067470u: goto P_0c067470;
case 0x0c067472u: goto P_0c067472;
case 0x0c067474u: goto P_0c067474;
case 0x0c067476u: goto P_0c067476;
case 0x0c067478u: goto P_0c067478;
case 0x0c06747au: goto P_0c06747a;
case 0x0c06747cu: goto P_0c06747c;
case 0x0c06747eu: goto P_0c06747e;
case 0x0c067480u: goto P_0c067480;
case 0x0c067482u: goto P_0c067482;
case 0x0c067484u: goto P_0c067484;
case 0x0c067486u: goto P_0c067486;
case 0x0c067488u: goto P_0c067488;
case 0x0c06748au: goto P_0c06748a;
case 0x0c06748cu: goto P_0c06748c;
case 0x0c06748eu: goto P_0c06748e;
case 0x0c067490u: goto P_0c067490;
case 0x0c067492u: goto P_0c067492;
case 0x0c067494u: goto P_0c067494;
case 0x0c067496u: goto P_0c067496;
case 0x0c067498u: goto P_0c067498;
case 0x0c06749au: goto P_0c06749a;
case 0x0c06749cu: goto P_0c06749c;
case 0x0c06749eu: goto P_0c06749e;
case 0x0c0674a0u: goto P_0c0674a0;
case 0x0c0674a2u: goto P_0c0674a2;
case 0x0c0674a4u: goto P_0c0674a4;
case 0x0c0674a6u: goto P_0c0674a6;
case 0x0c0674a8u: goto P_0c0674a8;
case 0x0c0674aau: goto P_0c0674aa;
case 0x0c0674acu: goto P_0c0674ac;
case 0x0c0674aeu: goto P_0c0674ae;
case 0x0c0674b0u: goto P_0c0674b0;
case 0x0c0674b2u: goto P_0c0674b2;
case 0x0c0674b4u: goto P_0c0674b4;
case 0x0c0674b6u: goto P_0c0674b6;
case 0x0c0674b8u: goto P_0c0674b8;
case 0x0c0674bau: goto P_0c0674ba;
case 0x0c0674bcu: goto P_0c0674bc;
case 0x0c0674beu: goto P_0c0674be;
case 0x0c0674c0u: goto P_0c0674c0;
case 0x0c0674c2u: goto P_0c0674c2;
case 0x0c0674c4u: goto P_0c0674c4;
case 0x0c0674c6u: goto P_0c0674c6;
case 0x0c0674c8u: goto P_0c0674c8;
case 0x0c0674cau: goto P_0c0674ca;
case 0x0c0674ccu: goto P_0c0674cc;
case 0x0c0674ceu: goto P_0c0674ce;
case 0x0c0674d0u: goto P_0c0674d0;
case 0x0c0674d2u: goto P_0c0674d2;
case 0x0c0674d4u: goto P_0c0674d4;
case 0x0c0674d6u: goto P_0c0674d6;
case 0x0c0674d8u: goto P_0c0674d8;
case 0x0c0674dau: goto P_0c0674da;
case 0x0c0674dcu: goto P_0c0674dc;
case 0x0c0674deu: goto P_0c0674de;
case 0x0c0674e0u: goto P_0c0674e0;
case 0x0c0674e2u: goto P_0c0674e2;
case 0x0c0674e4u: goto P_0c0674e4;
case 0x0c0674e6u: goto P_0c0674e6;
case 0x0c0674e8u: goto P_0c0674e8;
case 0x0c0674eau: goto P_0c0674ea;
case 0x0c0674ecu: goto P_0c0674ec;
case 0x0c0674eeu: goto P_0c0674ee;
case 0x0c0674f0u: goto P_0c0674f0;
case 0x0c0674f2u: goto P_0c0674f2;
case 0x0c0674f4u: goto P_0c0674f4;
case 0x0c0674f6u: goto P_0c0674f6;
case 0x0c0674f8u: goto P_0c0674f8;
case 0x0c0674fau: goto P_0c0674fa;
case 0x0c0674fcu: goto P_0c0674fc;
case 0x0c0674feu: goto P_0c0674fe;
case 0x0c067562u: goto P_0c067562;
case 0x0c067564u: goto P_0c067564;
case 0x0c06758au: goto P_0c06758a;
case 0x0c06758cu: goto P_0c06758c;
case 0x0c0675d4u: goto P_0c0675d4;
case 0x0c0675d6u: goto P_0c0675d6;
case 0x0c0675deu: goto P_0c0675de;
case 0x0c0675e0u: goto P_0c0675e0;
case 0x0c0675e2u: goto P_0c0675e2;
case 0x0c0675e4u: goto P_0c0675e4;
case 0x0c0675e6u: goto P_0c0675e6;
case 0x0c0675fcu: goto P_0c0675fc;
case 0x0c0675feu: goto P_0c0675fe;
case 0x0c067600u: goto P_0c067600;
case 0x0c067602u: goto P_0c067602;
case 0x0c067604u: goto P_0c067604;
case 0x0c067606u: goto P_0c067606;
case 0x0c067608u: goto P_0c067608;
case 0x0c06760au: goto P_0c06760a;
case 0x0c06760cu: goto P_0c06760c;
case 0x0c06760eu: goto P_0c06760e;
case 0x0c067610u: goto P_0c067610;
case 0x0c06763cu: goto P_0c06763c;
case 0x0c06763eu: goto P_0c06763e;
case 0x0c067640u: goto P_0c067640;
case 0x0c067642u: goto P_0c067642;
case 0x0c067644u: goto P_0c067644;
case 0x0c067646u: goto P_0c067646;
case 0x0c067648u: goto P_0c067648;
case 0x0c06764au: goto P_0c06764a;
case 0x0c06764cu: goto P_0c06764c;
case 0x0c06764eu: goto P_0c06764e;
case 0x0c067650u: goto P_0c067650;
case 0x0c067652u: goto P_0c067652;
case 0x0c067654u: goto P_0c067654;
case 0x0c067656u: goto P_0c067656;
case 0x0c067658u: goto P_0c067658;
case 0x0c06765au: goto P_0c06765a;
case 0x0c06765cu: goto P_0c06765c;
case 0x0c06765eu: goto P_0c06765e;
case 0x0c067660u: goto P_0c067660;
case 0x0c067662u: goto P_0c067662;
case 0x0c067664u: goto P_0c067664;
case 0x0c067666u: goto P_0c067666;
case 0x0c067668u: goto P_0c067668;
case 0x0c06766au: goto P_0c06766a;
case 0x0c06766cu: goto P_0c06766c;
case 0x0c06766eu: goto P_0c06766e;
case 0x0c067670u: goto P_0c067670;
case 0x0c067672u: goto P_0c067672;
case 0x0c067674u: goto P_0c067674;
case 0x0c067676u: goto P_0c067676;
case 0x0c067678u: goto P_0c067678;
case 0x0c06767au: goto P_0c06767a;
case 0x0c06767cu: goto P_0c06767c;
case 0x0c06767eu: goto P_0c06767e;
case 0x0c067680u: goto P_0c067680;
case 0x0c067682u: goto P_0c067682;
case 0x0c067684u: goto P_0c067684;
case 0x0c067686u: goto P_0c067686;
case 0x0c067688u: goto P_0c067688;
case 0x0c06768au: goto P_0c06768a;
case 0x0c06768cu: goto P_0c06768c;
case 0x0c06768eu: goto P_0c06768e;
case 0x0c067690u: goto P_0c067690;
case 0x0c067692u: goto P_0c067692;
case 0x0c067694u: goto P_0c067694;
case 0x0c067696u: goto P_0c067696;
case 0x0c067698u: goto P_0c067698;
case 0x0c06769au: goto P_0c06769a;
case 0x0c06769cu: goto P_0c06769c;
case 0x0c06769eu: goto P_0c06769e;
case 0x0c0676a0u: goto P_0c0676a0;
case 0x0c0676a2u: goto P_0c0676a2;
case 0x0c0676a4u: goto P_0c0676a4;
case 0x0c0676a6u: goto P_0c0676a6;
case 0x0c0676a8u: goto P_0c0676a8;
case 0x0c0676aau: goto P_0c0676aa;
case 0x0c0676acu: goto P_0c0676ac;
case 0x0c0676aeu: goto P_0c0676ae;
case 0x0c0676b0u: goto P_0c0676b0;
case 0x0c0676b2u: goto P_0c0676b2;
case 0x0c0676b4u: goto P_0c0676b4;
case 0x0c0676b6u: goto P_0c0676b6;
case 0x0c0676b8u: goto P_0c0676b8;
case 0x0c0676bau: goto P_0c0676ba;
case 0x0c0676bcu: goto P_0c0676bc;
case 0x0c0676beu: goto P_0c0676be;
case 0x0c0676c0u: goto P_0c0676c0;
case 0x0c0676c2u: goto P_0c0676c2;
case 0x0c0676c4u: goto P_0c0676c4;
case 0x0c0676c6u: goto P_0c0676c6;
case 0x0c0676c8u: goto P_0c0676c8;
case 0x0c0676cau: goto P_0c0676ca;
case 0x0c0676ccu: goto P_0c0676cc;
case 0x0c0676ceu: goto P_0c0676ce;
case 0x0c0676d0u: goto P_0c0676d0;
case 0x0c0676d2u: goto P_0c0676d2;
case 0x0c0676d4u: goto P_0c0676d4;
case 0x0c0676d6u: goto P_0c0676d6;
case 0x0c0676d8u: goto P_0c0676d8;
case 0x0c0676dau: goto P_0c0676da;
case 0x0c0676dcu: goto P_0c0676dc;
case 0x0c0676deu: goto P_0c0676de;
case 0x0c0676e0u: goto P_0c0676e0;
case 0x0c0676e2u: goto P_0c0676e2;
case 0x0c0676e4u: goto P_0c0676e4;
case 0x0c0676e6u: goto P_0c0676e6;
case 0x0c0676e8u: goto P_0c0676e8;
case 0x0c0676eau: goto P_0c0676ea;
case 0x0c0676ecu: goto P_0c0676ec;
case 0x0c0676eeu: goto P_0c0676ee;
case 0x0c0676f0u: goto P_0c0676f0;
case 0x0c0676f2u: goto P_0c0676f2;
case 0x0c0676f4u: goto P_0c0676f4;
case 0x0c0676f6u: goto P_0c0676f6;
case 0x0c0676f8u: goto P_0c0676f8;
case 0x0c0676fau: goto P_0c0676fa;
case 0x0c0676fcu: goto P_0c0676fc;
case 0x0c0676feu: goto P_0c0676fe;
case 0x0c067700u: goto P_0c067700;
case 0x0c067702u: goto P_0c067702;
case 0x0c067704u: goto P_0c067704;
case 0x0c067706u: goto P_0c067706;
case 0x0c067708u: goto P_0c067708;
case 0x0c06770au: goto P_0c06770a;
case 0x0c06770cu: goto P_0c06770c;
case 0x0c06770eu: goto P_0c06770e;
case 0x0c067710u: goto P_0c067710;
case 0x0c067712u: goto P_0c067712;
case 0x0c06773cu: goto P_0c06773c;
case 0x0c06773eu: goto P_0c06773e;
case 0x0c067740u: goto P_0c067740;
case 0x0c067742u: goto P_0c067742;
case 0x0c067744u: goto P_0c067744;
case 0x0c067746u: goto P_0c067746;
case 0x0c067748u: goto P_0c067748;
case 0x0c06774au: goto P_0c06774a;
case 0x0c06774cu: goto P_0c06774c;
case 0x0c06774eu: goto P_0c06774e;
case 0x0c067750u: goto P_0c067750;
case 0x0c067752u: goto P_0c067752;
case 0x0c067754u: goto P_0c067754;
case 0x0c067756u: goto P_0c067756;
case 0x0c067758u: goto P_0c067758;
case 0x0c06775au: goto P_0c06775a;
case 0x0c06775cu: goto P_0c06775c;
case 0x0c06775eu: goto P_0c06775e;
case 0x0c067760u: goto P_0c067760;
case 0x0c067762u: goto P_0c067762;
case 0x0c067764u: goto P_0c067764;
case 0x0c067766u: goto P_0c067766;
case 0x0c067768u: goto P_0c067768;
case 0x0c06776au: goto P_0c06776a;
case 0x0c06776cu: goto P_0c06776c;
case 0x0c06776eu: goto P_0c06776e;
case 0x0c067770u: goto P_0c067770;
case 0x0c067772u: goto P_0c067772;
case 0x0c067774u: goto P_0c067774;
case 0x0c067776u: goto P_0c067776;
case 0x0c067778u: goto P_0c067778;
case 0x0c06777au: goto P_0c06777a;
case 0x0c06777cu: goto P_0c06777c;
case 0x0c06777eu: goto P_0c06777e;
case 0x0c067780u: goto P_0c067780;
case 0x0c067782u: goto P_0c067782;
case 0x0c067784u: goto P_0c067784;
case 0x0c067786u: goto P_0c067786;
case 0x0c067788u: goto P_0c067788;
case 0x0c06778au: goto P_0c06778a;
case 0x0c06778cu: goto P_0c06778c;
case 0x0c06778eu: goto P_0c06778e;
case 0x0c067790u: goto P_0c067790;
case 0x0c067792u: goto P_0c067792;
case 0x0c067794u: goto P_0c067794;
case 0x0c067796u: goto P_0c067796;
case 0x0c067798u: goto P_0c067798;
case 0x0c06779au: goto P_0c06779a;
case 0x0c06779cu: goto P_0c06779c;
case 0x0c06779eu: goto P_0c06779e;
case 0x0c0677a0u: goto P_0c0677a0;
case 0x0c0677a2u: goto P_0c0677a2;
case 0x0c0677a4u: goto P_0c0677a4;
case 0x0c0677a6u: goto P_0c0677a6;
case 0x0c0677a8u: goto P_0c0677a8;
case 0x0c0677aau: goto P_0c0677aa;
case 0x0c0677acu: goto P_0c0677ac;
case 0x0c0677aeu: goto P_0c0677ae;
case 0x0c0677b0u: goto P_0c0677b0;
case 0x0c0677b2u: goto P_0c0677b2;
case 0x0c0677b4u: goto P_0c0677b4;
case 0x0c0677b6u: goto P_0c0677b6;
case 0x0c0677b8u: goto P_0c0677b8;
case 0x0c0677bau: goto P_0c0677ba;
case 0x0c0677bcu: goto P_0c0677bc;
case 0x0c0677beu: goto P_0c0677be;
case 0x0c0677c0u: goto P_0c0677c0;
case 0x0c0677c2u: goto P_0c0677c2;
case 0x0c0677c4u: goto P_0c0677c4;
case 0x0c0677c6u: goto P_0c0677c6;
case 0x0c0677c8u: goto P_0c0677c8;
case 0x0c0677cau: goto P_0c0677ca;
case 0x0c0677ccu: goto P_0c0677cc;
case 0x0c0677ceu: goto P_0c0677ce;
case 0x0c0677d0u: goto P_0c0677d0;
case 0x0c0677d2u: goto P_0c0677d2;
case 0x0c0677d4u: goto P_0c0677d4;
case 0x0c0677d6u: goto P_0c0677d6;
case 0x0c0677d8u: goto P_0c0677d8;
case 0x0c0677dau: goto P_0c0677da;
case 0x0c0677dcu: goto P_0c0677dc;
case 0x0c0677deu: goto P_0c0677de;
case 0x0c0677e0u: goto P_0c0677e0;
case 0x0c0677e2u: goto P_0c0677e2;
case 0x0c0677e4u: goto P_0c0677e4;
case 0x0c0677e6u: goto P_0c0677e6;
case 0x0c0677e8u: goto P_0c0677e8;
case 0x0c0677eau: goto P_0c0677ea;
case 0x0c0677ecu: goto P_0c0677ec;
case 0x0c0677eeu: goto P_0c0677ee;
case 0x0c0677f0u: goto P_0c0677f0;
case 0x0c0677f2u: goto P_0c0677f2;
case 0x0c0677f4u: goto P_0c0677f4;
case 0x0c0677f6u: goto P_0c0677f6;
case 0x0c0677f8u: goto P_0c0677f8;
case 0x0c0677fau: goto P_0c0677fa;
case 0x0c0677fcu: goto P_0c0677fc;
case 0x0c0677feu: goto P_0c0677fe;
case 0x0c067800u: goto P_0c067800;
case 0x0c067802u: goto P_0c067802;
case 0x0c067804u: goto P_0c067804;
case 0x0c067806u: goto P_0c067806;
case 0x0c067808u: goto P_0c067808;
case 0x0c06780au: goto P_0c06780a;
case 0x0c06780cu: goto P_0c06780c;
case 0x0c06780eu: goto P_0c06780e;
case 0x0c067810u: goto P_0c067810;
case 0x0c067812u: goto P_0c067812;
case 0x0c067814u: goto P_0c067814;
case 0x0c067816u: goto P_0c067816;
case 0x0c067818u: goto P_0c067818;
case 0x0c06781au: goto P_0c06781a;
case 0x0c06781cu: goto P_0c06781c;
case 0x0c06781eu: goto P_0c06781e;
case 0x0c067820u: goto P_0c067820;
case 0x0c067822u: goto P_0c067822;
case 0x0c067824u: goto P_0c067824;
case 0x0c067826u: goto P_0c067826;
case 0x0c067828u: goto P_0c067828;
case 0x0c06782au: goto P_0c06782a;
case 0x0c06782cu: goto P_0c06782c;
case 0x0c06782eu: goto P_0c06782e;
case 0x0c067830u: goto P_0c067830;
case 0x0c067832u: goto P_0c067832;
case 0x0c067834u: goto P_0c067834;
case 0x0c067836u: goto P_0c067836;
case 0x0c067838u: goto P_0c067838;
case 0x0c06783au: goto P_0c06783a;
case 0x0c06783cu: goto P_0c06783c;
case 0x0c06783eu: goto P_0c06783e;
case 0x0c067840u: goto P_0c067840;
case 0x0c067894u: goto P_0c067894;
case 0x0c067896u: goto P_0c067896;
case 0x0c067898u: goto P_0c067898;
case 0x0c06789au: goto P_0c06789a;
case 0x0c06789cu: goto P_0c06789c;
case 0x0c06789eu: goto P_0c06789e;
case 0x0c0678a0u: goto P_0c0678a0;
case 0x0c0678a2u: goto P_0c0678a2;
case 0x0c0678a4u: goto P_0c0678a4;
case 0x0c0678a6u: goto P_0c0678a6;
case 0x0c0678a8u: goto P_0c0678a8;
case 0x0c0678aau: goto P_0c0678aa;
case 0x0c0678acu: goto P_0c0678ac;
case 0x0c0678aeu: goto P_0c0678ae;
case 0x0c0678b0u: goto P_0c0678b0;
case 0x0c0678b2u: goto P_0c0678b2;
case 0x0c0678b4u: goto P_0c0678b4;
case 0x0c0678b6u: goto P_0c0678b6;
case 0x0c0678b8u: goto P_0c0678b8;
case 0x0c0678bau: goto P_0c0678ba;
case 0x0c0678bcu: goto P_0c0678bc;
case 0x0c0678beu: goto P_0c0678be;
case 0x0c0678c0u: goto P_0c0678c0;
case 0x0c0678c2u: goto P_0c0678c2;
case 0x0c0678c4u: goto P_0c0678c4;
case 0x0c0678c6u: goto P_0c0678c6;
case 0x0c0678c8u: goto P_0c0678c8;
case 0x0c0678cau: goto P_0c0678ca;
case 0x0c0678ccu: goto P_0c0678cc;
case 0x0c0678ceu: goto P_0c0678ce;
case 0x0c0678d0u: goto P_0c0678d0;
case 0x0c0678d2u: goto P_0c0678d2;
case 0x0c0678d4u: goto P_0c0678d4;
case 0x0c0678d6u: goto P_0c0678d6;
case 0x0c0678d8u: goto P_0c0678d8;
case 0x0c0678dau: goto P_0c0678da;
case 0x0c0678dcu: goto P_0c0678dc;
case 0x0c0678deu: goto P_0c0678de;
case 0x0c0678e0u: goto P_0c0678e0;
case 0x0c0678e2u: goto P_0c0678e2;
case 0x0c0678e4u: goto P_0c0678e4;
case 0x0c0678e6u: goto P_0c0678e6;
case 0x0c0678e8u: goto P_0c0678e8;
case 0x0c0678eau: goto P_0c0678ea;
case 0x0c0678ecu: goto P_0c0678ec;
case 0x0c0678eeu: goto P_0c0678ee;
case 0x0c0678f0u: goto P_0c0678f0;
case 0x0c0678f2u: goto P_0c0678f2;
case 0x0c0678f4u: goto P_0c0678f4;
case 0x0c0678f6u: goto P_0c0678f6;
case 0x0c067ea8u: goto P_0c067ea8;
case 0x0c067eaau: goto P_0c067eaa;
case 0x0c067eacu: goto P_0c067eac;
case 0x0c067eaeu: goto P_0c067eae;
case 0x0c067eb0u: goto P_0c067eb0;
case 0x0c067eb2u: goto P_0c067eb2;
case 0x0c067eb4u: goto P_0c067eb4;
case 0x0c067eb6u: goto P_0c067eb6;
case 0x0c067eb8u: goto P_0c067eb8;
case 0x0c067ebau: goto P_0c067eba;
case 0x0c067ebcu: goto P_0c067ebc;
case 0x0c067ebeu: goto P_0c067ebe;
case 0x0c067ec0u: goto P_0c067ec0;
case 0x0c067ec2u: goto P_0c067ec2;
case 0x0c067ec4u: goto P_0c067ec4;
case 0x0c067ec6u: goto P_0c067ec6;
case 0x0c067ec8u: goto P_0c067ec8;
case 0x0c067ecau: goto P_0c067eca;
case 0x0c067eccu: goto P_0c067ecc;
case 0x0c067eceu: goto P_0c067ece;
case 0x0c067ed0u: goto P_0c067ed0;
case 0x0c067ed2u: goto P_0c067ed2;
case 0x0c067ed4u: goto P_0c067ed4;
case 0x0c067ed6u: goto P_0c067ed6;
case 0x0c067ed8u: goto P_0c067ed8;
case 0x0c067edau: goto P_0c067eda;
case 0x0c067edcu: goto P_0c067edc;
case 0x0c067edeu: goto P_0c067ede;
case 0x0c067ee0u: goto P_0c067ee0;
case 0x0c067ee2u: goto P_0c067ee2;
case 0x0c067ee4u: goto P_0c067ee4;
case 0x0c067ee6u: goto P_0c067ee6;
case 0x0c067ee8u: goto P_0c067ee8;
case 0x0c067eeau: goto P_0c067eea;
case 0x0c067eecu: goto P_0c067eec;
case 0x0c067eeeu: goto P_0c067eee;
case 0x0c0681ccu: goto P_0c0681cc;
case 0x0c0681ceu: goto P_0c0681ce;
case 0x0c0681d0u: goto P_0c0681d0;
case 0x0c0681d2u: goto P_0c0681d2;
case 0x0c0681d4u: goto P_0c0681d4;
case 0x0c0681d6u: goto P_0c0681d6;
case 0x0c0681d8u: goto P_0c0681d8;
case 0x0c0681dau: goto P_0c0681da;
case 0x0c0681dcu: goto P_0c0681dc;
case 0x0c0681deu: goto P_0c0681de;
case 0x0c0681e0u: goto P_0c0681e0;
case 0x0c0681e2u: goto P_0c0681e2;
case 0x0c0681e4u: goto P_0c0681e4;
case 0x0c0681e6u: goto P_0c0681e6;
case 0x0c0681e8u: goto P_0c0681e8;
case 0x0c0681eau: goto P_0c0681ea;
case 0x0c0681ecu: goto P_0c0681ec;
case 0x0c0681eeu: goto P_0c0681ee;
case 0x0c0681f0u: goto P_0c0681f0;
case 0x0c0681f2u: goto P_0c0681f2;
case 0x0c0681f4u: goto P_0c0681f4;
case 0x0c0681f6u: goto P_0c0681f6;
case 0x0c0681f8u: goto P_0c0681f8;
case 0x0c0681fau: goto P_0c0681fa;
case 0x0c0681fcu: goto P_0c0681fc;
case 0x0c0681feu: goto P_0c0681fe;
case 0x0c068200u: goto P_0c068200;
case 0x0c068202u: goto P_0c068202;
case 0x0c068204u: goto P_0c068204;
case 0x0c068206u: goto P_0c068206;
case 0x0c068208u: goto P_0c068208;
case 0x0c06820au: goto P_0c06820a;
case 0x0c06820cu: goto P_0c06820c;
case 0x0c06820eu: goto P_0c06820e;
case 0x0c068210u: goto P_0c068210;
case 0x0c068212u: goto P_0c068212;
case 0x0c068214u: goto P_0c068214;
case 0x0c068216u: goto P_0c068216;
case 0x0c068218u: goto P_0c068218;
case 0x0c06821au: goto P_0c06821a;
case 0x0c06821cu: goto P_0c06821c;
case 0x0c06821eu: goto P_0c06821e;
case 0x0c068220u: goto P_0c068220;
case 0x0c068222u: goto P_0c068222;
case 0x0c068224u: goto P_0c068224;
case 0x0c068226u: goto P_0c068226;
case 0x0c068228u: goto P_0c068228;
case 0x0c06822au: goto P_0c06822a;
case 0x0c06822cu: goto P_0c06822c;
case 0x0c06822eu: goto P_0c06822e;
case 0x0c068230u: goto P_0c068230;
case 0x0c068232u: goto P_0c068232;
case 0x0c068234u: goto P_0c068234;
case 0x0c068236u: goto P_0c068236;
case 0x0c068238u: goto P_0c068238;
case 0x0c06823au: goto P_0c06823a;
case 0x0c06823cu: goto P_0c06823c;
case 0x0c06823eu: goto P_0c06823e;
case 0x0c068240u: goto P_0c068240;
case 0x0c068242u: goto P_0c068242;
case 0x0c068244u: goto P_0c068244;
case 0x0c068246u: goto P_0c068246;
case 0x0c068248u: goto P_0c068248;
case 0x0c06824au: goto P_0c06824a;
case 0x0c06824cu: goto P_0c06824c;
case 0x0c06824eu: goto P_0c06824e;
case 0x0c068250u: goto P_0c068250;
case 0x0c068252u: goto P_0c068252;
case 0x0c068254u: goto P_0c068254;
case 0x0c068256u: goto P_0c068256;
case 0x0c068258u: goto P_0c068258;
case 0x0c06825au: goto P_0c06825a;
case 0x0c06825cu: goto P_0c06825c;
case 0x0c06825eu: goto P_0c06825e;
case 0x0c068260u: goto P_0c068260;
case 0x0c068262u: goto P_0c068262;
case 0x0c068264u: goto P_0c068264;
case 0x0c068266u: goto P_0c068266;
case 0x0c068268u: goto P_0c068268;
case 0x0c06826au: goto P_0c06826a;
case 0x0c06826cu: goto P_0c06826c;
case 0x0c06826eu: goto P_0c06826e;
case 0x0c068270u: goto P_0c068270;
case 0x0c068272u: goto P_0c068272;
case 0x0c068274u: goto P_0c068274;
case 0x0c068276u: goto P_0c068276;
case 0x0c068278u: goto P_0c068278;
case 0x0c06827au: goto P_0c06827a;
case 0x0c06827cu: goto P_0c06827c;
case 0x0c06827eu: goto P_0c06827e;
case 0x0c068280u: goto P_0c068280;
case 0x0c068282u: goto P_0c068282;
case 0x0c068284u: goto P_0c068284;
case 0x0c068286u: goto P_0c068286;
case 0x0c068288u: goto P_0c068288;
case 0x0c06828au: goto P_0c06828a;
case 0x0c06828cu: goto P_0c06828c;
case 0x0c06828eu: goto P_0c06828e;
case 0x0c068290u: goto P_0c068290;
case 0x0c068292u: goto P_0c068292;
case 0x0c068294u: goto P_0c068294;
case 0x0c068296u: goto P_0c068296;
case 0x0c068298u: goto P_0c068298;
case 0x0c06829au: goto P_0c06829a;
case 0x0c06829cu: goto P_0c06829c;
case 0x0c06829eu: goto P_0c06829e;
case 0x0c0685deu: goto P_0c0685de;
case 0x0c0685e0u: goto P_0c0685e0;
case 0x0c0685e2u: goto P_0c0685e2;
case 0x0c0685e4u: goto P_0c0685e4;
case 0x0c0685e6u: goto P_0c0685e6;
case 0x0c0685e8u: goto P_0c0685e8;
case 0x0c0685eau: goto P_0c0685ea;
case 0x0c0685ecu: goto P_0c0685ec;
case 0x0c0685eeu: goto P_0c0685ee;
case 0x0c0685f0u: goto P_0c0685f0;
case 0x0c06862au: goto P_0c06862a;
case 0x0c06862cu: goto P_0c06862c;
case 0x0c06862eu: goto P_0c06862e;
case 0x0c068630u: goto P_0c068630;
case 0x0c068632u: goto P_0c068632;
case 0x0c068634u: goto P_0c068634;
case 0x0c068636u: goto P_0c068636;
case 0x0c068638u: goto P_0c068638;
case 0x0c06863au: goto P_0c06863a;
case 0x0c06863cu: goto P_0c06863c;
case 0x0c06863eu: goto P_0c06863e;
case 0x0c068640u: goto P_0c068640;
case 0x0c068642u: goto P_0c068642;
case 0x0c068644u: goto P_0c068644;
case 0x0c068646u: goto P_0c068646;
case 0x0c068648u: goto P_0c068648;
case 0x0c06864au: goto P_0c06864a;
case 0x0c06864cu: goto P_0c06864c;
case 0x0c06864eu: goto P_0c06864e;
case 0x0c068650u: goto P_0c068650;
case 0x0c068652u: goto P_0c068652;
case 0x0c068654u: goto P_0c068654;
case 0x0c068656u: goto P_0c068656;
case 0x0c068658u: goto P_0c068658;
case 0x0c06865au: goto P_0c06865a;
case 0x0c06865cu: goto P_0c06865c;
case 0x0c06865eu: goto P_0c06865e;
case 0x0c068660u: goto P_0c068660;
case 0x0c068662u: goto P_0c068662;
case 0x0c068664u: goto P_0c068664;
case 0x0c068666u: goto P_0c068666;
case 0x0c068668u: goto P_0c068668;
case 0x0c06866au: goto P_0c06866a;
case 0x0c06866cu: goto P_0c06866c;
case 0x0c06866eu: goto P_0c06866e;
case 0x0c068670u: goto P_0c068670;
case 0x0c068672u: goto P_0c068672;
case 0x0c068674u: goto P_0c068674;
case 0x0c068676u: goto P_0c068676;
case 0x0c068678u: goto P_0c068678;
case 0x0c06867au: goto P_0c06867a;
case 0x0c06867cu: goto P_0c06867c;
case 0x0c06867eu: goto P_0c06867e;
case 0x0c068680u: goto P_0c068680;
case 0x0c068682u: goto P_0c068682;
case 0x0c068684u: goto P_0c068684;
case 0x0c068686u: goto P_0c068686;
case 0x0c068688u: goto P_0c068688;
case 0x0c06868au: goto P_0c06868a;
case 0x0c06868cu: goto P_0c06868c;
case 0x0c06868eu: goto P_0c06868e;
case 0x0c068690u: goto P_0c068690;
case 0x0c068692u: goto P_0c068692;
case 0x0c068694u: goto P_0c068694;
case 0x0c068696u: goto P_0c068696;
case 0x0c068698u: goto P_0c068698;
case 0x0c06869au: goto P_0c06869a;
case 0x0c06869cu: goto P_0c06869c;
case 0x0c06869eu: goto P_0c06869e;
case 0x0c0686a0u: goto P_0c0686a0;
case 0x0c0686a2u: goto P_0c0686a2;
case 0x0c0686a4u: goto P_0c0686a4;
case 0x0c0686a6u: goto P_0c0686a6;
case 0x0c0686a8u: goto P_0c0686a8;
case 0x0c0686aau: goto P_0c0686aa;
case 0x0c0686acu: goto P_0c0686ac;
case 0x0c0686aeu: goto P_0c0686ae;
case 0x0c0686b0u: goto P_0c0686b0;
case 0x0c0686b2u: goto P_0c0686b2;
case 0x0c0686b4u: goto P_0c0686b4;
case 0x0c0686b6u: goto P_0c0686b6;
case 0x0c0686b8u: goto P_0c0686b8;
case 0x0c0686bau: goto P_0c0686ba;
case 0x0c0686bcu: goto P_0c0686bc;
case 0x0c0686beu: goto P_0c0686be;
case 0x0c0686c0u: goto P_0c0686c0;
case 0x0c0686ecu: goto P_0c0686ec;
case 0x0c0686eeu: goto P_0c0686ee;
case 0x0c0686f0u: goto P_0c0686f0;
case 0x0c0686f2u: goto P_0c0686f2;
case 0x0c0686f4u: goto P_0c0686f4;
case 0x0c0686f6u: goto P_0c0686f6;
case 0x0c0686f8u: goto P_0c0686f8;
case 0x0c0686fau: goto P_0c0686fa;
case 0x0c0686fcu: goto P_0c0686fc;
case 0x0c0686feu: goto P_0c0686fe;
case 0x0c068700u: goto P_0c068700;
case 0x0c068702u: goto P_0c068702;
case 0x0c068704u: goto P_0c068704;
case 0x0c068706u: goto P_0c068706;
case 0x0c068708u: goto P_0c068708;
case 0x0c06870au: goto P_0c06870a;
case 0x0c06870cu: goto P_0c06870c;
case 0x0c06870eu: goto P_0c06870e;
case 0x0c068710u: goto P_0c068710;
case 0x0c068712u: goto P_0c068712;
case 0x0c068714u: goto P_0c068714;
case 0x0c068716u: goto P_0c068716;
case 0x0c068718u: goto P_0c068718;
case 0x0c06871au: goto P_0c06871a;
case 0x0c06871cu: goto P_0c06871c;
case 0x0c06871eu: goto P_0c06871e;
case 0x0c068720u: goto P_0c068720;
case 0x0c068722u: goto P_0c068722;
case 0x0c068724u: goto P_0c068724;
case 0x0c068726u: goto P_0c068726;
case 0x0c068728u: goto P_0c068728;
case 0x0c06872au: goto P_0c06872a;
case 0x0c06872cu: goto P_0c06872c;
case 0x0c06872eu: goto P_0c06872e;
case 0x0c068730u: goto P_0c068730;
case 0x0c068732u: goto P_0c068732;
case 0x0c068734u: goto P_0c068734;
case 0x0c068736u: goto P_0c068736;
case 0x0c068738u: goto P_0c068738;
case 0x0c06873au: goto P_0c06873a;
case 0x0c06873cu: goto P_0c06873c;
case 0x0c06873eu: goto P_0c06873e;
case 0x0c068740u: goto P_0c068740;
case 0x0c068742u: goto P_0c068742;
case 0x0c068744u: goto P_0c068744;
case 0x0c068746u: goto P_0c068746;
case 0x0c068748u: goto P_0c068748;
case 0x0c06874au: goto P_0c06874a;
case 0x0c06874cu: goto P_0c06874c;
case 0x0c06874eu: goto P_0c06874e;
case 0x0c068750u: goto P_0c068750;
case 0x0c068752u: goto P_0c068752;
case 0x0c068754u: goto P_0c068754;
case 0x0c068756u: goto P_0c068756;
case 0x0c068758u: goto P_0c068758;
case 0x0c06875au: goto P_0c06875a;
case 0x0c06875cu: goto P_0c06875c;
case 0x0c06875eu: goto P_0c06875e;
case 0x0c068760u: goto P_0c068760;
case 0x0c068762u: goto P_0c068762;
case 0x0c068764u: goto P_0c068764;
case 0x0c068766u: goto P_0c068766;
case 0x0c068768u: goto P_0c068768;
case 0x0c06876au: goto P_0c06876a;
case 0x0c06876cu: goto P_0c06876c;
case 0x0c06876eu: goto P_0c06876e;
case 0x0c068770u: goto P_0c068770;
case 0x0c068772u: goto P_0c068772;
case 0x0c068774u: goto P_0c068774;
case 0x0c068776u: goto P_0c068776;
case 0x0c068778u: goto P_0c068778;
case 0x0c06877au: goto P_0c06877a;
case 0x0c06877cu: goto P_0c06877c;
case 0x0c06877eu: goto P_0c06877e;
case 0x0c068780u: goto P_0c068780;
case 0x0c068782u: goto P_0c068782;
case 0x0c068784u: goto P_0c068784;
case 0x0c068786u: goto P_0c068786;
case 0x0c068788u: goto P_0c068788;
case 0x0c06878au: goto P_0c06878a;
case 0x0c06878cu: goto P_0c06878c;
case 0x0c06878eu: goto P_0c06878e;
case 0x0c068790u: goto P_0c068790;
case 0x0c068792u: goto P_0c068792;
case 0x0c068794u: goto P_0c068794;
case 0x0c068796u: goto P_0c068796;
case 0x0c068798u: goto P_0c068798;
case 0x0c06879au: goto P_0c06879a;
case 0x0c06879cu: goto P_0c06879c;
case 0x0c06879eu: goto P_0c06879e;
case 0x0c0687a0u: goto P_0c0687a0;
case 0x0c0687a2u: goto P_0c0687a2;
case 0x0c0687a4u: goto P_0c0687a4;
case 0x0c0687a6u: goto P_0c0687a6;
case 0x0c0687a8u: goto P_0c0687a8;
case 0x0c0687aau: goto P_0c0687aa;
case 0x0c0687acu: goto P_0c0687ac;
case 0x0c0687aeu: goto P_0c0687ae;
case 0x0c0687b0u: goto P_0c0687b0;
case 0x0c0687b2u: goto P_0c0687b2;
case 0x0c0687b4u: goto P_0c0687b4;
case 0x0c0687b6u: goto P_0c0687b6;
case 0x0c0687b8u: goto P_0c0687b8;
case 0x0c0687bau: goto P_0c0687ba;
case 0x0c0687bcu: goto P_0c0687bc;
case 0x0c0687beu: goto P_0c0687be;
case 0x0c0687c0u: goto P_0c0687c0;
case 0x0c0687c2u: goto P_0c0687c2;
case 0x0c0687c4u: goto P_0c0687c4;
case 0x0c0687c6u: goto P_0c0687c6;
case 0x0c0687c8u: goto P_0c0687c8;
case 0x0c0687cau: goto P_0c0687ca;
case 0x0c0687ccu: goto P_0c0687cc;
case 0x0c0687ceu: goto P_0c0687ce;
case 0x0c0687d0u: goto P_0c0687d0;
case 0x0c0687d2u: goto P_0c0687d2;
case 0x0c0687d4u: goto P_0c0687d4;
case 0x0c0687d6u: goto P_0c0687d6;
case 0x0c0687d8u: goto P_0c0687d8;
case 0x0c0687dau: goto P_0c0687da;
case 0x0c0687dcu: goto P_0c0687dc;
case 0x0c0687deu: goto P_0c0687de;
case 0x0c0687e0u: goto P_0c0687e0;
case 0x0c0687e2u: goto P_0c0687e2;
case 0x0c0687eau: goto P_0c0687ea;
case 0x0c0687ecu: goto P_0c0687ec;
case 0x0c0687eeu: goto P_0c0687ee;
case 0x0c0687f0u: goto P_0c0687f0;
case 0x0c0687f2u: goto P_0c0687f2;
case 0x0c0687f4u: goto P_0c0687f4;
case 0x0c0687f6u: goto P_0c0687f6;
case 0x0c0687f8u: goto P_0c0687f8;
case 0x0c0687fau: goto P_0c0687fa;
case 0x0c0687fcu: goto P_0c0687fc;
case 0x0c0687feu: goto P_0c0687fe;
case 0x0c068800u: goto P_0c068800;
case 0x0c068802u: goto P_0c068802;
case 0x0c068804u: goto P_0c068804;
case 0x0c068806u: goto P_0c068806;
case 0x0c068808u: goto P_0c068808;
case 0x0c06880au: goto P_0c06880a;
case 0x0c06880cu: goto P_0c06880c;
case 0x0c06880eu: goto P_0c06880e;
case 0x0c068810u: goto P_0c068810;
case 0x0c068812u: goto P_0c068812;
case 0x0c068814u: goto P_0c068814;
case 0x0c068816u: goto P_0c068816;
case 0x0c068818u: goto P_0c068818;
case 0x0c06881au: goto P_0c06881a;
case 0x0c06881cu: goto P_0c06881c;
case 0x0c06881eu: goto P_0c06881e;
case 0x0c068820u: goto P_0c068820;
case 0x0c068822u: goto P_0c068822;
case 0x0c068824u: goto P_0c068824;
case 0x0c068826u: goto P_0c068826;
case 0x0c068828u: goto P_0c068828;
case 0x0c06882au: goto P_0c06882a;
case 0x0c06882cu: goto P_0c06882c;
case 0x0c06882eu: goto P_0c06882e;
case 0x0c068830u: goto P_0c068830;
case 0x0c068832u: goto P_0c068832;
case 0x0c068834u: goto P_0c068834;
case 0x0c068836u: goto P_0c068836;
case 0x0c068838u: goto P_0c068838;
case 0x0c06883au: goto P_0c06883a;
case 0x0c06883cu: goto P_0c06883c;
case 0x0c06883eu: goto P_0c06883e;
case 0x0c068840u: goto P_0c068840;
case 0x0c068842u: goto P_0c068842;
case 0x0c068844u: goto P_0c068844;
case 0x0c068846u: goto P_0c068846;
case 0x0c068848u: goto P_0c068848;
case 0x0c06884au: goto P_0c06884a;
case 0x0c06884cu: goto P_0c06884c;
case 0x0c06884eu: goto P_0c06884e;
case 0x0c068850u: goto P_0c068850;
case 0x0c068852u: goto P_0c068852;
case 0x0c068854u: goto P_0c068854;
case 0x0c068856u: goto P_0c068856;
case 0x0c068858u: goto P_0c068858;
case 0x0c06885au: goto P_0c06885a;
case 0x0c06885cu: goto P_0c06885c;
case 0x0c06885eu: goto P_0c06885e;
case 0x0c068860u: goto P_0c068860;
case 0x0c068862u: goto P_0c068862;
case 0x0c068864u: goto P_0c068864;
case 0x0c068866u: goto P_0c068866;
case 0x0c068868u: goto P_0c068868;
case 0x0c06886au: goto P_0c06886a;
case 0x0c06886cu: goto P_0c06886c;
case 0x0c06886eu: goto P_0c06886e;
case 0x0c068870u: goto P_0c068870;
case 0x0c068872u: goto P_0c068872;
case 0x0c068874u: goto P_0c068874;
case 0x0c068876u: goto P_0c068876;
case 0x0c068878u: goto P_0c068878;
case 0x0c06887au: goto P_0c06887a;
case 0x0c06887cu: goto P_0c06887c;
case 0x0c06887eu: goto P_0c06887e;
case 0x0c068880u: goto P_0c068880;
case 0x0c068882u: goto P_0c068882;
case 0x0c068884u: goto P_0c068884;
case 0x0c068886u: goto P_0c068886;
case 0x0c068888u: goto P_0c068888;
case 0x0c06888au: goto P_0c06888a;
case 0x0c06888cu: goto P_0c06888c;
case 0x0c06888eu: goto P_0c06888e;
case 0x0c068890u: goto P_0c068890;
case 0x0c068892u: goto P_0c068892;
case 0x0c068894u: goto P_0c068894;
case 0x0c068896u: goto P_0c068896;
case 0x0c068898u: goto P_0c068898;
case 0x0c06889au: goto P_0c06889a;
case 0x0c06889cu: goto P_0c06889c;
case 0x0c06889eu: goto P_0c06889e;
case 0x0c0688a0u: goto P_0c0688a0;
case 0x0c0688a2u: goto P_0c0688a2;
case 0x0c0688a4u: goto P_0c0688a4;
case 0x0c0688a6u: goto P_0c0688a6;
case 0x0c0688a8u: goto P_0c0688a8;
case 0x0c0688aau: goto P_0c0688aa;
case 0x0c0688acu: goto P_0c0688ac;
case 0x0c0688aeu: goto P_0c0688ae;
case 0x0c0688b0u: goto P_0c0688b0;
case 0x0c0688b2u: goto P_0c0688b2;
case 0x0c0688b4u: goto P_0c0688b4;
case 0x0c0688b6u: goto P_0c0688b6;
case 0x0c0688b8u: goto P_0c0688b8;
case 0x0c0688bau: goto P_0c0688ba;
case 0x0c0688bcu: goto P_0c0688bc;
case 0x0c0688beu: goto P_0c0688be;
case 0x0c0688c0u: goto P_0c0688c0;
case 0x0c0688c2u: goto P_0c0688c2;
case 0x0c0688c4u: goto P_0c0688c4;
case 0x0c0688c6u: goto P_0c0688c6;
case 0x0c0688c8u: goto P_0c0688c8;
case 0x0c0688cau: goto P_0c0688ca;
case 0x0c0688ccu: goto P_0c0688cc;
case 0x0c0688ceu: goto P_0c0688ce;
case 0x0c0688d0u: goto P_0c0688d0;
case 0x0c0688d2u: goto P_0c0688d2;
case 0x0c0688d4u: goto P_0c0688d4;
case 0x0c0688d6u: goto P_0c0688d6;
case 0x0c0688d8u: goto P_0c0688d8;
case 0x0c0688dau: goto P_0c0688da;
case 0x0c0688dcu: goto P_0c0688dc;
case 0x0c0688deu: goto P_0c0688de;
case 0x0c0688e0u: goto P_0c0688e0;
case 0x0c0688e2u: goto P_0c0688e2;
case 0x0c0688e4u: goto P_0c0688e4;
case 0x0c0688e6u: goto P_0c0688e6;
case 0x0c0688e8u: goto P_0c0688e8;
case 0x0c0688eau: goto P_0c0688ea;
case 0x0c0688ecu: goto P_0c0688ec;
case 0x0c0688eeu: goto P_0c0688ee;
case 0x0c0688f0u: goto P_0c0688f0;
case 0x0c0688f2u: goto P_0c0688f2;
case 0x0c0688f4u: goto P_0c0688f4;
case 0x0c0688f6u: goto P_0c0688f6;
case 0x0c0688f8u: goto P_0c0688f8;
case 0x0c0688fau: goto P_0c0688fa;
case 0x0c0688fcu: goto P_0c0688fc;
case 0x0c0688feu: goto P_0c0688fe;
case 0x0c068900u: goto P_0c068900;
case 0x0c068902u: goto P_0c068902;
case 0x0c068904u: goto P_0c068904;
case 0x0c068906u: goto P_0c068906;
case 0x0c068908u: goto P_0c068908;
case 0x0c06890au: goto P_0c06890a;
case 0x0c06890cu: goto P_0c06890c;
case 0x0c06890eu: goto P_0c06890e;
case 0x0c068910u: goto P_0c068910;
case 0x0c068912u: goto P_0c068912;
case 0x0c068914u: goto P_0c068914;
case 0x0c068916u: goto P_0c068916;
case 0x0c068918u: goto P_0c068918;
case 0x0c06891au: goto P_0c06891a;
case 0x0c06891cu: goto P_0c06891c;
case 0x0c06891eu: goto P_0c06891e;
case 0x0c068920u: goto P_0c068920;
case 0x0c068922u: goto P_0c068922;
case 0x0c068924u: goto P_0c068924;
case 0x0c068926u: goto P_0c068926;
case 0x0c068928u: goto P_0c068928;
case 0x0c06892au: goto P_0c06892a;
case 0x0c06892cu: goto P_0c06892c;
case 0x0c06892eu: goto P_0c06892e;
case 0x0c068930u: goto P_0c068930;
case 0x0c068932u: goto P_0c068932;
case 0x0c068934u: goto P_0c068934;
case 0x0c068936u: goto P_0c068936;
case 0x0c068938u: goto P_0c068938;
case 0x0c06893au: goto P_0c06893a;
case 0x0c06893cu: goto P_0c06893c;
case 0x0c06893eu: goto P_0c06893e;
case 0x0c068940u: goto P_0c068940;
case 0x0c068942u: goto P_0c068942;
case 0x0c068944u: goto P_0c068944;
case 0x0c068946u: goto P_0c068946;
case 0x0c068948u: goto P_0c068948;
case 0x0c06894au: goto P_0c06894a;
case 0x0c06894cu: goto P_0c06894c;
case 0x0c06894eu: goto P_0c06894e;
case 0x0c068950u: goto P_0c068950;
case 0x0c068952u: goto P_0c068952;
case 0x0c068954u: goto P_0c068954;
case 0x0c068956u: goto P_0c068956;
case 0x0c068958u: goto P_0c068958;
case 0x0c06895au: goto P_0c06895a;
case 0x0c06895cu: goto P_0c06895c;
case 0x0c06895eu: goto P_0c06895e;
case 0x0c068960u: goto P_0c068960;
case 0x0c068962u: goto P_0c068962;
case 0x0c068964u: goto P_0c068964;
case 0x0c068974u: goto P_0c068974;
case 0x0c068976u: goto P_0c068976;
case 0x0c068978u: goto P_0c068978;
case 0x0c06897au: goto P_0c06897a;
case 0x0c06897cu: goto P_0c06897c;
case 0x0c06897eu: goto P_0c06897e;
case 0x0c068980u: goto P_0c068980;
case 0x0c068982u: goto P_0c068982;
case 0x0c068984u: goto P_0c068984;
case 0x0c068986u: goto P_0c068986;
case 0x0c068988u: goto P_0c068988;
case 0x0c06898au: goto P_0c06898a;
case 0x0c06898cu: goto P_0c06898c;
case 0x0c06898eu: goto P_0c06898e;
case 0x0c068992u: goto P_0c068992;
case 0x0c068994u: goto P_0c068994;
case 0x0c068996u: goto P_0c068996;
case 0x0c068998u: goto P_0c068998;
case 0x0c06899au: goto P_0c06899a;
case 0x0c06899cu: goto P_0c06899c;
case 0x0c06899eu: goto P_0c06899e;
case 0x0c0689a0u: goto P_0c0689a0;
case 0x0c0689a2u: goto P_0c0689a2;
case 0x0c0689a4u: goto P_0c0689a4;
case 0x0c0689a6u: goto P_0c0689a6;
case 0x0c0689a8u: goto P_0c0689a8;
case 0x0c0689aau: goto P_0c0689aa;
case 0x0c0689acu: goto P_0c0689ac;
case 0x0c0689aeu: goto P_0c0689ae;
case 0x0c0689b0u: goto P_0c0689b0;
case 0x0c0689b2u: goto P_0c0689b2;
case 0x0c0689b4u: goto P_0c0689b4;
case 0x0c0689b6u: goto P_0c0689b6;
case 0x0c0689b8u: goto P_0c0689b8;
case 0x0c0689bau: goto P_0c0689ba;
case 0x0c0689bcu: goto P_0c0689bc;
case 0x0c0689beu: goto P_0c0689be;
case 0x0c0689c0u: goto P_0c0689c0;
case 0x0c0689c2u: goto P_0c0689c2;
case 0x0c0689c4u: goto P_0c0689c4;
case 0x0c0689c6u: goto P_0c0689c6;
case 0x0c0689c8u: goto P_0c0689c8;
case 0x0c0689cau: goto P_0c0689ca;
case 0x0c0689ccu: goto P_0c0689cc;
case 0x0c0689ceu: goto P_0c0689ce;
case 0x0c0689d0u: goto P_0c0689d0;
case 0x0c0689d2u: goto P_0c0689d2;
case 0x0c0689d4u: goto P_0c0689d4;
case 0x0c0689d6u: goto P_0c0689d6;
case 0x0c0689d8u: goto P_0c0689d8;
case 0x0c0689dau: goto P_0c0689da;
case 0x0c0689dcu: goto P_0c0689dc;
case 0x0c0689deu: goto P_0c0689de;
case 0x0c0689e0u: goto P_0c0689e0;
case 0x0c0689e2u: goto P_0c0689e2;
case 0x0c0689e4u: goto P_0c0689e4;
case 0x0c0689e6u: goto P_0c0689e6;
case 0x0c0689e8u: goto P_0c0689e8;
case 0x0c0689eau: goto P_0c0689ea;
case 0x0c0689ecu: goto P_0c0689ec;
case 0x0c0689eeu: goto P_0c0689ee;
case 0x0c0689f0u: goto P_0c0689f0;
case 0x0c0689f2u: goto P_0c0689f2;
case 0x0c0689f4u: goto P_0c0689f4;
case 0x0c0689f6u: goto P_0c0689f6;
case 0x0c0689f8u: goto P_0c0689f8;
case 0x0c0689fau: goto P_0c0689fa;
case 0x0c0689fcu: goto P_0c0689fc;
case 0x0c0689feu: goto P_0c0689fe;
case 0x0c068a00u: goto P_0c068a00;
case 0x0c068a02u: goto P_0c068a02;
case 0x0c068a04u: goto P_0c068a04;
case 0x0c068a06u: goto P_0c068a06;
case 0x0c068a08u: goto P_0c068a08;
case 0x0c068a0au: goto P_0c068a0a;
case 0x0c068a0cu: goto P_0c068a0c;
case 0x0c068a0eu: goto P_0c068a0e;
case 0x0c068a10u: goto P_0c068a10;
case 0x0c068a12u: goto P_0c068a12;
case 0x0c068a14u: goto P_0c068a14;
case 0x0c068a16u: goto P_0c068a16;
case 0x0c068a18u: goto P_0c068a18;
case 0x0c068a1au: goto P_0c068a1a;
case 0x0c068a1cu: goto P_0c068a1c;
case 0x0c068a1eu: goto P_0c068a1e;
case 0x0c068a20u: goto P_0c068a20;
case 0x0c068a22u: goto P_0c068a22;
case 0x0c068a24u: goto P_0c068a24;
case 0x0c068a26u: goto P_0c068a26;
case 0x0c068a28u: goto P_0c068a28;
case 0x0c068a2au: goto P_0c068a2a;
case 0x0c068a2cu: goto P_0c068a2c;
case 0x0c068a2eu: goto P_0c068a2e;
case 0x0c068a30u: goto P_0c068a30;
case 0x0c068a32u: goto P_0c068a32;
case 0x0c068a34u: goto P_0c068a34;
case 0x0c068a36u: goto P_0c068a36;
case 0x0c068a38u: goto P_0c068a38;
case 0x0c068a3au: goto P_0c068a3a;
case 0x0c068a3cu: goto P_0c068a3c;
case 0x0c068a3eu: goto P_0c068a3e;
case 0x0c068a40u: goto P_0c068a40;
case 0x0c068a42u: goto P_0c068a42;
case 0x0c068a44u: goto P_0c068a44;
case 0x0c068a46u: goto P_0c068a46;
case 0x0c068a48u: goto P_0c068a48;
case 0x0c068a4au: goto P_0c068a4a;
case 0x0c068a4cu: goto P_0c068a4c;
case 0x0c068a4eu: goto P_0c068a4e;
case 0x0c068a50u: goto P_0c068a50;
case 0x0c068a52u: goto P_0c068a52;
case 0x0c068a54u: goto P_0c068a54;
case 0x0c068a56u: goto P_0c068a56;
case 0x0c068a58u: goto P_0c068a58;
case 0x0c068a5au: goto P_0c068a5a;
case 0x0c068a5cu: goto P_0c068a5c;
case 0x0c068a5eu: goto P_0c068a5e;
case 0x0c068a60u: goto P_0c068a60;
case 0x0c068a62u: goto P_0c068a62;
case 0x0c068a64u: goto P_0c068a64;
case 0x0c068a66u: goto P_0c068a66;
case 0x0c068a68u: goto P_0c068a68;
case 0x0c068a6au: goto P_0c068a6a;
case 0x0c068a6cu: goto P_0c068a6c;
case 0x0c068a6eu: goto P_0c068a6e;
case 0x0c068a70u: goto P_0c068a70;
case 0x0c068a72u: goto P_0c068a72;
case 0x0c068a74u: goto P_0c068a74;
case 0x0c068a76u: goto P_0c068a76;
case 0x0c068a78u: goto P_0c068a78;
case 0x0c068a7au: goto P_0c068a7a;
case 0x0c068a7cu: goto P_0c068a7c;
case 0x0c068a7eu: goto P_0c068a7e;
case 0x0c068a80u: goto P_0c068a80;
case 0x0c068a82u: goto P_0c068a82;
case 0x0c068a84u: goto P_0c068a84;
case 0x0c068a86u: goto P_0c068a86;
case 0x0c068a88u: goto P_0c068a88;
case 0x0c068a8au: goto P_0c068a8a;
case 0x0c068a8cu: goto P_0c068a8c;
case 0x0c068a8eu: goto P_0c068a8e;
case 0x0c068a90u: goto P_0c068a90;
case 0x0c068a92u: goto P_0c068a92;
case 0x0c068a94u: goto P_0c068a94;
case 0x0c068a96u: goto P_0c068a96;
case 0x0c068a98u: goto P_0c068a98;
case 0x0c068a9au: goto P_0c068a9a;
case 0x0c068a9cu: goto P_0c068a9c;
case 0x0c068a9eu: goto P_0c068a9e;
case 0x0c068aa0u: goto P_0c068aa0;
case 0x0c068aa2u: goto P_0c068aa2;
case 0x0c068aa4u: goto P_0c068aa4;
case 0x0c068aa6u: goto P_0c068aa6;
case 0x0c068aa8u: goto P_0c068aa8;
case 0x0c068aaau: goto P_0c068aaa;
case 0x0c068aacu: goto P_0c068aac;
case 0x0c068aaeu: goto P_0c068aae;
case 0x0c068ab0u: goto P_0c068ab0;
case 0x0c068ab2u: goto P_0c068ab2;
case 0x0c068ab4u: goto P_0c068ab4;
case 0x0c068ab6u: goto P_0c068ab6;
case 0x0c068ab8u: goto P_0c068ab8;
case 0x0c068abau: goto P_0c068aba;
case 0x0c068abcu: goto P_0c068abc;
case 0x0c068abeu: goto P_0c068abe;
case 0x0c068ac0u: goto P_0c068ac0;
case 0x0c068ac2u: goto P_0c068ac2;
case 0x0c068ac4u: goto P_0c068ac4;
case 0x0c068ac6u: goto P_0c068ac6;
case 0x0c068ac8u: goto P_0c068ac8;
case 0x0c068acau: goto P_0c068aca;
case 0x0c068accu: goto P_0c068acc;
case 0x0c068aceu: goto P_0c068ace;
case 0x0c068ad0u: goto P_0c068ad0;
case 0x0c068ad2u: goto P_0c068ad2;
case 0x0c068ad4u: goto P_0c068ad4;
case 0x0c068ad6u: goto P_0c068ad6;
case 0x0c068ad8u: goto P_0c068ad8;
case 0x0c068adau: goto P_0c068ada;
case 0x0c068adcu: goto P_0c068adc;
case 0x0c068adeu: goto P_0c068ade;
case 0x0c068ae0u: goto P_0c068ae0;
case 0x0c068ae2u: goto P_0c068ae2;
case 0x0c068ae4u: goto P_0c068ae4;
case 0x0c068ae6u: goto P_0c068ae6;
case 0x0c068ae8u: goto P_0c068ae8;
case 0x0c068aeau: goto P_0c068aea;
case 0x0c068aecu: goto P_0c068aec;
case 0x0c068aeeu: goto P_0c068aee;
case 0x0c068af0u: goto P_0c068af0;
case 0x0c068af2u: goto P_0c068af2;
case 0x0c068af4u: goto P_0c068af4;
case 0x0c068af6u: goto P_0c068af6;
case 0x0c068af8u: goto P_0c068af8;
case 0x0c068afau: goto P_0c068afa;
case 0x0c068afcu: goto P_0c068afc;
case 0x0c068afeu: goto P_0c068afe;
case 0x0c068b00u: goto P_0c068b00;
case 0x0c068b02u: goto P_0c068b02;
case 0x0c068b04u: goto P_0c068b04;
case 0x0c068b06u: goto P_0c068b06;
case 0x0c068b08u: goto P_0c068b08;
case 0x0c068b0au: goto P_0c068b0a;
case 0x0c068b0cu: goto P_0c068b0c;
case 0x0c068b0eu: goto P_0c068b0e;
case 0x0c068b10u: goto P_0c068b10;
case 0x0c068b12u: goto P_0c068b12;
case 0x0c068b14u: goto P_0c068b14;
case 0x0c068b16u: goto P_0c068b16;
case 0x0c068b18u: goto P_0c068b18;
case 0x0c068b1au: goto P_0c068b1a;
case 0x0c068b1cu: goto P_0c068b1c;
case 0x0c068b1eu: goto P_0c068b1e;
case 0x0c068b20u: goto P_0c068b20;
case 0x0c068b22u: goto P_0c068b22;
case 0x0c068b24u: goto P_0c068b24;
case 0x0c068b26u: goto P_0c068b26;
case 0x0c068b28u: goto P_0c068b28;
case 0x0c068b2au: goto P_0c068b2a;
case 0x0c068b2cu: goto P_0c068b2c;
case 0x0c068b2eu: goto P_0c068b2e;
case 0x0c068b30u: goto P_0c068b30;
case 0x0c068b32u: goto P_0c068b32;
case 0x0c068b34u: goto P_0c068b34;
case 0x0c068b36u: goto P_0c068b36;
case 0x0c068b38u: goto P_0c068b38;
case 0x0c068b3au: goto P_0c068b3a;
case 0x0c068b3cu: goto P_0c068b3c;
case 0x0c068b3eu: goto P_0c068b3e;
case 0x0c068b40u: goto P_0c068b40;
case 0x0c068b42u: goto P_0c068b42;
case 0x0c068b44u: goto P_0c068b44;
case 0x0c068b46u: goto P_0c068b46;
case 0x0c068b48u: goto P_0c068b48;
case 0x0c068b4au: goto P_0c068b4a;
case 0x0c068b4cu: goto P_0c068b4c;
case 0x0c068b64u: goto P_0c068b64;
case 0x0c068b66u: goto P_0c068b66;
case 0x0c068b68u: goto P_0c068b68;
case 0x0c068b6au: goto P_0c068b6a;
case 0x0c068b6cu: goto P_0c068b6c;
case 0x0c068b6eu: goto P_0c068b6e;
case 0x0c068b70u: goto P_0c068b70;
case 0x0c068b72u: goto P_0c068b72;
case 0x0c068b74u: goto P_0c068b74;
case 0x0c068b76u: goto P_0c068b76;
case 0x0c068b78u: goto P_0c068b78;
case 0x0c068b7au: goto P_0c068b7a;
case 0x0c068b7cu: goto P_0c068b7c;
case 0x0c068b7eu: goto P_0c068b7e;
case 0x0c068b80u: goto P_0c068b80;
case 0x0c068b82u: goto P_0c068b82;
case 0x0c068b84u: goto P_0c068b84;
case 0x0c068b86u: goto P_0c068b86;
case 0x0c068b88u: goto P_0c068b88;
case 0x0c068b8au: goto P_0c068b8a;
case 0x0c068b8cu: goto P_0c068b8c;
case 0x0c068b8eu: goto P_0c068b8e;
case 0x0c068b90u: goto P_0c068b90;
case 0x0c068b92u: goto P_0c068b92;
case 0x0c068b94u: goto P_0c068b94;
case 0x0c068b96u: goto P_0c068b96;
case 0x0c068b98u: goto P_0c068b98;
case 0x0c068b9au: goto P_0c068b9a;
case 0x0c068b9cu: goto P_0c068b9c;
case 0x0c068b9eu: goto P_0c068b9e;
case 0x0c068ba0u: goto P_0c068ba0;
case 0x0c068ba2u: goto P_0c068ba2;
case 0x0c068ba4u: goto P_0c068ba4;
case 0x0c068ba6u: goto P_0c068ba6;
case 0x0c068ba8u: goto P_0c068ba8;
case 0x0c068baau: goto P_0c068baa;
case 0x0c068bacu: goto P_0c068bac;
case 0x0c068baeu: goto P_0c068bae;
case 0x0c068bb0u: goto P_0c068bb0;
case 0x0c068bb2u: goto P_0c068bb2;
case 0x0c068bb4u: goto P_0c068bb4;
case 0x0c068bb6u: goto P_0c068bb6;
case 0x0c068bb8u: goto P_0c068bb8;
case 0x0c068bbau: goto P_0c068bba;
case 0x0c068bbcu: goto P_0c068bbc;
case 0x0c068bbeu: goto P_0c068bbe;
case 0x0c068bc0u: goto P_0c068bc0;
case 0x0c068bc2u: goto P_0c068bc2;
case 0x0c068bc4u: goto P_0c068bc4;
case 0x0c068bc6u: goto P_0c068bc6;
case 0x0c068bc8u: goto P_0c068bc8;
case 0x0c068bcau: goto P_0c068bca;
case 0x0c068bccu: goto P_0c068bcc;
case 0x0c068bceu: goto P_0c068bce;
case 0x0c068bd0u: goto P_0c068bd0;
case 0x0c068bd2u: goto P_0c068bd2;
case 0x0c068bd4u: goto P_0c068bd4;
case 0x0c068bd6u: goto P_0c068bd6;
case 0x0c068bd8u: goto P_0c068bd8;
case 0x0c068bdau: goto P_0c068bda;
case 0x0c068bdcu: goto P_0c068bdc;
case 0x0c068bdeu: goto P_0c068bde;
case 0x0c068be0u: goto P_0c068be0;
case 0x0c068be2u: goto P_0c068be2;
case 0x0c068be4u: goto P_0c068be4;
case 0x0c068be6u: goto P_0c068be6;
case 0x0c068be8u: goto P_0c068be8;
case 0x0c068beau: goto P_0c068bea;
case 0x0c068becu: goto P_0c068bec;
case 0x0c068beeu: goto P_0c068bee;
case 0x0c068bf0u: goto P_0c068bf0;
case 0x0c068bf2u: goto P_0c068bf2;
case 0x0c068bf4u: goto P_0c068bf4;
case 0x0c068bf6u: goto P_0c068bf6;
case 0x0c068bf8u: goto P_0c068bf8;
case 0x0c068bfau: goto P_0c068bfa;
case 0x0c068bfcu: goto P_0c068bfc;
case 0x0c068bfeu: goto P_0c068bfe;
case 0x0c068c00u: goto P_0c068c00;
case 0x0c068c02u: goto P_0c068c02;
case 0x0c068e0eu: goto P_0c068e0e;
case 0x0c068e10u: goto P_0c068e10;
case 0x0c068e12u: goto P_0c068e12;
case 0x0c068e14u: goto P_0c068e14;
case 0x0c068e16u: goto P_0c068e16;
case 0x0c068e18u: goto P_0c068e18;
case 0x0c068e1au: goto P_0c068e1a;
case 0x0c068e1cu: goto P_0c068e1c;
case 0x0c068e1eu: goto P_0c068e1e;
case 0x0c068e20u: goto P_0c068e20;
case 0x0c068e22u: goto P_0c068e22;
case 0x0c068e24u: goto P_0c068e24;
case 0x0c068e26u: goto P_0c068e26;
case 0x0c068e28u: goto P_0c068e28;
case 0x0c068e2au: goto P_0c068e2a;
case 0x0c068e2cu: goto P_0c068e2c;
case 0x0c068e2eu: goto P_0c068e2e;
case 0x0c068e30u: goto P_0c068e30;
case 0x0c068e32u: goto P_0c068e32;
case 0x0c068e34u: goto P_0c068e34;
case 0x0c068e36u: goto P_0c068e36;
case 0x0c068e38u: goto P_0c068e38;
case 0x0c068e3au: goto P_0c068e3a;
case 0x0c068e3cu: goto P_0c068e3c;
case 0x0c068e3eu: goto P_0c068e3e;
case 0x0c068e40u: goto P_0c068e40;
case 0x0c068e42u: goto P_0c068e42;
case 0x0c068e44u: goto P_0c068e44;
case 0x0c068e46u: goto P_0c068e46;
case 0x0c068e48u: goto P_0c068e48;
case 0x0c068e4au: goto P_0c068e4a;
case 0x0c068e4cu: goto P_0c068e4c;
case 0x0c068e4eu: goto P_0c068e4e;
case 0x0c068e6cu: goto P_0c068e6c;
case 0x0c068e6eu: goto P_0c068e6e;
case 0x0c068e70u: goto P_0c068e70;
case 0x0c068e72u: goto P_0c068e72;
case 0x0c068e74u: goto P_0c068e74;
case 0x0c068e76u: goto P_0c068e76;
case 0x0c068e78u: goto P_0c068e78;
case 0x0c068e7au: goto P_0c068e7a;
case 0x0c068e7cu: goto P_0c068e7c;
case 0x0c068e7eu: goto P_0c068e7e;
case 0x0c068e80u: goto P_0c068e80;
case 0x0c068e82u: goto P_0c068e82;
case 0x0c068e84u: goto P_0c068e84;
case 0x0c068e86u: goto P_0c068e86;
case 0x0c068e88u: goto P_0c068e88;
case 0x0c068e8au: goto P_0c068e8a;
case 0x0c068e8cu: goto P_0c068e8c;
case 0x0c068e8eu: goto P_0c068e8e;
case 0x0c068e90u: goto P_0c068e90;
case 0x0c068e92u: goto P_0c068e92;
case 0x0c068e94u: goto P_0c068e94;
case 0x0c068e96u: goto P_0c068e96;
case 0x0c068e98u: goto P_0c068e98;
case 0x0c068e9au: goto P_0c068e9a;
case 0x0c068e9cu: goto P_0c068e9c;
case 0x0c068e9eu: goto P_0c068e9e;
case 0x0c068ea0u: goto P_0c068ea0;
case 0x0c068ea2u: goto P_0c068ea2;
case 0x0c068ea4u: goto P_0c068ea4;
case 0x0c068ea6u: goto P_0c068ea6;
case 0x0c068ea8u: goto P_0c068ea8;
case 0x0c068eaau: goto P_0c068eaa;
case 0x0c068eacu: goto P_0c068eac;
case 0x0c068eaeu: goto P_0c068eae;
case 0x0c068eb0u: goto P_0c068eb0;
case 0x0c068eb2u: goto P_0c068eb2;
case 0x0c068eb4u: goto P_0c068eb4;
case 0x0c068eb6u: goto P_0c068eb6;
case 0x0c068eb8u: goto P_0c068eb8;
case 0x0c068ebau: goto P_0c068eba;
case 0x0c068ebcu: goto P_0c068ebc;
case 0x0c068ebeu: goto P_0c068ebe;
case 0x0c068ec0u: goto P_0c068ec0;
case 0x0c068ec2u: goto P_0c068ec2;
case 0x0c068ec4u: goto P_0c068ec4;
case 0x0c068ec6u: goto P_0c068ec6;
case 0x0c068ec8u: goto P_0c068ec8;
case 0x0c068ecau: goto P_0c068eca;
case 0x0c068eccu: goto P_0c068ecc;
case 0x0c068eceu: goto P_0c068ece;
case 0x0c068ed0u: goto P_0c068ed0;
case 0x0c068ed2u: goto P_0c068ed2;
case 0x0c068ed4u: goto P_0c068ed4;
case 0x0c068ed6u: goto P_0c068ed6;
case 0x0c068ed8u: goto P_0c068ed8;
case 0x0c068edau: goto P_0c068eda;
case 0x0c068edcu: goto P_0c068edc;
case 0x0c068edeu: goto P_0c068ede;
case 0x0c068ee0u: goto P_0c068ee0;
case 0x0c068ee2u: goto P_0c068ee2;
case 0x0c068ee4u: goto P_0c068ee4;
case 0x0c068ee6u: goto P_0c068ee6;
case 0x0c068ee8u: goto P_0c068ee8;
case 0x0c068eeau: goto P_0c068eea;
case 0x0c068eecu: goto P_0c068eec;
case 0x0c068eeeu: goto P_0c068eee;
case 0x0c068ef0u: goto P_0c068ef0;
case 0x0c068ef2u: goto P_0c068ef2;
case 0x0c068ef4u: goto P_0c068ef4;
case 0x0c068ef6u: goto P_0c068ef6;
case 0x0c068ef8u: goto P_0c068ef8;
case 0x0c068efau: goto P_0c068efa;
case 0x0c068efcu: goto P_0c068efc;
case 0x0c068efeu: goto P_0c068efe;
case 0x0c068f00u: goto P_0c068f00;
case 0x0c068f02u: goto P_0c068f02;
case 0x0c068f04u: goto P_0c068f04;
case 0x0c068f06u: goto P_0c068f06;
case 0x0c068f08u: goto P_0c068f08;
case 0x0c068f0au: goto P_0c068f0a;
case 0x0c068f0cu: goto P_0c068f0c;
case 0x0c068f0eu: goto P_0c068f0e;
case 0x0c068f10u: goto P_0c068f10;
case 0x0c068f12u: goto P_0c068f12;
case 0x0c068f14u: goto P_0c068f14;
case 0x0c068f16u: goto P_0c068f16;
case 0x0c068f18u: goto P_0c068f18;
case 0x0c068f1au: goto P_0c068f1a;
case 0x0c068f1cu: goto P_0c068f1c;
case 0x0c068f1eu: goto P_0c068f1e;
case 0x0c068f20u: goto P_0c068f20;
case 0x0c068f22u: goto P_0c068f22;
case 0x0c068f24u: goto P_0c068f24;
case 0x0c068f26u: goto P_0c068f26;
case 0x0c068f28u: goto P_0c068f28;
case 0x0c068f2au: goto P_0c068f2a;
case 0x0c068f2cu: goto P_0c068f2c;
case 0x0c068f2eu: goto P_0c068f2e;
case 0x0c068f30u: goto P_0c068f30;
case 0x0c068f32u: goto P_0c068f32;
case 0x0c068f34u: goto P_0c068f34;
case 0x0c068f36u: goto P_0c068f36;
case 0x0c068f38u: goto P_0c068f38;
case 0x0c068f3au: goto P_0c068f3a;
case 0x0c068f3cu: goto P_0c068f3c;
case 0x0c068f3eu: goto P_0c068f3e;
case 0x0c068f40u: goto P_0c068f40;
case 0x0c068f42u: goto P_0c068f42;
case 0x0c068f44u: goto P_0c068f44;
case 0x0c068f46u: goto P_0c068f46;
case 0x0c068f48u: goto P_0c068f48;
case 0x0c068f4au: goto P_0c068f4a;
case 0x0c068f4cu: goto P_0c068f4c;
case 0x0c068f4eu: goto P_0c068f4e;
case 0x0c068f50u: goto P_0c068f50;
case 0x0c068f52u: goto P_0c068f52;
case 0x0c068f54u: goto P_0c068f54;
case 0x0c068f56u: goto P_0c068f56;
case 0x0c068f58u: goto P_0c068f58;
case 0x0c068f5au: goto P_0c068f5a;
case 0x0c068f5cu: goto P_0c068f5c;
case 0x0c068f5eu: goto P_0c068f5e;
case 0x0c068f60u: goto P_0c068f60;
case 0x0c068f62u: goto P_0c068f62;
case 0x0c068f64u: goto P_0c068f64;
case 0x0c068f66u: goto P_0c068f66;
case 0x0c068f68u: goto P_0c068f68;
case 0x0c068f6au: goto P_0c068f6a;
case 0x0c068f6cu: goto P_0c068f6c;
case 0x0c068f6eu: goto P_0c068f6e;
case 0x0c068f70u: goto P_0c068f70;
case 0x0c068f72u: goto P_0c068f72;
case 0x0c068f74u: goto P_0c068f74;
case 0x0c068f76u: goto P_0c068f76;
case 0x0c068f78u: goto P_0c068f78;
case 0x0c068f7au: goto P_0c068f7a;
case 0x0c068f7cu: goto P_0c068f7c;
case 0x0c068f7eu: goto P_0c068f7e;
case 0x0c068f80u: goto P_0c068f80;
case 0x0c068f82u: goto P_0c068f82;
case 0x0c068f84u: goto P_0c068f84;
case 0x0c068f86u: goto P_0c068f86;
case 0x0c068f88u: goto P_0c068f88;
case 0x0c068f8au: goto P_0c068f8a;
case 0x0c068f8cu: goto P_0c068f8c;
case 0x0c068f8eu: goto P_0c068f8e;
case 0x0c068f90u: goto P_0c068f90;
case 0x0c069624u: goto P_0c069624;
case 0x0c069626u: goto P_0c069626;
case 0x0c069628u: goto P_0c069628;
case 0x0c06962au: goto P_0c06962a;
case 0x0c06962cu: goto P_0c06962c;
case 0x0c06962eu: goto P_0c06962e;
case 0x0c069630u: goto P_0c069630;
case 0x0c069632u: goto P_0c069632;
case 0x0c069634u: goto P_0c069634;
case 0x0c069636u: goto P_0c069636;
case 0x0c069638u: goto P_0c069638;
case 0x0c06963au: goto P_0c06963a;
case 0x0c06963cu: goto P_0c06963c;
case 0x0c06963eu: goto P_0c06963e;
case 0x0c069640u: goto P_0c069640;
case 0x0c069642u: goto P_0c069642;
case 0x0c069644u: goto P_0c069644;
case 0x0c069646u: goto P_0c069646;
case 0x0c069648u: goto P_0c069648;
case 0x0c06964au: goto P_0c06964a;
case 0x0c06964cu: goto P_0c06964c;
case 0x0c06964eu: goto P_0c06964e;
case 0x0c069650u: goto P_0c069650;
case 0x0c069652u: goto P_0c069652;
case 0x0c069654u: goto P_0c069654;
case 0x0c069656u: goto P_0c069656;
case 0x0c069658u: goto P_0c069658;
case 0x0c06965au: goto P_0c06965a;
case 0x0c06965cu: goto P_0c06965c;
case 0x0c06965eu: goto P_0c06965e;
case 0x0c069660u: goto P_0c069660;
case 0x0c069662u: goto P_0c069662;
case 0x0c069664u: goto P_0c069664;
case 0x0c069666u: goto P_0c069666;
case 0x0c069668u: goto P_0c069668;
case 0x0c06966au: goto P_0c06966a;
case 0x0c06966cu: goto P_0c06966c;
case 0x0c06966eu: goto P_0c06966e;
case 0x0c069670u: goto P_0c069670;
case 0x0c069672u: goto P_0c069672;
case 0x0c069674u: goto P_0c069674;
case 0x0c069676u: goto P_0c069676;
case 0x0c069678u: goto P_0c069678;
case 0x0c06967au: goto P_0c06967a;
case 0x0c06967cu: goto P_0c06967c;
case 0x0c06967eu: goto P_0c06967e;
case 0x0c069680u: goto P_0c069680;
case 0x0c069682u: goto P_0c069682;
case 0x0c069684u: goto P_0c069684;
case 0x0c069686u: goto P_0c069686;
case 0x0c069688u: goto P_0c069688;
case 0x0c06968au: goto P_0c06968a;
case 0x0c06968cu: goto P_0c06968c;
case 0x0c06968eu: goto P_0c06968e;
case 0x0c069690u: goto P_0c069690;
case 0x0c069692u: goto P_0c069692;
case 0x0c069694u: goto P_0c069694;
case 0x0c069696u: goto P_0c069696;
case 0x0c069698u: goto P_0c069698;
case 0x0c06969au: goto P_0c06969a;
case 0x0c06969cu: goto P_0c06969c;
case 0x0c06f77cu: goto P_0c06f77c;
case 0x0c06f77eu: goto P_0c06f77e;
case 0x0c06f780u: goto P_0c06f780;
case 0x0c06f782u: goto P_0c06f782;
case 0x0c06f784u: goto P_0c06f784;
case 0x0c06f786u: goto P_0c06f786;
case 0x0c06f788u: goto P_0c06f788;
case 0x0c06f78au: goto P_0c06f78a;
case 0x0c06f78cu: goto P_0c06f78c;
case 0x0c06f78eu: goto P_0c06f78e;
case 0x0c06f790u: goto P_0c06f790;
case 0x0c06f792u: goto P_0c06f792;
case 0x0c06f794u: goto P_0c06f794;
case 0x0c06f796u: goto P_0c06f796;
case 0x0c06f798u: goto P_0c06f798;
case 0x0c06f79au: goto P_0c06f79a;
case 0x0c06f79cu: goto P_0c06f79c;
case 0x0c06f79eu: goto P_0c06f79e;
case 0x0c06f7a0u: goto P_0c06f7a0;
case 0x0c06f7a2u: goto P_0c06f7a2;
case 0x0c06f7a4u: goto P_0c06f7a4;
case 0x0c06f7a6u: goto P_0c06f7a6;
case 0x0c06f7a8u: goto P_0c06f7a8;
case 0x0c06f7aau: goto P_0c06f7aa;
case 0x0c06f7acu: goto P_0c06f7ac;
case 0x0c06f7aeu: goto P_0c06f7ae;
case 0x0c06f7b0u: goto P_0c06f7b0;
case 0x0c06f7b2u: goto P_0c06f7b2;
case 0x0c06f7b4u: goto P_0c06f7b4;
case 0x0c06f7b6u: goto P_0c06f7b6;
case 0x0c06f7b8u: goto P_0c06f7b8;
case 0x0c06f7bau: goto P_0c06f7ba;
case 0x0c06f7bcu: goto P_0c06f7bc;
case 0x0c06f7beu: goto P_0c06f7be;
case 0x0c06f7c0u: goto P_0c06f7c0;
case 0x0c06f7c2u: goto P_0c06f7c2;
case 0x0c06f7c4u: goto P_0c06f7c4;
case 0x0c06f7c6u: goto P_0c06f7c6;
case 0x0c06f7c8u: goto P_0c06f7c8;
case 0x0c06f7cau: goto P_0c06f7ca;
case 0x0c06f7ccu: goto P_0c06f7cc;
case 0x0c06f7ceu: goto P_0c06f7ce;
case 0x0c06f7d0u: goto P_0c06f7d0;
case 0x0c06f7d2u: goto P_0c06f7d2;
case 0x0c06f7d4u: goto P_0c06f7d4;
case 0x0c06f7d6u: goto P_0c06f7d6;
case 0x0c06f7d8u: goto P_0c06f7d8;
case 0x0c06f7dau: goto P_0c06f7da;
case 0x0c06f7dcu: goto P_0c06f7dc;
case 0x0c06f7deu: goto P_0c06f7de;
case 0x0c06f7e0u: goto P_0c06f7e0;
case 0x0c06f7e2u: goto P_0c06f7e2;
case 0x0c06f7e4u: goto P_0c06f7e4;
case 0x0c06f7e6u: goto P_0c06f7e6;
case 0x0c06f7e8u: goto P_0c06f7e8;
case 0x0c06f7eau: goto P_0c06f7ea;
case 0x0c06f7ecu: goto P_0c06f7ec;
case 0x0c06f7eeu: goto P_0c06f7ee;
case 0x0c06f7f0u: goto P_0c06f7f0;
case 0x0c06f7f2u: goto P_0c06f7f2;
case 0x0c06f7f4u: goto P_0c06f7f4;
case 0x0c06f7f6u: goto P_0c06f7f6;
case 0x0c06f7f8u: goto P_0c06f7f8;
case 0x0c06f7fau: goto P_0c06f7fa;
case 0x0c06f7fcu: goto P_0c06f7fc;
case 0x0c06f7feu: goto P_0c06f7fe;
case 0x0c06f800u: goto P_0c06f800;
case 0x0c06f802u: goto P_0c06f802;
case 0x0c06f804u: goto P_0c06f804;
case 0x0c06f806u: goto P_0c06f806;
case 0x0c06f808u: goto P_0c06f808;
case 0x0c06f80au: goto P_0c06f80a;
case 0x0c06f80cu: goto P_0c06f80c;
case 0x0c06f80eu: goto P_0c06f80e;
case 0x0c06f810u: goto P_0c06f810;
case 0x0c06f812u: goto P_0c06f812;
case 0x0c06f814u: goto P_0c06f814;
case 0x0c06f816u: goto P_0c06f816;
case 0x0c06f818u: goto P_0c06f818;
case 0x0c06f81au: goto P_0c06f81a;
case 0x0c06f81cu: goto P_0c06f81c;
case 0x0c06f81eu: goto P_0c06f81e;
case 0x0c06f820u: goto P_0c06f820;
case 0x0c06f822u: goto P_0c06f822;
case 0x0c06f824u: goto P_0c06f824;
case 0x0c06f826u: goto P_0c06f826;
case 0x0c06f828u: goto P_0c06f828;
case 0x0c06f82au: goto P_0c06f82a;
case 0x0c06f82cu: goto P_0c06f82c;
case 0x0c06f82eu: goto P_0c06f82e;
case 0x0c06f830u: goto P_0c06f830;
case 0x0c06f832u: goto P_0c06f832;
case 0x0c06f834u: goto P_0c06f834;
case 0x0c06f836u: goto P_0c06f836;
case 0x0c06f838u: goto P_0c06f838;
case 0x0c06f83au: goto P_0c06f83a;
case 0x0c06f83cu: goto P_0c06f83c;
case 0x0c06f83eu: goto P_0c06f83e;
case 0x0c06f840u: goto P_0c06f840;
case 0x0c06f842u: goto P_0c06f842;
case 0x0c06f844u: goto P_0c06f844;
case 0x0c06f846u: goto P_0c06f846;
case 0x0c06f848u: goto P_0c06f848;
case 0x0c06f84au: goto P_0c06f84a;
case 0x0c06f84cu: goto P_0c06f84c;
case 0x0c06f84eu: goto P_0c06f84e;
case 0x0c06f850u: goto P_0c06f850;
case 0x0c06f852u: goto P_0c06f852;
case 0x0c06f854u: goto P_0c06f854;
case 0x0c06f856u: goto P_0c06f856;
case 0x0c06f858u: goto P_0c06f858;
case 0x0c06f85au: goto P_0c06f85a;
case 0x0c06f85cu: goto P_0c06f85c;
case 0x0c06f85eu: goto P_0c06f85e;
case 0x0c06f860u: goto P_0c06f860;
case 0x0c06f862u: goto P_0c06f862;
case 0x0c06f864u: goto P_0c06f864;
case 0x0c06f866u: goto P_0c06f866;
case 0x0c06f868u: goto P_0c06f868;
case 0x0c06f86au: goto P_0c06f86a;
case 0x0c06f86cu: goto P_0c06f86c;
case 0x0c06f86eu: goto P_0c06f86e;
case 0x0c06f870u: goto P_0c06f870;
case 0x0c06f872u: goto P_0c06f872;
case 0x0c06f874u: goto P_0c06f874;
case 0x0c06f876u: goto P_0c06f876;
case 0x0c06f878u: goto P_0c06f878;
case 0x0c06f87au: goto P_0c06f87a;
case 0x0c06f87cu: goto P_0c06f87c;
case 0x0c06f87eu: goto P_0c06f87e;
case 0x0c06f880u: goto P_0c06f880;
case 0x0c06f882u: goto P_0c06f882;
case 0x0c06f884u: goto P_0c06f884;
case 0x0c06f886u: goto P_0c06f886;
case 0x0c06f888u: goto P_0c06f888;
case 0x0c06f88au: goto P_0c06f88a;
case 0x0c06f88cu: goto P_0c06f88c;
case 0x0c06f88eu: goto P_0c06f88e;
case 0x0c06f890u: goto P_0c06f890;
case 0x0c06f892u: goto P_0c06f892;
case 0x0c06f894u: goto P_0c06f894;
case 0x0c06f896u: goto P_0c06f896;
case 0x0c06f898u: goto P_0c06f898;
case 0x0c06f89au: goto P_0c06f89a;
case 0x0c06f89cu: goto P_0c06f89c;
case 0x0c06f89eu: goto P_0c06f89e;
case 0x0c06f8a0u: goto P_0c06f8a0;
case 0x0c06f8a2u: goto P_0c06f8a2;
case 0x0c06f8a4u: goto P_0c06f8a4;
case 0x0c06f8a6u: goto P_0c06f8a6;
case 0x0c06f8a8u: goto P_0c06f8a8;
case 0x0c06f8aau: goto P_0c06f8aa;
case 0x0c06f8acu: goto P_0c06f8ac;
case 0x0c06f8aeu: goto P_0c06f8ae;
case 0x0c06f8b0u: goto P_0c06f8b0;
case 0x0c06f8b2u: goto P_0c06f8b2;
case 0x0c06f8b4u: goto P_0c06f8b4;
case 0x0c06f8b6u: goto P_0c06f8b6;
case 0x0c06f8b8u: goto P_0c06f8b8;
case 0x0c06f8bau: goto P_0c06f8ba;
case 0x0c06f8bcu: goto P_0c06f8bc;
case 0x0c06f8beu: goto P_0c06f8be;
case 0x0c06f8c0u: goto P_0c06f8c0;
case 0x0c06f8c2u: goto P_0c06f8c2;
case 0x0c06f8c4u: goto P_0c06f8c4;
case 0x0c06f8c6u: goto P_0c06f8c6;
case 0x0c06f8c8u: goto P_0c06f8c8;
case 0x0c06f8cau: goto P_0c06f8ca;
case 0x0c06f8ccu: goto P_0c06f8cc;
case 0x0c06f8ceu: goto P_0c06f8ce;
case 0x0c06f8d0u: goto P_0c06f8d0;
case 0x0c06f8d2u: goto P_0c06f8d2;
case 0x0c06f8d4u: goto P_0c06f8d4;
case 0x0c06f8d6u: goto P_0c06f8d6;
case 0x0c06f8d8u: goto P_0c06f8d8;
case 0x0c06f8dau: goto P_0c06f8da;
case 0x0c06f8dcu: goto P_0c06f8dc;
case 0x0c06f8deu: goto P_0c06f8de;
case 0x0c06f8e0u: goto P_0c06f8e0;
case 0x0c06f8e2u: goto P_0c06f8e2;
case 0x0c06f8e4u: goto P_0c06f8e4;
case 0x0c06f8e6u: goto P_0c06f8e6;
case 0x0c06f8e8u: goto P_0c06f8e8;
case 0x0c06f8eau: goto P_0c06f8ea;
case 0x0c06f8ecu: goto P_0c06f8ec;
case 0x0c06f8eeu: goto P_0c06f8ee;
case 0x0c06f8f0u: goto P_0c06f8f0;
case 0x0c06f8f2u: goto P_0c06f8f2;
case 0x0c06f8f4u: goto P_0c06f8f4;
case 0x0c06f8f6u: goto P_0c06f8f6;
case 0x0c06f8f8u: goto P_0c06f8f8;
case 0x0c06f8fau: goto P_0c06f8fa;
case 0x0c06f8fcu: goto P_0c06f8fc;
case 0x0c06f8feu: goto P_0c06f8fe;
case 0x0c06f900u: goto P_0c06f900;
case 0x0c06f902u: goto P_0c06f902;
case 0x0c06f904u: goto P_0c06f904;
case 0x0c06f906u: goto P_0c06f906;
case 0x0c06f908u: goto P_0c06f908;
case 0x0c06f90au: goto P_0c06f90a;
case 0x0c06f90cu: goto P_0c06f90c;
case 0x0c06f90eu: goto P_0c06f90e;
case 0x0c06f910u: goto P_0c06f910;
case 0x0c06f912u: goto P_0c06f912;
case 0x0c06f914u: goto P_0c06f914;
case 0x0c06f916u: goto P_0c06f916;
case 0x0c06f918u: goto P_0c06f918;
case 0x0c06f91au: goto P_0c06f91a;
case 0x0c06f91cu: goto P_0c06f91c;
case 0x0c06f91eu: goto P_0c06f91e;
case 0x0c06f920u: goto P_0c06f920;
case 0x0c06f922u: goto P_0c06f922;
case 0x0c06f924u: goto P_0c06f924;
case 0x0c06f926u: goto P_0c06f926;
case 0x0c06f928u: goto P_0c06f928;
case 0x0c06f92au: goto P_0c06f92a;
case 0x0c06f92cu: goto P_0c06f92c;
case 0x0c06f92eu: goto P_0c06f92e;
case 0x0c06f930u: goto P_0c06f930;
case 0x0c06f932u: goto P_0c06f932;
case 0x0c06f934u: goto P_0c06f934;
case 0x0c06f936u: goto P_0c06f936;
case 0x0c06f938u: goto P_0c06f938;
case 0x0c06f93au: goto P_0c06f93a;
case 0x0c06f93cu: goto P_0c06f93c;
case 0x0c06f93eu: goto P_0c06f93e;
case 0x0c06f940u: goto P_0c06f940;
case 0x0c06f942u: goto P_0c06f942;
case 0x0c06f944u: goto P_0c06f944;
case 0x0c06f946u: goto P_0c06f946;
case 0x0c06f948u: goto P_0c06f948;
case 0x0c06f94au: goto P_0c06f94a;
case 0x0c06f94cu: goto P_0c06f94c;
case 0x0c06f94eu: goto P_0c06f94e;
case 0x0c06f950u: goto P_0c06f950;
case 0x0c06f952u: goto P_0c06f952;
case 0x0c06f954u: goto P_0c06f954;
case 0x0c06f956u: goto P_0c06f956;
case 0x0c06f958u: goto P_0c06f958;
case 0x0c06f95au: goto P_0c06f95a;
case 0x0c06f95cu: goto P_0c06f95c;
case 0x0c06f95eu: goto P_0c06f95e;
case 0x0c06f960u: goto P_0c06f960;
case 0x0c06f962u: goto P_0c06f962;
case 0x0c06f964u: goto P_0c06f964;
case 0x0c06f966u: goto P_0c06f966;
case 0x0c06f968u: goto P_0c06f968;
case 0x0c06f96au: goto P_0c06f96a;
case 0x0c06f96cu: goto P_0c06f96c;
case 0x0c06f96eu: goto P_0c06f96e;
case 0x0c06f970u: goto P_0c06f970;
case 0x0c06f972u: goto P_0c06f972;
case 0x0c06f974u: goto P_0c06f974;
case 0x0c06f976u: goto P_0c06f976;
case 0x0c06f978u: goto P_0c06f978;
case 0x0c06f97au: goto P_0c06f97a;
case 0x0c06f97cu: goto P_0c06f97c;
case 0x0c06f97eu: goto P_0c06f97e;
case 0x0c06f980u: goto P_0c06f980;
case 0x0c06f982u: goto P_0c06f982;
case 0x0c06f984u: goto P_0c06f984;
case 0x0c06f986u: goto P_0c06f986;
case 0x0c06f988u: goto P_0c06f988;
case 0x0c06f98au: goto P_0c06f98a;
case 0x0c06f98cu: goto P_0c06f98c;
case 0x0c06f98eu: goto P_0c06f98e;
case 0x0c06f990u: goto P_0c06f990;
case 0x0c071104u: goto P_0c071104;
case 0x0c071106u: goto P_0c071106;
case 0x0c071108u: goto P_0c071108;
case 0x0c07110au: goto P_0c07110a;
case 0x0c07110cu: goto P_0c07110c;
case 0x0c07110eu: goto P_0c07110e;
case 0x0c071110u: goto P_0c071110;
case 0x0c071112u: goto P_0c071112;
case 0x0c071114u: goto P_0c071114;
case 0x0c071116u: goto P_0c071116;
case 0x0c071118u: goto P_0c071118;
case 0x0c07111au: goto P_0c07111a;
case 0x0c07111cu: goto P_0c07111c;
case 0x0c07111eu: goto P_0c07111e;
case 0x0c071120u: goto P_0c071120;
case 0x0c071122u: goto P_0c071122;
case 0x0c071124u: goto P_0c071124;
case 0x0c071126u: goto P_0c071126;
case 0x0c071128u: goto P_0c071128;
case 0x0c07112au: goto P_0c07112a;
case 0x0c07112cu: goto P_0c07112c;
case 0x0c07112eu: goto P_0c07112e;
case 0x0c071130u: goto P_0c071130;
case 0x0c071132u: goto P_0c071132;
case 0x0c071134u: goto P_0c071134;
case 0x0c071136u: goto P_0c071136;
case 0x0c071138u: goto P_0c071138;
case 0x0c07113au: goto P_0c07113a;
case 0x0c07113cu: goto P_0c07113c;
case 0x0c07113eu: goto P_0c07113e;
case 0x0c071faau: goto P_0c071faa;
case 0x0c071facu: goto P_0c071fac;
case 0x0c071faeu: goto P_0c071fae;
case 0x0c071fb0u: goto P_0c071fb0;
case 0x0c071fb2u: goto P_0c071fb2;
case 0x0c071fb4u: goto P_0c071fb4;
case 0x0c071fb6u: goto P_0c071fb6;
case 0x0c071fb8u: goto P_0c071fb8;
case 0x0c071fbau: goto P_0c071fba;
case 0x0c071fbcu: goto P_0c071fbc;
case 0x0c071fbeu: goto P_0c071fbe;
case 0x0c071fc0u: goto P_0c071fc0;
case 0x0c071fc2u: goto P_0c071fc2;
case 0x0c071fc4u: goto P_0c071fc4;
case 0x0c071fc6u: goto P_0c071fc6;
case 0x0c071fc8u: goto P_0c071fc8;
case 0x0c071fcau: goto P_0c071fca;
case 0x0c071fccu: goto P_0c071fcc;
case 0x0c071fd4u: goto P_0c071fd4;
case 0x0c071fd6u: goto P_0c071fd6;
case 0x0c071fd8u: goto P_0c071fd8;
case 0x0c071fdau: goto P_0c071fda;
case 0x0c071fdcu: goto P_0c071fdc;
case 0x0c071fdeu: goto P_0c071fde;
case 0x0c071fe0u: goto P_0c071fe0;
case 0x0c071fe2u: goto P_0c071fe2;
case 0x0c071fe4u: goto P_0c071fe4;
case 0x0c071fe6u: goto P_0c071fe6;
case 0x0c071fe8u: goto P_0c071fe8;
case 0x0c071feau: goto P_0c071fea;
case 0x0c071fecu: goto P_0c071fec;
case 0x0c071feeu: goto P_0c071fee;
case 0x0c071ff0u: goto P_0c071ff0;
case 0x0c071ff2u: goto P_0c071ff2;
case 0x0c071ff4u: goto P_0c071ff4;
case 0x0c071ff6u: goto P_0c071ff6;
case 0x0c071ff8u: goto P_0c071ff8;
case 0x0c071ffau: goto P_0c071ffa;
case 0x0c071ffcu: goto P_0c071ffc;
case 0x0c071ffeu: goto P_0c071ffe;
case 0x0c072000u: goto P_0c072000;
case 0x0c072002u: goto P_0c072002;
case 0x0c072004u: goto P_0c072004;
case 0x0c072006u: goto P_0c072006;
case 0x0c072008u: goto P_0c072008;
case 0x0c07200au: goto P_0c07200a;
case 0x0c07200cu: goto P_0c07200c;
case 0x0c07200eu: goto P_0c07200e;
case 0x0c072010u: goto P_0c072010;
case 0x0c072012u: goto P_0c072012;
case 0x0c072014u: goto P_0c072014;
case 0x0c072016u: goto P_0c072016;
case 0x0c072018u: goto P_0c072018;
case 0x0c07201au: goto P_0c07201a;
case 0x0c07201cu: goto P_0c07201c;
case 0x0c07201eu: goto P_0c07201e;
case 0x0c072020u: goto P_0c072020;
case 0x0c072022u: goto P_0c072022;
case 0x0c072024u: goto P_0c072024;
case 0x0c072026u: goto P_0c072026;
case 0x0c072028u: goto P_0c072028;
case 0x0c07202au: goto P_0c07202a;
case 0x0c07202cu: goto P_0c07202c;
case 0x0c07202eu: goto P_0c07202e;
case 0x0c072030u: goto P_0c072030;
case 0x0c072032u: goto P_0c072032;
case 0x0c072034u: goto P_0c072034;
case 0x0c072036u: goto P_0c072036;
case 0x0c072038u: goto P_0c072038;
case 0x0c07203au: goto P_0c07203a;
case 0x0c07203cu: goto P_0c07203c;
case 0x0c07203eu: goto P_0c07203e;
case 0x0c072040u: goto P_0c072040;
case 0x0c072042u: goto P_0c072042;
case 0x0c072044u: goto P_0c072044;
case 0x0c072046u: goto P_0c072046;
case 0x0c072048u: goto P_0c072048;
case 0x0c07204au: goto P_0c07204a;
case 0x0c07204cu: goto P_0c07204c;
case 0x0c07204eu: goto P_0c07204e;
case 0x0c072050u: goto P_0c072050;
case 0x0c072052u: goto P_0c072052;
case 0x0c072054u: goto P_0c072054;
case 0x0c072056u: goto P_0c072056;
case 0x0c072058u: goto P_0c072058;
case 0x0c07205au: goto P_0c07205a;
case 0x0c07205cu: goto P_0c07205c;
case 0x0c07205eu: goto P_0c07205e;
case 0x0c072060u: goto P_0c072060;
case 0x0c072062u: goto P_0c072062;
case 0x0c072064u: goto P_0c072064;
case 0x0c072066u: goto P_0c072066;
case 0x0c072068u: goto P_0c072068;
case 0x0c07206au: goto P_0c07206a;
case 0x0c07206cu: goto P_0c07206c;
case 0x0c07206eu: goto P_0c07206e;
case 0x0c072070u: goto P_0c072070;
case 0x0c072072u: goto P_0c072072;
case 0x0c072074u: goto P_0c072074;
case 0x0c07b398u: goto P_0c07b398;
case 0x0c07b39au: goto P_0c07b39a;
case 0x0c07b39cu: goto P_0c07b39c;
case 0x0c07b39eu: goto P_0c07b39e;
case 0x0c07b3a0u: goto P_0c07b3a0;
case 0x0c07b3a2u: goto P_0c07b3a2;
case 0x0c07b3a4u: goto P_0c07b3a4;
case 0x0c07b3a6u: goto P_0c07b3a6;
case 0x0c07b3a8u: goto P_0c07b3a8;
case 0x0c07b3aau: goto P_0c07b3aa;
case 0x0c07b3acu: goto P_0c07b3ac;
case 0x0c07b3aeu: goto P_0c07b3ae;
case 0x0c07b3b0u: goto P_0c07b3b0;
case 0x0c07b3b2u: goto P_0c07b3b2;
case 0x0c07b3b4u: goto P_0c07b3b4;
case 0x0c07b3b6u: goto P_0c07b3b6;
case 0x0c07b3b8u: goto P_0c07b3b8;
case 0x0c07b3bau: goto P_0c07b3ba;
case 0x0c07b3bcu: goto P_0c07b3bc;
case 0x0c07b3beu: goto P_0c07b3be;
case 0x0c07b3c0u: goto P_0c07b3c0;
case 0x0c07b3c2u: goto P_0c07b3c2;
case 0x0c07b3c4u: goto P_0c07b3c4;
case 0x0c07b3c6u: goto P_0c07b3c6;
case 0x0c07b3c8u: goto P_0c07b3c8;
case 0x0c07b3cau: goto P_0c07b3ca;
case 0x0c07b3ccu: goto P_0c07b3cc;
case 0x0c07b3ceu: goto P_0c07b3ce;
case 0x0c07b3d0u: goto P_0c07b3d0;
case 0x0c07b6c4u: goto P_0c07b6c4;
case 0x0c07b6c6u: goto P_0c07b6c6;
case 0x0c07b6c8u: goto P_0c07b6c8;
case 0x0c07b6cau: goto P_0c07b6ca;
case 0x0c07b6ccu: goto P_0c07b6cc;
case 0x0c07b6ceu: goto P_0c07b6ce;
case 0x0c07b6d0u: goto P_0c07b6d0;
case 0x0c07b6d2u: goto P_0c07b6d2;
case 0x0c07b6d4u: goto P_0c07b6d4;
case 0x0c07b6d6u: goto P_0c07b6d6;
case 0x0c07b6d8u: goto P_0c07b6d8;
case 0x0c07b6dau: goto P_0c07b6da;
case 0x0c07b6dcu: goto P_0c07b6dc;
case 0x0c07b6deu: goto P_0c07b6de;
case 0x0c07b6e0u: goto P_0c07b6e0;
case 0x0c07b6e2u: goto P_0c07b6e2;
case 0x0c07b6e4u: goto P_0c07b6e4;
case 0x0c07b6e6u: goto P_0c07b6e6;
case 0x0c07b6e8u: goto P_0c07b6e8;
case 0x0c07b6eau: goto P_0c07b6ea;
case 0x0c07b6ecu: goto P_0c07b6ec;
case 0x0c07b6eeu: goto P_0c07b6ee;
case 0x0c07b6f0u: goto P_0c07b6f0;
case 0x0c07b6f2u: goto P_0c07b6f2;
case 0x0c09518cu: goto P_0c09518c;
case 0x0c09518eu: goto P_0c09518e;
case 0x0c095190u: goto P_0c095190;
case 0x0c095192u: goto P_0c095192;
case 0x0c095194u: goto P_0c095194;
case 0x0c095196u: goto P_0c095196;
case 0x0c095198u: goto P_0c095198;
case 0x0c09519au: goto P_0c09519a;
case 0x0c09519cu: goto P_0c09519c;
case 0x0c09519eu: goto P_0c09519e;
case 0x0c0951a0u: goto P_0c0951a0;
case 0x0c0951a2u: goto P_0c0951a2;
case 0x0c0951a4u: goto P_0c0951a4;
case 0x0c0951a6u: goto P_0c0951a6;
case 0x0c0951a8u: goto P_0c0951a8;
case 0x0c0951aau: goto P_0c0951aa;
case 0x0c0951acu: goto P_0c0951ac;
case 0x0c0951aeu: goto P_0c0951ae;
case 0x0c0951b0u: goto P_0c0951b0;
case 0x0c0951b2u: goto P_0c0951b2;
case 0x0c0951b4u: goto P_0c0951b4;
case 0x0c0951b6u: goto P_0c0951b6;
case 0x0c0951b8u: goto P_0c0951b8;
case 0x0c0951bau: goto P_0c0951ba;
case 0x0c0951bcu: goto P_0c0951bc;
case 0x0c0951beu: goto P_0c0951be;
case 0x0c0951c0u: goto P_0c0951c0;
case 0x0c0951c2u: goto P_0c0951c2;
case 0x0c0951c4u: goto P_0c0951c4;
case 0x0c0951c6u: goto P_0c0951c6;
case 0x0c0951c8u: goto P_0c0951c8;
case 0x0c0951cau: goto P_0c0951ca;
case 0x0c0951ccu: goto P_0c0951cc;
case 0x0c0951ceu: goto P_0c0951ce;
case 0x0c0951d0u: goto P_0c0951d0;
case 0x0c0951d2u: goto P_0c0951d2;
case 0x0c0951d4u: goto P_0c0951d4;
case 0x0c0951d6u: goto P_0c0951d6;
case 0x0c0951d8u: goto P_0c0951d8;
case 0x0c0951dau: goto P_0c0951da;
case 0x0c0951dcu: goto P_0c0951dc;
case 0x0c0951deu: goto P_0c0951de;
case 0x0c0951e0u: goto P_0c0951e0;
case 0x0c0951e2u: goto P_0c0951e2;
case 0x0c0951e4u: goto P_0c0951e4;
case 0x0c0951e6u: goto P_0c0951e6;
case 0x0c0951e8u: goto P_0c0951e8;
case 0x0c0951eau: goto P_0c0951ea;
case 0x0c0951ecu: goto P_0c0951ec;
case 0x0c0951eeu: goto P_0c0951ee;
case 0x0c0951f0u: goto P_0c0951f0;
case 0x0c0951f2u: goto P_0c0951f2;
case 0x0c0951f4u: goto P_0c0951f4;
case 0x0c0951f6u: goto P_0c0951f6;
case 0x0c0951f8u: goto P_0c0951f8;
case 0x0c0951fau: goto P_0c0951fa;
case 0x0c0951fcu: goto P_0c0951fc;
case 0x0c0951feu: goto P_0c0951fe;
case 0x0c095200u: goto P_0c095200;
case 0x0c095202u: goto P_0c095202;
case 0x0c095204u: goto P_0c095204;
case 0x0c095206u: goto P_0c095206;
case 0x0c095208u: goto P_0c095208;
case 0x0c09520au: goto P_0c09520a;
case 0x0c09520cu: goto P_0c09520c;
case 0x0c09520eu: goto P_0c09520e;
case 0x0c095210u: goto P_0c095210;
case 0x0c095212u: goto P_0c095212;
case 0x0c095214u: goto P_0c095214;
case 0x0c095216u: goto P_0c095216;
case 0x0c095218u: goto P_0c095218;
case 0x0c09521au: goto P_0c09521a;
case 0x0c09521cu: goto P_0c09521c;
case 0x0c09521eu: goto P_0c09521e;
case 0x0c095220u: goto P_0c095220;
case 0x0c095222u: goto P_0c095222;
case 0x0c095224u: goto P_0c095224;
case 0x0c095226u: goto P_0c095226;
case 0x0c095228u: goto P_0c095228;
case 0x0c09522au: goto P_0c09522a;
case 0x0c09522cu: goto P_0c09522c;
case 0x0c09522eu: goto P_0c09522e;
case 0x0c095230u: goto P_0c095230;
case 0x0c095232u: goto P_0c095232;
case 0x0c095234u: goto P_0c095234;
case 0x0c095236u: goto P_0c095236;
case 0x0c095238u: goto P_0c095238;
case 0x0c09523au: goto P_0c09523a;
case 0x0c09523cu: goto P_0c09523c;
case 0x0c09523eu: goto P_0c09523e;
case 0x0c095240u: goto P_0c095240;
case 0x0c095242u: goto P_0c095242;
case 0x0c095244u: goto P_0c095244;
case 0x0c095246u: goto P_0c095246;
case 0x0c095248u: goto P_0c095248;
case 0x0c09524au: goto P_0c09524a;
case 0x0c095264u: goto P_0c095264;
case 0x0c095266u: goto P_0c095266;
case 0x0c095268u: goto P_0c095268;
case 0x0c09526au: goto P_0c09526a;
case 0x0c09526cu: goto P_0c09526c;
case 0x0c09526eu: goto P_0c09526e;
case 0x0c095270u: goto P_0c095270;
case 0x0c095272u: goto P_0c095272;
case 0x0c095274u: goto P_0c095274;
case 0x0c095276u: goto P_0c095276;
case 0x0c095278u: goto P_0c095278;
case 0x0c09527au: goto P_0c09527a;
case 0x0c09527cu: goto P_0c09527c;
case 0x0c09527eu: goto P_0c09527e;
case 0x0c095280u: goto P_0c095280;
case 0x0c095282u: goto P_0c095282;
case 0x0c095284u: goto P_0c095284;
case 0x0c095286u: goto P_0c095286;
case 0x0c095288u: goto P_0c095288;
case 0x0c09528au: goto P_0c09528a;
case 0x0c09528cu: goto P_0c09528c;
case 0x0c09528eu: goto P_0c09528e;
case 0x0c095290u: goto P_0c095290;
case 0x0c095292u: goto P_0c095292;
case 0x0c095294u: goto P_0c095294;
case 0x0c095296u: goto P_0c095296;
case 0x0c095298u: goto P_0c095298;
case 0x0c09529au: goto P_0c09529a;
case 0x0c09529cu: goto P_0c09529c;
case 0x0c09529eu: goto P_0c09529e;
case 0x0c0952a0u: goto P_0c0952a0;
case 0x0c0952a2u: goto P_0c0952a2;
case 0x0c0952a4u: goto P_0c0952a4;
case 0x0c0952a6u: goto P_0c0952a6;
case 0x0c0952a8u: goto P_0c0952a8;
case 0x0c0952aau: goto P_0c0952aa;
case 0x0c0952acu: goto P_0c0952ac;
case 0x0c0952aeu: goto P_0c0952ae;
case 0x0c0952b0u: goto P_0c0952b0;
case 0x0c0952b2u: goto P_0c0952b2;
case 0x0c0952b4u: goto P_0c0952b4;
case 0x0c0952b6u: goto P_0c0952b6;
case 0x0c0952b8u: goto P_0c0952b8;
case 0x0c0952bau: goto P_0c0952ba;
case 0x0c0952bcu: goto P_0c0952bc;
case 0x0c0952beu: goto P_0c0952be;
case 0x0c0952c0u: goto P_0c0952c0;
case 0x0c0952c2u: goto P_0c0952c2;
case 0x0c0952c4u: goto P_0c0952c4;
case 0x0c0952c6u: goto P_0c0952c6;
case 0x0c0952c8u: goto P_0c0952c8;
case 0x0c0952cau: goto P_0c0952ca;
case 0x0c0952ccu: goto P_0c0952cc;
case 0x0c0952ceu: goto P_0c0952ce;
case 0x0c0952d0u: goto P_0c0952d0;
case 0x0c0952d2u: goto P_0c0952d2;
case 0x0c0952d4u: goto P_0c0952d4;
case 0x0c0952d6u: goto P_0c0952d6;
case 0x0c0952d8u: goto P_0c0952d8;
case 0x0c0952dau: goto P_0c0952da;
case 0x0c0952dcu: goto P_0c0952dc;
case 0x0c0952deu: goto P_0c0952de;
case 0x0c0952e0u: goto P_0c0952e0;
case 0x0c0952e2u: goto P_0c0952e2;
case 0x0c0952e4u: goto P_0c0952e4;
case 0x0c0952e6u: goto P_0c0952e6;
case 0x0c0952e8u: goto P_0c0952e8;
case 0x0c0952eau: goto P_0c0952ea;
case 0x0c0952ecu: goto P_0c0952ec;
case 0x0c0952eeu: goto P_0c0952ee;
case 0x0c0952f0u: goto P_0c0952f0;
case 0x0c0952f2u: goto P_0c0952f2;
case 0x0c0952f4u: goto P_0c0952f4;
case 0x0c0952f6u: goto P_0c0952f6;
case 0x0c0952f8u: goto P_0c0952f8;
case 0x0c0952fau: goto P_0c0952fa;
case 0x0c0952fcu: goto P_0c0952fc;
case 0x0c0952feu: goto P_0c0952fe;
case 0x0c095300u: goto P_0c095300;
case 0x0c095302u: goto P_0c095302;
case 0x0c095304u: goto P_0c095304;
case 0x0c095306u: goto P_0c095306;
case 0x0c095308u: goto P_0c095308;
case 0x0c09530au: goto P_0c09530a;
case 0x0c09530cu: goto P_0c09530c;
case 0x0c09530eu: goto P_0c09530e;
case 0x0c095310u: goto P_0c095310;
case 0x0c095312u: goto P_0c095312;
case 0x0c095314u: goto P_0c095314;
case 0x0c095316u: goto P_0c095316;
case 0x0c095318u: goto P_0c095318;
case 0x0c09531au: goto P_0c09531a;
case 0x0c09531cu: goto P_0c09531c;
case 0x0c09531eu: goto P_0c09531e;
case 0x0c095320u: goto P_0c095320;
case 0x0c095322u: goto P_0c095322;
case 0x0c095324u: goto P_0c095324;
case 0x0c095326u: goto P_0c095326;
case 0x0c095328u: goto P_0c095328;
case 0x0c0c10a2u: goto P_0c0c10a2;
case 0x0c0c10a4u: goto P_0c0c10a4;
case 0x0c0c10a6u: goto P_0c0c10a6;
case 0x0c0c10a8u: goto P_0c0c10a8;
case 0x0c0c10aau: goto P_0c0c10aa;
case 0x0c0c10acu: goto P_0c0c10ac;
case 0x0c0c10aeu: goto P_0c0c10ae;
case 0x0c0c10b0u: goto P_0c0c10b0;
case 0x0c0c10b2u: goto P_0c0c10b2;
case 0x0c0c10b4u: goto P_0c0c10b4;
case 0x0c0c10b6u: goto P_0c0c10b6;
case 0x0c0c10b8u: goto P_0c0c10b8;
case 0x0c0c10bau: goto P_0c0c10ba;
case 0x0c0c10bcu: goto P_0c0c10bc;
case 0x0c0c10beu: goto P_0c0c10be;
case 0x0c0c10c0u: goto P_0c0c10c0;
case 0x0c0c10c2u: goto P_0c0c10c2;
case 0x0c0c10c4u: goto P_0c0c10c4;
case 0x0c0c10c6u: goto P_0c0c10c6;
case 0x0c0c10c8u: goto P_0c0c10c8;
case 0x0c0c10cau: goto P_0c0c10ca;
case 0x0c0c10ccu: goto P_0c0c10cc;
case 0x0c0c10ceu: goto P_0c0c10ce;
case 0x0c0c10d0u: goto P_0c0c10d0;
case 0x0c0c10d2u: goto P_0c0c10d2;
case 0x0c0c10d4u: goto P_0c0c10d4;
case 0x0c0c10d6u: goto P_0c0c10d6;
case 0x0c0c10d8u: goto P_0c0c10d8;
case 0x0c0c10dau: goto P_0c0c10da;
case 0x0c0c10dcu: goto P_0c0c10dc;
case 0x0c0c10deu: goto P_0c0c10de;
case 0x0c0c10e0u: goto P_0c0c10e0;
case 0x0c0c10e2u: goto P_0c0c10e2;
case 0x0c0c10e4u: goto P_0c0c10e4;
case 0x0c0c10e6u: goto P_0c0c10e6;
case 0x0c0c10e8u: goto P_0c0c10e8;
case 0x0c0c10eau: goto P_0c0c10ea;
case 0x0c0c10ecu: goto P_0c0c10ec;
case 0x0c0c10eeu: goto P_0c0c10ee;
case 0x0c0c10f0u: goto P_0c0c10f0;
case 0x0c0c10f2u: goto P_0c0c10f2;
case 0x0c0c10f4u: goto P_0c0c10f4;
case 0x0c0c10f6u: goto P_0c0c10f6;
case 0x0c0c10f8u: goto P_0c0c10f8;
case 0x0c0c10fau: goto P_0c0c10fa;
case 0x0c0c10fcu: goto P_0c0c10fc;
case 0x0c0c10feu: goto P_0c0c10fe;
case 0x0c0c1100u: goto P_0c0c1100;
case 0x0c0c1102u: goto P_0c0c1102;
case 0x0c0c1104u: goto P_0c0c1104;
case 0x0c0c1106u: goto P_0c0c1106;
case 0x0c0c1108u: goto P_0c0c1108;
case 0x0c0c110au: goto P_0c0c110a;
case 0x0c0c110cu: goto P_0c0c110c;
case 0x0c0c110eu: goto P_0c0c110e;
case 0x0c0c1110u: goto P_0c0c1110;
case 0x0c0c1112u: goto P_0c0c1112;
case 0x0c0c1114u: goto P_0c0c1114;
case 0x0c0c1116u: goto P_0c0c1116;
case 0x0c0c1118u: goto P_0c0c1118;
case 0x0c0c111au: goto P_0c0c111a;
case 0x0c0c111cu: goto P_0c0c111c;
case 0x0c0c111eu: goto P_0c0c111e;
case 0x0c0c1120u: goto P_0c0c1120;
case 0x0c0c1122u: goto P_0c0c1122;
case 0x0c0c1124u: goto P_0c0c1124;
case 0x0c0c1126u: goto P_0c0c1126;
case 0x0c0c1128u: goto P_0c0c1128;
case 0x0c0c112au: goto P_0c0c112a;
case 0x0c0c112cu: goto P_0c0c112c;
case 0x0c0c112eu: goto P_0c0c112e;
case 0x0c0c1130u: goto P_0c0c1130;
case 0x0c0c1132u: goto P_0c0c1132;
case 0x0c0c1134u: goto P_0c0c1134;
case 0x0c0c1136u: goto P_0c0c1136;
case 0x0c0c1138u: goto P_0c0c1138;
case 0x0c0c113au: goto P_0c0c113a;
case 0x0c0c113cu: goto P_0c0c113c;
case 0x0c0c113eu: goto P_0c0c113e;
case 0x0c0c1140u: goto P_0c0c1140;
case 0x0c0c1142u: goto P_0c0c1142;
case 0x0c0c1144u: goto P_0c0c1144;
case 0x0c0c1146u: goto P_0c0c1146;
case 0x0c0c1148u: goto P_0c0c1148;
case 0x0c0c114au: goto P_0c0c114a;
case 0x0c0c114cu: goto P_0c0c114c;
case 0x0c0c114eu: goto P_0c0c114e;
case 0x0c0c1150u: goto P_0c0c1150;
case 0x0c0c1152u: goto P_0c0c1152;
case 0x0c0c1154u: goto P_0c0c1154;
case 0x0c0c1156u: goto P_0c0c1156;
case 0x0c0c1158u: goto P_0c0c1158;
case 0x0c0c115au: goto P_0c0c115a;
case 0x0c0c115cu: goto P_0c0c115c;
case 0x0c0c115eu: goto P_0c0c115e;
case 0x0c0c1160u: goto P_0c0c1160;
case 0x0c0c1162u: goto P_0c0c1162;
case 0x0c0c1164u: goto P_0c0c1164;
case 0x0c0c1166u: goto P_0c0c1166;
case 0x0c0c1168u: goto P_0c0c1168;
case 0x0c0c116au: goto P_0c0c116a;
case 0x0c0c116cu: goto P_0c0c116c;
case 0x0c0c116eu: goto P_0c0c116e;
case 0x0c0c1170u: goto P_0c0c1170;
case 0x0c0c1172u: goto P_0c0c1172;
case 0x0c0c1174u: goto P_0c0c1174;
case 0x0c0c1176u: goto P_0c0c1176;
case 0x0c0c1178u: goto P_0c0c1178;
case 0x0c0c117au: goto P_0c0c117a;
case 0x0c0c117cu: goto P_0c0c117c;
case 0x0c0c124eu: goto P_0c0c124e;
case 0x0c0c1250u: goto P_0c0c1250;
case 0x0c0c1252u: goto P_0c0c1252;
case 0x0c0c1254u: goto P_0c0c1254;
case 0x0c0c1256u: goto P_0c0c1256;
case 0x0c0c1258u: goto P_0c0c1258;
case 0x0c0c125au: goto P_0c0c125a;
case 0x0c0c125cu: goto P_0c0c125c;
case 0x0c0c125eu: goto P_0c0c125e;
case 0x0c0c1260u: goto P_0c0c1260;
case 0x0c0c1262u: goto P_0c0c1262;
case 0x0c0c1264u: goto P_0c0c1264;
case 0x0c0c1266u: goto P_0c0c1266;
case 0x0c0c1268u: goto P_0c0c1268;
case 0x0c0c126au: goto P_0c0c126a;
case 0x0c0c126cu: goto P_0c0c126c;
case 0x0c0c126eu: goto P_0c0c126e;
case 0x0c0c1270u: goto P_0c0c1270;
case 0x0c0c1272u: goto P_0c0c1272;
case 0x0c0c1274u: goto P_0c0c1274;
case 0x0c0c1276u: goto P_0c0c1276;
case 0x0c0c1278u: goto P_0c0c1278;
case 0x0c0c127au: goto P_0c0c127a;
case 0x0c0c127cu: goto P_0c0c127c;
case 0x0c0c127eu: goto P_0c0c127e;
case 0x0c0c1280u: goto P_0c0c1280;
case 0x0c0c1282u: goto P_0c0c1282;
case 0x0c0c1284u: goto P_0c0c1284;
case 0x0c0c1286u: goto P_0c0c1286;
case 0x0c0c1288u: goto P_0c0c1288;
case 0x0c0c128au: goto P_0c0c128a;
case 0x0c0c128cu: goto P_0c0c128c;
case 0x0c0c128eu: goto P_0c0c128e;
case 0x0c0c1290u: goto P_0c0c1290;
case 0x0c0c1292u: goto P_0c0c1292;
case 0x0c0c1294u: goto P_0c0c1294;
case 0x0c0c1296u: goto P_0c0c1296;
case 0x0c0c1298u: goto P_0c0c1298;
case 0x0c0c129au: goto P_0c0c129a;
case 0x0c0c129cu: goto P_0c0c129c;
case 0x0c0c129eu: goto P_0c0c129e;
case 0x0c0c12a0u: goto P_0c0c12a0;
case 0x0c0c12a2u: goto P_0c0c12a2;
case 0x0c0c12a4u: goto P_0c0c12a4;
case 0x0c0c12a6u: goto P_0c0c12a6;
case 0x0c0c12a8u: goto P_0c0c12a8;
case 0x0c0c12aau: goto P_0c0c12aa;
case 0x0c0c12acu: goto P_0c0c12ac;
case 0x0c0c12aeu: goto P_0c0c12ae;
case 0x0c0c12b0u: goto P_0c0c12b0;
case 0x0c0c12b2u: goto P_0c0c12b2;
case 0x0c0c12b4u: goto P_0c0c12b4;
case 0x0c0c12b6u: goto P_0c0c12b6;
case 0x0c0c12b8u: goto P_0c0c12b8;
case 0x0c0c12bau: goto P_0c0c12ba;
case 0x0c0c12bcu: goto P_0c0c12bc;
case 0x0c0c12beu: goto P_0c0c12be;
case 0x0c0c12c0u: goto P_0c0c12c0;
case 0x0c0c12c2u: goto P_0c0c12c2;
case 0x0c0c12c4u: goto P_0c0c12c4;
case 0x0c0c12c6u: goto P_0c0c12c6;
case 0x0c0c12c8u: goto P_0c0c12c8;
case 0x0c0c12cau: goto P_0c0c12ca;
case 0x0c0c12ccu: goto P_0c0c12cc;
case 0x0c0c12ceu: goto P_0c0c12ce;
case 0x0c0c12d0u: goto P_0c0c12d0;
case 0x0c0c12d2u: goto P_0c0c12d2;
case 0x0c0c12d4u: goto P_0c0c12d4;
case 0x0c0c12d6u: goto P_0c0c12d6;
case 0x0c0c1fbau: goto P_0c0c1fba;
case 0x0c0c1fbcu: goto P_0c0c1fbc;
case 0x0c0c1fbeu: goto P_0c0c1fbe;
case 0x0c0c1fc0u: goto P_0c0c1fc0;
case 0x0c0c1fc2u: goto P_0c0c1fc2;
case 0x0c0c1fc4u: goto P_0c0c1fc4;
case 0x0c0c1fc6u: goto P_0c0c1fc6;
case 0x0c0c1fc8u: goto P_0c0c1fc8;
case 0x0c0c1fcau: goto P_0c0c1fca;
case 0x0c0c1fccu: goto P_0c0c1fcc;
case 0x0c0c1fceu: goto P_0c0c1fce;
case 0x0c0c1fd0u: goto P_0c0c1fd0;
case 0x0c0c1fd2u: goto P_0c0c1fd2;
case 0x0c0c1fd4u: goto P_0c0c1fd4;
case 0x0c0c1fd6u: goto P_0c0c1fd6;
case 0x0c0c1fd8u: goto P_0c0c1fd8;
case 0x0c0c1fdau: goto P_0c0c1fda;
case 0x0c0c1fdcu: goto P_0c0c1fdc;
case 0x0c0c1fdeu: goto P_0c0c1fde;
case 0x0c0c1fe0u: goto P_0c0c1fe0;
case 0x0c0c1fe2u: goto P_0c0c1fe2;
case 0x0c0c1fe4u: goto P_0c0c1fe4;
case 0x0c0c1fe6u: goto P_0c0c1fe6;
case 0x0c0c1fe8u: goto P_0c0c1fe8;
case 0x0c0c1feau: goto P_0c0c1fea;
case 0x0c0c1fecu: goto P_0c0c1fec;
case 0x0c0c1feeu: goto P_0c0c1fee;
case 0x0c0c1ff0u: goto P_0c0c1ff0;
case 0x0c0c1ff2u: goto P_0c0c1ff2;
case 0x0c0c1ff4u: goto P_0c0c1ff4;
case 0x0c0c1ff6u: goto P_0c0c1ff6;
case 0x0c0c1ff8u: goto P_0c0c1ff8;
case 0x0c0c1ffau: goto P_0c0c1ffa;
case 0x0c0c1ffcu: goto P_0c0c1ffc;
case 0x0c0c1ffeu: goto P_0c0c1ffe;
case 0x0c0c2000u: goto P_0c0c2000;
case 0x0c0c2002u: goto P_0c0c2002;
case 0x0c0c2004u: goto P_0c0c2004;
case 0x0c0c2006u: goto P_0c0c2006;
case 0x0c0c2008u: goto P_0c0c2008;
case 0x0c0c200au: goto P_0c0c200a;
case 0x0c0c200cu: goto P_0c0c200c;
case 0x0c0c200eu: goto P_0c0c200e;
case 0x0c0c2010u: goto P_0c0c2010;
case 0x0c0c2012u: goto P_0c0c2012;
case 0x0c0c2014u: goto P_0c0c2014;
case 0x0c0c2016u: goto P_0c0c2016;
case 0x0c0c2018u: goto P_0c0c2018;
case 0x0c0c201au: goto P_0c0c201a;
case 0x0c0c201cu: goto P_0c0c201c;
case 0x0c0c201eu: goto P_0c0c201e;
case 0x0c0c2020u: goto P_0c0c2020;
case 0x0c0c2022u: goto P_0c0c2022;
case 0x0c0c2024u: goto P_0c0c2024;
case 0x0c0c2026u: goto P_0c0c2026;
case 0x0c0c2028u: goto P_0c0c2028;
case 0x0c0c202au: goto P_0c0c202a;
case 0x0c0c202cu: goto P_0c0c202c;
case 0x0c0c202eu: goto P_0c0c202e;
case 0x0c0c2030u: goto P_0c0c2030;
case 0x0c0c2032u: goto P_0c0c2032;
case 0x0c0c2034u: goto P_0c0c2034;
case 0x0c0c2036u: goto P_0c0c2036;
case 0x0c0c2038u: goto P_0c0c2038;
case 0x0c0c203au: goto P_0c0c203a;
case 0x0c0c203cu: goto P_0c0c203c;
case 0x0c0c203eu: goto P_0c0c203e;
case 0x0c0c2040u: goto P_0c0c2040;
case 0x0c0c2042u: goto P_0c0c2042;
case 0x0c0c2044u: goto P_0c0c2044;
case 0x0c0c2046u: goto P_0c0c2046;
case 0x0c0c2048u: goto P_0c0c2048;
case 0x0c0c204au: goto P_0c0c204a;
case 0x0c0c204cu: goto P_0c0c204c;
case 0x0c0c204eu: goto P_0c0c204e;
case 0x0c0c2050u: goto P_0c0c2050;
case 0x0c0c2052u: goto P_0c0c2052;
case 0x0c0c2054u: goto P_0c0c2054;
case 0x0c0c2056u: goto P_0c0c2056;
case 0x0c0c2058u: goto P_0c0c2058;
case 0x0c0c205au: goto P_0c0c205a;
case 0x0c0c205cu: goto P_0c0c205c;
case 0x0c0c205eu: goto P_0c0c205e;
case 0x0c0c2060u: goto P_0c0c2060;
case 0x0c0c2062u: goto P_0c0c2062;
case 0x0c0c2064u: goto P_0c0c2064;
case 0x0c0c2066u: goto P_0c0c2066;
case 0x0c0c2068u: goto P_0c0c2068;
case 0x0c0c206au: goto P_0c0c206a;
case 0x0c0c206cu: goto P_0c0c206c;
case 0x0c0c206eu: goto P_0c0c206e;
case 0x0c0c2070u: goto P_0c0c2070;
case 0x0c0c2072u: goto P_0c0c2072;
case 0x0c0c2074u: goto P_0c0c2074;
case 0x0c0c2076u: goto P_0c0c2076;
case 0x0c0c2078u: goto P_0c0c2078;
case 0x0c0c207au: goto P_0c0c207a;
case 0x0c0c207cu: goto P_0c0c207c;
case 0x0c0c207eu: goto P_0c0c207e;
case 0x0c0c2080u: goto P_0c0c2080;
case 0x0c0c2082u: goto P_0c0c2082;
case 0x0c0c2084u: goto P_0c0c2084;
case 0x0c0c2086u: goto P_0c0c2086;
case 0x0c0c2088u: goto P_0c0c2088;
case 0x0c0c208au: goto P_0c0c208a;
case 0x0c0c208cu: goto P_0c0c208c;
case 0x0c0c208eu: goto P_0c0c208e;
case 0x0c0c2090u: goto P_0c0c2090;
case 0x0c0c2092u: goto P_0c0c2092;
case 0x0c0c2094u: goto P_0c0c2094;
case 0x0c0c2096u: goto P_0c0c2096;
case 0x0c0c2098u: goto P_0c0c2098;
case 0x0c0c209au: goto P_0c0c209a;
case 0x0c0c209cu: goto P_0c0c209c;
case 0x0c0c209eu: goto P_0c0c209e;
case 0x0c0c20a0u: goto P_0c0c20a0;
case 0x0c0c20a2u: goto P_0c0c20a2;
case 0x0c0c20a4u: goto P_0c0c20a4;
case 0x0c0c20a6u: goto P_0c0c20a6;
case 0x0c0c20a8u: goto P_0c0c20a8;
case 0x0c0c20aau: goto P_0c0c20aa;
case 0x0c0c20acu: goto P_0c0c20ac;
case 0x0c0c20aeu: goto P_0c0c20ae;
case 0x0c0c20b0u: goto P_0c0c20b0;
case 0x0c0c20b2u: goto P_0c0c20b2;
case 0x0c0c20b4u: goto P_0c0c20b4;
case 0x0c0c20b6u: goto P_0c0c20b6;
case 0x0c0c20b8u: goto P_0c0c20b8;
case 0x0c0c20bau: goto P_0c0c20ba;
case 0x0c0c20bcu: goto P_0c0c20bc;
case 0x0c0c20beu: goto P_0c0c20be;
case 0x0c0c20c0u: goto P_0c0c20c0;
case 0x0c0c20c2u: goto P_0c0c20c2;
case 0x0c0c20c4u: goto P_0c0c20c4;
case 0x0c0c20c6u: goto P_0c0c20c6;
case 0x0c0c20c8u: goto P_0c0c20c8;
case 0x0c0c20cau: goto P_0c0c20ca;
case 0x0c0c20ccu: goto P_0c0c20cc;
case 0x0c0c20ceu: goto P_0c0c20ce;
case 0x0c0c20d0u: goto P_0c0c20d0;
case 0x0c0c20d2u: goto P_0c0c20d2;
case 0x0c0c20d4u: goto P_0c0c20d4;
case 0x0c0c20d6u: goto P_0c0c20d6;
case 0x0c0c20d8u: goto P_0c0c20d8;
case 0x0c0c20dau: goto P_0c0c20da;
case 0x0c0c20dcu: goto P_0c0c20dc;
case 0x0c0c20deu: goto P_0c0c20de;
case 0x0c0c20e0u: goto P_0c0c20e0;
case 0x0c0c20e2u: goto P_0c0c20e2;
case 0x0c0c20e4u: goto P_0c0c20e4;
case 0x0c0c20e6u: goto P_0c0c20e6;
case 0x0c0c20e8u: goto P_0c0c20e8;
case 0x0c0c20eau: goto P_0c0c20ea;
case 0x0c0c20ecu: goto P_0c0c20ec;
case 0x0c0c20eeu: goto P_0c0c20ee;
case 0x0c0c20f0u: goto P_0c0c20f0;
case 0x0c0c20f2u: goto P_0c0c20f2;
case 0x0c0c20f4u: goto P_0c0c20f4;
case 0x0c0c20f6u: goto P_0c0c20f6;
case 0x0c0c20f8u: goto P_0c0c20f8;
case 0x0c0c20fau: goto P_0c0c20fa;
case 0x0c0c20fcu: goto P_0c0c20fc;
case 0x0c0c20feu: goto P_0c0c20fe;
case 0x0c0c2100u: goto P_0c0c2100;
case 0x0c0c2102u: goto P_0c0c2102;
case 0x0c0c2104u: goto P_0c0c2104;
case 0x0c0c2106u: goto P_0c0c2106;
case 0x0c0c2108u: goto P_0c0c2108;
case 0x0c0c210au: goto P_0c0c210a;
case 0x0c0c210cu: goto P_0c0c210c;
case 0x0c0c210eu: goto P_0c0c210e;
case 0x0c0c2110u: goto P_0c0c2110;
case 0x0c0c2112u: goto P_0c0c2112;
case 0x0c0c2114u: goto P_0c0c2114;
case 0x0c0c2116u: goto P_0c0c2116;
case 0x0c0c2118u: goto P_0c0c2118;
case 0x0c0c211au: goto P_0c0c211a;
case 0x0c0c211cu: goto P_0c0c211c;
case 0x0c0c211eu: goto P_0c0c211e;
case 0x0c0c2120u: goto P_0c0c2120;
case 0x0c0c2122u: goto P_0c0c2122;
case 0x0c0c2124u: goto P_0c0c2124;
case 0x0c0c2126u: goto P_0c0c2126;
case 0x0c0c2128u: goto P_0c0c2128;
case 0x0c0c212au: goto P_0c0c212a;
case 0x0c0c212cu: goto P_0c0c212c;
case 0x0c0c212eu: goto P_0c0c212e;
case 0x0c0c2130u: goto P_0c0c2130;
case 0x0c0c2132u: goto P_0c0c2132;
case 0x0c0c2134u: goto P_0c0c2134;
case 0x0c0c2136u: goto P_0c0c2136;
case 0x0c0c2138u: goto P_0c0c2138;
case 0x0c0c213au: goto P_0c0c213a;
case 0x0c0c213cu: goto P_0c0c213c;
case 0x0c0c213eu: goto P_0c0c213e;
case 0x0c0c2140u: goto P_0c0c2140;
case 0x0c0c2142u: goto P_0c0c2142;
case 0x0c0c2144u: goto P_0c0c2144;
case 0x0c0c2146u: goto P_0c0c2146;
case 0x0c0c2148u: goto P_0c0c2148;
case 0x0c0c214au: goto P_0c0c214a;
case 0x0c0c214cu: goto P_0c0c214c;
case 0x0c0c214eu: goto P_0c0c214e;
case 0x0c0c2150u: goto P_0c0c2150;
case 0x0c0c2152u: goto P_0c0c2152;
case 0x0c0c2154u: goto P_0c0c2154;
case 0x0c0c2156u: goto P_0c0c2156;
case 0x0c0c2158u: goto P_0c0c2158;
case 0x0c0c215au: goto P_0c0c215a;
case 0x0c0c215cu: goto P_0c0c215c;
case 0x0c0c215eu: goto P_0c0c215e;
case 0x0c0c2160u: goto P_0c0c2160;
case 0x0c0c2162u: goto P_0c0c2162;
case 0x0c0c2164u: goto P_0c0c2164;
case 0x0c0c2166u: goto P_0c0c2166;
case 0x0c0c2168u: goto P_0c0c2168;
case 0x0c0c216au: goto P_0c0c216a;
case 0x0c0c216cu: goto P_0c0c216c;
case 0x0c0c216eu: goto P_0c0c216e;
case 0x0c0c2170u: goto P_0c0c2170;
case 0x0c0c2172u: goto P_0c0c2172;
case 0x0c0c2184u: goto P_0c0c2184;
case 0x0c0c2186u: goto P_0c0c2186;
case 0x0c0c2188u: goto P_0c0c2188;
case 0x0c0c218au: goto P_0c0c218a;
case 0x0c0c218cu: goto P_0c0c218c;
case 0x0c0c218eu: goto P_0c0c218e;
case 0x0c0c2190u: goto P_0c0c2190;
case 0x0c0c2192u: goto P_0c0c2192;
case 0x0c0c2194u: goto P_0c0c2194;
case 0x0c0c2196u: goto P_0c0c2196;
case 0x0c0c2198u: goto P_0c0c2198;
case 0x0c0c219au: goto P_0c0c219a;
case 0x0c0c219cu: goto P_0c0c219c;
case 0x0c0c219eu: goto P_0c0c219e;
case 0x0c0c21a0u: goto P_0c0c21a0;
case 0x0c0c21a2u: goto P_0c0c21a2;
case 0x0c0c21a4u: goto P_0c0c21a4;
case 0x0c0c21a6u: goto P_0c0c21a6;
case 0x0c0c21a8u: goto P_0c0c21a8;
case 0x0c0c21aau: goto P_0c0c21aa;
case 0x0c0c21acu: goto P_0c0c21ac;
case 0x0c0c21aeu: goto P_0c0c21ae;
case 0x0c0c21b0u: goto P_0c0c21b0;
case 0x0c0c21b2u: goto P_0c0c21b2;
case 0x0c0c21b4u: goto P_0c0c21b4;
case 0x0c0c21b6u: goto P_0c0c21b6;
case 0x0c0c21b8u: goto P_0c0c21b8;
case 0x0c0c21bau: goto P_0c0c21ba;
case 0x0c0c21bcu: goto P_0c0c21bc;
case 0x0c0c21beu: goto P_0c0c21be;
case 0x0c0c21c0u: goto P_0c0c21c0;
case 0x0c0c21c2u: goto P_0c0c21c2;
case 0x0c0c21c4u: goto P_0c0c21c4;
case 0x0c0c21c6u: goto P_0c0c21c6;
case 0x0c0c21c8u: goto P_0c0c21c8;
case 0x0c0c21cau: goto P_0c0c21ca;
case 0x0c0c21ccu: goto P_0c0c21cc;
case 0x0c0c21ceu: goto P_0c0c21ce;
case 0x0c0c21d0u: goto P_0c0c21d0;
case 0x0c0c21d2u: goto P_0c0c21d2;
case 0x0c0c21d4u: goto P_0c0c21d4;
case 0x0c0c21d6u: goto P_0c0c21d6;
case 0x0c0c21d8u: goto P_0c0c21d8;
case 0x0c0c21dau: goto P_0c0c21da;
case 0x0c0c21dcu: goto P_0c0c21dc;
case 0x0c0c21deu: goto P_0c0c21de;
case 0x0c0c21e0u: goto P_0c0c21e0;
case 0x0c0c21e2u: goto P_0c0c21e2;
case 0x0c0c21e4u: goto P_0c0c21e4;
case 0x0c0c21e6u: goto P_0c0c21e6;
case 0x0c0c21e8u: goto P_0c0c21e8;
case 0x0c0c21eau: goto P_0c0c21ea;
case 0x0c0c21ecu: goto P_0c0c21ec;
case 0x0c0c21eeu: goto P_0c0c21ee;
case 0x0c0c21f0u: goto P_0c0c21f0;
case 0x0c0c21f2u: goto P_0c0c21f2;
case 0x0c0c21f4u: goto P_0c0c21f4;
case 0x0c0c21f6u: goto P_0c0c21f6;
case 0x0c0c21f8u: goto P_0c0c21f8;
case 0x0c0c21fau: goto P_0c0c21fa;
case 0x0c0c21fcu: goto P_0c0c21fc;
case 0x0c0c21feu: goto P_0c0c21fe;
case 0x0c0c2200u: goto P_0c0c2200;
case 0x0c0c2202u: goto P_0c0c2202;
case 0x0c0c2204u: goto P_0c0c2204;
case 0x0c0c2206u: goto P_0c0c2206;
case 0x0c0c2208u: goto P_0c0c2208;
case 0x0c0c220au: goto P_0c0c220a;
case 0x0c0c220cu: goto P_0c0c220c;
case 0x0c0c220eu: goto P_0c0c220e;
case 0x0c0c2210u: goto P_0c0c2210;
case 0x0c0c2212u: goto P_0c0c2212;
case 0x0c0c2214u: goto P_0c0c2214;
case 0x0c0c2216u: goto P_0c0c2216;
case 0x0c0c2218u: goto P_0c0c2218;
case 0x0c0c221au: goto P_0c0c221a;
case 0x0c0c221cu: goto P_0c0c221c;
case 0x0c0c221eu: goto P_0c0c221e;
case 0x0c0c2220u: goto P_0c0c2220;
case 0x0c0c2222u: goto P_0c0c2222;
case 0x0c0c2224u: goto P_0c0c2224;
case 0x0c0c2226u: goto P_0c0c2226;
case 0x0c0c2228u: goto P_0c0c2228;
case 0x0c0c222au: goto P_0c0c222a;
case 0x0c0c222cu: goto P_0c0c222c;
case 0x0c0c222eu: goto P_0c0c222e;
case 0x0c0c2230u: goto P_0c0c2230;
case 0x0c0c2232u: goto P_0c0c2232;
case 0x0c0c2234u: goto P_0c0c2234;
case 0x0c0c2236u: goto P_0c0c2236;
case 0x0c0c2238u: goto P_0c0c2238;
case 0x0c0c223au: goto P_0c0c223a;
case 0x0c0c223cu: goto P_0c0c223c;
case 0x0c0c223eu: goto P_0c0c223e;
case 0x0c0c2240u: goto P_0c0c2240;
case 0x0c0c2242u: goto P_0c0c2242;
case 0x0c0c2244u: goto P_0c0c2244;
case 0x0c0c6742u: goto P_0c0c6742;
case 0x0c0c6744u: goto P_0c0c6744;
case 0x0c0c6746u: goto P_0c0c6746;
case 0x0c0c6748u: goto P_0c0c6748;
default: return vf3_matrix_family(target,s,ram);
}
P_0c03b304: /* original 4f22, guest PC 0x0c03b304 */
if(!s->budget--) { s->failed_pc=0x0c03b304u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c03b306;
P_0c03b306: /* original 4729, guest PC 0x0c03b306 */
if(!s->budget--) { s->failed_pc=0x0c03b306u; return 0; }
r[7]>>=16;
goto P_0c03b308;
P_0c03b308: /* original 6543, guest PC 0x0c03b308 */
if(!s->budget--) { s->failed_pc=0x0c03b308u; return 0; }
r[5]=r[4];
goto P_0c03b30a;
P_0c03b30a: /* original 4719, guest PC 0x0c03b30a */
if(!s->budget--) { s->failed_pc=0x0c03b30au; return 0; }
r[7]>>=8;
goto P_0c03b30c;
P_0c03b30c: /* original 6643, guest PC 0x0c03b30c */
if(!s->budget--) { s->failed_pc=0x0c03b30cu; return 0; }
r[6]=r[4];
goto P_0c03b30e;
P_0c03b30e: /* original 677e, guest PC 0x0c03b30e */
if(!s->budget--) { s->failed_pc=0x0c03b30eu; return 0; }
r[7]=(uint32_t)(int32_t)(int8_t)r[7];
goto P_0c03b310;
P_0c03b310: /* original 7ffc, guest PC 0x0c03b310 */
if(!s->budget--) { s->failed_pc=0x0c03b310u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c03b312;
P_0c03b312: /* original 6073, guest PC 0x0c03b312 */
if(!s->budget--) { s->failed_pc=0x0c03b312u; return 0; }
r[0]=r[7];
goto P_0c03b314;
P_0c03b314: /* original 6ef3, guest PC 0x0c03b314 */
if(!s->budget--) { s->failed_pc=0x0c03b314u; return 0; }
r[14]=r[15];
goto P_0c03b316;
P_0c03b316: /* original 4529, guest PC 0x0c03b316 */
if(!s->budget--) { s->failed_pc=0x0c03b316u; return 0; }
r[5]>>=16;
goto P_0c03b318;
P_0c03b318: /* original 80e3, guest PC 0x0c03b318 */
if(!s->budget--) { s->failed_pc=0x0c03b318u; return 0; }
write(ram,r[14]+3,r[0],1);
goto P_0c03b31a;
P_0c03b31a: /* original 655f, guest PC 0x0c03b31a */
if(!s->budget--) { s->failed_pc=0x0c03b31au; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)r[5];
goto P_0c03b31c;
P_0c03b31c: /* original 6053, guest PC 0x0c03b31c */
if(!s->budget--) { s->failed_pc=0x0c03b31cu; return 0; }
r[0]=r[5];
goto P_0c03b31e;
P_0c03b31e: /* original e3f8, guest PC 0x0c03b31e */
if(!s->budget--) { s->failed_pc=0x0c03b31eu; return 0; }
r[3]=0xfffffff8u;
goto P_0c03b320;
P_0c03b320: /* original 80e2, guest PC 0x0c03b320 */
if(!s->budget--) { s->failed_pc=0x0c03b320u; return 0; }
write(ram,r[14]+2,r[0],1);
goto P_0c03b322;
P_0c03b322: /* original 463c, guest PC 0x0c03b322 */
if(!s->budget--) { s->failed_pc=0x0c03b322u; return 0; }
r[6]=(r[3]&0x80000000u)?((r[3]&31u)?(uint32_t)((int32_t)r[6]>>((-r[3])&31u)):((int32_t)r[6]<0?0xffffffffu:0)):r[6]<<(r[3]&31u);
goto P_0c03b324;
P_0c03b324: /* original 6063, guest PC 0x0c03b324 */
if(!s->budget--) { s->failed_pc=0x0c03b324u; return 0; }
r[0]=r[6];
goto P_0c03b326;
P_0c03b326: /* original 80e1, guest PC 0x0c03b326 */
if(!s->budget--) { s->failed_pc=0x0c03b326u; return 0; }
write(ram,r[14]+1,r[0],1);
goto P_0c03b328;
P_0c03b328: /* original 2e40, guest PC 0x0c03b328 */
if(!s->budget--) { s->failed_pc=0x0c03b328u; return 0; }
write(ram,r[14],r[4],1);
goto P_0c03b32a;
P_0c03b32a: /* original 63e2, guest PC 0x0c03b32a */
if(!s->budget--) { s->failed_pc=0x0c03b32au; return 0; }
tmp=read(ram,r[14],4);
r[3]=tmp;
goto P_0c03b32c;
P_0c03b32c: /* original d21e, guest PC 0x0c03b32c */
if(!s->budget--) { s->failed_pc=0x0c03b32cu; return 0; }
r[2]=read(ram,0x0c03b3a8u,4);
goto P_0c03b32e;
P_0c03b32e: /* original 420b, guest PC 0x0c03b32e */
if(!s->budget--) { s->failed_pc=0x0c03b32eu; return 0; }
target=r[2];
r[16]=0x0c03b332u;
r[15]-=4; write(ram,r[15],r[3],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c03b332u) { target=s->pc; goto dispatch; }
goto P_0c03b332;
P_0c03b330: /* original 2f36, guest PC 0x0c03b330 */
if(!s->budget--) { s->failed_pc=0x0c03b330u; return 0; }
r[15]-=4; write(ram,r[15],r[3],4);
goto P_0c03b332;
P_0c03b332: /* original 7f08, guest PC 0x0c03b332 */
if(!s->budget--) { s->failed_pc=0x0c03b332u; return 0; }
r[15]+=0x00000008u;
goto P_0c03b334;
P_0c03b334: /* original 4f26, guest PC 0x0c03b334 */
if(!s->budget--) { s->failed_pc=0x0c03b334u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c03b336;
P_0c03b336: /* original 000b, guest PC 0x0c03b336 */
if(!s->budget--) { s->failed_pc=0x0c03b336u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c03b338: /* original 6ef6, guest PC 0x0c03b338 */
if(!s->budget--) { s->failed_pc=0x0c03b338u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c03b33au,s,ram);
P_0c040378: /* original 7ffc, guest PC 0x0c040378 */
if(!s->budget--) { s->failed_pc=0x0c040378u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c04037a;
P_0c04037a: /* original 2f42, guest PC 0x0c04037a */
if(!s->budget--) { s->failed_pc=0x0c04037au; return 0; }
write(ram,r[15],r[4],4);
goto P_0c04037c;
P_0c04037c: /* original 62f2, guest PC 0x0c04037c */
if(!s->budget--) { s->failed_pc=0x0c04037cu; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c04037e;
P_0c04037e: /* original 4211, guest PC 0x0c04037e */
if(!s->budget--) { s->failed_pc=0x0c04037eu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>=0)!=0);
goto P_0c040380;
P_0c040380: /* original 8b03, guest PC 0x0c040380 */
if(!s->budget--) { s->failed_pc=0x0c040380u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04038a; }
goto P_0c040382;
P_0c040382: /* original e108, guest PC 0x0c040382 */
if(!s->budget--) { s->failed_pc=0x0c040382u; return 0; }
r[1]=0x00000008u;
goto P_0c040384;
P_0c040384: /* original 63f2, guest PC 0x0c040384 */
if(!s->budget--) { s->failed_pc=0x0c040384u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c040386;
P_0c040386: /* original 3313, guest PC 0x0c040386 */
if(!s->budget--) { s->failed_pc=0x0c040386u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>=(int32_t)r[1])!=0);
goto P_0c040388;
P_0c040388: /* original 8b03, guest PC 0x0c040388 */
if(!s->budget--) { s->failed_pc=0x0c040388u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c040392; }
goto P_0c04038a;
P_0c04038a: /* original e0ff, guest PC 0x0c04038a */
if(!s->budget--) { s->failed_pc=0x0c04038au; return 0; }
r[0]=0xffffffffu;
goto P_0c04038c;
P_0c04038c: /* original 7f04, guest PC 0x0c04038c */
if(!s->budget--) { s->failed_pc=0x0c04038cu; return 0; }
r[15]+=0x00000004u;
goto P_0c04038e;
P_0c04038e: /* original 000b, guest PC 0x0c04038e */
if(!s->budget--) { s->failed_pc=0x0c04038eu; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c040390: /* original 0009, guest PC 0x0c040390 */
if(!s->budget--) { s->failed_pc=0x0c040390u; return 0; }
goto P_0c040392;
P_0c040392: /* original 60f2, guest PC 0x0c040392 */
if(!s->budget--) { s->failed_pc=0x0c040392u; return 0; }
tmp=read(ram,r[15],4);
r[0]=tmp;
goto P_0c040394;
P_0c040394: /* original 6303, guest PC 0x0c040394 */
if(!s->budget--) { s->failed_pc=0x0c040394u; return 0; }
r[3]=r[0];
goto P_0c040396;
P_0c040396: /* original 4000, guest PC 0x0c040396 */
if(!s->budget--) { s->failed_pc=0x0c040396u; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c040398;
P_0c040398: /* original 303c, guest PC 0x0c040398 */
if(!s->budget--) { s->failed_pc=0x0c040398u; return 0; }
r[0]+=r[3];
goto P_0c04039a;
P_0c04039a: /* original 4008, guest PC 0x0c04039a */
if(!s->budget--) { s->failed_pc=0x0c04039au; return 0; }
r[0]<<=2;
goto P_0c04039c;
P_0c04039c: /* original 600e, guest PC 0x0c04039c */
if(!s->budget--) { s->failed_pc=0x0c04039cu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)r[0];
goto P_0c04039e;
P_0c04039e: /* original d107, guest PC 0x0c04039e */
if(!s->budget--) { s->failed_pc=0x0c04039eu; return 0; }
r[1]=read(ram,0x0c0403bcu,4);
goto P_0c0403a0;
P_0c0403a0: /* original 001e, guest PC 0x0c0403a0 */
if(!s->budget--) { s->failed_pc=0x0c0403a0u; return 0; }
r[0]=read(ram,r[1]+r[0],4);
goto P_0c0403a2;
P_0c0403a2: /* original 88ff, guest PC 0x0c0403a2 */
if(!s->budget--) { s->failed_pc=0x0c0403a2u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c0403a4;
P_0c0403a4: /* original 8b03, guest PC 0x0c0403a4 */
if(!s->budget--) { s->failed_pc=0x0c0403a4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0403ae; }
goto P_0c0403a6;
P_0c0403a6: /* original e0fe, guest PC 0x0c0403a6 */
if(!s->budget--) { s->failed_pc=0x0c0403a6u; return 0; }
r[0]=0xfffffffeu;
goto P_0c0403a8;
P_0c0403a8: /* original 7f04, guest PC 0x0c0403a8 */
if(!s->budget--) { s->failed_pc=0x0c0403a8u; return 0; }
r[15]+=0x00000004u;
goto P_0c0403aa;
P_0c0403aa: /* original 000b, guest PC 0x0c0403aa */
if(!s->budget--) { s->failed_pc=0x0c0403aau; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c0403ac: /* original 0009, guest PC 0x0c0403ac */
if(!s->budget--) { s->failed_pc=0x0c0403acu; return 0; }
goto P_0c0403ae;
P_0c0403ae: /* original e000, guest PC 0x0c0403ae */
if(!s->budget--) { s->failed_pc=0x0c0403aeu; return 0; }
r[0]=0x00000000u;
goto P_0c0403b0;
P_0c0403b0: /* original 7f04, guest PC 0x0c0403b0 */
if(!s->budget--) { s->failed_pc=0x0c0403b0u; return 0; }
r[15]+=0x00000004u;
goto P_0c0403b2;
P_0c0403b2: /* original 000b, guest PC 0x0c0403b2 */
if(!s->budget--) { s->failed_pc=0x0c0403b2u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c0403b4: /* original 0009, guest PC 0x0c0403b4 */
if(!s->budget--) { s->failed_pc=0x0c0403b4u; return 0; }
return vf3_matrix_family(0x0c0403b6u,s,ram);
P_0c05e1b2: /* original 4f22, guest PC 0x0c05e1b2 */
if(!s->budget--) { s->failed_pc=0x0c05e1b2u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c05e1b4;
P_0c05e1b4: /* original 9461, guest PC 0x0c05e1b4 */
if(!s->budget--) { s->failed_pc=0x0c05e1b4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c05e27au,2);
goto P_0c05e1b6;
P_0c05e1b6: /* original d339, guest PC 0x0c05e1b6 */
if(!s->budget--) { s->failed_pc=0x0c05e1b6u; return 0; }
r[3]=read(ram,0x0c05e29cu,4);
goto P_0c05e1b8;
P_0c05e1b8: /* original 430b, guest PC 0x0c05e1b8 */
if(!s->budget--) { s->failed_pc=0x0c05e1b8u; return 0; }
target=r[3];
r[16]=0x0c05e1bcu;
r[5]=read(ram,r[15]+4,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c05e1bcu) { target=s->pc; goto dispatch; }
goto P_0c05e1bc;
P_0c05e1ba: /* original 55f1, guest PC 0x0c05e1ba */
if(!s->budget--) { s->failed_pc=0x0c05e1bau; return 0; }
r[5]=read(ram,r[15]+4,4);
goto P_0c05e1bc;
P_0c05e1bc: /* original 4f26, guest PC 0x0c05e1bc */
if(!s->budget--) { s->failed_pc=0x0c05e1bcu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c05e1be;
P_0c05e1be: /* original 000b, guest PC 0x0c05e1be */
if(!s->budget--) { s->failed_pc=0x0c05e1beu; return 0; }
target=r[16];
r[0]=0x00000000u;
s->pc=target; return ram->oob==0;
P_0c05e1c0: /* original e000, guest PC 0x0c05e1c0 */
if(!s->budget--) { s->failed_pc=0x0c05e1c0u; return 0; }
r[0]=0x00000000u;
return vf3_matrix_family(0x0c05e1c2u,s,ram);
P_0c060d14: /* original d344, guest PC 0x0c060d14 */
if(!s->budget--) { s->failed_pc=0x0c060d14u; return 0; }
r[3]=read(ram,0x0c060e28u,4);
goto P_0c060d16;
P_0c060d16: /* original 343c, guest PC 0x0c060d16 */
if(!s->budget--) { s->failed_pc=0x0c060d16u; return 0; }
r[4]+=r[3];
goto P_0c060d18;
P_0c060d18: /* original 2452, guest PC 0x0c060d18 */
if(!s->budget--) { s->failed_pc=0x0c060d18u; return 0; }
write(ram,r[4],r[5],4);
goto P_0c060d1a;
P_0c060d1a: /* original 000b, guest PC 0x0c060d1a */
if(!s->budget--) { s->failed_pc=0x0c060d1au; return 0; }
target=r[16];
r[0]=0x00000001u;
s->pc=target; return ram->oob==0;
P_0c060d1c: /* original e001, guest PC 0x0c060d1c */
if(!s->budget--) { s->failed_pc=0x0c060d1cu; return 0; }
r[0]=0x00000001u;
return vf3_matrix_family(0x0c060d1eu,s,ram);
P_0c066dc4: /* original 4f22, guest PC 0x0c066dc4 */
if(!s->budget--) { s->failed_pc=0x0c066dc4u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c066dc6;
P_0c066dc6: /* original d329, guest PC 0x0c066dc6 */
if(!s->budget--) { s->failed_pc=0x0c066dc6u; return 0; }
r[3]=read(ram,0x0c066e6cu,4);
goto P_0c066dc8;
P_0c066dc8: /* original d227, guest PC 0x0c066dc8 */
if(!s->budget--) { s->failed_pc=0x0c066dc8u; return 0; }
r[2]=read(ram,0x0c066e68u,4);
goto P_0c066dca;
P_0c066dca: /* original 7ffc, guest PC 0x0c066dca */
if(!s->budget--) { s->failed_pc=0x0c066dcau; return 0; }
r[15]+=0xfffffffcu;
goto P_0c066dcc;
P_0c066dcc: /* original 420b, guest PC 0x0c066dcc */
if(!s->budget--) { s->failed_pc=0x0c066dccu; return 0; }
target=r[2];
r[16]=0x0c066dd0u;
write(ram,r[15],r[3],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c066dd0u) { target=s->pc; goto dispatch; }
goto P_0c066dd0;
P_0c066dce: /* original 2f32, guest PC 0x0c066dce */
if(!s->budget--) { s->failed_pc=0x0c066dceu; return 0; }
write(ram,r[15],r[3],4);
goto P_0c066dd0;
P_0c066dd0: /* original 2008, guest PC 0x0c066dd0 */
if(!s->budget--) { s->failed_pc=0x0c066dd0u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c066dd2;
P_0c066dd2: /* original 8908, guest PC 0x0c066dd2 */
if(!s->budget--) { s->failed_pc=0x0c066dd2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c066de6; }
goto P_0c066dd4;
P_0c066dd4: /* original 63f2, guest PC 0x0c066dd4 */
if(!s->budget--) { s->failed_pc=0x0c066dd4u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c066dd6;
P_0c066dd6: /* original 7f04, guest PC 0x0c066dd6 */
if(!s->budget--) { s->failed_pc=0x0c066dd6u; return 0; }
r[15]+=0x00000004u;
goto P_0c066dd8;
P_0c066dd8: /* original d221, guest PC 0x0c066dd8 */
if(!s->budget--) { s->failed_pc=0x0c066dd8u; return 0; }
r[2]=read(ram,0x0c066e60u,4);
goto P_0c066dda;
P_0c066dda: /* original 5133, guest PC 0x0c066dda */
if(!s->budget--) { s->failed_pc=0x0c066ddau; return 0; }
r[1]=read(ram,r[3]+12,4);
goto P_0c066ddc;
P_0c066ddc: /* original 6422, guest PC 0x0c066ddc */
if(!s->budget--) { s->failed_pc=0x0c066ddcu; return 0; }
tmp=read(ram,r[2],4);
r[4]=tmp;
goto P_0c066dde;
P_0c066dde: /* original 7101, guest PC 0x0c066dde */
if(!s->budget--) { s->failed_pc=0x0c066ddeu; return 0; }
r[1]+=0x00000001u;
goto P_0c066de0;
P_0c066de0: /* original 1313, guest PC 0x0c066de0 */
if(!s->budget--) { s->failed_pc=0x0c066de0u; return 0; }
write(ram,r[3]+12,r[1],4);
goto P_0c066de2;
P_0c066de2: /* original a004, guest PC 0x0c066de2 */
if(!s->budget--) { s->failed_pc=0x0c066de2u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c066dee;
P_0c066de4: /* original 4f26, guest PC 0x0c066de4 */
if(!s->budget--) { s->failed_pc=0x0c066de4u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c066de6;
P_0c066de6: /* original 7f04, guest PC 0x0c066de6 */
if(!s->budget--) { s->failed_pc=0x0c066de6u; return 0; }
r[15]+=0x00000004u;
goto P_0c066de8;
P_0c066de8: /* original 4f26, guest PC 0x0c066de8 */
if(!s->budget--) { s->failed_pc=0x0c066de8u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c066dea;
P_0c066dea: /* original 000b, guest PC 0x0c066dea */
if(!s->budget--) { s->failed_pc=0x0c066deau; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c066dec: /* original 0009, guest PC 0x0c066dec */
if(!s->budget--) { s->failed_pc=0x0c066decu; return 0; }
goto P_0c066dee;
P_0c066dee: /* original 2fe6, guest PC 0x0c066dee */
if(!s->budget--) { s->failed_pc=0x0c066deeu; return 0; }
r[15]-=4; write(ram,r[15],r[14],4);
goto P_0c066df0;
P_0c066df0: /* original 6e43, guest PC 0x0c066df0 */
if(!s->budget--) { s->failed_pc=0x0c066df0u; return 0; }
r[14]=r[4];
goto P_0c066df2;
P_0c066df2: /* original 2fd6, guest PC 0x0c066df2 */
if(!s->budget--) { s->failed_pc=0x0c066df2u; return 0; }
r[15]-=4; write(ram,r[15],r[13],4);
goto P_0c066df4;
P_0c066df4: /* original 2fc6, guest PC 0x0c066df4 */
if(!s->budget--) { s->failed_pc=0x0c066df4u; return 0; }
r[15]-=4; write(ram,r[15],r[12],4);
goto P_0c066df6;
P_0c066df6: /* original 2fb6, guest PC 0x0c066df6 */
if(!s->budget--) { s->failed_pc=0x0c066df6u; return 0; }
r[15]-=4; write(ram,r[15],r[11],4);
goto P_0c066df8;
P_0c066df8: /* original eb01, guest PC 0x0c066df8 */
if(!s->budget--) { s->failed_pc=0x0c066df8u; return 0; }
r[11]=0x00000001u;
goto P_0c066dfa;
P_0c066dfa: /* original 2fa6, guest PC 0x0c066dfa */
if(!s->budget--) { s->failed_pc=0x0c066dfau; return 0; }
r[15]-=4; write(ram,r[15],r[10],4);
goto P_0c066dfc;
P_0c066dfc: /* original 6cb3, guest PC 0x0c066dfc */
if(!s->budget--) { s->failed_pc=0x0c066dfcu; return 0; }
r[12]=r[11];
goto P_0c066dfe;
P_0c066dfe: /* original 2f96, guest PC 0x0c066dfe */
if(!s->budget--) { s->failed_pc=0x0c066dfeu; return 0; }
r[15]-=4; write(ram,r[15],r[9],4);
goto P_0c066e00;
P_0c066e00: /* original 2f86, guest PC 0x0c066e00 */
if(!s->budget--) { s->failed_pc=0x0c066e00u; return 0; }
r[15]-=4; write(ram,r[15],r[8],4);
goto P_0c066e02;
P_0c066e02: /* original 4f22, guest PC 0x0c066e02 */
if(!s->budget--) { s->failed_pc=0x0c066e02u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c066e04;
P_0c066e04: /* original d319, guest PC 0x0c066e04 */
if(!s->budget--) { s->failed_pc=0x0c066e04u; return 0; }
r[3]=read(ram,0x0c066e6cu,4);
goto P_0c066e06;
P_0c066e06: /* original d61a, guest PC 0x0c066e06 */
if(!s->budget--) { s->failed_pc=0x0c066e06u; return 0; }
r[6]=read(ram,0x0c066e70u,4);
goto P_0c066e08;
P_0c066e08: /* original 7fe8, guest PC 0x0c066e08 */
if(!s->budget--) { s->failed_pc=0x0c066e08u; return 0; }
r[15]+=0xffffffe8u;
goto P_0c066e0a;
P_0c066e0a: /* original 1f31, guest PC 0x0c066e0a */
if(!s->budget--) { s->failed_pc=0x0c066e0au; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c066e0c;
P_0c066e0c: /* original e340, guest PC 0x0c066e0c */
if(!s->budget--) { s->failed_pc=0x0c066e0cu; return 0; }
r[3]=0x00000040u;
goto P_0c066e0e;
P_0c066e0e: /* original 64e2, guest PC 0x0c066e0e */
if(!s->budget--) { s->failed_pc=0x0c066e0eu; return 0; }
tmp=read(ram,r[14],4);
r[4]=tmp;
goto P_0c066e10;
P_0c066e10: /* original 2438, guest PC 0x0c066e10 */
if(!s->budget--) { s->failed_pc=0x0c066e10u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[3])==0)!=0);
goto P_0c066e12;
P_0c066e12: /* original 8d04, guest PC 0x0c066e12 */
if(!s->budget--) { s->failed_pc=0x0c066e12u; return 0; }
cond=r[17]&1u;
r[5]=0x00000000u;
if(cond) { goto P_0c066e1e; }
goto P_0c066e16;
P_0c066e14: /* original e500, guest PC 0x0c066e14 */
if(!s->budget--) { s->failed_pc=0x0c066e14u; return 0; }
r[5]=0x00000000u;
goto P_0c066e16;
P_0c066e16: /* original 6462, guest PC 0x0c066e16 */
if(!s->budget--) { s->failed_pc=0x0c066e16u; return 0; }
tmp=read(ram,r[6],4);
r[4]=tmp;
goto P_0c066e18;
P_0c066e18: /* original 24b8, guest PC 0x0c066e18 */
if(!s->budget--) { s->failed_pc=0x0c066e18u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[11])==0)!=0);
goto P_0c066e1a;
P_0c066e1a: /* original 8900, guest PC 0x0c066e1a */
if(!s->budget--) { s->failed_pc=0x0c066e1au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c066e1e; }
goto P_0c066e1c;
P_0c066e1c: /* original 6c53, guest PC 0x0c066e1c */
if(!s->budget--) { s->failed_pc=0x0c066e1cu; return 0; }
r[12]=r[5];
goto P_0c066e1e;
P_0c066e1e: /* original 901b, guest PC 0x0c066e1e */
if(!s->budget--) { s->failed_pc=0x0c066e1eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c066e58u,2);
goto P_0c066e20;
P_0c066e20: /* original e200, guest PC 0x0c066e20 */
if(!s->budget--) { s->failed_pc=0x0c066e20u; return 0; }
r[2]=0x00000000u;
goto P_0c066e22;
P_0c066e22: /* original 03ed, guest PC 0x0c066e22 */
if(!s->budget--) { s->failed_pc=0x0c066e22u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c066e24;
P_0c066e24: /* original 04ed, guest PC 0x0c066e24 */
if(!s->budget--) { s->failed_pc=0x0c066e24u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c066e26;
P_0c066e26: /* original 73ff, guest PC 0x0c066e26 */
if(!s->budget--) { s->failed_pc=0x0c066e26u; return 0; }
r[3]+=0xffffffffu;
goto P_0c066e28;
P_0c066e28: /* original 3426, guest PC 0x0c066e28 */
if(!s->budget--) { s->failed_pc=0x0c066e28u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>r[2])!=0);
goto P_0c066e2a;
P_0c066e2a: /* original 0e35, guest PC 0x0c066e2a */
if(!s->budget--) { s->failed_pc=0x0c066e2au; return 0; }
write(ram,r[14]+r[0],r[3],2);
goto P_0c066e2c;
P_0c066e2c: /* original dd11, guest PC 0x0c066e2c */
if(!s->budget--) { s->failed_pc=0x0c066e2cu; return 0; }
r[13]=read(ram,0x0c066e74u,4);
goto P_0c066e2e;
P_0c066e2e: /* original 8978, guest PC 0x0c066e2e */
if(!s->budget--) { s->failed_pc=0x0c066e2eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c066f22; }
goto P_0c066e30;
P_0c066e30: /* original 900b, guest PC 0x0c066e30 */
if(!s->budget--) { s->failed_pc=0x0c066e30u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c066e4au,2);
goto P_0c066e32;
P_0c066e32: /* original 9212, guest PC 0x0c066e32 */
if(!s->budget--) { s->failed_pc=0x0c066e32u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c066e5au,2);
goto P_0c066e34;
P_0c066e34: /* original 04ee, guest PC 0x0c066e34 */
if(!s->budget--) { s->failed_pc=0x0c066e34u; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c066e36;
P_0c066e36: /* original 56d4, guest PC 0x0c066e36 */
if(!s->budget--) { s->failed_pc=0x0c066e36u; return 0; }
r[6]=read(ram,r[13]+16,4);
goto P_0c066e38;
P_0c066e38: /* original 6340, guest PC 0x0c066e38 */
if(!s->budget--) { s->failed_pc=0x0c066e38u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[4],1);
r[3]=tmp;
goto P_0c066e3a;
P_0c066e3a: /* original 633c, guest PC 0x0c066e3a */
if(!s->budget--) { s->failed_pc=0x0c066e3au; return 0; }
r[3]=r[3]&255u;
goto P_0c066e3c;
P_0c066e3c: /* original 3320, guest PC 0x0c066e3c */
if(!s->budget--) { s->failed_pc=0x0c066e3cu; return 0; }
r[17]=(r[17]&~1u)|((r[3]==r[2])!=0);
goto P_0c066e3e;
P_0c066e3e: /* original 8f1b, guest PC 0x0c066e3e */
if(!s->budget--) { s->failed_pc=0x0c066e3eu; return 0; }
cond=r[17]&1u;
r[7]=read(ram,r[13]+20,4);
if(!cond) { goto P_0c066e78; }
goto P_0c066e42;
P_0c066e40: /* original 57d5, guest PC 0x0c066e40 */
if(!s->budget--) { s->failed_pc=0x0c066e40u; return 0; }
r[7]=read(ram,r[13]+20,4);
goto P_0c066e42;
P_0c066e42: /* original 53f1, guest PC 0x0c066e42 */
if(!s->budget--) { s->failed_pc=0x0c066e42u; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c066e44;
P_0c066e44: /* original a096, guest PC 0x0c066e44 */
if(!s->budget--) { s->failed_pc=0x0c066e44u; return 0; }
write(ram,r[3]+12,r[5],4);
goto P_0c066f74;
P_0c066e46: /* original 1353, guest PC 0x0c066e46 */
if(!s->budget--) { s->failed_pc=0x0c066e46u; return 0; }
write(ram,r[3]+12,r[5],4);
return vf3_matrix_family(0x0c066e48u,s,ram);
P_0c066e78: /* original 6240, guest PC 0x0c066e78 */
if(!s->budget--) { s->failed_pc=0x0c066e78u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[4],1);
r[2]=tmp;
goto P_0c066e7a;
P_0c066e7a: /* original 622c, guest PC 0x0c066e7a */
if(!s->budget--) { s->failed_pc=0x0c066e7au; return 0; }
r[2]=r[2]&255u;
goto P_0c066e7c;
P_0c066e7c: /* original 1f24, guest PC 0x0c066e7c */
if(!s->budget--) { s->failed_pc=0x0c066e7cu; return 0; }
write(ram,r[15]+16,r[2],4);
goto P_0c066e7e;
P_0c066e7e: /* original 8541, guest PC 0x0c066e7e */
if(!s->budget--) { s->failed_pc=0x0c066e7eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+2,2);
goto P_0c066e80;
P_0c066e80: /* original 600d, guest PC 0x0c066e80 */
if(!s->budget--) { s->failed_pc=0x0c066e80u; return 0; }
r[0]=r[0]&65535u;
goto P_0c066e82;
P_0c066e82: /* original 1f02, guest PC 0x0c066e82 */
if(!s->budget--) { s->failed_pc=0x0c066e82u; return 0; }
write(ram,r[15]+8,r[0],4);
goto P_0c066e84;
P_0c066e84: /* original 5343, guest PC 0x0c066e84 */
if(!s->budget--) { s->failed_pc=0x0c066e84u; return 0; }
r[3]=read(ram,r[4]+12,4);
goto P_0c066e86;
P_0c066e86: /* original 5941, guest PC 0x0c066e86 */
if(!s->budget--) { s->failed_pc=0x0c066e86u; return 0; }
r[9]=read(ram,r[4]+4,4);
goto P_0c066e88;
P_0c066e88: /* original 5842, guest PC 0x0c066e88 */
if(!s->budget--) { s->failed_pc=0x0c066e88u; return 0; }
r[8]=read(ram,r[4]+8,4);
goto P_0c066e8a;
P_0c066e8a: /* original 1f31, guest PC 0x0c066e8a */
if(!s->budget--) { s->failed_pc=0x0c066e8au; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c066e8c;
P_0c066e8c: /* original 5345, guest PC 0x0c066e8c */
if(!s->budget--) { s->failed_pc=0x0c066e8cu; return 0; }
r[3]=read(ram,r[4]+20,4);
goto P_0c066e8e;
P_0c066e8e: /* original 5a44, guest PC 0x0c066e8e */
if(!s->budget--) { s->failed_pc=0x0c066e8eu; return 0; }
r[10]=read(ram,r[4]+16,4);
goto P_0c066e90;
P_0c066e90: /* original 1f35, guest PC 0x0c066e90 */
if(!s->budget--) { s->failed_pc=0x0c066e90u; return 0; }
write(ram,r[15]+20,r[3],4);
goto P_0c066e92;
P_0c066e92: /* original 5246, guest PC 0x0c066e92 */
if(!s->budget--) { s->failed_pc=0x0c066e92u; return 0; }
r[2]=read(ram,r[4]+24,4);
goto P_0c066e94;
P_0c066e94: /* original 741c, guest PC 0x0c066e94 */
if(!s->budget--) { s->failed_pc=0x0c066e94u; return 0; }
r[4]+=0x0000001cu;
goto P_0c066e96;
P_0c066e96: /* original 1f23, guest PC 0x0c066e96 */
if(!s->budget--) { s->failed_pc=0x0c066e96u; return 0; }
write(ram,r[15]+12,r[2],4);
goto P_0c066e98;
P_0c066e98: /* original 908d, guest PC 0x0c066e98 */
if(!s->budget--) { s->failed_pc=0x0c066e98u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c066fb6u,2);
goto P_0c066e9a;
P_0c066e9a: /* original 0e46, guest PC 0x0c066e9a */
if(!s->budget--) { s->failed_pc=0x0c066e9au; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c066e9c;
P_0c066e9c: /* original 908c, guest PC 0x0c066e9c */
if(!s->budget--) { s->failed_pc=0x0c066e9cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c066fb8u,2);
goto P_0c066e9e;
P_0c066e9e: /* original 53f4, guest PC 0x0c066e9e */
if(!s->budget--) { s->failed_pc=0x0c066e9eu; return 0; }
r[3]=read(ram,r[15]+16,4);
goto P_0c066ea0;
P_0c066ea0: /* original 0e34, guest PC 0x0c066ea0 */
if(!s->budget--) { s->failed_pc=0x0c066ea0u; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c066ea2;
P_0c066ea2: /* original 908a, guest PC 0x0c066ea2 */
if(!s->budget--) { s->failed_pc=0x0c066ea2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c066fbau,2);
goto P_0c066ea4;
P_0c066ea4: /* original 52f2, guest PC 0x0c066ea4 */
if(!s->budget--) { s->failed_pc=0x0c066ea4u; return 0; }
r[2]=read(ram,r[15]+8,4);
goto P_0c066ea6;
P_0c066ea6: /* original 0e25, guest PC 0x0c066ea6 */
if(!s->budget--) { s->failed_pc=0x0c066ea6u; return 0; }
write(ram,r[14]+r[0],r[2],2);
goto P_0c066ea8;
P_0c066ea8: /* original 9088, guest PC 0x0c066ea8 */
if(!s->budget--) { s->failed_pc=0x0c066ea8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c066fbcu,2);
goto P_0c066eaa;
P_0c066eaa: /* original 0696, guest PC 0x0c066eaa */
if(!s->budget--) { s->failed_pc=0x0c066eaau; return 0; }
write(ram,r[6]+r[0],r[9],4);
goto P_0c066eac;
P_0c066eac: /* original 0786, guest PC 0x0c066eac */
if(!s->budget--) { s->failed_pc=0x0c066eacu; return 0; }
write(ram,r[7]+r[0],r[8],4);
goto P_0c066eae;
P_0c066eae: /* original 9086, guest PC 0x0c066eae */
if(!s->budget--) { s->failed_pc=0x0c066eaeu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c066fbeu,2);
goto P_0c066eb0;
P_0c066eb0: /* original 53f1, guest PC 0x0c066eb0 */
if(!s->budget--) { s->failed_pc=0x0c066eb0u; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c066eb2;
P_0c066eb2: /* original 0636, guest PC 0x0c066eb2 */
if(!s->budget--) { s->failed_pc=0x0c066eb2u; return 0; }
write(ram,r[6]+r[0],r[3],4);
goto P_0c066eb4;
P_0c066eb4: /* original 07a6, guest PC 0x0c066eb4 */
if(!s->budget--) { s->failed_pc=0x0c066eb4u; return 0; }
write(ram,r[7]+r[0],r[10],4);
goto P_0c066eb6;
P_0c066eb6: /* original 53f5, guest PC 0x0c066eb6 */
if(!s->budget--) { s->failed_pc=0x0c066eb6u; return 0; }
r[3]=read(ram,r[15]+20,4);
goto P_0c066eb8;
P_0c066eb8: /* original 9082, guest PC 0x0c066eb8 */
if(!s->budget--) { s->failed_pc=0x0c066eb8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c066fc0u,2);
goto P_0c066eba;
P_0c066eba: /* original 7a04, guest PC 0x0c066eba */
if(!s->budget--) { s->failed_pc=0x0c066ebau; return 0; }
r[10]+=0x00000004u;
goto P_0c066ebc;
P_0c066ebc: /* original 0e36, guest PC 0x0c066ebc */
if(!s->budget--) { s->failed_pc=0x0c066ebcu; return 0; }
write(ram,r[14]+r[0],r[3],4);
goto P_0c066ebe;
P_0c066ebe: /* original e3f3, guest PC 0x0c066ebe */
if(!s->budget--) { s->failed_pc=0x0c066ebeu; return 0; }
r[3]=0xfffffff3u;
goto P_0c066ec0;
P_0c066ec0: /* original 907f, guest PC 0x0c066ec0 */
if(!s->budget--) { s->failed_pc=0x0c066ec0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c066fc2u,2);
goto P_0c066ec2;
P_0c066ec2: /* original 52f3, guest PC 0x0c066ec2 */
if(!s->budget--) { s->failed_pc=0x0c066ec2u; return 0; }
r[2]=read(ram,r[15]+12,4);
goto P_0c066ec4;
P_0c066ec4: /* original 0e26, guest PC 0x0c066ec4 */
if(!s->budget--) { s->failed_pc=0x0c066ec4u; return 0; }
write(ram,r[14]+r[0],r[2],4);
goto P_0c066ec6;
P_0c066ec6: /* original 61e2, guest PC 0x0c066ec6 */
if(!s->budget--) { s->failed_pc=0x0c066ec6u; return 0; }
tmp=read(ram,r[14],4);
r[1]=tmp;
goto P_0c066ec8;
P_0c066ec8: /* original 2139, guest PC 0x0c066ec8 */
if(!s->budget--) { s->failed_pc=0x0c066ec8u; return 0; }
r[1]&=r[3];
goto P_0c066eca;
P_0c066eca: /* original 2e12, guest PC 0x0c066eca */
if(!s->budget--) { s->failed_pc=0x0c066ecau; return 0; }
write(ram,r[14],r[1],4);
goto P_0c066ecc;
P_0c066ecc: /* original 947a, guest PC 0x0c066ecc */
if(!s->budget--) { s->failed_pc=0x0c066eccu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c066fc4u,2);
goto P_0c066ece;
P_0c066ece: /* original 1f94, guest PC 0x0c066ece */
if(!s->budget--) { s->failed_pc=0x0c066eceu; return 0; }
write(ram,r[15]+16,r[9],4);
goto P_0c066ed0;
P_0c066ed0: /* original 6953, guest PC 0x0c066ed0 */
if(!s->budget--) { s->failed_pc=0x0c066ed0u; return 0; }
r[9]=r[5];
goto P_0c066ed2;
P_0c066ed2: /* original 1f83, guest PC 0x0c066ed2 */
if(!s->budget--) { s->failed_pc=0x0c066ed2u; return 0; }
write(ram,r[15]+12,r[8],4);
goto P_0c066ed4;
P_0c066ed4: /* original 6853, guest PC 0x0c066ed4 */
if(!s->budget--) { s->failed_pc=0x0c066ed4u; return 0; }
r[8]=r[5];
goto P_0c066ed6;
P_0c066ed6: /* original 52f1, guest PC 0x0c066ed6 */
if(!s->budget--) { s->failed_pc=0x0c066ed6u; return 0; }
r[2]=read(ram,r[15]+4,4);
goto P_0c066ed8;
P_0c066ed8: /* original 7204, guest PC 0x0c066ed8 */
if(!s->budget--) { s->failed_pc=0x0c066ed8u; return 0; }
r[2]+=0x00000004u;
goto P_0c066eda;
P_0c066eda: /* original 1f22, guest PC 0x0c066eda */
if(!s->budget--) { s->failed_pc=0x0c066edau; return 0; }
write(ram,r[15]+8,r[2],4);
goto P_0c066edc;
P_0c066edc: /* original 1fa5, guest PC 0x0c066edc */
if(!s->budget--) { s->failed_pc=0x0c066edcu; return 0; }
write(ram,r[15]+20,r[10],4);
goto P_0c066ede;
P_0c066ede: /* original 1f51, guest PC 0x0c066ede */
if(!s->budget--) { s->failed_pc=0x0c066edeu; return 0; }
write(ram,r[15]+4,r[5],4);
goto P_0c066ee0;
P_0c066ee0: /* original 51f4, guest PC 0x0c066ee0 */
if(!s->budget--) { s->failed_pc=0x0c066ee0u; return 0; }
r[1]=read(ram,r[15]+16,4);
goto P_0c066ee2;
P_0c066ee2: /* original 2118, guest PC 0x0c066ee2 */
if(!s->budget--) { s->failed_pc=0x0c066ee2u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[1])==0)!=0);
goto P_0c066ee4;
P_0c066ee4: /* original 8f01, guest PC 0x0c066ee4 */
if(!s->budget--) { s->failed_pc=0x0c066ee4u; return 0; }
cond=r[17]&1u;
r[10]=r[5];
if(!cond) { goto P_0c066eea; }
goto P_0c066ee8;
P_0c066ee6: /* original 6a53, guest PC 0x0c066ee6 */
if(!s->budget--) { s->failed_pc=0x0c066ee6u; return 0; }
r[10]=r[5];
goto P_0c066ee8;
P_0c066ee8: /* original 1f41, guest PC 0x0c066ee8 */
if(!s->budget--) { s->failed_pc=0x0c066ee8u; return 0; }
write(ram,r[15]+4,r[4],4);
goto P_0c066eea;
P_0c066eea: /* original 53f3, guest PC 0x0c066eea */
if(!s->budget--) { s->failed_pc=0x0c066eeau; return 0; }
r[3]=read(ram,r[15]+12,4);
goto P_0c066eec;
P_0c066eec: /* original 2338, guest PC 0x0c066eec */
if(!s->budget--) { s->failed_pc=0x0c066eecu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c066eee;
P_0c066eee: /* original 8b00, guest PC 0x0c066eee */
if(!s->budget--) { s->failed_pc=0x0c066eeeu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c066ef2; }
goto P_0c066ef0;
P_0c066ef0: /* original 6843, guest PC 0x0c066ef0 */
if(!s->budget--) { s->failed_pc=0x0c066ef0u; return 0; }
r[8]=r[4];
goto P_0c066ef2;
P_0c066ef2: /* original 52f2, guest PC 0x0c066ef2 */
if(!s->budget--) { s->failed_pc=0x0c066ef2u; return 0; }
r[2]=read(ram,r[15]+8,4);
goto P_0c066ef4;
P_0c066ef4: /* original 2228, guest PC 0x0c066ef4 */
if(!s->budget--) { s->failed_pc=0x0c066ef4u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c066ef6;
P_0c066ef6: /* original 8b00, guest PC 0x0c066ef6 */
if(!s->budget--) { s->failed_pc=0x0c066ef6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c066efa; }
goto P_0c066ef8;
P_0c066ef8: /* original 6943, guest PC 0x0c066ef8 */
if(!s->budget--) { s->failed_pc=0x0c066ef8u; return 0; }
r[9]=r[4];
goto P_0c066efa;
P_0c066efa: /* original 52f5, guest PC 0x0c066efa */
if(!s->budget--) { s->failed_pc=0x0c066efau; return 0; }
r[2]=read(ram,r[15]+20,4);
goto P_0c066efc;
P_0c066efc: /* original 2228, guest PC 0x0c066efc */
if(!s->budget--) { s->failed_pc=0x0c066efcu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c066efe;
P_0c066efe: /* original 8b00, guest PC 0x0c066efe */
if(!s->budget--) { s->failed_pc=0x0c066efeu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c066f02; }
goto P_0c066f00;
P_0c066f00: /* original 6a43, guest PC 0x0c066f00 */
if(!s->budget--) { s->failed_pc=0x0c066f00u; return 0; }
r[10]=r[4];
goto P_0c066f02;
P_0c066f02: /* original 9060, guest PC 0x0c066f02 */
if(!s->budget--) { s->failed_pc=0x0c066f02u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c066fc6u,2);
goto P_0c066f04;
P_0c066f04: /* original 52f1, guest PC 0x0c066f04 */
if(!s->budget--) { s->failed_pc=0x0c066f04u; return 0; }
r[2]=read(ram,r[15]+4,4);
goto P_0c066f06;
P_0c066f06: /* original 0625, guest PC 0x0c066f06 */
if(!s->budget--) { s->failed_pc=0x0c066f06u; return 0; }
write(ram,r[6]+r[0],r[2],2);
goto P_0c066f08;
P_0c066f08: /* original 0785, guest PC 0x0c066f08 */
if(!s->budget--) { s->failed_pc=0x0c066f08u; return 0; }
write(ram,r[7]+r[0],r[8],2);
goto P_0c066f0a;
P_0c066f0a: /* original 7002, guest PC 0x0c066f0a */
if(!s->budget--) { s->failed_pc=0x0c066f0au; return 0; }
r[0]+=0x00000002u;
goto P_0c066f0c;
P_0c066f0c: /* original 0695, guest PC 0x0c066f0c */
if(!s->budget--) { s->failed_pc=0x0c066f0cu; return 0; }
write(ram,r[6]+r[0],r[9],2);
goto P_0c066f0e;
P_0c066f0e: /* original 07a5, guest PC 0x0c066f0e */
if(!s->budget--) { s->failed_pc=0x0c066f0eu; return 0; }
write(ram,r[7]+r[0],r[10],2);
goto P_0c066f10;
P_0c066f10: /* original 6053, guest PC 0x0c066f10 */
if(!s->budget--) { s->failed_pc=0x0c066f10u; return 0; }
r[0]=r[5];
goto P_0c066f12;
P_0c066f12: /* original b14a, guest PC 0x0c066f12 */
if(!s->budget--) { s->failed_pc=0x0c066f12u; return 0; }
target=0x0c0671aau; r[16]=0x0c066f16u;
write(ram,r[14]+6,r[0],2);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c066f16u) { target=s->pc; goto dispatch; }
goto P_0c066f16;
P_0c066f14: /* original 81e3, guest PC 0x0c066f14 */
if(!s->budget--) { s->failed_pc=0x0c066f14u; return 0; }
write(ram,r[14]+6,r[0],2);
goto P_0c066f16;
P_0c066f16: /* original b247, guest PC 0x0c066f16 */
if(!s->budget--) { s->failed_pc=0x0c066f16u; return 0; }
target=0x0c0673a8u; r[16]=0x0c066f1au;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c066f1au) { target=s->pc; goto dispatch; }
goto P_0c066f1a;
P_0c066f18: /* original 64e3, guest PC 0x0c066f18 */
if(!s->budget--) { s->failed_pc=0x0c066f18u; return 0; }
r[4]=r[14];
goto P_0c066f1a;
P_0c066f1a: /* original d32c, guest PC 0x0c066f1a */
if(!s->budget--) { s->failed_pc=0x0c066f1au; return 0; }
r[3]=read(ram,0x0c066fccu,4);
goto P_0c066f1c;
P_0c066f1c: /* original e5ff, guest PC 0x0c066f1c */
if(!s->budget--) { s->failed_pc=0x0c066f1cu; return 0; }
r[5]=0xffffffffu;
goto P_0c066f1e;
P_0c066f1e: /* original 430b, guest PC 0x0c066f1e */
if(!s->budget--) { s->failed_pc=0x0c066f1eu; return 0; }
target=r[3];
r[16]=0x0c066f22u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c066f22u) { target=s->pc; goto dispatch; }
goto P_0c066f22;
P_0c066f20: /* original 64e3, guest PC 0x0c066f20 */
if(!s->budget--) { s->failed_pc=0x0c066f20u; return 0; }
r[4]=r[14];
goto P_0c066f22;
P_0c066f22: /* original 62e2, guest PC 0x0c066f22 */
if(!s->budget--) { s->failed_pc=0x0c066f22u; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c066f24;
P_0c066f24: /* original 2f22, guest PC 0x0c066f24 */
if(!s->budget--) { s->failed_pc=0x0c066f24u; return 0; }
write(ram,r[15],r[2],4);
goto P_0c066f26;
P_0c066f26: /* original 904f, guest PC 0x0c066f26 */
if(!s->budget--) { s->failed_pc=0x0c066f26u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c066fc8u,2);
goto P_0c066f28;
P_0c066f28: /* original 03ed, guest PC 0x0c066f28 */
if(!s->budget--) { s->failed_pc=0x0c066f28u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c066f2a;
P_0c066f2a: /* original 7301, guest PC 0x0c066f2a */
if(!s->budget--) { s->failed_pc=0x0c066f2au; return 0; }
r[3]+=0x00000001u;
goto P_0c066f2c;
P_0c066f2c: /* original 0e35, guest PC 0x0c066f2c */
if(!s->budget--) { s->failed_pc=0x0c066f2cu; return 0; }
write(ram,r[14]+r[0],r[3],2);
goto P_0c066f2e;
P_0c066f2e: /* original 5ad4, guest PC 0x0c066f2e */
if(!s->budget--) { s->failed_pc=0x0c066f2eu; return 0; }
r[10]=read(ram,r[13]+16,4);
goto P_0c066f30;
P_0c066f30: /* original b095, guest PC 0x0c066f30 */
if(!s->budget--) { s->failed_pc=0x0c066f30u; return 0; }
target=0x0c06705eu; r[16]=0x0c066f34u;
r[4]=r[10];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c066f34u) { target=s->pc; goto dispatch; }
goto P_0c066f34;
P_0c066f32: /* original 64a3, guest PC 0x0c066f32 */
if(!s->budget--) { s->failed_pc=0x0c066f32u; return 0; }
r[4]=r[10];
goto P_0c066f34;
P_0c066f34: /* original 65f3, guest PC 0x0c066f34 */
if(!s->budget--) { s->failed_pc=0x0c066f34u; return 0; }
r[5]=r[15];
goto P_0c066f36;
P_0c066f36: /* original e604, guest PC 0x0c066f36 */
if(!s->budget--) { s->failed_pc=0x0c066f36u; return 0; }
r[6]=0x00000004u;
goto P_0c066f38;
P_0c066f38: /* original 67c3, guest PC 0x0c066f38 */
if(!s->budget--) { s->failed_pc=0x0c066f38u; return 0; }
r[7]=r[12];
goto P_0c066f3a;
P_0c066f3a: /* original b04d, guest PC 0x0c066f3a */
if(!s->budget--) { s->failed_pc=0x0c066f3au; return 0; }
target=0x0c066fd8u; r[16]=0x0c066f3eu;
r[4]=r[10];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c066f3eu) { target=s->pc; goto dispatch; }
goto P_0c066f3e;
P_0c066f3c: /* original 64a3, guest PC 0x0c066f3c */
if(!s->budget--) { s->failed_pc=0x0c066f3cu; return 0; }
r[4]=r[10];
goto P_0c066f3e;
P_0c066f3e: /* original 5ad5, guest PC 0x0c066f3e */
if(!s->budget--) { s->failed_pc=0x0c066f3eu; return 0; }
r[10]=read(ram,r[13]+20,4);
goto P_0c066f40;
P_0c066f40: /* original b08d, guest PC 0x0c066f40 */
if(!s->budget--) { s->failed_pc=0x0c066f40u; return 0; }
target=0x0c06705eu; r[16]=0x0c066f44u;
r[4]=r[10];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c066f44u) { target=s->pc; goto dispatch; }
goto P_0c066f44;
P_0c066f42: /* original 64a3, guest PC 0x0c066f42 */
if(!s->budget--) { s->failed_pc=0x0c066f42u; return 0; }
r[4]=r[10];
goto P_0c066f44;
P_0c066f44: /* original 65f3, guest PC 0x0c066f44 */
if(!s->budget--) { s->failed_pc=0x0c066f44u; return 0; }
r[5]=r[15];
goto P_0c066f46;
P_0c066f46: /* original e608, guest PC 0x0c066f46 */
if(!s->budget--) { s->failed_pc=0x0c066f46u; return 0; }
r[6]=0x00000008u;
goto P_0c066f48;
P_0c066f48: /* original 67c3, guest PC 0x0c066f48 */
if(!s->budget--) { s->failed_pc=0x0c066f48u; return 0; }
r[7]=r[12];
goto P_0c066f4a;
P_0c066f4a: /* original b045, guest PC 0x0c066f4a */
if(!s->budget--) { s->failed_pc=0x0c066f4au; return 0; }
target=0x0c066fd8u; r[16]=0x0c066f4eu;
r[4]=r[10];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c066f4eu) { target=s->pc; goto dispatch; }
goto P_0c066f4e;
P_0c066f4c: /* original 64a3, guest PC 0x0c066f4c */
if(!s->budget--) { s->failed_pc=0x0c066f4cu; return 0; }
r[4]=r[10];
goto P_0c066f4e;
P_0c066f4e: /* original 62f2, guest PC 0x0c066f4e */
if(!s->budget--) { s->failed_pc=0x0c066f4eu; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c066f50;
P_0c066f50: /* original 2b2b, guest PC 0x0c066f50 */
if(!s->budget--) { s->failed_pc=0x0c066f50u; return 0; }
r[11]|=r[2];
goto P_0c066f52;
P_0c066f52: /* original 63b3, guest PC 0x0c066f52 */
if(!s->budget--) { s->failed_pc=0x0c066f52u; return 0; }
r[3]=r[11];
goto P_0c066f54;
P_0c066f54: /* original 2fb2, guest PC 0x0c066f54 */
if(!s->budget--) { s->failed_pc=0x0c066f54u; return 0; }
write(ram,r[15],r[11],4);
goto P_0c066f56;
P_0c066f56: /* original 2eb2, guest PC 0x0c066f56 */
if(!s->budget--) { s->failed_pc=0x0c066f56u; return 0; }
write(ram,r[14],r[11],4);
goto P_0c066f58;
P_0c066f58: /* original b226, guest PC 0x0c066f58 */
if(!s->budget--) { s->failed_pc=0x0c066f58u; return 0; }
target=0x0c0673a8u; r[16]=0x0c066f5cu;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c066f5cu) { target=s->pc; goto dispatch; }
goto P_0c066f5c;
P_0c066f5a: /* original 64e3, guest PC 0x0c066f5a */
if(!s->budget--) { s->failed_pc=0x0c066f5au; return 0; }
r[4]=r[14];
goto P_0c066f5c;
P_0c066f5c: /* original b13c, guest PC 0x0c066f5c */
if(!s->budget--) { s->failed_pc=0x0c066f5cu; return 0; }
target=0x0c0671d8u; r[16]=0x0c066f60u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c066f60u) { target=s->pc; goto dispatch; }
goto P_0c066f60;
P_0c066f5e: /* original 64e3, guest PC 0x0c066f5e */
if(!s->budget--) { s->failed_pc=0x0c066f5eu; return 0; }
r[4]=r[14];
goto P_0c066f60;
P_0c066f60: /* original b1ae, guest PC 0x0c066f60 */
if(!s->budget--) { s->failed_pc=0x0c066f60u; return 0; }
target=0x0c0672c0u; r[16]=0x0c066f64u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c066f64u) { target=s->pc; goto dispatch; }
goto P_0c066f64;
P_0c066f62: /* original 64e3, guest PC 0x0c066f62 */
if(!s->budget--) { s->failed_pc=0x0c066f62u; return 0; }
r[4]=r[14];
goto P_0c066f64;
P_0c066f64: /* original b1f2, guest PC 0x0c066f64 */
if(!s->budget--) { s->failed_pc=0x0c066f64u; return 0; }
target=0x0c06734cu; r[16]=0x0c066f68u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c066f68u) { target=s->pc; goto dispatch; }
goto P_0c066f68;
P_0c066f66: /* original 0009, guest PC 0x0c066f66 */
if(!s->budget--) { s->failed_pc=0x0c066f66u; return 0; }
goto P_0c066f68;
P_0c066f68: /* original b1f2, guest PC 0x0c066f68 */
if(!s->budget--) { s->failed_pc=0x0c066f68u; return 0; }
target=0x0c067350u; r[16]=0x0c066f6cu;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c066f6cu) { target=s->pc; goto dispatch; }
goto P_0c066f6c;
P_0c066f6a: /* original 64e3, guest PC 0x0c066f6a */
if(!s->budget--) { s->failed_pc=0x0c066f6au; return 0; }
r[4]=r[14];
goto P_0c066f6c;
P_0c066f6c: /* original d217, guest PC 0x0c066f6c */
if(!s->budget--) { s->failed_pc=0x0c066f6cu; return 0; }
r[2]=read(ram,0x0c066fccu,4);
goto P_0c066f6e;
P_0c066f6e: /* original e500, guest PC 0x0c066f6e */
if(!s->budget--) { s->failed_pc=0x0c066f6eu; return 0; }
r[5]=0x00000000u;
goto P_0c066f70;
P_0c066f70: /* original 420b, guest PC 0x0c066f70 */
if(!s->budget--) { s->failed_pc=0x0c066f70u; return 0; }
target=r[2];
r[16]=0x0c066f74u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c066f74u) { target=s->pc; goto dispatch; }
goto P_0c066f74;
P_0c066f72: /* original 64e3, guest PC 0x0c066f72 */
if(!s->budget--) { s->failed_pc=0x0c066f72u; return 0; }
r[4]=r[14];
goto P_0c066f74;
P_0c066f74: /* original 7f18, guest PC 0x0c066f74 */
if(!s->budget--) { s->failed_pc=0x0c066f74u; return 0; }
r[15]+=0x00000018u;
goto P_0c066f76;
P_0c066f76: /* original 4f26, guest PC 0x0c066f76 */
if(!s->budget--) { s->failed_pc=0x0c066f76u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c066f78;
P_0c066f78: /* original 68f6, guest PC 0x0c066f78 */
if(!s->budget--) { s->failed_pc=0x0c066f78u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c066f7a;
P_0c066f7a: /* original 69f6, guest PC 0x0c066f7a */
if(!s->budget--) { s->failed_pc=0x0c066f7au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c066f7c;
P_0c066f7c: /* original 6af6, guest PC 0x0c066f7c */
if(!s->budget--) { s->failed_pc=0x0c066f7cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c066f7e;
P_0c066f7e: /* original 6bf6, guest PC 0x0c066f7e */
if(!s->budget--) { s->failed_pc=0x0c066f7eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c066f80;
P_0c066f80: /* original 6cf6, guest PC 0x0c066f80 */
if(!s->budget--) { s->failed_pc=0x0c066f80u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c066f82;
P_0c066f82: /* original 6df6, guest PC 0x0c066f82 */
if(!s->budget--) { s->failed_pc=0x0c066f82u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c066f84;
P_0c066f84: /* original 000b, guest PC 0x0c066f84 */
if(!s->budget--) { s->failed_pc=0x0c066f84u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c066f86: /* original 6ef6, guest PC 0x0c066f86 */
if(!s->budget--) { s->failed_pc=0x0c066f86u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c066f88;
P_0c066f88: /* original 6343, guest PC 0x0c066f88 */
if(!s->budget--) { s->failed_pc=0x0c066f88u; return 0; }
r[3]=r[4];
goto P_0c066f8a;
P_0c066f8a: /* original 6243, guest PC 0x0c066f8a */
if(!s->budget--) { s->failed_pc=0x0c066f8au; return 0; }
r[2]=r[4];
goto P_0c066f8c;
P_0c066f8c: /* original d110, guest PC 0x0c066f8c */
if(!s->budget--) { s->failed_pc=0x0c066f8cu; return 0; }
r[1]=read(ram,0x0c066fd0u,4);
goto P_0c066f8e;
P_0c066f8e: /* original 4329, guest PC 0x0c066f8e */
if(!s->budget--) { s->failed_pc=0x0c066f8eu; return 0; }
r[3]>>=16;
goto P_0c066f90;
P_0c066f90: /* original 4219, guest PC 0x0c066f90 */
if(!s->budget--) { s->failed_pc=0x0c066f90u; return 0; }
r[2]>>=8;
goto P_0c066f92;
P_0c066f92: /* original d010, guest PC 0x0c066f92 */
if(!s->budget--) { s->failed_pc=0x0c066f92u; return 0; }
r[0]=read(ram,0x0c066fd4u,4);
goto P_0c066f94;
P_0c066f94: /* original 4319, guest PC 0x0c066f94 */
if(!s->budget--) { s->failed_pc=0x0c066f94u; return 0; }
r[3]>>=8;
goto P_0c066f96;
P_0c066f96: /* original 2219, guest PC 0x0c066f96 */
if(!s->budget--) { s->failed_pc=0x0c066f96u; return 0; }
r[2]&=r[1];
goto P_0c066f98;
P_0c066f98: /* original 633c, guest PC 0x0c066f98 */
if(!s->budget--) { s->failed_pc=0x0c066f98u; return 0; }
r[3]=r[3]&255u;
goto P_0c066f9a;
P_0c066f9a: /* original 232b, guest PC 0x0c066f9a */
if(!s->budget--) { s->failed_pc=0x0c066f9au; return 0; }
r[3]|=r[2];
goto P_0c066f9c;
P_0c066f9c: /* original 6243, guest PC 0x0c066f9c */
if(!s->budget--) { s->failed_pc=0x0c066f9cu; return 0; }
r[2]=r[4];
goto P_0c066f9e;
P_0c066f9e: /* original 4218, guest PC 0x0c066f9e */
if(!s->budget--) { s->failed_pc=0x0c066f9eu; return 0; }
r[2]<<=8;
goto P_0c066fa0;
P_0c066fa0: /* original 2209, guest PC 0x0c066fa0 */
if(!s->budget--) { s->failed_pc=0x0c066fa0u; return 0; }
r[2]&=r[0];
goto P_0c066fa2;
P_0c066fa2: /* original 232b, guest PC 0x0c066fa2 */
if(!s->budget--) { s->failed_pc=0x0c066fa2u; return 0; }
r[3]|=r[2];
goto P_0c066fa4;
P_0c066fa4: /* original 6243, guest PC 0x0c066fa4 */
if(!s->budget--) { s->failed_pc=0x0c066fa4u; return 0; }
r[2]=r[4];
goto P_0c066fa6;
P_0c066fa6: /* original 4228, guest PC 0x0c066fa6 */
if(!s->budget--) { s->failed_pc=0x0c066fa6u; return 0; }
r[2]<<=16;
goto P_0c066fa8;
P_0c066fa8: /* original 6433, guest PC 0x0c066fa8 */
if(!s->budget--) { s->failed_pc=0x0c066fa8u; return 0; }
r[4]=r[3];
goto P_0c066faa;
P_0c066faa: /* original 4128, guest PC 0x0c066faa */
if(!s->budget--) { s->failed_pc=0x0c066faau; return 0; }
r[1]<<=16;
goto P_0c066fac;
P_0c066fac: /* original 4218, guest PC 0x0c066fac */
if(!s->budget--) { s->failed_pc=0x0c066facu; return 0; }
r[2]<<=8;
goto P_0c066fae;
P_0c066fae: /* original 2219, guest PC 0x0c066fae */
if(!s->budget--) { s->failed_pc=0x0c066faeu; return 0; }
r[2]&=r[1];
goto P_0c066fb0;
P_0c066fb0: /* original 242b, guest PC 0x0c066fb0 */
if(!s->budget--) { s->failed_pc=0x0c066fb0u; return 0; }
r[4]|=r[2];
goto P_0c066fb2;
P_0c066fb2: /* original 000b, guest PC 0x0c066fb2 */
if(!s->budget--) { s->failed_pc=0x0c066fb2u; return 0; }
target=r[16];
r[0]=r[4];
s->pc=target; return ram->oob==0;
P_0c066fb4: /* original 6043, guest PC 0x0c066fb4 */
if(!s->budget--) { s->failed_pc=0x0c066fb4u; return 0; }
r[0]=r[4];
return vf3_matrix_family(0x0c066fb6u,s,ram);
P_0c066fd8: /* original 2fe6, guest PC 0x0c066fd8 */
if(!s->budget--) { s->failed_pc=0x0c066fd8u; return 0; }
r[15]-=4; write(ram,r[15],r[14],4);
goto P_0c066fda;
P_0c066fda: /* original 6e43, guest PC 0x0c066fda */
if(!s->budget--) { s->failed_pc=0x0c066fdau; return 0; }
r[14]=r[4];
goto P_0c066fdc;
P_0c066fdc: /* original 2fd6, guest PC 0x0c066fdc */
if(!s->budget--) { s->failed_pc=0x0c066fdcu; return 0; }
r[15]-=4; write(ram,r[15],r[13],4);
goto P_0c066fde;
P_0c066fde: /* original 2fc6, guest PC 0x0c066fde */
if(!s->budget--) { s->failed_pc=0x0c066fdeu; return 0; }
r[15]-=4; write(ram,r[15],r[12],4);
goto P_0c066fe0;
P_0c066fe0: /* original 6c53, guest PC 0x0c066fe0 */
if(!s->budget--) { s->failed_pc=0x0c066fe0u; return 0; }
r[12]=r[5];
goto P_0c066fe2;
P_0c066fe2: /* original 2fb6, guest PC 0x0c066fe2 */
if(!s->budget--) { s->failed_pc=0x0c066fe2u; return 0; }
r[15]-=4; write(ram,r[15],r[11],4);
goto P_0c066fe4;
P_0c066fe4: /* original 6b63, guest PC 0x0c066fe4 */
if(!s->budget--) { s->failed_pc=0x0c066fe4u; return 0; }
r[11]=r[6];
goto P_0c066fe6;
P_0c066fe6: /* original 4f22, guest PC 0x0c066fe6 */
if(!s->budget--) { s->failed_pc=0x0c066fe6u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c066fe8;
P_0c066fe8: /* original 7ffc, guest PC 0x0c066fe8 */
if(!s->budget--) { s->failed_pc=0x0c066fe8u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c066fea;
P_0c066fea: /* original 2f72, guest PC 0x0c066fea */
if(!s->budget--) { s->failed_pc=0x0c066feau; return 0; }
write(ram,r[15],r[7],4);
goto P_0c066fec;
P_0c066fec: /* original 64c2, guest PC 0x0c066fec */
if(!s->budget--) { s->failed_pc=0x0c066fecu; return 0; }
tmp=read(ram,r[12],4);
r[4]=tmp;
goto P_0c066fee;
P_0c066fee: /* original 9069, guest PC 0x0c066fee */
if(!s->budget--) { s->failed_pc=0x0c066feeu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0670c4u,2);
goto P_0c066ff0;
P_0c066ff0: /* original 24b9, guest PC 0x0c066ff0 */
if(!s->budget--) { s->failed_pc=0x0c066ff0u; return 0; }
r[4]&=r[11];
goto P_0c066ff2;
P_0c066ff2: /* original 2448, guest PC 0x0c066ff2 */
if(!s->budget--) { s->failed_pc=0x0c066ff2u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c066ff4;
P_0c066ff4: /* original 8d0e, guest PC 0x0c066ff4 */
if(!s->budget--) { s->failed_pc=0x0c066ff4u; return 0; }
cond=r[17]&1u;
r[13]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
if(cond) { goto P_0c067014; }
goto P_0c066ff8;
P_0c066ff6: /* original 0ded, guest PC 0x0c066ff6 */
if(!s->budget--) { s->failed_pc=0x0c066ff6u; return 0; }
r[13]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c066ff8;
P_0c066ff8: /* original 62c2, guest PC 0x0c066ff8 */
if(!s->budget--) { s->failed_pc=0x0c066ff8u; return 0; }
tmp=read(ram,r[12],4);
r[2]=tmp;
goto P_0c066ffa;
P_0c066ffa: /* original 63b7, guest PC 0x0c066ffa */
if(!s->budget--) { s->failed_pc=0x0c066ffau; return 0; }
r[3]=~r[11];
goto P_0c066ffc;
P_0c066ffc: /* original 2239, guest PC 0x0c066ffc */
if(!s->budget--) { s->failed_pc=0x0c066ffcu; return 0; }
r[2]&=r[3];
goto P_0c066ffe;
P_0c066ffe: /* original 2c22, guest PC 0x0c066ffe */
if(!s->budget--) { s->failed_pc=0x0c066ffeu; return 0; }
write(ram,r[12],r[2],4);
goto P_0c067000;
P_0c067000: /* original 9061, guest PC 0x0c067000 */
if(!s->budget--) { s->failed_pc=0x0c067000u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0670c6u,2);
goto P_0c067002;
P_0c067002: /* original bfc1, guest PC 0x0c067002 */
if(!s->budget--) { s->failed_pc=0x0c067002u; return 0; }
target=0x0c066f88u; r[16]=0x0c067006u;
r[4]=read(ram,r[14]+r[0],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c067006u) { target=s->pc; goto dispatch; }
goto P_0c067006;
P_0c067004: /* original 04ee, guest PC 0x0c067004 */
if(!s->budget--) { s->failed_pc=0x0c067004u; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c067006;
P_0c067006: /* original 6403, guest PC 0x0c067006 */
if(!s->budget--) { s->failed_pc=0x0c067006u; return 0; }
r[4]=r[0];
goto P_0c067008;
P_0c067008: /* original 2448, guest PC 0x0c067008 */
if(!s->budget--) { s->failed_pc=0x0c067008u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c06700a;
P_0c06700a: /* original 8b03, guest PC 0x0c06700a */
if(!s->budget--) { s->failed_pc=0x0c06700au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c067014; }
goto P_0c06700c;
P_0c06700c: /* original 62e3, guest PC 0x0c06700c */
if(!s->budget--) { s->failed_pc=0x0c06700cu; return 0; }
r[2]=r[14];
goto P_0c06700e;
P_0c06700e: /* original 32dc, guest PC 0x0c06700e */
if(!s->budget--) { s->failed_pc=0x0c06700eu; return 0; }
r[2]+=r[13];
goto P_0c067010;
P_0c067010: /* original 6d21, guest PC 0x0c067010 */
if(!s->budget--) { s->failed_pc=0x0c067010u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[2],2);
r[13]=tmp;
goto P_0c067012;
P_0c067012: /* original 6ddd, guest PC 0x0c067012 */
if(!s->budget--) { s->failed_pc=0x0c067012u; return 0; }
r[13]=r[13]&65535u;
goto P_0c067014;
P_0c067014: /* original 63f2, guest PC 0x0c067014 */
if(!s->budget--) { s->failed_pc=0x0c067014u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c067016;
P_0c067016: /* original 9055, guest PC 0x0c067016 */
if(!s->budget--) { s->failed_pc=0x0c067016u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0670c4u,2);
goto P_0c067018;
P_0c067018: /* original 3d38, guest PC 0x0c067018 */
if(!s->budget--) { s->failed_pc=0x0c067018u; return 0; }
r[13]-=r[3];
goto P_0c06701a;
P_0c06701a: /* original 4d15, guest PC 0x0c06701a */
if(!s->budget--) { s->failed_pc=0x0c06701au; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[13]>0)!=0);
goto P_0c06701c;
P_0c06701c: /* original 8d18, guest PC 0x0c06701c */
if(!s->budget--) { s->failed_pc=0x0c06701cu; return 0; }
cond=r[17]&1u;
write(ram,r[14]+r[0],r[13],2);
if(cond) { goto P_0c067050; }
goto P_0c067020;
P_0c06701e: /* original 0ed5, guest PC 0x0c06701e */
if(!s->budget--) { s->failed_pc=0x0c06701eu; return 0; }
write(ram,r[14]+r[0],r[13],2);
goto P_0c067020;
P_0c067020: /* original 9052, guest PC 0x0c067020 */
if(!s->budget--) { s->failed_pc=0x0c067020u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0670c8u,2);
goto P_0c067022;
P_0c067022: /* original 04ee, guest PC 0x0c067022 */
if(!s->budget--) { s->failed_pc=0x0c067022u; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c067024;
P_0c067024: /* original 7404, guest PC 0x0c067024 */
if(!s->budget--) { s->failed_pc=0x0c067024u; return 0; }
r[4]+=0x00000004u;
goto P_0c067026;
P_0c067026: /* original 6546, guest PC 0x0c067026 */
if(!s->budget--) { s->failed_pc=0x0c067026u; return 0; }
tmp=read(ram,r[4],4);
r[4]+=4;
r[5]=tmp;
goto P_0c067028;
P_0c067028: /* original 6746, guest PC 0x0c067028 */
if(!s->budget--) { s->failed_pc=0x0c067028u; return 0; }
tmp=read(ram,r[4],4);
r[4]+=4;
r[7]=tmp;
goto P_0c06702a;
P_0c06702a: /* original 2558, guest PC 0x0c06702a */
if(!s->budget--) { s->failed_pc=0x0c06702au; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[5])==0)!=0);
goto P_0c06702c;
P_0c06702c: /* original 6642, guest PC 0x0c06702c */
if(!s->budget--) { s->failed_pc=0x0c06702cu; return 0; }
tmp=read(ram,r[4],4);
r[6]=tmp;
goto P_0c06702e;
P_0c06702e: /* original 8f07, guest PC 0x0c06702e */
if(!s->budget--) { s->failed_pc=0x0c06702eu; return 0; }
cond=r[17]&1u;
write(ram,r[14]+r[0],r[4],4);
if(!cond) { goto P_0c067040; }
goto P_0c067032;
P_0c067030: /* original 0e46, guest PC 0x0c067030 */
if(!s->budget--) { s->failed_pc=0x0c067030u; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c067032;
P_0c067032: /* original 9047, guest PC 0x0c067032 */
if(!s->budget--) { s->failed_pc=0x0c067032u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0670c4u,2);
goto P_0c067034;
P_0c067034: /* original 0e75, guest PC 0x0c067034 */
if(!s->budget--) { s->failed_pc=0x0c067034u; return 0; }
write(ram,r[14]+r[0],r[7],2);
goto P_0c067036;
P_0c067036: /* original 7008, guest PC 0x0c067036 */
if(!s->budget--) { s->failed_pc=0x0c067036u; return 0; }
r[0]+=0x00000008u;
goto P_0c067038;
P_0c067038: /* original 0e65, guest PC 0x0c067038 */
if(!s->budget--) { s->failed_pc=0x0c067038u; return 0; }
write(ram,r[14]+r[0],r[6],2);
goto P_0c06703a;
P_0c06703a: /* original d326, guest PC 0x0c06703a */
if(!s->budget--) { s->failed_pc=0x0c06703au; return 0; }
r[3]=read(ram,0x0c0670d4u,4);
goto P_0c06703c;
P_0c06703c: /* original a008, guest PC 0x0c06703c */
if(!s->budget--) { s->failed_pc=0x0c06703cu; return 0; }
write(ram,r[14]+48,r[3],4);
goto P_0c067050;
P_0c06703e: /* original 1e3c, guest PC 0x0c06703e */
if(!s->budget--) { s->failed_pc=0x0c06703eu; return 0; }
write(ram,r[14]+48,r[3],4);
goto P_0c067040;
P_0c067040: /* original 61c2, guest PC 0x0c067040 */
if(!s->budget--) { s->failed_pc=0x0c067040u; return 0; }
tmp=read(ram,r[12],4);
r[1]=tmp;
goto P_0c067042;
P_0c067042: /* original 21bb, guest PC 0x0c067042 */
if(!s->budget--) { s->failed_pc=0x0c067042u; return 0; }
r[1]|=r[11];
goto P_0c067044;
P_0c067044: /* original 2c12, guest PC 0x0c067044 */
if(!s->budget--) { s->failed_pc=0x0c067044u; return 0; }
write(ram,r[12],r[1],4);
goto P_0c067046;
P_0c067046: /* original 903d, guest PC 0x0c067046 */
if(!s->budget--) { s->failed_pc=0x0c067046u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0670c4u,2);
goto P_0c067048;
P_0c067048: /* original 0e75, guest PC 0x0c067048 */
if(!s->budget--) { s->failed_pc=0x0c067048u; return 0; }
write(ram,r[14]+r[0],r[7],2);
goto P_0c06704a;
P_0c06704a: /* original 7008, guest PC 0x0c06704a */
if(!s->budget--) { s->failed_pc=0x0c06704au; return 0; }
r[0]+=0x00000008u;
goto P_0c06704c;
P_0c06704c: /* original 0e65, guest PC 0x0c06704c */
if(!s->budget--) { s->failed_pc=0x0c06704cu; return 0; }
write(ram,r[14]+r[0],r[6],2);
goto P_0c06704e;
P_0c06704e: /* original 1e5c, guest PC 0x0c06704e */
if(!s->budget--) { s->failed_pc=0x0c06704eu; return 0; }
write(ram,r[14]+48,r[5],4);
goto P_0c067050;
P_0c067050: /* original 7f04, guest PC 0x0c067050 */
if(!s->budget--) { s->failed_pc=0x0c067050u; return 0; }
r[15]+=0x00000004u;
goto P_0c067052;
P_0c067052: /* original 4f26, guest PC 0x0c067052 */
if(!s->budget--) { s->failed_pc=0x0c067052u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c067054;
P_0c067054: /* original 6bf6, guest PC 0x0c067054 */
if(!s->budget--) { s->failed_pc=0x0c067054u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c067056;
P_0c067056: /* original 6cf6, guest PC 0x0c067056 */
if(!s->budget--) { s->failed_pc=0x0c067056u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c067058;
P_0c067058: /* original 6df6, guest PC 0x0c067058 */
if(!s->budget--) { s->failed_pc=0x0c067058u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c06705a;
P_0c06705a: /* original 000b, guest PC 0x0c06705a */
if(!s->budget--) { s->failed_pc=0x0c06705au; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c06705c: /* original 6ef6, guest PC 0x0c06705c */
if(!s->budget--) { s->failed_pc=0x0c06705cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c06705e;
P_0c06705e: /* original 2fe6, guest PC 0x0c06705e */
if(!s->budget--) { s->failed_pc=0x0c06705eu; return 0; }
r[15]-=4; write(ram,r[15],r[14],4);
goto P_0c067060;
P_0c067060: /* original 6e43, guest PC 0x0c067060 */
if(!s->budget--) { s->failed_pc=0x0c067060u; return 0; }
r[14]=r[4];
goto P_0c067062;
P_0c067062: /* original 2fd6, guest PC 0x0c067062 */
if(!s->budget--) { s->failed_pc=0x0c067062u; return 0; }
r[15]-=4; write(ram,r[15],r[13],4);
goto P_0c067064;
P_0c067064: /* original 2fc6, guest PC 0x0c067064 */
if(!s->budget--) { s->failed_pc=0x0c067064u; return 0; }
r[15]-=4; write(ram,r[15],r[12],4);
goto P_0c067066;
P_0c067066: /* original 2fb6, guest PC 0x0c067066 */
if(!s->budget--) { s->failed_pc=0x0c067066u; return 0; }
r[15]-=4; write(ram,r[15],r[11],4);
goto P_0c067068;
P_0c067068: /* original fffb, guest PC 0x0c067068 */
if(!s->budget--) { s->failed_pc=0x0c067068u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c06706a;
P_0c06706a: /* original ffeb, guest PC 0x0c06706a */
if(!s->budget--) { s->failed_pc=0x0c06706au; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,14,r[15]);
goto P_0c06706c;
P_0c06706c: /* original 902d, guest PC 0x0c06706c */
if(!s->budget--) { s->failed_pc=0x0c06706cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0670cau,2);
goto P_0c06706e;
P_0c06706e: /* original 4f22, guest PC 0x0c06706e */
if(!s->budget--) { s->failed_pc=0x0c06706eu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c067070;
P_0c067070: /* original 03ed, guest PC 0x0c067070 */
if(!s->budget--) { s->failed_pc=0x0c067070u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c067072;
P_0c067072: /* original 73ff, guest PC 0x0c067072 */
if(!s->budget--) { s->failed_pc=0x0c067072u; return 0; }
r[3]+=0xffffffffu;
goto P_0c067074;
P_0c067074: /* original 7ffc, guest PC 0x0c067074 */
if(!s->budget--) { s->failed_pc=0x0c067074u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c067076;
P_0c067076: /* original 0e35, guest PC 0x0c067076 */
if(!s->budget--) { s->failed_pc=0x0c067076u; return 0; }
write(ram,r[14]+r[0],r[3],2);
goto P_0c067078;
P_0c067078: /* original 02ed, guest PC 0x0c067078 */
if(!s->budget--) { s->failed_pc=0x0c067078u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c06707a;
P_0c06707a: /* original 4215, guest PC 0x0c06707a */
if(!s->budget--) { s->failed_pc=0x0c06707au; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>0)!=0);
goto P_0c06707c;
P_0c06707c: /* original 8b01, guest PC 0x0c06707c */
if(!s->budget--) { s->failed_pc=0x0c06707cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c067082; }
goto P_0c06707e;
P_0c06707e: /* original a08b, guest PC 0x0c06707e */
if(!s->budget--) { s->failed_pc=0x0c06707eu; return 0; }
goto P_0c067198;
P_0c067080: /* original 0009, guest PC 0x0c067080 */
if(!s->budget--) { s->failed_pc=0x0c067080u; return 0; }
goto P_0c067082;
P_0c067082: /* original 9023, guest PC 0x0c067082 */
if(!s->budget--) { s->failed_pc=0x0c067082u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0670ccu,2);
goto P_0c067084;
P_0c067084: /* original 04ee, guest PC 0x0c067084 */
if(!s->budget--) { s->failed_pc=0x0c067084u; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c067086;
P_0c067086: /* original 6340, guest PC 0x0c067086 */
if(!s->budget--) { s->failed_pc=0x0c067086u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[4],1);
r[3]=tmp;
goto P_0c067088;
P_0c067088: /* original 633c, guest PC 0x0c067088 */
if(!s->budget--) { s->failed_pc=0x0c067088u; return 0; }
r[3]=r[3]&255u;
goto P_0c06708a;
P_0c06708a: /* original 2f32, guest PC 0x0c06708a */
if(!s->budget--) { s->failed_pc=0x0c06708au; return 0; }
write(ram,r[15],r[3],4);
goto P_0c06708c;
P_0c06708c: /* original 8441, guest PC 0x0c06708c */
if(!s->budget--) { s->failed_pc=0x0c06708cu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+1,1);
goto P_0c06708e;
P_0c06708e: /* original 5641, guest PC 0x0c06708e */
if(!s->budget--) { s->failed_pc=0x0c06708eu; return 0; }
r[6]=read(ram,r[4]+4,4);
goto P_0c067090;
P_0c067090: /* original 650c, guest PC 0x0c067090 */
if(!s->budget--) { s->failed_pc=0x0c067090u; return 0; }
r[5]=r[0]&255u;
goto P_0c067092;
P_0c067092: /* original 8541, guest PC 0x0c067092 */
if(!s->budget--) { s->failed_pc=0x0c067092u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+2,2);
goto P_0c067094;
P_0c067094: /* original 5d45, guest PC 0x0c067094 */
if(!s->budget--) { s->failed_pc=0x0c067094u; return 0; }
r[13]=read(ram,r[4]+20,4);
goto P_0c067096;
P_0c067096: /* original 6b03, guest PC 0x0c067096 */
if(!s->budget--) { s->failed_pc=0x0c067096u; return 0; }
r[11]=r[0];
goto P_0c067098;
P_0c067098: /* original e008, guest PC 0x0c067098 */
if(!s->budget--) { s->failed_pc=0x0c067098u; return 0; }
r[0]=0x00000008u;
goto P_0c06709a;
P_0c06709a: /* original fe46, guest PC 0x0c06709a */
if(!s->budget--) { s->failed_pc=0x0c06709au; return 0; }
vf3_matrix_load(s,ram,14,r[4]+r[0]);
goto P_0c06709c;
P_0c06709c: /* original e00c, guest PC 0x0c06709c */
if(!s->budget--) { s->failed_pc=0x0c06709cu; return 0; }
r[0]=0x0000000cu;
goto P_0c06709e;
P_0c06709e: /* original f546, guest PC 0x0c06709e */
if(!s->budget--) { s->failed_pc=0x0c06709eu; return 0; }
vf3_matrix_load(s,ram,5,r[4]+r[0]);
goto P_0c0670a0;
P_0c0670a0: /* original e010, guest PC 0x0c0670a0 */
if(!s->budget--) { s->failed_pc=0x0c0670a0u; return 0; }
r[0]=0x00000010u;
goto P_0c0670a2;
P_0c0670a2: /* original ff46, guest PC 0x0c0670a2 */
if(!s->budget--) { s->failed_pc=0x0c0670a2u; return 0; }
vf3_matrix_load(s,ram,15,r[4]+r[0]);
goto P_0c0670a4;
P_0c0670a4: /* original 7418, guest PC 0x0c0670a4 */
if(!s->budget--) { s->failed_pc=0x0c0670a4u; return 0; }
r[4]+=0x00000018u;
goto P_0c0670a6;
P_0c0670a6: /* original 9010, guest PC 0x0c0670a6 */
if(!s->budget--) { s->failed_pc=0x0c0670a6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0670cau,2);
goto P_0c0670a8;
P_0c0670a8: /* original ff4d, guest PC 0x0c0670a8 */
if(!s->budget--) { s->failed_pc=0x0c0670a8u; return 0; }
fr[15]^=0x80000000u;
goto P_0c0670aa;
P_0c0670aa: /* original 0e65, guest PC 0x0c0670aa */
if(!s->budget--) { s->failed_pc=0x0c0670aau; return 0; }
write(ram,r[14]+r[0],r[6],2);
goto P_0c0670ac;
P_0c0670ac: /* original 70f2, guest PC 0x0c0670ac */
if(!s->budget--) { s->failed_pc=0x0c0670acu; return 0; }
r[0]+=0xfffffff2u;
goto P_0c0670ae;
P_0c0670ae: /* original 930e, guest PC 0x0c0670ae */
if(!s->budget--) { s->failed_pc=0x0c0670aeu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0670ceu,2);
goto P_0c0670b0;
P_0c0670b0: /* original 3530, guest PC 0x0c0670b0 */
if(!s->budget--) { s->failed_pc=0x0c0670b0u; return 0; }
r[17]=(r[17]&~1u)|((r[5]==r[3])!=0);
goto P_0c0670b2;
P_0c0670b2: /* original 8f11, guest PC 0x0c0670b2 */
if(!s->budget--) { s->failed_pc=0x0c0670b2u; return 0; }
cond=r[17]&1u;
write(ram,r[14]+r[0],r[4],4);
if(!cond) { goto P_0c0670d8; }
goto P_0c0670b6;
P_0c0670b4: /* original 0e46, guest PC 0x0c0670b4 */
if(!s->budget--) { s->failed_pc=0x0c0670b4u; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c0670b6;
P_0c0670b6: /* original 900b, guest PC 0x0c0670b6 */
if(!s->budget--) { s->failed_pc=0x0c0670b6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0670d0u,2);
goto P_0c0670b8;
P_0c0670b8: /* original e3fe, guest PC 0x0c0670b8 */
if(!s->budget--) { s->failed_pc=0x0c0670b8u; return 0; }
r[3]=0xfffffffeu;
goto P_0c0670ba;
P_0c0670ba: /* original 0e54, guest PC 0x0c0670ba */
if(!s->budget--) { s->failed_pc=0x0c0670bau; return 0; }
write(ram,r[14]+r[0],r[5],1);
goto P_0c0670bc;
P_0c0670bc: /* original 62e2, guest PC 0x0c0670bc */
if(!s->budget--) { s->failed_pc=0x0c0670bcu; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c0670be;
P_0c0670be: /* original 2239, guest PC 0x0c0670be */
if(!s->budget--) { s->failed_pc=0x0c0670beu; return 0; }
r[2]&=r[3];
goto P_0c0670c0;
P_0c0670c0: /* original a06a, guest PC 0x0c0670c0 */
if(!s->budget--) { s->failed_pc=0x0c0670c0u; return 0; }
write(ram,r[14],r[2],4);
goto P_0c067198;
P_0c0670c2: /* original 2e22, guest PC 0x0c0670c2 */
if(!s->budget--) { s->failed_pc=0x0c0670c2u; return 0; }
write(ram,r[14],r[2],4);
return vf3_matrix_family(0x0c0670c4u,s,ram);
P_0c0670d8: /* original e060, guest PC 0x0c0670d8 */
if(!s->budget--) { s->failed_pc=0x0c0670d8u; return 0; }
r[0]=0x00000060u;
goto P_0c0670da;
P_0c0670da: /* original 03ec, guest PC 0x0c0670da */
if(!s->budget--) { s->failed_pc=0x0c0670dau; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0670dc;
P_0c0670dc: /* original 633c, guest PC 0x0c0670dc */
if(!s->budget--) { s->failed_pc=0x0c0670dcu; return 0; }
r[3]=r[3]&255u;
goto P_0c0670de;
P_0c0670de: /* original 3350, guest PC 0x0c0670de */
if(!s->budget--) { s->failed_pc=0x0c0670deu; return 0; }
r[17]=(r[17]&~1u)|((r[3]==r[5])!=0);
goto P_0c0670e0;
P_0c0670e0: /* original 8f3b, guest PC 0x0c0670e0 */
if(!s->budget--) { s->failed_pc=0x0c0670e0u; return 0; }
cond=r[17]&1u;
r[12]=0x00000001u;
if(!cond) { goto P_0c06715a; }
goto P_0c0670e4;
P_0c0670e2: /* original ec01, guest PC 0x0c0670e2 */
if(!s->budget--) { s->failed_pc=0x0c0670e2u; return 0; }
r[12]=0x00000001u;
goto P_0c0670e4;
P_0c0670e4: /* original 63e2, guest PC 0x0c0670e4 */
if(!s->budget--) { s->failed_pc=0x0c0670e4u; return 0; }
tmp=read(ram,r[14],4);
r[3]=tmp;
goto P_0c0670e6;
P_0c0670e6: /* original 23c8, guest PC 0x0c0670e6 */
if(!s->budget--) { s->failed_pc=0x0c0670e6u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[12])==0)!=0);
goto P_0c0670e8;
P_0c0670e8: /* original 8937, guest PC 0x0c0670e8 */
if(!s->budget--) { s->failed_pc=0x0c0670e8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c06715a; }
goto P_0c0670ea;
P_0c0670ea: /* original 6053, guest PC 0x0c0670ea */
if(!s->budget--) { s->failed_pc=0x0c0670eau; return 0; }
r[0]=r[5];
goto P_0c0670ec;
P_0c0670ec: /* original 8816, guest PC 0x0c0670ec */
if(!s->budget--) { s->failed_pc=0x0c0670ecu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000016u)!=0);
goto P_0c0670ee;
P_0c0670ee: /* original 8905, guest PC 0x0c0670ee */
if(!s->budget--) { s->failed_pc=0x0c0670eeu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0670fc; }
goto P_0c0670f0;
P_0c0670f0: /* original d331, guest PC 0x0c0670f0 */
if(!s->budget--) { s->failed_pc=0x0c0670f0u; return 0; }
r[3]=read(ram,0x0c0671b8u,4);
goto P_0c0670f2;
P_0c0670f2: /* original f5fc, guest PC 0x0c0670f2 */
if(!s->budget--) { s->failed_pc=0x0c0670f2u; return 0; }
vf3_matrix_move(s,5,15);
goto P_0c0670f4;
P_0c0670f4: /* original f54d, guest PC 0x0c0670f4 */
if(!s->budget--) { s->failed_pc=0x0c0670f4u; return 0; }
fr[5]^=0x80000000u;
goto P_0c0670f6;
P_0c0670f6: /* original 430b, guest PC 0x0c0670f6 */
if(!s->budget--) { s->failed_pc=0x0c0670f6u; return 0; }
target=r[3];
r[16]=0x0c0670fau;
vf3_matrix_move(s,4,14);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0670fau) { target=s->pc; goto dispatch; }
goto P_0c0670fa;
P_0c0670f8: /* original f4ec, guest PC 0x0c0670f8 */
if(!s->budget--) { s->failed_pc=0x0c0670f8u; return 0; }
vf3_matrix_move(s,4,14);
goto P_0c0670fa;
P_0c0670fa: /* original f50c, guest PC 0x0c0670fa */
if(!s->budget--) { s->failed_pc=0x0c0670fau; return 0; }
vf3_matrix_move(s,5,0);
goto P_0c0670fc;
P_0c0670fc: /* original e010, guest PC 0x0c0670fc */
if(!s->budget--) { s->failed_pc=0x0c0670fcu; return 0; }
r[0]=0x00000010u;
goto P_0c0670fe;
P_0c0670fe: /* original fee7, guest PC 0x0c0670fe */
if(!s->budget--) { s->failed_pc=0x0c0670feu; return 0; }
vf3_matrix_store(s,ram,14,r[14]+r[0]);
goto P_0c067100;
P_0c067100: /* original e014, guest PC 0x0c067100 */
if(!s->budget--) { s->failed_pc=0x0c067100u; return 0; }
r[0]=0x00000014u;
goto P_0c067102;
P_0c067102: /* original fe57, guest PC 0x0c067102 */
if(!s->budget--) { s->failed_pc=0x0c067102u; return 0; }
vf3_matrix_store(s,ram,5,r[14]+r[0]);
goto P_0c067104;
P_0c067104: /* original e018, guest PC 0x0c067104 */
if(!s->budget--) { s->failed_pc=0x0c067104u; return 0; }
r[0]=0x00000018u;
goto P_0c067106;
P_0c067106: /* original fef7, guest PC 0x0c067106 */
if(!s->budget--) { s->failed_pc=0x0c067106u; return 0; }
vf3_matrix_store(s,ram,15,r[14]+r[0]);
goto P_0c067108;
P_0c067108: /* original 9051, guest PC 0x0c067108 */
if(!s->budget--) { s->failed_pc=0x0c067108u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0671aeu,2);
goto P_0c06710a;
P_0c06710a: /* original fee7, guest PC 0x0c06710a */
if(!s->budget--) { s->failed_pc=0x0c06710au; return 0; }
vf3_matrix_store(s,ram,14,r[14]+r[0]);
goto P_0c06710c;
P_0c06710c: /* original 7004, guest PC 0x0c06710c */
if(!s->budget--) { s->failed_pc=0x0c06710cu; return 0; }
r[0]+=0x00000004u;
goto P_0c06710e;
P_0c06710e: /* original fe57, guest PC 0x0c06710e */
if(!s->budget--) { s->failed_pc=0x0c06710eu; return 0; }
vf3_matrix_store(s,ram,5,r[14]+r[0]);
goto P_0c067110;
P_0c067110: /* original 7004, guest PC 0x0c067110 */
if(!s->budget--) { s->failed_pc=0x0c067110u; return 0; }
r[0]+=0x00000004u;
goto P_0c067112;
P_0c067112: /* original fef7, guest PC 0x0c067112 */
if(!s->budget--) { s->failed_pc=0x0c067112u; return 0; }
vf3_matrix_store(s,ram,15,r[14]+r[0]);
goto P_0c067114;
P_0c067114: /* original 904d, guest PC 0x0c067114 */
if(!s->budget--) { s->failed_pc=0x0c067114u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0671b2u,2);
goto P_0c067116;
P_0c067116: /* original 934b, guest PC 0x0c067116 */
if(!s->budget--) { s->failed_pc=0x0c067116u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0671b0u,2);
goto P_0c067118;
P_0c067118: /* original 0e34, guest PC 0x0c067118 */
if(!s->budget--) { s->failed_pc=0x0c067118u; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c06711a;
P_0c06711a: /* original 60b3, guest PC 0x0c06711a */
if(!s->budget--) { s->failed_pc=0x0c06711au; return 0; }
r[0]=r[11];
goto P_0c06711c;
P_0c06711c: /* original 81ef, guest PC 0x0c06711c */
if(!s->budget--) { s->failed_pc=0x0c06711cu; return 0; }
write(ram,r[14]+30,r[0],2);
goto P_0c06711e;
P_0c06711e: /* original 60d3, guest PC 0x0c06711e */
if(!s->budget--) { s->failed_pc=0x0c06711eu; return 0; }
r[0]=r[13];
goto P_0c067120;
P_0c067120: /* original 62e2, guest PC 0x0c067120 */
if(!s->budget--) { s->failed_pc=0x0c067120u; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c067122;
P_0c067122: /* original 88ff, guest PC 0x0c067122 */
if(!s->budget--) { s->failed_pc=0x0c067122u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c067124;
P_0c067124: /* original d325, guest PC 0x0c067124 */
if(!s->budget--) { s->failed_pc=0x0c067124u; return 0; }
r[3]=read(ram,0x0c0671bcu,4);
goto P_0c067126;
P_0c067126: /* original 2239, guest PC 0x0c067126 */
if(!s->budget--) { s->failed_pc=0x0c067126u; return 0; }
r[2]&=r[3];
goto P_0c067128;
P_0c067128: /* original 8d36, guest PC 0x0c067128 */
if(!s->budget--) { s->failed_pc=0x0c067128u; return 0; }
cond=r[17]&1u;
write(ram,r[14],r[2],4);
if(cond) { goto P_0c067198; }
goto P_0c06712c;
P_0c06712a: /* original 2e22, guest PC 0x0c06712a */
if(!s->budget--) { s->failed_pc=0x0c06712au; return 0; }
write(ram,r[14],r[2],4);
goto P_0c06712c;
P_0c06712c: /* original 53ee, guest PC 0x0c06712c */
if(!s->budget--) { s->failed_pc=0x0c06712cu; return 0; }
r[3]=read(ram,r[14]+56,4);
goto P_0c06712e;
P_0c06712e: /* original 33d0, guest PC 0x0c06712e */
if(!s->budget--) { s->failed_pc=0x0c06712eu; return 0; }
r[17]=(r[17]&~1u)|((r[3]==r[13])!=0);
goto P_0c067130;
P_0c067130: /* original 8d02, guest PC 0x0c067130 */
if(!s->budget--) { s->failed_pc=0x0c067130u; return 0; }
cond=r[17]&1u;
r[4]=0x00000000u;
if(cond) { goto P_0c067138; }
goto P_0c067134;
P_0c067132: /* original e400, guest PC 0x0c067132 */
if(!s->budget--) { s->failed_pc=0x0c067132u; return 0; }
r[4]=0x00000000u;
goto P_0c067134;
P_0c067134: /* original 1edc, guest PC 0x0c067134 */
if(!s->budget--) { s->failed_pc=0x0c067134u; return 0; }
write(ram,r[14]+48,r[13],4);
goto P_0c067136;
P_0c067136: /* original 1e4e, guest PC 0x0c067136 */
if(!s->budget--) { s->failed_pc=0x0c067136u; return 0; }
write(ram,r[14]+56,r[4],4);
goto P_0c067138;
P_0c067138: /* original 62e2, guest PC 0x0c067138 */
if(!s->budget--) { s->failed_pc=0x0c067138u; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c06713a;
P_0c06713a: /* original e066, guest PC 0x0c06713a */
if(!s->budget--) { s->failed_pc=0x0c06713au; return 0; }
r[0]=0x00000066u;
goto P_0c06713c;
P_0c06713c: /* original d320, guest PC 0x0c06713c */
if(!s->budget--) { s->failed_pc=0x0c06713cu; return 0; }
r[3]=read(ram,0x0c0671c0u,4);
goto P_0c06713e;
P_0c06713e: /* original 2239, guest PC 0x0c06713e */
if(!s->budget--) { s->failed_pc=0x0c06713eu; return 0; }
r[2]&=r[3];
goto P_0c067140;
P_0c067140: /* original 2e22, guest PC 0x0c067140 */
if(!s->budget--) { s->failed_pc=0x0c067140u; return 0; }
write(ram,r[14],r[2],4);
goto P_0c067142;
P_0c067142: /* original 9237, guest PC 0x0c067142 */
if(!s->budget--) { s->failed_pc=0x0c067142u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0671b4u,2);
goto P_0c067144;
P_0c067144: /* original 61e2, guest PC 0x0c067144 */
if(!s->budget--) { s->failed_pc=0x0c067144u; return 0; }
tmp=read(ram,r[14],4);
r[1]=tmp;
goto P_0c067146;
P_0c067146: /* original 212b, guest PC 0x0c067146 */
if(!s->budget--) { s->failed_pc=0x0c067146u; return 0; }
r[1]|=r[2];
goto P_0c067148;
P_0c067148: /* original 2e12, guest PC 0x0c067148 */
if(!s->budget--) { s->failed_pc=0x0c067148u; return 0; }
write(ram,r[14],r[1],4);
goto P_0c06714a;
P_0c06714a: /* original 0e45, guest PC 0x0c06714a */
if(!s->budget--) { s->failed_pc=0x0c06714au; return 0; }
write(ram,r[14]+r[0],r[4],2);
goto P_0c06714c;
P_0c06714c: /* original e048, guest PC 0x0c06714c */
if(!s->budget--) { s->failed_pc=0x0c06714cu; return 0; }
r[0]=0x00000048u;
goto P_0c06714e;
P_0c06714e: /* original 0e46, guest PC 0x0c06714e */
if(!s->budget--) { s->failed_pc=0x0c06714eu; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c067150;
P_0c067150: /* original 84e4, guest PC 0x0c067150 */
if(!s->budget--) { s->failed_pc=0x0c067150u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+4,1);
goto P_0c067152;
P_0c067152: /* original 2008, guest PC 0x0c067152 */
if(!s->budget--) { s->failed_pc=0x0c067152u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c067154;
P_0c067154: /* original 8b20, guest PC 0x0c067154 */
if(!s->budget--) { s->failed_pc=0x0c067154u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c067198; }
goto P_0c067156;
P_0c067156: /* original a01f, guest PC 0x0c067156 */
if(!s->budget--) { s->failed_pc=0x0c067156u; return 0; }
goto P_0c067198;
P_0c067158: /* original 0009, guest PC 0x0c067158 */
if(!s->budget--) { s->failed_pc=0x0c067158u; return 0; }
goto P_0c06715a;
P_0c06715a: /* original 60d3, guest PC 0x0c06715a */
if(!s->budget--) { s->failed_pc=0x0c06715au; return 0; }
r[0]=r[13];
goto P_0c06715c;
P_0c06715c: /* original 88ff, guest PC 0x0c06715c */
if(!s->budget--) { s->failed_pc=0x0c06715cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c06715e;
P_0c06715e: /* original 8f01, guest PC 0x0c06715e */
if(!s->budget--) { s->failed_pc=0x0c06715eu; return 0; }
cond=r[17]&1u;
r[0]=0x00000060u;
if(!cond) { goto P_0c067164; }
goto P_0c067162;
P_0c067160: /* original e060, guest PC 0x0c067160 */
if(!s->budget--) { s->failed_pc=0x0c067160u; return 0; }
r[0]=0x00000060u;
goto P_0c067162;
P_0c067162: /* original dd18, guest PC 0x0c067162 */
if(!s->budget--) { s->failed_pc=0x0c067162u; return 0; }
r[13]=read(ram,0x0c0671c4u,4);
goto P_0c067164;
P_0c067164: /* original 0e54, guest PC 0x0c067164 */
if(!s->budget--) { s->failed_pc=0x0c067164u; return 0; }
write(ram,r[14]+r[0],r[5],1);
goto P_0c067166;
P_0c067166: /* original 66b3, guest PC 0x0c067166 */
if(!s->budget--) { s->failed_pc=0x0c067166u; return 0; }
r[6]=r[11];
goto P_0c067168;
P_0c067168: /* original 65f2, guest PC 0x0c067168 */
if(!s->budget--) { s->failed_pc=0x0c067168u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c06716a;
P_0c06716a: /* original d317, guest PC 0x0c06716a */
if(!s->budget--) { s->failed_pc=0x0c06716au; return 0; }
r[3]=read(ram,0x0c0671c8u,4);
goto P_0c06716c;
P_0c06716c: /* original f4ec, guest PC 0x0c06716c */
if(!s->budget--) { s->failed_pc=0x0c06716cu; return 0; }
vf3_matrix_move(s,4,14);
goto P_0c06716e;
P_0c06716e: /* original f6fc, guest PC 0x0c06716e */
if(!s->budget--) { s->failed_pc=0x0c06716eu; return 0; }
vf3_matrix_move(s,6,15);
goto P_0c067170;
P_0c067170: /* original 430b, guest PC 0x0c067170 */
if(!s->budget--) { s->failed_pc=0x0c067170u; return 0; }
target=r[3];
r[16]=0x0c067174u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c067174u) { target=s->pc; goto dispatch; }
goto P_0c067174;
P_0c067172: /* original 64e3, guest PC 0x0c067172 */
if(!s->budget--) { s->failed_pc=0x0c067172u; return 0; }
r[4]=r[14];
goto P_0c067174;
P_0c067174: /* original 1edc, guest PC 0x0c067174 */
if(!s->budget--) { s->failed_pc=0x0c067174u; return 0; }
write(ram,r[14]+48,r[13],4);
goto P_0c067176;
P_0c067176: /* original d215, guest PC 0x0c067176 */
if(!s->budget--) { s->failed_pc=0x0c067176u; return 0; }
r[2]=read(ram,0x0c0671ccu,4);
goto P_0c067178;
P_0c067178: /* original 1e23, guest PC 0x0c067178 */
if(!s->budget--) { s->failed_pc=0x0c067178u; return 0; }
write(ram,r[14]+12,r[2],4);
goto P_0c06717a;
P_0c06717a: /* original 84e4, guest PC 0x0c06717a */
if(!s->budget--) { s->failed_pc=0x0c06717au; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+4,1);
goto P_0c06717c;
P_0c06717c: /* original 2008, guest PC 0x0c06717c */
if(!s->budget--) { s->failed_pc=0x0c06717cu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c06717e;
P_0c06717e: /* original 8b04, guest PC 0x0c06717e */
if(!s->budget--) { s->failed_pc=0x0c06717eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06718a; }
goto P_0c067180;
P_0c067180: /* original 62e2, guest PC 0x0c067180 */
if(!s->budget--) { s->failed_pc=0x0c067180u; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c067182;
P_0c067182: /* original e3fe, guest PC 0x0c067182 */
if(!s->budget--) { s->failed_pc=0x0c067182u; return 0; }
r[3]=0xfffffffeu;
goto P_0c067184;
P_0c067184: /* original 2239, guest PC 0x0c067184 */
if(!s->budget--) { s->failed_pc=0x0c067184u; return 0; }
r[2]&=r[3];
goto P_0c067186;
P_0c067186: /* original a005, guest PC 0x0c067186 */
if(!s->budget--) { s->failed_pc=0x0c067186u; return 0; }
write(ram,r[14],r[2],4);
goto P_0c067194;
P_0c067188: /* original 2e22, guest PC 0x0c067188 */
if(!s->budget--) { s->failed_pc=0x0c067188u; return 0; }
write(ram,r[14],r[2],4);
goto P_0c06718a;
P_0c06718a: /* original d011, guest PC 0x0c06718a */
if(!s->budget--) { s->failed_pc=0x0c06718au; return 0; }
r[0]=read(ram,0x0c0671d0u,4);
goto P_0c06718c;
P_0c06718c: /* original 6402, guest PC 0x0c06718c */
if(!s->budget--) { s->failed_pc=0x0c06718cu; return 0; }
tmp=read(ram,r[0],4);
r[4]=tmp;
goto P_0c06718e;
P_0c06718e: /* original 6342, guest PC 0x0c06718e */
if(!s->budget--) { s->failed_pc=0x0c06718eu; return 0; }
tmp=read(ram,r[4],4);
r[3]=tmp;
goto P_0c067190;
P_0c067190: /* original 23cb, guest PC 0x0c067190 */
if(!s->budget--) { s->failed_pc=0x0c067190u; return 0; }
r[3]|=r[12];
goto P_0c067192;
P_0c067192: /* original 2432, guest PC 0x0c067192 */
if(!s->budget--) { s->failed_pc=0x0c067192u; return 0; }
write(ram,r[4],r[3],4);
goto P_0c067194;
P_0c067194: /* original d20f, guest PC 0x0c067194 */
if(!s->budget--) { s->failed_pc=0x0c067194u; return 0; }
r[2]=read(ram,0x0c0671d4u,4);
goto P_0c067196;
P_0c067196: /* original 22c0, guest PC 0x0c067196 */
if(!s->budget--) { s->failed_pc=0x0c067196u; return 0; }
write(ram,r[2],r[12],1);
goto P_0c067198;
P_0c067198: /* original 7f04, guest PC 0x0c067198 */
if(!s->budget--) { s->failed_pc=0x0c067198u; return 0; }
r[15]+=0x00000004u;
goto P_0c06719a;
P_0c06719a: /* original 4f26, guest PC 0x0c06719a */
if(!s->budget--) { s->failed_pc=0x0c06719au; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c06719c;
P_0c06719c: /* original fef9, guest PC 0x0c06719c */
if(!s->budget--) { s->failed_pc=0x0c06719cu; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c06719e;
P_0c06719e: /* original fff9, guest PC 0x0c06719e */
if(!s->budget--) { s->failed_pc=0x0c06719eu; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0671a0;
P_0c0671a0: /* original 6bf6, guest PC 0x0c0671a0 */
if(!s->budget--) { s->failed_pc=0x0c0671a0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0671a2;
P_0c0671a2: /* original 6cf6, guest PC 0x0c0671a2 */
if(!s->budget--) { s->failed_pc=0x0c0671a2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0671a4;
P_0c0671a4: /* original 6df6, guest PC 0x0c0671a4 */
if(!s->budget--) { s->failed_pc=0x0c0671a4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0671a6;
P_0c0671a6: /* original 000b, guest PC 0x0c0671a6 */
if(!s->budget--) { s->failed_pc=0x0c0671a6u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0671a8: /* original 6ef6, guest PC 0x0c0671a8 */
if(!s->budget--) { s->failed_pc=0x0c0671a8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0671aa;
P_0c0671aa: /* original 000b, guest PC 0x0c0671aa */
if(!s->budget--) { s->failed_pc=0x0c0671aau; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c0671ac: /* original 0009, guest PC 0x0c0671ac */
if(!s->budget--) { s->failed_pc=0x0c0671acu; return 0; }
return vf3_matrix_family(0x0c0671aeu,s,ram);
P_0c0671d8: /* original 9064, guest PC 0x0c0671d8 */
if(!s->budget--) { s->failed_pc=0x0c0671d8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0672a4u,2);
goto P_0c0671da;
P_0c0671da: /* original 4f22, guest PC 0x0c0671da */
if(!s->budget--) { s->failed_pc=0x0c0671dau; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0671dc;
P_0c0671dc: /* original 064c, guest PC 0x0c0671dc */
if(!s->budget--) { s->failed_pc=0x0c0671dcu; return 0; }
r[6]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c0671de;
P_0c0671de: /* original 2668, guest PC 0x0c0671de */
if(!s->budget--) { s->failed_pc=0x0c0671deu; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[6])==0)!=0);
goto P_0c0671e0;
P_0c0671e0: /* original 6563, guest PC 0x0c0671e0 */
if(!s->budget--) { s->failed_pc=0x0c0671e0u; return 0; }
r[5]=r[6];
goto P_0c0671e2;
P_0c0671e2: /* original 7ff4, guest PC 0x0c0671e2 */
if(!s->budget--) { s->failed_pc=0x0c0671e2u; return 0; }
r[15]+=0xfffffff4u;
goto P_0c0671e4;
P_0c0671e4: /* original 8d5a, guest PC 0x0c0671e4 */
if(!s->budget--) { s->failed_pc=0x0c0671e4u; return 0; }
cond=r[17]&1u;
r[5]+=0xffffffffu;
if(cond) { goto P_0c06729c; }
goto P_0c0671e8;
P_0c0671e6: /* original 75ff, guest PC 0x0c0671e6 */
if(!s->budget--) { s->failed_pc=0x0c0671e6u; return 0; }
r[5]+=0xffffffffu;
goto P_0c0671e8;
P_0c0671e8: /* original 0454, guest PC 0x0c0671e8 */
if(!s->budget--) { s->failed_pc=0x0c0671e8u; return 0; }
write(ram,r[4]+r[0],r[5],1);
goto P_0c0671ea;
P_0c0671ea: /* original 702c, guest PC 0x0c0671ea */
if(!s->budget--) { s->failed_pc=0x0c0671eau; return 0; }
r[0]+=0x0000002cu;
goto P_0c0671ec;
P_0c0671ec: /* original f446, guest PC 0x0c0671ec */
if(!s->budget--) { s->failed_pc=0x0c0671ecu; return 0; }
vf3_matrix_load(s,ram,4,r[4]+r[0]);
goto P_0c0671ee;
P_0c0671ee: /* original 70e4, guest PC 0x0c0671ee */
if(!s->budget--) { s->failed_pc=0x0c0671eeu; return 0; }
r[0]+=0xffffffe4u;
goto P_0c0671f0;
P_0c0671f0: /* original f846, guest PC 0x0c0671f0 */
if(!s->budget--) { s->failed_pc=0x0c0671f0u; return 0; }
vf3_matrix_load(s,ram,8,r[4]+r[0]);
goto P_0c0671f2;
P_0c0671f2: /* original 9058, guest PC 0x0c0671f2 */
if(!s->budget--) { s->failed_pc=0x0c0671f2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0672a6u,2);
goto P_0c0671f4;
P_0c0671f4: /* original f546, guest PC 0x0c0671f4 */
if(!s->budget--) { s->failed_pc=0x0c0671f4u; return 0; }
vf3_matrix_load(s,ram,5,r[4]+r[0]);
goto P_0c0671f6;
P_0c0671f6: /* original 7004, guest PC 0x0c0671f6 */
if(!s->budget--) { s->failed_pc=0x0c0671f6u; return 0; }
r[0]+=0x00000004u;
goto P_0c0671f8;
P_0c0671f8: /* original f746, guest PC 0x0c0671f8 */
if(!s->budget--) { s->failed_pc=0x0c0671f8u; return 0; }
vf3_matrix_load(s,ram,7,r[4]+r[0]);
goto P_0c0671fa;
P_0c0671fa: /* original 700c, guest PC 0x0c0671fa */
if(!s->budget--) { s->failed_pc=0x0c0671fau; return 0; }
r[0]+=0x0000000cu;
goto P_0c0671fc;
P_0c0671fc: /* original f646, guest PC 0x0c0671fc */
if(!s->budget--) { s->failed_pc=0x0c0671fcu; return 0; }
vf3_matrix_load(s,ram,6,r[4]+r[0]);
goto P_0c0671fe;
P_0c0671fe: /* original 9053, guest PC 0x0c0671fe */
if(!s->budget--) { s->failed_pc=0x0c0671feu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0672a8u,2);
goto P_0c067200;
P_0c067200: /* original fb46, guest PC 0x0c067200 */
if(!s->budget--) { s->failed_pc=0x0c067200u; return 0; }
vf3_matrix_load(s,ram,11,r[4]+r[0]);
goto P_0c067202;
P_0c067202: /* original 7004, guest PC 0x0c067202 */
if(!s->budget--) { s->failed_pc=0x0c067202u; return 0; }
r[0]+=0x00000004u;
goto P_0c067204;
P_0c067204: /* original f346, guest PC 0x0c067204 */
if(!s->budget--) { s->failed_pc=0x0c067204u; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c067206;
P_0c067206: /* original e008, guest PC 0x0c067206 */
if(!s->budget--) { s->failed_pc=0x0c067206u; return 0; }
r[0]=0x00000008u;
goto P_0c067208;
P_0c067208: /* original ff37, guest PC 0x0c067208 */
if(!s->budget--) { s->failed_pc=0x0c067208u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c06720a;
P_0c06720a: /* original 904e, guest PC 0x0c06720a */
if(!s->budget--) { s->failed_pc=0x0c06720au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0672aau,2);
goto P_0c06720c;
P_0c06720c: /* original f946, guest PC 0x0c06720c */
if(!s->budget--) { s->failed_pc=0x0c06720cu; return 0; }
vf3_matrix_load(s,ram,9,r[4]+r[0]);
goto P_0c06720e;
P_0c06720e: /* original 7004, guest PC 0x0c06720e */
if(!s->budget--) { s->failed_pc=0x0c06720eu; return 0; }
r[0]+=0x00000004u;
goto P_0c067210;
P_0c067210: /* original 034c, guest PC 0x0c067210 */
if(!s->budget--) { s->failed_pc=0x0c067210u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c067212;
P_0c067212: /* original 7002, guest PC 0x0c067212 */
if(!s->budget--) { s->failed_pc=0x0c067212u; return 0; }
r[0]+=0x00000002u;
goto P_0c067214;
P_0c067214: /* original 024c, guest PC 0x0c067214 */
if(!s->budget--) { s->failed_pc=0x0c067214u; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c067216;
P_0c067216: /* original 3327, guest PC 0x0c067216 */
if(!s->budget--) { s->failed_pc=0x0c067216u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>(int32_t)r[2])!=0);
goto P_0c067218;
P_0c067218: /* original 891b, guest PC 0x0c067218 */
if(!s->budget--) { s->failed_pc=0x0c067218u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c067252; }
goto P_0c06721a;
P_0c06721a: /* original d327, guest PC 0x0c06721a */
if(!s->budget--) { s->failed_pc=0x0c06721au; return 0; }
r[3]=read(ram,0x0c0672b8u,4);
goto P_0c06721c;
P_0c06721c: /* original f480, guest PC 0x0c06721c */
if(!s->budget--) { s->failed_pc=0x0c06721cu; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[8],r[18],'+');
goto P_0c06721e;
P_0c06721e: /* original 6630, guest PC 0x0c06721e */
if(!s->budget--) { s->failed_pc=0x0c06721eu; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[3],1);
r[6]=tmp;
goto P_0c067220;
P_0c067220: /* original 666c, guest PC 0x0c067220 */
if(!s->budget--) { s->failed_pc=0x0c067220u; return 0; }
r[6]=r[6]&255u;
goto P_0c067222;
P_0c067222: /* original 6063, guest PC 0x0c067222 */
if(!s->budget--) { s->failed_pc=0x0c067222u; return 0; }
r[0]=r[6];
goto P_0c067224;
P_0c067224: /* original 8806, guest PC 0x0c067224 */
if(!s->budget--) { s->failed_pc=0x0c067224u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000006u)!=0);
goto P_0c067226;
P_0c067226: /* original 8f02, guest PC 0x0c067226 */
if(!s->budget--) { s->failed_pc=0x0c067226u; return 0; }
cond=r[17]&1u;
fr[8]=0;
if(!cond) { goto P_0c06722e; }
goto P_0c06722a;
P_0c067228: /* original f88d, guest PC 0x0c067228 */
if(!s->budget--) { s->failed_pc=0x0c067228u; return 0; }
fr[8]=0;
goto P_0c06722a;
P_0c06722a: /* original 903f, guest PC 0x0c06722a */
if(!s->budget--) { s->failed_pc=0x0c06722au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0672acu,2);
goto P_0c06722c;
P_0c06722c: /* original f846, guest PC 0x0c06722c */
if(!s->budget--) { s->failed_pc=0x0c06722cu; return 0; }
vf3_matrix_load(s,ram,8,r[4]+r[0]);
goto P_0c06722e;
P_0c06722e: /* original f34c, guest PC 0x0c06722e */
if(!s->budget--) { s->failed_pc=0x0c06722eu; return 0; }
vf3_matrix_move(s,3,4);
goto P_0c067230;
P_0c067230: /* original f381, guest PC 0x0c067230 */
if(!s->budget--) { s->failed_pc=0x0c067230u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[8],r[18],'-');
goto P_0c067232;
P_0c067232: /* original f28d, guest PC 0x0c067232 */
if(!s->budget--) { s->failed_pc=0x0c067232u; return 0; }
fr[2]=0;
goto P_0c067234;
P_0c067234: /* original fa9d, guest PC 0x0c067234 */
if(!s->budget--) { s->failed_pc=0x0c067234u; return 0; }
fr[10]=0x3f800000u;
goto P_0c067236;
P_0c067236: /* original f235, guest PC 0x0c067236 */
if(!s->budget--) { s->failed_pc=0x0c067236u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[2])>as_float(fr[3]))!=0);
goto P_0c067238;
P_0c067238: /* original 8d01, guest PC 0x0c067238 */
if(!s->budget--) { s->failed_pc=0x0c067238u; return 0; }
cond=r[17]&1u;
vf3_matrix_store(s,ram,3,r[15]);
if(cond) { goto P_0c06723e; }
goto P_0c06723c;
P_0c06723a: /* original ff3a, guest PC 0x0c06723a */
if(!s->budget--) { s->failed_pc=0x0c06723au; return 0; }
vf3_matrix_store(s,ram,3,r[15]);
goto P_0c06723c;
P_0c06723c: /* original f84c, guest PC 0x0c06723c */
if(!s->budget--) { s->failed_pc=0x0c06723cu; return 0; }
vf3_matrix_move(s,8,4);
goto P_0c06723e;
P_0c06723e: /* original f38c, guest PC 0x0c06723e */
if(!s->budget--) { s->failed_pc=0x0c06723eu; return 0; }
vf3_matrix_move(s,3,8);
goto P_0c067240;
P_0c067240: /* original f3a1, guest PC 0x0c067240 */
if(!s->budget--) { s->failed_pc=0x0c067240u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[10],r[18],'-');
goto P_0c067242;
P_0c067242: /* original f28d, guest PC 0x0c067242 */
if(!s->budget--) { s->failed_pc=0x0c067242u; return 0; }
fr[2]=0;
goto P_0c067244;
P_0c067244: /* original e004, guest PC 0x0c067244 */
if(!s->budget--) { s->failed_pc=0x0c067244u; return 0; }
r[0]=0x00000004u;
goto P_0c067246;
P_0c067246: /* original f235, guest PC 0x0c067246 */
if(!s->budget--) { s->failed_pc=0x0c067246u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[2])>as_float(fr[3]))!=0);
goto P_0c067248;
P_0c067248: /* original 8d02, guest PC 0x0c067248 */
if(!s->budget--) { s->failed_pc=0x0c067248u; return 0; }
cond=r[17]&1u;
vf3_matrix_store(s,ram,3,r[15]+r[0]);
if(cond) { goto P_0c067250; }
goto P_0c06724c;
P_0c06724a: /* original ff37, guest PC 0x0c06724a */
if(!s->budget--) { s->failed_pc=0x0c06724au; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c06724c;
P_0c06724c: /* original a001, guest PC 0x0c06724c */
if(!s->budget--) { s->failed_pc=0x0c06724cu; return 0; }
vf3_matrix_move(s,4,10);
goto P_0c067252;
P_0c06724e: /* original f4ac, guest PC 0x0c06724e */
if(!s->budget--) { s->failed_pc=0x0c06724eu; return 0; }
vf3_matrix_move(s,4,10);
goto P_0c067250;
P_0c067250: /* original f48c, guest PC 0x0c067250 */
if(!s->budget--) { s->failed_pc=0x0c067250u; return 0; }
vf3_matrix_move(s,4,8);
goto P_0c067252;
P_0c067252: /* original e008, guest PC 0x0c067252 */
if(!s->budget--) { s->failed_pc=0x0c067252u; return 0; }
r[0]=0x00000008u;
goto P_0c067254;
P_0c067254: /* original f5b0, guest PC 0x0c067254 */
if(!s->budget--) { s->failed_pc=0x0c067254u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[11],r[18],'+');
goto P_0c067256;
P_0c067256: /* original f3f6, guest PC 0x0c067256 */
if(!s->budget--) { s->failed_pc=0x0c067256u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c067258;
P_0c067258: /* original f690, guest PC 0x0c067258 */
if(!s->budget--) { s->failed_pc=0x0c067258u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[9],r[18],'+');
goto P_0c06725a;
P_0c06725a: /* original 9024, guest PC 0x0c06725a */
if(!s->budget--) { s->failed_pc=0x0c06725au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0672a6u,2);
goto P_0c06725c;
P_0c06725c: /* original 4515, guest PC 0x0c06725c */
if(!s->budget--) { s->failed_pc=0x0c06725cu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[5]>0)!=0);
goto P_0c06725e;
P_0c06725e: /* original f730, guest PC 0x0c06725e */
if(!s->budget--) { s->failed_pc=0x0c06725eu; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[3],r[18],'+');
goto P_0c067260;
P_0c067260: /* original f457, guest PC 0x0c067260 */
if(!s->budget--) { s->failed_pc=0x0c067260u; return 0; }
vf3_matrix_store(s,ram,5,r[4]+r[0]);
goto P_0c067262;
P_0c067262: /* original 7004, guest PC 0x0c067262 */
if(!s->budget--) { s->failed_pc=0x0c067262u; return 0; }
r[0]+=0x00000004u;
goto P_0c067264;
P_0c067264: /* original f477, guest PC 0x0c067264 */
if(!s->budget--) { s->failed_pc=0x0c067264u; return 0; }
vf3_matrix_store(s,ram,7,r[4]+r[0]);
goto P_0c067266;
P_0c067266: /* original 700c, guest PC 0x0c067266 */
if(!s->budget--) { s->failed_pc=0x0c067266u; return 0; }
r[0]+=0x0000000cu;
goto P_0c067268;
P_0c067268: /* original f467, guest PC 0x0c067268 */
if(!s->budget--) { s->failed_pc=0x0c067268u; return 0; }
vf3_matrix_store(s,ram,6,r[4]+r[0]);
goto P_0c06726a;
P_0c06726a: /* original 9020, guest PC 0x0c06726a */
if(!s->budget--) { s->failed_pc=0x0c06726au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0672aeu,2);
goto P_0c06726c;
P_0c06726c: /* original f447, guest PC 0x0c06726c */
if(!s->budget--) { s->failed_pc=0x0c06726cu; return 0; }
vf3_matrix_store(s,ram,4,r[4]+r[0]);
goto P_0c06726e;
P_0c06726e: /* original 7004, guest PC 0x0c06726e */
if(!s->budget--) { s->failed_pc=0x0c06726eu; return 0; }
r[0]+=0x00000004u;
goto P_0c067270;
P_0c067270: /* original 961e, guest PC 0x0c067270 */
if(!s->budget--) { s->failed_pc=0x0c067270u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0672b0u,2);
goto P_0c067272;
P_0c067272: /* original 0464, guest PC 0x0c067272 */
if(!s->budget--) { s->failed_pc=0x0c067272u; return 0; }
write(ram,r[4]+r[0],r[6],1);
goto P_0c067274;
P_0c067274: /* original 7001, guest PC 0x0c067274 */
if(!s->budget--) { s->failed_pc=0x0c067274u; return 0; }
r[0]+=0x00000001u;
goto P_0c067276;
P_0c067276: /* original 0464, guest PC 0x0c067276 */
if(!s->budget--) { s->failed_pc=0x0c067276u; return 0; }
write(ram,r[4]+r[0],r[6],1);
goto P_0c067278;
P_0c067278: /* original 7001, guest PC 0x0c067278 */
if(!s->budget--) { s->failed_pc=0x0c067278u; return 0; }
r[0]+=0x00000001u;
goto P_0c06727a;
P_0c06727a: /* original 8d0c, guest PC 0x0c06727a */
if(!s->budget--) { s->failed_pc=0x0c06727au; return 0; }
cond=r[17]&1u;
write(ram,r[4]+r[0],r[6],1);
if(cond) { goto P_0c067296; }
goto P_0c06727e;
P_0c06727c: /* original 0464, guest PC 0x0c06727c */
if(!s->budget--) { s->failed_pc=0x0c06727cu; return 0; }
write(ram,r[4]+r[0],r[6],1);
goto P_0c06727e;
P_0c06727e: /* original 9018, guest PC 0x0c06727e */
if(!s->budget--) { s->failed_pc=0x0c06727eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0672b2u,2);
goto P_0c067280;
P_0c067280: /* original 064c, guest PC 0x0c067280 */
if(!s->budget--) { s->failed_pc=0x0c067280u; return 0; }
r[6]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c067282;
P_0c067282: /* original 7001, guest PC 0x0c067282 */
if(!s->budget--) { s->failed_pc=0x0c067282u; return 0; }
r[0]+=0x00000001u;
goto P_0c067284;
P_0c067284: /* original 074c, guest PC 0x0c067284 */
if(!s->budget--) { s->failed_pc=0x0c067284u; return 0; }
r[7]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c067286;
P_0c067286: /* original 7001, guest PC 0x0c067286 */
if(!s->budget--) { s->failed_pc=0x0c067286u; return 0; }
r[0]+=0x00000001u;
goto P_0c067288;
P_0c067288: /* original 054c, guest PC 0x0c067288 */
if(!s->budget--) { s->failed_pc=0x0c067288u; return 0; }
r[5]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c06728a;
P_0c06728a: /* original 9013, guest PC 0x0c06728a */
if(!s->budget--) { s->failed_pc=0x0c06728au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0672b4u,2);
goto P_0c06728c;
P_0c06728c: /* original 0464, guest PC 0x0c06728c */
if(!s->budget--) { s->failed_pc=0x0c06728cu; return 0; }
write(ram,r[4]+r[0],r[6],1);
goto P_0c06728e;
P_0c06728e: /* original 7001, guest PC 0x0c06728e */
if(!s->budget--) { s->failed_pc=0x0c06728eu; return 0; }
r[0]+=0x00000001u;
goto P_0c067290;
P_0c067290: /* original 0474, guest PC 0x0c067290 */
if(!s->budget--) { s->failed_pc=0x0c067290u; return 0; }
write(ram,r[4]+r[0],r[7],1);
goto P_0c067292;
P_0c067292: /* original 7001, guest PC 0x0c067292 */
if(!s->budget--) { s->failed_pc=0x0c067292u; return 0; }
r[0]+=0x00000001u;
goto P_0c067294;
P_0c067294: /* original 0454, guest PC 0x0c067294 */
if(!s->budget--) { s->failed_pc=0x0c067294u; return 0; }
write(ram,r[4]+r[0],r[5],1);
goto P_0c067296;
P_0c067296: /* original d309, guest PC 0x0c067296 */
if(!s->budget--) { s->failed_pc=0x0c067296u; return 0; }
r[3]=read(ram,0x0c0672bcu,4);
goto P_0c067298;
P_0c067298: /* original 430b, guest PC 0x0c067298 */
if(!s->budget--) { s->failed_pc=0x0c067298u; return 0; }
target=r[3];
r[16]=0x0c06729cu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c06729cu) { target=s->pc; goto dispatch; }
goto P_0c06729c;
P_0c06729a: /* original 0009, guest PC 0x0c06729a */
if(!s->budget--) { s->failed_pc=0x0c06729au; return 0; }
goto P_0c06729c;
P_0c06729c: /* original 7f0c, guest PC 0x0c06729c */
if(!s->budget--) { s->failed_pc=0x0c06729cu; return 0; }
r[15]+=0x0000000cu;
goto P_0c06729e;
P_0c06729e: /* original 4f26, guest PC 0x0c06729e */
if(!s->budget--) { s->failed_pc=0x0c06729eu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0672a0;
P_0c0672a0: /* original 000b, guest PC 0x0c0672a0 */
if(!s->budget--) { s->failed_pc=0x0c0672a0u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c0672a2: /* original 0009, guest PC 0x0c0672a2 */
if(!s->budget--) { s->failed_pc=0x0c0672a2u; return 0; }
return vf3_matrix_family(0x0c0672a4u,s,ram);
P_0c0672c0: /* original 2fe6, guest PC 0x0c0672c0 */
if(!s->budget--) { s->failed_pc=0x0c0672c0u; return 0; }
r[15]-=4; write(ram,r[15],r[14],4);
goto P_0c0672c2;
P_0c0672c2: /* original 905b, guest PC 0x0c0672c2 */
if(!s->budget--) { s->failed_pc=0x0c0672c2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06737cu,2);
goto P_0c0672c4;
P_0c0672c4: /* original 4f22, guest PC 0x0c0672c4 */
if(!s->budget--) { s->failed_pc=0x0c0672c4u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0672c6;
P_0c0672c6: /* original 054c, guest PC 0x0c0672c6 */
if(!s->budget--) { s->failed_pc=0x0c0672c6u; return 0; }
r[5]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c0672c8;
P_0c0672c8: /* original 655c, guest PC 0x0c0672c8 */
if(!s->budget--) { s->failed_pc=0x0c0672c8u; return 0; }
r[5]=r[5]&255u;
goto P_0c0672ca;
P_0c0672ca: /* original 2558, guest PC 0x0c0672ca */
if(!s->budget--) { s->failed_pc=0x0c0672cau; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[5])==0)!=0);
goto P_0c0672cc;
P_0c0672cc: /* original 893b, guest PC 0x0c0672cc */
if(!s->budget--) { s->failed_pc=0x0c0672ccu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c067346; }
goto P_0c0672ce;
P_0c0672ce: /* original 75ff, guest PC 0x0c0672ce */
if(!s->budget--) { s->failed_pc=0x0c0672ceu; return 0; }
r[5]+=0xffffffffu;
goto P_0c0672d0;
P_0c0672d0: /* original 0454, guest PC 0x0c0672d0 */
if(!s->budget--) { s->failed_pc=0x0c0672d0u; return 0; }
write(ram,r[4]+r[0],r[5],1);
goto P_0c0672d2;
P_0c0672d2: /* original 70ff, guest PC 0x0c0672d2 */
if(!s->budget--) { s->failed_pc=0x0c0672d2u; return 0; }
r[0]+=0xffffffffu;
goto P_0c0672d4;
P_0c0672d4: /* original 064c, guest PC 0x0c0672d4 */
if(!s->budget--) { s->failed_pc=0x0c0672d4u; return 0; }
r[6]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c0672d6;
P_0c0672d6: /* original 606c, guest PC 0x0c0672d6 */
if(!s->budget--) { s->failed_pc=0x0c0672d6u; return 0; }
r[0]=r[6]&255u;
goto P_0c0672d8;
P_0c0672d8: /* original 8802, guest PC 0x0c0672d8 */
if(!s->budget--) { s->failed_pc=0x0c0672d8u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c0672da;
P_0c0672da: /* original 8d0e, guest PC 0x0c0672da */
if(!s->budget--) { s->failed_pc=0x0c0672dau; return 0; }
cond=r[17]&1u;
r[6]=r[0];
if(cond) { goto P_0c0672fa; }
goto P_0c0672de;
P_0c0672dc: /* original 6603, guest PC 0x0c0672dc */
if(!s->budget--) { s->failed_pc=0x0c0672dcu; return 0; }
r[6]=r[0];
goto P_0c0672de;
P_0c0672de: /* original 6063, guest PC 0x0c0672de */
if(!s->budget--) { s->failed_pc=0x0c0672deu; return 0; }
r[0]=r[6];
goto P_0c0672e0;
P_0c0672e0: /* original 8805, guest PC 0x0c0672e0 */
if(!s->budget--) { s->failed_pc=0x0c0672e0u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000005u)!=0);
goto P_0c0672e2;
P_0c0672e2: /* original 890a, guest PC 0x0c0672e2 */
if(!s->budget--) { s->failed_pc=0x0c0672e2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0672fa; }
goto P_0c0672e4;
P_0c0672e4: /* original e61f, guest PC 0x0c0672e4 */
if(!s->budget--) { s->failed_pc=0x0c0672e4u; return 0; }
r[6]=0x0000001fu;
goto P_0c0672e6;
P_0c0672e6: /* original 6363, guest PC 0x0c0672e6 */
if(!s->budget--) { s->failed_pc=0x0c0672e6u; return 0; }
r[3]=r[6];
goto P_0c0672e8;
P_0c0672e8: /* original 3358, guest PC 0x0c0672e8 */
if(!s->budget--) { s->failed_pc=0x0c0672e8u; return 0; }
r[3]-=r[5];
goto P_0c0672ea;
P_0c0672ea: /* original 6033, guest PC 0x0c0672ea */
if(!s->budget--) { s->failed_pc=0x0c0672eau; return 0; }
r[0]=r[3];
goto P_0c0672ec;
P_0c0672ec: /* original 881d, guest PC 0x0c0672ec */
if(!s->budget--) { s->failed_pc=0x0c0672ecu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000001du)!=0);
goto P_0c0672ee;
P_0c0672ee: /* original 8f04, guest PC 0x0c0672ee */
if(!s->budget--) { s->failed_pc=0x0c0672eeu; return 0; }
cond=r[17]&1u;
r[5]=r[3];
if(!cond) { goto P_0c0672fa; }
goto P_0c0672f2;
P_0c0672f0: /* original 6533, guest PC 0x0c0672f0 */
if(!s->budget--) { s->failed_pc=0x0c0672f0u; return 0; }
r[5]=r[3];
goto P_0c0672f2;
P_0c0672f2: /* original 6242, guest PC 0x0c0672f2 */
if(!s->budget--) { s->failed_pc=0x0c0672f2u; return 0; }
tmp=read(ram,r[4],4);
r[2]=tmp;
goto P_0c0672f4;
P_0c0672f4: /* original 9343, guest PC 0x0c0672f4 */
if(!s->budget--) { s->failed_pc=0x0c0672f4u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06737eu,2);
goto P_0c0672f6;
P_0c0672f6: /* original 2239, guest PC 0x0c0672f6 */
if(!s->budget--) { s->failed_pc=0x0c0672f6u; return 0; }
r[2]&=r[3];
goto P_0c0672f8;
P_0c0672f8: /* original 2422, guest PC 0x0c0672f8 */
if(!s->budget--) { s->failed_pc=0x0c0672f8u; return 0; }
write(ram,r[4],r[2],4);
goto P_0c0672fa;
P_0c0672fa: /* original 6753, guest PC 0x0c0672fa */
if(!s->budget--) { s->failed_pc=0x0c0672fau; return 0; }
r[7]=r[5];
goto P_0c0672fc;
P_0c0672fc: /* original 6053, guest PC 0x0c0672fc */
if(!s->budget--) { s->failed_pc=0x0c0672fcu; return 0; }
r[0]=r[5];
goto P_0c0672fe;
P_0c0672fe: /* original 6653, guest PC 0x0c0672fe */
if(!s->budget--) { s->failed_pc=0x0c0672feu; return 0; }
r[6]=r[5];
goto P_0c067300;
P_0c067300: /* original 943e, guest PC 0x0c067300 */
if(!s->budget--) { s->failed_pc=0x0c067300u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c067380u,2);
goto P_0c067302;
P_0c067302: /* original d223, guest PC 0x0c067302 */
if(!s->budget--) { s->failed_pc=0x0c067302u; return 0; }
r[2]=read(ram,0x0c067390u,4);
goto P_0c067304;
P_0c067304: /* original 4008, guest PC 0x0c067304 */
if(!s->budget--) { s->failed_pc=0x0c067304u; return 0; }
r[0]<<=2;
goto P_0c067306;
P_0c067306: /* original 4718, guest PC 0x0c067306 */
if(!s->budget--) { s->failed_pc=0x0c067306u; return 0; }
r[7]<<=8;
goto P_0c067308;
P_0c067308: /* original d320, guest PC 0x0c067308 */
if(!s->budget--) { s->failed_pc=0x0c067308u; return 0; }
r[3]=read(ram,0x0c06738cu,4);
goto P_0c06730a;
P_0c06730a: /* original 4628, guest PC 0x0c06730a */
if(!s->budget--) { s->failed_pc=0x0c06730au; return 0; }
r[6]<<=16;
goto P_0c06730c;
P_0c06730c: /* original de21, guest PC 0x0c06730c */
if(!s->budget--) { s->failed_pc=0x0c06730cu; return 0; }
r[14]=read(ram,0x0c067394u,4);
goto P_0c06730e;
P_0c06730e: /* original 4708, guest PC 0x0c06730e */
if(!s->budget--) { s->failed_pc=0x0c06730eu; return 0; }
r[7]<<=2;
goto P_0c067310;
P_0c067310: /* original 2409, guest PC 0x0c067310 */
if(!s->budget--) { s->failed_pc=0x0c067310u; return 0; }
r[4]&=r[0];
goto P_0c067312;
P_0c067312: /* original 6053, guest PC 0x0c067312 */
if(!s->budget--) { s->failed_pc=0x0c067312u; return 0; }
r[0]=r[5];
goto P_0c067314;
P_0c067314: /* original 4608, guest PC 0x0c067314 */
if(!s->budget--) { s->failed_pc=0x0c067314u; return 0; }
r[6]<<=2;
goto P_0c067316;
P_0c067316: /* original 881f, guest PC 0x0c067316 */
if(!s->budget--) { s->failed_pc=0x0c067316u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000001fu)!=0);
goto P_0c067318;
P_0c067318: /* original 2639, guest PC 0x0c067318 */
if(!s->budget--) { s->failed_pc=0x0c067318u; return 0; }
r[6]&=r[3];
goto P_0c06731a;
P_0c06731a: /* original 2729, guest PC 0x0c06731a */
if(!s->budget--) { s->failed_pc=0x0c06731au; return 0; }
r[7]&=r[2];
goto P_0c06731c;
P_0c06731c: /* original 267b, guest PC 0x0c06731c */
if(!s->budget--) { s->failed_pc=0x0c06731cu; return 0; }
r[6]|=r[7];
goto P_0c06731e;
P_0c06731e: /* original 8f0e, guest PC 0x0c06731e */
if(!s->budget--) { s->failed_pc=0x0c06731eu; return 0; }
cond=r[17]&1u;
r[4]|=r[6];
if(!cond) { goto P_0c06733e; }
goto P_0c067322;
P_0c067320: /* original 246b, guest PC 0x0c067320 */
if(!s->budget--) { s->failed_pc=0x0c067320u; return 0; }
r[4]|=r[6];
goto P_0c067322;
P_0c067322: /* original d31d, guest PC 0x0c067322 */
if(!s->budget--) { s->failed_pc=0x0c067322u; return 0; }
r[3]=read(ram,0x0c067398u,4);
goto P_0c067324;
P_0c067324: /* original 430b, guest PC 0x0c067324 */
if(!s->budget--) { s->failed_pc=0x0c067324u; return 0; }
target=r[3];
r[16]=0x0c067328u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c067328u) { target=s->pc; goto dispatch; }
goto P_0c067328;
P_0c067326: /* original 64e3, guest PC 0x0c067326 */
if(!s->budget--) { s->failed_pc=0x0c067326u; return 0; }
r[4]=r[14];
goto P_0c067328;
P_0c067328: /* original d21b, guest PC 0x0c067328 */
if(!s->budget--) { s->failed_pc=0x0c067328u; return 0; }
r[2]=read(ram,0x0c067398u,4);
goto P_0c06732a;
P_0c06732a: /* original 64e3, guest PC 0x0c06732a */
if(!s->budget--) { s->failed_pc=0x0c06732au; return 0; }
r[4]=r[14];
goto P_0c06732c;
P_0c06732c: /* original 420b, guest PC 0x0c06732c */
if(!s->budget--) { s->failed_pc=0x0c06732cu; return 0; }
target=r[2];
r[16]=0x0c067330u;
r[4]+=0x0000002cu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c067330u) { target=s->pc; goto dispatch; }
goto P_0c067330;
P_0c06732e: /* original 742c, guest PC 0x0c06732e */
if(!s->budget--) { s->failed_pc=0x0c06732eu; return 0; }
r[4]+=0x0000002cu;
goto P_0c067330;
P_0c067330: /* original 9627, guest PC 0x0c067330 */
if(!s->budget--) { s->failed_pc=0x0c067330u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c067382u,2);
goto P_0c067332;
P_0c067332: /* original 9427, guest PC 0x0c067332 */
if(!s->budget--) { s->failed_pc=0x0c067332u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c067384u,2);
goto P_0c067334;
P_0c067334: /* original d319, guest PC 0x0c067334 */
if(!s->budget--) { s->failed_pc=0x0c067334u; return 0; }
r[3]=read(ram,0x0c06739cu,4);
goto P_0c067336;
P_0c067336: /* original 36ec, guest PC 0x0c067336 */
if(!s->budget--) { s->failed_pc=0x0c067336u; return 0; }
r[6]+=r[14];
goto P_0c067338;
P_0c067338: /* original 430b, guest PC 0x0c067338 */
if(!s->budget--) { s->failed_pc=0x0c067338u; return 0; }
target=r[3];
r[16]=0x0c06733cu;
r[5]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c06733cu) { target=s->pc; goto dispatch; }
goto P_0c06733c;
P_0c06733a: /* original 65e3, guest PC 0x0c06733a */
if(!s->budget--) { s->failed_pc=0x0c06733au; return 0; }
r[5]=r[14];
goto P_0c06733c;
P_0c06733c: /* original e400, guest PC 0x0c06733c */
if(!s->budget--) { s->failed_pc=0x0c06733cu; return 0; }
r[4]=0x00000000u;
goto P_0c06733e;
P_0c06733e: /* original 9022, guest PC 0x0c06733e */
if(!s->budget--) { s->failed_pc=0x0c06733eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c067386u,2);
goto P_0c067340;
P_0c067340: /* original 0e46, guest PC 0x0c067340 */
if(!s->budget--) { s->failed_pc=0x0c067340u; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c067342;
P_0c067342: /* original 7004, guest PC 0x0c067342 */
if(!s->budget--) { s->failed_pc=0x0c067342u; return 0; }
r[0]+=0x00000004u;
goto P_0c067344;
P_0c067344: /* original 0e46, guest PC 0x0c067344 */
if(!s->budget--) { s->failed_pc=0x0c067344u; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c067346;
P_0c067346: /* original 4f26, guest PC 0x0c067346 */
if(!s->budget--) { s->failed_pc=0x0c067346u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c067348;
P_0c067348: /* original 000b, guest PC 0x0c067348 */
if(!s->budget--) { s->failed_pc=0x0c067348u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c06734a: /* original 6ef6, guest PC 0x0c06734a */
if(!s->budget--) { s->failed_pc=0x0c06734au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c06734c;
P_0c06734c: /* original 000b, guest PC 0x0c06734c */
if(!s->budget--) { s->failed_pc=0x0c06734cu; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c06734e: /* original 0009, guest PC 0x0c06734e */
if(!s->budget--) { s->failed_pc=0x0c06734eu; return 0; }
goto P_0c067350;
P_0c067350: /* original 901a, guest PC 0x0c067350 */
if(!s->budget--) { s->failed_pc=0x0c067350u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c067388u,2);
goto P_0c067352;
P_0c067352: /* original 034c, guest PC 0x0c067352 */
if(!s->budget--) { s->failed_pc=0x0c067352u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c067354;
P_0c067354: /* original 2338, guest PC 0x0c067354 */
if(!s->budget--) { s->failed_pc=0x0c067354u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c067356;
P_0c067356: /* original 8905, guest PC 0x0c067356 */
if(!s->budget--) { s->failed_pc=0x0c067356u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c067364; }
goto P_0c067358;
P_0c067358: /* original d311, guest PC 0x0c067358 */
if(!s->budget--) { s->failed_pc=0x0c067358u; return 0; }
r[3]=read(ram,0x0c0673a0u,4);
goto P_0c06735a;
P_0c06735a: /* original 014c, guest PC 0x0c06735a */
if(!s->budget--) { s->failed_pc=0x0c06735au; return 0; }
r[1]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c06735c;
P_0c06735c: /* original 6231, guest PC 0x0c06735c */
if(!s->budget--) { s->failed_pc=0x0c06735cu; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[3],2);
r[2]=tmp;
goto P_0c06735e;
P_0c06735e: /* original 611c, guest PC 0x0c06735e */
if(!s->budget--) { s->failed_pc=0x0c06735eu; return 0; }
r[1]=r[1]&255u;
goto P_0c067360;
P_0c067360: /* original 3218, guest PC 0x0c067360 */
if(!s->budget--) { s->failed_pc=0x0c067360u; return 0; }
r[2]-=r[1];
goto P_0c067362;
P_0c067362: /* original 2321, guest PC 0x0c067362 */
if(!s->budget--) { s->failed_pc=0x0c067362u; return 0; }
write(ram,r[3],r[2],2);
goto P_0c067364;
P_0c067364: /* original 000b, guest PC 0x0c067364 */
if(!s->budget--) { s->failed_pc=0x0c067364u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c067366: /* original 0009, guest PC 0x0c067366 */
if(!s->budget--) { s->failed_pc=0x0c067366u; return 0; }
return vf3_matrix_family(0x0c067368u,s,ram);
P_0c0673a8: /* original 4f22, guest PC 0x0c0673a8 */
if(!s->budget--) { s->failed_pc=0x0c0673a8u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0673aa;
P_0c0673aa: /* original 904a, guest PC 0x0c0673aa */
if(!s->budget--) { s->failed_pc=0x0c0673aau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c067442u,2);
goto P_0c0673ac;
P_0c0673ac: /* original 6243, guest PC 0x0c0673ac */
if(!s->budget--) { s->failed_pc=0x0c0673acu; return 0; }
r[2]=r[4];
goto P_0c0673ae;
P_0c0673ae: /* original 9349, guest PC 0x0c0673ae */
if(!s->budget--) { s->failed_pc=0x0c0673aeu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c067444u,2);
goto P_0c0673b0;
P_0c0673b0: /* original 4f12, guest PC 0x0c0673b0 */
if(!s->budget--) { s->failed_pc=0x0c0673b0u; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c0673b2;
P_0c0673b2: /* original 3f0c, guest PC 0x0c0673b2 */
if(!s->budget--) { s->failed_pc=0x0c0673b2u; return 0; }
r[15]+=r[0];
goto P_0c0673b4;
P_0c0673b4: /* original 33fc, guest PC 0x0c0673b4 */
if(!s->budget--) { s->failed_pc=0x0c0673b4u; return 0; }
r[3]+=r[15];
goto P_0c0673b6;
P_0c0673b6: /* original 2342, guest PC 0x0c0673b6 */
if(!s->budget--) { s->failed_pc=0x0c0673b6u; return 0; }
write(ram,r[3],r[4],4);
goto P_0c0673b8;
P_0c0673b8: /* original 9045, guest PC 0x0c0673b8 */
if(!s->budget--) { s->failed_pc=0x0c0673b8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c067446u,2);
goto P_0c0673ba;
P_0c0673ba: /* original 032e, guest PC 0x0c0673ba */
if(!s->budget--) { s->failed_pc=0x0c0673bau; return 0; }
r[3]=read(ram,r[2]+r[0],4);
goto P_0c0673bc;
P_0c0673bc: /* original 9044, guest PC 0x0c0673bc */
if(!s->budget--) { s->failed_pc=0x0c0673bcu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c067448u,2);
goto P_0c0673be;
P_0c0673be: /* original 0f36, guest PC 0x0c0673be */
if(!s->budget--) { s->failed_pc=0x0c0673beu; return 0; }
write(ram,r[15]+r[0],r[3],4);
goto P_0c0673c0;
P_0c0673c0: /* original 9040, guest PC 0x0c0673c0 */
if(!s->budget--) { s->failed_pc=0x0c0673c0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c067444u,2);
goto P_0c0673c2;
P_0c0673c2: /* original 9142, guest PC 0x0c0673c2 */
if(!s->budget--) { s->failed_pc=0x0c0673c2u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06744au,2);
goto P_0c0673c4;
P_0c0673c4: /* original 02fe, guest PC 0x0c0673c4 */
if(!s->budget--) { s->failed_pc=0x0c0673c4u; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c0673c6;
P_0c0673c6: /* original 31fc, guest PC 0x0c0673c6 */
if(!s->budget--) { s->failed_pc=0x0c0673c6u; return 0; }
r[1]+=r[15];
goto P_0c0673c8;
P_0c0673c8: /* original 8523, guest PC 0x0c0673c8 */
if(!s->budget--) { s->failed_pc=0x0c0673c8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[2]+6,2);
goto P_0c0673ca;
P_0c0673ca: /* original 600d, guest PC 0x0c0673ca */
if(!s->budget--) { s->failed_pc=0x0c0673cau; return 0; }
r[0]=r[0]&65535u;
goto P_0c0673cc;
P_0c0673cc: /* original 2102, guest PC 0x0c0673cc */
if(!s->budget--) { s->failed_pc=0x0c0673ccu; return 0; }
write(ram,r[1],r[0],4);
goto P_0c0673ce;
P_0c0673ce: /* original d123, guest PC 0x0c0673ce */
if(!s->budget--) { s->failed_pc=0x0c0673ceu; return 0; }
r[1]=read(ram,0x0c06745cu,4);
goto P_0c0673d0;
P_0c0673d0: /* original e320, guest PC 0x0c0673d0 */
if(!s->budget--) { s->failed_pc=0x0c0673d0u; return 0; }
r[3]=0x00000020u;
goto P_0c0673d2;
P_0c0673d2: /* original 6212, guest PC 0x0c0673d2 */
if(!s->budget--) { s->failed_pc=0x0c0673d2u; return 0; }
tmp=read(ram,r[1],4);
r[2]=tmp;
goto P_0c0673d4;
P_0c0673d4: /* original 3237, guest PC 0x0c0673d4 */
if(!s->budget--) { s->failed_pc=0x0c0673d4u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>(int32_t)r[3])!=0);
goto P_0c0673d6;
P_0c0673d6: /* original 8b74, guest PC 0x0c0673d6 */
if(!s->budget--) { s->failed_pc=0x0c0673d6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0674c2; }
goto P_0c0673d8;
P_0c0673d8: /* original d020, guest PC 0x0c0673d8 */
if(!s->budget--) { s->failed_pc=0x0c0673d8u; return 0; }
r[0]=read(ram,0x0c06745cu,4);
goto P_0c0673da;
P_0c0673da: /* original 6102, guest PC 0x0c0673da */
if(!s->budget--) { s->failed_pc=0x0c0673dau; return 0; }
tmp=read(ram,r[0],4);
r[1]=tmp;
goto P_0c0673dc;
P_0c0673dc: /* original 9036, guest PC 0x0c0673dc */
if(!s->budget--) { s->failed_pc=0x0c0673dcu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06744cu,2);
goto P_0c0673de;
P_0c0673de: /* original 71e0, guest PC 0x0c0673de */
if(!s->budget--) { s->failed_pc=0x0c0673deu; return 0; }
r[1]+=0xffffffe0u;
goto P_0c0673e0;
P_0c0673e0: /* original 0f16, guest PC 0x0c0673e0 */
if(!s->budget--) { s->failed_pc=0x0c0673e0u; return 0; }
write(ram,r[15]+r[0],r[1],4);
goto P_0c0673e2;
P_0c0673e2: /* original d01f, guest PC 0x0c0673e2 */
if(!s->budget--) { s->failed_pc=0x0c0673e2u; return 0; }
r[0]=read(ram,0x0c067460u,4);
goto P_0c0673e4;
P_0c0673e4: /* original 6202, guest PC 0x0c0673e4 */
if(!s->budget--) { s->failed_pc=0x0c0673e4u; return 0; }
tmp=read(ram,r[0],4);
r[2]=tmp;
goto P_0c0673e6;
P_0c0673e6: /* original 9032, guest PC 0x0c0673e6 */
if(!s->budget--) { s->failed_pc=0x0c0673e6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06744eu,2);
goto P_0c0673e8;
P_0c0673e8: /* original 0f26, guest PC 0x0c0673e8 */
if(!s->budget--) { s->failed_pc=0x0c0673e8u; return 0; }
write(ram,r[15]+r[0],r[2],4);
goto P_0c0673ea;
P_0c0673ea: /* original 9031, guest PC 0x0c0673ea */
if(!s->budget--) { s->failed_pc=0x0c0673eau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c067450u,2);
goto P_0c0673ec;
P_0c0673ec: /* original d31d, guest PC 0x0c0673ec */
if(!s->budget--) { s->failed_pc=0x0c0673ecu; return 0; }
r[3]=read(ram,0x0c067464u,4);
goto P_0c0673ee;
P_0c0673ee: /* original 0f36, guest PC 0x0c0673ee */
if(!s->budget--) { s->failed_pc=0x0c0673eeu; return 0; }
write(ram,r[15]+r[0],r[3],4);
goto P_0c0673f0;
P_0c0673f0: /* original 6013, guest PC 0x0c0673f0 */
if(!s->budget--) { s->failed_pc=0x0c0673f0u; return 0; }
r[0]=r[1];
goto P_0c0673f2;
P_0c0673f2: /* original 8806, guest PC 0x0c0673f2 */
if(!s->budget--) { s->failed_pc=0x0c0673f2u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000006u)!=0);
goto P_0c0673f4;
P_0c0673f4: /* original 8938, guest PC 0x0c0673f4 */
if(!s->budget--) { s->failed_pc=0x0c0673f4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c067468; }
goto P_0c0673f6;
P_0c0673f6: /* original e2fd, guest PC 0x0c0673f6 */
if(!s->budget--) { s->failed_pc=0x0c0673f6u; return 0; }
r[2]=0xfffffffdu;
goto P_0c0673f8;
P_0c0673f8: /* original 902b, guest PC 0x0c0673f8 */
if(!s->budget--) { s->failed_pc=0x0c0673f8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c067452u,2);
goto P_0c0673fa;
P_0c0673fa: /* original 0127, guest PC 0x0c0673fa */
if(!s->budget--) { s->failed_pc=0x0c0673fau; return 0; }
r[19]=r[1]*r[2];
goto P_0c0673fc;
P_0c0673fc: /* original 011a, guest PC 0x0c0673fc */
if(!s->budget--) { s->failed_pc=0x0c0673fcu; return 0; }
r[1]=r[19];
goto P_0c0673fe;
P_0c0673fe: /* original 0f16, guest PC 0x0c0673fe */
if(!s->budget--) { s->failed_pc=0x0c0673feu; return 0; }
write(ram,r[15]+r[0],r[1],4);
goto P_0c067400;
P_0c067400: /* original e107, guest PC 0x0c067400 */
if(!s->budget--) { s->failed_pc=0x0c067400u; return 0; }
r[1]=0x00000007u;
goto P_0c067402;
P_0c067402: /* original 9023, guest PC 0x0c067402 */
if(!s->budget--) { s->failed_pc=0x0c067402u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06744cu,2);
goto P_0c067404;
P_0c067404: /* original 03fe, guest PC 0x0c067404 */
if(!s->budget--) { s->failed_pc=0x0c067404u; return 0; }
r[3]=read(ram,r[15]+r[0],4);
goto P_0c067406;
P_0c067406: /* original 9025, guest PC 0x0c067406 */
if(!s->budget--) { s->failed_pc=0x0c067406u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c067454u,2);
goto P_0c067408;
P_0c067408: /* original 6233, guest PC 0x0c067408 */
if(!s->budget--) { s->failed_pc=0x0c067408u; return 0; }
r[2]=r[3];
goto P_0c06740a;
P_0c06740a: /* original 4208, guest PC 0x0c06740a */
if(!s->budget--) { s->failed_pc=0x0c06740au; return 0; }
r[2]<<=2;
goto P_0c06740c;
P_0c06740c: /* original 4300, guest PC 0x0c06740c */
if(!s->budget--) { s->failed_pc=0x0c06740cu; return 0; }
r[17]=(r[17]&~1u)|((r[3]>>31)!=0);
r[3]<<=1;
goto P_0c06740e;
P_0c06740e: /* original 332c, guest PC 0x0c06740e */
if(!s->budget--) { s->failed_pc=0x0c06740eu; return 0; }
r[3]+=r[2];
goto P_0c067410;
P_0c067410: /* original 0f36, guest PC 0x0c067410 */
if(!s->budget--) { s->failed_pc=0x0c067410u; return 0; }
write(ram,r[15]+r[0],r[3],4);
goto P_0c067412;
P_0c067412: /* original 901e, guest PC 0x0c067412 */
if(!s->budget--) { s->failed_pc=0x0c067412u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c067452u,2);
goto P_0c067414;
P_0c067414: /* original 02fe, guest PC 0x0c067414 */
if(!s->budget--) { s->failed_pc=0x0c067414u; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c067416;
P_0c067416: /* original 901c, guest PC 0x0c067416 */
if(!s->budget--) { s->failed_pc=0x0c067416u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c067452u,2);
goto P_0c067418;
P_0c067418: /* original 7218, guest PC 0x0c067418 */
if(!s->budget--) { s->failed_pc=0x0c067418u; return 0; }
r[2]+=0x00000018u;
goto P_0c06741a;
P_0c06741a: /* original 0f26, guest PC 0x0c06741a */
if(!s->budget--) { s->failed_pc=0x0c06741au; return 0; }
write(ram,r[15]+r[0],r[2],4);
goto P_0c06741c;
P_0c06741c: /* original e060, guest PC 0x0c06741c */
if(!s->budget--) { s->failed_pc=0x0c06741cu; return 0; }
r[0]=0x00000060u;
goto P_0c06741e;
P_0c06741e: /* original 421d, guest PC 0x0c06741e */
if(!s->budget--) { s->failed_pc=0x0c06741eu; return 0; }
r[2]=(r[1]&0x80000000u)?((r[1]&31u)?r[2]>>((-r[1])&31u):0):r[2]<<(r[1]&31u);
goto P_0c067420;
P_0c067420: /* original 0f26, guest PC 0x0c067420 */
if(!s->budget--) { s->failed_pc=0x0c067420u; return 0; }
write(ram,r[15]+r[0],r[2],4);
goto P_0c067422;
P_0c067422: /* original 9016, guest PC 0x0c067422 */
if(!s->budget--) { s->failed_pc=0x0c067422u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c067452u,2);
goto P_0c067424;
P_0c067424: /* original 01fe, guest PC 0x0c067424 */
if(!s->budget--) { s->failed_pc=0x0c067424u; return 0; }
r[1]=read(ram,r[15]+r[0],4);
goto P_0c067426;
P_0c067426: /* original 9014, guest PC 0x0c067426 */
if(!s->budget--) { s->failed_pc=0x0c067426u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c067452u,2);
goto P_0c067428;
P_0c067428: /* original 4128, guest PC 0x0c067428 */
if(!s->budget--) { s->failed_pc=0x0c067428u; return 0; }
r[1]<<=16;
goto P_0c06742a;
P_0c06742a: /* original 0f16, guest PC 0x0c06742a */
if(!s->budget--) { s->failed_pc=0x0c06742au; return 0; }
write(ram,r[15]+r[0],r[1],4);
goto P_0c06742c;
P_0c06742c: /* original 231b, guest PC 0x0c06742c */
if(!s->budget--) { s->failed_pc=0x0c06742cu; return 0; }
r[3]|=r[1];
goto P_0c06742e;
P_0c06742e: /* original 9013, guest PC 0x0c06742e */
if(!s->budget--) { s->failed_pc=0x0c06742eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c067458u,2);
goto P_0c067430;
P_0c067430: /* original 9211, guest PC 0x0c067430 */
if(!s->budget--) { s->failed_pc=0x0c067430u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c067456u,2);
goto P_0c067432;
P_0c067432: /* original 232b, guest PC 0x0c067432 */
if(!s->budget--) { s->failed_pc=0x0c067432u; return 0; }
r[3]|=r[2];
goto P_0c067434;
P_0c067434: /* original 0f26, guest PC 0x0c067434 */
if(!s->budget--) { s->failed_pc=0x0c067434u; return 0; }
write(ram,r[15]+r[0],r[2],4);
goto P_0c067436;
P_0c067436: /* original 900c, guest PC 0x0c067436 */
if(!s->budget--) { s->failed_pc=0x0c067436u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c067452u,2);
goto P_0c067438;
P_0c067438: /* original e200, guest PC 0x0c067438 */
if(!s->budget--) { s->failed_pc=0x0c067438u; return 0; }
r[2]=0x00000000u;
goto P_0c06743a;
P_0c06743a: /* original 0f36, guest PC 0x0c06743a */
if(!s->budget--) { s->failed_pc=0x0c06743au; return 0; }
write(ram,r[15]+r[0],r[3],4);
goto P_0c06743c;
P_0c06743c: /* original 900d, guest PC 0x0c06743c */
if(!s->budget--) { s->failed_pc=0x0c06743cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06745au,2);
goto P_0c06743e;
P_0c06743e: /* original a020, guest PC 0x0c06743e */
if(!s->budget--) { s->failed_pc=0x0c06743eu; return 0; }
write(ram,r[15]+r[0],r[2],4);
goto P_0c067482;
P_0c067440: /* original 0f26, guest PC 0x0c067440 */
if(!s->budget--) { s->failed_pc=0x0c067440u; return 0; }
write(ram,r[15]+r[0],r[2],4);
return vf3_matrix_family(0x0c067442u,s,ram);
P_0c067468: /* original e060, guest PC 0x0c067468 */
if(!s->budget--) { s->failed_pc=0x0c067468u; return 0; }
r[0]=0x00000060u;
goto P_0c06746a;
P_0c06746a: /* original e300, guest PC 0x0c06746a */
if(!s->budget--) { s->failed_pc=0x0c06746au; return 0; }
r[3]=0x00000000u;
goto P_0c06746c;
P_0c06746c: /* original 0f36, guest PC 0x0c06746c */
if(!s->budget--) { s->failed_pc=0x0c06746cu; return 0; }
write(ram,r[15]+r[0],r[3],4);
goto P_0c06746e;
P_0c06746e: /* original d329, guest PC 0x0c06746e */
if(!s->budget--) { s->failed_pc=0x0c06746eu; return 0; }
r[3]=read(ram,0x0c067514u,4);
goto P_0c067470;
P_0c067470: /* original 9046, guest PC 0x0c067470 */
if(!s->budget--) { s->failed_pc=0x0c067470u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c067500u,2);
goto P_0c067472;
P_0c067472: /* original 430b, guest PC 0x0c067472 */
if(!s->budget--) { s->failed_pc=0x0c067472u; return 0; }
target=r[3];
r[16]=0x0c067476u;
r[4]=read(ram,r[15]+r[0],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c067476u) { target=s->pc; goto dispatch; }
goto P_0c067476;
P_0c067474: /* original 04fe, guest PC 0x0c067474 */
if(!s->budget--) { s->failed_pc=0x0c067474u; return 0; }
r[4]=read(ram,r[15]+r[0],4);
goto P_0c067476;
P_0c067476: /* original 9044, guest PC 0x0c067476 */
if(!s->budget--) { s->failed_pc=0x0c067476u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c067502u,2);
goto P_0c067478;
P_0c067478: /* original e200, guest PC 0x0c067478 */
if(!s->budget--) { s->failed_pc=0x0c067478u; return 0; }
r[2]=0x00000000u;
goto P_0c06747a;
P_0c06747a: /* original e302, guest PC 0x0c06747a */
if(!s->budget--) { s->failed_pc=0x0c06747au; return 0; }
r[3]=0x00000002u;
goto P_0c06747c;
P_0c06747c: /* original 0f26, guest PC 0x0c06747c */
if(!s->budget--) { s->failed_pc=0x0c06747cu; return 0; }
write(ram,r[15]+r[0],r[2],4);
goto P_0c06747e;
P_0c06747e: /* original 9041, guest PC 0x0c06747e */
if(!s->budget--) { s->failed_pc=0x0c06747eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c067504u,2);
goto P_0c067480;
P_0c067480: /* original 0f36, guest PC 0x0c067480 */
if(!s->budget--) { s->failed_pc=0x0c067480u; return 0; }
write(ram,r[15]+r[0],r[3],4);
goto P_0c067482;
P_0c067482: /* original 913f, guest PC 0x0c067482 */
if(!s->budget--) { s->failed_pc=0x0c067482u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c067504u,2);
goto P_0c067484;
P_0c067484: /* original 31fc, guest PC 0x0c067484 */
if(!s->budget--) { s->failed_pc=0x0c067484u; return 0; }
r[1]+=r[15];
goto P_0c067486;
P_0c067486: /* original 6012, guest PC 0x0c067486 */
if(!s->budget--) { s->failed_pc=0x0c067486u; return 0; }
tmp=read(ram,r[1],4);
r[0]=tmp;
goto P_0c067488;
P_0c067488: /* original cb01, guest PC 0x0c067488 */
if(!s->budget--) { s->failed_pc=0x0c067488u; return 0; }
r[0]|=1u;
goto P_0c06748a;
P_0c06748a: /* original 2f06, guest PC 0x0c06748a */
if(!s->budget--) { s->failed_pc=0x0c06748au; return 0; }
r[15]-=4; write(ram,r[15],r[0],4);
goto P_0c06748c;
P_0c06748c: /* original 9038, guest PC 0x0c06748c */
if(!s->budget--) { s->failed_pc=0x0c06748cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c067500u,2);
goto P_0c06748e;
P_0c06748e: /* original d322, guest PC 0x0c06748e */
if(!s->budget--) { s->failed_pc=0x0c06748eu; return 0; }
r[3]=read(ram,0x0c067518u,4);
goto P_0c067490;
P_0c067490: /* original 07fe, guest PC 0x0c067490 */
if(!s->budget--) { s->failed_pc=0x0c067490u; return 0; }
r[7]=read(ram,r[15]+r[0],4);
goto P_0c067492;
P_0c067492: /* original 9038, guest PC 0x0c067492 */
if(!s->budget--) { s->failed_pc=0x0c067492u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c067506u,2);
goto P_0c067494;
P_0c067494: /* original 06fe, guest PC 0x0c067494 */
if(!s->budget--) { s->failed_pc=0x0c067494u; return 0; }
r[6]=read(ram,r[15]+r[0],4);
goto P_0c067496;
P_0c067496: /* original 9037, guest PC 0x0c067496 */
if(!s->budget--) { s->failed_pc=0x0c067496u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c067508u,2);
goto P_0c067498;
P_0c067498: /* original 05fe, guest PC 0x0c067498 */
if(!s->budget--) { s->failed_pc=0x0c067498u; return 0; }
r[5]=read(ram,r[15]+r[0],4);
goto P_0c06749a;
P_0c06749a: /* original e064, guest PC 0x0c06749a */
if(!s->budget--) { s->failed_pc=0x0c06749au; return 0; }
r[0]=0x00000064u;
goto P_0c06749c;
P_0c06749c: /* original 430b, guest PC 0x0c06749c */
if(!s->budget--) { s->failed_pc=0x0c06749cu; return 0; }
target=r[3];
r[16]=0x0c0674a0u;
r[4]=read(ram,r[15]+r[0],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0674a0u) { target=s->pc; goto dispatch; }
goto P_0c0674a0;
P_0c06749e: /* original 04fe, guest PC 0x0c06749e */
if(!s->budget--) { s->failed_pc=0x0c06749eu; return 0; }
r[4]=read(ram,r[15]+r[0],4);
goto P_0c0674a0;
P_0c0674a0: /* original 9033, guest PC 0x0c0674a0 */
if(!s->budget--) { s->failed_pc=0x0c0674a0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06750au,2);
goto P_0c0674a2;
P_0c0674a2: /* original 7f04, guest PC 0x0c0674a2 */
if(!s->budget--) { s->failed_pc=0x0c0674a2u; return 0; }
r[15]+=0x00000004u;
goto P_0c0674a4;
P_0c0674a4: /* original e327, guest PC 0x0c0674a4 */
if(!s->budget--) { s->failed_pc=0x0c0674a4u; return 0; }
r[3]=0x00000027u;
goto P_0c0674a6;
P_0c0674a6: /* original 02fe, guest PC 0x0c0674a6 */
if(!s->budget--) { s->failed_pc=0x0c0674a6u; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c0674a8;
P_0c0674a8: /* original 902f, guest PC 0x0c0674a8 */
if(!s->budget--) { s->failed_pc=0x0c0674a8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06750au,2);
goto P_0c0674aa;
P_0c0674aa: /* original 7221, guest PC 0x0c0674aa */
if(!s->budget--) { s->failed_pc=0x0c0674aau; return 0; }
r[2]+=0x00000021u;
goto P_0c0674ac;
P_0c0674ac: /* original 3232, guest PC 0x0c0674ac */
if(!s->budget--) { s->failed_pc=0x0c0674acu; return 0; }
r[17]=(r[17]&~1u)|((r[2]>=r[3])!=0);
goto P_0c0674ae;
P_0c0674ae: /* original 8f04, guest PC 0x0c0674ae */
if(!s->budget--) { s->failed_pc=0x0c0674aeu; return 0; }
cond=r[17]&1u;
write(ram,r[15]+r[0],r[2],4);
if(!cond) { goto P_0c0674ba; }
goto P_0c0674b2;
P_0c0674b0: /* original 0f26, guest PC 0x0c0674b0 */
if(!s->budget--) { s->failed_pc=0x0c0674b0u; return 0; }
write(ram,r[15]+r[0],r[2],4);
goto P_0c0674b2;
P_0c0674b2: /* original 912a, guest PC 0x0c0674b2 */
if(!s->budget--) { s->failed_pc=0x0c0674b2u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06750au,2);
goto P_0c0674b4;
P_0c0674b4: /* original e0ff, guest PC 0x0c0674b4 */
if(!s->budget--) { s->failed_pc=0x0c0674b4u; return 0; }
r[0]=0xffffffffu;
goto P_0c0674b6;
P_0c0674b6: /* original 31fc, guest PC 0x0c0674b6 */
if(!s->budget--) { s->failed_pc=0x0c0674b6u; return 0; }
r[1]+=r[15];
goto P_0c0674b8;
P_0c0674b8: /* original 2102, guest PC 0x0c0674b8 */
if(!s->budget--) { s->failed_pc=0x0c0674b8u; return 0; }
write(ram,r[1],r[0],4);
goto P_0c0674ba;
P_0c0674ba: /* original 9026, guest PC 0x0c0674ba */
if(!s->budget--) { s->failed_pc=0x0c0674bau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06750au,2);
goto P_0c0674bc;
P_0c0674bc: /* original d217, guest PC 0x0c0674bc */
if(!s->budget--) { s->failed_pc=0x0c0674bcu; return 0; }
r[2]=read(ram,0x0c06751cu,4);
goto P_0c0674be;
P_0c0674be: /* original 03fe, guest PC 0x0c0674be */
if(!s->budget--) { s->failed_pc=0x0c0674beu; return 0; }
r[3]=read(ram,r[15]+r[0],4);
goto P_0c0674c0;
P_0c0674c0: /* original 2232, guest PC 0x0c0674c0 */
if(!s->budget--) { s->failed_pc=0x0c0674c0u; return 0; }
write(ram,r[2],r[3],4);
goto P_0c0674c2;
P_0c0674c2: /* original 9023, guest PC 0x0c0674c2 */
if(!s->budget--) { s->failed_pc=0x0c0674c2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06750cu,2);
goto P_0c0674c4;
P_0c0674c4: /* original 01fe, guest PC 0x0c0674c4 */
if(!s->budget--) { s->failed_pc=0x0c0674c4u; return 0; }
r[1]=read(ram,r[15]+r[0],4);
goto P_0c0674c6;
P_0c0674c6: /* original 9022, guest PC 0x0c0674c6 */
if(!s->budget--) { s->failed_pc=0x0c0674c6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06750eu,2);
goto P_0c0674c8;
P_0c0674c8: /* original 6311, guest PC 0x0c0674c8 */
if(!s->budget--) { s->failed_pc=0x0c0674c8u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[1],2);
r[3]=tmp;
goto P_0c0674ca;
P_0c0674ca: /* original 633d, guest PC 0x0c0674ca */
if(!s->budget--) { s->failed_pc=0x0c0674cau; return 0; }
r[3]=r[3]&65535u;
goto P_0c0674cc;
P_0c0674cc: /* original 0f36, guest PC 0x0c0674cc */
if(!s->budget--) { s->failed_pc=0x0c0674ccu; return 0; }
write(ram,r[15]+r[0],r[3],4);
goto P_0c0674ce;
P_0c0674ce: /* original 901f, guest PC 0x0c0674ce */
if(!s->budget--) { s->failed_pc=0x0c0674ceu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c067510u,2);
goto P_0c0674d0;
P_0c0674d0: /* original 02fe, guest PC 0x0c0674d0 */
if(!s->budget--) { s->failed_pc=0x0c0674d0u; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c0674d2;
P_0c0674d2: /* original 3232, guest PC 0x0c0674d2 */
if(!s->budget--) { s->failed_pc=0x0c0674d2u; return 0; }
r[17]=(r[17]&~1u)|((r[2]>=r[3])!=0);
goto P_0c0674d4;
P_0c0674d4: /* original 8902, guest PC 0x0c0674d4 */
if(!s->budget--) { s->failed_pc=0x0c0674d4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0674dc; }
goto P_0c0674d6;
P_0c0674d6: /* original d112, guest PC 0x0c0674d6 */
if(!s->budget--) { s->failed_pc=0x0c0674d6u; return 0; }
r[1]=read(ram,0x0c067520u,4);
goto P_0c0674d8;
P_0c0674d8: /* original 412b, guest PC 0x0c0674d8 */
if(!s->budget--) { s->failed_pc=0x0c0674d8u; return 0; }
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
P_0c0674da: /* original 0009, guest PC 0x0c0674da */
if(!s->budget--) { s->failed_pc=0x0c0674dau; return 0; }
goto P_0c0674dc;
P_0c0674dc: /* original 9016, guest PC 0x0c0674dc */
if(!s->budget--) { s->failed_pc=0x0c0674dcu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06750cu,2);
goto P_0c0674de;
P_0c0674de: /* original 9116, guest PC 0x0c0674de */
if(!s->budget--) { s->failed_pc=0x0c0674deu; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06750eu,2);
goto P_0c0674e0;
P_0c0674e0: /* original 03fe, guest PC 0x0c0674e0 */
if(!s->budget--) { s->failed_pc=0x0c0674e0u; return 0; }
r[3]=read(ram,r[15]+r[0],4);
goto P_0c0674e2;
P_0c0674e2: /* original 31fc, guest PC 0x0c0674e2 */
if(!s->budget--) { s->failed_pc=0x0c0674e2u; return 0; }
r[1]+=r[15];
goto P_0c0674e4;
P_0c0674e4: /* original 8432, guest PC 0x0c0674e4 */
if(!s->budget--) { s->failed_pc=0x0c0674e4u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[3]+2,1);
goto P_0c0674e6;
P_0c0674e6: /* original 600c, guest PC 0x0c0674e6 */
if(!s->budget--) { s->failed_pc=0x0c0674e6u; return 0; }
r[0]=r[0]&255u;
goto P_0c0674e8;
P_0c0674e8: /* original 2102, guest PC 0x0c0674e8 */
if(!s->budget--) { s->failed_pc=0x0c0674e8u; return 0; }
write(ram,r[1],r[0],4);
goto P_0c0674ea;
P_0c0674ea: /* original e11f, guest PC 0x0c0674ea */
if(!s->budget--) { s->failed_pc=0x0c0674eau; return 0; }
r[1]=0x0000001fu;
goto P_0c0674ec;
P_0c0674ec: /* original 3012, guest PC 0x0c0674ec */
if(!s->budget--) { s->failed_pc=0x0c0674ecu; return 0; }
r[17]=(r[17]&~1u)|((r[0]>=r[1])!=0);
goto P_0c0674ee;
P_0c0674ee: /* original 8b01, guest PC 0x0c0674ee */
if(!s->budget--) { s->failed_pc=0x0c0674eeu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0674f4; }
goto P_0c0674f0;
P_0c0674f0: /* original a084, guest PC 0x0c0674f0 */
if(!s->budget--) { s->failed_pc=0x0c0674f0u; return 0; }
goto P_0c0675fc;
P_0c0674f2: /* original 0009, guest PC 0x0c0674f2 */
if(!s->budget--) { s->failed_pc=0x0c0674f2u; return 0; }
goto P_0c0674f4;
P_0c0674f4: /* original 4000, guest PC 0x0c0674f4 */
if(!s->budget--) { s->failed_pc=0x0c0674f4u; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c0674f6;
P_0c0674f6: /* original 6103, guest PC 0x0c0674f6 */
if(!s->budget--) { s->failed_pc=0x0c0674f6u; return 0; }
r[1]=r[0];
goto P_0c0674f8;
P_0c0674f8: /* original c70a, guest PC 0x0c0674f8 */
if(!s->budget--) { s->failed_pc=0x0c0674f8u; return 0; }
r[0]=0x0c067524u;
goto P_0c0674fa;
P_0c0674fa: /* original 001d, guest PC 0x0c0674fa */
if(!s->budget--) { s->failed_pc=0x0c0674fau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[1]+r[0],2);
goto P_0c0674fc;
P_0c0674fc: /* original 0023, guest PC 0x0c0674fc */
if(!s->budget--) { s->failed_pc=0x0c0674fcu; return 0; }
target=r[0]+0x0c067500u;
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
P_0c0674fe: /* original 0009, guest PC 0x0c0674fe */
if(!s->budget--) { s->failed_pc=0x0c0674feu; return 0; }
return vf3_matrix_family(0x0c067500u,s,ram);
P_0c067562: /* original a06b, guest PC 0x0c067562 */
if(!s->budget--) { s->failed_pc=0x0c067562u; return 0; }
goto P_0c06763c;
P_0c067564: /* original 0009, guest PC 0x0c067564 */
if(!s->budget--) { s->failed_pc=0x0c067564u; return 0; }
return vf3_matrix_family(0x0c067566u,s,ram);
P_0c06758a: /* original a61f, guest PC 0x0c06758a */
if(!s->budget--) { s->failed_pc=0x0c06758au; return 0; }
goto P_0c0681cc;
P_0c06758c: /* original 0009, guest PC 0x0c06758c */
if(!s->budget--) { s->failed_pc=0x0c06758cu; return 0; }
return vf3_matrix_family(0x0c06758eu,s,ram);
P_0c0675d4: /* original a012, guest PC 0x0c0675d4 */
if(!s->budget--) { s->failed_pc=0x0c0675d4u; return 0; }
goto P_0c0675fc;
P_0c0675d6: /* original 0009, guest PC 0x0c0675d6 */
if(!s->budget--) { s->failed_pc=0x0c0675d6u; return 0; }
return vf3_matrix_family(0x0c0675d8u,s,ram);
P_0c0675de: /* original d214, guest PC 0x0c0675de */
if(!s->budget--) { s->failed_pc=0x0c0675deu; return 0; }
r[2]=read(ram,0x0c067630u,4);
goto P_0c0675e0;
P_0c0675e0: /* original 422b, guest PC 0x0c0675e0 */
if(!s->budget--) { s->failed_pc=0x0c0675e0u; return 0; }
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
P_0c0675e2: /* original 0009, guest PC 0x0c0675e2 */
if(!s->budget--) { s->failed_pc=0x0c0675e2u; return 0; }
goto P_0c0675e4;
P_0c0675e4: /* original a460, guest PC 0x0c0675e4 */
if(!s->budget--) { s->failed_pc=0x0c0675e4u; return 0; }
goto P_0c067ea8;
P_0c0675e6: /* original 0009, guest PC 0x0c0675e6 */
if(!s->budget--) { s->failed_pc=0x0c0675e6u; return 0; }
return vf3_matrix_family(0x0c0675e8u,s,ram);
P_0c0675fc: /* original 9009, guest PC 0x0c0675fc */
if(!s->budget--) { s->failed_pc=0x0c0675fcu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c067612u,2);
goto P_0c0675fe;
P_0c0675fe: /* original 02fe, guest PC 0x0c0675fe */
if(!s->budget--) { s->failed_pc=0x0c0675feu; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c067600;
P_0c067600: /* original 9007, guest PC 0x0c067600 */
if(!s->budget--) { s->failed_pc=0x0c067600u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c067612u,2);
goto P_0c067602;
P_0c067602: /* original 7206, guest PC 0x0c067602 */
if(!s->budget--) { s->failed_pc=0x0c067602u; return 0; }
r[2]+=0x00000006u;
goto P_0c067604;
P_0c067604: /* original 0f26, guest PC 0x0c067604 */
if(!s->budget--) { s->failed_pc=0x0c067604u; return 0; }
write(ram,r[15]+r[0],r[2],4);
goto P_0c067606;
P_0c067606: /* original 9006, guest PC 0x0c067606 */
if(!s->budget--) { s->failed_pc=0x0c067606u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c067616u,2);
goto P_0c067608;
P_0c067608: /* original 03fe, guest PC 0x0c067608 */
if(!s->budget--) { s->failed_pc=0x0c067608u; return 0; }
r[3]=read(ram,r[15]+r[0],4);
goto P_0c06760a;
P_0c06760a: /* original 9005, guest PC 0x0c06760a */
if(!s->budget--) { s->failed_pc=0x0c06760au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c067618u,2);
goto P_0c06760c;
P_0c06760c: /* original 0326, guest PC 0x0c06760c */
if(!s->budget--) { s->failed_pc=0x0c06760cu; return 0; }
write(ram,r[3]+r[0],r[2],4);
goto P_0c06760e;
P_0c06760e: /* original aede, guest PC 0x0c06760e */
if(!s->budget--) { s->failed_pc=0x0c06760eu; return 0; }
goto P_0c0673ce;
P_0c067610: /* original 0009, guest PC 0x0c067610 */
if(!s->budget--) { s->failed_pc=0x0c067610u; return 0; }
return vf3_matrix_family(0x0c067612u,s,ram);
P_0c06763c: /* original 906a, guest PC 0x0c06763c */
if(!s->budget--) { s->failed_pc=0x0c06763cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c067714u,2);
goto P_0c06763e;
P_0c06763e: /* original 01fe, guest PC 0x0c06763e */
if(!s->budget--) { s->failed_pc=0x0c06763eu; return 0; }
r[1]=read(ram,r[15]+r[0],4);
goto P_0c067640;
P_0c067640: /* original 8413, guest PC 0x0c067640 */
if(!s->budget--) { s->failed_pc=0x0c067640u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[1]+3,1);
goto P_0c067642;
P_0c067642: /* original 9168, guest PC 0x0c067642 */
if(!s->budget--) { s->failed_pc=0x0c067642u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c067716u,2);
goto P_0c067644;
P_0c067644: /* original 600c, guest PC 0x0c067644 */
if(!s->budget--) { s->failed_pc=0x0c067644u; return 0; }
r[0]=r[0]&255u;
goto P_0c067646;
P_0c067646: /* original 31fc, guest PC 0x0c067646 */
if(!s->budget--) { s->failed_pc=0x0c067646u; return 0; }
r[1]+=r[15];
goto P_0c067648;
P_0c067648: /* original 2102, guest PC 0x0c067648 */
if(!s->budget--) { s->failed_pc=0x0c067648u; return 0; }
write(ram,r[1],r[0],4);
goto P_0c06764a;
P_0c06764a: /* original 9063, guest PC 0x0c06764a */
if(!s->budget--) { s->failed_pc=0x0c06764au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c067714u,2);
goto P_0c06764c;
P_0c06764c: /* original 9164, guest PC 0x0c06764c */
if(!s->budget--) { s->failed_pc=0x0c06764cu; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c067718u,2);
goto P_0c06764e;
P_0c06764e: /* original 03fe, guest PC 0x0c06764e */
if(!s->budget--) { s->failed_pc=0x0c06764eu; return 0; }
r[3]=read(ram,r[15]+r[0],4);
goto P_0c067650;
P_0c067650: /* original 31fc, guest PC 0x0c067650 */
if(!s->budget--) { s->failed_pc=0x0c067650u; return 0; }
r[1]+=r[15];
goto P_0c067652;
P_0c067652: /* original 8532, guest PC 0x0c067652 */
if(!s->budget--) { s->failed_pc=0x0c067652u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[3]+4,2);
goto P_0c067654;
P_0c067654: /* original 600d, guest PC 0x0c067654 */
if(!s->budget--) { s->failed_pc=0x0c067654u; return 0; }
r[0]=r[0]&65535u;
goto P_0c067656;
P_0c067656: /* original 2102, guest PC 0x0c067656 */
if(!s->budget--) { s->failed_pc=0x0c067656u; return 0; }
write(ram,r[1],r[0],4);
goto P_0c067658;
P_0c067658: /* original 9060, guest PC 0x0c067658 */
if(!s->budget--) { s->failed_pc=0x0c067658u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06771cu,2);
goto P_0c06765a;
P_0c06765a: /* original 935e, guest PC 0x0c06765a */
if(!s->budget--) { s->failed_pc=0x0c06765au; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06771au,2);
goto P_0c06765c;
P_0c06765c: /* original 0f36, guest PC 0x0c06765c */
if(!s->budget--) { s->failed_pc=0x0c06765cu; return 0; }
write(ram,r[15]+r[0],r[3],4);
goto P_0c06765e;
P_0c06765e: /* original 915a, guest PC 0x0c06765e */
if(!s->budget--) { s->failed_pc=0x0c06765eu; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c067716u,2);
goto P_0c067660;
P_0c067660: /* original 31fc, guest PC 0x0c067660 */
if(!s->budget--) { s->failed_pc=0x0c067660u; return 0; }
r[1]+=r[15];
goto P_0c067662;
P_0c067662: /* original 6012, guest PC 0x0c067662 */
if(!s->budget--) { s->failed_pc=0x0c067662u; return 0; }
tmp=read(ram,r[1],4);
r[0]=tmp;
goto P_0c067664;
P_0c067664: /* original c880, guest PC 0x0c067664 */
if(!s->budget--) { s->failed_pc=0x0c067664u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&128u)==0)!=0);
goto P_0c067666;
P_0c067666: /* original 890e, guest PC 0x0c067666 */
if(!s->budget--) { s->failed_pc=0x0c067666u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c067686; }
goto P_0c067668;
P_0c067668: /* original 9059, guest PC 0x0c067668 */
if(!s->budget--) { s->failed_pc=0x0c067668u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06771eu,2);
goto P_0c06766a;
P_0c06766a: /* original 9259, guest PC 0x0c06766a */
if(!s->budget--) { s->failed_pc=0x0c06766au; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c067720u,2);
goto P_0c06766c;
P_0c06766c: /* original 03fe, guest PC 0x0c06766c */
if(!s->budget--) { s->failed_pc=0x0c06766cu; return 0; }
r[3]=read(ram,r[15]+r[0],4);
goto P_0c06766e;
P_0c06766e: /* original 6132, guest PC 0x0c06766e */
if(!s->budget--) { s->failed_pc=0x0c06766eu; return 0; }
tmp=read(ram,r[3],4);
r[1]=tmp;
goto P_0c067670;
P_0c067670: /* original 212b, guest PC 0x0c067670 */
if(!s->budget--) { s->failed_pc=0x0c067670u; return 0; }
r[1]|=r[2];
goto P_0c067672;
P_0c067672: /* original 2312, guest PC 0x0c067672 */
if(!s->budget--) { s->failed_pc=0x0c067672u; return 0; }
write(ram,r[3],r[1],4);
goto P_0c067674;
P_0c067674: /* original e300, guest PC 0x0c067674 */
if(!s->budget--) { s->failed_pc=0x0c067674u; return 0; }
r[3]=0x00000000u;
goto P_0c067676;
P_0c067676: /* original 9051, guest PC 0x0c067676 */
if(!s->budget--) { s->failed_pc=0x0c067676u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06771cu,2);
goto P_0c067678;
P_0c067678: /* original 0f36, guest PC 0x0c067678 */
if(!s->budget--) { s->failed_pc=0x0c067678u; return 0; }
write(ram,r[15]+r[0],r[3],4);
goto P_0c06767a;
P_0c06767a: /* original 904c, guest PC 0x0c06767a */
if(!s->budget--) { s->failed_pc=0x0c06767au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c067716u,2);
goto P_0c06767c;
P_0c06767c: /* original 9351, guest PC 0x0c06767c */
if(!s->budget--) { s->failed_pc=0x0c06767cu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c067722u,2);
goto P_0c06767e;
P_0c06767e: /* original 01fe, guest PC 0x0c06767e */
if(!s->budget--) { s->failed_pc=0x0c06767eu; return 0; }
r[1]=read(ram,r[15]+r[0],4);
goto P_0c067680;
P_0c067680: /* original 9049, guest PC 0x0c067680 */
if(!s->budget--) { s->failed_pc=0x0c067680u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c067716u,2);
goto P_0c067682;
P_0c067682: /* original 2139, guest PC 0x0c067682 */
if(!s->budget--) { s->failed_pc=0x0c067682u; return 0; }
r[1]&=r[3];
goto P_0c067684;
P_0c067684: /* original 0f16, guest PC 0x0c067684 */
if(!s->budget--) { s->failed_pc=0x0c067684u; return 0; }
write(ram,r[15]+r[0],r[1],4);
goto P_0c067686;
P_0c067686: /* original e200, guest PC 0x0c067686 */
if(!s->budget--) { s->failed_pc=0x0c067686u; return 0; }
r[2]=0x00000000u;
goto P_0c067688;
P_0c067688: /* original 1f26, guest PC 0x0c067688 */
if(!s->budget--) { s->failed_pc=0x0c067688u; return 0; }
write(ram,r[15]+24,r[2],4);
goto P_0c06768a;
P_0c06768a: /* original 9044, guest PC 0x0c06768a */
if(!s->budget--) { s->failed_pc=0x0c06768au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c067716u,2);
goto P_0c06768c;
P_0c06768c: /* original 00fe, guest PC 0x0c06768c */
if(!s->budget--) { s->failed_pc=0x0c06768cu; return 0; }
r[0]=read(ram,r[15]+r[0],4);
goto P_0c06768e;
P_0c06768e: /* original 8800, guest PC 0x0c06768e */
if(!s->budget--) { s->failed_pc=0x0c06768eu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000000u)!=0);
goto P_0c067690;
P_0c067690: /* original 891c, guest PC 0x0c067690 */
if(!s->budget--) { s->failed_pc=0x0c067690u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0676cc; }
goto P_0c067692;
P_0c067692: /* original 8801, guest PC 0x0c067692 */
if(!s->budget--) { s->failed_pc=0x0c067692u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c067694;
P_0c067694: /* original 8917, guest PC 0x0c067694 */
if(!s->budget--) { s->failed_pc=0x0c067694u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0676c6; }
goto P_0c067696;
P_0c067696: /* original 8804, guest PC 0x0c067696 */
if(!s->budget--) { s->failed_pc=0x0c067696u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000004u)!=0);
goto P_0c067698;
P_0c067698: /* original 891b, guest PC 0x0c067698 */
if(!s->budget--) { s->failed_pc=0x0c067698u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0676d2; }
goto P_0c06769a;
P_0c06769a: /* original 8806, guest PC 0x0c06769a */
if(!s->budget--) { s->failed_pc=0x0c06769au; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000006u)!=0);
goto P_0c06769c;
P_0c06769c: /* original 891c, guest PC 0x0c06769c */
if(!s->budget--) { s->failed_pc=0x0c06769cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0676d8; }
goto P_0c06769e;
P_0c06769e: /* original 8807, guest PC 0x0c06769e */
if(!s->budget--) { s->failed_pc=0x0c06769eu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000007u)!=0);
goto P_0c0676a0;
P_0c0676a0: /* original 891d, guest PC 0x0c0676a0 */
if(!s->budget--) { s->failed_pc=0x0c0676a0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0676de; }
goto P_0c0676a2;
P_0c0676a2: /* original 8808, guest PC 0x0c0676a2 */
if(!s->budget--) { s->failed_pc=0x0c0676a2u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000008u)!=0);
goto P_0c0676a4;
P_0c0676a4: /* original 891e, guest PC 0x0c0676a4 */
if(!s->budget--) { s->failed_pc=0x0c0676a4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0676e4; }
goto P_0c0676a6;
P_0c0676a6: /* original 8809, guest PC 0x0c0676a6 */
if(!s->budget--) { s->failed_pc=0x0c0676a6u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000009u)!=0);
goto P_0c0676a8;
P_0c0676a8: /* original 8931, guest PC 0x0c0676a8 */
if(!s->budget--) { s->failed_pc=0x0c0676a8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c06770e; }
goto P_0c0676aa;
P_0c0676aa: /* original 880a, guest PC 0x0c0676aa */
if(!s->budget--) { s->failed_pc=0x0c0676aau; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000au)!=0);
goto P_0c0676ac;
P_0c0676ac: /* original 8946, guest PC 0x0c0676ac */
if(!s->budget--) { s->failed_pc=0x0c0676acu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c06773c; }
goto P_0c0676ae;
P_0c0676ae: /* original 880b, guest PC 0x0c0676ae */
if(!s->budget--) { s->failed_pc=0x0c0676aeu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000bu)!=0);
goto P_0c0676b0;
P_0c0676b0: /* original 894f, guest PC 0x0c0676b0 */
if(!s->budget--) { s->failed_pc=0x0c0676b0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c067752; }
goto P_0c0676b2;
P_0c0676b2: /* original 880c, guest PC 0x0c0676b2 */
if(!s->budget--) { s->failed_pc=0x0c0676b2u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000cu)!=0);
goto P_0c0676b4;
P_0c0676b4: /* original 8b01, guest PC 0x0c0676b4 */
if(!s->budget--) { s->failed_pc=0x0c0676b4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0676ba; }
goto P_0c0676b6;
P_0c0676b6: /* original a093, guest PC 0x0c0676b6 */
if(!s->budget--) { s->failed_pc=0x0c0676b6u; return 0; }
goto P_0c0677e0;
P_0c0676b8: /* original 0009, guest PC 0x0c0676b8 */
if(!s->budget--) { s->failed_pc=0x0c0676b8u; return 0; }
goto P_0c0676ba;
P_0c0676ba: /* original 880d, guest PC 0x0c0676ba */
if(!s->budget--) { s->failed_pc=0x0c0676bau; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000du)!=0);
goto P_0c0676bc;
P_0c0676bc: /* original 8b01, guest PC 0x0c0676bc */
if(!s->budget--) { s->failed_pc=0x0c0676bcu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0676c2; }
goto P_0c0676be;
P_0c0676be: /* original a09c, guest PC 0x0c0676be */
if(!s->budget--) { s->failed_pc=0x0c0676beu; return 0; }
goto P_0c0677fa;
P_0c0676c0: /* original 0009, guest PC 0x0c0676c0 */
if(!s->budget--) { s->failed_pc=0x0c0676c0u; return 0; }
goto P_0c0676c2;
P_0c0676c2: /* original a04c, guest PC 0x0c0676c2 */
if(!s->budget--) { s->failed_pc=0x0c0676c2u; return 0; }
goto P_0c06775e;
P_0c0676c4: /* original 0009, guest PC 0x0c0676c4 */
if(!s->budget--) { s->failed_pc=0x0c0676c4u; return 0; }
goto P_0c0676c6;
P_0c0676c6: /* original e301, guest PC 0x0c0676c6 */
if(!s->budget--) { s->failed_pc=0x0c0676c6u; return 0; }
r[3]=0x00000001u;
goto P_0c0676c8;
P_0c0676c8: /* original a0e4, guest PC 0x0c0676c8 */
if(!s->budget--) { s->failed_pc=0x0c0676c8u; return 0; }
write(ram,r[15]+32,r[3],4);
goto P_0c067894;
P_0c0676ca: /* original 1f38, guest PC 0x0c0676ca */
if(!s->budget--) { s->failed_pc=0x0c0676cau; return 0; }
write(ram,r[15]+32,r[3],4);
goto P_0c0676cc;
P_0c0676cc: /* original e101, guest PC 0x0c0676cc */
if(!s->budget--) { s->failed_pc=0x0c0676ccu; return 0; }
r[1]=0x00000001u;
goto P_0c0676ce;
P_0c0676ce: /* original a069, guest PC 0x0c0676ce */
if(!s->budget--) { s->failed_pc=0x0c0676ceu; return 0; }
write(ram,r[15]+28,r[1],4);
goto P_0c0677a4;
P_0c0676d0: /* original 1f17, guest PC 0x0c0676d0 */
if(!s->budget--) { s->failed_pc=0x0c0676d0u; return 0; }
write(ram,r[15]+28,r[1],4);
goto P_0c0676d2;
P_0c0676d2: /* original e201, guest PC 0x0c0676d2 */
if(!s->budget--) { s->failed_pc=0x0c0676d2u; return 0; }
r[2]=0x00000001u;
goto P_0c0676d4;
P_0c0676d4: /* original a070, guest PC 0x0c0676d4 */
if(!s->budget--) { s->failed_pc=0x0c0676d4u; return 0; }
write(ram,r[15]+24,r[2],4);
goto P_0c0677b8;
P_0c0676d6: /* original 1f26, guest PC 0x0c0676d6 */
if(!s->budget--) { s->failed_pc=0x0c0676d6u; return 0; }
write(ram,r[15]+24,r[2],4);
goto P_0c0676d8;
P_0c0676d8: /* original e101, guest PC 0x0c0676d8 */
if(!s->budget--) { s->failed_pc=0x0c0676d8u; return 0; }
r[1]=0x00000001u;
goto P_0c0676da;
P_0c0676da: /* original a0fb, guest PC 0x0c0676da */
if(!s->budget--) { s->failed_pc=0x0c0676dau; return 0; }
write(ram,r[15]+20,r[1],4);
goto P_0c0678d4;
P_0c0676dc: /* original 1f15, guest PC 0x0c0676dc */
if(!s->budget--) { s->failed_pc=0x0c0676dcu; return 0; }
write(ram,r[15]+20,r[1],4);
goto P_0c0676de;
P_0c0676de: /* original e201, guest PC 0x0c0676de */
if(!s->budget--) { s->failed_pc=0x0c0676deu; return 0; }
r[2]=0x00000001u;
goto P_0c0676e0;
P_0c0676e0: /* original a074, guest PC 0x0c0676e0 */
if(!s->budget--) { s->failed_pc=0x0c0676e0u; return 0; }
write(ram,r[15]+16,r[2],4);
goto P_0c0677cc;
P_0c0676e2: /* original 1f24, guest PC 0x0c0676e2 */
if(!s->budget--) { s->failed_pc=0x0c0676e2u; return 0; }
write(ram,r[15]+16,r[2],4);
goto P_0c0676e4;
P_0c0676e4: /* original e101, guest PC 0x0c0676e4 */
if(!s->budget--) { s->failed_pc=0x0c0676e4u; return 0; }
r[1]=0x00000001u;
goto P_0c0676e6;
P_0c0676e6: /* original 1f13, guest PC 0x0c0676e6 */
if(!s->budget--) { s->failed_pc=0x0c0676e6u; return 0; }
write(ram,r[15]+12,r[1],4);
goto P_0c0676e8;
P_0c0676e8: /* original e100, guest PC 0x0c0676e8 */
if(!s->budget--) { s->failed_pc=0x0c0676e8u; return 0; }
r[1]=0x00000000u;
goto P_0c0676ea;
P_0c0676ea: /* original d30f, guest PC 0x0c0676ea */
if(!s->budget--) { s->failed_pc=0x0c0676eau; return 0; }
r[3]=read(ram,0x0c067728u,4);
goto P_0c0676ec;
P_0c0676ec: /* original 6213, guest PC 0x0c0676ec */
if(!s->budget--) { s->failed_pc=0x0c0676ecu; return 0; }
r[2]=r[1];
goto P_0c0676ee;
P_0c0676ee: /* original 2312, guest PC 0x0c0676ee */
if(!s->budget--) { s->failed_pc=0x0c0676eeu; return 0; }
write(ram,r[3],r[1],4);
goto P_0c0676f0;
P_0c0676f0: /* original d00e, guest PC 0x0c0676f0 */
if(!s->budget--) { s->failed_pc=0x0c0676f0u; return 0; }
r[0]=read(ram,0x0c06772cu,4);
goto P_0c0676f2;
P_0c0676f2: /* original 2012, guest PC 0x0c0676f2 */
if(!s->budget--) { s->failed_pc=0x0c0676f2u; return 0; }
write(ram,r[0],r[1],4);
goto P_0c0676f4;
P_0c0676f4: /* original d20e, guest PC 0x0c0676f4 */
if(!s->budget--) { s->failed_pc=0x0c0676f4u; return 0; }
r[2]=read(ram,0x0c067730u,4);
goto P_0c0676f6;
P_0c0676f6: /* original 2212, guest PC 0x0c0676f6 */
if(!s->budget--) { s->failed_pc=0x0c0676f6u; return 0; }
write(ram,r[2],r[1],4);
goto P_0c0676f8;
P_0c0676f8: /* original d30e, guest PC 0x0c0676f8 */
if(!s->budget--) { s->failed_pc=0x0c0676f8u; return 0; }
r[3]=read(ram,0x0c067734u,4);
goto P_0c0676fa;
P_0c0676fa: /* original d00f, guest PC 0x0c0676fa */
if(!s->budget--) { s->failed_pc=0x0c0676fau; return 0; }
r[0]=read(ram,0x0c067738u,4);
goto P_0c0676fc;
P_0c0676fc: /* original 2032, guest PC 0x0c0676fc */
if(!s->budget--) { s->failed_pc=0x0c0676fcu; return 0; }
write(ram,r[0],r[3],4);
goto P_0c0676fe;
P_0c0676fe: /* original 900e, guest PC 0x0c0676fe */
if(!s->budget--) { s->failed_pc=0x0c0676feu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06771eu,2);
goto P_0c067700;
P_0c067700: /* original 9210, guest PC 0x0c067700 */
if(!s->budget--) { s->failed_pc=0x0c067700u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c067724u,2);
goto P_0c067702;
P_0c067702: /* original 03fe, guest PC 0x0c067702 */
if(!s->budget--) { s->failed_pc=0x0c067702u; return 0; }
r[3]=read(ram,r[15]+r[0],4);
goto P_0c067704;
P_0c067704: /* original 6132, guest PC 0x0c067704 */
if(!s->budget--) { s->failed_pc=0x0c067704u; return 0; }
tmp=read(ram,r[3],4);
r[1]=tmp;
goto P_0c067706;
P_0c067706: /* original 2129, guest PC 0x0c067706 */
if(!s->budget--) { s->failed_pc=0x0c067706u; return 0; }
r[1]&=r[2];
goto P_0c067708;
P_0c067708: /* original 2312, guest PC 0x0c067708 */
if(!s->budget--) { s->failed_pc=0x0c067708u; return 0; }
write(ram,r[3],r[1],4);
goto P_0c06770a;
P_0c06770a: /* original af77, guest PC 0x0c06770a */
if(!s->budget--) { s->failed_pc=0x0c06770au; return 0; }
goto P_0c0675fc;
P_0c06770c: /* original 0009, guest PC 0x0c06770c */
if(!s->budget--) { s->failed_pc=0x0c06770cu; return 0; }
goto P_0c06770e;
P_0c06770e: /* original e201, guest PC 0x0c06770e */
if(!s->budget--) { s->failed_pc=0x0c06770eu; return 0; }
r[2]=0x00000001u;
goto P_0c067710;
P_0c067710: /* original a078, guest PC 0x0c067710 */
if(!s->budget--) { s->failed_pc=0x0c067710u; return 0; }
write(ram,r[15]+8,r[2],4);
goto P_0c067804;
P_0c067712: /* original 1f22, guest PC 0x0c067712 */
if(!s->budget--) { s->failed_pc=0x0c067712u; return 0; }
write(ram,r[15]+8,r[2],4);
return vf3_matrix_family(0x0c067714u,s,ram);
P_0c06773c: /* original e021, guest PC 0x0c06773c */
if(!s->budget--) { s->failed_pc=0x0c06773cu; return 0; }
r[0]=0x00000021u;
goto P_0c06773e;
P_0c06773e: /* original e101, guest PC 0x0c06773e */
if(!s->budget--) { s->failed_pc=0x0c06773eu; return 0; }
r[1]=0x00000001u;
goto P_0c067740;
P_0c067740: /* original 1f11, guest PC 0x0c067740 */
if(!s->budget--) { s->failed_pc=0x0c067740u; return 0; }
write(ram,r[15]+4,r[1],4);
goto P_0c067742;
P_0c067742: /* original d345, guest PC 0x0c067742 */
if(!s->budget--) { s->failed_pc=0x0c067742u; return 0; }
r[3]=read(ram,0x0c067858u,4);
goto P_0c067744;
P_0c067744: /* original 2302, guest PC 0x0c067744 */
if(!s->budget--) { s->failed_pc=0x0c067744u; return 0; }
write(ram,r[3],r[0],4);
goto P_0c067746;
P_0c067746: /* original 907c, guest PC 0x0c067746 */
if(!s->budget--) { s->failed_pc=0x0c067746u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c067842u,2);
goto P_0c067748;
P_0c067748: /* original d144, guest PC 0x0c067748 */
if(!s->budget--) { s->failed_pc=0x0c067748u; return 0; }
r[1]=read(ram,0x0c06785cu,4);
goto P_0c06774a;
P_0c06774a: /* original 02fe, guest PC 0x0c06774a */
if(!s->budget--) { s->failed_pc=0x0c06774au; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c06774c;
P_0c06774c: /* original 2122, guest PC 0x0c06774c */
if(!s->budget--) { s->failed_pc=0x0c06774cu; return 0; }
write(ram,r[1],r[2],4);
goto P_0c06774e;
P_0c06774e: /* original af55, guest PC 0x0c06774e */
if(!s->budget--) { s->failed_pc=0x0c06774eu; return 0; }
goto P_0c0675fc;
P_0c067750: /* original 0009, guest PC 0x0c067750 */
if(!s->budget--) { s->failed_pc=0x0c067750u; return 0; }
goto P_0c067752;
P_0c067752: /* original 9077, guest PC 0x0c067752 */
if(!s->budget--) { s->failed_pc=0x0c067752u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c067844u,2);
goto P_0c067754;
P_0c067754: /* original 9277, guest PC 0x0c067754 */
if(!s->budget--) { s->failed_pc=0x0c067754u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c067846u,2);
goto P_0c067756;
P_0c067756: /* original 03fe, guest PC 0x0c067756 */
if(!s->budget--) { s->failed_pc=0x0c067756u; return 0; }
r[3]=read(ram,r[15]+r[0],4);
goto P_0c067758;
P_0c067758: /* original 323c, guest PC 0x0c067758 */
if(!s->budget--) { s->failed_pc=0x0c067758u; return 0; }
r[2]+=r[3];
goto P_0c06775a;
P_0c06775a: /* original a047, guest PC 0x0c06775a */
if(!s->budget--) { s->failed_pc=0x0c06775au; return 0; }
write(ram,r[15],r[2],4);
goto P_0c0677ec;
P_0c06775c: /* original 2f22, guest PC 0x0c06775c */
if(!s->budget--) { s->failed_pc=0x0c06775cu; return 0; }
write(ram,r[15],r[2],4);
goto P_0c06775e;
P_0c06775e: /* original 9073, guest PC 0x0c06775e */
if(!s->budget--) { s->failed_pc=0x0c06775eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c067848u,2);
goto P_0c067760;
P_0c067760: /* original e31f, guest PC 0x0c067760 */
if(!s->budget--) { s->failed_pc=0x0c067760u; return 0; }
r[3]=0x0000001fu;
goto P_0c067762;
P_0c067762: /* original 0f36, guest PC 0x0c067762 */
if(!s->budget--) { s->failed_pc=0x0c067762u; return 0; }
write(ram,r[15]+r[0],r[3],4);
goto P_0c067764;
P_0c067764: /* original 906e, guest PC 0x0c067764 */
if(!s->budget--) { s->failed_pc=0x0c067764u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c067844u,2);
goto P_0c067766;
P_0c067766: /* original 02fe, guest PC 0x0c067766 */
if(!s->budget--) { s->failed_pc=0x0c067766u; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c067768;
P_0c067768: /* original 906f, guest PC 0x0c067768 */
if(!s->budget--) { s->failed_pc=0x0c067768u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06784au,2);
goto P_0c06776a;
P_0c06776a: /* original 03fc, guest PC 0x0c06776a */
if(!s->budget--) { s->failed_pc=0x0c06776au; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[15]+r[0],1);
goto P_0c06776c;
P_0c06776c: /* original 906e, guest PC 0x0c06776c */
if(!s->budget--) { s->failed_pc=0x0c06776cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06784cu,2);
goto P_0c06776e;
P_0c06776e: /* original 0234, guest PC 0x0c06776e */
if(!s->budget--) { s->failed_pc=0x0c06776eu; return 0; }
write(ram,r[2]+r[0],r[3],1);
goto P_0c067770;
P_0c067770: /* original 9068, guest PC 0x0c067770 */
if(!s->budget--) { s->failed_pc=0x0c067770u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c067844u,2);
goto P_0c067772;
P_0c067772: /* original 02fe, guest PC 0x0c067772 */
if(!s->budget--) { s->failed_pc=0x0c067772u; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c067774;
P_0c067774: /* original 9068, guest PC 0x0c067774 */
if(!s->budget--) { s->failed_pc=0x0c067774u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c067848u,2);
goto P_0c067776;
P_0c067776: /* original 03fc, guest PC 0x0c067776 */
if(!s->budget--) { s->failed_pc=0x0c067776u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[15]+r[0],1);
goto P_0c067778;
P_0c067778: /* original 9069, guest PC 0x0c067778 */
if(!s->budget--) { s->failed_pc=0x0c067778u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06784eu,2);
goto P_0c06777a;
P_0c06777a: /* original 0234, guest PC 0x0c06777a */
if(!s->budget--) { s->failed_pc=0x0c06777au; return 0; }
write(ram,r[2]+r[0],r[3],1);
goto P_0c06777c;
P_0c06777c: /* original 9065, guest PC 0x0c06777c */
if(!s->budget--) { s->failed_pc=0x0c06777cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06784au,2);
goto P_0c06777e;
P_0c06777e: /* original 00fe, guest PC 0x0c06777e */
if(!s->budget--) { s->failed_pc=0x0c06777eu; return 0; }
r[0]=read(ram,r[15]+r[0],4);
goto P_0c067780;
P_0c067780: /* original 8803, guest PC 0x0c067780 */
if(!s->budget--) { s->failed_pc=0x0c067780u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000003u)!=0);
goto P_0c067782;
P_0c067782: /* original 8b01, guest PC 0x0c067782 */
if(!s->budget--) { s->failed_pc=0x0c067782u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c067788; }
goto P_0c067784;
P_0c067784: /* original af3a, guest PC 0x0c067784 */
if(!s->budget--) { s->failed_pc=0x0c067784u; return 0; }
goto P_0c0675fc;
P_0c067786: /* original 0009, guest PC 0x0c067786 */
if(!s->budget--) { s->failed_pc=0x0c067786u; return 0; }
goto P_0c067788;
P_0c067788: /* original 905e, guest PC 0x0c067788 */
if(!s->budget--) { s->failed_pc=0x0c067788u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c067848u,2);
goto P_0c06778a;
P_0c06778a: /* original d335, guest PC 0x0c06778a */
if(!s->budget--) { s->failed_pc=0x0c06778au; return 0; }
r[3]=read(ram,0x0c067860u,4);
goto P_0c06778c;
P_0c06778c: /* original 0f36, guest PC 0x0c06778c */
if(!s->budget--) { s->failed_pc=0x0c06778cu; return 0; }
write(ram,r[15]+r[0],r[3],4);
goto P_0c06778e;
P_0c06778e: /* original 6233, guest PC 0x0c06778e */
if(!s->budget--) { s->failed_pc=0x0c06778eu; return 0; }
r[2]=r[3];
goto P_0c067790;
P_0c067790: /* original d134, guest PC 0x0c067790 */
if(!s->budget--) { s->failed_pc=0x0c067790u; return 0; }
r[1]=read(ram,0x0c067864u,4);
goto P_0c067792;
P_0c067792: /* original 2132, guest PC 0x0c067792 */
if(!s->budget--) { s->failed_pc=0x0c067792u; return 0; }
write(ram,r[1],r[3],4);
goto P_0c067794;
P_0c067794: /* original 9058, guest PC 0x0c067794 */
if(!s->budget--) { s->failed_pc=0x0c067794u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c067848u,2);
goto P_0c067796;
P_0c067796: /* original d234, guest PC 0x0c067796 */
if(!s->budget--) { s->failed_pc=0x0c067796u; return 0; }
r[2]=read(ram,0x0c067868u,4);
goto P_0c067798;
P_0c067798: /* original 03fe, guest PC 0x0c067798 */
if(!s->budget--) { s->failed_pc=0x0c067798u; return 0; }
r[3]=read(ram,r[15]+r[0],4);
goto P_0c06779a;
P_0c06779a: /* original 2232, guest PC 0x0c06779a */
if(!s->budget--) { s->failed_pc=0x0c06779au; return 0; }
write(ram,r[2],r[3],4);
goto P_0c06779c;
P_0c06779c: /* original 9055, guest PC 0x0c06779c */
if(!s->budget--) { s->failed_pc=0x0c06779cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06784au,2);
goto P_0c06779e;
P_0c06779e: /* original 00fe, guest PC 0x0c06779e */
if(!s->budget--) { s->failed_pc=0x0c06779eu; return 0; }
r[0]=read(ram,r[15]+r[0],4);
goto P_0c0677a0;
P_0c0677a0: /* original 8805, guest PC 0x0c0677a0 */
if(!s->budget--) { s->failed_pc=0x0c0677a0u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000005u)!=0);
goto P_0c0677a2;
P_0c0677a2: /* original 8909, guest PC 0x0c0677a2 */
if(!s->budget--) { s->failed_pc=0x0c0677a2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0677b8; }
goto P_0c0677a4;
P_0c0677a4: /* original d631, guest PC 0x0c0677a4 */
if(!s->budget--) { s->failed_pc=0x0c0677a4u; return 0; }
r[6]=read(ram,0x0c06786cu,4);
goto P_0c0677a6;
P_0c0677a6: /* original 9053, guest PC 0x0c0677a6 */
if(!s->budget--) { s->failed_pc=0x0c0677a6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c067850u,2);
goto P_0c0677a8;
P_0c0677a8: /* original d331, guest PC 0x0c0677a8 */
if(!s->budget--) { s->failed_pc=0x0c0677a8u; return 0; }
r[3]=read(ram,0x0c067870u,4);
goto P_0c0677aa;
P_0c0677aa: /* original 6563, guest PC 0x0c0677aa */
if(!s->budget--) { s->failed_pc=0x0c0677aau; return 0; }
r[5]=r[6];
goto P_0c0677ac;
P_0c0677ac: /* original 75a8, guest PC 0x0c0677ac */
if(!s->budget--) { s->failed_pc=0x0c0677acu; return 0; }
r[5]+=0xffffffa8u;
goto P_0c0677ae;
P_0c0677ae: /* original 430b, guest PC 0x0c0677ae */
if(!s->budget--) { s->failed_pc=0x0c0677aeu; return 0; }
target=r[3];
r[16]=0x0c0677b2u;
r[4]=read(ram,r[15]+r[0],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0677b2u) { target=s->pc; goto dispatch; }
goto P_0c0677b2;
P_0c0677b0: /* original 04fe, guest PC 0x0c0677b0 */
if(!s->budget--) { s->failed_pc=0x0c0677b0u; return 0; }
r[4]=read(ram,r[15]+r[0],4);
goto P_0c0677b2;
P_0c0677b2: /* original d230, guest PC 0x0c0677b2 */
if(!s->budget--) { s->failed_pc=0x0c0677b2u; return 0; }
r[2]=read(ram,0x0c067874u,4);
goto P_0c0677b4;
P_0c0677b4: /* original a007, guest PC 0x0c0677b4 */
if(!s->budget--) { s->failed_pc=0x0c0677b4u; return 0; }
goto P_0c0677c6;
P_0c0677b6: /* original 0009, guest PC 0x0c0677b6 */
if(!s->budget--) { s->failed_pc=0x0c0677b6u; return 0; }
goto P_0c0677b8;
P_0c0677b8: /* original 904a, guest PC 0x0c0677b8 */
if(!s->budget--) { s->failed_pc=0x0c0677b8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c067850u,2);
goto P_0c0677ba;
P_0c0677ba: /* original d32d, guest PC 0x0c0677ba */
if(!s->budget--) { s->failed_pc=0x0c0677bau; return 0; }
r[3]=read(ram,0x0c067870u,4);
goto P_0c0677bc;
P_0c0677bc: /* original d62b, guest PC 0x0c0677bc */
if(!s->budget--) { s->failed_pc=0x0c0677bcu; return 0; }
r[6]=read(ram,0x0c06786cu,4);
goto P_0c0677be;
P_0c0677be: /* original d52e, guest PC 0x0c0677be */
if(!s->budget--) { s->failed_pc=0x0c0677beu; return 0; }
r[5]=read(ram,0x0c067878u,4);
goto P_0c0677c0;
P_0c0677c0: /* original 430b, guest PC 0x0c0677c0 */
if(!s->budget--) { s->failed_pc=0x0c0677c0u; return 0; }
target=r[3];
r[16]=0x0c0677c4u;
r[4]=read(ram,r[15]+r[0],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0677c4u) { target=s->pc; goto dispatch; }
goto P_0c0677c4;
P_0c0677c2: /* original 04fe, guest PC 0x0c0677c2 */
if(!s->budget--) { s->failed_pc=0x0c0677c2u; return 0; }
r[4]=read(ram,r[15]+r[0],4);
goto P_0c0677c4;
P_0c0677c4: /* original d22c, guest PC 0x0c0677c4 */
if(!s->budget--) { s->failed_pc=0x0c0677c4u; return 0; }
r[2]=read(ram,0x0c067878u,4);
goto P_0c0677c6;
P_0c0677c6: /* original 9044, guest PC 0x0c0677c6 */
if(!s->budget--) { s->failed_pc=0x0c0677c6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c067852u,2);
goto P_0c0677c8;
P_0c0677c8: /* original a027, guest PC 0x0c0677c8 */
if(!s->budget--) { s->failed_pc=0x0c0677c8u; return 0; }
write(ram,r[15]+r[0],r[2],4);
goto P_0c06781a;
P_0c0677ca: /* original 0f26, guest PC 0x0c0677ca */
if(!s->budget--) { s->failed_pc=0x0c0677cau; return 0; }
write(ram,r[15]+r[0],r[2],4);
goto P_0c0677cc;
P_0c0677cc: /* original d322, guest PC 0x0c0677cc */
if(!s->budget--) { s->failed_pc=0x0c0677ccu; return 0; }
r[3]=read(ram,0x0c067858u,4);
goto P_0c0677ce;
P_0c0677ce: /* original e000, guest PC 0x0c0677ce */
if(!s->budget--) { s->failed_pc=0x0c0677ceu; return 0; }
r[0]=0x00000000u;
goto P_0c0677d0;
P_0c0677d0: /* original 2302, guest PC 0x0c0677d0 */
if(!s->budget--) { s->failed_pc=0x0c0677d0u; return 0; }
write(ram,r[3],r[0],4);
goto P_0c0677d2;
P_0c0677d2: /* original 903e, guest PC 0x0c0677d2 */
if(!s->budget--) { s->failed_pc=0x0c0677d2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c067852u,2);
goto P_0c0677d4;
P_0c0677d4: /* original d229, guest PC 0x0c0677d4 */
if(!s->budget--) { s->failed_pc=0x0c0677d4u; return 0; }
r[2]=read(ram,0x0c06787cu,4);
goto P_0c0677d6;
P_0c0677d6: /* original 6123, guest PC 0x0c0677d6 */
if(!s->budget--) { s->failed_pc=0x0c0677d6u; return 0; }
r[1]=r[2];
goto P_0c0677d8;
P_0c0677d8: /* original 0f26, guest PC 0x0c0677d8 */
if(!s->budget--) { s->failed_pc=0x0c0677d8u; return 0; }
write(ram,r[15]+r[0],r[2],4);
goto P_0c0677da;
P_0c0677da: /* original d220, guest PC 0x0c0677da */
if(!s->budget--) { s->failed_pc=0x0c0677dau; return 0; }
r[2]=read(ram,0x0c06785cu,4);
goto P_0c0677dc;
P_0c0677dc: /* original a01d, guest PC 0x0c0677dc */
if(!s->budget--) { s->failed_pc=0x0c0677dcu; return 0; }
write(ram,r[2],r[1],4);
goto P_0c06781a;
P_0c0677de: /* original 2212, guest PC 0x0c0677de */
if(!s->budget--) { s->failed_pc=0x0c0677deu; return 0; }
write(ram,r[2],r[1],4);
goto P_0c0677e0;
P_0c0677e0: /* original 9030, guest PC 0x0c0677e0 */
if(!s->budget--) { s->failed_pc=0x0c0677e0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c067844u,2);
goto P_0c0677e2;
P_0c0677e2: /* original 9330, guest PC 0x0c0677e2 */
if(!s->budget--) { s->failed_pc=0x0c0677e2u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c067846u,2);
goto P_0c0677e4;
P_0c0677e4: /* original 01fe, guest PC 0x0c0677e4 */
if(!s->budget--) { s->failed_pc=0x0c0677e4u; return 0; }
r[1]=read(ram,r[15]+r[0],4);
goto P_0c0677e6;
P_0c0677e6: /* original 331c, guest PC 0x0c0677e6 */
if(!s->budget--) { s->failed_pc=0x0c0677e6u; return 0; }
r[3]+=r[1];
goto P_0c0677e8;
P_0c0677e8: /* original 7304, guest PC 0x0c0677e8 */
if(!s->budget--) { s->failed_pc=0x0c0677e8u; return 0; }
r[3]+=0x00000004u;
goto P_0c0677ea;
P_0c0677ea: /* original 2f32, guest PC 0x0c0677ea */
if(!s->budget--) { s->failed_pc=0x0c0677eau; return 0; }
write(ram,r[15],r[3],4);
goto P_0c0677ec;
P_0c0677ec: /* original 9029, guest PC 0x0c0677ec */
if(!s->budget--) { s->failed_pc=0x0c0677ecu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c067842u,2);
goto P_0c0677ee;
P_0c0677ee: /* original d324, guest PC 0x0c0677ee */
if(!s->budget--) { s->failed_pc=0x0c0677eeu; return 0; }
r[3]=read(ram,0x0c067880u,4);
goto P_0c0677f0;
P_0c0677f0: /* original 05fe, guest PC 0x0c0677f0 */
if(!s->budget--) { s->failed_pc=0x0c0677f0u; return 0; }
r[5]=read(ram,r[15]+r[0],4);
goto P_0c0677f2;
P_0c0677f2: /* original 430b, guest PC 0x0c0677f2 */
if(!s->budget--) { s->failed_pc=0x0c0677f2u; return 0; }
target=r[3];
r[16]=0x0c0677f6u;
tmp=read(ram,r[15],4);
r[4]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0677f6u) { target=s->pc; goto dispatch; }
goto P_0c0677f6;
P_0c0677f4: /* original 64f2, guest PC 0x0c0677f4 */
if(!s->budget--) { s->failed_pc=0x0c0677f4u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c0677f6;
P_0c0677f6: /* original af01, guest PC 0x0c0677f6 */
if(!s->budget--) { s->failed_pc=0x0c0677f6u; return 0; }
goto P_0c0675fc;
P_0c0677f8: /* original 0009, guest PC 0x0c0677f8 */
if(!s->budget--) { s->failed_pc=0x0c0677f8u; return 0; }
goto P_0c0677fa;
P_0c0677fa: /* original d322, guest PC 0x0c0677fa */
if(!s->budget--) { s->failed_pc=0x0c0677fau; return 0; }
r[3]=read(ram,0x0c067884u,4);
goto P_0c0677fc;
P_0c0677fc: /* original 430b, guest PC 0x0c0677fc */
if(!s->budget--) { s->failed_pc=0x0c0677fcu; return 0; }
target=r[3];
r[16]=0x0c067800u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c067800u) { target=s->pc; goto dispatch; }
goto P_0c067800;
P_0c0677fe: /* original 0009, guest PC 0x0c0677fe */
if(!s->budget--) { s->failed_pc=0x0c0677feu; return 0; }
goto P_0c067800;
P_0c067800: /* original aefc, guest PC 0x0c067800 */
if(!s->budget--) { s->failed_pc=0x0c067800u; return 0; }
goto P_0c0675fc;
P_0c067802: /* original 0009, guest PC 0x0c067802 */
if(!s->budget--) { s->failed_pc=0x0c067802u; return 0; }
goto P_0c067804;
P_0c067804: /* original 9025, guest PC 0x0c067804 */
if(!s->budget--) { s->failed_pc=0x0c067804u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c067852u,2);
goto P_0c067806;
P_0c067806: /* original e301, guest PC 0x0c067806 */
if(!s->budget--) { s->failed_pc=0x0c067806u; return 0; }
r[3]=0x00000001u;
goto P_0c067808;
P_0c067808: /* original 6533, guest PC 0x0c067808 */
if(!s->budget--) { s->failed_pc=0x0c067808u; return 0; }
r[5]=r[3];
goto P_0c06780a;
P_0c06780a: /* original e600, guest PC 0x0c06780a */
if(!s->budget--) { s->failed_pc=0x0c06780au; return 0; }
r[6]=0x00000000u;
goto P_0c06780c;
P_0c06780c: /* original 0f36, guest PC 0x0c06780c */
if(!s->budget--) { s->failed_pc=0x0c06780cu; return 0; }
write(ram,r[15]+r[0],r[3],4);
goto P_0c06780e;
P_0c06780e: /* original 9018, guest PC 0x0c06780e */
if(!s->budget--) { s->failed_pc=0x0c06780eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c067842u,2);
goto P_0c067810;
P_0c067810: /* original d31d, guest PC 0x0c067810 */
if(!s->budget--) { s->failed_pc=0x0c067810u; return 0; }
r[3]=read(ram,0x0c067888u,4);
goto P_0c067812;
P_0c067812: /* original 430b, guest PC 0x0c067812 */
if(!s->budget--) { s->failed_pc=0x0c067812u; return 0; }
target=r[3];
r[16]=0x0c067816u;
r[4]=read(ram,r[15]+r[0],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c067816u) { target=s->pc; goto dispatch; }
goto P_0c067816;
P_0c067814: /* original 04fe, guest PC 0x0c067814 */
if(!s->budget--) { s->failed_pc=0x0c067814u; return 0; }
r[4]=read(ram,r[15]+r[0],4);
goto P_0c067816;
P_0c067816: /* original aef1, guest PC 0x0c067816 */
if(!s->budget--) { s->failed_pc=0x0c067816u; return 0; }
goto P_0c0675fc;
P_0c067818: /* original 0009, guest PC 0x0c067818 */
if(!s->budget--) { s->failed_pc=0x0c067818u; return 0; }
goto P_0c06781a;
P_0c06781a: /* original d31c, guest PC 0x0c06781a */
if(!s->budget--) { s->failed_pc=0x0c06781au; return 0; }
r[3]=read(ram,0x0c06788cu,4);
goto P_0c06781c;
P_0c06781c: /* original d417, guest PC 0x0c06781c */
if(!s->budget--) { s->failed_pc=0x0c06781cu; return 0; }
r[4]=read(ram,0x0c06787cu,4);
goto P_0c06781e;
P_0c06781e: /* original 430b, guest PC 0x0c06781e */
if(!s->budget--) { s->failed_pc=0x0c06781eu; return 0; }
target=r[3];
r[16]=0x0c067822u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c067822u) { target=s->pc; goto dispatch; }
goto P_0c067822;
P_0c067820: /* original 0009, guest PC 0x0c067820 */
if(!s->budget--) { s->failed_pc=0x0c067820u; return 0; }
goto P_0c067822;
P_0c067822: /* original e060, guest PC 0x0c067822 */
if(!s->budget--) { s->failed_pc=0x0c067822u; return 0; }
r[0]=0x00000060u;
goto P_0c067824;
P_0c067824: /* original e200, guest PC 0x0c067824 */
if(!s->budget--) { s->failed_pc=0x0c067824u; return 0; }
r[2]=0x00000000u;
goto P_0c067826;
P_0c067826: /* original 0f26, guest PC 0x0c067826 */
if(!s->budget--) { s->failed_pc=0x0c067826u; return 0; }
write(ram,r[15]+r[0],r[2],4);
goto P_0c067828;
P_0c067828: /* original e303, guest PC 0x0c067828 */
if(!s->budget--) { s->failed_pc=0x0c067828u; return 0; }
r[3]=0x00000003u;
goto P_0c06782a;
P_0c06782a: /* original 2f36, guest PC 0x0c06782a */
if(!s->budget--) { s->failed_pc=0x0c06782au; return 0; }
r[15]-=4; write(ram,r[15],r[3],4);
goto P_0c06782c;
P_0c06782c: /* original 6723, guest PC 0x0c06782c */
if(!s->budget--) { s->failed_pc=0x0c06782cu; return 0; }
r[7]=r[2];
goto P_0c06782e;
P_0c06782e: /* original 9008, guest PC 0x0c06782e */
if(!s->budget--) { s->failed_pc=0x0c06782eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c067842u,2);
goto P_0c067830;
P_0c067830: /* original d217, guest PC 0x0c067830 */
if(!s->budget--) { s->failed_pc=0x0c067830u; return 0; }
r[2]=read(ram,0x0c067890u,4);
goto P_0c067832;
P_0c067832: /* original 06fe, guest PC 0x0c067832 */
if(!s->budget--) { s->failed_pc=0x0c067832u; return 0; }
r[6]=read(ram,r[15]+r[0],4);
goto P_0c067834;
P_0c067834: /* original 900e, guest PC 0x0c067834 */
if(!s->budget--) { s->failed_pc=0x0c067834u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c067854u,2);
goto P_0c067836;
P_0c067836: /* original 05fe, guest PC 0x0c067836 */
if(!s->budget--) { s->failed_pc=0x0c067836u; return 0; }
r[5]=read(ram,r[15]+r[0],4);
goto P_0c067838;
P_0c067838: /* original e064, guest PC 0x0c067838 */
if(!s->budget--) { s->failed_pc=0x0c067838u; return 0; }
r[0]=0x00000064u;
goto P_0c06783a;
P_0c06783a: /* original 420b, guest PC 0x0c06783a */
if(!s->budget--) { s->failed_pc=0x0c06783au; return 0; }
target=r[2];
r[16]=0x0c06783eu;
r[4]=read(ram,r[15]+r[0],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c06783eu) { target=s->pc; goto dispatch; }
goto P_0c06783e;
P_0c06783c: /* original 04fe, guest PC 0x0c06783c */
if(!s->budget--) { s->failed_pc=0x0c06783cu; return 0; }
r[4]=read(ram,r[15]+r[0],4);
goto P_0c06783e;
P_0c06783e: /* original a6ce, guest PC 0x0c06783e */
if(!s->budget--) { s->failed_pc=0x0c06783eu; return 0; }
goto P_0c0685de;
P_0c067840: /* original 0009, guest PC 0x0c067840 */
if(!s->budget--) { s->failed_pc=0x0c067840u; return 0; }
return vf3_matrix_family(0x0c067842u,s,ram);
P_0c067894: /* original 9030, guest PC 0x0c067894 */
if(!s->budget--) { s->failed_pc=0x0c067894u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0678f8u,2);
goto P_0c067896;
P_0c067896: /* original e200, guest PC 0x0c067896 */
if(!s->budget--) { s->failed_pc=0x0c067896u; return 0; }
r[2]=0x00000000u;
goto P_0c067898;
P_0c067898: /* original 6323, guest PC 0x0c067898 */
if(!s->budget--) { s->failed_pc=0x0c067898u; return 0; }
r[3]=r[2];
goto P_0c06789a;
P_0c06789a: /* original 0f26, guest PC 0x0c06789a */
if(!s->budget--) { s->failed_pc=0x0c06789au; return 0; }
write(ram,r[15]+r[0],r[2],4);
goto P_0c06789c;
P_0c06789c: /* original d11a, guest PC 0x0c06789c */
if(!s->budget--) { s->failed_pc=0x0c06789cu; return 0; }
r[1]=read(ram,0x0c067908u,4);
goto P_0c06789e;
P_0c06789e: /* original 2122, guest PC 0x0c06789e */
if(!s->budget--) { s->failed_pc=0x0c06789eu; return 0; }
write(ram,r[1],r[2],4);
goto P_0c0678a0;
P_0c0678a0: /* original 902a, guest PC 0x0c0678a0 */
if(!s->budget--) { s->failed_pc=0x0c0678a0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0678f8u,2);
goto P_0c0678a2;
P_0c0678a2: /* original d31a, guest PC 0x0c0678a2 */
if(!s->budget--) { s->failed_pc=0x0c0678a2u; return 0; }
r[3]=read(ram,0x0c06790cu,4);
goto P_0c0678a4;
P_0c0678a4: /* original 02fe, guest PC 0x0c0678a4 */
if(!s->budget--) { s->failed_pc=0x0c0678a4u; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c0678a6;
P_0c0678a6: /* original 2322, guest PC 0x0c0678a6 */
if(!s->budget--) { s->failed_pc=0x0c0678a6u; return 0; }
write(ram,r[3],r[2],4);
goto P_0c0678a8;
P_0c0678a8: /* original d21a, guest PC 0x0c0678a8 */
if(!s->budget--) { s->failed_pc=0x0c0678a8u; return 0; }
r[2]=read(ram,0x0c067914u,4);
goto P_0c0678aa;
P_0c0678aa: /* original d419, guest PC 0x0c0678aa */
if(!s->budget--) { s->failed_pc=0x0c0678aau; return 0; }
r[4]=read(ram,0x0c067910u,4);
goto P_0c0678ac;
P_0c0678ac: /* original 420b, guest PC 0x0c0678ac */
if(!s->budget--) { s->failed_pc=0x0c0678acu; return 0; }
target=r[2];
r[16]=0x0c0678b0u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0678b0u) { target=s->pc; goto dispatch; }
goto P_0c0678b0;
P_0c0678ae: /* original 0009, guest PC 0x0c0678ae */
if(!s->budget--) { s->failed_pc=0x0c0678aeu; return 0; }
goto P_0c0678b0;
P_0c0678b0: /* original d318, guest PC 0x0c0678b0 */
if(!s->budget--) { s->failed_pc=0x0c0678b0u; return 0; }
r[3]=read(ram,0x0c067914u,4);
goto P_0c0678b2;
P_0c0678b2: /* original d419, guest PC 0x0c0678b2 */
if(!s->budget--) { s->failed_pc=0x0c0678b2u; return 0; }
r[4]=read(ram,0x0c067918u,4);
goto P_0c0678b4;
P_0c0678b4: /* original 430b, guest PC 0x0c0678b4 */
if(!s->budget--) { s->failed_pc=0x0c0678b4u; return 0; }
target=r[3];
r[16]=0x0c0678b8u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0678b8u) { target=s->pc; goto dispatch; }
goto P_0c0678b8;
P_0c0678b6: /* original 0009, guest PC 0x0c0678b6 */
if(!s->budget--) { s->failed_pc=0x0c0678b6u; return 0; }
goto P_0c0678b8;
P_0c0678b8: /* original 941f, guest PC 0x0c0678b8 */
if(!s->budget--) { s->failed_pc=0x0c0678b8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0678fau,2);
goto P_0c0678ba;
P_0c0678ba: /* original d219, guest PC 0x0c0678ba */
if(!s->budget--) { s->failed_pc=0x0c0678bau; return 0; }
r[2]=read(ram,0x0c067920u,4);
goto P_0c0678bc;
P_0c0678bc: /* original d617, guest PC 0x0c0678bc */
if(!s->budget--) { s->failed_pc=0x0c0678bcu; return 0; }
r[6]=read(ram,0x0c06791cu,4);
goto P_0c0678be;
P_0c0678be: /* original d514, guest PC 0x0c0678be */
if(!s->budget--) { s->failed_pc=0x0c0678beu; return 0; }
r[5]=read(ram,0x0c067910u,4);
goto P_0c0678c0;
P_0c0678c0: /* original 420b, guest PC 0x0c0678c0 */
if(!s->budget--) { s->failed_pc=0x0c0678c0u; return 0; }
target=r[2];
r[16]=0x0c0678c4u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0678c4u) { target=s->pc; goto dispatch; }
goto P_0c0678c4;
P_0c0678c2: /* original 0009, guest PC 0x0c0678c2 */
if(!s->budget--) { s->failed_pc=0x0c0678c2u; return 0; }
goto P_0c0678c4;
P_0c0678c4: /* original 901a, guest PC 0x0c0678c4 */
if(!s->budget--) { s->failed_pc=0x0c0678c4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0678fcu,2);
goto P_0c0678c6;
P_0c0678c6: /* original 921a, guest PC 0x0c0678c6 */
if(!s->budget--) { s->failed_pc=0x0c0678c6u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0678feu,2);
goto P_0c0678c8;
P_0c0678c8: /* original 03fe, guest PC 0x0c0678c8 */
if(!s->budget--) { s->failed_pc=0x0c0678c8u; return 0; }
r[3]=read(ram,r[15]+r[0],4);
goto P_0c0678ca;
P_0c0678ca: /* original 6132, guest PC 0x0c0678ca */
if(!s->budget--) { s->failed_pc=0x0c0678cau; return 0; }
tmp=read(ram,r[3],4);
r[1]=tmp;
goto P_0c0678cc;
P_0c0678cc: /* original 2129, guest PC 0x0c0678cc */
if(!s->budget--) { s->failed_pc=0x0c0678ccu; return 0; }
r[1]&=r[2];
goto P_0c0678ce;
P_0c0678ce: /* original 2312, guest PC 0x0c0678ce */
if(!s->budget--) { s->failed_pc=0x0c0678ceu; return 0; }
write(ram,r[3],r[1],4);
goto P_0c0678d0;
P_0c0678d0: /* original ae94, guest PC 0x0c0678d0 */
if(!s->budget--) { s->failed_pc=0x0c0678d0u; return 0; }
goto P_0c0675fc;
P_0c0678d2: /* original 0009, guest PC 0x0c0678d2 */
if(!s->budget--) { s->failed_pc=0x0c0678d2u; return 0; }
goto P_0c0678d4;
P_0c0678d4: /* original 9315, guest PC 0x0c0678d4 */
if(!s->budget--) { s->failed_pc=0x0c0678d4u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c067902u,2);
goto P_0c0678d6;
P_0c0678d6: /* original 9013, guest PC 0x0c0678d6 */
if(!s->budget--) { s->failed_pc=0x0c0678d6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c067900u,2);
goto P_0c0678d8;
P_0c0678d8: /* original 33fc, guest PC 0x0c0678d8 */
if(!s->budget--) { s->failed_pc=0x0c0678d8u; return 0; }
r[3]+=r[15];
goto P_0c0678da;
P_0c0678da: /* original 2302, guest PC 0x0c0678da */
if(!s->budget--) { s->failed_pc=0x0c0678dau; return 0; }
write(ram,r[3],r[0],4);
goto P_0c0678dc;
P_0c0678dc: /* original 900e, guest PC 0x0c0678dc */
if(!s->budget--) { s->failed_pc=0x0c0678dcu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0678fcu,2);
goto P_0c0678de;
P_0c0678de: /* original 02fe, guest PC 0x0c0678de */
if(!s->budget--) { s->failed_pc=0x0c0678deu; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c0678e0;
P_0c0678e0: /* original 900f, guest PC 0x0c0678e0 */
if(!s->budget--) { s->failed_pc=0x0c0678e0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c067902u,2);
goto P_0c0678e2;
P_0c0678e2: /* original 03fd, guest PC 0x0c0678e2 */
if(!s->budget--) { s->failed_pc=0x0c0678e2u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+r[0],2);
goto P_0c0678e4;
P_0c0678e4: /* original 900e, guest PC 0x0c0678e4 */
if(!s->budget--) { s->failed_pc=0x0c0678e4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c067904u,2);
goto P_0c0678e6;
P_0c0678e6: /* original 0235, guest PC 0x0c0678e6 */
if(!s->budget--) { s->failed_pc=0x0c0678e6u; return 0; }
write(ram,r[2]+r[0],r[3],2);
goto P_0c0678e8;
P_0c0678e8: /* original 9008, guest PC 0x0c0678e8 */
if(!s->budget--) { s->failed_pc=0x0c0678e8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0678fcu,2);
goto P_0c0678ea;
P_0c0678ea: /* original 02fe, guest PC 0x0c0678ea */
if(!s->budget--) { s->failed_pc=0x0c0678eau; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c0678ec;
P_0c0678ec: /* original 9009, guest PC 0x0c0678ec */
if(!s->budget--) { s->failed_pc=0x0c0678ecu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c067902u,2);
goto P_0c0678ee;
P_0c0678ee: /* original 03fd, guest PC 0x0c0678ee */
if(!s->budget--) { s->failed_pc=0x0c0678eeu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+r[0],2);
goto P_0c0678f0;
P_0c0678f0: /* original 9009, guest PC 0x0c0678f0 */
if(!s->budget--) { s->failed_pc=0x0c0678f0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c067906u,2);
goto P_0c0678f2;
P_0c0678f2: /* original 0235, guest PC 0x0c0678f2 */
if(!s->budget--) { s->failed_pc=0x0c0678f2u; return 0; }
write(ram,r[2]+r[0],r[3],2);
goto P_0c0678f4;
P_0c0678f4: /* original ae82, guest PC 0x0c0678f4 */
if(!s->budget--) { s->failed_pc=0x0c0678f4u; return 0; }
goto P_0c0675fc;
P_0c0678f6: /* original 0009, guest PC 0x0c0678f6 */
if(!s->budget--) { s->failed_pc=0x0c0678f6u; return 0; }
return vf3_matrix_family(0x0c0678f8u,s,ram);
P_0c067ea8: /* original 905d, guest PC 0x0c067ea8 */
if(!s->budget--) { s->failed_pc=0x0c067ea8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c067f66u,2);
goto P_0c067eaa;
P_0c067eaa: /* original 01fe, guest PC 0x0c067eaa */
if(!s->budget--) { s->failed_pc=0x0c067eaau; return 0; }
r[1]=read(ram,r[15]+r[0],4);
goto P_0c067eac;
P_0c067eac: /* original 8512, guest PC 0x0c067eac */
if(!s->budget--) { s->failed_pc=0x0c067eacu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[1]+4,2);
goto P_0c067eae;
P_0c067eae: /* original 915b, guest PC 0x0c067eae */
if(!s->budget--) { s->failed_pc=0x0c067eaeu; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c067f68u,2);
goto P_0c067eb0;
P_0c067eb0: /* original 600d, guest PC 0x0c067eb0 */
if(!s->budget--) { s->failed_pc=0x0c067eb0u; return 0; }
r[0]=r[0]&65535u;
goto P_0c067eb2;
P_0c067eb2: /* original 31fc, guest PC 0x0c067eb2 */
if(!s->budget--) { s->failed_pc=0x0c067eb2u; return 0; }
r[1]+=r[15];
goto P_0c067eb4;
P_0c067eb4: /* original 2102, guest PC 0x0c067eb4 */
if(!s->budget--) { s->failed_pc=0x0c067eb4u; return 0; }
write(ram,r[1],r[0],4);
goto P_0c067eb6;
P_0c067eb6: /* original 9056, guest PC 0x0c067eb6 */
if(!s->budget--) { s->failed_pc=0x0c067eb6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c067f66u,2);
goto P_0c067eb8;
P_0c067eb8: /* original 9149, guest PC 0x0c067eb8 */
if(!s->budget--) { s->failed_pc=0x0c067eb8u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c067f4eu,2);
goto P_0c067eba;
P_0c067eba: /* original 03fe, guest PC 0x0c067eba */
if(!s->budget--) { s->failed_pc=0x0c067ebau; return 0; }
r[3]=read(ram,r[15]+r[0],4);
goto P_0c067ebc;
P_0c067ebc: /* original 31fc, guest PC 0x0c067ebc */
if(!s->budget--) { s->failed_pc=0x0c067ebcu; return 0; }
r[1]+=r[15];
goto P_0c067ebe;
P_0c067ebe: /* original 8433, guest PC 0x0c067ebe */
if(!s->budget--) { s->failed_pc=0x0c067ebeu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[3]+3,1);
goto P_0c067ec0;
P_0c067ec0: /* original 600c, guest PC 0x0c067ec0 */
if(!s->budget--) { s->failed_pc=0x0c067ec0u; return 0; }
r[0]=r[0]&255u;
goto P_0c067ec2;
P_0c067ec2: /* original 2102, guest PC 0x0c067ec2 */
if(!s->budget--) { s->failed_pc=0x0c067ec2u; return 0; }
write(ram,r[1],r[0],4);
goto P_0c067ec4;
P_0c067ec4: /* original d22b, guest PC 0x0c067ec4 */
if(!s->budget--) { s->failed_pc=0x0c067ec4u; return 0; }
r[2]=read(ram,0x0c067f74u,4);
goto P_0c067ec6;
P_0c067ec6: /* original 6322, guest PC 0x0c067ec6 */
if(!s->budget--) { s->failed_pc=0x0c067ec6u; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c067ec8;
P_0c067ec8: /* original 1f3f, guest PC 0x0c067ec8 */
if(!s->budget--) { s->failed_pc=0x0c067ec8u; return 0; }
write(ram,r[15]+60,r[3],4);
goto P_0c067eca;
P_0c067eca: /* original 9040, guest PC 0x0c067eca */
if(!s->budget--) { s->failed_pc=0x0c067ecau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c067f4eu,2);
goto P_0c067ecc;
P_0c067ecc: /* original 01fe, guest PC 0x0c067ecc */
if(!s->budget--) { s->failed_pc=0x0c067eccu; return 0; }
r[1]=read(ram,r[15]+r[0],4);
goto P_0c067ece;
P_0c067ece: /* original 2118, guest PC 0x0c067ece */
if(!s->budget--) { s->failed_pc=0x0c067eceu; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[1])==0)!=0);
goto P_0c067ed0;
P_0c067ed0: /* original 8b02, guest PC 0x0c067ed0 */
if(!s->budget--) { s->failed_pc=0x0c067ed0u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c067ed8; }
goto P_0c067ed2;
P_0c067ed2: /* original d129, guest PC 0x0c067ed2 */
if(!s->budget--) { s->failed_pc=0x0c067ed2u; return 0; }
r[1]=read(ram,0x0c067f78u,4);
goto P_0c067ed4;
P_0c067ed4: /* original 6312, guest PC 0x0c067ed4 */
if(!s->budget--) { s->failed_pc=0x0c067ed4u; return 0; }
tmp=read(ram,r[1],4);
r[3]=tmp;
goto P_0c067ed6;
P_0c067ed6: /* original 1f3f, guest PC 0x0c067ed6 */
if(!s->budget--) { s->failed_pc=0x0c067ed6u; return 0; }
write(ram,r[15]+60,r[3],4);
goto P_0c067ed8;
P_0c067ed8: /* original 9046, guest PC 0x0c067ed8 */
if(!s->budget--) { s->failed_pc=0x0c067ed8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c067f68u,2);
goto P_0c067eda;
P_0c067eda: /* original 52ff, guest PC 0x0c067eda */
if(!s->budget--) { s->failed_pc=0x0c067edau; return 0; }
r[2]=read(ram,r[15]+60,4);
goto P_0c067edc;
P_0c067edc: /* original 03fc, guest PC 0x0c067edc */
if(!s->budget--) { s->failed_pc=0x0c067edcu; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[15]+r[0],1);
goto P_0c067ede;
P_0c067ede: /* original 9044, guest PC 0x0c067ede */
if(!s->budget--) { s->failed_pc=0x0c067edeu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c067f6au,2);
goto P_0c067ee0;
P_0c067ee0: /* original 0234, guest PC 0x0c067ee0 */
if(!s->budget--) { s->failed_pc=0x0c067ee0u; return 0; }
write(ram,r[2]+r[0],r[3],1);
goto P_0c067ee2;
P_0c067ee2: /* original 9041, guest PC 0x0c067ee2 */
if(!s->budget--) { s->failed_pc=0x0c067ee2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c067f68u,2);
goto P_0c067ee4;
P_0c067ee4: /* original d325, guest PC 0x0c067ee4 */
if(!s->budget--) { s->failed_pc=0x0c067ee4u; return 0; }
r[3]=read(ram,0x0c067f7cu,4);
goto P_0c067ee6;
P_0c067ee6: /* original 05fe, guest PC 0x0c067ee6 */
if(!s->budget--) { s->failed_pc=0x0c067ee6u; return 0; }
r[5]=read(ram,r[15]+r[0],4);
goto P_0c067ee8;
P_0c067ee8: /* original 430b, guest PC 0x0c067ee8 */
if(!s->budget--) { s->failed_pc=0x0c067ee8u; return 0; }
target=r[3];
r[16]=0x0c067eecu;
r[4]=read(ram,r[15]+60,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c067eecu) { target=s->pc; goto dispatch; }
goto P_0c067eec;
P_0c067eea: /* original 54ff, guest PC 0x0c067eea */
if(!s->budget--) { s->failed_pc=0x0c067eeau; return 0; }
r[4]=read(ram,r[15]+60,4);
goto P_0c067eec;
P_0c067eec: /* original ab86, guest PC 0x0c067eec */
if(!s->budget--) { s->failed_pc=0x0c067eecu; return 0; }
goto P_0c0675fc;
P_0c067eee: /* original 0009, guest PC 0x0c067eee */
if(!s->budget--) { s->failed_pc=0x0c067eeeu; return 0; }
return vf3_matrix_family(0x0c067ef0u,s,ram);
P_0c0681cc: /* original 9085, guest PC 0x0c0681cc */
if(!s->budget--) { s->failed_pc=0x0c0681ccu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0682dau,2);
goto P_0c0681ce;
P_0c0681ce: /* original 01fe, guest PC 0x0c0681ce */
if(!s->budget--) { s->failed_pc=0x0c0681ceu; return 0; }
r[1]=read(ram,r[15]+r[0],4);
goto P_0c0681d0;
P_0c0681d0: /* original 8512, guest PC 0x0c0681d0 */
if(!s->budget--) { s->failed_pc=0x0c0681d0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[1]+4,2);
goto P_0c0681d2;
P_0c0681d2: /* original 9183, guest PC 0x0c0681d2 */
if(!s->budget--) { s->failed_pc=0x0c0681d2u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0682dcu,2);
goto P_0c0681d4;
P_0c0681d4: /* original 600d, guest PC 0x0c0681d4 */
if(!s->budget--) { s->failed_pc=0x0c0681d4u; return 0; }
r[0]=r[0]&65535u;
goto P_0c0681d6;
P_0c0681d6: /* original 31fc, guest PC 0x0c0681d6 */
if(!s->budget--) { s->failed_pc=0x0c0681d6u; return 0; }
r[1]+=r[15];
goto P_0c0681d8;
P_0c0681d8: /* original 2102, guest PC 0x0c0681d8 */
if(!s->budget--) { s->failed_pc=0x0c0681d8u; return 0; }
write(ram,r[1],r[0],4);
goto P_0c0681da;
P_0c0681da: /* original 907e, guest PC 0x0c0681da */
if(!s->budget--) { s->failed_pc=0x0c0681dau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0682dau,2);
goto P_0c0681dc;
P_0c0681dc: /* original 917f, guest PC 0x0c0681dc */
if(!s->budget--) { s->failed_pc=0x0c0681dcu; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0682deu,2);
goto P_0c0681de;
P_0c0681de: /* original 03fe, guest PC 0x0c0681de */
if(!s->budget--) { s->failed_pc=0x0c0681deu; return 0; }
r[3]=read(ram,r[15]+r[0],4);
goto P_0c0681e0;
P_0c0681e0: /* original 31fc, guest PC 0x0c0681e0 */
if(!s->budget--) { s->failed_pc=0x0c0681e0u; return 0; }
r[1]+=r[15];
goto P_0c0681e2;
P_0c0681e2: /* original 8433, guest PC 0x0c0681e2 */
if(!s->budget--) { s->failed_pc=0x0c0681e2u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[3]+3,1);
goto P_0c0681e4;
P_0c0681e4: /* original 600c, guest PC 0x0c0681e4 */
if(!s->budget--) { s->failed_pc=0x0c0681e4u; return 0; }
r[0]=r[0]&255u;
goto P_0c0681e6;
P_0c0681e6: /* original 2102, guest PC 0x0c0681e6 */
if(!s->budget--) { s->failed_pc=0x0c0681e6u; return 0; }
write(ram,r[1],r[0],4);
goto P_0c0681e8;
P_0c0681e8: /* original d240, guest PC 0x0c0681e8 */
if(!s->budget--) { s->failed_pc=0x0c0681e8u; return 0; }
r[2]=read(ram,0x0c0682ecu,4);
goto P_0c0681ea;
P_0c0681ea: /* original 6322, guest PC 0x0c0681ea */
if(!s->budget--) { s->failed_pc=0x0c0681eau; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c0681ec;
P_0c0681ec: /* original 1f3f, guest PC 0x0c0681ec */
if(!s->budget--) { s->failed_pc=0x0c0681ecu; return 0; }
write(ram,r[15]+60,r[3],4);
goto P_0c0681ee;
P_0c0681ee: /* original 9076, guest PC 0x0c0681ee */
if(!s->budget--) { s->failed_pc=0x0c0681eeu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0682deu,2);
goto P_0c0681f0;
P_0c0681f0: /* original 01fe, guest PC 0x0c0681f0 */
if(!s->budget--) { s->failed_pc=0x0c0681f0u; return 0; }
r[1]=read(ram,r[15]+r[0],4);
goto P_0c0681f2;
P_0c0681f2: /* original 2118, guest PC 0x0c0681f2 */
if(!s->budget--) { s->failed_pc=0x0c0681f2u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[1])==0)!=0);
goto P_0c0681f4;
P_0c0681f4: /* original 8902, guest PC 0x0c0681f4 */
if(!s->budget--) { s->failed_pc=0x0c0681f4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0681fc; }
goto P_0c0681f6;
P_0c0681f6: /* original d13e, guest PC 0x0c0681f6 */
if(!s->budget--) { s->failed_pc=0x0c0681f6u; return 0; }
r[1]=read(ram,0x0c0682f0u,4);
goto P_0c0681f8;
P_0c0681f8: /* original 6312, guest PC 0x0c0681f8 */
if(!s->budget--) { s->failed_pc=0x0c0681f8u; return 0; }
tmp=read(ram,r[1],4);
r[3]=tmp;
goto P_0c0681fa;
P_0c0681fa: /* original 1f3f, guest PC 0x0c0681fa */
if(!s->budget--) { s->failed_pc=0x0c0681fau; return 0; }
write(ram,r[15]+60,r[3],4);
goto P_0c0681fc;
P_0c0681fc: /* original 52ff, guest PC 0x0c0681fc */
if(!s->budget--) { s->failed_pc=0x0c0681fcu; return 0; }
r[2]=read(ram,r[15]+60,4);
goto P_0c0681fe;
P_0c0681fe: /* original e054, guest PC 0x0c0681fe */
if(!s->budget--) { s->failed_pc=0x0c0681feu; return 0; }
r[0]=0x00000054u;
goto P_0c068200;
P_0c068200: /* original 032e, guest PC 0x0c068200 */
if(!s->budget--) { s->failed_pc=0x0c068200u; return 0; }
r[3]=read(ram,r[2]+r[0],4);
goto P_0c068202;
P_0c068202: /* original 1f3c, guest PC 0x0c068202 */
if(!s->budget--) { s->failed_pc=0x0c068202u; return 0; }
write(ram,r[15]+48,r[3],4);
goto P_0c068204;
P_0c068204: /* original 906a, guest PC 0x0c068204 */
if(!s->budget--) { s->failed_pc=0x0c068204u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0682dcu,2);
goto P_0c068206;
P_0c068206: /* original 00fe, guest PC 0x0c068206 */
if(!s->budget--) { s->failed_pc=0x0c068206u; return 0; }
r[0]=read(ram,r[15]+r[0],4);
goto P_0c068208;
P_0c068208: /* original 880a, guest PC 0x0c068208 */
if(!s->budget--) { s->failed_pc=0x0c068208u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000au)!=0);
goto P_0c06820a;
P_0c06820a: /* original 891e, guest PC 0x0c06820a */
if(!s->budget--) { s->failed_pc=0x0c06820au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c06824a; }
goto P_0c06820c;
P_0c06820c: /* original 9066, guest PC 0x0c06820c */
if(!s->budget--) { s->failed_pc=0x0c06820cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0682dcu,2);
goto P_0c06820e;
P_0c06820e: /* original 00fe, guest PC 0x0c06820e */
if(!s->budget--) { s->failed_pc=0x0c06820eu; return 0; }
r[0]=read(ram,r[15]+r[0],4);
goto P_0c068210;
P_0c068210: /* original 880b, guest PC 0x0c068210 */
if(!s->budget--) { s->failed_pc=0x0c068210u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000bu)!=0);
goto P_0c068212;
P_0c068212: /* original 8923, guest PC 0x0c068212 */
if(!s->budget--) { s->failed_pc=0x0c068212u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c06825c; }
goto P_0c068214;
P_0c068214: /* original 9062, guest PC 0x0c068214 */
if(!s->budget--) { s->failed_pc=0x0c068214u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0682dcu,2);
goto P_0c068216;
P_0c068216: /* original 00fe, guest PC 0x0c068216 */
if(!s->budget--) { s->failed_pc=0x0c068216u; return 0; }
r[0]=read(ram,r[15]+r[0],4);
goto P_0c068218;
P_0c068218: /* original 880c, guest PC 0x0c068218 */
if(!s->budget--) { s->failed_pc=0x0c068218u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000cu)!=0);
goto P_0c06821a;
P_0c06821a: /* original 8928, guest PC 0x0c06821a */
if(!s->budget--) { s->failed_pc=0x0c06821au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c06826e; }
goto P_0c06821c;
P_0c06821c: /* original 905e, guest PC 0x0c06821c */
if(!s->budget--) { s->failed_pc=0x0c06821cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0682dcu,2);
goto P_0c06821e;
P_0c06821e: /* original 00fe, guest PC 0x0c06821e */
if(!s->budget--) { s->failed_pc=0x0c06821eu; return 0; }
r[0]=read(ram,r[15]+r[0],4);
goto P_0c068220;
P_0c068220: /* original 880d, guest PC 0x0c068220 */
if(!s->budget--) { s->failed_pc=0x0c068220u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000du)!=0);
goto P_0c068222;
P_0c068222: /* original 892d, guest PC 0x0c068222 */
if(!s->budget--) { s->failed_pc=0x0c068222u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c068280; }
goto P_0c068224;
P_0c068224: /* original 905a, guest PC 0x0c068224 */
if(!s->budget--) { s->failed_pc=0x0c068224u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0682dcu,2);
goto P_0c068226;
P_0c068226: /* original 00fe, guest PC 0x0c068226 */
if(!s->budget--) { s->failed_pc=0x0c068226u; return 0; }
r[0]=read(ram,r[15]+r[0],4);
goto P_0c068228;
P_0c068228: /* original 8808, guest PC 0x0c068228 */
if(!s->budget--) { s->failed_pc=0x0c068228u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000008u)!=0);
goto P_0c06822a;
P_0c06822a: /* original 8b07, guest PC 0x0c06822a */
if(!s->budget--) { s->failed_pc=0x0c06822au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06823c; }
goto P_0c06822c;
P_0c06822c: /* original 53fc, guest PC 0x0c06822c */
if(!s->budget--) { s->failed_pc=0x0c06822cu; return 0; }
r[3]=read(ram,r[15]+48,4);
goto P_0c06822e;
P_0c06822e: /* original e028, guest PC 0x0c06822e */
if(!s->budget--) { s->failed_pc=0x0c06822eu; return 0; }
r[0]=0x00000028u;
goto P_0c068230;
P_0c068230: /* original 023d, guest PC 0x0c068230 */
if(!s->budget--) { s->failed_pc=0x0c068230u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[3]+r[0],2);
goto P_0c068232;
P_0c068232: /* original 9055, guest PC 0x0c068232 */
if(!s->budget--) { s->failed_pc=0x0c068232u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0682e0u,2);
goto P_0c068234;
P_0c068234: /* original 0f26, guest PC 0x0c068234 */
if(!s->budget--) { s->failed_pc=0x0c068234u; return 0; }
write(ram,r[15]+r[0],r[2],4);
goto P_0c068236;
P_0c068236: /* original 6023, guest PC 0x0c068236 */
if(!s->budget--) { s->failed_pc=0x0c068236u; return 0; }
r[0]=r[2];
goto P_0c068238;
P_0c068238: /* original 88ff, guest PC 0x0c068238 */
if(!s->budget--) { s->failed_pc=0x0c068238u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c06823a;
P_0c06823a: /* original 8b2a, guest PC 0x0c06823a */
if(!s->budget--) { s->failed_pc=0x0c06823au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c068292; }
goto P_0c06823c;
P_0c06823c: /* original 53fc, guest PC 0x0c06823c */
if(!s->budget--) { s->failed_pc=0x0c06823cu; return 0; }
r[3]=read(ram,r[15]+48,4);
goto P_0c06823e;
P_0c06823e: /* original e022, guest PC 0x0c06823e */
if(!s->budget--) { s->failed_pc=0x0c06823eu; return 0; }
r[0]=0x00000022u;
goto P_0c068240;
P_0c068240: /* original 023d, guest PC 0x0c068240 */
if(!s->budget--) { s->failed_pc=0x0c068240u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[3]+r[0],2);
goto P_0c068242;
P_0c068242: /* original 904d, guest PC 0x0c068242 */
if(!s->budget--) { s->failed_pc=0x0c068242u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0682e0u,2);
goto P_0c068244;
P_0c068244: /* original 7201, guest PC 0x0c068244 */
if(!s->budget--) { s->failed_pc=0x0c068244u; return 0; }
r[2]+=0x00000001u;
goto P_0c068246;
P_0c068246: /* original a024, guest PC 0x0c068246 */
if(!s->budget--) { s->failed_pc=0x0c068246u; return 0; }
write(ram,r[15]+r[0],r[2],4);
goto P_0c068292;
P_0c068248: /* original 0f26, guest PC 0x0c068248 */
if(!s->budget--) { s->failed_pc=0x0c068248u; return 0; }
write(ram,r[15]+r[0],r[2],4);
goto P_0c06824a;
P_0c06824a: /* original d32a, guest PC 0x0c06824a */
if(!s->budget--) { s->failed_pc=0x0c06824au; return 0; }
r[3]=read(ram,0x0c0682f4u,4);
goto P_0c06824c;
P_0c06824c: /* original 55fc, guest PC 0x0c06824c */
if(!s->budget--) { s->failed_pc=0x0c06824cu; return 0; }
r[5]=read(ram,r[15]+48,4);
goto P_0c06824e;
P_0c06824e: /* original 430b, guest PC 0x0c06824e */
if(!s->budget--) { s->failed_pc=0x0c06824eu; return 0; }
target=r[3];
r[16]=0x0c068252u;
r[4]=read(ram,r[15]+60,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c068252u) { target=s->pc; goto dispatch; }
goto P_0c068252;
P_0c068250: /* original 54ff, guest PC 0x0c068250 */
if(!s->budget--) { s->failed_pc=0x0c068250u; return 0; }
r[4]=read(ram,r[15]+60,4);
goto P_0c068252;
P_0c068252: /* original e22a, guest PC 0x0c068252 */
if(!s->budget--) { s->failed_pc=0x0c068252u; return 0; }
r[2]=0x0000002au;
goto P_0c068254;
P_0c068254: /* original 1f0c, guest PC 0x0c068254 */
if(!s->budget--) { s->failed_pc=0x0c068254u; return 0; }
write(ram,r[15]+48,r[0],4);
goto P_0c068256;
P_0c068256: /* original 032d, guest PC 0x0c068256 */
if(!s->budget--) { s->failed_pc=0x0c068256u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[2]+r[0],2);
goto P_0c068258;
P_0c068258: /* original a019, guest PC 0x0c068258 */
if(!s->budget--) { s->failed_pc=0x0c068258u; return 0; }
goto P_0c06828e;
P_0c06825a: /* original 0009, guest PC 0x0c06825a */
if(!s->budget--) { s->failed_pc=0x0c06825au; return 0; }
goto P_0c06825c;
P_0c06825c: /* original d325, guest PC 0x0c06825c */
if(!s->budget--) { s->failed_pc=0x0c06825cu; return 0; }
r[3]=read(ram,0x0c0682f4u,4);
goto P_0c06825e;
P_0c06825e: /* original 55fc, guest PC 0x0c06825e */
if(!s->budget--) { s->failed_pc=0x0c06825eu; return 0; }
r[5]=read(ram,r[15]+48,4);
goto P_0c068260;
P_0c068260: /* original 430b, guest PC 0x0c068260 */
if(!s->budget--) { s->failed_pc=0x0c068260u; return 0; }
target=r[3];
r[16]=0x0c068264u;
r[4]=read(ram,r[15]+60,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c068264u) { target=s->pc; goto dispatch; }
goto P_0c068264;
P_0c068262: /* original 54ff, guest PC 0x0c068262 */
if(!s->budget--) { s->failed_pc=0x0c068262u; return 0; }
r[4]=read(ram,r[15]+60,4);
goto P_0c068264;
P_0c068264: /* original e22c, guest PC 0x0c068264 */
if(!s->budget--) { s->failed_pc=0x0c068264u; return 0; }
r[2]=0x0000002cu;
goto P_0c068266;
P_0c068266: /* original 1f0c, guest PC 0x0c068266 */
if(!s->budget--) { s->failed_pc=0x0c068266u; return 0; }
write(ram,r[15]+48,r[0],4);
goto P_0c068268;
P_0c068268: /* original 032d, guest PC 0x0c068268 */
if(!s->budget--) { s->failed_pc=0x0c068268u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[2]+r[0],2);
goto P_0c06826a;
P_0c06826a: /* original a010, guest PC 0x0c06826a */
if(!s->budget--) { s->failed_pc=0x0c06826au; return 0; }
goto P_0c06828e;
P_0c06826c: /* original 0009, guest PC 0x0c06826c */
if(!s->budget--) { s->failed_pc=0x0c06826cu; return 0; }
goto P_0c06826e;
P_0c06826e: /* original d321, guest PC 0x0c06826e */
if(!s->budget--) { s->failed_pc=0x0c06826eu; return 0; }
r[3]=read(ram,0x0c0682f4u,4);
goto P_0c068270;
P_0c068270: /* original 55fc, guest PC 0x0c068270 */
if(!s->budget--) { s->failed_pc=0x0c068270u; return 0; }
r[5]=read(ram,r[15]+48,4);
goto P_0c068272;
P_0c068272: /* original 430b, guest PC 0x0c068272 */
if(!s->budget--) { s->failed_pc=0x0c068272u; return 0; }
target=r[3];
r[16]=0x0c068276u;
r[4]=read(ram,r[15]+60,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c068276u) { target=s->pc; goto dispatch; }
goto P_0c068276;
P_0c068274: /* original 54ff, guest PC 0x0c068274 */
if(!s->budget--) { s->failed_pc=0x0c068274u; return 0; }
r[4]=read(ram,r[15]+60,4);
goto P_0c068276;
P_0c068276: /* original e22e, guest PC 0x0c068276 */
if(!s->budget--) { s->failed_pc=0x0c068276u; return 0; }
r[2]=0x0000002eu;
goto P_0c068278;
P_0c068278: /* original 1f0c, guest PC 0x0c068278 */
if(!s->budget--) { s->failed_pc=0x0c068278u; return 0; }
write(ram,r[15]+48,r[0],4);
goto P_0c06827a;
P_0c06827a: /* original 032d, guest PC 0x0c06827a */
if(!s->budget--) { s->failed_pc=0x0c06827au; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[2]+r[0],2);
goto P_0c06827c;
P_0c06827c: /* original a007, guest PC 0x0c06827c */
if(!s->budget--) { s->failed_pc=0x0c06827cu; return 0; }
goto P_0c06828e;
P_0c06827e: /* original 0009, guest PC 0x0c06827e */
if(!s->budget--) { s->failed_pc=0x0c06827eu; return 0; }
goto P_0c068280;
P_0c068280: /* original d31c, guest PC 0x0c068280 */
if(!s->budget--) { s->failed_pc=0x0c068280u; return 0; }
r[3]=read(ram,0x0c0682f4u,4);
goto P_0c068282;
P_0c068282: /* original 55fc, guest PC 0x0c068282 */
if(!s->budget--) { s->failed_pc=0x0c068282u; return 0; }
r[5]=read(ram,r[15]+48,4);
goto P_0c068284;
P_0c068284: /* original 430b, guest PC 0x0c068284 */
if(!s->budget--) { s->failed_pc=0x0c068284u; return 0; }
target=r[3];
r[16]=0x0c068288u;
r[4]=read(ram,r[15]+60,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c068288u) { target=s->pc; goto dispatch; }
goto P_0c068288;
P_0c068286: /* original 54ff, guest PC 0x0c068286 */
if(!s->budget--) { s->failed_pc=0x0c068286u; return 0; }
r[4]=read(ram,r[15]+60,4);
goto P_0c068288;
P_0c068288: /* original e230, guest PC 0x0c068288 */
if(!s->budget--) { s->failed_pc=0x0c068288u; return 0; }
r[2]=0x00000030u;
goto P_0c06828a;
P_0c06828a: /* original 1f0c, guest PC 0x0c06828a */
if(!s->budget--) { s->failed_pc=0x0c06828au; return 0; }
write(ram,r[15]+48,r[0],4);
goto P_0c06828c;
P_0c06828c: /* original 032d, guest PC 0x0c06828c */
if(!s->budget--) { s->failed_pc=0x0c06828cu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[2]+r[0],2);
goto P_0c06828e;
P_0c06828e: /* original 9027, guest PC 0x0c06828e */
if(!s->budget--) { s->failed_pc=0x0c06828eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0682e0u,2);
goto P_0c068290;
P_0c068290: /* original 0f36, guest PC 0x0c068290 */
if(!s->budget--) { s->failed_pc=0x0c068290u; return 0; }
write(ram,r[15]+r[0],r[3],4);
goto P_0c068292;
P_0c068292: /* original 9025, guest PC 0x0c068292 */
if(!s->budget--) { s->failed_pc=0x0c068292u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0682e0u,2);
goto P_0c068294;
P_0c068294: /* original 52ff, guest PC 0x0c068294 */
if(!s->budget--) { s->failed_pc=0x0c068294u; return 0; }
r[2]=read(ram,r[15]+60,4);
goto P_0c068296;
P_0c068296: /* original 03fd, guest PC 0x0c068296 */
if(!s->budget--) { s->failed_pc=0x0c068296u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+r[0],2);
goto P_0c068298;
P_0c068298: /* original 9023, guest PC 0x0c068298 */
if(!s->budget--) { s->failed_pc=0x0c068298u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0682e2u,2);
goto P_0c06829a;
P_0c06829a: /* original 0235, guest PC 0x0c06829a */
if(!s->budget--) { s->failed_pc=0x0c06829au; return 0; }
write(ram,r[2]+r[0],r[3],2);
goto P_0c06829c;
P_0c06829c: /* original a9ae, guest PC 0x0c06829c */
if(!s->budget--) { s->failed_pc=0x0c06829cu; return 0; }
goto P_0c0675fc;
P_0c06829e: /* original 0009, guest PC 0x0c06829e */
if(!s->budget--) { s->failed_pc=0x0c06829eu; return 0; }
return vf3_matrix_family(0x0c0682a0u,s,ram);
P_0c0685de: /* original a80d, guest PC 0x0c0685de */
if(!s->budget--) { s->failed_pc=0x0c0685deu; return 0; }
r[15]+=0x00000004u;
goto P_0c0675fc;
P_0c0685e0: /* original 7f04, guest PC 0x0c0685e0 */
if(!s->budget--) { s->failed_pc=0x0c0685e0u; return 0; }
r[15]+=0x00000004u;
goto P_0c0685e2;
P_0c0685e2: /* original 906f, guest PC 0x0c0685e2 */
if(!s->budget--) { s->failed_pc=0x0c0685e2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0686c4u,2);
goto P_0c0685e4;
P_0c0685e4: /* original e208, guest PC 0x0c0685e4 */
if(!s->budget--) { s->failed_pc=0x0c0685e4u; return 0; }
r[2]=0x00000008u;
goto P_0c0685e6;
P_0c0685e6: /* original 0f26, guest PC 0x0c0685e6 */
if(!s->budget--) { s->failed_pc=0x0c0685e6u; return 0; }
write(ram,r[15]+r[0],r[2],4);
goto P_0c0685e8;
P_0c0685e8: /* original 906c, guest PC 0x0c0685e8 */
if(!s->budget--) { s->failed_pc=0x0c0685e8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0686c4u,2);
goto P_0c0685ea;
P_0c0685ea: /* original d13a, guest PC 0x0c0685ea */
if(!s->budget--) { s->failed_pc=0x0c0685eau; return 0; }
r[1]=read(ram,0x0c0686d4u,4);
goto P_0c0685ec;
P_0c0685ec: /* original 03fc, guest PC 0x0c0685ec */
if(!s->budget--) { s->failed_pc=0x0c0685ecu; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[15]+r[0],1);
goto P_0c0685ee;
P_0c0685ee: /* original a805, guest PC 0x0c0685ee */
if(!s->budget--) { s->failed_pc=0x0c0685eeu; return 0; }
write(ram,r[1],r[3],1);
goto P_0c0675fc;
P_0c0685f0: /* original 2130, guest PC 0x0c0685f0 */
if(!s->budget--) { s->failed_pc=0x0c0685f0u; return 0; }
write(ram,r[1],r[3],1);
return vf3_matrix_family(0x0c0685f2u,s,ram);
P_0c06862a: /* original 914c, guest PC 0x0c06862a */
if(!s->budget--) { s->failed_pc=0x0c06862au; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0686c6u,2);
goto P_0c06862c;
P_0c06862c: /* original 3f1c, guest PC 0x0c06862c */
if(!s->budget--) { s->failed_pc=0x0c06862cu; return 0; }
r[15]+=r[1];
goto P_0c06862e;
P_0c06862e: /* original 4f16, guest PC 0x0c06862e */
if(!s->budget--) { s->failed_pc=0x0c06862eu; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c068630;
P_0c068630: /* original 4f26, guest PC 0x0c068630 */
if(!s->budget--) { s->failed_pc=0x0c068630u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c068632;
P_0c068632: /* original 000b, guest PC 0x0c068632 */
if(!s->budget--) { s->failed_pc=0x0c068632u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c068634: /* original 0009, guest PC 0x0c068634 */
if(!s->budget--) { s->failed_pc=0x0c068634u; return 0; }
goto P_0c068636;
P_0c068636: /* original 2fe6, guest PC 0x0c068636 */
if(!s->budget--) { s->failed_pc=0x0c068636u; return 0; }
r[15]-=4; write(ram,r[15],r[14],4);
goto P_0c068638;
P_0c068638: /* original 2558, guest PC 0x0c068638 */
if(!s->budget--) { s->failed_pc=0x0c068638u; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[5])==0)!=0);
goto P_0c06863a;
P_0c06863a: /* original 2fd6, guest PC 0x0c06863a */
if(!s->budget--) { s->failed_pc=0x0c06863au; return 0; }
r[15]-=4; write(ram,r[15],r[13],4);
goto P_0c06863c;
P_0c06863c: /* original 6e43, guest PC 0x0c06863c */
if(!s->budget--) { s->failed_pc=0x0c06863cu; return 0; }
r[14]=r[4];
goto P_0c06863e;
P_0c06863e: /* original fffb, guest PC 0x0c06863e */
if(!s->budget--) { s->failed_pc=0x0c06863eu; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c068640;
P_0c068640: /* original ffeb, guest PC 0x0c068640 */
if(!s->budget--) { s->failed_pc=0x0c068640u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,14,r[15]);
goto P_0c068642;
P_0c068642: /* original 4f22, guest PC 0x0c068642 */
if(!s->budget--) { s->failed_pc=0x0c068642u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c068644;
P_0c068644: /* original 7fb0, guest PC 0x0c068644 */
if(!s->budget--) { s->failed_pc=0x0c068644u; return 0; }
r[15]+=0xffffffb0u;
goto P_0c068646;
P_0c068646: /* original 8d06, guest PC 0x0c068646 */
if(!s->budget--) { s->failed_pc=0x0c068646u; return 0; }
cond=r[17]&1u;
r[4]=0x00000000u;
if(cond) { goto P_0c068656; }
goto P_0c06864a;
P_0c068648: /* original e400, guest PC 0x0c068648 */
if(!s->budget--) { s->failed_pc=0x0c068648u; return 0; }
r[4]=0x00000000u;
goto P_0c06864a;
P_0c06864a: /* original 903d, guest PC 0x0c06864a */
if(!s->budget--) { s->failed_pc=0x0c06864au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0686c8u,2);
goto P_0c06864c;
P_0c06864c: /* original 6543, guest PC 0x0c06864c */
if(!s->budget--) { s->failed_pc=0x0c06864cu; return 0; }
r[5]=r[4];
goto P_0c06864e;
P_0c06864e: /* original 0e54, guest PC 0x0c06864e */
if(!s->budget--) { s->failed_pc=0x0c06864eu; return 0; }
write(ram,r[14]+r[0],r[5],1);
goto P_0c068650;
P_0c068650: /* original 70dc, guest PC 0x0c068650 */
if(!s->budget--) { s->failed_pc=0x0c068650u; return 0; }
r[0]+=0xffffffdcu;
goto P_0c068652;
P_0c068652: /* original a011, guest PC 0x0c068652 */
if(!s->budget--) { s->failed_pc=0x0c068652u; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c068678;
P_0c068654: /* original 04ee, guest PC 0x0c068654 */
if(!s->budget--) { s->failed_pc=0x0c068654u; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c068656;
P_0c068656: /* original 9038, guest PC 0x0c068656 */
if(!s->budget--) { s->failed_pc=0x0c068656u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0686cau,2);
goto P_0c068658;
P_0c068658: /* original 6543, guest PC 0x0c068658 */
if(!s->budget--) { s->failed_pc=0x0c068658u; return 0; }
r[5]=r[4];
goto P_0c06865a;
P_0c06865a: /* original 04ee, guest PC 0x0c06865a */
if(!s->budget--) { s->failed_pc=0x0c06865au; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c06865c;
P_0c06865c: /* original 85e3, guest PC 0x0c06865c */
if(!s->budget--) { s->failed_pc=0x0c06865cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+6,2);
goto P_0c06865e;
P_0c06865e: /* original 670d, guest PC 0x0c06865e */
if(!s->budget--) { s->failed_pc=0x0c06865eu; return 0; }
r[7]=r[0]&65535u;
goto P_0c068660;
P_0c068660: /* original e034, guest PC 0x0c068660 */
if(!s->budget--) { s->failed_pc=0x0c068660u; return 0; }
r[0]=0x00000034u;
goto P_0c068662;
P_0c068662: /* original 064d, guest PC 0x0c068662 */
if(!s->budget--) { s->failed_pc=0x0c068662u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c068664;
P_0c068664: /* original 666d, guest PC 0x0c068664 */
if(!s->budget--) { s->failed_pc=0x0c068664u; return 0; }
r[6]=r[6]&65535u;
goto P_0c068666;
P_0c068666: /* original 3760, guest PC 0x0c068666 */
if(!s->budget--) { s->failed_pc=0x0c068666u; return 0; }
r[17]=(r[17]&~1u)|((r[7]==r[6])!=0);
goto P_0c068668;
P_0c068668: /* original 8b15, guest PC 0x0c068668 */
if(!s->budget--) { s->failed_pc=0x0c068668u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c068696; }
goto P_0c06866a;
P_0c06866a: /* original 902e, guest PC 0x0c06866a */
if(!s->budget--) { s->failed_pc=0x0c06866au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0686cau,2);
goto P_0c06866c;
P_0c06866c: /* original 741c, guest PC 0x0c06866c */
if(!s->budget--) { s->failed_pc=0x0c06866cu; return 0; }
r[4]+=0x0000001cu;
goto P_0c06866e;
P_0c06866e: /* original 0e46, guest PC 0x0c06866e */
if(!s->budget--) { s->failed_pc=0x0c06866eu; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c068670;
P_0c068670: /* original 7024, guest PC 0x0c068670 */
if(!s->budget--) { s->failed_pc=0x0c068670u; return 0; }
r[0]+=0x00000024u;
goto P_0c068672;
P_0c068672: /* original 06ec, guest PC 0x0c068672 */
if(!s->budget--) { s->failed_pc=0x0c068672u; return 0; }
r[6]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c068674;
P_0c068674: /* original 7601, guest PC 0x0c068674 */
if(!s->budget--) { s->failed_pc=0x0c068674u; return 0; }
r[6]+=0x00000001u;
goto P_0c068676;
P_0c068676: /* original 0e64, guest PC 0x0c068676 */
if(!s->budget--) { s->failed_pc=0x0c068676u; return 0; }
write(ram,r[14]+r[0],r[6],1);
goto P_0c068678;
P_0c068678: /* original e01a, guest PC 0x0c068678 */
if(!s->budget--) { s->failed_pc=0x0c068678u; return 0; }
r[0]=0x0000001au;
goto P_0c06867a;
P_0c06867a: /* original 064c, guest PC 0x0c06867a */
if(!s->budget--) { s->failed_pc=0x0c06867au; return 0; }
r[6]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c06867c;
P_0c06867c: /* original 666c, guest PC 0x0c06867c */
if(!s->budget--) { s->failed_pc=0x0c06867cu; return 0; }
r[6]=r[6]&255u;
goto P_0c06867e;
P_0c06867e: /* original 6063, guest PC 0x0c06867e */
if(!s->budget--) { s->failed_pc=0x0c06867eu; return 0; }
r[0]=r[6];
goto P_0c068680;
P_0c068680: /* original 8800, guest PC 0x0c068680 */
if(!s->budget--) { s->failed_pc=0x0c068680u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000000u)!=0);
goto P_0c068682;
P_0c068682: /* original 8d33, guest PC 0x0c068682 */
if(!s->budget--) { s->failed_pc=0x0c068682u; return 0; }
cond=r[17]&1u;
fr[5]=0;
if(cond) { goto P_0c0686ec; }
goto P_0c068686;
P_0c068684: /* original f58d, guest PC 0x0c068684 */
if(!s->budget--) { s->failed_pc=0x0c068684u; return 0; }
fr[5]=0;
goto P_0c068686;
P_0c068686: /* original 8801, guest PC 0x0c068686 */
if(!s->budget--) { s->failed_pc=0x0c068686u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c068688;
P_0c068688: /* original 894a, guest PC 0x0c068688 */
if(!s->budget--) { s->failed_pc=0x0c068688u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c068720; }
goto P_0c06868a;
P_0c06868a: /* original 8802, guest PC 0x0c06868a */
if(!s->budget--) { s->failed_pc=0x0c06868au; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c06868c;
P_0c06868c: /* original 8b01, guest PC 0x0c06868c */
if(!s->budget--) { s->failed_pc=0x0c06868cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c068692; }
goto P_0c06868e;
P_0c06868e: /* original a0ac, guest PC 0x0c06868e */
if(!s->budget--) { s->failed_pc=0x0c06868eu; return 0; }
goto P_0c0687ea;
P_0c068690: /* original 0009, guest PC 0x0c068690 */
if(!s->budget--) { s->failed_pc=0x0c068690u; return 0; }
goto P_0c068692;
P_0c068692: /* original aff4, guest PC 0x0c068692 */
if(!s->budget--) { s->failed_pc=0x0c068692u; return 0; }
goto P_0c06867e;
P_0c068694: /* original 0009, guest PC 0x0c068694 */
if(!s->budget--) { s->failed_pc=0x0c068694u; return 0; }
goto P_0c068696;
P_0c068696: /* original 85e3, guest PC 0x0c068696 */
if(!s->budget--) { s->failed_pc=0x0c068696u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+6,2);
goto P_0c068698;
P_0c068698: /* original 7001, guest PC 0x0c068698 */
if(!s->budget--) { s->failed_pc=0x0c068698u; return 0; }
r[0]+=0x00000001u;
goto P_0c06869a;
P_0c06869a: /* original 81e3, guest PC 0x0c06869a */
if(!s->budget--) { s->failed_pc=0x0c06869au; return 0; }
write(ram,r[14]+6,r[0],2);
goto P_0c06869c;
P_0c06869c: /* original e01a, guest PC 0x0c06869c */
if(!s->budget--) { s->failed_pc=0x0c06869cu; return 0; }
r[0]=0x0000001au;
goto P_0c06869e;
P_0c06869e: /* original 064c, guest PC 0x0c06869e */
if(!s->budget--) { s->failed_pc=0x0c06869eu; return 0; }
r[6]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c0686a0;
P_0c0686a0: /* original 666c, guest PC 0x0c0686a0 */
if(!s->budget--) { s->failed_pc=0x0c0686a0u; return 0; }
r[6]=r[6]&255u;
goto P_0c0686a2;
P_0c0686a2: /* original 6063, guest PC 0x0c0686a2 */
if(!s->budget--) { s->failed_pc=0x0c0686a2u; return 0; }
r[0]=r[6];
goto P_0c0686a4;
P_0c0686a4: /* original 8800, guest PC 0x0c0686a4 */
if(!s->budget--) { s->failed_pc=0x0c0686a4u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000000u)!=0);
goto P_0c0686a6;
P_0c0686a6: /* original f49d, guest PC 0x0c0686a6 */
if(!s->budget--) { s->failed_pc=0x0c0686a6u; return 0; }
fr[4]=0x3f800000u;
goto P_0c0686a8;
P_0c0686a8: /* original 6d43, guest PC 0x0c0686a8 */
if(!s->budget--) { s->failed_pc=0x0c0686a8u; return 0; }
r[13]=r[4];
goto P_0c0686aa;
P_0c0686aa: /* original 8f02, guest PC 0x0c0686aa */
if(!s->budget--) { s->failed_pc=0x0c0686aau; return 0; }
cond=r[17]&1u;
r[13]+=0x0000001cu;
if(!cond) { goto P_0c0686b2; }
goto P_0c0686ae;
P_0c0686ac: /* original 7d1c, guest PC 0x0c0686ac */
if(!s->budget--) { s->failed_pc=0x0c0686acu; return 0; }
r[13]+=0x0000001cu;
goto P_0c0686ae;
P_0c0686ae: /* original a273, guest PC 0x0c0686ae */
if(!s->budget--) { s->failed_pc=0x0c0686aeu; return 0; }
goto P_0c068b98;
P_0c0686b0: /* original 0009, guest PC 0x0c0686b0 */
if(!s->budget--) { s->failed_pc=0x0c0686b0u; return 0; }
goto P_0c0686b2;
P_0c0686b2: /* original 8801, guest PC 0x0c0686b2 */
if(!s->budget--) { s->failed_pc=0x0c0686b2u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c0686b4;
P_0c0686b4: /* original 8944, guest PC 0x0c0686b4 */
if(!s->budget--) { s->failed_pc=0x0c0686b4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c068740; }
goto P_0c0686b6;
P_0c0686b6: /* original 8802, guest PC 0x0c0686b6 */
if(!s->budget--) { s->failed_pc=0x0c0686b6u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c0686b8;
P_0c0686b8: /* original 8b01, guest PC 0x0c0686b8 */
if(!s->budget--) { s->failed_pc=0x0c0686b8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0686be; }
goto P_0c0686ba;
P_0c0686ba: /* original a16a, guest PC 0x0c0686ba */
if(!s->budget--) { s->failed_pc=0x0c0686bau; return 0; }
goto P_0c068992;
P_0c0686bc: /* original 0009, guest PC 0x0c0686bc */
if(!s->budget--) { s->failed_pc=0x0c0686bcu; return 0; }
goto P_0c0686be;
P_0c0686be: /* original aff0, guest PC 0x0c0686be */
if(!s->budget--) { s->failed_pc=0x0c0686beu; return 0; }
goto P_0c0686a2;
P_0c0686c0: /* original 0009, guest PC 0x0c0686c0 */
if(!s->budget--) { s->failed_pc=0x0c0686c0u; return 0; }
return vf3_matrix_family(0x0c0686c2u,s,ram);
P_0c0686ec: /* original e004, guest PC 0x0c0686ec */
if(!s->budget--) { s->failed_pc=0x0c0686ecu; return 0; }
r[0]=0x00000004u;
goto P_0c0686ee;
P_0c0686ee: /* original f448, guest PC 0x0c0686ee */
if(!s->budget--) { s->failed_pc=0x0c0686eeu; return 0; }
vf3_matrix_load(s,ram,4,r[4]);
goto P_0c0686f0;
P_0c0686f0: /* original f946, guest PC 0x0c0686f0 */
if(!s->budget--) { s->failed_pc=0x0c0686f0u; return 0; }
vf3_matrix_load(s,ram,9,r[4]+r[0]);
goto P_0c0686f2;
P_0c0686f2: /* original e008, guest PC 0x0c0686f2 */
if(!s->budget--) { s->failed_pc=0x0c0686f2u; return 0; }
r[0]=0x00000008u;
goto P_0c0686f4;
P_0c0686f4: /* original f846, guest PC 0x0c0686f4 */
if(!s->budget--) { s->failed_pc=0x0c0686f4u; return 0; }
vf3_matrix_load(s,ram,8,r[4]+r[0]);
goto P_0c0686f6;
P_0c0686f6: /* original e00c, guest PC 0x0c0686f6 */
if(!s->budget--) { s->failed_pc=0x0c0686f6u; return 0; }
r[0]=0x0000000cu;
goto P_0c0686f8;
P_0c0686f8: /* original f646, guest PC 0x0c0686f8 */
if(!s->budget--) { s->failed_pc=0x0c0686f8u; return 0; }
vf3_matrix_load(s,ram,6,r[4]+r[0]);
goto P_0c0686fa;
P_0c0686fa: /* original e010, guest PC 0x0c0686fa */
if(!s->budget--) { s->failed_pc=0x0c0686fau; return 0; }
r[0]=0x00000010u;
goto P_0c0686fc;
P_0c0686fc: /* original f546, guest PC 0x0c0686fc */
if(!s->budget--) { s->failed_pc=0x0c0686fcu; return 0; }
vf3_matrix_load(s,ram,5,r[4]+r[0]);
goto P_0c0686fe;
P_0c0686fe: /* original 2558, guest PC 0x0c0686fe */
if(!s->budget--) { s->failed_pc=0x0c0686feu; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[5])==0)!=0);
goto P_0c068700;
P_0c068700: /* original e014, guest PC 0x0c068700 */
if(!s->budget--) { s->failed_pc=0x0c068700u; return 0; }
r[0]=0x00000014u;
goto P_0c068702;
P_0c068702: /* original 8fc8, guest PC 0x0c068702 */
if(!s->budget--) { s->failed_pc=0x0c068702u; return 0; }
cond=r[17]&1u;
vf3_matrix_load(s,ram,7,r[4]+r[0]);
if(!cond) { goto P_0c068696; }
goto P_0c068706;
P_0c068704: /* original f746, guest PC 0x0c068704 */
if(!s->budget--) { s->failed_pc=0x0c068704u; return 0; }
vf3_matrix_load(s,ram,7,r[4]+r[0]);
goto P_0c068706;
P_0c068706: /* original e010, guest PC 0x0c068706 */
if(!s->budget--) { s->failed_pc=0x0c068706u; return 0; }
r[0]=0x00000010u;
goto P_0c068708;
P_0c068708: /* original fe47, guest PC 0x0c068708 */
if(!s->budget--) { s->failed_pc=0x0c068708u; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c06870a;
P_0c06870a: /* original e014, guest PC 0x0c06870a */
if(!s->budget--) { s->failed_pc=0x0c06870au; return 0; }
r[0]=0x00000014u;
goto P_0c06870c;
P_0c06870c: /* original fe97, guest PC 0x0c06870c */
if(!s->budget--) { s->failed_pc=0x0c06870cu; return 0; }
vf3_matrix_store(s,ram,9,r[14]+r[0]);
goto P_0c06870e;
P_0c06870e: /* original e018, guest PC 0x0c06870e */
if(!s->budget--) { s->failed_pc=0x0c06870eu; return 0; }
r[0]=0x00000018u;
goto P_0c068710;
P_0c068710: /* original fe87, guest PC 0x0c068710 */
if(!s->budget--) { s->failed_pc=0x0c068710u; return 0; }
vf3_matrix_store(s,ram,8,r[14]+r[0]);
goto P_0c068712;
P_0c068712: /* original 9067, guest PC 0x0c068712 */
if(!s->budget--) { s->failed_pc=0x0c068712u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0687e4u,2);
goto P_0c068714;
P_0c068714: /* original fe67, guest PC 0x0c068714 */
if(!s->budget--) { s->failed_pc=0x0c068714u; return 0; }
vf3_matrix_store(s,ram,6,r[14]+r[0]);
goto P_0c068716;
P_0c068716: /* original 7004, guest PC 0x0c068716 */
if(!s->budget--) { s->failed_pc=0x0c068716u; return 0; }
r[0]+=0x00000004u;
goto P_0c068718;
P_0c068718: /* original fe57, guest PC 0x0c068718 */
if(!s->budget--) { s->failed_pc=0x0c068718u; return 0; }
vf3_matrix_store(s,ram,5,r[14]+r[0]);
goto P_0c06871a;
P_0c06871a: /* original 7004, guest PC 0x0c06871a */
if(!s->budget--) { s->failed_pc=0x0c06871au; return 0; }
r[0]+=0x00000004u;
goto P_0c06871c;
P_0c06871c: /* original afbb, guest PC 0x0c06871c */
if(!s->budget--) { s->failed_pc=0x0c06871cu; return 0; }
vf3_matrix_store(s,ram,7,r[14]+r[0]);
goto P_0c068696;
P_0c06871e: /* original fe77, guest PC 0x0c06871e */
if(!s->budget--) { s->failed_pc=0x0c06871eu; return 0; }
vf3_matrix_store(s,ram,7,r[14]+r[0]);
goto P_0c068720;
P_0c068720: /* original e034, guest PC 0x0c068720 */
if(!s->budget--) { s->failed_pc=0x0c068720u; return 0; }
r[0]=0x00000034u;
goto P_0c068722;
P_0c068722: /* original 074d, guest PC 0x0c068722 */
if(!s->budget--) { s->failed_pc=0x0c068722u; return 0; }
r[7]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c068724;
P_0c068724: /* original 854c, guest PC 0x0c068724 */
if(!s->budget--) { s->failed_pc=0x0c068724u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+24,2);
goto P_0c068726;
P_0c068726: /* original 677d, guest PC 0x0c068726 */
if(!s->budget--) { s->failed_pc=0x0c068726u; return 0; }
r[7]=r[7]&65535u;
goto P_0c068728;
P_0c068728: /* original 6373, guest PC 0x0c068728 */
if(!s->budget--) { s->failed_pc=0x0c068728u; return 0; }
r[3]=r[7];
goto P_0c06872a;
P_0c06872a: /* original 660d, guest PC 0x0c06872a */
if(!s->budget--) { s->failed_pc=0x0c06872au; return 0; }
r[6]=r[0]&65535u;
goto P_0c06872c;
P_0c06872c: /* original 3368, guest PC 0x0c06872c */
if(!s->budget--) { s->failed_pc=0x0c06872cu; return 0; }
r[3]-=r[6];
goto P_0c06872e;
P_0c06872e: /* original 905a, guest PC 0x0c06872e */
if(!s->budget--) { s->failed_pc=0x0c06872eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0687e6u,2);
goto P_0c068730;
P_0c068730: /* original 6633, guest PC 0x0c068730 */
if(!s->budget--) { s->failed_pc=0x0c068730u; return 0; }
r[6]=r[3];
goto P_0c068732;
P_0c068732: /* original 465a, guest PC 0x0c068732 */
if(!s->budget--) { s->failed_pc=0x0c068732u; return 0; }
r[53]=r[6];
goto P_0c068734;
P_0c068734: /* original f32d, guest PC 0x0c068734 */
if(!s->budget--) { s->failed_pc=0x0c068734u; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c068736;
P_0c068736: /* original fe37, guest PC 0x0c068736 */
if(!s->budget--) { s->failed_pc=0x0c068736u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c068738;
P_0c068738: /* original 70e4, guest PC 0x0c068738 */
if(!s->budget--) { s->failed_pc=0x0c068738u; return 0; }
r[0]+=0xffffffe4u;
goto P_0c06873a;
P_0c06873a: /* original f45c, guest PC 0x0c06873a */
if(!s->budget--) { s->failed_pc=0x0c06873au; return 0; }
vf3_matrix_move(s,4,5);
goto P_0c06873c;
P_0c06873c: /* original afab, guest PC 0x0c06873c */
if(!s->budget--) { s->failed_pc=0x0c06873cu; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c068696;
P_0c06873e: /* original fe47, guest PC 0x0c06873e */
if(!s->budget--) { s->failed_pc=0x0c06873eu; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c068740;
P_0c068740: /* original f8d8, guest PC 0x0c068740 */
if(!s->budget--) { s->failed_pc=0x0c068740u; return 0; }
vf3_matrix_load(s,ram,8,r[13]);
goto P_0c068742;
P_0c068742: /* original f748, guest PC 0x0c068742 */
if(!s->budget--) { s->failed_pc=0x0c068742u; return 0; }
vf3_matrix_load(s,ram,7,r[4]);
goto P_0c068744;
P_0c068744: /* original 904f, guest PC 0x0c068744 */
if(!s->budget--) { s->failed_pc=0x0c068744u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0687e6u,2);
goto P_0c068746;
P_0c068746: /* original f871, guest PC 0x0c068746 */
if(!s->budget--) { s->failed_pc=0x0c068746u; return 0; }
fr[8]=vf3_fpu_binary(fr[8],fr[7],r[18],'-');
goto P_0c068748;
P_0c068748: /* original f5e6, guest PC 0x0c068748 */
if(!s->budget--) { s->failed_pc=0x0c068748u; return 0; }
vf3_matrix_load(s,ram,5,r[14]+r[0]);
goto P_0c06874a;
P_0c06874a: /* original 70e4, guest PC 0x0c06874a */
if(!s->budget--) { s->failed_pc=0x0c06874au; return 0; }
r[0]+=0xffffffe4u;
goto P_0c06874c;
P_0c06874c: /* original f6e6, guest PC 0x0c06874c */
if(!s->budget--) { s->failed_pc=0x0c06874cu; return 0; }
vf3_matrix_load(s,ram,6,r[14]+r[0]);
goto P_0c06874e;
P_0c06874e: /* original e004, guest PC 0x0c06874e */
if(!s->budget--) { s->failed_pc=0x0c06874eu; return 0; }
r[0]=0x00000004u;
goto P_0c068750;
P_0c068750: /* original f9d6, guest PC 0x0c068750 */
if(!s->budget--) { s->failed_pc=0x0c068750u; return 0; }
vf3_matrix_load(s,ram,9,r[13]+r[0]);
goto P_0c068752;
P_0c068752: /* original f862, guest PC 0x0c068752 */
if(!s->budget--) { s->failed_pc=0x0c068752u; return 0; }
fr[8]=vf3_fpu_binary(fr[8],fr[6],r[18],'*');
goto P_0c068754;
P_0c068754: /* original f853, guest PC 0x0c068754 */
if(!s->budget--) { s->failed_pc=0x0c068754u; return 0; }
fr[8]=vf3_fpu_binary(fr[8],fr[5],r[18],'/');
goto P_0c068756;
P_0c068756: /* original f870, guest PC 0x0c068756 */
if(!s->budget--) { s->failed_pc=0x0c068756u; return 0; }
fr[8]=vf3_fpu_binary(fr[8],fr[7],r[18],'+');
goto P_0c068758;
P_0c068758: /* original f746, guest PC 0x0c068758 */
if(!s->budget--) { s->failed_pc=0x0c068758u; return 0; }
vf3_matrix_load(s,ram,7,r[4]+r[0]);
goto P_0c06875a;
P_0c06875a: /* original e008, guest PC 0x0c06875a */
if(!s->budget--) { s->failed_pc=0x0c06875au; return 0; }
r[0]=0x00000008u;
goto P_0c06875c;
P_0c06875c: /* original f971, guest PC 0x0c06875c */
if(!s->budget--) { s->failed_pc=0x0c06875cu; return 0; }
fr[9]=vf3_fpu_binary(fr[9],fr[7],r[18],'-');
goto P_0c06875e;
P_0c06875e: /* original f37c, guest PC 0x0c06875e */
if(!s->budget--) { s->failed_pc=0x0c06875eu; return 0; }
vf3_matrix_move(s,3,7);
goto P_0c068760;
P_0c068760: /* original fad6, guest PC 0x0c068760 */
if(!s->budget--) { s->failed_pc=0x0c068760u; return 0; }
vf3_matrix_load(s,ram,10,r[13]+r[0]);
goto P_0c068762;
P_0c068762: /* original f962, guest PC 0x0c068762 */
if(!s->budget--) { s->failed_pc=0x0c068762u; return 0; }
fr[9]=vf3_fpu_binary(fr[9],fr[6],r[18],'*');
goto P_0c068764;
P_0c068764: /* original f953, guest PC 0x0c068764 */
if(!s->budget--) { s->failed_pc=0x0c068764u; return 0; }
fr[9]=vf3_fpu_binary(fr[9],fr[5],r[18],'/');
goto P_0c068766;
P_0c068766: /* original f79c, guest PC 0x0c068766 */
if(!s->budget--) { s->failed_pc=0x0c068766u; return 0; }
vf3_matrix_move(s,7,9);
goto P_0c068768;
P_0c068768: /* original f730, guest PC 0x0c068768 */
if(!s->budget--) { s->failed_pc=0x0c068768u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[3],r[18],'+');
goto P_0c06876a;
P_0c06876a: /* original f946, guest PC 0x0c06876a */
if(!s->budget--) { s->failed_pc=0x0c06876au; return 0; }
vf3_matrix_load(s,ram,9,r[4]+r[0]);
goto P_0c06876c;
P_0c06876c: /* original e00c, guest PC 0x0c06876c */
if(!s->budget--) { s->failed_pc=0x0c06876cu; return 0; }
r[0]=0x0000000cu;
goto P_0c06876e;
P_0c06876e: /* original fbd6, guest PC 0x0c06876e */
if(!s->budget--) { s->failed_pc=0x0c06876eu; return 0; }
vf3_matrix_load(s,ram,11,r[13]+r[0]);
goto P_0c068770;
P_0c068770: /* original fa91, guest PC 0x0c068770 */
if(!s->budget--) { s->failed_pc=0x0c068770u; return 0; }
fr[10]=vf3_fpu_binary(fr[10],fr[9],r[18],'-');
goto P_0c068772;
P_0c068772: /* original f39c, guest PC 0x0c068772 */
if(!s->budget--) { s->failed_pc=0x0c068772u; return 0; }
vf3_matrix_move(s,3,9);
goto P_0c068774;
P_0c068774: /* original fa62, guest PC 0x0c068774 */
if(!s->budget--) { s->failed_pc=0x0c068774u; return 0; }
fr[10]=vf3_fpu_binary(fr[10],fr[6],r[18],'*');
goto P_0c068776;
P_0c068776: /* original fa53, guest PC 0x0c068776 */
if(!s->budget--) { s->failed_pc=0x0c068776u; return 0; }
fr[10]=vf3_fpu_binary(fr[10],fr[5],r[18],'/');
goto P_0c068778;
P_0c068778: /* original f9ac, guest PC 0x0c068778 */
if(!s->budget--) { s->failed_pc=0x0c068778u; return 0; }
vf3_matrix_move(s,9,10);
goto P_0c06877a;
P_0c06877a: /* original f930, guest PC 0x0c06877a */
if(!s->budget--) { s->failed_pc=0x0c06877au; return 0; }
fr[9]=vf3_fpu_binary(fr[9],fr[3],r[18],'+');
goto P_0c06877c;
P_0c06877c: /* original fa46, guest PC 0x0c06877c */
if(!s->budget--) { s->failed_pc=0x0c06877cu; return 0; }
vf3_matrix_load(s,ram,10,r[4]+r[0]);
goto P_0c06877e;
P_0c06877e: /* original fba1, guest PC 0x0c06877e */
if(!s->budget--) { s->failed_pc=0x0c06877eu; return 0; }
fr[11]=vf3_fpu_binary(fr[11],fr[10],r[18],'-');
goto P_0c068780;
P_0c068780: /* original fb62, guest PC 0x0c068780 */
if(!s->budget--) { s->failed_pc=0x0c068780u; return 0; }
fr[11]=vf3_fpu_binary(fr[11],fr[6],r[18],'*');
goto P_0c068782;
P_0c068782: /* original e010, guest PC 0x0c068782 */
if(!s->budget--) { s->failed_pc=0x0c068782u; return 0; }
r[0]=0x00000010u;
goto P_0c068784;
P_0c068784: /* original f3d6, guest PC 0x0c068784 */
if(!s->budget--) { s->failed_pc=0x0c068784u; return 0; }
vf3_matrix_load(s,ram,3,r[13]+r[0]);
goto P_0c068786;
P_0c068786: /* original 2558, guest PC 0x0c068786 */
if(!s->budget--) { s->failed_pc=0x0c068786u; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[5])==0)!=0);
goto P_0c068788;
P_0c068788: /* original fb53, guest PC 0x0c068788 */
if(!s->budget--) { s->failed_pc=0x0c068788u; return 0; }
fr[11]=vf3_fpu_binary(fr[11],fr[5],r[18],'/');
goto P_0c06878a;
P_0c06878a: /* original fba0, guest PC 0x0c06878a */
if(!s->budget--) { s->failed_pc=0x0c06878au; return 0; }
fr[11]=vf3_fpu_binary(fr[11],fr[10],r[18],'+');
goto P_0c06878c;
P_0c06878c: /* original fa46, guest PC 0x0c06878c */
if(!s->budget--) { s->failed_pc=0x0c06878cu; return 0; }
vf3_matrix_load(s,ram,10,r[4]+r[0]);
goto P_0c06878e;
P_0c06878e: /* original e010, guest PC 0x0c06878e */
if(!s->budget--) { s->failed_pc=0x0c06878eu; return 0; }
r[0]=0x00000010u;
goto P_0c068790;
P_0c068790: /* original ff37, guest PC 0x0c068790 */
if(!s->budget--) { s->failed_pc=0x0c068790u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c068792;
P_0c068792: /* original f3a1, guest PC 0x0c068792 */
if(!s->budget--) { s->failed_pc=0x0c068792u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[10],r[18],'-');
goto P_0c068794;
P_0c068794: /* original e008, guest PC 0x0c068794 */
if(!s->budget--) { s->failed_pc=0x0c068794u; return 0; }
r[0]=0x00000008u;
goto P_0c068796;
P_0c068796: /* original ff37, guest PC 0x0c068796 */
if(!s->budget--) { s->failed_pc=0x0c068796u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c068798;
P_0c068798: /* original e034, guest PC 0x0c068798 */
if(!s->budget--) { s->failed_pc=0x0c068798u; return 0; }
r[0]=0x00000034u;
goto P_0c06879a;
P_0c06879a: /* original ff3c, guest PC 0x0c06879a */
if(!s->budget--) { s->failed_pc=0x0c06879au; return 0; }
vf3_matrix_move(s,15,3);
goto P_0c06879c;
P_0c06879c: /* original ff62, guest PC 0x0c06879c */
if(!s->budget--) { s->failed_pc=0x0c06879cu; return 0; }
fr[15]=vf3_fpu_binary(fr[15],fr[6],r[18],'*');
goto P_0c06879e;
P_0c06879e: /* original ff53, guest PC 0x0c06879e */
if(!s->budget--) { s->failed_pc=0x0c06879eu; return 0; }
fr[15]=vf3_fpu_binary(fr[15],fr[5],r[18],'/');
goto P_0c0687a0;
P_0c0687a0: /* original ffa0, guest PC 0x0c0687a0 */
if(!s->budget--) { s->failed_pc=0x0c0687a0u; return 0; }
fr[15]=vf3_fpu_binary(fr[15],fr[10],r[18],'+');
goto P_0c0687a2;
P_0c0687a2: /* original fff7, guest PC 0x0c0687a2 */
if(!s->budget--) { s->failed_pc=0x0c0687a2u; return 0; }
vf3_matrix_store(s,ram,15,r[15]+r[0]);
goto P_0c0687a4;
P_0c0687a4: /* original e014, guest PC 0x0c0687a4 */
if(!s->budget--) { s->failed_pc=0x0c0687a4u; return 0; }
r[0]=0x00000014u;
goto P_0c0687a6;
P_0c0687a6: /* original f3d6, guest PC 0x0c0687a6 */
if(!s->budget--) { s->failed_pc=0x0c0687a6u; return 0; }
vf3_matrix_load(s,ram,3,r[13]+r[0]);
goto P_0c0687a8;
P_0c0687a8: /* original fa46, guest PC 0x0c0687a8 */
if(!s->budget--) { s->failed_pc=0x0c0687a8u; return 0; }
vf3_matrix_load(s,ram,10,r[4]+r[0]);
goto P_0c0687aa;
P_0c0687aa: /* original e038, guest PC 0x0c0687aa */
if(!s->budget--) { s->failed_pc=0x0c0687aau; return 0; }
r[0]=0x00000038u;
goto P_0c0687ac;
P_0c0687ac: /* original ff37, guest PC 0x0c0687ac */
if(!s->budget--) { s->failed_pc=0x0c0687acu; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0687ae;
P_0c0687ae: /* original e040, guest PC 0x0c0687ae */
if(!s->budget--) { s->failed_pc=0x0c0687aeu; return 0; }
r[0]=0x00000040u;
goto P_0c0687b0;
P_0c0687b0: /* original f3a1, guest PC 0x0c0687b0 */
if(!s->budget--) { s->failed_pc=0x0c0687b0u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[10],r[18],'-');
goto P_0c0687b2;
P_0c0687b2: /* original ff37, guest PC 0x0c0687b2 */
if(!s->budget--) { s->failed_pc=0x0c0687b2u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0687b4;
P_0c0687b4: /* original f26c, guest PC 0x0c0687b4 */
if(!s->budget--) { s->failed_pc=0x0c0687b4u; return 0; }
vf3_matrix_move(s,2,6);
goto P_0c0687b6;
P_0c0687b6: /* original f63c, guest PC 0x0c0687b6 */
if(!s->budget--) { s->failed_pc=0x0c0687b6u; return 0; }
vf3_matrix_move(s,6,3);
goto P_0c0687b8;
P_0c0687b8: /* original f622, guest PC 0x0c0687b8 */
if(!s->budget--) { s->failed_pc=0x0c0687b8u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[2],r[18],'*');
goto P_0c0687ba;
P_0c0687ba: /* original f653, guest PC 0x0c0687ba */
if(!s->budget--) { s->failed_pc=0x0c0687bau; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[5],r[18],'/');
goto P_0c0687bc;
P_0c0687bc: /* original f56c, guest PC 0x0c0687bc */
if(!s->budget--) { s->failed_pc=0x0c0687bcu; return 0; }
vf3_matrix_move(s,5,6);
goto P_0c0687be;
P_0c0687be: /* original 8d02, guest PC 0x0c0687be */
if(!s->budget--) { s->failed_pc=0x0c0687beu; return 0; }
cond=r[17]&1u;
fr[5]=vf3_fpu_binary(fr[5],fr[10],r[18],'+');
if(cond) { goto P_0c0687c6; }
goto P_0c0687c2;
P_0c0687c0: /* original f5a0, guest PC 0x0c0687c0 */
if(!s->budget--) { s->failed_pc=0x0c0687c0u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[10],r[18],'+');
goto P_0c0687c2;
P_0c0687c2: /* original a1e9, guest PC 0x0c0687c2 */
if(!s->budget--) { s->failed_pc=0x0c0687c2u; return 0; }
goto P_0c068b98;
P_0c0687c4: /* original 0009, guest PC 0x0c0687c4 */
if(!s->budget--) { s->failed_pc=0x0c0687c4u; return 0; }
goto P_0c0687c6;
P_0c0687c6: /* original e010, guest PC 0x0c0687c6 */
if(!s->budget--) { s->failed_pc=0x0c0687c6u; return 0; }
r[0]=0x00000010u;
goto P_0c0687c8;
P_0c0687c8: /* original fe87, guest PC 0x0c0687c8 */
if(!s->budget--) { s->failed_pc=0x0c0687c8u; return 0; }
vf3_matrix_store(s,ram,8,r[14]+r[0]);
goto P_0c0687ca;
P_0c0687ca: /* original e014, guest PC 0x0c0687ca */
if(!s->budget--) { s->failed_pc=0x0c0687cau; return 0; }
r[0]=0x00000014u;
goto P_0c0687cc;
P_0c0687cc: /* original fe77, guest PC 0x0c0687cc */
if(!s->budget--) { s->failed_pc=0x0c0687ccu; return 0; }
vf3_matrix_store(s,ram,7,r[14]+r[0]);
goto P_0c0687ce;
P_0c0687ce: /* original e018, guest PC 0x0c0687ce */
if(!s->budget--) { s->failed_pc=0x0c0687ceu; return 0; }
r[0]=0x00000018u;
goto P_0c0687d0;
P_0c0687d0: /* original fe97, guest PC 0x0c0687d0 */
if(!s->budget--) { s->failed_pc=0x0c0687d0u; return 0; }
vf3_matrix_store(s,ram,9,r[14]+r[0]);
goto P_0c0687d2;
P_0c0687d2: /* original 9007, guest PC 0x0c0687d2 */
if(!s->budget--) { s->failed_pc=0x0c0687d2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0687e4u,2);
goto P_0c0687d4;
P_0c0687d4: /* original feb7, guest PC 0x0c0687d4 */
if(!s->budget--) { s->failed_pc=0x0c0687d4u; return 0; }
vf3_matrix_store(s,ram,11,r[14]+r[0]);
goto P_0c0687d6;
P_0c0687d6: /* original e034, guest PC 0x0c0687d6 */
if(!s->budget--) { s->failed_pc=0x0c0687d6u; return 0; }
r[0]=0x00000034u;
goto P_0c0687d8;
P_0c0687d8: /* original f3f6, guest PC 0x0c0687d8 */
if(!s->budget--) { s->failed_pc=0x0c0687d8u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0687da;
P_0c0687da: /* original 9005, guest PC 0x0c0687da */
if(!s->budget--) { s->failed_pc=0x0c0687dau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0687e8u,2);
goto P_0c0687dc;
P_0c0687dc: /* original fe37, guest PC 0x0c0687dc */
if(!s->budget--) { s->failed_pc=0x0c0687dcu; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0687de;
P_0c0687de: /* original 7004, guest PC 0x0c0687de */
if(!s->budget--) { s->failed_pc=0x0c0687deu; return 0; }
r[0]+=0x00000004u;
goto P_0c0687e0;
P_0c0687e0: /* original a1da, guest PC 0x0c0687e0 */
if(!s->budget--) { s->failed_pc=0x0c0687e0u; return 0; }
vf3_matrix_store(s,ram,5,r[14]+r[0]);
goto P_0c068b98;
P_0c0687e2: /* original fe57, guest PC 0x0c0687e2 */
if(!s->budget--) { s->failed_pc=0x0c0687e2u; return 0; }
vf3_matrix_store(s,ram,5,r[14]+r[0]);
return vf3_matrix_family(0x0c0687e4u,s,ram);
P_0c0687ea: /* original e034, guest PC 0x0c0687ea */
if(!s->budget--) { s->failed_pc=0x0c0687eau; return 0; }
r[0]=0x00000034u;
goto P_0c0687ec;
P_0c0687ec: /* original 024d, guest PC 0x0c0687ec */
if(!s->budget--) { s->failed_pc=0x0c0687ecu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c0687ee;
P_0c0687ee: /* original 854c, guest PC 0x0c0687ee */
if(!s->budget--) { s->failed_pc=0x0c0687eeu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+24,2);
goto P_0c0687f0;
P_0c0687f0: /* original 622d, guest PC 0x0c0687f0 */
if(!s->budget--) { s->failed_pc=0x0c0687f0u; return 0; }
r[2]=r[2]&65535u;
goto P_0c0687f2;
P_0c0687f2: /* original 600d, guest PC 0x0c0687f2 */
if(!s->budget--) { s->failed_pc=0x0c0687f2u; return 0; }
r[0]=r[0]&65535u;
goto P_0c0687f4;
P_0c0687f4: /* original 3208, guest PC 0x0c0687f4 */
if(!s->budget--) { s->failed_pc=0x0c0687f4u; return 0; }
r[2]-=r[0];
goto P_0c0687f6;
P_0c0687f6: /* original 90b6, guest PC 0x0c0687f6 */
if(!s->budget--) { s->failed_pc=0x0c0687f6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c068966u,2);
goto P_0c0687f8;
P_0c0687f8: /* original 425a, guest PC 0x0c0687f8 */
if(!s->budget--) { s->failed_pc=0x0c0687f8u; return 0; }
r[53]=r[2];
goto P_0c0687fa;
P_0c0687fa: /* original f32d, guest PC 0x0c0687fa */
if(!s->budget--) { s->failed_pc=0x0c0687fau; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c0687fc;
P_0c0687fc: /* original fe37, guest PC 0x0c0687fc */
if(!s->budget--) { s->failed_pc=0x0c0687fcu; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0687fe;
P_0c0687fe: /* original 70e4, guest PC 0x0c0687fe */
if(!s->budget--) { s->failed_pc=0x0c0687feu; return 0; }
r[0]+=0xffffffe4u;
goto P_0c068800;
P_0c068800: /* original f45c, guest PC 0x0c068800 */
if(!s->budget--) { s->failed_pc=0x0c068800u; return 0; }
vf3_matrix_move(s,4,5);
goto P_0c068802;
P_0c068802: /* original fe47, guest PC 0x0c068802 */
if(!s->budget--) { s->failed_pc=0x0c068802u; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c068804;
P_0c068804: /* original 7020, guest PC 0x0c068804 */
if(!s->budget--) { s->failed_pc=0x0c068804u; return 0; }
r[0]+=0x00000020u;
goto P_0c068806;
P_0c068806: /* original 06ec, guest PC 0x0c068806 */
if(!s->budget--) { s->failed_pc=0x0c068806u; return 0; }
r[6]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c068808;
P_0c068808: /* original c759, guest PC 0x0c068808 */
if(!s->budget--) { s->failed_pc=0x0c068808u; return 0; }
r[0]=0x0c068970u;
goto P_0c06880a;
P_0c06880a: /* original 2668, guest PC 0x0c06880a */
if(!s->budget--) { s->failed_pc=0x0c06880au; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[6])==0)!=0);
goto P_0c06880c;
P_0c06880c: /* original 8d51, guest PC 0x0c06880c */
if(!s->budget--) { s->failed_pc=0x0c06880cu; return 0; }
cond=r[17]&1u;
vf3_matrix_load(s,ram,6,r[0]);
if(cond) { goto P_0c0688b2; }
goto P_0c068810;
P_0c06880e: /* original f608, guest PC 0x0c06880e */
if(!s->budget--) { s->failed_pc=0x0c06880eu; return 0; }
vf3_matrix_load(s,ram,6,r[0]);
goto P_0c068810;
P_0c068810: /* original 6d43, guest PC 0x0c068810 */
if(!s->budget--) { s->failed_pc=0x0c068810u; return 0; }
r[13]=r[4];
goto P_0c068812;
P_0c068812: /* original e01a, guest PC 0x0c068812 */
if(!s->budget--) { s->failed_pc=0x0c068812u; return 0; }
r[0]=0x0000001au;
goto P_0c068814;
P_0c068814: /* original 7de4, guest PC 0x0c068814 */
if(!s->budget--) { s->failed_pc=0x0c068814u; return 0; }
r[13]+=0xffffffe4u;
goto P_0c068816;
P_0c068816: /* original 06dc, guest PC 0x0c068816 */
if(!s->budget--) { s->failed_pc=0x0c068816u; return 0; }
r[6]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+r[0],1);
goto P_0c068818;
P_0c068818: /* original 666c, guest PC 0x0c068818 */
if(!s->budget--) { s->failed_pc=0x0c068818u; return 0; }
r[6]=r[6]&255u;
goto P_0c06881a;
P_0c06881a: /* original 2668, guest PC 0x0c06881a */
if(!s->budget--) { s->failed_pc=0x0c06881au; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[6])==0)!=0);
goto P_0c06881c;
P_0c06881c: /* original 8949, guest PC 0x0c06881c */
if(!s->budget--) { s->failed_pc=0x0c06881cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0688b2; }
goto P_0c06881e;
P_0c06881e: /* original 6643, guest PC 0x0c06881e */
if(!s->budget--) { s->failed_pc=0x0c06881eu; return 0; }
r[6]=r[4];
goto P_0c068820;
P_0c068820: /* original 761c, guest PC 0x0c068820 */
if(!s->budget--) { s->failed_pc=0x0c068820u; return 0; }
r[6]+=0x0000001cu;
goto P_0c068822;
P_0c068822: /* original 856c, guest PC 0x0c068822 */
if(!s->budget--) { s->failed_pc=0x0c068822u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[6]+24,2);
goto P_0c068824;
P_0c068824: /* original f46c, guest PC 0x0c068824 */
if(!s->budget--) { s->failed_pc=0x0c068824u; return 0; }
vf3_matrix_move(s,4,6);
goto P_0c068826;
P_0c068826: /* original 630d, guest PC 0x0c068826 */
if(!s->budget--) { s->failed_pc=0x0c068826u; return 0; }
r[3]=r[0]&65535u;
goto P_0c068828;
P_0c068828: /* original 854c, guest PC 0x0c068828 */
if(!s->budget--) { s->failed_pc=0x0c068828u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+24,2);
goto P_0c06882a;
P_0c06882a: /* original f848, guest PC 0x0c06882a */
if(!s->budget--) { s->failed_pc=0x0c06882au; return 0; }
vf3_matrix_load(s,ram,8,r[4]);
goto P_0c06882c;
P_0c06882c: /* original 600d, guest PC 0x0c06882c */
if(!s->budget--) { s->failed_pc=0x0c06882cu; return 0; }
r[0]=r[0]&65535u;
goto P_0c06882e;
P_0c06882e: /* original fb68, guest PC 0x0c06882e */
if(!s->budget--) { s->failed_pc=0x0c06882eu; return 0; }
vf3_matrix_load(s,ram,11,r[6]);
goto P_0c068830;
P_0c068830: /* original 3308, guest PC 0x0c068830 */
if(!s->budget--) { s->failed_pc=0x0c068830u; return 0; }
r[3]-=r[0];
goto P_0c068832;
P_0c068832: /* original 435a, guest PC 0x0c068832 */
if(!s->budget--) { s->failed_pc=0x0c068832u; return 0; }
r[53]=r[3];
goto P_0c068834;
P_0c068834: /* original e004, guest PC 0x0c068834 */
if(!s->budget--) { s->failed_pc=0x0c068834u; return 0; }
r[0]=0x00000004u;
goto P_0c068836;
P_0c068836: /* original f946, guest PC 0x0c068836 */
if(!s->budget--) { s->failed_pc=0x0c068836u; return 0; }
vf3_matrix_load(s,ram,9,r[4]+r[0]);
goto P_0c068838;
P_0c068838: /* original e008, guest PC 0x0c068838 */
if(!s->budget--) { s->failed_pc=0x0c068838u; return 0; }
r[0]=0x00000008u;
goto P_0c06883a;
P_0c06883a: /* original f746, guest PC 0x0c06883a */
if(!s->budget--) { s->failed_pc=0x0c06883au; return 0; }
vf3_matrix_load(s,ram,7,r[4]+r[0]);
goto P_0c06883c;
P_0c06883c: /* original e004, guest PC 0x0c06883c */
if(!s->budget--) { s->failed_pc=0x0c06883cu; return 0; }
r[0]=0x00000004u;
goto P_0c06883e;
P_0c06883e: /* original f32d, guest PC 0x0c06883e */
if(!s->budget--) { s->failed_pc=0x0c06883eu; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c068840;
P_0c068840: /* original fa66, guest PC 0x0c068840 */
if(!s->budget--) { s->failed_pc=0x0c068840u; return 0; }
vf3_matrix_load(s,ram,10,r[6]+r[0]);
goto P_0c068842;
P_0c068842: /* original e008, guest PC 0x0c068842 */
if(!s->budget--) { s->failed_pc=0x0c068842u; return 0; }
r[0]=0x00000008u;
goto P_0c068844;
P_0c068844: /* original f432, guest PC 0x0c068844 */
if(!s->budget--) { s->failed_pc=0x0c068844u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'*');
goto P_0c068846;
P_0c068846: /* original f366, guest PC 0x0c068846 */
if(!s->budget--) { s->failed_pc=0x0c068846u; return 0; }
vf3_matrix_load(s,ram,3,r[6]+r[0]);
goto P_0c068848;
P_0c068848: /* original e020, guest PC 0x0c068848 */
if(!s->budget--) { s->failed_pc=0x0c068848u; return 0; }
r[0]=0x00000020u;
goto P_0c06884a;
P_0c06884a: /* original ff37, guest PC 0x0c06884a */
if(!s->budget--) { s->failed_pc=0x0c06884au; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c06884c;
P_0c06884c: /* original e020, guest PC 0x0c06884c */
if(!s->budget--) { s->failed_pc=0x0c06884cu; return 0; }
r[0]=0x00000020u;
goto P_0c06884e;
P_0c06884e: /* original f38c, guest PC 0x0c06884e */
if(!s->budget--) { s->failed_pc=0x0c06884eu; return 0; }
vf3_matrix_move(s,3,8);
goto P_0c068850;
P_0c068850: /* original f8bc, guest PC 0x0c068850 */
if(!s->budget--) { s->failed_pc=0x0c068850u; return 0; }
vf3_matrix_move(s,8,11);
goto P_0c068852;
P_0c068852: /* original f831, guest PC 0x0c068852 */
if(!s->budget--) { s->failed_pc=0x0c068852u; return 0; }
fr[8]=vf3_fpu_binary(fr[8],fr[3],r[18],'-');
goto P_0c068854;
P_0c068854: /* original f39c, guest PC 0x0c068854 */
if(!s->budget--) { s->failed_pc=0x0c068854u; return 0; }
vf3_matrix_move(s,3,9);
goto P_0c068856;
P_0c068856: /* original f9ac, guest PC 0x0c068856 */
if(!s->budget--) { s->failed_pc=0x0c068856u; return 0; }
vf3_matrix_move(s,9,10);
goto P_0c068858;
P_0c068858: /* original f931, guest PC 0x0c068858 */
if(!s->budget--) { s->failed_pc=0x0c068858u; return 0; }
fr[9]=vf3_fpu_binary(fr[9],fr[3],r[18],'-');
goto P_0c06885a;
P_0c06885a: /* original f37c, guest PC 0x0c06885a */
if(!s->budget--) { s->failed_pc=0x0c06885au; return 0; }
vf3_matrix_move(s,3,7);
goto P_0c06885c;
P_0c06885c: /* original f7f6, guest PC 0x0c06885c */
if(!s->budget--) { s->failed_pc=0x0c06885cu; return 0; }
vf3_matrix_load(s,ram,7,r[15]+r[0]);
goto P_0c06885e;
P_0c06885e: /* original f843, guest PC 0x0c06885e */
if(!s->budget--) { s->failed_pc=0x0c06885eu; return 0; }
fr[8]=vf3_fpu_binary(fr[8],fr[4],r[18],'/');
goto P_0c068860;
P_0c068860: /* original 9082, guest PC 0x0c068860 */
if(!s->budget--) { s->failed_pc=0x0c068860u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c068968u,2);
goto P_0c068862;
P_0c068862: /* original f731, guest PC 0x0c068862 */
if(!s->budget--) { s->failed_pc=0x0c068862u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[3],r[18],'-');
goto P_0c068864;
P_0c068864: /* original f943, guest PC 0x0c068864 */
if(!s->budget--) { s->failed_pc=0x0c068864u; return 0; }
fr[9]=vf3_fpu_binary(fr[9],fr[4],r[18],'/');
goto P_0c068866;
P_0c068866: /* original f743, guest PC 0x0c068866 */
if(!s->budget--) { s->failed_pc=0x0c068866u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[4],r[18],'/');
goto P_0c068868;
P_0c068868: /* original fe87, guest PC 0x0c068868 */
if(!s->budget--) { s->failed_pc=0x0c068868u; return 0; }
vf3_matrix_store(s,ram,8,r[14]+r[0]);
goto P_0c06886a;
P_0c06886a: /* original 7004, guest PC 0x0c06886a */
if(!s->budget--) { s->failed_pc=0x0c06886au; return 0; }
r[0]+=0x00000004u;
goto P_0c06886c;
P_0c06886c: /* original fe97, guest PC 0x0c06886c */
if(!s->budget--) { s->failed_pc=0x0c06886cu; return 0; }
vf3_matrix_store(s,ram,9,r[14]+r[0]);
goto P_0c06886e;
P_0c06886e: /* original 7004, guest PC 0x0c06886e */
if(!s->budget--) { s->failed_pc=0x0c06886eu; return 0; }
r[0]+=0x00000004u;
goto P_0c068870;
P_0c068870: /* original fe77, guest PC 0x0c068870 */
if(!s->budget--) { s->failed_pc=0x0c068870u; return 0; }
vf3_matrix_store(s,ram,7,r[14]+r[0]);
goto P_0c068872;
P_0c068872: /* original e00c, guest PC 0x0c068872 */
if(!s->budget--) { s->failed_pc=0x0c068872u; return 0; }
r[0]=0x0000000cu;
goto P_0c068874;
P_0c068874: /* original f7d6, guest PC 0x0c068874 */
if(!s->budget--) { s->failed_pc=0x0c068874u; return 0; }
vf3_matrix_load(s,ram,7,r[13]+r[0]);
goto P_0c068876;
P_0c068876: /* original e010, guest PC 0x0c068876 */
if(!s->budget--) { s->failed_pc=0x0c068876u; return 0; }
r[0]=0x00000010u;
goto P_0c068878;
P_0c068878: /* original f8d6, guest PC 0x0c068878 */
if(!s->budget--) { s->failed_pc=0x0c068878u; return 0; }
vf3_matrix_load(s,ram,8,r[13]+r[0]);
goto P_0c06887a;
P_0c06887a: /* original e014, guest PC 0x0c06887a */
if(!s->budget--) { s->failed_pc=0x0c06887au; return 0; }
r[0]=0x00000014u;
goto P_0c06887c;
P_0c06887c: /* original f9d6, guest PC 0x0c06887c */
if(!s->budget--) { s->failed_pc=0x0c06887cu; return 0; }
vf3_matrix_load(s,ram,9,r[13]+r[0]);
goto P_0c06887e;
P_0c06887e: /* original e00c, guest PC 0x0c06887e */
if(!s->budget--) { s->failed_pc=0x0c06887eu; return 0; }
r[0]=0x0000000cu;
goto P_0c068880;
P_0c068880: /* original fb66, guest PC 0x0c068880 */
if(!s->budget--) { s->failed_pc=0x0c068880u; return 0; }
vf3_matrix_load(s,ram,11,r[6]+r[0]);
goto P_0c068882;
P_0c068882: /* original e010, guest PC 0x0c068882 */
if(!s->budget--) { s->failed_pc=0x0c068882u; return 0; }
r[0]=0x00000010u;
goto P_0c068884;
P_0c068884: /* original fa66, guest PC 0x0c068884 */
if(!s->budget--) { s->failed_pc=0x0c068884u; return 0; }
vf3_matrix_load(s,ram,10,r[6]+r[0]);
goto P_0c068886;
P_0c068886: /* original e014, guest PC 0x0c068886 */
if(!s->budget--) { s->failed_pc=0x0c068886u; return 0; }
r[0]=0x00000014u;
goto P_0c068888;
P_0c068888: /* original f366, guest PC 0x0c068888 */
if(!s->budget--) { s->failed_pc=0x0c068888u; return 0; }
vf3_matrix_load(s,ram,3,r[6]+r[0]);
goto P_0c06888a;
P_0c06888a: /* original e00c, guest PC 0x0c06888a */
if(!s->budget--) { s->failed_pc=0x0c06888au; return 0; }
r[0]=0x0000000cu;
goto P_0c06888c;
P_0c06888c: /* original ff37, guest PC 0x0c06888c */
if(!s->budget--) { s->failed_pc=0x0c06888cu; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c06888e;
P_0c06888e: /* original e00c, guest PC 0x0c06888e */
if(!s->budget--) { s->failed_pc=0x0c06888eu; return 0; }
r[0]=0x0000000cu;
goto P_0c068890;
P_0c068890: /* original f37c, guest PC 0x0c068890 */
if(!s->budget--) { s->failed_pc=0x0c068890u; return 0; }
vf3_matrix_move(s,3,7);
goto P_0c068892;
P_0c068892: /* original f7bc, guest PC 0x0c068892 */
if(!s->budget--) { s->failed_pc=0x0c068892u; return 0; }
vf3_matrix_move(s,7,11);
goto P_0c068894;
P_0c068894: /* original f731, guest PC 0x0c068894 */
if(!s->budget--) { s->failed_pc=0x0c068894u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[3],r[18],'-');
goto P_0c068896;
P_0c068896: /* original f38c, guest PC 0x0c068896 */
if(!s->budget--) { s->failed_pc=0x0c068896u; return 0; }
vf3_matrix_move(s,3,8);
goto P_0c068898;
P_0c068898: /* original f8ac, guest PC 0x0c068898 */
if(!s->budget--) { s->failed_pc=0x0c068898u; return 0; }
vf3_matrix_move(s,8,10);
goto P_0c06889a;
P_0c06889a: /* original f831, guest PC 0x0c06889a */
if(!s->budget--) { s->failed_pc=0x0c06889au; return 0; }
fr[8]=vf3_fpu_binary(fr[8],fr[3],r[18],'-');
goto P_0c06889c;
P_0c06889c: /* original f39c, guest PC 0x0c06889c */
if(!s->budget--) { s->failed_pc=0x0c06889cu; return 0; }
vf3_matrix_move(s,3,9);
goto P_0c06889e;
P_0c06889e: /* original f9f6, guest PC 0x0c06889e */
if(!s->budget--) { s->failed_pc=0x0c06889eu; return 0; }
vf3_matrix_load(s,ram,9,r[15]+r[0]);
goto P_0c0688a0;
P_0c0688a0: /* original f843, guest PC 0x0c0688a0 */
if(!s->budget--) { s->failed_pc=0x0c0688a0u; return 0; }
fr[8]=vf3_fpu_binary(fr[8],fr[4],r[18],'/');
goto P_0c0688a2;
P_0c0688a2: /* original f743, guest PC 0x0c0688a2 */
if(!s->budget--) { s->failed_pc=0x0c0688a2u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[4],r[18],'/');
goto P_0c0688a4;
P_0c0688a4: /* original 9061, guest PC 0x0c0688a4 */
if(!s->budget--) { s->failed_pc=0x0c0688a4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06896au,2);
goto P_0c0688a6;
P_0c0688a6: /* original f931, guest PC 0x0c0688a6 */
if(!s->budget--) { s->failed_pc=0x0c0688a6u; return 0; }
fr[9]=vf3_fpu_binary(fr[9],fr[3],r[18],'-');
goto P_0c0688a8;
P_0c0688a8: /* original f943, guest PC 0x0c0688a8 */
if(!s->budget--) { s->failed_pc=0x0c0688a8u; return 0; }
fr[9]=vf3_fpu_binary(fr[9],fr[4],r[18],'/');
goto P_0c0688aa;
P_0c0688aa: /* original fe77, guest PC 0x0c0688aa */
if(!s->budget--) { s->failed_pc=0x0c0688aau; return 0; }
vf3_matrix_store(s,ram,7,r[14]+r[0]);
goto P_0c0688ac;
P_0c0688ac: /* original fe87, guest PC 0x0c0688ac */
if(!s->budget--) { s->failed_pc=0x0c0688acu; return 0; }
vf3_matrix_store(s,ram,8,r[14]+r[0]);
goto P_0c0688ae;
P_0c0688ae: /* original a00d, guest PC 0x0c0688ae */
if(!s->budget--) { s->failed_pc=0x0c0688aeu; return 0; }
vf3_matrix_store(s,ram,9,r[14]+r[0]);
goto P_0c0688cc;
P_0c0688b0: /* original fe97, guest PC 0x0c0688b0 */
if(!s->budget--) { s->failed_pc=0x0c0688b0u; return 0; }
vf3_matrix_store(s,ram,9,r[14]+r[0]);
goto P_0c0688b2;
P_0c0688b2: /* original 9059, guest PC 0x0c0688b2 */
if(!s->budget--) { s->failed_pc=0x0c0688b2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c068968u,2);
goto P_0c0688b4;
P_0c0688b4: /* original ff5c, guest PC 0x0c0688b4 */
if(!s->budget--) { s->failed_pc=0x0c0688b4u; return 0; }
vf3_matrix_move(s,15,5);
goto P_0c0688b6;
P_0c0688b6: /* original fef7, guest PC 0x0c0688b6 */
if(!s->budget--) { s->failed_pc=0x0c0688b6u; return 0; }
vf3_matrix_store(s,ram,15,r[14]+r[0]);
goto P_0c0688b8;
P_0c0688b8: /* original 7004, guest PC 0x0c0688b8 */
if(!s->budget--) { s->failed_pc=0x0c0688b8u; return 0; }
r[0]+=0x00000004u;
goto P_0c0688ba;
P_0c0688ba: /* original fef7, guest PC 0x0c0688ba */
if(!s->budget--) { s->failed_pc=0x0c0688bau; return 0; }
vf3_matrix_store(s,ram,15,r[14]+r[0]);
goto P_0c0688bc;
P_0c0688bc: /* original 7004, guest PC 0x0c0688bc */
if(!s->budget--) { s->failed_pc=0x0c0688bcu; return 0; }
r[0]+=0x00000004u;
goto P_0c0688be;
P_0c0688be: /* original fef7, guest PC 0x0c0688be */
if(!s->budget--) { s->failed_pc=0x0c0688beu; return 0; }
vf3_matrix_store(s,ram,15,r[14]+r[0]);
goto P_0c0688c0;
P_0c0688c0: /* original 7018, guest PC 0x0c0688c0 */
if(!s->budget--) { s->failed_pc=0x0c0688c0u; return 0; }
r[0]+=0x00000018u;
goto P_0c0688c2;
P_0c0688c2: /* original fef7, guest PC 0x0c0688c2 */
if(!s->budget--) { s->failed_pc=0x0c0688c2u; return 0; }
vf3_matrix_store(s,ram,15,r[14]+r[0]);
goto P_0c0688c4;
P_0c0688c4: /* original 7004, guest PC 0x0c0688c4 */
if(!s->budget--) { s->failed_pc=0x0c0688c4u; return 0; }
r[0]+=0x00000004u;
goto P_0c0688c6;
P_0c0688c6: /* original fef7, guest PC 0x0c0688c6 */
if(!s->budget--) { s->failed_pc=0x0c0688c6u; return 0; }
vf3_matrix_store(s,ram,15,r[14]+r[0]);
goto P_0c0688c8;
P_0c0688c8: /* original 7004, guest PC 0x0c0688c8 */
if(!s->budget--) { s->failed_pc=0x0c0688c8u; return 0; }
r[0]+=0x00000004u;
goto P_0c0688ca;
P_0c0688ca: /* original fef7, guest PC 0x0c0688ca */
if(!s->budget--) { s->failed_pc=0x0c0688cau; return 0; }
vf3_matrix_store(s,ram,15,r[14]+r[0]);
goto P_0c0688cc;
P_0c0688cc: /* original e036, guest PC 0x0c0688cc */
if(!s->budget--) { s->failed_pc=0x0c0688ccu; return 0; }
r[0]=0x00000036u;
goto P_0c0688ce;
P_0c0688ce: /* original 064c, guest PC 0x0c0688ce */
if(!s->budget--) { s->failed_pc=0x0c0688ceu; return 0; }
r[6]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c0688d0;
P_0c0688d0: /* original 666c, guest PC 0x0c0688d0 */
if(!s->budget--) { s->failed_pc=0x0c0688d0u; return 0; }
r[6]=r[6]&255u;
goto P_0c0688d2;
P_0c0688d2: /* original 2668, guest PC 0x0c0688d2 */
if(!s->budget--) { s->failed_pc=0x0c0688d2u; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[6])==0)!=0);
goto P_0c0688d4;
P_0c0688d4: /* original 894e, guest PC 0x0c0688d4 */
if(!s->budget--) { s->failed_pc=0x0c0688d4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c068974; }
goto P_0c0688d6;
P_0c0688d6: /* original 6743, guest PC 0x0c0688d6 */
if(!s->budget--) { s->failed_pc=0x0c0688d6u; return 0; }
r[7]=r[4];
goto P_0c0688d8;
P_0c0688d8: /* original 771c, guest PC 0x0c0688d8 */
if(!s->budget--) { s->failed_pc=0x0c0688d8u; return 0; }
r[7]+=0x0000001cu;
goto P_0c0688da;
P_0c0688da: /* original 857c, guest PC 0x0c0688da */
if(!s->budget--) { s->failed_pc=0x0c0688dau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[7]+24,2);
goto P_0c0688dc;
P_0c0688dc: /* original 6643, guest PC 0x0c0688dc */
if(!s->budget--) { s->failed_pc=0x0c0688dcu; return 0; }
r[6]=r[4];
goto P_0c0688de;
P_0c0688de: /* original 7638, guest PC 0x0c0688de */
if(!s->budget--) { s->failed_pc=0x0c0688deu; return 0; }
r[6]+=0x00000038u;
goto P_0c0688e0;
P_0c0688e0: /* original 6d0d, guest PC 0x0c0688e0 */
if(!s->budget--) { s->failed_pc=0x0c0688e0u; return 0; }
r[13]=r[0]&65535u;
goto P_0c0688e2;
P_0c0688e2: /* original 856c, guest PC 0x0c0688e2 */
if(!s->budget--) { s->failed_pc=0x0c0688e2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[6]+24,2);
goto P_0c0688e4;
P_0c0688e4: /* original 600d, guest PC 0x0c0688e4 */
if(!s->budget--) { s->failed_pc=0x0c0688e4u; return 0; }
r[0]=r[0]&65535u;
goto P_0c0688e6;
P_0c0688e6: /* original 6303, guest PC 0x0c0688e6 */
if(!s->budget--) { s->failed_pc=0x0c0688e6u; return 0; }
r[3]=r[0];
goto P_0c0688e8;
P_0c0688e8: /* original 33d8, guest PC 0x0c0688e8 */
if(!s->budget--) { s->failed_pc=0x0c0688e8u; return 0; }
r[3]-=r[13];
goto P_0c0688ea;
P_0c0688ea: /* original 6d33, guest PC 0x0c0688ea */
if(!s->budget--) { s->failed_pc=0x0c0688eau; return 0; }
r[13]=r[3];
goto P_0c0688ec;
P_0c0688ec: /* original 2f02, guest PC 0x0c0688ec */
if(!s->budget--) { s->failed_pc=0x0c0688ecu; return 0; }
write(ram,r[15],r[0],4);
goto P_0c0688ee;
P_0c0688ee: /* original 4d5a, guest PC 0x0c0688ee */
if(!s->budget--) { s->failed_pc=0x0c0688eeu; return 0; }
r[53]=r[13];
goto P_0c0688f0;
P_0c0688f0: /* original e004, guest PC 0x0c0688f0 */
if(!s->budget--) { s->failed_pc=0x0c0688f0u; return 0; }
r[0]=0x00000004u;
goto P_0c0688f2;
P_0c0688f2: /* original f46c, guest PC 0x0c0688f2 */
if(!s->budget--) { s->failed_pc=0x0c0688f2u; return 0; }
vf3_matrix_move(s,4,6);
goto P_0c0688f4;
P_0c0688f4: /* original f676, guest PC 0x0c0688f4 */
if(!s->budget--) { s->failed_pc=0x0c0688f4u; return 0; }
vf3_matrix_load(s,ram,6,r[7]+r[0]);
goto P_0c0688f6;
P_0c0688f6: /* original e008, guest PC 0x0c0688f6 */
if(!s->budget--) { s->failed_pc=0x0c0688f6u; return 0; }
r[0]=0x00000008u;
goto P_0c0688f8;
P_0c0688f8: /* original f32d, guest PC 0x0c0688f8 */
if(!s->budget--) { s->failed_pc=0x0c0688f8u; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c0688fa;
P_0c0688fa: /* original f568, guest PC 0x0c0688fa */
if(!s->budget--) { s->failed_pc=0x0c0688fau; return 0; }
vf3_matrix_load(s,ram,5,r[6]);
goto P_0c0688fc;
P_0c0688fc: /* original f776, guest PC 0x0c0688fc */
if(!s->budget--) { s->failed_pc=0x0c0688fcu; return 0; }
vf3_matrix_load(s,ram,7,r[7]+r[0]);
goto P_0c0688fe;
P_0c0688fe: /* original e004, guest PC 0x0c0688fe */
if(!s->budget--) { s->failed_pc=0x0c0688feu; return 0; }
r[0]=0x00000004u;
goto P_0c068900;
P_0c068900: /* original f966, guest PC 0x0c068900 */
if(!s->budget--) { s->failed_pc=0x0c068900u; return 0; }
vf3_matrix_load(s,ram,9,r[6]+r[0]);
goto P_0c068902;
P_0c068902: /* original e008, guest PC 0x0c068902 */
if(!s->budget--) { s->failed_pc=0x0c068902u; return 0; }
r[0]=0x00000008u;
goto P_0c068904;
P_0c068904: /* original f866, guest PC 0x0c068904 */
if(!s->budget--) { s->failed_pc=0x0c068904u; return 0; }
vf3_matrix_load(s,ram,8,r[6]+r[0]);
goto P_0c068906;
P_0c068906: /* original f432, guest PC 0x0c068906 */
if(!s->budget--) { s->failed_pc=0x0c068906u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'*');
goto P_0c068908;
P_0c068908: /* original f378, guest PC 0x0c068908 */
if(!s->budget--) { s->failed_pc=0x0c068908u; return 0; }
vf3_matrix_load(s,ram,3,r[7]);
goto P_0c06890a;
P_0c06890a: /* original f531, guest PC 0x0c06890a */
if(!s->budget--) { s->failed_pc=0x0c06890au; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[3],r[18],'-');
goto P_0c06890c;
P_0c06890c: /* original f36c, guest PC 0x0c06890c */
if(!s->budget--) { s->failed_pc=0x0c06890cu; return 0; }
vf3_matrix_move(s,3,6);
goto P_0c06890e;
P_0c06890e: /* original f69c, guest PC 0x0c06890e */
if(!s->budget--) { s->failed_pc=0x0c06890eu; return 0; }
vf3_matrix_move(s,6,9);
goto P_0c068910;
P_0c068910: /* original f631, guest PC 0x0c068910 */
if(!s->budget--) { s->failed_pc=0x0c068910u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[3],r[18],'-');
goto P_0c068912;
P_0c068912: /* original f37c, guest PC 0x0c068912 */
if(!s->budget--) { s->failed_pc=0x0c068912u; return 0; }
vf3_matrix_move(s,3,7);
goto P_0c068914;
P_0c068914: /* original f78c, guest PC 0x0c068914 */
if(!s->budget--) { s->failed_pc=0x0c068914u; return 0; }
vf3_matrix_move(s,7,8);
goto P_0c068916;
P_0c068916: /* original f543, guest PC 0x0c068916 */
if(!s->budget--) { s->failed_pc=0x0c068916u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[4],r[18],'/');
goto P_0c068918;
P_0c068918: /* original 9028, guest PC 0x0c068918 */
if(!s->budget--) { s->failed_pc=0x0c068918u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06896cu,2);
goto P_0c06891a;
P_0c06891a: /* original f731, guest PC 0x0c06891a */
if(!s->budget--) { s->failed_pc=0x0c06891au; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[3],r[18],'-');
goto P_0c06891c;
P_0c06891c: /* original f643, guest PC 0x0c06891c */
if(!s->budget--) { s->failed_pc=0x0c06891cu; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[4],r[18],'/');
goto P_0c06891e;
P_0c06891e: /* original f743, guest PC 0x0c06891e */
if(!s->budget--) { s->failed_pc=0x0c06891eu; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[4],r[18],'/');
goto P_0c068920;
P_0c068920: /* original fe57, guest PC 0x0c068920 */
if(!s->budget--) { s->failed_pc=0x0c068920u; return 0; }
vf3_matrix_store(s,ram,5,r[14]+r[0]);
goto P_0c068922;
P_0c068922: /* original 7004, guest PC 0x0c068922 */
if(!s->budget--) { s->failed_pc=0x0c068922u; return 0; }
r[0]+=0x00000004u;
goto P_0c068924;
P_0c068924: /* original fe67, guest PC 0x0c068924 */
if(!s->budget--) { s->failed_pc=0x0c068924u; return 0; }
vf3_matrix_store(s,ram,6,r[14]+r[0]);
goto P_0c068926;
P_0c068926: /* original 7004, guest PC 0x0c068926 */
if(!s->budget--) { s->failed_pc=0x0c068926u; return 0; }
r[0]+=0x00000004u;
goto P_0c068928;
P_0c068928: /* original fe77, guest PC 0x0c068928 */
if(!s->budget--) { s->failed_pc=0x0c068928u; return 0; }
vf3_matrix_store(s,ram,7,r[14]+r[0]);
goto P_0c06892a;
P_0c06892a: /* original e00c, guest PC 0x0c06892a */
if(!s->budget--) { s->failed_pc=0x0c06892au; return 0; }
r[0]=0x0000000cu;
goto P_0c06892c;
P_0c06892c: /* original f346, guest PC 0x0c06892c */
if(!s->budget--) { s->failed_pc=0x0c06892cu; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c06892e;
P_0c06892e: /* original e010, guest PC 0x0c06892e */
if(!s->budget--) { s->failed_pc=0x0c06892eu; return 0; }
r[0]=0x00000010u;
goto P_0c068930;
P_0c068930: /* original f546, guest PC 0x0c068930 */
if(!s->budget--) { s->failed_pc=0x0c068930u; return 0; }
vf3_matrix_load(s,ram,5,r[4]+r[0]);
goto P_0c068932;
P_0c068932: /* original e014, guest PC 0x0c068932 */
if(!s->budget--) { s->failed_pc=0x0c068932u; return 0; }
r[0]=0x00000014u;
goto P_0c068934;
P_0c068934: /* original f646, guest PC 0x0c068934 */
if(!s->budget--) { s->failed_pc=0x0c068934u; return 0; }
vf3_matrix_load(s,ram,6,r[4]+r[0]);
goto P_0c068936;
P_0c068936: /* original e00c, guest PC 0x0c068936 */
if(!s->budget--) { s->failed_pc=0x0c068936u; return 0; }
r[0]=0x0000000cu;
goto P_0c068938;
P_0c068938: /* original f866, guest PC 0x0c068938 */
if(!s->budget--) { s->failed_pc=0x0c068938u; return 0; }
vf3_matrix_load(s,ram,8,r[6]+r[0]);
goto P_0c06893a;
P_0c06893a: /* original e010, guest PC 0x0c06893a */
if(!s->budget--) { s->failed_pc=0x0c06893au; return 0; }
r[0]=0x00000010u;
goto P_0c06893c;
P_0c06893c: /* original f966, guest PC 0x0c06893c */
if(!s->budget--) { s->failed_pc=0x0c06893cu; return 0; }
vf3_matrix_load(s,ram,9,r[6]+r[0]);
goto P_0c06893e;
P_0c06893e: /* original e014, guest PC 0x0c06893e */
if(!s->budget--) { s->failed_pc=0x0c06893eu; return 0; }
r[0]=0x00000014u;
goto P_0c068940;
P_0c068940: /* original f78c, guest PC 0x0c068940 */
if(!s->budget--) { s->failed_pc=0x0c068940u; return 0; }
vf3_matrix_move(s,7,8);
goto P_0c068942;
P_0c068942: /* original f731, guest PC 0x0c068942 */
if(!s->budget--) { s->failed_pc=0x0c068942u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[3],r[18],'-');
goto P_0c068944;
P_0c068944: /* original f35c, guest PC 0x0c068944 */
if(!s->budget--) { s->failed_pc=0x0c068944u; return 0; }
vf3_matrix_move(s,3,5);
goto P_0c068946;
P_0c068946: /* original f59c, guest PC 0x0c068946 */
if(!s->budget--) { s->failed_pc=0x0c068946u; return 0; }
vf3_matrix_move(s,5,9);
goto P_0c068948;
P_0c068948: /* original f531, guest PC 0x0c068948 */
if(!s->budget--) { s->failed_pc=0x0c068948u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[3],r[18],'-');
goto P_0c06894a;
P_0c06894a: /* original fa66, guest PC 0x0c06894a */
if(!s->budget--) { s->failed_pc=0x0c06894au; return 0; }
vf3_matrix_load(s,ram,10,r[6]+r[0]);
goto P_0c06894c;
P_0c06894c: /* original f743, guest PC 0x0c06894c */
if(!s->budget--) { s->failed_pc=0x0c06894cu; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[4],r[18],'/');
goto P_0c06894e;
P_0c06894e: /* original f36c, guest PC 0x0c06894e */
if(!s->budget--) { s->failed_pc=0x0c06894eu; return 0; }
vf3_matrix_move(s,3,6);
goto P_0c068950;
P_0c068950: /* original f6ac, guest PC 0x0c068950 */
if(!s->budget--) { s->failed_pc=0x0c068950u; return 0; }
vf3_matrix_move(s,6,10);
goto P_0c068952;
P_0c068952: /* original f631, guest PC 0x0c068952 */
if(!s->budget--) { s->failed_pc=0x0c068952u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[3],r[18],'-');
goto P_0c068954;
P_0c068954: /* original f543, guest PC 0x0c068954 */
if(!s->budget--) { s->failed_pc=0x0c068954u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[4],r[18],'/');
goto P_0c068956;
P_0c068956: /* original f643, guest PC 0x0c068956 */
if(!s->budget--) { s->failed_pc=0x0c068956u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[4],r[18],'/');
goto P_0c068958;
P_0c068958: /* original 9009, guest PC 0x0c068958 */
if(!s->budget--) { s->failed_pc=0x0c068958u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06896eu,2);
goto P_0c06895a;
P_0c06895a: /* original fe77, guest PC 0x0c06895a */
if(!s->budget--) { s->failed_pc=0x0c06895au; return 0; }
vf3_matrix_store(s,ram,7,r[14]+r[0]);
goto P_0c06895c;
P_0c06895c: /* original 7004, guest PC 0x0c06895c */
if(!s->budget--) { s->failed_pc=0x0c06895cu; return 0; }
r[0]+=0x00000004u;
goto P_0c06895e;
P_0c06895e: /* original fe57, guest PC 0x0c06895e */
if(!s->budget--) { s->failed_pc=0x0c06895eu; return 0; }
vf3_matrix_store(s,ram,5,r[14]+r[0]);
goto P_0c068960;
P_0c068960: /* original 7004, guest PC 0x0c068960 */
if(!s->budget--) { s->failed_pc=0x0c068960u; return 0; }
r[0]+=0x00000004u;
goto P_0c068962;
P_0c068962: /* original ae98, guest PC 0x0c068962 */
if(!s->budget--) { s->failed_pc=0x0c068962u; return 0; }
vf3_matrix_store(s,ram,6,r[14]+r[0]);
goto P_0c068696;
P_0c068964: /* original fe67, guest PC 0x0c068964 */
if(!s->budget--) { s->failed_pc=0x0c068964u; return 0; }
vf3_matrix_store(s,ram,6,r[14]+r[0]);
return vf3_matrix_family(0x0c068966u,s,ram);
P_0c068974: /* original 900c, guest PC 0x0c068974 */
if(!s->budget--) { s->failed_pc=0x0c068974u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c068990u,2);
goto P_0c068976;
P_0c068976: /* original ff5c, guest PC 0x0c068976 */
if(!s->budget--) { s->failed_pc=0x0c068976u; return 0; }
vf3_matrix_move(s,15,5);
goto P_0c068978;
P_0c068978: /* original fef7, guest PC 0x0c068978 */
if(!s->budget--) { s->failed_pc=0x0c068978u; return 0; }
vf3_matrix_store(s,ram,15,r[14]+r[0]);
goto P_0c06897a;
P_0c06897a: /* original 7004, guest PC 0x0c06897a */
if(!s->budget--) { s->failed_pc=0x0c06897au; return 0; }
r[0]+=0x00000004u;
goto P_0c06897c;
P_0c06897c: /* original fef7, guest PC 0x0c06897c */
if(!s->budget--) { s->failed_pc=0x0c06897cu; return 0; }
vf3_matrix_store(s,ram,15,r[14]+r[0]);
goto P_0c06897e;
P_0c06897e: /* original 7004, guest PC 0x0c06897e */
if(!s->budget--) { s->failed_pc=0x0c06897eu; return 0; }
r[0]+=0x00000004u;
goto P_0c068980;
P_0c068980: /* original fef7, guest PC 0x0c068980 */
if(!s->budget--) { s->failed_pc=0x0c068980u; return 0; }
vf3_matrix_store(s,ram,15,r[14]+r[0]);
goto P_0c068982;
P_0c068982: /* original 7018, guest PC 0x0c068982 */
if(!s->budget--) { s->failed_pc=0x0c068982u; return 0; }
r[0]+=0x00000018u;
goto P_0c068984;
P_0c068984: /* original fef7, guest PC 0x0c068984 */
if(!s->budget--) { s->failed_pc=0x0c068984u; return 0; }
vf3_matrix_store(s,ram,15,r[14]+r[0]);
goto P_0c068986;
P_0c068986: /* original 7004, guest PC 0x0c068986 */
if(!s->budget--) { s->failed_pc=0x0c068986u; return 0; }
r[0]+=0x00000004u;
goto P_0c068988;
P_0c068988: /* original fef7, guest PC 0x0c068988 */
if(!s->budget--) { s->failed_pc=0x0c068988u; return 0; }
vf3_matrix_store(s,ram,15,r[14]+r[0]);
goto P_0c06898a;
P_0c06898a: /* original 7004, guest PC 0x0c06898a */
if(!s->budget--) { s->failed_pc=0x0c06898au; return 0; }
r[0]+=0x00000004u;
goto P_0c06898c;
P_0c06898c: /* original ae83, guest PC 0x0c06898c */
if(!s->budget--) { s->failed_pc=0x0c06898cu; return 0; }
vf3_matrix_store(s,ram,15,r[14]+r[0]);
goto P_0c068696;
P_0c06898e: /* original fef7, guest PC 0x0c06898e */
if(!s->budget--) { s->failed_pc=0x0c06898eu; return 0; }
vf3_matrix_store(s,ram,15,r[14]+r[0]);
return vf3_matrix_family(0x0c068990u,s,ram);
P_0c068992: /* original 90dc, guest PC 0x0c068992 */
if(!s->budget--) { s->failed_pc=0x0c068992u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c068b4eu,2);
goto P_0c068994;
P_0c068994: /* original fa4c, guest PC 0x0c068994 */
if(!s->budget--) { s->failed_pc=0x0c068994u; return 0; }
vf3_matrix_move(s,10,4);
goto P_0c068996;
P_0c068996: /* original f7e6, guest PC 0x0c068996 */
if(!s->budget--) { s->failed_pc=0x0c068996u; return 0; }
vf3_matrix_load(s,ram,7,r[14]+r[0]);
goto P_0c068998;
P_0c068998: /* original 70e4, guest PC 0x0c068998 */
if(!s->budget--) { s->failed_pc=0x0c068998u; return 0; }
r[0]+=0xffffffe4u;
goto P_0c06899a;
P_0c06899a: /* original f5e6, guest PC 0x0c06899a */
if(!s->budget--) { s->failed_pc=0x0c06899au; return 0; }
vf3_matrix_load(s,ram,5,r[14]+r[0]);
goto P_0c06899c;
P_0c06899c: /* original 7004, guest PC 0x0c06899c */
if(!s->budget--) { s->failed_pc=0x0c06899cu; return 0; }
r[0]+=0x00000004u;
goto P_0c06899e;
P_0c06899e: /* original fbe6, guest PC 0x0c06899e */
if(!s->budget--) { s->failed_pc=0x0c06899eu; return 0; }
vf3_matrix_load(s,ram,11,r[14]+r[0]);
goto P_0c0689a0;
P_0c0689a0: /* original 700c, guest PC 0x0c0689a0 */
if(!s->budget--) { s->failed_pc=0x0c0689a0u; return 0; }
r[0]+=0x0000000cu;
goto P_0c0689a2;
P_0c0689a2: /* original ff5c, guest PC 0x0c0689a2 */
if(!s->budget--) { s->failed_pc=0x0c0689a2u; return 0; }
vf3_matrix_move(s,15,5);
goto P_0c0689a4;
P_0c0689a4: /* original ff73, guest PC 0x0c0689a4 */
if(!s->budget--) { s->failed_pc=0x0c0689a4u; return 0; }
fr[15]=vf3_fpu_binary(fr[15],fr[7],r[18],'/');
goto P_0c0689a6;
P_0c0689a6: /* original f3e6, guest PC 0x0c0689a6 */
if(!s->budget--) { s->failed_pc=0x0c0689a6u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c0689a8;
P_0c0689a8: /* original f8d8, guest PC 0x0c0689a8 */
if(!s->budget--) { s->failed_pc=0x0c0689a8u; return 0; }
vf3_matrix_load(s,ram,8,r[13]);
goto P_0c0689aa;
P_0c0689aa: /* original f948, guest PC 0x0c0689aa */
if(!s->budget--) { s->failed_pc=0x0c0689aau; return 0; }
vf3_matrix_load(s,ram,9,r[4]);
goto P_0c0689ac;
P_0c0689ac: /* original f7fc, guest PC 0x0c0689ac */
if(!s->budget--) { s->failed_pc=0x0c0689acu; return 0; }
vf3_matrix_move(s,7,15);
goto P_0c0689ae;
P_0c0689ae: /* original f7a1, guest PC 0x0c0689ae */
if(!s->budget--) { s->failed_pc=0x0c0689aeu; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[10],r[18],'-');
goto P_0c0689b0;
P_0c0689b0: /* original f6fc, guest PC 0x0c0689b0 */
if(!s->budget--) { s->failed_pc=0x0c0689b0u; return 0; }
vf3_matrix_move(s,6,15);
goto P_0c0689b2;
P_0c0689b2: /* original f632, guest PC 0x0c0689b2 */
if(!s->budget--) { s->failed_pc=0x0c0689b2u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[3],r[18],'*');
goto P_0c0689b4;
P_0c0689b4: /* original fb72, guest PC 0x0c0689b4 */
if(!s->budget--) { s->failed_pc=0x0c0689b4u; return 0; }
fr[11]=vf3_fpu_binary(fr[11],fr[7],r[18],'*');
goto P_0c0689b6;
P_0c0689b6: /* original f37c, guest PC 0x0c0689b6 */
if(!s->budget--) { s->failed_pc=0x0c0689b6u; return 0; }
vf3_matrix_move(s,3,7);
goto P_0c0689b8;
P_0c0689b8: /* original f6b0, guest PC 0x0c0689b8 */
if(!s->budget--) { s->failed_pc=0x0c0689b8u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[11],r[18],'+');
goto P_0c0689ba;
P_0c0689ba: /* original f672, guest PC 0x0c0689ba */
if(!s->budget--) { s->failed_pc=0x0c0689bau; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[7],r[18],'*');
goto P_0c0689bc;
P_0c0689bc: /* original f730, guest PC 0x0c0689bc */
if(!s->budget--) { s->failed_pc=0x0c0689bcu; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[3],r[18],'+');
goto P_0c0689be;
P_0c0689be: /* original f38c, guest PC 0x0c0689be */
if(!s->budget--) { s->failed_pc=0x0c0689beu; return 0; }
vf3_matrix_move(s,3,8);
goto P_0c0689c0;
P_0c0689c0: /* original f89c, guest PC 0x0c0689c0 */
if(!s->budget--) { s->failed_pc=0x0c0689c0u; return 0; }
vf3_matrix_move(s,8,9);
goto P_0c0689c2;
P_0c0689c2: /* original f831, guest PC 0x0c0689c2 */
if(!s->budget--) { s->failed_pc=0x0c0689c2u; return 0; }
fr[8]=vf3_fpu_binary(fr[8],fr[3],r[18],'-');
goto P_0c0689c4;
P_0c0689c4: /* original f652, guest PC 0x0c0689c4 */
if(!s->budget--) { s->failed_pc=0x0c0689c4u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[5],r[18],'*');
goto P_0c0689c6;
P_0c0689c6: /* original f7a1, guest PC 0x0c0689c6 */
if(!s->budget--) { s->failed_pc=0x0c0689c6u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[10],r[18],'-');
goto P_0c0689c8;
P_0c0689c8: /* original f690, guest PC 0x0c0689c8 */
if(!s->budget--) { s->failed_pc=0x0c0689c8u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[9],r[18],'+');
goto P_0c0689ca;
P_0c0689ca: /* original f782, guest PC 0x0c0689ca */
if(!s->budget--) { s->failed_pc=0x0c0689cau; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[8],r[18],'*');
goto P_0c0689cc;
P_0c0689cc: /* original f37c, guest PC 0x0c0689cc */
if(!s->budget--) { s->failed_pc=0x0c0689ccu; return 0; }
vf3_matrix_move(s,3,7);
goto P_0c0689ce;
P_0c0689ce: /* original f7fc, guest PC 0x0c0689ce */
if(!s->budget--) { s->failed_pc=0x0c0689ceu; return 0; }
vf3_matrix_move(s,7,15);
goto P_0c0689d0;
P_0c0689d0: /* original f732, guest PC 0x0c0689d0 */
if(!s->budget--) { s->failed_pc=0x0c0689d0u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[3],r[18],'*');
goto P_0c0689d2;
P_0c0689d2: /* original e004, guest PC 0x0c0689d2 */
if(!s->budget--) { s->failed_pc=0x0c0689d2u; return 0; }
r[0]=0x00000004u;
goto P_0c0689d4;
P_0c0689d4: /* original f37c, guest PC 0x0c0689d4 */
if(!s->budget--) { s->failed_pc=0x0c0689d4u; return 0; }
vf3_matrix_move(s,3,7);
goto P_0c0689d6;
P_0c0689d6: /* original fa46, guest PC 0x0c0689d6 */
if(!s->budget--) { s->failed_pc=0x0c0689d6u; return 0; }
vf3_matrix_load(s,ram,10,r[4]+r[0]);
goto P_0c0689d8;
P_0c0689d8: /* original f9d6, guest PC 0x0c0689d8 */
if(!s->budget--) { s->failed_pc=0x0c0689d8u; return 0; }
vf3_matrix_load(s,ram,9,r[13]+r[0]);
goto P_0c0689da;
P_0c0689da: /* original f7fc, guest PC 0x0c0689da */
if(!s->budget--) { s->failed_pc=0x0c0689dau; return 0; }
vf3_matrix_move(s,7,15);
goto P_0c0689dc;
P_0c0689dc: /* original f732, guest PC 0x0c0689dc */
if(!s->budget--) { s->failed_pc=0x0c0689dcu; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[3],r[18],'*');
goto P_0c0689de;
P_0c0689de: /* original 90b7, guest PC 0x0c0689de */
if(!s->budget--) { s->failed_pc=0x0c0689deu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c068b50u,2);
goto P_0c0689e0;
P_0c0689e0: /* original f86c, guest PC 0x0c0689e0 */
if(!s->budget--) { s->failed_pc=0x0c0689e0u; return 0; }
vf3_matrix_move(s,8,6);
goto P_0c0689e2;
P_0c0689e2: /* original f3e6, guest PC 0x0c0689e2 */
if(!s->budget--) { s->failed_pc=0x0c0689e2u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c0689e4;
P_0c0689e4: /* original e018, guest PC 0x0c0689e4 */
if(!s->budget--) { s->failed_pc=0x0c0689e4u; return 0; }
r[0]=0x00000018u;
goto P_0c0689e6;
P_0c0689e6: /* original f870, guest PC 0x0c0689e6 */
if(!s->budget--) { s->failed_pc=0x0c0689e6u; return 0; }
fr[8]=vf3_fpu_binary(fr[8],fr[7],r[18],'+');
goto P_0c0689e8;
P_0c0689e8: /* original ff37, guest PC 0x0c0689e8 */
if(!s->budget--) { s->failed_pc=0x0c0689e8u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0689ea;
P_0c0689ea: /* original 90b2, guest PC 0x0c0689ea */
if(!s->budget--) { s->failed_pc=0x0c0689eau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c068b52u,2);
goto P_0c0689ec;
P_0c0689ec: /* original f7fc, guest PC 0x0c0689ec */
if(!s->budget--) { s->failed_pc=0x0c0689ecu; return 0; }
vf3_matrix_move(s,7,15);
goto P_0c0689ee;
P_0c0689ee: /* original fb4c, guest PC 0x0c0689ee */
if(!s->budget--) { s->failed_pc=0x0c0689eeu; return 0; }
vf3_matrix_move(s,11,4);
goto P_0c0689f0;
P_0c0689f0: /* original f7b1, guest PC 0x0c0689f0 */
if(!s->budget--) { s->failed_pc=0x0c0689f0u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[11],r[18],'-');
goto P_0c0689f2;
P_0c0689f2: /* original f3e6, guest PC 0x0c0689f2 */
if(!s->budget--) { s->failed_pc=0x0c0689f2u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c0689f4;
P_0c0689f4: /* original e018, guest PC 0x0c0689f4 */
if(!s->budget--) { s->failed_pc=0x0c0689f4u; return 0; }
r[0]=0x00000018u;
goto P_0c0689f6;
P_0c0689f6: /* original f2f6, guest PC 0x0c0689f6 */
if(!s->budget--) { s->failed_pc=0x0c0689f6u; return 0; }
vf3_matrix_load(s,ram,2,r[15]+r[0]);
goto P_0c0689f8;
P_0c0689f8: /* original e004, guest PC 0x0c0689f8 */
if(!s->budget--) { s->failed_pc=0x0c0689f8u; return 0; }
r[0]=0x00000004u;
goto P_0c0689fa;
P_0c0689fa: /* original f6fc, guest PC 0x0c0689fa */
if(!s->budget--) { s->failed_pc=0x0c0689fau; return 0; }
vf3_matrix_move(s,6,15);
goto P_0c0689fc;
P_0c0689fc: /* original f632, guest PC 0x0c0689fc */
if(!s->budget--) { s->failed_pc=0x0c0689fcu; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[3],r[18],'*');
goto P_0c0689fe;
P_0c0689fe: /* original f272, guest PC 0x0c0689fe */
if(!s->budget--) { s->failed_pc=0x0c0689feu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[7],r[18],'*');
goto P_0c068a00;
P_0c068a00: /* original f620, guest PC 0x0c068a00 */
if(!s->budget--) { s->failed_pc=0x0c068a00u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[2],r[18],'+');
goto P_0c068a02;
P_0c068a02: /* original ff27, guest PC 0x0c068a02 */
if(!s->budget--) { s->failed_pc=0x0c068a02u; return 0; }
vf3_matrix_store(s,ram,2,r[15]+r[0]);
goto P_0c068a04;
P_0c068a04: /* original f37c, guest PC 0x0c068a04 */
if(!s->budget--) { s->failed_pc=0x0c068a04u; return 0; }
vf3_matrix_move(s,3,7);
goto P_0c068a06;
P_0c068a06: /* original f672, guest PC 0x0c068a06 */
if(!s->budget--) { s->failed_pc=0x0c068a06u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[7],r[18],'*');
goto P_0c068a08;
P_0c068a08: /* original f730, guest PC 0x0c068a08 */
if(!s->budget--) { s->failed_pc=0x0c068a08u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[3],r[18],'+');
goto P_0c068a0a;
P_0c068a0a: /* original f39c, guest PC 0x0c068a0a */
if(!s->budget--) { s->failed_pc=0x0c068a0au; return 0; }
vf3_matrix_move(s,3,9);
goto P_0c068a0c;
P_0c068a0c: /* original f652, guest PC 0x0c068a0c */
if(!s->budget--) { s->failed_pc=0x0c068a0cu; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[5],r[18],'*');
goto P_0c068a0e;
P_0c068a0e: /* original f7b1, guest PC 0x0c068a0e */
if(!s->budget--) { s->failed_pc=0x0c068a0eu; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[11],r[18],'-');
goto P_0c068a10;
P_0c068a10: /* original f6a0, guest PC 0x0c068a10 */
if(!s->budget--) { s->failed_pc=0x0c068a10u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[10],r[18],'+');
goto P_0c068a12;
P_0c068a12: /* original f9ac, guest PC 0x0c068a12 */
if(!s->budget--) { s->failed_pc=0x0c068a12u; return 0; }
vf3_matrix_move(s,9,10);
goto P_0c068a14;
P_0c068a14: /* original f931, guest PC 0x0c068a14 */
if(!s->budget--) { s->failed_pc=0x0c068a14u; return 0; }
fr[9]=vf3_fpu_binary(fr[9],fr[3],r[18],'-');
goto P_0c068a16;
P_0c068a16: /* original e008, guest PC 0x0c068a16 */
if(!s->budget--) { s->failed_pc=0x0c068a16u; return 0; }
r[0]=0x00000008u;
goto P_0c068a18;
P_0c068a18: /* original fb46, guest PC 0x0c068a18 */
if(!s->budget--) { s->failed_pc=0x0c068a18u; return 0; }
vf3_matrix_load(s,ram,11,r[4]+r[0]);
goto P_0c068a1a;
P_0c068a1a: /* original fad6, guest PC 0x0c068a1a */
if(!s->budget--) { s->failed_pc=0x0c068a1au; return 0; }
vf3_matrix_load(s,ram,10,r[13]+r[0]);
goto P_0c068a1c;
P_0c068a1c: /* original f792, guest PC 0x0c068a1c */
if(!s->budget--) { s->failed_pc=0x0c068a1cu; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[9],r[18],'*');
goto P_0c068a1e;
P_0c068a1e: /* original 9099, guest PC 0x0c068a1e */
if(!s->budget--) { s->failed_pc=0x0c068a1eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c068b54u,2);
goto P_0c068a20;
P_0c068a20: /* original f96c, guest PC 0x0c068a20 */
if(!s->budget--) { s->failed_pc=0x0c068a20u; return 0; }
vf3_matrix_move(s,9,6);
goto P_0c068a22;
P_0c068a22: /* original f37c, guest PC 0x0c068a22 */
if(!s->budget--) { s->failed_pc=0x0c068a22u; return 0; }
vf3_matrix_move(s,3,7);
goto P_0c068a24;
P_0c068a24: /* original f7fc, guest PC 0x0c068a24 */
if(!s->budget--) { s->failed_pc=0x0c068a24u; return 0; }
vf3_matrix_move(s,7,15);
goto P_0c068a26;
P_0c068a26: /* original f732, guest PC 0x0c068a26 */
if(!s->budget--) { s->failed_pc=0x0c068a26u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[3],r[18],'*');
goto P_0c068a28;
P_0c068a28: /* original f37c, guest PC 0x0c068a28 */
if(!s->budget--) { s->failed_pc=0x0c068a28u; return 0; }
vf3_matrix_move(s,3,7);
goto P_0c068a2a;
P_0c068a2a: /* original f7fc, guest PC 0x0c068a2a */
if(!s->budget--) { s->failed_pc=0x0c068a2au; return 0; }
vf3_matrix_move(s,7,15);
goto P_0c068a2c;
P_0c068a2c: /* original f732, guest PC 0x0c068a2c */
if(!s->budget--) { s->failed_pc=0x0c068a2cu; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[3],r[18],'*');
goto P_0c068a2e;
P_0c068a2e: /* original f3e6, guest PC 0x0c068a2e */
if(!s->budget--) { s->failed_pc=0x0c068a2eu; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c068a30;
P_0c068a30: /* original e024, guest PC 0x0c068a30 */
if(!s->budget--) { s->failed_pc=0x0c068a30u; return 0; }
r[0]=0x00000024u;
goto P_0c068a32;
P_0c068a32: /* original ff37, guest PC 0x0c068a32 */
if(!s->budget--) { s->failed_pc=0x0c068a32u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c068a34;
P_0c068a34: /* original 908f, guest PC 0x0c068a34 */
if(!s->budget--) { s->failed_pc=0x0c068a34u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c068b56u,2);
goto P_0c068a36;
P_0c068a36: /* original f970, guest PC 0x0c068a36 */
if(!s->budget--) { s->failed_pc=0x0c068a36u; return 0; }
fr[9]=vf3_fpu_binary(fr[9],fr[7],r[18],'+');
goto P_0c068a38;
P_0c068a38: /* original fe4c, guest PC 0x0c068a38 */
if(!s->budget--) { s->failed_pc=0x0c068a38u; return 0; }
vf3_matrix_move(s,14,4);
goto P_0c068a3a;
P_0c068a3a: /* original f7fc, guest PC 0x0c068a3a */
if(!s->budget--) { s->failed_pc=0x0c068a3au; return 0; }
vf3_matrix_move(s,7,15);
goto P_0c068a3c;
P_0c068a3c: /* original f7e1, guest PC 0x0c068a3c */
if(!s->budget--) { s->failed_pc=0x0c068a3cu; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[14],r[18],'-');
goto P_0c068a3e;
P_0c068a3e: /* original f3e6, guest PC 0x0c068a3e */
if(!s->budget--) { s->failed_pc=0x0c068a3eu; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c068a40;
P_0c068a40: /* original e024, guest PC 0x0c068a40 */
if(!s->budget--) { s->failed_pc=0x0c068a40u; return 0; }
r[0]=0x00000024u;
goto P_0c068a42;
P_0c068a42: /* original f2f6, guest PC 0x0c068a42 */
if(!s->budget--) { s->failed_pc=0x0c068a42u; return 0; }
vf3_matrix_load(s,ram,2,r[15]+r[0]);
goto P_0c068a44;
P_0c068a44: /* original e014, guest PC 0x0c068a44 */
if(!s->budget--) { s->failed_pc=0x0c068a44u; return 0; }
r[0]=0x00000014u;
goto P_0c068a46;
P_0c068a46: /* original f6fc, guest PC 0x0c068a46 */
if(!s->budget--) { s->failed_pc=0x0c068a46u; return 0; }
vf3_matrix_move(s,6,15);
goto P_0c068a48;
P_0c068a48: /* original f632, guest PC 0x0c068a48 */
if(!s->budget--) { s->failed_pc=0x0c068a48u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[3],r[18],'*');
goto P_0c068a4a;
P_0c068a4a: /* original f272, guest PC 0x0c068a4a */
if(!s->budget--) { s->failed_pc=0x0c068a4au; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[7],r[18],'*');
goto P_0c068a4c;
P_0c068a4c: /* original f620, guest PC 0x0c068a4c */
if(!s->budget--) { s->failed_pc=0x0c068a4cu; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[2],r[18],'+');
goto P_0c068a4e;
P_0c068a4e: /* original ff27, guest PC 0x0c068a4e */
if(!s->budget--) { s->failed_pc=0x0c068a4eu; return 0; }
vf3_matrix_store(s,ram,2,r[15]+r[0]);
goto P_0c068a50;
P_0c068a50: /* original f672, guest PC 0x0c068a50 */
if(!s->budget--) { s->failed_pc=0x0c068a50u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[7],r[18],'*');
goto P_0c068a52;
P_0c068a52: /* original f37c, guest PC 0x0c068a52 */
if(!s->budget--) { s->failed_pc=0x0c068a52u; return 0; }
vf3_matrix_move(s,3,7);
goto P_0c068a54;
P_0c068a54: /* original f730, guest PC 0x0c068a54 */
if(!s->budget--) { s->failed_pc=0x0c068a54u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[3],r[18],'+');
goto P_0c068a56;
P_0c068a56: /* original f3ac, guest PC 0x0c068a56 */
if(!s->budget--) { s->failed_pc=0x0c068a56u; return 0; }
vf3_matrix_move(s,3,10);
goto P_0c068a58;
P_0c068a58: /* original e00c, guest PC 0x0c068a58 */
if(!s->budget--) { s->failed_pc=0x0c068a58u; return 0; }
r[0]=0x0000000cu;
goto P_0c068a5a;
P_0c068a5a: /* original fabc, guest PC 0x0c068a5a */
if(!s->budget--) { s->failed_pc=0x0c068a5au; return 0; }
vf3_matrix_move(s,10,11);
goto P_0c068a5c;
P_0c068a5c: /* original fa31, guest PC 0x0c068a5c */
if(!s->budget--) { s->failed_pc=0x0c068a5cu; return 0; }
fr[10]=vf3_fpu_binary(fr[10],fr[3],r[18],'-');
goto P_0c068a5e;
P_0c068a5e: /* original f652, guest PC 0x0c068a5e */
if(!s->budget--) { s->failed_pc=0x0c068a5eu; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[5],r[18],'*');
goto P_0c068a60;
P_0c068a60: /* original f046, guest PC 0x0c068a60 */
if(!s->budget--) { s->failed_pc=0x0c068a60u; return 0; }
vf3_matrix_load(s,ram,0,r[4]+r[0]);
goto P_0c068a62;
P_0c068a62: /* original f7e1, guest PC 0x0c068a62 */
if(!s->budget--) { s->failed_pc=0x0c068a62u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[14],r[18],'-');
goto P_0c068a64;
P_0c068a64: /* original f6b0, guest PC 0x0c068a64 */
if(!s->budget--) { s->failed_pc=0x0c068a64u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[11],r[18],'+');
goto P_0c068a66;
P_0c068a66: /* original f7a2, guest PC 0x0c068a66 */
if(!s->budget--) { s->failed_pc=0x0c068a66u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[10],r[18],'*');
goto P_0c068a68;
P_0c068a68: /* original fad6, guest PC 0x0c068a68 */
if(!s->budget--) { s->failed_pc=0x0c068a68u; return 0; }
vf3_matrix_load(s,ram,10,r[13]+r[0]);
goto P_0c068a6a;
P_0c068a6a: /* original 9075, guest PC 0x0c068a6a */
if(!s->budget--) { s->failed_pc=0x0c068a6au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c068b58u,2);
goto P_0c068a6c;
P_0c068a6c: /* original fb6c, guest PC 0x0c068a6c */
if(!s->budget--) { s->failed_pc=0x0c068a6cu; return 0; }
vf3_matrix_move(s,11,6);
goto P_0c068a6e;
P_0c068a6e: /* original f37c, guest PC 0x0c068a6e */
if(!s->budget--) { s->failed_pc=0x0c068a6eu; return 0; }
vf3_matrix_move(s,3,7);
goto P_0c068a70;
P_0c068a70: /* original f7fc, guest PC 0x0c068a70 */
if(!s->budget--) { s->failed_pc=0x0c068a70u; return 0; }
vf3_matrix_move(s,7,15);
goto P_0c068a72;
P_0c068a72: /* original f732, guest PC 0x0c068a72 */
if(!s->budget--) { s->failed_pc=0x0c068a72u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[3],r[18],'*');
goto P_0c068a74;
P_0c068a74: /* original f37c, guest PC 0x0c068a74 */
if(!s->budget--) { s->failed_pc=0x0c068a74u; return 0; }
vf3_matrix_move(s,3,7);
goto P_0c068a76;
P_0c068a76: /* original f7fc, guest PC 0x0c068a76 */
if(!s->budget--) { s->failed_pc=0x0c068a76u; return 0; }
vf3_matrix_move(s,7,15);
goto P_0c068a78;
P_0c068a78: /* original f732, guest PC 0x0c068a78 */
if(!s->budget--) { s->failed_pc=0x0c068a78u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[3],r[18],'*');
goto P_0c068a7a;
P_0c068a7a: /* original f3e6, guest PC 0x0c068a7a */
if(!s->budget--) { s->failed_pc=0x0c068a7au; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c068a7c;
P_0c068a7c: /* original e030, guest PC 0x0c068a7c */
if(!s->budget--) { s->failed_pc=0x0c068a7cu; return 0; }
r[0]=0x00000030u;
goto P_0c068a7e;
P_0c068a7e: /* original ff37, guest PC 0x0c068a7e */
if(!s->budget--) { s->failed_pc=0x0c068a7eu; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c068a80;
P_0c068a80: /* original 906b, guest PC 0x0c068a80 */
if(!s->budget--) { s->failed_pc=0x0c068a80u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c068b5au,2);
goto P_0c068a82;
P_0c068a82: /* original fb70, guest PC 0x0c068a82 */
if(!s->budget--) { s->failed_pc=0x0c068a82u; return 0; }
fr[11]=vf3_fpu_binary(fr[11],fr[7],r[18],'+');
goto P_0c068a84;
P_0c068a84: /* original f6fc, guest PC 0x0c068a84 */
if(!s->budget--) { s->failed_pc=0x0c068a84u; return 0; }
vf3_matrix_move(s,6,15);
goto P_0c068a86;
P_0c068a86: /* original f3e6, guest PC 0x0c068a86 */
if(!s->budget--) { s->failed_pc=0x0c068a86u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c068a88;
P_0c068a88: /* original e030, guest PC 0x0c068a88 */
if(!s->budget--) { s->failed_pc=0x0c068a88u; return 0; }
r[0]=0x00000030u;
goto P_0c068a8a;
P_0c068a8a: /* original f7fc, guest PC 0x0c068a8a */
if(!s->budget--) { s->failed_pc=0x0c068a8au; return 0; }
vf3_matrix_move(s,7,15);
goto P_0c068a8c;
P_0c068a8c: /* original f7e1, guest PC 0x0c068a8c */
if(!s->budget--) { s->failed_pc=0x0c068a8cu; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[14],r[18],'-');
goto P_0c068a8e;
P_0c068a8e: /* original f632, guest PC 0x0c068a8e */
if(!s->budget--) { s->failed_pc=0x0c068a8eu; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[3],r[18],'*');
goto P_0c068a90;
P_0c068a90: /* original f2f6, guest PC 0x0c068a90 */
if(!s->budget--) { s->failed_pc=0x0c068a90u; return 0; }
vf3_matrix_load(s,ram,2,r[15]+r[0]);
goto P_0c068a92;
P_0c068a92: /* original f272, guest PC 0x0c068a92 */
if(!s->budget--) { s->failed_pc=0x0c068a92u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[7],r[18],'*');
goto P_0c068a94;
P_0c068a94: /* original e01c, guest PC 0x0c068a94 */
if(!s->budget--) { s->failed_pc=0x0c068a94u; return 0; }
r[0]=0x0000001cu;
goto P_0c068a96;
P_0c068a96: /* original f620, guest PC 0x0c068a96 */
if(!s->budget--) { s->failed_pc=0x0c068a96u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[2],r[18],'+');
goto P_0c068a98;
P_0c068a98: /* original ff27, guest PC 0x0c068a98 */
if(!s->budget--) { s->failed_pc=0x0c068a98u; return 0; }
vf3_matrix_store(s,ram,2,r[15]+r[0]);
goto P_0c068a9a;
P_0c068a9a: /* original f37c, guest PC 0x0c068a9a */
if(!s->budget--) { s->failed_pc=0x0c068a9au; return 0; }
vf3_matrix_move(s,3,7);
goto P_0c068a9c;
P_0c068a9c: /* original e04c, guest PC 0x0c068a9c */
if(!s->budget--) { s->failed_pc=0x0c068a9cu; return 0; }
r[0]=0x0000004cu;
goto P_0c068a9e;
P_0c068a9e: /* original f672, guest PC 0x0c068a9e */
if(!s->budget--) { s->failed_pc=0x0c068a9eu; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[7],r[18],'*');
goto P_0c068aa0;
P_0c068aa0: /* original f730, guest PC 0x0c068aa0 */
if(!s->budget--) { s->failed_pc=0x0c068aa0u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[3],r[18],'+');
goto P_0c068aa2;
P_0c068aa2: /* original f3ac, guest PC 0x0c068aa2 */
if(!s->budget--) { s->failed_pc=0x0c068aa2u; return 0; }
vf3_matrix_move(s,3,10);
goto P_0c068aa4;
P_0c068aa4: /* original fa0c, guest PC 0x0c068aa4 */
if(!s->budget--) { s->failed_pc=0x0c068aa4u; return 0; }
vf3_matrix_move(s,10,0);
goto P_0c068aa6;
P_0c068aa6: /* original fa31, guest PC 0x0c068aa6 */
if(!s->budget--) { s->failed_pc=0x0c068aa6u; return 0; }
fr[10]=vf3_fpu_binary(fr[10],fr[3],r[18],'-');
goto P_0c068aa8;
P_0c068aa8: /* original f652, guest PC 0x0c068aa8 */
if(!s->budget--) { s->failed_pc=0x0c068aa8u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[5],r[18],'*');
goto P_0c068aaa;
P_0c068aaa: /* original f7e1, guest PC 0x0c068aaa */
if(!s->budget--) { s->failed_pc=0x0c068aaau; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[14],r[18],'-');
goto P_0c068aac;
P_0c068aac: /* original f600, guest PC 0x0c068aac */
if(!s->budget--) { s->failed_pc=0x0c068aacu; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[0],r[18],'+');
goto P_0c068aae;
P_0c068aae: /* original f7a2, guest PC 0x0c068aae */
if(!s->budget--) { s->failed_pc=0x0c068aaeu; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[10],r[18],'*');
goto P_0c068ab0;
P_0c068ab0: /* original f37c, guest PC 0x0c068ab0 */
if(!s->budget--) { s->failed_pc=0x0c068ab0u; return 0; }
vf3_matrix_move(s,3,7);
goto P_0c068ab2;
P_0c068ab2: /* original f7fc, guest PC 0x0c068ab2 */
if(!s->budget--) { s->failed_pc=0x0c068ab2u; return 0; }
vf3_matrix_move(s,7,15);
goto P_0c068ab4;
P_0c068ab4: /* original f732, guest PC 0x0c068ab4 */
if(!s->budget--) { s->failed_pc=0x0c068ab4u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[3],r[18],'*');
goto P_0c068ab6;
P_0c068ab6: /* original f37c, guest PC 0x0c068ab6 */
if(!s->budget--) { s->failed_pc=0x0c068ab6u; return 0; }
vf3_matrix_move(s,3,7);
goto P_0c068ab8;
P_0c068ab8: /* original f7fc, guest PC 0x0c068ab8 */
if(!s->budget--) { s->failed_pc=0x0c068ab8u; return 0; }
vf3_matrix_move(s,7,15);
goto P_0c068aba;
P_0c068aba: /* original f732, guest PC 0x0c068aba */
if(!s->budget--) { s->failed_pc=0x0c068abau; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[3],r[18],'*');
goto P_0c068abc;
P_0c068abc: /* original f670, guest PC 0x0c068abc */
if(!s->budget--) { s->failed_pc=0x0c068abcu; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[7],r[18],'+');
goto P_0c068abe;
P_0c068abe: /* original ff67, guest PC 0x0c068abe */
if(!s->budget--) { s->failed_pc=0x0c068abeu; return 0; }
vf3_matrix_store(s,ram,6,r[15]+r[0]);
goto P_0c068ac0;
P_0c068ac0: /* original e010, guest PC 0x0c068ac0 */
if(!s->budget--) { s->failed_pc=0x0c068ac0u; return 0; }
r[0]=0x00000010u;
goto P_0c068ac2;
P_0c068ac2: /* original fad6, guest PC 0x0c068ac2 */
if(!s->budget--) { s->failed_pc=0x0c068ac2u; return 0; }
vf3_matrix_load(s,ram,10,r[13]+r[0]);
goto P_0c068ac4;
P_0c068ac4: /* original fe46, guest PC 0x0c068ac4 */
if(!s->budget--) { s->failed_pc=0x0c068ac4u; return 0; }
vf3_matrix_load(s,ram,14,r[4]+r[0]);
goto P_0c068ac6;
P_0c068ac6: /* original 9049, guest PC 0x0c068ac6 */
if(!s->budget--) { s->failed_pc=0x0c068ac6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c068b5cu,2);
goto P_0c068ac8;
P_0c068ac8: /* original f3e6, guest PC 0x0c068ac8 */
if(!s->budget--) { s->failed_pc=0x0c068ac8u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c068aca;
P_0c068aca: /* original e028, guest PC 0x0c068aca */
if(!s->budget--) { s->failed_pc=0x0c068acau; return 0; }
r[0]=0x00000028u;
goto P_0c068acc;
P_0c068acc: /* original ff37, guest PC 0x0c068acc */
if(!s->budget--) { s->failed_pc=0x0c068accu; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c068ace;
P_0c068ace: /* original 9046, guest PC 0x0c068ace */
if(!s->budget--) { s->failed_pc=0x0c068aceu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c068b5eu,2);
goto P_0c068ad0;
P_0c068ad0: /* original f3e6, guest PC 0x0c068ad0 */
if(!s->budget--) { s->failed_pc=0x0c068ad0u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c068ad2;
P_0c068ad2: /* original f7fc, guest PC 0x0c068ad2 */
if(!s->budget--) { s->failed_pc=0x0c068ad2u; return 0; }
vf3_matrix_move(s,7,15);
goto P_0c068ad4;
P_0c068ad4: /* original e028, guest PC 0x0c068ad4 */
if(!s->budget--) { s->failed_pc=0x0c068ad4u; return 0; }
r[0]=0x00000028u;
goto P_0c068ad6;
P_0c068ad6: /* original f04c, guest PC 0x0c068ad6 */
if(!s->budget--) { s->failed_pc=0x0c068ad6u; return 0; }
vf3_matrix_move(s,0,4);
goto P_0c068ad8;
P_0c068ad8: /* original f701, guest PC 0x0c068ad8 */
if(!s->budget--) { s->failed_pc=0x0c068ad8u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[0],r[18],'-');
goto P_0c068ada;
P_0c068ada: /* original f2f6, guest PC 0x0c068ada */
if(!s->budget--) { s->failed_pc=0x0c068adau; return 0; }
vf3_matrix_load(s,ram,2,r[15]+r[0]);
goto P_0c068adc;
P_0c068adc: /* original e02c, guest PC 0x0c068adc */
if(!s->budget--) { s->failed_pc=0x0c068adcu; return 0; }
r[0]=0x0000002cu;
goto P_0c068ade;
P_0c068ade: /* original f6fc, guest PC 0x0c068ade */
if(!s->budget--) { s->failed_pc=0x0c068adeu; return 0; }
vf3_matrix_move(s,6,15);
goto P_0c068ae0;
P_0c068ae0: /* original f632, guest PC 0x0c068ae0 */
if(!s->budget--) { s->failed_pc=0x0c068ae0u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[3],r[18],'*');
goto P_0c068ae2;
P_0c068ae2: /* original f272, guest PC 0x0c068ae2 */
if(!s->budget--) { s->failed_pc=0x0c068ae2u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[7],r[18],'*');
goto P_0c068ae4;
P_0c068ae4: /* original f620, guest PC 0x0c068ae4 */
if(!s->budget--) { s->failed_pc=0x0c068ae4u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[2],r[18],'+');
goto P_0c068ae6;
P_0c068ae6: /* original ff27, guest PC 0x0c068ae6 */
if(!s->budget--) { s->failed_pc=0x0c068ae6u; return 0; }
vf3_matrix_store(s,ram,2,r[15]+r[0]);
goto P_0c068ae8;
P_0c068ae8: /* original f37c, guest PC 0x0c068ae8 */
if(!s->budget--) { s->failed_pc=0x0c068ae8u; return 0; }
vf3_matrix_move(s,3,7);
goto P_0c068aea;
P_0c068aea: /* original e03c, guest PC 0x0c068aea */
if(!s->budget--) { s->failed_pc=0x0c068aeau; return 0; }
r[0]=0x0000003cu;
goto P_0c068aec;
P_0c068aec: /* original f672, guest PC 0x0c068aec */
if(!s->budget--) { s->failed_pc=0x0c068aecu; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[7],r[18],'*');
goto P_0c068aee;
P_0c068aee: /* original f730, guest PC 0x0c068aee */
if(!s->budget--) { s->failed_pc=0x0c068aeeu; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[3],r[18],'+');
goto P_0c068af0;
P_0c068af0: /* original f3ac, guest PC 0x0c068af0 */
if(!s->budget--) { s->failed_pc=0x0c068af0u; return 0; }
vf3_matrix_move(s,3,10);
goto P_0c068af2;
P_0c068af2: /* original faec, guest PC 0x0c068af2 */
if(!s->budget--) { s->failed_pc=0x0c068af2u; return 0; }
vf3_matrix_move(s,10,14);
goto P_0c068af4;
P_0c068af4: /* original fa31, guest PC 0x0c068af4 */
if(!s->budget--) { s->failed_pc=0x0c068af4u; return 0; }
fr[10]=vf3_fpu_binary(fr[10],fr[3],r[18],'-');
goto P_0c068af6;
P_0c068af6: /* original f652, guest PC 0x0c068af6 */
if(!s->budget--) { s->failed_pc=0x0c068af6u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[5],r[18],'*');
goto P_0c068af8;
P_0c068af8: /* original f701, guest PC 0x0c068af8 */
if(!s->budget--) { s->failed_pc=0x0c068af8u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[0],r[18],'-');
goto P_0c068afa;
P_0c068afa: /* original f6e0, guest PC 0x0c068afa */
if(!s->budget--) { s->failed_pc=0x0c068afau; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[14],r[18],'+');
goto P_0c068afc;
P_0c068afc: /* original f7a2, guest PC 0x0c068afc */
if(!s->budget--) { s->failed_pc=0x0c068afcu; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[10],r[18],'*');
goto P_0c068afe;
P_0c068afe: /* original f37c, guest PC 0x0c068afe */
if(!s->budget--) { s->failed_pc=0x0c068afeu; return 0; }
vf3_matrix_move(s,3,7);
goto P_0c068b00;
P_0c068b00: /* original f7fc, guest PC 0x0c068b00 */
if(!s->budget--) { s->failed_pc=0x0c068b00u; return 0; }
vf3_matrix_move(s,7,15);
goto P_0c068b02;
P_0c068b02: /* original f732, guest PC 0x0c068b02 */
if(!s->budget--) { s->failed_pc=0x0c068b02u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[3],r[18],'*');
goto P_0c068b04;
P_0c068b04: /* original f37c, guest PC 0x0c068b04 */
if(!s->budget--) { s->failed_pc=0x0c068b04u; return 0; }
vf3_matrix_move(s,3,7);
goto P_0c068b06;
P_0c068b06: /* original f7fc, guest PC 0x0c068b06 */
if(!s->budget--) { s->failed_pc=0x0c068b06u; return 0; }
vf3_matrix_move(s,7,15);
goto P_0c068b08;
P_0c068b08: /* original f732, guest PC 0x0c068b08 */
if(!s->budget--) { s->failed_pc=0x0c068b08u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[3],r[18],'*');
goto P_0c068b0a;
P_0c068b0a: /* original f670, guest PC 0x0c068b0a */
if(!s->budget--) { s->failed_pc=0x0c068b0au; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[7],r[18],'+');
goto P_0c068b0c;
P_0c068b0c: /* original ff67, guest PC 0x0c068b0c */
if(!s->budget--) { s->failed_pc=0x0c068b0cu; return 0; }
vf3_matrix_store(s,ram,6,r[15]+r[0]);
goto P_0c068b0e;
P_0c068b0e: /* original e014, guest PC 0x0c068b0e */
if(!s->budget--) { s->failed_pc=0x0c068b0eu; return 0; }
r[0]=0x00000014u;
goto P_0c068b10;
P_0c068b10: /* original fe46, guest PC 0x0c068b10 */
if(!s->budget--) { s->failed_pc=0x0c068b10u; return 0; }
vf3_matrix_load(s,ram,14,r[4]+r[0]);
goto P_0c068b12;
P_0c068b12: /* original fad6, guest PC 0x0c068b12 */
if(!s->budget--) { s->failed_pc=0x0c068b12u; return 0; }
vf3_matrix_load(s,ram,10,r[13]+r[0]);
goto P_0c068b14;
P_0c068b14: /* original 9024, guest PC 0x0c068b14 */
if(!s->budget--) { s->failed_pc=0x0c068b14u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c068b60u,2);
goto P_0c068b16;
P_0c068b16: /* original f3e6, guest PC 0x0c068b16 */
if(!s->budget--) { s->failed_pc=0x0c068b16u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c068b18;
P_0c068b18: /* original e048, guest PC 0x0c068b18 */
if(!s->budget--) { s->failed_pc=0x0c068b18u; return 0; }
r[0]=0x00000048u;
goto P_0c068b1a;
P_0c068b1a: /* original ff37, guest PC 0x0c068b1a */
if(!s->budget--) { s->failed_pc=0x0c068b1au; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c068b1c;
P_0c068b1c: /* original 9021, guest PC 0x0c068b1c */
if(!s->budget--) { s->failed_pc=0x0c068b1cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c068b62u,2);
goto P_0c068b1e;
P_0c068b1e: /* original f7fc, guest PC 0x0c068b1e */
if(!s->budget--) { s->failed_pc=0x0c068b1eu; return 0; }
vf3_matrix_move(s,7,15);
goto P_0c068b20;
P_0c068b20: /* original f701, guest PC 0x0c068b20 */
if(!s->budget--) { s->failed_pc=0x0c068b20u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[0],r[18],'-');
goto P_0c068b22;
P_0c068b22: /* original f3e6, guest PC 0x0c068b22 */
if(!s->budget--) { s->failed_pc=0x0c068b22u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c068b24;
P_0c068b24: /* original e048, guest PC 0x0c068b24 */
if(!s->budget--) { s->failed_pc=0x0c068b24u; return 0; }
r[0]=0x00000048u;
goto P_0c068b26;
P_0c068b26: /* original f2f6, guest PC 0x0c068b26 */
if(!s->budget--) { s->failed_pc=0x0c068b26u; return 0; }
vf3_matrix_load(s,ram,2,r[15]+r[0]);
goto P_0c068b28;
P_0c068b28: /* original e044, guest PC 0x0c068b28 */
if(!s->budget--) { s->failed_pc=0x0c068b28u; return 0; }
r[0]=0x00000044u;
goto P_0c068b2a;
P_0c068b2a: /* original f6fc, guest PC 0x0c068b2a */
if(!s->budget--) { s->failed_pc=0x0c068b2au; return 0; }
vf3_matrix_move(s,6,15);
goto P_0c068b2c;
P_0c068b2c: /* original f632, guest PC 0x0c068b2c */
if(!s->budget--) { s->failed_pc=0x0c068b2cu; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[3],r[18],'*');
goto P_0c068b2e;
P_0c068b2e: /* original f272, guest PC 0x0c068b2e */
if(!s->budget--) { s->failed_pc=0x0c068b2eu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[7],r[18],'*');
goto P_0c068b30;
P_0c068b30: /* original f620, guest PC 0x0c068b30 */
if(!s->budget--) { s->failed_pc=0x0c068b30u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[2],r[18],'+');
goto P_0c068b32;
P_0c068b32: /* original ff27, guest PC 0x0c068b32 */
if(!s->budget--) { s->failed_pc=0x0c068b32u; return 0; }
vf3_matrix_store(s,ram,2,r[15]+r[0]);
goto P_0c068b34;
P_0c068b34: /* original f3ac, guest PC 0x0c068b34 */
if(!s->budget--) { s->failed_pc=0x0c068b34u; return 0; }
vf3_matrix_move(s,3,10);
goto P_0c068b36;
P_0c068b36: /* original faec, guest PC 0x0c068b36 */
if(!s->budget--) { s->failed_pc=0x0c068b36u; return 0; }
vf3_matrix_move(s,10,14);
goto P_0c068b38;
P_0c068b38: /* original fa31, guest PC 0x0c068b38 */
if(!s->budget--) { s->failed_pc=0x0c068b38u; return 0; }
fr[10]=vf3_fpu_binary(fr[10],fr[3],r[18],'-');
goto P_0c068b3a;
P_0c068b3a: /* original f672, guest PC 0x0c068b3a */
if(!s->budget--) { s->failed_pc=0x0c068b3au; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[7],r[18],'*');
goto P_0c068b3c;
P_0c068b3c: /* original f652, guest PC 0x0c068b3c */
if(!s->budget--) { s->failed_pc=0x0c068b3cu; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[5],r[18],'*');
goto P_0c068b3e;
P_0c068b3e: /* original f57c, guest PC 0x0c068b3e */
if(!s->budget--) { s->failed_pc=0x0c068b3eu; return 0; }
vf3_matrix_move(s,5,7);
goto P_0c068b40;
P_0c068b40: /* original f570, guest PC 0x0c068b40 */
if(!s->budget--) { s->failed_pc=0x0c068b40u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[7],r[18],'+');
goto P_0c068b42;
P_0c068b42: /* original f6e0, guest PC 0x0c068b42 */
if(!s->budget--) { s->failed_pc=0x0c068b42u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[14],r[18],'+');
goto P_0c068b44;
P_0c068b44: /* original f501, guest PC 0x0c068b44 */
if(!s->budget--) { s->failed_pc=0x0c068b44u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[0],r[18],'-');
goto P_0c068b46;
P_0c068b46: /* original f5a2, guest PC 0x0c068b46 */
if(!s->budget--) { s->failed_pc=0x0c068b46u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[10],r[18],'*');
goto P_0c068b48;
P_0c068b48: /* original f35c, guest PC 0x0c068b48 */
if(!s->budget--) { s->failed_pc=0x0c068b48u; return 0; }
vf3_matrix_move(s,3,5);
goto P_0c068b4a;
P_0c068b4a: /* original a00b, guest PC 0x0c068b4a */
if(!s->budget--) { s->failed_pc=0x0c068b4au; return 0; }
goto P_0c068b64;
P_0c068b4c: /* original 0009, guest PC 0x0c068b4c */
if(!s->budget--) { s->failed_pc=0x0c068b4cu; return 0; }
return vf3_matrix_family(0x0c068b4eu,s,ram);
P_0c068b64: /* original f5fc, guest PC 0x0c068b64 */
if(!s->budget--) { s->failed_pc=0x0c068b64u; return 0; }
vf3_matrix_move(s,5,15);
goto P_0c068b66;
P_0c068b66: /* original f532, guest PC 0x0c068b66 */
if(!s->budget--) { s->failed_pc=0x0c068b66u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[3],r[18],'*');
goto P_0c068b68;
P_0c068b68: /* original 2558, guest PC 0x0c068b68 */
if(!s->budget--) { s->failed_pc=0x0c068b68u; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[5])==0)!=0);
goto P_0c068b6a;
P_0c068b6a: /* original f35c, guest PC 0x0c068b6a */
if(!s->budget--) { s->failed_pc=0x0c068b6au; return 0; }
vf3_matrix_move(s,3,5);
goto P_0c068b6c;
P_0c068b6c: /* original f5fc, guest PC 0x0c068b6c */
if(!s->budget--) { s->failed_pc=0x0c068b6cu; return 0; }
vf3_matrix_move(s,5,15);
goto P_0c068b6e;
P_0c068b6e: /* original f532, guest PC 0x0c068b6e */
if(!s->budget--) { s->failed_pc=0x0c068b6eu; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[3],r[18],'*');
goto P_0c068b70;
P_0c068b70: /* original f35c, guest PC 0x0c068b70 */
if(!s->budget--) { s->failed_pc=0x0c068b70u; return 0; }
vf3_matrix_move(s,3,5);
goto P_0c068b72;
P_0c068b72: /* original f56c, guest PC 0x0c068b72 */
if(!s->budget--) { s->failed_pc=0x0c068b72u; return 0; }
vf3_matrix_move(s,5,6);
goto P_0c068b74;
P_0c068b74: /* original 8f10, guest PC 0x0c068b74 */
if(!s->budget--) { s->failed_pc=0x0c068b74u; return 0; }
cond=r[17]&1u;
fr[5]=vf3_fpu_binary(fr[5],fr[3],r[18],'+');
if(!cond) { goto P_0c068b98; }
goto P_0c068b78;
P_0c068b76: /* original f530, guest PC 0x0c068b76 */
if(!s->budget--) { s->failed_pc=0x0c068b76u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[3],r[18],'+');
goto P_0c068b78;
P_0c068b78: /* original e010, guest PC 0x0c068b78 */
if(!s->budget--) { s->failed_pc=0x0c068b78u; return 0; }
r[0]=0x00000010u;
goto P_0c068b7a;
P_0c068b7a: /* original fe87, guest PC 0x0c068b7a */
if(!s->budget--) { s->failed_pc=0x0c068b7au; return 0; }
vf3_matrix_store(s,ram,8,r[14]+r[0]);
goto P_0c068b7c;
P_0c068b7c: /* original e014, guest PC 0x0c068b7c */
if(!s->budget--) { s->failed_pc=0x0c068b7cu; return 0; }
r[0]=0x00000014u;
goto P_0c068b7e;
P_0c068b7e: /* original fe97, guest PC 0x0c068b7e */
if(!s->budget--) { s->failed_pc=0x0c068b7eu; return 0; }
vf3_matrix_store(s,ram,9,r[14]+r[0]);
goto P_0c068b80;
P_0c068b80: /* original e018, guest PC 0x0c068b80 */
if(!s->budget--) { s->failed_pc=0x0c068b80u; return 0; }
r[0]=0x00000018u;
goto P_0c068b82;
P_0c068b82: /* original feb7, guest PC 0x0c068b82 */
if(!s->budget--) { s->failed_pc=0x0c068b82u; return 0; }
vf3_matrix_store(s,ram,11,r[14]+r[0]);
goto P_0c068b84;
P_0c068b84: /* original e04c, guest PC 0x0c068b84 */
if(!s->budget--) { s->failed_pc=0x0c068b84u; return 0; }
r[0]=0x0000004cu;
goto P_0c068b86;
P_0c068b86: /* original f3f6, guest PC 0x0c068b86 */
if(!s->budget--) { s->failed_pc=0x0c068b86u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c068b88;
P_0c068b88: /* original 903c, guest PC 0x0c068b88 */
if(!s->budget--) { s->failed_pc=0x0c068b88u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c068c04u,2);
goto P_0c068b8a;
P_0c068b8a: /* original fe37, guest PC 0x0c068b8a */
if(!s->budget--) { s->failed_pc=0x0c068b8au; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c068b8c;
P_0c068b8c: /* original e03c, guest PC 0x0c068b8c */
if(!s->budget--) { s->failed_pc=0x0c068b8cu; return 0; }
r[0]=0x0000003cu;
goto P_0c068b8e;
P_0c068b8e: /* original f3f6, guest PC 0x0c068b8e */
if(!s->budget--) { s->failed_pc=0x0c068b8eu; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c068b90;
P_0c068b90: /* original 9039, guest PC 0x0c068b90 */
if(!s->budget--) { s->failed_pc=0x0c068b90u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c068c06u,2);
goto P_0c068b92;
P_0c068b92: /* original fe37, guest PC 0x0c068b92 */
if(!s->budget--) { s->failed_pc=0x0c068b92u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c068b94;
P_0c068b94: /* original 7004, guest PC 0x0c068b94 */
if(!s->budget--) { s->failed_pc=0x0c068b94u; return 0; }
r[0]+=0x00000004u;
goto P_0c068b96;
P_0c068b96: /* original fe57, guest PC 0x0c068b96 */
if(!s->budget--) { s->failed_pc=0x0c068b96u; return 0; }
vf3_matrix_store(s,ram,5,r[14]+r[0]);
goto P_0c068b98;
P_0c068b98: /* original 9036, guest PC 0x0c068b98 */
if(!s->budget--) { s->failed_pc=0x0c068b98u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c068c08u,2);
goto P_0c068b9a;
P_0c068b9a: /* original f5e6, guest PC 0x0c068b9a */
if(!s->budget--) { s->failed_pc=0x0c068b9au; return 0; }
vf3_matrix_load(s,ram,5,r[14]+r[0]);
goto P_0c068b9c;
P_0c068b9c: /* original f540, guest PC 0x0c068b9c */
if(!s->budget--) { s->failed_pc=0x0c068b9cu; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[4],r[18],'+');
goto P_0c068b9e;
P_0c068b9e: /* original fe57, guest PC 0x0c068b9e */
if(!s->budget--) { s->failed_pc=0x0c068b9eu; return 0; }
vf3_matrix_store(s,ram,5,r[14]+r[0]);
goto P_0c068ba0;
P_0c068ba0: /* original e010, guest PC 0x0c068ba0 */
if(!s->budget--) { s->failed_pc=0x0c068ba0u; return 0; }
r[0]=0x00000010u;
goto P_0c068ba2;
P_0c068ba2: /* original f8e6, guest PC 0x0c068ba2 */
if(!s->budget--) { s->failed_pc=0x0c068ba2u; return 0; }
vf3_matrix_load(s,ram,8,r[14]+r[0]);
goto P_0c068ba4;
P_0c068ba4: /* original e014, guest PC 0x0c068ba4 */
if(!s->budget--) { s->failed_pc=0x0c068ba4u; return 0; }
r[0]=0x00000014u;
goto P_0c068ba6;
P_0c068ba6: /* original f7e6, guest PC 0x0c068ba6 */
if(!s->budget--) { s->failed_pc=0x0c068ba6u; return 0; }
vf3_matrix_load(s,ram,7,r[14]+r[0]);
goto P_0c068ba8;
P_0c068ba8: /* original e018, guest PC 0x0c068ba8 */
if(!s->budget--) { s->failed_pc=0x0c068ba8u; return 0; }
r[0]=0x00000018u;
goto P_0c068baa;
P_0c068baa: /* original f6e6, guest PC 0x0c068baa */
if(!s->budget--) { s->failed_pc=0x0c068baau; return 0; }
vf3_matrix_load(s,ram,6,r[14]+r[0]);
goto P_0c068bac;
P_0c068bac: /* original 902a, guest PC 0x0c068bac */
if(!s->budget--) { s->failed_pc=0x0c068bacu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c068c04u,2);
goto P_0c068bae;
P_0c068bae: /* original d317, guest PC 0x0c068bae */
if(!s->budget--) { s->failed_pc=0x0c068baeu; return 0; }
r[3]=read(ram,0x0c068c0cu,4);
goto P_0c068bb0;
P_0c068bb0: /* original f9e6, guest PC 0x0c068bb0 */
if(!s->budget--) { s->failed_pc=0x0c068bb0u; return 0; }
vf3_matrix_load(s,ram,9,r[14]+r[0]);
goto P_0c068bb2;
P_0c068bb2: /* original 7004, guest PC 0x0c068bb2 */
if(!s->budget--) { s->failed_pc=0x0c068bb2u; return 0; }
r[0]+=0x00000004u;
goto P_0c068bb4;
P_0c068bb4: /* original f4e6, guest PC 0x0c068bb4 */
if(!s->budget--) { s->failed_pc=0x0c068bb4u; return 0; }
vf3_matrix_load(s,ram,4,r[14]+r[0]);
goto P_0c068bb6;
P_0c068bb6: /* original 7004, guest PC 0x0c068bb6 */
if(!s->budget--) { s->failed_pc=0x0c068bb6u; return 0; }
r[0]+=0x00000004u;
goto P_0c068bb8;
P_0c068bb8: /* original fee6, guest PC 0x0c068bb8 */
if(!s->budget--) { s->failed_pc=0x0c068bb8u; return 0; }
vf3_matrix_load(s,ram,14,r[14]+r[0]);
goto P_0c068bba;
P_0c068bba: /* original ff9c, guest PC 0x0c068bba */
if(!s->budget--) { s->failed_pc=0x0c068bbau; return 0; }
vf3_matrix_move(s,15,9);
goto P_0c068bbc;
P_0c068bbc: /* original ff81, guest PC 0x0c068bbc */
if(!s->budget--) { s->failed_pc=0x0c068bbcu; return 0; }
fr[15]=vf3_fpu_binary(fr[15],fr[8],r[18],'-');
goto P_0c068bbe;
P_0c068bbe: /* original fe61, guest PC 0x0c068bbe */
if(!s->budget--) { s->failed_pc=0x0c068bbeu; return 0; }
fr[14]=vf3_fpu_binary(fr[14],fr[6],r[18],'-');
goto P_0c068bc0;
P_0c068bc0: /* original f471, guest PC 0x0c068bc0 */
if(!s->budget--) { s->failed_pc=0x0c068bc0u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[7],r[18],'-');
goto P_0c068bc2;
P_0c068bc2: /* original f0fc, guest PC 0x0c068bc2 */
if(!s->budget--) { s->failed_pc=0x0c068bc2u; return 0; }
vf3_matrix_move(s,0,15);
goto P_0c068bc4;
P_0c068bc4: /* original f3ec, guest PC 0x0c068bc4 */
if(!s->budget--) { s->failed_pc=0x0c068bc4u; return 0; }
vf3_matrix_move(s,3,14);
goto P_0c068bc6;
P_0c068bc6: /* original f3e2, guest PC 0x0c068bc6 */
if(!s->budget--) { s->failed_pc=0x0c068bc6u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[14],r[18],'*');
goto P_0c068bc8;
P_0c068bc8: /* original f3fe, guest PC 0x0c068bc8 */
if(!s->budget--) { s->failed_pc=0x0c068bc8u; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[15],fr[3],r[18]);
goto P_0c068bca;
P_0c068bca: /* original f36d, guest PC 0x0c068bca */
if(!s->budget--) { s->failed_pc=0x0c068bcau; return 0; }
fr[3]=vf3_fpu_sqrt(fr[3],r[18]);
goto P_0c068bcc;
P_0c068bcc: /* original 430b, guest PC 0x0c068bcc */
if(!s->budget--) { s->failed_pc=0x0c068bccu; return 0; }
target=r[3];
r[16]=0x0c068bd0u;
vf3_matrix_move(s,5,3);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c068bd0u) { target=s->pc; goto dispatch; }
goto P_0c068bd0;
P_0c068bce: /* original f53c, guest PC 0x0c068bce */
if(!s->budget--) { s->failed_pc=0x0c068bceu; return 0; }
vf3_matrix_move(s,5,3);
goto P_0c068bd0;
P_0c068bd0: /* original 600f, guest PC 0x0c068bd0 */
if(!s->budget--) { s->failed_pc=0x0c068bd0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)r[0];
goto P_0c068bd2;
P_0c068bd2: /* original 2f02, guest PC 0x0c068bd2 */
if(!s->budget--) { s->failed_pc=0x0c068bd2u; return 0; }
write(ram,r[15],r[0],4);
goto P_0c068bd4;
P_0c068bd4: /* original f4fc, guest PC 0x0c068bd4 */
if(!s->budget--) { s->failed_pc=0x0c068bd4u; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c068bd6;
P_0c068bd6: /* original d30d, guest PC 0x0c068bd6 */
if(!s->budget--) { s->failed_pc=0x0c068bd6u; return 0; }
r[3]=read(ram,0x0c068c0cu,4);
goto P_0c068bd8;
P_0c068bd8: /* original f44d, guest PC 0x0c068bd8 */
if(!s->budget--) { s->failed_pc=0x0c068bd8u; return 0; }
fr[4]^=0x80000000u;
goto P_0c068bda;
P_0c068bda: /* original 430b, guest PC 0x0c068bda */
if(!s->budget--) { s->failed_pc=0x0c068bdau; return 0; }
target=r[3];
r[16]=0x0c068bdeu;
vf3_matrix_move(s,5,14);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c068bdeu) { target=s->pc; goto dispatch; }
goto P_0c068bde;
P_0c068bdc: /* original f5ec, guest PC 0x0c068bdc */
if(!s->budget--) { s->failed_pc=0x0c068bdcu; return 0; }
vf3_matrix_move(s,5,14);
goto P_0c068bde;
P_0c068bde: /* original 640f, guest PC 0x0c068bde */
if(!s->budget--) { s->failed_pc=0x0c068bdeu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)r[0];
goto P_0c068be0;
P_0c068be0: /* original 60f2, guest PC 0x0c068be0 */
if(!s->budget--) { s->failed_pc=0x0c068be0u; return 0; }
tmp=read(ram,r[15],4);
r[0]=tmp;
goto P_0c068be2;
P_0c068be2: /* original 81ee, guest PC 0x0c068be2 */
if(!s->budget--) { s->failed_pc=0x0c068be2u; return 0; }
write(ram,r[14]+28,r[0],2);
goto P_0c068be4;
P_0c068be4: /* original 6043, guest PC 0x0c068be4 */
if(!s->budget--) { s->failed_pc=0x0c068be4u; return 0; }
r[0]=r[4];
goto P_0c068be6;
P_0c068be6: /* original 81ef, guest PC 0x0c068be6 */
if(!s->budget--) { s->failed_pc=0x0c068be6u; return 0; }
write(ram,r[14]+30,r[0],2);
goto P_0c068be8;
P_0c068be8: /* original 85ef, guest PC 0x0c068be8 */
if(!s->budget--) { s->failed_pc=0x0c068be8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+30,2);
goto P_0c068bea;
P_0c068bea: /* original 640d, guest PC 0x0c068bea */
if(!s->budget--) { s->failed_pc=0x0c068beau; return 0; }
r[4]=r[0]&65535u;
goto P_0c068bec;
P_0c068bec: /* original 2448, guest PC 0x0c068bec */
if(!s->budget--) { s->failed_pc=0x0c068becu; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c068bee;
P_0c068bee: /* original 8b00, guest PC 0x0c068bee */
if(!s->budget--) { s->failed_pc=0x0c068beeu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c068bf2; }
goto P_0c068bf0;
P_0c068bf0: /* original e401, guest PC 0x0c068bf0 */
if(!s->budget--) { s->failed_pc=0x0c068bf0u; return 0; }
r[4]=0x00000001u;
goto P_0c068bf2;
P_0c068bf2: /* original 7f50, guest PC 0x0c068bf2 */
if(!s->budget--) { s->failed_pc=0x0c068bf2u; return 0; }
r[15]+=0x00000050u;
goto P_0c068bf4;
P_0c068bf4: /* original 6043, guest PC 0x0c068bf4 */
if(!s->budget--) { s->failed_pc=0x0c068bf4u; return 0; }
r[0]=r[4];
goto P_0c068bf6;
P_0c068bf6: /* original 4f26, guest PC 0x0c068bf6 */
if(!s->budget--) { s->failed_pc=0x0c068bf6u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c068bf8;
P_0c068bf8: /* original 81ef, guest PC 0x0c068bf8 */
if(!s->budget--) { s->failed_pc=0x0c068bf8u; return 0; }
write(ram,r[14]+30,r[0],2);
goto P_0c068bfa;
P_0c068bfa: /* original fef9, guest PC 0x0c068bfa */
if(!s->budget--) { s->failed_pc=0x0c068bfau; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c068bfc;
P_0c068bfc: /* original fff9, guest PC 0x0c068bfc */
if(!s->budget--) { s->failed_pc=0x0c068bfcu; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c068bfe;
P_0c068bfe: /* original 6df6, guest PC 0x0c068bfe */
if(!s->budget--) { s->failed_pc=0x0c068bfeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c068c00;
P_0c068c00: /* original 000b, guest PC 0x0c068c00 */
if(!s->budget--) { s->failed_pc=0x0c068c00u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c068c02: /* original 6ef6, guest PC 0x0c068c02 */
if(!s->budget--) { s->failed_pc=0x0c068c02u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c068c04u,s,ram);
P_0c068e0e: /* original 2fe6, guest PC 0x0c068e0e */
if(!s->budget--) { s->failed_pc=0x0c068e0eu; return 0; }
r[15]-=4; write(ram,r[15],r[14],4);
goto P_0c068e10;
P_0c068e10: /* original e008, guest PC 0x0c068e10 */
if(!s->budget--) { s->failed_pc=0x0c068e10u; return 0; }
r[0]=0x00000008u;
goto P_0c068e12;
P_0c068e12: /* original 2fd6, guest PC 0x0c068e12 */
if(!s->budget--) { s->failed_pc=0x0c068e12u; return 0; }
r[15]-=4; write(ram,r[15],r[13],4);
goto P_0c068e14;
P_0c068e14: /* original ed0f, guest PC 0x0c068e14 */
if(!s->budget--) { s->failed_pc=0x0c068e14u; return 0; }
r[13]=0x0000000fu;
goto P_0c068e16;
P_0c068e16: /* original 4f22, guest PC 0x0c068e16 */
if(!s->budget--) { s->failed_pc=0x0c068e16u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c068e18;
P_0c068e18: /* original 7fdc, guest PC 0x0c068e18 */
if(!s->budget--) { s->failed_pc=0x0c068e18u; return 0; }
r[15]+=0xffffffdcu;
goto P_0c068e1a;
P_0c068e1a: /* original ff47, guest PC 0x0c068e1a */
if(!s->budget--) { s->failed_pc=0x0c068e1au; return 0; }
vf3_matrix_store(s,ram,4,r[15]+r[0]);
goto P_0c068e1c;
P_0c068e1c: /* original e004, guest PC 0x0c068e1c */
if(!s->budget--) { s->failed_pc=0x0c068e1cu; return 0; }
r[0]=0x00000004u;
goto P_0c068e1e;
P_0c068e1e: /* original ff57, guest PC 0x0c068e1e */
if(!s->budget--) { s->failed_pc=0x0c068e1eu; return 0; }
vf3_matrix_store(s,ram,5,r[15]+r[0]);
goto P_0c068e20;
P_0c068e20: /* original 65f3, guest PC 0x0c068e20 */
if(!s->budget--) { s->failed_pc=0x0c068e20u; return 0; }
r[5]=r[15];
goto P_0c068e22;
P_0c068e22: /* original d310, guest PC 0x0c068e22 */
if(!s->budget--) { s->failed_pc=0x0c068e22u; return 0; }
r[3]=read(ram,0x0c068e64u,4);
goto P_0c068e24;
P_0c068e24: /* original 66f3, guest PC 0x0c068e24 */
if(!s->budget--) { s->failed_pc=0x0c068e24u; return 0; }
r[6]=r[15];
goto P_0c068e26;
P_0c068e26: /* original d210, guest PC 0x0c068e26 */
if(!s->budget--) { s->failed_pc=0x0c068e26u; return 0; }
r[2]=read(ram,0x0c068e68u,4);
goto P_0c068e28;
P_0c068e28: /* original 7508, guest PC 0x0c068e28 */
if(!s->budget--) { s->failed_pc=0x0c068e28u; return 0; }
r[5]+=0x00000008u;
goto P_0c068e2a;
P_0c068e2a: /* original 6030, guest PC 0x0c068e2a */
if(!s->budget--) { s->failed_pc=0x0c068e2au; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[3],1);
r[0]=tmp;
goto P_0c068e2c;
P_0c068e2c: /* original 7604, guest PC 0x0c068e2c */
if(!s->budget--) { s->failed_pc=0x0c068e2cu; return 0; }
r[6]+=0x00000004u;
goto P_0c068e2e;
P_0c068e2e: /* original 6e22, guest PC 0x0c068e2e */
if(!s->budget--) { s->failed_pc=0x0c068e2eu; return 0; }
tmp=read(ram,r[2],4);
r[14]=tmp;
goto P_0c068e30;
P_0c068e30: /* original 600c, guest PC 0x0c068e30 */
if(!s->budget--) { s->failed_pc=0x0c068e30u; return 0; }
r[0]=r[0]&255u;
goto P_0c068e32;
P_0c068e32: /* original 2d09, guest PC 0x0c068e32 */
if(!s->budget--) { s->failed_pc=0x0c068e32u; return 0; }
r[13]&=r[0];
goto P_0c068e34;
P_0c068e34: /* original bf8e, guest PC 0x0c068e34 */
if(!s->budget--) { s->failed_pc=0x0c068e34u; return 0; }
target=0x0c068d54u; r[16]=0x0c068e38u;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c068e38u) { target=s->pc; goto dispatch; }
goto P_0c068e38;
P_0c068e36: /* original 64d3, guest PC 0x0c068e36 */
if(!s->budget--) { s->failed_pc=0x0c068e36u; return 0; }
r[4]=r[13];
goto P_0c068e38;
P_0c068e38: /* original 2ee8, guest PC 0x0c068e38 */
if(!s->budget--) { s->failed_pc=0x0c068e38u; return 0; }
r[17]=(r[17]&~1u)|(((r[14]&r[14])==0)!=0);
goto P_0c068e3a;
P_0c068e3a: /* original 8b17, guest PC 0x0c068e3a */
if(!s->budget--) { s->failed_pc=0x0c068e3au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c068e6c; }
goto P_0c068e3c;
P_0c068e3c: /* original e004, guest PC 0x0c068e3c */
if(!s->budget--) { s->failed_pc=0x0c068e3cu; return 0; }
r[0]=0x00000004u;
goto P_0c068e3e;
P_0c068e3e: /* original 64f3, guest PC 0x0c068e3e */
if(!s->budget--) { s->failed_pc=0x0c068e3eu; return 0; }
r[4]=r[15];
goto P_0c068e40;
P_0c068e40: /* original f5f6, guest PC 0x0c068e40 */
if(!s->budget--) { s->failed_pc=0x0c068e40u; return 0; }
vf3_matrix_load(s,ram,5,r[15]+r[0]);
goto P_0c068e42;
P_0c068e42: /* original e008, guest PC 0x0c068e42 */
if(!s->budget--) { s->failed_pc=0x0c068e42u; return 0; }
r[0]=0x00000008u;
goto P_0c068e44;
P_0c068e44: /* original 7418, guest PC 0x0c068e44 */
if(!s->budget--) { s->failed_pc=0x0c068e44u; return 0; }
r[4]+=0x00000018u;
goto P_0c068e46;
P_0c068e46: /* original bfcd, guest PC 0x0c068e46 */
if(!s->budget--) { s->failed_pc=0x0c068e46u; return 0; }
target=0x0c068de4u; r[16]=0x0c068e4au;
vf3_matrix_load(s,ram,4,r[15]+r[0]);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c068e4au) { target=s->pc; goto dispatch; }
goto P_0c068e4a;
P_0c068e48: /* original f4f6, guest PC 0x0c068e48 */
if(!s->budget--) { s->failed_pc=0x0c068e48u; return 0; }
vf3_matrix_load(s,ram,4,r[15]+r[0]);
goto P_0c068e4a;
P_0c068e4a: /* original e014, guest PC 0x0c068e4a */
if(!s->budget--) { s->failed_pc=0x0c068e4au; return 0; }
r[0]=0x00000014u;
goto P_0c068e4c;
P_0c068e4c: /* original a09a, guest PC 0x0c068e4c */
if(!s->budget--) { s->failed_pc=0x0c068e4cu; return 0; }
vf3_matrix_store(s,ram,0,r[15]+r[0]);
goto P_0c068f84;
P_0c068e4e: /* original ff07, guest PC 0x0c068e4e */
if(!s->budget--) { s->failed_pc=0x0c068e4eu; return 0; }
vf3_matrix_store(s,ram,0,r[15]+r[0]);
return vf3_matrix_family(0x0c068e50u,s,ram);
P_0c068e6c: /* original c758, guest PC 0x0c068e6c */
if(!s->budget--) { s->failed_pc=0x0c068e6cu; return 0; }
r[0]=0x0c068fd0u;
goto P_0c068e6e;
P_0c068e6e: /* original f408, guest PC 0x0c068e6e */
if(!s->budget--) { s->failed_pc=0x0c068e6eu; return 0; }
vf3_matrix_load(s,ram,4,r[0]);
goto P_0c068e70;
P_0c068e70: /* original e008, guest PC 0x0c068e70 */
if(!s->budget--) { s->failed_pc=0x0c068e70u; return 0; }
r[0]=0x00000008u;
goto P_0c068e72;
P_0c068e72: /* original f3f6, guest PC 0x0c068e72 */
if(!s->budget--) { s->failed_pc=0x0c068e72u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c068e74;
P_0c068e74: /* original f345, guest PC 0x0c068e74 */
if(!s->budget--) { s->failed_pc=0x0c068e74u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[4]))!=0);
goto P_0c068e76;
P_0c068e76: /* original 8901, guest PC 0x0c068e76 */
if(!s->budget--) { s->failed_pc=0x0c068e76u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c068e7c; }
goto P_0c068e78;
P_0c068e78: /* original e008, guest PC 0x0c068e78 */
if(!s->budget--) { s->failed_pc=0x0c068e78u; return 0; }
r[0]=0x00000008u;
goto P_0c068e7a;
P_0c068e7a: /* original ff47, guest PC 0x0c068e7a */
if(!s->budget--) { s->failed_pc=0x0c068e7au; return 0; }
vf3_matrix_store(s,ram,4,r[15]+r[0]);
goto P_0c068e7c;
P_0c068e7c: /* original e004, guest PC 0x0c068e7c */
if(!s->budget--) { s->failed_pc=0x0c068e7cu; return 0; }
r[0]=0x00000004u;
goto P_0c068e7e;
P_0c068e7e: /* original f3f6, guest PC 0x0c068e7e */
if(!s->budget--) { s->failed_pc=0x0c068e7eu; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c068e80;
P_0c068e80: /* original f345, guest PC 0x0c068e80 */
if(!s->budget--) { s->failed_pc=0x0c068e80u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[4]))!=0);
goto P_0c068e82;
P_0c068e82: /* original 8901, guest PC 0x0c068e82 */
if(!s->budget--) { s->failed_pc=0x0c068e82u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c068e88; }
goto P_0c068e84;
P_0c068e84: /* original e004, guest PC 0x0c068e84 */
if(!s->budget--) { s->failed_pc=0x0c068e84u; return 0; }
r[0]=0x00000004u;
goto P_0c068e86;
P_0c068e86: /* original ff47, guest PC 0x0c068e86 */
if(!s->budget--) { s->failed_pc=0x0c068e86u; return 0; }
vf3_matrix_store(s,ram,4,r[15]+r[0]);
goto P_0c068e88;
P_0c068e88: /* original c752, guest PC 0x0c068e88 */
if(!s->budget--) { s->failed_pc=0x0c068e88u; return 0; }
r[0]=0x0c068fd4u;
goto P_0c068e8a;
P_0c068e8a: /* original f408, guest PC 0x0c068e8a */
if(!s->budget--) { s->failed_pc=0x0c068e8au; return 0; }
vf3_matrix_load(s,ram,4,r[0]);
goto P_0c068e8c;
P_0c068e8c: /* original e008, guest PC 0x0c068e8c */
if(!s->budget--) { s->failed_pc=0x0c068e8cu; return 0; }
r[0]=0x00000008u;
goto P_0c068e8e;
P_0c068e8e: /* original f3f6, guest PC 0x0c068e8e */
if(!s->budget--) { s->failed_pc=0x0c068e8eu; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c068e90;
P_0c068e90: /* original f435, guest PC 0x0c068e90 */
if(!s->budget--) { s->failed_pc=0x0c068e90u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[4])>as_float(fr[3]))!=0);
goto P_0c068e92;
P_0c068e92: /* original 8901, guest PC 0x0c068e92 */
if(!s->budget--) { s->failed_pc=0x0c068e92u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c068e98; }
goto P_0c068e94;
P_0c068e94: /* original e008, guest PC 0x0c068e94 */
if(!s->budget--) { s->failed_pc=0x0c068e94u; return 0; }
r[0]=0x00000008u;
goto P_0c068e96;
P_0c068e96: /* original ff47, guest PC 0x0c068e96 */
if(!s->budget--) { s->failed_pc=0x0c068e96u; return 0; }
vf3_matrix_store(s,ram,4,r[15]+r[0]);
goto P_0c068e98;
P_0c068e98: /* original e004, guest PC 0x0c068e98 */
if(!s->budget--) { s->failed_pc=0x0c068e98u; return 0; }
r[0]=0x00000004u;
goto P_0c068e9a;
P_0c068e9a: /* original f3f6, guest PC 0x0c068e9a */
if(!s->budget--) { s->failed_pc=0x0c068e9au; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c068e9c;
P_0c068e9c: /* original f435, guest PC 0x0c068e9c */
if(!s->budget--) { s->failed_pc=0x0c068e9cu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[4])>as_float(fr[3]))!=0);
goto P_0c068e9e;
P_0c068e9e: /* original 8901, guest PC 0x0c068e9e */
if(!s->budget--) { s->failed_pc=0x0c068e9eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c068ea4; }
goto P_0c068ea0;
P_0c068ea0: /* original e004, guest PC 0x0c068ea0 */
if(!s->budget--) { s->failed_pc=0x0c068ea0u; return 0; }
r[0]=0x00000004u;
goto P_0c068ea2;
P_0c068ea2: /* original ff47, guest PC 0x0c068ea2 */
if(!s->budget--) { s->failed_pc=0x0c068ea2u; return 0; }
vf3_matrix_store(s,ram,4,r[15]+r[0]);
goto P_0c068ea4;
P_0c068ea4: /* original c74c, guest PC 0x0c068ea4 */
if(!s->budget--) { s->failed_pc=0x0c068ea4u; return 0; }
r[0]=0x0c068fd8u;
goto P_0c068ea6;
P_0c068ea6: /* original f508, guest PC 0x0c068ea6 */
if(!s->budget--) { s->failed_pc=0x0c068ea6u; return 0; }
vf3_matrix_load(s,ram,5,r[0]);
goto P_0c068ea8;
P_0c068ea8: /* original c74c, guest PC 0x0c068ea8 */
if(!s->budget--) { s->failed_pc=0x0c068ea8u; return 0; }
r[0]=0x0c068fdcu;
goto P_0c068eaa;
P_0c068eaa: /* original f408, guest PC 0x0c068eaa */
if(!s->budget--) { s->failed_pc=0x0c068eaau; return 0; }
vf3_matrix_load(s,ram,4,r[0]);
goto P_0c068eac;
P_0c068eac: /* original e008, guest PC 0x0c068eac */
if(!s->budget--) { s->failed_pc=0x0c068eacu; return 0; }
r[0]=0x00000008u;
goto P_0c068eae;
P_0c068eae: /* original f2f6, guest PC 0x0c068eae */
if(!s->budget--) { s->failed_pc=0x0c068eaeu; return 0; }
vf3_matrix_load(s,ram,2,r[15]+r[0]);
goto P_0c068eb0;
P_0c068eb0: /* original e004, guest PC 0x0c068eb0 */
if(!s->budget--) { s->failed_pc=0x0c068eb0u; return 0; }
r[0]=0x00000004u;
goto P_0c068eb2;
P_0c068eb2: /* original f34c, guest PC 0x0c068eb2 */
if(!s->budget--) { s->failed_pc=0x0c068eb2u; return 0; }
vf3_matrix_move(s,3,4);
goto P_0c068eb4;
P_0c068eb4: /* original e307, guest PC 0x0c068eb4 */
if(!s->budget--) { s->failed_pc=0x0c068eb4u; return 0; }
r[3]=0x00000007u;
goto P_0c068eb6;
P_0c068eb6: /* original f05c, guest PC 0x0c068eb6 */
if(!s->budget--) { s->failed_pc=0x0c068eb6u; return 0; }
vf3_matrix_move(s,0,5);
goto P_0c068eb8;
P_0c068eb8: /* original f32e, guest PC 0x0c068eb8 */
if(!s->budget--) { s->failed_pc=0x0c068eb8u; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[2],fr[3],r[18]);
goto P_0c068eba;
P_0c068eba: /* original e17f, guest PC 0x0c068eba */
if(!s->budget--) { s->failed_pc=0x0c068ebau; return 0; }
r[1]=0x0000007fu;
goto P_0c068ebc;
P_0c068ebc: /* original f33d, guest PC 0x0c068ebc */
if(!s->budget--) { s->failed_pc=0x0c068ebcu; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c068ebe;
P_0c068ebe: /* original ff3a, guest PC 0x0c068ebe */
if(!s->budget--) { s->failed_pc=0x0c068ebeu; return 0; }
vf3_matrix_store(s,ram,3,r[15]);
goto P_0c068ec0;
P_0c068ec0: /* original f2f6, guest PC 0x0c068ec0 */
if(!s->budget--) { s->failed_pc=0x0c068ec0u; return 0; }
vf3_matrix_load(s,ram,2,r[15]+r[0]);
goto P_0c068ec2;
P_0c068ec2: /* original 9281, guest PC 0x0c068ec2 */
if(!s->budget--) { s->failed_pc=0x0c068ec2u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c068fc8u,2);
goto P_0c068ec4;
P_0c068ec4: /* original f42e, guest PC 0x0c068ec4 */
if(!s->budget--) { s->failed_pc=0x0c068ec4u; return 0; }
fr[4]=vf3_fpu_mac(fr[0],fr[2],fr[4],r[18]);
goto P_0c068ec6;
P_0c068ec6: /* original 045a, guest PC 0x0c068ec6 */
if(!s->budget--) { s->failed_pc=0x0c068ec6u; return 0; }
r[4]=r[53];
goto P_0c068ec8;
P_0c068ec8: /* original f64c, guest PC 0x0c068ec8 */
if(!s->budget--) { s->failed_pc=0x0c068ec8u; return 0; }
vf3_matrix_move(s,6,4);
goto P_0c068eca;
P_0c068eca: /* original f63d, guest PC 0x0c068eca */
if(!s->budget--) { s->failed_pc=0x0c068ecau; return 0; }
r[53]=truncate_float(fr[6]);
goto P_0c068ecc;
P_0c068ecc: /* original f4f8, guest PC 0x0c068ecc */
if(!s->budget--) { s->failed_pc=0x0c068eccu; return 0; }
vf3_matrix_load(s,ram,4,r[15]);
goto P_0c068ece;
P_0c068ece: /* original 055a, guest PC 0x0c068ece */
if(!s->budget--) { s->failed_pc=0x0c068eceu; return 0; }
r[5]=r[53];
goto P_0c068ed0;
P_0c068ed0: /* original 445a, guest PC 0x0c068ed0 */
if(!s->budget--) { s->failed_pc=0x0c068ed0u; return 0; }
r[53]=r[4];
goto P_0c068ed2;
P_0c068ed2: /* original 2419, guest PC 0x0c068ed2 */
if(!s->budget--) { s->failed_pc=0x0c068ed2u; return 0; }
r[4]&=r[1];
goto P_0c068ed4;
P_0c068ed4: /* original f32d, guest PC 0x0c068ed4 */
if(!s->budget--) { s->failed_pc=0x0c068ed4u; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c068ed6;
P_0c068ed6: /* original 455a, guest PC 0x0c068ed6 */
if(!s->budget--) { s->failed_pc=0x0c068ed6u; return 0; }
r[53]=r[5];
goto P_0c068ed8;
P_0c068ed8: /* original 453c, guest PC 0x0c068ed8 */
if(!s->budget--) { s->failed_pc=0x0c068ed8u; return 0; }
r[5]=(r[3]&0x80000000u)?((r[3]&31u)?(uint32_t)((int32_t)r[5]>>((-r[3])&31u)):((int32_t)r[5]<0?0xffffffffu:0)):r[5]<<(r[3]&31u);
goto P_0c068eda;
P_0c068eda: /* original 2529, guest PC 0x0c068eda */
if(!s->budget--) { s->failed_pc=0x0c068edau; return 0; }
r[5]&=r[2];
goto P_0c068edc;
P_0c068edc: /* original f22d, guest PC 0x0c068edc */
if(!s->budget--) { s->failed_pc=0x0c068edcu; return 0; }
fr[2]=vf3_fpu_float(r[53],r[18]);
goto P_0c068ede;
P_0c068ede: /* original 245b, guest PC 0x0c068ede */
if(!s->budget--) { s->failed_pc=0x0c068edeu; return 0; }
r[4]|=r[5];
goto P_0c068ee0;
P_0c068ee0: /* original f431, guest PC 0x0c068ee0 */
if(!s->budget--) { s->failed_pc=0x0c068ee0u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'-');
goto P_0c068ee2;
P_0c068ee2: /* original f52c, guest PC 0x0c068ee2 */
if(!s->budget--) { s->failed_pc=0x0c068ee2u; return 0; }
vf3_matrix_move(s,5,2);
goto P_0c068ee4;
P_0c068ee4: /* original 6043, guest PC 0x0c068ee4 */
if(!s->budget--) { s->failed_pc=0x0c068ee4u; return 0; }
r[0]=r[4];
goto P_0c068ee6;
P_0c068ee6: /* original f56c, guest PC 0x0c068ee6 */
if(!s->budget--) { s->failed_pc=0x0c068ee6u; return 0; }
vf3_matrix_move(s,5,6);
goto P_0c068ee8;
P_0c068ee8: /* original f32c, guest PC 0x0c068ee8 */
if(!s->budget--) { s->failed_pc=0x0c068ee8u; return 0; }
vf3_matrix_move(s,3,2);
goto P_0c068eea;
P_0c068eea: /* original 4008, guest PC 0x0c068eea */
if(!s->budget--) { s->failed_pc=0x0c068eeau; return 0; }
r[0]<<=2;
goto P_0c068eec;
P_0c068eec: /* original f531, guest PC 0x0c068eec */
if(!s->budget--) { s->failed_pc=0x0c068eecu; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[3],r[18],'-');
goto P_0c068eee;
P_0c068eee: /* original f3e6, guest PC 0x0c068eee */
if(!s->budget--) { s->failed_pc=0x0c068eeeu; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c068ef0;
P_0c068ef0: /* original e010, guest PC 0x0c068ef0 */
if(!s->budget--) { s->failed_pc=0x0c068ef0u; return 0; }
r[0]=0x00000010u;
goto P_0c068ef2;
P_0c068ef2: /* original f69d, guest PC 0x0c068ef2 */
if(!s->budget--) { s->failed_pc=0x0c068ef2u; return 0; }
fr[6]=0x3f800000u;
goto P_0c068ef4;
P_0c068ef4: /* original f86c, guest PC 0x0c068ef4 */
if(!s->budget--) { s->failed_pc=0x0c068ef4u; return 0; }
vf3_matrix_move(s,8,6);
goto P_0c068ef6;
P_0c068ef6: /* original f76c, guest PC 0x0c068ef6 */
if(!s->budget--) { s->failed_pc=0x0c068ef6u; return 0; }
vf3_matrix_move(s,7,6);
goto P_0c068ef8;
P_0c068ef8: /* original f741, guest PC 0x0c068ef8 */
if(!s->budget--) { s->failed_pc=0x0c068ef8u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[4],r[18],'-');
goto P_0c068efa;
P_0c068efa: /* original ff37, guest PC 0x0c068efa */
if(!s->budget--) { s->failed_pc=0x0c068efau; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c068efc;
P_0c068efc: /* original 6043, guest PC 0x0c068efc */
if(!s->budget--) { s->failed_pc=0x0c068efcu; return 0; }
r[0]=r[4];
goto P_0c068efe;
P_0c068efe: /* original 7001, guest PC 0x0c068efe */
if(!s->budget--) { s->failed_pc=0x0c068efeu; return 0; }
r[0]+=0x00000001u;
goto P_0c068f00;
P_0c068f00: /* original f851, guest PC 0x0c068f00 */
if(!s->budget--) { s->failed_pc=0x0c068f00u; return 0; }
fr[8]=vf3_fpu_binary(fr[8],fr[5],r[18],'-');
goto P_0c068f02;
P_0c068f02: /* original 4008, guest PC 0x0c068f02 */
if(!s->budget--) { s->failed_pc=0x0c068f02u; return 0; }
r[0]<<=2;
goto P_0c068f04;
P_0c068f04: /* original f2e6, guest PC 0x0c068f04 */
if(!s->budget--) { s->failed_pc=0x0c068f04u; return 0; }
vf3_matrix_load(s,ram,2,r[14]+r[0]);
goto P_0c068f06;
P_0c068f06: /* original e00c, guest PC 0x0c068f06 */
if(!s->budget--) { s->failed_pc=0x0c068f06u; return 0; }
r[0]=0x0000000cu;
goto P_0c068f08;
P_0c068f08: /* original ff27, guest PC 0x0c068f08 */
if(!s->budget--) { s->failed_pc=0x0c068f08u; return 0; }
vf3_matrix_store(s,ram,2,r[15]+r[0]);
goto P_0c068f0a;
P_0c068f0a: /* original 905e, guest PC 0x0c068f0a */
if(!s->budget--) { s->failed_pc=0x0c068f0au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c068fcau,2);
goto P_0c068f0c;
P_0c068f0c: /* original 304c, guest PC 0x0c068f0c */
if(!s->budget--) { s->failed_pc=0x0c068f0cu; return 0; }
r[0]+=r[4];
goto P_0c068f0e;
P_0c068f0e: /* original 4008, guest PC 0x0c068f0e */
if(!s->budget--) { s->failed_pc=0x0c068f0eu; return 0; }
r[0]<<=2;
goto P_0c068f10;
P_0c068f10: /* original f1e6, guest PC 0x0c068f10 */
if(!s->budget--) { s->failed_pc=0x0c068f10u; return 0; }
vf3_matrix_load(s,ram,1,r[14]+r[0]);
goto P_0c068f12;
P_0c068f12: /* original ff1a, guest PC 0x0c068f12 */
if(!s->budget--) { s->failed_pc=0x0c068f12u; return 0; }
vf3_matrix_store(s,ram,1,r[15]);
goto P_0c068f14;
P_0c068f14: /* original 905a, guest PC 0x0c068f14 */
if(!s->budget--) { s->failed_pc=0x0c068f14u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c068fccu,2);
goto P_0c068f16;
P_0c068f16: /* original 304c, guest PC 0x0c068f16 */
if(!s->budget--) { s->failed_pc=0x0c068f16u; return 0; }
r[0]+=r[4];
goto P_0c068f18;
P_0c068f18: /* original 4008, guest PC 0x0c068f18 */
if(!s->budget--) { s->failed_pc=0x0c068f18u; return 0; }
r[0]<<=2;
goto P_0c068f1a;
P_0c068f1a: /* original f6e6, guest PC 0x0c068f1a */
if(!s->budget--) { s->failed_pc=0x0c068f1au; return 0; }
vf3_matrix_load(s,ram,6,r[14]+r[0]);
goto P_0c068f1c;
P_0c068f1c: /* original e010, guest PC 0x0c068f1c */
if(!s->budget--) { s->failed_pc=0x0c068f1cu; return 0; }
r[0]=0x00000010u;
goto P_0c068f1e;
P_0c068f1e: /* original f3f6, guest PC 0x0c068f1e */
if(!s->budget--) { s->failed_pc=0x0c068f1eu; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c068f20;
P_0c068f20: /* original e010, guest PC 0x0c068f20 */
if(!s->budget--) { s->failed_pc=0x0c068f20u; return 0; }
r[0]=0x00000010u;
goto P_0c068f22;
P_0c068f22: /* original f372, guest PC 0x0c068f22 */
if(!s->budget--) { s->failed_pc=0x0c068f22u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[7],r[18],'*');
goto P_0c068f24;
P_0c068f24: /* original ff37, guest PC 0x0c068f24 */
if(!s->budget--) { s->failed_pc=0x0c068f24u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c068f26;
P_0c068f26: /* original e00c, guest PC 0x0c068f26 */
if(!s->budget--) { s->failed_pc=0x0c068f26u; return 0; }
r[0]=0x0000000cu;
goto P_0c068f28;
P_0c068f28: /* original f2f6, guest PC 0x0c068f28 */
if(!s->budget--) { s->failed_pc=0x0c068f28u; return 0; }
vf3_matrix_load(s,ram,2,r[15]+r[0]);
goto P_0c068f2a;
P_0c068f2a: /* original e00c, guest PC 0x0c068f2a */
if(!s->budget--) { s->failed_pc=0x0c068f2au; return 0; }
r[0]=0x0000000cu;
goto P_0c068f2c;
P_0c068f2c: /* original f642, guest PC 0x0c068f2c */
if(!s->budget--) { s->failed_pc=0x0c068f2cu; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[4],r[18],'*');
goto P_0c068f2e;
P_0c068f2e: /* original f242, guest PC 0x0c068f2e */
if(!s->budget--) { s->failed_pc=0x0c068f2eu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[4],r[18],'*');
goto P_0c068f30;
P_0c068f30: /* original ff27, guest PC 0x0c068f30 */
if(!s->budget--) { s->failed_pc=0x0c068f30u; return 0; }
vf3_matrix_store(s,ram,2,r[15]+r[0]);
goto P_0c068f32;
P_0c068f32: /* original e010, guest PC 0x0c068f32 */
if(!s->budget--) { s->failed_pc=0x0c068f32u; return 0; }
r[0]=0x00000010u;
goto P_0c068f34;
P_0c068f34: /* original f1f8, guest PC 0x0c068f34 */
if(!s->budget--) { s->failed_pc=0x0c068f34u; return 0; }
vf3_matrix_load(s,ram,1,r[15]);
goto P_0c068f36;
P_0c068f36: /* original f172, guest PC 0x0c068f36 */
if(!s->budget--) { s->failed_pc=0x0c068f36u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[7],r[18],'*');
goto P_0c068f38;
P_0c068f38: /* original ff1a, guest PC 0x0c068f38 */
if(!s->budget--) { s->failed_pc=0x0c068f38u; return 0; }
vf3_matrix_store(s,ram,1,r[15]);
goto P_0c068f3a;
P_0c068f3a: /* original f3f6, guest PC 0x0c068f3a */
if(!s->budget--) { s->failed_pc=0x0c068f3au; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c068f3c;
P_0c068f3c: /* original e010, guest PC 0x0c068f3c */
if(!s->budget--) { s->failed_pc=0x0c068f3cu; return 0; }
r[0]=0x00000010u;
goto P_0c068f3e;
P_0c068f3e: /* original f382, guest PC 0x0c068f3e */
if(!s->budget--) { s->failed_pc=0x0c068f3eu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[8],r[18],'*');
goto P_0c068f40;
P_0c068f40: /* original ff37, guest PC 0x0c068f40 */
if(!s->budget--) { s->failed_pc=0x0c068f40u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c068f42;
P_0c068f42: /* original e00c, guest PC 0x0c068f42 */
if(!s->budget--) { s->failed_pc=0x0c068f42u; return 0; }
r[0]=0x0000000cu;
goto P_0c068f44;
P_0c068f44: /* original f2f6, guest PC 0x0c068f44 */
if(!s->budget--) { s->failed_pc=0x0c068f44u; return 0; }
vf3_matrix_load(s,ram,2,r[15]+r[0]);
goto P_0c068f46;
P_0c068f46: /* original e00c, guest PC 0x0c068f46 */
if(!s->budget--) { s->failed_pc=0x0c068f46u; return 0; }
r[0]=0x0000000cu;
goto P_0c068f48;
P_0c068f48: /* original f282, guest PC 0x0c068f48 */
if(!s->budget--) { s->failed_pc=0x0c068f48u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[8],r[18],'*');
goto P_0c068f4a;
P_0c068f4a: /* original ff27, guest PC 0x0c068f4a */
if(!s->budget--) { s->failed_pc=0x0c068f4au; return 0; }
vf3_matrix_store(s,ram,2,r[15]+r[0]);
goto P_0c068f4c;
P_0c068f4c: /* original e014, guest PC 0x0c068f4c */
if(!s->budget--) { s->failed_pc=0x0c068f4cu; return 0; }
r[0]=0x00000014u;
goto P_0c068f4e;
P_0c068f4e: /* original f1f8, guest PC 0x0c068f4e */
if(!s->budget--) { s->failed_pc=0x0c068f4eu; return 0; }
vf3_matrix_load(s,ram,1,r[15]);
goto P_0c068f50;
P_0c068f50: /* original f05c, guest PC 0x0c068f50 */
if(!s->budget--) { s->failed_pc=0x0c068f50u; return 0; }
vf3_matrix_move(s,0,5);
goto P_0c068f52;
P_0c068f52: /* original f26e, guest PC 0x0c068f52 */
if(!s->budget--) { s->failed_pc=0x0c068f52u; return 0; }
fr[2]=vf3_fpu_mac(fr[0],fr[6],fr[2],r[18]);
goto P_0c068f54;
P_0c068f54: /* original f31e, guest PC 0x0c068f54 */
if(!s->budget--) { s->failed_pc=0x0c068f54u; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[1],fr[3],r[18]);
goto P_0c068f56;
P_0c068f56: /* original ff3a, guest PC 0x0c068f56 */
if(!s->budget--) { s->failed_pc=0x0c068f56u; return 0; }
vf3_matrix_store(s,ram,3,r[15]);
goto P_0c068f58;
P_0c068f58: /* original f42c, guest PC 0x0c068f58 */
if(!s->budget--) { s->failed_pc=0x0c068f58u; return 0; }
vf3_matrix_move(s,4,2);
goto P_0c068f5a;
P_0c068f5a: /* original f340, guest PC 0x0c068f5a */
if(!s->budget--) { s->failed_pc=0x0c068f5au; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'+');
goto P_0c068f5c;
P_0c068f5c: /* original ff37, guest PC 0x0c068f5c */
if(!s->budget--) { s->failed_pc=0x0c068f5cu; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c068f5e;
P_0c068f5e: /* original 60d3, guest PC 0x0c068f5e */
if(!s->budget--) { s->failed_pc=0x0c068f5eu; return 0; }
r[0]=r[13];
goto P_0c068f60;
P_0c068f60: /* original 880b, guest PC 0x0c068f60 */
if(!s->budget--) { s->failed_pc=0x0c068f60u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000bu)!=0);
goto P_0c068f62;
P_0c068f62: /* original 8b0f, guest PC 0x0c068f62 */
if(!s->budget--) { s->failed_pc=0x0c068f62u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c068f84; }
goto P_0c068f64;
P_0c068f64: /* original 62f3, guest PC 0x0c068f64 */
if(!s->budget--) { s->failed_pc=0x0c068f64u; return 0; }
r[2]=r[15];
goto P_0c068f66;
P_0c068f66: /* original 2f26, guest PC 0x0c068f66 */
if(!s->budget--) { s->failed_pc=0x0c068f66u; return 0; }
r[15]-=4; write(ram,r[15],r[2],4);
goto P_0c068f68;
P_0c068f68: /* original 63f3, guest PC 0x0c068f68 */
if(!s->budget--) { s->failed_pc=0x0c068f68u; return 0; }
r[3]=r[15];
goto P_0c068f6a;
P_0c068f6a: /* original 7310, guest PC 0x0c068f6a */
if(!s->budget--) { s->failed_pc=0x0c068f6au; return 0; }
r[3]+=0x00000010u;
goto P_0c068f6c;
P_0c068f6c: /* original 2f36, guest PC 0x0c068f6c */
if(!s->budget--) { s->failed_pc=0x0c068f6cu; return 0; }
r[15]-=4; write(ram,r[15],r[3],4);
goto P_0c068f6e;
P_0c068f6e: /* original 66f3, guest PC 0x0c068f6e */
if(!s->budget--) { s->failed_pc=0x0c068f6eu; return 0; }
r[6]=r[15];
goto P_0c068f70;
P_0c068f70: /* original 65f3, guest PC 0x0c068f70 */
if(!s->budget--) { s->failed_pc=0x0c068f70u; return 0; }
r[5]=r[15];
goto P_0c068f72;
P_0c068f72: /* original 67f3, guest PC 0x0c068f72 */
if(!s->budget--) { s->failed_pc=0x0c068f72u; return 0; }
r[7]=r[15];
goto P_0c068f74;
P_0c068f74: /* original d21a, guest PC 0x0c068f74 */
if(!s->budget--) { s->failed_pc=0x0c068f74u; return 0; }
r[2]=read(ram,0x0c068fe0u,4);
goto P_0c068f76;
P_0c068f76: /* original 64f3, guest PC 0x0c068f76 */
if(!s->budget--) { s->failed_pc=0x0c068f76u; return 0; }
r[4]=r[15];
goto P_0c068f78;
P_0c068f78: /* original 751c, guest PC 0x0c068f78 */
if(!s->budget--) { s->failed_pc=0x0c068f78u; return 0; }
r[5]+=0x0000001cu;
goto P_0c068f7a;
P_0c068f7a: /* original 7718, guest PC 0x0c068f7a */
if(!s->budget--) { s->failed_pc=0x0c068f7au; return 0; }
r[7]+=0x00000018u;
goto P_0c068f7c;
P_0c068f7c: /* original 760c, guest PC 0x0c068f7c */
if(!s->budget--) { s->failed_pc=0x0c068f7cu; return 0; }
r[6]+=0x0000000cu;
goto P_0c068f7e;
P_0c068f7e: /* original 420b, guest PC 0x0c068f7e */
if(!s->budget--) { s->failed_pc=0x0c068f7eu; return 0; }
target=r[2];
r[16]=0x0c068f82u;
r[4]+=0x00000010u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c068f82u) { target=s->pc; goto dispatch; }
goto P_0c068f82;
P_0c068f80: /* original 7410, guest PC 0x0c068f80 */
if(!s->budget--) { s->failed_pc=0x0c068f80u; return 0; }
r[4]+=0x00000010u;
goto P_0c068f82;
P_0c068f82: /* original 7f08, guest PC 0x0c068f82 */
if(!s->budget--) { s->failed_pc=0x0c068f82u; return 0; }
r[15]+=0x00000008u;
goto P_0c068f84;
P_0c068f84: /* original e014, guest PC 0x0c068f84 */
if(!s->budget--) { s->failed_pc=0x0c068f84u; return 0; }
r[0]=0x00000014u;
goto P_0c068f86;
P_0c068f86: /* original f0f6, guest PC 0x0c068f86 */
if(!s->budget--) { s->failed_pc=0x0c068f86u; return 0; }
vf3_matrix_load(s,ram,0,r[15]+r[0]);
goto P_0c068f88;
P_0c068f88: /* original 7f24, guest PC 0x0c068f88 */
if(!s->budget--) { s->failed_pc=0x0c068f88u; return 0; }
r[15]+=0x00000024u;
goto P_0c068f8a;
P_0c068f8a: /* original 4f26, guest PC 0x0c068f8a */
if(!s->budget--) { s->failed_pc=0x0c068f8au; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c068f8c;
P_0c068f8c: /* original 6df6, guest PC 0x0c068f8c */
if(!s->budget--) { s->failed_pc=0x0c068f8cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c068f8e;
P_0c068f8e: /* original 000b, guest PC 0x0c068f8e */
if(!s->budget--) { s->failed_pc=0x0c068f8eu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c068f90: /* original 6ef6, guest PC 0x0c068f90 */
if(!s->budget--) { s->failed_pc=0x0c068f90u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c068f92u,s,ram);
P_0c069624: /* original f38d, guest PC 0x0c069624 */
if(!s->budget--) { s->failed_pc=0x0c069624u; return 0; }
fr[3]=0;
goto P_0c069626;
P_0c069626: /* original f534, guest PC 0x0c069626 */
if(!s->budget--) { s->failed_pc=0x0c069626u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[5])==as_float(fr[3]))!=0);
goto P_0c069628;
P_0c069628: /* original 8b03, guest PC 0x0c069628 */
if(!s->budget--) { s->failed_pc=0x0c069628u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c069632; }
goto P_0c06962a;
P_0c06962a: /* original f434, guest PC 0x0c06962a */
if(!s->budget--) { s->failed_pc=0x0c06962au; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[4])==as_float(fr[3]))!=0);
goto P_0c06962c;
P_0c06962c: /* original 8b01, guest PC 0x0c06962c */
if(!s->budget--) { s->failed_pc=0x0c06962cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c069632; }
goto P_0c06962e;
P_0c06962e: /* original 000b, guest PC 0x0c06962e */
if(!s->budget--) { s->failed_pc=0x0c06962eu; return 0; }
target=r[16];
r[0]=0x00000000u;
s->pc=target; return ram->oob==0;
P_0c069630: /* original e000, guest PC 0x0c069630 */
if(!s->budget--) { s->failed_pc=0x0c069630u; return 0; }
r[0]=0x00000000u;
goto P_0c069632;
P_0c069632: /* original f38d, guest PC 0x0c069632 */
if(!s->budget--) { s->failed_pc=0x0c069632u; return 0; }
fr[3]=0;
goto P_0c069634;
P_0c069634: /* original f355, guest PC 0x0c069634 */
if(!s->budget--) { s->failed_pc=0x0c069634u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[5]))!=0);
goto P_0c069636;
P_0c069636: /* original 8f03, guest PC 0x0c069636 */
if(!s->budget--) { s->failed_pc=0x0c069636u; return 0; }
cond=r[17]&1u;
fr[3]=0;
if(!cond) { goto P_0c069640; }
goto P_0c06963a;
P_0c069638: /* original f38d, guest PC 0x0c069638 */
if(!s->budget--) { s->failed_pc=0x0c069638u; return 0; }
fr[3]=0;
goto P_0c06963a;
P_0c06963a: /* original f65c, guest PC 0x0c06963a */
if(!s->budget--) { s->failed_pc=0x0c06963au; return 0; }
vf3_matrix_move(s,6,5);
goto P_0c06963c;
P_0c06963c: /* original a001, guest PC 0x0c06963c */
if(!s->budget--) { s->failed_pc=0x0c06963cu; return 0; }
fr[6]^=0x80000000u;
goto P_0c069642;
P_0c06963e: /* original f64d, guest PC 0x0c06963e */
if(!s->budget--) { s->failed_pc=0x0c06963eu; return 0; }
fr[6]^=0x80000000u;
goto P_0c069640;
P_0c069640: /* original f65c, guest PC 0x0c069640 */
if(!s->budget--) { s->failed_pc=0x0c069640u; return 0; }
vf3_matrix_move(s,6,5);
goto P_0c069642;
P_0c069642: /* original f345, guest PC 0x0c069642 */
if(!s->budget--) { s->failed_pc=0x0c069642u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[4]))!=0);
goto P_0c069644;
P_0c069644: /* original 8b02, guest PC 0x0c069644 */
if(!s->budget--) { s->failed_pc=0x0c069644u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06964c; }
goto P_0c069646;
P_0c069646: /* original f74c, guest PC 0x0c069646 */
if(!s->budget--) { s->failed_pc=0x0c069646u; return 0; }
vf3_matrix_move(s,7,4);
goto P_0c069648;
P_0c069648: /* original a001, guest PC 0x0c069648 */
if(!s->budget--) { s->failed_pc=0x0c069648u; return 0; }
fr[7]^=0x80000000u;
goto P_0c06964e;
P_0c06964a: /* original f74d, guest PC 0x0c06964a */
if(!s->budget--) { s->failed_pc=0x0c06964au; return 0; }
fr[7]^=0x80000000u;
goto P_0c06964c;
P_0c06964c: /* original f74c, guest PC 0x0c06964c */
if(!s->budget--) { s->failed_pc=0x0c06964cu; return 0; }
vf3_matrix_move(s,7,4);
goto P_0c06964e;
P_0c06964e: /* original f675, guest PC 0x0c06964e */
if(!s->budget--) { s->failed_pc=0x0c06964eu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[6])>as_float(fr[7]))!=0);
goto P_0c069650;
P_0c069650: /* original 8b02, guest PC 0x0c069650 */
if(!s->budget--) { s->failed_pc=0x0c069650u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c069658; }
goto P_0c069652;
P_0c069652: /* original f87c, guest PC 0x0c069652 */
if(!s->budget--) { s->failed_pc=0x0c069652u; return 0; }
vf3_matrix_move(s,8,7);
goto P_0c069654;
P_0c069654: /* original a002, guest PC 0x0c069654 */
if(!s->budget--) { s->failed_pc=0x0c069654u; return 0; }
fr[8]=vf3_fpu_binary(fr[8],fr[6],r[18],'/');
goto P_0c06965c;
P_0c069656: /* original f863, guest PC 0x0c069656 */
if(!s->budget--) { s->failed_pc=0x0c069656u; return 0; }
fr[8]=vf3_fpu_binary(fr[8],fr[6],r[18],'/');
goto P_0c069658;
P_0c069658: /* original f86c, guest PC 0x0c069658 */
if(!s->budget--) { s->failed_pc=0x0c069658u; return 0; }
vf3_matrix_move(s,8,6);
goto P_0c06965a;
P_0c06965a: /* original f873, guest PC 0x0c06965a */
if(!s->budget--) { s->failed_pc=0x0c06965au; return 0; }
fr[8]=vf3_fpu_binary(fr[8],fr[7],r[18],'/');
goto P_0c06965c;
P_0c06965c: /* original c711, guest PC 0x0c06965c */
if(!s->budget--) { s->failed_pc=0x0c06965cu; return 0; }
r[0]=0x0c0696a4u;
goto P_0c06965e;
P_0c06965e: /* original f28c, guest PC 0x0c06965e */
if(!s->budget--) { s->failed_pc=0x0c06965eu; return 0; }
vf3_matrix_move(s,2,8);
goto P_0c069660;
P_0c069660: /* original f308, guest PC 0x0c069660 */
if(!s->budget--) { s->failed_pc=0x0c069660u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c069662;
P_0c069662: /* original d011, guest PC 0x0c069662 */
if(!s->budget--) { s->failed_pc=0x0c069662u; return 0; }
r[0]=read(ram,0x0c0696a8u,4);
goto P_0c069664;
P_0c069664: /* original f232, guest PC 0x0c069664 */
if(!s->budget--) { s->failed_pc=0x0c069664u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c069666;
P_0c069666: /* original f23d, guest PC 0x0c069666 */
if(!s->budget--) { s->failed_pc=0x0c069666u; return 0; }
r[53]=truncate_float(fr[2]);
goto P_0c069668;
P_0c069668: /* original 045a, guest PC 0x0c069668 */
if(!s->budget--) { s->failed_pc=0x0c069668u; return 0; }
r[4]=r[53];
goto P_0c06966a;
P_0c06966a: /* original 4400, guest PC 0x0c06966a */
if(!s->budget--) { s->failed_pc=0x0c06966au; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c06966c;
P_0c06966c: /* original f765, guest PC 0x0c06966c */
if(!s->budget--) { s->failed_pc=0x0c06966cu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[7])>as_float(fr[6]))!=0);
goto P_0c06966e;
P_0c06966e: /* original 8f03, guest PC 0x0c06966e */
if(!s->budget--) { s->failed_pc=0x0c06966eu; return 0; }
cond=r[17]&1u;
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
if(!cond) { goto P_0c069678; }
goto P_0c069672;
P_0c069670: /* original 044d, guest PC 0x0c069670 */
if(!s->budget--) { s->failed_pc=0x0c069670u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c069672;
P_0c069672: /* original 9214, guest PC 0x0c069672 */
if(!s->budget--) { s->failed_pc=0x0c069672u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06969eu,2);
goto P_0c069674;
P_0c069674: /* original 3248, guest PC 0x0c069674 */
if(!s->budget--) { s->failed_pc=0x0c069674u; return 0; }
r[2]-=r[4];
goto P_0c069676;
P_0c069676: /* original 6423, guest PC 0x0c069676 */
if(!s->budget--) { s->failed_pc=0x0c069676u; return 0; }
r[4]=r[2];
goto P_0c069678;
P_0c069678: /* original f38d, guest PC 0x0c069678 */
if(!s->budget--) { s->failed_pc=0x0c069678u; return 0; }
fr[3]=0;
goto P_0c06967a;
P_0c06967a: /* original f355, guest PC 0x0c06967a */
if(!s->budget--) { s->failed_pc=0x0c06967au; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[5]))!=0);
goto P_0c06967c;
P_0c06967c: /* original 8904, guest PC 0x0c06967c */
if(!s->budget--) { s->failed_pc=0x0c06967cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c069688; }
goto P_0c06967e;
P_0c06967e: /* original f38d, guest PC 0x0c06967e */
if(!s->budget--) { s->failed_pc=0x0c06967eu; return 0; }
fr[3]=0;
goto P_0c069680;
P_0c069680: /* original f345, guest PC 0x0c069680 */
if(!s->budget--) { s->failed_pc=0x0c069680u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[4]))!=0);
goto P_0c069682;
P_0c069682: /* original 8b09, guest PC 0x0c069682 */
if(!s->budget--) { s->failed_pc=0x0c069682u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c069698; }
goto P_0c069684;
P_0c069684: /* original a008, guest PC 0x0c069684 */
if(!s->budget--) { s->failed_pc=0x0c069684u; return 0; }
r[4]=0u-r[4];
goto P_0c069698;
P_0c069686: /* original 644b, guest PC 0x0c069686 */
if(!s->budget--) { s->failed_pc=0x0c069686u; return 0; }
r[4]=0u-r[4];
goto P_0c069688;
P_0c069688: /* original f345, guest PC 0x0c069688 */
if(!s->budget--) { s->failed_pc=0x0c069688u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[4]))!=0);
goto P_0c06968a;
P_0c06968a: /* original 8903, guest PC 0x0c06968a */
if(!s->budget--) { s->failed_pc=0x0c06968au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c069694; }
goto P_0c06968c;
P_0c06968c: /* original d207, guest PC 0x0c06968c */
if(!s->budget--) { s->failed_pc=0x0c06968cu; return 0; }
r[2]=read(ram,0x0c0696acu,4);
goto P_0c06968e;
P_0c06968e: /* original 3248, guest PC 0x0c06968e */
if(!s->budget--) { s->failed_pc=0x0c06968eu; return 0; }
r[2]-=r[4];
goto P_0c069690;
P_0c069690: /* original a002, guest PC 0x0c069690 */
if(!s->budget--) { s->failed_pc=0x0c069690u; return 0; }
r[4]=r[2];
goto P_0c069698;
P_0c069692: /* original 6423, guest PC 0x0c069692 */
if(!s->budget--) { s->failed_pc=0x0c069692u; return 0; }
r[4]=r[2];
goto P_0c069694;
P_0c069694: /* original 9104, guest PC 0x0c069694 */
if(!s->budget--) { s->failed_pc=0x0c069694u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0696a0u,2);
goto P_0c069696;
P_0c069696: /* original 341c, guest PC 0x0c069696 */
if(!s->budget--) { s->failed_pc=0x0c069696u; return 0; }
r[4]+=r[1];
goto P_0c069698;
P_0c069698: /* original 6043, guest PC 0x0c069698 */
if(!s->budget--) { s->failed_pc=0x0c069698u; return 0; }
r[0]=r[4];
goto P_0c06969a;
P_0c06969a: /* original 000b, guest PC 0x0c06969a */
if(!s->budget--) { s->failed_pc=0x0c06969au; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c06969c: /* original 0009, guest PC 0x0c06969c */
if(!s->budget--) { s->failed_pc=0x0c06969cu; return 0; }
return vf3_matrix_family(0x0c06969eu,s,ram);
P_0c06f77c: /* original f40b, guest PC 0x0c06f77c */
if(!s->budget--) { s->failed_pc=0x0c06f77cu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c06f77e;
P_0c06f77e: /* original 0009, guest PC 0x0c06f77e */
if(!s->budget--) { s->failed_pc=0x0c06f77eu; return 0; }
goto P_0c06f780;
P_0c06f780: /* original 65f3, guest PC 0x0c06f780 */
if(!s->budget--) { s->failed_pc=0x0c06f780u; return 0; }
r[5]=r[15];
goto P_0c06f782;
P_0c06f782: /* original 64d3, guest PC 0x0c06f782 */
if(!s->budget--) { s->failed_pc=0x0c06f782u; return 0; }
r[4]=r[13];
goto P_0c06f784;
P_0c06f784: /* original 7550, guest PC 0x0c06f784 */
if(!s->budget--) { s->failed_pc=0x0c06f784u; return 0; }
r[5]+=0x00000050u;
goto P_0c06f786;
P_0c06f786: /* original f449, guest PC 0x0c06f786 */
if(!s->budget--) { s->failed_pc=0x0c06f786u; return 0; }
vf3_matrix_load(s,ram,4,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c06f788;
P_0c06f788: /* original f549, guest PC 0x0c06f788 */
if(!s->budget--) { s->failed_pc=0x0c06f788u; return 0; }
vf3_matrix_load(s,ram,5,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c06f78a;
P_0c06f78a: /* original f648, guest PC 0x0c06f78a */
if(!s->budget--) { s->failed_pc=0x0c06f78au; return 0; }
vf3_matrix_load(s,ram,6,r[4]);
goto P_0c06f78c;
P_0c06f78c: /* original f79d, guest PC 0x0c06f78c */
if(!s->budget--) { s->failed_pc=0x0c06f78cu; return 0; }
fr[7]=0x3f800000u;
goto P_0c06f78e;
P_0c06f78e: /* original f5fd, guest PC 0x0c06f78e */
if(!s->budget--) { s->failed_pc=0x0c06f78eu; return 0; }
if(!vf3_fpu_ftrv(xf,fr+4,r[18],fr+4)) goto unsupported;
goto P_0c06f790;
P_0c06f790: /* original 750c, guest PC 0x0c06f790 */
if(!s->budget--) { s->failed_pc=0x0c06f790u; return 0; }
r[5]+=0x0000000cu;
goto P_0c06f792;
P_0c06f792: /* original f56b, guest PC 0x0c06f792 */
if(!s->budget--) { s->failed_pc=0x0c06f792u; return 0; }
r[5]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,6,r[5]);
goto P_0c06f794;
P_0c06f794: /* original f55b, guest PC 0x0c06f794 */
if(!s->budget--) { s->failed_pc=0x0c06f794u; return 0; }
r[5]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,5,r[5]);
goto P_0c06f796;
P_0c06f796: /* original f54b, guest PC 0x0c06f796 */
if(!s->budget--) { s->failed_pc=0x0c06f796u; return 0; }
r[5]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,4,r[5]);
goto P_0c06f798;
P_0c06f798: /* original 64f3, guest PC 0x0c06f798 */
if(!s->budget--) { s->failed_pc=0x0c06f798u; return 0; }
r[4]=r[15];
goto P_0c06f79a;
P_0c06f79a: /* original 65f3, guest PC 0x0c06f79a */
if(!s->budget--) { s->failed_pc=0x0c06f79au; return 0; }
r[5]=r[15];
goto P_0c06f79c;
P_0c06f79c: /* original 745c, guest PC 0x0c06f79c */
if(!s->budget--) { s->failed_pc=0x0c06f79cu; return 0; }
r[4]+=0x0000005cu;
goto P_0c06f79e;
P_0c06f79e: /* original 66d3, guest PC 0x0c06f79e */
if(!s->budget--) { s->failed_pc=0x0c06f79eu; return 0; }
r[6]=r[13];
goto P_0c06f7a0;
P_0c06f7a0: /* original 7550, guest PC 0x0c06f7a0 */
if(!s->budget--) { s->failed_pc=0x0c06f7a0u; return 0; }
r[5]+=0x00000050u;
goto P_0c06f7a2;
P_0c06f7a2: /* original f059, guest PC 0x0c06f7a2 */
if(!s->budget--) { s->failed_pc=0x0c06f7a2u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c06f7a4;
P_0c06f7a4: /* original f369, guest PC 0x0c06f7a4 */
if(!s->budget--) { s->failed_pc=0x0c06f7a4u; return 0; }
vf3_matrix_load(s,ram,3,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c06f7a6;
P_0c06f7a6: /* original f159, guest PC 0x0c06f7a6 */
if(!s->budget--) { s->failed_pc=0x0c06f7a6u; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c06f7a8;
P_0c06f7a8: /* original f469, guest PC 0x0c06f7a8 */
if(!s->budget--) { s->failed_pc=0x0c06f7a8u; return 0; }
vf3_matrix_load(s,ram,4,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c06f7aa;
P_0c06f7aa: /* original f031, guest PC 0x0c06f7aa */
if(!s->budget--) { s->failed_pc=0x0c06f7aau; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'-');
goto P_0c06f7ac;
P_0c06f7ac: /* original f258, guest PC 0x0c06f7ac */
if(!s->budget--) { s->failed_pc=0x0c06f7acu; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
goto P_0c06f7ae;
P_0c06f7ae: /* original f568, guest PC 0x0c06f7ae */
if(!s->budget--) { s->failed_pc=0x0c06f7aeu; return 0; }
vf3_matrix_load(s,ram,5,r[6]);
goto P_0c06f7b0;
P_0c06f7b0: /* original f141, guest PC 0x0c06f7b0 */
if(!s->budget--) { s->failed_pc=0x0c06f7b0u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'-');
goto P_0c06f7b2;
P_0c06f7b2: /* original f251, guest PC 0x0c06f7b2 */
if(!s->budget--) { s->failed_pc=0x0c06f7b2u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'-');
goto P_0c06f7b4;
P_0c06f7b4: /* original 7408, guest PC 0x0c06f7b4 */
if(!s->budget--) { s->failed_pc=0x0c06f7b4u; return 0; }
r[4]+=0x00000008u;
goto P_0c06f7b6;
P_0c06f7b6: /* original f42a, guest PC 0x0c06f7b6 */
if(!s->budget--) { s->failed_pc=0x0c06f7b6u; return 0; }
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c06f7b8;
P_0c06f7b8: /* original f41b, guest PC 0x0c06f7b8 */
if(!s->budget--) { s->failed_pc=0x0c06f7b8u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c06f7ba;
P_0c06f7ba: /* original f40b, guest PC 0x0c06f7ba */
if(!s->budget--) { s->failed_pc=0x0c06f7bau; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c06f7bc;
P_0c06f7bc: /* original 64f3, guest PC 0x0c06f7bc */
if(!s->budget--) { s->failed_pc=0x0c06f7bcu; return 0; }
r[4]=r[15];
goto P_0c06f7be;
P_0c06f7be: /* original 65f3, guest PC 0x0c06f7be */
if(!s->budget--) { s->failed_pc=0x0c06f7beu; return 0; }
r[5]=r[15];
goto P_0c06f7c0;
P_0c06f7c0: /* original 745c, guest PC 0x0c06f7c0 */
if(!s->budget--) { s->failed_pc=0x0c06f7c0u; return 0; }
r[4]+=0x0000005cu;
goto P_0c06f7c2;
P_0c06f7c2: /* original f4dc, guest PC 0x0c06f7c2 */
if(!s->budget--) { s->failed_pc=0x0c06f7c2u; return 0; }
vf3_matrix_move(s,4,13);
goto P_0c06f7c4;
P_0c06f7c4: /* original 755c, guest PC 0x0c06f7c4 */
if(!s->budget--) { s->failed_pc=0x0c06f7c4u; return 0; }
r[5]+=0x0000005cu;
goto P_0c06f7c6;
P_0c06f7c6: /* original f059, guest PC 0x0c06f7c6 */
if(!s->budget--) { s->failed_pc=0x0c06f7c6u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c06f7c8;
P_0c06f7c8: /* original f159, guest PC 0x0c06f7c8 */
if(!s->budget--) { s->failed_pc=0x0c06f7c8u; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c06f7ca;
P_0c06f7ca: /* original f259, guest PC 0x0c06f7ca */
if(!s->budget--) { s->failed_pc=0x0c06f7cau; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c06f7cc;
P_0c06f7cc: /* original 740c, guest PC 0x0c06f7cc */
if(!s->budget--) { s->failed_pc=0x0c06f7ccu; return 0; }
r[4]+=0x0000000cu;
goto P_0c06f7ce;
P_0c06f7ce: /* original f242, guest PC 0x0c06f7ce */
if(!s->budget--) { s->failed_pc=0x0c06f7ceu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[4],r[18],'*');
goto P_0c06f7d0;
P_0c06f7d0: /* original f142, guest PC 0x0c06f7d0 */
if(!s->budget--) { s->failed_pc=0x0c06f7d0u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'*');
goto P_0c06f7d2;
P_0c06f7d2: /* original f042, guest PC 0x0c06f7d2 */
if(!s->budget--) { s->failed_pc=0x0c06f7d2u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[4],r[18],'*');
goto P_0c06f7d4;
P_0c06f7d4: /* original f42b, guest PC 0x0c06f7d4 */
if(!s->budget--) { s->failed_pc=0x0c06f7d4u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c06f7d6;
P_0c06f7d6: /* original f41b, guest PC 0x0c06f7d6 */
if(!s->budget--) { s->failed_pc=0x0c06f7d6u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c06f7d8;
P_0c06f7d8: /* original f40b, guest PC 0x0c06f7d8 */
if(!s->budget--) { s->failed_pc=0x0c06f7d8u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c06f7da;
P_0c06f7da: /* original 0009, guest PC 0x0c06f7da */
if(!s->budget--) { s->failed_pc=0x0c06f7dau; return 0; }
goto P_0c06f7dc;
P_0c06f7dc: /* original 64f3, guest PC 0x0c06f7dc */
if(!s->budget--) { s->failed_pc=0x0c06f7dcu; return 0; }
r[4]=r[15];
goto P_0c06f7de;
P_0c06f7de: /* original 745c, guest PC 0x0c06f7de */
if(!s->budget--) { s->failed_pc=0x0c06f7deu; return 0; }
r[4]+=0x0000005cu;
goto P_0c06f7e0;
P_0c06f7e0: /* original f049, guest PC 0x0c06f7e0 */
if(!s->budget--) { s->failed_pc=0x0c06f7e0u; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c06f7e2;
P_0c06f7e2: /* original f149, guest PC 0x0c06f7e2 */
if(!s->budget--) { s->failed_pc=0x0c06f7e2u; return 0; }
vf3_matrix_load(s,ram,1,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c06f7e4;
P_0c06f7e4: /* original f249, guest PC 0x0c06f7e4 */
if(!s->budget--) { s->failed_pc=0x0c06f7e4u; return 0; }
vf3_matrix_load(s,ram,2,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c06f7e6;
P_0c06f7e6: /* original f38d, guest PC 0x0c06f7e6 */
if(!s->budget--) { s->failed_pc=0x0c06f7e6u; return 0; }
fr[3]=0;
goto P_0c06f7e8;
P_0c06f7e8: /* original f0ed, guest PC 0x0c06f7e8 */
if(!s->budget--) { s->failed_pc=0x0c06f7e8u; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+0,r[18],fr+3)) goto unsupported;
goto P_0c06f7ea;
P_0c06f7ea: /* original f03c, guest PC 0x0c06f7ea */
if(!s->budget--) { s->failed_pc=0x0c06f7eau; return 0; }
vf3_matrix_move(s,0,3);
goto P_0c06f7ec;
P_0c06f7ec: /* original f06d, guest PC 0x0c06f7ec */
if(!s->budget--) { s->failed_pc=0x0c06f7ecu; return 0; }
fr[0]=vf3_fpu_sqrt(fr[0],r[18]);
goto P_0c06f7ee;
P_0c06f7ee: /* original 0009, guest PC 0x0c06f7ee */
if(!s->budget--) { s->failed_pc=0x0c06f7eeu; return 0; }
goto P_0c06f7f0;
P_0c06f7f0: /* original 65f3, guest PC 0x0c06f7f0 */
if(!s->budget--) { s->failed_pc=0x0c06f7f0u; return 0; }
r[5]=r[15];
goto P_0c06f7f2;
P_0c06f7f2: /* original 64f3, guest PC 0x0c06f7f2 */
if(!s->budget--) { s->failed_pc=0x0c06f7f2u; return 0; }
r[4]=r[15];
goto P_0c06f7f4;
P_0c06f7f4: /* original 66f3, guest PC 0x0c06f7f4 */
if(!s->budget--) { s->failed_pc=0x0c06f7f4u; return 0; }
r[6]=r[15];
goto P_0c06f7f6;
P_0c06f7f6: /* original 7444, guest PC 0x0c06f7f6 */
if(!s->budget--) { s->failed_pc=0x0c06f7f6u; return 0; }
r[4]+=0x00000044u;
goto P_0c06f7f8;
P_0c06f7f8: /* original 7668, guest PC 0x0c06f7f8 */
if(!s->budget--) { s->failed_pc=0x0c06f7f8u; return 0; }
r[6]+=0x00000068u;
goto P_0c06f7fa;
P_0c06f7fa: /* original 755c, guest PC 0x0c06f7fa */
if(!s->budget--) { s->failed_pc=0x0c06f7fau; return 0; }
r[5]+=0x0000005cu;
goto P_0c06f7fc;
P_0c06f7fc: /* original f059, guest PC 0x0c06f7fc */
if(!s->budget--) { s->failed_pc=0x0c06f7fcu; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c06f7fe;
P_0c06f7fe: /* original f369, guest PC 0x0c06f7fe */
if(!s->budget--) { s->failed_pc=0x0c06f7feu; return 0; }
vf3_matrix_load(s,ram,3,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c06f800;
P_0c06f800: /* original f159, guest PC 0x0c06f800 */
if(!s->budget--) { s->failed_pc=0x0c06f800u; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c06f802;
P_0c06f802: /* original f469, guest PC 0x0c06f802 */
if(!s->budget--) { s->failed_pc=0x0c06f802u; return 0; }
vf3_matrix_load(s,ram,4,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c06f804;
P_0c06f804: /* original f259, guest PC 0x0c06f804 */
if(!s->budget--) { s->failed_pc=0x0c06f804u; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c06f806;
P_0c06f806: /* original f569, guest PC 0x0c06f806 */
if(!s->budget--) { s->failed_pc=0x0c06f806u; return 0; }
vf3_matrix_load(s,ram,5,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c06f808;
P_0c06f808: /* original 740c, guest PC 0x0c06f808 */
if(!s->budget--) { s->failed_pc=0x0c06f808u; return 0; }
r[4]+=0x0000000cu;
goto P_0c06f80a;
P_0c06f80a: /* original f030, guest PC 0x0c06f80a */
if(!s->budget--) { s->failed_pc=0x0c06f80au; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'+');
goto P_0c06f80c;
P_0c06f80c: /* original f250, guest PC 0x0c06f80c */
if(!s->budget--) { s->failed_pc=0x0c06f80cu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'+');
goto P_0c06f80e;
P_0c06f80e: /* original f140, guest PC 0x0c06f80e */
if(!s->budget--) { s->failed_pc=0x0c06f80eu; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'+');
goto P_0c06f810;
P_0c06f810: /* original f42b, guest PC 0x0c06f810 */
if(!s->budget--) { s->failed_pc=0x0c06f810u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c06f812;
P_0c06f812: /* original f41b, guest PC 0x0c06f812 */
if(!s->budget--) { s->failed_pc=0x0c06f812u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c06f814;
P_0c06f814: /* original f40b, guest PC 0x0c06f814 */
if(!s->budget--) { s->failed_pc=0x0c06f814u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c06f816;
P_0c06f816: /* original 0009, guest PC 0x0c06f816 */
if(!s->budget--) { s->failed_pc=0x0c06f816u; return 0; }
goto P_0c06f818;
P_0c06f818: /* original e038, guest PC 0x0c06f818 */
if(!s->budget--) { s->failed_pc=0x0c06f818u; return 0; }
r[0]=0x00000038u;
goto P_0c06f81a;
P_0c06f81a: /* original 65f3, guest PC 0x0c06f81a */
if(!s->budget--) { s->failed_pc=0x0c06f81au; return 0; }
r[5]=r[15];
goto P_0c06f81c;
P_0c06f81c: /* original f3f6, guest PC 0x0c06f81c */
if(!s->budget--) { s->failed_pc=0x0c06f81cu; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c06f81e;
P_0c06f81e: /* original e02c, guest PC 0x0c06f81e */
if(!s->budget--) { s->failed_pc=0x0c06f81eu; return 0; }
r[0]=0x0000002cu;
goto P_0c06f820;
P_0c06f820: /* original 64f3, guest PC 0x0c06f820 */
if(!s->budget--) { s->failed_pc=0x0c06f820u; return 0; }
r[4]=r[15];
goto P_0c06f822;
P_0c06f822: /* original 742c, guest PC 0x0c06f822 */
if(!s->budget--) { s->failed_pc=0x0c06f822u; return 0; }
r[4]+=0x0000002cu;
goto P_0c06f824;
P_0c06f824: /* original ff37, guest PC 0x0c06f824 */
if(!s->budget--) { s->failed_pc=0x0c06f824u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c06f826;
P_0c06f826: /* original e03c, guest PC 0x0c06f826 */
if(!s->budget--) { s->failed_pc=0x0c06f826u; return 0; }
r[0]=0x0000003cu;
goto P_0c06f828;
P_0c06f828: /* original f3f6, guest PC 0x0c06f828 */
if(!s->budget--) { s->failed_pc=0x0c06f828u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c06f82a;
P_0c06f82a: /* original e030, guest PC 0x0c06f82a */
if(!s->budget--) { s->failed_pc=0x0c06f82au; return 0; }
r[0]=0x00000030u;
goto P_0c06f82c;
P_0c06f82c: /* original 7544, guest PC 0x0c06f82c */
if(!s->budget--) { s->failed_pc=0x0c06f82cu; return 0; }
r[5]+=0x00000044u;
goto P_0c06f82e;
P_0c06f82e: /* original ff37, guest PC 0x0c06f82e */
if(!s->budget--) { s->failed_pc=0x0c06f82eu; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c06f830;
P_0c06f830: /* original e040, guest PC 0x0c06f830 */
if(!s->budget--) { s->failed_pc=0x0c06f830u; return 0; }
r[0]=0x00000040u;
goto P_0c06f832;
P_0c06f832: /* original f3f6, guest PC 0x0c06f832 */
if(!s->budget--) { s->failed_pc=0x0c06f832u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c06f834;
P_0c06f834: /* original e034, guest PC 0x0c06f834 */
if(!s->budget--) { s->failed_pc=0x0c06f834u; return 0; }
r[0]=0x00000034u;
goto P_0c06f836;
P_0c06f836: /* original ff37, guest PC 0x0c06f836 */
if(!s->budget--) { s->failed_pc=0x0c06f836u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c06f838;
P_0c06f838: /* original f049, guest PC 0x0c06f838 */
if(!s->budget--) { s->failed_pc=0x0c06f838u; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c06f83a;
P_0c06f83a: /* original f149, guest PC 0x0c06f83a */
if(!s->budget--) { s->failed_pc=0x0c06f83au; return 0; }
vf3_matrix_load(s,ram,1,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c06f83c;
P_0c06f83c: /* original f249, guest PC 0x0c06f83c */
if(!s->budget--) { s->failed_pc=0x0c06f83cu; return 0; }
vf3_matrix_load(s,ram,2,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c06f83e;
P_0c06f83e: /* original f38d, guest PC 0x0c06f83e */
if(!s->budget--) { s->failed_pc=0x0c06f83eu; return 0; }
fr[3]=0;
goto P_0c06f840;
P_0c06f840: /* original f459, guest PC 0x0c06f840 */
if(!s->budget--) { s->failed_pc=0x0c06f840u; return 0; }
vf3_matrix_load(s,ram,4,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c06f842;
P_0c06f842: /* original f559, guest PC 0x0c06f842 */
if(!s->budget--) { s->failed_pc=0x0c06f842u; return 0; }
vf3_matrix_load(s,ram,5,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c06f844;
P_0c06f844: /* original f659, guest PC 0x0c06f844 */
if(!s->budget--) { s->failed_pc=0x0c06f844u; return 0; }
vf3_matrix_load(s,ram,6,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c06f846;
P_0c06f846: /* original f78d, guest PC 0x0c06f846 */
if(!s->budget--) { s->failed_pc=0x0c06f846u; return 0; }
fr[7]=0;
goto P_0c06f848;
P_0c06f848: /* original f4ed, guest PC 0x0c06f848 */
if(!s->budget--) { s->failed_pc=0x0c06f848u; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+4,r[18],fr+7)) goto unsupported;
goto P_0c06f84a;
P_0c06f84a: /* original f07c, guest PC 0x0c06f84a */
if(!s->budget--) { s->failed_pc=0x0c06f84au; return 0; }
vf3_matrix_move(s,0,7);
goto P_0c06f84c;
P_0c06f84c: /* original 64f3, guest PC 0x0c06f84c */
if(!s->budget--) { s->failed_pc=0x0c06f84cu; return 0; }
r[4]=r[15];
goto P_0c06f84e;
P_0c06f84e: /* original 65f3, guest PC 0x0c06f84e */
if(!s->budget--) { s->failed_pc=0x0c06f84eu; return 0; }
r[5]=r[15];
goto P_0c06f850;
P_0c06f850: /* original 7420, guest PC 0x0c06f850 */
if(!s->budget--) { s->failed_pc=0x0c06f850u; return 0; }
r[4]+=0x00000020u;
goto P_0c06f852;
P_0c06f852: /* original f40c, guest PC 0x0c06f852 */
if(!s->budget--) { s->failed_pc=0x0c06f852u; return 0; }
vf3_matrix_move(s,4,0);
goto P_0c06f854;
P_0c06f854: /* original 752c, guest PC 0x0c06f854 */
if(!s->budget--) { s->failed_pc=0x0c06f854u; return 0; }
r[5]+=0x0000002cu;
goto P_0c06f856;
P_0c06f856: /* original f059, guest PC 0x0c06f856 */
if(!s->budget--) { s->failed_pc=0x0c06f856u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c06f858;
P_0c06f858: /* original f159, guest PC 0x0c06f858 */
if(!s->budget--) { s->failed_pc=0x0c06f858u; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c06f85a;
P_0c06f85a: /* original f259, guest PC 0x0c06f85a */
if(!s->budget--) { s->failed_pc=0x0c06f85au; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c06f85c;
P_0c06f85c: /* original f38d, guest PC 0x0c06f85c */
if(!s->budget--) { s->failed_pc=0x0c06f85cu; return 0; }
fr[3]=0;
goto P_0c06f85e;
P_0c06f85e: /* original f0ed, guest PC 0x0c06f85e */
if(!s->budget--) { s->failed_pc=0x0c06f85eu; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+0,r[18],fr+3)) goto unsupported;
goto P_0c06f860;
P_0c06f860: /* original f37d, guest PC 0x0c06f860 */
if(!s->budget--) { s->failed_pc=0x0c06f860u; return 0; }
if(!vf3_fpu_fsrra(fr[3],r[18],&fr[3])) goto unsupported;
goto P_0c06f862;
P_0c06f862: /* original f342, guest PC 0x0c06f862 */
if(!s->budget--) { s->failed_pc=0x0c06f862u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'*');
goto P_0c06f864;
P_0c06f864: /* original 740c, guest PC 0x0c06f864 */
if(!s->budget--) { s->failed_pc=0x0c06f864u; return 0; }
r[4]+=0x0000000cu;
goto P_0c06f866;
P_0c06f866: /* original f232, guest PC 0x0c06f866 */
if(!s->budget--) { s->failed_pc=0x0c06f866u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c06f868;
P_0c06f868: /* original f132, guest PC 0x0c06f868 */
if(!s->budget--) { s->failed_pc=0x0c06f868u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[3],r[18],'*');
goto P_0c06f86a;
P_0c06f86a: /* original f032, guest PC 0x0c06f86a */
if(!s->budget--) { s->failed_pc=0x0c06f86au; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'*');
goto P_0c06f86c;
P_0c06f86c: /* original f42b, guest PC 0x0c06f86c */
if(!s->budget--) { s->failed_pc=0x0c06f86cu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c06f86e;
P_0c06f86e: /* original f41b, guest PC 0x0c06f86e */
if(!s->budget--) { s->failed_pc=0x0c06f86eu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c06f870;
P_0c06f870: /* original f40b, guest PC 0x0c06f870 */
if(!s->budget--) { s->failed_pc=0x0c06f870u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c06f872;
P_0c06f872: /* original 0009, guest PC 0x0c06f872 */
if(!s->budget--) { s->failed_pc=0x0c06f872u; return 0; }
goto P_0c06f874;
P_0c06f874: /* original 64f3, guest PC 0x0c06f874 */
if(!s->budget--) { s->failed_pc=0x0c06f874u; return 0; }
r[4]=r[15];
goto P_0c06f876;
P_0c06f876: /* original 65f3, guest PC 0x0c06f876 */
if(!s->budget--) { s->failed_pc=0x0c06f876u; return 0; }
r[5]=r[15];
goto P_0c06f878;
P_0c06f878: /* original 7444, guest PC 0x0c06f878 */
if(!s->budget--) { s->failed_pc=0x0c06f878u; return 0; }
r[4]+=0x00000044u;
goto P_0c06f87a;
P_0c06f87a: /* original 7520, guest PC 0x0c06f87a */
if(!s->budget--) { s->failed_pc=0x0c06f87au; return 0; }
r[5]+=0x00000020u;
goto P_0c06f87c;
P_0c06f87c: /* original f049, guest PC 0x0c06f87c */
if(!s->budget--) { s->failed_pc=0x0c06f87cu; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c06f87e;
P_0c06f87e: /* original f359, guest PC 0x0c06f87e */
if(!s->budget--) { s->failed_pc=0x0c06f87eu; return 0; }
vf3_matrix_load(s,ram,3,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c06f880;
P_0c06f880: /* original f149, guest PC 0x0c06f880 */
if(!s->budget--) { s->failed_pc=0x0c06f880u; return 0; }
vf3_matrix_load(s,ram,1,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c06f882;
P_0c06f882: /* original f459, guest PC 0x0c06f882 */
if(!s->budget--) { s->failed_pc=0x0c06f882u; return 0; }
vf3_matrix_load(s,ram,4,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c06f884;
P_0c06f884: /* original f249, guest PC 0x0c06f884 */
if(!s->budget--) { s->failed_pc=0x0c06f884u; return 0; }
vf3_matrix_load(s,ram,2,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c06f886;
P_0c06f886: /* original f559, guest PC 0x0c06f886 */
if(!s->budget--) { s->failed_pc=0x0c06f886u; return 0; }
vf3_matrix_load(s,ram,5,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c06f888;
P_0c06f888: /* original f031, guest PC 0x0c06f888 */
if(!s->budget--) { s->failed_pc=0x0c06f888u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'-');
goto P_0c06f88a;
P_0c06f88a: /* original f251, guest PC 0x0c06f88a */
if(!s->budget--) { s->failed_pc=0x0c06f88au; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'-');
goto P_0c06f88c;
P_0c06f88c: /* original f141, guest PC 0x0c06f88c */
if(!s->budget--) { s->failed_pc=0x0c06f88cu; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'-');
goto P_0c06f88e;
P_0c06f88e: /* original f42b, guest PC 0x0c06f88e */
if(!s->budget--) { s->failed_pc=0x0c06f88eu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c06f890;
P_0c06f890: /* original f41b, guest PC 0x0c06f890 */
if(!s->budget--) { s->failed_pc=0x0c06f890u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c06f892;
P_0c06f892: /* original f40b, guest PC 0x0c06f892 */
if(!s->budget--) { s->failed_pc=0x0c06f892u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c06f894;
P_0c06f894: /* original 65f3, guest PC 0x0c06f894 */
if(!s->budget--) { s->failed_pc=0x0c06f894u; return 0; }
r[5]=r[15];
goto P_0c06f896;
P_0c06f896: /* original 64f3, guest PC 0x0c06f896 */
if(!s->budget--) { s->failed_pc=0x0c06f896u; return 0; }
r[4]=r[15];
goto P_0c06f898;
P_0c06f898: /* original 66f3, guest PC 0x0c06f898 */
if(!s->budget--) { s->failed_pc=0x0c06f898u; return 0; }
r[6]=r[15];
goto P_0c06f89a;
P_0c06f89a: /* original 742c, guest PC 0x0c06f89a */
if(!s->budget--) { s->failed_pc=0x0c06f89au; return 0; }
r[4]+=0x0000002cu;
goto P_0c06f89c;
P_0c06f89c: /* original 7644, guest PC 0x0c06f89c */
if(!s->budget--) { s->failed_pc=0x0c06f89cu; return 0; }
r[6]+=0x00000044u;
goto P_0c06f89e;
P_0c06f89e: /* original 7538, guest PC 0x0c06f89e */
if(!s->budget--) { s->failed_pc=0x0c06f89eu; return 0; }
r[5]+=0x00000038u;
goto P_0c06f8a0;
P_0c06f8a0: /* original f059, guest PC 0x0c06f8a0 */
if(!s->budget--) { s->failed_pc=0x0c06f8a0u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c06f8a2;
P_0c06f8a2: /* original f369, guest PC 0x0c06f8a2 */
if(!s->budget--) { s->failed_pc=0x0c06f8a2u; return 0; }
vf3_matrix_load(s,ram,3,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c06f8a4;
P_0c06f8a4: /* original f159, guest PC 0x0c06f8a4 */
if(!s->budget--) { s->failed_pc=0x0c06f8a4u; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c06f8a6;
P_0c06f8a6: /* original f469, guest PC 0x0c06f8a6 */
if(!s->budget--) { s->failed_pc=0x0c06f8a6u; return 0; }
vf3_matrix_load(s,ram,4,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c06f8a8;
P_0c06f8a8: /* original f259, guest PC 0x0c06f8a8 */
if(!s->budget--) { s->failed_pc=0x0c06f8a8u; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c06f8aa;
P_0c06f8aa: /* original f569, guest PC 0x0c06f8aa */
if(!s->budget--) { s->failed_pc=0x0c06f8aau; return 0; }
vf3_matrix_load(s,ram,5,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c06f8ac;
P_0c06f8ac: /* original 740c, guest PC 0x0c06f8ac */
if(!s->budget--) { s->failed_pc=0x0c06f8acu; return 0; }
r[4]+=0x0000000cu;
goto P_0c06f8ae;
P_0c06f8ae: /* original f030, guest PC 0x0c06f8ae */
if(!s->budget--) { s->failed_pc=0x0c06f8aeu; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'+');
goto P_0c06f8b0;
P_0c06f8b0: /* original f250, guest PC 0x0c06f8b0 */
if(!s->budget--) { s->failed_pc=0x0c06f8b0u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'+');
goto P_0c06f8b2;
P_0c06f8b2: /* original f140, guest PC 0x0c06f8b2 */
if(!s->budget--) { s->failed_pc=0x0c06f8b2u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'+');
goto P_0c06f8b4;
P_0c06f8b4: /* original f42b, guest PC 0x0c06f8b4 */
if(!s->budget--) { s->failed_pc=0x0c06f8b4u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c06f8b6;
P_0c06f8b6: /* original f41b, guest PC 0x0c06f8b6 */
if(!s->budget--) { s->failed_pc=0x0c06f8b6u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c06f8b8;
P_0c06f8b8: /* original f40b, guest PC 0x0c06f8b8 */
if(!s->budget--) { s->failed_pc=0x0c06f8b8u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c06f8ba;
P_0c06f8ba: /* original 0009, guest PC 0x0c06f8ba */
if(!s->budget--) { s->failed_pc=0x0c06f8bau; return 0; }
goto P_0c06f8bc;
P_0c06f8bc: /* original 64f3, guest PC 0x0c06f8bc */
if(!s->budget--) { s->failed_pc=0x0c06f8bcu; return 0; }
r[4]=r[15];
goto P_0c06f8be;
P_0c06f8be: /* original 65f3, guest PC 0x0c06f8be */
if(!s->budget--) { s->failed_pc=0x0c06f8beu; return 0; }
r[5]=r[15];
goto P_0c06f8c0;
P_0c06f8c0: /* original 742c, guest PC 0x0c06f8c0 */
if(!s->budget--) { s->failed_pc=0x0c06f8c0u; return 0; }
r[4]+=0x0000002cu;
goto P_0c06f8c2;
P_0c06f8c2: /* original f4ec, guest PC 0x0c06f8c2 */
if(!s->budget--) { s->failed_pc=0x0c06f8c2u; return 0; }
vf3_matrix_move(s,4,14);
goto P_0c06f8c4;
P_0c06f8c4: /* original 752c, guest PC 0x0c06f8c4 */
if(!s->budget--) { s->failed_pc=0x0c06f8c4u; return 0; }
r[5]+=0x0000002cu;
goto P_0c06f8c6;
P_0c06f8c6: /* original f059, guest PC 0x0c06f8c6 */
if(!s->budget--) { s->failed_pc=0x0c06f8c6u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c06f8c8;
P_0c06f8c8: /* original f159, guest PC 0x0c06f8c8 */
if(!s->budget--) { s->failed_pc=0x0c06f8c8u; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c06f8ca;
P_0c06f8ca: /* original f259, guest PC 0x0c06f8ca */
if(!s->budget--) { s->failed_pc=0x0c06f8cau; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c06f8cc;
P_0c06f8cc: /* original f38d, guest PC 0x0c06f8cc */
if(!s->budget--) { s->failed_pc=0x0c06f8ccu; return 0; }
fr[3]=0;
goto P_0c06f8ce;
P_0c06f8ce: /* original f0ed, guest PC 0x0c06f8ce */
if(!s->budget--) { s->failed_pc=0x0c06f8ceu; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+0,r[18],fr+3)) goto unsupported;
goto P_0c06f8d0;
P_0c06f8d0: /* original f37d, guest PC 0x0c06f8d0 */
if(!s->budget--) { s->failed_pc=0x0c06f8d0u; return 0; }
if(!vf3_fpu_fsrra(fr[3],r[18],&fr[3])) goto unsupported;
goto P_0c06f8d2;
P_0c06f8d2: /* original f342, guest PC 0x0c06f8d2 */
if(!s->budget--) { s->failed_pc=0x0c06f8d2u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'*');
goto P_0c06f8d4;
P_0c06f8d4: /* original 740c, guest PC 0x0c06f8d4 */
if(!s->budget--) { s->failed_pc=0x0c06f8d4u; return 0; }
r[4]+=0x0000000cu;
goto P_0c06f8d6;
P_0c06f8d6: /* original f232, guest PC 0x0c06f8d6 */
if(!s->budget--) { s->failed_pc=0x0c06f8d6u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c06f8d8;
P_0c06f8d8: /* original f132, guest PC 0x0c06f8d8 */
if(!s->budget--) { s->failed_pc=0x0c06f8d8u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[3],r[18],'*');
goto P_0c06f8da;
P_0c06f8da: /* original f032, guest PC 0x0c06f8da */
if(!s->budget--) { s->failed_pc=0x0c06f8dau; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'*');
goto P_0c06f8dc;
P_0c06f8dc: /* original f42b, guest PC 0x0c06f8dc */
if(!s->budget--) { s->failed_pc=0x0c06f8dcu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c06f8de;
P_0c06f8de: /* original f41b, guest PC 0x0c06f8de */
if(!s->budget--) { s->failed_pc=0x0c06f8deu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c06f8e0;
P_0c06f8e0: /* original f40b, guest PC 0x0c06f8e0 */
if(!s->budget--) { s->failed_pc=0x0c06f8e0u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c06f8e2;
P_0c06f8e2: /* original 0009, guest PC 0x0c06f8e2 */
if(!s->budget--) { s->failed_pc=0x0c06f8e2u; return 0; }
goto P_0c06f8e4;
P_0c06f8e4: /* original 64f3, guest PC 0x0c06f8e4 */
if(!s->budget--) { s->failed_pc=0x0c06f8e4u; return 0; }
r[4]=r[15];
goto P_0c06f8e6;
P_0c06f8e6: /* original 66f3, guest PC 0x0c06f8e6 */
if(!s->budget--) { s->failed_pc=0x0c06f8e6u; return 0; }
r[6]=r[15];
goto P_0c06f8e8;
P_0c06f8e8: /* original 7450, guest PC 0x0c06f8e8 */
if(!s->budget--) { s->failed_pc=0x0c06f8e8u; return 0; }
r[4]+=0x00000050u;
goto P_0c06f8ea;
P_0c06f8ea: /* original 65c3, guest PC 0x0c06f8ea */
if(!s->budget--) { s->failed_pc=0x0c06f8eau; return 0; }
r[5]=r[12];
goto P_0c06f8ec;
P_0c06f8ec: /* original 762c, guest PC 0x0c06f8ec */
if(!s->budget--) { s->failed_pc=0x0c06f8ecu; return 0; }
r[6]+=0x0000002cu;
goto P_0c06f8ee;
P_0c06f8ee: /* original f059, guest PC 0x0c06f8ee */
if(!s->budget--) { s->failed_pc=0x0c06f8eeu; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c06f8f0;
P_0c06f8f0: /* original f369, guest PC 0x0c06f8f0 */
if(!s->budget--) { s->failed_pc=0x0c06f8f0u; return 0; }
vf3_matrix_load(s,ram,3,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c06f8f2;
P_0c06f8f2: /* original f159, guest PC 0x0c06f8f2 */
if(!s->budget--) { s->failed_pc=0x0c06f8f2u; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c06f8f4;
P_0c06f8f4: /* original f469, guest PC 0x0c06f8f4 */
if(!s->budget--) { s->failed_pc=0x0c06f8f4u; return 0; }
vf3_matrix_load(s,ram,4,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c06f8f6;
P_0c06f8f6: /* original f259, guest PC 0x0c06f8f6 */
if(!s->budget--) { s->failed_pc=0x0c06f8f6u; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c06f8f8;
P_0c06f8f8: /* original f569, guest PC 0x0c06f8f8 */
if(!s->budget--) { s->failed_pc=0x0c06f8f8u; return 0; }
vf3_matrix_load(s,ram,5,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c06f8fa;
P_0c06f8fa: /* original 740c, guest PC 0x0c06f8fa */
if(!s->budget--) { s->failed_pc=0x0c06f8fau; return 0; }
r[4]+=0x0000000cu;
goto P_0c06f8fc;
P_0c06f8fc: /* original f030, guest PC 0x0c06f8fc */
if(!s->budget--) { s->failed_pc=0x0c06f8fcu; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'+');
goto P_0c06f8fe;
P_0c06f8fe: /* original f250, guest PC 0x0c06f8fe */
if(!s->budget--) { s->failed_pc=0x0c06f8feu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'+');
goto P_0c06f900;
P_0c06f900: /* original f140, guest PC 0x0c06f900 */
if(!s->budget--) { s->failed_pc=0x0c06f900u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'+');
goto P_0c06f902;
P_0c06f902: /* original f42b, guest PC 0x0c06f902 */
if(!s->budget--) { s->failed_pc=0x0c06f902u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c06f904;
P_0c06f904: /* original f41b, guest PC 0x0c06f904 */
if(!s->budget--) { s->failed_pc=0x0c06f904u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c06f906;
P_0c06f906: /* original f40b, guest PC 0x0c06f906 */
if(!s->budget--) { s->failed_pc=0x0c06f906u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c06f908;
P_0c06f908: /* original 66f3, guest PC 0x0c06f908 */
if(!s->budget--) { s->failed_pc=0x0c06f908u; return 0; }
r[6]=r[15];
goto P_0c06f90a;
P_0c06f90a: /* original 64d3, guest PC 0x0c06f90a */
if(!s->budget--) { s->failed_pc=0x0c06f90au; return 0; }
r[4]=r[13];
goto P_0c06f90c;
P_0c06f90c: /* original 65c3, guest PC 0x0c06f90c */
if(!s->budget--) { s->failed_pc=0x0c06f90cu; return 0; }
r[5]=r[12];
goto P_0c06f90e;
P_0c06f90e: /* original 762c, guest PC 0x0c06f90e */
if(!s->budget--) { s->failed_pc=0x0c06f90eu; return 0; }
r[6]+=0x0000002cu;
goto P_0c06f910;
P_0c06f910: /* original f059, guest PC 0x0c06f910 */
if(!s->budget--) { s->failed_pc=0x0c06f910u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c06f912;
P_0c06f912: /* original f369, guest PC 0x0c06f912 */
if(!s->budget--) { s->failed_pc=0x0c06f912u; return 0; }
vf3_matrix_load(s,ram,3,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c06f914;
P_0c06f914: /* original f159, guest PC 0x0c06f914 */
if(!s->budget--) { s->failed_pc=0x0c06f914u; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c06f916;
P_0c06f916: /* original f469, guest PC 0x0c06f916 */
if(!s->budget--) { s->failed_pc=0x0c06f916u; return 0; }
vf3_matrix_load(s,ram,4,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c06f918;
P_0c06f918: /* original f259, guest PC 0x0c06f918 */
if(!s->budget--) { s->failed_pc=0x0c06f918u; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c06f91a;
P_0c06f91a: /* original f569, guest PC 0x0c06f91a */
if(!s->budget--) { s->failed_pc=0x0c06f91au; return 0; }
vf3_matrix_load(s,ram,5,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c06f91c;
P_0c06f91c: /* original 740c, guest PC 0x0c06f91c */
if(!s->budget--) { s->failed_pc=0x0c06f91cu; return 0; }
r[4]+=0x0000000cu;
goto P_0c06f91e;
P_0c06f91e: /* original f030, guest PC 0x0c06f91e */
if(!s->budget--) { s->failed_pc=0x0c06f91eu; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'+');
goto P_0c06f920;
P_0c06f920: /* original f250, guest PC 0x0c06f920 */
if(!s->budget--) { s->failed_pc=0x0c06f920u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'+');
goto P_0c06f922;
P_0c06f922: /* original f140, guest PC 0x0c06f922 */
if(!s->budget--) { s->failed_pc=0x0c06f922u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'+');
goto P_0c06f924;
P_0c06f924: /* original f42b, guest PC 0x0c06f924 */
if(!s->budget--) { s->failed_pc=0x0c06f924u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c06f926;
P_0c06f926: /* original f41b, guest PC 0x0c06f926 */
if(!s->budget--) { s->failed_pc=0x0c06f926u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c06f928;
P_0c06f928: /* original f40b, guest PC 0x0c06f928 */
if(!s->budget--) { s->failed_pc=0x0c06f928u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c06f92a;
P_0c06f92a: /* original 0009, guest PC 0x0c06f92a */
if(!s->budget--) { s->failed_pc=0x0c06f92au; return 0; }
goto P_0c06f92c;
P_0c06f92c: /* original 7901, guest PC 0x0c06f92c */
if(!s->budget--) { s->failed_pc=0x0c06f92cu; return 0; }
r[9]+=0x00000001u;
goto P_0c06f92e;
P_0c06f92e: /* original 39a3, guest PC 0x0c06f92e */
if(!s->budget--) { s->failed_pc=0x0c06f92eu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[9]>=(int32_t)r[10])!=0);
goto P_0c06f930;
P_0c06f930: /* original 7d18, guest PC 0x0c06f930 */
if(!s->budget--) { s->failed_pc=0x0c06f930u; return 0; }
r[13]+=0x00000018u;
goto P_0c06f932;
P_0c06f932: /* original 8d03, guest PC 0x0c06f932 */
if(!s->budget--) { s->failed_pc=0x0c06f932u; return 0; }
cond=r[17]&1u;
r[12]+=0x00000018u;
if(cond) { goto P_0c06f93c; }
goto P_0c06f936;
P_0c06f934: /* original 7c18, guest PC 0x0c06f934 */
if(!s->budget--) { s->failed_pc=0x0c06f934u; return 0; }
r[12]+=0x00000018u;
goto P_0c06f936;
P_0c06f936: /* original d234, guest PC 0x0c06f936 */
if(!s->budget--) { s->failed_pc=0x0c06f936u; return 0; }
r[2]=read(ram,0x0c06fa08u,4);
goto P_0c06f938;
P_0c06f938: /* original 422b, guest PC 0x0c06f938 */
if(!s->budget--) { s->failed_pc=0x0c06f938u; return 0; }
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
P_0c06f93a: /* original 0009, guest PC 0x0c06f93a */
if(!s->budget--) { s->failed_pc=0x0c06f93au; return 0; }
goto P_0c06f93c;
P_0c06f93c: /* original d333, guest PC 0x0c06f93c */
if(!s->budget--) { s->failed_pc=0x0c06f93cu; return 0; }
r[3]=read(ram,0x0c06fa0cu,4);
goto P_0c06f93e;
P_0c06f93e: /* original 65e3, guest PC 0x0c06f93e */
if(!s->budget--) { s->failed_pc=0x0c06f93eu; return 0; }
r[5]=r[14];
goto P_0c06f940;
P_0c06f940: /* original 6783, guest PC 0x0c06f940 */
if(!s->budget--) { s->failed_pc=0x0c06f940u; return 0; }
r[7]=r[8];
goto P_0c06f942;
P_0c06f942: /* original 66d3, guest PC 0x0c06f942 */
if(!s->budget--) { s->failed_pc=0x0c06f942u; return 0; }
r[6]=r[13];
goto P_0c06f944;
P_0c06f944: /* original 430b, guest PC 0x0c06f944 */
if(!s->budget--) { s->failed_pc=0x0c06f944u; return 0; }
target=r[3];
r[16]=0x0c06f948u;
r[4]=r[11];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c06f948u) { target=s->pc; goto dispatch; }
goto P_0c06f948;
P_0c06f946: /* original 64b3, guest PC 0x0c06f946 */
if(!s->budget--) { s->failed_pc=0x0c06f946u; return 0; }
r[4]=r[11];
goto P_0c06f948;
P_0c06f948: /* original 7801, guest PC 0x0c06f948 */
if(!s->budget--) { s->failed_pc=0x0c06f948u; return 0; }
r[8]+=0x00000001u;
goto P_0c06f94a;
P_0c06f94a: /* original 52f1, guest PC 0x0c06f94a */
if(!s->budget--) { s->failed_pc=0x0c06f94au; return 0; }
r[2]=read(ram,r[15]+4,4);
goto P_0c06f94c;
P_0c06f94c: /* original 3823, guest PC 0x0c06f94c */
if(!s->budget--) { s->failed_pc=0x0c06f94cu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[8]>=(int32_t)r[2])!=0);
goto P_0c06f94e;
P_0c06f94e: /* original 8902, guest PC 0x0c06f94e */
if(!s->budget--) { s->failed_pc=0x0c06f94eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c06f956; }
goto P_0c06f950;
P_0c06f950: /* original d32f, guest PC 0x0c06f950 */
if(!s->budget--) { s->failed_pc=0x0c06f950u; return 0; }
r[3]=read(ram,0x0c06fa10u,4);
goto P_0c06f952;
P_0c06f952: /* original 432b, guest PC 0x0c06f952 */
if(!s->budget--) { s->failed_pc=0x0c06f952u; return 0; }
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
P_0c06f954: /* original 0009, guest PC 0x0c06f954 */
if(!s->budget--) { s->failed_pc=0x0c06f954u; return 0; }
goto P_0c06f956;
P_0c06f956: /* original d22f, guest PC 0x0c06f956 */
if(!s->budget--) { s->failed_pc=0x0c06f956u; return 0; }
r[2]=read(ram,0x0c06fa14u,4);
goto P_0c06f958;
P_0c06f958: /* original 420b, guest PC 0x0c06f958 */
if(!s->budget--) { s->failed_pc=0x0c06f958u; return 0; }
target=r[2];
r[16]=0x0c06f95cu;
r[4]=0x00000001u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c06f95cu) { target=s->pc; goto dispatch; }
goto P_0c06f95c;
P_0c06f95a: /* original e401, guest PC 0x0c06f95a */
if(!s->budget--) { s->failed_pc=0x0c06f95au; return 0; }
r[4]=0x00000001u;
goto P_0c06f95c;
P_0c06f95c: /* original d32e, guest PC 0x0c06f95c */
if(!s->budget--) { s->failed_pc=0x0c06f95cu; return 0; }
r[3]=read(ram,0x0c06fa18u,4);
goto P_0c06f95e;
P_0c06f95e: /* original 430b, guest PC 0x0c06f95e */
if(!s->budget--) { s->failed_pc=0x0c06f95eu; return 0; }
target=r[3];
r[16]=0x0c06f962u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c06f962u) { target=s->pc; goto dispatch; }
goto P_0c06f962;
P_0c06f960: /* original 64e3, guest PC 0x0c06f960 */
if(!s->budget--) { s->failed_pc=0x0c06f960u; return 0; }
r[4]=r[14];
goto P_0c06f962;
P_0c06f962: /* original d22e, guest PC 0x0c06f962 */
if(!s->budget--) { s->failed_pc=0x0c06f962u; return 0; }
r[2]=read(ram,0x0c06fa1cu,4);
goto P_0c06f964;
P_0c06f964: /* original 65e3, guest PC 0x0c06f964 */
if(!s->budget--) { s->failed_pc=0x0c06f964u; return 0; }
r[5]=r[14];
goto P_0c06f966;
P_0c06f966: /* original 420b, guest PC 0x0c06f966 */
if(!s->budget--) { s->failed_pc=0x0c06f966u; return 0; }
target=r[2];
r[16]=0x0c06f96au;
r[4]=r[11];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c06f96au) { target=s->pc; goto dispatch; }
goto P_0c06f96a;
P_0c06f968: /* original 64b3, guest PC 0x0c06f968 */
if(!s->budget--) { s->failed_pc=0x0c06f968u; return 0; }
r[4]=r[11];
goto P_0c06f96a;
P_0c06f96a: /* original d32d, guest PC 0x0c06f96a */
if(!s->budget--) { s->failed_pc=0x0c06f96au; return 0; }
r[3]=read(ram,0x0c06fa20u,4);
goto P_0c06f96c;
P_0c06f96c: /* original 64e3, guest PC 0x0c06f96c */
if(!s->budget--) { s->failed_pc=0x0c06f96cu; return 0; }
r[4]=r[14];
goto P_0c06f96e;
P_0c06f96e: /* original 65f2, guest PC 0x0c06f96e */
if(!s->budget--) { s->failed_pc=0x0c06f96eu; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c06f970;
P_0c06f970: /* original 430b, guest PC 0x0c06f970 */
if(!s->budget--) { s->failed_pc=0x0c06f970u; return 0; }
target=r[3];
r[16]=0x0c06f974u;
r[4]+=0x00000010u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c06f974u) { target=s->pc; goto dispatch; }
goto P_0c06f974;
P_0c06f972: /* original 7410, guest PC 0x0c06f972 */
if(!s->budget--) { s->failed_pc=0x0c06f972u; return 0; }
r[4]+=0x00000010u;
goto P_0c06f974;
P_0c06f974: /* original 7f74, guest PC 0x0c06f974 */
if(!s->budget--) { s->failed_pc=0x0c06f974u; return 0; }
r[15]+=0x00000074u;
goto P_0c06f976;
P_0c06f976: /* original 4f16, guest PC 0x0c06f976 */
if(!s->budget--) { s->failed_pc=0x0c06f976u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c06f978;
P_0c06f978: /* original 4f26, guest PC 0x0c06f978 */
if(!s->budget--) { s->failed_pc=0x0c06f978u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c06f97a;
P_0c06f97a: /* original fcf9, guest PC 0x0c06f97a */
if(!s->budget--) { s->failed_pc=0x0c06f97au; return 0; }
vf3_matrix_load(s,ram,12,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c06f97c;
P_0c06f97c: /* original fdf9, guest PC 0x0c06f97c */
if(!s->budget--) { s->failed_pc=0x0c06f97cu; return 0; }
vf3_matrix_load(s,ram,13,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c06f97e;
P_0c06f97e: /* original fef9, guest PC 0x0c06f97e */
if(!s->budget--) { s->failed_pc=0x0c06f97eu; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c06f980;
P_0c06f980: /* original fff9, guest PC 0x0c06f980 */
if(!s->budget--) { s->failed_pc=0x0c06f980u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c06f982;
P_0c06f982: /* original 68f6, guest PC 0x0c06f982 */
if(!s->budget--) { s->failed_pc=0x0c06f982u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c06f984;
P_0c06f984: /* original 69f6, guest PC 0x0c06f984 */
if(!s->budget--) { s->failed_pc=0x0c06f984u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c06f986;
P_0c06f986: /* original 6af6, guest PC 0x0c06f986 */
if(!s->budget--) { s->failed_pc=0x0c06f986u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c06f988;
P_0c06f988: /* original 6bf6, guest PC 0x0c06f988 */
if(!s->budget--) { s->failed_pc=0x0c06f988u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c06f98a;
P_0c06f98a: /* original 6cf6, guest PC 0x0c06f98a */
if(!s->budget--) { s->failed_pc=0x0c06f98au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c06f98c;
P_0c06f98c: /* original 6df6, guest PC 0x0c06f98c */
if(!s->budget--) { s->failed_pc=0x0c06f98cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c06f98e;
P_0c06f98e: /* original 000b, guest PC 0x0c06f98e */
if(!s->budget--) { s->failed_pc=0x0c06f98eu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c06f990: /* original 6ef6, guest PC 0x0c06f990 */
if(!s->budget--) { s->failed_pc=0x0c06f990u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c06f992u,s,ram);
P_0c071104: /* original f40b, guest PC 0x0c071104 */
if(!s->budget--) { s->failed_pc=0x0c071104u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c071106;
P_0c071106: /* original 0009, guest PC 0x0c071106 */
if(!s->budget--) { s->failed_pc=0x0c071106u; return 0; }
goto P_0c071108;
P_0c071108: /* original 52f1, guest PC 0x0c071108 */
if(!s->budget--) { s->failed_pc=0x0c071108u; return 0; }
r[2]=read(ram,r[15]+4,4);
goto P_0c07110a;
P_0c07110a: /* original 7d18, guest PC 0x0c07110a */
if(!s->budget--) { s->failed_pc=0x0c07110au; return 0; }
r[13]+=0x00000018u;
goto P_0c07110c;
P_0c07110c: /* original 78e8, guest PC 0x0c07110c */
if(!s->budget--) { s->failed_pc=0x0c07110cu; return 0; }
r[8]+=0xffffffe8u;
goto P_0c07110e;
P_0c07110e: /* original 7218, guest PC 0x0c07110e */
if(!s->budget--) { s->failed_pc=0x0c07110eu; return 0; }
r[2]+=0x00000018u;
goto P_0c071110;
P_0c071110: /* original 1f21, guest PC 0x0c071110 */
if(!s->budget--) { s->failed_pc=0x0c071110u; return 0; }
write(ram,r[15]+4,r[2],4);
goto P_0c071112;
P_0c071112: /* original 7ee8, guest PC 0x0c071112 */
if(!s->budget--) { s->failed_pc=0x0c071112u; return 0; }
r[14]+=0xffffffe8u;
goto P_0c071114;
P_0c071114: /* original 63f2, guest PC 0x0c071114 */
if(!s->budget--) { s->failed_pc=0x0c071114u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c071116;
P_0c071116: /* original 73ff, guest PC 0x0c071116 */
if(!s->budget--) { s->failed_pc=0x0c071116u; return 0; }
r[3]+=0xffffffffu;
goto P_0c071118;
P_0c071118: /* original 4315, guest PC 0x0c071118 */
if(!s->budget--) { s->failed_pc=0x0c071118u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>0)!=0);
goto P_0c07111a;
P_0c07111a: /* original 8f03, guest PC 0x0c07111a */
if(!s->budget--) { s->failed_pc=0x0c07111au; return 0; }
cond=r[17]&1u;
write(ram,r[15],r[3],4);
if(!cond) { goto P_0c071124; }
goto P_0c07111e;
P_0c07111c: /* original 2f32, guest PC 0x0c07111c */
if(!s->budget--) { s->failed_pc=0x0c07111cu; return 0; }
write(ram,r[15],r[3],4);
goto P_0c07111e;
P_0c07111e: /* original d11d, guest PC 0x0c07111e */
if(!s->budget--) { s->failed_pc=0x0c07111eu; return 0; }
r[1]=read(ram,0x0c071194u,4);
goto P_0c071120;
P_0c071120: /* original 412b, guest PC 0x0c071120 */
if(!s->budget--) { s->failed_pc=0x0c071120u; return 0; }
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
P_0c071122: /* original 0009, guest PC 0x0c071122 */
if(!s->budget--) { s->failed_pc=0x0c071122u; return 0; }
goto P_0c071124;
P_0c071124: /* original 7f5c, guest PC 0x0c071124 */
if(!s->budget--) { s->failed_pc=0x0c071124u; return 0; }
r[15]+=0x0000005cu;
goto P_0c071126;
P_0c071126: /* original 4f26, guest PC 0x0c071126 */
if(!s->budget--) { s->failed_pc=0x0c071126u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c071128;
P_0c071128: /* original fcf9, guest PC 0x0c071128 */
if(!s->budget--) { s->failed_pc=0x0c071128u; return 0; }
vf3_matrix_load(s,ram,12,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c07112a;
P_0c07112a: /* original fdf9, guest PC 0x0c07112a */
if(!s->budget--) { s->failed_pc=0x0c07112au; return 0; }
vf3_matrix_load(s,ram,13,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c07112c;
P_0c07112c: /* original fef9, guest PC 0x0c07112c */
if(!s->budget--) { s->failed_pc=0x0c07112cu; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c07112e;
P_0c07112e: /* original fff9, guest PC 0x0c07112e */
if(!s->budget--) { s->failed_pc=0x0c07112eu; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c071130;
P_0c071130: /* original 68f6, guest PC 0x0c071130 */
if(!s->budget--) { s->failed_pc=0x0c071130u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c071132;
P_0c071132: /* original 69f6, guest PC 0x0c071132 */
if(!s->budget--) { s->failed_pc=0x0c071132u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c071134;
P_0c071134: /* original 6af6, guest PC 0x0c071134 */
if(!s->budget--) { s->failed_pc=0x0c071134u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c071136;
P_0c071136: /* original 6bf6, guest PC 0x0c071136 */
if(!s->budget--) { s->failed_pc=0x0c071136u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c071138;
P_0c071138: /* original 6cf6, guest PC 0x0c071138 */
if(!s->budget--) { s->failed_pc=0x0c071138u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c07113a;
P_0c07113a: /* original 6df6, guest PC 0x0c07113a */
if(!s->budget--) { s->failed_pc=0x0c07113au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c07113c;
P_0c07113c: /* original 000b, guest PC 0x0c07113c */
if(!s->budget--) { s->failed_pc=0x0c07113cu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c07113e: /* original 6ef6, guest PC 0x0c07113e */
if(!s->budget--) { s->failed_pc=0x0c07113eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c071140u,s,ram);
P_0c071faa: /* original f40b, guest PC 0x0c071faa */
if(!s->budget--) { s->failed_pc=0x0c071faau; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c071fac;
P_0c071fac: /* original 2fe2, guest PC 0x0c071fac */
if(!s->budget--) { s->failed_pc=0x0c071facu; return 0; }
write(ram,r[15],r[14],4);
goto P_0c071fae;
P_0c071fae: /* original 6eb3, guest PC 0x0c071fae */
if(!s->budget--) { s->failed_pc=0x0c071faeu; return 0; }
r[14]=r[11];
goto P_0c071fb0;
P_0c071fb0: /* original 53f1, guest PC 0x0c071fb0 */
if(!s->budget--) { s->failed_pc=0x0c071fb0u; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c071fb2;
P_0c071fb2: /* original 7b18, guest PC 0x0c071fb2 */
if(!s->budget--) { s->failed_pc=0x0c071fb2u; return 0; }
r[11]+=0x00000018u;
goto P_0c071fb4;
P_0c071fb4: /* original 7818, guest PC 0x0c071fb4 */
if(!s->budget--) { s->failed_pc=0x0c071fb4u; return 0; }
r[8]+=0x00000018u;
goto P_0c071fb6;
P_0c071fb6: /* original 73ff, guest PC 0x0c071fb6 */
if(!s->budget--) { s->failed_pc=0x0c071fb6u; return 0; }
r[3]+=0xffffffffu;
goto P_0c071fb8;
P_0c071fb8: /* original 3397, guest PC 0x0c071fb8 */
if(!s->budget--) { s->failed_pc=0x0c071fb8u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>(int32_t)r[9])!=0);
goto P_0c071fba;
P_0c071fba: /* original 8f03, guest PC 0x0c071fba */
if(!s->budget--) { s->failed_pc=0x0c071fbau; return 0; }
cond=r[17]&1u;
write(ram,r[15]+4,r[3],4);
if(!cond) { goto P_0c071fc4; }
goto P_0c071fbe;
P_0c071fbc: /* original 1f31, guest PC 0x0c071fbc */
if(!s->budget--) { s->failed_pc=0x0c071fbcu; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c071fbe;
P_0c071fbe: /* original d204, guest PC 0x0c071fbe */
if(!s->budget--) { s->failed_pc=0x0c071fbeu; return 0; }
r[2]=read(ram,0x0c071fd0u,4);
goto P_0c071fc0;
P_0c071fc0: /* original 422b, guest PC 0x0c071fc0 */
if(!s->budget--) { s->failed_pc=0x0c071fc0u; return 0; }
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
P_0c071fc2: /* original 0009, guest PC 0x0c071fc2 */
if(!s->budget--) { s->failed_pc=0x0c071fc2u; return 0; }
goto P_0c071fc4;
P_0c071fc4: /* original 65f2, guest PC 0x0c071fc4 */
if(!s->budget--) { s->failed_pc=0x0c071fc4u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c071fc6;
P_0c071fc6: /* original 64d3, guest PC 0x0c071fc6 */
if(!s->budget--) { s->failed_pc=0x0c071fc6u; return 0; }
r[4]=r[13];
goto P_0c071fc8;
P_0c071fc8: /* original 66e3, guest PC 0x0c071fc8 */
if(!s->budget--) { s->failed_pc=0x0c071fc8u; return 0; }
r[6]=r[14];
goto P_0c071fca;
P_0c071fca: /* original a003, guest PC 0x0c071fca */
if(!s->budget--) { s->failed_pc=0x0c071fcau; return 0; }
goto P_0c071fd4;
P_0c071fcc: /* original 0009, guest PC 0x0c071fcc */
if(!s->budget--) { s->failed_pc=0x0c071fccu; return 0; }
return vf3_matrix_family(0x0c071fceu,s,ram);
P_0c071fd4: /* original f059, guest PC 0x0c071fd4 */
if(!s->budget--) { s->failed_pc=0x0c071fd4u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c071fd6;
P_0c071fd6: /* original f369, guest PC 0x0c071fd6 */
if(!s->budget--) { s->failed_pc=0x0c071fd6u; return 0; }
vf3_matrix_load(s,ram,3,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c071fd8;
P_0c071fd8: /* original f159, guest PC 0x0c071fd8 */
if(!s->budget--) { s->failed_pc=0x0c071fd8u; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c071fda;
P_0c071fda: /* original f469, guest PC 0x0c071fda */
if(!s->budget--) { s->failed_pc=0x0c071fdau; return 0; }
vf3_matrix_load(s,ram,4,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c071fdc;
P_0c071fdc: /* original f031, guest PC 0x0c071fdc */
if(!s->budget--) { s->failed_pc=0x0c071fdcu; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'-');
goto P_0c071fde;
P_0c071fde: /* original f258, guest PC 0x0c071fde */
if(!s->budget--) { s->failed_pc=0x0c071fdeu; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
goto P_0c071fe0;
P_0c071fe0: /* original f568, guest PC 0x0c071fe0 */
if(!s->budget--) { s->failed_pc=0x0c071fe0u; return 0; }
vf3_matrix_load(s,ram,5,r[6]);
goto P_0c071fe2;
P_0c071fe2: /* original f141, guest PC 0x0c071fe2 */
if(!s->budget--) { s->failed_pc=0x0c071fe2u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'-');
goto P_0c071fe4;
P_0c071fe4: /* original f251, guest PC 0x0c071fe4 */
if(!s->budget--) { s->failed_pc=0x0c071fe4u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'-');
goto P_0c071fe6;
P_0c071fe6: /* original 7408, guest PC 0x0c071fe6 */
if(!s->budget--) { s->failed_pc=0x0c071fe6u; return 0; }
r[4]+=0x00000008u;
goto P_0c071fe8;
P_0c071fe8: /* original f42a, guest PC 0x0c071fe8 */
if(!s->budget--) { s->failed_pc=0x0c071fe8u; return 0; }
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c071fea;
P_0c071fea: /* original f41b, guest PC 0x0c071fea */
if(!s->budget--) { s->failed_pc=0x0c071feau; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c071fec;
P_0c071fec: /* original f40b, guest PC 0x0c071fec */
if(!s->budget--) { s->failed_pc=0x0c071fecu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c071fee;
P_0c071fee: /* original 0009, guest PC 0x0c071fee */
if(!s->budget--) { s->failed_pc=0x0c071feeu; return 0; }
goto P_0c071ff0;
P_0c071ff0: /* original 64a3, guest PC 0x0c071ff0 */
if(!s->budget--) { s->failed_pc=0x0c071ff0u; return 0; }
r[4]=r[10];
goto P_0c071ff2;
P_0c071ff2: /* original 6583, guest PC 0x0c071ff2 */
if(!s->budget--) { s->failed_pc=0x0c071ff2u; return 0; }
r[5]=r[8];
goto P_0c071ff4;
P_0c071ff4: /* original 66e3, guest PC 0x0c071ff4 */
if(!s->budget--) { s->failed_pc=0x0c071ff4u; return 0; }
r[6]=r[14];
goto P_0c071ff6;
P_0c071ff6: /* original f059, guest PC 0x0c071ff6 */
if(!s->budget--) { s->failed_pc=0x0c071ff6u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c071ff8;
P_0c071ff8: /* original f369, guest PC 0x0c071ff8 */
if(!s->budget--) { s->failed_pc=0x0c071ff8u; return 0; }
vf3_matrix_load(s,ram,3,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c071ffa;
P_0c071ffa: /* original f159, guest PC 0x0c071ffa */
if(!s->budget--) { s->failed_pc=0x0c071ffau; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c071ffc;
P_0c071ffc: /* original f469, guest PC 0x0c071ffc */
if(!s->budget--) { s->failed_pc=0x0c071ffcu; return 0; }
vf3_matrix_load(s,ram,4,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c071ffe;
P_0c071ffe: /* original f031, guest PC 0x0c071ffe */
if(!s->budget--) { s->failed_pc=0x0c071ffeu; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'-');
goto P_0c072000;
P_0c072000: /* original f258, guest PC 0x0c072000 */
if(!s->budget--) { s->failed_pc=0x0c072000u; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
goto P_0c072002;
P_0c072002: /* original f568, guest PC 0x0c072002 */
if(!s->budget--) { s->failed_pc=0x0c072002u; return 0; }
vf3_matrix_load(s,ram,5,r[6]);
goto P_0c072004;
P_0c072004: /* original f141, guest PC 0x0c072004 */
if(!s->budget--) { s->failed_pc=0x0c072004u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'-');
goto P_0c072006;
P_0c072006: /* original f251, guest PC 0x0c072006 */
if(!s->budget--) { s->failed_pc=0x0c072006u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'-');
goto P_0c072008;
P_0c072008: /* original 7408, guest PC 0x0c072008 */
if(!s->budget--) { s->failed_pc=0x0c072008u; return 0; }
r[4]+=0x00000008u;
goto P_0c07200a;
P_0c07200a: /* original f42a, guest PC 0x0c07200a */
if(!s->budget--) { s->failed_pc=0x0c07200au; return 0; }
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c07200c;
P_0c07200c: /* original f41b, guest PC 0x0c07200c */
if(!s->budget--) { s->failed_pc=0x0c07200cu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c07200e;
P_0c07200e: /* original f40b, guest PC 0x0c07200e */
if(!s->budget--) { s->failed_pc=0x0c07200eu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c072010;
P_0c072010: /* original 66e3, guest PC 0x0c072010 */
if(!s->budget--) { s->failed_pc=0x0c072010u; return 0; }
r[6]=r[14];
goto P_0c072012;
P_0c072012: /* original 64d3, guest PC 0x0c072012 */
if(!s->budget--) { s->failed_pc=0x0c072012u; return 0; }
r[4]=r[13];
goto P_0c072014;
P_0c072014: /* original 65a3, guest PC 0x0c072014 */
if(!s->budget--) { s->failed_pc=0x0c072014u; return 0; }
r[5]=r[10];
goto P_0c072016;
P_0c072016: /* original 760c, guest PC 0x0c072016 */
if(!s->budget--) { s->failed_pc=0x0c072016u; return 0; }
r[6]+=0x0000000cu;
goto P_0c072018;
P_0c072018: /* original f049, guest PC 0x0c072018 */
if(!s->budget--) { s->failed_pc=0x0c072018u; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c07201a;
P_0c07201a: /* original f549, guest PC 0x0c07201a */
if(!s->budget--) { s->failed_pc=0x0c07201au; return 0; }
vf3_matrix_load(s,ram,5,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c07201c;
P_0c07201c: /* original f648, guest PC 0x0c07201c */
if(!s->budget--) { s->failed_pc=0x0c07201cu; return 0; }
vf3_matrix_load(s,ram,6,r[4]);
goto P_0c07201e;
P_0c07201e: /* original f859, guest PC 0x0c07201e */
if(!s->budget--) { s->failed_pc=0x0c07201eu; return 0; }
vf3_matrix_load(s,ram,8,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c072020;
P_0c072020: /* original f959, guest PC 0x0c072020 */
if(!s->budget--) { s->failed_pc=0x0c072020u; return 0; }
vf3_matrix_load(s,ram,9,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c072022;
P_0c072022: /* original fa58, guest PC 0x0c072022 */
if(!s->budget--) { s->failed_pc=0x0c072022u; return 0; }
vf3_matrix_load(s,ram,10,r[5]);
goto P_0c072024;
P_0c072024: /* original 760c, guest PC 0x0c072024 */
if(!s->budget--) { s->failed_pc=0x0c072024u; return 0; }
r[6]+=0x0000000cu;
goto P_0c072026;
P_0c072026: /* original f35c, guest PC 0x0c072026 */
if(!s->budget--) { s->failed_pc=0x0c072026u; return 0; }
vf3_matrix_move(s,3,5);
goto P_0c072028;
P_0c072028: /* original f382, guest PC 0x0c072028 */
if(!s->budget--) { s->failed_pc=0x0c072028u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[8],r[18],'*');
goto P_0c07202a;
P_0c07202a: /* original f20c, guest PC 0x0c07202a */
if(!s->budget--) { s->failed_pc=0x0c07202au; return 0; }
vf3_matrix_move(s,2,0);
goto P_0c07202c;
P_0c07202c: /* original f2a2, guest PC 0x0c07202c */
if(!s->budget--) { s->failed_pc=0x0c07202cu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[10],r[18],'*');
goto P_0c07202e;
P_0c07202e: /* original f16c, guest PC 0x0c07202e */
if(!s->budget--) { s->failed_pc=0x0c07202eu; return 0; }
vf3_matrix_move(s,1,6);
goto P_0c072030;
P_0c072030: /* original f192, guest PC 0x0c072030 */
if(!s->budget--) { s->failed_pc=0x0c072030u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[9],r[18],'*');
goto P_0c072032;
P_0c072032: /* original f34d, guest PC 0x0c072032 */
if(!s->budget--) { s->failed_pc=0x0c072032u; return 0; }
fr[3]^=0x80000000u;
goto P_0c072034;
P_0c072034: /* original f39e, guest PC 0x0c072034 */
if(!s->budget--) { s->failed_pc=0x0c072034u; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[9],fr[3],r[18]);
goto P_0c072036;
P_0c072036: /* original f24d, guest PC 0x0c072036 */
if(!s->budget--) { s->failed_pc=0x0c072036u; return 0; }
fr[2]^=0x80000000u;
goto P_0c072038;
P_0c072038: /* original f06c, guest PC 0x0c072038 */
if(!s->budget--) { s->failed_pc=0x0c072038u; return 0; }
vf3_matrix_move(s,0,6);
goto P_0c07203a;
P_0c07203a: /* original f28e, guest PC 0x0c07203a */
if(!s->budget--) { s->failed_pc=0x0c07203au; return 0; }
fr[2]=vf3_fpu_mac(fr[0],fr[8],fr[2],r[18]);
goto P_0c07203c;
P_0c07203c: /* original f14d, guest PC 0x0c07203c */
if(!s->budget--) { s->failed_pc=0x0c07203cu; return 0; }
fr[1]^=0x80000000u;
goto P_0c07203e;
P_0c07203e: /* original f63b, guest PC 0x0c07203e */
if(!s->budget--) { s->failed_pc=0x0c07203eu; return 0; }
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,3,r[6]);
goto P_0c072040;
P_0c072040: /* original f05c, guest PC 0x0c072040 */
if(!s->budget--) { s->failed_pc=0x0c072040u; return 0; }
vf3_matrix_move(s,0,5);
goto P_0c072042;
P_0c072042: /* original f1ae, guest PC 0x0c072042 */
if(!s->budget--) { s->failed_pc=0x0c072042u; return 0; }
fr[1]=vf3_fpu_mac(fr[0],fr[10],fr[1],r[18]);
goto P_0c072044;
P_0c072044: /* original f62b, guest PC 0x0c072044 */
if(!s->budget--) { s->failed_pc=0x0c072044u; return 0; }
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[6]);
goto P_0c072046;
P_0c072046: /* original f61b, guest PC 0x0c072046 */
if(!s->budget--) { s->failed_pc=0x0c072046u; return 0; }
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[6]);
goto P_0c072048;
P_0c072048: /* original 64e3, guest PC 0x0c072048 */
if(!s->budget--) { s->failed_pc=0x0c072048u; return 0; }
r[4]=r[14];
goto P_0c07204a;
P_0c07204a: /* original 740c, guest PC 0x0c07204a */
if(!s->budget--) { s->failed_pc=0x0c07204au; return 0; }
r[4]+=0x0000000cu;
goto P_0c07204c;
P_0c07204c: /* original f049, guest PC 0x0c07204c */
if(!s->budget--) { s->failed_pc=0x0c07204cu; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c07204e;
P_0c07204e: /* original f149, guest PC 0x0c07204e */
if(!s->budget--) { s->failed_pc=0x0c07204eu; return 0; }
vf3_matrix_load(s,ram,1,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c072050;
P_0c072050: /* original f249, guest PC 0x0c072050 */
if(!s->budget--) { s->failed_pc=0x0c072050u; return 0; }
vf3_matrix_load(s,ram,2,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c072052;
P_0c072052: /* original f38d, guest PC 0x0c072052 */
if(!s->budget--) { s->failed_pc=0x0c072052u; return 0; }
fr[3]=0;
goto P_0c072054;
P_0c072054: /* original f0ed, guest PC 0x0c072054 */
if(!s->budget--) { s->failed_pc=0x0c072054u; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+0,r[18],fr+3)) goto unsupported;
goto P_0c072056;
P_0c072056: /* original f37d, guest PC 0x0c072056 */
if(!s->budget--) { s->failed_pc=0x0c072056u; return 0; }
if(!vf3_fpu_fsrra(fr[3],r[18],&fr[3])) goto unsupported;
goto P_0c072058;
P_0c072058: /* original f232, guest PC 0x0c072058 */
if(!s->budget--) { s->failed_pc=0x0c072058u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c07205a;
P_0c07205a: /* original f132, guest PC 0x0c07205a */
if(!s->budget--) { s->failed_pc=0x0c07205au; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[3],r[18],'*');
goto P_0c07205c;
P_0c07205c: /* original f032, guest PC 0x0c07205c */
if(!s->budget--) { s->failed_pc=0x0c07205cu; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'*');
goto P_0c07205e;
P_0c07205e: /* original f42b, guest PC 0x0c07205e */
if(!s->budget--) { s->failed_pc=0x0c07205eu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c072060;
P_0c072060: /* original f41b, guest PC 0x0c072060 */
if(!s->budget--) { s->failed_pc=0x0c072060u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c072062;
P_0c072062: /* original f40b, guest PC 0x0c072062 */
if(!s->budget--) { s->failed_pc=0x0c072062u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c072064;
P_0c072064: /* original 7f60, guest PC 0x0c072064 */
if(!s->budget--) { s->failed_pc=0x0c072064u; return 0; }
r[15]+=0x00000060u;
goto P_0c072066;
P_0c072066: /* original 68f6, guest PC 0x0c072066 */
if(!s->budget--) { s->failed_pc=0x0c072066u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c072068;
P_0c072068: /* original 69f6, guest PC 0x0c072068 */
if(!s->budget--) { s->failed_pc=0x0c072068u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c07206a;
P_0c07206a: /* original 6af6, guest PC 0x0c07206a */
if(!s->budget--) { s->failed_pc=0x0c07206au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c07206c;
P_0c07206c: /* original 6bf6, guest PC 0x0c07206c */
if(!s->budget--) { s->failed_pc=0x0c07206cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c07206e;
P_0c07206e: /* original 6cf6, guest PC 0x0c07206e */
if(!s->budget--) { s->failed_pc=0x0c07206eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c072070;
P_0c072070: /* original 6df6, guest PC 0x0c072070 */
if(!s->budget--) { s->failed_pc=0x0c072070u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c072072;
P_0c072072: /* original 000b, guest PC 0x0c072072 */
if(!s->budget--) { s->failed_pc=0x0c072072u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c072074: /* original 6ef6, guest PC 0x0c072074 */
if(!s->budget--) { s->failed_pc=0x0c072074u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c072076u,s,ram);
P_0c07b398: /* original c748, guest PC 0x0c07b398 */
if(!s->budget--) { s->failed_pc=0x0c07b398u; return 0; }
r[0]=0x0c07b4bcu;
goto P_0c07b39a;
P_0c07b39a: /* original f24c, guest PC 0x0c07b39a */
if(!s->budget--) { s->failed_pc=0x0c07b39au; return 0; }
vf3_matrix_move(s,2,4);
goto P_0c07b39c;
P_0c07b39c: /* original f308, guest PC 0x0c07b39c */
if(!s->budget--) { s->failed_pc=0x0c07b39cu; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c07b39e;
P_0c07b39e: /* original e018, guest PC 0x0c07b39e */
if(!s->budget--) { s->failed_pc=0x0c07b39eu; return 0; }
r[0]=0x00000018u;
goto P_0c07b3a0;
P_0c07b3a0: /* original f460, guest PC 0x0c07b3a0 */
if(!s->budget--) { s->failed_pc=0x0c07b3a0u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[6],r[18],'+');
goto P_0c07b3a2;
P_0c07b3a2: /* original f230, guest PC 0x0c07b3a2 */
if(!s->budget--) { s->failed_pc=0x0c07b3a2u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'+');
goto P_0c07b3a4;
P_0c07b3a4: /* original f282, guest PC 0x0c07b3a4 */
if(!s->budget--) { s->failed_pc=0x0c07b3a4u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[8],r[18],'*');
goto P_0c07b3a6;
P_0c07b3a6: /* original f427, guest PC 0x0c07b3a6 */
if(!s->budget--) { s->failed_pc=0x0c07b3a6u; return 0; }
vf3_matrix_store(s,ram,2,r[4]+r[0]);
goto P_0c07b3a8;
P_0c07b3a8: /* original c745, guest PC 0x0c07b3a8 */
if(!s->budget--) { s->failed_pc=0x0c07b3a8u; return 0; }
r[0]=0x0c07b4c0u;
goto P_0c07b3aa;
P_0c07b3aa: /* original f208, guest PC 0x0c07b3aa */
if(!s->budget--) { s->failed_pc=0x0c07b3aau; return 0; }
vf3_matrix_load(s,ram,2,r[0]);
goto P_0c07b3ac;
P_0c07b3ac: /* original e01c, guest PC 0x0c07b3ac */
if(!s->budget--) { s->failed_pc=0x0c07b3acu; return 0; }
r[0]=0x0000001cu;
goto P_0c07b3ae;
P_0c07b3ae: /* original f15c, guest PC 0x0c07b3ae */
if(!s->budget--) { s->failed_pc=0x0c07b3aeu; return 0; }
vf3_matrix_move(s,1,5);
goto P_0c07b3b0;
P_0c07b3b0: /* original f570, guest PC 0x0c07b3b0 */
if(!s->budget--) { s->failed_pc=0x0c07b3b0u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[7],r[18],'+');
goto P_0c07b3b2;
P_0c07b3b2: /* original f120, guest PC 0x0c07b3b2 */
if(!s->budget--) { s->failed_pc=0x0c07b3b2u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[2],r[18],'+');
goto P_0c07b3b4;
P_0c07b3b4: /* original f192, guest PC 0x0c07b3b4 */
if(!s->budget--) { s->failed_pc=0x0c07b3b4u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[9],r[18],'*');
goto P_0c07b3b6;
P_0c07b3b6: /* original f417, guest PC 0x0c07b3b6 */
if(!s->budget--) { s->failed_pc=0x0c07b3b6u; return 0; }
vf3_matrix_store(s,ram,1,r[4]+r[0]);
goto P_0c07b3b8;
P_0c07b3b8: /* original c742, guest PC 0x0c07b3b8 */
if(!s->budget--) { s->failed_pc=0x0c07b3b8u; return 0; }
r[0]=0x0c07b4c4u;
goto P_0c07b3ba;
P_0c07b3ba: /* original f108, guest PC 0x0c07b3ba */
if(!s->budget--) { s->failed_pc=0x0c07b3bau; return 0; }
vf3_matrix_load(s,ram,1,r[0]);
goto P_0c07b3bc;
P_0c07b3bc: /* original e020, guest PC 0x0c07b3bc */
if(!s->budget--) { s->failed_pc=0x0c07b3bcu; return 0; }
r[0]=0x00000020u;
goto P_0c07b3be;
P_0c07b3be: /* original f410, guest PC 0x0c07b3be */
if(!s->budget--) { s->failed_pc=0x0c07b3beu; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[1],r[18],'+');
goto P_0c07b3c0;
P_0c07b3c0: /* original f482, guest PC 0x0c07b3c0 */
if(!s->budget--) { s->failed_pc=0x0c07b3c0u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[8],r[18],'*');
goto P_0c07b3c2;
P_0c07b3c2: /* original f447, guest PC 0x0c07b3c2 */
if(!s->budget--) { s->failed_pc=0x0c07b3c2u; return 0; }
vf3_matrix_store(s,ram,4,r[4]+r[0]);
goto P_0c07b3c4;
P_0c07b3c4: /* original c740, guest PC 0x0c07b3c4 */
if(!s->budget--) { s->failed_pc=0x0c07b3c4u; return 0; }
r[0]=0x0c07b4c8u;
goto P_0c07b3c6;
P_0c07b3c6: /* original f308, guest PC 0x0c07b3c6 */
if(!s->budget--) { s->failed_pc=0x0c07b3c6u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c07b3c8;
P_0c07b3c8: /* original e024, guest PC 0x0c07b3c8 */
if(!s->budget--) { s->failed_pc=0x0c07b3c8u; return 0; }
r[0]=0x00000024u;
goto P_0c07b3ca;
P_0c07b3ca: /* original f530, guest PC 0x0c07b3ca */
if(!s->budget--) { s->failed_pc=0x0c07b3cau; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[3],r[18],'+');
goto P_0c07b3cc;
P_0c07b3cc: /* original f592, guest PC 0x0c07b3cc */
if(!s->budget--) { s->failed_pc=0x0c07b3ccu; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[9],r[18],'*');
goto P_0c07b3ce;
P_0c07b3ce: /* original 000b, guest PC 0x0c07b3ce */
if(!s->budget--) { s->failed_pc=0x0c07b3ceu; return 0; }
target=r[16];
vf3_matrix_store(s,ram,5,r[4]+r[0]);
s->pc=target; return ram->oob==0;
P_0c07b3d0: /* original f457, guest PC 0x0c07b3d0 */
if(!s->budget--) { s->failed_pc=0x0c07b3d0u; return 0; }
vf3_matrix_store(s,ram,5,r[4]+r[0]);
return vf3_matrix_family(0x0c07b3d2u,s,ram);
P_0c07b6c4: /* original 4f22, guest PC 0x0c07b6c4 */
if(!s->budget--) { s->failed_pc=0x0c07b6c4u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c07b6c6;
P_0c07b6c6: /* original 7ffc, guest PC 0x0c07b6c6 */
if(!s->budget--) { s->failed_pc=0x0c07b6c6u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c07b6c8;
P_0c07b6c8: /* original 2f72, guest PC 0x0c07b6c8 */
if(!s->budget--) { s->failed_pc=0x0c07b6c8u; return 0; }
write(ram,r[15],r[7],4);
goto P_0c07b6ca;
P_0c07b6ca: /* original 53f2, guest PC 0x0c07b6ca */
if(!s->budget--) { s->failed_pc=0x0c07b6cau; return 0; }
r[3]=read(ram,r[15]+8,4);
goto P_0c07b6cc;
P_0c07b6cc: /* original 2f36, guest PC 0x0c07b6cc */
if(!s->budget--) { s->failed_pc=0x0c07b6ccu; return 0; }
r[15]-=4; write(ram,r[15],r[3],4);
goto P_0c07b6ce;
P_0c07b6ce: /* original 52f1, guest PC 0x0c07b6ce */
if(!s->budget--) { s->failed_pc=0x0c07b6ceu; return 0; }
r[2]=read(ram,r[15]+4,4);
goto P_0c07b6d0;
P_0c07b6d0: /* original 2f26, guest PC 0x0c07b6d0 */
if(!s->budget--) { s->failed_pc=0x0c07b6d0u; return 0; }
r[15]-=4; write(ram,r[15],r[2],4);
goto P_0c07b6d2;
P_0c07b6d2: /* original b004, guest PC 0x0c07b6d2 */
if(!s->budget--) { s->failed_pc=0x0c07b6d2u; return 0; }
target=0x0c07b6deu; r[16]=0x0c07b6d6u;
r[7]=0x00000000u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07b6d6u) { target=s->pc; goto dispatch; }
goto P_0c07b6d6;
P_0c07b6d4: /* original e700, guest PC 0x0c07b6d4 */
if(!s->budget--) { s->failed_pc=0x0c07b6d4u; return 0; }
r[7]=0x00000000u;
goto P_0c07b6d6;
P_0c07b6d6: /* original 7f0c, guest PC 0x0c07b6d6 */
if(!s->budget--) { s->failed_pc=0x0c07b6d6u; return 0; }
r[15]+=0x0000000cu;
goto P_0c07b6d8;
P_0c07b6d8: /* original 4f26, guest PC 0x0c07b6d8 */
if(!s->budget--) { s->failed_pc=0x0c07b6d8u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c07b6da;
P_0c07b6da: /* original 000b, guest PC 0x0c07b6da */
if(!s->budget--) { s->failed_pc=0x0c07b6dau; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c07b6dc: /* original 0009, guest PC 0x0c07b6dc */
if(!s->budget--) { s->failed_pc=0x0c07b6dcu; return 0; }
goto P_0c07b6de;
P_0c07b6de: /* original 4f22, guest PC 0x0c07b6de */
if(!s->budget--) { s->failed_pc=0x0c07b6deu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c07b6e0;
P_0c07b6e0: /* original 53f2, guest PC 0x0c07b6e0 */
if(!s->budget--) { s->failed_pc=0x0c07b6e0u; return 0; }
r[3]=read(ram,r[15]+8,4);
goto P_0c07b6e2;
P_0c07b6e2: /* original 2f36, guest PC 0x0c07b6e2 */
if(!s->budget--) { s->failed_pc=0x0c07b6e2u; return 0; }
r[15]-=4; write(ram,r[15],r[3],4);
goto P_0c07b6e4;
P_0c07b6e4: /* original d311, guest PC 0x0c07b6e4 */
if(!s->budget--) { s->failed_pc=0x0c07b6e4u; return 0; }
r[3]=read(ram,0x0c07b72cu,4);
goto P_0c07b6e6;
P_0c07b6e6: /* original 52f2, guest PC 0x0c07b6e6 */
if(!s->budget--) { s->failed_pc=0x0c07b6e6u; return 0; }
r[2]=read(ram,r[15]+8,4);
goto P_0c07b6e8;
P_0c07b6e8: /* original 430b, guest PC 0x0c07b6e8 */
if(!s->budget--) { s->failed_pc=0x0c07b6e8u; return 0; }
target=r[3];
r[16]=0x0c07b6ecu;
r[15]-=4; write(ram,r[15],r[2],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07b6ecu) { target=s->pc; goto dispatch; }
goto P_0c07b6ec;
P_0c07b6ea: /* original 2f26, guest PC 0x0c07b6ea */
if(!s->budget--) { s->failed_pc=0x0c07b6eau; return 0; }
r[15]-=4; write(ram,r[15],r[2],4);
goto P_0c07b6ec;
P_0c07b6ec: /* original 7f08, guest PC 0x0c07b6ec */
if(!s->budget--) { s->failed_pc=0x0c07b6ecu; return 0; }
r[15]+=0x00000008u;
goto P_0c07b6ee;
P_0c07b6ee: /* original 4f26, guest PC 0x0c07b6ee */
if(!s->budget--) { s->failed_pc=0x0c07b6eeu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c07b6f0;
P_0c07b6f0: /* original 000b, guest PC 0x0c07b6f0 */
if(!s->budget--) { s->failed_pc=0x0c07b6f0u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c07b6f2: /* original 0009, guest PC 0x0c07b6f2 */
if(!s->budget--) { s->failed_pc=0x0c07b6f2u; return 0; }
return vf3_matrix_family(0x0c07b6f4u,s,ram);
P_0c09518c: /* original 4f22, guest PC 0x0c09518c */
if(!s->budget--) { s->failed_pc=0x0c09518cu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c09518e;
P_0c09518e: /* original e060, guest PC 0x0c09518e */
if(!s->budget--) { s->failed_pc=0x0c09518eu; return 0; }
r[0]=0x00000060u;
goto P_0c095190;
P_0c095190: /* original 7ff8, guest PC 0x0c095190 */
if(!s->budget--) { s->failed_pc=0x0c095190u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c095192;
P_0c095192: /* original 1f51, guest PC 0x0c095192 */
if(!s->budget--) { s->failed_pc=0x0c095192u; return 0; }
write(ram,r[15]+4,r[5],4);
goto P_0c095194;
P_0c095194: /* original 004c, guest PC 0x0c095194 */
if(!s->budget--) { s->failed_pc=0x0c095194u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c095196;
P_0c095196: /* original d531, guest PC 0x0c095196 */
if(!s->budget--) { s->failed_pc=0x0c095196u; return 0; }
r[5]=read(ram,0x0c09525cu,4);
goto P_0c095198;
P_0c095198: /* original 600c, guest PC 0x0c095198 */
if(!s->budget--) { s->failed_pc=0x0c095198u; return 0; }
r[0]=r[0]&255u;
goto P_0c09519a;
P_0c09519a: /* original 8808, guest PC 0x0c09519a */
if(!s->budget--) { s->failed_pc=0x0c09519au; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000008u)!=0);
goto P_0c09519c;
P_0c09519c: /* original 8b08, guest PC 0x0c09519c */
if(!s->budget--) { s->failed_pc=0x0c09519cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0951b0; }
goto P_0c09519e;
P_0c09519e: /* original 9256, guest PC 0x0c09519e */
if(!s->budget--) { s->failed_pc=0x0c09519eu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09524eu,2);
goto P_0c0951a0;
P_0c0951a0: /* original e60f, guest PC 0x0c0951a0 */
if(!s->budget--) { s->failed_pc=0x0c0951a0u; return 0; }
r[6]=0x0000000fu;
goto P_0c0951a2;
P_0c0951a2: /* original 352c, guest PC 0x0c0951a2 */
if(!s->budget--) { s->failed_pc=0x0c0951a2u; return 0; }
r[5]+=r[2];
goto P_0c0951a4;
P_0c0951a4: /* original 2f52, guest PC 0x0c0951a4 */
if(!s->budget--) { s->failed_pc=0x0c0951a4u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0951a6;
P_0c0951a6: /* original 53f1, guest PC 0x0c0951a6 */
if(!s->budget--) { s->failed_pc=0x0c0951a6u; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c0951a8;
P_0c0951a8: /* original 2f36, guest PC 0x0c0951a8 */
if(!s->budget--) { s->failed_pc=0x0c0951a8u; return 0; }
r[15]-=4; write(ram,r[15],r[3],4);
goto P_0c0951aa;
P_0c0951aa: /* original 57f1, guest PC 0x0c0951aa */
if(!s->budget--) { s->failed_pc=0x0c0951aau; return 0; }
r[7]=read(ram,r[15]+4,4);
goto P_0c0951ac;
P_0c0951ac: /* original a00a, guest PC 0x0c0951ac */
if(!s->budget--) { s->failed_pc=0x0c0951acu; return 0; }
r[5]=0x00000000u;
goto P_0c0951c4;
P_0c0951ae: /* original e500, guest PC 0x0c0951ae */
if(!s->budget--) { s->failed_pc=0x0c0951aeu; return 0; }
r[5]=0x00000000u;
goto P_0c0951b0;
P_0c0951b0: /* original 8815, guest PC 0x0c0951b0 */
if(!s->budget--) { s->failed_pc=0x0c0951b0u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000015u)!=0);
goto P_0c0951b2;
P_0c0951b2: /* original 8b0a, guest PC 0x0c0951b2 */
if(!s->budget--) { s->failed_pc=0x0c0951b2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0951ca; }
goto P_0c0951b4;
P_0c0951b4: /* original 924c, guest PC 0x0c0951b4 */
if(!s->budget--) { s->failed_pc=0x0c0951b4u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c095250u,2);
goto P_0c0951b6;
P_0c0951b6: /* original e60f, guest PC 0x0c0951b6 */
if(!s->budget--) { s->failed_pc=0x0c0951b6u; return 0; }
r[6]=0x0000000fu;
goto P_0c0951b8;
P_0c0951b8: /* original 352c, guest PC 0x0c0951b8 */
if(!s->budget--) { s->failed_pc=0x0c0951b8u; return 0; }
r[5]+=r[2];
goto P_0c0951ba;
P_0c0951ba: /* original 2f52, guest PC 0x0c0951ba */
if(!s->budget--) { s->failed_pc=0x0c0951bau; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0951bc;
P_0c0951bc: /* original e501, guest PC 0x0c0951bc */
if(!s->budget--) { s->failed_pc=0x0c0951bcu; return 0; }
r[5]=0x00000001u;
goto P_0c0951be;
P_0c0951be: /* original 53f1, guest PC 0x0c0951be */
if(!s->budget--) { s->failed_pc=0x0c0951beu; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c0951c0;
P_0c0951c0: /* original 2f36, guest PC 0x0c0951c0 */
if(!s->budget--) { s->failed_pc=0x0c0951c0u; return 0; }
r[15]-=4; write(ram,r[15],r[3],4);
goto P_0c0951c2;
P_0c0951c2: /* original 57f1, guest PC 0x0c0951c2 */
if(!s->budget--) { s->failed_pc=0x0c0951c2u; return 0; }
r[7]=read(ram,r[15]+4,4);
goto P_0c0951c4;
P_0c0951c4: /* original b005, guest PC 0x0c0951c4 */
if(!s->budget--) { s->failed_pc=0x0c0951c4u; return 0; }
target=0x0c0951d2u; r[16]=0x0c0951c8u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0951c8u) { target=s->pc; goto dispatch; }
goto P_0c0951c8;
P_0c0951c6: /* original 0009, guest PC 0x0c0951c6 */
if(!s->budget--) { s->failed_pc=0x0c0951c6u; return 0; }
goto P_0c0951c8;
P_0c0951c8: /* original 7f04, guest PC 0x0c0951c8 */
if(!s->budget--) { s->failed_pc=0x0c0951c8u; return 0; }
r[15]+=0x00000004u;
goto P_0c0951ca;
P_0c0951ca: /* original 7f08, guest PC 0x0c0951ca */
if(!s->budget--) { s->failed_pc=0x0c0951cau; return 0; }
r[15]+=0x00000008u;
goto P_0c0951cc;
P_0c0951cc: /* original 4f26, guest PC 0x0c0951cc */
if(!s->budget--) { s->failed_pc=0x0c0951ccu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0951ce;
P_0c0951ce: /* original 000b, guest PC 0x0c0951ce */
if(!s->budget--) { s->failed_pc=0x0c0951ceu; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c0951d0: /* original 0009, guest PC 0x0c0951d0 */
if(!s->budget--) { s->failed_pc=0x0c0951d0u; return 0; }
goto P_0c0951d2;
P_0c0951d2: /* original 2fe6, guest PC 0x0c0951d2 */
if(!s->budget--) { s->failed_pc=0x0c0951d2u; return 0; }
r[15]-=4; write(ram,r[15],r[14],4);
goto P_0c0951d4;
P_0c0951d4: /* original c722, guest PC 0x0c0951d4 */
if(!s->budget--) { s->failed_pc=0x0c0951d4u; return 0; }
r[0]=0x0c095260u;
goto P_0c0951d6;
P_0c0951d6: /* original 2fd6, guest PC 0x0c0951d6 */
if(!s->budget--) { s->failed_pc=0x0c0951d6u; return 0; }
r[15]-=4; write(ram,r[15],r[13],4);
goto P_0c0951d8;
P_0c0951d8: /* original 6d63, guest PC 0x0c0951d8 */
if(!s->budget--) { s->failed_pc=0x0c0951d8u; return 0; }
r[13]=r[6];
goto P_0c0951da;
P_0c0951da: /* original 2fc6, guest PC 0x0c0951da */
if(!s->budget--) { s->failed_pc=0x0c0951dau; return 0; }
r[15]-=4; write(ram,r[15],r[12],4);
goto P_0c0951dc;
P_0c0951dc: /* original 2fb6, guest PC 0x0c0951dc */
if(!s->budget--) { s->failed_pc=0x0c0951dcu; return 0; }
r[15]-=4; write(ram,r[15],r[11],4);
goto P_0c0951de;
P_0c0951de: /* original 2fa6, guest PC 0x0c0951de */
if(!s->budget--) { s->failed_pc=0x0c0951deu; return 0; }
r[15]-=4; write(ram,r[15],r[10],4);
goto P_0c0951e0;
P_0c0951e0: /* original 2f96, guest PC 0x0c0951e0 */
if(!s->budget--) { s->failed_pc=0x0c0951e0u; return 0; }
r[15]-=4; write(ram,r[15],r[9],4);
goto P_0c0951e2;
P_0c0951e2: /* original 2f86, guest PC 0x0c0951e2 */
if(!s->budget--) { s->failed_pc=0x0c0951e2u; return 0; }
r[15]-=4; write(ram,r[15],r[8],4);
goto P_0c0951e4;
P_0c0951e4: /* original 4f22, guest PC 0x0c0951e4 */
if(!s->budget--) { s->failed_pc=0x0c0951e4u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0951e6;
P_0c0951e6: /* original 7fe4, guest PC 0x0c0951e6 */
if(!s->budget--) { s->failed_pc=0x0c0951e6u; return 0; }
r[15]+=0xffffffe4u;
goto P_0c0951e8;
P_0c0951e8: /* original 66f3, guest PC 0x0c0951e8 */
if(!s->budget--) { s->failed_pc=0x0c0951e8u; return 0; }
r[6]=r[15];
goto P_0c0951ea;
P_0c0951ea: /* original 7610, guest PC 0x0c0951ea */
if(!s->budget--) { s->failed_pc=0x0c0951eau; return 0; }
r[6]+=0x00000010u;
goto P_0c0951ec;
P_0c0951ec: /* original 2f72, guest PC 0x0c0951ec */
if(!s->budget--) { s->failed_pc=0x0c0951ecu; return 0; }
write(ram,r[15],r[7],4);
goto P_0c0951ee;
P_0c0951ee: /* original 9a30, guest PC 0x0c0951ee */
if(!s->budget--) { s->failed_pc=0x0c0951eeu; return 0; }
r[10]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c095252u,2);
goto P_0c0951f0;
P_0c0951f0: /* original f408, guest PC 0x0c0951f0 */
if(!s->budget--) { s->failed_pc=0x0c0951f0u; return 0; }
vf3_matrix_load(s,ram,4,r[0]);
goto P_0c0951f2;
P_0c0951f2: /* original e004, guest PC 0x0c0951f2 */
if(!s->budget--) { s->failed_pc=0x0c0951f2u; return 0; }
r[0]=0x00000004u;
goto P_0c0951f4;
P_0c0951f4: /* original 64a3, guest PC 0x0c0951f4 */
if(!s->budget--) { s->failed_pc=0x0c0951f4u; return 0; }
r[4]=r[10];
goto P_0c0951f6;
P_0c0951f6: /* original 74e9, guest PC 0x0c0951f6 */
if(!s->budget--) { s->failed_pc=0x0c0951f6u; return 0; }
r[4]+=0xffffffe9u;
goto P_0c0951f8;
P_0c0951f8: /* original 6943, guest PC 0x0c0951f8 */
if(!s->budget--) { s->failed_pc=0x0c0951f8u; return 0; }
r[9]=r[4];
goto P_0c0951fa;
P_0c0951fa: /* original 6c43, guest PC 0x0c0951fa */
if(!s->budget--) { s->failed_pc=0x0c0951fau; return 0; }
r[12]=r[4];
goto P_0c0951fc;
P_0c0951fc: /* original f64c, guest PC 0x0c0951fc */
if(!s->budget--) { s->failed_pc=0x0c0951fcu; return 0; }
vf3_matrix_move(s,6,4);
goto P_0c0951fe;
P_0c0951fe: /* original 6463, guest PC 0x0c0951fe */
if(!s->budget--) { s->failed_pc=0x0c0951feu; return 0; }
r[4]=r[6];
goto P_0c095200;
P_0c095200: /* original f59d, guest PC 0x0c095200 */
if(!s->budget--) { s->failed_pc=0x0c095200u; return 0; }
fr[5]=0x3f800000u;
goto P_0c095202;
P_0c095202: /* original f65a, guest PC 0x0c095202 */
if(!s->budget--) { s->failed_pc=0x0c095202u; return 0; }
vf3_matrix_store(s,ram,5,r[6]);
goto P_0c095204;
P_0c095204: /* original f667, guest PC 0x0c095204 */
if(!s->budget--) { s->failed_pc=0x0c095204u; return 0; }
vf3_matrix_store(s,ram,6,r[6]+r[0]);
goto P_0c095206;
P_0c095206: /* original e008, guest PC 0x0c095206 */
if(!s->budget--) { s->failed_pc=0x0c095206u; return 0; }
r[0]=0x00000008u;
goto P_0c095208;
P_0c095208: /* original f667, guest PC 0x0c095208 */
if(!s->budget--) { s->failed_pc=0x0c095208u; return 0; }
vf3_matrix_store(s,ram,6,r[6]+r[0]);
goto P_0c09520a;
P_0c09520a: /* original 6342, guest PC 0x0c09520a */
if(!s->budget--) { s->failed_pc=0x0c09520au; return 0; }
tmp=read(ram,r[4],4);
r[3]=tmp;
goto P_0c09520c;
P_0c09520c: /* original 1f31, guest PC 0x0c09520c */
if(!s->budget--) { s->failed_pc=0x0c09520cu; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c09520e;
P_0c09520e: /* original 5241, guest PC 0x0c09520e */
if(!s->budget--) { s->failed_pc=0x0c09520eu; return 0; }
r[2]=read(ram,r[4]+4,4);
goto P_0c095210;
P_0c095210: /* original 1f22, guest PC 0x0c095210 */
if(!s->budget--) { s->failed_pc=0x0c095210u; return 0; }
write(ram,r[15]+8,r[2],4);
goto P_0c095212;
P_0c095212: /* original 5342, guest PC 0x0c095212 */
if(!s->budget--) { s->failed_pc=0x0c095212u; return 0; }
r[3]=read(ram,r[4]+8,4);
goto P_0c095214;
P_0c095214: /* original 6853, guest PC 0x0c095214 */
if(!s->budget--) { s->failed_pc=0x0c095214u; return 0; }
r[8]=r[5];
goto P_0c095216;
P_0c095216: /* original 4d11, guest PC 0x0c095216 */
if(!s->budget--) { s->failed_pc=0x0c095216u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[13]>=0)!=0);
goto P_0c095218;
P_0c095218: /* original 4818, guest PC 0x0c095218 */
if(!s->budget--) { s->failed_pc=0x0c095218u; return 0; }
r[8]<<=8;
goto P_0c09521a;
P_0c09521a: /* original 1f33, guest PC 0x0c09521a */
if(!s->budget--) { s->failed_pc=0x0c09521au; return 0; }
write(ram,r[15]+12,r[3],4);
goto P_0c09521c;
P_0c09521c: /* original 8f2c, guest PC 0x0c09521c */
if(!s->budget--) { s->failed_pc=0x0c09521cu; return 0; }
cond=r[17]&1u;
r[11]=0x00000001u;
if(!cond) { goto P_0c095278; }
goto P_0c095220;
P_0c09521e: /* original eb01, guest PC 0x0c09521e */
if(!s->budget--) { s->failed_pc=0x0c09521eu; return 0; }
r[11]=0x00000001u;
goto P_0c095220;
P_0c095220: /* original 60f2, guest PC 0x0c095220 */
if(!s->budget--) { s->failed_pc=0x0c095220u; return 0; }
tmp=read(ram,r[15],4);
r[0]=tmp;
goto P_0c095222;
P_0c095222: /* original 6ed3, guest PC 0x0c095222 */
if(!s->budget--) { s->failed_pc=0x0c095222u; return 0; }
r[14]=r[13];
goto P_0c095224;
P_0c095224: /* original 4e08, guest PC 0x0c095224 */
if(!s->budget--) { s->failed_pc=0x0c095224u; return 0; }
r[14]<<=2;
goto P_0c095226;
P_0c095226: /* original 0eee, guest PC 0x0c095226 */
if(!s->budget--) { s->failed_pc=0x0c095226u; return 0; }
r[14]=read(ram,r[14]+r[0],4);
goto P_0c095228;
P_0c095228: /* original 2ee8, guest PC 0x0c095228 */
if(!s->budget--) { s->failed_pc=0x0c095228u; return 0; }
r[17]=(r[17]&~1u)|(((r[14]&r[14])==0)!=0);
goto P_0c09522a;
P_0c09522a: /* original 8922, guest PC 0x0c09522a */
if(!s->budget--) { s->failed_pc=0x0c09522au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c095272; }
goto P_0c09522c;
P_0c09522c: /* original 60e3, guest PC 0x0c09522c */
if(!s->budget--) { s->failed_pc=0x0c09522cu; return 0; }
r[0]=r[14];
goto P_0c09522e;
P_0c09522e: /* original 88ff, guest PC 0x0c09522e */
if(!s->budget--) { s->failed_pc=0x0c09522eu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c095230;
P_0c095230: /* original 891f, guest PC 0x0c095230 */
if(!s->budget--) { s->failed_pc=0x0c095230u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c095272; }
goto P_0c095232;
P_0c095232: /* original 53e1, guest PC 0x0c095232 */
if(!s->budget--) { s->failed_pc=0x0c095232u; return 0; }
r[3]=read(ram,r[14]+4,4);
goto P_0c095234;
P_0c095234: /* original 23b8, guest PC 0x0c095234 */
if(!s->budget--) { s->failed_pc=0x0c095234u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[11])==0)!=0);
goto P_0c095236;
P_0c095236: /* original 8915, guest PC 0x0c095236 */
if(!s->budget--) { s->failed_pc=0x0c095236u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c095264; }
goto P_0c095238;
P_0c095238: /* original 6183, guest PC 0x0c095238 */
if(!s->budget--) { s->failed_pc=0x0c095238u; return 0; }
r[1]=r[8];
goto P_0c09523a;
P_0c09523a: /* original 21db, guest PC 0x0c09523a */
if(!s->budget--) { s->failed_pc=0x0c09523au; return 0; }
r[1]|=r[13];
goto P_0c09523c;
P_0c09523c: /* original 2f16, guest PC 0x0c09523c */
if(!s->budget--) { s->failed_pc=0x0c09523cu; return 0; }
r[15]-=4; write(ram,r[15],r[1],4);
goto P_0c09523e;
P_0c09523e: /* original 55f2, guest PC 0x0c09523e */
if(!s->budget--) { s->failed_pc=0x0c09523eu; return 0; }
r[5]=read(ram,r[15]+8,4);
goto P_0c095240;
P_0c095240: /* original 56f3, guest PC 0x0c095240 */
if(!s->budget--) { s->failed_pc=0x0c095240u; return 0; }
r[6]=read(ram,r[15]+12,4);
goto P_0c095242;
P_0c095242: /* original 57f4, guest PC 0x0c095242 */
if(!s->budget--) { s->failed_pc=0x0c095242u; return 0; }
r[7]=read(ram,r[15]+16,4);
goto P_0c095244;
P_0c095244: /* original b02e, guest PC 0x0c095244 */
if(!s->budget--) { s->failed_pc=0x0c095244u; return 0; }
target=0x0c0952a4u; r[16]=0x0c095248u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c095248u) { target=s->pc; goto dispatch; }
goto P_0c095248;
P_0c095246: /* original 64e3, guest PC 0x0c095246 */
if(!s->budget--) { s->failed_pc=0x0c095246u; return 0; }
r[4]=r[14];
goto P_0c095248;
P_0c095248: /* original a013, guest PC 0x0c095248 */
if(!s->budget--) { s->failed_pc=0x0c095248u; return 0; }
r[15]+=0x00000004u;
goto P_0c095272;
P_0c09524a: /* original 7f04, guest PC 0x0c09524a */
if(!s->budget--) { s->failed_pc=0x0c09524au; return 0; }
r[15]+=0x00000004u;
return vf3_matrix_family(0x0c09524cu,s,ram);
P_0c095264: /* original 2338, guest PC 0x0c095264 */
if(!s->budget--) { s->failed_pc=0x0c095264u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c095266;
P_0c095266: /* original 8904, guest PC 0x0c095266 */
if(!s->budget--) { s->failed_pc=0x0c095266u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c095272; }
goto P_0c095268;
P_0c095268: /* original 65a3, guest PC 0x0c095268 */
if(!s->budget--) { s->failed_pc=0x0c095268u; return 0; }
r[5]=r[10];
goto P_0c09526a;
P_0c09526a: /* original 6693, guest PC 0x0c09526a */
if(!s->budget--) { s->failed_pc=0x0c09526au; return 0; }
r[6]=r[9];
goto P_0c09526c;
P_0c09526c: /* original 67c3, guest PC 0x0c09526c */
if(!s->budget--) { s->failed_pc=0x0c09526cu; return 0; }
r[7]=r[12];
goto P_0c09526e;
P_0c09526e: /* original b00d, guest PC 0x0c09526e */
if(!s->budget--) { s->failed_pc=0x0c09526eu; return 0; }
target=0x0c09528cu; r[16]=0x0c095272u;
r[4]=read(ram,r[14]+4,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c095272u) { target=s->pc; goto dispatch; }
goto P_0c095272;
P_0c095270: /* original 54e1, guest PC 0x0c095270 */
if(!s->budget--) { s->failed_pc=0x0c095270u; return 0; }
r[4]=read(ram,r[14]+4,4);
goto P_0c095272;
P_0c095272: /* original 7dff, guest PC 0x0c095272 */
if(!s->budget--) { s->failed_pc=0x0c095272u; return 0; }
r[13]+=0xffffffffu;
goto P_0c095274;
P_0c095274: /* original 4d11, guest PC 0x0c095274 */
if(!s->budget--) { s->failed_pc=0x0c095274u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[13]>=0)!=0);
goto P_0c095276;
P_0c095276: /* original 89d3, guest PC 0x0c095276 */
if(!s->budget--) { s->failed_pc=0x0c095276u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c095220; }
goto P_0c095278;
P_0c095278: /* original 7f1c, guest PC 0x0c095278 */
if(!s->budget--) { s->failed_pc=0x0c095278u; return 0; }
r[15]+=0x0000001cu;
goto P_0c09527a;
P_0c09527a: /* original 4f26, guest PC 0x0c09527a */
if(!s->budget--) { s->failed_pc=0x0c09527au; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c09527c;
P_0c09527c: /* original 68f6, guest PC 0x0c09527c */
if(!s->budget--) { s->failed_pc=0x0c09527cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c09527e;
P_0c09527e: /* original 69f6, guest PC 0x0c09527e */
if(!s->budget--) { s->failed_pc=0x0c09527eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c095280;
P_0c095280: /* original 6af6, guest PC 0x0c095280 */
if(!s->budget--) { s->failed_pc=0x0c095280u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c095282;
P_0c095282: /* original 6bf6, guest PC 0x0c095282 */
if(!s->budget--) { s->failed_pc=0x0c095282u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c095284;
P_0c095284: /* original 6cf6, guest PC 0x0c095284 */
if(!s->budget--) { s->failed_pc=0x0c095284u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c095286;
P_0c095286: /* original 6df6, guest PC 0x0c095286 */
if(!s->budget--) { s->failed_pc=0x0c095286u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c095288;
P_0c095288: /* original 000b, guest PC 0x0c095288 */
if(!s->budget--) { s->failed_pc=0x0c095288u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c09528a: /* original 6ef6, guest PC 0x0c09528a */
if(!s->budget--) { s->failed_pc=0x0c09528au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c09528c;
P_0c09528c: /* original 5443, guest PC 0x0c09528c */
if(!s->budget--) { s->failed_pc=0x0c09528cu; return 0; }
r[4]=read(ram,r[4]+12,4);
goto P_0c09528e;
P_0c09528e: /* original 2448, guest PC 0x0c09528e */
if(!s->budget--) { s->failed_pc=0x0c09528eu; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c095290;
P_0c095290: /* original 8906, guest PC 0x0c095290 */
if(!s->budget--) { s->failed_pc=0x0c095290u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0952a0; }
goto P_0c095292;
P_0c095292: /* original 4618, guest PC 0x0c095292 */
if(!s->budget--) { s->failed_pc=0x0c095292u; return 0; }
r[6]<<=8;
goto P_0c095294;
P_0c095294: /* original 6063, guest PC 0x0c095294 */
if(!s->budget--) { s->failed_pc=0x0c095294u; return 0; }
r[0]=r[6];
goto P_0c095296;
P_0c095296: /* original 207b, guest PC 0x0c095296 */
if(!s->budget--) { s->failed_pc=0x0c095296u; return 0; }
r[0]|=r[7];
goto P_0c095298;
P_0c095298: /* original 8142, guest PC 0x0c095298 */
if(!s->budget--) { s->failed_pc=0x0c095298u; return 0; }
write(ram,r[4]+4,r[0],2);
goto P_0c09529a;
P_0c09529a: /* original 9046, guest PC 0x0c09529a */
if(!s->budget--) { s->failed_pc=0x0c09529au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09532au,2);
goto P_0c09529c;
P_0c09529c: /* original 205b, guest PC 0x0c09529c */
if(!s->budget--) { s->failed_pc=0x0c09529cu; return 0; }
r[0]|=r[5];
goto P_0c09529e;
P_0c09529e: /* original 8143, guest PC 0x0c09529e */
if(!s->budget--) { s->failed_pc=0x0c09529eu; return 0; }
write(ram,r[4]+6,r[0],2);
goto P_0c0952a0;
P_0c0952a0: /* original 000b, guest PC 0x0c0952a0 */
if(!s->budget--) { s->failed_pc=0x0c0952a0u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c0952a2: /* original 0009, guest PC 0x0c0952a2 */
if(!s->budget--) { s->failed_pc=0x0c0952a2u; return 0; }
goto P_0c0952a4;
P_0c0952a4: /* original 2fc6, guest PC 0x0c0952a4 */
if(!s->budget--) { s->failed_pc=0x0c0952a4u; return 0; }
r[15]-=4; write(ram,r[15],r[12],4);
goto P_0c0952a6;
P_0c0952a6: /* original 6143, guest PC 0x0c0952a6 */
if(!s->budget--) { s->failed_pc=0x0c0952a6u; return 0; }
r[1]=r[4];
goto P_0c0952a8;
P_0c0952a8: /* original 2fb6, guest PC 0x0c0952a8 */
if(!s->budget--) { s->failed_pc=0x0c0952a8u; return 0; }
r[15]-=4; write(ram,r[15],r[11],4);
goto P_0c0952aa;
P_0c0952aa: /* original e3f8, guest PC 0x0c0952aa */
if(!s->budget--) { s->failed_pc=0x0c0952aau; return 0; }
r[3]=0xfffffff8u;
goto P_0c0952ac;
P_0c0952ac: /* original 2fa6, guest PC 0x0c0952ac */
if(!s->budget--) { s->failed_pc=0x0c0952acu; return 0; }
r[15]-=4; write(ram,r[15],r[10],4);
goto P_0c0952ae;
P_0c0952ae: /* original 7118, guest PC 0x0c0952ae */
if(!s->budget--) { s->failed_pc=0x0c0952aeu; return 0; }
r[1]+=0x00000018u;
goto P_0c0952b0;
P_0c0952b0: /* original 5bf3, guest PC 0x0c0952b0 */
if(!s->budget--) { s->failed_pc=0x0c0952b0u; return 0; }
r[11]=read(ram,r[15]+12,4);
goto P_0c0952b2;
P_0c0952b2: /* original ea20, guest PC 0x0c0952b2 */
if(!s->budget--) { s->failed_pc=0x0c0952b2u; return 0; }
r[10]=0x00000020u;
goto P_0c0952b4;
P_0c0952b4: /* original eccf, guest PC 0x0c0952b4 */
if(!s->budget--) { s->failed_pc=0x0c0952b4u; return 0; }
r[12]=0xffffffcfu;
goto P_0c0952b6;
P_0c0952b6: /* original 4b3c, guest PC 0x0c0952b6 */
if(!s->budget--) { s->failed_pc=0x0c0952b6u; return 0; }
r[11]=(r[3]&0x80000000u)?((r[3]&31u)?(uint32_t)((int32_t)r[11]>>((-r[3])&31u)):((int32_t)r[11]<0?0xffffffffu:0)):r[11]<<(r[3]&31u);
goto P_0c0952b8;
P_0c0952b8: /* original 6312, guest PC 0x0c0952b8 */
if(!s->budget--) { s->failed_pc=0x0c0952b8u; return 0; }
tmp=read(ram,r[1],4);
r[3]=tmp;
goto P_0c0952ba;
P_0c0952ba: /* original 2338, guest PC 0x0c0952ba */
if(!s->budget--) { s->failed_pc=0x0c0952bau; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0952bc;
P_0c0952bc: /* original 8931, guest PC 0x0c0952bc */
if(!s->budget--) { s->failed_pc=0x0c0952bcu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c095322; }
goto P_0c0952be;
P_0c0952be: /* original 6212, guest PC 0x0c0952be */
if(!s->budget--) { s->failed_pc=0x0c0952beu; return 0; }
tmp=read(ram,r[1],4);
r[2]=tmp;
goto P_0c0952c0;
P_0c0952c0: /* original 6413, guest PC 0x0c0952c0 */
if(!s->budget--) { s->failed_pc=0x0c0952c0u; return 0; }
r[4]=r[1];
goto P_0c0952c2;
P_0c0952c2: /* original 7428, guest PC 0x0c0952c2 */
if(!s->budget--) { s->failed_pc=0x0c0952c2u; return 0; }
r[4]+=0x00000028u;
goto P_0c0952c4;
P_0c0952c4: /* original 22c9, guest PC 0x0c0952c4 */
if(!s->budget--) { s->failed_pc=0x0c0952c4u; return 0; }
r[2]&=r[12];
goto P_0c0952c6;
P_0c0952c6: /* original 6323, guest PC 0x0c0952c6 */
if(!s->budget--) { s->failed_pc=0x0c0952c6u; return 0; }
r[3]=r[2];
goto P_0c0952c8;
P_0c0952c8: /* original e0fe, guest PC 0x0c0952c8 */
if(!s->budget--) { s->failed_pc=0x0c0952c8u; return 0; }
r[0]=0xfffffffeu;
goto P_0c0952ca;
P_0c0952ca: /* original 23ab, guest PC 0x0c0952ca */
if(!s->budget--) { s->failed_pc=0x0c0952cau; return 0; }
r[3]|=r[10];
goto P_0c0952cc;
P_0c0952cc: /* original 2bb8, guest PC 0x0c0952cc */
if(!s->budget--) { s->failed_pc=0x0c0952ccu; return 0; }
r[17]=(r[17]&~1u)|(((r[11]&r[11])==0)!=0);
goto P_0c0952ce;
P_0c0952ce: /* original 2132, guest PC 0x0c0952ce */
if(!s->budget--) { s->failed_pc=0x0c0952ceu; return 0; }
write(ram,r[1],r[3],4);
goto P_0c0952d0;
P_0c0952d0: /* original 6242, guest PC 0x0c0952d0 */
if(!s->budget--) { s->failed_pc=0x0c0952d0u; return 0; }
tmp=read(ram,r[4],4);
r[2]=tmp;
goto P_0c0952d2;
P_0c0952d2: /* original 2209, guest PC 0x0c0952d2 */
if(!s->budget--) { s->failed_pc=0x0c0952d2u; return 0; }
r[2]&=r[0];
goto P_0c0952d4;
P_0c0952d4: /* original 2422, guest PC 0x0c0952d4 */
if(!s->budget--) { s->failed_pc=0x0c0952d4u; return 0; }
write(ram,r[4],r[2],4);
goto P_0c0952d6;
P_0c0952d6: /* original 8f0e, guest PC 0x0c0952d6 */
if(!s->budget--) { s->failed_pc=0x0c0952d6u; return 0; }
cond=r[17]&1u;
r[4]=read(ram,r[1]+32,4);
if(!cond) { goto P_0c0952f6; }
goto P_0c0952da;
P_0c0952d8: /* original 5418, guest PC 0x0c0952d8 */
if(!s->budget--) { s->failed_pc=0x0c0952d8u; return 0; }
r[4]=read(ram,r[1]+32,4);
goto P_0c0952da;
P_0c0952da: /* original 6043, guest PC 0x0c0952da */
if(!s->budget--) { s->failed_pc=0x0c0952dau; return 0; }
r[0]=r[4];
goto P_0c0952dc;
P_0c0952dc: /* original 8805, guest PC 0x0c0952dc */
if(!s->budget--) { s->failed_pc=0x0c0952dcu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000005u)!=0);
goto P_0c0952de;
P_0c0952de: /* original 8916, guest PC 0x0c0952de */
if(!s->budget--) { s->failed_pc=0x0c0952deu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09530e; }
goto P_0c0952e0;
P_0c0952e0: /* original 6043, guest PC 0x0c0952e0 */
if(!s->budget--) { s->failed_pc=0x0c0952e0u; return 0; }
r[0]=r[4];
goto P_0c0952e2;
P_0c0952e2: /* original 8808, guest PC 0x0c0952e2 */
if(!s->budget--) { s->failed_pc=0x0c0952e2u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000008u)!=0);
goto P_0c0952e4;
P_0c0952e4: /* original 8913, guest PC 0x0c0952e4 */
if(!s->budget--) { s->failed_pc=0x0c0952e4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09530e; }
goto P_0c0952e6;
P_0c0952e6: /* original 6043, guest PC 0x0c0952e6 */
if(!s->budget--) { s->failed_pc=0x0c0952e6u; return 0; }
r[0]=r[4];
goto P_0c0952e8;
P_0c0952e8: /* original 8809, guest PC 0x0c0952e8 */
if(!s->budget--) { s->failed_pc=0x0c0952e8u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000009u)!=0);
goto P_0c0952ea;
P_0c0952ea: /* original 8910, guest PC 0x0c0952ea */
if(!s->budget--) { s->failed_pc=0x0c0952eau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09530e; }
goto P_0c0952ec;
P_0c0952ec: /* original 6043, guest PC 0x0c0952ec */
if(!s->budget--) { s->failed_pc=0x0c0952ecu; return 0; }
r[0]=r[4];
goto P_0c0952ee;
P_0c0952ee: /* original 880c, guest PC 0x0c0952ee */
if(!s->budget--) { s->failed_pc=0x0c0952eeu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000cu)!=0);
goto P_0c0952f0;
P_0c0952f0: /* original 8b10, guest PC 0x0c0952f0 */
if(!s->budget--) { s->failed_pc=0x0c0952f0u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c095314; }
goto P_0c0952f2;
P_0c0952f2: /* original a00c, guest PC 0x0c0952f2 */
if(!s->budget--) { s->failed_pc=0x0c0952f2u; return 0; }
goto P_0c09530e;
P_0c0952f4: /* original 0009, guest PC 0x0c0952f4 */
if(!s->budget--) { s->failed_pc=0x0c0952f4u; return 0; }
goto P_0c0952f6;
P_0c0952f6: /* original 6043, guest PC 0x0c0952f6 */
if(!s->budget--) { s->failed_pc=0x0c0952f6u; return 0; }
r[0]=r[4];
goto P_0c0952f8;
P_0c0952f8: /* original 8803, guest PC 0x0c0952f8 */
if(!s->budget--) { s->failed_pc=0x0c0952f8u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000003u)!=0);
goto P_0c0952fa;
P_0c0952fa: /* original 8908, guest PC 0x0c0952fa */
if(!s->budget--) { s->failed_pc=0x0c0952fau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09530e; }
goto P_0c0952fc;
P_0c0952fc: /* original 6043, guest PC 0x0c0952fc */
if(!s->budget--) { s->failed_pc=0x0c0952fcu; return 0; }
r[0]=r[4];
goto P_0c0952fe;
P_0c0952fe: /* original 8805, guest PC 0x0c0952fe */
if(!s->budget--) { s->failed_pc=0x0c0952feu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000005u)!=0);
goto P_0c095300;
P_0c095300: /* original 8905, guest PC 0x0c095300 */
if(!s->budget--) { s->failed_pc=0x0c095300u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09530e; }
goto P_0c095302;
P_0c095302: /* original 6043, guest PC 0x0c095302 */
if(!s->budget--) { s->failed_pc=0x0c095302u; return 0; }
r[0]=r[4];
goto P_0c095304;
P_0c095304: /* original 8806, guest PC 0x0c095304 */
if(!s->budget--) { s->failed_pc=0x0c095304u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000006u)!=0);
goto P_0c095306;
P_0c095306: /* original 8902, guest PC 0x0c095306 */
if(!s->budget--) { s->failed_pc=0x0c095306u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09530e; }
goto P_0c095308;
P_0c095308: /* original 6043, guest PC 0x0c095308 */
if(!s->budget--) { s->failed_pc=0x0c095308u; return 0; }
r[0]=r[4];
goto P_0c09530a;
P_0c09530a: /* original 8808, guest PC 0x0c09530a */
if(!s->budget--) { s->failed_pc=0x0c09530au; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000008u)!=0);
goto P_0c09530c;
P_0c09530c: /* original 8b02, guest PC 0x0c09530c */
if(!s->budget--) { s->failed_pc=0x0c09530cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c095314; }
goto P_0c09530e;
P_0c09530e: /* original 115c, guest PC 0x0c09530e */
if(!s->budget--) { s->failed_pc=0x0c09530eu; return 0; }
write(ram,r[1]+48,r[5],4);
goto P_0c095310;
P_0c095310: /* original 116d, guest PC 0x0c095310 */
if(!s->budget--) { s->failed_pc=0x0c095310u; return 0; }
write(ram,r[1]+52,r[6],4);
goto P_0c095312;
P_0c095312: /* original 117e, guest PC 0x0c095312 */
if(!s->budget--) { s->failed_pc=0x0c095312u; return 0; }
write(ram,r[1]+56,r[7],4);
goto P_0c095314;
P_0c095314: /* original e04c, guest PC 0x0c095314 */
if(!s->budget--) { s->failed_pc=0x0c095314u; return 0; }
r[0]=0x0000004cu;
goto P_0c095316;
P_0c095316: /* original 6313, guest PC 0x0c095316 */
if(!s->budget--) { s->failed_pc=0x0c095316u; return 0; }
r[3]=r[1];
goto P_0c095318;
P_0c095318: /* original 011e, guest PC 0x0c095318 */
if(!s->budget--) { s->failed_pc=0x0c095318u; return 0; }
r[1]=read(ram,r[1]+r[0],4);
goto P_0c09531a;
P_0c09531a: /* original 7350, guest PC 0x0c09531a */
if(!s->budget--) { s->failed_pc=0x0c09531au; return 0; }
r[3]+=0x00000050u;
goto P_0c09531c;
P_0c09531c: /* original 313c, guest PC 0x0c09531c */
if(!s->budget--) { s->failed_pc=0x0c09531cu; return 0; }
r[1]+=r[3];
goto P_0c09531e;
P_0c09531e: /* original afcb, guest PC 0x0c09531e */
if(!s->budget--) { s->failed_pc=0x0c09531eu; return 0; }
goto P_0c0952b8;
P_0c095320: /* original 0009, guest PC 0x0c095320 */
if(!s->budget--) { s->failed_pc=0x0c095320u; return 0; }
goto P_0c095322;
P_0c095322: /* original 6af6, guest PC 0x0c095322 */
if(!s->budget--) { s->failed_pc=0x0c095322u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c095324;
P_0c095324: /* original 6bf6, guest PC 0x0c095324 */
if(!s->budget--) { s->failed_pc=0x0c095324u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c095326;
P_0c095326: /* original 000b, guest PC 0x0c095326 */
if(!s->budget--) { s->failed_pc=0x0c095326u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
s->pc=target; return ram->oob==0;
P_0c095328: /* original 6cf6, guest PC 0x0c095328 */
if(!s->budget--) { s->failed_pc=0x0c095328u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
return vf3_matrix_family(0x0c09532au,s,ram);
P_0c0c10a2: /* original 2fe6, guest PC 0x0c0c10a2 */
if(!s->budget--) { s->failed_pc=0x0c0c10a2u; return 0; }
r[15]-=4; write(ram,r[15],r[14],4);
goto P_0c0c10a4;
P_0c0c10a4: /* original e600, guest PC 0x0c0c10a4 */
if(!s->budget--) { s->failed_pc=0x0c0c10a4u; return 0; }
r[6]=0x00000000u;
goto P_0c0c10a6;
P_0c0c10a6: /* original 2fd6, guest PC 0x0c0c10a6 */
if(!s->budget--) { s->failed_pc=0x0c0c10a6u; return 0; }
r[15]-=4; write(ram,r[15],r[13],4);
goto P_0c0c10a8;
P_0c0c10a8: /* original d54d, guest PC 0x0c0c10a8 */
if(!s->budget--) { s->failed_pc=0x0c0c10a8u; return 0; }
r[5]=read(ram,0x0c0c11e0u,4);
goto P_0c0c10aa;
P_0c0c10aa: /* original 7ff0, guest PC 0x0c0c10aa */
if(!s->budget--) { s->failed_pc=0x0c0c10aau; return 0; }
r[15]+=0xfffffff0u;
goto P_0c0c10ac;
P_0c0c10ac: /* original 6353, guest PC 0x0c0c10ac */
if(!s->budget--) { s->failed_pc=0x0c0c10acu; return 0; }
r[3]=r[5];
goto P_0c0c10ae;
P_0c0c10ae: /* original 7358, guest PC 0x0c0c10ae */
if(!s->budget--) { s->failed_pc=0x0c0c10aeu; return 0; }
r[3]+=0x00000058u;
goto P_0c0c10b0;
P_0c0c10b0: /* original 6253, guest PC 0x0c0c10b0 */
if(!s->budget--) { s->failed_pc=0x0c0c10b0u; return 0; }
r[2]=r[5];
goto P_0c0c10b2;
P_0c0c10b2: /* original 722c, guest PC 0x0c0c10b2 */
if(!s->budget--) { s->failed_pc=0x0c0c10b2u; return 0; }
r[2]+=0x0000002cu;
goto P_0c0c10b4;
P_0c0c10b4: /* original 2f52, guest PC 0x0c0c10b4 */
if(!s->budget--) { s->failed_pc=0x0c0c10b4u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0c10b6;
P_0c0c10b6: /* original 1f31, guest PC 0x0c0c10b6 */
if(!s->budget--) { s->failed_pc=0x0c0c10b6u; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c0c10b8;
P_0c0c10b8: /* original 1f23, guest PC 0x0c0c10b8 */
if(!s->budget--) { s->failed_pc=0x0c0c10b8u; return 0; }
write(ram,r[15]+12,r[2],4);
goto P_0c0c10ba;
P_0c0c10ba: /* original 9388, guest PC 0x0c0c10ba */
if(!s->budget--) { s->failed_pc=0x0c0c10bau; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c11ceu,2);
goto P_0c0c10bc;
P_0c0c10bc: /* original 335c, guest PC 0x0c0c10bc */
if(!s->budget--) { s->failed_pc=0x0c0c10bcu; return 0; }
r[3]+=r[5];
goto P_0c0c10be;
P_0c0c10be: /* original 1f32, guest PC 0x0c0c10be */
if(!s->budget--) { s->failed_pc=0x0c0c10beu; return 0; }
write(ram,r[15]+8,r[3],4);
goto P_0c0c10c0;
P_0c0c10c0: /* original 9286, guest PC 0x0c0c10c0 */
if(!s->budget--) { s->failed_pc=0x0c0c10c0u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c11d0u,2);
goto P_0c0c10c2;
P_0c0c10c2: /* original 2248, guest PC 0x0c0c10c2 */
if(!s->budget--) { s->failed_pc=0x0c0c10c2u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[4])==0)!=0);
goto P_0c0c10c4;
P_0c0c10c4: /* original 8d03, guest PC 0x0c0c10c4 */
if(!s->budget--) { s->failed_pc=0x0c0c10c4u; return 0; }
cond=r[17]&1u;
r[5]=0x00000004u;
if(cond) { goto P_0c0c10ce; }
goto P_0c0c10c8;
P_0c0c10c6: /* original e504, guest PC 0x0c0c10c6 */
if(!s->budget--) { s->failed_pc=0x0c0c10c6u; return 0; }
r[5]=0x00000004u;
goto P_0c0c10c8;
P_0c0c10c8: /* original 6763, guest PC 0x0c0c10c8 */
if(!s->budget--) { s->failed_pc=0x0c0c10c8u; return 0; }
r[7]=r[6];
goto P_0c0c10ca;
P_0c0c10ca: /* original a002, guest PC 0x0c0c10ca */
if(!s->budget--) { s->failed_pc=0x0c0c10cau; return 0; }
r[6]+=0x00000001u;
goto P_0c0c10d2;
P_0c0c10cc: /* original 7601, guest PC 0x0c0c10cc */
if(!s->budget--) { s->failed_pc=0x0c0c10ccu; return 0; }
r[6]+=0x00000001u;
goto P_0c0c10ce;
P_0c0c10ce: /* original 6753, guest PC 0x0c0c10ce */
if(!s->budget--) { s->failed_pc=0x0c0c10ceu; return 0; }
r[7]=r[5];
goto P_0c0c10d0;
P_0c0c10d0: /* original 7501, guest PC 0x0c0c10d0 */
if(!s->budget--) { s->failed_pc=0x0c0c10d0u; return 0; }
r[5]+=0x00000001u;
goto P_0c0c10d2;
P_0c0c10d2: /* original 937e, guest PC 0x0c0c10d2 */
if(!s->budget--) { s->failed_pc=0x0c0c10d2u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c11d2u,2);
goto P_0c0c10d4;
P_0c0c10d4: /* original 2348, guest PC 0x0c0c10d4 */
if(!s->budget--) { s->failed_pc=0x0c0c10d4u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[4])==0)!=0);
goto P_0c0c10d6;
P_0c0c10d6: /* original 8902, guest PC 0x0c0c10d6 */
if(!s->budget--) { s->failed_pc=0x0c0c10d6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c10de; }
goto P_0c0c10d8;
P_0c0c10d8: /* original 6d63, guest PC 0x0c0c10d8 */
if(!s->budget--) { s->failed_pc=0x0c0c10d8u; return 0; }
r[13]=r[6];
goto P_0c0c10da;
P_0c0c10da: /* original a002, guest PC 0x0c0c10da */
if(!s->budget--) { s->failed_pc=0x0c0c10dau; return 0; }
r[6]+=0x00000001u;
goto P_0c0c10e2;
P_0c0c10dc: /* original 7601, guest PC 0x0c0c10dc */
if(!s->budget--) { s->failed_pc=0x0c0c10dcu; return 0; }
r[6]+=0x00000001u;
goto P_0c0c10de;
P_0c0c10de: /* original 6d53, guest PC 0x0c0c10de */
if(!s->budget--) { s->failed_pc=0x0c0c10deu; return 0; }
r[13]=r[5];
goto P_0c0c10e0;
P_0c0c10e0: /* original 7501, guest PC 0x0c0c10e0 */
if(!s->budget--) { s->failed_pc=0x0c0c10e0u; return 0; }
r[5]+=0x00000001u;
goto P_0c0c10e2;
P_0c0c10e2: /* original 9277, guest PC 0x0c0c10e2 */
if(!s->budget--) { s->failed_pc=0x0c0c10e2u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c11d4u,2);
goto P_0c0c10e4;
P_0c0c10e4: /* original 2248, guest PC 0x0c0c10e4 */
if(!s->budget--) { s->failed_pc=0x0c0c10e4u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[4])==0)!=0);
goto P_0c0c10e6;
P_0c0c10e6: /* original 8902, guest PC 0x0c0c10e6 */
if(!s->budget--) { s->failed_pc=0x0c0c10e6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c10ee; }
goto P_0c0c10e8;
P_0c0c10e8: /* original 6e63, guest PC 0x0c0c10e8 */
if(!s->budget--) { s->failed_pc=0x0c0c10e8u; return 0; }
r[14]=r[6];
goto P_0c0c10ea;
P_0c0c10ea: /* original a002, guest PC 0x0c0c10ea */
if(!s->budget--) { s->failed_pc=0x0c0c10eau; return 0; }
r[6]+=0x00000001u;
goto P_0c0c10f2;
P_0c0c10ec: /* original 7601, guest PC 0x0c0c10ec */
if(!s->budget--) { s->failed_pc=0x0c0c10ecu; return 0; }
r[6]+=0x00000001u;
goto P_0c0c10ee;
P_0c0c10ee: /* original 6e53, guest PC 0x0c0c10ee */
if(!s->budget--) { s->failed_pc=0x0c0c10eeu; return 0; }
r[14]=r[5];
goto P_0c0c10f0;
P_0c0c10f0: /* original 7501, guest PC 0x0c0c10f0 */
if(!s->budget--) { s->failed_pc=0x0c0c10f0u; return 0; }
r[5]+=0x00000001u;
goto P_0c0c10f2;
P_0c0c10f2: /* original 9370, guest PC 0x0c0c10f2 */
if(!s->budget--) { s->failed_pc=0x0c0c10f2u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c11d6u,2);
goto P_0c0c10f4;
P_0c0c10f4: /* original 2438, guest PC 0x0c0c10f4 */
if(!s->budget--) { s->failed_pc=0x0c0c10f4u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[3])==0)!=0);
goto P_0c0c10f6;
P_0c0c10f6: /* original 8901, guest PC 0x0c0c10f6 */
if(!s->budget--) { s->failed_pc=0x0c0c10f6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c10fc; }
goto P_0c0c10f8;
P_0c0c10f8: /* original a001, guest PC 0x0c0c10f8 */
if(!s->budget--) { s->failed_pc=0x0c0c10f8u; return 0; }
r[4]=r[6];
goto P_0c0c10fe;
P_0c0c10fa: /* original 6463, guest PC 0x0c0c10fa */
if(!s->budget--) { s->failed_pc=0x0c0c10fau; return 0; }
r[4]=r[6];
goto P_0c0c10fc;
P_0c0c10fc: /* original 6453, guest PC 0x0c0c10fc */
if(!s->budget--) { s->failed_pc=0x0c0c10fcu; return 0; }
r[4]=r[5];
goto P_0c0c10fe;
P_0c0c10fe: /* original 63f2, guest PC 0x0c0c10fe */
if(!s->budget--) { s->failed_pc=0x0c0c10feu; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c0c1100;
P_0c0c1100: /* original e026, guest PC 0x0c0c1100 */
if(!s->budget--) { s->failed_pc=0x0c0c1100u; return 0; }
r[0]=0x00000026u;
goto P_0c0c1102;
P_0c0c1102: /* original 0375, guest PC 0x0c0c1102 */
if(!s->budget--) { s->failed_pc=0x0c0c1102u; return 0; }
write(ram,r[3]+r[0],r[7],2);
goto P_0c0c1104;
P_0c0c1104: /* original e026, guest PC 0x0c0c1104 */
if(!s->budget--) { s->failed_pc=0x0c0c1104u; return 0; }
r[0]=0x00000026u;
goto P_0c0c1106;
P_0c0c1106: /* original 53f3, guest PC 0x0c0c1106 */
if(!s->budget--) { s->failed_pc=0x0c0c1106u; return 0; }
r[3]=read(ram,r[15]+12,4);
goto P_0c0c1108;
P_0c0c1108: /* original 03d5, guest PC 0x0c0c1108 */
if(!s->budget--) { s->failed_pc=0x0c0c1108u; return 0; }
write(ram,r[3]+r[0],r[13],2);
goto P_0c0c110a;
P_0c0c110a: /* original e026, guest PC 0x0c0c110a */
if(!s->budget--) { s->failed_pc=0x0c0c110au; return 0; }
r[0]=0x00000026u;
goto P_0c0c110c;
P_0c0c110c: /* original 53f1, guest PC 0x0c0c110c */
if(!s->budget--) { s->failed_pc=0x0c0c110cu; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c0c110e;
P_0c0c110e: /* original 03e5, guest PC 0x0c0c110e */
if(!s->budget--) { s->failed_pc=0x0c0c110eu; return 0; }
write(ram,r[3]+r[0],r[14],2);
goto P_0c0c1110;
P_0c0c1110: /* original e026, guest PC 0x0c0c1110 */
if(!s->budget--) { s->failed_pc=0x0c0c1110u; return 0; }
r[0]=0x00000026u;
goto P_0c0c1112;
P_0c0c1112: /* original 53f2, guest PC 0x0c0c1112 */
if(!s->budget--) { s->failed_pc=0x0c0c1112u; return 0; }
r[3]=read(ram,r[15]+8,4);
goto P_0c0c1114;
P_0c0c1114: /* original 7f10, guest PC 0x0c0c1114 */
if(!s->budget--) { s->failed_pc=0x0c0c1114u; return 0; }
r[15]+=0x00000010u;
goto P_0c0c1116;
P_0c0c1116: /* original 0345, guest PC 0x0c0c1116 */
if(!s->budget--) { s->failed_pc=0x0c0c1116u; return 0; }
write(ram,r[3]+r[0],r[4],2);
goto P_0c0c1118;
P_0c0c1118: /* original 6df6, guest PC 0x0c0c1118 */
if(!s->budget--) { s->failed_pc=0x0c0c1118u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0c111a;
P_0c0c111a: /* original 000b, guest PC 0x0c0c111a */
if(!s->budget--) { s->failed_pc=0x0c0c111au; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0c111c: /* original 6ef6, guest PC 0x0c0c111c */
if(!s->budget--) { s->failed_pc=0x0c0c111cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0c111e;
P_0c0c111e: /* original 4f22, guest PC 0x0c0c111e */
if(!s->budget--) { s->failed_pc=0x0c0c111eu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0c1120;
P_0c0c1120: /* original e022, guest PC 0x0c0c1120 */
if(!s->budget--) { s->failed_pc=0x0c0c1120u; return 0; }
r[0]=0x00000022u;
goto P_0c0c1122;
P_0c0c1122: /* original 7ff0, guest PC 0x0c0c1122 */
if(!s->budget--) { s->failed_pc=0x0c0c1122u; return 0; }
r[15]+=0xfffffff0u;
goto P_0c0c1124;
P_0c0c1124: /* original 2f52, guest PC 0x0c0c1124 */
if(!s->budget--) { s->failed_pc=0x0c0c1124u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0c1126;
P_0c0c1126: /* original 1f61, guest PC 0x0c0c1126 */
if(!s->budget--) { s->failed_pc=0x0c0c1126u; return 0; }
write(ram,r[15]+4,r[6],4);
goto P_0c0c1128;
P_0c0c1128: /* original d52d, guest PC 0x0c0c1128 */
if(!s->budget--) { s->failed_pc=0x0c0c1128u; return 0; }
r[5]=read(ram,0x0c0c11e0u,4);
goto P_0c0c112a;
P_0c0c112a: /* original 6353, guest PC 0x0c0c112a */
if(!s->budget--) { s->failed_pc=0x0c0c112au; return 0; }
r[3]=r[5];
goto P_0c0c112c;
P_0c0c112c: /* original 7358, guest PC 0x0c0c112c */
if(!s->budget--) { s->failed_pc=0x0c0c112cu; return 0; }
r[3]+=0x00000058u;
goto P_0c0c112e;
P_0c0c112e: /* original 1f32, guest PC 0x0c0c112e */
if(!s->budget--) { s->failed_pc=0x0c0c112eu; return 0; }
write(ram,r[15]+8,r[3],4);
goto P_0c0c1130;
P_0c0c1130: /* original 6753, guest PC 0x0c0c1130 */
if(!s->budget--) { s->failed_pc=0x0c0c1130u; return 0; }
r[7]=r[5];
goto P_0c0c1132;
P_0c0c1132: /* original 6273, guest PC 0x0c0c1132 */
if(!s->budget--) { s->failed_pc=0x0c0c1132u; return 0; }
r[2]=r[7];
goto P_0c0c1134;
P_0c0c1134: /* original 722c, guest PC 0x0c0c1134 */
if(!s->budget--) { s->failed_pc=0x0c0c1134u; return 0; }
r[2]+=0x0000002cu;
goto P_0c0c1136;
P_0c0c1136: /* original 1f23, guest PC 0x0c0c1136 */
if(!s->budget--) { s->failed_pc=0x0c0c1136u; return 0; }
write(ram,r[15]+12,r[2],4);
goto P_0c0c1138;
P_0c0c1138: /* original 9649, guest PC 0x0c0c1138 */
if(!s->budget--) { s->failed_pc=0x0c0c1138u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c11ceu,2);
goto P_0c0c113a;
P_0c0c113a: /* original 037d, guest PC 0x0c0c113a */
if(!s->budget--) { s->failed_pc=0x0c0c113au; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[7]+r[0],2);
goto P_0c0c113c;
P_0c0c113c: /* original 365c, guest PC 0x0c0c113c */
if(!s->budget--) { s->failed_pc=0x0c0c113cu; return 0; }
r[6]+=r[5];
goto P_0c0c113e;
P_0c0c113e: /* original d529, guest PC 0x0c0c113e */
if(!s->budget--) { s->failed_pc=0x0c0c113eu; return 0; }
r[5]=read(ram,0x0c0c11e4u,4);
goto P_0c0c1140;
P_0c0c1140: /* original 2359, guest PC 0x0c0c1140 */
if(!s->budget--) { s->failed_pc=0x0c0c1140u; return 0; }
r[3]&=r[5];
goto P_0c0c1142;
P_0c0c1142: /* original 0735, guest PC 0x0c0c1142 */
if(!s->budget--) { s->failed_pc=0x0c0c1142u; return 0; }
write(ram,r[7]+r[0],r[3],2);
goto P_0c0c1144;
P_0c0c1144: /* original e022, guest PC 0x0c0c1144 */
if(!s->budget--) { s->failed_pc=0x0c0c1144u; return 0; }
r[0]=0x00000022u;
goto P_0c0c1146;
P_0c0c1146: /* original 53f2, guest PC 0x0c0c1146 */
if(!s->budget--) { s->failed_pc=0x0c0c1146u; return 0; }
r[3]=read(ram,r[15]+8,4);
goto P_0c0c1148;
P_0c0c1148: /* original 023d, guest PC 0x0c0c1148 */
if(!s->budget--) { s->failed_pc=0x0c0c1148u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[3]+r[0],2);
goto P_0c0c114a;
P_0c0c114a: /* original 2259, guest PC 0x0c0c114a */
if(!s->budget--) { s->failed_pc=0x0c0c114au; return 0; }
r[2]&=r[5];
goto P_0c0c114c;
P_0c0c114c: /* original 0325, guest PC 0x0c0c114c */
if(!s->budget--) { s->failed_pc=0x0c0c114cu; return 0; }
write(ram,r[3]+r[0],r[2],2);
goto P_0c0c114e;
P_0c0c114e: /* original e022, guest PC 0x0c0c114e */
if(!s->budget--) { s->failed_pc=0x0c0c114eu; return 0; }
r[0]=0x00000022u;
goto P_0c0c1150;
P_0c0c1150: /* original 53f3, guest PC 0x0c0c1150 */
if(!s->budget--) { s->failed_pc=0x0c0c1150u; return 0; }
r[3]=read(ram,r[15]+12,4);
goto P_0c0c1152;
P_0c0c1152: /* original 023d, guest PC 0x0c0c1152 */
if(!s->budget--) { s->failed_pc=0x0c0c1152u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[3]+r[0],2);
goto P_0c0c1154;
P_0c0c1154: /* original 2259, guest PC 0x0c0c1154 */
if(!s->budget--) { s->failed_pc=0x0c0c1154u; return 0; }
r[2]&=r[5];
goto P_0c0c1156;
P_0c0c1156: /* original 0325, guest PC 0x0c0c1156 */
if(!s->budget--) { s->failed_pc=0x0c0c1156u; return 0; }
write(ram,r[3]+r[0],r[2],2);
goto P_0c0c1158;
P_0c0c1158: /* original 036d, guest PC 0x0c0c1158 */
if(!s->budget--) { s->failed_pc=0x0c0c1158u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[6]+r[0],2);
goto P_0c0c115a;
P_0c0c115a: /* original 2359, guest PC 0x0c0c115a */
if(!s->budget--) { s->failed_pc=0x0c0c115au; return 0; }
r[3]&=r[5];
goto P_0c0c115c;
P_0c0c115c: /* original bfa1, guest PC 0x0c0c115c */
if(!s->budget--) { s->failed_pc=0x0c0c115cu; return 0; }
target=0x0c0c10a2u; r[16]=0x0c0c1160u;
write(ram,r[6]+r[0],r[3],2);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c1160u) { target=s->pc; goto dispatch; }
goto P_0c0c1160;
P_0c0c115e: /* original 0635, guest PC 0x0c0c115e */
if(!s->budget--) { s->failed_pc=0x0c0c115eu; return 0; }
write(ram,r[6]+r[0],r[3],2);
goto P_0c0c1160;
P_0c0c1160: /* original 63f2, guest PC 0x0c0c1160 */
if(!s->budget--) { s->failed_pc=0x0c0c1160u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c0c1162;
P_0c0c1162: /* original e022, guest PC 0x0c0c1162 */
if(!s->budget--) { s->failed_pc=0x0c0c1162u; return 0; }
r[0]=0x00000022u;
goto P_0c0c1164;
P_0c0c1164: /* original e202, guest PC 0x0c0c1164 */
if(!s->budget--) { s->failed_pc=0x0c0c1164u; return 0; }
r[2]=0x00000002u;
goto P_0c0c1166;
P_0c0c1166: /* original 013d, guest PC 0x0c0c1166 */
if(!s->budget--) { s->failed_pc=0x0c0c1166u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,r[3]+r[0],2);
goto P_0c0c1168;
P_0c0c1168: /* original 212b, guest PC 0x0c0c1168 */
if(!s->budget--) { s->failed_pc=0x0c0c1168u; return 0; }
r[1]|=r[2];
goto P_0c0c116a;
P_0c0c116a: /* original 0315, guest PC 0x0c0c116a */
if(!s->budget--) { s->failed_pc=0x0c0c116au; return 0; }
write(ram,r[3]+r[0],r[1],2);
goto P_0c0c116c;
P_0c0c116c: /* original e022, guest PC 0x0c0c116c */
if(!s->budget--) { s->failed_pc=0x0c0c116cu; return 0; }
r[0]=0x00000022u;
goto P_0c0c116e;
P_0c0c116e: /* original 53f1, guest PC 0x0c0c116e */
if(!s->budget--) { s->failed_pc=0x0c0c116eu; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c0c1170;
P_0c0c1170: /* original 7f10, guest PC 0x0c0c1170 */
if(!s->budget--) { s->failed_pc=0x0c0c1170u; return 0; }
r[15]+=0x00000010u;
goto P_0c0c1172;
P_0c0c1172: /* original 4f26, guest PC 0x0c0c1172 */
if(!s->budget--) { s->failed_pc=0x0c0c1172u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c1174;
P_0c0c1174: /* original 013d, guest PC 0x0c0c1174 */
if(!s->budget--) { s->failed_pc=0x0c0c1174u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,r[3]+r[0],2);
goto P_0c0c1176;
P_0c0c1176: /* original 212b, guest PC 0x0c0c1176 */
if(!s->budget--) { s->failed_pc=0x0c0c1176u; return 0; }
r[1]|=r[2];
goto P_0c0c1178;
P_0c0c1178: /* original 0315, guest PC 0x0c0c1178 */
if(!s->budget--) { s->failed_pc=0x0c0c1178u; return 0; }
write(ram,r[3]+r[0],r[1],2);
goto P_0c0c117a;
P_0c0c117a: /* original 000b, guest PC 0x0c0c117a */
if(!s->budget--) { s->failed_pc=0x0c0c117au; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c0c117c: /* original 0009, guest PC 0x0c0c117c */
if(!s->budget--) { s->failed_pc=0x0c0c117cu; return 0; }
return vf3_matrix_family(0x0c0c117eu,s,ram);
P_0c0c124e: /* original e100, guest PC 0x0c0c124e */
if(!s->budget--) { s->failed_pc=0x0c0c124eu; return 0; }
r[1]=0x00000000u;
goto P_0c0c1250;
P_0c0c1250: /* original d324, guest PC 0x0c0c1250 */
if(!s->budget--) { s->failed_pc=0x0c0c1250u; return 0; }
r[3]=read(ram,0x0c0c12e4u,4);
goto P_0c0c1252;
P_0c0c1252: /* original e022, guest PC 0x0c0c1252 */
if(!s->budget--) { s->failed_pc=0x0c0c1252u; return 0; }
r[0]=0x00000022u;
goto P_0c0c1254;
P_0c0c1254: /* original 7ffc, guest PC 0x0c0c1254 */
if(!s->budget--) { s->failed_pc=0x0c0c1254u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c0c1256;
P_0c0c1256: /* original 2f32, guest PC 0x0c0c1256 */
if(!s->budget--) { s->failed_pc=0x0c0c1256u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c0c1258;
P_0c0c1258: /* original 0415, guest PC 0x0c0c1258 */
if(!s->budget--) { s->failed_pc=0x0c0c1258u; return 0; }
write(ram,r[4]+r[0],r[1],2);
goto P_0c0c125a;
P_0c0c125a: /* original 6063, guest PC 0x0c0c125a */
if(!s->budget--) { s->failed_pc=0x0c0c125au; return 0; }
r[0]=r[6];
goto P_0c0c125c;
P_0c0c125c: /* original 1474, guest PC 0x0c0c125c */
if(!s->budget--) { s->failed_pc=0x0c0c125cu; return 0; }
write(ram,r[4]+16,r[7],4);
goto P_0c0c125e;
P_0c0c125e: /* original 53f1, guest PC 0x0c0c125e */
if(!s->budget--) { s->failed_pc=0x0c0c125eu; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c0c1260;
P_0c0c1260: /* original 1433, guest PC 0x0c0c1260 */
if(!s->budget--) { s->failed_pc=0x0c0c1260u; return 0; }
write(ram,r[4]+12,r[3],4);
goto P_0c0c1262;
P_0c0c1262: /* original 2451, guest PC 0x0c0c1262 */
if(!s->budget--) { s->failed_pc=0x0c0c1262u; return 0; }
write(ram,r[4],r[5],2);
goto P_0c0c1264;
P_0c0c1264: /* original 8141, guest PC 0x0c0c1264 */
if(!s->budget--) { s->failed_pc=0x0c0c1264u; return 0; }
write(ram,r[4]+2,r[0],2);
goto P_0c0c1266;
P_0c0c1266: /* original e040, guest PC 0x0c0c1266 */
if(!s->budget--) { s->failed_pc=0x0c0c1266u; return 0; }
r[0]=0x00000040u;
goto P_0c0c1268;
P_0c0c1268: /* original 53f2, guest PC 0x0c0c1268 */
if(!s->budget--) { s->failed_pc=0x0c0c1268u; return 0; }
r[3]=read(ram,r[15]+8,4);
goto P_0c0c126a;
P_0c0c126a: /* original 1436, guest PC 0x0c0c126a */
if(!s->budget--) { s->failed_pc=0x0c0c126au; return 0; }
write(ram,r[4]+24,r[3],4);
goto P_0c0c126c;
P_0c0c126c: /* original 52f3, guest PC 0x0c0c126c */
if(!s->budget--) { s->failed_pc=0x0c0c126cu; return 0; }
r[2]=read(ram,r[15]+12,4);
goto P_0c0c126e;
P_0c0c126e: /* original 1427, guest PC 0x0c0c126e */
if(!s->budget--) { s->failed_pc=0x0c0c126eu; return 0; }
write(ram,r[4]+28,r[2],4);
goto P_0c0c1270;
P_0c0c1270: /* original 8142, guest PC 0x0c0c1270 */
if(!s->budget--) { s->failed_pc=0x0c0c1270u; return 0; }
write(ram,r[4]+4,r[0],2);
goto P_0c0c1272;
P_0c0c1272: /* original e030, guest PC 0x0c0c1272 */
if(!s->budget--) { s->failed_pc=0x0c0c1272u; return 0; }
r[0]=0x00000030u;
goto P_0c0c1274;
P_0c0c1274: /* original 8143, guest PC 0x0c0c1274 */
if(!s->budget--) { s->failed_pc=0x0c0c1274u; return 0; }
write(ram,r[4]+6,r[0],2);
goto P_0c0c1276;
P_0c0c1276: /* original e03e, guest PC 0x0c0c1276 */
if(!s->budget--) { s->failed_pc=0x0c0c1276u; return 0; }
r[0]=0x0000003eu;
goto P_0c0c1278;
P_0c0c1278: /* original 8144, guest PC 0x0c0c1278 */
if(!s->budget--) { s->failed_pc=0x0c0c1278u; return 0; }
write(ram,r[4]+8,r[0],2);
goto P_0c0c127a;
P_0c0c127a: /* original e02e, guest PC 0x0c0c127a */
if(!s->budget--) { s->failed_pc=0x0c0c127au; return 0; }
r[0]=0x0000002eu;
goto P_0c0c127c;
P_0c0c127c: /* original 8145, guest PC 0x0c0c127c */
if(!s->budget--) { s->failed_pc=0x0c0c127cu; return 0; }
write(ram,r[4]+10,r[0],2);
goto P_0c0c127e;
P_0c0c127e: /* original 6013, guest PC 0x0c0c127e */
if(!s->budget--) { s->failed_pc=0x0c0c127eu; return 0; }
r[0]=r[1];
goto P_0c0c1280;
P_0c0c1280: /* original 814a, guest PC 0x0c0c1280 */
if(!s->budget--) { s->failed_pc=0x0c0c1280u; return 0; }
write(ram,r[4]+20,r[0],2);
goto P_0c0c1282;
P_0c0c1282: /* original 814b, guest PC 0x0c0c1282 */
if(!s->budget--) { s->failed_pc=0x0c0c1282u; return 0; }
write(ram,r[4]+22,r[0],2);
goto P_0c0c1284;
P_0c0c1284: /* original e020, guest PC 0x0c0c1284 */
if(!s->budget--) { s->failed_pc=0x0c0c1284u; return 0; }
r[0]=0x00000020u;
goto P_0c0c1286;
P_0c0c1286: /* original 932a, guest PC 0x0c0c1286 */
if(!s->budget--) { s->failed_pc=0x0c0c1286u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c12deu,2);
goto P_0c0c1288;
P_0c0c1288: /* original 0435, guest PC 0x0c0c1288 */
if(!s->budget--) { s->failed_pc=0x0c0c1288u; return 0; }
write(ram,r[4]+r[0],r[3],2);
goto P_0c0c128a;
P_0c0c128a: /* original e3ff, guest PC 0x0c0c128a */
if(!s->budget--) { s->failed_pc=0x0c0c128au; return 0; }
r[3]=0xffffffffu;
goto P_0c0c128c;
P_0c0c128c: /* original 62f2, guest PC 0x0c0c128c */
if(!s->budget--) { s->failed_pc=0x0c0c128cu; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c0c128e;
P_0c0c128e: /* original 9027, guest PC 0x0c0c128e */
if(!s->budget--) { s->failed_pc=0x0c0c128eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c12e0u,2);
goto P_0c0c1290;
P_0c0c1290: /* original 0236, guest PC 0x0c0c1290 */
if(!s->budget--) { s->failed_pc=0x0c0c1290u; return 0; }
write(ram,r[2]+r[0],r[3],4);
goto P_0c0c1292;
P_0c0c1292: /* original a000, guest PC 0x0c0c1292 */
if(!s->budget--) { s->failed_pc=0x0c0c1292u; return 0; }
r[15]+=0x00000004u;
goto P_0c0c1296;
P_0c0c1294: /* original 7f04, guest PC 0x0c0c1294 */
if(!s->budget--) { s->failed_pc=0x0c0c1294u; return 0; }
r[15]+=0x00000004u;
goto P_0c0c1296;
P_0c0c1296: /* original 2fe6, guest PC 0x0c0c1296 */
if(!s->budget--) { s->failed_pc=0x0c0c1296u; return 0; }
r[15]-=4; write(ram,r[15],r[14],4);
goto P_0c0c1298;
P_0c0c1298: /* original 6e43, guest PC 0x0c0c1298 */
if(!s->budget--) { s->failed_pc=0x0c0c1298u; return 0; }
r[14]=r[4];
goto P_0c0c129a;
P_0c0c129a: /* original 2fd6, guest PC 0x0c0c129a */
if(!s->budget--) { s->failed_pc=0x0c0c129au; return 0; }
r[15]-=4; write(ram,r[15],r[13],4);
goto P_0c0c129c;
P_0c0c129c: /* original ed00, guest PC 0x0c0c129c */
if(!s->budget--) { s->failed_pc=0x0c0c129cu; return 0; }
r[13]=0x00000000u;
goto P_0c0c129e;
P_0c0c129e: /* original 2fc6, guest PC 0x0c0c129e */
if(!s->budget--) { s->failed_pc=0x0c0c129eu; return 0; }
r[15]-=4; write(ram,r[15],r[12],4);
goto P_0c0c12a0;
P_0c0c12a0: /* original ec78, guest PC 0x0c0c12a0 */
if(!s->budget--) { s->failed_pc=0x0c0c12a0u; return 0; }
r[12]=0x00000078u;
goto P_0c0c12a2;
P_0c0c12a2: /* original 2fb6, guest PC 0x0c0c12a2 */
if(!s->budget--) { s->failed_pc=0x0c0c12a2u; return 0; }
r[15]-=4; write(ram,r[15],r[11],4);
goto P_0c0c12a4;
P_0c0c12a4: /* original 4f22, guest PC 0x0c0c12a4 */
if(!s->budget--) { s->failed_pc=0x0c0c12a4u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0c12a6;
P_0c0c12a6: /* original 7ffc, guest PC 0x0c0c12a6 */
if(!s->budget--) { s->failed_pc=0x0c0c12a6u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c0c12a8;
P_0c0c12a8: /* original 2f42, guest PC 0x0c0c12a8 */
if(!s->budget--) { s->failed_pc=0x0c0c12a8u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c0c12aa;
P_0c0c12aa: /* original 5ee3, guest PC 0x0c0c12aa */
if(!s->budget--) { s->failed_pc=0x0c0c12aau; return 0; }
r[14]=read(ram,r[14]+12,4);
goto P_0c0c12ac;
P_0c0c12ac: /* original db0f, guest PC 0x0c0c12ac */
if(!s->budget--) { s->failed_pc=0x0c0c12acu; return 0; }
r[11]=read(ram,0x0c0c12ecu,4);
goto P_0c0c12ae;
P_0c0c12ae: /* original e500, guest PC 0x0c0c12ae */
if(!s->budget--) { s->failed_pc=0x0c0c12aeu; return 0; }
r[5]=0x00000000u;
goto P_0c0c12b0;
P_0c0c12b0: /* original e644, guest PC 0x0c0c12b0 */
if(!s->budget--) { s->failed_pc=0x0c0c12b0u; return 0; }
r[6]=0x00000044u;
goto P_0c0c12b2;
P_0c0c12b2: /* original 4b0b, guest PC 0x0c0c12b2 */
if(!s->budget--) { s->failed_pc=0x0c0c12b2u; return 0; }
target=r[11];
r[16]=0x0c0c12b6u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c12b6u) { target=s->pc; goto dispatch; }
goto P_0c0c12b6;
P_0c0c12b4: /* original 64e3, guest PC 0x0c0c12b4 */
if(!s->budget--) { s->failed_pc=0x0c0c12b4u; return 0; }
r[4]=r[14];
goto P_0c0c12b6;
P_0c0c12b6: /* original 7d01, guest PC 0x0c0c12b6 */
if(!s->budget--) { s->failed_pc=0x0c0c12b6u; return 0; }
r[13]+=0x00000001u;
goto P_0c0c12b8;
P_0c0c12b8: /* original 3dc2, guest PC 0x0c0c12b8 */
if(!s->budget--) { s->failed_pc=0x0c0c12b8u; return 0; }
r[17]=(r[17]&~1u)|((r[13]>=r[12])!=0);
goto P_0c0c12ba;
P_0c0c12ba: /* original 8ff8, guest PC 0x0c0c12ba */
if(!s->budget--) { s->failed_pc=0x0c0c12bau; return 0; }
cond=r[17]&1u;
r[14]+=0x00000044u;
if(!cond) { goto P_0c0c12ae; }
goto P_0c0c12be;
P_0c0c12bc: /* original 7e44, guest PC 0x0c0c12bc */
if(!s->budget--) { s->failed_pc=0x0c0c12bcu; return 0; }
r[14]+=0x00000044u;
goto P_0c0c12be;
P_0c0c12be: /* original 63f2, guest PC 0x0c0c12be */
if(!s->budget--) { s->failed_pc=0x0c0c12beu; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c0c12c0;
P_0c0c12c0: /* original 7f04, guest PC 0x0c0c12c0 */
if(!s->budget--) { s->failed_pc=0x0c0c12c0u; return 0; }
r[15]+=0x00000004u;
goto P_0c0c12c2;
P_0c0c12c2: /* original 4f26, guest PC 0x0c0c12c2 */
if(!s->budget--) { s->failed_pc=0x0c0c12c2u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c12c4;
P_0c0c12c4: /* original e022, guest PC 0x0c0c12c4 */
if(!s->budget--) { s->failed_pc=0x0c0c12c4u; return 0; }
r[0]=0x00000022u;
goto P_0c0c12c6;
P_0c0c12c6: /* original 013d, guest PC 0x0c0c12c6 */
if(!s->budget--) { s->failed_pc=0x0c0c12c6u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,r[3]+r[0],2);
goto P_0c0c12c8;
P_0c0c12c8: /* original e201, guest PC 0x0c0c12c8 */
if(!s->budget--) { s->failed_pc=0x0c0c12c8u; return 0; }
r[2]=0x00000001u;
goto P_0c0c12ca;
P_0c0c12ca: /* original 212b, guest PC 0x0c0c12ca */
if(!s->budget--) { s->failed_pc=0x0c0c12cau; return 0; }
r[1]|=r[2];
goto P_0c0c12cc;
P_0c0c12cc: /* original 0315, guest PC 0x0c0c12cc */
if(!s->budget--) { s->failed_pc=0x0c0c12ccu; return 0; }
write(ram,r[3]+r[0],r[1],2);
goto P_0c0c12ce;
P_0c0c12ce: /* original 6bf6, guest PC 0x0c0c12ce */
if(!s->budget--) { s->failed_pc=0x0c0c12ceu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0c12d0;
P_0c0c12d0: /* original 6cf6, guest PC 0x0c0c12d0 */
if(!s->budget--) { s->failed_pc=0x0c0c12d0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0c12d2;
P_0c0c12d2: /* original 6df6, guest PC 0x0c0c12d2 */
if(!s->budget--) { s->failed_pc=0x0c0c12d2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0c12d4;
P_0c0c12d4: /* original 000b, guest PC 0x0c0c12d4 */
if(!s->budget--) { s->failed_pc=0x0c0c12d4u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0c12d6: /* original 6ef6, guest PC 0x0c0c12d6 */
if(!s->budget--) { s->failed_pc=0x0c0c12d6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0c12d8u,s,ram);
P_0c0c1fba: /* original 2fe6, guest PC 0x0c0c1fba */
if(!s->budget--) { s->failed_pc=0x0c0c1fbau; return 0; }
r[15]-=4; write(ram,r[15],r[14],4);
goto P_0c0c1fbc;
P_0c0c1fbc: /* original e044, guest PC 0x0c0c1fbc */
if(!s->budget--) { s->failed_pc=0x0c0c1fbcu; return 0; }
r[0]=0x00000044u;
goto P_0c0c1fbe;
P_0c0c1fbe: /* original 2fd6, guest PC 0x0c0c1fbe */
if(!s->budget--) { s->failed_pc=0x0c0c1fbeu; return 0; }
r[15]-=4; write(ram,r[15],r[13],4);
goto P_0c0c1fc0;
P_0c0c1fc0: /* original 2fc6, guest PC 0x0c0c1fc0 */
if(!s->budget--) { s->failed_pc=0x0c0c1fc0u; return 0; }
r[15]-=4; write(ram,r[15],r[12],4);
goto P_0c0c1fc2;
P_0c0c1fc2: /* original 6c53, guest PC 0x0c0c1fc2 */
if(!s->budget--) { s->failed_pc=0x0c0c1fc2u; return 0; }
r[12]=r[5];
goto P_0c0c1fc4;
P_0c0c1fc4: /* original 2fb6, guest PC 0x0c0c1fc4 */
if(!s->budget--) { s->failed_pc=0x0c0c1fc4u; return 0; }
r[15]-=4; write(ram,r[15],r[11],4);
goto P_0c0c1fc6;
P_0c0c1fc6: /* original 2fa6, guest PC 0x0c0c1fc6 */
if(!s->budget--) { s->failed_pc=0x0c0c1fc6u; return 0; }
r[15]-=4; write(ram,r[15],r[10],4);
goto P_0c0c1fc8;
P_0c0c1fc8: /* original 6a63, guest PC 0x0c0c1fc8 */
if(!s->budget--) { s->failed_pc=0x0c0c1fc8u; return 0; }
r[10]=r[6];
goto P_0c0c1fca;
P_0c0c1fca: /* original 2f96, guest PC 0x0c0c1fca */
if(!s->budget--) { s->failed_pc=0x0c0c1fcau; return 0; }
r[15]-=4; write(ram,r[15],r[9],4);
goto P_0c0c1fcc;
P_0c0c1fcc: /* original 6943, guest PC 0x0c0c1fcc */
if(!s->budget--) { s->failed_pc=0x0c0c1fccu; return 0; }
r[9]=r[4];
goto P_0c0c1fce;
P_0c0c1fce: /* original 2f86, guest PC 0x0c0c1fce */
if(!s->budget--) { s->failed_pc=0x0c0c1fceu; return 0; }
r[15]-=4; write(ram,r[15],r[8],4);
goto P_0c0c1fd0;
P_0c0c1fd0: /* original fffb, guest PC 0x0c0c1fd0 */
if(!s->budget--) { s->failed_pc=0x0c0c1fd0u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c0c1fd2;
P_0c0c1fd2: /* original ffeb, guest PC 0x0c0c1fd2 */
if(!s->budget--) { s->failed_pc=0x0c0c1fd2u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,14,r[15]);
goto P_0c0c1fd4;
P_0c0c1fd4: /* original ffdb, guest PC 0x0c0c1fd4 */
if(!s->budget--) { s->failed_pc=0x0c0c1fd4u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,13,r[15]);
goto P_0c0c1fd6;
P_0c0c1fd6: /* original ffcb, guest PC 0x0c0c1fd6 */
if(!s->budget--) { s->failed_pc=0x0c0c1fd6u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,12,r[15]);
goto P_0c0c1fd8;
P_0c0c1fd8: /* original 4f22, guest PC 0x0c0c1fd8 */
if(!s->budget--) { s->failed_pc=0x0c0c1fd8u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0c1fda;
P_0c0c1fda: /* original 7fec, guest PC 0x0c0c1fda */
if(!s->budget--) { s->failed_pc=0x0c0c1fdau; return 0; }
r[15]+=0xffffffecu;
goto P_0c0c1fdc;
P_0c0c1fdc: /* original 2f72, guest PC 0x0c0c1fdc */
if(!s->budget--) { s->failed_pc=0x0c0c1fdcu; return 0; }
write(ram,r[15],r[7],4);
goto P_0c0c1fde;
P_0c0c1fde: /* original 0bfe, guest PC 0x0c0c1fde */
if(!s->budget--) { s->failed_pc=0x0c0c1fdeu; return 0; }
r[11]=read(ram,r[15]+r[0],4);
goto P_0c0c1fe0;
P_0c0c1fe0: /* original e048, guest PC 0x0c0c1fe0 */
if(!s->budget--) { s->failed_pc=0x0c0c1fe0u; return 0; }
r[0]=0x00000048u;
goto P_0c0c1fe2;
P_0c0c1fe2: /* original d364, guest PC 0x0c0c1fe2 */
if(!s->budget--) { s->failed_pc=0x0c0c1fe2u; return 0; }
r[3]=read(ram,0x0c0c2174u,4);
goto P_0c0c1fe4;
P_0c0c1fe4: /* original 54a3, guest PC 0x0c0c1fe4 */
if(!s->budget--) { s->failed_pc=0x0c0c1fe4u; return 0; }
r[4]=read(ram,r[10]+12,4);
goto P_0c0c1fe6;
P_0c0c1fe6: /* original 0dfe, guest PC 0x0c0c1fe6 */
if(!s->budget--) { s->failed_pc=0x0c0c1fe6u; return 0; }
r[13]=read(ram,r[15]+r[0],4);
goto P_0c0c1fe8;
P_0c0c1fe8: /* original 23c8, guest PC 0x0c0c1fe8 */
if(!s->budget--) { s->failed_pc=0x0c0c1fe8u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[12])==0)!=0);
goto P_0c0c1fea;
P_0c0c1fea: /* original 8d20, guest PC 0x0c0c1fea */
if(!s->budget--) { s->failed_pc=0x0c0c1feau; return 0; }
cond=r[17]&1u;
r[8]=0x0000003fu;
if(cond) { goto P_0c0c202e; }
goto P_0c0c1fee;
P_0c0c1fec: /* original e83f, guest PC 0x0c0c1fec */
if(!s->budget--) { s->failed_pc=0x0c0c1fecu; return 0; }
r[8]=0x0000003fu;
goto P_0c0c1fee;
P_0c0c1fee: /* original e3f9, guest PC 0x0c0c1fee */
if(!s->budget--) { s->failed_pc=0x0c0c1feeu; return 0; }
r[3]=0xfffffff9u;
goto P_0c0c1ff0;
P_0c0c1ff0: /* original 6d93, guest PC 0x0c0c1ff0 */
if(!s->budget--) { s->failed_pc=0x0c0c1ff0u; return 0; }
r[13]=r[9];
goto P_0c0c1ff2;
P_0c0c1ff2: /* original 493d, guest PC 0x0c0c1ff2 */
if(!s->budget--) { s->failed_pc=0x0c0c1ff2u; return 0; }
r[9]=(r[3]&0x80000000u)?((r[3]&31u)?r[9]>>((-r[3])&31u):0):r[9]<<(r[3]&31u);
goto P_0c0c1ff4;
P_0c0c1ff4: /* original d25f, guest PC 0x0c0c1ff4 */
if(!s->budget--) { s->failed_pc=0x0c0c1ff4u; return 0; }
r[2]=read(ram,0x0c0c2174u,4);
goto P_0c0c1ff6;
P_0c0c1ff6: /* original e500, guest PC 0x0c0c1ff6 */
if(!s->budget--) { s->failed_pc=0x0c0c1ff6u; return 0; }
r[5]=0x00000000u;
goto P_0c0c1ff8;
P_0c0c1ff8: /* original 6e93, guest PC 0x0c0c1ff8 */
if(!s->budget--) { s->failed_pc=0x0c0c1ff8u; return 0; }
r[14]=r[9];
goto P_0c0c1ffa;
P_0c0c1ffa: /* original 4d01, guest PC 0x0c0c1ffa */
if(!s->budget--) { s->failed_pc=0x0c0c1ffau; return 0; }
r[17]=(r[17]&~1u)|((r[13]&1)!=0);
r[13]>>=1;
goto P_0c0c1ffc;
P_0c0c1ffc: /* original 6653, guest PC 0x0c0c1ffc */
if(!s->budget--) { s->failed_pc=0x0c0c1ffcu; return 0; }
r[6]=r[5];
goto P_0c0c1ffe;
P_0c0c1ffe: /* original 2c2a, guest PC 0x0c0c1ffe */
if(!s->budget--) { s->failed_pc=0x0c0c1ffeu; return 0; }
r[12]^=r[2];
goto P_0c0c2000;
P_0c0c2000: /* original 2e89, guest PC 0x0c0c2000 */
if(!s->budget--) { s->failed_pc=0x0c0c2000u; return 0; }
r[14]&=r[8];
goto P_0c0c2002;
P_0c0c2002: /* original 2d89, guest PC 0x0c0c2002 */
if(!s->budget--) { s->failed_pc=0x0c0c2002u; return 0; }
r[13]&=r[8];
goto P_0c0c2004;
P_0c0c2004: /* original a00f, guest PC 0x0c0c2004 */
if(!s->budget--) { s->failed_pc=0x0c0c2004u; return 0; }
r[7]=0x00000078u;
goto P_0c0c2026;
P_0c0c2006: /* original e778, guest PC 0x0c0c2006 */
if(!s->budget--) { s->failed_pc=0x0c0c2006u; return 0; }
r[7]=0x00000078u;
goto P_0c0c2008;
P_0c0c2008: /* original 8543, guest PC 0x0c0c2008 */
if(!s->budget--) { s->failed_pc=0x0c0c2008u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+6,2);
goto P_0c0c200a;
P_0c0c200a: /* original 600d, guest PC 0x0c0c200a */
if(!s->budget--) { s->failed_pc=0x0c0c200au; return 0; }
r[0]=r[0]&65535u;
goto P_0c0c200c;
P_0c0c200c: /* original 30d0, guest PC 0x0c0c200c */
if(!s->budget--) { s->failed_pc=0x0c0c200cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==r[13])!=0);
goto P_0c0c200e;
P_0c0c200e: /* original 8b08, guest PC 0x0c0c200e */
if(!s->budget--) { s->failed_pc=0x0c0c200eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c2022; }
goto P_0c0c2010;
P_0c0c2010: /* original 8544, guest PC 0x0c0c2010 */
if(!s->budget--) { s->failed_pc=0x0c0c2010u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+8,2);
goto P_0c0c2012;
P_0c0c2012: /* original 600d, guest PC 0x0c0c2012 */
if(!s->budget--) { s->failed_pc=0x0c0c2012u; return 0; }
r[0]=r[0]&65535u;
goto P_0c0c2014;
P_0c0c2014: /* original 30e0, guest PC 0x0c0c2014 */
if(!s->budget--) { s->failed_pc=0x0c0c2014u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==r[14])!=0);
goto P_0c0c2016;
P_0c0c2016: /* original 8b04, guest PC 0x0c0c2016 */
if(!s->budget--) { s->failed_pc=0x0c0c2016u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c2022; }
goto P_0c0c2018;
P_0c0c2018: /* original 8541, guest PC 0x0c0c2018 */
if(!s->budget--) { s->failed_pc=0x0c0c2018u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+2,2);
goto P_0c0c201a;
P_0c0c201a: /* original 600d, guest PC 0x0c0c201a */
if(!s->budget--) { s->failed_pc=0x0c0c201au; return 0; }
r[0]=r[0]&65535u;
goto P_0c0c201c;
P_0c0c201c: /* original 30c0, guest PC 0x0c0c201c */
if(!s->budget--) { s->failed_pc=0x0c0c201cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==r[12])!=0);
goto P_0c0c201e;
P_0c0c201e: /* original 8b00, guest PC 0x0c0c201e */
if(!s->budget--) { s->failed_pc=0x0c0c201eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c2022; }
goto P_0c0c2020;
P_0c0c2020: /* original 2451, guest PC 0x0c0c2020 */
if(!s->budget--) { s->failed_pc=0x0c0c2020u; return 0; }
write(ram,r[4],r[5],2);
goto P_0c0c2022;
P_0c0c2022: /* original 7601, guest PC 0x0c0c2022 */
if(!s->budget--) { s->failed_pc=0x0c0c2022u; return 0; }
r[6]+=0x00000001u;
goto P_0c0c2024;
P_0c0c2024: /* original 7444, guest PC 0x0c0c2024 */
if(!s->budget--) { s->failed_pc=0x0c0c2024u; return 0; }
r[4]+=0x00000044u;
goto P_0c0c2026;
P_0c0c2026: /* original 3672, guest PC 0x0c0c2026 */
if(!s->budget--) { s->failed_pc=0x0c0c2026u; return 0; }
r[17]=(r[17]&~1u)|((r[6]>=r[7])!=0);
goto P_0c0c2028;
P_0c0c2028: /* original 8bee, guest PC 0x0c0c2028 */
if(!s->budget--) { s->failed_pc=0x0c0c2028u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c2008; }
goto P_0c0c202a;
P_0c0c202a: /* original a00f, guest PC 0x0c0c202a */
if(!s->budget--) { s->failed_pc=0x0c0c202au; return 0; }
goto P_0c0c204c;
P_0c0c202c: /* original 0009, guest PC 0x0c0c202c */
if(!s->budget--) { s->failed_pc=0x0c0c202cu; return 0; }
goto P_0c0c202e;
P_0c0c202e: /* original 2fd6, guest PC 0x0c0c202e */
if(!s->budget--) { s->failed_pc=0x0c0c202eu; return 0; }
r[15]-=4; write(ram,r[15],r[13],4);
goto P_0c0c2030;
P_0c0c2030: /* original 66a3, guest PC 0x0c0c2030 */
if(!s->budget--) { s->failed_pc=0x0c0c2030u; return 0; }
r[6]=r[10];
goto P_0c0c2032;
P_0c0c2032: /* original 2fb6, guest PC 0x0c0c2032 */
if(!s->budget--) { s->failed_pc=0x0c0c2032u; return 0; }
r[15]-=4; write(ram,r[15],r[11],4);
goto P_0c0c2034;
P_0c0c2034: /* original d54f, guest PC 0x0c0c2034 */
if(!s->budget--) { s->failed_pc=0x0c0c2034u; return 0; }
r[5]=read(ram,0x0c0c2174u,4);
goto P_0c0c2036;
P_0c0c2036: /* original 57f2, guest PC 0x0c0c2036 */
if(!s->budget--) { s->failed_pc=0x0c0c2036u; return 0; }
r[7]=read(ram,r[15]+8,4);
goto P_0c0c2038;
P_0c0c2038: /* original 25cb, guest PC 0x0c0c2038 */
if(!s->budget--) { s->failed_pc=0x0c0c2038u; return 0; }
r[5]|=r[12];
goto P_0c0c203a;
P_0c0c203a: /* original bfbe, guest PC 0x0c0c203a */
if(!s->budget--) { s->failed_pc=0x0c0c203au; return 0; }
target=0x0c0c1fbau; r[16]=0x0c0c203eu;
r[4]=r[9];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c203eu) { target=s->pc; goto dispatch; }
goto P_0c0c203e;
P_0c0c203c: /* original 6493, guest PC 0x0c0c203c */
if(!s->budget--) { s->failed_pc=0x0c0c203cu; return 0; }
r[4]=r[9];
goto P_0c0c203e;
P_0c0c203e: /* original d24e, guest PC 0x0c0c203e */
if(!s->budget--) { s->failed_pc=0x0c0c203eu; return 0; }
r[2]=read(ram,0x0c0c2178u,4);
goto P_0c0c2040;
P_0c0c2040: /* original 7f08, guest PC 0x0c0c2040 */
if(!s->budget--) { s->failed_pc=0x0c0c2040u; return 0; }
r[15]+=0x00000008u;
goto P_0c0c2042;
P_0c0c2042: /* original 420b, guest PC 0x0c0c2042 */
if(!s->budget--) { s->failed_pc=0x0c0c2042u; return 0; }
target=r[2];
r[16]=0x0c0c2046u;
r[4]=r[10];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c2046u) { target=s->pc; goto dispatch; }
goto P_0c0c2046;
P_0c0c2044: /* original 64a3, guest PC 0x0c0c2044 */
if(!s->budget--) { s->failed_pc=0x0c0c2044u; return 0; }
r[4]=r[10];
goto P_0c0c2046;
P_0c0c2046: /* original 6e03, guest PC 0x0c0c2046 */
if(!s->budget--) { s->failed_pc=0x0c0c2046u; return 0; }
r[14]=r[0];
goto P_0c0c2048;
P_0c0c2048: /* original 2ee8, guest PC 0x0c0c2048 */
if(!s->budget--) { s->failed_pc=0x0c0c2048u; return 0; }
r[17]=(r[17]&~1u)|(((r[14]&r[14])==0)!=0);
goto P_0c0c204a;
P_0c0c204a: /* original 8b01, guest PC 0x0c0c204a */
if(!s->budget--) { s->failed_pc=0x0c0c204au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c2050; }
goto P_0c0c204c;
P_0c0c204c: /* original a0ed, guest PC 0x0c0c204c */
if(!s->budget--) { s->failed_pc=0x0c0c204cu; return 0; }
r[0]=0x00000000u;
goto P_0c0c222a;
P_0c0c204e: /* original e000, guest PC 0x0c0c204e */
if(!s->budget--) { s->failed_pc=0x0c0c204eu; return 0; }
r[0]=0x00000000u;
goto P_0c0c2050;
P_0c0c2050: /* original 63f2, guest PC 0x0c0c2050 */
if(!s->budget--) { s->failed_pc=0x0c0c2050u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c0c2052;
P_0c0c2052: /* original 2338, guest PC 0x0c0c2052 */
if(!s->budget--) { s->failed_pc=0x0c0c2052u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0c2054;
P_0c0c2054: /* original 8905, guest PC 0x0c0c2054 */
if(!s->budget--) { s->failed_pc=0x0c0c2054u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c2062; }
goto P_0c0c2056;
P_0c0c2056: /* original 64f2, guest PC 0x0c0c2056 */
if(!s->budget--) { s->failed_pc=0x0c0c2056u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c0c2058;
P_0c0c2058: /* original 65f2, guest PC 0x0c0c2058 */
if(!s->budget--) { s->failed_pc=0x0c0c2058u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0c205a;
P_0c0c205a: /* original 4429, guest PC 0x0c0c205a */
if(!s->budget--) { s->failed_pc=0x0c0c205au; return 0; }
r[4]>>=16;
goto P_0c0c205c;
P_0c0c205c: /* original 655f, guest PC 0x0c0c205c */
if(!s->budget--) { s->failed_pc=0x0c0c205cu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)r[5];
goto P_0c0c205e;
P_0c0c205e: /* original a007, guest PC 0x0c0c205e */
if(!s->budget--) { s->failed_pc=0x0c0c205eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)r[4];
goto P_0c0c2070;
P_0c0c2060: /* original 644f, guest PC 0x0c0c2060 */
if(!s->budget--) { s->failed_pc=0x0c0c2060u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)r[4];
goto P_0c0c2062;
P_0c0c2062: /* original e3f9, guest PC 0x0c0c2062 */
if(!s->budget--) { s->failed_pc=0x0c0c2062u; return 0; }
r[3]=0xfffffff9u;
goto P_0c0c2064;
P_0c0c2064: /* original 6593, guest PC 0x0c0c2064 */
if(!s->budget--) { s->failed_pc=0x0c0c2064u; return 0; }
r[5]=r[9];
goto P_0c0c2066;
P_0c0c2066: /* original 493d, guest PC 0x0c0c2066 */
if(!s->budget--) { s->failed_pc=0x0c0c2066u; return 0; }
r[9]=(r[3]&0x80000000u)?((r[3]&31u)?r[9]>>((-r[3])&31u):0):r[9]<<(r[3]&31u);
goto P_0c0c2068;
P_0c0c2068: /* original 6493, guest PC 0x0c0c2068 */
if(!s->budget--) { s->failed_pc=0x0c0c2068u; return 0; }
r[4]=r[9];
goto P_0c0c206a;
P_0c0c206a: /* original 4501, guest PC 0x0c0c206a */
if(!s->budget--) { s->failed_pc=0x0c0c206au; return 0; }
r[17]=(r[17]&~1u)|((r[5]&1)!=0);
r[5]>>=1;
goto P_0c0c206c;
P_0c0c206c: /* original 2489, guest PC 0x0c0c206c */
if(!s->budget--) { s->failed_pc=0x0c0c206cu; return 0; }
r[4]&=r[8];
goto P_0c0c206e;
P_0c0c206e: /* original 2589, guest PC 0x0c0c206e */
if(!s->budget--) { s->failed_pc=0x0c0c206eu; return 0; }
r[5]&=r[8];
goto P_0c0c2070;
P_0c0c2070: /* original 6053, guest PC 0x0c0c2070 */
if(!s->budget--) { s->failed_pc=0x0c0c2070u; return 0; }
r[0]=r[5];
goto P_0c0c2072;
P_0c0c2072: /* original 4508, guest PC 0x0c0c2072 */
if(!s->budget--) { s->failed_pc=0x0c0c2072u; return 0; }
r[5]<<=2;
goto P_0c0c2074;
P_0c0c2074: /* original 4500, guest PC 0x0c0c2074 */
if(!s->budget--) { s->failed_pc=0x0c0c2074u; return 0; }
r[17]=(r[17]&~1u)|((r[5]>>31)!=0);
r[5]<<=1;
goto P_0c0c2076;
P_0c0c2076: /* original 81e3, guest PC 0x0c0c2076 */
if(!s->budget--) { s->failed_pc=0x0c0c2076u; return 0; }
write(ram,r[14]+6,r[0],2);
goto P_0c0c2078;
P_0c0c2078: /* original 6043, guest PC 0x0c0c2078 */
if(!s->budget--) { s->failed_pc=0x0c0c2078u; return 0; }
r[0]=r[4];
goto P_0c0c207a;
P_0c0c207a: /* original 4408, guest PC 0x0c0c207a */
if(!s->budget--) { s->failed_pc=0x0c0c207au; return 0; }
r[4]<<=2;
goto P_0c0c207c;
P_0c0c207c: /* original 4400, guest PC 0x0c0c207c */
if(!s->budget--) { s->failed_pc=0x0c0c207cu; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c0c207e;
P_0c0c207e: /* original 81e4, guest PC 0x0c0c207e */
if(!s->budget--) { s->failed_pc=0x0c0c207eu; return 0; }
write(ram,r[14]+8,r[0],2);
goto P_0c0c2080;
P_0c0c2080: /* original 60c3, guest PC 0x0c0c2080 */
if(!s->budget--) { s->failed_pc=0x0c0c2080u; return 0; }
r[0]=r[12];
goto P_0c0c2082;
P_0c0c2082: /* original 81e1, guest PC 0x0c0c2082 */
if(!s->budget--) { s->failed_pc=0x0c0c2082u; return 0; }
write(ram,r[14]+2,r[0],2);
goto P_0c0c2084;
P_0c0c2084: /* original 455a, guest PC 0x0c0c2084 */
if(!s->budget--) { s->failed_pc=0x0c0c2084u; return 0; }
r[53]=r[5];
goto P_0c0c2086;
P_0c0c2086: /* original e010, guest PC 0x0c0c2086 */
if(!s->budget--) { s->failed_pc=0x0c0c2086u; return 0; }
r[0]=0x00000010u;
goto P_0c0c2088;
P_0c0c2088: /* original f32d, guest PC 0x0c0c2088 */
if(!s->budget--) { s->failed_pc=0x0c0c2088u; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c0c208a;
P_0c0c208a: /* original ff37, guest PC 0x0c0c208a */
if(!s->budget--) { s->failed_pc=0x0c0c208au; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0c208c;
P_0c0c208c: /* original e00c, guest PC 0x0c0c208c */
if(!s->budget--) { s->failed_pc=0x0c0c208cu; return 0; }
r[0]=0x0000000cu;
goto P_0c0c208e;
P_0c0c208e: /* original 445a, guest PC 0x0c0c208e */
if(!s->budget--) { s->failed_pc=0x0c0c208eu; return 0; }
r[53]=r[4];
goto P_0c0c2090;
P_0c0c2090: /* original f22d, guest PC 0x0c0c2090 */
if(!s->budget--) { s->failed_pc=0x0c0c2090u; return 0; }
fr[2]=vf3_fpu_float(r[53],r[18]);
goto P_0c0c2092;
P_0c0c2092: /* original ff27, guest PC 0x0c0c2092 */
if(!s->budget--) { s->failed_pc=0x0c0c2092u; return 0; }
vf3_matrix_store(s,ram,2,r[15]+r[0]);
goto P_0c0c2094;
P_0c0c2094: /* original d339, guest PC 0x0c0c2094 */
if(!s->budget--) { s->failed_pc=0x0c0c2094u; return 0; }
r[3]=read(ram,0x0c0c217cu,4);
goto P_0c0c2096;
P_0c0c2096: /* original 430b, guest PC 0x0c0c2096 */
if(!s->budget--) { s->failed_pc=0x0c0c2096u; return 0; }
target=r[3];
r[16]=0x0c0c209au;
r[4]=r[12];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c209au) { target=s->pc; goto dispatch; }
goto P_0c0c209a;
P_0c0c2098: /* original 64c3, guest PC 0x0c0c2098 */
if(!s->budget--) { s->failed_pc=0x0c0c2098u; return 0; }
r[4]=r[12];
goto P_0c0c209a;
P_0c0c209a: /* original 6c03, guest PC 0x0c0c209a */
if(!s->budget--) { s->failed_pc=0x0c0c209au; return 0; }
r[12]=r[0];
goto P_0c0c209c;
P_0c0c209c: /* original e004, guest PC 0x0c0c209c */
if(!s->budget--) { s->failed_pc=0x0c0c209cu; return 0; }
r[0]=0x00000004u;
goto P_0c0c209e;
P_0c0c209e: /* original fec6, guest PC 0x0c0c209e */
if(!s->budget--) { s->failed_pc=0x0c0c209eu; return 0; }
vf3_matrix_load(s,ram,14,r[12]+r[0]);
goto P_0c0c20a0;
P_0c0c20a0: /* original e008, guest PC 0x0c0c20a0 */
if(!s->budget--) { s->failed_pc=0x0c0c20a0u; return 0; }
r[0]=0x00000008u;
goto P_0c0c20a2;
P_0c0c20a2: /* original f3c6, guest PC 0x0c0c20a2 */
if(!s->budget--) { s->failed_pc=0x0c0c20a2u; return 0; }
vf3_matrix_load(s,ram,3,r[12]+r[0]);
goto P_0c0c20a4;
P_0c0c20a4: /* original e004, guest PC 0x0c0c20a4 */
if(!s->budget--) { s->failed_pc=0x0c0c20a4u; return 0; }
r[0]=0x00000004u;
goto P_0c0c20a6;
P_0c0c20a6: /* original fdc8, guest PC 0x0c0c20a6 */
if(!s->budget--) { s->failed_pc=0x0c0c20a6u; return 0; }
vf3_matrix_load(s,ram,13,r[12]);
goto P_0c0c20a8;
P_0c0c20a8: /* original 2bb8, guest PC 0x0c0c20a8 */
if(!s->budget--) { s->failed_pc=0x0c0c20a8u; return 0; }
r[17]=(r[17]&~1u)|(((r[11]&r[11])==0)!=0);
goto P_0c0c20aa;
P_0c0c20aa: /* original ff37, guest PC 0x0c0c20aa */
if(!s->budget--) { s->failed_pc=0x0c0c20aau; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0c20ac;
P_0c0c20ac: /* original e00c, guest PC 0x0c0c20ac */
if(!s->budget--) { s->failed_pc=0x0c0c20acu; return 0; }
r[0]=0x0000000cu;
goto P_0c0c20ae;
P_0c0c20ae: /* original ffc6, guest PC 0x0c0c20ae */
if(!s->budget--) { s->failed_pc=0x0c0c20aeu; return 0; }
vf3_matrix_load(s,ram,15,r[12]+r[0]);
goto P_0c0c20b0;
P_0c0c20b0: /* original e010, guest PC 0x0c0c20b0 */
if(!s->budget--) { s->failed_pc=0x0c0c20b0u; return 0; }
r[0]=0x00000010u;
goto P_0c0c20b2;
P_0c0c20b2: /* original f3c6, guest PC 0x0c0c20b2 */
if(!s->budget--) { s->failed_pc=0x0c0c20b2u; return 0; }
vf3_matrix_load(s,ram,3,r[12]+r[0]);
goto P_0c0c20b4;
P_0c0c20b4: /* original e008, guest PC 0x0c0c20b4 */
if(!s->budget--) { s->failed_pc=0x0c0c20b4u; return 0; }
r[0]=0x00000008u;
goto P_0c0c20b6;
P_0c0c20b6: /* original ff37, guest PC 0x0c0c20b6 */
if(!s->budget--) { s->failed_pc=0x0c0c20b6u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0c20b8;
P_0c0c20b8: /* original e014, guest PC 0x0c0c20b8 */
if(!s->budget--) { s->failed_pc=0x0c0c20b8u; return 0; }
r[0]=0x00000014u;
goto P_0c0c20ba;
P_0c0c20ba: /* original 8d43, guest PC 0x0c0c20ba */
if(!s->budget--) { s->failed_pc=0x0c0c20bau; return 0; }
cond=r[17]&1u;
vf3_matrix_load(s,ram,12,r[12]+r[0]);
if(cond) { goto P_0c0c2144; }
goto P_0c0c20be;
P_0c0c20bc: /* original fcc6, guest PC 0x0c0c20bc */
if(!s->budget--) { s->failed_pc=0x0c0c20bcu; return 0; }
vf3_matrix_load(s,ram,12,r[12]+r[0]);
goto P_0c0c20be;
P_0c0c20be: /* original 67b3, guest PC 0x0c0c20be */
if(!s->budget--) { s->failed_pc=0x0c0c20beu; return 0; }
r[7]=r[11];
goto P_0c0c20c0;
P_0c0c20c0: /* original 4729, guest PC 0x0c0c20c0 */
if(!s->budget--) { s->failed_pc=0x0c0c20c0u; return 0; }
r[7]>>=16;
goto P_0c0c20c2;
P_0c0c20c2: /* original 4719, guest PC 0x0c0c20c2 */
if(!s->budget--) { s->failed_pc=0x0c0c20c2u; return 0; }
r[7]>>=8;
goto P_0c0c20c4;
P_0c0c20c4: /* original 64b3, guest PC 0x0c0c20c4 */
if(!s->budget--) { s->failed_pc=0x0c0c20c4u; return 0; }
r[4]=r[11];
goto P_0c0c20c6;
P_0c0c20c6: /* original 677c, guest PC 0x0c0c20c6 */
if(!s->budget--) { s->failed_pc=0x0c0c20c6u; return 0; }
r[7]=r[7]&255u;
goto P_0c0c20c8;
P_0c0c20c8: /* original 66b3, guest PC 0x0c0c20c8 */
if(!s->budget--) { s->failed_pc=0x0c0c20c8u; return 0; }
r[6]=r[11];
goto P_0c0c20ca;
P_0c0c20ca: /* original 4708, guest PC 0x0c0c20ca */
if(!s->budget--) { s->failed_pc=0x0c0c20cau; return 0; }
r[7]<<=2;
goto P_0c0c20cc;
P_0c0c20cc: /* original 4700, guest PC 0x0c0c20cc */
if(!s->budget--) { s->failed_pc=0x0c0c20ccu; return 0; }
r[17]=(r[17]&~1u)|((r[7]>>31)!=0);
r[7]<<=1;
goto P_0c0c20ce;
P_0c0c20ce: /* original 475a, guest PC 0x0c0c20ce */
if(!s->budget--) { s->failed_pc=0x0c0c20ceu; return 0; }
r[53]=r[7];
goto P_0c0c20d0;
P_0c0c20d0: /* original 4629, guest PC 0x0c0c20d0 */
if(!s->budget--) { s->failed_pc=0x0c0c20d0u; return 0; }
r[6]>>=16;
goto P_0c0c20d2;
P_0c0c20d2: /* original 4419, guest PC 0x0c0c20d2 */
if(!s->budget--) { s->failed_pc=0x0c0c20d2u; return 0; }
r[4]>>=8;
goto P_0c0c20d4;
P_0c0c20d4: /* original 4711, guest PC 0x0c0c20d4 */
if(!s->budget--) { s->failed_pc=0x0c0c20d4u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[7]>=0)!=0);
goto P_0c0c20d6;
P_0c0c20d6: /* original 644c, guest PC 0x0c0c20d6 */
if(!s->budget--) { s->failed_pc=0x0c0c20d6u; return 0; }
r[4]=r[4]&255u;
goto P_0c0c20d8;
P_0c0c20d8: /* original 65bc, guest PC 0x0c0c20d8 */
if(!s->budget--) { s->failed_pc=0x0c0c20d8u; return 0; }
r[5]=r[11]&255u;
goto P_0c0c20da;
P_0c0c20da: /* original 666c, guest PC 0x0c0c20da */
if(!s->budget--) { s->failed_pc=0x0c0c20dau; return 0; }
r[6]=r[6]&255u;
goto P_0c0c20dc;
P_0c0c20dc: /* original 8d04, guest PC 0x0c0c20dc */
if(!s->budget--) { s->failed_pc=0x0c0c20dcu; return 0; }
cond=r[17]&1u;
fr[3]=vf3_fpu_float(r[53],r[18]);
if(cond) { goto P_0c0c20e8; }
goto P_0c0c20e0;
P_0c0c20de: /* original f32d, guest PC 0x0c0c20de */
if(!s->budget--) { s->failed_pc=0x0c0c20deu; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c0c20e0;
P_0c0c20e0: /* original d327, guest PC 0x0c0c20e0 */
if(!s->budget--) { s->failed_pc=0x0c0c20e0u; return 0; }
r[3]=read(ram,0x0c0c2180u,4);
goto P_0c0c20e2;
P_0c0c20e2: /* original 435a, guest PC 0x0c0c20e2 */
if(!s->budget--) { s->failed_pc=0x0c0c20e2u; return 0; }
r[53]=r[3];
goto P_0c0c20e4;
P_0c0c20e4: /* original f20d, guest PC 0x0c0c20e4 */
if(!s->budget--) { s->failed_pc=0x0c0c20e4u; return 0; }
fr[2]=r[53];
goto P_0c0c20e6;
P_0c0c20e6: /* original f320, guest PC 0x0c0c20e6 */
if(!s->budget--) { s->failed_pc=0x0c0c20e6u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[2],r[18],'+');
goto P_0c0c20e8;
P_0c0c20e8: /* original f2dc, guest PC 0x0c0c20e8 */
if(!s->budget--) { s->failed_pc=0x0c0c20e8u; return 0; }
vf3_matrix_move(s,2,13);
goto P_0c0c20ea;
P_0c0c20ea: /* original 4608, guest PC 0x0c0c20ea */
if(!s->budget--) { s->failed_pc=0x0c0c20eau; return 0; }
r[6]<<=2;
goto P_0c0c20ec;
P_0c0c20ec: /* original fd3c, guest PC 0x0c0c20ec */
if(!s->budget--) { s->failed_pc=0x0c0c20ecu; return 0; }
vf3_matrix_move(s,13,3);
goto P_0c0c20ee;
P_0c0c20ee: /* original 4600, guest PC 0x0c0c20ee */
if(!s->budget--) { s->failed_pc=0x0c0c20eeu; return 0; }
r[17]=(r[17]&~1u)|((r[6]>>31)!=0);
r[6]<<=1;
goto P_0c0c20f0;
P_0c0c20f0: /* original fd20, guest PC 0x0c0c20f0 */
if(!s->budget--) { s->failed_pc=0x0c0c20f0u; return 0; }
fr[13]=vf3_fpu_binary(fr[13],fr[2],r[18],'+');
goto P_0c0c20f2;
P_0c0c20f2: /* original 465a, guest PC 0x0c0c20f2 */
if(!s->budget--) { s->failed_pc=0x0c0c20f2u; return 0; }
r[53]=r[6];
goto P_0c0c20f4;
P_0c0c20f4: /* original 4611, guest PC 0x0c0c20f4 */
if(!s->budget--) { s->failed_pc=0x0c0c20f4u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[6]>=0)!=0);
goto P_0c0c20f6;
P_0c0c20f6: /* original 8d04, guest PC 0x0c0c20f6 */
if(!s->budget--) { s->failed_pc=0x0c0c20f6u; return 0; }
cond=r[17]&1u;
fr[3]=vf3_fpu_float(r[53],r[18]);
if(cond) { goto P_0c0c2102; }
goto P_0c0c20fa;
P_0c0c20f8: /* original f32d, guest PC 0x0c0c20f8 */
if(!s->budget--) { s->failed_pc=0x0c0c20f8u; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c0c20fa;
P_0c0c20fa: /* original d321, guest PC 0x0c0c20fa */
if(!s->budget--) { s->failed_pc=0x0c0c20fau; return 0; }
r[3]=read(ram,0x0c0c2180u,4);
goto P_0c0c20fc;
P_0c0c20fc: /* original 435a, guest PC 0x0c0c20fc */
if(!s->budget--) { s->failed_pc=0x0c0c20fcu; return 0; }
r[53]=r[3];
goto P_0c0c20fe;
P_0c0c20fe: /* original f20d, guest PC 0x0c0c20fe */
if(!s->budget--) { s->failed_pc=0x0c0c20feu; return 0; }
fr[2]=r[53];
goto P_0c0c2100;
P_0c0c2100: /* original f320, guest PC 0x0c0c2100 */
if(!s->budget--) { s->failed_pc=0x0c0c2100u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[2],r[18],'+');
goto P_0c0c2102;
P_0c0c2102: /* original 4408, guest PC 0x0c0c2102 */
if(!s->budget--) { s->failed_pc=0x0c0c2102u; return 0; }
r[4]<<=2;
goto P_0c0c2104;
P_0c0c2104: /* original f2ec, guest PC 0x0c0c2104 */
if(!s->budget--) { s->failed_pc=0x0c0c2104u; return 0; }
vf3_matrix_move(s,2,14);
goto P_0c0c2106;
P_0c0c2106: /* original 4400, guest PC 0x0c0c2106 */
if(!s->budget--) { s->failed_pc=0x0c0c2106u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c0c2108;
P_0c0c2108: /* original fe3c, guest PC 0x0c0c2108 */
if(!s->budget--) { s->failed_pc=0x0c0c2108u; return 0; }
vf3_matrix_move(s,14,3);
goto P_0c0c210a;
P_0c0c210a: /* original 445a, guest PC 0x0c0c210a */
if(!s->budget--) { s->failed_pc=0x0c0c210au; return 0; }
r[53]=r[4];
goto P_0c0c210c;
P_0c0c210c: /* original fe20, guest PC 0x0c0c210c */
if(!s->budget--) { s->failed_pc=0x0c0c210cu; return 0; }
fr[14]=vf3_fpu_binary(fr[14],fr[2],r[18],'+');
goto P_0c0c210e;
P_0c0c210e: /* original f38d, guest PC 0x0c0c210e */
if(!s->budget--) { s->failed_pc=0x0c0c210eu; return 0; }
fr[3]=0;
goto P_0c0c2110;
P_0c0c2110: /* original f22d, guest PC 0x0c0c2110 */
if(!s->budget--) { s->failed_pc=0x0c0c2110u; return 0; }
fr[2]=vf3_fpu_float(r[53],r[18]);
goto P_0c0c2112;
P_0c0c2112: /* original f325, guest PC 0x0c0c2112 */
if(!s->budget--) { s->failed_pc=0x0c0c2112u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[2]))!=0);
goto P_0c0c2114;
P_0c0c2114: /* original 8f05, guest PC 0x0c0c2114 */
if(!s->budget--) { s->failed_pc=0x0c0c2114u; return 0; }
cond=r[17]&1u;
vf3_matrix_move(s,4,2);
if(!cond) { goto P_0c0c2122; }
goto P_0c0c2118;
P_0c0c2116: /* original f42c, guest PC 0x0c0c2116 */
if(!s->budget--) { s->failed_pc=0x0c0c2116u; return 0; }
vf3_matrix_move(s,4,2);
goto P_0c0c2118;
P_0c0c2118: /* original c719, guest PC 0x0c0c2118 */
if(!s->budget--) { s->failed_pc=0x0c0c2118u; return 0; }
r[0]=0x0c0c2180u;
goto P_0c0c211a;
P_0c0c211a: /* original f34c, guest PC 0x0c0c211a */
if(!s->budget--) { s->failed_pc=0x0c0c211au; return 0; }
vf3_matrix_move(s,3,4);
goto P_0c0c211c;
P_0c0c211c: /* original f208, guest PC 0x0c0c211c */
if(!s->budget--) { s->failed_pc=0x0c0c211cu; return 0; }
vf3_matrix_load(s,ram,2,r[0]);
goto P_0c0c211e;
P_0c0c211e: /* original a001, guest PC 0x0c0c211e */
if(!s->budget--) { s->failed_pc=0x0c0c211eu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[2],r[18],'+');
goto P_0c0c2124;
P_0c0c2120: /* original f320, guest PC 0x0c0c2120 */
if(!s->budget--) { s->failed_pc=0x0c0c2120u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[2],r[18],'+');
goto P_0c0c2122;
P_0c0c2122: /* original f34c, guest PC 0x0c0c2122 */
if(!s->budget--) { s->failed_pc=0x0c0c2122u; return 0; }
vf3_matrix_move(s,3,4);
goto P_0c0c2124;
P_0c0c2124: /* original 4508, guest PC 0x0c0c2124 */
if(!s->budget--) { s->failed_pc=0x0c0c2124u; return 0; }
r[5]<<=2;
goto P_0c0c2126;
P_0c0c2126: /* original 4500, guest PC 0x0c0c2126 */
if(!s->budget--) { s->failed_pc=0x0c0c2126u; return 0; }
r[17]=(r[17]&~1u)|((r[5]>>31)!=0);
r[5]<<=1;
goto P_0c0c2128;
P_0c0c2128: /* original e004, guest PC 0x0c0c2128 */
if(!s->budget--) { s->failed_pc=0x0c0c2128u; return 0; }
r[0]=0x00000004u;
goto P_0c0c212a;
P_0c0c212a: /* original ff37, guest PC 0x0c0c212a */
if(!s->budget--) { s->failed_pc=0x0c0c212au; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0c212c;
P_0c0c212c: /* original 455a, guest PC 0x0c0c212c */
if(!s->budget--) { s->failed_pc=0x0c0c212cu; return 0; }
r[53]=r[5];
goto P_0c0c212e;
P_0c0c212e: /* original f18d, guest PC 0x0c0c212e */
if(!s->budget--) { s->failed_pc=0x0c0c212eu; return 0; }
fr[1]=0;
goto P_0c0c2130;
P_0c0c2130: /* original f22d, guest PC 0x0c0c2130 */
if(!s->budget--) { s->failed_pc=0x0c0c2130u; return 0; }
fr[2]=vf3_fpu_float(r[53],r[18]);
goto P_0c0c2132;
P_0c0c2132: /* original f125, guest PC 0x0c0c2132 */
if(!s->budget--) { s->failed_pc=0x0c0c2132u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[1])>as_float(fr[2]))!=0);
goto P_0c0c2134;
P_0c0c2134: /* original 8f05, guest PC 0x0c0c2134 */
if(!s->budget--) { s->failed_pc=0x0c0c2134u; return 0; }
cond=r[17]&1u;
vf3_matrix_move(s,4,2);
if(!cond) { goto P_0c0c2142; }
goto P_0c0c2138;
P_0c0c2136: /* original f42c, guest PC 0x0c0c2136 */
if(!s->budget--) { s->failed_pc=0x0c0c2136u; return 0; }
vf3_matrix_move(s,4,2);
goto P_0c0c2138;
P_0c0c2138: /* original c711, guest PC 0x0c0c2138 */
if(!s->budget--) { s->failed_pc=0x0c0c2138u; return 0; }
r[0]=0x0c0c2180u;
goto P_0c0c213a;
P_0c0c213a: /* original ff4c, guest PC 0x0c0c213a */
if(!s->budget--) { s->failed_pc=0x0c0c213au; return 0; }
vf3_matrix_move(s,15,4);
goto P_0c0c213c;
P_0c0c213c: /* original f208, guest PC 0x0c0c213c */
if(!s->budget--) { s->failed_pc=0x0c0c213cu; return 0; }
vf3_matrix_load(s,ram,2,r[0]);
goto P_0c0c213e;
P_0c0c213e: /* original a001, guest PC 0x0c0c213e */
if(!s->budget--) { s->failed_pc=0x0c0c213eu; return 0; }
fr[15]=vf3_fpu_binary(fr[15],fr[2],r[18],'+');
goto P_0c0c2144;
P_0c0c2140: /* original ff20, guest PC 0x0c0c2140 */
if(!s->budget--) { s->failed_pc=0x0c0c2140u; return 0; }
fr[15]=vf3_fpu_binary(fr[15],fr[2],r[18],'+');
goto P_0c0c2142;
P_0c0c2142: /* original ff4c, guest PC 0x0c0c2142 */
if(!s->budget--) { s->failed_pc=0x0c0c2142u; return 0; }
vf3_matrix_move(s,15,4);
goto P_0c0c2144;
P_0c0c2144: /* original e004, guest PC 0x0c0c2144 */
if(!s->budget--) { s->failed_pc=0x0c0c2144u; return 0; }
r[0]=0x00000004u;
goto P_0c0c2146;
P_0c0c2146: /* original f3f6, guest PC 0x0c0c2146 */
if(!s->budget--) { s->failed_pc=0x0c0c2146u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0c2148;
P_0c0c2148: /* original e340, guest PC 0x0c0c2148 */
if(!s->budget--) { s->failed_pc=0x0c0c2148u; return 0; }
r[3]=0x00000040u;
goto P_0c0c214a;
P_0c0c214a: /* original f33d, guest PC 0x0c0c214a */
if(!s->budget--) { s->failed_pc=0x0c0c214au; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c0c214c;
P_0c0c214c: /* original 005a, guest PC 0x0c0c214c */
if(!s->budget--) { s->failed_pc=0x0c0c214cu; return 0; }
r[0]=r[53];
goto P_0c0c214e;
P_0c0c214e: /* original ff3d, guest PC 0x0c0c214e */
if(!s->budget--) { s->failed_pc=0x0c0c214eu; return 0; }
r[53]=truncate_float(fr[15]);
goto P_0c0c2150;
P_0c0c2150: /* original 600d, guest PC 0x0c0c2150 */
if(!s->budget--) { s->failed_pc=0x0c0c2150u; return 0; }
r[0]=r[0]&65535u;
goto P_0c0c2152;
P_0c0c2152: /* original 4009, guest PC 0x0c0c2152 */
if(!s->budget--) { s->failed_pc=0x0c0c2152u; return 0; }
r[0]>>=2;
goto P_0c0c2154;
P_0c0c2154: /* original 4001, guest PC 0x0c0c2154 */
if(!s->budget--) { s->failed_pc=0x0c0c2154u; return 0; }
r[17]=(r[17]&~1u)|((r[0]&1)!=0);
r[0]>>=1;
goto P_0c0c2156;
P_0c0c2156: /* original 81e5, guest PC 0x0c0c2156 */
if(!s->budget--) { s->failed_pc=0x0c0c2156u; return 0; }
write(ram,r[14]+10,r[0],2);
goto P_0c0c2158;
P_0c0c2158: /* original 005a, guest PC 0x0c0c2158 */
if(!s->budget--) { s->failed_pc=0x0c0c2158u; return 0; }
r[0]=r[53];
goto P_0c0c215a;
P_0c0c215a: /* original 600d, guest PC 0x0c0c215a */
if(!s->budget--) { s->failed_pc=0x0c0c215au; return 0; }
r[0]=r[0]&65535u;
goto P_0c0c215c;
P_0c0c215c: /* original 4009, guest PC 0x0c0c215c */
if(!s->budget--) { s->failed_pc=0x0c0c215cu; return 0; }
r[0]>>=2;
goto P_0c0c215e;
P_0c0c215e: /* original 4001, guest PC 0x0c0c215e */
if(!s->budget--) { s->failed_pc=0x0c0c215eu; return 0; }
r[17]=(r[17]&~1u)|((r[0]&1)!=0);
r[0]>>=1;
goto P_0c0c2160;
P_0c0c2160: /* original 81e6, guest PC 0x0c0c2160 */
if(!s->budget--) { s->failed_pc=0x0c0c2160u; return 0; }
write(ram,r[14]+12,r[0],2);
goto P_0c0c2162;
P_0c0c2162: /* original e008, guest PC 0x0c0c2162 */
if(!s->budget--) { s->failed_pc=0x0c0c2162u; return 0; }
r[0]=0x00000008u;
goto P_0c0c2164;
P_0c0c2164: /* original f3f6, guest PC 0x0c0c2164 */
if(!s->budget--) { s->failed_pc=0x0c0c2164u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0c2166;
P_0c0c2166: /* original e004, guest PC 0x0c0c2166 */
if(!s->budget--) { s->failed_pc=0x0c0c2166u; return 0; }
r[0]=0x00000004u;
goto P_0c0c2168;
P_0c0c2168: /* original f6f6, guest PC 0x0c0c2168 */
if(!s->budget--) { s->failed_pc=0x0c0c2168u; return 0; }
vf3_matrix_load(s,ram,6,r[15]+r[0]);
goto P_0c0c216a;
P_0c0c216a: /* original 23d8, guest PC 0x0c0c216a */
if(!s->budget--) { s->failed_pc=0x0c0c216au; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[13])==0)!=0);
goto P_0c0c216c;
P_0c0c216c: /* original 8d0a, guest PC 0x0c0c216c */
if(!s->budget--) { s->failed_pc=0x0c0c216cu; return 0; }
cond=r[17]&1u;
fr[6]=vf3_fpu_binary(fr[6],fr[3],r[18],'*');
if(cond) { goto P_0c0c2184; }
goto P_0c0c2170;
P_0c0c216e: /* original f632, guest PC 0x0c0c216e */
if(!s->budget--) { s->failed_pc=0x0c0c216eu; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[3],r[18],'*');
goto P_0c0c2170;
P_0c0c2170: /* original a00d, guest PC 0x0c0c2170 */
if(!s->budget--) { s->failed_pc=0x0c0c2170u; return 0; }
vf3_matrix_move(s,7,15);
goto P_0c0c218e;
P_0c0c2172: /* original f7fc, guest PC 0x0c0c2172 */
if(!s->budget--) { s->failed_pc=0x0c0c2172u; return 0; }
vf3_matrix_move(s,7,15);
return vf3_matrix_family(0x0c0c2174u,s,ram);
P_0c0c2184: /* original c731, guest PC 0x0c0c2184 */
if(!s->budget--) { s->failed_pc=0x0c0c2184u; return 0; }
r[0]=0x0c0c224cu;
goto P_0c0c2186;
P_0c0c2186: /* original f1fc, guest PC 0x0c0c2186 */
if(!s->budget--) { s->failed_pc=0x0c0c2186u; return 0; }
vf3_matrix_move(s,1,15);
goto P_0c0c2188;
P_0c0c2188: /* original f208, guest PC 0x0c0c2188 */
if(!s->budget--) { s->failed_pc=0x0c0c2188u; return 0; }
vf3_matrix_load(s,ram,2,r[0]);
goto P_0c0c218a;
P_0c0c218a: /* original f120, guest PC 0x0c0c218a */
if(!s->budget--) { s->failed_pc=0x0c0c218au; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[2],r[18],'+');
goto P_0c0c218c;
P_0c0c218c: /* original f71c, guest PC 0x0c0c218c */
if(!s->budget--) { s->failed_pc=0x0c0c218cu; return 0; }
vf3_matrix_move(s,7,1);
goto P_0c0c218e;
P_0c0c218e: /* original e026, guest PC 0x0c0c218e */
if(!s->budget--) { s->failed_pc=0x0c0c218eu; return 0; }
r[0]=0x00000026u;
goto P_0c0c2190;
P_0c0c2190: /* original f7c2, guest PC 0x0c0c2190 */
if(!s->budget--) { s->failed_pc=0x0c0c2190u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[12],r[18],'*');
goto P_0c0c2192;
P_0c0c2192: /* original 03ad, guest PC 0x0c0c2192 */
if(!s->budget--) { s->failed_pc=0x0c0c2192u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[10]+r[0],2);
goto P_0c0c2194;
P_0c0c2194: /* original 64e3, guest PC 0x0c0c2194 */
if(!s->budget--) { s->failed_pc=0x0c0c2194u; return 0; }
r[4]=r[14];
goto P_0c0c2196;
P_0c0c2196: /* original d02e, guest PC 0x0c0c2196 */
if(!s->budget--) { s->failed_pc=0x0c0c2196u; return 0; }
r[0]=read(ram,0x0c0c2250u,4);
goto P_0c0c2198;
P_0c0c2198: /* original 633d, guest PC 0x0c0c2198 */
if(!s->budget--) { s->failed_pc=0x0c0c2198u; return 0; }
r[3]=r[3]&65535u;
goto P_0c0c219a;
P_0c0c219a: /* original 4308, guest PC 0x0c0c219a */
if(!s->budget--) { s->failed_pc=0x0c0c219au; return 0; }
r[3]<<=2;
goto P_0c0c219c;
P_0c0c219c: /* original f836, guest PC 0x0c0c219c */
if(!s->budget--) { s->failed_pc=0x0c0c219cu; return 0; }
vf3_matrix_load(s,ram,8,r[3]+r[0]);
goto P_0c0c219e;
P_0c0c219e: /* original e00c, guest PC 0x0c0c219e */
if(!s->budget--) { s->failed_pc=0x0c0c219eu; return 0; }
r[0]=0x0000000cu;
goto P_0c0c21a0;
P_0c0c21a0: /* original f5f6, guest PC 0x0c0c21a0 */
if(!s->budget--) { s->failed_pc=0x0c0c21a0u; return 0; }
vf3_matrix_load(s,ram,5,r[15]+r[0]);
goto P_0c0c21a2;
P_0c0c21a2: /* original e010, guest PC 0x0c0c21a2 */
if(!s->budget--) { s->failed_pc=0x0c0c21a2u; return 0; }
r[0]=0x00000010u;
goto P_0c0c21a4;
P_0c0c21a4: /* original d32b, guest PC 0x0c0c21a4 */
if(!s->budget--) { s->failed_pc=0x0c0c21a4u; return 0; }
r[3]=read(ram,0x0c0c2254u,4);
goto P_0c0c21a6;
P_0c0c21a6: /* original f4f6, guest PC 0x0c0c21a6 */
if(!s->budget--) { s->failed_pc=0x0c0c21a6u; return 0; }
vf3_matrix_load(s,ram,4,r[15]+r[0]);
goto P_0c0c21a8;
P_0c0c21a8: /* original 430b, guest PC 0x0c0c21a8 */
if(!s->budget--) { s->failed_pc=0x0c0c21a8u; return 0; }
target=r[3];
r[16]=0x0c0c21acu;
r[4]+=0x00000010u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c21acu) { target=s->pc; goto dispatch; }
goto P_0c0c21ac;
P_0c0c21aa: /* original 7410, guest PC 0x0c0c21aa */
if(!s->budget--) { s->failed_pc=0x0c0c21aau; return 0; }
r[4]+=0x00000010u;
goto P_0c0c21ac;
P_0c0c21ac: /* original e008, guest PC 0x0c0c21ac */
if(!s->budget--) { s->failed_pc=0x0c0c21acu; return 0; }
r[0]=0x00000008u;
goto P_0c0c21ae;
P_0c0c21ae: /* original d32a, guest PC 0x0c0c21ae */
if(!s->budget--) { s->failed_pc=0x0c0c21aeu; return 0; }
r[3]=read(ram,0x0c0c2258u,4);
goto P_0c0c21b0;
P_0c0c21b0: /* original f8f6, guest PC 0x0c0c21b0 */
if(!s->budget--) { s->failed_pc=0x0c0c21b0u; return 0; }
vf3_matrix_load(s,ram,8,r[15]+r[0]);
goto P_0c0c21b2;
P_0c0c21b2: /* original e004, guest PC 0x0c0c21b2 */
if(!s->budget--) { s->failed_pc=0x0c0c21b2u; return 0; }
r[0]=0x00000004u;
goto P_0c0c21b4;
P_0c0c21b4: /* original f6f6, guest PC 0x0c0c21b4 */
if(!s->budget--) { s->failed_pc=0x0c0c21b4u; return 0; }
vf3_matrix_load(s,ram,6,r[15]+r[0]);
goto P_0c0c21b6;
P_0c0c21b6: /* original 64e3, guest PC 0x0c0c21b6 */
if(!s->budget--) { s->failed_pc=0x0c0c21b6u; return 0; }
r[4]=r[14];
goto P_0c0c21b8;
P_0c0c21b8: /* original f4dc, guest PC 0x0c0c21b8 */
if(!s->budget--) { s->failed_pc=0x0c0c21b8u; return 0; }
vf3_matrix_move(s,4,13);
goto P_0c0c21ba;
P_0c0c21ba: /* original f7fc, guest PC 0x0c0c21ba */
if(!s->budget--) { s->failed_pc=0x0c0c21bau; return 0; }
vf3_matrix_move(s,7,15);
goto P_0c0c21bc;
P_0c0c21bc: /* original f9cc, guest PC 0x0c0c21bc */
if(!s->budget--) { s->failed_pc=0x0c0c21bcu; return 0; }
vf3_matrix_move(s,9,12);
goto P_0c0c21be;
P_0c0c21be: /* original f5ec, guest PC 0x0c0c21be */
if(!s->budget--) { s->failed_pc=0x0c0c21beu; return 0; }
vf3_matrix_move(s,5,14);
goto P_0c0c21c0;
P_0c0c21c0: /* original 430b, guest PC 0x0c0c21c0 */
if(!s->budget--) { s->failed_pc=0x0c0c21c0u; return 0; }
target=r[3];
r[16]=0x0c0c21c4u;
r[4]+=0x00000010u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c21c4u) { target=s->pc; goto dispatch; }
goto P_0c0c21c4;
P_0c0c21c2: /* original 7410, guest PC 0x0c0c21c2 */
if(!s->budget--) { s->failed_pc=0x0c0c21c2u; return 0; }
r[4]+=0x00000010u;
goto P_0c0c21c4;
P_0c0c21c4: /* original 50c8, guest PC 0x0c0c21c4 */
if(!s->budget--) { s->failed_pc=0x0c0c21c4u; return 0; }
r[0]=read(ram,r[12]+32,4);
goto P_0c0c21c6;
P_0c0c21c6: /* original e501, guest PC 0x0c0c21c6 */
if(!s->budget--) { s->failed_pc=0x0c0c21c6u; return 0; }
r[5]=0x00000001u;
goto P_0c0c21c8;
P_0c0c21c8: /* original d124, guest PC 0x0c0c21c8 */
if(!s->budget--) { s->failed_pc=0x0c0c21c8u; return 0; }
r[1]=read(ram,0x0c0c225cu,4);
goto P_0c0c21ca;
P_0c0c21ca: /* original 4000, guest PC 0x0c0c21ca */
if(!s->budget--) { s->failed_pc=0x0c0c21cau; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c0c21cc;
P_0c0c21cc: /* original 001d, guest PC 0x0c0c21cc */
if(!s->budget--) { s->failed_pc=0x0c0c21ccu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[1]+r[0],2);
goto P_0c0c21ce;
P_0c0c21ce: /* original 25d8, guest PC 0x0c0c21ce */
if(!s->budget--) { s->failed_pc=0x0c0c21ceu; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[13])==0)!=0);
goto P_0c0c21d0;
P_0c0c21d0: /* original 81e2, guest PC 0x0c0c21d0 */
if(!s->budget--) { s->failed_pc=0x0c0c21d0u; return 0; }
write(ram,r[14]+4,r[0],2);
goto P_0c0c21d2;
P_0c0c21d2: /* original 600d, guest PC 0x0c0c21d2 */
if(!s->budget--) { s->failed_pc=0x0c0c21d2u; return 0; }
r[0]=r[0]&65535u;
goto P_0c0c21d4;
P_0c0c21d4: /* original 1e04, guest PC 0x0c0c21d4 */
if(!s->budget--) { s->failed_pc=0x0c0c21d4u; return 0; }
write(ram,r[14]+16,r[0],4);
goto P_0c0c21d6;
P_0c0c21d6: /* original e040, guest PC 0x0c0c21d6 */
if(!s->budget--) { s->failed_pc=0x0c0c21d6u; return 0; }
r[0]=0x00000040u;
goto P_0c0c21d8;
P_0c0c21d8: /* original f39d, guest PC 0x0c0c21d8 */
if(!s->budget--) { s->failed_pc=0x0c0c21d8u; return 0; }
fr[3]=0x3f800000u;
goto P_0c0c21da;
P_0c0c21da: /* original fe37, guest PC 0x0c0c21da */
if(!s->budget--) { s->failed_pc=0x0c0c21dau; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0c21dc;
P_0c0c21dc: /* original 9433, guest PC 0x0c0c21dc */
if(!s->budget--) { s->failed_pc=0x0c0c21dcu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c2246u,2);
goto P_0c0c21de;
P_0c0c21de: /* original 8d04, guest PC 0x0c0c21de */
if(!s->budget--) { s->failed_pc=0x0c0c21deu; return 0; }
cond=r[17]&1u;
write(ram,r[14],r[5],2);
if(cond) { goto P_0c0c21ea; }
goto P_0c0c21e2;
P_0c0c21e0: /* original 2e51, guest PC 0x0c0c21e0 */
if(!s->budget--) { s->failed_pc=0x0c0c21e0u; return 0; }
write(ram,r[14],r[5],2);
goto P_0c0c21e2;
P_0c0c21e2: /* original 60e1, guest PC 0x0c0c21e2 */
if(!s->budget--) { s->failed_pc=0x0c0c21e2u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[14],2);
r[0]=tmp;
goto P_0c0c21e4;
P_0c0c21e4: /* original cb02, guest PC 0x0c0c21e4 */
if(!s->budget--) { s->failed_pc=0x0c0c21e4u; return 0; }
r[0]|=2u;
goto P_0c0c21e6;
P_0c0c21e6: /* original 2e01, guest PC 0x0c0c21e6 */
if(!s->budget--) { s->failed_pc=0x0c0c21e6u; return 0; }
write(ram,r[14],r[0],2);
goto P_0c0c21e8;
P_0c0c21e8: /* original 942e, guest PC 0x0c0c21e8 */
if(!s->budget--) { s->failed_pc=0x0c0c21e8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c2248u,2);
goto P_0c0c21ea;
P_0c0c21ea: /* original e202, guest PC 0x0c0c21ea */
if(!s->budget--) { s->failed_pc=0x0c0c21eau; return 0; }
r[2]=0x00000002u;
goto P_0c0c21ec;
P_0c0c21ec: /* original 22d8, guest PC 0x0c0c21ec */
if(!s->budget--) { s->failed_pc=0x0c0c21ecu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[13])==0)!=0);
goto P_0c0c21ee;
P_0c0c21ee: /* original 8d03, guest PC 0x0c0c21ee */
if(!s->budget--) { s->failed_pc=0x0c0c21eeu; return 0; }
cond=r[17]&1u;
r[2]=0x00000004u;
if(cond) { goto P_0c0c21f8; }
goto P_0c0c21f2;
P_0c0c21f0: /* original e204, guest PC 0x0c0c21f0 */
if(!s->budget--) { s->failed_pc=0x0c0c21f0u; return 0; }
r[2]=0x00000004u;
goto P_0c0c21f2;
P_0c0c21f2: /* original 60e1, guest PC 0x0c0c21f2 */
if(!s->budget--) { s->failed_pc=0x0c0c21f2u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[14],2);
r[0]=tmp;
goto P_0c0c21f4;
P_0c0c21f4: /* original cb04, guest PC 0x0c0c21f4 */
if(!s->budget--) { s->failed_pc=0x0c0c21f4u; return 0; }
r[0]|=4u;
goto P_0c0c21f6;
P_0c0c21f6: /* original 2e01, guest PC 0x0c0c21f6 */
if(!s->budget--) { s->failed_pc=0x0c0c21f6u; return 0; }
write(ram,r[14],r[0],2);
goto P_0c0c21f8;
P_0c0c21f8: /* original 22d8, guest PC 0x0c0c21f8 */
if(!s->budget--) { s->failed_pc=0x0c0c21f8u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[13])==0)!=0);
goto P_0c0c21fa;
P_0c0c21fa: /* original 8d03, guest PC 0x0c0c21fa */
if(!s->budget--) { s->failed_pc=0x0c0c21fau; return 0; }
cond=r[17]&1u;
r[2]=0x00000008u;
if(cond) { goto P_0c0c2204; }
goto P_0c0c21fe;
P_0c0c21fc: /* original e208, guest PC 0x0c0c21fc */
if(!s->budget--) { s->failed_pc=0x0c0c21fcu; return 0; }
r[2]=0x00000008u;
goto P_0c0c21fe;
P_0c0c21fe: /* original 60e1, guest PC 0x0c0c21fe */
if(!s->budget--) { s->failed_pc=0x0c0c21feu; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[14],2);
r[0]=tmp;
goto P_0c0c2200;
P_0c0c2200: /* original cb08, guest PC 0x0c0c2200 */
if(!s->budget--) { s->failed_pc=0x0c0c2200u; return 0; }
r[0]|=8u;
goto P_0c0c2202;
P_0c0c2202: /* original 2e01, guest PC 0x0c0c2202 */
if(!s->budget--) { s->failed_pc=0x0c0c2202u; return 0; }
write(ram,r[14],r[0],2);
goto P_0c0c2204;
P_0c0c2204: /* original 22d8, guest PC 0x0c0c2204 */
if(!s->budget--) { s->failed_pc=0x0c0c2204u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[13])==0)!=0);
goto P_0c0c2206;
P_0c0c2206: /* original 8901, guest PC 0x0c0c2206 */
if(!s->budget--) { s->failed_pc=0x0c0c2206u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c220c; }
goto P_0c0c2208;
P_0c0c2208: /* original 911f, guest PC 0x0c0c2208 */
if(!s->budget--) { s->failed_pc=0x0c0c2208u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c224au,2);
goto P_0c0c220a;
P_0c0c220a: /* original 241b, guest PC 0x0c0c220a */
if(!s->budget--) { s->failed_pc=0x0c0c220au; return 0; }
r[4]|=r[1];
goto P_0c0c220c;
P_0c0c220c: /* original e310, guest PC 0x0c0c220c */
if(!s->budget--) { s->failed_pc=0x0c0c220cu; return 0; }
r[3]=0x00000010u;
goto P_0c0c220e;
P_0c0c220e: /* original 23d8, guest PC 0x0c0c220e */
if(!s->budget--) { s->failed_pc=0x0c0c220eu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[13])==0)!=0);
goto P_0c0c2210;
P_0c0c2210: /* original 8d03, guest PC 0x0c0c2210 */
if(!s->budget--) { s->failed_pc=0x0c0c2210u; return 0; }
cond=r[17]&1u;
r[3]=0x00000020u;
if(cond) { goto P_0c0c221a; }
goto P_0c0c2214;
P_0c0c2212: /* original e320, guest PC 0x0c0c2212 */
if(!s->budget--) { s->failed_pc=0x0c0c2212u; return 0; }
r[3]=0x00000020u;
goto P_0c0c2214;
P_0c0c2214: /* original 60e1, guest PC 0x0c0c2214 */
if(!s->budget--) { s->failed_pc=0x0c0c2214u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[14],2);
r[0]=tmp;
goto P_0c0c2216;
P_0c0c2216: /* original cb10, guest PC 0x0c0c2216 */
if(!s->budget--) { s->failed_pc=0x0c0c2216u; return 0; }
r[0]|=16u;
goto P_0c0c2218;
P_0c0c2218: /* original 2e01, guest PC 0x0c0c2218 */
if(!s->budget--) { s->failed_pc=0x0c0c2218u; return 0; }
write(ram,r[14],r[0],2);
goto P_0c0c221a;
P_0c0c221a: /* original 2d38, guest PC 0x0c0c221a */
if(!s->budget--) { s->failed_pc=0x0c0c221au; return 0; }
r[17]=(r[17]&~1u)|(((r[13]&r[3])==0)!=0);
goto P_0c0c221c;
P_0c0c221c: /* original 8902, guest PC 0x0c0c221c */
if(!s->budget--) { s->failed_pc=0x0c0c221cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c2224; }
goto P_0c0c221e;
P_0c0c221e: /* original 61e1, guest PC 0x0c0c221e */
if(!s->budget--) { s->failed_pc=0x0c0c221eu; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[14],2);
r[1]=tmp;
goto P_0c0c2220;
P_0c0c2220: /* original 213b, guest PC 0x0c0c2220 */
if(!s->budget--) { s->failed_pc=0x0c0c2220u; return 0; }
r[1]|=r[3];
goto P_0c0c2222;
P_0c0c2222: /* original 2e11, guest PC 0x0c0c2222 */
if(!s->budget--) { s->failed_pc=0x0c0c2222u; return 0; }
write(ram,r[14],r[1],2);
goto P_0c0c2224;
P_0c0c2224: /* original 60e3, guest PC 0x0c0c2224 */
if(!s->budget--) { s->failed_pc=0x0c0c2224u; return 0; }
r[0]=r[14];
goto P_0c0c2226;
P_0c0c2226: /* original 7010, guest PC 0x0c0c2226 */
if(!s->budget--) { s->failed_pc=0x0c0c2226u; return 0; }
r[0]+=0x00000010u;
goto P_0c0c2228;
P_0c0c2228: /* original 1e4f, guest PC 0x0c0c2228 */
if(!s->budget--) { s->failed_pc=0x0c0c2228u; return 0; }
write(ram,r[14]+60,r[4],4);
goto P_0c0c222a;
P_0c0c222a: /* original 7f14, guest PC 0x0c0c222a */
if(!s->budget--) { s->failed_pc=0x0c0c222au; return 0; }
r[15]+=0x00000014u;
goto P_0c0c222c;
P_0c0c222c: /* original 4f26, guest PC 0x0c0c222c */
if(!s->budget--) { s->failed_pc=0x0c0c222cu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c222e;
P_0c0c222e: /* original fcf9, guest PC 0x0c0c222e */
if(!s->budget--) { s->failed_pc=0x0c0c222eu; return 0; }
vf3_matrix_load(s,ram,12,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0c2230;
P_0c0c2230: /* original fdf9, guest PC 0x0c0c2230 */
if(!s->budget--) { s->failed_pc=0x0c0c2230u; return 0; }
vf3_matrix_load(s,ram,13,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0c2232;
P_0c0c2232: /* original fef9, guest PC 0x0c0c2232 */
if(!s->budget--) { s->failed_pc=0x0c0c2232u; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0c2234;
P_0c0c2234: /* original fff9, guest PC 0x0c0c2234 */
if(!s->budget--) { s->failed_pc=0x0c0c2234u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0c2236;
P_0c0c2236: /* original 68f6, guest PC 0x0c0c2236 */
if(!s->budget--) { s->failed_pc=0x0c0c2236u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c0c2238;
P_0c0c2238: /* original 69f6, guest PC 0x0c0c2238 */
if(!s->budget--) { s->failed_pc=0x0c0c2238u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0c223a;
P_0c0c223a: /* original 6af6, guest PC 0x0c0c223a */
if(!s->budget--) { s->failed_pc=0x0c0c223au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0c223c;
P_0c0c223c: /* original 6bf6, guest PC 0x0c0c223c */
if(!s->budget--) { s->failed_pc=0x0c0c223cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0c223e;
P_0c0c223e: /* original 6cf6, guest PC 0x0c0c223e */
if(!s->budget--) { s->failed_pc=0x0c0c223eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0c2240;
P_0c0c2240: /* original 6df6, guest PC 0x0c0c2240 */
if(!s->budget--) { s->failed_pc=0x0c0c2240u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0c2242;
P_0c0c2242: /* original 000b, guest PC 0x0c0c2242 */
if(!s->budget--) { s->failed_pc=0x0c0c2242u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0c2244: /* original 6ef6, guest PC 0x0c0c2244 */
if(!s->budget--) { s->failed_pc=0x0c0c2244u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0c2246u,s,ram);
P_0c0c6742: /* original 9049, guest PC 0x0c0c6742 */
if(!s->budget--) { s->failed_pc=0x0c0c6742u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c67d8u,2);
goto P_0c0c6744;
P_0c0c6744: /* original d426, guest PC 0x0c0c6744 */
if(!s->budget--) { s->failed_pc=0x0c0c6744u; return 0; }
r[4]=read(ram,0x0c0c67e0u,4);
goto P_0c0c6746;
P_0c0c6746: /* original 000b, guest PC 0x0c0c6746 */
if(!s->budget--) { s->failed_pc=0x0c0c6746u; return 0; }
target=r[16];
r[0]=read(ram,r[4]+r[0],4);
s->pc=target; return ram->oob==0;
P_0c0c6748: /* original 004e, guest PC 0x0c0c6748 */
if(!s->budget--) { s->failed_pc=0x0c0c6748u; return 0; }
r[0]=read(ram,r[4]+r[0],4);
return vf3_matrix_family(0x0c0c674au,s,ram);
unsupported: s->failed_pc=target; return 0;
}
static const uint32_t owned_pcs[]={
0x0c03b304u,0x0c03b306u,0x0c03b308u,0x0c03b30au,0x0c03b30cu,0x0c03b30eu,0x0c03b310u,0x0c03b312u,0x0c03b314u,0x0c03b316u,0x0c03b318u,0x0c03b31au,0x0c03b31cu,0x0c03b31eu,0x0c03b320u,0x0c03b322u,
0x0c03b324u,0x0c03b326u,0x0c03b328u,0x0c03b32au,0x0c03b32cu,0x0c03b32eu,0x0c03b330u,0x0c03b332u,0x0c03b334u,0x0c03b336u,0x0c03b338u,0x0c040378u,0x0c04037au,0x0c04037cu,0x0c04037eu,0x0c040380u,
0x0c040382u,0x0c040384u,0x0c040386u,0x0c040388u,0x0c04038au,0x0c04038cu,0x0c04038eu,0x0c040390u,0x0c040392u,0x0c040394u,0x0c040396u,0x0c040398u,0x0c04039au,0x0c04039cu,0x0c04039eu,0x0c0403a0u,
0x0c0403a2u,0x0c0403a4u,0x0c0403a6u,0x0c0403a8u,0x0c0403aau,0x0c0403acu,0x0c0403aeu,0x0c0403b0u,0x0c0403b2u,0x0c0403b4u,0x0c05e1b2u,0x0c05e1b4u,0x0c05e1b6u,0x0c05e1b8u,0x0c05e1bau,0x0c05e1bcu,
0x0c05e1beu,0x0c05e1c0u,0x0c060d14u,0x0c060d16u,0x0c060d18u,0x0c060d1au,0x0c060d1cu,0x0c066dc4u,0x0c066dc6u,0x0c066dc8u,0x0c066dcau,0x0c066dccu,0x0c066dceu,0x0c066dd0u,0x0c066dd2u,0x0c066dd4u,
0x0c066dd6u,0x0c066dd8u,0x0c066ddau,0x0c066ddcu,0x0c066ddeu,0x0c066de0u,0x0c066de2u,0x0c066de4u,0x0c066de6u,0x0c066de8u,0x0c066deau,0x0c066decu,0x0c066deeu,0x0c066df0u,0x0c066df2u,0x0c066df4u,
0x0c066df6u,0x0c066df8u,0x0c066dfau,0x0c066dfcu,0x0c066dfeu,0x0c066e00u,0x0c066e02u,0x0c066e04u,0x0c066e06u,0x0c066e08u,0x0c066e0au,0x0c066e0cu,0x0c066e0eu,0x0c066e10u,0x0c066e12u,0x0c066e14u,
0x0c066e16u,0x0c066e18u,0x0c066e1au,0x0c066e1cu,0x0c066e1eu,0x0c066e20u,0x0c066e22u,0x0c066e24u,0x0c066e26u,0x0c066e28u,0x0c066e2au,0x0c066e2cu,0x0c066e2eu,0x0c066e30u,0x0c066e32u,0x0c066e34u,
0x0c066e36u,0x0c066e38u,0x0c066e3au,0x0c066e3cu,0x0c066e3eu,0x0c066e40u,0x0c066e42u,0x0c066e44u,0x0c066e46u,0x0c066e78u,0x0c066e7au,0x0c066e7cu,0x0c066e7eu,0x0c066e80u,0x0c066e82u,0x0c066e84u,
0x0c066e86u,0x0c066e88u,0x0c066e8au,0x0c066e8cu,0x0c066e8eu,0x0c066e90u,0x0c066e92u,0x0c066e94u,0x0c066e96u,0x0c066e98u,0x0c066e9au,0x0c066e9cu,0x0c066e9eu,0x0c066ea0u,0x0c066ea2u,0x0c066ea4u,
0x0c066ea6u,0x0c066ea8u,0x0c066eaau,0x0c066eacu,0x0c066eaeu,0x0c066eb0u,0x0c066eb2u,0x0c066eb4u,0x0c066eb6u,0x0c066eb8u,0x0c066ebau,0x0c066ebcu,0x0c066ebeu,0x0c066ec0u,0x0c066ec2u,0x0c066ec4u,
0x0c066ec6u,0x0c066ec8u,0x0c066ecau,0x0c066eccu,0x0c066eceu,0x0c066ed0u,0x0c066ed2u,0x0c066ed4u,0x0c066ed6u,0x0c066ed8u,0x0c066edau,0x0c066edcu,0x0c066edeu,0x0c066ee0u,0x0c066ee2u,0x0c066ee4u,
0x0c066ee6u,0x0c066ee8u,0x0c066eeau,0x0c066eecu,0x0c066eeeu,0x0c066ef0u,0x0c066ef2u,0x0c066ef4u,0x0c066ef6u,0x0c066ef8u,0x0c066efau,0x0c066efcu,0x0c066efeu,0x0c066f00u,0x0c066f02u,0x0c066f04u,
0x0c066f06u,0x0c066f08u,0x0c066f0au,0x0c066f0cu,0x0c066f0eu,0x0c066f10u,0x0c066f12u,0x0c066f14u,0x0c066f16u,0x0c066f18u,0x0c066f1au,0x0c066f1cu,0x0c066f1eu,0x0c066f20u,0x0c066f22u,0x0c066f24u,
0x0c066f26u,0x0c066f28u,0x0c066f2au,0x0c066f2cu,0x0c066f2eu,0x0c066f30u,0x0c066f32u,0x0c066f34u,0x0c066f36u,0x0c066f38u,0x0c066f3au,0x0c066f3cu,0x0c066f3eu,0x0c066f40u,0x0c066f42u,0x0c066f44u,
0x0c066f46u,0x0c066f48u,0x0c066f4au,0x0c066f4cu,0x0c066f4eu,0x0c066f50u,0x0c066f52u,0x0c066f54u,0x0c066f56u,0x0c066f58u,0x0c066f5au,0x0c066f5cu,0x0c066f5eu,0x0c066f60u,0x0c066f62u,0x0c066f64u,
0x0c066f66u,0x0c066f68u,0x0c066f6au,0x0c066f6cu,0x0c066f6eu,0x0c066f70u,0x0c066f72u,0x0c066f74u,0x0c066f76u,0x0c066f78u,0x0c066f7au,0x0c066f7cu,0x0c066f7eu,0x0c066f80u,0x0c066f82u,0x0c066f84u,
0x0c066f86u,0x0c066f88u,0x0c066f8au,0x0c066f8cu,0x0c066f8eu,0x0c066f90u,0x0c066f92u,0x0c066f94u,0x0c066f96u,0x0c066f98u,0x0c066f9au,0x0c066f9cu,0x0c066f9eu,0x0c066fa0u,0x0c066fa2u,0x0c066fa4u,
0x0c066fa6u,0x0c066fa8u,0x0c066faau,0x0c066facu,0x0c066faeu,0x0c066fb0u,0x0c066fb2u,0x0c066fb4u,0x0c066fd8u,0x0c066fdau,0x0c066fdcu,0x0c066fdeu,0x0c066fe0u,0x0c066fe2u,0x0c066fe4u,0x0c066fe6u,
0x0c066fe8u,0x0c066feau,0x0c066fecu,0x0c066feeu,0x0c066ff0u,0x0c066ff2u,0x0c066ff4u,0x0c066ff6u,0x0c066ff8u,0x0c066ffau,0x0c066ffcu,0x0c066ffeu,0x0c067000u,0x0c067002u,0x0c067004u,0x0c067006u,
0x0c067008u,0x0c06700au,0x0c06700cu,0x0c06700eu,0x0c067010u,0x0c067012u,0x0c067014u,0x0c067016u,0x0c067018u,0x0c06701au,0x0c06701cu,0x0c06701eu,0x0c067020u,0x0c067022u,0x0c067024u,0x0c067026u,
0x0c067028u,0x0c06702au,0x0c06702cu,0x0c06702eu,0x0c067030u,0x0c067032u,0x0c067034u,0x0c067036u,0x0c067038u,0x0c06703au,0x0c06703cu,0x0c06703eu,0x0c067040u,0x0c067042u,0x0c067044u,0x0c067046u,
0x0c067048u,0x0c06704au,0x0c06704cu,0x0c06704eu,0x0c067050u,0x0c067052u,0x0c067054u,0x0c067056u,0x0c067058u,0x0c06705au,0x0c06705cu,0x0c06705eu,0x0c067060u,0x0c067062u,0x0c067064u,0x0c067066u,
0x0c067068u,0x0c06706au,0x0c06706cu,0x0c06706eu,0x0c067070u,0x0c067072u,0x0c067074u,0x0c067076u,0x0c067078u,0x0c06707au,0x0c06707cu,0x0c06707eu,0x0c067080u,0x0c067082u,0x0c067084u,0x0c067086u,
0x0c067088u,0x0c06708au,0x0c06708cu,0x0c06708eu,0x0c067090u,0x0c067092u,0x0c067094u,0x0c067096u,0x0c067098u,0x0c06709au,0x0c06709cu,0x0c06709eu,0x0c0670a0u,0x0c0670a2u,0x0c0670a4u,0x0c0670a6u,
0x0c0670a8u,0x0c0670aau,0x0c0670acu,0x0c0670aeu,0x0c0670b0u,0x0c0670b2u,0x0c0670b4u,0x0c0670b6u,0x0c0670b8u,0x0c0670bau,0x0c0670bcu,0x0c0670beu,0x0c0670c0u,0x0c0670c2u,0x0c0670d8u,0x0c0670dau,
0x0c0670dcu,0x0c0670deu,0x0c0670e0u,0x0c0670e2u,0x0c0670e4u,0x0c0670e6u,0x0c0670e8u,0x0c0670eau,0x0c0670ecu,0x0c0670eeu,0x0c0670f0u,0x0c0670f2u,0x0c0670f4u,0x0c0670f6u,0x0c0670f8u,0x0c0670fau,
0x0c0670fcu,0x0c0670feu,0x0c067100u,0x0c067102u,0x0c067104u,0x0c067106u,0x0c067108u,0x0c06710au,0x0c06710cu,0x0c06710eu,0x0c067110u,0x0c067112u,0x0c067114u,0x0c067116u,0x0c067118u,0x0c06711au,
0x0c06711cu,0x0c06711eu,0x0c067120u,0x0c067122u,0x0c067124u,0x0c067126u,0x0c067128u,0x0c06712au,0x0c06712cu,0x0c06712eu,0x0c067130u,0x0c067132u,0x0c067134u,0x0c067136u,0x0c067138u,0x0c06713au,
0x0c06713cu,0x0c06713eu,0x0c067140u,0x0c067142u,0x0c067144u,0x0c067146u,0x0c067148u,0x0c06714au,0x0c06714cu,0x0c06714eu,0x0c067150u,0x0c067152u,0x0c067154u,0x0c067156u,0x0c067158u,0x0c06715au,
0x0c06715cu,0x0c06715eu,0x0c067160u,0x0c067162u,0x0c067164u,0x0c067166u,0x0c067168u,0x0c06716au,0x0c06716cu,0x0c06716eu,0x0c067170u,0x0c067172u,0x0c067174u,0x0c067176u,0x0c067178u,0x0c06717au,
0x0c06717cu,0x0c06717eu,0x0c067180u,0x0c067182u,0x0c067184u,0x0c067186u,0x0c067188u,0x0c06718au,0x0c06718cu,0x0c06718eu,0x0c067190u,0x0c067192u,0x0c067194u,0x0c067196u,0x0c067198u,0x0c06719au,
0x0c06719cu,0x0c06719eu,0x0c0671a0u,0x0c0671a2u,0x0c0671a4u,0x0c0671a6u,0x0c0671a8u,0x0c0671aau,0x0c0671acu,0x0c0671d8u,0x0c0671dau,0x0c0671dcu,0x0c0671deu,0x0c0671e0u,0x0c0671e2u,0x0c0671e4u,
0x0c0671e6u,0x0c0671e8u,0x0c0671eau,0x0c0671ecu,0x0c0671eeu,0x0c0671f0u,0x0c0671f2u,0x0c0671f4u,0x0c0671f6u,0x0c0671f8u,0x0c0671fau,0x0c0671fcu,0x0c0671feu,0x0c067200u,0x0c067202u,0x0c067204u,
0x0c067206u,0x0c067208u,0x0c06720au,0x0c06720cu,0x0c06720eu,0x0c067210u,0x0c067212u,0x0c067214u,0x0c067216u,0x0c067218u,0x0c06721au,0x0c06721cu,0x0c06721eu,0x0c067220u,0x0c067222u,0x0c067224u,
0x0c067226u,0x0c067228u,0x0c06722au,0x0c06722cu,0x0c06722eu,0x0c067230u,0x0c067232u,0x0c067234u,0x0c067236u,0x0c067238u,0x0c06723au,0x0c06723cu,0x0c06723eu,0x0c067240u,0x0c067242u,0x0c067244u,
0x0c067246u,0x0c067248u,0x0c06724au,0x0c06724cu,0x0c06724eu,0x0c067250u,0x0c067252u,0x0c067254u,0x0c067256u,0x0c067258u,0x0c06725au,0x0c06725cu,0x0c06725eu,0x0c067260u,0x0c067262u,0x0c067264u,
0x0c067266u,0x0c067268u,0x0c06726au,0x0c06726cu,0x0c06726eu,0x0c067270u,0x0c067272u,0x0c067274u,0x0c067276u,0x0c067278u,0x0c06727au,0x0c06727cu,0x0c06727eu,0x0c067280u,0x0c067282u,0x0c067284u,
0x0c067286u,0x0c067288u,0x0c06728au,0x0c06728cu,0x0c06728eu,0x0c067290u,0x0c067292u,0x0c067294u,0x0c067296u,0x0c067298u,0x0c06729au,0x0c06729cu,0x0c06729eu,0x0c0672a0u,0x0c0672a2u,0x0c0672c0u,
0x0c0672c2u,0x0c0672c4u,0x0c0672c6u,0x0c0672c8u,0x0c0672cau,0x0c0672ccu,0x0c0672ceu,0x0c0672d0u,0x0c0672d2u,0x0c0672d4u,0x0c0672d6u,0x0c0672d8u,0x0c0672dau,0x0c0672dcu,0x0c0672deu,0x0c0672e0u,
0x0c0672e2u,0x0c0672e4u,0x0c0672e6u,0x0c0672e8u,0x0c0672eau,0x0c0672ecu,0x0c0672eeu,0x0c0672f0u,0x0c0672f2u,0x0c0672f4u,0x0c0672f6u,0x0c0672f8u,0x0c0672fau,0x0c0672fcu,0x0c0672feu,0x0c067300u,
0x0c067302u,0x0c067304u,0x0c067306u,0x0c067308u,0x0c06730au,0x0c06730cu,0x0c06730eu,0x0c067310u,0x0c067312u,0x0c067314u,0x0c067316u,0x0c067318u,0x0c06731au,0x0c06731cu,0x0c06731eu,0x0c067320u,
0x0c067322u,0x0c067324u,0x0c067326u,0x0c067328u,0x0c06732au,0x0c06732cu,0x0c06732eu,0x0c067330u,0x0c067332u,0x0c067334u,0x0c067336u,0x0c067338u,0x0c06733au,0x0c06733cu,0x0c06733eu,0x0c067340u,
0x0c067342u,0x0c067344u,0x0c067346u,0x0c067348u,0x0c06734au,0x0c06734cu,0x0c06734eu,0x0c067350u,0x0c067352u,0x0c067354u,0x0c067356u,0x0c067358u,0x0c06735au,0x0c06735cu,0x0c06735eu,0x0c067360u,
0x0c067362u,0x0c067364u,0x0c067366u,0x0c0673a8u,0x0c0673aau,0x0c0673acu,0x0c0673aeu,0x0c0673b0u,0x0c0673b2u,0x0c0673b4u,0x0c0673b6u,0x0c0673b8u,0x0c0673bau,0x0c0673bcu,0x0c0673beu,0x0c0673c0u,
0x0c0673c2u,0x0c0673c4u,0x0c0673c6u,0x0c0673c8u,0x0c0673cau,0x0c0673ccu,0x0c0673ceu,0x0c0673d0u,0x0c0673d2u,0x0c0673d4u,0x0c0673d6u,0x0c0673d8u,0x0c0673dau,0x0c0673dcu,0x0c0673deu,0x0c0673e0u,
0x0c0673e2u,0x0c0673e4u,0x0c0673e6u,0x0c0673e8u,0x0c0673eau,0x0c0673ecu,0x0c0673eeu,0x0c0673f0u,0x0c0673f2u,0x0c0673f4u,0x0c0673f6u,0x0c0673f8u,0x0c0673fau,0x0c0673fcu,0x0c0673feu,0x0c067400u,
0x0c067402u,0x0c067404u,0x0c067406u,0x0c067408u,0x0c06740au,0x0c06740cu,0x0c06740eu,0x0c067410u,0x0c067412u,0x0c067414u,0x0c067416u,0x0c067418u,0x0c06741au,0x0c06741cu,0x0c06741eu,0x0c067420u,
0x0c067422u,0x0c067424u,0x0c067426u,0x0c067428u,0x0c06742au,0x0c06742cu,0x0c06742eu,0x0c067430u,0x0c067432u,0x0c067434u,0x0c067436u,0x0c067438u,0x0c06743au,0x0c06743cu,0x0c06743eu,0x0c067440u,
0x0c067468u,0x0c06746au,0x0c06746cu,0x0c06746eu,0x0c067470u,0x0c067472u,0x0c067474u,0x0c067476u,0x0c067478u,0x0c06747au,0x0c06747cu,0x0c06747eu,0x0c067480u,0x0c067482u,0x0c067484u,0x0c067486u,
0x0c067488u,0x0c06748au,0x0c06748cu,0x0c06748eu,0x0c067490u,0x0c067492u,0x0c067494u,0x0c067496u,0x0c067498u,0x0c06749au,0x0c06749cu,0x0c06749eu,0x0c0674a0u,0x0c0674a2u,0x0c0674a4u,0x0c0674a6u,
0x0c0674a8u,0x0c0674aau,0x0c0674acu,0x0c0674aeu,0x0c0674b0u,0x0c0674b2u,0x0c0674b4u,0x0c0674b6u,0x0c0674b8u,0x0c0674bau,0x0c0674bcu,0x0c0674beu,0x0c0674c0u,0x0c0674c2u,0x0c0674c4u,0x0c0674c6u,
0x0c0674c8u,0x0c0674cau,0x0c0674ccu,0x0c0674ceu,0x0c0674d0u,0x0c0674d2u,0x0c0674d4u,0x0c0674d6u,0x0c0674d8u,0x0c0674dau,0x0c0674dcu,0x0c0674deu,0x0c0674e0u,0x0c0674e2u,0x0c0674e4u,0x0c0674e6u,
0x0c0674e8u,0x0c0674eau,0x0c0674ecu,0x0c0674eeu,0x0c0674f0u,0x0c0674f2u,0x0c0674f4u,0x0c0674f6u,0x0c0674f8u,0x0c0674fau,0x0c0674fcu,0x0c0674feu,0x0c067562u,0x0c067564u,0x0c06758au,0x0c06758cu,
0x0c0675d4u,0x0c0675d6u,0x0c0675deu,0x0c0675e0u,0x0c0675e2u,0x0c0675e4u,0x0c0675e6u,0x0c0675fcu,0x0c0675feu,0x0c067600u,0x0c067602u,0x0c067604u,0x0c067606u,0x0c067608u,0x0c06760au,0x0c06760cu,
0x0c06760eu,0x0c067610u,0x0c06763cu,0x0c06763eu,0x0c067640u,0x0c067642u,0x0c067644u,0x0c067646u,0x0c067648u,0x0c06764au,0x0c06764cu,0x0c06764eu,0x0c067650u,0x0c067652u,0x0c067654u,0x0c067656u,
0x0c067658u,0x0c06765au,0x0c06765cu,0x0c06765eu,0x0c067660u,0x0c067662u,0x0c067664u,0x0c067666u,0x0c067668u,0x0c06766au,0x0c06766cu,0x0c06766eu,0x0c067670u,0x0c067672u,0x0c067674u,0x0c067676u,
0x0c067678u,0x0c06767au,0x0c06767cu,0x0c06767eu,0x0c067680u,0x0c067682u,0x0c067684u,0x0c067686u,0x0c067688u,0x0c06768au,0x0c06768cu,0x0c06768eu,0x0c067690u,0x0c067692u,0x0c067694u,0x0c067696u,
0x0c067698u,0x0c06769au,0x0c06769cu,0x0c06769eu,0x0c0676a0u,0x0c0676a2u,0x0c0676a4u,0x0c0676a6u,0x0c0676a8u,0x0c0676aau,0x0c0676acu,0x0c0676aeu,0x0c0676b0u,0x0c0676b2u,0x0c0676b4u,0x0c0676b6u,
0x0c0676b8u,0x0c0676bau,0x0c0676bcu,0x0c0676beu,0x0c0676c0u,0x0c0676c2u,0x0c0676c4u,0x0c0676c6u,0x0c0676c8u,0x0c0676cau,0x0c0676ccu,0x0c0676ceu,0x0c0676d0u,0x0c0676d2u,0x0c0676d4u,0x0c0676d6u,
0x0c0676d8u,0x0c0676dau,0x0c0676dcu,0x0c0676deu,0x0c0676e0u,0x0c0676e2u,0x0c0676e4u,0x0c0676e6u,0x0c0676e8u,0x0c0676eau,0x0c0676ecu,0x0c0676eeu,0x0c0676f0u,0x0c0676f2u,0x0c0676f4u,0x0c0676f6u,
0x0c0676f8u,0x0c0676fau,0x0c0676fcu,0x0c0676feu,0x0c067700u,0x0c067702u,0x0c067704u,0x0c067706u,0x0c067708u,0x0c06770au,0x0c06770cu,0x0c06770eu,0x0c067710u,0x0c067712u,0x0c06773cu,0x0c06773eu,
0x0c067740u,0x0c067742u,0x0c067744u,0x0c067746u,0x0c067748u,0x0c06774au,0x0c06774cu,0x0c06774eu,0x0c067750u,0x0c067752u,0x0c067754u,0x0c067756u,0x0c067758u,0x0c06775au,0x0c06775cu,0x0c06775eu,
0x0c067760u,0x0c067762u,0x0c067764u,0x0c067766u,0x0c067768u,0x0c06776au,0x0c06776cu,0x0c06776eu,0x0c067770u,0x0c067772u,0x0c067774u,0x0c067776u,0x0c067778u,0x0c06777au,0x0c06777cu,0x0c06777eu,
0x0c067780u,0x0c067782u,0x0c067784u,0x0c067786u,0x0c067788u,0x0c06778au,0x0c06778cu,0x0c06778eu,0x0c067790u,0x0c067792u,0x0c067794u,0x0c067796u,0x0c067798u,0x0c06779au,0x0c06779cu,0x0c06779eu,
0x0c0677a0u,0x0c0677a2u,0x0c0677a4u,0x0c0677a6u,0x0c0677a8u,0x0c0677aau,0x0c0677acu,0x0c0677aeu,0x0c0677b0u,0x0c0677b2u,0x0c0677b4u,0x0c0677b6u,0x0c0677b8u,0x0c0677bau,0x0c0677bcu,0x0c0677beu,
0x0c0677c0u,0x0c0677c2u,0x0c0677c4u,0x0c0677c6u,0x0c0677c8u,0x0c0677cau,0x0c0677ccu,0x0c0677ceu,0x0c0677d0u,0x0c0677d2u,0x0c0677d4u,0x0c0677d6u,0x0c0677d8u,0x0c0677dau,0x0c0677dcu,0x0c0677deu,
0x0c0677e0u,0x0c0677e2u,0x0c0677e4u,0x0c0677e6u,0x0c0677e8u,0x0c0677eau,0x0c0677ecu,0x0c0677eeu,0x0c0677f0u,0x0c0677f2u,0x0c0677f4u,0x0c0677f6u,0x0c0677f8u,0x0c0677fau,0x0c0677fcu,0x0c0677feu,
0x0c067800u,0x0c067802u,0x0c067804u,0x0c067806u,0x0c067808u,0x0c06780au,0x0c06780cu,0x0c06780eu,0x0c067810u,0x0c067812u,0x0c067814u,0x0c067816u,0x0c067818u,0x0c06781au,0x0c06781cu,0x0c06781eu,
0x0c067820u,0x0c067822u,0x0c067824u,0x0c067826u,0x0c067828u,0x0c06782au,0x0c06782cu,0x0c06782eu,0x0c067830u,0x0c067832u,0x0c067834u,0x0c067836u,0x0c067838u,0x0c06783au,0x0c06783cu,0x0c06783eu,
0x0c067840u,0x0c067894u,0x0c067896u,0x0c067898u,0x0c06789au,0x0c06789cu,0x0c06789eu,0x0c0678a0u,0x0c0678a2u,0x0c0678a4u,0x0c0678a6u,0x0c0678a8u,0x0c0678aau,0x0c0678acu,0x0c0678aeu,0x0c0678b0u,
0x0c0678b2u,0x0c0678b4u,0x0c0678b6u,0x0c0678b8u,0x0c0678bau,0x0c0678bcu,0x0c0678beu,0x0c0678c0u,0x0c0678c2u,0x0c0678c4u,0x0c0678c6u,0x0c0678c8u,0x0c0678cau,0x0c0678ccu,0x0c0678ceu,0x0c0678d0u,
0x0c0678d2u,0x0c0678d4u,0x0c0678d6u,0x0c0678d8u,0x0c0678dau,0x0c0678dcu,0x0c0678deu,0x0c0678e0u,0x0c0678e2u,0x0c0678e4u,0x0c0678e6u,0x0c0678e8u,0x0c0678eau,0x0c0678ecu,0x0c0678eeu,0x0c0678f0u,
0x0c0678f2u,0x0c0678f4u,0x0c0678f6u,0x0c067ea8u,0x0c067eaau,0x0c067eacu,0x0c067eaeu,0x0c067eb0u,0x0c067eb2u,0x0c067eb4u,0x0c067eb6u,0x0c067eb8u,0x0c067ebau,0x0c067ebcu,0x0c067ebeu,0x0c067ec0u,
0x0c067ec2u,0x0c067ec4u,0x0c067ec6u,0x0c067ec8u,0x0c067ecau,0x0c067eccu,0x0c067eceu,0x0c067ed0u,0x0c067ed2u,0x0c067ed4u,0x0c067ed6u,0x0c067ed8u,0x0c067edau,0x0c067edcu,0x0c067edeu,0x0c067ee0u,
0x0c067ee2u,0x0c067ee4u,0x0c067ee6u,0x0c067ee8u,0x0c067eeau,0x0c067eecu,0x0c067eeeu,0x0c0681ccu,0x0c0681ceu,0x0c0681d0u,0x0c0681d2u,0x0c0681d4u,0x0c0681d6u,0x0c0681d8u,0x0c0681dau,0x0c0681dcu,
0x0c0681deu,0x0c0681e0u,0x0c0681e2u,0x0c0681e4u,0x0c0681e6u,0x0c0681e8u,0x0c0681eau,0x0c0681ecu,0x0c0681eeu,0x0c0681f0u,0x0c0681f2u,0x0c0681f4u,0x0c0681f6u,0x0c0681f8u,0x0c0681fau,0x0c0681fcu,
0x0c0681feu,0x0c068200u,0x0c068202u,0x0c068204u,0x0c068206u,0x0c068208u,0x0c06820au,0x0c06820cu,0x0c06820eu,0x0c068210u,0x0c068212u,0x0c068214u,0x0c068216u,0x0c068218u,0x0c06821au,0x0c06821cu,
0x0c06821eu,0x0c068220u,0x0c068222u,0x0c068224u,0x0c068226u,0x0c068228u,0x0c06822au,0x0c06822cu,0x0c06822eu,0x0c068230u,0x0c068232u,0x0c068234u,0x0c068236u,0x0c068238u,0x0c06823au,0x0c06823cu,
0x0c06823eu,0x0c068240u,0x0c068242u,0x0c068244u,0x0c068246u,0x0c068248u,0x0c06824au,0x0c06824cu,0x0c06824eu,0x0c068250u,0x0c068252u,0x0c068254u,0x0c068256u,0x0c068258u,0x0c06825au,0x0c06825cu,
0x0c06825eu,0x0c068260u,0x0c068262u,0x0c068264u,0x0c068266u,0x0c068268u,0x0c06826au,0x0c06826cu,0x0c06826eu,0x0c068270u,0x0c068272u,0x0c068274u,0x0c068276u,0x0c068278u,0x0c06827au,0x0c06827cu,
0x0c06827eu,0x0c068280u,0x0c068282u,0x0c068284u,0x0c068286u,0x0c068288u,0x0c06828au,0x0c06828cu,0x0c06828eu,0x0c068290u,0x0c068292u,0x0c068294u,0x0c068296u,0x0c068298u,0x0c06829au,0x0c06829cu,
0x0c06829eu,0x0c0685deu,0x0c0685e0u,0x0c0685e2u,0x0c0685e4u,0x0c0685e6u,0x0c0685e8u,0x0c0685eau,0x0c0685ecu,0x0c0685eeu,0x0c0685f0u,0x0c06862au,0x0c06862cu,0x0c06862eu,0x0c068630u,0x0c068632u,
0x0c068634u,0x0c068636u,0x0c068638u,0x0c06863au,0x0c06863cu,0x0c06863eu,0x0c068640u,0x0c068642u,0x0c068644u,0x0c068646u,0x0c068648u,0x0c06864au,0x0c06864cu,0x0c06864eu,0x0c068650u,0x0c068652u,
0x0c068654u,0x0c068656u,0x0c068658u,0x0c06865au,0x0c06865cu,0x0c06865eu,0x0c068660u,0x0c068662u,0x0c068664u,0x0c068666u,0x0c068668u,0x0c06866au,0x0c06866cu,0x0c06866eu,0x0c068670u,0x0c068672u,
0x0c068674u,0x0c068676u,0x0c068678u,0x0c06867au,0x0c06867cu,0x0c06867eu,0x0c068680u,0x0c068682u,0x0c068684u,0x0c068686u,0x0c068688u,0x0c06868au,0x0c06868cu,0x0c06868eu,0x0c068690u,0x0c068692u,
0x0c068694u,0x0c068696u,0x0c068698u,0x0c06869au,0x0c06869cu,0x0c06869eu,0x0c0686a0u,0x0c0686a2u,0x0c0686a4u,0x0c0686a6u,0x0c0686a8u,0x0c0686aau,0x0c0686acu,0x0c0686aeu,0x0c0686b0u,0x0c0686b2u,
0x0c0686b4u,0x0c0686b6u,0x0c0686b8u,0x0c0686bau,0x0c0686bcu,0x0c0686beu,0x0c0686c0u,0x0c0686ecu,0x0c0686eeu,0x0c0686f0u,0x0c0686f2u,0x0c0686f4u,0x0c0686f6u,0x0c0686f8u,0x0c0686fau,0x0c0686fcu,
0x0c0686feu,0x0c068700u,0x0c068702u,0x0c068704u,0x0c068706u,0x0c068708u,0x0c06870au,0x0c06870cu,0x0c06870eu,0x0c068710u,0x0c068712u,0x0c068714u,0x0c068716u,0x0c068718u,0x0c06871au,0x0c06871cu,
0x0c06871eu,0x0c068720u,0x0c068722u,0x0c068724u,0x0c068726u,0x0c068728u,0x0c06872au,0x0c06872cu,0x0c06872eu,0x0c068730u,0x0c068732u,0x0c068734u,0x0c068736u,0x0c068738u,0x0c06873au,0x0c06873cu,
0x0c06873eu,0x0c068740u,0x0c068742u,0x0c068744u,0x0c068746u,0x0c068748u,0x0c06874au,0x0c06874cu,0x0c06874eu,0x0c068750u,0x0c068752u,0x0c068754u,0x0c068756u,0x0c068758u,0x0c06875au,0x0c06875cu,
0x0c06875eu,0x0c068760u,0x0c068762u,0x0c068764u,0x0c068766u,0x0c068768u,0x0c06876au,0x0c06876cu,0x0c06876eu,0x0c068770u,0x0c068772u,0x0c068774u,0x0c068776u,0x0c068778u,0x0c06877au,0x0c06877cu,
0x0c06877eu,0x0c068780u,0x0c068782u,0x0c068784u,0x0c068786u,0x0c068788u,0x0c06878au,0x0c06878cu,0x0c06878eu,0x0c068790u,0x0c068792u,0x0c068794u,0x0c068796u,0x0c068798u,0x0c06879au,0x0c06879cu,
0x0c06879eu,0x0c0687a0u,0x0c0687a2u,0x0c0687a4u,0x0c0687a6u,0x0c0687a8u,0x0c0687aau,0x0c0687acu,0x0c0687aeu,0x0c0687b0u,0x0c0687b2u,0x0c0687b4u,0x0c0687b6u,0x0c0687b8u,0x0c0687bau,0x0c0687bcu,
0x0c0687beu,0x0c0687c0u,0x0c0687c2u,0x0c0687c4u,0x0c0687c6u,0x0c0687c8u,0x0c0687cau,0x0c0687ccu,0x0c0687ceu,0x0c0687d0u,0x0c0687d2u,0x0c0687d4u,0x0c0687d6u,0x0c0687d8u,0x0c0687dau,0x0c0687dcu,
0x0c0687deu,0x0c0687e0u,0x0c0687e2u,0x0c0687eau,0x0c0687ecu,0x0c0687eeu,0x0c0687f0u,0x0c0687f2u,0x0c0687f4u,0x0c0687f6u,0x0c0687f8u,0x0c0687fau,0x0c0687fcu,0x0c0687feu,0x0c068800u,0x0c068802u,
0x0c068804u,0x0c068806u,0x0c068808u,0x0c06880au,0x0c06880cu,0x0c06880eu,0x0c068810u,0x0c068812u,0x0c068814u,0x0c068816u,0x0c068818u,0x0c06881au,0x0c06881cu,0x0c06881eu,0x0c068820u,0x0c068822u,
0x0c068824u,0x0c068826u,0x0c068828u,0x0c06882au,0x0c06882cu,0x0c06882eu,0x0c068830u,0x0c068832u,0x0c068834u,0x0c068836u,0x0c068838u,0x0c06883au,0x0c06883cu,0x0c06883eu,0x0c068840u,0x0c068842u,
0x0c068844u,0x0c068846u,0x0c068848u,0x0c06884au,0x0c06884cu,0x0c06884eu,0x0c068850u,0x0c068852u,0x0c068854u,0x0c068856u,0x0c068858u,0x0c06885au,0x0c06885cu,0x0c06885eu,0x0c068860u,0x0c068862u,
0x0c068864u,0x0c068866u,0x0c068868u,0x0c06886au,0x0c06886cu,0x0c06886eu,0x0c068870u,0x0c068872u,0x0c068874u,0x0c068876u,0x0c068878u,0x0c06887au,0x0c06887cu,0x0c06887eu,0x0c068880u,0x0c068882u,
0x0c068884u,0x0c068886u,0x0c068888u,0x0c06888au,0x0c06888cu,0x0c06888eu,0x0c068890u,0x0c068892u,0x0c068894u,0x0c068896u,0x0c068898u,0x0c06889au,0x0c06889cu,0x0c06889eu,0x0c0688a0u,0x0c0688a2u,
0x0c0688a4u,0x0c0688a6u,0x0c0688a8u,0x0c0688aau,0x0c0688acu,0x0c0688aeu,0x0c0688b0u,0x0c0688b2u,0x0c0688b4u,0x0c0688b6u,0x0c0688b8u,0x0c0688bau,0x0c0688bcu,0x0c0688beu,0x0c0688c0u,0x0c0688c2u,
0x0c0688c4u,0x0c0688c6u,0x0c0688c8u,0x0c0688cau,0x0c0688ccu,0x0c0688ceu,0x0c0688d0u,0x0c0688d2u,0x0c0688d4u,0x0c0688d6u,0x0c0688d8u,0x0c0688dau,0x0c0688dcu,0x0c0688deu,0x0c0688e0u,0x0c0688e2u,
0x0c0688e4u,0x0c0688e6u,0x0c0688e8u,0x0c0688eau,0x0c0688ecu,0x0c0688eeu,0x0c0688f0u,0x0c0688f2u,0x0c0688f4u,0x0c0688f6u,0x0c0688f8u,0x0c0688fau,0x0c0688fcu,0x0c0688feu,0x0c068900u,0x0c068902u,
0x0c068904u,0x0c068906u,0x0c068908u,0x0c06890au,0x0c06890cu,0x0c06890eu,0x0c068910u,0x0c068912u,0x0c068914u,0x0c068916u,0x0c068918u,0x0c06891au,0x0c06891cu,0x0c06891eu,0x0c068920u,0x0c068922u,
0x0c068924u,0x0c068926u,0x0c068928u,0x0c06892au,0x0c06892cu,0x0c06892eu,0x0c068930u,0x0c068932u,0x0c068934u,0x0c068936u,0x0c068938u,0x0c06893au,0x0c06893cu,0x0c06893eu,0x0c068940u,0x0c068942u,
0x0c068944u,0x0c068946u,0x0c068948u,0x0c06894au,0x0c06894cu,0x0c06894eu,0x0c068950u,0x0c068952u,0x0c068954u,0x0c068956u,0x0c068958u,0x0c06895au,0x0c06895cu,0x0c06895eu,0x0c068960u,0x0c068962u,
0x0c068964u,0x0c068974u,0x0c068976u,0x0c068978u,0x0c06897au,0x0c06897cu,0x0c06897eu,0x0c068980u,0x0c068982u,0x0c068984u,0x0c068986u,0x0c068988u,0x0c06898au,0x0c06898cu,0x0c06898eu,0x0c068992u,
0x0c068994u,0x0c068996u,0x0c068998u,0x0c06899au,0x0c06899cu,0x0c06899eu,0x0c0689a0u,0x0c0689a2u,0x0c0689a4u,0x0c0689a6u,0x0c0689a8u,0x0c0689aau,0x0c0689acu,0x0c0689aeu,0x0c0689b0u,0x0c0689b2u,
0x0c0689b4u,0x0c0689b6u,0x0c0689b8u,0x0c0689bau,0x0c0689bcu,0x0c0689beu,0x0c0689c0u,0x0c0689c2u,0x0c0689c4u,0x0c0689c6u,0x0c0689c8u,0x0c0689cau,0x0c0689ccu,0x0c0689ceu,0x0c0689d0u,0x0c0689d2u,
0x0c0689d4u,0x0c0689d6u,0x0c0689d8u,0x0c0689dau,0x0c0689dcu,0x0c0689deu,0x0c0689e0u,0x0c0689e2u,0x0c0689e4u,0x0c0689e6u,0x0c0689e8u,0x0c0689eau,0x0c0689ecu,0x0c0689eeu,0x0c0689f0u,0x0c0689f2u,
0x0c0689f4u,0x0c0689f6u,0x0c0689f8u,0x0c0689fau,0x0c0689fcu,0x0c0689feu,0x0c068a00u,0x0c068a02u,0x0c068a04u,0x0c068a06u,0x0c068a08u,0x0c068a0au,0x0c068a0cu,0x0c068a0eu,0x0c068a10u,0x0c068a12u,
0x0c068a14u,0x0c068a16u,0x0c068a18u,0x0c068a1au,0x0c068a1cu,0x0c068a1eu,0x0c068a20u,0x0c068a22u,0x0c068a24u,0x0c068a26u,0x0c068a28u,0x0c068a2au,0x0c068a2cu,0x0c068a2eu,0x0c068a30u,0x0c068a32u,
0x0c068a34u,0x0c068a36u,0x0c068a38u,0x0c068a3au,0x0c068a3cu,0x0c068a3eu,0x0c068a40u,0x0c068a42u,0x0c068a44u,0x0c068a46u,0x0c068a48u,0x0c068a4au,0x0c068a4cu,0x0c068a4eu,0x0c068a50u,0x0c068a52u,
0x0c068a54u,0x0c068a56u,0x0c068a58u,0x0c068a5au,0x0c068a5cu,0x0c068a5eu,0x0c068a60u,0x0c068a62u,0x0c068a64u,0x0c068a66u,0x0c068a68u,0x0c068a6au,0x0c068a6cu,0x0c068a6eu,0x0c068a70u,0x0c068a72u,
0x0c068a74u,0x0c068a76u,0x0c068a78u,0x0c068a7au,0x0c068a7cu,0x0c068a7eu,0x0c068a80u,0x0c068a82u,0x0c068a84u,0x0c068a86u,0x0c068a88u,0x0c068a8au,0x0c068a8cu,0x0c068a8eu,0x0c068a90u,0x0c068a92u,
0x0c068a94u,0x0c068a96u,0x0c068a98u,0x0c068a9au,0x0c068a9cu,0x0c068a9eu,0x0c068aa0u,0x0c068aa2u,0x0c068aa4u,0x0c068aa6u,0x0c068aa8u,0x0c068aaau,0x0c068aacu,0x0c068aaeu,0x0c068ab0u,0x0c068ab2u,
0x0c068ab4u,0x0c068ab6u,0x0c068ab8u,0x0c068abau,0x0c068abcu,0x0c068abeu,0x0c068ac0u,0x0c068ac2u,0x0c068ac4u,0x0c068ac6u,0x0c068ac8u,0x0c068acau,0x0c068accu,0x0c068aceu,0x0c068ad0u,0x0c068ad2u,
0x0c068ad4u,0x0c068ad6u,0x0c068ad8u,0x0c068adau,0x0c068adcu,0x0c068adeu,0x0c068ae0u,0x0c068ae2u,0x0c068ae4u,0x0c068ae6u,0x0c068ae8u,0x0c068aeau,0x0c068aecu,0x0c068aeeu,0x0c068af0u,0x0c068af2u,
0x0c068af4u,0x0c068af6u,0x0c068af8u,0x0c068afau,0x0c068afcu,0x0c068afeu,0x0c068b00u,0x0c068b02u,0x0c068b04u,0x0c068b06u,0x0c068b08u,0x0c068b0au,0x0c068b0cu,0x0c068b0eu,0x0c068b10u,0x0c068b12u,
0x0c068b14u,0x0c068b16u,0x0c068b18u,0x0c068b1au,0x0c068b1cu,0x0c068b1eu,0x0c068b20u,0x0c068b22u,0x0c068b24u,0x0c068b26u,0x0c068b28u,0x0c068b2au,0x0c068b2cu,0x0c068b2eu,0x0c068b30u,0x0c068b32u,
0x0c068b34u,0x0c068b36u,0x0c068b38u,0x0c068b3au,0x0c068b3cu,0x0c068b3eu,0x0c068b40u,0x0c068b42u,0x0c068b44u,0x0c068b46u,0x0c068b48u,0x0c068b4au,0x0c068b4cu,0x0c068b64u,0x0c068b66u,0x0c068b68u,
0x0c068b6au,0x0c068b6cu,0x0c068b6eu,0x0c068b70u,0x0c068b72u,0x0c068b74u,0x0c068b76u,0x0c068b78u,0x0c068b7au,0x0c068b7cu,0x0c068b7eu,0x0c068b80u,0x0c068b82u,0x0c068b84u,0x0c068b86u,0x0c068b88u,
0x0c068b8au,0x0c068b8cu,0x0c068b8eu,0x0c068b90u,0x0c068b92u,0x0c068b94u,0x0c068b96u,0x0c068b98u,0x0c068b9au,0x0c068b9cu,0x0c068b9eu,0x0c068ba0u,0x0c068ba2u,0x0c068ba4u,0x0c068ba6u,0x0c068ba8u,
0x0c068baau,0x0c068bacu,0x0c068baeu,0x0c068bb0u,0x0c068bb2u,0x0c068bb4u,0x0c068bb6u,0x0c068bb8u,0x0c068bbau,0x0c068bbcu,0x0c068bbeu,0x0c068bc0u,0x0c068bc2u,0x0c068bc4u,0x0c068bc6u,0x0c068bc8u,
0x0c068bcau,0x0c068bccu,0x0c068bceu,0x0c068bd0u,0x0c068bd2u,0x0c068bd4u,0x0c068bd6u,0x0c068bd8u,0x0c068bdau,0x0c068bdcu,0x0c068bdeu,0x0c068be0u,0x0c068be2u,0x0c068be4u,0x0c068be6u,0x0c068be8u,
0x0c068beau,0x0c068becu,0x0c068beeu,0x0c068bf0u,0x0c068bf2u,0x0c068bf4u,0x0c068bf6u,0x0c068bf8u,0x0c068bfau,0x0c068bfcu,0x0c068bfeu,0x0c068c00u,0x0c068c02u,0x0c068e0eu,0x0c068e10u,0x0c068e12u,
0x0c068e14u,0x0c068e16u,0x0c068e18u,0x0c068e1au,0x0c068e1cu,0x0c068e1eu,0x0c068e20u,0x0c068e22u,0x0c068e24u,0x0c068e26u,0x0c068e28u,0x0c068e2au,0x0c068e2cu,0x0c068e2eu,0x0c068e30u,0x0c068e32u,
0x0c068e34u,0x0c068e36u,0x0c068e38u,0x0c068e3au,0x0c068e3cu,0x0c068e3eu,0x0c068e40u,0x0c068e42u,0x0c068e44u,0x0c068e46u,0x0c068e48u,0x0c068e4au,0x0c068e4cu,0x0c068e4eu,0x0c068e6cu,0x0c068e6eu,
0x0c068e70u,0x0c068e72u,0x0c068e74u,0x0c068e76u,0x0c068e78u,0x0c068e7au,0x0c068e7cu,0x0c068e7eu,0x0c068e80u,0x0c068e82u,0x0c068e84u,0x0c068e86u,0x0c068e88u,0x0c068e8au,0x0c068e8cu,0x0c068e8eu,
0x0c068e90u,0x0c068e92u,0x0c068e94u,0x0c068e96u,0x0c068e98u,0x0c068e9au,0x0c068e9cu,0x0c068e9eu,0x0c068ea0u,0x0c068ea2u,0x0c068ea4u,0x0c068ea6u,0x0c068ea8u,0x0c068eaau,0x0c068eacu,0x0c068eaeu,
0x0c068eb0u,0x0c068eb2u,0x0c068eb4u,0x0c068eb6u,0x0c068eb8u,0x0c068ebau,0x0c068ebcu,0x0c068ebeu,0x0c068ec0u,0x0c068ec2u,0x0c068ec4u,0x0c068ec6u,0x0c068ec8u,0x0c068ecau,0x0c068eccu,0x0c068eceu,
0x0c068ed0u,0x0c068ed2u,0x0c068ed4u,0x0c068ed6u,0x0c068ed8u,0x0c068edau,0x0c068edcu,0x0c068edeu,0x0c068ee0u,0x0c068ee2u,0x0c068ee4u,0x0c068ee6u,0x0c068ee8u,0x0c068eeau,0x0c068eecu,0x0c068eeeu,
0x0c068ef0u,0x0c068ef2u,0x0c068ef4u,0x0c068ef6u,0x0c068ef8u,0x0c068efau,0x0c068efcu,0x0c068efeu,0x0c068f00u,0x0c068f02u,0x0c068f04u,0x0c068f06u,0x0c068f08u,0x0c068f0au,0x0c068f0cu,0x0c068f0eu,
0x0c068f10u,0x0c068f12u,0x0c068f14u,0x0c068f16u,0x0c068f18u,0x0c068f1au,0x0c068f1cu,0x0c068f1eu,0x0c068f20u,0x0c068f22u,0x0c068f24u,0x0c068f26u,0x0c068f28u,0x0c068f2au,0x0c068f2cu,0x0c068f2eu,
0x0c068f30u,0x0c068f32u,0x0c068f34u,0x0c068f36u,0x0c068f38u,0x0c068f3au,0x0c068f3cu,0x0c068f3eu,0x0c068f40u,0x0c068f42u,0x0c068f44u,0x0c068f46u,0x0c068f48u,0x0c068f4au,0x0c068f4cu,0x0c068f4eu,
0x0c068f50u,0x0c068f52u,0x0c068f54u,0x0c068f56u,0x0c068f58u,0x0c068f5au,0x0c068f5cu,0x0c068f5eu,0x0c068f60u,0x0c068f62u,0x0c068f64u,0x0c068f66u,0x0c068f68u,0x0c068f6au,0x0c068f6cu,0x0c068f6eu,
0x0c068f70u,0x0c068f72u,0x0c068f74u,0x0c068f76u,0x0c068f78u,0x0c068f7au,0x0c068f7cu,0x0c068f7eu,0x0c068f80u,0x0c068f82u,0x0c068f84u,0x0c068f86u,0x0c068f88u,0x0c068f8au,0x0c068f8cu,0x0c068f8eu,
0x0c068f90u,0x0c069624u,0x0c069626u,0x0c069628u,0x0c06962au,0x0c06962cu,0x0c06962eu,0x0c069630u,0x0c069632u,0x0c069634u,0x0c069636u,0x0c069638u,0x0c06963au,0x0c06963cu,0x0c06963eu,0x0c069640u,
0x0c069642u,0x0c069644u,0x0c069646u,0x0c069648u,0x0c06964au,0x0c06964cu,0x0c06964eu,0x0c069650u,0x0c069652u,0x0c069654u,0x0c069656u,0x0c069658u,0x0c06965au,0x0c06965cu,0x0c06965eu,0x0c069660u,
0x0c069662u,0x0c069664u,0x0c069666u,0x0c069668u,0x0c06966au,0x0c06966cu,0x0c06966eu,0x0c069670u,0x0c069672u,0x0c069674u,0x0c069676u,0x0c069678u,0x0c06967au,0x0c06967cu,0x0c06967eu,0x0c069680u,
0x0c069682u,0x0c069684u,0x0c069686u,0x0c069688u,0x0c06968au,0x0c06968cu,0x0c06968eu,0x0c069690u,0x0c069692u,0x0c069694u,0x0c069696u,0x0c069698u,0x0c06969au,0x0c06969cu,0x0c06f77cu,0x0c06f77eu,
0x0c06f780u,0x0c06f782u,0x0c06f784u,0x0c06f786u,0x0c06f788u,0x0c06f78au,0x0c06f78cu,0x0c06f78eu,0x0c06f790u,0x0c06f792u,0x0c06f794u,0x0c06f796u,0x0c06f798u,0x0c06f79au,0x0c06f79cu,0x0c06f79eu,
0x0c06f7a0u,0x0c06f7a2u,0x0c06f7a4u,0x0c06f7a6u,0x0c06f7a8u,0x0c06f7aau,0x0c06f7acu,0x0c06f7aeu,0x0c06f7b0u,0x0c06f7b2u,0x0c06f7b4u,0x0c06f7b6u,0x0c06f7b8u,0x0c06f7bau,0x0c06f7bcu,0x0c06f7beu,
0x0c06f7c0u,0x0c06f7c2u,0x0c06f7c4u,0x0c06f7c6u,0x0c06f7c8u,0x0c06f7cau,0x0c06f7ccu,0x0c06f7ceu,0x0c06f7d0u,0x0c06f7d2u,0x0c06f7d4u,0x0c06f7d6u,0x0c06f7d8u,0x0c06f7dau,0x0c06f7dcu,0x0c06f7deu,
0x0c06f7e0u,0x0c06f7e2u,0x0c06f7e4u,0x0c06f7e6u,0x0c06f7e8u,0x0c06f7eau,0x0c06f7ecu,0x0c06f7eeu,0x0c06f7f0u,0x0c06f7f2u,0x0c06f7f4u,0x0c06f7f6u,0x0c06f7f8u,0x0c06f7fau,0x0c06f7fcu,0x0c06f7feu,
0x0c06f800u,0x0c06f802u,0x0c06f804u,0x0c06f806u,0x0c06f808u,0x0c06f80au,0x0c06f80cu,0x0c06f80eu,0x0c06f810u,0x0c06f812u,0x0c06f814u,0x0c06f816u,0x0c06f818u,0x0c06f81au,0x0c06f81cu,0x0c06f81eu,
0x0c06f820u,0x0c06f822u,0x0c06f824u,0x0c06f826u,0x0c06f828u,0x0c06f82au,0x0c06f82cu,0x0c06f82eu,0x0c06f830u,0x0c06f832u,0x0c06f834u,0x0c06f836u,0x0c06f838u,0x0c06f83au,0x0c06f83cu,0x0c06f83eu,
0x0c06f840u,0x0c06f842u,0x0c06f844u,0x0c06f846u,0x0c06f848u,0x0c06f84au,0x0c06f84cu,0x0c06f84eu,0x0c06f850u,0x0c06f852u,0x0c06f854u,0x0c06f856u,0x0c06f858u,0x0c06f85au,0x0c06f85cu,0x0c06f85eu,
0x0c06f860u,0x0c06f862u,0x0c06f864u,0x0c06f866u,0x0c06f868u,0x0c06f86au,0x0c06f86cu,0x0c06f86eu,0x0c06f870u,0x0c06f872u,0x0c06f874u,0x0c06f876u,0x0c06f878u,0x0c06f87au,0x0c06f87cu,0x0c06f87eu,
0x0c06f880u,0x0c06f882u,0x0c06f884u,0x0c06f886u,0x0c06f888u,0x0c06f88au,0x0c06f88cu,0x0c06f88eu,0x0c06f890u,0x0c06f892u,0x0c06f894u,0x0c06f896u,0x0c06f898u,0x0c06f89au,0x0c06f89cu,0x0c06f89eu,
0x0c06f8a0u,0x0c06f8a2u,0x0c06f8a4u,0x0c06f8a6u,0x0c06f8a8u,0x0c06f8aau,0x0c06f8acu,0x0c06f8aeu,0x0c06f8b0u,0x0c06f8b2u,0x0c06f8b4u,0x0c06f8b6u,0x0c06f8b8u,0x0c06f8bau,0x0c06f8bcu,0x0c06f8beu,
0x0c06f8c0u,0x0c06f8c2u,0x0c06f8c4u,0x0c06f8c6u,0x0c06f8c8u,0x0c06f8cau,0x0c06f8ccu,0x0c06f8ceu,0x0c06f8d0u,0x0c06f8d2u,0x0c06f8d4u,0x0c06f8d6u,0x0c06f8d8u,0x0c06f8dau,0x0c06f8dcu,0x0c06f8deu,
0x0c06f8e0u,0x0c06f8e2u,0x0c06f8e4u,0x0c06f8e6u,0x0c06f8e8u,0x0c06f8eau,0x0c06f8ecu,0x0c06f8eeu,0x0c06f8f0u,0x0c06f8f2u,0x0c06f8f4u,0x0c06f8f6u,0x0c06f8f8u,0x0c06f8fau,0x0c06f8fcu,0x0c06f8feu,
0x0c06f900u,0x0c06f902u,0x0c06f904u,0x0c06f906u,0x0c06f908u,0x0c06f90au,0x0c06f90cu,0x0c06f90eu,0x0c06f910u,0x0c06f912u,0x0c06f914u,0x0c06f916u,0x0c06f918u,0x0c06f91au,0x0c06f91cu,0x0c06f91eu,
0x0c06f920u,0x0c06f922u,0x0c06f924u,0x0c06f926u,0x0c06f928u,0x0c06f92au,0x0c06f92cu,0x0c06f92eu,0x0c06f930u,0x0c06f932u,0x0c06f934u,0x0c06f936u,0x0c06f938u,0x0c06f93au,0x0c06f93cu,0x0c06f93eu,
0x0c06f940u,0x0c06f942u,0x0c06f944u,0x0c06f946u,0x0c06f948u,0x0c06f94au,0x0c06f94cu,0x0c06f94eu,0x0c06f950u,0x0c06f952u,0x0c06f954u,0x0c06f956u,0x0c06f958u,0x0c06f95au,0x0c06f95cu,0x0c06f95eu,
0x0c06f960u,0x0c06f962u,0x0c06f964u,0x0c06f966u,0x0c06f968u,0x0c06f96au,0x0c06f96cu,0x0c06f96eu,0x0c06f970u,0x0c06f972u,0x0c06f974u,0x0c06f976u,0x0c06f978u,0x0c06f97au,0x0c06f97cu,0x0c06f97eu,
0x0c06f980u,0x0c06f982u,0x0c06f984u,0x0c06f986u,0x0c06f988u,0x0c06f98au,0x0c06f98cu,0x0c06f98eu,0x0c06f990u,0x0c071104u,0x0c071106u,0x0c071108u,0x0c07110au,0x0c07110cu,0x0c07110eu,0x0c071110u,
0x0c071112u,0x0c071114u,0x0c071116u,0x0c071118u,0x0c07111au,0x0c07111cu,0x0c07111eu,0x0c071120u,0x0c071122u,0x0c071124u,0x0c071126u,0x0c071128u,0x0c07112au,0x0c07112cu,0x0c07112eu,0x0c071130u,
0x0c071132u,0x0c071134u,0x0c071136u,0x0c071138u,0x0c07113au,0x0c07113cu,0x0c07113eu,0x0c071faau,0x0c071facu,0x0c071faeu,0x0c071fb0u,0x0c071fb2u,0x0c071fb4u,0x0c071fb6u,0x0c071fb8u,0x0c071fbau,
0x0c071fbcu,0x0c071fbeu,0x0c071fc0u,0x0c071fc2u,0x0c071fc4u,0x0c071fc6u,0x0c071fc8u,0x0c071fcau,0x0c071fccu,0x0c071fd4u,0x0c071fd6u,0x0c071fd8u,0x0c071fdau,0x0c071fdcu,0x0c071fdeu,0x0c071fe0u,
0x0c071fe2u,0x0c071fe4u,0x0c071fe6u,0x0c071fe8u,0x0c071feau,0x0c071fecu,0x0c071feeu,0x0c071ff0u,0x0c071ff2u,0x0c071ff4u,0x0c071ff6u,0x0c071ff8u,0x0c071ffau,0x0c071ffcu,0x0c071ffeu,0x0c072000u,
0x0c072002u,0x0c072004u,0x0c072006u,0x0c072008u,0x0c07200au,0x0c07200cu,0x0c07200eu,0x0c072010u,0x0c072012u,0x0c072014u,0x0c072016u,0x0c072018u,0x0c07201au,0x0c07201cu,0x0c07201eu,0x0c072020u,
0x0c072022u,0x0c072024u,0x0c072026u,0x0c072028u,0x0c07202au,0x0c07202cu,0x0c07202eu,0x0c072030u,0x0c072032u,0x0c072034u,0x0c072036u,0x0c072038u,0x0c07203au,0x0c07203cu,0x0c07203eu,0x0c072040u,
0x0c072042u,0x0c072044u,0x0c072046u,0x0c072048u,0x0c07204au,0x0c07204cu,0x0c07204eu,0x0c072050u,0x0c072052u,0x0c072054u,0x0c072056u,0x0c072058u,0x0c07205au,0x0c07205cu,0x0c07205eu,0x0c072060u,
0x0c072062u,0x0c072064u,0x0c072066u,0x0c072068u,0x0c07206au,0x0c07206cu,0x0c07206eu,0x0c072070u,0x0c072072u,0x0c072074u,0x0c07b398u,0x0c07b39au,0x0c07b39cu,0x0c07b39eu,0x0c07b3a0u,0x0c07b3a2u,
0x0c07b3a4u,0x0c07b3a6u,0x0c07b3a8u,0x0c07b3aau,0x0c07b3acu,0x0c07b3aeu,0x0c07b3b0u,0x0c07b3b2u,0x0c07b3b4u,0x0c07b3b6u,0x0c07b3b8u,0x0c07b3bau,0x0c07b3bcu,0x0c07b3beu,0x0c07b3c0u,0x0c07b3c2u,
0x0c07b3c4u,0x0c07b3c6u,0x0c07b3c8u,0x0c07b3cau,0x0c07b3ccu,0x0c07b3ceu,0x0c07b3d0u,0x0c07b6c4u,0x0c07b6c6u,0x0c07b6c8u,0x0c07b6cau,0x0c07b6ccu,0x0c07b6ceu,0x0c07b6d0u,0x0c07b6d2u,0x0c07b6d4u,
0x0c07b6d6u,0x0c07b6d8u,0x0c07b6dau,0x0c07b6dcu,0x0c07b6deu,0x0c07b6e0u,0x0c07b6e2u,0x0c07b6e4u,0x0c07b6e6u,0x0c07b6e8u,0x0c07b6eau,0x0c07b6ecu,0x0c07b6eeu,0x0c07b6f0u,0x0c07b6f2u,0x0c09518cu,
0x0c09518eu,0x0c095190u,0x0c095192u,0x0c095194u,0x0c095196u,0x0c095198u,0x0c09519au,0x0c09519cu,0x0c09519eu,0x0c0951a0u,0x0c0951a2u,0x0c0951a4u,0x0c0951a6u,0x0c0951a8u,0x0c0951aau,0x0c0951acu,
0x0c0951aeu,0x0c0951b0u,0x0c0951b2u,0x0c0951b4u,0x0c0951b6u,0x0c0951b8u,0x0c0951bau,0x0c0951bcu,0x0c0951beu,0x0c0951c0u,0x0c0951c2u,0x0c0951c4u,0x0c0951c6u,0x0c0951c8u,0x0c0951cau,0x0c0951ccu,
0x0c0951ceu,0x0c0951d0u,0x0c0951d2u,0x0c0951d4u,0x0c0951d6u,0x0c0951d8u,0x0c0951dau,0x0c0951dcu,0x0c0951deu,0x0c0951e0u,0x0c0951e2u,0x0c0951e4u,0x0c0951e6u,0x0c0951e8u,0x0c0951eau,0x0c0951ecu,
0x0c0951eeu,0x0c0951f0u,0x0c0951f2u,0x0c0951f4u,0x0c0951f6u,0x0c0951f8u,0x0c0951fau,0x0c0951fcu,0x0c0951feu,0x0c095200u,0x0c095202u,0x0c095204u,0x0c095206u,0x0c095208u,0x0c09520au,0x0c09520cu,
0x0c09520eu,0x0c095210u,0x0c095212u,0x0c095214u,0x0c095216u,0x0c095218u,0x0c09521au,0x0c09521cu,0x0c09521eu,0x0c095220u,0x0c095222u,0x0c095224u,0x0c095226u,0x0c095228u,0x0c09522au,0x0c09522cu,
0x0c09522eu,0x0c095230u,0x0c095232u,0x0c095234u,0x0c095236u,0x0c095238u,0x0c09523au,0x0c09523cu,0x0c09523eu,0x0c095240u,0x0c095242u,0x0c095244u,0x0c095246u,0x0c095248u,0x0c09524au,0x0c095264u,
0x0c095266u,0x0c095268u,0x0c09526au,0x0c09526cu,0x0c09526eu,0x0c095270u,0x0c095272u,0x0c095274u,0x0c095276u,0x0c095278u,0x0c09527au,0x0c09527cu,0x0c09527eu,0x0c095280u,0x0c095282u,0x0c095284u,
0x0c095286u,0x0c095288u,0x0c09528au,0x0c09528cu,0x0c09528eu,0x0c095290u,0x0c095292u,0x0c095294u,0x0c095296u,0x0c095298u,0x0c09529au,0x0c09529cu,0x0c09529eu,0x0c0952a0u,0x0c0952a2u,0x0c0952a4u,
0x0c0952a6u,0x0c0952a8u,0x0c0952aau,0x0c0952acu,0x0c0952aeu,0x0c0952b0u,0x0c0952b2u,0x0c0952b4u,0x0c0952b6u,0x0c0952b8u,0x0c0952bau,0x0c0952bcu,0x0c0952beu,0x0c0952c0u,0x0c0952c2u,0x0c0952c4u,
0x0c0952c6u,0x0c0952c8u,0x0c0952cau,0x0c0952ccu,0x0c0952ceu,0x0c0952d0u,0x0c0952d2u,0x0c0952d4u,0x0c0952d6u,0x0c0952d8u,0x0c0952dau,0x0c0952dcu,0x0c0952deu,0x0c0952e0u,0x0c0952e2u,0x0c0952e4u,
0x0c0952e6u,0x0c0952e8u,0x0c0952eau,0x0c0952ecu,0x0c0952eeu,0x0c0952f0u,0x0c0952f2u,0x0c0952f4u,0x0c0952f6u,0x0c0952f8u,0x0c0952fau,0x0c0952fcu,0x0c0952feu,0x0c095300u,0x0c095302u,0x0c095304u,
0x0c095306u,0x0c095308u,0x0c09530au,0x0c09530cu,0x0c09530eu,0x0c095310u,0x0c095312u,0x0c095314u,0x0c095316u,0x0c095318u,0x0c09531au,0x0c09531cu,0x0c09531eu,0x0c095320u,0x0c095322u,0x0c095324u,
0x0c095326u,0x0c095328u,0x0c0c10a2u,0x0c0c10a4u,0x0c0c10a6u,0x0c0c10a8u,0x0c0c10aau,0x0c0c10acu,0x0c0c10aeu,0x0c0c10b0u,0x0c0c10b2u,0x0c0c10b4u,0x0c0c10b6u,0x0c0c10b8u,0x0c0c10bau,0x0c0c10bcu,
0x0c0c10beu,0x0c0c10c0u,0x0c0c10c2u,0x0c0c10c4u,0x0c0c10c6u,0x0c0c10c8u,0x0c0c10cau,0x0c0c10ccu,0x0c0c10ceu,0x0c0c10d0u,0x0c0c10d2u,0x0c0c10d4u,0x0c0c10d6u,0x0c0c10d8u,0x0c0c10dau,0x0c0c10dcu,
0x0c0c10deu,0x0c0c10e0u,0x0c0c10e2u,0x0c0c10e4u,0x0c0c10e6u,0x0c0c10e8u,0x0c0c10eau,0x0c0c10ecu,0x0c0c10eeu,0x0c0c10f0u,0x0c0c10f2u,0x0c0c10f4u,0x0c0c10f6u,0x0c0c10f8u,0x0c0c10fau,0x0c0c10fcu,
0x0c0c10feu,0x0c0c1100u,0x0c0c1102u,0x0c0c1104u,0x0c0c1106u,0x0c0c1108u,0x0c0c110au,0x0c0c110cu,0x0c0c110eu,0x0c0c1110u,0x0c0c1112u,0x0c0c1114u,0x0c0c1116u,0x0c0c1118u,0x0c0c111au,0x0c0c111cu,
0x0c0c111eu,0x0c0c1120u,0x0c0c1122u,0x0c0c1124u,0x0c0c1126u,0x0c0c1128u,0x0c0c112au,0x0c0c112cu,0x0c0c112eu,0x0c0c1130u,0x0c0c1132u,0x0c0c1134u,0x0c0c1136u,0x0c0c1138u,0x0c0c113au,0x0c0c113cu,
0x0c0c113eu,0x0c0c1140u,0x0c0c1142u,0x0c0c1144u,0x0c0c1146u,0x0c0c1148u,0x0c0c114au,0x0c0c114cu,0x0c0c114eu,0x0c0c1150u,0x0c0c1152u,0x0c0c1154u,0x0c0c1156u,0x0c0c1158u,0x0c0c115au,0x0c0c115cu,
0x0c0c115eu,0x0c0c1160u,0x0c0c1162u,0x0c0c1164u,0x0c0c1166u,0x0c0c1168u,0x0c0c116au,0x0c0c116cu,0x0c0c116eu,0x0c0c1170u,0x0c0c1172u,0x0c0c1174u,0x0c0c1176u,0x0c0c1178u,0x0c0c117au,0x0c0c117cu,
0x0c0c124eu,0x0c0c1250u,0x0c0c1252u,0x0c0c1254u,0x0c0c1256u,0x0c0c1258u,0x0c0c125au,0x0c0c125cu,0x0c0c125eu,0x0c0c1260u,0x0c0c1262u,0x0c0c1264u,0x0c0c1266u,0x0c0c1268u,0x0c0c126au,0x0c0c126cu,
0x0c0c126eu,0x0c0c1270u,0x0c0c1272u,0x0c0c1274u,0x0c0c1276u,0x0c0c1278u,0x0c0c127au,0x0c0c127cu,0x0c0c127eu,0x0c0c1280u,0x0c0c1282u,0x0c0c1284u,0x0c0c1286u,0x0c0c1288u,0x0c0c128au,0x0c0c128cu,
0x0c0c128eu,0x0c0c1290u,0x0c0c1292u,0x0c0c1294u,0x0c0c1296u,0x0c0c1298u,0x0c0c129au,0x0c0c129cu,0x0c0c129eu,0x0c0c12a0u,0x0c0c12a2u,0x0c0c12a4u,0x0c0c12a6u,0x0c0c12a8u,0x0c0c12aau,0x0c0c12acu,
0x0c0c12aeu,0x0c0c12b0u,0x0c0c12b2u,0x0c0c12b4u,0x0c0c12b6u,0x0c0c12b8u,0x0c0c12bau,0x0c0c12bcu,0x0c0c12beu,0x0c0c12c0u,0x0c0c12c2u,0x0c0c12c4u,0x0c0c12c6u,0x0c0c12c8u,0x0c0c12cau,0x0c0c12ccu,
0x0c0c12ceu,0x0c0c12d0u,0x0c0c12d2u,0x0c0c12d4u,0x0c0c12d6u,0x0c0c1fbau,0x0c0c1fbcu,0x0c0c1fbeu,0x0c0c1fc0u,0x0c0c1fc2u,0x0c0c1fc4u,0x0c0c1fc6u,0x0c0c1fc8u,0x0c0c1fcau,0x0c0c1fccu,0x0c0c1fceu,
0x0c0c1fd0u,0x0c0c1fd2u,0x0c0c1fd4u,0x0c0c1fd6u,0x0c0c1fd8u,0x0c0c1fdau,0x0c0c1fdcu,0x0c0c1fdeu,0x0c0c1fe0u,0x0c0c1fe2u,0x0c0c1fe4u,0x0c0c1fe6u,0x0c0c1fe8u,0x0c0c1feau,0x0c0c1fecu,0x0c0c1feeu,
0x0c0c1ff0u,0x0c0c1ff2u,0x0c0c1ff4u,0x0c0c1ff6u,0x0c0c1ff8u,0x0c0c1ffau,0x0c0c1ffcu,0x0c0c1ffeu,0x0c0c2000u,0x0c0c2002u,0x0c0c2004u,0x0c0c2006u,0x0c0c2008u,0x0c0c200au,0x0c0c200cu,0x0c0c200eu,
0x0c0c2010u,0x0c0c2012u,0x0c0c2014u,0x0c0c2016u,0x0c0c2018u,0x0c0c201au,0x0c0c201cu,0x0c0c201eu,0x0c0c2020u,0x0c0c2022u,0x0c0c2024u,0x0c0c2026u,0x0c0c2028u,0x0c0c202au,0x0c0c202cu,0x0c0c202eu,
0x0c0c2030u,0x0c0c2032u,0x0c0c2034u,0x0c0c2036u,0x0c0c2038u,0x0c0c203au,0x0c0c203cu,0x0c0c203eu,0x0c0c2040u,0x0c0c2042u,0x0c0c2044u,0x0c0c2046u,0x0c0c2048u,0x0c0c204au,0x0c0c204cu,0x0c0c204eu,
0x0c0c2050u,0x0c0c2052u,0x0c0c2054u,0x0c0c2056u,0x0c0c2058u,0x0c0c205au,0x0c0c205cu,0x0c0c205eu,0x0c0c2060u,0x0c0c2062u,0x0c0c2064u,0x0c0c2066u,0x0c0c2068u,0x0c0c206au,0x0c0c206cu,0x0c0c206eu,
0x0c0c2070u,0x0c0c2072u,0x0c0c2074u,0x0c0c2076u,0x0c0c2078u,0x0c0c207au,0x0c0c207cu,0x0c0c207eu,0x0c0c2080u,0x0c0c2082u,0x0c0c2084u,0x0c0c2086u,0x0c0c2088u,0x0c0c208au,0x0c0c208cu,0x0c0c208eu,
0x0c0c2090u,0x0c0c2092u,0x0c0c2094u,0x0c0c2096u,0x0c0c2098u,0x0c0c209au,0x0c0c209cu,0x0c0c209eu,0x0c0c20a0u,0x0c0c20a2u,0x0c0c20a4u,0x0c0c20a6u,0x0c0c20a8u,0x0c0c20aau,0x0c0c20acu,0x0c0c20aeu,
0x0c0c20b0u,0x0c0c20b2u,0x0c0c20b4u,0x0c0c20b6u,0x0c0c20b8u,0x0c0c20bau,0x0c0c20bcu,0x0c0c20beu,0x0c0c20c0u,0x0c0c20c2u,0x0c0c20c4u,0x0c0c20c6u,0x0c0c20c8u,0x0c0c20cau,0x0c0c20ccu,0x0c0c20ceu,
0x0c0c20d0u,0x0c0c20d2u,0x0c0c20d4u,0x0c0c20d6u,0x0c0c20d8u,0x0c0c20dau,0x0c0c20dcu,0x0c0c20deu,0x0c0c20e0u,0x0c0c20e2u,0x0c0c20e4u,0x0c0c20e6u,0x0c0c20e8u,0x0c0c20eau,0x0c0c20ecu,0x0c0c20eeu,
0x0c0c20f0u,0x0c0c20f2u,0x0c0c20f4u,0x0c0c20f6u,0x0c0c20f8u,0x0c0c20fau,0x0c0c20fcu,0x0c0c20feu,0x0c0c2100u,0x0c0c2102u,0x0c0c2104u,0x0c0c2106u,0x0c0c2108u,0x0c0c210au,0x0c0c210cu,0x0c0c210eu,
0x0c0c2110u,0x0c0c2112u,0x0c0c2114u,0x0c0c2116u,0x0c0c2118u,0x0c0c211au,0x0c0c211cu,0x0c0c211eu,0x0c0c2120u,0x0c0c2122u,0x0c0c2124u,0x0c0c2126u,0x0c0c2128u,0x0c0c212au,0x0c0c212cu,0x0c0c212eu,
0x0c0c2130u,0x0c0c2132u,0x0c0c2134u,0x0c0c2136u,0x0c0c2138u,0x0c0c213au,0x0c0c213cu,0x0c0c213eu,0x0c0c2140u,0x0c0c2142u,0x0c0c2144u,0x0c0c2146u,0x0c0c2148u,0x0c0c214au,0x0c0c214cu,0x0c0c214eu,
0x0c0c2150u,0x0c0c2152u,0x0c0c2154u,0x0c0c2156u,0x0c0c2158u,0x0c0c215au,0x0c0c215cu,0x0c0c215eu,0x0c0c2160u,0x0c0c2162u,0x0c0c2164u,0x0c0c2166u,0x0c0c2168u,0x0c0c216au,0x0c0c216cu,0x0c0c216eu,
0x0c0c2170u,0x0c0c2172u,0x0c0c2184u,0x0c0c2186u,0x0c0c2188u,0x0c0c218au,0x0c0c218cu,0x0c0c218eu,0x0c0c2190u,0x0c0c2192u,0x0c0c2194u,0x0c0c2196u,0x0c0c2198u,0x0c0c219au,0x0c0c219cu,0x0c0c219eu,
0x0c0c21a0u,0x0c0c21a2u,0x0c0c21a4u,0x0c0c21a6u,0x0c0c21a8u,0x0c0c21aau,0x0c0c21acu,0x0c0c21aeu,0x0c0c21b0u,0x0c0c21b2u,0x0c0c21b4u,0x0c0c21b6u,0x0c0c21b8u,0x0c0c21bau,0x0c0c21bcu,0x0c0c21beu,
0x0c0c21c0u,0x0c0c21c2u,0x0c0c21c4u,0x0c0c21c6u,0x0c0c21c8u,0x0c0c21cau,0x0c0c21ccu,0x0c0c21ceu,0x0c0c21d0u,0x0c0c21d2u,0x0c0c21d4u,0x0c0c21d6u,0x0c0c21d8u,0x0c0c21dau,0x0c0c21dcu,0x0c0c21deu,
0x0c0c21e0u,0x0c0c21e2u,0x0c0c21e4u,0x0c0c21e6u,0x0c0c21e8u,0x0c0c21eau,0x0c0c21ecu,0x0c0c21eeu,0x0c0c21f0u,0x0c0c21f2u,0x0c0c21f4u,0x0c0c21f6u,0x0c0c21f8u,0x0c0c21fau,0x0c0c21fcu,0x0c0c21feu,
0x0c0c2200u,0x0c0c2202u,0x0c0c2204u,0x0c0c2206u,0x0c0c2208u,0x0c0c220au,0x0c0c220cu,0x0c0c220eu,0x0c0c2210u,0x0c0c2212u,0x0c0c2214u,0x0c0c2216u,0x0c0c2218u,0x0c0c221au,0x0c0c221cu,0x0c0c221eu,
0x0c0c2220u,0x0c0c2222u,0x0c0c2224u,0x0c0c2226u,0x0c0c2228u,0x0c0c222au,0x0c0c222cu,0x0c0c222eu,0x0c0c2230u,0x0c0c2232u,0x0c0c2234u,0x0c0c2236u,0x0c0c2238u,0x0c0c223au,0x0c0c223cu,0x0c0c223eu,
0x0c0c2240u,0x0c0c2242u,0x0c0c2244u,0x0c0c6742u,0x0c0c6744u,0x0c0c6746u,0x0c0c6748u,
};
int vf3_seventh_c5_adapter_contains(uint32_t pc) {
pc&=0x1fffffffu; unsigned lo=0,hi=sizeof(owned_pcs)/sizeof(owned_pcs[0]);
while(lo<hi) { unsigned mid=lo+(hi-lo)/2; if(owned_pcs[mid]<pc) lo=mid+1; else hi=mid; }
return lo<sizeof(owned_pcs)/sizeof(owned_pcs[0]) && owned_pcs[lo]==pc;
}
