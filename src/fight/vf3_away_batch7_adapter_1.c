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
int vf3_away_batch7_adapter_1(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c042edeu: goto P_0c042ede;
case 0x0c042ee0u: goto P_0c042ee0;
case 0x0c042ee2u: goto P_0c042ee2;
case 0x0c042ee4u: goto P_0c042ee4;
case 0x0c042ee6u: goto P_0c042ee6;
case 0x0c042ee8u: goto P_0c042ee8;
case 0x0c042eeau: goto P_0c042eea;
case 0x0c042eecu: goto P_0c042eec;
case 0x0c042eeeu: goto P_0c042eee;
case 0x0c042ef0u: goto P_0c042ef0;
case 0x0c042ef2u: goto P_0c042ef2;
case 0x0c042efcu: goto P_0c042efc;
case 0x0c042efeu: goto P_0c042efe;
case 0x0c042f00u: goto P_0c042f00;
case 0x0c042f02u: goto P_0c042f02;
case 0x0c042f04u: goto P_0c042f04;
case 0x0c042f06u: goto P_0c042f06;
case 0x0c043018u: goto P_0c043018;
case 0x0c04301au: goto P_0c04301a;
case 0x0c04301cu: goto P_0c04301c;
case 0x0c04301eu: goto P_0c04301e;
case 0x0c043020u: goto P_0c043020;
case 0x0c043022u: goto P_0c043022;
case 0x0c043024u: goto P_0c043024;
case 0x0c043026u: goto P_0c043026;
case 0x0c043028u: goto P_0c043028;
case 0x0c04302au: goto P_0c04302a;
case 0x0c04302cu: goto P_0c04302c;
case 0x0c04302eu: goto P_0c04302e;
case 0x0c043030u: goto P_0c043030;
case 0x0c043032u: goto P_0c043032;
case 0x0c043034u: goto P_0c043034;
case 0x0c043036u: goto P_0c043036;
case 0x0c043038u: goto P_0c043038;
case 0x0c04303au: goto P_0c04303a;
case 0x0c04303cu: goto P_0c04303c;
case 0x0c04303eu: goto P_0c04303e;
case 0x0c043040u: goto P_0c043040;
case 0x0c043042u: goto P_0c043042;
case 0x0c043044u: goto P_0c043044;
case 0x0c043046u: goto P_0c043046;
case 0x0c043048u: goto P_0c043048;
case 0x0c04304au: goto P_0c04304a;
case 0x0c04304cu: goto P_0c04304c;
case 0x0c04304eu: goto P_0c04304e;
case 0x0c043050u: goto P_0c043050;
case 0x0c043052u: goto P_0c043052;
case 0x0c043054u: goto P_0c043054;
case 0x0c043056u: goto P_0c043056;
case 0x0c043058u: goto P_0c043058;
case 0x0c04305au: goto P_0c04305a;
case 0x0c04305cu: goto P_0c04305c;
case 0x0c04305eu: goto P_0c04305e;
case 0x0c043060u: goto P_0c043060;
case 0x0c04b9e4u: goto P_0c04b9e4;
case 0x0c04b9e6u: goto P_0c04b9e6;
case 0x0c04b9e8u: goto P_0c04b9e8;
case 0x0c04b9eau: goto P_0c04b9ea;
case 0x0c04b9ecu: goto P_0c04b9ec;
case 0x0c04b9eeu: goto P_0c04b9ee;
case 0x0c04b9f0u: goto P_0c04b9f0;
case 0x0c04b9f2u: goto P_0c04b9f2;
case 0x0c04b9f4u: goto P_0c04b9f4;
case 0x0c04b9f6u: goto P_0c04b9f6;
case 0x0c04b9f8u: goto P_0c04b9f8;
case 0x0c04b9fau: goto P_0c04b9fa;
case 0x0c0541ecu: goto P_0c0541ec;
case 0x0c0541eeu: goto P_0c0541ee;
case 0x0c0541f0u: goto P_0c0541f0;
case 0x0c0541f2u: goto P_0c0541f2;
case 0x0c0541f4u: goto P_0c0541f4;
case 0x0c0541f6u: goto P_0c0541f6;
case 0x0c0541f8u: goto P_0c0541f8;
case 0x0c0541fau: goto P_0c0541fa;
case 0x0c0541fcu: goto P_0c0541fc;
case 0x0c0541feu: goto P_0c0541fe;
case 0x0c054200u: goto P_0c054200;
case 0x0c054202u: goto P_0c054202;
case 0x0c054204u: goto P_0c054204;
case 0x0c054206u: goto P_0c054206;
case 0x0c054208u: goto P_0c054208;
case 0x0c05420au: goto P_0c05420a;
case 0x0c05420cu: goto P_0c05420c;
case 0x0c05420eu: goto P_0c05420e;
case 0x0c054210u: goto P_0c054210;
case 0x0c054212u: goto P_0c054212;
case 0x0c054214u: goto P_0c054214;
case 0x0c054216u: goto P_0c054216;
case 0x0c054218u: goto P_0c054218;
case 0x0c05421au: goto P_0c05421a;
case 0x0c05421cu: goto P_0c05421c;
case 0x0c05421eu: goto P_0c05421e;
case 0x0c054220u: goto P_0c054220;
case 0x0c054222u: goto P_0c054222;
case 0x0c054224u: goto P_0c054224;
case 0x0c054226u: goto P_0c054226;
case 0x0c054228u: goto P_0c054228;
case 0x0c05422au: goto P_0c05422a;
case 0x0c05422cu: goto P_0c05422c;
case 0x0c05422eu: goto P_0c05422e;
case 0x0c054230u: goto P_0c054230;
case 0x0c054232u: goto P_0c054232;
case 0x0c054234u: goto P_0c054234;
case 0x0c054236u: goto P_0c054236;
case 0x0c054238u: goto P_0c054238;
case 0x0c05423au: goto P_0c05423a;
case 0x0c05423cu: goto P_0c05423c;
case 0x0c05423eu: goto P_0c05423e;
case 0x0c054240u: goto P_0c054240;
case 0x0c054c1cu: goto P_0c054c1c;
case 0x0c054c1eu: goto P_0c054c1e;
case 0x0c054c20u: goto P_0c054c20;
case 0x0c054c22u: goto P_0c054c22;
case 0x0c054c24u: goto P_0c054c24;
case 0x0c054c26u: goto P_0c054c26;
case 0x0c054c28u: goto P_0c054c28;
case 0x0c054c2au: goto P_0c054c2a;
case 0x0c054c2cu: goto P_0c054c2c;
case 0x0c054c2eu: goto P_0c054c2e;
case 0x0c054c30u: goto P_0c054c30;
case 0x0c054c32u: goto P_0c054c32;
case 0x0c054c34u: goto P_0c054c34;
case 0x0c054c36u: goto P_0c054c36;
case 0x0c054c38u: goto P_0c054c38;
case 0x0c054c3au: goto P_0c054c3a;
case 0x0c054c3cu: goto P_0c054c3c;
case 0x0c054c3eu: goto P_0c054c3e;
case 0x0c054c40u: goto P_0c054c40;
case 0x0c054c42u: goto P_0c054c42;
case 0x0c054c44u: goto P_0c054c44;
case 0x0c054c46u: goto P_0c054c46;
case 0x0c054c48u: goto P_0c054c48;
case 0x0c054c4au: goto P_0c054c4a;
case 0x0c054c4cu: goto P_0c054c4c;
case 0x0c054c4eu: goto P_0c054c4e;
case 0x0c054c50u: goto P_0c054c50;
case 0x0c054c52u: goto P_0c054c52;
case 0x0c054c54u: goto P_0c054c54;
case 0x0c054c56u: goto P_0c054c56;
case 0x0c054c58u: goto P_0c054c58;
case 0x0c054c5au: goto P_0c054c5a;
case 0x0c054c5cu: goto P_0c054c5c;
case 0x0c054c5eu: goto P_0c054c5e;
case 0x0c054c60u: goto P_0c054c60;
case 0x0c054c62u: goto P_0c054c62;
case 0x0c054c64u: goto P_0c054c64;
case 0x0c054c66u: goto P_0c054c66;
case 0x0c054c68u: goto P_0c054c68;
case 0x0c054c6au: goto P_0c054c6a;
case 0x0c054c6cu: goto P_0c054c6c;
case 0x0c054c6eu: goto P_0c054c6e;
case 0x0c054c70u: goto P_0c054c70;
case 0x0c054c72u: goto P_0c054c72;
case 0x0c054c74u: goto P_0c054c74;
case 0x0c054c76u: goto P_0c054c76;
case 0x0c054c78u: goto P_0c054c78;
case 0x0c054c7au: goto P_0c054c7a;
case 0x0c054c7cu: goto P_0c054c7c;
case 0x0c054c7eu: goto P_0c054c7e;
case 0x0c054c80u: goto P_0c054c80;
case 0x0c054c82u: goto P_0c054c82;
case 0x0c054c84u: goto P_0c054c84;
case 0x0c054c86u: goto P_0c054c86;
case 0x0c054c88u: goto P_0c054c88;
case 0x0c054c8au: goto P_0c054c8a;
case 0x0c054c8cu: goto P_0c054c8c;
case 0x0c054c8eu: goto P_0c054c8e;
case 0x0c054c90u: goto P_0c054c90;
case 0x0c054c92u: goto P_0c054c92;
case 0x0c054c94u: goto P_0c054c94;
case 0x0c054c96u: goto P_0c054c96;
case 0x0c054c98u: goto P_0c054c98;
case 0x0c054c9au: goto P_0c054c9a;
case 0x0c054c9cu: goto P_0c054c9c;
case 0x0c054c9eu: goto P_0c054c9e;
case 0x0c054ca0u: goto P_0c054ca0;
case 0x0c054ca2u: goto P_0c054ca2;
case 0x0c054ca4u: goto P_0c054ca4;
case 0x0c054ca6u: goto P_0c054ca6;
case 0x0c054ca8u: goto P_0c054ca8;
case 0x0c054caau: goto P_0c054caa;
case 0x0c054cacu: goto P_0c054cac;
case 0x0c054caeu: goto P_0c054cae;
case 0x0c054cb0u: goto P_0c054cb0;
case 0x0c054cb2u: goto P_0c054cb2;
case 0x0c054cb4u: goto P_0c054cb4;
case 0x0c054cb6u: goto P_0c054cb6;
case 0x0c054cb8u: goto P_0c054cb8;
case 0x0c054cbau: goto P_0c054cba;
case 0x0c054cbcu: goto P_0c054cbc;
case 0x0c054cbeu: goto P_0c054cbe;
case 0x0c054cc0u: goto P_0c054cc0;
case 0x0c054cc2u: goto P_0c054cc2;
case 0x0c054cc4u: goto P_0c054cc4;
case 0x0c054cc6u: goto P_0c054cc6;
case 0x0c054cc8u: goto P_0c054cc8;
case 0x0c054ce6u: goto P_0c054ce6;
case 0x0c054ce8u: goto P_0c054ce8;
case 0x0c054ceau: goto P_0c054cea;
case 0x0c054cecu: goto P_0c054cec;
case 0x0c054ceeu: goto P_0c054cee;
case 0x0c054cf0u: goto P_0c054cf0;
case 0x0c054cf2u: goto P_0c054cf2;
case 0x0c054cf4u: goto P_0c054cf4;
case 0x0c054cf6u: goto P_0c054cf6;
case 0x0c054cf8u: goto P_0c054cf8;
case 0x0c054cfau: goto P_0c054cfa;
case 0x0c054cfcu: goto P_0c054cfc;
case 0x0c054cfeu: goto P_0c054cfe;
case 0x0c054d00u: goto P_0c054d00;
case 0x0c054d02u: goto P_0c054d02;
case 0x0c054d04u: goto P_0c054d04;
case 0x0c054d06u: goto P_0c054d06;
case 0x0c054d08u: goto P_0c054d08;
case 0x0c054d0au: goto P_0c054d0a;
case 0x0c054d0cu: goto P_0c054d0c;
case 0x0c054d0eu: goto P_0c054d0e;
case 0x0c054d10u: goto P_0c054d10;
case 0x0c054d12u: goto P_0c054d12;
case 0x0c054d14u: goto P_0c054d14;
case 0x0c054d16u: goto P_0c054d16;
case 0x0c054d18u: goto P_0c054d18;
case 0x0c054d1au: goto P_0c054d1a;
case 0x0c054d1cu: goto P_0c054d1c;
case 0x0c054d1eu: goto P_0c054d1e;
case 0x0c054d20u: goto P_0c054d20;
case 0x0c054d22u: goto P_0c054d22;
case 0x0c054d24u: goto P_0c054d24;
case 0x0c054d26u: goto P_0c054d26;
case 0x0c054d28u: goto P_0c054d28;
case 0x0c054d2au: goto P_0c054d2a;
case 0x0c054d2cu: goto P_0c054d2c;
case 0x0c054d2eu: goto P_0c054d2e;
case 0x0c054d30u: goto P_0c054d30;
case 0x0c054d32u: goto P_0c054d32;
case 0x0c054d34u: goto P_0c054d34;
case 0x0c054d36u: goto P_0c054d36;
case 0x0c054d38u: goto P_0c054d38;
case 0x0c054d3au: goto P_0c054d3a;
case 0x0c054d3cu: goto P_0c054d3c;
case 0x0c054d3eu: goto P_0c054d3e;
case 0x0c054d40u: goto P_0c054d40;
case 0x0c054d42u: goto P_0c054d42;
case 0x0c054d44u: goto P_0c054d44;
case 0x0c054d46u: goto P_0c054d46;
case 0x0c054d48u: goto P_0c054d48;
case 0x0c054d4au: goto P_0c054d4a;
case 0x0c054d4cu: goto P_0c054d4c;
case 0x0c054d4eu: goto P_0c054d4e;
case 0x0c054d50u: goto P_0c054d50;
case 0x0c054d52u: goto P_0c054d52;
case 0x0c054d54u: goto P_0c054d54;
case 0x0c054d56u: goto P_0c054d56;
case 0x0c054d58u: goto P_0c054d58;
case 0x0c054d5au: goto P_0c054d5a;
case 0x0c054d5cu: goto P_0c054d5c;
case 0x0c054d5eu: goto P_0c054d5e;
case 0x0c054d60u: goto P_0c054d60;
case 0x0c054d62u: goto P_0c054d62;
case 0x0c054d64u: goto P_0c054d64;
case 0x0c054d66u: goto P_0c054d66;
case 0x0c054d68u: goto P_0c054d68;
case 0x0c054d6au: goto P_0c054d6a;
case 0x0c054d6cu: goto P_0c054d6c;
case 0x0c054d6eu: goto P_0c054d6e;
case 0x0c054d70u: goto P_0c054d70;
case 0x0c054d72u: goto P_0c054d72;
case 0x0c054d74u: goto P_0c054d74;
case 0x0c054d76u: goto P_0c054d76;
case 0x0c054d78u: goto P_0c054d78;
case 0x0c054d7au: goto P_0c054d7a;
case 0x0c054d7cu: goto P_0c054d7c;
case 0x0c054d7eu: goto P_0c054d7e;
case 0x0c054d80u: goto P_0c054d80;
case 0x0c054d82u: goto P_0c054d82;
case 0x0c054d84u: goto P_0c054d84;
case 0x0c054d86u: goto P_0c054d86;
case 0x0c054d88u: goto P_0c054d88;
case 0x0c054d8au: goto P_0c054d8a;
case 0x0c054d8cu: goto P_0c054d8c;
case 0x0c054d8eu: goto P_0c054d8e;
case 0x0c054d90u: goto P_0c054d90;
case 0x0c054d92u: goto P_0c054d92;
case 0x0c054d94u: goto P_0c054d94;
case 0x0c054d96u: goto P_0c054d96;
case 0x0c054d98u: goto P_0c054d98;
case 0x0c054d9au: goto P_0c054d9a;
case 0x0c054d9cu: goto P_0c054d9c;
case 0x0c054d9eu: goto P_0c054d9e;
case 0x0c054da0u: goto P_0c054da0;
case 0x0c054da2u: goto P_0c054da2;
case 0x0c054da4u: goto P_0c054da4;
case 0x0c054da6u: goto P_0c054da6;
case 0x0c054da8u: goto P_0c054da8;
case 0x0c054daau: goto P_0c054daa;
case 0x0c054dacu: goto P_0c054dac;
case 0x0c054daeu: goto P_0c054dae;
case 0x0c054db0u: goto P_0c054db0;
case 0x0c054db2u: goto P_0c054db2;
case 0x0c054db4u: goto P_0c054db4;
case 0x0c054db6u: goto P_0c054db6;
case 0x0c054db8u: goto P_0c054db8;
case 0x0c054dbau: goto P_0c054dba;
case 0x0c054dbcu: goto P_0c054dbc;
case 0x0c054dbeu: goto P_0c054dbe;
case 0x0c054dc0u: goto P_0c054dc0;
case 0x0c054dc2u: goto P_0c054dc2;
case 0x0c054dc4u: goto P_0c054dc4;
case 0x0c054dc6u: goto P_0c054dc6;
case 0x0c054dc8u: goto P_0c054dc8;
case 0x0c054dcau: goto P_0c054dca;
case 0x0c054dccu: goto P_0c054dcc;
case 0x0c054dceu: goto P_0c054dce;
case 0x0c054dd0u: goto P_0c054dd0;
case 0x0c054dd2u: goto P_0c054dd2;
case 0x0c054dd4u: goto P_0c054dd4;
case 0x0c054dd6u: goto P_0c054dd6;
case 0x0c054dd8u: goto P_0c054dd8;
case 0x0c054ddau: goto P_0c054dda;
case 0x0c054ddcu: goto P_0c054ddc;
case 0x0c054ddeu: goto P_0c054dde;
case 0x0c054de0u: goto P_0c054de0;
case 0x0c054de2u: goto P_0c054de2;
case 0x0c054de4u: goto P_0c054de4;
case 0x0c054de6u: goto P_0c054de6;
case 0x0c054de8u: goto P_0c054de8;
case 0x0c054deau: goto P_0c054dea;
case 0x0c054decu: goto P_0c054dec;
case 0x0c054deeu: goto P_0c054dee;
case 0x0c054df0u: goto P_0c054df0;
case 0x0c054df2u: goto P_0c054df2;
case 0x0c054df4u: goto P_0c054df4;
case 0x0c054df6u: goto P_0c054df6;
case 0x0c054df8u: goto P_0c054df8;
case 0x0c054dfau: goto P_0c054dfa;
case 0x0c054dfcu: goto P_0c054dfc;
case 0x0c054dfeu: goto P_0c054dfe;
case 0x0c054e00u: goto P_0c054e00;
case 0x0c054e02u: goto P_0c054e02;
case 0x0c054e04u: goto P_0c054e04;
case 0x0c054e06u: goto P_0c054e06;
case 0x0c054e08u: goto P_0c054e08;
case 0x0c054e0au: goto P_0c054e0a;
case 0x0c054e0cu: goto P_0c054e0c;
case 0x0c054e0eu: goto P_0c054e0e;
case 0x0c054e10u: goto P_0c054e10;
case 0x0c054e12u: goto P_0c054e12;
case 0x0c054e14u: goto P_0c054e14;
case 0x0c054e16u: goto P_0c054e16;
case 0x0c054e18u: goto P_0c054e18;
case 0x0c054e1au: goto P_0c054e1a;
case 0x0c054e1cu: goto P_0c054e1c;
case 0x0c054e1eu: goto P_0c054e1e;
case 0x0c054e20u: goto P_0c054e20;
case 0x0c054e22u: goto P_0c054e22;
case 0x0c054e24u: goto P_0c054e24;
case 0x0c054e26u: goto P_0c054e26;
case 0x0c054e28u: goto P_0c054e28;
case 0x0c054e2au: goto P_0c054e2a;
case 0x0c054e2cu: goto P_0c054e2c;
case 0x0c054e2eu: goto P_0c054e2e;
case 0x0c054e30u: goto P_0c054e30;
case 0x0c054e32u: goto P_0c054e32;
case 0x0c054e34u: goto P_0c054e34;
case 0x0c054e36u: goto P_0c054e36;
case 0x0c054e38u: goto P_0c054e38;
case 0x0c054e3au: goto P_0c054e3a;
case 0x0c054e3cu: goto P_0c054e3c;
case 0x0c054e3eu: goto P_0c054e3e;
case 0x0c054e40u: goto P_0c054e40;
case 0x0c054e42u: goto P_0c054e42;
case 0x0c054e44u: goto P_0c054e44;
case 0x0c054e46u: goto P_0c054e46;
case 0x0c054e48u: goto P_0c054e48;
case 0x0c054e4au: goto P_0c054e4a;
case 0x0c054e4cu: goto P_0c054e4c;
case 0x0c054e4eu: goto P_0c054e4e;
case 0x0c054e50u: goto P_0c054e50;
case 0x0c054e52u: goto P_0c054e52;
case 0x0c054e54u: goto P_0c054e54;
case 0x0c054e56u: goto P_0c054e56;
case 0x0c054e58u: goto P_0c054e58;
case 0x0c054e5au: goto P_0c054e5a;
case 0x0c054e5cu: goto P_0c054e5c;
case 0x0c054e5eu: goto P_0c054e5e;
case 0x0c054e60u: goto P_0c054e60;
case 0x0c054e62u: goto P_0c054e62;
case 0x0c054e64u: goto P_0c054e64;
case 0x0c054e66u: goto P_0c054e66;
case 0x0c054e68u: goto P_0c054e68;
case 0x0c054e6au: goto P_0c054e6a;
case 0x0c054e6cu: goto P_0c054e6c;
case 0x0c054e6eu: goto P_0c054e6e;
case 0x0c054e70u: goto P_0c054e70;
case 0x0c054e72u: goto P_0c054e72;
case 0x0c054e74u: goto P_0c054e74;
case 0x0c054e76u: goto P_0c054e76;
case 0x0c054e78u: goto P_0c054e78;
case 0x0c054e7au: goto P_0c054e7a;
case 0x0c054e7cu: goto P_0c054e7c;
case 0x0c054e7eu: goto P_0c054e7e;
case 0x0c054e80u: goto P_0c054e80;
case 0x0c054e82u: goto P_0c054e82;
case 0x0c054e84u: goto P_0c054e84;
case 0x0c054e86u: goto P_0c054e86;
case 0x0c054e88u: goto P_0c054e88;
case 0x0c054e8au: goto P_0c054e8a;
case 0x0c054e8cu: goto P_0c054e8c;
case 0x0c054e8eu: goto P_0c054e8e;
case 0x0c054e90u: goto P_0c054e90;
case 0x0c054e92u: goto P_0c054e92;
case 0x0c054e94u: goto P_0c054e94;
case 0x0c054e96u: goto P_0c054e96;
case 0x0c054e98u: goto P_0c054e98;
case 0x0c054e9au: goto P_0c054e9a;
case 0x0c054e9cu: goto P_0c054e9c;
case 0x0c054e9eu: goto P_0c054e9e;
case 0x0c054ea0u: goto P_0c054ea0;
case 0x0c054ea2u: goto P_0c054ea2;
case 0x0c054ea4u: goto P_0c054ea4;
case 0x0c054ea6u: goto P_0c054ea6;
case 0x0c054ea8u: goto P_0c054ea8;
case 0x0c054eaau: goto P_0c054eaa;
case 0x0c054eacu: goto P_0c054eac;
case 0x0c054eaeu: goto P_0c054eae;
case 0x0c054eb0u: goto P_0c054eb0;
case 0x0c054eb2u: goto P_0c054eb2;
case 0x0c054eb4u: goto P_0c054eb4;
case 0x0c054eb6u: goto P_0c054eb6;
case 0x0c054eb8u: goto P_0c054eb8;
case 0x0c054ebau: goto P_0c054eba;
case 0x0c054ebcu: goto P_0c054ebc;
case 0x0c054ebeu: goto P_0c054ebe;
case 0x0c054ec0u: goto P_0c054ec0;
case 0x0c054ec2u: goto P_0c054ec2;
case 0x0c054ec4u: goto P_0c054ec4;
case 0x0c054ec6u: goto P_0c054ec6;
case 0x0c054ec8u: goto P_0c054ec8;
case 0x0c054ecau: goto P_0c054eca;
default: return vf3_matrix_family(target,s,ram);
}
P_0c042ede: /* original 303c, guest PC 0x0c042ede */
if(!s->budget--) { s->failed_pc=0x0c042edeu; return 0; }
r[0]+=r[3];
goto P_0c042ee0;
P_0c042ee0: /* original 64f6, guest PC 0x0c042ee0 */
if(!s->budget--) { s->failed_pc=0x0c042ee0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[4]=tmp;
goto P_0c042ee2;
P_0c042ee2: /* original 000b, guest PC 0x0c042ee2 */
if(!s->budget--) { s->failed_pc=0x0c042ee2u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[3]=tmp;
s->pc=target; return ram->oob==0;
P_0c042ee4: /* original 63f6, guest PC 0x0c042ee4 */
if(!s->budget--) { s->failed_pc=0x0c042ee4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[3]=tmp;
goto P_0c042ee6;
P_0c042ee6: /* original 2f26, guest PC 0x0c042ee6 */
if(!s->budget--) { s->failed_pc=0x0c042ee6u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c042ee8;
P_0c042ee8: /* original d102, guest PC 0x0c042ee8 */
if(!s->budget--) { s->failed_pc=0x0c042ee8u; return 0; }
r[1]=read(ram,0x0c042ef4u,4);
goto P_0c042eea;
P_0c042eea: /* original d203, guest PC 0x0c042eea */
if(!s->budget--) { s->failed_pc=0x0c042eeau; return 0; }
r[2]=read(ram,0x0c042ef8u,4);
goto P_0c042eec;
P_0c042eec: /* original e000, guest PC 0x0c042eec */
if(!s->budget--) { s->failed_pc=0x0c042eecu; return 0; }
r[0]=0x00000000u;
goto P_0c042eee;
P_0c042eee: /* original 2122, guest PC 0x0c042eee */
if(!s->budget--) { s->failed_pc=0x0c042eeeu; return 0; }
write(ram,r[1],r[2],4);
goto P_0c042ef0;
P_0c042ef0: /* original 000b, guest PC 0x0c042ef0 */
if(!s->budget--) { s->failed_pc=0x0c042ef0u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[2]=tmp;
s->pc=target; return ram->oob==0;
P_0c042ef2: /* original 62f6, guest PC 0x0c042ef2 */
if(!s->budget--) { s->failed_pc=0x0c042ef2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[2]=tmp;
if(!vf3_matrix_family(0x0c042ef4u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c042ef4u; return 0; } return 1;
P_0c042efc: /* original 2f36, guest PC 0x0c042efc */
if(!s->budget--) { s->failed_pc=0x0c042efcu; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c042efe;
P_0c042efe: /* original d305, guest PC 0x0c042efe */
if(!s->budget--) { s->failed_pc=0x0c042efeu; return 0; }
r[3]=read(ram,0x0c042f14u,4);
goto P_0c042f00;
P_0c042f00: /* original 033e, guest PC 0x0c042f00 */
if(!s->budget--) { s->failed_pc=0x0c042f00u; return 0; }
r[3]=read(ram,r[3]+r[0],4);
goto P_0c042f02;
P_0c042f02: /* original 70fc, guest PC 0x0c042f02 */
if(!s->budget--) { s->failed_pc=0x0c042f02u; return 0; }
r[0]+=0xfffffffcu;
goto P_0c042f04;
P_0c042f04: /* original 432b, guest PC 0x0c042f04 */
if(!s->budget--) { s->failed_pc=0x0c042f04u; return 0; }
target=r[3];
r[0]=read(ram,r[2]+r[0],4);
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
P_0c042f06: /* original 002e, guest PC 0x0c042f06 */
if(!s->budget--) { s->failed_pc=0x0c042f06u; return 0; }
r[0]=read(ram,r[2]+r[0],4);
if(!vf3_matrix_family(0x0c042f08u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c042f08u; return 0; } return 1;
P_0c043018: /* original 3450, guest PC 0x0c043018 */
if(!s->budget--) { s->failed_pc=0x0c043018u; return 0; }
r[17]=(r[17]&~1u)|((r[4]==r[5])!=0);
goto P_0c04301a;
P_0c04301a: /* original 8d20, guest PC 0x0c04301a */
if(!s->budget--) { s->failed_pc=0x0c04301au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04305e; }
goto P_0c04301e;
P_0c04301c: /* original 0009, guest PC 0x0c04301c */
if(!s->budget--) { s->failed_pc=0x0c04301cu; return 0; }
goto P_0c04301e;
P_0c04301e: /* original 3452, guest PC 0x0c04301e */
if(!s->budget--) { s->failed_pc=0x0c04301eu; return 0; }
r[17]=(r[17]&~1u)|((r[4]>=r[5])!=0);
goto P_0c043020;
P_0c043020: /* original 8d0e, guest PC 0x0c043020 */
if(!s->budget--) { s->failed_pc=0x0c043020u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c043040; }
goto P_0c043024;
P_0c043022: /* original 0009, guest PC 0x0c043022 */
if(!s->budget--) { s->failed_pc=0x0c043022u; return 0; }
goto P_0c043024;
P_0c043024: /* original 6753, guest PC 0x0c043024 */
if(!s->budget--) { s->failed_pc=0x0c043024u; return 0; }
r[7]=r[5];
goto P_0c043026;
P_0c043026: /* original e500, guest PC 0x0c043026 */
if(!s->budget--) { s->failed_pc=0x0c043026u; return 0; }
r[5]=0x00000000u;
goto P_0c043028;
P_0c043028: /* original 6353, guest PC 0x0c043028 */
if(!s->budget--) { s->failed_pc=0x0c043028u; return 0; }
r[3]=r[5];
goto P_0c04302a;
P_0c04302a: /* original 3362, guest PC 0x0c04302a */
if(!s->budget--) { s->failed_pc=0x0c04302au; return 0; }
r[17]=(r[17]&~1u)|((r[3]>=r[6])!=0);
goto P_0c04302c;
P_0c04302c: /* original 8d17, guest PC 0x0c04302c */
if(!s->budget--) { s->failed_pc=0x0c04302cu; return 0; }
cond=r[17]&1u;
r[0]=r[4];
if(cond) { goto P_0c04305e; }
goto P_0c043030;
P_0c04302e: /* original 6043, guest PC 0x0c04302e */
if(!s->budget--) { s->failed_pc=0x0c04302eu; return 0; }
r[0]=r[4];
goto P_0c043030;
P_0c043030: /* original 6374, guest PC 0x0c043030 */
if(!s->budget--) { s->failed_pc=0x0c043030u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[7],1);
r[7]+=1;
r[3]=tmp;
goto P_0c043032;
P_0c043032: /* original 7501, guest PC 0x0c043032 */
if(!s->budget--) { s->failed_pc=0x0c043032u; return 0; }
r[5]+=0x00000001u;
goto P_0c043034;
P_0c043034: /* original 2030, guest PC 0x0c043034 */
if(!s->budget--) { s->failed_pc=0x0c043034u; return 0; }
write(ram,r[0],r[3],1);
goto P_0c043036;
P_0c043036: /* original 3562, guest PC 0x0c043036 */
if(!s->budget--) { s->failed_pc=0x0c043036u; return 0; }
r[17]=(r[17]&~1u)|((r[5]>=r[6])!=0);
goto P_0c043038;
P_0c043038: /* original 8ffa, guest PC 0x0c043038 */
if(!s->budget--) { s->failed_pc=0x0c043038u; return 0; }
cond=r[17]&1u;
r[0]+=0x00000001u;
if(!cond) { goto P_0c043030; }
goto P_0c04303c;
P_0c04303a: /* original 7001, guest PC 0x0c04303a */
if(!s->budget--) { s->failed_pc=0x0c04303au; return 0; }
r[0]+=0x00000001u;
goto P_0c04303c;
P_0c04303c: /* original a00f, guest PC 0x0c04303c */
if(!s->budget--) { s->failed_pc=0x0c04303cu; return 0; }
goto P_0c04305e;
P_0c04303e: /* original 0009, guest PC 0x0c04303e */
if(!s->budget--) { s->failed_pc=0x0c04303eu; return 0; }
goto P_0c043040;
P_0c043040: /* original 6743, guest PC 0x0c043040 */
if(!s->budget--) { s->failed_pc=0x0c043040u; return 0; }
r[7]=r[4];
goto P_0c043042;
P_0c043042: /* original 376c, guest PC 0x0c043042 */
if(!s->budget--) { s->failed_pc=0x0c043042u; return 0; }
r[7]+=r[6];
goto P_0c043044;
P_0c043044: /* original 6053, guest PC 0x0c043044 */
if(!s->budget--) { s->failed_pc=0x0c043044u; return 0; }
r[0]=r[5];
goto P_0c043046;
P_0c043046: /* original 0009, guest PC 0x0c043046 */
if(!s->budget--) { s->failed_pc=0x0c043046u; return 0; }
goto P_0c043048;
P_0c043048: /* original e500, guest PC 0x0c043048 */
if(!s->budget--) { s->failed_pc=0x0c043048u; return 0; }
r[5]=0x00000000u;
goto P_0c04304a;
P_0c04304a: /* original 6253, guest PC 0x0c04304a */
if(!s->budget--) { s->failed_pc=0x0c04304au; return 0; }
r[2]=r[5];
goto P_0c04304c;
P_0c04304c: /* original 3262, guest PC 0x0c04304c */
if(!s->budget--) { s->failed_pc=0x0c04304cu; return 0; }
r[17]=(r[17]&~1u)|((r[2]>=r[6])!=0);
goto P_0c04304e;
P_0c04304e: /* original 8d06, guest PC 0x0c04304e */
if(!s->budget--) { s->failed_pc=0x0c04304eu; return 0; }
cond=r[17]&1u;
r[0]+=r[6];
if(cond) { goto P_0c04305e; }
goto P_0c043052;
P_0c043050: /* original 306c, guest PC 0x0c043050 */
if(!s->budget--) { s->failed_pc=0x0c043050u; return 0; }
r[0]+=r[6];
goto P_0c043052;
P_0c043052: /* original 70ff, guest PC 0x0c043052 */
if(!s->budget--) { s->failed_pc=0x0c043052u; return 0; }
r[0]+=0xffffffffu;
goto P_0c043054;
P_0c043054: /* original 6300, guest PC 0x0c043054 */
if(!s->budget--) { s->failed_pc=0x0c043054u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[0],1);
r[3]=tmp;
goto P_0c043056;
P_0c043056: /* original 7501, guest PC 0x0c043056 */
if(!s->budget--) { s->failed_pc=0x0c043056u; return 0; }
r[5]+=0x00000001u;
goto P_0c043058;
P_0c043058: /* original 3562, guest PC 0x0c043058 */
if(!s->budget--) { s->failed_pc=0x0c043058u; return 0; }
r[17]=(r[17]&~1u)|((r[5]>=r[6])!=0);
goto P_0c04305a;
P_0c04305a: /* original 8ffa, guest PC 0x0c04305a */
if(!s->budget--) { s->failed_pc=0x0c04305au; return 0; }
cond=r[17]&1u;
tmp=r[3]; r[7]-=1; write(ram,r[7],tmp,1);
if(!cond) { goto P_0c043052; }
goto P_0c04305e;
P_0c04305c: /* original 2734, guest PC 0x0c04305c */
if(!s->budget--) { s->failed_pc=0x0c04305cu; return 0; }
tmp=r[3]; r[7]-=1; write(ram,r[7],tmp,1);
goto P_0c04305e;
P_0c04305e: /* original 000b, guest PC 0x0c04305e */
if(!s->budget--) { s->failed_pc=0x0c04305eu; return 0; }
target=r[16];
r[0]=r[4];
s->pc=target; return ram->oob==0;
P_0c043060: /* original 6043, guest PC 0x0c043060 */
if(!s->budget--) { s->failed_pc=0x0c043060u; return 0; }
r[0]=r[4];
if(!vf3_matrix_family(0x0c043062u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c043062u; return 0; } return 1;
P_0c04b9e4: /* original e700, guest PC 0x0c04b9e4 */
if(!s->budget--) { s->failed_pc=0x0c04b9e4u; return 0; }
r[7]=0x00000000u;
goto P_0c04b9e6;
P_0c04b9e6: /* original 6373, guest PC 0x0c04b9e6 */
if(!s->budget--) { s->failed_pc=0x0c04b9e6u; return 0; }
r[3]=r[7];
goto P_0c04b9e8;
P_0c04b9e8: /* original 3362, guest PC 0x0c04b9e8 */
if(!s->budget--) { s->failed_pc=0x0c04b9e8u; return 0; }
r[17]=(r[17]&~1u)|((r[3]>=r[6])!=0);
goto P_0c04b9ea;
P_0c04b9ea: /* original 8d05, guest PC 0x0c04b9ea */
if(!s->budget--) { s->failed_pc=0x0c04b9eau; return 0; }
cond=r[17]&1u;
r[0]=r[4];
if(cond) { goto P_0c04b9f8; }
goto P_0c04b9ee;
P_0c04b9ec: /* original 6043, guest PC 0x0c04b9ec */
if(!s->budget--) { s->failed_pc=0x0c04b9ecu; return 0; }
r[0]=r[4];
goto P_0c04b9ee;
P_0c04b9ee: /* original 7701, guest PC 0x0c04b9ee */
if(!s->budget--) { s->failed_pc=0x0c04b9eeu; return 0; }
r[7]+=0x00000001u;
goto P_0c04b9f0;
P_0c04b9f0: /* original 2050, guest PC 0x0c04b9f0 */
if(!s->budget--) { s->failed_pc=0x0c04b9f0u; return 0; }
write(ram,r[0],r[5],1);
goto P_0c04b9f2;
P_0c04b9f2: /* original 3762, guest PC 0x0c04b9f2 */
if(!s->budget--) { s->failed_pc=0x0c04b9f2u; return 0; }
r[17]=(r[17]&~1u)|((r[7]>=r[6])!=0);
goto P_0c04b9f4;
P_0c04b9f4: /* original 8ffb, guest PC 0x0c04b9f4 */
if(!s->budget--) { s->failed_pc=0x0c04b9f4u; return 0; }
cond=r[17]&1u;
r[0]+=0x00000001u;
if(!cond) { goto P_0c04b9ee; }
goto P_0c04b9f8;
P_0c04b9f6: /* original 7001, guest PC 0x0c04b9f6 */
if(!s->budget--) { s->failed_pc=0x0c04b9f6u; return 0; }
r[0]+=0x00000001u;
goto P_0c04b9f8;
P_0c04b9f8: /* original 000b, guest PC 0x0c04b9f8 */
if(!s->budget--) { s->failed_pc=0x0c04b9f8u; return 0; }
target=r[16];
r[0]=r[4];
s->pc=target; return ram->oob==0;
P_0c04b9fa: /* original 6043, guest PC 0x0c04b9fa */
if(!s->budget--) { s->failed_pc=0x0c04b9fau; return 0; }
r[0]=r[4];
if(!vf3_matrix_family(0x0c04b9fcu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c04b9fcu; return 0; } return 1;
P_0c0541ec: /* original 2fe6, guest PC 0x0c0541ec */
if(!s->budget--) { s->failed_pc=0x0c0541ecu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0541ee;
P_0c0541ee: /* original e708, guest PC 0x0c0541ee */
if(!s->budget--) { s->failed_pc=0x0c0541eeu; return 0; }
r[7]=0x00000008u;
goto P_0c0541f0;
P_0c0541f0: /* original 3768, guest PC 0x0c0541f0 */
if(!s->budget--) { s->failed_pc=0x0c0541f0u; return 0; }
r[7]-=r[6];
goto P_0c0541f2;
P_0c0541f2: /* original 6e7f, guest PC 0x0c0541f2 */
if(!s->budget--) { s->failed_pc=0x0c0541f2u; return 0; }
r[14]=(uint32_t)(int32_t)(int16_t)r[7];
goto P_0c0541f4;
P_0c0541f4: /* original 2ee8, guest PC 0x0c0541f4 */
if(!s->budget--) { s->failed_pc=0x0c0541f4u; return 0; }
r[17]=(r[17]&~1u)|(((r[14]&r[14])==0)!=0);
goto P_0c0541f6;
P_0c0541f6: /* original 8d22, guest PC 0x0c0541f6 */
if(!s->budget--) { s->failed_pc=0x0c0541f6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05423e; }
goto P_0c0541fa;
P_0c0541f8: /* original 0009, guest PC 0x0c0541f8 */
if(!s->budget--) { s->failed_pc=0x0c0541f8u; return 0; }
goto P_0c0541fa;
P_0c0541fa: /* original 9122, guest PC 0x0c0541fa */
if(!s->budget--) { s->failed_pc=0x0c0541fau; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c054242u,2);
goto P_0c0541fc;
P_0c0541fc: /* original 0009, guest PC 0x0c0541fc */
if(!s->budget--) { s->failed_pc=0x0c0541fcu; return 0; }
goto P_0c0541fe;
P_0c0541fe: /* original 41ec, guest PC 0x0c0541fe */
if(!s->budget--) { s->failed_pc=0x0c0541feu; return 0; }
r[1]=(r[14]&0x80000000u)?((r[14]&31u)?(uint32_t)((int32_t)r[1]>>((-r[14])&31u)):((int32_t)r[1]<0?0xffffffffu:0)):r[1]<<(r[14]&31u);
goto P_0c054200;
P_0c054200: /* original e700, guest PC 0x0c054200 */
if(!s->budget--) { s->failed_pc=0x0c054200u; return 0; }
r[7]=0x00000000u;
goto P_0c054202;
P_0c054202: /* original 75ff, guest PC 0x0c054202 */
if(!s->budget--) { s->failed_pc=0x0c054202u; return 0; }
r[5]+=0xffffffffu;
goto P_0c054204;
P_0c054204: /* original 4511, guest PC 0x0c054204 */
if(!s->budget--) { s->failed_pc=0x0c054204u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[5]>=0)!=0);
goto P_0c054206;
P_0c054206: /* original 8f12, guest PC 0x0c054206 */
if(!s->budget--) { s->failed_pc=0x0c054206u; return 0; }
cond=r[17]&1u;
r[4]+=r[5];
if(!cond) { goto P_0c05422e; }
goto P_0c05420a;
P_0c054208: /* original 345c, guest PC 0x0c054208 */
if(!s->budget--) { s->failed_pc=0x0c054208u; return 0; }
r[4]+=r[5];
goto P_0c05420a;
P_0c05420a: /* original 636f, guest PC 0x0c05420a */
if(!s->budget--) { s->failed_pc=0x0c05420au; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)r[6];
goto P_0c05420c;
P_0c05420c: /* original 6240, guest PC 0x0c05420c */
if(!s->budget--) { s->failed_pc=0x0c05420cu; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[4],1);
r[2]=tmp;
goto P_0c05420e;
P_0c05420e: /* original 6040, guest PC 0x0c05420e */
if(!s->budget--) { s->failed_pc=0x0c05420eu; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[4],1);
r[0]=tmp;
goto P_0c054210;
P_0c054210: /* original 2019, guest PC 0x0c054210 */
if(!s->budget--) { s->failed_pc=0x0c054210u; return 0; }
r[0]&=r[1];
goto P_0c054212;
P_0c054212: /* original 0009, guest PC 0x0c054212 */
if(!s->budget--) { s->failed_pc=0x0c054212u; return 0; }
goto P_0c054214;
P_0c054214: /* original 423d, guest PC 0x0c054214 */
if(!s->budget--) { s->failed_pc=0x0c054214u; return 0; }
r[2]=(r[3]&0x80000000u)?((r[3]&31u)?r[2]>>((-r[3])&31u):0):r[2]<<(r[3]&31u);
goto P_0c054216;
P_0c054216: /* original 2420, guest PC 0x0c054216 */
if(!s->budget--) { s->failed_pc=0x0c054216u; return 0; }
write(ram,r[4],r[2],1);
goto P_0c054218;
P_0c054218: /* original 6340, guest PC 0x0c054218 */
if(!s->budget--) { s->failed_pc=0x0c054218u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[4],1);
r[3]=tmp;
goto P_0c05421a;
P_0c05421a: /* original 237b, guest PC 0x0c05421a */
if(!s->budget--) { s->failed_pc=0x0c05421au; return 0; }
r[3]|=r[7];
goto P_0c05421c;
P_0c05421c: /* original 2430, guest PC 0x0c05421c */
if(!s->budget--) { s->failed_pc=0x0c05421cu; return 0; }
write(ram,r[4],r[3],1);
goto P_0c05421e;
P_0c05421e: /* original 670c, guest PC 0x0c05421e */
if(!s->budget--) { s->failed_pc=0x0c05421eu; return 0; }
r[7]=r[0]&255u;
goto P_0c054220;
P_0c054220: /* original 63eb, guest PC 0x0c054220 */
if(!s->budget--) { s->failed_pc=0x0c054220u; return 0; }
r[3]=0u-r[14];
goto P_0c054222;
P_0c054222: /* original 0009, guest PC 0x0c054222 */
if(!s->budget--) { s->failed_pc=0x0c054222u; return 0; }
goto P_0c054224;
P_0c054224: /* original 473d, guest PC 0x0c054224 */
if(!s->budget--) { s->failed_pc=0x0c054224u; return 0; }
r[7]=(r[3]&0x80000000u)?((r[3]&31u)?r[7]>>((-r[3])&31u):0):r[7]<<(r[3]&31u);
goto P_0c054226;
P_0c054226: /* original 75ff, guest PC 0x0c054226 */
if(!s->budget--) { s->failed_pc=0x0c054226u; return 0; }
r[5]+=0xffffffffu;
goto P_0c054228;
P_0c054228: /* original 4511, guest PC 0x0c054228 */
if(!s->budget--) { s->failed_pc=0x0c054228u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[5]>=0)!=0);
goto P_0c05422a;
P_0c05422a: /* original 8dee, guest PC 0x0c05422a */
if(!s->budget--) { s->failed_pc=0x0c05422au; return 0; }
cond=r[17]&1u;
r[4]+=0xffffffffu;
if(cond) { goto P_0c05420a; }
goto P_0c05422e;
P_0c05422c: /* original 74ff, guest PC 0x0c05422c */
if(!s->budget--) { s->failed_pc=0x0c05422cu; return 0; }
r[4]+=0xffffffffu;
goto P_0c05422e;
P_0c05422e: /* original 677c, guest PC 0x0c05422e */
if(!s->budget--) { s->failed_pc=0x0c05422eu; return 0; }
r[7]=r[7]&255u;
goto P_0c054230;
P_0c054230: /* original 2778, guest PC 0x0c054230 */
if(!s->budget--) { s->failed_pc=0x0c054230u; return 0; }
r[17]=(r[17]&~1u)|(((r[7]&r[7])==0)!=0);
goto P_0c054232;
P_0c054232: /* original 8d03, guest PC 0x0c054232 */
if(!s->budget--) { s->failed_pc=0x0c054232u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05423c; }
goto P_0c054236;
P_0c054234: /* original 0009, guest PC 0x0c054234 */
if(!s->budget--) { s->failed_pc=0x0c054234u; return 0; }
goto P_0c054236;
P_0c054236: /* original e001, guest PC 0x0c054236 */
if(!s->budget--) { s->failed_pc=0x0c054236u; return 0; }
r[0]=0x00000001u;
goto P_0c054238;
P_0c054238: /* original 000b, guest PC 0x0c054238 */
if(!s->budget--) { s->failed_pc=0x0c054238u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c05423a: /* original 6ef6, guest PC 0x0c05423a */
if(!s->budget--) { s->failed_pc=0x0c05423au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c05423c;
P_0c05423c: /* original e000, guest PC 0x0c05423c */
if(!s->budget--) { s->failed_pc=0x0c05423cu; return 0; }
r[0]=0x00000000u;
goto P_0c05423e;
P_0c05423e: /* original 000b, guest PC 0x0c05423e */
if(!s->budget--) { s->failed_pc=0x0c05423eu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c054240: /* original 6ef6, guest PC 0x0c054240 */
if(!s->budget--) { s->failed_pc=0x0c054240u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c054242u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c054242u; return 0; } return 1;
P_0c054c1c: /* original 2f06, guest PC 0x0c054c1c */
if(!s->budget--) { s->failed_pc=0x0c054c1cu; return 0; }
tmp=r[0]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c054c1e;
P_0c054c1e: /* original 2f46, guest PC 0x0c054c1e */
if(!s->budget--) { s->failed_pc=0x0c054c1eu; return 0; }
tmp=r[4]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c054c20;
P_0c054c20: /* original 2f56, guest PC 0x0c054c20 */
if(!s->budget--) { s->failed_pc=0x0c054c20u; return 0; }
tmp=r[5]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c054c22;
P_0c054c22: /* original 2f66, guest PC 0x0c054c22 */
if(!s->budget--) { s->failed_pc=0x0c054c22u; return 0; }
tmp=r[6]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c054c24;
P_0c054c24: /* original 2f76, guest PC 0x0c054c24 */
if(!s->budget--) { s->failed_pc=0x0c054c24u; return 0; }
tmp=r[7]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c054c26;
P_0c054c26: /* original 57f6, guest PC 0x0c054c26 */
if(!s->budget--) { s->failed_pc=0x0c054c26u; return 0; }
r[7]=read(ram,r[15]+24,4);
goto P_0c054c28;
P_0c054c28: /* original 56f7, guest PC 0x0c054c28 */
if(!s->budget--) { s->failed_pc=0x0c054c28u; return 0; }
r[6]=read(ram,r[15]+28,4);
goto P_0c054c2a;
P_0c054c2a: /* original 55f8, guest PC 0x0c054c2a */
if(!s->budget--) { s->failed_pc=0x0c054c2au; return 0; }
r[5]=read(ram,r[15]+32,4);
goto P_0c054c2c;
P_0c054c2c: /* original 54f9, guest PC 0x0c054c2c */
if(!s->budget--) { s->failed_pc=0x0c054c2cu; return 0; }
r[4]=read(ram,r[15]+36,4);
goto P_0c054c2e;
P_0c054c2e: /* original d0b6, guest PC 0x0c054c2e */
if(!s->budget--) { s->failed_pc=0x0c054c2eu; return 0; }
r[0]=read(ram,0x0c054f08u,4);
goto P_0c054c30;
P_0c054c30: /* original a059, guest PC 0x0c054c30 */
if(!s->budget--) { s->failed_pc=0x0c054c30u; return 0; }
r[6]^=r[0];
goto P_0c054ce6;
P_0c054c32: /* original 260a, guest PC 0x0c054c32 */
if(!s->budget--) { s->failed_pc=0x0c054c32u; return 0; }
r[6]^=r[0];
goto P_0c054c34;
P_0c054c34: /* original 2448, guest PC 0x0c054c34 */
if(!s->budget--) { s->failed_pc=0x0c054c34u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c054c36;
P_0c054c36: /* original 8b07, guest PC 0x0c054c36 */
if(!s->budget--) { s->failed_pc=0x0c054c36u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c054c48; }
goto P_0c054c38;
P_0c054c38: /* original 2558, guest PC 0x0c054c38 */
if(!s->budget--) { s->failed_pc=0x0c054c38u; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[5])==0)!=0);
goto P_0c054c3a;
P_0c054c3a: /* original 8b05, guest PC 0x0c054c3a */
if(!s->budget--) { s->failed_pc=0x0c054c3au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c054c48; }
goto P_0c054c3c;
P_0c054c3c: /* original 3930, guest PC 0x0c054c3c */
if(!s->budget--) { s->failed_pc=0x0c054c3cu; return 0; }
r[17]=(r[17]&~1u)|((r[9]==r[3])!=0);
goto P_0c054c3e;
P_0c054c3e: /* original 8b07, guest PC 0x0c054c3e */
if(!s->budget--) { s->failed_pc=0x0c054c3eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c054c50; }
goto P_0c054c40;
P_0c054c40: /* original 2778, guest PC 0x0c054c40 */
if(!s->budget--) { s->failed_pc=0x0c054c40u; return 0; }
r[17]=(r[17]&~1u)|(((r[7]&r[7])==0)!=0);
goto P_0c054c42;
P_0c054c42: /* original 8b01, guest PC 0x0c054c42 */
if(!s->budget--) { s->failed_pc=0x0c054c42u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c054c48; }
goto P_0c054c44;
P_0c054c44: /* original 2ba7, guest PC 0x0c054c44 */
if(!s->budget--) { s->failed_pc=0x0c054c44u; return 0; }
r[17]=(r[17]&~0x301u)|((r[11]>>31)<<8)|((r[10]>>31)<<9)|(((r[11]^r[10])>>31)&1u);
goto P_0c054c46;
P_0c054c46: /* original 8b03, guest PC 0x0c054c46 */
if(!s->budget--) { s->failed_pc=0x0c054c46u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c054c50; }
goto P_0c054c48;
P_0c054c48: /* original ea00, guest PC 0x0c054c48 */
if(!s->budget--) { s->failed_pc=0x0c054c48u; return 0; }
r[10]=0x00000000u;
goto P_0c054c4a;
P_0c054c4a: /* original e400, guest PC 0x0c054c4a */
if(!s->budget--) { s->failed_pc=0x0c054c4au; return 0; }
r[4]=0x00000000u;
goto P_0c054c4c;
P_0c054c4c: /* original a11f, guest PC 0x0c054c4c */
if(!s->budget--) { s->failed_pc=0x0c054c4cu; return 0; }
r[5]=0x00000008u;
goto P_0c054e8e;
P_0c054c4e: /* original e508, guest PC 0x0c054c4e */
if(!s->budget--) { s->failed_pc=0x0c054c4eu; return 0; }
r[5]=0x00000008u;
goto P_0c054c50;
P_0c054c50: /* original a11d, guest PC 0x0c054c50 */
if(!s->budget--) { s->failed_pc=0x0c054c50u; return 0; }
goto P_0c054e8e;
P_0c054c52: /* original 0009, guest PC 0x0c054c52 */
if(!s->budget--) { s->failed_pc=0x0c054c52u; return 0; }
goto P_0c054c54;
P_0c054c54: /* original 2888, guest PC 0x0c054c54 */
if(!s->budget--) { s->failed_pc=0x0c054c54u; return 0; }
r[17]=(r[17]&~1u)|(((r[8]&r[8])==0)!=0);
goto P_0c054c56;
P_0c054c56: /* original 8b07, guest PC 0x0c054c56 */
if(!s->budget--) { s->failed_pc=0x0c054c56u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c054c68; }
goto P_0c054c58;
P_0c054c58: /* original 2448, guest PC 0x0c054c58 */
if(!s->budget--) { s->failed_pc=0x0c054c58u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c054c5a;
P_0c054c5a: /* original 8b0b, guest PC 0x0c054c5a */
if(!s->budget--) { s->failed_pc=0x0c054c5au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c054c74; }
goto P_0c054c5c;
P_0c054c5c: /* original 2558, guest PC 0x0c054c5c */
if(!s->budget--) { s->failed_pc=0x0c054c5cu; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[5])==0)!=0);
goto P_0c054c5e;
P_0c054c5e: /* original 8b09, guest PC 0x0c054c5e */
if(!s->budget--) { s->failed_pc=0x0c054c5eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c054c74; }
goto P_0c054c60;
P_0c054c60: /* original 2778, guest PC 0x0c054c60 */
if(!s->budget--) { s->failed_pc=0x0c054c60u; return 0; }
r[17]=(r[17]&~1u)|(((r[7]&r[7])==0)!=0);
goto P_0c054c62;
P_0c054c62: /* original 8b0d, guest PC 0x0c054c62 */
if(!s->budget--) { s->failed_pc=0x0c054c62u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c054c80; }
goto P_0c054c64;
P_0c054c64: /* original a113, guest PC 0x0c054c64 */
if(!s->budget--) { s->failed_pc=0x0c054c64u; return 0; }
r[10]&=r[11];
goto P_0c054e8e;
P_0c054c66: /* original 2ab9, guest PC 0x0c054c66 */
if(!s->budget--) { s->failed_pc=0x0c054c66u; return 0; }
r[10]&=r[11];
goto P_0c054c68;
P_0c054c68: /* original 2668, guest PC 0x0c054c68 */
if(!s->budget--) { s->failed_pc=0x0c054c68u; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[6])==0)!=0);
goto P_0c054c6a;
P_0c054c6a: /* original 8b1e, guest PC 0x0c054c6a */
if(!s->budget--) { s->failed_pc=0x0c054c6au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c054caa; }
goto P_0c054c6c;
P_0c054c6c: /* original 2778, guest PC 0x0c054c6c */
if(!s->budget--) { s->failed_pc=0x0c054c6cu; return 0; }
r[17]=(r[17]&~1u)|(((r[7]&r[7])==0)!=0);
goto P_0c054c6e;
P_0c054c6e: /* original 8b1c, guest PC 0x0c054c6e */
if(!s->budget--) { s->failed_pc=0x0c054c6eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c054caa; }
goto P_0c054c70;
P_0c054c70: /* original a00a, guest PC 0x0c054c70 */
if(!s->budget--) { s->failed_pc=0x0c054c70u; return 0; }
goto P_0c054c88;
P_0c054c72: /* original 0009, guest PC 0x0c054c72 */
if(!s->budget--) { s->failed_pc=0x0c054c72u; return 0; }
goto P_0c054c74;
P_0c054c74: /* original 2668, guest PC 0x0c054c74 */
if(!s->budget--) { s->failed_pc=0x0c054c74u; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[6])==0)!=0);
goto P_0c054c76;
P_0c054c76: /* original 8b0e, guest PC 0x0c054c76 */
if(!s->budget--) { s->failed_pc=0x0c054c76u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c054c96; }
goto P_0c054c78;
P_0c054c78: /* original 2778, guest PC 0x0c054c78 */
if(!s->budget--) { s->failed_pc=0x0c054c78u; return 0; }
r[17]=(r[17]&~1u)|(((r[7]&r[7])==0)!=0);
goto P_0c054c7a;
P_0c054c7a: /* original 8b0c, guest PC 0x0c054c7a */
if(!s->budget--) { s->failed_pc=0x0c054c7au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c054c96; }
goto P_0c054c7c;
P_0c054c7c: /* original a004, guest PC 0x0c054c7c */
if(!s->budget--) { s->failed_pc=0x0c054c7cu; return 0; }
goto P_0c054c88;
P_0c054c7e: /* original 0009, guest PC 0x0c054c7e */
if(!s->budget--) { s->failed_pc=0x0c054c7eu; return 0; }
goto P_0c054c80;
P_0c054c80: /* original 6463, guest PC 0x0c054c80 */
if(!s->budget--) { s->failed_pc=0x0c054c80u; return 0; }
r[4]=r[6];
goto P_0c054c82;
P_0c054c82: /* original 6573, guest PC 0x0c054c82 */
if(!s->budget--) { s->failed_pc=0x0c054c82u; return 0; }
r[5]=r[7];
goto P_0c054c84;
P_0c054c84: /* original 6893, guest PC 0x0c054c84 */
if(!s->budget--) { s->failed_pc=0x0c054c84u; return 0; }
r[8]=r[9];
goto P_0c054c86;
P_0c054c86: /* original 6ab3, guest PC 0x0c054c86 */
if(!s->budget--) { s->failed_pc=0x0c054c86u; return 0; }
r[10]=r[11];
goto P_0c054c88;
P_0c054c88: /* original 4500, guest PC 0x0c054c88 */
if(!s->budget--) { s->failed_pc=0x0c054c88u; return 0; }
r[17]=(r[17]&~1u)|((r[5]>>31)!=0);
r[5]<<=1;
goto P_0c054c8a;
P_0c054c8a: /* original 4424, guest PC 0x0c054c8a */
if(!s->budget--) { s->failed_pc=0x0c054c8au; return 0; }
tmp=r[4]>>31; r[4]=(r[4]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c054c8c;
P_0c054c8c: /* original 4500, guest PC 0x0c054c8c */
if(!s->budget--) { s->failed_pc=0x0c054c8cu; return 0; }
r[17]=(r[17]&~1u)|((r[5]>>31)!=0);
r[5]<<=1;
goto P_0c054c8e;
P_0c054c8e: /* original 4424, guest PC 0x0c054c8e */
if(!s->budget--) { s->failed_pc=0x0c054c8eu; return 0; }
tmp=r[4]>>31; r[4]=(r[4]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c054c90;
P_0c054c90: /* original 4500, guest PC 0x0c054c90 */
if(!s->budget--) { s->failed_pc=0x0c054c90u; return 0; }
r[17]=(r[17]&~1u)|((r[5]>>31)!=0);
r[5]<<=1;
goto P_0c054c92;
P_0c054c92: /* original a0fc, guest PC 0x0c054c92 */
if(!s->budget--) { s->failed_pc=0x0c054c92u; return 0; }
tmp=r[4]>>31; r[4]=(r[4]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c054e8e;
P_0c054c94: /* original 4424, guest PC 0x0c054c94 */
if(!s->budget--) { s->failed_pc=0x0c054c94u; return 0; }
tmp=r[4]>>31; r[4]=(r[4]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c054c96;
P_0c054c96: /* original d39b, guest PC 0x0c054c96 */
if(!s->budget--) { s->failed_pc=0x0c054c96u; return 0; }
r[3]=read(ram,0x0c054f04u,4);
goto P_0c054c98;
P_0c054c98: /* original 4500, guest PC 0x0c054c98 */
if(!s->budget--) { s->failed_pc=0x0c054c98u; return 0; }
r[17]=(r[17]&~1u)|((r[5]>>31)!=0);
r[5]<<=1;
goto P_0c054c9a;
P_0c054c9a: /* original 4424, guest PC 0x0c054c9a */
if(!s->budget--) { s->failed_pc=0x0c054c9au; return 0; }
tmp=r[4]>>31; r[4]=(r[4]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c054c9c;
P_0c054c9c: /* original 3433, guest PC 0x0c054c9c */
if(!s->budget--) { s->failed_pc=0x0c054c9cu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[3])!=0);
goto P_0c054c9e;
P_0c054c9e: /* original 8904, guest PC 0x0c054c9e */
if(!s->budget--) { s->failed_pc=0x0c054c9eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c054caa; }
goto P_0c054ca0;
P_0c054ca0: /* original 4500, guest PC 0x0c054ca0 */
if(!s->budget--) { s->failed_pc=0x0c054ca0u; return 0; }
r[17]=(r[17]&~1u)|((r[5]>>31)!=0);
r[5]<<=1;
goto P_0c054ca2;
P_0c054ca2: /* original 4424, guest PC 0x0c054ca2 */
if(!s->budget--) { s->failed_pc=0x0c054ca2u; return 0; }
tmp=r[4]>>31; r[4]=(r[4]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c054ca4;
P_0c054ca4: /* original 3433, guest PC 0x0c054ca4 */
if(!s->budget--) { s->failed_pc=0x0c054ca4u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[3])!=0);
goto P_0c054ca6;
P_0c054ca6: /* original 8ffb, guest PC 0x0c054ca6 */
if(!s->budget--) { s->failed_pc=0x0c054ca6u; return 0; }
cond=r[17]&1u;
r[8]+=0xffffffffu;
if(!cond) { goto P_0c054ca0; }
goto P_0c054caa;
P_0c054ca8: /* original 78ff, guest PC 0x0c054ca8 */
if(!s->budget--) { s->failed_pc=0x0c054ca8u; return 0; }
r[8]+=0xffffffffu;
goto P_0c054caa;
P_0c054caa: /* original d396, guest PC 0x0c054caa */
if(!s->budget--) { s->failed_pc=0x0c054caau; return 0; }
r[3]=read(ram,0x0c054f04u,4);
goto P_0c054cac;
P_0c054cac: /* original 4700, guest PC 0x0c054cac */
if(!s->budget--) { s->failed_pc=0x0c054cacu; return 0; }
r[17]=(r[17]&~1u)|((r[7]>>31)!=0);
r[7]<<=1;
goto P_0c054cae;
P_0c054cae: /* original 4624, guest PC 0x0c054cae */
if(!s->budget--) { s->failed_pc=0x0c054caeu; return 0; }
tmp=r[6]>>31; r[6]=(r[6]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c054cb0;
P_0c054cb0: /* original 3633, guest PC 0x0c054cb0 */
if(!s->budget--) { s->failed_pc=0x0c054cb0u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[6]>=(int32_t)r[3])!=0);
goto P_0c054cb2;
P_0c054cb2: /* original 8904, guest PC 0x0c054cb2 */
if(!s->budget--) { s->failed_pc=0x0c054cb2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c054cbe; }
goto P_0c054cb4;
P_0c054cb4: /* original 4700, guest PC 0x0c054cb4 */
if(!s->budget--) { s->failed_pc=0x0c054cb4u; return 0; }
r[17]=(r[17]&~1u)|((r[7]>>31)!=0);
r[7]<<=1;
goto P_0c054cb6;
P_0c054cb6: /* original 4624, guest PC 0x0c054cb6 */
if(!s->budget--) { s->failed_pc=0x0c054cb6u; return 0; }
tmp=r[6]>>31; r[6]=(r[6]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c054cb8;
P_0c054cb8: /* original 3633, guest PC 0x0c054cb8 */
if(!s->budget--) { s->failed_pc=0x0c054cb8u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[6]>=(int32_t)r[3])!=0);
goto P_0c054cba;
P_0c054cba: /* original 8ffb, guest PC 0x0c054cba */
if(!s->budget--) { s->failed_pc=0x0c054cbau; return 0; }
cond=r[17]&1u;
r[9]+=0xffffffffu;
if(!cond) { goto P_0c054cb4; }
goto P_0c054cbe;
P_0c054cbc: /* original 79ff, guest PC 0x0c054cbc */
if(!s->budget--) { s->failed_pc=0x0c054cbcu; return 0; }
r[9]+=0xffffffffu;
goto P_0c054cbe;
P_0c054cbe: /* original 3987, guest PC 0x0c054cbe */
if(!s->budget--) { s->failed_pc=0x0c054cbeu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[9]>(int32_t)r[8])!=0);
goto P_0c054cc0;
P_0c054cc0: /* original 8b01, guest PC 0x0c054cc0 */
if(!s->budget--) { s->failed_pc=0x0c054cc0u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c054cc6; }
goto P_0c054cc2;
P_0c054cc2: /* original a108, guest PC 0x0c054cc2 */
if(!s->budget--) { s->failed_pc=0x0c054cc2u; return 0; }
return vf3_matrix_family(0x0c054ed6u,s,ram);
P_0c054cc4: /* original 0009, guest PC 0x0c054cc4 */
if(!s->budget--) { s->failed_pc=0x0c054cc4u; return 0; }
goto P_0c054cc6;
P_0c054cc6: /* original a034, guest PC 0x0c054cc6 */
if(!s->budget--) { s->failed_pc=0x0c054cc6u; return 0; }
goto P_0c054d32;
P_0c054cc8: /* original 0009, guest PC 0x0c054cc8 */
if(!s->budget--) { s->failed_pc=0x0c054cc8u; return 0; }
if(!vf3_matrix_family(0x0c054ccau,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c054ccau; return 0; } return 1;
P_0c054ce6: /* original 2f26, guest PC 0x0c054ce6 */
if(!s->budget--) { s->failed_pc=0x0c054ce6u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c054ce8;
P_0c054ce8: /* original 2f36, guest PC 0x0c054ce8 */
if(!s->budget--) { s->failed_pc=0x0c054ce8u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c054cea;
P_0c054cea: /* original 2f86, guest PC 0x0c054cea */
if(!s->budget--) { s->failed_pc=0x0c054ceau; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c054cec;
P_0c054cec: /* original 2f96, guest PC 0x0c054cec */
if(!s->budget--) { s->failed_pc=0x0c054cecu; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c054cee;
P_0c054cee: /* original 2fa6, guest PC 0x0c054cee */
if(!s->budget--) { s->failed_pc=0x0c054ceeu; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c054cf0;
P_0c054cf0: /* original 2fb6, guest PC 0x0c054cf0 */
if(!s->budget--) { s->failed_pc=0x0c054cf0u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c054cf2;
P_0c054cf2: /* original 4404, guest PC 0x0c054cf2 */
if(!s->budget--) { s->failed_pc=0x0c054cf2u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]=(r[4]<<1)|(r[4]>>31);
goto P_0c054cf4;
P_0c054cf4: /* original 4604, guest PC 0x0c054cf4 */
if(!s->budget--) { s->failed_pc=0x0c054cf4u; return 0; }
r[17]=(r[17]&~1u)|((r[6]>>31)!=0);
r[6]=(r[6]<<1)|(r[6]>>31);
goto P_0c054cf6;
P_0c054cf6: /* original 3462, guest PC 0x0c054cf6 */
if(!s->budget--) { s->failed_pc=0x0c054cf6u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>=r[6])!=0);
goto P_0c054cf8;
P_0c054cf8: /* original 8905, guest PC 0x0c054cf8 */
if(!s->budget--) { s->failed_pc=0x0c054cf8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c054d06; }
goto P_0c054cfa;
P_0c054cfa: /* original 6243, guest PC 0x0c054cfa */
if(!s->budget--) { s->failed_pc=0x0c054cfau; return 0; }
r[2]=r[4];
goto P_0c054cfc;
P_0c054cfc: /* original 6463, guest PC 0x0c054cfc */
if(!s->budget--) { s->failed_pc=0x0c054cfcu; return 0; }
r[4]=r[6];
goto P_0c054cfe;
P_0c054cfe: /* original 6623, guest PC 0x0c054cfe */
if(!s->budget--) { s->failed_pc=0x0c054cfeu; return 0; }
r[6]=r[2];
goto P_0c054d00;
P_0c054d00: /* original 6253, guest PC 0x0c054d00 */
if(!s->budget--) { s->failed_pc=0x0c054d00u; return 0; }
r[2]=r[5];
goto P_0c054d02;
P_0c054d02: /* original 6573, guest PC 0x0c054d02 */
if(!s->budget--) { s->failed_pc=0x0c054d02u; return 0; }
r[5]=r[7];
goto P_0c054d04;
P_0c054d04: /* original 6723, guest PC 0x0c054d04 */
if(!s->budget--) { s->failed_pc=0x0c054d04u; return 0; }
r[7]=r[2];
goto P_0c054d06;
P_0c054d06: /* original 4405, guest PC 0x0c054d06 */
if(!s->budget--) { s->failed_pc=0x0c054d06u; return 0; }
r[17]=(r[17]&~1u)|((r[4]&1u)!=0);
r[4]=(r[4]>>1)|(r[4]<<31);
goto P_0c054d08;
P_0c054d08: /* original 4605, guest PC 0x0c054d08 */
if(!s->budget--) { s->failed_pc=0x0c054d08u; return 0; }
r[17]=(r[17]&~1u)|((r[6]&1u)!=0);
r[6]=(r[6]>>1)|(r[6]<<31);
goto P_0c054d0a;
P_0c054d0a: /* original d379, guest PC 0x0c054d0a */
if(!s->budget--) { s->failed_pc=0x0c054d0au; return 0; }
r[3]=read(ram,0x0c054ef0u,4);
goto P_0c054d0c;
P_0c054d0c: /* original d079, guest PC 0x0c054d0c */
if(!s->budget--) { s->failed_pc=0x0c054d0cu; return 0; }
r[0]=read(ram,0x0c054ef4u,4);
goto P_0c054d0e;
P_0c054d0e: /* original 6a43, guest PC 0x0c054d0e */
if(!s->budget--) { s->failed_pc=0x0c054d0eu; return 0; }
r[10]=r[4];
goto P_0c054d10;
P_0c054d10: /* original 6b63, guest PC 0x0c054d10 */
if(!s->budget--) { s->failed_pc=0x0c054d10u; return 0; }
r[11]=r[6];
goto P_0c054d12;
P_0c054d12: /* original 6843, guest PC 0x0c054d12 */
if(!s->budget--) { s->failed_pc=0x0c054d12u; return 0; }
r[8]=r[4];
goto P_0c054d14;
P_0c054d14: /* original 4829, guest PC 0x0c054d14 */
if(!s->budget--) { s->failed_pc=0x0c054d14u; return 0; }
r[8]>>=16;
goto P_0c054d16;
P_0c054d16: /* original 4809, guest PC 0x0c054d16 */
if(!s->budget--) { s->failed_pc=0x0c054d16u; return 0; }
r[8]>>=2;
goto P_0c054d18;
P_0c054d18: /* original 4809, guest PC 0x0c054d18 */
if(!s->budget--) { s->failed_pc=0x0c054d18u; return 0; }
r[8]>>=2;
goto P_0c054d1a;
P_0c054d1a: /* original 2839, guest PC 0x0c054d1a */
if(!s->budget--) { s->failed_pc=0x0c054d1au; return 0; }
r[8]&=r[3];
goto P_0c054d1c;
P_0c054d1c: /* original 6963, guest PC 0x0c054d1c */
if(!s->budget--) { s->failed_pc=0x0c054d1cu; return 0; }
r[9]=r[6];
goto P_0c054d1e;
P_0c054d1e: /* original 4929, guest PC 0x0c054d1e */
if(!s->budget--) { s->failed_pc=0x0c054d1eu; return 0; }
r[9]>>=16;
goto P_0c054d20;
P_0c054d20: /* original 4909, guest PC 0x0c054d20 */
if(!s->budget--) { s->failed_pc=0x0c054d20u; return 0; }
r[9]>>=2;
goto P_0c054d22;
P_0c054d22: /* original 4909, guest PC 0x0c054d22 */
if(!s->budget--) { s->failed_pc=0x0c054d22u; return 0; }
r[9]>>=2;
goto P_0c054d24;
P_0c054d24: /* original 2939, guest PC 0x0c054d24 */
if(!s->budget--) { s->failed_pc=0x0c054d24u; return 0; }
r[9]&=r[3];
goto P_0c054d26;
P_0c054d26: /* original 2409, guest PC 0x0c054d26 */
if(!s->budget--) { s->failed_pc=0x0c054d26u; return 0; }
r[4]&=r[0];
goto P_0c054d28;
P_0c054d28: /* original 2609, guest PC 0x0c054d28 */
if(!s->budget--) { s->failed_pc=0x0c054d28u; return 0; }
r[6]&=r[0];
goto P_0c054d2a;
P_0c054d2a: /* original 3830, guest PC 0x0c054d2a */
if(!s->budget--) { s->failed_pc=0x0c054d2au; return 0; }
r[17]=(r[17]&~1u)|((r[8]==r[3])!=0);
goto P_0c054d2c;
P_0c054d2c: /* original 8982, guest PC 0x0c054d2c */
if(!s->budget--) { s->failed_pc=0x0c054d2cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c054c34; }
goto P_0c054d2e;
P_0c054d2e: /* original 2998, guest PC 0x0c054d2e */
if(!s->budget--) { s->failed_pc=0x0c054d2eu; return 0; }
r[17]=(r[17]&~1u)|(((r[9]&r[9])==0)!=0);
goto P_0c054d30;
P_0c054d30: /* original 8990, guest PC 0x0c054d30 */
if(!s->budget--) { s->failed_pc=0x0c054d30u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c054c54; }
goto P_0c054d32;
P_0c054d32: /* original 4500, guest PC 0x0c054d32 */
if(!s->budget--) { s->failed_pc=0x0c054d32u; return 0; }
r[17]=(r[17]&~1u)|((r[5]>>31)!=0);
r[5]<<=1;
goto P_0c054d34;
P_0c054d34: /* original 4424, guest PC 0x0c054d34 */
if(!s->budget--) { s->failed_pc=0x0c054d34u; return 0; }
tmp=r[4]>>31; r[4]=(r[4]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c054d36;
P_0c054d36: /* original 4500, guest PC 0x0c054d36 */
if(!s->budget--) { s->failed_pc=0x0c054d36u; return 0; }
r[17]=(r[17]&~1u)|((r[5]>>31)!=0);
r[5]<<=1;
goto P_0c054d38;
P_0c054d38: /* original 4424, guest PC 0x0c054d38 */
if(!s->budget--) { s->failed_pc=0x0c054d38u; return 0; }
tmp=r[4]>>31; r[4]=(r[4]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c054d3a;
P_0c054d3a: /* original 4500, guest PC 0x0c054d3a */
if(!s->budget--) { s->failed_pc=0x0c054d3au; return 0; }
r[17]=(r[17]&~1u)|((r[5]>>31)!=0);
r[5]<<=1;
goto P_0c054d3c;
P_0c054d3c: /* original 4424, guest PC 0x0c054d3c */
if(!s->budget--) { s->failed_pc=0x0c054d3cu; return 0; }
tmp=r[4]>>31; r[4]=(r[4]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c054d3e;
P_0c054d3e: /* original 4700, guest PC 0x0c054d3e */
if(!s->budget--) { s->failed_pc=0x0c054d3eu; return 0; }
r[17]=(r[17]&~1u)|((r[7]>>31)!=0);
r[7]<<=1;
goto P_0c054d40;
P_0c054d40: /* original 4624, guest PC 0x0c054d40 */
if(!s->budget--) { s->failed_pc=0x0c054d40u; return 0; }
tmp=r[6]>>31; r[6]=(r[6]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c054d42;
P_0c054d42: /* original 4700, guest PC 0x0c054d42 */
if(!s->budget--) { s->failed_pc=0x0c054d42u; return 0; }
r[17]=(r[17]&~1u)|((r[7]>>31)!=0);
r[7]<<=1;
goto P_0c054d44;
P_0c054d44: /* original 4624, guest PC 0x0c054d44 */
if(!s->budget--) { s->failed_pc=0x0c054d44u; return 0; }
tmp=r[6]>>31; r[6]=(r[6]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c054d46;
P_0c054d46: /* original 4700, guest PC 0x0c054d46 */
if(!s->budget--) { s->failed_pc=0x0c054d46u; return 0; }
r[17]=(r[17]&~1u)|((r[7]>>31)!=0);
r[7]<<=1;
goto P_0c054d48;
P_0c054d48: /* original 4624, guest PC 0x0c054d48 */
if(!s->budget--) { s->failed_pc=0x0c054d48u; return 0; }
tmp=r[6]>>31; r[6]=(r[6]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c054d4a;
P_0c054d4a: /* original d06b, guest PC 0x0c054d4a */
if(!s->budget--) { s->failed_pc=0x0c054d4au; return 0; }
r[0]=read(ram,0x0c054ef8u,4);
goto P_0c054d4c;
P_0c054d4c: /* original 240b, guest PC 0x0c054d4c */
if(!s->budget--) { s->failed_pc=0x0c054d4cu; return 0; }
r[4]|=r[0];
goto P_0c054d4e;
P_0c054d4e: /* original 260b, guest PC 0x0c054d4e */
if(!s->budget--) { s->failed_pc=0x0c054d4eu; return 0; }
r[6]|=r[0];
goto P_0c054d50;
P_0c054d50: /* original 6283, guest PC 0x0c054d50 */
if(!s->budget--) { s->failed_pc=0x0c054d50u; return 0; }
r[2]=r[8];
goto P_0c054d52;
P_0c054d52: /* original 3298, guest PC 0x0c054d52 */
if(!s->budget--) { s->failed_pc=0x0c054d52u; return 0; }
r[2]-=r[9];
goto P_0c054d54;
P_0c054d54: /* original 2228, guest PC 0x0c054d54 */
if(!s->budget--) { s->failed_pc=0x0c054d54u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c054d56;
P_0c054d56: /* original 8929, guest PC 0x0c054d56 */
if(!s->budget--) { s->failed_pc=0x0c054d56u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c054dac; }
goto P_0c054d58;
P_0c054d58: /* original e303, guest PC 0x0c054d58 */
if(!s->budget--) { s->failed_pc=0x0c054d58u; return 0; }
r[3]=0x00000003u;
goto P_0c054d5a;
P_0c054d5a: /* original 3323, guest PC 0x0c054d5a */
if(!s->budget--) { s->failed_pc=0x0c054d5au; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>=(int32_t)r[2])!=0);
goto P_0c054d5c;
P_0c054d5c: /* original 8922, guest PC 0x0c054d5c */
if(!s->budget--) { s->failed_pc=0x0c054d5cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c054da4; }
goto P_0c054d5e;
P_0c054d5e: /* original e336, guest PC 0x0c054d5e */
if(!s->budget--) { s->failed_pc=0x0c054d5eu; return 0; }
r[3]=0x00000036u;
goto P_0c054d60;
P_0c054d60: /* original 3237, guest PC 0x0c054d60 */
if(!s->budget--) { s->failed_pc=0x0c054d60u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>(int32_t)r[3])!=0);
goto P_0c054d62;
P_0c054d62: /* original 891c, guest PC 0x0c054d62 */
if(!s->budget--) { s->failed_pc=0x0c054d62u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c054d9e; }
goto P_0c054d64;
P_0c054d64: /* original e320, guest PC 0x0c054d64 */
if(!s->budget--) { s->failed_pc=0x0c054d64u; return 0; }
r[3]=0x00000020u;
goto P_0c054d66;
P_0c054d66: /* original 3237, guest PC 0x0c054d66 */
if(!s->budget--) { s->failed_pc=0x0c054d66u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>(int32_t)r[3])!=0);
goto P_0c054d68;
P_0c054d68: /* original 8f06, guest PC 0x0c054d68 */
if(!s->budget--) { s->failed_pc=0x0c054d68u; return 0; }
cond=r[17]&1u;
r[9]=0x00000001u;
if(!cond) { goto P_0c054d78; }
goto P_0c054d6c;
P_0c054d6a: /* original e901, guest PC 0x0c054d6a */
if(!s->budget--) { s->failed_pc=0x0c054d6au; return 0; }
r[9]=0x00000001u;
goto P_0c054d6c;
P_0c054d6c: /* original 3238, guest PC 0x0c054d6c */
if(!s->budget--) { s->failed_pc=0x0c054d6cu; return 0; }
r[2]-=r[3];
goto P_0c054d6e;
P_0c054d6e: /* original 2778, guest PC 0x0c054d6e */
if(!s->budget--) { s->failed_pc=0x0c054d6eu; return 0; }
r[17]=(r[17]&~1u)|(((r[7]&r[7])==0)!=0);
goto P_0c054d70;
P_0c054d70: /* original 8900, guest PC 0x0c054d70 */
if(!s->budget--) { s->failed_pc=0x0c054d70u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c054d74; }
goto P_0c054d72;
P_0c054d72: /* original 269b, guest PC 0x0c054d72 */
if(!s->budget--) { s->failed_pc=0x0c054d72u; return 0; }
r[6]|=r[9];
goto P_0c054d74;
P_0c054d74: /* original 6763, guest PC 0x0c054d74 */
if(!s->budget--) { s->failed_pc=0x0c054d74u; return 0; }
r[7]=r[6];
goto P_0c054d76;
P_0c054d76: /* original e600, guest PC 0x0c054d76 */
if(!s->budget--) { s->failed_pc=0x0c054d76u; return 0; }
r[6]=0x00000000u;
goto P_0c054d78;
P_0c054d78: /* original 4f02, guest PC 0x0c054d78 */
if(!s->budget--) { s->failed_pc=0x0c054d78u; return 0; }
r[15]-=4; write(ram,r[15],r[20],4);
goto P_0c054d7a;
P_0c054d7a: /* original c765, guest PC 0x0c054d7a */
if(!s->budget--) { s->failed_pc=0x0c054d7au; return 0; }
r[0]=code_base|0x00054f10u;
goto P_0c054d7c;
P_0c054d7c: /* original 4f12, guest PC 0x0c054d7c */
if(!s->budget--) { s->failed_pc=0x0c054d7cu; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c054d7e;
P_0c054d7e: /* original 4208, guest PC 0x0c054d7e */
if(!s->budget--) { s->failed_pc=0x0c054d7eu; return 0; }
r[2]<<=2;
goto P_0c054d80;
P_0c054d80: /* original 302c, guest PC 0x0c054d80 */
if(!s->budget--) { s->failed_pc=0x0c054d80u; return 0; }
r[0]+=r[2];
goto P_0c054d82;
P_0c054d82: /* original 6002, guest PC 0x0c054d82 */
if(!s->budget--) { s->failed_pc=0x0c054d82u; return 0; }
tmp=read(ram,r[0],4);
r[0]=tmp;
goto P_0c054d84;
P_0c054d84: /* original 3705, guest PC 0x0c054d84 */
if(!s->budget--) { s->failed_pc=0x0c054d84u; return 0; }
wide=(uint64_t)r[7]*r[0]; r[19]=(uint32_t)wide; r[20]=(uint32_t)(wide>>32);
goto P_0c054d86;
P_0c054d86: /* original 070a, guest PC 0x0c054d86 */
if(!s->budget--) { s->failed_pc=0x0c054d86u; return 0; }
r[7]=r[20];
goto P_0c054d88;
P_0c054d88: /* original 021a, guest PC 0x0c054d88 */
if(!s->budget--) { s->failed_pc=0x0c054d88u; return 0; }
r[2]=r[19];
goto P_0c054d8a;
P_0c054d8a: /* original 3605, guest PC 0x0c054d8a */
if(!s->budget--) { s->failed_pc=0x0c054d8au; return 0; }
wide=(uint64_t)r[6]*r[0]; r[19]=(uint32_t)wide; r[20]=(uint32_t)(wide>>32);
goto P_0c054d8c;
P_0c054d8c: /* original 060a, guest PC 0x0c054d8c */
if(!s->budget--) { s->failed_pc=0x0c054d8cu; return 0; }
r[6]=r[20];
goto P_0c054d8e;
P_0c054d8e: /* original 031a, guest PC 0x0c054d8e */
if(!s->budget--) { s->failed_pc=0x0c054d8eu; return 0; }
r[3]=r[19];
goto P_0c054d90;
P_0c054d90: /* original 4f16, guest PC 0x0c054d90 */
if(!s->budget--) { s->failed_pc=0x0c054d90u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c054d92;
P_0c054d92: /* original 2228, guest PC 0x0c054d92 */
if(!s->budget--) { s->failed_pc=0x0c054d92u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c054d94;
P_0c054d94: /* original 4f06, guest PC 0x0c054d94 */
if(!s->budget--) { s->failed_pc=0x0c054d94u; return 0; }
r[20]=read(ram,r[15],4); r[15]+=4;
goto P_0c054d96;
P_0c054d96: /* original 8d09, guest PC 0x0c054d96 */
if(!s->budget--) { s->failed_pc=0x0c054d96u; return 0; }
cond=r[17]&1u;
r[7]|=r[3];
if(cond) { goto P_0c054dac; }
goto P_0c054d9a;
P_0c054d98: /* original 273b, guest PC 0x0c054d98 */
if(!s->budget--) { s->failed_pc=0x0c054d98u; return 0; }
r[7]|=r[3];
goto P_0c054d9a;
P_0c054d9a: /* original a007, guest PC 0x0c054d9a */
if(!s->budget--) { s->failed_pc=0x0c054d9au; return 0; }
r[7]|=r[9];
goto P_0c054dac;
P_0c054d9c: /* original 279b, guest PC 0x0c054d9c */
if(!s->budget--) { s->failed_pc=0x0c054d9cu; return 0; }
r[7]|=r[9];
goto P_0c054d9e;
P_0c054d9e: /* original e600, guest PC 0x0c054d9e */
if(!s->budget--) { s->failed_pc=0x0c054d9eu; return 0; }
r[6]=0x00000000u;
goto P_0c054da0;
P_0c054da0: /* original a004, guest PC 0x0c054da0 */
if(!s->budget--) { s->failed_pc=0x0c054da0u; return 0; }
r[7]=0x00000001u;
goto P_0c054dac;
P_0c054da2: /* original e701, guest PC 0x0c054da2 */
if(!s->budget--) { s->failed_pc=0x0c054da2u; return 0; }
r[7]=0x00000001u;
goto P_0c054da4;
P_0c054da4: /* original 4601, guest PC 0x0c054da4 */
if(!s->budget--) { s->failed_pc=0x0c054da4u; return 0; }
r[17]=(r[17]&~1u)|((r[6]&1)!=0);
r[6]>>=1;
goto P_0c054da6;
P_0c054da6: /* original 4725, guest PC 0x0c054da6 */
if(!s->budget--) { s->failed_pc=0x0c054da6u; return 0; }
tmp=r[7]&1u; r[7]=(r[7]>>1)|((r[17]&1u)<<31);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c054da8;
P_0c054da8: /* original 4210, guest PC 0x0c054da8 */
if(!s->budget--) { s->failed_pc=0x0c054da8u; return 0; }
--r[2];
r[17]=(r[17]&~1u)|((r[2]==0)!=0);
goto P_0c054daa;
P_0c054daa: /* original 8bfb, guest PC 0x0c054daa */
if(!s->budget--) { s->failed_pc=0x0c054daau; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c054da4; }
goto P_0c054dac;
P_0c054dac: /* original 2ba7, guest PC 0x0c054dac */
if(!s->budget--) { s->failed_pc=0x0c054dacu; return 0; }
r[17]=(r[17]&~0x301u)|((r[11]>>31)<<8)|((r[10]>>31)<<9)|(((r[11]^r[10])>>31)&1u);
goto P_0c054dae;
P_0c054dae: /* original 890f, guest PC 0x0c054dae */
if(!s->budget--) { s->failed_pc=0x0c054daeu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c054dd0; }
goto P_0c054db0;
P_0c054db0: /* original 357e, guest PC 0x0c054db0 */
if(!s->budget--) { s->failed_pc=0x0c054db0u; return 0; }
wide=(uint64_t)r[5]+r[7]+(r[17]&1u); r[5]=(uint32_t)wide;
r[17]=(r[17]&~1u)|((wide>>32)!=0);
goto P_0c054db2;
P_0c054db2: /* original 346e, guest PC 0x0c054db2 */
if(!s->budget--) { s->failed_pc=0x0c054db2u; return 0; }
wide=(uint64_t)r[4]+r[6]+(r[17]&1u); r[4]=(uint32_t)wide;
r[17]=(r[17]&~1u)|((wide>>32)!=0);
goto P_0c054db4;
P_0c054db4: /* original d352, guest PC 0x0c054db4 */
if(!s->budget--) { s->failed_pc=0x0c054db4u; return 0; }
r[3]=read(ram,0x0c054f00u,4);
goto P_0c054db6;
P_0c054db6: /* original 3347, guest PC 0x0c054db6 */
if(!s->budget--) { s->failed_pc=0x0c054db6u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>(int32_t)r[4])!=0);
goto P_0c054db8;
P_0c054db8: /* original 8952, guest PC 0x0c054db8 */
if(!s->budget--) { s->failed_pc=0x0c054db8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c054e60; }
goto P_0c054dba;
P_0c054dba: /* original 4401, guest PC 0x0c054dba */
if(!s->budget--) { s->failed_pc=0x0c054dbau; return 0; }
r[17]=(r[17]&~1u)|((r[4]&1)!=0);
r[4]>>=1;
goto P_0c054dbc;
P_0c054dbc: /* original 4525, guest PC 0x0c054dbc */
if(!s->budget--) { s->failed_pc=0x0c054dbcu; return 0; }
tmp=r[5]&1u; r[5]=(r[5]>>1)|((r[17]&1u)<<31);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c054dbe;
P_0c054dbe: /* original 0229, guest PC 0x0c054dbe */
if(!s->budget--) { s->failed_pc=0x0c054dbeu; return 0; }
r[2]=r[17]&1u;
goto P_0c054dc0;
P_0c054dc0: /* original 252b, guest PC 0x0c054dc0 */
if(!s->budget--) { s->failed_pc=0x0c054dc0u; return 0; }
r[5]|=r[2];
goto P_0c054dc2;
P_0c054dc2: /* original 7801, guest PC 0x0c054dc2 */
if(!s->budget--) { s->failed_pc=0x0c054dc2u; return 0; }
r[8]+=0x00000001u;
goto P_0c054dc4;
P_0c054dc4: /* original d34a, guest PC 0x0c054dc4 */
if(!s->budget--) { s->failed_pc=0x0c054dc4u; return 0; }
r[3]=read(ram,0x0c054ef0u,4);
goto P_0c054dc6;
P_0c054dc6: /* original 3830, guest PC 0x0c054dc6 */
if(!s->budget--) { s->failed_pc=0x0c054dc6u; return 0; }
r[17]=(r[17]&~1u)|((r[8]==r[3])!=0);
goto P_0c054dc8;
P_0c054dc8: /* original 8b4a, guest PC 0x0c054dc8 */
if(!s->budget--) { s->failed_pc=0x0c054dc8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c054e60; }
goto P_0c054dca;
P_0c054dca: /* original e500, guest PC 0x0c054dca */
if(!s->budget--) { s->failed_pc=0x0c054dcau; return 0; }
r[5]=0x00000000u;
goto P_0c054dcc;
P_0c054dcc: /* original a05f, guest PC 0x0c054dcc */
if(!s->budget--) { s->failed_pc=0x0c054dccu; return 0; }
r[4]=0x00000000u;
goto P_0c054e8e;
P_0c054dce: /* original e400, guest PC 0x0c054dce */
if(!s->budget--) { s->failed_pc=0x0c054dceu; return 0; }
r[4]=0x00000000u;
goto P_0c054dd0;
P_0c054dd0: /* original 3640, guest PC 0x0c054dd0 */
if(!s->budget--) { s->failed_pc=0x0c054dd0u; return 0; }
r[17]=(r[17]&~1u)|((r[6]==r[4])!=0);
goto P_0c054dd2;
P_0c054dd2: /* original 8b01, guest PC 0x0c054dd2 */
if(!s->budget--) { s->failed_pc=0x0c054dd2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c054dd8; }
goto P_0c054dd4;
P_0c054dd4: /* original 3750, guest PC 0x0c054dd4 */
if(!s->budget--) { s->failed_pc=0x0c054dd4u; return 0; }
r[17]=(r[17]&~1u)|((r[7]==r[5])!=0);
goto P_0c054dd6;
P_0c054dd6: /* original 8979, guest PC 0x0c054dd6 */
if(!s->budget--) { s->failed_pc=0x0c054dd6u; return 0; }
cond=r[17]&1u;
if(cond) { return vf3_matrix_family(0x0c054eccu,s,ram); }
goto P_0c054dd8;
P_0c054dd8: /* original 357a, guest PC 0x0c054dd8 */
if(!s->budget--) { s->failed_pc=0x0c054dd8u; return 0; }
wide=(uint64_t)r[5]-r[7]-(r[17]&1u); r[5]=(uint32_t)wide;
r[17]=(r[17]&~1u)|((wide>>32)!=0);
goto P_0c054dda;
P_0c054dda: /* original 346a, guest PC 0x0c054dda */
if(!s->budget--) { s->failed_pc=0x0c054ddau; return 0; }
wide=(uint64_t)r[4]-r[6]-(r[17]&1u); r[4]=(uint32_t)wide;
r[17]=(r[17]&~1u)|((wide>>32)!=0);
goto P_0c054ddc;
P_0c054ddc: /* original 8b03, guest PC 0x0c054ddc */
if(!s->budget--) { s->failed_pc=0x0c054ddcu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c054de6; }
goto P_0c054dde;
P_0c054dde: /* original 0008, guest PC 0x0c054dde */
if(!s->budget--) { s->failed_pc=0x0c054ddeu; return 0; }
r[17]=(r[17]&~1u)|((0)!=0);
goto P_0c054de0;
P_0c054de0: /* original 655a, guest PC 0x0c054de0 */
if(!s->budget--) { s->failed_pc=0x0c054de0u; return 0; }
wide=0ull-(uint64_t)r[5]-(r[17]&1u); r[5]=(uint32_t)wide;
r[17]=(r[17]&~1u)|((wide>>32)!=0);
goto P_0c054de2;
P_0c054de2: /* original 644a, guest PC 0x0c054de2 */
if(!s->budget--) { s->failed_pc=0x0c054de2u; return 0; }
wide=0ull-(uint64_t)r[4]-(r[17]&1u); r[4]=(uint32_t)wide;
r[17]=(r[17]&~1u)|((wide>>32)!=0);
goto P_0c054de4;
P_0c054de4: /* original 6ab3, guest PC 0x0c054de4 */
if(!s->budget--) { s->failed_pc=0x0c054de4u; return 0; }
r[10]=r[11];
goto P_0c054de6;
P_0c054de6: /* original 2448, guest PC 0x0c054de6 */
if(!s->budget--) { s->failed_pc=0x0c054de6u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c054de8;
P_0c054de8: /* original 8b02, guest PC 0x0c054de8 */
if(!s->budget--) { s->failed_pc=0x0c054de8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c054df0; }
goto P_0c054dea;
P_0c054dea: /* original 6453, guest PC 0x0c054dea */
if(!s->budget--) { s->failed_pc=0x0c054deau; return 0; }
r[4]=r[5];
goto P_0c054dec;
P_0c054dec: /* original e500, guest PC 0x0c054dec */
if(!s->budget--) { s->failed_pc=0x0c054decu; return 0; }
r[5]=0x00000000u;
goto P_0c054dee;
P_0c054dee: /* original 78e0, guest PC 0x0c054dee */
if(!s->budget--) { s->failed_pc=0x0c054deeu; return 0; }
r[8]+=0xffffffe0u;
goto P_0c054df0;
P_0c054df0: /* original d346, guest PC 0x0c054df0 */
if(!s->budget--) { s->failed_pc=0x0c054df0u; return 0; }
r[3]=read(ram,0x0c054f0cu,4);
goto P_0c054df2;
P_0c054df2: /* original 2348, guest PC 0x0c054df2 */
if(!s->budget--) { s->failed_pc=0x0c054df2u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[4])==0)!=0);
goto P_0c054df4;
P_0c054df4: /* original 8b04, guest PC 0x0c054df4 */
if(!s->budget--) { s->failed_pc=0x0c054df4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c054e00; }
goto P_0c054df6;
P_0c054df6: /* original 6353, guest PC 0x0c054df6 */
if(!s->budget--) { s->failed_pc=0x0c054df6u; return 0; }
r[3]=r[5];
goto P_0c054df8;
P_0c054df8: /* original 234d, guest PC 0x0c054df8 */
if(!s->budget--) { s->failed_pc=0x0c054df8u; return 0; }
r[3]=(r[3]>>16)|(r[4]<<16);
goto P_0c054dfa;
P_0c054dfa: /* original 6433, guest PC 0x0c054dfa */
if(!s->budget--) { s->failed_pc=0x0c054dfau; return 0; }
r[4]=r[3];
goto P_0c054dfc;
P_0c054dfc: /* original 4528, guest PC 0x0c054dfc */
if(!s->budget--) { s->failed_pc=0x0c054dfcu; return 0; }
r[5]<<=16;
goto P_0c054dfe;
P_0c054dfe: /* original 78f0, guest PC 0x0c054dfe */
if(!s->budget--) { s->failed_pc=0x0c054dfeu; return 0; }
r[8]+=0xfffffff0u;
goto P_0c054e00;
P_0c054e00: /* original d33f, guest PC 0x0c054e00 */
if(!s->budget--) { s->failed_pc=0x0c054e00u; return 0; }
r[3]=read(ram,0x0c054f00u,4);
goto P_0c054e02;
P_0c054e02: /* original 3346, guest PC 0x0c054e02 */
if(!s->budget--) { s->failed_pc=0x0c054e02u; return 0; }
r[17]=(r[17]&~1u)|((r[3]>r[4])!=0);
goto P_0c054e04;
P_0c054e04: /* original 8915, guest PC 0x0c054e04 */
if(!s->budget--) { s->failed_pc=0x0c054e04u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c054e32; }
goto P_0c054e06;
P_0c054e06: /* original 4401, guest PC 0x0c054e06 */
if(!s->budget--) { s->failed_pc=0x0c054e06u; return 0; }
r[17]=(r[17]&~1u)|((r[4]&1)!=0);
r[4]>>=1;
goto P_0c054e08;
P_0c054e08: /* original 4525, guest PC 0x0c054e08 */
if(!s->budget--) { s->failed_pc=0x0c054e08u; return 0; }
tmp=r[5]&1u; r[5]=(r[5]>>1)|((r[17]&1u)<<31);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c054e0a;
P_0c054e0a: /* original 3346, guest PC 0x0c054e0a */
if(!s->budget--) { s->failed_pc=0x0c054e0au; return 0; }
r[17]=(r[17]&~1u)|((r[3]>r[4])!=0);
goto P_0c054e0c;
P_0c054e0c: /* original 8d28, guest PC 0x0c054e0c */
if(!s->budget--) { s->failed_pc=0x0c054e0cu; return 0; }
cond=r[17]&1u;
r[8]+=0x00000001u;
if(cond) { goto P_0c054e60; }
goto P_0c054e10;
P_0c054e0e: /* original 7801, guest PC 0x0c054e0e */
if(!s->budget--) { s->failed_pc=0x0c054e0eu; return 0; }
r[8]+=0x00000001u;
goto P_0c054e10;
P_0c054e10: /* original 4401, guest PC 0x0c054e10 */
if(!s->budget--) { s->failed_pc=0x0c054e10u; return 0; }
r[17]=(r[17]&~1u)|((r[4]&1)!=0);
r[4]>>=1;
goto P_0c054e12;
P_0c054e12: /* original 4525, guest PC 0x0c054e12 */
if(!s->budget--) { s->failed_pc=0x0c054e12u; return 0; }
tmp=r[5]&1u; r[5]=(r[5]>>1)|((r[17]&1u)<<31);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c054e14;
P_0c054e14: /* original 3346, guest PC 0x0c054e14 */
if(!s->budget--) { s->failed_pc=0x0c054e14u; return 0; }
r[17]=(r[17]&~1u)|((r[3]>r[4])!=0);
goto P_0c054e16;
P_0c054e16: /* original 8d23, guest PC 0x0c054e16 */
if(!s->budget--) { s->failed_pc=0x0c054e16u; return 0; }
cond=r[17]&1u;
r[8]+=0x00000001u;
if(cond) { goto P_0c054e60; }
goto P_0c054e1a;
P_0c054e18: /* original 7801, guest PC 0x0c054e18 */
if(!s->budget--) { s->failed_pc=0x0c054e18u; return 0; }
r[8]+=0x00000001u;
goto P_0c054e1a;
P_0c054e1a: /* original 4401, guest PC 0x0c054e1a */
if(!s->budget--) { s->failed_pc=0x0c054e1au; return 0; }
r[17]=(r[17]&~1u)|((r[4]&1)!=0);
r[4]>>=1;
goto P_0c054e1c;
P_0c054e1c: /* original 4525, guest PC 0x0c054e1c */
if(!s->budget--) { s->failed_pc=0x0c054e1cu; return 0; }
tmp=r[5]&1u; r[5]=(r[5]>>1)|((r[17]&1u)<<31);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c054e1e;
P_0c054e1e: /* original 3346, guest PC 0x0c054e1e */
if(!s->budget--) { s->failed_pc=0x0c054e1eu; return 0; }
r[17]=(r[17]&~1u)|((r[3]>r[4])!=0);
goto P_0c054e20;
P_0c054e20: /* original 8d1e, guest PC 0x0c054e20 */
if(!s->budget--) { s->failed_pc=0x0c054e20u; return 0; }
cond=r[17]&1u;
r[8]+=0x00000001u;
if(cond) { goto P_0c054e60; }
goto P_0c054e24;
P_0c054e22: /* original 7801, guest PC 0x0c054e22 */
if(!s->budget--) { s->failed_pc=0x0c054e22u; return 0; }
r[8]+=0x00000001u;
goto P_0c054e24;
P_0c054e24: /* original 4401, guest PC 0x0c054e24 */
if(!s->budget--) { s->failed_pc=0x0c054e24u; return 0; }
r[17]=(r[17]&~1u)|((r[4]&1)!=0);
r[4]>>=1;
goto P_0c054e26;
P_0c054e26: /* original 4525, guest PC 0x0c054e26 */
if(!s->budget--) { s->failed_pc=0x0c054e26u; return 0; }
tmp=r[5]&1u; r[5]=(r[5]>>1)|((r[17]&1u)<<31);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c054e28;
P_0c054e28: /* original 3346, guest PC 0x0c054e28 */
if(!s->budget--) { s->failed_pc=0x0c054e28u; return 0; }
r[17]=(r[17]&~1u)|((r[3]>r[4])!=0);
goto P_0c054e2a;
P_0c054e2a: /* original 8d19, guest PC 0x0c054e2a */
if(!s->budget--) { s->failed_pc=0x0c054e2au; return 0; }
cond=r[17]&1u;
r[8]+=0x00000001u;
if(cond) { goto P_0c054e60; }
goto P_0c054e2e;
P_0c054e2c: /* original 7801, guest PC 0x0c054e2c */
if(!s->budget--) { s->failed_pc=0x0c054e2cu; return 0; }
r[8]+=0x00000001u;
goto P_0c054e2e;
P_0c054e2e: /* original afea, guest PC 0x0c054e2e */
if(!s->budget--) { s->failed_pc=0x0c054e2eu; return 0; }
goto P_0c054e06;
P_0c054e30: /* original 0009, guest PC 0x0c054e30 */
if(!s->budget--) { s->failed_pc=0x0c054e30u; return 0; }
goto P_0c054e32;
P_0c054e32: /* original d331, guest PC 0x0c054e32 */
if(!s->budget--) { s->failed_pc=0x0c054e32u; return 0; }
r[3]=read(ram,0x0c054ef8u,4);
goto P_0c054e34;
P_0c054e34: /* original 3433, guest PC 0x0c054e34 */
if(!s->budget--) { s->failed_pc=0x0c054e34u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[3])!=0);
goto P_0c054e36;
P_0c054e36: /* original 8913, guest PC 0x0c054e36 */
if(!s->budget--) { s->failed_pc=0x0c054e36u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c054e60; }
goto P_0c054e38;
P_0c054e38: /* original 4500, guest PC 0x0c054e38 */
if(!s->budget--) { s->failed_pc=0x0c054e38u; return 0; }
r[17]=(r[17]&~1u)|((r[5]>>31)!=0);
r[5]<<=1;
goto P_0c054e3a;
P_0c054e3a: /* original 4424, guest PC 0x0c054e3a */
if(!s->budget--) { s->failed_pc=0x0c054e3au; return 0; }
tmp=r[4]>>31; r[4]=(r[4]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c054e3c;
P_0c054e3c: /* original 3433, guest PC 0x0c054e3c */
if(!s->budget--) { s->failed_pc=0x0c054e3cu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[3])!=0);
goto P_0c054e3e;
P_0c054e3e: /* original 8d0f, guest PC 0x0c054e3e */
if(!s->budget--) { s->failed_pc=0x0c054e3eu; return 0; }
cond=r[17]&1u;
r[8]+=0xffffffffu;
if(cond) { goto P_0c054e60; }
goto P_0c054e42;
P_0c054e40: /* original 78ff, guest PC 0x0c054e40 */
if(!s->budget--) { s->failed_pc=0x0c054e40u; return 0; }
r[8]+=0xffffffffu;
goto P_0c054e42;
P_0c054e42: /* original 4500, guest PC 0x0c054e42 */
if(!s->budget--) { s->failed_pc=0x0c054e42u; return 0; }
r[17]=(r[17]&~1u)|((r[5]>>31)!=0);
r[5]<<=1;
goto P_0c054e44;
P_0c054e44: /* original 4424, guest PC 0x0c054e44 */
if(!s->budget--) { s->failed_pc=0x0c054e44u; return 0; }
tmp=r[4]>>31; r[4]=(r[4]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c054e46;
P_0c054e46: /* original 3433, guest PC 0x0c054e46 */
if(!s->budget--) { s->failed_pc=0x0c054e46u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[3])!=0);
goto P_0c054e48;
P_0c054e48: /* original 8d0a, guest PC 0x0c054e48 */
if(!s->budget--) { s->failed_pc=0x0c054e48u; return 0; }
cond=r[17]&1u;
r[8]+=0xffffffffu;
if(cond) { goto P_0c054e60; }
goto P_0c054e4c;
P_0c054e4a: /* original 78ff, guest PC 0x0c054e4a */
if(!s->budget--) { s->failed_pc=0x0c054e4au; return 0; }
r[8]+=0xffffffffu;
goto P_0c054e4c;
P_0c054e4c: /* original 4500, guest PC 0x0c054e4c */
if(!s->budget--) { s->failed_pc=0x0c054e4cu; return 0; }
r[17]=(r[17]&~1u)|((r[5]>>31)!=0);
r[5]<<=1;
goto P_0c054e4e;
P_0c054e4e: /* original 4424, guest PC 0x0c054e4e */
if(!s->budget--) { s->failed_pc=0x0c054e4eu; return 0; }
tmp=r[4]>>31; r[4]=(r[4]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c054e50;
P_0c054e50: /* original 3433, guest PC 0x0c054e50 */
if(!s->budget--) { s->failed_pc=0x0c054e50u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[3])!=0);
goto P_0c054e52;
P_0c054e52: /* original 8d05, guest PC 0x0c054e52 */
if(!s->budget--) { s->failed_pc=0x0c054e52u; return 0; }
cond=r[17]&1u;
r[8]+=0xffffffffu;
if(cond) { goto P_0c054e60; }
goto P_0c054e56;
P_0c054e54: /* original 78ff, guest PC 0x0c054e54 */
if(!s->budget--) { s->failed_pc=0x0c054e54u; return 0; }
r[8]+=0xffffffffu;
goto P_0c054e56;
P_0c054e56: /* original 4500, guest PC 0x0c054e56 */
if(!s->budget--) { s->failed_pc=0x0c054e56u; return 0; }
r[17]=(r[17]&~1u)|((r[5]>>31)!=0);
r[5]<<=1;
goto P_0c054e58;
P_0c054e58: /* original 4424, guest PC 0x0c054e58 */
if(!s->budget--) { s->failed_pc=0x0c054e58u; return 0; }
tmp=r[4]>>31; r[4]=(r[4]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c054e5a;
P_0c054e5a: /* original 3433, guest PC 0x0c054e5a */
if(!s->budget--) { s->failed_pc=0x0c054e5au; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[3])!=0);
goto P_0c054e5c;
P_0c054e5c: /* original 8fec, guest PC 0x0c054e5c */
if(!s->budget--) { s->failed_pc=0x0c054e5cu; return 0; }
cond=r[17]&1u;
r[8]+=0xffffffffu;
if(!cond) { goto P_0c054e38; }
goto P_0c054e60;
P_0c054e5e: /* original 78ff, guest PC 0x0c054e5e */
if(!s->budget--) { s->failed_pc=0x0c054e5eu; return 0; }
r[8]+=0xffffffffu;
goto P_0c054e60;
P_0c054e60: /* original 4815, guest PC 0x0c054e60 */
if(!s->budget--) { s->failed_pc=0x0c054e60u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[8]>0)!=0);
goto P_0c054e62;
P_0c054e62: /* original 8905, guest PC 0x0c054e62 */
if(!s->budget--) { s->failed_pc=0x0c054e62u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c054e70; }
goto P_0c054e64;
P_0c054e64: /* original 688b, guest PC 0x0c054e64 */
if(!s->budget--) { s->failed_pc=0x0c054e64u; return 0; }
r[8]=0u-r[8];
goto P_0c054e66;
P_0c054e66: /* original 7801, guest PC 0x0c054e66 */
if(!s->budget--) { s->failed_pc=0x0c054e66u; return 0; }
r[8]+=0x00000001u;
goto P_0c054e68;
P_0c054e68: /* original 4401, guest PC 0x0c054e68 */
if(!s->budget--) { s->failed_pc=0x0c054e68u; return 0; }
r[17]=(r[17]&~1u)|((r[4]&1)!=0);
r[4]>>=1;
goto P_0c054e6a;
P_0c054e6a: /* original 4525, guest PC 0x0c054e6a */
if(!s->budget--) { s->failed_pc=0x0c054e6au; return 0; }
tmp=r[5]&1u; r[5]=(r[5]>>1)|((r[17]&1u)<<31);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c054e6c;
P_0c054e6c: /* original 4810, guest PC 0x0c054e6c */
if(!s->budget--) { s->failed_pc=0x0c054e6cu; return 0; }
--r[8];
r[17]=(r[17]&~1u)|((r[8]==0)!=0);
goto P_0c054e6e;
P_0c054e6e: /* original 8bfb, guest PC 0x0c054e6e */
if(!s->budget--) { s->failed_pc=0x0c054e6eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c054e68; }
goto P_0c054e70;
P_0c054e70: /* original 6053, guest PC 0x0c054e70 */
if(!s->budget--) { s->failed_pc=0x0c054e70u; return 0; }
r[0]=r[5];
goto P_0c054e72;
P_0c054e72: /* original c804, guest PC 0x0c054e72 */
if(!s->budget--) { s->failed_pc=0x0c054e72u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&4u)==0)!=0);
goto P_0c054e74;
P_0c054e74: /* original 890b, guest PC 0x0c054e74 */
if(!s->budget--) { s->failed_pc=0x0c054e74u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c054e8e; }
goto P_0c054e76;
P_0c054e76: /* original c80b, guest PC 0x0c054e76 */
if(!s->budget--) { s->failed_pc=0x0c054e76u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&11u)==0)!=0);
goto P_0c054e78;
P_0c054e78: /* original 8909, guest PC 0x0c054e78 */
if(!s->budget--) { s->failed_pc=0x0c054e78u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c054e8e; }
goto P_0c054e7a;
P_0c054e7a: /* original e008, guest PC 0x0c054e7a */
if(!s->budget--) { s->failed_pc=0x0c054e7au; return 0; }
r[0]=0x00000008u;
goto P_0c054e7c;
P_0c054e7c: /* original 350e, guest PC 0x0c054e7c */
if(!s->budget--) { s->failed_pc=0x0c054e7cu; return 0; }
wide=(uint64_t)r[5]+r[0]+(r[17]&1u); r[5]=(uint32_t)wide;
r[17]=(r[17]&~1u)|((wide>>32)!=0);
goto P_0c054e7e;
P_0c054e7e: /* original e000, guest PC 0x0c054e7e */
if(!s->budget--) { s->failed_pc=0x0c054e7eu; return 0; }
r[0]=0x00000000u;
goto P_0c054e80;
P_0c054e80: /* original 340e, guest PC 0x0c054e80 */
if(!s->budget--) { s->failed_pc=0x0c054e80u; return 0; }
wide=(uint64_t)r[4]+r[0]+(r[17]&1u); r[4]=(uint32_t)wide;
r[17]=(r[17]&~1u)|((wide>>32)!=0);
goto P_0c054e82;
P_0c054e82: /* original d01f, guest PC 0x0c054e82 */
if(!s->budget--) { s->failed_pc=0x0c054e82u; return 0; }
r[0]=read(ram,0x0c054f00u,4);
goto P_0c054e84;
P_0c054e84: /* original 3047, guest PC 0x0c054e84 */
if(!s->budget--) { s->failed_pc=0x0c054e84u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[0]>(int32_t)r[4])!=0);
goto P_0c054e86;
P_0c054e86: /* original 8902, guest PC 0x0c054e86 */
if(!s->budget--) { s->failed_pc=0x0c054e86u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c054e8e; }
goto P_0c054e88;
P_0c054e88: /* original 4401, guest PC 0x0c054e88 */
if(!s->budget--) { s->failed_pc=0x0c054e88u; return 0; }
r[17]=(r[17]&~1u)|((r[4]&1)!=0);
r[4]>>=1;
goto P_0c054e8a;
P_0c054e8a: /* original 4525, guest PC 0x0c054e8a */
if(!s->budget--) { s->failed_pc=0x0c054e8au; return 0; }
tmp=r[5]&1u; r[5]=(r[5]>>1)|((r[17]&1u)<<31);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c054e8c;
P_0c054e8c: /* original 7801, guest PC 0x0c054e8c */
if(!s->budget--) { s->failed_pc=0x0c054e8cu; return 0; }
r[8]+=0x00000001u;
goto P_0c054e8e;
P_0c054e8e: /* original 4401, guest PC 0x0c054e8e */
if(!s->budget--) { s->failed_pc=0x0c054e8eu; return 0; }
r[17]=(r[17]&~1u)|((r[4]&1)!=0);
r[4]>>=1;
goto P_0c054e90;
P_0c054e90: /* original 4525, guest PC 0x0c054e90 */
if(!s->budget--) { s->failed_pc=0x0c054e90u; return 0; }
tmp=r[5]&1u; r[5]=(r[5]>>1)|((r[17]&1u)<<31);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c054e92;
P_0c054e92: /* original 4401, guest PC 0x0c054e92 */
if(!s->budget--) { s->failed_pc=0x0c054e92u; return 0; }
r[17]=(r[17]&~1u)|((r[4]&1)!=0);
r[4]>>=1;
goto P_0c054e94;
P_0c054e94: /* original 4525, guest PC 0x0c054e94 */
if(!s->budget--) { s->failed_pc=0x0c054e94u; return 0; }
tmp=r[5]&1u; r[5]=(r[5]>>1)|((r[17]&1u)<<31);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c054e96;
P_0c054e96: /* original 4401, guest PC 0x0c054e96 */
if(!s->budget--) { s->failed_pc=0x0c054e96u; return 0; }
r[17]=(r[17]&~1u)|((r[4]&1)!=0);
r[4]>>=1;
goto P_0c054e98;
P_0c054e98: /* original 4525, guest PC 0x0c054e98 */
if(!s->budget--) { s->failed_pc=0x0c054e98u; return 0; }
tmp=r[5]&1u; r[5]=(r[5]>>1)|((r[17]&1u)<<31);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c054e9a;
P_0c054e9a: /* original d016, guest PC 0x0c054e9a */
if(!s->budget--) { s->failed_pc=0x0c054e9au; return 0; }
r[0]=read(ram,0x0c054ef4u,4);
goto P_0c054e9c;
P_0c054e9c: /* original 2409, guest PC 0x0c054e9c */
if(!s->budget--) { s->failed_pc=0x0c054e9cu; return 0; }
r[4]&=r[0];
goto P_0c054e9e;
P_0c054e9e: /* original 4828, guest PC 0x0c054e9e */
if(!s->budget--) { s->failed_pc=0x0c054e9eu; return 0; }
r[8]<<=16;
goto P_0c054ea0;
P_0c054ea0: /* original 4808, guest PC 0x0c054ea0 */
if(!s->budget--) { s->failed_pc=0x0c054ea0u; return 0; }
r[8]<<=2;
goto P_0c054ea2;
P_0c054ea2: /* original 4808, guest PC 0x0c054ea2 */
if(!s->budget--) { s->failed_pc=0x0c054ea2u; return 0; }
r[8]<<=2;
goto P_0c054ea4;
P_0c054ea4: /* original 248b, guest PC 0x0c054ea4 */
if(!s->budget--) { s->failed_pc=0x0c054ea4u; return 0; }
r[4]|=r[8];
goto P_0c054ea6;
P_0c054ea6: /* original 4400, guest PC 0x0c054ea6 */
if(!s->budget--) { s->failed_pc=0x0c054ea6u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c054ea8;
P_0c054ea8: /* original 4a00, guest PC 0x0c054ea8 */
if(!s->budget--) { s->failed_pc=0x0c054ea8u; return 0; }
r[17]=(r[17]&~1u)|((r[10]>>31)!=0);
r[10]<<=1;
goto P_0c054eaa;
P_0c054eaa: /* original 4425, guest PC 0x0c054eaa */
if(!s->budget--) { s->failed_pc=0x0c054eaau; return 0; }
tmp=r[4]&1u; r[4]=(r[4]>>1)|((r[17]&1u)<<31);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c054eac;
P_0c054eac: /* original 6bf6, guest PC 0x0c054eac */
if(!s->budget--) { s->failed_pc=0x0c054eacu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c054eae;
P_0c054eae: /* original 6af6, guest PC 0x0c054eae */
if(!s->budget--) { s->failed_pc=0x0c054eaeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c054eb0;
P_0c054eb0: /* original 69f6, guest PC 0x0c054eb0 */
if(!s->budget--) { s->failed_pc=0x0c054eb0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c054eb2;
P_0c054eb2: /* original 68f6, guest PC 0x0c054eb2 */
if(!s->budget--) { s->failed_pc=0x0c054eb2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c054eb4;
P_0c054eb4: /* original 63f6, guest PC 0x0c054eb4 */
if(!s->budget--) { s->failed_pc=0x0c054eb4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[3]=tmp;
goto P_0c054eb6;
P_0c054eb6: /* original 62f6, guest PC 0x0c054eb6 */
if(!s->budget--) { s->failed_pc=0x0c054eb6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[2]=tmp;
goto P_0c054eb8;
P_0c054eb8: /* original 56f5, guest PC 0x0c054eb8 */
if(!s->budget--) { s->failed_pc=0x0c054eb8u; return 0; }
r[6]=read(ram,r[15]+20,4);
goto P_0c054eba;
P_0c054eba: /* original 2652, guest PC 0x0c054eba */
if(!s->budget--) { s->failed_pc=0x0c054ebau; return 0; }
write(ram,r[6],r[5],4);
goto P_0c054ebc;
P_0c054ebc: /* original 1641, guest PC 0x0c054ebc */
if(!s->budget--) { s->failed_pc=0x0c054ebcu; return 0; }
write(ram,r[6]+4,r[4],4);
goto P_0c054ebe;
P_0c054ebe: /* original 67f6, guest PC 0x0c054ebe */
if(!s->budget--) { s->failed_pc=0x0c054ebeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[7]=tmp;
goto P_0c054ec0;
P_0c054ec0: /* original 66f6, guest PC 0x0c054ec0 */
if(!s->budget--) { s->failed_pc=0x0c054ec0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[6]=tmp;
goto P_0c054ec2;
P_0c054ec2: /* original 65f6, guest PC 0x0c054ec2 */
if(!s->budget--) { s->failed_pc=0x0c054ec2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[5]=tmp;
goto P_0c054ec4;
P_0c054ec4: /* original 64f6, guest PC 0x0c054ec4 */
if(!s->budget--) { s->failed_pc=0x0c054ec4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[4]=tmp;
goto P_0c054ec6;
P_0c054ec6: /* original 60f6, guest PC 0x0c054ec6 */
if(!s->budget--) { s->failed_pc=0x0c054ec6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[0]=tmp;
goto P_0c054ec8;
P_0c054ec8: /* original 000b, guest PC 0x0c054ec8 */
if(!s->budget--) { s->failed_pc=0x0c054ec8u; return 0; }
target=r[16];
r[15]+=0x00000014u;
s->pc=target; return ram->oob==0;
P_0c054eca: /* original 7f14, guest PC 0x0c054eca */
if(!s->budget--) { s->failed_pc=0x0c054ecau; return 0; }
r[15]+=0x00000014u;
return vf3_matrix_family(0x0c054eccu,s,ram);
unsupported: s->failed_pc=target; return 0;
}
