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
int vf3_away_batch32_adapter_0(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c0644e8u: goto P_0c0644e8;
case 0x0c0644eau: goto P_0c0644ea;
case 0x0c0644ecu: goto P_0c0644ec;
case 0x0c0644eeu: goto P_0c0644ee;
case 0x0c0644f0u: goto P_0c0644f0;
case 0x0c0644f2u: goto P_0c0644f2;
case 0x0c0644f4u: goto P_0c0644f4;
case 0x0c0644f6u: goto P_0c0644f6;
case 0x0c0644f8u: goto P_0c0644f8;
case 0x0c0644fau: goto P_0c0644fa;
case 0x0c0644fcu: goto P_0c0644fc;
case 0x0c0644feu: goto P_0c0644fe;
case 0x0c064500u: goto P_0c064500;
case 0x0c064502u: goto P_0c064502;
case 0x0c064504u: goto P_0c064504;
case 0x0c064506u: goto P_0c064506;
case 0x0c064508u: goto P_0c064508;
case 0x0c06450au: goto P_0c06450a;
case 0x0c06450cu: goto P_0c06450c;
case 0x0c06450eu: goto P_0c06450e;
case 0x0c064510u: goto P_0c064510;
case 0x0c064512u: goto P_0c064512;
case 0x0c064514u: goto P_0c064514;
case 0x0c064516u: goto P_0c064516;
case 0x0c064518u: goto P_0c064518;
case 0x0c06451au: goto P_0c06451a;
case 0x0c06451cu: goto P_0c06451c;
case 0x0c06451eu: goto P_0c06451e;
case 0x0c064520u: goto P_0c064520;
case 0x0c064522u: goto P_0c064522;
case 0x0c064524u: goto P_0c064524;
case 0x0c064526u: goto P_0c064526;
case 0x0c064528u: goto P_0c064528;
case 0x0c06452au: goto P_0c06452a;
case 0x0c06452cu: goto P_0c06452c;
case 0x0c06452eu: goto P_0c06452e;
case 0x0c064530u: goto P_0c064530;
case 0x0c064532u: goto P_0c064532;
case 0x0c064534u: goto P_0c064534;
case 0x0c064536u: goto P_0c064536;
case 0x0c064538u: goto P_0c064538;
case 0x0c06453au: goto P_0c06453a;
case 0x0c06453cu: goto P_0c06453c;
case 0x0c06453eu: goto P_0c06453e;
case 0x0c064540u: goto P_0c064540;
case 0x0c064542u: goto P_0c064542;
case 0x0c064544u: goto P_0c064544;
case 0x0c064546u: goto P_0c064546;
case 0x0c064548u: goto P_0c064548;
case 0x0c06454au: goto P_0c06454a;
case 0x0c06454cu: goto P_0c06454c;
case 0x0c06454eu: goto P_0c06454e;
case 0x0c064550u: goto P_0c064550;
case 0x0c064552u: goto P_0c064552;
case 0x0c064554u: goto P_0c064554;
case 0x0c064556u: goto P_0c064556;
case 0x0c064558u: goto P_0c064558;
case 0x0c06455au: goto P_0c06455a;
case 0x0c06455cu: goto P_0c06455c;
case 0x0c06455eu: goto P_0c06455e;
case 0x0c064560u: goto P_0c064560;
case 0x0c064562u: goto P_0c064562;
case 0x0c064564u: goto P_0c064564;
case 0x0c064566u: goto P_0c064566;
case 0x0c064568u: goto P_0c064568;
case 0x0c06456au: goto P_0c06456a;
case 0x0c06456cu: goto P_0c06456c;
case 0x0c06456eu: goto P_0c06456e;
case 0x0c064570u: goto P_0c064570;
case 0x0c064572u: goto P_0c064572;
case 0x0c064574u: goto P_0c064574;
case 0x0c064576u: goto P_0c064576;
case 0x0c064578u: goto P_0c064578;
case 0x0c06457au: goto P_0c06457a;
case 0x0c06457cu: goto P_0c06457c;
case 0x0c06457eu: goto P_0c06457e;
case 0x0c064580u: goto P_0c064580;
case 0x0c064582u: goto P_0c064582;
case 0x0c064584u: goto P_0c064584;
case 0x0c064586u: goto P_0c064586;
case 0x0c064588u: goto P_0c064588;
case 0x0c06458au: goto P_0c06458a;
case 0x0c06458cu: goto P_0c06458c;
case 0x0c06458eu: goto P_0c06458e;
case 0x0c064590u: goto P_0c064590;
case 0x0c064592u: goto P_0c064592;
case 0x0c064d90u: goto P_0c064d90;
case 0x0c064d92u: goto P_0c064d92;
case 0x0c064d94u: goto P_0c064d94;
case 0x0c064d96u: goto P_0c064d96;
case 0x0c064d98u: goto P_0c064d98;
case 0x0c064d9au: goto P_0c064d9a;
case 0x0c064d9cu: goto P_0c064d9c;
case 0x0c064d9eu: goto P_0c064d9e;
case 0x0c064da0u: goto P_0c064da0;
case 0x0c064da2u: goto P_0c064da2;
case 0x0c064da4u: goto P_0c064da4;
case 0x0c064da6u: goto P_0c064da6;
case 0x0c064da8u: goto P_0c064da8;
case 0x0c064daau: goto P_0c064daa;
case 0x0c064dacu: goto P_0c064dac;
case 0x0c064daeu: goto P_0c064dae;
case 0x0c064db0u: goto P_0c064db0;
case 0x0c064db2u: goto P_0c064db2;
case 0x0c064db4u: goto P_0c064db4;
case 0x0c064db6u: goto P_0c064db6;
case 0x0c064db8u: goto P_0c064db8;
case 0x0c064dbau: goto P_0c064dba;
case 0x0c064dbcu: goto P_0c064dbc;
case 0x0c064dbeu: goto P_0c064dbe;
case 0x0c064dc0u: goto P_0c064dc0;
case 0x0c064dc2u: goto P_0c064dc2;
case 0x0c064dc4u: goto P_0c064dc4;
case 0x0c064dc6u: goto P_0c064dc6;
case 0x0c064dc8u: goto P_0c064dc8;
case 0x0c064dcau: goto P_0c064dca;
case 0x0c064dccu: goto P_0c064dcc;
case 0x0c064dceu: goto P_0c064dce;
case 0x0c064dd0u: goto P_0c064dd0;
case 0x0c064dd2u: goto P_0c064dd2;
case 0x0c064dd4u: goto P_0c064dd4;
case 0x0c064dd6u: goto P_0c064dd6;
case 0x0c064dd8u: goto P_0c064dd8;
case 0x0c064ddau: goto P_0c064dda;
case 0x0c064ddcu: goto P_0c064ddc;
case 0x0c064ddeu: goto P_0c064dde;
case 0x0c064de0u: goto P_0c064de0;
case 0x0c064de2u: goto P_0c064de2;
case 0x0c064de4u: goto P_0c064de4;
case 0x0c064de6u: goto P_0c064de6;
case 0x0c064de8u: goto P_0c064de8;
case 0x0c064deau: goto P_0c064dea;
case 0x0c064decu: goto P_0c064dec;
case 0x0c064deeu: goto P_0c064dee;
case 0x0c064df0u: goto P_0c064df0;
case 0x0c064df2u: goto P_0c064df2;
case 0x0c064df4u: goto P_0c064df4;
case 0x0c064df6u: goto P_0c064df6;
case 0x0c064df8u: goto P_0c064df8;
case 0x0c064dfau: goto P_0c064dfa;
case 0x0c064dfcu: goto P_0c064dfc;
case 0x0c064dfeu: goto P_0c064dfe;
case 0x0c064e00u: goto P_0c064e00;
case 0x0c064e02u: goto P_0c064e02;
case 0x0c064e04u: goto P_0c064e04;
case 0x0c064e06u: goto P_0c064e06;
case 0x0c064e08u: goto P_0c064e08;
case 0x0c064e0au: goto P_0c064e0a;
case 0x0c064e0cu: goto P_0c064e0c;
case 0x0c064e0eu: goto P_0c064e0e;
case 0x0c064e10u: goto P_0c064e10;
case 0x0c064e12u: goto P_0c064e12;
case 0x0c064e14u: goto P_0c064e14;
case 0x0c064e16u: goto P_0c064e16;
case 0x0c064e18u: goto P_0c064e18;
case 0x0c064e1au: goto P_0c064e1a;
case 0x0c064e1cu: goto P_0c064e1c;
case 0x0c064e1eu: goto P_0c064e1e;
case 0x0c064e20u: goto P_0c064e20;
case 0x0c064e22u: goto P_0c064e22;
case 0x0c064e24u: goto P_0c064e24;
case 0x0c064e26u: goto P_0c064e26;
case 0x0c064e28u: goto P_0c064e28;
case 0x0c064e2au: goto P_0c064e2a;
case 0x0c064e2cu: goto P_0c064e2c;
case 0x0c064e2eu: goto P_0c064e2e;
case 0x0c064e30u: goto P_0c064e30;
case 0x0c064e32u: goto P_0c064e32;
case 0x0c064e34u: goto P_0c064e34;
case 0x0c064e36u: goto P_0c064e36;
case 0x0c064e38u: goto P_0c064e38;
case 0x0c064e3au: goto P_0c064e3a;
case 0x0c064e3cu: goto P_0c064e3c;
case 0x0c064e3eu: goto P_0c064e3e;
case 0x0c064e40u: goto P_0c064e40;
case 0x0c064e42u: goto P_0c064e42;
case 0x0c064e44u: goto P_0c064e44;
case 0x0c064e46u: goto P_0c064e46;
case 0x0c064e48u: goto P_0c064e48;
case 0x0c064e4au: goto P_0c064e4a;
case 0x0c064e4cu: goto P_0c064e4c;
case 0x0c064e4eu: goto P_0c064e4e;
case 0x0c064e50u: goto P_0c064e50;
case 0x0c064e52u: goto P_0c064e52;
case 0x0c064e54u: goto P_0c064e54;
case 0x0c064e56u: goto P_0c064e56;
case 0x0c064e58u: goto P_0c064e58;
case 0x0c064e5au: goto P_0c064e5a;
case 0x0c064e5cu: goto P_0c064e5c;
case 0x0c064e5eu: goto P_0c064e5e;
case 0x0c064e60u: goto P_0c064e60;
case 0x0c064e62u: goto P_0c064e62;
case 0x0c064e64u: goto P_0c064e64;
case 0x0c064e66u: goto P_0c064e66;
case 0x0c064e68u: goto P_0c064e68;
case 0x0c064e6au: goto P_0c064e6a;
case 0x0c064e6cu: goto P_0c064e6c;
case 0x0c064e6eu: goto P_0c064e6e;
case 0x0c064e70u: goto P_0c064e70;
case 0x0c064e72u: goto P_0c064e72;
case 0x0c064e74u: goto P_0c064e74;
case 0x0c064e76u: goto P_0c064e76;
case 0x0c064e78u: goto P_0c064e78;
case 0x0c064e7au: goto P_0c064e7a;
case 0x0c064e7cu: goto P_0c064e7c;
case 0x0c064e7eu: goto P_0c064e7e;
case 0x0c064e80u: goto P_0c064e80;
case 0x0c064e82u: goto P_0c064e82;
case 0x0c064e84u: goto P_0c064e84;
case 0x0c064e86u: goto P_0c064e86;
case 0x0c064e88u: goto P_0c064e88;
case 0x0c064e8au: goto P_0c064e8a;
case 0x0c064e8cu: goto P_0c064e8c;
case 0x0c064e8eu: goto P_0c064e8e;
case 0x0c064e90u: goto P_0c064e90;
case 0x0c064e92u: goto P_0c064e92;
case 0x0c064e94u: goto P_0c064e94;
case 0x0c064e96u: goto P_0c064e96;
case 0x0c064e98u: goto P_0c064e98;
case 0x0c064e9au: goto P_0c064e9a;
case 0x0c064e9cu: goto P_0c064e9c;
case 0x0c064e9eu: goto P_0c064e9e;
case 0x0c064ea0u: goto P_0c064ea0;
case 0x0c064ea2u: goto P_0c064ea2;
case 0x0c064ea4u: goto P_0c064ea4;
case 0x0c064ea6u: goto P_0c064ea6;
case 0x0c064ea8u: goto P_0c064ea8;
case 0x0c064eaau: goto P_0c064eaa;
case 0x0c064eacu: goto P_0c064eac;
case 0x0c064eaeu: goto P_0c064eae;
case 0x0c064eb0u: goto P_0c064eb0;
case 0x0c064eb2u: goto P_0c064eb2;
case 0x0c064eb4u: goto P_0c064eb4;
case 0x0c064eb6u: goto P_0c064eb6;
case 0x0c064eb8u: goto P_0c064eb8;
case 0x0c064ebau: goto P_0c064eba;
case 0x0c064ebcu: goto P_0c064ebc;
case 0x0c064ebeu: goto P_0c064ebe;
case 0x0c064ec0u: goto P_0c064ec0;
case 0x0c064ec2u: goto P_0c064ec2;
case 0x0c064ec4u: goto P_0c064ec4;
case 0x0c064ec6u: goto P_0c064ec6;
case 0x0c064ec8u: goto P_0c064ec8;
case 0x0c064ecau: goto P_0c064eca;
case 0x0c064eccu: goto P_0c064ecc;
case 0x0c064eceu: goto P_0c064ece;
case 0x0c064ed0u: goto P_0c064ed0;
case 0x0c064ed2u: goto P_0c064ed2;
case 0x0c064ed4u: goto P_0c064ed4;
case 0x0c064ed6u: goto P_0c064ed6;
case 0x0c064ed8u: goto P_0c064ed8;
case 0x0c064edau: goto P_0c064eda;
case 0x0c064edcu: goto P_0c064edc;
case 0x0c064edeu: goto P_0c064ede;
case 0x0c064ee0u: goto P_0c064ee0;
case 0x0c064ee2u: goto P_0c064ee2;
case 0x0c064ee4u: goto P_0c064ee4;
case 0x0c064ee6u: goto P_0c064ee6;
case 0x0c064ee8u: goto P_0c064ee8;
case 0x0c064eeau: goto P_0c064eea;
case 0x0c064eecu: goto P_0c064eec;
case 0x0c064eeeu: goto P_0c064eee;
case 0x0c064ef0u: goto P_0c064ef0;
case 0x0c064ef2u: goto P_0c064ef2;
case 0x0c064ef4u: goto P_0c064ef4;
case 0x0c064ef6u: goto P_0c064ef6;
case 0x0c064ef8u: goto P_0c064ef8;
case 0x0c064efau: goto P_0c064efa;
case 0x0c064efcu: goto P_0c064efc;
case 0x0c064efeu: goto P_0c064efe;
case 0x0c064f00u: goto P_0c064f00;
case 0x0c064f02u: goto P_0c064f02;
case 0x0c064f04u: goto P_0c064f04;
case 0x0c064f06u: goto P_0c064f06;
case 0x0c064f08u: goto P_0c064f08;
case 0x0c064f0au: goto P_0c064f0a;
case 0x0c064f0cu: goto P_0c064f0c;
case 0x0c064f0eu: goto P_0c064f0e;
case 0x0c064f10u: goto P_0c064f10;
case 0x0c064f12u: goto P_0c064f12;
case 0x0c064f14u: goto P_0c064f14;
case 0x0c064f16u: goto P_0c064f16;
case 0x0c064f18u: goto P_0c064f18;
case 0x0c064f1au: goto P_0c064f1a;
case 0x0c064f1cu: goto P_0c064f1c;
case 0x0c064f1eu: goto P_0c064f1e;
case 0x0c064f20u: goto P_0c064f20;
case 0x0c064f22u: goto P_0c064f22;
case 0x0c064f24u: goto P_0c064f24;
case 0x0c064f26u: goto P_0c064f26;
case 0x0c064f28u: goto P_0c064f28;
case 0x0c064f2au: goto P_0c064f2a;
case 0x0c064f2cu: goto P_0c064f2c;
case 0x0c064f2eu: goto P_0c064f2e;
case 0x0c064f30u: goto P_0c064f30;
case 0x0c064f32u: goto P_0c064f32;
case 0x0c064f34u: goto P_0c064f34;
case 0x0c064f36u: goto P_0c064f36;
case 0x0c064f38u: goto P_0c064f38;
case 0x0c064f3au: goto P_0c064f3a;
case 0x0c064f3cu: goto P_0c064f3c;
case 0x0c064f3eu: goto P_0c064f3e;
case 0x0c064f40u: goto P_0c064f40;
case 0x0c064f42u: goto P_0c064f42;
case 0x0c064f44u: goto P_0c064f44;
case 0x0c064f46u: goto P_0c064f46;
case 0x0c064f48u: goto P_0c064f48;
case 0x0c064f4au: goto P_0c064f4a;
case 0x0c064f4cu: goto P_0c064f4c;
case 0x0c064f4eu: goto P_0c064f4e;
case 0x0c064f50u: goto P_0c064f50;
case 0x0c064f52u: goto P_0c064f52;
case 0x0c064f54u: goto P_0c064f54;
case 0x0c064f56u: goto P_0c064f56;
case 0x0c064f58u: goto P_0c064f58;
case 0x0c064f5au: goto P_0c064f5a;
case 0x0c064f5cu: goto P_0c064f5c;
case 0x0c064f5eu: goto P_0c064f5e;
case 0x0c064f60u: goto P_0c064f60;
case 0x0c064f62u: goto P_0c064f62;
case 0x0c064f64u: goto P_0c064f64;
case 0x0c064f66u: goto P_0c064f66;
case 0x0c064f68u: goto P_0c064f68;
case 0x0c064f6au: goto P_0c064f6a;
case 0x0c064f6cu: goto P_0c064f6c;
case 0x0c064f6eu: goto P_0c064f6e;
case 0x0c064f70u: goto P_0c064f70;
case 0x0c064f72u: goto P_0c064f72;
case 0x0c064f74u: goto P_0c064f74;
case 0x0c064f76u: goto P_0c064f76;
case 0x0c064f78u: goto P_0c064f78;
case 0x0c064f7au: goto P_0c064f7a;
case 0x0c064f7cu: goto P_0c064f7c;
case 0x0c064f7eu: goto P_0c064f7e;
case 0x0c064f80u: goto P_0c064f80;
case 0x0c064f82u: goto P_0c064f82;
case 0x0c064f84u: goto P_0c064f84;
case 0x0c064f86u: goto P_0c064f86;
case 0x0c064f88u: goto P_0c064f88;
case 0x0c064f8au: goto P_0c064f8a;
case 0x0c064f8cu: goto P_0c064f8c;
case 0x0c064f8eu: goto P_0c064f8e;
case 0x0c064f90u: goto P_0c064f90;
case 0x0c064f92u: goto P_0c064f92;
case 0x0c064f94u: goto P_0c064f94;
case 0x0c064f96u: goto P_0c064f96;
case 0x0c064f98u: goto P_0c064f98;
case 0x0c064f9au: goto P_0c064f9a;
case 0x0c064f9cu: goto P_0c064f9c;
case 0x0c064f9eu: goto P_0c064f9e;
case 0x0c064fa0u: goto P_0c064fa0;
case 0x0c064fa2u: goto P_0c064fa2;
case 0x0c064fa4u: goto P_0c064fa4;
case 0x0c064fa6u: goto P_0c064fa6;
case 0x0c064fa8u: goto P_0c064fa8;
case 0x0c064faau: goto P_0c064faa;
case 0x0c064facu: goto P_0c064fac;
case 0x0c064faeu: goto P_0c064fae;
case 0x0c064fb0u: goto P_0c064fb0;
case 0x0c064fb2u: goto P_0c064fb2;
case 0x0c064fb4u: goto P_0c064fb4;
case 0x0c064fb6u: goto P_0c064fb6;
case 0x0c064fb8u: goto P_0c064fb8;
case 0x0c064fbau: goto P_0c064fba;
case 0x0c064fbcu: goto P_0c064fbc;
case 0x0c064fbeu: goto P_0c064fbe;
case 0x0c064fc0u: goto P_0c064fc0;
case 0x0c064fc2u: goto P_0c064fc2;
case 0x0c064fc4u: goto P_0c064fc4;
case 0x0c064fc6u: goto P_0c064fc6;
case 0x0c064fc8u: goto P_0c064fc8;
case 0x0c064fcau: goto P_0c064fca;
case 0x0c064fccu: goto P_0c064fcc;
case 0x0c064fceu: goto P_0c064fce;
case 0x0c064fd0u: goto P_0c064fd0;
case 0x0c064fd2u: goto P_0c064fd2;
case 0x0c064fd4u: goto P_0c064fd4;
case 0x0c064fd6u: goto P_0c064fd6;
case 0x0c064fd8u: goto P_0c064fd8;
case 0x0c064fdau: goto P_0c064fda;
case 0x0c064fdcu: goto P_0c064fdc;
case 0x0c064fdeu: goto P_0c064fde;
case 0x0c064fe0u: goto P_0c064fe0;
case 0x0c064fe2u: goto P_0c064fe2;
case 0x0c064fe4u: goto P_0c064fe4;
case 0x0c064fe6u: goto P_0c064fe6;
case 0x0c064fe8u: goto P_0c064fe8;
case 0x0c064feau: goto P_0c064fea;
case 0x0c064fecu: goto P_0c064fec;
case 0x0c064feeu: goto P_0c064fee;
case 0x0c064ff0u: goto P_0c064ff0;
case 0x0c064ff2u: goto P_0c064ff2;
case 0x0c064ff4u: goto P_0c064ff4;
case 0x0c064ff6u: goto P_0c064ff6;
case 0x0c064ff8u: goto P_0c064ff8;
case 0x0c064ffau: goto P_0c064ffa;
case 0x0c064ffcu: goto P_0c064ffc;
case 0x0c064ffeu: goto P_0c064ffe;
case 0x0c065000u: goto P_0c065000;
case 0x0c065002u: goto P_0c065002;
case 0x0c065004u: goto P_0c065004;
case 0x0c065006u: goto P_0c065006;
case 0x0c065008u: goto P_0c065008;
case 0x0c06500au: goto P_0c06500a;
case 0x0c06500cu: goto P_0c06500c;
case 0x0c06500eu: goto P_0c06500e;
case 0x0c065010u: goto P_0c065010;
case 0x0c065012u: goto P_0c065012;
case 0x0c065014u: goto P_0c065014;
case 0x0c065016u: goto P_0c065016;
case 0x0c065018u: goto P_0c065018;
case 0x0c06501au: goto P_0c06501a;
case 0x0c06501cu: goto P_0c06501c;
case 0x0c06501eu: goto P_0c06501e;
case 0x0c065020u: goto P_0c065020;
case 0x0c065022u: goto P_0c065022;
case 0x0c065024u: goto P_0c065024;
case 0x0c065026u: goto P_0c065026;
case 0x0c065028u: goto P_0c065028;
case 0x0c06502au: goto P_0c06502a;
case 0x0c06502cu: goto P_0c06502c;
case 0x0c06502eu: goto P_0c06502e;
case 0x0c065030u: goto P_0c065030;
case 0x0c065032u: goto P_0c065032;
case 0x0c065034u: goto P_0c065034;
case 0x0c065036u: goto P_0c065036;
case 0x0c065038u: goto P_0c065038;
case 0x0c06503au: goto P_0c06503a;
case 0x0c06503cu: goto P_0c06503c;
case 0x0c06503eu: goto P_0c06503e;
case 0x0c065040u: goto P_0c065040;
case 0x0c065042u: goto P_0c065042;
case 0x0c065044u: goto P_0c065044;
case 0x0c065046u: goto P_0c065046;
case 0x0c065048u: goto P_0c065048;
case 0x0c06504au: goto P_0c06504a;
case 0x0c06504cu: goto P_0c06504c;
case 0x0c06504eu: goto P_0c06504e;
case 0x0c065050u: goto P_0c065050;
case 0x0c065052u: goto P_0c065052;
case 0x0c065054u: goto P_0c065054;
case 0x0c065056u: goto P_0c065056;
case 0x0c065058u: goto P_0c065058;
case 0x0c06505au: goto P_0c06505a;
default: return vf3_matrix_family(target,s,ram);
}
P_0c0644e8: /* original d283, guest PC 0x0c0644e8 */
if(!s->budget--) { s->failed_pc=0x0c0644e8u; return 0; }
r[2]=read(ram,0x0c0646f8u,4);
goto P_0c0644ea;
P_0c0644ea: /* original 2668, guest PC 0x0c0644ea */
if(!s->budget--) { s->failed_pc=0x0c0644eau; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[6])==0)!=0);
goto P_0c0644ec;
P_0c0644ec: /* original e307, guest PC 0x0c0644ec */
if(!s->budget--) { s->failed_pc=0x0c0644ecu; return 0; }
r[3]=0x00000007u;
goto P_0c0644ee;
P_0c0644ee: /* original 2439, guest PC 0x0c0644ee */
if(!s->budget--) { s->failed_pc=0x0c0644eeu; return 0; }
r[4]&=r[3];
goto P_0c0644f0;
P_0c0644f0: /* original 4428, guest PC 0x0c0644f0 */
if(!s->budget--) { s->failed_pc=0x0c0644f0u; return 0; }
r[4]<<=16;
goto P_0c0644f2;
P_0c0644f2: /* original 4418, guest PC 0x0c0644f2 */
if(!s->budget--) { s->failed_pc=0x0c0644f2u; return 0; }
r[4]<<=8;
goto P_0c0644f4;
P_0c0644f4: /* original 8d04, guest PC 0x0c0644f4 */
if(!s->budget--) { s->failed_pc=0x0c0644f4u; return 0; }
cond=r[17]&1u;
write(ram,r[2],r[4],4);
if(cond) { goto P_0c064500; }
goto P_0c0644f8;
P_0c0644f6: /* original 2242, guest PC 0x0c0644f6 */
if(!s->budget--) { s->failed_pc=0x0c0644f6u; return 0; }
write(ram,r[2],r[4],4);
goto P_0c0644f8;
P_0c0644f8: /* original d180, guest PC 0x0c0644f8 */
if(!s->budget--) { s->failed_pc=0x0c0644f8u; return 0; }
r[1]=read(ram,0x0c0646fcu,4);
goto P_0c0644fa;
P_0c0644fa: /* original 6022, guest PC 0x0c0644fa */
if(!s->budget--) { s->failed_pc=0x0c0644fau; return 0; }
tmp=read(ram,r[2],4);
r[0]=tmp;
goto P_0c0644fc;
P_0c0644fc: /* original 201b, guest PC 0x0c0644fc */
if(!s->budget--) { s->failed_pc=0x0c0644fcu; return 0; }
r[0]|=r[1];
goto P_0c0644fe;
P_0c0644fe: /* original 2202, guest PC 0x0c0644fe */
if(!s->budget--) { s->failed_pc=0x0c0644feu; return 0; }
write(ram,r[2],r[0],4);
goto P_0c064500;
P_0c064500: /* original 2558, guest PC 0x0c064500 */
if(!s->budget--) { s->failed_pc=0x0c064500u; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[5])==0)!=0);
goto P_0c064502;
P_0c064502: /* original 8904, guest PC 0x0c064502 */
if(!s->budget--) { s->failed_pc=0x0c064502u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c06450e; }
goto P_0c064504;
P_0c064504: /* original d37c, guest PC 0x0c064504 */
if(!s->budget--) { s->failed_pc=0x0c064504u; return 0; }
r[3]=read(ram,0x0c0646f8u,4);
goto P_0c064506;
P_0c064506: /* original d27e, guest PC 0x0c064506 */
if(!s->budget--) { s->failed_pc=0x0c064506u; return 0; }
r[2]=read(ram,0x0c064700u,4);
goto P_0c064508;
P_0c064508: /* original 6132, guest PC 0x0c064508 */
if(!s->budget--) { s->failed_pc=0x0c064508u; return 0; }
tmp=read(ram,r[3],4);
r[1]=tmp;
goto P_0c06450a;
P_0c06450a: /* original 212b, guest PC 0x0c06450a */
if(!s->budget--) { s->failed_pc=0x0c06450au; return 0; }
r[1]|=r[2];
goto P_0c06450c;
P_0c06450c: /* original 2312, guest PC 0x0c06450c */
if(!s->budget--) { s->failed_pc=0x0c06450cu; return 0; }
write(ram,r[3],r[1],4);
goto P_0c06450e;
P_0c06450e: /* original 000b, guest PC 0x0c06450e */
if(!s->budget--) { s->failed_pc=0x0c06450eu; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c064510: /* original 0009, guest PC 0x0c064510 */
if(!s->budget--) { s->failed_pc=0x0c064510u; return 0; }
goto P_0c064512;
P_0c064512: /* original d37c, guest PC 0x0c064512 */
if(!s->budget--) { s->failed_pc=0x0c064512u; return 0; }
r[3]=read(ram,0x0c064704u,4);
goto P_0c064514;
P_0c064514: /* original 2348, guest PC 0x0c064514 */
if(!s->budget--) { s->failed_pc=0x0c064514u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[4])==0)!=0);
goto P_0c064516;
P_0c064516: /* original 8d09, guest PC 0x0c064516 */
if(!s->budget--) { s->failed_pc=0x0c064516u; return 0; }
cond=r[17]&1u;
r[5]=0x00000001u;
if(cond) { goto P_0c06452c; }
goto P_0c06451a;
P_0c064518: /* original e501, guest PC 0x0c064518 */
if(!s->budget--) { s->failed_pc=0x0c064518u; return 0; }
r[5]=0x00000001u;
goto P_0c06451a;
P_0c06451a: /* original d37b, guest PC 0x0c06451a */
if(!s->budget--) { s->failed_pc=0x0c06451au; return 0; }
r[3]=read(ram,0x0c064708u,4);
goto P_0c06451c;
P_0c06451c: /* original 2348, guest PC 0x0c06451c */
if(!s->budget--) { s->failed_pc=0x0c06451cu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[4])==0)!=0);
goto P_0c06451e;
P_0c06451e: /* original 8d01, guest PC 0x0c06451e */
if(!s->budget--) { s->failed_pc=0x0c06451eu; return 0; }
cond=r[17]&1u;
r[5]+=0x00000001u;
if(cond) { goto P_0c064524; }
goto P_0c064522;
P_0c064520: /* original 7501, guest PC 0x0c064520 */
if(!s->budget--) { s->failed_pc=0x0c064520u; return 0; }
r[5]+=0x00000001u;
goto P_0c064522;
P_0c064522: /* original 7501, guest PC 0x0c064522 */
if(!s->budget--) { s->failed_pc=0x0c064522u; return 0; }
r[5]+=0x00000001u;
goto P_0c064524;
P_0c064524: /* original d379, guest PC 0x0c064524 */
if(!s->budget--) { s->failed_pc=0x0c064524u; return 0; }
r[3]=read(ram,0x0c06470cu,4);
goto P_0c064526;
P_0c064526: /* original 2438, guest PC 0x0c064526 */
if(!s->budget--) { s->failed_pc=0x0c064526u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[3])==0)!=0);
goto P_0c064528;
P_0c064528: /* original 8b00, guest PC 0x0c064528 */
if(!s->budget--) { s->failed_pc=0x0c064528u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06452c; }
goto P_0c06452a;
P_0c06452a: /* original 7501, guest PC 0x0c06452a */
if(!s->budget--) { s->failed_pc=0x0c06452au; return 0; }
r[5]+=0x00000001u;
goto P_0c06452c;
P_0c06452c: /* original 000b, guest PC 0x0c06452c */
if(!s->budget--) { s->failed_pc=0x0c06452cu; return 0; }
target=r[16];
r[0]=r[5];
s->pc=target; return ram->oob==0;
P_0c06452e: /* original 6053, guest PC 0x0c06452e */
if(!s->budget--) { s->failed_pc=0x0c06452eu; return 0; }
r[0]=r[5];
goto P_0c064530;
P_0c064530: /* original d375, guest PC 0x0c064530 */
if(!s->budget--) { s->failed_pc=0x0c064530u; return 0; }
r[3]=read(ram,0x0c064708u,4);
goto P_0c064532;
P_0c064532: /* original 2438, guest PC 0x0c064532 */
if(!s->budget--) { s->failed_pc=0x0c064532u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[3])==0)!=0);
goto P_0c064534;
P_0c064534: /* original 8904, guest PC 0x0c064534 */
if(!s->budget--) { s->failed_pc=0x0c064534u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c064540; }
goto P_0c064536;
P_0c064536: /* original 6153, guest PC 0x0c064536 */
if(!s->budget--) { s->failed_pc=0x0c064536u; return 0; }
r[1]=r[5];
goto P_0c064538;
P_0c064538: /* original d075, guest PC 0x0c064538 */
if(!s->budget--) { s->failed_pc=0x0c064538u; return 0; }
r[0]=read(ram,0x0c064710u,4);
goto P_0c06453a;
P_0c06453a: /* original 7501, guest PC 0x0c06453a */
if(!s->budget--) { s->failed_pc=0x0c06453au; return 0; }
r[5]+=0x00000001u;
goto P_0c06453c;
P_0c06453c: /* original 4108, guest PC 0x0c06453c */
if(!s->budget--) { s->failed_pc=0x0c06453cu; return 0; }
r[1]<<=2;
goto P_0c06453e;
P_0c06453e: /* original 0166, guest PC 0x0c06453e */
if(!s->budget--) { s->failed_pc=0x0c06453eu; return 0; }
write(ram,r[1]+r[0],r[6],4);
goto P_0c064540;
P_0c064540: /* original 000b, guest PC 0x0c064540 */
if(!s->budget--) { s->failed_pc=0x0c064540u; return 0; }
target=r[16];
r[0]=r[5];
s->pc=target; return ram->oob==0;
P_0c064542: /* original 6053, guest PC 0x0c064542 */
if(!s->budget--) { s->failed_pc=0x0c064542u; return 0; }
r[0]=r[5];
goto P_0c064544;
P_0c064544: /* original d36f, guest PC 0x0c064544 */
if(!s->budget--) { s->failed_pc=0x0c064544u; return 0; }
r[3]=read(ram,0x0c064704u,4);
goto P_0c064546;
P_0c064546: /* original 2348, guest PC 0x0c064546 */
if(!s->budget--) { s->failed_pc=0x0c064546u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[4])==0)!=0);
goto P_0c064548;
P_0c064548: /* original 8914, guest PC 0x0c064548 */
if(!s->budget--) { s->failed_pc=0x0c064548u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c064574; }
goto P_0c06454a;
P_0c06454a: /* original d170, guest PC 0x0c06454a */
if(!s->budget--) { s->failed_pc=0x0c06454au; return 0; }
r[1]=read(ram,0x0c06470cu,4);
goto P_0c06454c;
P_0c06454c: /* original 2418, guest PC 0x0c06454c */
if(!s->budget--) { s->failed_pc=0x0c06454cu; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[1])==0)!=0);
goto P_0c06454e;
P_0c06454e: /* original 8904, guest PC 0x0c06454e */
if(!s->budget--) { s->failed_pc=0x0c06454eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c06455a; }
goto P_0c064550;
P_0c064550: /* original d06f, guest PC 0x0c064550 */
if(!s->budget--) { s->failed_pc=0x0c064550u; return 0; }
r[0]=read(ram,0x0c064710u,4);
goto P_0c064552;
P_0c064552: /* original 6253, guest PC 0x0c064552 */
if(!s->budget--) { s->failed_pc=0x0c064552u; return 0; }
r[2]=r[5];
goto P_0c064554;
P_0c064554: /* original 7501, guest PC 0x0c064554 */
if(!s->budget--) { s->failed_pc=0x0c064554u; return 0; }
r[5]+=0x00000001u;
goto P_0c064556;
P_0c064556: /* original a00c, guest PC 0x0c064556 */
if(!s->budget--) { s->failed_pc=0x0c064556u; return 0; }
r[2]<<=2;
goto P_0c064572;
P_0c064558: /* original 4208, guest PC 0x0c064558 */
if(!s->budget--) { s->failed_pc=0x0c064558u; return 0; }
r[2]<<=2;
goto P_0c06455a;
P_0c06455a: /* original 6253, guest PC 0x0c06455a */
if(!s->budget--) { s->failed_pc=0x0c06455au; return 0; }
r[2]=r[5];
goto P_0c06455c;
P_0c06455c: /* original d36d, guest PC 0x0c06455c */
if(!s->budget--) { s->failed_pc=0x0c06455cu; return 0; }
r[3]=read(ram,0x0c064714u,4);
goto P_0c06455e;
P_0c06455e: /* original 7501, guest PC 0x0c06455e */
if(!s->budget--) { s->failed_pc=0x0c06455eu; return 0; }
r[5]+=0x00000001u;
goto P_0c064560;
P_0c064560: /* original d06b, guest PC 0x0c064560 */
if(!s->budget--) { s->failed_pc=0x0c064560u; return 0; }
r[0]=read(ram,0x0c064710u,4);
goto P_0c064562;
P_0c064562: /* original 4208, guest PC 0x0c064562 */
if(!s->budget--) { s->failed_pc=0x0c064562u; return 0; }
r[2]<<=2;
goto P_0c064564;
P_0c064564: /* original 2369, guest PC 0x0c064564 */
if(!s->budget--) { s->failed_pc=0x0c064564u; return 0; }
r[3]&=r[6];
goto P_0c064566;
P_0c064566: /* original 0236, guest PC 0x0c064566 */
if(!s->budget--) { s->failed_pc=0x0c064566u; return 0; }
write(ram,r[2]+r[0],r[3],4);
goto P_0c064568;
P_0c064568: /* original 6253, guest PC 0x0c064568 */
if(!s->budget--) { s->failed_pc=0x0c064568u; return 0; }
r[2]=r[5];
goto P_0c06456a;
P_0c06456a: /* original 7501, guest PC 0x0c06456a */
if(!s->budget--) { s->failed_pc=0x0c06456au; return 0; }
r[5]+=0x00000001u;
goto P_0c06456c;
P_0c06456c: /* original 4208, guest PC 0x0c06456c */
if(!s->budget--) { s->failed_pc=0x0c06456cu; return 0; }
r[2]<<=2;
goto P_0c06456e;
P_0c06456e: /* original 666d, guest PC 0x0c06456e */
if(!s->budget--) { s->failed_pc=0x0c06456eu; return 0; }
r[6]=r[6]&65535u;
goto P_0c064570;
P_0c064570: /* original 4628, guest PC 0x0c064570 */
if(!s->budget--) { s->failed_pc=0x0c064570u; return 0; }
r[6]<<=16;
goto P_0c064572;
P_0c064572: /* original 0266, guest PC 0x0c064572 */
if(!s->budget--) { s->failed_pc=0x0c064572u; return 0; }
write(ram,r[2]+r[0],r[6],4);
goto P_0c064574;
P_0c064574: /* original 000b, guest PC 0x0c064574 */
if(!s->budget--) { s->failed_pc=0x0c064574u; return 0; }
target=r[16];
r[0]=r[5];
s->pc=target; return ram->oob==0;
P_0c064576: /* original 6053, guest PC 0x0c064576 */
if(!s->budget--) { s->failed_pc=0x0c064576u; return 0; }
r[0]=r[5];
goto P_0c064578;
P_0c064578: /* original d362, guest PC 0x0c064578 */
if(!s->budget--) { s->failed_pc=0x0c064578u; return 0; }
r[3]=read(ram,0x0c064704u,4);
goto P_0c06457a;
P_0c06457a: /* original 2438, guest PC 0x0c06457a */
if(!s->budget--) { s->failed_pc=0x0c06457au; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[3])==0)!=0);
goto P_0c06457c;
P_0c06457c: /* original 8908, guest PC 0x0c06457c */
if(!s->budget--) { s->failed_pc=0x0c06457cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c064590; }
goto P_0c06457e;
P_0c06457e: /* original 6153, guest PC 0x0c06457e */
if(!s->budget--) { s->failed_pc=0x0c06457eu; return 0; }
r[1]=r[5];
goto P_0c064580;
P_0c064580: /* original d063, guest PC 0x0c064580 */
if(!s->budget--) { s->failed_pc=0x0c064580u; return 0; }
r[0]=read(ram,0x0c064710u,4);
goto P_0c064582;
P_0c064582: /* original 7501, guest PC 0x0c064582 */
if(!s->budget--) { s->failed_pc=0x0c064582u; return 0; }
r[5]+=0x00000001u;
goto P_0c064584;
P_0c064584: /* original 4108, guest PC 0x0c064584 */
if(!s->budget--) { s->failed_pc=0x0c064584u; return 0; }
r[1]<<=2;
goto P_0c064586;
P_0c064586: /* original 0166, guest PC 0x0c064586 */
if(!s->budget--) { s->failed_pc=0x0c064586u; return 0; }
write(ram,r[1]+r[0],r[6],4);
goto P_0c064588;
P_0c064588: /* original 6253, guest PC 0x0c064588 */
if(!s->budget--) { s->failed_pc=0x0c064588u; return 0; }
r[2]=r[5];
goto P_0c06458a;
P_0c06458a: /* original 7501, guest PC 0x0c06458a */
if(!s->budget--) { s->failed_pc=0x0c06458au; return 0; }
r[5]+=0x00000001u;
goto P_0c06458c;
P_0c06458c: /* original 4208, guest PC 0x0c06458c */
if(!s->budget--) { s->failed_pc=0x0c06458cu; return 0; }
r[2]<<=2;
goto P_0c06458e;
P_0c06458e: /* original 0276, guest PC 0x0c06458e */
if(!s->budget--) { s->failed_pc=0x0c06458eu; return 0; }
write(ram,r[2]+r[0],r[7],4);
goto P_0c064590;
P_0c064590: /* original 000b, guest PC 0x0c064590 */
if(!s->budget--) { s->failed_pc=0x0c064590u; return 0; }
target=r[16];
r[0]=r[5];
s->pc=target; return ram->oob==0;
P_0c064592: /* original 6053, guest PC 0x0c064592 */
if(!s->budget--) { s->failed_pc=0x0c064592u; return 0; }
r[0]=r[5];
if(!vf3_matrix_family(0x0c064594u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c064594u; return 0; } return 1;
P_0c064d90: /* original 2fe6, guest PC 0x0c064d90 */
if(!s->budget--) { s->failed_pc=0x0c064d90u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c064d92;
P_0c064d92: /* original 2fd6, guest PC 0x0c064d92 */
if(!s->budget--) { s->failed_pc=0x0c064d92u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c064d94;
P_0c064d94: /* original 2fc6, guest PC 0x0c064d94 */
if(!s->budget--) { s->failed_pc=0x0c064d94u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c064d96;
P_0c064d96: /* original ec00, guest PC 0x0c064d96 */
if(!s->budget--) { s->failed_pc=0x0c064d96u; return 0; }
r[12]=0x00000000u;
goto P_0c064d98;
P_0c064d98: /* original 2fb6, guest PC 0x0c064d98 */
if(!s->budget--) { s->failed_pc=0x0c064d98u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c064d9a;
P_0c064d9a: /* original 2fa6, guest PC 0x0c064d9a */
if(!s->budget--) { s->failed_pc=0x0c064d9au; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c064d9c;
P_0c064d9c: /* original 2f96, guest PC 0x0c064d9c */
if(!s->budget--) { s->failed_pc=0x0c064d9cu; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c064d9e;
P_0c064d9e: /* original fffb, guest PC 0x0c064d9e */
if(!s->budget--) { s->failed_pc=0x0c064d9eu; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c064da0;
P_0c064da0: /* original 4f22, guest PC 0x0c064da0 */
if(!s->budget--) { s->failed_pc=0x0c064da0u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c064da2;
P_0c064da2: /* original 7ff0, guest PC 0x0c064da2 */
if(!s->budget--) { s->failed_pc=0x0c064da2u; return 0; }
r[15]+=0xfffffff0u;
goto P_0c064da4;
P_0c064da4: /* original 6342, guest PC 0x0c064da4 */
if(!s->budget--) { s->failed_pc=0x0c064da4u; return 0; }
tmp=read(ram,r[4],4);
r[3]=tmp;
goto P_0c064da6;
P_0c064da6: /* original 65f3, guest PC 0x0c064da6 */
if(!s->budget--) { s->failed_pc=0x0c064da6u; return 0; }
r[5]=r[15];
goto P_0c064da8;
P_0c064da8: /* original 7504, guest PC 0x0c064da8 */
if(!s->budget--) { s->failed_pc=0x0c064da8u; return 0; }
r[5]+=0x00000004u;
goto P_0c064daa;
P_0c064daa: /* original 6d53, guest PC 0x0c064daa */
if(!s->budget--) { s->failed_pc=0x0c064daau; return 0; }
r[13]=r[5];
goto P_0c064dac;
P_0c064dac: /* original 2d32, guest PC 0x0c064dac */
if(!s->budget--) { s->failed_pc=0x0c064dacu; return 0; }
write(ram,r[13],r[3],4);
goto P_0c064dae;
P_0c064dae: /* original 6bd3, guest PC 0x0c064dae */
if(!s->budget--) { s->failed_pc=0x0c064daeu; return 0; }
r[11]=r[13];
goto P_0c064db0;
P_0c064db0: /* original 5241, guest PC 0x0c064db0 */
if(!s->budget--) { s->failed_pc=0x0c064db0u; return 0; }
r[2]=read(ram,r[4]+4,4);
goto P_0c064db2;
P_0c064db2: /* original 6ad3, guest PC 0x0c064db2 */
if(!s->budget--) { s->failed_pc=0x0c064db2u; return 0; }
r[10]=r[13];
goto P_0c064db4;
P_0c064db4: /* original 7b04, guest PC 0x0c064db4 */
if(!s->budget--) { s->failed_pc=0x0c064db4u; return 0; }
r[11]+=0x00000004u;
goto P_0c064db6;
P_0c064db6: /* original 7a08, guest PC 0x0c064db6 */
if(!s->budget--) { s->failed_pc=0x0c064db6u; return 0; }
r[10]+=0x00000008u;
goto P_0c064db8;
P_0c064db8: /* original 2b22, guest PC 0x0c064db8 */
if(!s->budget--) { s->failed_pc=0x0c064db8u; return 0; }
write(ram,r[11],r[2],4);
goto P_0c064dba;
P_0c064dba: /* original 5342, guest PC 0x0c064dba */
if(!s->budget--) { s->failed_pc=0x0c064dbau; return 0; }
r[3]=read(ram,r[4]+8,4);
goto P_0c064dbc;
P_0c064dbc: /* original d2a7, guest PC 0x0c064dbc */
if(!s->budget--) { s->failed_pc=0x0c064dbcu; return 0; }
r[2]=read(ram,0x0c06505cu,4);
goto P_0c064dbe;
P_0c064dbe: /* original 2a32, guest PC 0x0c064dbe */
if(!s->budget--) { s->failed_pc=0x0c064dbeu; return 0; }
write(ram,r[10],r[3],4);
goto P_0c064dc0;
P_0c064dc0: /* original 6e22, guest PC 0x0c064dc0 */
if(!s->budget--) { s->failed_pc=0x0c064dc0u; return 0; }
tmp=read(ram,r[2],4);
r[14]=tmp;
goto P_0c064dc2;
P_0c064dc2: /* original d3a7, guest PC 0x0c064dc2 */
if(!s->budget--) { s->failed_pc=0x0c064dc2u; return 0; }
r[3]=read(ram,0x0c065060u,4);
goto P_0c064dc4;
P_0c064dc4: /* original 6532, guest PC 0x0c064dc4 */
if(!s->budget--) { s->failed_pc=0x0c064dc4u; return 0; }
tmp=read(ram,r[3],4);
r[5]=tmp;
goto P_0c064dc6;
P_0c064dc6: /* original d1a7, guest PC 0x0c064dc6 */
if(!s->budget--) { s->failed_pc=0x0c064dc6u; return 0; }
r[1]=read(ram,0x0c065064u,4);
goto P_0c064dc8;
P_0c064dc8: /* original 6412, guest PC 0x0c064dc8 */
if(!s->budget--) { s->failed_pc=0x0c064dc8u; return 0; }
tmp=read(ram,r[1],4);
r[4]=tmp;
goto P_0c064dca;
P_0c064dca: /* original d0a7, guest PC 0x0c064dca */
if(!s->budget--) { s->failed_pc=0x0c064dcau; return 0; }
r[0]=read(ram,0x0c065068u,4);
goto P_0c064dcc;
P_0c064dcc: /* original 62c3, guest PC 0x0c064dcc */
if(!s->budget--) { s->failed_pc=0x0c064dccu; return 0; }
r[2]=r[12];
goto P_0c064dce;
P_0c064dce: /* original 7c01, guest PC 0x0c064dce */
if(!s->budget--) { s->failed_pc=0x0c064dceu; return 0; }
r[12]+=0x00000001u;
goto P_0c064dd0;
P_0c064dd0: /* original 4208, guest PC 0x0c064dd0 */
if(!s->budget--) { s->failed_pc=0x0c064dd0u; return 0; }
r[2]<<=2;
goto P_0c064dd2;
P_0c064dd2: /* original 02e6, guest PC 0x0c064dd2 */
if(!s->budget--) { s->failed_pc=0x0c064dd2u; return 0; }
write(ram,r[2]+r[0],r[14],4);
goto P_0c064dd4;
P_0c064dd4: /* original 63c3, guest PC 0x0c064dd4 */
if(!s->budget--) { s->failed_pc=0x0c064dd4u; return 0; }
r[3]=r[12];
goto P_0c064dd6;
P_0c064dd6: /* original 7c01, guest PC 0x0c064dd6 */
if(!s->budget--) { s->failed_pc=0x0c064dd6u; return 0; }
r[12]+=0x00000001u;
goto P_0c064dd8;
P_0c064dd8: /* original 4308, guest PC 0x0c064dd8 */
if(!s->budget--) { s->failed_pc=0x0c064dd8u; return 0; }
r[3]<<=2;
goto P_0c064dda;
P_0c064dda: /* original 0356, guest PC 0x0c064dda */
if(!s->budget--) { s->failed_pc=0x0c064ddau; return 0; }
write(ram,r[3]+r[0],r[5],4);
goto P_0c064ddc;
P_0c064ddc: /* original 62c3, guest PC 0x0c064ddc */
if(!s->budget--) { s->failed_pc=0x0c064ddcu; return 0; }
r[2]=r[12];
goto P_0c064dde;
P_0c064dde: /* original 7c01, guest PC 0x0c064dde */
if(!s->budget--) { s->failed_pc=0x0c064ddeu; return 0; }
r[12]+=0x00000001u;
goto P_0c064de0;
P_0c064de0: /* original 4208, guest PC 0x0c064de0 */
if(!s->budget--) { s->failed_pc=0x0c064de0u; return 0; }
r[2]<<=2;
goto P_0c064de2;
P_0c064de2: /* original 0246, guest PC 0x0c064de2 */
if(!s->budget--) { s->failed_pc=0x0c064de2u; return 0; }
write(ram,r[2]+r[0],r[4],4);
goto P_0c064de4;
P_0c064de4: /* original 62d2, guest PC 0x0c064de4 */
if(!s->budget--) { s->failed_pc=0x0c064de4u; return 0; }
tmp=read(ram,r[13],4);
r[2]=tmp;
goto P_0c064de6;
P_0c064de6: /* original 63c3, guest PC 0x0c064de6 */
if(!s->budget--) { s->failed_pc=0x0c064de6u; return 0; }
r[3]=r[12];
goto P_0c064de8;
P_0c064de8: /* original 5221, guest PC 0x0c064de8 */
if(!s->budget--) { s->failed_pc=0x0c064de8u; return 0; }
r[2]=read(ram,r[2]+4,4);
goto P_0c064dea;
P_0c064dea: /* original 7c01, guest PC 0x0c064dea */
if(!s->budget--) { s->failed_pc=0x0c064deau; return 0; }
r[12]+=0x00000001u;
goto P_0c064dec;
P_0c064dec: /* original 4308, guest PC 0x0c064dec */
if(!s->budget--) { s->failed_pc=0x0c064decu; return 0; }
r[3]<<=2;
goto P_0c064dee;
P_0c064dee: /* original 0326, guest PC 0x0c064dee */
if(!s->budget--) { s->failed_pc=0x0c064deeu; return 0; }
write(ram,r[3]+r[0],r[2],4);
goto P_0c064df0;
P_0c064df0: /* original 62d2, guest PC 0x0c064df0 */
if(!s->budget--) { s->failed_pc=0x0c064df0u; return 0; }
tmp=read(ram,r[13],4);
r[2]=tmp;
goto P_0c064df2;
P_0c064df2: /* original 63c3, guest PC 0x0c064df2 */
if(!s->budget--) { s->failed_pc=0x0c064df2u; return 0; }
r[3]=r[12];
goto P_0c064df4;
P_0c064df4: /* original 5222, guest PC 0x0c064df4 */
if(!s->budget--) { s->failed_pc=0x0c064df4u; return 0; }
r[2]=read(ram,r[2]+8,4);
goto P_0c064df6;
P_0c064df6: /* original 7c01, guest PC 0x0c064df6 */
if(!s->budget--) { s->failed_pc=0x0c064df6u; return 0; }
r[12]+=0x00000001u;
goto P_0c064df8;
P_0c064df8: /* original 4308, guest PC 0x0c064df8 */
if(!s->budget--) { s->failed_pc=0x0c064df8u; return 0; }
r[3]<<=2;
goto P_0c064dfa;
P_0c064dfa: /* original 0326, guest PC 0x0c064dfa */
if(!s->budget--) { s->failed_pc=0x0c064dfau; return 0; }
write(ram,r[3]+r[0],r[2],4);
goto P_0c064dfc;
P_0c064dfc: /* original 62d2, guest PC 0x0c064dfc */
if(!s->budget--) { s->failed_pc=0x0c064dfcu; return 0; }
tmp=read(ram,r[13],4);
r[2]=tmp;
goto P_0c064dfe;
P_0c064dfe: /* original 63c3, guest PC 0x0c064dfe */
if(!s->budget--) { s->failed_pc=0x0c064dfeu; return 0; }
r[3]=r[12];
goto P_0c064e00;
P_0c064e00: /* original 5223, guest PC 0x0c064e00 */
if(!s->budget--) { s->failed_pc=0x0c064e00u; return 0; }
r[2]=read(ram,r[2]+12,4);
goto P_0c064e02;
P_0c064e02: /* original 7c01, guest PC 0x0c064e02 */
if(!s->budget--) { s->failed_pc=0x0c064e02u; return 0; }
r[12]+=0x00000001u;
goto P_0c064e04;
P_0c064e04: /* original 4308, guest PC 0x0c064e04 */
if(!s->budget--) { s->failed_pc=0x0c064e04u; return 0; }
r[3]<<=2;
goto P_0c064e06;
P_0c064e06: /* original 0326, guest PC 0x0c064e06 */
if(!s->budget--) { s->failed_pc=0x0c064e06u; return 0; }
write(ram,r[3]+r[0],r[2],4);
goto P_0c064e08;
P_0c064e08: /* original 67d2, guest PC 0x0c064e08 */
if(!s->budget--) { s->failed_pc=0x0c064e08u; return 0; }
tmp=read(ram,r[13],4);
r[7]=tmp;
goto P_0c064e0a;
P_0c064e0a: /* original 2f72, guest PC 0x0c064e0a */
if(!s->budget--) { s->failed_pc=0x0c064e0au; return 0; }
write(ram,r[15],r[7],4);
goto P_0c064e0c;
P_0c064e0c: /* original 5775, guest PC 0x0c064e0c */
if(!s->budget--) { s->failed_pc=0x0c064e0cu; return 0; }
r[7]=read(ram,r[7]+20,4);
goto P_0c064e0e;
P_0c064e0e: /* original 65c3, guest PC 0x0c064e0e */
if(!s->budget--) { s->failed_pc=0x0c064e0eu; return 0; }
r[5]=r[12];
goto P_0c064e10;
P_0c064e10: /* original 66f2, guest PC 0x0c064e10 */
if(!s->budget--) { s->failed_pc=0x0c064e10u; return 0; }
tmp=read(ram,r[15],4);
r[6]=tmp;
goto P_0c064e12;
P_0c064e12: /* original 5664, guest PC 0x0c064e12 */
if(!s->budget--) { s->failed_pc=0x0c064e12u; return 0; }
r[6]=read(ram,r[6]+16,4);
goto P_0c064e14;
P_0c064e14: /* original bbb0, guest PC 0x0c064e14 */
if(!s->budget--) { s->failed_pc=0x0c064e14u; return 0; }
target=code_base|0x0c064578u; r[16]=code_base|0x0c064e18u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c064e18u) { target=s->pc; goto dispatch; }
goto P_0c064e18;
P_0c064e16: /* original 64e3, guest PC 0x0c064e16 */
if(!s->budget--) { s->failed_pc=0x0c064e16u; return 0; }
r[4]=r[14];
goto P_0c064e18;
P_0c064e18: /* original 64d2, guest PC 0x0c064e18 */
if(!s->budget--) { s->failed_pc=0x0c064e18u; return 0; }
tmp=read(ram,r[13],4);
r[4]=tmp;
goto P_0c064e1a;
P_0c064e1a: /* original e120, guest PC 0x0c064e1a */
if(!s->budget--) { s->failed_pc=0x0c064e1au; return 0; }
r[1]=0x00000020u;
goto P_0c064e1c;
P_0c064e1c: /* original 6903, guest PC 0x0c064e1c */
if(!s->budget--) { s->failed_pc=0x0c064e1cu; return 0; }
r[9]=r[0];
goto P_0c064e1e;
P_0c064e1e: /* original 6393, guest PC 0x0c064e1e */
if(!s->budget--) { s->failed_pc=0x0c064e1eu; return 0; }
r[3]=r[9];
goto P_0c064e20;
P_0c064e20: /* original c792, guest PC 0x0c064e20 */
if(!s->budget--) { s->failed_pc=0x0c064e20u; return 0; }
r[0]=code_base|0x0006506cu;
goto P_0c064e22;
P_0c064e22: /* original 314c, guest PC 0x0c064e22 */
if(!s->budget--) { s->failed_pc=0x0c064e22u; return 0; }
r[1]+=r[4];
goto P_0c064e24;
P_0c064e24: /* original ff08, guest PC 0x0c064e24 */
if(!s->budget--) { s->failed_pc=0x0c064e24u; return 0; }
vf3_matrix_load(s,ram,15,r[0]);
goto P_0c064e26;
P_0c064e26: /* original 7901, guest PC 0x0c064e26 */
if(!s->budget--) { s->failed_pc=0x0c064e26u; return 0; }
r[9]+=0x00000001u;
goto P_0c064e28;
P_0c064e28: /* original f318, guest PC 0x0c064e28 */
if(!s->budget--) { s->failed_pc=0x0c064e28u; return 0; }
vf3_matrix_load(s,ram,3,r[1]);
goto P_0c064e2a;
P_0c064e2a: /* original 4308, guest PC 0x0c064e2a */
if(!s->budget--) { s->failed_pc=0x0c064e2au; return 0; }
r[3]<<=2;
goto P_0c064e2c;
P_0c064e2c: /* original d08e, guest PC 0x0c064e2c */
if(!s->budget--) { s->failed_pc=0x0c064e2cu; return 0; }
r[0]=read(ram,0x0c065068u,4);
goto P_0c064e2e;
P_0c064e2e: /* original f3f2, guest PC 0x0c064e2e */
if(!s->budget--) { s->failed_pc=0x0c064e2eu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[15],r[18],'*');
goto P_0c064e30;
P_0c064e30: /* original f33d, guest PC 0x0c064e30 */
if(!s->budget--) { s->failed_pc=0x0c064e30u; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c064e32;
P_0c064e32: /* original e124, guest PC 0x0c064e32 */
if(!s->budget--) { s->failed_pc=0x0c064e32u; return 0; }
r[1]=0x00000024u;
goto P_0c064e34;
P_0c064e34: /* original 025a, guest PC 0x0c064e34 */
if(!s->budget--) { s->failed_pc=0x0c064e34u; return 0; }
r[2]=r[53];
goto P_0c064e36;
P_0c064e36: /* original 4228, guest PC 0x0c064e36 */
if(!s->budget--) { s->failed_pc=0x0c064e36u; return 0; }
r[2]<<=16;
goto P_0c064e38;
P_0c064e38: /* original 4218, guest PC 0x0c064e38 */
if(!s->budget--) { s->failed_pc=0x0c064e38u; return 0; }
r[2]<<=8;
goto P_0c064e3a;
P_0c064e3a: /* original 314c, guest PC 0x0c064e3a */
if(!s->budget--) { s->failed_pc=0x0c064e3au; return 0; }
r[1]+=r[4];
goto P_0c064e3c;
P_0c064e3c: /* original f318, guest PC 0x0c064e3c */
if(!s->budget--) { s->failed_pc=0x0c064e3cu; return 0; }
vf3_matrix_load(s,ram,3,r[1]);
goto P_0c064e3e;
P_0c064e3e: /* original f3f2, guest PC 0x0c064e3e */
if(!s->budget--) { s->failed_pc=0x0c064e3eu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[15],r[18],'*');
goto P_0c064e40;
P_0c064e40: /* original f33d, guest PC 0x0c064e40 */
if(!s->budget--) { s->failed_pc=0x0c064e40u; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c064e42;
P_0c064e42: /* original 015a, guest PC 0x0c064e42 */
if(!s->budget--) { s->failed_pc=0x0c064e42u; return 0; }
r[1]=r[53];
goto P_0c064e44;
P_0c064e44: /* original 4128, guest PC 0x0c064e44 */
if(!s->budget--) { s->failed_pc=0x0c064e44u; return 0; }
r[1]<<=16;
goto P_0c064e46;
P_0c064e46: /* original 221b, guest PC 0x0c064e46 */
if(!s->budget--) { s->failed_pc=0x0c064e46u; return 0; }
r[2]|=r[1];
goto P_0c064e48;
P_0c064e48: /* original e128, guest PC 0x0c064e48 */
if(!s->budget--) { s->failed_pc=0x0c064e48u; return 0; }
r[1]=0x00000028u;
goto P_0c064e4a;
P_0c064e4a: /* original 314c, guest PC 0x0c064e4a */
if(!s->budget--) { s->failed_pc=0x0c064e4au; return 0; }
r[1]+=r[4];
goto P_0c064e4c;
P_0c064e4c: /* original f318, guest PC 0x0c064e4c */
if(!s->budget--) { s->failed_pc=0x0c064e4cu; return 0; }
vf3_matrix_load(s,ram,3,r[1]);
goto P_0c064e4e;
P_0c064e4e: /* original f3f2, guest PC 0x0c064e4e */
if(!s->budget--) { s->failed_pc=0x0c064e4eu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[15],r[18],'*');
goto P_0c064e50;
P_0c064e50: /* original f33d, guest PC 0x0c064e50 */
if(!s->budget--) { s->failed_pc=0x0c064e50u; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c064e52;
P_0c064e52: /* original 015a, guest PC 0x0c064e52 */
if(!s->budget--) { s->failed_pc=0x0c064e52u; return 0; }
r[1]=r[53];
goto P_0c064e54;
P_0c064e54: /* original 4118, guest PC 0x0c064e54 */
if(!s->budget--) { s->failed_pc=0x0c064e54u; return 0; }
r[1]<<=8;
goto P_0c064e56;
P_0c064e56: /* original 221b, guest PC 0x0c064e56 */
if(!s->budget--) { s->failed_pc=0x0c064e56u; return 0; }
r[2]|=r[1];
goto P_0c064e58;
P_0c064e58: /* original e12c, guest PC 0x0c064e58 */
if(!s->budget--) { s->failed_pc=0x0c064e58u; return 0; }
r[1]=0x0000002cu;
goto P_0c064e5a;
P_0c064e5a: /* original 314c, guest PC 0x0c064e5a */
if(!s->budget--) { s->failed_pc=0x0c064e5au; return 0; }
r[1]+=r[4];
goto P_0c064e5c;
P_0c064e5c: /* original f318, guest PC 0x0c064e5c */
if(!s->budget--) { s->failed_pc=0x0c064e5cu; return 0; }
vf3_matrix_load(s,ram,3,r[1]);
goto P_0c064e5e;
P_0c064e5e: /* original f3f2, guest PC 0x0c064e5e */
if(!s->budget--) { s->failed_pc=0x0c064e5eu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[15],r[18],'*');
goto P_0c064e60;
P_0c064e60: /* original f33d, guest PC 0x0c064e60 */
if(!s->budget--) { s->failed_pc=0x0c064e60u; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c064e62;
P_0c064e62: /* original 015a, guest PC 0x0c064e62 */
if(!s->budget--) { s->failed_pc=0x0c064e62u; return 0; }
r[1]=r[53];
goto P_0c064e64;
P_0c064e64: /* original 221b, guest PC 0x0c064e64 */
if(!s->budget--) { s->failed_pc=0x0c064e64u; return 0; }
r[2]|=r[1];
goto P_0c064e66;
P_0c064e66: /* original 0326, guest PC 0x0c064e66 */
if(!s->budget--) { s->failed_pc=0x0c064e66u; return 0; }
write(ram,r[3]+r[0],r[2],4);
goto P_0c064e68;
P_0c064e68: /* original 6cd2, guest PC 0x0c064e68 */
if(!s->budget--) { s->failed_pc=0x0c064e68u; return 0; }
tmp=read(ram,r[13],4);
r[12]=tmp;
goto P_0c064e6a;
P_0c064e6a: /* original e030, guest PC 0x0c064e6a */
if(!s->budget--) { s->failed_pc=0x0c064e6au; return 0; }
r[0]=0x00000030u;
goto P_0c064e6c;
P_0c064e6c: /* original f3c6, guest PC 0x0c064e6c */
if(!s->budget--) { s->failed_pc=0x0c064e6cu; return 0; }
vf3_matrix_load(s,ram,3,r[12]+r[0]);
goto P_0c064e6e;
P_0c064e6e: /* original e034, guest PC 0x0c064e6e */
if(!s->budget--) { s->failed_pc=0x0c064e6eu; return 0; }
r[0]=0x00000034u;
goto P_0c064e70;
P_0c064e70: /* original f3f2, guest PC 0x0c064e70 */
if(!s->budget--) { s->failed_pc=0x0c064e70u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[15],r[18],'*');
goto P_0c064e72;
P_0c064e72: /* original f33d, guest PC 0x0c064e72 */
if(!s->budget--) { s->failed_pc=0x0c064e72u; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c064e74;
P_0c064e74: /* original f3c6, guest PC 0x0c064e74 */
if(!s->budget--) { s->failed_pc=0x0c064e74u; return 0; }
vf3_matrix_load(s,ram,3,r[12]+r[0]);
goto P_0c064e76;
P_0c064e76: /* original 065a, guest PC 0x0c064e76 */
if(!s->budget--) { s->failed_pc=0x0c064e76u; return 0; }
r[6]=r[53];
goto P_0c064e78;
P_0c064e78: /* original 4628, guest PC 0x0c064e78 */
if(!s->budget--) { s->failed_pc=0x0c064e78u; return 0; }
r[6]<<=16;
goto P_0c064e7a;
P_0c064e7a: /* original 4618, guest PC 0x0c064e7a */
if(!s->budget--) { s->failed_pc=0x0c064e7au; return 0; }
r[6]<<=8;
goto P_0c064e7c;
P_0c064e7c: /* original f3f2, guest PC 0x0c064e7c */
if(!s->budget--) { s->failed_pc=0x0c064e7cu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[15],r[18],'*');
goto P_0c064e7e;
P_0c064e7e: /* original e038, guest PC 0x0c064e7e */
if(!s->budget--) { s->failed_pc=0x0c064e7eu; return 0; }
r[0]=0x00000038u;
goto P_0c064e80;
P_0c064e80: /* original f33d, guest PC 0x0c064e80 */
if(!s->budget--) { s->failed_pc=0x0c064e80u; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c064e82;
P_0c064e82: /* original 035a, guest PC 0x0c064e82 */
if(!s->budget--) { s->failed_pc=0x0c064e82u; return 0; }
r[3]=r[53];
goto P_0c064e84;
P_0c064e84: /* original f3c6, guest PC 0x0c064e84 */
if(!s->budget--) { s->failed_pc=0x0c064e84u; return 0; }
vf3_matrix_load(s,ram,3,r[12]+r[0]);
goto P_0c064e86;
P_0c064e86: /* original 4328, guest PC 0x0c064e86 */
if(!s->budget--) { s->failed_pc=0x0c064e86u; return 0; }
r[3]<<=16;
goto P_0c064e88;
P_0c064e88: /* original 263b, guest PC 0x0c064e88 */
if(!s->budget--) { s->failed_pc=0x0c064e88u; return 0; }
r[6]|=r[3];
goto P_0c064e8a;
P_0c064e8a: /* original f3f2, guest PC 0x0c064e8a */
if(!s->budget--) { s->failed_pc=0x0c064e8au; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[15],r[18],'*');
goto P_0c064e8c;
P_0c064e8c: /* original f33d, guest PC 0x0c064e8c */
if(!s->budget--) { s->failed_pc=0x0c064e8cu; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c064e8e;
P_0c064e8e: /* original e03c, guest PC 0x0c064e8e */
if(!s->budget--) { s->failed_pc=0x0c064e8eu; return 0; }
r[0]=0x0000003cu;
goto P_0c064e90;
P_0c064e90: /* original f3c6, guest PC 0x0c064e90 */
if(!s->budget--) { s->failed_pc=0x0c064e90u; return 0; }
vf3_matrix_load(s,ram,3,r[12]+r[0]);
goto P_0c064e92;
P_0c064e92: /* original 035a, guest PC 0x0c064e92 */
if(!s->budget--) { s->failed_pc=0x0c064e92u; return 0; }
r[3]=r[53];
goto P_0c064e94;
P_0c064e94: /* original 4318, guest PC 0x0c064e94 */
if(!s->budget--) { s->failed_pc=0x0c064e94u; return 0; }
r[3]<<=8;
goto P_0c064e96;
P_0c064e96: /* original 263b, guest PC 0x0c064e96 */
if(!s->budget--) { s->failed_pc=0x0c064e96u; return 0; }
r[6]|=r[3];
goto P_0c064e98;
P_0c064e98: /* original f3f2, guest PC 0x0c064e98 */
if(!s->budget--) { s->failed_pc=0x0c064e98u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[15],r[18],'*');
goto P_0c064e9a;
P_0c064e9a: /* original 6593, guest PC 0x0c064e9a */
if(!s->budget--) { s->failed_pc=0x0c064e9au; return 0; }
r[5]=r[9];
goto P_0c064e9c;
P_0c064e9c: /* original f33d, guest PC 0x0c064e9c */
if(!s->budget--) { s->failed_pc=0x0c064e9cu; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c064e9e;
P_0c064e9e: /* original 035a, guest PC 0x0c064e9e */
if(!s->budget--) { s->failed_pc=0x0c064e9eu; return 0; }
r[3]=r[53];
goto P_0c064ea0;
P_0c064ea0: /* original 263b, guest PC 0x0c064ea0 */
if(!s->budget--) { s->failed_pc=0x0c064ea0u; return 0; }
r[6]|=r[3];
goto P_0c064ea2;
P_0c064ea2: /* original bb45, guest PC 0x0c064ea2 */
if(!s->budget--) { s->failed_pc=0x0c064ea2u; return 0; }
target=code_base|0x0c064530u; r[16]=code_base|0x0c064ea6u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c064ea6u) { target=s->pc; goto dispatch; }
goto P_0c064ea6;
P_0c064ea4: /* original 64e3, guest PC 0x0c064ea4 */
if(!s->budget--) { s->failed_pc=0x0c064ea4u; return 0; }
r[4]=r[14];
goto P_0c064ea6;
P_0c064ea6: /* original 6c03, guest PC 0x0c064ea6 */
if(!s->budget--) { s->failed_pc=0x0c064ea6u; return 0; }
r[12]=r[0];
goto P_0c064ea8;
P_0c064ea8: /* original 61b2, guest PC 0x0c064ea8 */
if(!s->budget--) { s->failed_pc=0x0c064ea8u; return 0; }
tmp=read(ram,r[11],4);
r[1]=tmp;
goto P_0c064eaa;
P_0c064eaa: /* original 63c3, guest PC 0x0c064eaa */
if(!s->budget--) { s->failed_pc=0x0c064eaau; return 0; }
r[3]=r[12];
goto P_0c064eac;
P_0c064eac: /* original d06e, guest PC 0x0c064eac */
if(!s->budget--) { s->failed_pc=0x0c064eacu; return 0; }
r[0]=read(ram,0x0c065068u,4);
goto P_0c064eae;
P_0c064eae: /* original 7c01, guest PC 0x0c064eae */
if(!s->budget--) { s->failed_pc=0x0c064eaeu; return 0; }
r[12]+=0x00000001u;
goto P_0c064eb0;
P_0c064eb0: /* original 5211, guest PC 0x0c064eb0 */
if(!s->budget--) { s->failed_pc=0x0c064eb0u; return 0; }
r[2]=read(ram,r[1]+4,4);
goto P_0c064eb2;
P_0c064eb2: /* original 4308, guest PC 0x0c064eb2 */
if(!s->budget--) { s->failed_pc=0x0c064eb2u; return 0; }
r[3]<<=2;
goto P_0c064eb4;
P_0c064eb4: /* original 0326, guest PC 0x0c064eb4 */
if(!s->budget--) { s->failed_pc=0x0c064eb4u; return 0; }
write(ram,r[3]+r[0],r[2],4);
goto P_0c064eb6;
P_0c064eb6: /* original 63c3, guest PC 0x0c064eb6 */
if(!s->budget--) { s->failed_pc=0x0c064eb6u; return 0; }
r[3]=r[12];
goto P_0c064eb8;
P_0c064eb8: /* original 61b2, guest PC 0x0c064eb8 */
if(!s->budget--) { s->failed_pc=0x0c064eb8u; return 0; }
tmp=read(ram,r[11],4);
r[1]=tmp;
goto P_0c064eba;
P_0c064eba: /* original 7c01, guest PC 0x0c064eba */
if(!s->budget--) { s->failed_pc=0x0c064ebau; return 0; }
r[12]+=0x00000001u;
goto P_0c064ebc;
P_0c064ebc: /* original 5212, guest PC 0x0c064ebc */
if(!s->budget--) { s->failed_pc=0x0c064ebcu; return 0; }
r[2]=read(ram,r[1]+8,4);
goto P_0c064ebe;
P_0c064ebe: /* original 4308, guest PC 0x0c064ebe */
if(!s->budget--) { s->failed_pc=0x0c064ebeu; return 0; }
r[3]<<=2;
goto P_0c064ec0;
P_0c064ec0: /* original 0326, guest PC 0x0c064ec0 */
if(!s->budget--) { s->failed_pc=0x0c064ec0u; return 0; }
write(ram,r[3]+r[0],r[2],4);
goto P_0c064ec2;
P_0c064ec2: /* original 63c3, guest PC 0x0c064ec2 */
if(!s->budget--) { s->failed_pc=0x0c064ec2u; return 0; }
r[3]=r[12];
goto P_0c064ec4;
P_0c064ec4: /* original 61b2, guest PC 0x0c064ec4 */
if(!s->budget--) { s->failed_pc=0x0c064ec4u; return 0; }
tmp=read(ram,r[11],4);
r[1]=tmp;
goto P_0c064ec6;
P_0c064ec6: /* original 7c01, guest PC 0x0c064ec6 */
if(!s->budget--) { s->failed_pc=0x0c064ec6u; return 0; }
r[12]+=0x00000001u;
goto P_0c064ec8;
P_0c064ec8: /* original 5213, guest PC 0x0c064ec8 */
if(!s->budget--) { s->failed_pc=0x0c064ec8u; return 0; }
r[2]=read(ram,r[1]+12,4);
goto P_0c064eca;
P_0c064eca: /* original 4308, guest PC 0x0c064eca */
if(!s->budget--) { s->failed_pc=0x0c064ecau; return 0; }
r[3]<<=2;
goto P_0c064ecc;
P_0c064ecc: /* original 0326, guest PC 0x0c064ecc */
if(!s->budget--) { s->failed_pc=0x0c064eccu; return 0; }
write(ram,r[3]+r[0],r[2],4);
goto P_0c064ece;
P_0c064ece: /* original 65c3, guest PC 0x0c064ece */
if(!s->budget--) { s->failed_pc=0x0c064eceu; return 0; }
r[5]=r[12];
goto P_0c064ed0;
P_0c064ed0: /* original 67b2, guest PC 0x0c064ed0 */
if(!s->budget--) { s->failed_pc=0x0c064ed0u; return 0; }
tmp=read(ram,r[11],4);
r[7]=tmp;
goto P_0c064ed2;
P_0c064ed2: /* original 2f72, guest PC 0x0c064ed2 */
if(!s->budget--) { s->failed_pc=0x0c064ed2u; return 0; }
write(ram,r[15],r[7],4);
goto P_0c064ed4;
P_0c064ed4: /* original 5775, guest PC 0x0c064ed4 */
if(!s->budget--) { s->failed_pc=0x0c064ed4u; return 0; }
r[7]=read(ram,r[7]+20,4);
goto P_0c064ed6;
P_0c064ed6: /* original 66f2, guest PC 0x0c064ed6 */
if(!s->budget--) { s->failed_pc=0x0c064ed6u; return 0; }
tmp=read(ram,r[15],4);
r[6]=tmp;
goto P_0c064ed8;
P_0c064ed8: /* original 5664, guest PC 0x0c064ed8 */
if(!s->budget--) { s->failed_pc=0x0c064ed8u; return 0; }
r[6]=read(ram,r[6]+16,4);
goto P_0c064eda;
P_0c064eda: /* original bb4d, guest PC 0x0c064eda */
if(!s->budget--) { s->failed_pc=0x0c064edau; return 0; }
target=code_base|0x0c064578u; r[16]=code_base|0x0c064edeu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c064edeu) { target=s->pc; goto dispatch; }
goto P_0c064ede;
P_0c064edc: /* original 64e3, guest PC 0x0c064edc */
if(!s->budget--) { s->failed_pc=0x0c064edcu; return 0; }
r[4]=r[14];
goto P_0c064ede;
P_0c064ede: /* original 6903, guest PC 0x0c064ede */
if(!s->budget--) { s->failed_pc=0x0c064edeu; return 0; }
r[9]=r[0];
goto P_0c064ee0;
P_0c064ee0: /* original 64b2, guest PC 0x0c064ee0 */
if(!s->budget--) { s->failed_pc=0x0c064ee0u; return 0; }
tmp=read(ram,r[11],4);
r[4]=tmp;
goto P_0c064ee2;
P_0c064ee2: /* original e120, guest PC 0x0c064ee2 */
if(!s->budget--) { s->failed_pc=0x0c064ee2u; return 0; }
r[1]=0x00000020u;
goto P_0c064ee4;
P_0c064ee4: /* original d060, guest PC 0x0c064ee4 */
if(!s->budget--) { s->failed_pc=0x0c064ee4u; return 0; }
r[0]=read(ram,0x0c065068u,4);
goto P_0c064ee6;
P_0c064ee6: /* original 6293, guest PC 0x0c064ee6 */
if(!s->budget--) { s->failed_pc=0x0c064ee6u; return 0; }
r[2]=r[9];
goto P_0c064ee8;
P_0c064ee8: /* original 7901, guest PC 0x0c064ee8 */
if(!s->budget--) { s->failed_pc=0x0c064ee8u; return 0; }
r[9]+=0x00000001u;
goto P_0c064eea;
P_0c064eea: /* original 4208, guest PC 0x0c064eea */
if(!s->budget--) { s->failed_pc=0x0c064eeau; return 0; }
r[2]<<=2;
goto P_0c064eec;
P_0c064eec: /* original 314c, guest PC 0x0c064eec */
if(!s->budget--) { s->failed_pc=0x0c064eecu; return 0; }
r[1]+=r[4];
goto P_0c064eee;
P_0c064eee: /* original f318, guest PC 0x0c064eee */
if(!s->budget--) { s->failed_pc=0x0c064eeeu; return 0; }
vf3_matrix_load(s,ram,3,r[1]);
goto P_0c064ef0;
P_0c064ef0: /* original f3f2, guest PC 0x0c064ef0 */
if(!s->budget--) { s->failed_pc=0x0c064ef0u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[15],r[18],'*');
goto P_0c064ef2;
P_0c064ef2: /* original e124, guest PC 0x0c064ef2 */
if(!s->budget--) { s->failed_pc=0x0c064ef2u; return 0; }
r[1]=0x00000024u;
goto P_0c064ef4;
P_0c064ef4: /* original f33d, guest PC 0x0c064ef4 */
if(!s->budget--) { s->failed_pc=0x0c064ef4u; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c064ef6;
P_0c064ef6: /* original 314c, guest PC 0x0c064ef6 */
if(!s->budget--) { s->failed_pc=0x0c064ef6u; return 0; }
r[1]+=r[4];
goto P_0c064ef8;
P_0c064ef8: /* original f318, guest PC 0x0c064ef8 */
if(!s->budget--) { s->failed_pc=0x0c064ef8u; return 0; }
vf3_matrix_load(s,ram,3,r[1]);
goto P_0c064efa;
P_0c064efa: /* original 035a, guest PC 0x0c064efa */
if(!s->budget--) { s->failed_pc=0x0c064efau; return 0; }
r[3]=r[53];
goto P_0c064efc;
P_0c064efc: /* original 4328, guest PC 0x0c064efc */
if(!s->budget--) { s->failed_pc=0x0c064efcu; return 0; }
r[3]<<=16;
goto P_0c064efe;
P_0c064efe: /* original 4318, guest PC 0x0c064efe */
if(!s->budget--) { s->failed_pc=0x0c064efeu; return 0; }
r[3]<<=8;
goto P_0c064f00;
P_0c064f00: /* original f3f2, guest PC 0x0c064f00 */
if(!s->budget--) { s->failed_pc=0x0c064f00u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[15],r[18],'*');
goto P_0c064f02;
P_0c064f02: /* original f33d, guest PC 0x0c064f02 */
if(!s->budget--) { s->failed_pc=0x0c064f02u; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c064f04;
P_0c064f04: /* original 015a, guest PC 0x0c064f04 */
if(!s->budget--) { s->failed_pc=0x0c064f04u; return 0; }
r[1]=r[53];
goto P_0c064f06;
P_0c064f06: /* original 4128, guest PC 0x0c064f06 */
if(!s->budget--) { s->failed_pc=0x0c064f06u; return 0; }
r[1]<<=16;
goto P_0c064f08;
P_0c064f08: /* original 231b, guest PC 0x0c064f08 */
if(!s->budget--) { s->failed_pc=0x0c064f08u; return 0; }
r[3]|=r[1];
goto P_0c064f0a;
P_0c064f0a: /* original e128, guest PC 0x0c064f0a */
if(!s->budget--) { s->failed_pc=0x0c064f0au; return 0; }
r[1]=0x00000028u;
goto P_0c064f0c;
P_0c064f0c: /* original 314c, guest PC 0x0c064f0c */
if(!s->budget--) { s->failed_pc=0x0c064f0cu; return 0; }
r[1]+=r[4];
goto P_0c064f0e;
P_0c064f0e: /* original f318, guest PC 0x0c064f0e */
if(!s->budget--) { s->failed_pc=0x0c064f0eu; return 0; }
vf3_matrix_load(s,ram,3,r[1]);
goto P_0c064f10;
P_0c064f10: /* original f3f2, guest PC 0x0c064f10 */
if(!s->budget--) { s->failed_pc=0x0c064f10u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[15],r[18],'*');
goto P_0c064f12;
P_0c064f12: /* original f33d, guest PC 0x0c064f12 */
if(!s->budget--) { s->failed_pc=0x0c064f12u; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c064f14;
P_0c064f14: /* original 015a, guest PC 0x0c064f14 */
if(!s->budget--) { s->failed_pc=0x0c064f14u; return 0; }
r[1]=r[53];
goto P_0c064f16;
P_0c064f16: /* original 4118, guest PC 0x0c064f16 */
if(!s->budget--) { s->failed_pc=0x0c064f16u; return 0; }
r[1]<<=8;
goto P_0c064f18;
P_0c064f18: /* original 231b, guest PC 0x0c064f18 */
if(!s->budget--) { s->failed_pc=0x0c064f18u; return 0; }
r[3]|=r[1];
goto P_0c064f1a;
P_0c064f1a: /* original e12c, guest PC 0x0c064f1a */
if(!s->budget--) { s->failed_pc=0x0c064f1au; return 0; }
r[1]=0x0000002cu;
goto P_0c064f1c;
P_0c064f1c: /* original 314c, guest PC 0x0c064f1c */
if(!s->budget--) { s->failed_pc=0x0c064f1cu; return 0; }
r[1]+=r[4];
goto P_0c064f1e;
P_0c064f1e: /* original f318, guest PC 0x0c064f1e */
if(!s->budget--) { s->failed_pc=0x0c064f1eu; return 0; }
vf3_matrix_load(s,ram,3,r[1]);
goto P_0c064f20;
P_0c064f20: /* original f3f2, guest PC 0x0c064f20 */
if(!s->budget--) { s->failed_pc=0x0c064f20u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[15],r[18],'*');
goto P_0c064f22;
P_0c064f22: /* original f33d, guest PC 0x0c064f22 */
if(!s->budget--) { s->failed_pc=0x0c064f22u; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c064f24;
P_0c064f24: /* original 015a, guest PC 0x0c064f24 */
if(!s->budget--) { s->failed_pc=0x0c064f24u; return 0; }
r[1]=r[53];
goto P_0c064f26;
P_0c064f26: /* original 231b, guest PC 0x0c064f26 */
if(!s->budget--) { s->failed_pc=0x0c064f26u; return 0; }
r[3]|=r[1];
goto P_0c064f28;
P_0c064f28: /* original 0236, guest PC 0x0c064f28 */
if(!s->budget--) { s->failed_pc=0x0c064f28u; return 0; }
write(ram,r[2]+r[0],r[3],4);
goto P_0c064f2a;
P_0c064f2a: /* original e030, guest PC 0x0c064f2a */
if(!s->budget--) { s->failed_pc=0x0c064f2au; return 0; }
r[0]=0x00000030u;
goto P_0c064f2c;
P_0c064f2c: /* original 6cb2, guest PC 0x0c064f2c */
if(!s->budget--) { s->failed_pc=0x0c064f2cu; return 0; }
tmp=read(ram,r[11],4);
r[12]=tmp;
goto P_0c064f2e;
P_0c064f2e: /* original f3c6, guest PC 0x0c064f2e */
if(!s->budget--) { s->failed_pc=0x0c064f2eu; return 0; }
vf3_matrix_load(s,ram,3,r[12]+r[0]);
goto P_0c064f30;
P_0c064f30: /* original f3f2, guest PC 0x0c064f30 */
if(!s->budget--) { s->failed_pc=0x0c064f30u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[15],r[18],'*');
goto P_0c064f32;
P_0c064f32: /* original e034, guest PC 0x0c064f32 */
if(!s->budget--) { s->failed_pc=0x0c064f32u; return 0; }
r[0]=0x00000034u;
goto P_0c064f34;
P_0c064f34: /* original f33d, guest PC 0x0c064f34 */
if(!s->budget--) { s->failed_pc=0x0c064f34u; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c064f36;
P_0c064f36: /* original 065a, guest PC 0x0c064f36 */
if(!s->budget--) { s->failed_pc=0x0c064f36u; return 0; }
r[6]=r[53];
goto P_0c064f38;
P_0c064f38: /* original f3c6, guest PC 0x0c064f38 */
if(!s->budget--) { s->failed_pc=0x0c064f38u; return 0; }
vf3_matrix_load(s,ram,3,r[12]+r[0]);
goto P_0c064f3a;
P_0c064f3a: /* original 4628, guest PC 0x0c064f3a */
if(!s->budget--) { s->failed_pc=0x0c064f3au; return 0; }
r[6]<<=16;
goto P_0c064f3c;
P_0c064f3c: /* original 4618, guest PC 0x0c064f3c */
if(!s->budget--) { s->failed_pc=0x0c064f3cu; return 0; }
r[6]<<=8;
goto P_0c064f3e;
P_0c064f3e: /* original f3f2, guest PC 0x0c064f3e */
if(!s->budget--) { s->failed_pc=0x0c064f3eu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[15],r[18],'*');
goto P_0c064f40;
P_0c064f40: /* original f33d, guest PC 0x0c064f40 */
if(!s->budget--) { s->failed_pc=0x0c064f40u; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c064f42;
P_0c064f42: /* original e038, guest PC 0x0c064f42 */
if(!s->budget--) { s->failed_pc=0x0c064f42u; return 0; }
r[0]=0x00000038u;
goto P_0c064f44;
P_0c064f44: /* original f3c6, guest PC 0x0c064f44 */
if(!s->budget--) { s->failed_pc=0x0c064f44u; return 0; }
vf3_matrix_load(s,ram,3,r[12]+r[0]);
goto P_0c064f46;
P_0c064f46: /* original 035a, guest PC 0x0c064f46 */
if(!s->budget--) { s->failed_pc=0x0c064f46u; return 0; }
r[3]=r[53];
goto P_0c064f48;
P_0c064f48: /* original 4328, guest PC 0x0c064f48 */
if(!s->budget--) { s->failed_pc=0x0c064f48u; return 0; }
r[3]<<=16;
goto P_0c064f4a;
P_0c064f4a: /* original 263b, guest PC 0x0c064f4a */
if(!s->budget--) { s->failed_pc=0x0c064f4au; return 0; }
r[6]|=r[3];
goto P_0c064f4c;
P_0c064f4c: /* original f3f2, guest PC 0x0c064f4c */
if(!s->budget--) { s->failed_pc=0x0c064f4cu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[15],r[18],'*');
goto P_0c064f4e;
P_0c064f4e: /* original e03c, guest PC 0x0c064f4e */
if(!s->budget--) { s->failed_pc=0x0c064f4eu; return 0; }
r[0]=0x0000003cu;
goto P_0c064f50;
P_0c064f50: /* original f33d, guest PC 0x0c064f50 */
if(!s->budget--) { s->failed_pc=0x0c064f50u; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c064f52;
P_0c064f52: /* original 035a, guest PC 0x0c064f52 */
if(!s->budget--) { s->failed_pc=0x0c064f52u; return 0; }
r[3]=r[53];
goto P_0c064f54;
P_0c064f54: /* original f3c6, guest PC 0x0c064f54 */
if(!s->budget--) { s->failed_pc=0x0c064f54u; return 0; }
vf3_matrix_load(s,ram,3,r[12]+r[0]);
goto P_0c064f56;
P_0c064f56: /* original 4318, guest PC 0x0c064f56 */
if(!s->budget--) { s->failed_pc=0x0c064f56u; return 0; }
r[3]<<=8;
goto P_0c064f58;
P_0c064f58: /* original 263b, guest PC 0x0c064f58 */
if(!s->budget--) { s->failed_pc=0x0c064f58u; return 0; }
r[6]|=r[3];
goto P_0c064f5a;
P_0c064f5a: /* original f3f2, guest PC 0x0c064f5a */
if(!s->budget--) { s->failed_pc=0x0c064f5au; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[15],r[18],'*');
goto P_0c064f5c;
P_0c064f5c: /* original f33d, guest PC 0x0c064f5c */
if(!s->budget--) { s->failed_pc=0x0c064f5cu; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c064f5e;
P_0c064f5e: /* original 035a, guest PC 0x0c064f5e */
if(!s->budget--) { s->failed_pc=0x0c064f5eu; return 0; }
r[3]=r[53];
goto P_0c064f60;
P_0c064f60: /* original 263b, guest PC 0x0c064f60 */
if(!s->budget--) { s->failed_pc=0x0c064f60u; return 0; }
r[6]|=r[3];
goto P_0c064f62;
P_0c064f62: /* original 6593, guest PC 0x0c064f62 */
if(!s->budget--) { s->failed_pc=0x0c064f62u; return 0; }
r[5]=r[9];
goto P_0c064f64;
P_0c064f64: /* original bae4, guest PC 0x0c064f64 */
if(!s->budget--) { s->failed_pc=0x0c064f64u; return 0; }
target=code_base|0x0c064530u; r[16]=code_base|0x0c064f68u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c064f68u) { target=s->pc; goto dispatch; }
goto P_0c064f68;
P_0c064f66: /* original 64e3, guest PC 0x0c064f66 */
if(!s->budget--) { s->failed_pc=0x0c064f66u; return 0; }
r[4]=r[14];
goto P_0c064f68;
P_0c064f68: /* original 61a2, guest PC 0x0c064f68 */
if(!s->budget--) { s->failed_pc=0x0c064f68u; return 0; }
tmp=read(ram,r[10],4);
r[1]=tmp;
goto P_0c064f6a;
P_0c064f6a: /* original 6c03, guest PC 0x0c064f6a */
if(!s->budget--) { s->failed_pc=0x0c064f6au; return 0; }
r[12]=r[0];
goto P_0c064f6c;
P_0c064f6c: /* original 5211, guest PC 0x0c064f6c */
if(!s->budget--) { s->failed_pc=0x0c064f6cu; return 0; }
r[2]=read(ram,r[1]+4,4);
goto P_0c064f6e;
P_0c064f6e: /* original 63c3, guest PC 0x0c064f6e */
if(!s->budget--) { s->failed_pc=0x0c064f6eu; return 0; }
r[3]=r[12];
goto P_0c064f70;
P_0c064f70: /* original d03d, guest PC 0x0c064f70 */
if(!s->budget--) { s->failed_pc=0x0c064f70u; return 0; }
r[0]=read(ram,0x0c065068u,4);
goto P_0c064f72;
P_0c064f72: /* original 7c01, guest PC 0x0c064f72 */
if(!s->budget--) { s->failed_pc=0x0c064f72u; return 0; }
r[12]+=0x00000001u;
goto P_0c064f74;
P_0c064f74: /* original 4308, guest PC 0x0c064f74 */
if(!s->budget--) { s->failed_pc=0x0c064f74u; return 0; }
r[3]<<=2;
goto P_0c064f76;
P_0c064f76: /* original 0326, guest PC 0x0c064f76 */
if(!s->budget--) { s->failed_pc=0x0c064f76u; return 0; }
write(ram,r[3]+r[0],r[2],4);
goto P_0c064f78;
P_0c064f78: /* original 61a2, guest PC 0x0c064f78 */
if(!s->budget--) { s->failed_pc=0x0c064f78u; return 0; }
tmp=read(ram,r[10],4);
r[1]=tmp;
goto P_0c064f7a;
P_0c064f7a: /* original 63c3, guest PC 0x0c064f7a */
if(!s->budget--) { s->failed_pc=0x0c064f7au; return 0; }
r[3]=r[12];
goto P_0c064f7c;
P_0c064f7c: /* original 5212, guest PC 0x0c064f7c */
if(!s->budget--) { s->failed_pc=0x0c064f7cu; return 0; }
r[2]=read(ram,r[1]+8,4);
goto P_0c064f7e;
P_0c064f7e: /* original 7c01, guest PC 0x0c064f7e */
if(!s->budget--) { s->failed_pc=0x0c064f7eu; return 0; }
r[12]+=0x00000001u;
goto P_0c064f80;
P_0c064f80: /* original 4308, guest PC 0x0c064f80 */
if(!s->budget--) { s->failed_pc=0x0c064f80u; return 0; }
r[3]<<=2;
goto P_0c064f82;
P_0c064f82: /* original 0326, guest PC 0x0c064f82 */
if(!s->budget--) { s->failed_pc=0x0c064f82u; return 0; }
write(ram,r[3]+r[0],r[2],4);
goto P_0c064f84;
P_0c064f84: /* original 61a2, guest PC 0x0c064f84 */
if(!s->budget--) { s->failed_pc=0x0c064f84u; return 0; }
tmp=read(ram,r[10],4);
r[1]=tmp;
goto P_0c064f86;
P_0c064f86: /* original 63c3, guest PC 0x0c064f86 */
if(!s->budget--) { s->failed_pc=0x0c064f86u; return 0; }
r[3]=r[12];
goto P_0c064f88;
P_0c064f88: /* original 5213, guest PC 0x0c064f88 */
if(!s->budget--) { s->failed_pc=0x0c064f88u; return 0; }
r[2]=read(ram,r[1]+12,4);
goto P_0c064f8a;
P_0c064f8a: /* original 7c01, guest PC 0x0c064f8a */
if(!s->budget--) { s->failed_pc=0x0c064f8au; return 0; }
r[12]+=0x00000001u;
goto P_0c064f8c;
P_0c064f8c: /* original 4308, guest PC 0x0c064f8c */
if(!s->budget--) { s->failed_pc=0x0c064f8cu; return 0; }
r[3]<<=2;
goto P_0c064f8e;
P_0c064f8e: /* original 0326, guest PC 0x0c064f8e */
if(!s->budget--) { s->failed_pc=0x0c064f8eu; return 0; }
write(ram,r[3]+r[0],r[2],4);
goto P_0c064f90;
P_0c064f90: /* original 67a2, guest PC 0x0c064f90 */
if(!s->budget--) { s->failed_pc=0x0c064f90u; return 0; }
tmp=read(ram,r[10],4);
r[7]=tmp;
goto P_0c064f92;
P_0c064f92: /* original 65c3, guest PC 0x0c064f92 */
if(!s->budget--) { s->failed_pc=0x0c064f92u; return 0; }
r[5]=r[12];
goto P_0c064f94;
P_0c064f94: /* original 2f72, guest PC 0x0c064f94 */
if(!s->budget--) { s->failed_pc=0x0c064f94u; return 0; }
write(ram,r[15],r[7],4);
goto P_0c064f96;
P_0c064f96: /* original 5775, guest PC 0x0c064f96 */
if(!s->budget--) { s->failed_pc=0x0c064f96u; return 0; }
r[7]=read(ram,r[7]+20,4);
goto P_0c064f98;
P_0c064f98: /* original 66f2, guest PC 0x0c064f98 */
if(!s->budget--) { s->failed_pc=0x0c064f98u; return 0; }
tmp=read(ram,r[15],4);
r[6]=tmp;
goto P_0c064f9a;
P_0c064f9a: /* original 5664, guest PC 0x0c064f9a */
if(!s->budget--) { s->failed_pc=0x0c064f9au; return 0; }
r[6]=read(ram,r[6]+16,4);
goto P_0c064f9c;
P_0c064f9c: /* original baec, guest PC 0x0c064f9c */
if(!s->budget--) { s->failed_pc=0x0c064f9cu; return 0; }
target=code_base|0x0c064578u; r[16]=code_base|0x0c064fa0u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c064fa0u) { target=s->pc; goto dispatch; }
goto P_0c064fa0;
P_0c064f9e: /* original 64e3, guest PC 0x0c064f9e */
if(!s->budget--) { s->failed_pc=0x0c064f9eu; return 0; }
r[4]=r[14];
goto P_0c064fa0;
P_0c064fa0: /* original 64a2, guest PC 0x0c064fa0 */
if(!s->budget--) { s->failed_pc=0x0c064fa0u; return 0; }
tmp=read(ram,r[10],4);
r[4]=tmp;
goto P_0c064fa2;
P_0c064fa2: /* original e120, guest PC 0x0c064fa2 */
if(!s->budget--) { s->failed_pc=0x0c064fa2u; return 0; }
r[1]=0x00000020u;
goto P_0c064fa4;
P_0c064fa4: /* original 6c03, guest PC 0x0c064fa4 */
if(!s->budget--) { s->failed_pc=0x0c064fa4u; return 0; }
r[12]=r[0];
goto P_0c064fa6;
P_0c064fa6: /* original 62c3, guest PC 0x0c064fa6 */
if(!s->budget--) { s->failed_pc=0x0c064fa6u; return 0; }
r[2]=r[12];
goto P_0c064fa8;
P_0c064fa8: /* original d02f, guest PC 0x0c064fa8 */
if(!s->budget--) { s->failed_pc=0x0c064fa8u; return 0; }
r[0]=read(ram,0x0c065068u,4);
goto P_0c064faa;
P_0c064faa: /* original 314c, guest PC 0x0c064faa */
if(!s->budget--) { s->failed_pc=0x0c064faau; return 0; }
r[1]+=r[4];
goto P_0c064fac;
P_0c064fac: /* original f318, guest PC 0x0c064fac */
if(!s->budget--) { s->failed_pc=0x0c064facu; return 0; }
vf3_matrix_load(s,ram,3,r[1]);
goto P_0c064fae;
P_0c064fae: /* original 7c01, guest PC 0x0c064fae */
if(!s->budget--) { s->failed_pc=0x0c064faeu; return 0; }
r[12]+=0x00000001u;
goto P_0c064fb0;
P_0c064fb0: /* original 4208, guest PC 0x0c064fb0 */
if(!s->budget--) { s->failed_pc=0x0c064fb0u; return 0; }
r[2]<<=2;
goto P_0c064fb2;
P_0c064fb2: /* original f3f2, guest PC 0x0c064fb2 */
if(!s->budget--) { s->failed_pc=0x0c064fb2u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[15],r[18],'*');
goto P_0c064fb4;
P_0c064fb4: /* original f33d, guest PC 0x0c064fb4 */
if(!s->budget--) { s->failed_pc=0x0c064fb4u; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c064fb6;
P_0c064fb6: /* original e124, guest PC 0x0c064fb6 */
if(!s->budget--) { s->failed_pc=0x0c064fb6u; return 0; }
r[1]=0x00000024u;
goto P_0c064fb8;
P_0c064fb8: /* original 035a, guest PC 0x0c064fb8 */
if(!s->budget--) { s->failed_pc=0x0c064fb8u; return 0; }
r[3]=r[53];
goto P_0c064fba;
P_0c064fba: /* original 4328, guest PC 0x0c064fba */
if(!s->budget--) { s->failed_pc=0x0c064fbau; return 0; }
r[3]<<=16;
goto P_0c064fbc;
P_0c064fbc: /* original 4318, guest PC 0x0c064fbc */
if(!s->budget--) { s->failed_pc=0x0c064fbcu; return 0; }
r[3]<<=8;
goto P_0c064fbe;
P_0c064fbe: /* original 314c, guest PC 0x0c064fbe */
if(!s->budget--) { s->failed_pc=0x0c064fbeu; return 0; }
r[1]+=r[4];
goto P_0c064fc0;
P_0c064fc0: /* original f318, guest PC 0x0c064fc0 */
if(!s->budget--) { s->failed_pc=0x0c064fc0u; return 0; }
vf3_matrix_load(s,ram,3,r[1]);
goto P_0c064fc2;
P_0c064fc2: /* original f3f2, guest PC 0x0c064fc2 */
if(!s->budget--) { s->failed_pc=0x0c064fc2u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[15],r[18],'*');
goto P_0c064fc4;
P_0c064fc4: /* original f33d, guest PC 0x0c064fc4 */
if(!s->budget--) { s->failed_pc=0x0c064fc4u; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c064fc6;
P_0c064fc6: /* original 015a, guest PC 0x0c064fc6 */
if(!s->budget--) { s->failed_pc=0x0c064fc6u; return 0; }
r[1]=r[53];
goto P_0c064fc8;
P_0c064fc8: /* original 4128, guest PC 0x0c064fc8 */
if(!s->budget--) { s->failed_pc=0x0c064fc8u; return 0; }
r[1]<<=16;
goto P_0c064fca;
P_0c064fca: /* original 231b, guest PC 0x0c064fca */
if(!s->budget--) { s->failed_pc=0x0c064fcau; return 0; }
r[3]|=r[1];
goto P_0c064fcc;
P_0c064fcc: /* original e128, guest PC 0x0c064fcc */
if(!s->budget--) { s->failed_pc=0x0c064fccu; return 0; }
r[1]=0x00000028u;
goto P_0c064fce;
P_0c064fce: /* original 314c, guest PC 0x0c064fce */
if(!s->budget--) { s->failed_pc=0x0c064fceu; return 0; }
r[1]+=r[4];
goto P_0c064fd0;
P_0c064fd0: /* original f318, guest PC 0x0c064fd0 */
if(!s->budget--) { s->failed_pc=0x0c064fd0u; return 0; }
vf3_matrix_load(s,ram,3,r[1]);
goto P_0c064fd2;
P_0c064fd2: /* original f3f2, guest PC 0x0c064fd2 */
if(!s->budget--) { s->failed_pc=0x0c064fd2u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[15],r[18],'*');
goto P_0c064fd4;
P_0c064fd4: /* original f33d, guest PC 0x0c064fd4 */
if(!s->budget--) { s->failed_pc=0x0c064fd4u; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c064fd6;
P_0c064fd6: /* original 015a, guest PC 0x0c064fd6 */
if(!s->budget--) { s->failed_pc=0x0c064fd6u; return 0; }
r[1]=r[53];
goto P_0c064fd8;
P_0c064fd8: /* original 4118, guest PC 0x0c064fd8 */
if(!s->budget--) { s->failed_pc=0x0c064fd8u; return 0; }
r[1]<<=8;
goto P_0c064fda;
P_0c064fda: /* original 231b, guest PC 0x0c064fda */
if(!s->budget--) { s->failed_pc=0x0c064fdau; return 0; }
r[3]|=r[1];
goto P_0c064fdc;
P_0c064fdc: /* original e12c, guest PC 0x0c064fdc */
if(!s->budget--) { s->failed_pc=0x0c064fdcu; return 0; }
r[1]=0x0000002cu;
goto P_0c064fde;
P_0c064fde: /* original 314c, guest PC 0x0c064fde */
if(!s->budget--) { s->failed_pc=0x0c064fdeu; return 0; }
r[1]+=r[4];
goto P_0c064fe0;
P_0c064fe0: /* original f318, guest PC 0x0c064fe0 */
if(!s->budget--) { s->failed_pc=0x0c064fe0u; return 0; }
vf3_matrix_load(s,ram,3,r[1]);
goto P_0c064fe2;
P_0c064fe2: /* original f3f2, guest PC 0x0c064fe2 */
if(!s->budget--) { s->failed_pc=0x0c064fe2u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[15],r[18],'*');
goto P_0c064fe4;
P_0c064fe4: /* original f33d, guest PC 0x0c064fe4 */
if(!s->budget--) { s->failed_pc=0x0c064fe4u; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c064fe6;
P_0c064fe6: /* original 015a, guest PC 0x0c064fe6 */
if(!s->budget--) { s->failed_pc=0x0c064fe6u; return 0; }
r[1]=r[53];
goto P_0c064fe8;
P_0c064fe8: /* original 231b, guest PC 0x0c064fe8 */
if(!s->budget--) { s->failed_pc=0x0c064fe8u; return 0; }
r[3]|=r[1];
goto P_0c064fea;
P_0c064fea: /* original 0236, guest PC 0x0c064fea */
if(!s->budget--) { s->failed_pc=0x0c064feau; return 0; }
write(ram,r[2]+r[0],r[3],4);
goto P_0c064fec;
P_0c064fec: /* original 6ba2, guest PC 0x0c064fec */
if(!s->budget--) { s->failed_pc=0x0c064fecu; return 0; }
tmp=read(ram,r[10],4);
r[11]=tmp;
goto P_0c064fee;
P_0c064fee: /* original e030, guest PC 0x0c064fee */
if(!s->budget--) { s->failed_pc=0x0c064feeu; return 0; }
r[0]=0x00000030u;
goto P_0c064ff0;
P_0c064ff0: /* original f3b6, guest PC 0x0c064ff0 */
if(!s->budget--) { s->failed_pc=0x0c064ff0u; return 0; }
vf3_matrix_load(s,ram,3,r[11]+r[0]);
goto P_0c064ff2;
P_0c064ff2: /* original e034, guest PC 0x0c064ff2 */
if(!s->budget--) { s->failed_pc=0x0c064ff2u; return 0; }
r[0]=0x00000034u;
goto P_0c064ff4;
P_0c064ff4: /* original f3f2, guest PC 0x0c064ff4 */
if(!s->budget--) { s->failed_pc=0x0c064ff4u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[15],r[18],'*');
goto P_0c064ff6;
P_0c064ff6: /* original f33d, guest PC 0x0c064ff6 */
if(!s->budget--) { s->failed_pc=0x0c064ff6u; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c064ff8;
P_0c064ff8: /* original f3b6, guest PC 0x0c064ff8 */
if(!s->budget--) { s->failed_pc=0x0c064ff8u; return 0; }
vf3_matrix_load(s,ram,3,r[11]+r[0]);
goto P_0c064ffa;
P_0c064ffa: /* original 065a, guest PC 0x0c064ffa */
if(!s->budget--) { s->failed_pc=0x0c064ffau; return 0; }
r[6]=r[53];
goto P_0c064ffc;
P_0c064ffc: /* original 4628, guest PC 0x0c064ffc */
if(!s->budget--) { s->failed_pc=0x0c064ffcu; return 0; }
r[6]<<=16;
goto P_0c064ffe;
P_0c064ffe: /* original 4618, guest PC 0x0c064ffe */
if(!s->budget--) { s->failed_pc=0x0c064ffeu; return 0; }
r[6]<<=8;
goto P_0c065000;
P_0c065000: /* original f3f2, guest PC 0x0c065000 */
if(!s->budget--) { s->failed_pc=0x0c065000u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[15],r[18],'*');
goto P_0c065002;
P_0c065002: /* original e038, guest PC 0x0c065002 */
if(!s->budget--) { s->failed_pc=0x0c065002u; return 0; }
r[0]=0x00000038u;
goto P_0c065004;
P_0c065004: /* original f33d, guest PC 0x0c065004 */
if(!s->budget--) { s->failed_pc=0x0c065004u; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c065006;
P_0c065006: /* original 035a, guest PC 0x0c065006 */
if(!s->budget--) { s->failed_pc=0x0c065006u; return 0; }
r[3]=r[53];
goto P_0c065008;
P_0c065008: /* original f3b6, guest PC 0x0c065008 */
if(!s->budget--) { s->failed_pc=0x0c065008u; return 0; }
vf3_matrix_load(s,ram,3,r[11]+r[0]);
goto P_0c06500a;
P_0c06500a: /* original 4328, guest PC 0x0c06500a */
if(!s->budget--) { s->failed_pc=0x0c06500au; return 0; }
r[3]<<=16;
goto P_0c06500c;
P_0c06500c: /* original 263b, guest PC 0x0c06500c */
if(!s->budget--) { s->failed_pc=0x0c06500cu; return 0; }
r[6]|=r[3];
goto P_0c06500e;
P_0c06500e: /* original f3f2, guest PC 0x0c06500e */
if(!s->budget--) { s->failed_pc=0x0c06500eu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[15],r[18],'*');
goto P_0c065010;
P_0c065010: /* original f33d, guest PC 0x0c065010 */
if(!s->budget--) { s->failed_pc=0x0c065010u; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c065012;
P_0c065012: /* original e03c, guest PC 0x0c065012 */
if(!s->budget--) { s->failed_pc=0x0c065012u; return 0; }
r[0]=0x0000003cu;
goto P_0c065014;
P_0c065014: /* original f3b6, guest PC 0x0c065014 */
if(!s->budget--) { s->failed_pc=0x0c065014u; return 0; }
vf3_matrix_load(s,ram,3,r[11]+r[0]);
goto P_0c065016;
P_0c065016: /* original 035a, guest PC 0x0c065016 */
if(!s->budget--) { s->failed_pc=0x0c065016u; return 0; }
r[3]=r[53];
goto P_0c065018;
P_0c065018: /* original 4318, guest PC 0x0c065018 */
if(!s->budget--) { s->failed_pc=0x0c065018u; return 0; }
r[3]<<=8;
goto P_0c06501a;
P_0c06501a: /* original 263b, guest PC 0x0c06501a */
if(!s->budget--) { s->failed_pc=0x0c06501au; return 0; }
r[6]|=r[3];
goto P_0c06501c;
P_0c06501c: /* original f3f2, guest PC 0x0c06501c */
if(!s->budget--) { s->failed_pc=0x0c06501cu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[15],r[18],'*');
goto P_0c06501e;
P_0c06501e: /* original f33d, guest PC 0x0c06501e */
if(!s->budget--) { s->failed_pc=0x0c06501eu; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c065020;
P_0c065020: /* original 035a, guest PC 0x0c065020 */
if(!s->budget--) { s->failed_pc=0x0c065020u; return 0; }
r[3]=r[53];
goto P_0c065022;
P_0c065022: /* original 263b, guest PC 0x0c065022 */
if(!s->budget--) { s->failed_pc=0x0c065022u; return 0; }
r[6]|=r[3];
goto P_0c065024;
P_0c065024: /* original 65c3, guest PC 0x0c065024 */
if(!s->budget--) { s->failed_pc=0x0c065024u; return 0; }
r[5]=r[12];
goto P_0c065026;
P_0c065026: /* original ba83, guest PC 0x0c065026 */
if(!s->budget--) { s->failed_pc=0x0c065026u; return 0; }
target=code_base|0x0c064530u; r[16]=code_base|0x0c06502au;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06502au) { target=s->pc; goto dispatch; }
goto P_0c06502a;
P_0c065028: /* original 64e3, guest PC 0x0c065028 */
if(!s->budget--) { s->failed_pc=0x0c065028u; return 0; }
r[4]=r[14];
goto P_0c06502a;
P_0c06502a: /* original 6403, guest PC 0x0c06502a */
if(!s->budget--) { s->failed_pc=0x0c06502au; return 0; }
r[4]=r[0];
goto P_0c06502c;
P_0c06502c: /* original d310, guest PC 0x0c06502c */
if(!s->budget--) { s->failed_pc=0x0c06502cu; return 0; }
r[3]=read(ram,0x0c065070u,4);
goto P_0c06502e;
P_0c06502e: /* original 4408, guest PC 0x0c06502e */
if(!s->budget--) { s->failed_pc=0x0c06502eu; return 0; }
r[4]<<=2;
goto P_0c065030;
P_0c065030: /* original 2342, guest PC 0x0c065030 */
if(!s->budget--) { s->failed_pc=0x0c065030u; return 0; }
write(ram,r[3],r[4],4);
goto P_0c065032;
P_0c065032: /* original ba6e, guest PC 0x0c065032 */
if(!s->budget--) { s->failed_pc=0x0c065032u; return 0; }
target=code_base|0x0c064512u; r[16]=code_base|0x0c065036u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c065036u) { target=s->pc; goto dispatch; }
goto P_0c065036;
P_0c065034: /* original 64e3, guest PC 0x0c065034 */
if(!s->budget--) { s->failed_pc=0x0c065034u; return 0; }
r[4]=r[14];
goto P_0c065036;
P_0c065036: /* original 6403, guest PC 0x0c065036 */
if(!s->budget--) { s->failed_pc=0x0c065036u; return 0; }
r[4]=r[0];
goto P_0c065038;
P_0c065038: /* original e500, guest PC 0x0c065038 */
if(!s->budget--) { s->failed_pc=0x0c065038u; return 0; }
r[5]=0x00000000u;
goto P_0c06503a;
P_0c06503a: /* original ba55, guest PC 0x0c06503a */
if(!s->budget--) { s->failed_pc=0x0c06503au; return 0; }
target=code_base|0x0c0644e8u; r[16]=code_base|0x0c06503eu;
r[6]=r[5];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06503eu) { target=s->pc; goto dispatch; }
goto P_0c06503e;
P_0c06503c: /* original 6653, guest PC 0x0c06503c */
if(!s->budget--) { s->failed_pc=0x0c06503cu; return 0; }
r[6]=r[5];
goto P_0c06503e;
P_0c06503e: /* original 63d2, guest PC 0x0c06503e */
if(!s->budget--) { s->failed_pc=0x0c06503eu; return 0; }
tmp=read(ram,r[13],4);
r[3]=tmp;
goto P_0c065040;
P_0c065040: /* original d10c, guest PC 0x0c065040 */
if(!s->budget--) { s->failed_pc=0x0c065040u; return 0; }
r[1]=read(ram,0x0c065074u,4);
goto P_0c065042;
P_0c065042: /* original 5233, guest PC 0x0c065042 */
if(!s->budget--) { s->failed_pc=0x0c065042u; return 0; }
r[2]=read(ram,r[3]+12,4);
goto P_0c065044;
P_0c065044: /* original 2122, guest PC 0x0c065044 */
if(!s->budget--) { s->failed_pc=0x0c065044u; return 0; }
write(ram,r[1],r[2],4);
goto P_0c065046;
P_0c065046: /* original e000, guest PC 0x0c065046 */
if(!s->budget--) { s->failed_pc=0x0c065046u; return 0; }
r[0]=0x00000000u;
goto P_0c065048;
P_0c065048: /* original 7f10, guest PC 0x0c065048 */
if(!s->budget--) { s->failed_pc=0x0c065048u; return 0; }
r[15]+=0x00000010u;
goto P_0c06504a;
P_0c06504a: /* original 4f26, guest PC 0x0c06504a */
if(!s->budget--) { s->failed_pc=0x0c06504au; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c06504c;
P_0c06504c: /* original fff9, guest PC 0x0c06504c */
if(!s->budget--) { s->failed_pc=0x0c06504cu; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c06504e;
P_0c06504e: /* original 69f6, guest PC 0x0c06504e */
if(!s->budget--) { s->failed_pc=0x0c06504eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c065050;
P_0c065050: /* original 6af6, guest PC 0x0c065050 */
if(!s->budget--) { s->failed_pc=0x0c065050u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c065052;
P_0c065052: /* original 6bf6, guest PC 0x0c065052 */
if(!s->budget--) { s->failed_pc=0x0c065052u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c065054;
P_0c065054: /* original 6cf6, guest PC 0x0c065054 */
if(!s->budget--) { s->failed_pc=0x0c065054u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c065056;
P_0c065056: /* original 6df6, guest PC 0x0c065056 */
if(!s->budget--) { s->failed_pc=0x0c065056u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c065058;
P_0c065058: /* original 000b, guest PC 0x0c065058 */
if(!s->budget--) { s->failed_pc=0x0c065058u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c06505a: /* original 6ef6, guest PC 0x0c06505a */
if(!s->budget--) { s->failed_pc=0x0c06505au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c06505cu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c06505cu; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
