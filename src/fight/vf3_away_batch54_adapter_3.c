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
int vf3_away_batch54_adapter_3(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c087e04u: goto P_0c087e04;
case 0x0c087e06u: goto P_0c087e06;
case 0x0c087e08u: goto P_0c087e08;
case 0x0c087e0au: goto P_0c087e0a;
case 0x0c087e0cu: goto P_0c087e0c;
case 0x0c087e0eu: goto P_0c087e0e;
case 0x0c087e10u: goto P_0c087e10;
case 0x0c087e12u: goto P_0c087e12;
case 0x0c087e14u: goto P_0c087e14;
case 0x0c087e16u: goto P_0c087e16;
case 0x0c087e18u: goto P_0c087e18;
case 0x0c087e1au: goto P_0c087e1a;
case 0x0c087e1cu: goto P_0c087e1c;
case 0x0c087e1eu: goto P_0c087e1e;
case 0x0c087e20u: goto P_0c087e20;
case 0x0c087e22u: goto P_0c087e22;
case 0x0c087e24u: goto P_0c087e24;
case 0x0c087e26u: goto P_0c087e26;
case 0x0c087e28u: goto P_0c087e28;
case 0x0c087e2au: goto P_0c087e2a;
case 0x0c087e2cu: goto P_0c087e2c;
case 0x0c087e2eu: goto P_0c087e2e;
case 0x0c087e30u: goto P_0c087e30;
case 0x0c087e32u: goto P_0c087e32;
case 0x0c087e34u: goto P_0c087e34;
case 0x0c087e36u: goto P_0c087e36;
case 0x0c087e38u: goto P_0c087e38;
case 0x0c087e3au: goto P_0c087e3a;
case 0x0c087e3cu: goto P_0c087e3c;
case 0x0c087e3eu: goto P_0c087e3e;
case 0x0c087e40u: goto P_0c087e40;
case 0x0c087e42u: goto P_0c087e42;
case 0x0c087e44u: goto P_0c087e44;
case 0x0c087e46u: goto P_0c087e46;
case 0x0c087e48u: goto P_0c087e48;
case 0x0c087e4au: goto P_0c087e4a;
case 0x0c087e4cu: goto P_0c087e4c;
case 0x0c087e4eu: goto P_0c087e4e;
case 0x0c087e50u: goto P_0c087e50;
case 0x0c087e52u: goto P_0c087e52;
case 0x0c087e54u: goto P_0c087e54;
case 0x0c087e56u: goto P_0c087e56;
case 0x0c087e58u: goto P_0c087e58;
case 0x0c087e5au: goto P_0c087e5a;
case 0x0c087e5cu: goto P_0c087e5c;
case 0x0c087e5eu: goto P_0c087e5e;
case 0x0c087e60u: goto P_0c087e60;
case 0x0c087e62u: goto P_0c087e62;
case 0x0c087e64u: goto P_0c087e64;
case 0x0c087e66u: goto P_0c087e66;
case 0x0c087e68u: goto P_0c087e68;
case 0x0c087e6au: goto P_0c087e6a;
case 0x0c087e6cu: goto P_0c087e6c;
case 0x0c087e6eu: goto P_0c087e6e;
case 0x0c087e70u: goto P_0c087e70;
case 0x0c087e72u: goto P_0c087e72;
case 0x0c087e74u: goto P_0c087e74;
case 0x0c087e76u: goto P_0c087e76;
case 0x0c087e78u: goto P_0c087e78;
case 0x0c087e7au: goto P_0c087e7a;
case 0x0c087e7cu: goto P_0c087e7c;
case 0x0c087e7eu: goto P_0c087e7e;
case 0x0c087e80u: goto P_0c087e80;
case 0x0c087e82u: goto P_0c087e82;
case 0x0c087e84u: goto P_0c087e84;
case 0x0c087e86u: goto P_0c087e86;
case 0x0c087e88u: goto P_0c087e88;
case 0x0c087e8au: goto P_0c087e8a;
case 0x0c087e8cu: goto P_0c087e8c;
case 0x0c087e8eu: goto P_0c087e8e;
case 0x0c087e90u: goto P_0c087e90;
case 0x0c087e92u: goto P_0c087e92;
case 0x0c087e94u: goto P_0c087e94;
case 0x0c087e96u: goto P_0c087e96;
case 0x0c087e98u: goto P_0c087e98;
case 0x0c087e9au: goto P_0c087e9a;
case 0x0c087e9cu: goto P_0c087e9c;
case 0x0c087e9eu: goto P_0c087e9e;
case 0x0c087ea0u: goto P_0c087ea0;
case 0x0c087ebcu: goto P_0c087ebc;
case 0x0c087ebeu: goto P_0c087ebe;
case 0x0c087ec0u: goto P_0c087ec0;
case 0x0c087ec2u: goto P_0c087ec2;
case 0x0c087ec4u: goto P_0c087ec4;
case 0x0c087ec6u: goto P_0c087ec6;
case 0x0c087ec8u: goto P_0c087ec8;
case 0x0c087ecau: goto P_0c087eca;
case 0x0c087eccu: goto P_0c087ecc;
case 0x0c087eceu: goto P_0c087ece;
case 0x0c087ed0u: goto P_0c087ed0;
case 0x0c087ed2u: goto P_0c087ed2;
case 0x0c087ed4u: goto P_0c087ed4;
case 0x0c087ed6u: goto P_0c087ed6;
case 0x0c087ed8u: goto P_0c087ed8;
case 0x0c087edau: goto P_0c087eda;
case 0x0c087edcu: goto P_0c087edc;
case 0x0c087edeu: goto P_0c087ede;
case 0x0c087ee0u: goto P_0c087ee0;
case 0x0c087ee2u: goto P_0c087ee2;
case 0x0c087ee4u: goto P_0c087ee4;
case 0x0c087ee6u: goto P_0c087ee6;
case 0x0c087ee8u: goto P_0c087ee8;
case 0x0c087eeau: goto P_0c087eea;
case 0x0c087eecu: goto P_0c087eec;
case 0x0c087eeeu: goto P_0c087eee;
case 0x0c087ef0u: goto P_0c087ef0;
case 0x0c087ef2u: goto P_0c087ef2;
case 0x0c087ef4u: goto P_0c087ef4;
case 0x0c087ef6u: goto P_0c087ef6;
case 0x0c087ef8u: goto P_0c087ef8;
case 0x0c087efau: goto P_0c087efa;
case 0x0c087efcu: goto P_0c087efc;
case 0x0c087efeu: goto P_0c087efe;
case 0x0c087f00u: goto P_0c087f00;
case 0x0c087f02u: goto P_0c087f02;
case 0x0c087f04u: goto P_0c087f04;
case 0x0c087f06u: goto P_0c087f06;
case 0x0c087f08u: goto P_0c087f08;
case 0x0c087f0au: goto P_0c087f0a;
case 0x0c087f0cu: goto P_0c087f0c;
case 0x0c087f0eu: goto P_0c087f0e;
case 0x0c087f10u: goto P_0c087f10;
case 0x0c087f12u: goto P_0c087f12;
case 0x0c087f14u: goto P_0c087f14;
case 0x0c087f16u: goto P_0c087f16;
case 0x0c087f18u: goto P_0c087f18;
case 0x0c087f1au: goto P_0c087f1a;
case 0x0c087f1cu: goto P_0c087f1c;
case 0x0c087f1eu: goto P_0c087f1e;
case 0x0c087f20u: goto P_0c087f20;
case 0x0c087f22u: goto P_0c087f22;
case 0x0c087f24u: goto P_0c087f24;
case 0x0c087f26u: goto P_0c087f26;
case 0x0c087f28u: goto P_0c087f28;
case 0x0c087f2au: goto P_0c087f2a;
case 0x0c087f2cu: goto P_0c087f2c;
case 0x0c087f2eu: goto P_0c087f2e;
case 0x0c087f30u: goto P_0c087f30;
case 0x0c087f32u: goto P_0c087f32;
case 0x0c087f34u: goto P_0c087f34;
case 0x0c087f36u: goto P_0c087f36;
case 0x0c087f38u: goto P_0c087f38;
case 0x0c087f3au: goto P_0c087f3a;
case 0x0c087f3cu: goto P_0c087f3c;
case 0x0c087f3eu: goto P_0c087f3e;
case 0x0c087f40u: goto P_0c087f40;
case 0x0c087f42u: goto P_0c087f42;
case 0x0c087f44u: goto P_0c087f44;
case 0x0c087f46u: goto P_0c087f46;
case 0x0c087f48u: goto P_0c087f48;
case 0x0c087f4au: goto P_0c087f4a;
case 0x0c087f4cu: goto P_0c087f4c;
case 0x0c087f4eu: goto P_0c087f4e;
case 0x0c087f50u: goto P_0c087f50;
case 0x0c087f52u: goto P_0c087f52;
case 0x0c087f54u: goto P_0c087f54;
case 0x0c087f56u: goto P_0c087f56;
case 0x0c087f58u: goto P_0c087f58;
case 0x0c087f5au: goto P_0c087f5a;
case 0x0c087f5cu: goto P_0c087f5c;
case 0x0c087f5eu: goto P_0c087f5e;
case 0x0c087f60u: goto P_0c087f60;
case 0x0c087f62u: goto P_0c087f62;
case 0x0c087f64u: goto P_0c087f64;
case 0x0c087f66u: goto P_0c087f66;
case 0x0c087f68u: goto P_0c087f68;
case 0x0c087f6au: goto P_0c087f6a;
case 0x0c087f6cu: goto P_0c087f6c;
case 0x0c087f6eu: goto P_0c087f6e;
case 0x0c087f70u: goto P_0c087f70;
case 0x0c087f72u: goto P_0c087f72;
case 0x0c087f74u: goto P_0c087f74;
case 0x0c087f76u: goto P_0c087f76;
case 0x0c087f78u: goto P_0c087f78;
case 0x0c087f7au: goto P_0c087f7a;
case 0x0c087f7cu: goto P_0c087f7c;
case 0x0c087f7eu: goto P_0c087f7e;
case 0x0c087f80u: goto P_0c087f80;
case 0x0c087f82u: goto P_0c087f82;
case 0x0c087f84u: goto P_0c087f84;
case 0x0c087f86u: goto P_0c087f86;
case 0x0c087f88u: goto P_0c087f88;
case 0x0c087f8au: goto P_0c087f8a;
case 0x0c087f8cu: goto P_0c087f8c;
case 0x0c087f8eu: goto P_0c087f8e;
case 0x0c087f90u: goto P_0c087f90;
case 0x0c087f92u: goto P_0c087f92;
case 0x0c087f94u: goto P_0c087f94;
case 0x0c087f96u: goto P_0c087f96;
case 0x0c087f98u: goto P_0c087f98;
case 0x0c087f9au: goto P_0c087f9a;
case 0x0c087f9cu: goto P_0c087f9c;
case 0x0c087f9eu: goto P_0c087f9e;
case 0x0c087fa0u: goto P_0c087fa0;
case 0x0c087fa2u: goto P_0c087fa2;
case 0x0c087fa4u: goto P_0c087fa4;
case 0x0c087fa6u: goto P_0c087fa6;
case 0x0c087fa8u: goto P_0c087fa8;
case 0x0c087faau: goto P_0c087faa;
case 0x0c087facu: goto P_0c087fac;
case 0x0c087faeu: goto P_0c087fae;
case 0x0c087fb0u: goto P_0c087fb0;
case 0x0c087fb2u: goto P_0c087fb2;
case 0x0c087fb4u: goto P_0c087fb4;
case 0x0c087fb6u: goto P_0c087fb6;
case 0x0c087fb8u: goto P_0c087fb8;
case 0x0c087fbau: goto P_0c087fba;
case 0x0c087fbcu: goto P_0c087fbc;
case 0x0c087fbeu: goto P_0c087fbe;
case 0x0c087fc0u: goto P_0c087fc0;
case 0x0c087fc2u: goto P_0c087fc2;
case 0x0c087fc4u: goto P_0c087fc4;
case 0x0c087fc6u: goto P_0c087fc6;
case 0x0c087fc8u: goto P_0c087fc8;
case 0x0c087fcau: goto P_0c087fca;
case 0x0c087fccu: goto P_0c087fcc;
case 0x0c087fceu: goto P_0c087fce;
case 0x0c087fd0u: goto P_0c087fd0;
case 0x0c087fd2u: goto P_0c087fd2;
case 0x0c087fd4u: goto P_0c087fd4;
case 0x0c087fd6u: goto P_0c087fd6;
case 0x0c087fd8u: goto P_0c087fd8;
case 0x0c087fdau: goto P_0c087fda;
case 0x0c087fdcu: goto P_0c087fdc;
case 0x0c087fdeu: goto P_0c087fde;
case 0x0c087fe0u: goto P_0c087fe0;
case 0x0c087fe2u: goto P_0c087fe2;
case 0x0c087fe4u: goto P_0c087fe4;
case 0x0c087fe6u: goto P_0c087fe6;
case 0x0c087fe8u: goto P_0c087fe8;
case 0x0c087feau: goto P_0c087fea;
case 0x0c087fecu: goto P_0c087fec;
case 0x0c087feeu: goto P_0c087fee;
case 0x0c087ff0u: goto P_0c087ff0;
case 0x0c087ff2u: goto P_0c087ff2;
case 0x0c087ff4u: goto P_0c087ff4;
case 0x0c087ff6u: goto P_0c087ff6;
case 0x0c087ff8u: goto P_0c087ff8;
case 0x0c087ffau: goto P_0c087ffa;
case 0x0c087ffcu: goto P_0c087ffc;
case 0x0c087ffeu: goto P_0c087ffe;
case 0x0c088000u: goto P_0c088000;
case 0x0c088002u: goto P_0c088002;
case 0x0c088004u: goto P_0c088004;
case 0x0c088006u: goto P_0c088006;
case 0x0c088008u: goto P_0c088008;
case 0x0c08800au: goto P_0c08800a;
case 0x0c08800cu: goto P_0c08800c;
case 0x0c088024u: goto P_0c088024;
case 0x0c088026u: goto P_0c088026;
case 0x0c088028u: goto P_0c088028;
case 0x0c08802au: goto P_0c08802a;
case 0x0c08802cu: goto P_0c08802c;
case 0x0c08802eu: goto P_0c08802e;
case 0x0c088030u: goto P_0c088030;
case 0x0c088032u: goto P_0c088032;
case 0x0c088034u: goto P_0c088034;
case 0x0c088036u: goto P_0c088036;
case 0x0c088038u: goto P_0c088038;
case 0x0c08803au: goto P_0c08803a;
case 0x0c08803cu: goto P_0c08803c;
case 0x0c08803eu: goto P_0c08803e;
case 0x0c088040u: goto P_0c088040;
case 0x0c088042u: goto P_0c088042;
case 0x0c088044u: goto P_0c088044;
case 0x0c088046u: goto P_0c088046;
case 0x0c088048u: goto P_0c088048;
case 0x0c08804au: goto P_0c08804a;
case 0x0c08804cu: goto P_0c08804c;
case 0x0c08804eu: goto P_0c08804e;
case 0x0c088050u: goto P_0c088050;
case 0x0c088052u: goto P_0c088052;
case 0x0c088054u: goto P_0c088054;
case 0x0c088056u: goto P_0c088056;
case 0x0c088058u: goto P_0c088058;
case 0x0c08805au: goto P_0c08805a;
case 0x0c08805cu: goto P_0c08805c;
case 0x0c08805eu: goto P_0c08805e;
case 0x0c088060u: goto P_0c088060;
case 0x0c088062u: goto P_0c088062;
case 0x0c088064u: goto P_0c088064;
case 0x0c088066u: goto P_0c088066;
case 0x0c088068u: goto P_0c088068;
case 0x0c08806au: goto P_0c08806a;
case 0x0c08806cu: goto P_0c08806c;
case 0x0c08806eu: goto P_0c08806e;
case 0x0c088070u: goto P_0c088070;
case 0x0c088072u: goto P_0c088072;
case 0x0c088074u: goto P_0c088074;
case 0x0c088076u: goto P_0c088076;
case 0x0c088078u: goto P_0c088078;
case 0x0c08807au: goto P_0c08807a;
case 0x0c08807cu: goto P_0c08807c;
case 0x0c08807eu: goto P_0c08807e;
case 0x0c088080u: goto P_0c088080;
case 0x0c088082u: goto P_0c088082;
case 0x0c088084u: goto P_0c088084;
case 0x0c088086u: goto P_0c088086;
case 0x0c088088u: goto P_0c088088;
case 0x0c08808au: goto P_0c08808a;
case 0x0c08808cu: goto P_0c08808c;
case 0x0c08808eu: goto P_0c08808e;
case 0x0c088090u: goto P_0c088090;
case 0x0c088092u: goto P_0c088092;
case 0x0c088094u: goto P_0c088094;
case 0x0c088096u: goto P_0c088096;
case 0x0c088098u: goto P_0c088098;
case 0x0c08809au: goto P_0c08809a;
case 0x0c08809cu: goto P_0c08809c;
case 0x0c08809eu: goto P_0c08809e;
case 0x0c0880a0u: goto P_0c0880a0;
case 0x0c0880a2u: goto P_0c0880a2;
case 0x0c0880a4u: goto P_0c0880a4;
case 0x0c0880a6u: goto P_0c0880a6;
case 0x0c0880a8u: goto P_0c0880a8;
case 0x0c0880aau: goto P_0c0880aa;
case 0x0c0880acu: goto P_0c0880ac;
case 0x0c0880aeu: goto P_0c0880ae;
case 0x0c0880b0u: goto P_0c0880b0;
case 0x0c0880b2u: goto P_0c0880b2;
case 0x0c0880b4u: goto P_0c0880b4;
case 0x0c0880b6u: goto P_0c0880b6;
case 0x0c0880b8u: goto P_0c0880b8;
case 0x0c0880bau: goto P_0c0880ba;
case 0x0c0880bcu: goto P_0c0880bc;
case 0x0c0880beu: goto P_0c0880be;
case 0x0c0880c0u: goto P_0c0880c0;
case 0x0c0880c2u: goto P_0c0880c2;
case 0x0c0880c4u: goto P_0c0880c4;
case 0x0c0880c6u: goto P_0c0880c6;
case 0x0c0880c8u: goto P_0c0880c8;
case 0x0c0880cau: goto P_0c0880ca;
case 0x0c0880ccu: goto P_0c0880cc;
case 0x0c0880ceu: goto P_0c0880ce;
case 0x0c0880d0u: goto P_0c0880d0;
case 0x0c0880d2u: goto P_0c0880d2;
case 0x0c0880d4u: goto P_0c0880d4;
case 0x0c0880d6u: goto P_0c0880d6;
case 0x0c0880d8u: goto P_0c0880d8;
case 0x0c0880dau: goto P_0c0880da;
case 0x0c0880dcu: goto P_0c0880dc;
case 0x0c0880deu: goto P_0c0880de;
case 0x0c0880e0u: goto P_0c0880e0;
case 0x0c0880e2u: goto P_0c0880e2;
case 0x0c0880e4u: goto P_0c0880e4;
case 0x0c0880e6u: goto P_0c0880e6;
case 0x0c0880e8u: goto P_0c0880e8;
case 0x0c0880eau: goto P_0c0880ea;
case 0x0c0880ecu: goto P_0c0880ec;
case 0x0c0880eeu: goto P_0c0880ee;
case 0x0c0880f0u: goto P_0c0880f0;
case 0x0c0880f2u: goto P_0c0880f2;
case 0x0c0880f4u: goto P_0c0880f4;
case 0x0c0880f6u: goto P_0c0880f6;
case 0x0c0880f8u: goto P_0c0880f8;
case 0x0c0880fau: goto P_0c0880fa;
case 0x0c0880fcu: goto P_0c0880fc;
case 0x0c0880feu: goto P_0c0880fe;
case 0x0c088100u: goto P_0c088100;
case 0x0c088102u: goto P_0c088102;
case 0x0c088104u: goto P_0c088104;
case 0x0c088106u: goto P_0c088106;
case 0x0c088108u: goto P_0c088108;
case 0x0c08810au: goto P_0c08810a;
case 0x0c08810cu: goto P_0c08810c;
case 0x0c08810eu: goto P_0c08810e;
case 0x0c088110u: goto P_0c088110;
case 0x0c088112u: goto P_0c088112;
case 0x0c088114u: goto P_0c088114;
case 0x0c088116u: goto P_0c088116;
case 0x0c088118u: goto P_0c088118;
case 0x0c08811au: goto P_0c08811a;
case 0x0c08811cu: goto P_0c08811c;
case 0x0c08811eu: goto P_0c08811e;
case 0x0c088120u: goto P_0c088120;
case 0x0c088122u: goto P_0c088122;
case 0x0c088124u: goto P_0c088124;
case 0x0c088126u: goto P_0c088126;
case 0x0c088128u: goto P_0c088128;
case 0x0c08812au: goto P_0c08812a;
case 0x0c08812cu: goto P_0c08812c;
case 0x0c08812eu: goto P_0c08812e;
case 0x0c088130u: goto P_0c088130;
case 0x0c088132u: goto P_0c088132;
case 0x0c088134u: goto P_0c088134;
case 0x0c088136u: goto P_0c088136;
case 0x0c088138u: goto P_0c088138;
default: return vf3_matrix_family(target,s,ram);
}
P_0c087e04: /* original 2fe6, guest PC 0x0c087e04 */
if(!s->budget--) { s->failed_pc=0x0c087e04u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c087e06;
P_0c087e06: /* original 2fd6, guest PC 0x0c087e06 */
if(!s->budget--) { s->failed_pc=0x0c087e06u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c087e08;
P_0c087e08: /* original 2fc6, guest PC 0x0c087e08 */
if(!s->budget--) { s->failed_pc=0x0c087e08u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c087e0a;
P_0c087e0a: /* original 2fb6, guest PC 0x0c087e0a */
if(!s->budget--) { s->failed_pc=0x0c087e0au; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c087e0c;
P_0c087e0c: /* original 2fa6, guest PC 0x0c087e0c */
if(!s->budget--) { s->failed_pc=0x0c087e0cu; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c087e0e;
P_0c087e0e: /* original 2f96, guest PC 0x0c087e0e */
if(!s->budget--) { s->failed_pc=0x0c087e0eu; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c087e10;
P_0c087e10: /* original 2f86, guest PC 0x0c087e10 */
if(!s->budget--) { s->failed_pc=0x0c087e10u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c087e12;
P_0c087e12: /* original fffb, guest PC 0x0c087e12 */
if(!s->budget--) { s->failed_pc=0x0c087e12u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c087e14;
P_0c087e14: /* original ffeb, guest PC 0x0c087e14 */
if(!s->budget--) { s->failed_pc=0x0c087e14u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,14,r[15]);
goto P_0c087e16;
P_0c087e16: /* original ffdb, guest PC 0x0c087e16 */
if(!s->budget--) { s->failed_pc=0x0c087e16u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,13,r[15]);
goto P_0c087e18;
P_0c087e18: /* original ffcb, guest PC 0x0c087e18 */
if(!s->budget--) { s->failed_pc=0x0c087e18u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,12,r[15]);
goto P_0c087e1a;
P_0c087e1a: /* original d124, guest PC 0x0c087e1a */
if(!s->budget--) { s->failed_pc=0x0c087e1au; return 0; }
r[1]=read(ram,0x0c087eacu,4);
goto P_0c087e1c;
P_0c087e1c: /* original 4f22, guest PC 0x0c087e1c */
if(!s->budget--) { s->failed_pc=0x0c087e1cu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c087e1e;
P_0c087e1e: /* original d322, guest PC 0x0c087e1e */
if(!s->budget--) { s->failed_pc=0x0c087e1eu; return 0; }
r[3]=read(ram,0x0c087ea8u,4);
goto P_0c087e20;
P_0c087e20: /* original 6212, guest PC 0x0c087e20 */
if(!s->budget--) { s->failed_pc=0x0c087e20u; return 0; }
tmp=read(ram,r[1],4);
r[2]=tmp;
goto P_0c087e22;
P_0c087e22: /* original 7f98, guest PC 0x0c087e22 */
if(!s->budget--) { s->failed_pc=0x0c087e22u; return 0; }
r[15]+=0xffffff98u;
goto P_0c087e24;
P_0c087e24: /* original 2238, guest PC 0x0c087e24 */
if(!s->budget--) { s->failed_pc=0x0c087e24u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c087e26;
P_0c087e26: /* original 8901, guest PC 0x0c087e26 */
if(!s->budget--) { s->failed_pc=0x0c087e26u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c087e2c; }
goto P_0c087e28;
P_0c087e28: /* original a179, guest PC 0x0c087e28 */
if(!s->budget--) { s->failed_pc=0x0c087e28u; return 0; }
goto P_0c08811e;
P_0c087e2a: /* original 0009, guest PC 0x0c087e2a */
if(!s->budget--) { s->failed_pc=0x0c087e2au; return 0; }
goto P_0c087e2c;
P_0c087e2c: /* original d320, guest PC 0x0c087e2c */
if(!s->budget--) { s->failed_pc=0x0c087e2cu; return 0; }
r[3]=read(ram,0x0c087eb0u,4);
goto P_0c087e2e;
P_0c087e2e: /* original 6d43, guest PC 0x0c087e2e */
if(!s->budget--) { s->failed_pc=0x0c087e2eu; return 0; }
r[13]=r[4];
goto P_0c087e30;
P_0c087e30: /* original 6e32, guest PC 0x0c087e30 */
if(!s->budget--) { s->failed_pc=0x0c087e30u; return 0; }
tmp=read(ram,r[3],4);
r[14]=tmp;
goto P_0c087e32;
P_0c087e32: /* original bee1, guest PC 0x0c087e32 */
if(!s->budget--) { s->failed_pc=0x0c087e32u; return 0; }
target=code_base|0x0c087bf8u; r[16]=code_base|0x0c087e36u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c087e36u) { target=s->pc; goto dispatch; }
goto P_0c087e36;
P_0c087e34: /* original 64e3, guest PC 0x0c087e34 */
if(!s->budget--) { s->failed_pc=0x0c087e34u; return 0; }
r[4]=r[14];
goto P_0c087e36;
P_0c087e36: /* original e028, guest PC 0x0c087e36 */
if(!s->budget--) { s->failed_pc=0x0c087e36u; return 0; }
r[0]=0x00000028u;
goto P_0c087e38;
P_0c087e38: /* original f3e6, guest PC 0x0c087e38 */
if(!s->budget--) { s->failed_pc=0x0c087e38u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c087e3a;
P_0c087e3a: /* original 9032, guest PC 0x0c087e3a */
if(!s->budget--) { s->failed_pc=0x0c087e3au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c087ea2u,2);
goto P_0c087e3c;
P_0c087e3c: /* original fe37, guest PC 0x0c087e3c */
if(!s->budget--) { s->failed_pc=0x0c087e3cu; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c087e3e;
P_0c087e3e: /* original d31d, guest PC 0x0c087e3e */
if(!s->budget--) { s->failed_pc=0x0c087e3eu; return 0; }
r[3]=read(ram,0x0c087eb4u,4);
goto P_0c087e40;
P_0c087e40: /* original 6e32, guest PC 0x0c087e40 */
if(!s->budget--) { s->failed_pc=0x0c087e40u; return 0; }
tmp=read(ram,r[3],4);
r[14]=tmp;
goto P_0c087e42;
P_0c087e42: /* original bed9, guest PC 0x0c087e42 */
if(!s->budget--) { s->failed_pc=0x0c087e42u; return 0; }
target=code_base|0x0c087bf8u; r[16]=code_base|0x0c087e46u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c087e46u) { target=s->pc; goto dispatch; }
goto P_0c087e46;
P_0c087e44: /* original 64e3, guest PC 0x0c087e44 */
if(!s->budget--) { s->failed_pc=0x0c087e44u; return 0; }
r[4]=r[14];
goto P_0c087e46;
P_0c087e46: /* original e028, guest PC 0x0c087e46 */
if(!s->budget--) { s->failed_pc=0x0c087e46u; return 0; }
r[0]=0x00000028u;
goto P_0c087e48;
P_0c087e48: /* original f3e6, guest PC 0x0c087e48 */
if(!s->budget--) { s->failed_pc=0x0c087e48u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c087e4a;
P_0c087e4a: /* original 902a, guest PC 0x0c087e4a */
if(!s->budget--) { s->failed_pc=0x0c087e4au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c087ea2u,2);
goto P_0c087e4c;
P_0c087e4c: /* original fe37, guest PC 0x0c087e4c */
if(!s->budget--) { s->failed_pc=0x0c087e4cu; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c087e4e;
P_0c087e4e: /* original 9e29, guest PC 0x0c087e4e */
if(!s->budget--) { s->failed_pc=0x0c087e4eu; return 0; }
r[14]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c087ea4u,2);
goto P_0c087e50;
P_0c087e50: /* original d319, guest PC 0x0c087e50 */
if(!s->budget--) { s->failed_pc=0x0c087e50u; return 0; }
r[3]=read(ram,0x0c087eb8u,4);
goto P_0c087e52;
P_0c087e52: /* original 3edc, guest PC 0x0c087e52 */
if(!s->budget--) { s->failed_pc=0x0c087e52u; return 0; }
r[14]+=r[13];
goto P_0c087e54;
P_0c087e54: /* original 430b, guest PC 0x0c087e54 */
if(!s->budget--) { s->failed_pc=0x0c087e54u; return 0; }
target=r[3];
r[16]=code_base|0x0c087e58u;
r[4]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c087e58u) { target=s->pc; goto dispatch; }
goto P_0c087e58;
P_0c087e56: /* original e400, guest PC 0x0c087e56 */
if(!s->budget--) { s->failed_pc=0x0c087e56u; return 0; }
r[4]=0x00000000u;
goto P_0c087e58;
P_0c087e58: /* original 67f3, guest PC 0x0c087e58 */
if(!s->budget--) { s->failed_pc=0x0c087e58u; return 0; }
r[7]=r[15];
goto P_0c087e5a;
P_0c087e5a: /* original 66f3, guest PC 0x0c087e5a */
if(!s->budget--) { s->failed_pc=0x0c087e5au; return 0; }
r[6]=r[15];
goto P_0c087e5c;
P_0c087e5c: /* original 65f3, guest PC 0x0c087e5c */
if(!s->budget--) { s->failed_pc=0x0c087e5cu; return 0; }
r[5]=r[15];
goto P_0c087e5e;
P_0c087e5e: /* original 7544, guest PC 0x0c087e5e */
if(!s->budget--) { s->failed_pc=0x0c087e5eu; return 0; }
r[5]+=0x00000044u;
goto P_0c087e60;
P_0c087e60: /* original 765c, guest PC 0x0c087e60 */
if(!s->budget--) { s->failed_pc=0x0c087e60u; return 0; }
r[6]+=0x0000005cu;
goto P_0c087e62;
P_0c087e62: /* original 64f3, guest PC 0x0c087e62 */
if(!s->budget--) { s->failed_pc=0x0c087e62u; return 0; }
r[4]=r[15];
goto P_0c087e64;
P_0c087e64: /* original 7750, guest PC 0x0c087e64 */
if(!s->budget--) { s->failed_pc=0x0c087e64u; return 0; }
r[7]+=0x00000050u;
goto P_0c087e66;
P_0c087e66: /* original 6153, guest PC 0x0c087e66 */
if(!s->budget--) { s->failed_pc=0x0c087e66u; return 0; }
r[1]=r[5];
goto P_0c087e68;
P_0c087e68: /* original 6263, guest PC 0x0c087e68 */
if(!s->budget--) { s->failed_pc=0x0c087e68u; return 0; }
r[2]=r[6];
goto P_0c087e6a;
P_0c087e6a: /* original 6373, guest PC 0x0c087e6a */
if(!s->budget--) { s->failed_pc=0x0c087e6au; return 0; }
r[3]=r[7];
goto P_0c087e6c;
P_0c087e6c: /* original 7438, guest PC 0x0c087e6c */
if(!s->budget--) { s->failed_pc=0x0c087e6cu; return 0; }
r[4]+=0x00000038u;
goto P_0c087e6e;
P_0c087e6e: /* original 1f25, guest PC 0x0c087e6e */
if(!s->budget--) { s->failed_pc=0x0c087e6eu; return 0; }
write(ram,r[15]+20,r[2],4);
goto P_0c087e70;
P_0c087e70: /* original 1f36, guest PC 0x0c087e70 */
if(!s->budget--) { s->failed_pc=0x0c087e70u; return 0; }
write(ram,r[15]+24,r[3],4);
goto P_0c087e72;
P_0c087e72: /* original 6363, guest PC 0x0c087e72 */
if(!s->budget--) { s->failed_pc=0x0c087e72u; return 0; }
r[3]=r[6];
goto P_0c087e74;
P_0c087e74: /* original 1f19, guest PC 0x0c087e74 */
if(!s->budget--) { s->failed_pc=0x0c087e74u; return 0; }
write(ram,r[15]+36,r[1],4);
goto P_0c087e76;
P_0c087e76: /* original 6173, guest PC 0x0c087e76 */
if(!s->budget--) { s->failed_pc=0x0c087e76u; return 0; }
r[1]=r[7];
goto P_0c087e78;
P_0c087e78: /* original 6243, guest PC 0x0c087e78 */
if(!s->budget--) { s->failed_pc=0x0c087e78u; return 0; }
r[2]=r[4];
goto P_0c087e7a;
P_0c087e7a: /* original 6a23, guest PC 0x0c087e7a */
if(!s->budget--) { s->failed_pc=0x0c087e7au; return 0; }
r[10]=r[2];
goto P_0c087e7c;
P_0c087e7c: /* original 6b53, guest PC 0x0c087e7c */
if(!s->budget--) { s->failed_pc=0x0c087e7cu; return 0; }
r[11]=r[5];
goto P_0c087e7e;
P_0c087e7e: /* original 6873, guest PC 0x0c087e7e */
if(!s->budget--) { s->failed_pc=0x0c087e7eu; return 0; }
r[8]=r[7];
goto P_0c087e80;
P_0c087e80: /* original 6963, guest PC 0x0c087e80 */
if(!s->budget--) { s->failed_pc=0x0c087e80u; return 0; }
r[9]=r[6];
goto P_0c087e82;
P_0c087e82: /* original 7104, guest PC 0x0c087e82 */
if(!s->budget--) { s->failed_pc=0x0c087e82u; return 0; }
r[1]+=0x00000004u;
goto P_0c087e84;
P_0c087e84: /* original 7304, guest PC 0x0c087e84 */
if(!s->budget--) { s->failed_pc=0x0c087e84u; return 0; }
r[3]+=0x00000004u;
goto P_0c087e86;
P_0c087e86: /* original 1f2a, guest PC 0x0c087e86 */
if(!s->budget--) { s->failed_pc=0x0c087e86u; return 0; }
write(ram,r[15]+40,r[2],4);
goto P_0c087e88;
P_0c087e88: /* original 7908, guest PC 0x0c087e88 */
if(!s->budget--) { s->failed_pc=0x0c087e88u; return 0; }
r[9]+=0x00000008u;
goto P_0c087e8a;
P_0c087e8a: /* original 1f3b, guest PC 0x0c087e8a */
if(!s->budget--) { s->failed_pc=0x0c087e8au; return 0; }
write(ram,r[15]+44,r[3],4);
goto P_0c087e8c;
P_0c087e8c: /* original 7508, guest PC 0x0c087e8c */
if(!s->budget--) { s->failed_pc=0x0c087e8cu; return 0; }
r[5]+=0x00000008u;
goto P_0c087e8e;
P_0c087e8e: /* original 1f1c, guest PC 0x0c087e8e */
if(!s->budget--) { s->failed_pc=0x0c087e8eu; return 0; }
write(ram,r[15]+48,r[1],4);
goto P_0c087e90;
P_0c087e90: /* original 7808, guest PC 0x0c087e90 */
if(!s->budget--) { s->failed_pc=0x0c087e90u; return 0; }
r[8]+=0x00000008u;
goto P_0c087e92;
P_0c087e92: /* original ec08, guest PC 0x0c087e92 */
if(!s->budget--) { s->failed_pc=0x0c087e92u; return 0; }
r[12]=0x00000008u;
goto P_0c087e94;
P_0c087e94: /* original 7b04, guest PC 0x0c087e94 */
if(!s->budget--) { s->failed_pc=0x0c087e94u; return 0; }
r[11]+=0x00000004u;
goto P_0c087e96;
P_0c087e96: /* original 7a04, guest PC 0x0c087e96 */
if(!s->budget--) { s->failed_pc=0x0c087e96u; return 0; }
r[10]+=0x00000004u;
goto P_0c087e98;
P_0c087e98: /* original 7408, guest PC 0x0c087e98 */
if(!s->budget--) { s->failed_pc=0x0c087e98u; return 0; }
r[4]+=0x00000008u;
goto P_0c087e9a;
P_0c087e9a: /* original 1f58, guest PC 0x0c087e9a */
if(!s->budget--) { s->failed_pc=0x0c087e9au; return 0; }
write(ram,r[15]+32,r[5],4);
goto P_0c087e9c;
P_0c087e9c: /* original 1f47, guest PC 0x0c087e9c */
if(!s->budget--) { s->failed_pc=0x0c087e9cu; return 0; }
write(ram,r[15]+28,r[4],4);
goto P_0c087e9e;
P_0c087e9e: /* original a130, guest PC 0x0c087e9e */
if(!s->budget--) { s->failed_pc=0x0c087e9eu; return 0; }
fr[14]=0;
goto P_0c088102;
P_0c087ea0: /* original fe8d, guest PC 0x0c087ea0 */
if(!s->budget--) { s->failed_pc=0x0c087ea0u; return 0; }
fr[14]=0;
if(!vf3_matrix_family(0x0c087ea2u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c087ea2u; return 0; } return 1;
P_0c087ebc: /* original d354, guest PC 0x0c087ebc */
if(!s->budget--) { s->failed_pc=0x0c087ebcu; return 0; }
r[3]=read(ram,0x0c088010u,4);
goto P_0c087ebe;
P_0c087ebe: /* original 430b, guest PC 0x0c087ebe */
if(!s->budget--) { s->failed_pc=0x0c087ebeu; return 0; }
target=r[3];
r[16]=code_base|0x0c087ec2u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c087ec2u) { target=s->pc; goto dispatch; }
goto P_0c087ec2;
P_0c087ec0: /* original 64e3, guest PC 0x0c087ec0 */
if(!s->budget--) { s->failed_pc=0x0c087ec0u; return 0; }
r[4]=r[14];
goto P_0c087ec2;
P_0c087ec2: /* original 90a4, guest PC 0x0c087ec2 */
if(!s->budget--) { s->failed_pc=0x0c087ec2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08800eu,2);
goto P_0c087ec4;
P_0c087ec4: /* original ffe6, guest PC 0x0c087ec4 */
if(!s->budget--) { s->failed_pc=0x0c087ec4u; return 0; }
vf3_matrix_load(s,ram,15,r[14]+r[0]);
goto P_0c087ec6;
P_0c087ec6: /* original 70fc, guest PC 0x0c087ec6 */
if(!s->budget--) { s->failed_pc=0x0c087ec6u; return 0; }
r[0]+=0xfffffffcu;
goto P_0c087ec8;
P_0c087ec8: /* original fde6, guest PC 0x0c087ec8 */
if(!s->budget--) { s->failed_pc=0x0c087ec8u; return 0; }
vf3_matrix_load(s,ram,13,r[14]+r[0]);
goto P_0c087eca;
P_0c087eca: /* original 7008, guest PC 0x0c087eca */
if(!s->budget--) { s->failed_pc=0x0c087ecau; return 0; }
r[0]+=0x00000008u;
goto P_0c087ecc;
P_0c087ecc: /* original fce6, guest PC 0x0c087ecc */
if(!s->budget--) { s->failed_pc=0x0c087eccu; return 0; }
vf3_matrix_load(s,ram,12,r[14]+r[0]);
goto P_0c087ece;
P_0c087ece: /* original c751, guest PC 0x0c087ece */
if(!s->budget--) { s->failed_pc=0x0c087eceu; return 0; }
r[0]=code_base|0x00088014u;
goto P_0c087ed0;
P_0c087ed0: /* original f308, guest PC 0x0c087ed0 */
if(!s->budget--) { s->failed_pc=0x0c087ed0u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c087ed2;
P_0c087ed2: /* original e010, guest PC 0x0c087ed2 */
if(!s->budget--) { s->failed_pc=0x0c087ed2u; return 0; }
r[0]=0x00000010u;
goto P_0c087ed4;
P_0c087ed4: /* original ff37, guest PC 0x0c087ed4 */
if(!s->budget--) { s->failed_pc=0x0c087ed4u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c087ed6;
P_0c087ed6: /* original e00c, guest PC 0x0c087ed6 */
if(!s->budget--) { s->failed_pc=0x0c087ed6u; return 0; }
r[0]=0x0000000cu;
goto P_0c087ed8;
P_0c087ed8: /* original ffe7, guest PC 0x0c087ed8 */
if(!s->budget--) { s->failed_pc=0x0c087ed8u; return 0; }
vf3_matrix_store(s,ram,14,r[15]+r[0]);
goto P_0c087eda;
P_0c087eda: /* original c74f, guest PC 0x0c087eda */
if(!s->budget--) { s->failed_pc=0x0c087edau; return 0; }
r[0]=code_base|0x00088018u;
goto P_0c087edc;
P_0c087edc: /* original f408, guest PC 0x0c087edc */
if(!s->budget--) { s->failed_pc=0x0c087edcu; return 0; }
vf3_matrix_load(s,ram,4,r[0]);
goto P_0c087ede;
P_0c087ede: /* original 60c3, guest PC 0x0c087ede */
if(!s->budget--) { s->failed_pc=0x0c087edeu; return 0; }
r[0]=r[12];
goto P_0c087ee0;
P_0c087ee0: /* original 8801, guest PC 0x0c087ee0 */
if(!s->budget--) { s->failed_pc=0x0c087ee0u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c087ee2;
P_0c087ee2: /* original ff42, guest PC 0x0c087ee2 */
if(!s->budget--) { s->failed_pc=0x0c087ee2u; return 0; }
fr[15]=vf3_fpu_binary(fr[15],fr[4],r[18],'*');
goto P_0c087ee4;
P_0c087ee4: /* original 8f01, guest PC 0x0c087ee4 */
if(!s->budget--) { s->failed_pc=0x0c087ee4u; return 0; }
cond=r[17]&1u;
fr[12]=vf3_fpu_binary(fr[12],fr[4],r[18],'*');
if(!cond) { goto P_0c087eea; }
goto P_0c087ee8;
P_0c087ee6: /* original fc42, guest PC 0x0c087ee6 */
if(!s->budget--) { s->failed_pc=0x0c087ee6u; return 0; }
fr[12]=vf3_fpu_binary(fr[12],fr[4],r[18],'*');
goto P_0c087ee8;
P_0c087ee8: /* original fcec, guest PC 0x0c087ee8 */
if(!s->budget--) { s->failed_pc=0x0c087ee8u; return 0; }
vf3_matrix_move(s,12,14);
goto P_0c087eea;
P_0c087eea: /* original 66f3, guest PC 0x0c087eea */
if(!s->budget--) { s->failed_pc=0x0c087eeau; return 0; }
r[6]=r[15];
goto P_0c087eec;
P_0c087eec: /* original 65f3, guest PC 0x0c087eec */
if(!s->budget--) { s->failed_pc=0x0c087eecu; return 0; }
r[5]=r[15];
goto P_0c087eee;
P_0c087eee: /* original f6cc, guest PC 0x0c087eee */
if(!s->budget--) { s->failed_pc=0x0c087eeeu; return 0; }
vf3_matrix_move(s,6,12);
goto P_0c087ef0;
P_0c087ef0: /* original 7504, guest PC 0x0c087ef0 */
if(!s->budget--) { s->failed_pc=0x0c087ef0u; return 0; }
r[5]+=0x00000004u;
goto P_0c087ef2;
P_0c087ef2: /* original 7608, guest PC 0x0c087ef2 */
if(!s->budget--) { s->failed_pc=0x0c087ef2u; return 0; }
r[6]+=0x00000008u;
goto P_0c087ef4;
P_0c087ef4: /* original f4fc, guest PC 0x0c087ef4 */
if(!s->budget--) { s->failed_pc=0x0c087ef4u; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c087ef6;
P_0c087ef6: /* original f5dc, guest PC 0x0c087ef6 */
if(!s->budget--) { s->failed_pc=0x0c087ef6u; return 0; }
vf3_matrix_move(s,5,13);
goto P_0c087ef8;
P_0c087ef8: /* original bbfb, guest PC 0x0c087ef8 */
if(!s->budget--) { s->failed_pc=0x0c087ef8u; return 0; }
target=code_base|0x0c0876f2u; r[16]=code_base|0x0c087efcu;
r[4]=r[15];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c087efcu) { target=s->pc; goto dispatch; }
goto P_0c087efc;
P_0c087efa: /* original 64f3, guest PC 0x0c087efa */
if(!s->budget--) { s->failed_pc=0x0c087efau; return 0; }
r[4]=r[15];
goto P_0c087efc;
P_0c087efc: /* original f4f8, guest PC 0x0c087efc */
if(!s->budget--) { s->failed_pc=0x0c087efcu; return 0; }
vf3_matrix_load(s,ram,4,r[15]);
goto P_0c087efe;
P_0c087efe: /* original bd6c, guest PC 0x0c087efe */
if(!s->budget--) { s->failed_pc=0x0c087efeu; return 0; }
target=code_base|0x0c0879dau; r[16]=code_base|0x0c087f02u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c087f02u) { target=s->pc; goto dispatch; }
goto P_0c087f02;
P_0c087f00: /* original 64d3, guest PC 0x0c087f00 */
if(!s->budget--) { s->failed_pc=0x0c087f00u; return 0; }
r[4]=r[13];
goto P_0c087f02;
P_0c087f02: /* original e004, guest PC 0x0c087f02 */
if(!s->budget--) { s->failed_pc=0x0c087f02u; return 0; }
r[0]=0x00000004u;
goto P_0c087f04;
P_0c087f04: /* original f40c, guest PC 0x0c087f04 */
if(!s->budget--) { s->failed_pc=0x0c087f04u; return 0; }
vf3_matrix_move(s,4,0);
goto P_0c087f06;
P_0c087f06: /* original f3f6, guest PC 0x0c087f06 */
if(!s->budget--) { s->failed_pc=0x0c087f06u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c087f08;
P_0c087f08: /* original f28d, guest PC 0x0c087f08 */
if(!s->budget--) { s->failed_pc=0x0c087f08u; return 0; }
fr[2]=0;
goto P_0c087f0a;
P_0c087f0a: /* original f431, guest PC 0x0c087f0a */
if(!s->budget--) { s->failed_pc=0x0c087f0au; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'-');
goto P_0c087f0c;
P_0c087f0c: /* original f245, guest PC 0x0c087f0c */
if(!s->budget--) { s->failed_pc=0x0c087f0cu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[2])>as_float(fr[4]))!=0);
goto P_0c087f0e;
P_0c087f0e: /* original 8b01, guest PC 0x0c087f0e */
if(!s->budget--) { s->failed_pc=0x0c087f0eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c087f14; }
goto P_0c087f10;
P_0c087f10: /* original e00c, guest PC 0x0c087f10 */
if(!s->budget--) { s->failed_pc=0x0c087f10u; return 0; }
r[0]=0x0000000cu;
goto P_0c087f12;
P_0c087f12: /* original f4f6, guest PC 0x0c087f12 */
if(!s->budget--) { s->failed_pc=0x0c087f12u; return 0; }
vf3_matrix_load(s,ram,4,r[15]+r[0]);
goto P_0c087f14;
P_0c087f14: /* original e010, guest PC 0x0c087f14 */
if(!s->budget--) { s->failed_pc=0x0c087f14u; return 0; }
r[0]=0x00000010u;
goto P_0c087f16;
P_0c087f16: /* original f34c, guest PC 0x0c087f16 */
if(!s->budget--) { s->failed_pc=0x0c087f16u; return 0; }
vf3_matrix_move(s,3,4);
goto P_0c087f18;
P_0c087f18: /* original f4f6, guest PC 0x0c087f18 */
if(!s->budget--) { s->failed_pc=0x0c087f18u; return 0; }
vf3_matrix_load(s,ram,4,r[15]+r[0]);
goto P_0c087f1a;
P_0c087f1a: /* original e004, guest PC 0x0c087f1a */
if(!s->budget--) { s->failed_pc=0x0c087f1au; return 0; }
r[0]=0x00000004u;
goto P_0c087f1c;
P_0c087f1c: /* original 53f5, guest PC 0x0c087f1c */
if(!s->budget--) { s->failed_pc=0x0c087f1cu; return 0; }
r[3]=read(ram,r[15]+20,4);
goto P_0c087f1e;
P_0c087f1e: /* original f432, guest PC 0x0c087f1e */
if(!s->budget--) { s->failed_pc=0x0c087f1eu; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'*');
goto P_0c087f20;
P_0c087f20: /* original f3f8, guest PC 0x0c087f20 */
if(!s->budget--) { s->failed_pc=0x0c087f20u; return 0; }
vf3_matrix_load(s,ram,3,r[15]);
goto P_0c087f22;
P_0c087f22: /* original f33a, guest PC 0x0c087f22 */
if(!s->budget--) { s->failed_pc=0x0c087f22u; return 0; }
vf3_matrix_store(s,ram,3,r[3]);
goto P_0c087f24;
P_0c087f24: /* original f3f6, guest PC 0x0c087f24 */
if(!s->budget--) { s->failed_pc=0x0c087f24u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c087f26;
P_0c087f26: /* original e008, guest PC 0x0c087f26 */
if(!s->budget--) { s->failed_pc=0x0c087f26u; return 0; }
r[0]=0x00000008u;
goto P_0c087f28;
P_0c087f28: /* original 53f6, guest PC 0x0c087f28 */
if(!s->budget--) { s->failed_pc=0x0c087f28u; return 0; }
r[3]=read(ram,r[15]+24,4);
goto P_0c087f2a;
P_0c087f2a: /* original f33a, guest PC 0x0c087f2a */
if(!s->budget--) { s->failed_pc=0x0c087f2au; return 0; }
vf3_matrix_store(s,ram,3,r[3]);
goto P_0c087f2c;
P_0c087f2c: /* original f3f6, guest PC 0x0c087f2c */
if(!s->budget--) { s->failed_pc=0x0c087f2cu; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c087f2e;
P_0c087f2e: /* original 60c3, guest PC 0x0c087f2e */
if(!s->budget--) { s->failed_pc=0x0c087f2eu; return 0; }
r[0]=r[12];
goto P_0c087f30;
P_0c087f30: /* original 53f9, guest PC 0x0c087f30 */
if(!s->budget--) { s->failed_pc=0x0c087f30u; return 0; }
r[3]=read(ram,r[15]+36,4);
goto P_0c087f32;
P_0c087f32: /* original 8801, guest PC 0x0c087f32 */
if(!s->budget--) { s->failed_pc=0x0c087f32u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c087f34;
P_0c087f34: /* original f33a, guest PC 0x0c087f34 */
if(!s->budget--) { s->failed_pc=0x0c087f34u; return 0; }
vf3_matrix_store(s,ram,3,r[3]);
goto P_0c087f36;
P_0c087f36: /* original 53fa, guest PC 0x0c087f36 */
if(!s->budget--) { s->failed_pc=0x0c087f36u; return 0; }
r[3]=read(ram,r[15]+40,4);
goto P_0c087f38;
P_0c087f38: /* original f34a, guest PC 0x0c087f38 */
if(!s->budget--) { s->failed_pc=0x0c087f38u; return 0; }
vf3_matrix_store(s,ram,4,r[3]);
goto P_0c087f3a;
P_0c087f3a: /* original 8f01, guest PC 0x0c087f3a */
if(!s->budget--) { s->failed_pc=0x0c087f3au; return 0; }
cond=r[17]&1u;
fr[12]^=0x80000000u;
if(!cond) { goto P_0c087f40; }
goto P_0c087f3e;
P_0c087f3c: /* original fc4d, guest PC 0x0c087f3c */
if(!s->budget--) { s->failed_pc=0x0c087f3cu; return 0; }
fr[12]^=0x80000000u;
goto P_0c087f3e;
P_0c087f3e: /* original ff4d, guest PC 0x0c087f3e */
if(!s->budget--) { s->failed_pc=0x0c087f3eu; return 0; }
fr[15]^=0x80000000u;
goto P_0c087f40;
P_0c087f40: /* original 66f3, guest PC 0x0c087f40 */
if(!s->budget--) { s->failed_pc=0x0c087f40u; return 0; }
r[6]=r[15];
goto P_0c087f42;
P_0c087f42: /* original 65f3, guest PC 0x0c087f42 */
if(!s->budget--) { s->failed_pc=0x0c087f42u; return 0; }
r[5]=r[15];
goto P_0c087f44;
P_0c087f44: /* original f6cc, guest PC 0x0c087f44 */
if(!s->budget--) { s->failed_pc=0x0c087f44u; return 0; }
vf3_matrix_move(s,6,12);
goto P_0c087f46;
P_0c087f46: /* original 7504, guest PC 0x0c087f46 */
if(!s->budget--) { s->failed_pc=0x0c087f46u; return 0; }
r[5]+=0x00000004u;
goto P_0c087f48;
P_0c087f48: /* original 7608, guest PC 0x0c087f48 */
if(!s->budget--) { s->failed_pc=0x0c087f48u; return 0; }
r[6]+=0x00000008u;
goto P_0c087f4a;
P_0c087f4a: /* original f4fc, guest PC 0x0c087f4a */
if(!s->budget--) { s->failed_pc=0x0c087f4au; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c087f4c;
P_0c087f4c: /* original f5dc, guest PC 0x0c087f4c */
if(!s->budget--) { s->failed_pc=0x0c087f4cu; return 0; }
vf3_matrix_move(s,5,13);
goto P_0c087f4e;
P_0c087f4e: /* original bbd0, guest PC 0x0c087f4e */
if(!s->budget--) { s->failed_pc=0x0c087f4eu; return 0; }
target=code_base|0x0c0876f2u; r[16]=code_base|0x0c087f52u;
r[4]=r[15];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c087f52u) { target=s->pc; goto dispatch; }
goto P_0c087f52;
P_0c087f50: /* original 64f3, guest PC 0x0c087f50 */
if(!s->budget--) { s->failed_pc=0x0c087f50u; return 0; }
r[4]=r[15];
goto P_0c087f52;
P_0c087f52: /* original f4f8, guest PC 0x0c087f52 */
if(!s->budget--) { s->failed_pc=0x0c087f52u; return 0; }
vf3_matrix_load(s,ram,4,r[15]);
goto P_0c087f54;
P_0c087f54: /* original bd41, guest PC 0x0c087f54 */
if(!s->budget--) { s->failed_pc=0x0c087f54u; return 0; }
target=code_base|0x0c0879dau; r[16]=code_base|0x0c087f58u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c087f58u) { target=s->pc; goto dispatch; }
goto P_0c087f58;
P_0c087f56: /* original 64d3, guest PC 0x0c087f56 */
if(!s->budget--) { s->failed_pc=0x0c087f56u; return 0; }
r[4]=r[13];
goto P_0c087f58;
P_0c087f58: /* original e004, guest PC 0x0c087f58 */
if(!s->budget--) { s->failed_pc=0x0c087f58u; return 0; }
r[0]=0x00000004u;
goto P_0c087f5a;
P_0c087f5a: /* original f40c, guest PC 0x0c087f5a */
if(!s->budget--) { s->failed_pc=0x0c087f5au; return 0; }
vf3_matrix_move(s,4,0);
goto P_0c087f5c;
P_0c087f5c: /* original f3f6, guest PC 0x0c087f5c */
if(!s->budget--) { s->failed_pc=0x0c087f5cu; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c087f5e;
P_0c087f5e: /* original f28d, guest PC 0x0c087f5e */
if(!s->budget--) { s->failed_pc=0x0c087f5eu; return 0; }
fr[2]=0;
goto P_0c087f60;
P_0c087f60: /* original f431, guest PC 0x0c087f60 */
if(!s->budget--) { s->failed_pc=0x0c087f60u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'-');
goto P_0c087f62;
P_0c087f62: /* original f245, guest PC 0x0c087f62 */
if(!s->budget--) { s->failed_pc=0x0c087f62u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[2])>as_float(fr[4]))!=0);
goto P_0c087f64;
P_0c087f64: /* original 8f02, guest PC 0x0c087f64 */
if(!s->budget--) { s->failed_pc=0x0c087f64u; return 0; }
cond=r[17]&1u;
vf3_matrix_move(s,5,13);
if(!cond) { goto P_0c087f6c; }
goto P_0c087f68;
P_0c087f66: /* original f5dc, guest PC 0x0c087f66 */
if(!s->budget--) { s->failed_pc=0x0c087f66u; return 0; }
vf3_matrix_move(s,5,13);
goto P_0c087f68;
P_0c087f68: /* original e00c, guest PC 0x0c087f68 */
if(!s->budget--) { s->failed_pc=0x0c087f68u; return 0; }
r[0]=0x0000000cu;
goto P_0c087f6a;
P_0c087f6a: /* original f4f6, guest PC 0x0c087f6a */
if(!s->budget--) { s->failed_pc=0x0c087f6au; return 0; }
vf3_matrix_load(s,ram,4,r[15]+r[0]);
goto P_0c087f6c;
P_0c087f6c: /* original f54d, guest PC 0x0c087f6c */
if(!s->budget--) { s->failed_pc=0x0c087f6cu; return 0; }
fr[5]^=0x80000000u;
goto P_0c087f6e;
P_0c087f6e: /* original f65c, guest PC 0x0c087f6e */
if(!s->budget--) { s->failed_pc=0x0c087f6eu; return 0; }
vf3_matrix_move(s,6,5);
goto P_0c087f70;
P_0c087f70: /* original f641, guest PC 0x0c087f70 */
if(!s->budget--) { s->failed_pc=0x0c087f70u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[4],r[18],'-');
goto P_0c087f72;
P_0c087f72: /* original f38d, guest PC 0x0c087f72 */
if(!s->budget--) { s->failed_pc=0x0c087f72u; return 0; }
fr[3]=0;
goto P_0c087f74;
P_0c087f74: /* original f365, guest PC 0x0c087f74 */
if(!s->budget--) { s->failed_pc=0x0c087f74u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[6]))!=0);
goto P_0c087f76;
P_0c087f76: /* original 8b00, guest PC 0x0c087f76 */
if(!s->budget--) { s->failed_pc=0x0c087f76u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c087f7a; }
goto P_0c087f78;
P_0c087f78: /* original f45c, guest PC 0x0c087f78 */
if(!s->budget--) { s->failed_pc=0x0c087f78u; return 0; }
vf3_matrix_move(s,4,5);
goto P_0c087f7a;
P_0c087f7a: /* original e010, guest PC 0x0c087f7a */
if(!s->budget--) { s->failed_pc=0x0c087f7au; return 0; }
r[0]=0x00000010u;
goto P_0c087f7c;
P_0c087f7c: /* original f34c, guest PC 0x0c087f7c */
if(!s->budget--) { s->failed_pc=0x0c087f7cu; return 0; }
vf3_matrix_move(s,3,4);
goto P_0c087f7e;
P_0c087f7e: /* original f4f6, guest PC 0x0c087f7e */
if(!s->budget--) { s->failed_pc=0x0c087f7eu; return 0; }
vf3_matrix_load(s,ram,4,r[15]+r[0]);
goto P_0c087f80;
P_0c087f80: /* original e004, guest PC 0x0c087f80 */
if(!s->budget--) { s->failed_pc=0x0c087f80u; return 0; }
r[0]=0x00000004u;
goto P_0c087f82;
P_0c087f82: /* original 53fb, guest PC 0x0c087f82 */
if(!s->budget--) { s->failed_pc=0x0c087f82u; return 0; }
r[3]=read(ram,r[15]+44,4);
goto P_0c087f84;
P_0c087f84: /* original f432, guest PC 0x0c087f84 */
if(!s->budget--) { s->failed_pc=0x0c087f84u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'*');
goto P_0c087f86;
P_0c087f86: /* original f3f8, guest PC 0x0c087f86 */
if(!s->budget--) { s->failed_pc=0x0c087f86u; return 0; }
vf3_matrix_load(s,ram,3,r[15]);
goto P_0c087f88;
P_0c087f88: /* original f33a, guest PC 0x0c087f88 */
if(!s->budget--) { s->failed_pc=0x0c087f88u; return 0; }
vf3_matrix_store(s,ram,3,r[3]);
goto P_0c087f8a;
P_0c087f8a: /* original f3f6, guest PC 0x0c087f8a */
if(!s->budget--) { s->failed_pc=0x0c087f8au; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c087f8c;
P_0c087f8c: /* original e008, guest PC 0x0c087f8c */
if(!s->budget--) { s->failed_pc=0x0c087f8cu; return 0; }
r[0]=0x00000008u;
goto P_0c087f8e;
P_0c087f8e: /* original 53fc, guest PC 0x0c087f8e */
if(!s->budget--) { s->failed_pc=0x0c087f8eu; return 0; }
r[3]=read(ram,r[15]+48,4);
goto P_0c087f90;
P_0c087f90: /* original f33a, guest PC 0x0c087f90 */
if(!s->budget--) { s->failed_pc=0x0c087f90u; return 0; }
vf3_matrix_store(s,ram,3,r[3]);
goto P_0c087f92;
P_0c087f92: /* original f3f6, guest PC 0x0c087f92 */
if(!s->budget--) { s->failed_pc=0x0c087f92u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c087f94;
P_0c087f94: /* original 60c3, guest PC 0x0c087f94 */
if(!s->budget--) { s->failed_pc=0x0c087f94u; return 0; }
r[0]=r[12];
goto P_0c087f96;
P_0c087f96: /* original 8801, guest PC 0x0c087f96 */
if(!s->budget--) { s->failed_pc=0x0c087f96u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c087f98;
P_0c087f98: /* original fb3a, guest PC 0x0c087f98 */
if(!s->budget--) { s->failed_pc=0x0c087f98u; return 0; }
vf3_matrix_store(s,ram,3,r[11]);
goto P_0c087f9a;
P_0c087f9a: /* original 8f05, guest PC 0x0c087f9a */
if(!s->budget--) { s->failed_pc=0x0c087f9au; return 0; }
cond=r[17]&1u;
vf3_matrix_store(s,ram,4,r[10]);
if(!cond) { goto P_0c087fa8; }
goto P_0c087f9e;
P_0c087f9c: /* original fa4a, guest PC 0x0c087f9c */
if(!s->budget--) { s->failed_pc=0x0c087f9cu; return 0; }
vf3_matrix_store(s,ram,4,r[10]);
goto P_0c087f9e;
P_0c087f9e: /* original c71f, guest PC 0x0c087f9e */
if(!s->budget--) { s->failed_pc=0x0c087f9eu; return 0; }
r[0]=code_base|0x0008801cu;
goto P_0c087fa0;
P_0c087fa0: /* original ffec, guest PC 0x0c087fa0 */
if(!s->budget--) { s->failed_pc=0x0c087fa0u; return 0; }
vf3_matrix_move(s,15,14);
goto P_0c087fa2;
P_0c087fa2: /* original fd08, guest PC 0x0c087fa2 */
if(!s->budget--) { s->failed_pc=0x0c087fa2u; return 0; }
vf3_matrix_load(s,ram,13,r[0]);
goto P_0c087fa4;
P_0c087fa4: /* original c71e, guest PC 0x0c087fa4 */
if(!s->budget--) { s->failed_pc=0x0c087fa4u; return 0; }
r[0]=code_base|0x00088020u;
goto P_0c087fa6;
P_0c087fa6: /* original fc08, guest PC 0x0c087fa6 */
if(!s->budget--) { s->failed_pc=0x0c087fa6u; return 0; }
vf3_matrix_load(s,ram,12,r[0]);
goto P_0c087fa8;
P_0c087fa8: /* original 66f3, guest PC 0x0c087fa8 */
if(!s->budget--) { s->failed_pc=0x0c087fa8u; return 0; }
r[6]=r[15];
goto P_0c087faa;
P_0c087faa: /* original 65f3, guest PC 0x0c087faa */
if(!s->budget--) { s->failed_pc=0x0c087faau; return 0; }
r[5]=r[15];
goto P_0c087fac;
P_0c087fac: /* original ff4d, guest PC 0x0c087fac */
if(!s->budget--) { s->failed_pc=0x0c087facu; return 0; }
fr[15]^=0x80000000u;
goto P_0c087fae;
P_0c087fae: /* original e034, guest PC 0x0c087fae */
if(!s->budget--) { s->failed_pc=0x0c087faeu; return 0; }
r[0]=0x00000034u;
goto P_0c087fb0;
P_0c087fb0: /* original 7608, guest PC 0x0c087fb0 */
if(!s->budget--) { s->failed_pc=0x0c087fb0u; return 0; }
r[6]+=0x00000008u;
goto P_0c087fb2;
P_0c087fb2: /* original fff7, guest PC 0x0c087fb2 */
if(!s->budget--) { s->failed_pc=0x0c087fb2u; return 0; }
vf3_matrix_store(s,ram,15,r[15]+r[0]);
goto P_0c087fb4;
P_0c087fb4: /* original 7504, guest PC 0x0c087fb4 */
if(!s->budget--) { s->failed_pc=0x0c087fb4u; return 0; }
r[5]+=0x00000004u;
goto P_0c087fb6;
P_0c087fb6: /* original f6cc, guest PC 0x0c087fb6 */
if(!s->budget--) { s->failed_pc=0x0c087fb6u; return 0; }
vf3_matrix_move(s,6,12);
goto P_0c087fb8;
P_0c087fb8: /* original f4fc, guest PC 0x0c087fb8 */
if(!s->budget--) { s->failed_pc=0x0c087fb8u; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c087fba;
P_0c087fba: /* original f5dc, guest PC 0x0c087fba */
if(!s->budget--) { s->failed_pc=0x0c087fbau; return 0; }
vf3_matrix_move(s,5,13);
goto P_0c087fbc;
P_0c087fbc: /* original bb99, guest PC 0x0c087fbc */
if(!s->budget--) { s->failed_pc=0x0c087fbcu; return 0; }
target=code_base|0x0c0876f2u; r[16]=code_base|0x0c087fc0u;
r[4]=r[15];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c087fc0u) { target=s->pc; goto dispatch; }
goto P_0c087fc0;
P_0c087fbe: /* original 64f3, guest PC 0x0c087fbe */
if(!s->budget--) { s->failed_pc=0x0c087fbeu; return 0; }
r[4]=r[15];
goto P_0c087fc0;
P_0c087fc0: /* original f4f8, guest PC 0x0c087fc0 */
if(!s->budget--) { s->failed_pc=0x0c087fc0u; return 0; }
vf3_matrix_load(s,ram,4,r[15]);
goto P_0c087fc2;
P_0c087fc2: /* original bd0a, guest PC 0x0c087fc2 */
if(!s->budget--) { s->failed_pc=0x0c087fc2u; return 0; }
target=code_base|0x0c0879dau; r[16]=code_base|0x0c087fc6u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c087fc6u) { target=s->pc; goto dispatch; }
goto P_0c087fc6;
P_0c087fc4: /* original 64d3, guest PC 0x0c087fc4 */
if(!s->budget--) { s->failed_pc=0x0c087fc4u; return 0; }
r[4]=r[13];
goto P_0c087fc6;
P_0c087fc6: /* original e004, guest PC 0x0c087fc6 */
if(!s->budget--) { s->failed_pc=0x0c087fc6u; return 0; }
r[0]=0x00000004u;
goto P_0c087fc8;
P_0c087fc8: /* original f40c, guest PC 0x0c087fc8 */
if(!s->budget--) { s->failed_pc=0x0c087fc8u; return 0; }
vf3_matrix_move(s,4,0);
goto P_0c087fca;
P_0c087fca: /* original f3f6, guest PC 0x0c087fca */
if(!s->budget--) { s->failed_pc=0x0c087fcau; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c087fcc;
P_0c087fcc: /* original f28d, guest PC 0x0c087fcc */
if(!s->budget--) { s->failed_pc=0x0c087fccu; return 0; }
fr[2]=0;
goto P_0c087fce;
P_0c087fce: /* original f431, guest PC 0x0c087fce */
if(!s->budget--) { s->failed_pc=0x0c087fceu; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'-');
goto P_0c087fd0;
P_0c087fd0: /* original f245, guest PC 0x0c087fd0 */
if(!s->budget--) { s->failed_pc=0x0c087fd0u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[2])>as_float(fr[4]))!=0);
goto P_0c087fd2;
P_0c087fd2: /* original 8f02, guest PC 0x0c087fd2 */
if(!s->budget--) { s->failed_pc=0x0c087fd2u; return 0; }
cond=r[17]&1u;
vf3_matrix_move(s,15,13);
if(!cond) { goto P_0c087fda; }
goto P_0c087fd6;
P_0c087fd4: /* original ffdc, guest PC 0x0c087fd4 */
if(!s->budget--) { s->failed_pc=0x0c087fd4u; return 0; }
vf3_matrix_move(s,15,13);
goto P_0c087fd6;
P_0c087fd6: /* original e00c, guest PC 0x0c087fd6 */
if(!s->budget--) { s->failed_pc=0x0c087fd6u; return 0; }
r[0]=0x0000000cu;
goto P_0c087fd8;
P_0c087fd8: /* original f4f6, guest PC 0x0c087fd8 */
if(!s->budget--) { s->failed_pc=0x0c087fd8u; return 0; }
vf3_matrix_load(s,ram,4,r[15]+r[0]);
goto P_0c087fda;
P_0c087fda: /* original ff4d, guest PC 0x0c087fda */
if(!s->budget--) { s->failed_pc=0x0c087fdau; return 0; }
fr[15]^=0x80000000u;
goto P_0c087fdc;
P_0c087fdc: /* original f5fc, guest PC 0x0c087fdc */
if(!s->budget--) { s->failed_pc=0x0c087fdcu; return 0; }
vf3_matrix_move(s,5,15);
goto P_0c087fde;
P_0c087fde: /* original f541, guest PC 0x0c087fde */
if(!s->budget--) { s->failed_pc=0x0c087fdeu; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[4],r[18],'-');
goto P_0c087fe0;
P_0c087fe0: /* original f38d, guest PC 0x0c087fe0 */
if(!s->budget--) { s->failed_pc=0x0c087fe0u; return 0; }
fr[3]=0;
goto P_0c087fe2;
P_0c087fe2: /* original f355, guest PC 0x0c087fe2 */
if(!s->budget--) { s->failed_pc=0x0c087fe2u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[5]))!=0);
goto P_0c087fe4;
P_0c087fe4: /* original 8b00, guest PC 0x0c087fe4 */
if(!s->budget--) { s->failed_pc=0x0c087fe4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c087fe8; }
goto P_0c087fe6;
P_0c087fe6: /* original f4fc, guest PC 0x0c087fe6 */
if(!s->budget--) { s->failed_pc=0x0c087fe6u; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c087fe8;
P_0c087fe8: /* original e010, guest PC 0x0c087fe8 */
if(!s->budget--) { s->failed_pc=0x0c087fe8u; return 0; }
r[0]=0x00000010u;
goto P_0c087fea;
P_0c087fea: /* original f34c, guest PC 0x0c087fea */
if(!s->budget--) { s->failed_pc=0x0c087feau; return 0; }
vf3_matrix_move(s,3,4);
goto P_0c087fec;
P_0c087fec: /* original f4f6, guest PC 0x0c087fec */
if(!s->budget--) { s->failed_pc=0x0c087fecu; return 0; }
vf3_matrix_load(s,ram,4,r[15]+r[0]);
goto P_0c087fee;
P_0c087fee: /* original e004, guest PC 0x0c087fee */
if(!s->budget--) { s->failed_pc=0x0c087feeu; return 0; }
r[0]=0x00000004u;
goto P_0c087ff0;
P_0c087ff0: /* original f432, guest PC 0x0c087ff0 */
if(!s->budget--) { s->failed_pc=0x0c087ff0u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'*');
goto P_0c087ff2;
P_0c087ff2: /* original f3f8, guest PC 0x0c087ff2 */
if(!s->budget--) { s->failed_pc=0x0c087ff2u; return 0; }
vf3_matrix_load(s,ram,3,r[15]);
goto P_0c087ff4;
P_0c087ff4: /* original f93a, guest PC 0x0c087ff4 */
if(!s->budget--) { s->failed_pc=0x0c087ff4u; return 0; }
vf3_matrix_store(s,ram,3,r[9]);
goto P_0c087ff6;
P_0c087ff6: /* original f3f6, guest PC 0x0c087ff6 */
if(!s->budget--) { s->failed_pc=0x0c087ff6u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c087ff8;
P_0c087ff8: /* original e008, guest PC 0x0c087ff8 */
if(!s->budget--) { s->failed_pc=0x0c087ff8u; return 0; }
r[0]=0x00000008u;
goto P_0c087ffa;
P_0c087ffa: /* original f83a, guest PC 0x0c087ffa */
if(!s->budget--) { s->failed_pc=0x0c087ffau; return 0; }
vf3_matrix_store(s,ram,3,r[8]);
goto P_0c087ffc;
P_0c087ffc: /* original f3f6, guest PC 0x0c087ffc */
if(!s->budget--) { s->failed_pc=0x0c087ffcu; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c087ffe;
P_0c087ffe: /* original 53f8, guest PC 0x0c087ffe */
if(!s->budget--) { s->failed_pc=0x0c087ffeu; return 0; }
r[3]=read(ram,r[15]+32,4);
goto P_0c088000;
P_0c088000: /* original f33a, guest PC 0x0c088000 */
if(!s->budget--) { s->failed_pc=0x0c088000u; return 0; }
vf3_matrix_store(s,ram,3,r[3]);
goto P_0c088002;
P_0c088002: /* original 53f7, guest PC 0x0c088002 */
if(!s->budget--) { s->failed_pc=0x0c088002u; return 0; }
r[3]=read(ram,r[15]+28,4);
goto P_0c088004;
P_0c088004: /* original f34a, guest PC 0x0c088004 */
if(!s->budget--) { s->failed_pc=0x0c088004u; return 0; }
vf3_matrix_store(s,ram,4,r[3]);
goto P_0c088006;
P_0c088006: /* original f6cc, guest PC 0x0c088006 */
if(!s->budget--) { s->failed_pc=0x0c088006u; return 0; }
vf3_matrix_move(s,6,12);
goto P_0c088008;
P_0c088008: /* original f64d, guest PC 0x0c088008 */
if(!s->budget--) { s->failed_pc=0x0c088008u; return 0; }
fr[6]^=0x80000000u;
goto P_0c08800a;
P_0c08800a: /* original a00b, guest PC 0x0c08800a */
if(!s->budget--) { s->failed_pc=0x0c08800au; return 0; }
goto P_0c088024;
P_0c08800c: /* original 0009, guest PC 0x0c08800c */
if(!s->budget--) { s->failed_pc=0x0c08800cu; return 0; }
if(!vf3_matrix_family(0x0c08800eu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c08800eu; return 0; } return 1;
P_0c088024: /* original e034, guest PC 0x0c088024 */
if(!s->budget--) { s->failed_pc=0x0c088024u; return 0; }
r[0]=0x00000034u;
goto P_0c088026;
P_0c088026: /* original 66f3, guest PC 0x0c088026 */
if(!s->budget--) { s->failed_pc=0x0c088026u; return 0; }
r[6]=r[15];
goto P_0c088028;
P_0c088028: /* original 65f3, guest PC 0x0c088028 */
if(!s->budget--) { s->failed_pc=0x0c088028u; return 0; }
r[5]=r[15];
goto P_0c08802a;
P_0c08802a: /* original f4f6, guest PC 0x0c08802a */
if(!s->budget--) { s->failed_pc=0x0c08802au; return 0; }
vf3_matrix_load(s,ram,4,r[15]+r[0]);
goto P_0c08802c;
P_0c08802c: /* original 7504, guest PC 0x0c08802c */
if(!s->budget--) { s->failed_pc=0x0c08802cu; return 0; }
r[5]+=0x00000004u;
goto P_0c08802e;
P_0c08802e: /* original f5dc, guest PC 0x0c08802e */
if(!s->budget--) { s->failed_pc=0x0c08802eu; return 0; }
vf3_matrix_move(s,5,13);
goto P_0c088030;
P_0c088030: /* original 7608, guest PC 0x0c088030 */
if(!s->budget--) { s->failed_pc=0x0c088030u; return 0; }
r[6]+=0x00000008u;
goto P_0c088032;
P_0c088032: /* original bb5e, guest PC 0x0c088032 */
if(!s->budget--) { s->failed_pc=0x0c088032u; return 0; }
target=code_base|0x0c0876f2u; r[16]=code_base|0x0c088036u;
r[4]=r[15];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c088036u) { target=s->pc; goto dispatch; }
goto P_0c088036;
P_0c088034: /* original 64f3, guest PC 0x0c088034 */
if(!s->budget--) { s->failed_pc=0x0c088034u; return 0; }
r[4]=r[15];
goto P_0c088036;
P_0c088036: /* original f4f8, guest PC 0x0c088036 */
if(!s->budget--) { s->failed_pc=0x0c088036u; return 0; }
vf3_matrix_load(s,ram,4,r[15]);
goto P_0c088038;
P_0c088038: /* original bccf, guest PC 0x0c088038 */
if(!s->budget--) { s->failed_pc=0x0c088038u; return 0; }
target=code_base|0x0c0879dau; r[16]=code_base|0x0c08803cu;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08803cu) { target=s->pc; goto dispatch; }
goto P_0c08803c;
P_0c08803a: /* original 64d3, guest PC 0x0c08803a */
if(!s->budget--) { s->failed_pc=0x0c08803au; return 0; }
r[4]=r[13];
goto P_0c08803c;
P_0c08803c: /* original e004, guest PC 0x0c08803c */
if(!s->budget--) { s->failed_pc=0x0c08803cu; return 0; }
r[0]=0x00000004u;
goto P_0c08803e;
P_0c08803e: /* original f40c, guest PC 0x0c08803e */
if(!s->budget--) { s->failed_pc=0x0c08803eu; return 0; }
vf3_matrix_move(s,4,0);
goto P_0c088040;
P_0c088040: /* original f3f6, guest PC 0x0c088040 */
if(!s->budget--) { s->failed_pc=0x0c088040u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c088042;
P_0c088042: /* original f28d, guest PC 0x0c088042 */
if(!s->budget--) { s->failed_pc=0x0c088042u; return 0; }
fr[2]=0;
goto P_0c088044;
P_0c088044: /* original f431, guest PC 0x0c088044 */
if(!s->budget--) { s->failed_pc=0x0c088044u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'-');
goto P_0c088046;
P_0c088046: /* original f245, guest PC 0x0c088046 */
if(!s->budget--) { s->failed_pc=0x0c088046u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[2])>as_float(fr[4]))!=0);
goto P_0c088048;
P_0c088048: /* original 8f02, guest PC 0x0c088048 */
if(!s->budget--) { s->failed_pc=0x0c088048u; return 0; }
cond=r[17]&1u;
vf3_matrix_move(s,5,15);
if(!cond) { goto P_0c088050; }
goto P_0c08804c;
P_0c08804a: /* original f5fc, guest PC 0x0c08804a */
if(!s->budget--) { s->failed_pc=0x0c08804au; return 0; }
vf3_matrix_move(s,5,15);
goto P_0c08804c;
P_0c08804c: /* original e00c, guest PC 0x0c08804c */
if(!s->budget--) { s->failed_pc=0x0c08804cu; return 0; }
r[0]=0x0000000cu;
goto P_0c08804e;
P_0c08804e: /* original f4f6, guest PC 0x0c08804e */
if(!s->budget--) { s->failed_pc=0x0c08804eu; return 0; }
vf3_matrix_load(s,ram,4,r[15]+r[0]);
goto P_0c088050;
P_0c088050: /* original f541, guest PC 0x0c088050 */
if(!s->budget--) { s->failed_pc=0x0c088050u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[4],r[18],'-');
goto P_0c088052;
P_0c088052: /* original f38d, guest PC 0x0c088052 */
if(!s->budget--) { s->failed_pc=0x0c088052u; return 0; }
fr[3]=0;
goto P_0c088054;
P_0c088054: /* original f355, guest PC 0x0c088054 */
if(!s->budget--) { s->failed_pc=0x0c088054u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[5]))!=0);
goto P_0c088056;
P_0c088056: /* original 8b00, guest PC 0x0c088056 */
if(!s->budget--) { s->failed_pc=0x0c088056u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c08805a; }
goto P_0c088058;
P_0c088058: /* original f4fc, guest PC 0x0c088058 */
if(!s->budget--) { s->failed_pc=0x0c088058u; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c08805a;
P_0c08805a: /* original e010, guest PC 0x0c08805a */
if(!s->budget--) { s->failed_pc=0x0c08805au; return 0; }
r[0]=0x00000010u;
goto P_0c08805c;
P_0c08805c: /* original ffec, guest PC 0x0c08805c */
if(!s->budget--) { s->failed_pc=0x0c08805cu; return 0; }
vf3_matrix_move(s,15,14);
goto P_0c08805e;
P_0c08805e: /* original f8f6, guest PC 0x0c08805e */
if(!s->budget--) { s->failed_pc=0x0c08805eu; return 0; }
vf3_matrix_load(s,ram,8,r[15]+r[0]);
goto P_0c088060;
P_0c088060: /* original e008, guest PC 0x0c088060 */
if(!s->budget--) { s->failed_pc=0x0c088060u; return 0; }
r[0]=0x00000008u;
goto P_0c088062;
P_0c088062: /* original f6f6, guest PC 0x0c088062 */
if(!s->budget--) { s->failed_pc=0x0c088062u; return 0; }
vf3_matrix_load(s,ram,6,r[15]+r[0]);
goto P_0c088064;
P_0c088064: /* original e004, guest PC 0x0c088064 */
if(!s->budget--) { s->failed_pc=0x0c088064u; return 0; }
r[0]=0x00000004u;
goto P_0c088066;
P_0c088066: /* original f842, guest PC 0x0c088066 */
if(!s->budget--) { s->failed_pc=0x0c088066u; return 0; }
fr[8]=vf3_fpu_binary(fr[8],fr[4],r[18],'*');
goto P_0c088068;
P_0c088068: /* original f4f8, guest PC 0x0c088068 */
if(!s->budget--) { s->failed_pc=0x0c088068u; return 0; }
vf3_matrix_load(s,ram,4,r[15]);
goto P_0c08806a;
P_0c08806a: /* original f5f6, guest PC 0x0c08806a */
if(!s->budget--) { s->failed_pc=0x0c08806au; return 0; }
vf3_matrix_load(s,ram,5,r[15]+r[0]);
goto P_0c08806c;
P_0c08806c: /* original f9ec, guest PC 0x0c08806c */
if(!s->budget--) { s->failed_pc=0x0c08806cu; return 0; }
vf3_matrix_move(s,9,14);
goto P_0c08806e;
P_0c08806e: /* original f7ec, guest PC 0x0c08806e */
if(!s->budget--) { s->failed_pc=0x0c08806eu; return 0; }
vf3_matrix_move(s,7,14);
goto P_0c088070;
P_0c088070: /* original bc3a, guest PC 0x0c088070 */
if(!s->budget--) { s->failed_pc=0x0c088070u; return 0; }
target=code_base|0x0c0878e8u; r[16]=code_base|0x0c088074u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c088074u) { target=s->pc; goto dispatch; }
goto P_0c088074;
P_0c088072: /* original 64e3, guest PC 0x0c088072 */
if(!s->budget--) { s->failed_pc=0x0c088072u; return 0; }
r[4]=r[14];
goto P_0c088074;
P_0c088074: /* original 53f8, guest PC 0x0c088074 */
if(!s->budget--) { s->failed_pc=0x0c088074u; return 0; }
r[3]=read(ram,r[15]+32,4);
goto P_0c088076;
P_0c088076: /* original 52f7, guest PC 0x0c088076 */
if(!s->budget--) { s->failed_pc=0x0c088076u; return 0; }
r[2]=read(ram,r[15]+28,4);
goto P_0c088078;
P_0c088078: /* original f638, guest PC 0x0c088078 */
if(!s->budget--) { s->failed_pc=0x0c088078u; return 0; }
vf3_matrix_load(s,ram,6,r[3]);
goto P_0c08807a;
P_0c08807a: /* original f588, guest PC 0x0c08807a */
if(!s->budget--) { s->failed_pc=0x0c08807au; return 0; }
vf3_matrix_load(s,ram,5,r[8]);
goto P_0c08807c;
P_0c08807c: /* original f498, guest PC 0x0c08807c */
if(!s->budget--) { s->failed_pc=0x0c08807cu; return 0; }
vf3_matrix_load(s,ram,4,r[9]);
goto P_0c08807e;
P_0c08807e: /* original f828, guest PC 0x0c08807e */
if(!s->budget--) { s->failed_pc=0x0c08807eu; return 0; }
vf3_matrix_load(s,ram,8,r[2]);
goto P_0c088080;
P_0c088080: /* original f9fc, guest PC 0x0c088080 */
if(!s->budget--) { s->failed_pc=0x0c088080u; return 0; }
vf3_matrix_move(s,9,15);
goto P_0c088082;
P_0c088082: /* original f7fc, guest PC 0x0c088082 */
if(!s->budget--) { s->failed_pc=0x0c088082u; return 0; }
vf3_matrix_move(s,7,15);
goto P_0c088084;
P_0c088084: /* original bc30, guest PC 0x0c088084 */
if(!s->budget--) { s->failed_pc=0x0c088084u; return 0; }
target=code_base|0x0c0878e8u; r[16]=code_base|0x0c088088u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c088088u) { target=s->pc; goto dispatch; }
goto P_0c088088;
P_0c088086: /* original 64e3, guest PC 0x0c088086 */
if(!s->budget--) { s->failed_pc=0x0c088086u; return 0; }
r[4]=r[14];
goto P_0c088088;
P_0c088088: /* original 52fc, guest PC 0x0c088088 */
if(!s->budget--) { s->failed_pc=0x0c088088u; return 0; }
r[2]=read(ram,r[15]+48,4);
goto P_0c08808a;
P_0c08808a: /* original 53fb, guest PC 0x0c08808a */
if(!s->budget--) { s->failed_pc=0x0c08808au; return 0; }
r[3]=read(ram,r[15]+44,4);
goto P_0c08808c;
P_0c08808c: /* original f528, guest PC 0x0c08808c */
if(!s->budget--) { s->failed_pc=0x0c08808cu; return 0; }
vf3_matrix_load(s,ram,5,r[2]);
goto P_0c08808e;
P_0c08808e: /* original f438, guest PC 0x0c08808e */
if(!s->budget--) { s->failed_pc=0x0c08808eu; return 0; }
vf3_matrix_load(s,ram,4,r[3]);
goto P_0c088090;
P_0c088090: /* original f8a8, guest PC 0x0c088090 */
if(!s->budget--) { s->failed_pc=0x0c088090u; return 0; }
vf3_matrix_load(s,ram,8,r[10]);
goto P_0c088092;
P_0c088092: /* original f6b8, guest PC 0x0c088092 */
if(!s->budget--) { s->failed_pc=0x0c088092u; return 0; }
vf3_matrix_load(s,ram,6,r[11]);
goto P_0c088094;
P_0c088094: /* original f9fc, guest PC 0x0c088094 */
if(!s->budget--) { s->failed_pc=0x0c088094u; return 0; }
vf3_matrix_move(s,9,15);
goto P_0c088096;
P_0c088096: /* original f7fc, guest PC 0x0c088096 */
if(!s->budget--) { s->failed_pc=0x0c088096u; return 0; }
vf3_matrix_move(s,7,15);
goto P_0c088098;
P_0c088098: /* original bc26, guest PC 0x0c088098 */
if(!s->budget--) { s->failed_pc=0x0c088098u; return 0; }
target=code_base|0x0c0878e8u; r[16]=code_base|0x0c08809cu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08809cu) { target=s->pc; goto dispatch; }
goto P_0c08809c;
P_0c08809a: /* original 64e3, guest PC 0x0c08809a */
if(!s->budget--) { s->failed_pc=0x0c08809au; return 0; }
r[4]=r[14];
goto P_0c08809c;
P_0c08809c: /* original 53f9, guest PC 0x0c08809c */
if(!s->budget--) { s->failed_pc=0x0c08809cu; return 0; }
r[3]=read(ram,r[15]+36,4);
goto P_0c08809e;
P_0c08809e: /* original 52fa, guest PC 0x0c08809e */
if(!s->budget--) { s->failed_pc=0x0c08809eu; return 0; }
r[2]=read(ram,r[15]+40,4);
goto P_0c0880a0;
P_0c0880a0: /* original f638, guest PC 0x0c0880a0 */
if(!s->budget--) { s->failed_pc=0x0c0880a0u; return 0; }
vf3_matrix_load(s,ram,6,r[3]);
goto P_0c0880a2;
P_0c0880a2: /* original f828, guest PC 0x0c0880a2 */
if(!s->budget--) { s->failed_pc=0x0c0880a2u; return 0; }
vf3_matrix_load(s,ram,8,r[2]);
goto P_0c0880a4;
P_0c0880a4: /* original 52f6, guest PC 0x0c0880a4 */
if(!s->budget--) { s->failed_pc=0x0c0880a4u; return 0; }
r[2]=read(ram,r[15]+24,4);
goto P_0c0880a6;
P_0c0880a6: /* original 53f5, guest PC 0x0c0880a6 */
if(!s->budget--) { s->failed_pc=0x0c0880a6u; return 0; }
r[3]=read(ram,r[15]+20,4);
goto P_0c0880a8;
P_0c0880a8: /* original f528, guest PC 0x0c0880a8 */
if(!s->budget--) { s->failed_pc=0x0c0880a8u; return 0; }
vf3_matrix_load(s,ram,5,r[2]);
goto P_0c0880aa;
P_0c0880aa: /* original f438, guest PC 0x0c0880aa */
if(!s->budget--) { s->failed_pc=0x0c0880aau; return 0; }
vf3_matrix_load(s,ram,4,r[3]);
goto P_0c0880ac;
P_0c0880ac: /* original f9fc, guest PC 0x0c0880ac */
if(!s->budget--) { s->failed_pc=0x0c0880acu; return 0; }
vf3_matrix_move(s,9,15);
goto P_0c0880ae;
P_0c0880ae: /* original f7fc, guest PC 0x0c0880ae */
if(!s->budget--) { s->failed_pc=0x0c0880aeu; return 0; }
vf3_matrix_move(s,7,15);
goto P_0c0880b0;
P_0c0880b0: /* original bc1a, guest PC 0x0c0880b0 */
if(!s->budget--) { s->failed_pc=0x0c0880b0u; return 0; }
target=code_base|0x0c0878e8u; r[16]=code_base|0x0c0880b4u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0880b4u) { target=s->pc; goto dispatch; }
goto P_0c0880b4;
P_0c0880b2: /* original 64e3, guest PC 0x0c0880b2 */
if(!s->budget--) { s->failed_pc=0x0c0880b2u; return 0; }
r[4]=r[14];
goto P_0c0880b4;
P_0c0880b4: /* original e034, guest PC 0x0c0880b4 */
if(!s->budget--) { s->failed_pc=0x0c0880b4u; return 0; }
r[0]=0x00000034u;
goto P_0c0880b6;
P_0c0880b6: /* original ffe6, guest PC 0x0c0880b6 */
if(!s->budget--) { s->failed_pc=0x0c0880b6u; return 0; }
vf3_matrix_load(s,ram,15,r[14]+r[0]);
goto P_0c0880b8;
P_0c0880b8: /* original e074, guest PC 0x0c0880b8 */
if(!s->budget--) { s->failed_pc=0x0c0880b8u; return 0; }
r[0]=0x00000074u;
goto P_0c0880ba;
P_0c0880ba: /* original f4e6, guest PC 0x0c0880ba */
if(!s->budget--) { s->failed_pc=0x0c0880bau; return 0; }
vf3_matrix_load(s,ram,4,r[14]+r[0]);
goto P_0c0880bc;
P_0c0880bc: /* original c720, guest PC 0x0c0880bc */
if(!s->budget--) { s->failed_pc=0x0c0880bcu; return 0; }
r[0]=code_base|0x00088140u;
goto P_0c0880be;
P_0c0880be: /* original f508, guest PC 0x0c0880be */
if(!s->budget--) { s->failed_pc=0x0c0880beu; return 0; }
vf3_matrix_load(s,ram,5,r[0]);
goto P_0c0880c0;
P_0c0880c0: /* original c720, guest PC 0x0c0880c0 */
if(!s->budget--) { s->failed_pc=0x0c0880c0u; return 0; }
r[0]=code_base|0x00088144u;
goto P_0c0880c2;
P_0c0880c2: /* original f608, guest PC 0x0c0880c2 */
if(!s->budget--) { s->failed_pc=0x0c0880c2u; return 0; }
vf3_matrix_load(s,ram,6,r[0]);
goto P_0c0880c4;
P_0c0880c4: /* original e074, guest PC 0x0c0880c4 */
if(!s->budget--) { s->failed_pc=0x0c0880c4u; return 0; }
r[0]=0x00000074u;
goto P_0c0880c6;
P_0c0880c6: /* original f06c, guest PC 0x0c0880c6 */
if(!s->budget--) { s->failed_pc=0x0c0880c6u; return 0; }
vf3_matrix_move(s,0,6);
goto P_0c0880c8;
P_0c0880c8: /* original f54e, guest PC 0x0c0880c8 */
if(!s->budget--) { s->failed_pc=0x0c0880c8u; return 0; }
fr[5]=vf3_fpu_mac(fr[0],fr[4],fr[5],r[18]);
goto P_0c0880ca;
P_0c0880ca: /* original f45c, guest PC 0x0c0880ca */
if(!s->budget--) { s->failed_pc=0x0c0880cau; return 0; }
vf3_matrix_move(s,4,5);
goto P_0c0880cc;
P_0c0880cc: /* original ff40, guest PC 0x0c0880cc */
if(!s->budget--) { s->failed_pc=0x0c0880ccu; return 0; }
fr[15]=vf3_fpu_binary(fr[15],fr[4],r[18],'+');
goto P_0c0880ce;
P_0c0880ce: /* original fe47, guest PC 0x0c0880ce */
if(!s->budget--) { s->failed_pc=0x0c0880ceu; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c0880d0;
P_0c0880d0: /* original e004, guest PC 0x0c0880d0 */
if(!s->budget--) { s->failed_pc=0x0c0880d0u; return 0; }
r[0]=0x00000004u;
goto P_0c0880d2;
P_0c0880d2: /* original 9432, guest PC 0x0c0880d2 */
if(!s->budget--) { s->failed_pc=0x0c0880d2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08813au,2);
goto P_0c0880d4;
P_0c0880d4: /* original 34ec, guest PC 0x0c0880d4 */
if(!s->budget--) { s->failed_pc=0x0c0880d4u; return 0; }
r[4]+=r[14];
goto P_0c0880d6;
P_0c0880d6: /* original f546, guest PC 0x0c0880d6 */
if(!s->budget--) { s->failed_pc=0x0c0880d6u; return 0; }
vf3_matrix_load(s,ram,5,r[4]+r[0]);
goto P_0c0880d8;
P_0c0880d8: /* original e008, guest PC 0x0c0880d8 */
if(!s->budget--) { s->failed_pc=0x0c0880d8u; return 0; }
r[0]=0x00000008u;
goto P_0c0880da;
P_0c0880da: /* original f646, guest PC 0x0c0880da */
if(!s->budget--) { s->failed_pc=0x0c0880dau; return 0; }
vf3_matrix_load(s,ram,6,r[4]+r[0]);
goto P_0c0880dc;
P_0c0880dc: /* original 6543, guest PC 0x0c0880dc */
if(!s->budget--) { s->failed_pc=0x0c0880dcu; return 0; }
r[5]=r[4];
goto P_0c0880de;
P_0c0880de: /* original 750c, guest PC 0x0c0880de */
if(!s->budget--) { s->failed_pc=0x0c0880deu; return 0; }
r[5]+=0x0000000cu;
goto P_0c0880e0;
P_0c0880e0: /* original f448, guest PC 0x0c0880e0 */
if(!s->budget--) { s->failed_pc=0x0c0880e0u; return 0; }
vf3_matrix_load(s,ram,4,r[4]);
goto P_0c0880e2;
P_0c0880e2: /* original c718, guest PC 0x0c0880e2 */
if(!s->budget--) { s->failed_pc=0x0c0880e2u; return 0; }
r[0]=code_base|0x00088144u;
goto P_0c0880e4;
P_0c0880e4: /* original f758, guest PC 0x0c0880e4 */
if(!s->budget--) { s->failed_pc=0x0c0880e4u; return 0; }
vf3_matrix_load(s,ram,7,r[5]);
goto P_0c0880e6;
P_0c0880e6: /* original f808, guest PC 0x0c0880e6 */
if(!s->budget--) { s->failed_pc=0x0c0880e6u; return 0; }
vf3_matrix_load(s,ram,8,r[0]);
goto P_0c0880e8;
P_0c0880e8: /* original f782, guest PC 0x0c0880e8 */
if(!s->budget--) { s->failed_pc=0x0c0880e8u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[8],r[18],'*');
goto P_0c0880ea;
P_0c0880ea: /* original f57a, guest PC 0x0c0880ea */
if(!s->budget--) { s->failed_pc=0x0c0880eau; return 0; }
vf3_matrix_store(s,ram,7,r[5]);
goto P_0c0880ec;
P_0c0880ec: /* original bb56, guest PC 0x0c0880ec */
if(!s->budget--) { s->failed_pc=0x0c0880ecu; return 0; }
target=code_base|0x0c08779cu; r[16]=code_base|0x0c0880f0u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0880f0u) { target=s->pc; goto dispatch; }
goto P_0c0880f0;
P_0c0880ee: /* original 64d3, guest PC 0x0c0880ee */
if(!s->budget--) { s->failed_pc=0x0c0880eeu; return 0; }
r[4]=r[13];
goto P_0c0880f0;
P_0c0880f0: /* original ba7e, guest PC 0x0c0880f0 */
if(!s->budget--) { s->failed_pc=0x0c0880f0u; return 0; }
target=code_base|0x0c0875f0u; r[16]=code_base|0x0c0880f4u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0880f4u) { target=s->pc; goto dispatch; }
goto P_0c0880f4;
P_0c0880f2: /* original 64e3, guest PC 0x0c0880f2 */
if(!s->budget--) { s->failed_pc=0x0c0880f2u; return 0; }
r[4]=r[14];
goto P_0c0880f4;
P_0c0880f4: /* original bad0, guest PC 0x0c0880f4 */
if(!s->budget--) { s->failed_pc=0x0c0880f4u; return 0; }
target=code_base|0x0c087698u; r[16]=code_base|0x0c0880f8u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0880f8u) { target=s->pc; goto dispatch; }
goto P_0c0880f8;
P_0c0880f6: /* original 64e3, guest PC 0x0c0880f6 */
if(!s->budget--) { s->failed_pc=0x0c0880f6u; return 0; }
r[4]=r[14];
goto P_0c0880f8;
P_0c0880f8: /* original e034, guest PC 0x0c0880f8 */
if(!s->budget--) { s->failed_pc=0x0c0880f8u; return 0; }
r[0]=0x00000034u;
goto P_0c0880fa;
P_0c0880fa: /* original fef7, guest PC 0x0c0880fa */
if(!s->budget--) { s->failed_pc=0x0c0880fau; return 0; }
vf3_matrix_store(s,ram,15,r[14]+r[0]);
goto P_0c0880fc;
P_0c0880fc: /* original 7cff, guest PC 0x0c0880fc */
if(!s->budget--) { s->failed_pc=0x0c0880fcu; return 0; }
r[12]+=0xffffffffu;
goto P_0c0880fe;
P_0c0880fe: /* original 931d, guest PC 0x0c0880fe */
if(!s->budget--) { s->failed_pc=0x0c0880feu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08813cu,2);
goto P_0c088100;
P_0c088100: /* original 3e3c, guest PC 0x0c088100 */
if(!s->budget--) { s->failed_pc=0x0c088100u; return 0; }
r[14]+=r[3];
goto P_0c088102;
P_0c088102: /* original 2cc8, guest PC 0x0c088102 */
if(!s->budget--) { s->failed_pc=0x0c088102u; return 0; }
r[17]=(r[17]&~1u)|(((r[12]&r[12])==0)!=0);
goto P_0c088104;
P_0c088104: /* original 8901, guest PC 0x0c088104 */
if(!s->budget--) { s->failed_pc=0x0c088104u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c08810a; }
goto P_0c088106;
P_0c088106: /* original aed9, guest PC 0x0c088106 */
if(!s->budget--) { s->failed_pc=0x0c088106u; return 0; }
goto P_0c087ebc;
P_0c088108: /* original 0009, guest PC 0x0c088108 */
if(!s->budget--) { s->failed_pc=0x0c088108u; return 0; }
goto P_0c08810a;
P_0c08810a: /* original d30f, guest PC 0x0c08810a */
if(!s->budget--) { s->failed_pc=0x0c08810au; return 0; }
r[3]=read(ram,0x0c088148u,4);
goto P_0c08810c;
P_0c08810c: /* original 430b, guest PC 0x0c08810c */
if(!s->budget--) { s->failed_pc=0x0c08810cu; return 0; }
target=r[3];
r[16]=code_base|0x0c088110u;
r[4]=0x00000001u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c088110u) { target=s->pc; goto dispatch; }
goto P_0c088110;
P_0c08810e: /* original e401, guest PC 0x0c08810e */
if(!s->budget--) { s->failed_pc=0x0c08810eu; return 0; }
r[4]=0x00000001u;
goto P_0c088110;
P_0c088110: /* original 9015, guest PC 0x0c088110 */
if(!s->budget--) { s->failed_pc=0x0c088110u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08813eu,2);
goto P_0c088112;
P_0c088112: /* original 04de, guest PC 0x0c088112 */
if(!s->budget--) { s->failed_pc=0x0c088112u; return 0; }
r[4]=read(ram,r[13]+r[0],4);
goto P_0c088114;
P_0c088114: /* original 70fc, guest PC 0x0c088114 */
if(!s->budget--) { s->failed_pc=0x0c088114u; return 0; }
r[0]+=0xfffffffcu;
goto P_0c088116;
P_0c088116: /* original 05de, guest PC 0x0c088116 */
if(!s->budget--) { s->failed_pc=0x0c088116u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c088118;
P_0c088118: /* original 7004, guest PC 0x0c088118 */
if(!s->budget--) { s->failed_pc=0x0c088118u; return 0; }
r[0]+=0x00000004u;
goto P_0c08811a;
P_0c08811a: /* original 345c, guest PC 0x0c08811a */
if(!s->budget--) { s->failed_pc=0x0c08811au; return 0; }
r[4]+=r[5];
goto P_0c08811c;
P_0c08811c: /* original 0d46, guest PC 0x0c08811c */
if(!s->budget--) { s->failed_pc=0x0c08811cu; return 0; }
write(ram,r[13]+r[0],r[4],4);
goto P_0c08811e;
P_0c08811e: /* original 7f68, guest PC 0x0c08811e */
if(!s->budget--) { s->failed_pc=0x0c08811eu; return 0; }
r[15]+=0x00000068u;
goto P_0c088120;
P_0c088120: /* original 4f26, guest PC 0x0c088120 */
if(!s->budget--) { s->failed_pc=0x0c088120u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c088122;
P_0c088122: /* original fcf9, guest PC 0x0c088122 */
if(!s->budget--) { s->failed_pc=0x0c088122u; return 0; }
vf3_matrix_load(s,ram,12,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c088124;
P_0c088124: /* original fdf9, guest PC 0x0c088124 */
if(!s->budget--) { s->failed_pc=0x0c088124u; return 0; }
vf3_matrix_load(s,ram,13,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c088126;
P_0c088126: /* original fef9, guest PC 0x0c088126 */
if(!s->budget--) { s->failed_pc=0x0c088126u; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c088128;
P_0c088128: /* original fff9, guest PC 0x0c088128 */
if(!s->budget--) { s->failed_pc=0x0c088128u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c08812a;
P_0c08812a: /* original 68f6, guest PC 0x0c08812a */
if(!s->budget--) { s->failed_pc=0x0c08812au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c08812c;
P_0c08812c: /* original 69f6, guest PC 0x0c08812c */
if(!s->budget--) { s->failed_pc=0x0c08812cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c08812e;
P_0c08812e: /* original 6af6, guest PC 0x0c08812e */
if(!s->budget--) { s->failed_pc=0x0c08812eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c088130;
P_0c088130: /* original 6bf6, guest PC 0x0c088130 */
if(!s->budget--) { s->failed_pc=0x0c088130u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c088132;
P_0c088132: /* original 6cf6, guest PC 0x0c088132 */
if(!s->budget--) { s->failed_pc=0x0c088132u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c088134;
P_0c088134: /* original 6df6, guest PC 0x0c088134 */
if(!s->budget--) { s->failed_pc=0x0c088134u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c088136;
P_0c088136: /* original 000b, guest PC 0x0c088136 */
if(!s->budget--) { s->failed_pc=0x0c088136u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c088138: /* original 6ef6, guest PC 0x0c088138 */
if(!s->budget--) { s->failed_pc=0x0c088138u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c08813au,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c08813au; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
