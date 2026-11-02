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
int vf3_away_batch229_adapter_0(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c0a2e06u: goto P_0c0a2e06;
case 0x0c0a2e08u: goto P_0c0a2e08;
case 0x0c0a2e0au: goto P_0c0a2e0a;
case 0x0c0a2e0cu: goto P_0c0a2e0c;
case 0x0c0a2e0eu: goto P_0c0a2e0e;
case 0x0c0a2e10u: goto P_0c0a2e10;
case 0x0c0a2e12u: goto P_0c0a2e12;
case 0x0c0a2e14u: goto P_0c0a2e14;
case 0x0c0a2e16u: goto P_0c0a2e16;
case 0x0c0a2e18u: goto P_0c0a2e18;
case 0x0c0a2e1au: goto P_0c0a2e1a;
case 0x0c0a2e1cu: goto P_0c0a2e1c;
case 0x0c0a2e1eu: goto P_0c0a2e1e;
case 0x0c0a2e20u: goto P_0c0a2e20;
case 0x0c0a2e22u: goto P_0c0a2e22;
case 0x0c0a2e24u: goto P_0c0a2e24;
case 0x0c0a2e26u: goto P_0c0a2e26;
case 0x0c0a2e28u: goto P_0c0a2e28;
case 0x0c0a2e2au: goto P_0c0a2e2a;
case 0x0c0b6ef2u: goto P_0c0b6ef2;
case 0x0c0b6ef4u: goto P_0c0b6ef4;
case 0x0c0b6ef6u: goto P_0c0b6ef6;
case 0x0c0b6ef8u: goto P_0c0b6ef8;
case 0x0c0b6efau: goto P_0c0b6efa;
case 0x0c0b6efcu: goto P_0c0b6efc;
case 0x0c0b6efeu: goto P_0c0b6efe;
case 0x0c0b6f00u: goto P_0c0b6f00;
case 0x0c0b6f02u: goto P_0c0b6f02;
case 0x0c0b6f04u: goto P_0c0b6f04;
case 0x0c0b6f06u: goto P_0c0b6f06;
case 0x0c0b6f08u: goto P_0c0b6f08;
case 0x0c0b6f0au: goto P_0c0b6f0a;
case 0x0c0b6f0cu: goto P_0c0b6f0c;
case 0x0c0b6f0eu: goto P_0c0b6f0e;
case 0x0c0b6f10u: goto P_0c0b6f10;
case 0x0c0b6f12u: goto P_0c0b6f12;
case 0x0c0b6f14u: goto P_0c0b6f14;
case 0x0c0b6f16u: goto P_0c0b6f16;
case 0x0c0b6f18u: goto P_0c0b6f18;
case 0x0c0b6f1au: goto P_0c0b6f1a;
case 0x0c0b6f1cu: goto P_0c0b6f1c;
case 0x0c0b6f1eu: goto P_0c0b6f1e;
case 0x0c0b6f20u: goto P_0c0b6f20;
case 0x0c0b6f22u: goto P_0c0b6f22;
case 0x0c0b6f24u: goto P_0c0b6f24;
case 0x0c0b6f26u: goto P_0c0b6f26;
case 0x0c0b6f28u: goto P_0c0b6f28;
case 0x0c0b6f2au: goto P_0c0b6f2a;
case 0x0c0b6f2cu: goto P_0c0b6f2c;
case 0x0c0b6f2eu: goto P_0c0b6f2e;
case 0x0c0b6f30u: goto P_0c0b6f30;
case 0x0c0b6f32u: goto P_0c0b6f32;
case 0x0c0b6f34u: goto P_0c0b6f34;
case 0x0c0b6f36u: goto P_0c0b6f36;
case 0x0c0b6f38u: goto P_0c0b6f38;
case 0x0c0b6f3au: goto P_0c0b6f3a;
case 0x0c0b6f3cu: goto P_0c0b6f3c;
case 0x0c0b6f3eu: goto P_0c0b6f3e;
case 0x0c0b6f40u: goto P_0c0b6f40;
case 0x0c0b6f42u: goto P_0c0b6f42;
case 0x0c0b6f44u: goto P_0c0b6f44;
case 0x0c0b6f46u: goto P_0c0b6f46;
case 0x0c0b6f48u: goto P_0c0b6f48;
case 0x0c0b6f4au: goto P_0c0b6f4a;
case 0x0c0b6f4cu: goto P_0c0b6f4c;
case 0x0c0b6f4eu: goto P_0c0b6f4e;
case 0x0c0b6f50u: goto P_0c0b6f50;
case 0x0c0b6f52u: goto P_0c0b6f52;
case 0x0c0b6f54u: goto P_0c0b6f54;
case 0x0c0b6f56u: goto P_0c0b6f56;
case 0x0c0b6f58u: goto P_0c0b6f58;
case 0x0c0b6f5au: goto P_0c0b6f5a;
case 0x0c0b6f5cu: goto P_0c0b6f5c;
case 0x0c0b6f5eu: goto P_0c0b6f5e;
case 0x0c0b6f60u: goto P_0c0b6f60;
case 0x0c0b6f62u: goto P_0c0b6f62;
case 0x0c0b6f64u: goto P_0c0b6f64;
case 0x0c0b6f66u: goto P_0c0b6f66;
case 0x0c0b6f68u: goto P_0c0b6f68;
case 0x0c0b6f6au: goto P_0c0b6f6a;
case 0x0c0b6f6cu: goto P_0c0b6f6c;
case 0x0c0b6f6eu: goto P_0c0b6f6e;
case 0x0c0b6f70u: goto P_0c0b6f70;
case 0x0c0b6f72u: goto P_0c0b6f72;
case 0x0c0b6f74u: goto P_0c0b6f74;
case 0x0c0b6f76u: goto P_0c0b6f76;
case 0x0c0b6f78u: goto P_0c0b6f78;
case 0x0c0b6f7au: goto P_0c0b6f7a;
case 0x0c0b6f7cu: goto P_0c0b6f7c;
case 0x0c0b6f7eu: goto P_0c0b6f7e;
case 0x0c0b6f80u: goto P_0c0b6f80;
case 0x0c0b6f82u: goto P_0c0b6f82;
case 0x0c0b6f84u: goto P_0c0b6f84;
case 0x0c0b6f86u: goto P_0c0b6f86;
case 0x0c0b6f88u: goto P_0c0b6f88;
case 0x0c0b6f8au: goto P_0c0b6f8a;
case 0x0c0b6f8cu: goto P_0c0b6f8c;
case 0x0c0b6f8eu: goto P_0c0b6f8e;
case 0x0c0b6f90u: goto P_0c0b6f90;
case 0x0c0b6f92u: goto P_0c0b6f92;
case 0x0c0b6f94u: goto P_0c0b6f94;
case 0x0c0b6f96u: goto P_0c0b6f96;
case 0x0c0b6f98u: goto P_0c0b6f98;
case 0x0c0b6f9au: goto P_0c0b6f9a;
case 0x0c0b6f9cu: goto P_0c0b6f9c;
case 0x0c0b6f9eu: goto P_0c0b6f9e;
case 0x0c0b6fa0u: goto P_0c0b6fa0;
case 0x0c0b6fa2u: goto P_0c0b6fa2;
case 0x0c0b6fa4u: goto P_0c0b6fa4;
case 0x0c0b6fa6u: goto P_0c0b6fa6;
case 0x0c0b6fa8u: goto P_0c0b6fa8;
case 0x0c0b6faau: goto P_0c0b6faa;
case 0x0c0b6facu: goto P_0c0b6fac;
case 0x0c0b6faeu: goto P_0c0b6fae;
case 0x0c0b6fb0u: goto P_0c0b6fb0;
case 0x0c0b6fb2u: goto P_0c0b6fb2;
case 0x0c0b6fb4u: goto P_0c0b6fb4;
case 0x0c0b6fb6u: goto P_0c0b6fb6;
case 0x0c0b6fb8u: goto P_0c0b6fb8;
case 0x0c0b6fbau: goto P_0c0b6fba;
case 0x0c0b6fbcu: goto P_0c0b6fbc;
case 0x0c0b6fbeu: goto P_0c0b6fbe;
case 0x0c0b6fc0u: goto P_0c0b6fc0;
case 0x0c0b6fc2u: goto P_0c0b6fc2;
case 0x0c0b6fc4u: goto P_0c0b6fc4;
case 0x0c0b6fc6u: goto P_0c0b6fc6;
case 0x0c0b6fc8u: goto P_0c0b6fc8;
case 0x0c0b6fcau: goto P_0c0b6fca;
case 0x0c0b6fccu: goto P_0c0b6fcc;
case 0x0c0b6fceu: goto P_0c0b6fce;
case 0x0c0b6fd0u: goto P_0c0b6fd0;
case 0x0c0b6fd2u: goto P_0c0b6fd2;
case 0x0c0b6fd4u: goto P_0c0b6fd4;
case 0x0c0b6fd6u: goto P_0c0b6fd6;
case 0x0c0b6fd8u: goto P_0c0b6fd8;
case 0x0c0b6fdau: goto P_0c0b6fda;
case 0x0c0b6fdcu: goto P_0c0b6fdc;
case 0x0c0b6fdeu: goto P_0c0b6fde;
case 0x0c0b6fe0u: goto P_0c0b6fe0;
case 0x0c0b6fe2u: goto P_0c0b6fe2;
case 0x0c0b6fe4u: goto P_0c0b6fe4;
case 0x0c0b6fe6u: goto P_0c0b6fe6;
case 0x0c0b6fe8u: goto P_0c0b6fe8;
case 0x0c0b6feau: goto P_0c0b6fea;
case 0x0c0b6fecu: goto P_0c0b6fec;
case 0x0c0b6feeu: goto P_0c0b6fee;
case 0x0c0b6ff0u: goto P_0c0b6ff0;
case 0x0c0b6ff2u: goto P_0c0b6ff2;
case 0x0c0b6ff4u: goto P_0c0b6ff4;
case 0x0c0b6ff6u: goto P_0c0b6ff6;
case 0x0c0b6ff8u: goto P_0c0b6ff8;
case 0x0c0b6ffau: goto P_0c0b6ffa;
case 0x0c0b6ffcu: goto P_0c0b6ffc;
case 0x0c0b6ffeu: goto P_0c0b6ffe;
case 0x0c0b7000u: goto P_0c0b7000;
case 0x0c0b7002u: goto P_0c0b7002;
case 0x0c0b7004u: goto P_0c0b7004;
case 0x0c0b7006u: goto P_0c0b7006;
case 0x0c0b7008u: goto P_0c0b7008;
case 0x0c0b700au: goto P_0c0b700a;
case 0x0c0b700cu: goto P_0c0b700c;
case 0x0c0b700eu: goto P_0c0b700e;
case 0x0c0b7010u: goto P_0c0b7010;
case 0x0c0b7012u: goto P_0c0b7012;
case 0x0c0b7014u: goto P_0c0b7014;
case 0x0c0b7016u: goto P_0c0b7016;
case 0x0c0b7018u: goto P_0c0b7018;
case 0x0c0b701au: goto P_0c0b701a;
case 0x0c0b701cu: goto P_0c0b701c;
case 0x0c0b701eu: goto P_0c0b701e;
case 0x0c0b7020u: goto P_0c0b7020;
case 0x0c0b7022u: goto P_0c0b7022;
case 0x0c0b7024u: goto P_0c0b7024;
case 0x0c0b7026u: goto P_0c0b7026;
case 0x0c0b7028u: goto P_0c0b7028;
case 0x0c0b702au: goto P_0c0b702a;
case 0x0c0b702cu: goto P_0c0b702c;
case 0x0c0b702eu: goto P_0c0b702e;
case 0x0c0b7030u: goto P_0c0b7030;
case 0x0c0b7032u: goto P_0c0b7032;
case 0x0c0b7034u: goto P_0c0b7034;
case 0x0c0b7036u: goto P_0c0b7036;
case 0x0c0b7038u: goto P_0c0b7038;
case 0x0c0b703au: goto P_0c0b703a;
case 0x0c0b703cu: goto P_0c0b703c;
case 0x0c0b703eu: goto P_0c0b703e;
case 0x0c0b7040u: goto P_0c0b7040;
case 0x0c0b7042u: goto P_0c0b7042;
case 0x0c0b7044u: goto P_0c0b7044;
case 0x0c0b7046u: goto P_0c0b7046;
case 0x0c0b7048u: goto P_0c0b7048;
case 0x0c0b704au: goto P_0c0b704a;
case 0x0c0b704cu: goto P_0c0b704c;
case 0x0c0b704eu: goto P_0c0b704e;
case 0x0c0b7050u: goto P_0c0b7050;
case 0x0c0b7052u: goto P_0c0b7052;
case 0x0c0b7054u: goto P_0c0b7054;
case 0x0c0b70c4u: goto P_0c0b70c4;
case 0x0c0b70c6u: goto P_0c0b70c6;
case 0x0c0b70c8u: goto P_0c0b70c8;
case 0x0c0b70cau: goto P_0c0b70ca;
case 0x0c0b70ccu: goto P_0c0b70cc;
case 0x0c0b70ceu: goto P_0c0b70ce;
case 0x0c0b70d0u: goto P_0c0b70d0;
case 0x0c0b70d2u: goto P_0c0b70d2;
case 0x0c0b70d4u: goto P_0c0b70d4;
case 0x0c0b70d6u: goto P_0c0b70d6;
case 0x0c0b70d8u: goto P_0c0b70d8;
case 0x0c0b70dau: goto P_0c0b70da;
case 0x0c0b70dcu: goto P_0c0b70dc;
case 0x0c0b70deu: goto P_0c0b70de;
case 0x0c0b70e0u: goto P_0c0b70e0;
case 0x0c0b70e2u: goto P_0c0b70e2;
case 0x0c0b70e4u: goto P_0c0b70e4;
case 0x0c0b70e6u: goto P_0c0b70e6;
case 0x0c0b70e8u: goto P_0c0b70e8;
case 0x0c0b70eau: goto P_0c0b70ea;
case 0x0c0b70ecu: goto P_0c0b70ec;
case 0x0c0b70eeu: goto P_0c0b70ee;
case 0x0c0b70f0u: goto P_0c0b70f0;
case 0x0c0b70f2u: goto P_0c0b70f2;
case 0x0c0b70f4u: goto P_0c0b70f4;
case 0x0c0b70f6u: goto P_0c0b70f6;
case 0x0c0b70f8u: goto P_0c0b70f8;
case 0x0c0b70fau: goto P_0c0b70fa;
case 0x0c0b70fcu: goto P_0c0b70fc;
case 0x0c0b70feu: goto P_0c0b70fe;
case 0x0c0b7100u: goto P_0c0b7100;
case 0x0c0b7102u: goto P_0c0b7102;
case 0x0c0b7104u: goto P_0c0b7104;
case 0x0c0b7106u: goto P_0c0b7106;
case 0x0c0b7108u: goto P_0c0b7108;
case 0x0c0b710au: goto P_0c0b710a;
case 0x0c0b710cu: goto P_0c0b710c;
case 0x0c0b710eu: goto P_0c0b710e;
case 0x0c0b7110u: goto P_0c0b7110;
case 0x0c0b7112u: goto P_0c0b7112;
case 0x0c0b7114u: goto P_0c0b7114;
case 0x0c0b7116u: goto P_0c0b7116;
case 0x0c0b7118u: goto P_0c0b7118;
case 0x0c0b711au: goto P_0c0b711a;
case 0x0c0b711cu: goto P_0c0b711c;
case 0x0c0b711eu: goto P_0c0b711e;
case 0x0c0b7120u: goto P_0c0b7120;
case 0x0c0b7122u: goto P_0c0b7122;
case 0x0c0b7124u: goto P_0c0b7124;
case 0x0c0b7126u: goto P_0c0b7126;
case 0x0c0b7128u: goto P_0c0b7128;
case 0x0c0b712au: goto P_0c0b712a;
case 0x0c0b712cu: goto P_0c0b712c;
case 0x0c0b712eu: goto P_0c0b712e;
case 0x0c0b7130u: goto P_0c0b7130;
case 0x0c0b7132u: goto P_0c0b7132;
case 0x0c0b7134u: goto P_0c0b7134;
case 0x0c0b7136u: goto P_0c0b7136;
case 0x0c0b7138u: goto P_0c0b7138;
case 0x0c0b713au: goto P_0c0b713a;
case 0x0c0b713cu: goto P_0c0b713c;
case 0x0c0b713eu: goto P_0c0b713e;
case 0x0c0b7140u: goto P_0c0b7140;
case 0x0c0b7142u: goto P_0c0b7142;
case 0x0c0b7144u: goto P_0c0b7144;
case 0x0c0b7146u: goto P_0c0b7146;
case 0x0c0b7148u: goto P_0c0b7148;
case 0x0c0b714au: goto P_0c0b714a;
case 0x0c0b714cu: goto P_0c0b714c;
case 0x0c0b714eu: goto P_0c0b714e;
case 0x0c0b7150u: goto P_0c0b7150;
case 0x0c0b7152u: goto P_0c0b7152;
case 0x0c0b7154u: goto P_0c0b7154;
case 0x0c0b7156u: goto P_0c0b7156;
case 0x0c0b7158u: goto P_0c0b7158;
case 0x0c0b715au: goto P_0c0b715a;
case 0x0c0b715cu: goto P_0c0b715c;
case 0x0c0b715eu: goto P_0c0b715e;
case 0x0c0b7160u: goto P_0c0b7160;
case 0x0c0b7162u: goto P_0c0b7162;
case 0x0c0b7164u: goto P_0c0b7164;
case 0x0c0b7166u: goto P_0c0b7166;
case 0x0c0b7168u: goto P_0c0b7168;
case 0x0c0b716au: goto P_0c0b716a;
case 0x0c0b716cu: goto P_0c0b716c;
case 0x0c0b716eu: goto P_0c0b716e;
case 0x0c0b7170u: goto P_0c0b7170;
case 0x0c0b7172u: goto P_0c0b7172;
case 0x0c0b7174u: goto P_0c0b7174;
case 0x0c0b7176u: goto P_0c0b7176;
case 0x0c0b7178u: goto P_0c0b7178;
case 0x0c0b717au: goto P_0c0b717a;
case 0x0c0b717cu: goto P_0c0b717c;
case 0x0c0b717eu: goto P_0c0b717e;
case 0x0c0b7180u: goto P_0c0b7180;
case 0x0c0b7182u: goto P_0c0b7182;
case 0x0c0b7184u: goto P_0c0b7184;
case 0x0c0b7186u: goto P_0c0b7186;
case 0x0c0b7188u: goto P_0c0b7188;
case 0x0c0b718au: goto P_0c0b718a;
case 0x0c0b718cu: goto P_0c0b718c;
case 0x0c0b718eu: goto P_0c0b718e;
case 0x0c0b7190u: goto P_0c0b7190;
case 0x0c0b7192u: goto P_0c0b7192;
case 0x0c0b7194u: goto P_0c0b7194;
case 0x0c0b7196u: goto P_0c0b7196;
case 0x0c0b7198u: goto P_0c0b7198;
case 0x0c0b719au: goto P_0c0b719a;
case 0x0c0b719cu: goto P_0c0b719c;
case 0x0c0b719eu: goto P_0c0b719e;
case 0x0c0b71a0u: goto P_0c0b71a0;
case 0x0c0b71a2u: goto P_0c0b71a2;
case 0x0c0b71a4u: goto P_0c0b71a4;
case 0x0c0b71a6u: goto P_0c0b71a6;
case 0x0c0b71a8u: goto P_0c0b71a8;
case 0x0c0b71aau: goto P_0c0b71aa;
case 0x0c0b71acu: goto P_0c0b71ac;
case 0x0c0b71aeu: goto P_0c0b71ae;
case 0x0c0b71b0u: goto P_0c0b71b0;
case 0x0c0b71b2u: goto P_0c0b71b2;
case 0x0c0b71b4u: goto P_0c0b71b4;
case 0x0c0b71b6u: goto P_0c0b71b6;
case 0x0c0b71b8u: goto P_0c0b71b8;
case 0x0c0b71bau: goto P_0c0b71ba;
case 0x0c0b71bcu: goto P_0c0b71bc;
case 0x0c0b71beu: goto P_0c0b71be;
case 0x0c0b71c0u: goto P_0c0b71c0;
case 0x0c0b71c2u: goto P_0c0b71c2;
case 0x0c0b71c4u: goto P_0c0b71c4;
case 0x0c0b71c6u: goto P_0c0b71c6;
case 0x0c0b71c8u: goto P_0c0b71c8;
case 0x0c0b71cau: goto P_0c0b71ca;
case 0x0c0b71ccu: goto P_0c0b71cc;
case 0x0c0b71ceu: goto P_0c0b71ce;
case 0x0c0b71d0u: goto P_0c0b71d0;
case 0x0c0b71d2u: goto P_0c0b71d2;
case 0x0c0b71d4u: goto P_0c0b71d4;
case 0x0c0b71d6u: goto P_0c0b71d6;
case 0x0c0b71d8u: goto P_0c0b71d8;
case 0x0c0b71dau: goto P_0c0b71da;
case 0x0c0b71dcu: goto P_0c0b71dc;
case 0x0c0b71deu: goto P_0c0b71de;
case 0x0c0b71e0u: goto P_0c0b71e0;
case 0x0c0b71e2u: goto P_0c0b71e2;
case 0x0c0b71e4u: goto P_0c0b71e4;
case 0x0c0b71e6u: goto P_0c0b71e6;
case 0x0c0b71e8u: goto P_0c0b71e8;
case 0x0c0b71eau: goto P_0c0b71ea;
case 0x0c0b71ecu: goto P_0c0b71ec;
case 0x0c0b71eeu: goto P_0c0b71ee;
case 0x0c0b71f0u: goto P_0c0b71f0;
case 0x0c0b71f2u: goto P_0c0b71f2;
case 0x0c0b71f4u: goto P_0c0b71f4;
case 0x0c0b71f6u: goto P_0c0b71f6;
case 0x0c0b71f8u: goto P_0c0b71f8;
case 0x0c0b71fau: goto P_0c0b71fa;
case 0x0c0b71fcu: goto P_0c0b71fc;
case 0x0c0b71feu: goto P_0c0b71fe;
case 0x0c0b7200u: goto P_0c0b7200;
case 0x0c0b7202u: goto P_0c0b7202;
case 0x0c0b7204u: goto P_0c0b7204;
case 0x0c0b7206u: goto P_0c0b7206;
case 0x0c0b7208u: goto P_0c0b7208;
case 0x0c0b720au: goto P_0c0b720a;
case 0x0c0b720cu: goto P_0c0b720c;
case 0x0c0b720eu: goto P_0c0b720e;
case 0x0c0b7210u: goto P_0c0b7210;
case 0x0c0b7212u: goto P_0c0b7212;
case 0x0c0b7214u: goto P_0c0b7214;
case 0x0c0b7216u: goto P_0c0b7216;
case 0x0c0b7218u: goto P_0c0b7218;
case 0x0c0b721au: goto P_0c0b721a;
case 0x0c0b721cu: goto P_0c0b721c;
case 0x0c0b7296u: goto P_0c0b7296;
case 0x0c0b7298u: goto P_0c0b7298;
case 0x0c0b729au: goto P_0c0b729a;
case 0x0c0b729cu: goto P_0c0b729c;
case 0x0c0b729eu: goto P_0c0b729e;
case 0x0c0b72a0u: goto P_0c0b72a0;
case 0x0c0b72a2u: goto P_0c0b72a2;
case 0x0c0b72a4u: goto P_0c0b72a4;
case 0x0c0b72a6u: goto P_0c0b72a6;
case 0x0c0b72a8u: goto P_0c0b72a8;
case 0x0c0b72aau: goto P_0c0b72aa;
case 0x0c0b72acu: goto P_0c0b72ac;
case 0x0c0b72aeu: goto P_0c0b72ae;
case 0x0c0b72b0u: goto P_0c0b72b0;
case 0x0c0b72b2u: goto P_0c0b72b2;
case 0x0c0b72b4u: goto P_0c0b72b4;
case 0x0c0b72b6u: goto P_0c0b72b6;
case 0x0c0b72b8u: goto P_0c0b72b8;
case 0x0c0b72bau: goto P_0c0b72ba;
case 0x0c0b72bcu: goto P_0c0b72bc;
case 0x0c0b72beu: goto P_0c0b72be;
case 0x0c0b72c0u: goto P_0c0b72c0;
case 0x0c0b72c2u: goto P_0c0b72c2;
case 0x0c0b72c4u: goto P_0c0b72c4;
case 0x0c0b72c6u: goto P_0c0b72c6;
case 0x0c0b72c8u: goto P_0c0b72c8;
case 0x0c0b72cau: goto P_0c0b72ca;
case 0x0c0b72ccu: goto P_0c0b72cc;
case 0x0c0b72ceu: goto P_0c0b72ce;
case 0x0c0b72d0u: goto P_0c0b72d0;
case 0x0c0b72d2u: goto P_0c0b72d2;
case 0x0c0b72d4u: goto P_0c0b72d4;
case 0x0c0b72d6u: goto P_0c0b72d6;
case 0x0c0b72d8u: goto P_0c0b72d8;
case 0x0c0b72dau: goto P_0c0b72da;
case 0x0c0b72dcu: goto P_0c0b72dc;
case 0x0c0b72deu: goto P_0c0b72de;
case 0x0c0b72e0u: goto P_0c0b72e0;
case 0x0c0b72e2u: goto P_0c0b72e2;
case 0x0c0b72e4u: goto P_0c0b72e4;
case 0x0c0b72e6u: goto P_0c0b72e6;
case 0x0c0b72e8u: goto P_0c0b72e8;
case 0x0c0b72eau: goto P_0c0b72ea;
case 0x0c0b72ecu: goto P_0c0b72ec;
default: return vf3_matrix_family(target,s,ram);
}
P_0c0a2e06: /* original d359, guest PC 0x0c0a2e06 */
if(!s->budget--) { s->failed_pc=0x0c0a2e06u; return 0; }
r[3]=read(ram,0x0c0a2f6cu,4);
goto P_0c0a2e08;
P_0c0a2e08: /* original 6643, guest PC 0x0c0a2e08 */
if(!s->budget--) { s->failed_pc=0x0c0a2e08u; return 0; }
r[6]=r[4];
goto P_0c0a2e0a;
P_0c0a2e0a: /* original 4608, guest PC 0x0c0a2e0a */
if(!s->budget--) { s->failed_pc=0x0c0a2e0au; return 0; }
r[6]<<=2;
goto P_0c0a2e0c;
P_0c0a2e0c: /* original 363c, guest PC 0x0c0a2e0c */
if(!s->budget--) { s->failed_pc=0x0c0a2e0cu; return 0; }
r[6]+=r[3];
goto P_0c0a2e0e;
P_0c0a2e0e: /* original 6262, guest PC 0x0c0a2e0e */
if(!s->budget--) { s->failed_pc=0x0c0a2e0eu; return 0; }
tmp=read(ram,r[6],4);
r[2]=tmp;
goto P_0c0a2e10;
P_0c0a2e10: /* original 2228, guest PC 0x0c0a2e10 */
if(!s->budget--) { s->failed_pc=0x0c0a2e10u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c0a2e12;
P_0c0a2e12: /* original 8b09, guest PC 0x0c0a2e12 */
if(!s->budget--) { s->failed_pc=0x0c0a2e12u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a2e28; }
goto P_0c0a2e14;
P_0c0a2e14: /* original 6062, guest PC 0x0c0a2e14 */
if(!s->budget--) { s->failed_pc=0x0c0a2e14u; return 0; }
tmp=read(ram,r[6],4);
r[0]=tmp;
goto P_0c0a2e16;
P_0c0a2e16: /* original 88ff, guest PC 0x0c0a2e16 */
if(!s->budget--) { s->failed_pc=0x0c0a2e16u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c0a2e18;
P_0c0a2e18: /* original 8906, guest PC 0x0c0a2e18 */
if(!s->budget--) { s->failed_pc=0x0c0a2e18u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a2e28; }
goto P_0c0a2e1a;
P_0c0a2e1a: /* original 5051, guest PC 0x0c0a2e1a */
if(!s->budget--) { s->failed_pc=0x0c0a2e1au; return 0; }
r[0]=read(ram,r[5]+4,4);
goto P_0c0a2e1c;
P_0c0a2e1c: /* original c801, guest PC 0x0c0a2e1c */
if(!s->budget--) { s->failed_pc=0x0c0a2e1cu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&1u)==0)!=0);
goto P_0c0a2e1e;
P_0c0a2e1e: /* original 8901, guest PC 0x0c0a2e1e */
if(!s->budget--) { s->failed_pc=0x0c0a2e1eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a2e24; }
goto P_0c0a2e20;
P_0c0a2e20: /* original a002, guest PC 0x0c0a2e20 */
if(!s->budget--) { s->failed_pc=0x0c0a2e20u; return 0; }
write(ram,r[6],r[5],4);
goto P_0c0a2e28;
P_0c0a2e22: /* original 2652, guest PC 0x0c0a2e22 */
if(!s->budget--) { s->failed_pc=0x0c0a2e22u; return 0; }
write(ram,r[6],r[5],4);
goto P_0c0a2e24;
P_0c0a2e24: /* original 6152, guest PC 0x0c0a2e24 */
if(!s->budget--) { s->failed_pc=0x0c0a2e24u; return 0; }
tmp=read(ram,r[5],4);
r[1]=tmp;
goto P_0c0a2e26;
P_0c0a2e26: /* original 2612, guest PC 0x0c0a2e26 */
if(!s->budget--) { s->failed_pc=0x0c0a2e26u; return 0; }
write(ram,r[6],r[1],4);
goto P_0c0a2e28;
P_0c0a2e28: /* original 000b, guest PC 0x0c0a2e28 */
if(!s->budget--) { s->failed_pc=0x0c0a2e28u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c0a2e2a: /* original 0009, guest PC 0x0c0a2e2a */
if(!s->budget--) { s->failed_pc=0x0c0a2e2au; return 0; }
if(!vf3_matrix_family(0x0c0a2e2cu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0a2e2cu; return 0; } return 1;
P_0c0b6ef2: /* original 2fe6, guest PC 0x0c0b6ef2 */
if(!s->budget--) { s->failed_pc=0x0c0b6ef2u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0b6ef4;
P_0c0b6ef4: /* original 2fd6, guest PC 0x0c0b6ef4 */
if(!s->budget--) { s->failed_pc=0x0c0b6ef4u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0b6ef6;
P_0c0b6ef6: /* original 2fc6, guest PC 0x0c0b6ef6 */
if(!s->budget--) { s->failed_pc=0x0c0b6ef6u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0b6ef8;
P_0c0b6ef8: /* original 2fb6, guest PC 0x0c0b6ef8 */
if(!s->budget--) { s->failed_pc=0x0c0b6ef8u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0b6efa;
P_0c0b6efa: /* original 2fa6, guest PC 0x0c0b6efa */
if(!s->budget--) { s->failed_pc=0x0c0b6efau; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0b6efc;
P_0c0b6efc: /* original 2f96, guest PC 0x0c0b6efc */
if(!s->budget--) { s->failed_pc=0x0c0b6efcu; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0b6efe;
P_0c0b6efe: /* original 4f22, guest PC 0x0c0b6efe */
if(!s->budget--) { s->failed_pc=0x0c0b6efeu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0b6f00;
P_0c0b6f00: /* original 5d44, guest PC 0x0c0b6f00 */
if(!s->budget--) { s->failed_pc=0x0c0b6f00u; return 0; }
r[13]=read(ram,r[4]+16,4);
goto P_0c0b6f02;
P_0c0b6f02: /* original 94a8, guest PC 0x0c0b6f02 */
if(!s->budget--) { s->failed_pc=0x0c0b6f02u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b7056u,2);
goto P_0c0b6f04;
P_0c0b6f04: /* original de6e, guest PC 0x0c0b6f04 */
if(!s->budget--) { s->failed_pc=0x0c0b6f04u; return 0; }
r[14]=read(ram,0x0c0b70c0u,4);
goto P_0c0b6f06;
P_0c0b6f06: /* original 7ff8, guest PC 0x0c0b6f06 */
if(!s->budget--) { s->failed_pc=0x0c0b6f06u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c0b6f08;
P_0c0b6f08: /* original 4e0b, guest PC 0x0c0b6f08 */
if(!s->budget--) { s->failed_pc=0x0c0b6f08u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b6f0cu;
tmp=read(ram,r[13],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b6f0cu) { target=s->pc; goto dispatch; }
goto P_0c0b6f0c;
P_0c0b6f0a: /* original 65d2, guest PC 0x0c0b6f0a */
if(!s->budget--) { s->failed_pc=0x0c0b6f0au; return 0; }
tmp=read(ram,r[13],4);
r[5]=tmp;
goto P_0c0b6f0c;
P_0c0b6f0c: /* original 94a4, guest PC 0x0c0b6f0c */
if(!s->budget--) { s->failed_pc=0x0c0b6f0cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b7058u,2);
goto P_0c0b6f0e;
P_0c0b6f0e: /* original 4e0b, guest PC 0x0c0b6f0e */
if(!s->budget--) { s->failed_pc=0x0c0b6f0eu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b6f12u;
r[5]=read(ram,r[13]+4,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b6f12u) { target=s->pc; goto dispatch; }
goto P_0c0b6f12;
P_0c0b6f10: /* original 55d1, guest PC 0x0c0b6f10 */
if(!s->budget--) { s->failed_pc=0x0c0b6f10u; return 0; }
r[5]=read(ram,r[13]+4,4);
goto P_0c0b6f12;
P_0c0b6f12: /* original 94a2, guest PC 0x0c0b6f12 */
if(!s->budget--) { s->failed_pc=0x0c0b6f12u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b705au,2);
goto P_0c0b6f14;
P_0c0b6f14: /* original 4e0b, guest PC 0x0c0b6f14 */
if(!s->budget--) { s->failed_pc=0x0c0b6f14u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b6f18u;
r[5]=read(ram,r[13]+8,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b6f18u) { target=s->pc; goto dispatch; }
goto P_0c0b6f18;
P_0c0b6f16: /* original 55d2, guest PC 0x0c0b6f16 */
if(!s->budget--) { s->failed_pc=0x0c0b6f16u; return 0; }
r[5]=read(ram,r[13]+8,4);
goto P_0c0b6f18;
P_0c0b6f18: /* original 94a0, guest PC 0x0c0b6f18 */
if(!s->budget--) { s->failed_pc=0x0c0b6f18u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b705cu,2);
goto P_0c0b6f1a;
P_0c0b6f1a: /* original 4e0b, guest PC 0x0c0b6f1a */
if(!s->budget--) { s->failed_pc=0x0c0b6f1au; return 0; }
target=r[14];
r[16]=code_base|0x0c0b6f1eu;
r[5]=read(ram,r[13]+12,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b6f1eu) { target=s->pc; goto dispatch; }
goto P_0c0b6f1e;
P_0c0b6f1c: /* original 55d3, guest PC 0x0c0b6f1c */
if(!s->budget--) { s->failed_pc=0x0c0b6f1cu; return 0; }
r[5]=read(ram,r[13]+12,4);
goto P_0c0b6f1e;
P_0c0b6f1e: /* original 949e, guest PC 0x0c0b6f1e */
if(!s->budget--) { s->failed_pc=0x0c0b6f1eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b705eu,2);
goto P_0c0b6f20;
P_0c0b6f20: /* original 4e0b, guest PC 0x0c0b6f20 */
if(!s->budget--) { s->failed_pc=0x0c0b6f20u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b6f24u;
r[5]=read(ram,r[13]+16,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b6f24u) { target=s->pc; goto dispatch; }
goto P_0c0b6f24;
P_0c0b6f22: /* original 55d4, guest PC 0x0c0b6f22 */
if(!s->budget--) { s->failed_pc=0x0c0b6f22u; return 0; }
r[5]=read(ram,r[13]+16,4);
goto P_0c0b6f24;
P_0c0b6f24: /* original 949c, guest PC 0x0c0b6f24 */
if(!s->budget--) { s->failed_pc=0x0c0b6f24u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b7060u,2);
goto P_0c0b6f26;
P_0c0b6f26: /* original 4e0b, guest PC 0x0c0b6f26 */
if(!s->budget--) { s->failed_pc=0x0c0b6f26u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b6f2au;
r[5]=read(ram,r[13]+20,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b6f2au) { target=s->pc; goto dispatch; }
goto P_0c0b6f2a;
P_0c0b6f28: /* original 55d5, guest PC 0x0c0b6f28 */
if(!s->budget--) { s->failed_pc=0x0c0b6f28u; return 0; }
r[5]=read(ram,r[13]+20,4);
goto P_0c0b6f2a;
P_0c0b6f2a: /* original 949a, guest PC 0x0c0b6f2a */
if(!s->budget--) { s->failed_pc=0x0c0b6f2au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b7062u,2);
goto P_0c0b6f2c;
P_0c0b6f2c: /* original 4e0b, guest PC 0x0c0b6f2c */
if(!s->budget--) { s->failed_pc=0x0c0b6f2cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b6f30u;
r[5]=read(ram,r[13]+24,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b6f30u) { target=s->pc; goto dispatch; }
goto P_0c0b6f30;
P_0c0b6f2e: /* original 55d6, guest PC 0x0c0b6f2e */
if(!s->budget--) { s->failed_pc=0x0c0b6f2eu; return 0; }
r[5]=read(ram,r[13]+24,4);
goto P_0c0b6f30;
P_0c0b6f30: /* original 9498, guest PC 0x0c0b6f30 */
if(!s->budget--) { s->failed_pc=0x0c0b6f30u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b7064u,2);
goto P_0c0b6f32;
P_0c0b6f32: /* original 4e0b, guest PC 0x0c0b6f32 */
if(!s->budget--) { s->failed_pc=0x0c0b6f32u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b6f36u;
r[5]=read(ram,r[13]+28,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b6f36u) { target=s->pc; goto dispatch; }
goto P_0c0b6f36;
P_0c0b6f34: /* original 55d7, guest PC 0x0c0b6f34 */
if(!s->budget--) { s->failed_pc=0x0c0b6f34u; return 0; }
r[5]=read(ram,r[13]+28,4);
goto P_0c0b6f36;
P_0c0b6f36: /* original 9496, guest PC 0x0c0b6f36 */
if(!s->budget--) { s->failed_pc=0x0c0b6f36u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b7066u,2);
goto P_0c0b6f38;
P_0c0b6f38: /* original 4e0b, guest PC 0x0c0b6f38 */
if(!s->budget--) { s->failed_pc=0x0c0b6f38u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b6f3cu;
r[5]=read(ram,r[13]+32,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b6f3cu) { target=s->pc; goto dispatch; }
goto P_0c0b6f3c;
P_0c0b6f3a: /* original 55d8, guest PC 0x0c0b6f3a */
if(!s->budget--) { s->failed_pc=0x0c0b6f3au; return 0; }
r[5]=read(ram,r[13]+32,4);
goto P_0c0b6f3c;
P_0c0b6f3c: /* original 9494, guest PC 0x0c0b6f3c */
if(!s->budget--) { s->failed_pc=0x0c0b6f3cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b7068u,2);
goto P_0c0b6f3e;
P_0c0b6f3e: /* original 4e0b, guest PC 0x0c0b6f3e */
if(!s->budget--) { s->failed_pc=0x0c0b6f3eu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b6f42u;
r[5]=read(ram,r[13]+36,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b6f42u) { target=s->pc; goto dispatch; }
goto P_0c0b6f42;
P_0c0b6f40: /* original 55d9, guest PC 0x0c0b6f40 */
if(!s->budget--) { s->failed_pc=0x0c0b6f40u; return 0; }
r[5]=read(ram,r[13]+36,4);
goto P_0c0b6f42;
P_0c0b6f42: /* original 9492, guest PC 0x0c0b6f42 */
if(!s->budget--) { s->failed_pc=0x0c0b6f42u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b706au,2);
goto P_0c0b6f44;
P_0c0b6f44: /* original 4e0b, guest PC 0x0c0b6f44 */
if(!s->budget--) { s->failed_pc=0x0c0b6f44u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b6f48u;
r[5]=read(ram,r[13]+40,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b6f48u) { target=s->pc; goto dispatch; }
goto P_0c0b6f48;
P_0c0b6f46: /* original 55da, guest PC 0x0c0b6f46 */
if(!s->budget--) { s->failed_pc=0x0c0b6f46u; return 0; }
r[5]=read(ram,r[13]+40,4);
goto P_0c0b6f48;
P_0c0b6f48: /* original 9490, guest PC 0x0c0b6f48 */
if(!s->budget--) { s->failed_pc=0x0c0b6f48u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b706cu,2);
goto P_0c0b6f4a;
P_0c0b6f4a: /* original 4e0b, guest PC 0x0c0b6f4a */
if(!s->budget--) { s->failed_pc=0x0c0b6f4au; return 0; }
target=r[14];
r[16]=code_base|0x0c0b6f4eu;
r[5]=read(ram,r[13]+44,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b6f4eu) { target=s->pc; goto dispatch; }
goto P_0c0b6f4e;
P_0c0b6f4c: /* original 55db, guest PC 0x0c0b6f4c */
if(!s->budget--) { s->failed_pc=0x0c0b6f4cu; return 0; }
r[5]=read(ram,r[13]+44,4);
goto P_0c0b6f4e;
P_0c0b6f4e: /* original 948e, guest PC 0x0c0b6f4e */
if(!s->budget--) { s->failed_pc=0x0c0b6f4eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b706eu,2);
goto P_0c0b6f50;
P_0c0b6f50: /* original 4e0b, guest PC 0x0c0b6f50 */
if(!s->budget--) { s->failed_pc=0x0c0b6f50u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b6f54u;
r[5]=read(ram,r[13]+48,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b6f54u) { target=s->pc; goto dispatch; }
goto P_0c0b6f54;
P_0c0b6f52: /* original 55dc, guest PC 0x0c0b6f52 */
if(!s->budget--) { s->failed_pc=0x0c0b6f52u; return 0; }
r[5]=read(ram,r[13]+48,4);
goto P_0c0b6f54;
P_0c0b6f54: /* original 948c, guest PC 0x0c0b6f54 */
if(!s->budget--) { s->failed_pc=0x0c0b6f54u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b7070u,2);
goto P_0c0b6f56;
P_0c0b6f56: /* original 4e0b, guest PC 0x0c0b6f56 */
if(!s->budget--) { s->failed_pc=0x0c0b6f56u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b6f5au;
r[5]=read(ram,r[13]+52,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b6f5au) { target=s->pc; goto dispatch; }
goto P_0c0b6f5a;
P_0c0b6f58: /* original 55dd, guest PC 0x0c0b6f58 */
if(!s->budget--) { s->failed_pc=0x0c0b6f58u; return 0; }
r[5]=read(ram,r[13]+52,4);
goto P_0c0b6f5a;
P_0c0b6f5a: /* original 948a, guest PC 0x0c0b6f5a */
if(!s->budget--) { s->failed_pc=0x0c0b6f5au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b7072u,2);
goto P_0c0b6f5c;
P_0c0b6f5c: /* original 4e0b, guest PC 0x0c0b6f5c */
if(!s->budget--) { s->failed_pc=0x0c0b6f5cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b6f60u;
r[5]=read(ram,r[13]+56,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b6f60u) { target=s->pc; goto dispatch; }
goto P_0c0b6f60;
P_0c0b6f5e: /* original 55de, guest PC 0x0c0b6f5e */
if(!s->budget--) { s->failed_pc=0x0c0b6f5eu; return 0; }
r[5]=read(ram,r[13]+56,4);
goto P_0c0b6f60;
P_0c0b6f60: /* original 9488, guest PC 0x0c0b6f60 */
if(!s->budget--) { s->failed_pc=0x0c0b6f60u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b7074u,2);
goto P_0c0b6f62;
P_0c0b6f62: /* original 4e0b, guest PC 0x0c0b6f62 */
if(!s->budget--) { s->failed_pc=0x0c0b6f62u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b6f66u;
r[5]=read(ram,r[13]+60,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b6f66u) { target=s->pc; goto dispatch; }
goto P_0c0b6f66;
P_0c0b6f64: /* original 55df, guest PC 0x0c0b6f64 */
if(!s->budget--) { s->failed_pc=0x0c0b6f64u; return 0; }
r[5]=read(ram,r[13]+60,4);
goto P_0c0b6f66;
P_0c0b6f66: /* original 9486, guest PC 0x0c0b6f66 */
if(!s->budget--) { s->failed_pc=0x0c0b6f66u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b7076u,2);
goto P_0c0b6f68;
P_0c0b6f68: /* original e040, guest PC 0x0c0b6f68 */
if(!s->budget--) { s->failed_pc=0x0c0b6f68u; return 0; }
r[0]=0x00000040u;
goto P_0c0b6f6a;
P_0c0b6f6a: /* original 4e0b, guest PC 0x0c0b6f6a */
if(!s->budget--) { s->failed_pc=0x0c0b6f6au; return 0; }
target=r[14];
r[16]=code_base|0x0c0b6f6eu;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b6f6eu) { target=s->pc; goto dispatch; }
goto P_0c0b6f6e;
P_0c0b6f6c: /* original 05de, guest PC 0x0c0b6f6c */
if(!s->budget--) { s->failed_pc=0x0c0b6f6cu; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b6f6e;
P_0c0b6f6e: /* original 9483, guest PC 0x0c0b6f6e */
if(!s->budget--) { s->failed_pc=0x0c0b6f6eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b7078u,2);
goto P_0c0b6f70;
P_0c0b6f70: /* original e044, guest PC 0x0c0b6f70 */
if(!s->budget--) { s->failed_pc=0x0c0b6f70u; return 0; }
r[0]=0x00000044u;
goto P_0c0b6f72;
P_0c0b6f72: /* original 4e0b, guest PC 0x0c0b6f72 */
if(!s->budget--) { s->failed_pc=0x0c0b6f72u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b6f76u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b6f76u) { target=s->pc; goto dispatch; }
goto P_0c0b6f76;
P_0c0b6f74: /* original 05de, guest PC 0x0c0b6f74 */
if(!s->budget--) { s->failed_pc=0x0c0b6f74u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b6f76;
P_0c0b6f76: /* original 9480, guest PC 0x0c0b6f76 */
if(!s->budget--) { s->failed_pc=0x0c0b6f76u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b707au,2);
goto P_0c0b6f78;
P_0c0b6f78: /* original e048, guest PC 0x0c0b6f78 */
if(!s->budget--) { s->failed_pc=0x0c0b6f78u; return 0; }
r[0]=0x00000048u;
goto P_0c0b6f7a;
P_0c0b6f7a: /* original 4e0b, guest PC 0x0c0b6f7a */
if(!s->budget--) { s->failed_pc=0x0c0b6f7au; return 0; }
target=r[14];
r[16]=code_base|0x0c0b6f7eu;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b6f7eu) { target=s->pc; goto dispatch; }
goto P_0c0b6f7e;
P_0c0b6f7c: /* original 05de, guest PC 0x0c0b6f7c */
if(!s->budget--) { s->failed_pc=0x0c0b6f7cu; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b6f7e;
P_0c0b6f7e: /* original 947d, guest PC 0x0c0b6f7e */
if(!s->budget--) { s->failed_pc=0x0c0b6f7eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b707cu,2);
goto P_0c0b6f80;
P_0c0b6f80: /* original e04c, guest PC 0x0c0b6f80 */
if(!s->budget--) { s->failed_pc=0x0c0b6f80u; return 0; }
r[0]=0x0000004cu;
goto P_0c0b6f82;
P_0c0b6f82: /* original 4e0b, guest PC 0x0c0b6f82 */
if(!s->budget--) { s->failed_pc=0x0c0b6f82u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b6f86u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b6f86u) { target=s->pc; goto dispatch; }
goto P_0c0b6f86;
P_0c0b6f84: /* original 05de, guest PC 0x0c0b6f84 */
if(!s->budget--) { s->failed_pc=0x0c0b6f84u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b6f86;
P_0c0b6f86: /* original 947a, guest PC 0x0c0b6f86 */
if(!s->budget--) { s->failed_pc=0x0c0b6f86u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b707eu,2);
goto P_0c0b6f88;
P_0c0b6f88: /* original e050, guest PC 0x0c0b6f88 */
if(!s->budget--) { s->failed_pc=0x0c0b6f88u; return 0; }
r[0]=0x00000050u;
goto P_0c0b6f8a;
P_0c0b6f8a: /* original 4e0b, guest PC 0x0c0b6f8a */
if(!s->budget--) { s->failed_pc=0x0c0b6f8au; return 0; }
target=r[14];
r[16]=code_base|0x0c0b6f8eu;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b6f8eu) { target=s->pc; goto dispatch; }
goto P_0c0b6f8e;
P_0c0b6f8c: /* original 05de, guest PC 0x0c0b6f8c */
if(!s->budget--) { s->failed_pc=0x0c0b6f8cu; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b6f8e;
P_0c0b6f8e: /* original 9477, guest PC 0x0c0b6f8e */
if(!s->budget--) { s->failed_pc=0x0c0b6f8eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b7080u,2);
goto P_0c0b6f90;
P_0c0b6f90: /* original e054, guest PC 0x0c0b6f90 */
if(!s->budget--) { s->failed_pc=0x0c0b6f90u; return 0; }
r[0]=0x00000054u;
goto P_0c0b6f92;
P_0c0b6f92: /* original 4e0b, guest PC 0x0c0b6f92 */
if(!s->budget--) { s->failed_pc=0x0c0b6f92u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b6f96u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b6f96u) { target=s->pc; goto dispatch; }
goto P_0c0b6f96;
P_0c0b6f94: /* original 05de, guest PC 0x0c0b6f94 */
if(!s->budget--) { s->failed_pc=0x0c0b6f94u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b6f96;
P_0c0b6f96: /* original 9474, guest PC 0x0c0b6f96 */
if(!s->budget--) { s->failed_pc=0x0c0b6f96u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b7082u,2);
goto P_0c0b6f98;
P_0c0b6f98: /* original e058, guest PC 0x0c0b6f98 */
if(!s->budget--) { s->failed_pc=0x0c0b6f98u; return 0; }
r[0]=0x00000058u;
goto P_0c0b6f9a;
P_0c0b6f9a: /* original 4e0b, guest PC 0x0c0b6f9a */
if(!s->budget--) { s->failed_pc=0x0c0b6f9au; return 0; }
target=r[14];
r[16]=code_base|0x0c0b6f9eu;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b6f9eu) { target=s->pc; goto dispatch; }
goto P_0c0b6f9e;
P_0c0b6f9c: /* original 05de, guest PC 0x0c0b6f9c */
if(!s->budget--) { s->failed_pc=0x0c0b6f9cu; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b6f9e;
P_0c0b6f9e: /* original 9471, guest PC 0x0c0b6f9e */
if(!s->budget--) { s->failed_pc=0x0c0b6f9eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b7084u,2);
goto P_0c0b6fa0;
P_0c0b6fa0: /* original e05c, guest PC 0x0c0b6fa0 */
if(!s->budget--) { s->failed_pc=0x0c0b6fa0u; return 0; }
r[0]=0x0000005cu;
goto P_0c0b6fa2;
P_0c0b6fa2: /* original 4e0b, guest PC 0x0c0b6fa2 */
if(!s->budget--) { s->failed_pc=0x0c0b6fa2u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b6fa6u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b6fa6u) { target=s->pc; goto dispatch; }
goto P_0c0b6fa6;
P_0c0b6fa4: /* original 05de, guest PC 0x0c0b6fa4 */
if(!s->budget--) { s->failed_pc=0x0c0b6fa4u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b6fa6;
P_0c0b6fa6: /* original 946e, guest PC 0x0c0b6fa6 */
if(!s->budget--) { s->failed_pc=0x0c0b6fa6u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b7086u,2);
goto P_0c0b6fa8;
P_0c0b6fa8: /* original e060, guest PC 0x0c0b6fa8 */
if(!s->budget--) { s->failed_pc=0x0c0b6fa8u; return 0; }
r[0]=0x00000060u;
goto P_0c0b6faa;
P_0c0b6faa: /* original 4e0b, guest PC 0x0c0b6faa */
if(!s->budget--) { s->failed_pc=0x0c0b6faau; return 0; }
target=r[14];
r[16]=code_base|0x0c0b6faeu;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b6faeu) { target=s->pc; goto dispatch; }
goto P_0c0b6fae;
P_0c0b6fac: /* original 05de, guest PC 0x0c0b6fac */
if(!s->budget--) { s->failed_pc=0x0c0b6facu; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b6fae;
P_0c0b6fae: /* original 946b, guest PC 0x0c0b6fae */
if(!s->budget--) { s->failed_pc=0x0c0b6faeu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b7088u,2);
goto P_0c0b6fb0;
P_0c0b6fb0: /* original e064, guest PC 0x0c0b6fb0 */
if(!s->budget--) { s->failed_pc=0x0c0b6fb0u; return 0; }
r[0]=0x00000064u;
goto P_0c0b6fb2;
P_0c0b6fb2: /* original 4e0b, guest PC 0x0c0b6fb2 */
if(!s->budget--) { s->failed_pc=0x0c0b6fb2u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b6fb6u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b6fb6u) { target=s->pc; goto dispatch; }
goto P_0c0b6fb6;
P_0c0b6fb4: /* original 05de, guest PC 0x0c0b6fb4 */
if(!s->budget--) { s->failed_pc=0x0c0b6fb4u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b6fb6;
P_0c0b6fb6: /* original 9468, guest PC 0x0c0b6fb6 */
if(!s->budget--) { s->failed_pc=0x0c0b6fb6u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b708au,2);
goto P_0c0b6fb8;
P_0c0b6fb8: /* original e068, guest PC 0x0c0b6fb8 */
if(!s->budget--) { s->failed_pc=0x0c0b6fb8u; return 0; }
r[0]=0x00000068u;
goto P_0c0b6fba;
P_0c0b6fba: /* original 4e0b, guest PC 0x0c0b6fba */
if(!s->budget--) { s->failed_pc=0x0c0b6fbau; return 0; }
target=r[14];
r[16]=code_base|0x0c0b6fbeu;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b6fbeu) { target=s->pc; goto dispatch; }
goto P_0c0b6fbe;
P_0c0b6fbc: /* original 05de, guest PC 0x0c0b6fbc */
if(!s->budget--) { s->failed_pc=0x0c0b6fbcu; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b6fbe;
P_0c0b6fbe: /* original 9465, guest PC 0x0c0b6fbe */
if(!s->budget--) { s->failed_pc=0x0c0b6fbeu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b708cu,2);
goto P_0c0b6fc0;
P_0c0b6fc0: /* original e06c, guest PC 0x0c0b6fc0 */
if(!s->budget--) { s->failed_pc=0x0c0b6fc0u; return 0; }
r[0]=0x0000006cu;
goto P_0c0b6fc2;
P_0c0b6fc2: /* original 4e0b, guest PC 0x0c0b6fc2 */
if(!s->budget--) { s->failed_pc=0x0c0b6fc2u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b6fc6u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b6fc6u) { target=s->pc; goto dispatch; }
goto P_0c0b6fc6;
P_0c0b6fc4: /* original 05de, guest PC 0x0c0b6fc4 */
if(!s->budget--) { s->failed_pc=0x0c0b6fc4u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b6fc6;
P_0c0b6fc6: /* original 9462, guest PC 0x0c0b6fc6 */
if(!s->budget--) { s->failed_pc=0x0c0b6fc6u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b708eu,2);
goto P_0c0b6fc8;
P_0c0b6fc8: /* original e070, guest PC 0x0c0b6fc8 */
if(!s->budget--) { s->failed_pc=0x0c0b6fc8u; return 0; }
r[0]=0x00000070u;
goto P_0c0b6fca;
P_0c0b6fca: /* original 4e0b, guest PC 0x0c0b6fca */
if(!s->budget--) { s->failed_pc=0x0c0b6fcau; return 0; }
target=r[14];
r[16]=code_base|0x0c0b6fceu;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b6fceu) { target=s->pc; goto dispatch; }
goto P_0c0b6fce;
P_0c0b6fcc: /* original 05de, guest PC 0x0c0b6fcc */
if(!s->budget--) { s->failed_pc=0x0c0b6fccu; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b6fce;
P_0c0b6fce: /* original 945f, guest PC 0x0c0b6fce */
if(!s->budget--) { s->failed_pc=0x0c0b6fceu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b7090u,2);
goto P_0c0b6fd0;
P_0c0b6fd0: /* original e074, guest PC 0x0c0b6fd0 */
if(!s->budget--) { s->failed_pc=0x0c0b6fd0u; return 0; }
r[0]=0x00000074u;
goto P_0c0b6fd2;
P_0c0b6fd2: /* original 4e0b, guest PC 0x0c0b6fd2 */
if(!s->budget--) { s->failed_pc=0x0c0b6fd2u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b6fd6u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b6fd6u) { target=s->pc; goto dispatch; }
goto P_0c0b6fd6;
P_0c0b6fd4: /* original 05de, guest PC 0x0c0b6fd4 */
if(!s->budget--) { s->failed_pc=0x0c0b6fd4u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b6fd6;
P_0c0b6fd6: /* original 945c, guest PC 0x0c0b6fd6 */
if(!s->budget--) { s->failed_pc=0x0c0b6fd6u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b7092u,2);
goto P_0c0b6fd8;
P_0c0b6fd8: /* original e078, guest PC 0x0c0b6fd8 */
if(!s->budget--) { s->failed_pc=0x0c0b6fd8u; return 0; }
r[0]=0x00000078u;
goto P_0c0b6fda;
P_0c0b6fda: /* original 4e0b, guest PC 0x0c0b6fda */
if(!s->budget--) { s->failed_pc=0x0c0b6fdau; return 0; }
target=r[14];
r[16]=code_base|0x0c0b6fdeu;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b6fdeu) { target=s->pc; goto dispatch; }
goto P_0c0b6fde;
P_0c0b6fdc: /* original 05de, guest PC 0x0c0b6fdc */
if(!s->budget--) { s->failed_pc=0x0c0b6fdcu; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b6fde;
P_0c0b6fde: /* original 9459, guest PC 0x0c0b6fde */
if(!s->budget--) { s->failed_pc=0x0c0b6fdeu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b7094u,2);
goto P_0c0b6fe0;
P_0c0b6fe0: /* original e07c, guest PC 0x0c0b6fe0 */
if(!s->budget--) { s->failed_pc=0x0c0b6fe0u; return 0; }
r[0]=0x0000007cu;
goto P_0c0b6fe2;
P_0c0b6fe2: /* original 4e0b, guest PC 0x0c0b6fe2 */
if(!s->budget--) { s->failed_pc=0x0c0b6fe2u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b6fe6u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b6fe6u) { target=s->pc; goto dispatch; }
goto P_0c0b6fe6;
P_0c0b6fe4: /* original 05de, guest PC 0x0c0b6fe4 */
if(!s->budget--) { s->failed_pc=0x0c0b6fe4u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b6fe6;
P_0c0b6fe6: /* original 9457, guest PC 0x0c0b6fe6 */
if(!s->budget--) { s->failed_pc=0x0c0b6fe6u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b7098u,2);
goto P_0c0b6fe8;
P_0c0b6fe8: /* original 9055, guest PC 0x0c0b6fe8 */
if(!s->budget--) { s->failed_pc=0x0c0b6fe8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b7096u,2);
goto P_0c0b6fea;
P_0c0b6fea: /* original 4e0b, guest PC 0x0c0b6fea */
if(!s->budget--) { s->failed_pc=0x0c0b6feau; return 0; }
target=r[14];
r[16]=code_base|0x0c0b6feeu;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b6feeu) { target=s->pc; goto dispatch; }
goto P_0c0b6fee;
P_0c0b6fec: /* original 05de, guest PC 0x0c0b6fec */
if(!s->budget--) { s->failed_pc=0x0c0b6fecu; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b6fee;
P_0c0b6fee: /* original 9554, guest PC 0x0c0b6fee */
if(!s->budget--) { s->failed_pc=0x0c0b6feeu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b709au,2);
goto P_0c0b6ff0;
P_0c0b6ff0: /* original 35dc, guest PC 0x0c0b6ff0 */
if(!s->budget--) { s->failed_pc=0x0c0b6ff0u; return 0; }
r[5]+=r[13];
goto P_0c0b6ff2;
P_0c0b6ff2: /* original 2f52, guest PC 0x0c0b6ff2 */
if(!s->budget--) { s->failed_pc=0x0c0b6ff2u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0b6ff4;
P_0c0b6ff4: /* original 9452, guest PC 0x0c0b6ff4 */
if(!s->budget--) { s->failed_pc=0x0c0b6ff4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b709cu,2);
goto P_0c0b6ff6;
P_0c0b6ff6: /* original 4e0b, guest PC 0x0c0b6ff6 */
if(!s->budget--) { s->failed_pc=0x0c0b6ff6u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b6ffau;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b6ffau) { target=s->pc; goto dispatch; }
goto P_0c0b6ffa;
P_0c0b6ff8: /* original 6552, guest PC 0x0c0b6ff8 */
if(!s->budget--) { s->failed_pc=0x0c0b6ff8u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b6ffa;
P_0c0b6ffa: /* original 9550, guest PC 0x0c0b6ffa */
if(!s->budget--) { s->failed_pc=0x0c0b6ffau; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b709eu,2);
goto P_0c0b6ffc;
P_0c0b6ffc: /* original 35dc, guest PC 0x0c0b6ffc */
if(!s->budget--) { s->failed_pc=0x0c0b6ffcu; return 0; }
r[5]+=r[13];
goto P_0c0b6ffe;
P_0c0b6ffe: /* original 1f51, guest PC 0x0c0b6ffe */
if(!s->budget--) { s->failed_pc=0x0c0b6ffeu; return 0; }
write(ram,r[15]+4,r[5],4);
goto P_0c0b7000;
P_0c0b7000: /* original 944e, guest PC 0x0c0b7000 */
if(!s->budget--) { s->failed_pc=0x0c0b7000u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b70a0u,2);
goto P_0c0b7002;
P_0c0b7002: /* original 4e0b, guest PC 0x0c0b7002 */
if(!s->budget--) { s->failed_pc=0x0c0b7002u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b7006u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b7006u) { target=s->pc; goto dispatch; }
goto P_0c0b7006;
P_0c0b7004: /* original 6552, guest PC 0x0c0b7004 */
if(!s->budget--) { s->failed_pc=0x0c0b7004u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b7006;
P_0c0b7006: /* original 944d, guest PC 0x0c0b7006 */
if(!s->budget--) { s->failed_pc=0x0c0b7006u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b70a4u,2);
goto P_0c0b7008;
P_0c0b7008: /* original 904b, guest PC 0x0c0b7008 */
if(!s->budget--) { s->failed_pc=0x0c0b7008u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b70a2u,2);
goto P_0c0b700a;
P_0c0b700a: /* original 4e0b, guest PC 0x0c0b700a */
if(!s->budget--) { s->failed_pc=0x0c0b700au; return 0; }
target=r[14];
r[16]=code_base|0x0c0b700eu;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b700eu) { target=s->pc; goto dispatch; }
goto P_0c0b700e;
P_0c0b700c: /* original 05de, guest PC 0x0c0b700c */
if(!s->budget--) { s->failed_pc=0x0c0b700cu; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b700e;
P_0c0b700e: /* original 944b, guest PC 0x0c0b700e */
if(!s->budget--) { s->failed_pc=0x0c0b700eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b70a8u,2);
goto P_0c0b7010;
P_0c0b7010: /* original 9049, guest PC 0x0c0b7010 */
if(!s->budget--) { s->failed_pc=0x0c0b7010u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b70a6u,2);
goto P_0c0b7012;
P_0c0b7012: /* original 4e0b, guest PC 0x0c0b7012 */
if(!s->budget--) { s->failed_pc=0x0c0b7012u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b7016u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b7016u) { target=s->pc; goto dispatch; }
goto P_0c0b7016;
P_0c0b7014: /* original 05de, guest PC 0x0c0b7014 */
if(!s->budget--) { s->failed_pc=0x0c0b7014u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b7016;
P_0c0b7016: /* original 9948, guest PC 0x0c0b7016 */
if(!s->budget--) { s->failed_pc=0x0c0b7016u; return 0; }
r[9]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b70aau,2);
goto P_0c0b7018;
P_0c0b7018: /* original 9448, guest PC 0x0c0b7018 */
if(!s->budget--) { s->failed_pc=0x0c0b7018u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b70acu,2);
goto P_0c0b701a;
P_0c0b701a: /* original 39dc, guest PC 0x0c0b701a */
if(!s->budget--) { s->failed_pc=0x0c0b701au; return 0; }
r[9]+=r[13];
goto P_0c0b701c;
P_0c0b701c: /* original 4e0b, guest PC 0x0c0b701c */
if(!s->budget--) { s->failed_pc=0x0c0b701cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b7020u;
tmp=read(ram,r[9],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b7020u) { target=s->pc; goto dispatch; }
goto P_0c0b7020;
P_0c0b701e: /* original 6592, guest PC 0x0c0b701e */
if(!s->budget--) { s->failed_pc=0x0c0b701eu; return 0; }
tmp=read(ram,r[9],4);
r[5]=tmp;
goto P_0c0b7020;
P_0c0b7020: /* original 9445, guest PC 0x0c0b7020 */
if(!s->budget--) { s->failed_pc=0x0c0b7020u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b70aeu,2);
goto P_0c0b7022;
P_0c0b7022: /* original 4e0b, guest PC 0x0c0b7022 */
if(!s->budget--) { s->failed_pc=0x0c0b7022u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b7026u;
tmp=read(ram,r[9],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b7026u) { target=s->pc; goto dispatch; }
goto P_0c0b7026;
P_0c0b7024: /* original 6592, guest PC 0x0c0b7024 */
if(!s->budget--) { s->failed_pc=0x0c0b7024u; return 0; }
tmp=read(ram,r[9],4);
r[5]=tmp;
goto P_0c0b7026;
P_0c0b7026: /* original 9443, guest PC 0x0c0b7026 */
if(!s->budget--) { s->failed_pc=0x0c0b7026u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b70b0u,2);
goto P_0c0b7028;
P_0c0b7028: /* original 4e0b, guest PC 0x0c0b7028 */
if(!s->budget--) { s->failed_pc=0x0c0b7028u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b702cu;
tmp=read(ram,r[9],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b702cu) { target=s->pc; goto dispatch; }
goto P_0c0b702c;
P_0c0b702a: /* original 6592, guest PC 0x0c0b702a */
if(!s->budget--) { s->failed_pc=0x0c0b702au; return 0; }
tmp=read(ram,r[9],4);
r[5]=tmp;
goto P_0c0b702c;
P_0c0b702c: /* original 9441, guest PC 0x0c0b702c */
if(!s->budget--) { s->failed_pc=0x0c0b702cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b70b2u,2);
goto P_0c0b702e;
P_0c0b702e: /* original 4e0b, guest PC 0x0c0b702e */
if(!s->budget--) { s->failed_pc=0x0c0b702eu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b7032u;
tmp=read(ram,r[9],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b7032u) { target=s->pc; goto dispatch; }
goto P_0c0b7032;
P_0c0b7030: /* original 6592, guest PC 0x0c0b7030 */
if(!s->budget--) { s->failed_pc=0x0c0b7030u; return 0; }
tmp=read(ram,r[9],4);
r[5]=tmp;
goto P_0c0b7032;
P_0c0b7032: /* original 9c3f, guest PC 0x0c0b7032 */
if(!s->budget--) { s->failed_pc=0x0c0b7032u; return 0; }
r[12]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b70b4u,2);
goto P_0c0b7034;
P_0c0b7034: /* original 943f, guest PC 0x0c0b7034 */
if(!s->budget--) { s->failed_pc=0x0c0b7034u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b70b6u,2);
goto P_0c0b7036;
P_0c0b7036: /* original 3cdc, guest PC 0x0c0b7036 */
if(!s->budget--) { s->failed_pc=0x0c0b7036u; return 0; }
r[12]+=r[13];
goto P_0c0b7038;
P_0c0b7038: /* original 4e0b, guest PC 0x0c0b7038 */
if(!s->budget--) { s->failed_pc=0x0c0b7038u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b703cu;
tmp=read(ram,r[12],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b703cu) { target=s->pc; goto dispatch; }
goto P_0c0b703c;
P_0c0b703a: /* original 65c2, guest PC 0x0c0b703a */
if(!s->budget--) { s->failed_pc=0x0c0b703au; return 0; }
tmp=read(ram,r[12],4);
r[5]=tmp;
goto P_0c0b703c;
P_0c0b703c: /* original 943c, guest PC 0x0c0b703c */
if(!s->budget--) { s->failed_pc=0x0c0b703cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b70b8u,2);
goto P_0c0b703e;
P_0c0b703e: /* original 4e0b, guest PC 0x0c0b703e */
if(!s->budget--) { s->failed_pc=0x0c0b703eu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b7042u;
tmp=read(ram,r[12],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b7042u) { target=s->pc; goto dispatch; }
goto P_0c0b7042;
P_0c0b7040: /* original 65c2, guest PC 0x0c0b7040 */
if(!s->budget--) { s->failed_pc=0x0c0b7040u; return 0; }
tmp=read(ram,r[12],4);
r[5]=tmp;
goto P_0c0b7042;
P_0c0b7042: /* original 943a, guest PC 0x0c0b7042 */
if(!s->budget--) { s->failed_pc=0x0c0b7042u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b70bau,2);
goto P_0c0b7044;
P_0c0b7044: /* original 4e0b, guest PC 0x0c0b7044 */
if(!s->budget--) { s->failed_pc=0x0c0b7044u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b7048u;
tmp=read(ram,r[12],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b7048u) { target=s->pc; goto dispatch; }
goto P_0c0b7048;
P_0c0b7046: /* original 65c2, guest PC 0x0c0b7046 */
if(!s->budget--) { s->failed_pc=0x0c0b7046u; return 0; }
tmp=read(ram,r[12],4);
r[5]=tmp;
goto P_0c0b7048;
P_0c0b7048: /* original 9438, guest PC 0x0c0b7048 */
if(!s->budget--) { s->failed_pc=0x0c0b7048u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b70bcu,2);
goto P_0c0b704a;
P_0c0b704a: /* original 4e0b, guest PC 0x0c0b704a */
if(!s->budget--) { s->failed_pc=0x0c0b704au; return 0; }
target=r[14];
r[16]=code_base|0x0c0b704eu;
tmp=read(ram,r[12],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b704eu) { target=s->pc; goto dispatch; }
goto P_0c0b704e;
P_0c0b704c: /* original 65c2, guest PC 0x0c0b704c */
if(!s->budget--) { s->failed_pc=0x0c0b704cu; return 0; }
tmp=read(ram,r[12],4);
r[5]=tmp;
goto P_0c0b704e;
P_0c0b704e: /* original 9b36, guest PC 0x0c0b704e */
if(!s->budget--) { s->failed_pc=0x0c0b704eu; return 0; }
r[11]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b70beu,2);
goto P_0c0b7050;
P_0c0b7050: /* original 3bdc, guest PC 0x0c0b7050 */
if(!s->budget--) { s->failed_pc=0x0c0b7050u; return 0; }
r[11]+=r[13];
goto P_0c0b7052;
P_0c0b7052: /* original a037, guest PC 0x0c0b7052 */
if(!s->budget--) { s->failed_pc=0x0c0b7052u; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
goto P_0c0b70c4;
P_0c0b7054: /* original 65b2, guest PC 0x0c0b7054 */
if(!s->budget--) { s->failed_pc=0x0c0b7054u; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
if(!vf3_matrix_family(0x0c0b7056u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0b7056u; return 0; } return 1;
P_0c0b70c4: /* original 94ab, guest PC 0x0c0b70c4 */
if(!s->budget--) { s->failed_pc=0x0c0b70c4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b721eu,2);
goto P_0c0b70c6;
P_0c0b70c6: /* original 4e0b, guest PC 0x0c0b70c6 */
if(!s->budget--) { s->failed_pc=0x0c0b70c6u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b70cau;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b70cau) { target=s->pc; goto dispatch; }
goto P_0c0b70ca;
P_0c0b70c8: /* original 0009, guest PC 0x0c0b70c8 */
if(!s->budget--) { s->failed_pc=0x0c0b70c8u; return 0; }
goto P_0c0b70ca;
P_0c0b70ca: /* original 94a9, guest PC 0x0c0b70ca */
if(!s->budget--) { s->failed_pc=0x0c0b70cau; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b7220u,2);
goto P_0c0b70cc;
P_0c0b70cc: /* original 4e0b, guest PC 0x0c0b70cc */
if(!s->budget--) { s->failed_pc=0x0c0b70ccu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b70d0u;
tmp=read(ram,r[11],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b70d0u) { target=s->pc; goto dispatch; }
goto P_0c0b70d0;
P_0c0b70ce: /* original 65b2, guest PC 0x0c0b70ce */
if(!s->budget--) { s->failed_pc=0x0c0b70ceu; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
goto P_0c0b70d0;
P_0c0b70d0: /* original 94a7, guest PC 0x0c0b70d0 */
if(!s->budget--) { s->failed_pc=0x0c0b70d0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b7222u,2);
goto P_0c0b70d2;
P_0c0b70d2: /* original 4e0b, guest PC 0x0c0b70d2 */
if(!s->budget--) { s->failed_pc=0x0c0b70d2u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b70d6u;
tmp=read(ram,r[11],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b70d6u) { target=s->pc; goto dispatch; }
goto P_0c0b70d6;
P_0c0b70d4: /* original 65b2, guest PC 0x0c0b70d4 */
if(!s->budget--) { s->failed_pc=0x0c0b70d4u; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
goto P_0c0b70d6;
P_0c0b70d6: /* original 94a5, guest PC 0x0c0b70d6 */
if(!s->budget--) { s->failed_pc=0x0c0b70d6u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b7224u,2);
goto P_0c0b70d8;
P_0c0b70d8: /* original 4e0b, guest PC 0x0c0b70d8 */
if(!s->budget--) { s->failed_pc=0x0c0b70d8u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b70dcu;
tmp=read(ram,r[11],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b70dcu) { target=s->pc; goto dispatch; }
goto P_0c0b70dc;
P_0c0b70da: /* original 65b2, guest PC 0x0c0b70da */
if(!s->budget--) { s->failed_pc=0x0c0b70dau; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
goto P_0c0b70dc;
P_0c0b70dc: /* original 9aa3, guest PC 0x0c0b70dc */
if(!s->budget--) { s->failed_pc=0x0c0b70dcu; return 0; }
r[10]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b7226u,2);
goto P_0c0b70de;
P_0c0b70de: /* original 94a3, guest PC 0x0c0b70de */
if(!s->budget--) { s->failed_pc=0x0c0b70deu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b7228u,2);
goto P_0c0b70e0;
P_0c0b70e0: /* original 3adc, guest PC 0x0c0b70e0 */
if(!s->budget--) { s->failed_pc=0x0c0b70e0u; return 0; }
r[10]+=r[13];
goto P_0c0b70e2;
P_0c0b70e2: /* original 4e0b, guest PC 0x0c0b70e2 */
if(!s->budget--) { s->failed_pc=0x0c0b70e2u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b70e6u;
tmp=read(ram,r[10],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b70e6u) { target=s->pc; goto dispatch; }
goto P_0c0b70e6;
P_0c0b70e4: /* original 65a2, guest PC 0x0c0b70e4 */
if(!s->budget--) { s->failed_pc=0x0c0b70e4u; return 0; }
tmp=read(ram,r[10],4);
r[5]=tmp;
goto P_0c0b70e6;
P_0c0b70e6: /* original 94a0, guest PC 0x0c0b70e6 */
if(!s->budget--) { s->failed_pc=0x0c0b70e6u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b722au,2);
goto P_0c0b70e8;
P_0c0b70e8: /* original 4e0b, guest PC 0x0c0b70e8 */
if(!s->budget--) { s->failed_pc=0x0c0b70e8u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b70ecu;
tmp=read(ram,r[10],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b70ecu) { target=s->pc; goto dispatch; }
goto P_0c0b70ec;
P_0c0b70ea: /* original 65a2, guest PC 0x0c0b70ea */
if(!s->budget--) { s->failed_pc=0x0c0b70eau; return 0; }
tmp=read(ram,r[10],4);
r[5]=tmp;
goto P_0c0b70ec;
P_0c0b70ec: /* original 949e, guest PC 0x0c0b70ec */
if(!s->budget--) { s->failed_pc=0x0c0b70ecu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b722cu,2);
goto P_0c0b70ee;
P_0c0b70ee: /* original 4e0b, guest PC 0x0c0b70ee */
if(!s->budget--) { s->failed_pc=0x0c0b70eeu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b70f2u;
tmp=read(ram,r[10],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b70f2u) { target=s->pc; goto dispatch; }
goto P_0c0b70f2;
P_0c0b70f0: /* original 65a2, guest PC 0x0c0b70f0 */
if(!s->budget--) { s->failed_pc=0x0c0b70f0u; return 0; }
tmp=read(ram,r[10],4);
r[5]=tmp;
goto P_0c0b70f2;
P_0c0b70f2: /* original 949c, guest PC 0x0c0b70f2 */
if(!s->budget--) { s->failed_pc=0x0c0b70f2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b722eu,2);
goto P_0c0b70f4;
P_0c0b70f4: /* original 4e0b, guest PC 0x0c0b70f4 */
if(!s->budget--) { s->failed_pc=0x0c0b70f4u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b70f8u;
tmp=read(ram,r[10],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b70f8u) { target=s->pc; goto dispatch; }
goto P_0c0b70f8;
P_0c0b70f6: /* original 65a2, guest PC 0x0c0b70f6 */
if(!s->budget--) { s->failed_pc=0x0c0b70f6u; return 0; }
tmp=read(ram,r[10],4);
r[5]=tmp;
goto P_0c0b70f8;
P_0c0b70f8: /* original 949a, guest PC 0x0c0b70f8 */
if(!s->budget--) { s->failed_pc=0x0c0b70f8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b7230u,2);
goto P_0c0b70fa;
P_0c0b70fa: /* original 65f2, guest PC 0x0c0b70fa */
if(!s->budget--) { s->failed_pc=0x0c0b70fau; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0b70fc;
P_0c0b70fc: /* original 4e0b, guest PC 0x0c0b70fc */
if(!s->budget--) { s->failed_pc=0x0c0b70fcu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b7100u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b7100u) { target=s->pc; goto dispatch; }
goto P_0c0b7100;
P_0c0b70fe: /* original 6552, guest PC 0x0c0b70fe */
if(!s->budget--) { s->failed_pc=0x0c0b70feu; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b7100;
P_0c0b7100: /* original 9497, guest PC 0x0c0b7100 */
if(!s->budget--) { s->failed_pc=0x0c0b7100u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b7232u,2);
goto P_0c0b7102;
P_0c0b7102: /* original 55f1, guest PC 0x0c0b7102 */
if(!s->budget--) { s->failed_pc=0x0c0b7102u; return 0; }
r[5]=read(ram,r[15]+4,4);
goto P_0c0b7104;
P_0c0b7104: /* original 4e0b, guest PC 0x0c0b7104 */
if(!s->budget--) { s->failed_pc=0x0c0b7104u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b7108u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b7108u) { target=s->pc; goto dispatch; }
goto P_0c0b7108;
P_0c0b7106: /* original 6552, guest PC 0x0c0b7106 */
if(!s->budget--) { s->failed_pc=0x0c0b7106u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b7108;
P_0c0b7108: /* original 9494, guest PC 0x0c0b7108 */
if(!s->budget--) { s->failed_pc=0x0c0b7108u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b7234u,2);
goto P_0c0b710a;
P_0c0b710a: /* original 4e0b, guest PC 0x0c0b710a */
if(!s->budget--) { s->failed_pc=0x0c0b710au; return 0; }
target=r[14];
r[16]=code_base|0x0c0b710eu;
tmp=read(ram,r[9],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b710eu) { target=s->pc; goto dispatch; }
goto P_0c0b710e;
P_0c0b710c: /* original 6592, guest PC 0x0c0b710c */
if(!s->budget--) { s->failed_pc=0x0c0b710cu; return 0; }
tmp=read(ram,r[9],4);
r[5]=tmp;
goto P_0c0b710e;
P_0c0b710e: /* original 9492, guest PC 0x0c0b710e */
if(!s->budget--) { s->failed_pc=0x0c0b710eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b7236u,2);
goto P_0c0b7110;
P_0c0b7110: /* original 4e0b, guest PC 0x0c0b7110 */
if(!s->budget--) { s->failed_pc=0x0c0b7110u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b7114u;
tmp=read(ram,r[9],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b7114u) { target=s->pc; goto dispatch; }
goto P_0c0b7114;
P_0c0b7112: /* original 6592, guest PC 0x0c0b7112 */
if(!s->budget--) { s->failed_pc=0x0c0b7112u; return 0; }
tmp=read(ram,r[9],4);
r[5]=tmp;
goto P_0c0b7114;
P_0c0b7114: /* original 9490, guest PC 0x0c0b7114 */
if(!s->budget--) { s->failed_pc=0x0c0b7114u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b7238u,2);
goto P_0c0b7116;
P_0c0b7116: /* original 4e0b, guest PC 0x0c0b7116 */
if(!s->budget--) { s->failed_pc=0x0c0b7116u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b711au;
tmp=read(ram,r[9],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b711au) { target=s->pc; goto dispatch; }
goto P_0c0b711a;
P_0c0b7118: /* original 6592, guest PC 0x0c0b7118 */
if(!s->budget--) { s->failed_pc=0x0c0b7118u; return 0; }
tmp=read(ram,r[9],4);
r[5]=tmp;
goto P_0c0b711a;
P_0c0b711a: /* original 948e, guest PC 0x0c0b711a */
if(!s->budget--) { s->failed_pc=0x0c0b711au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b723au,2);
goto P_0c0b711c;
P_0c0b711c: /* original 4e0b, guest PC 0x0c0b711c */
if(!s->budget--) { s->failed_pc=0x0c0b711cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b7120u;
tmp=read(ram,r[9],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b7120u) { target=s->pc; goto dispatch; }
goto P_0c0b7120;
P_0c0b711e: /* original 6592, guest PC 0x0c0b711e */
if(!s->budget--) { s->failed_pc=0x0c0b711eu; return 0; }
tmp=read(ram,r[9],4);
r[5]=tmp;
goto P_0c0b7120;
P_0c0b7120: /* original 948c, guest PC 0x0c0b7120 */
if(!s->budget--) { s->failed_pc=0x0c0b7120u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b723cu,2);
goto P_0c0b7122;
P_0c0b7122: /* original 4e0b, guest PC 0x0c0b7122 */
if(!s->budget--) { s->failed_pc=0x0c0b7122u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b7126u;
tmp=read(ram,r[12],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b7126u) { target=s->pc; goto dispatch; }
goto P_0c0b7126;
P_0c0b7124: /* original 65c2, guest PC 0x0c0b7124 */
if(!s->budget--) { s->failed_pc=0x0c0b7124u; return 0; }
tmp=read(ram,r[12],4);
r[5]=tmp;
goto P_0c0b7126;
P_0c0b7126: /* original 948a, guest PC 0x0c0b7126 */
if(!s->budget--) { s->failed_pc=0x0c0b7126u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b723eu,2);
goto P_0c0b7128;
P_0c0b7128: /* original 4e0b, guest PC 0x0c0b7128 */
if(!s->budget--) { s->failed_pc=0x0c0b7128u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b712cu;
tmp=read(ram,r[12],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b712cu) { target=s->pc; goto dispatch; }
goto P_0c0b712c;
P_0c0b712a: /* original 65c2, guest PC 0x0c0b712a */
if(!s->budget--) { s->failed_pc=0x0c0b712au; return 0; }
tmp=read(ram,r[12],4);
r[5]=tmp;
goto P_0c0b712c;
P_0c0b712c: /* original 9488, guest PC 0x0c0b712c */
if(!s->budget--) { s->failed_pc=0x0c0b712cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b7240u,2);
goto P_0c0b712e;
P_0c0b712e: /* original 4e0b, guest PC 0x0c0b712e */
if(!s->budget--) { s->failed_pc=0x0c0b712eu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b7132u;
tmp=read(ram,r[12],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b7132u) { target=s->pc; goto dispatch; }
goto P_0c0b7132;
P_0c0b7130: /* original 65c2, guest PC 0x0c0b7130 */
if(!s->budget--) { s->failed_pc=0x0c0b7130u; return 0; }
tmp=read(ram,r[12],4);
r[5]=tmp;
goto P_0c0b7132;
P_0c0b7132: /* original 9486, guest PC 0x0c0b7132 */
if(!s->budget--) { s->failed_pc=0x0c0b7132u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b7242u,2);
goto P_0c0b7134;
P_0c0b7134: /* original 4e0b, guest PC 0x0c0b7134 */
if(!s->budget--) { s->failed_pc=0x0c0b7134u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b7138u;
tmp=read(ram,r[12],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b7138u) { target=s->pc; goto dispatch; }
goto P_0c0b7138;
P_0c0b7136: /* original 65c2, guest PC 0x0c0b7136 */
if(!s->budget--) { s->failed_pc=0x0c0b7136u; return 0; }
tmp=read(ram,r[12],4);
r[5]=tmp;
goto P_0c0b7138;
P_0c0b7138: /* original 9484, guest PC 0x0c0b7138 */
if(!s->budget--) { s->failed_pc=0x0c0b7138u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b7244u,2);
goto P_0c0b713a;
P_0c0b713a: /* original 4e0b, guest PC 0x0c0b713a */
if(!s->budget--) { s->failed_pc=0x0c0b713au; return 0; }
target=r[14];
r[16]=code_base|0x0c0b713eu;
tmp=read(ram,r[11],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b713eu) { target=s->pc; goto dispatch; }
goto P_0c0b713e;
P_0c0b713c: /* original 65b2, guest PC 0x0c0b713c */
if(!s->budget--) { s->failed_pc=0x0c0b713cu; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
goto P_0c0b713e;
P_0c0b713e: /* original 9482, guest PC 0x0c0b713e */
if(!s->budget--) { s->failed_pc=0x0c0b713eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b7246u,2);
goto P_0c0b7140;
P_0c0b7140: /* original 4e0b, guest PC 0x0c0b7140 */
if(!s->budget--) { s->failed_pc=0x0c0b7140u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b7144u;
tmp=read(ram,r[11],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b7144u) { target=s->pc; goto dispatch; }
goto P_0c0b7144;
P_0c0b7142: /* original 65b2, guest PC 0x0c0b7142 */
if(!s->budget--) { s->failed_pc=0x0c0b7142u; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
goto P_0c0b7144;
P_0c0b7144: /* original 9480, guest PC 0x0c0b7144 */
if(!s->budget--) { s->failed_pc=0x0c0b7144u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b7248u,2);
goto P_0c0b7146;
P_0c0b7146: /* original 4e0b, guest PC 0x0c0b7146 */
if(!s->budget--) { s->failed_pc=0x0c0b7146u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b714au;
tmp=read(ram,r[11],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b714au) { target=s->pc; goto dispatch; }
goto P_0c0b714a;
P_0c0b7148: /* original 65b2, guest PC 0x0c0b7148 */
if(!s->budget--) { s->failed_pc=0x0c0b7148u; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
goto P_0c0b714a;
P_0c0b714a: /* original 947e, guest PC 0x0c0b714a */
if(!s->budget--) { s->failed_pc=0x0c0b714au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b724au,2);
goto P_0c0b714c;
P_0c0b714c: /* original 4e0b, guest PC 0x0c0b714c */
if(!s->budget--) { s->failed_pc=0x0c0b714cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b7150u;
tmp=read(ram,r[11],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b7150u) { target=s->pc; goto dispatch; }
goto P_0c0b7150;
P_0c0b714e: /* original 65b2, guest PC 0x0c0b714e */
if(!s->budget--) { s->failed_pc=0x0c0b714eu; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
goto P_0c0b7150;
P_0c0b7150: /* original 947c, guest PC 0x0c0b7150 */
if(!s->budget--) { s->failed_pc=0x0c0b7150u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b724cu,2);
goto P_0c0b7152;
P_0c0b7152: /* original 4e0b, guest PC 0x0c0b7152 */
if(!s->budget--) { s->failed_pc=0x0c0b7152u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b7156u;
tmp=read(ram,r[10],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b7156u) { target=s->pc; goto dispatch; }
goto P_0c0b7156;
P_0c0b7154: /* original 65a2, guest PC 0x0c0b7154 */
if(!s->budget--) { s->failed_pc=0x0c0b7154u; return 0; }
tmp=read(ram,r[10],4);
r[5]=tmp;
goto P_0c0b7156;
P_0c0b7156: /* original 947a, guest PC 0x0c0b7156 */
if(!s->budget--) { s->failed_pc=0x0c0b7156u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b724eu,2);
goto P_0c0b7158;
P_0c0b7158: /* original 4e0b, guest PC 0x0c0b7158 */
if(!s->budget--) { s->failed_pc=0x0c0b7158u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b715cu;
tmp=read(ram,r[10],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b715cu) { target=s->pc; goto dispatch; }
goto P_0c0b715c;
P_0c0b715a: /* original 65a2, guest PC 0x0c0b715a */
if(!s->budget--) { s->failed_pc=0x0c0b715au; return 0; }
tmp=read(ram,r[10],4);
r[5]=tmp;
goto P_0c0b715c;
P_0c0b715c: /* original 9478, guest PC 0x0c0b715c */
if(!s->budget--) { s->failed_pc=0x0c0b715cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b7250u,2);
goto P_0c0b715e;
P_0c0b715e: /* original 4e0b, guest PC 0x0c0b715e */
if(!s->budget--) { s->failed_pc=0x0c0b715eu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b7162u;
tmp=read(ram,r[10],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b7162u) { target=s->pc; goto dispatch; }
goto P_0c0b7162;
P_0c0b7160: /* original 65a2, guest PC 0x0c0b7160 */
if(!s->budget--) { s->failed_pc=0x0c0b7160u; return 0; }
tmp=read(ram,r[10],4);
r[5]=tmp;
goto P_0c0b7162;
P_0c0b7162: /* original 9476, guest PC 0x0c0b7162 */
if(!s->budget--) { s->failed_pc=0x0c0b7162u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b7252u,2);
goto P_0c0b7164;
P_0c0b7164: /* original 4e0b, guest PC 0x0c0b7164 */
if(!s->budget--) { s->failed_pc=0x0c0b7164u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b7168u;
tmp=read(ram,r[10],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b7168u) { target=s->pc; goto dispatch; }
goto P_0c0b7168;
P_0c0b7166: /* original 65a2, guest PC 0x0c0b7166 */
if(!s->budget--) { s->failed_pc=0x0c0b7166u; return 0; }
tmp=read(ram,r[10],4);
r[5]=tmp;
goto P_0c0b7168;
P_0c0b7168: /* original 9574, guest PC 0x0c0b7168 */
if(!s->budget--) { s->failed_pc=0x0c0b7168u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b7254u,2);
goto P_0c0b716a;
P_0c0b716a: /* original 35dc, guest PC 0x0c0b716a */
if(!s->budget--) { s->failed_pc=0x0c0b716au; return 0; }
r[5]+=r[13];
goto P_0c0b716c;
P_0c0b716c: /* original 2f52, guest PC 0x0c0b716c */
if(!s->budget--) { s->failed_pc=0x0c0b716cu; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0b716e;
P_0c0b716e: /* original 9472, guest PC 0x0c0b716e */
if(!s->budget--) { s->failed_pc=0x0c0b716eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b7256u,2);
goto P_0c0b7170;
P_0c0b7170: /* original 4e0b, guest PC 0x0c0b7170 */
if(!s->budget--) { s->failed_pc=0x0c0b7170u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b7174u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b7174u) { target=s->pc; goto dispatch; }
goto P_0c0b7174;
P_0c0b7172: /* original 6552, guest PC 0x0c0b7172 */
if(!s->budget--) { s->failed_pc=0x0c0b7172u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b7174;
P_0c0b7174: /* original 9470, guest PC 0x0c0b7174 */
if(!s->budget--) { s->failed_pc=0x0c0b7174u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b7258u,2);
goto P_0c0b7176;
P_0c0b7176: /* original 65f2, guest PC 0x0c0b7176 */
if(!s->budget--) { s->failed_pc=0x0c0b7176u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0b7178;
P_0c0b7178: /* original 4e0b, guest PC 0x0c0b7178 */
if(!s->budget--) { s->failed_pc=0x0c0b7178u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b717cu;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b717cu) { target=s->pc; goto dispatch; }
goto P_0c0b717c;
P_0c0b717a: /* original 6552, guest PC 0x0c0b717a */
if(!s->budget--) { s->failed_pc=0x0c0b717au; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b717c;
P_0c0b717c: /* original 956d, guest PC 0x0c0b717c */
if(!s->budget--) { s->failed_pc=0x0c0b717cu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b725au,2);
goto P_0c0b717e;
P_0c0b717e: /* original 35dc, guest PC 0x0c0b717e */
if(!s->budget--) { s->failed_pc=0x0c0b717eu; return 0; }
r[5]+=r[13];
goto P_0c0b7180;
P_0c0b7180: /* original 2f52, guest PC 0x0c0b7180 */
if(!s->budget--) { s->failed_pc=0x0c0b7180u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0b7182;
P_0c0b7182: /* original 946b, guest PC 0x0c0b7182 */
if(!s->budget--) { s->failed_pc=0x0c0b7182u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b725cu,2);
goto P_0c0b7184;
P_0c0b7184: /* original 4e0b, guest PC 0x0c0b7184 */
if(!s->budget--) { s->failed_pc=0x0c0b7184u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b7188u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b7188u) { target=s->pc; goto dispatch; }
goto P_0c0b7188;
P_0c0b7186: /* original 6552, guest PC 0x0c0b7186 */
if(!s->budget--) { s->failed_pc=0x0c0b7186u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b7188;
P_0c0b7188: /* original 9469, guest PC 0x0c0b7188 */
if(!s->budget--) { s->failed_pc=0x0c0b7188u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b725eu,2);
goto P_0c0b718a;
P_0c0b718a: /* original 65f2, guest PC 0x0c0b718a */
if(!s->budget--) { s->failed_pc=0x0c0b718au; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0b718c;
P_0c0b718c: /* original 4e0b, guest PC 0x0c0b718c */
if(!s->budget--) { s->failed_pc=0x0c0b718cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b7190u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b7190u) { target=s->pc; goto dispatch; }
goto P_0c0b7190;
P_0c0b718e: /* original 6552, guest PC 0x0c0b718e */
if(!s->budget--) { s->failed_pc=0x0c0b718eu; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b7190;
P_0c0b7190: /* original 9467, guest PC 0x0c0b7190 */
if(!s->budget--) { s->failed_pc=0x0c0b7190u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b7262u,2);
goto P_0c0b7192;
P_0c0b7192: /* original 9065, guest PC 0x0c0b7192 */
if(!s->budget--) { s->failed_pc=0x0c0b7192u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b7260u,2);
goto P_0c0b7194;
P_0c0b7194: /* original 4e0b, guest PC 0x0c0b7194 */
if(!s->budget--) { s->failed_pc=0x0c0b7194u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b7198u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b7198u) { target=s->pc; goto dispatch; }
goto P_0c0b7198;
P_0c0b7196: /* original 05de, guest PC 0x0c0b7196 */
if(!s->budget--) { s->failed_pc=0x0c0b7196u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b7198;
P_0c0b7198: /* original 9564, guest PC 0x0c0b7198 */
if(!s->budget--) { s->failed_pc=0x0c0b7198u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b7264u,2);
goto P_0c0b719a;
P_0c0b719a: /* original 35dc, guest PC 0x0c0b719a */
if(!s->budget--) { s->failed_pc=0x0c0b719au; return 0; }
r[5]+=r[13];
goto P_0c0b719c;
P_0c0b719c: /* original 2f52, guest PC 0x0c0b719c */
if(!s->budget--) { s->failed_pc=0x0c0b719cu; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0b719e;
P_0c0b719e: /* original 9462, guest PC 0x0c0b719e */
if(!s->budget--) { s->failed_pc=0x0c0b719eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b7266u,2);
goto P_0c0b71a0;
P_0c0b71a0: /* original 4e0b, guest PC 0x0c0b71a0 */
if(!s->budget--) { s->failed_pc=0x0c0b71a0u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b71a4u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b71a4u) { target=s->pc; goto dispatch; }
goto P_0c0b71a4;
P_0c0b71a2: /* original 6552, guest PC 0x0c0b71a2 */
if(!s->budget--) { s->failed_pc=0x0c0b71a2u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b71a4;
P_0c0b71a4: /* original 9460, guest PC 0x0c0b71a4 */
if(!s->budget--) { s->failed_pc=0x0c0b71a4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b7268u,2);
goto P_0c0b71a6;
P_0c0b71a6: /* original 65f2, guest PC 0x0c0b71a6 */
if(!s->budget--) { s->failed_pc=0x0c0b71a6u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0b71a8;
P_0c0b71a8: /* original 4e0b, guest PC 0x0c0b71a8 */
if(!s->budget--) { s->failed_pc=0x0c0b71a8u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b71acu;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b71acu) { target=s->pc; goto dispatch; }
goto P_0c0b71ac;
P_0c0b71aa: /* original 6552, guest PC 0x0c0b71aa */
if(!s->budget--) { s->failed_pc=0x0c0b71aau; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b71ac;
P_0c0b71ac: /* original 945e, guest PC 0x0c0b71ac */
if(!s->budget--) { s->failed_pc=0x0c0b71acu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b726cu,2);
goto P_0c0b71ae;
P_0c0b71ae: /* original 905c, guest PC 0x0c0b71ae */
if(!s->budget--) { s->failed_pc=0x0c0b71aeu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b726au,2);
goto P_0c0b71b0;
P_0c0b71b0: /* original 4e0b, guest PC 0x0c0b71b0 */
if(!s->budget--) { s->failed_pc=0x0c0b71b0u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b71b4u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b71b4u) { target=s->pc; goto dispatch; }
goto P_0c0b71b4;
P_0c0b71b2: /* original 05de, guest PC 0x0c0b71b2 */
if(!s->budget--) { s->failed_pc=0x0c0b71b2u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b71b4;
P_0c0b71b4: /* original 955b, guest PC 0x0c0b71b4 */
if(!s->budget--) { s->failed_pc=0x0c0b71b4u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b726eu,2);
goto P_0c0b71b6;
P_0c0b71b6: /* original 35dc, guest PC 0x0c0b71b6 */
if(!s->budget--) { s->failed_pc=0x0c0b71b6u; return 0; }
r[5]+=r[13];
goto P_0c0b71b8;
P_0c0b71b8: /* original 2f52, guest PC 0x0c0b71b8 */
if(!s->budget--) { s->failed_pc=0x0c0b71b8u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0b71ba;
P_0c0b71ba: /* original 9459, guest PC 0x0c0b71ba */
if(!s->budget--) { s->failed_pc=0x0c0b71bau; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b7270u,2);
goto P_0c0b71bc;
P_0c0b71bc: /* original 4e0b, guest PC 0x0c0b71bc */
if(!s->budget--) { s->failed_pc=0x0c0b71bcu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b71c0u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b71c0u) { target=s->pc; goto dispatch; }
goto P_0c0b71c0;
P_0c0b71be: /* original 6552, guest PC 0x0c0b71be */
if(!s->budget--) { s->failed_pc=0x0c0b71beu; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b71c0;
P_0c0b71c0: /* original 9457, guest PC 0x0c0b71c0 */
if(!s->budget--) { s->failed_pc=0x0c0b71c0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b7272u,2);
goto P_0c0b71c2;
P_0c0b71c2: /* original 65f2, guest PC 0x0c0b71c2 */
if(!s->budget--) { s->failed_pc=0x0c0b71c2u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0b71c4;
P_0c0b71c4: /* original 4e0b, guest PC 0x0c0b71c4 */
if(!s->budget--) { s->failed_pc=0x0c0b71c4u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b71c8u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b71c8u) { target=s->pc; goto dispatch; }
goto P_0c0b71c8;
P_0c0b71c6: /* original 6552, guest PC 0x0c0b71c6 */
if(!s->budget--) { s->failed_pc=0x0c0b71c6u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b71c8;
P_0c0b71c8: /* original 9455, guest PC 0x0c0b71c8 */
if(!s->budget--) { s->failed_pc=0x0c0b71c8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b7276u,2);
goto P_0c0b71ca;
P_0c0b71ca: /* original 9053, guest PC 0x0c0b71ca */
if(!s->budget--) { s->failed_pc=0x0c0b71cau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b7274u,2);
goto P_0c0b71cc;
P_0c0b71cc: /* original 4e0b, guest PC 0x0c0b71cc */
if(!s->budget--) { s->failed_pc=0x0c0b71ccu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b71d0u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b71d0u) { target=s->pc; goto dispatch; }
goto P_0c0b71d0;
P_0c0b71ce: /* original 05de, guest PC 0x0c0b71ce */
if(!s->budget--) { s->failed_pc=0x0c0b71ceu; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b71d0;
P_0c0b71d0: /* original 9552, guest PC 0x0c0b71d0 */
if(!s->budget--) { s->failed_pc=0x0c0b71d0u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b7278u,2);
goto P_0c0b71d2;
P_0c0b71d2: /* original 35dc, guest PC 0x0c0b71d2 */
if(!s->budget--) { s->failed_pc=0x0c0b71d2u; return 0; }
r[5]+=r[13];
goto P_0c0b71d4;
P_0c0b71d4: /* original 2f52, guest PC 0x0c0b71d4 */
if(!s->budget--) { s->failed_pc=0x0c0b71d4u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0b71d6;
P_0c0b71d6: /* original 9450, guest PC 0x0c0b71d6 */
if(!s->budget--) { s->failed_pc=0x0c0b71d6u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b727au,2);
goto P_0c0b71d8;
P_0c0b71d8: /* original 4e0b, guest PC 0x0c0b71d8 */
if(!s->budget--) { s->failed_pc=0x0c0b71d8u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b71dcu;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b71dcu) { target=s->pc; goto dispatch; }
goto P_0c0b71dc;
P_0c0b71da: /* original 6552, guest PC 0x0c0b71da */
if(!s->budget--) { s->failed_pc=0x0c0b71dau; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b71dc;
P_0c0b71dc: /* original 944e, guest PC 0x0c0b71dc */
if(!s->budget--) { s->failed_pc=0x0c0b71dcu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b727cu,2);
goto P_0c0b71de;
P_0c0b71de: /* original 65f2, guest PC 0x0c0b71de */
if(!s->budget--) { s->failed_pc=0x0c0b71deu; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0b71e0;
P_0c0b71e0: /* original 4e0b, guest PC 0x0c0b71e0 */
if(!s->budget--) { s->failed_pc=0x0c0b71e0u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b71e4u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b71e4u) { target=s->pc; goto dispatch; }
goto P_0c0b71e4;
P_0c0b71e2: /* original 6552, guest PC 0x0c0b71e2 */
if(!s->budget--) { s->failed_pc=0x0c0b71e2u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b71e4;
P_0c0b71e4: /* original 954b, guest PC 0x0c0b71e4 */
if(!s->budget--) { s->failed_pc=0x0c0b71e4u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b727eu,2);
goto P_0c0b71e6;
P_0c0b71e6: /* original 35dc, guest PC 0x0c0b71e6 */
if(!s->budget--) { s->failed_pc=0x0c0b71e6u; return 0; }
r[5]+=r[13];
goto P_0c0b71e8;
P_0c0b71e8: /* original 2f52, guest PC 0x0c0b71e8 */
if(!s->budget--) { s->failed_pc=0x0c0b71e8u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0b71ea;
P_0c0b71ea: /* original 9449, guest PC 0x0c0b71ea */
if(!s->budget--) { s->failed_pc=0x0c0b71eau; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b7280u,2);
goto P_0c0b71ec;
P_0c0b71ec: /* original 4e0b, guest PC 0x0c0b71ec */
if(!s->budget--) { s->failed_pc=0x0c0b71ecu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b71f0u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b71f0u) { target=s->pc; goto dispatch; }
goto P_0c0b71f0;
P_0c0b71ee: /* original 6552, guest PC 0x0c0b71ee */
if(!s->budget--) { s->failed_pc=0x0c0b71eeu; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b71f0;
P_0c0b71f0: /* original 9447, guest PC 0x0c0b71f0 */
if(!s->budget--) { s->failed_pc=0x0c0b71f0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b7282u,2);
goto P_0c0b71f2;
P_0c0b71f2: /* original 65f2, guest PC 0x0c0b71f2 */
if(!s->budget--) { s->failed_pc=0x0c0b71f2u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0b71f4;
P_0c0b71f4: /* original 4e0b, guest PC 0x0c0b71f4 */
if(!s->budget--) { s->failed_pc=0x0c0b71f4u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b71f8u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b71f8u) { target=s->pc; goto dispatch; }
goto P_0c0b71f8;
P_0c0b71f6: /* original 6552, guest PC 0x0c0b71f6 */
if(!s->budget--) { s->failed_pc=0x0c0b71f6u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b71f8;
P_0c0b71f8: /* original 9445, guest PC 0x0c0b71f8 */
if(!s->budget--) { s->failed_pc=0x0c0b71f8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b7286u,2);
goto P_0c0b71fa;
P_0c0b71fa: /* original 9043, guest PC 0x0c0b71fa */
if(!s->budget--) { s->failed_pc=0x0c0b71fau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b7284u,2);
goto P_0c0b71fc;
P_0c0b71fc: /* original 4e0b, guest PC 0x0c0b71fc */
if(!s->budget--) { s->failed_pc=0x0c0b71fcu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b7200u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b7200u) { target=s->pc; goto dispatch; }
goto P_0c0b7200;
P_0c0b71fe: /* original 05de, guest PC 0x0c0b71fe */
if(!s->budget--) { s->failed_pc=0x0c0b71feu; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b7200;
P_0c0b7200: /* original 9443, guest PC 0x0c0b7200 */
if(!s->budget--) { s->failed_pc=0x0c0b7200u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b728au,2);
goto P_0c0b7202;
P_0c0b7202: /* original 9041, guest PC 0x0c0b7202 */
if(!s->budget--) { s->failed_pc=0x0c0b7202u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b7288u,2);
goto P_0c0b7204;
P_0c0b7204: /* original 4e0b, guest PC 0x0c0b7204 */
if(!s->budget--) { s->failed_pc=0x0c0b7204u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b7208u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b7208u) { target=s->pc; goto dispatch; }
goto P_0c0b7208;
P_0c0b7206: /* original 05de, guest PC 0x0c0b7206 */
if(!s->budget--) { s->failed_pc=0x0c0b7206u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b7208;
P_0c0b7208: /* original 9441, guest PC 0x0c0b7208 */
if(!s->budget--) { s->failed_pc=0x0c0b7208u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b728eu,2);
goto P_0c0b720a;
P_0c0b720a: /* original 903f, guest PC 0x0c0b720a */
if(!s->budget--) { s->failed_pc=0x0c0b720au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b728cu,2);
goto P_0c0b720c;
P_0c0b720c: /* original 4e0b, guest PC 0x0c0b720c */
if(!s->budget--) { s->failed_pc=0x0c0b720cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b7210u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b7210u) { target=s->pc; goto dispatch; }
goto P_0c0b7210;
P_0c0b720e: /* original 05de, guest PC 0x0c0b720e */
if(!s->budget--) { s->failed_pc=0x0c0b720eu; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b7210;
P_0c0b7210: /* original 943f, guest PC 0x0c0b7210 */
if(!s->budget--) { s->failed_pc=0x0c0b7210u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b7292u,2);
goto P_0c0b7212;
P_0c0b7212: /* original 903d, guest PC 0x0c0b7212 */
if(!s->budget--) { s->failed_pc=0x0c0b7212u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b7290u,2);
goto P_0c0b7214;
P_0c0b7214: /* original 4e0b, guest PC 0x0c0b7214 */
if(!s->budget--) { s->failed_pc=0x0c0b7214u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b7218u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b7218u) { target=s->pc; goto dispatch; }
goto P_0c0b7218;
P_0c0b7216: /* original 05de, guest PC 0x0c0b7216 */
if(!s->budget--) { s->failed_pc=0x0c0b7216u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b7218;
P_0c0b7218: /* original 903c, guest PC 0x0c0b7218 */
if(!s->budget--) { s->failed_pc=0x0c0b7218u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b7294u,2);
goto P_0c0b721a;
P_0c0b721a: /* original a03c, guest PC 0x0c0b721a */
if(!s->budget--) { s->failed_pc=0x0c0b721au; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b7296;
P_0c0b721c: /* original 05de, guest PC 0x0c0b721c */
if(!s->budget--) { s->failed_pc=0x0c0b721cu; return 0; }
r[5]=read(ram,r[13]+r[0],4);
if(!vf3_matrix_family(0x0c0b721eu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0b721eu; return 0; } return 1;
P_0c0b7296: /* original 942a, guest PC 0x0c0b7296 */
if(!s->budget--) { s->failed_pc=0x0c0b7296u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b72eeu,2);
goto P_0c0b7298;
P_0c0b7298: /* original 4e0b, guest PC 0x0c0b7298 */
if(!s->budget--) { s->failed_pc=0x0c0b7298u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b729cu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b729cu) { target=s->pc; goto dispatch; }
goto P_0c0b729c;
P_0c0b729a: /* original 0009, guest PC 0x0c0b729a */
if(!s->budget--) { s->failed_pc=0x0c0b729au; return 0; }
goto P_0c0b729c;
P_0c0b729c: /* original 9429, guest PC 0x0c0b729c */
if(!s->budget--) { s->failed_pc=0x0c0b729cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b72f2u,2);
goto P_0c0b729e;
P_0c0b729e: /* original 9027, guest PC 0x0c0b729e */
if(!s->budget--) { s->failed_pc=0x0c0b729eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b72f0u,2);
goto P_0c0b72a0;
P_0c0b72a0: /* original 4e0b, guest PC 0x0c0b72a0 */
if(!s->budget--) { s->failed_pc=0x0c0b72a0u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b72a4u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b72a4u) { target=s->pc; goto dispatch; }
goto P_0c0b72a4;
P_0c0b72a2: /* original 05de, guest PC 0x0c0b72a2 */
if(!s->budget--) { s->failed_pc=0x0c0b72a2u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b72a4;
P_0c0b72a4: /* original 9427, guest PC 0x0c0b72a4 */
if(!s->budget--) { s->failed_pc=0x0c0b72a4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b72f6u,2);
goto P_0c0b72a6;
P_0c0b72a6: /* original 9025, guest PC 0x0c0b72a6 */
if(!s->budget--) { s->failed_pc=0x0c0b72a6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b72f4u,2);
goto P_0c0b72a8;
P_0c0b72a8: /* original 4e0b, guest PC 0x0c0b72a8 */
if(!s->budget--) { s->failed_pc=0x0c0b72a8u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b72acu;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b72acu) { target=s->pc; goto dispatch; }
goto P_0c0b72ac;
P_0c0b72aa: /* original 05de, guest PC 0x0c0b72aa */
if(!s->budget--) { s->failed_pc=0x0c0b72aau; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b72ac;
P_0c0b72ac: /* original 9425, guest PC 0x0c0b72ac */
if(!s->budget--) { s->failed_pc=0x0c0b72acu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b72fau,2);
goto P_0c0b72ae;
P_0c0b72ae: /* original 9023, guest PC 0x0c0b72ae */
if(!s->budget--) { s->failed_pc=0x0c0b72aeu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b72f8u,2);
goto P_0c0b72b0;
P_0c0b72b0: /* original 4e0b, guest PC 0x0c0b72b0 */
if(!s->budget--) { s->failed_pc=0x0c0b72b0u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b72b4u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b72b4u) { target=s->pc; goto dispatch; }
goto P_0c0b72b4;
P_0c0b72b2: /* original 05de, guest PC 0x0c0b72b2 */
if(!s->budget--) { s->failed_pc=0x0c0b72b2u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b72b4;
P_0c0b72b4: /* original 9423, guest PC 0x0c0b72b4 */
if(!s->budget--) { s->failed_pc=0x0c0b72b4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b72feu,2);
goto P_0c0b72b6;
P_0c0b72b6: /* original 9021, guest PC 0x0c0b72b6 */
if(!s->budget--) { s->failed_pc=0x0c0b72b6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b72fcu,2);
goto P_0c0b72b8;
P_0c0b72b8: /* original 4e0b, guest PC 0x0c0b72b8 */
if(!s->budget--) { s->failed_pc=0x0c0b72b8u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b72bcu;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b72bcu) { target=s->pc; goto dispatch; }
goto P_0c0b72bc;
P_0c0b72ba: /* original 05de, guest PC 0x0c0b72ba */
if(!s->budget--) { s->failed_pc=0x0c0b72bau; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b72bc;
P_0c0b72bc: /* original 9421, guest PC 0x0c0b72bc */
if(!s->budget--) { s->failed_pc=0x0c0b72bcu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b7302u,2);
goto P_0c0b72be;
P_0c0b72be: /* original 901f, guest PC 0x0c0b72be */
if(!s->budget--) { s->failed_pc=0x0c0b72beu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b7300u,2);
goto P_0c0b72c0;
P_0c0b72c0: /* original 4e0b, guest PC 0x0c0b72c0 */
if(!s->budget--) { s->failed_pc=0x0c0b72c0u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b72c4u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b72c4u) { target=s->pc; goto dispatch; }
goto P_0c0b72c4;
P_0c0b72c2: /* original 05de, guest PC 0x0c0b72c2 */
if(!s->budget--) { s->failed_pc=0x0c0b72c2u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b72c4;
P_0c0b72c4: /* original 941f, guest PC 0x0c0b72c4 */
if(!s->budget--) { s->failed_pc=0x0c0b72c4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b7306u,2);
goto P_0c0b72c6;
P_0c0b72c6: /* original 901d, guest PC 0x0c0b72c6 */
if(!s->budget--) { s->failed_pc=0x0c0b72c6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b7304u,2);
goto P_0c0b72c8;
P_0c0b72c8: /* original 4e0b, guest PC 0x0c0b72c8 */
if(!s->budget--) { s->failed_pc=0x0c0b72c8u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b72ccu;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b72ccu) { target=s->pc; goto dispatch; }
goto P_0c0b72cc;
P_0c0b72ca: /* original 05de, guest PC 0x0c0b72ca */
if(!s->budget--) { s->failed_pc=0x0c0b72cau; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b72cc;
P_0c0b72cc: /* original 941d, guest PC 0x0c0b72cc */
if(!s->budget--) { s->failed_pc=0x0c0b72ccu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b730au,2);
goto P_0c0b72ce;
P_0c0b72ce: /* original 901b, guest PC 0x0c0b72ce */
if(!s->budget--) { s->failed_pc=0x0c0b72ceu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b7308u,2);
goto P_0c0b72d0;
P_0c0b72d0: /* original 4e0b, guest PC 0x0c0b72d0 */
if(!s->budget--) { s->failed_pc=0x0c0b72d0u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b72d4u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b72d4u) { target=s->pc; goto dispatch; }
goto P_0c0b72d4;
P_0c0b72d2: /* original 05de, guest PC 0x0c0b72d2 */
if(!s->budget--) { s->failed_pc=0x0c0b72d2u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b72d4;
P_0c0b72d4: /* original 941b, guest PC 0x0c0b72d4 */
if(!s->budget--) { s->failed_pc=0x0c0b72d4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b730eu,2);
goto P_0c0b72d6;
P_0c0b72d6: /* original 9019, guest PC 0x0c0b72d6 */
if(!s->budget--) { s->failed_pc=0x0c0b72d6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b730cu,2);
goto P_0c0b72d8;
P_0c0b72d8: /* original 4e0b, guest PC 0x0c0b72d8 */
if(!s->budget--) { s->failed_pc=0x0c0b72d8u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b72dcu;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b72dcu) { target=s->pc; goto dispatch; }
goto P_0c0b72dc;
P_0c0b72da: /* original 05de, guest PC 0x0c0b72da */
if(!s->budget--) { s->failed_pc=0x0c0b72dau; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b72dc;
P_0c0b72dc: /* original 7f08, guest PC 0x0c0b72dc */
if(!s->budget--) { s->failed_pc=0x0c0b72dcu; return 0; }
r[15]+=0x00000008u;
goto P_0c0b72de;
P_0c0b72de: /* original 4f26, guest PC 0x0c0b72de */
if(!s->budget--) { s->failed_pc=0x0c0b72deu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0b72e0;
P_0c0b72e0: /* original 69f6, guest PC 0x0c0b72e0 */
if(!s->budget--) { s->failed_pc=0x0c0b72e0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0b72e2;
P_0c0b72e2: /* original 6af6, guest PC 0x0c0b72e2 */
if(!s->budget--) { s->failed_pc=0x0c0b72e2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0b72e4;
P_0c0b72e4: /* original 6bf6, guest PC 0x0c0b72e4 */
if(!s->budget--) { s->failed_pc=0x0c0b72e4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0b72e6;
P_0c0b72e6: /* original 6cf6, guest PC 0x0c0b72e6 */
if(!s->budget--) { s->failed_pc=0x0c0b72e6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0b72e8;
P_0c0b72e8: /* original 6df6, guest PC 0x0c0b72e8 */
if(!s->budget--) { s->failed_pc=0x0c0b72e8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0b72ea;
P_0c0b72ea: /* original 000b, guest PC 0x0c0b72ea */
if(!s->budget--) { s->failed_pc=0x0c0b72eau; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0b72ec: /* original 6ef6, guest PC 0x0c0b72ec */
if(!s->budget--) { s->failed_pc=0x0c0b72ecu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0b72eeu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0b72eeu; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
