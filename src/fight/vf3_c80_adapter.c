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
int vf3_c80_adapter(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u;
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c046e66u: goto P_0c046e66;
case 0x0c046e68u: goto P_0c046e68;
case 0x0c046e6au: goto P_0c046e6a;
case 0x0c046e6cu: goto P_0c046e6c;
case 0x0c046e6eu: goto P_0c046e6e;
case 0x0c046e70u: goto P_0c046e70;
case 0x0c046e72u: goto P_0c046e72;
case 0x0c046e74u: goto P_0c046e74;
case 0x0c046e76u: goto P_0c046e76;
case 0x0c046e78u: goto P_0c046e78;
case 0x0c046e7au: goto P_0c046e7a;
case 0x0c046e7cu: goto P_0c046e7c;
case 0x0c046e7eu: goto P_0c046e7e;
case 0x0c046e80u: goto P_0c046e80;
case 0x0c046e82u: goto P_0c046e82;
case 0x0c046e84u: goto P_0c046e84;
case 0x0c046e86u: goto P_0c046e86;
case 0x0c046e88u: goto P_0c046e88;
case 0x0c046e8au: goto P_0c046e8a;
case 0x0c046e8cu: goto P_0c046e8c;
case 0x0c046e8eu: goto P_0c046e8e;
case 0x0c046e90u: goto P_0c046e90;
case 0x0c046e92u: goto P_0c046e92;
case 0x0c046e94u: goto P_0c046e94;
case 0x0c046e96u: goto P_0c046e96;
case 0x0c046e98u: goto P_0c046e98;
case 0x0c046e9au: goto P_0c046e9a;
case 0x0c046e9cu: goto P_0c046e9c;
case 0x0c046e9eu: goto P_0c046e9e;
case 0x0c046ea0u: goto P_0c046ea0;
case 0x0c046ea2u: goto P_0c046ea2;
case 0x0c046ea4u: goto P_0c046ea4;
case 0x0c046ea6u: goto P_0c046ea6;
case 0x0c046ea8u: goto P_0c046ea8;
case 0x0c046eaau: goto P_0c046eaa;
case 0x0c046eaeu: goto P_0c046eae;
case 0x0c046eb0u: goto P_0c046eb0;
case 0x0c046eb2u: goto P_0c046eb2;
case 0x0c046eb4u: goto P_0c046eb4;
case 0x0c046eb6u: goto P_0c046eb6;
case 0x0c046eb8u: goto P_0c046eb8;
case 0x0c046ebau: goto P_0c046eba;
case 0x0c046ebcu: goto P_0c046ebc;
case 0x0c046ebeu: goto P_0c046ebe;
case 0x0c046ec0u: goto P_0c046ec0;
case 0x0c046ec2u: goto P_0c046ec2;
case 0x0c046ec4u: goto P_0c046ec4;
case 0x0c046ec6u: goto P_0c046ec6;
case 0x0c046ec8u: goto P_0c046ec8;
case 0x0c046ecau: goto P_0c046eca;
case 0x0c046eccu: goto P_0c046ecc;
case 0x0c046eceu: goto P_0c046ece;
case 0x0c046ed0u: goto P_0c046ed0;
case 0x0c046ed2u: goto P_0c046ed2;
case 0x0c046ed4u: goto P_0c046ed4;
case 0x0c046ed6u: goto P_0c046ed6;
case 0x0c046ed8u: goto P_0c046ed8;
case 0x0c046edau: goto P_0c046eda;
case 0x0c046edcu: goto P_0c046edc;
case 0x0c046edeu: goto P_0c046ede;
case 0x0c046ee0u: goto P_0c046ee0;
case 0x0c046ee2u: goto P_0c046ee2;
case 0x0c046ee4u: goto P_0c046ee4;
case 0x0c046ee6u: goto P_0c046ee6;
case 0x0c046ee8u: goto P_0c046ee8;
case 0x0c046eeau: goto P_0c046eea;
case 0x0c046eecu: goto P_0c046eec;
case 0x0c046eeeu: goto P_0c046eee;
case 0x0c046ef0u: goto P_0c046ef0;
case 0x0c046ef2u: goto P_0c046ef2;
case 0x0c046ef4u: goto P_0c046ef4;
case 0x0c046ef6u: goto P_0c046ef6;
case 0x0c046ef8u: goto P_0c046ef8;
case 0x0c046efau: goto P_0c046efa;
case 0x0c046efcu: goto P_0c046efc;
case 0x0c046efeu: goto P_0c046efe;
case 0x0c046f00u: goto P_0c046f00;
case 0x0c046f02u: goto P_0c046f02;
case 0x0c046f04u: goto P_0c046f04;
case 0x0c046f06u: goto P_0c046f06;
case 0x0c046f08u: goto P_0c046f08;
case 0x0c046f0au: goto P_0c046f0a;
case 0x0c046f0cu: goto P_0c046f0c;
case 0x0c046f0eu: goto P_0c046f0e;
case 0x0c046f10u: goto P_0c046f10;
case 0x0c046f12u: goto P_0c046f12;
case 0x0c046f14u: goto P_0c046f14;
case 0x0c046f16u: goto P_0c046f16;
case 0x0c046f18u: goto P_0c046f18;
case 0x0c046f1au: goto P_0c046f1a;
case 0x0c046f1cu: goto P_0c046f1c;
case 0x0c046f1eu: goto P_0c046f1e;
case 0x0c046f20u: goto P_0c046f20;
case 0x0c046f22u: goto P_0c046f22;
case 0x0c046f24u: goto P_0c046f24;
case 0x0c046f26u: goto P_0c046f26;
case 0x0c046f28u: goto P_0c046f28;
case 0x0c046f2au: goto P_0c046f2a;
case 0x0c046f2cu: goto P_0c046f2c;
case 0x0c046f2eu: goto P_0c046f2e;
case 0x0c046f30u: goto P_0c046f30;
case 0x0c046f32u: goto P_0c046f32;
case 0x0c046f34u: goto P_0c046f34;
case 0x0c046f36u: goto P_0c046f36;
case 0x0c046f38u: goto P_0c046f38;
case 0x0c046f3au: goto P_0c046f3a;
case 0x0c046f3cu: goto P_0c046f3c;
case 0x0c046f3eu: goto P_0c046f3e;
case 0x0c046f40u: goto P_0c046f40;
case 0x0c046f42u: goto P_0c046f42;
case 0x0c046f44u: goto P_0c046f44;
case 0x0c046f46u: goto P_0c046f46;
case 0x0c046f48u: goto P_0c046f48;
case 0x0c046f4au: goto P_0c046f4a;
case 0x0c046f4cu: goto P_0c046f4c;
case 0x0c046f4eu: goto P_0c046f4e;
case 0x0c046f50u: goto P_0c046f50;
case 0x0c046f52u: goto P_0c046f52;
case 0x0c046f54u: goto P_0c046f54;
case 0x0c046f56u: goto P_0c046f56;
case 0x0c046f58u: goto P_0c046f58;
case 0x0c046f5au: goto P_0c046f5a;
case 0x0c046f5cu: goto P_0c046f5c;
case 0x0c046f5eu: goto P_0c046f5e;
case 0x0c046f60u: goto P_0c046f60;
case 0x0c046f62u: goto P_0c046f62;
case 0x0c046f64u: goto P_0c046f64;
case 0x0c046f66u: goto P_0c046f66;
case 0x0c046f68u: goto P_0c046f68;
case 0x0c046f6au: goto P_0c046f6a;
case 0x0c046f6cu: goto P_0c046f6c;
case 0x0c046f6eu: goto P_0c046f6e;
case 0x0c046f70u: goto P_0c046f70;
case 0x0c046f72u: goto P_0c046f72;
case 0x0c046f74u: goto P_0c046f74;
case 0x0c046f76u: goto P_0c046f76;
case 0x0c046f78u: goto P_0c046f78;
case 0x0c046f7au: goto P_0c046f7a;
case 0x0c046f7cu: goto P_0c046f7c;
case 0x0c046f7eu: goto P_0c046f7e;
case 0x0c046f80u: goto P_0c046f80;
case 0x0c046f82u: goto P_0c046f82;
case 0x0c046f84u: goto P_0c046f84;
case 0x0c046f86u: goto P_0c046f86;
case 0x0c046f88u: goto P_0c046f88;
case 0x0c046f8au: goto P_0c046f8a;
case 0x0c046f8cu: goto P_0c046f8c;
case 0x0c046f8eu: goto P_0c046f8e;
case 0x0c046f90u: goto P_0c046f90;
case 0x0c046f92u: goto P_0c046f92;
case 0x0c046f94u: goto P_0c046f94;
case 0x0c046f96u: goto P_0c046f96;
case 0x0c046f98u: goto P_0c046f98;
case 0x0c046f9au: goto P_0c046f9a;
case 0x0c046f9cu: goto P_0c046f9c;
case 0x0c046f9eu: goto P_0c046f9e;
case 0x0c046fa0u: goto P_0c046fa0;
case 0x0c046fa2u: goto P_0c046fa2;
case 0x0c046fa4u: goto P_0c046fa4;
case 0x0c046fb4u: goto P_0c046fb4;
case 0x0c046fb6u: goto P_0c046fb6;
case 0x0c046fb8u: goto P_0c046fb8;
case 0x0c046fbau: goto P_0c046fba;
case 0x0c046fbcu: goto P_0c046fbc;
case 0x0c046fbeu: goto P_0c046fbe;
case 0x0c046fc0u: goto P_0c046fc0;
case 0x0c046fc2u: goto P_0c046fc2;
case 0x0c046fc4u: goto P_0c046fc4;
case 0x0c046fc6u: goto P_0c046fc6;
case 0x0c046fc8u: goto P_0c046fc8;
case 0x0c046fcau: goto P_0c046fca;
case 0x0c046fccu: goto P_0c046fcc;
case 0x0c046fceu: goto P_0c046fce;
case 0x0c046fd0u: goto P_0c046fd0;
case 0x0c046fd2u: goto P_0c046fd2;
case 0x0c046fd4u: goto P_0c046fd4;
case 0x0c046fd6u: goto P_0c046fd6;
case 0x0c046fd8u: goto P_0c046fd8;
case 0x0c046fdau: goto P_0c046fda;
case 0x0c046fdcu: goto P_0c046fdc;
case 0x0c046fdeu: goto P_0c046fde;
case 0x0c046fe0u: goto P_0c046fe0;
case 0x0c046fe2u: goto P_0c046fe2;
case 0x0c046fe4u: goto P_0c046fe4;
case 0x0c046fe6u: goto P_0c046fe6;
case 0x0c046fe8u: goto P_0c046fe8;
case 0x0c046feau: goto P_0c046fea;
case 0x0c046fecu: goto P_0c046fec;
case 0x0c046feeu: goto P_0c046fee;
case 0x0c046ff0u: goto P_0c046ff0;
case 0x0c046ff2u: goto P_0c046ff2;
case 0x0c046ff4u: goto P_0c046ff4;
case 0x0c046ff6u: goto P_0c046ff6;
case 0x0c046ff8u: goto P_0c046ff8;
case 0x0c046ffau: goto P_0c046ffa;
case 0x0c046ffcu: goto P_0c046ffc;
case 0x0c046ffeu: goto P_0c046ffe;
case 0x0c047000u: goto P_0c047000;
case 0x0c047002u: goto P_0c047002;
case 0x0c047004u: goto P_0c047004;
case 0x0c047006u: goto P_0c047006;
case 0x0c047008u: goto P_0c047008;
case 0x0c04700au: goto P_0c04700a;
case 0x0c04700cu: goto P_0c04700c;
case 0x0c04700eu: goto P_0c04700e;
case 0x0c047010u: goto P_0c047010;
case 0x0c047012u: goto P_0c047012;
case 0x0c047014u: goto P_0c047014;
case 0x0c047016u: goto P_0c047016;
case 0x0c047018u: goto P_0c047018;
case 0x0c04701au: goto P_0c04701a;
case 0x0c04701cu: goto P_0c04701c;
case 0x0c04701eu: goto P_0c04701e;
case 0x0c047020u: goto P_0c047020;
case 0x0c047022u: goto P_0c047022;
case 0x0c047024u: goto P_0c047024;
case 0x0c047026u: goto P_0c047026;
case 0x0c047028u: goto P_0c047028;
case 0x0c04702au: goto P_0c04702a;
case 0x0c04702cu: goto P_0c04702c;
case 0x0c04702eu: goto P_0c04702e;
case 0x0c047030u: goto P_0c047030;
case 0x0c047032u: goto P_0c047032;
case 0x0c047034u: goto P_0c047034;
case 0x0c047036u: goto P_0c047036;
case 0x0c047038u: goto P_0c047038;
case 0x0c04703au: goto P_0c04703a;
case 0x0c04703cu: goto P_0c04703c;
case 0x0c04703eu: goto P_0c04703e;
case 0x0c047040u: goto P_0c047040;
case 0x0c047042u: goto P_0c047042;
case 0x0c047044u: goto P_0c047044;
case 0x0c047046u: goto P_0c047046;
case 0x0c047048u: goto P_0c047048;
case 0x0c04704au: goto P_0c04704a;
case 0x0c0471d8u: goto P_0c0471d8;
case 0x0c0471dau: goto P_0c0471da;
case 0x0c0471dcu: goto P_0c0471dc;
case 0x0c0471deu: goto P_0c0471de;
case 0x0c0471e0u: goto P_0c0471e0;
case 0x0c0471e2u: goto P_0c0471e2;
case 0x0c0471e4u: goto P_0c0471e4;
case 0x0c0471e6u: goto P_0c0471e6;
case 0x0c0471e8u: goto P_0c0471e8;
case 0x0c0471eau: goto P_0c0471ea;
case 0x0c0471ecu: goto P_0c0471ec;
case 0x0c0471eeu: goto P_0c0471ee;
case 0x0c0471f0u: goto P_0c0471f0;
case 0x0c0471f2u: goto P_0c0471f2;
case 0x0c0471f4u: goto P_0c0471f4;
case 0x0c0471f6u: goto P_0c0471f6;
case 0x0c0471f8u: goto P_0c0471f8;
case 0x0c0471fau: goto P_0c0471fa;
case 0x0c0471fcu: goto P_0c0471fc;
case 0x0c0471feu: goto P_0c0471fe;
case 0x0c047200u: goto P_0c047200;
case 0x0c047202u: goto P_0c047202;
case 0x0c047204u: goto P_0c047204;
case 0x0c047218u: goto P_0c047218;
case 0x0c04721au: goto P_0c04721a;
case 0x0c04721cu: goto P_0c04721c;
case 0x0c04721eu: goto P_0c04721e;
case 0x0c047220u: goto P_0c047220;
case 0x0c047222u: goto P_0c047222;
case 0x0c047224u: goto P_0c047224;
case 0x0c047226u: goto P_0c047226;
case 0x0c047228u: goto P_0c047228;
case 0x0c04722au: goto P_0c04722a;
case 0x0c04722cu: goto P_0c04722c;
case 0x0c0491a4u: goto P_0c0491a4;
case 0x0c0491a6u: goto P_0c0491a6;
case 0x0c0491a8u: goto P_0c0491a8;
case 0x0c0491aau: goto P_0c0491aa;
case 0x0c0491acu: goto P_0c0491ac;
case 0x0c0491aeu: goto P_0c0491ae;
case 0x0c0491b0u: goto P_0c0491b0;
case 0x0c0491b2u: goto P_0c0491b2;
case 0x0c0491b4u: goto P_0c0491b4;
case 0x0c0491b6u: goto P_0c0491b6;
case 0x0c0491b8u: goto P_0c0491b8;
case 0x0c0491bau: goto P_0c0491ba;
case 0x0c0491bcu: goto P_0c0491bc;
case 0x0c0491beu: goto P_0c0491be;
case 0x0c0491c0u: goto P_0c0491c0;
case 0x0c0491c2u: goto P_0c0491c2;
case 0x0c0491c4u: goto P_0c0491c4;
case 0x0c0491c6u: goto P_0c0491c6;
case 0x0c0491c8u: goto P_0c0491c8;
case 0x0c0491cau: goto P_0c0491ca;
case 0x0c0491ccu: goto P_0c0491cc;
case 0x0c0491ceu: goto P_0c0491ce;
case 0x0c0491d0u: goto P_0c0491d0;
case 0x0c0491d2u: goto P_0c0491d2;
case 0x0c0491d4u: goto P_0c0491d4;
case 0x0c0491d6u: goto P_0c0491d6;
case 0x0c0491d8u: goto P_0c0491d8;
case 0x0c0491dau: goto P_0c0491da;
case 0x0c0491dcu: goto P_0c0491dc;
case 0x0c0491deu: goto P_0c0491de;
case 0x0c0491e0u: goto P_0c0491e0;
case 0x0c0491e2u: goto P_0c0491e2;
case 0x0c0491e4u: goto P_0c0491e4;
case 0x0c0491e6u: goto P_0c0491e6;
case 0x0c0491e8u: goto P_0c0491e8;
case 0x0c0491eau: goto P_0c0491ea;
case 0x0c0491ecu: goto P_0c0491ec;
case 0x0c0491eeu: goto P_0c0491ee;
case 0x0c0491f0u: goto P_0c0491f0;
case 0x0c0491f2u: goto P_0c0491f2;
case 0x0c0491f4u: goto P_0c0491f4;
case 0x0c0491f6u: goto P_0c0491f6;
case 0x0c0491f8u: goto P_0c0491f8;
case 0x0c0491fau: goto P_0c0491fa;
case 0x0c0491fcu: goto P_0c0491fc;
case 0x0c0491feu: goto P_0c0491fe;
case 0x0c049200u: goto P_0c049200;
case 0x0c049202u: goto P_0c049202;
case 0x0c049204u: goto P_0c049204;
case 0x0c049206u: goto P_0c049206;
case 0x0c049208u: goto P_0c049208;
case 0x0c04920au: goto P_0c04920a;
case 0x0c04920cu: goto P_0c04920c;
case 0x0c04920eu: goto P_0c04920e;
case 0x0c049210u: goto P_0c049210;
case 0x0c049212u: goto P_0c049212;
case 0x0c049214u: goto P_0c049214;
case 0x0c049216u: goto P_0c049216;
case 0x0c049218u: goto P_0c049218;
case 0x0c04921au: goto P_0c04921a;
case 0x0c04921cu: goto P_0c04921c;
case 0x0c04921eu: goto P_0c04921e;
case 0x0c049220u: goto P_0c049220;
case 0x0c049222u: goto P_0c049222;
case 0x0c049224u: goto P_0c049224;
case 0x0c049226u: goto P_0c049226;
case 0x0c049228u: goto P_0c049228;
case 0x0c04922au: goto P_0c04922a;
case 0x0c04922cu: goto P_0c04922c;
case 0x0c04922eu: goto P_0c04922e;
case 0x0c049230u: goto P_0c049230;
case 0x0c049232u: goto P_0c049232;
case 0x0c049234u: goto P_0c049234;
case 0x0c049236u: goto P_0c049236;
case 0x0c049238u: goto P_0c049238;
case 0x0c04923au: goto P_0c04923a;
case 0x0c04923cu: goto P_0c04923c;
case 0x0c04923eu: goto P_0c04923e;
case 0x0c049240u: goto P_0c049240;
case 0x0c049242u: goto P_0c049242;
case 0x0c049244u: goto P_0c049244;
case 0x0c049246u: goto P_0c049246;
case 0x0c049248u: goto P_0c049248;
case 0x0c04924au: goto P_0c04924a;
case 0x0c04924cu: goto P_0c04924c;
case 0x0c04924eu: goto P_0c04924e;
case 0x0c049250u: goto P_0c049250;
case 0x0c049252u: goto P_0c049252;
case 0x0c049254u: goto P_0c049254;
case 0x0c049256u: goto P_0c049256;
case 0x0c049258u: goto P_0c049258;
case 0x0c04925au: goto P_0c04925a;
case 0x0c04925cu: goto P_0c04925c;
case 0x0c04925eu: goto P_0c04925e;
case 0x0c049260u: goto P_0c049260;
case 0x0c049262u: goto P_0c049262;
case 0x0c049264u: goto P_0c049264;
case 0x0c049266u: goto P_0c049266;
case 0x0c049268u: goto P_0c049268;
case 0x0c04926au: goto P_0c04926a;
case 0x0c04926cu: goto P_0c04926c;
case 0x0c04926eu: goto P_0c04926e;
case 0x0c049270u: goto P_0c049270;
case 0x0c049272u: goto P_0c049272;
case 0x0c049274u: goto P_0c049274;
case 0x0c049276u: goto P_0c049276;
case 0x0c049278u: goto P_0c049278;
case 0x0c04927au: goto P_0c04927a;
case 0x0c04927cu: goto P_0c04927c;
case 0x0c04927eu: goto P_0c04927e;
case 0x0c049280u: goto P_0c049280;
case 0x0c049282u: goto P_0c049282;
case 0x0c049284u: goto P_0c049284;
case 0x0c049286u: goto P_0c049286;
case 0x0c049288u: goto P_0c049288;
case 0x0c04928au: goto P_0c04928a;
case 0x0c04928cu: goto P_0c04928c;
case 0x0c04928eu: goto P_0c04928e;
case 0x0c049290u: goto P_0c049290;
case 0x0c049292u: goto P_0c049292;
case 0x0c049294u: goto P_0c049294;
case 0x0c049296u: goto P_0c049296;
case 0x0c049298u: goto P_0c049298;
case 0x0c04929au: goto P_0c04929a;
case 0x0c04929cu: goto P_0c04929c;
case 0x0c04929eu: goto P_0c04929e;
case 0x0c0492a0u: goto P_0c0492a0;
case 0x0c0492beu: goto P_0c0492be;
case 0x0c0492c0u: goto P_0c0492c0;
case 0x0c0492c2u: goto P_0c0492c2;
case 0x0c0492c4u: goto P_0c0492c4;
case 0x0c0492c6u: goto P_0c0492c6;
case 0x0c0492c8u: goto P_0c0492c8;
case 0x0c0492cau: goto P_0c0492ca;
case 0x0c0492ccu: goto P_0c0492cc;
case 0x0c0492ceu: goto P_0c0492ce;
case 0x0c0492d0u: goto P_0c0492d0;
case 0x0c0492d2u: goto P_0c0492d2;
case 0x0c0492d4u: goto P_0c0492d4;
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
case 0x0c04c9aeu: goto P_0c04c9ae;
case 0x0c04c9b0u: goto P_0c04c9b0;
case 0x0c04c9b2u: goto P_0c04c9b2;
case 0x0c04c9b4u: goto P_0c04c9b4;
case 0x0c04c9b6u: goto P_0c04c9b6;
case 0x0c04c9b8u: goto P_0c04c9b8;
case 0x0c04c9bau: goto P_0c04c9ba;
case 0x0c04c9bcu: goto P_0c04c9bc;
case 0x0c04c9beu: goto P_0c04c9be;
case 0x0c04c9c0u: goto P_0c04c9c0;
case 0x0c04c9c2u: goto P_0c04c9c2;
case 0x0c04c9c4u: goto P_0c04c9c4;
case 0x0c04c9c6u: goto P_0c04c9c6;
case 0x0c04c9c8u: goto P_0c04c9c8;
case 0x0c04c9cau: goto P_0c04c9ca;
case 0x0c04c9ccu: goto P_0c04c9cc;
case 0x0c04c9ceu: goto P_0c04c9ce;
case 0x0c04c9d0u: goto P_0c04c9d0;
case 0x0c04c9d2u: goto P_0c04c9d2;
case 0x0c04c9d4u: goto P_0c04c9d4;
case 0x0c04c9d6u: goto P_0c04c9d6;
case 0x0c04c9d8u: goto P_0c04c9d8;
case 0x0c04c9dau: goto P_0c04c9da;
case 0x0c04c9dcu: goto P_0c04c9dc;
case 0x0c04c9deu: goto P_0c04c9de;
case 0x0c04c9e0u: goto P_0c04c9e0;
case 0x0c04c9e2u: goto P_0c04c9e2;
case 0x0c04c9e4u: goto P_0c04c9e4;
case 0x0c04c9e6u: goto P_0c04c9e6;
case 0x0c04c9e8u: goto P_0c04c9e8;
case 0x0c04c9eau: goto P_0c04c9ea;
case 0x0c04c9ecu: goto P_0c04c9ec;
case 0x0c04c9eeu: goto P_0c04c9ee;
case 0x0c04c9f0u: goto P_0c04c9f0;
case 0x0c04c9f2u: goto P_0c04c9f2;
case 0x0c04c9f4u: goto P_0c04c9f4;
case 0x0c04c9f6u: goto P_0c04c9f6;
case 0x0c04c9f8u: goto P_0c04c9f8;
case 0x0c04c9fau: goto P_0c04c9fa;
case 0x0c04c9fcu: goto P_0c04c9fc;
case 0x0c04c9feu: goto P_0c04c9fe;
case 0x0c04ca00u: goto P_0c04ca00;
case 0x0c04ca02u: goto P_0c04ca02;
case 0x0c04ca04u: goto P_0c04ca04;
case 0x0c04ca06u: goto P_0c04ca06;
case 0x0c04ca08u: goto P_0c04ca08;
case 0x0c04ca0au: goto P_0c04ca0a;
case 0x0c04ca0cu: goto P_0c04ca0c;
case 0x0c04ca0eu: goto P_0c04ca0e;
case 0x0c04ca10u: goto P_0c04ca10;
case 0x0c04ca12u: goto P_0c04ca12;
case 0x0c04ca14u: goto P_0c04ca14;
case 0x0c04ca16u: goto P_0c04ca16;
case 0x0c04ca18u: goto P_0c04ca18;
case 0x0c04ca1au: goto P_0c04ca1a;
case 0x0c04ca1cu: goto P_0c04ca1c;
case 0x0c04ca1eu: goto P_0c04ca1e;
case 0x0c04ca20u: goto P_0c04ca20;
case 0x0c04ca22u: goto P_0c04ca22;
case 0x0c04ca24u: goto P_0c04ca24;
case 0x0c04ca26u: goto P_0c04ca26;
case 0x0c04ca28u: goto P_0c04ca28;
case 0x0c04ca50u: goto P_0c04ca50;
case 0x0c04ca52u: goto P_0c04ca52;
case 0x0c04ca54u: goto P_0c04ca54;
case 0x0c04ca56u: goto P_0c04ca56;
case 0x0c04ca58u: goto P_0c04ca58;
case 0x0c04ca5au: goto P_0c04ca5a;
case 0x0c04ca5cu: goto P_0c04ca5c;
case 0x0c04ca5eu: goto P_0c04ca5e;
case 0x0c04ca60u: goto P_0c04ca60;
case 0x0c04ca62u: goto P_0c04ca62;
case 0x0c04ca64u: goto P_0c04ca64;
case 0x0c04ca66u: goto P_0c04ca66;
case 0x0c04ca68u: goto P_0c04ca68;
case 0x0c04ca6au: goto P_0c04ca6a;
case 0x0c04ca6cu: goto P_0c04ca6c;
case 0x0c04ca6eu: goto P_0c04ca6e;
case 0x0c04ca70u: goto P_0c04ca70;
case 0x0c04ca72u: goto P_0c04ca72;
case 0x0c04ca74u: goto P_0c04ca74;
case 0x0c04ca76u: goto P_0c04ca76;
case 0x0c04ca78u: goto P_0c04ca78;
case 0x0c04ca7au: goto P_0c04ca7a;
case 0x0c04ca7cu: goto P_0c04ca7c;
case 0x0c04ca7eu: goto P_0c04ca7e;
case 0x0c04ca80u: goto P_0c04ca80;
case 0x0c04ca82u: goto P_0c04ca82;
case 0x0c04ca84u: goto P_0c04ca84;
case 0x0c04ca86u: goto P_0c04ca86;
case 0x0c04ca88u: goto P_0c04ca88;
case 0x0c04ca8au: goto P_0c04ca8a;
case 0x0c04ca8cu: goto P_0c04ca8c;
case 0x0c04ca8eu: goto P_0c04ca8e;
case 0x0c04ca90u: goto P_0c04ca90;
case 0x0c04ca92u: goto P_0c04ca92;
case 0x0c04ca94u: goto P_0c04ca94;
case 0x0c04ca96u: goto P_0c04ca96;
case 0x0c04ca98u: goto P_0c04ca98;
case 0x0c04ca9au: goto P_0c04ca9a;
case 0x0c04ca9cu: goto P_0c04ca9c;
case 0x0c04ca9eu: goto P_0c04ca9e;
case 0x0c04caa0u: goto P_0c04caa0;
case 0x0c04caa2u: goto P_0c04caa2;
case 0x0c04caa4u: goto P_0c04caa4;
case 0x0c04caa6u: goto P_0c04caa6;
case 0x0c04caa8u: goto P_0c04caa8;
case 0x0c04caaau: goto P_0c04caaa;
case 0x0c04caacu: goto P_0c04caac;
case 0x0c04caaeu: goto P_0c04caae;
case 0x0c04cab0u: goto P_0c04cab0;
case 0x0c04cab2u: goto P_0c04cab2;
case 0x0c04cab4u: goto P_0c04cab4;
case 0x0c04cab6u: goto P_0c04cab6;
case 0x0c04cab8u: goto P_0c04cab8;
case 0x0c04cabau: goto P_0c04caba;
case 0x0c04cabcu: goto P_0c04cabc;
case 0x0c04cabeu: goto P_0c04cabe;
case 0x0c04cac0u: goto P_0c04cac0;
case 0x0c04cac2u: goto P_0c04cac2;
case 0x0c04cac4u: goto P_0c04cac4;
case 0x0c04cac6u: goto P_0c04cac6;
case 0x0c04cac8u: goto P_0c04cac8;
case 0x0c04cacau: goto P_0c04caca;
case 0x0c04caccu: goto P_0c04cacc;
case 0x0c04caceu: goto P_0c04cace;
case 0x0c04cad0u: goto P_0c04cad0;
case 0x0c04cad2u: goto P_0c04cad2;
case 0x0c04cad4u: goto P_0c04cad4;
case 0x0c04cad6u: goto P_0c04cad6;
case 0x0c04cad8u: goto P_0c04cad8;
case 0x0c04cadau: goto P_0c04cada;
case 0x0c04cadcu: goto P_0c04cadc;
case 0x0c04cadeu: goto P_0c04cade;
case 0x0c04cae0u: goto P_0c04cae0;
case 0x0c04cae2u: goto P_0c04cae2;
case 0x0c04cae4u: goto P_0c04cae4;
case 0x0c04cae6u: goto P_0c04cae6;
case 0x0c04cae8u: goto P_0c04cae8;
case 0x0c04caeau: goto P_0c04caea;
case 0x0c04caecu: goto P_0c04caec;
case 0x0c04caeeu: goto P_0c04caee;
case 0x0c04caf0u: goto P_0c04caf0;
case 0x0c04caf2u: goto P_0c04caf2;
case 0x0c04caf4u: goto P_0c04caf4;
case 0x0c04caf6u: goto P_0c04caf6;
case 0x0c04caf8u: goto P_0c04caf8;
case 0x0c04cafau: goto P_0c04cafa;
case 0x0c04cafcu: goto P_0c04cafc;
case 0x0c04cafeu: goto P_0c04cafe;
case 0x0c04cb00u: goto P_0c04cb00;
case 0x0c04cb02u: goto P_0c04cb02;
case 0x0c04cb04u: goto P_0c04cb04;
case 0x0c04cb06u: goto P_0c04cb06;
case 0x0c04cb08u: goto P_0c04cb08;
case 0x0c04cb0au: goto P_0c04cb0a;
case 0x0c04cb0cu: goto P_0c04cb0c;
case 0x0c04cb0eu: goto P_0c04cb0e;
case 0x0c04cb10u: goto P_0c04cb10;
case 0x0c04cb12u: goto P_0c04cb12;
case 0x0c04cb14u: goto P_0c04cb14;
case 0x0c04cb16u: goto P_0c04cb16;
case 0x0c04cb18u: goto P_0c04cb18;
case 0x0c04cb1au: goto P_0c04cb1a;
case 0x0c04cb1cu: goto P_0c04cb1c;
case 0x0c04cb1eu: goto P_0c04cb1e;
case 0x0c04cb20u: goto P_0c04cb20;
case 0x0c04cb22u: goto P_0c04cb22;
case 0x0c04cb24u: goto P_0c04cb24;
case 0x0c04cb26u: goto P_0c04cb26;
case 0x0c04cb28u: goto P_0c04cb28;
case 0x0c04cb2au: goto P_0c04cb2a;
case 0x0c04cb2cu: goto P_0c04cb2c;
case 0x0c04cb2eu: goto P_0c04cb2e;
case 0x0c04cb30u: goto P_0c04cb30;
case 0x0c04cb32u: goto P_0c04cb32;
case 0x0c04cb34u: goto P_0c04cb34;
case 0x0c04cb36u: goto P_0c04cb36;
case 0x0c04cb38u: goto P_0c04cb38;
case 0x0c04cb3au: goto P_0c04cb3a;
case 0x0c04cb3cu: goto P_0c04cb3c;
case 0x0c081d24u: goto P_0c081d24;
case 0x0c081d26u: goto P_0c081d26;
case 0x0c081d28u: goto P_0c081d28;
case 0x0c081d2au: goto P_0c081d2a;
case 0x0c081d2cu: goto P_0c081d2c;
case 0x0c081d2eu: goto P_0c081d2e;
case 0x0c081d30u: goto P_0c081d30;
case 0x0c081d32u: goto P_0c081d32;
case 0x0c081d34u: goto P_0c081d34;
case 0x0c081d36u: goto P_0c081d36;
case 0x0c081d38u: goto P_0c081d38;
case 0x0c081d3au: goto P_0c081d3a;
case 0x0c081d3cu: goto P_0c081d3c;
case 0x0c081d3eu: goto P_0c081d3e;
case 0x0c081d40u: goto P_0c081d40;
case 0x0c081d42u: goto P_0c081d42;
case 0x0c081d44u: goto P_0c081d44;
case 0x0c081d46u: goto P_0c081d46;
case 0x0c081d48u: goto P_0c081d48;
case 0x0c081d4au: goto P_0c081d4a;
case 0x0c081d4cu: goto P_0c081d4c;
case 0x0c081d4eu: goto P_0c081d4e;
case 0x0c081d50u: goto P_0c081d50;
case 0x0c081d52u: goto P_0c081d52;
case 0x0c081d54u: goto P_0c081d54;
case 0x0c081d56u: goto P_0c081d56;
case 0x0c081d58u: goto P_0c081d58;
case 0x0c081d5au: goto P_0c081d5a;
case 0x0c081d5cu: goto P_0c081d5c;
case 0x0c081d5eu: goto P_0c081d5e;
case 0x0c081d60u: goto P_0c081d60;
case 0x0c081d62u: goto P_0c081d62;
case 0x0c081d64u: goto P_0c081d64;
case 0x0c081d66u: goto P_0c081d66;
case 0x0c081d68u: goto P_0c081d68;
case 0x0c081d6au: goto P_0c081d6a;
case 0x0c081d6cu: goto P_0c081d6c;
case 0x0c081d6eu: goto P_0c081d6e;
case 0x0c081d70u: goto P_0c081d70;
case 0x0c081d72u: goto P_0c081d72;
case 0x0c081d74u: goto P_0c081d74;
case 0x0c081d76u: goto P_0c081d76;
case 0x0c081d78u: goto P_0c081d78;
case 0x0c081d7au: goto P_0c081d7a;
case 0x0c081d7cu: goto P_0c081d7c;
case 0x0c081d7eu: goto P_0c081d7e;
case 0x0c081d80u: goto P_0c081d80;
case 0x0c081d82u: goto P_0c081d82;
case 0x0c081d84u: goto P_0c081d84;
case 0x0c081d86u: goto P_0c081d86;
case 0x0c081d88u: goto P_0c081d88;
case 0x0c081d8au: goto P_0c081d8a;
case 0x0c081d8cu: goto P_0c081d8c;
case 0x0c081d8eu: goto P_0c081d8e;
case 0x0c081d90u: goto P_0c081d90;
case 0x0c081d92u: goto P_0c081d92;
case 0x0c081d94u: goto P_0c081d94;
case 0x0c081d96u: goto P_0c081d96;
case 0x0c081d98u: goto P_0c081d98;
case 0x0c081d9au: goto P_0c081d9a;
case 0x0c081d9cu: goto P_0c081d9c;
case 0x0c081d9eu: goto P_0c081d9e;
case 0x0c081da0u: goto P_0c081da0;
case 0x0c081da2u: goto P_0c081da2;
case 0x0c081da4u: goto P_0c081da4;
case 0x0c081da6u: goto P_0c081da6;
case 0x0c081da8u: goto P_0c081da8;
case 0x0c081daau: goto P_0c081daa;
case 0x0c081dacu: goto P_0c081dac;
case 0x0c081daeu: goto P_0c081dae;
case 0x0c081db0u: goto P_0c081db0;
case 0x0c081db2u: goto P_0c081db2;
case 0x0c081db4u: goto P_0c081db4;
case 0x0c081db6u: goto P_0c081db6;
case 0x0c081db8u: goto P_0c081db8;
case 0x0c081dbau: goto P_0c081dba;
case 0x0c081dbcu: goto P_0c081dbc;
case 0x0c081dbeu: goto P_0c081dbe;
case 0x0c081dc0u: goto P_0c081dc0;
case 0x0c081dc2u: goto P_0c081dc2;
case 0x0c081dc4u: goto P_0c081dc4;
case 0x0c081dc6u: goto P_0c081dc6;
case 0x0c081dc8u: goto P_0c081dc8;
case 0x0c081dcau: goto P_0c081dca;
case 0x0c081dccu: goto P_0c081dcc;
case 0x0c081dceu: goto P_0c081dce;
case 0x0c081dd0u: goto P_0c081dd0;
case 0x0c081dd2u: goto P_0c081dd2;
case 0x0c081dd4u: goto P_0c081dd4;
case 0x0c081dd6u: goto P_0c081dd6;
case 0x0c081dd8u: goto P_0c081dd8;
case 0x0c081ddau: goto P_0c081dda;
case 0x0c081ddcu: goto P_0c081ddc;
case 0x0c081ddeu: goto P_0c081dde;
case 0x0c081de0u: goto P_0c081de0;
case 0x0c081de2u: goto P_0c081de2;
case 0x0c081de4u: goto P_0c081de4;
case 0x0c081de6u: goto P_0c081de6;
case 0x0c081de8u: goto P_0c081de8;
case 0x0c081deau: goto P_0c081dea;
case 0x0c081decu: goto P_0c081dec;
case 0x0c081deeu: goto P_0c081dee;
case 0x0c081df0u: goto P_0c081df0;
case 0x0c081df2u: goto P_0c081df2;
case 0x0c081df4u: goto P_0c081df4;
case 0x0c081df6u: goto P_0c081df6;
case 0x0c081df8u: goto P_0c081df8;
case 0x0c081dfau: goto P_0c081dfa;
case 0x0c081dfcu: goto P_0c081dfc;
case 0x0c081dfeu: goto P_0c081dfe;
case 0x0c081e00u: goto P_0c081e00;
case 0x0c081e02u: goto P_0c081e02;
case 0x0c081e04u: goto P_0c081e04;
case 0x0c081e06u: goto P_0c081e06;
case 0x0c081e08u: goto P_0c081e08;
case 0x0c081e0au: goto P_0c081e0a;
case 0x0c081e0cu: goto P_0c081e0c;
case 0x0c081e0eu: goto P_0c081e0e;
case 0x0c081e10u: goto P_0c081e10;
case 0x0c081e12u: goto P_0c081e12;
case 0x0c081e14u: goto P_0c081e14;
case 0x0c081e16u: goto P_0c081e16;
case 0x0c081e18u: goto P_0c081e18;
case 0x0c081e1au: goto P_0c081e1a;
case 0x0c081e1cu: goto P_0c081e1c;
case 0x0c081e1eu: goto P_0c081e1e;
case 0x0c081e20u: goto P_0c081e20;
case 0x0c081e22u: goto P_0c081e22;
case 0x0c081e24u: goto P_0c081e24;
case 0x0c081e26u: goto P_0c081e26;
case 0x0c081e28u: goto P_0c081e28;
case 0x0c081e2au: goto P_0c081e2a;
case 0x0c081e2cu: goto P_0c081e2c;
case 0x0c081e2eu: goto P_0c081e2e;
case 0x0c081e30u: goto P_0c081e30;
case 0x0c081e32u: goto P_0c081e32;
case 0x0c081e34u: goto P_0c081e34;
case 0x0c081e36u: goto P_0c081e36;
case 0x0c081e38u: goto P_0c081e38;
case 0x0c081e3au: goto P_0c081e3a;
case 0x0c081e3cu: goto P_0c081e3c;
case 0x0c081e3eu: goto P_0c081e3e;
case 0x0c081e68u: goto P_0c081e68;
case 0x0c081e6au: goto P_0c081e6a;
case 0x0c081e6cu: goto P_0c081e6c;
case 0x0c081e6eu: goto P_0c081e6e;
case 0x0c081e70u: goto P_0c081e70;
case 0x0c081e72u: goto P_0c081e72;
case 0x0c081e74u: goto P_0c081e74;
case 0x0c081e76u: goto P_0c081e76;
case 0x0c081e78u: goto P_0c081e78;
case 0x0c081e7au: goto P_0c081e7a;
case 0x0c081e7cu: goto P_0c081e7c;
case 0x0c081e7eu: goto P_0c081e7e;
case 0x0c081e80u: goto P_0c081e80;
case 0x0c081e82u: goto P_0c081e82;
case 0x0c081e84u: goto P_0c081e84;
case 0x0c081e86u: goto P_0c081e86;
case 0x0c081e88u: goto P_0c081e88;
case 0x0c081e8au: goto P_0c081e8a;
case 0x0c081e8cu: goto P_0c081e8c;
case 0x0c081e8eu: goto P_0c081e8e;
case 0x0c081e90u: goto P_0c081e90;
case 0x0c081e92u: goto P_0c081e92;
case 0x0c081e94u: goto P_0c081e94;
case 0x0c081e96u: goto P_0c081e96;
case 0x0c081e98u: goto P_0c081e98;
case 0x0c081e9au: goto P_0c081e9a;
case 0x0c081e9cu: goto P_0c081e9c;
case 0x0c081e9eu: goto P_0c081e9e;
case 0x0c081ea0u: goto P_0c081ea0;
case 0x0c081ea2u: goto P_0c081ea2;
case 0x0c081ea4u: goto P_0c081ea4;
case 0x0c081ea6u: goto P_0c081ea6;
case 0x0c081ea8u: goto P_0c081ea8;
case 0x0c081eaau: goto P_0c081eaa;
case 0x0c081eacu: goto P_0c081eac;
case 0x0c081eaeu: goto P_0c081eae;
case 0x0c081eb0u: goto P_0c081eb0;
case 0x0c081eb2u: goto P_0c081eb2;
case 0x0c081eb4u: goto P_0c081eb4;
case 0x0c081eb6u: goto P_0c081eb6;
case 0x0c081eb8u: goto P_0c081eb8;
case 0x0c081ebau: goto P_0c081eba;
case 0x0c081ebcu: goto P_0c081ebc;
case 0x0c081ebeu: goto P_0c081ebe;
case 0x0c081ec0u: goto P_0c081ec0;
case 0x0c081ec2u: goto P_0c081ec2;
case 0x0c081ec4u: goto P_0c081ec4;
case 0x0c081ec6u: goto P_0c081ec6;
case 0x0c081ec8u: goto P_0c081ec8;
case 0x0c081ecau: goto P_0c081eca;
case 0x0c081eccu: goto P_0c081ecc;
case 0x0c081eceu: goto P_0c081ece;
case 0x0c081ed0u: goto P_0c081ed0;
case 0x0c081ed2u: goto P_0c081ed2;
case 0x0c081ed4u: goto P_0c081ed4;
case 0x0c081ed6u: goto P_0c081ed6;
case 0x0c081ed8u: goto P_0c081ed8;
case 0x0c081edau: goto P_0c081eda;
case 0x0c081edcu: goto P_0c081edc;
case 0x0c081edeu: goto P_0c081ede;
case 0x0c081ee0u: goto P_0c081ee0;
case 0x0c081ee2u: goto P_0c081ee2;
case 0x0c081ee4u: goto P_0c081ee4;
case 0x0c081ee6u: goto P_0c081ee6;
case 0x0c081ee8u: goto P_0c081ee8;
case 0x0c081eeau: goto P_0c081eea;
case 0x0c081eecu: goto P_0c081eec;
case 0x0c081eeeu: goto P_0c081eee;
case 0x0c081ef0u: goto P_0c081ef0;
case 0x0c081ef2u: goto P_0c081ef2;
case 0x0c081ef4u: goto P_0c081ef4;
case 0x0c081ef6u: goto P_0c081ef6;
case 0x0c081ef8u: goto P_0c081ef8;
case 0x0c081efau: goto P_0c081efa;
case 0x0c081efcu: goto P_0c081efc;
case 0x0c081efeu: goto P_0c081efe;
case 0x0c081f00u: goto P_0c081f00;
case 0x0c081f02u: goto P_0c081f02;
case 0x0c081f04u: goto P_0c081f04;
case 0x0c081f06u: goto P_0c081f06;
case 0x0c081f08u: goto P_0c081f08;
case 0x0c081f0au: goto P_0c081f0a;
case 0x0c081f0cu: goto P_0c081f0c;
case 0x0c081f0eu: goto P_0c081f0e;
case 0x0c081f10u: goto P_0c081f10;
case 0x0c081f12u: goto P_0c081f12;
case 0x0c081f14u: goto P_0c081f14;
case 0x0c081f16u: goto P_0c081f16;
case 0x0c081f18u: goto P_0c081f18;
case 0x0c081f1au: goto P_0c081f1a;
case 0x0c081f1cu: goto P_0c081f1c;
case 0x0c081f1eu: goto P_0c081f1e;
case 0x0c081f20u: goto P_0c081f20;
case 0x0c081f22u: goto P_0c081f22;
case 0x0c081f24u: goto P_0c081f24;
case 0x0c081f26u: goto P_0c081f26;
case 0x0c081f28u: goto P_0c081f28;
case 0x0c081f2au: goto P_0c081f2a;
case 0x0c081f2cu: goto P_0c081f2c;
case 0x0c081f2eu: goto P_0c081f2e;
case 0x0c081f30u: goto P_0c081f30;
case 0x0c081f32u: goto P_0c081f32;
case 0x0c081f34u: goto P_0c081f34;
case 0x0c081f36u: goto P_0c081f36;
case 0x0c081f38u: goto P_0c081f38;
case 0x0c081f3au: goto P_0c081f3a;
case 0x0c081f3cu: goto P_0c081f3c;
case 0x0c081f3eu: goto P_0c081f3e;
case 0x0c081f40u: goto P_0c081f40;
case 0x0c081f42u: goto P_0c081f42;
case 0x0c081f44u: goto P_0c081f44;
case 0x0c081f46u: goto P_0c081f46;
case 0x0c081f48u: goto P_0c081f48;
case 0x0c081f4au: goto P_0c081f4a;
case 0x0c081f4cu: goto P_0c081f4c;
case 0x0c081f4eu: goto P_0c081f4e;
case 0x0c081f50u: goto P_0c081f50;
case 0x0c081f52u: goto P_0c081f52;
case 0x0c081f54u: goto P_0c081f54;
case 0x0c081f56u: goto P_0c081f56;
case 0x0c081f58u: goto P_0c081f58;
case 0x0c081f5au: goto P_0c081f5a;
case 0x0c081f5cu: goto P_0c081f5c;
case 0x0c081f5eu: goto P_0c081f5e;
case 0x0c081f60u: goto P_0c081f60;
case 0x0c081f62u: goto P_0c081f62;
case 0x0c081f64u: goto P_0c081f64;
case 0x0c081f66u: goto P_0c081f66;
case 0x0c081f68u: goto P_0c081f68;
case 0x0c081f6au: goto P_0c081f6a;
case 0x0c081f6cu: goto P_0c081f6c;
case 0x0c081f6eu: goto P_0c081f6e;
case 0x0c081f70u: goto P_0c081f70;
case 0x0c081f72u: goto P_0c081f72;
case 0x0c081f74u: goto P_0c081f74;
case 0x0c081f76u: goto P_0c081f76;
case 0x0c081f78u: goto P_0c081f78;
case 0x0c081f7au: goto P_0c081f7a;
case 0x0c081f7cu: goto P_0c081f7c;
case 0x0c081f7eu: goto P_0c081f7e;
case 0x0c081f80u: goto P_0c081f80;
case 0x0c081f82u: goto P_0c081f82;
case 0x0c0831f8u: goto P_0c0831f8;
case 0x0c0831fau: goto P_0c0831fa;
case 0x0c0831fcu: goto P_0c0831fc;
case 0x0c0831feu: goto P_0c0831fe;
case 0x0c083200u: goto P_0c083200;
case 0x0c083202u: goto P_0c083202;
case 0x0c083204u: goto P_0c083204;
case 0x0c083206u: goto P_0c083206;
case 0x0c083208u: goto P_0c083208;
case 0x0c08320au: goto P_0c08320a;
case 0x0c08320cu: goto P_0c08320c;
case 0x0c08320eu: goto P_0c08320e;
case 0x0c083210u: goto P_0c083210;
case 0x0c083212u: goto P_0c083212;
case 0x0c083214u: goto P_0c083214;
case 0x0c083216u: goto P_0c083216;
case 0x0c083218u: goto P_0c083218;
case 0x0c08321au: goto P_0c08321a;
case 0x0c08321cu: goto P_0c08321c;
case 0x0c08321eu: goto P_0c08321e;
case 0x0c083220u: goto P_0c083220;
case 0x0c083222u: goto P_0c083222;
case 0x0c083224u: goto P_0c083224;
case 0x0c083226u: goto P_0c083226;
case 0x0c083228u: goto P_0c083228;
case 0x0c08322au: goto P_0c08322a;
case 0x0c08322cu: goto P_0c08322c;
case 0x0c08322eu: goto P_0c08322e;
case 0x0c083230u: goto P_0c083230;
case 0x0c083232u: goto P_0c083232;
case 0x0c083234u: goto P_0c083234;
case 0x0c083236u: goto P_0c083236;
case 0x0c083238u: goto P_0c083238;
case 0x0c08323au: goto P_0c08323a;
case 0x0c08323cu: goto P_0c08323c;
case 0x0c08323eu: goto P_0c08323e;
case 0x0c083240u: goto P_0c083240;
case 0x0c083242u: goto P_0c083242;
case 0x0c083244u: goto P_0c083244;
case 0x0c08327cu: goto P_0c08327c;
case 0x0c08327eu: goto P_0c08327e;
case 0x0c083280u: goto P_0c083280;
case 0x0c083282u: goto P_0c083282;
case 0x0c083284u: goto P_0c083284;
case 0x0c083286u: goto P_0c083286;
case 0x0c083288u: goto P_0c083288;
case 0x0c08328au: goto P_0c08328a;
case 0x0c08328cu: goto P_0c08328c;
case 0x0c08328eu: goto P_0c08328e;
case 0x0c083290u: goto P_0c083290;
case 0x0c083292u: goto P_0c083292;
case 0x0c083294u: goto P_0c083294;
case 0x0c083296u: goto P_0c083296;
case 0x0c083298u: goto P_0c083298;
case 0x0c08329au: goto P_0c08329a;
case 0x0c08329cu: goto P_0c08329c;
case 0x0c08329eu: goto P_0c08329e;
case 0x0c0832a0u: goto P_0c0832a0;
case 0x0c0832a2u: goto P_0c0832a2;
case 0x0c0832a4u: goto P_0c0832a4;
case 0x0c0832a6u: goto P_0c0832a6;
case 0x0c0832a8u: goto P_0c0832a8;
case 0x0c0832aau: goto P_0c0832aa;
case 0x0c0832acu: goto P_0c0832ac;
case 0x0c0832aeu: goto P_0c0832ae;
case 0x0c0832b0u: goto P_0c0832b0;
case 0x0c0832b2u: goto P_0c0832b2;
case 0x0c0832b4u: goto P_0c0832b4;
case 0x0c0832b6u: goto P_0c0832b6;
case 0x0c0832b8u: goto P_0c0832b8;
case 0x0c0832bau: goto P_0c0832ba;
case 0x0c0832bcu: goto P_0c0832bc;
case 0x0c0832beu: goto P_0c0832be;
case 0x0c0832c0u: goto P_0c0832c0;
case 0x0c0832c2u: goto P_0c0832c2;
case 0x0c0832c4u: goto P_0c0832c4;
case 0x0c0832c6u: goto P_0c0832c6;
case 0x0c0832c8u: goto P_0c0832c8;
case 0x0c0832cau: goto P_0c0832ca;
case 0x0c0832ccu: goto P_0c0832cc;
case 0x0c0832ceu: goto P_0c0832ce;
case 0x0c0832d0u: goto P_0c0832d0;
case 0x0c0832d2u: goto P_0c0832d2;
case 0x0c0832d4u: goto P_0c0832d4;
case 0x0c0832d6u: goto P_0c0832d6;
case 0x0c0832d8u: goto P_0c0832d8;
case 0x0c0832dau: goto P_0c0832da;
case 0x0c0832dcu: goto P_0c0832dc;
case 0x0c0832deu: goto P_0c0832de;
case 0x0c0832e0u: goto P_0c0832e0;
case 0x0c0832e2u: goto P_0c0832e2;
case 0x0c0832e4u: goto P_0c0832e4;
case 0x0c0832e6u: goto P_0c0832e6;
case 0x0c0832e8u: goto P_0c0832e8;
case 0x0c0832eau: goto P_0c0832ea;
case 0x0c0832ecu: goto P_0c0832ec;
case 0x0c0832eeu: goto P_0c0832ee;
case 0x0c0832f0u: goto P_0c0832f0;
case 0x0c0832f2u: goto P_0c0832f2;
case 0x0c0832f4u: goto P_0c0832f4;
case 0x0c0832f6u: goto P_0c0832f6;
case 0x0c0832f8u: goto P_0c0832f8;
case 0x0c0832fau: goto P_0c0832fa;
case 0x0c0832fcu: goto P_0c0832fc;
case 0x0c0832feu: goto P_0c0832fe;
case 0x0c083300u: goto P_0c083300;
case 0x0c083302u: goto P_0c083302;
case 0x0c083304u: goto P_0c083304;
case 0x0c083306u: goto P_0c083306;
case 0x0c083308u: goto P_0c083308;
case 0x0c08330au: goto P_0c08330a;
case 0x0c08330cu: goto P_0c08330c;
case 0x0c08330eu: goto P_0c08330e;
case 0x0c083310u: goto P_0c083310;
case 0x0c083312u: goto P_0c083312;
case 0x0c083314u: goto P_0c083314;
case 0x0c083316u: goto P_0c083316;
case 0x0c083318u: goto P_0c083318;
case 0x0c08331au: goto P_0c08331a;
case 0x0c08331cu: goto P_0c08331c;
case 0x0c08331eu: goto P_0c08331e;
case 0x0c083320u: goto P_0c083320;
case 0x0c083322u: goto P_0c083322;
case 0x0c083324u: goto P_0c083324;
case 0x0c083326u: goto P_0c083326;
case 0x0c083328u: goto P_0c083328;
case 0x0c08332au: goto P_0c08332a;
case 0x0c08332cu: goto P_0c08332c;
case 0x0c08332eu: goto P_0c08332e;
case 0x0c083330u: goto P_0c083330;
case 0x0c083332u: goto P_0c083332;
case 0x0c083334u: goto P_0c083334;
case 0x0c083336u: goto P_0c083336;
case 0x0c083338u: goto P_0c083338;
case 0x0c08333au: goto P_0c08333a;
case 0x0c08333cu: goto P_0c08333c;
case 0x0c08333eu: goto P_0c08333e;
case 0x0c083340u: goto P_0c083340;
case 0x0c083342u: goto P_0c083342;
case 0x0c083344u: goto P_0c083344;
case 0x0c083346u: goto P_0c083346;
case 0x0c083348u: goto P_0c083348;
case 0x0c08334au: goto P_0c08334a;
case 0x0c08334cu: goto P_0c08334c;
case 0x0c08334eu: goto P_0c08334e;
case 0x0c083350u: goto P_0c083350;
case 0x0c083352u: goto P_0c083352;
case 0x0c083354u: goto P_0c083354;
case 0x0c083356u: goto P_0c083356;
case 0x0c083358u: goto P_0c083358;
case 0x0c08335au: goto P_0c08335a;
case 0x0c08335cu: goto P_0c08335c;
case 0x0c08335eu: goto P_0c08335e;
case 0x0c083360u: goto P_0c083360;
case 0x0c083362u: goto P_0c083362;
case 0x0c083364u: goto P_0c083364;
case 0x0c083384u: goto P_0c083384;
case 0x0c083386u: goto P_0c083386;
case 0x0c083388u: goto P_0c083388;
case 0x0c08338au: goto P_0c08338a;
case 0x0c08338cu: goto P_0c08338c;
case 0x0c08338eu: goto P_0c08338e;
case 0x0c083390u: goto P_0c083390;
case 0x0c083392u: goto P_0c083392;
case 0x0c083394u: goto P_0c083394;
case 0x0c083396u: goto P_0c083396;
case 0x0c083398u: goto P_0c083398;
case 0x0c08339au: goto P_0c08339a;
case 0x0c08339cu: goto P_0c08339c;
case 0x0c08339eu: goto P_0c08339e;
case 0x0c0833a0u: goto P_0c0833a0;
case 0x0c0833a2u: goto P_0c0833a2;
case 0x0c0833a4u: goto P_0c0833a4;
case 0x0c0833a6u: goto P_0c0833a6;
case 0x0c0833a8u: goto P_0c0833a8;
case 0x0c0833aau: goto P_0c0833aa;
case 0x0c0833acu: goto P_0c0833ac;
case 0x0c0833aeu: goto P_0c0833ae;
case 0x0c0833b0u: goto P_0c0833b0;
case 0x0c0833b2u: goto P_0c0833b2;
case 0x0c0833b4u: goto P_0c0833b4;
case 0x0c0833b6u: goto P_0c0833b6;
case 0x0c0833b8u: goto P_0c0833b8;
case 0x0c0833bau: goto P_0c0833ba;
case 0x0c0833bcu: goto P_0c0833bc;
case 0x0c0833beu: goto P_0c0833be;
case 0x0c0833c0u: goto P_0c0833c0;
case 0x0c0833c2u: goto P_0c0833c2;
case 0x0c0833c4u: goto P_0c0833c4;
case 0x0c0833c6u: goto P_0c0833c6;
case 0x0c0833c8u: goto P_0c0833c8;
case 0x0c0833cau: goto P_0c0833ca;
case 0x0c0833ccu: goto P_0c0833cc;
case 0x0c0833ceu: goto P_0c0833ce;
case 0x0c0833d0u: goto P_0c0833d0;
case 0x0c0833d2u: goto P_0c0833d2;
case 0x0c0833d4u: goto P_0c0833d4;
case 0x0c0833d6u: goto P_0c0833d6;
case 0x0c0833d8u: goto P_0c0833d8;
case 0x0c0833dau: goto P_0c0833da;
case 0x0c0833dcu: goto P_0c0833dc;
case 0x0c0833deu: goto P_0c0833de;
case 0x0c0833e0u: goto P_0c0833e0;
case 0x0c0833e2u: goto P_0c0833e2;
case 0x0c0833e4u: goto P_0c0833e4;
case 0x0c0833e6u: goto P_0c0833e6;
case 0x0c0833e8u: goto P_0c0833e8;
case 0x0c0833eau: goto P_0c0833ea;
case 0x0c0833ecu: goto P_0c0833ec;
case 0x0c0833eeu: goto P_0c0833ee;
case 0x0c0833f0u: goto P_0c0833f0;
case 0x0c0833f2u: goto P_0c0833f2;
case 0x0c0833f4u: goto P_0c0833f4;
case 0x0c0833f6u: goto P_0c0833f6;
case 0x0c0833f8u: goto P_0c0833f8;
case 0x0c0833fau: goto P_0c0833fa;
case 0x0c0833fcu: goto P_0c0833fc;
case 0x0c0833feu: goto P_0c0833fe;
case 0x0c083400u: goto P_0c083400;
case 0x0c083402u: goto P_0c083402;
case 0x0c083404u: goto P_0c083404;
case 0x0c083406u: goto P_0c083406;
case 0x0c083408u: goto P_0c083408;
case 0x0c08340au: goto P_0c08340a;
case 0x0c08340cu: goto P_0c08340c;
case 0x0c08340eu: goto P_0c08340e;
case 0x0c083410u: goto P_0c083410;
case 0x0c083412u: goto P_0c083412;
case 0x0c083414u: goto P_0c083414;
case 0x0c083416u: goto P_0c083416;
case 0x0c083418u: goto P_0c083418;
case 0x0c08341au: goto P_0c08341a;
case 0x0c08341cu: goto P_0c08341c;
case 0x0c08341eu: goto P_0c08341e;
case 0x0c083420u: goto P_0c083420;
case 0x0c083422u: goto P_0c083422;
case 0x0c083424u: goto P_0c083424;
case 0x0c083426u: goto P_0c083426;
case 0x0c083428u: goto P_0c083428;
case 0x0c08342au: goto P_0c08342a;
case 0x0c08342cu: goto P_0c08342c;
case 0x0c08342eu: goto P_0c08342e;
case 0x0c083430u: goto P_0c083430;
case 0x0c083432u: goto P_0c083432;
case 0x0c083434u: goto P_0c083434;
case 0x0c083436u: goto P_0c083436;
case 0x0c083438u: goto P_0c083438;
case 0x0c08343au: goto P_0c08343a;
case 0x0c08343cu: goto P_0c08343c;
case 0x0c08343eu: goto P_0c08343e;
case 0x0c083440u: goto P_0c083440;
case 0x0c083442u: goto P_0c083442;
case 0x0c083444u: goto P_0c083444;
case 0x0c083446u: goto P_0c083446;
case 0x0c083448u: goto P_0c083448;
case 0x0c08344au: goto P_0c08344a;
case 0x0c08344cu: goto P_0c08344c;
case 0x0c08344eu: goto P_0c08344e;
case 0x0c083450u: goto P_0c083450;
case 0x0c083452u: goto P_0c083452;
case 0x0c083454u: goto P_0c083454;
case 0x0c083456u: goto P_0c083456;
case 0x0c083458u: goto P_0c083458;
case 0x0c08345au: goto P_0c08345a;
case 0x0c08345cu: goto P_0c08345c;
case 0x0c08345eu: goto P_0c08345e;
case 0x0c083460u: goto P_0c083460;
case 0x0c083462u: goto P_0c083462;
case 0x0c083464u: goto P_0c083464;
case 0x0c083466u: goto P_0c083466;
case 0x0c083468u: goto P_0c083468;
case 0x0c08346au: goto P_0c08346a;
case 0x0c08346cu: goto P_0c08346c;
case 0x0c08346eu: goto P_0c08346e;
case 0x0c083470u: goto P_0c083470;
case 0x0c083472u: goto P_0c083472;
case 0x0c083474u: goto P_0c083474;
case 0x0c083476u: goto P_0c083476;
case 0x0c083478u: goto P_0c083478;
case 0x0c08347au: goto P_0c08347a;
case 0x0c08347cu: goto P_0c08347c;
case 0x0c08347eu: goto P_0c08347e;
case 0x0c083480u: goto P_0c083480;
case 0x0c083482u: goto P_0c083482;
case 0x0c083484u: goto P_0c083484;
case 0x0c083486u: goto P_0c083486;
case 0x0c083488u: goto P_0c083488;
case 0x0c08348au: goto P_0c08348a;
case 0x0c08348cu: goto P_0c08348c;
case 0x0c08348eu: goto P_0c08348e;
case 0x0c083490u: goto P_0c083490;
case 0x0c083492u: goto P_0c083492;
case 0x0c0834b0u: goto P_0c0834b0;
case 0x0c0834b2u: goto P_0c0834b2;
case 0x0c0834b4u: goto P_0c0834b4;
case 0x0c0834b6u: goto P_0c0834b6;
case 0x0c0834b8u: goto P_0c0834b8;
case 0x0c0834bau: goto P_0c0834ba;
case 0x0c0834bcu: goto P_0c0834bc;
case 0x0c0834beu: goto P_0c0834be;
case 0x0c0834c0u: goto P_0c0834c0;
case 0x0c0834c2u: goto P_0c0834c2;
case 0x0c0834c4u: goto P_0c0834c4;
case 0x0c0834c6u: goto P_0c0834c6;
case 0x0c0834c8u: goto P_0c0834c8;
case 0x0c0834cau: goto P_0c0834ca;
case 0x0c0834ccu: goto P_0c0834cc;
case 0x0c0834ceu: goto P_0c0834ce;
case 0x0c0834d0u: goto P_0c0834d0;
case 0x0c0834d2u: goto P_0c0834d2;
case 0x0c0834d4u: goto P_0c0834d4;
case 0x0c0834d6u: goto P_0c0834d6;
case 0x0c0834d8u: goto P_0c0834d8;
case 0x0c0834dau: goto P_0c0834da;
case 0x0c0834dcu: goto P_0c0834dc;
case 0x0c0834deu: goto P_0c0834de;
case 0x0c0834e0u: goto P_0c0834e0;
case 0x0c0834e2u: goto P_0c0834e2;
case 0x0c0834e4u: goto P_0c0834e4;
case 0x0c0834e6u: goto P_0c0834e6;
case 0x0c0834e8u: goto P_0c0834e8;
case 0x0c0834eau: goto P_0c0834ea;
case 0x0c0834ecu: goto P_0c0834ec;
case 0x0c0834eeu: goto P_0c0834ee;
case 0x0c0834f0u: goto P_0c0834f0;
case 0x0c0834f2u: goto P_0c0834f2;
case 0x0c0834f4u: goto P_0c0834f4;
case 0x0c0834f6u: goto P_0c0834f6;
case 0x0c0834f8u: goto P_0c0834f8;
case 0x0c0834fau: goto P_0c0834fa;
case 0x0c0834fcu: goto P_0c0834fc;
case 0x0c0834feu: goto P_0c0834fe;
case 0x0c083500u: goto P_0c083500;
case 0x0c083502u: goto P_0c083502;
case 0x0c083504u: goto P_0c083504;
case 0x0c083506u: goto P_0c083506;
case 0x0c083508u: goto P_0c083508;
case 0x0c08350au: goto P_0c08350a;
case 0x0c08350cu: goto P_0c08350c;
case 0x0c08350eu: goto P_0c08350e;
case 0x0c083510u: goto P_0c083510;
case 0x0c083512u: goto P_0c083512;
case 0x0c083514u: goto P_0c083514;
case 0x0c083516u: goto P_0c083516;
case 0x0c083518u: goto P_0c083518;
case 0x0c08351au: goto P_0c08351a;
case 0x0c08351cu: goto P_0c08351c;
case 0x0c08351eu: goto P_0c08351e;
case 0x0c083520u: goto P_0c083520;
case 0x0c083522u: goto P_0c083522;
case 0x0c083524u: goto P_0c083524;
case 0x0c083526u: goto P_0c083526;
case 0x0c083528u: goto P_0c083528;
case 0x0c08352au: goto P_0c08352a;
case 0x0c08352cu: goto P_0c08352c;
case 0x0c08352eu: goto P_0c08352e;
case 0x0c083530u: goto P_0c083530;
case 0x0c083532u: goto P_0c083532;
case 0x0c083534u: goto P_0c083534;
case 0x0c083536u: goto P_0c083536;
case 0x0c083538u: goto P_0c083538;
case 0x0c08353au: goto P_0c08353a;
case 0x0c08353cu: goto P_0c08353c;
case 0x0c08353eu: goto P_0c08353e;
case 0x0c083540u: goto P_0c083540;
case 0x0c083542u: goto P_0c083542;
case 0x0c083544u: goto P_0c083544;
case 0x0c083546u: goto P_0c083546;
case 0x0c083548u: goto P_0c083548;
case 0x0c08354au: goto P_0c08354a;
case 0x0c08354cu: goto P_0c08354c;
case 0x0c08354eu: goto P_0c08354e;
case 0x0c083550u: goto P_0c083550;
case 0x0c083552u: goto P_0c083552;
case 0x0c083554u: goto P_0c083554;
case 0x0c083556u: goto P_0c083556;
case 0x0c083558u: goto P_0c083558;
case 0x0c08355au: goto P_0c08355a;
case 0x0c08355cu: goto P_0c08355c;
case 0x0c08355eu: goto P_0c08355e;
case 0x0c083560u: goto P_0c083560;
case 0x0c083562u: goto P_0c083562;
case 0x0c083564u: goto P_0c083564;
case 0x0c083566u: goto P_0c083566;
case 0x0c083568u: goto P_0c083568;
case 0x0c08356au: goto P_0c08356a;
case 0x0c08356cu: goto P_0c08356c;
case 0x0c08356eu: goto P_0c08356e;
case 0x0c083570u: goto P_0c083570;
case 0x0c083572u: goto P_0c083572;
case 0x0c083574u: goto P_0c083574;
case 0x0c083576u: goto P_0c083576;
case 0x0c083578u: goto P_0c083578;
case 0x0c08357au: goto P_0c08357a;
case 0x0c08357cu: goto P_0c08357c;
case 0x0c08357eu: goto P_0c08357e;
case 0x0c083580u: goto P_0c083580;
case 0x0c083582u: goto P_0c083582;
case 0x0c083584u: goto P_0c083584;
case 0x0c083586u: goto P_0c083586;
case 0x0c083588u: goto P_0c083588;
case 0x0c08358au: goto P_0c08358a;
case 0x0c08358cu: goto P_0c08358c;
case 0x0c08358eu: goto P_0c08358e;
case 0x0c083590u: goto P_0c083590;
case 0x0c083592u: goto P_0c083592;
case 0x0c083594u: goto P_0c083594;
case 0x0c083596u: goto P_0c083596;
case 0x0c083598u: goto P_0c083598;
case 0x0c08359au: goto P_0c08359a;
case 0x0c08359cu: goto P_0c08359c;
case 0x0c08359eu: goto P_0c08359e;
case 0x0c0835a0u: goto P_0c0835a0;
case 0x0c0835a2u: goto P_0c0835a2;
case 0x0c0835a4u: goto P_0c0835a4;
case 0x0c0835a6u: goto P_0c0835a6;
case 0x0c0835a8u: goto P_0c0835a8;
case 0x0c0835c4u: goto P_0c0835c4;
case 0x0c0835c6u: goto P_0c0835c6;
case 0x0c0835c8u: goto P_0c0835c8;
case 0x0c0835cau: goto P_0c0835ca;
case 0x0c0835ccu: goto P_0c0835cc;
case 0x0c0835ceu: goto P_0c0835ce;
case 0x0c0835d0u: goto P_0c0835d0;
case 0x0c0835d2u: goto P_0c0835d2;
case 0x0c0835d4u: goto P_0c0835d4;
case 0x0c0835d6u: goto P_0c0835d6;
case 0x0c0835d8u: goto P_0c0835d8;
case 0x0c0835dau: goto P_0c0835da;
case 0x0c0835dcu: goto P_0c0835dc;
case 0x0c0835deu: goto P_0c0835de;
case 0x0c0835e0u: goto P_0c0835e0;
case 0x0c0835e2u: goto P_0c0835e2;
case 0x0c0835e4u: goto P_0c0835e4;
case 0x0c0835e6u: goto P_0c0835e6;
case 0x0c0835e8u: goto P_0c0835e8;
case 0x0c0835eau: goto P_0c0835ea;
case 0x0c0835ecu: goto P_0c0835ec;
case 0x0c0835eeu: goto P_0c0835ee;
case 0x0c0835f0u: goto P_0c0835f0;
case 0x0c0835f2u: goto P_0c0835f2;
case 0x0c0835f4u: goto P_0c0835f4;
case 0x0c0835f6u: goto P_0c0835f6;
case 0x0c0835f8u: goto P_0c0835f8;
case 0x0c0835fau: goto P_0c0835fa;
case 0x0c0835fcu: goto P_0c0835fc;
case 0x0c0835feu: goto P_0c0835fe;
case 0x0c083600u: goto P_0c083600;
case 0x0c083602u: goto P_0c083602;
case 0x0c083604u: goto P_0c083604;
case 0x0c083606u: goto P_0c083606;
case 0x0c083608u: goto P_0c083608;
case 0x0c08360au: goto P_0c08360a;
case 0x0c08360cu: goto P_0c08360c;
case 0x0c08360eu: goto P_0c08360e;
case 0x0c083610u: goto P_0c083610;
case 0x0c083612u: goto P_0c083612;
case 0x0c083614u: goto P_0c083614;
case 0x0c083616u: goto P_0c083616;
case 0x0c083618u: goto P_0c083618;
case 0x0c08361au: goto P_0c08361a;
case 0x0c08361cu: goto P_0c08361c;
case 0x0c08361eu: goto P_0c08361e;
case 0x0c083620u: goto P_0c083620;
case 0x0c083622u: goto P_0c083622;
case 0x0c083624u: goto P_0c083624;
case 0x0c083626u: goto P_0c083626;
case 0x0c083628u: goto P_0c083628;
case 0x0c08362au: goto P_0c08362a;
case 0x0c08362cu: goto P_0c08362c;
case 0x0c08362eu: goto P_0c08362e;
case 0x0c083630u: goto P_0c083630;
case 0x0c083632u: goto P_0c083632;
case 0x0c083634u: goto P_0c083634;
case 0x0c083636u: goto P_0c083636;
case 0x0c083638u: goto P_0c083638;
case 0x0c08363au: goto P_0c08363a;
case 0x0c08363cu: goto P_0c08363c;
case 0x0c08363eu: goto P_0c08363e;
case 0x0c083640u: goto P_0c083640;
case 0x0c083642u: goto P_0c083642;
case 0x0c083644u: goto P_0c083644;
case 0x0c083646u: goto P_0c083646;
case 0x0c083648u: goto P_0c083648;
case 0x0c08364au: goto P_0c08364a;
case 0x0c08364cu: goto P_0c08364c;
case 0x0c08364eu: goto P_0c08364e;
case 0x0c083650u: goto P_0c083650;
case 0x0c083652u: goto P_0c083652;
case 0x0c083654u: goto P_0c083654;
case 0x0c083656u: goto P_0c083656;
case 0x0c083658u: goto P_0c083658;
case 0x0c08365au: goto P_0c08365a;
case 0x0c08365cu: goto P_0c08365c;
case 0x0c08365eu: goto P_0c08365e;
case 0x0c083660u: goto P_0c083660;
case 0x0c083662u: goto P_0c083662;
case 0x0c083664u: goto P_0c083664;
case 0x0c083666u: goto P_0c083666;
case 0x0c083668u: goto P_0c083668;
case 0x0c08366au: goto P_0c08366a;
case 0x0c08366cu: goto P_0c08366c;
case 0x0c08366eu: goto P_0c08366e;
case 0x0c083670u: goto P_0c083670;
case 0x0c083672u: goto P_0c083672;
case 0x0c083674u: goto P_0c083674;
case 0x0c083676u: goto P_0c083676;
case 0x0c083678u: goto P_0c083678;
case 0x0c08367au: goto P_0c08367a;
case 0x0c08367cu: goto P_0c08367c;
case 0x0c08367eu: goto P_0c08367e;
case 0x0c083680u: goto P_0c083680;
case 0x0c083682u: goto P_0c083682;
case 0x0c083684u: goto P_0c083684;
case 0x0c083686u: goto P_0c083686;
case 0x0c083688u: goto P_0c083688;
case 0x0c08368au: goto P_0c08368a;
case 0x0c08368cu: goto P_0c08368c;
case 0x0c08368eu: goto P_0c08368e;
case 0x0c083690u: goto P_0c083690;
case 0x0c083692u: goto P_0c083692;
case 0x0c083694u: goto P_0c083694;
case 0x0c083696u: goto P_0c083696;
case 0x0c083698u: goto P_0c083698;
case 0x0c08369au: goto P_0c08369a;
case 0x0c08369cu: goto P_0c08369c;
case 0x0c08369eu: goto P_0c08369e;
case 0x0c0836a0u: goto P_0c0836a0;
case 0x0c0836a2u: goto P_0c0836a2;
case 0x0c0836a4u: goto P_0c0836a4;
case 0x0c0836a6u: goto P_0c0836a6;
case 0x0c0836a8u: goto P_0c0836a8;
case 0x0c0836aau: goto P_0c0836aa;
case 0x0c0836acu: goto P_0c0836ac;
case 0x0c0836aeu: goto P_0c0836ae;
case 0x0c0836b0u: goto P_0c0836b0;
case 0x0c0836b2u: goto P_0c0836b2;
case 0x0c0836b4u: goto P_0c0836b4;
case 0x0c0836b6u: goto P_0c0836b6;
case 0x0c0836b8u: goto P_0c0836b8;
case 0x0c0836bau: goto P_0c0836ba;
case 0x0c0836bcu: goto P_0c0836bc;
case 0x0c0836beu: goto P_0c0836be;
case 0x0c0836c0u: goto P_0c0836c0;
case 0x0c0836c2u: goto P_0c0836c2;
case 0x0c0836c4u: goto P_0c0836c4;
case 0x0c0836c6u: goto P_0c0836c6;
case 0x0c0836c8u: goto P_0c0836c8;
case 0x0c0836cau: goto P_0c0836ca;
case 0x0c0836ccu: goto P_0c0836cc;
case 0x0c0836ceu: goto P_0c0836ce;
case 0x0c0836d0u: goto P_0c0836d0;
case 0x0c0836d2u: goto P_0c0836d2;
case 0x0c0836d4u: goto P_0c0836d4;
case 0x0c0836f0u: goto P_0c0836f0;
case 0x0c0836f2u: goto P_0c0836f2;
case 0x0c0836f4u: goto P_0c0836f4;
case 0x0c0836f6u: goto P_0c0836f6;
case 0x0c0836f8u: goto P_0c0836f8;
case 0x0c0836fau: goto P_0c0836fa;
case 0x0c0836fcu: goto P_0c0836fc;
case 0x0c0836feu: goto P_0c0836fe;
case 0x0c083700u: goto P_0c083700;
case 0x0c083702u: goto P_0c083702;
case 0x0c083704u: goto P_0c083704;
case 0x0c083706u: goto P_0c083706;
case 0x0c083708u: goto P_0c083708;
case 0x0c08370au: goto P_0c08370a;
case 0x0c08370cu: goto P_0c08370c;
case 0x0c08370eu: goto P_0c08370e;
case 0x0c083710u: goto P_0c083710;
case 0x0c083712u: goto P_0c083712;
case 0x0c083714u: goto P_0c083714;
case 0x0c083716u: goto P_0c083716;
case 0x0c083718u: goto P_0c083718;
case 0x0c08371au: goto P_0c08371a;
case 0x0c08371cu: goto P_0c08371c;
case 0x0c08371eu: goto P_0c08371e;
case 0x0c083720u: goto P_0c083720;
case 0x0c083722u: goto P_0c083722;
case 0x0c083724u: goto P_0c083724;
case 0x0c083726u: goto P_0c083726;
case 0x0c083728u: goto P_0c083728;
case 0x0c08372au: goto P_0c08372a;
case 0x0c08372cu: goto P_0c08372c;
case 0x0c08372eu: goto P_0c08372e;
case 0x0c083730u: goto P_0c083730;
case 0x0c083732u: goto P_0c083732;
case 0x0c083734u: goto P_0c083734;
case 0x0c083736u: goto P_0c083736;
case 0x0c083738u: goto P_0c083738;
case 0x0c08373au: goto P_0c08373a;
case 0x0c08373cu: goto P_0c08373c;
case 0x0c08373eu: goto P_0c08373e;
case 0x0c083740u: goto P_0c083740;
case 0x0c083742u: goto P_0c083742;
case 0x0c083744u: goto P_0c083744;
case 0x0c083746u: goto P_0c083746;
case 0x0c083748u: goto P_0c083748;
case 0x0c08374au: goto P_0c08374a;
case 0x0c08374cu: goto P_0c08374c;
case 0x0c08374eu: goto P_0c08374e;
case 0x0c083750u: goto P_0c083750;
case 0x0c083752u: goto P_0c083752;
case 0x0c083754u: goto P_0c083754;
case 0x0c083756u: goto P_0c083756;
case 0x0c083758u: goto P_0c083758;
case 0x0c08375au: goto P_0c08375a;
case 0x0c08375cu: goto P_0c08375c;
case 0x0c08375eu: goto P_0c08375e;
case 0x0c083760u: goto P_0c083760;
case 0x0c083762u: goto P_0c083762;
case 0x0c083764u: goto P_0c083764;
case 0x0c083766u: goto P_0c083766;
case 0x0c083768u: goto P_0c083768;
case 0x0c08376au: goto P_0c08376a;
case 0x0c08376cu: goto P_0c08376c;
case 0x0c08376eu: goto P_0c08376e;
case 0x0c083770u: goto P_0c083770;
case 0x0c083772u: goto P_0c083772;
case 0x0c083774u: goto P_0c083774;
case 0x0c083776u: goto P_0c083776;
case 0x0c083778u: goto P_0c083778;
case 0x0c08377au: goto P_0c08377a;
case 0x0c08377cu: goto P_0c08377c;
case 0x0c08377eu: goto P_0c08377e;
case 0x0c083780u: goto P_0c083780;
case 0x0c083782u: goto P_0c083782;
case 0x0c083784u: goto P_0c083784;
case 0x0c083786u: goto P_0c083786;
case 0x0c083788u: goto P_0c083788;
case 0x0c08378au: goto P_0c08378a;
case 0x0c08378cu: goto P_0c08378c;
case 0x0c08378eu: goto P_0c08378e;
case 0x0c083790u: goto P_0c083790;
case 0x0c083792u: goto P_0c083792;
case 0x0c083794u: goto P_0c083794;
case 0x0c083796u: goto P_0c083796;
case 0x0c083798u: goto P_0c083798;
case 0x0c08379au: goto P_0c08379a;
case 0x0c08379cu: goto P_0c08379c;
case 0x0c08379eu: goto P_0c08379e;
case 0x0c0837a0u: goto P_0c0837a0;
case 0x0c0837a2u: goto P_0c0837a2;
case 0x0c0837a4u: goto P_0c0837a4;
case 0x0c0837a6u: goto P_0c0837a6;
case 0x0c0837a8u: goto P_0c0837a8;
case 0x0c0837aau: goto P_0c0837aa;
case 0x0c0837acu: goto P_0c0837ac;
case 0x0c0837aeu: goto P_0c0837ae;
case 0x0c0837b0u: goto P_0c0837b0;
case 0x0c0837b2u: goto P_0c0837b2;
case 0x0c0837b4u: goto P_0c0837b4;
case 0x0c0837b6u: goto P_0c0837b6;
case 0x0c0837b8u: goto P_0c0837b8;
case 0x0c0837bau: goto P_0c0837ba;
case 0x0c0837bcu: goto P_0c0837bc;
case 0x0c0837beu: goto P_0c0837be;
case 0x0c0837c0u: goto P_0c0837c0;
case 0x0c0837c2u: goto P_0c0837c2;
case 0x0c0837c4u: goto P_0c0837c4;
case 0x0c0837c6u: goto P_0c0837c6;
case 0x0c0837c8u: goto P_0c0837c8;
case 0x0c0837cau: goto P_0c0837ca;
case 0x0c0837ccu: goto P_0c0837cc;
case 0x0c0837ceu: goto P_0c0837ce;
case 0x0c0837d0u: goto P_0c0837d0;
case 0x0c0837d2u: goto P_0c0837d2;
case 0x0c0837d4u: goto P_0c0837d4;
case 0x0c0837d6u: goto P_0c0837d6;
case 0x0c0837d8u: goto P_0c0837d8;
case 0x0c0837dau: goto P_0c0837da;
case 0x0c0837dcu: goto P_0c0837dc;
case 0x0c0837deu: goto P_0c0837de;
case 0x0c0837e0u: goto P_0c0837e0;
case 0x0c0837e2u: goto P_0c0837e2;
case 0x0c0837e4u: goto P_0c0837e4;
case 0x0c0837e6u: goto P_0c0837e6;
case 0x0c0837e8u: goto P_0c0837e8;
case 0x0c0837eau: goto P_0c0837ea;
case 0x0c0837ecu: goto P_0c0837ec;
case 0x0c0837eeu: goto P_0c0837ee;
case 0x0c0837f0u: goto P_0c0837f0;
case 0x0c08380cu: goto P_0c08380c;
case 0x0c08380eu: goto P_0c08380e;
case 0x0c083810u: goto P_0c083810;
case 0x0c083812u: goto P_0c083812;
case 0x0c083814u: goto P_0c083814;
case 0x0c083816u: goto P_0c083816;
case 0x0c083818u: goto P_0c083818;
case 0x0c08381au: goto P_0c08381a;
case 0x0c08381cu: goto P_0c08381c;
case 0x0c08381eu: goto P_0c08381e;
case 0x0c083820u: goto P_0c083820;
case 0x0c083822u: goto P_0c083822;
case 0x0c083824u: goto P_0c083824;
case 0x0c083826u: goto P_0c083826;
case 0x0c083828u: goto P_0c083828;
case 0x0c08382au: goto P_0c08382a;
case 0x0c08382cu: goto P_0c08382c;
case 0x0c08382eu: goto P_0c08382e;
case 0x0c083830u: goto P_0c083830;
case 0x0c083832u: goto P_0c083832;
case 0x0c083834u: goto P_0c083834;
case 0x0c083836u: goto P_0c083836;
case 0x0c083838u: goto P_0c083838;
case 0x0c08383au: goto P_0c08383a;
case 0x0c08383cu: goto P_0c08383c;
case 0x0c08383eu: goto P_0c08383e;
case 0x0c083840u: goto P_0c083840;
case 0x0c083842u: goto P_0c083842;
case 0x0c083844u: goto P_0c083844;
case 0x0c083846u: goto P_0c083846;
case 0x0c083848u: goto P_0c083848;
case 0x0c08384au: goto P_0c08384a;
case 0x0c08384cu: goto P_0c08384c;
case 0x0c08384eu: goto P_0c08384e;
case 0x0c083850u: goto P_0c083850;
case 0x0c083852u: goto P_0c083852;
case 0x0c083854u: goto P_0c083854;
case 0x0c083856u: goto P_0c083856;
case 0x0c083858u: goto P_0c083858;
case 0x0c08385au: goto P_0c08385a;
case 0x0c08385cu: goto P_0c08385c;
case 0x0c08385eu: goto P_0c08385e;
case 0x0c083860u: goto P_0c083860;
case 0x0c083862u: goto P_0c083862;
case 0x0c083864u: goto P_0c083864;
case 0x0c083866u: goto P_0c083866;
case 0x0c083868u: goto P_0c083868;
case 0x0c08386au: goto P_0c08386a;
case 0x0c08386cu: goto P_0c08386c;
case 0x0c08386eu: goto P_0c08386e;
case 0x0c083870u: goto P_0c083870;
case 0x0c083872u: goto P_0c083872;
case 0x0c083874u: goto P_0c083874;
case 0x0c083876u: goto P_0c083876;
case 0x0c083878u: goto P_0c083878;
case 0x0c08387au: goto P_0c08387a;
case 0x0c08387cu: goto P_0c08387c;
case 0x0c08387eu: goto P_0c08387e;
case 0x0c083880u: goto P_0c083880;
case 0x0c083882u: goto P_0c083882;
case 0x0c083884u: goto P_0c083884;
case 0x0c083886u: goto P_0c083886;
case 0x0c083888u: goto P_0c083888;
case 0x0c08388au: goto P_0c08388a;
case 0x0c08388cu: goto P_0c08388c;
case 0x0c08388eu: goto P_0c08388e;
case 0x0c083890u: goto P_0c083890;
case 0x0c083892u: goto P_0c083892;
case 0x0c083894u: goto P_0c083894;
case 0x0c083896u: goto P_0c083896;
case 0x0c083898u: goto P_0c083898;
case 0x0c08389au: goto P_0c08389a;
case 0x0c08389cu: goto P_0c08389c;
case 0x0c08389eu: goto P_0c08389e;
case 0x0c0838a0u: goto P_0c0838a0;
case 0x0c0838a2u: goto P_0c0838a2;
case 0x0c0838a4u: goto P_0c0838a4;
case 0x0c0838a6u: goto P_0c0838a6;
case 0x0c0838a8u: goto P_0c0838a8;
case 0x0c0838aau: goto P_0c0838aa;
case 0x0c0838acu: goto P_0c0838ac;
case 0x0c0838aeu: goto P_0c0838ae;
case 0x0c0838b0u: goto P_0c0838b0;
case 0x0c0838b2u: goto P_0c0838b2;
case 0x0c0838b4u: goto P_0c0838b4;
case 0x0c0838b6u: goto P_0c0838b6;
case 0x0c0838b8u: goto P_0c0838b8;
case 0x0c0838bau: goto P_0c0838ba;
case 0x0c0838bcu: goto P_0c0838bc;
case 0x0c0838beu: goto P_0c0838be;
case 0x0c0838c0u: goto P_0c0838c0;
case 0x0c0838c2u: goto P_0c0838c2;
case 0x0c0838c4u: goto P_0c0838c4;
case 0x0c0838c6u: goto P_0c0838c6;
case 0x0c0838c8u: goto P_0c0838c8;
case 0x0c0838cau: goto P_0c0838ca;
case 0x0c0838ccu: goto P_0c0838cc;
case 0x0c0838ceu: goto P_0c0838ce;
case 0x0c0838d0u: goto P_0c0838d0;
case 0x0c0838d2u: goto P_0c0838d2;
case 0x0c0838d4u: goto P_0c0838d4;
case 0x0c0838d6u: goto P_0c0838d6;
case 0x0c0838f0u: goto P_0c0838f0;
case 0x0c0838f2u: goto P_0c0838f2;
case 0x0c0838f4u: goto P_0c0838f4;
case 0x0c0838f6u: goto P_0c0838f6;
case 0x0c0838f8u: goto P_0c0838f8;
case 0x0c0838fau: goto P_0c0838fa;
case 0x0c0838fcu: goto P_0c0838fc;
case 0x0c0838feu: goto P_0c0838fe;
case 0x0c083900u: goto P_0c083900;
case 0x0c083902u: goto P_0c083902;
case 0x0c083904u: goto P_0c083904;
case 0x0c083906u: goto P_0c083906;
case 0x0c083908u: goto P_0c083908;
case 0x0c08390au: goto P_0c08390a;
case 0x0c08390cu: goto P_0c08390c;
case 0x0c08390eu: goto P_0c08390e;
case 0x0c083910u: goto P_0c083910;
case 0x0c083912u: goto P_0c083912;
case 0x0c083914u: goto P_0c083914;
case 0x0c083916u: goto P_0c083916;
case 0x0c083918u: goto P_0c083918;
case 0x0c08391au: goto P_0c08391a;
case 0x0c08391cu: goto P_0c08391c;
case 0x0c08391eu: goto P_0c08391e;
case 0x0c083920u: goto P_0c083920;
case 0x0c083922u: goto P_0c083922;
case 0x0c083924u: goto P_0c083924;
case 0x0c083926u: goto P_0c083926;
case 0x0c083928u: goto P_0c083928;
case 0x0c08392au: goto P_0c08392a;
case 0x0c08392cu: goto P_0c08392c;
case 0x0c08392eu: goto P_0c08392e;
case 0x0c083930u: goto P_0c083930;
case 0x0c083932u: goto P_0c083932;
case 0x0c083934u: goto P_0c083934;
case 0x0c083936u: goto P_0c083936;
case 0x0c083938u: goto P_0c083938;
case 0x0c08393au: goto P_0c08393a;
case 0x0c08393cu: goto P_0c08393c;
case 0x0c08393eu: goto P_0c08393e;
case 0x0c083940u: goto P_0c083940;
case 0x0c083942u: goto P_0c083942;
case 0x0c083944u: goto P_0c083944;
case 0x0c083946u: goto P_0c083946;
case 0x0c083948u: goto P_0c083948;
case 0x0c08394au: goto P_0c08394a;
case 0x0c08394cu: goto P_0c08394c;
case 0x0c08394eu: goto P_0c08394e;
case 0x0c083950u: goto P_0c083950;
case 0x0c083952u: goto P_0c083952;
case 0x0c083954u: goto P_0c083954;
case 0x0c083956u: goto P_0c083956;
case 0x0c083958u: goto P_0c083958;
case 0x0c08395au: goto P_0c08395a;
case 0x0c08395cu: goto P_0c08395c;
case 0x0c08395eu: goto P_0c08395e;
case 0x0c083960u: goto P_0c083960;
case 0x0c083962u: goto P_0c083962;
case 0x0c083964u: goto P_0c083964;
case 0x0c083966u: goto P_0c083966;
case 0x0c083968u: goto P_0c083968;
case 0x0c08396au: goto P_0c08396a;
case 0x0c08396cu: goto P_0c08396c;
case 0x0c08396eu: goto P_0c08396e;
case 0x0c083970u: goto P_0c083970;
case 0x0c083972u: goto P_0c083972;
case 0x0c083974u: goto P_0c083974;
case 0x0c083976u: goto P_0c083976;
case 0x0c083978u: goto P_0c083978;
case 0x0c08397au: goto P_0c08397a;
case 0x0c08397cu: goto P_0c08397c;
case 0x0c08397eu: goto P_0c08397e;
case 0x0c083980u: goto P_0c083980;
case 0x0c083982u: goto P_0c083982;
case 0x0c083984u: goto P_0c083984;
case 0x0c083986u: goto P_0c083986;
case 0x0c083988u: goto P_0c083988;
case 0x0c08398au: goto P_0c08398a;
case 0x0c08398cu: goto P_0c08398c;
case 0x0c08398eu: goto P_0c08398e;
case 0x0c083990u: goto P_0c083990;
case 0x0c083992u: goto P_0c083992;
case 0x0c083994u: goto P_0c083994;
case 0x0c083996u: goto P_0c083996;
case 0x0c083998u: goto P_0c083998;
case 0x0c08399au: goto P_0c08399a;
case 0x0c08399cu: goto P_0c08399c;
case 0x0c08399eu: goto P_0c08399e;
case 0x0c0839a0u: goto P_0c0839a0;
case 0x0c0839a2u: goto P_0c0839a2;
case 0x0c0839a4u: goto P_0c0839a4;
case 0x0c0839a6u: goto P_0c0839a6;
case 0x0c0839a8u: goto P_0c0839a8;
case 0x0c0839aau: goto P_0c0839aa;
case 0x0c0839acu: goto P_0c0839ac;
case 0x0c0839aeu: goto P_0c0839ae;
case 0x0c0839b0u: goto P_0c0839b0;
case 0x0c0839b2u: goto P_0c0839b2;
case 0x0c0839b4u: goto P_0c0839b4;
case 0x0c0839b6u: goto P_0c0839b6;
case 0x0c0839b8u: goto P_0c0839b8;
case 0x0c0839bau: goto P_0c0839ba;
case 0x0c0839bcu: goto P_0c0839bc;
case 0x0c0839beu: goto P_0c0839be;
case 0x0c0839c0u: goto P_0c0839c0;
case 0x0c0839c2u: goto P_0c0839c2;
case 0x0c0839c4u: goto P_0c0839c4;
case 0x0c0839c6u: goto P_0c0839c6;
case 0x0c0839c8u: goto P_0c0839c8;
case 0x0c0839cau: goto P_0c0839ca;
case 0x0c0839ccu: goto P_0c0839cc;
case 0x0c0839ceu: goto P_0c0839ce;
case 0x0c0839d0u: goto P_0c0839d0;
case 0x0c0839d2u: goto P_0c0839d2;
case 0x0c0839d4u: goto P_0c0839d4;
case 0x0c0839d6u: goto P_0c0839d6;
case 0x0c0839d8u: goto P_0c0839d8;
case 0x0c0839dau: goto P_0c0839da;
case 0x0c0839dcu: goto P_0c0839dc;
case 0x0c0839deu: goto P_0c0839de;
case 0x0c0839e0u: goto P_0c0839e0;
case 0x0c0839e2u: goto P_0c0839e2;
case 0x0c0839e4u: goto P_0c0839e4;
case 0x0c0839e6u: goto P_0c0839e6;
case 0x0c0839e8u: goto P_0c0839e8;
case 0x0c0839eau: goto P_0c0839ea;
case 0x0c0839ecu: goto P_0c0839ec;
case 0x0c0839eeu: goto P_0c0839ee;
case 0x0c0839f0u: goto P_0c0839f0;
case 0x0c0839f2u: goto P_0c0839f2;
case 0x0c0839f4u: goto P_0c0839f4;
case 0x0c0839f6u: goto P_0c0839f6;
case 0x0c0839f8u: goto P_0c0839f8;
case 0x0c0839fau: goto P_0c0839fa;
case 0x0c0839fcu: goto P_0c0839fc;
case 0x0c0839feu: goto P_0c0839fe;
case 0x0c083a00u: goto P_0c083a00;
case 0x0c083a02u: goto P_0c083a02;
case 0x0c083a04u: goto P_0c083a04;
case 0x0c083a24u: goto P_0c083a24;
case 0x0c083a26u: goto P_0c083a26;
case 0x0c083a28u: goto P_0c083a28;
case 0x0c083a2au: goto P_0c083a2a;
case 0x0c083a2cu: goto P_0c083a2c;
case 0x0c083a2eu: goto P_0c083a2e;
case 0x0c083a30u: goto P_0c083a30;
case 0x0c083a32u: goto P_0c083a32;
case 0x0c083a34u: goto P_0c083a34;
case 0x0c083a36u: goto P_0c083a36;
case 0x0c083a38u: goto P_0c083a38;
case 0x0c083a3au: goto P_0c083a3a;
case 0x0c083a3cu: goto P_0c083a3c;
case 0x0c083a3eu: goto P_0c083a3e;
case 0x0c083a40u: goto P_0c083a40;
case 0x0c083a42u: goto P_0c083a42;
case 0x0c083a44u: goto P_0c083a44;
case 0x0c083a46u: goto P_0c083a46;
case 0x0c083a48u: goto P_0c083a48;
case 0x0c083a4au: goto P_0c083a4a;
case 0x0c083a4cu: goto P_0c083a4c;
case 0x0c083a4eu: goto P_0c083a4e;
case 0x0c083a50u: goto P_0c083a50;
case 0x0c083a52u: goto P_0c083a52;
case 0x0c083a54u: goto P_0c083a54;
case 0x0c083a56u: goto P_0c083a56;
case 0x0c083a58u: goto P_0c083a58;
case 0x0c083a5au: goto P_0c083a5a;
case 0x0c083a5cu: goto P_0c083a5c;
case 0x0c083a5eu: goto P_0c083a5e;
case 0x0c083a60u: goto P_0c083a60;
case 0x0c083a62u: goto P_0c083a62;
case 0x0c083a64u: goto P_0c083a64;
case 0x0c083a66u: goto P_0c083a66;
case 0x0c083a68u: goto P_0c083a68;
case 0x0c083a6au: goto P_0c083a6a;
case 0x0c083a6cu: goto P_0c083a6c;
case 0x0c083a6eu: goto P_0c083a6e;
case 0x0c083a70u: goto P_0c083a70;
case 0x0c083a72u: goto P_0c083a72;
case 0x0c083a74u: goto P_0c083a74;
case 0x0c083a76u: goto P_0c083a76;
case 0x0c083a78u: goto P_0c083a78;
case 0x0c083a7au: goto P_0c083a7a;
case 0x0c083a7cu: goto P_0c083a7c;
case 0x0c083a7eu: goto P_0c083a7e;
case 0x0c083a80u: goto P_0c083a80;
case 0x0c083a82u: goto P_0c083a82;
case 0x0c083a84u: goto P_0c083a84;
case 0x0c083a86u: goto P_0c083a86;
case 0x0c083a88u: goto P_0c083a88;
case 0x0c083a8au: goto P_0c083a8a;
case 0x0c083a8cu: goto P_0c083a8c;
case 0x0c083a8eu: goto P_0c083a8e;
case 0x0c083a90u: goto P_0c083a90;
case 0x0c083a92u: goto P_0c083a92;
case 0x0c083a94u: goto P_0c083a94;
case 0x0c083a96u: goto P_0c083a96;
case 0x0c083aa8u: goto P_0c083aa8;
case 0x0c083aaau: goto P_0c083aaa;
case 0x0c083aacu: goto P_0c083aac;
case 0x0c083aaeu: goto P_0c083aae;
case 0x0c083ab0u: goto P_0c083ab0;
case 0x0c083ab2u: goto P_0c083ab2;
case 0x0c083ab4u: goto P_0c083ab4;
case 0x0c083ab6u: goto P_0c083ab6;
case 0x0c083ab8u: goto P_0c083ab8;
case 0x0c083abau: goto P_0c083aba;
case 0x0c083abcu: goto P_0c083abc;
case 0x0c083abeu: goto P_0c083abe;
case 0x0c083ac0u: goto P_0c083ac0;
case 0x0c083ac2u: goto P_0c083ac2;
case 0x0c083ac4u: goto P_0c083ac4;
case 0x0c083ac6u: goto P_0c083ac6;
case 0x0c083ac8u: goto P_0c083ac8;
case 0x0c083acau: goto P_0c083aca;
case 0x0c083accu: goto P_0c083acc;
case 0x0c083aceu: goto P_0c083ace;
case 0x0c083ad0u: goto P_0c083ad0;
case 0x0c083ad2u: goto P_0c083ad2;
case 0x0c083ad4u: goto P_0c083ad4;
case 0x0c083ad6u: goto P_0c083ad6;
case 0x0c083ad8u: goto P_0c083ad8;
case 0x0c083adau: goto P_0c083ada;
case 0x0c083adcu: goto P_0c083adc;
case 0x0c083adeu: goto P_0c083ade;
case 0x0c083ae0u: goto P_0c083ae0;
case 0x0c083ae2u: goto P_0c083ae2;
case 0x0c083ae4u: goto P_0c083ae4;
case 0x0c083ae6u: goto P_0c083ae6;
case 0x0c083ae8u: goto P_0c083ae8;
case 0x0c083aeau: goto P_0c083aea;
case 0x0c083aecu: goto P_0c083aec;
case 0x0c083aeeu: goto P_0c083aee;
case 0x0c083af0u: goto P_0c083af0;
case 0x0c083af2u: goto P_0c083af2;
case 0x0c083af4u: goto P_0c083af4;
case 0x0c083af6u: goto P_0c083af6;
case 0x0c083af8u: goto P_0c083af8;
case 0x0c083afau: goto P_0c083afa;
case 0x0c083afcu: goto P_0c083afc;
case 0x0c083afeu: goto P_0c083afe;
case 0x0c083b00u: goto P_0c083b00;
case 0x0c083b02u: goto P_0c083b02;
case 0x0c083b04u: goto P_0c083b04;
case 0x0c083b06u: goto P_0c083b06;
case 0x0c083b08u: goto P_0c083b08;
case 0x0c083b0au: goto P_0c083b0a;
case 0x0c083b0cu: goto P_0c083b0c;
case 0x0c083b0eu: goto P_0c083b0e;
case 0x0c083b10u: goto P_0c083b10;
case 0x0c083b12u: goto P_0c083b12;
case 0x0c083b14u: goto P_0c083b14;
case 0x0c083b16u: goto P_0c083b16;
case 0x0c083b18u: goto P_0c083b18;
case 0x0c083b1au: goto P_0c083b1a;
case 0x0c083b1cu: goto P_0c083b1c;
case 0x0c083b1eu: goto P_0c083b1e;
case 0x0c083b20u: goto P_0c083b20;
case 0x0c083b22u: goto P_0c083b22;
case 0x0c083b24u: goto P_0c083b24;
case 0x0c083b26u: goto P_0c083b26;
case 0x0c083b28u: goto P_0c083b28;
case 0x0c083b2au: goto P_0c083b2a;
case 0x0c083b2cu: goto P_0c083b2c;
case 0x0c083b2eu: goto P_0c083b2e;
case 0x0c083b30u: goto P_0c083b30;
case 0x0c083b32u: goto P_0c083b32;
case 0x0c083b34u: goto P_0c083b34;
case 0x0c083b36u: goto P_0c083b36;
case 0x0c083b38u: goto P_0c083b38;
case 0x0c083b3au: goto P_0c083b3a;
case 0x0c083b78u: goto P_0c083b78;
case 0x0c083b7au: goto P_0c083b7a;
case 0x0c083b7cu: goto P_0c083b7c;
case 0x0c083b7eu: goto P_0c083b7e;
case 0x0c083b80u: goto P_0c083b80;
case 0x0c083b82u: goto P_0c083b82;
case 0x0c083b84u: goto P_0c083b84;
case 0x0c083b86u: goto P_0c083b86;
case 0x0c083b88u: goto P_0c083b88;
case 0x0c083b8au: goto P_0c083b8a;
case 0x0c083b8cu: goto P_0c083b8c;
case 0x0c083b8eu: goto P_0c083b8e;
case 0x0c083b90u: goto P_0c083b90;
case 0x0c083b92u: goto P_0c083b92;
case 0x0c083b94u: goto P_0c083b94;
case 0x0c083b96u: goto P_0c083b96;
case 0x0c083b98u: goto P_0c083b98;
case 0x0c083b9au: goto P_0c083b9a;
case 0x0c083b9cu: goto P_0c083b9c;
case 0x0c083b9eu: goto P_0c083b9e;
case 0x0c083ba0u: goto P_0c083ba0;
case 0x0c083ba2u: goto P_0c083ba2;
case 0x0c083ba4u: goto P_0c083ba4;
case 0x0c083ba6u: goto P_0c083ba6;
case 0x0c083ba8u: goto P_0c083ba8;
case 0x0c083baau: goto P_0c083baa;
case 0x0c083bacu: goto P_0c083bac;
case 0x0c083baeu: goto P_0c083bae;
case 0x0c083bb0u: goto P_0c083bb0;
case 0x0c083bb2u: goto P_0c083bb2;
case 0x0c083bb4u: goto P_0c083bb4;
case 0x0c083bb6u: goto P_0c083bb6;
case 0x0c083bb8u: goto P_0c083bb8;
case 0x0c083bbau: goto P_0c083bba;
case 0x0c083bbcu: goto P_0c083bbc;
case 0x0c083bbeu: goto P_0c083bbe;
case 0x0c083bc0u: goto P_0c083bc0;
case 0x0c083bc2u: goto P_0c083bc2;
case 0x0c083bc4u: goto P_0c083bc4;
case 0x0c083bc6u: goto P_0c083bc6;
case 0x0c083bc8u: goto P_0c083bc8;
case 0x0c083bcau: goto P_0c083bca;
case 0x0c083bccu: goto P_0c083bcc;
case 0x0c083bceu: goto P_0c083bce;
case 0x0c083bd0u: goto P_0c083bd0;
case 0x0c083bd2u: goto P_0c083bd2;
case 0x0c083bd4u: goto P_0c083bd4;
case 0x0c083bd6u: goto P_0c083bd6;
case 0x0c083bd8u: goto P_0c083bd8;
case 0x0c083bdau: goto P_0c083bda;
case 0x0c083bdcu: goto P_0c083bdc;
case 0x0c083bdeu: goto P_0c083bde;
case 0x0c083be0u: goto P_0c083be0;
case 0x0c083be2u: goto P_0c083be2;
case 0x0c083be4u: goto P_0c083be4;
case 0x0c083be6u: goto P_0c083be6;
case 0x0c083be8u: goto P_0c083be8;
case 0x0c083beau: goto P_0c083bea;
case 0x0c083becu: goto P_0c083bec;
case 0x0c083beeu: goto P_0c083bee;
case 0x0c083bf0u: goto P_0c083bf0;
case 0x0c083bf2u: goto P_0c083bf2;
case 0x0c083bf4u: goto P_0c083bf4;
case 0x0c083bf6u: goto P_0c083bf6;
case 0x0c083bf8u: goto P_0c083bf8;
case 0x0c083bfau: goto P_0c083bfa;
case 0x0c083bfcu: goto P_0c083bfc;
case 0x0c083bfeu: goto P_0c083bfe;
case 0x0c083c00u: goto P_0c083c00;
case 0x0c083c02u: goto P_0c083c02;
case 0x0c083c04u: goto P_0c083c04;
case 0x0c083c06u: goto P_0c083c06;
case 0x0c083c08u: goto P_0c083c08;
case 0x0c083c0au: goto P_0c083c0a;
case 0x0c083c0cu: goto P_0c083c0c;
case 0x0c083c0eu: goto P_0c083c0e;
case 0x0c083c10u: goto P_0c083c10;
case 0x0c083c12u: goto P_0c083c12;
case 0x0c083c14u: goto P_0c083c14;
case 0x0c083c16u: goto P_0c083c16;
case 0x0c083c18u: goto P_0c083c18;
case 0x0c083c1au: goto P_0c083c1a;
case 0x0c083c1cu: goto P_0c083c1c;
case 0x0c083c1eu: goto P_0c083c1e;
case 0x0c083c20u: goto P_0c083c20;
case 0x0c083c22u: goto P_0c083c22;
case 0x0c083c24u: goto P_0c083c24;
case 0x0c083c26u: goto P_0c083c26;
case 0x0c083c28u: goto P_0c083c28;
case 0x0c083c2au: goto P_0c083c2a;
case 0x0c083c2cu: goto P_0c083c2c;
case 0x0c083c2eu: goto P_0c083c2e;
case 0x0c083c30u: goto P_0c083c30;
case 0x0c083c32u: goto P_0c083c32;
case 0x0c083c34u: goto P_0c083c34;
case 0x0c083c36u: goto P_0c083c36;
case 0x0c083c38u: goto P_0c083c38;
case 0x0c083c3au: goto P_0c083c3a;
case 0x0c083c3cu: goto P_0c083c3c;
case 0x0c083c3eu: goto P_0c083c3e;
case 0x0c083c40u: goto P_0c083c40;
case 0x0c083c42u: goto P_0c083c42;
case 0x0c083c44u: goto P_0c083c44;
case 0x0c083c46u: goto P_0c083c46;
case 0x0c083c48u: goto P_0c083c48;
case 0x0c083c4au: goto P_0c083c4a;
case 0x0c083c4cu: goto P_0c083c4c;
case 0x0c083c4eu: goto P_0c083c4e;
case 0x0c083c50u: goto P_0c083c50;
case 0x0c083c52u: goto P_0c083c52;
case 0x0c083c54u: goto P_0c083c54;
case 0x0c0853feu: goto P_0c0853fe;
case 0x0c085400u: goto P_0c085400;
case 0x0c085402u: goto P_0c085402;
case 0x0c085404u: goto P_0c085404;
case 0x0c085406u: goto P_0c085406;
case 0x0c085408u: goto P_0c085408;
case 0x0c08540au: goto P_0c08540a;
case 0x0c08540cu: goto P_0c08540c;
case 0x0c08540eu: goto P_0c08540e;
case 0x0c085410u: goto P_0c085410;
case 0x0c085412u: goto P_0c085412;
case 0x0c085414u: goto P_0c085414;
case 0x0c085416u: goto P_0c085416;
case 0x0c085418u: goto P_0c085418;
case 0x0c08541au: goto P_0c08541a;
case 0x0c08541cu: goto P_0c08541c;
case 0x0c08541eu: goto P_0c08541e;
case 0x0c085420u: goto P_0c085420;
case 0x0c085422u: goto P_0c085422;
case 0x0c085424u: goto P_0c085424;
case 0x0c085426u: goto P_0c085426;
case 0x0c085428u: goto P_0c085428;
case 0x0c08542au: goto P_0c08542a;
case 0x0c08542cu: goto P_0c08542c;
case 0x0c08542eu: goto P_0c08542e;
case 0x0c085430u: goto P_0c085430;
case 0x0c085432u: goto P_0c085432;
case 0x0c085434u: goto P_0c085434;
case 0x0c085436u: goto P_0c085436;
case 0x0c085438u: goto P_0c085438;
case 0x0c08543au: goto P_0c08543a;
case 0x0c08543cu: goto P_0c08543c;
case 0x0c08543eu: goto P_0c08543e;
case 0x0c085440u: goto P_0c085440;
case 0x0c085442u: goto P_0c085442;
case 0x0c085444u: goto P_0c085444;
case 0x0c085446u: goto P_0c085446;
case 0x0c085448u: goto P_0c085448;
case 0x0c08544au: goto P_0c08544a;
case 0x0c08544cu: goto P_0c08544c;
case 0x0c08544eu: goto P_0c08544e;
case 0x0c085450u: goto P_0c085450;
case 0x0c085452u: goto P_0c085452;
case 0x0c085480u: goto P_0c085480;
case 0x0c085482u: goto P_0c085482;
case 0x0c085484u: goto P_0c085484;
case 0x0c085486u: goto P_0c085486;
case 0x0c085488u: goto P_0c085488;
case 0x0c08548au: goto P_0c08548a;
case 0x0c08548cu: goto P_0c08548c;
case 0x0c08548eu: goto P_0c08548e;
case 0x0c085490u: goto P_0c085490;
case 0x0c085492u: goto P_0c085492;
case 0x0c085494u: goto P_0c085494;
case 0x0c085496u: goto P_0c085496;
case 0x0c085498u: goto P_0c085498;
case 0x0c08549au: goto P_0c08549a;
case 0x0c08549cu: goto P_0c08549c;
case 0x0c08549eu: goto P_0c08549e;
case 0x0c0854a0u: goto P_0c0854a0;
case 0x0c0854a2u: goto P_0c0854a2;
case 0x0c0854a4u: goto P_0c0854a4;
case 0x0c0854a6u: goto P_0c0854a6;
case 0x0c0854a8u: goto P_0c0854a8;
case 0x0c0854aau: goto P_0c0854aa;
case 0x0c0854acu: goto P_0c0854ac;
case 0x0c0854aeu: goto P_0c0854ae;
case 0x0c0854b0u: goto P_0c0854b0;
case 0x0c0854b2u: goto P_0c0854b2;
case 0x0c0854b4u: goto P_0c0854b4;
case 0x0c0854b6u: goto P_0c0854b6;
case 0x0c0854b8u: goto P_0c0854b8;
case 0x0c0854bau: goto P_0c0854ba;
case 0x0c0854bcu: goto P_0c0854bc;
case 0x0c0854beu: goto P_0c0854be;
case 0x0c0854c0u: goto P_0c0854c0;
case 0x0c0854c2u: goto P_0c0854c2;
case 0x0c0854c4u: goto P_0c0854c4;
case 0x0c0854c6u: goto P_0c0854c6;
case 0x0c0854c8u: goto P_0c0854c8;
case 0x0c0854cau: goto P_0c0854ca;
case 0x0c0854ccu: goto P_0c0854cc;
case 0x0c0854ceu: goto P_0c0854ce;
case 0x0c0854d0u: goto P_0c0854d0;
case 0x0c0854d2u: goto P_0c0854d2;
case 0x0c0854d4u: goto P_0c0854d4;
case 0x0c0854d6u: goto P_0c0854d6;
case 0x0c0854d8u: goto P_0c0854d8;
case 0x0c0854dau: goto P_0c0854da;
case 0x0c0854dcu: goto P_0c0854dc;
case 0x0c0854deu: goto P_0c0854de;
case 0x0c0854e0u: goto P_0c0854e0;
case 0x0c0854e2u: goto P_0c0854e2;
case 0x0c0854e4u: goto P_0c0854e4;
case 0x0c0854e6u: goto P_0c0854e6;
case 0x0c0854e8u: goto P_0c0854e8;
case 0x0c0854eau: goto P_0c0854ea;
case 0x0c0854ecu: goto P_0c0854ec;
case 0x0c0854eeu: goto P_0c0854ee;
case 0x0c0854f0u: goto P_0c0854f0;
case 0x0c0854f2u: goto P_0c0854f2;
case 0x0c0854f4u: goto P_0c0854f4;
case 0x0c0854f6u: goto P_0c0854f6;
case 0x0c0854f8u: goto P_0c0854f8;
case 0x0c0854fau: goto P_0c0854fa;
case 0x0c0854fcu: goto P_0c0854fc;
case 0x0c0854feu: goto P_0c0854fe;
case 0x0c085500u: goto P_0c085500;
case 0x0c085502u: goto P_0c085502;
case 0x0c085504u: goto P_0c085504;
case 0x0c085506u: goto P_0c085506;
case 0x0c085508u: goto P_0c085508;
case 0x0c08550au: goto P_0c08550a;
case 0x0c08550cu: goto P_0c08550c;
case 0x0c08550eu: goto P_0c08550e;
case 0x0c085510u: goto P_0c085510;
case 0x0c085512u: goto P_0c085512;
case 0x0c085514u: goto P_0c085514;
case 0x0c085516u: goto P_0c085516;
case 0x0c085518u: goto P_0c085518;
case 0x0c08551au: goto P_0c08551a;
case 0x0c08551cu: goto P_0c08551c;
case 0x0c08551eu: goto P_0c08551e;
case 0x0c085520u: goto P_0c085520;
case 0x0c085522u: goto P_0c085522;
case 0x0c085524u: goto P_0c085524;
case 0x0c085526u: goto P_0c085526;
case 0x0c085528u: goto P_0c085528;
case 0x0c08552au: goto P_0c08552a;
case 0x0c08552cu: goto P_0c08552c;
case 0x0c08552eu: goto P_0c08552e;
case 0x0c085530u: goto P_0c085530;
case 0x0c085532u: goto P_0c085532;
case 0x0c085534u: goto P_0c085534;
case 0x0c085536u: goto P_0c085536;
case 0x0c085538u: goto P_0c085538;
case 0x0c08553au: goto P_0c08553a;
case 0x0c08553cu: goto P_0c08553c;
case 0x0c08553eu: goto P_0c08553e;
case 0x0c085540u: goto P_0c085540;
case 0x0c085542u: goto P_0c085542;
case 0x0c085544u: goto P_0c085544;
case 0x0c085546u: goto P_0c085546;
case 0x0c085548u: goto P_0c085548;
case 0x0c08554au: goto P_0c08554a;
case 0x0c08554cu: goto P_0c08554c;
case 0x0c08554eu: goto P_0c08554e;
case 0x0c085550u: goto P_0c085550;
case 0x0c085552u: goto P_0c085552;
case 0x0c085554u: goto P_0c085554;
case 0x0c085556u: goto P_0c085556;
case 0x0c085558u: goto P_0c085558;
case 0x0c08555au: goto P_0c08555a;
case 0x0c08555cu: goto P_0c08555c;
case 0x0c08555eu: goto P_0c08555e;
case 0x0c085560u: goto P_0c085560;
case 0x0c085562u: goto P_0c085562;
case 0x0c085564u: goto P_0c085564;
case 0x0c085566u: goto P_0c085566;
case 0x0c085568u: goto P_0c085568;
case 0x0c08556au: goto P_0c08556a;
case 0x0c08556cu: goto P_0c08556c;
case 0x0c08556eu: goto P_0c08556e;
case 0x0c085570u: goto P_0c085570;
case 0x0c085572u: goto P_0c085572;
case 0x0c085574u: goto P_0c085574;
case 0x0c086b3au: goto P_0c086b3a;
case 0x0c086b3cu: goto P_0c086b3c;
case 0x0c086b3eu: goto P_0c086b3e;
case 0x0c086b40u: goto P_0c086b40;
case 0x0c086b42u: goto P_0c086b42;
case 0x0c086b44u: goto P_0c086b44;
case 0x0c086b46u: goto P_0c086b46;
case 0x0c086b48u: goto P_0c086b48;
case 0x0c086b4au: goto P_0c086b4a;
case 0x0c086b4cu: goto P_0c086b4c;
case 0x0c086b4eu: goto P_0c086b4e;
case 0x0c086b50u: goto P_0c086b50;
case 0x0c086b52u: goto P_0c086b52;
case 0x0c086b54u: goto P_0c086b54;
case 0x0c086b56u: goto P_0c086b56;
case 0x0c086b58u: goto P_0c086b58;
case 0x0c086b5au: goto P_0c086b5a;
case 0x0c086b5cu: goto P_0c086b5c;
case 0x0c086b5eu: goto P_0c086b5e;
case 0x0c086b60u: goto P_0c086b60;
case 0x0c086b62u: goto P_0c086b62;
case 0x0c086b64u: goto P_0c086b64;
case 0x0c086b66u: goto P_0c086b66;
case 0x0c086b68u: goto P_0c086b68;
case 0x0c086b6au: goto P_0c086b6a;
case 0x0c086b6cu: goto P_0c086b6c;
case 0x0c086b6eu: goto P_0c086b6e;
case 0x0c086b70u: goto P_0c086b70;
case 0x0c086b72u: goto P_0c086b72;
case 0x0c086b74u: goto P_0c086b74;
case 0x0c086b76u: goto P_0c086b76;
case 0x0c086b78u: goto P_0c086b78;
case 0x0c086b7au: goto P_0c086b7a;
case 0x0c086b7cu: goto P_0c086b7c;
case 0x0c086b7eu: goto P_0c086b7e;
case 0x0c086b80u: goto P_0c086b80;
case 0x0c086b9cu: goto P_0c086b9c;
case 0x0c086b9eu: goto P_0c086b9e;
case 0x0c086ba0u: goto P_0c086ba0;
case 0x0c086ba2u: goto P_0c086ba2;
case 0x0c086ba4u: goto P_0c086ba4;
case 0x0c086ba6u: goto P_0c086ba6;
case 0x0c086ba8u: goto P_0c086ba8;
case 0x0c086baau: goto P_0c086baa;
case 0x0c086bacu: goto P_0c086bac;
case 0x0c086baeu: goto P_0c086bae;
case 0x0c086bb0u: goto P_0c086bb0;
case 0x0c086bb2u: goto P_0c086bb2;
case 0x0c086bb4u: goto P_0c086bb4;
case 0x0c086bb6u: goto P_0c086bb6;
case 0x0c086bb8u: goto P_0c086bb8;
case 0x0c086bbau: goto P_0c086bba;
case 0x0c086bbcu: goto P_0c086bbc;
case 0x0c086bbeu: goto P_0c086bbe;
case 0x0c086bc0u: goto P_0c086bc0;
case 0x0c086bc2u: goto P_0c086bc2;
case 0x0c086bc4u: goto P_0c086bc4;
case 0x0c086bc6u: goto P_0c086bc6;
case 0x0c086bc8u: goto P_0c086bc8;
case 0x0c086bcau: goto P_0c086bca;
case 0x0c086bccu: goto P_0c086bcc;
case 0x0c086bceu: goto P_0c086bce;
case 0x0c086bd0u: goto P_0c086bd0;
case 0x0c086bd2u: goto P_0c086bd2;
case 0x0c086bd4u: goto P_0c086bd4;
case 0x0c086bd6u: goto P_0c086bd6;
case 0x0c086bd8u: goto P_0c086bd8;
case 0x0c086bdau: goto P_0c086bda;
case 0x0c086bdcu: goto P_0c086bdc;
case 0x0c086bdeu: goto P_0c086bde;
case 0x0c086be0u: goto P_0c086be0;
case 0x0c086be2u: goto P_0c086be2;
case 0x0c086be4u: goto P_0c086be4;
case 0x0c086be6u: goto P_0c086be6;
case 0x0c086be8u: goto P_0c086be8;
case 0x0c086beau: goto P_0c086bea;
case 0x0c086becu: goto P_0c086bec;
case 0x0c086beeu: goto P_0c086bee;
case 0x0c086bf0u: goto P_0c086bf0;
case 0x0c086bf2u: goto P_0c086bf2;
case 0x0c086bf4u: goto P_0c086bf4;
case 0x0c086bf6u: goto P_0c086bf6;
case 0x0c086bf8u: goto P_0c086bf8;
case 0x0c086bfau: goto P_0c086bfa;
case 0x0c086bfcu: goto P_0c086bfc;
case 0x0c086bfeu: goto P_0c086bfe;
case 0x0c086c00u: goto P_0c086c00;
case 0x0c086c02u: goto P_0c086c02;
case 0x0c086c04u: goto P_0c086c04;
case 0x0c086c06u: goto P_0c086c06;
case 0x0c086c08u: goto P_0c086c08;
case 0x0c086c0au: goto P_0c086c0a;
case 0x0c086c0cu: goto P_0c086c0c;
case 0x0c086c0eu: goto P_0c086c0e;
case 0x0c086c10u: goto P_0c086c10;
case 0x0c086c12u: goto P_0c086c12;
case 0x0c086c14u: goto P_0c086c14;
case 0x0c086c16u: goto P_0c086c16;
case 0x0c086c18u: goto P_0c086c18;
case 0x0c086c1au: goto P_0c086c1a;
case 0x0c086c1cu: goto P_0c086c1c;
case 0x0c086c1eu: goto P_0c086c1e;
case 0x0c086c20u: goto P_0c086c20;
case 0x0c086c22u: goto P_0c086c22;
case 0x0c086c24u: goto P_0c086c24;
case 0x0c086c26u: goto P_0c086c26;
case 0x0c086c28u: goto P_0c086c28;
case 0x0c086c2au: goto P_0c086c2a;
case 0x0c086c2cu: goto P_0c086c2c;
case 0x0c086c2eu: goto P_0c086c2e;
case 0x0c086c30u: goto P_0c086c30;
case 0x0c086c32u: goto P_0c086c32;
case 0x0c086c34u: goto P_0c086c34;
case 0x0c086c36u: goto P_0c086c36;
case 0x0c086c38u: goto P_0c086c38;
case 0x0c086c3au: goto P_0c086c3a;
case 0x0c086c3cu: goto P_0c086c3c;
case 0x0c086c3eu: goto P_0c086c3e;
case 0x0c086c40u: goto P_0c086c40;
case 0x0c086c42u: goto P_0c086c42;
case 0x0c086c44u: goto P_0c086c44;
case 0x0c086c46u: goto P_0c086c46;
case 0x0c086c48u: goto P_0c086c48;
case 0x0c086c4au: goto P_0c086c4a;
case 0x0c086c4cu: goto P_0c086c4c;
case 0x0c086c4eu: goto P_0c086c4e;
case 0x0c086c50u: goto P_0c086c50;
case 0x0c086c52u: goto P_0c086c52;
case 0x0c086c54u: goto P_0c086c54;
case 0x0c086c56u: goto P_0c086c56;
case 0x0c086c58u: goto P_0c086c58;
case 0x0c086c5au: goto P_0c086c5a;
case 0x0c086c5cu: goto P_0c086c5c;
case 0x0c086c5eu: goto P_0c086c5e;
case 0x0c086c60u: goto P_0c086c60;
case 0x0c086c62u: goto P_0c086c62;
case 0x0c086c64u: goto P_0c086c64;
case 0x0c086c66u: goto P_0c086c66;
case 0x0c086c68u: goto P_0c086c68;
case 0x0c086c6au: goto P_0c086c6a;
case 0x0c086c6cu: goto P_0c086c6c;
case 0x0c086c6eu: goto P_0c086c6e;
case 0x0c086c70u: goto P_0c086c70;
case 0x0c086c72u: goto P_0c086c72;
case 0x0c086c74u: goto P_0c086c74;
case 0x0c086c76u: goto P_0c086c76;
case 0x0c086c78u: goto P_0c086c78;
case 0x0c086c7au: goto P_0c086c7a;
case 0x0c086c7cu: goto P_0c086c7c;
case 0x0c086c7eu: goto P_0c086c7e;
case 0x0c086c80u: goto P_0c086c80;
case 0x0c086c82u: goto P_0c086c82;
case 0x0c086c84u: goto P_0c086c84;
case 0x0c086c86u: goto P_0c086c86;
case 0x0c086c88u: goto P_0c086c88;
case 0x0c086c8au: goto P_0c086c8a;
case 0x0c086c8cu: goto P_0c086c8c;
case 0x0c086c8eu: goto P_0c086c8e;
case 0x0c086c90u: goto P_0c086c90;
case 0x0c086c92u: goto P_0c086c92;
case 0x0c086c94u: goto P_0c086c94;
case 0x0c086c96u: goto P_0c086c96;
case 0x0c086c98u: goto P_0c086c98;
case 0x0c086c9au: goto P_0c086c9a;
case 0x0c086c9cu: goto P_0c086c9c;
case 0x0c086c9eu: goto P_0c086c9e;
case 0x0c086ca0u: goto P_0c086ca0;
case 0x0c086ca2u: goto P_0c086ca2;
case 0x0c086ca4u: goto P_0c086ca4;
case 0x0c086ca6u: goto P_0c086ca6;
case 0x0c086ca8u: goto P_0c086ca8;
case 0x0c086caau: goto P_0c086caa;
case 0x0c086cacu: goto P_0c086cac;
case 0x0c086caeu: goto P_0c086cae;
case 0x0c086cb0u: goto P_0c086cb0;
case 0x0c086cb2u: goto P_0c086cb2;
case 0x0c086cb4u: goto P_0c086cb4;
case 0x0c086cb6u: goto P_0c086cb6;
case 0x0c086cb8u: goto P_0c086cb8;
case 0x0c086cbau: goto P_0c086cba;
case 0x0c086cbcu: goto P_0c086cbc;
case 0x0c086cbeu: goto P_0c086cbe;
case 0x0c086cc0u: goto P_0c086cc0;
case 0x0c086cc2u: goto P_0c086cc2;
case 0x0c086cc4u: goto P_0c086cc4;
case 0x0c086cc6u: goto P_0c086cc6;
case 0x0c086cc8u: goto P_0c086cc8;
case 0x0c086ccau: goto P_0c086cca;
case 0x0c086cccu: goto P_0c086ccc;
case 0x0c086cceu: goto P_0c086cce;
case 0x0c086cd0u: goto P_0c086cd0;
case 0x0c086cd2u: goto P_0c086cd2;
case 0x0c087542u: goto P_0c087542;
case 0x0c087544u: goto P_0c087544;
case 0x0c087546u: goto P_0c087546;
case 0x0c087548u: goto P_0c087548;
case 0x0c08754au: goto P_0c08754a;
case 0x0c08754cu: goto P_0c08754c;
case 0x0c08754eu: goto P_0c08754e;
case 0x0c087550u: goto P_0c087550;
case 0x0c087552u: goto P_0c087552;
case 0x0c087554u: goto P_0c087554;
case 0x0c087556u: goto P_0c087556;
case 0x0c087558u: goto P_0c087558;
case 0x0c08755au: goto P_0c08755a;
case 0x0c08755cu: goto P_0c08755c;
case 0x0c08755eu: goto P_0c08755e;
case 0x0c087560u: goto P_0c087560;
case 0x0c08894cu: goto P_0c08894c;
case 0x0c08894eu: goto P_0c08894e;
case 0x0c088950u: goto P_0c088950;
case 0x0c088952u: goto P_0c088952;
case 0x0c088954u: goto P_0c088954;
case 0x0c088956u: goto P_0c088956;
case 0x0c088958u: goto P_0c088958;
case 0x0c08895au: goto P_0c08895a;
case 0x0c08895cu: goto P_0c08895c;
case 0x0c08895eu: goto P_0c08895e;
case 0x0c088960u: goto P_0c088960;
case 0x0c088962u: goto P_0c088962;
case 0x0c088964u: goto P_0c088964;
case 0x0c088966u: goto P_0c088966;
case 0x0c088968u: goto P_0c088968;
case 0x0c08896au: goto P_0c08896a;
case 0x0c08896cu: goto P_0c08896c;
case 0x0c08896eu: goto P_0c08896e;
case 0x0c088970u: goto P_0c088970;
case 0x0c088972u: goto P_0c088972;
case 0x0c088974u: goto P_0c088974;
case 0x0c088976u: goto P_0c088976;
case 0x0c088978u: goto P_0c088978;
case 0x0c08897au: goto P_0c08897a;
case 0x0c08897cu: goto P_0c08897c;
case 0x0c08897eu: goto P_0c08897e;
case 0x0c088980u: goto P_0c088980;
case 0x0c088982u: goto P_0c088982;
case 0x0c088984u: goto P_0c088984;
case 0x0c088986u: goto P_0c088986;
case 0x0c088988u: goto P_0c088988;
case 0x0c08898au: goto P_0c08898a;
case 0x0c08898cu: goto P_0c08898c;
case 0x0c08898eu: goto P_0c08898e;
case 0x0c088990u: goto P_0c088990;
case 0x0c088992u: goto P_0c088992;
case 0x0c088994u: goto P_0c088994;
case 0x0c088996u: goto P_0c088996;
case 0x0c088998u: goto P_0c088998;
case 0x0c08899au: goto P_0c08899a;
case 0x0c08899cu: goto P_0c08899c;
case 0x0c08899eu: goto P_0c08899e;
case 0x0c0889a0u: goto P_0c0889a0;
case 0x0c0889a2u: goto P_0c0889a2;
case 0x0c0889a4u: goto P_0c0889a4;
case 0x0c0889a6u: goto P_0c0889a6;
case 0x0c0889a8u: goto P_0c0889a8;
case 0x0c0889aau: goto P_0c0889aa;
case 0x0c0889acu: goto P_0c0889ac;
case 0x0c0889aeu: goto P_0c0889ae;
case 0x0c0889b0u: goto P_0c0889b0;
case 0x0c0889b2u: goto P_0c0889b2;
case 0x0c0889b4u: goto P_0c0889b4;
case 0x0c0889b6u: goto P_0c0889b6;
case 0x0c0889ccu: goto P_0c0889cc;
case 0x0c0889ceu: goto P_0c0889ce;
case 0x0c0889d0u: goto P_0c0889d0;
case 0x0c0889d2u: goto P_0c0889d2;
case 0x0c0889d4u: goto P_0c0889d4;
case 0x0c0889d6u: goto P_0c0889d6;
case 0x0c0889d8u: goto P_0c0889d8;
case 0x0c0889dau: goto P_0c0889da;
case 0x0c0889dcu: goto P_0c0889dc;
case 0x0c0889deu: goto P_0c0889de;
case 0x0c0889e0u: goto P_0c0889e0;
case 0x0c0889e2u: goto P_0c0889e2;
case 0x0c0889e4u: goto P_0c0889e4;
case 0x0c0889e6u: goto P_0c0889e6;
case 0x0c0889e8u: goto P_0c0889e8;
case 0x0c0889eau: goto P_0c0889ea;
case 0x0c0889ecu: goto P_0c0889ec;
case 0x0c0889eeu: goto P_0c0889ee;
case 0x0c0889f0u: goto P_0c0889f0;
case 0x0c0889f2u: goto P_0c0889f2;
case 0x0c0889f4u: goto P_0c0889f4;
case 0x0c0889f6u: goto P_0c0889f6;
case 0x0c0889f8u: goto P_0c0889f8;
case 0x0c0889fau: goto P_0c0889fa;
case 0x0c0889fcu: goto P_0c0889fc;
case 0x0c0889feu: goto P_0c0889fe;
case 0x0c088a00u: goto P_0c088a00;
case 0x0c088a02u: goto P_0c088a02;
case 0x0c088a04u: goto P_0c088a04;
case 0x0c088a06u: goto P_0c088a06;
case 0x0c088a08u: goto P_0c088a08;
case 0x0c088a0au: goto P_0c088a0a;
case 0x0c088a0cu: goto P_0c088a0c;
case 0x0c088a0eu: goto P_0c088a0e;
case 0x0c088a10u: goto P_0c088a10;
case 0x0c088a12u: goto P_0c088a12;
case 0x0c088a14u: goto P_0c088a14;
case 0x0c088a16u: goto P_0c088a16;
case 0x0c088a18u: goto P_0c088a18;
case 0x0c088a1au: goto P_0c088a1a;
case 0x0c088a1cu: goto P_0c088a1c;
case 0x0c088a1eu: goto P_0c088a1e;
case 0x0c088a20u: goto P_0c088a20;
case 0x0c088a22u: goto P_0c088a22;
case 0x0c088a24u: goto P_0c088a24;
case 0x0c088a26u: goto P_0c088a26;
case 0x0c088a28u: goto P_0c088a28;
case 0x0c088a2au: goto P_0c088a2a;
case 0x0c088a2cu: goto P_0c088a2c;
case 0x0c088a2eu: goto P_0c088a2e;
case 0x0c088a30u: goto P_0c088a30;
case 0x0c088a32u: goto P_0c088a32;
case 0x0c088a34u: goto P_0c088a34;
case 0x0c088a36u: goto P_0c088a36;
case 0x0c088a38u: goto P_0c088a38;
case 0x0c088a3au: goto P_0c088a3a;
case 0x0c088a3cu: goto P_0c088a3c;
case 0x0c088a3eu: goto P_0c088a3e;
case 0x0c088a40u: goto P_0c088a40;
case 0x0c088a42u: goto P_0c088a42;
case 0x0c088a44u: goto P_0c088a44;
case 0x0c088a46u: goto P_0c088a46;
case 0x0c088a48u: goto P_0c088a48;
case 0x0c088a4au: goto P_0c088a4a;
case 0x0c088a4cu: goto P_0c088a4c;
case 0x0c088a78u: goto P_0c088a78;
case 0x0c088a7au: goto P_0c088a7a;
case 0x0c088a7cu: goto P_0c088a7c;
case 0x0c088a7eu: goto P_0c088a7e;
case 0x0c088a80u: goto P_0c088a80;
case 0x0c088a82u: goto P_0c088a82;
case 0x0c088a84u: goto P_0c088a84;
case 0x0c088a86u: goto P_0c088a86;
case 0x0c088a88u: goto P_0c088a88;
case 0x0c088a8au: goto P_0c088a8a;
case 0x0c088a8cu: goto P_0c088a8c;
case 0x0c088a8eu: goto P_0c088a8e;
case 0x0c088a90u: goto P_0c088a90;
case 0x0c088a92u: goto P_0c088a92;
case 0x0c088a94u: goto P_0c088a94;
case 0x0c088a96u: goto P_0c088a96;
case 0x0c088a98u: goto P_0c088a98;
case 0x0c088a9au: goto P_0c088a9a;
case 0x0c088a9cu: goto P_0c088a9c;
case 0x0c088a9eu: goto P_0c088a9e;
case 0x0c088aa0u: goto P_0c088aa0;
case 0x0c088aa2u: goto P_0c088aa2;
case 0x0c088aa4u: goto P_0c088aa4;
case 0x0c088aa6u: goto P_0c088aa6;
case 0x0c088aa8u: goto P_0c088aa8;
case 0x0c088aaau: goto P_0c088aaa;
case 0x0c088aacu: goto P_0c088aac;
case 0x0c088aaeu: goto P_0c088aae;
case 0x0c088ab0u: goto P_0c088ab0;
case 0x0c088ab2u: goto P_0c088ab2;
case 0x0c088ab4u: goto P_0c088ab4;
case 0x0c088ab6u: goto P_0c088ab6;
case 0x0c088ab8u: goto P_0c088ab8;
case 0x0c088abau: goto P_0c088aba;
case 0x0c088abcu: goto P_0c088abc;
case 0x0c088abeu: goto P_0c088abe;
case 0x0c088ac0u: goto P_0c088ac0;
case 0x0c088ac2u: goto P_0c088ac2;
case 0x0c088ac4u: goto P_0c088ac4;
case 0x0c088ac6u: goto P_0c088ac6;
case 0x0c088ac8u: goto P_0c088ac8;
case 0x0c088acau: goto P_0c088aca;
case 0x0c088accu: goto P_0c088acc;
case 0x0c088aceu: goto P_0c088ace;
case 0x0c088ad0u: goto P_0c088ad0;
case 0x0c088ad2u: goto P_0c088ad2;
case 0x0c088ad4u: goto P_0c088ad4;
case 0x0c088ad6u: goto P_0c088ad6;
case 0x0c088ad8u: goto P_0c088ad8;
case 0x0c088adau: goto P_0c088ada;
case 0x0c088adcu: goto P_0c088adc;
case 0x0c088adeu: goto P_0c088ade;
case 0x0c088ae0u: goto P_0c088ae0;
case 0x0c088ae2u: goto P_0c088ae2;
case 0x0c088ae4u: goto P_0c088ae4;
case 0x0c088ae6u: goto P_0c088ae6;
case 0x0c088ae8u: goto P_0c088ae8;
case 0x0c088aeau: goto P_0c088aea;
case 0x0c088aecu: goto P_0c088aec;
case 0x0c088aeeu: goto P_0c088aee;
case 0x0c088af0u: goto P_0c088af0;
case 0x0c088af2u: goto P_0c088af2;
case 0x0c088af4u: goto P_0c088af4;
case 0x0c088af6u: goto P_0c088af6;
case 0x0c088af8u: goto P_0c088af8;
case 0x0c088afau: goto P_0c088afa;
case 0x0c088afcu: goto P_0c088afc;
case 0x0c088afeu: goto P_0c088afe;
case 0x0c088b00u: goto P_0c088b00;
case 0x0c088b02u: goto P_0c088b02;
case 0x0c088b04u: goto P_0c088b04;
case 0x0c088b06u: goto P_0c088b06;
case 0x0c088b08u: goto P_0c088b08;
case 0x0c088b0au: goto P_0c088b0a;
case 0x0c088b0cu: goto P_0c088b0c;
case 0x0c088b0eu: goto P_0c088b0e;
case 0x0c088b10u: goto P_0c088b10;
case 0x0c088b12u: goto P_0c088b12;
case 0x0c088b14u: goto P_0c088b14;
case 0x0c088b16u: goto P_0c088b16;
case 0x0c088b18u: goto P_0c088b18;
case 0x0c088b1au: goto P_0c088b1a;
case 0x0c088b1cu: goto P_0c088b1c;
case 0x0c088b1eu: goto P_0c088b1e;
case 0x0c088b20u: goto P_0c088b20;
case 0x0c088b22u: goto P_0c088b22;
case 0x0c088b24u: goto P_0c088b24;
case 0x0c088b26u: goto P_0c088b26;
case 0x0c088b28u: goto P_0c088b28;
case 0x0c088b2au: goto P_0c088b2a;
case 0x0c088b2cu: goto P_0c088b2c;
case 0x0c088b2eu: goto P_0c088b2e;
case 0x0c088b30u: goto P_0c088b30;
case 0x0c088b32u: goto P_0c088b32;
case 0x0c088b34u: goto P_0c088b34;
case 0x0c088b36u: goto P_0c088b36;
case 0x0c0c72e2u: goto P_0c0c72e2;
case 0x0c0c72e4u: goto P_0c0c72e4;
case 0x0c0c72e6u: goto P_0c0c72e6;
case 0x0c0c72e8u: goto P_0c0c72e8;
case 0x0c0c72eau: goto P_0c0c72ea;
case 0x0c0c72ecu: goto P_0c0c72ec;
case 0x0c0c72eeu: goto P_0c0c72ee;
case 0x0c0c72f0u: goto P_0c0c72f0;
case 0x0c0c72f2u: goto P_0c0c72f2;
case 0x0c0c72f4u: goto P_0c0c72f4;
case 0x0c0c72f6u: goto P_0c0c72f6;
case 0x0c0c72f8u: goto P_0c0c72f8;
case 0x0c0c72fau: goto P_0c0c72fa;
case 0x0c0c72fcu: goto P_0c0c72fc;
case 0x0c0c72feu: goto P_0c0c72fe;
case 0x0c0c7300u: goto P_0c0c7300;
case 0x0c0c7302u: goto P_0c0c7302;
case 0x0c0c7304u: goto P_0c0c7304;
case 0x0c0c7306u: goto P_0c0c7306;
case 0x0c0c7308u: goto P_0c0c7308;
case 0x0c0c730au: goto P_0c0c730a;
case 0x0c0c730cu: goto P_0c0c730c;
case 0x0c0c730eu: goto P_0c0c730e;
case 0x0c0c7310u: goto P_0c0c7310;
case 0x0c0c7312u: goto P_0c0c7312;
case 0x0c0c7314u: goto P_0c0c7314;
case 0x0c0c7316u: goto P_0c0c7316;
case 0x0c0c7318u: goto P_0c0c7318;
case 0x0c0c731au: goto P_0c0c731a;
case 0x0c0c731cu: goto P_0c0c731c;
case 0x0c0c731eu: goto P_0c0c731e;
case 0x0c0c7320u: goto P_0c0c7320;
case 0x0c0c7322u: goto P_0c0c7322;
case 0x0c0c7324u: goto P_0c0c7324;
case 0x0c0c7326u: goto P_0c0c7326;
case 0x0c0c7328u: goto P_0c0c7328;
case 0x0c0c732au: goto P_0c0c732a;
case 0x0c0c732cu: goto P_0c0c732c;
case 0x0c0c732eu: goto P_0c0c732e;
case 0x0c0c7330u: goto P_0c0c7330;
case 0x0c0c7332u: goto P_0c0c7332;
case 0x0c0c7334u: goto P_0c0c7334;
case 0x0c0c7336u: goto P_0c0c7336;
case 0x0c0c7338u: goto P_0c0c7338;
case 0x0c0c733au: goto P_0c0c733a;
case 0x0c0c733cu: goto P_0c0c733c;
case 0x0c0c733eu: goto P_0c0c733e;
case 0x0c0c7340u: goto P_0c0c7340;
case 0x0c0c7342u: goto P_0c0c7342;
case 0x0c0c7344u: goto P_0c0c7344;
case 0x0c0c7346u: goto P_0c0c7346;
case 0x0c0c7348u: goto P_0c0c7348;
case 0x0c0c734au: goto P_0c0c734a;
case 0x0c0c734cu: goto P_0c0c734c;
case 0x0c0c734eu: goto P_0c0c734e;
case 0x0c0c7350u: goto P_0c0c7350;
case 0x0c0c7352u: goto P_0c0c7352;
case 0x0c0c7354u: goto P_0c0c7354;
case 0x0c0c7356u: goto P_0c0c7356;
case 0x0c0c7358u: goto P_0c0c7358;
case 0x0c0c735au: goto P_0c0c735a;
case 0x0c0c735cu: goto P_0c0c735c;
case 0x0c0c735eu: goto P_0c0c735e;
case 0x0c0c7360u: goto P_0c0c7360;
case 0x0c0c7362u: goto P_0c0c7362;
case 0x0c0c7364u: goto P_0c0c7364;
case 0x0c0c7366u: goto P_0c0c7366;
case 0x0c0c7368u: goto P_0c0c7368;
case 0x0c0c736au: goto P_0c0c736a;
case 0x0c0c736cu: goto P_0c0c736c;
case 0x0c0c736eu: goto P_0c0c736e;
case 0x0c0c7370u: goto P_0c0c7370;
case 0x0c0c7372u: goto P_0c0c7372;
case 0x0c0c7374u: goto P_0c0c7374;
case 0x0c0c7376u: goto P_0c0c7376;
case 0x0c0c7378u: goto P_0c0c7378;
case 0x0c0c737au: goto P_0c0c737a;
case 0x0c0c7398u: goto P_0c0c7398;
case 0x0c0c739au: goto P_0c0c739a;
case 0x0c0c739cu: goto P_0c0c739c;
case 0x0c0c739eu: goto P_0c0c739e;
case 0x0c0c73a0u: goto P_0c0c73a0;
case 0x0c0c73a2u: goto P_0c0c73a2;
case 0x0c0c73a4u: goto P_0c0c73a4;
case 0x0c0c73a6u: goto P_0c0c73a6;
case 0x0c0c73a8u: goto P_0c0c73a8;
case 0x0c0c73aau: goto P_0c0c73aa;
case 0x0c0c73acu: goto P_0c0c73ac;
case 0x0c0c73aeu: goto P_0c0c73ae;
case 0x0c0c73b0u: goto P_0c0c73b0;
case 0x0c0c73b2u: goto P_0c0c73b2;
case 0x0c0c73b4u: goto P_0c0c73b4;
case 0x0c0c73b6u: goto P_0c0c73b6;
case 0x0c0c73b8u: goto P_0c0c73b8;
case 0x0c0c73bau: goto P_0c0c73ba;
case 0x0c0c73bcu: goto P_0c0c73bc;
case 0x0c0c73beu: goto P_0c0c73be;
case 0x0c0c73c0u: goto P_0c0c73c0;
case 0x0c0c73c2u: goto P_0c0c73c2;
case 0x0c0c73c4u: goto P_0c0c73c4;
case 0x0c0c73c6u: goto P_0c0c73c6;
case 0x0c0c73c8u: goto P_0c0c73c8;
case 0x0c0c73cau: goto P_0c0c73ca;
case 0x0c0c73ccu: goto P_0c0c73cc;
case 0x0c0c73ceu: goto P_0c0c73ce;
case 0x0c0c73d0u: goto P_0c0c73d0;
case 0x0c0c73d2u: goto P_0c0c73d2;
case 0x0c0c73d4u: goto P_0c0c73d4;
case 0x0c0c73d6u: goto P_0c0c73d6;
case 0x0c0c73d8u: goto P_0c0c73d8;
case 0x0c0c73dau: goto P_0c0c73da;
case 0x0c0c73dcu: goto P_0c0c73dc;
case 0x0c0c73deu: goto P_0c0c73de;
case 0x0c0c73e0u: goto P_0c0c73e0;
case 0x0c0c73e2u: goto P_0c0c73e2;
case 0x0c0c73e4u: goto P_0c0c73e4;
case 0x0c0c73e6u: goto P_0c0c73e6;
case 0x0c0c73e8u: goto P_0c0c73e8;
case 0x0c0c73eau: goto P_0c0c73ea;
case 0x0c0c73ecu: goto P_0c0c73ec;
case 0x0c0c73eeu: goto P_0c0c73ee;
case 0x0c0c73f0u: goto P_0c0c73f0;
case 0x0c0c73f2u: goto P_0c0c73f2;
case 0x0c0c73f4u: goto P_0c0c73f4;
case 0x0c0c73f6u: goto P_0c0c73f6;
case 0x0c0c73f8u: goto P_0c0c73f8;
case 0x0c0c73fau: goto P_0c0c73fa;
case 0x0c0c73fcu: goto P_0c0c73fc;
case 0x0c0c73feu: goto P_0c0c73fe;
case 0x0c0c7400u: goto P_0c0c7400;
case 0x0c0c7402u: goto P_0c0c7402;
case 0x0c0c7404u: goto P_0c0c7404;
case 0x0c0c7406u: goto P_0c0c7406;
case 0x0c0c7408u: goto P_0c0c7408;
case 0x0c0c740au: goto P_0c0c740a;
case 0x0c0c740cu: goto P_0c0c740c;
case 0x0c0c740eu: goto P_0c0c740e;
case 0x0c0c7410u: goto P_0c0c7410;
case 0x0c0c7412u: goto P_0c0c7412;
case 0x0c0c7414u: goto P_0c0c7414;
case 0x0c0c7416u: goto P_0c0c7416;
case 0x0c0c7418u: goto P_0c0c7418;
case 0x0c0c741au: goto P_0c0c741a;
case 0x0c0c741cu: goto P_0c0c741c;
case 0x0c0c741eu: goto P_0c0c741e;
case 0x0c0c7420u: goto P_0c0c7420;
case 0x0c0c7422u: goto P_0c0c7422;
case 0x0c0c7424u: goto P_0c0c7424;
case 0x0c0c7426u: goto P_0c0c7426;
case 0x0c0c7428u: goto P_0c0c7428;
case 0x0c0c742au: goto P_0c0c742a;
case 0x0c0c742cu: goto P_0c0c742c;
case 0x0c0c742eu: goto P_0c0c742e;
case 0x0c0c7430u: goto P_0c0c7430;
case 0x0c0c7432u: goto P_0c0c7432;
case 0x0c0c7434u: goto P_0c0c7434;
case 0x0c0c7436u: goto P_0c0c7436;
case 0x0c0c7438u: goto P_0c0c7438;
case 0x0c0c743au: goto P_0c0c743a;
case 0x0c0c743cu: goto P_0c0c743c;
case 0x0c0c743eu: goto P_0c0c743e;
case 0x0c0c7440u: goto P_0c0c7440;
case 0x0c0c7442u: goto P_0c0c7442;
case 0x0c0c7444u: goto P_0c0c7444;
case 0x0c0c7446u: goto P_0c0c7446;
case 0x0c0c7448u: goto P_0c0c7448;
case 0x0c0c744au: goto P_0c0c744a;
case 0x0c0c744cu: goto P_0c0c744c;
case 0x0c0c744eu: goto P_0c0c744e;
case 0x0c0c7450u: goto P_0c0c7450;
case 0x0c0c7452u: goto P_0c0c7452;
case 0x0c0c7454u: goto P_0c0c7454;
case 0x0c0c7456u: goto P_0c0c7456;
case 0x0c0c7458u: goto P_0c0c7458;
case 0x0c0c745au: goto P_0c0c745a;
case 0x0c0c745cu: goto P_0c0c745c;
case 0x0c0c745eu: goto P_0c0c745e;
case 0x0c0c7460u: goto P_0c0c7460;
case 0x0c0c7462u: goto P_0c0c7462;
case 0x0c0c7464u: goto P_0c0c7464;
case 0x0c0c7466u: goto P_0c0c7466;
case 0x0c0c7468u: goto P_0c0c7468;
case 0x0c0c746au: goto P_0c0c746a;
case 0x0c0c746cu: goto P_0c0c746c;
case 0x0c0c746eu: goto P_0c0c746e;
case 0x0c0c7470u: goto P_0c0c7470;
case 0x0c0c7472u: goto P_0c0c7472;
case 0x0c0c7474u: goto P_0c0c7474;
case 0x0c0c7476u: goto P_0c0c7476;
case 0x0c0c7478u: goto P_0c0c7478;
case 0x0c0c747au: goto P_0c0c747a;
case 0x0c0c747cu: goto P_0c0c747c;
case 0x0c0c747eu: goto P_0c0c747e;
case 0x0c0c7480u: goto P_0c0c7480;
case 0x0c0c7482u: goto P_0c0c7482;
case 0x0c0c7484u: goto P_0c0c7484;
case 0x0c0c7486u: goto P_0c0c7486;
case 0x0c0c7488u: goto P_0c0c7488;
case 0x0c0c748au: goto P_0c0c748a;
case 0x0c0c748cu: goto P_0c0c748c;
case 0x0c0c748eu: goto P_0c0c748e;
case 0x0c0c7490u: goto P_0c0c7490;
case 0x0c0c7492u: goto P_0c0c7492;
case 0x0c0c7802u: goto P_0c0c7802;
case 0x0c0c7804u: goto P_0c0c7804;
case 0x0c0c7806u: goto P_0c0c7806;
case 0x0c0c7808u: goto P_0c0c7808;
case 0x0c0c780au: goto P_0c0c780a;
case 0x0c0c780cu: goto P_0c0c780c;
case 0x0c0c780eu: goto P_0c0c780e;
case 0x0c0c7810u: goto P_0c0c7810;
case 0x0c0c7812u: goto P_0c0c7812;
case 0x0c0c7814u: goto P_0c0c7814;
case 0x0c0c7816u: goto P_0c0c7816;
case 0x0c0c7818u: goto P_0c0c7818;
case 0x0c0c781au: goto P_0c0c781a;
case 0x0c0c781cu: goto P_0c0c781c;
case 0x0c0c781eu: goto P_0c0c781e;
case 0x0c0c7820u: goto P_0c0c7820;
case 0x0c0c7822u: goto P_0c0c7822;
case 0x0c0c7824u: goto P_0c0c7824;
case 0x0c0c7826u: goto P_0c0c7826;
case 0x0c0c7828u: goto P_0c0c7828;
case 0x0c0c782au: goto P_0c0c782a;
case 0x0c0c782cu: goto P_0c0c782c;
case 0x0c0c782eu: goto P_0c0c782e;
case 0x0c0c7830u: goto P_0c0c7830;
case 0x0c0c7832u: goto P_0c0c7832;
case 0x0c0c7834u: goto P_0c0c7834;
case 0x0c0c7836u: goto P_0c0c7836;
case 0x0c0c7838u: goto P_0c0c7838;
case 0x0c0c783au: goto P_0c0c783a;
case 0x0c0c783cu: goto P_0c0c783c;
case 0x0c0c783eu: goto P_0c0c783e;
case 0x0c0c7840u: goto P_0c0c7840;
case 0x0c0c7842u: goto P_0c0c7842;
case 0x0c0c7844u: goto P_0c0c7844;
case 0x0c0c7846u: goto P_0c0c7846;
case 0x0c0c7848u: goto P_0c0c7848;
case 0x0c0c784au: goto P_0c0c784a;
case 0x0c0c784cu: goto P_0c0c784c;
case 0x0c0c784eu: goto P_0c0c784e;
case 0x0c0c7850u: goto P_0c0c7850;
case 0x0c0c7852u: goto P_0c0c7852;
case 0x0c0c7854u: goto P_0c0c7854;
case 0x0c0c7856u: goto P_0c0c7856;
case 0x0c0c7858u: goto P_0c0c7858;
case 0x0c0c785au: goto P_0c0c785a;
case 0x0c0c785cu: goto P_0c0c785c;
case 0x0c0c7a88u: goto P_0c0c7a88;
case 0x0c0c7a8au: goto P_0c0c7a8a;
case 0x0c0c7a8cu: goto P_0c0c7a8c;
case 0x0c0c7a8eu: goto P_0c0c7a8e;
case 0x0c0c7a90u: goto P_0c0c7a90;
case 0x0c0c7a92u: goto P_0c0c7a92;
case 0x0c0c7a94u: goto P_0c0c7a94;
case 0x0c0c7a96u: goto P_0c0c7a96;
case 0x0c0c7a98u: goto P_0c0c7a98;
case 0x0c0c7a9au: goto P_0c0c7a9a;
case 0x0c0c7a9cu: goto P_0c0c7a9c;
case 0x0c0c7a9eu: goto P_0c0c7a9e;
case 0x0c0c7aa0u: goto P_0c0c7aa0;
case 0x0c0c7aa2u: goto P_0c0c7aa2;
case 0x0c0c7aa4u: goto P_0c0c7aa4;
case 0x0c0c7aa6u: goto P_0c0c7aa6;
case 0x0c0c7aa8u: goto P_0c0c7aa8;
case 0x0c0c7aaau: goto P_0c0c7aaa;
case 0x0c0c7aacu: goto P_0c0c7aac;
case 0x0c0c7aaeu: goto P_0c0c7aae;
case 0x0c0c7ab0u: goto P_0c0c7ab0;
case 0x0c0c7ab2u: goto P_0c0c7ab2;
case 0x0c0c7ab4u: goto P_0c0c7ab4;
case 0x0c0c7ab6u: goto P_0c0c7ab6;
case 0x0c0c7ab8u: goto P_0c0c7ab8;
case 0x0c0c7abau: goto P_0c0c7aba;
case 0x0c0c7abcu: goto P_0c0c7abc;
case 0x0c0c7abeu: goto P_0c0c7abe;
case 0x0c0c7ac0u: goto P_0c0c7ac0;
case 0x0c0c7ac2u: goto P_0c0c7ac2;
case 0x0c0c7ac4u: goto P_0c0c7ac4;
case 0x0c0c7ac6u: goto P_0c0c7ac6;
case 0x0c0c7ac8u: goto P_0c0c7ac8;
case 0x0c0c7acau: goto P_0c0c7aca;
case 0x0c0c7accu: goto P_0c0c7acc;
case 0x0c0c7aceu: goto P_0c0c7ace;
case 0x0c0c7ad0u: goto P_0c0c7ad0;
case 0x0c0c7ad2u: goto P_0c0c7ad2;
case 0x0c0c7ad4u: goto P_0c0c7ad4;
case 0x0c0c7ad6u: goto P_0c0c7ad6;
case 0x0c0c7ad8u: goto P_0c0c7ad8;
case 0x0c0c7adau: goto P_0c0c7ada;
case 0x0c0c7adcu: goto P_0c0c7adc;
case 0x0c0c7adeu: goto P_0c0c7ade;
case 0x0c0c7ae0u: goto P_0c0c7ae0;
case 0x0c0c7ae2u: goto P_0c0c7ae2;
case 0x0c0c7ae4u: goto P_0c0c7ae4;
case 0x0c0c7ae6u: goto P_0c0c7ae6;
case 0x0c0c7ae8u: goto P_0c0c7ae8;
case 0x0c0c7aeau: goto P_0c0c7aea;
case 0x0c0c7aecu: goto P_0c0c7aec;
case 0x0c0c7aeeu: goto P_0c0c7aee;
case 0x0c0c7af0u: goto P_0c0c7af0;
case 0x0c0c7af2u: goto P_0c0c7af2;
case 0x0c0c7af4u: goto P_0c0c7af4;
case 0x0c0c7af6u: goto P_0c0c7af6;
case 0x0c0c7af8u: goto P_0c0c7af8;
case 0x0c0c7afau: goto P_0c0c7afa;
case 0x0c0c7afcu: goto P_0c0c7afc;
case 0x0c0c7afeu: goto P_0c0c7afe;
case 0x0c0c7b00u: goto P_0c0c7b00;
case 0x0c0c7b02u: goto P_0c0c7b02;
case 0x0c0c7b04u: goto P_0c0c7b04;
case 0x0c0c7b06u: goto P_0c0c7b06;
case 0x0c0c7b08u: goto P_0c0c7b08;
case 0x0c0c7b0au: goto P_0c0c7b0a;
case 0x0c0c7b0cu: goto P_0c0c7b0c;
case 0x0c0c7b0eu: goto P_0c0c7b0e;
case 0x0c0c7b10u: goto P_0c0c7b10;
case 0x0c0c7b12u: goto P_0c0c7b12;
case 0x0c0c7b14u: goto P_0c0c7b14;
case 0x0c0c7b16u: goto P_0c0c7b16;
case 0x0c0c7b18u: goto P_0c0c7b18;
case 0x0c0c7b1au: goto P_0c0c7b1a;
case 0x0c0c7b1cu: goto P_0c0c7b1c;
case 0x0c0c7b1eu: goto P_0c0c7b1e;
case 0x0c0c7b20u: goto P_0c0c7b20;
case 0x0c0c7b22u: goto P_0c0c7b22;
case 0x0c0c7b24u: goto P_0c0c7b24;
case 0x0c0c7b26u: goto P_0c0c7b26;
case 0x0c0c7b78u: goto P_0c0c7b78;
case 0x0c0c7b7au: goto P_0c0c7b7a;
case 0x0c0c7b7cu: goto P_0c0c7b7c;
case 0x0c0c7b7eu: goto P_0c0c7b7e;
case 0x0c0c7b80u: goto P_0c0c7b80;
case 0x0c0c7b82u: goto P_0c0c7b82;
case 0x0c0c7b84u: goto P_0c0c7b84;
case 0x0c0c7b86u: goto P_0c0c7b86;
case 0x0c0c7b88u: goto P_0c0c7b88;
case 0x0c0c7b8au: goto P_0c0c7b8a;
case 0x0c0c7b8cu: goto P_0c0c7b8c;
case 0x0c0c7b8eu: goto P_0c0c7b8e;
case 0x0c0c7b90u: goto P_0c0c7b90;
case 0x0c0c7b92u: goto P_0c0c7b92;
case 0x0c0c7b94u: goto P_0c0c7b94;
case 0x0c0c7b96u: goto P_0c0c7b96;
case 0x0c0c7b98u: goto P_0c0c7b98;
case 0x0c0c7b9au: goto P_0c0c7b9a;
case 0x0c0c7b9cu: goto P_0c0c7b9c;
case 0x0c0c7b9eu: goto P_0c0c7b9e;
case 0x0c0c7ba0u: goto P_0c0c7ba0;
case 0x0c0c7ba2u: goto P_0c0c7ba2;
case 0x0c0c7ba4u: goto P_0c0c7ba4;
case 0x0c0c7ba6u: goto P_0c0c7ba6;
case 0x0c0c7ba8u: goto P_0c0c7ba8;
case 0x0c0c7baau: goto P_0c0c7baa;
case 0x0c0c7bacu: goto P_0c0c7bac;
case 0x0c0c7baeu: goto P_0c0c7bae;
case 0x0c0c7bb0u: goto P_0c0c7bb0;
case 0x0c0c7bb2u: goto P_0c0c7bb2;
case 0x0c0c7bb4u: goto P_0c0c7bb4;
case 0x0c0c7bb6u: goto P_0c0c7bb6;
case 0x0c0c7bb8u: goto P_0c0c7bb8;
case 0x0c0c7bbau: goto P_0c0c7bba;
case 0x0c0c7bbcu: goto P_0c0c7bbc;
case 0x0c0c7bbeu: goto P_0c0c7bbe;
case 0x0c0c7bc0u: goto P_0c0c7bc0;
case 0x0c0c7bc2u: goto P_0c0c7bc2;
case 0x0c0c7bc4u: goto P_0c0c7bc4;
case 0x0c0c7bc6u: goto P_0c0c7bc6;
case 0x0c0c7bc8u: goto P_0c0c7bc8;
case 0x0c0c7bcau: goto P_0c0c7bca;
case 0x0c0c7bccu: goto P_0c0c7bcc;
case 0x0c0c7bceu: goto P_0c0c7bce;
case 0x0c0c7bd0u: goto P_0c0c7bd0;
case 0x0c0c7bd2u: goto P_0c0c7bd2;
case 0x0c0c7bd4u: goto P_0c0c7bd4;
case 0x0c0c7bd6u: goto P_0c0c7bd6;
case 0x0c0c7bd8u: goto P_0c0c7bd8;
case 0x0c0c7bdau: goto P_0c0c7bda;
case 0x0c0c7bdcu: goto P_0c0c7bdc;
case 0x0c0c7bdeu: goto P_0c0c7bde;
case 0x0c0c7be0u: goto P_0c0c7be0;
case 0x0c0c7be2u: goto P_0c0c7be2;
case 0x0c0c7be4u: goto P_0c0c7be4;
case 0x0c0c7be6u: goto P_0c0c7be6;
case 0x0c0c7be8u: goto P_0c0c7be8;
case 0x0c0c7beau: goto P_0c0c7bea;
case 0x0c0c7becu: goto P_0c0c7bec;
case 0x0c0c7beeu: goto P_0c0c7bee;
case 0x0c0c7bf0u: goto P_0c0c7bf0;
case 0x0c0c7bf2u: goto P_0c0c7bf2;
case 0x0c0c7bf4u: goto P_0c0c7bf4;
case 0x0c0c7bf6u: goto P_0c0c7bf6;
case 0x0c0c7bf8u: goto P_0c0c7bf8;
case 0x0c0c7bfau: goto P_0c0c7bfa;
case 0x0c0c7bfcu: goto P_0c0c7bfc;
case 0x0c0c7bfeu: goto P_0c0c7bfe;
case 0x0c0c7c00u: goto P_0c0c7c00;
case 0x0c0c7c02u: goto P_0c0c7c02;
case 0x0c0c7c04u: goto P_0c0c7c04;
case 0x0c0c7c06u: goto P_0c0c7c06;
case 0x0c0c7c08u: goto P_0c0c7c08;
case 0x0c0c7c0au: goto P_0c0c7c0a;
case 0x0c0c7c0cu: goto P_0c0c7c0c;
case 0x0c0c7c0eu: goto P_0c0c7c0e;
case 0x0c0c7c10u: goto P_0c0c7c10;
case 0x0c0c7c12u: goto P_0c0c7c12;
case 0x0c0c7c14u: goto P_0c0c7c14;
case 0x0c0c7c16u: goto P_0c0c7c16;
case 0x0c0c7c18u: goto P_0c0c7c18;
case 0x0c0c7c1au: goto P_0c0c7c1a;
case 0x0c0c7c1cu: goto P_0c0c7c1c;
case 0x0c0c7c1eu: goto P_0c0c7c1e;
case 0x0c0c7c20u: goto P_0c0c7c20;
case 0x0c0c7c22u: goto P_0c0c7c22;
case 0x0c0c7c24u: goto P_0c0c7c24;
case 0x0c0c7c26u: goto P_0c0c7c26;
case 0x0c0c7c28u: goto P_0c0c7c28;
case 0x0c0c7c2au: goto P_0c0c7c2a;
case 0x0c0c7c2cu: goto P_0c0c7c2c;
case 0x0c0c7c2eu: goto P_0c0c7c2e;
case 0x0c0c7c30u: goto P_0c0c7c30;
case 0x0c0c7c32u: goto P_0c0c7c32;
case 0x0c0c9cc0u: goto P_0c0c9cc0;
case 0x0c0c9cc2u: goto P_0c0c9cc2;
case 0x0c0c9cc4u: goto P_0c0c9cc4;
case 0x0c0c9cc6u: goto P_0c0c9cc6;
case 0x0c0c9cc8u: goto P_0c0c9cc8;
case 0x0c0c9ccau: goto P_0c0c9cca;
case 0x0c0c9cccu: goto P_0c0c9ccc;
case 0x0c0c9cceu: goto P_0c0c9cce;
case 0x0c0c9cd0u: goto P_0c0c9cd0;
case 0x0c0c9cd2u: goto P_0c0c9cd2;
case 0x0c0c9cd4u: goto P_0c0c9cd4;
case 0x0c0c9cd6u: goto P_0c0c9cd6;
case 0x0c0c9cd8u: goto P_0c0c9cd8;
case 0x0c0c9cdau: goto P_0c0c9cda;
case 0x0c0c9cdcu: goto P_0c0c9cdc;
case 0x0c0c9cdeu: goto P_0c0c9cde;
case 0x0c0c9ce0u: goto P_0c0c9ce0;
case 0x0c0c9ce2u: goto P_0c0c9ce2;
case 0x0c0c9ce4u: goto P_0c0c9ce4;
default: return vf3_matrix_family(target,s,ram);
}
P_0c046e66: /* original 4f22, guest PC 0x0c046e66 */
if(!s->budget--) { s->failed_pc=0x0c046e66u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c046e68;
P_0c046e68: /* original 03ed, guest PC 0x0c046e68 */
if(!s->budget--) { s->failed_pc=0x0c046e68u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c046e6a;
P_0c046e6a: /* original 2338, guest PC 0x0c046e6a */
if(!s->budget--) { s->failed_pc=0x0c046e6au; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c046e6c;
P_0c046e6c: /* original 7ff4, guest PC 0x0c046e6c */
if(!s->budget--) { s->failed_pc=0x0c046e6cu; return 0; }
r[15]+=0xfffffff4u;
goto P_0c046e6e;
P_0c046e6e: /* original 8d1a, guest PC 0x0c046e6e */
if(!s->budget--) { s->failed_pc=0x0c046e6eu; return 0; }
cond=r[17]&1u;
r[12]=r[4];
if(cond) { goto P_0c046ea6; }
goto P_0c046e72;
P_0c046e70: /* original 6c43, guest PC 0x0c046e70 */
if(!s->budget--) { s->failed_pc=0x0c046e70u; return 0; }
r[12]=r[4];
goto P_0c046e72;
P_0c046e72: /* original 03ed, guest PC 0x0c046e72 */
if(!s->budget--) { s->failed_pc=0x0c046e72u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c046e74;
P_0c046e74: /* original ea03, guest PC 0x0c046e74 */
if(!s->budget--) { s->failed_pc=0x0c046e74u; return 0; }
r[10]=0x00000003u;
goto P_0c046e76;
P_0c046e76: /* original 633d, guest PC 0x0c046e76 */
if(!s->budget--) { s->failed_pc=0x0c046e76u; return 0; }
r[3]=r[3]&65535u;
goto P_0c046e78;
P_0c046e78: /* original 33a7, guest PC 0x0c046e78 */
if(!s->budget--) { s->failed_pc=0x0c046e78u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>(int32_t)r[10])!=0);
goto P_0c046e7a;
P_0c046e7a: /* original 8914, guest PC 0x0c046e7a */
if(!s->budget--) { s->failed_pc=0x0c046e7au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c046ea6; }
goto P_0c046e7c;
P_0c046e7c: /* original e054, guest PC 0x0c046e7c */
if(!s->budget--) { s->failed_pc=0x0c046e7cu; return 0; }
r[0]=0x00000054u;
goto P_0c046e7e;
P_0c046e7e: /* original 02ed, guest PC 0x0c046e7e */
if(!s->budget--) { s->failed_pc=0x0c046e7eu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c046e80;
P_0c046e80: /* original 622d, guest PC 0x0c046e80 */
if(!s->budget--) { s->failed_pc=0x0c046e80u; return 0; }
r[2]=r[2]&65535u;
goto P_0c046e82;
P_0c046e82: /* original 32a7, guest PC 0x0c046e82 */
if(!s->budget--) { s->failed_pc=0x0c046e82u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>(int32_t)r[10])!=0);
goto P_0c046e84;
P_0c046e84: /* original 890f, guest PC 0x0c046e84 */
if(!s->budget--) { s->failed_pc=0x0c046e84u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c046ea6; }
goto P_0c046e86;
P_0c046e86: /* original e044, guest PC 0x0c046e86 */
if(!s->budget--) { s->failed_pc=0x0c046e86u; return 0; }
r[0]=0x00000044u;
goto P_0c046e88;
P_0c046e88: /* original 03ee, guest PC 0x0c046e88 */
if(!s->budget--) { s->failed_pc=0x0c046e88u; return 0; }
r[3]=read(ram,r[14]+r[0],4);
goto P_0c046e8a;
P_0c046e8a: /* original 2338, guest PC 0x0c046e8a */
if(!s->budget--) { s->failed_pc=0x0c046e8au; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c046e8c;
P_0c046e8c: /* original 890b, guest PC 0x0c046e8c */
if(!s->budget--) { s->failed_pc=0x0c046e8cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c046ea6; }
goto P_0c046e8e;
P_0c046e8e: /* original e048, guest PC 0x0c046e8e */
if(!s->budget--) { s->failed_pc=0x0c046e8eu; return 0; }
r[0]=0x00000048u;
goto P_0c046e90;
P_0c046e90: /* original 03ee, guest PC 0x0c046e90 */
if(!s->budget--) { s->failed_pc=0x0c046e90u; return 0; }
r[3]=read(ram,r[14]+r[0],4);
goto P_0c046e92;
P_0c046e92: /* original 2338, guest PC 0x0c046e92 */
if(!s->budget--) { s->failed_pc=0x0c046e92u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c046e94;
P_0c046e94: /* original 8907, guest PC 0x0c046e94 */
if(!s->budget--) { s->failed_pc=0x0c046e94u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c046ea6; }
goto P_0c046e96;
P_0c046e96: /* original e054, guest PC 0x0c046e96 */
if(!s->budget--) { s->failed_pc=0x0c046e96u; return 0; }
r[0]=0x00000054u;
goto P_0c046e98;
P_0c046e98: /* original 02ed, guest PC 0x0c046e98 */
if(!s->budget--) { s->failed_pc=0x0c046e98u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c046e9a;
P_0c046e9a: /* original 2228, guest PC 0x0c046e9a */
if(!s->budget--) { s->failed_pc=0x0c046e9au; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c046e9c;
P_0c046e9c: /* original 8907, guest PC 0x0c046e9c */
if(!s->budget--) { s->failed_pc=0x0c046e9cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c046eae; }
goto P_0c046e9e;
P_0c046e9e: /* original e050, guest PC 0x0c046e9e */
if(!s->budget--) { s->failed_pc=0x0c046e9eu; return 0; }
r[0]=0x00000050u;
goto P_0c046ea0;
P_0c046ea0: /* original 01ee, guest PC 0x0c046ea0 */
if(!s->budget--) { s->failed_pc=0x0c046ea0u; return 0; }
r[1]=read(ram,r[14]+r[0],4);
goto P_0c046ea2;
P_0c046ea2: /* original 2118, guest PC 0x0c046ea2 */
if(!s->budget--) { s->failed_pc=0x0c046ea2u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[1])==0)!=0);
goto P_0c046ea4;
P_0c046ea4: /* original 8b03, guest PC 0x0c046ea4 */
if(!s->budget--) { s->failed_pc=0x0c046ea4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c046eae; }
goto P_0c046ea6;
P_0c046ea6: /* original 9001, guest PC 0x0c046ea6 */
if(!s->budget--) { s->failed_pc=0x0c046ea6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c046eacu,2);
goto P_0c046ea8;
P_0c046ea8: /* original a0c6, guest PC 0x0c046ea8 */
if(!s->budget--) { s->failed_pc=0x0c046ea8u; return 0; }
goto P_0c047038;
P_0c046eaa: /* original 0009, guest PC 0x0c046eaa */
if(!s->budget--) { s->failed_pc=0x0c046eaau; return 0; }
return vf3_matrix_family(0x0c046eacu,s,ram);
P_0c046eae: /* original db3e, guest PC 0x0c046eae */
if(!s->budget--) { s->failed_pc=0x0c046eaeu; return 0; }
r[11]=read(ram,0x0c046fa8u,4);
goto P_0c046eb0;
P_0c046eb0: /* original e500, guest PC 0x0c046eb0 */
if(!s->budget--) { s->failed_pc=0x0c046eb0u; return 0; }
r[5]=0x00000000u;
goto P_0c046eb2;
P_0c046eb2: /* original e660, guest PC 0x0c046eb2 */
if(!s->budget--) { s->failed_pc=0x0c046eb2u; return 0; }
r[6]=0x00000060u;
goto P_0c046eb4;
P_0c046eb4: /* original 6dc3, guest PC 0x0c046eb4 */
if(!s->budget--) { s->failed_pc=0x0c046eb4u; return 0; }
r[13]=r[12];
goto P_0c046eb6;
P_0c046eb6: /* original 4b0b, guest PC 0x0c046eb6 */
if(!s->budget--) { s->failed_pc=0x0c046eb6u; return 0; }
target=r[11];
r[16]=code_base|0x0c046ebau;
r[4]=r[12];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c046ebau) { target=s->pc; goto dispatch; }
goto P_0c046eba;
P_0c046eb8: /* original 64c3, guest PC 0x0c046eb8 */
if(!s->budget--) { s->failed_pc=0x0c046eb8u; return 0; }
r[4]=r[12];
goto P_0c046eba;
P_0c046eba: /* original e520, guest PC 0x0c046eba */
if(!s->budget--) { s->failed_pc=0x0c046ebau; return 0; }
r[5]=0x00000020u;
goto P_0c046ebc;
P_0c046ebc: /* original e610, guest PC 0x0c046ebc */
if(!s->budget--) { s->failed_pc=0x0c046ebcu; return 0; }
r[6]=0x00000010u;
goto P_0c046ebe;
P_0c046ebe: /* original 4b0b, guest PC 0x0c046ebe */
if(!s->budget--) { s->failed_pc=0x0c046ebeu; return 0; }
target=r[11];
r[16]=code_base|0x0c046ec2u;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c046ec2u) { target=s->pc; goto dispatch; }
goto P_0c046ec2;
P_0c046ec0: /* original 64d3, guest PC 0x0c046ec0 */
if(!s->budget--) { s->failed_pc=0x0c046ec0u; return 0; }
r[4]=r[13];
goto P_0c046ec2;
P_0c046ec2: /* original e620, guest PC 0x0c046ec2 */
if(!s->budget--) { s->failed_pc=0x0c046ec2u; return 0; }
r[6]=0x00000020u;
goto P_0c046ec4;
P_0c046ec4: /* original 64d3, guest PC 0x0c046ec4 */
if(!s->budget--) { s->failed_pc=0x0c046ec4u; return 0; }
r[4]=r[13];
goto P_0c046ec6;
P_0c046ec6: /* original 6563, guest PC 0x0c046ec6 */
if(!s->budget--) { s->failed_pc=0x0c046ec6u; return 0; }
r[5]=r[6];
goto P_0c046ec8;
P_0c046ec8: /* original 4b0b, guest PC 0x0c046ec8 */
if(!s->budget--) { s->failed_pc=0x0c046ec8u; return 0; }
target=r[11];
r[16]=code_base|0x0c046eccu;
r[4]+=0x00000010u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c046eccu) { target=s->pc; goto dispatch; }
goto P_0c046ecc;
P_0c046eca: /* original 7410, guest PC 0x0c046eca */
if(!s->budget--) { s->failed_pc=0x0c046ecau; return 0; }
r[4]+=0x00000010u;
goto P_0c046ecc;
P_0c046ecc: /* original 64d3, guest PC 0x0c046ecc */
if(!s->budget--) { s->failed_pc=0x0c046eccu; return 0; }
r[4]=r[13];
goto P_0c046ece;
P_0c046ece: /* original e500, guest PC 0x0c046ece */
if(!s->budget--) { s->failed_pc=0x0c046eceu; return 0; }
r[5]=0x00000000u;
goto P_0c046ed0;
P_0c046ed0: /* original e610, guest PC 0x0c046ed0 */
if(!s->budget--) { s->failed_pc=0x0c046ed0u; return 0; }
r[6]=0x00000010u;
goto P_0c046ed2;
P_0c046ed2: /* original 4b0b, guest PC 0x0c046ed2 */
if(!s->budget--) { s->failed_pc=0x0c046ed2u; return 0; }
target=r[11];
r[16]=code_base|0x0c046ed6u;
r[4]+=0x00000030u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c046ed6u) { target=s->pc; goto dispatch; }
goto P_0c046ed6;
P_0c046ed4: /* original 7430, guest PC 0x0c046ed4 */
if(!s->budget--) { s->failed_pc=0x0c046ed4u; return 0; }
r[4]+=0x00000030u;
goto P_0c046ed6;
P_0c046ed6: /* original e600, guest PC 0x0c046ed6 */
if(!s->budget--) { s->failed_pc=0x0c046ed6u; return 0; }
r[6]=0x00000000u;
goto P_0c046ed8;
P_0c046ed8: /* original 67d3, guest PC 0x0c046ed8 */
if(!s->budget--) { s->failed_pc=0x0c046ed8u; return 0; }
r[7]=r[13];
goto P_0c046eda;
P_0c046eda: /* original e410, guest PC 0x0c046eda */
if(!s->budget--) { s->failed_pc=0x0c046edau; return 0; }
r[4]=0x00000010u;
goto P_0c046edc;
P_0c046edc: /* original 65e3, guest PC 0x0c046edc */
if(!s->budget--) { s->failed_pc=0x0c046edcu; return 0; }
r[5]=r[14];
goto P_0c046ede;
P_0c046ede: /* original 6350, guest PC 0x0c046ede */
if(!s->budget--) { s->failed_pc=0x0c046edeu; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[5],1);
r[3]=tmp;
goto P_0c046ee0;
P_0c046ee0: /* original 2338, guest PC 0x0c046ee0 */
if(!s->budget--) { s->failed_pc=0x0c046ee0u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c046ee2;
P_0c046ee2: /* original 8905, guest PC 0x0c046ee2 */
if(!s->budget--) { s->failed_pc=0x0c046ee2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c046ef0; }
goto P_0c046ee4;
P_0c046ee4: /* original 6354, guest PC 0x0c046ee4 */
if(!s->budget--) { s->failed_pc=0x0c046ee4u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[5],1);
r[5]+=1;
r[3]=tmp;
goto P_0c046ee6;
P_0c046ee6: /* original 7601, guest PC 0x0c046ee6 */
if(!s->budget--) { s->failed_pc=0x0c046ee6u; return 0; }
r[6]+=0x00000001u;
goto P_0c046ee8;
P_0c046ee8: /* original 3643, guest PC 0x0c046ee8 */
if(!s->budget--) { s->failed_pc=0x0c046ee8u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[6]>=(int32_t)r[4])!=0);
goto P_0c046eea;
P_0c046eea: /* original 2730, guest PC 0x0c046eea */
if(!s->budget--) { s->failed_pc=0x0c046eeau; return 0; }
write(ram,r[7],r[3],1);
goto P_0c046eec;
P_0c046eec: /* original 8ff7, guest PC 0x0c046eec */
if(!s->budget--) { s->failed_pc=0x0c046eecu; return 0; }
cond=r[17]&1u;
r[7]+=0x00000001u;
if(!cond) { goto P_0c046ede; }
goto P_0c046ef0;
P_0c046eee: /* original 7701, guest PC 0x0c046eee */
if(!s->budget--) { s->failed_pc=0x0c046eeeu; return 0; }
r[7]+=0x00000001u;
goto P_0c046ef0;
P_0c046ef0: /* original 66e3, guest PC 0x0c046ef0 */
if(!s->budget--) { s->failed_pc=0x0c046ef0u; return 0; }
r[6]=r[14];
goto P_0c046ef2;
P_0c046ef2: /* original e500, guest PC 0x0c046ef2 */
if(!s->budget--) { s->failed_pc=0x0c046ef2u; return 0; }
r[5]=0x00000000u;
goto P_0c046ef4;
P_0c046ef4: /* original 68d3, guest PC 0x0c046ef4 */
if(!s->budget--) { s->failed_pc=0x0c046ef4u; return 0; }
r[8]=r[13];
goto P_0c046ef6;
P_0c046ef6: /* original 6753, guest PC 0x0c046ef6 */
if(!s->budget--) { s->failed_pc=0x0c046ef6u; return 0; }
r[7]=r[5];
goto P_0c046ef8;
P_0c046ef8: /* original e920, guest PC 0x0c046ef8 */
if(!s->budget--) { s->failed_pc=0x0c046ef8u; return 0; }
r[9]=0x00000020u;
goto P_0c046efa;
P_0c046efa: /* original 7810, guest PC 0x0c046efa */
if(!s->budget--) { s->failed_pc=0x0c046efau; return 0; }
r[8]+=0x00000010u;
goto P_0c046efc;
P_0c046efc: /* original 7612, guest PC 0x0c046efc */
if(!s->budget--) { s->failed_pc=0x0c046efcu; return 0; }
r[6]+=0x00000012u;
goto P_0c046efe;
P_0c046efe: /* original 6360, guest PC 0x0c046efe */
if(!s->budget--) { s->failed_pc=0x0c046efeu; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[6],1);
r[3]=tmp;
goto P_0c046f00;
P_0c046f00: /* original 2338, guest PC 0x0c046f00 */
if(!s->budget--) { s->failed_pc=0x0c046f00u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c046f02;
P_0c046f02: /* original 8905, guest PC 0x0c046f02 */
if(!s->budget--) { s->failed_pc=0x0c046f02u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c046f10; }
goto P_0c046f04;
P_0c046f04: /* original 6364, guest PC 0x0c046f04 */
if(!s->budget--) { s->failed_pc=0x0c046f04u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[6],1);
r[6]+=1;
r[3]=tmp;
goto P_0c046f06;
P_0c046f06: /* original 7701, guest PC 0x0c046f06 */
if(!s->budget--) { s->failed_pc=0x0c046f06u; return 0; }
r[7]+=0x00000001u;
goto P_0c046f08;
P_0c046f08: /* original 3793, guest PC 0x0c046f08 */
if(!s->budget--) { s->failed_pc=0x0c046f08u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[7]>=(int32_t)r[9])!=0);
goto P_0c046f0a;
P_0c046f0a: /* original 2830, guest PC 0x0c046f0a */
if(!s->budget--) { s->failed_pc=0x0c046f0au; return 0; }
write(ram,r[8],r[3],1);
goto P_0c046f0c;
P_0c046f0c: /* original 8ff7, guest PC 0x0c046f0c */
if(!s->budget--) { s->failed_pc=0x0c046f0cu; return 0; }
cond=r[17]&1u;
r[8]+=0x00000001u;
if(!cond) { goto P_0c046efe; }
goto P_0c046f10;
P_0c046f0e: /* original 7801, guest PC 0x0c046f0e */
if(!s->budget--) { s->failed_pc=0x0c046f0eu; return 0; }
r[8]+=0x00000001u;
goto P_0c046f10;
P_0c046f10: /* original 67e3, guest PC 0x0c046f10 */
if(!s->budget--) { s->failed_pc=0x0c046f10u; return 0; }
r[7]=r[14];
goto P_0c046f12;
P_0c046f12: /* original 69d3, guest PC 0x0c046f12 */
if(!s->budget--) { s->failed_pc=0x0c046f12u; return 0; }
r[9]=r[13];
goto P_0c046f14;
P_0c046f14: /* original 6653, guest PC 0x0c046f14 */
if(!s->budget--) { s->failed_pc=0x0c046f14u; return 0; }
r[6]=r[5];
goto P_0c046f16;
P_0c046f16: /* original 7734, guest PC 0x0c046f16 */
if(!s->budget--) { s->failed_pc=0x0c046f16u; return 0; }
r[7]+=0x00000034u;
goto P_0c046f18;
P_0c046f18: /* original 7930, guest PC 0x0c046f18 */
if(!s->budget--) { s->failed_pc=0x0c046f18u; return 0; }
r[9]+=0x00000030u;
goto P_0c046f1a;
P_0c046f1a: /* original 6370, guest PC 0x0c046f1a */
if(!s->budget--) { s->failed_pc=0x0c046f1au; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[7],1);
r[3]=tmp;
goto P_0c046f1c;
P_0c046f1c: /* original 2338, guest PC 0x0c046f1c */
if(!s->budget--) { s->failed_pc=0x0c046f1cu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c046f1e;
P_0c046f1e: /* original 8905, guest PC 0x0c046f1e */
if(!s->budget--) { s->failed_pc=0x0c046f1eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c046f2c; }
goto P_0c046f20;
P_0c046f20: /* original 6374, guest PC 0x0c046f20 */
if(!s->budget--) { s->failed_pc=0x0c046f20u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[7],1);
r[7]+=1;
r[3]=tmp;
goto P_0c046f22;
P_0c046f22: /* original 7601, guest PC 0x0c046f22 */
if(!s->budget--) { s->failed_pc=0x0c046f22u; return 0; }
r[6]+=0x00000001u;
goto P_0c046f24;
P_0c046f24: /* original 3643, guest PC 0x0c046f24 */
if(!s->budget--) { s->failed_pc=0x0c046f24u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[6]>=(int32_t)r[4])!=0);
goto P_0c046f26;
P_0c046f26: /* original 2930, guest PC 0x0c046f26 */
if(!s->budget--) { s->failed_pc=0x0c046f26u; return 0; }
write(ram,r[9],r[3],1);
goto P_0c046f28;
P_0c046f28: /* original 8ff7, guest PC 0x0c046f28 */
if(!s->budget--) { s->failed_pc=0x0c046f28u; return 0; }
cond=r[17]&1u;
r[9]+=0x00000001u;
if(!cond) { goto P_0c046f1a; }
goto P_0c046f2c;
P_0c046f2a: /* original 7901, guest PC 0x0c046f2a */
if(!s->budget--) { s->failed_pc=0x0c046f2au; return 0; }
r[9]+=0x00000001u;
goto P_0c046f2c;
P_0c046f2c: /* original e04c, guest PC 0x0c046f2c */
if(!s->budget--) { s->failed_pc=0x0c046f2cu; return 0; }
r[0]=0x0000004cu;
goto P_0c046f2e;
P_0c046f2e: /* original 943a, guest PC 0x0c046f2e */
if(!s->budget--) { s->failed_pc=0x0c046f2eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c046fa6u,2);
goto P_0c046f30;
P_0c046f30: /* original 09ed, guest PC 0x0c046f30 */
if(!s->budget--) { s->failed_pc=0x0c046f30u; return 0; }
r[9]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c046f32;
P_0c046f32: /* original d01e, guest PC 0x0c046f32 */
if(!s->budget--) { s->failed_pc=0x0c046f32u; return 0; }
r[0]=read(ram,0x0c046facu,4);
goto P_0c046f34;
P_0c046f34: /* original 699d, guest PC 0x0c046f34 */
if(!s->budget--) { s->failed_pc=0x0c046f34u; return 0; }
r[9]=r[9]&65535u;
goto P_0c046f36;
P_0c046f36: /* original 29a9, guest PC 0x0c046f36 */
if(!s->budget--) { s->failed_pc=0x0c046f36u; return 0; }
r[9]&=r[10];
goto P_0c046f38;
P_0c046f38: /* original 4908, guest PC 0x0c046f38 */
if(!s->budget--) { s->failed_pc=0x0c046f38u; return 0; }
r[9]<<=2;
goto P_0c046f3a;
P_0c046f3a: /* original 099e, guest PC 0x0c046f3a */
if(!s->budget--) { s->failed_pc=0x0c046f3au; return 0; }
r[9]=read(ram,r[9]+r[0],4);
goto P_0c046f3c;
P_0c046f3c: /* original e054, guest PC 0x0c046f3c */
if(!s->budget--) { s->failed_pc=0x0c046f3cu; return 0; }
r[0]=0x00000054u;
goto P_0c046f3e;
P_0c046f3e: /* original 08ed, guest PC 0x0c046f3e */
if(!s->budget--) { s->failed_pc=0x0c046f3eu; return 0; }
r[8]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c046f40;
P_0c046f40: /* original d01b, guest PC 0x0c046f40 */
if(!s->budget--) { s->failed_pc=0x0c046f40u; return 0; }
r[0]=read(ram,0x0c046fb0u,4);
goto P_0c046f42;
P_0c046f42: /* original 6693, guest PC 0x0c046f42 */
if(!s->budget--) { s->failed_pc=0x0c046f42u; return 0; }
r[6]=r[9];
goto P_0c046f44;
P_0c046f44: /* original 688d, guest PC 0x0c046f44 */
if(!s->budget--) { s->failed_pc=0x0c046f44u; return 0; }
r[8]=r[8]&65535u;
goto P_0c046f46;
P_0c046f46: /* original 28a9, guest PC 0x0c046f46 */
if(!s->budget--) { s->failed_pc=0x0c046f46u; return 0; }
r[8]&=r[10];
goto P_0c046f48;
P_0c046f48: /* original 4808, guest PC 0x0c046f48 */
if(!s->budget--) { s->failed_pc=0x0c046f48u; return 0; }
r[8]<<=2;
goto P_0c046f4a;
P_0c046f4a: /* original 088e, guest PC 0x0c046f4a */
if(!s->budget--) { s->failed_pc=0x0c046f4au; return 0; }
r[8]=read(ram,r[8]+r[0],4);
goto P_0c046f4c;
P_0c046f4c: /* original e05c, guest PC 0x0c046f4c */
if(!s->budget--) { s->failed_pc=0x0c046f4cu; return 0; }
r[0]=0x0000005cu;
goto P_0c046f4e;
P_0c046f4e: /* original 0aee, guest PC 0x0c046f4e */
if(!s->budget--) { s->failed_pc=0x0c046f4eu; return 0; }
r[10]=read(ram,r[14]+r[0],4);
goto P_0c046f50;
P_0c046f50: /* original e04e, guest PC 0x0c046f50 */
if(!s->budget--) { s->failed_pc=0x0c046f50u; return 0; }
r[0]=0x0000004eu;
goto P_0c046f52;
P_0c046f52: /* original 03ed, guest PC 0x0c046f52 */
if(!s->budget--) { s->failed_pc=0x0c046f52u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c046f54;
P_0c046f54: /* original e042, guest PC 0x0c046f54 */
if(!s->budget--) { s->failed_pc=0x0c046f54u; return 0; }
r[0]=0x00000042u;
goto P_0c046f56;
P_0c046f56: /* original 368c, guest PC 0x0c046f56 */
if(!s->budget--) { s->failed_pc=0x0c046f56u; return 0; }
r[6]+=r[8];
goto P_0c046f58;
P_0c046f58: /* original 0d35, guest PC 0x0c046f58 */
if(!s->budget--) { s->failed_pc=0x0c046f58u; return 0; }
write(ram,r[13]+r[0],r[3],2);
goto P_0c046f5a;
P_0c046f5a: /* original e04c, guest PC 0x0c046f5a */
if(!s->budget--) { s->failed_pc=0x0c046f5au; return 0; }
r[0]=0x0000004cu;
goto P_0c046f5c;
P_0c046f5c: /* original 02ed, guest PC 0x0c046f5c */
if(!s->budget--) { s->failed_pc=0x0c046f5cu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c046f5e;
P_0c046f5e: /* original e040, guest PC 0x0c046f5e */
if(!s->budget--) { s->failed_pc=0x0c046f5eu; return 0; }
r[0]=0x00000040u;
goto P_0c046f60;
P_0c046f60: /* original 3a6c, guest PC 0x0c046f60 */
if(!s->budget--) { s->failed_pc=0x0c046f60u; return 0; }
r[10]+=r[6];
goto P_0c046f62;
P_0c046f62: /* original 0d25, guest PC 0x0c046f62 */
if(!s->budget--) { s->failed_pc=0x0c046f62u; return 0; }
write(ram,r[13]+r[0],r[2],2);
goto P_0c046f64;
P_0c046f64: /* original e054, guest PC 0x0c046f64 */
if(!s->budget--) { s->failed_pc=0x0c046f64u; return 0; }
r[0]=0x00000054u;
goto P_0c046f66;
P_0c046f66: /* original 2f42, guest PC 0x0c046f66 */
if(!s->budget--) { s->failed_pc=0x0c046f66u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c046f68;
P_0c046f68: /* original 03ed, guest PC 0x0c046f68 */
if(!s->budget--) { s->failed_pc=0x0c046f68u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c046f6a;
P_0c046f6a: /* original 2338, guest PC 0x0c046f6a */
if(!s->budget--) { s->failed_pc=0x0c046f6au; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c046f6c;
P_0c046f6c: /* original 8d04, guest PC 0x0c046f6c */
if(!s->budget--) { s->failed_pc=0x0c046f6cu; return 0; }
cond=r[17]&1u;
r[10]+=r[4];
if(cond) { goto P_0c046f78; }
goto P_0c046f70;
P_0c046f6e: /* original 3a4c, guest PC 0x0c046f6e */
if(!s->budget--) { s->failed_pc=0x0c046f6eu; return 0; }
r[10]+=r[4];
goto P_0c046f70;
P_0c046f70: /* original e050, guest PC 0x0c046f70 */
if(!s->budget--) { s->failed_pc=0x0c046f70u; return 0; }
r[0]=0x00000050u;
goto P_0c046f72;
P_0c046f72: /* original 01ee, guest PC 0x0c046f72 */
if(!s->budget--) { s->failed_pc=0x0c046f72u; return 0; }
r[1]=read(ram,r[14]+r[0],4);
goto P_0c046f74;
P_0c046f74: /* original 2118, guest PC 0x0c046f74 */
if(!s->budget--) { s->failed_pc=0x0c046f74u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[1])==0)!=0);
goto P_0c046f76;
P_0c046f76: /* original 8b03, guest PC 0x0c046f76 */
if(!s->budget--) { s->failed_pc=0x0c046f76u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c046f80; }
goto P_0c046f78;
P_0c046f78: /* original e044, guest PC 0x0c046f78 */
if(!s->budget--) { s->failed_pc=0x0c046f78u; return 0; }
r[0]=0x00000044u;
goto P_0c046f7a;
P_0c046f7a: /* original 0d55, guest PC 0x0c046f7a */
if(!s->budget--) { s->failed_pc=0x0c046f7au; return 0; }
write(ram,r[13]+r[0],r[5],2);
goto P_0c046f7c;
P_0c046f7c: /* original a007, guest PC 0x0c046f7c */
if(!s->budget--) { s->failed_pc=0x0c046f7cu; return 0; }
write(ram,r[15]+8,r[5],4);
goto P_0c046f8e;
P_0c046f7e: /* original 1f52, guest PC 0x0c046f7e */
if(!s->budget--) { s->failed_pc=0x0c046f7eu; return 0; }
write(ram,r[15]+8,r[5],4);
goto P_0c046f80;
P_0c046f80: /* original e054, guest PC 0x0c046f80 */
if(!s->budget--) { s->failed_pc=0x0c046f80u; return 0; }
r[0]=0x00000054u;
goto P_0c046f82;
P_0c046f82: /* original 6393, guest PC 0x0c046f82 */
if(!s->budget--) { s->failed_pc=0x0c046f82u; return 0; }
r[3]=r[9];
goto P_0c046f84;
P_0c046f84: /* original 02ed, guest PC 0x0c046f84 */
if(!s->budget--) { s->failed_pc=0x0c046f84u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c046f86;
P_0c046f86: /* original 334c, guest PC 0x0c046f86 */
if(!s->budget--) { s->failed_pc=0x0c046f86u; return 0; }
r[3]+=r[4];
goto P_0c046f88;
P_0c046f88: /* original e044, guest PC 0x0c046f88 */
if(!s->budget--) { s->failed_pc=0x0c046f88u; return 0; }
r[0]=0x00000044u;
goto P_0c046f8a;
P_0c046f8a: /* original 0d25, guest PC 0x0c046f8a */
if(!s->budget--) { s->failed_pc=0x0c046f8au; return 0; }
write(ram,r[13]+r[0],r[2],2);
goto P_0c046f8c;
P_0c046f8c: /* original 1f32, guest PC 0x0c046f8c */
if(!s->budget--) { s->failed_pc=0x0c046f8cu; return 0; }
write(ram,r[15]+8,r[3],4);
goto P_0c046f8e;
P_0c046f8e: /* original e05c, guest PC 0x0c046f8e */
if(!s->budget--) { s->failed_pc=0x0c046f8eu; return 0; }
r[0]=0x0000005cu;
goto P_0c046f90;
P_0c046f90: /* original 02ee, guest PC 0x0c046f90 */
if(!s->budget--) { s->failed_pc=0x0c046f90u; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c046f92;
P_0c046f92: /* original 2228, guest PC 0x0c046f92 */
if(!s->budget--) { s->failed_pc=0x0c046f92u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c046f94;
P_0c046f94: /* original 8903, guest PC 0x0c046f94 */
if(!s->budget--) { s->failed_pc=0x0c046f94u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c046f9e; }
goto P_0c046f96;
P_0c046f96: /* original e058, guest PC 0x0c046f96 */
if(!s->budget--) { s->failed_pc=0x0c046f96u; return 0; }
r[0]=0x00000058u;
goto P_0c046f98;
P_0c046f98: /* original 02ee, guest PC 0x0c046f98 */
if(!s->budget--) { s->failed_pc=0x0c046f98u; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c046f9a;
P_0c046f9a: /* original 2228, guest PC 0x0c046f9a */
if(!s->budget--) { s->failed_pc=0x0c046f9au; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c046f9c;
P_0c046f9c: /* original 8b0a, guest PC 0x0c046f9c */
if(!s->budget--) { s->failed_pc=0x0c046f9cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c046fb4; }
goto P_0c046f9e;
P_0c046f9e: /* original e048, guest PC 0x0c046f9e */
if(!s->budget--) { s->failed_pc=0x0c046f9eu; return 0; }
r[0]=0x00000048u;
goto P_0c046fa0;
P_0c046fa0: /* original 0d56, guest PC 0x0c046fa0 */
if(!s->budget--) { s->failed_pc=0x0c046fa0u; return 0; }
write(ram,r[13]+r[0],r[5],4);
goto P_0c046fa2;
P_0c046fa2: /* original a00d, guest PC 0x0c046fa2 */
if(!s->budget--) { s->failed_pc=0x0c046fa2u; return 0; }
write(ram,r[15]+4,r[5],4);
goto P_0c046fc0;
P_0c046fa4: /* original 1f51, guest PC 0x0c046fa4 */
if(!s->budget--) { s->failed_pc=0x0c046fa4u; return 0; }
write(ram,r[15]+4,r[5],4);
return vf3_matrix_family(0x0c046fa6u,s,ram);
P_0c046fb4: /* original e05c, guest PC 0x0c046fb4 */
if(!s->budget--) { s->failed_pc=0x0c046fb4u; return 0; }
r[0]=0x0000005cu;
goto P_0c046fb6;
P_0c046fb6: /* original 02ee, guest PC 0x0c046fb6 */
if(!s->budget--) { s->failed_pc=0x0c046fb6u; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c046fb8;
P_0c046fb8: /* original 364c, guest PC 0x0c046fb8 */
if(!s->budget--) { s->failed_pc=0x0c046fb8u; return 0; }
r[6]+=r[4];
goto P_0c046fba;
P_0c046fba: /* original e048, guest PC 0x0c046fba */
if(!s->budget--) { s->failed_pc=0x0c046fbau; return 0; }
r[0]=0x00000048u;
goto P_0c046fbc;
P_0c046fbc: /* original 0d26, guest PC 0x0c046fbc */
if(!s->budget--) { s->failed_pc=0x0c046fbcu; return 0; }
write(ram,r[13]+r[0],r[2],4);
goto P_0c046fbe;
P_0c046fbe: /* original 1f61, guest PC 0x0c046fbe */
if(!s->budget--) { s->failed_pc=0x0c046fbeu; return 0; }
write(ram,r[15]+4,r[6],4);
goto P_0c046fc0;
P_0c046fc0: /* original 2998, guest PC 0x0c046fc0 */
if(!s->budget--) { s->failed_pc=0x0c046fc0u; return 0; }
r[17]=(r[17]&~1u)|(((r[9]&r[9])==0)!=0);
goto P_0c046fc2;
P_0c046fc2: /* original 890d, guest PC 0x0c046fc2 */
if(!s->budget--) { s->failed_pc=0x0c046fc2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c046fe0; }
goto P_0c046fc4;
P_0c046fc4: /* original e044, guest PC 0x0c046fc4 */
if(!s->budget--) { s->failed_pc=0x0c046fc4u; return 0; }
r[0]=0x00000044u;
goto P_0c046fc6;
P_0c046fc6: /* original d341, guest PC 0x0c046fc6 */
if(!s->budget--) { s->failed_pc=0x0c046fc6u; return 0; }
r[3]=read(ram,0x0c0470ccu,4);
goto P_0c046fc8;
P_0c046fc8: /* original 05ee, guest PC 0x0c046fc8 */
if(!s->budget--) { s->failed_pc=0x0c046fc8u; return 0; }
r[5]=read(ram,r[14]+r[0],4);
goto P_0c046fca;
P_0c046fca: /* original e620, guest PC 0x0c046fca */
if(!s->budget--) { s->failed_pc=0x0c046fcau; return 0; }
r[6]=0x00000020u;
goto P_0c046fcc;
P_0c046fcc: /* original 64c3, guest PC 0x0c046fcc */
if(!s->budget--) { s->failed_pc=0x0c046fccu; return 0; }
r[4]=r[12];
goto P_0c046fce;
P_0c046fce: /* original 430b, guest PC 0x0c046fce */
if(!s->budget--) { s->failed_pc=0x0c046fceu; return 0; }
target=r[3];
r[16]=code_base|0x0c046fd2u;
r[4]+=0x00000060u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c046fd2u) { target=s->pc; goto dispatch; }
goto P_0c046fd2;
P_0c046fd0: /* original 7460, guest PC 0x0c046fd0 */
if(!s->budget--) { s->failed_pc=0x0c046fd0u; return 0; }
r[4]+=0x00000060u;
goto P_0c046fd2;
P_0c046fd2: /* original e048, guest PC 0x0c046fd2 */
if(!s->budget--) { s->failed_pc=0x0c046fd2u; return 0; }
r[0]=0x00000048u;
goto P_0c046fd4;
P_0c046fd4: /* original 64f2, guest PC 0x0c046fd4 */
if(!s->budget--) { s->failed_pc=0x0c046fd4u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c046fd6;
P_0c046fd6: /* original d33d, guest PC 0x0c046fd6 */
if(!s->budget--) { s->failed_pc=0x0c046fd6u; return 0; }
r[3]=read(ram,0x0c0470ccu,4);
goto P_0c046fd8;
P_0c046fd8: /* original 6693, guest PC 0x0c046fd8 */
if(!s->budget--) { s->failed_pc=0x0c046fd8u; return 0; }
r[6]=r[9];
goto P_0c046fda;
P_0c046fda: /* original 05ee, guest PC 0x0c046fda */
if(!s->budget--) { s->failed_pc=0x0c046fdau; return 0; }
r[5]=read(ram,r[14]+r[0],4);
goto P_0c046fdc;
P_0c046fdc: /* original 430b, guest PC 0x0c046fdc */
if(!s->budget--) { s->failed_pc=0x0c046fdcu; return 0; }
target=r[3];
r[16]=code_base|0x0c046fe0u;
r[4]+=r[12];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c046fe0u) { target=s->pc; goto dispatch; }
goto P_0c046fe0;
P_0c046fde: /* original 34cc, guest PC 0x0c046fde */
if(!s->budget--) { s->failed_pc=0x0c046fdeu; return 0; }
r[4]+=r[12];
goto P_0c046fe0;
P_0c046fe0: /* original 2888, guest PC 0x0c046fe0 */
if(!s->budget--) { s->failed_pc=0x0c046fe0u; return 0; }
r[17]=(r[17]&~1u)|(((r[8]&r[8])==0)!=0);
goto P_0c046fe2;
P_0c046fe2: /* original 8906, guest PC 0x0c046fe2 */
if(!s->budget--) { s->failed_pc=0x0c046fe2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c046ff2; }
goto P_0c046fe4;
P_0c046fe4: /* original e050, guest PC 0x0c046fe4 */
if(!s->budget--) { s->failed_pc=0x0c046fe4u; return 0; }
r[0]=0x00000050u;
goto P_0c046fe6;
P_0c046fe6: /* original 54f2, guest PC 0x0c046fe6 */
if(!s->budget--) { s->failed_pc=0x0c046fe6u; return 0; }
r[4]=read(ram,r[15]+8,4);
goto P_0c046fe8;
P_0c046fe8: /* original d338, guest PC 0x0c046fe8 */
if(!s->budget--) { s->failed_pc=0x0c046fe8u; return 0; }
r[3]=read(ram,0x0c0470ccu,4);
goto P_0c046fea;
P_0c046fea: /* original 6683, guest PC 0x0c046fea */
if(!s->budget--) { s->failed_pc=0x0c046feau; return 0; }
r[6]=r[8];
goto P_0c046fec;
P_0c046fec: /* original 05ee, guest PC 0x0c046fec */
if(!s->budget--) { s->failed_pc=0x0c046fecu; return 0; }
r[5]=read(ram,r[14]+r[0],4);
goto P_0c046fee;
P_0c046fee: /* original 430b, guest PC 0x0c046fee */
if(!s->budget--) { s->failed_pc=0x0c046feeu; return 0; }
target=r[3];
r[16]=code_base|0x0c046ff2u;
r[4]+=r[12];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c046ff2u) { target=s->pc; goto dispatch; }
goto P_0c046ff2;
P_0c046ff0: /* original 34cc, guest PC 0x0c046ff0 */
if(!s->budget--) { s->failed_pc=0x0c046ff0u; return 0; }
r[4]+=r[12];
goto P_0c046ff2;
P_0c046ff2: /* original e05c, guest PC 0x0c046ff2 */
if(!s->budget--) { s->failed_pc=0x0c046ff2u; return 0; }
r[0]=0x0000005cu;
goto P_0c046ff4;
P_0c046ff4: /* original 02ee, guest PC 0x0c046ff4 */
if(!s->budget--) { s->failed_pc=0x0c046ff4u; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c046ff6;
P_0c046ff6: /* original 2228, guest PC 0x0c046ff6 */
if(!s->budget--) { s->failed_pc=0x0c046ff6u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c046ff8;
P_0c046ff8: /* original 8906, guest PC 0x0c046ff8 */
if(!s->budget--) { s->failed_pc=0x0c046ff8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c047008; }
goto P_0c046ffa;
P_0c046ffa: /* original 06ee, guest PC 0x0c046ffa */
if(!s->budget--) { s->failed_pc=0x0c046ffau; return 0; }
r[6]=read(ram,r[14]+r[0],4);
goto P_0c046ffc;
P_0c046ffc: /* original e058, guest PC 0x0c046ffc */
if(!s->budget--) { s->failed_pc=0x0c046ffcu; return 0; }
r[0]=0x00000058u;
goto P_0c046ffe;
P_0c046ffe: /* original d333, guest PC 0x0c046ffe */
if(!s->budget--) { s->failed_pc=0x0c046ffeu; return 0; }
r[3]=read(ram,0x0c0470ccu,4);
goto P_0c047000;
P_0c047000: /* original 54f1, guest PC 0x0c047000 */
if(!s->budget--) { s->failed_pc=0x0c047000u; return 0; }
r[4]=read(ram,r[15]+4,4);
goto P_0c047002;
P_0c047002: /* original 05ee, guest PC 0x0c047002 */
if(!s->budget--) { s->failed_pc=0x0c047002u; return 0; }
r[5]=read(ram,r[14]+r[0],4);
goto P_0c047004;
P_0c047004: /* original 430b, guest PC 0x0c047004 */
if(!s->budget--) { s->failed_pc=0x0c047004u; return 0; }
target=r[3];
r[16]=code_base|0x0c047008u;
r[4]+=r[12];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c047008u) { target=s->pc; goto dispatch; }
goto P_0c047008;
P_0c047006: /* original 34cc, guest PC 0x0c047006 */
if(!s->budget--) { s->failed_pc=0x0c047006u; return 0; }
r[4]+=r[12];
goto P_0c047008;
P_0c047008: /* original 9e5a, guest PC 0x0c047008 */
if(!s->budget--) { s->failed_pc=0x0c047008u; return 0; }
r[14]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0470c0u,2);
goto P_0c04700a;
P_0c04700a: /* original 2ea9, guest PC 0x0c04700a */
if(!s->budget--) { s->failed_pc=0x0c04700au; return 0; }
r[14]&=r[10];
goto P_0c04700c;
P_0c04700c: /* original 2ee8, guest PC 0x0c04700c */
if(!s->budget--) { s->failed_pc=0x0c04700cu; return 0; }
r[17]=(r[17]&~1u)|(((r[14]&r[14])==0)!=0);
goto P_0c04700e;
P_0c04700e: /* original 8905, guest PC 0x0c04700e */
if(!s->budget--) { s->failed_pc=0x0c04700eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04701c; }
goto P_0c047010;
P_0c047010: /* original 9657, guest PC 0x0c047010 */
if(!s->budget--) { s->failed_pc=0x0c047010u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0470c2u,2);
goto P_0c047012;
P_0c047012: /* original 64c3, guest PC 0x0c047012 */
if(!s->budget--) { s->failed_pc=0x0c047012u; return 0; }
r[4]=r[12];
goto P_0c047014;
P_0c047014: /* original e500, guest PC 0x0c047014 */
if(!s->budget--) { s->failed_pc=0x0c047014u; return 0; }
r[5]=0x00000000u;
goto P_0c047016;
P_0c047016: /* original 36e8, guest PC 0x0c047016 */
if(!s->budget--) { s->failed_pc=0x0c047016u; return 0; }
r[6]-=r[14];
goto P_0c047018;
P_0c047018: /* original 4b0b, guest PC 0x0c047018 */
if(!s->budget--) { s->failed_pc=0x0c047018u; return 0; }
target=r[11];
r[16]=code_base|0x0c04701cu;
r[4]+=r[10];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04701cu) { target=s->pc; goto dispatch; }
goto P_0c04701c;
P_0c04701a: /* original 34ac, guest PC 0x0c04701a */
if(!s->budget--) { s->failed_pc=0x0c04701au; return 0; }
r[4]+=r[10];
goto P_0c04701c;
P_0c04701c: /* original 65a3, guest PC 0x0c04701c */
if(!s->budget--) { s->failed_pc=0x0c04701cu; return 0; }
r[5]=r[10];
goto P_0c04701e;
P_0c04701e: /* original b0db, guest PC 0x0c04701e */
if(!s->budget--) { s->failed_pc=0x0c04701eu; return 0; }
target=0x0c0471d8u; r[16]=code_base|0x0c047022u;
r[4]=r[12];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c047022u) { target=s->pc; goto dispatch; }
goto P_0c047022;
P_0c047020: /* original 64c3, guest PC 0x0c047020 */
if(!s->budget--) { s->failed_pc=0x0c047020u; return 0; }
r[4]=r[12];
goto P_0c047022;
P_0c047022: /* original e146, guest PC 0x0c047022 */
if(!s->budget--) { s->failed_pc=0x0c047022u; return 0; }
r[1]=0x00000046u;
goto P_0c047024;
P_0c047024: /* original 2ee8, guest PC 0x0c047024 */
if(!s->budget--) { s->failed_pc=0x0c047024u; return 0; }
r[17]=(r[17]&~1u)|(((r[14]&r[14])==0)!=0);
goto P_0c047026;
P_0c047026: /* original 31dc, guest PC 0x0c047026 */
if(!s->budget--) { s->failed_pc=0x0c047026u; return 0; }
r[1]+=r[13];
goto P_0c047028;
P_0c047028: /* original 8d02, guest PC 0x0c047028 */
if(!s->budget--) { s->failed_pc=0x0c047028u; return 0; }
cond=r[17]&1u;
write(ram,r[1],r[0],2);
if(cond) { goto P_0c047030; }
goto P_0c04702c;
P_0c04702a: /* original 2101, guest PC 0x0c04702a */
if(!s->budget--) { s->failed_pc=0x0c04702au; return 0; }
write(ram,r[1],r[0],2);
goto P_0c04702c;
P_0c04702c: /* original a001, guest PC 0x0c04702c */
if(!s->budget--) { s->failed_pc=0x0c04702cu; return 0; }
r[0]=0x00000001u;
goto P_0c047032;
P_0c04702e: /* original e001, guest PC 0x0c04702e */
if(!s->budget--) { s->failed_pc=0x0c04702eu; return 0; }
r[0]=0x00000001u;
goto P_0c047030;
P_0c047030: /* original e000, guest PC 0x0c047030 */
if(!s->budget--) { s->failed_pc=0x0c047030u; return 0; }
r[0]=0x00000000u;
goto P_0c047032;
P_0c047032: /* original 4a19, guest PC 0x0c047032 */
if(!s->budget--) { s->failed_pc=0x0c047032u; return 0; }
r[10]>>=8;
goto P_0c047034;
P_0c047034: /* original 4a01, guest PC 0x0c047034 */
if(!s->budget--) { s->failed_pc=0x0c047034u; return 0; }
r[17]=(r[17]&~1u)|((r[10]&1)!=0);
r[10]>>=1;
goto P_0c047036;
P_0c047036: /* original 30ac, guest PC 0x0c047036 */
if(!s->budget--) { s->failed_pc=0x0c047036u; return 0; }
r[0]+=r[10];
goto P_0c047038;
P_0c047038: /* original 7f0c, guest PC 0x0c047038 */
if(!s->budget--) { s->failed_pc=0x0c047038u; return 0; }
r[15]+=0x0000000cu;
goto P_0c04703a;
P_0c04703a: /* original 4f26, guest PC 0x0c04703a */
if(!s->budget--) { s->failed_pc=0x0c04703au; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c04703c;
P_0c04703c: /* original 68f6, guest PC 0x0c04703c */
if(!s->budget--) { s->failed_pc=0x0c04703cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c04703e;
P_0c04703e: /* original 69f6, guest PC 0x0c04703e */
if(!s->budget--) { s->failed_pc=0x0c04703eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c047040;
P_0c047040: /* original 6af6, guest PC 0x0c047040 */
if(!s->budget--) { s->failed_pc=0x0c047040u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c047042;
P_0c047042: /* original 6bf6, guest PC 0x0c047042 */
if(!s->budget--) { s->failed_pc=0x0c047042u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c047044;
P_0c047044: /* original 6cf6, guest PC 0x0c047044 */
if(!s->budget--) { s->failed_pc=0x0c047044u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c047046;
P_0c047046: /* original 6df6, guest PC 0x0c047046 */
if(!s->budget--) { s->failed_pc=0x0c047046u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c047048;
P_0c047048: /* original 000b, guest PC 0x0c047048 */
if(!s->budget--) { s->failed_pc=0x0c047048u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c04704a: /* original 6ef6, guest PC 0x0c04704a */
if(!s->budget--) { s->failed_pc=0x0c04704au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c04704cu,s,ram);
P_0c0471d8: /* original 2fc6, guest PC 0x0c0471d8 */
if(!s->budget--) { s->failed_pc=0x0c0471d8u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0471da;
P_0c0471da: /* original e600, guest PC 0x0c0471da */
if(!s->budget--) { s->failed_pc=0x0c0471dau; return 0; }
r[6]=0x00000000u;
goto P_0c0471dc;
P_0c0471dc: /* original 2fb6, guest PC 0x0c0471dc */
if(!s->budget--) { s->failed_pc=0x0c0471dcu; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0471de;
P_0c0471de: /* original eb08, guest PC 0x0c0471de */
if(!s->budget--) { s->failed_pc=0x0c0471deu; return 0; }
r[11]=0x00000008u;
goto P_0c0471e0;
P_0c0471e0: /* original 2fa6, guest PC 0x0c0471e0 */
if(!s->budget--) { s->failed_pc=0x0c0471e0u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0471e2;
P_0c0471e2: /* original 6a43, guest PC 0x0c0471e2 */
if(!s->budget--) { s->failed_pc=0x0c0471e2u; return 0; }
r[10]=r[4];
goto P_0c0471e4;
P_0c0471e4: /* original 9111, guest PC 0x0c0471e4 */
if(!s->budget--) { s->failed_pc=0x0c0471e4u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04720au,2);
goto P_0c0471e6;
P_0c0471e6: /* original 6463, guest PC 0x0c0471e6 */
if(!s->budget--) { s->failed_pc=0x0c0471e6u; return 0; }
r[4]=r[6];
goto P_0c0471e8;
P_0c0471e8: /* original d00a, guest PC 0x0c0471e8 */
if(!s->budget--) { s->failed_pc=0x0c0471e8u; return 0; }
r[0]=read(ram,0x0c047214u,4);
goto P_0c0471ea;
P_0c0471ea: /* original a019, guest PC 0x0c0471ea */
if(!s->budget--) { s->failed_pc=0x0c0471eau; return 0; }
r[12]=r[6];
goto P_0c047220;
P_0c0471ec: /* original 6c63, guest PC 0x0c0471ec */
if(!s->budget--) { s->failed_pc=0x0c0471ecu; return 0; }
r[12]=r[6];
goto P_0c0471ee;
P_0c0471ee: /* original 63a4, guest PC 0x0c0471ee */
if(!s->budget--) { s->failed_pc=0x0c0471eeu; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[10],1);
r[10]+=1;
r[3]=tmp;
goto P_0c0471f0;
P_0c0471f0: /* original 67b3, guest PC 0x0c0471f0 */
if(!s->budget--) { s->failed_pc=0x0c0471f0u; return 0; }
r[7]=r[11];
goto P_0c0471f2;
P_0c0471f2: /* original 4318, guest PC 0x0c0471f2 */
if(!s->budget--) { s->failed_pc=0x0c0471f2u; return 0; }
r[3]<<=8;
goto P_0c0471f4;
P_0c0471f4: /* original 243a, guest PC 0x0c0471f4 */
if(!s->budget--) { s->failed_pc=0x0c0471f4u; return 0; }
r[4]^=r[3];
goto P_0c0471f6;
P_0c0471f6: /* original 6243, guest PC 0x0c0471f6 */
if(!s->budget--) { s->failed_pc=0x0c0471f6u; return 0; }
r[2]=r[4];
goto P_0c0471f8;
P_0c0471f8: /* original 6643, guest PC 0x0c0471f8 */
if(!s->budget--) { s->failed_pc=0x0c0471f8u; return 0; }
r[6]=r[4];
goto P_0c0471fa;
P_0c0471fa: /* original 4600, guest PC 0x0c0471fa */
if(!s->budget--) { s->failed_pc=0x0c0471fau; return 0; }
r[17]=(r[17]&~1u)|((r[6]>>31)!=0);
r[6]<<=1;
goto P_0c0471fc;
P_0c0471fc: /* original 2208, guest PC 0x0c0471fc */
if(!s->budget--) { s->failed_pc=0x0c0471fcu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[0])==0)!=0);
goto P_0c0471fe;
P_0c0471fe: /* original 890b, guest PC 0x0c0471fe */
if(!s->budget--) { s->failed_pc=0x0c0471feu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c047218; }
goto P_0c047200;
P_0c047200: /* original 6463, guest PC 0x0c047200 */
if(!s->budget--) { s->failed_pc=0x0c047200u; return 0; }
r[4]=r[6];
goto P_0c047202;
P_0c047202: /* original a00a, guest PC 0x0c047202 */
if(!s->budget--) { s->failed_pc=0x0c047202u; return 0; }
r[4]^=r[1];
goto P_0c04721a;
P_0c047204: /* original 241a, guest PC 0x0c047204 */
if(!s->budget--) { s->failed_pc=0x0c047204u; return 0; }
r[4]^=r[1];
return vf3_matrix_family(0x0c047206u,s,ram);
P_0c047218: /* original 6463, guest PC 0x0c047218 */
if(!s->budget--) { s->failed_pc=0x0c047218u; return 0; }
r[4]=r[6];
goto P_0c04721a;
P_0c04721a: /* original 4710, guest PC 0x0c04721a */
if(!s->budget--) { s->failed_pc=0x0c04721au; return 0; }
--r[7];
r[17]=(r[17]&~1u)|((r[7]==0)!=0);
goto P_0c04721c;
P_0c04721c: /* original 8beb, guest PC 0x0c04721c */
if(!s->budget--) { s->failed_pc=0x0c04721cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0471f6; }
goto P_0c04721e;
P_0c04721e: /* original 7c01, guest PC 0x0c04721e */
if(!s->budget--) { s->failed_pc=0x0c04721eu; return 0; }
r[12]+=0x00000001u;
goto P_0c047220;
P_0c047220: /* original 3c52, guest PC 0x0c047220 */
if(!s->budget--) { s->failed_pc=0x0c047220u; return 0; }
r[17]=(r[17]&~1u)|((r[12]>=r[5])!=0);
goto P_0c047222;
P_0c047222: /* original 8be4, guest PC 0x0c047222 */
if(!s->budget--) { s->failed_pc=0x0c047222u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0471ee; }
goto P_0c047224;
P_0c047224: /* original 6af6, guest PC 0x0c047224 */
if(!s->budget--) { s->failed_pc=0x0c047224u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c047226;
P_0c047226: /* original 6043, guest PC 0x0c047226 */
if(!s->budget--) { s->failed_pc=0x0c047226u; return 0; }
r[0]=r[4];
goto P_0c047228;
P_0c047228: /* original 6bf6, guest PC 0x0c047228 */
if(!s->budget--) { s->failed_pc=0x0c047228u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c04722a;
P_0c04722a: /* original 000b, guest PC 0x0c04722a */
if(!s->budget--) { s->failed_pc=0x0c04722au; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
s->pc=target; return ram->oob==0;
P_0c04722c: /* original 6cf6, guest PC 0x0c04722c */
if(!s->budget--) { s->failed_pc=0x0c04722cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
return vf3_matrix_family(0x0c04722eu,s,ram);
P_0c0491a4: /* original f449, guest PC 0x0c0491a4 */
if(!s->budget--) { s->failed_pc=0x0c0491a4u; return 0; }
vf3_matrix_load(s,ram,4,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c0491a6;
P_0c0491a6: /* original f549, guest PC 0x0c0491a6 */
if(!s->budget--) { s->failed_pc=0x0c0491a6u; return 0; }
vf3_matrix_load(s,ram,5,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c0491a8;
P_0c0491a8: /* original f649, guest PC 0x0c0491a8 */
if(!s->budget--) { s->failed_pc=0x0c0491a8u; return 0; }
vf3_matrix_load(s,ram,6,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c0491aa;
P_0c0491aa: /* original f79d, guest PC 0x0c0491aa */
if(!s->budget--) { s->failed_pc=0x0c0491aau; return 0; }
fr[7]=0x3f800000u;
goto P_0c0491ac;
P_0c0491ac: /* original f249, guest PC 0x0c0491ac */
if(!s->budget--) { s->failed_pc=0x0c0491acu; return 0; }
vf3_matrix_load(s,ram,2,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c0491ae;
P_0c0491ae: /* original f049, guest PC 0x0c0491ae */
if(!s->budget--) { s->failed_pc=0x0c0491aeu; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c0491b0;
P_0c0491b0: /* original f149, guest PC 0x0c0491b0 */
if(!s->budget--) { s->failed_pc=0x0c0491b0u; return 0; }
vf3_matrix_load(s,ram,1,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c0491b2;
P_0c0491b2: /* original f5fd, guest PC 0x0c0491b2 */
if(!s->budget--) { s->failed_pc=0x0c0491b2u; return 0; }
if(!vf3_fpu_ftrv(xf,fr+4,r[18],fr+4)) goto unsupported;
goto P_0c0491b4;
P_0c0491b4: /* original f38d, guest PC 0x0c0491b4 */
if(!s->budget--) { s->failed_pc=0x0c0491b4u; return 0; }
fr[3]=0;
goto P_0c0491b6;
P_0c0491b6: /* original fa49, guest PC 0x0c0491b6 */
if(!s->budget--) { s->failed_pc=0x0c0491b6u; return 0; }
vf3_matrix_load(s,ram,10,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c0491b8;
P_0c0491b8: /* original 60d3, guest PC 0x0c0491b8 */
if(!s->budget--) { s->failed_pc=0x0c0491b8u; return 0; }
r[0]=r[13];
goto P_0c0491ba;
P_0c0491ba: /* original f849, guest PC 0x0c0491ba */
if(!s->budget--) { s->failed_pc=0x0c0491bau; return 0; }
vf3_matrix_load(s,ram,8,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c0491bc;
P_0c0491bc: /* original 4029, guest PC 0x0c0491bc */
if(!s->budget--) { s->failed_pc=0x0c0491bcu; return 0; }
r[0]>>=16;
goto P_0c0491be;
P_0c0491be: /* original f949, guest PC 0x0c0491be */
if(!s->budget--) { s->failed_pc=0x0c0491beu; return 0; }
vf3_matrix_load(s,ram,9,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c0491c0;
P_0c0491c0: /* original f3ed, guest PC 0x0c0491c0 */
if(!s->budget--) { s->failed_pc=0x0c0491c0u; return 0; }
if(!vf3_fpu_fipr(fr+12,fr+0,r[18],fr+3)) goto unsupported;
goto P_0c0491c2;
P_0c0491c2: /* original f249, guest PC 0x0c0491c2 */
if(!s->budget--) { s->failed_pc=0x0c0491c2u; return 0; }
vf3_matrix_load(s,ram,2,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c0491c4;
P_0c0491c4: /* original fff1, guest PC 0x0c0491c4 */
if(!s->budget--) { s->failed_pc=0x0c0491c4u; return 0; }
fr[15]=vf3_fpu_binary(fr[15],fr[15],r[18],'-');
goto P_0c0491c6;
P_0c0491c6: /* original f79d, guest PC 0x0c0491c6 */
if(!s->budget--) { s->failed_pc=0x0c0491c6u; return 0; }
fr[7]=0x3f800000u;
goto P_0c0491c8;
P_0c0491c8: /* original f743, guest PC 0x0c0491c8 */
if(!s->budget--) { s->failed_pc=0x0c0491c8u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[4],r[18],'/');
goto P_0c0491ca;
P_0c0491ca: /* original f049, guest PC 0x0c0491ca */
if(!s->budget--) { s->failed_pc=0x0c0491cau; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c0491cc;
P_0c0491cc: /* original 4028, guest PC 0x0c0491cc */
if(!s->budget--) { s->failed_pc=0x0c0491ccu; return 0; }
r[0]<<=16;
goto P_0c0491ce;
P_0c0491ce: /* original fb8d, guest PC 0x0c0491ce */
if(!s->budget--) { s->failed_pc=0x0c0491ceu; return 0; }
fr[11]=0;
goto P_0c0491d0;
P_0c0491d0: /* original f3b5, guest PC 0x0c0491d0 */
if(!s->budget--) { s->failed_pc=0x0c0491d0u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[11]))!=0);
goto P_0c0491d2;
P_0c0491d2: /* original f149, guest PC 0x0c0491d2 */
if(!s->budget--) { s->failed_pc=0x0c0491d2u; return 0; }
vf3_matrix_load(s,ram,1,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c0491d4;
P_0c0491d4: /* original 7420, guest PC 0x0c0491d4 */
if(!s->budget--) { s->failed_pc=0x0c0491d4u; return 0; }
r[4]+=0x00000020u;
goto P_0c0491d6;
P_0c0491d6: /* original fbed, guest PC 0x0c0491d6 */
if(!s->budget--) { s->failed_pc=0x0c0491d6u; return 0; }
if(!vf3_fpu_fipr(fr+12,fr+8,r[18],fr+11)) goto unsupported;
goto P_0c0491d8;
P_0c0491d8: /* original 0483, guest PC 0x0c0491d8 */
if(!s->budget--) { s->failed_pc=0x0c0491d8u; return 0; }
if((r[4]&0xFC000000u)==0xE0000000u) pref(ram,r[4]);
goto P_0c0491da;
P_0c0491da: /* original 8900, guest PC 0x0c0491da */
if(!s->budget--) { s->failed_pc=0x0c0491dau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0491de; }
goto P_0c0491dc;
P_0c0491dc: /* original f38d, guest PC 0x0c0491dc */
if(!s->budget--) { s->failed_pc=0x0c0491dcu; return 0; }
fr[3]=0;
goto P_0c0491de;
P_0c0491de: /* original f83c, guest PC 0x0c0491de */
if(!s->budget--) { s->failed_pc=0x0c0491deu; return 0; }
vf3_matrix_move(s,8,3);
goto P_0c0491e0;
P_0c0491e0: /* original f882, guest PC 0x0c0491e0 */
if(!s->budget--) { s->failed_pc=0x0c0491e0u; return 0; }
fr[8]=vf3_fpu_binary(fr[8],fr[8],r[18],'*');
goto P_0c0491e2;
P_0c0491e2: /* original f99d, guest PC 0x0c0491e2 */
if(!s->budget--) { s->failed_pc=0x0c0491e2u; return 0; }
fr[9]=0x3f800000u;
goto P_0c0491e4;
P_0c0491e4: /* original fced, guest PC 0x0c0491e4 */
if(!s->budget--) { s->failed_pc=0x0c0491e4u; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+12,r[18],fr+15)) goto unsupported;
goto P_0c0491e6;
P_0c0491e6: /* original fa8d, guest PC 0x0c0491e6 */
if(!s->budget--) { s->failed_pc=0x0c0491e6u; return 0; }
fr[10]=0;
goto P_0c0491e8;
P_0c0491e8: /* original fab5, guest PC 0x0c0491e8 */
if(!s->budget--) { s->failed_pc=0x0c0491e8u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[10])>as_float(fr[11]))!=0);
goto P_0c0491ea;
P_0c0491ea: /* original 62d3, guest PC 0x0c0491ea */
if(!s->budget--) { s->failed_pc=0x0c0491eau; return 0; }
r[2]=r[13];
goto P_0c0491ec;
P_0c0491ec: /* original f981, guest PC 0x0c0491ec */
if(!s->budget--) { s->failed_pc=0x0c0491ecu; return 0; }
fr[9]=vf3_fpu_binary(fr[9],fr[8],r[18],'-');
goto P_0c0491ee;
P_0c0491ee: /* original 622c, guest PC 0x0c0491ee */
if(!s->budget--) { s->failed_pc=0x0c0491eeu; return 0; }
r[2]=r[2]&255u;
goto P_0c0491f0;
P_0c0491f0: /* original 8b00, guest PC 0x0c0491f0 */
if(!s->budget--) { s->failed_pc=0x0c0491f0u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0491f4; }
goto P_0c0491f2;
P_0c0491f2: /* original fb4d, guest PC 0x0c0491f2 */
if(!s->budget--) { s->failed_pc=0x0c0491f2u; return 0; }
fr[11]^=0x80000000u;
goto P_0c0491f4;
P_0c0491f4: /* original 0029, guest PC 0x0c0491f4 */
if(!s->budget--) { s->failed_pc=0x0c0491f4u; return 0; }
r[0]=r[17]&1u;
goto P_0c0491f6;
P_0c0491f6: /* original faf5, guest PC 0x0c0491f6 */
if(!s->budget--) { s->failed_pc=0x0c0491f6u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[10])>as_float(fr[15]))!=0);
goto P_0c0491f8;
P_0c0491f8: /* original 425a, guest PC 0x0c0491f8 */
if(!s->budget--) { s->failed_pc=0x0c0491f8u; return 0; }
r[53]=r[2];
goto P_0c0491fa;
P_0c0491fa: /* original f96d, guest PC 0x0c0491fa */
if(!s->budget--) { s->failed_pc=0x0c0491fau; return 0; }
fr[9]=vf3_fpu_sqrt(fr[9],r[18]);
goto P_0c0491fc;
P_0c0491fc: /* original 8b00, guest PC 0x0c0491fc */
if(!s->budget--) { s->failed_pc=0x0c0491fcu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c049200; }
goto P_0c0491fe;
P_0c0491fe: /* original ff4d, guest PC 0x0c0491fe */
if(!s->budget--) { s->failed_pc=0x0c0491feu; return 0; }
fr[15]^=0x80000000u;
goto P_0c049200;
P_0c049200: /* original 0129, guest PC 0x0c049200 */
if(!s->budget--) { s->failed_pc=0x0c049200u; return 0; }
r[1]=r[17]&1u;
goto P_0c049202;
P_0c049202: /* original ffb5, guest PC 0x0c049202 */
if(!s->budget--) { s->failed_pc=0x0c049202u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[15])>as_float(fr[11]))!=0);
goto P_0c049204;
P_0c049204: /* original fafc, guest PC 0x0c049204 */
if(!s->budget--) { s->failed_pc=0x0c049204u; return 0; }
vf3_matrix_move(s,10,15);
goto P_0c049206;
P_0c049206: /* original 4108, guest PC 0x0c049206 */
if(!s->budget--) { s->failed_pc=0x0c049206u; return 0; }
r[1]<<=2;
goto P_0c049208;
P_0c049208: /* original 8b02, guest PC 0x0c049208 */
if(!s->budget--) { s->failed_pc=0x0c049208u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c049210; }
goto P_0c04920a;
P_0c04920a: /* original ffbc, guest PC 0x0c04920a */
if(!s->budget--) { s->failed_pc=0x0c04920au; return 0; }
vf3_matrix_move(s,15,11);
goto P_0c04920c;
P_0c04920c: /* original cb02, guest PC 0x0c04920c */
if(!s->budget--) { s->failed_pc=0x0c04920cu; return 0; }
r[0]|=2u;
goto P_0c04920e;
P_0c04920e: /* original fbac, guest PC 0x0c04920e */
if(!s->budget--) { s->failed_pc=0x0c04920eu; return 0; }
vf3_matrix_move(s,11,10);
goto P_0c049210;
P_0c049210: /* original 210b, guest PC 0x0c049210 */
if(!s->budget--) { s->failed_pc=0x0c049210u; return 0; }
r[1]|=r[0];
goto P_0c049212;
P_0c049212: /* original fa2d, guest PC 0x0c049212 */
if(!s->budget--) { s->failed_pc=0x0c049212u; return 0; }
fr[10]=vf3_fpu_float(r[53],r[18]);
goto P_0c049214;
P_0c049214: /* original 4100, guest PC 0x0c049214 */
if(!s->budget--) { s->failed_pc=0x0c049214u; return 0; }
r[17]=(r[17]&~1u)|((r[1]>>31)!=0);
r[1]<<=1;
goto P_0c049216;
P_0c049216: /* original c736, guest PC 0x0c049216 */
if(!s->budget--) { s->failed_pc=0x0c049216u; return 0; }
r[0]=0x0c0492f0u;
goto P_0c049218;
P_0c049218: /* original 011d, guest PC 0x0c049218 */
if(!s->budget--) { s->failed_pc=0x0c049218u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,r[1]+r[0],2);
goto P_0c04921a;
P_0c04921a: /* original c731, guest PC 0x0c04921a */
if(!s->budget--) { s->failed_pc=0x0c04921au; return 0; }
r[0]=0x0c0492e0u;
goto P_0c04921c;
P_0c04921c: /* original f009, guest PC 0x0c04921c */
if(!s->budget--) { s->failed_pc=0x0c04921cu; return 0; }
vf3_matrix_load(s,ram,0,r[0]);
r[0]+=(r[18]&0x100000u)?8:4;
goto P_0c04921e;
P_0c04921e: /* original ffb3, guest PC 0x0c04921e */
if(!s->budget--) { s->failed_pc=0x0c04921eu; return 0; }
fr[15]=vf3_fpu_binary(fr[15],fr[11],r[18],'/');
goto P_0c049220;
P_0c049220: /* original 4101, guest PC 0x0c049220 */
if(!s->budget--) { s->failed_pc=0x0c049220u; return 0; }
r[17]=(r[17]&~1u)|((r[1]&1)!=0);
r[1]>>=1;
goto P_0c049222;
P_0c049222: /* original fb09, guest PC 0x0c049222 */
if(!s->budget--) { s->failed_pc=0x0c049222u; return 0; }
vf3_matrix_load(s,ram,11,r[0]);
r[0]+=(r[18]&0x100000u)?8:4;
goto P_0c049224;
P_0c049224: /* original f3a2, guest PC 0x0c049224 */
if(!s->budget--) { s->failed_pc=0x0c049224u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[10],r[18],'*');
goto P_0c049226;
P_0c049226: /* original 6202, guest PC 0x0c049226 */
if(!s->budget--) { s->failed_pc=0x0c049226u; return 0; }
tmp=read(ram,r[0],4);
r[2]=tmp;
goto P_0c049228;
P_0c049228: /* original 60d3, guest PC 0x0c049228 */
if(!s->budget--) { s->failed_pc=0x0c049228u; return 0; }
r[0]=r[13];
goto P_0c04922a;
P_0c04922a: /* original 4029, guest PC 0x0c04922a */
if(!s->budget--) { s->failed_pc=0x0c04922au; return 0; }
r[0]>>=16;
goto P_0c04922c;
P_0c04922c: /* original f9a2, guest PC 0x0c04922c */
if(!s->budget--) { s->failed_pc=0x0c04922cu; return 0; }
fr[9]=vf3_fpu_binary(fr[9],fr[10],r[18],'*');
goto P_0c04922e;
P_0c04922e: /* original 4028, guest PC 0x0c04922e */
if(!s->budget--) { s->failed_pc=0x0c04922eu; return 0; }
r[0]<<=16;
goto P_0c049230;
P_0c049230: /* original f33d, guest PC 0x0c049230 */
if(!s->budget--) { s->failed_pc=0x0c049230u; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c049232;
P_0c049232: /* original 210b, guest PC 0x0c049232 */
if(!s->budget--) { s->failed_pc=0x0c049232u; return 0; }
r[1]|=r[0];
goto P_0c049234;
P_0c049234: /* original 005a, guest PC 0x0c049234 */
if(!s->budget--) { s->failed_pc=0x0c049234u; return 0; }
r[0]=r[53];
goto P_0c049236;
P_0c049236: /* original 7420, guest PC 0x0c049236 */
if(!s->budget--) { s->failed_pc=0x0c049236u; return 0; }
r[4]+=0x00000020u;
goto P_0c049238;
P_0c049238: /* original f93d, guest PC 0x0c049238 */
if(!s->budget--) { s->failed_pc=0x0c049238u; return 0; }
r[53]=truncate_float(fr[9]);
goto P_0c04923a;
P_0c04923a: /* original 0483, guest PC 0x0c04923a */
if(!s->budget--) { s->failed_pc=0x0c04923au; return 0; }
if((r[4]&0xFC000000u)==0xE0000000u) pref(ram,r[4]);
goto P_0c04923c;
P_0c04923c: /* original 4028, guest PC 0x0c04923c */
if(!s->budget--) { s->failed_pc=0x0c04923cu; return 0; }
r[0]<<=16;
goto P_0c04923e;
P_0c04923e: /* original 310c, guest PC 0x0c04923e */
if(!s->budget--) { s->failed_pc=0x0c04923eu; return 0; }
r[1]+=r[0];
goto P_0c049240;
P_0c049240: /* original 005a, guest PC 0x0c049240 */
if(!s->budget--) { s->failed_pc=0x0c049240u; return 0; }
r[0]=r[53];
goto P_0c049242;
P_0c049242: /* original 74c0, guest PC 0x0c049242 */
if(!s->budget--) { s->failed_pc=0x0c049242u; return 0; }
r[4]+=0xffffffc0u;
goto P_0c049244;
P_0c049244: /* original fbfe, guest PC 0x0c049244 */
if(!s->budget--) { s->failed_pc=0x0c049244u; return 0; }
fr[11]=vf3_fpu_mac(fr[0],fr[15],fr[11],r[18]);
goto P_0c049246;
P_0c049246: /* original 4018, guest PC 0x0c049246 */
if(!s->budget--) { s->failed_pc=0x0c049246u; return 0; }
r[0]<<=8;
goto P_0c049248;
P_0c049248: /* original fb3d, guest PC 0x0c049248 */
if(!s->budget--) { s->failed_pc=0x0c049248u; return 0; }
r[53]=truncate_float(fr[11]);
goto P_0c04924a;
P_0c04924a: /* original ff8d, guest PC 0x0c04924a */
if(!s->budget--) { s->failed_pc=0x0c04924au; return 0; }
fr[15]=0;
goto P_0c04924c;
P_0c04924c: /* original 310c, guest PC 0x0c04924c */
if(!s->budget--) { s->failed_pc=0x0c04924cu; return 0; }
r[1]+=r[0];
goto P_0c04924e;
P_0c04924e: /* original 005a, guest PC 0x0c04924e */
if(!s->budget--) { s->failed_pc=0x0c04924eu; return 0; }
r[0]=r[53];
goto P_0c049250;
P_0c049250: /* original c9ff, guest PC 0x0c049250 */
if(!s->budget--) { s->failed_pc=0x0c049250u; return 0; }
r[0]&=255u;
goto P_0c049252;
P_0c049252: /* original 002c, guest PC 0x0c049252 */
if(!s->budget--) { s->failed_pc=0x0c049252u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[2]+r[0],1);
goto P_0c049254;
P_0c049254: /* original 8b00, guest PC 0x0c049254 */
if(!s->budget--) { s->failed_pc=0x0c049254u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c049258; }
goto P_0c049256;
P_0c049256: /* original 600b, guest PC 0x0c049256 */
if(!s->budget--) { s->failed_pc=0x0c049256u; return 0; }
r[0]=0u-r[0];
goto P_0c049258;
P_0c049258: /* original 301c, guest PC 0x0c049258 */
if(!s->budget--) { s->failed_pc=0x0c049258u; return 0; }
r[0]+=r[1];
goto P_0c04925a;
P_0c04925a: /* original 2606, guest PC 0x0c04925a */
if(!s->budget--) { s->failed_pc=0x0c04925au; return 0; }
tmp=r[0]; r[6]-=4; write(ram,r[6],tmp,4);
goto P_0c04925c;
P_0c04925c: /* original f3fd, guest PC 0x0c04925c */
if(!s->budget--) { s->failed_pc=0x0c04925cu; return 0; }
r[18]^=0x100000u;
goto P_0c04925e;
P_0c04925e: /* original 6146, guest PC 0x0c04925e */
if(!s->budget--) { s->failed_pc=0x0c04925eu; return 0; }
tmp=read(ram,r[4],4);
r[4]+=4;
r[1]=tmp;
goto P_0c049260;
P_0c049260: /* original f672, guest PC 0x0c049260 */
if(!s->budget--) { s->failed_pc=0x0c049260u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[7],r[18],'*');
goto P_0c049262;
P_0c049262: /* original 6246, guest PC 0x0c049262 */
if(!s->budget--) { s->failed_pc=0x0c049262u; return 0; }
tmp=read(ram,r[4],4);
r[4]+=4;
r[2]=tmp;
goto P_0c049264;
P_0c049264: /* original f572, guest PC 0x0c049264 */
if(!s->budget--) { s->failed_pc=0x0c049264u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[7],r[18],'*');
goto P_0c049266;
P_0c049266: /* original 2686, guest PC 0x0c049266 */
if(!s->budget--) { s->failed_pc=0x0c049266u; return 0; }
tmp=r[8]; r[6]-=4; write(ram,r[6],tmp,4);
goto P_0c049268;
P_0c049268: /* original 6e03, guest PC 0x0c049268 */
if(!s->budget--) { s->failed_pc=0x0c049268u; return 0; }
r[14]=r[0];
goto P_0c04926a;
P_0c04926a: /* original 2626, guest PC 0x0c04926a */
if(!s->budget--) { s->failed_pc=0x0c04926au; return 0; }
tmp=r[2]; r[6]-=4; write(ram,r[6],tmp,4);
goto P_0c04926c;
P_0c04926c: /* original 6063, guest PC 0x0c04926c */
if(!s->budget--) { s->failed_pc=0x0c04926cu; return 0; }
r[0]=r[6];
goto P_0c04926e;
P_0c04926e: /* original 2616, guest PC 0x0c04926e */
if(!s->budget--) { s->failed_pc=0x0c04926eu; return 0; }
tmp=r[1]; r[6]-=4; write(ram,r[6],tmp,4);
goto P_0c049270;
P_0c049270: /* original 4021, guest PC 0x0c049270 */
if(!s->budget--) { s->failed_pc=0x0c049270u; return 0; }
r[17]=(r[17]&~1u)|((r[0]&1)!=0);
r[0]=(uint32_t)((int32_t)r[0]>>1);
goto P_0c049272;
P_0c049272: /* original f66b, guest PC 0x0c049272 */
if(!s->budget--) { s->failed_pc=0x0c049272u; return 0; }
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,6,r[6]);
goto P_0c049274;
P_0c049274: /* original 4310, guest PC 0x0c049274 */
if(!s->budget--) { s->failed_pc=0x0c049274u; return 0; }
--r[3];
r[17]=(r[17]&~1u)|((r[3]==0)!=0);
goto P_0c049276;
P_0c049276: /* original f64b, guest PC 0x0c049276 */
if(!s->budget--) { s->failed_pc=0x0c049276u; return 0; }
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,4,r[6]);
goto P_0c049278;
P_0c049278: /* original 8d05, guest PC 0x0c049278 */
if(!s->budget--) { s->failed_pc=0x0c049278u; return 0; }
cond=r[17]&1u;
r[18]^=0x100000u;
if(cond) { goto P_0c049286; }
goto P_0c04927c;
P_0c04927a: /* original f3fd, guest PC 0x0c04927a */
if(!s->budget--) { s->failed_pc=0x0c04927au; return 0; }
r[18]^=0x100000u;
goto P_0c04927c;
P_0c04927c: /* original 2662, guest PC 0x0c04927c */
if(!s->budget--) { s->failed_pc=0x0c04927cu; return 0; }
write(ram,r[6],r[6],4);
goto P_0c04927e;
P_0c04927e: /* original 7520, guest PC 0x0c04927e */
if(!s->budget--) { s->failed_pc=0x0c04927eu; return 0; }
r[5]+=0x00000020u;
goto P_0c049280;
P_0c049280: /* original 0683, guest PC 0x0c049280 */
if(!s->budget--) { s->failed_pc=0x0c049280u; return 0; }
if((r[6]&0xFC000000u)==0xE0000000u) pref(ram,r[6]);
goto P_0c049282;
P_0c049282: /* original af8f, guest PC 0x0c049282 */
if(!s->budget--) { s->failed_pc=0x0c049282u; return 0; }
r[6]+=0x00000040u;
goto P_0c0491a4;
P_0c049284: /* original 7640, guest PC 0x0c049284 */
if(!s->budget--) { s->failed_pc=0x0c049284u; return 0; }
r[6]+=0x00000040u;
goto P_0c049286;
P_0c049286: /* original 2602, guest PC 0x0c049286 */
if(!s->budget--) { s->failed_pc=0x0c049286u; return 0; }
write(ram,r[6],r[0],4);
goto P_0c049288;
P_0c049288: /* original 7520, guest PC 0x0c049288 */
if(!s->budget--) { s->failed_pc=0x0c049288u; return 0; }
r[5]+=0x00000020u;
goto P_0c04928a;
P_0c04928a: /* original 6046, guest PC 0x0c04928a */
if(!s->budget--) { s->failed_pc=0x0c04928au; return 0; }
tmp=read(ram,r[4],4);
r[4]+=4;
r[0]=tmp;
goto P_0c04928c;
P_0c04928c: /* original 0683, guest PC 0x0c04928c */
if(!s->budget--) { s->failed_pc=0x0c04928cu; return 0; }
if((r[6]&0xFC000000u)==0xE0000000u) pref(ram,r[6]);
goto P_0c04928e;
P_0c04928e: /* original 7640, guest PC 0x0c04928e */
if(!s->budget--) { s->failed_pc=0x0c04928eu; return 0; }
r[6]+=0x00000040u;
goto P_0c049290;
P_0c049290: /* original 4015, guest PC 0x0c049290 */
if(!s->budget--) { s->failed_pc=0x0c049290u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[0]>0)!=0);
goto P_0c049292;
P_0c049292: /* original 8f03, guest PC 0x0c049292 */
if(!s->budget--) { s->failed_pc=0x0c049292u; return 0; }
cond=r[17]&1u;
r[17]=(r[17]&~1u)|(((r[0]&128u)==0)!=0);
if(!cond) { goto P_0c04929c; }
goto P_0c049296;
P_0c049294: /* original c880, guest PC 0x0c049294 */
if(!s->budget--) { s->failed_pc=0x0c049294u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&128u)==0)!=0);
goto P_0c049296;
P_0c049296: /* original 8f85, guest PC 0x0c049296 */
if(!s->budget--) { s->failed_pc=0x0c049296u; return 0; }
cond=r[17]&1u;
tmp=read(ram,r[4],4);
r[4]+=4;
r[3]=tmp;
if(!cond) { goto P_0c0491a4; }
goto P_0c04929a;
P_0c049298: /* original 6346, guest PC 0x0c049298 */
if(!s->budget--) { s->failed_pc=0x0c049298u; return 0; }
tmp=read(ram,r[4],4);
r[4]+=4;
r[3]=tmp;
goto P_0c04929a;
P_0c04929a: /* original 74fc, guest PC 0x0c04929a */
if(!s->budget--) { s->failed_pc=0x0c04929au; return 0; }
r[4]+=0xfffffffcu;
goto P_0c04929c;
P_0c04929c: /* original 74fc, guest PC 0x0c04929c */
if(!s->budget--) { s->failed_pc=0x0c04929cu; return 0; }
r[4]+=0xfffffffcu;
goto P_0c04929e;
P_0c04929e: /* original 000b, guest PC 0x0c04929e */
if(!s->budget--) { s->failed_pc=0x0c04929eu; return 0; }
target=r[16];
r[6]+=0xffffffe0u;
s->pc=target; return ram->oob==0;
P_0c0492a0: /* original 76e0, guest PC 0x0c0492a0 */
if(!s->budget--) { s->failed_pc=0x0c0492a0u; return 0; }
r[6]+=0xffffffe0u;
return vf3_matrix_family(0x0c0492a2u,s,ram);
P_0c0492be: /* original f60b, guest PC 0x0c0492be */
if(!s->budget--) { s->failed_pc=0x0c0492beu; return 0; }
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[6]);
goto P_0c0492c0;
P_0c0492c0: /* original 4021, guest PC 0x0c0492c0 */
if(!s->budget--) { s->failed_pc=0x0c0492c0u; return 0; }
r[17]=(r[17]&~1u)|((r[0]&1)!=0);
r[0]=(uint32_t)((int32_t)r[0]>>1);
goto P_0c0492c2;
P_0c0492c2: /* original f66b, guest PC 0x0c0492c2 */
if(!s->budget--) { s->failed_pc=0x0c0492c2u; return 0; }
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,6,r[6]);
goto P_0c0492c4;
P_0c0492c4: /* original 4310, guest PC 0x0c0492c4 */
if(!s->budget--) { s->failed_pc=0x0c0492c4u; return 0; }
--r[3];
r[17]=(r[17]&~1u)|((r[3]==0)!=0);
goto P_0c0492c6;
P_0c0492c6: /* original f64b, guest PC 0x0c0492c6 */
if(!s->budget--) { s->failed_pc=0x0c0492c6u; return 0; }
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,4,r[6]);
goto P_0c0492c8;
P_0c0492c8: /* original 8ddd, guest PC 0x0c0492c8 */
if(!s->budget--) { s->failed_pc=0x0c0492c8u; return 0; }
cond=r[17]&1u;
r[18]^=0x100000u;
if(cond) { goto P_0c049286; }
goto P_0c0492cc;
P_0c0492ca: /* original f3fd, guest PC 0x0c0492ca */
if(!s->budget--) { s->failed_pc=0x0c0492cau; return 0; }
r[18]^=0x100000u;
goto P_0c0492cc;
P_0c0492cc: /* original 2662, guest PC 0x0c0492cc */
if(!s->budget--) { s->failed_pc=0x0c0492ccu; return 0; }
write(ram,r[6],r[6],4);
goto P_0c0492ce;
P_0c0492ce: /* original 7520, guest PC 0x0c0492ce */
if(!s->budget--) { s->failed_pc=0x0c0492ceu; return 0; }
r[5]+=0x00000020u;
goto P_0c0492d0;
P_0c0492d0: /* original 0683, guest PC 0x0c0492d0 */
if(!s->budget--) { s->failed_pc=0x0c0492d0u; return 0; }
if((r[6]&0xFC000000u)==0xE0000000u) pref(ram,r[6]);
goto P_0c0492d2;
P_0c0492d2: /* original af67, guest PC 0x0c0492d2 */
if(!s->budget--) { s->failed_pc=0x0c0492d2u; return 0; }
r[6]+=0x00000040u;
goto P_0c0491a4;
P_0c0492d4: /* original 7640, guest PC 0x0c0492d4 */
if(!s->budget--) { s->failed_pc=0x0c0492d4u; return 0; }
r[6]+=0x00000040u;
return vf3_matrix_family(0x0c0492d6u,s,ram);
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
return vf3_matrix_family(0x0c04b9fcu,s,ram);
P_0c04c9ae: /* original 4f22, guest PC 0x0c04c9ae */
if(!s->budget--) { s->failed_pc=0x0c04c9aeu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c04c9b0;
P_0c04c9b0: /* original 6322, guest PC 0x0c04c9b0 */
if(!s->budget--) { s->failed_pc=0x0c04c9b0u; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c04c9b2;
P_0c04c9b2: /* original 5132, guest PC 0x0c04c9b2 */
if(!s->budget--) { s->failed_pc=0x0c04c9b2u; return 0; }
r[1]=read(ram,r[3]+8,4);
goto P_0c04c9b4;
P_0c04c9b4: /* original 4f12, guest PC 0x0c04c9b4 */
if(!s->budget--) { s->failed_pc=0x0c04c9b4u; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c04c9b6;
P_0c04c9b6: /* original 2118, guest PC 0x0c04c9b6 */
if(!s->budget--) { s->failed_pc=0x0c04c9b6u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[1])==0)!=0);
goto P_0c04c9b8;
P_0c04c9b8: /* original 8d34, guest PC 0x0c04c9b8 */
if(!s->budget--) { s->failed_pc=0x0c04c9b8u; return 0; }
cond=r[17]&1u;
r[12]=r[4];
if(cond) { goto P_0c04ca24; }
goto P_0c04c9bc;
P_0c04c9ba: /* original 6c43, guest PC 0x0c04c9ba */
if(!s->budget--) { s->failed_pc=0x0c04c9bau; return 0; }
r[12]=r[4];
goto P_0c04c9bc;
P_0c04c9bc: /* original 2558, guest PC 0x0c04c9bc */
if(!s->budget--) { s->failed_pc=0x0c04c9bcu; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[5])==0)!=0);
goto P_0c04c9be;
P_0c04c9be: /* original 8931, guest PC 0x0c04c9be */
if(!s->budget--) { s->failed_pc=0x0c04c9beu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04ca24; }
goto P_0c04c9c0;
P_0c04c9c0: /* original 9e33, guest PC 0x0c04c9c0 */
if(!s->budget--) { s->failed_pc=0x0c04c9c0u; return 0; }
r[14]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04ca2au,2);
goto P_0c04c9c2;
P_0c04c9c2: /* original d31b, guest PC 0x0c04c9c2 */
if(!s->budget--) { s->failed_pc=0x0c04c9c2u; return 0; }
r[3]=read(ram,0x0c04ca30u,4);
goto P_0c04c9c4;
P_0c04c9c4: /* original 2cef, guest PC 0x0c04c9c4 */
if(!s->budget--) { s->failed_pc=0x0c04c9c4u; return 0; }
r[19]=(uint32_t)((int32_t)(int16_t)r[12]*(int32_t)(int16_t)r[14]);
goto P_0c04c9c6;
P_0c04c9c6: /* original d71f, guest PC 0x0c04c9c6 */
if(!s->budget--) { s->failed_pc=0x0c04c9c6u; return 0; }
r[7]=read(ram,0x0c04ca44u,4);
goto P_0c04c9c8;
P_0c04c9c8: /* original d41d, guest PC 0x0c04c9c8 */
if(!s->budget--) { s->failed_pc=0x0c04c9c8u; return 0; }
r[4]=read(ram,0x0c04ca40u,4);
goto P_0c04c9ca;
P_0c04c9ca: /* original 0e1a, guest PC 0x0c04c9ca */
if(!s->budget--) { s->failed_pc=0x0c04c9cau; return 0; }
r[14]=r[19];
goto P_0c04c9cc;
P_0c04c9cc: /* original 6eef, guest PC 0x0c04c9cc */
if(!s->budget--) { s->failed_pc=0x0c04c9ccu; return 0; }
r[14]=(uint32_t)(int32_t)(int16_t)r[14];
goto P_0c04c9ce;
P_0c04c9ce: /* original 3e3c, guest PC 0x0c04c9ce */
if(!s->budget--) { s->failed_pc=0x0c04c9ceu; return 0; }
r[14]+=r[3];
goto P_0c04c9d0;
P_0c04c9d0: /* original 5de1, guest PC 0x0c04c9d0 */
if(!s->budget--) { s->failed_pc=0x0c04c9d0u; return 0; }
r[13]=read(ram,r[14]+4,4);
goto P_0c04c9d2;
P_0c04c9d2: /* original 60d3, guest PC 0x0c04c9d2 */
if(!s->budget--) { s->failed_pc=0x0c04c9d2u; return 0; }
r[0]=r[13];
goto P_0c04c9d4;
P_0c04c9d4: /* original 8800, guest PC 0x0c04c9d4 */
if(!s->budget--) { s->failed_pc=0x0c04c9d4u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000000u)!=0);
goto P_0c04c9d6;
P_0c04c9d6: /* original 8907, guest PC 0x0c04c9d6 */
if(!s->budget--) { s->failed_pc=0x0c04c9d6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04c9e8; }
goto P_0c04c9d8;
P_0c04c9d8: /* original 8801, guest PC 0x0c04c9d8 */
if(!s->budget--) { s->failed_pc=0x0c04c9d8u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c04c9da;
P_0c04c9da: /* original 8908, guest PC 0x0c04c9da */
if(!s->budget--) { s->failed_pc=0x0c04c9dau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04c9ee; }
goto P_0c04c9dc;
P_0c04c9dc: /* original 8802, guest PC 0x0c04c9dc */
if(!s->budget--) { s->failed_pc=0x0c04c9dcu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c04c9de;
P_0c04c9de: /* original 8909, guest PC 0x0c04c9de */
if(!s->budget--) { s->failed_pc=0x0c04c9deu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04c9f4; }
goto P_0c04c9e0;
P_0c04c9e0: /* original 8803, guest PC 0x0c04c9e0 */
if(!s->budget--) { s->failed_pc=0x0c04c9e0u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000003u)!=0);
goto P_0c04c9e2;
P_0c04c9e2: /* original 890a, guest PC 0x0c04c9e2 */
if(!s->budget--) { s->failed_pc=0x0c04c9e2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04c9fa; }
goto P_0c04c9e4;
P_0c04c9e4: /* original a00c, guest PC 0x0c04c9e4 */
if(!s->budget--) { s->failed_pc=0x0c04c9e4u; return 0; }
goto P_0c04ca00;
P_0c04c9e6: /* original 0009, guest PC 0x0c04c9e6 */
if(!s->budget--) { s->failed_pc=0x0c04c9e6u; return 0; }
goto P_0c04c9e8;
P_0c04c9e8: /* original 6442, guest PC 0x0c04c9e8 */
if(!s->budget--) { s->failed_pc=0x0c04c9e8u; return 0; }
tmp=read(ram,r[4],4);
r[4]=tmp;
goto P_0c04c9ea;
P_0c04c9ea: /* original a013, guest PC 0x0c04c9ea */
if(!s->budget--) { s->failed_pc=0x0c04c9eau; return 0; }
tmp=read(ram,r[7],4);
r[13]=tmp;
goto P_0c04ca14;
P_0c04c9ec: /* original 6d72, guest PC 0x0c04c9ec */
if(!s->budget--) { s->failed_pc=0x0c04c9ecu; return 0; }
tmp=read(ram,r[7],4);
r[13]=tmp;
goto P_0c04c9ee;
P_0c04c9ee: /* original 5441, guest PC 0x0c04c9ee */
if(!s->budget--) { s->failed_pc=0x0c04c9eeu; return 0; }
r[4]=read(ram,r[4]+4,4);
goto P_0c04c9f0;
P_0c04c9f0: /* original a010, guest PC 0x0c04c9f0 */
if(!s->budget--) { s->failed_pc=0x0c04c9f0u; return 0; }
r[13]=read(ram,r[7]+4,4);
goto P_0c04ca14;
P_0c04c9f2: /* original 5d71, guest PC 0x0c04c9f2 */
if(!s->budget--) { s->failed_pc=0x0c04c9f2u; return 0; }
r[13]=read(ram,r[7]+4,4);
goto P_0c04c9f4;
P_0c04c9f4: /* original 5442, guest PC 0x0c04c9f4 */
if(!s->budget--) { s->failed_pc=0x0c04c9f4u; return 0; }
r[4]=read(ram,r[4]+8,4);
goto P_0c04c9f6;
P_0c04c9f6: /* original a00d, guest PC 0x0c04c9f6 */
if(!s->budget--) { s->failed_pc=0x0c04c9f6u; return 0; }
r[13]=read(ram,r[7]+8,4);
goto P_0c04ca14;
P_0c04c9f8: /* original 5d72, guest PC 0x0c04c9f8 */
if(!s->budget--) { s->failed_pc=0x0c04c9f8u; return 0; }
r[13]=read(ram,r[7]+8,4);
goto P_0c04c9fa;
P_0c04c9fa: /* original 5443, guest PC 0x0c04c9fa */
if(!s->budget--) { s->failed_pc=0x0c04c9fau; return 0; }
r[4]=read(ram,r[4]+12,4);
goto P_0c04c9fc;
P_0c04c9fc: /* original a00a, guest PC 0x0c04c9fc */
if(!s->budget--) { s->failed_pc=0x0c04c9fcu; return 0; }
r[13]=read(ram,r[7]+12,4);
goto P_0c04ca14;
P_0c04c9fe: /* original 5d73, guest PC 0x0c04c9fe */
if(!s->budget--) { s->failed_pc=0x0c04c9feu; return 0; }
r[13]=read(ram,r[7]+12,4);
goto P_0c04ca00;
P_0c04ca00: /* original 2fd6, guest PC 0x0c04ca00 */
if(!s->budget--) { s->failed_pc=0x0c04ca00u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04ca02;
P_0c04ca02: /* original 9213, guest PC 0x0c04ca02 */
if(!s->budget--) { s->failed_pc=0x0c04ca02u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04ca2cu,2);
goto P_0c04ca04;
P_0c04ca04: /* original 2f26, guest PC 0x0c04ca04 */
if(!s->budget--) { s->failed_pc=0x0c04ca04u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04ca06;
P_0c04ca06: /* original d110, guest PC 0x0c04ca06 */
if(!s->budget--) { s->failed_pc=0x0c04ca06u; return 0; }
r[1]=read(ram,0x0c04ca48u,4);
goto P_0c04ca08;
P_0c04ca08: /* original 2f16, guest PC 0x0c04ca08 */
if(!s->budget--) { s->failed_pc=0x0c04ca08u; return 0; }
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04ca0a;
P_0c04ca0a: /* original d310, guest PC 0x0c04ca0a */
if(!s->budget--) { s->failed_pc=0x0c04ca0au; return 0; }
r[3]=read(ram,0x0c04ca4cu,4);
goto P_0c04ca0c;
P_0c04ca0c: /* original bdc8, guest PC 0x0c04ca0c */
if(!s->budget--) { s->failed_pc=0x0c04ca0cu; return 0; }
target=0x0c04c5a0u; r[16]=code_base|0x0c04ca10u;
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04ca10u) { target=s->pc; goto dispatch; }
goto P_0c04ca10;
P_0c04ca0e: /* original 2f36, guest PC 0x0c04ca0e */
if(!s->budget--) { s->failed_pc=0x0c04ca0eu; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04ca10;
P_0c04ca10: /* original a008, guest PC 0x0c04ca10 */
if(!s->budget--) { s->failed_pc=0x0c04ca10u; return 0; }
r[15]+=0x00000010u;
goto P_0c04ca24;
P_0c04ca12: /* original 7f10, guest PC 0x0c04ca12 */
if(!s->budget--) { s->failed_pc=0x0c04ca12u; return 0; }
r[15]+=0x00000010u;
goto P_0c04ca14;
P_0c04ca14: /* original 6743, guest PC 0x0c04ca14 */
if(!s->budget--) { s->failed_pc=0x0c04ca14u; return 0; }
r[7]=r[4];
goto P_0c04ca16;
P_0c04ca16: /* original 37dc, guest PC 0x0c04ca16 */
if(!s->budget--) { s->failed_pc=0x0c04ca16u; return 0; }
r[7]+=r[13];
goto P_0c04ca18;
P_0c04ca18: /* original 7701, guest PC 0x0c04ca18 */
if(!s->budget--) { s->failed_pc=0x0c04ca18u; return 0; }
r[7]+=0x00000001u;
goto P_0c04ca1a;
P_0c04ca1a: /* original 4718, guest PC 0x0c04ca1a */
if(!s->budget--) { s->failed_pc=0x0c04ca1au; return 0; }
r[7]<<=8;
goto P_0c04ca1c;
P_0c04ca1c: /* original 4700, guest PC 0x0c04ca1c */
if(!s->budget--) { s->failed_pc=0x0c04ca1cu; return 0; }
r[17]=(r[17]&~1u)|((r[7]>>31)!=0);
r[7]<<=1;
goto P_0c04ca1e;
P_0c04ca1e: /* original 7720, guest PC 0x0c04ca1e */
if(!s->budget--) { s->failed_pc=0x0c04ca1eu; return 0; }
r[7]+=0x00000020u;
goto P_0c04ca20;
P_0c04ca20: /* original 3767, guest PC 0x0c04ca20 */
if(!s->budget--) { s->failed_pc=0x0c04ca20u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[7]>(int32_t)r[6])!=0);
goto P_0c04ca22;
P_0c04ca22: /* original 8b15, guest PC 0x0c04ca22 */
if(!s->budget--) { s->failed_pc=0x0c04ca22u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04ca50; }
goto P_0c04ca24;
P_0c04ca24: /* original 9003, guest PC 0x0c04ca24 */
if(!s->budget--) { s->failed_pc=0x0c04ca24u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04ca2eu,2);
goto P_0c04ca26;
P_0c04ca26: /* original a082, guest PC 0x0c04ca26 */
if(!s->budget--) { s->failed_pc=0x0c04ca26u; return 0; }
goto P_0c04cb2e;
P_0c04ca28: /* original 0009, guest PC 0x0c04ca28 */
if(!s->budget--) { s->failed_pc=0x0c04ca28u; return 0; }
return vf3_matrix_family(0x0c04ca2au,s,ram);
P_0c04ca50: /* original e34c, guest PC 0x0c04ca50 */
if(!s->budget--) { s->failed_pc=0x0c04ca50u; return 0; }
r[3]=0x0000004cu;
goto P_0c04ca52;
P_0c04ca52: /* original 2c3f, guest PC 0x0c04ca52 */
if(!s->budget--) { s->failed_pc=0x0c04ca52u; return 0; }
r[19]=(uint32_t)((int32_t)(int16_t)r[12]*(int32_t)(int16_t)r[3]);
goto P_0c04ca54;
P_0c04ca54: /* original eb01, guest PC 0x0c04ca54 */
if(!s->budget--) { s->failed_pc=0x0c04ca54u; return 0; }
r[11]=0x00000001u;
goto P_0c04ca56;
P_0c04ca56: /* original 60b3, guest PC 0x0c04ca56 */
if(!s->budget--) { s->failed_pc=0x0c04ca56u; return 0; }
r[0]=r[11];
goto P_0c04ca58;
P_0c04ca58: /* original 80e2, guest PC 0x0c04ca58 */
if(!s->budget--) { s->failed_pc=0x0c04ca58u; return 0; }
write(ram,r[14]+2,r[0],1);
goto P_0c04ca5a;
P_0c04ca5a: /* original e000, guest PC 0x0c04ca5a */
if(!s->budget--) { s->failed_pc=0x0c04ca5au; return 0; }
r[0]=0x00000000u;
goto P_0c04ca5c;
P_0c04ca5c: /* original 2ec1, guest PC 0x0c04ca5c */
if(!s->budget--) { s->failed_pc=0x0c04ca5cu; return 0; }
write(ram,r[14],r[12],2);
goto P_0c04ca5e;
P_0c04ca5e: /* original 031a, guest PC 0x0c04ca5e */
if(!s->budget--) { s->failed_pc=0x0c04ca5eu; return 0; }
r[3]=r[19];
goto P_0c04ca60;
P_0c04ca60: /* original d24f, guest PC 0x0c04ca60 */
if(!s->budget--) { s->failed_pc=0x0c04ca60u; return 0; }
r[2]=read(ram,0x0c04cba0u,4);
goto P_0c04ca62;
P_0c04ca62: /* original 633f, guest PC 0x0c04ca62 */
if(!s->budget--) { s->failed_pc=0x0c04ca62u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)r[3];
goto P_0c04ca64;
P_0c04ca64: /* original 332c, guest PC 0x0c04ca64 */
if(!s->budget--) { s->failed_pc=0x0c04ca64u; return 0; }
r[3]+=r[2];
goto P_0c04ca66;
P_0c04ca66: /* original 1e37, guest PC 0x0c04ca66 */
if(!s->budget--) { s->failed_pc=0x0c04ca66u; return 0; }
write(ram,r[14]+28,r[3],4);
goto P_0c04ca68;
P_0c04ca68: /* original 6353, guest PC 0x0c04ca68 */
if(!s->budget--) { s->failed_pc=0x0c04ca68u; return 0; }
r[3]=r[5];
goto P_0c04ca6a;
P_0c04ca6a: /* original 7320, guest PC 0x0c04ca6a */
if(!s->budget--) { s->failed_pc=0x0c04ca6au; return 0; }
r[3]+=0x00000020u;
goto P_0c04ca6c;
P_0c04ca6c: /* original 80ea, guest PC 0x0c04ca6c */
if(!s->budget--) { s->failed_pc=0x0c04ca6cu; return 0; }
write(ram,r[14]+10,r[0],1);
goto P_0c04ca6e;
P_0c04ca6e: /* original 80eb, guest PC 0x0c04ca6e */
if(!s->budget--) { s->failed_pc=0x0c04ca6eu; return 0; }
write(ram,r[14]+11,r[0],1);
goto P_0c04ca70;
P_0c04ca70: /* original 80ec, guest PC 0x0c04ca70 */
if(!s->budget--) { s->failed_pc=0x0c04ca70u; return 0; }
write(ram,r[14]+12,r[0],1);
goto P_0c04ca72;
P_0c04ca72: /* original 60b3, guest PC 0x0c04ca72 */
if(!s->budget--) { s->failed_pc=0x0c04ca72u; return 0; }
r[0]=r[11];
goto P_0c04ca74;
P_0c04ca74: /* original 1e5b, guest PC 0x0c04ca74 */
if(!s->budget--) { s->failed_pc=0x0c04ca74u; return 0; }
write(ram,r[14]+44,r[5],4);
goto P_0c04ca76;
P_0c04ca76: /* original 1e38, guest PC 0x0c04ca76 */
if(!s->budget--) { s->failed_pc=0x0c04ca76u; return 0; }
write(ram,r[14]+32,r[3],4);
goto P_0c04ca78;
P_0c04ca78: /* original 6343, guest PC 0x0c04ca78 */
if(!s->budget--) { s->failed_pc=0x0c04ca78u; return 0; }
r[3]=r[4];
goto P_0c04ca7a;
P_0c04ca7a: /* original 7301, guest PC 0x0c04ca7a */
if(!s->budget--) { s->failed_pc=0x0c04ca7au; return 0; }
r[3]+=0x00000001u;
goto P_0c04ca7c;
P_0c04ca7c: /* original 918c, guest PC 0x0c04ca7c */
if(!s->budget--) { s->failed_pc=0x0c04ca7cu; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04cb98u,2);
goto P_0c04ca7e;
P_0c04ca7e: /* original 4318, guest PC 0x0c04ca7e */
if(!s->budget--) { s->failed_pc=0x0c04ca7eu; return 0; }
r[3]<<=8;
goto P_0c04ca80;
P_0c04ca80: /* original 4300, guest PC 0x0c04ca80 */
if(!s->budget--) { s->failed_pc=0x0c04ca80u; return 0; }
r[17]=(r[17]&~1u)|((r[3]>>31)!=0);
r[3]<<=1;
goto P_0c04ca82;
P_0c04ca82: /* original 335c, guest PC 0x0c04ca82 */
if(!s->budget--) { s->failed_pc=0x0c04ca82u; return 0; }
r[3]+=r[5];
goto P_0c04ca84;
P_0c04ca84: /* original 7320, guest PC 0x0c04ca84 */
if(!s->budget--) { s->failed_pc=0x0c04ca84u; return 0; }
r[3]+=0x00000020u;
goto P_0c04ca86;
P_0c04ca86: /* original 315c, guest PC 0x0c04ca86 */
if(!s->budget--) { s->failed_pc=0x0c04ca86u; return 0; }
r[1]+=r[5];
goto P_0c04ca88;
P_0c04ca88: /* original 1e19, guest PC 0x0c04ca88 */
if(!s->budget--) { s->failed_pc=0x0c04ca88u; return 0; }
write(ram,r[14]+36,r[1],4);
goto P_0c04ca8a;
P_0c04ca8a: /* original 1e3a, guest PC 0x0c04ca8a */
if(!s->budget--) { s->failed_pc=0x0c04ca8au; return 0; }
write(ram,r[14]+40,r[3],4);
goto P_0c04ca8c;
P_0c04ca8c: /* original 81e7, guest PC 0x0c04ca8c */
if(!s->budget--) { s->failed_pc=0x0c04ca8cu; return 0; }
write(ram,r[14]+14,r[0],2);
goto P_0c04ca8e;
P_0c04ca8e: /* original 6043, guest PC 0x0c04ca8e */
if(!s->budget--) { s->failed_pc=0x0c04ca8eu; return 0; }
r[0]=r[4];
goto P_0c04ca90;
P_0c04ca90: /* original 81e8, guest PC 0x0c04ca90 */
if(!s->budget--) { s->failed_pc=0x0c04ca90u; return 0; }
write(ram,r[14]+16,r[0],2);
goto P_0c04ca92;
P_0c04ca92: /* original 60d3, guest PC 0x0c04ca92 */
if(!s->budget--) { s->failed_pc=0x0c04ca92u; return 0; }
r[0]=r[13];
goto P_0c04ca94;
P_0c04ca94: /* original 81e9, guest PC 0x0c04ca94 */
if(!s->budget--) { s->failed_pc=0x0c04ca94u; return 0; }
write(ram,r[14]+18,r[0],2);
goto P_0c04ca96;
P_0c04ca96: /* original e020, guest PC 0x0c04ca96 */
if(!s->budget--) { s->failed_pc=0x0c04ca96u; return 0; }
r[0]=0x00000020u;
goto P_0c04ca98;
P_0c04ca98: /* original e500, guest PC 0x0c04ca98 */
if(!s->budget--) { s->failed_pc=0x0c04ca98u; return 0; }
r[5]=0x00000000u;
goto P_0c04ca9a;
P_0c04ca9a: /* original 64e3, guest PC 0x0c04ca9a */
if(!s->budget--) { s->failed_pc=0x0c04ca9au; return 0; }
r[4]=r[14];
goto P_0c04ca9c;
P_0c04ca9c: /* original 81ea, guest PC 0x0c04ca9c */
if(!s->budget--) { s->failed_pc=0x0c04ca9cu; return 0; }
write(ram,r[14]+20,r[0],2);
goto P_0c04ca9e;
P_0c04ca9e: /* original e610, guest PC 0x0c04ca9e */
if(!s->budget--) { s->failed_pc=0x0c04ca9eu; return 0; }
r[6]=0x00000010u;
goto P_0c04caa0;
P_0c04caa0: /* original da40, guest PC 0x0c04caa0 */
if(!s->budget--) { s->failed_pc=0x0c04caa0u; return 0; }
r[10]=read(ram,0x0c04cba4u,4);
goto P_0c04caa2;
P_0c04caa2: /* original 4a0b, guest PC 0x0c04caa2 */
if(!s->budget--) { s->failed_pc=0x0c04caa2u; return 0; }
target=r[10];
r[16]=code_base|0x0c04caa6u;
r[4]+=0x00000038u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04caa6u) { target=s->pc; goto dispatch; }
goto P_0c04caa6;
P_0c04caa4: /* original 7438, guest PC 0x0c04caa4 */
if(!s->budget--) { s->failed_pc=0x0c04caa4u; return 0; }
r[4]+=0x00000038u;
goto P_0c04caa6;
P_0c04caa6: /* original 9678, guest PC 0x0c04caa6 */
if(!s->budget--) { s->failed_pc=0x0c04caa6u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04cb9au,2);
goto P_0c04caa8;
P_0c04caa8: /* original 64e3, guest PC 0x0c04caa8 */
if(!s->budget--) { s->failed_pc=0x0c04caa8u; return 0; }
r[4]=r[14];
goto P_0c04caaa;
P_0c04caaa: /* original e500, guest PC 0x0c04caaa */
if(!s->budget--) { s->failed_pc=0x0c04caaau; return 0; }
r[5]=0x00000000u;
goto P_0c04caac;
P_0c04caac: /* original 4a0b, guest PC 0x0c04caac */
if(!s->budget--) { s->failed_pc=0x0c04caacu; return 0; }
target=r[10];
r[16]=code_base|0x0c04cab0u;
r[4]+=0x00000048u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04cab0u) { target=s->pc; goto dispatch; }
goto P_0c04cab0;
P_0c04caae: /* original 7448, guest PC 0x0c04caae */
if(!s->budget--) { s->failed_pc=0x0c04caaeu; return 0; }
r[4]+=0x00000048u;
goto P_0c04cab0;
P_0c04cab0: /* original e547, guest PC 0x0c04cab0 */
if(!s->budget--) { s->failed_pc=0x0c04cab0u; return 0; }
r[5]=0x00000047u;
goto P_0c04cab2;
P_0c04cab2: /* original e620, guest PC 0x0c04cab2 */
if(!s->budget--) { s->failed_pc=0x0c04cab2u; return 0; }
r[6]=0x00000020u;
goto P_0c04cab4;
P_0c04cab4: /* original 4a0b, guest PC 0x0c04cab4 */
if(!s->budget--) { s->failed_pc=0x0c04cab4u; return 0; }
target=r[10];
r[16]=code_base|0x0c04cab8u;
r[4]=read(ram,r[14]+44,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04cab8u) { target=s->pc; goto dispatch; }
goto P_0c04cab8;
P_0c04cab6: /* original 54eb, guest PC 0x0c04cab6 */
if(!s->budget--) { s->failed_pc=0x0c04cab6u; return 0; }
r[4]=read(ram,r[14]+44,4);
goto P_0c04cab8;
P_0c04cab8: /* original e553, guest PC 0x0c04cab8 */
if(!s->budget--) { s->failed_pc=0x0c04cab8u; return 0; }
r[5]=0x00000053u;
goto P_0c04caba;
P_0c04caba: /* original e620, guest PC 0x0c04caba */
if(!s->budget--) { s->failed_pc=0x0c04cabau; return 0; }
r[6]=0x00000020u;
goto P_0c04cabc;
P_0c04cabc: /* original 4a0b, guest PC 0x0c04cabc */
if(!s->budget--) { s->failed_pc=0x0c04cabcu; return 0; }
target=r[10];
r[16]=code_base|0x0c04cac0u;
r[4]=read(ram,r[14]+32,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04cac0u) { target=s->pc; goto dispatch; }
goto P_0c04cac0;
P_0c04cabe: /* original 54e8, guest PC 0x0c04cabe */
if(!s->budget--) { s->failed_pc=0x0c04cabeu; return 0; }
r[4]=read(ram,r[14]+32,4);
goto P_0c04cac0;
P_0c04cac0: /* original e546, guest PC 0x0c04cac0 */
if(!s->budget--) { s->failed_pc=0x0c04cac0u; return 0; }
r[5]=0x00000046u;
goto P_0c04cac2;
P_0c04cac2: /* original e620, guest PC 0x0c04cac2 */
if(!s->budget--) { s->failed_pc=0x0c04cac2u; return 0; }
r[6]=0x00000020u;
goto P_0c04cac4;
P_0c04cac4: /* original 4a0b, guest PC 0x0c04cac4 */
if(!s->budget--) { s->failed_pc=0x0c04cac4u; return 0; }
target=r[10];
r[16]=code_base|0x0c04cac8u;
r[4]=read(ram,r[14]+36,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04cac8u) { target=s->pc; goto dispatch; }
goto P_0c04cac8;
P_0c04cac6: /* original 54e9, guest PC 0x0c04cac6 */
if(!s->budget--) { s->failed_pc=0x0c04cac6u; return 0; }
r[4]=read(ram,r[14]+36,4);
goto P_0c04cac8;
P_0c04cac8: /* original e544, guest PC 0x0c04cac8 */
if(!s->budget--) { s->failed_pc=0x0c04cac8u; return 0; }
r[5]=0x00000044u;
goto P_0c04caca;
P_0c04caca: /* original e620, guest PC 0x0c04caca */
if(!s->budget--) { s->failed_pc=0x0c04cacau; return 0; }
r[6]=0x00000020u;
goto P_0c04cacc;
P_0c04cacc: /* original 4a0b, guest PC 0x0c04cacc */
if(!s->budget--) { s->failed_pc=0x0c04caccu; return 0; }
target=r[10];
r[16]=code_base|0x0c04cad0u;
r[4]=read(ram,r[14]+40,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04cad0u) { target=s->pc; goto dispatch; }
goto P_0c04cad0;
P_0c04cace: /* original 54ea, guest PC 0x0c04cace */
if(!s->budget--) { s->failed_pc=0x0c04caceu; return 0; }
r[4]=read(ram,r[14]+40,4);
goto P_0c04cad0;
P_0c04cad0: /* original 2fc6, guest PC 0x0c04cad0 */
if(!s->budget--) { s->failed_pc=0x0c04cad0u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04cad2;
P_0c04cad2: /* original d335, guest PC 0x0c04cad2 */
if(!s->budget--) { s->failed_pc=0x0c04cad2u; return 0; }
r[3]=read(ram,0x0c04cba8u,4);
goto P_0c04cad4;
P_0c04cad4: /* original bd64, guest PC 0x0c04cad4 */
if(!s->budget--) { s->failed_pc=0x0c04cad4u; return 0; }
target=0x0c04c5a0u; r[16]=code_base|0x0c04cad8u;
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04cad8u) { target=s->pc; goto dispatch; }
goto P_0c04cad8;
P_0c04cad6: /* original 2f36, guest PC 0x0c04cad6 */
if(!s->budget--) { s->failed_pc=0x0c04cad6u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04cad8;
P_0c04cad8: /* original 51e8, guest PC 0x0c04cad8 */
if(!s->budget--) { s->failed_pc=0x0c04cad8u; return 0; }
r[1]=read(ram,r[14]+32,4);
goto P_0c04cada;
P_0c04cada: /* original 71ff, guest PC 0x0c04cada */
if(!s->budget--) { s->failed_pc=0x0c04cadau; return 0; }
r[1]+=0xffffffffu;
goto P_0c04cadc;
P_0c04cadc: /* original 2f16, guest PC 0x0c04cadc */
if(!s->budget--) { s->failed_pc=0x0c04cadcu; return 0; }
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04cade;
P_0c04cade: /* original 53eb, guest PC 0x0c04cade */
if(!s->budget--) { s->failed_pc=0x0c04cadeu; return 0; }
r[3]=read(ram,r[14]+44,4);
goto P_0c04cae0;
P_0c04cae0: /* original 2f36, guest PC 0x0c04cae0 */
if(!s->budget--) { s->failed_pc=0x0c04cae0u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04cae2;
P_0c04cae2: /* original d232, guest PC 0x0c04cae2 */
if(!s->budget--) { s->failed_pc=0x0c04cae2u; return 0; }
r[2]=read(ram,0x0c04cbacu,4);
goto P_0c04cae4;
P_0c04cae4: /* original bd5c, guest PC 0x0c04cae4 */
if(!s->budget--) { s->failed_pc=0x0c04cae4u; return 0; }
target=0x0c04c5a0u; r[16]=code_base|0x0c04cae8u;
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04cae8u) { target=s->pc; goto dispatch; }
goto P_0c04cae8;
P_0c04cae6: /* original 2f26, guest PC 0x0c04cae6 */
if(!s->budget--) { s->failed_pc=0x0c04cae6u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04cae8;
P_0c04cae8: /* original 51e9, guest PC 0x0c04cae8 */
if(!s->budget--) { s->failed_pc=0x0c04cae8u; return 0; }
r[1]=read(ram,r[14]+36,4);
goto P_0c04caea;
P_0c04caea: /* original 71ff, guest PC 0x0c04caea */
if(!s->budget--) { s->failed_pc=0x0c04caeau; return 0; }
r[1]+=0xffffffffu;
goto P_0c04caec;
P_0c04caec: /* original 2f16, guest PC 0x0c04caec */
if(!s->budget--) { s->failed_pc=0x0c04caecu; return 0; }
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04caee;
P_0c04caee: /* original 53e8, guest PC 0x0c04caee */
if(!s->budget--) { s->failed_pc=0x0c04caeeu; return 0; }
r[3]=read(ram,r[14]+32,4);
goto P_0c04caf0;
P_0c04caf0: /* original 2f36, guest PC 0x0c04caf0 */
if(!s->budget--) { s->failed_pc=0x0c04caf0u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04caf2;
P_0c04caf2: /* original d22f, guest PC 0x0c04caf2 */
if(!s->budget--) { s->failed_pc=0x0c04caf2u; return 0; }
r[2]=read(ram,0x0c04cbb0u,4);
goto P_0c04caf4;
P_0c04caf4: /* original bd54, guest PC 0x0c04caf4 */
if(!s->budget--) { s->failed_pc=0x0c04caf4u; return 0; }
target=0x0c04c5a0u; r[16]=code_base|0x0c04caf8u;
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04caf8u) { target=s->pc; goto dispatch; }
goto P_0c04caf8;
P_0c04caf6: /* original 2f26, guest PC 0x0c04caf6 */
if(!s->budget--) { s->failed_pc=0x0c04caf6u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04caf8;
P_0c04caf8: /* original 51ea, guest PC 0x0c04caf8 */
if(!s->budget--) { s->failed_pc=0x0c04caf8u; return 0; }
r[1]=read(ram,r[14]+40,4);
goto P_0c04cafa;
P_0c04cafa: /* original 71ff, guest PC 0x0c04cafa */
if(!s->budget--) { s->failed_pc=0x0c04cafau; return 0; }
r[1]+=0xffffffffu;
goto P_0c04cafc;
P_0c04cafc: /* original 2f16, guest PC 0x0c04cafc */
if(!s->budget--) { s->failed_pc=0x0c04cafcu; return 0; }
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04cafe;
P_0c04cafe: /* original 53e9, guest PC 0x0c04cafe */
if(!s->budget--) { s->failed_pc=0x0c04cafeu; return 0; }
r[3]=read(ram,r[14]+36,4);
goto P_0c04cb00;
P_0c04cb00: /* original 2f36, guest PC 0x0c04cb00 */
if(!s->budget--) { s->failed_pc=0x0c04cb00u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04cb02;
P_0c04cb02: /* original d22c, guest PC 0x0c04cb02 */
if(!s->budget--) { s->failed_pc=0x0c04cb02u; return 0; }
r[2]=read(ram,0x0c04cbb4u,4);
goto P_0c04cb04;
P_0c04cb04: /* original bd4c, guest PC 0x0c04cb04 */
if(!s->budget--) { s->failed_pc=0x0c04cb04u; return 0; }
target=0x0c04c5a0u; r[16]=code_base|0x0c04cb08u;
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04cb08u) { target=s->pc; goto dispatch; }
goto P_0c04cb08;
P_0c04cb06: /* original 2f26, guest PC 0x0c04cb06 */
if(!s->budget--) { s->failed_pc=0x0c04cb06u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04cb08;
P_0c04cb08: /* original 52ea, guest PC 0x0c04cb08 */
if(!s->budget--) { s->failed_pc=0x0c04cb08u; return 0; }
r[2]=read(ram,r[14]+40,4);
goto P_0c04cb0a;
P_0c04cb0a: /* original 4d18, guest PC 0x0c04cb0a */
if(!s->budget--) { s->failed_pc=0x0c04cb0au; return 0; }
r[13]<<=8;
goto P_0c04cb0c;
P_0c04cb0c: /* original 4d00, guest PC 0x0c04cb0c */
if(!s->budget--) { s->failed_pc=0x0c04cb0cu; return 0; }
r[17]=(r[17]&~1u)|((r[13]>>31)!=0);
r[13]<<=1;
goto P_0c04cb0e;
P_0c04cb0e: /* original 3d2c, guest PC 0x0c04cb0e */
if(!s->budget--) { s->failed_pc=0x0c04cb0eu; return 0; }
r[13]+=r[2];
goto P_0c04cb10;
P_0c04cb10: /* original 7dff, guest PC 0x0c04cb10 */
if(!s->budget--) { s->failed_pc=0x0c04cb10u; return 0; }
r[13]+=0xffffffffu;
goto P_0c04cb12;
P_0c04cb12: /* original 2fd6, guest PC 0x0c04cb12 */
if(!s->budget--) { s->failed_pc=0x0c04cb12u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04cb14;
P_0c04cb14: /* original 53ea, guest PC 0x0c04cb14 */
if(!s->budget--) { s->failed_pc=0x0c04cb14u; return 0; }
r[3]=read(ram,r[14]+40,4);
goto P_0c04cb16;
P_0c04cb16: /* original 2f36, guest PC 0x0c04cb16 */
if(!s->budget--) { s->failed_pc=0x0c04cb16u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04cb18;
P_0c04cb18: /* original d227, guest PC 0x0c04cb18 */
if(!s->budget--) { s->failed_pc=0x0c04cb18u; return 0; }
r[2]=read(ram,0x0c04cbb8u,4);
goto P_0c04cb1a;
P_0c04cb1a: /* original bd41, guest PC 0x0c04cb1a */
if(!s->budget--) { s->failed_pc=0x0c04cb1au; return 0; }
target=0x0c04c5a0u; r[16]=code_base|0x0c04cb1eu;
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04cb1eu) { target=s->pc; goto dispatch; }
goto P_0c04cb1e;
P_0c04cb1c: /* original 2f26, guest PC 0x0c04cb1c */
if(!s->budget--) { s->failed_pc=0x0c04cb1cu; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04cb1e;
P_0c04cb1e: /* original 54e7, guest PC 0x0c04cb1e */
if(!s->budget--) { s->failed_pc=0x0c04cb1eu; return 0; }
r[4]=read(ram,r[14]+28,4);
goto P_0c04cb20;
P_0c04cb20: /* original 60b3, guest PC 0x0c04cb20 */
if(!s->budget--) { s->failed_pc=0x0c04cb20u; return 0; }
r[0]=r[11];
goto P_0c04cb22;
P_0c04cb22: /* original 7f38, guest PC 0x0c04cb22 */
if(!s->budget--) { s->failed_pc=0x0c04cb22u; return 0; }
r[15]+=0x00000038u;
goto P_0c04cb24;
P_0c04cb24: /* original 5247, guest PC 0x0c04cb24 */
if(!s->budget--) { s->failed_pc=0x0c04cb24u; return 0; }
r[2]=read(ram,r[4]+28,4);
goto P_0c04cb26;
P_0c04cb26: /* original 142c, guest PC 0x0c04cb26 */
if(!s->budget--) { s->failed_pc=0x0c04cb26u; return 0; }
write(ram,r[4]+48,r[2],4);
goto P_0c04cb28;
P_0c04cb28: /* original 80e8, guest PC 0x0c04cb28 */
if(!s->budget--) { s->failed_pc=0x0c04cb28u; return 0; }
write(ram,r[14]+8,r[0],1);
goto P_0c04cb2a;
P_0c04cb2a: /* original 80e9, guest PC 0x0c04cb2a */
if(!s->budget--) { s->failed_pc=0x0c04cb2au; return 0; }
write(ram,r[14]+9,r[0],1);
goto P_0c04cb2c;
P_0c04cb2c: /* original e000, guest PC 0x0c04cb2c */
if(!s->budget--) { s->failed_pc=0x0c04cb2cu; return 0; }
r[0]=0x00000000u;
goto P_0c04cb2e;
P_0c04cb2e: /* original 4f16, guest PC 0x0c04cb2e */
if(!s->budget--) { s->failed_pc=0x0c04cb2eu; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c04cb30;
P_0c04cb30: /* original 4f26, guest PC 0x0c04cb30 */
if(!s->budget--) { s->failed_pc=0x0c04cb30u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c04cb32;
P_0c04cb32: /* original 6af6, guest PC 0x0c04cb32 */
if(!s->budget--) { s->failed_pc=0x0c04cb32u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c04cb34;
P_0c04cb34: /* original 6bf6, guest PC 0x0c04cb34 */
if(!s->budget--) { s->failed_pc=0x0c04cb34u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c04cb36;
P_0c04cb36: /* original 6cf6, guest PC 0x0c04cb36 */
if(!s->budget--) { s->failed_pc=0x0c04cb36u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c04cb38;
P_0c04cb38: /* original 6df6, guest PC 0x0c04cb38 */
if(!s->budget--) { s->failed_pc=0x0c04cb38u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c04cb3a;
P_0c04cb3a: /* original 000b, guest PC 0x0c04cb3a */
if(!s->budget--) { s->failed_pc=0x0c04cb3au; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c04cb3c: /* original 6ef6, guest PC 0x0c04cb3c */
if(!s->budget--) { s->failed_pc=0x0c04cb3cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c04cb3eu,s,ram);
P_0c081d24: /* original 2fe6, guest PC 0x0c081d24 */
if(!s->budget--) { s->failed_pc=0x0c081d24u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c081d26;
P_0c081d26: /* original e307, guest PC 0x0c081d26 */
if(!s->budget--) { s->failed_pc=0x0c081d26u; return 0; }
r[3]=0x00000007u;
goto P_0c081d28;
P_0c081d28: /* original 2fd6, guest PC 0x0c081d28 */
if(!s->budget--) { s->failed_pc=0x0c081d28u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c081d2a;
P_0c081d2a: /* original 453c, guest PC 0x0c081d2a */
if(!s->budget--) { s->failed_pc=0x0c081d2au; return 0; }
r[5]=(r[3]&0x80000000u)?((r[3]&31u)?(uint32_t)((int32_t)r[5]>>((-r[3])&31u)):((int32_t)r[5]<0?0xffffffffu:0)):r[5]<<(r[3]&31u);
goto P_0c081d2c;
P_0c081d2c: /* original 2fc6, guest PC 0x0c081d2c */
if(!s->budget--) { s->failed_pc=0x0c081d2cu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c081d2e;
P_0c081d2e: /* original 6c43, guest PC 0x0c081d2e */
if(!s->budget--) { s->failed_pc=0x0c081d2eu; return 0; }
r[12]=r[4];
goto P_0c081d30;
P_0c081d30: /* original 2fb6, guest PC 0x0c081d30 */
if(!s->budget--) { s->failed_pc=0x0c081d30u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c081d32;
P_0c081d32: /* original 7c02, guest PC 0x0c081d32 */
if(!s->budget--) { s->failed_pc=0x0c081d32u; return 0; }
r[12]+=0x00000002u;
goto P_0c081d34;
P_0c081d34: /* original 2fa6, guest PC 0x0c081d34 */
if(!s->budget--) { s->failed_pc=0x0c081d34u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c081d36;
P_0c081d36: /* original 6d63, guest PC 0x0c081d36 */
if(!s->budget--) { s->failed_pc=0x0c081d36u; return 0; }
r[13]=r[6];
goto P_0c081d38;
P_0c081d38: /* original 4f22, guest PC 0x0c081d38 */
if(!s->budget--) { s->failed_pc=0x0c081d38u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c081d3a;
P_0c081d3a: /* original db4a, guest PC 0x0c081d3a */
if(!s->budget--) { s->failed_pc=0x0c081d3au; return 0; }
r[11]=read(ram,0x0c081e64u,4);
goto P_0c081d3c;
P_0c081d3c: /* original 4c00, guest PC 0x0c081d3c */
if(!s->budget--) { s->failed_pc=0x0c081d3cu; return 0; }
r[17]=(r[17]&~1u)|((r[12]>>31)!=0);
r[12]<<=1;
goto P_0c081d3e;
P_0c081d3e: /* original de48, guest PC 0x0c081d3e */
if(!s->budget--) { s->failed_pc=0x0c081d3eu; return 0; }
r[14]=read(ram,0x0c081e60u,4);
goto P_0c081d40;
P_0c081d40: /* original 2dd8, guest PC 0x0c081d40 */
if(!s->budget--) { s->failed_pc=0x0c081d40u; return 0; }
r[17]=(r[17]&~1u)|(((r[13]&r[13])==0)!=0);
goto P_0c081d42;
P_0c081d42: /* original 2c5b, guest PC 0x0c081d42 */
if(!s->budget--) { s->failed_pc=0x0c081d42u; return 0; }
r[12]|=r[5];
goto P_0c081d44;
P_0c081d44: /* original 8f07, guest PC 0x0c081d44 */
if(!s->budget--) { s->failed_pc=0x0c081d44u; return 0; }
cond=r[17]&1u;
r[10]=0x00000010u;
if(!cond) { goto P_0c081d56; }
goto P_0c081d48;
P_0c081d46: /* original ea10, guest PC 0x0c081d46 */
if(!s->budget--) { s->failed_pc=0x0c081d46u; return 0; }
r[10]=0x00000010u;
goto P_0c081d48;
P_0c081d48: /* original 66e3, guest PC 0x0c081d48 */
if(!s->budget--) { s->failed_pc=0x0c081d48u; return 0; }
r[6]=r[14];
goto P_0c081d4a;
P_0c081d4a: /* original 2fa6, guest PC 0x0c081d4a */
if(!s->budget--) { s->failed_pc=0x0c081d4au; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c081d4c;
P_0c081d4c: /* original 9578, guest PC 0x0c081d4c */
if(!s->budget--) { s->failed_pc=0x0c081d4cu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c081e40u,2);
goto P_0c081d4e;
P_0c081d4e: /* original e700, guest PC 0x0c081d4e */
if(!s->budget--) { s->failed_pc=0x0c081d4eu; return 0; }
r[7]=0x00000000u;
goto P_0c081d50;
P_0c081d50: /* original 4b0b, guest PC 0x0c081d50 */
if(!s->budget--) { s->failed_pc=0x0c081d50u; return 0; }
target=r[11];
r[16]=code_base|0x0c081d54u;
r[4]=r[12];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c081d54u) { target=s->pc; goto dispatch; }
goto P_0c081d54;
P_0c081d52: /* original 64c3, guest PC 0x0c081d52 */
if(!s->budget--) { s->failed_pc=0x0c081d52u; return 0; }
r[4]=r[12];
goto P_0c081d54;
P_0c081d54: /* original 7f04, guest PC 0x0c081d54 */
if(!s->budget--) { s->failed_pc=0x0c081d54u; return 0; }
r[15]+=0x00000004u;
goto P_0c081d56;
P_0c081d56: /* original 60d3, guest PC 0x0c081d56 */
if(!s->budget--) { s->failed_pc=0x0c081d56u; return 0; }
r[0]=r[13];
goto P_0c081d58;
P_0c081d58: /* original 8801, guest PC 0x0c081d58 */
if(!s->budget--) { s->failed_pc=0x0c081d58u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c081d5a;
P_0c081d5a: /* original 8b06, guest PC 0x0c081d5a */
if(!s->budget--) { s->failed_pc=0x0c081d5au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c081d6a; }
goto P_0c081d5c;
P_0c081d5c: /* original 66e3, guest PC 0x0c081d5c */
if(!s->budget--) { s->failed_pc=0x0c081d5cu; return 0; }
r[6]=r[14];
goto P_0c081d5e;
P_0c081d5e: /* original 2fa6, guest PC 0x0c081d5e */
if(!s->budget--) { s->failed_pc=0x0c081d5eu; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c081d60;
P_0c081d60: /* original 956f, guest PC 0x0c081d60 */
if(!s->budget--) { s->failed_pc=0x0c081d60u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c081e42u,2);
goto P_0c081d62;
P_0c081d62: /* original e700, guest PC 0x0c081d62 */
if(!s->budget--) { s->failed_pc=0x0c081d62u; return 0; }
r[7]=0x00000000u;
goto P_0c081d64;
P_0c081d64: /* original 4b0b, guest PC 0x0c081d64 */
if(!s->budget--) { s->failed_pc=0x0c081d64u; return 0; }
target=r[11];
r[16]=code_base|0x0c081d68u;
r[4]=r[12];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c081d68u) { target=s->pc; goto dispatch; }
goto P_0c081d68;
P_0c081d66: /* original 64c3, guest PC 0x0c081d66 */
if(!s->budget--) { s->failed_pc=0x0c081d66u; return 0; }
r[4]=r[12];
goto P_0c081d68;
P_0c081d68: /* original 7f04, guest PC 0x0c081d68 */
if(!s->budget--) { s->failed_pc=0x0c081d68u; return 0; }
r[15]+=0x00000004u;
goto P_0c081d6a;
P_0c081d6a: /* original 60d3, guest PC 0x0c081d6a */
if(!s->budget--) { s->failed_pc=0x0c081d6au; return 0; }
r[0]=r[13];
goto P_0c081d6c;
P_0c081d6c: /* original 8802, guest PC 0x0c081d6c */
if(!s->budget--) { s->failed_pc=0x0c081d6cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c081d6e;
P_0c081d6e: /* original 8b06, guest PC 0x0c081d6e */
if(!s->budget--) { s->failed_pc=0x0c081d6eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c081d7e; }
goto P_0c081d70;
P_0c081d70: /* original 66e3, guest PC 0x0c081d70 */
if(!s->budget--) { s->failed_pc=0x0c081d70u; return 0; }
r[6]=r[14];
goto P_0c081d72;
P_0c081d72: /* original 2fa6, guest PC 0x0c081d72 */
if(!s->budget--) { s->failed_pc=0x0c081d72u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c081d74;
P_0c081d74: /* original 9566, guest PC 0x0c081d74 */
if(!s->budget--) { s->failed_pc=0x0c081d74u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c081e44u,2);
goto P_0c081d76;
P_0c081d76: /* original e700, guest PC 0x0c081d76 */
if(!s->budget--) { s->failed_pc=0x0c081d76u; return 0; }
r[7]=0x00000000u;
goto P_0c081d78;
P_0c081d78: /* original 4b0b, guest PC 0x0c081d78 */
if(!s->budget--) { s->failed_pc=0x0c081d78u; return 0; }
target=r[11];
r[16]=code_base|0x0c081d7cu;
r[4]=r[12];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c081d7cu) { target=s->pc; goto dispatch; }
goto P_0c081d7c;
P_0c081d7a: /* original 64c3, guest PC 0x0c081d7a */
if(!s->budget--) { s->failed_pc=0x0c081d7au; return 0; }
r[4]=r[12];
goto P_0c081d7c;
P_0c081d7c: /* original 7f04, guest PC 0x0c081d7c */
if(!s->budget--) { s->failed_pc=0x0c081d7cu; return 0; }
r[15]+=0x00000004u;
goto P_0c081d7e;
P_0c081d7e: /* original 60d3, guest PC 0x0c081d7e */
if(!s->budget--) { s->failed_pc=0x0c081d7eu; return 0; }
r[0]=r[13];
goto P_0c081d80;
P_0c081d80: /* original 8804, guest PC 0x0c081d80 */
if(!s->budget--) { s->failed_pc=0x0c081d80u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000004u)!=0);
goto P_0c081d82;
P_0c081d82: /* original 8b06, guest PC 0x0c081d82 */
if(!s->budget--) { s->failed_pc=0x0c081d82u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c081d92; }
goto P_0c081d84;
P_0c081d84: /* original 66e3, guest PC 0x0c081d84 */
if(!s->budget--) { s->failed_pc=0x0c081d84u; return 0; }
r[6]=r[14];
goto P_0c081d86;
P_0c081d86: /* original 2fa6, guest PC 0x0c081d86 */
if(!s->budget--) { s->failed_pc=0x0c081d86u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c081d88;
P_0c081d88: /* original 955d, guest PC 0x0c081d88 */
if(!s->budget--) { s->failed_pc=0x0c081d88u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c081e46u,2);
goto P_0c081d8a;
P_0c081d8a: /* original e700, guest PC 0x0c081d8a */
if(!s->budget--) { s->failed_pc=0x0c081d8au; return 0; }
r[7]=0x00000000u;
goto P_0c081d8c;
P_0c081d8c: /* original 4b0b, guest PC 0x0c081d8c */
if(!s->budget--) { s->failed_pc=0x0c081d8cu; return 0; }
target=r[11];
r[16]=code_base|0x0c081d90u;
r[4]=r[12];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c081d90u) { target=s->pc; goto dispatch; }
goto P_0c081d90;
P_0c081d8e: /* original 64c3, guest PC 0x0c081d8e */
if(!s->budget--) { s->failed_pc=0x0c081d8eu; return 0; }
r[4]=r[12];
goto P_0c081d90;
P_0c081d90: /* original 7f04, guest PC 0x0c081d90 */
if(!s->budget--) { s->failed_pc=0x0c081d90u; return 0; }
r[15]+=0x00000004u;
goto P_0c081d92;
P_0c081d92: /* original 60d3, guest PC 0x0c081d92 */
if(!s->budget--) { s->failed_pc=0x0c081d92u; return 0; }
r[0]=r[13];
goto P_0c081d94;
P_0c081d94: /* original 8808, guest PC 0x0c081d94 */
if(!s->budget--) { s->failed_pc=0x0c081d94u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000008u)!=0);
goto P_0c081d96;
P_0c081d96: /* original 8b06, guest PC 0x0c081d96 */
if(!s->budget--) { s->failed_pc=0x0c081d96u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c081da6; }
goto P_0c081d98;
P_0c081d98: /* original 66e3, guest PC 0x0c081d98 */
if(!s->budget--) { s->failed_pc=0x0c081d98u; return 0; }
r[6]=r[14];
goto P_0c081d9a;
P_0c081d9a: /* original 2fa6, guest PC 0x0c081d9a */
if(!s->budget--) { s->failed_pc=0x0c081d9au; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c081d9c;
P_0c081d9c: /* original 9554, guest PC 0x0c081d9c */
if(!s->budget--) { s->failed_pc=0x0c081d9cu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c081e48u,2);
goto P_0c081d9e;
P_0c081d9e: /* original e700, guest PC 0x0c081d9e */
if(!s->budget--) { s->failed_pc=0x0c081d9eu; return 0; }
r[7]=0x00000000u;
goto P_0c081da0;
P_0c081da0: /* original 4b0b, guest PC 0x0c081da0 */
if(!s->budget--) { s->failed_pc=0x0c081da0u; return 0; }
target=r[11];
r[16]=code_base|0x0c081da4u;
r[4]=r[12];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c081da4u) { target=s->pc; goto dispatch; }
goto P_0c081da4;
P_0c081da2: /* original 64c3, guest PC 0x0c081da2 */
if(!s->budget--) { s->failed_pc=0x0c081da2u; return 0; }
r[4]=r[12];
goto P_0c081da4;
P_0c081da4: /* original 7f04, guest PC 0x0c081da4 */
if(!s->budget--) { s->failed_pc=0x0c081da4u; return 0; }
r[15]+=0x00000004u;
goto P_0c081da6;
P_0c081da6: /* original 60d3, guest PC 0x0c081da6 */
if(!s->budget--) { s->failed_pc=0x0c081da6u; return 0; }
r[0]=r[13];
goto P_0c081da8;
P_0c081da8: /* original 8810, guest PC 0x0c081da8 */
if(!s->budget--) { s->failed_pc=0x0c081da8u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000010u)!=0);
goto P_0c081daa;
P_0c081daa: /* original 8b06, guest PC 0x0c081daa */
if(!s->budget--) { s->failed_pc=0x0c081daau; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c081dba; }
goto P_0c081dac;
P_0c081dac: /* original 66e3, guest PC 0x0c081dac */
if(!s->budget--) { s->failed_pc=0x0c081dacu; return 0; }
r[6]=r[14];
goto P_0c081dae;
P_0c081dae: /* original 2fa6, guest PC 0x0c081dae */
if(!s->budget--) { s->failed_pc=0x0c081daeu; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c081db0;
P_0c081db0: /* original 954b, guest PC 0x0c081db0 */
if(!s->budget--) { s->failed_pc=0x0c081db0u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c081e4au,2);
goto P_0c081db2;
P_0c081db2: /* original e700, guest PC 0x0c081db2 */
if(!s->budget--) { s->failed_pc=0x0c081db2u; return 0; }
r[7]=0x00000000u;
goto P_0c081db4;
P_0c081db4: /* original 4b0b, guest PC 0x0c081db4 */
if(!s->budget--) { s->failed_pc=0x0c081db4u; return 0; }
target=r[11];
r[16]=code_base|0x0c081db8u;
r[4]=r[12];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c081db8u) { target=s->pc; goto dispatch; }
goto P_0c081db8;
P_0c081db6: /* original 64c3, guest PC 0x0c081db6 */
if(!s->budget--) { s->failed_pc=0x0c081db6u; return 0; }
r[4]=r[12];
goto P_0c081db8;
P_0c081db8: /* original 7f04, guest PC 0x0c081db8 */
if(!s->budget--) { s->failed_pc=0x0c081db8u; return 0; }
r[15]+=0x00000004u;
goto P_0c081dba;
P_0c081dba: /* original 60d3, guest PC 0x0c081dba */
if(!s->budget--) { s->failed_pc=0x0c081dbau; return 0; }
r[0]=r[13];
goto P_0c081dbc;
P_0c081dbc: /* original 8820, guest PC 0x0c081dbc */
if(!s->budget--) { s->failed_pc=0x0c081dbcu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000020u)!=0);
goto P_0c081dbe;
P_0c081dbe: /* original 8b06, guest PC 0x0c081dbe */
if(!s->budget--) { s->failed_pc=0x0c081dbeu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c081dce; }
goto P_0c081dc0;
P_0c081dc0: /* original 66e3, guest PC 0x0c081dc0 */
if(!s->budget--) { s->failed_pc=0x0c081dc0u; return 0; }
r[6]=r[14];
goto P_0c081dc2;
P_0c081dc2: /* original 2fa6, guest PC 0x0c081dc2 */
if(!s->budget--) { s->failed_pc=0x0c081dc2u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c081dc4;
P_0c081dc4: /* original 9542, guest PC 0x0c081dc4 */
if(!s->budget--) { s->failed_pc=0x0c081dc4u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c081e4cu,2);
goto P_0c081dc6;
P_0c081dc6: /* original e700, guest PC 0x0c081dc6 */
if(!s->budget--) { s->failed_pc=0x0c081dc6u; return 0; }
r[7]=0x00000000u;
goto P_0c081dc8;
P_0c081dc8: /* original 4b0b, guest PC 0x0c081dc8 */
if(!s->budget--) { s->failed_pc=0x0c081dc8u; return 0; }
target=r[11];
r[16]=code_base|0x0c081dccu;
r[4]=r[12];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c081dccu) { target=s->pc; goto dispatch; }
goto P_0c081dcc;
P_0c081dca: /* original 64c3, guest PC 0x0c081dca */
if(!s->budget--) { s->failed_pc=0x0c081dcau; return 0; }
r[4]=r[12];
goto P_0c081dcc;
P_0c081dcc: /* original 7f04, guest PC 0x0c081dcc */
if(!s->budget--) { s->failed_pc=0x0c081dccu; return 0; }
r[15]+=0x00000004u;
goto P_0c081dce;
P_0c081dce: /* original 60d3, guest PC 0x0c081dce */
if(!s->budget--) { s->failed_pc=0x0c081dceu; return 0; }
r[0]=r[13];
goto P_0c081dd0;
P_0c081dd0: /* original 8840, guest PC 0x0c081dd0 */
if(!s->budget--) { s->failed_pc=0x0c081dd0u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000040u)!=0);
goto P_0c081dd2;
P_0c081dd2: /* original 8b06, guest PC 0x0c081dd2 */
if(!s->budget--) { s->failed_pc=0x0c081dd2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c081de2; }
goto P_0c081dd4;
P_0c081dd4: /* original 66e3, guest PC 0x0c081dd4 */
if(!s->budget--) { s->failed_pc=0x0c081dd4u; return 0; }
r[6]=r[14];
goto P_0c081dd6;
P_0c081dd6: /* original 2fa6, guest PC 0x0c081dd6 */
if(!s->budget--) { s->failed_pc=0x0c081dd6u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c081dd8;
P_0c081dd8: /* original 9539, guest PC 0x0c081dd8 */
if(!s->budget--) { s->failed_pc=0x0c081dd8u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c081e4eu,2);
goto P_0c081dda;
P_0c081dda: /* original e700, guest PC 0x0c081dda */
if(!s->budget--) { s->failed_pc=0x0c081ddau; return 0; }
r[7]=0x00000000u;
goto P_0c081ddc;
P_0c081ddc: /* original 4b0b, guest PC 0x0c081ddc */
if(!s->budget--) { s->failed_pc=0x0c081ddcu; return 0; }
target=r[11];
r[16]=code_base|0x0c081de0u;
r[4]=r[12];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c081de0u) { target=s->pc; goto dispatch; }
goto P_0c081de0;
P_0c081dde: /* original 64c3, guest PC 0x0c081dde */
if(!s->budget--) { s->failed_pc=0x0c081ddeu; return 0; }
r[4]=r[12];
goto P_0c081de0;
P_0c081de0: /* original 7f04, guest PC 0x0c081de0 */
if(!s->budget--) { s->failed_pc=0x0c081de0u; return 0; }
r[15]+=0x00000004u;
goto P_0c081de2;
P_0c081de2: /* original 9235, guest PC 0x0c081de2 */
if(!s->budget--) { s->failed_pc=0x0c081de2u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c081e50u,2);
goto P_0c081de4;
P_0c081de4: /* original 3d20, guest PC 0x0c081de4 */
if(!s->budget--) { s->failed_pc=0x0c081de4u; return 0; }
r[17]=(r[17]&~1u)|((r[13]==r[2])!=0);
goto P_0c081de6;
P_0c081de6: /* original 8b06, guest PC 0x0c081de6 */
if(!s->budget--) { s->failed_pc=0x0c081de6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c081df6; }
goto P_0c081de8;
P_0c081de8: /* original 66e3, guest PC 0x0c081de8 */
if(!s->budget--) { s->failed_pc=0x0c081de8u; return 0; }
r[6]=r[14];
goto P_0c081dea;
P_0c081dea: /* original 2fa6, guest PC 0x0c081dea */
if(!s->budget--) { s->failed_pc=0x0c081deau; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c081dec;
P_0c081dec: /* original 9531, guest PC 0x0c081dec */
if(!s->budget--) { s->failed_pc=0x0c081decu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c081e52u,2);
goto P_0c081dee;
P_0c081dee: /* original e700, guest PC 0x0c081dee */
if(!s->budget--) { s->failed_pc=0x0c081deeu; return 0; }
r[7]=0x00000000u;
goto P_0c081df0;
P_0c081df0: /* original 4b0b, guest PC 0x0c081df0 */
if(!s->budget--) { s->failed_pc=0x0c081df0u; return 0; }
target=r[11];
r[16]=code_base|0x0c081df4u;
r[4]=r[12];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c081df4u) { target=s->pc; goto dispatch; }
goto P_0c081df4;
P_0c081df2: /* original 64c3, guest PC 0x0c081df2 */
if(!s->budget--) { s->failed_pc=0x0c081df2u; return 0; }
r[4]=r[12];
goto P_0c081df4;
P_0c081df4: /* original 7f04, guest PC 0x0c081df4 */
if(!s->budget--) { s->failed_pc=0x0c081df4u; return 0; }
r[15]+=0x00000004u;
goto P_0c081df6;
P_0c081df6: /* original 922d, guest PC 0x0c081df6 */
if(!s->budget--) { s->failed_pc=0x0c081df6u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c081e54u,2);
goto P_0c081df8;
P_0c081df8: /* original 3d20, guest PC 0x0c081df8 */
if(!s->budget--) { s->failed_pc=0x0c081df8u; return 0; }
r[17]=(r[17]&~1u)|((r[13]==r[2])!=0);
goto P_0c081dfa;
P_0c081dfa: /* original 8b06, guest PC 0x0c081dfa */
if(!s->budget--) { s->failed_pc=0x0c081dfau; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c081e0a; }
goto P_0c081dfc;
P_0c081dfc: /* original 66e3, guest PC 0x0c081dfc */
if(!s->budget--) { s->failed_pc=0x0c081dfcu; return 0; }
r[6]=r[14];
goto P_0c081dfe;
P_0c081dfe: /* original 2fa6, guest PC 0x0c081dfe */
if(!s->budget--) { s->failed_pc=0x0c081dfeu; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c081e00;
P_0c081e00: /* original 9529, guest PC 0x0c081e00 */
if(!s->budget--) { s->failed_pc=0x0c081e00u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c081e56u,2);
goto P_0c081e02;
P_0c081e02: /* original e700, guest PC 0x0c081e02 */
if(!s->budget--) { s->failed_pc=0x0c081e02u; return 0; }
r[7]=0x00000000u;
goto P_0c081e04;
P_0c081e04: /* original 4b0b, guest PC 0x0c081e04 */
if(!s->budget--) { s->failed_pc=0x0c081e04u; return 0; }
target=r[11];
r[16]=code_base|0x0c081e08u;
r[4]=r[12];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c081e08u) { target=s->pc; goto dispatch; }
goto P_0c081e08;
P_0c081e06: /* original 64c3, guest PC 0x0c081e06 */
if(!s->budget--) { s->failed_pc=0x0c081e06u; return 0; }
r[4]=r[12];
goto P_0c081e08;
P_0c081e08: /* original 7f04, guest PC 0x0c081e08 */
if(!s->budget--) { s->failed_pc=0x0c081e08u; return 0; }
r[15]+=0x00000004u;
goto P_0c081e0a;
P_0c081e0a: /* original 9225, guest PC 0x0c081e0a */
if(!s->budget--) { s->failed_pc=0x0c081e0au; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c081e58u,2);
goto P_0c081e0c;
P_0c081e0c: /* original 3d20, guest PC 0x0c081e0c */
if(!s->budget--) { s->failed_pc=0x0c081e0cu; return 0; }
r[17]=(r[17]&~1u)|((r[13]==r[2])!=0);
goto P_0c081e0e;
P_0c081e0e: /* original 8b06, guest PC 0x0c081e0e */
if(!s->budget--) { s->failed_pc=0x0c081e0eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c081e1e; }
goto P_0c081e10;
P_0c081e10: /* original 66e3, guest PC 0x0c081e10 */
if(!s->budget--) { s->failed_pc=0x0c081e10u; return 0; }
r[6]=r[14];
goto P_0c081e12;
P_0c081e12: /* original 2fa6, guest PC 0x0c081e12 */
if(!s->budget--) { s->failed_pc=0x0c081e12u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c081e14;
P_0c081e14: /* original 9521, guest PC 0x0c081e14 */
if(!s->budget--) { s->failed_pc=0x0c081e14u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c081e5au,2);
goto P_0c081e16;
P_0c081e16: /* original e700, guest PC 0x0c081e16 */
if(!s->budget--) { s->failed_pc=0x0c081e16u; return 0; }
r[7]=0x00000000u;
goto P_0c081e18;
P_0c081e18: /* original 4b0b, guest PC 0x0c081e18 */
if(!s->budget--) { s->failed_pc=0x0c081e18u; return 0; }
target=r[11];
r[16]=code_base|0x0c081e1cu;
r[4]=r[12];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c081e1cu) { target=s->pc; goto dispatch; }
goto P_0c081e1c;
P_0c081e1a: /* original 64c3, guest PC 0x0c081e1a */
if(!s->budget--) { s->failed_pc=0x0c081e1au; return 0; }
r[4]=r[12];
goto P_0c081e1c;
P_0c081e1c: /* original 7f04, guest PC 0x0c081e1c */
if(!s->budget--) { s->failed_pc=0x0c081e1cu; return 0; }
r[15]+=0x00000004u;
goto P_0c081e1e;
P_0c081e1e: /* original 921d, guest PC 0x0c081e1e */
if(!s->budget--) { s->failed_pc=0x0c081e1eu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c081e5cu,2);
goto P_0c081e20;
P_0c081e20: /* original 3d20, guest PC 0x0c081e20 */
if(!s->budget--) { s->failed_pc=0x0c081e20u; return 0; }
r[17]=(r[17]&~1u)|((r[13]==r[2])!=0);
goto P_0c081e22;
P_0c081e22: /* original 8b06, guest PC 0x0c081e22 */
if(!s->budget--) { s->failed_pc=0x0c081e22u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c081e32; }
goto P_0c081e24;
P_0c081e24: /* original 66e3, guest PC 0x0c081e24 */
if(!s->budget--) { s->failed_pc=0x0c081e24u; return 0; }
r[6]=r[14];
goto P_0c081e26;
P_0c081e26: /* original 2fa6, guest PC 0x0c081e26 */
if(!s->budget--) { s->failed_pc=0x0c081e26u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c081e28;
P_0c081e28: /* original 9519, guest PC 0x0c081e28 */
if(!s->budget--) { s->failed_pc=0x0c081e28u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c081e5eu,2);
goto P_0c081e2a;
P_0c081e2a: /* original e700, guest PC 0x0c081e2a */
if(!s->budget--) { s->failed_pc=0x0c081e2au; return 0; }
r[7]=0x00000000u;
goto P_0c081e2c;
P_0c081e2c: /* original 4b0b, guest PC 0x0c081e2c */
if(!s->budget--) { s->failed_pc=0x0c081e2cu; return 0; }
target=r[11];
r[16]=code_base|0x0c081e30u;
r[4]=r[12];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c081e30u) { target=s->pc; goto dispatch; }
goto P_0c081e30;
P_0c081e2e: /* original 64c3, guest PC 0x0c081e2e */
if(!s->budget--) { s->failed_pc=0x0c081e2eu; return 0; }
r[4]=r[12];
goto P_0c081e30;
P_0c081e30: /* original 7f04, guest PC 0x0c081e30 */
if(!s->budget--) { s->failed_pc=0x0c081e30u; return 0; }
r[15]+=0x00000004u;
goto P_0c081e32;
P_0c081e32: /* original 4f26, guest PC 0x0c081e32 */
if(!s->budget--) { s->failed_pc=0x0c081e32u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c081e34;
P_0c081e34: /* original 6af6, guest PC 0x0c081e34 */
if(!s->budget--) { s->failed_pc=0x0c081e34u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c081e36;
P_0c081e36: /* original 6bf6, guest PC 0x0c081e36 */
if(!s->budget--) { s->failed_pc=0x0c081e36u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c081e38;
P_0c081e38: /* original 6cf6, guest PC 0x0c081e38 */
if(!s->budget--) { s->failed_pc=0x0c081e38u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c081e3a;
P_0c081e3a: /* original 6df6, guest PC 0x0c081e3a */
if(!s->budget--) { s->failed_pc=0x0c081e3au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c081e3c;
P_0c081e3c: /* original 000b, guest PC 0x0c081e3c */
if(!s->budget--) { s->failed_pc=0x0c081e3cu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c081e3e: /* original 6ef6, guest PC 0x0c081e3e */
if(!s->budget--) { s->failed_pc=0x0c081e3eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c081e40u,s,ram);
P_0c081e68: /* original 2fe6, guest PC 0x0c081e68 */
if(!s->budget--) { s->failed_pc=0x0c081e68u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c081e6a;
P_0c081e6a: /* original e307, guest PC 0x0c081e6a */
if(!s->budget--) { s->failed_pc=0x0c081e6au; return 0; }
r[3]=0x00000007u;
goto P_0c081e6c;
P_0c081e6c: /* original 2fd6, guest PC 0x0c081e6c */
if(!s->budget--) { s->failed_pc=0x0c081e6cu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c081e6e;
P_0c081e6e: /* original 453c, guest PC 0x0c081e6e */
if(!s->budget--) { s->failed_pc=0x0c081e6eu; return 0; }
r[5]=(r[3]&0x80000000u)?((r[3]&31u)?(uint32_t)((int32_t)r[5]>>((-r[3])&31u)):((int32_t)r[5]<0?0xffffffffu:0)):r[5]<<(r[3]&31u);
goto P_0c081e70;
P_0c081e70: /* original 2fc6, guest PC 0x0c081e70 */
if(!s->budget--) { s->failed_pc=0x0c081e70u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c081e72;
P_0c081e72: /* original 6c43, guest PC 0x0c081e72 */
if(!s->budget--) { s->failed_pc=0x0c081e72u; return 0; }
r[12]=r[4];
goto P_0c081e74;
P_0c081e74: /* original 2fb6, guest PC 0x0c081e74 */
if(!s->budget--) { s->failed_pc=0x0c081e74u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c081e76;
P_0c081e76: /* original 7c02, guest PC 0x0c081e76 */
if(!s->budget--) { s->failed_pc=0x0c081e76u; return 0; }
r[12]+=0x00000002u;
goto P_0c081e78;
P_0c081e78: /* original 2fa6, guest PC 0x0c081e78 */
if(!s->budget--) { s->failed_pc=0x0c081e78u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c081e7a;
P_0c081e7a: /* original 6d63, guest PC 0x0c081e7a */
if(!s->budget--) { s->failed_pc=0x0c081e7au; return 0; }
r[13]=r[6];
goto P_0c081e7c;
P_0c081e7c: /* original 4f22, guest PC 0x0c081e7c */
if(!s->budget--) { s->failed_pc=0x0c081e7cu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c081e7e;
P_0c081e7e: /* original db4a, guest PC 0x0c081e7e */
if(!s->budget--) { s->failed_pc=0x0c081e7eu; return 0; }
r[11]=read(ram,0x0c081fa8u,4);
goto P_0c081e80;
P_0c081e80: /* original 4c00, guest PC 0x0c081e80 */
if(!s->budget--) { s->failed_pc=0x0c081e80u; return 0; }
r[17]=(r[17]&~1u)|((r[12]>>31)!=0);
r[12]<<=1;
goto P_0c081e82;
P_0c081e82: /* original de48, guest PC 0x0c081e82 */
if(!s->budget--) { s->failed_pc=0x0c081e82u; return 0; }
r[14]=read(ram,0x0c081fa4u,4);
goto P_0c081e84;
P_0c081e84: /* original 2dd8, guest PC 0x0c081e84 */
if(!s->budget--) { s->failed_pc=0x0c081e84u; return 0; }
r[17]=(r[17]&~1u)|(((r[13]&r[13])==0)!=0);
goto P_0c081e86;
P_0c081e86: /* original 2c5b, guest PC 0x0c081e86 */
if(!s->budget--) { s->failed_pc=0x0c081e86u; return 0; }
r[12]|=r[5];
goto P_0c081e88;
P_0c081e88: /* original 8f07, guest PC 0x0c081e88 */
if(!s->budget--) { s->failed_pc=0x0c081e88u; return 0; }
cond=r[17]&1u;
r[10]=0x00000010u;
if(!cond) { goto P_0c081e9a; }
goto P_0c081e8c;
P_0c081e8a: /* original ea10, guest PC 0x0c081e8a */
if(!s->budget--) { s->failed_pc=0x0c081e8au; return 0; }
r[10]=0x00000010u;
goto P_0c081e8c;
P_0c081e8c: /* original 66e3, guest PC 0x0c081e8c */
if(!s->budget--) { s->failed_pc=0x0c081e8cu; return 0; }
r[6]=r[14];
goto P_0c081e8e;
P_0c081e8e: /* original 2fa6, guest PC 0x0c081e8e */
if(!s->budget--) { s->failed_pc=0x0c081e8eu; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c081e90;
P_0c081e90: /* original 9578, guest PC 0x0c081e90 */
if(!s->budget--) { s->failed_pc=0x0c081e90u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c081f84u,2);
goto P_0c081e92;
P_0c081e92: /* original e700, guest PC 0x0c081e92 */
if(!s->budget--) { s->failed_pc=0x0c081e92u; return 0; }
r[7]=0x00000000u;
goto P_0c081e94;
P_0c081e94: /* original 4b0b, guest PC 0x0c081e94 */
if(!s->budget--) { s->failed_pc=0x0c081e94u; return 0; }
target=r[11];
r[16]=code_base|0x0c081e98u;
r[4]=r[12];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c081e98u) { target=s->pc; goto dispatch; }
goto P_0c081e98;
P_0c081e96: /* original 64c3, guest PC 0x0c081e96 */
if(!s->budget--) { s->failed_pc=0x0c081e96u; return 0; }
r[4]=r[12];
goto P_0c081e98;
P_0c081e98: /* original 7f04, guest PC 0x0c081e98 */
if(!s->budget--) { s->failed_pc=0x0c081e98u; return 0; }
r[15]+=0x00000004u;
goto P_0c081e9a;
P_0c081e9a: /* original 60d3, guest PC 0x0c081e9a */
if(!s->budget--) { s->failed_pc=0x0c081e9au; return 0; }
r[0]=r[13];
goto P_0c081e9c;
P_0c081e9c: /* original 8801, guest PC 0x0c081e9c */
if(!s->budget--) { s->failed_pc=0x0c081e9cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c081e9e;
P_0c081e9e: /* original 8b06, guest PC 0x0c081e9e */
if(!s->budget--) { s->failed_pc=0x0c081e9eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c081eae; }
goto P_0c081ea0;
P_0c081ea0: /* original 66e3, guest PC 0x0c081ea0 */
if(!s->budget--) { s->failed_pc=0x0c081ea0u; return 0; }
r[6]=r[14];
goto P_0c081ea2;
P_0c081ea2: /* original 2fa6, guest PC 0x0c081ea2 */
if(!s->budget--) { s->failed_pc=0x0c081ea2u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c081ea4;
P_0c081ea4: /* original 956f, guest PC 0x0c081ea4 */
if(!s->budget--) { s->failed_pc=0x0c081ea4u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c081f86u,2);
goto P_0c081ea6;
P_0c081ea6: /* original e700, guest PC 0x0c081ea6 */
if(!s->budget--) { s->failed_pc=0x0c081ea6u; return 0; }
r[7]=0x00000000u;
goto P_0c081ea8;
P_0c081ea8: /* original 4b0b, guest PC 0x0c081ea8 */
if(!s->budget--) { s->failed_pc=0x0c081ea8u; return 0; }
target=r[11];
r[16]=code_base|0x0c081eacu;
r[4]=r[12];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c081eacu) { target=s->pc; goto dispatch; }
goto P_0c081eac;
P_0c081eaa: /* original 64c3, guest PC 0x0c081eaa */
if(!s->budget--) { s->failed_pc=0x0c081eaau; return 0; }
r[4]=r[12];
goto P_0c081eac;
P_0c081eac: /* original 7f04, guest PC 0x0c081eac */
if(!s->budget--) { s->failed_pc=0x0c081eacu; return 0; }
r[15]+=0x00000004u;
goto P_0c081eae;
P_0c081eae: /* original 60d3, guest PC 0x0c081eae */
if(!s->budget--) { s->failed_pc=0x0c081eaeu; return 0; }
r[0]=r[13];
goto P_0c081eb0;
P_0c081eb0: /* original 8802, guest PC 0x0c081eb0 */
if(!s->budget--) { s->failed_pc=0x0c081eb0u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c081eb2;
P_0c081eb2: /* original 8b06, guest PC 0x0c081eb2 */
if(!s->budget--) { s->failed_pc=0x0c081eb2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c081ec2; }
goto P_0c081eb4;
P_0c081eb4: /* original 66e3, guest PC 0x0c081eb4 */
if(!s->budget--) { s->failed_pc=0x0c081eb4u; return 0; }
r[6]=r[14];
goto P_0c081eb6;
P_0c081eb6: /* original 2fa6, guest PC 0x0c081eb6 */
if(!s->budget--) { s->failed_pc=0x0c081eb6u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c081eb8;
P_0c081eb8: /* original 9566, guest PC 0x0c081eb8 */
if(!s->budget--) { s->failed_pc=0x0c081eb8u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c081f88u,2);
goto P_0c081eba;
P_0c081eba: /* original e700, guest PC 0x0c081eba */
if(!s->budget--) { s->failed_pc=0x0c081ebau; return 0; }
r[7]=0x00000000u;
goto P_0c081ebc;
P_0c081ebc: /* original 4b0b, guest PC 0x0c081ebc */
if(!s->budget--) { s->failed_pc=0x0c081ebcu; return 0; }
target=r[11];
r[16]=code_base|0x0c081ec0u;
r[4]=r[12];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c081ec0u) { target=s->pc; goto dispatch; }
goto P_0c081ec0;
P_0c081ebe: /* original 64c3, guest PC 0x0c081ebe */
if(!s->budget--) { s->failed_pc=0x0c081ebeu; return 0; }
r[4]=r[12];
goto P_0c081ec0;
P_0c081ec0: /* original 7f04, guest PC 0x0c081ec0 */
if(!s->budget--) { s->failed_pc=0x0c081ec0u; return 0; }
r[15]+=0x00000004u;
goto P_0c081ec2;
P_0c081ec2: /* original 60d3, guest PC 0x0c081ec2 */
if(!s->budget--) { s->failed_pc=0x0c081ec2u; return 0; }
r[0]=r[13];
goto P_0c081ec4;
P_0c081ec4: /* original 8804, guest PC 0x0c081ec4 */
if(!s->budget--) { s->failed_pc=0x0c081ec4u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000004u)!=0);
goto P_0c081ec6;
P_0c081ec6: /* original 8b06, guest PC 0x0c081ec6 */
if(!s->budget--) { s->failed_pc=0x0c081ec6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c081ed6; }
goto P_0c081ec8;
P_0c081ec8: /* original 66e3, guest PC 0x0c081ec8 */
if(!s->budget--) { s->failed_pc=0x0c081ec8u; return 0; }
r[6]=r[14];
goto P_0c081eca;
P_0c081eca: /* original 2fa6, guest PC 0x0c081eca */
if(!s->budget--) { s->failed_pc=0x0c081ecau; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c081ecc;
P_0c081ecc: /* original 955d, guest PC 0x0c081ecc */
if(!s->budget--) { s->failed_pc=0x0c081eccu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c081f8au,2);
goto P_0c081ece;
P_0c081ece: /* original e700, guest PC 0x0c081ece */
if(!s->budget--) { s->failed_pc=0x0c081eceu; return 0; }
r[7]=0x00000000u;
goto P_0c081ed0;
P_0c081ed0: /* original 4b0b, guest PC 0x0c081ed0 */
if(!s->budget--) { s->failed_pc=0x0c081ed0u; return 0; }
target=r[11];
r[16]=code_base|0x0c081ed4u;
r[4]=r[12];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c081ed4u) { target=s->pc; goto dispatch; }
goto P_0c081ed4;
P_0c081ed2: /* original 64c3, guest PC 0x0c081ed2 */
if(!s->budget--) { s->failed_pc=0x0c081ed2u; return 0; }
r[4]=r[12];
goto P_0c081ed4;
P_0c081ed4: /* original 7f04, guest PC 0x0c081ed4 */
if(!s->budget--) { s->failed_pc=0x0c081ed4u; return 0; }
r[15]+=0x00000004u;
goto P_0c081ed6;
P_0c081ed6: /* original 60d3, guest PC 0x0c081ed6 */
if(!s->budget--) { s->failed_pc=0x0c081ed6u; return 0; }
r[0]=r[13];
goto P_0c081ed8;
P_0c081ed8: /* original 8808, guest PC 0x0c081ed8 */
if(!s->budget--) { s->failed_pc=0x0c081ed8u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000008u)!=0);
goto P_0c081eda;
P_0c081eda: /* original 8b06, guest PC 0x0c081eda */
if(!s->budget--) { s->failed_pc=0x0c081edau; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c081eea; }
goto P_0c081edc;
P_0c081edc: /* original 66e3, guest PC 0x0c081edc */
if(!s->budget--) { s->failed_pc=0x0c081edcu; return 0; }
r[6]=r[14];
goto P_0c081ede;
P_0c081ede: /* original 2fa6, guest PC 0x0c081ede */
if(!s->budget--) { s->failed_pc=0x0c081edeu; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c081ee0;
P_0c081ee0: /* original 9554, guest PC 0x0c081ee0 */
if(!s->budget--) { s->failed_pc=0x0c081ee0u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c081f8cu,2);
goto P_0c081ee2;
P_0c081ee2: /* original e700, guest PC 0x0c081ee2 */
if(!s->budget--) { s->failed_pc=0x0c081ee2u; return 0; }
r[7]=0x00000000u;
goto P_0c081ee4;
P_0c081ee4: /* original 4b0b, guest PC 0x0c081ee4 */
if(!s->budget--) { s->failed_pc=0x0c081ee4u; return 0; }
target=r[11];
r[16]=code_base|0x0c081ee8u;
r[4]=r[12];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c081ee8u) { target=s->pc; goto dispatch; }
goto P_0c081ee8;
P_0c081ee6: /* original 64c3, guest PC 0x0c081ee6 */
if(!s->budget--) { s->failed_pc=0x0c081ee6u; return 0; }
r[4]=r[12];
goto P_0c081ee8;
P_0c081ee8: /* original 7f04, guest PC 0x0c081ee8 */
if(!s->budget--) { s->failed_pc=0x0c081ee8u; return 0; }
r[15]+=0x00000004u;
goto P_0c081eea;
P_0c081eea: /* original 60d3, guest PC 0x0c081eea */
if(!s->budget--) { s->failed_pc=0x0c081eeau; return 0; }
r[0]=r[13];
goto P_0c081eec;
P_0c081eec: /* original 8810, guest PC 0x0c081eec */
if(!s->budget--) { s->failed_pc=0x0c081eecu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000010u)!=0);
goto P_0c081eee;
P_0c081eee: /* original 8b06, guest PC 0x0c081eee */
if(!s->budget--) { s->failed_pc=0x0c081eeeu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c081efe; }
goto P_0c081ef0;
P_0c081ef0: /* original 66e3, guest PC 0x0c081ef0 */
if(!s->budget--) { s->failed_pc=0x0c081ef0u; return 0; }
r[6]=r[14];
goto P_0c081ef2;
P_0c081ef2: /* original 2fa6, guest PC 0x0c081ef2 */
if(!s->budget--) { s->failed_pc=0x0c081ef2u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c081ef4;
P_0c081ef4: /* original 954b, guest PC 0x0c081ef4 */
if(!s->budget--) { s->failed_pc=0x0c081ef4u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c081f8eu,2);
goto P_0c081ef6;
P_0c081ef6: /* original e700, guest PC 0x0c081ef6 */
if(!s->budget--) { s->failed_pc=0x0c081ef6u; return 0; }
r[7]=0x00000000u;
goto P_0c081ef8;
P_0c081ef8: /* original 4b0b, guest PC 0x0c081ef8 */
if(!s->budget--) { s->failed_pc=0x0c081ef8u; return 0; }
target=r[11];
r[16]=code_base|0x0c081efcu;
r[4]=r[12];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c081efcu) { target=s->pc; goto dispatch; }
goto P_0c081efc;
P_0c081efa: /* original 64c3, guest PC 0x0c081efa */
if(!s->budget--) { s->failed_pc=0x0c081efau; return 0; }
r[4]=r[12];
goto P_0c081efc;
P_0c081efc: /* original 7f04, guest PC 0x0c081efc */
if(!s->budget--) { s->failed_pc=0x0c081efcu; return 0; }
r[15]+=0x00000004u;
goto P_0c081efe;
P_0c081efe: /* original 60d3, guest PC 0x0c081efe */
if(!s->budget--) { s->failed_pc=0x0c081efeu; return 0; }
r[0]=r[13];
goto P_0c081f00;
P_0c081f00: /* original 8820, guest PC 0x0c081f00 */
if(!s->budget--) { s->failed_pc=0x0c081f00u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000020u)!=0);
goto P_0c081f02;
P_0c081f02: /* original 8b06, guest PC 0x0c081f02 */
if(!s->budget--) { s->failed_pc=0x0c081f02u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c081f12; }
goto P_0c081f04;
P_0c081f04: /* original 66e3, guest PC 0x0c081f04 */
if(!s->budget--) { s->failed_pc=0x0c081f04u; return 0; }
r[6]=r[14];
goto P_0c081f06;
P_0c081f06: /* original 2fa6, guest PC 0x0c081f06 */
if(!s->budget--) { s->failed_pc=0x0c081f06u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c081f08;
P_0c081f08: /* original 9542, guest PC 0x0c081f08 */
if(!s->budget--) { s->failed_pc=0x0c081f08u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c081f90u,2);
goto P_0c081f0a;
P_0c081f0a: /* original e700, guest PC 0x0c081f0a */
if(!s->budget--) { s->failed_pc=0x0c081f0au; return 0; }
r[7]=0x00000000u;
goto P_0c081f0c;
P_0c081f0c: /* original 4b0b, guest PC 0x0c081f0c */
if(!s->budget--) { s->failed_pc=0x0c081f0cu; return 0; }
target=r[11];
r[16]=code_base|0x0c081f10u;
r[4]=r[12];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c081f10u) { target=s->pc; goto dispatch; }
goto P_0c081f10;
P_0c081f0e: /* original 64c3, guest PC 0x0c081f0e */
if(!s->budget--) { s->failed_pc=0x0c081f0eu; return 0; }
r[4]=r[12];
goto P_0c081f10;
P_0c081f10: /* original 7f04, guest PC 0x0c081f10 */
if(!s->budget--) { s->failed_pc=0x0c081f10u; return 0; }
r[15]+=0x00000004u;
goto P_0c081f12;
P_0c081f12: /* original 60d3, guest PC 0x0c081f12 */
if(!s->budget--) { s->failed_pc=0x0c081f12u; return 0; }
r[0]=r[13];
goto P_0c081f14;
P_0c081f14: /* original 8840, guest PC 0x0c081f14 */
if(!s->budget--) { s->failed_pc=0x0c081f14u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000040u)!=0);
goto P_0c081f16;
P_0c081f16: /* original 8b06, guest PC 0x0c081f16 */
if(!s->budget--) { s->failed_pc=0x0c081f16u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c081f26; }
goto P_0c081f18;
P_0c081f18: /* original 66e3, guest PC 0x0c081f18 */
if(!s->budget--) { s->failed_pc=0x0c081f18u; return 0; }
r[6]=r[14];
goto P_0c081f1a;
P_0c081f1a: /* original 2fa6, guest PC 0x0c081f1a */
if(!s->budget--) { s->failed_pc=0x0c081f1au; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c081f1c;
P_0c081f1c: /* original 9539, guest PC 0x0c081f1c */
if(!s->budget--) { s->failed_pc=0x0c081f1cu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c081f92u,2);
goto P_0c081f1e;
P_0c081f1e: /* original e700, guest PC 0x0c081f1e */
if(!s->budget--) { s->failed_pc=0x0c081f1eu; return 0; }
r[7]=0x00000000u;
goto P_0c081f20;
P_0c081f20: /* original 4b0b, guest PC 0x0c081f20 */
if(!s->budget--) { s->failed_pc=0x0c081f20u; return 0; }
target=r[11];
r[16]=code_base|0x0c081f24u;
r[4]=r[12];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c081f24u) { target=s->pc; goto dispatch; }
goto P_0c081f24;
P_0c081f22: /* original 64c3, guest PC 0x0c081f22 */
if(!s->budget--) { s->failed_pc=0x0c081f22u; return 0; }
r[4]=r[12];
goto P_0c081f24;
P_0c081f24: /* original 7f04, guest PC 0x0c081f24 */
if(!s->budget--) { s->failed_pc=0x0c081f24u; return 0; }
r[15]+=0x00000004u;
goto P_0c081f26;
P_0c081f26: /* original 9235, guest PC 0x0c081f26 */
if(!s->budget--) { s->failed_pc=0x0c081f26u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c081f94u,2);
goto P_0c081f28;
P_0c081f28: /* original 3d20, guest PC 0x0c081f28 */
if(!s->budget--) { s->failed_pc=0x0c081f28u; return 0; }
r[17]=(r[17]&~1u)|((r[13]==r[2])!=0);
goto P_0c081f2a;
P_0c081f2a: /* original 8b06, guest PC 0x0c081f2a */
if(!s->budget--) { s->failed_pc=0x0c081f2au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c081f3a; }
goto P_0c081f2c;
P_0c081f2c: /* original 66e3, guest PC 0x0c081f2c */
if(!s->budget--) { s->failed_pc=0x0c081f2cu; return 0; }
r[6]=r[14];
goto P_0c081f2e;
P_0c081f2e: /* original 2fa6, guest PC 0x0c081f2e */
if(!s->budget--) { s->failed_pc=0x0c081f2eu; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c081f30;
P_0c081f30: /* original 9531, guest PC 0x0c081f30 */
if(!s->budget--) { s->failed_pc=0x0c081f30u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c081f96u,2);
goto P_0c081f32;
P_0c081f32: /* original e700, guest PC 0x0c081f32 */
if(!s->budget--) { s->failed_pc=0x0c081f32u; return 0; }
r[7]=0x00000000u;
goto P_0c081f34;
P_0c081f34: /* original 4b0b, guest PC 0x0c081f34 */
if(!s->budget--) { s->failed_pc=0x0c081f34u; return 0; }
target=r[11];
r[16]=code_base|0x0c081f38u;
r[4]=r[12];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c081f38u) { target=s->pc; goto dispatch; }
goto P_0c081f38;
P_0c081f36: /* original 64c3, guest PC 0x0c081f36 */
if(!s->budget--) { s->failed_pc=0x0c081f36u; return 0; }
r[4]=r[12];
goto P_0c081f38;
P_0c081f38: /* original 7f04, guest PC 0x0c081f38 */
if(!s->budget--) { s->failed_pc=0x0c081f38u; return 0; }
r[15]+=0x00000004u;
goto P_0c081f3a;
P_0c081f3a: /* original 922d, guest PC 0x0c081f3a */
if(!s->budget--) { s->failed_pc=0x0c081f3au; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c081f98u,2);
goto P_0c081f3c;
P_0c081f3c: /* original 3d20, guest PC 0x0c081f3c */
if(!s->budget--) { s->failed_pc=0x0c081f3cu; return 0; }
r[17]=(r[17]&~1u)|((r[13]==r[2])!=0);
goto P_0c081f3e;
P_0c081f3e: /* original 8b06, guest PC 0x0c081f3e */
if(!s->budget--) { s->failed_pc=0x0c081f3eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c081f4e; }
goto P_0c081f40;
P_0c081f40: /* original 66e3, guest PC 0x0c081f40 */
if(!s->budget--) { s->failed_pc=0x0c081f40u; return 0; }
r[6]=r[14];
goto P_0c081f42;
P_0c081f42: /* original 2fa6, guest PC 0x0c081f42 */
if(!s->budget--) { s->failed_pc=0x0c081f42u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c081f44;
P_0c081f44: /* original 9529, guest PC 0x0c081f44 */
if(!s->budget--) { s->failed_pc=0x0c081f44u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c081f9au,2);
goto P_0c081f46;
P_0c081f46: /* original e700, guest PC 0x0c081f46 */
if(!s->budget--) { s->failed_pc=0x0c081f46u; return 0; }
r[7]=0x00000000u;
goto P_0c081f48;
P_0c081f48: /* original 4b0b, guest PC 0x0c081f48 */
if(!s->budget--) { s->failed_pc=0x0c081f48u; return 0; }
target=r[11];
r[16]=code_base|0x0c081f4cu;
r[4]=r[12];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c081f4cu) { target=s->pc; goto dispatch; }
goto P_0c081f4c;
P_0c081f4a: /* original 64c3, guest PC 0x0c081f4a */
if(!s->budget--) { s->failed_pc=0x0c081f4au; return 0; }
r[4]=r[12];
goto P_0c081f4c;
P_0c081f4c: /* original 7f04, guest PC 0x0c081f4c */
if(!s->budget--) { s->failed_pc=0x0c081f4cu; return 0; }
r[15]+=0x00000004u;
goto P_0c081f4e;
P_0c081f4e: /* original 9225, guest PC 0x0c081f4e */
if(!s->budget--) { s->failed_pc=0x0c081f4eu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c081f9cu,2);
goto P_0c081f50;
P_0c081f50: /* original 3d20, guest PC 0x0c081f50 */
if(!s->budget--) { s->failed_pc=0x0c081f50u; return 0; }
r[17]=(r[17]&~1u)|((r[13]==r[2])!=0);
goto P_0c081f52;
P_0c081f52: /* original 8b06, guest PC 0x0c081f52 */
if(!s->budget--) { s->failed_pc=0x0c081f52u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c081f62; }
goto P_0c081f54;
P_0c081f54: /* original 66e3, guest PC 0x0c081f54 */
if(!s->budget--) { s->failed_pc=0x0c081f54u; return 0; }
r[6]=r[14];
goto P_0c081f56;
P_0c081f56: /* original 2fa6, guest PC 0x0c081f56 */
if(!s->budget--) { s->failed_pc=0x0c081f56u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c081f58;
P_0c081f58: /* original 9521, guest PC 0x0c081f58 */
if(!s->budget--) { s->failed_pc=0x0c081f58u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c081f9eu,2);
goto P_0c081f5a;
P_0c081f5a: /* original e700, guest PC 0x0c081f5a */
if(!s->budget--) { s->failed_pc=0x0c081f5au; return 0; }
r[7]=0x00000000u;
goto P_0c081f5c;
P_0c081f5c: /* original 4b0b, guest PC 0x0c081f5c */
if(!s->budget--) { s->failed_pc=0x0c081f5cu; return 0; }
target=r[11];
r[16]=code_base|0x0c081f60u;
r[4]=r[12];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c081f60u) { target=s->pc; goto dispatch; }
goto P_0c081f60;
P_0c081f5e: /* original 64c3, guest PC 0x0c081f5e */
if(!s->budget--) { s->failed_pc=0x0c081f5eu; return 0; }
r[4]=r[12];
goto P_0c081f60;
P_0c081f60: /* original 7f04, guest PC 0x0c081f60 */
if(!s->budget--) { s->failed_pc=0x0c081f60u; return 0; }
r[15]+=0x00000004u;
goto P_0c081f62;
P_0c081f62: /* original 921d, guest PC 0x0c081f62 */
if(!s->budget--) { s->failed_pc=0x0c081f62u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c081fa0u,2);
goto P_0c081f64;
P_0c081f64: /* original 3d20, guest PC 0x0c081f64 */
if(!s->budget--) { s->failed_pc=0x0c081f64u; return 0; }
r[17]=(r[17]&~1u)|((r[13]==r[2])!=0);
goto P_0c081f66;
P_0c081f66: /* original 8b06, guest PC 0x0c081f66 */
if(!s->budget--) { s->failed_pc=0x0c081f66u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c081f76; }
goto P_0c081f68;
P_0c081f68: /* original 66e3, guest PC 0x0c081f68 */
if(!s->budget--) { s->failed_pc=0x0c081f68u; return 0; }
r[6]=r[14];
goto P_0c081f6a;
P_0c081f6a: /* original 2fa6, guest PC 0x0c081f6a */
if(!s->budget--) { s->failed_pc=0x0c081f6au; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c081f6c;
P_0c081f6c: /* original 9519, guest PC 0x0c081f6c */
if(!s->budget--) { s->failed_pc=0x0c081f6cu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c081fa2u,2);
goto P_0c081f6e;
P_0c081f6e: /* original e700, guest PC 0x0c081f6e */
if(!s->budget--) { s->failed_pc=0x0c081f6eu; return 0; }
r[7]=0x00000000u;
goto P_0c081f70;
P_0c081f70: /* original 4b0b, guest PC 0x0c081f70 */
if(!s->budget--) { s->failed_pc=0x0c081f70u; return 0; }
target=r[11];
r[16]=code_base|0x0c081f74u;
r[4]=r[12];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c081f74u) { target=s->pc; goto dispatch; }
goto P_0c081f74;
P_0c081f72: /* original 64c3, guest PC 0x0c081f72 */
if(!s->budget--) { s->failed_pc=0x0c081f72u; return 0; }
r[4]=r[12];
goto P_0c081f74;
P_0c081f74: /* original 7f04, guest PC 0x0c081f74 */
if(!s->budget--) { s->failed_pc=0x0c081f74u; return 0; }
r[15]+=0x00000004u;
goto P_0c081f76;
P_0c081f76: /* original 4f26, guest PC 0x0c081f76 */
if(!s->budget--) { s->failed_pc=0x0c081f76u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c081f78;
P_0c081f78: /* original 6af6, guest PC 0x0c081f78 */
if(!s->budget--) { s->failed_pc=0x0c081f78u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c081f7a;
P_0c081f7a: /* original 6bf6, guest PC 0x0c081f7a */
if(!s->budget--) { s->failed_pc=0x0c081f7au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c081f7c;
P_0c081f7c: /* original 6cf6, guest PC 0x0c081f7c */
if(!s->budget--) { s->failed_pc=0x0c081f7cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c081f7e;
P_0c081f7e: /* original 6df6, guest PC 0x0c081f7e */
if(!s->budget--) { s->failed_pc=0x0c081f7eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c081f80;
P_0c081f80: /* original 000b, guest PC 0x0c081f80 */
if(!s->budget--) { s->failed_pc=0x0c081f80u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c081f82: /* original 6ef6, guest PC 0x0c081f82 */
if(!s->budget--) { s->failed_pc=0x0c081f82u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c081f84u,s,ram);
P_0c0831f8: /* original 4f22, guest PC 0x0c0831f8 */
if(!s->budget--) { s->failed_pc=0x0c0831f8u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0831fa;
P_0c0831fa: /* original 9b2b, guest PC 0x0c0831fa */
if(!s->budget--) { s->failed_pc=0x0c0831fau; return 0; }
r[11]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c083254u,2);
goto P_0c0831fc;
P_0c0831fc: /* original 7fec, guest PC 0x0c0831fc */
if(!s->budget--) { s->failed_pc=0x0c0831fcu; return 0; }
r[15]+=0xffffffecu;
goto P_0c0831fe;
P_0c0831fe: /* original 1f43, guest PC 0x0c0831fe */
if(!s->budget--) { s->failed_pc=0x0c0831feu; return 0; }
write(ram,r[15]+12,r[4],4);
goto P_0c083200;
P_0c083200: /* original 1f54, guest PC 0x0c083200 */
if(!s->budget--) { s->failed_pc=0x0c083200u; return 0; }
write(ram,r[15]+16,r[5],4);
goto P_0c083202;
P_0c083202: /* original dd1a, guest PC 0x0c083202 */
if(!s->budget--) { s->failed_pc=0x0c083202u; return 0; }
r[13]=read(ram,0x0c08326cu,4);
goto P_0c083204;
P_0c083204: /* original de18, guest PC 0x0c083204 */
if(!s->budget--) { s->failed_pc=0x0c083204u; return 0; }
r[14]=read(ram,0x0c083268u,4);
goto P_0c083206;
P_0c083206: /* original d31a, guest PC 0x0c083206 */
if(!s->budget--) { s->failed_pc=0x0c083206u; return 0; }
r[3]=read(ram,0x0c083270u,4);
goto P_0c083208;
P_0c083208: /* original 430b, guest PC 0x0c083208 */
if(!s->budget--) { s->failed_pc=0x0c083208u; return 0; }
target=r[3];
r[16]=code_base|0x0c08320cu;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08320cu) { target=s->pc; goto dispatch; }
goto P_0c08320c;
P_0c08320a: /* original 64d3, guest PC 0x0c08320a */
if(!s->budget--) { s->failed_pc=0x0c08320au; return 0; }
r[4]=r[13];
goto P_0c08320c;
P_0c08320c: /* original d213, guest PC 0x0c08320c */
if(!s->budget--) { s->failed_pc=0x0c08320cu; return 0; }
r[2]=read(ram,0x0c08325cu,4);
goto P_0c08320e;
P_0c08320e: /* original e502, guest PC 0x0c08320e */
if(!s->budget--) { s->failed_pc=0x0c08320eu; return 0; }
r[5]=0x00000002u;
goto P_0c083210;
P_0c083210: /* original 9621, guest PC 0x0c083210 */
if(!s->budget--) { s->failed_pc=0x0c083210u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c083256u,2);
goto P_0c083212;
P_0c083212: /* original 420b, guest PC 0x0c083212 */
if(!s->budget--) { s->failed_pc=0x0c083212u; return 0; }
target=r[2];
r[16]=code_base|0x0c083216u;
r[4]=0x00000016u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c083216u) { target=s->pc; goto dispatch; }
goto P_0c083216;
P_0c083214: /* original e416, guest PC 0x0c083214 */
if(!s->budget--) { s->failed_pc=0x0c083214u; return 0; }
r[4]=0x00000016u;
goto P_0c083216;
P_0c083216: /* original a42d, guest PC 0x0c083216 */
if(!s->budget--) { s->failed_pc=0x0c083216u; return 0; }
r[10]=0x00000000u;
goto P_0c083a74;
P_0c083218: /* original ea00, guest PC 0x0c083218 */
if(!s->budget--) { s->failed_pc=0x0c083218u; return 0; }
r[10]=0x00000000u;
goto P_0c08321a;
P_0c08321a: /* original dc16, guest PC 0x0c08321a */
if(!s->budget--) { s->failed_pc=0x0c08321au; return 0; }
r[12]=read(ram,0x0c083274u,4);
goto P_0c08321c;
P_0c08321c: /* original 4c0b, guest PC 0x0c08321c */
if(!s->budget--) { s->failed_pc=0x0c08321cu; return 0; }
target=r[12];
r[16]=code_base|0x0c083220u;
r[4]=r[10];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c083220u) { target=s->pc; goto dispatch; }
goto P_0c083220;
P_0c08321e: /* original 64a3, guest PC 0x0c08321e */
if(!s->budget--) { s->failed_pc=0x0c08321eu; return 0; }
r[4]=r[10];
goto P_0c083220;
P_0c083220: /* original 68a3, guest PC 0x0c083220 */
if(!s->budget--) { s->failed_pc=0x0c083220u; return 0; }
r[8]=r[10];
goto P_0c083222;
P_0c083222: /* original 4808, guest PC 0x0c083222 */
if(!s->budget--) { s->failed_pc=0x0c083222u; return 0; }
r[8]<<=2;
goto P_0c083224;
P_0c083224: /* original 63a3, guest PC 0x0c083224 */
if(!s->budget--) { s->failed_pc=0x0c083224u; return 0; }
r[3]=r[10];
goto P_0c083226;
P_0c083226: /* original 383c, guest PC 0x0c083226 */
if(!s->budget--) { s->failed_pc=0x0c083226u; return 0; }
r[8]+=r[3];
goto P_0c083228;
P_0c083228: /* original 6903, guest PC 0x0c083228 */
if(!s->budget--) { s->failed_pc=0x0c083228u; return 0; }
r[9]=r[0];
goto P_0c08322a;
P_0c08322a: /* original 6392, guest PC 0x0c08322a */
if(!s->budget--) { s->failed_pc=0x0c08322au; return 0; }
tmp=read(ram,r[9],4);
r[3]=tmp;
goto P_0c08322c;
P_0c08322c: /* original d212, guest PC 0x0c08322c */
if(!s->budget--) { s->failed_pc=0x0c08322cu; return 0; }
r[2]=read(ram,0x0c083278u,4);
goto P_0c08322e;
P_0c08322e: /* original 4808, guest PC 0x0c08322e */
if(!s->budget--) { s->failed_pc=0x0c08322eu; return 0; }
r[8]<<=2;
goto P_0c083230;
P_0c083230: /* original 6c83, guest PC 0x0c083230 */
if(!s->budget--) { s->failed_pc=0x0c083230u; return 0; }
r[12]=r[8];
goto P_0c083232;
P_0c083232: /* original 3320, guest PC 0x0c083232 */
if(!s->budget--) { s->failed_pc=0x0c083232u; return 0; }
r[17]=(r[17]&~1u)|((r[3]==r[2])!=0);
goto P_0c083234;
P_0c083234: /* original 8f22, guest PC 0x0c083234 */
if(!s->budget--) { s->failed_pc=0x0c083234u; return 0; }
cond=r[17]&1u;
r[12]+=0x00000007u;
if(!cond) { goto P_0c08327c; }
goto P_0c083238;
P_0c083236: /* original 7c07, guest PC 0x0c083236 */
if(!s->budget--) { s->failed_pc=0x0c083236u; return 0; }
r[12]+=0x00000007u;
goto P_0c083238;
P_0c083238: /* original d308, guest PC 0x0c083238 */
if(!s->budget--) { s->failed_pc=0x0c083238u; return 0; }
r[3]=read(ram,0x0c08325cu,4);
goto P_0c08323a;
P_0c08323a: /* original 65c3, guest PC 0x0c08323a */
if(!s->budget--) { s->failed_pc=0x0c08323au; return 0; }
r[5]=r[12];
goto P_0c08323c;
P_0c08323c: /* original 960c, guest PC 0x0c08323c */
if(!s->budget--) { s->failed_pc=0x0c08323cu; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c083258u,2);
goto P_0c08323e;
P_0c08323e: /* original 430b, guest PC 0x0c08323e */
if(!s->budget--) { s->failed_pc=0x0c08323eu; return 0; }
target=r[3];
r[16]=code_base|0x0c083242u;
r[4]=0x0000001du;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c083242u) { target=s->pc; goto dispatch; }
goto P_0c083242;
P_0c083240: /* original e41d, guest PC 0x0c083240 */
if(!s->budget--) { s->failed_pc=0x0c083240u; return 0; }
r[4]=0x0000001du;
goto P_0c083242;
P_0c083242: /* original a022, guest PC 0x0c083242 */
if(!s->budget--) { s->failed_pc=0x0c083242u; return 0; }
goto P_0c08328a;
P_0c083244: /* original 0009, guest PC 0x0c083244 */
if(!s->budget--) { s->failed_pc=0x0c083244u; return 0; }
return vf3_matrix_family(0x0c083246u,s,ram);
P_0c08327c: /* original 33b0, guest PC 0x0c08327c */
if(!s->budget--) { s->failed_pc=0x0c08327cu; return 0; }
r[17]=(r[17]&~1u)|((r[3]==r[11])!=0);
goto P_0c08327e;
P_0c08327e: /* original 8b04, guest PC 0x0c08327e */
if(!s->budget--) { s->failed_pc=0x0c08327eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c08328a; }
goto P_0c083280;
P_0c083280: /* original d33e, guest PC 0x0c083280 */
if(!s->budget--) { s->failed_pc=0x0c083280u; return 0; }
r[3]=read(ram,0x0c08337cu,4);
goto P_0c083282;
P_0c083282: /* original 65c3, guest PC 0x0c083282 */
if(!s->budget--) { s->failed_pc=0x0c083282u; return 0; }
r[5]=r[12];
goto P_0c083284;
P_0c083284: /* original 966f, guest PC 0x0c083284 */
if(!s->budget--) { s->failed_pc=0x0c083284u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c083366u,2);
goto P_0c083286;
P_0c083286: /* original 430b, guest PC 0x0c083286 */
if(!s->budget--) { s->failed_pc=0x0c083286u; return 0; }
target=r[3];
r[16]=code_base|0x0c08328au;
r[4]=0x00000021u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08328au) { target=s->pc; goto dispatch; }
goto P_0c08328a;
P_0c083288: /* original e421, guest PC 0x0c083288 */
if(!s->budget--) { s->failed_pc=0x0c083288u; return 0; }
r[4]=0x00000021u;
goto P_0c08328a;
P_0c08328a: /* original d53d, guest PC 0x0c08328a */
if(!s->budget--) { s->failed_pc=0x0c08328au; return 0; }
r[5]=read(ram,0x0c083380u,4);
goto P_0c08328c;
P_0c08328c: /* original e408, guest PC 0x0c08328c */
if(!s->budget--) { s->failed_pc=0x0c08328cu; return 0; }
r[4]=0x00000008u;
goto P_0c08328e;
P_0c08328e: /* original 63a3, guest PC 0x0c08328e */
if(!s->budget--) { s->failed_pc=0x0c08328eu; return 0; }
r[3]=r[10];
goto P_0c083290;
P_0c083290: /* original 4308, guest PC 0x0c083290 */
if(!s->budget--) { s->failed_pc=0x0c083290u; return 0; }
r[3]<<=2;
goto P_0c083292;
P_0c083292: /* original 6252, guest PC 0x0c083292 */
if(!s->budget--) { s->failed_pc=0x0c083292u; return 0; }
tmp=read(ram,r[5],4);
r[2]=tmp;
goto P_0c083294;
P_0c083294: /* original e501, guest PC 0x0c083294 */
if(!s->budget--) { s->failed_pc=0x0c083294u; return 0; }
r[5]=0x00000001u;
goto P_0c083296;
P_0c083296: /* original 2249, guest PC 0x0c083296 */
if(!s->budget--) { s->failed_pc=0x0c083296u; return 0; }
r[2]&=r[4];
goto P_0c083298;
P_0c083298: /* original 1f22, guest PC 0x0c083298 */
if(!s->budget--) { s->failed_pc=0x0c083298u; return 0; }
write(ram,r[15]+8,r[2],4);
goto P_0c08329a;
P_0c08329a: /* original 2f32, guest PC 0x0c08329a */
if(!s->budget--) { s->failed_pc=0x0c08329au; return 0; }
write(ram,r[15],r[3],4);
goto P_0c08329c;
P_0c08329c: /* original 9264, guest PC 0x0c08329c */
if(!s->budget--) { s->failed_pc=0x0c08329cu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c083368u,2);
goto P_0c08329e;
P_0c08329e: /* original 32ec, guest PC 0x0c08329e */
if(!s->budget--) { s->failed_pc=0x0c08329eu; return 0; }
r[2]+=r[14];
goto P_0c0832a0;
P_0c0832a0: /* original 332c, guest PC 0x0c0832a0 */
if(!s->budget--) { s->failed_pc=0x0c0832a0u; return 0; }
r[3]+=r[2];
goto P_0c0832a2;
P_0c0832a2: /* original 62d3, guest PC 0x0c0832a2 */
if(!s->budget--) { s->failed_pc=0x0c0832a2u; return 0; }
r[2]=r[13];
goto P_0c0832a4;
P_0c0832a4: /* original 6132, guest PC 0x0c0832a4 */
if(!s->budget--) { s->failed_pc=0x0c0832a4u; return 0; }
tmp=read(ram,r[3],4);
r[1]=tmp;
goto P_0c0832a6;
P_0c0832a6: /* original e307, guest PC 0x0c0832a6 */
if(!s->budget--) { s->failed_pc=0x0c0832a6u; return 0; }
r[3]=0x00000007u;
goto P_0c0832a8;
P_0c0832a8: /* original 423c, guest PC 0x0c0832a8 */
if(!s->budget--) { s->failed_pc=0x0c0832a8u; return 0; }
r[2]=(r[3]&0x80000000u)?((r[3]&31u)?(uint32_t)((int32_t)r[2]>>((-r[3])&31u)):((int32_t)r[2]<0?0xffffffffu:0)):r[2]<<(r[3]&31u);
goto P_0c0832aa;
P_0c0832aa: /* original 2159, guest PC 0x0c0832aa */
if(!s->budget--) { s->failed_pc=0x0c0832aau; return 0; }
r[1]&=r[5];
goto P_0c0832ac;
P_0c0832ac: /* original 65c3, guest PC 0x0c0832ac */
if(!s->budget--) { s->failed_pc=0x0c0832acu; return 0; }
r[5]=r[12];
goto P_0c0832ae;
P_0c0832ae: /* original 1f11, guest PC 0x0c0832ae */
if(!s->budget--) { s->failed_pc=0x0c0832aeu; return 0; }
write(ram,r[15]+4,r[1],4);
goto P_0c0832b0;
P_0c0832b0: /* original 224b, guest PC 0x0c0832b0 */
if(!s->budget--) { s->failed_pc=0x0c0832b0u; return 0; }
r[2]|=r[4];
goto P_0c0832b2;
P_0c0832b2: /* original 1f24, guest PC 0x0c0832b2 */
if(!s->budget--) { s->failed_pc=0x0c0832b2u; return 0; }
write(ram,r[15]+16,r[2],4);
goto P_0c0832b4;
P_0c0832b4: /* original 9659, guest PC 0x0c0832b4 */
if(!s->budget--) { s->failed_pc=0x0c0832b4u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08336au,2);
goto P_0c0832b6;
P_0c0832b6: /* original d131, guest PC 0x0c0832b6 */
if(!s->budget--) { s->failed_pc=0x0c0832b6u; return 0; }
r[1]=read(ram,0x0c08337cu,4);
goto P_0c0832b8;
P_0c0832b8: /* original 36ac, guest PC 0x0c0832b8 */
if(!s->budget--) { s->failed_pc=0x0c0832b8u; return 0; }
r[6]+=r[10];
goto P_0c0832ba;
P_0c0832ba: /* original 410b, guest PC 0x0c0832ba */
if(!s->budget--) { s->failed_pc=0x0c0832bau; return 0; }
target=r[1];
r[16]=code_base|0x0c0832beu;
r[4]=0x00000004u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0832beu) { target=s->pc; goto dispatch; }
goto P_0c0832be;
P_0c0832bc: /* original e404, guest PC 0x0c0832bc */
if(!s->budget--) { s->failed_pc=0x0c0832bcu; return 0; }
r[4]=0x00000004u;
goto P_0c0832be;
P_0c0832be: /* original 9053, guest PC 0x0c0832be */
if(!s->budget--) { s->failed_pc=0x0c0832beu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c083368u,2);
goto P_0c0832c0;
P_0c0832c0: /* original 63f2, guest PC 0x0c0832c0 */
if(!s->budget--) { s->failed_pc=0x0c0832c0u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c0832c2;
P_0c0832c2: /* original 30ec, guest PC 0x0c0832c2 */
if(!s->budget--) { s->failed_pc=0x0c0832c2u; return 0; }
r[0]+=r[14];
goto P_0c0832c4;
P_0c0832c4: /* original 003e, guest PC 0x0c0832c4 */
if(!s->budget--) { s->failed_pc=0x0c0832c4u; return 0; }
r[0]=read(ram,r[3]+r[0],4);
goto P_0c0832c6;
P_0c0832c6: /* original c804, guest PC 0x0c0832c6 */
if(!s->budget--) { s->failed_pc=0x0c0832c6u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&4u)==0)!=0);
goto P_0c0832c8;
P_0c0832c8: /* original 8907, guest PC 0x0c0832c8 */
if(!s->budget--) { s->failed_pc=0x0c0832c8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0832da; }
goto P_0c0832ca;
P_0c0832ca: /* original 994f, guest PC 0x0c0832ca */
if(!s->budget--) { s->failed_pc=0x0c0832cau; return 0; }
r[9]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08336cu,2);
goto P_0c0832cc;
P_0c0832cc: /* original 65c3, guest PC 0x0c0832cc */
if(!s->budget--) { s->failed_pc=0x0c0832ccu; return 0; }
r[5]=r[12];
goto P_0c0832ce;
P_0c0832ce: /* original d12b, guest PC 0x0c0832ce */
if(!s->budget--) { s->failed_pc=0x0c0832ceu; return 0; }
r[1]=read(ram,0x0c08337cu,4);
goto P_0c0832d0;
P_0c0832d0: /* original 6693, guest PC 0x0c0832d0 */
if(!s->budget--) { s->failed_pc=0x0c0832d0u; return 0; }
r[6]=r[9];
goto P_0c0832d2;
P_0c0832d2: /* original 410b, guest PC 0x0c0832d2 */
if(!s->budget--) { s->failed_pc=0x0c0832d2u; return 0; }
target=r[1];
r[16]=code_base|0x0c0832d6u;
r[4]=0x00000007u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0832d6u) { target=s->pc; goto dispatch; }
goto P_0c0832d6;
P_0c0832d4: /* original e407, guest PC 0x0c0832d4 */
if(!s->budget--) { s->failed_pc=0x0c0832d4u; return 0; }
r[4]=0x00000007u;
goto P_0c0832d6;
P_0c0832d6: /* original a3cb, guest PC 0x0c0832d6 */
if(!s->budget--) { s->failed_pc=0x0c0832d6u; return 0; }
goto P_0c083a70;
P_0c0832d8: /* original 0009, guest PC 0x0c0832d8 */
if(!s->budget--) { s->failed_pc=0x0c0832d8u; return 0; }
goto P_0c0832da;
P_0c0832da: /* original 6283, guest PC 0x0c0832da */
if(!s->budget--) { s->failed_pc=0x0c0832dau; return 0; }
r[2]=r[8];
goto P_0c0832dc;
P_0c0832dc: /* original 7217, guest PC 0x0c0832dc */
if(!s->budget--) { s->failed_pc=0x0c0832dcu; return 0; }
r[2]+=0x00000017u;
goto P_0c0832de;
P_0c0832de: /* original 9d46, guest PC 0x0c0832de */
if(!s->budget--) { s->failed_pc=0x0c0832deu; return 0; }
r[13]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08336eu,2);
goto P_0c0832e0;
P_0c0832e0: /* original 2f22, guest PC 0x0c0832e0 */
if(!s->budget--) { s->failed_pc=0x0c0832e0u; return 0; }
write(ram,r[15],r[2],4);
goto P_0c0832e2;
P_0c0832e2: /* original 51f1, guest PC 0x0c0832e2 */
if(!s->budget--) { s->failed_pc=0x0c0832e2u; return 0; }
r[1]=read(ram,r[15]+4,4);
goto P_0c0832e4;
P_0c0832e4: /* original 2118, guest PC 0x0c0832e4 */
if(!s->budget--) { s->failed_pc=0x0c0832e4u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[1])==0)!=0);
goto P_0c0832e6;
P_0c0832e6: /* original 8910, guest PC 0x0c0832e6 */
if(!s->budget--) { s->failed_pc=0x0c0832e6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c08330a; }
goto P_0c0832e8;
P_0c0832e8: /* original d124, guest PC 0x0c0832e8 */
if(!s->budget--) { s->failed_pc=0x0c0832e8u; return 0; }
r[1]=read(ram,0x0c08337cu,4);
goto P_0c0832ea;
P_0c0832ea: /* original 65c3, guest PC 0x0c0832ea */
if(!s->budget--) { s->failed_pc=0x0c0832eau; return 0; }
r[5]=r[12];
goto P_0c0832ec;
P_0c0832ec: /* original 9640, guest PC 0x0c0832ec */
if(!s->budget--) { s->failed_pc=0x0c0832ecu; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c083370u,2);
goto P_0c0832ee;
P_0c0832ee: /* original 410b, guest PC 0x0c0832ee */
if(!s->budget--) { s->failed_pc=0x0c0832eeu; return 0; }
target=r[1];
r[16]=code_base|0x0c0832f2u;
r[4]=0x00000014u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0832f2u) { target=s->pc; goto dispatch; }
goto P_0c0832f2;
P_0c0832f0: /* original e414, guest PC 0x0c0832f0 */
if(!s->budget--) { s->failed_pc=0x0c0832f0u; return 0; }
r[4]=0x00000014u;
goto P_0c0832f2;
P_0c0832f2: /* original d322, guest PC 0x0c0832f2 */
if(!s->budget--) { s->failed_pc=0x0c0832f2u; return 0; }
r[3]=read(ram,0x0c08337cu,4);
goto P_0c0832f4;
P_0c0832f4: /* original 65c3, guest PC 0x0c0832f4 */
if(!s->budget--) { s->failed_pc=0x0c0832f4u; return 0; }
r[5]=r[12];
goto P_0c0832f6;
P_0c0832f6: /* original 963c, guest PC 0x0c0832f6 */
if(!s->budget--) { s->failed_pc=0x0c0832f6u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c083372u,2);
goto P_0c0832f8;
P_0c0832f8: /* original 430b, guest PC 0x0c0832f8 */
if(!s->budget--) { s->failed_pc=0x0c0832f8u; return 0; }
target=r[3];
r[16]=code_base|0x0c0832fcu;
r[4]=0x00000007u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0832fcu) { target=s->pc; goto dispatch; }
goto P_0c0832fc;
P_0c0832fa: /* original e407, guest PC 0x0c0832fa */
if(!s->budget--) { s->failed_pc=0x0c0832fau; return 0; }
r[4]=0x00000007u;
goto P_0c0832fc;
P_0c0832fc: /* original d31f, guest PC 0x0c0832fc */
if(!s->budget--) { s->failed_pc=0x0c0832fcu; return 0; }
r[3]=read(ram,0x0c08337cu,4);
goto P_0c0832fe;
P_0c0832fe: /* original 66d3, guest PC 0x0c0832fe */
if(!s->budget--) { s->failed_pc=0x0c0832feu; return 0; }
r[6]=r[13];
goto P_0c083300;
P_0c083300: /* original 65f2, guest PC 0x0c083300 */
if(!s->budget--) { s->failed_pc=0x0c083300u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c083302;
P_0c083302: /* original 430b, guest PC 0x0c083302 */
if(!s->budget--) { s->failed_pc=0x0c083302u; return 0; }
target=r[3];
r[16]=code_base|0x0c083306u;
r[4]=0x00000010u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c083306u) { target=s->pc; goto dispatch; }
goto P_0c083306;
P_0c083304: /* original e410, guest PC 0x0c083304 */
if(!s->budget--) { s->failed_pc=0x0c083304u; return 0; }
r[4]=0x00000010u;
goto P_0c083306;
P_0c083306: /* original a068, guest PC 0x0c083306 */
if(!s->budget--) { s->failed_pc=0x0c083306u; return 0; }
goto P_0c0833da;
P_0c083308: /* original 0009, guest PC 0x0c083308 */
if(!s->budget--) { s->failed_pc=0x0c083308u; return 0; }
goto P_0c08330a;
P_0c08330a: /* original 9233, guest PC 0x0c08330a */
if(!s->budget--) { s->failed_pc=0x0c08330au; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c083374u,2);
goto P_0c08330c;
P_0c08330c: /* original 63a3, guest PC 0x0c08330c */
if(!s->budget--) { s->failed_pc=0x0c08330cu; return 0; }
r[3]=r[10];
goto P_0c08330e;
P_0c08330e: /* original 4308, guest PC 0x0c08330e */
if(!s->budget--) { s->failed_pc=0x0c08330eu; return 0; }
r[3]<<=2;
goto P_0c083310;
P_0c083310: /* original 32ec, guest PC 0x0c083310 */
if(!s->budget--) { s->failed_pc=0x0c083310u; return 0; }
r[2]+=r[14];
goto P_0c083312;
P_0c083312: /* original 332c, guest PC 0x0c083312 */
if(!s->budget--) { s->failed_pc=0x0c083312u; return 0; }
r[3]+=r[2];
goto P_0c083314;
P_0c083314: /* original 6132, guest PC 0x0c083314 */
if(!s->budget--) { s->failed_pc=0x0c083314u; return 0; }
tmp=read(ram,r[3],4);
r[1]=tmp;
goto P_0c083316;
P_0c083316: /* original 2118, guest PC 0x0c083316 */
if(!s->budget--) { s->failed_pc=0x0c083316u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[1])==0)!=0);
goto P_0c083318;
P_0c083318: /* original 8b34, guest PC 0x0c083318 */
if(!s->budget--) { s->failed_pc=0x0c083318u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c083384; }
goto P_0c08331a;
P_0c08331a: /* original d318, guest PC 0x0c08331a */
if(!s->budget--) { s->failed_pc=0x0c08331au; return 0; }
r[3]=read(ram,0x0c08337cu,4);
goto P_0c08331c;
P_0c08331c: /* original 65c3, guest PC 0x0c08331c */
if(!s->budget--) { s->failed_pc=0x0c08331cu; return 0; }
r[5]=r[12];
goto P_0c08331e;
P_0c08331e: /* original 9627, guest PC 0x0c08331e */
if(!s->budget--) { s->failed_pc=0x0c08331eu; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c083370u,2);
goto P_0c083320;
P_0c083320: /* original 430b, guest PC 0x0c083320 */
if(!s->budget--) { s->failed_pc=0x0c083320u; return 0; }
target=r[3];
r[16]=code_base|0x0c083324u;
r[4]=0x00000014u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c083324u) { target=s->pc; goto dispatch; }
goto P_0c083324;
P_0c083322: /* original e414, guest PC 0x0c083322 */
if(!s->budget--) { s->failed_pc=0x0c083322u; return 0; }
r[4]=0x00000014u;
goto P_0c083324;
P_0c083324: /* original 9327, guest PC 0x0c083324 */
if(!s->budget--) { s->failed_pc=0x0c083324u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c083376u,2);
goto P_0c083326;
P_0c083326: /* original 60a3, guest PC 0x0c083326 */
if(!s->budget--) { s->failed_pc=0x0c083326u; return 0; }
r[0]=r[10];
goto P_0c083328;
P_0c083328: /* original 4008, guest PC 0x0c083328 */
if(!s->budget--) { s->failed_pc=0x0c083328u; return 0; }
r[0]<<=2;
goto P_0c08332a;
P_0c08332a: /* original 33ec, guest PC 0x0c08332a */
if(!s->budget--) { s->failed_pc=0x0c08332au; return 0; }
r[3]+=r[14];
goto P_0c08332c;
P_0c08332c: /* original 003e, guest PC 0x0c08332c */
if(!s->budget--) { s->failed_pc=0x0c08332cu; return 0; }
r[0]=read(ram,r[3]+r[0],4);
goto P_0c08332e;
P_0c08332e: /* original 8809, guest PC 0x0c08332e */
if(!s->budget--) { s->failed_pc=0x0c08332eu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000009u)!=0);
goto P_0c083330;
P_0c083330: /* original 8b09, guest PC 0x0c083330 */
if(!s->budget--) { s->failed_pc=0x0c083330u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c083346; }
goto P_0c083332;
P_0c083332: /* original 53f2, guest PC 0x0c083332 */
if(!s->budget--) { s->failed_pc=0x0c083332u; return 0; }
r[3]=read(ram,r[15]+8,4);
goto P_0c083334;
P_0c083334: /* original 2338, guest PC 0x0c083334 */
if(!s->budget--) { s->failed_pc=0x0c083334u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c083336;
P_0c083336: /* original 890e, guest PC 0x0c083336 */
if(!s->budget--) { s->failed_pc=0x0c083336u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c083356; }
goto P_0c083338;
P_0c083338: /* original d310, guest PC 0x0c083338 */
if(!s->budget--) { s->failed_pc=0x0c083338u; return 0; }
r[3]=read(ram,0x0c08337cu,4);
goto P_0c08333a;
P_0c08333a: /* original 65f2, guest PC 0x0c08333a */
if(!s->budget--) { s->failed_pc=0x0c08333au; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c08333c;
P_0c08333c: /* original 961c, guest PC 0x0c08333c */
if(!s->budget--) { s->failed_pc=0x0c08333cu; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c083378u,2);
goto P_0c08333e;
P_0c08333e: /* original 430b, guest PC 0x0c08333e */
if(!s->budget--) { s->failed_pc=0x0c08333eu; return 0; }
target=r[3];
r[16]=code_base|0x0c083342u;
r[4]=0x00000010u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c083342u) { target=s->pc; goto dispatch; }
goto P_0c083342;
P_0c083340: /* original e410, guest PC 0x0c083340 */
if(!s->budget--) { s->failed_pc=0x0c083340u; return 0; }
r[4]=0x00000010u;
goto P_0c083342;
P_0c083342: /* original a008, guest PC 0x0c083342 */
if(!s->budget--) { s->failed_pc=0x0c083342u; return 0; }
goto P_0c083356;
P_0c083344: /* original 0009, guest PC 0x0c083344 */
if(!s->budget--) { s->failed_pc=0x0c083344u; return 0; }
goto P_0c083346;
P_0c083346: /* original d30d, guest PC 0x0c083346 */
if(!s->budget--) { s->failed_pc=0x0c083346u; return 0; }
r[3]=read(ram,0x0c08337cu,4);
goto P_0c083348;
P_0c083348: /* original 66d3, guest PC 0x0c083348 */
if(!s->budget--) { s->failed_pc=0x0c083348u; return 0; }
r[6]=r[13];
goto P_0c08334a;
P_0c08334a: /* original 65f2, guest PC 0x0c08334a */
if(!s->budget--) { s->failed_pc=0x0c08334au; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c08334c;
P_0c08334c: /* original 430b, guest PC 0x0c08334c */
if(!s->budget--) { s->failed_pc=0x0c08334cu; return 0; }
target=r[3];
r[16]=code_base|0x0c083350u;
r[4]=0x00000010u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c083350u) { target=s->pc; goto dispatch; }
goto P_0c083350;
P_0c08334e: /* original e410, guest PC 0x0c08334e */
if(!s->budget--) { s->failed_pc=0x0c08334eu; return 0; }
r[4]=0x00000010u;
goto P_0c083350;
P_0c083350: /* original 52f2, guest PC 0x0c083350 */
if(!s->budget--) { s->failed_pc=0x0c083350u; return 0; }
r[2]=read(ram,r[15]+8,4);
goto P_0c083352;
P_0c083352: /* original 2228, guest PC 0x0c083352 */
if(!s->budget--) { s->failed_pc=0x0c083352u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c083354;
P_0c083354: /* original 8941, guest PC 0x0c083354 */
if(!s->budget--) { s->failed_pc=0x0c083354u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0833da; }
goto P_0c083356;
P_0c083356: /* original 9d10, guest PC 0x0c083356 */
if(!s->budget--) { s->failed_pc=0x0c083356u; return 0; }
r[13]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08337au,2);
goto P_0c083358;
P_0c083358: /* original 65c3, guest PC 0x0c083358 */
if(!s->budget--) { s->failed_pc=0x0c083358u; return 0; }
r[5]=r[12];
goto P_0c08335a;
P_0c08335a: /* original d308, guest PC 0x0c08335a */
if(!s->budget--) { s->failed_pc=0x0c08335au; return 0; }
r[3]=read(ram,0x0c08337cu,4);
goto P_0c08335c;
P_0c08335c: /* original 66d3, guest PC 0x0c08335c */
if(!s->budget--) { s->failed_pc=0x0c08335cu; return 0; }
r[6]=r[13];
goto P_0c08335e;
P_0c08335e: /* original 430b, guest PC 0x0c08335e */
if(!s->budget--) { s->failed_pc=0x0c08335eu; return 0; }
target=r[3];
r[16]=code_base|0x0c083362u;
r[4]=0x00000007u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c083362u) { target=s->pc; goto dispatch; }
goto P_0c083362;
P_0c083360: /* original e407, guest PC 0x0c083360 */
if(!s->budget--) { s->failed_pc=0x0c083360u; return 0; }
r[4]=0x00000007u;
goto P_0c083362;
P_0c083362: /* original a03a, guest PC 0x0c083362 */
if(!s->budget--) { s->failed_pc=0x0c083362u; return 0; }
goto P_0c0833da;
P_0c083364: /* original 0009, guest PC 0x0c083364 */
if(!s->budget--) { s->failed_pc=0x0c083364u; return 0; }
return vf3_matrix_family(0x0c083366u,s,ram);
P_0c083384: /* original 9386, guest PC 0x0c083384 */
if(!s->budget--) { s->failed_pc=0x0c083384u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c083494u,2);
goto P_0c083386;
P_0c083386: /* original 60a3, guest PC 0x0c083386 */
if(!s->budget--) { s->failed_pc=0x0c083386u; return 0; }
r[0]=r[10];
goto P_0c083388;
P_0c083388: /* original 4008, guest PC 0x0c083388 */
if(!s->budget--) { s->failed_pc=0x0c083388u; return 0; }
r[0]<<=2;
goto P_0c08338a;
P_0c08338a: /* original 33ec, guest PC 0x0c08338a */
if(!s->budget--) { s->failed_pc=0x0c08338au; return 0; }
r[3]+=r[14];
goto P_0c08338c;
P_0c08338c: /* original 003e, guest PC 0x0c08338c */
if(!s->budget--) { s->failed_pc=0x0c08338cu; return 0; }
r[0]=read(ram,r[3]+r[0],4);
goto P_0c08338e;
P_0c08338e: /* original 8801, guest PC 0x0c08338e */
if(!s->budget--) { s->failed_pc=0x0c08338eu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c083390;
P_0c083390: /* original 8b23, guest PC 0x0c083390 */
if(!s->budget--) { s->failed_pc=0x0c083390u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0833da; }
goto P_0c083392;
P_0c083392: /* original d344, guest PC 0x0c083392 */
if(!s->budget--) { s->failed_pc=0x0c083392u; return 0; }
r[3]=read(ram,0x0c0834a4u,4);
goto P_0c083394;
P_0c083394: /* original 65c3, guest PC 0x0c083394 */
if(!s->budget--) { s->failed_pc=0x0c083394u; return 0; }
r[5]=r[12];
goto P_0c083396;
P_0c083396: /* original 967e, guest PC 0x0c083396 */
if(!s->budget--) { s->failed_pc=0x0c083396u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c083496u,2);
goto P_0c083398;
P_0c083398: /* original 430b, guest PC 0x0c083398 */
if(!s->budget--) { s->failed_pc=0x0c083398u; return 0; }
target=r[3];
r[16]=code_base|0x0c08339cu;
r[4]=0x00000007u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08339cu) { target=s->pc; goto dispatch; }
goto P_0c08339c;
P_0c08339a: /* original e407, guest PC 0x0c08339a */
if(!s->budget--) { s->failed_pc=0x0c08339au; return 0; }
r[4]=0x00000007u;
goto P_0c08339c;
P_0c08339c: /* original 937c, guest PC 0x0c08339c */
if(!s->budget--) { s->failed_pc=0x0c08339cu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c083498u,2);
goto P_0c08339e;
P_0c08339e: /* original 60a3, guest PC 0x0c08339e */
if(!s->budget--) { s->failed_pc=0x0c08339eu; return 0; }
r[0]=r[10];
goto P_0c0833a0;
P_0c0833a0: /* original 4008, guest PC 0x0c0833a0 */
if(!s->budget--) { s->failed_pc=0x0c0833a0u; return 0; }
r[0]<<=2;
goto P_0c0833a2;
P_0c0833a2: /* original 33ec, guest PC 0x0c0833a2 */
if(!s->budget--) { s->failed_pc=0x0c0833a2u; return 0; }
r[3]+=r[14];
goto P_0c0833a4;
P_0c0833a4: /* original 003e, guest PC 0x0c0833a4 */
if(!s->budget--) { s->failed_pc=0x0c0833a4u; return 0; }
r[0]=read(ram,r[3]+r[0],4);
goto P_0c0833a6;
P_0c0833a6: /* original 8809, guest PC 0x0c0833a6 */
if(!s->budget--) { s->failed_pc=0x0c0833a6u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000009u)!=0);
goto P_0c0833a8;
P_0c0833a8: /* original 8b09, guest PC 0x0c0833a8 */
if(!s->budget--) { s->failed_pc=0x0c0833a8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0833be; }
goto P_0c0833aa;
P_0c0833aa: /* original 53f2, guest PC 0x0c0833aa */
if(!s->budget--) { s->failed_pc=0x0c0833aau; return 0; }
r[3]=read(ram,r[15]+8,4);
goto P_0c0833ac;
P_0c0833ac: /* original 2338, guest PC 0x0c0833ac */
if(!s->budget--) { s->failed_pc=0x0c0833acu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0833ae;
P_0c0833ae: /* original 890e, guest PC 0x0c0833ae */
if(!s->budget--) { s->failed_pc=0x0c0833aeu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0833ce; }
goto P_0c0833b0;
P_0c0833b0: /* original d33c, guest PC 0x0c0833b0 */
if(!s->budget--) { s->failed_pc=0x0c0833b0u; return 0; }
r[3]=read(ram,0x0c0834a4u,4);
goto P_0c0833b2;
P_0c0833b2: /* original 65f2, guest PC 0x0c0833b2 */
if(!s->budget--) { s->failed_pc=0x0c0833b2u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0833b4;
P_0c0833b4: /* original 9671, guest PC 0x0c0833b4 */
if(!s->budget--) { s->failed_pc=0x0c0833b4u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08349au,2);
goto P_0c0833b6;
P_0c0833b6: /* original 430b, guest PC 0x0c0833b6 */
if(!s->budget--) { s->failed_pc=0x0c0833b6u; return 0; }
target=r[3];
r[16]=code_base|0x0c0833bau;
r[4]=0x00000010u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0833bau) { target=s->pc; goto dispatch; }
goto P_0c0833ba;
P_0c0833b8: /* original e410, guest PC 0x0c0833b8 */
if(!s->budget--) { s->failed_pc=0x0c0833b8u; return 0; }
r[4]=0x00000010u;
goto P_0c0833ba;
P_0c0833ba: /* original a008, guest PC 0x0c0833ba */
if(!s->budget--) { s->failed_pc=0x0c0833bau; return 0; }
goto P_0c0833ce;
P_0c0833bc: /* original 0009, guest PC 0x0c0833bc */
if(!s->budget--) { s->failed_pc=0x0c0833bcu; return 0; }
goto P_0c0833be;
P_0c0833be: /* original d339, guest PC 0x0c0833be */
if(!s->budget--) { s->failed_pc=0x0c0833beu; return 0; }
r[3]=read(ram,0x0c0834a4u,4);
goto P_0c0833c0;
P_0c0833c0: /* original 66d3, guest PC 0x0c0833c0 */
if(!s->budget--) { s->failed_pc=0x0c0833c0u; return 0; }
r[6]=r[13];
goto P_0c0833c2;
P_0c0833c2: /* original 65f2, guest PC 0x0c0833c2 */
if(!s->budget--) { s->failed_pc=0x0c0833c2u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0833c4;
P_0c0833c4: /* original 430b, guest PC 0x0c0833c4 */
if(!s->budget--) { s->failed_pc=0x0c0833c4u; return 0; }
target=r[3];
r[16]=code_base|0x0c0833c8u;
r[4]=0x00000010u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0833c8u) { target=s->pc; goto dispatch; }
goto P_0c0833c8;
P_0c0833c6: /* original e410, guest PC 0x0c0833c6 */
if(!s->budget--) { s->failed_pc=0x0c0833c6u; return 0; }
r[4]=0x00000010u;
goto P_0c0833c8;
P_0c0833c8: /* original 52f2, guest PC 0x0c0833c8 */
if(!s->budget--) { s->failed_pc=0x0c0833c8u; return 0; }
r[2]=read(ram,r[15]+8,4);
goto P_0c0833ca;
P_0c0833ca: /* original 2228, guest PC 0x0c0833ca */
if(!s->budget--) { s->failed_pc=0x0c0833cau; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c0833cc;
P_0c0833cc: /* original 8905, guest PC 0x0c0833cc */
if(!s->budget--) { s->failed_pc=0x0c0833ccu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0833da; }
goto P_0c0833ce;
P_0c0833ce: /* original 9d65, guest PC 0x0c0833ce */
if(!s->budget--) { s->failed_pc=0x0c0833ceu; return 0; }
r[13]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08349cu,2);
goto P_0c0833d0;
P_0c0833d0: /* original 65c3, guest PC 0x0c0833d0 */
if(!s->budget--) { s->failed_pc=0x0c0833d0u; return 0; }
r[5]=r[12];
goto P_0c0833d2;
P_0c0833d2: /* original d334, guest PC 0x0c0833d2 */
if(!s->budget--) { s->failed_pc=0x0c0833d2u; return 0; }
r[3]=read(ram,0x0c0834a4u,4);
goto P_0c0833d4;
P_0c0833d4: /* original 66d3, guest PC 0x0c0833d4 */
if(!s->budget--) { s->failed_pc=0x0c0833d4u; return 0; }
r[6]=r[13];
goto P_0c0833d6;
P_0c0833d6: /* original 430b, guest PC 0x0c0833d6 */
if(!s->budget--) { s->failed_pc=0x0c0833d6u; return 0; }
target=r[3];
r[16]=code_base|0x0c0833dau;
r[4]=0x00000014u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0833dau) { target=s->pc; goto dispatch; }
goto P_0c0833da;
P_0c0833d8: /* original e414, guest PC 0x0c0833d8 */
if(!s->budget--) { s->failed_pc=0x0c0833d8u; return 0; }
r[4]=0x00000014u;
goto P_0c0833da;
P_0c0833da: /* original 6383, guest PC 0x0c0833da */
if(!s->budget--) { s->failed_pc=0x0c0833dau; return 0; }
r[3]=r[8];
goto P_0c0833dc;
P_0c0833dc: /* original 7311, guest PC 0x0c0833dc */
if(!s->budget--) { s->failed_pc=0x0c0833dcu; return 0; }
r[3]+=0x00000011u;
goto P_0c0833de;
P_0c0833de: /* original 60a3, guest PC 0x0c0833de */
if(!s->budget--) { s->failed_pc=0x0c0833deu; return 0; }
r[0]=r[10];
goto P_0c0833e0;
P_0c0833e0: /* original 4008, guest PC 0x0c0833e0 */
if(!s->budget--) { s->failed_pc=0x0c0833e0u; return 0; }
r[0]<<=2;
goto P_0c0833e2;
P_0c0833e2: /* original 6283, guest PC 0x0c0833e2 */
if(!s->budget--) { s->failed_pc=0x0c0833e2u; return 0; }
r[2]=r[8];
goto P_0c0833e4;
P_0c0833e4: /* original 6ca3, guest PC 0x0c0833e4 */
if(!s->budget--) { s->failed_pc=0x0c0833e4u; return 0; }
r[12]=r[10];
goto P_0c0833e6;
P_0c0833e6: /* original 6d83, guest PC 0x0c0833e6 */
if(!s->budget--) { s->failed_pc=0x0c0833e6u; return 0; }
r[13]=r[8];
goto P_0c0833e8;
P_0c0833e8: /* original 7d0a, guest PC 0x0c0833e8 */
if(!s->budget--) { s->failed_pc=0x0c0833e8u; return 0; }
r[13]+=0x0000000au;
goto P_0c0833ea;
P_0c0833ea: /* original 4c08, guest PC 0x0c0833ea */
if(!s->budget--) { s->failed_pc=0x0c0833eau; return 0; }
r[12]<<=2;
goto P_0c0833ec;
P_0c0833ec: /* original 1fd2, guest PC 0x0c0833ec */
if(!s->budget--) { s->failed_pc=0x0c0833ecu; return 0; }
write(ram,r[15]+8,r[13],4);
goto P_0c0833ee;
P_0c0833ee: /* original 2f32, guest PC 0x0c0833ee */
if(!s->budget--) { s->failed_pc=0x0c0833eeu; return 0; }
write(ram,r[15],r[3],4);
goto P_0c0833f0;
P_0c0833f0: /* original 720f, guest PC 0x0c0833f0 */
if(!s->budget--) { s->failed_pc=0x0c0833f0u; return 0; }
r[2]+=0x0000000fu;
goto P_0c0833f2;
P_0c0833f2: /* original 4c08, guest PC 0x0c0833f2 */
if(!s->budget--) { s->failed_pc=0x0c0833f2u; return 0; }
r[12]<<=2;
goto P_0c0833f4;
P_0c0833f4: /* original 1f21, guest PC 0x0c0833f4 */
if(!s->budget--) { s->failed_pc=0x0c0833f4u; return 0; }
write(ram,r[15]+4,r[2],4);
goto P_0c0833f6;
P_0c0833f6: /* original 934d, guest PC 0x0c0833f6 */
if(!s->budget--) { s->failed_pc=0x0c0833f6u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c083494u,2);
goto P_0c0833f8;
P_0c0833f8: /* original 33ec, guest PC 0x0c0833f8 */
if(!s->budget--) { s->failed_pc=0x0c0833f8u; return 0; }
r[3]+=r[14];
goto P_0c0833fa;
P_0c0833fa: /* original 003e, guest PC 0x0c0833fa */
if(!s->budget--) { s->failed_pc=0x0c0833fau; return 0; }
r[0]=read(ram,r[3]+r[0],4);
goto P_0c0833fc;
P_0c0833fc: /* original 8801, guest PC 0x0c0833fc */
if(!s->budget--) { s->failed_pc=0x0c0833fcu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c0833fe;
P_0c0833fe: /* original 8f57, guest PC 0x0c0833fe */
if(!s->budget--) { s->failed_pc=0x0c0833feu; return 0; }
cond=r[17]&1u;
r[12]<<=2;
if(!cond) { goto P_0c0834b0; }
goto P_0c083402;
P_0c083400: /* original 4c08, guest PC 0x0c083400 */
if(!s->budget--) { s->failed_pc=0x0c083400u; return 0; }
r[12]<<=2;
goto P_0c083402;
P_0c083402: /* original 9349, guest PC 0x0c083402 */
if(!s->budget--) { s->failed_pc=0x0c083402u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c083498u,2);
goto P_0c083404;
P_0c083404: /* original 60a3, guest PC 0x0c083404 */
if(!s->budget--) { s->failed_pc=0x0c083404u; return 0; }
r[0]=r[10];
goto P_0c083406;
P_0c083406: /* original 4008, guest PC 0x0c083406 */
if(!s->budget--) { s->failed_pc=0x0c083406u; return 0; }
r[0]<<=2;
goto P_0c083408;
P_0c083408: /* original 33ec, guest PC 0x0c083408 */
if(!s->budget--) { s->failed_pc=0x0c083408u; return 0; }
r[3]+=r[14];
goto P_0c08340a;
P_0c08340a: /* original 003e, guest PC 0x0c08340a */
if(!s->budget--) { s->failed_pc=0x0c08340au; return 0; }
r[0]=read(ram,r[3]+r[0],4);
goto P_0c08340c;
P_0c08340c: /* original 8801, guest PC 0x0c08340c */
if(!s->budget--) { s->failed_pc=0x0c08340cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c08340e;
P_0c08340e: /* original 8b20, guest PC 0x0c08340e */
if(!s->budget--) { s->failed_pc=0x0c08340eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c083452; }
goto P_0c083410;
P_0c083410: /* original d324, guest PC 0x0c083410 */
if(!s->budget--) { s->failed_pc=0x0c083410u; return 0; }
r[3]=read(ram,0x0c0834a4u,4);
goto P_0c083412;
P_0c083412: /* original 65d3, guest PC 0x0c083412 */
if(!s->budget--) { s->failed_pc=0x0c083412u; return 0; }
r[5]=r[13];
goto P_0c083414;
P_0c083414: /* original 9643, guest PC 0x0c083414 */
if(!s->budget--) { s->failed_pc=0x0c083414u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08349eu,2);
goto P_0c083416;
P_0c083416: /* original 430b, guest PC 0x0c083416 */
if(!s->budget--) { s->failed_pc=0x0c083416u; return 0; }
target=r[3];
r[16]=code_base|0x0c08341au;
r[4]=0x00000012u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08341au) { target=s->pc; goto dispatch; }
goto P_0c08341a;
P_0c083418: /* original e412, guest PC 0x0c083418 */
if(!s->budget--) { s->failed_pc=0x0c083418u; return 0; }
r[4]=0x00000012u;
goto P_0c08341a;
P_0c08341a: /* original 9641, guest PC 0x0c08341a */
if(!s->budget--) { s->failed_pc=0x0c08341au; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0834a0u,2);
goto P_0c08341c;
P_0c08341c: /* original 65d3, guest PC 0x0c08341c */
if(!s->budget--) { s->failed_pc=0x0c08341cu; return 0; }
r[5]=r[13];
goto P_0c08341e;
P_0c08341e: /* original d322, guest PC 0x0c08341e */
if(!s->budget--) { s->failed_pc=0x0c08341eu; return 0; }
r[3]=read(ram,0x0c0834a8u,4);
goto P_0c083420;
P_0c083420: /* original 36ec, guest PC 0x0c083420 */
if(!s->budget--) { s->failed_pc=0x0c083420u; return 0; }
r[6]+=r[14];
goto P_0c083422;
P_0c083422: /* original 36cc, guest PC 0x0c083422 */
if(!s->budget--) { s->failed_pc=0x0c083422u; return 0; }
r[6]+=r[12];
goto P_0c083424;
P_0c083424: /* original 5661, guest PC 0x0c083424 */
if(!s->budget--) { s->failed_pc=0x0c083424u; return 0; }
r[6]=read(ram,r[6]+4,4);
goto P_0c083426;
P_0c083426: /* original 430b, guest PC 0x0c083426 */
if(!s->budget--) { s->failed_pc=0x0c083426u; return 0; }
target=r[3];
r[16]=code_base|0x0c08342au;
r[4]=0x00000014u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08342au) { target=s->pc; goto dispatch; }
goto P_0c08342a;
P_0c083428: /* original e414, guest PC 0x0c083428 */
if(!s->budget--) { s->failed_pc=0x0c083428u; return 0; }
r[4]=0x00000014u;
goto P_0c08342a;
P_0c08342a: /* original 6292, guest PC 0x0c08342a */
if(!s->budget--) { s->failed_pc=0x0c08342au; return 0; }
tmp=read(ram,r[9],4);
r[2]=tmp;
goto P_0c08342c;
P_0c08342c: /* original 32b0, guest PC 0x0c08342c */
if(!s->budget--) { s->failed_pc=0x0c08342cu; return 0; }
r[17]=(r[17]&~1u)|((r[2]==r[11])!=0);
goto P_0c08342e;
P_0c08342e: /* original 8f06, guest PC 0x0c08342e */
if(!s->budget--) { s->failed_pc=0x0c08342eu; return 0; }
cond=r[17]&1u;
r[4]=0x0000002du;
if(!cond) { goto P_0c08343e; }
goto P_0c083432;
P_0c083430: /* original e42d, guest PC 0x0c083430 */
if(!s->budget--) { s->failed_pc=0x0c083430u; return 0; }
r[4]=0x0000002du;
goto P_0c083432;
P_0c083432: /* original 9635, guest PC 0x0c083432 */
if(!s->budget--) { s->failed_pc=0x0c083432u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0834a0u,2);
goto P_0c083434;
P_0c083434: /* original 36ec, guest PC 0x0c083434 */
if(!s->budget--) { s->failed_pc=0x0c083434u; return 0; }
r[6]+=r[14];
goto P_0c083436;
P_0c083436: /* original 36cc, guest PC 0x0c083436 */
if(!s->budget--) { s->failed_pc=0x0c083436u; return 0; }
r[6]+=r[12];
goto P_0c083438;
P_0c083438: /* original 5661, guest PC 0x0c083438 */
if(!s->budget--) { s->failed_pc=0x0c083438u; return 0; }
r[6]=read(ram,r[6]+4,4);
goto P_0c08343a;
P_0c08343a: /* original a005, guest PC 0x0c08343a */
if(!s->budget--) { s->failed_pc=0x0c08343au; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c083448;
P_0c08343c: /* original 65f2, guest PC 0x0c08343c */
if(!s->budget--) { s->failed_pc=0x0c08343cu; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c08343e;
P_0c08343e: /* original 962f, guest PC 0x0c08343e */
if(!s->budget--) { s->failed_pc=0x0c08343eu; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0834a0u,2);
goto P_0c083440;
P_0c083440: /* original 55f1, guest PC 0x0c083440 */
if(!s->budget--) { s->failed_pc=0x0c083440u; return 0; }
r[5]=read(ram,r[15]+4,4);
goto P_0c083442;
P_0c083442: /* original 36ec, guest PC 0x0c083442 */
if(!s->budget--) { s->failed_pc=0x0c083442u; return 0; }
r[6]+=r[14];
goto P_0c083444;
P_0c083444: /* original 36cc, guest PC 0x0c083444 */
if(!s->budget--) { s->failed_pc=0x0c083444u; return 0; }
r[6]+=r[12];
goto P_0c083446;
P_0c083446: /* original 5661, guest PC 0x0c083446 */
if(!s->budget--) { s->failed_pc=0x0c083446u; return 0; }
r[6]=read(ram,r[6]+4,4);
goto P_0c083448;
P_0c083448: /* original d317, guest PC 0x0c083448 */
if(!s->budget--) { s->failed_pc=0x0c083448u; return 0; }
r[3]=read(ram,0x0c0834a8u,4);
goto P_0c08344a;
P_0c08344a: /* original 430b, guest PC 0x0c08344a */
if(!s->budget--) { s->failed_pc=0x0c08344au; return 0; }
target=r[3];
r[16]=code_base|0x0c08344eu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08344eu) { target=s->pc; goto dispatch; }
goto P_0c08344e;
P_0c08344c: /* original 0009, guest PC 0x0c08344c */
if(!s->budget--) { s->failed_pc=0x0c08344cu; return 0; }
goto P_0c08344e;
P_0c08344e: /* original a045, guest PC 0x0c08344e */
if(!s->budget--) { s->failed_pc=0x0c08344eu; return 0; }
goto P_0c0834dc;
P_0c083450: /* original 0009, guest PC 0x0c083450 */
if(!s->budget--) { s->failed_pc=0x0c083450u; return 0; }
goto P_0c083452;
P_0c083452: /* original d314, guest PC 0x0c083452 */
if(!s->budget--) { s->failed_pc=0x0c083452u; return 0; }
r[3]=read(ram,0x0c0834a4u,4);
goto P_0c083454;
P_0c083454: /* original 65d3, guest PC 0x0c083454 */
if(!s->budget--) { s->failed_pc=0x0c083454u; return 0; }
r[5]=r[13];
goto P_0c083456;
P_0c083456: /* original 9624, guest PC 0x0c083456 */
if(!s->budget--) { s->failed_pc=0x0c083456u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0834a2u,2);
goto P_0c083458;
P_0c083458: /* original 430b, guest PC 0x0c083458 */
if(!s->budget--) { s->failed_pc=0x0c083458u; return 0; }
target=r[3];
r[16]=code_base|0x0c08345cu;
r[4]=0x00000012u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08345cu) { target=s->pc; goto dispatch; }
goto P_0c08345c;
P_0c08345a: /* original e412, guest PC 0x0c08345a */
if(!s->budget--) { s->failed_pc=0x0c08345au; return 0; }
r[4]=0x00000012u;
goto P_0c08345c;
P_0c08345c: /* original 9620, guest PC 0x0c08345c */
if(!s->budget--) { s->failed_pc=0x0c08345cu; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0834a0u,2);
goto P_0c08345e;
P_0c08345e: /* original 65d3, guest PC 0x0c08345e */
if(!s->budget--) { s->failed_pc=0x0c08345eu; return 0; }
r[5]=r[13];
goto P_0c083460;
P_0c083460: /* original d312, guest PC 0x0c083460 */
if(!s->budget--) { s->failed_pc=0x0c083460u; return 0; }
r[3]=read(ram,0x0c0834acu,4);
goto P_0c083462;
P_0c083462: /* original 36ec, guest PC 0x0c083462 */
if(!s->budget--) { s->failed_pc=0x0c083462u; return 0; }
r[6]+=r[14];
goto P_0c083464;
P_0c083464: /* original 36cc, guest PC 0x0c083464 */
if(!s->budget--) { s->failed_pc=0x0c083464u; return 0; }
r[6]+=r[12];
goto P_0c083466;
P_0c083466: /* original 5661, guest PC 0x0c083466 */
if(!s->budget--) { s->failed_pc=0x0c083466u; return 0; }
r[6]=read(ram,r[6]+4,4);
goto P_0c083468;
P_0c083468: /* original 430b, guest PC 0x0c083468 */
if(!s->budget--) { s->failed_pc=0x0c083468u; return 0; }
target=r[3];
r[16]=code_base|0x0c08346cu;
r[4]=0x00000014u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08346cu) { target=s->pc; goto dispatch; }
goto P_0c08346c;
P_0c08346a: /* original e414, guest PC 0x0c08346a */
if(!s->budget--) { s->failed_pc=0x0c08346au; return 0; }
r[4]=0x00000014u;
goto P_0c08346c;
P_0c08346c: /* original 6292, guest PC 0x0c08346c */
if(!s->budget--) { s->failed_pc=0x0c08346cu; return 0; }
tmp=read(ram,r[9],4);
r[2]=tmp;
goto P_0c08346e;
P_0c08346e: /* original 32b0, guest PC 0x0c08346e */
if(!s->budget--) { s->failed_pc=0x0c08346eu; return 0; }
r[17]=(r[17]&~1u)|((r[2]==r[11])!=0);
goto P_0c083470;
P_0c083470: /* original 8f06, guest PC 0x0c083470 */
if(!s->budget--) { s->failed_pc=0x0c083470u; return 0; }
cond=r[17]&1u;
r[4]=0x0000002du;
if(!cond) { goto P_0c083480; }
goto P_0c083474;
P_0c083472: /* original e42d, guest PC 0x0c083472 */
if(!s->budget--) { s->failed_pc=0x0c083472u; return 0; }
r[4]=0x0000002du;
goto P_0c083474;
P_0c083474: /* original 9614, guest PC 0x0c083474 */
if(!s->budget--) { s->failed_pc=0x0c083474u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0834a0u,2);
goto P_0c083476;
P_0c083476: /* original 36ec, guest PC 0x0c083476 */
if(!s->budget--) { s->failed_pc=0x0c083476u; return 0; }
r[6]+=r[14];
goto P_0c083478;
P_0c083478: /* original 36cc, guest PC 0x0c083478 */
if(!s->budget--) { s->failed_pc=0x0c083478u; return 0; }
r[6]+=r[12];
goto P_0c08347a;
P_0c08347a: /* original 5661, guest PC 0x0c08347a */
if(!s->budget--) { s->failed_pc=0x0c08347au; return 0; }
r[6]=read(ram,r[6]+4,4);
goto P_0c08347c;
P_0c08347c: /* original a005, guest PC 0x0c08347c */
if(!s->budget--) { s->failed_pc=0x0c08347cu; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c08348a;
P_0c08347e: /* original 65f2, guest PC 0x0c08347e */
if(!s->budget--) { s->failed_pc=0x0c08347eu; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c083480;
P_0c083480: /* original 960e, guest PC 0x0c083480 */
if(!s->budget--) { s->failed_pc=0x0c083480u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0834a0u,2);
goto P_0c083482;
P_0c083482: /* original 55f1, guest PC 0x0c083482 */
if(!s->budget--) { s->failed_pc=0x0c083482u; return 0; }
r[5]=read(ram,r[15]+4,4);
goto P_0c083484;
P_0c083484: /* original 36ec, guest PC 0x0c083484 */
if(!s->budget--) { s->failed_pc=0x0c083484u; return 0; }
r[6]+=r[14];
goto P_0c083486;
P_0c083486: /* original 36cc, guest PC 0x0c083486 */
if(!s->budget--) { s->failed_pc=0x0c083486u; return 0; }
r[6]+=r[12];
goto P_0c083488;
P_0c083488: /* original 5661, guest PC 0x0c083488 */
if(!s->budget--) { s->failed_pc=0x0c083488u; return 0; }
r[6]=read(ram,r[6]+4,4);
goto P_0c08348a;
P_0c08348a: /* original d308, guest PC 0x0c08348a */
if(!s->budget--) { s->failed_pc=0x0c08348au; return 0; }
r[3]=read(ram,0x0c0834acu,4);
goto P_0c08348c;
P_0c08348c: /* original 430b, guest PC 0x0c08348c */
if(!s->budget--) { s->failed_pc=0x0c08348cu; return 0; }
target=r[3];
r[16]=code_base|0x0c083490u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c083490u) { target=s->pc; goto dispatch; }
goto P_0c083490;
P_0c08348e: /* original 0009, guest PC 0x0c08348e */
if(!s->budget--) { s->failed_pc=0x0c08348eu; return 0; }
goto P_0c083490;
P_0c083490: /* original a024, guest PC 0x0c083490 */
if(!s->budget--) { s->failed_pc=0x0c083490u; return 0; }
goto P_0c0834dc;
P_0c083492: /* original 0009, guest PC 0x0c083492 */
if(!s->budget--) { s->failed_pc=0x0c083492u; return 0; }
return vf3_matrix_family(0x0c083494u,s,ram);
P_0c0834b0: /* original d341, guest PC 0x0c0834b0 */
if(!s->budget--) { s->failed_pc=0x0c0834b0u; return 0; }
r[3]=read(ram,0x0c0835b8u,4);
goto P_0c0834b2;
P_0c0834b2: /* original 65d3, guest PC 0x0c0834b2 */
if(!s->budget--) { s->failed_pc=0x0c0834b2u; return 0; }
r[5]=r[13];
goto P_0c0834b4;
P_0c0834b4: /* original 9679, guest PC 0x0c0834b4 */
if(!s->budget--) { s->failed_pc=0x0c0834b4u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0835aau,2);
goto P_0c0834b6;
P_0c0834b6: /* original 430b, guest PC 0x0c0834b6 */
if(!s->budget--) { s->failed_pc=0x0c0834b6u; return 0; }
target=r[3];
r[16]=code_base|0x0c0834bau;
r[4]=0x00000012u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0834bau) { target=s->pc; goto dispatch; }
goto P_0c0834ba;
P_0c0834b8: /* original e412, guest PC 0x0c0834b8 */
if(!s->budget--) { s->failed_pc=0x0c0834b8u; return 0; }
r[4]=0x00000012u;
goto P_0c0834ba;
P_0c0834ba: /* original d240, guest PC 0x0c0834ba */
if(!s->budget--) { s->failed_pc=0x0c0834bau; return 0; }
r[2]=read(ram,0x0c0835bcu,4);
goto P_0c0834bc;
P_0c0834bc: /* original 65d3, guest PC 0x0c0834bc */
if(!s->budget--) { s->failed_pc=0x0c0834bcu; return 0; }
r[5]=r[13];
goto P_0c0834be;
P_0c0834be: /* original e604, guest PC 0x0c0834be */
if(!s->budget--) { s->failed_pc=0x0c0834beu; return 0; }
r[6]=0x00000004u;
goto P_0c0834c0;
P_0c0834c0: /* original 420b, guest PC 0x0c0834c0 */
if(!s->budget--) { s->failed_pc=0x0c0834c0u; return 0; }
target=r[2];
r[16]=code_base|0x0c0834c4u;
r[4]=0x00000007u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0834c4u) { target=s->pc; goto dispatch; }
goto P_0c0834c4;
P_0c0834c2: /* original e407, guest PC 0x0c0834c2 */
if(!s->budget--) { s->failed_pc=0x0c0834c2u; return 0; }
r[4]=0x00000007u;
goto P_0c0834c4;
P_0c0834c4: /* original 6392, guest PC 0x0c0834c4 */
if(!s->budget--) { s->failed_pc=0x0c0834c4u; return 0; }
tmp=read(ram,r[9],4);
r[3]=tmp;
goto P_0c0834c6;
P_0c0834c6: /* original 33b0, guest PC 0x0c0834c6 */
if(!s->budget--) { s->failed_pc=0x0c0834c6u; return 0; }
r[17]=(r[17]&~1u)|((r[3]==r[11])!=0);
goto P_0c0834c8;
P_0c0834c8: /* original 8f03, guest PC 0x0c0834c8 */
if(!s->budget--) { s->failed_pc=0x0c0834c8u; return 0; }
cond=r[17]&1u;
r[4]=0x0000002du;
if(!cond) { goto P_0c0834d2; }
goto P_0c0834cc;
P_0c0834ca: /* original e42d, guest PC 0x0c0834ca */
if(!s->budget--) { s->failed_pc=0x0c0834cau; return 0; }
r[4]=0x0000002du;
goto P_0c0834cc;
P_0c0834cc: /* original e604, guest PC 0x0c0834cc */
if(!s->budget--) { s->failed_pc=0x0c0834ccu; return 0; }
r[6]=0x00000004u;
goto P_0c0834ce;
P_0c0834ce: /* original a002, guest PC 0x0c0834ce */
if(!s->budget--) { s->failed_pc=0x0c0834ceu; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0834d6;
P_0c0834d0: /* original 65f2, guest PC 0x0c0834d0 */
if(!s->budget--) { s->failed_pc=0x0c0834d0u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0834d2;
P_0c0834d2: /* original 55f1, guest PC 0x0c0834d2 */
if(!s->budget--) { s->failed_pc=0x0c0834d2u; return 0; }
r[5]=read(ram,r[15]+4,4);
goto P_0c0834d4;
P_0c0834d4: /* original e604, guest PC 0x0c0834d4 */
if(!s->budget--) { s->failed_pc=0x0c0834d4u; return 0; }
r[6]=0x00000004u;
goto P_0c0834d6;
P_0c0834d6: /* original d339, guest PC 0x0c0834d6 */
if(!s->budget--) { s->failed_pc=0x0c0834d6u; return 0; }
r[3]=read(ram,0x0c0835bcu,4);
goto P_0c0834d8;
P_0c0834d8: /* original 430b, guest PC 0x0c0834d8 */
if(!s->budget--) { s->failed_pc=0x0c0834d8u; return 0; }
target=r[3];
r[16]=code_base|0x0c0834dcu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0834dcu) { target=s->pc; goto dispatch; }
goto P_0c0834dc;
P_0c0834da: /* original 0009, guest PC 0x0c0834da */
if(!s->budget--) { s->failed_pc=0x0c0834dau; return 0; }
goto P_0c0834dc;
P_0c0834dc: /* original 60a3, guest PC 0x0c0834dc */
if(!s->budget--) { s->failed_pc=0x0c0834dcu; return 0; }
r[0]=r[10];
goto P_0c0834de;
P_0c0834de: /* original 4008, guest PC 0x0c0834de */
if(!s->budget--) { s->failed_pc=0x0c0834deu; return 0; }
r[0]<<=2;
goto P_0c0834e0;
P_0c0834e0: /* original 6283, guest PC 0x0c0834e0 */
if(!s->budget--) { s->failed_pc=0x0c0834e0u; return 0; }
r[2]=r[8];
goto P_0c0834e2;
P_0c0834e2: /* original 720d, guest PC 0x0c0834e2 */
if(!s->budget--) { s->failed_pc=0x0c0834e2u; return 0; }
r[2]+=0x0000000du;
goto P_0c0834e4;
P_0c0834e4: /* original 2f22, guest PC 0x0c0834e4 */
if(!s->budget--) { s->failed_pc=0x0c0834e4u; return 0; }
write(ram,r[15],r[2],4);
goto P_0c0834e6;
P_0c0834e6: /* original 9361, guest PC 0x0c0834e6 */
if(!s->budget--) { s->failed_pc=0x0c0834e6u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0835acu,2);
goto P_0c0834e8;
P_0c0834e8: /* original 33ec, guest PC 0x0c0834e8 */
if(!s->budget--) { s->failed_pc=0x0c0834e8u; return 0; }
r[3]+=r[14];
goto P_0c0834ea;
P_0c0834ea: /* original 003e, guest PC 0x0c0834ea */
if(!s->budget--) { s->failed_pc=0x0c0834eau; return 0; }
r[0]=read(ram,r[3]+r[0],4);
goto P_0c0834ec;
P_0c0834ec: /* original 8801, guest PC 0x0c0834ec */
if(!s->budget--) { s->failed_pc=0x0c0834ecu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c0834ee;
P_0c0834ee: /* original 8f4b, guest PC 0x0c0834ee */
if(!s->budget--) { s->failed_pc=0x0c0834eeu; return 0; }
cond=r[17]&1u;
r[13]+=0x00000002u;
if(!cond) { goto P_0c083588; }
goto P_0c0834f2;
P_0c0834f0: /* original 7d02, guest PC 0x0c0834f0 */
if(!s->budget--) { s->failed_pc=0x0c0834f0u; return 0; }
r[13]+=0x00000002u;
goto P_0c0834f2;
P_0c0834f2: /* original 935c, guest PC 0x0c0834f2 */
if(!s->budget--) { s->failed_pc=0x0c0834f2u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0835aeu,2);
goto P_0c0834f4;
P_0c0834f4: /* original 60a3, guest PC 0x0c0834f4 */
if(!s->budget--) { s->failed_pc=0x0c0834f4u; return 0; }
r[0]=r[10];
goto P_0c0834f6;
P_0c0834f6: /* original 4008, guest PC 0x0c0834f6 */
if(!s->budget--) { s->failed_pc=0x0c0834f6u; return 0; }
r[0]<<=2;
goto P_0c0834f8;
P_0c0834f8: /* original 33ec, guest PC 0x0c0834f8 */
if(!s->budget--) { s->failed_pc=0x0c0834f8u; return 0; }
r[3]+=r[14];
goto P_0c0834fa;
P_0c0834fa: /* original 003e, guest PC 0x0c0834fa */
if(!s->budget--) { s->failed_pc=0x0c0834fau; return 0; }
r[0]=read(ram,r[3]+r[0],4);
goto P_0c0834fc;
P_0c0834fc: /* original 8802, guest PC 0x0c0834fc */
if(!s->budget--) { s->failed_pc=0x0c0834fcu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c0834fe;
P_0c0834fe: /* original 8b21, guest PC 0x0c0834fe */
if(!s->budget--) { s->failed_pc=0x0c0834feu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c083544; }
goto P_0c083500;
P_0c083500: /* original d32d, guest PC 0x0c083500 */
if(!s->budget--) { s->failed_pc=0x0c083500u; return 0; }
r[3]=read(ram,0x0c0835b8u,4);
goto P_0c083502;
P_0c083502: /* original 65d3, guest PC 0x0c083502 */
if(!s->budget--) { s->failed_pc=0x0c083502u; return 0; }
r[5]=r[13];
goto P_0c083504;
P_0c083504: /* original 9654, guest PC 0x0c083504 */
if(!s->budget--) { s->failed_pc=0x0c083504u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0835b0u,2);
goto P_0c083506;
P_0c083506: /* original 430b, guest PC 0x0c083506 */
if(!s->budget--) { s->failed_pc=0x0c083506u; return 0; }
target=r[3];
r[16]=code_base|0x0c08350au;
r[4]=0x00000012u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08350au) { target=s->pc; goto dispatch; }
goto P_0c08350a;
P_0c083508: /* original e412, guest PC 0x0c083508 */
if(!s->budget--) { s->failed_pc=0x0c083508u; return 0; }
r[4]=0x00000012u;
goto P_0c08350a;
P_0c08350a: /* original 9652, guest PC 0x0c08350a */
if(!s->budget--) { s->failed_pc=0x0c08350au; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0835b2u,2);
goto P_0c08350c;
P_0c08350c: /* original 65d3, guest PC 0x0c08350c */
if(!s->budget--) { s->failed_pc=0x0c08350cu; return 0; }
r[5]=r[13];
goto P_0c08350e;
P_0c08350e: /* original d32c, guest PC 0x0c08350e */
if(!s->budget--) { s->failed_pc=0x0c08350eu; return 0; }
r[3]=read(ram,0x0c0835c0u,4);
goto P_0c083510;
P_0c083510: /* original 36ec, guest PC 0x0c083510 */
if(!s->budget--) { s->failed_pc=0x0c083510u; return 0; }
r[6]+=r[14];
goto P_0c083512;
P_0c083512: /* original 36cc, guest PC 0x0c083512 */
if(!s->budget--) { s->failed_pc=0x0c083512u; return 0; }
r[6]+=r[12];
goto P_0c083514;
P_0c083514: /* original 5662, guest PC 0x0c083514 */
if(!s->budget--) { s->failed_pc=0x0c083514u; return 0; }
r[6]=read(ram,r[6]+8,4);
goto P_0c083516;
P_0c083516: /* original 430b, guest PC 0x0c083516 */
if(!s->budget--) { s->failed_pc=0x0c083516u; return 0; }
target=r[3];
r[16]=code_base|0x0c08351au;
r[4]=0x00000014u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08351au) { target=s->pc; goto dispatch; }
goto P_0c08351a;
P_0c083518: /* original e414, guest PC 0x0c083518 */
if(!s->budget--) { s->failed_pc=0x0c083518u; return 0; }
r[4]=0x00000014u;
goto P_0c08351a;
P_0c08351a: /* original 6292, guest PC 0x0c08351a */
if(!s->budget--) { s->failed_pc=0x0c08351au; return 0; }
tmp=read(ram,r[9],4);
r[2]=tmp;
goto P_0c08351c;
P_0c08351c: /* original 32b0, guest PC 0x0c08351c */
if(!s->budget--) { s->failed_pc=0x0c08351cu; return 0; }
r[17]=(r[17]&~1u)|((r[2]==r[11])!=0);
goto P_0c08351e;
P_0c08351e: /* original 8b06, guest PC 0x0c08351e */
if(!s->budget--) { s->failed_pc=0x0c08351eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c08352e; }
goto P_0c083520;
P_0c083520: /* original 9647, guest PC 0x0c083520 */
if(!s->budget--) { s->failed_pc=0x0c083520u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0835b2u,2);
goto P_0c083522;
P_0c083522: /* original 55f1, guest PC 0x0c083522 */
if(!s->budget--) { s->failed_pc=0x0c083522u; return 0; }
r[5]=read(ram,r[15]+4,4);
goto P_0c083524;
P_0c083524: /* original 36ec, guest PC 0x0c083524 */
if(!s->budget--) { s->failed_pc=0x0c083524u; return 0; }
r[6]+=r[14];
goto P_0c083526;
P_0c083526: /* original 36cc, guest PC 0x0c083526 */
if(!s->budget--) { s->failed_pc=0x0c083526u; return 0; }
r[6]+=r[12];
goto P_0c083528;
P_0c083528: /* original 5662, guest PC 0x0c083528 */
if(!s->budget--) { s->failed_pc=0x0c083528u; return 0; }
r[6]=read(ram,r[6]+8,4);
goto P_0c08352a;
P_0c08352a: /* original a006, guest PC 0x0c08352a */
if(!s->budget--) { s->failed_pc=0x0c08352au; return 0; }
r[4]=0x00000030u;
goto P_0c08353a;
P_0c08352c: /* original e430, guest PC 0x0c08352c */
if(!s->budget--) { s->failed_pc=0x0c08352cu; return 0; }
r[4]=0x00000030u;
goto P_0c08352e;
P_0c08352e: /* original 9640, guest PC 0x0c08352e */
if(!s->budget--) { s->failed_pc=0x0c08352eu; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0835b2u,2);
goto P_0c083530;
P_0c083530: /* original e433, guest PC 0x0c083530 */
if(!s->budget--) { s->failed_pc=0x0c083530u; return 0; }
r[4]=0x00000033u;
goto P_0c083532;
P_0c083532: /* original 65f2, guest PC 0x0c083532 */
if(!s->budget--) { s->failed_pc=0x0c083532u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c083534;
P_0c083534: /* original 36ec, guest PC 0x0c083534 */
if(!s->budget--) { s->failed_pc=0x0c083534u; return 0; }
r[6]+=r[14];
goto P_0c083536;
P_0c083536: /* original 36cc, guest PC 0x0c083536 */
if(!s->budget--) { s->failed_pc=0x0c083536u; return 0; }
r[6]+=r[12];
goto P_0c083538;
P_0c083538: /* original 5662, guest PC 0x0c083538 */
if(!s->budget--) { s->failed_pc=0x0c083538u; return 0; }
r[6]=read(ram,r[6]+8,4);
goto P_0c08353a;
P_0c08353a: /* original d321, guest PC 0x0c08353a */
if(!s->budget--) { s->failed_pc=0x0c08353au; return 0; }
r[3]=read(ram,0x0c0835c0u,4);
goto P_0c08353c;
P_0c08353c: /* original 430b, guest PC 0x0c08353c */
if(!s->budget--) { s->failed_pc=0x0c08353cu; return 0; }
target=r[3];
r[16]=code_base|0x0c083540u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c083540u) { target=s->pc; goto dispatch; }
goto P_0c083540;
P_0c08353e: /* original 0009, guest PC 0x0c08353e */
if(!s->budget--) { s->failed_pc=0x0c08353eu; return 0; }
goto P_0c083540;
P_0c083540: /* original a046, guest PC 0x0c083540 */
if(!s->budget--) { s->failed_pc=0x0c083540u; return 0; }
goto P_0c0835d0;
P_0c083542: /* original 0009, guest PC 0x0c083542 */
if(!s->budget--) { s->failed_pc=0x0c083542u; return 0; }
goto P_0c083544;
P_0c083544: /* original d31c, guest PC 0x0c083544 */
if(!s->budget--) { s->failed_pc=0x0c083544u; return 0; }
r[3]=read(ram,0x0c0835b8u,4);
goto P_0c083546;
P_0c083546: /* original 65d3, guest PC 0x0c083546 */
if(!s->budget--) { s->failed_pc=0x0c083546u; return 0; }
r[5]=r[13];
goto P_0c083548;
P_0c083548: /* original 9634, guest PC 0x0c083548 */
if(!s->budget--) { s->failed_pc=0x0c083548u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0835b4u,2);
goto P_0c08354a;
P_0c08354a: /* original 430b, guest PC 0x0c08354a */
if(!s->budget--) { s->failed_pc=0x0c08354au; return 0; }
target=r[3];
r[16]=code_base|0x0c08354eu;
r[4]=0x00000012u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08354eu) { target=s->pc; goto dispatch; }
goto P_0c08354e;
P_0c08354c: /* original e412, guest PC 0x0c08354c */
if(!s->budget--) { s->failed_pc=0x0c08354cu; return 0; }
r[4]=0x00000012u;
goto P_0c08354e;
P_0c08354e: /* original 9630, guest PC 0x0c08354e */
if(!s->budget--) { s->failed_pc=0x0c08354eu; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0835b2u,2);
goto P_0c083550;
P_0c083550: /* original 65d3, guest PC 0x0c083550 */
if(!s->budget--) { s->failed_pc=0x0c083550u; return 0; }
r[5]=r[13];
goto P_0c083552;
P_0c083552: /* original d31a, guest PC 0x0c083552 */
if(!s->budget--) { s->failed_pc=0x0c083552u; return 0; }
r[3]=read(ram,0x0c0835bcu,4);
goto P_0c083554;
P_0c083554: /* original 36ec, guest PC 0x0c083554 */
if(!s->budget--) { s->failed_pc=0x0c083554u; return 0; }
r[6]+=r[14];
goto P_0c083556;
P_0c083556: /* original 36cc, guest PC 0x0c083556 */
if(!s->budget--) { s->failed_pc=0x0c083556u; return 0; }
r[6]+=r[12];
goto P_0c083558;
P_0c083558: /* original 5662, guest PC 0x0c083558 */
if(!s->budget--) { s->failed_pc=0x0c083558u; return 0; }
r[6]=read(ram,r[6]+8,4);
goto P_0c08355a;
P_0c08355a: /* original 430b, guest PC 0x0c08355a */
if(!s->budget--) { s->failed_pc=0x0c08355au; return 0; }
target=r[3];
r[16]=code_base|0x0c08355eu;
r[4]=0x00000014u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08355eu) { target=s->pc; goto dispatch; }
goto P_0c08355e;
P_0c08355c: /* original e414, guest PC 0x0c08355c */
if(!s->budget--) { s->failed_pc=0x0c08355cu; return 0; }
r[4]=0x00000014u;
goto P_0c08355e;
P_0c08355e: /* original 6292, guest PC 0x0c08355e */
if(!s->budget--) { s->failed_pc=0x0c08355eu; return 0; }
tmp=read(ram,r[9],4);
r[2]=tmp;
goto P_0c083560;
P_0c083560: /* original 32b0, guest PC 0x0c083560 */
if(!s->budget--) { s->failed_pc=0x0c083560u; return 0; }
r[17]=(r[17]&~1u)|((r[2]==r[11])!=0);
goto P_0c083562;
P_0c083562: /* original 8b06, guest PC 0x0c083562 */
if(!s->budget--) { s->failed_pc=0x0c083562u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c083572; }
goto P_0c083564;
P_0c083564: /* original 9625, guest PC 0x0c083564 */
if(!s->budget--) { s->failed_pc=0x0c083564u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0835b2u,2);
goto P_0c083566;
P_0c083566: /* original 55f1, guest PC 0x0c083566 */
if(!s->budget--) { s->failed_pc=0x0c083566u; return 0; }
r[5]=read(ram,r[15]+4,4);
goto P_0c083568;
P_0c083568: /* original 36ec, guest PC 0x0c083568 */
if(!s->budget--) { s->failed_pc=0x0c083568u; return 0; }
r[6]+=r[14];
goto P_0c08356a;
P_0c08356a: /* original 36cc, guest PC 0x0c08356a */
if(!s->budget--) { s->failed_pc=0x0c08356au; return 0; }
r[6]+=r[12];
goto P_0c08356c;
P_0c08356c: /* original 5662, guest PC 0x0c08356c */
if(!s->budget--) { s->failed_pc=0x0c08356cu; return 0; }
r[6]=read(ram,r[6]+8,4);
goto P_0c08356e;
P_0c08356e: /* original a006, guest PC 0x0c08356e */
if(!s->budget--) { s->failed_pc=0x0c08356eu; return 0; }
r[4]=0x00000030u;
goto P_0c08357e;
P_0c083570: /* original e430, guest PC 0x0c083570 */
if(!s->budget--) { s->failed_pc=0x0c083570u; return 0; }
r[4]=0x00000030u;
goto P_0c083572;
P_0c083572: /* original 961e, guest PC 0x0c083572 */
if(!s->budget--) { s->failed_pc=0x0c083572u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0835b2u,2);
goto P_0c083574;
P_0c083574: /* original e433, guest PC 0x0c083574 */
if(!s->budget--) { s->failed_pc=0x0c083574u; return 0; }
r[4]=0x00000033u;
goto P_0c083576;
P_0c083576: /* original 65f2, guest PC 0x0c083576 */
if(!s->budget--) { s->failed_pc=0x0c083576u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c083578;
P_0c083578: /* original 36ec, guest PC 0x0c083578 */
if(!s->budget--) { s->failed_pc=0x0c083578u; return 0; }
r[6]+=r[14];
goto P_0c08357a;
P_0c08357a: /* original 36cc, guest PC 0x0c08357a */
if(!s->budget--) { s->failed_pc=0x0c08357au; return 0; }
r[6]+=r[12];
goto P_0c08357c;
P_0c08357c: /* original 5662, guest PC 0x0c08357c */
if(!s->budget--) { s->failed_pc=0x0c08357cu; return 0; }
r[6]=read(ram,r[6]+8,4);
goto P_0c08357e;
P_0c08357e: /* original d30f, guest PC 0x0c08357e */
if(!s->budget--) { s->failed_pc=0x0c08357eu; return 0; }
r[3]=read(ram,0x0c0835bcu,4);
goto P_0c083580;
P_0c083580: /* original 430b, guest PC 0x0c083580 */
if(!s->budget--) { s->failed_pc=0x0c083580u; return 0; }
target=r[3];
r[16]=code_base|0x0c083584u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c083584u) { target=s->pc; goto dispatch; }
goto P_0c083584;
P_0c083582: /* original 0009, guest PC 0x0c083582 */
if(!s->budget--) { s->failed_pc=0x0c083582u; return 0; }
goto P_0c083584;
P_0c083584: /* original a024, guest PC 0x0c083584 */
if(!s->budget--) { s->failed_pc=0x0c083584u; return 0; }
goto P_0c0835d0;
P_0c083586: /* original 0009, guest PC 0x0c083586 */
if(!s->budget--) { s->failed_pc=0x0c083586u; return 0; }
goto P_0c083588;
P_0c083588: /* original d30b, guest PC 0x0c083588 */
if(!s->budget--) { s->failed_pc=0x0c083588u; return 0; }
r[3]=read(ram,0x0c0835b8u,4);
goto P_0c08358a;
P_0c08358a: /* original 65d3, guest PC 0x0c08358a */
if(!s->budget--) { s->failed_pc=0x0c08358au; return 0; }
r[5]=r[13];
goto P_0c08358c;
P_0c08358c: /* original 9612, guest PC 0x0c08358c */
if(!s->budget--) { s->failed_pc=0x0c08358cu; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0835b4u,2);
goto P_0c08358e;
P_0c08358e: /* original 430b, guest PC 0x0c08358e */
if(!s->budget--) { s->failed_pc=0x0c08358eu; return 0; }
target=r[3];
r[16]=code_base|0x0c083592u;
r[4]=0x00000012u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c083592u) { target=s->pc; goto dispatch; }
goto P_0c083592;
P_0c083590: /* original e412, guest PC 0x0c083590 */
if(!s->budget--) { s->failed_pc=0x0c083590u; return 0; }
r[4]=0x00000012u;
goto P_0c083592;
P_0c083592: /* original d20a, guest PC 0x0c083592 */
if(!s->budget--) { s->failed_pc=0x0c083592u; return 0; }
r[2]=read(ram,0x0c0835bcu,4);
goto P_0c083594;
P_0c083594: /* original 65d3, guest PC 0x0c083594 */
if(!s->budget--) { s->failed_pc=0x0c083594u; return 0; }
r[5]=r[13];
goto P_0c083596;
P_0c083596: /* original e608, guest PC 0x0c083596 */
if(!s->budget--) { s->failed_pc=0x0c083596u; return 0; }
r[6]=0x00000008u;
goto P_0c083598;
P_0c083598: /* original 420b, guest PC 0x0c083598 */
if(!s->budget--) { s->failed_pc=0x0c083598u; return 0; }
target=r[2];
r[16]=code_base|0x0c08359cu;
r[4]=0x00000007u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08359cu) { target=s->pc; goto dispatch; }
goto P_0c08359c;
P_0c08359a: /* original e407, guest PC 0x0c08359a */
if(!s->budget--) { s->failed_pc=0x0c08359au; return 0; }
r[4]=0x00000007u;
goto P_0c08359c;
P_0c08359c: /* original 6392, guest PC 0x0c08359c */
if(!s->budget--) { s->failed_pc=0x0c08359cu; return 0; }
tmp=read(ram,r[9],4);
r[3]=tmp;
goto P_0c08359e;
P_0c08359e: /* original 33b0, guest PC 0x0c08359e */
if(!s->budget--) { s->failed_pc=0x0c08359eu; return 0; }
r[17]=(r[17]&~1u)|((r[3]==r[11])!=0);
goto P_0c0835a0;
P_0c0835a0: /* original 8b10, guest PC 0x0c0835a0 */
if(!s->budget--) { s->failed_pc=0x0c0835a0u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0835c4; }
goto P_0c0835a2;
P_0c0835a2: /* original 55f1, guest PC 0x0c0835a2 */
if(!s->budget--) { s->failed_pc=0x0c0835a2u; return 0; }
r[5]=read(ram,r[15]+4,4);
goto P_0c0835a4;
P_0c0835a4: /* original e608, guest PC 0x0c0835a4 */
if(!s->budget--) { s->failed_pc=0x0c0835a4u; return 0; }
r[6]=0x00000008u;
goto P_0c0835a6;
P_0c0835a6: /* original a010, guest PC 0x0c0835a6 */
if(!s->budget--) { s->failed_pc=0x0c0835a6u; return 0; }
r[4]=0x00000030u;
goto P_0c0835ca;
P_0c0835a8: /* original e430, guest PC 0x0c0835a8 */
if(!s->budget--) { s->failed_pc=0x0c0835a8u; return 0; }
r[4]=0x00000030u;
return vf3_matrix_family(0x0c0835aau,s,ram);
P_0c0835c4: /* original 65f2, guest PC 0x0c0835c4 */
if(!s->budget--) { s->failed_pc=0x0c0835c4u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0835c6;
P_0c0835c6: /* original e433, guest PC 0x0c0835c6 */
if(!s->budget--) { s->failed_pc=0x0c0835c6u; return 0; }
r[4]=0x00000033u;
goto P_0c0835c8;
P_0c0835c8: /* original e608, guest PC 0x0c0835c8 */
if(!s->budget--) { s->failed_pc=0x0c0835c8u; return 0; }
r[6]=0x00000008u;
goto P_0c0835ca;
P_0c0835ca: /* original d346, guest PC 0x0c0835ca */
if(!s->budget--) { s->failed_pc=0x0c0835cau; return 0; }
r[3]=read(ram,0x0c0836e4u,4);
goto P_0c0835cc;
P_0c0835cc: /* original 430b, guest PC 0x0c0835cc */
if(!s->budget--) { s->failed_pc=0x0c0835ccu; return 0; }
target=r[3];
r[16]=code_base|0x0c0835d0u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0835d0u) { target=s->pc; goto dispatch; }
goto P_0c0835d0;
P_0c0835ce: /* original 0009, guest PC 0x0c0835ce */
if(!s->budget--) { s->failed_pc=0x0c0835ceu; return 0; }
goto P_0c0835d0;
P_0c0835d0: /* original 6292, guest PC 0x0c0835d0 */
if(!s->budget--) { s->failed_pc=0x0c0835d0u; return 0; }
tmp=read(ram,r[9],4);
r[2]=tmp;
goto P_0c0835d2;
P_0c0835d2: /* original 32b0, guest PC 0x0c0835d2 */
if(!s->budget--) { s->failed_pc=0x0c0835d2u; return 0; }
r[17]=(r[17]&~1u)|((r[2]==r[11])!=0);
goto P_0c0835d4;
P_0c0835d4: /* original 8b4b, guest PC 0x0c0835d4 */
if(!s->budget--) { s->failed_pc=0x0c0835d4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c08366e; }
goto P_0c0835d6;
P_0c0835d6: /* original 937e, guest PC 0x0c0835d6 */
if(!s->budget--) { s->failed_pc=0x0c0835d6u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0836d6u,2);
goto P_0c0835d8;
P_0c0835d8: /* original 60a3, guest PC 0x0c0835d8 */
if(!s->budget--) { s->failed_pc=0x0c0835d8u; return 0; }
r[0]=r[10];
goto P_0c0835da;
P_0c0835da: /* original 4008, guest PC 0x0c0835da */
if(!s->budget--) { s->failed_pc=0x0c0835dau; return 0; }
r[0]<<=2;
goto P_0c0835dc;
P_0c0835dc: /* original 33ec, guest PC 0x0c0835dc */
if(!s->budget--) { s->failed_pc=0x0c0835dcu; return 0; }
r[3]+=r[14];
goto P_0c0835de;
P_0c0835de: /* original 003e, guest PC 0x0c0835de */
if(!s->budget--) { s->failed_pc=0x0c0835deu; return 0; }
r[0]=read(ram,r[3]+r[0],4);
goto P_0c0835e0;
P_0c0835e0: /* original 8801, guest PC 0x0c0835e0 */
if(!s->budget--) { s->failed_pc=0x0c0835e0u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c0835e2;
P_0c0835e2: /* original 8f35, guest PC 0x0c0835e2 */
if(!s->budget--) { s->failed_pc=0x0c0835e2u; return 0; }
cond=r[17]&1u;
r[13]+=0x00000002u;
if(!cond) { goto P_0c083650; }
goto P_0c0835e6;
P_0c0835e4: /* original 7d02, guest PC 0x0c0835e4 */
if(!s->budget--) { s->failed_pc=0x0c0835e4u; return 0; }
r[13]+=0x00000002u;
goto P_0c0835e6;
P_0c0835e6: /* original 9377, guest PC 0x0c0835e6 */
if(!s->budget--) { s->failed_pc=0x0c0835e6u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0836d8u,2);
goto P_0c0835e8;
P_0c0835e8: /* original 60a3, guest PC 0x0c0835e8 */
if(!s->budget--) { s->failed_pc=0x0c0835e8u; return 0; }
r[0]=r[10];
goto P_0c0835ea;
P_0c0835ea: /* original 4008, guest PC 0x0c0835ea */
if(!s->budget--) { s->failed_pc=0x0c0835eau; return 0; }
r[0]<<=2;
goto P_0c0835ec;
P_0c0835ec: /* original 33ec, guest PC 0x0c0835ec */
if(!s->budget--) { s->failed_pc=0x0c0835ecu; return 0; }
r[3]+=r[14];
goto P_0c0835ee;
P_0c0835ee: /* original 003e, guest PC 0x0c0835ee */
if(!s->budget--) { s->failed_pc=0x0c0835eeu; return 0; }
r[0]=read(ram,r[3]+r[0],4);
goto P_0c0835f0;
P_0c0835f0: /* original 8803, guest PC 0x0c0835f0 */
if(!s->budget--) { s->failed_pc=0x0c0835f0u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000003u)!=0);
goto P_0c0835f2;
P_0c0835f2: /* original 8b16, guest PC 0x0c0835f2 */
if(!s->budget--) { s->failed_pc=0x0c0835f2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c083622; }
goto P_0c0835f4;
P_0c0835f4: /* original d33c, guest PC 0x0c0835f4 */
if(!s->budget--) { s->failed_pc=0x0c0835f4u; return 0; }
r[3]=read(ram,0x0c0836e8u,4);
goto P_0c0835f6;
P_0c0835f6: /* original 65d3, guest PC 0x0c0835f6 */
if(!s->budget--) { s->failed_pc=0x0c0835f6u; return 0; }
r[5]=r[13];
goto P_0c0835f8;
P_0c0835f8: /* original 966f, guest PC 0x0c0835f8 */
if(!s->budget--) { s->failed_pc=0x0c0835f8u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0836dau,2);
goto P_0c0835fa;
P_0c0835fa: /* original 430b, guest PC 0x0c0835fa */
if(!s->budget--) { s->failed_pc=0x0c0835fau; return 0; }
target=r[3];
r[16]=code_base|0x0c0835feu;
r[4]=0x00000012u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0835feu) { target=s->pc; goto dispatch; }
goto P_0c0835fe;
P_0c0835fc: /* original e412, guest PC 0x0c0835fc */
if(!s->budget--) { s->failed_pc=0x0c0835fcu; return 0; }
r[4]=0x00000012u;
goto P_0c0835fe;
P_0c0835fe: /* original 966d, guest PC 0x0c0835fe */
if(!s->budget--) { s->failed_pc=0x0c0835feu; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0836dcu,2);
goto P_0c083600;
P_0c083600: /* original 65d3, guest PC 0x0c083600 */
if(!s->budget--) { s->failed_pc=0x0c083600u; return 0; }
r[5]=r[13];
goto P_0c083602;
P_0c083602: /* original d33a, guest PC 0x0c083602 */
if(!s->budget--) { s->failed_pc=0x0c083602u; return 0; }
r[3]=read(ram,0x0c0836ecu,4);
goto P_0c083604;
P_0c083604: /* original 36ec, guest PC 0x0c083604 */
if(!s->budget--) { s->failed_pc=0x0c083604u; return 0; }
r[6]+=r[14];
goto P_0c083606;
P_0c083606: /* original 36cc, guest PC 0x0c083606 */
if(!s->budget--) { s->failed_pc=0x0c083606u; return 0; }
r[6]+=r[12];
goto P_0c083608;
P_0c083608: /* original 5663, guest PC 0x0c083608 */
if(!s->budget--) { s->failed_pc=0x0c083608u; return 0; }
r[6]=read(ram,r[6]+12,4);
goto P_0c08360a;
P_0c08360a: /* original 430b, guest PC 0x0c08360a */
if(!s->budget--) { s->failed_pc=0x0c08360au; return 0; }
target=r[3];
r[16]=code_base|0x0c08360eu;
r[4]=0x00000014u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08360eu) { target=s->pc; goto dispatch; }
goto P_0c08360e;
P_0c08360c: /* original e414, guest PC 0x0c08360c */
if(!s->budget--) { s->failed_pc=0x0c08360cu; return 0; }
r[4]=0x00000014u;
goto P_0c08360e;
P_0c08360e: /* original 9665, guest PC 0x0c08360e */
if(!s->budget--) { s->failed_pc=0x0c08360eu; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0836dcu,2);
goto P_0c083610;
P_0c083610: /* original d336, guest PC 0x0c083610 */
if(!s->budget--) { s->failed_pc=0x0c083610u; return 0; }
r[3]=read(ram,0x0c0836ecu,4);
goto P_0c083612;
P_0c083612: /* original 36ec, guest PC 0x0c083612 */
if(!s->budget--) { s->failed_pc=0x0c083612u; return 0; }
r[6]+=r[14];
goto P_0c083614;
P_0c083614: /* original 65f2, guest PC 0x0c083614 */
if(!s->budget--) { s->failed_pc=0x0c083614u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c083616;
P_0c083616: /* original 36cc, guest PC 0x0c083616 */
if(!s->budget--) { s->failed_pc=0x0c083616u; return 0; }
r[6]+=r[12];
goto P_0c083618;
P_0c083618: /* original 5663, guest PC 0x0c083618 */
if(!s->budget--) { s->failed_pc=0x0c083618u; return 0; }
r[6]=read(ram,r[6]+12,4);
goto P_0c08361a;
P_0c08361a: /* original 430b, guest PC 0x0c08361a */
if(!s->budget--) { s->failed_pc=0x0c08361au; return 0; }
target=r[3];
r[16]=code_base|0x0c08361eu;
r[4]=0x00000034u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08361eu) { target=s->pc; goto dispatch; }
goto P_0c08361e;
P_0c08361c: /* original e434, guest PC 0x0c08361c */
if(!s->budget--) { s->failed_pc=0x0c08361cu; return 0; }
r[4]=0x00000034u;
goto P_0c08361e;
P_0c08361e: /* original a026, guest PC 0x0c08361e */
if(!s->budget--) { s->failed_pc=0x0c08361eu; return 0; }
goto P_0c08366e;
P_0c083620: /* original 0009, guest PC 0x0c083620 */
if(!s->budget--) { s->failed_pc=0x0c083620u; return 0; }
goto P_0c083622;
P_0c083622: /* original d331, guest PC 0x0c083622 */
if(!s->budget--) { s->failed_pc=0x0c083622u; return 0; }
r[3]=read(ram,0x0c0836e8u,4);
goto P_0c083624;
P_0c083624: /* original 65d3, guest PC 0x0c083624 */
if(!s->budget--) { s->failed_pc=0x0c083624u; return 0; }
r[5]=r[13];
goto P_0c083626;
P_0c083626: /* original 965a, guest PC 0x0c083626 */
if(!s->budget--) { s->failed_pc=0x0c083626u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0836deu,2);
goto P_0c083628;
P_0c083628: /* original 430b, guest PC 0x0c083628 */
if(!s->budget--) { s->failed_pc=0x0c083628u; return 0; }
target=r[3];
r[16]=code_base|0x0c08362cu;
r[4]=0x00000012u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08362cu) { target=s->pc; goto dispatch; }
goto P_0c08362c;
P_0c08362a: /* original e412, guest PC 0x0c08362a */
if(!s->budget--) { s->failed_pc=0x0c08362au; return 0; }
r[4]=0x00000012u;
goto P_0c08362c;
P_0c08362c: /* original 9656, guest PC 0x0c08362c */
if(!s->budget--) { s->failed_pc=0x0c08362cu; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0836dcu,2);
goto P_0c08362e;
P_0c08362e: /* original 65d3, guest PC 0x0c08362e */
if(!s->budget--) { s->failed_pc=0x0c08362eu; return 0; }
r[5]=r[13];
goto P_0c083630;
P_0c083630: /* original d32c, guest PC 0x0c083630 */
if(!s->budget--) { s->failed_pc=0x0c083630u; return 0; }
r[3]=read(ram,0x0c0836e4u,4);
goto P_0c083632;
P_0c083632: /* original 36ec, guest PC 0x0c083632 */
if(!s->budget--) { s->failed_pc=0x0c083632u; return 0; }
r[6]+=r[14];
goto P_0c083634;
P_0c083634: /* original 36cc, guest PC 0x0c083634 */
if(!s->budget--) { s->failed_pc=0x0c083634u; return 0; }
r[6]+=r[12];
goto P_0c083636;
P_0c083636: /* original 5663, guest PC 0x0c083636 */
if(!s->budget--) { s->failed_pc=0x0c083636u; return 0; }
r[6]=read(ram,r[6]+12,4);
goto P_0c083638;
P_0c083638: /* original 430b, guest PC 0x0c083638 */
if(!s->budget--) { s->failed_pc=0x0c083638u; return 0; }
target=r[3];
r[16]=code_base|0x0c08363cu;
r[4]=0x00000014u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08363cu) { target=s->pc; goto dispatch; }
goto P_0c08363c;
P_0c08363a: /* original e414, guest PC 0x0c08363a */
if(!s->budget--) { s->failed_pc=0x0c08363au; return 0; }
r[4]=0x00000014u;
goto P_0c08363c;
P_0c08363c: /* original 964e, guest PC 0x0c08363c */
if(!s->budget--) { s->failed_pc=0x0c08363cu; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0836dcu,2);
goto P_0c08363e;
P_0c08363e: /* original d329, guest PC 0x0c08363e */
if(!s->budget--) { s->failed_pc=0x0c08363eu; return 0; }
r[3]=read(ram,0x0c0836e4u,4);
goto P_0c083640;
P_0c083640: /* original 36ec, guest PC 0x0c083640 */
if(!s->budget--) { s->failed_pc=0x0c083640u; return 0; }
r[6]+=r[14];
goto P_0c083642;
P_0c083642: /* original 65f2, guest PC 0x0c083642 */
if(!s->budget--) { s->failed_pc=0x0c083642u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c083644;
P_0c083644: /* original 36cc, guest PC 0x0c083644 */
if(!s->budget--) { s->failed_pc=0x0c083644u; return 0; }
r[6]+=r[12];
goto P_0c083646;
P_0c083646: /* original 5663, guest PC 0x0c083646 */
if(!s->budget--) { s->failed_pc=0x0c083646u; return 0; }
r[6]=read(ram,r[6]+12,4);
goto P_0c083648;
P_0c083648: /* original 430b, guest PC 0x0c083648 */
if(!s->budget--) { s->failed_pc=0x0c083648u; return 0; }
target=r[3];
r[16]=code_base|0x0c08364cu;
r[4]=0x00000034u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08364cu) { target=s->pc; goto dispatch; }
goto P_0c08364c;
P_0c08364a: /* original e434, guest PC 0x0c08364a */
if(!s->budget--) { s->failed_pc=0x0c08364au; return 0; }
r[4]=0x00000034u;
goto P_0c08364c;
P_0c08364c: /* original a00f, guest PC 0x0c08364c */
if(!s->budget--) { s->failed_pc=0x0c08364cu; return 0; }
goto P_0c08366e;
P_0c08364e: /* original 0009, guest PC 0x0c08364e */
if(!s->budget--) { s->failed_pc=0x0c08364eu; return 0; }
goto P_0c083650;
P_0c083650: /* original d325, guest PC 0x0c083650 */
if(!s->budget--) { s->failed_pc=0x0c083650u; return 0; }
r[3]=read(ram,0x0c0836e8u,4);
goto P_0c083652;
P_0c083652: /* original 65d3, guest PC 0x0c083652 */
if(!s->budget--) { s->failed_pc=0x0c083652u; return 0; }
r[5]=r[13];
goto P_0c083654;
P_0c083654: /* original 9643, guest PC 0x0c083654 */
if(!s->budget--) { s->failed_pc=0x0c083654u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0836deu,2);
goto P_0c083656;
P_0c083656: /* original 430b, guest PC 0x0c083656 */
if(!s->budget--) { s->failed_pc=0x0c083656u; return 0; }
target=r[3];
r[16]=code_base|0x0c08365au;
r[4]=0x00000012u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08365au) { target=s->pc; goto dispatch; }
goto P_0c08365a;
P_0c083658: /* original e412, guest PC 0x0c083658 */
if(!s->budget--) { s->failed_pc=0x0c083658u; return 0; }
r[4]=0x00000012u;
goto P_0c08365a;
P_0c08365a: /* original d222, guest PC 0x0c08365a */
if(!s->budget--) { s->failed_pc=0x0c08365au; return 0; }
r[2]=read(ram,0x0c0836e4u,4);
goto P_0c08365c;
P_0c08365c: /* original 65d3, guest PC 0x0c08365c */
if(!s->budget--) { s->failed_pc=0x0c08365cu; return 0; }
r[5]=r[13];
goto P_0c08365e;
P_0c08365e: /* original e610, guest PC 0x0c08365e */
if(!s->budget--) { s->failed_pc=0x0c08365eu; return 0; }
r[6]=0x00000010u;
goto P_0c083660;
P_0c083660: /* original 420b, guest PC 0x0c083660 */
if(!s->budget--) { s->failed_pc=0x0c083660u; return 0; }
target=r[2];
r[16]=code_base|0x0c083664u;
r[4]=0x00000007u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c083664u) { target=s->pc; goto dispatch; }
goto P_0c083664;
P_0c083662: /* original e407, guest PC 0x0c083662 */
if(!s->budget--) { s->failed_pc=0x0c083662u; return 0; }
r[4]=0x00000007u;
goto P_0c083664;
P_0c083664: /* original d31f, guest PC 0x0c083664 */
if(!s->budget--) { s->failed_pc=0x0c083664u; return 0; }
r[3]=read(ram,0x0c0836e4u,4);
goto P_0c083666;
P_0c083666: /* original e610, guest PC 0x0c083666 */
if(!s->budget--) { s->failed_pc=0x0c083666u; return 0; }
r[6]=0x00000010u;
goto P_0c083668;
P_0c083668: /* original 65f2, guest PC 0x0c083668 */
if(!s->budget--) { s->failed_pc=0x0c083668u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c08366a;
P_0c08366a: /* original 430b, guest PC 0x0c08366a */
if(!s->budget--) { s->failed_pc=0x0c08366au; return 0; }
target=r[3];
r[16]=code_base|0x0c08366eu;
r[4]=0x00000034u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08366eu) { target=s->pc; goto dispatch; }
goto P_0c08366e;
P_0c08366c: /* original e434, guest PC 0x0c08366c */
if(!s->budget--) { s->failed_pc=0x0c08366cu; return 0; }
r[4]=0x00000034u;
goto P_0c08366e;
P_0c08366e: /* original 60a3, guest PC 0x0c08366e */
if(!s->budget--) { s->failed_pc=0x0c08366eu; return 0; }
r[0]=r[10];
goto P_0c083670;
P_0c083670: /* original 4008, guest PC 0x0c083670 */
if(!s->budget--) { s->failed_pc=0x0c083670u; return 0; }
r[0]<<=2;
goto P_0c083672;
P_0c083672: /* original 6283, guest PC 0x0c083672 */
if(!s->budget--) { s->failed_pc=0x0c083672u; return 0; }
r[2]=r[8];
goto P_0c083674;
P_0c083674: /* original 720c, guest PC 0x0c083674 */
if(!s->budget--) { s->failed_pc=0x0c083674u; return 0; }
r[2]+=0x0000000cu;
goto P_0c083676;
P_0c083676: /* original 1f21, guest PC 0x0c083676 */
if(!s->budget--) { s->failed_pc=0x0c083676u; return 0; }
write(ram,r[15]+4,r[2],4);
goto P_0c083678;
P_0c083678: /* original 932d, guest PC 0x0c083678 */
if(!s->budget--) { s->failed_pc=0x0c083678u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0836d6u,2);
goto P_0c08367a;
P_0c08367a: /* original 33ec, guest PC 0x0c08367a */
if(!s->budget--) { s->failed_pc=0x0c08367au; return 0; }
r[3]+=r[14];
goto P_0c08367c;
P_0c08367c: /* original 003e, guest PC 0x0c08367c */
if(!s->budget--) { s->failed_pc=0x0c08367cu; return 0; }
r[0]=read(ram,r[3]+r[0],4);
goto P_0c08367e;
P_0c08367e: /* original 8801, guest PC 0x0c08367e */
if(!s->budget--) { s->failed_pc=0x0c08367eu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c083680;
P_0c083680: /* original 8f58, guest PC 0x0c083680 */
if(!s->budget--) { s->failed_pc=0x0c083680u; return 0; }
cond=r[17]&1u;
r[13]+=0x00000002u;
if(!cond) { goto P_0c083734; }
goto P_0c083684;
P_0c083682: /* original 7d02, guest PC 0x0c083682 */
if(!s->budget--) { s->failed_pc=0x0c083682u; return 0; }
r[13]+=0x00000002u;
goto P_0c083684;
P_0c083684: /* original 9328, guest PC 0x0c083684 */
if(!s->budget--) { s->failed_pc=0x0c083684u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0836d8u,2);
goto P_0c083686;
P_0c083686: /* original 60a3, guest PC 0x0c083686 */
if(!s->budget--) { s->failed_pc=0x0c083686u; return 0; }
r[0]=r[10];
goto P_0c083688;
P_0c083688: /* original 4008, guest PC 0x0c083688 */
if(!s->budget--) { s->failed_pc=0x0c083688u; return 0; }
r[0]<<=2;
goto P_0c08368a;
P_0c08368a: /* original 33ec, guest PC 0x0c08368a */
if(!s->budget--) { s->failed_pc=0x0c08368au; return 0; }
r[3]+=r[14];
goto P_0c08368c;
P_0c08368c: /* original 003e, guest PC 0x0c08368c */
if(!s->budget--) { s->failed_pc=0x0c08368cu; return 0; }
r[0]=read(ram,r[3]+r[0],4);
goto P_0c08368e;
P_0c08368e: /* original 8804, guest PC 0x0c08368e */
if(!s->budget--) { s->failed_pc=0x0c08368eu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000004u)!=0);
goto P_0c083690;
P_0c083690: /* original 8b2e, guest PC 0x0c083690 */
if(!s->budget--) { s->failed_pc=0x0c083690u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0836f0; }
goto P_0c083692;
P_0c083692: /* original d315, guest PC 0x0c083692 */
if(!s->budget--) { s->failed_pc=0x0c083692u; return 0; }
r[3]=read(ram,0x0c0836e8u,4);
goto P_0c083694;
P_0c083694: /* original 65d3, guest PC 0x0c083694 */
if(!s->budget--) { s->failed_pc=0x0c083694u; return 0; }
r[5]=r[13];
goto P_0c083696;
P_0c083696: /* original 9623, guest PC 0x0c083696 */
if(!s->budget--) { s->failed_pc=0x0c083696u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0836e0u,2);
goto P_0c083698;
P_0c083698: /* original 430b, guest PC 0x0c083698 */
if(!s->budget--) { s->failed_pc=0x0c083698u; return 0; }
target=r[3];
r[16]=code_base|0x0c08369cu;
r[4]=0x00000012u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08369cu) { target=s->pc; goto dispatch; }
goto P_0c08369c;
P_0c08369a: /* original e412, guest PC 0x0c08369a */
if(!s->budget--) { s->failed_pc=0x0c08369au; return 0; }
r[4]=0x00000012u;
goto P_0c08369c;
P_0c08369c: /* original 961e, guest PC 0x0c08369c */
if(!s->budget--) { s->failed_pc=0x0c08369cu; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0836dcu,2);
goto P_0c08369e;
P_0c08369e: /* original 65d3, guest PC 0x0c08369e */
if(!s->budget--) { s->failed_pc=0x0c08369eu; return 0; }
r[5]=r[13];
goto P_0c0836a0;
P_0c0836a0: /* original d312, guest PC 0x0c0836a0 */
if(!s->budget--) { s->failed_pc=0x0c0836a0u; return 0; }
r[3]=read(ram,0x0c0836ecu,4);
goto P_0c0836a2;
P_0c0836a2: /* original 36ec, guest PC 0x0c0836a2 */
if(!s->budget--) { s->failed_pc=0x0c0836a2u; return 0; }
r[6]+=r[14];
goto P_0c0836a4;
P_0c0836a4: /* original 36cc, guest PC 0x0c0836a4 */
if(!s->budget--) { s->failed_pc=0x0c0836a4u; return 0; }
r[6]+=r[12];
goto P_0c0836a6;
P_0c0836a6: /* original 5664, guest PC 0x0c0836a6 */
if(!s->budget--) { s->failed_pc=0x0c0836a6u; return 0; }
r[6]=read(ram,r[6]+16,4);
goto P_0c0836a8;
P_0c0836a8: /* original 430b, guest PC 0x0c0836a8 */
if(!s->budget--) { s->failed_pc=0x0c0836a8u; return 0; }
target=r[3];
r[16]=code_base|0x0c0836acu;
r[4]=0x00000014u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0836acu) { target=s->pc; goto dispatch; }
goto P_0c0836ac;
P_0c0836aa: /* original e414, guest PC 0x0c0836aa */
if(!s->budget--) { s->failed_pc=0x0c0836aau; return 0; }
r[4]=0x00000014u;
goto P_0c0836ac;
P_0c0836ac: /* original 6292, guest PC 0x0c0836ac */
if(!s->budget--) { s->failed_pc=0x0c0836acu; return 0; }
tmp=read(ram,r[9],4);
r[2]=tmp;
goto P_0c0836ae;
P_0c0836ae: /* original 32b0, guest PC 0x0c0836ae */
if(!s->budget--) { s->failed_pc=0x0c0836aeu; return 0; }
r[17]=(r[17]&~1u)|((r[2]==r[11])!=0);
goto P_0c0836b0;
P_0c0836b0: /* original 8b06, guest PC 0x0c0836b0 */
if(!s->budget--) { s->failed_pc=0x0c0836b0u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0836c0; }
goto P_0c0836b2;
P_0c0836b2: /* original 9613, guest PC 0x0c0836b2 */
if(!s->budget--) { s->failed_pc=0x0c0836b2u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0836dcu,2);
goto P_0c0836b4;
P_0c0836b4: /* original 55f1, guest PC 0x0c0836b4 */
if(!s->budget--) { s->failed_pc=0x0c0836b4u; return 0; }
r[5]=read(ram,r[15]+4,4);
goto P_0c0836b6;
P_0c0836b6: /* original 36ec, guest PC 0x0c0836b6 */
if(!s->budget--) { s->failed_pc=0x0c0836b6u; return 0; }
r[6]+=r[14];
goto P_0c0836b8;
P_0c0836b8: /* original 36cc, guest PC 0x0c0836b8 */
if(!s->budget--) { s->failed_pc=0x0c0836b8u; return 0; }
r[6]+=r[12];
goto P_0c0836ba;
P_0c0836ba: /* original 5664, guest PC 0x0c0836ba */
if(!s->budget--) { s->failed_pc=0x0c0836bau; return 0; }
r[6]=read(ram,r[6]+16,4);
goto P_0c0836bc;
P_0c0836bc: /* original a006, guest PC 0x0c0836bc */
if(!s->budget--) { s->failed_pc=0x0c0836bcu; return 0; }
r[4]=0x00000027u;
goto P_0c0836cc;
P_0c0836be: /* original e427, guest PC 0x0c0836be */
if(!s->budget--) { s->failed_pc=0x0c0836beu; return 0; }
r[4]=0x00000027u;
goto P_0c0836c0;
P_0c0836c0: /* original 960c, guest PC 0x0c0836c0 */
if(!s->budget--) { s->failed_pc=0x0c0836c0u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0836dcu,2);
goto P_0c0836c2;
P_0c0836c2: /* original e428, guest PC 0x0c0836c2 */
if(!s->budget--) { s->failed_pc=0x0c0836c2u; return 0; }
r[4]=0x00000028u;
goto P_0c0836c4;
P_0c0836c4: /* original 65f2, guest PC 0x0c0836c4 */
if(!s->budget--) { s->failed_pc=0x0c0836c4u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0836c6;
P_0c0836c6: /* original 36ec, guest PC 0x0c0836c6 */
if(!s->budget--) { s->failed_pc=0x0c0836c6u; return 0; }
r[6]+=r[14];
goto P_0c0836c8;
P_0c0836c8: /* original 36cc, guest PC 0x0c0836c8 */
if(!s->budget--) { s->failed_pc=0x0c0836c8u; return 0; }
r[6]+=r[12];
goto P_0c0836ca;
P_0c0836ca: /* original 5664, guest PC 0x0c0836ca */
if(!s->budget--) { s->failed_pc=0x0c0836cau; return 0; }
r[6]=read(ram,r[6]+16,4);
goto P_0c0836cc;
P_0c0836cc: /* original d307, guest PC 0x0c0836cc */
if(!s->budget--) { s->failed_pc=0x0c0836ccu; return 0; }
r[3]=read(ram,0x0c0836ecu,4);
goto P_0c0836ce;
P_0c0836ce: /* original 430b, guest PC 0x0c0836ce */
if(!s->budget--) { s->failed_pc=0x0c0836ceu; return 0; }
target=r[3];
r[16]=code_base|0x0c0836d2u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0836d2u) { target=s->pc; goto dispatch; }
goto P_0c0836d2;
P_0c0836d0: /* original 0009, guest PC 0x0c0836d0 */
if(!s->budget--) { s->failed_pc=0x0c0836d0u; return 0; }
goto P_0c0836d2;
P_0c0836d2: /* original a046, guest PC 0x0c0836d2 */
if(!s->budget--) { s->failed_pc=0x0c0836d2u; return 0; }
goto P_0c083762;
P_0c0836d4: /* original 0009, guest PC 0x0c0836d4 */
if(!s->budget--) { s->failed_pc=0x0c0836d4u; return 0; }
return vf3_matrix_family(0x0c0836d6u,s,ram);
P_0c0836f0: /* original d343, guest PC 0x0c0836f0 */
if(!s->budget--) { s->failed_pc=0x0c0836f0u; return 0; }
r[3]=read(ram,0x0c083800u,4);
goto P_0c0836f2;
P_0c0836f2: /* original 65d3, guest PC 0x0c0836f2 */
if(!s->budget--) { s->failed_pc=0x0c0836f2u; return 0; }
r[5]=r[13];
goto P_0c0836f4;
P_0c0836f4: /* original 967d, guest PC 0x0c0836f4 */
if(!s->budget--) { s->failed_pc=0x0c0836f4u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0837f2u,2);
goto P_0c0836f6;
P_0c0836f6: /* original 430b, guest PC 0x0c0836f6 */
if(!s->budget--) { s->failed_pc=0x0c0836f6u; return 0; }
target=r[3];
r[16]=code_base|0x0c0836fau;
r[4]=0x00000012u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0836fau) { target=s->pc; goto dispatch; }
goto P_0c0836fa;
P_0c0836f8: /* original e412, guest PC 0x0c0836f8 */
if(!s->budget--) { s->failed_pc=0x0c0836f8u; return 0; }
r[4]=0x00000012u;
goto P_0c0836fa;
P_0c0836fa: /* original 967b, guest PC 0x0c0836fa */
if(!s->budget--) { s->failed_pc=0x0c0836fau; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0837f4u,2);
goto P_0c0836fc;
P_0c0836fc: /* original 65d3, guest PC 0x0c0836fc */
if(!s->budget--) { s->failed_pc=0x0c0836fcu; return 0; }
r[5]=r[13];
goto P_0c0836fe;
P_0c0836fe: /* original d341, guest PC 0x0c0836fe */
if(!s->budget--) { s->failed_pc=0x0c0836feu; return 0; }
r[3]=read(ram,0x0c083804u,4);
goto P_0c083700;
P_0c083700: /* original 36ec, guest PC 0x0c083700 */
if(!s->budget--) { s->failed_pc=0x0c083700u; return 0; }
r[6]+=r[14];
goto P_0c083702;
P_0c083702: /* original 36cc, guest PC 0x0c083702 */
if(!s->budget--) { s->failed_pc=0x0c083702u; return 0; }
r[6]+=r[12];
goto P_0c083704;
P_0c083704: /* original 5664, guest PC 0x0c083704 */
if(!s->budget--) { s->failed_pc=0x0c083704u; return 0; }
r[6]=read(ram,r[6]+16,4);
goto P_0c083706;
P_0c083706: /* original 430b, guest PC 0x0c083706 */
if(!s->budget--) { s->failed_pc=0x0c083706u; return 0; }
target=r[3];
r[16]=code_base|0x0c08370au;
r[4]=0x00000014u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08370au) { target=s->pc; goto dispatch; }
goto P_0c08370a;
P_0c083708: /* original e414, guest PC 0x0c083708 */
if(!s->budget--) { s->failed_pc=0x0c083708u; return 0; }
r[4]=0x00000014u;
goto P_0c08370a;
P_0c08370a: /* original 6292, guest PC 0x0c08370a */
if(!s->budget--) { s->failed_pc=0x0c08370au; return 0; }
tmp=read(ram,r[9],4);
r[2]=tmp;
goto P_0c08370c;
P_0c08370c: /* original 32b0, guest PC 0x0c08370c */
if(!s->budget--) { s->failed_pc=0x0c08370cu; return 0; }
r[17]=(r[17]&~1u)|((r[2]==r[11])!=0);
goto P_0c08370e;
P_0c08370e: /* original 8b06, guest PC 0x0c08370e */
if(!s->budget--) { s->failed_pc=0x0c08370eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c08371e; }
goto P_0c083710;
P_0c083710: /* original 9670, guest PC 0x0c083710 */
if(!s->budget--) { s->failed_pc=0x0c083710u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0837f4u,2);
goto P_0c083712;
P_0c083712: /* original 55f1, guest PC 0x0c083712 */
if(!s->budget--) { s->failed_pc=0x0c083712u; return 0; }
r[5]=read(ram,r[15]+4,4);
goto P_0c083714;
P_0c083714: /* original 36ec, guest PC 0x0c083714 */
if(!s->budget--) { s->failed_pc=0x0c083714u; return 0; }
r[6]+=r[14];
goto P_0c083716;
P_0c083716: /* original 36cc, guest PC 0x0c083716 */
if(!s->budget--) { s->failed_pc=0x0c083716u; return 0; }
r[6]+=r[12];
goto P_0c083718;
P_0c083718: /* original 5664, guest PC 0x0c083718 */
if(!s->budget--) { s->failed_pc=0x0c083718u; return 0; }
r[6]=read(ram,r[6]+16,4);
goto P_0c08371a;
P_0c08371a: /* original a006, guest PC 0x0c08371a */
if(!s->budget--) { s->failed_pc=0x0c08371au; return 0; }
r[4]=0x00000027u;
goto P_0c08372a;
P_0c08371c: /* original e427, guest PC 0x0c08371c */
if(!s->budget--) { s->failed_pc=0x0c08371cu; return 0; }
r[4]=0x00000027u;
goto P_0c08371e;
P_0c08371e: /* original 9669, guest PC 0x0c08371e */
if(!s->budget--) { s->failed_pc=0x0c08371eu; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0837f4u,2);
goto P_0c083720;
P_0c083720: /* original e428, guest PC 0x0c083720 */
if(!s->budget--) { s->failed_pc=0x0c083720u; return 0; }
r[4]=0x00000028u;
goto P_0c083722;
P_0c083722: /* original 65f2, guest PC 0x0c083722 */
if(!s->budget--) { s->failed_pc=0x0c083722u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c083724;
P_0c083724: /* original 36ec, guest PC 0x0c083724 */
if(!s->budget--) { s->failed_pc=0x0c083724u; return 0; }
r[6]+=r[14];
goto P_0c083726;
P_0c083726: /* original 36cc, guest PC 0x0c083726 */
if(!s->budget--) { s->failed_pc=0x0c083726u; return 0; }
r[6]+=r[12];
goto P_0c083728;
P_0c083728: /* original 5664, guest PC 0x0c083728 */
if(!s->budget--) { s->failed_pc=0x0c083728u; return 0; }
r[6]=read(ram,r[6]+16,4);
goto P_0c08372a;
P_0c08372a: /* original d336, guest PC 0x0c08372a */
if(!s->budget--) { s->failed_pc=0x0c08372au; return 0; }
r[3]=read(ram,0x0c083804u,4);
goto P_0c08372c;
P_0c08372c: /* original 430b, guest PC 0x0c08372c */
if(!s->budget--) { s->failed_pc=0x0c08372cu; return 0; }
target=r[3];
r[16]=code_base|0x0c083730u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c083730u) { target=s->pc; goto dispatch; }
goto P_0c083730;
P_0c08372e: /* original 0009, guest PC 0x0c08372e */
if(!s->budget--) { s->failed_pc=0x0c08372eu; return 0; }
goto P_0c083730;
P_0c083730: /* original a017, guest PC 0x0c083730 */
if(!s->budget--) { s->failed_pc=0x0c083730u; return 0; }
goto P_0c083762;
P_0c083732: /* original 0009, guest PC 0x0c083732 */
if(!s->budget--) { s->failed_pc=0x0c083732u; return 0; }
goto P_0c083734;
P_0c083734: /* original d332, guest PC 0x0c083734 */
if(!s->budget--) { s->failed_pc=0x0c083734u; return 0; }
r[3]=read(ram,0x0c083800u,4);
goto P_0c083736;
P_0c083736: /* original 65d3, guest PC 0x0c083736 */
if(!s->budget--) { s->failed_pc=0x0c083736u; return 0; }
r[5]=r[13];
goto P_0c083738;
P_0c083738: /* original 965b, guest PC 0x0c083738 */
if(!s->budget--) { s->failed_pc=0x0c083738u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0837f2u,2);
goto P_0c08373a;
P_0c08373a: /* original 430b, guest PC 0x0c08373a */
if(!s->budget--) { s->failed_pc=0x0c08373au; return 0; }
target=r[3];
r[16]=code_base|0x0c08373eu;
r[4]=0x00000012u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08373eu) { target=s->pc; goto dispatch; }
goto P_0c08373e;
P_0c08373c: /* original e412, guest PC 0x0c08373c */
if(!s->budget--) { s->failed_pc=0x0c08373cu; return 0; }
r[4]=0x00000012u;
goto P_0c08373e;
P_0c08373e: /* original d231, guest PC 0x0c08373e */
if(!s->budget--) { s->failed_pc=0x0c08373eu; return 0; }
r[2]=read(ram,0x0c083804u,4);
goto P_0c083740;
P_0c083740: /* original 65d3, guest PC 0x0c083740 */
if(!s->budget--) { s->failed_pc=0x0c083740u; return 0; }
r[5]=r[13];
goto P_0c083742;
P_0c083742: /* original e601, guest PC 0x0c083742 */
if(!s->budget--) { s->failed_pc=0x0c083742u; return 0; }
r[6]=0x00000001u;
goto P_0c083744;
P_0c083744: /* original 420b, guest PC 0x0c083744 */
if(!s->budget--) { s->failed_pc=0x0c083744u; return 0; }
target=r[2];
r[16]=code_base|0x0c083748u;
r[4]=0x00000007u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c083748u) { target=s->pc; goto dispatch; }
goto P_0c083748;
P_0c083746: /* original e407, guest PC 0x0c083746 */
if(!s->budget--) { s->failed_pc=0x0c083746u; return 0; }
r[4]=0x00000007u;
goto P_0c083748;
P_0c083748: /* original 6392, guest PC 0x0c083748 */
if(!s->budget--) { s->failed_pc=0x0c083748u; return 0; }
tmp=read(ram,r[9],4);
r[3]=tmp;
goto P_0c08374a;
P_0c08374a: /* original 33b0, guest PC 0x0c08374a */
if(!s->budget--) { s->failed_pc=0x0c08374au; return 0; }
r[17]=(r[17]&~1u)|((r[3]==r[11])!=0);
goto P_0c08374c;
P_0c08374c: /* original 8b03, guest PC 0x0c08374c */
if(!s->budget--) { s->failed_pc=0x0c08374cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c083756; }
goto P_0c08374e;
P_0c08374e: /* original 55f1, guest PC 0x0c08374e */
if(!s->budget--) { s->failed_pc=0x0c08374eu; return 0; }
r[5]=read(ram,r[15]+4,4);
goto P_0c083750;
P_0c083750: /* original e601, guest PC 0x0c083750 */
if(!s->budget--) { s->failed_pc=0x0c083750u; return 0; }
r[6]=0x00000001u;
goto P_0c083752;
P_0c083752: /* original a003, guest PC 0x0c083752 */
if(!s->budget--) { s->failed_pc=0x0c083752u; return 0; }
r[4]=0x00000027u;
goto P_0c08375c;
P_0c083754: /* original e427, guest PC 0x0c083754 */
if(!s->budget--) { s->failed_pc=0x0c083754u; return 0; }
r[4]=0x00000027u;
goto P_0c083756;
P_0c083756: /* original 65f2, guest PC 0x0c083756 */
if(!s->budget--) { s->failed_pc=0x0c083756u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c083758;
P_0c083758: /* original e428, guest PC 0x0c083758 */
if(!s->budget--) { s->failed_pc=0x0c083758u; return 0; }
r[4]=0x00000028u;
goto P_0c08375a;
P_0c08375a: /* original e601, guest PC 0x0c08375a */
if(!s->budget--) { s->failed_pc=0x0c08375au; return 0; }
r[6]=0x00000001u;
goto P_0c08375c;
P_0c08375c: /* original d329, guest PC 0x0c08375c */
if(!s->budget--) { s->failed_pc=0x0c08375cu; return 0; }
r[3]=read(ram,0x0c083804u,4);
goto P_0c08375e;
P_0c08375e: /* original 430b, guest PC 0x0c08375e */
if(!s->budget--) { s->failed_pc=0x0c08375eu; return 0; }
target=r[3];
r[16]=code_base|0x0c083762u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c083762u) { target=s->pc; goto dispatch; }
goto P_0c083762;
P_0c083760: /* original 0009, guest PC 0x0c083760 */
if(!s->budget--) { s->failed_pc=0x0c083760u; return 0; }
goto P_0c083762;
P_0c083762: /* original 9348, guest PC 0x0c083762 */
if(!s->budget--) { s->failed_pc=0x0c083762u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0837f6u,2);
goto P_0c083764;
P_0c083764: /* original 60a3, guest PC 0x0c083764 */
if(!s->budget--) { s->failed_pc=0x0c083764u; return 0; }
r[0]=r[10];
goto P_0c083766;
P_0c083766: /* original 4008, guest PC 0x0c083766 */
if(!s->budget--) { s->failed_pc=0x0c083766u; return 0; }
r[0]<<=2;
goto P_0c083768;
P_0c083768: /* original 33ec, guest PC 0x0c083768 */
if(!s->budget--) { s->failed_pc=0x0c083768u; return 0; }
r[3]+=r[14];
goto P_0c08376a;
P_0c08376a: /* original 003e, guest PC 0x0c08376a */
if(!s->budget--) { s->failed_pc=0x0c08376au; return 0; }
r[0]=read(ram,r[3]+r[0],4);
goto P_0c08376c;
P_0c08376c: /* original 8801, guest PC 0x0c08376c */
if(!s->budget--) { s->failed_pc=0x0c08376cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c08376e;
P_0c08376e: /* original 8f58, guest PC 0x0c08376e */
if(!s->budget--) { s->failed_pc=0x0c08376eu; return 0; }
cond=r[17]&1u;
r[13]+=0x00000002u;
if(!cond) { goto P_0c083822; }
goto P_0c083772;
P_0c083770: /* original 7d02, guest PC 0x0c083770 */
if(!s->budget--) { s->failed_pc=0x0c083770u; return 0; }
r[13]+=0x00000002u;
goto P_0c083772;
P_0c083772: /* original 9341, guest PC 0x0c083772 */
if(!s->budget--) { s->failed_pc=0x0c083772u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0837f8u,2);
goto P_0c083774;
P_0c083774: /* original 60a3, guest PC 0x0c083774 */
if(!s->budget--) { s->failed_pc=0x0c083774u; return 0; }
r[0]=r[10];
goto P_0c083776;
P_0c083776: /* original 4008, guest PC 0x0c083776 */
if(!s->budget--) { s->failed_pc=0x0c083776u; return 0; }
r[0]<<=2;
goto P_0c083778;
P_0c083778: /* original 33ec, guest PC 0x0c083778 */
if(!s->budget--) { s->failed_pc=0x0c083778u; return 0; }
r[3]+=r[14];
goto P_0c08377a;
P_0c08377a: /* original 003e, guest PC 0x0c08377a */
if(!s->budget--) { s->failed_pc=0x0c08377au; return 0; }
r[0]=read(ram,r[3]+r[0],4);
goto P_0c08377c;
P_0c08377c: /* original 8805, guest PC 0x0c08377c */
if(!s->budget--) { s->failed_pc=0x0c08377cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000005u)!=0);
goto P_0c08377e;
P_0c08377e: /* original 8b21, guest PC 0x0c08377e */
if(!s->budget--) { s->failed_pc=0x0c08377eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0837c4; }
goto P_0c083780;
P_0c083780: /* original d31f, guest PC 0x0c083780 */
if(!s->budget--) { s->failed_pc=0x0c083780u; return 0; }
r[3]=read(ram,0x0c083800u,4);
goto P_0c083782;
P_0c083782: /* original 65d3, guest PC 0x0c083782 */
if(!s->budget--) { s->failed_pc=0x0c083782u; return 0; }
r[5]=r[13];
goto P_0c083784;
P_0c083784: /* original 9639, guest PC 0x0c083784 */
if(!s->budget--) { s->failed_pc=0x0c083784u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0837fau,2);
goto P_0c083786;
P_0c083786: /* original 430b, guest PC 0x0c083786 */
if(!s->budget--) { s->failed_pc=0x0c083786u; return 0; }
target=r[3];
r[16]=code_base|0x0c08378au;
r[4]=0x00000012u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08378au) { target=s->pc; goto dispatch; }
goto P_0c08378a;
P_0c083788: /* original e412, guest PC 0x0c083788 */
if(!s->budget--) { s->failed_pc=0x0c083788u; return 0; }
r[4]=0x00000012u;
goto P_0c08378a;
P_0c08378a: /* original 9633, guest PC 0x0c08378a */
if(!s->budget--) { s->failed_pc=0x0c08378au; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0837f4u,2);
goto P_0c08378c;
P_0c08378c: /* original 65d3, guest PC 0x0c08378c */
if(!s->budget--) { s->failed_pc=0x0c08378cu; return 0; }
r[5]=r[13];
goto P_0c08378e;
P_0c08378e: /* original d31e, guest PC 0x0c08378e */
if(!s->budget--) { s->failed_pc=0x0c08378eu; return 0; }
r[3]=read(ram,0x0c083808u,4);
goto P_0c083790;
P_0c083790: /* original 36ec, guest PC 0x0c083790 */
if(!s->budget--) { s->failed_pc=0x0c083790u; return 0; }
r[6]+=r[14];
goto P_0c083792;
P_0c083792: /* original 36cc, guest PC 0x0c083792 */
if(!s->budget--) { s->failed_pc=0x0c083792u; return 0; }
r[6]+=r[12];
goto P_0c083794;
P_0c083794: /* original 5665, guest PC 0x0c083794 */
if(!s->budget--) { s->failed_pc=0x0c083794u; return 0; }
r[6]=read(ram,r[6]+20,4);
goto P_0c083796;
P_0c083796: /* original 430b, guest PC 0x0c083796 */
if(!s->budget--) { s->failed_pc=0x0c083796u; return 0; }
target=r[3];
r[16]=code_base|0x0c08379au;
r[4]=0x00000014u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08379au) { target=s->pc; goto dispatch; }
goto P_0c08379a;
P_0c083798: /* original e414, guest PC 0x0c083798 */
if(!s->budget--) { s->failed_pc=0x0c083798u; return 0; }
r[4]=0x00000014u;
goto P_0c08379a;
P_0c08379a: /* original 6292, guest PC 0x0c08379a */
if(!s->budget--) { s->failed_pc=0x0c08379au; return 0; }
tmp=read(ram,r[9],4);
r[2]=tmp;
goto P_0c08379c;
P_0c08379c: /* original 32b0, guest PC 0x0c08379c */
if(!s->budget--) { s->failed_pc=0x0c08379cu; return 0; }
r[17]=(r[17]&~1u)|((r[2]==r[11])!=0);
goto P_0c08379e;
P_0c08379e: /* original 8b06, guest PC 0x0c08379e */
if(!s->budget--) { s->failed_pc=0x0c08379eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0837ae; }
goto P_0c0837a0;
P_0c0837a0: /* original 9628, guest PC 0x0c0837a0 */
if(!s->budget--) { s->failed_pc=0x0c0837a0u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0837f4u,2);
goto P_0c0837a2;
P_0c0837a2: /* original 55f2, guest PC 0x0c0837a2 */
if(!s->budget--) { s->failed_pc=0x0c0837a2u; return 0; }
r[5]=read(ram,r[15]+8,4);
goto P_0c0837a4;
P_0c0837a4: /* original 36ec, guest PC 0x0c0837a4 */
if(!s->budget--) { s->failed_pc=0x0c0837a4u; return 0; }
r[6]+=r[14];
goto P_0c0837a6;
P_0c0837a6: /* original 36cc, guest PC 0x0c0837a6 */
if(!s->budget--) { s->failed_pc=0x0c0837a6u; return 0; }
r[6]+=r[12];
goto P_0c0837a8;
P_0c0837a8: /* original 5665, guest PC 0x0c0837a8 */
if(!s->budget--) { s->failed_pc=0x0c0837a8u; return 0; }
r[6]=read(ram,r[6]+20,4);
goto P_0c0837aa;
P_0c0837aa: /* original a006, guest PC 0x0c0837aa */
if(!s->budget--) { s->failed_pc=0x0c0837aau; return 0; }
r[4]=0x0000002bu;
goto P_0c0837ba;
P_0c0837ac: /* original e42b, guest PC 0x0c0837ac */
if(!s->budget--) { s->failed_pc=0x0c0837acu; return 0; }
r[4]=0x0000002bu;
goto P_0c0837ae;
P_0c0837ae: /* original 9621, guest PC 0x0c0837ae */
if(!s->budget--) { s->failed_pc=0x0c0837aeu; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0837f4u,2);
goto P_0c0837b0;
P_0c0837b0: /* original e42e, guest PC 0x0c0837b0 */
if(!s->budget--) { s->failed_pc=0x0c0837b0u; return 0; }
r[4]=0x0000002eu;
goto P_0c0837b2;
P_0c0837b2: /* original 55f2, guest PC 0x0c0837b2 */
if(!s->budget--) { s->failed_pc=0x0c0837b2u; return 0; }
r[5]=read(ram,r[15]+8,4);
goto P_0c0837b4;
P_0c0837b4: /* original 36ec, guest PC 0x0c0837b4 */
if(!s->budget--) { s->failed_pc=0x0c0837b4u; return 0; }
r[6]+=r[14];
goto P_0c0837b6;
P_0c0837b6: /* original 36cc, guest PC 0x0c0837b6 */
if(!s->budget--) { s->failed_pc=0x0c0837b6u; return 0; }
r[6]+=r[12];
goto P_0c0837b8;
P_0c0837b8: /* original 5665, guest PC 0x0c0837b8 */
if(!s->budget--) { s->failed_pc=0x0c0837b8u; return 0; }
r[6]=read(ram,r[6]+20,4);
goto P_0c0837ba;
P_0c0837ba: /* original d313, guest PC 0x0c0837ba */
if(!s->budget--) { s->failed_pc=0x0c0837bau; return 0; }
r[3]=read(ram,0x0c083808u,4);
goto P_0c0837bc;
P_0c0837bc: /* original 430b, guest PC 0x0c0837bc */
if(!s->budget--) { s->failed_pc=0x0c0837bcu; return 0; }
target=r[3];
r[16]=code_base|0x0c0837c0u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0837c0u) { target=s->pc; goto dispatch; }
goto P_0c0837c0;
P_0c0837be: /* original 0009, guest PC 0x0c0837be */
if(!s->budget--) { s->failed_pc=0x0c0837beu; return 0; }
goto P_0c0837c0;
P_0c0837c0: /* original a046, guest PC 0x0c0837c0 */
if(!s->budget--) { s->failed_pc=0x0c0837c0u; return 0; }
goto P_0c083850;
P_0c0837c2: /* original 0009, guest PC 0x0c0837c2 */
if(!s->budget--) { s->failed_pc=0x0c0837c2u; return 0; }
goto P_0c0837c4;
P_0c0837c4: /* original d30e, guest PC 0x0c0837c4 */
if(!s->budget--) { s->failed_pc=0x0c0837c4u; return 0; }
r[3]=read(ram,0x0c083800u,4);
goto P_0c0837c6;
P_0c0837c6: /* original 65d3, guest PC 0x0c0837c6 */
if(!s->budget--) { s->failed_pc=0x0c0837c6u; return 0; }
r[5]=r[13];
goto P_0c0837c8;
P_0c0837c8: /* original 9618, guest PC 0x0c0837c8 */
if(!s->budget--) { s->failed_pc=0x0c0837c8u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0837fcu,2);
goto P_0c0837ca;
P_0c0837ca: /* original 430b, guest PC 0x0c0837ca */
if(!s->budget--) { s->failed_pc=0x0c0837cau; return 0; }
target=r[3];
r[16]=code_base|0x0c0837ceu;
r[4]=0x00000012u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0837ceu) { target=s->pc; goto dispatch; }
goto P_0c0837ce;
P_0c0837cc: /* original e412, guest PC 0x0c0837cc */
if(!s->budget--) { s->failed_pc=0x0c0837ccu; return 0; }
r[4]=0x00000012u;
goto P_0c0837ce;
P_0c0837ce: /* original 9611, guest PC 0x0c0837ce */
if(!s->budget--) { s->failed_pc=0x0c0837ceu; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0837f4u,2);
goto P_0c0837d0;
P_0c0837d0: /* original 65d3, guest PC 0x0c0837d0 */
if(!s->budget--) { s->failed_pc=0x0c0837d0u; return 0; }
r[5]=r[13];
goto P_0c0837d2;
P_0c0837d2: /* original d30c, guest PC 0x0c0837d2 */
if(!s->budget--) { s->failed_pc=0x0c0837d2u; return 0; }
r[3]=read(ram,0x0c083804u,4);
goto P_0c0837d4;
P_0c0837d4: /* original 36ec, guest PC 0x0c0837d4 */
if(!s->budget--) { s->failed_pc=0x0c0837d4u; return 0; }
r[6]+=r[14];
goto P_0c0837d6;
P_0c0837d6: /* original 36cc, guest PC 0x0c0837d6 */
if(!s->budget--) { s->failed_pc=0x0c0837d6u; return 0; }
r[6]+=r[12];
goto P_0c0837d8;
P_0c0837d8: /* original 5665, guest PC 0x0c0837d8 */
if(!s->budget--) { s->failed_pc=0x0c0837d8u; return 0; }
r[6]=read(ram,r[6]+20,4);
goto P_0c0837da;
P_0c0837da: /* original 430b, guest PC 0x0c0837da */
if(!s->budget--) { s->failed_pc=0x0c0837dau; return 0; }
target=r[3];
r[16]=code_base|0x0c0837deu;
r[4]=0x00000014u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0837deu) { target=s->pc; goto dispatch; }
goto P_0c0837de;
P_0c0837dc: /* original e414, guest PC 0x0c0837dc */
if(!s->budget--) { s->failed_pc=0x0c0837dcu; return 0; }
r[4]=0x00000014u;
goto P_0c0837de;
P_0c0837de: /* original 6292, guest PC 0x0c0837de */
if(!s->budget--) { s->failed_pc=0x0c0837deu; return 0; }
tmp=read(ram,r[9],4);
r[2]=tmp;
goto P_0c0837e0;
P_0c0837e0: /* original 32b0, guest PC 0x0c0837e0 */
if(!s->budget--) { s->failed_pc=0x0c0837e0u; return 0; }
r[17]=(r[17]&~1u)|((r[2]==r[11])!=0);
goto P_0c0837e2;
P_0c0837e2: /* original 8b13, guest PC 0x0c0837e2 */
if(!s->budget--) { s->failed_pc=0x0c0837e2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c08380c; }
goto P_0c0837e4;
P_0c0837e4: /* original 9606, guest PC 0x0c0837e4 */
if(!s->budget--) { s->failed_pc=0x0c0837e4u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0837f4u,2);
goto P_0c0837e6;
P_0c0837e6: /* original 55f2, guest PC 0x0c0837e6 */
if(!s->budget--) { s->failed_pc=0x0c0837e6u; return 0; }
r[5]=read(ram,r[15]+8,4);
goto P_0c0837e8;
P_0c0837e8: /* original 36ec, guest PC 0x0c0837e8 */
if(!s->budget--) { s->failed_pc=0x0c0837e8u; return 0; }
r[6]+=r[14];
goto P_0c0837ea;
P_0c0837ea: /* original 36cc, guest PC 0x0c0837ea */
if(!s->budget--) { s->failed_pc=0x0c0837eau; return 0; }
r[6]+=r[12];
goto P_0c0837ec;
P_0c0837ec: /* original 5665, guest PC 0x0c0837ec */
if(!s->budget--) { s->failed_pc=0x0c0837ecu; return 0; }
r[6]=read(ram,r[6]+20,4);
goto P_0c0837ee;
P_0c0837ee: /* original a013, guest PC 0x0c0837ee */
if(!s->budget--) { s->failed_pc=0x0c0837eeu; return 0; }
r[4]=0x0000002bu;
goto P_0c083818;
P_0c0837f0: /* original e42b, guest PC 0x0c0837f0 */
if(!s->budget--) { s->failed_pc=0x0c0837f0u; return 0; }
r[4]=0x0000002bu;
return vf3_matrix_family(0x0c0837f2u,s,ram);
P_0c08380c: /* original 9664, guest PC 0x0c08380c */
if(!s->budget--) { s->failed_pc=0x0c08380cu; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0838d8u,2);
goto P_0c08380e;
P_0c08380e: /* original e42e, guest PC 0x0c08380e */
if(!s->budget--) { s->failed_pc=0x0c08380eu; return 0; }
r[4]=0x0000002eu;
goto P_0c083810;
P_0c083810: /* original 55f2, guest PC 0x0c083810 */
if(!s->budget--) { s->failed_pc=0x0c083810u; return 0; }
r[5]=read(ram,r[15]+8,4);
goto P_0c083812;
P_0c083812: /* original 36ec, guest PC 0x0c083812 */
if(!s->budget--) { s->failed_pc=0x0c083812u; return 0; }
r[6]+=r[14];
goto P_0c083814;
P_0c083814: /* original 36cc, guest PC 0x0c083814 */
if(!s->budget--) { s->failed_pc=0x0c083814u; return 0; }
r[6]+=r[12];
goto P_0c083816;
P_0c083816: /* original 5665, guest PC 0x0c083816 */
if(!s->budget--) { s->failed_pc=0x0c083816u; return 0; }
r[6]=read(ram,r[6]+20,4);
goto P_0c083818;
P_0c083818: /* original d332, guest PC 0x0c083818 */
if(!s->budget--) { s->failed_pc=0x0c083818u; return 0; }
r[3]=read(ram,0x0c0838e4u,4);
goto P_0c08381a;
P_0c08381a: /* original 430b, guest PC 0x0c08381a */
if(!s->budget--) { s->failed_pc=0x0c08381au; return 0; }
target=r[3];
r[16]=code_base|0x0c08381eu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08381eu) { target=s->pc; goto dispatch; }
goto P_0c08381e;
P_0c08381c: /* original 0009, guest PC 0x0c08381c */
if(!s->budget--) { s->failed_pc=0x0c08381cu; return 0; }
goto P_0c08381e;
P_0c08381e: /* original a017, guest PC 0x0c08381e */
if(!s->budget--) { s->failed_pc=0x0c08381eu; return 0; }
goto P_0c083850;
P_0c083820: /* original 0009, guest PC 0x0c083820 */
if(!s->budget--) { s->failed_pc=0x0c083820u; return 0; }
goto P_0c083822;
P_0c083822: /* original d331, guest PC 0x0c083822 */
if(!s->budget--) { s->failed_pc=0x0c083822u; return 0; }
r[3]=read(ram,0x0c0838e8u,4);
goto P_0c083824;
P_0c083824: /* original 65d3, guest PC 0x0c083824 */
if(!s->budget--) { s->failed_pc=0x0c083824u; return 0; }
r[5]=r[13];
goto P_0c083826;
P_0c083826: /* original 9658, guest PC 0x0c083826 */
if(!s->budget--) { s->failed_pc=0x0c083826u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0838dau,2);
goto P_0c083828;
P_0c083828: /* original 430b, guest PC 0x0c083828 */
if(!s->budget--) { s->failed_pc=0x0c083828u; return 0; }
target=r[3];
r[16]=code_base|0x0c08382cu;
r[4]=0x00000012u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08382cu) { target=s->pc; goto dispatch; }
goto P_0c08382c;
P_0c08382a: /* original e412, guest PC 0x0c08382a */
if(!s->budget--) { s->failed_pc=0x0c08382au; return 0; }
r[4]=0x00000012u;
goto P_0c08382c;
P_0c08382c: /* original d22d, guest PC 0x0c08382c */
if(!s->budget--) { s->failed_pc=0x0c08382cu; return 0; }
r[2]=read(ram,0x0c0838e4u,4);
goto P_0c08382e;
P_0c08382e: /* original 65d3, guest PC 0x0c08382e */
if(!s->budget--) { s->failed_pc=0x0c08382eu; return 0; }
r[5]=r[13];
goto P_0c083830;
P_0c083830: /* original e602, guest PC 0x0c083830 */
if(!s->budget--) { s->failed_pc=0x0c083830u; return 0; }
r[6]=0x00000002u;
goto P_0c083832;
P_0c083832: /* original 420b, guest PC 0x0c083832 */
if(!s->budget--) { s->failed_pc=0x0c083832u; return 0; }
target=r[2];
r[16]=code_base|0x0c083836u;
r[4]=0x00000007u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c083836u) { target=s->pc; goto dispatch; }
goto P_0c083836;
P_0c083834: /* original e407, guest PC 0x0c083834 */
if(!s->budget--) { s->failed_pc=0x0c083834u; return 0; }
r[4]=0x00000007u;
goto P_0c083836;
P_0c083836: /* original 6392, guest PC 0x0c083836 */
if(!s->budget--) { s->failed_pc=0x0c083836u; return 0; }
tmp=read(ram,r[9],4);
r[3]=tmp;
goto P_0c083838;
P_0c083838: /* original 33b0, guest PC 0x0c083838 */
if(!s->budget--) { s->failed_pc=0x0c083838u; return 0; }
r[17]=(r[17]&~1u)|((r[3]==r[11])!=0);
goto P_0c08383a;
P_0c08383a: /* original 8b03, guest PC 0x0c08383a */
if(!s->budget--) { s->failed_pc=0x0c08383au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c083844; }
goto P_0c08383c;
P_0c08383c: /* original 55f2, guest PC 0x0c08383c */
if(!s->budget--) { s->failed_pc=0x0c08383cu; return 0; }
r[5]=read(ram,r[15]+8,4);
goto P_0c08383e;
P_0c08383e: /* original e602, guest PC 0x0c08383e */
if(!s->budget--) { s->failed_pc=0x0c08383eu; return 0; }
r[6]=0x00000002u;
goto P_0c083840;
P_0c083840: /* original a003, guest PC 0x0c083840 */
if(!s->budget--) { s->failed_pc=0x0c083840u; return 0; }
r[4]=0x0000002bu;
goto P_0c08384a;
P_0c083842: /* original e42b, guest PC 0x0c083842 */
if(!s->budget--) { s->failed_pc=0x0c083842u; return 0; }
r[4]=0x0000002bu;
goto P_0c083844;
P_0c083844: /* original 55f2, guest PC 0x0c083844 */
if(!s->budget--) { s->failed_pc=0x0c083844u; return 0; }
r[5]=read(ram,r[15]+8,4);
goto P_0c083846;
P_0c083846: /* original e42e, guest PC 0x0c083846 */
if(!s->budget--) { s->failed_pc=0x0c083846u; return 0; }
r[4]=0x0000002eu;
goto P_0c083848;
P_0c083848: /* original e602, guest PC 0x0c083848 */
if(!s->budget--) { s->failed_pc=0x0c083848u; return 0; }
r[6]=0x00000002u;
goto P_0c08384a;
P_0c08384a: /* original d326, guest PC 0x0c08384a */
if(!s->budget--) { s->failed_pc=0x0c08384au; return 0; }
r[3]=read(ram,0x0c0838e4u,4);
goto P_0c08384c;
P_0c08384c: /* original 430b, guest PC 0x0c08384c */
if(!s->budget--) { s->failed_pc=0x0c08384cu; return 0; }
target=r[3];
r[16]=code_base|0x0c083850u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c083850u) { target=s->pc; goto dispatch; }
goto P_0c083850;
P_0c08384e: /* original 0009, guest PC 0x0c08384e */
if(!s->budget--) { s->failed_pc=0x0c08384eu; return 0; }
goto P_0c083850;
P_0c083850: /* original 7808, guest PC 0x0c083850 */
if(!s->budget--) { s->failed_pc=0x0c083850u; return 0; }
r[8]+=0x00000008u;
goto P_0c083852;
P_0c083852: /* original 2f82, guest PC 0x0c083852 */
if(!s->budget--) { s->failed_pc=0x0c083852u; return 0; }
write(ram,r[15],r[8],4);
goto P_0c083854;
P_0c083854: /* original 6392, guest PC 0x0c083854 */
if(!s->budget--) { s->failed_pc=0x0c083854u; return 0; }
tmp=read(ram,r[9],4);
r[3]=tmp;
goto P_0c083856;
P_0c083856: /* original 33b0, guest PC 0x0c083856 */
if(!s->budget--) { s->failed_pc=0x0c083856u; return 0; }
r[17]=(r[17]&~1u)|((r[3]==r[11])!=0);
goto P_0c083858;
P_0c083858: /* original 8b59, guest PC 0x0c083858 */
if(!s->budget--) { s->failed_pc=0x0c083858u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c08390e; }
goto P_0c08385a;
P_0c08385a: /* original 9340, guest PC 0x0c08385a */
if(!s->budget--) { s->failed_pc=0x0c08385au; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0838deu,2);
goto P_0c08385c;
P_0c08385c: /* original 60a3, guest PC 0x0c08385c */
if(!s->budget--) { s->failed_pc=0x0c08385cu; return 0; }
r[0]=r[10];
goto P_0c08385e;
P_0c08385e: /* original 4008, guest PC 0x0c08385e */
if(!s->budget--) { s->failed_pc=0x0c08385eu; return 0; }
r[0]<<=2;
goto P_0c083860;
P_0c083860: /* original 983c, guest PC 0x0c083860 */
if(!s->budget--) { s->failed_pc=0x0c083860u; return 0; }
r[8]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0838dcu,2);
goto P_0c083862;
P_0c083862: /* original 33ec, guest PC 0x0c083862 */
if(!s->budget--) { s->failed_pc=0x0c083862u; return 0; }
r[3]+=r[14];
goto P_0c083864;
P_0c083864: /* original 003e, guest PC 0x0c083864 */
if(!s->budget--) { s->failed_pc=0x0c083864u; return 0; }
r[0]=read(ram,r[3]+r[0],4);
goto P_0c083866;
P_0c083866: /* original 8801, guest PC 0x0c083866 */
if(!s->budget--) { s->failed_pc=0x0c083866u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c083868;
P_0c083868: /* original 8f42, guest PC 0x0c083868 */
if(!s->budget--) { s->failed_pc=0x0c083868u; return 0; }
cond=r[17]&1u;
r[13]+=0x00000002u;
if(!cond) { goto P_0c0838f0; }
goto P_0c08386c;
P_0c08386a: /* original 7d02, guest PC 0x0c08386a */
if(!s->budget--) { s->failed_pc=0x0c08386au; return 0; }
r[13]+=0x00000002u;
goto P_0c08386c;
P_0c08386c: /* original 9338, guest PC 0x0c08386c */
if(!s->budget--) { s->failed_pc=0x0c08386cu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0838e0u,2);
goto P_0c08386e;
P_0c08386e: /* original 60a3, guest PC 0x0c08386e */
if(!s->budget--) { s->failed_pc=0x0c08386eu; return 0; }
r[0]=r[10];
goto P_0c083870;
P_0c083870: /* original 4008, guest PC 0x0c083870 */
if(!s->budget--) { s->failed_pc=0x0c083870u; return 0; }
r[0]<<=2;
goto P_0c083872;
P_0c083872: /* original 33ec, guest PC 0x0c083872 */
if(!s->budget--) { s->failed_pc=0x0c083872u; return 0; }
r[3]+=r[14];
goto P_0c083874;
P_0c083874: /* original 003e, guest PC 0x0c083874 */
if(!s->budget--) { s->failed_pc=0x0c083874u; return 0; }
r[0]=read(ram,r[3]+r[0],4);
goto P_0c083876;
P_0c083876: /* original 8806, guest PC 0x0c083876 */
if(!s->budget--) { s->failed_pc=0x0c083876u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000006u)!=0);
goto P_0c083878;
P_0c083878: /* original 8b17, guest PC 0x0c083878 */
if(!s->budget--) { s->failed_pc=0x0c083878u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0838aa; }
goto P_0c08387a;
P_0c08387a: /* original 9832, guest PC 0x0c08387a */
if(!s->budget--) { s->failed_pc=0x0c08387au; return 0; }
r[8]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0838e2u,2);
goto P_0c08387c;
P_0c08387c: /* original 65d3, guest PC 0x0c08387c */
if(!s->budget--) { s->failed_pc=0x0c08387cu; return 0; }
r[5]=r[13];
goto P_0c08387e;
P_0c08387e: /* original d31a, guest PC 0x0c08387e */
if(!s->budget--) { s->failed_pc=0x0c08387eu; return 0; }
r[3]=read(ram,0x0c0838e8u,4);
goto P_0c083880;
P_0c083880: /* original 6683, guest PC 0x0c083880 */
if(!s->budget--) { s->failed_pc=0x0c083880u; return 0; }
r[6]=r[8];
goto P_0c083882;
P_0c083882: /* original 430b, guest PC 0x0c083882 */
if(!s->budget--) { s->failed_pc=0x0c083882u; return 0; }
target=r[3];
r[16]=code_base|0x0c083886u;
r[4]=0x00000012u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c083886u) { target=s->pc; goto dispatch; }
goto P_0c083886;
P_0c083884: /* original e412, guest PC 0x0c083884 */
if(!s->budget--) { s->failed_pc=0x0c083884u; return 0; }
r[4]=0x00000012u;
goto P_0c083886;
P_0c083886: /* original 9627, guest PC 0x0c083886 */
if(!s->budget--) { s->failed_pc=0x0c083886u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0838d8u,2);
goto P_0c083888;
P_0c083888: /* original 65d3, guest PC 0x0c083888 */
if(!s->budget--) { s->failed_pc=0x0c083888u; return 0; }
r[5]=r[13];
goto P_0c08388a;
P_0c08388a: /* original d318, guest PC 0x0c08388a */
if(!s->budget--) { s->failed_pc=0x0c08388au; return 0; }
r[3]=read(ram,0x0c0838ecu,4);
goto P_0c08388c;
P_0c08388c: /* original 36ec, guest PC 0x0c08388c */
if(!s->budget--) { s->failed_pc=0x0c08388cu; return 0; }
r[6]+=r[14];
goto P_0c08388e;
P_0c08388e: /* original 36cc, guest PC 0x0c08388e */
if(!s->budget--) { s->failed_pc=0x0c08388eu; return 0; }
r[6]+=r[12];
goto P_0c083890;
P_0c083890: /* original 5666, guest PC 0x0c083890 */
if(!s->budget--) { s->failed_pc=0x0c083890u; return 0; }
r[6]=read(ram,r[6]+24,4);
goto P_0c083892;
P_0c083892: /* original 430b, guest PC 0x0c083892 */
if(!s->budget--) { s->failed_pc=0x0c083892u; return 0; }
target=r[3];
r[16]=code_base|0x0c083896u;
r[4]=0x00000014u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c083896u) { target=s->pc; goto dispatch; }
goto P_0c083896;
P_0c083894: /* original e414, guest PC 0x0c083894 */
if(!s->budget--) { s->failed_pc=0x0c083894u; return 0; }
r[4]=0x00000014u;
goto P_0c083896;
P_0c083896: /* original 961f, guest PC 0x0c083896 */
if(!s->budget--) { s->failed_pc=0x0c083896u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0838d8u,2);
goto P_0c083898;
P_0c083898: /* original d314, guest PC 0x0c083898 */
if(!s->budget--) { s->failed_pc=0x0c083898u; return 0; }
r[3]=read(ram,0x0c0838ecu,4);
goto P_0c08389a;
P_0c08389a: /* original 36ec, guest PC 0x0c08389a */
if(!s->budget--) { s->failed_pc=0x0c08389au; return 0; }
r[6]+=r[14];
goto P_0c08389c;
P_0c08389c: /* original 65f2, guest PC 0x0c08389c */
if(!s->budget--) { s->failed_pc=0x0c08389cu; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c08389e;
P_0c08389e: /* original 36cc, guest PC 0x0c08389e */
if(!s->budget--) { s->failed_pc=0x0c08389eu; return 0; }
r[6]+=r[12];
goto P_0c0838a0;
P_0c0838a0: /* original 5666, guest PC 0x0c0838a0 */
if(!s->budget--) { s->failed_pc=0x0c0838a0u; return 0; }
r[6]=read(ram,r[6]+24,4);
goto P_0c0838a2;
P_0c0838a2: /* original 430b, guest PC 0x0c0838a2 */
if(!s->budget--) { s->failed_pc=0x0c0838a2u; return 0; }
target=r[3];
r[16]=code_base|0x0c0838a6u;
r[4]=0x00000033u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0838a6u) { target=s->pc; goto dispatch; }
goto P_0c0838a6;
P_0c0838a4: /* original e433, guest PC 0x0c0838a4 */
if(!s->budget--) { s->failed_pc=0x0c0838a4u; return 0; }
r[4]=0x00000033u;
goto P_0c0838a6;
P_0c0838a6: /* original a032, guest PC 0x0c0838a6 */
if(!s->budget--) { s->failed_pc=0x0c0838a6u; return 0; }
goto P_0c08390e;
P_0c0838a8: /* original 0009, guest PC 0x0c0838a8 */
if(!s->budget--) { s->failed_pc=0x0c0838a8u; return 0; }
goto P_0c0838aa;
P_0c0838aa: /* original d30f, guest PC 0x0c0838aa */
if(!s->budget--) { s->failed_pc=0x0c0838aau; return 0; }
r[3]=read(ram,0x0c0838e8u,4);
goto P_0c0838ac;
P_0c0838ac: /* original 65d3, guest PC 0x0c0838ac */
if(!s->budget--) { s->failed_pc=0x0c0838acu; return 0; }
r[5]=r[13];
goto P_0c0838ae;
P_0c0838ae: /* original 6683, guest PC 0x0c0838ae */
if(!s->budget--) { s->failed_pc=0x0c0838aeu; return 0; }
r[6]=r[8];
goto P_0c0838b0;
P_0c0838b0: /* original 430b, guest PC 0x0c0838b0 */
if(!s->budget--) { s->failed_pc=0x0c0838b0u; return 0; }
target=r[3];
r[16]=code_base|0x0c0838b4u;
r[4]=0x00000012u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0838b4u) { target=s->pc; goto dispatch; }
goto P_0c0838b4;
P_0c0838b2: /* original e412, guest PC 0x0c0838b2 */
if(!s->budget--) { s->failed_pc=0x0c0838b2u; return 0; }
r[4]=0x00000012u;
goto P_0c0838b4;
P_0c0838b4: /* original 9610, guest PC 0x0c0838b4 */
if(!s->budget--) { s->failed_pc=0x0c0838b4u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0838d8u,2);
goto P_0c0838b6;
P_0c0838b6: /* original 65d3, guest PC 0x0c0838b6 */
if(!s->budget--) { s->failed_pc=0x0c0838b6u; return 0; }
r[5]=r[13];
goto P_0c0838b8;
P_0c0838b8: /* original d30a, guest PC 0x0c0838b8 */
if(!s->budget--) { s->failed_pc=0x0c0838b8u; return 0; }
r[3]=read(ram,0x0c0838e4u,4);
goto P_0c0838ba;
P_0c0838ba: /* original 36ec, guest PC 0x0c0838ba */
if(!s->budget--) { s->failed_pc=0x0c0838bau; return 0; }
r[6]+=r[14];
goto P_0c0838bc;
P_0c0838bc: /* original 36cc, guest PC 0x0c0838bc */
if(!s->budget--) { s->failed_pc=0x0c0838bcu; return 0; }
r[6]+=r[12];
goto P_0c0838be;
P_0c0838be: /* original 5666, guest PC 0x0c0838be */
if(!s->budget--) { s->failed_pc=0x0c0838beu; return 0; }
r[6]=read(ram,r[6]+24,4);
goto P_0c0838c0;
P_0c0838c0: /* original 430b, guest PC 0x0c0838c0 */
if(!s->budget--) { s->failed_pc=0x0c0838c0u; return 0; }
target=r[3];
r[16]=code_base|0x0c0838c4u;
r[4]=0x00000014u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0838c4u) { target=s->pc; goto dispatch; }
goto P_0c0838c4;
P_0c0838c2: /* original e414, guest PC 0x0c0838c2 */
if(!s->budget--) { s->failed_pc=0x0c0838c2u; return 0; }
r[4]=0x00000014u;
goto P_0c0838c4;
P_0c0838c4: /* original 9608, guest PC 0x0c0838c4 */
if(!s->budget--) { s->failed_pc=0x0c0838c4u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0838d8u,2);
goto P_0c0838c6;
P_0c0838c6: /* original d307, guest PC 0x0c0838c6 */
if(!s->budget--) { s->failed_pc=0x0c0838c6u; return 0; }
r[3]=read(ram,0x0c0838e4u,4);
goto P_0c0838c8;
P_0c0838c8: /* original 36ec, guest PC 0x0c0838c8 */
if(!s->budget--) { s->failed_pc=0x0c0838c8u; return 0; }
r[6]+=r[14];
goto P_0c0838ca;
P_0c0838ca: /* original 65f2, guest PC 0x0c0838ca */
if(!s->budget--) { s->failed_pc=0x0c0838cau; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0838cc;
P_0c0838cc: /* original 36cc, guest PC 0x0c0838cc */
if(!s->budget--) { s->failed_pc=0x0c0838ccu; return 0; }
r[6]+=r[12];
goto P_0c0838ce;
P_0c0838ce: /* original 5666, guest PC 0x0c0838ce */
if(!s->budget--) { s->failed_pc=0x0c0838ceu; return 0; }
r[6]=read(ram,r[6]+24,4);
goto P_0c0838d0;
P_0c0838d0: /* original 430b, guest PC 0x0c0838d0 */
if(!s->budget--) { s->failed_pc=0x0c0838d0u; return 0; }
target=r[3];
r[16]=code_base|0x0c0838d4u;
r[4]=0x00000033u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0838d4u) { target=s->pc; goto dispatch; }
goto P_0c0838d4;
P_0c0838d2: /* original e433, guest PC 0x0c0838d2 */
if(!s->budget--) { s->failed_pc=0x0c0838d2u; return 0; }
r[4]=0x00000033u;
goto P_0c0838d4;
P_0c0838d4: /* original a01b, guest PC 0x0c0838d4 */
if(!s->budget--) { s->failed_pc=0x0c0838d4u; return 0; }
goto P_0c08390e;
P_0c0838d6: /* original 0009, guest PC 0x0c0838d6 */
if(!s->budget--) { s->failed_pc=0x0c0838d6u; return 0; }
return vf3_matrix_family(0x0c0838d8u,s,ram);
P_0c0838f0: /* original d348, guest PC 0x0c0838f0 */
if(!s->budget--) { s->failed_pc=0x0c0838f0u; return 0; }
r[3]=read(ram,0x0c083a14u,4);
goto P_0c0838f2;
P_0c0838f2: /* original 65d3, guest PC 0x0c0838f2 */
if(!s->budget--) { s->failed_pc=0x0c0838f2u; return 0; }
r[5]=r[13];
goto P_0c0838f4;
P_0c0838f4: /* original 6683, guest PC 0x0c0838f4 */
if(!s->budget--) { s->failed_pc=0x0c0838f4u; return 0; }
r[6]=r[8];
goto P_0c0838f6;
P_0c0838f6: /* original 430b, guest PC 0x0c0838f6 */
if(!s->budget--) { s->failed_pc=0x0c0838f6u; return 0; }
target=r[3];
r[16]=code_base|0x0c0838fau;
r[4]=0x00000012u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0838fau) { target=s->pc; goto dispatch; }
goto P_0c0838fa;
P_0c0838f8: /* original e412, guest PC 0x0c0838f8 */
if(!s->budget--) { s->failed_pc=0x0c0838f8u; return 0; }
r[4]=0x00000012u;
goto P_0c0838fa;
P_0c0838fa: /* original d247, guest PC 0x0c0838fa */
if(!s->budget--) { s->failed_pc=0x0c0838fau; return 0; }
r[2]=read(ram,0x0c083a18u,4);
goto P_0c0838fc;
P_0c0838fc: /* original 65d3, guest PC 0x0c0838fc */
if(!s->budget--) { s->failed_pc=0x0c0838fcu; return 0; }
r[5]=r[13];
goto P_0c0838fe;
P_0c0838fe: /* original e608, guest PC 0x0c0838fe */
if(!s->budget--) { s->failed_pc=0x0c0838feu; return 0; }
r[6]=0x00000008u;
goto P_0c083900;
P_0c083900: /* original 420b, guest PC 0x0c083900 */
if(!s->budget--) { s->failed_pc=0x0c083900u; return 0; }
target=r[2];
r[16]=code_base|0x0c083904u;
r[4]=0x00000007u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c083904u) { target=s->pc; goto dispatch; }
goto P_0c083904;
P_0c083902: /* original e407, guest PC 0x0c083902 */
if(!s->budget--) { s->failed_pc=0x0c083902u; return 0; }
r[4]=0x00000007u;
goto P_0c083904;
P_0c083904: /* original d344, guest PC 0x0c083904 */
if(!s->budget--) { s->failed_pc=0x0c083904u; return 0; }
r[3]=read(ram,0x0c083a18u,4);
goto P_0c083906;
P_0c083906: /* original e608, guest PC 0x0c083906 */
if(!s->budget--) { s->failed_pc=0x0c083906u; return 0; }
r[6]=0x00000008u;
goto P_0c083908;
P_0c083908: /* original 65f2, guest PC 0x0c083908 */
if(!s->budget--) { s->failed_pc=0x0c083908u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c08390a;
P_0c08390a: /* original 430b, guest PC 0x0c08390a */
if(!s->budget--) { s->failed_pc=0x0c08390au; return 0; }
target=r[3];
r[16]=code_base|0x0c08390eu;
r[4]=0x00000033u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08390eu) { target=s->pc; goto dispatch; }
goto P_0c08390e;
P_0c08390c: /* original e433, guest PC 0x0c08390c */
if(!s->budget--) { s->failed_pc=0x0c08390cu; return 0; }
r[4]=0x00000033u;
goto P_0c08390e;
P_0c08390e: /* original 6392, guest PC 0x0c08390e */
if(!s->budget--) { s->failed_pc=0x0c08390eu; return 0; }
tmp=read(ram,r[9],4);
r[3]=tmp;
goto P_0c083910;
P_0c083910: /* original d242, guest PC 0x0c083910 */
if(!s->budget--) { s->failed_pc=0x0c083910u; return 0; }
r[2]=read(ram,0x0c083a1cu,4);
goto P_0c083912;
P_0c083912: /* original 3320, guest PC 0x0c083912 */
if(!s->budget--) { s->failed_pc=0x0c083912u; return 0; }
r[17]=(r[17]&~1u)|((r[3]==r[2])!=0);
goto P_0c083914;
P_0c083914: /* original 8901, guest PC 0x0c083914 */
if(!s->budget--) { s->failed_pc=0x0c083914u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c08391a; }
goto P_0c083916;
P_0c083916: /* original a0ab, guest PC 0x0c083916 */
if(!s->budget--) { s->failed_pc=0x0c083916u; return 0; }
goto P_0c083a70;
P_0c083918: /* original 0009, guest PC 0x0c083918 */
if(!s->budget--) { s->failed_pc=0x0c083918u; return 0; }
goto P_0c08391a;
P_0c08391a: /* original 9375, guest PC 0x0c08391a */
if(!s->budget--) { s->failed_pc=0x0c08391au; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c083a08u,2);
goto P_0c08391c;
P_0c08391c: /* original 60a3, guest PC 0x0c08391c */
if(!s->budget--) { s->failed_pc=0x0c08391cu; return 0; }
r[0]=r[10];
goto P_0c08391e;
P_0c08391e: /* original 4008, guest PC 0x0c08391e */
if(!s->budget--) { s->failed_pc=0x0c08391eu; return 0; }
r[0]<<=2;
goto P_0c083920;
P_0c083920: /* original 9971, guest PC 0x0c083920 */
if(!s->budget--) { s->failed_pc=0x0c083920u; return 0; }
r[9]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c083a06u,2);
goto P_0c083922;
P_0c083922: /* original 33ec, guest PC 0x0c083922 */
if(!s->budget--) { s->failed_pc=0x0c083922u; return 0; }
r[3]+=r[14];
goto P_0c083924;
P_0c083924: /* original 003e, guest PC 0x0c083924 */
if(!s->budget--) { s->failed_pc=0x0c083924u; return 0; }
r[0]=read(ram,r[3]+r[0],4);
goto P_0c083926;
P_0c083926: /* original 8801, guest PC 0x0c083926 */
if(!s->budget--) { s->failed_pc=0x0c083926u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c083928;
P_0c083928: /* original 8f36, guest PC 0x0c083928 */
if(!s->budget--) { s->failed_pc=0x0c083928u; return 0; }
cond=r[17]&1u;
r[13]+=0x00000002u;
if(!cond) { goto P_0c083998; }
goto P_0c08392c;
P_0c08392a: /* original 7d02, guest PC 0x0c08392a */
if(!s->budget--) { s->failed_pc=0x0c08392au; return 0; }
r[13]+=0x00000002u;
goto P_0c08392c;
P_0c08392c: /* original 936d, guest PC 0x0c08392c */
if(!s->budget--) { s->failed_pc=0x0c08392cu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c083a0au,2);
goto P_0c08392e;
P_0c08392e: /* original 60a3, guest PC 0x0c08392e */
if(!s->budget--) { s->failed_pc=0x0c08392eu; return 0; }
r[0]=r[10];
goto P_0c083930;
P_0c083930: /* original 4008, guest PC 0x0c083930 */
if(!s->budget--) { s->failed_pc=0x0c083930u; return 0; }
r[0]<<=2;
goto P_0c083932;
P_0c083932: /* original 33ec, guest PC 0x0c083932 */
if(!s->budget--) { s->failed_pc=0x0c083932u; return 0; }
r[3]+=r[14];
goto P_0c083934;
P_0c083934: /* original 003e, guest PC 0x0c083934 */
if(!s->budget--) { s->failed_pc=0x0c083934u; return 0; }
r[0]=read(ram,r[3]+r[0],4);
goto P_0c083936;
P_0c083936: /* original 8807, guest PC 0x0c083936 */
if(!s->budget--) { s->failed_pc=0x0c083936u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000007u)!=0);
goto P_0c083938;
P_0c083938: /* original 8b17, guest PC 0x0c083938 */
if(!s->budget--) { s->failed_pc=0x0c083938u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c08396a; }
goto P_0c08393a;
P_0c08393a: /* original 9967, guest PC 0x0c08393a */
if(!s->budget--) { s->failed_pc=0x0c08393au; return 0; }
r[9]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c083a0cu,2);
goto P_0c08393c;
P_0c08393c: /* original 65d3, guest PC 0x0c08393c */
if(!s->budget--) { s->failed_pc=0x0c08393cu; return 0; }
r[5]=r[13];
goto P_0c08393e;
P_0c08393e: /* original d335, guest PC 0x0c08393e */
if(!s->budget--) { s->failed_pc=0x0c08393eu; return 0; }
r[3]=read(ram,0x0c083a14u,4);
goto P_0c083940;
P_0c083940: /* original 6693, guest PC 0x0c083940 */
if(!s->budget--) { s->failed_pc=0x0c083940u; return 0; }
r[6]=r[9];
goto P_0c083942;
P_0c083942: /* original 430b, guest PC 0x0c083942 */
if(!s->budget--) { s->failed_pc=0x0c083942u; return 0; }
target=r[3];
r[16]=code_base|0x0c083946u;
r[4]=0x00000012u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c083946u) { target=s->pc; goto dispatch; }
goto P_0c083946;
P_0c083944: /* original e412, guest PC 0x0c083944 */
if(!s->budget--) { s->failed_pc=0x0c083944u; return 0; }
r[4]=0x00000012u;
goto P_0c083946;
P_0c083946: /* original 9662, guest PC 0x0c083946 */
if(!s->budget--) { s->failed_pc=0x0c083946u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c083a0eu,2);
goto P_0c083948;
P_0c083948: /* original 65d3, guest PC 0x0c083948 */
if(!s->budget--) { s->failed_pc=0x0c083948u; return 0; }
r[5]=r[13];
goto P_0c08394a;
P_0c08394a: /* original d335, guest PC 0x0c08394a */
if(!s->budget--) { s->failed_pc=0x0c08394au; return 0; }
r[3]=read(ram,0x0c083a20u,4);
goto P_0c08394c;
P_0c08394c: /* original 36ec, guest PC 0x0c08394c */
if(!s->budget--) { s->failed_pc=0x0c08394cu; return 0; }
r[6]+=r[14];
goto P_0c08394e;
P_0c08394e: /* original 36cc, guest PC 0x0c08394e */
if(!s->budget--) { s->failed_pc=0x0c08394eu; return 0; }
r[6]+=r[12];
goto P_0c083950;
P_0c083950: /* original 5667, guest PC 0x0c083950 */
if(!s->budget--) { s->failed_pc=0x0c083950u; return 0; }
r[6]=read(ram,r[6]+28,4);
goto P_0c083952;
P_0c083952: /* original 430b, guest PC 0x0c083952 */
if(!s->budget--) { s->failed_pc=0x0c083952u; return 0; }
target=r[3];
r[16]=code_base|0x0c083956u;
r[4]=0x00000014u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c083956u) { target=s->pc; goto dispatch; }
goto P_0c083956;
P_0c083954: /* original e414, guest PC 0x0c083954 */
if(!s->budget--) { s->failed_pc=0x0c083954u; return 0; }
r[4]=0x00000014u;
goto P_0c083956;
P_0c083956: /* original 965a, guest PC 0x0c083956 */
if(!s->budget--) { s->failed_pc=0x0c083956u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c083a0eu,2);
goto P_0c083958;
P_0c083958: /* original d331, guest PC 0x0c083958 */
if(!s->budget--) { s->failed_pc=0x0c083958u; return 0; }
r[3]=read(ram,0x0c083a20u,4);
goto P_0c08395a;
P_0c08395a: /* original 36ec, guest PC 0x0c08395a */
if(!s->budget--) { s->failed_pc=0x0c08395au; return 0; }
r[6]+=r[14];
goto P_0c08395c;
P_0c08395c: /* original 65f2, guest PC 0x0c08395c */
if(!s->budget--) { s->failed_pc=0x0c08395cu; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c08395e;
P_0c08395e: /* original 36cc, guest PC 0x0c08395e */
if(!s->budget--) { s->failed_pc=0x0c08395eu; return 0; }
r[6]+=r[12];
goto P_0c083960;
P_0c083960: /* original 5667, guest PC 0x0c083960 */
if(!s->budget--) { s->failed_pc=0x0c083960u; return 0; }
r[6]=read(ram,r[6]+28,4);
goto P_0c083962;
P_0c083962: /* original 430b, guest PC 0x0c083962 */
if(!s->budget--) { s->failed_pc=0x0c083962u; return 0; }
target=r[3];
r[16]=code_base|0x0c083966u;
r[4]=0x00000021u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c083966u) { target=s->pc; goto dispatch; }
goto P_0c083966;
P_0c083964: /* original e421, guest PC 0x0c083964 */
if(!s->budget--) { s->failed_pc=0x0c083964u; return 0; }
r[4]=0x00000021u;
goto P_0c083966;
P_0c083966: /* original a026, guest PC 0x0c083966 */
if(!s->budget--) { s->failed_pc=0x0c083966u; return 0; }
goto P_0c0839b6;
P_0c083968: /* original 0009, guest PC 0x0c083968 */
if(!s->budget--) { s->failed_pc=0x0c083968u; return 0; }
goto P_0c08396a;
P_0c08396a: /* original d32a, guest PC 0x0c08396a */
if(!s->budget--) { s->failed_pc=0x0c08396au; return 0; }
r[3]=read(ram,0x0c083a14u,4);
goto P_0c08396c;
P_0c08396c: /* original 65d3, guest PC 0x0c08396c */
if(!s->budget--) { s->failed_pc=0x0c08396cu; return 0; }
r[5]=r[13];
goto P_0c08396e;
P_0c08396e: /* original 6693, guest PC 0x0c08396e */
if(!s->budget--) { s->failed_pc=0x0c08396eu; return 0; }
r[6]=r[9];
goto P_0c083970;
P_0c083970: /* original 430b, guest PC 0x0c083970 */
if(!s->budget--) { s->failed_pc=0x0c083970u; return 0; }
target=r[3];
r[16]=code_base|0x0c083974u;
r[4]=0x00000012u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c083974u) { target=s->pc; goto dispatch; }
goto P_0c083974;
P_0c083972: /* original e412, guest PC 0x0c083972 */
if(!s->budget--) { s->failed_pc=0x0c083972u; return 0; }
r[4]=0x00000012u;
goto P_0c083974;
P_0c083974: /* original 964b, guest PC 0x0c083974 */
if(!s->budget--) { s->failed_pc=0x0c083974u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c083a0eu,2);
goto P_0c083976;
P_0c083976: /* original 65d3, guest PC 0x0c083976 */
if(!s->budget--) { s->failed_pc=0x0c083976u; return 0; }
r[5]=r[13];
goto P_0c083978;
P_0c083978: /* original d327, guest PC 0x0c083978 */
if(!s->budget--) { s->failed_pc=0x0c083978u; return 0; }
r[3]=read(ram,0x0c083a18u,4);
goto P_0c08397a;
P_0c08397a: /* original 36ec, guest PC 0x0c08397a */
if(!s->budget--) { s->failed_pc=0x0c08397au; return 0; }
r[6]+=r[14];
goto P_0c08397c;
P_0c08397c: /* original 36cc, guest PC 0x0c08397c */
if(!s->budget--) { s->failed_pc=0x0c08397cu; return 0; }
r[6]+=r[12];
goto P_0c08397e;
P_0c08397e: /* original 5667, guest PC 0x0c08397e */
if(!s->budget--) { s->failed_pc=0x0c08397eu; return 0; }
r[6]=read(ram,r[6]+28,4);
goto P_0c083980;
P_0c083980: /* original 430b, guest PC 0x0c083980 */
if(!s->budget--) { s->failed_pc=0x0c083980u; return 0; }
target=r[3];
r[16]=code_base|0x0c083984u;
r[4]=0x00000014u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c083984u) { target=s->pc; goto dispatch; }
goto P_0c083984;
P_0c083982: /* original e414, guest PC 0x0c083982 */
if(!s->budget--) { s->failed_pc=0x0c083982u; return 0; }
r[4]=0x00000014u;
goto P_0c083984;
P_0c083984: /* original 9643, guest PC 0x0c083984 */
if(!s->budget--) { s->failed_pc=0x0c083984u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c083a0eu,2);
goto P_0c083986;
P_0c083986: /* original d324, guest PC 0x0c083986 */
if(!s->budget--) { s->failed_pc=0x0c083986u; return 0; }
r[3]=read(ram,0x0c083a18u,4);
goto P_0c083988;
P_0c083988: /* original 36ec, guest PC 0x0c083988 */
if(!s->budget--) { s->failed_pc=0x0c083988u; return 0; }
r[6]+=r[14];
goto P_0c08398a;
P_0c08398a: /* original 65f2, guest PC 0x0c08398a */
if(!s->budget--) { s->failed_pc=0x0c08398au; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c08398c;
P_0c08398c: /* original 36cc, guest PC 0x0c08398c */
if(!s->budget--) { s->failed_pc=0x0c08398cu; return 0; }
r[6]+=r[12];
goto P_0c08398e;
P_0c08398e: /* original 5667, guest PC 0x0c08398e */
if(!s->budget--) { s->failed_pc=0x0c08398eu; return 0; }
r[6]=read(ram,r[6]+28,4);
goto P_0c083990;
P_0c083990: /* original 430b, guest PC 0x0c083990 */
if(!s->budget--) { s->failed_pc=0x0c083990u; return 0; }
target=r[3];
r[16]=code_base|0x0c083994u;
r[4]=0x00000021u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c083994u) { target=s->pc; goto dispatch; }
goto P_0c083994;
P_0c083992: /* original e421, guest PC 0x0c083992 */
if(!s->budget--) { s->failed_pc=0x0c083992u; return 0; }
r[4]=0x00000021u;
goto P_0c083994;
P_0c083994: /* original a00f, guest PC 0x0c083994 */
if(!s->budget--) { s->failed_pc=0x0c083994u; return 0; }
goto P_0c0839b6;
P_0c083996: /* original 0009, guest PC 0x0c083996 */
if(!s->budget--) { s->failed_pc=0x0c083996u; return 0; }
goto P_0c083998;
P_0c083998: /* original d31e, guest PC 0x0c083998 */
if(!s->budget--) { s->failed_pc=0x0c083998u; return 0; }
r[3]=read(ram,0x0c083a14u,4);
goto P_0c08399a;
P_0c08399a: /* original 65d3, guest PC 0x0c08399a */
if(!s->budget--) { s->failed_pc=0x0c08399au; return 0; }
r[5]=r[13];
goto P_0c08399c;
P_0c08399c: /* original 6693, guest PC 0x0c08399c */
if(!s->budget--) { s->failed_pc=0x0c08399cu; return 0; }
r[6]=r[9];
goto P_0c08399e;
P_0c08399e: /* original 430b, guest PC 0x0c08399e */
if(!s->budget--) { s->failed_pc=0x0c08399eu; return 0; }
target=r[3];
r[16]=code_base|0x0c0839a2u;
r[4]=0x00000012u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0839a2u) { target=s->pc; goto dispatch; }
goto P_0c0839a2;
P_0c0839a0: /* original e412, guest PC 0x0c0839a0 */
if(!s->budget--) { s->failed_pc=0x0c0839a0u; return 0; }
r[4]=0x00000012u;
goto P_0c0839a2;
P_0c0839a2: /* original d21d, guest PC 0x0c0839a2 */
if(!s->budget--) { s->failed_pc=0x0c0839a2u; return 0; }
r[2]=read(ram,0x0c083a18u,4);
goto P_0c0839a4;
P_0c0839a4: /* original 65d3, guest PC 0x0c0839a4 */
if(!s->budget--) { s->failed_pc=0x0c0839a4u; return 0; }
r[5]=r[13];
goto P_0c0839a6;
P_0c0839a6: /* original e610, guest PC 0x0c0839a6 */
if(!s->budget--) { s->failed_pc=0x0c0839a6u; return 0; }
r[6]=0x00000010u;
goto P_0c0839a8;
P_0c0839a8: /* original 420b, guest PC 0x0c0839a8 */
if(!s->budget--) { s->failed_pc=0x0c0839a8u; return 0; }
target=r[2];
r[16]=code_base|0x0c0839acu;
r[4]=0x00000007u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0839acu) { target=s->pc; goto dispatch; }
goto P_0c0839ac;
P_0c0839aa: /* original e407, guest PC 0x0c0839aa */
if(!s->budget--) { s->failed_pc=0x0c0839aau; return 0; }
r[4]=0x00000007u;
goto P_0c0839ac;
P_0c0839ac: /* original d31a, guest PC 0x0c0839ac */
if(!s->budget--) { s->failed_pc=0x0c0839acu; return 0; }
r[3]=read(ram,0x0c083a18u,4);
goto P_0c0839ae;
P_0c0839ae: /* original e610, guest PC 0x0c0839ae */
if(!s->budget--) { s->failed_pc=0x0c0839aeu; return 0; }
r[6]=0x00000010u;
goto P_0c0839b0;
P_0c0839b0: /* original 65f2, guest PC 0x0c0839b0 */
if(!s->budget--) { s->failed_pc=0x0c0839b0u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0839b2;
P_0c0839b2: /* original 430b, guest PC 0x0c0839b2 */
if(!s->budget--) { s->failed_pc=0x0c0839b2u; return 0; }
target=r[3];
r[16]=code_base|0x0c0839b6u;
r[4]=0x00000021u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0839b6u) { target=s->pc; goto dispatch; }
goto P_0c0839b6;
P_0c0839b4: /* original e421, guest PC 0x0c0839b4 */
if(!s->budget--) { s->failed_pc=0x0c0839b4u; return 0; }
r[4]=0x00000021u;
goto P_0c0839b6;
P_0c0839b6: /* original 9327, guest PC 0x0c0839b6 */
if(!s->budget--) { s->failed_pc=0x0c0839b6u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c083a08u,2);
goto P_0c0839b8;
P_0c0839b8: /* original 60a3, guest PC 0x0c0839b8 */
if(!s->budget--) { s->failed_pc=0x0c0839b8u; return 0; }
r[0]=r[10];
goto P_0c0839ba;
P_0c0839ba: /* original 4008, guest PC 0x0c0839ba */
if(!s->budget--) { s->failed_pc=0x0c0839bau; return 0; }
r[0]<<=2;
goto P_0c0839bc;
P_0c0839bc: /* original 9928, guest PC 0x0c0839bc */
if(!s->budget--) { s->failed_pc=0x0c0839bcu; return 0; }
r[9]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c083a10u,2);
goto P_0c0839be;
P_0c0839be: /* original 33ec, guest PC 0x0c0839be */
if(!s->budget--) { s->failed_pc=0x0c0839beu; return 0; }
r[3]+=r[14];
goto P_0c0839c0;
P_0c0839c0: /* original 003e, guest PC 0x0c0839c0 */
if(!s->budget--) { s->failed_pc=0x0c0839c0u; return 0; }
r[0]=read(ram,r[3]+r[0],4);
goto P_0c0839c2;
P_0c0839c2: /* original 8801, guest PC 0x0c0839c2 */
if(!s->budget--) { s->failed_pc=0x0c0839c2u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c0839c4;
P_0c0839c4: /* original 8f45, guest PC 0x0c0839c4 */
if(!s->budget--) { s->failed_pc=0x0c0839c4u; return 0; }
cond=r[17]&1u;
r[13]+=0x00000002u;
if(!cond) { goto P_0c083a52; }
goto P_0c0839c8;
P_0c0839c6: /* original 7d02, guest PC 0x0c0839c6 */
if(!s->budget--) { s->failed_pc=0x0c0839c6u; return 0; }
r[13]+=0x00000002u;
goto P_0c0839c8;
P_0c0839c8: /* original 931f, guest PC 0x0c0839c8 */
if(!s->budget--) { s->failed_pc=0x0c0839c8u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c083a0au,2);
goto P_0c0839ca;
P_0c0839ca: /* original 60a3, guest PC 0x0c0839ca */
if(!s->budget--) { s->failed_pc=0x0c0839cau; return 0; }
r[0]=r[10];
goto P_0c0839cc;
P_0c0839cc: /* original 4008, guest PC 0x0c0839cc */
if(!s->budget--) { s->failed_pc=0x0c0839ccu; return 0; }
r[0]<<=2;
goto P_0c0839ce;
P_0c0839ce: /* original 33ec, guest PC 0x0c0839ce */
if(!s->budget--) { s->failed_pc=0x0c0839ceu; return 0; }
r[3]+=r[14];
goto P_0c0839d0;
P_0c0839d0: /* original 003e, guest PC 0x0c0839d0 */
if(!s->budget--) { s->failed_pc=0x0c0839d0u; return 0; }
r[0]=read(ram,r[3]+r[0],4);
goto P_0c0839d2;
P_0c0839d2: /* original 8808, guest PC 0x0c0839d2 */
if(!s->budget--) { s->failed_pc=0x0c0839d2u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000008u)!=0);
goto P_0c0839d4;
P_0c0839d4: /* original 8b26, guest PC 0x0c0839d4 */
if(!s->budget--) { s->failed_pc=0x0c0839d4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c083a24; }
goto P_0c0839d6;
P_0c0839d6: /* original 991c, guest PC 0x0c0839d6 */
if(!s->budget--) { s->failed_pc=0x0c0839d6u; return 0; }
r[9]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c083a12u,2);
goto P_0c0839d8;
P_0c0839d8: /* original 65d3, guest PC 0x0c0839d8 */
if(!s->budget--) { s->failed_pc=0x0c0839d8u; return 0; }
r[5]=r[13];
goto P_0c0839da;
P_0c0839da: /* original d30e, guest PC 0x0c0839da */
if(!s->budget--) { s->failed_pc=0x0c0839dau; return 0; }
r[3]=read(ram,0x0c083a14u,4);
goto P_0c0839dc;
P_0c0839dc: /* original 6693, guest PC 0x0c0839dc */
if(!s->budget--) { s->failed_pc=0x0c0839dcu; return 0; }
r[6]=r[9];
goto P_0c0839de;
P_0c0839de: /* original 430b, guest PC 0x0c0839de */
if(!s->budget--) { s->failed_pc=0x0c0839deu; return 0; }
target=r[3];
r[16]=code_base|0x0c0839e2u;
r[4]=0x00000012u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0839e2u) { target=s->pc; goto dispatch; }
goto P_0c0839e2;
P_0c0839e0: /* original e412, guest PC 0x0c0839e0 */
if(!s->budget--) { s->failed_pc=0x0c0839e0u; return 0; }
r[4]=0x00000012u;
goto P_0c0839e2;
P_0c0839e2: /* original 9614, guest PC 0x0c0839e2 */
if(!s->budget--) { s->failed_pc=0x0c0839e2u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c083a0eu,2);
goto P_0c0839e4;
P_0c0839e4: /* original 65d3, guest PC 0x0c0839e4 */
if(!s->budget--) { s->failed_pc=0x0c0839e4u; return 0; }
r[5]=r[13];
goto P_0c0839e6;
P_0c0839e6: /* original d30e, guest PC 0x0c0839e6 */
if(!s->budget--) { s->failed_pc=0x0c0839e6u; return 0; }
r[3]=read(ram,0x0c083a20u,4);
goto P_0c0839e8;
P_0c0839e8: /* original 36ec, guest PC 0x0c0839e8 */
if(!s->budget--) { s->failed_pc=0x0c0839e8u; return 0; }
r[6]+=r[14];
goto P_0c0839ea;
P_0c0839ea: /* original 36cc, guest PC 0x0c0839ea */
if(!s->budget--) { s->failed_pc=0x0c0839eau; return 0; }
r[6]+=r[12];
goto P_0c0839ec;
P_0c0839ec: /* original 5668, guest PC 0x0c0839ec */
if(!s->budget--) { s->failed_pc=0x0c0839ecu; return 0; }
r[6]=read(ram,r[6]+32,4);
goto P_0c0839ee;
P_0c0839ee: /* original 430b, guest PC 0x0c0839ee */
if(!s->budget--) { s->failed_pc=0x0c0839eeu; return 0; }
target=r[3];
r[16]=code_base|0x0c0839f2u;
r[4]=0x00000014u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0839f2u) { target=s->pc; goto dispatch; }
goto P_0c0839f2;
P_0c0839f0: /* original e414, guest PC 0x0c0839f0 */
if(!s->budget--) { s->failed_pc=0x0c0839f0u; return 0; }
r[4]=0x00000014u;
goto P_0c0839f2;
P_0c0839f2: /* original 960c, guest PC 0x0c0839f2 */
if(!s->budget--) { s->failed_pc=0x0c0839f2u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c083a0eu,2);
goto P_0c0839f4;
P_0c0839f4: /* original d30a, guest PC 0x0c0839f4 */
if(!s->budget--) { s->failed_pc=0x0c0839f4u; return 0; }
r[3]=read(ram,0x0c083a20u,4);
goto P_0c0839f6;
P_0c0839f6: /* original 36ec, guest PC 0x0c0839f6 */
if(!s->budget--) { s->failed_pc=0x0c0839f6u; return 0; }
r[6]+=r[14];
goto P_0c0839f8;
P_0c0839f8: /* original 65f2, guest PC 0x0c0839f8 */
if(!s->budget--) { s->failed_pc=0x0c0839f8u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0839fa;
P_0c0839fa: /* original 36cc, guest PC 0x0c0839fa */
if(!s->budget--) { s->failed_pc=0x0c0839fau; return 0; }
r[6]+=r[12];
goto P_0c0839fc;
P_0c0839fc: /* original 5668, guest PC 0x0c0839fc */
if(!s->budget--) { s->failed_pc=0x0c0839fcu; return 0; }
r[6]=read(ram,r[6]+32,4);
goto P_0c0839fe;
P_0c0839fe: /* original 430b, guest PC 0x0c0839fe */
if(!s->budget--) { s->failed_pc=0x0c0839feu; return 0; }
target=r[3];
r[16]=code_base|0x0c083a02u;
r[4]=0x00000031u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c083a02u) { target=s->pc; goto dispatch; }
goto P_0c083a02;
P_0c083a00: /* original e431, guest PC 0x0c083a00 */
if(!s->budget--) { s->failed_pc=0x0c083a00u; return 0; }
r[4]=0x00000031u;
goto P_0c083a02;
P_0c083a02: /* original a035, guest PC 0x0c083a02 */
if(!s->budget--) { s->failed_pc=0x0c083a02u; return 0; }
goto P_0c083a70;
P_0c083a04: /* original 0009, guest PC 0x0c083a04 */
if(!s->budget--) { s->failed_pc=0x0c083a04u; return 0; }
return vf3_matrix_family(0x0c083a06u,s,ram);
P_0c083a24: /* original d34a, guest PC 0x0c083a24 */
if(!s->budget--) { s->failed_pc=0x0c083a24u; return 0; }
r[3]=read(ram,0x0c083b50u,4);
goto P_0c083a26;
P_0c083a26: /* original 65d3, guest PC 0x0c083a26 */
if(!s->budget--) { s->failed_pc=0x0c083a26u; return 0; }
r[5]=r[13];
goto P_0c083a28;
P_0c083a28: /* original 6693, guest PC 0x0c083a28 */
if(!s->budget--) { s->failed_pc=0x0c083a28u; return 0; }
r[6]=r[9];
goto P_0c083a2a;
P_0c083a2a: /* original 430b, guest PC 0x0c083a2a */
if(!s->budget--) { s->failed_pc=0x0c083a2au; return 0; }
target=r[3];
r[16]=code_base|0x0c083a2eu;
r[4]=0x00000012u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c083a2eu) { target=s->pc; goto dispatch; }
goto P_0c083a2e;
P_0c083a2c: /* original e412, guest PC 0x0c083a2c */
if(!s->budget--) { s->failed_pc=0x0c083a2cu; return 0; }
r[4]=0x00000012u;
goto P_0c083a2e;
P_0c083a2e: /* original 9685, guest PC 0x0c083a2e */
if(!s->budget--) { s->failed_pc=0x0c083a2eu; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c083b3cu,2);
goto P_0c083a30;
P_0c083a30: /* original 65d3, guest PC 0x0c083a30 */
if(!s->budget--) { s->failed_pc=0x0c083a30u; return 0; }
r[5]=r[13];
goto P_0c083a32;
P_0c083a32: /* original d348, guest PC 0x0c083a32 */
if(!s->budget--) { s->failed_pc=0x0c083a32u; return 0; }
r[3]=read(ram,0x0c083b54u,4);
goto P_0c083a34;
P_0c083a34: /* original 36ec, guest PC 0x0c083a34 */
if(!s->budget--) { s->failed_pc=0x0c083a34u; return 0; }
r[6]+=r[14];
goto P_0c083a36;
P_0c083a36: /* original 36cc, guest PC 0x0c083a36 */
if(!s->budget--) { s->failed_pc=0x0c083a36u; return 0; }
r[6]+=r[12];
goto P_0c083a38;
P_0c083a38: /* original 5668, guest PC 0x0c083a38 */
if(!s->budget--) { s->failed_pc=0x0c083a38u; return 0; }
r[6]=read(ram,r[6]+32,4);
goto P_0c083a3a;
P_0c083a3a: /* original 430b, guest PC 0x0c083a3a */
if(!s->budget--) { s->failed_pc=0x0c083a3au; return 0; }
target=r[3];
r[16]=code_base|0x0c083a3eu;
r[4]=0x00000014u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c083a3eu) { target=s->pc; goto dispatch; }
goto P_0c083a3e;
P_0c083a3c: /* original e414, guest PC 0x0c083a3c */
if(!s->budget--) { s->failed_pc=0x0c083a3cu; return 0; }
r[4]=0x00000014u;
goto P_0c083a3e;
P_0c083a3e: /* original 967d, guest PC 0x0c083a3e */
if(!s->budget--) { s->failed_pc=0x0c083a3eu; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c083b3cu,2);
goto P_0c083a40;
P_0c083a40: /* original d344, guest PC 0x0c083a40 */
if(!s->budget--) { s->failed_pc=0x0c083a40u; return 0; }
r[3]=read(ram,0x0c083b54u,4);
goto P_0c083a42;
P_0c083a42: /* original 36ec, guest PC 0x0c083a42 */
if(!s->budget--) { s->failed_pc=0x0c083a42u; return 0; }
r[6]+=r[14];
goto P_0c083a44;
P_0c083a44: /* original 65f2, guest PC 0x0c083a44 */
if(!s->budget--) { s->failed_pc=0x0c083a44u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c083a46;
P_0c083a46: /* original 36cc, guest PC 0x0c083a46 */
if(!s->budget--) { s->failed_pc=0x0c083a46u; return 0; }
r[6]+=r[12];
goto P_0c083a48;
P_0c083a48: /* original 5668, guest PC 0x0c083a48 */
if(!s->budget--) { s->failed_pc=0x0c083a48u; return 0; }
r[6]=read(ram,r[6]+32,4);
goto P_0c083a4a;
P_0c083a4a: /* original 430b, guest PC 0x0c083a4a */
if(!s->budget--) { s->failed_pc=0x0c083a4au; return 0; }
target=r[3];
r[16]=code_base|0x0c083a4eu;
r[4]=0x00000031u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c083a4eu) { target=s->pc; goto dispatch; }
goto P_0c083a4e;
P_0c083a4c: /* original e431, guest PC 0x0c083a4c */
if(!s->budget--) { s->failed_pc=0x0c083a4cu; return 0; }
r[4]=0x00000031u;
goto P_0c083a4e;
P_0c083a4e: /* original a00f, guest PC 0x0c083a4e */
if(!s->budget--) { s->failed_pc=0x0c083a4eu; return 0; }
goto P_0c083a70;
P_0c083a50: /* original 0009, guest PC 0x0c083a50 */
if(!s->budget--) { s->failed_pc=0x0c083a50u; return 0; }
goto P_0c083a52;
P_0c083a52: /* original d33f, guest PC 0x0c083a52 */
if(!s->budget--) { s->failed_pc=0x0c083a52u; return 0; }
r[3]=read(ram,0x0c083b50u,4);
goto P_0c083a54;
P_0c083a54: /* original 65d3, guest PC 0x0c083a54 */
if(!s->budget--) { s->failed_pc=0x0c083a54u; return 0; }
r[5]=r[13];
goto P_0c083a56;
P_0c083a56: /* original 6693, guest PC 0x0c083a56 */
if(!s->budget--) { s->failed_pc=0x0c083a56u; return 0; }
r[6]=r[9];
goto P_0c083a58;
P_0c083a58: /* original 430b, guest PC 0x0c083a58 */
if(!s->budget--) { s->failed_pc=0x0c083a58u; return 0; }
target=r[3];
r[16]=code_base|0x0c083a5cu;
r[4]=0x00000012u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c083a5cu) { target=s->pc; goto dispatch; }
goto P_0c083a5c;
P_0c083a5a: /* original e412, guest PC 0x0c083a5a */
if(!s->budget--) { s->failed_pc=0x0c083a5au; return 0; }
r[4]=0x00000012u;
goto P_0c083a5c;
P_0c083a5c: /* original d23d, guest PC 0x0c083a5c */
if(!s->budget--) { s->failed_pc=0x0c083a5cu; return 0; }
r[2]=read(ram,0x0c083b54u,4);
goto P_0c083a5e;
P_0c083a5e: /* original 65d3, guest PC 0x0c083a5e */
if(!s->budget--) { s->failed_pc=0x0c083a5eu; return 0; }
r[5]=r[13];
goto P_0c083a60;
P_0c083a60: /* original e610, guest PC 0x0c083a60 */
if(!s->budget--) { s->failed_pc=0x0c083a60u; return 0; }
r[6]=0x00000010u;
goto P_0c083a62;
P_0c083a62: /* original 420b, guest PC 0x0c083a62 */
if(!s->budget--) { s->failed_pc=0x0c083a62u; return 0; }
target=r[2];
r[16]=code_base|0x0c083a66u;
r[4]=0x00000007u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c083a66u) { target=s->pc; goto dispatch; }
goto P_0c083a66;
P_0c083a64: /* original e407, guest PC 0x0c083a64 */
if(!s->budget--) { s->failed_pc=0x0c083a64u; return 0; }
r[4]=0x00000007u;
goto P_0c083a66;
P_0c083a66: /* original d33b, guest PC 0x0c083a66 */
if(!s->budget--) { s->failed_pc=0x0c083a66u; return 0; }
r[3]=read(ram,0x0c083b54u,4);
goto P_0c083a68;
P_0c083a68: /* original e610, guest PC 0x0c083a68 */
if(!s->budget--) { s->failed_pc=0x0c083a68u; return 0; }
r[6]=0x00000010u;
goto P_0c083a6a;
P_0c083a6a: /* original 65f2, guest PC 0x0c083a6a */
if(!s->budget--) { s->failed_pc=0x0c083a6au; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c083a6c;
P_0c083a6c: /* original 430b, guest PC 0x0c083a6c */
if(!s->budget--) { s->failed_pc=0x0c083a6cu; return 0; }
target=r[3];
r[16]=code_base|0x0c083a70u;
r[4]=0x00000031u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c083a70u) { target=s->pc; goto dispatch; }
goto P_0c083a70;
P_0c083a6e: /* original e431, guest PC 0x0c083a6e */
if(!s->budget--) { s->failed_pc=0x0c083a6eu; return 0; }
r[4]=0x00000031u;
goto P_0c083a70;
P_0c083a70: /* original 7a01, guest PC 0x0c083a70 */
if(!s->budget--) { s->failed_pc=0x0c083a70u; return 0; }
r[10]+=0x00000001u;
goto P_0c083a72;
P_0c083a72: /* original 7d0c, guest PC 0x0c083a72 */
if(!s->budget--) { s->failed_pc=0x0c083a72u; return 0; }
r[13]+=0x0000000cu;
goto P_0c083a74;
P_0c083a74: /* original e402, guest PC 0x0c083a74 */
if(!s->budget--) { s->failed_pc=0x0c083a74u; return 0; }
r[4]=0x00000002u;
goto P_0c083a76;
P_0c083a76: /* original 3a43, guest PC 0x0c083a76 */
if(!s->budget--) { s->failed_pc=0x0c083a76u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[10]>=(int32_t)r[4])!=0);
goto P_0c083a78;
P_0c083a78: /* original 8901, guest PC 0x0c083a78 */
if(!s->budget--) { s->failed_pc=0x0c083a78u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c083a7e; }
goto P_0c083a7a;
P_0c083a7a: /* original abce, guest PC 0x0c083a7a */
if(!s->budget--) { s->failed_pc=0x0c083a7au; return 0; }
goto P_0c08321a;
P_0c083a7c: /* original 0009, guest PC 0x0c083a7c */
if(!s->budget--) { s->failed_pc=0x0c083a7cu; return 0; }
goto P_0c083a7e;
P_0c083a7e: /* original 54f3, guest PC 0x0c083a7e */
if(!s->budget--) { s->failed_pc=0x0c083a7eu; return 0; }
r[4]=read(ram,r[15]+12,4);
goto P_0c083a80;
P_0c083a80: /* original 55f4, guest PC 0x0c083a80 */
if(!s->budget--) { s->failed_pc=0x0c083a80u; return 0; }
r[5]=read(ram,r[15]+16,4);
goto P_0c083a82;
P_0c083a82: /* original 7f14, guest PC 0x0c083a82 */
if(!s->budget--) { s->failed_pc=0x0c083a82u; return 0; }
r[15]+=0x00000014u;
goto P_0c083a84;
P_0c083a84: /* original 4f26, guest PC 0x0c083a84 */
if(!s->budget--) { s->failed_pc=0x0c083a84u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c083a86;
P_0c083a86: /* original d334, guest PC 0x0c083a86 */
if(!s->budget--) { s->failed_pc=0x0c083a86u; return 0; }
r[3]=read(ram,0x0c083b58u,4);
goto P_0c083a88;
P_0c083a88: /* original 68f6, guest PC 0x0c083a88 */
if(!s->budget--) { s->failed_pc=0x0c083a88u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c083a8a;
P_0c083a8a: /* original 69f6, guest PC 0x0c083a8a */
if(!s->budget--) { s->failed_pc=0x0c083a8au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c083a8c;
P_0c083a8c: /* original 6af6, guest PC 0x0c083a8c */
if(!s->budget--) { s->failed_pc=0x0c083a8cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c083a8e;
P_0c083a8e: /* original 6bf6, guest PC 0x0c083a8e */
if(!s->budget--) { s->failed_pc=0x0c083a8eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c083a90;
P_0c083a90: /* original 6cf6, guest PC 0x0c083a90 */
if(!s->budget--) { s->failed_pc=0x0c083a90u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c083a92;
P_0c083a92: /* original 6df6, guest PC 0x0c083a92 */
if(!s->budget--) { s->failed_pc=0x0c083a92u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c083a94;
P_0c083a94: /* original 432b, guest PC 0x0c083a94 */
if(!s->budget--) { s->failed_pc=0x0c083a94u; return 0; }
target=r[3];
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
P_0c083a96: /* original 6ef6, guest PC 0x0c083a96 */
if(!s->budget--) { s->failed_pc=0x0c083a96u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c083a98u,s,ram);
P_0c083aa8: /* original 4f22, guest PC 0x0c083aa8 */
if(!s->budget--) { s->failed_pc=0x0c083aa8u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c083aaa;
P_0c083aaa: /* original 7ff4, guest PC 0x0c083aaa */
if(!s->budget--) { s->failed_pc=0x0c083aaau; return 0; }
r[15]+=0xfffffff4u;
goto P_0c083aac;
P_0c083aac: /* original 1f42, guest PC 0x0c083aac */
if(!s->budget--) { s->failed_pc=0x0c083aacu; return 0; }
write(ram,r[15]+8,r[4],4);
goto P_0c083aae;
P_0c083aae: /* original dd2c, guest PC 0x0c083aae */
if(!s->budget--) { s->failed_pc=0x0c083aaeu; return 0; }
r[13]=read(ram,0x0c083b60u,4);
goto P_0c083ab0;
P_0c083ab0: /* original de2a, guest PC 0x0c083ab0 */
if(!s->budget--) { s->failed_pc=0x0c083ab0u; return 0; }
r[14]=read(ram,0x0c083b5cu,4);
goto P_0c083ab2;
P_0c083ab2: /* original 1fd1, guest PC 0x0c083ab2 */
if(!s->budget--) { s->failed_pc=0x0c083ab2u; return 0; }
write(ram,r[15]+4,r[13],4);
goto P_0c083ab4;
P_0c083ab4: /* original d32b, guest PC 0x0c083ab4 */
if(!s->budget--) { s->failed_pc=0x0c083ab4u; return 0; }
r[3]=read(ram,0x0c083b64u,4);
goto P_0c083ab6;
P_0c083ab6: /* original 430b, guest PC 0x0c083ab6 */
if(!s->budget--) { s->failed_pc=0x0c083ab6u; return 0; }
target=r[3];
r[16]=code_base|0x0c083abau;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c083abau) { target=s->pc; goto dispatch; }
goto P_0c083aba;
P_0c083ab8: /* original 64d3, guest PC 0x0c083ab8 */
if(!s->budget--) { s->failed_pc=0x0c083ab8u; return 0; }
r[4]=r[13];
goto P_0c083aba;
P_0c083aba: /* original d225, guest PC 0x0c083aba */
if(!s->budget--) { s->failed_pc=0x0c083abau; return 0; }
r[2]=read(ram,0x0c083b50u,4);
goto P_0c083abc;
P_0c083abc: /* original e50b, guest PC 0x0c083abc */
if(!s->budget--) { s->failed_pc=0x0c083abcu; return 0; }
r[5]=0x0000000bu;
goto P_0c083abe;
P_0c083abe: /* original 963e, guest PC 0x0c083abe */
if(!s->budget--) { s->failed_pc=0x0c083abeu; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c083b3eu,2);
goto P_0c083ac0;
P_0c083ac0: /* original 420b, guest PC 0x0c083ac0 */
if(!s->budget--) { s->failed_pc=0x0c083ac0u; return 0; }
target=r[2];
r[16]=code_base|0x0c083ac4u;
r[4]=0x00000017u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c083ac4u) { target=s->pc; goto dispatch; }
goto P_0c083ac4;
P_0c083ac2: /* original e417, guest PC 0x0c083ac2 */
if(!s->budget--) { s->failed_pc=0x0c083ac2u; return 0; }
r[4]=0x00000017u;
goto P_0c083ac4;
P_0c083ac4: /* original 9a3c, guest PC 0x0c083ac4 */
if(!s->budget--) { s->failed_pc=0x0c083ac4u; return 0; }
r[10]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c083b40u,2);
goto P_0c083ac6;
P_0c083ac6: /* original ed00, guest PC 0x0c083ac6 */
if(!s->budget--) { s->failed_pc=0x0c083ac6u; return 0; }
r[13]=0x00000000u;
goto P_0c083ac8;
P_0c083ac8: /* original 9b3b, guest PC 0x0c083ac8 */
if(!s->budget--) { s->failed_pc=0x0c083ac8u; return 0; }
r[11]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c083b42u,2);
goto P_0c083aca;
P_0c083aca: /* original d928, guest PC 0x0c083aca */
if(!s->budget--) { s->failed_pc=0x0c083acau; return 0; }
r[9]=read(ram,0x0c083b6cu,4);
goto P_0c083acc;
P_0c083acc: /* original d826, guest PC 0x0c083acc */
if(!s->budget--) { s->failed_pc=0x0c083accu; return 0; }
r[8]=read(ram,0x0c083b68u,4);
goto P_0c083ace;
P_0c083ace: /* original d328, guest PC 0x0c083ace */
if(!s->budget--) { s->failed_pc=0x0c083aceu; return 0; }
r[3]=read(ram,0x0c083b70u,4);
goto P_0c083ad0;
P_0c083ad0: /* original e500, guest PC 0x0c083ad0 */
if(!s->budget--) { s->failed_pc=0x0c083ad0u; return 0; }
r[5]=0x00000000u;
goto P_0c083ad2;
P_0c083ad2: /* original 430b, guest PC 0x0c083ad2 */
if(!s->budget--) { s->failed_pc=0x0c083ad2u; return 0; }
target=r[3];
r[16]=code_base|0x0c083ad6u;
r[4]=read(ram,r[15]+4,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c083ad6u) { target=s->pc; goto dispatch; }
goto P_0c083ad6;
P_0c083ad4: /* original 54f1, guest PC 0x0c083ad4 */
if(!s->budget--) { s->failed_pc=0x0c083ad4u; return 0; }
r[4]=read(ram,r[15]+4,4);
goto P_0c083ad6;
P_0c083ad6: /* original 60d3, guest PC 0x0c083ad6 */
if(!s->budget--) { s->failed_pc=0x0c083ad6u; return 0; }
r[0]=r[13];
goto P_0c083ad8;
P_0c083ad8: /* original 8800, guest PC 0x0c083ad8 */
if(!s->budget--) { s->failed_pc=0x0c083ad8u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000000u)!=0);
goto P_0c083ada;
P_0c083ada: /* original 8909, guest PC 0x0c083ada */
if(!s->budget--) { s->failed_pc=0x0c083adau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c083af0; }
goto P_0c083adc;
P_0c083adc: /* original 8801, guest PC 0x0c083adc */
if(!s->budget--) { s->failed_pc=0x0c083adcu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c083ade;
P_0c083ade: /* original 894b, guest PC 0x0c083ade */
if(!s->budget--) { s->failed_pc=0x0c083adeu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c083b78; }
goto P_0c083ae0;
P_0c083ae0: /* original 8802, guest PC 0x0c083ae0 */
if(!s->budget--) { s->failed_pc=0x0c083ae0u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c083ae2;
P_0c083ae2: /* original 896d, guest PC 0x0c083ae2 */
if(!s->budget--) { s->failed_pc=0x0c083ae2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c083bc0; }
goto P_0c083ae4;
P_0c083ae4: /* original 8803, guest PC 0x0c083ae4 */
if(!s->budget--) { s->failed_pc=0x0c083ae4u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000003u)!=0);
goto P_0c083ae6;
P_0c083ae6: /* original 8b01, guest PC 0x0c083ae6 */
if(!s->budget--) { s->failed_pc=0x0c083ae6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c083aec; }
goto P_0c083ae8;
P_0c083ae8: /* original a092, guest PC 0x0c083ae8 */
if(!s->budget--) { s->failed_pc=0x0c083ae8u; return 0; }
goto P_0c083c10;
P_0c083aea: /* original 0009, guest PC 0x0c083aea */
if(!s->budget--) { s->failed_pc=0x0c083aeau; return 0; }
goto P_0c083aec;
P_0c083aec: /* original a09c, guest PC 0x0c083aec */
if(!s->budget--) { s->failed_pc=0x0c083aecu; return 0; }
goto P_0c083c28;
P_0c083aee: /* original 0009, guest PC 0x0c083aee */
if(!s->budget--) { s->failed_pc=0x0c083aeeu; return 0; }
goto P_0c083af0;
P_0c083af0: /* original 9028, guest PC 0x0c083af0 */
if(!s->budget--) { s->failed_pc=0x0c083af0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c083b44u,2);
goto P_0c083af2;
P_0c083af2: /* original 02ee, guest PC 0x0c083af2 */
if(!s->budget--) { s->failed_pc=0x0c083af2u; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c083af4;
P_0c083af4: /* original 3d20, guest PC 0x0c083af4 */
if(!s->budget--) { s->failed_pc=0x0c083af4u; return 0; }
r[17]=(r[17]&~1u)|((r[13]==r[2])!=0);
goto P_0c083af6;
P_0c083af6: /* original 8b0d, guest PC 0x0c083af6 */
if(!s->budget--) { s->failed_pc=0x0c083af6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c083b14; }
goto P_0c083af8;
P_0c083af8: /* original d215, guest PC 0x0c083af8 */
if(!s->budget--) { s->failed_pc=0x0c083af8u; return 0; }
r[2]=read(ram,0x0c083b50u,4);
goto P_0c083afa;
P_0c083afa: /* original e512, guest PC 0x0c083afa */
if(!s->budget--) { s->failed_pc=0x0c083afau; return 0; }
r[5]=0x00000012u;
goto P_0c083afc;
P_0c083afc: /* original 9623, guest PC 0x0c083afc */
if(!s->budget--) { s->failed_pc=0x0c083afcu; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c083b46u,2);
goto P_0c083afe;
P_0c083afe: /* original 420b, guest PC 0x0c083afe */
if(!s->budget--) { s->failed_pc=0x0c083afeu; return 0; }
target=r[2];
r[16]=code_base|0x0c083b02u;
r[4]=0x00000010u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c083b02u) { target=s->pc; goto dispatch; }
goto P_0c083b02;
P_0c083b00: /* original e410, guest PC 0x0c083b00 */
if(!s->budget--) { s->failed_pc=0x0c083b00u; return 0; }
r[4]=0x00000010u;
goto P_0c083b02;
P_0c083b02: /* original d313, guest PC 0x0c083b02 */
if(!s->budget--) { s->failed_pc=0x0c083b02u; return 0; }
r[3]=read(ram,0x0c083b50u,4);
goto P_0c083b04;
P_0c083b04: /* original e513, guest PC 0x0c083b04 */
if(!s->budget--) { s->failed_pc=0x0c083b04u; return 0; }
r[5]=0x00000013u;
goto P_0c083b06;
P_0c083b06: /* original 66b3, guest PC 0x0c083b06 */
if(!s->budget--) { s->failed_pc=0x0c083b06u; return 0; }
r[6]=r[11];
goto P_0c083b08;
P_0c083b08: /* original 430b, guest PC 0x0c083b08 */
if(!s->budget--) { s->failed_pc=0x0c083b08u; return 0; }
target=r[3];
r[16]=code_base|0x0c083b0cu;
r[4]=0x0000001du;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c083b0cu) { target=s->pc; goto dispatch; }
goto P_0c083b0c;
P_0c083b0a: /* original e41d, guest PC 0x0c083b0a */
if(!s->budget--) { s->failed_pc=0x0c083b0au; return 0; }
r[4]=0x0000001du;
goto P_0c083b0c;
P_0c083b0c: /* original e513, guest PC 0x0c083b0c */
if(!s->budget--) { s->failed_pc=0x0c083b0cu; return 0; }
r[5]=0x00000013u;
goto P_0c083b0e;
P_0c083b0e: /* original 66a3, guest PC 0x0c083b0e */
if(!s->budget--) { s->failed_pc=0x0c083b0eu; return 0; }
r[6]=r[10];
goto P_0c083b10;
P_0c083b10: /* original a003, guest PC 0x0c083b10 */
if(!s->budget--) { s->failed_pc=0x0c083b10u; return 0; }
r[4]=0x00000038u;
goto P_0c083b1a;
P_0c083b12: /* original e438, guest PC 0x0c083b12 */
if(!s->budget--) { s->failed_pc=0x0c083b12u; return 0; }
r[4]=0x00000038u;
goto P_0c083b14;
P_0c083b14: /* original 9618, guest PC 0x0c083b14 */
if(!s->budget--) { s->failed_pc=0x0c083b14u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c083b48u,2);
goto P_0c083b16;
P_0c083b16: /* original e410, guest PC 0x0c083b16 */
if(!s->budget--) { s->failed_pc=0x0c083b16u; return 0; }
r[4]=0x00000010u;
goto P_0c083b18;
P_0c083b18: /* original e512, guest PC 0x0c083b18 */
if(!s->budget--) { s->failed_pc=0x0c083b18u; return 0; }
r[5]=0x00000012u;
goto P_0c083b1a;
P_0c083b1a: /* original d20d, guest PC 0x0c083b1a */
if(!s->budget--) { s->failed_pc=0x0c083b1au; return 0; }
r[2]=read(ram,0x0c083b50u,4);
goto P_0c083b1c;
P_0c083b1c: /* original 420b, guest PC 0x0c083b1c */
if(!s->budget--) { s->failed_pc=0x0c083b1cu; return 0; }
target=r[2];
r[16]=code_base|0x0c083b20u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c083b20u) { target=s->pc; goto dispatch; }
goto P_0c083b20;
P_0c083b1e: /* original 0009, guest PC 0x0c083b1e */
if(!s->budget--) { s->failed_pc=0x0c083b1eu; return 0; }
goto P_0c083b20;
P_0c083b20: /* original 9014, guest PC 0x0c083b20 */
if(!s->budget--) { s->failed_pc=0x0c083b20u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c083b4cu,2);
goto P_0c083b22;
P_0c083b22: /* original 9c12, guest PC 0x0c083b22 */
if(!s->budget--) { s->failed_pc=0x0c083b22u; return 0; }
r[12]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c083b4au,2);
goto P_0c083b24;
P_0c083b24: /* original 03ee, guest PC 0x0c083b24 */
if(!s->budget--) { s->failed_pc=0x0c083b24u; return 0; }
r[3]=read(ram,r[14]+r[0],4);
goto P_0c083b26;
P_0c083b26: /* original 6233, guest PC 0x0c083b26 */
if(!s->budget--) { s->failed_pc=0x0c083b26u; return 0; }
r[2]=r[3];
goto P_0c083b28;
P_0c083b28: /* original 2f32, guest PC 0x0c083b28 */
if(!s->budget--) { s->failed_pc=0x0c083b28u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c083b2a;
P_0c083b2a: /* original 4300, guest PC 0x0c083b2a */
if(!s->budget--) { s->failed_pc=0x0c083b2au; return 0; }
r[17]=(r[17]&~1u)|((r[3]>>31)!=0);
r[3]<<=1;
goto P_0c083b2c;
P_0c083b2c: /* original d011, guest PC 0x0c083b2c */
if(!s->budget--) { s->failed_pc=0x0c083b2cu; return 0; }
r[0]=read(ram,0x0c083b74u,4);
goto P_0c083b2e;
P_0c083b2e: /* original 332c, guest PC 0x0c083b2e */
if(!s->budget--) { s->failed_pc=0x0c083b2eu; return 0; }
r[3]+=r[2];
goto P_0c083b30;
P_0c083b30: /* original 4308, guest PC 0x0c083b30 */
if(!s->budget--) { s->failed_pc=0x0c083b30u; return 0; }
r[3]<<=2;
goto P_0c083b32;
P_0c083b32: /* original 013e, guest PC 0x0c083b32 */
if(!s->budget--) { s->failed_pc=0x0c083b32u; return 0; }
r[1]=read(ram,r[3]+r[0],4);
goto P_0c083b34;
P_0c083b34: /* original 2f16, guest PC 0x0c083b34 */
if(!s->budget--) { s->failed_pc=0x0c083b34u; return 0; }
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c083b36;
P_0c083b36: /* original 52f1, guest PC 0x0c083b36 */
if(!s->budget--) { s->failed_pc=0x0c083b36u; return 0; }
r[2]=read(ram,r[15]+4,4);
goto P_0c083b38;
P_0c083b38: /* original a065, guest PC 0x0c083b38 */
if(!s->budget--) { s->failed_pc=0x0c083b38u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c083c06;
P_0c083b3a: /* original 2f26, guest PC 0x0c083b3a */
if(!s->budget--) { s->failed_pc=0x0c083b3au; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
return vf3_matrix_family(0x0c083b3cu,s,ram);
P_0c083b78: /* original 906d, guest PC 0x0c083b78 */
if(!s->budget--) { s->failed_pc=0x0c083b78u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c083c56u,2);
goto P_0c083b7a;
P_0c083b7a: /* original 02ee, guest PC 0x0c083b7a */
if(!s->budget--) { s->failed_pc=0x0c083b7au; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c083b7c;
P_0c083b7c: /* original 3d20, guest PC 0x0c083b7c */
if(!s->budget--) { s->failed_pc=0x0c083b7cu; return 0; }
r[17]=(r[17]&~1u)|((r[13]==r[2])!=0);
goto P_0c083b7e;
P_0c083b7e: /* original 8b0d, guest PC 0x0c083b7e */
if(!s->budget--) { s->failed_pc=0x0c083b7eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c083b9c; }
goto P_0c083b80;
P_0c083b80: /* original d23b, guest PC 0x0c083b80 */
if(!s->budget--) { s->failed_pc=0x0c083b80u; return 0; }
r[2]=read(ram,0x0c083c70u,4);
goto P_0c083b82;
P_0c083b82: /* original e516, guest PC 0x0c083b82 */
if(!s->budget--) { s->failed_pc=0x0c083b82u; return 0; }
r[5]=0x00000016u;
goto P_0c083b84;
P_0c083b84: /* original 9668, guest PC 0x0c083b84 */
if(!s->budget--) { s->failed_pc=0x0c083b84u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c083c58u,2);
goto P_0c083b86;
P_0c083b86: /* original 420b, guest PC 0x0c083b86 */
if(!s->budget--) { s->failed_pc=0x0c083b86u; return 0; }
target=r[2];
r[16]=code_base|0x0c083b8au;
r[4]=0x00000010u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c083b8au) { target=s->pc; goto dispatch; }
goto P_0c083b8a;
P_0c083b88: /* original e410, guest PC 0x0c083b88 */
if(!s->budget--) { s->failed_pc=0x0c083b88u; return 0; }
r[4]=0x00000010u;
goto P_0c083b8a;
P_0c083b8a: /* original d339, guest PC 0x0c083b8a */
if(!s->budget--) { s->failed_pc=0x0c083b8au; return 0; }
r[3]=read(ram,0x0c083c70u,4);
goto P_0c083b8c;
P_0c083b8c: /* original e517, guest PC 0x0c083b8c */
if(!s->budget--) { s->failed_pc=0x0c083b8cu; return 0; }
r[5]=0x00000017u;
goto P_0c083b8e;
P_0c083b8e: /* original 66b3, guest PC 0x0c083b8e */
if(!s->budget--) { s->failed_pc=0x0c083b8eu; return 0; }
r[6]=r[11];
goto P_0c083b90;
P_0c083b90: /* original 430b, guest PC 0x0c083b90 */
if(!s->budget--) { s->failed_pc=0x0c083b90u; return 0; }
target=r[3];
r[16]=code_base|0x0c083b94u;
r[4]=0x0000001du;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c083b94u) { target=s->pc; goto dispatch; }
goto P_0c083b94;
P_0c083b92: /* original e41d, guest PC 0x0c083b92 */
if(!s->budget--) { s->failed_pc=0x0c083b92u; return 0; }
r[4]=0x0000001du;
goto P_0c083b94;
P_0c083b94: /* original e517, guest PC 0x0c083b94 */
if(!s->budget--) { s->failed_pc=0x0c083b94u; return 0; }
r[5]=0x00000017u;
goto P_0c083b96;
P_0c083b96: /* original 66a3, guest PC 0x0c083b96 */
if(!s->budget--) { s->failed_pc=0x0c083b96u; return 0; }
r[6]=r[10];
goto P_0c083b98;
P_0c083b98: /* original a003, guest PC 0x0c083b98 */
if(!s->budget--) { s->failed_pc=0x0c083b98u; return 0; }
r[4]=0x00000038u;
goto P_0c083ba2;
P_0c083b9a: /* original e438, guest PC 0x0c083b9a */
if(!s->budget--) { s->failed_pc=0x0c083b9au; return 0; }
r[4]=0x00000038u;
goto P_0c083b9c;
P_0c083b9c: /* original 965d, guest PC 0x0c083b9c */
if(!s->budget--) { s->failed_pc=0x0c083b9cu; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c083c5au,2);
goto P_0c083b9e;
P_0c083b9e: /* original e410, guest PC 0x0c083b9e */
if(!s->budget--) { s->failed_pc=0x0c083b9eu; return 0; }
r[4]=0x00000010u;
goto P_0c083ba0;
P_0c083ba0: /* original e516, guest PC 0x0c083ba0 */
if(!s->budget--) { s->failed_pc=0x0c083ba0u; return 0; }
r[5]=0x00000016u;
goto P_0c083ba2;
P_0c083ba2: /* original d233, guest PC 0x0c083ba2 */
if(!s->budget--) { s->failed_pc=0x0c083ba2u; return 0; }
r[2]=read(ram,0x0c083c70u,4);
goto P_0c083ba4;
P_0c083ba4: /* original 420b, guest PC 0x0c083ba4 */
if(!s->budget--) { s->failed_pc=0x0c083ba4u; return 0; }
target=r[2];
r[16]=code_base|0x0c083ba8u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c083ba8u) { target=s->pc; goto dispatch; }
goto P_0c083ba8;
P_0c083ba6: /* original 0009, guest PC 0x0c083ba6 */
if(!s->budget--) { s->failed_pc=0x0c083ba6u; return 0; }
goto P_0c083ba8;
P_0c083ba8: /* original 9059, guest PC 0x0c083ba8 */
if(!s->budget--) { s->failed_pc=0x0c083ba8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c083c5eu,2);
goto P_0c083baa;
P_0c083baa: /* original 9c57, guest PC 0x0c083baa */
if(!s->budget--) { s->failed_pc=0x0c083baau; return 0; }
r[12]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c083c5cu,2);
goto P_0c083bac;
P_0c083bac: /* original 03ee, guest PC 0x0c083bac */
if(!s->budget--) { s->failed_pc=0x0c083bacu; return 0; }
r[3]=read(ram,r[14]+r[0],4);
goto P_0c083bae;
P_0c083bae: /* original 2f32, guest PC 0x0c083bae */
if(!s->budget--) { s->failed_pc=0x0c083baeu; return 0; }
write(ram,r[15],r[3],4);
goto P_0c083bb0;
P_0c083bb0: /* original 4308, guest PC 0x0c083bb0 */
if(!s->budget--) { s->failed_pc=0x0c083bb0u; return 0; }
r[3]<<=2;
goto P_0c083bb2;
P_0c083bb2: /* original d030, guest PC 0x0c083bb2 */
if(!s->budget--) { s->failed_pc=0x0c083bb2u; return 0; }
r[0]=read(ram,0x0c083c74u,4);
goto P_0c083bb4;
P_0c083bb4: /* original 4300, guest PC 0x0c083bb4 */
if(!s->budget--) { s->failed_pc=0x0c083bb4u; return 0; }
r[17]=(r[17]&~1u)|((r[3]>>31)!=0);
r[3]<<=1;
goto P_0c083bb6;
P_0c083bb6: /* original 023e, guest PC 0x0c083bb6 */
if(!s->budget--) { s->failed_pc=0x0c083bb6u; return 0; }
r[2]=read(ram,r[3]+r[0],4);
goto P_0c083bb8;
P_0c083bb8: /* original 2f26, guest PC 0x0c083bb8 */
if(!s->budget--) { s->failed_pc=0x0c083bb8u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c083bba;
P_0c083bba: /* original 51f1, guest PC 0x0c083bba */
if(!s->budget--) { s->failed_pc=0x0c083bbau; return 0; }
r[1]=read(ram,r[15]+4,4);
goto P_0c083bbc;
P_0c083bbc: /* original a023, guest PC 0x0c083bbc */
if(!s->budget--) { s->failed_pc=0x0c083bbcu; return 0; }
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c083c06;
P_0c083bbe: /* original 2f16, guest PC 0x0c083bbe */
if(!s->budget--) { s->failed_pc=0x0c083bbeu; return 0; }
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c083bc0;
P_0c083bc0: /* original 9049, guest PC 0x0c083bc0 */
if(!s->budget--) { s->failed_pc=0x0c083bc0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c083c56u,2);
goto P_0c083bc2;
P_0c083bc2: /* original 02ee, guest PC 0x0c083bc2 */
if(!s->budget--) { s->failed_pc=0x0c083bc2u; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c083bc4;
P_0c083bc4: /* original 3d20, guest PC 0x0c083bc4 */
if(!s->budget--) { s->failed_pc=0x0c083bc4u; return 0; }
r[17]=(r[17]&~1u)|((r[13]==r[2])!=0);
goto P_0c083bc6;
P_0c083bc6: /* original 8b0d, guest PC 0x0c083bc6 */
if(!s->budget--) { s->failed_pc=0x0c083bc6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c083be4; }
goto P_0c083bc8;
P_0c083bc8: /* original d229, guest PC 0x0c083bc8 */
if(!s->budget--) { s->failed_pc=0x0c083bc8u; return 0; }
r[2]=read(ram,0x0c083c70u,4);
goto P_0c083bca;
P_0c083bca: /* original e51a, guest PC 0x0c083bca */
if(!s->budget--) { s->failed_pc=0x0c083bcau; return 0; }
r[5]=0x0000001au;
goto P_0c083bcc;
P_0c083bcc: /* original 9648, guest PC 0x0c083bcc */
if(!s->budget--) { s->failed_pc=0x0c083bccu; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c083c60u,2);
goto P_0c083bce;
P_0c083bce: /* original 420b, guest PC 0x0c083bce */
if(!s->budget--) { s->failed_pc=0x0c083bceu; return 0; }
target=r[2];
r[16]=code_base|0x0c083bd2u;
r[4]=0x00000010u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c083bd2u) { target=s->pc; goto dispatch; }
goto P_0c083bd2;
P_0c083bd0: /* original e410, guest PC 0x0c083bd0 */
if(!s->budget--) { s->failed_pc=0x0c083bd0u; return 0; }
r[4]=0x00000010u;
goto P_0c083bd2;
P_0c083bd2: /* original d327, guest PC 0x0c083bd2 */
if(!s->budget--) { s->failed_pc=0x0c083bd2u; return 0; }
r[3]=read(ram,0x0c083c70u,4);
goto P_0c083bd4;
P_0c083bd4: /* original e51b, guest PC 0x0c083bd4 */
if(!s->budget--) { s->failed_pc=0x0c083bd4u; return 0; }
r[5]=0x0000001bu;
goto P_0c083bd6;
P_0c083bd6: /* original 66b3, guest PC 0x0c083bd6 */
if(!s->budget--) { s->failed_pc=0x0c083bd6u; return 0; }
r[6]=r[11];
goto P_0c083bd8;
P_0c083bd8: /* original 430b, guest PC 0x0c083bd8 */
if(!s->budget--) { s->failed_pc=0x0c083bd8u; return 0; }
target=r[3];
r[16]=code_base|0x0c083bdcu;
r[4]=0x0000001du;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c083bdcu) { target=s->pc; goto dispatch; }
goto P_0c083bdc;
P_0c083bda: /* original e41d, guest PC 0x0c083bda */
if(!s->budget--) { s->failed_pc=0x0c083bdau; return 0; }
r[4]=0x0000001du;
goto P_0c083bdc;
P_0c083bdc: /* original e51b, guest PC 0x0c083bdc */
if(!s->budget--) { s->failed_pc=0x0c083bdcu; return 0; }
r[5]=0x0000001bu;
goto P_0c083bde;
P_0c083bde: /* original 66a3, guest PC 0x0c083bde */
if(!s->budget--) { s->failed_pc=0x0c083bdeu; return 0; }
r[6]=r[10];
goto P_0c083be0;
P_0c083be0: /* original a003, guest PC 0x0c083be0 */
if(!s->budget--) { s->failed_pc=0x0c083be0u; return 0; }
r[4]=0x00000038u;
goto P_0c083bea;
P_0c083be2: /* original e438, guest PC 0x0c083be2 */
if(!s->budget--) { s->failed_pc=0x0c083be2u; return 0; }
r[4]=0x00000038u;
goto P_0c083be4;
P_0c083be4: /* original 963d, guest PC 0x0c083be4 */
if(!s->budget--) { s->failed_pc=0x0c083be4u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c083c62u,2);
goto P_0c083be6;
P_0c083be6: /* original e410, guest PC 0x0c083be6 */
if(!s->budget--) { s->failed_pc=0x0c083be6u; return 0; }
r[4]=0x00000010u;
goto P_0c083be8;
P_0c083be8: /* original e51a, guest PC 0x0c083be8 */
if(!s->budget--) { s->failed_pc=0x0c083be8u; return 0; }
r[5]=0x0000001au;
goto P_0c083bea;
P_0c083bea: /* original d221, guest PC 0x0c083bea */
if(!s->budget--) { s->failed_pc=0x0c083beau; return 0; }
r[2]=read(ram,0x0c083c70u,4);
goto P_0c083bec;
P_0c083bec: /* original 420b, guest PC 0x0c083bec */
if(!s->budget--) { s->failed_pc=0x0c083becu; return 0; }
target=r[2];
r[16]=code_base|0x0c083bf0u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c083bf0u) { target=s->pc; goto dispatch; }
goto P_0c083bf0;
P_0c083bee: /* original 0009, guest PC 0x0c083bee */
if(!s->budget--) { s->failed_pc=0x0c083beeu; return 0; }
goto P_0c083bf0;
P_0c083bf0: /* original 9039, guest PC 0x0c083bf0 */
if(!s->budget--) { s->failed_pc=0x0c083bf0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c083c66u,2);
goto P_0c083bf2;
P_0c083bf2: /* original 9c37, guest PC 0x0c083bf2 */
if(!s->budget--) { s->failed_pc=0x0c083bf2u; return 0; }
r[12]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c083c64u,2);
goto P_0c083bf4;
P_0c083bf4: /* original 03ee, guest PC 0x0c083bf4 */
if(!s->budget--) { s->failed_pc=0x0c083bf4u; return 0; }
r[3]=read(ram,r[14]+r[0],4);
goto P_0c083bf6;
P_0c083bf6: /* original 2f32, guest PC 0x0c083bf6 */
if(!s->budget--) { s->failed_pc=0x0c083bf6u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c083bf8;
P_0c083bf8: /* original 4308, guest PC 0x0c083bf8 */
if(!s->budget--) { s->failed_pc=0x0c083bf8u; return 0; }
r[3]<<=2;
goto P_0c083bfa;
P_0c083bfa: /* original d01f, guest PC 0x0c083bfa */
if(!s->budget--) { s->failed_pc=0x0c083bfau; return 0; }
r[0]=read(ram,0x0c083c78u,4);
goto P_0c083bfc;
P_0c083bfc: /* original 4300, guest PC 0x0c083bfc */
if(!s->budget--) { s->failed_pc=0x0c083bfcu; return 0; }
r[17]=(r[17]&~1u)|((r[3]>>31)!=0);
r[3]<<=1;
goto P_0c083bfe;
P_0c083bfe: /* original 023e, guest PC 0x0c083bfe */
if(!s->budget--) { s->failed_pc=0x0c083bfeu; return 0; }
r[2]=read(ram,r[3]+r[0],4);
goto P_0c083c00;
P_0c083c00: /* original 2f26, guest PC 0x0c083c00 */
if(!s->budget--) { s->failed_pc=0x0c083c00u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c083c02;
P_0c083c02: /* original 51f1, guest PC 0x0c083c02 */
if(!s->budget--) { s->failed_pc=0x0c083c02u; return 0; }
r[1]=read(ram,r[15]+4,4);
goto P_0c083c04;
P_0c083c04: /* original 2f16, guest PC 0x0c083c04 */
if(!s->budget--) { s->failed_pc=0x0c083c04u; return 0; }
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c083c06;
P_0c083c06: /* original 2f86, guest PC 0x0c083c06 */
if(!s->budget--) { s->failed_pc=0x0c083c06u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c083c08;
P_0c083c08: /* original 490b, guest PC 0x0c083c08 */
if(!s->budget--) { s->failed_pc=0x0c083c08u; return 0; }
target=r[9];
r[16]=code_base|0x0c083c0cu;
r[4]=r[12];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c083c0cu) { target=s->pc; goto dispatch; }
goto P_0c083c0c;
P_0c083c0a: /* original 64c3, guest PC 0x0c083c0a */
if(!s->budget--) { s->failed_pc=0x0c083c0au; return 0; }
r[4]=r[12];
goto P_0c083c0c;
P_0c083c0c: /* original a00c, guest PC 0x0c083c0c */
if(!s->budget--) { s->failed_pc=0x0c083c0cu; return 0; }
r[15]+=0x0000000cu;
goto P_0c083c28;
P_0c083c0e: /* original 7f0c, guest PC 0x0c083c0e */
if(!s->budget--) { s->failed_pc=0x0c083c0eu; return 0; }
r[15]+=0x0000000cu;
goto P_0c083c10;
P_0c083c10: /* original 9021, guest PC 0x0c083c10 */
if(!s->budget--) { s->failed_pc=0x0c083c10u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c083c56u,2);
goto P_0c083c12;
P_0c083c12: /* original 02ee, guest PC 0x0c083c12 */
if(!s->budget--) { s->failed_pc=0x0c083c12u; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c083c14;
P_0c083c14: /* original 3d20, guest PC 0x0c083c14 */
if(!s->budget--) { s->failed_pc=0x0c083c14u; return 0; }
r[17]=(r[17]&~1u)|((r[13]==r[2])!=0);
goto P_0c083c16;
P_0c083c16: /* original 8f03, guest PC 0x0c083c16 */
if(!s->budget--) { s->failed_pc=0x0c083c16u; return 0; }
cond=r[17]&1u;
r[5]=0x0000001fu;
if(!cond) { goto P_0c083c20; }
goto P_0c083c1a;
P_0c083c18: /* original e51f, guest PC 0x0c083c18 */
if(!s->budget--) { s->failed_pc=0x0c083c18u; return 0; }
r[5]=0x0000001fu;
goto P_0c083c1a;
P_0c083c1a: /* original 9625, guest PC 0x0c083c1a */
if(!s->budget--) { s->failed_pc=0x0c083c1au; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c083c68u,2);
goto P_0c083c1c;
P_0c083c1c: /* original a001, guest PC 0x0c083c1c */
if(!s->budget--) { s->failed_pc=0x0c083c1cu; return 0; }
goto P_0c083c22;
P_0c083c1e: /* original 0009, guest PC 0x0c083c1e */
if(!s->budget--) { s->failed_pc=0x0c083c1eu; return 0; }
goto P_0c083c20;
P_0c083c20: /* original 9623, guest PC 0x0c083c20 */
if(!s->budget--) { s->failed_pc=0x0c083c20u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c083c6au,2);
goto P_0c083c22;
P_0c083c22: /* original d213, guest PC 0x0c083c22 */
if(!s->budget--) { s->failed_pc=0x0c083c22u; return 0; }
r[2]=read(ram,0x0c083c70u,4);
goto P_0c083c24;
P_0c083c24: /* original 420b, guest PC 0x0c083c24 */
if(!s->budget--) { s->failed_pc=0x0c083c24u; return 0; }
target=r[2];
r[16]=code_base|0x0c083c28u;
r[4]=0x00000010u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c083c28u) { target=s->pc; goto dispatch; }
goto P_0c083c28;
P_0c083c26: /* original e410, guest PC 0x0c083c26 */
if(!s->budget--) { s->failed_pc=0x0c083c26u; return 0; }
r[4]=0x00000010u;
goto P_0c083c28;
P_0c083c28: /* original e204, guest PC 0x0c083c28 */
if(!s->budget--) { s->failed_pc=0x0c083c28u; return 0; }
r[2]=0x00000004u;
goto P_0c083c2a;
P_0c083c2a: /* original 7d01, guest PC 0x0c083c2a */
if(!s->budget--) { s->failed_pc=0x0c083c2au; return 0; }
r[13]+=0x00000001u;
goto P_0c083c2c;
P_0c083c2c: /* original 3d23, guest PC 0x0c083c2c */
if(!s->budget--) { s->failed_pc=0x0c083c2cu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[13]>=(int32_t)r[2])!=0);
goto P_0c083c2e;
P_0c083c2e: /* original 8901, guest PC 0x0c083c2e */
if(!s->budget--) { s->failed_pc=0x0c083c2eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c083c34; }
goto P_0c083c30;
P_0c083c30: /* original af4d, guest PC 0x0c083c30 */
if(!s->budget--) { s->failed_pc=0x0c083c30u; return 0; }
goto P_0c083ace;
P_0c083c32: /* original 0009, guest PC 0x0c083c32 */
if(!s->budget--) { s->failed_pc=0x0c083c32u; return 0; }
goto P_0c083c34;
P_0c083c34: /* original d311, guest PC 0x0c083c34 */
if(!s->budget--) { s->failed_pc=0x0c083c34u; return 0; }
r[3]=read(ram,0x0c083c7cu,4);
goto P_0c083c36;
P_0c083c36: /* original 9519, guest PC 0x0c083c36 */
if(!s->budget--) { s->failed_pc=0x0c083c36u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c083c6cu,2);
goto P_0c083c38;
P_0c083c38: /* original 430b, guest PC 0x0c083c38 */
if(!s->budget--) { s->failed_pc=0x0c083c38u; return 0; }
target=r[3];
r[16]=code_base|0x0c083c3cu;
r[4]=read(ram,r[15]+4,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c083c3cu) { target=s->pc; goto dispatch; }
goto P_0c083c3c;
P_0c083c3a: /* original 54f1, guest PC 0x0c083c3a */
if(!s->budget--) { s->failed_pc=0x0c083c3au; return 0; }
r[4]=read(ram,r[15]+4,4);
goto P_0c083c3c;
P_0c083c3c: /* original 54f2, guest PC 0x0c083c3c */
if(!s->budget--) { s->failed_pc=0x0c083c3cu; return 0; }
r[4]=read(ram,r[15]+8,4);
goto P_0c083c3e;
P_0c083c3e: /* original 7f0c, guest PC 0x0c083c3e */
if(!s->budget--) { s->failed_pc=0x0c083c3eu; return 0; }
r[15]+=0x0000000cu;
goto P_0c083c40;
P_0c083c40: /* original 4f26, guest PC 0x0c083c40 */
if(!s->budget--) { s->failed_pc=0x0c083c40u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c083c42;
P_0c083c42: /* original 65c3, guest PC 0x0c083c42 */
if(!s->budget--) { s->failed_pc=0x0c083c42u; return 0; }
r[5]=r[12];
goto P_0c083c44;
P_0c083c44: /* original d30e, guest PC 0x0c083c44 */
if(!s->budget--) { s->failed_pc=0x0c083c44u; return 0; }
r[3]=read(ram,0x0c083c80u,4);
goto P_0c083c46;
P_0c083c46: /* original 68f6, guest PC 0x0c083c46 */
if(!s->budget--) { s->failed_pc=0x0c083c46u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c083c48;
P_0c083c48: /* original 69f6, guest PC 0x0c083c48 */
if(!s->budget--) { s->failed_pc=0x0c083c48u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c083c4a;
P_0c083c4a: /* original 6af6, guest PC 0x0c083c4a */
if(!s->budget--) { s->failed_pc=0x0c083c4au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c083c4c;
P_0c083c4c: /* original 6bf6, guest PC 0x0c083c4c */
if(!s->budget--) { s->failed_pc=0x0c083c4cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c083c4e;
P_0c083c4e: /* original 6cf6, guest PC 0x0c083c4e */
if(!s->budget--) { s->failed_pc=0x0c083c4eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c083c50;
P_0c083c50: /* original 6df6, guest PC 0x0c083c50 */
if(!s->budget--) { s->failed_pc=0x0c083c50u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c083c52;
P_0c083c52: /* original 432b, guest PC 0x0c083c52 */
if(!s->budget--) { s->failed_pc=0x0c083c52u; return 0; }
target=r[3];
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
P_0c083c54: /* original 6ef6, guest PC 0x0c083c54 */
if(!s->budget--) { s->failed_pc=0x0c083c54u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c083c56u,s,ram);
P_0c0853fe: /* original 4f22, guest PC 0x0c0853fe */
if(!s->budget--) { s->failed_pc=0x0c0853feu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c085400;
P_0c085400: /* original d318, guest PC 0x0c085400 */
if(!s->budget--) { s->failed_pc=0x0c085400u; return 0; }
r[3]=read(ram,0x0c085464u,4);
goto P_0c085402;
P_0c085402: /* original 6212, guest PC 0x0c085402 */
if(!s->budget--) { s->failed_pc=0x0c085402u; return 0; }
tmp=read(ram,r[1],4);
r[2]=tmp;
goto P_0c085404;
P_0c085404: /* original 7ff0, guest PC 0x0c085404 */
if(!s->budget--) { s->failed_pc=0x0c085404u; return 0; }
r[15]+=0xfffffff0u;
goto P_0c085406;
P_0c085406: /* original 2238, guest PC 0x0c085406 */
if(!s->budget--) { s->failed_pc=0x0c085406u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c085408;
P_0c085408: /* original 8d02, guest PC 0x0c085408 */
if(!s->budget--) { s->failed_pc=0x0c085408u; return 0; }
cond=r[17]&1u;
r[11]=0x00000000u;
if(cond) { goto P_0c085410; }
goto P_0c08540c;
P_0c08540a: /* original eb00, guest PC 0x0c08540a */
if(!s->budget--) { s->failed_pc=0x0c08540au; return 0; }
r[11]=0x00000000u;
goto P_0c08540c;
P_0c08540c: /* original a0a5, guest PC 0x0c08540c */
if(!s->budget--) { s->failed_pc=0x0c08540cu; return 0; }
goto P_0c08555a;
P_0c08540e: /* original 0009, guest PC 0x0c08540e */
if(!s->budget--) { s->failed_pc=0x0c08540eu; return 0; }
goto P_0c085410;
P_0c085410: /* original d316, guest PC 0x0c085410 */
if(!s->budget--) { s->failed_pc=0x0c085410u; return 0; }
r[3]=read(ram,0x0c08546cu,4);
goto P_0c085412;
P_0c085412: /* original 6543, guest PC 0x0c085412 */
if(!s->budget--) { s->failed_pc=0x0c085412u; return 0; }
r[5]=r[4];
goto P_0c085414;
P_0c085414: /* original d216, guest PC 0x0c085414 */
if(!s->budget--) { s->failed_pc=0x0c085414u; return 0; }
r[2]=read(ram,0x0c085470u,4);
goto P_0c085416;
P_0c085416: /* original 6a32, guest PC 0x0c085416 */
if(!s->budget--) { s->failed_pc=0x0c085416u; return 0; }
tmp=read(ram,r[3],4);
r[10]=tmp;
goto P_0c085418;
P_0c085418: /* original 85af, guest PC 0x0c085418 */
if(!s->budget--) { s->failed_pc=0x0c085418u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[10]+30,2);
goto P_0c08541a;
P_0c08541a: /* original 6403, guest PC 0x0c08541a */
if(!s->budget--) { s->failed_pc=0x0c08541au; return 0; }
r[4]=r[0];
goto P_0c08541c;
P_0c08541c: /* original 3427, guest PC 0x0c08541c */
if(!s->budget--) { s->failed_pc=0x0c08541cu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>(int32_t)r[2])!=0);
goto P_0c08541e;
P_0c08541e: /* original 8b02, guest PC 0x0c08541e */
if(!s->budget--) { s->failed_pc=0x0c08541eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c085426; }
goto P_0c085420;
P_0c085420: /* original d80e, guest PC 0x0c085420 */
if(!s->budget--) { s->failed_pc=0x0c085420u; return 0; }
r[8]=read(ram,0x0c08545cu,4);
goto P_0c085422;
P_0c085422: /* original a001, guest PC 0x0c085422 */
if(!s->budget--) { s->failed_pc=0x0c085422u; return 0; }
goto P_0c085428;
P_0c085424: /* original 0009, guest PC 0x0c085424 */
if(!s->budget--) { s->failed_pc=0x0c085424u; return 0; }
goto P_0c085426;
P_0c085426: /* original d813, guest PC 0x0c085426 */
if(!s->budget--) { s->failed_pc=0x0c085426u; return 0; }
r[8]=read(ram,0x0c085474u,4);
goto P_0c085428;
P_0c085428: /* original dc0b, guest PC 0x0c085428 */
if(!s->budget--) { s->failed_pc=0x0c085428u; return 0; }
r[12]=read(ram,0x0c085458u,4);
goto P_0c08542a;
P_0c08542a: /* original 6e53, guest PC 0x0c08542a */
if(!s->budget--) { s->failed_pc=0x0c08542au; return 0; }
r[14]=r[5];
goto P_0c08542c;
P_0c08542c: /* original 2fb2, guest PC 0x0c08542c */
if(!s->budget--) { s->failed_pc=0x0c08542cu; return 0; }
write(ram,r[15],r[11],4);
goto P_0c08542e;
P_0c08542e: /* original d312, guest PC 0x0c08542e */
if(!s->budget--) { s->failed_pc=0x0c08542eu; return 0; }
r[3]=read(ram,0x0c085478u,4);
goto P_0c085430;
P_0c085430: /* original a08d, guest PC 0x0c085430 */
if(!s->budget--) { s->failed_pc=0x0c085430u; return 0; }
write(ram,r[15]+8,r[3],4);
goto P_0c08554e;
P_0c085432: /* original 1f32, guest PC 0x0c085432 */
if(!s->budget--) { s->failed_pc=0x0c085432u; return 0; }
write(ram,r[15]+8,r[3],4);
goto P_0c085434;
P_0c085434: /* original e008, guest PC 0x0c085434 */
if(!s->budget--) { s->failed_pc=0x0c085434u; return 0; }
r[0]=0x00000008u;
goto P_0c085436;
P_0c085436: /* original fee6, guest PC 0x0c085436 */
if(!s->budget--) { s->failed_pc=0x0c085436u; return 0; }
vf3_matrix_load(s,ram,14,r[14]+r[0]);
goto P_0c085438;
P_0c085438: /* original 85e6, guest PC 0x0c085438 */
if(!s->budget--) { s->failed_pc=0x0c085438u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+12,2);
goto P_0c08543a;
P_0c08543a: /* original 6d03, guest PC 0x0c08543a */
if(!s->budget--) { s->failed_pc=0x0c08543au; return 0; }
r[13]=r[0];
goto P_0c08543c;
P_0c08543c: /* original 2dd8, guest PC 0x0c08543c */
if(!s->budget--) { s->failed_pc=0x0c08543cu; return 0; }
r[17]=(r[17]&~1u)|(((r[13]&r[13])==0)!=0);
goto P_0c08543e;
P_0c08543e: /* original 8f1f, guest PC 0x0c08543e */
if(!s->budget--) { s->failed_pc=0x0c08543eu; return 0; }
cond=r[17]&1u;
vf3_matrix_load(s,ram,15,r[14]);
if(!cond) { goto P_0c085480; }
goto P_0c085442;
P_0c085440: /* original ffe8, guest PC 0x0c085440 */
if(!s->budget--) { s->failed_pc=0x0c085440u; return 0; }
vf3_matrix_load(s,ram,15,r[14]);
goto P_0c085442;
P_0c085442: /* original d10e, guest PC 0x0c085442 */
if(!s->budget--) { s->failed_pc=0x0c085442u; return 0; }
r[1]=read(ram,0x0c08547cu,4);
goto P_0c085444;
P_0c085444: /* original 9206, guest PC 0x0c085444 */
if(!s->budget--) { s->failed_pc=0x0c085444u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c085454u,2);
goto P_0c085446;
P_0c085446: /* original 6312, guest PC 0x0c085446 */
if(!s->budget--) { s->failed_pc=0x0c085446u; return 0; }
tmp=read(ram,r[1],4);
r[3]=tmp;
goto P_0c085448;
P_0c085448: /* original 3327, guest PC 0x0c085448 */
if(!s->budget--) { s->failed_pc=0x0c085448u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>(int32_t)r[2])!=0);
goto P_0c08544a;
P_0c08544a: /* original 8b19, guest PC 0x0c08544a */
if(!s->budget--) { s->failed_pc=0x0c08544au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c085480; }
goto P_0c08544c;
P_0c08544c: /* original 50f2, guest PC 0x0c08544c */
if(!s->budget--) { s->failed_pc=0x0c08544cu; return 0; }
r[0]=read(ram,r[15]+8,4);
goto P_0c08544e;
P_0c08544e: /* original 6001, guest PC 0x0c08544e */
if(!s->budget--) { s->failed_pc=0x0c08544eu; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[0],2);
r[0]=tmp;
goto P_0c085450;
P_0c085450: /* original a079, guest PC 0x0c085450 */
if(!s->budget--) { s->failed_pc=0x0c085450u; return 0; }
write(ram,r[14]+14,r[0],2);
goto P_0c085546;
P_0c085452: /* original 81e7, guest PC 0x0c085452 */
if(!s->budget--) { s->failed_pc=0x0c085452u; return 0; }
write(ram,r[14]+14,r[0],2);
return vf3_matrix_family(0x0c085454u,s,ram);
P_0c085480: /* original 85e8, guest PC 0x0c085480 */
if(!s->budget--) { s->failed_pc=0x0c085480u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+16,2);
goto P_0c085482;
P_0c085482: /* original f4c8, guest PC 0x0c085482 */
if(!s->budget--) { s->failed_pc=0x0c085482u; return 0; }
vf3_matrix_load(s,ram,4,r[12]);
goto P_0c085484;
P_0c085484: /* original 6903, guest PC 0x0c085484 */
if(!s->budget--) { s->failed_pc=0x0c085484u; return 0; }
r[9]=r[0];
goto P_0c085486;
P_0c085486: /* original e010, guest PC 0x0c085486 */
if(!s->budget--) { s->failed_pc=0x0c085486u; return 0; }
r[0]=0x00000010u;
goto P_0c085488;
P_0c085488: /* original fca6, guest PC 0x0c085488 */
if(!s->budget--) { s->failed_pc=0x0c085488u; return 0; }
vf3_matrix_load(s,ram,12,r[10]+r[0]);
goto P_0c08548a;
P_0c08548a: /* original e018, guest PC 0x0c08548a */
if(!s->budget--) { s->failed_pc=0x0c08548au; return 0; }
r[0]=0x00000018u;
goto P_0c08548c;
P_0c08548c: /* original fda6, guest PC 0x0c08548c */
if(!s->budget--) { s->failed_pc=0x0c08548cu; return 0; }
vf3_matrix_load(s,ram,13,r[10]+r[0]);
goto P_0c08548e;
P_0c08548e: /* original ff40, guest PC 0x0c08548e */
if(!s->budget--) { s->failed_pc=0x0c08548eu; return 0; }
fr[15]=vf3_fpu_binary(fr[15],fr[4],r[18],'+');
goto P_0c085490;
P_0c085490: /* original 85af, guest PC 0x0c085490 */
if(!s->budget--) { s->failed_pc=0x0c085490u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[10]+30,2);
goto P_0c085492;
P_0c085492: /* original 53c6, guest PC 0x0c085492 */
if(!s->budget--) { s->failed_pc=0x0c085492u; return 0; }
r[3]=read(ram,r[12]+24,4);
goto P_0c085494;
P_0c085494: /* original 6503, guest PC 0x0c085494 */
if(!s->budget--) { s->failed_pc=0x0c085494u; return 0; }
r[5]=r[0];
goto P_0c085496;
P_0c085496: /* original e004, guest PC 0x0c085496 */
if(!s->budget--) { s->failed_pc=0x0c085496u; return 0; }
r[0]=0x00000004u;
goto P_0c085498;
P_0c085498: /* original f5c6, guest PC 0x0c085498 */
if(!s->budget--) { s->failed_pc=0x0c085498u; return 0; }
vf3_matrix_load(s,ram,5,r[12]+r[0]);
goto P_0c08549a;
P_0c08549a: /* original e008, guest PC 0x0c08549a */
if(!s->budget--) { s->failed_pc=0x0c08549au; return 0; }
r[0]=0x00000008u;
goto P_0c08549c;
P_0c08549c: /* original f9c6, guest PC 0x0c08549c */
if(!s->budget--) { s->failed_pc=0x0c08549cu; return 0; }
vf3_matrix_load(s,ram,9,r[12]+r[0]);
goto P_0c08549e;
P_0c08549e: /* original e00c, guest PC 0x0c08549e */
if(!s->budget--) { s->failed_pc=0x0c08549eu; return 0; }
r[0]=0x0000000cu;
goto P_0c0854a0;
P_0c0854a0: /* original f7c6, guest PC 0x0c0854a0 */
if(!s->budget--) { s->failed_pc=0x0c0854a0u; return 0; }
vf3_matrix_load(s,ram,7,r[12]+r[0]);
goto P_0c0854a2;
P_0c0854a2: /* original e010, guest PC 0x0c0854a2 */
if(!s->budget--) { s->failed_pc=0x0c0854a2u; return 0; }
r[0]=0x00000010u;
goto P_0c0854a4;
P_0c0854a4: /* original f8c6, guest PC 0x0c0854a4 */
if(!s->budget--) { s->failed_pc=0x0c0854a4u; return 0; }
vf3_matrix_load(s,ram,8,r[12]+r[0]);
goto P_0c0854a6;
P_0c0854a6: /* original ff95, guest PC 0x0c0854a6 */
if(!s->budget--) { s->failed_pc=0x0c0854a6u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[15])>as_float(fr[9]))!=0);
goto P_0c0854a8;
P_0c0854a8: /* original e014, guest PC 0x0c0854a8 */
if(!s->budget--) { s->failed_pc=0x0c0854a8u; return 0; }
r[0]=0x00000014u;
goto P_0c0854aa;
P_0c0854aa: /* original f6c6, guest PC 0x0c0854aa */
if(!s->budget--) { s->failed_pc=0x0c0854aau; return 0; }
vf3_matrix_load(s,ram,6,r[12]+r[0]);
goto P_0c0854ac;
P_0c0854ac: /* original 1f31, guest PC 0x0c0854ac */
if(!s->budget--) { s->failed_pc=0x0c0854acu; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c0854ae;
P_0c0854ae: /* original 54c7, guest PC 0x0c0854ae */
if(!s->budget--) { s->failed_pc=0x0c0854aeu; return 0; }
r[4]=read(ram,r[12]+28,4);
goto P_0c0854b0;
P_0c0854b0: /* original 7c20, guest PC 0x0c0854b0 */
if(!s->budget--) { s->failed_pc=0x0c0854b0u; return 0; }
r[12]+=0x00000020u;
goto P_0c0854b2;
P_0c0854b2: /* original 1fd3, guest PC 0x0c0854b2 */
if(!s->budget--) { s->failed_pc=0x0c0854b2u; return 0; }
write(ram,r[15]+12,r[13],4);
goto P_0c0854b4;
P_0c0854b4: /* original 345c, guest PC 0x0c0854b4 */
if(!s->budget--) { s->failed_pc=0x0c0854b4u; return 0; }
r[4]+=r[5];
goto P_0c0854b6;
P_0c0854b6: /* original 955e, guest PC 0x0c0854b6 */
if(!s->budget--) { s->failed_pc=0x0c0854b6u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c085576u,2);
goto P_0c0854b8;
P_0c0854b8: /* original 345c, guest PC 0x0c0854b8 */
if(!s->budget--) { s->failed_pc=0x0c0854b8u; return 0; }
r[4]+=r[5];
goto P_0c0854ba;
P_0c0854ba: /* original 6043, guest PC 0x0c0854ba */
if(!s->budget--) { s->failed_pc=0x0c0854bau; return 0; }
r[0]=r[4];
goto P_0c0854bc;
P_0c0854bc: /* original 81e9, guest PC 0x0c0854bc */
if(!s->budget--) { s->failed_pc=0x0c0854bcu; return 0; }
write(ram,r[14]+18,r[0],2);
goto P_0c0854be;
P_0c0854be: /* original 8d04, guest PC 0x0c0854be */
if(!s->budget--) { s->failed_pc=0x0c0854beu; return 0; }
cond=r[17]&1u;
fr[14]=vf3_fpu_binary(fr[14],fr[5],r[18],'+');
if(cond) { goto P_0c0854ca; }
goto P_0c0854c2;
P_0c0854c0: /* original fe50, guest PC 0x0c0854c0 */
if(!s->budget--) { s->failed_pc=0x0c0854c0u; return 0; }
fr[14]=vf3_fpu_binary(fr[14],fr[5],r[18],'+');
goto P_0c0854c2;
P_0c0854c2: /* original 2dd8, guest PC 0x0c0854c2 */
if(!s->budget--) { s->failed_pc=0x0c0854c2u; return 0; }
r[17]=(r[17]&~1u)|(((r[13]&r[13])==0)!=0);
goto P_0c0854c4;
P_0c0854c4: /* original 8f01, guest PC 0x0c0854c4 */
if(!s->budget--) { s->failed_pc=0x0c0854c4u; return 0; }
cond=r[17]&1u;
fr[15]=vf3_fpu_binary(fr[15],fr[4],r[18],'-');
if(!cond) { goto P_0c0854ca; }
goto P_0c0854c8;
P_0c0854c6: /* original ff41, guest PC 0x0c0854c6 */
if(!s->budget--) { s->failed_pc=0x0c0854c6u; return 0; }
fr[15]=vf3_fpu_binary(fr[15],fr[4],r[18],'-');
goto P_0c0854c8;
P_0c0854c8: /* original ff8c, guest PC 0x0c0854c8 */
if(!s->budget--) { s->failed_pc=0x0c0854c8u; return 0; }
vf3_matrix_move(s,15,8);
goto P_0c0854ca;
P_0c0854ca: /* original fe75, guest PC 0x0c0854ca */
if(!s->budget--) { s->failed_pc=0x0c0854cau; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[14])>as_float(fr[7]))!=0);
goto P_0c0854cc;
P_0c0854cc: /* original 8903, guest PC 0x0c0854cc */
if(!s->budget--) { s->failed_pc=0x0c0854ccu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0854d6; }
goto P_0c0854ce;
P_0c0854ce: /* original 2dd8, guest PC 0x0c0854ce */
if(!s->budget--) { s->failed_pc=0x0c0854ceu; return 0; }
r[17]=(r[17]&~1u)|(((r[13]&r[13])==0)!=0);
goto P_0c0854d0;
P_0c0854d0: /* original 8f01, guest PC 0x0c0854d0 */
if(!s->budget--) { s->failed_pc=0x0c0854d0u; return 0; }
cond=r[17]&1u;
fr[14]=vf3_fpu_binary(fr[14],fr[5],r[18],'-');
if(!cond) { goto P_0c0854d6; }
goto P_0c0854d4;
P_0c0854d2: /* original fe51, guest PC 0x0c0854d2 */
if(!s->budget--) { s->failed_pc=0x0c0854d2u; return 0; }
fr[14]=vf3_fpu_binary(fr[14],fr[5],r[18],'-');
goto P_0c0854d4;
P_0c0854d4: /* original fe6c, guest PC 0x0c0854d4 */
if(!s->budget--) { s->failed_pc=0x0c0854d4u; return 0; }
vf3_matrix_move(s,14,6);
goto P_0c0854d6;
P_0c0854d6: /* original d328, guest PC 0x0c0854d6 */
if(!s->budget--) { s->failed_pc=0x0c0854d6u; return 0; }
r[3]=read(ram,0x0c085578u,4);
goto P_0c0854d8;
P_0c0854d8: /* original f5ec, guest PC 0x0c0854d8 */
if(!s->budget--) { s->failed_pc=0x0c0854d8u; return 0; }
vf3_matrix_move(s,5,14);
goto P_0c0854da;
P_0c0854da: /* original 430b, guest PC 0x0c0854da */
if(!s->budget--) { s->failed_pc=0x0c0854dau; return 0; }
target=r[3];
r[16]=code_base|0x0c0854deu;
vf3_matrix_move(s,4,15);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0854deu) { target=s->pc; goto dispatch; }
goto P_0c0854de;
P_0c0854dc: /* original f4fc, guest PC 0x0c0854dc */
if(!s->budget--) { s->failed_pc=0x0c0854dcu; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c0854de;
P_0c0854de: /* original 7901, guest PC 0x0c0854de */
if(!s->budget--) { s->failed_pc=0x0c0854deu; return 0; }
r[9]+=0x00000001u;
goto P_0c0854e0;
P_0c0854e0: /* original 6293, guest PC 0x0c0854e0 */
if(!s->budget--) { s->failed_pc=0x0c0854e0u; return 0; }
r[2]=r[9];
goto P_0c0854e2;
P_0c0854e2: /* original e401, guest PC 0x0c0854e2 */
if(!s->budget--) { s->failed_pc=0x0c0854e2u; return 0; }
r[4]=0x00000001u;
goto P_0c0854e4;
P_0c0854e4: /* original 2248, guest PC 0x0c0854e4 */
if(!s->budget--) { s->failed_pc=0x0c0854e4u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[4])==0)!=0);
goto P_0c0854e6;
P_0c0854e6: /* original 8d01, guest PC 0x0c0854e6 */
if(!s->budget--) { s->failed_pc=0x0c0854e6u; return 0; }
cond=r[17]&1u;
vf3_matrix_move(s,5,0);
if(cond) { goto P_0c0854ec; }
goto P_0c0854ea;
P_0c0854e8: /* original f50c, guest PC 0x0c0854e8 */
if(!s->budget--) { s->failed_pc=0x0c0854e8u; return 0; }
vf3_matrix_move(s,5,0);
goto P_0c0854ea;
P_0c0854ea: /* original 7d01, guest PC 0x0c0854ea */
if(!s->budget--) { s->failed_pc=0x0c0854eau; return 0; }
r[13]+=0x00000001u;
goto P_0c0854ec;
P_0c0854ec: /* original fde1, guest PC 0x0c0854ec */
if(!s->budget--) { s->failed_pc=0x0c0854ecu; return 0; }
fr[13]=vf3_fpu_binary(fr[13],fr[14],r[18],'-');
goto P_0c0854ee;
P_0c0854ee: /* original 649d, guest PC 0x0c0854ee */
if(!s->budget--) { s->failed_pc=0x0c0854eeu; return 0; }
r[4]=r[9]&65535u;
goto P_0c0854f0;
P_0c0854f0: /* original fcf1, guest PC 0x0c0854f0 */
if(!s->budget--) { s->failed_pc=0x0c0854f0u; return 0; }
fr[12]=vf3_fpu_binary(fr[12],fr[15],r[18],'-');
goto P_0c0854f2;
P_0c0854f2: /* original 52f1, guest PC 0x0c0854f2 */
if(!s->budget--) { s->failed_pc=0x0c0854f2u; return 0; }
r[2]=read(ram,r[15]+4,4);
goto P_0c0854f4;
P_0c0854f4: /* original 6043, guest PC 0x0c0854f4 */
if(!s->budget--) { s->failed_pc=0x0c0854f4u; return 0; }
r[0]=r[4];
goto P_0c0854f6;
P_0c0854f6: /* original 81e8, guest PC 0x0c0854f6 */
if(!s->budget--) { s->failed_pc=0x0c0854f6u; return 0; }
write(ram,r[14]+16,r[0],2);
goto P_0c0854f8;
P_0c0854f8: /* original 2d29, guest PC 0x0c0854f8 */
if(!s->budget--) { s->failed_pc=0x0c0854f8u; return 0; }
r[13]&=r[2];
goto P_0c0854fa;
P_0c0854fa: /* original 60d3, guest PC 0x0c0854fa */
if(!s->budget--) { s->failed_pc=0x0c0854fau; return 0; }
r[0]=r[13];
goto P_0c0854fc;
P_0c0854fc: /* original 81e6, guest PC 0x0c0854fc */
if(!s->budget--) { s->failed_pc=0x0c0854fcu; return 0; }
write(ram,r[14]+12,r[0],2);
goto P_0c0854fe;
P_0c0854fe: /* original f3dc, guest PC 0x0c0854fe */
if(!s->budget--) { s->failed_pc=0x0c0854feu; return 0; }
vf3_matrix_move(s,3,13);
goto P_0c085500;
P_0c085500: /* original f3d2, guest PC 0x0c085500 */
if(!s->budget--) { s->failed_pc=0x0c085500u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[13],r[18],'*');
goto P_0c085502;
P_0c085502: /* original f0cc, guest PC 0x0c085502 */
if(!s->budget--) { s->failed_pc=0x0c085502u; return 0; }
vf3_matrix_move(s,0,12);
goto P_0c085504;
P_0c085504: /* original c71d, guest PC 0x0c085504 */
if(!s->budget--) { s->failed_pc=0x0c085504u; return 0; }
r[0]=0x0c08557cu;
goto P_0c085506;
P_0c085506: /* original 53f3, guest PC 0x0c085506 */
if(!s->budget--) { s->failed_pc=0x0c085506u; return 0; }
r[3]=read(ram,r[15]+12,4);
goto P_0c085508;
P_0c085508: /* original f608, guest PC 0x0c085508 */
if(!s->budget--) { s->failed_pc=0x0c085508u; return 0; }
vf3_matrix_load(s,ram,6,r[0]);
goto P_0c08550a;
P_0c08550a: /* original f3ce, guest PC 0x0c08550a */
if(!s->budget--) { s->failed_pc=0x0c08550au; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[12],fr[3],r[18]);
goto P_0c08550c;
P_0c08550c: /* original 2338, guest PC 0x0c08550c */
if(!s->budget--) { s->failed_pc=0x0c08550cu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c08550e;
P_0c08550e: /* original f43c, guest PC 0x0c08550e */
if(!s->budget--) { s->failed_pc=0x0c08550eu; return 0; }
vf3_matrix_move(s,4,3);
goto P_0c085510;
P_0c085510: /* original 8f06, guest PC 0x0c085510 */
if(!s->budget--) { s->failed_pc=0x0c085510u; return 0; }
cond=r[17]&1u;
fr[4]&=0x7fffffffu;
if(!cond) { goto P_0c085520; }
goto P_0c085514;
P_0c085512: /* original f45d, guest PC 0x0c085512 */
if(!s->budget--) { s->failed_pc=0x0c085512u; return 0; }
fr[4]&=0x7fffffffu;
goto P_0c085514;
P_0c085514: /* original f465, guest PC 0x0c085514 */
if(!s->budget--) { s->failed_pc=0x0c085514u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[4])>as_float(fr[6]))!=0);
goto P_0c085516;
P_0c085516: /* original 6482, guest PC 0x0c085516 */
if(!s->budget--) { s->failed_pc=0x0c085516u; return 0; }
tmp=read(ram,r[8],4);
r[4]=tmp;
goto P_0c085518;
P_0c085518: /* original 8d0a, guest PC 0x0c085518 */
if(!s->budget--) { s->failed_pc=0x0c085518u; return 0; }
cond=r[17]&1u;
write(ram,r[14]+20,r[4],4);
if(cond) { goto P_0c085530; }
goto P_0c08551c;
P_0c08551a: /* original 1e45, guest PC 0x0c08551a */
if(!s->budget--) { s->failed_pc=0x0c08551au; return 0; }
write(ram,r[14]+20,r[4],4);
goto P_0c08551c;
P_0c08551c: /* original a006, guest PC 0x0c08551c */
if(!s->budget--) { s->failed_pc=0x0c08551cu; return 0; }
r[13]=r[11];
goto P_0c08552c;
P_0c08551e: /* original 6db3, guest PC 0x0c08551e */
if(!s->budget--) { s->failed_pc=0x0c08551eu; return 0; }
r[13]=r[11];
goto P_0c085520;
P_0c085520: /* original e43e, guest PC 0x0c085520 */
if(!s->budget--) { s->failed_pc=0x0c085520u; return 0; }
r[4]=0x0000003eu;
goto P_0c085522;
P_0c085522: /* original 3d43, guest PC 0x0c085522 */
if(!s->budget--) { s->failed_pc=0x0c085522u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[13]>=(int32_t)r[4])!=0);
goto P_0c085524;
P_0c085524: /* original 8b04, guest PC 0x0c085524 */
if(!s->budget--) { s->failed_pc=0x0c085524u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c085530; }
goto P_0c085526;
P_0c085526: /* original f645, guest PC 0x0c085526 */
if(!s->budget--) { s->failed_pc=0x0c085526u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[6])>as_float(fr[4]))!=0);
goto P_0c085528;
P_0c085528: /* original 8d02, guest PC 0x0c085528 */
if(!s->budget--) { s->failed_pc=0x0c085528u; return 0; }
cond=r[17]&1u;
r[13]=r[11];
if(cond) { goto P_0c085530; }
goto P_0c08552c;
P_0c08552a: /* original 6db3, guest PC 0x0c08552a */
if(!s->budget--) { s->failed_pc=0x0c08552au; return 0; }
r[13]=r[11];
goto P_0c08552c;
P_0c08552c: /* original 60b3, guest PC 0x0c08552c */
if(!s->budget--) { s->failed_pc=0x0c08552cu; return 0; }
r[0]=r[11];
goto P_0c08552e;
P_0c08552e: /* original 81e6, guest PC 0x0c08552e */
if(!s->budget--) { s->failed_pc=0x0c08552eu; return 0; }
write(ram,r[14]+12,r[0],2);
goto P_0c085530;
P_0c085530: /* original 60d3, guest PC 0x0c085530 */
if(!s->budget--) { s->failed_pc=0x0c085530u; return 0; }
r[0]=r[13];
goto P_0c085532;
P_0c085532: /* original 54e5, guest PC 0x0c085532 */
if(!s->budget--) { s->failed_pc=0x0c085532u; return 0; }
r[4]=read(ram,r[14]+20,4);
goto P_0c085534;
P_0c085534: /* original 4000, guest PC 0x0c085534 */
if(!s->budget--) { s->failed_pc=0x0c085534u; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c085536;
P_0c085536: /* original 004d, guest PC 0x0c085536 */
if(!s->budget--) { s->failed_pc=0x0c085536u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c085538;
P_0c085538: /* original 7804, guest PC 0x0c085538 */
if(!s->budget--) { s->failed_pc=0x0c085538u; return 0; }
r[8]+=0x00000004u;
goto P_0c08553a;
P_0c08553a: /* original 81e7, guest PC 0x0c08553a */
if(!s->budget--) { s->failed_pc=0x0c08553au; return 0; }
write(ram,r[14]+14,r[0],2);
goto P_0c08553c;
P_0c08553c: /* original e004, guest PC 0x0c08553c */
if(!s->budget--) { s->failed_pc=0x0c08553cu; return 0; }
r[0]=0x00000004u;
goto P_0c08553e;
P_0c08553e: /* original fefa, guest PC 0x0c08553e */
if(!s->budget--) { s->failed_pc=0x0c08553eu; return 0; }
vf3_matrix_store(s,ram,15,r[14]);
goto P_0c085540;
P_0c085540: /* original fe57, guest PC 0x0c085540 */
if(!s->budget--) { s->failed_pc=0x0c085540u; return 0; }
vf3_matrix_store(s,ram,5,r[14]+r[0]);
goto P_0c085542;
P_0c085542: /* original e008, guest PC 0x0c085542 */
if(!s->budget--) { s->failed_pc=0x0c085542u; return 0; }
r[0]=0x00000008u;
goto P_0c085544;
P_0c085544: /* original fee7, guest PC 0x0c085544 */
if(!s->budget--) { s->failed_pc=0x0c085544u; return 0; }
vf3_matrix_store(s,ram,14,r[14]+r[0]);
goto P_0c085546;
P_0c085546: /* original 63f2, guest PC 0x0c085546 */
if(!s->budget--) { s->failed_pc=0x0c085546u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c085548;
P_0c085548: /* original 7e18, guest PC 0x0c085548 */
if(!s->budget--) { s->failed_pc=0x0c085548u; return 0; }
r[14]+=0x00000018u;
goto P_0c08554a;
P_0c08554a: /* original 7301, guest PC 0x0c08554a */
if(!s->budget--) { s->failed_pc=0x0c08554au; return 0; }
r[3]+=0x00000001u;
goto P_0c08554c;
P_0c08554c: /* original 2f32, guest PC 0x0c08554c */
if(!s->budget--) { s->failed_pc=0x0c08554cu; return 0; }
write(ram,r[15],r[3],4);
goto P_0c08554e;
P_0c08554e: /* original 63f2, guest PC 0x0c08554e */
if(!s->budget--) { s->failed_pc=0x0c08554eu; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c085550;
P_0c085550: /* original e40d, guest PC 0x0c085550 */
if(!s->budget--) { s->failed_pc=0x0c085550u; return 0; }
r[4]=0x0000000du;
goto P_0c085552;
P_0c085552: /* original 3343, guest PC 0x0c085552 */
if(!s->budget--) { s->failed_pc=0x0c085552u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>=(int32_t)r[4])!=0);
goto P_0c085554;
P_0c085554: /* original 8901, guest PC 0x0c085554 */
if(!s->budget--) { s->failed_pc=0x0c085554u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c08555a; }
goto P_0c085556;
P_0c085556: /* original af6d, guest PC 0x0c085556 */
if(!s->budget--) { s->failed_pc=0x0c085556u; return 0; }
goto P_0c085434;
P_0c085558: /* original 0009, guest PC 0x0c085558 */
if(!s->budget--) { s->failed_pc=0x0c085558u; return 0; }
goto P_0c08555a;
P_0c08555a: /* original 7f10, guest PC 0x0c08555a */
if(!s->budget--) { s->failed_pc=0x0c08555au; return 0; }
r[15]+=0x00000010u;
goto P_0c08555c;
P_0c08555c: /* original 4f26, guest PC 0x0c08555c */
if(!s->budget--) { s->failed_pc=0x0c08555cu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c08555e;
P_0c08555e: /* original fcf9, guest PC 0x0c08555e */
if(!s->budget--) { s->failed_pc=0x0c08555eu; return 0; }
vf3_matrix_load(s,ram,12,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c085560;
P_0c085560: /* original fdf9, guest PC 0x0c085560 */
if(!s->budget--) { s->failed_pc=0x0c085560u; return 0; }
vf3_matrix_load(s,ram,13,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c085562;
P_0c085562: /* original fef9, guest PC 0x0c085562 */
if(!s->budget--) { s->failed_pc=0x0c085562u; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c085564;
P_0c085564: /* original fff9, guest PC 0x0c085564 */
if(!s->budget--) { s->failed_pc=0x0c085564u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c085566;
P_0c085566: /* original 68f6, guest PC 0x0c085566 */
if(!s->budget--) { s->failed_pc=0x0c085566u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c085568;
P_0c085568: /* original 69f6, guest PC 0x0c085568 */
if(!s->budget--) { s->failed_pc=0x0c085568u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c08556a;
P_0c08556a: /* original 6af6, guest PC 0x0c08556a */
if(!s->budget--) { s->failed_pc=0x0c08556au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c08556c;
P_0c08556c: /* original 6bf6, guest PC 0x0c08556c */
if(!s->budget--) { s->failed_pc=0x0c08556cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c08556e;
P_0c08556e: /* original 6cf6, guest PC 0x0c08556e */
if(!s->budget--) { s->failed_pc=0x0c08556eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c085570;
P_0c085570: /* original 6df6, guest PC 0x0c085570 */
if(!s->budget--) { s->failed_pc=0x0c085570u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c085572;
P_0c085572: /* original 000b, guest PC 0x0c085572 */
if(!s->budget--) { s->failed_pc=0x0c085572u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c085574: /* original 6ef6, guest PC 0x0c085574 */
if(!s->budget--) { s->failed_pc=0x0c085574u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c085576u,s,ram);
P_0c086b3a: /* original 4f22, guest PC 0x0c086b3a */
if(!s->budget--) { s->failed_pc=0x0c086b3au; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c086b3c;
P_0c086b3c: /* original 6242, guest PC 0x0c086b3c */
if(!s->budget--) { s->failed_pc=0x0c086b3cu; return 0; }
tmp=read(ram,r[4],4);
r[2]=tmp;
goto P_0c086b3e;
P_0c086b3e: /* original d312, guest PC 0x0c086b3e */
if(!s->budget--) { s->failed_pc=0x0c086b3eu; return 0; }
r[3]=read(ram,0x0c086b88u,4);
goto P_0c086b40;
P_0c086b40: /* original 7ff8, guest PC 0x0c086b40 */
if(!s->budget--) { s->failed_pc=0x0c086b40u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c086b42;
P_0c086b42: /* original 2238, guest PC 0x0c086b42 */
if(!s->budget--) { s->failed_pc=0x0c086b42u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c086b44;
P_0c086b44: /* original 8901, guest PC 0x0c086b44 */
if(!s->budget--) { s->failed_pc=0x0c086b44u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c086b4a; }
goto P_0c086b46;
P_0c086b46: /* original a0b7, guest PC 0x0c086b46 */
if(!s->budget--) { s->failed_pc=0x0c086b46u; return 0; }
goto P_0c086cb8;
P_0c086b48: /* original 0009, guest PC 0x0c086b48 */
if(!s->budget--) { s->failed_pc=0x0c086b48u; return 0; }
goto P_0c086b4a;
P_0c086b4a: /* original 5141, guest PC 0x0c086b4a */
if(!s->budget--) { s->failed_pc=0x0c086b4au; return 0; }
r[1]=read(ram,r[4]+4,4);
goto P_0c086b4c;
P_0c086b4c: /* original d30f, guest PC 0x0c086b4c */
if(!s->budget--) { s->failed_pc=0x0c086b4cu; return 0; }
r[3]=read(ram,0x0c086b8cu,4);
goto P_0c086b4e;
P_0c086b4e: /* original 2138, guest PC 0x0c086b4e */
if(!s->budget--) { s->failed_pc=0x0c086b4eu; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[3])==0)!=0);
goto P_0c086b50;
P_0c086b50: /* original 8901, guest PC 0x0c086b50 */
if(!s->budget--) { s->failed_pc=0x0c086b50u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c086b56; }
goto P_0c086b52;
P_0c086b52: /* original a0b1, guest PC 0x0c086b52 */
if(!s->budget--) { s->failed_pc=0x0c086b52u; return 0; }
goto P_0c086cb8;
P_0c086b54: /* original 0009, guest PC 0x0c086b54 */
if(!s->budget--) { s->failed_pc=0x0c086b54u; return 0; }
goto P_0c086b56;
P_0c086b56: /* original d00e, guest PC 0x0c086b56 */
if(!s->budget--) { s->failed_pc=0x0c086b56u; return 0; }
r[0]=read(ram,0x0c086b90u,4);
goto P_0c086b58;
P_0c086b58: /* original ec01, guest PC 0x0c086b58 */
if(!s->budget--) { s->failed_pc=0x0c086b58u; return 0; }
r[12]=0x00000001u;
goto P_0c086b5a;
P_0c086b5a: /* original eb0f, guest PC 0x0c086b5a */
if(!s->budget--) { s->failed_pc=0x0c086b5au; return 0; }
r[11]=0x0000000fu;
goto P_0c086b5c;
P_0c086b5c: /* original 6802, guest PC 0x0c086b5c */
if(!s->budget--) { s->failed_pc=0x0c086b5cu; return 0; }
tmp=read(ram,r[0],4);
r[8]=tmp;
goto P_0c086b5e;
P_0c086b5e: /* original e00c, guest PC 0x0c086b5e */
if(!s->budget--) { s->failed_pc=0x0c086b5eu; return 0; }
r[0]=0x0000000cu;
goto P_0c086b60;
P_0c086b60: /* original fdd6, guest PC 0x0c086b60 */
if(!s->budget--) { s->failed_pc=0x0c086b60u; return 0; }
vf3_matrix_load(s,ram,13,r[13]+r[0]);
goto P_0c086b62;
P_0c086b62: /* original e010, guest PC 0x0c086b62 */
if(!s->budget--) { s->failed_pc=0x0c086b62u; return 0; }
r[0]=0x00000010u;
goto P_0c086b64;
P_0c086b64: /* original f3d6, guest PC 0x0c086b64 */
if(!s->budget--) { s->failed_pc=0x0c086b64u; return 0; }
vf3_matrix_load(s,ram,3,r[13]+r[0]);
goto P_0c086b66;
P_0c086b66: /* original e014, guest PC 0x0c086b66 */
if(!s->budget--) { s->failed_pc=0x0c086b66u; return 0; }
r[0]=0x00000014u;
goto P_0c086b68;
P_0c086b68: /* original ff3a, guest PC 0x0c086b68 */
if(!s->budget--) { s->failed_pc=0x0c086b68u; return 0; }
vf3_matrix_store(s,ram,3,r[15]);
goto P_0c086b6a;
P_0c086b6a: /* original fcd6, guest PC 0x0c086b6a */
if(!s->budget--) { s->failed_pc=0x0c086b6au; return 0; }
vf3_matrix_load(s,ram,12,r[13]+r[0]);
goto P_0c086b6c;
P_0c086b6c: /* original e03c, guest PC 0x0c086b6c */
if(!s->budget--) { s->failed_pc=0x0c086b6cu; return 0; }
r[0]=0x0000003cu;
goto P_0c086b6e;
P_0c086b6e: /* original fed6, guest PC 0x0c086b6e */
if(!s->budget--) { s->failed_pc=0x0c086b6eu; return 0; }
vf3_matrix_load(s,ram,14,r[13]+r[0]);
goto P_0c086b70;
P_0c086b70: /* original e040, guest PC 0x0c086b70 */
if(!s->budget--) { s->failed_pc=0x0c086b70u; return 0; }
r[0]=0x00000040u;
goto P_0c086b72;
P_0c086b72: /* original f3d6, guest PC 0x0c086b72 */
if(!s->budget--) { s->failed_pc=0x0c086b72u; return 0; }
vf3_matrix_load(s,ram,3,r[13]+r[0]);
goto P_0c086b74;
P_0c086b74: /* original e004, guest PC 0x0c086b74 */
if(!s->budget--) { s->failed_pc=0x0c086b74u; return 0; }
r[0]=0x00000004u;
goto P_0c086b76;
P_0c086b76: /* original ff37, guest PC 0x0c086b76 */
if(!s->budget--) { s->failed_pc=0x0c086b76u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c086b78;
P_0c086b78: /* original c706, guest PC 0x0c086b78 */
if(!s->budget--) { s->failed_pc=0x0c086b78u; return 0; }
r[0]=0x0c086b94u;
goto P_0c086b7a;
P_0c086b7a: /* original da07, guest PC 0x0c086b7a */
if(!s->budget--) { s->failed_pc=0x0c086b7au; return 0; }
r[10]=read(ram,0x0c086b98u,4);
goto P_0c086b7c;
P_0c086b7c: /* original ff08, guest PC 0x0c086b7c */
if(!s->budget--) { s->failed_pc=0x0c086b7cu; return 0; }
vf3_matrix_load(s,ram,15,r[0]);
goto P_0c086b7e;
P_0c086b7e: /* original a072, guest PC 0x0c086b7e */
if(!s->budget--) { s->failed_pc=0x0c086b7eu; return 0; }
r[9]=0x00000002u;
goto P_0c086c66;
P_0c086b80: /* original e902, guest PC 0x0c086b80 */
if(!s->budget--) { s->failed_pc=0x0c086b80u; return 0; }
r[9]=0x00000002u;
return vf3_matrix_family(0x0c086b82u,s,ram);
P_0c086b9c: /* original d24f, guest PC 0x0c086b9c */
if(!s->budget--) { s->failed_pc=0x0c086b9cu; return 0; }
r[2]=read(ram,0x0c086cdcu,4);
goto P_0c086b9e;
P_0c086b9e: /* original 420b, guest PC 0x0c086b9e */
if(!s->budget--) { s->failed_pc=0x0c086b9eu; return 0; }
target=r[2];
r[16]=code_base|0x0c086ba2u;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c086ba2u) { target=s->pc; goto dispatch; }
goto P_0c086ba2;
P_0c086ba0: /* original 64d3, guest PC 0x0c086ba0 */
if(!s->budget--) { s->failed_pc=0x0c086ba0u; return 0; }
r[4]=r[13];
goto P_0c086ba2;
P_0c086ba2: /* original 88ff, guest PC 0x0c086ba2 */
if(!s->budget--) { s->failed_pc=0x0c086ba2u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c086ba4;
P_0c086ba4: /* original 8f02, guest PC 0x0c086ba4 */
if(!s->budget--) { s->failed_pc=0x0c086ba4u; return 0; }
cond=r[17]&1u;
r[4]=r[0];
if(!cond) { goto P_0c086bac; }
goto P_0c086ba8;
P_0c086ba6: /* original 6403, guest PC 0x0c086ba6 */
if(!s->budget--) { s->failed_pc=0x0c086ba6u; return 0; }
r[4]=r[0];
goto P_0c086ba8;
P_0c086ba8: /* original a086, guest PC 0x0c086ba8 */
if(!s->budget--) { s->failed_pc=0x0c086ba8u; return 0; }
goto P_0c086cb8;
P_0c086baa: /* original 0009, guest PC 0x0c086baa */
if(!s->budget--) { s->failed_pc=0x0c086baau; return 0; }
goto P_0c086bac;
P_0c086bac: /* original e00c, guest PC 0x0c086bac */
if(!s->budget--) { s->failed_pc=0x0c086bacu; return 0; }
r[0]=0x0000000cu;
goto P_0c086bae;
P_0c086bae: /* original 6e43, guest PC 0x0c086bae */
if(!s->budget--) { s->failed_pc=0x0c086baeu; return 0; }
r[14]=r[4];
goto P_0c086bb0;
P_0c086bb0: /* original fed7, guest PC 0x0c086bb0 */
if(!s->budget--) { s->failed_pc=0x0c086bb0u; return 0; }
vf3_matrix_store(s,ram,13,r[14]+r[0]);
goto P_0c086bb2;
P_0c086bb2: /* original e010, guest PC 0x0c086bb2 */
if(!s->budget--) { s->failed_pc=0x0c086bb2u; return 0; }
r[0]=0x00000010u;
goto P_0c086bb4;
P_0c086bb4: /* original f3f8, guest PC 0x0c086bb4 */
if(!s->budget--) { s->failed_pc=0x0c086bb4u; return 0; }
vf3_matrix_load(s,ram,3,r[15]);
goto P_0c086bb6;
P_0c086bb6: /* original fe37, guest PC 0x0c086bb6 */
if(!s->budget--) { s->failed_pc=0x0c086bb6u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c086bb8;
P_0c086bb8: /* original e014, guest PC 0x0c086bb8 */
if(!s->budget--) { s->failed_pc=0x0c086bb8u; return 0; }
r[0]=0x00000014u;
goto P_0c086bba;
P_0c086bba: /* original 4a0b, guest PC 0x0c086bba */
if(!s->budget--) { s->failed_pc=0x0c086bbau; return 0; }
target=r[10];
r[16]=code_base|0x0c086bbeu;
vf3_matrix_store(s,ram,12,r[14]+r[0]);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c086bbeu) { target=s->pc; goto dispatch; }
goto P_0c086bbe;
P_0c086bbc: /* original fec7, guest PC 0x0c086bbc */
if(!s->budget--) { s->failed_pc=0x0c086bbcu; return 0; }
vf3_matrix_store(s,ram,12,r[14]+r[0]);
goto P_0c086bbe;
P_0c086bbe: /* original 6503, guest PC 0x0c086bbe */
if(!s->budget--) { s->failed_pc=0x0c086bbeu; return 0; }
r[5]=r[0];
goto P_0c086bc0;
P_0c086bc0: /* original 25b9, guest PC 0x0c086bc0 */
if(!s->budget--) { s->failed_pc=0x0c086bc0u; return 0; }
r[5]&=r[11];
goto P_0c086bc2;
P_0c086bc2: /* original 455a, guest PC 0x0c086bc2 */
if(!s->budget--) { s->failed_pc=0x0c086bc2u; return 0; }
r[53]=r[5];
goto P_0c086bc4;
P_0c086bc4: /* original e3fb, guest PC 0x0c086bc4 */
if(!s->budget--) { s->failed_pc=0x0c086bc4u; return 0; }
r[3]=0xfffffffbu;
goto P_0c086bc6;
P_0c086bc6: /* original 6403, guest PC 0x0c086bc6 */
if(!s->budget--) { s->failed_pc=0x0c086bc6u; return 0; }
r[4]=r[0];
goto P_0c086bc8;
P_0c086bc8: /* original e61f, guest PC 0x0c086bc8 */
if(!s->budget--) { s->failed_pc=0x0c086bc8u; return 0; }
r[6]=0x0000001fu;
goto P_0c086bca;
P_0c086bca: /* original 403c, guest PC 0x0c086bca */
if(!s->budget--) { s->failed_pc=0x0c086bcau; return 0; }
r[0]=(r[3]&0x80000000u)?((r[3]&31u)?(uint32_t)((int32_t)r[0]>>((-r[3])&31u)):((int32_t)r[0]<0?0xffffffffu:0)):r[0]<<(r[3]&31u);
goto P_0c086bcc;
P_0c086bcc: /* original f7fc, guest PC 0x0c086bcc */
if(!s->budget--) { s->failed_pc=0x0c086bccu; return 0; }
vf3_matrix_move(s,7,15);
goto P_0c086bce;
P_0c086bce: /* original f32d, guest PC 0x0c086bce */
if(!s->budget--) { s->failed_pc=0x0c086bceu; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c086bd0;
P_0c086bd0: /* original 2609, guest PC 0x0c086bd0 */
if(!s->budget--) { s->failed_pc=0x0c086bd0u; return 0; }
r[6]&=r[0];
goto P_0c086bd2;
P_0c086bd2: /* original 465a, guest PC 0x0c086bd2 */
if(!s->budget--) { s->failed_pc=0x0c086bd2u; return 0; }
r[53]=r[6];
goto P_0c086bd4;
P_0c086bd4: /* original e3f7, guest PC 0x0c086bd4 */
if(!s->budget--) { s->failed_pc=0x0c086bd4u; return 0; }
r[3]=0xfffffff7u;
goto P_0c086bd6;
P_0c086bd6: /* original 443c, guest PC 0x0c086bd6 */
if(!s->budget--) { s->failed_pc=0x0c086bd6u; return 0; }
r[4]=(r[3]&0x80000000u)?((r[3]&31u)?(uint32_t)((int32_t)r[4]>>((-r[3])&31u)):((int32_t)r[4]<0?0xffffffffu:0)):r[4]<<(r[3]&31u);
goto P_0c086bd8;
P_0c086bd8: /* original 24b9, guest PC 0x0c086bd8 */
if(!s->budget--) { s->failed_pc=0x0c086bd8u; return 0; }
r[4]&=r[11];
goto P_0c086bda;
P_0c086bda: /* original f22d, guest PC 0x0c086bda */
if(!s->budget--) { s->failed_pc=0x0c086bdau; return 0; }
fr[2]=vf3_fpu_float(r[53],r[18]);
goto P_0c086bdc;
P_0c086bdc: /* original 445a, guest PC 0x0c086bdc */
if(!s->budget--) { s->failed_pc=0x0c086bdcu; return 0; }
r[53]=r[4];
goto P_0c086bde;
P_0c086bde: /* original f53c, guest PC 0x0c086bde */
if(!s->budget--) { s->failed_pc=0x0c086bdeu; return 0; }
vf3_matrix_move(s,5,3);
goto P_0c086be0;
P_0c086be0: /* original f572, guest PC 0x0c086be0 */
if(!s->budget--) { s->failed_pc=0x0c086be0u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[7],r[18],'*');
goto P_0c086be2;
P_0c086be2: /* original 25c8, guest PC 0x0c086be2 */
if(!s->budget--) { s->failed_pc=0x0c086be2u; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[12])==0)!=0);
goto P_0c086be4;
P_0c086be4: /* original f32d, guest PC 0x0c086be4 */
if(!s->budget--) { s->failed_pc=0x0c086be4u; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c086be6;
P_0c086be6: /* original f62c, guest PC 0x0c086be6 */
if(!s->budget--) { s->failed_pc=0x0c086be6u; return 0; }
vf3_matrix_move(s,6,2);
goto P_0c086be8;
P_0c086be8: /* original f672, guest PC 0x0c086be8 */
if(!s->budget--) { s->failed_pc=0x0c086be8u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[7],r[18],'*');
goto P_0c086bea;
P_0c086bea: /* original f43c, guest PC 0x0c086bea */
if(!s->budget--) { s->failed_pc=0x0c086beau; return 0; }
vf3_matrix_move(s,4,3);
goto P_0c086bec;
P_0c086bec: /* original 8f01, guest PC 0x0c086bec */
if(!s->budget--) { s->failed_pc=0x0c086becu; return 0; }
cond=r[17]&1u;
fr[4]=vf3_fpu_binary(fr[4],fr[7],r[18],'*');
if(!cond) { goto P_0c086bf2; }
goto P_0c086bf0;
P_0c086bee: /* original f472, guest PC 0x0c086bee */
if(!s->budget--) { s->failed_pc=0x0c086beeu; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[7],r[18],'*');
goto P_0c086bf0;
P_0c086bf0: /* original f54d, guest PC 0x0c086bf0 */
if(!s->budget--) { s->failed_pc=0x0c086bf0u; return 0; }
fr[5]^=0x80000000u;
goto P_0c086bf2;
P_0c086bf2: /* original 26c8, guest PC 0x0c086bf2 */
if(!s->budget--) { s->failed_pc=0x0c086bf2u; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[12])==0)!=0);
goto P_0c086bf4;
P_0c086bf4: /* original 8b00, guest PC 0x0c086bf4 */
if(!s->budget--) { s->failed_pc=0x0c086bf4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c086bf8; }
goto P_0c086bf6;
P_0c086bf6: /* original f64d, guest PC 0x0c086bf6 */
if(!s->budget--) { s->failed_pc=0x0c086bf6u; return 0; }
fr[6]^=0x80000000u;
goto P_0c086bf8;
P_0c086bf8: /* original 24c8, guest PC 0x0c086bf8 */
if(!s->budget--) { s->failed_pc=0x0c086bf8u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[12])==0)!=0);
goto P_0c086bfa;
P_0c086bfa: /* original 8f01, guest PC 0x0c086bfa */
if(!s->budget--) { s->failed_pc=0x0c086bfau; return 0; }
cond=r[17]&1u;
fr[5]=vf3_fpu_binary(fr[5],fr[14],r[18],'+');
if(!cond) { goto P_0c086c00; }
goto P_0c086bfe;
P_0c086bfc: /* original f5e0, guest PC 0x0c086bfc */
if(!s->budget--) { s->failed_pc=0x0c086bfcu; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[14],r[18],'+');
goto P_0c086bfe;
P_0c086bfe: /* original f44d, guest PC 0x0c086bfe */
if(!s->budget--) { s->failed_pc=0x0c086bfeu; return 0; }
fr[4]^=0x80000000u;
goto P_0c086c00;
P_0c086c00: /* original e004, guest PC 0x0c086c00 */
if(!s->budget--) { s->failed_pc=0x0c086c00u; return 0; }
r[0]=0x00000004u;
goto P_0c086c02;
P_0c086c02: /* original f3f6, guest PC 0x0c086c02 */
if(!s->budget--) { s->failed_pc=0x0c086c02u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c086c04;
P_0c086c04: /* original e018, guest PC 0x0c086c04 */
if(!s->budget--) { s->failed_pc=0x0c086c04u; return 0; }
r[0]=0x00000018u;
goto P_0c086c06;
P_0c086c06: /* original fe57, guest PC 0x0c086c06 */
if(!s->budget--) { s->failed_pc=0x0c086c06u; return 0; }
vf3_matrix_store(s,ram,5,r[14]+r[0]);
goto P_0c086c08;
P_0c086c08: /* original e01c, guest PC 0x0c086c08 */
if(!s->budget--) { s->failed_pc=0x0c086c08u; return 0; }
r[0]=0x0000001cu;
goto P_0c086c0a;
P_0c086c0a: /* original f430, guest PC 0x0c086c0a */
if(!s->budget--) { s->failed_pc=0x0c086c0au; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'+');
goto P_0c086c0c;
P_0c086c0c: /* original fe67, guest PC 0x0c086c0c */
if(!s->budget--) { s->failed_pc=0x0c086c0cu; return 0; }
vf3_matrix_store(s,ram,6,r[14]+r[0]);
goto P_0c086c0e;
P_0c086c0e: /* original e020, guest PC 0x0c086c0e */
if(!s->budget--) { s->failed_pc=0x0c086c0eu; return 0; }
r[0]=0x00000020u;
goto P_0c086c10;
P_0c086c10: /* original e300, guest PC 0x0c086c10 */
if(!s->budget--) { s->failed_pc=0x0c086c10u; return 0; }
r[3]=0x00000000u;
goto P_0c086c12;
P_0c086c12: /* original fe47, guest PC 0x0c086c12 */
if(!s->budget--) { s->failed_pc=0x0c086c12u; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c086c14;
P_0c086c14: /* original e026, guest PC 0x0c086c14 */
if(!s->budget--) { s->failed_pc=0x0c086c14u; return 0; }
r[0]=0x00000026u;
goto P_0c086c16;
P_0c086c16: /* original 4a0b, guest PC 0x0c086c16 */
if(!s->budget--) { s->failed_pc=0x0c086c16u; return 0; }
target=r[10];
r[16]=code_base|0x0c086c1au;
write(ram,r[14]+r[0],r[3],1);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c086c1au) { target=s->pc; goto dispatch; }
goto P_0c086c1a;
P_0c086c18: /* original 0e34, guest PC 0x0c086c18 */
if(!s->budget--) { s->failed_pc=0x0c086c18u; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c086c1a;
P_0c086c1a: /* original e507, guest PC 0x0c086c1a */
if(!s->budget--) { s->failed_pc=0x0c086c1au; return 0; }
r[5]=0x00000007u;
goto P_0c086c1c;
P_0c086c1c: /* original 6403, guest PC 0x0c086c1c */
if(!s->budget--) { s->failed_pc=0x0c086c1cu; return 0; }
r[4]=r[0];
goto P_0c086c1e;
P_0c086c1e: /* original e038, guest PC 0x0c086c1e */
if(!s->budget--) { s->failed_pc=0x0c086c1eu; return 0; }
r[0]=0x00000038u;
goto P_0c086c20;
P_0c086c20: /* original 2549, guest PC 0x0c086c20 */
if(!s->budget--) { s->failed_pc=0x0c086c20u; return 0; }
r[5]&=r[4];
goto P_0c086c22;
P_0c086c22: /* original 04dc, guest PC 0x0c086c22 */
if(!s->budget--) { s->failed_pc=0x0c086c22u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+r[0],1);
goto P_0c086c24;
P_0c086c24: /* original d02e, guest PC 0x0c086c24 */
if(!s->budget--) { s->failed_pc=0x0c086c24u; return 0; }
r[0]=read(ram,0x0c086ce0u,4);
goto P_0c086c26;
P_0c086c26: /* original 4408, guest PC 0x0c086c26 */
if(!s->budget--) { s->failed_pc=0x0c086c26u; return 0; }
r[4]<<=2;
goto P_0c086c28;
P_0c086c28: /* original 4400, guest PC 0x0c086c28 */
if(!s->budget--) { s->failed_pc=0x0c086c28u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c086c2a;
P_0c086c2a: /* original 354c, guest PC 0x0c086c2a */
if(!s->budget--) { s->failed_pc=0x0c086c2au; return 0; }
r[5]+=r[4];
goto P_0c086c2c;
P_0c086c2c: /* original 055c, guest PC 0x0c086c2c */
if(!s->budget--) { s->failed_pc=0x0c086c2cu; return 0; }
r[5]=(uint32_t)(int32_t)(int8_t)read(ram,r[5]+r[0],1);
goto P_0c086c2e;
P_0c086c2e: /* original d02d, guest PC 0x0c086c2e */
if(!s->budget--) { s->failed_pc=0x0c086c2eu; return 0; }
r[0]=read(ram,0x0c086ce4u,4);
goto P_0c086c30;
P_0c086c30: /* original 4508, guest PC 0x0c086c30 */
if(!s->budget--) { s->failed_pc=0x0c086c30u; return 0; }
r[5]<<=2;
goto P_0c086c32;
P_0c086c32: /* original 055e, guest PC 0x0c086c32 */
if(!s->budget--) { s->failed_pc=0x0c086c32u; return 0; }
r[5]=read(ram,r[5]+r[0],4);
goto P_0c086c34;
P_0c086c34: /* original 1e5a, guest PC 0x0c086c34 */
if(!s->budget--) { s->failed_pc=0x0c086c34u; return 0; }
write(ram,r[14]+40,r[5],4);
goto P_0c086c36;
P_0c086c36: /* original d32c, guest PC 0x0c086c36 */
if(!s->budget--) { s->failed_pc=0x0c086c36u; return 0; }
r[3]=read(ram,0x0c086ce8u,4);
goto P_0c086c38;
P_0c086c38: /* original 430b, guest PC 0x0c086c38 */
if(!s->budget--) { s->failed_pc=0x0c086c38u; return 0; }
target=r[3];
r[16]=code_base|0x0c086c3cu;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c086c3cu) { target=s->pc; goto dispatch; }
goto P_0c086c3c;
P_0c086c3a: /* original 64e3, guest PC 0x0c086c3a */
if(!s->budget--) { s->failed_pc=0x0c086c3au; return 0; }
r[4]=r[14];
goto P_0c086c3c;
P_0c086c3c: /* original 858f, guest PC 0x0c086c3c */
if(!s->budget--) { s->failed_pc=0x0c086c3cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[8]+30,2);
goto P_0c086c3e;
P_0c086c3e: /* original 79ff, guest PC 0x0c086c3e */
if(!s->budget--) { s->failed_pc=0x0c086c3eu; return 0; }
r[9]+=0xffffffffu;
goto P_0c086c40;
P_0c086c40: /* original d32a, guest PC 0x0c086c40 */
if(!s->budget--) { s->failed_pc=0x0c086c40u; return 0; }
r[3]=read(ram,0x0c086cecu,4);
goto P_0c086c42;
P_0c086c42: /* original 6403, guest PC 0x0c086c42 */
if(!s->budget--) { s->failed_pc=0x0c086c42u; return 0; }
r[4]=r[0];
goto P_0c086c44;
P_0c086c44: /* original 9146, guest PC 0x0c086c44 */
if(!s->budget--) { s->failed_pc=0x0c086c44u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c086cd4u,2);
goto P_0c086c46;
P_0c086c46: /* original 6032, guest PC 0x0c086c46 */
if(!s->budget--) { s->failed_pc=0x0c086c46u; return 0; }
tmp=read(ram,r[3],4);
r[0]=tmp;
goto P_0c086c48;
P_0c086c48: /* original e3f3, guest PC 0x0c086c48 */
if(!s->budget--) { s->failed_pc=0x0c086c48u; return 0; }
r[3]=0xfffffff3u;
goto P_0c086c4a;
P_0c086c4a: /* original c903, guest PC 0x0c086c4a */
if(!s->budget--) { s->failed_pc=0x0c086c4au; return 0; }
r[0]&=3u;
goto P_0c086c4c;
P_0c086c4c: /* original 6503, guest PC 0x0c086c4c */
if(!s->budget--) { s->failed_pc=0x0c086c4cu; return 0; }
r[5]=r[0];
goto P_0c086c4e;
P_0c086c4e: /* original d028, guest PC 0x0c086c4e */
if(!s->budget--) { s->failed_pc=0x0c086c4eu; return 0; }
r[0]=read(ram,0x0c086cf0u,4);
goto P_0c086c50;
P_0c086c50: /* original 4500, guest PC 0x0c086c50 */
if(!s->budget--) { s->failed_pc=0x0c086c50u; return 0; }
r[17]=(r[17]&~1u)|((r[5]>>31)!=0);
r[5]<<=1;
goto P_0c086c52;
P_0c086c52: /* original 025d, guest PC 0x0c086c52 */
if(!s->budget--) { s->failed_pc=0x0c086c52u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[5]+r[0],2);
goto P_0c086c54;
P_0c086c54: /* original 903f, guest PC 0x0c086c54 */
if(!s->budget--) { s->failed_pc=0x0c086c54u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c086cd6u,2);
goto P_0c086c56;
P_0c086c56: /* original 652d, guest PC 0x0c086c56 */
if(!s->budget--) { s->failed_pc=0x0c086c56u; return 0; }
r[5]=r[2]&65535u;
goto P_0c086c58;
P_0c086c58: /* original 345c, guest PC 0x0c086c58 */
if(!s->budget--) { s->failed_pc=0x0c086c58u; return 0; }
r[4]+=r[5];
goto P_0c086c5a;
P_0c086c5a: /* original 341c, guest PC 0x0c086c5a */
if(!s->budget--) { s->failed_pc=0x0c086c5au; return 0; }
r[4]+=r[1];
goto P_0c086c5c;
P_0c086c5c: /* original e503, guest PC 0x0c086c5c */
if(!s->budget--) { s->failed_pc=0x0c086c5cu; return 0; }
r[5]=0x00000003u;
goto P_0c086c5e;
P_0c086c5e: /* original 443c, guest PC 0x0c086c5e */
if(!s->budget--) { s->failed_pc=0x0c086c5eu; return 0; }
r[4]=(r[3]&0x80000000u)?((r[3]&31u)?(uint32_t)((int32_t)r[4]>>((-r[3])&31u)):((int32_t)r[4]<0?0xffffffffu:0)):r[4]<<(r[3]&31u);
goto P_0c086c60;
P_0c086c60: /* original 2549, guest PC 0x0c086c60 */
if(!s->budget--) { s->failed_pc=0x0c086c60u; return 0; }
r[5]&=r[4];
goto P_0c086c62;
P_0c086c62: /* original 305c, guest PC 0x0c086c62 */
if(!s->budget--) { s->failed_pc=0x0c086c62u; return 0; }
r[0]+=r[5];
goto P_0c086c64;
P_0c086c64: /* original 81e5, guest PC 0x0c086c64 */
if(!s->budget--) { s->failed_pc=0x0c086c64u; return 0; }
write(ram,r[14]+10,r[0],2);
goto P_0c086c66;
P_0c086c66: /* original 2998, guest PC 0x0c086c66 */
if(!s->budget--) { s->failed_pc=0x0c086c66u; return 0; }
r[17]=(r[17]&~1u)|(((r[9]&r[9])==0)!=0);
goto P_0c086c68;
P_0c086c68: /* original 8b98, guest PC 0x0c086c68 */
if(!s->budget--) { s->failed_pc=0x0c086c68u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c086b9c; }
goto P_0c086c6a;
P_0c086c6a: /* original e03b, guest PC 0x0c086c6a */
if(!s->budget--) { s->failed_pc=0x0c086c6au; return 0; }
r[0]=0x0000003bu;
goto P_0c086c6c;
P_0c086c6c: /* original 04dc, guest PC 0x0c086c6c */
if(!s->budget--) { s->failed_pc=0x0c086c6cu; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+r[0],1);
goto P_0c086c6e;
P_0c086c6e: /* original 4410, guest PC 0x0c086c6e */
if(!s->budget--) { s->failed_pc=0x0c086c6eu; return 0; }
--r[4];
r[17]=(r[17]&~1u)|((r[4]==0)!=0);
goto P_0c086c70;
P_0c086c70: /* original 8b20, guest PC 0x0c086c70 */
if(!s->budget--) { s->failed_pc=0x0c086c70u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c086cb4; }
goto P_0c086c72;
P_0c086c72: /* original c721, guest PC 0x0c086c72 */
if(!s->budget--) { s->failed_pc=0x0c086c72u; return 0; }
r[0]=0x0c086cf8u;
goto P_0c086c74;
P_0c086c74: /* original d31f, guest PC 0x0c086c74 */
if(!s->budget--) { s->failed_pc=0x0c086c74u; return 0; }
r[3]=read(ram,0x0c086cf4u,4);
goto P_0c086c76;
P_0c086c76: /* original f608, guest PC 0x0c086c76 */
if(!s->budget--) { s->failed_pc=0x0c086c76u; return 0; }
vf3_matrix_load(s,ram,6,r[0]);
goto P_0c086c78;
P_0c086c78: /* original e010, guest PC 0x0c086c78 */
if(!s->budget--) { s->failed_pc=0x0c086c78u; return 0; }
r[0]=0x00000010u;
goto P_0c086c7a;
P_0c086c7a: /* original f486, guest PC 0x0c086c7a */
if(!s->budget--) { s->failed_pc=0x0c086c7au; return 0; }
vf3_matrix_load(s,ram,4,r[8]+r[0]);
goto P_0c086c7c;
P_0c086c7c: /* original e018, guest PC 0x0c086c7c */
if(!s->budget--) { s->failed_pc=0x0c086c7cu; return 0; }
r[0]=0x00000018u;
goto P_0c086c7e;
P_0c086c7e: /* original f586, guest PC 0x0c086c7e */
if(!s->budget--) { s->failed_pc=0x0c086c7eu; return 0; }
vf3_matrix_load(s,ram,5,r[8]+r[0]);
goto P_0c086c80;
P_0c086c80: /* original e00c, guest PC 0x0c086c80 */
if(!s->budget--) { s->failed_pc=0x0c086c80u; return 0; }
r[0]=0x0000000cu;
goto P_0c086c82;
P_0c086c82: /* original f7d6, guest PC 0x0c086c82 */
if(!s->budget--) { s->failed_pc=0x0c086c82u; return 0; }
vf3_matrix_load(s,ram,7,r[13]+r[0]);
goto P_0c086c84;
P_0c086c84: /* original e014, guest PC 0x0c086c84 */
if(!s->budget--) { s->failed_pc=0x0c086c84u; return 0; }
r[0]=0x00000014u;
goto P_0c086c86;
P_0c086c86: /* original f8d6, guest PC 0x0c086c86 */
if(!s->budget--) { s->failed_pc=0x0c086c86u; return 0; }
vf3_matrix_load(s,ram,8,r[13]+r[0]);
goto P_0c086c88;
P_0c086c88: /* original e43f, guest PC 0x0c086c88 */
if(!s->budget--) { s->failed_pc=0x0c086c88u; return 0; }
r[4]=0x0000003fu;
goto P_0c086c8a;
P_0c086c8a: /* original f471, guest PC 0x0c086c8a */
if(!s->budget--) { s->failed_pc=0x0c086c8au; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[7],r[18],'-');
goto P_0c086c8c;
P_0c086c8c: /* original 2459, guest PC 0x0c086c8c */
if(!s->budget--) { s->failed_pc=0x0c086c8cu; return 0; }
r[4]&=r[5];
goto P_0c086c8e;
P_0c086c8e: /* original f581, guest PC 0x0c086c8e */
if(!s->budget--) { s->failed_pc=0x0c086c8eu; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[8],r[18],'-');
goto P_0c086c90;
P_0c086c90: /* original 6532, guest PC 0x0c086c90 */
if(!s->budget--) { s->failed_pc=0x0c086c90u; return 0; }
tmp=read(ram,r[3],4);
r[5]=tmp;
goto P_0c086c92;
P_0c086c92: /* original 7407, guest PC 0x0c086c92 */
if(!s->budget--) { s->failed_pc=0x0c086c92u; return 0; }
r[4]+=0x00000007u;
goto P_0c086c94;
P_0c086c94: /* original f34c, guest PC 0x0c086c94 */
if(!s->budget--) { s->failed_pc=0x0c086c94u; return 0; }
vf3_matrix_move(s,3,4);
goto P_0c086c96;
P_0c086c96: /* original f432, guest PC 0x0c086c96 */
if(!s->budget--) { s->failed_pc=0x0c086c96u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'*');
goto P_0c086c98;
P_0c086c98: /* original f35c, guest PC 0x0c086c98 */
if(!s->budget--) { s->failed_pc=0x0c086c98u; return 0; }
vf3_matrix_move(s,3,5);
goto P_0c086c9a;
P_0c086c9a: /* original f532, guest PC 0x0c086c9a */
if(!s->budget--) { s->failed_pc=0x0c086c9au; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[3],r[18],'*');
goto P_0c086c9c;
P_0c086c9c: /* original f450, guest PC 0x0c086c9c */
if(!s->budget--) { s->failed_pc=0x0c086c9cu; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[5],r[18],'+');
goto P_0c086c9e;
P_0c086c9e: /* original f465, guest PC 0x0c086c9e */
if(!s->budget--) { s->failed_pc=0x0c086c9eu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[4])>as_float(fr[6]))!=0);
goto P_0c086ca0;
P_0c086ca0: /* original 8d03, guest PC 0x0c086ca0 */
if(!s->budget--) { s->failed_pc=0x0c086ca0u; return 0; }
cond=r[17]&1u;
tmp=read(ram,r[5],4);
r[5]=tmp;
if(cond) { goto P_0c086caa; }
goto P_0c086ca4;
P_0c086ca2: /* original 6552, guest PC 0x0c086ca2 */
if(!s->budget--) { s->failed_pc=0x0c086ca2u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c086ca4;
P_0c086ca4: /* original 9118, guest PC 0x0c086ca4 */
if(!s->budget--) { s->failed_pc=0x0c086ca4u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c086cd8u,2);
goto P_0c086ca6;
P_0c086ca6: /* original a002, guest PC 0x0c086ca6 */
if(!s->budget--) { s->failed_pc=0x0c086ca6u; return 0; }
r[5]|=r[1];
goto P_0c086cae;
P_0c086ca8: /* original 251b, guest PC 0x0c086ca8 */
if(!s->budget--) { s->failed_pc=0x0c086ca8u; return 0; }
r[5]|=r[1];
goto P_0c086caa;
P_0c086caa: /* original 9016, guest PC 0x0c086caa */
if(!s->budget--) { s->failed_pc=0x0c086caau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c086cdau,2);
goto P_0c086cac;
P_0c086cac: /* original 250b, guest PC 0x0c086cac */
if(!s->budget--) { s->failed_pc=0x0c086cacu; return 0; }
r[5]|=r[0];
goto P_0c086cae;
P_0c086cae: /* original d211, guest PC 0x0c086cae */
if(!s->budget--) { s->failed_pc=0x0c086caeu; return 0; }
r[2]=read(ram,0x0c086cf4u,4);
goto P_0c086cb0;
P_0c086cb0: /* original 6322, guest PC 0x0c086cb0 */
if(!s->budget--) { s->failed_pc=0x0c086cb0u; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c086cb2;
P_0c086cb2: /* original 2352, guest PC 0x0c086cb2 */
if(!s->budget--) { s->failed_pc=0x0c086cb2u; return 0; }
write(ram,r[3],r[5],4);
goto P_0c086cb4;
P_0c086cb4: /* original e03b, guest PC 0x0c086cb4 */
if(!s->budget--) { s->failed_pc=0x0c086cb4u; return 0; }
r[0]=0x0000003bu;
goto P_0c086cb6;
P_0c086cb6: /* original 0d44, guest PC 0x0c086cb6 */
if(!s->budget--) { s->failed_pc=0x0c086cb6u; return 0; }
write(ram,r[13]+r[0],r[4],1);
goto P_0c086cb8;
P_0c086cb8: /* original 7f08, guest PC 0x0c086cb8 */
if(!s->budget--) { s->failed_pc=0x0c086cb8u; return 0; }
r[15]+=0x00000008u;
goto P_0c086cba;
P_0c086cba: /* original 4f26, guest PC 0x0c086cba */
if(!s->budget--) { s->failed_pc=0x0c086cbau; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c086cbc;
P_0c086cbc: /* original fcf9, guest PC 0x0c086cbc */
if(!s->budget--) { s->failed_pc=0x0c086cbcu; return 0; }
vf3_matrix_load(s,ram,12,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c086cbe;
P_0c086cbe: /* original fdf9, guest PC 0x0c086cbe */
if(!s->budget--) { s->failed_pc=0x0c086cbeu; return 0; }
vf3_matrix_load(s,ram,13,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c086cc0;
P_0c086cc0: /* original fef9, guest PC 0x0c086cc0 */
if(!s->budget--) { s->failed_pc=0x0c086cc0u; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c086cc2;
P_0c086cc2: /* original fff9, guest PC 0x0c086cc2 */
if(!s->budget--) { s->failed_pc=0x0c086cc2u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c086cc4;
P_0c086cc4: /* original 68f6, guest PC 0x0c086cc4 */
if(!s->budget--) { s->failed_pc=0x0c086cc4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c086cc6;
P_0c086cc6: /* original 69f6, guest PC 0x0c086cc6 */
if(!s->budget--) { s->failed_pc=0x0c086cc6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c086cc8;
P_0c086cc8: /* original 6af6, guest PC 0x0c086cc8 */
if(!s->budget--) { s->failed_pc=0x0c086cc8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c086cca;
P_0c086cca: /* original 6bf6, guest PC 0x0c086cca */
if(!s->budget--) { s->failed_pc=0x0c086ccau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c086ccc;
P_0c086ccc: /* original 6cf6, guest PC 0x0c086ccc */
if(!s->budget--) { s->failed_pc=0x0c086cccu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c086cce;
P_0c086cce: /* original 6df6, guest PC 0x0c086cce */
if(!s->budget--) { s->failed_pc=0x0c086cceu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c086cd0;
P_0c086cd0: /* original 000b, guest PC 0x0c086cd0 */
if(!s->budget--) { s->failed_pc=0x0c086cd0u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c086cd2: /* original 6ef6, guest PC 0x0c086cd2 */
if(!s->budget--) { s->failed_pc=0x0c086cd2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c086cd4u,s,ram);
P_0c087542: /* original 5041, guest PC 0x0c087542 */
if(!s->budget--) { s->failed_pc=0x0c087542u; return 0; }
r[0]=read(ram,r[4]+4,4);
goto P_0c087544;
P_0c087544: /* original 88ff, guest PC 0x0c087544 */
if(!s->budget--) { s->failed_pc=0x0c087544u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c087546;
P_0c087546: /* original 8d0a, guest PC 0x0c087546 */
if(!s->budget--) { s->failed_pc=0x0c087546u; return 0; }
cond=r[17]&1u;
r[5]=r[0];
if(cond) { goto P_0c08755e; }
goto P_0c08754a;
P_0c087548: /* original 6503, guest PC 0x0c087548 */
if(!s->budget--) { s->failed_pc=0x0c087548u; return 0; }
r[5]=r[0];
goto P_0c08754a;
P_0c08754a: /* original 6252, guest PC 0x0c08754a */
if(!s->budget--) { s->failed_pc=0x0c08754au; return 0; }
tmp=read(ram,r[5],4);
r[2]=tmp;
goto P_0c08754c;
P_0c08754c: /* original 1421, guest PC 0x0c08754c */
if(!s->budget--) { s->failed_pc=0x0c08754cu; return 0; }
write(ram,r[4]+4,r[2],4);
goto P_0c08754e;
P_0c08754e: /* original 6642, guest PC 0x0c08754e */
if(!s->budget--) { s->failed_pc=0x0c08754eu; return 0; }
tmp=read(ram,r[4],4);
r[6]=tmp;
goto P_0c087550;
P_0c087550: /* original 6063, guest PC 0x0c087550 */
if(!s->budget--) { s->failed_pc=0x0c087550u; return 0; }
r[0]=r[6];
goto P_0c087552;
P_0c087552: /* original 88ff, guest PC 0x0c087552 */
if(!s->budget--) { s->failed_pc=0x0c087552u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c087554;
P_0c087554: /* original 2562, guest PC 0x0c087554 */
if(!s->budget--) { s->failed_pc=0x0c087554u; return 0; }
write(ram,r[5],r[6],4);
goto P_0c087556;
P_0c087556: /* original 2452, guest PC 0x0c087556 */
if(!s->budget--) { s->failed_pc=0x0c087556u; return 0; }
write(ram,r[4],r[5],4);
goto P_0c087558;
P_0c087558: /* original 8d01, guest PC 0x0c087558 */
if(!s->budget--) { s->failed_pc=0x0c087558u; return 0; }
cond=r[17]&1u;
write(ram,r[5]+4,r[4],4);
if(cond) { goto P_0c08755e; }
goto P_0c08755c;
P_0c08755a: /* original 1541, guest PC 0x0c08755a */
if(!s->budget--) { s->failed_pc=0x0c08755au; return 0; }
write(ram,r[5]+4,r[4],4);
goto P_0c08755c;
P_0c08755c: /* original 1651, guest PC 0x0c08755c */
if(!s->budget--) { s->failed_pc=0x0c08755cu; return 0; }
write(ram,r[6]+4,r[5],4);
goto P_0c08755e;
P_0c08755e: /* original 000b, guest PC 0x0c08755e */
if(!s->budget--) { s->failed_pc=0x0c08755eu; return 0; }
target=r[16];
r[0]=r[5];
s->pc=target; return ram->oob==0;
P_0c087560: /* original 6053, guest PC 0x0c087560 */
if(!s->budget--) { s->failed_pc=0x0c087560u; return 0; }
r[0]=r[5];
return vf3_matrix_family(0x0c087562u,s,ram);
P_0c08894c: /* original 6543, guest PC 0x0c08894c */
if(!s->budget--) { s->failed_pc=0x0c08894cu; return 0; }
r[5]=r[4];
goto P_0c08894e;
P_0c08894e: /* original 6643, guest PC 0x0c08894e */
if(!s->budget--) { s->failed_pc=0x0c08894eu; return 0; }
r[6]=r[4];
goto P_0c088950;
P_0c088950: /* original e40e, guest PC 0x0c088950 */
if(!s->budget--) { s->failed_pc=0x0c088950u; return 0; }
r[4]=0x0000000eu;
goto P_0c088952;
P_0c088952: /* original e700, guest PC 0x0c088952 */
if(!s->budget--) { s->failed_pc=0x0c088952u; return 0; }
r[7]=0x00000000u;
goto P_0c088954;
P_0c088954: /* original 7508, guest PC 0x0c088954 */
if(!s->budget--) { s->failed_pc=0x0c088954u; return 0; }
r[5]+=0x00000008u;
goto P_0c088956;
P_0c088956: /* original 4410, guest PC 0x0c088956 */
if(!s->budget--) { s->failed_pc=0x0c088956u; return 0; }
--r[4];
r[17]=(r[17]&~1u)|((r[4]==0)!=0);
goto P_0c088958;
P_0c088958: /* original 2571, guest PC 0x0c088958 */
if(!s->budget--) { s->failed_pc=0x0c088958u; return 0; }
write(ram,r[5],r[7],2);
goto P_0c08895a;
P_0c08895a: /* original 8ffc, guest PC 0x0c08895a */
if(!s->budget--) { s->failed_pc=0x0c08895au; return 0; }
cond=r[17]&1u;
r[5]+=0x00000004u;
if(!cond) { goto P_0c088956; }
goto P_0c08895e;
P_0c08895c: /* original 7504, guest PC 0x0c08895c */
if(!s->budget--) { s->failed_pc=0x0c08895cu; return 0; }
r[5]+=0x00000004u;
goto P_0c08895e;
P_0c08895e: /* original e000, guest PC 0x0c08895e */
if(!s->budget--) { s->failed_pc=0x0c08895eu; return 0; }
r[0]=0x00000000u;
goto P_0c088960;
P_0c088960: /* original 8163, guest PC 0x0c088960 */
if(!s->budget--) { s->failed_pc=0x0c088960u; return 0; }
write(ram,r[6]+6,r[0],2);
goto P_0c088962;
P_0c088962: /* original 000b, guest PC 0x0c088962 */
if(!s->budget--) { s->failed_pc=0x0c088962u; return 0; }
target=r[16];
write(ram,r[6]+4,r[0],2);
s->pc=target; return ram->oob==0;
P_0c088964: /* original 8162, guest PC 0x0c088964 */
if(!s->budget--) { s->failed_pc=0x0c088964u; return 0; }
write(ram,r[6]+4,r[0],2);
goto P_0c088966;
P_0c088966: /* original 5544, guest PC 0x0c088966 */
if(!s->budget--) { s->failed_pc=0x0c088966u; return 0; }
r[5]=read(ram,r[4]+16,4);
goto P_0c088968;
P_0c088968: /* original d439, guest PC 0x0c088968 */
if(!s->budget--) { s->failed_pc=0x0c088968u; return 0; }
r[4]=read(ram,0x0c088a50u,4);
goto P_0c08896a;
P_0c08896a: /* original 4508, guest PC 0x0c08896a */
if(!s->budget--) { s->failed_pc=0x0c08896au; return 0; }
r[5]<<=2;
goto P_0c08896c;
P_0c08896c: /* original 4508, guest PC 0x0c08896c */
if(!s->budget--) { s->failed_pc=0x0c08896cu; return 0; }
r[5]<<=2;
goto P_0c08896e;
P_0c08896e: /* original 4508, guest PC 0x0c08896e */
if(!s->budget--) { s->failed_pc=0x0c08896eu; return 0; }
r[5]<<=2;
goto P_0c088970;
P_0c088970: /* original 4500, guest PC 0x0c088970 */
if(!s->budget--) { s->failed_pc=0x0c088970u; return 0; }
r[17]=(r[17]&~1u)|((r[5]>>31)!=0);
r[5]<<=1;
goto P_0c088972;
P_0c088972: /* original 345c, guest PC 0x0c088972 */
if(!s->budget--) { s->failed_pc=0x0c088972u; return 0; }
r[4]+=r[5];
goto P_0c088974;
P_0c088974: /* original 000b, guest PC 0x0c088974 */
if(!s->budget--) { s->failed_pc=0x0c088974u; return 0; }
target=r[16];
r[0]=r[4];
s->pc=target; return ram->oob==0;
P_0c088976: /* original 6043, guest PC 0x0c088976 */
if(!s->budget--) { s->failed_pc=0x0c088976u; return 0; }
r[0]=r[4];
goto P_0c088978;
P_0c088978: /* original c736, guest PC 0x0c088978 */
if(!s->budget--) { s->failed_pc=0x0c088978u; return 0; }
r[0]=0x0c088a54u;
goto P_0c08897a;
P_0c08897a: /* original f708, guest PC 0x0c08897a */
if(!s->budget--) { s->failed_pc=0x0c08897au; return 0; }
vf3_matrix_load(s,ram,7,r[0]);
goto P_0c08897c;
P_0c08897c: /* original 9067, guest PC 0x0c08897c */
if(!s->budget--) { s->failed_pc=0x0c08897cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c088a4eu,2);
goto P_0c08897e;
P_0c08897e: /* original f646, guest PC 0x0c08897e */
if(!s->budget--) { s->failed_pc=0x0c08897eu; return 0; }
vf3_matrix_load(s,ram,6,r[4]+r[0]);
goto P_0c088980;
P_0c088980: /* original 7008, guest PC 0x0c088980 */
if(!s->budget--) { s->failed_pc=0x0c088980u; return 0; }
r[0]+=0x00000008u;
goto P_0c088982;
P_0c088982: /* original f346, guest PC 0x0c088982 */
if(!s->budget--) { s->failed_pc=0x0c088982u; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c088984;
P_0c088984: /* original f641, guest PC 0x0c088984 */
if(!s->budget--) { s->failed_pc=0x0c088984u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[4],r[18],'-');
goto P_0c088986;
P_0c088986: /* original f34d, guest PC 0x0c088986 */
if(!s->budget--) { s->failed_pc=0x0c088986u; return 0; }
fr[3]^=0x80000000u;
goto P_0c088988;
P_0c088988: /* original f43c, guest PC 0x0c088988 */
if(!s->budget--) { s->failed_pc=0x0c088988u; return 0; }
vf3_matrix_move(s,4,3);
goto P_0c08898a;
P_0c08898a: /* original f451, guest PC 0x0c08898a */
if(!s->budget--) { s->failed_pc=0x0c08898au; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[5],r[18],'-');
goto P_0c08898c;
P_0c08898c: /* original f36c, guest PC 0x0c08898c */
if(!s->budget--) { s->failed_pc=0x0c08898cu; return 0; }
vf3_matrix_move(s,3,6);
goto P_0c08898e;
P_0c08898e: /* original f362, guest PC 0x0c08898e */
if(!s->budget--) { s->failed_pc=0x0c08898eu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[6],r[18],'*');
goto P_0c088990;
P_0c088990: /* original f04c, guest PC 0x0c088990 */
if(!s->budget--) { s->failed_pc=0x0c088990u; return 0; }
vf3_matrix_move(s,0,4);
goto P_0c088992;
P_0c088992: /* original f34e, guest PC 0x0c088992 */
if(!s->budget--) { s->failed_pc=0x0c088992u; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[4],fr[3],r[18]);
goto P_0c088994;
P_0c088994: /* original f43c, guest PC 0x0c088994 */
if(!s->budget--) { s->failed_pc=0x0c088994u; return 0; }
vf3_matrix_move(s,4,3);
goto P_0c088996;
P_0c088996: /* original f475, guest PC 0x0c088996 */
if(!s->budget--) { s->failed_pc=0x0c088996u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[4])>as_float(fr[7]))!=0);
goto P_0c088998;
P_0c088998: /* original 890c, guest PC 0x0c088998 */
if(!s->budget--) { s->failed_pc=0x0c088998u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0889b4; }
goto P_0c08899a;
P_0c08899a: /* original 6251, guest PC 0x0c08899a */
if(!s->budget--) { s->failed_pc=0x0c08899au; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[5],2);
r[2]=tmp;
goto P_0c08899c;
P_0c08899c: /* original 636d, guest PC 0x0c08899c */
if(!s->budget--) { s->failed_pc=0x0c08899cu; return 0; }
r[3]=r[6]&65535u;
goto P_0c08899e;
P_0c08899e: /* original 622d, guest PC 0x0c08899e */
if(!s->budget--) { s->failed_pc=0x0c08899eu; return 0; }
r[2]=r[2]&65535u;
goto P_0c0889a0;
P_0c0889a0: /* original 2238, guest PC 0x0c0889a0 */
if(!s->budget--) { s->failed_pc=0x0c0889a0u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0889a2;
P_0c0889a2: /* original 8b07, guest PC 0x0c0889a2 */
if(!s->budget--) { s->failed_pc=0x0c0889a2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0889b4; }
goto P_0c0889a4;
P_0c0889a4: /* original d32c, guest PC 0x0c0889a4 */
if(!s->budget--) { s->failed_pc=0x0c0889a4u; return 0; }
r[3]=read(ram,0x0c088a58u,4);
goto P_0c0889a6;
P_0c0889a6: /* original 6432, guest PC 0x0c0889a6 */
if(!s->budget--) { s->failed_pc=0x0c0889a6u; return 0; }
tmp=read(ram,r[3],4);
r[4]=tmp;
goto P_0c0889a8;
P_0c0889a8: /* original 6042, guest PC 0x0c0889a8 */
if(!s->budget--) { s->failed_pc=0x0c0889a8u; return 0; }
tmp=read(ram,r[4],4);
r[0]=tmp;
goto P_0c0889aa;
P_0c0889aa: /* original cb40, guest PC 0x0c0889aa */
if(!s->budget--) { s->failed_pc=0x0c0889aau; return 0; }
r[0]|=64u;
goto P_0c0889ac;
P_0c0889ac: /* original 2402, guest PC 0x0c0889ac */
if(!s->budget--) { s->failed_pc=0x0c0889acu; return 0; }
write(ram,r[4],r[0],4);
goto P_0c0889ae;
P_0c0889ae: /* original 6251, guest PC 0x0c0889ae */
if(!s->budget--) { s->failed_pc=0x0c0889aeu; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[5],2);
r[2]=tmp;
goto P_0c0889b0;
P_0c0889b0: /* original 226b, guest PC 0x0c0889b0 */
if(!s->budget--) { s->failed_pc=0x0c0889b0u; return 0; }
r[2]|=r[6];
goto P_0c0889b2;
P_0c0889b2: /* original 2521, guest PC 0x0c0889b2 */
if(!s->budget--) { s->failed_pc=0x0c0889b2u; return 0; }
write(ram,r[5],r[2],2);
goto P_0c0889b4;
P_0c0889b4: /* original 000b, guest PC 0x0c0889b4 */
if(!s->budget--) { s->failed_pc=0x0c0889b4u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c0889b6: /* original 0009, guest PC 0x0c0889b6 */
if(!s->budget--) { s->failed_pc=0x0c0889b6u; return 0; }
return vf3_matrix_family(0x0c0889b8u,s,ram);
P_0c0889cc: /* original 4f22, guest PC 0x0c0889cc */
if(!s->budget--) { s->failed_pc=0x0c0889ccu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0889ce;
P_0c0889ce: /* original 6212, guest PC 0x0c0889ce */
if(!s->budget--) { s->failed_pc=0x0c0889ceu; return 0; }
tmp=read(ram,r[1],4);
r[2]=tmp;
goto P_0c0889d0;
P_0c0889d0: /* original d322, guest PC 0x0c0889d0 */
if(!s->budget--) { s->failed_pc=0x0c0889d0u; return 0; }
r[3]=read(ram,0x0c088a5cu,4);
goto P_0c0889d2;
P_0c0889d2: /* original 7fe0, guest PC 0x0c0889d2 */
if(!s->budget--) { s->failed_pc=0x0c0889d2u; return 0; }
r[15]+=0xffffffe0u;
goto P_0c0889d4;
P_0c0889d4: /* original 2238, guest PC 0x0c0889d4 */
if(!s->budget--) { s->failed_pc=0x0c0889d4u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0889d6;
P_0c0889d6: /* original 8d02, guest PC 0x0c0889d6 */
if(!s->budget--) { s->failed_pc=0x0c0889d6u; return 0; }
cond=r[17]&1u;
r[12]=r[4];
if(cond) { goto P_0c0889de; }
goto P_0c0889da;
P_0c0889d8: /* original 6c43, guest PC 0x0c0889d8 */
if(!s->budget--) { s->failed_pc=0x0c0889d8u; return 0; }
r[12]=r[4];
goto P_0c0889da;
P_0c0889da: /* original a0a1, guest PC 0x0c0889da */
if(!s->budget--) { s->failed_pc=0x0c0889dau; return 0; }
goto P_0c088b20;
P_0c0889dc: /* original 0009, guest PC 0x0c0889dc */
if(!s->budget--) { s->failed_pc=0x0c0889dcu; return 0; }
goto P_0c0889de;
P_0c0889de: /* original d123, guest PC 0x0c0889de */
if(!s->budget--) { s->failed_pc=0x0c0889deu; return 0; }
r[1]=read(ram,0x0c088a6cu,4);
goto P_0c0889e0;
P_0c0889e0: /* original d321, guest PC 0x0c0889e0 */
if(!s->budget--) { s->failed_pc=0x0c0889e0u; return 0; }
r[3]=read(ram,0x0c088a68u,4);
goto P_0c0889e2;
P_0c0889e2: /* original 6212, guest PC 0x0c0889e2 */
if(!s->budget--) { s->failed_pc=0x0c0889e2u; return 0; }
tmp=read(ram,r[1],4);
r[2]=tmp;
goto P_0c0889e4;
P_0c0889e4: /* original de1f, guest PC 0x0c0889e4 */
if(!s->budget--) { s->failed_pc=0x0c0889e4u; return 0; }
r[14]=read(ram,0x0c088a64u,4);
goto P_0c0889e6;
P_0c0889e6: /* original 2238, guest PC 0x0c0889e6 */
if(!s->budget--) { s->failed_pc=0x0c0889e6u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0889e8;
P_0c0889e8: /* original 890b, guest PC 0x0c0889e8 */
if(!s->budget--) { s->failed_pc=0x0c0889e8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c088a02; }
goto P_0c0889ea;
P_0c0889ea: /* original bfaf, guest PC 0x0c0889ea */
if(!s->budget--) { s->failed_pc=0x0c0889eau; return 0; }
target=0x0c08894cu; r[16]=code_base|0x0c0889eeu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0889eeu) { target=s->pc; goto dispatch; }
goto P_0c0889ee;
P_0c0889ec: /* original 0009, guest PC 0x0c0889ec */
if(!s->budget--) { s->failed_pc=0x0c0889ecu; return 0; }
goto P_0c0889ee;
P_0c0889ee: /* original e054, guest PC 0x0c0889ee */
if(!s->budget--) { s->failed_pc=0x0c0889eeu; return 0; }
r[0]=0x00000054u;
goto P_0c0889f0;
P_0c0889f0: /* original bfb9, guest PC 0x0c0889f0 */
if(!s->budget--) { s->failed_pc=0x0c0889f0u; return 0; }
target=0x0c088966u; r[16]=code_base|0x0c0889f4u;
r[4]=read(ram,r[14]+r[0],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0889f4u) { target=s->pc; goto dispatch; }
goto P_0c0889f4;
P_0c0889f2: /* original 04ee, guest PC 0x0c0889f2 */
if(!s->budget--) { s->failed_pc=0x0c0889f2u; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c0889f4;
P_0c0889f4: /* original 6403, guest PC 0x0c0889f4 */
if(!s->budget--) { s->failed_pc=0x0c0889f4u; return 0; }
r[4]=r[0];
goto P_0c0889f6;
P_0c0889f6: /* original e034, guest PC 0x0c0889f6 */
if(!s->budget--) { s->failed_pc=0x0c0889f6u; return 0; }
r[0]=0x00000034u;
goto P_0c0889f8;
P_0c0889f8: /* original 004d, guest PC 0x0c0889f8 */
if(!s->budget--) { s->failed_pc=0x0c0889f8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c0889fa;
P_0c0889fa: /* original 81c2, guest PC 0x0c0889fa */
if(!s->budget--) { s->failed_pc=0x0c0889fau; return 0; }
write(ram,r[12]+4,r[0],2);
goto P_0c0889fc;
P_0c0889fc: /* original e036, guest PC 0x0c0889fc */
if(!s->budget--) { s->failed_pc=0x0c0889fcu; return 0; }
r[0]=0x00000036u;
goto P_0c0889fe;
P_0c0889fe: /* original 004d, guest PC 0x0c0889fe */
if(!s->budget--) { s->failed_pc=0x0c0889feu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c088a00;
P_0c088a00: /* original 81c3, guest PC 0x0c088a00 */
if(!s->budget--) { s->failed_pc=0x0c088a00u; return 0; }
write(ram,r[12]+6,r[0],2);
goto P_0c088a02;
P_0c088a02: /* original d31b, guest PC 0x0c088a02 */
if(!s->budget--) { s->failed_pc=0x0c088a02u; return 0; }
r[3]=read(ram,0x0c088a70u,4);
goto P_0c088a04;
P_0c088a04: /* original 6430, guest PC 0x0c088a04 */
if(!s->budget--) { s->failed_pc=0x0c088a04u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[3],1);
r[4]=tmp;
goto P_0c088a06;
P_0c088a06: /* original 604c, guest PC 0x0c088a06 */
if(!s->budget--) { s->failed_pc=0x0c088a06u; return 0; }
r[0]=r[4]&255u;
goto P_0c088a08;
P_0c088a08: /* original 8809, guest PC 0x0c088a08 */
if(!s->budget--) { s->failed_pc=0x0c088a08u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000009u)!=0);
goto P_0c088a0a;
P_0c088a0a: /* original 8d08, guest PC 0x0c088a0a */
if(!s->budget--) { s->failed_pc=0x0c088a0au; return 0; }
cond=r[17]&1u;
r[4]=r[0];
if(cond) { goto P_0c088a1e; }
goto P_0c088a0e;
P_0c088a0c: /* original 6403, guest PC 0x0c088a0c */
if(!s->budget--) { s->failed_pc=0x0c088a0cu; return 0; }
r[4]=r[0];
goto P_0c088a0e;
P_0c088a0e: /* original 6043, guest PC 0x0c088a0e */
if(!s->budget--) { s->failed_pc=0x0c088a0eu; return 0; }
r[0]=r[4];
goto P_0c088a10;
P_0c088a10: /* original 880d, guest PC 0x0c088a10 */
if(!s->budget--) { s->failed_pc=0x0c088a10u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000du)!=0);
goto P_0c088a12;
P_0c088a12: /* original 8904, guest PC 0x0c088a12 */
if(!s->budget--) { s->failed_pc=0x0c088a12u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c088a1e; }
goto P_0c088a14;
P_0c088a14: /* original 6043, guest PC 0x0c088a14 */
if(!s->budget--) { s->failed_pc=0x0c088a14u; return 0; }
r[0]=r[4];
goto P_0c088a16;
P_0c088a16: /* original 880b, guest PC 0x0c088a16 */
if(!s->budget--) { s->failed_pc=0x0c088a16u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000bu)!=0);
goto P_0c088a18;
P_0c088a18: /* original 8901, guest PC 0x0c088a18 */
if(!s->budget--) { s->failed_pc=0x0c088a18u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c088a1e; }
goto P_0c088a1a;
P_0c088a1a: /* original a081, guest PC 0x0c088a1a */
if(!s->budget--) { s->failed_pc=0x0c088a1au; return 0; }
goto P_0c088b20;
P_0c088a1c: /* original 0009, guest PC 0x0c088a1c */
if(!s->budget--) { s->failed_pc=0x0c088a1cu; return 0; }
goto P_0c088a1e;
P_0c088a1e: /* original e30e, guest PC 0x0c088a1e */
if(!s->budget--) { s->failed_pc=0x0c088a1eu; return 0; }
r[3]=0x0000000eu;
goto P_0c088a20;
P_0c088a20: /* original 68c3, guest PC 0x0c088a20 */
if(!s->budget--) { s->failed_pc=0x0c088a20u; return 0; }
r[8]=r[12];
goto P_0c088a22;
P_0c088a22: /* original e048, guest PC 0x0c088a22 */
if(!s->budget--) { s->failed_pc=0x0c088a22u; return 0; }
r[0]=0x00000048u;
goto P_0c088a24;
P_0c088a24: /* original 1f33, guest PC 0x0c088a24 */
if(!s->budget--) { s->failed_pc=0x0c088a24u; return 0; }
write(ram,r[15]+12,r[3],4);
goto P_0c088a26;
P_0c088a26: /* original 54e4, guest PC 0x0c088a26 */
if(!s->budget--) { s->failed_pc=0x0c088a26u; return 0; }
r[4]=read(ram,r[14]+16,4);
goto P_0c088a28;
P_0c088a28: /* original ed01, guest PC 0x0c088a28 */
if(!s->budget--) { s->failed_pc=0x0c088a28u; return 0; }
r[13]=0x00000001u;
goto P_0c088a2a;
P_0c088a2a: /* original 7808, guest PC 0x0c088a2a */
if(!s->budget--) { s->failed_pc=0x0c088a2au; return 0; }
r[8]+=0x00000008u;
goto P_0c088a2c;
P_0c088a2c: /* original 034e, guest PC 0x0c088a2c */
if(!s->budget--) { s->failed_pc=0x0c088a2cu; return 0; }
r[3]=read(ram,r[4]+r[0],4);
goto P_0c088a2e;
P_0c088a2e: /* original e048, guest PC 0x0c088a2e */
if(!s->budget--) { s->failed_pc=0x0c088a2eu; return 0; }
r[0]=0x00000048u;
goto P_0c088a30;
P_0c088a30: /* original 1f35, guest PC 0x0c088a30 */
if(!s->budget--) { s->failed_pc=0x0c088a30u; return 0; }
write(ram,r[15]+20,r[3],4);
goto P_0c088a32;
P_0c088a32: /* original 6242, guest PC 0x0c088a32 */
if(!s->budget--) { s->failed_pc=0x0c088a32u; return 0; }
tmp=read(ram,r[4],4);
r[2]=tmp;
goto P_0c088a34;
P_0c088a34: /* original 1f26, guest PC 0x0c088a34 */
if(!s->budget--) { s->failed_pc=0x0c088a34u; return 0; }
write(ram,r[15]+24,r[2],4);
goto P_0c088a36;
P_0c088a36: /* original 54e5, guest PC 0x0c088a36 */
if(!s->budget--) { s->failed_pc=0x0c088a36u; return 0; }
r[4]=read(ram,r[14]+20,4);
goto P_0c088a38;
P_0c088a38: /* original 034e, guest PC 0x0c088a38 */
if(!s->budget--) { s->failed_pc=0x0c088a38u; return 0; }
r[3]=read(ram,r[4]+r[0],4);
goto P_0c088a3a;
P_0c088a3a: /* original 1f34, guest PC 0x0c088a3a */
if(!s->budget--) { s->failed_pc=0x0c088a3au; return 0; }
write(ram,r[15]+16,r[3],4);
goto P_0c088a3c;
P_0c088a3c: /* original 6242, guest PC 0x0c088a3c */
if(!s->budget--) { s->failed_pc=0x0c088a3cu; return 0; }
tmp=read(ram,r[4],4);
r[2]=tmp;
goto P_0c088a3e;
P_0c088a3e: /* original 1f27, guest PC 0x0c088a3e */
if(!s->budget--) { s->failed_pc=0x0c088a3eu; return 0; }
write(ram,r[15]+28,r[2],4);
goto P_0c088a40;
P_0c088a40: /* original d30c, guest PC 0x0c088a40 */
if(!s->budget--) { s->failed_pc=0x0c088a40u; return 0; }
r[3]=read(ram,0x0c088a74u,4);
goto P_0c088a42;
P_0c088a42: /* original 1f32, guest PC 0x0c088a42 */
if(!s->budget--) { s->failed_pc=0x0c088a42u; return 0; }
write(ram,r[15]+8,r[3],4);
goto P_0c088a44;
P_0c088a44: /* original 85c2, guest PC 0x0c088a44 */
if(!s->budget--) { s->failed_pc=0x0c088a44u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[12]+4,2);
goto P_0c088a46;
P_0c088a46: /* original 2f01, guest PC 0x0c088a46 */
if(!s->budget--) { s->failed_pc=0x0c088a46u; return 0; }
write(ram,r[15],r[0],2);
goto P_0c088a48;
P_0c088a48: /* original 85c3, guest PC 0x0c088a48 */
if(!s->budget--) { s->failed_pc=0x0c088a48u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[12]+6,2);
goto P_0c088a4a;
P_0c088a4a: /* original a057, guest PC 0x0c088a4a */
if(!s->budget--) { s->failed_pc=0x0c088a4au; return 0; }
write(ram,r[15]+4,r[0],2);
goto P_0c088afc;
P_0c088a4c: /* original 81f2, guest PC 0x0c088a4c */
if(!s->budget--) { s->failed_pc=0x0c088a4cu; return 0; }
write(ram,r[15]+4,r[0],2);
return vf3_matrix_family(0x0c088a4eu,s,ram);
P_0c088a78: /* original 51f2, guest PC 0x0c088a78 */
if(!s->budget--) { s->failed_pc=0x0c088a78u; return 0; }
r[1]=read(ram,r[15]+8,4);
goto P_0c088a7a;
P_0c088a7a: /* original 7104, guest PC 0x0c088a7a */
if(!s->budget--) { s->failed_pc=0x0c088a7au; return 0; }
r[1]+=0x00000004u;
goto P_0c088a7c;
P_0c088a7c: /* original 1f12, guest PC 0x0c088a7c */
if(!s->budget--) { s->failed_pc=0x0c088a7cu; return 0; }
write(ram,r[15]+8,r[1],4);
goto P_0c088a7e;
P_0c088a7e: /* original 71fc, guest PC 0x0c088a7e */
if(!s->budget--) { s->failed_pc=0x0c088a7eu; return 0; }
r[1]+=0xfffffffcu;
goto P_0c088a80;
P_0c088a80: /* original 53f2, guest PC 0x0c088a80 */
if(!s->budget--) { s->failed_pc=0x0c088a80u; return 0; }
r[3]=read(ram,r[15]+8,4);
goto P_0c088a82;
P_0c088a82: /* original fe18, guest PC 0x0c088a82 */
if(!s->budget--) { s->failed_pc=0x0c088a82u; return 0; }
vf3_matrix_load(s,ram,14,r[1]);
goto P_0c088a84;
P_0c088a84: /* original 7304, guest PC 0x0c088a84 */
if(!s->budget--) { s->failed_pc=0x0c088a84u; return 0; }
r[3]+=0x00000004u;
goto P_0c088a86;
P_0c088a86: /* original 6233, guest PC 0x0c088a86 */
if(!s->budget--) { s->failed_pc=0x0c088a86u; return 0; }
r[2]=r[3];
goto P_0c088a88;
P_0c088a88: /* original 7204, guest PC 0x0c088a88 */
if(!s->budget--) { s->failed_pc=0x0c088a88u; return 0; }
r[2]+=0x00000004u;
goto P_0c088a8a;
P_0c088a8a: /* original 1f22, guest PC 0x0c088a8a */
if(!s->budget--) { s->failed_pc=0x0c088a8au; return 0; }
write(ram,r[15]+8,r[2],4);
goto P_0c088a8c;
P_0c088a8c: /* original 72fc, guest PC 0x0c088a8c */
if(!s->budget--) { s->failed_pc=0x0c088a8cu; return 0; }
r[2]+=0xfffffffcu;
goto P_0c088a8e;
P_0c088a8e: /* original 53f5, guest PC 0x0c088a8e */
if(!s->budget--) { s->failed_pc=0x0c088a8eu; return 0; }
r[3]=read(ram,r[15]+20,4);
goto P_0c088a90;
P_0c088a90: /* original 9b52, guest PC 0x0c088a90 */
if(!s->budget--) { s->failed_pc=0x0c088a90u; return 0; }
r[11]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c088b38u,2);
goto P_0c088a92;
P_0c088a92: /* original da2b, guest PC 0x0c088a92 */
if(!s->budget--) { s->failed_pc=0x0c088a92u; return 0; }
r[10]=read(ram,0x0c088b40u,4);
goto P_0c088a94;
P_0c088a94: /* original ff28, guest PC 0x0c088a94 */
if(!s->budget--) { s->failed_pc=0x0c088a94u; return 0; }
vf3_matrix_load(s,ram,15,r[2]);
goto P_0c088a96;
P_0c088a96: /* original 23b8, guest PC 0x0c088a96 */
if(!s->budget--) { s->failed_pc=0x0c088a96u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[11])==0)!=0);
goto P_0c088a98;
P_0c088a98: /* original d928, guest PC 0x0c088a98 */
if(!s->budget--) { s->failed_pc=0x0c088a98u; return 0; }
r[9]=read(ram,0x0c088b3cu,4);
goto P_0c088a9a;
P_0c088a9a: /* original 8b02, guest PC 0x0c088a9a */
if(!s->budget--) { s->failed_pc=0x0c088a9au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c088aa2; }
goto P_0c088a9c;
P_0c088a9c: /* original 52f5, guest PC 0x0c088a9c */
if(!s->budget--) { s->failed_pc=0x0c088a9cu; return 0; }
r[2]=read(ram,r[15]+20,4);
goto P_0c088a9e;
P_0c088a9e: /* original 22a8, guest PC 0x0c088a9e */
if(!s->budget--) { s->failed_pc=0x0c088a9eu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[10])==0)!=0);
goto P_0c088aa0;
P_0c088aa0: /* original 8908, guest PC 0x0c088aa0 */
if(!s->budget--) { s->failed_pc=0x0c088aa0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c088ab4; }
goto P_0c088aa2;
P_0c088aa2: /* original 53f6, guest PC 0x0c088aa2 */
if(!s->budget--) { s->failed_pc=0x0c088aa2u; return 0; }
r[3]=read(ram,r[15]+24,4);
goto P_0c088aa4;
P_0c088aa4: /* original 2398, guest PC 0x0c088aa4 */
if(!s->budget--) { s->failed_pc=0x0c088aa4u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[9])==0)!=0);
goto P_0c088aa6;
P_0c088aa6: /* original 8905, guest PC 0x0c088aa6 */
if(!s->budget--) { s->failed_pc=0x0c088aa6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c088ab4; }
goto P_0c088aa8;
P_0c088aa8: /* original f5fc, guest PC 0x0c088aa8 */
if(!s->budget--) { s->failed_pc=0x0c088aa8u; return 0; }
vf3_matrix_move(s,5,15);
goto P_0c088aaa;
P_0c088aaa: /* original 66d3, guest PC 0x0c088aaa */
if(!s->budget--) { s->failed_pc=0x0c088aaau; return 0; }
r[6]=r[13];
goto P_0c088aac;
P_0c088aac: /* original f4ec, guest PC 0x0c088aac */
if(!s->budget--) { s->failed_pc=0x0c088aacu; return 0; }
vf3_matrix_move(s,4,14);
goto P_0c088aae;
P_0c088aae: /* original 65f3, guest PC 0x0c088aae */
if(!s->budget--) { s->failed_pc=0x0c088aaeu; return 0; }
r[5]=r[15];
goto P_0c088ab0;
P_0c088ab0: /* original bf62, guest PC 0x0c088ab0 */
if(!s->budget--) { s->failed_pc=0x0c088ab0u; return 0; }
target=0x0c088978u; r[16]=code_base|0x0c088ab4u;
r[4]=read(ram,r[14]+16,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c088ab4u) { target=s->pc; goto dispatch; }
goto P_0c088ab4;
P_0c088ab2: /* original 54e4, guest PC 0x0c088ab2 */
if(!s->budget--) { s->failed_pc=0x0c088ab2u; return 0; }
r[4]=read(ram,r[14]+16,4);
goto P_0c088ab4;
P_0c088ab4: /* original 52f4, guest PC 0x0c088ab4 */
if(!s->budget--) { s->failed_pc=0x0c088ab4u; return 0; }
r[2]=read(ram,r[15]+16,4);
goto P_0c088ab6;
P_0c088ab6: /* original 2b28, guest PC 0x0c088ab6 */
if(!s->budget--) { s->failed_pc=0x0c088ab6u; return 0; }
r[17]=(r[17]&~1u)|(((r[11]&r[2])==0)!=0);
goto P_0c088ab8;
P_0c088ab8: /* original 8b02, guest PC 0x0c088ab8 */
if(!s->budget--) { s->failed_pc=0x0c088ab8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c088ac0; }
goto P_0c088aba;
P_0c088aba: /* original 53f4, guest PC 0x0c088aba */
if(!s->budget--) { s->failed_pc=0x0c088abau; return 0; }
r[3]=read(ram,r[15]+16,4);
goto P_0c088abc;
P_0c088abc: /* original 2a38, guest PC 0x0c088abc */
if(!s->budget--) { s->failed_pc=0x0c088abcu; return 0; }
r[17]=(r[17]&~1u)|(((r[10]&r[3])==0)!=0);
goto P_0c088abe;
P_0c088abe: /* original 8908, guest PC 0x0c088abe */
if(!s->budget--) { s->failed_pc=0x0c088abeu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c088ad2; }
goto P_0c088ac0;
P_0c088ac0: /* original 52f7, guest PC 0x0c088ac0 */
if(!s->budget--) { s->failed_pc=0x0c088ac0u; return 0; }
r[2]=read(ram,r[15]+28,4);
goto P_0c088ac2;
P_0c088ac2: /* original 2928, guest PC 0x0c088ac2 */
if(!s->budget--) { s->failed_pc=0x0c088ac2u; return 0; }
r[17]=(r[17]&~1u)|(((r[9]&r[2])==0)!=0);
goto P_0c088ac4;
P_0c088ac4: /* original 8905, guest PC 0x0c088ac4 */
if(!s->budget--) { s->failed_pc=0x0c088ac4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c088ad2; }
goto P_0c088ac6;
P_0c088ac6: /* original f5fc, guest PC 0x0c088ac6 */
if(!s->budget--) { s->failed_pc=0x0c088ac6u; return 0; }
vf3_matrix_move(s,5,15);
goto P_0c088ac8;
P_0c088ac8: /* original 66d3, guest PC 0x0c088ac8 */
if(!s->budget--) { s->failed_pc=0x0c088ac8u; return 0; }
r[6]=r[13];
goto P_0c088aca;
P_0c088aca: /* original f4ec, guest PC 0x0c088aca */
if(!s->budget--) { s->failed_pc=0x0c088acau; return 0; }
vf3_matrix_move(s,4,14);
goto P_0c088acc;
P_0c088acc: /* original 65f3, guest PC 0x0c088acc */
if(!s->budget--) { s->failed_pc=0x0c088accu; return 0; }
r[5]=r[15];
goto P_0c088ace;
P_0c088ace: /* original bf53, guest PC 0x0c088ace */
if(!s->budget--) { s->failed_pc=0x0c088aceu; return 0; }
target=0x0c088978u; r[16]=code_base|0x0c088ad2u;
r[4]=read(ram,r[14]+20,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c088ad2u) { target=s->pc; goto dispatch; }
goto P_0c088ad2;
P_0c088ad0: /* original 54e5, guest PC 0x0c088ad0 */
if(!s->budget--) { s->failed_pc=0x0c088ad0u; return 0; }
r[4]=read(ram,r[14]+20,4);
goto P_0c088ad2;
P_0c088ad2: /* original 62f1, guest PC 0x0c088ad2 */
if(!s->budget--) { s->failed_pc=0x0c088ad2u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[15],2);
r[2]=tmp;
goto P_0c088ad4;
P_0c088ad4: /* original 63dd, guest PC 0x0c088ad4 */
if(!s->budget--) { s->failed_pc=0x0c088ad4u; return 0; }
r[3]=r[13]&65535u;
goto P_0c088ad6;
P_0c088ad6: /* original 622d, guest PC 0x0c088ad6 */
if(!s->budget--) { s->failed_pc=0x0c088ad6u; return 0; }
r[2]=r[2]&65535u;
goto P_0c088ad8;
P_0c088ad8: /* original 2238, guest PC 0x0c088ad8 */
if(!s->budget--) { s->failed_pc=0x0c088ad8u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c088ada;
P_0c088ada: /* original 8d0a, guest PC 0x0c088ada */
if(!s->budget--) { s->failed_pc=0x0c088adau; return 0; }
cond=r[17]&1u;
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[8],2);
r[4]=tmp;
if(cond) { goto P_0c088af2; }
goto P_0c088ade;
P_0c088adc: /* original 6481, guest PC 0x0c088adc */
if(!s->budget--) { s->failed_pc=0x0c088adcu; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[8],2);
r[4]=tmp;
goto P_0c088ade;
P_0c088ade: /* original 634f, guest PC 0x0c088ade */
if(!s->budget--) { s->failed_pc=0x0c088adeu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)r[4];
goto P_0c088ae0;
P_0c088ae0: /* original e510, guest PC 0x0c088ae0 */
if(!s->budget--) { s->failed_pc=0x0c088ae0u; return 0; }
r[5]=0x00000010u;
goto P_0c088ae2;
P_0c088ae2: /* original 3353, guest PC 0x0c088ae2 */
if(!s->budget--) { s->failed_pc=0x0c088ae2u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>=(int32_t)r[5])!=0);
goto P_0c088ae4;
P_0c088ae4: /* original 8902, guest PC 0x0c088ae4 */
if(!s->budget--) { s->failed_pc=0x0c088ae4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c088aec; }
goto P_0c088ae6;
P_0c088ae6: /* original 7401, guest PC 0x0c088ae6 */
if(!s->budget--) { s->failed_pc=0x0c088ae6u; return 0; }
r[4]+=0x00000001u;
goto P_0c088ae8;
P_0c088ae8: /* original a003, guest PC 0x0c088ae8 */
if(!s->budget--) { s->failed_pc=0x0c088ae8u; return 0; }
write(ram,r[8],r[4],2);
goto P_0c088af2;
P_0c088aea: /* original 2841, guest PC 0x0c088aea */
if(!s->budget--) { s->failed_pc=0x0c088aeau; return 0; }
write(ram,r[8],r[4],2);
goto P_0c088aec;
P_0c088aec: /* original 85f2, guest PC 0x0c088aec */
if(!s->budget--) { s->failed_pc=0x0c088aecu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+4,2);
goto P_0c088aee;
P_0c088aee: /* original 20db, guest PC 0x0c088aee */
if(!s->budget--) { s->failed_pc=0x0c088aeeu; return 0; }
r[0]|=r[13];
goto P_0c088af0;
P_0c088af0: /* original 81f2, guest PC 0x0c088af0 */
if(!s->budget--) { s->failed_pc=0x0c088af0u; return 0; }
write(ram,r[15]+4,r[0],2);
goto P_0c088af2;
P_0c088af2: /* original 53f3, guest PC 0x0c088af2 */
if(!s->budget--) { s->failed_pc=0x0c088af2u; return 0; }
r[3]=read(ram,r[15]+12,4);
goto P_0c088af4;
P_0c088af4: /* original 7804, guest PC 0x0c088af4 */
if(!s->budget--) { s->failed_pc=0x0c088af4u; return 0; }
r[8]+=0x00000004u;
goto P_0c088af6;
P_0c088af6: /* original 4d00, guest PC 0x0c088af6 */
if(!s->budget--) { s->failed_pc=0x0c088af6u; return 0; }
r[17]=(r[17]&~1u)|((r[13]>>31)!=0);
r[13]<<=1;
goto P_0c088af8;
P_0c088af8: /* original 73ff, guest PC 0x0c088af8 */
if(!s->budget--) { s->failed_pc=0x0c088af8u; return 0; }
r[3]+=0xffffffffu;
goto P_0c088afa;
P_0c088afa: /* original 1f33, guest PC 0x0c088afa */
if(!s->budget--) { s->failed_pc=0x0c088afau; return 0; }
write(ram,r[15]+12,r[3],4);
goto P_0c088afc;
P_0c088afc: /* original 52f3, guest PC 0x0c088afc */
if(!s->budget--) { s->failed_pc=0x0c088afcu; return 0; }
r[2]=read(ram,r[15]+12,4);
goto P_0c088afe;
P_0c088afe: /* original 2228, guest PC 0x0c088afe */
if(!s->budget--) { s->failed_pc=0x0c088afeu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c088b00;
P_0c088b00: /* original 8bba, guest PC 0x0c088b00 */
if(!s->budget--) { s->failed_pc=0x0c088b00u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c088a78; }
goto P_0c088b02;
P_0c088b02: /* original 60f1, guest PC 0x0c088b02 */
if(!s->budget--) { s->failed_pc=0x0c088b02u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[15],2);
r[0]=tmp;
goto P_0c088b04;
P_0c088b04: /* original 81c2, guest PC 0x0c088b04 */
if(!s->budget--) { s->failed_pc=0x0c088b04u; return 0; }
write(ram,r[12]+4,r[0],2);
goto P_0c088b06;
P_0c088b06: /* original 85f2, guest PC 0x0c088b06 */
if(!s->budget--) { s->failed_pc=0x0c088b06u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+4,2);
goto P_0c088b08;
P_0c088b08: /* original 81c3, guest PC 0x0c088b08 */
if(!s->budget--) { s->failed_pc=0x0c088b08u; return 0; }
write(ram,r[12]+6,r[0],2);
goto P_0c088b0a;
P_0c088b0a: /* original e050, guest PC 0x0c088b0a */
if(!s->budget--) { s->failed_pc=0x0c088b0au; return 0; }
r[0]=0x00000050u;
goto P_0c088b0c;
P_0c088b0c: /* original bf2b, guest PC 0x0c088b0c */
if(!s->budget--) { s->failed_pc=0x0c088b0cu; return 0; }
target=0x0c088966u; r[16]=code_base|0x0c088b10u;
r[4]=read(ram,r[14]+r[0],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c088b10u) { target=s->pc; goto dispatch; }
goto P_0c088b10;
P_0c088b0e: /* original 04ee, guest PC 0x0c088b0e */
if(!s->budget--) { s->failed_pc=0x0c088b0eu; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c088b10;
P_0c088b10: /* original 62f1, guest PC 0x0c088b10 */
if(!s->budget--) { s->failed_pc=0x0c088b10u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[15],2);
r[2]=tmp;
goto P_0c088b12;
P_0c088b12: /* original 6403, guest PC 0x0c088b12 */
if(!s->budget--) { s->failed_pc=0x0c088b12u; return 0; }
r[4]=r[0];
goto P_0c088b14;
P_0c088b14: /* original e034, guest PC 0x0c088b14 */
if(!s->budget--) { s->failed_pc=0x0c088b14u; return 0; }
r[0]=0x00000034u;
goto P_0c088b16;
P_0c088b16: /* original 0425, guest PC 0x0c088b16 */
if(!s->budget--) { s->failed_pc=0x0c088b16u; return 0; }
write(ram,r[4]+r[0],r[2],2);
goto P_0c088b18;
P_0c088b18: /* original e136, guest PC 0x0c088b18 */
if(!s->budget--) { s->failed_pc=0x0c088b18u; return 0; }
r[1]=0x00000036u;
goto P_0c088b1a;
P_0c088b1a: /* original 85f2, guest PC 0x0c088b1a */
if(!s->budget--) { s->failed_pc=0x0c088b1au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+4,2);
goto P_0c088b1c;
P_0c088b1c: /* original 314c, guest PC 0x0c088b1c */
if(!s->budget--) { s->failed_pc=0x0c088b1cu; return 0; }
r[1]+=r[4];
goto P_0c088b1e;
P_0c088b1e: /* original 2101, guest PC 0x0c088b1e */
if(!s->budget--) { s->failed_pc=0x0c088b1eu; return 0; }
write(ram,r[1],r[0],2);
goto P_0c088b20;
P_0c088b20: /* original 7f20, guest PC 0x0c088b20 */
if(!s->budget--) { s->failed_pc=0x0c088b20u; return 0; }
r[15]+=0x00000020u;
goto P_0c088b22;
P_0c088b22: /* original 4f26, guest PC 0x0c088b22 */
if(!s->budget--) { s->failed_pc=0x0c088b22u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c088b24;
P_0c088b24: /* original fef9, guest PC 0x0c088b24 */
if(!s->budget--) { s->failed_pc=0x0c088b24u; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c088b26;
P_0c088b26: /* original fff9, guest PC 0x0c088b26 */
if(!s->budget--) { s->failed_pc=0x0c088b26u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c088b28;
P_0c088b28: /* original 68f6, guest PC 0x0c088b28 */
if(!s->budget--) { s->failed_pc=0x0c088b28u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c088b2a;
P_0c088b2a: /* original 69f6, guest PC 0x0c088b2a */
if(!s->budget--) { s->failed_pc=0x0c088b2au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c088b2c;
P_0c088b2c: /* original 6af6, guest PC 0x0c088b2c */
if(!s->budget--) { s->failed_pc=0x0c088b2cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c088b2e;
P_0c088b2e: /* original 6bf6, guest PC 0x0c088b2e */
if(!s->budget--) { s->failed_pc=0x0c088b2eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c088b30;
P_0c088b30: /* original 6cf6, guest PC 0x0c088b30 */
if(!s->budget--) { s->failed_pc=0x0c088b30u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c088b32;
P_0c088b32: /* original 6df6, guest PC 0x0c088b32 */
if(!s->budget--) { s->failed_pc=0x0c088b32u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c088b34;
P_0c088b34: /* original 000b, guest PC 0x0c088b34 */
if(!s->budget--) { s->failed_pc=0x0c088b34u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c088b36: /* original 6ef6, guest PC 0x0c088b36 */
if(!s->budget--) { s->failed_pc=0x0c088b36u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c088b38u,s,ram);
P_0c0c72e2: /* original 4f22, guest PC 0x0c0c72e2 */
if(!s->budget--) { s->failed_pc=0x0c0c72e2u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0c72e4;
P_0c0c72e4: /* original de26, guest PC 0x0c0c72e4 */
if(!s->budget--) { s->failed_pc=0x0c0c72e4u; return 0; }
r[14]=read(ram,0x0c0c7380u,4);
goto P_0c0c72e6;
P_0c0c72e6: /* original dc27, guest PC 0x0c0c72e6 */
if(!s->budget--) { s->failed_pc=0x0c0c72e6u; return 0; }
r[12]=read(ram,0x0c0c7384u,4);
goto P_0c0c72e8;
P_0c0c72e8: /* original 4f12, guest PC 0x0c0c72e8 */
if(!s->budget--) { s->failed_pc=0x0c0c72e8u; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c0c72ea;
P_0c0c72ea: /* original 0bec, guest PC 0x0c0c72ea */
if(!s->budget--) { s->failed_pc=0x0c0c72eau; return 0; }
r[11]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0c72ec;
P_0c0c72ec: /* original e02b, guest PC 0x0c0c72ec */
if(!s->budget--) { s->failed_pc=0x0c0c72ecu; return 0; }
r[0]=0x0000002bu;
goto P_0c0c72ee;
P_0c0c72ee: /* original 03ec, guest PC 0x0c0c72ee */
if(!s->budget--) { s->failed_pc=0x0c0c72eeu; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0c72f0;
P_0c0c72f0: /* original 6bbc, guest PC 0x0c0c72f0 */
if(!s->budget--) { s->failed_pc=0x0c0c72f0u; return 0; }
r[11]=r[11]&255u;
goto P_0c0c72f2;
P_0c0c72f2: /* original 60b3, guest PC 0x0c0c72f2 */
if(!s->budget--) { s->failed_pc=0x0c0c72f2u; return 0; }
r[0]=r[11];
goto P_0c0c72f4;
P_0c0c72f4: /* original 7ff8, guest PC 0x0c0c72f4 */
if(!s->budget--) { s->failed_pc=0x0c0c72f4u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c0c72f6;
P_0c0c72f6: /* original 8803, guest PC 0x0c0c72f6 */
if(!s->budget--) { s->failed_pc=0x0c0c72f6u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000003u)!=0);
goto P_0c0c72f8;
P_0c0c72f8: /* original 2f32, guest PC 0x0c0c72f8 */
if(!s->budget--) { s->failed_pc=0x0c0c72f8u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c0c72fa;
P_0c0c72fa: /* original da23, guest PC 0x0c0c72fa */
if(!s->budget--) { s->failed_pc=0x0c0c72fau; return 0; }
r[10]=read(ram,0x0c0c7388u,4);
goto P_0c0c72fc;
P_0c0c72fc: /* original 8b01, guest PC 0x0c0c72fc */
if(!s->budget--) { s->failed_pc=0x0c0c72fcu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c7302; }
goto P_0c0c72fe;
P_0c0c72fe: /* original a0a8, guest PC 0x0c0c72fe */
if(!s->budget--) { s->failed_pc=0x0c0c72feu; return 0; }
goto P_0c0c7452;
P_0c0c7300: /* original 0009, guest PC 0x0c0c7300 */
if(!s->budget--) { s->failed_pc=0x0c0c7300u; return 0; }
goto P_0c0c7302;
P_0c0c7302: /* original 64c3, guest PC 0x0c0c7302 */
if(!s->budget--) { s->failed_pc=0x0c0c7302u; return 0; }
r[4]=r[12];
goto P_0c0c7304;
P_0c0c7304: /* original 4a0b, guest PC 0x0c0c7304 */
if(!s->budget--) { s->failed_pc=0x0c0c7304u; return 0; }
target=r[10];
r[16]=code_base|0x0c0c7308u;
r[4]+=0x00000001u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c7308u) { target=s->pc; goto dispatch; }
goto P_0c0c7308;
P_0c0c7306: /* original 7401, guest PC 0x0c0c7306 */
if(!s->budget--) { s->failed_pc=0x0c0c7306u; return 0; }
r[4]+=0x00000001u;
goto P_0c0c7308;
P_0c0c7308: /* original e904, guest PC 0x0c0c7308 */
if(!s->budget--) { s->failed_pc=0x0c0c7308u; return 0; }
r[9]=0x00000004u;
goto P_0c0c730a;
P_0c0c730a: /* original 640c, guest PC 0x0c0c730a */
if(!s->budget--) { s->failed_pc=0x0c0c730au; return 0; }
r[4]=r[0]&255u;
goto P_0c0c730c;
P_0c0c730c: /* original 1e4f, guest PC 0x0c0c730c */
if(!s->budget--) { s->failed_pc=0x0c0c730cu; return 0; }
write(ram,r[14]+60,r[4],4);
goto P_0c0c730e;
P_0c0c730e: /* original 53e2, guest PC 0x0c0c730e */
if(!s->budget--) { s->failed_pc=0x0c0c730eu; return 0; }
r[3]=read(ram,r[14]+8,4);
goto P_0c0c7310;
P_0c0c7310: /* original 2398, guest PC 0x0c0c7310 */
if(!s->budget--) { s->failed_pc=0x0c0c7310u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[9])==0)!=0);
goto P_0c0c7312;
P_0c0c7312: /* original 8904, guest PC 0x0c0c7312 */
if(!s->budget--) { s->failed_pc=0x0c0c7312u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c731e; }
goto P_0c0c7314;
P_0c0c7314: /* original 64c3, guest PC 0x0c0c7314 */
if(!s->budget--) { s->failed_pc=0x0c0c7314u; return 0; }
r[4]=r[12];
goto P_0c0c7316;
P_0c0c7316: /* original 4a0b, guest PC 0x0c0c7316 */
if(!s->budget--) { s->failed_pc=0x0c0c7316u; return 0; }
target=r[10];
r[16]=code_base|0x0c0c731au;
r[4]+=0x00000001u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c731au) { target=s->pc; goto dispatch; }
goto P_0c0c731a;
P_0c0c7318: /* original 7401, guest PC 0x0c0c7318 */
if(!s->budget--) { s->failed_pc=0x0c0c7318u; return 0; }
r[4]+=0x00000001u;
goto P_0c0c731a;
P_0c0c731a: /* original 640c, guest PC 0x0c0c731a */
if(!s->budget--) { s->failed_pc=0x0c0c731au; return 0; }
r[4]=r[0]&255u;
goto P_0c0c731c;
P_0c0c731c: /* original 1e4f, guest PC 0x0c0c731c */
if(!s->budget--) { s->failed_pc=0x0c0c731cu; return 0; }
write(ram,r[14]+60,r[4],4);
goto P_0c0c731e;
P_0c0c731e: /* original 942d, guest PC 0x0c0c731e */
if(!s->budget--) { s->failed_pc=0x0c0c731eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c737cu,2);
goto P_0c0c7320;
P_0c0c7320: /* original 63f2, guest PC 0x0c0c7320 */
if(!s->budget--) { s->failed_pc=0x0c0c7320u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c0c7322;
P_0c0c7322: /* original 34ec, guest PC 0x0c0c7322 */
if(!s->budget--) { s->failed_pc=0x0c0c7322u; return 0; }
r[4]+=r[14];
goto P_0c0c7324;
P_0c0c7324: /* original dd19, guest PC 0x0c0c7324 */
if(!s->budget--) { s->failed_pc=0x0c0c7324u; return 0; }
r[13]=read(ram,0x0c0c738cu,4);
goto P_0c0c7326;
P_0c0c7326: /* original 74ff, guest PC 0x0c0c7326 */
if(!s->budget--) { s->failed_pc=0x0c0c7326u; return 0; }
r[4]+=0xffffffffu;
goto P_0c0c7328;
P_0c0c7328: /* original d719, guest PC 0x0c0c7328 */
if(!s->budget--) { s->failed_pc=0x0c0c7328u; return 0; }
r[7]=read(ram,0x0c0c7390u,4);
goto P_0c0c732a;
P_0c0c732a: /* original 343c, guest PC 0x0c0c732a */
if(!s->budget--) { s->failed_pc=0x0c0c732au; return 0; }
r[4]+=r[3];
goto P_0c0c732c;
P_0c0c732c: /* original 63b3, guest PC 0x0c0c732c */
if(!s->budget--) { s->failed_pc=0x0c0c732cu; return 0; }
r[3]=r[11];
goto P_0c0c732e;
P_0c0c732e: /* original 6440, guest PC 0x0c0c732e */
if(!s->budget--) { s->failed_pc=0x0c0c732eu; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[4],1);
r[4]=tmp;
goto P_0c0c7330;
P_0c0c7330: /* original 73fe, guest PC 0x0c0c7330 */
if(!s->budget--) { s->failed_pc=0x0c0c7330u; return 0; }
r[3]+=0xfffffffeu;
goto P_0c0c7332;
P_0c0c7332: /* original 7bff, guest PC 0x0c0c7332 */
if(!s->budget--) { s->failed_pc=0x0c0c7332u; return 0; }
r[11]+=0xffffffffu;
goto P_0c0c7334;
P_0c0c7334: /* original 644c, guest PC 0x0c0c7334 */
if(!s->budget--) { s->failed_pc=0x0c0c7334u; return 0; }
r[4]=r[4]&255u;
goto P_0c0c7336;
P_0c0c7336: /* original 6643, guest PC 0x0c0c7336 */
if(!s->budget--) { s->failed_pc=0x0c0c7336u; return 0; }
r[6]=r[4];
goto P_0c0c7338;
P_0c0c7338: /* original 4600, guest PC 0x0c0c7338 */
if(!s->budget--) { s->failed_pc=0x0c0c7338u; return 0; }
r[17]=(r[17]&~1u)|((r[6]>>31)!=0);
r[6]<<=1;
goto P_0c0c733a;
P_0c0c733a: /* original 3d6c, guest PC 0x0c0c733a */
if(!s->budget--) { s->failed_pc=0x0c0c733au; return 0; }
r[13]+=r[6];
goto P_0c0c733c;
P_0c0c733c: /* original 6dd0, guest PC 0x0c0c733c */
if(!s->budget--) { s->failed_pc=0x0c0c733cu; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[13],1);
r[13]=tmp;
goto P_0c0c733e;
P_0c0c733e: /* original 2732, guest PC 0x0c0c733e */
if(!s->budget--) { s->failed_pc=0x0c0c733eu; return 0; }
write(ram,r[7],r[3],4);
goto P_0c0c7340;
P_0c0c7340: /* original 6ddc, guest PC 0x0c0c7340 */
if(!s->budget--) { s->failed_pc=0x0c0c7340u; return 0; }
r[13]=r[13]&255u;
goto P_0c0c7342;
P_0c0c7342: /* original 2fb2, guest PC 0x0c0c7342 */
if(!s->budget--) { s->failed_pc=0x0c0c7342u; return 0; }
write(ram,r[15],r[11],4);
goto P_0c0c7344;
P_0c0c7344: /* original 17b1, guest PC 0x0c0c7344 */
if(!s->budget--) { s->failed_pc=0x0c0c7344u; return 0; }
write(ram,r[7]+4,r[11],4);
goto P_0c0c7346;
P_0c0c7346: /* original d613, guest PC 0x0c0c7346 */
if(!s->budget--) { s->failed_pc=0x0c0c7346u; return 0; }
r[6]=read(ram,0x0c0c7394u,4);
goto P_0c0c7348;
P_0c0c7348: /* original 6372, guest PC 0x0c0c7348 */
if(!s->budget--) { s->failed_pc=0x0c0c7348u; return 0; }
tmp=read(ram,r[7],4);
r[3]=tmp;
goto P_0c0c734a;
P_0c0c734a: /* original 5565, guest PC 0x0c0c734a */
if(!s->budget--) { s->failed_pc=0x0c0c734au; return 0; }
r[5]=read(ram,r[6]+20,4);
goto P_0c0c734c;
P_0c0c734c: /* original 5664, guest PC 0x0c0c734c */
if(!s->budget--) { s->failed_pc=0x0c0c734cu; return 0; }
r[6]=read(ram,r[6]+16,4);
goto P_0c0c734e;
P_0c0c734e: /* original 2338, guest PC 0x0c0c734e */
if(!s->budget--) { s->failed_pc=0x0c0c734eu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0c7350;
P_0c0c7350: /* original 8d22, guest PC 0x0c0c7350 */
if(!s->budget--) { s->failed_pc=0x0c0c7350u; return 0; }
cond=r[17]&1u;
r[12]=r[4];
if(cond) { goto P_0c0c7398; }
goto P_0c0c7354;
P_0c0c7352: /* original 6c43, guest PC 0x0c0c7352 */
if(!s->budget--) { s->failed_pc=0x0c0c7352u; return 0; }
r[12]=r[4];
goto P_0c0c7354;
P_0c0c7354: /* original 1f51, guest PC 0x0c0c7354 */
if(!s->budget--) { s->failed_pc=0x0c0c7354u; return 0; }
write(ram,r[15]+4,r[5],4);
goto P_0c0c7356;
P_0c0c7356: /* original e060, guest PC 0x0c0c7356 */
if(!s->budget--) { s->failed_pc=0x0c0c7356u; return 0; }
r[0]=0x00000060u;
goto P_0c0c7358;
P_0c0c7358: /* original 6563, guest PC 0x0c0c7358 */
if(!s->budget--) { s->failed_pc=0x0c0c7358u; return 0; }
r[5]=r[6];
goto P_0c0c735a;
P_0c0c735a: /* original 0b5c, guest PC 0x0c0c735a */
if(!s->budget--) { s->failed_pc=0x0c0c735au; return 0; }
r[11]=(uint32_t)(int32_t)(int8_t)read(ram,r[5]+r[0],1);
goto P_0c0c735c;
P_0c0c735c: /* original e30d, guest PC 0x0c0c735c */
if(!s->budget--) { s->failed_pc=0x0c0c735cu; return 0; }
r[3]=0x0000000du;
goto P_0c0c735e;
P_0c0c735e: /* original 56f1, guest PC 0x0c0c735e */
if(!s->budget--) { s->failed_pc=0x0c0c735eu; return 0; }
r[6]=read(ram,r[15]+4,4);
goto P_0c0c7360;
P_0c0c7360: /* original 6bbc, guest PC 0x0c0c7360 */
if(!s->budget--) { s->failed_pc=0x0c0c7360u; return 0; }
r[11]=r[11]&255u;
goto P_0c0c7362;
P_0c0c7362: /* original 3b32, guest PC 0x0c0c7362 */
if(!s->budget--) { s->failed_pc=0x0c0c7362u; return 0; }
r[17]=(r[17]&~1u)|((r[11]>=r[3])!=0);
goto P_0c0c7364;
P_0c0c7364: /* original 8900, guest PC 0x0c0c7364 */
if(!s->budget--) { s->failed_pc=0x0c0c7364u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c7368; }
goto P_0c0c7366;
P_0c0c7366: /* original 740d, guest PC 0x0c0c7366 */
if(!s->budget--) { s->failed_pc=0x0c0c7366u; return 0; }
r[4]+=0x0000000du;
goto P_0c0c7368;
P_0c0c7368: /* original 34b0, guest PC 0x0c0c7368 */
if(!s->budget--) { s->failed_pc=0x0c0c7368u; return 0; }
r[17]=(r[17]&~1u)|((r[4]==r[11])!=0);
goto P_0c0c736a;
P_0c0c736a: /* original 8b00, guest PC 0x0c0c736a */
if(!s->budget--) { s->failed_pc=0x0c0c736au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c736e; }
goto P_0c0c736c;
P_0c0c736c: /* original 74f3, guest PC 0x0c0c736c */
if(!s->budget--) { s->failed_pc=0x0c0c736cu; return 0; }
r[4]+=0xfffffff3u;
goto P_0c0c736e;
P_0c0c736e: /* original 5371, guest PC 0x0c0c736e */
if(!s->budget--) { s->failed_pc=0x0c0c736eu; return 0; }
r[3]=read(ram,r[7]+4,4);
goto P_0c0c7370;
P_0c0c7370: /* original 2338, guest PC 0x0c0c7370 */
if(!s->budget--) { s->failed_pc=0x0c0c7370u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0c7372;
P_0c0c7372: /* original 8901, guest PC 0x0c0c7372 */
if(!s->budget--) { s->failed_pc=0x0c0c7372u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c7378; }
goto P_0c0c7374;
P_0c0c7374: /* original a083, guest PC 0x0c0c7374 */
if(!s->budget--) { s->failed_pc=0x0c0c7374u; return 0; }
goto P_0c0c747e;
P_0c0c7376: /* original 0009, guest PC 0x0c0c7376 */
if(!s->budget--) { s->failed_pc=0x0c0c7376u; return 0; }
goto P_0c0c7378;
P_0c0c7378: /* original a018, guest PC 0x0c0c7378 */
if(!s->budget--) { s->failed_pc=0x0c0c7378u; return 0; }
goto P_0c0c73ac;
P_0c0c737a: /* original 0009, guest PC 0x0c0c737a */
if(!s->budget--) { s->failed_pc=0x0c0c737au; return 0; }
return vf3_matrix_family(0x0c0c737cu,s,ram);
P_0c0c7398: /* original e060, guest PC 0x0c0c7398 */
if(!s->budget--) { s->failed_pc=0x0c0c7398u; return 0; }
r[0]=0x00000060u;
goto P_0c0c739a;
P_0c0c739a: /* original 075c, guest PC 0x0c0c739a */
if(!s->budget--) { s->failed_pc=0x0c0c739au; return 0; }
r[7]=(uint32_t)(int32_t)(int8_t)read(ram,r[5]+r[0],1);
goto P_0c0c739c;
P_0c0c739c: /* original e30d, guest PC 0x0c0c739c */
if(!s->budget--) { s->failed_pc=0x0c0c739cu; return 0; }
r[3]=0x0000000du;
goto P_0c0c739e;
P_0c0c739e: /* original 677c, guest PC 0x0c0c739e */
if(!s->budget--) { s->failed_pc=0x0c0c739eu; return 0; }
r[7]=r[7]&255u;
goto P_0c0c73a0;
P_0c0c73a0: /* original 3732, guest PC 0x0c0c73a0 */
if(!s->budget--) { s->failed_pc=0x0c0c73a0u; return 0; }
r[17]=(r[17]&~1u)|((r[7]>=r[3])!=0);
goto P_0c0c73a2;
P_0c0c73a2: /* original 8900, guest PC 0x0c0c73a2 */
if(!s->budget--) { s->failed_pc=0x0c0c73a2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c73a6; }
goto P_0c0c73a4;
P_0c0c73a4: /* original 740d, guest PC 0x0c0c73a4 */
if(!s->budget--) { s->failed_pc=0x0c0c73a4u; return 0; }
r[4]+=0x0000000du;
goto P_0c0c73a6;
P_0c0c73a6: /* original 3470, guest PC 0x0c0c73a6 */
if(!s->budget--) { s->failed_pc=0x0c0c73a6u; return 0; }
r[17]=(r[17]&~1u)|((r[4]==r[7])!=0);
goto P_0c0c73a8;
P_0c0c73a8: /* original 8b00, guest PC 0x0c0c73a8 */
if(!s->budget--) { s->failed_pc=0x0c0c73a8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c73ac; }
goto P_0c0c73aa;
P_0c0c73aa: /* original 740d, guest PC 0x0c0c73aa */
if(!s->budget--) { s->failed_pc=0x0c0c73aau; return 0; }
r[4]+=0x0000000du;
goto P_0c0c73ac;
P_0c0c73ac: /* original e060, guest PC 0x0c0c73ac */
if(!s->budget--) { s->failed_pc=0x0c0c73acu; return 0; }
r[0]=0x00000060u;
goto P_0c0c73ae;
P_0c0c73ae: /* original 0644, guest PC 0x0c0c73ae */
if(!s->budget--) { s->failed_pc=0x0c0c73aeu; return 0; }
write(ram,r[6]+r[0],r[4],1);
goto P_0c0c73b0;
P_0c0c73b0: /* original e061, guest PC 0x0c0c73b0 */
if(!s->budget--) { s->failed_pc=0x0c0c73b0u; return 0; }
r[0]=0x00000061u;
goto P_0c0c73b2;
P_0c0c73b2: /* original 06c4, guest PC 0x0c0c73b2 */
if(!s->budget--) { s->failed_pc=0x0c0c73b2u; return 0; }
write(ram,r[6]+r[0],r[12],1);
goto P_0c0c73b4;
P_0c0c73b4: /* original 53e2, guest PC 0x0c0c73b4 */
if(!s->budget--) { s->failed_pc=0x0c0c73b4u; return 0; }
r[3]=read(ram,r[14]+8,4);
goto P_0c0c73b6;
P_0c0c73b6: /* original 2398, guest PC 0x0c0c73b6 */
if(!s->budget--) { s->failed_pc=0x0c0c73b6u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[9])==0)!=0);
goto P_0c0c73b8;
P_0c0c73b8: /* original 8d06, guest PC 0x0c0c73b8 */
if(!s->budget--) { s->failed_pc=0x0c0c73b8u; return 0; }
cond=r[17]&1u;
r[0]=r[12];
if(cond) { goto P_0c0c73c8; }
goto P_0c0c73bc;
P_0c0c73ba: /* original 60c3, guest PC 0x0c0c73ba */
if(!s->budget--) { s->failed_pc=0x0c0c73bau; return 0; }
r[0]=r[12];
goto P_0c0c73bc;
P_0c0c73bc: /* original 926a, guest PC 0x0c0c73bc */
if(!s->budget--) { s->failed_pc=0x0c0c73bcu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c7494u,2);
goto P_0c0c73be;
P_0c0c73be: /* original 32ec, guest PC 0x0c0c73be */
if(!s->budget--) { s->failed_pc=0x0c0c73beu; return 0; }
r[2]+=r[14];
goto P_0c0c73c0;
P_0c0c73c0: /* original 32cc, guest PC 0x0c0c73c0 */
if(!s->budget--) { s->failed_pc=0x0c0c73c0u; return 0; }
r[2]+=r[12];
goto P_0c0c73c2;
P_0c0c73c2: /* original 6320, guest PC 0x0c0c73c2 */
if(!s->budget--) { s->failed_pc=0x0c0c73c2u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[2],1);
r[3]=tmp;
goto P_0c0c73c4;
P_0c0c73c4: /* original 7301, guest PC 0x0c0c73c4 */
if(!s->budget--) { s->failed_pc=0x0c0c73c4u; return 0; }
r[3]+=0x00000001u;
goto P_0c0c73c6;
P_0c0c73c6: /* original 2230, guest PC 0x0c0c73c6 */
if(!s->budget--) { s->failed_pc=0x0c0c73c6u; return 0; }
write(ram,r[2],r[3],1);
goto P_0c0c73c8;
P_0c0c73c8: /* original 8809, guest PC 0x0c0c73c8 */
if(!s->budget--) { s->failed_pc=0x0c0c73c8u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000009u)!=0);
goto P_0c0c73ca;
P_0c0c73ca: /* original 8b58, guest PC 0x0c0c73ca */
if(!s->budget--) { s->failed_pc=0x0c0c73cau; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c747e; }
goto P_0c0c73cc;
P_0c0c73cc: /* original 9063, guest PC 0x0c0c73cc */
if(!s->budget--) { s->failed_pc=0x0c0c73ccu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c7496u,2);
goto P_0c0c73ce;
P_0c0c73ce: /* original e202, guest PC 0x0c0c73ce */
if(!s->budget--) { s->failed_pc=0x0c0c73ceu; return 0; }
r[2]=0x00000002u;
goto P_0c0c73d0;
P_0c0c73d0: /* original 0e24, guest PC 0x0c0c73d0 */
if(!s->budget--) { s->failed_pc=0x0c0c73d0u; return 0; }
write(ram,r[14]+r[0],r[2],1);
goto P_0c0c73d2;
P_0c0c73d2: /* original 53e2, guest PC 0x0c0c73d2 */
if(!s->budget--) { s->failed_pc=0x0c0c73d2u; return 0; }
r[3]=read(ram,r[14]+8,4);
goto P_0c0c73d4;
P_0c0c73d4: /* original 2938, guest PC 0x0c0c73d4 */
if(!s->budget--) { s->failed_pc=0x0c0c73d4u; return 0; }
r[17]=(r[17]&~1u)|(((r[9]&r[3])==0)!=0);
goto P_0c0c73d6;
P_0c0c73d6: /* original 892a, guest PC 0x0c0c73d6 */
if(!s->budget--) { s->failed_pc=0x0c0c73d6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c742e; }
goto P_0c0c73d8;
P_0c0c73d8: /* original 64f2, guest PC 0x0c0c73d8 */
if(!s->budget--) { s->failed_pc=0x0c0c73d8u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c0c73da;
P_0c0c73da: /* original 965d, guest PC 0x0c0c73da */
if(!s->budget--) { s->failed_pc=0x0c0c73dau; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c7498u,2);
goto P_0c0c73dc;
P_0c0c73dc: /* original 6343, guest PC 0x0c0c73dc */
if(!s->budget--) { s->failed_pc=0x0c0c73dcu; return 0; }
r[3]=r[4];
goto P_0c0c73de;
P_0c0c73de: /* original 905c, guest PC 0x0c0c73de */
if(!s->budget--) { s->failed_pc=0x0c0c73deu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c749au,2);
goto P_0c0c73e0;
P_0c0c73e0: /* original 4408, guest PC 0x0c0c73e0 */
if(!s->budget--) { s->failed_pc=0x0c0c73e0u; return 0; }
r[4]<<=2;
goto P_0c0c73e2;
P_0c0c73e2: /* original 343c, guest PC 0x0c0c73e2 */
if(!s->budget--) { s->failed_pc=0x0c0c73e2u; return 0; }
r[4]+=r[3];
goto P_0c0c73e4;
P_0c0c73e4: /* original 03ec, guest PC 0x0c0c73e4 */
if(!s->budget--) { s->failed_pc=0x0c0c73e4u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0c73e6;
P_0c0c73e6: /* original 36ec, guest PC 0x0c0c73e6 */
if(!s->budget--) { s->failed_pc=0x0c0c73e6u; return 0; }
r[6]+=r[14];
goto P_0c0c73e8;
P_0c0c73e8: /* original 364c, guest PC 0x0c0c73e8 */
if(!s->budget--) { s->failed_pc=0x0c0c73e8u; return 0; }
r[6]+=r[4];
goto P_0c0c73ea;
P_0c0c73ea: /* original 2f32, guest PC 0x0c0c73ea */
if(!s->budget--) { s->failed_pc=0x0c0c73eau; return 0; }
write(ram,r[15],r[3],4);
goto P_0c0c73ec;
P_0c0c73ec: /* original d72c, guest PC 0x0c0c73ec */
if(!s->budget--) { s->failed_pc=0x0c0c73ecu; return 0; }
r[7]=read(ram,0x0c0c74a0u,4);
goto P_0c0c73ee;
P_0c0c73ee: /* original ee0a, guest PC 0x0c0c73ee */
if(!s->budget--) { s->failed_pc=0x0c0c73eeu; return 0; }
r[14]=0x0000000au;
goto P_0c0c73f0;
P_0c0c73f0: /* original e400, guest PC 0x0c0c73f0 */
if(!s->budget--) { s->failed_pc=0x0c0c73f0u; return 0; }
r[4]=0x00000000u;
goto P_0c0c73f2;
P_0c0c73f2: /* original 6563, guest PC 0x0c0c73f2 */
if(!s->budget--) { s->failed_pc=0x0c0c73f2u; return 0; }
r[5]=r[6];
goto P_0c0c73f4;
P_0c0c73f4: /* original 354c, guest PC 0x0c0c73f4 */
if(!s->budget--) { s->failed_pc=0x0c0c73f4u; return 0; }
r[5]+=r[4];
goto P_0c0c73f6;
P_0c0c73f6: /* original 6550, guest PC 0x0c0c73f6 */
if(!s->budget--) { s->failed_pc=0x0c0c73f6u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[5],1);
r[5]=tmp;
goto P_0c0c73f8;
P_0c0c73f8: /* original 655c, guest PC 0x0c0c73f8 */
if(!s->budget--) { s->failed_pc=0x0c0c73f8u; return 0; }
r[5]=r[5]&255u;
goto P_0c0c73fa;
P_0c0c73fa: /* original 357c, guest PC 0x0c0c73fa */
if(!s->budget--) { s->failed_pc=0x0c0c73fau; return 0; }
r[5]+=r[7];
goto P_0c0c73fc;
P_0c0c73fc: /* original 6550, guest PC 0x0c0c73fc */
if(!s->budget--) { s->failed_pc=0x0c0c73fcu; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[5],1);
r[5]=tmp;
goto P_0c0c73fe;
P_0c0c73fe: /* original 655c, guest PC 0x0c0c73fe */
if(!s->budget--) { s->failed_pc=0x0c0c73feu; return 0; }
r[5]=r[5]&255u;
goto P_0c0c7400;
P_0c0c7400: /* original 3e56, guest PC 0x0c0c7400 */
if(!s->budget--) { s->failed_pc=0x0c0c7400u; return 0; }
r[17]=(r[17]&~1u)|((r[14]>r[5])!=0);
goto P_0c0c7402;
P_0c0c7402: /* original 8f01, guest PC 0x0c0c7402 */
if(!s->budget--) { s->failed_pc=0x0c0c7402u; return 0; }
cond=r[17]&1u;
r[4]+=0x00000001u;
if(!cond) { goto P_0c0c7408; }
goto P_0c0c7406;
P_0c0c7404: /* original 7401, guest PC 0x0c0c7404 */
if(!s->budget--) { s->failed_pc=0x0c0c7404u; return 0; }
r[4]+=0x00000001u;
goto P_0c0c7406;
P_0c0c7406: /* original 6e53, guest PC 0x0c0c7406 */
if(!s->budget--) { s->failed_pc=0x0c0c7406u; return 0; }
r[14]=r[5];
goto P_0c0c7408;
P_0c0c7408: /* original 63f2, guest PC 0x0c0c7408 */
if(!s->budget--) { s->failed_pc=0x0c0c7408u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c0c740a;
P_0c0c740a: /* original 3346, guest PC 0x0c0c740a */
if(!s->budget--) { s->failed_pc=0x0c0c740au; return 0; }
r[17]=(r[17]&~1u)|((r[3]>r[4])!=0);
goto P_0c0c740c;
P_0c0c740c: /* original 89f1, guest PC 0x0c0c740c */
if(!s->budget--) { s->failed_pc=0x0c0c740cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c73f2; }
goto P_0c0c740e;
P_0c0c740e: /* original d225, guest PC 0x0c0c740e */
if(!s->budget--) { s->failed_pc=0x0c0c740eu; return 0; }
r[2]=read(ram,0x0c0c74a4u,4);
goto P_0c0c7410;
P_0c0c7410: /* original 420b, guest PC 0x0c0c7410 */
if(!s->budget--) { s->failed_pc=0x0c0c7410u; return 0; }
target=r[2];
r[16]=code_base|0x0c0c7414u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c7414u) { target=s->pc; goto dispatch; }
goto P_0c0c7414;
P_0c0c7412: /* original 0009, guest PC 0x0c0c7412 */
if(!s->budget--) { s->failed_pc=0x0c0c7412u; return 0; }
goto P_0c0c7414;
P_0c0c7414: /* original d324, guest PC 0x0c0c7414 */
if(!s->budget--) { s->failed_pc=0x0c0c7414u; return 0; }
r[3]=read(ram,0x0c0c74a8u,4);
goto P_0c0c7416;
P_0c0c7416: /* original 6103, guest PC 0x0c0c7416 */
if(!s->budget--) { s->failed_pc=0x0c0c7416u; return 0; }
r[1]=r[0];
goto P_0c0c7418;
P_0c0c7418: /* original 6403, guest PC 0x0c0c7418 */
if(!s->budget--) { s->failed_pc=0x0c0c7418u; return 0; }
r[4]=r[0];
goto P_0c0c741a;
P_0c0c741a: /* original 430b, guest PC 0x0c0c741a */
if(!s->budget--) { s->failed_pc=0x0c0c741au; return 0; }
target=r[3];
r[16]=code_base|0x0c0c741eu;
r[0]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c741eu) { target=s->pc; goto dispatch; }
goto P_0c0c741e;
P_0c0c741c: /* original 60e3, guest PC 0x0c0c741c */
if(!s->budget--) { s->failed_pc=0x0c0c741cu; return 0; }
r[0]=r[14];
goto P_0c0c741e;
P_0c0c741e: /* original 6503, guest PC 0x0c0c741e */
if(!s->budget--) { s->failed_pc=0x0c0c741eu; return 0; }
r[5]=r[0];
goto P_0c0c7420;
P_0c0c7420: /* original 05e7, guest PC 0x0c0c7420 */
if(!s->budget--) { s->failed_pc=0x0c0c7420u; return 0; }
r[19]=r[5]*r[14];
goto P_0c0c7422;
P_0c0c7422: /* original 051a, guest PC 0x0c0c7422 */
if(!s->budget--) { s->failed_pc=0x0c0c7422u; return 0; }
r[5]=r[19];
goto P_0c0c7424;
P_0c0c7424: /* original 3458, guest PC 0x0c0c7424 */
if(!s->budget--) { s->failed_pc=0x0c0c7424u; return 0; }
r[4]-=r[5];
goto P_0c0c7426;
P_0c0c7426: /* original d521, guest PC 0x0c0c7426 */
if(!s->budget--) { s->failed_pc=0x0c0c7426u; return 0; }
r[5]=read(ram,0x0c0c74acu,4);
goto P_0c0c7428;
P_0c0c7428: /* original 6d43, guest PC 0x0c0c7428 */
if(!s->budget--) { s->failed_pc=0x0c0c7428u; return 0; }
r[13]=r[4];
goto P_0c0c742a;
P_0c0c742a: /* original a00f, guest PC 0x0c0c742a */
if(!s->budget--) { s->failed_pc=0x0c0c742au; return 0; }
r[13]+=r[5];
goto P_0c0c744c;
P_0c0c742c: /* original 3d5c, guest PC 0x0c0c742c */
if(!s->budget--) { s->failed_pc=0x0c0c742cu; return 0; }
r[13]+=r[5];
goto P_0c0c742e;
P_0c0c742e: /* original e060, guest PC 0x0c0c742e */
if(!s->budget--) { s->failed_pc=0x0c0c742eu; return 0; }
r[0]=0x00000060u;
goto P_0c0c7430;
P_0c0c7430: /* original d21c, guest PC 0x0c0c7430 */
if(!s->budget--) { s->failed_pc=0x0c0c7430u; return 0; }
r[2]=read(ram,0x0c0c74a4u,4);
goto P_0c0c7432;
P_0c0c7432: /* original 045c, guest PC 0x0c0c7432 */
if(!s->budget--) { s->failed_pc=0x0c0c7432u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[5]+r[0],1);
goto P_0c0c7434;
P_0c0c7434: /* original d51e, guest PC 0x0c0c7434 */
if(!s->budget--) { s->failed_pc=0x0c0c7434u; return 0; }
r[5]=read(ram,0x0c0c74b0u,4);
goto P_0c0c7436;
P_0c0c7436: /* original 644c, guest PC 0x0c0c7436 */
if(!s->budget--) { s->failed_pc=0x0c0c7436u; return 0; }
r[4]=r[4]&255u;
goto P_0c0c7438;
P_0c0c7438: /* original 4408, guest PC 0x0c0c7438 */
if(!s->budget--) { s->failed_pc=0x0c0c7438u; return 0; }
r[4]<<=2;
goto P_0c0c743a;
P_0c0c743a: /* original 354c, guest PC 0x0c0c743a */
if(!s->budget--) { s->failed_pc=0x0c0c743au; return 0; }
r[5]+=r[4];
goto P_0c0c743c;
P_0c0c743c: /* original 6352, guest PC 0x0c0c743c */
if(!s->budget--) { s->failed_pc=0x0c0c743cu; return 0; }
tmp=read(ram,r[5],4);
r[3]=tmp;
goto P_0c0c743e;
P_0c0c743e: /* original 420b, guest PC 0x0c0c743e */
if(!s->budget--) { s->failed_pc=0x0c0c743eu; return 0; }
target=r[2];
r[16]=code_base|0x0c0c7442u;
write(ram,r[15],r[3],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c7442u) { target=s->pc; goto dispatch; }
goto P_0c0c7442;
P_0c0c7440: /* original 2f32, guest PC 0x0c0c7440 */
if(!s->budget--) { s->failed_pc=0x0c0c7440u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c0c7442;
P_0c0c7442: /* original 6df2, guest PC 0x0c0c7442 */
if(!s->budget--) { s->failed_pc=0x0c0c7442u; return 0; }
tmp=read(ram,r[15],4);
r[13]=tmp;
goto P_0c0c7444;
P_0c0c7444: /* original e30f, guest PC 0x0c0c7444 */
if(!s->budget--) { s->failed_pc=0x0c0c7444u; return 0; }
r[3]=0x0000000fu;
goto P_0c0c7446;
P_0c0c7446: /* original 6403, guest PC 0x0c0c7446 */
if(!s->budget--) { s->failed_pc=0x0c0c7446u; return 0; }
r[4]=r[0];
goto P_0c0c7448;
P_0c0c7448: /* original 2439, guest PC 0x0c0c7448 */
if(!s->budget--) { s->failed_pc=0x0c0c7448u; return 0; }
r[4]&=r[3];
goto P_0c0c744a;
P_0c0c744a: /* original 3d4c, guest PC 0x0c0c744a */
if(!s->budget--) { s->failed_pc=0x0c0c744au; return 0; }
r[13]+=r[4];
goto P_0c0c744c;
P_0c0c744c: /* original 6dd0, guest PC 0x0c0c744c */
if(!s->budget--) { s->failed_pc=0x0c0c744cu; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[13],1);
r[13]=tmp;
goto P_0c0c744e;
P_0c0c744e: /* original a016, guest PC 0x0c0c744e */
if(!s->budget--) { s->failed_pc=0x0c0c744eu; return 0; }
r[13]=r[13]&255u;
goto P_0c0c747e;
P_0c0c7450: /* original 6ddc, guest PC 0x0c0c7450 */
if(!s->budget--) { s->failed_pc=0x0c0c7450u; return 0; }
r[13]=r[13]&255u;
goto P_0c0c7452;
P_0c0c7452: /* original 9023, guest PC 0x0c0c7452 */
if(!s->budget--) { s->failed_pc=0x0c0c7452u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c749cu,2);
goto P_0c0c7454;
P_0c0c7454: /* original ed0f, guest PC 0x0c0c7454 */
if(!s->budget--) { s->failed_pc=0x0c0c7454u; return 0; }
r[13]=0x0000000fu;
goto P_0c0c7456;
P_0c0c7456: /* original 04ee, guest PC 0x0c0c7456 */
if(!s->budget--) { s->failed_pc=0x0c0c7456u; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c0c7458;
P_0c0c7458: /* original 7401, guest PC 0x0c0c7458 */
if(!s->budget--) { s->failed_pc=0x0c0c7458u; return 0; }
r[4]+=0x00000001u;
goto P_0c0c745a;
P_0c0c745a: /* original 0e46, guest PC 0x0c0c745a */
if(!s->budget--) { s->failed_pc=0x0c0c745au; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c0c745c;
P_0c0c745c: /* original 2d49, guest PC 0x0c0c745c */
if(!s->budget--) { s->failed_pc=0x0c0c745cu; return 0; }
r[13]&=r[4];
goto P_0c0c745e;
P_0c0c745e: /* original d015, guest PC 0x0c0c745e */
if(!s->budget--) { s->failed_pc=0x0c0c745eu; return 0; }
r[0]=read(ram,0x0c0c74b4u,4);
goto P_0c0c7460;
P_0c0c7460: /* original 64c3, guest PC 0x0c0c7460 */
if(!s->budget--) { s->failed_pc=0x0c0c7460u; return 0; }
r[4]=r[12];
goto P_0c0c7462;
P_0c0c7462: /* original 0ddc, guest PC 0x0c0c7462 */
if(!s->budget--) { s->failed_pc=0x0c0c7462u; return 0; }
r[13]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+r[0],1);
goto P_0c0c7464;
P_0c0c7464: /* original 4a0b, guest PC 0x0c0c7464 */
if(!s->budget--) { s->failed_pc=0x0c0c7464u; return 0; }
target=r[10];
r[16]=code_base|0x0c0c7468u;
r[4]+=0x00000001u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c7468u) { target=s->pc; goto dispatch; }
goto P_0c0c7468;
P_0c0c7466: /* original 7401, guest PC 0x0c0c7466 */
if(!s->budget--) { s->failed_pc=0x0c0c7466u; return 0; }
r[4]+=0x00000001u;
goto P_0c0c7468;
P_0c0c7468: /* original 640c, guest PC 0x0c0c7468 */
if(!s->budget--) { s->failed_pc=0x0c0c7468u; return 0; }
r[4]=r[0]&255u;
goto P_0c0c746a;
P_0c0c746a: /* original 1e4f, guest PC 0x0c0c746a */
if(!s->budget--) { s->failed_pc=0x0c0c746au; return 0; }
write(ram,r[14]+60,r[4],4);
goto P_0c0c746c;
P_0c0c746c: /* original 64c3, guest PC 0x0c0c746c */
if(!s->budget--) { s->failed_pc=0x0c0c746cu; return 0; }
r[4]=r[12];
goto P_0c0c746e;
P_0c0c746e: /* original 4a0b, guest PC 0x0c0c746e */
if(!s->budget--) { s->failed_pc=0x0c0c746eu; return 0; }
target=r[10];
r[16]=code_base|0x0c0c7472u;
r[4]+=0x0000000fu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c7472u) { target=s->pc; goto dispatch; }
goto P_0c0c7472;
P_0c0c7470: /* original 740f, guest PC 0x0c0c7470 */
if(!s->budget--) { s->failed_pc=0x0c0c7470u; return 0; }
r[4]+=0x0000000fu;
goto P_0c0c7472;
P_0c0c7472: /* original 640c, guest PC 0x0c0c7472 */
if(!s->budget--) { s->failed_pc=0x0c0c7472u; return 0; }
r[4]=r[0]&255u;
goto P_0c0c7474;
P_0c0c7474: /* original 2448, guest PC 0x0c0c7474 */
if(!s->budget--) { s->failed_pc=0x0c0c7474u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c0c7476;
P_0c0c7476: /* original 8b02, guest PC 0x0c0c7476 */
if(!s->budget--) { s->failed_pc=0x0c0c7476u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c747e; }
goto P_0c0c7478;
P_0c0c7478: /* original 9011, guest PC 0x0c0c7478 */
if(!s->budget--) { s->failed_pc=0x0c0c7478u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c749eu,2);
goto P_0c0c747a;
P_0c0c747a: /* original 0dec, guest PC 0x0c0c747a */
if(!s->budget--) { s->failed_pc=0x0c0c747au; return 0; }
r[13]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0c747c;
P_0c0c747c: /* original 6ddc, guest PC 0x0c0c747c */
if(!s->budget--) { s->failed_pc=0x0c0c747cu; return 0; }
r[13]=r[13]&255u;
goto P_0c0c747e;
P_0c0c747e: /* original 7f08, guest PC 0x0c0c747e */
if(!s->budget--) { s->failed_pc=0x0c0c747eu; return 0; }
r[15]+=0x00000008u;
goto P_0c0c7480;
P_0c0c7480: /* original 60d3, guest PC 0x0c0c7480 */
if(!s->budget--) { s->failed_pc=0x0c0c7480u; return 0; }
r[0]=r[13];
goto P_0c0c7482;
P_0c0c7482: /* original 4f16, guest PC 0x0c0c7482 */
if(!s->budget--) { s->failed_pc=0x0c0c7482u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c7484;
P_0c0c7484: /* original 4f26, guest PC 0x0c0c7484 */
if(!s->budget--) { s->failed_pc=0x0c0c7484u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c7486;
P_0c0c7486: /* original 69f6, guest PC 0x0c0c7486 */
if(!s->budget--) { s->failed_pc=0x0c0c7486u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0c7488;
P_0c0c7488: /* original 6af6, guest PC 0x0c0c7488 */
if(!s->budget--) { s->failed_pc=0x0c0c7488u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0c748a;
P_0c0c748a: /* original 6bf6, guest PC 0x0c0c748a */
if(!s->budget--) { s->failed_pc=0x0c0c748au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0c748c;
P_0c0c748c: /* original 6cf6, guest PC 0x0c0c748c */
if(!s->budget--) { s->failed_pc=0x0c0c748cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0c748e;
P_0c0c748e: /* original 6df6, guest PC 0x0c0c748e */
if(!s->budget--) { s->failed_pc=0x0c0c748eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0c7490;
P_0c0c7490: /* original 000b, guest PC 0x0c0c7490 */
if(!s->budget--) { s->failed_pc=0x0c0c7490u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0c7492: /* original 6ef6, guest PC 0x0c0c7492 */
if(!s->budget--) { s->failed_pc=0x0c0c7492u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0c7494u,s,ram);
P_0c0c7802: /* original e01c, guest PC 0x0c0c7802 */
if(!s->budget--) { s->failed_pc=0x0c0c7802u; return 0; }
r[0]=0x0000001cu;
goto P_0c0c7804;
P_0c0c7804: /* original 2fe6, guest PC 0x0c0c7804 */
if(!s->budget--) { s->failed_pc=0x0c0c7804u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c7806;
P_0c0c7806: /* original 2fd6, guest PC 0x0c0c7806 */
if(!s->budget--) { s->failed_pc=0x0c0c7806u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c7808;
P_0c0c7808: /* original 2fc6, guest PC 0x0c0c7808 */
if(!s->budget--) { s->failed_pc=0x0c0c7808u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c780a;
P_0c0c780a: /* original 2fb6, guest PC 0x0c0c780a */
if(!s->budget--) { s->failed_pc=0x0c0c780au; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c780c;
P_0c0c780c: /* original 2fa6, guest PC 0x0c0c780c */
if(!s->budget--) { s->failed_pc=0x0c0c780cu; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c780e;
P_0c0c780e: /* original d419, guest PC 0x0c0c780e */
if(!s->budget--) { s->failed_pc=0x0c0c780eu; return 0; }
r[4]=read(ram,0x0c0c7874u,4);
goto P_0c0c7810;
P_0c0c7810: /* original 4f22, guest PC 0x0c0c7810 */
if(!s->budget--) { s->failed_pc=0x0c0c7810u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0c7812;
P_0c0c7812: /* original 004c, guest PC 0x0c0c7812 */
if(!s->budget--) { s->failed_pc=0x0c0c7812u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c0c7814;
P_0c0c7814: /* original e40f, guest PC 0x0c0c7814 */
if(!s->budget--) { s->failed_pc=0x0c0c7814u; return 0; }
r[4]=0x0000000fu;
goto P_0c0c7816;
P_0c0c7816: /* original 600c, guest PC 0x0c0c7816 */
if(!s->budget--) { s->failed_pc=0x0c0c7816u; return 0; }
r[0]=r[0]&255u;
goto P_0c0c7818;
P_0c0c7818: /* original 2409, guest PC 0x0c0c7818 */
if(!s->budget--) { s->failed_pc=0x0c0c7818u; return 0; }
r[4]&=r[0];
goto P_0c0c781a;
P_0c0c781a: /* original d017, guest PC 0x0c0c781a */
if(!s->budget--) { s->failed_pc=0x0c0c781au; return 0; }
r[0]=read(ram,0x0c0c7878u,4);
goto P_0c0c781c;
P_0c0c781c: /* original 6e43, guest PC 0x0c0c781c */
if(!s->budget--) { s->failed_pc=0x0c0c781cu; return 0; }
r[14]=r[4];
goto P_0c0c781e;
P_0c0c781e: /* original 4e08, guest PC 0x0c0c781e */
if(!s->budget--) { s->failed_pc=0x0c0c781eu; return 0; }
r[14]<<=2;
goto P_0c0c7820;
P_0c0c7820: /* original 0eee, guest PC 0x0c0c7820 */
if(!s->budget--) { s->failed_pc=0x0c0c7820u; return 0; }
r[14]=read(ram,r[14]+r[0],4);
goto P_0c0c7822;
P_0c0c7822: /* original 2ee8, guest PC 0x0c0c7822 */
if(!s->budget--) { s->failed_pc=0x0c0c7822u; return 0; }
r[17]=(r[17]&~1u)|(((r[14]&r[14])==0)!=0);
goto P_0c0c7824;
P_0c0c7824: /* original 8914, guest PC 0x0c0c7824 */
if(!s->budget--) { s->failed_pc=0x0c0c7824u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c7850; }
goto P_0c0c7826;
P_0c0c7826: /* original dc17, guest PC 0x0c0c7826 */
if(!s->budget--) { s->failed_pc=0x0c0c7826u; return 0; }
r[12]=read(ram,0x0c0c7884u,4);
goto P_0c0c7828;
P_0c0c7828: /* original db15, guest PC 0x0c0c7828 */
if(!s->budget--) { s->failed_pc=0x0c0c7828u; return 0; }
r[11]=read(ram,0x0c0c7880u,4);
goto P_0c0c782a;
P_0c0c782a: /* original da14, guest PC 0x0c0c782a */
if(!s->budget--) { s->failed_pc=0x0c0c782au; return 0; }
r[10]=read(ram,0x0c0c787cu,4);
goto P_0c0c782c;
P_0c0c782c: /* original a00d, guest PC 0x0c0c782c */
if(!s->budget--) { s->failed_pc=0x0c0c782cu; return 0; }
r[13]=0x00000001u;
goto P_0c0c784a;
P_0c0c782e: /* original ed01, guest PC 0x0c0c782e */
if(!s->budget--) { s->failed_pc=0x0c0c782eu; return 0; }
r[13]=0x00000001u;
goto P_0c0c7830;
P_0c0c7830: /* original 60e5, guest PC 0x0c0c7830 */
if(!s->budget--) { s->failed_pc=0x0c0c7830u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[14],2);
r[14]+=2;
r[0]=tmp;
goto P_0c0c7832;
P_0c0c7832: /* original 600d, guest PC 0x0c0c7832 */
if(!s->budget--) { s->failed_pc=0x0c0c7832u; return 0; }
r[0]=r[0]&65535u;
goto P_0c0c7834;
P_0c0c7834: /* original 4008, guest PC 0x0c0c7834 */
if(!s->budget--) { s->failed_pc=0x0c0c7834u; return 0; }
r[0]<<=2;
goto P_0c0c7836;
P_0c0c7836: /* original 04ce, guest PC 0x0c0c7836 */
if(!s->budget--) { s->failed_pc=0x0c0c7836u; return 0; }
r[4]=read(ram,r[12]+r[0],4);
goto P_0c0c7838;
P_0c0c7838: /* original 5341, guest PC 0x0c0c7838 */
if(!s->budget--) { s->failed_pc=0x0c0c7838u; return 0; }
r[3]=read(ram,r[4]+4,4);
goto P_0c0c783a;
P_0c0c783a: /* original 23d8, guest PC 0x0c0c783a */
if(!s->budget--) { s->failed_pc=0x0c0c783au; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[13])==0)!=0);
goto P_0c0c783c;
P_0c0c783c: /* original 8903, guest PC 0x0c0c783c */
if(!s->budget--) { s->failed_pc=0x0c0c783cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c7846; }
goto P_0c0c783e;
P_0c0c783e: /* original 4b0b, guest PC 0x0c0c783e */
if(!s->budget--) { s->failed_pc=0x0c0c783eu; return 0; }
target=r[11];
r[16]=code_base|0x0c0c7842u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c7842u) { target=s->pc; goto dispatch; }
goto P_0c0c7842;
P_0c0c7840: /* original 0009, guest PC 0x0c0c7840 */
if(!s->budget--) { s->failed_pc=0x0c0c7840u; return 0; }
goto P_0c0c7842;
P_0c0c7842: /* original a002, guest PC 0x0c0c7842 */
if(!s->budget--) { s->failed_pc=0x0c0c7842u; return 0; }
goto P_0c0c784a;
P_0c0c7844: /* original 0009, guest PC 0x0c0c7844 */
if(!s->budget--) { s->failed_pc=0x0c0c7844u; return 0; }
goto P_0c0c7846;
P_0c0c7846: /* original 4a0b, guest PC 0x0c0c7846 */
if(!s->budget--) { s->failed_pc=0x0c0c7846u; return 0; }
target=r[10];
r[16]=code_base|0x0c0c784au;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c784au) { target=s->pc; goto dispatch; }
goto P_0c0c784a;
P_0c0c7848: /* original 0009, guest PC 0x0c0c7848 */
if(!s->budget--) { s->failed_pc=0x0c0c7848u; return 0; }
goto P_0c0c784a;
P_0c0c784a: /* original 62e1, guest PC 0x0c0c784a */
if(!s->budget--) { s->failed_pc=0x0c0c784au; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[14],2);
r[2]=tmp;
goto P_0c0c784c;
P_0c0c784c: /* original 2228, guest PC 0x0c0c784c */
if(!s->budget--) { s->failed_pc=0x0c0c784cu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c0c784e;
P_0c0c784e: /* original 8bef, guest PC 0x0c0c784e */
if(!s->budget--) { s->failed_pc=0x0c0c784eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c7830; }
goto P_0c0c7850;
P_0c0c7850: /* original 4f26, guest PC 0x0c0c7850 */
if(!s->budget--) { s->failed_pc=0x0c0c7850u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c7852;
P_0c0c7852: /* original 6af6, guest PC 0x0c0c7852 */
if(!s->budget--) { s->failed_pc=0x0c0c7852u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0c7854;
P_0c0c7854: /* original 6bf6, guest PC 0x0c0c7854 */
if(!s->budget--) { s->failed_pc=0x0c0c7854u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0c7856;
P_0c0c7856: /* original 6cf6, guest PC 0x0c0c7856 */
if(!s->budget--) { s->failed_pc=0x0c0c7856u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0c7858;
P_0c0c7858: /* original 6df6, guest PC 0x0c0c7858 */
if(!s->budget--) { s->failed_pc=0x0c0c7858u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0c785a;
P_0c0c785a: /* original 000b, guest PC 0x0c0c785a */
if(!s->budget--) { s->failed_pc=0x0c0c785au; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0c785c: /* original 6ef6, guest PC 0x0c0c785c */
if(!s->budget--) { s->failed_pc=0x0c0c785cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0c785eu,s,ram);
P_0c0c7a88: /* original 4f22, guest PC 0x0c0c7a88 */
if(!s->budget--) { s->failed_pc=0x0c0c7a88u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0c7a8a;
P_0c0c7a8a: /* original 00ec, guest PC 0x0c0c7a8a */
if(!s->budget--) { s->failed_pc=0x0c0c7a8au; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0c7a8c;
P_0c0c7a8c: /* original dc33, guest PC 0x0c0c7a8c */
if(!s->budget--) { s->failed_pc=0x0c0c7a8cu; return 0; }
r[12]=read(ram,0x0c0c7b5cu,4);
goto P_0c0c7a8e;
P_0c0c7a8e: /* original 600c, guest PC 0x0c0c7a8e */
if(!s->budget--) { s->failed_pc=0x0c0c7a8eu; return 0; }
r[0]=r[0]&255u;
goto P_0c0c7a90;
P_0c0c7a90: /* original d52f, guest PC 0x0c0c7a90 */
if(!s->budget--) { s->failed_pc=0x0c0c7a90u; return 0; }
r[5]=read(ram,0x0c0c7b50u,4);
goto P_0c0c7a92;
P_0c0c7a92: /* original 2d09, guest PC 0x0c0c7a92 */
if(!s->budget--) { s->failed_pc=0x0c0c7a92u; return 0; }
r[13]&=r[0];
goto P_0c0c7a94;
P_0c0c7a94: /* original d032, guest PC 0x0c0c7a94 */
if(!s->budget--) { s->failed_pc=0x0c0c7a94u; return 0; }
r[0]=read(ram,0x0c0c7b60u,4);
goto P_0c0c7a96;
P_0c0c7a96: /* original 69d3, guest PC 0x0c0c7a96 */
if(!s->budget--) { s->failed_pc=0x0c0c7a96u; return 0; }
r[9]=r[13];
goto P_0c0c7a98;
P_0c0c7a98: /* original 4908, guest PC 0x0c0c7a98 */
if(!s->budget--) { s->failed_pc=0x0c0c7a98u; return 0; }
r[9]<<=2;
goto P_0c0c7a9a;
P_0c0c7a9a: /* original 039e, guest PC 0x0c0c7a9a */
if(!s->budget--) { s->failed_pc=0x0c0c7a9au; return 0; }
r[3]=read(ram,r[9]+r[0],4);
goto P_0c0c7a9c;
P_0c0c7a9c: /* original 7ffc, guest PC 0x0c0c7a9c */
if(!s->budget--) { s->failed_pc=0x0c0c7a9cu; return 0; }
r[15]+=0xfffffffcu;
goto P_0c0c7a9e;
P_0c0c7a9e: /* original d42d, guest PC 0x0c0c7a9e */
if(!s->budget--) { s->failed_pc=0x0c0c7a9eu; return 0; }
r[4]=read(ram,0x0c0c7b54u,4);
goto P_0c0c7aa0;
P_0c0c7aa0: /* original db2d, guest PC 0x0c0c7aa0 */
if(!s->budget--) { s->failed_pc=0x0c0c7aa0u; return 0; }
r[11]=read(ram,0x0c0c7b58u,4);
goto P_0c0c7aa2;
P_0c0c7aa2: /* original 4315, guest PC 0x0c0c7aa2 */
if(!s->budget--) { s->failed_pc=0x0c0c7aa2u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>0)!=0);
goto P_0c0c7aa4;
P_0c0c7aa4: /* original 8f12, guest PC 0x0c0c7aa4 */
if(!s->budget--) { s->failed_pc=0x0c0c7aa4u; return 0; }
cond=r[17]&1u;
r[10]=0x00000000u;
if(!cond) { goto P_0c0c7acc; }
goto P_0c0c7aa8;
P_0c0c7aa6: /* original ea00, guest PC 0x0c0c7aa6 */
if(!s->budget--) { s->failed_pc=0x0c0c7aa6u; return 0; }
r[10]=0x00000000u;
goto P_0c0c7aa8;
P_0c0c7aa8: /* original 9042, guest PC 0x0c0c7aa8 */
if(!s->budget--) { s->failed_pc=0x0c0c7aa8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c7b30u,2);
goto P_0c0c7aaa;
P_0c0c7aaa: /* original 04a6, guest PC 0x0c0c7aaa */
if(!s->budget--) { s->failed_pc=0x0c0c7aaau; return 0; }
write(ram,r[4]+r[0],r[10],4);
goto P_0c0c7aac;
P_0c0c7aac: /* original 25a2, guest PC 0x0c0c7aac */
if(!s->budget--) { s->failed_pc=0x0c0c7aacu; return 0; }
write(ram,r[5],r[10],4);
goto P_0c0c7aae;
P_0c0c7aae: /* original 9340, guest PC 0x0c0c7aae */
if(!s->budget--) { s->failed_pc=0x0c0c7aaeu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c7b32u,2);
goto P_0c0c7ab0;
P_0c0c7ab0: /* original 2f36, guest PC 0x0c0c7ab0 */
if(!s->budget--) { s->failed_pc=0x0c0c7ab0u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c7ab2;
P_0c0c7ab2: /* original 2fb6, guest PC 0x0c0c7ab2 */
if(!s->budget--) { s->failed_pc=0x0c0c7ab2u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c7ab4;
P_0c0c7ab4: /* original 2fd6, guest PC 0x0c0c7ab4 */
if(!s->budget--) { s->failed_pc=0x0c0c7ab4u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c7ab6;
P_0c0c7ab6: /* original d22c, guest PC 0x0c0c7ab6 */
if(!s->budget--) { s->failed_pc=0x0c0c7ab6u; return 0; }
r[2]=read(ram,0x0c0c7b68u,4);
goto P_0c0c7ab8;
P_0c0c7ab8: /* original 963c, guest PC 0x0c0c7ab8 */
if(!s->budget--) { s->failed_pc=0x0c0c7ab8u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c7b34u,2);
goto P_0c0c7aba;
P_0c0c7aba: /* original 6522, guest PC 0x0c0c7aba */
if(!s->budget--) { s->failed_pc=0x0c0c7abau; return 0; }
tmp=read(ram,r[2],4);
r[5]=tmp;
goto P_0c0c7abc;
P_0c0c7abc: /* original 36ec, guest PC 0x0c0c7abc */
if(!s->budget--) { s->failed_pc=0x0c0c7abcu; return 0; }
r[6]+=r[14];
goto P_0c0c7abe;
P_0c0c7abe: /* original d028, guest PC 0x0c0c7abe */
if(!s->budget--) { s->failed_pc=0x0c0c7abeu; return 0; }
r[0]=read(ram,0x0c0c7b60u,4);
goto P_0c0c7ac0;
P_0c0c7ac0: /* original d728, guest PC 0x0c0c7ac0 */
if(!s->budget--) { s->failed_pc=0x0c0c7ac0u; return 0; }
r[7]=read(ram,0x0c0c7b64u,4);
goto P_0c0c7ac2;
P_0c0c7ac2: /* original 7608, guest PC 0x0c0c7ac2 */
if(!s->budget--) { s->failed_pc=0x0c0c7ac2u; return 0; }
r[6]+=0x00000008u;
goto P_0c0c7ac4;
P_0c0c7ac4: /* original 4c0b, guest PC 0x0c0c7ac4 */
if(!s->budget--) { s->failed_pc=0x0c0c7ac4u; return 0; }
target=r[12];
r[16]=code_base|0x0c0c7ac8u;
r[4]=read(ram,r[9]+r[0],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c7ac8u) { target=s->pc; goto dispatch; }
goto P_0c0c7ac8;
P_0c0c7ac6: /* original 049e, guest PC 0x0c0c7ac6 */
if(!s->budget--) { s->failed_pc=0x0c0c7ac6u; return 0; }
r[4]=read(ram,r[9]+r[0],4);
goto P_0c0c7ac8;
P_0c0c7ac8: /* original a003, guest PC 0x0c0c7ac8 */
if(!s->budget--) { s->failed_pc=0x0c0c7ac8u; return 0; }
r[15]+=0x0000000cu;
goto P_0c0c7ad2;
P_0c0c7aca: /* original 7f0c, guest PC 0x0c0c7aca */
if(!s->budget--) { s->failed_pc=0x0c0c7acau; return 0; }
r[15]+=0x0000000cu;
goto P_0c0c7acc;
P_0c0c7acc: /* original 9030, guest PC 0x0c0c7acc */
if(!s->budget--) { s->failed_pc=0x0c0c7accu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c7b30u,2);
goto P_0c0c7ace;
P_0c0c7ace: /* original 04a6, guest PC 0x0c0c7ace */
if(!s->budget--) { s->failed_pc=0x0c0c7aceu; return 0; }
write(ram,r[4]+r[0],r[10],4);
goto P_0c0c7ad0;
P_0c0c7ad0: /* original 25a2, guest PC 0x0c0c7ad0 */
if(!s->budget--) { s->failed_pc=0x0c0c7ad0u; return 0; }
write(ram,r[5],r[10],4);
goto P_0c0c7ad2;
P_0c0c7ad2: /* original 69d3, guest PC 0x0c0c7ad2 */
if(!s->budget--) { s->failed_pc=0x0c0c7ad2u; return 0; }
r[9]=r[13];
goto P_0c0c7ad4;
P_0c0c7ad4: /* original 4908, guest PC 0x0c0c7ad4 */
if(!s->budget--) { s->failed_pc=0x0c0c7ad4u; return 0; }
r[9]<<=2;
goto P_0c0c7ad6;
P_0c0c7ad6: /* original d026, guest PC 0x0c0c7ad6 */
if(!s->budget--) { s->failed_pc=0x0c0c7ad6u; return 0; }
r[0]=read(ram,0x0c0c7b70u,4);
goto P_0c0c7ad8;
P_0c0c7ad8: /* original 4900, guest PC 0x0c0c7ad8 */
if(!s->budget--) { s->failed_pc=0x0c0c7ad8u; return 0; }
r[17]=(r[17]&~1u)|((r[9]>>31)!=0);
r[9]<<=1;
goto P_0c0c7ada;
P_0c0c7ada: /* original d424, guest PC 0x0c0c7ada */
if(!s->budget--) { s->failed_pc=0x0c0c7adau; return 0; }
r[4]=read(ram,0x0c0c7b6cu,4);
goto P_0c0c7adc;
P_0c0c7adc: /* original 009e, guest PC 0x0c0c7adc */
if(!s->budget--) { s->failed_pc=0x0c0c7adcu; return 0; }
r[0]=read(ram,r[9]+r[0],4);
goto P_0c0c7ade;
P_0c0c7ade: /* original d819, guest PC 0x0c0c7ade */
if(!s->budget--) { s->failed_pc=0x0c0c7adeu; return 0; }
r[8]=read(ram,0x0c0c7b44u,4);
goto P_0c0c7ae0;
P_0c0c7ae0: /* original 88ff, guest PC 0x0c0c7ae0 */
if(!s->budget--) { s->failed_pc=0x0c0c7ae0u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c0c7ae2;
P_0c0c7ae2: /* original 8949, guest PC 0x0c0c7ae2 */
if(!s->budget--) { s->failed_pc=0x0c0c7ae2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c7b78; }
goto P_0c0c7ae4;
P_0c0c7ae4: /* original 9027, guest PC 0x0c0c7ae4 */
if(!s->budget--) { s->failed_pc=0x0c0c7ae4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c7b36u,2);
goto P_0c0c7ae6;
P_0c0c7ae6: /* original e700, guest PC 0x0c0c7ae6 */
if(!s->budget--) { s->failed_pc=0x0c0c7ae6u; return 0; }
r[7]=0x00000000u;
goto P_0c0c7ae8;
P_0c0c7ae8: /* original 6242, guest PC 0x0c0c7ae8 */
if(!s->budget--) { s->failed_pc=0x0c0c7ae8u; return 0; }
tmp=read(ram,r[4],4);
r[2]=tmp;
goto P_0c0c7aea;
P_0c0c7aea: /* original 0e26, guest PC 0x0c0c7aea */
if(!s->budget--) { s->failed_pc=0x0c0c7aeau; return 0; }
write(ram,r[14]+r[0],r[2],4);
goto P_0c0c7aec;
P_0c0c7aec: /* original 70fc, guest PC 0x0c0c7aec */
if(!s->budget--) { s->failed_pc=0x0c0c7aecu; return 0; }
r[0]+=0xfffffffcu;
goto P_0c0c7aee;
P_0c0c7aee: /* original 0ea6, guest PC 0x0c0c7aee */
if(!s->budget--) { s->failed_pc=0x0c0c7aeeu; return 0; }
write(ram,r[14]+r[0],r[10],4);
goto P_0c0c7af0;
P_0c0c7af0: /* original 7004, guest PC 0x0c0c7af0 */
if(!s->budget--) { s->failed_pc=0x0c0c7af0u; return 0; }
r[0]+=0x00000004u;
goto P_0c0c7af2;
P_0c0c7af2: /* original 9321, guest PC 0x0c0c7af2 */
if(!s->budget--) { s->failed_pc=0x0c0c7af2u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c7b38u,2);
goto P_0c0c7af4;
P_0c0c7af4: /* original 2f36, guest PC 0x0c0c7af4 */
if(!s->budget--) { s->failed_pc=0x0c0c7af4u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c7af6;
P_0c0c7af6: /* original 2fb6, guest PC 0x0c0c7af6 */
if(!s->budget--) { s->failed_pc=0x0c0c7af6u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c7af8;
P_0c0c7af8: /* original 2fd6, guest PC 0x0c0c7af8 */
if(!s->budget--) { s->failed_pc=0x0c0c7af8u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c7afa;
P_0c0c7afa: /* original d41d, guest PC 0x0c0c7afa */
if(!s->budget--) { s->failed_pc=0x0c0c7afau; return 0; }
r[4]=read(ram,0x0c0c7b70u,4);
goto P_0c0c7afc;
P_0c0c7afc: /* original 961a, guest PC 0x0c0c7afc */
if(!s->budget--) { s->failed_pc=0x0c0c7afcu; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c7b34u,2);
goto P_0c0c7afe;
P_0c0c7afe: /* original 349c, guest PC 0x0c0c7afe */
if(!s->budget--) { s->failed_pc=0x0c0c7afeu; return 0; }
r[4]+=r[9];
goto P_0c0c7b00;
P_0c0c7b00: /* original 05ee, guest PC 0x0c0c7b00 */
if(!s->budget--) { s->failed_pc=0x0c0c7b00u; return 0; }
r[5]=read(ram,r[14]+r[0],4);
goto P_0c0c7b02;
P_0c0c7b02: /* original 36ec, guest PC 0x0c0c7b02 */
if(!s->budget--) { s->failed_pc=0x0c0c7b02u; return 0; }
r[6]+=r[14];
goto P_0c0c7b04;
P_0c0c7b04: /* original 1f43, guest PC 0x0c0c7b04 */
if(!s->budget--) { s->failed_pc=0x0c0c7b04u; return 0; }
write(ram,r[15]+12,r[4],4);
goto P_0c0c7b06;
P_0c0c7b06: /* original 7608, guest PC 0x0c0c7b06 */
if(!s->budget--) { s->failed_pc=0x0c0c7b06u; return 0; }
r[6]+=0x00000008u;
goto P_0c0c7b08;
P_0c0c7b08: /* original 4c0b, guest PC 0x0c0c7b08 */
if(!s->budget--) { s->failed_pc=0x0c0c7b08u; return 0; }
target=r[12];
r[16]=code_base|0x0c0c7b0cu;
tmp=read(ram,r[4],4);
r[4]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c7b0cu) { target=s->pc; goto dispatch; }
goto P_0c0c7b0c;
P_0c0c7b0a: /* original 6442, guest PC 0x0c0c7b0a */
if(!s->budget--) { s->failed_pc=0x0c0c7b0au; return 0; }
tmp=read(ram,r[4],4);
r[4]=tmp;
goto P_0c0c7b0c;
P_0c0c7b0c: /* original 9315, guest PC 0x0c0c7b0c */
if(!s->budget--) { s->failed_pc=0x0c0c7b0cu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c7b3au,2);
goto P_0c0c7b0e;
P_0c0c7b0e: /* original 2f36, guest PC 0x0c0c7b0e */
if(!s->budget--) { s->failed_pc=0x0c0c7b0eu; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c7b10;
P_0c0c7b10: /* original 2fb6, guest PC 0x0c0c7b10 */
if(!s->budget--) { s->failed_pc=0x0c0c7b10u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c7b12;
P_0c0c7b12: /* original 2fd6, guest PC 0x0c0c7b12 */
if(!s->budget--) { s->failed_pc=0x0c0c7b12u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c7b14;
P_0c0c7b14: /* original 960e, guest PC 0x0c0c7b14 */
if(!s->budget--) { s->failed_pc=0x0c0c7b14u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c7b34u,2);
goto P_0c0c7b16;
P_0c0c7b16: /* original 6582, guest PC 0x0c0c7b16 */
if(!s->budget--) { s->failed_pc=0x0c0c7b16u; return 0; }
tmp=read(ram,r[8],4);
r[5]=tmp;
goto P_0c0c7b18;
P_0c0c7b18: /* original 52f6, guest PC 0x0c0c7b18 */
if(!s->budget--) { s->failed_pc=0x0c0c7b18u; return 0; }
r[2]=read(ram,r[15]+24,4);
goto P_0c0c7b1a;
P_0c0c7b1a: /* original 36ec, guest PC 0x0c0c7b1a */
if(!s->budget--) { s->failed_pc=0x0c0c7b1au; return 0; }
r[6]+=r[14];
goto P_0c0c7b1c;
P_0c0c7b1c: /* original d715, guest PC 0x0c0c7b1c */
if(!s->budget--) { s->failed_pc=0x0c0c7b1cu; return 0; }
r[7]=read(ram,0x0c0c7b74u,4);
goto P_0c0c7b1e;
P_0c0c7b1e: /* original 7608, guest PC 0x0c0c7b1e */
if(!s->budget--) { s->failed_pc=0x0c0c7b1eu; return 0; }
r[6]+=0x00000008u;
goto P_0c0c7b20;
P_0c0c7b20: /* original 4c0b, guest PC 0x0c0c7b20 */
if(!s->budget--) { s->failed_pc=0x0c0c7b20u; return 0; }
target=r[12];
r[16]=code_base|0x0c0c7b24u;
r[4]=read(ram,r[2]+4,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c7b24u) { target=s->pc; goto dispatch; }
goto P_0c0c7b24;
P_0c0c7b22: /* original 5421, guest PC 0x0c0c7b22 */
if(!s->budget--) { s->failed_pc=0x0c0c7b22u; return 0; }
r[4]=read(ram,r[2]+4,4);
goto P_0c0c7b24;
P_0c0c7b24: /* original a07c, guest PC 0x0c0c7b24 */
if(!s->budget--) { s->failed_pc=0x0c0c7b24u; return 0; }
r[15]+=0x00000018u;
goto P_0c0c7c20;
P_0c0c7b26: /* original 7f18, guest PC 0x0c0c7b26 */
if(!s->budget--) { s->failed_pc=0x0c0c7b26u; return 0; }
r[15]+=0x00000018u;
return vf3_matrix_family(0x0c0c7b28u,s,ram);
P_0c0c7b78: /* original d033, guest PC 0x0c0c7b78 */
if(!s->budget--) { s->failed_pc=0x0c0c7b78u; return 0; }
r[0]=read(ram,0x0c0c7c48u,4);
goto P_0c0c7b7a;
P_0c0c7b7a: /* original 009e, guest PC 0x0c0c7b7a */
if(!s->budget--) { s->failed_pc=0x0c0c7b7au; return 0; }
r[0]=read(ram,r[9]+r[0],4);
goto P_0c0c7b7c;
P_0c0c7b7c: /* original 88ff, guest PC 0x0c0c7b7c */
if(!s->budget--) { s->failed_pc=0x0c0c7b7cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c0c7b7e;
P_0c0c7b7e: /* original 893e, guest PC 0x0c0c7b7e */
if(!s->budget--) { s->failed_pc=0x0c0c7b7eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c7bfe; }
goto P_0c0c7b80;
P_0c0c7b80: /* original 9058, guest PC 0x0c0c7b80 */
if(!s->budget--) { s->failed_pc=0x0c0c7b80u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c7c34u,2);
goto P_0c0c7b82;
P_0c0c7b82: /* original 0ea6, guest PC 0x0c0c7b82 */
if(!s->budget--) { s->failed_pc=0x0c0c7b82u; return 0; }
write(ram,r[14]+r[0],r[10],4);
goto P_0c0c7b84;
P_0c0c7b84: /* original 70fc, guest PC 0x0c0c7b84 */
if(!s->budget--) { s->failed_pc=0x0c0c7b84u; return 0; }
r[0]+=0xfffffffcu;
goto P_0c0c7b86;
P_0c0c7b86: /* original 6342, guest PC 0x0c0c7b86 */
if(!s->budget--) { s->failed_pc=0x0c0c7b86u; return 0; }
tmp=read(ram,r[4],4);
r[3]=tmp;
goto P_0c0c7b88;
P_0c0c7b88: /* original 0e36, guest PC 0x0c0c7b88 */
if(!s->budget--) { s->failed_pc=0x0c0c7b88u; return 0; }
write(ram,r[14]+r[0],r[3],4);
goto P_0c0c7b8a;
P_0c0c7b8a: /* original e01c, guest PC 0x0c0c7b8a */
if(!s->budget--) { s->failed_pc=0x0c0c7b8au; return 0; }
r[0]=0x0000001cu;
goto P_0c0c7b8c;
P_0c0c7b8c: /* original 00ec, guest PC 0x0c0c7b8c */
if(!s->budget--) { s->failed_pc=0x0c0c7b8cu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0c7b8e;
P_0c0c7b8e: /* original 600c, guest PC 0x0c0c7b8e */
if(!s->budget--) { s->failed_pc=0x0c0c7b8eu; return 0; }
r[0]=r[0]&255u;
goto P_0c0c7b90;
P_0c0c7b90: /* original 8812, guest PC 0x0c0c7b90 */
if(!s->budget--) { s->failed_pc=0x0c0c7b90u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000012u)!=0);
goto P_0c0c7b92;
P_0c0c7b92: /* original 8b16, guest PC 0x0c0c7b92 */
if(!s->budget--) { s->failed_pc=0x0c0c7b92u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c7bc2; }
goto P_0c0c7b94;
P_0c0c7b94: /* original 924f, guest PC 0x0c0c7b94 */
if(!s->budget--) { s->failed_pc=0x0c0c7b94u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c7c36u,2);
goto P_0c0c7b96;
P_0c0c7b96: /* original e700, guest PC 0x0c0c7b96 */
if(!s->budget--) { s->failed_pc=0x0c0c7b96u; return 0; }
r[7]=0x00000000u;
goto P_0c0c7b98;
P_0c0c7b98: /* original 2f26, guest PC 0x0c0c7b98 */
if(!s->budget--) { s->failed_pc=0x0c0c7b98u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c7b9a;
P_0c0c7b9a: /* original 2fb6, guest PC 0x0c0c7b9a */
if(!s->budget--) { s->failed_pc=0x0c0c7b9au; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c7b9c;
P_0c0c7b9c: /* original 2fd6, guest PC 0x0c0c7b9c */
if(!s->budget--) { s->failed_pc=0x0c0c7b9cu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c7b9e;
P_0c0c7b9e: /* original 964b, guest PC 0x0c0c7b9e */
if(!s->budget--) { s->failed_pc=0x0c0c7b9eu; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c7c38u,2);
goto P_0c0c7ba0;
P_0c0c7ba0: /* original 904b, guest PC 0x0c0c7ba0 */
if(!s->budget--) { s->failed_pc=0x0c0c7ba0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c7c3au,2);
goto P_0c0c7ba2;
P_0c0c7ba2: /* original 36ec, guest PC 0x0c0c7ba2 */
if(!s->budget--) { s->failed_pc=0x0c0c7ba2u; return 0; }
r[6]+=r[14];
goto P_0c0c7ba4;
P_0c0c7ba4: /* original 944a, guest PC 0x0c0c7ba4 */
if(!s->budget--) { s->failed_pc=0x0c0c7ba4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c7c3cu,2);
goto P_0c0c7ba6;
P_0c0c7ba6: /* original 7608, guest PC 0x0c0c7ba6 */
if(!s->budget--) { s->failed_pc=0x0c0c7ba6u; return 0; }
r[6]+=0x00000008u;
goto P_0c0c7ba8;
P_0c0c7ba8: /* original 4c0b, guest PC 0x0c0c7ba8 */
if(!s->budget--) { s->failed_pc=0x0c0c7ba8u; return 0; }
target=r[12];
r[16]=code_base|0x0c0c7bacu;
r[5]=read(ram,r[14]+r[0],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c7bacu) { target=s->pc; goto dispatch; }
goto P_0c0c7bac;
P_0c0c7baa: /* original 05ee, guest PC 0x0c0c7baa */
if(!s->budget--) { s->failed_pc=0x0c0c7baau; return 0; }
r[5]=read(ram,r[14]+r[0],4);
goto P_0c0c7bac;
P_0c0c7bac: /* original 9347, guest PC 0x0c0c7bac */
if(!s->budget--) { s->failed_pc=0x0c0c7bacu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c7c3eu,2);
goto P_0c0c7bae;
P_0c0c7bae: /* original 2f36, guest PC 0x0c0c7bae */
if(!s->budget--) { s->failed_pc=0x0c0c7baeu; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c7bb0;
P_0c0c7bb0: /* original 2fb6, guest PC 0x0c0c7bb0 */
if(!s->budget--) { s->failed_pc=0x0c0c7bb0u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c7bb2;
P_0c0c7bb2: /* original 2fd6, guest PC 0x0c0c7bb2 */
if(!s->budget--) { s->failed_pc=0x0c0c7bb2u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c7bb4;
P_0c0c7bb4: /* original 9640, guest PC 0x0c0c7bb4 */
if(!s->budget--) { s->failed_pc=0x0c0c7bb4u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c7c38u,2);
goto P_0c0c7bb6;
P_0c0c7bb6: /* original 9443, guest PC 0x0c0c7bb6 */
if(!s->budget--) { s->failed_pc=0x0c0c7bb6u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c7c40u,2);
goto P_0c0c7bb8;
P_0c0c7bb8: /* original 36ec, guest PC 0x0c0c7bb8 */
if(!s->budget--) { s->failed_pc=0x0c0c7bb8u; return 0; }
r[6]+=r[14];
goto P_0c0c7bba;
P_0c0c7bba: /* original d724, guest PC 0x0c0c7bba */
if(!s->budget--) { s->failed_pc=0x0c0c7bbau; return 0; }
r[7]=read(ram,0x0c0c7c4cu,4);
goto P_0c0c7bbc;
P_0c0c7bbc: /* original 7608, guest PC 0x0c0c7bbc */
if(!s->budget--) { s->failed_pc=0x0c0c7bbcu; return 0; }
r[6]+=0x00000008u;
goto P_0c0c7bbe;
P_0c0c7bbe: /* original a01a, guest PC 0x0c0c7bbe */
if(!s->budget--) { s->failed_pc=0x0c0c7bbeu; return 0; }
tmp=read(ram,r[8],4);
r[5]=tmp;
goto P_0c0c7bf6;
P_0c0c7bc0: /* original 6582, guest PC 0x0c0c7bc0 */
if(!s->budget--) { s->failed_pc=0x0c0c7bc0u; return 0; }
tmp=read(ram,r[8],4);
r[5]=tmp;
goto P_0c0c7bc2;
P_0c0c7bc2: /* original 933e, guest PC 0x0c0c7bc2 */
if(!s->budget--) { s->failed_pc=0x0c0c7bc2u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c7c42u,2);
goto P_0c0c7bc4;
P_0c0c7bc4: /* original e700, guest PC 0x0c0c7bc4 */
if(!s->budget--) { s->failed_pc=0x0c0c7bc4u; return 0; }
r[7]=0x00000000u;
goto P_0c0c7bc6;
P_0c0c7bc6: /* original 2f36, guest PC 0x0c0c7bc6 */
if(!s->budget--) { s->failed_pc=0x0c0c7bc6u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c7bc8;
P_0c0c7bc8: /* original 2fb6, guest PC 0x0c0c7bc8 */
if(!s->budget--) { s->failed_pc=0x0c0c7bc8u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c7bca;
P_0c0c7bca: /* original 2fd6, guest PC 0x0c0c7bca */
if(!s->budget--) { s->failed_pc=0x0c0c7bcau; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c7bcc;
P_0c0c7bcc: /* original 9035, guest PC 0x0c0c7bcc */
if(!s->budget--) { s->failed_pc=0x0c0c7bccu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c7c3au,2);
goto P_0c0c7bce;
P_0c0c7bce: /* original d41e, guest PC 0x0c0c7bce */
if(!s->budget--) { s->failed_pc=0x0c0c7bceu; return 0; }
r[4]=read(ram,0x0c0c7c48u,4);
goto P_0c0c7bd0;
P_0c0c7bd0: /* original 9632, guest PC 0x0c0c7bd0 */
if(!s->budget--) { s->failed_pc=0x0c0c7bd0u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c7c38u,2);
goto P_0c0c7bd2;
P_0c0c7bd2: /* original 05ee, guest PC 0x0c0c7bd2 */
if(!s->budget--) { s->failed_pc=0x0c0c7bd2u; return 0; }
r[5]=read(ram,r[14]+r[0],4);
goto P_0c0c7bd4;
P_0c0c7bd4: /* original 349c, guest PC 0x0c0c7bd4 */
if(!s->budget--) { s->failed_pc=0x0c0c7bd4u; return 0; }
r[4]+=r[9];
goto P_0c0c7bd6;
P_0c0c7bd6: /* original 36ec, guest PC 0x0c0c7bd6 */
if(!s->budget--) { s->failed_pc=0x0c0c7bd6u; return 0; }
r[6]+=r[14];
goto P_0c0c7bd8;
P_0c0c7bd8: /* original 1f43, guest PC 0x0c0c7bd8 */
if(!s->budget--) { s->failed_pc=0x0c0c7bd8u; return 0; }
write(ram,r[15]+12,r[4],4);
goto P_0c0c7bda;
P_0c0c7bda: /* original 7608, guest PC 0x0c0c7bda */
if(!s->budget--) { s->failed_pc=0x0c0c7bdau; return 0; }
r[6]+=0x00000008u;
goto P_0c0c7bdc;
P_0c0c7bdc: /* original 4c0b, guest PC 0x0c0c7bdc */
if(!s->budget--) { s->failed_pc=0x0c0c7bdcu; return 0; }
target=r[12];
r[16]=code_base|0x0c0c7be0u;
tmp=read(ram,r[4],4);
r[4]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c7be0u) { target=s->pc; goto dispatch; }
goto P_0c0c7be0;
P_0c0c7bde: /* original 6442, guest PC 0x0c0c7bde */
if(!s->budget--) { s->failed_pc=0x0c0c7bdeu; return 0; }
tmp=read(ram,r[4],4);
r[4]=tmp;
goto P_0c0c7be0;
P_0c0c7be0: /* original 9330, guest PC 0x0c0c7be0 */
if(!s->budget--) { s->failed_pc=0x0c0c7be0u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c7c44u,2);
goto P_0c0c7be2;
P_0c0c7be2: /* original 2f36, guest PC 0x0c0c7be2 */
if(!s->budget--) { s->failed_pc=0x0c0c7be2u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c7be4;
P_0c0c7be4: /* original 2fb6, guest PC 0x0c0c7be4 */
if(!s->budget--) { s->failed_pc=0x0c0c7be4u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c7be6;
P_0c0c7be6: /* original 2fd6, guest PC 0x0c0c7be6 */
if(!s->budget--) { s->failed_pc=0x0c0c7be6u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c7be8;
P_0c0c7be8: /* original 52f6, guest PC 0x0c0c7be8 */
if(!s->budget--) { s->failed_pc=0x0c0c7be8u; return 0; }
r[2]=read(ram,r[15]+24,4);
goto P_0c0c7bea;
P_0c0c7bea: /* original 9625, guest PC 0x0c0c7bea */
if(!s->budget--) { s->failed_pc=0x0c0c7beau; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c7c38u,2);
goto P_0c0c7bec;
P_0c0c7bec: /* original d717, guest PC 0x0c0c7bec */
if(!s->budget--) { s->failed_pc=0x0c0c7becu; return 0; }
r[7]=read(ram,0x0c0c7c4cu,4);
goto P_0c0c7bee;
P_0c0c7bee: /* original 5421, guest PC 0x0c0c7bee */
if(!s->budget--) { s->failed_pc=0x0c0c7beeu; return 0; }
r[4]=read(ram,r[2]+4,4);
goto P_0c0c7bf0;
P_0c0c7bf0: /* original 36ec, guest PC 0x0c0c7bf0 */
if(!s->budget--) { s->failed_pc=0x0c0c7bf0u; return 0; }
r[6]+=r[14];
goto P_0c0c7bf2;
P_0c0c7bf2: /* original 6582, guest PC 0x0c0c7bf2 */
if(!s->budget--) { s->failed_pc=0x0c0c7bf2u; return 0; }
tmp=read(ram,r[8],4);
r[5]=tmp;
goto P_0c0c7bf4;
P_0c0c7bf4: /* original 7608, guest PC 0x0c0c7bf4 */
if(!s->budget--) { s->failed_pc=0x0c0c7bf4u; return 0; }
r[6]+=0x00000008u;
goto P_0c0c7bf6;
P_0c0c7bf6: /* original 4c0b, guest PC 0x0c0c7bf6 */
if(!s->budget--) { s->failed_pc=0x0c0c7bf6u; return 0; }
target=r[12];
r[16]=code_base|0x0c0c7bfau;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c7bfau) { target=s->pc; goto dispatch; }
goto P_0c0c7bfa;
P_0c0c7bf8: /* original 0009, guest PC 0x0c0c7bf8 */
if(!s->budget--) { s->failed_pc=0x0c0c7bf8u; return 0; }
goto P_0c0c7bfa;
P_0c0c7bfa: /* original a011, guest PC 0x0c0c7bfa */
if(!s->budget--) { s->failed_pc=0x0c0c7bfau; return 0; }
r[15]+=0x00000018u;
goto P_0c0c7c20;
P_0c0c7bfc: /* original 7f18, guest PC 0x0c0c7bfc */
if(!s->budget--) { s->failed_pc=0x0c0c7bfcu; return 0; }
r[15]+=0x00000018u;
goto P_0c0c7bfe;
P_0c0c7bfe: /* original 7f04, guest PC 0x0c0c7bfe */
if(!s->budget--) { s->failed_pc=0x0c0c7bfeu; return 0; }
r[15]+=0x00000004u;
goto P_0c0c7c00;
P_0c0c7c00: /* original 9018, guest PC 0x0c0c7c00 */
if(!s->budget--) { s->failed_pc=0x0c0c7c00u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c7c34u,2);
goto P_0c0c7c02;
P_0c0c7c02: /* original 4f26, guest PC 0x0c0c7c02 */
if(!s->budget--) { s->failed_pc=0x0c0c7c02u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c7c04;
P_0c0c7c04: /* original 0ea6, guest PC 0x0c0c7c04 */
if(!s->budget--) { s->failed_pc=0x0c0c7c04u; return 0; }
write(ram,r[14]+r[0],r[10],4);
goto P_0c0c7c06;
P_0c0c7c06: /* original 70fc, guest PC 0x0c0c7c06 */
if(!s->budget--) { s->failed_pc=0x0c0c7c06u; return 0; }
r[0]+=0xfffffffcu;
goto P_0c0c7c08;
P_0c0c7c08: /* original 0ea6, guest PC 0x0c0c7c08 */
if(!s->budget--) { s->failed_pc=0x0c0c7c08u; return 0; }
write(ram,r[14]+r[0],r[10],4);
goto P_0c0c7c0a;
P_0c0c7c0a: /* original 7048, guest PC 0x0c0c7c0a */
if(!s->budget--) { s->failed_pc=0x0c0c7c0au; return 0; }
r[0]+=0x00000048u;
goto P_0c0c7c0c;
P_0c0c7c0c: /* original e3ff, guest PC 0x0c0c7c0c */
if(!s->budget--) { s->failed_pc=0x0c0c7c0cu; return 0; }
r[3]=0xffffffffu;
goto P_0c0c7c0e;
P_0c0c7c0e: /* original 0e36, guest PC 0x0c0c7c0e */
if(!s->budget--) { s->failed_pc=0x0c0c7c0eu; return 0; }
write(ram,r[14]+r[0],r[3],4);
goto P_0c0c7c10;
P_0c0c7c10: /* original 68f6, guest PC 0x0c0c7c10 */
if(!s->budget--) { s->failed_pc=0x0c0c7c10u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c0c7c12;
P_0c0c7c12: /* original 69f6, guest PC 0x0c0c7c12 */
if(!s->budget--) { s->failed_pc=0x0c0c7c12u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0c7c14;
P_0c0c7c14: /* original 6af6, guest PC 0x0c0c7c14 */
if(!s->budget--) { s->failed_pc=0x0c0c7c14u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0c7c16;
P_0c0c7c16: /* original 6bf6, guest PC 0x0c0c7c16 */
if(!s->budget--) { s->failed_pc=0x0c0c7c16u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0c7c18;
P_0c0c7c18: /* original 6cf6, guest PC 0x0c0c7c18 */
if(!s->budget--) { s->failed_pc=0x0c0c7c18u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0c7c1a;
P_0c0c7c1a: /* original 6df6, guest PC 0x0c0c7c1a */
if(!s->budget--) { s->failed_pc=0x0c0c7c1au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0c7c1c;
P_0c0c7c1c: /* original adf1, guest PC 0x0c0c7c1c */
if(!s->budget--) { s->failed_pc=0x0c0c7c1cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0c7802;
P_0c0c7c1e: /* original 6ef6, guest PC 0x0c0c7c1e */
if(!s->budget--) { s->failed_pc=0x0c0c7c1eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0c7c20;
P_0c0c7c20: /* original 7f04, guest PC 0x0c0c7c20 */
if(!s->budget--) { s->failed_pc=0x0c0c7c20u; return 0; }
r[15]+=0x00000004u;
goto P_0c0c7c22;
P_0c0c7c22: /* original 4f26, guest PC 0x0c0c7c22 */
if(!s->budget--) { s->failed_pc=0x0c0c7c22u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c7c24;
P_0c0c7c24: /* original 68f6, guest PC 0x0c0c7c24 */
if(!s->budget--) { s->failed_pc=0x0c0c7c24u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c0c7c26;
P_0c0c7c26: /* original 69f6, guest PC 0x0c0c7c26 */
if(!s->budget--) { s->failed_pc=0x0c0c7c26u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0c7c28;
P_0c0c7c28: /* original 6af6, guest PC 0x0c0c7c28 */
if(!s->budget--) { s->failed_pc=0x0c0c7c28u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0c7c2a;
P_0c0c7c2a: /* original 6bf6, guest PC 0x0c0c7c2a */
if(!s->budget--) { s->failed_pc=0x0c0c7c2au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0c7c2c;
P_0c0c7c2c: /* original 6cf6, guest PC 0x0c0c7c2c */
if(!s->budget--) { s->failed_pc=0x0c0c7c2cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0c7c2e;
P_0c0c7c2e: /* original 6df6, guest PC 0x0c0c7c2e */
if(!s->budget--) { s->failed_pc=0x0c0c7c2eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0c7c30;
P_0c0c7c30: /* original 000b, guest PC 0x0c0c7c30 */
if(!s->budget--) { s->failed_pc=0x0c0c7c30u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0c7c32: /* original 6ef6, guest PC 0x0c0c7c32 */
if(!s->budget--) { s->failed_pc=0x0c0c7c32u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0c7c34u,s,ram);
P_0c0c9cc0: /* original 9031, guest PC 0x0c0c9cc0 */
if(!s->budget--) { s->failed_pc=0x0c0c9cc0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c9d26u,2);
goto P_0c0c9cc2;
P_0c0c9cc2: /* original d41c, guest PC 0x0c0c9cc2 */
if(!s->budget--) { s->failed_pc=0x0c0c9cc2u; return 0; }
r[4]=read(ram,0x0c0c9d34u,4);
goto P_0c0c9cc4;
P_0c0c9cc4: /* original 4f12, guest PC 0x0c0c9cc4 */
if(!s->budget--) { s->failed_pc=0x0c0c9cc4u; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c0c9cc6;
P_0c0c9cc6: /* original 034e, guest PC 0x0c0c9cc6 */
if(!s->budget--) { s->failed_pc=0x0c0c9cc6u; return 0; }
r[3]=read(ram,r[4]+r[0],4);
goto P_0c0c9cc8;
P_0c0c9cc8: /* original 70fc, guest PC 0x0c0c9cc8 */
if(!s->budget--) { s->failed_pc=0x0c0c9cc8u; return 0; }
r[0]+=0xfffffffcu;
goto P_0c0c9cca;
P_0c0c9cca: /* original 024e, guest PC 0x0c0c9cca */
if(!s->budget--) { s->failed_pc=0x0c0c9ccau; return 0; }
r[2]=read(ram,r[4]+r[0],4);
goto P_0c0c9ccc;
P_0c0c9ccc: /* original 7008, guest PC 0x0c0c9ccc */
if(!s->budget--) { s->failed_pc=0x0c0c9cccu; return 0; }
r[0]+=0x00000008u;
goto P_0c0c9cce;
P_0c0c9cce: /* original 014d, guest PC 0x0c0c9cce */
if(!s->budget--) { s->failed_pc=0x0c0c9cceu; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c0c9cd0;
P_0c0c9cd0: /* original 70f8, guest PC 0x0c0c9cd0 */
if(!s->budget--) { s->failed_pc=0x0c0c9cd0u; return 0; }
r[0]+=0xfffffff8u;
goto P_0c0c9cd2;
P_0c0c9cd2: /* original 0237, guest PC 0x0c0c9cd2 */
if(!s->budget--) { s->failed_pc=0x0c0c9cd2u; return 0; }
r[19]=r[2]*r[3];
goto P_0c0c9cd4;
P_0c0c9cd4: /* original 051a, guest PC 0x0c0c9cd4 */
if(!s->budget--) { s->failed_pc=0x0c0c9cd4u; return 0; }
r[5]=r[19];
goto P_0c0c9cd6;
P_0c0c9cd6: /* original 351c, guest PC 0x0c0c9cd6 */
if(!s->budget--) { s->failed_pc=0x0c0c9cd6u; return 0; }
r[5]+=r[1];
goto P_0c0c9cd8;
P_0c0c9cd8: /* original 0456, guest PC 0x0c0c9cd8 */
if(!s->budget--) { s->failed_pc=0x0c0c9cd8u; return 0; }
write(ram,r[4]+r[0],r[5],4);
goto P_0c0c9cda;
P_0c0c9cda: /* original 4529, guest PC 0x0c0c9cda */
if(!s->budget--) { s->failed_pc=0x0c0c9cdau; return 0; }
r[5]>>=16;
goto P_0c0c9cdc;
P_0c0c9cdc: /* original 9421, guest PC 0x0c0c9cdc */
if(!s->budget--) { s->failed_pc=0x0c0c9cdcu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c9d22u,2);
goto P_0c0c9cde;
P_0c0c9cde: /* original 2459, guest PC 0x0c0c9cde */
if(!s->budget--) { s->failed_pc=0x0c0c9cdeu; return 0; }
r[4]&=r[5];
goto P_0c0c9ce0;
P_0c0c9ce0: /* original 6043, guest PC 0x0c0c9ce0 */
if(!s->budget--) { s->failed_pc=0x0c0c9ce0u; return 0; }
r[0]=r[4];
goto P_0c0c9ce2;
P_0c0c9ce2: /* original 000b, guest PC 0x0c0c9ce2 */
if(!s->budget--) { s->failed_pc=0x0c0c9ce2u; return 0; }
target=r[16];
r[19]=read(ram,r[15],4); r[15]+=4;
s->pc=target; return ram->oob==0;
P_0c0c9ce4: /* original 4f16, guest PC 0x0c0c9ce4 */
if(!s->budget--) { s->failed_pc=0x0c0c9ce4u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
return vf3_matrix_family(0x0c0c9ce6u,s,ram);
unsupported: s->failed_pc=target; return 0;
}
static const uint32_t owned_pcs[]={
0x0c046e66u,0x0c046e68u,0x0c046e6au,0x0c046e6cu,0x0c046e6eu,0x0c046e70u,0x0c046e72u,0x0c046e74u,0x0c046e76u,0x0c046e78u,0x0c046e7au,0x0c046e7cu,0x0c046e7eu,0x0c046e80u,0x0c046e82u,0x0c046e84u,
0x0c046e86u,0x0c046e88u,0x0c046e8au,0x0c046e8cu,0x0c046e8eu,0x0c046e90u,0x0c046e92u,0x0c046e94u,0x0c046e96u,0x0c046e98u,0x0c046e9au,0x0c046e9cu,0x0c046e9eu,0x0c046ea0u,0x0c046ea2u,0x0c046ea4u,
0x0c046ea6u,0x0c046ea8u,0x0c046eaau,0x0c046eaeu,0x0c046eb0u,0x0c046eb2u,0x0c046eb4u,0x0c046eb6u,0x0c046eb8u,0x0c046ebau,0x0c046ebcu,0x0c046ebeu,0x0c046ec0u,0x0c046ec2u,0x0c046ec4u,0x0c046ec6u,
0x0c046ec8u,0x0c046ecau,0x0c046eccu,0x0c046eceu,0x0c046ed0u,0x0c046ed2u,0x0c046ed4u,0x0c046ed6u,0x0c046ed8u,0x0c046edau,0x0c046edcu,0x0c046edeu,0x0c046ee0u,0x0c046ee2u,0x0c046ee4u,0x0c046ee6u,
0x0c046ee8u,0x0c046eeau,0x0c046eecu,0x0c046eeeu,0x0c046ef0u,0x0c046ef2u,0x0c046ef4u,0x0c046ef6u,0x0c046ef8u,0x0c046efau,0x0c046efcu,0x0c046efeu,0x0c046f00u,0x0c046f02u,0x0c046f04u,0x0c046f06u,
0x0c046f08u,0x0c046f0au,0x0c046f0cu,0x0c046f0eu,0x0c046f10u,0x0c046f12u,0x0c046f14u,0x0c046f16u,0x0c046f18u,0x0c046f1au,0x0c046f1cu,0x0c046f1eu,0x0c046f20u,0x0c046f22u,0x0c046f24u,0x0c046f26u,
0x0c046f28u,0x0c046f2au,0x0c046f2cu,0x0c046f2eu,0x0c046f30u,0x0c046f32u,0x0c046f34u,0x0c046f36u,0x0c046f38u,0x0c046f3au,0x0c046f3cu,0x0c046f3eu,0x0c046f40u,0x0c046f42u,0x0c046f44u,0x0c046f46u,
0x0c046f48u,0x0c046f4au,0x0c046f4cu,0x0c046f4eu,0x0c046f50u,0x0c046f52u,0x0c046f54u,0x0c046f56u,0x0c046f58u,0x0c046f5au,0x0c046f5cu,0x0c046f5eu,0x0c046f60u,0x0c046f62u,0x0c046f64u,0x0c046f66u,
0x0c046f68u,0x0c046f6au,0x0c046f6cu,0x0c046f6eu,0x0c046f70u,0x0c046f72u,0x0c046f74u,0x0c046f76u,0x0c046f78u,0x0c046f7au,0x0c046f7cu,0x0c046f7eu,0x0c046f80u,0x0c046f82u,0x0c046f84u,0x0c046f86u,
0x0c046f88u,0x0c046f8au,0x0c046f8cu,0x0c046f8eu,0x0c046f90u,0x0c046f92u,0x0c046f94u,0x0c046f96u,0x0c046f98u,0x0c046f9au,0x0c046f9cu,0x0c046f9eu,0x0c046fa0u,0x0c046fa2u,0x0c046fa4u,0x0c046fb4u,
0x0c046fb6u,0x0c046fb8u,0x0c046fbau,0x0c046fbcu,0x0c046fbeu,0x0c046fc0u,0x0c046fc2u,0x0c046fc4u,0x0c046fc6u,0x0c046fc8u,0x0c046fcau,0x0c046fccu,0x0c046fceu,0x0c046fd0u,0x0c046fd2u,0x0c046fd4u,
0x0c046fd6u,0x0c046fd8u,0x0c046fdau,0x0c046fdcu,0x0c046fdeu,0x0c046fe0u,0x0c046fe2u,0x0c046fe4u,0x0c046fe6u,0x0c046fe8u,0x0c046feau,0x0c046fecu,0x0c046feeu,0x0c046ff0u,0x0c046ff2u,0x0c046ff4u,
0x0c046ff6u,0x0c046ff8u,0x0c046ffau,0x0c046ffcu,0x0c046ffeu,0x0c047000u,0x0c047002u,0x0c047004u,0x0c047006u,0x0c047008u,0x0c04700au,0x0c04700cu,0x0c04700eu,0x0c047010u,0x0c047012u,0x0c047014u,
0x0c047016u,0x0c047018u,0x0c04701au,0x0c04701cu,0x0c04701eu,0x0c047020u,0x0c047022u,0x0c047024u,0x0c047026u,0x0c047028u,0x0c04702au,0x0c04702cu,0x0c04702eu,0x0c047030u,0x0c047032u,0x0c047034u,
0x0c047036u,0x0c047038u,0x0c04703au,0x0c04703cu,0x0c04703eu,0x0c047040u,0x0c047042u,0x0c047044u,0x0c047046u,0x0c047048u,0x0c04704au,0x0c0471d8u,0x0c0471dau,0x0c0471dcu,0x0c0471deu,0x0c0471e0u,
0x0c0471e2u,0x0c0471e4u,0x0c0471e6u,0x0c0471e8u,0x0c0471eau,0x0c0471ecu,0x0c0471eeu,0x0c0471f0u,0x0c0471f2u,0x0c0471f4u,0x0c0471f6u,0x0c0471f8u,0x0c0471fau,0x0c0471fcu,0x0c0471feu,0x0c047200u,
0x0c047202u,0x0c047204u,0x0c047218u,0x0c04721au,0x0c04721cu,0x0c04721eu,0x0c047220u,0x0c047222u,0x0c047224u,0x0c047226u,0x0c047228u,0x0c04722au,0x0c04722cu,0x0c0491a4u,0x0c0491a6u,0x0c0491a8u,
0x0c0491aau,0x0c0491acu,0x0c0491aeu,0x0c0491b0u,0x0c0491b2u,0x0c0491b4u,0x0c0491b6u,0x0c0491b8u,0x0c0491bau,0x0c0491bcu,0x0c0491beu,0x0c0491c0u,0x0c0491c2u,0x0c0491c4u,0x0c0491c6u,0x0c0491c8u,
0x0c0491cau,0x0c0491ccu,0x0c0491ceu,0x0c0491d0u,0x0c0491d2u,0x0c0491d4u,0x0c0491d6u,0x0c0491d8u,0x0c0491dau,0x0c0491dcu,0x0c0491deu,0x0c0491e0u,0x0c0491e2u,0x0c0491e4u,0x0c0491e6u,0x0c0491e8u,
0x0c0491eau,0x0c0491ecu,0x0c0491eeu,0x0c0491f0u,0x0c0491f2u,0x0c0491f4u,0x0c0491f6u,0x0c0491f8u,0x0c0491fau,0x0c0491fcu,0x0c0491feu,0x0c049200u,0x0c049202u,0x0c049204u,0x0c049206u,0x0c049208u,
0x0c04920au,0x0c04920cu,0x0c04920eu,0x0c049210u,0x0c049212u,0x0c049214u,0x0c049216u,0x0c049218u,0x0c04921au,0x0c04921cu,0x0c04921eu,0x0c049220u,0x0c049222u,0x0c049224u,0x0c049226u,0x0c049228u,
0x0c04922au,0x0c04922cu,0x0c04922eu,0x0c049230u,0x0c049232u,0x0c049234u,0x0c049236u,0x0c049238u,0x0c04923au,0x0c04923cu,0x0c04923eu,0x0c049240u,0x0c049242u,0x0c049244u,0x0c049246u,0x0c049248u,
0x0c04924au,0x0c04924cu,0x0c04924eu,0x0c049250u,0x0c049252u,0x0c049254u,0x0c049256u,0x0c049258u,0x0c04925au,0x0c04925cu,0x0c04925eu,0x0c049260u,0x0c049262u,0x0c049264u,0x0c049266u,0x0c049268u,
0x0c04926au,0x0c04926cu,0x0c04926eu,0x0c049270u,0x0c049272u,0x0c049274u,0x0c049276u,0x0c049278u,0x0c04927au,0x0c04927cu,0x0c04927eu,0x0c049280u,0x0c049282u,0x0c049284u,0x0c049286u,0x0c049288u,
0x0c04928au,0x0c04928cu,0x0c04928eu,0x0c049290u,0x0c049292u,0x0c049294u,0x0c049296u,0x0c049298u,0x0c04929au,0x0c04929cu,0x0c04929eu,0x0c0492a0u,0x0c0492beu,0x0c0492c0u,0x0c0492c2u,0x0c0492c4u,
0x0c0492c6u,0x0c0492c8u,0x0c0492cau,0x0c0492ccu,0x0c0492ceu,0x0c0492d0u,0x0c0492d2u,0x0c0492d4u,0x0c04b9e4u,0x0c04b9e6u,0x0c04b9e8u,0x0c04b9eau,0x0c04b9ecu,0x0c04b9eeu,0x0c04b9f0u,0x0c04b9f2u,
0x0c04b9f4u,0x0c04b9f6u,0x0c04b9f8u,0x0c04b9fau,0x0c04c9aeu,0x0c04c9b0u,0x0c04c9b2u,0x0c04c9b4u,0x0c04c9b6u,0x0c04c9b8u,0x0c04c9bau,0x0c04c9bcu,0x0c04c9beu,0x0c04c9c0u,0x0c04c9c2u,0x0c04c9c4u,
0x0c04c9c6u,0x0c04c9c8u,0x0c04c9cau,0x0c04c9ccu,0x0c04c9ceu,0x0c04c9d0u,0x0c04c9d2u,0x0c04c9d4u,0x0c04c9d6u,0x0c04c9d8u,0x0c04c9dau,0x0c04c9dcu,0x0c04c9deu,0x0c04c9e0u,0x0c04c9e2u,0x0c04c9e4u,
0x0c04c9e6u,0x0c04c9e8u,0x0c04c9eau,0x0c04c9ecu,0x0c04c9eeu,0x0c04c9f0u,0x0c04c9f2u,0x0c04c9f4u,0x0c04c9f6u,0x0c04c9f8u,0x0c04c9fau,0x0c04c9fcu,0x0c04c9feu,0x0c04ca00u,0x0c04ca02u,0x0c04ca04u,
0x0c04ca06u,0x0c04ca08u,0x0c04ca0au,0x0c04ca0cu,0x0c04ca0eu,0x0c04ca10u,0x0c04ca12u,0x0c04ca14u,0x0c04ca16u,0x0c04ca18u,0x0c04ca1au,0x0c04ca1cu,0x0c04ca1eu,0x0c04ca20u,0x0c04ca22u,0x0c04ca24u,
0x0c04ca26u,0x0c04ca28u,0x0c04ca50u,0x0c04ca52u,0x0c04ca54u,0x0c04ca56u,0x0c04ca58u,0x0c04ca5au,0x0c04ca5cu,0x0c04ca5eu,0x0c04ca60u,0x0c04ca62u,0x0c04ca64u,0x0c04ca66u,0x0c04ca68u,0x0c04ca6au,
0x0c04ca6cu,0x0c04ca6eu,0x0c04ca70u,0x0c04ca72u,0x0c04ca74u,0x0c04ca76u,0x0c04ca78u,0x0c04ca7au,0x0c04ca7cu,0x0c04ca7eu,0x0c04ca80u,0x0c04ca82u,0x0c04ca84u,0x0c04ca86u,0x0c04ca88u,0x0c04ca8au,
0x0c04ca8cu,0x0c04ca8eu,0x0c04ca90u,0x0c04ca92u,0x0c04ca94u,0x0c04ca96u,0x0c04ca98u,0x0c04ca9au,0x0c04ca9cu,0x0c04ca9eu,0x0c04caa0u,0x0c04caa2u,0x0c04caa4u,0x0c04caa6u,0x0c04caa8u,0x0c04caaau,
0x0c04caacu,0x0c04caaeu,0x0c04cab0u,0x0c04cab2u,0x0c04cab4u,0x0c04cab6u,0x0c04cab8u,0x0c04cabau,0x0c04cabcu,0x0c04cabeu,0x0c04cac0u,0x0c04cac2u,0x0c04cac4u,0x0c04cac6u,0x0c04cac8u,0x0c04cacau,
0x0c04caccu,0x0c04caceu,0x0c04cad0u,0x0c04cad2u,0x0c04cad4u,0x0c04cad6u,0x0c04cad8u,0x0c04cadau,0x0c04cadcu,0x0c04cadeu,0x0c04cae0u,0x0c04cae2u,0x0c04cae4u,0x0c04cae6u,0x0c04cae8u,0x0c04caeau,
0x0c04caecu,0x0c04caeeu,0x0c04caf0u,0x0c04caf2u,0x0c04caf4u,0x0c04caf6u,0x0c04caf8u,0x0c04cafau,0x0c04cafcu,0x0c04cafeu,0x0c04cb00u,0x0c04cb02u,0x0c04cb04u,0x0c04cb06u,0x0c04cb08u,0x0c04cb0au,
0x0c04cb0cu,0x0c04cb0eu,0x0c04cb10u,0x0c04cb12u,0x0c04cb14u,0x0c04cb16u,0x0c04cb18u,0x0c04cb1au,0x0c04cb1cu,0x0c04cb1eu,0x0c04cb20u,0x0c04cb22u,0x0c04cb24u,0x0c04cb26u,0x0c04cb28u,0x0c04cb2au,
0x0c04cb2cu,0x0c04cb2eu,0x0c04cb30u,0x0c04cb32u,0x0c04cb34u,0x0c04cb36u,0x0c04cb38u,0x0c04cb3au,0x0c04cb3cu,0x0c081d24u,0x0c081d26u,0x0c081d28u,0x0c081d2au,0x0c081d2cu,0x0c081d2eu,0x0c081d30u,
0x0c081d32u,0x0c081d34u,0x0c081d36u,0x0c081d38u,0x0c081d3au,0x0c081d3cu,0x0c081d3eu,0x0c081d40u,0x0c081d42u,0x0c081d44u,0x0c081d46u,0x0c081d48u,0x0c081d4au,0x0c081d4cu,0x0c081d4eu,0x0c081d50u,
0x0c081d52u,0x0c081d54u,0x0c081d56u,0x0c081d58u,0x0c081d5au,0x0c081d5cu,0x0c081d5eu,0x0c081d60u,0x0c081d62u,0x0c081d64u,0x0c081d66u,0x0c081d68u,0x0c081d6au,0x0c081d6cu,0x0c081d6eu,0x0c081d70u,
0x0c081d72u,0x0c081d74u,0x0c081d76u,0x0c081d78u,0x0c081d7au,0x0c081d7cu,0x0c081d7eu,0x0c081d80u,0x0c081d82u,0x0c081d84u,0x0c081d86u,0x0c081d88u,0x0c081d8au,0x0c081d8cu,0x0c081d8eu,0x0c081d90u,
0x0c081d92u,0x0c081d94u,0x0c081d96u,0x0c081d98u,0x0c081d9au,0x0c081d9cu,0x0c081d9eu,0x0c081da0u,0x0c081da2u,0x0c081da4u,0x0c081da6u,0x0c081da8u,0x0c081daau,0x0c081dacu,0x0c081daeu,0x0c081db0u,
0x0c081db2u,0x0c081db4u,0x0c081db6u,0x0c081db8u,0x0c081dbau,0x0c081dbcu,0x0c081dbeu,0x0c081dc0u,0x0c081dc2u,0x0c081dc4u,0x0c081dc6u,0x0c081dc8u,0x0c081dcau,0x0c081dccu,0x0c081dceu,0x0c081dd0u,
0x0c081dd2u,0x0c081dd4u,0x0c081dd6u,0x0c081dd8u,0x0c081ddau,0x0c081ddcu,0x0c081ddeu,0x0c081de0u,0x0c081de2u,0x0c081de4u,0x0c081de6u,0x0c081de8u,0x0c081deau,0x0c081decu,0x0c081deeu,0x0c081df0u,
0x0c081df2u,0x0c081df4u,0x0c081df6u,0x0c081df8u,0x0c081dfau,0x0c081dfcu,0x0c081dfeu,0x0c081e00u,0x0c081e02u,0x0c081e04u,0x0c081e06u,0x0c081e08u,0x0c081e0au,0x0c081e0cu,0x0c081e0eu,0x0c081e10u,
0x0c081e12u,0x0c081e14u,0x0c081e16u,0x0c081e18u,0x0c081e1au,0x0c081e1cu,0x0c081e1eu,0x0c081e20u,0x0c081e22u,0x0c081e24u,0x0c081e26u,0x0c081e28u,0x0c081e2au,0x0c081e2cu,0x0c081e2eu,0x0c081e30u,
0x0c081e32u,0x0c081e34u,0x0c081e36u,0x0c081e38u,0x0c081e3au,0x0c081e3cu,0x0c081e3eu,0x0c081e68u,0x0c081e6au,0x0c081e6cu,0x0c081e6eu,0x0c081e70u,0x0c081e72u,0x0c081e74u,0x0c081e76u,0x0c081e78u,
0x0c081e7au,0x0c081e7cu,0x0c081e7eu,0x0c081e80u,0x0c081e82u,0x0c081e84u,0x0c081e86u,0x0c081e88u,0x0c081e8au,0x0c081e8cu,0x0c081e8eu,0x0c081e90u,0x0c081e92u,0x0c081e94u,0x0c081e96u,0x0c081e98u,
0x0c081e9au,0x0c081e9cu,0x0c081e9eu,0x0c081ea0u,0x0c081ea2u,0x0c081ea4u,0x0c081ea6u,0x0c081ea8u,0x0c081eaau,0x0c081eacu,0x0c081eaeu,0x0c081eb0u,0x0c081eb2u,0x0c081eb4u,0x0c081eb6u,0x0c081eb8u,
0x0c081ebau,0x0c081ebcu,0x0c081ebeu,0x0c081ec0u,0x0c081ec2u,0x0c081ec4u,0x0c081ec6u,0x0c081ec8u,0x0c081ecau,0x0c081eccu,0x0c081eceu,0x0c081ed0u,0x0c081ed2u,0x0c081ed4u,0x0c081ed6u,0x0c081ed8u,
0x0c081edau,0x0c081edcu,0x0c081edeu,0x0c081ee0u,0x0c081ee2u,0x0c081ee4u,0x0c081ee6u,0x0c081ee8u,0x0c081eeau,0x0c081eecu,0x0c081eeeu,0x0c081ef0u,0x0c081ef2u,0x0c081ef4u,0x0c081ef6u,0x0c081ef8u,
0x0c081efau,0x0c081efcu,0x0c081efeu,0x0c081f00u,0x0c081f02u,0x0c081f04u,0x0c081f06u,0x0c081f08u,0x0c081f0au,0x0c081f0cu,0x0c081f0eu,0x0c081f10u,0x0c081f12u,0x0c081f14u,0x0c081f16u,0x0c081f18u,
0x0c081f1au,0x0c081f1cu,0x0c081f1eu,0x0c081f20u,0x0c081f22u,0x0c081f24u,0x0c081f26u,0x0c081f28u,0x0c081f2au,0x0c081f2cu,0x0c081f2eu,0x0c081f30u,0x0c081f32u,0x0c081f34u,0x0c081f36u,0x0c081f38u,
0x0c081f3au,0x0c081f3cu,0x0c081f3eu,0x0c081f40u,0x0c081f42u,0x0c081f44u,0x0c081f46u,0x0c081f48u,0x0c081f4au,0x0c081f4cu,0x0c081f4eu,0x0c081f50u,0x0c081f52u,0x0c081f54u,0x0c081f56u,0x0c081f58u,
0x0c081f5au,0x0c081f5cu,0x0c081f5eu,0x0c081f60u,0x0c081f62u,0x0c081f64u,0x0c081f66u,0x0c081f68u,0x0c081f6au,0x0c081f6cu,0x0c081f6eu,0x0c081f70u,0x0c081f72u,0x0c081f74u,0x0c081f76u,0x0c081f78u,
0x0c081f7au,0x0c081f7cu,0x0c081f7eu,0x0c081f80u,0x0c081f82u,0x0c0831f8u,0x0c0831fau,0x0c0831fcu,0x0c0831feu,0x0c083200u,0x0c083202u,0x0c083204u,0x0c083206u,0x0c083208u,0x0c08320au,0x0c08320cu,
0x0c08320eu,0x0c083210u,0x0c083212u,0x0c083214u,0x0c083216u,0x0c083218u,0x0c08321au,0x0c08321cu,0x0c08321eu,0x0c083220u,0x0c083222u,0x0c083224u,0x0c083226u,0x0c083228u,0x0c08322au,0x0c08322cu,
0x0c08322eu,0x0c083230u,0x0c083232u,0x0c083234u,0x0c083236u,0x0c083238u,0x0c08323au,0x0c08323cu,0x0c08323eu,0x0c083240u,0x0c083242u,0x0c083244u,0x0c08327cu,0x0c08327eu,0x0c083280u,0x0c083282u,
0x0c083284u,0x0c083286u,0x0c083288u,0x0c08328au,0x0c08328cu,0x0c08328eu,0x0c083290u,0x0c083292u,0x0c083294u,0x0c083296u,0x0c083298u,0x0c08329au,0x0c08329cu,0x0c08329eu,0x0c0832a0u,0x0c0832a2u,
0x0c0832a4u,0x0c0832a6u,0x0c0832a8u,0x0c0832aau,0x0c0832acu,0x0c0832aeu,0x0c0832b0u,0x0c0832b2u,0x0c0832b4u,0x0c0832b6u,0x0c0832b8u,0x0c0832bau,0x0c0832bcu,0x0c0832beu,0x0c0832c0u,0x0c0832c2u,
0x0c0832c4u,0x0c0832c6u,0x0c0832c8u,0x0c0832cau,0x0c0832ccu,0x0c0832ceu,0x0c0832d0u,0x0c0832d2u,0x0c0832d4u,0x0c0832d6u,0x0c0832d8u,0x0c0832dau,0x0c0832dcu,0x0c0832deu,0x0c0832e0u,0x0c0832e2u,
0x0c0832e4u,0x0c0832e6u,0x0c0832e8u,0x0c0832eau,0x0c0832ecu,0x0c0832eeu,0x0c0832f0u,0x0c0832f2u,0x0c0832f4u,0x0c0832f6u,0x0c0832f8u,0x0c0832fau,0x0c0832fcu,0x0c0832feu,0x0c083300u,0x0c083302u,
0x0c083304u,0x0c083306u,0x0c083308u,0x0c08330au,0x0c08330cu,0x0c08330eu,0x0c083310u,0x0c083312u,0x0c083314u,0x0c083316u,0x0c083318u,0x0c08331au,0x0c08331cu,0x0c08331eu,0x0c083320u,0x0c083322u,
0x0c083324u,0x0c083326u,0x0c083328u,0x0c08332au,0x0c08332cu,0x0c08332eu,0x0c083330u,0x0c083332u,0x0c083334u,0x0c083336u,0x0c083338u,0x0c08333au,0x0c08333cu,0x0c08333eu,0x0c083340u,0x0c083342u,
0x0c083344u,0x0c083346u,0x0c083348u,0x0c08334au,0x0c08334cu,0x0c08334eu,0x0c083350u,0x0c083352u,0x0c083354u,0x0c083356u,0x0c083358u,0x0c08335au,0x0c08335cu,0x0c08335eu,0x0c083360u,0x0c083362u,
0x0c083364u,0x0c083384u,0x0c083386u,0x0c083388u,0x0c08338au,0x0c08338cu,0x0c08338eu,0x0c083390u,0x0c083392u,0x0c083394u,0x0c083396u,0x0c083398u,0x0c08339au,0x0c08339cu,0x0c08339eu,0x0c0833a0u,
0x0c0833a2u,0x0c0833a4u,0x0c0833a6u,0x0c0833a8u,0x0c0833aau,0x0c0833acu,0x0c0833aeu,0x0c0833b0u,0x0c0833b2u,0x0c0833b4u,0x0c0833b6u,0x0c0833b8u,0x0c0833bau,0x0c0833bcu,0x0c0833beu,0x0c0833c0u,
0x0c0833c2u,0x0c0833c4u,0x0c0833c6u,0x0c0833c8u,0x0c0833cau,0x0c0833ccu,0x0c0833ceu,0x0c0833d0u,0x0c0833d2u,0x0c0833d4u,0x0c0833d6u,0x0c0833d8u,0x0c0833dau,0x0c0833dcu,0x0c0833deu,0x0c0833e0u,
0x0c0833e2u,0x0c0833e4u,0x0c0833e6u,0x0c0833e8u,0x0c0833eau,0x0c0833ecu,0x0c0833eeu,0x0c0833f0u,0x0c0833f2u,0x0c0833f4u,0x0c0833f6u,0x0c0833f8u,0x0c0833fau,0x0c0833fcu,0x0c0833feu,0x0c083400u,
0x0c083402u,0x0c083404u,0x0c083406u,0x0c083408u,0x0c08340au,0x0c08340cu,0x0c08340eu,0x0c083410u,0x0c083412u,0x0c083414u,0x0c083416u,0x0c083418u,0x0c08341au,0x0c08341cu,0x0c08341eu,0x0c083420u,
0x0c083422u,0x0c083424u,0x0c083426u,0x0c083428u,0x0c08342au,0x0c08342cu,0x0c08342eu,0x0c083430u,0x0c083432u,0x0c083434u,0x0c083436u,0x0c083438u,0x0c08343au,0x0c08343cu,0x0c08343eu,0x0c083440u,
0x0c083442u,0x0c083444u,0x0c083446u,0x0c083448u,0x0c08344au,0x0c08344cu,0x0c08344eu,0x0c083450u,0x0c083452u,0x0c083454u,0x0c083456u,0x0c083458u,0x0c08345au,0x0c08345cu,0x0c08345eu,0x0c083460u,
0x0c083462u,0x0c083464u,0x0c083466u,0x0c083468u,0x0c08346au,0x0c08346cu,0x0c08346eu,0x0c083470u,0x0c083472u,0x0c083474u,0x0c083476u,0x0c083478u,0x0c08347au,0x0c08347cu,0x0c08347eu,0x0c083480u,
0x0c083482u,0x0c083484u,0x0c083486u,0x0c083488u,0x0c08348au,0x0c08348cu,0x0c08348eu,0x0c083490u,0x0c083492u,0x0c0834b0u,0x0c0834b2u,0x0c0834b4u,0x0c0834b6u,0x0c0834b8u,0x0c0834bau,0x0c0834bcu,
0x0c0834beu,0x0c0834c0u,0x0c0834c2u,0x0c0834c4u,0x0c0834c6u,0x0c0834c8u,0x0c0834cau,0x0c0834ccu,0x0c0834ceu,0x0c0834d0u,0x0c0834d2u,0x0c0834d4u,0x0c0834d6u,0x0c0834d8u,0x0c0834dau,0x0c0834dcu,
0x0c0834deu,0x0c0834e0u,0x0c0834e2u,0x0c0834e4u,0x0c0834e6u,0x0c0834e8u,0x0c0834eau,0x0c0834ecu,0x0c0834eeu,0x0c0834f0u,0x0c0834f2u,0x0c0834f4u,0x0c0834f6u,0x0c0834f8u,0x0c0834fau,0x0c0834fcu,
0x0c0834feu,0x0c083500u,0x0c083502u,0x0c083504u,0x0c083506u,0x0c083508u,0x0c08350au,0x0c08350cu,0x0c08350eu,0x0c083510u,0x0c083512u,0x0c083514u,0x0c083516u,0x0c083518u,0x0c08351au,0x0c08351cu,
0x0c08351eu,0x0c083520u,0x0c083522u,0x0c083524u,0x0c083526u,0x0c083528u,0x0c08352au,0x0c08352cu,0x0c08352eu,0x0c083530u,0x0c083532u,0x0c083534u,0x0c083536u,0x0c083538u,0x0c08353au,0x0c08353cu,
0x0c08353eu,0x0c083540u,0x0c083542u,0x0c083544u,0x0c083546u,0x0c083548u,0x0c08354au,0x0c08354cu,0x0c08354eu,0x0c083550u,0x0c083552u,0x0c083554u,0x0c083556u,0x0c083558u,0x0c08355au,0x0c08355cu,
0x0c08355eu,0x0c083560u,0x0c083562u,0x0c083564u,0x0c083566u,0x0c083568u,0x0c08356au,0x0c08356cu,0x0c08356eu,0x0c083570u,0x0c083572u,0x0c083574u,0x0c083576u,0x0c083578u,0x0c08357au,0x0c08357cu,
0x0c08357eu,0x0c083580u,0x0c083582u,0x0c083584u,0x0c083586u,0x0c083588u,0x0c08358au,0x0c08358cu,0x0c08358eu,0x0c083590u,0x0c083592u,0x0c083594u,0x0c083596u,0x0c083598u,0x0c08359au,0x0c08359cu,
0x0c08359eu,0x0c0835a0u,0x0c0835a2u,0x0c0835a4u,0x0c0835a6u,0x0c0835a8u,0x0c0835c4u,0x0c0835c6u,0x0c0835c8u,0x0c0835cau,0x0c0835ccu,0x0c0835ceu,0x0c0835d0u,0x0c0835d2u,0x0c0835d4u,0x0c0835d6u,
0x0c0835d8u,0x0c0835dau,0x0c0835dcu,0x0c0835deu,0x0c0835e0u,0x0c0835e2u,0x0c0835e4u,0x0c0835e6u,0x0c0835e8u,0x0c0835eau,0x0c0835ecu,0x0c0835eeu,0x0c0835f0u,0x0c0835f2u,0x0c0835f4u,0x0c0835f6u,
0x0c0835f8u,0x0c0835fau,0x0c0835fcu,0x0c0835feu,0x0c083600u,0x0c083602u,0x0c083604u,0x0c083606u,0x0c083608u,0x0c08360au,0x0c08360cu,0x0c08360eu,0x0c083610u,0x0c083612u,0x0c083614u,0x0c083616u,
0x0c083618u,0x0c08361au,0x0c08361cu,0x0c08361eu,0x0c083620u,0x0c083622u,0x0c083624u,0x0c083626u,0x0c083628u,0x0c08362au,0x0c08362cu,0x0c08362eu,0x0c083630u,0x0c083632u,0x0c083634u,0x0c083636u,
0x0c083638u,0x0c08363au,0x0c08363cu,0x0c08363eu,0x0c083640u,0x0c083642u,0x0c083644u,0x0c083646u,0x0c083648u,0x0c08364au,0x0c08364cu,0x0c08364eu,0x0c083650u,0x0c083652u,0x0c083654u,0x0c083656u,
0x0c083658u,0x0c08365au,0x0c08365cu,0x0c08365eu,0x0c083660u,0x0c083662u,0x0c083664u,0x0c083666u,0x0c083668u,0x0c08366au,0x0c08366cu,0x0c08366eu,0x0c083670u,0x0c083672u,0x0c083674u,0x0c083676u,
0x0c083678u,0x0c08367au,0x0c08367cu,0x0c08367eu,0x0c083680u,0x0c083682u,0x0c083684u,0x0c083686u,0x0c083688u,0x0c08368au,0x0c08368cu,0x0c08368eu,0x0c083690u,0x0c083692u,0x0c083694u,0x0c083696u,
0x0c083698u,0x0c08369au,0x0c08369cu,0x0c08369eu,0x0c0836a0u,0x0c0836a2u,0x0c0836a4u,0x0c0836a6u,0x0c0836a8u,0x0c0836aau,0x0c0836acu,0x0c0836aeu,0x0c0836b0u,0x0c0836b2u,0x0c0836b4u,0x0c0836b6u,
0x0c0836b8u,0x0c0836bau,0x0c0836bcu,0x0c0836beu,0x0c0836c0u,0x0c0836c2u,0x0c0836c4u,0x0c0836c6u,0x0c0836c8u,0x0c0836cau,0x0c0836ccu,0x0c0836ceu,0x0c0836d0u,0x0c0836d2u,0x0c0836d4u,0x0c0836f0u,
0x0c0836f2u,0x0c0836f4u,0x0c0836f6u,0x0c0836f8u,0x0c0836fau,0x0c0836fcu,0x0c0836feu,0x0c083700u,0x0c083702u,0x0c083704u,0x0c083706u,0x0c083708u,0x0c08370au,0x0c08370cu,0x0c08370eu,0x0c083710u,
0x0c083712u,0x0c083714u,0x0c083716u,0x0c083718u,0x0c08371au,0x0c08371cu,0x0c08371eu,0x0c083720u,0x0c083722u,0x0c083724u,0x0c083726u,0x0c083728u,0x0c08372au,0x0c08372cu,0x0c08372eu,0x0c083730u,
0x0c083732u,0x0c083734u,0x0c083736u,0x0c083738u,0x0c08373au,0x0c08373cu,0x0c08373eu,0x0c083740u,0x0c083742u,0x0c083744u,0x0c083746u,0x0c083748u,0x0c08374au,0x0c08374cu,0x0c08374eu,0x0c083750u,
0x0c083752u,0x0c083754u,0x0c083756u,0x0c083758u,0x0c08375au,0x0c08375cu,0x0c08375eu,0x0c083760u,0x0c083762u,0x0c083764u,0x0c083766u,0x0c083768u,0x0c08376au,0x0c08376cu,0x0c08376eu,0x0c083770u,
0x0c083772u,0x0c083774u,0x0c083776u,0x0c083778u,0x0c08377au,0x0c08377cu,0x0c08377eu,0x0c083780u,0x0c083782u,0x0c083784u,0x0c083786u,0x0c083788u,0x0c08378au,0x0c08378cu,0x0c08378eu,0x0c083790u,
0x0c083792u,0x0c083794u,0x0c083796u,0x0c083798u,0x0c08379au,0x0c08379cu,0x0c08379eu,0x0c0837a0u,0x0c0837a2u,0x0c0837a4u,0x0c0837a6u,0x0c0837a8u,0x0c0837aau,0x0c0837acu,0x0c0837aeu,0x0c0837b0u,
0x0c0837b2u,0x0c0837b4u,0x0c0837b6u,0x0c0837b8u,0x0c0837bau,0x0c0837bcu,0x0c0837beu,0x0c0837c0u,0x0c0837c2u,0x0c0837c4u,0x0c0837c6u,0x0c0837c8u,0x0c0837cau,0x0c0837ccu,0x0c0837ceu,0x0c0837d0u,
0x0c0837d2u,0x0c0837d4u,0x0c0837d6u,0x0c0837d8u,0x0c0837dau,0x0c0837dcu,0x0c0837deu,0x0c0837e0u,0x0c0837e2u,0x0c0837e4u,0x0c0837e6u,0x0c0837e8u,0x0c0837eau,0x0c0837ecu,0x0c0837eeu,0x0c0837f0u,
0x0c08380cu,0x0c08380eu,0x0c083810u,0x0c083812u,0x0c083814u,0x0c083816u,0x0c083818u,0x0c08381au,0x0c08381cu,0x0c08381eu,0x0c083820u,0x0c083822u,0x0c083824u,0x0c083826u,0x0c083828u,0x0c08382au,
0x0c08382cu,0x0c08382eu,0x0c083830u,0x0c083832u,0x0c083834u,0x0c083836u,0x0c083838u,0x0c08383au,0x0c08383cu,0x0c08383eu,0x0c083840u,0x0c083842u,0x0c083844u,0x0c083846u,0x0c083848u,0x0c08384au,
0x0c08384cu,0x0c08384eu,0x0c083850u,0x0c083852u,0x0c083854u,0x0c083856u,0x0c083858u,0x0c08385au,0x0c08385cu,0x0c08385eu,0x0c083860u,0x0c083862u,0x0c083864u,0x0c083866u,0x0c083868u,0x0c08386au,
0x0c08386cu,0x0c08386eu,0x0c083870u,0x0c083872u,0x0c083874u,0x0c083876u,0x0c083878u,0x0c08387au,0x0c08387cu,0x0c08387eu,0x0c083880u,0x0c083882u,0x0c083884u,0x0c083886u,0x0c083888u,0x0c08388au,
0x0c08388cu,0x0c08388eu,0x0c083890u,0x0c083892u,0x0c083894u,0x0c083896u,0x0c083898u,0x0c08389au,0x0c08389cu,0x0c08389eu,0x0c0838a0u,0x0c0838a2u,0x0c0838a4u,0x0c0838a6u,0x0c0838a8u,0x0c0838aau,
0x0c0838acu,0x0c0838aeu,0x0c0838b0u,0x0c0838b2u,0x0c0838b4u,0x0c0838b6u,0x0c0838b8u,0x0c0838bau,0x0c0838bcu,0x0c0838beu,0x0c0838c0u,0x0c0838c2u,0x0c0838c4u,0x0c0838c6u,0x0c0838c8u,0x0c0838cau,
0x0c0838ccu,0x0c0838ceu,0x0c0838d0u,0x0c0838d2u,0x0c0838d4u,0x0c0838d6u,0x0c0838f0u,0x0c0838f2u,0x0c0838f4u,0x0c0838f6u,0x0c0838f8u,0x0c0838fau,0x0c0838fcu,0x0c0838feu,0x0c083900u,0x0c083902u,
0x0c083904u,0x0c083906u,0x0c083908u,0x0c08390au,0x0c08390cu,0x0c08390eu,0x0c083910u,0x0c083912u,0x0c083914u,0x0c083916u,0x0c083918u,0x0c08391au,0x0c08391cu,0x0c08391eu,0x0c083920u,0x0c083922u,
0x0c083924u,0x0c083926u,0x0c083928u,0x0c08392au,0x0c08392cu,0x0c08392eu,0x0c083930u,0x0c083932u,0x0c083934u,0x0c083936u,0x0c083938u,0x0c08393au,0x0c08393cu,0x0c08393eu,0x0c083940u,0x0c083942u,
0x0c083944u,0x0c083946u,0x0c083948u,0x0c08394au,0x0c08394cu,0x0c08394eu,0x0c083950u,0x0c083952u,0x0c083954u,0x0c083956u,0x0c083958u,0x0c08395au,0x0c08395cu,0x0c08395eu,0x0c083960u,0x0c083962u,
0x0c083964u,0x0c083966u,0x0c083968u,0x0c08396au,0x0c08396cu,0x0c08396eu,0x0c083970u,0x0c083972u,0x0c083974u,0x0c083976u,0x0c083978u,0x0c08397au,0x0c08397cu,0x0c08397eu,0x0c083980u,0x0c083982u,
0x0c083984u,0x0c083986u,0x0c083988u,0x0c08398au,0x0c08398cu,0x0c08398eu,0x0c083990u,0x0c083992u,0x0c083994u,0x0c083996u,0x0c083998u,0x0c08399au,0x0c08399cu,0x0c08399eu,0x0c0839a0u,0x0c0839a2u,
0x0c0839a4u,0x0c0839a6u,0x0c0839a8u,0x0c0839aau,0x0c0839acu,0x0c0839aeu,0x0c0839b0u,0x0c0839b2u,0x0c0839b4u,0x0c0839b6u,0x0c0839b8u,0x0c0839bau,0x0c0839bcu,0x0c0839beu,0x0c0839c0u,0x0c0839c2u,
0x0c0839c4u,0x0c0839c6u,0x0c0839c8u,0x0c0839cau,0x0c0839ccu,0x0c0839ceu,0x0c0839d0u,0x0c0839d2u,0x0c0839d4u,0x0c0839d6u,0x0c0839d8u,0x0c0839dau,0x0c0839dcu,0x0c0839deu,0x0c0839e0u,0x0c0839e2u,
0x0c0839e4u,0x0c0839e6u,0x0c0839e8u,0x0c0839eau,0x0c0839ecu,0x0c0839eeu,0x0c0839f0u,0x0c0839f2u,0x0c0839f4u,0x0c0839f6u,0x0c0839f8u,0x0c0839fau,0x0c0839fcu,0x0c0839feu,0x0c083a00u,0x0c083a02u,
0x0c083a04u,0x0c083a24u,0x0c083a26u,0x0c083a28u,0x0c083a2au,0x0c083a2cu,0x0c083a2eu,0x0c083a30u,0x0c083a32u,0x0c083a34u,0x0c083a36u,0x0c083a38u,0x0c083a3au,0x0c083a3cu,0x0c083a3eu,0x0c083a40u,
0x0c083a42u,0x0c083a44u,0x0c083a46u,0x0c083a48u,0x0c083a4au,0x0c083a4cu,0x0c083a4eu,0x0c083a50u,0x0c083a52u,0x0c083a54u,0x0c083a56u,0x0c083a58u,0x0c083a5au,0x0c083a5cu,0x0c083a5eu,0x0c083a60u,
0x0c083a62u,0x0c083a64u,0x0c083a66u,0x0c083a68u,0x0c083a6au,0x0c083a6cu,0x0c083a6eu,0x0c083a70u,0x0c083a72u,0x0c083a74u,0x0c083a76u,0x0c083a78u,0x0c083a7au,0x0c083a7cu,0x0c083a7eu,0x0c083a80u,
0x0c083a82u,0x0c083a84u,0x0c083a86u,0x0c083a88u,0x0c083a8au,0x0c083a8cu,0x0c083a8eu,0x0c083a90u,0x0c083a92u,0x0c083a94u,0x0c083a96u,0x0c083aa8u,0x0c083aaau,0x0c083aacu,0x0c083aaeu,0x0c083ab0u,
0x0c083ab2u,0x0c083ab4u,0x0c083ab6u,0x0c083ab8u,0x0c083abau,0x0c083abcu,0x0c083abeu,0x0c083ac0u,0x0c083ac2u,0x0c083ac4u,0x0c083ac6u,0x0c083ac8u,0x0c083acau,0x0c083accu,0x0c083aceu,0x0c083ad0u,
0x0c083ad2u,0x0c083ad4u,0x0c083ad6u,0x0c083ad8u,0x0c083adau,0x0c083adcu,0x0c083adeu,0x0c083ae0u,0x0c083ae2u,0x0c083ae4u,0x0c083ae6u,0x0c083ae8u,0x0c083aeau,0x0c083aecu,0x0c083aeeu,0x0c083af0u,
0x0c083af2u,0x0c083af4u,0x0c083af6u,0x0c083af8u,0x0c083afau,0x0c083afcu,0x0c083afeu,0x0c083b00u,0x0c083b02u,0x0c083b04u,0x0c083b06u,0x0c083b08u,0x0c083b0au,0x0c083b0cu,0x0c083b0eu,0x0c083b10u,
0x0c083b12u,0x0c083b14u,0x0c083b16u,0x0c083b18u,0x0c083b1au,0x0c083b1cu,0x0c083b1eu,0x0c083b20u,0x0c083b22u,0x0c083b24u,0x0c083b26u,0x0c083b28u,0x0c083b2au,0x0c083b2cu,0x0c083b2eu,0x0c083b30u,
0x0c083b32u,0x0c083b34u,0x0c083b36u,0x0c083b38u,0x0c083b3au,0x0c083b78u,0x0c083b7au,0x0c083b7cu,0x0c083b7eu,0x0c083b80u,0x0c083b82u,0x0c083b84u,0x0c083b86u,0x0c083b88u,0x0c083b8au,0x0c083b8cu,
0x0c083b8eu,0x0c083b90u,0x0c083b92u,0x0c083b94u,0x0c083b96u,0x0c083b98u,0x0c083b9au,0x0c083b9cu,0x0c083b9eu,0x0c083ba0u,0x0c083ba2u,0x0c083ba4u,0x0c083ba6u,0x0c083ba8u,0x0c083baau,0x0c083bacu,
0x0c083baeu,0x0c083bb0u,0x0c083bb2u,0x0c083bb4u,0x0c083bb6u,0x0c083bb8u,0x0c083bbau,0x0c083bbcu,0x0c083bbeu,0x0c083bc0u,0x0c083bc2u,0x0c083bc4u,0x0c083bc6u,0x0c083bc8u,0x0c083bcau,0x0c083bccu,
0x0c083bceu,0x0c083bd0u,0x0c083bd2u,0x0c083bd4u,0x0c083bd6u,0x0c083bd8u,0x0c083bdau,0x0c083bdcu,0x0c083bdeu,0x0c083be0u,0x0c083be2u,0x0c083be4u,0x0c083be6u,0x0c083be8u,0x0c083beau,0x0c083becu,
0x0c083beeu,0x0c083bf0u,0x0c083bf2u,0x0c083bf4u,0x0c083bf6u,0x0c083bf8u,0x0c083bfau,0x0c083bfcu,0x0c083bfeu,0x0c083c00u,0x0c083c02u,0x0c083c04u,0x0c083c06u,0x0c083c08u,0x0c083c0au,0x0c083c0cu,
0x0c083c0eu,0x0c083c10u,0x0c083c12u,0x0c083c14u,0x0c083c16u,0x0c083c18u,0x0c083c1au,0x0c083c1cu,0x0c083c1eu,0x0c083c20u,0x0c083c22u,0x0c083c24u,0x0c083c26u,0x0c083c28u,0x0c083c2au,0x0c083c2cu,
0x0c083c2eu,0x0c083c30u,0x0c083c32u,0x0c083c34u,0x0c083c36u,0x0c083c38u,0x0c083c3au,0x0c083c3cu,0x0c083c3eu,0x0c083c40u,0x0c083c42u,0x0c083c44u,0x0c083c46u,0x0c083c48u,0x0c083c4au,0x0c083c4cu,
0x0c083c4eu,0x0c083c50u,0x0c083c52u,0x0c083c54u,0x0c0853feu,0x0c085400u,0x0c085402u,0x0c085404u,0x0c085406u,0x0c085408u,0x0c08540au,0x0c08540cu,0x0c08540eu,0x0c085410u,0x0c085412u,0x0c085414u,
0x0c085416u,0x0c085418u,0x0c08541au,0x0c08541cu,0x0c08541eu,0x0c085420u,0x0c085422u,0x0c085424u,0x0c085426u,0x0c085428u,0x0c08542au,0x0c08542cu,0x0c08542eu,0x0c085430u,0x0c085432u,0x0c085434u,
0x0c085436u,0x0c085438u,0x0c08543au,0x0c08543cu,0x0c08543eu,0x0c085440u,0x0c085442u,0x0c085444u,0x0c085446u,0x0c085448u,0x0c08544au,0x0c08544cu,0x0c08544eu,0x0c085450u,0x0c085452u,0x0c085480u,
0x0c085482u,0x0c085484u,0x0c085486u,0x0c085488u,0x0c08548au,0x0c08548cu,0x0c08548eu,0x0c085490u,0x0c085492u,0x0c085494u,0x0c085496u,0x0c085498u,0x0c08549au,0x0c08549cu,0x0c08549eu,0x0c0854a0u,
0x0c0854a2u,0x0c0854a4u,0x0c0854a6u,0x0c0854a8u,0x0c0854aau,0x0c0854acu,0x0c0854aeu,0x0c0854b0u,0x0c0854b2u,0x0c0854b4u,0x0c0854b6u,0x0c0854b8u,0x0c0854bau,0x0c0854bcu,0x0c0854beu,0x0c0854c0u,
0x0c0854c2u,0x0c0854c4u,0x0c0854c6u,0x0c0854c8u,0x0c0854cau,0x0c0854ccu,0x0c0854ceu,0x0c0854d0u,0x0c0854d2u,0x0c0854d4u,0x0c0854d6u,0x0c0854d8u,0x0c0854dau,0x0c0854dcu,0x0c0854deu,0x0c0854e0u,
0x0c0854e2u,0x0c0854e4u,0x0c0854e6u,0x0c0854e8u,0x0c0854eau,0x0c0854ecu,0x0c0854eeu,0x0c0854f0u,0x0c0854f2u,0x0c0854f4u,0x0c0854f6u,0x0c0854f8u,0x0c0854fau,0x0c0854fcu,0x0c0854feu,0x0c085500u,
0x0c085502u,0x0c085504u,0x0c085506u,0x0c085508u,0x0c08550au,0x0c08550cu,0x0c08550eu,0x0c085510u,0x0c085512u,0x0c085514u,0x0c085516u,0x0c085518u,0x0c08551au,0x0c08551cu,0x0c08551eu,0x0c085520u,
0x0c085522u,0x0c085524u,0x0c085526u,0x0c085528u,0x0c08552au,0x0c08552cu,0x0c08552eu,0x0c085530u,0x0c085532u,0x0c085534u,0x0c085536u,0x0c085538u,0x0c08553au,0x0c08553cu,0x0c08553eu,0x0c085540u,
0x0c085542u,0x0c085544u,0x0c085546u,0x0c085548u,0x0c08554au,0x0c08554cu,0x0c08554eu,0x0c085550u,0x0c085552u,0x0c085554u,0x0c085556u,0x0c085558u,0x0c08555au,0x0c08555cu,0x0c08555eu,0x0c085560u,
0x0c085562u,0x0c085564u,0x0c085566u,0x0c085568u,0x0c08556au,0x0c08556cu,0x0c08556eu,0x0c085570u,0x0c085572u,0x0c085574u,0x0c086b3au,0x0c086b3cu,0x0c086b3eu,0x0c086b40u,0x0c086b42u,0x0c086b44u,
0x0c086b46u,0x0c086b48u,0x0c086b4au,0x0c086b4cu,0x0c086b4eu,0x0c086b50u,0x0c086b52u,0x0c086b54u,0x0c086b56u,0x0c086b58u,0x0c086b5au,0x0c086b5cu,0x0c086b5eu,0x0c086b60u,0x0c086b62u,0x0c086b64u,
0x0c086b66u,0x0c086b68u,0x0c086b6au,0x0c086b6cu,0x0c086b6eu,0x0c086b70u,0x0c086b72u,0x0c086b74u,0x0c086b76u,0x0c086b78u,0x0c086b7au,0x0c086b7cu,0x0c086b7eu,0x0c086b80u,0x0c086b9cu,0x0c086b9eu,
0x0c086ba0u,0x0c086ba2u,0x0c086ba4u,0x0c086ba6u,0x0c086ba8u,0x0c086baau,0x0c086bacu,0x0c086baeu,0x0c086bb0u,0x0c086bb2u,0x0c086bb4u,0x0c086bb6u,0x0c086bb8u,0x0c086bbau,0x0c086bbcu,0x0c086bbeu,
0x0c086bc0u,0x0c086bc2u,0x0c086bc4u,0x0c086bc6u,0x0c086bc8u,0x0c086bcau,0x0c086bccu,0x0c086bceu,0x0c086bd0u,0x0c086bd2u,0x0c086bd4u,0x0c086bd6u,0x0c086bd8u,0x0c086bdau,0x0c086bdcu,0x0c086bdeu,
0x0c086be0u,0x0c086be2u,0x0c086be4u,0x0c086be6u,0x0c086be8u,0x0c086beau,0x0c086becu,0x0c086beeu,0x0c086bf0u,0x0c086bf2u,0x0c086bf4u,0x0c086bf6u,0x0c086bf8u,0x0c086bfau,0x0c086bfcu,0x0c086bfeu,
0x0c086c00u,0x0c086c02u,0x0c086c04u,0x0c086c06u,0x0c086c08u,0x0c086c0au,0x0c086c0cu,0x0c086c0eu,0x0c086c10u,0x0c086c12u,0x0c086c14u,0x0c086c16u,0x0c086c18u,0x0c086c1au,0x0c086c1cu,0x0c086c1eu,
0x0c086c20u,0x0c086c22u,0x0c086c24u,0x0c086c26u,0x0c086c28u,0x0c086c2au,0x0c086c2cu,0x0c086c2eu,0x0c086c30u,0x0c086c32u,0x0c086c34u,0x0c086c36u,0x0c086c38u,0x0c086c3au,0x0c086c3cu,0x0c086c3eu,
0x0c086c40u,0x0c086c42u,0x0c086c44u,0x0c086c46u,0x0c086c48u,0x0c086c4au,0x0c086c4cu,0x0c086c4eu,0x0c086c50u,0x0c086c52u,0x0c086c54u,0x0c086c56u,0x0c086c58u,0x0c086c5au,0x0c086c5cu,0x0c086c5eu,
0x0c086c60u,0x0c086c62u,0x0c086c64u,0x0c086c66u,0x0c086c68u,0x0c086c6au,0x0c086c6cu,0x0c086c6eu,0x0c086c70u,0x0c086c72u,0x0c086c74u,0x0c086c76u,0x0c086c78u,0x0c086c7au,0x0c086c7cu,0x0c086c7eu,
0x0c086c80u,0x0c086c82u,0x0c086c84u,0x0c086c86u,0x0c086c88u,0x0c086c8au,0x0c086c8cu,0x0c086c8eu,0x0c086c90u,0x0c086c92u,0x0c086c94u,0x0c086c96u,0x0c086c98u,0x0c086c9au,0x0c086c9cu,0x0c086c9eu,
0x0c086ca0u,0x0c086ca2u,0x0c086ca4u,0x0c086ca6u,0x0c086ca8u,0x0c086caau,0x0c086cacu,0x0c086caeu,0x0c086cb0u,0x0c086cb2u,0x0c086cb4u,0x0c086cb6u,0x0c086cb8u,0x0c086cbau,0x0c086cbcu,0x0c086cbeu,
0x0c086cc0u,0x0c086cc2u,0x0c086cc4u,0x0c086cc6u,0x0c086cc8u,0x0c086ccau,0x0c086cccu,0x0c086cceu,0x0c086cd0u,0x0c086cd2u,0x0c087542u,0x0c087544u,0x0c087546u,0x0c087548u,0x0c08754au,0x0c08754cu,
0x0c08754eu,0x0c087550u,0x0c087552u,0x0c087554u,0x0c087556u,0x0c087558u,0x0c08755au,0x0c08755cu,0x0c08755eu,0x0c087560u,0x0c08894cu,0x0c08894eu,0x0c088950u,0x0c088952u,0x0c088954u,0x0c088956u,
0x0c088958u,0x0c08895au,0x0c08895cu,0x0c08895eu,0x0c088960u,0x0c088962u,0x0c088964u,0x0c088966u,0x0c088968u,0x0c08896au,0x0c08896cu,0x0c08896eu,0x0c088970u,0x0c088972u,0x0c088974u,0x0c088976u,
0x0c088978u,0x0c08897au,0x0c08897cu,0x0c08897eu,0x0c088980u,0x0c088982u,0x0c088984u,0x0c088986u,0x0c088988u,0x0c08898au,0x0c08898cu,0x0c08898eu,0x0c088990u,0x0c088992u,0x0c088994u,0x0c088996u,
0x0c088998u,0x0c08899au,0x0c08899cu,0x0c08899eu,0x0c0889a0u,0x0c0889a2u,0x0c0889a4u,0x0c0889a6u,0x0c0889a8u,0x0c0889aau,0x0c0889acu,0x0c0889aeu,0x0c0889b0u,0x0c0889b2u,0x0c0889b4u,0x0c0889b6u,
0x0c0889ccu,0x0c0889ceu,0x0c0889d0u,0x0c0889d2u,0x0c0889d4u,0x0c0889d6u,0x0c0889d8u,0x0c0889dau,0x0c0889dcu,0x0c0889deu,0x0c0889e0u,0x0c0889e2u,0x0c0889e4u,0x0c0889e6u,0x0c0889e8u,0x0c0889eau,
0x0c0889ecu,0x0c0889eeu,0x0c0889f0u,0x0c0889f2u,0x0c0889f4u,0x0c0889f6u,0x0c0889f8u,0x0c0889fau,0x0c0889fcu,0x0c0889feu,0x0c088a00u,0x0c088a02u,0x0c088a04u,0x0c088a06u,0x0c088a08u,0x0c088a0au,
0x0c088a0cu,0x0c088a0eu,0x0c088a10u,0x0c088a12u,0x0c088a14u,0x0c088a16u,0x0c088a18u,0x0c088a1au,0x0c088a1cu,0x0c088a1eu,0x0c088a20u,0x0c088a22u,0x0c088a24u,0x0c088a26u,0x0c088a28u,0x0c088a2au,
0x0c088a2cu,0x0c088a2eu,0x0c088a30u,0x0c088a32u,0x0c088a34u,0x0c088a36u,0x0c088a38u,0x0c088a3au,0x0c088a3cu,0x0c088a3eu,0x0c088a40u,0x0c088a42u,0x0c088a44u,0x0c088a46u,0x0c088a48u,0x0c088a4au,
0x0c088a4cu,0x0c088a78u,0x0c088a7au,0x0c088a7cu,0x0c088a7eu,0x0c088a80u,0x0c088a82u,0x0c088a84u,0x0c088a86u,0x0c088a88u,0x0c088a8au,0x0c088a8cu,0x0c088a8eu,0x0c088a90u,0x0c088a92u,0x0c088a94u,
0x0c088a96u,0x0c088a98u,0x0c088a9au,0x0c088a9cu,0x0c088a9eu,0x0c088aa0u,0x0c088aa2u,0x0c088aa4u,0x0c088aa6u,0x0c088aa8u,0x0c088aaau,0x0c088aacu,0x0c088aaeu,0x0c088ab0u,0x0c088ab2u,0x0c088ab4u,
0x0c088ab6u,0x0c088ab8u,0x0c088abau,0x0c088abcu,0x0c088abeu,0x0c088ac0u,0x0c088ac2u,0x0c088ac4u,0x0c088ac6u,0x0c088ac8u,0x0c088acau,0x0c088accu,0x0c088aceu,0x0c088ad0u,0x0c088ad2u,0x0c088ad4u,
0x0c088ad6u,0x0c088ad8u,0x0c088adau,0x0c088adcu,0x0c088adeu,0x0c088ae0u,0x0c088ae2u,0x0c088ae4u,0x0c088ae6u,0x0c088ae8u,0x0c088aeau,0x0c088aecu,0x0c088aeeu,0x0c088af0u,0x0c088af2u,0x0c088af4u,
0x0c088af6u,0x0c088af8u,0x0c088afau,0x0c088afcu,0x0c088afeu,0x0c088b00u,0x0c088b02u,0x0c088b04u,0x0c088b06u,0x0c088b08u,0x0c088b0au,0x0c088b0cu,0x0c088b0eu,0x0c088b10u,0x0c088b12u,0x0c088b14u,
0x0c088b16u,0x0c088b18u,0x0c088b1au,0x0c088b1cu,0x0c088b1eu,0x0c088b20u,0x0c088b22u,0x0c088b24u,0x0c088b26u,0x0c088b28u,0x0c088b2au,0x0c088b2cu,0x0c088b2eu,0x0c088b30u,0x0c088b32u,0x0c088b34u,
0x0c088b36u,0x0c0c72e2u,0x0c0c72e4u,0x0c0c72e6u,0x0c0c72e8u,0x0c0c72eau,0x0c0c72ecu,0x0c0c72eeu,0x0c0c72f0u,0x0c0c72f2u,0x0c0c72f4u,0x0c0c72f6u,0x0c0c72f8u,0x0c0c72fau,0x0c0c72fcu,0x0c0c72feu,
0x0c0c7300u,0x0c0c7302u,0x0c0c7304u,0x0c0c7306u,0x0c0c7308u,0x0c0c730au,0x0c0c730cu,0x0c0c730eu,0x0c0c7310u,0x0c0c7312u,0x0c0c7314u,0x0c0c7316u,0x0c0c7318u,0x0c0c731au,0x0c0c731cu,0x0c0c731eu,
0x0c0c7320u,0x0c0c7322u,0x0c0c7324u,0x0c0c7326u,0x0c0c7328u,0x0c0c732au,0x0c0c732cu,0x0c0c732eu,0x0c0c7330u,0x0c0c7332u,0x0c0c7334u,0x0c0c7336u,0x0c0c7338u,0x0c0c733au,0x0c0c733cu,0x0c0c733eu,
0x0c0c7340u,0x0c0c7342u,0x0c0c7344u,0x0c0c7346u,0x0c0c7348u,0x0c0c734au,0x0c0c734cu,0x0c0c734eu,0x0c0c7350u,0x0c0c7352u,0x0c0c7354u,0x0c0c7356u,0x0c0c7358u,0x0c0c735au,0x0c0c735cu,0x0c0c735eu,
0x0c0c7360u,0x0c0c7362u,0x0c0c7364u,0x0c0c7366u,0x0c0c7368u,0x0c0c736au,0x0c0c736cu,0x0c0c736eu,0x0c0c7370u,0x0c0c7372u,0x0c0c7374u,0x0c0c7376u,0x0c0c7378u,0x0c0c737au,0x0c0c7398u,0x0c0c739au,
0x0c0c739cu,0x0c0c739eu,0x0c0c73a0u,0x0c0c73a2u,0x0c0c73a4u,0x0c0c73a6u,0x0c0c73a8u,0x0c0c73aau,0x0c0c73acu,0x0c0c73aeu,0x0c0c73b0u,0x0c0c73b2u,0x0c0c73b4u,0x0c0c73b6u,0x0c0c73b8u,0x0c0c73bau,
0x0c0c73bcu,0x0c0c73beu,0x0c0c73c0u,0x0c0c73c2u,0x0c0c73c4u,0x0c0c73c6u,0x0c0c73c8u,0x0c0c73cau,0x0c0c73ccu,0x0c0c73ceu,0x0c0c73d0u,0x0c0c73d2u,0x0c0c73d4u,0x0c0c73d6u,0x0c0c73d8u,0x0c0c73dau,
0x0c0c73dcu,0x0c0c73deu,0x0c0c73e0u,0x0c0c73e2u,0x0c0c73e4u,0x0c0c73e6u,0x0c0c73e8u,0x0c0c73eau,0x0c0c73ecu,0x0c0c73eeu,0x0c0c73f0u,0x0c0c73f2u,0x0c0c73f4u,0x0c0c73f6u,0x0c0c73f8u,0x0c0c73fau,
0x0c0c73fcu,0x0c0c73feu,0x0c0c7400u,0x0c0c7402u,0x0c0c7404u,0x0c0c7406u,0x0c0c7408u,0x0c0c740au,0x0c0c740cu,0x0c0c740eu,0x0c0c7410u,0x0c0c7412u,0x0c0c7414u,0x0c0c7416u,0x0c0c7418u,0x0c0c741au,
0x0c0c741cu,0x0c0c741eu,0x0c0c7420u,0x0c0c7422u,0x0c0c7424u,0x0c0c7426u,0x0c0c7428u,0x0c0c742au,0x0c0c742cu,0x0c0c742eu,0x0c0c7430u,0x0c0c7432u,0x0c0c7434u,0x0c0c7436u,0x0c0c7438u,0x0c0c743au,
0x0c0c743cu,0x0c0c743eu,0x0c0c7440u,0x0c0c7442u,0x0c0c7444u,0x0c0c7446u,0x0c0c7448u,0x0c0c744au,0x0c0c744cu,0x0c0c744eu,0x0c0c7450u,0x0c0c7452u,0x0c0c7454u,0x0c0c7456u,0x0c0c7458u,0x0c0c745au,
0x0c0c745cu,0x0c0c745eu,0x0c0c7460u,0x0c0c7462u,0x0c0c7464u,0x0c0c7466u,0x0c0c7468u,0x0c0c746au,0x0c0c746cu,0x0c0c746eu,0x0c0c7470u,0x0c0c7472u,0x0c0c7474u,0x0c0c7476u,0x0c0c7478u,0x0c0c747au,
0x0c0c747cu,0x0c0c747eu,0x0c0c7480u,0x0c0c7482u,0x0c0c7484u,0x0c0c7486u,0x0c0c7488u,0x0c0c748au,0x0c0c748cu,0x0c0c748eu,0x0c0c7490u,0x0c0c7492u,0x0c0c7802u,0x0c0c7804u,0x0c0c7806u,0x0c0c7808u,
0x0c0c780au,0x0c0c780cu,0x0c0c780eu,0x0c0c7810u,0x0c0c7812u,0x0c0c7814u,0x0c0c7816u,0x0c0c7818u,0x0c0c781au,0x0c0c781cu,0x0c0c781eu,0x0c0c7820u,0x0c0c7822u,0x0c0c7824u,0x0c0c7826u,0x0c0c7828u,
0x0c0c782au,0x0c0c782cu,0x0c0c782eu,0x0c0c7830u,0x0c0c7832u,0x0c0c7834u,0x0c0c7836u,0x0c0c7838u,0x0c0c783au,0x0c0c783cu,0x0c0c783eu,0x0c0c7840u,0x0c0c7842u,0x0c0c7844u,0x0c0c7846u,0x0c0c7848u,
0x0c0c784au,0x0c0c784cu,0x0c0c784eu,0x0c0c7850u,0x0c0c7852u,0x0c0c7854u,0x0c0c7856u,0x0c0c7858u,0x0c0c785au,0x0c0c785cu,0x0c0c7a88u,0x0c0c7a8au,0x0c0c7a8cu,0x0c0c7a8eu,0x0c0c7a90u,0x0c0c7a92u,
0x0c0c7a94u,0x0c0c7a96u,0x0c0c7a98u,0x0c0c7a9au,0x0c0c7a9cu,0x0c0c7a9eu,0x0c0c7aa0u,0x0c0c7aa2u,0x0c0c7aa4u,0x0c0c7aa6u,0x0c0c7aa8u,0x0c0c7aaau,0x0c0c7aacu,0x0c0c7aaeu,0x0c0c7ab0u,0x0c0c7ab2u,
0x0c0c7ab4u,0x0c0c7ab6u,0x0c0c7ab8u,0x0c0c7abau,0x0c0c7abcu,0x0c0c7abeu,0x0c0c7ac0u,0x0c0c7ac2u,0x0c0c7ac4u,0x0c0c7ac6u,0x0c0c7ac8u,0x0c0c7acau,0x0c0c7accu,0x0c0c7aceu,0x0c0c7ad0u,0x0c0c7ad2u,
0x0c0c7ad4u,0x0c0c7ad6u,0x0c0c7ad8u,0x0c0c7adau,0x0c0c7adcu,0x0c0c7adeu,0x0c0c7ae0u,0x0c0c7ae2u,0x0c0c7ae4u,0x0c0c7ae6u,0x0c0c7ae8u,0x0c0c7aeau,0x0c0c7aecu,0x0c0c7aeeu,0x0c0c7af0u,0x0c0c7af2u,
0x0c0c7af4u,0x0c0c7af6u,0x0c0c7af8u,0x0c0c7afau,0x0c0c7afcu,0x0c0c7afeu,0x0c0c7b00u,0x0c0c7b02u,0x0c0c7b04u,0x0c0c7b06u,0x0c0c7b08u,0x0c0c7b0au,0x0c0c7b0cu,0x0c0c7b0eu,0x0c0c7b10u,0x0c0c7b12u,
0x0c0c7b14u,0x0c0c7b16u,0x0c0c7b18u,0x0c0c7b1au,0x0c0c7b1cu,0x0c0c7b1eu,0x0c0c7b20u,0x0c0c7b22u,0x0c0c7b24u,0x0c0c7b26u,0x0c0c7b78u,0x0c0c7b7au,0x0c0c7b7cu,0x0c0c7b7eu,0x0c0c7b80u,0x0c0c7b82u,
0x0c0c7b84u,0x0c0c7b86u,0x0c0c7b88u,0x0c0c7b8au,0x0c0c7b8cu,0x0c0c7b8eu,0x0c0c7b90u,0x0c0c7b92u,0x0c0c7b94u,0x0c0c7b96u,0x0c0c7b98u,0x0c0c7b9au,0x0c0c7b9cu,0x0c0c7b9eu,0x0c0c7ba0u,0x0c0c7ba2u,
0x0c0c7ba4u,0x0c0c7ba6u,0x0c0c7ba8u,0x0c0c7baau,0x0c0c7bacu,0x0c0c7baeu,0x0c0c7bb0u,0x0c0c7bb2u,0x0c0c7bb4u,0x0c0c7bb6u,0x0c0c7bb8u,0x0c0c7bbau,0x0c0c7bbcu,0x0c0c7bbeu,0x0c0c7bc0u,0x0c0c7bc2u,
0x0c0c7bc4u,0x0c0c7bc6u,0x0c0c7bc8u,0x0c0c7bcau,0x0c0c7bccu,0x0c0c7bceu,0x0c0c7bd0u,0x0c0c7bd2u,0x0c0c7bd4u,0x0c0c7bd6u,0x0c0c7bd8u,0x0c0c7bdau,0x0c0c7bdcu,0x0c0c7bdeu,0x0c0c7be0u,0x0c0c7be2u,
0x0c0c7be4u,0x0c0c7be6u,0x0c0c7be8u,0x0c0c7beau,0x0c0c7becu,0x0c0c7beeu,0x0c0c7bf0u,0x0c0c7bf2u,0x0c0c7bf4u,0x0c0c7bf6u,0x0c0c7bf8u,0x0c0c7bfau,0x0c0c7bfcu,0x0c0c7bfeu,0x0c0c7c00u,0x0c0c7c02u,
0x0c0c7c04u,0x0c0c7c06u,0x0c0c7c08u,0x0c0c7c0au,0x0c0c7c0cu,0x0c0c7c0eu,0x0c0c7c10u,0x0c0c7c12u,0x0c0c7c14u,0x0c0c7c16u,0x0c0c7c18u,0x0c0c7c1au,0x0c0c7c1cu,0x0c0c7c1eu,0x0c0c7c20u,0x0c0c7c22u,
0x0c0c7c24u,0x0c0c7c26u,0x0c0c7c28u,0x0c0c7c2au,0x0c0c7c2cu,0x0c0c7c2eu,0x0c0c7c30u,0x0c0c7c32u,0x0c0c9cc0u,0x0c0c9cc2u,0x0c0c9cc4u,0x0c0c9cc6u,0x0c0c9cc8u,0x0c0c9ccau,0x0c0c9cccu,0x0c0c9cceu,
0x0c0c9cd0u,0x0c0c9cd2u,0x0c0c9cd4u,0x0c0c9cd6u,0x0c0c9cd8u,0x0c0c9cdau,0x0c0c9cdcu,0x0c0c9cdeu,0x0c0c9ce0u,0x0c0c9ce2u,0x0c0c9ce4u,
};
int vf3_c80_adapter_contains(uint32_t pc) {
pc&=0x1fffffffu; unsigned lo=0,hi=sizeof(owned_pcs)/sizeof(owned_pcs[0]);
while(lo<hi) { unsigned mid=lo+(hi-lo)/2; if(owned_pcs[mid]<pc) lo=mid+1; else hi=mid; }
return lo<sizeof(owned_pcs)/sizeof(owned_pcs[0]) && owned_pcs[lo]==pc;
}
