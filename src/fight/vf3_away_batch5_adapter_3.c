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
int vf3_away_batch5_adapter_3(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c043ee8u: goto P_0c043ee8;
case 0x0c043eeau: goto P_0c043eea;
case 0x0c043eecu: goto P_0c043eec;
case 0x0c04403cu: goto P_0c04403c;
case 0x0c04403eu: goto P_0c04403e;
case 0x0c044040u: goto P_0c044040;
case 0x0c044042u: goto P_0c044042;
case 0x0c044044u: goto P_0c044044;
case 0x0c044046u: goto P_0c044046;
case 0x0c044048u: goto P_0c044048;
case 0x0c04404au: goto P_0c04404a;
case 0x0c04404cu: goto P_0c04404c;
case 0x0c04404eu: goto P_0c04404e;
case 0x0c044050u: goto P_0c044050;
case 0x0c044052u: goto P_0c044052;
case 0x0c044054u: goto P_0c044054;
case 0x0c044056u: goto P_0c044056;
case 0x0c044058u: goto P_0c044058;
case 0x0c04405au: goto P_0c04405a;
case 0x0c04405cu: goto P_0c04405c;
case 0x0c04405eu: goto P_0c04405e;
case 0x0c044060u: goto P_0c044060;
case 0x0c044062u: goto P_0c044062;
case 0x0c044064u: goto P_0c044064;
case 0x0c044066u: goto P_0c044066;
case 0x0c0441aau: goto P_0c0441aa;
case 0x0c0441acu: goto P_0c0441ac;
case 0x0c0441aeu: goto P_0c0441ae;
case 0x0c044c7cu: goto P_0c044c7c;
case 0x0c044c7eu: goto P_0c044c7e;
case 0x0c044c80u: goto P_0c044c80;
case 0x0c044c82u: goto P_0c044c82;
case 0x0c044c84u: goto P_0c044c84;
case 0x0c044c86u: goto P_0c044c86;
case 0x0c044c88u: goto P_0c044c88;
case 0x0c044c8au: goto P_0c044c8a;
case 0x0c044c8cu: goto P_0c044c8c;
case 0x0c044c8eu: goto P_0c044c8e;
case 0x0c044c90u: goto P_0c044c90;
case 0x0c044c92u: goto P_0c044c92;
case 0x0c044c94u: goto P_0c044c94;
case 0x0c044c96u: goto P_0c044c96;
case 0x0c044c98u: goto P_0c044c98;
case 0x0c044c9au: goto P_0c044c9a;
case 0x0c044c9cu: goto P_0c044c9c;
case 0x0c044c9eu: goto P_0c044c9e;
case 0x0c044ca0u: goto P_0c044ca0;
case 0x0c044ca2u: goto P_0c044ca2;
case 0x0c044ca4u: goto P_0c044ca4;
case 0x0c044ca6u: goto P_0c044ca6;
case 0x0c044ca8u: goto P_0c044ca8;
case 0x0c044caau: goto P_0c044caa;
case 0x0c044cacu: goto P_0c044cac;
case 0x0c044caeu: goto P_0c044cae;
case 0x0c044cb0u: goto P_0c044cb0;
case 0x0c044cb2u: goto P_0c044cb2;
case 0x0c044cb4u: goto P_0c044cb4;
case 0x0c044cb6u: goto P_0c044cb6;
case 0x0c044cb8u: goto P_0c044cb8;
case 0x0c044cbau: goto P_0c044cba;
case 0x0c044cbcu: goto P_0c044cbc;
case 0x0c044cbeu: goto P_0c044cbe;
case 0x0c044cc0u: goto P_0c044cc0;
case 0x0c044cc2u: goto P_0c044cc2;
case 0x0c044cc4u: goto P_0c044cc4;
case 0x0c044cc6u: goto P_0c044cc6;
case 0x0c044cc8u: goto P_0c044cc8;
case 0x0c044ccau: goto P_0c044cca;
case 0x0c044cccu: goto P_0c044ccc;
case 0x0c044cceu: goto P_0c044cce;
case 0x0c044cd0u: goto P_0c044cd0;
case 0x0c044cd2u: goto P_0c044cd2;
case 0x0c044cd4u: goto P_0c044cd4;
case 0x0c044cd6u: goto P_0c044cd6;
case 0x0c044cd8u: goto P_0c044cd8;
case 0x0c044cdau: goto P_0c044cda;
case 0x0c044cdcu: goto P_0c044cdc;
case 0x0c044cdeu: goto P_0c044cde;
case 0x0c044ce0u: goto P_0c044ce0;
case 0x0c044ce2u: goto P_0c044ce2;
case 0x0c044ce4u: goto P_0c044ce4;
case 0x0c044ce6u: goto P_0c044ce6;
case 0x0c044ce8u: goto P_0c044ce8;
case 0x0c044ceau: goto P_0c044cea;
case 0x0c044cecu: goto P_0c044cec;
case 0x0c044ceeu: goto P_0c044cee;
case 0x0c044cf0u: goto P_0c044cf0;
case 0x0c044cf2u: goto P_0c044cf2;
case 0x0c044cf4u: goto P_0c044cf4;
case 0x0c044cf6u: goto P_0c044cf6;
case 0x0c044cf8u: goto P_0c044cf8;
case 0x0c044cfau: goto P_0c044cfa;
case 0x0c044cfcu: goto P_0c044cfc;
case 0x0c044cfeu: goto P_0c044cfe;
case 0x0c044d00u: goto P_0c044d00;
case 0x0c044d02u: goto P_0c044d02;
case 0x0c044d04u: goto P_0c044d04;
case 0x0c044d06u: goto P_0c044d06;
case 0x0c044d08u: goto P_0c044d08;
case 0x0c044d0au: goto P_0c044d0a;
case 0x0c044d0cu: goto P_0c044d0c;
case 0x0c044d0eu: goto P_0c044d0e;
case 0x0c044d50u: goto P_0c044d50;
case 0x0c044d52u: goto P_0c044d52;
case 0x0c044d54u: goto P_0c044d54;
case 0x0c044d56u: goto P_0c044d56;
case 0x0c044d58u: goto P_0c044d58;
case 0x0c044d5au: goto P_0c044d5a;
case 0x0c044d5cu: goto P_0c044d5c;
case 0x0c044d5eu: goto P_0c044d5e;
case 0x0c044d60u: goto P_0c044d60;
case 0x0c044d62u: goto P_0c044d62;
case 0x0c044d64u: goto P_0c044d64;
case 0x0c044d66u: goto P_0c044d66;
case 0x0c044d68u: goto P_0c044d68;
case 0x0c044d6au: goto P_0c044d6a;
case 0x0c044d6cu: goto P_0c044d6c;
case 0x0c044d6eu: goto P_0c044d6e;
case 0x0c044d70u: goto P_0c044d70;
case 0x0c044d72u: goto P_0c044d72;
case 0x0c044d74u: goto P_0c044d74;
case 0x0c044d76u: goto P_0c044d76;
case 0x0c044d78u: goto P_0c044d78;
case 0x0c044d7au: goto P_0c044d7a;
case 0x0c044d7cu: goto P_0c044d7c;
case 0x0c044d7eu: goto P_0c044d7e;
case 0x0c044d80u: goto P_0c044d80;
case 0x0c044d82u: goto P_0c044d82;
case 0x0c044d84u: goto P_0c044d84;
case 0x0c044d86u: goto P_0c044d86;
case 0x0c044d88u: goto P_0c044d88;
case 0x0c044d8au: goto P_0c044d8a;
case 0x0c044d8cu: goto P_0c044d8c;
case 0x0c044d8eu: goto P_0c044d8e;
case 0x0c044d90u: goto P_0c044d90;
case 0x0c044d92u: goto P_0c044d92;
case 0x0c044d94u: goto P_0c044d94;
case 0x0c044d96u: goto P_0c044d96;
case 0x0c044d98u: goto P_0c044d98;
case 0x0c044d9au: goto P_0c044d9a;
case 0x0c044d9cu: goto P_0c044d9c;
case 0x0c044d9eu: goto P_0c044d9e;
case 0x0c044da0u: goto P_0c044da0;
case 0x0c044da2u: goto P_0c044da2;
case 0x0c044da4u: goto P_0c044da4;
case 0x0c044da6u: goto P_0c044da6;
case 0x0c044da8u: goto P_0c044da8;
case 0x0c044daau: goto P_0c044daa;
case 0x0c044dacu: goto P_0c044dac;
case 0x0c044daeu: goto P_0c044dae;
case 0x0c044db0u: goto P_0c044db0;
case 0x0c044db2u: goto P_0c044db2;
case 0x0c044db4u: goto P_0c044db4;
case 0x0c044db6u: goto P_0c044db6;
case 0x0c044db8u: goto P_0c044db8;
case 0x0c044dbau: goto P_0c044dba;
case 0x0c044dbcu: goto P_0c044dbc;
case 0x0c044dbeu: goto P_0c044dbe;
case 0x0c044dc0u: goto P_0c044dc0;
case 0x0c044dc2u: goto P_0c044dc2;
case 0x0c044dc4u: goto P_0c044dc4;
case 0x0c044dc6u: goto P_0c044dc6;
case 0x0c044dc8u: goto P_0c044dc8;
case 0x0c044dcau: goto P_0c044dca;
case 0x0c044dccu: goto P_0c044dcc;
case 0x0c044dceu: goto P_0c044dce;
case 0x0c044dd0u: goto P_0c044dd0;
case 0x0c044dd2u: goto P_0c044dd2;
case 0x0c044dd4u: goto P_0c044dd4;
case 0x0c044dd6u: goto P_0c044dd6;
case 0x0c044dd8u: goto P_0c044dd8;
case 0x0c044ddau: goto P_0c044dda;
case 0x0c044ddcu: goto P_0c044ddc;
case 0x0c044ddeu: goto P_0c044dde;
case 0x0c044de0u: goto P_0c044de0;
case 0x0c044de2u: goto P_0c044de2;
case 0x0c044de4u: goto P_0c044de4;
case 0x0c044de6u: goto P_0c044de6;
case 0x0c044de8u: goto P_0c044de8;
case 0x0c044deau: goto P_0c044dea;
case 0x0c044decu: goto P_0c044dec;
case 0x0c044deeu: goto P_0c044dee;
case 0x0c044df0u: goto P_0c044df0;
case 0x0c044df2u: goto P_0c044df2;
case 0x0c044df4u: goto P_0c044df4;
case 0x0c044df6u: goto P_0c044df6;
case 0x0c044df8u: goto P_0c044df8;
case 0x0c044dfau: goto P_0c044dfa;
case 0x0c044dfcu: goto P_0c044dfc;
case 0x0c044dfeu: goto P_0c044dfe;
case 0x0c044e00u: goto P_0c044e00;
case 0x0c044e02u: goto P_0c044e02;
case 0x0c044e04u: goto P_0c044e04;
case 0x0c044e06u: goto P_0c044e06;
case 0x0c044e08u: goto P_0c044e08;
case 0x0c044e0au: goto P_0c044e0a;
case 0x0c044e0cu: goto P_0c044e0c;
case 0x0c044e0eu: goto P_0c044e0e;
case 0x0c044e10u: goto P_0c044e10;
case 0x0c044e12u: goto P_0c044e12;
case 0x0c044e14u: goto P_0c044e14;
case 0x0c044e16u: goto P_0c044e16;
case 0x0c044e18u: goto P_0c044e18;
case 0x0c044e1au: goto P_0c044e1a;
case 0x0c044e1cu: goto P_0c044e1c;
case 0x0c044e1eu: goto P_0c044e1e;
case 0x0c044e20u: goto P_0c044e20;
case 0x0c044e22u: goto P_0c044e22;
case 0x0c044e24u: goto P_0c044e24;
case 0x0c044e26u: goto P_0c044e26;
case 0x0c044e28u: goto P_0c044e28;
case 0x0c044e2au: goto P_0c044e2a;
case 0x0c044e2cu: goto P_0c044e2c;
case 0x0c044e2eu: goto P_0c044e2e;
case 0x0c044e30u: goto P_0c044e30;
case 0x0c044e32u: goto P_0c044e32;
case 0x0c044e34u: goto P_0c044e34;
case 0x0c044e36u: goto P_0c044e36;
case 0x0c044e38u: goto P_0c044e38;
case 0x0c044e3au: goto P_0c044e3a;
case 0x0c044e3cu: goto P_0c044e3c;
case 0x0c044e3eu: goto P_0c044e3e;
case 0x0c044e40u: goto P_0c044e40;
case 0x0c044e42u: goto P_0c044e42;
case 0x0c044e44u: goto P_0c044e44;
case 0x0c044e46u: goto P_0c044e46;
case 0x0c044e48u: goto P_0c044e48;
case 0x0c044e6cu: goto P_0c044e6c;
case 0x0c044e6eu: goto P_0c044e6e;
case 0x0c044e70u: goto P_0c044e70;
case 0x0c044e72u: goto P_0c044e72;
case 0x0c044e74u: goto P_0c044e74;
case 0x0c044e76u: goto P_0c044e76;
case 0x0c044e78u: goto P_0c044e78;
case 0x0c044e7au: goto P_0c044e7a;
case 0x0c044e7cu: goto P_0c044e7c;
case 0x0c044e7eu: goto P_0c044e7e;
case 0x0c044e80u: goto P_0c044e80;
case 0x0c044e82u: goto P_0c044e82;
case 0x0c044e84u: goto P_0c044e84;
case 0x0c044e86u: goto P_0c044e86;
case 0x0c044e88u: goto P_0c044e88;
case 0x0c044e8au: goto P_0c044e8a;
case 0x0c044e8cu: goto P_0c044e8c;
case 0x0c044e8eu: goto P_0c044e8e;
case 0x0c044e90u: goto P_0c044e90;
case 0x0c044e92u: goto P_0c044e92;
case 0x0c044e94u: goto P_0c044e94;
case 0x0c044e96u: goto P_0c044e96;
case 0x0c044e98u: goto P_0c044e98;
case 0x0c044e9au: goto P_0c044e9a;
case 0x0c044e9cu: goto P_0c044e9c;
case 0x0c044e9eu: goto P_0c044e9e;
case 0x0c044ea0u: goto P_0c044ea0;
case 0x0c044ea2u: goto P_0c044ea2;
case 0x0c044ea4u: goto P_0c044ea4;
case 0x0c044ea6u: goto P_0c044ea6;
case 0x0c044ea8u: goto P_0c044ea8;
case 0x0c044eaau: goto P_0c044eaa;
case 0x0c044eacu: goto P_0c044eac;
case 0x0c044eaeu: goto P_0c044eae;
case 0x0c044eb0u: goto P_0c044eb0;
case 0x0c044eb2u: goto P_0c044eb2;
case 0x0c044eb4u: goto P_0c044eb4;
case 0x0c044eb6u: goto P_0c044eb6;
case 0x0c044eb8u: goto P_0c044eb8;
case 0x0c044ebau: goto P_0c044eba;
case 0x0c044ebcu: goto P_0c044ebc;
case 0x0c044ebeu: goto P_0c044ebe;
case 0x0c044ec0u: goto P_0c044ec0;
case 0x0c044ec2u: goto P_0c044ec2;
case 0x0c044ec4u: goto P_0c044ec4;
case 0x0c044ec6u: goto P_0c044ec6;
case 0x0c044ec8u: goto P_0c044ec8;
case 0x0c044ecau: goto P_0c044eca;
case 0x0c044eccu: goto P_0c044ecc;
case 0x0c044eceu: goto P_0c044ece;
case 0x0c044ed0u: goto P_0c044ed0;
case 0x0c044ed2u: goto P_0c044ed2;
case 0x0c044ed4u: goto P_0c044ed4;
case 0x0c044ed6u: goto P_0c044ed6;
case 0x0c044ed8u: goto P_0c044ed8;
case 0x0c044edau: goto P_0c044eda;
case 0x0c044edcu: goto P_0c044edc;
case 0x0c044edeu: goto P_0c044ede;
case 0x0c044ee0u: goto P_0c044ee0;
case 0x0c044ee2u: goto P_0c044ee2;
case 0x0c044ee4u: goto P_0c044ee4;
case 0x0c044ee6u: goto P_0c044ee6;
case 0x0c044ee8u: goto P_0c044ee8;
case 0x0c044eeau: goto P_0c044eea;
case 0x0c044eecu: goto P_0c044eec;
case 0x0c044eeeu: goto P_0c044eee;
case 0x0c044ef0u: goto P_0c044ef0;
case 0x0c044ef2u: goto P_0c044ef2;
case 0x0c044ef4u: goto P_0c044ef4;
case 0x0c044ef6u: goto P_0c044ef6;
case 0x0c044ef8u: goto P_0c044ef8;
case 0x0c044efau: goto P_0c044efa;
case 0x0c044efcu: goto P_0c044efc;
case 0x0c044efeu: goto P_0c044efe;
case 0x0c044f00u: goto P_0c044f00;
case 0x0c044f02u: goto P_0c044f02;
case 0x0c044f04u: goto P_0c044f04;
case 0x0c044f06u: goto P_0c044f06;
case 0x0c044f08u: goto P_0c044f08;
case 0x0c044f0au: goto P_0c044f0a;
case 0x0c044f0cu: goto P_0c044f0c;
case 0x0c044f0eu: goto P_0c044f0e;
case 0x0c044f10u: goto P_0c044f10;
case 0x0c044f12u: goto P_0c044f12;
case 0x0c044f14u: goto P_0c044f14;
case 0x0c044f16u: goto P_0c044f16;
case 0x0c044f18u: goto P_0c044f18;
case 0x0c044f1au: goto P_0c044f1a;
case 0x0c044f1cu: goto P_0c044f1c;
case 0x0c044f1eu: goto P_0c044f1e;
case 0x0c044f20u: goto P_0c044f20;
case 0x0c044f22u: goto P_0c044f22;
case 0x0c044f24u: goto P_0c044f24;
case 0x0c044f26u: goto P_0c044f26;
case 0x0c044f28u: goto P_0c044f28;
case 0x0c044f2au: goto P_0c044f2a;
case 0x0c044f2cu: goto P_0c044f2c;
case 0x0c044f2eu: goto P_0c044f2e;
case 0x0c044f30u: goto P_0c044f30;
case 0x0c044f32u: goto P_0c044f32;
case 0x0c044f34u: goto P_0c044f34;
case 0x0c044f36u: goto P_0c044f36;
case 0x0c044f38u: goto P_0c044f38;
case 0x0c044f3au: goto P_0c044f3a;
case 0x0c044f3cu: goto P_0c044f3c;
case 0x0c044f3eu: goto P_0c044f3e;
case 0x0c044f40u: goto P_0c044f40;
case 0x0c044f42u: goto P_0c044f42;
case 0x0c044f44u: goto P_0c044f44;
case 0x0c044f46u: goto P_0c044f46;
case 0x0c044f48u: goto P_0c044f48;
case 0x0c044f4au: goto P_0c044f4a;
case 0x0c044f4cu: goto P_0c044f4c;
case 0x0c044f4eu: goto P_0c044f4e;
case 0x0c044f50u: goto P_0c044f50;
case 0x0c044f52u: goto P_0c044f52;
case 0x0c044f54u: goto P_0c044f54;
case 0x0c044f56u: goto P_0c044f56;
case 0x0c044f58u: goto P_0c044f58;
case 0x0c044f5au: goto P_0c044f5a;
case 0x0c044f5cu: goto P_0c044f5c;
case 0x0c044f5eu: goto P_0c044f5e;
case 0x0c044f60u: goto P_0c044f60;
case 0x0c044f62u: goto P_0c044f62;
case 0x0c044f64u: goto P_0c044f64;
case 0x0c044f66u: goto P_0c044f66;
case 0x0c044f68u: goto P_0c044f68;
case 0x0c044f6au: goto P_0c044f6a;
case 0x0c044f6cu: goto P_0c044f6c;
case 0x0c044f6eu: goto P_0c044f6e;
case 0x0c044f70u: goto P_0c044f70;
case 0x0c044f72u: goto P_0c044f72;
case 0x0c044f74u: goto P_0c044f74;
case 0x0c044f76u: goto P_0c044f76;
case 0x0c044f78u: goto P_0c044f78;
case 0x0c044f7au: goto P_0c044f7a;
default: return vf3_matrix_family(target,s,ram);
}
P_0c043ee8: /* original d312, guest PC 0x0c043ee8 */
if(!s->budget--) { s->failed_pc=0x0c043ee8u; return 0; }
r[3]=read(ram,0x0c043f34u,4);
goto P_0c043eea;
P_0c043eea: /* original 432b, guest PC 0x0c043eea */
if(!s->budget--) { s->failed_pc=0x0c043eeau; return 0; }
target=r[3];
code_base=target&0xff000000u;
switch(target&0x1fffffffu) {
case 0x0c036610u: return vf3_matrix_family(0x0c036610u,s,ram);
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
P_0c043eec: /* original 0009, guest PC 0x0c043eec */
if(!s->budget--) { s->failed_pc=0x0c043eecu; return 0; }
if(!vf3_matrix_family(0x0c043eeeu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c043eeeu; return 0; } return 1;
P_0c04403c: /* original 4f22, guest PC 0x0c04403c */
if(!s->budget--) { s->failed_pc=0x0c04403cu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c04403e;
P_0c04403e: /* original 7ffc, guest PC 0x0c04403e */
if(!s->budget--) { s->failed_pc=0x0c04403eu; return 0; }
r[15]+=0xfffffffcu;
goto P_0c044040;
P_0c044040: /* original 53f2, guest PC 0x0c044040 */
if(!s->budget--) { s->failed_pc=0x0c044040u; return 0; }
r[3]=read(ram,r[15]+8,4);
goto P_0c044042;
P_0c044042: /* original 2f36, guest PC 0x0c044042 */
if(!s->budget--) { s->failed_pc=0x0c044042u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c044044;
P_0c044044: /* original d33d, guest PC 0x0c044044 */
if(!s->budget--) { s->failed_pc=0x0c044044u; return 0; }
r[3]=read(ram,0x0c04413cu,4);
goto P_0c044046;
P_0c044046: /* original 430b, guest PC 0x0c044046 */
if(!s->budget--) { s->failed_pc=0x0c044046u; return 0; }
target=r[3];
r[16]=code_base|0x0c04404au;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04404au) { target=s->pc; goto dispatch; }
goto P_0c04404a;
P_0c044048: /* original 0009, guest PC 0x0c044048 */
if(!s->budget--) { s->failed_pc=0x0c044048u; return 0; }
goto P_0c04404a;
P_0c04404a: /* original 7f04, guest PC 0x0c04404a */
if(!s->budget--) { s->failed_pc=0x0c04404au; return 0; }
r[15]+=0x00000004u;
goto P_0c04404c;
P_0c04404c: /* original 2f02, guest PC 0x0c04404c */
if(!s->budget--) { s->failed_pc=0x0c04404cu; return 0; }
write(ram,r[15],r[0],4);
goto P_0c04404e;
P_0c04404e: /* original d23c, guest PC 0x0c04404e */
if(!s->budget--) { s->failed_pc=0x0c04404eu; return 0; }
r[2]=read(ram,0x0c044140u,4);
goto P_0c044050;
P_0c044050: /* original 9073, guest PC 0x0c044050 */
if(!s->budget--) { s->failed_pc=0x0c044050u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04413au,2);
goto P_0c044052;
P_0c044052: /* original 6322, guest PC 0x0c044052 */
if(!s->budget--) { s->failed_pc=0x0c044052u; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c044054;
P_0c044054: /* original 013e, guest PC 0x0c044054 */
if(!s->budget--) { s->failed_pc=0x0c044054u; return 0; }
r[1]=read(ram,r[3]+r[0],4);
goto P_0c044056;
P_0c044056: /* original 2118, guest PC 0x0c044056 */
if(!s->budget--) { s->failed_pc=0x0c044056u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[1])==0)!=0);
goto P_0c044058;
P_0c044058: /* original 8901, guest PC 0x0c044058 */
if(!s->budget--) { s->failed_pc=0x0c044058u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04405e; }
goto P_0c04405a;
P_0c04405a: /* original be53, guest PC 0x0c04405a */
if(!s->budget--) { s->failed_pc=0x0c04405au; return 0; }
target=code_base|0x0c043d04u; r[16]=code_base|0x0c04405eu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04405eu) { target=s->pc; goto dispatch; }
goto P_0c04405e;
P_0c04405c: /* original 0009, guest PC 0x0c04405c */
if(!s->budget--) { s->failed_pc=0x0c04405cu; return 0; }
goto P_0c04405e;
P_0c04405e: /* original 60f2, guest PC 0x0c04405e */
if(!s->budget--) { s->failed_pc=0x0c04405eu; return 0; }
tmp=read(ram,r[15],4);
r[0]=tmp;
goto P_0c044060;
P_0c044060: /* original 7f04, guest PC 0x0c044060 */
if(!s->budget--) { s->failed_pc=0x0c044060u; return 0; }
r[15]+=0x00000004u;
goto P_0c044062;
P_0c044062: /* original 4f26, guest PC 0x0c044062 */
if(!s->budget--) { s->failed_pc=0x0c044062u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c044064;
P_0c044064: /* original 000b, guest PC 0x0c044064 */
if(!s->budget--) { s->failed_pc=0x0c044064u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c044066: /* original 0009, guest PC 0x0c044066 */
if(!s->budget--) { s->failed_pc=0x0c044066u; return 0; }
if(!vf3_matrix_family(0x0c044068u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c044068u; return 0; } return 1;
P_0c0441aa: /* original d33f, guest PC 0x0c0441aa */
if(!s->budget--) { s->failed_pc=0x0c0441aau; return 0; }
r[3]=read(ram,0x0c0442a8u,4);
goto P_0c0441ac;
P_0c0441ac: /* original 432b, guest PC 0x0c0441ac */
if(!s->budget--) { s->failed_pc=0x0c0441acu; return 0; }
target=r[3];
code_base=target&0xff000000u;
switch(target&0x1fffffffu) {
case 0x0c03665eu: return vf3_matrix_family(0x0c03665eu,s,ram);
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
P_0c0441ae: /* original 0009, guest PC 0x0c0441ae */
if(!s->budget--) { s->failed_pc=0x0c0441aeu; return 0; }
if(!vf3_matrix_family(0x0c0441b0u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0441b0u; return 0; } return 1;
P_0c044c7c: /* original d531, guest PC 0x0c044c7c */
if(!s->budget--) { s->failed_pc=0x0c044c7cu; return 0; }
r[5]=read(ram,0x0c044d44u,4);
goto P_0c044c7e;
P_0c044c7e: /* original 4415, guest PC 0x0c044c7e */
if(!s->budget--) { s->failed_pc=0x0c044c7eu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>0)!=0);
goto P_0c044c80;
P_0c044c80: /* original 9049, guest PC 0x0c044c80 */
if(!s->budget--) { s->failed_pc=0x0c044c80u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c044d16u,2);
goto P_0c044c82;
P_0c044c82: /* original 6352, guest PC 0x0c044c82 */
if(!s->budget--) { s->failed_pc=0x0c044c82u; return 0; }
tmp=read(ram,r[5],4);
r[3]=tmp;
goto P_0c044c84;
P_0c044c84: /* original 6103, guest PC 0x0c044c84 */
if(!s->budget--) { s->failed_pc=0x0c044c84u; return 0; }
r[1]=r[0];
goto P_0c044c86;
P_0c044c86: /* original 710c, guest PC 0x0c044c86 */
if(!s->budget--) { s->failed_pc=0x0c044c86u; return 0; }
r[1]+=0x0000000cu;
goto P_0c044c88;
P_0c044c88: /* original 6233, guest PC 0x0c044c88 */
if(!s->budget--) { s->failed_pc=0x0c044c88u; return 0; }
r[2]=r[3];
goto P_0c044c8a;
P_0c044c8a: /* original 312c, guest PC 0x0c044c8a */
if(!s->budget--) { s->failed_pc=0x0c044c8au; return 0; }
r[1]+=r[2];
goto P_0c044c8c;
P_0c044c8c: /* original 6112, guest PC 0x0c044c8c */
if(!s->budget--) { s->failed_pc=0x0c044c8cu; return 0; }
tmp=read(ram,r[1],4);
r[1]=tmp;
goto P_0c044c8e;
P_0c044c8e: /* original 023e, guest PC 0x0c044c8e */
if(!s->budget--) { s->failed_pc=0x0c044c8eu; return 0; }
r[2]=read(ram,r[3]+r[0],4);
goto P_0c044c90;
P_0c044c90: /* original 4108, guest PC 0x0c044c90 */
if(!s->budget--) { s->failed_pc=0x0c044c90u; return 0; }
r[1]<<=2;
goto P_0c044c92;
P_0c044c92: /* original 321c, guest PC 0x0c044c92 */
if(!s->budget--) { s->failed_pc=0x0c044c92u; return 0; }
r[2]+=r[1];
goto P_0c044c94;
P_0c044c94: /* original 0326, guest PC 0x0c044c94 */
if(!s->budget--) { s->failed_pc=0x0c044c94u; return 0; }
write(ram,r[3]+r[0],r[2],4);
goto P_0c044c96;
P_0c044c96: /* original 6152, guest PC 0x0c044c96 */
if(!s->budget--) { s->failed_pc=0x0c044c96u; return 0; }
tmp=read(ram,r[5],4);
r[1]=tmp;
goto P_0c044c98;
P_0c044c98: /* original 973e, guest PC 0x0c044c98 */
if(!s->budget--) { s->failed_pc=0x0c044c98u; return 0; }
r[7]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c044d18u,2);
goto P_0c044c9a;
P_0c044c9a: /* original 011e, guest PC 0x0c044c9a */
if(!s->budget--) { s->failed_pc=0x0c044c9au; return 0; }
r[1]=read(ram,r[1]+r[0],4);
goto P_0c044c9c;
P_0c044c9c: /* original 8f05, guest PC 0x0c044c9c */
if(!s->budget--) { s->failed_pc=0x0c044c9cu; return 0; }
cond=r[17]&1u;
r[6]=0x00000000u;
if(!cond) { goto P_0c044caa; }
goto P_0c044ca0;
P_0c044c9e: /* original e600, guest PC 0x0c044c9e */
if(!s->budget--) { s->failed_pc=0x0c044c9eu; return 0; }
r[6]=0x00000000u;
goto P_0c044ca0;
P_0c044ca0: /* original 7601, guest PC 0x0c044ca0 */
if(!s->budget--) { s->failed_pc=0x0c044ca0u; return 0; }
r[6]+=0x00000001u;
goto P_0c044ca2;
P_0c044ca2: /* original 2172, guest PC 0x0c044ca2 */
if(!s->budget--) { s->failed_pc=0x0c044ca2u; return 0; }
write(ram,r[1],r[7],4);
goto P_0c044ca4;
P_0c044ca4: /* original 3643, guest PC 0x0c044ca4 */
if(!s->budget--) { s->failed_pc=0x0c044ca4u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[6]>=(int32_t)r[4])!=0);
goto P_0c044ca6;
P_0c044ca6: /* original 8ffb, guest PC 0x0c044ca6 */
if(!s->budget--) { s->failed_pc=0x0c044ca6u; return 0; }
cond=r[17]&1u;
r[1]+=0x00000004u;
if(!cond) { goto P_0c044ca0; }
goto P_0c044caa;
P_0c044ca8: /* original 7104, guest PC 0x0c044ca8 */
if(!s->budget--) { s->failed_pc=0x0c044ca8u; return 0; }
r[1]+=0x00000004u;
goto P_0c044caa;
P_0c044caa: /* original 9036, guest PC 0x0c044caa */
if(!s->budget--) { s->failed_pc=0x0c044caau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c044d1au,2);
goto P_0c044cac;
P_0c044cac: /* original 6252, guest PC 0x0c044cac */
if(!s->budget--) { s->failed_pc=0x0c044cacu; return 0; }
tmp=read(ram,r[5],4);
r[2]=tmp;
goto P_0c044cae;
P_0c044cae: /* original 0246, guest PC 0x0c044cae */
if(!s->budget--) { s->failed_pc=0x0c044caeu; return 0; }
write(ram,r[2]+r[0],r[4],4);
goto P_0c044cb0;
P_0c044cb0: /* original 7004, guest PC 0x0c044cb0 */
if(!s->budget--) { s->failed_pc=0x0c044cb0u; return 0; }
r[0]+=0x00000004u;
goto P_0c044cb2;
P_0c044cb2: /* original 6352, guest PC 0x0c044cb2 */
if(!s->budget--) { s->failed_pc=0x0c044cb2u; return 0; }
tmp=read(ram,r[5],4);
r[3]=tmp;
goto P_0c044cb4;
P_0c044cb4: /* original 4408, guest PC 0x0c044cb4 */
if(!s->budget--) { s->failed_pc=0x0c044cb4u; return 0; }
r[4]<<=2;
goto P_0c044cb6;
P_0c044cb6: /* original 023e, guest PC 0x0c044cb6 */
if(!s->budget--) { s->failed_pc=0x0c044cb6u; return 0; }
r[2]=read(ram,r[3]+r[0],4);
goto P_0c044cb8;
P_0c044cb8: /* original 324c, guest PC 0x0c044cb8 */
if(!s->budget--) { s->failed_pc=0x0c044cb8u; return 0; }
r[2]+=r[4];
goto P_0c044cba;
P_0c044cba: /* original 0326, guest PC 0x0c044cba */
if(!s->budget--) { s->failed_pc=0x0c044cbau; return 0; }
write(ram,r[3]+r[0],r[2],4);
goto P_0c044cbc;
P_0c044cbc: /* original 000b, guest PC 0x0c044cbc */
if(!s->budget--) { s->failed_pc=0x0c044cbcu; return 0; }
target=r[16];
r[0]=0x00000000u;
s->pc=target; return ram->oob==0;
P_0c044cbe: /* original e000, guest PC 0x0c044cbe */
if(!s->budget--) { s->failed_pc=0x0c044cbeu; return 0; }
r[0]=0x00000000u;
goto P_0c044cc0;
P_0c044cc0: /* original 2fe6, guest PC 0x0c044cc0 */
if(!s->budget--) { s->failed_pc=0x0c044cc0u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c044cc2;
P_0c044cc2: /* original e044, guest PC 0x0c044cc2 */
if(!s->budget--) { s->failed_pc=0x0c044cc2u; return 0; }
r[0]=0x00000044u;
goto P_0c044cc4;
P_0c044cc4: /* original 2fd6, guest PC 0x0c044cc4 */
if(!s->budget--) { s->failed_pc=0x0c044cc4u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c044cc6;
P_0c044cc6: /* original 2fc6, guest PC 0x0c044cc6 */
if(!s->budget--) { s->failed_pc=0x0c044cc6u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c044cc8;
P_0c044cc8: /* original 2fb6, guest PC 0x0c044cc8 */
if(!s->budget--) { s->failed_pc=0x0c044cc8u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c044cca;
P_0c044cca: /* original 6b73, guest PC 0x0c044cca */
if(!s->budget--) { s->failed_pc=0x0c044ccau; return 0; }
r[11]=r[7];
goto P_0c044ccc;
P_0c044ccc: /* original 2fa6, guest PC 0x0c044ccc */
if(!s->budget--) { s->failed_pc=0x0c044cccu; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c044cce;
P_0c044cce: /* original 2f96, guest PC 0x0c044cce */
if(!s->budget--) { s->failed_pc=0x0c044cceu; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c044cd0;
P_0c044cd0: /* original 6943, guest PC 0x0c044cd0 */
if(!s->budget--) { s->failed_pc=0x0c044cd0u; return 0; }
r[9]=r[4];
goto P_0c044cd2;
P_0c044cd2: /* original 2f86, guest PC 0x0c044cd2 */
if(!s->budget--) { s->failed_pc=0x0c044cd2u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c044cd4;
P_0c044cd4: /* original 4f22, guest PC 0x0c044cd4 */
if(!s->budget--) { s->failed_pc=0x0c044cd4u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c044cd6;
P_0c044cd6: /* original 4f12, guest PC 0x0c044cd6 */
if(!s->budget--) { s->failed_pc=0x0c044cd6u; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c044cd8;
P_0c044cd8: /* original 7fe4, guest PC 0x0c044cd8 */
if(!s->budget--) { s->failed_pc=0x0c044cd8u; return 0; }
r[15]+=0xffffffe4u;
goto P_0c044cda;
P_0c044cda: /* original 2f50, guest PC 0x0c044cda */
if(!s->budget--) { s->failed_pc=0x0c044cdau; return 0; }
write(ram,r[15],r[5],1);
goto P_0c044cdc;
P_0c044cdc: /* original 1f66, guest PC 0x0c044cdc */
if(!s->budget--) { s->failed_pc=0x0c044cdcu; return 0; }
write(ram,r[15]+24,r[6],4);
goto P_0c044cde;
P_0c044cde: /* original 63f0, guest PC 0x0c044cde */
if(!s->budget--) { s->failed_pc=0x0c044cdeu; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[15],1);
r[3]=tmp;
goto P_0c044ce0;
P_0c044ce0: /* original 0cfe, guest PC 0x0c044ce0 */
if(!s->budget--) { s->failed_pc=0x0c044ce0u; return 0; }
r[12]=read(ram,r[15]+r[0],4);
goto P_0c044ce2;
P_0c044ce2: /* original 633c, guest PC 0x0c044ce2 */
if(!s->budget--) { s->failed_pc=0x0c044ce2u; return 0; }
r[3]=r[3]&255u;
goto P_0c044ce4;
P_0c044ce4: /* original 1f31, guest PC 0x0c044ce4 */
if(!s->budget--) { s->failed_pc=0x0c044ce4u; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c044ce6;
P_0c044ce6: /* original 2f36, guest PC 0x0c044ce6 */
if(!s->budget--) { s->failed_pc=0x0c044ce6u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c044ce8;
P_0c044ce8: /* original 2f96, guest PC 0x0c044ce8 */
if(!s->budget--) { s->failed_pc=0x0c044ce8u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c044cea;
P_0c044cea: /* original d217, guest PC 0x0c044cea */
if(!s->budget--) { s->failed_pc=0x0c044ceau; return 0; }
r[2]=read(ram,0x0c044d48u,4);
goto P_0c044cec;
P_0c044cec: /* original d117, guest PC 0x0c044cec */
if(!s->budget--) { s->failed_pc=0x0c044cecu; return 0; }
r[1]=read(ram,0x0c044d4cu,4);
goto P_0c044cee;
P_0c044cee: /* original 410b, guest PC 0x0c044cee */
if(!s->budget--) { s->failed_pc=0x0c044ceeu; return 0; }
target=r[1];
r[16]=code_base|0x0c044cf2u;
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c044cf2u) { target=s->pc; goto dispatch; }
goto P_0c044cf2;
P_0c044cf0: /* original 2f26, guest PC 0x0c044cf0 */
if(!s->budget--) { s->failed_pc=0x0c044cf0u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c044cf2;
P_0c044cf2: /* original ea2c, guest PC 0x0c044cf2 */
if(!s->budget--) { s->failed_pc=0x0c044cf2u; return 0; }
r[10]=0x0000002cu;
goto P_0c044cf4;
P_0c044cf4: /* original de13, guest PC 0x0c044cf4 */
if(!s->budget--) { s->failed_pc=0x0c044cf4u; return 0; }
r[14]=read(ram,0x0c044d44u,4);
goto P_0c044cf6;
P_0c044cf6: /* original 29af, guest PC 0x0c044cf6 */
if(!s->budget--) { s->failed_pc=0x0c044cf6u; return 0; }
r[19]=(uint32_t)((int32_t)(int16_t)r[9]*(int32_t)(int16_t)r[10]);
goto P_0c044cf8;
P_0c044cf8: /* original 64e2, guest PC 0x0c044cf8 */
if(!s->budget--) { s->failed_pc=0x0c044cf8u; return 0; }
tmp=read(ram,r[14],4);
r[4]=tmp;
goto P_0c044cfa;
P_0c044cfa: /* original 6343, guest PC 0x0c044cfa */
if(!s->budget--) { s->failed_pc=0x0c044cfau; return 0; }
r[3]=r[4];
goto P_0c044cfc;
P_0c044cfc: /* original 7328, guest PC 0x0c044cfc */
if(!s->budget--) { s->failed_pc=0x0c044cfcu; return 0; }
r[3]+=0x00000028u;
goto P_0c044cfe;
P_0c044cfe: /* original 0a1a, guest PC 0x0c044cfe */
if(!s->budget--) { s->failed_pc=0x0c044cfeu; return 0; }
r[10]=r[19];
goto P_0c044d00;
P_0c044d00: /* original 6aaf, guest PC 0x0c044d00 */
if(!s->budget--) { s->failed_pc=0x0c044d00u; return 0; }
r[10]=(uint32_t)(int32_t)(int16_t)r[10];
goto P_0c044d02;
P_0c044d02: /* original 33ac, guest PC 0x0c044d02 */
if(!s->budget--) { s->failed_pc=0x0c044d02u; return 0; }
r[3]+=r[10];
goto P_0c044d04;
P_0c044d04: /* original 8436, guest PC 0x0c044d04 */
if(!s->budget--) { s->failed_pc=0x0c044d04u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[3]+6,1);
goto P_0c044d06;
P_0c044d06: /* original 2008, guest PC 0x0c044d06 */
if(!s->budget--) { s->failed_pc=0x0c044d06u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c044d08;
P_0c044d08: /* original 8d22, guest PC 0x0c044d08 */
if(!s->budget--) { s->failed_pc=0x0c044d08u; return 0; }
cond=r[17]&1u;
r[15]+=0x0000000cu;
if(cond) { goto P_0c044d50; }
goto P_0c044d0c;
P_0c044d0a: /* original 7f0c, guest PC 0x0c044d0a */
if(!s->budget--) { s->failed_pc=0x0c044d0au; return 0; }
r[15]+=0x0000000cu;
goto P_0c044d0c;
P_0c044d0c: /* original a12b, guest PC 0x0c044d0c */
if(!s->budget--) { s->failed_pc=0x0c044d0cu; return 0; }
r[0]=0xffffffffu;
goto P_0c044f66;
P_0c044d0e: /* original e0ff, guest PC 0x0c044d0e */
if(!s->budget--) { s->failed_pc=0x0c044d0eu; return 0; }
r[0]=0xffffffffu;
if(!vf3_matrix_family(0x0c044d10u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c044d10u; return 0; } return 1;
P_0c044d50: /* original 60f0, guest PC 0x0c044d50 */
if(!s->budget--) { s->failed_pc=0x0c044d50u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[15],1);
r[0]=tmp;
goto P_0c044d52;
P_0c044d52: /* original 62f3, guest PC 0x0c044d52 */
if(!s->budget--) { s->failed_pc=0x0c044d52u; return 0; }
r[2]=r[15];
goto P_0c044d54;
P_0c044d54: /* original 7210, guest PC 0x0c044d54 */
if(!s->budget--) { s->failed_pc=0x0c044d54u; return 0; }
r[2]+=0x00000010u;
goto P_0c044d56;
P_0c044d56: /* original 68b3, guest PC 0x0c044d56 */
if(!s->budget--) { s->failed_pc=0x0c044d56u; return 0; }
r[8]=r[11];
goto P_0c044d58;
P_0c044d58: /* original 8036, guest PC 0x0c044d58 */
if(!s->budget--) { s->failed_pc=0x0c044d58u; return 0; }
write(ram,r[3]+6,r[0],1);
goto P_0c044d5a;
P_0c044d5a: /* original 38cc, guest PC 0x0c044d5a */
if(!s->budget--) { s->failed_pc=0x0c044d5au; return 0; }
r[8]+=r[12];
goto P_0c044d5c;
P_0c044d5c: /* original 6483, guest PC 0x0c044d5c */
if(!s->budget--) { s->failed_pc=0x0c044d5cu; return 0; }
r[4]=r[8];
goto P_0c044d5e;
P_0c044d5e: /* original 7403, guest PC 0x0c044d5e */
if(!s->budget--) { s->failed_pc=0x0c044d5eu; return 0; }
r[4]+=0x00000003u;
goto P_0c044d60;
P_0c044d60: /* original 1f42, guest PC 0x0c044d60 */
if(!s->budget--) { s->failed_pc=0x0c044d60u; return 0; }
write(ram,r[15]+8,r[4],4);
goto P_0c044d62;
P_0c044d62: /* original e403, guest PC 0x0c044d62 */
if(!s->budget--) { s->failed_pc=0x0c044d62u; return 0; }
r[4]=0x00000003u;
goto P_0c044d64;
P_0c044d64: /* original d03c, guest PC 0x0c044d64 */
if(!s->budget--) { s->failed_pc=0x0c044d64u; return 0; }
r[0]=read(ram,0x0c044e58u,4);
goto P_0c044d66;
P_0c044d66: /* original 039c, guest PC 0x0c044d66 */
if(!s->budget--) { s->failed_pc=0x0c044d66u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[9]+r[0],1);
goto P_0c044d68;
P_0c044d68: /* original 2230, guest PC 0x0c044d68 */
if(!s->budget--) { s->failed_pc=0x0c044d68u; return 0; }
write(ram,r[2],r[3],1);
goto P_0c044d6a;
P_0c044d6a: /* original e2fa, guest PC 0x0c044d6a */
if(!s->budget--) { s->failed_pc=0x0c044d6au; return 0; }
r[2]=0xfffffffau;
goto P_0c044d6c;
P_0c044d6c: /* original 956d, guest PC 0x0c044d6c */
if(!s->budget--) { s->failed_pc=0x0c044d6cu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c044e4au,2);
goto P_0c044d6e;
P_0c044d6e: /* original 2539, guest PC 0x0c044d6e */
if(!s->budget--) { s->failed_pc=0x0c044d6eu; return 0; }
r[5]&=r[3];
goto P_0c044d70;
P_0c044d70: /* original 655c, guest PC 0x0c044d70 */
if(!s->budget--) { s->failed_pc=0x0c044d70u; return 0; }
r[5]=r[5]&255u;
goto P_0c044d72;
P_0c044d72: /* original 1f53, guest PC 0x0c044d72 */
if(!s->budget--) { s->failed_pc=0x0c044d72u; return 0; }
write(ram,r[15]+12,r[5],4);
goto P_0c044d74;
P_0c044d74: /* original 452c, guest PC 0x0c044d74 */
if(!s->budget--) { s->failed_pc=0x0c044d74u; return 0; }
r[5]=(r[2]&0x80000000u)?((r[2]&31u)?(uint32_t)((int32_t)r[5]>>((-r[2])&31u)):((int32_t)r[5]<0?0xffffffffu:0)):r[5]<<(r[2]&31u);
goto P_0c044d76;
P_0c044d76: /* original 2549, guest PC 0x0c044d76 */
if(!s->budget--) { s->failed_pc=0x0c044d76u; return 0; }
r[5]&=r[4];
goto P_0c044d78;
P_0c044d78: /* original 2f52, guest PC 0x0c044d78 */
if(!s->budget--) { s->failed_pc=0x0c044d78u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c044d7a;
P_0c044d7a: /* original 6de2, guest PC 0x0c044d7a */
if(!s->budget--) { s->failed_pc=0x0c044d7au; return 0; }
tmp=read(ram,r[14],4);
r[13]=tmp;
goto P_0c044d7c;
P_0c044d7c: /* original 9066, guest PC 0x0c044d7c */
if(!s->budget--) { s->failed_pc=0x0c044d7cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c044e4cu,2);
goto P_0c044d7e;
P_0c044d7e: /* original 62d3, guest PC 0x0c044d7e */
if(!s->budget--) { s->failed_pc=0x0c044d7eu; return 0; }
r[2]=r[13];
goto P_0c044d80;
P_0c044d80: /* original 032e, guest PC 0x0c044d80 */
if(!s->budget--) { s->failed_pc=0x0c044d80u; return 0; }
r[3]=read(ram,r[2]+r[0],4);
goto P_0c044d82;
P_0c044d82: /* original 4315, guest PC 0x0c044d82 */
if(!s->budget--) { s->failed_pc=0x0c044d82u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>0)!=0);
goto P_0c044d84;
P_0c044d84: /* original 8b0f, guest PC 0x0c044d84 */
if(!s->budget--) { s->failed_pc=0x0c044d84u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c044da6; }
goto P_0c044d86;
P_0c044d86: /* original 9062, guest PC 0x0c044d86 */
if(!s->budget--) { s->failed_pc=0x0c044d86u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c044e4eu,2);
goto P_0c044d88;
P_0c044d88: /* original 01de, guest PC 0x0c044d88 */
if(!s->budget--) { s->failed_pc=0x0c044d88u; return 0; }
r[1]=read(ram,r[13]+r[0],4);
goto P_0c044d8a;
P_0c044d8a: /* original 4115, guest PC 0x0c044d8a */
if(!s->budget--) { s->failed_pc=0x0c044d8au; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[1]>0)!=0);
goto P_0c044d8c;
P_0c044d8c: /* original 8b0b, guest PC 0x0c044d8c */
if(!s->budget--) { s->failed_pc=0x0c044d8cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c044da6; }
goto P_0c044d8e;
P_0c044d8e: /* original 905f, guest PC 0x0c044d8e */
if(!s->budget--) { s->failed_pc=0x0c044d8eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c044e50u,2);
goto P_0c044d90;
P_0c044d90: /* original 02de, guest PC 0x0c044d90 */
if(!s->budget--) { s->failed_pc=0x0c044d90u; return 0; }
r[2]=read(ram,r[13]+r[0],4);
goto P_0c044d92;
P_0c044d92: /* original 6322, guest PC 0x0c044d92 */
if(!s->budget--) { s->failed_pc=0x0c044d92u; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c044d94;
P_0c044d94: /* original 62f2, guest PC 0x0c044d94 */
if(!s->budget--) { s->failed_pc=0x0c044d94u; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c044d96;
P_0c044d96: /* original 4329, guest PC 0x0c044d96 */
if(!s->budget--) { s->failed_pc=0x0c044d96u; return 0; }
r[3]>>=16;
goto P_0c044d98;
P_0c044d98: /* original 633f, guest PC 0x0c044d98 */
if(!s->budget--) { s->failed_pc=0x0c044d98u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)r[3];
goto P_0c044d9a;
P_0c044d9a: /* original 2439, guest PC 0x0c044d9a */
if(!s->budget--) { s->failed_pc=0x0c044d9au; return 0; }
r[4]&=r[3];
goto P_0c044d9c;
P_0c044d9c: /* original 3240, guest PC 0x0c044d9c */
if(!s->budget--) { s->failed_pc=0x0c044d9cu; return 0; }
r[17]=(r[17]&~1u)|((r[2]==r[4])!=0);
goto P_0c044d9e;
P_0c044d9e: /* original 8b02, guest PC 0x0c044d9e */
if(!s->budget--) { s->failed_pc=0x0c044d9eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c044da6; }
goto P_0c044da0;
P_0c044da0: /* original 9054, guest PC 0x0c044da0 */
if(!s->budget--) { s->failed_pc=0x0c044da0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c044e4cu,2);
goto P_0c044da2;
P_0c044da2: /* original bf6b, guest PC 0x0c044da2 */
if(!s->budget--) { s->failed_pc=0x0c044da2u; return 0; }
target=code_base|0x0c044c7cu; r[16]=code_base|0x0c044da6u;
r[4]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c044da6u) { target=s->pc; goto dispatch; }
goto P_0c044da6;
P_0c044da4: /* original 04de, guest PC 0x0c044da4 */
if(!s->budget--) { s->failed_pc=0x0c044da4u; return 0; }
r[4]=read(ram,r[13]+r[0],4);
goto P_0c044da6;
P_0c044da6: /* original 9053, guest PC 0x0c044da6 */
if(!s->budget--) { s->failed_pc=0x0c044da6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c044e50u,2);
goto P_0c044da8;
P_0c044da8: /* original 62e2, guest PC 0x0c044da8 */
if(!s->budget--) { s->failed_pc=0x0c044da8u; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c044daa;
P_0c044daa: /* original 6103, guest PC 0x0c044daa */
if(!s->budget--) { s->failed_pc=0x0c044daau; return 0; }
r[1]=r[0];
goto P_0c044dac;
P_0c044dac: /* original 710c, guest PC 0x0c044dac */
if(!s->budget--) { s->failed_pc=0x0c044dacu; return 0; }
r[1]+=0x0000000cu;
goto P_0c044dae;
P_0c044dae: /* original 6323, guest PC 0x0c044dae */
if(!s->budget--) { s->failed_pc=0x0c044daeu; return 0; }
r[3]=r[2];
goto P_0c044db0;
P_0c044db0: /* original 313c, guest PC 0x0c044db0 */
if(!s->budget--) { s->failed_pc=0x0c044db0u; return 0; }
r[1]+=r[3];
goto P_0c044db2;
P_0c044db2: /* original 6112, guest PC 0x0c044db2 */
if(!s->budget--) { s->failed_pc=0x0c044db2u; return 0; }
tmp=read(ram,r[1],4);
r[1]=tmp;
goto P_0c044db4;
P_0c044db4: /* original 032e, guest PC 0x0c044db4 */
if(!s->budget--) { s->failed_pc=0x0c044db4u; return 0; }
r[3]=read(ram,r[2]+r[0],4);
goto P_0c044db6;
P_0c044db6: /* original 4108, guest PC 0x0c044db6 */
if(!s->budget--) { s->failed_pc=0x0c044db6u; return 0; }
r[1]<<=2;
goto P_0c044db8;
P_0c044db8: /* original 331c, guest PC 0x0c044db8 */
if(!s->budget--) { s->failed_pc=0x0c044db8u; return 0; }
r[3]+=r[1];
goto P_0c044dba;
P_0c044dba: /* original 0236, guest PC 0x0c044dba */
if(!s->budget--) { s->failed_pc=0x0c044dbau; return 0; }
write(ram,r[2]+r[0],r[3],4);
goto P_0c044dbc;
P_0c044dbc: /* original 618c, guest PC 0x0c044dbc */
if(!s->budget--) { s->failed_pc=0x0c044dbcu; return 0; }
r[1]=r[8]&255u;
goto P_0c044dbe;
P_0c044dbe: /* original 62f2, guest PC 0x0c044dbe */
if(!s->budget--) { s->failed_pc=0x0c044dbeu; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c044dc0;
P_0c044dc0: /* original 6de2, guest PC 0x0c044dc0 */
if(!s->budget--) { s->failed_pc=0x0c044dc0u; return 0; }
tmp=read(ram,r[14],4);
r[13]=tmp;
goto P_0c044dc2;
P_0c044dc2: /* original 4228, guest PC 0x0c044dc2 */
if(!s->budget--) { s->failed_pc=0x0c044dc2u; return 0; }
r[2]<<=16;
goto P_0c044dc4;
P_0c044dc4: /* original 0dde, guest PC 0x0c044dc4 */
if(!s->budget--) { s->failed_pc=0x0c044dc4u; return 0; }
r[13]=read(ram,r[13]+r[0],4);
goto P_0c044dc6;
P_0c044dc6: /* original 221b, guest PC 0x0c044dc6 */
if(!s->budget--) { s->failed_pc=0x0c044dc6u; return 0; }
r[2]|=r[1];
goto P_0c044dc8;
P_0c044dc8: /* original 1f15, guest PC 0x0c044dc8 */
if(!s->budget--) { s->failed_pc=0x0c044dc8u; return 0; }
write(ram,r[15]+20,r[1],4);
goto P_0c044dca;
P_0c044dca: /* original 2d22, guest PC 0x0c044dca */
if(!s->budget--) { s->failed_pc=0x0c044dcau; return 0; }
write(ram,r[13],r[2],4);
goto P_0c044dcc;
P_0c044dcc: /* original 7d04, guest PC 0x0c044dcc */
if(!s->budget--) { s->failed_pc=0x0c044dccu; return 0; }
r[13]+=0x00000004u;
goto P_0c044dce;
P_0c044dce: /* original 2fd6, guest PC 0x0c044dce */
if(!s->budget--) { s->failed_pc=0x0c044dceu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c044dd0;
P_0c044dd0: /* original 7d04, guest PC 0x0c044dd0 */
if(!s->budget--) { s->failed_pc=0x0c044dd0u; return 0; }
r[13]+=0x00000004u;
goto P_0c044dd2;
P_0c044dd2: /* original 60e2, guest PC 0x0c044dd2 */
if(!s->budget--) { s->failed_pc=0x0c044dd2u; return 0; }
tmp=read(ram,r[14],4);
r[0]=tmp;
goto P_0c044dd4;
P_0c044dd4: /* original 913d, guest PC 0x0c044dd4 */
if(!s->budget--) { s->failed_pc=0x0c044dd4u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c044e52u,2);
goto P_0c044dd6;
P_0c044dd6: /* original 6303, guest PC 0x0c044dd6 */
if(!s->budget--) { s->failed_pc=0x0c044dd6u; return 0; }
r[3]=r[0];
goto P_0c044dd8;
P_0c044dd8: /* original 313c, guest PC 0x0c044dd8 */
if(!s->budget--) { s->failed_pc=0x0c044dd8u; return 0; }
r[1]+=r[3];
goto P_0c044dda;
P_0c044dda: /* original 6310, guest PC 0x0c044dda */
if(!s->budget--) { s->failed_pc=0x0c044ddau; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[1],1);
r[3]=tmp;
goto P_0c044ddc;
P_0c044ddc: /* original 6233, guest PC 0x0c044ddc */
if(!s->budget--) { s->failed_pc=0x0c044ddcu; return 0; }
r[2]=r[3];
goto P_0c044dde;
P_0c044dde: /* original 4300, guest PC 0x0c044dde */
if(!s->budget--) { s->failed_pc=0x0c044ddeu; return 0; }
r[17]=(r[17]&~1u)|((r[3]>>31)!=0);
r[3]<<=1;
goto P_0c044de0;
P_0c044de0: /* original 332c, guest PC 0x0c044de0 */
if(!s->budget--) { s->failed_pc=0x0c044de0u; return 0; }
r[3]+=r[2];
goto P_0c044de2;
P_0c044de2: /* original 4308, guest PC 0x0c044de2 */
if(!s->budget--) { s->failed_pc=0x0c044de2u; return 0; }
r[3]<<=2;
goto P_0c044de4;
P_0c044de4: /* original 4308, guest PC 0x0c044de4 */
if(!s->budget--) { s->failed_pc=0x0c044de4u; return 0; }
r[3]<<=2;
goto P_0c044de6;
P_0c044de6: /* original 9235, guest PC 0x0c044de6 */
if(!s->budget--) { s->failed_pc=0x0c044de6u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c044e54u,2);
goto P_0c044de8;
P_0c044de8: /* original 4300, guest PC 0x0c044de8 */
if(!s->budget--) { s->failed_pc=0x0c044de8u; return 0; }
r[17]=(r[17]&~1u)|((r[3]>>31)!=0);
r[3]<<=1;
goto P_0c044dea;
P_0c044dea: /* original 633c, guest PC 0x0c044dea */
if(!s->budget--) { s->failed_pc=0x0c044deau; return 0; }
r[3]=r[3]&255u;
goto P_0c044dec;
P_0c044dec: /* original 6493, guest PC 0x0c044dec */
if(!s->budget--) { s->failed_pc=0x0c044decu; return 0; }
r[4]=r[9];
goto P_0c044dee;
P_0c044dee: /* original 302c, guest PC 0x0c044dee */
if(!s->budget--) { s->failed_pc=0x0c044deeu; return 0; }
r[0]+=r[2];
goto P_0c044df0;
P_0c044df0: /* original 303c, guest PC 0x0c044df0 */
if(!s->budget--) { s->failed_pc=0x0c044df0u; return 0; }
r[0]+=r[3];
goto P_0c044df2;
P_0c044df2: /* original d31a, guest PC 0x0c044df2 */
if(!s->budget--) { s->failed_pc=0x0c044df2u; return 0; }
r[3]=read(ram,0x0c044e5cu,4);
goto P_0c044df4;
P_0c044df4: /* original 4408, guest PC 0x0c044df4 */
if(!s->budget--) { s->failed_pc=0x0c044df4u; return 0; }
r[4]<<=2;
goto P_0c044df6;
P_0c044df6: /* original 430b, guest PC 0x0c044df6 */
if(!s->budget--) { s->failed_pc=0x0c044df6u; return 0; }
target=r[3];
r[16]=code_base|0x0c044dfau;
r[4]=read(ram,r[4]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c044dfau) { target=s->pc; goto dispatch; }
goto P_0c044dfa;
P_0c044df8: /* original 044e, guest PC 0x0c044df8 */
if(!s->budget--) { s->failed_pc=0x0c044df8u; return 0; }
r[4]=read(ram,r[4]+r[0],4);
goto P_0c044dfa;
P_0c044dfa: /* original 62f6, guest PC 0x0c044dfa */
if(!s->budget--) { s->failed_pc=0x0c044dfau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[2]=tmp;
goto P_0c044dfc;
P_0c044dfc: /* original 2202, guest PC 0x0c044dfc */
if(!s->budget--) { s->failed_pc=0x0c044dfcu; return 0; }
write(ram,r[2],r[0],4);
goto P_0c044dfe;
P_0c044dfe: /* original e010, guest PC 0x0c044dfe */
if(!s->budget--) { s->failed_pc=0x0c044dfeu; return 0; }
r[0]=0x00000010u;
goto P_0c044e00;
P_0c044e00: /* original 09fc, guest PC 0x0c044e00 */
if(!s->budget--) { s->failed_pc=0x0c044e00u; return 0; }
r[9]=(uint32_t)(int32_t)(int8_t)read(ram,r[15]+r[0],1);
goto P_0c044e02;
P_0c044e02: /* original 60e2, guest PC 0x0c044e02 */
if(!s->budget--) { s->failed_pc=0x0c044e02u; return 0; }
tmp=read(ram,r[14],4);
r[0]=tmp;
goto P_0c044e04;
P_0c044e04: /* original 9127, guest PC 0x0c044e04 */
if(!s->budget--) { s->failed_pc=0x0c044e04u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c044e56u,2);
goto P_0c044e06;
P_0c044e06: /* original d616, guest PC 0x0c044e06 */
if(!s->budget--) { s->failed_pc=0x0c044e06u; return 0; }
r[6]=read(ram,0x0c044e60u,4);
goto P_0c044e08;
P_0c044e08: /* original 001e, guest PC 0x0c044e08 */
if(!s->budget--) { s->failed_pc=0x0c044e08u; return 0; }
r[0]=read(ram,r[1]+r[0],4);
goto P_0c044e0a;
P_0c044e0a: /* original 57f6, guest PC 0x0c044e0a */
if(!s->budget--) { s->failed_pc=0x0c044e0au; return 0; }
r[7]=read(ram,r[15]+24,4);
goto P_0c044e0c;
P_0c044e0c: /* original d416, guest PC 0x0c044e0c */
if(!s->budget--) { s->failed_pc=0x0c044e0cu; return 0; }
r[4]=read(ram,0x0c044e68u,4);
goto P_0c044e0e;
P_0c044e0e: /* original 8801, guest PC 0x0c044e0e */
if(!s->budget--) { s->failed_pc=0x0c044e0eu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c044e10;
P_0c044e10: /* original d514, guest PC 0x0c044e10 */
if(!s->budget--) { s->failed_pc=0x0c044e10u; return 0; }
r[5]=read(ram,0x0c044e64u,4);
goto P_0c044e12;
P_0c044e12: /* original 8f2b, guest PC 0x0c044e12 */
if(!s->budget--) { s->failed_pc=0x0c044e12u; return 0; }
cond=r[17]&1u;
r[9]=r[9]&255u;
if(!cond) { goto P_0c044e6c; }
goto P_0c044e16;
P_0c044e14: /* original 699c, guest PC 0x0c044e14 */
if(!s->budget--) { s->failed_pc=0x0c044e14u; return 0; }
r[9]=r[9]&255u;
goto P_0c044e16;
P_0c044e16: /* original 53f1, guest PC 0x0c044e16 */
if(!s->budget--) { s->failed_pc=0x0c044e16u; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c044e18;
P_0c044e18: /* original 4928, guest PC 0x0c044e18 */
if(!s->budget--) { s->failed_pc=0x0c044e18u; return 0; }
r[9]<<=16;
goto P_0c044e1a;
P_0c044e1a: /* original 50f3, guest PC 0x0c044e1a */
if(!s->budget--) { s->failed_pc=0x0c044e1au; return 0; }
r[0]=read(ram,r[15]+12,4);
goto P_0c044e1c;
P_0c044e1c: /* original 2949, guest PC 0x0c044e1c */
if(!s->budget--) { s->failed_pc=0x0c044e1cu; return 0; }
r[9]&=r[4];
goto P_0c044e1e;
P_0c044e1e: /* original 4328, guest PC 0x0c044e1e */
if(!s->budget--) { s->failed_pc=0x0c044e1eu; return 0; }
r[3]<<=16;
goto P_0c044e20;
P_0c044e20: /* original 4b15, guest PC 0x0c044e20 */
if(!s->budget--) { s->failed_pc=0x0c044e20u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[11]>0)!=0);
goto P_0c044e22;
P_0c044e22: /* original 4318, guest PC 0x0c044e22 */
if(!s->budget--) { s->failed_pc=0x0c044e22u; return 0; }
r[3]<<=8;
goto P_0c044e24;
P_0c044e24: /* original 4018, guest PC 0x0c044e24 */
if(!s->budget--) { s->failed_pc=0x0c044e24u; return 0; }
r[0]<<=8;
goto P_0c044e26;
P_0c044e26: /* original 2369, guest PC 0x0c044e26 */
if(!s->budget--) { s->failed_pc=0x0c044e26u; return 0; }
r[3]&=r[6];
goto P_0c044e28;
P_0c044e28: /* original 2059, guest PC 0x0c044e28 */
if(!s->budget--) { s->failed_pc=0x0c044e28u; return 0; }
r[0]&=r[5];
goto P_0c044e2a;
P_0c044e2a: /* original 239b, guest PC 0x0c044e2a */
if(!s->budget--) { s->failed_pc=0x0c044e2au; return 0; }
r[3]|=r[9];
goto P_0c044e2c;
P_0c044e2c: /* original 230b, guest PC 0x0c044e2c */
if(!s->budget--) { s->failed_pc=0x0c044e2cu; return 0; }
r[3]|=r[0];
goto P_0c044e2e;
P_0c044e2e: /* original 50f5, guest PC 0x0c044e2e */
if(!s->budget--) { s->failed_pc=0x0c044e2eu; return 0; }
r[0]=read(ram,r[15]+20,4);
goto P_0c044e30;
P_0c044e30: /* original 230b, guest PC 0x0c044e30 */
if(!s->budget--) { s->failed_pc=0x0c044e30u; return 0; }
r[3]|=r[0];
goto P_0c044e32;
P_0c044e32: /* original 2d32, guest PC 0x0c044e32 */
if(!s->budget--) { s->failed_pc=0x0c044e32u; return 0; }
write(ram,r[13],r[3],4);
goto P_0c044e34;
P_0c044e34: /* original 7d04, guest PC 0x0c044e34 */
if(!s->budget--) { s->failed_pc=0x0c044e34u; return 0; }
r[13]+=0x00000004u;
goto P_0c044e36;
P_0c044e36: /* original 8f43, guest PC 0x0c044e36 */
if(!s->budget--) { s->failed_pc=0x0c044e36u; return 0; }
cond=r[17]&1u;
r[9]=0x00000000u;
if(!cond) { goto P_0c044ec0; }
goto P_0c044e3a;
P_0c044e38: /* original e900, guest PC 0x0c044e38 */
if(!s->budget--) { s->failed_pc=0x0c044e38u; return 0; }
r[9]=0x00000000u;
goto P_0c044e3a;
P_0c044e3a: /* original 6376, guest PC 0x0c044e3a */
if(!s->budget--) { s->failed_pc=0x0c044e3au; return 0; }
tmp=read(ram,r[7],4);
r[7]+=4;
r[3]=tmp;
goto P_0c044e3c;
P_0c044e3c: /* original 7901, guest PC 0x0c044e3c */
if(!s->budget--) { s->failed_pc=0x0c044e3cu; return 0; }
r[9]+=0x00000001u;
goto P_0c044e3e;
P_0c044e3e: /* original 39b3, guest PC 0x0c044e3e */
if(!s->budget--) { s->failed_pc=0x0c044e3eu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[9]>=(int32_t)r[11])!=0);
goto P_0c044e40;
P_0c044e40: /* original 2d32, guest PC 0x0c044e40 */
if(!s->budget--) { s->failed_pc=0x0c044e40u; return 0; }
write(ram,r[13],r[3],4);
goto P_0c044e42;
P_0c044e42: /* original 8ffa, guest PC 0x0c044e42 */
if(!s->budget--) { s->failed_pc=0x0c044e42u; return 0; }
cond=r[17]&1u;
r[13]+=0x00000004u;
if(!cond) { goto P_0c044e3a; }
goto P_0c044e46;
P_0c044e44: /* original 7d04, guest PC 0x0c044e44 */
if(!s->budget--) { s->failed_pc=0x0c044e44u; return 0; }
r[13]+=0x00000004u;
goto P_0c044e46;
P_0c044e46: /* original a03b, guest PC 0x0c044e46 */
if(!s->budget--) { s->failed_pc=0x0c044e46u; return 0; }
goto P_0c044ec0;
P_0c044e48: /* original 0009, guest PC 0x0c044e48 */
if(!s->budget--) { s->failed_pc=0x0c044e48u; return 0; }
if(!vf3_matrix_family(0x0c044e4au,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c044e4au; return 0; } return 1;
P_0c044e6c: /* original 53f3, guest PC 0x0c044e6c */
if(!s->budget--) { s->failed_pc=0x0c044e6cu; return 0; }
r[3]=read(ram,r[15]+12,4);
goto P_0c044e6e;
P_0c044e6e: /* original 4918, guest PC 0x0c044e6e */
if(!s->budget--) { s->failed_pc=0x0c044e6eu; return 0; }
r[9]<<=8;
goto P_0c044e70;
P_0c044e70: /* original 4828, guest PC 0x0c044e70 */
if(!s->budget--) { s->failed_pc=0x0c044e70u; return 0; }
r[8]<<=16;
goto P_0c044e72;
P_0c044e72: /* original 50f1, guest PC 0x0c044e72 */
if(!s->budget--) { s->failed_pc=0x0c044e72u; return 0; }
r[0]=read(ram,r[15]+4,4);
goto P_0c044e74;
P_0c044e74: /* original 4328, guest PC 0x0c044e74 */
if(!s->budget--) { s->failed_pc=0x0c044e74u; return 0; }
r[3]<<=16;
goto P_0c044e76;
P_0c044e76: /* original 4b15, guest PC 0x0c044e76 */
if(!s->budget--) { s->failed_pc=0x0c044e76u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[11]>0)!=0);
goto P_0c044e78;
P_0c044e78: /* original 4818, guest PC 0x0c044e78 */
if(!s->budget--) { s->failed_pc=0x0c044e78u; return 0; }
r[8]<<=8;
goto P_0c044e7a;
P_0c044e7a: /* original 2349, guest PC 0x0c044e7a */
if(!s->budget--) { s->failed_pc=0x0c044e7au; return 0; }
r[3]&=r[4];
goto P_0c044e7c;
P_0c044e7c: /* original 2959, guest PC 0x0c044e7c */
if(!s->budget--) { s->failed_pc=0x0c044e7cu; return 0; }
r[9]&=r[5];
goto P_0c044e7e;
P_0c044e7e: /* original 2869, guest PC 0x0c044e7e */
if(!s->budget--) { s->failed_pc=0x0c044e7eu; return 0; }
r[8]&=r[6];
goto P_0c044e80;
P_0c044e80: /* original 239b, guest PC 0x0c044e80 */
if(!s->budget--) { s->failed_pc=0x0c044e80u; return 0; }
r[3]|=r[9];
goto P_0c044e82;
P_0c044e82: /* original 238b, guest PC 0x0c044e82 */
if(!s->budget--) { s->failed_pc=0x0c044e82u; return 0; }
r[3]|=r[8];
goto P_0c044e84;
P_0c044e84: /* original 230b, guest PC 0x0c044e84 */
if(!s->budget--) { s->failed_pc=0x0c044e84u; return 0; }
r[3]|=r[0];
goto P_0c044e86;
P_0c044e86: /* original 2d32, guest PC 0x0c044e86 */
if(!s->budget--) { s->failed_pc=0x0c044e86u; return 0; }
write(ram,r[13],r[3],4);
goto P_0c044e88;
P_0c044e88: /* original 7d04, guest PC 0x0c044e88 */
if(!s->budget--) { s->failed_pc=0x0c044e88u; return 0; }
r[13]+=0x00000004u;
goto P_0c044e8a;
P_0c044e8a: /* original 8f19, guest PC 0x0c044e8a */
if(!s->budget--) { s->failed_pc=0x0c044e8au; return 0; }
cond=r[17]&1u;
r[8]=0x00000000u;
if(!cond) { goto P_0c044ec0; }
goto P_0c044e8e;
P_0c044e8c: /* original e800, guest PC 0x0c044e8c */
if(!s->budget--) { s->failed_pc=0x0c044e8cu; return 0; }
r[8]=0x00000000u;
goto P_0c044e8e;
P_0c044e8e: /* original 6976, guest PC 0x0c044e8e */
if(!s->budget--) { s->failed_pc=0x0c044e8eu; return 0; }
tmp=read(ram,r[7],4);
r[7]+=4;
r[9]=tmp;
goto P_0c044e90;
P_0c044e90: /* original 7801, guest PC 0x0c044e90 */
if(!s->budget--) { s->failed_pc=0x0c044e90u; return 0; }
r[8]+=0x00000001u;
goto P_0c044e92;
P_0c044e92: /* original 38b3, guest PC 0x0c044e92 */
if(!s->budget--) { s->failed_pc=0x0c044e92u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[8]>=(int32_t)r[11])!=0);
goto P_0c044e94;
P_0c044e94: /* original 6293, guest PC 0x0c044e94 */
if(!s->budget--) { s->failed_pc=0x0c044e94u; return 0; }
r[2]=r[9];
goto P_0c044e96;
P_0c044e96: /* original 6393, guest PC 0x0c044e96 */
if(!s->budget--) { s->failed_pc=0x0c044e96u; return 0; }
r[3]=r[9];
goto P_0c044e98;
P_0c044e98: /* original 4228, guest PC 0x0c044e98 */
if(!s->budget--) { s->failed_pc=0x0c044e98u; return 0; }
r[2]<<=16;
goto P_0c044e9a;
P_0c044e9a: /* original 6193, guest PC 0x0c044e9a */
if(!s->budget--) { s->failed_pc=0x0c044e9au; return 0; }
r[1]=r[9];
goto P_0c044e9c;
P_0c044e9c: /* original 4318, guest PC 0x0c044e9c */
if(!s->budget--) { s->failed_pc=0x0c044e9cu; return 0; }
r[3]<<=8;
goto P_0c044e9e;
P_0c044e9e: /* original 4218, guest PC 0x0c044e9e */
if(!s->budget--) { s->failed_pc=0x0c044e9eu; return 0; }
r[2]<<=8;
goto P_0c044ea0;
P_0c044ea0: /* original 2349, guest PC 0x0c044ea0 */
if(!s->budget--) { s->failed_pc=0x0c044ea0u; return 0; }
r[3]&=r[4];
goto P_0c044ea2;
P_0c044ea2: /* original 2269, guest PC 0x0c044ea2 */
if(!s->budget--) { s->failed_pc=0x0c044ea2u; return 0; }
r[2]&=r[6];
goto P_0c044ea4;
P_0c044ea4: /* original 223b, guest PC 0x0c044ea4 */
if(!s->budget--) { s->failed_pc=0x0c044ea4u; return 0; }
r[2]|=r[3];
goto P_0c044ea6;
P_0c044ea6: /* original e3f8, guest PC 0x0c044ea6 */
if(!s->budget--) { s->failed_pc=0x0c044ea6u; return 0; }
r[3]=0xfffffff8u;
goto P_0c044ea8;
P_0c044ea8: /* original 413c, guest PC 0x0c044ea8 */
if(!s->budget--) { s->failed_pc=0x0c044ea8u; return 0; }
r[1]=(r[3]&0x80000000u)?((r[3]&31u)?(uint32_t)((int32_t)r[1]>>((-r[3])&31u)):((int32_t)r[1]<0?0xffffffffu:0)):r[1]<<(r[3]&31u);
goto P_0c044eaa;
P_0c044eaa: /* original 2159, guest PC 0x0c044eaa */
if(!s->budget--) { s->failed_pc=0x0c044eaau; return 0; }
r[1]&=r[5];
goto P_0c044eac;
P_0c044eac: /* original 221b, guest PC 0x0c044eac */
if(!s->budget--) { s->failed_pc=0x0c044eacu; return 0; }
r[2]|=r[1];
goto P_0c044eae;
P_0c044eae: /* original 6193, guest PC 0x0c044eae */
if(!s->budget--) { s->failed_pc=0x0c044eaeu; return 0; }
r[1]=r[9];
goto P_0c044eb0;
P_0c044eb0: /* original 4129, guest PC 0x0c044eb0 */
if(!s->budget--) { s->failed_pc=0x0c044eb0u; return 0; }
r[1]>>=16;
goto P_0c044eb2;
P_0c044eb2: /* original 4119, guest PC 0x0c044eb2 */
if(!s->budget--) { s->failed_pc=0x0c044eb2u; return 0; }
r[1]>>=8;
goto P_0c044eb4;
P_0c044eb4: /* original 611e, guest PC 0x0c044eb4 */
if(!s->budget--) { s->failed_pc=0x0c044eb4u; return 0; }
r[1]=(uint32_t)(int32_t)(int8_t)r[1];
goto P_0c044eb6;
P_0c044eb6: /* original 611c, guest PC 0x0c044eb6 */
if(!s->budget--) { s->failed_pc=0x0c044eb6u; return 0; }
r[1]=r[1]&255u;
goto P_0c044eb8;
P_0c044eb8: /* original 221b, guest PC 0x0c044eb8 */
if(!s->budget--) { s->failed_pc=0x0c044eb8u; return 0; }
r[2]|=r[1];
goto P_0c044eba;
P_0c044eba: /* original 2d22, guest PC 0x0c044eba */
if(!s->budget--) { s->failed_pc=0x0c044ebau; return 0; }
write(ram,r[13],r[2],4);
goto P_0c044ebc;
P_0c044ebc: /* original 8fe7, guest PC 0x0c044ebc */
if(!s->budget--) { s->failed_pc=0x0c044ebcu; return 0; }
cond=r[17]&1u;
r[13]+=0x00000004u;
if(!cond) { goto P_0c044e8e; }
goto P_0c044ec0;
P_0c044ebe: /* original 7d04, guest PC 0x0c044ebe */
if(!s->budget--) { s->failed_pc=0x0c044ebeu; return 0; }
r[13]+=0x00000004u;
goto P_0c044ec0;
P_0c044ec0: /* original 9179, guest PC 0x0c044ec0 */
if(!s->budget--) { s->failed_pc=0x0c044ec0u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c044fb6u,2);
goto P_0c044ec2;
P_0c044ec2: /* original 60e2, guest PC 0x0c044ec2 */
if(!s->budget--) { s->failed_pc=0x0c044ec2u; return 0; }
tmp=read(ram,r[14],4);
r[0]=tmp;
goto P_0c044ec4;
P_0c044ec4: /* original 001e, guest PC 0x0c044ec4 */
if(!s->budget--) { s->failed_pc=0x0c044ec4u; return 0; }
r[0]=read(ram,r[1]+r[0],4);
goto P_0c044ec6;
P_0c044ec6: /* original 8801, guest PC 0x0c044ec6 */
if(!s->budget--) { s->failed_pc=0x0c044ec6u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c044ec8;
P_0c044ec8: /* original 8b1c, guest PC 0x0c044ec8 */
if(!s->budget--) { s->failed_pc=0x0c044ec8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c044f04; }
goto P_0c044eca;
P_0c044eca: /* original e040, guest PC 0x0c044eca */
if(!s->budget--) { s->failed_pc=0x0c044ecau; return 0; }
r[0]=0x00000040u;
goto P_0c044ecc;
P_0c044ecc: /* original 4c15, guest PC 0x0c044ecc */
if(!s->budget--) { s->failed_pc=0x0c044eccu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[12]>0)!=0);
goto P_0c044ece;
P_0c044ece: /* original 07fe, guest PC 0x0c044ece */
if(!s->budget--) { s->failed_pc=0x0c044eceu; return 0; }
r[7]=read(ram,r[15]+r[0],4);
goto P_0c044ed0;
P_0c044ed0: /* original 8f23, guest PC 0x0c044ed0 */
if(!s->budget--) { s->failed_pc=0x0c044ed0u; return 0; }
cond=r[17]&1u;
r[11]=0x00000000u;
if(!cond) { goto P_0c044f1a; }
goto P_0c044ed4;
P_0c044ed2: /* original eb00, guest PC 0x0c044ed2 */
if(!s->budget--) { s->failed_pc=0x0c044ed2u; return 0; }
r[11]=0x00000000u;
goto P_0c044ed4;
P_0c044ed4: /* original 8471, guest PC 0x0c044ed4 */
if(!s->budget--) { s->failed_pc=0x0c044ed4u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[7]+1,1);
goto P_0c044ed6;
P_0c044ed6: /* original 7b01, guest PC 0x0c044ed6 */
if(!s->budget--) { s->failed_pc=0x0c044ed6u; return 0; }
r[11]+=0x00000001u;
goto P_0c044ed8;
P_0c044ed8: /* original 6170, guest PC 0x0c044ed8 */
if(!s->budget--) { s->failed_pc=0x0c044ed8u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[7],1);
r[1]=tmp;
goto P_0c044eda;
P_0c044eda: /* original 3bc3, guest PC 0x0c044eda */
if(!s->budget--) { s->failed_pc=0x0c044edau; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[11]>=(int32_t)r[12])!=0);
goto P_0c044edc;
P_0c044edc: /* original 4028, guest PC 0x0c044edc */
if(!s->budget--) { s->failed_pc=0x0c044edcu; return 0; }
r[0]<<=16;
goto P_0c044ede;
P_0c044ede: /* original 2049, guest PC 0x0c044ede */
if(!s->budget--) { s->failed_pc=0x0c044edeu; return 0; }
r[0]&=r[4];
goto P_0c044ee0;
P_0c044ee0: /* original 6303, guest PC 0x0c044ee0 */
if(!s->budget--) { s->failed_pc=0x0c044ee0u; return 0; }
r[3]=r[0];
goto P_0c044ee2;
P_0c044ee2: /* original 8472, guest PC 0x0c044ee2 */
if(!s->budget--) { s->failed_pc=0x0c044ee2u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[7]+2,1);
goto P_0c044ee4;
P_0c044ee4: /* original 4128, guest PC 0x0c044ee4 */
if(!s->budget--) { s->failed_pc=0x0c044ee4u; return 0; }
r[1]<<=16;
goto P_0c044ee6;
P_0c044ee6: /* original 4018, guest PC 0x0c044ee6 */
if(!s->budget--) { s->failed_pc=0x0c044ee6u; return 0; }
r[0]<<=8;
goto P_0c044ee8;
P_0c044ee8: /* original 2059, guest PC 0x0c044ee8 */
if(!s->budget--) { s->failed_pc=0x0c044ee8u; return 0; }
r[0]&=r[5];
goto P_0c044eea;
P_0c044eea: /* original 230b, guest PC 0x0c044eea */
if(!s->budget--) { s->failed_pc=0x0c044eeau; return 0; }
r[3]|=r[0];
goto P_0c044eec;
P_0c044eec: /* original 8473, guest PC 0x0c044eec */
if(!s->budget--) { s->failed_pc=0x0c044eecu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[7]+3,1);
goto P_0c044eee;
P_0c044eee: /* original 4118, guest PC 0x0c044eee */
if(!s->budget--) { s->failed_pc=0x0c044eeeu; return 0; }
r[1]<<=8;
goto P_0c044ef0;
P_0c044ef0: /* original 2169, guest PC 0x0c044ef0 */
if(!s->budget--) { s->failed_pc=0x0c044ef0u; return 0; }
r[1]&=r[6];
goto P_0c044ef2;
P_0c044ef2: /* original 600c, guest PC 0x0c044ef2 */
if(!s->budget--) { s->failed_pc=0x0c044ef2u; return 0; }
r[0]=r[0]&255u;
goto P_0c044ef4;
P_0c044ef4: /* original 231b, guest PC 0x0c044ef4 */
if(!s->budget--) { s->failed_pc=0x0c044ef4u; return 0; }
r[3]|=r[1];
goto P_0c044ef6;
P_0c044ef6: /* original 230b, guest PC 0x0c044ef6 */
if(!s->budget--) { s->failed_pc=0x0c044ef6u; return 0; }
r[3]|=r[0];
goto P_0c044ef8;
P_0c044ef8: /* original 2d32, guest PC 0x0c044ef8 */
if(!s->budget--) { s->failed_pc=0x0c044ef8u; return 0; }
write(ram,r[13],r[3],4);
goto P_0c044efa;
P_0c044efa: /* original 7d04, guest PC 0x0c044efa */
if(!s->budget--) { s->failed_pc=0x0c044efau; return 0; }
r[13]+=0x00000004u;
goto P_0c044efc;
P_0c044efc: /* original 8fea, guest PC 0x0c044efc */
if(!s->budget--) { s->failed_pc=0x0c044efcu; return 0; }
cond=r[17]&1u;
r[7]+=0x00000004u;
if(!cond) { goto P_0c044ed4; }
goto P_0c044f00;
P_0c044efe: /* original 7704, guest PC 0x0c044efe */
if(!s->budget--) { s->failed_pc=0x0c044efeu; return 0; }
r[7]+=0x00000004u;
goto P_0c044f00;
P_0c044f00: /* original a00b, guest PC 0x0c044f00 */
if(!s->budget--) { s->failed_pc=0x0c044f00u; return 0; }
goto P_0c044f1a;
P_0c044f02: /* original 0009, guest PC 0x0c044f02 */
if(!s->budget--) { s->failed_pc=0x0c044f02u; return 0; }
goto P_0c044f04;
P_0c044f04: /* original e040, guest PC 0x0c044f04 */
if(!s->budget--) { s->failed_pc=0x0c044f04u; return 0; }
r[0]=0x00000040u;
goto P_0c044f06;
P_0c044f06: /* original 4c15, guest PC 0x0c044f06 */
if(!s->budget--) { s->failed_pc=0x0c044f06u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[12]>0)!=0);
goto P_0c044f08;
P_0c044f08: /* original 05fe, guest PC 0x0c044f08 */
if(!s->budget--) { s->failed_pc=0x0c044f08u; return 0; }
r[5]=read(ram,r[15]+r[0],4);
goto P_0c044f0a;
P_0c044f0a: /* original 8f06, guest PC 0x0c044f0a */
if(!s->budget--) { s->failed_pc=0x0c044f0au; return 0; }
cond=r[17]&1u;
r[4]=0x00000000u;
if(!cond) { goto P_0c044f1a; }
goto P_0c044f0e;
P_0c044f0c: /* original e400, guest PC 0x0c044f0c */
if(!s->budget--) { s->failed_pc=0x0c044f0cu; return 0; }
r[4]=0x00000000u;
goto P_0c044f0e;
P_0c044f0e: /* original 6356, guest PC 0x0c044f0e */
if(!s->budget--) { s->failed_pc=0x0c044f0eu; return 0; }
tmp=read(ram,r[5],4);
r[5]+=4;
r[3]=tmp;
goto P_0c044f10;
P_0c044f10: /* original 7401, guest PC 0x0c044f10 */
if(!s->budget--) { s->failed_pc=0x0c044f10u; return 0; }
r[4]+=0x00000001u;
goto P_0c044f12;
P_0c044f12: /* original 34c3, guest PC 0x0c044f12 */
if(!s->budget--) { s->failed_pc=0x0c044f12u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[12])!=0);
goto P_0c044f14;
P_0c044f14: /* original 2d32, guest PC 0x0c044f14 */
if(!s->budget--) { s->failed_pc=0x0c044f14u; return 0; }
write(ram,r[13],r[3],4);
goto P_0c044f16;
P_0c044f16: /* original 8ffa, guest PC 0x0c044f16 */
if(!s->budget--) { s->failed_pc=0x0c044f16u; return 0; }
cond=r[17]&1u;
r[13]+=0x00000004u;
if(!cond) { goto P_0c044f0e; }
goto P_0c044f1a;
P_0c044f18: /* original 7d04, guest PC 0x0c044f18 */
if(!s->budget--) { s->failed_pc=0x0c044f18u; return 0; }
r[13]+=0x00000004u;
goto P_0c044f1a;
P_0c044f1a: /* original 904d, guest PC 0x0c044f1a */
if(!s->budget--) { s->failed_pc=0x0c044f1au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c044fb8u,2);
goto P_0c044f1c;
P_0c044f1c: /* original 52f2, guest PC 0x0c044f1c */
if(!s->budget--) { s->failed_pc=0x0c044f1cu; return 0; }
r[2]=read(ram,r[15]+8,4);
goto P_0c044f1e;
P_0c044f1e: /* original 63e2, guest PC 0x0c044f1e */
if(!s->budget--) { s->failed_pc=0x0c044f1eu; return 0; }
tmp=read(ram,r[14],4);
r[3]=tmp;
goto P_0c044f20;
P_0c044f20: /* original 0326, guest PC 0x0c044f20 */
if(!s->budget--) { s->failed_pc=0x0c044f20u; return 0; }
write(ram,r[3]+r[0],r[2],4);
goto P_0c044f22;
P_0c044f22: /* original 7004, guest PC 0x0c044f22 */
if(!s->budget--) { s->failed_pc=0x0c044f22u; return 0; }
r[0]+=0x00000004u;
goto P_0c044f24;
P_0c044f24: /* original 63e2, guest PC 0x0c044f24 */
if(!s->budget--) { s->failed_pc=0x0c044f24u; return 0; }
tmp=read(ram,r[14],4);
r[3]=tmp;
goto P_0c044f26;
P_0c044f26: /* original 52f2, guest PC 0x0c044f26 */
if(!s->budget--) { s->failed_pc=0x0c044f26u; return 0; }
r[2]=read(ram,r[15]+8,4);
goto P_0c044f28;
P_0c044f28: /* original 013e, guest PC 0x0c044f28 */
if(!s->budget--) { s->failed_pc=0x0c044f28u; return 0; }
r[1]=read(ram,r[3]+r[0],4);
goto P_0c044f2a;
P_0c044f2a: /* original 4208, guest PC 0x0c044f2a */
if(!s->budget--) { s->failed_pc=0x0c044f2au; return 0; }
r[2]<<=2;
goto P_0c044f2c;
P_0c044f2c: /* original 312c, guest PC 0x0c044f2c */
if(!s->budget--) { s->failed_pc=0x0c044f2cu; return 0; }
r[1]+=r[2];
goto P_0c044f2e;
P_0c044f2e: /* original 0316, guest PC 0x0c044f2e */
if(!s->budget--) { s->failed_pc=0x0c044f2eu; return 0; }
write(ram,r[3]+r[0],r[1],4);
goto P_0c044f30;
P_0c044f30: /* original 7004, guest PC 0x0c044f30 */
if(!s->budget--) { s->failed_pc=0x0c044f30u; return 0; }
r[0]+=0x00000004u;
goto P_0c044f32;
P_0c044f32: /* original 63e2, guest PC 0x0c044f32 */
if(!s->budget--) { s->failed_pc=0x0c044f32u; return 0; }
tmp=read(ram,r[14],4);
r[3]=tmp;
goto P_0c044f34;
P_0c044f34: /* original 62e2, guest PC 0x0c044f34 */
if(!s->budget--) { s->failed_pc=0x0c044f34u; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c044f36;
P_0c044f36: /* original 013e, guest PC 0x0c044f36 */
if(!s->budget--) { s->failed_pc=0x0c044f36u; return 0; }
r[1]=read(ram,r[3]+r[0],4);
goto P_0c044f38;
P_0c044f38: /* original 7228, guest PC 0x0c044f38 */
if(!s->budget--) { s->failed_pc=0x0c044f38u; return 0; }
r[2]+=0x00000028u;
goto P_0c044f3a;
P_0c044f3a: /* original 7101, guest PC 0x0c044f3a */
if(!s->budget--) { s->failed_pc=0x0c044f3au; return 0; }
r[1]+=0x00000001u;
goto P_0c044f3c;
P_0c044f3c: /* original 0316, guest PC 0x0c044f3c */
if(!s->budget--) { s->failed_pc=0x0c044f3cu; return 0; }
write(ram,r[3]+r[0],r[1],4);
goto P_0c044f3e;
P_0c044f3e: /* original 71ff, guest PC 0x0c044f3e */
if(!s->budget--) { s->failed_pc=0x0c044f3eu; return 0; }
r[1]+=0xffffffffu;
goto P_0c044f40;
P_0c044f40: /* original 32ac, guest PC 0x0c044f40 */
if(!s->budget--) { s->failed_pc=0x0c044f40u; return 0; }
r[2]+=r[10];
goto P_0c044f42;
P_0c044f42: /* original 1216, guest PC 0x0c044f42 */
if(!s->budget--) { s->failed_pc=0x0c044f42u; return 0; }
write(ram,r[2]+24,r[1],4);
goto P_0c044f44;
P_0c044f44: /* original 63e2, guest PC 0x0c044f44 */
if(!s->budget--) { s->failed_pc=0x0c044f44u; return 0; }
tmp=read(ram,r[14],4);
r[3]=tmp;
goto P_0c044f46;
P_0c044f46: /* original d21e, guest PC 0x0c044f46 */
if(!s->budget--) { s->failed_pc=0x0c044f46u; return 0; }
r[2]=read(ram,0x0c044fc0u,4);
goto P_0c044f48;
P_0c044f48: /* original 013e, guest PC 0x0c044f48 */
if(!s->budget--) { s->failed_pc=0x0c044f48u; return 0; }
r[1]=read(ram,r[3]+r[0],4);
goto P_0c044f4a;
P_0c044f4a: /* original 2129, guest PC 0x0c044f4a */
if(!s->budget--) { s->failed_pc=0x0c044f4au; return 0; }
r[1]&=r[2];
goto P_0c044f4c;
P_0c044f4c: /* original 0316, guest PC 0x0c044f4c */
if(!s->budget--) { s->failed_pc=0x0c044f4cu; return 0; }
write(ram,r[3]+r[0],r[1],4);
goto P_0c044f4e;
P_0c044f4e: /* original 63e2, guest PC 0x0c044f4e */
if(!s->budget--) { s->failed_pc=0x0c044f4eu; return 0; }
tmp=read(ram,r[14],4);
r[3]=tmp;
goto P_0c044f50;
P_0c044f50: /* original 013e, guest PC 0x0c044f50 */
if(!s->budget--) { s->failed_pc=0x0c044f50u; return 0; }
r[1]=read(ram,r[3]+r[0],4);
goto P_0c044f52;
P_0c044f52: /* original 2118, guest PC 0x0c044f52 */
if(!s->budget--) { s->failed_pc=0x0c044f52u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[1])==0)!=0);
goto P_0c044f54;
P_0c044f54: /* original 8b03, guest PC 0x0c044f54 */
if(!s->budget--) { s->failed_pc=0x0c044f54u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c044f5e; }
goto P_0c044f56;
P_0c044f56: /* original 9030, guest PC 0x0c044f56 */
if(!s->budget--) { s->failed_pc=0x0c044f56u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c044fbau,2);
goto P_0c044f58;
P_0c044f58: /* original e301, guest PC 0x0c044f58 */
if(!s->budget--) { s->failed_pc=0x0c044f58u; return 0; }
r[3]=0x00000001u;
goto P_0c044f5a;
P_0c044f5a: /* original 61e2, guest PC 0x0c044f5a */
if(!s->budget--) { s->failed_pc=0x0c044f5au; return 0; }
tmp=read(ram,r[14],4);
r[1]=tmp;
goto P_0c044f5c;
P_0c044f5c: /* original 0136, guest PC 0x0c044f5c */
if(!s->budget--) { s->failed_pc=0x0c044f5cu; return 0; }
write(ram,r[1]+r[0],r[3],4);
goto P_0c044f5e;
P_0c044f5e: /* original 60e2, guest PC 0x0c044f5e */
if(!s->budget--) { s->failed_pc=0x0c044f5eu; return 0; }
tmp=read(ram,r[14],4);
r[0]=tmp;
goto P_0c044f60;
P_0c044f60: /* original 7028, guest PC 0x0c044f60 */
if(!s->budget--) { s->failed_pc=0x0c044f60u; return 0; }
r[0]+=0x00000028u;
goto P_0c044f62;
P_0c044f62: /* original 30ac, guest PC 0x0c044f62 */
if(!s->budget--) { s->failed_pc=0x0c044f62u; return 0; }
r[0]+=r[10];
goto P_0c044f64;
P_0c044f64: /* original 5006, guest PC 0x0c044f64 */
if(!s->budget--) { s->failed_pc=0x0c044f64u; return 0; }
r[0]=read(ram,r[0]+24,4);
goto P_0c044f66;
P_0c044f66: /* original 7f1c, guest PC 0x0c044f66 */
if(!s->budget--) { s->failed_pc=0x0c044f66u; return 0; }
r[15]+=0x0000001cu;
goto P_0c044f68;
P_0c044f68: /* original 4f16, guest PC 0x0c044f68 */
if(!s->budget--) { s->failed_pc=0x0c044f68u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c044f6a;
P_0c044f6a: /* original 4f26, guest PC 0x0c044f6a */
if(!s->budget--) { s->failed_pc=0x0c044f6au; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c044f6c;
P_0c044f6c: /* original 68f6, guest PC 0x0c044f6c */
if(!s->budget--) { s->failed_pc=0x0c044f6cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c044f6e;
P_0c044f6e: /* original 69f6, guest PC 0x0c044f6e */
if(!s->budget--) { s->failed_pc=0x0c044f6eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c044f70;
P_0c044f70: /* original 6af6, guest PC 0x0c044f70 */
if(!s->budget--) { s->failed_pc=0x0c044f70u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c044f72;
P_0c044f72: /* original 6bf6, guest PC 0x0c044f72 */
if(!s->budget--) { s->failed_pc=0x0c044f72u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c044f74;
P_0c044f74: /* original 6cf6, guest PC 0x0c044f74 */
if(!s->budget--) { s->failed_pc=0x0c044f74u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c044f76;
P_0c044f76: /* original 6df6, guest PC 0x0c044f76 */
if(!s->budget--) { s->failed_pc=0x0c044f76u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c044f78;
P_0c044f78: /* original 000b, guest PC 0x0c044f78 */
if(!s->budget--) { s->failed_pc=0x0c044f78u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c044f7a: /* original 6ef6, guest PC 0x0c044f7a */
if(!s->budget--) { s->failed_pc=0x0c044f7au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c044f7cu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c044f7cu; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
