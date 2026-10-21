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
int vf3_c96_adapter(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u;
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c034cecu: goto P_0c034cec;
case 0x0c034ceeu: goto P_0c034cee;
case 0x0c034cf0u: goto P_0c034cf0;
case 0x0c034cf2u: goto P_0c034cf2;
case 0x0c034cf4u: goto P_0c034cf4;
case 0x0c034cf6u: goto P_0c034cf6;
case 0x0c034cf8u: goto P_0c034cf8;
case 0x0c034d14u: goto P_0c034d14;
case 0x0c034d16u: goto P_0c034d16;
case 0x0c034d18u: goto P_0c034d18;
case 0x0c034d1au: goto P_0c034d1a;
case 0x0c034d1cu: goto P_0c034d1c;
case 0x0c034d1eu: goto P_0c034d1e;
case 0x0c034d20u: goto P_0c034d20;
case 0x0c034d22u: goto P_0c034d22;
case 0x0c034d24u: goto P_0c034d24;
case 0x0c034d26u: goto P_0c034d26;
case 0x0c034d28u: goto P_0c034d28;
case 0x0c034d2au: goto P_0c034d2a;
case 0x0c034d2cu: goto P_0c034d2c;
case 0x0c034d2eu: goto P_0c034d2e;
case 0x0c034d30u: goto P_0c034d30;
case 0x0c034d32u: goto P_0c034d32;
case 0x0c034d34u: goto P_0c034d34;
case 0x0c034d36u: goto P_0c034d36;
case 0x0c034d38u: goto P_0c034d38;
case 0x0c034d3au: goto P_0c034d3a;
case 0x0c034d3cu: goto P_0c034d3c;
case 0x0c034d3eu: goto P_0c034d3e;
case 0x0c034d40u: goto P_0c034d40;
case 0x0c034d42u: goto P_0c034d42;
case 0x0c034d44u: goto P_0c034d44;
case 0x0c034d46u: goto P_0c034d46;
case 0x0c034d48u: goto P_0c034d48;
case 0x0c034d4au: goto P_0c034d4a;
case 0x0c034d4cu: goto P_0c034d4c;
case 0x0c034d4eu: goto P_0c034d4e;
case 0x0c034d50u: goto P_0c034d50;
case 0x0c034d52u: goto P_0c034d52;
case 0x0c034d54u: goto P_0c034d54;
case 0x0c034d56u: goto P_0c034d56;
case 0x0c034d58u: goto P_0c034d58;
case 0x0c034d5au: goto P_0c034d5a;
case 0x0c034d5cu: goto P_0c034d5c;
case 0x0c034d5eu: goto P_0c034d5e;
case 0x0c034d60u: goto P_0c034d60;
case 0x0c034d62u: goto P_0c034d62;
case 0x0c034d64u: goto P_0c034d64;
case 0x0c034d66u: goto P_0c034d66;
case 0x0c034d68u: goto P_0c034d68;
case 0x0c034d6au: goto P_0c034d6a;
case 0x0c034d6cu: goto P_0c034d6c;
case 0x0c034d6eu: goto P_0c034d6e;
case 0x0c034d70u: goto P_0c034d70;
case 0x0c034d72u: goto P_0c034d72;
case 0x0c034d74u: goto P_0c034d74;
case 0x0c034d76u: goto P_0c034d76;
case 0x0c034d78u: goto P_0c034d78;
case 0x0c034d7au: goto P_0c034d7a;
case 0x0c034d7cu: goto P_0c034d7c;
case 0x0c034d7eu: goto P_0c034d7e;
case 0x0c034d80u: goto P_0c034d80;
case 0x0c034d82u: goto P_0c034d82;
case 0x0c034d84u: goto P_0c034d84;
case 0x0c034d86u: goto P_0c034d86;
case 0x0c034d88u: goto P_0c034d88;
case 0x0c034d8au: goto P_0c034d8a;
case 0x0c034d8cu: goto P_0c034d8c;
case 0x0c034d8eu: goto P_0c034d8e;
case 0x0c034d90u: goto P_0c034d90;
case 0x0c034d92u: goto P_0c034d92;
case 0x0c034d94u: goto P_0c034d94;
case 0x0c034d96u: goto P_0c034d96;
case 0x0c034d98u: goto P_0c034d98;
case 0x0c034d9au: goto P_0c034d9a;
case 0x0c034d9cu: goto P_0c034d9c;
case 0x0c034d9eu: goto P_0c034d9e;
case 0x0c034da0u: goto P_0c034da0;
case 0x0c034da2u: goto P_0c034da2;
case 0x0c034da4u: goto P_0c034da4;
case 0x0c034da6u: goto P_0c034da6;
case 0x0c034da8u: goto P_0c034da8;
case 0x0c034daau: goto P_0c034daa;
case 0x0c034dacu: goto P_0c034dac;
case 0x0c034daeu: goto P_0c034dae;
case 0x0c034db0u: goto P_0c034db0;
case 0x0c034db2u: goto P_0c034db2;
case 0x0c034db4u: goto P_0c034db4;
case 0x0c034db6u: goto P_0c034db6;
case 0x0c034db8u: goto P_0c034db8;
case 0x0c034dbau: goto P_0c034dba;
case 0x0c034dbcu: goto P_0c034dbc;
case 0x0c034dbeu: goto P_0c034dbe;
case 0x0c034dc0u: goto P_0c034dc0;
case 0x0c034dc2u: goto P_0c034dc2;
case 0x0c034dc4u: goto P_0c034dc4;
case 0x0c034dc6u: goto P_0c034dc6;
case 0x0c034dc8u: goto P_0c034dc8;
case 0x0c034dcau: goto P_0c034dca;
case 0x0c034dccu: goto P_0c034dcc;
case 0x0c034dceu: goto P_0c034dce;
case 0x0c034dd0u: goto P_0c034dd0;
case 0x0c034dd2u: goto P_0c034dd2;
case 0x0c034dd4u: goto P_0c034dd4;
case 0x0c034dd6u: goto P_0c034dd6;
case 0x0c034dd8u: goto P_0c034dd8;
case 0x0c034ddau: goto P_0c034dda;
case 0x0c034ddcu: goto P_0c034ddc;
case 0x0c034ddeu: goto P_0c034dde;
case 0x0c034de0u: goto P_0c034de0;
case 0x0c034de2u: goto P_0c034de2;
case 0x0c034de4u: goto P_0c034de4;
case 0x0c034de6u: goto P_0c034de6;
case 0x0c034de8u: goto P_0c034de8;
case 0x0c034deau: goto P_0c034dea;
case 0x0c034decu: goto P_0c034dec;
case 0x0c034deeu: goto P_0c034dee;
case 0x0c034df0u: goto P_0c034df0;
case 0x0c034df2u: goto P_0c034df2;
case 0x0c034df4u: goto P_0c034df4;
case 0x0c034df6u: goto P_0c034df6;
case 0x0c034df8u: goto P_0c034df8;
case 0x0c034dfau: goto P_0c034dfa;
case 0x0c034dfcu: goto P_0c034dfc;
case 0x0c034dfeu: goto P_0c034dfe;
case 0x0c034e00u: goto P_0c034e00;
case 0x0c034e02u: goto P_0c034e02;
case 0x0c034e04u: goto P_0c034e04;
case 0x0c034e06u: goto P_0c034e06;
case 0x0c034e08u: goto P_0c034e08;
case 0x0c034e0au: goto P_0c034e0a;
case 0x0c034e0cu: goto P_0c034e0c;
case 0x0c034e0eu: goto P_0c034e0e;
case 0x0c034e10u: goto P_0c034e10;
case 0x0c034e12u: goto P_0c034e12;
case 0x0c034e14u: goto P_0c034e14;
case 0x0c034e16u: goto P_0c034e16;
case 0x0c034e18u: goto P_0c034e18;
case 0x0c034e1au: goto P_0c034e1a;
case 0x0c034e1cu: goto P_0c034e1c;
case 0x0c034e1eu: goto P_0c034e1e;
case 0x0c034e20u: goto P_0c034e20;
case 0x0c034e22u: goto P_0c034e22;
case 0x0c034e24u: goto P_0c034e24;
case 0x0c034e26u: goto P_0c034e26;
case 0x0c034e28u: goto P_0c034e28;
case 0x0c034e2au: goto P_0c034e2a;
case 0x0c034e2cu: goto P_0c034e2c;
case 0x0c034e2eu: goto P_0c034e2e;
case 0x0c034e30u: goto P_0c034e30;
case 0x0c034e32u: goto P_0c034e32;
case 0x0c034e34u: goto P_0c034e34;
case 0x0c034e36u: goto P_0c034e36;
case 0x0c034e38u: goto P_0c034e38;
case 0x0c034e6cu: goto P_0c034e6c;
case 0x0c034e6eu: goto P_0c034e6e;
case 0x0c034e70u: goto P_0c034e70;
case 0x0c034e72u: goto P_0c034e72;
case 0x0c034e74u: goto P_0c034e74;
case 0x0c034e76u: goto P_0c034e76;
case 0x0c034e78u: goto P_0c034e78;
case 0x0c034e7au: goto P_0c034e7a;
case 0x0c034e7cu: goto P_0c034e7c;
case 0x0c034e7eu: goto P_0c034e7e;
case 0x0c034e80u: goto P_0c034e80;
case 0x0c034e82u: goto P_0c034e82;
case 0x0c034e84u: goto P_0c034e84;
case 0x0c034e86u: goto P_0c034e86;
case 0x0c034e88u: goto P_0c034e88;
case 0x0c034e8au: goto P_0c034e8a;
case 0x0c034e8cu: goto P_0c034e8c;
case 0x0c034e8eu: goto P_0c034e8e;
case 0x0c034e90u: goto P_0c034e90;
case 0x0c034e92u: goto P_0c034e92;
case 0x0c034e94u: goto P_0c034e94;
case 0x0c034e96u: goto P_0c034e96;
case 0x0c034e98u: goto P_0c034e98;
case 0x0c034e9au: goto P_0c034e9a;
case 0x0c034e9cu: goto P_0c034e9c;
case 0x0c034e9eu: goto P_0c034e9e;
case 0x0c034ea0u: goto P_0c034ea0;
case 0x0c034ea2u: goto P_0c034ea2;
case 0x0c034ea4u: goto P_0c034ea4;
case 0x0c034ea6u: goto P_0c034ea6;
case 0x0c034ea8u: goto P_0c034ea8;
case 0x0c034eaau: goto P_0c034eaa;
case 0x0c034eacu: goto P_0c034eac;
case 0x0c034eaeu: goto P_0c034eae;
case 0x0c034eb0u: goto P_0c034eb0;
case 0x0c034eb2u: goto P_0c034eb2;
case 0x0c034eb4u: goto P_0c034eb4;
case 0x0c034eb6u: goto P_0c034eb6;
case 0x0c034eb8u: goto P_0c034eb8;
case 0x0c034ebau: goto P_0c034eba;
case 0x0c034ebcu: goto P_0c034ebc;
case 0x0c034ebeu: goto P_0c034ebe;
case 0x0c034ec0u: goto P_0c034ec0;
case 0x0c034ec2u: goto P_0c034ec2;
case 0x0c034ec4u: goto P_0c034ec4;
case 0x0c034ec6u: goto P_0c034ec6;
case 0x0c034ec8u: goto P_0c034ec8;
case 0x0c034ecau: goto P_0c034eca;
case 0x0c034eccu: goto P_0c034ecc;
case 0x0c034eceu: goto P_0c034ece;
case 0x0c034ed0u: goto P_0c034ed0;
case 0x0c034ed2u: goto P_0c034ed2;
case 0x0c034ed4u: goto P_0c034ed4;
case 0x0c034ed6u: goto P_0c034ed6;
case 0x0c034ed8u: goto P_0c034ed8;
case 0x0c034edau: goto P_0c034eda;
case 0x0c034edcu: goto P_0c034edc;
case 0x0c034edeu: goto P_0c034ede;
case 0x0c034ee0u: goto P_0c034ee0;
case 0x0c034ee2u: goto P_0c034ee2;
case 0x0c034ee4u: goto P_0c034ee4;
case 0x0c034ee6u: goto P_0c034ee6;
case 0x0c034ee8u: goto P_0c034ee8;
case 0x0c034eeau: goto P_0c034eea;
case 0x0c034eecu: goto P_0c034eec;
case 0x0c034eeeu: goto P_0c034eee;
case 0x0c034ef0u: goto P_0c034ef0;
case 0x0c034ef2u: goto P_0c034ef2;
case 0x0c034ef4u: goto P_0c034ef4;
case 0x0c034ef6u: goto P_0c034ef6;
case 0x0c034ef8u: goto P_0c034ef8;
case 0x0c034efau: goto P_0c034efa;
case 0x0c034efcu: goto P_0c034efc;
case 0x0c034efeu: goto P_0c034efe;
case 0x0c034f00u: goto P_0c034f00;
case 0x0c034f02u: goto P_0c034f02;
case 0x0c034f04u: goto P_0c034f04;
case 0x0c034f06u: goto P_0c034f06;
case 0x0c034f08u: goto P_0c034f08;
case 0x0c034f0au: goto P_0c034f0a;
case 0x0c034f0cu: goto P_0c034f0c;
case 0x0c034f0eu: goto P_0c034f0e;
case 0x0c034f10u: goto P_0c034f10;
case 0x0c034f12u: goto P_0c034f12;
case 0x0c034f14u: goto P_0c034f14;
case 0x0c034f16u: goto P_0c034f16;
case 0x0c034f18u: goto P_0c034f18;
case 0x0c034f1au: goto P_0c034f1a;
case 0x0c034f1cu: goto P_0c034f1c;
case 0x0c034f1eu: goto P_0c034f1e;
case 0x0c034f20u: goto P_0c034f20;
case 0x0c034f22u: goto P_0c034f22;
case 0x0c034f24u: goto P_0c034f24;
case 0x0c0367acu: goto P_0c0367ac;
case 0x0c0367aeu: goto P_0c0367ae;
case 0x0c0367b0u: goto P_0c0367b0;
case 0x0c0367b2u: goto P_0c0367b2;
case 0x0c0367b4u: goto P_0c0367b4;
case 0x0c0367b6u: goto P_0c0367b6;
case 0x0c0367b8u: goto P_0c0367b8;
case 0x0c0367bau: goto P_0c0367ba;
case 0x0c0367bcu: goto P_0c0367bc;
case 0x0c0367beu: goto P_0c0367be;
case 0x0c0367c0u: goto P_0c0367c0;
case 0x0c0367c2u: goto P_0c0367c2;
case 0x0c0367c4u: goto P_0c0367c4;
case 0x0c0367c6u: goto P_0c0367c6;
case 0x0c0367c8u: goto P_0c0367c8;
case 0x0c0367cau: goto P_0c0367ca;
case 0x0c0367ccu: goto P_0c0367cc;
case 0x0c0367ceu: goto P_0c0367ce;
case 0x0c0367d0u: goto P_0c0367d0;
case 0x0c0367d2u: goto P_0c0367d2;
case 0x0c0367d4u: goto P_0c0367d4;
case 0x0c0367d6u: goto P_0c0367d6;
case 0x0c0367d8u: goto P_0c0367d8;
case 0x0c0367dau: goto P_0c0367da;
case 0x0c0367dcu: goto P_0c0367dc;
case 0x0c0367deu: goto P_0c0367de;
case 0x0c0367e0u: goto P_0c0367e0;
case 0x0c0367e2u: goto P_0c0367e2;
case 0x0c0367e4u: goto P_0c0367e4;
case 0x0c0367e6u: goto P_0c0367e6;
case 0x0c0367e8u: goto P_0c0367e8;
case 0x0c0367eau: goto P_0c0367ea;
case 0x0c0367ecu: goto P_0c0367ec;
case 0x0c0367eeu: goto P_0c0367ee;
case 0x0c0367f0u: goto P_0c0367f0;
case 0x0c0367f2u: goto P_0c0367f2;
case 0x0c0367f4u: goto P_0c0367f4;
case 0x0c0367f6u: goto P_0c0367f6;
case 0x0c0367f8u: goto P_0c0367f8;
case 0x0c0367fau: goto P_0c0367fa;
case 0x0c0367fcu: goto P_0c0367fc;
case 0x0c0367feu: goto P_0c0367fe;
case 0x0c036800u: goto P_0c036800;
case 0x0c036802u: goto P_0c036802;
case 0x0c036804u: goto P_0c036804;
case 0x0c036806u: goto P_0c036806;
case 0x0c036808u: goto P_0c036808;
case 0x0c03680au: goto P_0c03680a;
case 0x0c03680cu: goto P_0c03680c;
case 0x0c03680eu: goto P_0c03680e;
case 0x0c036810u: goto P_0c036810;
case 0x0c036812u: goto P_0c036812;
case 0x0c036814u: goto P_0c036814;
case 0x0c036816u: goto P_0c036816;
case 0x0c036818u: goto P_0c036818;
case 0x0c03681au: goto P_0c03681a;
case 0x0c03681cu: goto P_0c03681c;
case 0x0c03681eu: goto P_0c03681e;
case 0x0c036820u: goto P_0c036820;
case 0x0c036822u: goto P_0c036822;
case 0x0c036824u: goto P_0c036824;
case 0x0c036826u: goto P_0c036826;
case 0x0c036828u: goto P_0c036828;
case 0x0c03682au: goto P_0c03682a;
case 0x0c03682cu: goto P_0c03682c;
case 0x0c03682eu: goto P_0c03682e;
case 0x0c036830u: goto P_0c036830;
case 0x0c036832u: goto P_0c036832;
case 0x0c036834u: goto P_0c036834;
case 0x0c036836u: goto P_0c036836;
case 0x0c036838u: goto P_0c036838;
case 0x0c03683au: goto P_0c03683a;
case 0x0c03683cu: goto P_0c03683c;
case 0x0c03683eu: goto P_0c03683e;
case 0x0c036840u: goto P_0c036840;
case 0x0c036842u: goto P_0c036842;
case 0x0c036844u: goto P_0c036844;
case 0x0c036846u: goto P_0c036846;
case 0x0c036848u: goto P_0c036848;
case 0x0c03684au: goto P_0c03684a;
case 0x0c03684cu: goto P_0c03684c;
case 0x0c03684eu: goto P_0c03684e;
case 0x0c036850u: goto P_0c036850;
case 0x0c036852u: goto P_0c036852;
case 0x0c036854u: goto P_0c036854;
case 0x0c036856u: goto P_0c036856;
case 0x0c036858u: goto P_0c036858;
case 0x0c03685au: goto P_0c03685a;
case 0x0c03685cu: goto P_0c03685c;
case 0x0c03685eu: goto P_0c03685e;
case 0x0c036860u: goto P_0c036860;
case 0x0c036862u: goto P_0c036862;
case 0x0c036864u: goto P_0c036864;
case 0x0c036866u: goto P_0c036866;
case 0x0c036868u: goto P_0c036868;
case 0x0c03686au: goto P_0c03686a;
case 0x0c03686cu: goto P_0c03686c;
case 0x0c03686eu: goto P_0c03686e;
case 0x0c036870u: goto P_0c036870;
case 0x0c036872u: goto P_0c036872;
case 0x0c036874u: goto P_0c036874;
case 0x0c036876u: goto P_0c036876;
case 0x0c036878u: goto P_0c036878;
case 0x0c03687au: goto P_0c03687a;
case 0x0c03687cu: goto P_0c03687c;
case 0x0c03687eu: goto P_0c03687e;
case 0x0c036880u: goto P_0c036880;
case 0x0c036882u: goto P_0c036882;
case 0x0c036884u: goto P_0c036884;
case 0x0c036886u: goto P_0c036886;
case 0x0c036888u: goto P_0c036888;
case 0x0c03688au: goto P_0c03688a;
case 0x0c03688cu: goto P_0c03688c;
case 0x0c03688eu: goto P_0c03688e;
case 0x0c036890u: goto P_0c036890;
case 0x0c036892u: goto P_0c036892;
case 0x0c036894u: goto P_0c036894;
case 0x0c036896u: goto P_0c036896;
case 0x0c036898u: goto P_0c036898;
case 0x0c03689au: goto P_0c03689a;
case 0x0c03689cu: goto P_0c03689c;
case 0x0c03689eu: goto P_0c03689e;
case 0x0c0368a0u: goto P_0c0368a0;
case 0x0c0368a2u: goto P_0c0368a2;
case 0x0c0368a4u: goto P_0c0368a4;
case 0x0c0368a6u: goto P_0c0368a6;
case 0x0c0368a8u: goto P_0c0368a8;
case 0x0c0381f0u: goto P_0c0381f0;
case 0x0c0381f2u: goto P_0c0381f2;
case 0x0c0381f4u: goto P_0c0381f4;
case 0x0c0381f6u: goto P_0c0381f6;
case 0x0c0381f8u: goto P_0c0381f8;
case 0x0c0381fau: goto P_0c0381fa;
case 0x0c0381fcu: goto P_0c0381fc;
case 0x0c0381feu: goto P_0c0381fe;
case 0x0c038200u: goto P_0c038200;
case 0x0c038202u: goto P_0c038202;
case 0x0c038204u: goto P_0c038204;
case 0x0c038206u: goto P_0c038206;
case 0x0c038208u: goto P_0c038208;
case 0x0c03820au: goto P_0c03820a;
case 0x0c03820cu: goto P_0c03820c;
case 0x0c03820eu: goto P_0c03820e;
case 0x0c038210u: goto P_0c038210;
case 0x0c038212u: goto P_0c038212;
case 0x0c038214u: goto P_0c038214;
case 0x0c038216u: goto P_0c038216;
case 0x0c038218u: goto P_0c038218;
case 0x0c03821au: goto P_0c03821a;
case 0x0c03821cu: goto P_0c03821c;
case 0x0c03821eu: goto P_0c03821e;
case 0x0c038220u: goto P_0c038220;
case 0x0c038222u: goto P_0c038222;
case 0x0c038224u: goto P_0c038224;
case 0x0c038226u: goto P_0c038226;
case 0x0c038228u: goto P_0c038228;
case 0x0c03822au: goto P_0c03822a;
case 0x0c03822cu: goto P_0c03822c;
case 0x0c03822eu: goto P_0c03822e;
case 0x0c038230u: goto P_0c038230;
case 0x0c038232u: goto P_0c038232;
case 0x0c038234u: goto P_0c038234;
case 0x0c038236u: goto P_0c038236;
case 0x0c038238u: goto P_0c038238;
case 0x0c03823au: goto P_0c03823a;
case 0x0c03823cu: goto P_0c03823c;
case 0x0c03823eu: goto P_0c03823e;
case 0x0c038240u: goto P_0c038240;
case 0x0c038242u: goto P_0c038242;
case 0x0c038244u: goto P_0c038244;
case 0x0c038246u: goto P_0c038246;
case 0x0c038248u: goto P_0c038248;
case 0x0c03824au: goto P_0c03824a;
case 0x0c03824cu: goto P_0c03824c;
case 0x0c03824eu: goto P_0c03824e;
case 0x0c038250u: goto P_0c038250;
case 0x0c038252u: goto P_0c038252;
case 0x0c038254u: goto P_0c038254;
case 0x0c038256u: goto P_0c038256;
case 0x0c038258u: goto P_0c038258;
case 0x0c03825au: goto P_0c03825a;
case 0x0c03825cu: goto P_0c03825c;
case 0x0c03825eu: goto P_0c03825e;
case 0x0c038260u: goto P_0c038260;
case 0x0c038262u: goto P_0c038262;
case 0x0c038264u: goto P_0c038264;
case 0x0c038266u: goto P_0c038266;
case 0x0c038268u: goto P_0c038268;
case 0x0c03826au: goto P_0c03826a;
case 0x0c03826cu: goto P_0c03826c;
case 0x0c03826eu: goto P_0c03826e;
case 0x0c038270u: goto P_0c038270;
case 0x0c038272u: goto P_0c038272;
case 0x0c038274u: goto P_0c038274;
case 0x0c038276u: goto P_0c038276;
case 0x0c038278u: goto P_0c038278;
case 0x0c03827au: goto P_0c03827a;
case 0x0c03827cu: goto P_0c03827c;
case 0x0c03827eu: goto P_0c03827e;
case 0x0c038280u: goto P_0c038280;
case 0x0c038282u: goto P_0c038282;
case 0x0c038284u: goto P_0c038284;
case 0x0c038286u: goto P_0c038286;
case 0x0c038288u: goto P_0c038288;
case 0x0c03828au: goto P_0c03828a;
case 0x0c03828cu: goto P_0c03828c;
case 0x0c03828eu: goto P_0c03828e;
case 0x0c038290u: goto P_0c038290;
case 0x0c038292u: goto P_0c038292;
case 0x0c038294u: goto P_0c038294;
case 0x0c038296u: goto P_0c038296;
case 0x0c038298u: goto P_0c038298;
case 0x0c03829au: goto P_0c03829a;
case 0x0c03829cu: goto P_0c03829c;
case 0x0c03829eu: goto P_0c03829e;
case 0x0c0382a0u: goto P_0c0382a0;
case 0x0c0382a2u: goto P_0c0382a2;
case 0x0c0382a4u: goto P_0c0382a4;
case 0x0c0382a6u: goto P_0c0382a6;
case 0x0c0382a8u: goto P_0c0382a8;
case 0x0c0382aau: goto P_0c0382aa;
case 0x0c0382acu: goto P_0c0382ac;
case 0x0c0382aeu: goto P_0c0382ae;
case 0x0c0382b0u: goto P_0c0382b0;
case 0x0c0382b2u: goto P_0c0382b2;
case 0x0c0382b4u: goto P_0c0382b4;
case 0x0c0382b6u: goto P_0c0382b6;
case 0x0c0382b8u: goto P_0c0382b8;
case 0x0c0382bau: goto P_0c0382ba;
case 0x0c0382bcu: goto P_0c0382bc;
case 0x0c0382beu: goto P_0c0382be;
case 0x0c0382c0u: goto P_0c0382c0;
case 0x0c0382c2u: goto P_0c0382c2;
case 0x0c0382c4u: goto P_0c0382c4;
case 0x0c0382c6u: goto P_0c0382c6;
case 0x0c0382c8u: goto P_0c0382c8;
case 0x0c0382cau: goto P_0c0382ca;
case 0x0c0382ccu: goto P_0c0382cc;
case 0x0c0382ceu: goto P_0c0382ce;
case 0x0c0382d0u: goto P_0c0382d0;
case 0x0c0382d2u: goto P_0c0382d2;
case 0x0c0382d4u: goto P_0c0382d4;
case 0x0c0382d6u: goto P_0c0382d6;
case 0x0c0382d8u: goto P_0c0382d8;
case 0x0c0382dau: goto P_0c0382da;
case 0x0c0382dcu: goto P_0c0382dc;
case 0x0c0382deu: goto P_0c0382de;
case 0x0c0382e0u: goto P_0c0382e0;
case 0x0c0382e2u: goto P_0c0382e2;
case 0x0c0382e4u: goto P_0c0382e4;
case 0x0c0382e6u: goto P_0c0382e6;
case 0x0c0382e8u: goto P_0c0382e8;
case 0x0c0382eau: goto P_0c0382ea;
case 0x0c0382ecu: goto P_0c0382ec;
case 0x0c0382eeu: goto P_0c0382ee;
case 0x0c0382f0u: goto P_0c0382f0;
case 0x0c0382f2u: goto P_0c0382f2;
case 0x0c0382f4u: goto P_0c0382f4;
case 0x0c0382f6u: goto P_0c0382f6;
case 0x0c0382f8u: goto P_0c0382f8;
case 0x0c0382fau: goto P_0c0382fa;
case 0x0c0382fcu: goto P_0c0382fc;
case 0x0c0382feu: goto P_0c0382fe;
case 0x0c038300u: goto P_0c038300;
case 0x0c038302u: goto P_0c038302;
case 0x0c038304u: goto P_0c038304;
case 0x0c038306u: goto P_0c038306;
case 0x0c038308u: goto P_0c038308;
case 0x0c03830au: goto P_0c03830a;
case 0x0c03830cu: goto P_0c03830c;
case 0x0c03830eu: goto P_0c03830e;
case 0x0c038310u: goto P_0c038310;
case 0x0c038312u: goto P_0c038312;
case 0x0c038314u: goto P_0c038314;
case 0x0c038316u: goto P_0c038316;
case 0x0c038318u: goto P_0c038318;
case 0x0c03831au: goto P_0c03831a;
case 0x0c03831cu: goto P_0c03831c;
case 0x0c03831eu: goto P_0c03831e;
case 0x0c038320u: goto P_0c038320;
case 0x0c038322u: goto P_0c038322;
case 0x0c038324u: goto P_0c038324;
case 0x0c038326u: goto P_0c038326;
case 0x0c038328u: goto P_0c038328;
case 0x0c03832au: goto P_0c03832a;
case 0x0c03832cu: goto P_0c03832c;
case 0x0c03832eu: goto P_0c03832e;
case 0x0c038330u: goto P_0c038330;
case 0x0c038332u: goto P_0c038332;
case 0x0c038334u: goto P_0c038334;
case 0x0c038336u: goto P_0c038336;
case 0x0c038338u: goto P_0c038338;
case 0x0c04454cu: goto P_0c04454c;
case 0x0c04454eu: goto P_0c04454e;
case 0x0c044550u: goto P_0c044550;
case 0x0c044552u: goto P_0c044552;
case 0x0c044554u: goto P_0c044554;
case 0x0c044556u: goto P_0c044556;
case 0x0c044558u: goto P_0c044558;
case 0x0c04455au: goto P_0c04455a;
case 0x0c04455cu: goto P_0c04455c;
case 0x0c04455eu: goto P_0c04455e;
case 0x0c044560u: goto P_0c044560;
case 0x0c044562u: goto P_0c044562;
case 0x0c044564u: goto P_0c044564;
case 0x0c044566u: goto P_0c044566;
case 0x0c044568u: goto P_0c044568;
case 0x0c04456au: goto P_0c04456a;
case 0x0c04456cu: goto P_0c04456c;
case 0x0c04456eu: goto P_0c04456e;
case 0x0c044570u: goto P_0c044570;
case 0x0c044572u: goto P_0c044572;
case 0x0c044574u: goto P_0c044574;
case 0x0c044576u: goto P_0c044576;
case 0x0c044578u: goto P_0c044578;
case 0x0c04457au: goto P_0c04457a;
case 0x0c04457cu: goto P_0c04457c;
case 0x0c04457eu: goto P_0c04457e;
case 0x0c044580u: goto P_0c044580;
case 0x0c059848u: goto P_0c059848;
case 0x0c05984au: goto P_0c05984a;
case 0x0c05984cu: goto P_0c05984c;
case 0x0c05984eu: goto P_0c05984e;
case 0x0c059850u: goto P_0c059850;
case 0x0c059852u: goto P_0c059852;
case 0x0c059854u: goto P_0c059854;
case 0x0c059856u: goto P_0c059856;
case 0x0c059858u: goto P_0c059858;
case 0x0c05985au: goto P_0c05985a;
case 0x0c05985cu: goto P_0c05985c;
case 0x0c05985eu: goto P_0c05985e;
case 0x0c059860u: goto P_0c059860;
case 0x0c059862u: goto P_0c059862;
case 0x0c059864u: goto P_0c059864;
case 0x0c059866u: goto P_0c059866;
case 0x0c059868u: goto P_0c059868;
case 0x0c05986au: goto P_0c05986a;
case 0x0c05986cu: goto P_0c05986c;
case 0x0c05986eu: goto P_0c05986e;
case 0x0c059870u: goto P_0c059870;
case 0x0c059872u: goto P_0c059872;
case 0x0c059874u: goto P_0c059874;
case 0x0c059876u: goto P_0c059876;
case 0x0c059878u: goto P_0c059878;
case 0x0c05987au: goto P_0c05987a;
case 0x0c05987cu: goto P_0c05987c;
case 0x0c05987eu: goto P_0c05987e;
case 0x0c059880u: goto P_0c059880;
case 0x0c059882u: goto P_0c059882;
case 0x0c059884u: goto P_0c059884;
case 0x0c059886u: goto P_0c059886;
case 0x0c059888u: goto P_0c059888;
case 0x0c05988au: goto P_0c05988a;
case 0x0c05988cu: goto P_0c05988c;
case 0x0c05988eu: goto P_0c05988e;
case 0x0c059890u: goto P_0c059890;
case 0x0c059892u: goto P_0c059892;
case 0x0c059894u: goto P_0c059894;
case 0x0c05c280u: goto P_0c05c280;
case 0x0c05c282u: goto P_0c05c282;
case 0x0c05c284u: goto P_0c05c284;
case 0x0c05c286u: goto P_0c05c286;
case 0x0c05c288u: goto P_0c05c288;
case 0x0c05c28au: goto P_0c05c28a;
case 0x0c05c28cu: goto P_0c05c28c;
case 0x0c05c28eu: goto P_0c05c28e;
case 0x0c05c290u: goto P_0c05c290;
case 0x0c05c292u: goto P_0c05c292;
case 0x0c05c294u: goto P_0c05c294;
case 0x0c05c296u: goto P_0c05c296;
case 0x0c05c298u: goto P_0c05c298;
case 0x0c05c29au: goto P_0c05c29a;
case 0x0c05c29cu: goto P_0c05c29c;
case 0x0c05c29eu: goto P_0c05c29e;
case 0x0c05c2a0u: goto P_0c05c2a0;
case 0x0c05c2a2u: goto P_0c05c2a2;
case 0x0c05c2a4u: goto P_0c05c2a4;
case 0x0c05c2a6u: goto P_0c05c2a6;
case 0x0c05c2a8u: goto P_0c05c2a8;
case 0x0c05c2aau: goto P_0c05c2aa;
case 0x0c05c2acu: goto P_0c05c2ac;
case 0x0c05c2aeu: goto P_0c05c2ae;
case 0x0c05c2b0u: goto P_0c05c2b0;
case 0x0c05c2b2u: goto P_0c05c2b2;
case 0x0c05c2b4u: goto P_0c05c2b4;
case 0x0c05c2b6u: goto P_0c05c2b6;
case 0x0c05c2b8u: goto P_0c05c2b8;
case 0x0c05c2bau: goto P_0c05c2ba;
case 0x0c05c2bcu: goto P_0c05c2bc;
case 0x0c05c2beu: goto P_0c05c2be;
case 0x0c05c2c0u: goto P_0c05c2c0;
case 0x0c05c2c2u: goto P_0c05c2c2;
case 0x0c05c2c4u: goto P_0c05c2c4;
case 0x0c05c2c6u: goto P_0c05c2c6;
case 0x0c05c2c8u: goto P_0c05c2c8;
case 0x0c05c2cau: goto P_0c05c2ca;
case 0x0c05c2ccu: goto P_0c05c2cc;
case 0x0c05c2ceu: goto P_0c05c2ce;
case 0x0c05c2d0u: goto P_0c05c2d0;
case 0x0c05c2d2u: goto P_0c05c2d2;
case 0x0c05c2d4u: goto P_0c05c2d4;
case 0x0c05c2d6u: goto P_0c05c2d6;
case 0x0c05c2d8u: goto P_0c05c2d8;
case 0x0c05c2dau: goto P_0c05c2da;
case 0x0c05c2dcu: goto P_0c05c2dc;
case 0x0c05c2deu: goto P_0c05c2de;
case 0x0c05c2e0u: goto P_0c05c2e0;
case 0x0c05c2e2u: goto P_0c05c2e2;
case 0x0c05c2e4u: goto P_0c05c2e4;
case 0x0c05c2e6u: goto P_0c05c2e6;
case 0x0c05c2e8u: goto P_0c05c2e8;
case 0x0c05c2eau: goto P_0c05c2ea;
case 0x0c05c2ecu: goto P_0c05c2ec;
case 0x0c05c2eeu: goto P_0c05c2ee;
case 0x0c05c2f0u: goto P_0c05c2f0;
case 0x0c05c2f2u: goto P_0c05c2f2;
case 0x0c05c2f4u: goto P_0c05c2f4;
case 0x0c05c2f6u: goto P_0c05c2f6;
case 0x0c05c2f8u: goto P_0c05c2f8;
case 0x0c05c2fau: goto P_0c05c2fa;
case 0x0c05c2fcu: goto P_0c05c2fc;
case 0x0c05c2feu: goto P_0c05c2fe;
case 0x0c05c300u: goto P_0c05c300;
case 0x0c05c302u: goto P_0c05c302;
case 0x0c05c304u: goto P_0c05c304;
case 0x0c05c306u: goto P_0c05c306;
case 0x0c05c308u: goto P_0c05c308;
case 0x0c05c30au: goto P_0c05c30a;
case 0x0c05c30cu: goto P_0c05c30c;
case 0x0c05c30eu: goto P_0c05c30e;
case 0x0c05c310u: goto P_0c05c310;
case 0x0c05c312u: goto P_0c05c312;
case 0x0c05c314u: goto P_0c05c314;
case 0x0c05c316u: goto P_0c05c316;
case 0x0c05c318u: goto P_0c05c318;
case 0x0c05c31au: goto P_0c05c31a;
case 0x0c05c31cu: goto P_0c05c31c;
case 0x0c05c31eu: goto P_0c05c31e;
case 0x0c05c320u: goto P_0c05c320;
case 0x0c05c322u: goto P_0c05c322;
case 0x0c05c324u: goto P_0c05c324;
case 0x0c05c326u: goto P_0c05c326;
case 0x0c05c328u: goto P_0c05c328;
case 0x0c05c32au: goto P_0c05c32a;
case 0x0c05c32cu: goto P_0c05c32c;
case 0x0c05c32eu: goto P_0c05c32e;
case 0x0c05c330u: goto P_0c05c330;
case 0x0c05c332u: goto P_0c05c332;
case 0x0c05c334u: goto P_0c05c334;
case 0x0c05c336u: goto P_0c05c336;
case 0x0c05c338u: goto P_0c05c338;
case 0x0c05c33au: goto P_0c05c33a;
case 0x0c05c33cu: goto P_0c05c33c;
case 0x0c05c33eu: goto P_0c05c33e;
case 0x0c05c340u: goto P_0c05c340;
case 0x0c05c342u: goto P_0c05c342;
case 0x0c05c344u: goto P_0c05c344;
case 0x0c05c346u: goto P_0c05c346;
case 0x0c05c348u: goto P_0c05c348;
case 0x0c05c34au: goto P_0c05c34a;
case 0x0c05c34cu: goto P_0c05c34c;
case 0x0c05c368u: goto P_0c05c368;
case 0x0c05c36au: goto P_0c05c36a;
case 0x0c05c36cu: goto P_0c05c36c;
case 0x0c05c36eu: goto P_0c05c36e;
case 0x0c05c370u: goto P_0c05c370;
case 0x0c05c372u: goto P_0c05c372;
case 0x0c05c374u: goto P_0c05c374;
case 0x0c05c376u: goto P_0c05c376;
case 0x0c05c378u: goto P_0c05c378;
case 0x0c05c37au: goto P_0c05c37a;
case 0x0c05c37cu: goto P_0c05c37c;
case 0x0c05c37eu: goto P_0c05c37e;
case 0x0c05c380u: goto P_0c05c380;
case 0x0c05c382u: goto P_0c05c382;
case 0x0c05c384u: goto P_0c05c384;
case 0x0c05c386u: goto P_0c05c386;
case 0x0c05c388u: goto P_0c05c388;
case 0x0c05c38au: goto P_0c05c38a;
case 0x0c05c38cu: goto P_0c05c38c;
case 0x0c05c38eu: goto P_0c05c38e;
case 0x0c05c390u: goto P_0c05c390;
case 0x0c05c392u: goto P_0c05c392;
case 0x0c05c394u: goto P_0c05c394;
case 0x0c05c396u: goto P_0c05c396;
case 0x0c05c398u: goto P_0c05c398;
case 0x0c05c39au: goto P_0c05c39a;
case 0x0c05c39cu: goto P_0c05c39c;
case 0x0c05c39eu: goto P_0c05c39e;
case 0x0c05c3a0u: goto P_0c05c3a0;
case 0x0c05c3a2u: goto P_0c05c3a2;
case 0x0c05c3a4u: goto P_0c05c3a4;
case 0x0c05c3a6u: goto P_0c05c3a6;
case 0x0c05c3a8u: goto P_0c05c3a8;
case 0x0c05c3aau: goto P_0c05c3aa;
case 0x0c05c3acu: goto P_0c05c3ac;
case 0x0c05c3aeu: goto P_0c05c3ae;
case 0x0c05c3b0u: goto P_0c05c3b0;
case 0x0c05c3b2u: goto P_0c05c3b2;
case 0x0c05c3b4u: goto P_0c05c3b4;
case 0x0c05c3b6u: goto P_0c05c3b6;
case 0x0c05c3b8u: goto P_0c05c3b8;
case 0x0c05c3bau: goto P_0c05c3ba;
case 0x0c05c3bcu: goto P_0c05c3bc;
case 0x0c05c3beu: goto P_0c05c3be;
case 0x0c05c3c0u: goto P_0c05c3c0;
case 0x0c05c3c2u: goto P_0c05c3c2;
case 0x0c05c3c4u: goto P_0c05c3c4;
case 0x0c05c3c6u: goto P_0c05c3c6;
case 0x0c05c3c8u: goto P_0c05c3c8;
case 0x0c05c3cau: goto P_0c05c3ca;
case 0x0c05c3ccu: goto P_0c05c3cc;
case 0x0c05c3ceu: goto P_0c05c3ce;
case 0x0c05c3d0u: goto P_0c05c3d0;
case 0x0c05c3d2u: goto P_0c05c3d2;
case 0x0c05c3d4u: goto P_0c05c3d4;
case 0x0c05c3d6u: goto P_0c05c3d6;
case 0x0c05c3d8u: goto P_0c05c3d8;
case 0x0c05c3dau: goto P_0c05c3da;
case 0x0c05c3dcu: goto P_0c05c3dc;
case 0x0c05c3deu: goto P_0c05c3de;
case 0x0c05c3e0u: goto P_0c05c3e0;
case 0x0c05c3e2u: goto P_0c05c3e2;
case 0x0c05c3e4u: goto P_0c05c3e4;
case 0x0c05c3e6u: goto P_0c05c3e6;
case 0x0c05c3e8u: goto P_0c05c3e8;
case 0x0c05c3eau: goto P_0c05c3ea;
case 0x0c05c3ecu: goto P_0c05c3ec;
case 0x0c05c3eeu: goto P_0c05c3ee;
case 0x0c05c3f0u: goto P_0c05c3f0;
case 0x0c05c3f2u: goto P_0c05c3f2;
case 0x0c05c3f4u: goto P_0c05c3f4;
case 0x0c05c3f6u: goto P_0c05c3f6;
case 0x0c05c3f8u: goto P_0c05c3f8;
case 0x0c05c3fau: goto P_0c05c3fa;
case 0x0c05c3fcu: goto P_0c05c3fc;
case 0x0c05c3feu: goto P_0c05c3fe;
case 0x0c05c400u: goto P_0c05c400;
case 0x0c05c402u: goto P_0c05c402;
case 0x0c05c404u: goto P_0c05c404;
case 0x0c05c406u: goto P_0c05c406;
case 0x0c05c408u: goto P_0c05c408;
case 0x0c05c40au: goto P_0c05c40a;
case 0x0c05c40cu: goto P_0c05c40c;
case 0x0c05c40eu: goto P_0c05c40e;
case 0x0c05c410u: goto P_0c05c410;
case 0x0c05c412u: goto P_0c05c412;
case 0x0c05c414u: goto P_0c05c414;
case 0x0c05c416u: goto P_0c05c416;
case 0x0c05c418u: goto P_0c05c418;
case 0x0c05c41au: goto P_0c05c41a;
case 0x0c05c41cu: goto P_0c05c41c;
case 0x0c05c41eu: goto P_0c05c41e;
case 0x0c05c420u: goto P_0c05c420;
case 0x0c05c422u: goto P_0c05c422;
case 0x0c05c424u: goto P_0c05c424;
case 0x0c05c426u: goto P_0c05c426;
case 0x0c05c428u: goto P_0c05c428;
case 0x0c05c42au: goto P_0c05c42a;
case 0x0c05c42cu: goto P_0c05c42c;
case 0x0c05c42eu: goto P_0c05c42e;
case 0x0c05c430u: goto P_0c05c430;
case 0x0c05c432u: goto P_0c05c432;
case 0x0c05c434u: goto P_0c05c434;
case 0x0c05c436u: goto P_0c05c436;
case 0x0c05c438u: goto P_0c05c438;
case 0x0c05c43au: goto P_0c05c43a;
case 0x0c05c43cu: goto P_0c05c43c;
case 0x0c05c43eu: goto P_0c05c43e;
case 0x0c05c440u: goto P_0c05c440;
case 0x0c05c442u: goto P_0c05c442;
case 0x0c05c444u: goto P_0c05c444;
case 0x0c05c446u: goto P_0c05c446;
case 0x0c05c448u: goto P_0c05c448;
case 0x0c05c44au: goto P_0c05c44a;
case 0x0c05c44cu: goto P_0c05c44c;
case 0x0c05c44eu: goto P_0c05c44e;
case 0x0c05c450u: goto P_0c05c450;
case 0x0c05c452u: goto P_0c05c452;
case 0x0c05c454u: goto P_0c05c454;
case 0x0c05c456u: goto P_0c05c456;
case 0x0c05c458u: goto P_0c05c458;
case 0x0c05c45au: goto P_0c05c45a;
case 0x0c05c45cu: goto P_0c05c45c;
case 0x0c05f36eu: goto P_0c05f36e;
case 0x0c05f370u: goto P_0c05f370;
case 0x0c05f372u: goto P_0c05f372;
case 0x0c05f374u: goto P_0c05f374;
case 0x0c05f376u: goto P_0c05f376;
case 0x0c05f378u: goto P_0c05f378;
case 0x0c05f37au: goto P_0c05f37a;
case 0x0c05f37cu: goto P_0c05f37c;
case 0x0c05f37eu: goto P_0c05f37e;
case 0x0c05f380u: goto P_0c05f380;
case 0x0c05f382u: goto P_0c05f382;
case 0x0c05f384u: goto P_0c05f384;
case 0x0c05f386u: goto P_0c05f386;
case 0x0c05f388u: goto P_0c05f388;
case 0x0c05f38au: goto P_0c05f38a;
case 0x0c05f38cu: goto P_0c05f38c;
case 0x0c05f38eu: goto P_0c05f38e;
case 0x0c05f390u: goto P_0c05f390;
case 0x0c05f392u: goto P_0c05f392;
case 0x0c05f3b0u: goto P_0c05f3b0;
case 0x0c05f3b2u: goto P_0c05f3b2;
case 0x0c05f3b4u: goto P_0c05f3b4;
case 0x0c05f3b6u: goto P_0c05f3b6;
case 0x0c05f3b8u: goto P_0c05f3b8;
case 0x0c05f3bau: goto P_0c05f3ba;
case 0x0c05f3bcu: goto P_0c05f3bc;
case 0x0c05f3beu: goto P_0c05f3be;
case 0x0c05f3c0u: goto P_0c05f3c0;
case 0x0c05f3c2u: goto P_0c05f3c2;
case 0x0c05f3c4u: goto P_0c05f3c4;
case 0x0c05f3c6u: goto P_0c05f3c6;
case 0x0c05f3c8u: goto P_0c05f3c8;
case 0x0c05f3cau: goto P_0c05f3ca;
case 0x0c05f3ccu: goto P_0c05f3cc;
case 0x0c05f3ceu: goto P_0c05f3ce;
case 0x0c05f3d0u: goto P_0c05f3d0;
case 0x0c05f3d2u: goto P_0c05f3d2;
case 0x0c05f3d4u: goto P_0c05f3d4;
case 0x0c05f3d6u: goto P_0c05f3d6;
case 0x0c05f3d8u: goto P_0c05f3d8;
case 0x0c05f3dau: goto P_0c05f3da;
case 0x0c05f3dcu: goto P_0c05f3dc;
case 0x0c060d62u: goto P_0c060d62;
case 0x0c060d64u: goto P_0c060d64;
case 0x0c060d66u: goto P_0c060d66;
case 0x0c060d68u: goto P_0c060d68;
case 0x0c060d6au: goto P_0c060d6a;
case 0x0c060d6cu: goto P_0c060d6c;
case 0x0c060d6eu: goto P_0c060d6e;
case 0x0c060d70u: goto P_0c060d70;
case 0x0c060d72u: goto P_0c060d72;
case 0x0c060d74u: goto P_0c060d74;
case 0x0c060d76u: goto P_0c060d76;
case 0x0c060e50u: goto P_0c060e50;
case 0x0c060e52u: goto P_0c060e52;
case 0x0c060e54u: goto P_0c060e54;
case 0x0c060e56u: goto P_0c060e56;
case 0x0c060e58u: goto P_0c060e58;
case 0x0c060e5au: goto P_0c060e5a;
case 0x0c060e5cu: goto P_0c060e5c;
case 0x0c060e5eu: goto P_0c060e5e;
case 0x0c060e60u: goto P_0c060e60;
case 0x0c060e62u: goto P_0c060e62;
case 0x0c060e64u: goto P_0c060e64;
case 0x0c060e66u: goto P_0c060e66;
case 0x0c060e68u: goto P_0c060e68;
case 0x0c060e6au: goto P_0c060e6a;
case 0x0c060e6cu: goto P_0c060e6c;
case 0x0c060e6eu: goto P_0c060e6e;
case 0x0c060e70u: goto P_0c060e70;
case 0x0c060e72u: goto P_0c060e72;
case 0x0c07ae9cu: goto P_0c07ae9c;
case 0x0c07ae9eu: goto P_0c07ae9e;
case 0x0c07aea0u: goto P_0c07aea0;
case 0x0c07aea2u: goto P_0c07aea2;
case 0x0c07aea4u: goto P_0c07aea4;
case 0x0c07aea6u: goto P_0c07aea6;
case 0x0c07aea8u: goto P_0c07aea8;
case 0x0c07aeaau: goto P_0c07aeaa;
case 0x0c07aeacu: goto P_0c07aeac;
case 0x0c07aeaeu: goto P_0c07aeae;
case 0x0c07aeb0u: goto P_0c07aeb0;
case 0x0c07aeb2u: goto P_0c07aeb2;
case 0x0c07aeb4u: goto P_0c07aeb4;
case 0x0c07aeb6u: goto P_0c07aeb6;
case 0x0c07aeb8u: goto P_0c07aeb8;
case 0x0c07aebau: goto P_0c07aeba;
case 0x0c07aebcu: goto P_0c07aebc;
case 0x0c07aebeu: goto P_0c07aebe;
case 0x0c07aec0u: goto P_0c07aec0;
case 0x0c07aec2u: goto P_0c07aec2;
case 0x0c07aec4u: goto P_0c07aec4;
case 0x0c07aec6u: goto P_0c07aec6;
case 0x0c0a6642u: goto P_0c0a6642;
case 0x0c0a6644u: goto P_0c0a6644;
case 0x0c0a6646u: goto P_0c0a6646;
case 0x0c0a6648u: goto P_0c0a6648;
case 0x0c0a664au: goto P_0c0a664a;
case 0x0c0a664cu: goto P_0c0a664c;
case 0x0c0a664eu: goto P_0c0a664e;
case 0x0c0a6650u: goto P_0c0a6650;
case 0x0c0a6652u: goto P_0c0a6652;
case 0x0c0a6654u: goto P_0c0a6654;
case 0x0c0a6656u: goto P_0c0a6656;
case 0x0c0a6658u: goto P_0c0a6658;
case 0x0c0a665au: goto P_0c0a665a;
case 0x0c0a665cu: goto P_0c0a665c;
case 0x0c0a665eu: goto P_0c0a665e;
case 0x0c0a6660u: goto P_0c0a6660;
case 0x0c0a6662u: goto P_0c0a6662;
case 0x0c0a6664u: goto P_0c0a6664;
case 0x0c0a6666u: goto P_0c0a6666;
case 0x0c0a6668u: goto P_0c0a6668;
case 0x0c0a666au: goto P_0c0a666a;
case 0x0c0a666cu: goto P_0c0a666c;
case 0x0c0a666eu: goto P_0c0a666e;
case 0x0c0a6670u: goto P_0c0a6670;
case 0x0c0a6672u: goto P_0c0a6672;
case 0x0c0a6674u: goto P_0c0a6674;
case 0x0c0a6676u: goto P_0c0a6676;
case 0x0c0a6678u: goto P_0c0a6678;
case 0x0c0a667au: goto P_0c0a667a;
case 0x0c0a667cu: goto P_0c0a667c;
case 0x0c0a667eu: goto P_0c0a667e;
case 0x0c0a6680u: goto P_0c0a6680;
case 0x0c0a6682u: goto P_0c0a6682;
case 0x0c0a6684u: goto P_0c0a6684;
case 0x0c0a6686u: goto P_0c0a6686;
case 0x0c0a6688u: goto P_0c0a6688;
case 0x0c0a668au: goto P_0c0a668a;
case 0x0c0a668cu: goto P_0c0a668c;
case 0x0c0a668eu: goto P_0c0a668e;
case 0x0c0a6690u: goto P_0c0a6690;
case 0x0c0a6692u: goto P_0c0a6692;
case 0x0c0a6694u: goto P_0c0a6694;
case 0x0c0a6696u: goto P_0c0a6696;
case 0x0c0a6698u: goto P_0c0a6698;
case 0x0c0a669au: goto P_0c0a669a;
case 0x0c0a669cu: goto P_0c0a669c;
case 0x0c0a669eu: goto P_0c0a669e;
case 0x0c0a66a0u: goto P_0c0a66a0;
case 0x0c0a66a2u: goto P_0c0a66a2;
case 0x0c0a66a4u: goto P_0c0a66a4;
case 0x0c0a66a6u: goto P_0c0a66a6;
case 0x0c0a66a8u: goto P_0c0a66a8;
case 0x0c0a66aau: goto P_0c0a66aa;
case 0x0c0a66acu: goto P_0c0a66ac;
case 0x0c0a66aeu: goto P_0c0a66ae;
case 0x0c0a66b0u: goto P_0c0a66b0;
case 0x0c0a66b2u: goto P_0c0a66b2;
case 0x0c0a66b4u: goto P_0c0a66b4;
case 0x0c0a66b6u: goto P_0c0a66b6;
case 0x0c0a66b8u: goto P_0c0a66b8;
case 0x0c0a66bau: goto P_0c0a66ba;
case 0x0c0a66bcu: goto P_0c0a66bc;
case 0x0c0a66beu: goto P_0c0a66be;
case 0x0c0a66c0u: goto P_0c0a66c0;
case 0x0c0a66c2u: goto P_0c0a66c2;
case 0x0c0a66c4u: goto P_0c0a66c4;
case 0x0c0a66c6u: goto P_0c0a66c6;
case 0x0c0a66c8u: goto P_0c0a66c8;
case 0x0c0a66cau: goto P_0c0a66ca;
case 0x0c0a66ccu: goto P_0c0a66cc;
case 0x0c0a66ceu: goto P_0c0a66ce;
case 0x0c0a66d0u: goto P_0c0a66d0;
case 0x0c0a66d2u: goto P_0c0a66d2;
case 0x0c0a66d4u: goto P_0c0a66d4;
case 0x0c0a66d6u: goto P_0c0a66d6;
case 0x0c0a66d8u: goto P_0c0a66d8;
case 0x0c0a66dau: goto P_0c0a66da;
case 0x0c0a66dcu: goto P_0c0a66dc;
case 0x0c0a66deu: goto P_0c0a66de;
case 0x0c0a66e0u: goto P_0c0a66e0;
case 0x0c0a66e2u: goto P_0c0a66e2;
case 0x0c0a66e4u: goto P_0c0a66e4;
case 0x0c0a66e6u: goto P_0c0a66e6;
case 0x0c0a66e8u: goto P_0c0a66e8;
case 0x0c0a66eau: goto P_0c0a66ea;
case 0x0c0a66ecu: goto P_0c0a66ec;
case 0x0c0a66eeu: goto P_0c0a66ee;
case 0x0c0a66f0u: goto P_0c0a66f0;
case 0x0c0a66f2u: goto P_0c0a66f2;
case 0x0c0a66f4u: goto P_0c0a66f4;
case 0x0c0a66f6u: goto P_0c0a66f6;
case 0x0c0a66f8u: goto P_0c0a66f8;
case 0x0c0a66fau: goto P_0c0a66fa;
case 0x0c0a66fcu: goto P_0c0a66fc;
case 0x0c0a66feu: goto P_0c0a66fe;
case 0x0c0a6700u: goto P_0c0a6700;
case 0x0c0a6702u: goto P_0c0a6702;
case 0x0c0a6704u: goto P_0c0a6704;
case 0x0c0a6706u: goto P_0c0a6706;
case 0x0c0a6708u: goto P_0c0a6708;
case 0x0c0a670au: goto P_0c0a670a;
case 0x0c0a670cu: goto P_0c0a670c;
case 0x0c0a670eu: goto P_0c0a670e;
case 0x0c0a6710u: goto P_0c0a6710;
case 0x0c0a6712u: goto P_0c0a6712;
case 0x0c0a6714u: goto P_0c0a6714;
case 0x0c0a6716u: goto P_0c0a6716;
case 0x0c0a6718u: goto P_0c0a6718;
case 0x0c0a671au: goto P_0c0a671a;
case 0x0c0a671cu: goto P_0c0a671c;
case 0x0c0a671eu: goto P_0c0a671e;
case 0x0c0a6720u: goto P_0c0a6720;
case 0x0c0a6722u: goto P_0c0a6722;
case 0x0c0a6724u: goto P_0c0a6724;
case 0x0c0a6726u: goto P_0c0a6726;
case 0x0c0a6728u: goto P_0c0a6728;
case 0x0c0a672au: goto P_0c0a672a;
case 0x0c0a672cu: goto P_0c0a672c;
case 0x0c0a672eu: goto P_0c0a672e;
case 0x0c0a6730u: goto P_0c0a6730;
case 0x0c0a6732u: goto P_0c0a6732;
case 0x0c0a6734u: goto P_0c0a6734;
case 0x0c0a6736u: goto P_0c0a6736;
case 0x0c0a6738u: goto P_0c0a6738;
case 0x0c0a673au: goto P_0c0a673a;
case 0x0c0a673cu: goto P_0c0a673c;
case 0x0c0a673eu: goto P_0c0a673e;
case 0x0c0a6740u: goto P_0c0a6740;
case 0x0c0a6742u: goto P_0c0a6742;
case 0x0c0a6744u: goto P_0c0a6744;
case 0x0c0a6746u: goto P_0c0a6746;
case 0x0c0a6748u: goto P_0c0a6748;
case 0x0c0a674au: goto P_0c0a674a;
case 0x0c0a674cu: goto P_0c0a674c;
case 0x0c0a674eu: goto P_0c0a674e;
case 0x0c0a6750u: goto P_0c0a6750;
case 0x0c0a6752u: goto P_0c0a6752;
case 0x0c0a6754u: goto P_0c0a6754;
case 0x0c0a6756u: goto P_0c0a6756;
case 0x0c0a6758u: goto P_0c0a6758;
case 0x0c0a675au: goto P_0c0a675a;
case 0x0c0a675cu: goto P_0c0a675c;
case 0x0c0a675eu: goto P_0c0a675e;
case 0x0c0a6760u: goto P_0c0a6760;
case 0x0c0a6762u: goto P_0c0a6762;
case 0x0c0a6764u: goto P_0c0a6764;
case 0x0c0a6766u: goto P_0c0a6766;
case 0x0c0a6768u: goto P_0c0a6768;
case 0x0c0a676au: goto P_0c0a676a;
case 0x0c0a676cu: goto P_0c0a676c;
case 0x0c0a676eu: goto P_0c0a676e;
case 0x0c0a6770u: goto P_0c0a6770;
case 0x0c0a6772u: goto P_0c0a6772;
case 0x0c0a6774u: goto P_0c0a6774;
case 0x0c0a6776u: goto P_0c0a6776;
case 0x0c0a6778u: goto P_0c0a6778;
case 0x0c0a677au: goto P_0c0a677a;
case 0x0c0a677cu: goto P_0c0a677c;
case 0x0c0a677eu: goto P_0c0a677e;
case 0x0c0a6780u: goto P_0c0a6780;
case 0x0c0a6782u: goto P_0c0a6782;
case 0x0c0a6784u: goto P_0c0a6784;
case 0x0c0a6786u: goto P_0c0a6786;
case 0x0c0a6788u: goto P_0c0a6788;
default: return vf3_matrix_family(target,s,ram);
}
P_0c034cec: /* original 4f22, guest PC 0x0c034cec */
if(!s->budget--) { s->failed_pc=0x0c034cecu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c034cee;
P_0c034cee: /* original 6de2, guest PC 0x0c034cee */
if(!s->budget--) { s->failed_pc=0x0c034ceeu; return 0; }
tmp=read(ram,r[14],4);
r[13]=tmp;
goto P_0c034cf0;
P_0c034cf0: /* original 2dd8, guest PC 0x0c034cf0 */
if(!s->budget--) { s->failed_pc=0x0c034cf0u; return 0; }
r[17]=(r[17]&~1u)|(((r[13]&r[13])==0)!=0);
goto P_0c034cf2;
P_0c034cf2: /* original 7ff4, guest PC 0x0c034cf2 */
if(!s->budget--) { s->failed_pc=0x0c034cf2u; return 0; }
r[15]+=0xfffffff4u;
goto P_0c034cf4;
P_0c034cf4: /* original 8b0e, guest PC 0x0c034cf4 */
if(!s->budget--) { s->failed_pc=0x0c034cf4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c034d14; }
goto P_0c034cf6;
P_0c034cf6: /* original a10e, guest PC 0x0c034cf6 */
if(!s->budget--) { s->failed_pc=0x0c034cf6u; return 0; }
r[0]=0xffffffffu;
goto P_0c034f16;
P_0c034cf8: /* original e0ff, guest PC 0x0c034cf8 */
if(!s->budget--) { s->failed_pc=0x0c034cf8u; return 0; }
r[0]=0xffffffffu;
return vf3_matrix_family(0x0c034cfau,s,ram);
P_0c034d14: /* original 0002, guest PC 0x0c034d14 */
if(!s->budget--) { s->failed_pc=0x0c034d14u; return 0; }
r[0]=r[17];
goto P_0c034d16;
P_0c034d16: /* original 4009, guest PC 0x0c034d16 */
if(!s->budget--) { s->failed_pc=0x0c034d16u; return 0; }
r[0]>>=2;
goto P_0c034d18;
P_0c034d18: /* original 4009, guest PC 0x0c034d18 */
if(!s->budget--) { s->failed_pc=0x0c034d18u; return 0; }
r[0]>>=2;
goto P_0c034d1a;
P_0c034d1a: /* original c90f, guest PC 0x0c034d1a */
if(!s->budget--) { s->failed_pc=0x0c034d1au; return 0; }
r[0]&=15u;
goto P_0c034d1c;
P_0c034d1c: /* original 2f02, guest PC 0x0c034d1c */
if(!s->budget--) { s->failed_pc=0x0c034d1cu; return 0; }
write(ram,r[15],r[0],4);
goto P_0c034d1e;
P_0c034d1e: /* original 0002, guest PC 0x0c034d1e */
if(!s->budget--) { s->failed_pc=0x0c034d1eu; return 0; }
r[0]=r[17];
goto P_0c034d20;
P_0c034d20: /* original 938b, guest PC 0x0c034d20 */
if(!s->budget--) { s->failed_pc=0x0c034d20u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c034e3au,2);
goto P_0c034d22;
P_0c034d22: /* original 2039, guest PC 0x0c034d22 */
if(!s->budget--) { s->failed_pc=0x0c034d22u; return 0; }
r[0]&=r[3];
goto P_0c034d24;
P_0c034d24: /* original 400e, guest PC 0x0c034d24 */
if(!s->budget--) { s->failed_pc=0x0c034d24u; return 0; }
r[17]=r[0];
goto P_0c034d26;
P_0c034d26: /* original 52d5, guest PC 0x0c034d26 */
if(!s->budget--) { s->failed_pc=0x0c034d26u; return 0; }
r[2]=read(ram,r[13]+20,4);
goto P_0c034d28;
P_0c034d28: /* original 6322, guest PC 0x0c034d28 */
if(!s->budget--) { s->failed_pc=0x0c034d28u; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c034d2a;
P_0c034d2a: /* original 430b, guest PC 0x0c034d2a */
if(!s->budget--) { s->failed_pc=0x0c034d2au; return 0; }
target=r[3];
r[16]=code_base|0x0c034d2eu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c034d2eu) { target=s->pc; goto dispatch; }
goto P_0c034d2e;
P_0c034d2c: /* original 0009, guest PC 0x0c034d2c */
if(!s->budget--) { s->failed_pc=0x0c034d2cu; return 0; }
goto P_0c034d2e;
P_0c034d2e: /* original 62e2, guest PC 0x0c034d2e */
if(!s->budget--) { s->failed_pc=0x0c034d2eu; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c034d30;
P_0c034d30: /* original ed00, guest PC 0x0c034d30 */
if(!s->budget--) { s->failed_pc=0x0c034d30u; return 0; }
r[13]=0x00000000u;
goto P_0c034d32;
P_0c034d32: /* original 12d8, guest PC 0x0c034d32 */
if(!s->budget--) { s->failed_pc=0x0c034d32u; return 0; }
write(ram,r[2]+32,r[13],4);
goto P_0c034d34;
P_0c034d34: /* original 63e2, guest PC 0x0c034d34 */
if(!s->budget--) { s->failed_pc=0x0c034d34u; return 0; }
tmp=read(ram,r[14],4);
r[3]=tmp;
goto P_0c034d36;
P_0c034d36: /* original 13d9, guest PC 0x0c034d36 */
if(!s->budget--) { s->failed_pc=0x0c034d36u; return 0; }
write(ram,r[3]+36,r[13],4);
goto P_0c034d38;
P_0c034d38: /* original d142, guest PC 0x0c034d38 */
if(!s->budget--) { s->failed_pc=0x0c034d38u; return 0; }
r[1]=read(ram,0x0c034e44u,4);
goto P_0c034d3a;
P_0c034d3a: /* original 62e2, guest PC 0x0c034d3a */
if(!s->budget--) { s->failed_pc=0x0c034d3au; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c034d3c;
P_0c034d3c: /* original 6312, guest PC 0x0c034d3c */
if(!s->budget--) { s->failed_pc=0x0c034d3cu; return 0; }
tmp=read(ram,r[1],4);
r[3]=tmp;
goto P_0c034d3e;
P_0c034d3e: /* original 1231, guest PC 0x0c034d3e */
if(!s->budget--) { s->failed_pc=0x0c034d3eu; return 0; }
write(ram,r[2]+4,r[3],4);
goto P_0c034d40;
P_0c034d40: /* original d041, guest PC 0x0c034d40 */
if(!s->budget--) { s->failed_pc=0x0c034d40u; return 0; }
r[0]=read(ram,0x0c034e48u,4);
goto P_0c034d42;
P_0c034d42: /* original 62e2, guest PC 0x0c034d42 */
if(!s->budget--) { s->failed_pc=0x0c034d42u; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c034d44;
P_0c034d44: /* original 6302, guest PC 0x0c034d44 */
if(!s->budget--) { s->failed_pc=0x0c034d44u; return 0; }
tmp=read(ram,r[0],4);
r[3]=tmp;
goto P_0c034d46;
P_0c034d46: /* original 1232, guest PC 0x0c034d46 */
if(!s->budget--) { s->failed_pc=0x0c034d46u; return 0; }
write(ram,r[2]+8,r[3],4);
goto P_0c034d48;
P_0c034d48: /* original 62e2, guest PC 0x0c034d48 */
if(!s->budget--) { s->failed_pc=0x0c034d48u; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c034d4a;
P_0c034d4a: /* original 12da, guest PC 0x0c034d4a */
if(!s->budget--) { s->failed_pc=0x0c034d4au; return 0; }
write(ram,r[2]+40,r[13],4);
goto P_0c034d4c;
P_0c034d4c: /* original 62e2, guest PC 0x0c034d4c */
if(!s->budget--) { s->failed_pc=0x0c034d4cu; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c034d4e;
P_0c034d4e: /* original 64d3, guest PC 0x0c034d4e */
if(!s->budget--) { s->failed_pc=0x0c034d4eu; return 0; }
r[4]=r[13];
goto P_0c034d50;
P_0c034d50: /* original 65e2, guest PC 0x0c034d50 */
if(!s->budget--) { s->failed_pc=0x0c034d50u; return 0; }
tmp=read(ram,r[14],4);
r[5]=tmp;
goto P_0c034d52;
P_0c034d52: /* original 6122, guest PC 0x0c034d52 */
if(!s->budget--) { s->failed_pc=0x0c034d52u; return 0; }
tmp=read(ram,r[2],4);
r[1]=tmp;
goto P_0c034d54;
P_0c034d54: /* original 9372, guest PC 0x0c034d54 */
if(!s->budget--) { s->failed_pc=0x0c034d54u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c034e3cu,2);
goto P_0c034d56;
P_0c034d56: /* original 7101, guest PC 0x0c034d56 */
if(!s->budget--) { s->failed_pc=0x0c034d56u; return 0; }
r[1]+=0x00000001u;
goto P_0c034d58;
P_0c034d58: /* original 4115, guest PC 0x0c034d58 */
if(!s->budget--) { s->failed_pc=0x0c034d58u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[1]>0)!=0);
goto P_0c034d5a;
P_0c034d5a: /* original 8f09, guest PC 0x0c034d5a */
if(!s->budget--) { s->failed_pc=0x0c034d5au; return 0; }
cond=r[17]&1u;
r[5]+=r[3];
if(!cond) { goto P_0c034d70; }
goto P_0c034d5e;
P_0c034d5c: /* original 353c, guest PC 0x0c034d5c */
if(!s->budget--) { s->failed_pc=0x0c034d5cu; return 0; }
r[5]+=r[3];
goto P_0c034d5e;
P_0c034d5e: /* original e048, guest PC 0x0c034d5e */
if(!s->budget--) { s->failed_pc=0x0c034d5eu; return 0; }
r[0]=0x00000048u;
goto P_0c034d60;
P_0c034d60: /* original 7401, guest PC 0x0c034d60 */
if(!s->budget--) { s->failed_pc=0x0c034d60u; return 0; }
r[4]+=0x00000001u;
goto P_0c034d62;
P_0c034d62: /* original 05d5, guest PC 0x0c034d62 */
if(!s->budget--) { s->failed_pc=0x0c034d62u; return 0; }
write(ram,r[5]+r[0],r[13],2);
goto P_0c034d64;
P_0c034d64: /* original 63e2, guest PC 0x0c034d64 */
if(!s->budget--) { s->failed_pc=0x0c034d64u; return 0; }
tmp=read(ram,r[14],4);
r[3]=tmp;
goto P_0c034d66;
P_0c034d66: /* original 6232, guest PC 0x0c034d66 */
if(!s->budget--) { s->failed_pc=0x0c034d66u; return 0; }
tmp=read(ram,r[3],4);
r[2]=tmp;
goto P_0c034d68;
P_0c034d68: /* original 7201, guest PC 0x0c034d68 */
if(!s->budget--) { s->failed_pc=0x0c034d68u; return 0; }
r[2]+=0x00000001u;
goto P_0c034d6a;
P_0c034d6a: /* original 3423, guest PC 0x0c034d6a */
if(!s->budget--) { s->failed_pc=0x0c034d6au; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[2])!=0);
goto P_0c034d6c;
P_0c034d6c: /* original 8ff7, guest PC 0x0c034d6c */
if(!s->budget--) { s->failed_pc=0x0c034d6cu; return 0; }
cond=r[17]&1u;
r[5]+=0x00000050u;
if(!cond) { goto P_0c034d5e; }
goto P_0c034d70;
P_0c034d6e: /* original 7550, guest PC 0x0c034d6e */
if(!s->budget--) { s->failed_pc=0x0c034d6eu; return 0; }
r[5]+=0x00000050u;
goto P_0c034d70;
P_0c034d70: /* original 62e2, guest PC 0x0c034d70 */
if(!s->budget--) { s->failed_pc=0x0c034d70u; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c034d72;
P_0c034d72: /* original 9163, guest PC 0x0c034d72 */
if(!s->budget--) { s->failed_pc=0x0c034d72u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c034e3cu,2);
goto P_0c034d74;
P_0c034d74: /* original 6323, guest PC 0x0c034d74 */
if(!s->budget--) { s->failed_pc=0x0c034d74u; return 0; }
r[3]=r[2];
goto P_0c034d76;
P_0c034d76: /* original 313c, guest PC 0x0c034d76 */
if(!s->budget--) { s->failed_pc=0x0c034d76u; return 0; }
r[1]+=r[3];
goto P_0c034d78;
P_0c034d78: /* original 121b, guest PC 0x0c034d78 */
if(!s->budget--) { s->failed_pc=0x0c034d78u; return 0; }
write(ram,r[2]+44,r[1],4);
goto P_0c034d7a;
P_0c034d7a: /* original 63e2, guest PC 0x0c034d7a */
if(!s->budget--) { s->failed_pc=0x0c034d7au; return 0; }
tmp=read(ram,r[14],4);
r[3]=tmp;
goto P_0c034d7c;
P_0c034d7c: /* original 915e, guest PC 0x0c034d7c */
if(!s->budget--) { s->failed_pc=0x0c034d7cu; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c034e3cu,2);
goto P_0c034d7e;
P_0c034d7e: /* original 6233, guest PC 0x0c034d7e */
if(!s->budget--) { s->failed_pc=0x0c034d7eu; return 0; }
r[2]=r[3];
goto P_0c034d80;
P_0c034d80: /* original 312c, guest PC 0x0c034d80 */
if(!s->budget--) { s->failed_pc=0x0c034d80u; return 0; }
r[1]+=r[2];
goto P_0c034d82;
P_0c034d82: /* original 7150, guest PC 0x0c034d82 */
if(!s->budget--) { s->failed_pc=0x0c034d82u; return 0; }
r[1]+=0x00000050u;
goto P_0c034d84;
P_0c034d84: /* original 131c, guest PC 0x0c034d84 */
if(!s->budget--) { s->failed_pc=0x0c034d84u; return 0; }
write(ram,r[3]+48,r[1],4);
goto P_0c034d86;
P_0c034d86: /* original 60f2, guest PC 0x0c034d86 */
if(!s->budget--) { s->failed_pc=0x0c034d86u; return 0; }
tmp=read(ram,r[15],4);
r[0]=tmp;
goto P_0c034d88;
P_0c034d88: /* original 0302, guest PC 0x0c034d88 */
if(!s->budget--) { s->failed_pc=0x0c034d88u; return 0; }
r[3]=r[17];
goto P_0c034d8a;
P_0c034d8a: /* original 9256, guest PC 0x0c034d8a */
if(!s->budget--) { s->failed_pc=0x0c034d8au; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c034e3au,2);
goto P_0c034d8c;
P_0c034d8c: /* original c90f, guest PC 0x0c034d8c */
if(!s->budget--) { s->failed_pc=0x0c034d8cu; return 0; }
r[0]&=15u;
goto P_0c034d8e;
P_0c034d8e: /* original 4008, guest PC 0x0c034d8e */
if(!s->budget--) { s->failed_pc=0x0c034d8eu; return 0; }
r[0]<<=2;
goto P_0c034d90;
P_0c034d90: /* original 2329, guest PC 0x0c034d90 */
if(!s->budget--) { s->failed_pc=0x0c034d90u; return 0; }
r[3]&=r[2];
goto P_0c034d92;
P_0c034d92: /* original 4008, guest PC 0x0c034d92 */
if(!s->budget--) { s->failed_pc=0x0c034d92u; return 0; }
r[0]<<=2;
goto P_0c034d94;
P_0c034d94: /* original 203b, guest PC 0x0c034d94 */
if(!s->budget--) { s->failed_pc=0x0c034d94u; return 0; }
r[0]|=r[3];
goto P_0c034d96;
P_0c034d96: /* original 400e, guest PC 0x0c034d96 */
if(!s->budget--) { s->failed_pc=0x0c034d96u; return 0; }
r[17]=r[0];
goto P_0c034d98;
P_0c034d98: /* original d32c, guest PC 0x0c034d98 */
if(!s->budget--) { s->failed_pc=0x0c034d98u; return 0; }
r[3]=read(ram,0x0c034e4cu,4);
goto P_0c034d9a;
P_0c034d9a: /* original 6132, guest PC 0x0c034d9a */
if(!s->budget--) { s->failed_pc=0x0c034d9au; return 0; }
tmp=read(ram,r[3],4);
r[1]=tmp;
goto P_0c034d9c;
P_0c034d9c: /* original 2118, guest PC 0x0c034d9c */
if(!s->budget--) { s->failed_pc=0x0c034d9cu; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[1])==0)!=0);
goto P_0c034d9e;
P_0c034d9e: /* original 8b07, guest PC 0x0c034d9e */
if(!s->budget--) { s->failed_pc=0x0c034d9eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c034db0; }
goto P_0c034da0;
P_0c034da0: /* original 944d, guest PC 0x0c034da0 */
if(!s->budget--) { s->failed_pc=0x0c034da0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c034e3eu,2);
goto P_0c034da2;
P_0c034da2: /* original e700, guest PC 0x0c034da2 */
if(!s->budget--) { s->failed_pc=0x0c034da2u; return 0; }
r[7]=0x00000000u;
goto P_0c034da4;
P_0c034da4: /* original d22b, guest PC 0x0c034da4 */
if(!s->budget--) { s->failed_pc=0x0c034da4u; return 0; }
r[2]=read(ram,0x0c034e54u,4);
goto P_0c034da6;
P_0c034da6: /* original d52a, guest PC 0x0c034da6 */
if(!s->budget--) { s->failed_pc=0x0c034da6u; return 0; }
r[5]=read(ram,0x0c034e50u,4);
goto P_0c034da8;
P_0c034da8: /* original 420b, guest PC 0x0c034da8 */
if(!s->budget--) { s->failed_pc=0x0c034da8u; return 0; }
target=r[2];
r[16]=code_base|0x0c034dacu;
r[6]=0x00000050u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c034dacu) { target=s->pc; goto dispatch; }
goto P_0c034dac;
P_0c034daa: /* original e650, guest PC 0x0c034daa */
if(!s->budget--) { s->failed_pc=0x0c034daau; return 0; }
r[6]=0x00000050u;
goto P_0c034dac;
P_0c034dac: /* original d327, guest PC 0x0c034dac */
if(!s->budget--) { s->failed_pc=0x0c034dacu; return 0; }
r[3]=read(ram,0x0c034e4cu,4);
goto P_0c034dae;
P_0c034dae: /* original 2302, guest PC 0x0c034dae */
if(!s->budget--) { s->failed_pc=0x0c034daeu; return 0; }
write(ram,r[3],r[0],4);
goto P_0c034db0;
P_0c034db0: /* original d129, guest PC 0x0c034db0 */
if(!s->budget--) { s->failed_pc=0x0c034db0u; return 0; }
r[1]=read(ram,0x0c034e58u,4);
goto P_0c034db2;
P_0c034db2: /* original 6212, guest PC 0x0c034db2 */
if(!s->budget--) { s->failed_pc=0x0c034db2u; return 0; }
tmp=read(ram,r[1],4);
r[2]=tmp;
goto P_0c034db4;
P_0c034db4: /* original 2228, guest PC 0x0c034db4 */
if(!s->budget--) { s->failed_pc=0x0c034db4u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c034db6;
P_0c034db6: /* original 8b07, guest PC 0x0c034db6 */
if(!s->budget--) { s->failed_pc=0x0c034db6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c034dc8; }
goto P_0c034db8;
P_0c034db8: /* original 9442, guest PC 0x0c034db8 */
if(!s->budget--) { s->failed_pc=0x0c034db8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c034e40u,2);
goto P_0c034dba;
P_0c034dba: /* original e700, guest PC 0x0c034dba */
if(!s->budget--) { s->failed_pc=0x0c034dbau; return 0; }
r[7]=0x00000000u;
goto P_0c034dbc;
P_0c034dbc: /* original d325, guest PC 0x0c034dbc */
if(!s->budget--) { s->failed_pc=0x0c034dbcu; return 0; }
r[3]=read(ram,0x0c034e54u,4);
goto P_0c034dbe;
P_0c034dbe: /* original d527, guest PC 0x0c034dbe */
if(!s->budget--) { s->failed_pc=0x0c034dbeu; return 0; }
r[5]=read(ram,0x0c034e5cu,4);
goto P_0c034dc0;
P_0c034dc0: /* original 430b, guest PC 0x0c034dc0 */
if(!s->budget--) { s->failed_pc=0x0c034dc0u; return 0; }
target=r[3];
r[16]=code_base|0x0c034dc4u;
r[6]=0x00000010u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c034dc4u) { target=s->pc; goto dispatch; }
goto P_0c034dc4;
P_0c034dc2: /* original e610, guest PC 0x0c034dc2 */
if(!s->budget--) { s->failed_pc=0x0c034dc2u; return 0; }
r[6]=0x00000010u;
goto P_0c034dc4;
P_0c034dc4: /* original d224, guest PC 0x0c034dc4 */
if(!s->budget--) { s->failed_pc=0x0c034dc4u; return 0; }
r[2]=read(ram,0x0c034e58u,4);
goto P_0c034dc6;
P_0c034dc6: /* original 2202, guest PC 0x0c034dc6 */
if(!s->budget--) { s->failed_pc=0x0c034dc6u; return 0; }
write(ram,r[2],r[0],4);
goto P_0c034dc8;
P_0c034dc8: /* original 64e2, guest PC 0x0c034dc8 */
if(!s->budget--) { s->failed_pc=0x0c034dc8u; return 0; }
tmp=read(ram,r[14],4);
r[4]=tmp;
goto P_0c034dca;
P_0c034dca: /* original e700, guest PC 0x0c034dca */
if(!s->budget--) { s->failed_pc=0x0c034dcau; return 0; }
r[7]=0x00000000u;
goto P_0c034dcc;
P_0c034dcc: /* original d324, guest PC 0x0c034dcc */
if(!s->budget--) { s->failed_pc=0x0c034dccu; return 0; }
r[3]=read(ram,0x0c034e60u,4);
goto P_0c034dce;
P_0c034dce: /* original 6673, guest PC 0x0c034dce */
if(!s->budget--) { s->failed_pc=0x0c034dceu; return 0; }
r[6]=r[7];
goto P_0c034dd0;
P_0c034dd0: /* original 6573, guest PC 0x0c034dd0 */
if(!s->budget--) { s->failed_pc=0x0c034dd0u; return 0; }
r[5]=r[7];
goto P_0c034dd2;
P_0c034dd2: /* original 430b, guest PC 0x0c034dd2 */
if(!s->budget--) { s->failed_pc=0x0c034dd2u; return 0; }
target=r[3];
r[16]=code_base|0x0c034dd6u;
r[4]=read(ram,r[4]+44,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c034dd6u) { target=s->pc; goto dispatch; }
goto P_0c034dd6;
P_0c034dd4: /* original 544b, guest PC 0x0c034dd4 */
if(!s->budget--) { s->failed_pc=0x0c034dd4u; return 0; }
r[4]=read(ram,r[4]+44,4);
goto P_0c034dd6;
P_0c034dd6: /* original 62e2, guest PC 0x0c034dd6 */
if(!s->budget--) { s->failed_pc=0x0c034dd6u; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c034dd8;
P_0c034dd8: /* original 5325, guest PC 0x0c034dd8 */
if(!s->budget--) { s->failed_pc=0x0c034dd8u; return 0; }
r[3]=read(ram,r[2]+20,4);
goto P_0c034dda;
P_0c034dda: /* original 5137, guest PC 0x0c034dda */
if(!s->budget--) { s->failed_pc=0x0c034ddau; return 0; }
r[1]=read(ram,r[3]+28,4);
goto P_0c034ddc;
P_0c034ddc: /* original 410b, guest PC 0x0c034ddc */
if(!s->budget--) { s->failed_pc=0x0c034ddcu; return 0; }
target=r[1];
r[16]=code_base|0x0c034de0u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c034de0u) { target=s->pc; goto dispatch; }
goto P_0c034de0;
P_0c034dde: /* original 0009, guest PC 0x0c034dde */
if(!s->budget--) { s->failed_pc=0x0c034ddeu; return 0; }
goto P_0c034de0;
P_0c034de0: /* original 6403, guest PC 0x0c034de0 */
if(!s->budget--) { s->failed_pc=0x0c034de0u; return 0; }
r[4]=r[0];
goto P_0c034de2;
P_0c034de2: /* original 2448, guest PC 0x0c034de2 */
if(!s->budget--) { s->failed_pc=0x0c034de2u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c034de4;
P_0c034de4: /* original 891d, guest PC 0x0c034de4 */
if(!s->budget--) { s->failed_pc=0x0c034de4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c034e22; }
goto P_0c034de6;
P_0c034de6: /* original 62e2, guest PC 0x0c034de6 */
if(!s->budget--) { s->failed_pc=0x0c034de6u; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c034de8;
P_0c034de8: /* original e04c, guest PC 0x0c034de8 */
if(!s->budget--) { s->failed_pc=0x0c034de8u; return 0; }
r[0]=0x0000004cu;
goto P_0c034dea;
P_0c034dea: /* original e104, guest PC 0x0c034dea */
if(!s->budget--) { s->failed_pc=0x0c034deau; return 0; }
r[1]=0x00000004u;
goto P_0c034dec;
P_0c034dec: /* original 532b, guest PC 0x0c034dec */
if(!s->budget--) { s->failed_pc=0x0c034decu; return 0; }
r[3]=read(ram,r[2]+44,4);
goto P_0c034dee;
P_0c034dee: /* original 134f, guest PC 0x0c034dee */
if(!s->budget--) { s->failed_pc=0x0c034deeu; return 0; }
write(ram,r[3]+60,r[4],4);
goto P_0c034df0;
P_0c034df0: /* original 62e2, guest PC 0x0c034df0 */
if(!s->budget--) { s->failed_pc=0x0c034df0u; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c034df2;
P_0c034df2: /* original 532b, guest PC 0x0c034df2 */
if(!s->budget--) { s->failed_pc=0x0c034df2u; return 0; }
r[3]=read(ram,r[2]+44,4);
goto P_0c034df4;
P_0c034df4: /* original 0315, guest PC 0x0c034df4 */
if(!s->budget--) { s->failed_pc=0x0c034df4u; return 0; }
write(ram,r[3]+r[0],r[1],2);
goto P_0c034df6;
P_0c034df6: /* original 63e2, guest PC 0x0c034df6 */
if(!s->budget--) { s->failed_pc=0x0c034df6u; return 0; }
tmp=read(ram,r[14],4);
r[3]=tmp;
goto P_0c034df8;
P_0c034df8: /* original 6233, guest PC 0x0c034df8 */
if(!s->budget--) { s->failed_pc=0x0c034df8u; return 0; }
r[2]=r[3];
goto P_0c034dfa;
P_0c034dfa: /* original 512b, guest PC 0x0c034dfa */
if(!s->budget--) { s->failed_pc=0x0c034dfau; return 0; }
r[1]=read(ram,r[2]+44,4);
goto P_0c034dfc;
P_0c034dfc: /* original 131a, guest PC 0x0c034dfc */
if(!s->budget--) { s->failed_pc=0x0c034dfcu; return 0; }
write(ram,r[3]+40,r[1],4);
goto P_0c034dfe;
P_0c034dfe: /* original d319, guest PC 0x0c034dfe */
if(!s->budget--) { s->failed_pc=0x0c034dfeu; return 0; }
r[3]=read(ram,0x0c034e64u,4);
goto P_0c034e00;
P_0c034e00: /* original 64e2, guest PC 0x0c034e00 */
if(!s->budget--) { s->failed_pc=0x0c034e00u; return 0; }
tmp=read(ram,r[14],4);
r[4]=tmp;
goto P_0c034e02;
P_0c034e02: /* original 430b, guest PC 0x0c034e02 */
if(!s->budget--) { s->failed_pc=0x0c034e02u; return 0; }
target=r[3];
r[16]=code_base|0x0c034e06u;
r[4]=read(ram,r[4]+44,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c034e06u) { target=s->pc; goto dispatch; }
goto P_0c034e06;
P_0c034e04: /* original 544b, guest PC 0x0c034e04 */
if(!s->budget--) { s->failed_pc=0x0c034e04u; return 0; }
r[4]=read(ram,r[4]+44,4);
goto P_0c034e06;
P_0c034e06: /* original d318, guest PC 0x0c034e06 */
if(!s->budget--) { s->failed_pc=0x0c034e06u; return 0; }
r[3]=read(ram,0x0c034e68u,4);
goto P_0c034e08;
P_0c034e08: /* original 6c03, guest PC 0x0c034e08 */
if(!s->budget--) { s->failed_pc=0x0c034e08u; return 0; }
r[12]=r[0];
goto P_0c034e0a;
P_0c034e0a: /* original 64e2, guest PC 0x0c034e0a */
if(!s->budget--) { s->failed_pc=0x0c034e0au; return 0; }
tmp=read(ram,r[14],4);
r[4]=tmp;
goto P_0c034e0c;
P_0c034e0c: /* original 430b, guest PC 0x0c034e0c */
if(!s->budget--) { s->failed_pc=0x0c034e0cu; return 0; }
target=r[3];
r[16]=code_base|0x0c034e10u;
r[4]=read(ram,r[4]+44,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c034e10u) { target=s->pc; goto dispatch; }
goto P_0c034e10;
P_0c034e0e: /* original 544b, guest PC 0x0c034e0e */
if(!s->budget--) { s->failed_pc=0x0c034e0eu; return 0; }
r[4]=read(ram,r[4]+44,4);
goto P_0c034e10;
P_0c034e10: /* original 62e2, guest PC 0x0c034e10 */
if(!s->budget--) { s->failed_pc=0x0c034e10u; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c034e12;
P_0c034e12: /* original 6bf3, guest PC 0x0c034e12 */
if(!s->budget--) { s->failed_pc=0x0c034e12u; return 0; }
r[11]=r[15];
goto P_0c034e14;
P_0c034e14: /* original 7b04, guest PC 0x0c034e14 */
if(!s->budget--) { s->failed_pc=0x0c034e14u; return 0; }
r[11]+=0x00000004u;
goto P_0c034e16;
P_0c034e16: /* original 5325, guest PC 0x0c034e16 */
if(!s->budget--) { s->failed_pc=0x0c034e16u; return 0; }
r[3]=read(ram,r[2]+20,4);
goto P_0c034e18;
P_0c034e18: /* original 5138, guest PC 0x0c034e18 */
if(!s->budget--) { s->failed_pc=0x0c034e18u; return 0; }
r[1]=read(ram,r[3]+32,4);
goto P_0c034e1a;
P_0c034e1a: /* original 410b, guest PC 0x0c034e1a */
if(!s->budget--) { s->failed_pc=0x0c034e1au; return 0; }
target=r[1];
r[16]=code_base|0x0c034e1eu;
r[4]=r[11];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c034e1eu) { target=s->pc; goto dispatch; }
goto P_0c034e1e;
P_0c034e1c: /* original 64b3, guest PC 0x0c034e1c */
if(!s->budget--) { s->failed_pc=0x0c034e1cu; return 0; }
r[4]=r[11];
goto P_0c034e1e;
P_0c034e1e: /* original 2008, guest PC 0x0c034e1e */
if(!s->budget--) { s->failed_pc=0x0c034e1eu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c034e20;
P_0c034e20: /* original 8b01, guest PC 0x0c034e20 */
if(!s->budget--) { s->failed_pc=0x0c034e20u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c034e26; }
goto P_0c034e22;
P_0c034e22: /* original a078, guest PC 0x0c034e22 */
if(!s->budget--) { s->failed_pc=0x0c034e22u; return 0; }
r[0]=0xfffffffeu;
goto P_0c034f16;
P_0c034e24: /* original e0fe, guest PC 0x0c034e24 */
if(!s->budget--) { s->failed_pc=0x0c034e24u; return 0; }
r[0]=0xfffffffeu;
goto P_0c034e26;
P_0c034e26: /* original 2cc8, guest PC 0x0c034e26 */
if(!s->budget--) { s->failed_pc=0x0c034e26u; return 0; }
r[17]=(r[17]&~1u)|(((r[12]&r[12])==0)!=0);
goto P_0c034e28;
P_0c034e28: /* original 8922, guest PC 0x0c034e28 */
if(!s->budget--) { s->failed_pc=0x0c034e28u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c034e70; }
goto P_0c034e2a;
P_0c034e2a: /* original 60c3, guest PC 0x0c034e2a */
if(!s->budget--) { s->failed_pc=0x0c034e2au; return 0; }
r[0]=r[12];
goto P_0c034e2c;
P_0c034e2c: /* original 88e3, guest PC 0x0c034e2c */
if(!s->budget--) { s->failed_pc=0x0c034e2cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffe3u)!=0);
goto P_0c034e2e;
P_0c034e2e: /* original 8b1d, guest PC 0x0c034e2e */
if(!s->budget--) { s->failed_pc=0x0c034e2eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c034e6c; }
goto P_0c034e30;
P_0c034e30: /* original 60b2, guest PC 0x0c034e30 */
if(!s->budget--) { s->failed_pc=0x0c034e30u; return 0; }
tmp=read(ram,r[11],4);
r[0]=tmp;
goto P_0c034e32;
P_0c034e32: /* original 8806, guest PC 0x0c034e32 */
if(!s->budget--) { s->failed_pc=0x0c034e32u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000006u)!=0);
goto P_0c034e34;
P_0c034e34: /* original 8b1a, guest PC 0x0c034e34 */
if(!s->budget--) { s->failed_pc=0x0c034e34u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c034e6c; }
goto P_0c034e36;
P_0c034e36: /* original a06e, guest PC 0x0c034e36 */
if(!s->budget--) { s->failed_pc=0x0c034e36u; return 0; }
r[0]=0xffffffe9u;
goto P_0c034f16;
P_0c034e38: /* original e0e9, guest PC 0x0c034e38 */
if(!s->budget--) { s->failed_pc=0x0c034e38u; return 0; }
r[0]=0xffffffe9u;
return vf3_matrix_family(0x0c034e3au,s,ram);
P_0c034e6c: /* original a053, guest PC 0x0c034e6c */
if(!s->budget--) { s->failed_pc=0x0c034e6cu; return 0; }
r[0]=r[12];
goto P_0c034f16;
P_0c034e6e: /* original 60c3, guest PC 0x0c034e6e */
if(!s->budget--) { s->failed_pc=0x0c034e6eu; return 0; }
r[0]=r[12];
goto P_0c034e70;
P_0c034e70: /* original 52b1, guest PC 0x0c034e70 */
if(!s->budget--) { s->failed_pc=0x0c034e70u; return 0; }
r[2]=read(ram,r[11]+4,4);
goto P_0c034e72;
P_0c034e72: /* original 9370, guest PC 0x0c034e72 */
if(!s->budget--) { s->failed_pc=0x0c034e72u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c034f56u,2);
goto P_0c034e74;
P_0c034e74: /* original 3230, guest PC 0x0c034e74 */
if(!s->budget--) { s->failed_pc=0x0c034e74u; return 0; }
r[17]=(r[17]&~1u)|((r[2]==r[3])!=0);
goto P_0c034e76;
P_0c034e76: /* original 8b49, guest PC 0x0c034e76 */
if(!s->budget--) { s->failed_pc=0x0c034e76u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c034f0c; }
goto P_0c034e78;
P_0c034e78: /* original 66e2, guest PC 0x0c034e78 */
if(!s->budget--) { s->failed_pc=0x0c034e78u; return 0; }
tmp=read(ram,r[14],4);
r[6]=tmp;
goto P_0c034e7a;
P_0c034e7a: /* original e501, guest PC 0x0c034e7a */
if(!s->budget--) { s->failed_pc=0x0c034e7au; return 0; }
r[5]=0x00000001u;
goto P_0c034e7c;
P_0c034e7c: /* original 64e2, guest PC 0x0c034e7c */
if(!s->budget--) { s->failed_pc=0x0c034e7cu; return 0; }
tmp=read(ram,r[14],4);
r[4]=tmp;
goto P_0c034e7e;
P_0c034e7e: /* original d339, guest PC 0x0c034e7e */
if(!s->budget--) { s->failed_pc=0x0c034e7eu; return 0; }
r[3]=read(ram,0x0c034f64u,4);
goto P_0c034e80;
P_0c034e80: /* original 7640, guest PC 0x0c034e80 */
if(!s->budget--) { s->failed_pc=0x0c034e80u; return 0; }
r[6]+=0x00000040u;
goto P_0c034e82;
P_0c034e82: /* original 430b, guest PC 0x0c034e82 */
if(!s->budget--) { s->failed_pc=0x0c034e82u; return 0; }
target=r[3];
r[16]=code_base|0x0c034e86u;
r[4]=read(ram,r[4]+4,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c034e86u) { target=s->pc; goto dispatch; }
goto P_0c034e86;
P_0c034e84: /* original 5441, guest PC 0x0c034e84 */
if(!s->budget--) { s->failed_pc=0x0c034e84u; return 0; }
r[4]=read(ram,r[4]+4,4);
goto P_0c034e86;
P_0c034e86: /* original 6403, guest PC 0x0c034e86 */
if(!s->budget--) { s->failed_pc=0x0c034e86u; return 0; }
r[4]=r[0];
goto P_0c034e88;
P_0c034e88: /* original 2448, guest PC 0x0c034e88 */
if(!s->budget--) { s->failed_pc=0x0c034e88u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c034e8a;
P_0c034e8a: /* original 8b38, guest PC 0x0c034e8a */
if(!s->budget--) { s->failed_pc=0x0c034e8au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c034efe; }
goto P_0c034e8c;
P_0c034e8c: /* original 64e2, guest PC 0x0c034e8c */
if(!s->budget--) { s->failed_pc=0x0c034e8cu; return 0; }
tmp=read(ram,r[14],4);
r[4]=tmp;
goto P_0c034e8e;
P_0c034e8e: /* original bcca, guest PC 0x0c034e8e */
if(!s->budget--) { s->failed_pc=0x0c034e8eu; return 0; }
target=0x0c034826u; r[16]=code_base|0x0c034e92u;
r[4]+=0x00000040u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c034e92u) { target=s->pc; goto dispatch; }
goto P_0c034e92;
P_0c034e90: /* original 7440, guest PC 0x0c034e90 */
if(!s->budget--) { s->failed_pc=0x0c034e90u; return 0; }
r[4]+=0x00000040u;
goto P_0c034e92;
P_0c034e92: /* original 2008, guest PC 0x0c034e92 */
if(!s->budget--) { s->failed_pc=0x0c034e92u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c034e94;
P_0c034e94: /* original 893a, guest PC 0x0c034e94 */
if(!s->budget--) { s->failed_pc=0x0c034e94u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c034f0c; }
goto P_0c034e96;
P_0c034e96: /* original 64e2, guest PC 0x0c034e96 */
if(!s->budget--) { s->failed_pc=0x0c034e96u; return 0; }
tmp=read(ram,r[14],4);
r[4]=tmp;
goto P_0c034e98;
P_0c034e98: /* original 68e2, guest PC 0x0c034e98 */
if(!s->budget--) { s->failed_pc=0x0c034e98u; return 0; }
tmp=read(ram,r[14],4);
r[8]=tmp;
goto P_0c034e9a;
P_0c034e9a: /* original 935d, guest PC 0x0c034e9a */
if(!s->budget--) { s->failed_pc=0x0c034e9au; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c034f58u,2);
goto P_0c034e9c;
P_0c034e9c: /* original 7440, guest PC 0x0c034e9c */
if(!s->budget--) { s->failed_pc=0x0c034e9cu; return 0; }
r[4]+=0x00000040u;
goto P_0c034e9e;
P_0c034e9e: /* original 780c, guest PC 0x0c034e9e */
if(!s->budget--) { s->failed_pc=0x0c034e9eu; return 0; }
r[8]+=0x0000000cu;
goto P_0c034ea0;
P_0c034ea0: /* original bcae, guest PC 0x0c034ea0 */
if(!s->budget--) { s->failed_pc=0x0c034ea0u; return 0; }
target=0x0c034800u; r[16]=code_base|0x0c034ea4u;
r[4]+=r[3];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c034ea4u) { target=s->pc; goto dispatch; }
goto P_0c034ea4;
P_0c034ea2: /* original 343c, guest PC 0x0c034ea2 */
if(!s->budget--) { s->failed_pc=0x0c034ea2u; return 0; }
r[4]+=r[3];
goto P_0c034ea4;
P_0c034ea4: /* original 2802, guest PC 0x0c034ea4 */
if(!s->budget--) { s->failed_pc=0x0c034ea4u; return 0; }
write(ram,r[8],r[0],4);
goto P_0c034ea6;
P_0c034ea6: /* original 63e2, guest PC 0x0c034ea6 */
if(!s->budget--) { s->failed_pc=0x0c034ea6u; return 0; }
tmp=read(ram,r[14],4);
r[3]=tmp;
goto P_0c034ea8;
P_0c034ea8: /* original 9257, guest PC 0x0c034ea8 */
if(!s->budget--) { s->failed_pc=0x0c034ea8u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c034f5au,2);
goto P_0c034eaa;
P_0c034eaa: /* original 5133, guest PC 0x0c034eaa */
if(!s->budget--) { s->failed_pc=0x0c034eaau; return 0; }
r[1]=read(ram,r[3]+12,4);
goto P_0c034eac;
P_0c034eac: /* original 312c, guest PC 0x0c034eac */
if(!s->budget--) { s->failed_pc=0x0c034eacu; return 0; }
r[1]+=r[2];
goto P_0c034eae;
P_0c034eae: /* original 1313, guest PC 0x0c034eae */
if(!s->budget--) { s->failed_pc=0x0c034eaeu; return 0; }
write(ram,r[3]+12,r[1],4);
goto P_0c034eb0;
P_0c034eb0: /* original 64e2, guest PC 0x0c034eb0 */
if(!s->budget--) { s->failed_pc=0x0c034eb0u; return 0; }
tmp=read(ram,r[14],4);
r[4]=tmp;
goto P_0c034eb2;
P_0c034eb2: /* original 68e2, guest PC 0x0c034eb2 */
if(!s->budget--) { s->failed_pc=0x0c034eb2u; return 0; }
tmp=read(ram,r[14],4);
r[8]=tmp;
goto P_0c034eb4;
P_0c034eb4: /* original 9352, guest PC 0x0c034eb4 */
if(!s->budget--) { s->failed_pc=0x0c034eb4u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c034f5cu,2);
goto P_0c034eb6;
P_0c034eb6: /* original 7440, guest PC 0x0c034eb6 */
if(!s->budget--) { s->failed_pc=0x0c034eb6u; return 0; }
r[4]+=0x00000040u;
goto P_0c034eb8;
P_0c034eb8: /* original 7810, guest PC 0x0c034eb8 */
if(!s->budget--) { s->failed_pc=0x0c034eb8u; return 0; }
r[8]+=0x00000010u;
goto P_0c034eba;
P_0c034eba: /* original bca1, guest PC 0x0c034eba */
if(!s->budget--) { s->failed_pc=0x0c034ebau; return 0; }
target=0x0c034800u; r[16]=code_base|0x0c034ebeu;
r[4]+=r[3];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c034ebeu) { target=s->pc; goto dispatch; }
goto P_0c034ebe;
P_0c034ebc: /* original 343c, guest PC 0x0c034ebc */
if(!s->budget--) { s->failed_pc=0x0c034ebcu; return 0; }
r[4]+=r[3];
goto P_0c034ebe;
P_0c034ebe: /* original 2802, guest PC 0x0c034ebe */
if(!s->budget--) { s->failed_pc=0x0c034ebeu; return 0; }
write(ram,r[8],r[0],4);
goto P_0c034ec0;
P_0c034ec0: /* original 64e2, guest PC 0x0c034ec0 */
if(!s->budget--) { s->failed_pc=0x0c034ec0u; return 0; }
tmp=read(ram,r[14],4);
r[4]=tmp;
goto P_0c034ec2;
P_0c034ec2: /* original 934c, guest PC 0x0c034ec2 */
if(!s->budget--) { s->failed_pc=0x0c034ec2u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c034f5eu,2);
goto P_0c034ec4;
P_0c034ec4: /* original 7440, guest PC 0x0c034ec4 */
if(!s->budget--) { s->failed_pc=0x0c034ec4u; return 0; }
r[4]+=0x00000040u;
goto P_0c034ec6;
P_0c034ec6: /* original bc9b, guest PC 0x0c034ec6 */
if(!s->budget--) { s->failed_pc=0x0c034ec6u; return 0; }
target=0x0c034800u; r[16]=code_base|0x0c034ecau;
r[4]+=r[3];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c034ecau) { target=s->pc; goto dispatch; }
goto P_0c034eca;
P_0c034ec8: /* original 343c, guest PC 0x0c034ec8 */
if(!s->budget--) { s->failed_pc=0x0c034ec8u; return 0; }
r[4]+=r[3];
goto P_0c034eca;
P_0c034eca: /* original 64e2, guest PC 0x0c034eca */
if(!s->budget--) { s->failed_pc=0x0c034ecau; return 0; }
tmp=read(ram,r[14],4);
r[4]=tmp;
goto P_0c034ecc;
P_0c034ecc: /* original 6c03, guest PC 0x0c034ecc */
if(!s->budget--) { s->failed_pc=0x0c034eccu; return 0; }
r[12]=r[0];
goto P_0c034ece;
P_0c034ece: /* original 9344, guest PC 0x0c034ece */
if(!s->budget--) { s->failed_pc=0x0c034eceu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c034f5au,2);
goto P_0c034ed0;
P_0c034ed0: /* original 9246, guest PC 0x0c034ed0 */
if(!s->budget--) { s->failed_pc=0x0c034ed0u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c034f60u,2);
goto P_0c034ed2;
P_0c034ed2: /* original 7440, guest PC 0x0c034ed2 */
if(!s->budget--) { s->failed_pc=0x0c034ed2u; return 0; }
r[4]+=0x00000040u;
goto P_0c034ed4;
P_0c034ed4: /* original 3c3c, guest PC 0x0c034ed4 */
if(!s->budget--) { s->failed_pc=0x0c034ed4u; return 0; }
r[12]+=r[3];
goto P_0c034ed6;
P_0c034ed6: /* original bc93, guest PC 0x0c034ed6 */
if(!s->budget--) { s->failed_pc=0x0c034ed6u; return 0; }
target=0x0c034800u; r[16]=code_base|0x0c034edau;
r[4]+=r[2];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c034edau) { target=s->pc; goto dispatch; }
goto P_0c034eda;
P_0c034ed8: /* original 342c, guest PC 0x0c034ed8 */
if(!s->budget--) { s->failed_pc=0x0c034ed8u; return 0; }
r[4]+=r[2];
goto P_0c034eda;
P_0c034eda: /* original 63e2, guest PC 0x0c034eda */
if(!s->budget--) { s->failed_pc=0x0c034edau; return 0; }
tmp=read(ram,r[14],4);
r[3]=tmp;
goto P_0c034edc;
P_0c034edc: /* original 6703, guest PC 0x0c034edc */
if(!s->budget--) { s->failed_pc=0x0c034edcu; return 0; }
r[7]=r[0];
goto P_0c034ede;
P_0c034ede: /* original 65c3, guest PC 0x0c034ede */
if(!s->budget--) { s->failed_pc=0x0c034edeu; return 0; }
r[5]=r[12];
goto P_0c034ee0;
P_0c034ee0: /* original 5236, guest PC 0x0c034ee0 */
if(!s->budget--) { s->failed_pc=0x0c034ee0u; return 0; }
r[2]=read(ram,r[3]+24,4);
goto P_0c034ee2;
P_0c034ee2: /* original 12d2, guest PC 0x0c034ee2 */
if(!s->budget--) { s->failed_pc=0x0c034ee2u; return 0; }
write(ram,r[2]+8,r[13],4);
goto P_0c034ee4;
P_0c034ee4: /* original 66e2, guest PC 0x0c034ee4 */
if(!s->budget--) { s->failed_pc=0x0c034ee4u; return 0; }
tmp=read(ram,r[14],4);
r[6]=tmp;
goto P_0c034ee6;
P_0c034ee6: /* original 64e2, guest PC 0x0c034ee6 */
if(!s->budget--) { s->failed_pc=0x0c034ee6u; return 0; }
tmp=read(ram,r[14],4);
r[4]=tmp;
goto P_0c034ee8;
P_0c034ee8: /* original d31f, guest PC 0x0c034ee8 */
if(!s->budget--) { s->failed_pc=0x0c034ee8u; return 0; }
r[3]=read(ram,0x0c034f68u,4);
goto P_0c034eea;
P_0c034eea: /* original 5666, guest PC 0x0c034eea */
if(!s->budget--) { s->failed_pc=0x0c034eeau; return 0; }
r[6]=read(ram,r[6]+24,4);
goto P_0c034eec;
P_0c034eec: /* original 430b, guest PC 0x0c034eec */
if(!s->budget--) { s->failed_pc=0x0c034eecu; return 0; }
target=r[3];
r[16]=code_base|0x0c034ef0u;
r[4]+=0x00000040u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c034ef0u) { target=s->pc; goto dispatch; }
goto P_0c034ef0;
P_0c034eee: /* original 7440, guest PC 0x0c034eee */
if(!s->budget--) { s->failed_pc=0x0c034eeeu; return 0; }
r[4]+=0x00000040u;
goto P_0c034ef0;
P_0c034ef0: /* original 88f4, guest PC 0x0c034ef0 */
if(!s->budget--) { s->failed_pc=0x0c034ef0u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xfffffff4u)!=0);
goto P_0c034ef2;
P_0c034ef2: /* original 8f02, guest PC 0x0c034ef2 */
if(!s->budget--) { s->failed_pc=0x0c034ef2u; return 0; }
cond=r[17]&1u;
r[4]=r[0];
if(!cond) { goto P_0c034efa; }
goto P_0c034ef6;
P_0c034ef4: /* original 6403, guest PC 0x0c034ef4 */
if(!s->budget--) { s->failed_pc=0x0c034ef4u; return 0; }
r[4]=r[0];
goto P_0c034ef6;
P_0c034ef6: /* original a00e, guest PC 0x0c034ef6 */
if(!s->budget--) { s->failed_pc=0x0c034ef6u; return 0; }
r[0]=r[4];
goto P_0c034f16;
P_0c034ef8: /* original 6043, guest PC 0x0c034ef8 */
if(!s->budget--) { s->failed_pc=0x0c034ef8u; return 0; }
r[0]=r[4];
goto P_0c034efa;
P_0c034efa: /* original 2448, guest PC 0x0c034efa */
if(!s->budget--) { s->failed_pc=0x0c034efau; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c034efc;
P_0c034efc: /* original 8901, guest PC 0x0c034efc */
if(!s->budget--) { s->failed_pc=0x0c034efcu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c034f02; }
goto P_0c034efe;
P_0c034efe: /* original a00a, guest PC 0x0c034efe */
if(!s->budget--) { s->failed_pc=0x0c034efeu; return 0; }
r[0]=0xfffffffcu;
goto P_0c034f16;
P_0c034f00: /* original e0fc, guest PC 0x0c034f00 */
if(!s->budget--) { s->failed_pc=0x0c034f00u; return 0; }
r[0]=0xfffffffcu;
goto P_0c034f02;
P_0c034f02: /* original 64e2, guest PC 0x0c034f02 */
if(!s->budget--) { s->failed_pc=0x0c034f02u; return 0; }
tmp=read(ram,r[14],4);
r[4]=tmp;
goto P_0c034f04;
P_0c034f04: /* original 5346, guest PC 0x0c034f04 */
if(!s->budget--) { s->failed_pc=0x0c034f04u; return 0; }
r[3]=read(ram,r[4]+24,4);
goto P_0c034f06;
P_0c034f06: /* original 6232, guest PC 0x0c034f06 */
if(!s->budget--) { s->failed_pc=0x0c034f06u; return 0; }
tmp=read(ram,r[3],4);
r[2]=tmp;
goto P_0c034f08;
P_0c034f08: /* original 2228, guest PC 0x0c034f08 */
if(!s->budget--) { s->failed_pc=0x0c034f08u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c034f0a;
P_0c034f0a: /* original 8b01, guest PC 0x0c034f0a */
if(!s->budget--) { s->failed_pc=0x0c034f0au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c034f10; }
goto P_0c034f0c;
P_0c034f0c: /* original a003, guest PC 0x0c034f0c */
if(!s->budget--) { s->failed_pc=0x0c034f0cu; return 0; }
r[0]=0xfffffffbu;
goto P_0c034f16;
P_0c034f0e: /* original e0fb, guest PC 0x0c034f0e */
if(!s->budget--) { s->failed_pc=0x0c034f0eu; return 0; }
r[0]=0xfffffffbu;
goto P_0c034f10;
P_0c034f10: /* original e301, guest PC 0x0c034f10 */
if(!s->budget--) { s->failed_pc=0x0c034f10u; return 0; }
r[3]=0x00000001u;
goto P_0c034f12;
P_0c034f12: /* original e000, guest PC 0x0c034f12 */
if(!s->budget--) { s->failed_pc=0x0c034f12u; return 0; }
r[0]=0x00000000u;
goto P_0c034f14;
P_0c034f14: /* original 1438, guest PC 0x0c034f14 */
if(!s->budget--) { s->failed_pc=0x0c034f14u; return 0; }
write(ram,r[4]+32,r[3],4);
goto P_0c034f16;
P_0c034f16: /* original 7f0c, guest PC 0x0c034f16 */
if(!s->budget--) { s->failed_pc=0x0c034f16u; return 0; }
r[15]+=0x0000000cu;
goto P_0c034f18;
P_0c034f18: /* original 4f26, guest PC 0x0c034f18 */
if(!s->budget--) { s->failed_pc=0x0c034f18u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c034f1a;
P_0c034f1a: /* original 68f6, guest PC 0x0c034f1a */
if(!s->budget--) { s->failed_pc=0x0c034f1au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c034f1c;
P_0c034f1c: /* original 6bf6, guest PC 0x0c034f1c */
if(!s->budget--) { s->failed_pc=0x0c034f1cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c034f1e;
P_0c034f1e: /* original 6cf6, guest PC 0x0c034f1e */
if(!s->budget--) { s->failed_pc=0x0c034f1eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c034f20;
P_0c034f20: /* original 6df6, guest PC 0x0c034f20 */
if(!s->budget--) { s->failed_pc=0x0c034f20u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c034f22;
P_0c034f22: /* original 000b, guest PC 0x0c034f22 */
if(!s->budget--) { s->failed_pc=0x0c034f22u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c034f24: /* original 6ef6, guest PC 0x0c034f24 */
if(!s->budget--) { s->failed_pc=0x0c034f24u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c034f26u,s,ram);
P_0c0367ac: /* original 4f22, guest PC 0x0c0367ac */
if(!s->budget--) { s->failed_pc=0x0c0367acu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0367ae;
P_0c0367ae: /* original 7ffc, guest PC 0x0c0367ae */
if(!s->budget--) { s->failed_pc=0x0c0367aeu; return 0; }
r[15]+=0xfffffffcu;
goto P_0c0367b0;
P_0c0367b0: /* original 2f52, guest PC 0x0c0367b0 */
if(!s->budget--) { s->failed_pc=0x0c0367b0u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0367b2;
P_0c0367b2: /* original bfef, guest PC 0x0c0367b2 */
if(!s->budget--) { s->failed_pc=0x0c0367b2u; return 0; }
target=0x0c036794u; r[16]=code_base|0x0c0367b6u;
r[4]=r[5];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0367b6u) { target=s->pc; goto dispatch; }
goto P_0c0367b6;
P_0c0367b4: /* original 6453, guest PC 0x0c0367b4 */
if(!s->budget--) { s->failed_pc=0x0c0367b4u; return 0; }
r[4]=r[5];
goto P_0c0367b6;
P_0c0367b6: /* original db6d, guest PC 0x0c0367b6 */
if(!s->budget--) { s->failed_pc=0x0c0367b6u; return 0; }
r[11]=read(ram,0x0c03696cu,4);
goto P_0c0367b8;
P_0c0367b8: /* original 65d3, guest PC 0x0c0367b8 */
if(!s->budget--) { s->failed_pc=0x0c0367b8u; return 0; }
r[5]=r[13];
goto P_0c0367ba;
P_0c0367ba: /* original 6c03, guest PC 0x0c0367ba */
if(!s->budget--) { s->failed_pc=0x0c0367bau; return 0; }
r[12]=r[0];
goto P_0c0367bc;
P_0c0367bc: /* original 4b0b, guest PC 0x0c0367bc */
if(!s->budget--) { s->failed_pc=0x0c0367bcu; return 0; }
target=r[11];
r[16]=code_base|0x0c0367c0u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0367c0u) { target=s->pc; goto dispatch; }
goto P_0c0367c0;
P_0c0367be: /* original 64e3, guest PC 0x0c0367be */
if(!s->budget--) { s->failed_pc=0x0c0367beu; return 0; }
r[4]=r[14];
goto P_0c0367c0;
P_0c0367c0: /* original 62c2, guest PC 0x0c0367c0 */
if(!s->budget--) { s->failed_pc=0x0c0367c0u; return 0; }
tmp=read(ram,r[12],4);
r[2]=tmp;
goto P_0c0367c2;
P_0c0367c2: /* original da6b, guest PC 0x0c0367c2 */
if(!s->budget--) { s->failed_pc=0x0c0367c2u; return 0; }
r[10]=read(ram,0x0c036970u,4);
goto P_0c0367c4;
P_0c0367c4: /* original 2f26, guest PC 0x0c0367c4 */
if(!s->budget--) { s->failed_pc=0x0c0367c4u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0367c6;
P_0c0367c6: /* original d36b, guest PC 0x0c0367c6 */
if(!s->budget--) { s->failed_pc=0x0c0367c6u; return 0; }
r[3]=read(ram,0x0c036974u,4);
goto P_0c0367c8;
P_0c0367c8: /* original 4a0b, guest PC 0x0c0367c8 */
if(!s->budget--) { s->failed_pc=0x0c0367c8u; return 0; }
target=r[10];
r[16]=code_base|0x0c0367ccu;
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0367ccu) { target=s->pc; goto dispatch; }
goto P_0c0367cc;
P_0c0367ca: /* original 2f36, guest PC 0x0c0367ca */
if(!s->budget--) { s->failed_pc=0x0c0367cau; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0367cc;
P_0c0367cc: /* original 65d3, guest PC 0x0c0367cc */
if(!s->budget--) { s->failed_pc=0x0c0367ccu; return 0; }
r[5]=r[13];
goto P_0c0367ce;
P_0c0367ce: /* original 7501, guest PC 0x0c0367ce */
if(!s->budget--) { s->failed_pc=0x0c0367ceu; return 0; }
r[5]+=0x00000001u;
goto P_0c0367d0;
P_0c0367d0: /* original 4b0b, guest PC 0x0c0367d0 */
if(!s->budget--) { s->failed_pc=0x0c0367d0u; return 0; }
target=r[11];
r[16]=code_base|0x0c0367d4u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0367d4u) { target=s->pc; goto dispatch; }
goto P_0c0367d4;
P_0c0367d2: /* original 64e3, guest PC 0x0c0367d2 */
if(!s->budget--) { s->failed_pc=0x0c0367d2u; return 0; }
r[4]=r[14];
goto P_0c0367d4;
P_0c0367d4: /* original 52c1, guest PC 0x0c0367d4 */
if(!s->budget--) { s->failed_pc=0x0c0367d4u; return 0; }
r[2]=read(ram,r[12]+4,4);
goto P_0c0367d6;
P_0c0367d6: /* original 2f26, guest PC 0x0c0367d6 */
if(!s->budget--) { s->failed_pc=0x0c0367d6u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0367d8;
P_0c0367d8: /* original d367, guest PC 0x0c0367d8 */
if(!s->budget--) { s->failed_pc=0x0c0367d8u; return 0; }
r[3]=read(ram,0x0c036978u,4);
goto P_0c0367da;
P_0c0367da: /* original 4a0b, guest PC 0x0c0367da */
if(!s->budget--) { s->failed_pc=0x0c0367dau; return 0; }
target=r[10];
r[16]=code_base|0x0c0367deu;
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0367deu) { target=s->pc; goto dispatch; }
goto P_0c0367de;
P_0c0367dc: /* original 2f36, guest PC 0x0c0367dc */
if(!s->budget--) { s->failed_pc=0x0c0367dcu; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0367de;
P_0c0367de: /* original 65d3, guest PC 0x0c0367de */
if(!s->budget--) { s->failed_pc=0x0c0367deu; return 0; }
r[5]=r[13];
goto P_0c0367e0;
P_0c0367e0: /* original 7502, guest PC 0x0c0367e0 */
if(!s->budget--) { s->failed_pc=0x0c0367e0u; return 0; }
r[5]+=0x00000002u;
goto P_0c0367e2;
P_0c0367e2: /* original 4b0b, guest PC 0x0c0367e2 */
if(!s->budget--) { s->failed_pc=0x0c0367e2u; return 0; }
target=r[11];
r[16]=code_base|0x0c0367e6u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0367e6u) { target=s->pc; goto dispatch; }
goto P_0c0367e6;
P_0c0367e4: /* original 64e3, guest PC 0x0c0367e4 */
if(!s->budget--) { s->failed_pc=0x0c0367e4u; return 0; }
r[4]=r[14];
goto P_0c0367e6;
P_0c0367e6: /* original 52c2, guest PC 0x0c0367e6 */
if(!s->budget--) { s->failed_pc=0x0c0367e6u; return 0; }
r[2]=read(ram,r[12]+8,4);
goto P_0c0367e8;
P_0c0367e8: /* original 2f26, guest PC 0x0c0367e8 */
if(!s->budget--) { s->failed_pc=0x0c0367e8u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0367ea;
P_0c0367ea: /* original d364, guest PC 0x0c0367ea */
if(!s->budget--) { s->failed_pc=0x0c0367eau; return 0; }
r[3]=read(ram,0x0c03697cu,4);
goto P_0c0367ec;
P_0c0367ec: /* original 4a0b, guest PC 0x0c0367ec */
if(!s->budget--) { s->failed_pc=0x0c0367ecu; return 0; }
target=r[10];
r[16]=code_base|0x0c0367f0u;
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0367f0u) { target=s->pc; goto dispatch; }
goto P_0c0367f0;
P_0c0367ee: /* original 2f36, guest PC 0x0c0367ee */
if(!s->budget--) { s->failed_pc=0x0c0367eeu; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0367f0;
P_0c0367f0: /* original 65d3, guest PC 0x0c0367f0 */
if(!s->budget--) { s->failed_pc=0x0c0367f0u; return 0; }
r[5]=r[13];
goto P_0c0367f2;
P_0c0367f2: /* original 7503, guest PC 0x0c0367f2 */
if(!s->budget--) { s->failed_pc=0x0c0367f2u; return 0; }
r[5]+=0x00000003u;
goto P_0c0367f4;
P_0c0367f4: /* original 4b0b, guest PC 0x0c0367f4 */
if(!s->budget--) { s->failed_pc=0x0c0367f4u; return 0; }
target=r[11];
r[16]=code_base|0x0c0367f8u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0367f8u) { target=s->pc; goto dispatch; }
goto P_0c0367f8;
P_0c0367f6: /* original 64e3, guest PC 0x0c0367f6 */
if(!s->budget--) { s->failed_pc=0x0c0367f6u; return 0; }
r[4]=r[14];
goto P_0c0367f8;
P_0c0367f8: /* original 52c3, guest PC 0x0c0367f8 */
if(!s->budget--) { s->failed_pc=0x0c0367f8u; return 0; }
r[2]=read(ram,r[12]+12,4);
goto P_0c0367fa;
P_0c0367fa: /* original 2f26, guest PC 0x0c0367fa */
if(!s->budget--) { s->failed_pc=0x0c0367fau; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0367fc;
P_0c0367fc: /* original d360, guest PC 0x0c0367fc */
if(!s->budget--) { s->failed_pc=0x0c0367fcu; return 0; }
r[3]=read(ram,0x0c036980u,4);
goto P_0c0367fe;
P_0c0367fe: /* original 4a0b, guest PC 0x0c0367fe */
if(!s->budget--) { s->failed_pc=0x0c0367feu; return 0; }
target=r[10];
r[16]=code_base|0x0c036802u;
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c036802u) { target=s->pc; goto dispatch; }
goto P_0c036802;
P_0c036800: /* original 2f36, guest PC 0x0c036800 */
if(!s->budget--) { s->failed_pc=0x0c036800u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c036802;
P_0c036802: /* original 65d3, guest PC 0x0c036802 */
if(!s->budget--) { s->failed_pc=0x0c036802u; return 0; }
r[5]=r[13];
goto P_0c036804;
P_0c036804: /* original 7504, guest PC 0x0c036804 */
if(!s->budget--) { s->failed_pc=0x0c036804u; return 0; }
r[5]+=0x00000004u;
goto P_0c036806;
P_0c036806: /* original 4b0b, guest PC 0x0c036806 */
if(!s->budget--) { s->failed_pc=0x0c036806u; return 0; }
target=r[11];
r[16]=code_base|0x0c03680au;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c03680au) { target=s->pc; goto dispatch; }
goto P_0c03680a;
P_0c036808: /* original 64e3, guest PC 0x0c036808 */
if(!s->budget--) { s->failed_pc=0x0c036808u; return 0; }
r[4]=r[14];
goto P_0c03680a;
P_0c03680a: /* original 52c4, guest PC 0x0c03680a */
if(!s->budget--) { s->failed_pc=0x0c03680au; return 0; }
r[2]=read(ram,r[12]+16,4);
goto P_0c03680c;
P_0c03680c: /* original 2f26, guest PC 0x0c03680c */
if(!s->budget--) { s->failed_pc=0x0c03680cu; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03680e;
P_0c03680e: /* original d35d, guest PC 0x0c03680e */
if(!s->budget--) { s->failed_pc=0x0c03680eu; return 0; }
r[3]=read(ram,0x0c036984u,4);
goto P_0c036810;
P_0c036810: /* original 4a0b, guest PC 0x0c036810 */
if(!s->budget--) { s->failed_pc=0x0c036810u; return 0; }
target=r[10];
r[16]=code_base|0x0c036814u;
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c036814u) { target=s->pc; goto dispatch; }
goto P_0c036814;
P_0c036812: /* original 2f36, guest PC 0x0c036812 */
if(!s->budget--) { s->failed_pc=0x0c036812u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c036814;
P_0c036814: /* original 65d3, guest PC 0x0c036814 */
if(!s->budget--) { s->failed_pc=0x0c036814u; return 0; }
r[5]=r[13];
goto P_0c036816;
P_0c036816: /* original 7505, guest PC 0x0c036816 */
if(!s->budget--) { s->failed_pc=0x0c036816u; return 0; }
r[5]+=0x00000005u;
goto P_0c036818;
P_0c036818: /* original 4b0b, guest PC 0x0c036818 */
if(!s->budget--) { s->failed_pc=0x0c036818u; return 0; }
target=r[11];
r[16]=code_base|0x0c03681cu;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c03681cu) { target=s->pc; goto dispatch; }
goto P_0c03681c;
P_0c03681a: /* original 64e3, guest PC 0x0c03681a */
if(!s->budget--) { s->failed_pc=0x0c03681au; return 0; }
r[4]=r[14];
goto P_0c03681c;
P_0c03681c: /* original 52c5, guest PC 0x0c03681c */
if(!s->budget--) { s->failed_pc=0x0c03681cu; return 0; }
r[2]=read(ram,r[12]+20,4);
goto P_0c03681e;
P_0c03681e: /* original 2f26, guest PC 0x0c03681e */
if(!s->budget--) { s->failed_pc=0x0c03681eu; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c036820;
P_0c036820: /* original d359, guest PC 0x0c036820 */
if(!s->budget--) { s->failed_pc=0x0c036820u; return 0; }
r[3]=read(ram,0x0c036988u,4);
goto P_0c036822;
P_0c036822: /* original 4a0b, guest PC 0x0c036822 */
if(!s->budget--) { s->failed_pc=0x0c036822u; return 0; }
target=r[10];
r[16]=code_base|0x0c036826u;
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c036826u) { target=s->pc; goto dispatch; }
goto P_0c036826;
P_0c036824: /* original 2f36, guest PC 0x0c036824 */
if(!s->budget--) { s->failed_pc=0x0c036824u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c036826;
P_0c036826: /* original 65d3, guest PC 0x0c036826 */
if(!s->budget--) { s->failed_pc=0x0c036826u; return 0; }
r[5]=r[13];
goto P_0c036828;
P_0c036828: /* original 7506, guest PC 0x0c036828 */
if(!s->budget--) { s->failed_pc=0x0c036828u; return 0; }
r[5]+=0x00000006u;
goto P_0c03682a;
P_0c03682a: /* original 4b0b, guest PC 0x0c03682a */
if(!s->budget--) { s->failed_pc=0x0c03682au; return 0; }
target=r[11];
r[16]=code_base|0x0c03682eu;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c03682eu) { target=s->pc; goto dispatch; }
goto P_0c03682e;
P_0c03682c: /* original 64e3, guest PC 0x0c03682c */
if(!s->budget--) { s->failed_pc=0x0c03682cu; return 0; }
r[4]=r[14];
goto P_0c03682e;
P_0c03682e: /* original 85cc, guest PC 0x0c03682e */
if(!s->budget--) { s->failed_pc=0x0c03682eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[12]+24,2);
goto P_0c036830;
P_0c036830: /* original 600d, guest PC 0x0c036830 */
if(!s->budget--) { s->failed_pc=0x0c036830u; return 0; }
r[0]=r[0]&65535u;
goto P_0c036832;
P_0c036832: /* original 2f06, guest PC 0x0c036832 */
if(!s->budget--) { s->failed_pc=0x0c036832u; return 0; }
tmp=r[0]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c036834;
P_0c036834: /* original d355, guest PC 0x0c036834 */
if(!s->budget--) { s->failed_pc=0x0c036834u; return 0; }
r[3]=read(ram,0x0c03698cu,4);
goto P_0c036836;
P_0c036836: /* original 4a0b, guest PC 0x0c036836 */
if(!s->budget--) { s->failed_pc=0x0c036836u; return 0; }
target=r[10];
r[16]=code_base|0x0c03683au;
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c03683au) { target=s->pc; goto dispatch; }
goto P_0c03683a;
P_0c036838: /* original 2f36, guest PC 0x0c036838 */
if(!s->budget--) { s->failed_pc=0x0c036838u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03683a;
P_0c03683a: /* original 65d3, guest PC 0x0c03683a */
if(!s->budget--) { s->failed_pc=0x0c03683au; return 0; }
r[5]=r[13];
goto P_0c03683c;
P_0c03683c: /* original 7507, guest PC 0x0c03683c */
if(!s->budget--) { s->failed_pc=0x0c03683cu; return 0; }
r[5]+=0x00000007u;
goto P_0c03683e;
P_0c03683e: /* original 4b0b, guest PC 0x0c03683e */
if(!s->budget--) { s->failed_pc=0x0c03683eu; return 0; }
target=r[11];
r[16]=code_base|0x0c036842u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c036842u) { target=s->pc; goto dispatch; }
goto P_0c036842;
P_0c036840: /* original 64e3, guest PC 0x0c036840 */
if(!s->budget--) { s->failed_pc=0x0c036840u; return 0; }
r[4]=r[14];
goto P_0c036842;
P_0c036842: /* original 85cd, guest PC 0x0c036842 */
if(!s->budget--) { s->failed_pc=0x0c036842u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[12]+26,2);
goto P_0c036844;
P_0c036844: /* original 600d, guest PC 0x0c036844 */
if(!s->budget--) { s->failed_pc=0x0c036844u; return 0; }
r[0]=r[0]&65535u;
goto P_0c036846;
P_0c036846: /* original 2f06, guest PC 0x0c036846 */
if(!s->budget--) { s->failed_pc=0x0c036846u; return 0; }
tmp=r[0]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c036848;
P_0c036848: /* original d351, guest PC 0x0c036848 */
if(!s->budget--) { s->failed_pc=0x0c036848u; return 0; }
r[3]=read(ram,0x0c036990u,4);
goto P_0c03684a;
P_0c03684a: /* original 4a0b, guest PC 0x0c03684a */
if(!s->budget--) { s->failed_pc=0x0c03684au; return 0; }
target=r[10];
r[16]=code_base|0x0c03684eu;
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c03684eu) { target=s->pc; goto dispatch; }
goto P_0c03684e;
P_0c03684c: /* original 2f36, guest PC 0x0c03684c */
if(!s->budget--) { s->failed_pc=0x0c03684cu; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03684e;
P_0c03684e: /* original 65d3, guest PC 0x0c03684e */
if(!s->budget--) { s->failed_pc=0x0c03684eu; return 0; }
r[5]=r[13];
goto P_0c036850;
P_0c036850: /* original 7508, guest PC 0x0c036850 */
if(!s->budget--) { s->failed_pc=0x0c036850u; return 0; }
r[5]+=0x00000008u;
goto P_0c036852;
P_0c036852: /* original 4b0b, guest PC 0x0c036852 */
if(!s->budget--) { s->failed_pc=0x0c036852u; return 0; }
target=r[11];
r[16]=code_base|0x0c036856u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c036856u) { target=s->pc; goto dispatch; }
goto P_0c036856;
P_0c036854: /* original 64e3, guest PC 0x0c036854 */
if(!s->budget--) { s->failed_pc=0x0c036854u; return 0; }
r[4]=r[14];
goto P_0c036856;
P_0c036856: /* original 85ce, guest PC 0x0c036856 */
if(!s->budget--) { s->failed_pc=0x0c036856u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[12]+28,2);
goto P_0c036858;
P_0c036858: /* original 2f06, guest PC 0x0c036858 */
if(!s->budget--) { s->failed_pc=0x0c036858u; return 0; }
tmp=r[0]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03685a;
P_0c03685a: /* original d34e, guest PC 0x0c03685a */
if(!s->budget--) { s->failed_pc=0x0c03685au; return 0; }
r[3]=read(ram,0x0c036994u,4);
goto P_0c03685c;
P_0c03685c: /* original 4a0b, guest PC 0x0c03685c */
if(!s->budget--) { s->failed_pc=0x0c03685cu; return 0; }
target=r[10];
r[16]=code_base|0x0c036860u;
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c036860u) { target=s->pc; goto dispatch; }
goto P_0c036860;
P_0c03685e: /* original 2f36, guest PC 0x0c03685e */
if(!s->budget--) { s->failed_pc=0x0c03685eu; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c036860;
P_0c036860: /* original 65d3, guest PC 0x0c036860 */
if(!s->budget--) { s->failed_pc=0x0c036860u; return 0; }
r[5]=r[13];
goto P_0c036862;
P_0c036862: /* original 7509, guest PC 0x0c036862 */
if(!s->budget--) { s->failed_pc=0x0c036862u; return 0; }
r[5]+=0x00000009u;
goto P_0c036864;
P_0c036864: /* original 4b0b, guest PC 0x0c036864 */
if(!s->budget--) { s->failed_pc=0x0c036864u; return 0; }
target=r[11];
r[16]=code_base|0x0c036868u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c036868u) { target=s->pc; goto dispatch; }
goto P_0c036868;
P_0c036866: /* original 64e3, guest PC 0x0c036866 */
if(!s->budget--) { s->failed_pc=0x0c036866u; return 0; }
r[4]=r[14];
goto P_0c036868;
P_0c036868: /* original 85cf, guest PC 0x0c036868 */
if(!s->budget--) { s->failed_pc=0x0c036868u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[12]+30,2);
goto P_0c03686a;
P_0c03686a: /* original 2f06, guest PC 0x0c03686a */
if(!s->budget--) { s->failed_pc=0x0c03686au; return 0; }
tmp=r[0]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03686c;
P_0c03686c: /* original d34a, guest PC 0x0c03686c */
if(!s->budget--) { s->failed_pc=0x0c03686cu; return 0; }
r[3]=read(ram,0x0c036998u,4);
goto P_0c03686e;
P_0c03686e: /* original 4a0b, guest PC 0x0c03686e */
if(!s->budget--) { s->failed_pc=0x0c03686eu; return 0; }
target=r[10];
r[16]=code_base|0x0c036872u;
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c036872u) { target=s->pc; goto dispatch; }
goto P_0c036872;
P_0c036870: /* original 2f36, guest PC 0x0c036870 */
if(!s->budget--) { s->failed_pc=0x0c036870u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c036872;
P_0c036872: /* original 65d3, guest PC 0x0c036872 */
if(!s->budget--) { s->failed_pc=0x0c036872u; return 0; }
r[5]=r[13];
goto P_0c036874;
P_0c036874: /* original 750a, guest PC 0x0c036874 */
if(!s->budget--) { s->failed_pc=0x0c036874u; return 0; }
r[5]+=0x0000000au;
goto P_0c036876;
P_0c036876: /* original 4b0b, guest PC 0x0c036876 */
if(!s->budget--) { s->failed_pc=0x0c036876u; return 0; }
target=r[11];
r[16]=code_base|0x0c03687au;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c03687au) { target=s->pc; goto dispatch; }
goto P_0c03687a;
P_0c036878: /* original 64e3, guest PC 0x0c036878 */
if(!s->budget--) { s->failed_pc=0x0c036878u; return 0; }
r[4]=r[14];
goto P_0c03687a;
P_0c03687a: /* original e020, guest PC 0x0c03687a */
if(!s->budget--) { s->failed_pc=0x0c03687au; return 0; }
r[0]=0x00000020u;
goto P_0c03687c;
P_0c03687c: /* original 02cd, guest PC 0x0c03687c */
if(!s->budget--) { s->failed_pc=0x0c03687cu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[12]+r[0],2);
goto P_0c03687e;
P_0c03687e: /* original 2f26, guest PC 0x0c03687e */
if(!s->budget--) { s->failed_pc=0x0c03687eu; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c036880;
P_0c036880: /* original d346, guest PC 0x0c036880 */
if(!s->budget--) { s->failed_pc=0x0c036880u; return 0; }
r[3]=read(ram,0x0c03699cu,4);
goto P_0c036882;
P_0c036882: /* original 4a0b, guest PC 0x0c036882 */
if(!s->budget--) { s->failed_pc=0x0c036882u; return 0; }
target=r[10];
r[16]=code_base|0x0c036886u;
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c036886u) { target=s->pc; goto dispatch; }
goto P_0c036886;
P_0c036884: /* original 2f36, guest PC 0x0c036884 */
if(!s->budget--) { s->failed_pc=0x0c036884u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c036886;
P_0c036886: /* original 65d3, guest PC 0x0c036886 */
if(!s->budget--) { s->failed_pc=0x0c036886u; return 0; }
r[5]=r[13];
goto P_0c036888;
P_0c036888: /* original 750b, guest PC 0x0c036888 */
if(!s->budget--) { s->failed_pc=0x0c036888u; return 0; }
r[5]+=0x0000000bu;
goto P_0c03688a;
P_0c03688a: /* original 4b0b, guest PC 0x0c03688a */
if(!s->budget--) { s->failed_pc=0x0c03688au; return 0; }
target=r[11];
r[16]=code_base|0x0c03688eu;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c03688eu) { target=s->pc; goto dispatch; }
goto P_0c03688e;
P_0c03688c: /* original 64e3, guest PC 0x0c03688c */
if(!s->budget--) { s->failed_pc=0x0c03688cu; return 0; }
r[4]=r[14];
goto P_0c03688e;
P_0c03688e: /* original e022, guest PC 0x0c03688e */
if(!s->budget--) { s->failed_pc=0x0c03688eu; return 0; }
r[0]=0x00000022u;
goto P_0c036890;
P_0c036890: /* original 02cd, guest PC 0x0c036890 */
if(!s->budget--) { s->failed_pc=0x0c036890u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[12]+r[0],2);
goto P_0c036892;
P_0c036892: /* original 2f26, guest PC 0x0c036892 */
if(!s->budget--) { s->failed_pc=0x0c036892u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c036894;
P_0c036894: /* original d342, guest PC 0x0c036894 */
if(!s->budget--) { s->failed_pc=0x0c036894u; return 0; }
r[3]=read(ram,0x0c0369a0u,4);
goto P_0c036896;
P_0c036896: /* original 4a0b, guest PC 0x0c036896 */
if(!s->budget--) { s->failed_pc=0x0c036896u; return 0; }
target=r[10];
r[16]=code_base|0x0c03689au;
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c03689au) { target=s->pc; goto dispatch; }
goto P_0c03689a;
P_0c036898: /* original 2f36, guest PC 0x0c036898 */
if(!s->budget--) { s->failed_pc=0x0c036898u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03689a;
P_0c03689a: /* original 7f64, guest PC 0x0c03689a */
if(!s->budget--) { s->failed_pc=0x0c03689au; return 0; }
r[15]+=0x00000064u;
goto P_0c03689c;
P_0c03689c: /* original 4f26, guest PC 0x0c03689c */
if(!s->budget--) { s->failed_pc=0x0c03689cu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c03689e;
P_0c03689e: /* original 6af6, guest PC 0x0c03689e */
if(!s->budget--) { s->failed_pc=0x0c03689eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0368a0;
P_0c0368a0: /* original 6bf6, guest PC 0x0c0368a0 */
if(!s->budget--) { s->failed_pc=0x0c0368a0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0368a2;
P_0c0368a2: /* original 6cf6, guest PC 0x0c0368a2 */
if(!s->budget--) { s->failed_pc=0x0c0368a2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0368a4;
P_0c0368a4: /* original 6df6, guest PC 0x0c0368a4 */
if(!s->budget--) { s->failed_pc=0x0c0368a4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0368a6;
P_0c0368a6: /* original 000b, guest PC 0x0c0368a6 */
if(!s->budget--) { s->failed_pc=0x0c0368a6u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0368a8: /* original 6ef6, guest PC 0x0c0368a8 */
if(!s->budget--) { s->failed_pc=0x0c0368a8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0368aau,s,ram);
P_0c0381f0: /* original 4f22, guest PC 0x0c0381f0 */
if(!s->budget--) { s->failed_pc=0x0c0381f0u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0381f2;
P_0c0381f2: /* original d990, guest PC 0x0c0381f2 */
if(!s->budget--) { s->failed_pc=0x0c0381f2u; return 0; }
r[9]=read(ram,0x0c038434u,4);
goto P_0c0381f4;
P_0c0381f4: /* original d490, guest PC 0x0c0381f4 */
if(!s->budget--) { s->failed_pc=0x0c0381f4u; return 0; }
r[4]=read(ram,0x0c038438u,4);
goto P_0c0381f6;
P_0c0381f6: /* original 7fc0, guest PC 0x0c0381f6 */
if(!s->budget--) { s->failed_pc=0x0c0381f6u; return 0; }
r[15]+=0xffffffc0u;
goto P_0c0381f8;
P_0c0381f8: /* original 490b, guest PC 0x0c0381f8 */
if(!s->budget--) { s->failed_pc=0x0c0381f8u; return 0; }
target=r[9];
r[16]=code_base|0x0c0381fcu;
r[13]=r[5];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0381fcu) { target=s->pc; goto dispatch; }
goto P_0c0381fc;
P_0c0381fa: /* original 6d53, guest PC 0x0c0381fa */
if(!s->budget--) { s->failed_pc=0x0c0381fau; return 0; }
r[13]=r[5];
goto P_0c0381fc;
P_0c0381fc: /* original d490, guest PC 0x0c0381fc */
if(!s->budget--) { s->failed_pc=0x0c0381fcu; return 0; }
r[4]=read(ram,0x0c038440u,4);
goto P_0c0381fe;
P_0c0381fe: /* original d88f, guest PC 0x0c0381fe */
if(!s->budget--) { s->failed_pc=0x0c0381feu; return 0; }
r[8]=read(ram,0x0c03843cu,4);
goto P_0c038200;
P_0c038200: /* original 480b, guest PC 0x0c038200 */
if(!s->budget--) { s->failed_pc=0x0c038200u; return 0; }
target=r[8];
r[16]=code_base|0x0c038204u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c038204u) { target=s->pc; goto dispatch; }
goto P_0c038204;
P_0c038202: /* original 0009, guest PC 0x0c038202 */
if(!s->budget--) { s->failed_pc=0x0c038202u; return 0; }
goto P_0c038204;
P_0c038204: /* original e004, guest PC 0x0c038204 */
if(!s->budget--) { s->failed_pc=0x0c038204u; return 0; }
r[0]=0x00000004u;
goto P_0c038206;
P_0c038206: /* original dc8f, guest PC 0x0c038206 */
if(!s->budget--) { s->failed_pc=0x0c038206u; return 0; }
r[12]=read(ram,0x0c038444u,4);
goto P_0c038208;
P_0c038208: /* original 2fc2, guest PC 0x0c038208 */
if(!s->budget--) { s->failed_pc=0x0c038208u; return 0; }
write(ram,r[15],r[12],4);
goto P_0c03820a;
P_0c03820a: /* original f3e8, guest PC 0x0c03820a */
if(!s->budget--) { s->failed_pc=0x0c03820au; return 0; }
vf3_matrix_load(s,ram,3,r[14]);
goto P_0c03820c;
P_0c03820c: /* original ff37, guest PC 0x0c03820c */
if(!s->budget--) { s->failed_pc=0x0c03820cu; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c03820e;
P_0c03820e: /* original e004, guest PC 0x0c03820e */
if(!s->budget--) { s->failed_pc=0x0c03820eu; return 0; }
r[0]=0x00000004u;
goto P_0c038210;
P_0c038210: /* original f3e6, guest PC 0x0c038210 */
if(!s->budget--) { s->failed_pc=0x0c038210u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c038212;
P_0c038212: /* original e008, guest PC 0x0c038212 */
if(!s->budget--) { s->failed_pc=0x0c038212u; return 0; }
r[0]=0x00000008u;
goto P_0c038214;
P_0c038214: /* original ff37, guest PC 0x0c038214 */
if(!s->budget--) { s->failed_pc=0x0c038214u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c038216;
P_0c038216: /* original e008, guest PC 0x0c038216 */
if(!s->budget--) { s->failed_pc=0x0c038216u; return 0; }
r[0]=0x00000008u;
goto P_0c038218;
P_0c038218: /* original f3e6, guest PC 0x0c038218 */
if(!s->budget--) { s->failed_pc=0x0c038218u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c03821a;
P_0c03821a: /* original e00c, guest PC 0x0c03821a */
if(!s->budget--) { s->failed_pc=0x0c03821au; return 0; }
r[0]=0x0000000cu;
goto P_0c03821c;
P_0c03821c: /* original ff37, guest PC 0x0c03821c */
if(!s->budget--) { s->failed_pc=0x0c03821cu; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c03821e;
P_0c03821e: /* original e00c, guest PC 0x0c03821e */
if(!s->budget--) { s->failed_pc=0x0c03821eu; return 0; }
r[0]=0x0000000cu;
goto P_0c038220;
P_0c038220: /* original f3e6, guest PC 0x0c038220 */
if(!s->budget--) { s->failed_pc=0x0c038220u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c038222;
P_0c038222: /* original e010, guest PC 0x0c038222 */
if(!s->budget--) { s->failed_pc=0x0c038222u; return 0; }
r[0]=0x00000010u;
goto P_0c038224;
P_0c038224: /* original ff37, guest PC 0x0c038224 */
if(!s->budget--) { s->failed_pc=0x0c038224u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c038226;
P_0c038226: /* original e010, guest PC 0x0c038226 */
if(!s->budget--) { s->failed_pc=0x0c038226u; return 0; }
r[0]=0x00000010u;
goto P_0c038228;
P_0c038228: /* original f3e6, guest PC 0x0c038228 */
if(!s->budget--) { s->failed_pc=0x0c038228u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c03822a;
P_0c03822a: /* original e014, guest PC 0x0c03822a */
if(!s->budget--) { s->failed_pc=0x0c03822au; return 0; }
r[0]=0x00000014u;
goto P_0c03822c;
P_0c03822c: /* original ff37, guest PC 0x0c03822c */
if(!s->budget--) { s->failed_pc=0x0c03822cu; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c03822e;
P_0c03822e: /* original e014, guest PC 0x0c03822e */
if(!s->budget--) { s->failed_pc=0x0c03822eu; return 0; }
r[0]=0x00000014u;
goto P_0c038230;
P_0c038230: /* original f3e6, guest PC 0x0c038230 */
if(!s->budget--) { s->failed_pc=0x0c038230u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c038232;
P_0c038232: /* original e018, guest PC 0x0c038232 */
if(!s->budget--) { s->failed_pc=0x0c038232u; return 0; }
r[0]=0x00000018u;
goto P_0c038234;
P_0c038234: /* original ff37, guest PC 0x0c038234 */
if(!s->budget--) { s->failed_pc=0x0c038234u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c038236;
P_0c038236: /* original e018, guest PC 0x0c038236 */
if(!s->budget--) { s->failed_pc=0x0c038236u; return 0; }
r[0]=0x00000018u;
goto P_0c038238;
P_0c038238: /* original f3e6, guest PC 0x0c038238 */
if(!s->budget--) { s->failed_pc=0x0c038238u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c03823a;
P_0c03823a: /* original e01c, guest PC 0x0c03823a */
if(!s->budget--) { s->failed_pc=0x0c03823au; return 0; }
r[0]=0x0000001cu;
goto P_0c03823c;
P_0c03823c: /* original ff37, guest PC 0x0c03823c */
if(!s->budget--) { s->failed_pc=0x0c03823cu; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c03823e;
P_0c03823e: /* original e01c, guest PC 0x0c03823e */
if(!s->budget--) { s->failed_pc=0x0c03823eu; return 0; }
r[0]=0x0000001cu;
goto P_0c038240;
P_0c038240: /* original f3e6, guest PC 0x0c038240 */
if(!s->budget--) { s->failed_pc=0x0c038240u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c038242;
P_0c038242: /* original e020, guest PC 0x0c038242 */
if(!s->budget--) { s->failed_pc=0x0c038242u; return 0; }
r[0]=0x00000020u;
goto P_0c038244;
P_0c038244: /* original ff37, guest PC 0x0c038244 */
if(!s->budget--) { s->failed_pc=0x0c038244u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c038246;
P_0c038246: /* original e020, guest PC 0x0c038246 */
if(!s->budget--) { s->failed_pc=0x0c038246u; return 0; }
r[0]=0x00000020u;
goto P_0c038248;
P_0c038248: /* original f3e6, guest PC 0x0c038248 */
if(!s->budget--) { s->failed_pc=0x0c038248u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c03824a;
P_0c03824a: /* original e024, guest PC 0x0c03824a */
if(!s->budget--) { s->failed_pc=0x0c03824au; return 0; }
r[0]=0x00000024u;
goto P_0c03824c;
P_0c03824c: /* original e611, guest PC 0x0c03824c */
if(!s->budget--) { s->failed_pc=0x0c03824cu; return 0; }
r[6]=0x00000011u;
goto P_0c03824e;
P_0c03824e: /* original ff37, guest PC 0x0c03824e */
if(!s->budget--) { s->failed_pc=0x0c03824eu; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c038250;
P_0c038250: /* original e740, guest PC 0x0c038250 */
if(!s->budget--) { s->failed_pc=0x0c038250u; return 0; }
r[7]=0x00000040u;
goto P_0c038252;
P_0c038252: /* original da7d, guest PC 0x0c038252 */
if(!s->budget--) { s->failed_pc=0x0c038252u; return 0; }
r[10]=read(ram,0x0c038448u,4);
goto P_0c038254;
P_0c038254: /* original d47a, guest PC 0x0c038254 */
if(!s->budget--) { s->failed_pc=0x0c038254u; return 0; }
r[4]=read(ram,0x0c038440u,4);
goto P_0c038256;
P_0c038256: /* original 4a0b, guest PC 0x0c038256 */
if(!s->budget--) { s->failed_pc=0x0c038256u; return 0; }
target=r[10];
r[16]=code_base|0x0c03825au;
r[5]=r[15];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c03825au) { target=s->pc; goto dispatch; }
goto P_0c03825a;
P_0c038258: /* original 65f3, guest PC 0x0c038258 */
if(!s->budget--) { s->failed_pc=0x0c038258u; return 0; }
r[5]=r[15];
goto P_0c03825a;
P_0c03825a: /* original d47c, guest PC 0x0c03825a */
if(!s->budget--) { s->failed_pc=0x0c03825au; return 0; }
r[4]=read(ram,0x0c03844cu,4);
goto P_0c03825c;
P_0c03825c: /* original 7e24, guest PC 0x0c03825c */
if(!s->budget--) { s->failed_pc=0x0c03825cu; return 0; }
r[14]+=0x00000024u;
goto P_0c03825e;
P_0c03825e: /* original 490b, guest PC 0x0c03825e */
if(!s->budget--) { s->failed_pc=0x0c03825eu; return 0; }
target=r[9];
r[16]=code_base|0x0c038262u;
r[13]+=0xffffffffu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c038262u) { target=s->pc; goto dispatch; }
goto P_0c038262;
P_0c038260: /* original 7dff, guest PC 0x0c038260 */
if(!s->budget--) { s->failed_pc=0x0c038260u; return 0; }
r[13]+=0xffffffffu;
goto P_0c038262;
P_0c038262: /* original d477, guest PC 0x0c038262 */
if(!s->budget--) { s->failed_pc=0x0c038262u; return 0; }
r[4]=read(ram,0x0c038440u,4);
goto P_0c038264;
P_0c038264: /* original 480b, guest PC 0x0c038264 */
if(!s->budget--) { s->failed_pc=0x0c038264u; return 0; }
target=r[8];
r[16]=code_base|0x0c038268u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c038268u) { target=s->pc; goto dispatch; }
goto P_0c038268;
P_0c038266: /* original 0009, guest PC 0x0c038266 */
if(!s->budget--) { s->failed_pc=0x0c038266u; return 0; }
goto P_0c038268;
P_0c038268: /* original eb01, guest PC 0x0c038268 */
if(!s->budget--) { s->failed_pc=0x0c038268u; return 0; }
r[11]=0x00000001u;
goto P_0c03826a;
P_0c03826a: /* original 3db7, guest PC 0x0c03826a */
if(!s->budget--) { s->failed_pc=0x0c03826au; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[13]>(int32_t)r[11])!=0);
goto P_0c03826c;
P_0c03826c: /* original 8b2c, guest PC 0x0c03826c */
if(!s->budget--) { s->failed_pc=0x0c03826cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0382c8; }
goto P_0c03826e;
P_0c03826e: /* original e004, guest PC 0x0c03826e */
if(!s->budget--) { s->failed_pc=0x0c03826eu; return 0; }
r[0]=0x00000004u;
goto P_0c038270;
P_0c038270: /* original 2fc2, guest PC 0x0c038270 */
if(!s->budget--) { s->failed_pc=0x0c038270u; return 0; }
write(ram,r[15],r[12],4);
goto P_0c038272;
P_0c038272: /* original f3e8, guest PC 0x0c038272 */
if(!s->budget--) { s->failed_pc=0x0c038272u; return 0; }
vf3_matrix_load(s,ram,3,r[14]);
goto P_0c038274;
P_0c038274: /* original ff37, guest PC 0x0c038274 */
if(!s->budget--) { s->failed_pc=0x0c038274u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c038276;
P_0c038276: /* original e004, guest PC 0x0c038276 */
if(!s->budget--) { s->failed_pc=0x0c038276u; return 0; }
r[0]=0x00000004u;
goto P_0c038278;
P_0c038278: /* original f3e6, guest PC 0x0c038278 */
if(!s->budget--) { s->failed_pc=0x0c038278u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c03827a;
P_0c03827a: /* original e008, guest PC 0x0c03827a */
if(!s->budget--) { s->failed_pc=0x0c03827au; return 0; }
r[0]=0x00000008u;
goto P_0c03827c;
P_0c03827c: /* original ff37, guest PC 0x0c03827c */
if(!s->budget--) { s->failed_pc=0x0c03827cu; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c03827e;
P_0c03827e: /* original e008, guest PC 0x0c03827e */
if(!s->budget--) { s->failed_pc=0x0c03827eu; return 0; }
r[0]=0x00000008u;
goto P_0c038280;
P_0c038280: /* original f3e6, guest PC 0x0c038280 */
if(!s->budget--) { s->failed_pc=0x0c038280u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c038282;
P_0c038282: /* original e00c, guest PC 0x0c038282 */
if(!s->budget--) { s->failed_pc=0x0c038282u; return 0; }
r[0]=0x0000000cu;
goto P_0c038284;
P_0c038284: /* original ff37, guest PC 0x0c038284 */
if(!s->budget--) { s->failed_pc=0x0c038284u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c038286;
P_0c038286: /* original e00c, guest PC 0x0c038286 */
if(!s->budget--) { s->failed_pc=0x0c038286u; return 0; }
r[0]=0x0000000cu;
goto P_0c038288;
P_0c038288: /* original f3e6, guest PC 0x0c038288 */
if(!s->budget--) { s->failed_pc=0x0c038288u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c03828a;
P_0c03828a: /* original e010, guest PC 0x0c03828a */
if(!s->budget--) { s->failed_pc=0x0c03828au; return 0; }
r[0]=0x00000010u;
goto P_0c03828c;
P_0c03828c: /* original ff37, guest PC 0x0c03828c */
if(!s->budget--) { s->failed_pc=0x0c03828cu; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c03828e;
P_0c03828e: /* original e010, guest PC 0x0c03828e */
if(!s->budget--) { s->failed_pc=0x0c03828eu; return 0; }
r[0]=0x00000010u;
goto P_0c038290;
P_0c038290: /* original f3e6, guest PC 0x0c038290 */
if(!s->budget--) { s->failed_pc=0x0c038290u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c038292;
P_0c038292: /* original e014, guest PC 0x0c038292 */
if(!s->budget--) { s->failed_pc=0x0c038292u; return 0; }
r[0]=0x00000014u;
goto P_0c038294;
P_0c038294: /* original ff37, guest PC 0x0c038294 */
if(!s->budget--) { s->failed_pc=0x0c038294u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c038296;
P_0c038296: /* original e014, guest PC 0x0c038296 */
if(!s->budget--) { s->failed_pc=0x0c038296u; return 0; }
r[0]=0x00000014u;
goto P_0c038298;
P_0c038298: /* original f3e6, guest PC 0x0c038298 */
if(!s->budget--) { s->failed_pc=0x0c038298u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c03829a;
P_0c03829a: /* original e018, guest PC 0x0c03829a */
if(!s->budget--) { s->failed_pc=0x0c03829au; return 0; }
r[0]=0x00000018u;
goto P_0c03829c;
P_0c03829c: /* original ff37, guest PC 0x0c03829c */
if(!s->budget--) { s->failed_pc=0x0c03829cu; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c03829e;
P_0c03829e: /* original e018, guest PC 0x0c03829e */
if(!s->budget--) { s->failed_pc=0x0c03829eu; return 0; }
r[0]=0x00000018u;
goto P_0c0382a0;
P_0c0382a0: /* original f3e6, guest PC 0x0c0382a0 */
if(!s->budget--) { s->failed_pc=0x0c0382a0u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c0382a2;
P_0c0382a2: /* original e01c, guest PC 0x0c0382a2 */
if(!s->budget--) { s->failed_pc=0x0c0382a2u; return 0; }
r[0]=0x0000001cu;
goto P_0c0382a4;
P_0c0382a4: /* original ff37, guest PC 0x0c0382a4 */
if(!s->budget--) { s->failed_pc=0x0c0382a4u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0382a6;
P_0c0382a6: /* original e01c, guest PC 0x0c0382a6 */
if(!s->budget--) { s->failed_pc=0x0c0382a6u; return 0; }
r[0]=0x0000001cu;
goto P_0c0382a8;
P_0c0382a8: /* original f3e6, guest PC 0x0c0382a8 */
if(!s->budget--) { s->failed_pc=0x0c0382a8u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c0382aa;
P_0c0382aa: /* original e020, guest PC 0x0c0382aa */
if(!s->budget--) { s->failed_pc=0x0c0382aau; return 0; }
r[0]=0x00000020u;
goto P_0c0382ac;
P_0c0382ac: /* original ff37, guest PC 0x0c0382ac */
if(!s->budget--) { s->failed_pc=0x0c0382acu; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0382ae;
P_0c0382ae: /* original e020, guest PC 0x0c0382ae */
if(!s->budget--) { s->failed_pc=0x0c0382aeu; return 0; }
r[0]=0x00000020u;
goto P_0c0382b0;
P_0c0382b0: /* original f3e6, guest PC 0x0c0382b0 */
if(!s->budget--) { s->failed_pc=0x0c0382b0u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c0382b2;
P_0c0382b2: /* original e024, guest PC 0x0c0382b2 */
if(!s->budget--) { s->failed_pc=0x0c0382b2u; return 0; }
r[0]=0x00000024u;
goto P_0c0382b4;
P_0c0382b4: /* original e611, guest PC 0x0c0382b4 */
if(!s->budget--) { s->failed_pc=0x0c0382b4u; return 0; }
r[6]=0x00000011u;
goto P_0c0382b6;
P_0c0382b6: /* original ff37, guest PC 0x0c0382b6 */
if(!s->budget--) { s->failed_pc=0x0c0382b6u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0382b8;
P_0c0382b8: /* original e740, guest PC 0x0c0382b8 */
if(!s->budget--) { s->failed_pc=0x0c0382b8u; return 0; }
r[7]=0x00000040u;
goto P_0c0382ba;
P_0c0382ba: /* original d461, guest PC 0x0c0382ba */
if(!s->budget--) { s->failed_pc=0x0c0382bau; return 0; }
r[4]=read(ram,0x0c038440u,4);
goto P_0c0382bc;
P_0c0382bc: /* original 4a0b, guest PC 0x0c0382bc */
if(!s->budget--) { s->failed_pc=0x0c0382bcu; return 0; }
target=r[10];
r[16]=code_base|0x0c0382c0u;
r[5]=r[15];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0382c0u) { target=s->pc; goto dispatch; }
goto P_0c0382c0;
P_0c0382be: /* original 65f3, guest PC 0x0c0382be */
if(!s->budget--) { s->failed_pc=0x0c0382beu; return 0; }
r[5]=r[15];
goto P_0c0382c0;
P_0c0382c0: /* original 7dff, guest PC 0x0c0382c0 */
if(!s->budget--) { s->failed_pc=0x0c0382c0u; return 0; }
r[13]+=0xffffffffu;
goto P_0c0382c2;
P_0c0382c2: /* original 3db7, guest PC 0x0c0382c2 */
if(!s->budget--) { s->failed_pc=0x0c0382c2u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[13]>(int32_t)r[11])!=0);
goto P_0c0382c4;
P_0c0382c4: /* original 8dd3, guest PC 0x0c0382c4 */
if(!s->budget--) { s->failed_pc=0x0c0382c4u; return 0; }
cond=r[17]&1u;
r[14]+=0x00000024u;
if(cond) { goto P_0c03826e; }
goto P_0c0382c8;
P_0c0382c6: /* original 7e24, guest PC 0x0c0382c6 */
if(!s->budget--) { s->failed_pc=0x0c0382c6u; return 0; }
r[14]+=0x00000024u;
goto P_0c0382c8;
P_0c0382c8: /* original d461, guest PC 0x0c0382c8 */
if(!s->budget--) { s->failed_pc=0x0c0382c8u; return 0; }
r[4]=read(ram,0x0c038450u,4);
goto P_0c0382ca;
P_0c0382ca: /* original 490b, guest PC 0x0c0382ca */
if(!s->budget--) { s->failed_pc=0x0c0382cau; return 0; }
target=r[9];
r[16]=code_base|0x0c0382ceu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0382ceu) { target=s->pc; goto dispatch; }
goto P_0c0382ce;
P_0c0382cc: /* original 0009, guest PC 0x0c0382cc */
if(!s->budget--) { s->failed_pc=0x0c0382ccu; return 0; }
goto P_0c0382ce;
P_0c0382ce: /* original d45c, guest PC 0x0c0382ce */
if(!s->budget--) { s->failed_pc=0x0c0382ceu; return 0; }
r[4]=read(ram,0x0c038440u,4);
goto P_0c0382d0;
P_0c0382d0: /* original 480b, guest PC 0x0c0382d0 */
if(!s->budget--) { s->failed_pc=0x0c0382d0u; return 0; }
target=r[8];
r[16]=code_base|0x0c0382d4u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0382d4u) { target=s->pc; goto dispatch; }
goto P_0c0382d4;
P_0c0382d2: /* original 0009, guest PC 0x0c0382d2 */
if(!s->budget--) { s->failed_pc=0x0c0382d2u; return 0; }
goto P_0c0382d4;
P_0c0382d4: /* original e004, guest PC 0x0c0382d4 */
if(!s->budget--) { s->failed_pc=0x0c0382d4u; return 0; }
r[0]=0x00000004u;
goto P_0c0382d6;
P_0c0382d6: /* original 2fc2, guest PC 0x0c0382d6 */
if(!s->budget--) { s->failed_pc=0x0c0382d6u; return 0; }
write(ram,r[15],r[12],4);
goto P_0c0382d8;
P_0c0382d8: /* original f3e8, guest PC 0x0c0382d8 */
if(!s->budget--) { s->failed_pc=0x0c0382d8u; return 0; }
vf3_matrix_load(s,ram,3,r[14]);
goto P_0c0382da;
P_0c0382da: /* original ff37, guest PC 0x0c0382da */
if(!s->budget--) { s->failed_pc=0x0c0382dau; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0382dc;
P_0c0382dc: /* original e004, guest PC 0x0c0382dc */
if(!s->budget--) { s->failed_pc=0x0c0382dcu; return 0; }
r[0]=0x00000004u;
goto P_0c0382de;
P_0c0382de: /* original f3e6, guest PC 0x0c0382de */
if(!s->budget--) { s->failed_pc=0x0c0382deu; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c0382e0;
P_0c0382e0: /* original e008, guest PC 0x0c0382e0 */
if(!s->budget--) { s->failed_pc=0x0c0382e0u; return 0; }
r[0]=0x00000008u;
goto P_0c0382e2;
P_0c0382e2: /* original ff37, guest PC 0x0c0382e2 */
if(!s->budget--) { s->failed_pc=0x0c0382e2u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0382e4;
P_0c0382e4: /* original e008, guest PC 0x0c0382e4 */
if(!s->budget--) { s->failed_pc=0x0c0382e4u; return 0; }
r[0]=0x00000008u;
goto P_0c0382e6;
P_0c0382e6: /* original f3e6, guest PC 0x0c0382e6 */
if(!s->budget--) { s->failed_pc=0x0c0382e6u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c0382e8;
P_0c0382e8: /* original e00c, guest PC 0x0c0382e8 */
if(!s->budget--) { s->failed_pc=0x0c0382e8u; return 0; }
r[0]=0x0000000cu;
goto P_0c0382ea;
P_0c0382ea: /* original ff37, guest PC 0x0c0382ea */
if(!s->budget--) { s->failed_pc=0x0c0382eau; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0382ec;
P_0c0382ec: /* original e00c, guest PC 0x0c0382ec */
if(!s->budget--) { s->failed_pc=0x0c0382ecu; return 0; }
r[0]=0x0000000cu;
goto P_0c0382ee;
P_0c0382ee: /* original f3e6, guest PC 0x0c0382ee */
if(!s->budget--) { s->failed_pc=0x0c0382eeu; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c0382f0;
P_0c0382f0: /* original e010, guest PC 0x0c0382f0 */
if(!s->budget--) { s->failed_pc=0x0c0382f0u; return 0; }
r[0]=0x00000010u;
goto P_0c0382f2;
P_0c0382f2: /* original ff37, guest PC 0x0c0382f2 */
if(!s->budget--) { s->failed_pc=0x0c0382f2u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0382f4;
P_0c0382f4: /* original e010, guest PC 0x0c0382f4 */
if(!s->budget--) { s->failed_pc=0x0c0382f4u; return 0; }
r[0]=0x00000010u;
goto P_0c0382f6;
P_0c0382f6: /* original f3e6, guest PC 0x0c0382f6 */
if(!s->budget--) { s->failed_pc=0x0c0382f6u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c0382f8;
P_0c0382f8: /* original e014, guest PC 0x0c0382f8 */
if(!s->budget--) { s->failed_pc=0x0c0382f8u; return 0; }
r[0]=0x00000014u;
goto P_0c0382fa;
P_0c0382fa: /* original ff37, guest PC 0x0c0382fa */
if(!s->budget--) { s->failed_pc=0x0c0382fau; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0382fc;
P_0c0382fc: /* original e014, guest PC 0x0c0382fc */
if(!s->budget--) { s->failed_pc=0x0c0382fcu; return 0; }
r[0]=0x00000014u;
goto P_0c0382fe;
P_0c0382fe: /* original f3e6, guest PC 0x0c0382fe */
if(!s->budget--) { s->failed_pc=0x0c0382feu; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c038300;
P_0c038300: /* original e018, guest PC 0x0c038300 */
if(!s->budget--) { s->failed_pc=0x0c038300u; return 0; }
r[0]=0x00000018u;
goto P_0c038302;
P_0c038302: /* original ff37, guest PC 0x0c038302 */
if(!s->budget--) { s->failed_pc=0x0c038302u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c038304;
P_0c038304: /* original e018, guest PC 0x0c038304 */
if(!s->budget--) { s->failed_pc=0x0c038304u; return 0; }
r[0]=0x00000018u;
goto P_0c038306;
P_0c038306: /* original f3e6, guest PC 0x0c038306 */
if(!s->budget--) { s->failed_pc=0x0c038306u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c038308;
P_0c038308: /* original e01c, guest PC 0x0c038308 */
if(!s->budget--) { s->failed_pc=0x0c038308u; return 0; }
r[0]=0x0000001cu;
goto P_0c03830a;
P_0c03830a: /* original ff37, guest PC 0x0c03830a */
if(!s->budget--) { s->failed_pc=0x0c03830au; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c03830c;
P_0c03830c: /* original e01c, guest PC 0x0c03830c */
if(!s->budget--) { s->failed_pc=0x0c03830cu; return 0; }
r[0]=0x0000001cu;
goto P_0c03830e;
P_0c03830e: /* original f3e6, guest PC 0x0c03830e */
if(!s->budget--) { s->failed_pc=0x0c03830eu; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c038310;
P_0c038310: /* original e020, guest PC 0x0c038310 */
if(!s->budget--) { s->failed_pc=0x0c038310u; return 0; }
r[0]=0x00000020u;
goto P_0c038312;
P_0c038312: /* original ff37, guest PC 0x0c038312 */
if(!s->budget--) { s->failed_pc=0x0c038312u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c038314;
P_0c038314: /* original e020, guest PC 0x0c038314 */
if(!s->budget--) { s->failed_pc=0x0c038314u; return 0; }
r[0]=0x00000020u;
goto P_0c038316;
P_0c038316: /* original f3e6, guest PC 0x0c038316 */
if(!s->budget--) { s->failed_pc=0x0c038316u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c038318;
P_0c038318: /* original e024, guest PC 0x0c038318 */
if(!s->budget--) { s->failed_pc=0x0c038318u; return 0; }
r[0]=0x00000024u;
goto P_0c03831a;
P_0c03831a: /* original e611, guest PC 0x0c03831a */
if(!s->budget--) { s->failed_pc=0x0c03831au; return 0; }
r[6]=0x00000011u;
goto P_0c03831c;
P_0c03831c: /* original ff37, guest PC 0x0c03831c */
if(!s->budget--) { s->failed_pc=0x0c03831cu; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c03831e;
P_0c03831e: /* original e740, guest PC 0x0c03831e */
if(!s->budget--) { s->failed_pc=0x0c03831eu; return 0; }
r[7]=0x00000040u;
goto P_0c038320;
P_0c038320: /* original d447, guest PC 0x0c038320 */
if(!s->budget--) { s->failed_pc=0x0c038320u; return 0; }
r[4]=read(ram,0x0c038440u,4);
goto P_0c038322;
P_0c038322: /* original 4a0b, guest PC 0x0c038322 */
if(!s->budget--) { s->failed_pc=0x0c038322u; return 0; }
target=r[10];
r[16]=code_base|0x0c038326u;
r[5]=r[15];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c038326u) { target=s->pc; goto dispatch; }
goto P_0c038326;
P_0c038324: /* original 65f3, guest PC 0x0c038324 */
if(!s->budget--) { s->failed_pc=0x0c038324u; return 0; }
r[5]=r[15];
goto P_0c038326;
P_0c038326: /* original 7f40, guest PC 0x0c038326 */
if(!s->budget--) { s->failed_pc=0x0c038326u; return 0; }
r[15]+=0x00000040u;
goto P_0c038328;
P_0c038328: /* original 4f26, guest PC 0x0c038328 */
if(!s->budget--) { s->failed_pc=0x0c038328u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c03832a;
P_0c03832a: /* original 68f6, guest PC 0x0c03832a */
if(!s->budget--) { s->failed_pc=0x0c03832au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c03832c;
P_0c03832c: /* original 69f6, guest PC 0x0c03832c */
if(!s->budget--) { s->failed_pc=0x0c03832cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c03832e;
P_0c03832e: /* original 6af6, guest PC 0x0c03832e */
if(!s->budget--) { s->failed_pc=0x0c03832eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c038330;
P_0c038330: /* original 6bf6, guest PC 0x0c038330 */
if(!s->budget--) { s->failed_pc=0x0c038330u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c038332;
P_0c038332: /* original 6cf6, guest PC 0x0c038332 */
if(!s->budget--) { s->failed_pc=0x0c038332u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c038334;
P_0c038334: /* original 6df6, guest PC 0x0c038334 */
if(!s->budget--) { s->failed_pc=0x0c038334u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c038336;
P_0c038336: /* original 000b, guest PC 0x0c038336 */
if(!s->budget--) { s->failed_pc=0x0c038336u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c038338: /* original 6ef6, guest PC 0x0c038338 */
if(!s->budget--) { s->failed_pc=0x0c038338u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c03833au,s,ram);
P_0c04454c: /* original 4f22, guest PC 0x0c04454c */
if(!s->budget--) { s->failed_pc=0x0c04454cu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c04454e;
P_0c04454e: /* original 013d, guest PC 0x0c04454e */
if(!s->budget--) { s->failed_pc=0x0c04454eu; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,r[3]+r[0],2);
goto P_0c044550;
P_0c044550: /* original 3e1c, guest PC 0x0c044550 */
if(!s->budget--) { s->failed_pc=0x0c044550u; return 0; }
r[14]+=r[1];
goto P_0c044552;
P_0c044552: /* original d13e, guest PC 0x0c044552 */
if(!s->budget--) { s->failed_pc=0x0c044552u; return 0; }
r[1]=read(ram,0x0c04464cu,4);
goto P_0c044554;
P_0c044554: /* original 63e3, guest PC 0x0c044554 */
if(!s->budget--) { s->failed_pc=0x0c044554u; return 0; }
r[3]=r[14];
goto P_0c044556;
P_0c044556: /* original 4e00, guest PC 0x0c044556 */
if(!s->budget--) { s->failed_pc=0x0c044556u; return 0; }
r[17]=(r[17]&~1u)|((r[14]>>31)!=0);
r[14]<<=1;
goto P_0c044558;
P_0c044558: /* original 3e3c, guest PC 0x0c044558 */
if(!s->budget--) { s->failed_pc=0x0c044558u; return 0; }
r[14]+=r[3];
goto P_0c04455a;
P_0c04455a: /* original 4e08, guest PC 0x0c04455a */
if(!s->budget--) { s->failed_pc=0x0c04455au; return 0; }
r[14]<<=2;
goto P_0c04455c;
P_0c04455c: /* original 6eef, guest PC 0x0c04455c */
if(!s->budget--) { s->failed_pc=0x0c04455cu; return 0; }
r[14]=(uint32_t)(int32_t)(int16_t)r[14];
goto P_0c04455e;
P_0c04455e: /* original 3e1c, guest PC 0x0c04455e */
if(!s->budget--) { s->failed_pc=0x0c04455eu; return 0; }
r[14]+=r[1];
goto P_0c044560;
P_0c044560: /* original 1e52, guest PC 0x0c044560 */
if(!s->budget--) { s->failed_pc=0x0c044560u; return 0; }
write(ram,r[14]+8,r[5],4);
goto P_0c044562;
P_0c044562: /* original 65d3, guest PC 0x0c044562 */
if(!s->budget--) { s->failed_pc=0x0c044562u; return 0; }
r[5]=r[13];
goto P_0c044564;
P_0c044564: /* original 1e61, guest PC 0x0c044564 */
if(!s->budget--) { s->failed_pc=0x0c044564u; return 0; }
write(ram,r[14]+4,r[6],4);
goto P_0c044566;
P_0c044566: /* original 4500, guest PC 0x0c044566 */
if(!s->budget--) { s->failed_pc=0x0c044566u; return 0; }
r[17]=(r[17]&~1u)|((r[5]>>31)!=0);
r[5]<<=1;
goto P_0c044568;
P_0c044568: /* original 2ed2, guest PC 0x0c044568 */
if(!s->budget--) { s->failed_pc=0x0c044568u; return 0; }
write(ram,r[14],r[13],4);
goto P_0c04456a;
P_0c04456a: /* original 6322, guest PC 0x0c04456a */
if(!s->budget--) { s->failed_pc=0x0c04456au; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c04456c;
P_0c04456c: /* original d438, guest PC 0x0c04456c */
if(!s->budget--) { s->failed_pc=0x0c04456cu; return 0; }
r[4]=read(ram,0x0c044650u,4);
goto P_0c04456e;
P_0c04456e: /* original 013e, guest PC 0x0c04456e */
if(!s->budget--) { s->failed_pc=0x0c04456eu; return 0; }
r[1]=read(ram,r[3]+r[0],4);
goto P_0c044570;
P_0c044570: /* original d338, guest PC 0x0c044570 */
if(!s->budget--) { s->failed_pc=0x0c044570u; return 0; }
r[3]=read(ram,0x0c044654u,4);
goto P_0c044572;
P_0c044572: /* original 56e1, guest PC 0x0c044572 */
if(!s->budget--) { s->failed_pc=0x0c044572u; return 0; }
r[6]=read(ram,r[14]+4,4);
goto P_0c044574;
P_0c044574: /* original 430b, guest PC 0x0c044574 */
if(!s->budget--) { s->failed_pc=0x0c044574u; return 0; }
target=r[3];
r[16]=code_base|0x0c044578u;
r[5]+=r[1];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c044578u) { target=s->pc; goto dispatch; }
goto P_0c044578;
P_0c044576: /* original 351c, guest PC 0x0c044576 */
if(!s->budget--) { s->failed_pc=0x0c044576u; return 0; }
r[5]+=r[1];
goto P_0c044578;
P_0c044578: /* original 4f26, guest PC 0x0c044578 */
if(!s->budget--) { s->failed_pc=0x0c044578u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c04457a;
P_0c04457a: /* original e000, guest PC 0x0c04457a */
if(!s->budget--) { s->failed_pc=0x0c04457au; return 0; }
r[0]=0x00000000u;
goto P_0c04457c;
P_0c04457c: /* original 6df6, guest PC 0x0c04457c */
if(!s->budget--) { s->failed_pc=0x0c04457cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c04457e;
P_0c04457e: /* original 000b, guest PC 0x0c04457e */
if(!s->budget--) { s->failed_pc=0x0c04457eu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c044580: /* original 6ef6, guest PC 0x0c044580 */
if(!s->budget--) { s->failed_pc=0x0c044580u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c044582u,s,ram);
P_0c059848: /* original 4f22, guest PC 0x0c059848 */
if(!s->budget--) { s->failed_pc=0x0c059848u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c05984a;
P_0c05984a: /* original d32a, guest PC 0x0c05984a */
if(!s->budget--) { s->failed_pc=0x0c05984au; return 0; }
r[3]=read(ram,0x0c0598f4u,4);
goto P_0c05984c;
P_0c05984c: /* original de2a, guest PC 0x0c05984c */
if(!s->budget--) { s->failed_pc=0x0c05984cu; return 0; }
r[14]=read(ram,0x0c0598f8u,4);
goto P_0c05984e;
P_0c05984e: /* original 6432, guest PC 0x0c05984e */
if(!s->budget--) { s->failed_pc=0x0c05984eu; return 0; }
tmp=read(ram,r[3],4);
r[4]=tmp;
goto P_0c059850;
P_0c059850: /* original d22a, guest PC 0x0c059850 */
if(!s->budget--) { s->failed_pc=0x0c059850u; return 0; }
r[2]=read(ram,0x0c0598fcu,4);
goto P_0c059852;
P_0c059852: /* original 6442, guest PC 0x0c059852 */
if(!s->budget--) { s->failed_pc=0x0c059852u; return 0; }
tmp=read(ram,r[4],4);
r[4]=tmp;
goto P_0c059854;
P_0c059854: /* original 6543, guest PC 0x0c059854 */
if(!s->budget--) { s->failed_pc=0x0c059854u; return 0; }
r[5]=r[4];
goto P_0c059856;
P_0c059856: /* original 4529, guest PC 0x0c059856 */
if(!s->budget--) { s->failed_pc=0x0c059856u; return 0; }
r[5]>>=16;
goto P_0c059858;
P_0c059858: /* original 4519, guest PC 0x0c059858 */
if(!s->budget--) { s->failed_pc=0x0c059858u; return 0; }
r[5]>>=8;
goto P_0c05985a;
P_0c05985a: /* original 2252, guest PC 0x0c05985a */
if(!s->budget--) { s->failed_pc=0x0c05985au; return 0; }
write(ram,r[2],r[5],4);
goto P_0c05985c;
P_0c05985c: /* original d128, guest PC 0x0c05985c */
if(!s->budget--) { s->failed_pc=0x0c05985cu; return 0; }
r[1]=read(ram,0x0c059900u,4);
goto P_0c05985e;
P_0c05985e: /* original 2152, guest PC 0x0c05985e */
if(!s->budget--) { s->failed_pc=0x0c05985eu; return 0; }
write(ram,r[1],r[5],4);
goto P_0c059860;
P_0c059860: /* original dd28, guest PC 0x0c059860 */
if(!s->budget--) { s->failed_pc=0x0c059860u; return 0; }
r[13]=read(ram,0x0c059904u,4);
goto P_0c059862;
P_0c059862: /* original ec04, guest PC 0x0c059862 */
if(!s->budget--) { s->failed_pc=0x0c059862u; return 0; }
r[12]=0x00000004u;
goto P_0c059864;
P_0c059864: /* original d328, guest PC 0x0c059864 */
if(!s->budget--) { s->failed_pc=0x0c059864u; return 0; }
r[3]=read(ram,0x0c059908u,4);
goto P_0c059866;
P_0c059866: /* original 2d49, guest PC 0x0c059866 */
if(!s->budget--) { s->failed_pc=0x0c059866u; return 0; }
r[13]&=r[4];
goto P_0c059868;
P_0c059868: /* original db28, guest PC 0x0c059868 */
if(!s->budget--) { s->failed_pc=0x0c059868u; return 0; }
r[11]=read(ram,0x0c05990cu,4);
goto P_0c05986a;
P_0c05986a: /* original 2d3b, guest PC 0x0c05986a */
if(!s->budget--) { s->failed_pc=0x0c05986au; return 0; }
r[13]|=r[3];
goto P_0c05986c;
P_0c05986c: /* original e620, guest PC 0x0c05986c */
if(!s->budget--) { s->failed_pc=0x0c05986cu; return 0; }
r[6]=0x00000020u;
goto P_0c05986e;
P_0c05986e: /* original 65e3, guest PC 0x0c05986e */
if(!s->budget--) { s->failed_pc=0x0c05986eu; return 0; }
r[5]=r[14];
goto P_0c059870;
P_0c059870: /* original 4b0b, guest PC 0x0c059870 */
if(!s->budget--) { s->failed_pc=0x0c059870u; return 0; }
target=r[11];
r[16]=code_base|0x0c059874u;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c059874u) { target=s->pc; goto dispatch; }
goto P_0c059874;
P_0c059872: /* original 64d3, guest PC 0x0c059872 */
if(!s->budget--) { s->failed_pc=0x0c059872u; return 0; }
r[4]=r[13];
goto P_0c059874;
P_0c059874: /* original 0d83, guest PC 0x0c059874 */
if(!s->budget--) { s->failed_pc=0x0c059874u; return 0; }
if((r[13]&0xFC000000u)==0xE0000000u) pref(ram,r[13]);
goto P_0c059876;
P_0c059876: /* original 7d20, guest PC 0x0c059876 */
if(!s->budget--) { s->failed_pc=0x0c059876u; return 0; }
r[13]+=0x00000020u;
goto P_0c059878;
P_0c059878: /* original 4c10, guest PC 0x0c059878 */
if(!s->budget--) { s->failed_pc=0x0c059878u; return 0; }
--r[12];
r[17]=(r[17]&~1u)|((r[12]==0)!=0);
goto P_0c05987a;
P_0c05987a: /* original 8ff7, guest PC 0x0c05987a */
if(!s->budget--) { s->failed_pc=0x0c05987au; return 0; }
cond=r[17]&1u;
r[14]+=0x00000020u;
if(!cond) { goto P_0c05986c; }
goto P_0c05987e;
P_0c05987c: /* original 7e20, guest PC 0x0c05987c */
if(!s->budget--) { s->failed_pc=0x0c05987cu; return 0; }
r[14]+=0x00000020u;
goto P_0c05987e;
P_0c05987e: /* original d21d, guest PC 0x0c05987e */
if(!s->budget--) { s->failed_pc=0x0c05987eu; return 0; }
r[2]=read(ram,0x0c0598f4u,4);
goto P_0c059880;
P_0c059880: /* original 9136, guest PC 0x0c059880 */
if(!s->budget--) { s->failed_pc=0x0c059880u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0598f0u,2);
goto P_0c059882;
P_0c059882: /* original 6322, guest PC 0x0c059882 */
if(!s->budget--) { s->failed_pc=0x0c059882u; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c059884;
P_0c059884: /* original 6032, guest PC 0x0c059884 */
if(!s->budget--) { s->failed_pc=0x0c059884u; return 0; }
tmp=read(ram,r[3],4);
r[0]=tmp;
goto P_0c059886;
P_0c059886: /* original 301c, guest PC 0x0c059886 */
if(!s->budget--) { s->failed_pc=0x0c059886u; return 0; }
r[0]+=r[1];
goto P_0c059888;
P_0c059888: /* original 2302, guest PC 0x0c059888 */
if(!s->budget--) { s->failed_pc=0x0c059888u; return 0; }
write(ram,r[3],r[0],4);
goto P_0c05988a;
P_0c05988a: /* original 4f26, guest PC 0x0c05988a */
if(!s->budget--) { s->failed_pc=0x0c05988au; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c05988c;
P_0c05988c: /* original 6bf6, guest PC 0x0c05988c */
if(!s->budget--) { s->failed_pc=0x0c05988cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c05988e;
P_0c05988e: /* original 6cf6, guest PC 0x0c05988e */
if(!s->budget--) { s->failed_pc=0x0c05988eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c059890;
P_0c059890: /* original 6df6, guest PC 0x0c059890 */
if(!s->budget--) { s->failed_pc=0x0c059890u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c059892;
P_0c059892: /* original 000b, guest PC 0x0c059892 */
if(!s->budget--) { s->failed_pc=0x0c059892u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c059894: /* original 6ef6, guest PC 0x0c059894 */
if(!s->budget--) { s->failed_pc=0x0c059894u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c059896u,s,ram);
P_0c05c280: /* original 2fe6, guest PC 0x0c05c280 */
if(!s->budget--) { s->failed_pc=0x0c05c280u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05c282;
P_0c05c282: /* original 6e43, guest PC 0x0c05c282 */
if(!s->budget--) { s->failed_pc=0x0c05c282u; return 0; }
r[14]=r[4];
goto P_0c05c284;
P_0c05c284: /* original d376, guest PC 0x0c05c284 */
if(!s->budget--) { s->failed_pc=0x0c05c284u; return 0; }
r[3]=read(ram,0x0c05c460u,4);
goto P_0c05c286;
P_0c05c286: /* original 2fd6, guest PC 0x0c05c286 */
if(!s->budget--) { s->failed_pc=0x0c05c286u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05c288;
P_0c05c288: /* original 2fc6, guest PC 0x0c05c288 */
if(!s->budget--) { s->failed_pc=0x0c05c288u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05c28a;
P_0c05c28a: /* original 4f22, guest PC 0x0c05c28a */
if(!s->budget--) { s->failed_pc=0x0c05c28au; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c05c28c;
P_0c05c28c: /* original 7ffc, guest PC 0x0c05c28c */
if(!s->budget--) { s->failed_pc=0x0c05c28cu; return 0; }
r[15]+=0xfffffffcu;
goto P_0c05c28e;
P_0c05c28e: /* original 54e2, guest PC 0x0c05c28e */
if(!s->budget--) { s->failed_pc=0x0c05c28eu; return 0; }
r[4]=read(ram,r[14]+8,4);
goto P_0c05c290;
P_0c05c290: /* original 6542, guest PC 0x0c05c290 */
if(!s->budget--) { s->failed_pc=0x0c05c290u; return 0; }
tmp=read(ram,r[4],4);
r[5]=tmp;
goto P_0c05c292;
P_0c05c292: /* original 5d41, guest PC 0x0c05c292 */
if(!s->budget--) { s->failed_pc=0x0c05c292u; return 0; }
r[13]=read(ram,r[4]+4,4);
goto P_0c05c294;
P_0c05c294: /* original 6453, guest PC 0x0c05c294 */
if(!s->budget--) { s->failed_pc=0x0c05c294u; return 0; }
r[4]=r[5];
goto P_0c05c296;
P_0c05c296: /* original 4408, guest PC 0x0c05c296 */
if(!s->budget--) { s->failed_pc=0x0c05c296u; return 0; }
r[4]<<=2;
goto P_0c05c298;
P_0c05c298: /* original 2f42, guest PC 0x0c05c298 */
if(!s->budget--) { s->failed_pc=0x0c05c298u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c05c29a;
P_0c05c29a: /* original 60e2, guest PC 0x0c05c29a */
if(!s->budget--) { s->failed_pc=0x0c05c29au; return 0; }
tmp=read(ram,r[14],4);
r[0]=tmp;
goto P_0c05c29c;
P_0c05c29c: /* original 55e1, guest PC 0x0c05c29c */
if(!s->budget--) { s->failed_pc=0x0c05c29cu; return 0; }
r[5]=read(ram,r[14]+4,4);
goto P_0c05c29e;
P_0c05c29e: /* original 044e, guest PC 0x0c05c29e */
if(!s->budget--) { s->failed_pc=0x0c05c29eu; return 0; }
r[4]=read(ram,r[4]+r[0],4);
goto P_0c05c2a0;
P_0c05c2a0: /* original 6643, guest PC 0x0c05c2a0 */
if(!s->budget--) { s->failed_pc=0x0c05c2a0u; return 0; }
r[6]=r[4];
goto P_0c05c2a2;
P_0c05c2a2: /* original 4629, guest PC 0x0c05c2a2 */
if(!s->budget--) { s->failed_pc=0x0c05c2a2u; return 0; }
r[6]>>=16;
goto P_0c05c2a4;
P_0c05c2a4: /* original 4619, guest PC 0x0c05c2a4 */
if(!s->budget--) { s->failed_pc=0x0c05c2a4u; return 0; }
r[6]>>=8;
goto P_0c05c2a6;
P_0c05c2a6: /* original 2362, guest PC 0x0c05c2a6 */
if(!s->budget--) { s->failed_pc=0x0c05c2a6u; return 0; }
write(ram,r[3],r[6],4);
goto P_0c05c2a8;
P_0c05c2a8: /* original d26e, guest PC 0x0c05c2a8 */
if(!s->budget--) { s->failed_pc=0x0c05c2a8u; return 0; }
r[2]=read(ram,0x0c05c464u,4);
goto P_0c05c2aa;
P_0c05c2aa: /* original 2262, guest PC 0x0c05c2aa */
if(!s->budget--) { s->failed_pc=0x0c05c2aau; return 0; }
write(ram,r[2],r[6],4);
goto P_0c05c2ac;
P_0c05c2ac: /* original dc6e, guest PC 0x0c05c2ac */
if(!s->budget--) { s->failed_pc=0x0c05c2acu; return 0; }
r[12]=read(ram,0x0c05c468u,4);
goto P_0c05c2ae;
P_0c05c2ae: /* original 66d3, guest PC 0x0c05c2ae */
if(!s->budget--) { s->failed_pc=0x0c05c2aeu; return 0; }
r[6]=r[13];
goto P_0c05c2b0;
P_0c05c2b0: /* original d36f, guest PC 0x0c05c2b0 */
if(!s->budget--) { s->failed_pc=0x0c05c2b0u; return 0; }
r[3]=read(ram,0x0c05c470u,4);
goto P_0c05c2b2;
P_0c05c2b2: /* original 2c49, guest PC 0x0c05c2b2 */
if(!s->budget--) { s->failed_pc=0x0c05c2b2u; return 0; }
r[12]&=r[4];
goto P_0c05c2b4;
P_0c05c2b4: /* original d16d, guest PC 0x0c05c2b4 */
if(!s->budget--) { s->failed_pc=0x0c05c2b4u; return 0; }
r[1]=read(ram,0x0c05c46cu,4);
goto P_0c05c2b6;
P_0c05c2b6: /* original 2c1b, guest PC 0x0c05c2b6 */
if(!s->budget--) { s->failed_pc=0x0c05c2b6u; return 0; }
r[12]|=r[1];
goto P_0c05c2b8;
P_0c05c2b8: /* original 430b, guest PC 0x0c05c2b8 */
if(!s->budget--) { s->failed_pc=0x0c05c2b8u; return 0; }
target=r[3];
r[16]=code_base|0x0c05c2bcu;
r[4]=r[12];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c05c2bcu) { target=s->pc; goto dispatch; }
goto P_0c05c2bc;
P_0c05c2ba: /* original 64c3, guest PC 0x0c05c2ba */
if(!s->budget--) { s->failed_pc=0x0c05c2bau; return 0; }
r[4]=r[12];
goto P_0c05c2bc;
P_0c05c2bc: /* original 0c83, guest PC 0x0c05c2bc */
if(!s->budget--) { s->failed_pc=0x0c05c2bcu; return 0; }
if((r[12]&0xFC000000u)==0xE0000000u) pref(ram,r[12]);
goto P_0c05c2be;
P_0c05c2be: /* original 60d3, guest PC 0x0c05c2be */
if(!s->budget--) { s->failed_pc=0x0c05c2beu; return 0; }
r[0]=r[13];
goto P_0c05c2c0;
P_0c05c2c0: /* original 0009, guest PC 0x0c05c2c0 */
if(!s->budget--) { s->failed_pc=0x0c05c2c0u; return 0; }
goto P_0c05c2c2;
P_0c05c2c2: /* original 8840, guest PC 0x0c05c2c2 */
if(!s->budget--) { s->failed_pc=0x0c05c2c2u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000040u)!=0);
goto P_0c05c2c4;
P_0c05c2c4: /* original 8b01, guest PC 0x0c05c2c4 */
if(!s->budget--) { s->failed_pc=0x0c05c2c4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c05c2ca; }
goto P_0c05c2c6;
P_0c05c2c6: /* original 7c20, guest PC 0x0c05c2c6 */
if(!s->budget--) { s->failed_pc=0x0c05c2c6u; return 0; }
r[12]+=0x00000020u;
goto P_0c05c2c8;
P_0c05c2c8: /* original 0c83, guest PC 0x0c05c2c8 */
if(!s->budget--) { s->failed_pc=0x0c05c2c8u; return 0; }
if((r[12]&0xFC000000u)==0xE0000000u) pref(ram,r[12]);
goto P_0c05c2ca;
P_0c05c2ca: /* original 4d09, guest PC 0x0c05c2ca */
if(!s->budget--) { s->failed_pc=0x0c05c2cau; return 0; }
r[13]>>=2;
goto P_0c05c2cc;
P_0c05c2cc: /* original 63f2, guest PC 0x0c05c2cc */
if(!s->budget--) { s->failed_pc=0x0c05c2ccu; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c05c2ce;
P_0c05c2ce: /* original 4d08, guest PC 0x0c05c2ce */
if(!s->budget--) { s->failed_pc=0x0c05c2ceu; return 0; }
r[13]<<=2;
goto P_0c05c2d0;
P_0c05c2d0: /* original 60e2, guest PC 0x0c05c2d0 */
if(!s->budget--) { s->failed_pc=0x0c05c2d0u; return 0; }
tmp=read(ram,r[14],4);
r[0]=tmp;
goto P_0c05c2d2;
P_0c05c2d2: /* original 023e, guest PC 0x0c05c2d2 */
if(!s->budget--) { s->failed_pc=0x0c05c2d2u; return 0; }
r[2]=read(ram,r[3]+r[0],4);
goto P_0c05c2d4;
P_0c05c2d4: /* original 32dc, guest PC 0x0c05c2d4 */
if(!s->budget--) { s->failed_pc=0x0c05c2d4u; return 0; }
r[2]+=r[13];
goto P_0c05c2d6;
P_0c05c2d6: /* original 0326, guest PC 0x0c05c2d6 */
if(!s->budget--) { s->failed_pc=0x0c05c2d6u; return 0; }
write(ram,r[3]+r[0],r[2],4);
goto P_0c05c2d8;
P_0c05c2d8: /* original e000, guest PC 0x0c05c2d8 */
if(!s->budget--) { s->failed_pc=0x0c05c2d8u; return 0; }
r[0]=0x00000000u;
goto P_0c05c2da;
P_0c05c2da: /* original 7f04, guest PC 0x0c05c2da */
if(!s->budget--) { s->failed_pc=0x0c05c2dau; return 0; }
r[15]+=0x00000004u;
goto P_0c05c2dc;
P_0c05c2dc: /* original 4f26, guest PC 0x0c05c2dc */
if(!s->budget--) { s->failed_pc=0x0c05c2dcu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c05c2de;
P_0c05c2de: /* original 6cf6, guest PC 0x0c05c2de */
if(!s->budget--) { s->failed_pc=0x0c05c2deu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c05c2e0;
P_0c05c2e0: /* original 6df6, guest PC 0x0c05c2e0 */
if(!s->budget--) { s->failed_pc=0x0c05c2e0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c05c2e2;
P_0c05c2e2: /* original 000b, guest PC 0x0c05c2e2 */
if(!s->budget--) { s->failed_pc=0x0c05c2e2u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c05c2e4: /* original 6ef6, guest PC 0x0c05c2e4 */
if(!s->budget--) { s->failed_pc=0x0c05c2e4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c05c2e6;
P_0c05c2e6: /* original 2fe6, guest PC 0x0c05c2e6 */
if(!s->budget--) { s->failed_pc=0x0c05c2e6u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05c2e8;
P_0c05c2e8: /* original 2fd6, guest PC 0x0c05c2e8 */
if(!s->budget--) { s->failed_pc=0x0c05c2e8u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05c2ea;
P_0c05c2ea: /* original 6d43, guest PC 0x0c05c2ea */
if(!s->budget--) { s->failed_pc=0x0c05c2eau; return 0; }
r[13]=r[4];
goto P_0c05c2ec;
P_0c05c2ec: /* original d361, guest PC 0x0c05c2ec */
if(!s->budget--) { s->failed_pc=0x0c05c2ecu; return 0; }
r[3]=read(ram,0x0c05c474u,4);
goto P_0c05c2ee;
P_0c05c2ee: /* original 2fc6, guest PC 0x0c05c2ee */
if(!s->budget--) { s->failed_pc=0x0c05c2eeu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05c2f0;
P_0c05c2f0: /* original 4f22, guest PC 0x0c05c2f0 */
if(!s->budget--) { s->failed_pc=0x0c05c2f0u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c05c2f2;
P_0c05c2f2: /* original 6c73, guest PC 0x0c05c2f2 */
if(!s->budget--) { s->failed_pc=0x0c05c2f2u; return 0; }
r[12]=r[7];
goto P_0c05c2f4;
P_0c05c2f4: /* original d25a, guest PC 0x0c05c2f4 */
if(!s->budget--) { s->failed_pc=0x0c05c2f4u; return 0; }
r[2]=read(ram,0x0c05c460u,4);
goto P_0c05c2f6;
P_0c05c2f6: /* original 7ffc, guest PC 0x0c05c2f6 */
if(!s->budget--) { s->failed_pc=0x0c05c2f6u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c05c2f8;
P_0c05c2f8: /* original 2362, guest PC 0x0c05c2f8 */
if(!s->budget--) { s->failed_pc=0x0c05c2f8u; return 0; }
write(ram,r[3],r[6],4);
goto P_0c05c2fa;
P_0c05c2fa: /* original 54d2, guest PC 0x0c05c2fa */
if(!s->budget--) { s->failed_pc=0x0c05c2fau; return 0; }
r[4]=read(ram,r[13]+8,4);
goto P_0c05c2fc;
P_0c05c2fc: /* original 6442, guest PC 0x0c05c2fc */
if(!s->budget--) { s->failed_pc=0x0c05c2fcu; return 0; }
tmp=read(ram,r[4],4);
r[4]=tmp;
goto P_0c05c2fe;
P_0c05c2fe: /* original 4408, guest PC 0x0c05c2fe */
if(!s->budget--) { s->failed_pc=0x0c05c2feu; return 0; }
r[4]<<=2;
goto P_0c05c300;
P_0c05c300: /* original 2f42, guest PC 0x0c05c300 */
if(!s->budget--) { s->failed_pc=0x0c05c300u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c05c302;
P_0c05c302: /* original 60d2, guest PC 0x0c05c302 */
if(!s->budget--) { s->failed_pc=0x0c05c302u; return 0; }
tmp=read(ram,r[13],4);
r[0]=tmp;
goto P_0c05c304;
P_0c05c304: /* original 044e, guest PC 0x0c05c304 */
if(!s->budget--) { s->failed_pc=0x0c05c304u; return 0; }
r[4]=read(ram,r[4]+r[0],4);
goto P_0c05c306;
P_0c05c306: /* original 6643, guest PC 0x0c05c306 */
if(!s->budget--) { s->failed_pc=0x0c05c306u; return 0; }
r[6]=r[4];
goto P_0c05c308;
P_0c05c308: /* original 4629, guest PC 0x0c05c308 */
if(!s->budget--) { s->failed_pc=0x0c05c308u; return 0; }
r[6]>>=16;
goto P_0c05c30a;
P_0c05c30a: /* original 4619, guest PC 0x0c05c30a */
if(!s->budget--) { s->failed_pc=0x0c05c30au; return 0; }
r[6]>>=8;
goto P_0c05c30c;
P_0c05c30c: /* original 2262, guest PC 0x0c05c30c */
if(!s->budget--) { s->failed_pc=0x0c05c30cu; return 0; }
write(ram,r[2],r[6],4);
goto P_0c05c30e;
P_0c05c30e: /* original d155, guest PC 0x0c05c30e */
if(!s->budget--) { s->failed_pc=0x0c05c30eu; return 0; }
r[1]=read(ram,0x0c05c464u,4);
goto P_0c05c310;
P_0c05c310: /* original 2162, guest PC 0x0c05c310 */
if(!s->budget--) { s->failed_pc=0x0c05c310u; return 0; }
write(ram,r[1],r[6],4);
goto P_0c05c312;
P_0c05c312: /* original 66c3, guest PC 0x0c05c312 */
if(!s->budget--) { s->failed_pc=0x0c05c312u; return 0; }
r[6]=r[12];
goto P_0c05c314;
P_0c05c314: /* original d256, guest PC 0x0c05c314 */
if(!s->budget--) { s->failed_pc=0x0c05c314u; return 0; }
r[2]=read(ram,0x0c05c470u,4);
goto P_0c05c316;
P_0c05c316: /* original de54, guest PC 0x0c05c316 */
if(!s->budget--) { s->failed_pc=0x0c05c316u; return 0; }
r[14]=read(ram,0x0c05c468u,4);
goto P_0c05c318;
P_0c05c318: /* original d354, guest PC 0x0c05c318 */
if(!s->budget--) { s->failed_pc=0x0c05c318u; return 0; }
r[3]=read(ram,0x0c05c46cu,4);
goto P_0c05c31a;
P_0c05c31a: /* original 2e49, guest PC 0x0c05c31a */
if(!s->budget--) { s->failed_pc=0x0c05c31au; return 0; }
r[14]&=r[4];
goto P_0c05c31c;
P_0c05c31c: /* original 2e3b, guest PC 0x0c05c31c */
if(!s->budget--) { s->failed_pc=0x0c05c31cu; return 0; }
r[14]|=r[3];
goto P_0c05c31e;
P_0c05c31e: /* original 420b, guest PC 0x0c05c31e */
if(!s->budget--) { s->failed_pc=0x0c05c31eu; return 0; }
target=r[2];
r[16]=code_base|0x0c05c322u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c05c322u) { target=s->pc; goto dispatch; }
goto P_0c05c322;
P_0c05c320: /* original 64e3, guest PC 0x0c05c320 */
if(!s->budget--) { s->failed_pc=0x0c05c320u; return 0; }
r[4]=r[14];
goto P_0c05c322;
P_0c05c322: /* original 0e83, guest PC 0x0c05c322 */
if(!s->budget--) { s->failed_pc=0x0c05c322u; return 0; }
if((r[14]&0xFC000000u)==0xE0000000u) pref(ram,r[14]);
goto P_0c05c324;
P_0c05c324: /* original 60c3, guest PC 0x0c05c324 */
if(!s->budget--) { s->failed_pc=0x0c05c324u; return 0; }
r[0]=r[12];
goto P_0c05c326;
P_0c05c326: /* original 0009, guest PC 0x0c05c326 */
if(!s->budget--) { s->failed_pc=0x0c05c326u; return 0; }
goto P_0c05c328;
P_0c05c328: /* original 8840, guest PC 0x0c05c328 */
if(!s->budget--) { s->failed_pc=0x0c05c328u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000040u)!=0);
goto P_0c05c32a;
P_0c05c32a: /* original 8b01, guest PC 0x0c05c32a */
if(!s->budget--) { s->failed_pc=0x0c05c32au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c05c330; }
goto P_0c05c32c;
P_0c05c32c: /* original 7e20, guest PC 0x0c05c32c */
if(!s->budget--) { s->failed_pc=0x0c05c32cu; return 0; }
r[14]+=0x00000020u;
goto P_0c05c32e;
P_0c05c32e: /* original 0e83, guest PC 0x0c05c32e */
if(!s->budget--) { s->failed_pc=0x0c05c32eu; return 0; }
if((r[14]&0xFC000000u)==0xE0000000u) pref(ram,r[14]);
goto P_0c05c330;
P_0c05c330: /* original 62f2, guest PC 0x0c05c330 */
if(!s->budget--) { s->failed_pc=0x0c05c330u; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c05c332;
P_0c05c332: /* original 4c21, guest PC 0x0c05c332 */
if(!s->budget--) { s->failed_pc=0x0c05c332u; return 0; }
r[17]=(r[17]&~1u)|((r[12]&1)!=0);
r[12]=(uint32_t)((int32_t)r[12]>>1);
goto P_0c05c334;
P_0c05c334: /* original 60d2, guest PC 0x0c05c334 */
if(!s->budget--) { s->failed_pc=0x0c05c334u; return 0; }
tmp=read(ram,r[13],4);
r[0]=tmp;
goto P_0c05c336;
P_0c05c336: /* original 4c21, guest PC 0x0c05c336 */
if(!s->budget--) { s->failed_pc=0x0c05c336u; return 0; }
r[17]=(r[17]&~1u)|((r[12]&1)!=0);
r[12]=(uint32_t)((int32_t)r[12]>>1);
goto P_0c05c338;
P_0c05c338: /* original 032e, guest PC 0x0c05c338 */
if(!s->budget--) { s->failed_pc=0x0c05c338u; return 0; }
r[3]=read(ram,r[2]+r[0],4);
goto P_0c05c33a;
P_0c05c33a: /* original 4c08, guest PC 0x0c05c33a */
if(!s->budget--) { s->failed_pc=0x0c05c33au; return 0; }
r[12]<<=2;
goto P_0c05c33c;
P_0c05c33c: /* original 33cc, guest PC 0x0c05c33c */
if(!s->budget--) { s->failed_pc=0x0c05c33cu; return 0; }
r[3]+=r[12];
goto P_0c05c33e;
P_0c05c33e: /* original 0236, guest PC 0x0c05c33e */
if(!s->budget--) { s->failed_pc=0x0c05c33eu; return 0; }
write(ram,r[2]+r[0],r[3],4);
goto P_0c05c340;
P_0c05c340: /* original e000, guest PC 0x0c05c340 */
if(!s->budget--) { s->failed_pc=0x0c05c340u; return 0; }
r[0]=0x00000000u;
goto P_0c05c342;
P_0c05c342: /* original 7f04, guest PC 0x0c05c342 */
if(!s->budget--) { s->failed_pc=0x0c05c342u; return 0; }
r[15]+=0x00000004u;
goto P_0c05c344;
P_0c05c344: /* original 4f26, guest PC 0x0c05c344 */
if(!s->budget--) { s->failed_pc=0x0c05c344u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c05c346;
P_0c05c346: /* original 6cf6, guest PC 0x0c05c346 */
if(!s->budget--) { s->failed_pc=0x0c05c346u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c05c348;
P_0c05c348: /* original 6df6, guest PC 0x0c05c348 */
if(!s->budget--) { s->failed_pc=0x0c05c348u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c05c34a;
P_0c05c34a: /* original 000b, guest PC 0x0c05c34a */
if(!s->budget--) { s->failed_pc=0x0c05c34au; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c05c34c: /* original 6ef6, guest PC 0x0c05c34c */
if(!s->budget--) { s->failed_pc=0x0c05c34cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c05c34eu,s,ram);
P_0c05c368: /* original 4f22, guest PC 0x0c05c368 */
if(!s->budget--) { s->failed_pc=0x0c05c368u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c05c36a;
P_0c05c36a: /* original 6ba3, guest PC 0x0c05c36a */
if(!s->budget--) { s->failed_pc=0x0c05c36au; return 0; }
r[11]=r[10];
goto P_0c05c36c;
P_0c05c36c: /* original d83f, guest PC 0x0c05c36c */
if(!s->budget--) { s->failed_pc=0x0c05c36cu; return 0; }
r[8]=read(ram,0x0c05c46cu,4);
goto P_0c05c36e;
P_0c05c36e: /* original 7fd4, guest PC 0x0c05c36e */
if(!s->budget--) { s->failed_pc=0x0c05c36eu; return 0; }
r[15]+=0xffffffd4u;
goto P_0c05c370;
P_0c05c370: /* original d93d, guest PC 0x0c05c370 */
if(!s->budget--) { s->failed_pc=0x0c05c370u; return 0; }
r[9]=read(ram,0x0c05c468u,4);
goto P_0c05c372;
P_0c05c372: /* original 7bfc, guest PC 0x0c05c372 */
if(!s->budget--) { s->failed_pc=0x0c05c372u; return 0; }
r[11]+=0xfffffffcu;
goto P_0c05c374;
P_0c05c374: /* original 1f62, guest PC 0x0c05c374 */
if(!s->budget--) { s->failed_pc=0x0c05c374u; return 0; }
write(ram,r[15]+8,r[6],4);
goto P_0c05c376;
P_0c05c376: /* original 1f71, guest PC 0x0c05c376 */
if(!s->budget--) { s->failed_pc=0x0c05c376u; return 0; }
write(ram,r[15]+4,r[7],4);
goto P_0c05c378;
P_0c05c378: /* original 430b, guest PC 0x0c05c378 */
if(!s->budget--) { s->failed_pc=0x0c05c378u; return 0; }
target=r[3];
r[16]=code_base|0x0c05c37cu;
r[4]=r[12];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c05c37cu) { target=s->pc; goto dispatch; }
goto P_0c05c37c;
P_0c05c37a: /* original 64c3, guest PC 0x0c05c37a */
if(!s->budget--) { s->failed_pc=0x0c05c37au; return 0; }
r[4]=r[12];
goto P_0c05c37c;
P_0c05c37c: /* original 8808, guest PC 0x0c05c37c */
if(!s->budget--) { s->failed_pc=0x0c05c37cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000008u)!=0);
goto P_0c05c37e;
P_0c05c37e: /* original 8941, guest PC 0x0c05c37e */
if(!s->budget--) { s->failed_pc=0x0c05c37eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05c404; }
goto P_0c05c380;
P_0c05c380: /* original 56e1, guest PC 0x0c05c380 */
if(!s->budget--) { s->failed_pc=0x0c05c380u; return 0; }
r[6]=read(ram,r[14]+4,4);
goto P_0c05c382;
P_0c05c382: /* original e301, guest PC 0x0c05c382 */
if(!s->budget--) { s->failed_pc=0x0c05c382u; return 0; }
r[3]=0x00000001u;
goto P_0c05c384;
P_0c05c384: /* original d73d, guest PC 0x0c05c384 */
if(!s->budget--) { s->failed_pc=0x0c05c384u; return 0; }
r[7]=read(ram,0x0c05c47cu,4);
goto P_0c05c386;
P_0c05c386: /* original 2c38, guest PC 0x0c05c386 */
if(!s->budget--) { s->failed_pc=0x0c05c386u; return 0; }
r[17]=(r[17]&~1u)|(((r[12]&r[3])==0)!=0);
goto P_0c05c388;
P_0c05c388: /* original 6662, guest PC 0x0c05c388 */
if(!s->budget--) { s->failed_pc=0x0c05c388u; return 0; }
tmp=read(ram,r[6],4);
r[6]=tmp;
goto P_0c05c38a;
P_0c05c38a: /* original 6573, guest PC 0x0c05c38a */
if(!s->budget--) { s->failed_pc=0x0c05c38au; return 0; }
r[5]=r[7];
goto P_0c05c38c;
P_0c05c38c: /* original d43c, guest PC 0x0c05c38c */
if(!s->budget--) { s->failed_pc=0x0c05c38cu; return 0; }
r[4]=read(ram,0x0c05c480u,4);
goto P_0c05c38e;
P_0c05c38e: /* original 8d03, guest PC 0x0c05c38e */
if(!s->budget--) { s->failed_pc=0x0c05c38eu; return 0; }
cond=r[17]&1u;
r[4]&=r[6];
if(cond) { goto P_0c05c398; }
goto P_0c05c392;
P_0c05c390: /* original 2469, guest PC 0x0c05c390 */
if(!s->budget--) { s->failed_pc=0x0c05c390u; return 0; }
r[4]&=r[6];
goto P_0c05c392;
P_0c05c392: /* original d13c, guest PC 0x0c05c392 */
if(!s->budget--) { s->failed_pc=0x0c05c392u; return 0; }
r[1]=read(ram,0x0c05c484u,4);
goto P_0c05c394;
P_0c05c394: /* original a001, guest PC 0x0c05c394 */
if(!s->budget--) { s->failed_pc=0x0c05c394u; return 0; }
goto P_0c05c39a;
P_0c05c396: /* original 0009, guest PC 0x0c05c396 */
if(!s->budget--) { s->failed_pc=0x0c05c396u; return 0; }
goto P_0c05c398;
P_0c05c398: /* original d13b, guest PC 0x0c05c398 */
if(!s->budget--) { s->failed_pc=0x0c05c398u; return 0; }
r[1]=read(ram,0x0c05c488u,4);
goto P_0c05c39a;
P_0c05c39a: /* original 241b, guest PC 0x0c05c39a */
if(!s->budget--) { s->failed_pc=0x0c05c39au; return 0; }
r[4]|=r[1];
goto P_0c05c39c;
P_0c05c39c: /* original 2542, guest PC 0x0c05c39c */
if(!s->budget--) { s->failed_pc=0x0c05c39cu; return 0; }
write(ram,r[5],r[4],4);
goto P_0c05c39e;
P_0c05c39e: /* original 6573, guest PC 0x0c05c39e */
if(!s->budget--) { s->failed_pc=0x0c05c39eu; return 0; }
r[5]=r[7];
goto P_0c05c3a0;
P_0c05c3a0: /* original 60e2, guest PC 0x0c05c3a0 */
if(!s->budget--) { s->failed_pc=0x0c05c3a0u; return 0; }
tmp=read(ram,r[14],4);
r[0]=tmp;
goto P_0c05c3a2;
P_0c05c3a2: /* original 04de, guest PC 0x0c05c3a2 */
if(!s->budget--) { s->failed_pc=0x0c05c3a2u; return 0; }
r[4]=read(ram,r[13]+r[0],4);
goto P_0c05c3a4;
P_0c05c3a4: /* original 6643, guest PC 0x0c05c3a4 */
if(!s->budget--) { s->failed_pc=0x0c05c3a4u; return 0; }
r[6]=r[4];
goto P_0c05c3a6;
P_0c05c3a6: /* original 4629, guest PC 0x0c05c3a6 */
if(!s->budget--) { s->failed_pc=0x0c05c3a6u; return 0; }
r[6]>>=16;
goto P_0c05c3a8;
P_0c05c3a8: /* original 4619, guest PC 0x0c05c3a8 */
if(!s->budget--) { s->failed_pc=0x0c05c3a8u; return 0; }
r[6]>>=8;
goto P_0c05c3aa;
P_0c05c3aa: /* original 2b62, guest PC 0x0c05c3aa */
if(!s->budget--) { s->failed_pc=0x0c05c3aau; return 0; }
write(ram,r[11],r[6],4);
goto P_0c05c3ac;
P_0c05c3ac: /* original 2a62, guest PC 0x0c05c3ac */
if(!s->budget--) { s->failed_pc=0x0c05c3acu; return 0; }
write(ram,r[10],r[6],4);
goto P_0c05c3ae;
P_0c05c3ae: /* original 6c43, guest PC 0x0c05c3ae */
if(!s->budget--) { s->failed_pc=0x0c05c3aeu; return 0; }
r[12]=r[4];
goto P_0c05c3b0;
P_0c05c3b0: /* original d32f, guest PC 0x0c05c3b0 */
if(!s->budget--) { s->failed_pc=0x0c05c3b0u; return 0; }
r[3]=read(ram,0x0c05c470u,4);
goto P_0c05c3b2;
P_0c05c3b2: /* original e620, guest PC 0x0c05c3b2 */
if(!s->budget--) { s->failed_pc=0x0c05c3b2u; return 0; }
r[6]=0x00000020u;
goto P_0c05c3b4;
P_0c05c3b4: /* original 2c99, guest PC 0x0c05c3b4 */
if(!s->budget--) { s->failed_pc=0x0c05c3b4u; return 0; }
r[12]&=r[9];
goto P_0c05c3b6;
P_0c05c3b6: /* original 2c8b, guest PC 0x0c05c3b6 */
if(!s->budget--) { s->failed_pc=0x0c05c3b6u; return 0; }
r[12]|=r[8];
goto P_0c05c3b8;
P_0c05c3b8: /* original 430b, guest PC 0x0c05c3b8 */
if(!s->budget--) { s->failed_pc=0x0c05c3b8u; return 0; }
target=r[3];
r[16]=code_base|0x0c05c3bcu;
r[4]=r[12];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c05c3bcu) { target=s->pc; goto dispatch; }
goto P_0c05c3bc;
P_0c05c3ba: /* original 64c3, guest PC 0x0c05c3ba */
if(!s->budget--) { s->failed_pc=0x0c05c3bau; return 0; }
r[4]=r[12];
goto P_0c05c3bc;
P_0c05c3bc: /* original 0c83, guest PC 0x0c05c3bc */
if(!s->budget--) { s->failed_pc=0x0c05c3bcu; return 0; }
if((r[12]&0xFC000000u)==0xE0000000u) pref(ram,r[12]);
goto P_0c05c3be;
P_0c05c3be: /* original 60e2, guest PC 0x0c05c3be */
if(!s->budget--) { s->failed_pc=0x0c05c3beu; return 0; }
tmp=read(ram,r[14],4);
r[0]=tmp;
goto P_0c05c3c0;
P_0c05c3c0: /* original 03de, guest PC 0x0c05c3c0 */
if(!s->budget--) { s->failed_pc=0x0c05c3c0u; return 0; }
r[3]=read(ram,r[13]+r[0],4);
goto P_0c05c3c2;
P_0c05c3c2: /* original e202, guest PC 0x0c05c3c2 */
if(!s->budget--) { s->failed_pc=0x0c05c3c2u; return 0; }
r[2]=0x00000002u;
goto P_0c05c3c4;
P_0c05c3c4: /* original 7320, guest PC 0x0c05c3c4 */
if(!s->budget--) { s->failed_pc=0x0c05c3c4u; return 0; }
r[3]+=0x00000020u;
goto P_0c05c3c6;
P_0c05c3c6: /* original 0d36, guest PC 0x0c05c3c6 */
if(!s->budget--) { s->failed_pc=0x0c05c3c6u; return 0; }
write(ram,r[13]+r[0],r[3],4);
goto P_0c05c3c8;
P_0c05c3c8: /* original a019, guest PC 0x0c05c3c8 */
if(!s->budget--) { s->failed_pc=0x0c05c3c8u; return 0; }
write(ram,r[15],r[2],4);
goto P_0c05c3fe;
P_0c05c3ca: /* original 2f22, guest PC 0x0c05c3ca */
if(!s->budget--) { s->failed_pc=0x0c05c3cau; return 0; }
write(ram,r[15],r[2],4);
goto P_0c05c3cc;
P_0c05c3cc: /* original 60e2, guest PC 0x0c05c3cc */
if(!s->budget--) { s->failed_pc=0x0c05c3ccu; return 0; }
tmp=read(ram,r[14],4);
r[0]=tmp;
goto P_0c05c3ce;
P_0c05c3ce: /* original 04de, guest PC 0x0c05c3ce */
if(!s->budget--) { s->failed_pc=0x0c05c3ceu; return 0; }
r[4]=read(ram,r[13]+r[0],4);
goto P_0c05c3d0;
P_0c05c3d0: /* original d52e, guest PC 0x0c05c3d0 */
if(!s->budget--) { s->failed_pc=0x0c05c3d0u; return 0; }
r[5]=read(ram,0x0c05c48cu,4);
goto P_0c05c3d2;
P_0c05c3d2: /* original 6643, guest PC 0x0c05c3d2 */
if(!s->budget--) { s->failed_pc=0x0c05c3d2u; return 0; }
r[6]=r[4];
goto P_0c05c3d4;
P_0c05c3d4: /* original 4629, guest PC 0x0c05c3d4 */
if(!s->budget--) { s->failed_pc=0x0c05c3d4u; return 0; }
r[6]>>=16;
goto P_0c05c3d6;
P_0c05c3d6: /* original 4619, guest PC 0x0c05c3d6 */
if(!s->budget--) { s->failed_pc=0x0c05c3d6u; return 0; }
r[6]>>=8;
goto P_0c05c3d8;
P_0c05c3d8: /* original 2b62, guest PC 0x0c05c3d8 */
if(!s->budget--) { s->failed_pc=0x0c05c3d8u; return 0; }
write(ram,r[11],r[6],4);
goto P_0c05c3da;
P_0c05c3da: /* original 2a62, guest PC 0x0c05c3da */
if(!s->budget--) { s->failed_pc=0x0c05c3dau; return 0; }
write(ram,r[10],r[6],4);
goto P_0c05c3dc;
P_0c05c3dc: /* original d324, guest PC 0x0c05c3dc */
if(!s->budget--) { s->failed_pc=0x0c05c3dcu; return 0; }
r[3]=read(ram,0x0c05c470u,4);
goto P_0c05c3de;
P_0c05c3de: /* original 6c43, guest PC 0x0c05c3de */
if(!s->budget--) { s->failed_pc=0x0c05c3deu; return 0; }
r[12]=r[4];
goto P_0c05c3e0;
P_0c05c3e0: /* original 2c99, guest PC 0x0c05c3e0 */
if(!s->budget--) { s->failed_pc=0x0c05c3e0u; return 0; }
r[12]&=r[9];
goto P_0c05c3e2;
P_0c05c3e2: /* original 2c8b, guest PC 0x0c05c3e2 */
if(!s->budget--) { s->failed_pc=0x0c05c3e2u; return 0; }
r[12]|=r[8];
goto P_0c05c3e4;
P_0c05c3e4: /* original e640, guest PC 0x0c05c3e4 */
if(!s->budget--) { s->failed_pc=0x0c05c3e4u; return 0; }
r[6]=0x00000040u;
goto P_0c05c3e6;
P_0c05c3e6: /* original 430b, guest PC 0x0c05c3e6 */
if(!s->budget--) { s->failed_pc=0x0c05c3e6u; return 0; }
target=r[3];
r[16]=code_base|0x0c05c3eau;
r[4]=r[12];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c05c3eau) { target=s->pc; goto dispatch; }
goto P_0c05c3ea;
P_0c05c3e8: /* original 64c3, guest PC 0x0c05c3e8 */
if(!s->budget--) { s->failed_pc=0x0c05c3e8u; return 0; }
r[4]=r[12];
goto P_0c05c3ea;
P_0c05c3ea: /* original 0c83, guest PC 0x0c05c3ea */
if(!s->budget--) { s->failed_pc=0x0c05c3eau; return 0; }
if((r[12]&0xFC000000u)==0xE0000000u) pref(ram,r[12]);
goto P_0c05c3ec;
P_0c05c3ec: /* original 7c20, guest PC 0x0c05c3ec */
if(!s->budget--) { s->failed_pc=0x0c05c3ecu; return 0; }
r[12]+=0x00000020u;
goto P_0c05c3ee;
P_0c05c3ee: /* original 0c83, guest PC 0x0c05c3ee */
if(!s->budget--) { s->failed_pc=0x0c05c3eeu; return 0; }
if((r[12]&0xFC000000u)==0xE0000000u) pref(ram,r[12]);
goto P_0c05c3f0;
P_0c05c3f0: /* original 60e2, guest PC 0x0c05c3f0 */
if(!s->budget--) { s->failed_pc=0x0c05c3f0u; return 0; }
tmp=read(ram,r[14],4);
r[0]=tmp;
goto P_0c05c3f2;
P_0c05c3f2: /* original 02de, guest PC 0x0c05c3f2 */
if(!s->budget--) { s->failed_pc=0x0c05c3f2u; return 0; }
r[2]=read(ram,r[13]+r[0],4);
goto P_0c05c3f4;
P_0c05c3f4: /* original 7240, guest PC 0x0c05c3f4 */
if(!s->budget--) { s->failed_pc=0x0c05c3f4u; return 0; }
r[2]+=0x00000040u;
goto P_0c05c3f6;
P_0c05c3f6: /* original 0d26, guest PC 0x0c05c3f6 */
if(!s->budget--) { s->failed_pc=0x0c05c3f6u; return 0; }
write(ram,r[13]+r[0],r[2],4);
goto P_0c05c3f8;
P_0c05c3f8: /* original 63f2, guest PC 0x0c05c3f8 */
if(!s->budget--) { s->failed_pc=0x0c05c3f8u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c05c3fa;
P_0c05c3fa: /* original 73ff, guest PC 0x0c05c3fa */
if(!s->budget--) { s->failed_pc=0x0c05c3fau; return 0; }
r[3]+=0xffffffffu;
goto P_0c05c3fc;
P_0c05c3fc: /* original 2f32, guest PC 0x0c05c3fc */
if(!s->budget--) { s->failed_pc=0x0c05c3fcu; return 0; }
write(ram,r[15],r[3],4);
goto P_0c05c3fe;
P_0c05c3fe: /* original 62f2, guest PC 0x0c05c3fe */
if(!s->budget--) { s->failed_pc=0x0c05c3feu; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c05c400;
P_0c05c400: /* original 2228, guest PC 0x0c05c400 */
if(!s->budget--) { s->failed_pc=0x0c05c400u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c05c402;
P_0c05c402: /* original 8be3, guest PC 0x0c05c402 */
if(!s->budget--) { s->failed_pc=0x0c05c402u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c05c3cc; }
goto P_0c05c404;
P_0c05c404: /* original d322, guest PC 0x0c05c404 */
if(!s->budget--) { s->failed_pc=0x0c05c404u; return 0; }
r[3]=read(ram,0x0c05c490u,4);
goto P_0c05c406;
P_0c05c406: /* original e04c, guest PC 0x0c05c406 */
if(!s->budget--) { s->failed_pc=0x0c05c406u; return 0; }
r[0]=0x0000004cu;
goto P_0c05c408;
P_0c05c408: /* original 64f3, guest PC 0x0c05c408 */
if(!s->budget--) { s->failed_pc=0x0c05c408u; return 0; }
r[4]=r[15];
goto P_0c05c40a;
P_0c05c40a: /* original 740c, guest PC 0x0c05c40a */
if(!s->budget--) { s->failed_pc=0x0c05c40au; return 0; }
r[4]+=0x0000000cu;
goto P_0c05c40c;
P_0c05c40c: /* original 2432, guest PC 0x0c05c40c */
if(!s->budget--) { s->failed_pc=0x0c05c40cu; return 0; }
write(ram,r[4],r[3],4);
goto P_0c05c40e;
P_0c05c40e: /* original 6543, guest PC 0x0c05c40e */
if(!s->budget--) { s->failed_pc=0x0c05c40eu; return 0; }
r[5]=r[4];
goto P_0c05c410;
P_0c05c410: /* original 52f2, guest PC 0x0c05c410 */
if(!s->budget--) { s->failed_pc=0x0c05c410u; return 0; }
r[2]=read(ram,r[15]+8,4);
goto P_0c05c412;
P_0c05c412: /* original 1424, guest PC 0x0c05c412 */
if(!s->budget--) { s->failed_pc=0x0c05c412u; return 0; }
write(ram,r[4]+16,r[2],4);
goto P_0c05c414;
P_0c05c414: /* original 53f1, guest PC 0x0c05c414 */
if(!s->budget--) { s->failed_pc=0x0c05c414u; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c05c416;
P_0c05c416: /* original 1435, guest PC 0x0c05c416 */
if(!s->budget--) { s->failed_pc=0x0c05c416u; return 0; }
write(ram,r[4]+20,r[3],4);
goto P_0c05c418;
P_0c05c418: /* original 02fe, guest PC 0x0c05c418 */
if(!s->budget--) { s->failed_pc=0x0c05c418u; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c05c41a;
P_0c05c41a: /* original e050, guest PC 0x0c05c41a */
if(!s->budget--) { s->failed_pc=0x0c05c41au; return 0; }
r[0]=0x00000050u;
goto P_0c05c41c;
P_0c05c41c: /* original 1426, guest PC 0x0c05c41c */
if(!s->budget--) { s->failed_pc=0x0c05c41cu; return 0; }
write(ram,r[4]+24,r[2],4);
goto P_0c05c41e;
P_0c05c41e: /* original 03fe, guest PC 0x0c05c41e */
if(!s->budget--) { s->failed_pc=0x0c05c41eu; return 0; }
r[3]=read(ram,r[15]+r[0],4);
goto P_0c05c420;
P_0c05c420: /* original 1437, guest PC 0x0c05c420 */
if(!s->budget--) { s->failed_pc=0x0c05c420u; return 0; }
write(ram,r[4]+28,r[3],4);
goto P_0c05c422;
P_0c05c422: /* original 60e2, guest PC 0x0c05c422 */
if(!s->budget--) { s->failed_pc=0x0c05c422u; return 0; }
tmp=read(ram,r[14],4);
r[0]=tmp;
goto P_0c05c424;
P_0c05c424: /* original 06de, guest PC 0x0c05c424 */
if(!s->budget--) { s->failed_pc=0x0c05c424u; return 0; }
r[6]=read(ram,r[13]+r[0],4);
goto P_0c05c426;
P_0c05c426: /* original 6463, guest PC 0x0c05c426 */
if(!s->budget--) { s->failed_pc=0x0c05c426u; return 0; }
r[4]=r[6];
goto P_0c05c428;
P_0c05c428: /* original 4429, guest PC 0x0c05c428 */
if(!s->budget--) { s->failed_pc=0x0c05c428u; return 0; }
r[4]>>=16;
goto P_0c05c42a;
P_0c05c42a: /* original 4419, guest PC 0x0c05c42a */
if(!s->budget--) { s->failed_pc=0x0c05c42au; return 0; }
r[4]>>=8;
goto P_0c05c42c;
P_0c05c42c: /* original 2b42, guest PC 0x0c05c42c */
if(!s->budget--) { s->failed_pc=0x0c05c42cu; return 0; }
write(ram,r[11],r[4],4);
goto P_0c05c42e;
P_0c05c42e: /* original 2a42, guest PC 0x0c05c42e */
if(!s->budget--) { s->failed_pc=0x0c05c42eu; return 0; }
write(ram,r[10],r[4],4);
goto P_0c05c430;
P_0c05c430: /* original d30f, guest PC 0x0c05c430 */
if(!s->budget--) { s->failed_pc=0x0c05c430u; return 0; }
r[3]=read(ram,0x0c05c470u,4);
goto P_0c05c432;
P_0c05c432: /* original 6c63, guest PC 0x0c05c432 */
if(!s->budget--) { s->failed_pc=0x0c05c432u; return 0; }
r[12]=r[6];
goto P_0c05c434;
P_0c05c434: /* original 2c99, guest PC 0x0c05c434 */
if(!s->budget--) { s->failed_pc=0x0c05c434u; return 0; }
r[12]&=r[9];
goto P_0c05c436;
P_0c05c436: /* original 2c8b, guest PC 0x0c05c436 */
if(!s->budget--) { s->failed_pc=0x0c05c436u; return 0; }
r[12]|=r[8];
goto P_0c05c438;
P_0c05c438: /* original e620, guest PC 0x0c05c438 */
if(!s->budget--) { s->failed_pc=0x0c05c438u; return 0; }
r[6]=0x00000020u;
goto P_0c05c43a;
P_0c05c43a: /* original 430b, guest PC 0x0c05c43a */
if(!s->budget--) { s->failed_pc=0x0c05c43au; return 0; }
target=r[3];
r[16]=code_base|0x0c05c43eu;
r[4]=r[12];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c05c43eu) { target=s->pc; goto dispatch; }
goto P_0c05c43e;
P_0c05c43c: /* original 64c3, guest PC 0x0c05c43c */
if(!s->budget--) { s->failed_pc=0x0c05c43cu; return 0; }
r[4]=r[12];
goto P_0c05c43e;
P_0c05c43e: /* original 0c83, guest PC 0x0c05c43e */
if(!s->budget--) { s->failed_pc=0x0c05c43eu; return 0; }
if((r[12]&0xFC000000u)==0xE0000000u) pref(ram,r[12]);
goto P_0c05c440;
P_0c05c440: /* original 60e2, guest PC 0x0c05c440 */
if(!s->budget--) { s->failed_pc=0x0c05c440u; return 0; }
tmp=read(ram,r[14],4);
r[0]=tmp;
goto P_0c05c442;
P_0c05c442: /* original 03de, guest PC 0x0c05c442 */
if(!s->budget--) { s->failed_pc=0x0c05c442u; return 0; }
r[3]=read(ram,r[13]+r[0],4);
goto P_0c05c444;
P_0c05c444: /* original 7320, guest PC 0x0c05c444 */
if(!s->budget--) { s->failed_pc=0x0c05c444u; return 0; }
r[3]+=0x00000020u;
goto P_0c05c446;
P_0c05c446: /* original 0d36, guest PC 0x0c05c446 */
if(!s->budget--) { s->failed_pc=0x0c05c446u; return 0; }
write(ram,r[13]+r[0],r[3],4);
goto P_0c05c448;
P_0c05c448: /* original e000, guest PC 0x0c05c448 */
if(!s->budget--) { s->failed_pc=0x0c05c448u; return 0; }
r[0]=0x00000000u;
goto P_0c05c44a;
P_0c05c44a: /* original 7f2c, guest PC 0x0c05c44a */
if(!s->budget--) { s->failed_pc=0x0c05c44au; return 0; }
r[15]+=0x0000002cu;
goto P_0c05c44c;
P_0c05c44c: /* original 4f26, guest PC 0x0c05c44c */
if(!s->budget--) { s->failed_pc=0x0c05c44cu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c05c44e;
P_0c05c44e: /* original 68f6, guest PC 0x0c05c44e */
if(!s->budget--) { s->failed_pc=0x0c05c44eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c05c450;
P_0c05c450: /* original 69f6, guest PC 0x0c05c450 */
if(!s->budget--) { s->failed_pc=0x0c05c450u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c05c452;
P_0c05c452: /* original 6af6, guest PC 0x0c05c452 */
if(!s->budget--) { s->failed_pc=0x0c05c452u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c05c454;
P_0c05c454: /* original 6bf6, guest PC 0x0c05c454 */
if(!s->budget--) { s->failed_pc=0x0c05c454u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c05c456;
P_0c05c456: /* original 6cf6, guest PC 0x0c05c456 */
if(!s->budget--) { s->failed_pc=0x0c05c456u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c05c458;
P_0c05c458: /* original 6df6, guest PC 0x0c05c458 */
if(!s->budget--) { s->failed_pc=0x0c05c458u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c05c45a;
P_0c05c45a: /* original 000b, guest PC 0x0c05c45a */
if(!s->budget--) { s->failed_pc=0x0c05c45au; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c05c45c: /* original 6ef6, guest PC 0x0c05c45c */
if(!s->budget--) { s->failed_pc=0x0c05c45cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c05c45eu,s,ram);
P_0c05f36e: /* original 4f22, guest PC 0x0c05f36e */
if(!s->budget--) { s->failed_pc=0x0c05f36eu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c05f370;
P_0c05f370: /* original 7ff8, guest PC 0x0c05f370 */
if(!s->budget--) { s->failed_pc=0x0c05f370u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c05f372;
P_0c05f372: /* original 2f62, guest PC 0x0c05f372 */
if(!s->budget--) { s->failed_pc=0x0c05f372u; return 0; }
write(ram,r[15],r[6],4);
goto P_0c05f374;
P_0c05f374: /* original 1f71, guest PC 0x0c05f374 */
if(!s->budget--) { s->failed_pc=0x0c05f374u; return 0; }
write(ram,r[15]+4,r[7],4);
goto P_0c05f376;
P_0c05f376: /* original 65f2, guest PC 0x0c05f376 */
if(!s->budget--) { s->failed_pc=0x0c05f376u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c05f378;
P_0c05f378: /* original be9e, guest PC 0x0c05f378 */
if(!s->budget--) { s->failed_pc=0x0c05f378u; return 0; }
target=0x0c05f0b8u; r[16]=code_base|0x0c05f37cu;
r[4]=r[5];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c05f37cu) { target=s->pc; goto dispatch; }
goto P_0c05f37c;
P_0c05f37a: /* original 6453, guest PC 0x0c05f37a */
if(!s->budget--) { s->failed_pc=0x0c05f37au; return 0; }
r[4]=r[5];
goto P_0c05f37c;
P_0c05f37c: /* original 6403, guest PC 0x0c05f37c */
if(!s->budget--) { s->failed_pc=0x0c05f37cu; return 0; }
r[4]=r[0];
goto P_0c05f37e;
P_0c05f37e: /* original 6203, guest PC 0x0c05f37e */
if(!s->budget--) { s->failed_pc=0x0c05f37eu; return 0; }
r[2]=r[0];
goto P_0c05f380;
P_0c05f380: /* original 50f1, guest PC 0x0c05f380 */
if(!s->budget--) { s->failed_pc=0x0c05f380u; return 0; }
r[0]=read(ram,r[15]+4,4);
goto P_0c05f382;
P_0c05f382: /* original c801, guest PC 0x0c05f382 */
if(!s->budget--) { s->failed_pc=0x0c05f382u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&1u)==0)!=0);
goto P_0c05f384;
P_0c05f384: /* original 8d14, guest PC 0x0c05f384 */
if(!s->budget--) { s->failed_pc=0x0c05f384u; return 0; }
cond=r[17]&1u;
r[2]<<=2;
if(cond) { goto P_0c05f3b0; }
goto P_0c05f388;
P_0c05f386: /* original 4208, guest PC 0x0c05f386 */
if(!s->budget--) { s->failed_pc=0x0c05f386u; return 0; }
r[2]<<=2;
goto P_0c05f388;
P_0c05f388: /* original d003, guest PC 0x0c05f388 */
if(!s->budget--) { s->failed_pc=0x0c05f388u; return 0; }
r[0]=read(ram,0x0c05f398u,4);
goto P_0c05f38a;
P_0c05f38a: /* original 0c2e, guest PC 0x0c05f38a */
if(!s->budget--) { s->failed_pc=0x0c05f38au; return 0; }
r[12]=read(ram,r[2]+r[0],4);
goto P_0c05f38c;
P_0c05f38c: /* original d007, guest PC 0x0c05f38c */
if(!s->budget--) { s->failed_pc=0x0c05f38cu; return 0; }
r[0]=read(ram,0x0c05f3acu,4);
goto P_0c05f38e;
P_0c05f38e: /* original 0a2e, guest PC 0x0c05f38e */
if(!s->budget--) { s->failed_pc=0x0c05f38eu; return 0; }
r[10]=read(ram,r[2]+r[0],4);
goto P_0c05f390;
P_0c05f390: /* original a012, guest PC 0x0c05f390 */
if(!s->budget--) { s->failed_pc=0x0c05f390u; return 0; }
r[10]+=0x0000000au;
goto P_0c05f3b8;
P_0c05f392: /* original 7a0a, guest PC 0x0c05f392 */
if(!s->budget--) { s->failed_pc=0x0c05f392u; return 0; }
r[10]+=0x0000000au;
return vf3_matrix_family(0x0c05f394u,s,ram);
P_0c05f3b0: /* original d044, guest PC 0x0c05f3b0 */
if(!s->budget--) { s->failed_pc=0x0c05f3b0u; return 0; }
r[0]=read(ram,0x0c05f4c4u,4);
goto P_0c05f3b2;
P_0c05f3b2: /* original 0c2e, guest PC 0x0c05f3b2 */
if(!s->budget--) { s->failed_pc=0x0c05f3b2u; return 0; }
r[12]=read(ram,r[2]+r[0],4);
goto P_0c05f3b4;
P_0c05f3b4: /* original d044, guest PC 0x0c05f3b4 */
if(!s->budget--) { s->failed_pc=0x0c05f3b4u; return 0; }
r[0]=read(ram,0x0c05f4c8u,4);
goto P_0c05f3b6;
P_0c05f3b6: /* original 0a2e, guest PC 0x0c05f3b6 */
if(!s->budget--) { s->failed_pc=0x0c05f3b6u; return 0; }
r[10]=read(ram,r[2]+r[0],4);
goto P_0c05f3b8;
P_0c05f3b8: /* original d244, guest PC 0x0c05f3b8 */
if(!s->budget--) { s->failed_pc=0x0c05f3b8u; return 0; }
r[2]=read(ram,0x0c05f4ccu,4);
goto P_0c05f3ba;
P_0c05f3ba: /* original 66c3, guest PC 0x0c05f3ba */
if(!s->budget--) { s->failed_pc=0x0c05f3bau; return 0; }
r[6]=r[12];
goto P_0c05f3bc;
P_0c05f3bc: /* original 65d3, guest PC 0x0c05f3bc */
if(!s->budget--) { s->failed_pc=0x0c05f3bcu; return 0; }
r[5]=r[13];
goto P_0c05f3be;
P_0c05f3be: /* original 420b, guest PC 0x0c05f3be */
if(!s->budget--) { s->failed_pc=0x0c05f3beu; return 0; }
target=r[2];
r[16]=code_base|0x0c05f3c2u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c05f3c2u) { target=s->pc; goto dispatch; }
goto P_0c05f3c2;
P_0c05f3c0: /* original 64e3, guest PC 0x0c05f3c0 */
if(!s->budget--) { s->failed_pc=0x0c05f3c0u; return 0; }
r[4]=r[14];
goto P_0c05f3c2;
P_0c05f3c2: /* original 3dcc, guest PC 0x0c05f3c2 */
if(!s->budget--) { s->failed_pc=0x0c05f3c2u; return 0; }
r[13]+=r[12];
goto P_0c05f3c4;
P_0c05f3c4: /* original 937d, guest PC 0x0c05f3c4 */
if(!s->budget--) { s->failed_pc=0x0c05f3c4u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c05f4c2u,2);
goto P_0c05f3c6;
P_0c05f3c6: /* original 66a3, guest PC 0x0c05f3c6 */
if(!s->budget--) { s->failed_pc=0x0c05f3c6u; return 0; }
r[6]=r[10];
goto P_0c05f3c8;
P_0c05f3c8: /* original d240, guest PC 0x0c05f3c8 */
if(!s->budget--) { s->failed_pc=0x0c05f3c8u; return 0; }
r[2]=read(ram,0x0c05f4ccu,4);
goto P_0c05f3ca;
P_0c05f3ca: /* original 7f08, guest PC 0x0c05f3ca */
if(!s->budget--) { s->failed_pc=0x0c05f3cau; return 0; }
r[15]+=0x00000008u;
goto P_0c05f3cc;
P_0c05f3cc: /* original 4f26, guest PC 0x0c05f3cc */
if(!s->budget--) { s->failed_pc=0x0c05f3ccu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c05f3ce;
P_0c05f3ce: /* original 3e3c, guest PC 0x0c05f3ce */
if(!s->budget--) { s->failed_pc=0x0c05f3ceu; return 0; }
r[14]+=r[3];
goto P_0c05f3d0;
P_0c05f3d0: /* original 6af6, guest PC 0x0c05f3d0 */
if(!s->budget--) { s->failed_pc=0x0c05f3d0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c05f3d2;
P_0c05f3d2: /* original 65d3, guest PC 0x0c05f3d2 */
if(!s->budget--) { s->failed_pc=0x0c05f3d2u; return 0; }
r[5]=r[13];
goto P_0c05f3d4;
P_0c05f3d4: /* original 6cf6, guest PC 0x0c05f3d4 */
if(!s->budget--) { s->failed_pc=0x0c05f3d4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c05f3d6;
P_0c05f3d6: /* original 64e3, guest PC 0x0c05f3d6 */
if(!s->budget--) { s->failed_pc=0x0c05f3d6u; return 0; }
r[4]=r[14];
goto P_0c05f3d8;
P_0c05f3d8: /* original 6df6, guest PC 0x0c05f3d8 */
if(!s->budget--) { s->failed_pc=0x0c05f3d8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c05f3da;
P_0c05f3da: /* original 422b, guest PC 0x0c05f3da */
if(!s->budget--) { s->failed_pc=0x0c05f3dau; return 0; }
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
P_0c05f3dc: /* original 6ef6, guest PC 0x0c05f3dc */
if(!s->budget--) { s->failed_pc=0x0c05f3dcu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c05f3deu,s,ram);
P_0c060d62: /* original 4f22, guest PC 0x0c060d62 */
if(!s->budget--) { s->failed_pc=0x0c060d62u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c060d64;
P_0c060d64: /* original d332, guest PC 0x0c060d64 */
if(!s->budget--) { s->failed_pc=0x0c060d64u; return 0; }
r[3]=read(ram,0x0c060e30u,4);
goto P_0c060d66;
P_0c060d66: /* original 7ffc, guest PC 0x0c060d66 */
if(!s->budget--) { s->failed_pc=0x0c060d66u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c060d68;
P_0c060d68: /* original d232, guest PC 0x0c060d68 */
if(!s->budget--) { s->failed_pc=0x0c060d68u; return 0; }
r[2]=read(ram,0x0c060e34u,4);
goto P_0c060d6a;
P_0c060d6a: /* original 2f52, guest PC 0x0c060d6a */
if(!s->budget--) { s->failed_pc=0x0c060d6au; return 0; }
write(ram,r[15],r[5],4);
goto P_0c060d6c;
P_0c060d6c: /* original 420b, guest PC 0x0c060d6c */
if(!s->budget--) { s->failed_pc=0x0c060d6cu; return 0; }
target=r[2];
r[16]=code_base|0x0c060d70u;
r[5]+=r[3];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c060d70u) { target=s->pc; goto dispatch; }
goto P_0c060d70;
P_0c060d6e: /* original 353c, guest PC 0x0c060d6e */
if(!s->budget--) { s->failed_pc=0x0c060d6eu; return 0; }
r[5]+=r[3];
goto P_0c060d70;
P_0c060d70: /* original 7f04, guest PC 0x0c060d70 */
if(!s->budget--) { s->failed_pc=0x0c060d70u; return 0; }
r[15]+=0x00000004u;
goto P_0c060d72;
P_0c060d72: /* original 4f26, guest PC 0x0c060d72 */
if(!s->budget--) { s->failed_pc=0x0c060d72u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c060d74;
P_0c060d74: /* original 000b, guest PC 0x0c060d74 */
if(!s->budget--) { s->failed_pc=0x0c060d74u; return 0; }
target=r[16];
r[0]=0x00000001u;
s->pc=target; return ram->oob==0;
P_0c060d76: /* original e001, guest PC 0x0c060d76 */
if(!s->budget--) { s->failed_pc=0x0c060d76u; return 0; }
r[0]=0x00000001u;
return vf3_matrix_family(0x0c060d78u,s,ram);
P_0c060e50: /* original 4f22, guest PC 0x0c060e50 */
if(!s->budget--) { s->failed_pc=0x0c060e50u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c060e52;
P_0c060e52: /* original 7ff4, guest PC 0x0c060e52 */
if(!s->budget--) { s->failed_pc=0x0c060e52u; return 0; }
r[15]+=0xfffffff4u;
goto P_0c060e54;
P_0c060e54: /* original d328, guest PC 0x0c060e54 */
if(!s->budget--) { s->failed_pc=0x0c060e54u; return 0; }
r[3]=read(ram,0x0c060ef8u,4);
goto P_0c060e56;
P_0c060e56: /* original 2f42, guest PC 0x0c060e56 */
if(!s->budget--) { s->failed_pc=0x0c060e56u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c060e58;
P_0c060e58: /* original 1f52, guest PC 0x0c060e58 */
if(!s->budget--) { s->failed_pc=0x0c060e58u; return 0; }
write(ram,r[15]+8,r[5],4);
goto P_0c060e5a;
P_0c060e5a: /* original 1f61, guest PC 0x0c060e5a */
if(!s->budget--) { s->failed_pc=0x0c060e5au; return 0; }
write(ram,r[15]+4,r[6],4);
goto P_0c060e5c;
P_0c060e5c: /* original 55f2, guest PC 0x0c060e5c */
if(!s->budget--) { s->failed_pc=0x0c060e5cu; return 0; }
r[5]=read(ram,r[15]+8,4);
goto P_0c060e5e;
P_0c060e5e: /* original 353c, guest PC 0x0c060e5e */
if(!s->budget--) { s->failed_pc=0x0c060e5eu; return 0; }
r[5]+=r[3];
goto P_0c060e60;
P_0c060e60: /* original d226, guest PC 0x0c060e60 */
if(!s->budget--) { s->failed_pc=0x0c060e60u; return 0; }
r[2]=read(ram,0x0c060efcu,4);
goto P_0c060e62;
P_0c060e62: /* original 420b, guest PC 0x0c060e62 */
if(!s->budget--) { s->failed_pc=0x0c060e62u; return 0; }
target=r[2];
r[16]=code_base|0x0c060e66u;
tmp=read(ram,r[15],4);
r[4]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c060e66u) { target=s->pc; goto dispatch; }
goto P_0c060e66;
P_0c060e64: /* original 64f2, guest PC 0x0c060e64 */
if(!s->budget--) { s->failed_pc=0x0c060e64u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c060e66;
P_0c060e66: /* original 55f1, guest PC 0x0c060e66 */
if(!s->budget--) { s->failed_pc=0x0c060e66u; return 0; }
r[5]=read(ram,r[15]+4,4);
goto P_0c060e68;
P_0c060e68: /* original bf59, guest PC 0x0c060e68 */
if(!s->budget--) { s->failed_pc=0x0c060e68u; return 0; }
target=0x0c060d1eu; r[16]=code_base|0x0c060e6cu;
tmp=read(ram,r[15],4);
r[4]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c060e6cu) { target=s->pc; goto dispatch; }
goto P_0c060e6c;
P_0c060e6a: /* original 64f2, guest PC 0x0c060e6a */
if(!s->budget--) { s->failed_pc=0x0c060e6au; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c060e6c;
P_0c060e6c: /* original 7f0c, guest PC 0x0c060e6c */
if(!s->budget--) { s->failed_pc=0x0c060e6cu; return 0; }
r[15]+=0x0000000cu;
goto P_0c060e6e;
P_0c060e6e: /* original 4f26, guest PC 0x0c060e6e */
if(!s->budget--) { s->failed_pc=0x0c060e6eu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c060e70;
P_0c060e70: /* original 000b, guest PC 0x0c060e70 */
if(!s->budget--) { s->failed_pc=0x0c060e70u; return 0; }
target=r[16];
r[0]=0x00000001u;
s->pc=target; return ram->oob==0;
P_0c060e72: /* original e001, guest PC 0x0c060e72 */
if(!s->budget--) { s->failed_pc=0x0c060e72u; return 0; }
r[0]=0x00000001u;
return vf3_matrix_family(0x0c060e74u,s,ram);
P_0c07ae9c: /* original 4f22, guest PC 0x0c07ae9c */
if(!s->budget--) { s->failed_pc=0x0c07ae9cu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c07ae9e;
P_0c07ae9e: /* original 6121, guest PC 0x0c07ae9e */
if(!s->budget--) { s->failed_pc=0x0c07ae9eu; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[2],2);
r[1]=tmp;
goto P_0c07aea0;
P_0c07aea0: /* original d328, guest PC 0x0c07aea0 */
if(!s->budget--) { s->failed_pc=0x0c07aea0u; return 0; }
r[3]=read(ram,0x0c07af44u,4);
goto P_0c07aea2;
P_0c07aea2: /* original 2118, guest PC 0x0c07aea2 */
if(!s->budget--) { s->failed_pc=0x0c07aea2u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[1])==0)!=0);
goto P_0c07aea4;
P_0c07aea4: /* original 8f0d, guest PC 0x0c07aea4 */
if(!s->budget--) { s->failed_pc=0x0c07aea4u; return 0; }
cond=r[17]&1u;
tmp=read(ram,r[3],4);
r[14]=tmp;
if(!cond) { goto P_0c07aec2; }
goto P_0c07aea8;
P_0c07aea6: /* original 6e32, guest PC 0x0c07aea6 */
if(!s->budget--) { s->failed_pc=0x0c07aea6u; return 0; }
tmp=read(ram,r[3],4);
r[14]=tmp;
goto P_0c07aea8;
P_0c07aea8: /* original d12a, guest PC 0x0c07aea8 */
if(!s->budget--) { s->failed_pc=0x0c07aea8u; return 0; }
r[1]=read(ram,0x0c07af54u,4);
goto P_0c07aeaa;
P_0c07aeaa: /* original 65e3, guest PC 0x0c07aeaa */
if(!s->budget--) { s->failed_pc=0x0c07aeaau; return 0; }
r[5]=r[14];
goto P_0c07aeac;
P_0c07aeac: /* original 410b, guest PC 0x0c07aeac */
if(!s->budget--) { s->failed_pc=0x0c07aeacu; return 0; }
target=r[1];
r[16]=code_base|0x0c07aeb0u;
r[4]=0x0000000cu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07aeb0u) { target=s->pc; goto dispatch; }
goto P_0c07aeb0;
P_0c07aeae: /* original e40c, guest PC 0x0c07aeae */
if(!s->budget--) { s->failed_pc=0x0c07aeaeu; return 0; }
r[4]=0x0000000cu;
goto P_0c07aeb0;
P_0c07aeb0: /* original d329, guest PC 0x0c07aeb0 */
if(!s->budget--) { s->failed_pc=0x0c07aeb0u; return 0; }
r[3]=read(ram,0x0c07af58u,4);
goto P_0c07aeb2;
P_0c07aeb2: /* original 430b, guest PC 0x0c07aeb2 */
if(!s->budget--) { s->failed_pc=0x0c07aeb2u; return 0; }
target=r[3];
r[16]=code_base|0x0c07aeb6u;
r[4]=0x0000001bu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07aeb6u) { target=s->pc; goto dispatch; }
goto P_0c07aeb6;
P_0c07aeb4: /* original e41b, guest PC 0x0c07aeb4 */
if(!s->budget--) { s->failed_pc=0x0c07aeb4u; return 0; }
r[4]=0x0000001bu;
goto P_0c07aeb6;
P_0c07aeb6: /* original d429, guest PC 0x0c07aeb6 */
if(!s->budget--) { s->failed_pc=0x0c07aeb6u; return 0; }
r[4]=read(ram,0x0c07af5cu,4);
goto P_0c07aeb8;
P_0c07aeb8: /* original bca5, guest PC 0x0c07aeb8 */
if(!s->budget--) { s->failed_pc=0x0c07aeb8u; return 0; }
target=0x0c07a806u; r[16]=code_base|0x0c07aebcu;
r[5]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07aebcu) { target=s->pc; goto dispatch; }
goto P_0c07aebc;
P_0c07aeba: /* original 65e3, guest PC 0x0c07aeba */
if(!s->budget--) { s->failed_pc=0x0c07aebau; return 0; }
r[5]=r[14];
goto P_0c07aebc;
P_0c07aebc: /* original d324, guest PC 0x0c07aebc */
if(!s->budget--) { s->failed_pc=0x0c07aebcu; return 0; }
r[3]=read(ram,0x0c07af50u,4);
goto P_0c07aebe;
P_0c07aebe: /* original e21b, guest PC 0x0c07aebe */
if(!s->budget--) { s->failed_pc=0x0c07aebeu; return 0; }
r[2]=0x0000001bu;
goto P_0c07aec0;
P_0c07aec0: /* original 2321, guest PC 0x0c07aec0 */
if(!s->budget--) { s->failed_pc=0x0c07aec0u; return 0; }
write(ram,r[3],r[2],2);
goto P_0c07aec2;
P_0c07aec2: /* original 4f26, guest PC 0x0c07aec2 */
if(!s->budget--) { s->failed_pc=0x0c07aec2u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c07aec4;
P_0c07aec4: /* original 000b, guest PC 0x0c07aec4 */
if(!s->budget--) { s->failed_pc=0x0c07aec4u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c07aec6: /* original 6ef6, guest PC 0x0c07aec6 */
if(!s->budget--) { s->failed_pc=0x0c07aec6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c07aec8u,s,ram);
P_0c0a6642: /* original 4f22, guest PC 0x0c0a6642 */
if(!s->budget--) { s->failed_pc=0x0c0a6642u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0a6644;
P_0c0a6644: /* original 90a1, guest PC 0x0c0a6644 */
if(!s->budget--) { s->failed_pc=0x0c0a6644u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a678au,2);
goto P_0c0a6646;
P_0c0a6646: /* original 3f0c, guest PC 0x0c0a6646 */
if(!s->budget--) { s->failed_pc=0x0c0a6646u; return 0; }
r[15]+=r[0];
goto P_0c0a6648;
P_0c0a6648: /* original 2f42, guest PC 0x0c0a6648 */
if(!s->budget--) { s->failed_pc=0x0c0a6648u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c0a664a;
P_0c0a664a: /* original 1f52, guest PC 0x0c0a664a */
if(!s->budget--) { s->failed_pc=0x0c0a664au; return 0; }
write(ram,r[15]+8,r[5],4);
goto P_0c0a664c;
P_0c0a664c: /* original 1f63, guest PC 0x0c0a664c */
if(!s->budget--) { s->failed_pc=0x0c0a664cu; return 0; }
write(ram,r[15]+12,r[6],4);
goto P_0c0a664e;
P_0c0a664e: /* original 1f71, guest PC 0x0c0a664e */
if(!s->budget--) { s->failed_pc=0x0c0a664eu; return 0; }
write(ram,r[15]+4,r[7],4);
goto P_0c0a6650;
P_0c0a6650: /* original 909c, guest PC 0x0c0a6650 */
if(!s->budget--) { s->failed_pc=0x0c0a6650u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a678cu,2);
goto P_0c0a6652;
P_0c0a6652: /* original d352, guest PC 0x0c0a6652 */
if(!s->budget--) { s->failed_pc=0x0c0a6652u; return 0; }
r[3]=read(ram,0x0c0a679cu,4);
goto P_0c0a6654;
P_0c0a6654: /* original 0afe, guest PC 0x0c0a6654 */
if(!s->budget--) { s->failed_pc=0x0c0a6654u; return 0; }
r[10]=read(ram,r[15]+r[0],4);
goto P_0c0a6656;
P_0c0a6656: /* original 430b, guest PC 0x0c0a6656 */
if(!s->budget--) { s->failed_pc=0x0c0a6656u; return 0; }
target=r[3];
r[16]=code_base|0x0c0a665au;
r[4]=0x00000000u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a665au) { target=s->pc; goto dispatch; }
goto P_0c0a665a;
P_0c0a6658: /* original e400, guest PC 0x0c0a6658 */
if(!s->budget--) { s->failed_pc=0x0c0a6658u; return 0; }
r[4]=0x00000000u;
goto P_0c0a665a;
P_0c0a665a: /* original 62f2, guest PC 0x0c0a665a */
if(!s->budget--) { s->failed_pc=0x0c0a665au; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c0a665c;
P_0c0a665c: /* original fe8d, guest PC 0x0c0a665c */
if(!s->budget--) { s->failed_pc=0x0c0a665cu; return 0; }
fr[14]=0;
goto P_0c0a665e;
P_0c0a665e: /* original 1f24, guest PC 0x0c0a665e */
if(!s->budget--) { s->failed_pc=0x0c0a665eu; return 0; }
write(ram,r[15]+16,r[2],4);
goto P_0c0a6660;
P_0c0a6660: /* original 53f2, guest PC 0x0c0a6660 */
if(!s->budget--) { s->failed_pc=0x0c0a6660u; return 0; }
r[3]=read(ram,r[15]+8,4);
goto P_0c0a6662;
P_0c0a6662: /* original 2f32, guest PC 0x0c0a6662 */
if(!s->budget--) { s->failed_pc=0x0c0a6662u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c0a6664;
P_0c0a6664: /* original 5cf3, guest PC 0x0c0a6664 */
if(!s->budget--) { s->failed_pc=0x0c0a6664u; return 0; }
r[12]=read(ram,r[15]+12,4);
goto P_0c0a6666;
P_0c0a6666: /* original d34e, guest PC 0x0c0a6666 */
if(!s->budget--) { s->failed_pc=0x0c0a6666u; return 0; }
r[3]=read(ram,0x0c0a67a0u,4);
goto P_0c0a6668;
P_0c0a6668: /* original 64c2, guest PC 0x0c0a6668 */
if(!s->budget--) { s->failed_pc=0x0c0a6668u; return 0; }
tmp=read(ram,r[12],4);
r[4]=tmp;
goto P_0c0a666a;
P_0c0a666a: /* original 684c, guest PC 0x0c0a666a */
if(!s->budget--) { s->failed_pc=0x0c0a666au; return 0; }
r[8]=r[4]&255u;
goto P_0c0a666c;
P_0c0a666c: /* original 54f4, guest PC 0x0c0a666c */
if(!s->budget--) { s->failed_pc=0x0c0a666cu; return 0; }
r[4]=read(ram,r[15]+16,4);
goto P_0c0a666e;
P_0c0a666e: /* original 430b, guest PC 0x0c0a666e */
if(!s->budget--) { s->failed_pc=0x0c0a666eu; return 0; }
target=r[3];
r[16]=code_base|0x0c0a6672u;
r[4]+=0x00000010u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a6672u) { target=s->pc; goto dispatch; }
goto P_0c0a6672;
P_0c0a6670: /* original 7410, guest PC 0x0c0a6670 */
if(!s->budget--) { s->failed_pc=0x0c0a6670u; return 0; }
r[4]+=0x00000010u;
goto P_0c0a6672;
P_0c0a6672: /* original d24a, guest PC 0x0c0a6672 */
if(!s->budget--) { s->failed_pc=0x0c0a6672u; return 0; }
r[2]=read(ram,0x0c0a679cu,4);
goto P_0c0a6674;
P_0c0a6674: /* original 420b, guest PC 0x0c0a6674 */
if(!s->budget--) { s->failed_pc=0x0c0a6674u; return 0; }
target=r[2];
r[16]=code_base|0x0c0a6678u;
r[4]=0x00000000u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a6678u) { target=s->pc; goto dispatch; }
goto P_0c0a6678;
P_0c0a6676: /* original e400, guest PC 0x0c0a6676 */
if(!s->budget--) { s->failed_pc=0x0c0a6676u; return 0; }
r[4]=0x00000000u;
goto P_0c0a6678;
P_0c0a6678: /* original d34a, guest PC 0x0c0a6678 */
if(!s->budget--) { s->failed_pc=0x0c0a6678u; return 0; }
r[3]=read(ram,0x0c0a67a4u,4);
goto P_0c0a667a;
P_0c0a667a: /* original 430b, guest PC 0x0c0a667a */
if(!s->budget--) { s->failed_pc=0x0c0a667au; return 0; }
target=r[3];
r[16]=code_base|0x0c0a667eu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a667eu) { target=s->pc; goto dispatch; }
goto P_0c0a667e;
P_0c0a667c: /* original 0009, guest PC 0x0c0a667c */
if(!s->budget--) { s->failed_pc=0x0c0a667cu; return 0; }
goto P_0c0a667e;
P_0c0a667e: /* original 9586, guest PC 0x0c0a667e */
if(!s->budget--) { s->failed_pc=0x0c0a667eu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a678eu,2);
goto P_0c0a6680;
P_0c0a6680: /* original d349, guest PC 0x0c0a6680 */
if(!s->budget--) { s->failed_pc=0x0c0a6680u; return 0; }
r[3]=read(ram,0x0c0a67a8u,4);
goto P_0c0a6682;
P_0c0a6682: /* original 35fc, guest PC 0x0c0a6682 */
if(!s->budget--) { s->failed_pc=0x0c0a6682u; return 0; }
r[5]+=r[15];
goto P_0c0a6684;
P_0c0a6684: /* original 430b, guest PC 0x0c0a6684 */
if(!s->budget--) { s->failed_pc=0x0c0a6684u; return 0; }
target=r[3];
r[16]=code_base|0x0c0a6688u;
tmp=read(ram,r[15],4);
r[4]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a6688u) { target=s->pc; goto dispatch; }
goto P_0c0a6688;
P_0c0a6686: /* original 64f2, guest PC 0x0c0a6686 */
if(!s->budget--) { s->failed_pc=0x0c0a6686u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c0a6688;
P_0c0a6688: /* original d248, guest PC 0x0c0a6688 */
if(!s->budget--) { s->failed_pc=0x0c0a6688u; return 0; }
r[2]=read(ram,0x0c0a67acu,4);
goto P_0c0a668a;
P_0c0a668a: /* original 420b, guest PC 0x0c0a668a */
if(!s->budget--) { s->failed_pc=0x0c0a668au; return 0; }
target=r[2];
r[16]=code_base|0x0c0a668eu;
r[4]=0x00000001u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a668eu) { target=s->pc; goto dispatch; }
goto P_0c0a668e;
P_0c0a668c: /* original e401, guest PC 0x0c0a668c */
if(!s->budget--) { s->failed_pc=0x0c0a668cu; return 0; }
r[4]=0x00000001u;
goto P_0c0a668e;
P_0c0a668e: /* original 69f3, guest PC 0x0c0a668e */
if(!s->budget--) { s->failed_pc=0x0c0a668eu; return 0; }
r[9]=r[15];
goto P_0c0a6690;
P_0c0a6690: /* original 7918, guest PC 0x0c0a6690 */
if(!s->budget--) { s->failed_pc=0x0c0a6690u; return 0; }
r[9]+=0x00000018u;
goto P_0c0a6692;
P_0c0a6692: /* original ee00, guest PC 0x0c0a6692 */
if(!s->budget--) { s->failed_pc=0x0c0a6692u; return 0; }
r[14]=0x00000000u;
goto P_0c0a6694;
P_0c0a6694: /* original 6dc3, guest PC 0x0c0a6694 */
if(!s->budget--) { s->failed_pc=0x0c0a6694u; return 0; }
r[13]=r[12];
goto P_0c0a6696;
P_0c0a6696: /* original 6be3, guest PC 0x0c0a6696 */
if(!s->budget--) { s->failed_pc=0x0c0a6696u; return 0; }
r[11]=r[14];
goto P_0c0a6698;
P_0c0a6698: /* original 7d04, guest PC 0x0c0a6698 */
if(!s->budget--) { s->failed_pc=0x0c0a6698u; return 0; }
r[13]+=0x00000004u;
goto P_0c0a669a;
P_0c0a669a: /* original 2f92, guest PC 0x0c0a669a */
if(!s->budget--) { s->failed_pc=0x0c0a669au; return 0; }
write(ram,r[15],r[9],4);
goto P_0c0a669c;
P_0c0a669c: /* original ffec, guest PC 0x0c0a669c */
if(!s->budget--) { s->failed_pc=0x0c0a669cu; return 0; }
vf3_matrix_move(s,15,14);
goto P_0c0a669e;
P_0c0a669e: /* original 9077, guest PC 0x0c0a669e */
if(!s->budget--) { s->failed_pc=0x0c0a669eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a6790u,2);
goto P_0c0a66a0;
P_0c0a66a0: /* original 63bb, guest PC 0x0c0a66a0 */
if(!s->budget--) { s->failed_pc=0x0c0a66a0u; return 0; }
r[3]=0u-r[11];
goto P_0c0a66a2;
P_0c0a66a2: /* original f3d8, guest PC 0x0c0a66a2 */
if(!s->budget--) { s->failed_pc=0x0c0a66a2u; return 0; }
vf3_matrix_load(s,ram,3,r[13]);
goto P_0c0a66a4;
P_0c0a66a4: /* original ff37, guest PC 0x0c0a66a4 */
if(!s->budget--) { s->failed_pc=0x0c0a66a4u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0a66a6;
P_0c0a66a6: /* original e004, guest PC 0x0c0a66a6 */
if(!s->budget--) { s->failed_pc=0x0c0a66a6u; return 0; }
r[0]=0x00000004u;
goto P_0c0a66a8;
P_0c0a66a8: /* original f3d6, guest PC 0x0c0a66a8 */
if(!s->budget--) { s->failed_pc=0x0c0a66a8u; return 0; }
vf3_matrix_load(s,ram,3,r[13]+r[0]);
goto P_0c0a66aa;
P_0c0a66aa: /* original 9072, guest PC 0x0c0a66aa */
if(!s->budget--) { s->failed_pc=0x0c0a66aau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a6792u,2);
goto P_0c0a66ac;
P_0c0a66ac: /* original ff37, guest PC 0x0c0a66ac */
if(!s->budget--) { s->failed_pc=0x0c0a66acu; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0a66ae;
P_0c0a66ae: /* original e008, guest PC 0x0c0a66ae */
if(!s->budget--) { s->failed_pc=0x0c0a66aeu; return 0; }
r[0]=0x00000008u;
goto P_0c0a66b0;
P_0c0a66b0: /* original f3d6, guest PC 0x0c0a66b0 */
if(!s->budget--) { s->failed_pc=0x0c0a66b0u; return 0; }
vf3_matrix_load(s,ram,3,r[13]+r[0]);
goto P_0c0a66b2;
P_0c0a66b2: /* original 906f, guest PC 0x0c0a66b2 */
if(!s->budget--) { s->failed_pc=0x0c0a66b2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a6794u,2);
goto P_0c0a66b4;
P_0c0a66b4: /* original ff37, guest PC 0x0c0a66b4 */
if(!s->budget--) { s->failed_pc=0x0c0a66b4u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0a66b6;
P_0c0a66b6: /* original d23e, guest PC 0x0c0a66b6 */
if(!s->budget--) { s->failed_pc=0x0c0a66b6u; return 0; }
r[2]=read(ram,0x0c0a67b0u,4);
goto P_0c0a66b8;
P_0c0a66b8: /* original 51f1, guest PC 0x0c0a66b8 */
if(!s->budget--) { s->failed_pc=0x0c0a66b8u; return 0; }
r[1]=read(ram,r[15]+4,4);
goto P_0c0a66ba;
P_0c0a66ba: /* original 423d, guest PC 0x0c0a66ba */
if(!s->budget--) { s->failed_pc=0x0c0a66bau; return 0; }
r[2]=(r[3]&0x80000000u)?((r[3]&31u)?r[2]>>((-r[3])&31u):0):r[2]<<(r[3]&31u);
goto P_0c0a66bc;
P_0c0a66bc: /* original 2218, guest PC 0x0c0a66bc */
if(!s->budget--) { s->failed_pc=0x0c0a66bcu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[1])==0)!=0);
goto P_0c0a66be;
P_0c0a66be: /* original 8d18, guest PC 0x0c0a66be */
if(!s->budget--) { s->failed_pc=0x0c0a66beu; return 0; }
cond=r[17]&1u;
r[13]+=0x0000000cu;
if(cond) { goto P_0c0a66f2; }
goto P_0c0a66c2;
P_0c0a66c0: /* original 7d0c, guest PC 0x0c0a66c0 */
if(!s->budget--) { s->failed_pc=0x0c0a66c0u; return 0; }
r[13]+=0x0000000cu;
goto P_0c0a66c2;
P_0c0a66c2: /* original 9564, guest PC 0x0c0a66c2 */
if(!s->budget--) { s->failed_pc=0x0c0a66c2u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a678eu,2);
goto P_0c0a66c4;
P_0c0a66c4: /* original 9464, guest PC 0x0c0a66c4 */
if(!s->budget--) { s->failed_pc=0x0c0a66c4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a6790u,2);
goto P_0c0a66c6;
P_0c0a66c6: /* original d23b, guest PC 0x0c0a66c6 */
if(!s->budget--) { s->failed_pc=0x0c0a66c6u; return 0; }
r[2]=read(ram,0x0c0a67b4u,4);
goto P_0c0a66c8;
P_0c0a66c8: /* original 35fc, guest PC 0x0c0a66c8 */
if(!s->budget--) { s->failed_pc=0x0c0a66c8u; return 0; }
r[5]+=r[15];
goto P_0c0a66ca;
P_0c0a66ca: /* original 420b, guest PC 0x0c0a66ca */
if(!s->budget--) { s->failed_pc=0x0c0a66cau; return 0; }
target=r[2];
r[16]=code_base|0x0c0a66ceu;
r[4]+=r[15];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a66ceu) { target=s->pc; goto dispatch; }
goto P_0c0a66ce;
P_0c0a66cc: /* original 34fc, guest PC 0x0c0a66cc */
if(!s->budget--) { s->failed_pc=0x0c0a66ccu; return 0; }
r[4]+=r[15];
goto P_0c0a66ce;
P_0c0a66ce: /* original 905e, guest PC 0x0c0a66ce */
if(!s->budget--) { s->failed_pc=0x0c0a66ceu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a678eu,2);
goto P_0c0a66d0;
P_0c0a66d0: /* original f40c, guest PC 0x0c0a66d0 */
if(!s->budget--) { s->failed_pc=0x0c0a66d0u; return 0; }
vf3_matrix_move(s,4,0);
goto P_0c0a66d2;
P_0c0a66d2: /* original fdf6, guest PC 0x0c0a66d2 */
if(!s->budget--) { s->failed_pc=0x0c0a66d2u; return 0; }
vf3_matrix_load(s,ram,13,r[15]+r[0]);
goto P_0c0a66d4;
P_0c0a66d4: /* original 905f, guest PC 0x0c0a66d4 */
if(!s->budget--) { s->failed_pc=0x0c0a66d4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a6796u,2);
goto P_0c0a66d6;
P_0c0a66d6: /* original fcf6, guest PC 0x0c0a66d6 */
if(!s->budget--) { s->failed_pc=0x0c0a66d6u; return 0; }
vf3_matrix_load(s,ram,12,r[15]+r[0]);
goto P_0c0a66d8;
P_0c0a66d8: /* original 905e, guest PC 0x0c0a66d8 */
if(!s->budget--) { s->failed_pc=0x0c0a66d8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a6798u,2);
goto P_0c0a66da;
P_0c0a66da: /* original f3f6, guest PC 0x0c0a66da */
if(!s->budget--) { s->failed_pc=0x0c0a66dau; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0a66dc;
P_0c0a66dc: /* original e014, guest PC 0x0c0a66dc */
if(!s->budget--) { s->failed_pc=0x0c0a66dcu; return 0; }
r[0]=0x00000014u;
goto P_0c0a66de;
P_0c0a66de: /* original ff37, guest PC 0x0c0a66de */
if(!s->budget--) { s->failed_pc=0x0c0a66deu; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0a66e0;
P_0c0a66e0: /* original f38d, guest PC 0x0c0a66e0 */
if(!s->budget--) { s->failed_pc=0x0c0a66e0u; return 0; }
fr[3]=0;
goto P_0c0a66e2;
P_0c0a66e2: /* original f345, guest PC 0x0c0a66e2 */
if(!s->budget--) { s->failed_pc=0x0c0a66e2u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[4]))!=0);
goto P_0c0a66e4;
P_0c0a66e4: /* original 8b05, guest PC 0x0c0a66e4 */
if(!s->budget--) { s->failed_pc=0x0c0a66e4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a66f2; }
goto P_0c0a66e6;
P_0c0a66e6: /* original ff40, guest PC 0x0c0a66e6 */
if(!s->budget--) { s->failed_pc=0x0c0a66e6u; return 0; }
fr[15]=vf3_fpu_binary(fr[15],fr[4],r[18],'+');
goto P_0c0a66e8;
P_0c0a66e8: /* original e004, guest PC 0x0c0a66e8 */
if(!s->budget--) { s->failed_pc=0x0c0a66e8u; return 0; }
r[0]=0x00000004u;
goto P_0c0a66ea;
P_0c0a66ea: /* original 29b2, guest PC 0x0c0a66ea */
if(!s->budget--) { s->failed_pc=0x0c0a66eau; return 0; }
write(ram,r[9],r[11],4);
goto P_0c0a66ec;
P_0c0a66ec: /* original 7e01, guest PC 0x0c0a66ec */
if(!s->budget--) { s->failed_pc=0x0c0a66ecu; return 0; }
r[14]+=0x00000001u;
goto P_0c0a66ee;
P_0c0a66ee: /* original f947, guest PC 0x0c0a66ee */
if(!s->budget--) { s->failed_pc=0x0c0a66eeu; return 0; }
vf3_matrix_store(s,ram,4,r[9]+r[0]);
goto P_0c0a66f0;
P_0c0a66f0: /* original 7908, guest PC 0x0c0a66f0 */
if(!s->budget--) { s->failed_pc=0x0c0a66f0u; return 0; }
r[9]+=0x00000008u;
goto P_0c0a66f2;
P_0c0a66f2: /* original 4810, guest PC 0x0c0a66f2 */
if(!s->budget--) { s->failed_pc=0x0c0a66f2u; return 0; }
--r[8];
r[17]=(r[17]&~1u)|((r[8]==0)!=0);
goto P_0c0a66f4;
P_0c0a66f4: /* original 8fd3, guest PC 0x0c0a66f4 */
if(!s->budget--) { s->failed_pc=0x0c0a66f4u; return 0; }
cond=r[17]&1u;
r[11]+=0x00000001u;
if(!cond) { goto P_0c0a669e; }
goto P_0c0a66f8;
P_0c0a66f6: /* original 7b01, guest PC 0x0c0a66f6 */
if(!s->budget--) { s->failed_pc=0x0c0a66f6u; return 0; }
r[11]+=0x00000001u;
goto P_0c0a66f8;
P_0c0a66f8: /* original 2ee8, guest PC 0x0c0a66f8 */
if(!s->budget--) { s->failed_pc=0x0c0a66f8u; return 0; }
r[17]=(r[17]&~1u)|(((r[14]&r[14])==0)!=0);
goto P_0c0a66fa;
P_0c0a66fa: /* original 892b, guest PC 0x0c0a66fa */
if(!s->budget--) { s->failed_pc=0x0c0a66fau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a6754; }
goto P_0c0a66fc;
P_0c0a66fc: /* original f3fc, guest PC 0x0c0a66fc */
if(!s->budget--) { s->failed_pc=0x0c0a66fcu; return 0; }
vf3_matrix_move(s,3,15);
goto P_0c0a66fe;
P_0c0a66fe: /* original ff9d, guest PC 0x0c0a66fe */
if(!s->budget--) { s->failed_pc=0x0c0a66feu; return 0; }
fr[15]=0x3f800000u;
goto P_0c0a6700;
P_0c0a6700: /* original ff33, guest PC 0x0c0a6700 */
if(!s->budget--) { s->failed_pc=0x0c0a6700u; return 0; }
fr[15]=vf3_fpu_binary(fr[15],fr[3],r[18],'/');
goto P_0c0a6702;
P_0c0a6702: /* original 64f2, guest PC 0x0c0a6702 */
if(!s->budget--) { s->failed_pc=0x0c0a6702u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c0a6704;
P_0c0a6704: /* original f7ec, guest PC 0x0c0a6704 */
if(!s->budget--) { s->failed_pc=0x0c0a6704u; return 0; }
vf3_matrix_move(s,7,14);
goto P_0c0a6706;
P_0c0a6706: /* original f4ec, guest PC 0x0c0a6706 */
if(!s->budget--) { s->failed_pc=0x0c0a6706u; return 0; }
vf3_matrix_move(s,4,14);
goto P_0c0a6708;
P_0c0a6708: /* original f5ec, guest PC 0x0c0a6708 */
if(!s->budget--) { s->failed_pc=0x0c0a6708u; return 0; }
vf3_matrix_move(s,5,14);
goto P_0c0a670a;
P_0c0a670a: /* original 6742, guest PC 0x0c0a670a */
if(!s->budget--) { s->failed_pc=0x0c0a670au; return 0; }
tmp=read(ram,r[4],4);
r[7]=tmp;
goto P_0c0a670c;
P_0c0a670c: /* original 66c3, guest PC 0x0c0a670c */
if(!s->budget--) { s->failed_pc=0x0c0a670cu; return 0; }
r[6]=r[12];
goto P_0c0a670e;
P_0c0a670e: /* original e004, guest PC 0x0c0a670e */
if(!s->budget--) { s->failed_pc=0x0c0a670eu; return 0; }
r[0]=0x00000004u;
goto P_0c0a6710;
P_0c0a6710: /* original f34c, guest PC 0x0c0a6710 */
if(!s->budget--) { s->failed_pc=0x0c0a6710u; return 0; }
vf3_matrix_move(s,3,4);
goto P_0c0a6712;
P_0c0a6712: /* original 6573, guest PC 0x0c0a6712 */
if(!s->budget--) { s->failed_pc=0x0c0a6712u; return 0; }
r[5]=r[7];
goto P_0c0a6714;
P_0c0a6714: /* original 6373, guest PC 0x0c0a6714 */
if(!s->budget--) { s->failed_pc=0x0c0a6714u; return 0; }
r[3]=r[7];
goto P_0c0a6716;
P_0c0a6716: /* original 4500, guest PC 0x0c0a6716 */
if(!s->budget--) { s->failed_pc=0x0c0a6716u; return 0; }
r[17]=(r[17]&~1u)|((r[5]>>31)!=0);
r[5]<<=1;
goto P_0c0a6718;
P_0c0a6718: /* original f646, guest PC 0x0c0a6718 */
if(!s->budget--) { s->failed_pc=0x0c0a6718u; return 0; }
vf3_matrix_load(s,ram,6,r[4]+r[0]);
goto P_0c0a671a;
P_0c0a671a: /* original 353c, guest PC 0x0c0a671a */
if(!s->budget--) { s->failed_pc=0x0c0a671au; return 0; }
r[5]+=r[3];
goto P_0c0a671c;
P_0c0a671c: /* original f25c, guest PC 0x0c0a671c */
if(!s->budget--) { s->failed_pc=0x0c0a671cu; return 0; }
vf3_matrix_move(s,2,5);
goto P_0c0a671e;
P_0c0a671e: /* original 4508, guest PC 0x0c0a671e */
if(!s->budget--) { s->failed_pc=0x0c0a671eu; return 0; }
r[5]<<=2;
goto P_0c0a6720;
P_0c0a6720: /* original f06c, guest PC 0x0c0a6720 */
if(!s->budget--) { s->failed_pc=0x0c0a6720u; return 0; }
vf3_matrix_move(s,0,6);
goto P_0c0a6722;
P_0c0a6722: /* original 7604, guest PC 0x0c0a6722 */
if(!s->budget--) { s->failed_pc=0x0c0a6722u; return 0; }
r[6]+=0x00000004u;
goto P_0c0a6724;
P_0c0a6724: /* original 356c, guest PC 0x0c0a6724 */
if(!s->budget--) { s->failed_pc=0x0c0a6724u; return 0; }
r[5]+=r[6];
goto P_0c0a6726;
P_0c0a6726: /* original f958, guest PC 0x0c0a6726 */
if(!s->budget--) { s->failed_pc=0x0c0a6726u; return 0; }
vf3_matrix_load(s,ram,9,r[5]);
goto P_0c0a6728;
P_0c0a6728: /* original 4e10, guest PC 0x0c0a6728 */
if(!s->budget--) { s->failed_pc=0x0c0a6728u; return 0; }
--r[14];
r[17]=(r[17]&~1u)|((r[14]==0)!=0);
goto P_0c0a672a;
P_0c0a672a: /* original f856, guest PC 0x0c0a672a */
if(!s->budget--) { s->failed_pc=0x0c0a672au; return 0; }
vf3_matrix_load(s,ram,8,r[5]+r[0]);
goto P_0c0a672c;
P_0c0a672c: /* original e008, guest PC 0x0c0a672c */
if(!s->budget--) { s->failed_pc=0x0c0a672cu; return 0; }
r[0]=0x00000008u;
goto P_0c0a672e;
P_0c0a672e: /* original f39e, guest PC 0x0c0a672e */
if(!s->budget--) { s->failed_pc=0x0c0a672eu; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[9],fr[3],r[18]);
goto P_0c0a6730;
P_0c0a6730: /* original fa56, guest PC 0x0c0a6730 */
if(!s->budget--) { s->failed_pc=0x0c0a6730u; return 0; }
vf3_matrix_load(s,ram,10,r[5]+r[0]);
goto P_0c0a6732;
P_0c0a6732: /* original f28e, guest PC 0x0c0a6732 */
if(!s->budget--) { s->failed_pc=0x0c0a6732u; return 0; }
fr[2]=vf3_fpu_mac(fr[0],fr[8],fr[2],r[18]);
goto P_0c0a6734;
P_0c0a6734: /* original 7408, guest PC 0x0c0a6734 */
if(!s->budget--) { s->failed_pc=0x0c0a6734u; return 0; }
r[4]+=0x00000008u;
goto P_0c0a6736;
P_0c0a6736: /* original f43c, guest PC 0x0c0a6736 */
if(!s->budget--) { s->failed_pc=0x0c0a6736u; return 0; }
vf3_matrix_move(s,4,3);
goto P_0c0a6738;
P_0c0a6738: /* original f37c, guest PC 0x0c0a6738 */
if(!s->budget--) { s->failed_pc=0x0c0a6738u; return 0; }
vf3_matrix_move(s,3,7);
goto P_0c0a673a;
P_0c0a673a: /* original f3ae, guest PC 0x0c0a673a */
if(!s->budget--) { s->failed_pc=0x0c0a673au; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[10],fr[3],r[18]);
goto P_0c0a673c;
P_0c0a673c: /* original f52c, guest PC 0x0c0a673c */
if(!s->budget--) { s->failed_pc=0x0c0a673cu; return 0; }
vf3_matrix_move(s,5,2);
goto P_0c0a673e;
P_0c0a673e: /* original 8fe4, guest PC 0x0c0a673e */
if(!s->budget--) { s->failed_pc=0x0c0a673eu; return 0; }
cond=r[17]&1u;
vf3_matrix_move(s,7,3);
if(!cond) { goto P_0c0a670a; }
goto P_0c0a6742;
P_0c0a6740: /* original f73c, guest PC 0x0c0a6740 */
if(!s->budget--) { s->failed_pc=0x0c0a6740u; return 0; }
vf3_matrix_move(s,7,3);
goto P_0c0a6742;
P_0c0a6742: /* original fc5c, guest PC 0x0c0a6742 */
if(!s->budget--) { s->failed_pc=0x0c0a6742u; return 0; }
vf3_matrix_move(s,12,5);
goto P_0c0a6744;
P_0c0a6744: /* original f7f2, guest PC 0x0c0a6744 */
if(!s->budget--) { s->failed_pc=0x0c0a6744u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[15],r[18],'*');
goto P_0c0a6746;
P_0c0a6746: /* original fd4c, guest PC 0x0c0a6746 */
if(!s->budget--) { s->failed_pc=0x0c0a6746u; return 0; }
vf3_matrix_move(s,13,4);
goto P_0c0a6748;
P_0c0a6748: /* original fcf2, guest PC 0x0c0a6748 */
if(!s->budget--) { s->failed_pc=0x0c0a6748u; return 0; }
fr[12]=vf3_fpu_binary(fr[12],fr[15],r[18],'*');
goto P_0c0a674a;
P_0c0a674a: /* original fdf2, guest PC 0x0c0a674a */
if(!s->budget--) { s->failed_pc=0x0c0a674au; return 0; }
fr[13]=vf3_fpu_binary(fr[13],fr[15],r[18],'*');
goto P_0c0a674c;
P_0c0a674c: /* original e014, guest PC 0x0c0a674c */
if(!s->budget--) { s->failed_pc=0x0c0a674cu; return 0; }
r[0]=0x00000014u;
goto P_0c0a674e;
P_0c0a674e: /* original ff77, guest PC 0x0c0a674e */
if(!s->budget--) { s->failed_pc=0x0c0a674eu; return 0; }
vf3_matrix_store(s,ram,7,r[15]+r[0]);
goto P_0c0a6750;
P_0c0a6750: /* original a001, guest PC 0x0c0a6750 */
if(!s->budget--) { s->failed_pc=0x0c0a6750u; return 0; }
r[14]=0x00000001u;
goto P_0c0a6756;
P_0c0a6752: /* original ee01, guest PC 0x0c0a6752 */
if(!s->budget--) { s->failed_pc=0x0c0a6752u; return 0; }
r[14]=0x00000001u;
goto P_0c0a6754;
P_0c0a6754: /* original ee00, guest PC 0x0c0a6754 */
if(!s->budget--) { s->failed_pc=0x0c0a6754u; return 0; }
r[14]=0x00000000u;
goto P_0c0a6756;
P_0c0a6756: /* original d215, guest PC 0x0c0a6756 */
if(!s->budget--) { s->failed_pc=0x0c0a6756u; return 0; }
r[2]=read(ram,0x0c0a67acu,4);
goto P_0c0a6758;
P_0c0a6758: /* original 420b, guest PC 0x0c0a6758 */
if(!s->budget--) { s->failed_pc=0x0c0a6758u; return 0; }
target=r[2];
r[16]=code_base|0x0c0a675cu;
r[4]=0x00000001u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a675cu) { target=s->pc; goto dispatch; }
goto P_0c0a675c;
P_0c0a675a: /* original e401, guest PC 0x0c0a675a */
if(!s->budget--) { s->failed_pc=0x0c0a675au; return 0; }
r[4]=0x00000001u;
goto P_0c0a675c;
P_0c0a675c: /* original e004, guest PC 0x0c0a675c */
if(!s->budget--) { s->failed_pc=0x0c0a675cu; return 0; }
r[0]=0x00000004u;
goto P_0c0a675e;
P_0c0a675e: /* original fada, guest PC 0x0c0a675e */
if(!s->budget--) { s->failed_pc=0x0c0a675eu; return 0; }
vf3_matrix_store(s,ram,13,r[10]);
goto P_0c0a6760;
P_0c0a6760: /* original fac7, guest PC 0x0c0a6760 */
if(!s->budget--) { s->failed_pc=0x0c0a6760u; return 0; }
vf3_matrix_store(s,ram,12,r[10]+r[0]);
goto P_0c0a6762;
P_0c0a6762: /* original e014, guest PC 0x0c0a6762 */
if(!s->budget--) { s->failed_pc=0x0c0a6762u; return 0; }
r[0]=0x00000014u;
goto P_0c0a6764;
P_0c0a6764: /* original f3f6, guest PC 0x0c0a6764 */
if(!s->budget--) { s->failed_pc=0x0c0a6764u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0a6766;
P_0c0a6766: /* original e008, guest PC 0x0c0a6766 */
if(!s->budget--) { s->failed_pc=0x0c0a6766u; return 0; }
r[0]=0x00000008u;
goto P_0c0a6768;
P_0c0a6768: /* original fa37, guest PC 0x0c0a6768 */
if(!s->budget--) { s->failed_pc=0x0c0a6768u; return 0; }
vf3_matrix_store(s,ram,3,r[10]+r[0]);
goto P_0c0a676a;
P_0c0a676a: /* original 60e3, guest PC 0x0c0a676a */
if(!s->budget--) { s->failed_pc=0x0c0a676au; return 0; }
r[0]=r[14];
goto P_0c0a676c;
P_0c0a676c: /* original 9115, guest PC 0x0c0a676c */
if(!s->budget--) { s->failed_pc=0x0c0a676cu; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a679au,2);
goto P_0c0a676e;
P_0c0a676e: /* original 3f1c, guest PC 0x0c0a676e */
if(!s->budget--) { s->failed_pc=0x0c0a676eu; return 0; }
r[15]+=r[1];
goto P_0c0a6770;
P_0c0a6770: /* original 4f26, guest PC 0x0c0a6770 */
if(!s->budget--) { s->failed_pc=0x0c0a6770u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a6772;
P_0c0a6772: /* original fcf9, guest PC 0x0c0a6772 */
if(!s->budget--) { s->failed_pc=0x0c0a6772u; return 0; }
vf3_matrix_load(s,ram,12,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0a6774;
P_0c0a6774: /* original fdf9, guest PC 0x0c0a6774 */
if(!s->budget--) { s->failed_pc=0x0c0a6774u; return 0; }
vf3_matrix_load(s,ram,13,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0a6776;
P_0c0a6776: /* original fef9, guest PC 0x0c0a6776 */
if(!s->budget--) { s->failed_pc=0x0c0a6776u; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0a6778;
P_0c0a6778: /* original fff9, guest PC 0x0c0a6778 */
if(!s->budget--) { s->failed_pc=0x0c0a6778u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0a677a;
P_0c0a677a: /* original 68f6, guest PC 0x0c0a677a */
if(!s->budget--) { s->failed_pc=0x0c0a677au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c0a677c;
P_0c0a677c: /* original 69f6, guest PC 0x0c0a677c */
if(!s->budget--) { s->failed_pc=0x0c0a677cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0a677e;
P_0c0a677e: /* original 6af6, guest PC 0x0c0a677e */
if(!s->budget--) { s->failed_pc=0x0c0a677eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0a6780;
P_0c0a6780: /* original 6bf6, guest PC 0x0c0a6780 */
if(!s->budget--) { s->failed_pc=0x0c0a6780u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0a6782;
P_0c0a6782: /* original 6cf6, guest PC 0x0c0a6782 */
if(!s->budget--) { s->failed_pc=0x0c0a6782u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0a6784;
P_0c0a6784: /* original 6df6, guest PC 0x0c0a6784 */
if(!s->budget--) { s->failed_pc=0x0c0a6784u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0a6786;
P_0c0a6786: /* original 000b, guest PC 0x0c0a6786 */
if(!s->budget--) { s->failed_pc=0x0c0a6786u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0a6788: /* original 6ef6, guest PC 0x0c0a6788 */
if(!s->budget--) { s->failed_pc=0x0c0a6788u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0a678au,s,ram);
unsupported: s->failed_pc=target; return 0;
}
static const uint32_t owned_pcs[]={
0x0c034cecu,0x0c034ceeu,0x0c034cf0u,0x0c034cf2u,0x0c034cf4u,0x0c034cf6u,0x0c034cf8u,0x0c034d14u,0x0c034d16u,0x0c034d18u,0x0c034d1au,0x0c034d1cu,0x0c034d1eu,0x0c034d20u,0x0c034d22u,0x0c034d24u,
0x0c034d26u,0x0c034d28u,0x0c034d2au,0x0c034d2cu,0x0c034d2eu,0x0c034d30u,0x0c034d32u,0x0c034d34u,0x0c034d36u,0x0c034d38u,0x0c034d3au,0x0c034d3cu,0x0c034d3eu,0x0c034d40u,0x0c034d42u,0x0c034d44u,
0x0c034d46u,0x0c034d48u,0x0c034d4au,0x0c034d4cu,0x0c034d4eu,0x0c034d50u,0x0c034d52u,0x0c034d54u,0x0c034d56u,0x0c034d58u,0x0c034d5au,0x0c034d5cu,0x0c034d5eu,0x0c034d60u,0x0c034d62u,0x0c034d64u,
0x0c034d66u,0x0c034d68u,0x0c034d6au,0x0c034d6cu,0x0c034d6eu,0x0c034d70u,0x0c034d72u,0x0c034d74u,0x0c034d76u,0x0c034d78u,0x0c034d7au,0x0c034d7cu,0x0c034d7eu,0x0c034d80u,0x0c034d82u,0x0c034d84u,
0x0c034d86u,0x0c034d88u,0x0c034d8au,0x0c034d8cu,0x0c034d8eu,0x0c034d90u,0x0c034d92u,0x0c034d94u,0x0c034d96u,0x0c034d98u,0x0c034d9au,0x0c034d9cu,0x0c034d9eu,0x0c034da0u,0x0c034da2u,0x0c034da4u,
0x0c034da6u,0x0c034da8u,0x0c034daau,0x0c034dacu,0x0c034daeu,0x0c034db0u,0x0c034db2u,0x0c034db4u,0x0c034db6u,0x0c034db8u,0x0c034dbau,0x0c034dbcu,0x0c034dbeu,0x0c034dc0u,0x0c034dc2u,0x0c034dc4u,
0x0c034dc6u,0x0c034dc8u,0x0c034dcau,0x0c034dccu,0x0c034dceu,0x0c034dd0u,0x0c034dd2u,0x0c034dd4u,0x0c034dd6u,0x0c034dd8u,0x0c034ddau,0x0c034ddcu,0x0c034ddeu,0x0c034de0u,0x0c034de2u,0x0c034de4u,
0x0c034de6u,0x0c034de8u,0x0c034deau,0x0c034decu,0x0c034deeu,0x0c034df0u,0x0c034df2u,0x0c034df4u,0x0c034df6u,0x0c034df8u,0x0c034dfau,0x0c034dfcu,0x0c034dfeu,0x0c034e00u,0x0c034e02u,0x0c034e04u,
0x0c034e06u,0x0c034e08u,0x0c034e0au,0x0c034e0cu,0x0c034e0eu,0x0c034e10u,0x0c034e12u,0x0c034e14u,0x0c034e16u,0x0c034e18u,0x0c034e1au,0x0c034e1cu,0x0c034e1eu,0x0c034e20u,0x0c034e22u,0x0c034e24u,
0x0c034e26u,0x0c034e28u,0x0c034e2au,0x0c034e2cu,0x0c034e2eu,0x0c034e30u,0x0c034e32u,0x0c034e34u,0x0c034e36u,0x0c034e38u,0x0c034e6cu,0x0c034e6eu,0x0c034e70u,0x0c034e72u,0x0c034e74u,0x0c034e76u,
0x0c034e78u,0x0c034e7au,0x0c034e7cu,0x0c034e7eu,0x0c034e80u,0x0c034e82u,0x0c034e84u,0x0c034e86u,0x0c034e88u,0x0c034e8au,0x0c034e8cu,0x0c034e8eu,0x0c034e90u,0x0c034e92u,0x0c034e94u,0x0c034e96u,
0x0c034e98u,0x0c034e9au,0x0c034e9cu,0x0c034e9eu,0x0c034ea0u,0x0c034ea2u,0x0c034ea4u,0x0c034ea6u,0x0c034ea8u,0x0c034eaau,0x0c034eacu,0x0c034eaeu,0x0c034eb0u,0x0c034eb2u,0x0c034eb4u,0x0c034eb6u,
0x0c034eb8u,0x0c034ebau,0x0c034ebcu,0x0c034ebeu,0x0c034ec0u,0x0c034ec2u,0x0c034ec4u,0x0c034ec6u,0x0c034ec8u,0x0c034ecau,0x0c034eccu,0x0c034eceu,0x0c034ed0u,0x0c034ed2u,0x0c034ed4u,0x0c034ed6u,
0x0c034ed8u,0x0c034edau,0x0c034edcu,0x0c034edeu,0x0c034ee0u,0x0c034ee2u,0x0c034ee4u,0x0c034ee6u,0x0c034ee8u,0x0c034eeau,0x0c034eecu,0x0c034eeeu,0x0c034ef0u,0x0c034ef2u,0x0c034ef4u,0x0c034ef6u,
0x0c034ef8u,0x0c034efau,0x0c034efcu,0x0c034efeu,0x0c034f00u,0x0c034f02u,0x0c034f04u,0x0c034f06u,0x0c034f08u,0x0c034f0au,0x0c034f0cu,0x0c034f0eu,0x0c034f10u,0x0c034f12u,0x0c034f14u,0x0c034f16u,
0x0c034f18u,0x0c034f1au,0x0c034f1cu,0x0c034f1eu,0x0c034f20u,0x0c034f22u,0x0c034f24u,0x0c0367acu,0x0c0367aeu,0x0c0367b0u,0x0c0367b2u,0x0c0367b4u,0x0c0367b6u,0x0c0367b8u,0x0c0367bau,0x0c0367bcu,
0x0c0367beu,0x0c0367c0u,0x0c0367c2u,0x0c0367c4u,0x0c0367c6u,0x0c0367c8u,0x0c0367cau,0x0c0367ccu,0x0c0367ceu,0x0c0367d0u,0x0c0367d2u,0x0c0367d4u,0x0c0367d6u,0x0c0367d8u,0x0c0367dau,0x0c0367dcu,
0x0c0367deu,0x0c0367e0u,0x0c0367e2u,0x0c0367e4u,0x0c0367e6u,0x0c0367e8u,0x0c0367eau,0x0c0367ecu,0x0c0367eeu,0x0c0367f0u,0x0c0367f2u,0x0c0367f4u,0x0c0367f6u,0x0c0367f8u,0x0c0367fau,0x0c0367fcu,
0x0c0367feu,0x0c036800u,0x0c036802u,0x0c036804u,0x0c036806u,0x0c036808u,0x0c03680au,0x0c03680cu,0x0c03680eu,0x0c036810u,0x0c036812u,0x0c036814u,0x0c036816u,0x0c036818u,0x0c03681au,0x0c03681cu,
0x0c03681eu,0x0c036820u,0x0c036822u,0x0c036824u,0x0c036826u,0x0c036828u,0x0c03682au,0x0c03682cu,0x0c03682eu,0x0c036830u,0x0c036832u,0x0c036834u,0x0c036836u,0x0c036838u,0x0c03683au,0x0c03683cu,
0x0c03683eu,0x0c036840u,0x0c036842u,0x0c036844u,0x0c036846u,0x0c036848u,0x0c03684au,0x0c03684cu,0x0c03684eu,0x0c036850u,0x0c036852u,0x0c036854u,0x0c036856u,0x0c036858u,0x0c03685au,0x0c03685cu,
0x0c03685eu,0x0c036860u,0x0c036862u,0x0c036864u,0x0c036866u,0x0c036868u,0x0c03686au,0x0c03686cu,0x0c03686eu,0x0c036870u,0x0c036872u,0x0c036874u,0x0c036876u,0x0c036878u,0x0c03687au,0x0c03687cu,
0x0c03687eu,0x0c036880u,0x0c036882u,0x0c036884u,0x0c036886u,0x0c036888u,0x0c03688au,0x0c03688cu,0x0c03688eu,0x0c036890u,0x0c036892u,0x0c036894u,0x0c036896u,0x0c036898u,0x0c03689au,0x0c03689cu,
0x0c03689eu,0x0c0368a0u,0x0c0368a2u,0x0c0368a4u,0x0c0368a6u,0x0c0368a8u,0x0c0381f0u,0x0c0381f2u,0x0c0381f4u,0x0c0381f6u,0x0c0381f8u,0x0c0381fau,0x0c0381fcu,0x0c0381feu,0x0c038200u,0x0c038202u,
0x0c038204u,0x0c038206u,0x0c038208u,0x0c03820au,0x0c03820cu,0x0c03820eu,0x0c038210u,0x0c038212u,0x0c038214u,0x0c038216u,0x0c038218u,0x0c03821au,0x0c03821cu,0x0c03821eu,0x0c038220u,0x0c038222u,
0x0c038224u,0x0c038226u,0x0c038228u,0x0c03822au,0x0c03822cu,0x0c03822eu,0x0c038230u,0x0c038232u,0x0c038234u,0x0c038236u,0x0c038238u,0x0c03823au,0x0c03823cu,0x0c03823eu,0x0c038240u,0x0c038242u,
0x0c038244u,0x0c038246u,0x0c038248u,0x0c03824au,0x0c03824cu,0x0c03824eu,0x0c038250u,0x0c038252u,0x0c038254u,0x0c038256u,0x0c038258u,0x0c03825au,0x0c03825cu,0x0c03825eu,0x0c038260u,0x0c038262u,
0x0c038264u,0x0c038266u,0x0c038268u,0x0c03826au,0x0c03826cu,0x0c03826eu,0x0c038270u,0x0c038272u,0x0c038274u,0x0c038276u,0x0c038278u,0x0c03827au,0x0c03827cu,0x0c03827eu,0x0c038280u,0x0c038282u,
0x0c038284u,0x0c038286u,0x0c038288u,0x0c03828au,0x0c03828cu,0x0c03828eu,0x0c038290u,0x0c038292u,0x0c038294u,0x0c038296u,0x0c038298u,0x0c03829au,0x0c03829cu,0x0c03829eu,0x0c0382a0u,0x0c0382a2u,
0x0c0382a4u,0x0c0382a6u,0x0c0382a8u,0x0c0382aau,0x0c0382acu,0x0c0382aeu,0x0c0382b0u,0x0c0382b2u,0x0c0382b4u,0x0c0382b6u,0x0c0382b8u,0x0c0382bau,0x0c0382bcu,0x0c0382beu,0x0c0382c0u,0x0c0382c2u,
0x0c0382c4u,0x0c0382c6u,0x0c0382c8u,0x0c0382cau,0x0c0382ccu,0x0c0382ceu,0x0c0382d0u,0x0c0382d2u,0x0c0382d4u,0x0c0382d6u,0x0c0382d8u,0x0c0382dau,0x0c0382dcu,0x0c0382deu,0x0c0382e0u,0x0c0382e2u,
0x0c0382e4u,0x0c0382e6u,0x0c0382e8u,0x0c0382eau,0x0c0382ecu,0x0c0382eeu,0x0c0382f0u,0x0c0382f2u,0x0c0382f4u,0x0c0382f6u,0x0c0382f8u,0x0c0382fau,0x0c0382fcu,0x0c0382feu,0x0c038300u,0x0c038302u,
0x0c038304u,0x0c038306u,0x0c038308u,0x0c03830au,0x0c03830cu,0x0c03830eu,0x0c038310u,0x0c038312u,0x0c038314u,0x0c038316u,0x0c038318u,0x0c03831au,0x0c03831cu,0x0c03831eu,0x0c038320u,0x0c038322u,
0x0c038324u,0x0c038326u,0x0c038328u,0x0c03832au,0x0c03832cu,0x0c03832eu,0x0c038330u,0x0c038332u,0x0c038334u,0x0c038336u,0x0c038338u,0x0c04454cu,0x0c04454eu,0x0c044550u,0x0c044552u,0x0c044554u,
0x0c044556u,0x0c044558u,0x0c04455au,0x0c04455cu,0x0c04455eu,0x0c044560u,0x0c044562u,0x0c044564u,0x0c044566u,0x0c044568u,0x0c04456au,0x0c04456cu,0x0c04456eu,0x0c044570u,0x0c044572u,0x0c044574u,
0x0c044576u,0x0c044578u,0x0c04457au,0x0c04457cu,0x0c04457eu,0x0c044580u,0x0c059848u,0x0c05984au,0x0c05984cu,0x0c05984eu,0x0c059850u,0x0c059852u,0x0c059854u,0x0c059856u,0x0c059858u,0x0c05985au,
0x0c05985cu,0x0c05985eu,0x0c059860u,0x0c059862u,0x0c059864u,0x0c059866u,0x0c059868u,0x0c05986au,0x0c05986cu,0x0c05986eu,0x0c059870u,0x0c059872u,0x0c059874u,0x0c059876u,0x0c059878u,0x0c05987au,
0x0c05987cu,0x0c05987eu,0x0c059880u,0x0c059882u,0x0c059884u,0x0c059886u,0x0c059888u,0x0c05988au,0x0c05988cu,0x0c05988eu,0x0c059890u,0x0c059892u,0x0c059894u,0x0c05c280u,0x0c05c282u,0x0c05c284u,
0x0c05c286u,0x0c05c288u,0x0c05c28au,0x0c05c28cu,0x0c05c28eu,0x0c05c290u,0x0c05c292u,0x0c05c294u,0x0c05c296u,0x0c05c298u,0x0c05c29au,0x0c05c29cu,0x0c05c29eu,0x0c05c2a0u,0x0c05c2a2u,0x0c05c2a4u,
0x0c05c2a6u,0x0c05c2a8u,0x0c05c2aau,0x0c05c2acu,0x0c05c2aeu,0x0c05c2b0u,0x0c05c2b2u,0x0c05c2b4u,0x0c05c2b6u,0x0c05c2b8u,0x0c05c2bau,0x0c05c2bcu,0x0c05c2beu,0x0c05c2c0u,0x0c05c2c2u,0x0c05c2c4u,
0x0c05c2c6u,0x0c05c2c8u,0x0c05c2cau,0x0c05c2ccu,0x0c05c2ceu,0x0c05c2d0u,0x0c05c2d2u,0x0c05c2d4u,0x0c05c2d6u,0x0c05c2d8u,0x0c05c2dau,0x0c05c2dcu,0x0c05c2deu,0x0c05c2e0u,0x0c05c2e2u,0x0c05c2e4u,
0x0c05c2e6u,0x0c05c2e8u,0x0c05c2eau,0x0c05c2ecu,0x0c05c2eeu,0x0c05c2f0u,0x0c05c2f2u,0x0c05c2f4u,0x0c05c2f6u,0x0c05c2f8u,0x0c05c2fau,0x0c05c2fcu,0x0c05c2feu,0x0c05c300u,0x0c05c302u,0x0c05c304u,
0x0c05c306u,0x0c05c308u,0x0c05c30au,0x0c05c30cu,0x0c05c30eu,0x0c05c310u,0x0c05c312u,0x0c05c314u,0x0c05c316u,0x0c05c318u,0x0c05c31au,0x0c05c31cu,0x0c05c31eu,0x0c05c320u,0x0c05c322u,0x0c05c324u,
0x0c05c326u,0x0c05c328u,0x0c05c32au,0x0c05c32cu,0x0c05c32eu,0x0c05c330u,0x0c05c332u,0x0c05c334u,0x0c05c336u,0x0c05c338u,0x0c05c33au,0x0c05c33cu,0x0c05c33eu,0x0c05c340u,0x0c05c342u,0x0c05c344u,
0x0c05c346u,0x0c05c348u,0x0c05c34au,0x0c05c34cu,0x0c05c368u,0x0c05c36au,0x0c05c36cu,0x0c05c36eu,0x0c05c370u,0x0c05c372u,0x0c05c374u,0x0c05c376u,0x0c05c378u,0x0c05c37au,0x0c05c37cu,0x0c05c37eu,
0x0c05c380u,0x0c05c382u,0x0c05c384u,0x0c05c386u,0x0c05c388u,0x0c05c38au,0x0c05c38cu,0x0c05c38eu,0x0c05c390u,0x0c05c392u,0x0c05c394u,0x0c05c396u,0x0c05c398u,0x0c05c39au,0x0c05c39cu,0x0c05c39eu,
0x0c05c3a0u,0x0c05c3a2u,0x0c05c3a4u,0x0c05c3a6u,0x0c05c3a8u,0x0c05c3aau,0x0c05c3acu,0x0c05c3aeu,0x0c05c3b0u,0x0c05c3b2u,0x0c05c3b4u,0x0c05c3b6u,0x0c05c3b8u,0x0c05c3bau,0x0c05c3bcu,0x0c05c3beu,
0x0c05c3c0u,0x0c05c3c2u,0x0c05c3c4u,0x0c05c3c6u,0x0c05c3c8u,0x0c05c3cau,0x0c05c3ccu,0x0c05c3ceu,0x0c05c3d0u,0x0c05c3d2u,0x0c05c3d4u,0x0c05c3d6u,0x0c05c3d8u,0x0c05c3dau,0x0c05c3dcu,0x0c05c3deu,
0x0c05c3e0u,0x0c05c3e2u,0x0c05c3e4u,0x0c05c3e6u,0x0c05c3e8u,0x0c05c3eau,0x0c05c3ecu,0x0c05c3eeu,0x0c05c3f0u,0x0c05c3f2u,0x0c05c3f4u,0x0c05c3f6u,0x0c05c3f8u,0x0c05c3fau,0x0c05c3fcu,0x0c05c3feu,
0x0c05c400u,0x0c05c402u,0x0c05c404u,0x0c05c406u,0x0c05c408u,0x0c05c40au,0x0c05c40cu,0x0c05c40eu,0x0c05c410u,0x0c05c412u,0x0c05c414u,0x0c05c416u,0x0c05c418u,0x0c05c41au,0x0c05c41cu,0x0c05c41eu,
0x0c05c420u,0x0c05c422u,0x0c05c424u,0x0c05c426u,0x0c05c428u,0x0c05c42au,0x0c05c42cu,0x0c05c42eu,0x0c05c430u,0x0c05c432u,0x0c05c434u,0x0c05c436u,0x0c05c438u,0x0c05c43au,0x0c05c43cu,0x0c05c43eu,
0x0c05c440u,0x0c05c442u,0x0c05c444u,0x0c05c446u,0x0c05c448u,0x0c05c44au,0x0c05c44cu,0x0c05c44eu,0x0c05c450u,0x0c05c452u,0x0c05c454u,0x0c05c456u,0x0c05c458u,0x0c05c45au,0x0c05c45cu,0x0c05f36eu,
0x0c05f370u,0x0c05f372u,0x0c05f374u,0x0c05f376u,0x0c05f378u,0x0c05f37au,0x0c05f37cu,0x0c05f37eu,0x0c05f380u,0x0c05f382u,0x0c05f384u,0x0c05f386u,0x0c05f388u,0x0c05f38au,0x0c05f38cu,0x0c05f38eu,
0x0c05f390u,0x0c05f392u,0x0c05f3b0u,0x0c05f3b2u,0x0c05f3b4u,0x0c05f3b6u,0x0c05f3b8u,0x0c05f3bau,0x0c05f3bcu,0x0c05f3beu,0x0c05f3c0u,0x0c05f3c2u,0x0c05f3c4u,0x0c05f3c6u,0x0c05f3c8u,0x0c05f3cau,
0x0c05f3ccu,0x0c05f3ceu,0x0c05f3d0u,0x0c05f3d2u,0x0c05f3d4u,0x0c05f3d6u,0x0c05f3d8u,0x0c05f3dau,0x0c05f3dcu,0x0c060d62u,0x0c060d64u,0x0c060d66u,0x0c060d68u,0x0c060d6au,0x0c060d6cu,0x0c060d6eu,
0x0c060d70u,0x0c060d72u,0x0c060d74u,0x0c060d76u,0x0c060e50u,0x0c060e52u,0x0c060e54u,0x0c060e56u,0x0c060e58u,0x0c060e5au,0x0c060e5cu,0x0c060e5eu,0x0c060e60u,0x0c060e62u,0x0c060e64u,0x0c060e66u,
0x0c060e68u,0x0c060e6au,0x0c060e6cu,0x0c060e6eu,0x0c060e70u,0x0c060e72u,0x0c07ae9cu,0x0c07ae9eu,0x0c07aea0u,0x0c07aea2u,0x0c07aea4u,0x0c07aea6u,0x0c07aea8u,0x0c07aeaau,0x0c07aeacu,0x0c07aeaeu,
0x0c07aeb0u,0x0c07aeb2u,0x0c07aeb4u,0x0c07aeb6u,0x0c07aeb8u,0x0c07aebau,0x0c07aebcu,0x0c07aebeu,0x0c07aec0u,0x0c07aec2u,0x0c07aec4u,0x0c07aec6u,0x0c0a6642u,0x0c0a6644u,0x0c0a6646u,0x0c0a6648u,
0x0c0a664au,0x0c0a664cu,0x0c0a664eu,0x0c0a6650u,0x0c0a6652u,0x0c0a6654u,0x0c0a6656u,0x0c0a6658u,0x0c0a665au,0x0c0a665cu,0x0c0a665eu,0x0c0a6660u,0x0c0a6662u,0x0c0a6664u,0x0c0a6666u,0x0c0a6668u,
0x0c0a666au,0x0c0a666cu,0x0c0a666eu,0x0c0a6670u,0x0c0a6672u,0x0c0a6674u,0x0c0a6676u,0x0c0a6678u,0x0c0a667au,0x0c0a667cu,0x0c0a667eu,0x0c0a6680u,0x0c0a6682u,0x0c0a6684u,0x0c0a6686u,0x0c0a6688u,
0x0c0a668au,0x0c0a668cu,0x0c0a668eu,0x0c0a6690u,0x0c0a6692u,0x0c0a6694u,0x0c0a6696u,0x0c0a6698u,0x0c0a669au,0x0c0a669cu,0x0c0a669eu,0x0c0a66a0u,0x0c0a66a2u,0x0c0a66a4u,0x0c0a66a6u,0x0c0a66a8u,
0x0c0a66aau,0x0c0a66acu,0x0c0a66aeu,0x0c0a66b0u,0x0c0a66b2u,0x0c0a66b4u,0x0c0a66b6u,0x0c0a66b8u,0x0c0a66bau,0x0c0a66bcu,0x0c0a66beu,0x0c0a66c0u,0x0c0a66c2u,0x0c0a66c4u,0x0c0a66c6u,0x0c0a66c8u,
0x0c0a66cau,0x0c0a66ccu,0x0c0a66ceu,0x0c0a66d0u,0x0c0a66d2u,0x0c0a66d4u,0x0c0a66d6u,0x0c0a66d8u,0x0c0a66dau,0x0c0a66dcu,0x0c0a66deu,0x0c0a66e0u,0x0c0a66e2u,0x0c0a66e4u,0x0c0a66e6u,0x0c0a66e8u,
0x0c0a66eau,0x0c0a66ecu,0x0c0a66eeu,0x0c0a66f0u,0x0c0a66f2u,0x0c0a66f4u,0x0c0a66f6u,0x0c0a66f8u,0x0c0a66fau,0x0c0a66fcu,0x0c0a66feu,0x0c0a6700u,0x0c0a6702u,0x0c0a6704u,0x0c0a6706u,0x0c0a6708u,
0x0c0a670au,0x0c0a670cu,0x0c0a670eu,0x0c0a6710u,0x0c0a6712u,0x0c0a6714u,0x0c0a6716u,0x0c0a6718u,0x0c0a671au,0x0c0a671cu,0x0c0a671eu,0x0c0a6720u,0x0c0a6722u,0x0c0a6724u,0x0c0a6726u,0x0c0a6728u,
0x0c0a672au,0x0c0a672cu,0x0c0a672eu,0x0c0a6730u,0x0c0a6732u,0x0c0a6734u,0x0c0a6736u,0x0c0a6738u,0x0c0a673au,0x0c0a673cu,0x0c0a673eu,0x0c0a6740u,0x0c0a6742u,0x0c0a6744u,0x0c0a6746u,0x0c0a6748u,
0x0c0a674au,0x0c0a674cu,0x0c0a674eu,0x0c0a6750u,0x0c0a6752u,0x0c0a6754u,0x0c0a6756u,0x0c0a6758u,0x0c0a675au,0x0c0a675cu,0x0c0a675eu,0x0c0a6760u,0x0c0a6762u,0x0c0a6764u,0x0c0a6766u,0x0c0a6768u,
0x0c0a676au,0x0c0a676cu,0x0c0a676eu,0x0c0a6770u,0x0c0a6772u,0x0c0a6774u,0x0c0a6776u,0x0c0a6778u,0x0c0a677au,0x0c0a677cu,0x0c0a677eu,0x0c0a6780u,0x0c0a6782u,0x0c0a6784u,0x0c0a6786u,0x0c0a6788u,
};
static const uint32_t claim_pcs[]={
0x0c034cecu,0x0c034ceeu,0x0c034cf0u,0x0c034cf2u,0x0c034cf4u,0x0c034cf6u,0x0c034cf8u,0x0c034d14u,0x0c034d16u,0x0c034d18u,0x0c034d1au,0x0c034d1cu,0x0c034d1eu,0x0c034d20u,0x0c034d22u,0x0c034d24u,
0x0c034d26u,0x0c034d28u,0x0c034d2au,0x0c034d2cu,0x0c034d2eu,0x0c034d30u,0x0c034d32u,0x0c034d34u,0x0c034d36u,0x0c034d38u,0x0c034d3au,0x0c034d3cu,0x0c034d3eu,0x0c034d40u,0x0c034d42u,0x0c034d44u,
0x0c034d46u,0x0c034d48u,0x0c034d4au,0x0c034d4cu,0x0c034d4eu,0x0c034d50u,0x0c034d52u,0x0c034d54u,0x0c034d56u,0x0c034d58u,0x0c034d5au,0x0c034d5cu,0x0c034d5eu,0x0c034d60u,0x0c034d62u,0x0c034d64u,
0x0c034d66u,0x0c034d68u,0x0c034d6au,0x0c034d6cu,0x0c034d6eu,0x0c034d70u,0x0c034d72u,0x0c034d74u,0x0c034d76u,0x0c034d78u,0x0c034d7au,0x0c034d7cu,0x0c034d7eu,0x0c034d80u,0x0c034d82u,0x0c034d84u,
0x0c034d86u,0x0c034d88u,0x0c034d8au,0x0c034d8cu,0x0c034d8eu,0x0c034d90u,0x0c034d92u,0x0c034d94u,0x0c034d96u,0x0c034d98u,0x0c034d9au,0x0c034d9cu,0x0c034d9eu,0x0c034da0u,0x0c034da2u,0x0c034da4u,
0x0c034da6u,0x0c034da8u,0x0c034daau,0x0c034dacu,0x0c034daeu,0x0c034db0u,0x0c034db2u,0x0c034db4u,0x0c034db6u,0x0c034db8u,0x0c034dbau,0x0c034dbcu,0x0c034dbeu,0x0c034dc0u,0x0c034dc2u,0x0c034dc4u,
0x0c034dc6u,0x0c034dc8u,0x0c034dcau,0x0c034dccu,0x0c034dceu,0x0c034dd0u,0x0c034dd2u,0x0c034dd4u,0x0c034dd6u,0x0c034dd8u,0x0c034ddau,0x0c034ddcu,0x0c034ddeu,0x0c034de0u,0x0c034de2u,0x0c034de4u,
0x0c034de6u,0x0c034de8u,0x0c034deau,0x0c034decu,0x0c034deeu,0x0c034df0u,0x0c034df2u,0x0c034df4u,0x0c034df6u,0x0c034df8u,0x0c034dfau,0x0c034dfcu,0x0c034dfeu,0x0c034e00u,0x0c034e02u,0x0c034e04u,
0x0c034e06u,0x0c034e08u,0x0c034e0au,0x0c034e0cu,0x0c034e0eu,0x0c034e10u,0x0c034e12u,0x0c034e14u,0x0c034e16u,0x0c034e18u,0x0c034e1au,0x0c034e1cu,0x0c034e1eu,0x0c034e20u,0x0c034e22u,0x0c034e24u,
0x0c034e26u,0x0c034e28u,0x0c034e2au,0x0c034e2cu,0x0c034e2eu,0x0c034e30u,0x0c034e32u,0x0c034e34u,0x0c034e36u,0x0c034e38u,0x0c034e6cu,0x0c034e6eu,0x0c034e70u,0x0c034e72u,0x0c034e74u,0x0c034e76u,
0x0c034e78u,0x0c034e7au,0x0c034e7cu,0x0c034e7eu,0x0c034e80u,0x0c034e82u,0x0c034e84u,0x0c034e86u,0x0c034e88u,0x0c034e8au,0x0c034e8cu,0x0c034e8eu,0x0c034e90u,0x0c034e92u,0x0c034e94u,0x0c034e96u,
0x0c034e98u,0x0c034e9au,0x0c034e9cu,0x0c034e9eu,0x0c034ea0u,0x0c034ea2u,0x0c034ea4u,0x0c034ea6u,0x0c034ea8u,0x0c034eaau,0x0c034eacu,0x0c034eaeu,0x0c034eb0u,0x0c034eb2u,0x0c034eb4u,0x0c034eb6u,
0x0c034eb8u,0x0c034ebau,0x0c034ebcu,0x0c034ebeu,0x0c034ec0u,0x0c034ec2u,0x0c034ec4u,0x0c034ec6u,0x0c034ec8u,0x0c034ecau,0x0c034eccu,0x0c034eceu,0x0c034ed0u,0x0c034ed2u,0x0c034ed4u,0x0c034ed6u,
0x0c034ed8u,0x0c034edau,0x0c034edcu,0x0c034edeu,0x0c034ee0u,0x0c034ee2u,0x0c034ee4u,0x0c034ee6u,0x0c034ee8u,0x0c034eeau,0x0c034eecu,0x0c034eeeu,0x0c034ef0u,0x0c034ef2u,0x0c034ef4u,0x0c034ef6u,
0x0c034ef8u,0x0c034efau,0x0c034efcu,0x0c034efeu,0x0c034f00u,0x0c034f02u,0x0c034f04u,0x0c034f06u,0x0c034f08u,0x0c034f0au,0x0c034f0cu,0x0c034f0eu,0x0c034f10u,0x0c034f12u,0x0c034f14u,0x0c034f16u,
0x0c034f18u,0x0c034f1au,0x0c034f1cu,0x0c034f1eu,0x0c034f20u,0x0c034f22u,0x0c034f24u,0x0c0367acu,0x0c0367aeu,0x0c0367b0u,0x0c0367b2u,0x0c0367b4u,0x0c0367b6u,0x0c0367b8u,0x0c0367bau,0x0c0367bcu,
0x0c0367beu,0x0c0367c0u,0x0c0367c2u,0x0c0367c4u,0x0c0367c6u,0x0c0367c8u,0x0c0367cau,0x0c0367ccu,0x0c0367ceu,0x0c0367d0u,0x0c0367d2u,0x0c0367d4u,0x0c0367d6u,0x0c0367d8u,0x0c0367dau,0x0c0367dcu,
0x0c0367deu,0x0c0367e0u,0x0c0367e2u,0x0c0367e4u,0x0c0367e6u,0x0c0367e8u,0x0c0367eau,0x0c0367ecu,0x0c0367eeu,0x0c0367f0u,0x0c0367f2u,0x0c0367f4u,0x0c0367f6u,0x0c0367f8u,0x0c0367fau,0x0c0367fcu,
0x0c0367feu,0x0c036800u,0x0c036802u,0x0c036804u,0x0c036806u,0x0c036808u,0x0c03680au,0x0c03680cu,0x0c03680eu,0x0c036810u,0x0c036812u,0x0c036814u,0x0c036816u,0x0c036818u,0x0c03681au,0x0c03681cu,
0x0c03681eu,0x0c036820u,0x0c036822u,0x0c036824u,0x0c036826u,0x0c036828u,0x0c03682au,0x0c03682cu,0x0c03682eu,0x0c036830u,0x0c036832u,0x0c036834u,0x0c036836u,0x0c036838u,0x0c03683au,0x0c03683cu,
0x0c03683eu,0x0c036840u,0x0c036842u,0x0c036844u,0x0c036846u,0x0c036848u,0x0c03684au,0x0c03684cu,0x0c03684eu,0x0c036850u,0x0c036852u,0x0c036854u,0x0c036856u,0x0c036858u,0x0c03685au,0x0c03685cu,
0x0c03685eu,0x0c036860u,0x0c036862u,0x0c036864u,0x0c036866u,0x0c036868u,0x0c03686au,0x0c03686cu,0x0c03686eu,0x0c036870u,0x0c036872u,0x0c036874u,0x0c036876u,0x0c036878u,0x0c03687au,0x0c03687cu,
0x0c03687eu,0x0c036880u,0x0c036882u,0x0c036884u,0x0c036886u,0x0c036888u,0x0c03688au,0x0c03688cu,0x0c03688eu,0x0c036890u,0x0c036892u,0x0c036894u,0x0c036896u,0x0c036898u,0x0c03689au,0x0c03689cu,
0x0c03689eu,0x0c0368a0u,0x0c0368a2u,0x0c0368a4u,0x0c0368a6u,0x0c0368a8u,0x0c0381f0u,0x0c0381f2u,0x0c0381f4u,0x0c0381f6u,0x0c0381f8u,0x0c0381fau,0x0c0381fcu,0x0c0381feu,0x0c038200u,0x0c038202u,
0x0c038204u,0x0c038206u,0x0c038208u,0x0c03820au,0x0c03820cu,0x0c03820eu,0x0c038210u,0x0c038212u,0x0c038214u,0x0c038216u,0x0c038218u,0x0c03821au,0x0c03821cu,0x0c03821eu,0x0c038220u,0x0c038222u,
0x0c038224u,0x0c038226u,0x0c038228u,0x0c03822au,0x0c03822cu,0x0c03822eu,0x0c038230u,0x0c038232u,0x0c038234u,0x0c038236u,0x0c038238u,0x0c03823au,0x0c03823cu,0x0c03823eu,0x0c038240u,0x0c038242u,
0x0c038244u,0x0c038246u,0x0c038248u,0x0c03824au,0x0c03824cu,0x0c03824eu,0x0c038250u,0x0c038252u,0x0c038254u,0x0c038256u,0x0c038258u,0x0c03825au,0x0c03825cu,0x0c03825eu,0x0c038260u,0x0c038262u,
0x0c038264u,0x0c038266u,0x0c038268u,0x0c03826au,0x0c03826cu,0x0c03826eu,0x0c038270u,0x0c038272u,0x0c038274u,0x0c038276u,0x0c038278u,0x0c03827au,0x0c03827cu,0x0c03827eu,0x0c038280u,0x0c038282u,
0x0c038284u,0x0c038286u,0x0c038288u,0x0c03828au,0x0c03828cu,0x0c03828eu,0x0c038290u,0x0c038292u,0x0c038294u,0x0c038296u,0x0c038298u,0x0c03829au,0x0c03829cu,0x0c03829eu,0x0c0382a0u,0x0c0382a2u,
0x0c0382a4u,0x0c0382a6u,0x0c0382a8u,0x0c0382aau,0x0c0382acu,0x0c0382aeu,0x0c0382b0u,0x0c0382b2u,0x0c0382b4u,0x0c0382b6u,0x0c0382b8u,0x0c0382bau,0x0c0382bcu,0x0c0382beu,0x0c0382c0u,0x0c0382c2u,
0x0c0382c4u,0x0c0382c6u,0x0c0382c8u,0x0c0382cau,0x0c0382ccu,0x0c0382ceu,0x0c0382d0u,0x0c0382d2u,0x0c0382d4u,0x0c0382d6u,0x0c0382d8u,0x0c0382dau,0x0c0382dcu,0x0c0382deu,0x0c0382e0u,0x0c0382e2u,
0x0c0382e4u,0x0c0382e6u,0x0c0382e8u,0x0c0382eau,0x0c0382ecu,0x0c0382eeu,0x0c0382f0u,0x0c0382f2u,0x0c0382f4u,0x0c0382f6u,0x0c0382f8u,0x0c0382fau,0x0c0382fcu,0x0c0382feu,0x0c038300u,0x0c038302u,
0x0c038304u,0x0c038306u,0x0c038308u,0x0c03830au,0x0c03830cu,0x0c03830eu,0x0c038310u,0x0c038312u,0x0c038314u,0x0c038316u,0x0c038318u,0x0c03831au,0x0c03831cu,0x0c03831eu,0x0c038320u,0x0c038322u,
0x0c038324u,0x0c038326u,0x0c038328u,0x0c03832au,0x0c03832cu,0x0c03832eu,0x0c038330u,0x0c038332u,0x0c038334u,0x0c038336u,0x0c038338u,0x0c04454cu,0x0c059848u,0x0c05c280u,0x0c05c282u,0x0c05c284u,
0x0c05c286u,0x0c05c288u,0x0c05c28au,0x0c05c28cu,0x0c05c28eu,0x0c05c290u,0x0c05c292u,0x0c05c294u,0x0c05c296u,0x0c05c298u,0x0c05c29au,0x0c05c29cu,0x0c05c29eu,0x0c05c2a0u,0x0c05c2a2u,0x0c05c2a4u,
0x0c05c2a6u,0x0c05c2a8u,0x0c05c2aau,0x0c05c2acu,0x0c05c2aeu,0x0c05c2b0u,0x0c05c2b2u,0x0c05c2b4u,0x0c05c2b6u,0x0c05c2b8u,0x0c05c2bau,0x0c05c2bcu,0x0c05c2beu,0x0c05c2c0u,0x0c05c2c2u,0x0c05c2c4u,
0x0c05c2c6u,0x0c05c2c8u,0x0c05c2cau,0x0c05c2ccu,0x0c05c2ceu,0x0c05c2d0u,0x0c05c2d2u,0x0c05c2d4u,0x0c05c2d6u,0x0c05c2d8u,0x0c05c2dau,0x0c05c2dcu,0x0c05c2deu,0x0c05c2e0u,0x0c05c2e2u,0x0c05c2e4u,
0x0c05c2e6u,0x0c05c2e8u,0x0c05c2eau,0x0c05c2ecu,0x0c05c2eeu,0x0c05c2f0u,0x0c05c2f2u,0x0c05c2f4u,0x0c05c2f6u,0x0c05c2f8u,0x0c05c2fau,0x0c05c2fcu,0x0c05c2feu,0x0c05c300u,0x0c05c302u,0x0c05c304u,
0x0c05c306u,0x0c05c308u,0x0c05c30au,0x0c05c30cu,0x0c05c30eu,0x0c05c310u,0x0c05c312u,0x0c05c314u,0x0c05c316u,0x0c05c318u,0x0c05c31au,0x0c05c31cu,0x0c05c31eu,0x0c05c320u,0x0c05c322u,0x0c05c324u,
0x0c05c326u,0x0c05c328u,0x0c05c32au,0x0c05c32cu,0x0c05c32eu,0x0c05c330u,0x0c05c332u,0x0c05c334u,0x0c05c336u,0x0c05c338u,0x0c05c33au,0x0c05c33cu,0x0c05c33eu,0x0c05c340u,0x0c05c342u,0x0c05c344u,
0x0c05c346u,0x0c05c348u,0x0c05c34au,0x0c05c34cu,0x0c05c368u,0x0c05c36au,0x0c05c36cu,0x0c05c36eu,0x0c05c370u,0x0c05c372u,0x0c05c374u,0x0c05c376u,0x0c05c378u,0x0c05c37au,0x0c05c37cu,0x0c05c37eu,
0x0c05c380u,0x0c05c382u,0x0c05c384u,0x0c05c386u,0x0c05c388u,0x0c05c38au,0x0c05c38cu,0x0c05c38eu,0x0c05c390u,0x0c05c392u,0x0c05c394u,0x0c05c396u,0x0c05c398u,0x0c05c39au,0x0c05c39cu,0x0c05c39eu,
0x0c05c3a0u,0x0c05c3a2u,0x0c05c3a4u,0x0c05c3a6u,0x0c05c3a8u,0x0c05c3aau,0x0c05c3acu,0x0c05c3aeu,0x0c05c3b0u,0x0c05c3b2u,0x0c05c3b4u,0x0c05c3b6u,0x0c05c3b8u,0x0c05c3bau,0x0c05c3bcu,0x0c05c3beu,
0x0c05c3c0u,0x0c05c3c2u,0x0c05c3c4u,0x0c05c3c6u,0x0c05c3c8u,0x0c05c3cau,0x0c05c3ccu,0x0c05c3ceu,0x0c05c3d0u,0x0c05c3d2u,0x0c05c3d4u,0x0c05c3d6u,0x0c05c3d8u,0x0c05c3dau,0x0c05c3dcu,0x0c05c3deu,
0x0c05c3e0u,0x0c05c3e2u,0x0c05c3e4u,0x0c05c3e6u,0x0c05c3e8u,0x0c05c3eau,0x0c05c3ecu,0x0c05c3eeu,0x0c05c3f0u,0x0c05c3f2u,0x0c05c3f4u,0x0c05c3f6u,0x0c05c3f8u,0x0c05c3fau,0x0c05c3fcu,0x0c05c3feu,
0x0c05c400u,0x0c05c402u,0x0c05c404u,0x0c05c406u,0x0c05c408u,0x0c05c40au,0x0c05c40cu,0x0c05c40eu,0x0c05c410u,0x0c05c412u,0x0c05c414u,0x0c05c416u,0x0c05c418u,0x0c05c41au,0x0c05c41cu,0x0c05c41eu,
0x0c05c420u,0x0c05c422u,0x0c05c424u,0x0c05c426u,0x0c05c428u,0x0c05c42au,0x0c05c42cu,0x0c05c42eu,0x0c05c430u,0x0c05c432u,0x0c05c434u,0x0c05c436u,0x0c05c438u,0x0c05c43au,0x0c05c43cu,0x0c05c43eu,
0x0c05c440u,0x0c05c442u,0x0c05c444u,0x0c05c446u,0x0c05c448u,0x0c05c44au,0x0c05c44cu,0x0c05c44eu,0x0c05c450u,0x0c05c452u,0x0c05c454u,0x0c05c456u,0x0c05c458u,0x0c05c45au,0x0c05c45cu,0x0c05f36eu,
0x0c060d62u,0x0c060d64u,0x0c060d66u,0x0c060d68u,0x0c060d6au,0x0c060d6cu,0x0c060d6eu,0x0c060d70u,0x0c060d72u,0x0c060d74u,0x0c060d76u,0x0c060e50u,0x0c07ae9cu,0x0c07ae9eu,0x0c07aea0u,0x0c07aea2u,
0x0c07aea4u,0x0c07aea6u,0x0c07aea8u,0x0c07aeaau,0x0c07aeacu,0x0c07aeaeu,0x0c07aeb0u,0x0c07aeb2u,0x0c07aeb4u,0x0c07aeb6u,0x0c07aeb8u,0x0c07aebau,0x0c07aebcu,0x0c07aebeu,0x0c07aec0u,0x0c07aec2u,
0x0c07aec4u,0x0c07aec6u,0x0c0a6642u,0x0c0a6644u,0x0c0a6646u,0x0c0a6648u,0x0c0a664au,0x0c0a664cu,0x0c0a664eu,0x0c0a6650u,0x0c0a6652u,0x0c0a6654u,0x0c0a6656u,0x0c0a6658u,0x0c0a665au,0x0c0a665cu,
0x0c0a665eu,0x0c0a6660u,0x0c0a6662u,0x0c0a6664u,0x0c0a6666u,0x0c0a6668u,0x0c0a666au,0x0c0a666cu,0x0c0a666eu,0x0c0a6670u,0x0c0a6672u,0x0c0a6674u,0x0c0a6676u,0x0c0a6678u,0x0c0a667au,0x0c0a667cu,
0x0c0a667eu,0x0c0a6680u,0x0c0a6682u,0x0c0a6684u,0x0c0a6686u,0x0c0a6688u,0x0c0a668au,0x0c0a668cu,0x0c0a668eu,0x0c0a6690u,0x0c0a6692u,0x0c0a6694u,0x0c0a6696u,0x0c0a6698u,0x0c0a669au,0x0c0a669cu,
0x0c0a669eu,0x0c0a66a0u,0x0c0a66a2u,0x0c0a66a4u,0x0c0a66a6u,0x0c0a66a8u,0x0c0a66aau,0x0c0a66acu,0x0c0a66aeu,0x0c0a66b0u,0x0c0a66b2u,0x0c0a66b4u,0x0c0a66b6u,0x0c0a66b8u,0x0c0a66bau,0x0c0a66bcu,
0x0c0a66beu,0x0c0a66c0u,0x0c0a66c2u,0x0c0a66c4u,0x0c0a66c6u,0x0c0a66c8u,0x0c0a66cau,0x0c0a66ccu,0x0c0a66ceu,0x0c0a66d0u,0x0c0a66d2u,0x0c0a66d4u,0x0c0a66d6u,0x0c0a66d8u,0x0c0a66dau,0x0c0a66dcu,
0x0c0a66deu,0x0c0a66e0u,0x0c0a66e2u,0x0c0a66e4u,0x0c0a66e6u,0x0c0a66e8u,0x0c0a66eau,0x0c0a66ecu,0x0c0a66eeu,0x0c0a66f0u,0x0c0a66f2u,0x0c0a66f4u,0x0c0a66f6u,0x0c0a66f8u,0x0c0a66fau,0x0c0a66fcu,
0x0c0a66feu,0x0c0a6700u,0x0c0a6702u,0x0c0a6704u,0x0c0a6706u,0x0c0a6708u,0x0c0a670au,0x0c0a670cu,0x0c0a670eu,0x0c0a6710u,0x0c0a6712u,0x0c0a6714u,0x0c0a6716u,0x0c0a6718u,0x0c0a671au,0x0c0a671cu,
0x0c0a671eu,0x0c0a6720u,0x0c0a6722u,0x0c0a6724u,0x0c0a6726u,0x0c0a6728u,0x0c0a672au,0x0c0a672cu,0x0c0a672eu,0x0c0a6730u,0x0c0a6732u,0x0c0a6734u,0x0c0a6736u,0x0c0a6738u,0x0c0a673au,0x0c0a673cu,
0x0c0a673eu,0x0c0a6740u,0x0c0a6742u,0x0c0a6744u,0x0c0a6746u,0x0c0a6748u,0x0c0a674au,0x0c0a674cu,0x0c0a674eu,0x0c0a6750u,0x0c0a6752u,0x0c0a6754u,0x0c0a6756u,0x0c0a6758u,0x0c0a675au,0x0c0a675cu,
0x0c0a675eu,0x0c0a6760u,0x0c0a6762u,0x0c0a6764u,0x0c0a6766u,0x0c0a6768u,0x0c0a676au,0x0c0a676cu,0x0c0a676eu,0x0c0a6770u,0x0c0a6772u,0x0c0a6774u,0x0c0a6776u,0x0c0a6778u,0x0c0a677au,0x0c0a677cu,
0x0c0a677eu,0x0c0a6780u,0x0c0a6782u,0x0c0a6784u,0x0c0a6786u,0x0c0a6788u,
};
int vf3_c96_adapter_contains(uint32_t pc) {
pc&=0x1fffffffu; unsigned lo=0,hi=sizeof(claim_pcs)/sizeof(claim_pcs[0]);
while(lo<hi) { unsigned mid=lo+(hi-lo)/2; if(claim_pcs[mid]<pc) lo=mid+1; else hi=mid; }
return lo<sizeof(claim_pcs)/sizeof(claim_pcs[0]) && claim_pcs[lo]==pc;
}
