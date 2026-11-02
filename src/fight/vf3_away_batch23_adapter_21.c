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
int vf3_away_batch23_adapter_21(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c0b7d9eu: goto P_0c0b7d9e;
case 0x0c0b7da0u: goto P_0c0b7da0;
case 0x0c0b7da2u: goto P_0c0b7da2;
case 0x0c0b7da4u: goto P_0c0b7da4;
case 0x0c0b7da6u: goto P_0c0b7da6;
case 0x0c0b7da8u: goto P_0c0b7da8;
case 0x0c0b7daau: goto P_0c0b7daa;
case 0x0c0b7dacu: goto P_0c0b7dac;
case 0x0c0b7daeu: goto P_0c0b7dae;
case 0x0c0b7db0u: goto P_0c0b7db0;
case 0x0c0b7db2u: goto P_0c0b7db2;
case 0x0c0b7db4u: goto P_0c0b7db4;
case 0x0c0b7db6u: goto P_0c0b7db6;
case 0x0c0b7db8u: goto P_0c0b7db8;
case 0x0c0b7dbau: goto P_0c0b7dba;
case 0x0c0b7dbcu: goto P_0c0b7dbc;
case 0x0c0b7dbeu: goto P_0c0b7dbe;
case 0x0c0b7dc0u: goto P_0c0b7dc0;
case 0x0c0b7dc2u: goto P_0c0b7dc2;
case 0x0c0b7dc4u: goto P_0c0b7dc4;
case 0x0c0b7dc6u: goto P_0c0b7dc6;
case 0x0c0b7dc8u: goto P_0c0b7dc8;
case 0x0c0b7dcau: goto P_0c0b7dca;
case 0x0c0b7dccu: goto P_0c0b7dcc;
case 0x0c0b7dceu: goto P_0c0b7dce;
case 0x0c0b7dd0u: goto P_0c0b7dd0;
case 0x0c0b7dd2u: goto P_0c0b7dd2;
case 0x0c0b7dd4u: goto P_0c0b7dd4;
case 0x0c0b7dd6u: goto P_0c0b7dd6;
case 0x0c0b7dd8u: goto P_0c0b7dd8;
case 0x0c0b7ddau: goto P_0c0b7dda;
case 0x0c0b7ddcu: goto P_0c0b7ddc;
case 0x0c0b7ddeu: goto P_0c0b7dde;
case 0x0c0b7de0u: goto P_0c0b7de0;
case 0x0c0b7de2u: goto P_0c0b7de2;
case 0x0c0b7de4u: goto P_0c0b7de4;
case 0x0c0b7de6u: goto P_0c0b7de6;
case 0x0c0b7de8u: goto P_0c0b7de8;
case 0x0c0b7deau: goto P_0c0b7dea;
case 0x0c0b7decu: goto P_0c0b7dec;
case 0x0c0b7deeu: goto P_0c0b7dee;
case 0x0c0b7df0u: goto P_0c0b7df0;
case 0x0c0b7df2u: goto P_0c0b7df2;
case 0x0c0b7df4u: goto P_0c0b7df4;
case 0x0c0b7df6u: goto P_0c0b7df6;
case 0x0c0b7df8u: goto P_0c0b7df8;
case 0x0c0b7dfau: goto P_0c0b7dfa;
case 0x0c0b7dfcu: goto P_0c0b7dfc;
case 0x0c0b7dfeu: goto P_0c0b7dfe;
case 0x0c0b7e00u: goto P_0c0b7e00;
case 0x0c0b7e02u: goto P_0c0b7e02;
case 0x0c0b7e04u: goto P_0c0b7e04;
case 0x0c0b7e06u: goto P_0c0b7e06;
case 0x0c0b7e08u: goto P_0c0b7e08;
case 0x0c0b7e0au: goto P_0c0b7e0a;
case 0x0c0b7e0cu: goto P_0c0b7e0c;
case 0x0c0b7e0eu: goto P_0c0b7e0e;
case 0x0c0b7e10u: goto P_0c0b7e10;
case 0x0c0b7e12u: goto P_0c0b7e12;
case 0x0c0b7e14u: goto P_0c0b7e14;
case 0x0c0b7e16u: goto P_0c0b7e16;
case 0x0c0b7e18u: goto P_0c0b7e18;
case 0x0c0b7e1au: goto P_0c0b7e1a;
case 0x0c0b7e1cu: goto P_0c0b7e1c;
case 0x0c0b7e1eu: goto P_0c0b7e1e;
case 0x0c0b7e20u: goto P_0c0b7e20;
case 0x0c0b7e22u: goto P_0c0b7e22;
case 0x0c0b7e24u: goto P_0c0b7e24;
case 0x0c0b7e26u: goto P_0c0b7e26;
case 0x0c0b7e28u: goto P_0c0b7e28;
case 0x0c0b7e2au: goto P_0c0b7e2a;
case 0x0c0b7e2cu: goto P_0c0b7e2c;
case 0x0c0b7e2eu: goto P_0c0b7e2e;
case 0x0c0b7e30u: goto P_0c0b7e30;
case 0x0c0b7e32u: goto P_0c0b7e32;
case 0x0c0b7e34u: goto P_0c0b7e34;
case 0x0c0b7e36u: goto P_0c0b7e36;
case 0x0c0b7e38u: goto P_0c0b7e38;
case 0x0c0b7e3au: goto P_0c0b7e3a;
case 0x0c0b7e3cu: goto P_0c0b7e3c;
case 0x0c0b7e3eu: goto P_0c0b7e3e;
case 0x0c0b7e40u: goto P_0c0b7e40;
case 0x0c0b7e42u: goto P_0c0b7e42;
case 0x0c0b7e44u: goto P_0c0b7e44;
case 0x0c0b7e46u: goto P_0c0b7e46;
case 0x0c0b7e48u: goto P_0c0b7e48;
case 0x0c0b7e4au: goto P_0c0b7e4a;
case 0x0c0b7e4cu: goto P_0c0b7e4c;
case 0x0c0b7e4eu: goto P_0c0b7e4e;
case 0x0c0b7e50u: goto P_0c0b7e50;
case 0x0c0b7e52u: goto P_0c0b7e52;
case 0x0c0b7e54u: goto P_0c0b7e54;
case 0x0c0b7e56u: goto P_0c0b7e56;
case 0x0c0b7e58u: goto P_0c0b7e58;
case 0x0c0b7e5au: goto P_0c0b7e5a;
case 0x0c0b7e5cu: goto P_0c0b7e5c;
case 0x0c0b7e5eu: goto P_0c0b7e5e;
case 0x0c0b7e60u: goto P_0c0b7e60;
case 0x0c0b7e62u: goto P_0c0b7e62;
case 0x0c0b7e64u: goto P_0c0b7e64;
case 0x0c0b7e66u: goto P_0c0b7e66;
case 0x0c0b7e68u: goto P_0c0b7e68;
case 0x0c0b7e6au: goto P_0c0b7e6a;
case 0x0c0b7e6cu: goto P_0c0b7e6c;
case 0x0c0b7e6eu: goto P_0c0b7e6e;
case 0x0c0b7e70u: goto P_0c0b7e70;
case 0x0c0b7e72u: goto P_0c0b7e72;
case 0x0c0b7e74u: goto P_0c0b7e74;
case 0x0c0b7e76u: goto P_0c0b7e76;
case 0x0c0b7e78u: goto P_0c0b7e78;
case 0x0c0b7e7au: goto P_0c0b7e7a;
case 0x0c0b7e7cu: goto P_0c0b7e7c;
case 0x0c0b7e7eu: goto P_0c0b7e7e;
case 0x0c0b7e80u: goto P_0c0b7e80;
case 0x0c0b7e82u: goto P_0c0b7e82;
case 0x0c0b7e84u: goto P_0c0b7e84;
case 0x0c0b7e86u: goto P_0c0b7e86;
case 0x0c0b7e88u: goto P_0c0b7e88;
case 0x0c0b7e8au: goto P_0c0b7e8a;
case 0x0c0b7e8cu: goto P_0c0b7e8c;
case 0x0c0b7e8eu: goto P_0c0b7e8e;
case 0x0c0b7e90u: goto P_0c0b7e90;
case 0x0c0b7e92u: goto P_0c0b7e92;
case 0x0c0b7e94u: goto P_0c0b7e94;
case 0x0c0b7e96u: goto P_0c0b7e96;
case 0x0c0b7e98u: goto P_0c0b7e98;
case 0x0c0b7e9au: goto P_0c0b7e9a;
case 0x0c0b7e9cu: goto P_0c0b7e9c;
case 0x0c0b7e9eu: goto P_0c0b7e9e;
case 0x0c0b7ea0u: goto P_0c0b7ea0;
case 0x0c0b7ea2u: goto P_0c0b7ea2;
case 0x0c0b7ea4u: goto P_0c0b7ea4;
case 0x0c0b7ea6u: goto P_0c0b7ea6;
case 0x0c0b7ea8u: goto P_0c0b7ea8;
case 0x0c0b7eaau: goto P_0c0b7eaa;
case 0x0c0b7eacu: goto P_0c0b7eac;
case 0x0c0b7eaeu: goto P_0c0b7eae;
case 0x0c0b7eb0u: goto P_0c0b7eb0;
case 0x0c0b7eb2u: goto P_0c0b7eb2;
case 0x0c0b7eb4u: goto P_0c0b7eb4;
case 0x0c0b7eb6u: goto P_0c0b7eb6;
case 0x0c0b7eb8u: goto P_0c0b7eb8;
case 0x0c0b7ebau: goto P_0c0b7eba;
case 0x0c0b7ebcu: goto P_0c0b7ebc;
case 0x0c0b7ebeu: goto P_0c0b7ebe;
case 0x0c0b7ec0u: goto P_0c0b7ec0;
case 0x0c0b7ec2u: goto P_0c0b7ec2;
case 0x0c0b7ec4u: goto P_0c0b7ec4;
case 0x0c0b7ec6u: goto P_0c0b7ec6;
case 0x0c0b7ec8u: goto P_0c0b7ec8;
case 0x0c0b7ecau: goto P_0c0b7eca;
case 0x0c0b7eccu: goto P_0c0b7ecc;
case 0x0c0b7eceu: goto P_0c0b7ece;
case 0x0c0b7ed0u: goto P_0c0b7ed0;
case 0x0c0b7ed2u: goto P_0c0b7ed2;
case 0x0c0b7ed4u: goto P_0c0b7ed4;
case 0x0c0b7ed6u: goto P_0c0b7ed6;
case 0x0c0b7ed8u: goto P_0c0b7ed8;
case 0x0c0b7edau: goto P_0c0b7eda;
case 0x0c0b7edcu: goto P_0c0b7edc;
case 0x0c0b7edeu: goto P_0c0b7ede;
case 0x0c0b7ee0u: goto P_0c0b7ee0;
case 0x0c0b7ee2u: goto P_0c0b7ee2;
case 0x0c0b7ee4u: goto P_0c0b7ee4;
case 0x0c0b7ee6u: goto P_0c0b7ee6;
case 0x0c0b7ee8u: goto P_0c0b7ee8;
case 0x0c0b7eeau: goto P_0c0b7eea;
case 0x0c0b7eecu: goto P_0c0b7eec;
case 0x0c0b7eeeu: goto P_0c0b7eee;
case 0x0c0b7ef0u: goto P_0c0b7ef0;
case 0x0c0b7ef2u: goto P_0c0b7ef2;
case 0x0c0b7ef4u: goto P_0c0b7ef4;
case 0x0c0b7ef6u: goto P_0c0b7ef6;
case 0x0c0b7ef8u: goto P_0c0b7ef8;
case 0x0c0b7efau: goto P_0c0b7efa;
case 0x0c0b7efcu: goto P_0c0b7efc;
case 0x0c0b7efeu: goto P_0c0b7efe;
case 0x0c0b7f00u: goto P_0c0b7f00;
case 0x0c0b7f70u: goto P_0c0b7f70;
case 0x0c0b7f72u: goto P_0c0b7f72;
case 0x0c0b7f74u: goto P_0c0b7f74;
case 0x0c0b7f76u: goto P_0c0b7f76;
case 0x0c0b7f78u: goto P_0c0b7f78;
case 0x0c0b7f7au: goto P_0c0b7f7a;
case 0x0c0b7f7cu: goto P_0c0b7f7c;
case 0x0c0b7f7eu: goto P_0c0b7f7e;
case 0x0c0b7f80u: goto P_0c0b7f80;
case 0x0c0b7f82u: goto P_0c0b7f82;
case 0x0c0b7f84u: goto P_0c0b7f84;
case 0x0c0b7f86u: goto P_0c0b7f86;
case 0x0c0b7f88u: goto P_0c0b7f88;
case 0x0c0b7f8au: goto P_0c0b7f8a;
case 0x0c0b7f8cu: goto P_0c0b7f8c;
case 0x0c0b7f8eu: goto P_0c0b7f8e;
case 0x0c0b7f90u: goto P_0c0b7f90;
case 0x0c0b7f92u: goto P_0c0b7f92;
case 0x0c0b7f94u: goto P_0c0b7f94;
case 0x0c0b7f96u: goto P_0c0b7f96;
case 0x0c0b7f98u: goto P_0c0b7f98;
case 0x0c0b7f9au: goto P_0c0b7f9a;
case 0x0c0b7f9cu: goto P_0c0b7f9c;
case 0x0c0b7f9eu: goto P_0c0b7f9e;
case 0x0c0b7fa0u: goto P_0c0b7fa0;
case 0x0c0b7fa2u: goto P_0c0b7fa2;
case 0x0c0b7fa4u: goto P_0c0b7fa4;
case 0x0c0b7fa6u: goto P_0c0b7fa6;
case 0x0c0b7fa8u: goto P_0c0b7fa8;
case 0x0c0b7faau: goto P_0c0b7faa;
case 0x0c0b7facu: goto P_0c0b7fac;
case 0x0c0b7faeu: goto P_0c0b7fae;
case 0x0c0b7fb0u: goto P_0c0b7fb0;
case 0x0c0b7fb2u: goto P_0c0b7fb2;
case 0x0c0b7fb4u: goto P_0c0b7fb4;
case 0x0c0b7fb6u: goto P_0c0b7fb6;
case 0x0c0b7fb8u: goto P_0c0b7fb8;
case 0x0c0b7fbau: goto P_0c0b7fba;
case 0x0c0b7fbcu: goto P_0c0b7fbc;
case 0x0c0b7fbeu: goto P_0c0b7fbe;
case 0x0c0b7fc0u: goto P_0c0b7fc0;
case 0x0c0b7fc2u: goto P_0c0b7fc2;
case 0x0c0b7fc4u: goto P_0c0b7fc4;
case 0x0c0b7fc6u: goto P_0c0b7fc6;
case 0x0c0b7fc8u: goto P_0c0b7fc8;
case 0x0c0b7fcau: goto P_0c0b7fca;
case 0x0c0b7fccu: goto P_0c0b7fcc;
case 0x0c0b7fceu: goto P_0c0b7fce;
case 0x0c0b7fd0u: goto P_0c0b7fd0;
case 0x0c0b7fd2u: goto P_0c0b7fd2;
case 0x0c0b7fd4u: goto P_0c0b7fd4;
case 0x0c0b7fd6u: goto P_0c0b7fd6;
case 0x0c0b7fd8u: goto P_0c0b7fd8;
case 0x0c0b7fdau: goto P_0c0b7fda;
case 0x0c0b7fdcu: goto P_0c0b7fdc;
case 0x0c0b7fdeu: goto P_0c0b7fde;
case 0x0c0b7fe0u: goto P_0c0b7fe0;
case 0x0c0b7fe2u: goto P_0c0b7fe2;
case 0x0c0b7fe4u: goto P_0c0b7fe4;
case 0x0c0b7fe6u: goto P_0c0b7fe6;
case 0x0c0b7fe8u: goto P_0c0b7fe8;
case 0x0c0b7feau: goto P_0c0b7fea;
case 0x0c0b7fecu: goto P_0c0b7fec;
case 0x0c0b7feeu: goto P_0c0b7fee;
case 0x0c0b7ff0u: goto P_0c0b7ff0;
case 0x0c0b7ff2u: goto P_0c0b7ff2;
case 0x0c0b7ff4u: goto P_0c0b7ff4;
case 0x0c0b7ff6u: goto P_0c0b7ff6;
case 0x0c0b7ff8u: goto P_0c0b7ff8;
case 0x0c0b7ffau: goto P_0c0b7ffa;
case 0x0c0b7ffcu: goto P_0c0b7ffc;
case 0x0c0b7ffeu: goto P_0c0b7ffe;
case 0x0c0b8000u: goto P_0c0b8000;
case 0x0c0b8002u: goto P_0c0b8002;
case 0x0c0b8004u: goto P_0c0b8004;
case 0x0c0b8006u: goto P_0c0b8006;
case 0x0c0b8008u: goto P_0c0b8008;
case 0x0c0b800au: goto P_0c0b800a;
case 0x0c0b800cu: goto P_0c0b800c;
case 0x0c0b800eu: goto P_0c0b800e;
case 0x0c0b8010u: goto P_0c0b8010;
case 0x0c0b8012u: goto P_0c0b8012;
case 0x0c0b8014u: goto P_0c0b8014;
case 0x0c0b8016u: goto P_0c0b8016;
case 0x0c0b8018u: goto P_0c0b8018;
case 0x0c0b801au: goto P_0c0b801a;
case 0x0c0b801cu: goto P_0c0b801c;
case 0x0c0b801eu: goto P_0c0b801e;
case 0x0c0b8020u: goto P_0c0b8020;
case 0x0c0b8022u: goto P_0c0b8022;
case 0x0c0b8024u: goto P_0c0b8024;
case 0x0c0b8026u: goto P_0c0b8026;
case 0x0c0b8028u: goto P_0c0b8028;
case 0x0c0b802au: goto P_0c0b802a;
case 0x0c0b802cu: goto P_0c0b802c;
case 0x0c0b802eu: goto P_0c0b802e;
case 0x0c0b8030u: goto P_0c0b8030;
case 0x0c0b8032u: goto P_0c0b8032;
case 0x0c0b8034u: goto P_0c0b8034;
case 0x0c0b8036u: goto P_0c0b8036;
case 0x0c0b8038u: goto P_0c0b8038;
case 0x0c0b803au: goto P_0c0b803a;
case 0x0c0b803cu: goto P_0c0b803c;
case 0x0c0b803eu: goto P_0c0b803e;
case 0x0c0b8040u: goto P_0c0b8040;
case 0x0c0b8042u: goto P_0c0b8042;
case 0x0c0b8044u: goto P_0c0b8044;
case 0x0c0b8046u: goto P_0c0b8046;
case 0x0c0b8048u: goto P_0c0b8048;
case 0x0c0b804au: goto P_0c0b804a;
case 0x0c0b804cu: goto P_0c0b804c;
case 0x0c0b804eu: goto P_0c0b804e;
case 0x0c0b8050u: goto P_0c0b8050;
case 0x0c0b8052u: goto P_0c0b8052;
case 0x0c0b8054u: goto P_0c0b8054;
case 0x0c0b8056u: goto P_0c0b8056;
case 0x0c0b8058u: goto P_0c0b8058;
case 0x0c0b805au: goto P_0c0b805a;
case 0x0c0b805cu: goto P_0c0b805c;
case 0x0c0b805eu: goto P_0c0b805e;
case 0x0c0b8060u: goto P_0c0b8060;
case 0x0c0b8062u: goto P_0c0b8062;
case 0x0c0b8064u: goto P_0c0b8064;
case 0x0c0b8066u: goto P_0c0b8066;
case 0x0c0b8068u: goto P_0c0b8068;
case 0x0c0b806au: goto P_0c0b806a;
case 0x0c0b806cu: goto P_0c0b806c;
case 0x0c0b806eu: goto P_0c0b806e;
case 0x0c0b8070u: goto P_0c0b8070;
case 0x0c0b8072u: goto P_0c0b8072;
case 0x0c0b8074u: goto P_0c0b8074;
case 0x0c0b8076u: goto P_0c0b8076;
case 0x0c0b8078u: goto P_0c0b8078;
case 0x0c0b807au: goto P_0c0b807a;
case 0x0c0b807cu: goto P_0c0b807c;
case 0x0c0b807eu: goto P_0c0b807e;
case 0x0c0b8080u: goto P_0c0b8080;
case 0x0c0b8082u: goto P_0c0b8082;
case 0x0c0b8084u: goto P_0c0b8084;
case 0x0c0b8086u: goto P_0c0b8086;
case 0x0c0b8088u: goto P_0c0b8088;
case 0x0c0b808au: goto P_0c0b808a;
case 0x0c0b808cu: goto P_0c0b808c;
case 0x0c0b808eu: goto P_0c0b808e;
case 0x0c0b8090u: goto P_0c0b8090;
case 0x0c0b8092u: goto P_0c0b8092;
case 0x0c0b8094u: goto P_0c0b8094;
case 0x0c0b8096u: goto P_0c0b8096;
case 0x0c0b8098u: goto P_0c0b8098;
case 0x0c0b809au: goto P_0c0b809a;
case 0x0c0b809cu: goto P_0c0b809c;
case 0x0c0b809eu: goto P_0c0b809e;
case 0x0c0b80a0u: goto P_0c0b80a0;
case 0x0c0b80a2u: goto P_0c0b80a2;
case 0x0c0b80a4u: goto P_0c0b80a4;
case 0x0c0b80a6u: goto P_0c0b80a6;
case 0x0c0b80a8u: goto P_0c0b80a8;
case 0x0c0b80aau: goto P_0c0b80aa;
case 0x0c0b80acu: goto P_0c0b80ac;
case 0x0c0b80aeu: goto P_0c0b80ae;
case 0x0c0b80b0u: goto P_0c0b80b0;
case 0x0c0b80b2u: goto P_0c0b80b2;
case 0x0c0b80b4u: goto P_0c0b80b4;
case 0x0c0b80b6u: goto P_0c0b80b6;
case 0x0c0b80b8u: goto P_0c0b80b8;
case 0x0c0b80bau: goto P_0c0b80ba;
case 0x0c0b80bcu: goto P_0c0b80bc;
case 0x0c0b80beu: goto P_0c0b80be;
case 0x0c0b80c0u: goto P_0c0b80c0;
case 0x0c0b80c2u: goto P_0c0b80c2;
case 0x0c0b80c4u: goto P_0c0b80c4;
case 0x0c0b80c6u: goto P_0c0b80c6;
case 0x0c0b80c8u: goto P_0c0b80c8;
case 0x0c0b8142u: goto P_0c0b8142;
case 0x0c0b8144u: goto P_0c0b8144;
case 0x0c0b8146u: goto P_0c0b8146;
case 0x0c0b8148u: goto P_0c0b8148;
case 0x0c0b814au: goto P_0c0b814a;
case 0x0c0b814cu: goto P_0c0b814c;
case 0x0c0b814eu: goto P_0c0b814e;
case 0x0c0b8150u: goto P_0c0b8150;
case 0x0c0b8152u: goto P_0c0b8152;
case 0x0c0b8154u: goto P_0c0b8154;
case 0x0c0b8156u: goto P_0c0b8156;
case 0x0c0b8158u: goto P_0c0b8158;
case 0x0c0b815au: goto P_0c0b815a;
case 0x0c0b815cu: goto P_0c0b815c;
case 0x0c0b815eu: goto P_0c0b815e;
case 0x0c0b8160u: goto P_0c0b8160;
case 0x0c0b8162u: goto P_0c0b8162;
case 0x0c0b8164u: goto P_0c0b8164;
case 0x0c0b8166u: goto P_0c0b8166;
case 0x0c0b8168u: goto P_0c0b8168;
case 0x0c0b816au: goto P_0c0b816a;
case 0x0c0b816cu: goto P_0c0b816c;
case 0x0c0b816eu: goto P_0c0b816e;
case 0x0c0b8170u: goto P_0c0b8170;
case 0x0c0b8172u: goto P_0c0b8172;
case 0x0c0b8174u: goto P_0c0b8174;
case 0x0c0b8176u: goto P_0c0b8176;
case 0x0c0b8178u: goto P_0c0b8178;
case 0x0c0b817au: goto P_0c0b817a;
case 0x0c0b817cu: goto P_0c0b817c;
case 0x0c0b817eu: goto P_0c0b817e;
case 0x0c0b8180u: goto P_0c0b8180;
case 0x0c0b8182u: goto P_0c0b8182;
case 0x0c0b8184u: goto P_0c0b8184;
case 0x0c0b8186u: goto P_0c0b8186;
case 0x0c0b8188u: goto P_0c0b8188;
case 0x0c0b818au: goto P_0c0b818a;
case 0x0c0b818cu: goto P_0c0b818c;
case 0x0c0b818eu: goto P_0c0b818e;
case 0x0c0b8190u: goto P_0c0b8190;
case 0x0c0b8192u: goto P_0c0b8192;
case 0x0c0b8194u: goto P_0c0b8194;
case 0x0c0b8196u: goto P_0c0b8196;
case 0x0c0b8198u: goto P_0c0b8198;
case 0x0c0b819au: goto P_0c0b819a;
case 0x0c0b819cu: goto P_0c0b819c;
case 0x0c0b819eu: goto P_0c0b819e;
case 0x0c0b81a0u: goto P_0c0b81a0;
default: return vf3_matrix_family(target,s,ram);
}
P_0c0b7d9e: /* original 2fe6, guest PC 0x0c0b7d9e */
if(!s->budget--) { s->failed_pc=0x0c0b7d9eu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0b7da0;
P_0c0b7da0: /* original 2fd6, guest PC 0x0c0b7da0 */
if(!s->budget--) { s->failed_pc=0x0c0b7da0u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0b7da2;
P_0c0b7da2: /* original 2fc6, guest PC 0x0c0b7da2 */
if(!s->budget--) { s->failed_pc=0x0c0b7da2u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0b7da4;
P_0c0b7da4: /* original 2fb6, guest PC 0x0c0b7da4 */
if(!s->budget--) { s->failed_pc=0x0c0b7da4u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0b7da6;
P_0c0b7da6: /* original 2fa6, guest PC 0x0c0b7da6 */
if(!s->budget--) { s->failed_pc=0x0c0b7da6u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0b7da8;
P_0c0b7da8: /* original 2f96, guest PC 0x0c0b7da8 */
if(!s->budget--) { s->failed_pc=0x0c0b7da8u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0b7daa;
P_0c0b7daa: /* original 4f22, guest PC 0x0c0b7daa */
if(!s->budget--) { s->failed_pc=0x0c0b7daau; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0b7dac;
P_0c0b7dac: /* original 5d44, guest PC 0x0c0b7dac */
if(!s->budget--) { s->failed_pc=0x0c0b7dacu; return 0; }
r[13]=read(ram,r[4]+16,4);
goto P_0c0b7dae;
P_0c0b7dae: /* original 94a8, guest PC 0x0c0b7dae */
if(!s->budget--) { s->failed_pc=0x0c0b7daeu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b7f02u,2);
goto P_0c0b7db0;
P_0c0b7db0: /* original de6e, guest PC 0x0c0b7db0 */
if(!s->budget--) { s->failed_pc=0x0c0b7db0u; return 0; }
r[14]=read(ram,0x0c0b7f6cu,4);
goto P_0c0b7db2;
P_0c0b7db2: /* original 7ff8, guest PC 0x0c0b7db2 */
if(!s->budget--) { s->failed_pc=0x0c0b7db2u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c0b7db4;
P_0c0b7db4: /* original 4e0b, guest PC 0x0c0b7db4 */
if(!s->budget--) { s->failed_pc=0x0c0b7db4u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b7db8u;
tmp=read(ram,r[13],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b7db8u) { target=s->pc; goto dispatch; }
goto P_0c0b7db8;
P_0c0b7db6: /* original 65d2, guest PC 0x0c0b7db6 */
if(!s->budget--) { s->failed_pc=0x0c0b7db6u; return 0; }
tmp=read(ram,r[13],4);
r[5]=tmp;
goto P_0c0b7db8;
P_0c0b7db8: /* original 94a4, guest PC 0x0c0b7db8 */
if(!s->budget--) { s->failed_pc=0x0c0b7db8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b7f04u,2);
goto P_0c0b7dba;
P_0c0b7dba: /* original 4e0b, guest PC 0x0c0b7dba */
if(!s->budget--) { s->failed_pc=0x0c0b7dbau; return 0; }
target=r[14];
r[16]=code_base|0x0c0b7dbeu;
r[5]=read(ram,r[13]+4,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b7dbeu) { target=s->pc; goto dispatch; }
goto P_0c0b7dbe;
P_0c0b7dbc: /* original 55d1, guest PC 0x0c0b7dbc */
if(!s->budget--) { s->failed_pc=0x0c0b7dbcu; return 0; }
r[5]=read(ram,r[13]+4,4);
goto P_0c0b7dbe;
P_0c0b7dbe: /* original 94a2, guest PC 0x0c0b7dbe */
if(!s->budget--) { s->failed_pc=0x0c0b7dbeu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b7f06u,2);
goto P_0c0b7dc0;
P_0c0b7dc0: /* original 4e0b, guest PC 0x0c0b7dc0 */
if(!s->budget--) { s->failed_pc=0x0c0b7dc0u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b7dc4u;
r[5]=read(ram,r[13]+8,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b7dc4u) { target=s->pc; goto dispatch; }
goto P_0c0b7dc4;
P_0c0b7dc2: /* original 55d2, guest PC 0x0c0b7dc2 */
if(!s->budget--) { s->failed_pc=0x0c0b7dc2u; return 0; }
r[5]=read(ram,r[13]+8,4);
goto P_0c0b7dc4;
P_0c0b7dc4: /* original 94a0, guest PC 0x0c0b7dc4 */
if(!s->budget--) { s->failed_pc=0x0c0b7dc4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b7f08u,2);
goto P_0c0b7dc6;
P_0c0b7dc6: /* original 4e0b, guest PC 0x0c0b7dc6 */
if(!s->budget--) { s->failed_pc=0x0c0b7dc6u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b7dcau;
r[5]=read(ram,r[13]+12,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b7dcau) { target=s->pc; goto dispatch; }
goto P_0c0b7dca;
P_0c0b7dc8: /* original 55d3, guest PC 0x0c0b7dc8 */
if(!s->budget--) { s->failed_pc=0x0c0b7dc8u; return 0; }
r[5]=read(ram,r[13]+12,4);
goto P_0c0b7dca;
P_0c0b7dca: /* original 949e, guest PC 0x0c0b7dca */
if(!s->budget--) { s->failed_pc=0x0c0b7dcau; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b7f0au,2);
goto P_0c0b7dcc;
P_0c0b7dcc: /* original 4e0b, guest PC 0x0c0b7dcc */
if(!s->budget--) { s->failed_pc=0x0c0b7dccu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b7dd0u;
r[5]=read(ram,r[13]+16,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b7dd0u) { target=s->pc; goto dispatch; }
goto P_0c0b7dd0;
P_0c0b7dce: /* original 55d4, guest PC 0x0c0b7dce */
if(!s->budget--) { s->failed_pc=0x0c0b7dceu; return 0; }
r[5]=read(ram,r[13]+16,4);
goto P_0c0b7dd0;
P_0c0b7dd0: /* original 949c, guest PC 0x0c0b7dd0 */
if(!s->budget--) { s->failed_pc=0x0c0b7dd0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b7f0cu,2);
goto P_0c0b7dd2;
P_0c0b7dd2: /* original 4e0b, guest PC 0x0c0b7dd2 */
if(!s->budget--) { s->failed_pc=0x0c0b7dd2u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b7dd6u;
r[5]=read(ram,r[13]+20,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b7dd6u) { target=s->pc; goto dispatch; }
goto P_0c0b7dd6;
P_0c0b7dd4: /* original 55d5, guest PC 0x0c0b7dd4 */
if(!s->budget--) { s->failed_pc=0x0c0b7dd4u; return 0; }
r[5]=read(ram,r[13]+20,4);
goto P_0c0b7dd6;
P_0c0b7dd6: /* original 949a, guest PC 0x0c0b7dd6 */
if(!s->budget--) { s->failed_pc=0x0c0b7dd6u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b7f0eu,2);
goto P_0c0b7dd8;
P_0c0b7dd8: /* original 4e0b, guest PC 0x0c0b7dd8 */
if(!s->budget--) { s->failed_pc=0x0c0b7dd8u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b7ddcu;
r[5]=read(ram,r[13]+24,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b7ddcu) { target=s->pc; goto dispatch; }
goto P_0c0b7ddc;
P_0c0b7dda: /* original 55d6, guest PC 0x0c0b7dda */
if(!s->budget--) { s->failed_pc=0x0c0b7ddau; return 0; }
r[5]=read(ram,r[13]+24,4);
goto P_0c0b7ddc;
P_0c0b7ddc: /* original 9498, guest PC 0x0c0b7ddc */
if(!s->budget--) { s->failed_pc=0x0c0b7ddcu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b7f10u,2);
goto P_0c0b7dde;
P_0c0b7dde: /* original 4e0b, guest PC 0x0c0b7dde */
if(!s->budget--) { s->failed_pc=0x0c0b7ddeu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b7de2u;
r[5]=read(ram,r[13]+28,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b7de2u) { target=s->pc; goto dispatch; }
goto P_0c0b7de2;
P_0c0b7de0: /* original 55d7, guest PC 0x0c0b7de0 */
if(!s->budget--) { s->failed_pc=0x0c0b7de0u; return 0; }
r[5]=read(ram,r[13]+28,4);
goto P_0c0b7de2;
P_0c0b7de2: /* original 9496, guest PC 0x0c0b7de2 */
if(!s->budget--) { s->failed_pc=0x0c0b7de2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b7f12u,2);
goto P_0c0b7de4;
P_0c0b7de4: /* original 4e0b, guest PC 0x0c0b7de4 */
if(!s->budget--) { s->failed_pc=0x0c0b7de4u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b7de8u;
r[5]=read(ram,r[13]+32,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b7de8u) { target=s->pc; goto dispatch; }
goto P_0c0b7de8;
P_0c0b7de6: /* original 55d8, guest PC 0x0c0b7de6 */
if(!s->budget--) { s->failed_pc=0x0c0b7de6u; return 0; }
r[5]=read(ram,r[13]+32,4);
goto P_0c0b7de8;
P_0c0b7de8: /* original 9494, guest PC 0x0c0b7de8 */
if(!s->budget--) { s->failed_pc=0x0c0b7de8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b7f14u,2);
goto P_0c0b7dea;
P_0c0b7dea: /* original 4e0b, guest PC 0x0c0b7dea */
if(!s->budget--) { s->failed_pc=0x0c0b7deau; return 0; }
target=r[14];
r[16]=code_base|0x0c0b7deeu;
r[5]=read(ram,r[13]+36,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b7deeu) { target=s->pc; goto dispatch; }
goto P_0c0b7dee;
P_0c0b7dec: /* original 55d9, guest PC 0x0c0b7dec */
if(!s->budget--) { s->failed_pc=0x0c0b7decu; return 0; }
r[5]=read(ram,r[13]+36,4);
goto P_0c0b7dee;
P_0c0b7dee: /* original 9492, guest PC 0x0c0b7dee */
if(!s->budget--) { s->failed_pc=0x0c0b7deeu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b7f16u,2);
goto P_0c0b7df0;
P_0c0b7df0: /* original 4e0b, guest PC 0x0c0b7df0 */
if(!s->budget--) { s->failed_pc=0x0c0b7df0u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b7df4u;
r[5]=read(ram,r[13]+40,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b7df4u) { target=s->pc; goto dispatch; }
goto P_0c0b7df4;
P_0c0b7df2: /* original 55da, guest PC 0x0c0b7df2 */
if(!s->budget--) { s->failed_pc=0x0c0b7df2u; return 0; }
r[5]=read(ram,r[13]+40,4);
goto P_0c0b7df4;
P_0c0b7df4: /* original 9490, guest PC 0x0c0b7df4 */
if(!s->budget--) { s->failed_pc=0x0c0b7df4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b7f18u,2);
goto P_0c0b7df6;
P_0c0b7df6: /* original 4e0b, guest PC 0x0c0b7df6 */
if(!s->budget--) { s->failed_pc=0x0c0b7df6u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b7dfau;
r[5]=read(ram,r[13]+44,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b7dfau) { target=s->pc; goto dispatch; }
goto P_0c0b7dfa;
P_0c0b7df8: /* original 55db, guest PC 0x0c0b7df8 */
if(!s->budget--) { s->failed_pc=0x0c0b7df8u; return 0; }
r[5]=read(ram,r[13]+44,4);
goto P_0c0b7dfa;
P_0c0b7dfa: /* original 948e, guest PC 0x0c0b7dfa */
if(!s->budget--) { s->failed_pc=0x0c0b7dfau; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b7f1au,2);
goto P_0c0b7dfc;
P_0c0b7dfc: /* original 4e0b, guest PC 0x0c0b7dfc */
if(!s->budget--) { s->failed_pc=0x0c0b7dfcu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b7e00u;
r[5]=read(ram,r[13]+48,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b7e00u) { target=s->pc; goto dispatch; }
goto P_0c0b7e00;
P_0c0b7dfe: /* original 55dc, guest PC 0x0c0b7dfe */
if(!s->budget--) { s->failed_pc=0x0c0b7dfeu; return 0; }
r[5]=read(ram,r[13]+48,4);
goto P_0c0b7e00;
P_0c0b7e00: /* original 948c, guest PC 0x0c0b7e00 */
if(!s->budget--) { s->failed_pc=0x0c0b7e00u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b7f1cu,2);
goto P_0c0b7e02;
P_0c0b7e02: /* original 4e0b, guest PC 0x0c0b7e02 */
if(!s->budget--) { s->failed_pc=0x0c0b7e02u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b7e06u;
r[5]=read(ram,r[13]+52,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b7e06u) { target=s->pc; goto dispatch; }
goto P_0c0b7e06;
P_0c0b7e04: /* original 55dd, guest PC 0x0c0b7e04 */
if(!s->budget--) { s->failed_pc=0x0c0b7e04u; return 0; }
r[5]=read(ram,r[13]+52,4);
goto P_0c0b7e06;
P_0c0b7e06: /* original 948a, guest PC 0x0c0b7e06 */
if(!s->budget--) { s->failed_pc=0x0c0b7e06u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b7f1eu,2);
goto P_0c0b7e08;
P_0c0b7e08: /* original 4e0b, guest PC 0x0c0b7e08 */
if(!s->budget--) { s->failed_pc=0x0c0b7e08u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b7e0cu;
r[5]=read(ram,r[13]+56,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b7e0cu) { target=s->pc; goto dispatch; }
goto P_0c0b7e0c;
P_0c0b7e0a: /* original 55de, guest PC 0x0c0b7e0a */
if(!s->budget--) { s->failed_pc=0x0c0b7e0au; return 0; }
r[5]=read(ram,r[13]+56,4);
goto P_0c0b7e0c;
P_0c0b7e0c: /* original 9488, guest PC 0x0c0b7e0c */
if(!s->budget--) { s->failed_pc=0x0c0b7e0cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b7f20u,2);
goto P_0c0b7e0e;
P_0c0b7e0e: /* original 4e0b, guest PC 0x0c0b7e0e */
if(!s->budget--) { s->failed_pc=0x0c0b7e0eu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b7e12u;
r[5]=read(ram,r[13]+60,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b7e12u) { target=s->pc; goto dispatch; }
goto P_0c0b7e12;
P_0c0b7e10: /* original 55df, guest PC 0x0c0b7e10 */
if(!s->budget--) { s->failed_pc=0x0c0b7e10u; return 0; }
r[5]=read(ram,r[13]+60,4);
goto P_0c0b7e12;
P_0c0b7e12: /* original 9486, guest PC 0x0c0b7e12 */
if(!s->budget--) { s->failed_pc=0x0c0b7e12u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b7f22u,2);
goto P_0c0b7e14;
P_0c0b7e14: /* original e040, guest PC 0x0c0b7e14 */
if(!s->budget--) { s->failed_pc=0x0c0b7e14u; return 0; }
r[0]=0x00000040u;
goto P_0c0b7e16;
P_0c0b7e16: /* original 4e0b, guest PC 0x0c0b7e16 */
if(!s->budget--) { s->failed_pc=0x0c0b7e16u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b7e1au;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b7e1au) { target=s->pc; goto dispatch; }
goto P_0c0b7e1a;
P_0c0b7e18: /* original 05de, guest PC 0x0c0b7e18 */
if(!s->budget--) { s->failed_pc=0x0c0b7e18u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b7e1a;
P_0c0b7e1a: /* original 9483, guest PC 0x0c0b7e1a */
if(!s->budget--) { s->failed_pc=0x0c0b7e1au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b7f24u,2);
goto P_0c0b7e1c;
P_0c0b7e1c: /* original e044, guest PC 0x0c0b7e1c */
if(!s->budget--) { s->failed_pc=0x0c0b7e1cu; return 0; }
r[0]=0x00000044u;
goto P_0c0b7e1e;
P_0c0b7e1e: /* original 4e0b, guest PC 0x0c0b7e1e */
if(!s->budget--) { s->failed_pc=0x0c0b7e1eu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b7e22u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b7e22u) { target=s->pc; goto dispatch; }
goto P_0c0b7e22;
P_0c0b7e20: /* original 05de, guest PC 0x0c0b7e20 */
if(!s->budget--) { s->failed_pc=0x0c0b7e20u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b7e22;
P_0c0b7e22: /* original 9480, guest PC 0x0c0b7e22 */
if(!s->budget--) { s->failed_pc=0x0c0b7e22u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b7f26u,2);
goto P_0c0b7e24;
P_0c0b7e24: /* original e048, guest PC 0x0c0b7e24 */
if(!s->budget--) { s->failed_pc=0x0c0b7e24u; return 0; }
r[0]=0x00000048u;
goto P_0c0b7e26;
P_0c0b7e26: /* original 4e0b, guest PC 0x0c0b7e26 */
if(!s->budget--) { s->failed_pc=0x0c0b7e26u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b7e2au;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b7e2au) { target=s->pc; goto dispatch; }
goto P_0c0b7e2a;
P_0c0b7e28: /* original 05de, guest PC 0x0c0b7e28 */
if(!s->budget--) { s->failed_pc=0x0c0b7e28u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b7e2a;
P_0c0b7e2a: /* original 947d, guest PC 0x0c0b7e2a */
if(!s->budget--) { s->failed_pc=0x0c0b7e2au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b7f28u,2);
goto P_0c0b7e2c;
P_0c0b7e2c: /* original e04c, guest PC 0x0c0b7e2c */
if(!s->budget--) { s->failed_pc=0x0c0b7e2cu; return 0; }
r[0]=0x0000004cu;
goto P_0c0b7e2e;
P_0c0b7e2e: /* original 4e0b, guest PC 0x0c0b7e2e */
if(!s->budget--) { s->failed_pc=0x0c0b7e2eu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b7e32u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b7e32u) { target=s->pc; goto dispatch; }
goto P_0c0b7e32;
P_0c0b7e30: /* original 05de, guest PC 0x0c0b7e30 */
if(!s->budget--) { s->failed_pc=0x0c0b7e30u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b7e32;
P_0c0b7e32: /* original 947a, guest PC 0x0c0b7e32 */
if(!s->budget--) { s->failed_pc=0x0c0b7e32u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b7f2au,2);
goto P_0c0b7e34;
P_0c0b7e34: /* original e050, guest PC 0x0c0b7e34 */
if(!s->budget--) { s->failed_pc=0x0c0b7e34u; return 0; }
r[0]=0x00000050u;
goto P_0c0b7e36;
P_0c0b7e36: /* original 4e0b, guest PC 0x0c0b7e36 */
if(!s->budget--) { s->failed_pc=0x0c0b7e36u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b7e3au;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b7e3au) { target=s->pc; goto dispatch; }
goto P_0c0b7e3a;
P_0c0b7e38: /* original 05de, guest PC 0x0c0b7e38 */
if(!s->budget--) { s->failed_pc=0x0c0b7e38u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b7e3a;
P_0c0b7e3a: /* original 9477, guest PC 0x0c0b7e3a */
if(!s->budget--) { s->failed_pc=0x0c0b7e3au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b7f2cu,2);
goto P_0c0b7e3c;
P_0c0b7e3c: /* original e054, guest PC 0x0c0b7e3c */
if(!s->budget--) { s->failed_pc=0x0c0b7e3cu; return 0; }
r[0]=0x00000054u;
goto P_0c0b7e3e;
P_0c0b7e3e: /* original 4e0b, guest PC 0x0c0b7e3e */
if(!s->budget--) { s->failed_pc=0x0c0b7e3eu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b7e42u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b7e42u) { target=s->pc; goto dispatch; }
goto P_0c0b7e42;
P_0c0b7e40: /* original 05de, guest PC 0x0c0b7e40 */
if(!s->budget--) { s->failed_pc=0x0c0b7e40u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b7e42;
P_0c0b7e42: /* original 9474, guest PC 0x0c0b7e42 */
if(!s->budget--) { s->failed_pc=0x0c0b7e42u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b7f2eu,2);
goto P_0c0b7e44;
P_0c0b7e44: /* original e058, guest PC 0x0c0b7e44 */
if(!s->budget--) { s->failed_pc=0x0c0b7e44u; return 0; }
r[0]=0x00000058u;
goto P_0c0b7e46;
P_0c0b7e46: /* original 4e0b, guest PC 0x0c0b7e46 */
if(!s->budget--) { s->failed_pc=0x0c0b7e46u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b7e4au;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b7e4au) { target=s->pc; goto dispatch; }
goto P_0c0b7e4a;
P_0c0b7e48: /* original 05de, guest PC 0x0c0b7e48 */
if(!s->budget--) { s->failed_pc=0x0c0b7e48u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b7e4a;
P_0c0b7e4a: /* original 9471, guest PC 0x0c0b7e4a */
if(!s->budget--) { s->failed_pc=0x0c0b7e4au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b7f30u,2);
goto P_0c0b7e4c;
P_0c0b7e4c: /* original e05c, guest PC 0x0c0b7e4c */
if(!s->budget--) { s->failed_pc=0x0c0b7e4cu; return 0; }
r[0]=0x0000005cu;
goto P_0c0b7e4e;
P_0c0b7e4e: /* original 4e0b, guest PC 0x0c0b7e4e */
if(!s->budget--) { s->failed_pc=0x0c0b7e4eu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b7e52u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b7e52u) { target=s->pc; goto dispatch; }
goto P_0c0b7e52;
P_0c0b7e50: /* original 05de, guest PC 0x0c0b7e50 */
if(!s->budget--) { s->failed_pc=0x0c0b7e50u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b7e52;
P_0c0b7e52: /* original 946e, guest PC 0x0c0b7e52 */
if(!s->budget--) { s->failed_pc=0x0c0b7e52u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b7f32u,2);
goto P_0c0b7e54;
P_0c0b7e54: /* original e060, guest PC 0x0c0b7e54 */
if(!s->budget--) { s->failed_pc=0x0c0b7e54u; return 0; }
r[0]=0x00000060u;
goto P_0c0b7e56;
P_0c0b7e56: /* original 4e0b, guest PC 0x0c0b7e56 */
if(!s->budget--) { s->failed_pc=0x0c0b7e56u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b7e5au;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b7e5au) { target=s->pc; goto dispatch; }
goto P_0c0b7e5a;
P_0c0b7e58: /* original 05de, guest PC 0x0c0b7e58 */
if(!s->budget--) { s->failed_pc=0x0c0b7e58u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b7e5a;
P_0c0b7e5a: /* original 946b, guest PC 0x0c0b7e5a */
if(!s->budget--) { s->failed_pc=0x0c0b7e5au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b7f34u,2);
goto P_0c0b7e5c;
P_0c0b7e5c: /* original e064, guest PC 0x0c0b7e5c */
if(!s->budget--) { s->failed_pc=0x0c0b7e5cu; return 0; }
r[0]=0x00000064u;
goto P_0c0b7e5e;
P_0c0b7e5e: /* original 4e0b, guest PC 0x0c0b7e5e */
if(!s->budget--) { s->failed_pc=0x0c0b7e5eu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b7e62u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b7e62u) { target=s->pc; goto dispatch; }
goto P_0c0b7e62;
P_0c0b7e60: /* original 05de, guest PC 0x0c0b7e60 */
if(!s->budget--) { s->failed_pc=0x0c0b7e60u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b7e62;
P_0c0b7e62: /* original 9468, guest PC 0x0c0b7e62 */
if(!s->budget--) { s->failed_pc=0x0c0b7e62u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b7f36u,2);
goto P_0c0b7e64;
P_0c0b7e64: /* original e068, guest PC 0x0c0b7e64 */
if(!s->budget--) { s->failed_pc=0x0c0b7e64u; return 0; }
r[0]=0x00000068u;
goto P_0c0b7e66;
P_0c0b7e66: /* original 4e0b, guest PC 0x0c0b7e66 */
if(!s->budget--) { s->failed_pc=0x0c0b7e66u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b7e6au;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b7e6au) { target=s->pc; goto dispatch; }
goto P_0c0b7e6a;
P_0c0b7e68: /* original 05de, guest PC 0x0c0b7e68 */
if(!s->budget--) { s->failed_pc=0x0c0b7e68u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b7e6a;
P_0c0b7e6a: /* original 9465, guest PC 0x0c0b7e6a */
if(!s->budget--) { s->failed_pc=0x0c0b7e6au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b7f38u,2);
goto P_0c0b7e6c;
P_0c0b7e6c: /* original e06c, guest PC 0x0c0b7e6c */
if(!s->budget--) { s->failed_pc=0x0c0b7e6cu; return 0; }
r[0]=0x0000006cu;
goto P_0c0b7e6e;
P_0c0b7e6e: /* original 4e0b, guest PC 0x0c0b7e6e */
if(!s->budget--) { s->failed_pc=0x0c0b7e6eu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b7e72u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b7e72u) { target=s->pc; goto dispatch; }
goto P_0c0b7e72;
P_0c0b7e70: /* original 05de, guest PC 0x0c0b7e70 */
if(!s->budget--) { s->failed_pc=0x0c0b7e70u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b7e72;
P_0c0b7e72: /* original 9462, guest PC 0x0c0b7e72 */
if(!s->budget--) { s->failed_pc=0x0c0b7e72u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b7f3au,2);
goto P_0c0b7e74;
P_0c0b7e74: /* original e070, guest PC 0x0c0b7e74 */
if(!s->budget--) { s->failed_pc=0x0c0b7e74u; return 0; }
r[0]=0x00000070u;
goto P_0c0b7e76;
P_0c0b7e76: /* original 4e0b, guest PC 0x0c0b7e76 */
if(!s->budget--) { s->failed_pc=0x0c0b7e76u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b7e7au;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b7e7au) { target=s->pc; goto dispatch; }
goto P_0c0b7e7a;
P_0c0b7e78: /* original 05de, guest PC 0x0c0b7e78 */
if(!s->budget--) { s->failed_pc=0x0c0b7e78u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b7e7a;
P_0c0b7e7a: /* original 945f, guest PC 0x0c0b7e7a */
if(!s->budget--) { s->failed_pc=0x0c0b7e7au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b7f3cu,2);
goto P_0c0b7e7c;
P_0c0b7e7c: /* original e074, guest PC 0x0c0b7e7c */
if(!s->budget--) { s->failed_pc=0x0c0b7e7cu; return 0; }
r[0]=0x00000074u;
goto P_0c0b7e7e;
P_0c0b7e7e: /* original 4e0b, guest PC 0x0c0b7e7e */
if(!s->budget--) { s->failed_pc=0x0c0b7e7eu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b7e82u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b7e82u) { target=s->pc; goto dispatch; }
goto P_0c0b7e82;
P_0c0b7e80: /* original 05de, guest PC 0x0c0b7e80 */
if(!s->budget--) { s->failed_pc=0x0c0b7e80u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b7e82;
P_0c0b7e82: /* original 945c, guest PC 0x0c0b7e82 */
if(!s->budget--) { s->failed_pc=0x0c0b7e82u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b7f3eu,2);
goto P_0c0b7e84;
P_0c0b7e84: /* original e078, guest PC 0x0c0b7e84 */
if(!s->budget--) { s->failed_pc=0x0c0b7e84u; return 0; }
r[0]=0x00000078u;
goto P_0c0b7e86;
P_0c0b7e86: /* original 4e0b, guest PC 0x0c0b7e86 */
if(!s->budget--) { s->failed_pc=0x0c0b7e86u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b7e8au;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b7e8au) { target=s->pc; goto dispatch; }
goto P_0c0b7e8a;
P_0c0b7e88: /* original 05de, guest PC 0x0c0b7e88 */
if(!s->budget--) { s->failed_pc=0x0c0b7e88u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b7e8a;
P_0c0b7e8a: /* original 9459, guest PC 0x0c0b7e8a */
if(!s->budget--) { s->failed_pc=0x0c0b7e8au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b7f40u,2);
goto P_0c0b7e8c;
P_0c0b7e8c: /* original e07c, guest PC 0x0c0b7e8c */
if(!s->budget--) { s->failed_pc=0x0c0b7e8cu; return 0; }
r[0]=0x0000007cu;
goto P_0c0b7e8e;
P_0c0b7e8e: /* original 4e0b, guest PC 0x0c0b7e8e */
if(!s->budget--) { s->failed_pc=0x0c0b7e8eu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b7e92u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b7e92u) { target=s->pc; goto dispatch; }
goto P_0c0b7e92;
P_0c0b7e90: /* original 05de, guest PC 0x0c0b7e90 */
if(!s->budget--) { s->failed_pc=0x0c0b7e90u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b7e92;
P_0c0b7e92: /* original 9457, guest PC 0x0c0b7e92 */
if(!s->budget--) { s->failed_pc=0x0c0b7e92u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b7f44u,2);
goto P_0c0b7e94;
P_0c0b7e94: /* original 9055, guest PC 0x0c0b7e94 */
if(!s->budget--) { s->failed_pc=0x0c0b7e94u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b7f42u,2);
goto P_0c0b7e96;
P_0c0b7e96: /* original 4e0b, guest PC 0x0c0b7e96 */
if(!s->budget--) { s->failed_pc=0x0c0b7e96u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b7e9au;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b7e9au) { target=s->pc; goto dispatch; }
goto P_0c0b7e9a;
P_0c0b7e98: /* original 05de, guest PC 0x0c0b7e98 */
if(!s->budget--) { s->failed_pc=0x0c0b7e98u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b7e9a;
P_0c0b7e9a: /* original 9554, guest PC 0x0c0b7e9a */
if(!s->budget--) { s->failed_pc=0x0c0b7e9au; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b7f46u,2);
goto P_0c0b7e9c;
P_0c0b7e9c: /* original 35dc, guest PC 0x0c0b7e9c */
if(!s->budget--) { s->failed_pc=0x0c0b7e9cu; return 0; }
r[5]+=r[13];
goto P_0c0b7e9e;
P_0c0b7e9e: /* original 2f52, guest PC 0x0c0b7e9e */
if(!s->budget--) { s->failed_pc=0x0c0b7e9eu; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0b7ea0;
P_0c0b7ea0: /* original 9452, guest PC 0x0c0b7ea0 */
if(!s->budget--) { s->failed_pc=0x0c0b7ea0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b7f48u,2);
goto P_0c0b7ea2;
P_0c0b7ea2: /* original 4e0b, guest PC 0x0c0b7ea2 */
if(!s->budget--) { s->failed_pc=0x0c0b7ea2u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b7ea6u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b7ea6u) { target=s->pc; goto dispatch; }
goto P_0c0b7ea6;
P_0c0b7ea4: /* original 6552, guest PC 0x0c0b7ea4 */
if(!s->budget--) { s->failed_pc=0x0c0b7ea4u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b7ea6;
P_0c0b7ea6: /* original 9550, guest PC 0x0c0b7ea6 */
if(!s->budget--) { s->failed_pc=0x0c0b7ea6u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b7f4au,2);
goto P_0c0b7ea8;
P_0c0b7ea8: /* original 35dc, guest PC 0x0c0b7ea8 */
if(!s->budget--) { s->failed_pc=0x0c0b7ea8u; return 0; }
r[5]+=r[13];
goto P_0c0b7eaa;
P_0c0b7eaa: /* original 1f51, guest PC 0x0c0b7eaa */
if(!s->budget--) { s->failed_pc=0x0c0b7eaau; return 0; }
write(ram,r[15]+4,r[5],4);
goto P_0c0b7eac;
P_0c0b7eac: /* original 944e, guest PC 0x0c0b7eac */
if(!s->budget--) { s->failed_pc=0x0c0b7eacu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b7f4cu,2);
goto P_0c0b7eae;
P_0c0b7eae: /* original 4e0b, guest PC 0x0c0b7eae */
if(!s->budget--) { s->failed_pc=0x0c0b7eaeu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b7eb2u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b7eb2u) { target=s->pc; goto dispatch; }
goto P_0c0b7eb2;
P_0c0b7eb0: /* original 6552, guest PC 0x0c0b7eb0 */
if(!s->budget--) { s->failed_pc=0x0c0b7eb0u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b7eb2;
P_0c0b7eb2: /* original 944d, guest PC 0x0c0b7eb2 */
if(!s->budget--) { s->failed_pc=0x0c0b7eb2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b7f50u,2);
goto P_0c0b7eb4;
P_0c0b7eb4: /* original 904b, guest PC 0x0c0b7eb4 */
if(!s->budget--) { s->failed_pc=0x0c0b7eb4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b7f4eu,2);
goto P_0c0b7eb6;
P_0c0b7eb6: /* original 4e0b, guest PC 0x0c0b7eb6 */
if(!s->budget--) { s->failed_pc=0x0c0b7eb6u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b7ebau;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b7ebau) { target=s->pc; goto dispatch; }
goto P_0c0b7eba;
P_0c0b7eb8: /* original 05de, guest PC 0x0c0b7eb8 */
if(!s->budget--) { s->failed_pc=0x0c0b7eb8u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b7eba;
P_0c0b7eba: /* original 944b, guest PC 0x0c0b7eba */
if(!s->budget--) { s->failed_pc=0x0c0b7ebau; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b7f54u,2);
goto P_0c0b7ebc;
P_0c0b7ebc: /* original 9049, guest PC 0x0c0b7ebc */
if(!s->budget--) { s->failed_pc=0x0c0b7ebcu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b7f52u,2);
goto P_0c0b7ebe;
P_0c0b7ebe: /* original 4e0b, guest PC 0x0c0b7ebe */
if(!s->budget--) { s->failed_pc=0x0c0b7ebeu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b7ec2u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b7ec2u) { target=s->pc; goto dispatch; }
goto P_0c0b7ec2;
P_0c0b7ec0: /* original 05de, guest PC 0x0c0b7ec0 */
if(!s->budget--) { s->failed_pc=0x0c0b7ec0u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b7ec2;
P_0c0b7ec2: /* original 9948, guest PC 0x0c0b7ec2 */
if(!s->budget--) { s->failed_pc=0x0c0b7ec2u; return 0; }
r[9]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b7f56u,2);
goto P_0c0b7ec4;
P_0c0b7ec4: /* original 9448, guest PC 0x0c0b7ec4 */
if(!s->budget--) { s->failed_pc=0x0c0b7ec4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b7f58u,2);
goto P_0c0b7ec6;
P_0c0b7ec6: /* original 39dc, guest PC 0x0c0b7ec6 */
if(!s->budget--) { s->failed_pc=0x0c0b7ec6u; return 0; }
r[9]+=r[13];
goto P_0c0b7ec8;
P_0c0b7ec8: /* original 4e0b, guest PC 0x0c0b7ec8 */
if(!s->budget--) { s->failed_pc=0x0c0b7ec8u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b7eccu;
tmp=read(ram,r[9],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b7eccu) { target=s->pc; goto dispatch; }
goto P_0c0b7ecc;
P_0c0b7eca: /* original 6592, guest PC 0x0c0b7eca */
if(!s->budget--) { s->failed_pc=0x0c0b7ecau; return 0; }
tmp=read(ram,r[9],4);
r[5]=tmp;
goto P_0c0b7ecc;
P_0c0b7ecc: /* original 9445, guest PC 0x0c0b7ecc */
if(!s->budget--) { s->failed_pc=0x0c0b7eccu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b7f5au,2);
goto P_0c0b7ece;
P_0c0b7ece: /* original 4e0b, guest PC 0x0c0b7ece */
if(!s->budget--) { s->failed_pc=0x0c0b7eceu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b7ed2u;
tmp=read(ram,r[9],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b7ed2u) { target=s->pc; goto dispatch; }
goto P_0c0b7ed2;
P_0c0b7ed0: /* original 6592, guest PC 0x0c0b7ed0 */
if(!s->budget--) { s->failed_pc=0x0c0b7ed0u; return 0; }
tmp=read(ram,r[9],4);
r[5]=tmp;
goto P_0c0b7ed2;
P_0c0b7ed2: /* original 9443, guest PC 0x0c0b7ed2 */
if(!s->budget--) { s->failed_pc=0x0c0b7ed2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b7f5cu,2);
goto P_0c0b7ed4;
P_0c0b7ed4: /* original 4e0b, guest PC 0x0c0b7ed4 */
if(!s->budget--) { s->failed_pc=0x0c0b7ed4u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b7ed8u;
tmp=read(ram,r[9],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b7ed8u) { target=s->pc; goto dispatch; }
goto P_0c0b7ed8;
P_0c0b7ed6: /* original 6592, guest PC 0x0c0b7ed6 */
if(!s->budget--) { s->failed_pc=0x0c0b7ed6u; return 0; }
tmp=read(ram,r[9],4);
r[5]=tmp;
goto P_0c0b7ed8;
P_0c0b7ed8: /* original 9441, guest PC 0x0c0b7ed8 */
if(!s->budget--) { s->failed_pc=0x0c0b7ed8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b7f5eu,2);
goto P_0c0b7eda;
P_0c0b7eda: /* original 4e0b, guest PC 0x0c0b7eda */
if(!s->budget--) { s->failed_pc=0x0c0b7edau; return 0; }
target=r[14];
r[16]=code_base|0x0c0b7edeu;
tmp=read(ram,r[9],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b7edeu) { target=s->pc; goto dispatch; }
goto P_0c0b7ede;
P_0c0b7edc: /* original 6592, guest PC 0x0c0b7edc */
if(!s->budget--) { s->failed_pc=0x0c0b7edcu; return 0; }
tmp=read(ram,r[9],4);
r[5]=tmp;
goto P_0c0b7ede;
P_0c0b7ede: /* original 9c3f, guest PC 0x0c0b7ede */
if(!s->budget--) { s->failed_pc=0x0c0b7edeu; return 0; }
r[12]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b7f60u,2);
goto P_0c0b7ee0;
P_0c0b7ee0: /* original 943f, guest PC 0x0c0b7ee0 */
if(!s->budget--) { s->failed_pc=0x0c0b7ee0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b7f62u,2);
goto P_0c0b7ee2;
P_0c0b7ee2: /* original 3cdc, guest PC 0x0c0b7ee2 */
if(!s->budget--) { s->failed_pc=0x0c0b7ee2u; return 0; }
r[12]+=r[13];
goto P_0c0b7ee4;
P_0c0b7ee4: /* original 4e0b, guest PC 0x0c0b7ee4 */
if(!s->budget--) { s->failed_pc=0x0c0b7ee4u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b7ee8u;
tmp=read(ram,r[12],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b7ee8u) { target=s->pc; goto dispatch; }
goto P_0c0b7ee8;
P_0c0b7ee6: /* original 65c2, guest PC 0x0c0b7ee6 */
if(!s->budget--) { s->failed_pc=0x0c0b7ee6u; return 0; }
tmp=read(ram,r[12],4);
r[5]=tmp;
goto P_0c0b7ee8;
P_0c0b7ee8: /* original 943c, guest PC 0x0c0b7ee8 */
if(!s->budget--) { s->failed_pc=0x0c0b7ee8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b7f64u,2);
goto P_0c0b7eea;
P_0c0b7eea: /* original 4e0b, guest PC 0x0c0b7eea */
if(!s->budget--) { s->failed_pc=0x0c0b7eeau; return 0; }
target=r[14];
r[16]=code_base|0x0c0b7eeeu;
tmp=read(ram,r[12],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b7eeeu) { target=s->pc; goto dispatch; }
goto P_0c0b7eee;
P_0c0b7eec: /* original 65c2, guest PC 0x0c0b7eec */
if(!s->budget--) { s->failed_pc=0x0c0b7eecu; return 0; }
tmp=read(ram,r[12],4);
r[5]=tmp;
goto P_0c0b7eee;
P_0c0b7eee: /* original 943a, guest PC 0x0c0b7eee */
if(!s->budget--) { s->failed_pc=0x0c0b7eeeu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b7f66u,2);
goto P_0c0b7ef0;
P_0c0b7ef0: /* original 4e0b, guest PC 0x0c0b7ef0 */
if(!s->budget--) { s->failed_pc=0x0c0b7ef0u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b7ef4u;
tmp=read(ram,r[12],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b7ef4u) { target=s->pc; goto dispatch; }
goto P_0c0b7ef4;
P_0c0b7ef2: /* original 65c2, guest PC 0x0c0b7ef2 */
if(!s->budget--) { s->failed_pc=0x0c0b7ef2u; return 0; }
tmp=read(ram,r[12],4);
r[5]=tmp;
goto P_0c0b7ef4;
P_0c0b7ef4: /* original 9438, guest PC 0x0c0b7ef4 */
if(!s->budget--) { s->failed_pc=0x0c0b7ef4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b7f68u,2);
goto P_0c0b7ef6;
P_0c0b7ef6: /* original 4e0b, guest PC 0x0c0b7ef6 */
if(!s->budget--) { s->failed_pc=0x0c0b7ef6u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b7efau;
tmp=read(ram,r[12],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b7efau) { target=s->pc; goto dispatch; }
goto P_0c0b7efa;
P_0c0b7ef8: /* original 65c2, guest PC 0x0c0b7ef8 */
if(!s->budget--) { s->failed_pc=0x0c0b7ef8u; return 0; }
tmp=read(ram,r[12],4);
r[5]=tmp;
goto P_0c0b7efa;
P_0c0b7efa: /* original 9b36, guest PC 0x0c0b7efa */
if(!s->budget--) { s->failed_pc=0x0c0b7efau; return 0; }
r[11]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b7f6au,2);
goto P_0c0b7efc;
P_0c0b7efc: /* original 3bdc, guest PC 0x0c0b7efc */
if(!s->budget--) { s->failed_pc=0x0c0b7efcu; return 0; }
r[11]+=r[13];
goto P_0c0b7efe;
P_0c0b7efe: /* original a037, guest PC 0x0c0b7efe */
if(!s->budget--) { s->failed_pc=0x0c0b7efeu; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
goto P_0c0b7f70;
P_0c0b7f00: /* original 65b2, guest PC 0x0c0b7f00 */
if(!s->budget--) { s->failed_pc=0x0c0b7f00u; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
if(!vf3_matrix_family(0x0c0b7f02u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0b7f02u; return 0; } return 1;
P_0c0b7f70: /* original 94ab, guest PC 0x0c0b7f70 */
if(!s->budget--) { s->failed_pc=0x0c0b7f70u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b80cau,2);
goto P_0c0b7f72;
P_0c0b7f72: /* original 4e0b, guest PC 0x0c0b7f72 */
if(!s->budget--) { s->failed_pc=0x0c0b7f72u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b7f76u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b7f76u) { target=s->pc; goto dispatch; }
goto P_0c0b7f76;
P_0c0b7f74: /* original 0009, guest PC 0x0c0b7f74 */
if(!s->budget--) { s->failed_pc=0x0c0b7f74u; return 0; }
goto P_0c0b7f76;
P_0c0b7f76: /* original 94a9, guest PC 0x0c0b7f76 */
if(!s->budget--) { s->failed_pc=0x0c0b7f76u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b80ccu,2);
goto P_0c0b7f78;
P_0c0b7f78: /* original 4e0b, guest PC 0x0c0b7f78 */
if(!s->budget--) { s->failed_pc=0x0c0b7f78u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b7f7cu;
tmp=read(ram,r[11],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b7f7cu) { target=s->pc; goto dispatch; }
goto P_0c0b7f7c;
P_0c0b7f7a: /* original 65b2, guest PC 0x0c0b7f7a */
if(!s->budget--) { s->failed_pc=0x0c0b7f7au; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
goto P_0c0b7f7c;
P_0c0b7f7c: /* original 94a7, guest PC 0x0c0b7f7c */
if(!s->budget--) { s->failed_pc=0x0c0b7f7cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b80ceu,2);
goto P_0c0b7f7e;
P_0c0b7f7e: /* original 4e0b, guest PC 0x0c0b7f7e */
if(!s->budget--) { s->failed_pc=0x0c0b7f7eu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b7f82u;
tmp=read(ram,r[11],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b7f82u) { target=s->pc; goto dispatch; }
goto P_0c0b7f82;
P_0c0b7f80: /* original 65b2, guest PC 0x0c0b7f80 */
if(!s->budget--) { s->failed_pc=0x0c0b7f80u; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
goto P_0c0b7f82;
P_0c0b7f82: /* original 94a5, guest PC 0x0c0b7f82 */
if(!s->budget--) { s->failed_pc=0x0c0b7f82u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b80d0u,2);
goto P_0c0b7f84;
P_0c0b7f84: /* original 4e0b, guest PC 0x0c0b7f84 */
if(!s->budget--) { s->failed_pc=0x0c0b7f84u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b7f88u;
tmp=read(ram,r[11],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b7f88u) { target=s->pc; goto dispatch; }
goto P_0c0b7f88;
P_0c0b7f86: /* original 65b2, guest PC 0x0c0b7f86 */
if(!s->budget--) { s->failed_pc=0x0c0b7f86u; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
goto P_0c0b7f88;
P_0c0b7f88: /* original 9aa3, guest PC 0x0c0b7f88 */
if(!s->budget--) { s->failed_pc=0x0c0b7f88u; return 0; }
r[10]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b80d2u,2);
goto P_0c0b7f8a;
P_0c0b7f8a: /* original 94a3, guest PC 0x0c0b7f8a */
if(!s->budget--) { s->failed_pc=0x0c0b7f8au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b80d4u,2);
goto P_0c0b7f8c;
P_0c0b7f8c: /* original 3adc, guest PC 0x0c0b7f8c */
if(!s->budget--) { s->failed_pc=0x0c0b7f8cu; return 0; }
r[10]+=r[13];
goto P_0c0b7f8e;
P_0c0b7f8e: /* original 4e0b, guest PC 0x0c0b7f8e */
if(!s->budget--) { s->failed_pc=0x0c0b7f8eu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b7f92u;
tmp=read(ram,r[10],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b7f92u) { target=s->pc; goto dispatch; }
goto P_0c0b7f92;
P_0c0b7f90: /* original 65a2, guest PC 0x0c0b7f90 */
if(!s->budget--) { s->failed_pc=0x0c0b7f90u; return 0; }
tmp=read(ram,r[10],4);
r[5]=tmp;
goto P_0c0b7f92;
P_0c0b7f92: /* original 94a0, guest PC 0x0c0b7f92 */
if(!s->budget--) { s->failed_pc=0x0c0b7f92u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b80d6u,2);
goto P_0c0b7f94;
P_0c0b7f94: /* original 4e0b, guest PC 0x0c0b7f94 */
if(!s->budget--) { s->failed_pc=0x0c0b7f94u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b7f98u;
tmp=read(ram,r[10],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b7f98u) { target=s->pc; goto dispatch; }
goto P_0c0b7f98;
P_0c0b7f96: /* original 65a2, guest PC 0x0c0b7f96 */
if(!s->budget--) { s->failed_pc=0x0c0b7f96u; return 0; }
tmp=read(ram,r[10],4);
r[5]=tmp;
goto P_0c0b7f98;
P_0c0b7f98: /* original 949e, guest PC 0x0c0b7f98 */
if(!s->budget--) { s->failed_pc=0x0c0b7f98u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b80d8u,2);
goto P_0c0b7f9a;
P_0c0b7f9a: /* original 4e0b, guest PC 0x0c0b7f9a */
if(!s->budget--) { s->failed_pc=0x0c0b7f9au; return 0; }
target=r[14];
r[16]=code_base|0x0c0b7f9eu;
tmp=read(ram,r[10],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b7f9eu) { target=s->pc; goto dispatch; }
goto P_0c0b7f9e;
P_0c0b7f9c: /* original 65a2, guest PC 0x0c0b7f9c */
if(!s->budget--) { s->failed_pc=0x0c0b7f9cu; return 0; }
tmp=read(ram,r[10],4);
r[5]=tmp;
goto P_0c0b7f9e;
P_0c0b7f9e: /* original 949c, guest PC 0x0c0b7f9e */
if(!s->budget--) { s->failed_pc=0x0c0b7f9eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b80dau,2);
goto P_0c0b7fa0;
P_0c0b7fa0: /* original 4e0b, guest PC 0x0c0b7fa0 */
if(!s->budget--) { s->failed_pc=0x0c0b7fa0u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b7fa4u;
tmp=read(ram,r[10],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b7fa4u) { target=s->pc; goto dispatch; }
goto P_0c0b7fa4;
P_0c0b7fa2: /* original 65a2, guest PC 0x0c0b7fa2 */
if(!s->budget--) { s->failed_pc=0x0c0b7fa2u; return 0; }
tmp=read(ram,r[10],4);
r[5]=tmp;
goto P_0c0b7fa4;
P_0c0b7fa4: /* original 949a, guest PC 0x0c0b7fa4 */
if(!s->budget--) { s->failed_pc=0x0c0b7fa4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b80dcu,2);
goto P_0c0b7fa6;
P_0c0b7fa6: /* original 65f2, guest PC 0x0c0b7fa6 */
if(!s->budget--) { s->failed_pc=0x0c0b7fa6u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0b7fa8;
P_0c0b7fa8: /* original 4e0b, guest PC 0x0c0b7fa8 */
if(!s->budget--) { s->failed_pc=0x0c0b7fa8u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b7facu;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b7facu) { target=s->pc; goto dispatch; }
goto P_0c0b7fac;
P_0c0b7faa: /* original 6552, guest PC 0x0c0b7faa */
if(!s->budget--) { s->failed_pc=0x0c0b7faau; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b7fac;
P_0c0b7fac: /* original 9497, guest PC 0x0c0b7fac */
if(!s->budget--) { s->failed_pc=0x0c0b7facu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b80deu,2);
goto P_0c0b7fae;
P_0c0b7fae: /* original 55f1, guest PC 0x0c0b7fae */
if(!s->budget--) { s->failed_pc=0x0c0b7faeu; return 0; }
r[5]=read(ram,r[15]+4,4);
goto P_0c0b7fb0;
P_0c0b7fb0: /* original 4e0b, guest PC 0x0c0b7fb0 */
if(!s->budget--) { s->failed_pc=0x0c0b7fb0u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b7fb4u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b7fb4u) { target=s->pc; goto dispatch; }
goto P_0c0b7fb4;
P_0c0b7fb2: /* original 6552, guest PC 0x0c0b7fb2 */
if(!s->budget--) { s->failed_pc=0x0c0b7fb2u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b7fb4;
P_0c0b7fb4: /* original 9494, guest PC 0x0c0b7fb4 */
if(!s->budget--) { s->failed_pc=0x0c0b7fb4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b80e0u,2);
goto P_0c0b7fb6;
P_0c0b7fb6: /* original 4e0b, guest PC 0x0c0b7fb6 */
if(!s->budget--) { s->failed_pc=0x0c0b7fb6u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b7fbau;
tmp=read(ram,r[9],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b7fbau) { target=s->pc; goto dispatch; }
goto P_0c0b7fba;
P_0c0b7fb8: /* original 6592, guest PC 0x0c0b7fb8 */
if(!s->budget--) { s->failed_pc=0x0c0b7fb8u; return 0; }
tmp=read(ram,r[9],4);
r[5]=tmp;
goto P_0c0b7fba;
P_0c0b7fba: /* original 9492, guest PC 0x0c0b7fba */
if(!s->budget--) { s->failed_pc=0x0c0b7fbau; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b80e2u,2);
goto P_0c0b7fbc;
P_0c0b7fbc: /* original 4e0b, guest PC 0x0c0b7fbc */
if(!s->budget--) { s->failed_pc=0x0c0b7fbcu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b7fc0u;
tmp=read(ram,r[9],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b7fc0u) { target=s->pc; goto dispatch; }
goto P_0c0b7fc0;
P_0c0b7fbe: /* original 6592, guest PC 0x0c0b7fbe */
if(!s->budget--) { s->failed_pc=0x0c0b7fbeu; return 0; }
tmp=read(ram,r[9],4);
r[5]=tmp;
goto P_0c0b7fc0;
P_0c0b7fc0: /* original 9490, guest PC 0x0c0b7fc0 */
if(!s->budget--) { s->failed_pc=0x0c0b7fc0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b80e4u,2);
goto P_0c0b7fc2;
P_0c0b7fc2: /* original 4e0b, guest PC 0x0c0b7fc2 */
if(!s->budget--) { s->failed_pc=0x0c0b7fc2u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b7fc6u;
tmp=read(ram,r[9],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b7fc6u) { target=s->pc; goto dispatch; }
goto P_0c0b7fc6;
P_0c0b7fc4: /* original 6592, guest PC 0x0c0b7fc4 */
if(!s->budget--) { s->failed_pc=0x0c0b7fc4u; return 0; }
tmp=read(ram,r[9],4);
r[5]=tmp;
goto P_0c0b7fc6;
P_0c0b7fc6: /* original 948e, guest PC 0x0c0b7fc6 */
if(!s->budget--) { s->failed_pc=0x0c0b7fc6u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b80e6u,2);
goto P_0c0b7fc8;
P_0c0b7fc8: /* original 4e0b, guest PC 0x0c0b7fc8 */
if(!s->budget--) { s->failed_pc=0x0c0b7fc8u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b7fccu;
tmp=read(ram,r[9],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b7fccu) { target=s->pc; goto dispatch; }
goto P_0c0b7fcc;
P_0c0b7fca: /* original 6592, guest PC 0x0c0b7fca */
if(!s->budget--) { s->failed_pc=0x0c0b7fcau; return 0; }
tmp=read(ram,r[9],4);
r[5]=tmp;
goto P_0c0b7fcc;
P_0c0b7fcc: /* original 948c, guest PC 0x0c0b7fcc */
if(!s->budget--) { s->failed_pc=0x0c0b7fccu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b80e8u,2);
goto P_0c0b7fce;
P_0c0b7fce: /* original 4e0b, guest PC 0x0c0b7fce */
if(!s->budget--) { s->failed_pc=0x0c0b7fceu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b7fd2u;
tmp=read(ram,r[12],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b7fd2u) { target=s->pc; goto dispatch; }
goto P_0c0b7fd2;
P_0c0b7fd0: /* original 65c2, guest PC 0x0c0b7fd0 */
if(!s->budget--) { s->failed_pc=0x0c0b7fd0u; return 0; }
tmp=read(ram,r[12],4);
r[5]=tmp;
goto P_0c0b7fd2;
P_0c0b7fd2: /* original 948a, guest PC 0x0c0b7fd2 */
if(!s->budget--) { s->failed_pc=0x0c0b7fd2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b80eau,2);
goto P_0c0b7fd4;
P_0c0b7fd4: /* original 4e0b, guest PC 0x0c0b7fd4 */
if(!s->budget--) { s->failed_pc=0x0c0b7fd4u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b7fd8u;
tmp=read(ram,r[12],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b7fd8u) { target=s->pc; goto dispatch; }
goto P_0c0b7fd8;
P_0c0b7fd6: /* original 65c2, guest PC 0x0c0b7fd6 */
if(!s->budget--) { s->failed_pc=0x0c0b7fd6u; return 0; }
tmp=read(ram,r[12],4);
r[5]=tmp;
goto P_0c0b7fd8;
P_0c0b7fd8: /* original 9488, guest PC 0x0c0b7fd8 */
if(!s->budget--) { s->failed_pc=0x0c0b7fd8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b80ecu,2);
goto P_0c0b7fda;
P_0c0b7fda: /* original 4e0b, guest PC 0x0c0b7fda */
if(!s->budget--) { s->failed_pc=0x0c0b7fdau; return 0; }
target=r[14];
r[16]=code_base|0x0c0b7fdeu;
tmp=read(ram,r[12],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b7fdeu) { target=s->pc; goto dispatch; }
goto P_0c0b7fde;
P_0c0b7fdc: /* original 65c2, guest PC 0x0c0b7fdc */
if(!s->budget--) { s->failed_pc=0x0c0b7fdcu; return 0; }
tmp=read(ram,r[12],4);
r[5]=tmp;
goto P_0c0b7fde;
P_0c0b7fde: /* original 9486, guest PC 0x0c0b7fde */
if(!s->budget--) { s->failed_pc=0x0c0b7fdeu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b80eeu,2);
goto P_0c0b7fe0;
P_0c0b7fe0: /* original 4e0b, guest PC 0x0c0b7fe0 */
if(!s->budget--) { s->failed_pc=0x0c0b7fe0u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b7fe4u;
tmp=read(ram,r[12],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b7fe4u) { target=s->pc; goto dispatch; }
goto P_0c0b7fe4;
P_0c0b7fe2: /* original 65c2, guest PC 0x0c0b7fe2 */
if(!s->budget--) { s->failed_pc=0x0c0b7fe2u; return 0; }
tmp=read(ram,r[12],4);
r[5]=tmp;
goto P_0c0b7fe4;
P_0c0b7fe4: /* original 9484, guest PC 0x0c0b7fe4 */
if(!s->budget--) { s->failed_pc=0x0c0b7fe4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b80f0u,2);
goto P_0c0b7fe6;
P_0c0b7fe6: /* original 4e0b, guest PC 0x0c0b7fe6 */
if(!s->budget--) { s->failed_pc=0x0c0b7fe6u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b7feau;
tmp=read(ram,r[11],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b7feau) { target=s->pc; goto dispatch; }
goto P_0c0b7fea;
P_0c0b7fe8: /* original 65b2, guest PC 0x0c0b7fe8 */
if(!s->budget--) { s->failed_pc=0x0c0b7fe8u; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
goto P_0c0b7fea;
P_0c0b7fea: /* original 9482, guest PC 0x0c0b7fea */
if(!s->budget--) { s->failed_pc=0x0c0b7feau; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b80f2u,2);
goto P_0c0b7fec;
P_0c0b7fec: /* original 4e0b, guest PC 0x0c0b7fec */
if(!s->budget--) { s->failed_pc=0x0c0b7fecu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b7ff0u;
tmp=read(ram,r[11],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b7ff0u) { target=s->pc; goto dispatch; }
goto P_0c0b7ff0;
P_0c0b7fee: /* original 65b2, guest PC 0x0c0b7fee */
if(!s->budget--) { s->failed_pc=0x0c0b7feeu; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
goto P_0c0b7ff0;
P_0c0b7ff0: /* original 9480, guest PC 0x0c0b7ff0 */
if(!s->budget--) { s->failed_pc=0x0c0b7ff0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b80f4u,2);
goto P_0c0b7ff2;
P_0c0b7ff2: /* original 4e0b, guest PC 0x0c0b7ff2 */
if(!s->budget--) { s->failed_pc=0x0c0b7ff2u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b7ff6u;
tmp=read(ram,r[11],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b7ff6u) { target=s->pc; goto dispatch; }
goto P_0c0b7ff6;
P_0c0b7ff4: /* original 65b2, guest PC 0x0c0b7ff4 */
if(!s->budget--) { s->failed_pc=0x0c0b7ff4u; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
goto P_0c0b7ff6;
P_0c0b7ff6: /* original 947e, guest PC 0x0c0b7ff6 */
if(!s->budget--) { s->failed_pc=0x0c0b7ff6u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b80f6u,2);
goto P_0c0b7ff8;
P_0c0b7ff8: /* original 4e0b, guest PC 0x0c0b7ff8 */
if(!s->budget--) { s->failed_pc=0x0c0b7ff8u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b7ffcu;
tmp=read(ram,r[11],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b7ffcu) { target=s->pc; goto dispatch; }
goto P_0c0b7ffc;
P_0c0b7ffa: /* original 65b2, guest PC 0x0c0b7ffa */
if(!s->budget--) { s->failed_pc=0x0c0b7ffau; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
goto P_0c0b7ffc;
P_0c0b7ffc: /* original 947c, guest PC 0x0c0b7ffc */
if(!s->budget--) { s->failed_pc=0x0c0b7ffcu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b80f8u,2);
goto P_0c0b7ffe;
P_0c0b7ffe: /* original 4e0b, guest PC 0x0c0b7ffe */
if(!s->budget--) { s->failed_pc=0x0c0b7ffeu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b8002u;
tmp=read(ram,r[10],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b8002u) { target=s->pc; goto dispatch; }
goto P_0c0b8002;
P_0c0b8000: /* original 65a2, guest PC 0x0c0b8000 */
if(!s->budget--) { s->failed_pc=0x0c0b8000u; return 0; }
tmp=read(ram,r[10],4);
r[5]=tmp;
goto P_0c0b8002;
P_0c0b8002: /* original 947a, guest PC 0x0c0b8002 */
if(!s->budget--) { s->failed_pc=0x0c0b8002u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b80fau,2);
goto P_0c0b8004;
P_0c0b8004: /* original 4e0b, guest PC 0x0c0b8004 */
if(!s->budget--) { s->failed_pc=0x0c0b8004u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b8008u;
tmp=read(ram,r[10],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b8008u) { target=s->pc; goto dispatch; }
goto P_0c0b8008;
P_0c0b8006: /* original 65a2, guest PC 0x0c0b8006 */
if(!s->budget--) { s->failed_pc=0x0c0b8006u; return 0; }
tmp=read(ram,r[10],4);
r[5]=tmp;
goto P_0c0b8008;
P_0c0b8008: /* original 9478, guest PC 0x0c0b8008 */
if(!s->budget--) { s->failed_pc=0x0c0b8008u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b80fcu,2);
goto P_0c0b800a;
P_0c0b800a: /* original 4e0b, guest PC 0x0c0b800a */
if(!s->budget--) { s->failed_pc=0x0c0b800au; return 0; }
target=r[14];
r[16]=code_base|0x0c0b800eu;
tmp=read(ram,r[10],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b800eu) { target=s->pc; goto dispatch; }
goto P_0c0b800e;
P_0c0b800c: /* original 65a2, guest PC 0x0c0b800c */
if(!s->budget--) { s->failed_pc=0x0c0b800cu; return 0; }
tmp=read(ram,r[10],4);
r[5]=tmp;
goto P_0c0b800e;
P_0c0b800e: /* original 9476, guest PC 0x0c0b800e */
if(!s->budget--) { s->failed_pc=0x0c0b800eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b80feu,2);
goto P_0c0b8010;
P_0c0b8010: /* original 4e0b, guest PC 0x0c0b8010 */
if(!s->budget--) { s->failed_pc=0x0c0b8010u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b8014u;
tmp=read(ram,r[10],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b8014u) { target=s->pc; goto dispatch; }
goto P_0c0b8014;
P_0c0b8012: /* original 65a2, guest PC 0x0c0b8012 */
if(!s->budget--) { s->failed_pc=0x0c0b8012u; return 0; }
tmp=read(ram,r[10],4);
r[5]=tmp;
goto P_0c0b8014;
P_0c0b8014: /* original 9574, guest PC 0x0c0b8014 */
if(!s->budget--) { s->failed_pc=0x0c0b8014u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b8100u,2);
goto P_0c0b8016;
P_0c0b8016: /* original 35dc, guest PC 0x0c0b8016 */
if(!s->budget--) { s->failed_pc=0x0c0b8016u; return 0; }
r[5]+=r[13];
goto P_0c0b8018;
P_0c0b8018: /* original 2f52, guest PC 0x0c0b8018 */
if(!s->budget--) { s->failed_pc=0x0c0b8018u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0b801a;
P_0c0b801a: /* original 9472, guest PC 0x0c0b801a */
if(!s->budget--) { s->failed_pc=0x0c0b801au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b8102u,2);
goto P_0c0b801c;
P_0c0b801c: /* original 4e0b, guest PC 0x0c0b801c */
if(!s->budget--) { s->failed_pc=0x0c0b801cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b8020u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b8020u) { target=s->pc; goto dispatch; }
goto P_0c0b8020;
P_0c0b801e: /* original 6552, guest PC 0x0c0b801e */
if(!s->budget--) { s->failed_pc=0x0c0b801eu; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b8020;
P_0c0b8020: /* original 9470, guest PC 0x0c0b8020 */
if(!s->budget--) { s->failed_pc=0x0c0b8020u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b8104u,2);
goto P_0c0b8022;
P_0c0b8022: /* original 65f2, guest PC 0x0c0b8022 */
if(!s->budget--) { s->failed_pc=0x0c0b8022u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0b8024;
P_0c0b8024: /* original 4e0b, guest PC 0x0c0b8024 */
if(!s->budget--) { s->failed_pc=0x0c0b8024u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b8028u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b8028u) { target=s->pc; goto dispatch; }
goto P_0c0b8028;
P_0c0b8026: /* original 6552, guest PC 0x0c0b8026 */
if(!s->budget--) { s->failed_pc=0x0c0b8026u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b8028;
P_0c0b8028: /* original 956d, guest PC 0x0c0b8028 */
if(!s->budget--) { s->failed_pc=0x0c0b8028u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b8106u,2);
goto P_0c0b802a;
P_0c0b802a: /* original 35dc, guest PC 0x0c0b802a */
if(!s->budget--) { s->failed_pc=0x0c0b802au; return 0; }
r[5]+=r[13];
goto P_0c0b802c;
P_0c0b802c: /* original 2f52, guest PC 0x0c0b802c */
if(!s->budget--) { s->failed_pc=0x0c0b802cu; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0b802e;
P_0c0b802e: /* original 946b, guest PC 0x0c0b802e */
if(!s->budget--) { s->failed_pc=0x0c0b802eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b8108u,2);
goto P_0c0b8030;
P_0c0b8030: /* original 4e0b, guest PC 0x0c0b8030 */
if(!s->budget--) { s->failed_pc=0x0c0b8030u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b8034u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b8034u) { target=s->pc; goto dispatch; }
goto P_0c0b8034;
P_0c0b8032: /* original 6552, guest PC 0x0c0b8032 */
if(!s->budget--) { s->failed_pc=0x0c0b8032u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b8034;
P_0c0b8034: /* original 9469, guest PC 0x0c0b8034 */
if(!s->budget--) { s->failed_pc=0x0c0b8034u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b810au,2);
goto P_0c0b8036;
P_0c0b8036: /* original 65f2, guest PC 0x0c0b8036 */
if(!s->budget--) { s->failed_pc=0x0c0b8036u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0b8038;
P_0c0b8038: /* original 4e0b, guest PC 0x0c0b8038 */
if(!s->budget--) { s->failed_pc=0x0c0b8038u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b803cu;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b803cu) { target=s->pc; goto dispatch; }
goto P_0c0b803c;
P_0c0b803a: /* original 6552, guest PC 0x0c0b803a */
if(!s->budget--) { s->failed_pc=0x0c0b803au; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b803c;
P_0c0b803c: /* original 9467, guest PC 0x0c0b803c */
if(!s->budget--) { s->failed_pc=0x0c0b803cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b810eu,2);
goto P_0c0b803e;
P_0c0b803e: /* original 9065, guest PC 0x0c0b803e */
if(!s->budget--) { s->failed_pc=0x0c0b803eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b810cu,2);
goto P_0c0b8040;
P_0c0b8040: /* original 4e0b, guest PC 0x0c0b8040 */
if(!s->budget--) { s->failed_pc=0x0c0b8040u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b8044u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b8044u) { target=s->pc; goto dispatch; }
goto P_0c0b8044;
P_0c0b8042: /* original 05de, guest PC 0x0c0b8042 */
if(!s->budget--) { s->failed_pc=0x0c0b8042u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b8044;
P_0c0b8044: /* original 9564, guest PC 0x0c0b8044 */
if(!s->budget--) { s->failed_pc=0x0c0b8044u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b8110u,2);
goto P_0c0b8046;
P_0c0b8046: /* original 35dc, guest PC 0x0c0b8046 */
if(!s->budget--) { s->failed_pc=0x0c0b8046u; return 0; }
r[5]+=r[13];
goto P_0c0b8048;
P_0c0b8048: /* original 2f52, guest PC 0x0c0b8048 */
if(!s->budget--) { s->failed_pc=0x0c0b8048u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0b804a;
P_0c0b804a: /* original 9462, guest PC 0x0c0b804a */
if(!s->budget--) { s->failed_pc=0x0c0b804au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b8112u,2);
goto P_0c0b804c;
P_0c0b804c: /* original 4e0b, guest PC 0x0c0b804c */
if(!s->budget--) { s->failed_pc=0x0c0b804cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b8050u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b8050u) { target=s->pc; goto dispatch; }
goto P_0c0b8050;
P_0c0b804e: /* original 6552, guest PC 0x0c0b804e */
if(!s->budget--) { s->failed_pc=0x0c0b804eu; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b8050;
P_0c0b8050: /* original 9460, guest PC 0x0c0b8050 */
if(!s->budget--) { s->failed_pc=0x0c0b8050u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b8114u,2);
goto P_0c0b8052;
P_0c0b8052: /* original 65f2, guest PC 0x0c0b8052 */
if(!s->budget--) { s->failed_pc=0x0c0b8052u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0b8054;
P_0c0b8054: /* original 4e0b, guest PC 0x0c0b8054 */
if(!s->budget--) { s->failed_pc=0x0c0b8054u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b8058u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b8058u) { target=s->pc; goto dispatch; }
goto P_0c0b8058;
P_0c0b8056: /* original 6552, guest PC 0x0c0b8056 */
if(!s->budget--) { s->failed_pc=0x0c0b8056u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b8058;
P_0c0b8058: /* original 945e, guest PC 0x0c0b8058 */
if(!s->budget--) { s->failed_pc=0x0c0b8058u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b8118u,2);
goto P_0c0b805a;
P_0c0b805a: /* original 905c, guest PC 0x0c0b805a */
if(!s->budget--) { s->failed_pc=0x0c0b805au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b8116u,2);
goto P_0c0b805c;
P_0c0b805c: /* original 4e0b, guest PC 0x0c0b805c */
if(!s->budget--) { s->failed_pc=0x0c0b805cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b8060u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b8060u) { target=s->pc; goto dispatch; }
goto P_0c0b8060;
P_0c0b805e: /* original 05de, guest PC 0x0c0b805e */
if(!s->budget--) { s->failed_pc=0x0c0b805eu; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b8060;
P_0c0b8060: /* original 955b, guest PC 0x0c0b8060 */
if(!s->budget--) { s->failed_pc=0x0c0b8060u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b811au,2);
goto P_0c0b8062;
P_0c0b8062: /* original 35dc, guest PC 0x0c0b8062 */
if(!s->budget--) { s->failed_pc=0x0c0b8062u; return 0; }
r[5]+=r[13];
goto P_0c0b8064;
P_0c0b8064: /* original 2f52, guest PC 0x0c0b8064 */
if(!s->budget--) { s->failed_pc=0x0c0b8064u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0b8066;
P_0c0b8066: /* original 9459, guest PC 0x0c0b8066 */
if(!s->budget--) { s->failed_pc=0x0c0b8066u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b811cu,2);
goto P_0c0b8068;
P_0c0b8068: /* original 4e0b, guest PC 0x0c0b8068 */
if(!s->budget--) { s->failed_pc=0x0c0b8068u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b806cu;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b806cu) { target=s->pc; goto dispatch; }
goto P_0c0b806c;
P_0c0b806a: /* original 6552, guest PC 0x0c0b806a */
if(!s->budget--) { s->failed_pc=0x0c0b806au; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b806c;
P_0c0b806c: /* original 9457, guest PC 0x0c0b806c */
if(!s->budget--) { s->failed_pc=0x0c0b806cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b811eu,2);
goto P_0c0b806e;
P_0c0b806e: /* original 65f2, guest PC 0x0c0b806e */
if(!s->budget--) { s->failed_pc=0x0c0b806eu; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0b8070;
P_0c0b8070: /* original 4e0b, guest PC 0x0c0b8070 */
if(!s->budget--) { s->failed_pc=0x0c0b8070u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b8074u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b8074u) { target=s->pc; goto dispatch; }
goto P_0c0b8074;
P_0c0b8072: /* original 6552, guest PC 0x0c0b8072 */
if(!s->budget--) { s->failed_pc=0x0c0b8072u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b8074;
P_0c0b8074: /* original 9455, guest PC 0x0c0b8074 */
if(!s->budget--) { s->failed_pc=0x0c0b8074u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b8122u,2);
goto P_0c0b8076;
P_0c0b8076: /* original 9053, guest PC 0x0c0b8076 */
if(!s->budget--) { s->failed_pc=0x0c0b8076u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b8120u,2);
goto P_0c0b8078;
P_0c0b8078: /* original 4e0b, guest PC 0x0c0b8078 */
if(!s->budget--) { s->failed_pc=0x0c0b8078u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b807cu;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b807cu) { target=s->pc; goto dispatch; }
goto P_0c0b807c;
P_0c0b807a: /* original 05de, guest PC 0x0c0b807a */
if(!s->budget--) { s->failed_pc=0x0c0b807au; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b807c;
P_0c0b807c: /* original 9552, guest PC 0x0c0b807c */
if(!s->budget--) { s->failed_pc=0x0c0b807cu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b8124u,2);
goto P_0c0b807e;
P_0c0b807e: /* original 35dc, guest PC 0x0c0b807e */
if(!s->budget--) { s->failed_pc=0x0c0b807eu; return 0; }
r[5]+=r[13];
goto P_0c0b8080;
P_0c0b8080: /* original 2f52, guest PC 0x0c0b8080 */
if(!s->budget--) { s->failed_pc=0x0c0b8080u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0b8082;
P_0c0b8082: /* original 9450, guest PC 0x0c0b8082 */
if(!s->budget--) { s->failed_pc=0x0c0b8082u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b8126u,2);
goto P_0c0b8084;
P_0c0b8084: /* original 4e0b, guest PC 0x0c0b8084 */
if(!s->budget--) { s->failed_pc=0x0c0b8084u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b8088u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b8088u) { target=s->pc; goto dispatch; }
goto P_0c0b8088;
P_0c0b8086: /* original 6552, guest PC 0x0c0b8086 */
if(!s->budget--) { s->failed_pc=0x0c0b8086u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b8088;
P_0c0b8088: /* original 944e, guest PC 0x0c0b8088 */
if(!s->budget--) { s->failed_pc=0x0c0b8088u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b8128u,2);
goto P_0c0b808a;
P_0c0b808a: /* original 65f2, guest PC 0x0c0b808a */
if(!s->budget--) { s->failed_pc=0x0c0b808au; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0b808c;
P_0c0b808c: /* original 4e0b, guest PC 0x0c0b808c */
if(!s->budget--) { s->failed_pc=0x0c0b808cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b8090u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b8090u) { target=s->pc; goto dispatch; }
goto P_0c0b8090;
P_0c0b808e: /* original 6552, guest PC 0x0c0b808e */
if(!s->budget--) { s->failed_pc=0x0c0b808eu; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b8090;
P_0c0b8090: /* original 954b, guest PC 0x0c0b8090 */
if(!s->budget--) { s->failed_pc=0x0c0b8090u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b812au,2);
goto P_0c0b8092;
P_0c0b8092: /* original 35dc, guest PC 0x0c0b8092 */
if(!s->budget--) { s->failed_pc=0x0c0b8092u; return 0; }
r[5]+=r[13];
goto P_0c0b8094;
P_0c0b8094: /* original 2f52, guest PC 0x0c0b8094 */
if(!s->budget--) { s->failed_pc=0x0c0b8094u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0b8096;
P_0c0b8096: /* original 9449, guest PC 0x0c0b8096 */
if(!s->budget--) { s->failed_pc=0x0c0b8096u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b812cu,2);
goto P_0c0b8098;
P_0c0b8098: /* original 4e0b, guest PC 0x0c0b8098 */
if(!s->budget--) { s->failed_pc=0x0c0b8098u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b809cu;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b809cu) { target=s->pc; goto dispatch; }
goto P_0c0b809c;
P_0c0b809a: /* original 6552, guest PC 0x0c0b809a */
if(!s->budget--) { s->failed_pc=0x0c0b809au; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b809c;
P_0c0b809c: /* original 9447, guest PC 0x0c0b809c */
if(!s->budget--) { s->failed_pc=0x0c0b809cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b812eu,2);
goto P_0c0b809e;
P_0c0b809e: /* original 65f2, guest PC 0x0c0b809e */
if(!s->budget--) { s->failed_pc=0x0c0b809eu; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0b80a0;
P_0c0b80a0: /* original 4e0b, guest PC 0x0c0b80a0 */
if(!s->budget--) { s->failed_pc=0x0c0b80a0u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b80a4u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b80a4u) { target=s->pc; goto dispatch; }
goto P_0c0b80a4;
P_0c0b80a2: /* original 6552, guest PC 0x0c0b80a2 */
if(!s->budget--) { s->failed_pc=0x0c0b80a2u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b80a4;
P_0c0b80a4: /* original 9445, guest PC 0x0c0b80a4 */
if(!s->budget--) { s->failed_pc=0x0c0b80a4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b8132u,2);
goto P_0c0b80a6;
P_0c0b80a6: /* original 9043, guest PC 0x0c0b80a6 */
if(!s->budget--) { s->failed_pc=0x0c0b80a6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b8130u,2);
goto P_0c0b80a8;
P_0c0b80a8: /* original 4e0b, guest PC 0x0c0b80a8 */
if(!s->budget--) { s->failed_pc=0x0c0b80a8u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b80acu;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b80acu) { target=s->pc; goto dispatch; }
goto P_0c0b80ac;
P_0c0b80aa: /* original 05de, guest PC 0x0c0b80aa */
if(!s->budget--) { s->failed_pc=0x0c0b80aau; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b80ac;
P_0c0b80ac: /* original 9443, guest PC 0x0c0b80ac */
if(!s->budget--) { s->failed_pc=0x0c0b80acu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b8136u,2);
goto P_0c0b80ae;
P_0c0b80ae: /* original 9041, guest PC 0x0c0b80ae */
if(!s->budget--) { s->failed_pc=0x0c0b80aeu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b8134u,2);
goto P_0c0b80b0;
P_0c0b80b0: /* original 4e0b, guest PC 0x0c0b80b0 */
if(!s->budget--) { s->failed_pc=0x0c0b80b0u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b80b4u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b80b4u) { target=s->pc; goto dispatch; }
goto P_0c0b80b4;
P_0c0b80b2: /* original 05de, guest PC 0x0c0b80b2 */
if(!s->budget--) { s->failed_pc=0x0c0b80b2u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b80b4;
P_0c0b80b4: /* original 9441, guest PC 0x0c0b80b4 */
if(!s->budget--) { s->failed_pc=0x0c0b80b4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b813au,2);
goto P_0c0b80b6;
P_0c0b80b6: /* original 903f, guest PC 0x0c0b80b6 */
if(!s->budget--) { s->failed_pc=0x0c0b80b6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b8138u,2);
goto P_0c0b80b8;
P_0c0b80b8: /* original 4e0b, guest PC 0x0c0b80b8 */
if(!s->budget--) { s->failed_pc=0x0c0b80b8u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b80bcu;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b80bcu) { target=s->pc; goto dispatch; }
goto P_0c0b80bc;
P_0c0b80ba: /* original 05de, guest PC 0x0c0b80ba */
if(!s->budget--) { s->failed_pc=0x0c0b80bau; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b80bc;
P_0c0b80bc: /* original 943f, guest PC 0x0c0b80bc */
if(!s->budget--) { s->failed_pc=0x0c0b80bcu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b813eu,2);
goto P_0c0b80be;
P_0c0b80be: /* original 903d, guest PC 0x0c0b80be */
if(!s->budget--) { s->failed_pc=0x0c0b80beu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b813cu,2);
goto P_0c0b80c0;
P_0c0b80c0: /* original 4e0b, guest PC 0x0c0b80c0 */
if(!s->budget--) { s->failed_pc=0x0c0b80c0u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b80c4u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b80c4u) { target=s->pc; goto dispatch; }
goto P_0c0b80c4;
P_0c0b80c2: /* original 05de, guest PC 0x0c0b80c2 */
if(!s->budget--) { s->failed_pc=0x0c0b80c2u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b80c4;
P_0c0b80c4: /* original 903c, guest PC 0x0c0b80c4 */
if(!s->budget--) { s->failed_pc=0x0c0b80c4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b8140u,2);
goto P_0c0b80c6;
P_0c0b80c6: /* original a03c, guest PC 0x0c0b80c6 */
if(!s->budget--) { s->failed_pc=0x0c0b80c6u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b8142;
P_0c0b80c8: /* original 05de, guest PC 0x0c0b80c8 */
if(!s->budget--) { s->failed_pc=0x0c0b80c8u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
if(!vf3_matrix_family(0x0c0b80cau,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0b80cau; return 0; } return 1;
P_0c0b8142: /* original 942e, guest PC 0x0c0b8142 */
if(!s->budget--) { s->failed_pc=0x0c0b8142u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b81a2u,2);
goto P_0c0b8144;
P_0c0b8144: /* original 4e0b, guest PC 0x0c0b8144 */
if(!s->budget--) { s->failed_pc=0x0c0b8144u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b8148u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b8148u) { target=s->pc; goto dispatch; }
goto P_0c0b8148;
P_0c0b8146: /* original 0009, guest PC 0x0c0b8146 */
if(!s->budget--) { s->failed_pc=0x0c0b8146u; return 0; }
goto P_0c0b8148;
P_0c0b8148: /* original 942d, guest PC 0x0c0b8148 */
if(!s->budget--) { s->failed_pc=0x0c0b8148u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b81a6u,2);
goto P_0c0b814a;
P_0c0b814a: /* original 902b, guest PC 0x0c0b814a */
if(!s->budget--) { s->failed_pc=0x0c0b814au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b81a4u,2);
goto P_0c0b814c;
P_0c0b814c: /* original 4e0b, guest PC 0x0c0b814c */
if(!s->budget--) { s->failed_pc=0x0c0b814cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b8150u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b8150u) { target=s->pc; goto dispatch; }
goto P_0c0b8150;
P_0c0b814e: /* original 05de, guest PC 0x0c0b814e */
if(!s->budget--) { s->failed_pc=0x0c0b814eu; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b8150;
P_0c0b8150: /* original 942b, guest PC 0x0c0b8150 */
if(!s->budget--) { s->failed_pc=0x0c0b8150u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b81aau,2);
goto P_0c0b8152;
P_0c0b8152: /* original 9029, guest PC 0x0c0b8152 */
if(!s->budget--) { s->failed_pc=0x0c0b8152u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b81a8u,2);
goto P_0c0b8154;
P_0c0b8154: /* original 4e0b, guest PC 0x0c0b8154 */
if(!s->budget--) { s->failed_pc=0x0c0b8154u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b8158u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b8158u) { target=s->pc; goto dispatch; }
goto P_0c0b8158;
P_0c0b8156: /* original 05de, guest PC 0x0c0b8156 */
if(!s->budget--) { s->failed_pc=0x0c0b8156u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b8158;
P_0c0b8158: /* original 9429, guest PC 0x0c0b8158 */
if(!s->budget--) { s->failed_pc=0x0c0b8158u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b81aeu,2);
goto P_0c0b815a;
P_0c0b815a: /* original 9027, guest PC 0x0c0b815a */
if(!s->budget--) { s->failed_pc=0x0c0b815au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b81acu,2);
goto P_0c0b815c;
P_0c0b815c: /* original 4e0b, guest PC 0x0c0b815c */
if(!s->budget--) { s->failed_pc=0x0c0b815cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b8160u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b8160u) { target=s->pc; goto dispatch; }
goto P_0c0b8160;
P_0c0b815e: /* original 05de, guest PC 0x0c0b815e */
if(!s->budget--) { s->failed_pc=0x0c0b815eu; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b8160;
P_0c0b8160: /* original 9427, guest PC 0x0c0b8160 */
if(!s->budget--) { s->failed_pc=0x0c0b8160u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b81b2u,2);
goto P_0c0b8162;
P_0c0b8162: /* original 9025, guest PC 0x0c0b8162 */
if(!s->budget--) { s->failed_pc=0x0c0b8162u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b81b0u,2);
goto P_0c0b8164;
P_0c0b8164: /* original 4e0b, guest PC 0x0c0b8164 */
if(!s->budget--) { s->failed_pc=0x0c0b8164u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b8168u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b8168u) { target=s->pc; goto dispatch; }
goto P_0c0b8168;
P_0c0b8166: /* original 05de, guest PC 0x0c0b8166 */
if(!s->budget--) { s->failed_pc=0x0c0b8166u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b8168;
P_0c0b8168: /* original 9425, guest PC 0x0c0b8168 */
if(!s->budget--) { s->failed_pc=0x0c0b8168u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b81b6u,2);
goto P_0c0b816a;
P_0c0b816a: /* original 9023, guest PC 0x0c0b816a */
if(!s->budget--) { s->failed_pc=0x0c0b816au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b81b4u,2);
goto P_0c0b816c;
P_0c0b816c: /* original 4e0b, guest PC 0x0c0b816c */
if(!s->budget--) { s->failed_pc=0x0c0b816cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b8170u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b8170u) { target=s->pc; goto dispatch; }
goto P_0c0b8170;
P_0c0b816e: /* original 05de, guest PC 0x0c0b816e */
if(!s->budget--) { s->failed_pc=0x0c0b816eu; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b8170;
P_0c0b8170: /* original 9423, guest PC 0x0c0b8170 */
if(!s->budget--) { s->failed_pc=0x0c0b8170u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b81bau,2);
goto P_0c0b8172;
P_0c0b8172: /* original 9021, guest PC 0x0c0b8172 */
if(!s->budget--) { s->failed_pc=0x0c0b8172u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b81b8u,2);
goto P_0c0b8174;
P_0c0b8174: /* original 4e0b, guest PC 0x0c0b8174 */
if(!s->budget--) { s->failed_pc=0x0c0b8174u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b8178u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b8178u) { target=s->pc; goto dispatch; }
goto P_0c0b8178;
P_0c0b8176: /* original 05de, guest PC 0x0c0b8176 */
if(!s->budget--) { s->failed_pc=0x0c0b8176u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b8178;
P_0c0b8178: /* original 9421, guest PC 0x0c0b8178 */
if(!s->budget--) { s->failed_pc=0x0c0b8178u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b81beu,2);
goto P_0c0b817a;
P_0c0b817a: /* original 901f, guest PC 0x0c0b817a */
if(!s->budget--) { s->failed_pc=0x0c0b817au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b81bcu,2);
goto P_0c0b817c;
P_0c0b817c: /* original 4e0b, guest PC 0x0c0b817c */
if(!s->budget--) { s->failed_pc=0x0c0b817cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b8180u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b8180u) { target=s->pc; goto dispatch; }
goto P_0c0b8180;
P_0c0b817e: /* original 05de, guest PC 0x0c0b817e */
if(!s->budget--) { s->failed_pc=0x0c0b817eu; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b8180;
P_0c0b8180: /* original 941f, guest PC 0x0c0b8180 */
if(!s->budget--) { s->failed_pc=0x0c0b8180u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b81c2u,2);
goto P_0c0b8182;
P_0c0b8182: /* original 901d, guest PC 0x0c0b8182 */
if(!s->budget--) { s->failed_pc=0x0c0b8182u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b81c0u,2);
goto P_0c0b8184;
P_0c0b8184: /* original 4e0b, guest PC 0x0c0b8184 */
if(!s->budget--) { s->failed_pc=0x0c0b8184u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b8188u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b8188u) { target=s->pc; goto dispatch; }
goto P_0c0b8188;
P_0c0b8186: /* original 05de, guest PC 0x0c0b8186 */
if(!s->budget--) { s->failed_pc=0x0c0b8186u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b8188;
P_0c0b8188: /* original 941d, guest PC 0x0c0b8188 */
if(!s->budget--) { s->failed_pc=0x0c0b8188u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b81c6u,2);
goto P_0c0b818a;
P_0c0b818a: /* original 901b, guest PC 0x0c0b818a */
if(!s->budget--) { s->failed_pc=0x0c0b818au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b81c4u,2);
goto P_0c0b818c;
P_0c0b818c: /* original 4e0b, guest PC 0x0c0b818c */
if(!s->budget--) { s->failed_pc=0x0c0b818cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b8190u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b8190u) { target=s->pc; goto dispatch; }
goto P_0c0b8190;
P_0c0b818e: /* original 05de, guest PC 0x0c0b818e */
if(!s->budget--) { s->failed_pc=0x0c0b818eu; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b8190;
P_0c0b8190: /* original 7f08, guest PC 0x0c0b8190 */
if(!s->budget--) { s->failed_pc=0x0c0b8190u; return 0; }
r[15]+=0x00000008u;
goto P_0c0b8192;
P_0c0b8192: /* original 4f26, guest PC 0x0c0b8192 */
if(!s->budget--) { s->failed_pc=0x0c0b8192u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0b8194;
P_0c0b8194: /* original 69f6, guest PC 0x0c0b8194 */
if(!s->budget--) { s->failed_pc=0x0c0b8194u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0b8196;
P_0c0b8196: /* original 6af6, guest PC 0x0c0b8196 */
if(!s->budget--) { s->failed_pc=0x0c0b8196u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0b8198;
P_0c0b8198: /* original 6bf6, guest PC 0x0c0b8198 */
if(!s->budget--) { s->failed_pc=0x0c0b8198u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0b819a;
P_0c0b819a: /* original 6cf6, guest PC 0x0c0b819a */
if(!s->budget--) { s->failed_pc=0x0c0b819au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0b819c;
P_0c0b819c: /* original 6df6, guest PC 0x0c0b819c */
if(!s->budget--) { s->failed_pc=0x0c0b819cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0b819e;
P_0c0b819e: /* original 000b, guest PC 0x0c0b819e */
if(!s->budget--) { s->failed_pc=0x0c0b819eu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0b81a0: /* original 6ef6, guest PC 0x0c0b81a0 */
if(!s->budget--) { s->failed_pc=0x0c0b81a0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0b81a2u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0b81a2u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
