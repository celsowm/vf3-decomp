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
int vf3_phase1_adapter_0(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c039e58u: goto P_0c039e58;
case 0x0c039e5au: goto P_0c039e5a;
case 0x0c039e5cu: goto P_0c039e5c;
case 0x0c039e5eu: goto P_0c039e5e;
case 0x0c039e60u: goto P_0c039e60;
case 0x0c039e70u: goto P_0c039e70;
case 0x0c039e72u: goto P_0c039e72;
case 0x0c039e74u: goto P_0c039e74;
case 0x0c039e76u: goto P_0c039e76;
case 0x0c039e78u: goto P_0c039e78;
case 0x0c039e7au: goto P_0c039e7a;
case 0x0c039e7cu: goto P_0c039e7c;
case 0x0c039e7eu: goto P_0c039e7e;
case 0x0c039e80u: goto P_0c039e80;
case 0x0c039e82u: goto P_0c039e82;
case 0x0c039f50u: goto P_0c039f50;
case 0x0c039f52u: goto P_0c039f52;
case 0x0c039f54u: goto P_0c039f54;
case 0x0c039f56u: goto P_0c039f56;
case 0x0c039f58u: goto P_0c039f58;
case 0x0c039f5au: goto P_0c039f5a;
case 0x0c039f5cu: goto P_0c039f5c;
case 0x0c039f5eu: goto P_0c039f5e;
case 0x0c039f60u: goto P_0c039f60;
case 0x0c039f62u: goto P_0c039f62;
case 0x0c039f70u: goto P_0c039f70;
case 0x0c039f72u: goto P_0c039f72;
case 0x0c039f74u: goto P_0c039f74;
case 0x0c039f76u: goto P_0c039f76;
case 0x0c039f78u: goto P_0c039f78;
case 0x0c039f7au: goto P_0c039f7a;
case 0x0c039f7cu: goto P_0c039f7c;
case 0x0c039f7eu: goto P_0c039f7e;
case 0x0c039f80u: goto P_0c039f80;
case 0x0c039f82u: goto P_0c039f82;
case 0x0c039f84u: goto P_0c039f84;
case 0x0c039f86u: goto P_0c039f86;
case 0x0c039f88u: goto P_0c039f88;
case 0x0c039f8au: goto P_0c039f8a;
case 0x0c039f90u: goto P_0c039f90;
case 0x0c039f92u: goto P_0c039f92;
case 0x0c039f94u: goto P_0c039f94;
case 0x0c039f96u: goto P_0c039f96;
case 0x0c039f98u: goto P_0c039f98;
case 0x0c039fa0u: goto P_0c039fa0;
case 0x0c039fa2u: goto P_0c039fa2;
case 0x0c039fa4u: goto P_0c039fa4;
case 0x0c039fa6u: goto P_0c039fa6;
case 0x0c039fd0u: goto P_0c039fd0;
case 0x0c039fd2u: goto P_0c039fd2;
case 0x0c039fd4u: goto P_0c039fd4;
case 0x0c039fd6u: goto P_0c039fd6;
case 0x0c039fd8u: goto P_0c039fd8;
case 0x0c039fdau: goto P_0c039fda;
case 0x0c039fdcu: goto P_0c039fdc;
case 0x0c039fdeu: goto P_0c039fde;
case 0x0c039fe0u: goto P_0c039fe0;
case 0x0c039fe2u: goto P_0c039fe2;
case 0x0c039fe4u: goto P_0c039fe4;
case 0x0c039fe6u: goto P_0c039fe6;
case 0x0c039fe8u: goto P_0c039fe8;
case 0x0c039feau: goto P_0c039fea;
case 0x0c039fecu: goto P_0c039fec;
case 0x0c039feeu: goto P_0c039fee;
case 0x0c039ff0u: goto P_0c039ff0;
case 0x0c039ff2u: goto P_0c039ff2;
case 0x0c039ff4u: goto P_0c039ff4;
case 0x0c039ff6u: goto P_0c039ff6;
case 0x0c039ff8u: goto P_0c039ff8;
case 0x0c039ffau: goto P_0c039ffa;
case 0x0c039ffcu: goto P_0c039ffc;
case 0x0c039ffeu: goto P_0c039ffe;
case 0x0c03a000u: goto P_0c03a000;
case 0x0c03a002u: goto P_0c03a002;
case 0x0c03a004u: goto P_0c03a004;
case 0x0c03a006u: goto P_0c03a006;
case 0x0c03a008u: goto P_0c03a008;
case 0x0c03a00au: goto P_0c03a00a;
case 0x0c03a00cu: goto P_0c03a00c;
case 0x0c03a00eu: goto P_0c03a00e;
case 0x0c03a010u: goto P_0c03a010;
case 0x0c03a012u: goto P_0c03a012;
case 0x0c03a014u: goto P_0c03a014;
case 0x0c03a016u: goto P_0c03a016;
case 0x0c03a018u: goto P_0c03a018;
case 0x0c03a01au: goto P_0c03a01a;
case 0x0c03a01cu: goto P_0c03a01c;
case 0x0c03a01eu: goto P_0c03a01e;
case 0x0c03a020u: goto P_0c03a020;
case 0x0c03a022u: goto P_0c03a022;
case 0x0c03a024u: goto P_0c03a024;
case 0x0c03a026u: goto P_0c03a026;
case 0x0c03a028u: goto P_0c03a028;
case 0x0c03a02au: goto P_0c03a02a;
case 0x0c03a02cu: goto P_0c03a02c;
case 0x0c03a02eu: goto P_0c03a02e;
case 0x0c03a030u: goto P_0c03a030;
case 0x0c03a032u: goto P_0c03a032;
case 0x0c03a034u: goto P_0c03a034;
case 0x0c03a040u: goto P_0c03a040;
case 0x0c03a042u: goto P_0c03a042;
case 0x0c03a044u: goto P_0c03a044;
case 0x0c03a046u: goto P_0c03a046;
case 0x0c03a048u: goto P_0c03a048;
case 0x0c03a04au: goto P_0c03a04a;
case 0x0c03a04cu: goto P_0c03a04c;
case 0x0c03a04eu: goto P_0c03a04e;
case 0x0c03a050u: goto P_0c03a050;
case 0x0c03a052u: goto P_0c03a052;
case 0x0c03a054u: goto P_0c03a054;
case 0x0c03f2e0u: goto P_0c03f2e0;
case 0x0c03f2e2u: goto P_0c03f2e2;
case 0x0c03f2e4u: goto P_0c03f2e4;
case 0x0c03f2e6u: goto P_0c03f2e6;
case 0x0c03f2e8u: goto P_0c03f2e8;
case 0x0c03f2eau: goto P_0c03f2ea;
case 0x0c03f2ecu: goto P_0c03f2ec;
case 0x0c03f2eeu: goto P_0c03f2ee;
case 0x0c03f2f0u: goto P_0c03f2f0;
case 0x0c03f350u: goto P_0c03f350;
case 0x0c03f352u: goto P_0c03f352;
case 0x0c03f354u: goto P_0c03f354;
case 0x0c03f356u: goto P_0c03f356;
case 0x0c03f358u: goto P_0c03f358;
case 0x0c03f35au: goto P_0c03f35a;
case 0x0c03f35cu: goto P_0c03f35c;
case 0x0c03f35eu: goto P_0c03f35e;
case 0x0c03f360u: goto P_0c03f360;
case 0x0c03f362u: goto P_0c03f362;
case 0x0c03f364u: goto P_0c03f364;
case 0x0c03f366u: goto P_0c03f366;
case 0x0c03f368u: goto P_0c03f368;
case 0x0c03f36au: goto P_0c03f36a;
case 0x0c03f36cu: goto P_0c03f36c;
case 0x0c03f36eu: goto P_0c03f36e;
case 0x0c03f370u: goto P_0c03f370;
case 0x0c03f372u: goto P_0c03f372;
case 0x0c03f374u: goto P_0c03f374;
case 0x0c03f376u: goto P_0c03f376;
case 0x0c03f378u: goto P_0c03f378;
case 0x0c03f37au: goto P_0c03f37a;
case 0x0c03f37cu: goto P_0c03f37c;
case 0x0c03f37eu: goto P_0c03f37e;
case 0x0c03f380u: goto P_0c03f380;
case 0x0c03f390u: goto P_0c03f390;
case 0x0c03f392u: goto P_0c03f392;
case 0x0c03f394u: goto P_0c03f394;
case 0x0c03f396u: goto P_0c03f396;
case 0x0c03f398u: goto P_0c03f398;
case 0x0c03f39au: goto P_0c03f39a;
case 0x0c03f39cu: goto P_0c03f39c;
case 0x0c03f39eu: goto P_0c03f39e;
case 0x0c03f3a0u: goto P_0c03f3a0;
case 0x0c03f3a2u: goto P_0c03f3a2;
case 0x0c03f3b0u: goto P_0c03f3b0;
case 0x0c03f3b2u: goto P_0c03f3b2;
case 0x0c03f3b4u: goto P_0c03f3b4;
case 0x0c03f3b6u: goto P_0c03f3b6;
case 0x0c03f3b8u: goto P_0c03f3b8;
case 0x0c03f3bau: goto P_0c03f3ba;
case 0x0c03f3bcu: goto P_0c03f3bc;
case 0x0c03f3beu: goto P_0c03f3be;
case 0x0c03f3c0u: goto P_0c03f3c0;
case 0x0c03f3c2u: goto P_0c03f3c2;
case 0x0c03f3c4u: goto P_0c03f3c4;
case 0x0c03f3c6u: goto P_0c03f3c6;
case 0x0c03f3c8u: goto P_0c03f3c8;
case 0x0c03f3cau: goto P_0c03f3ca;
case 0x0c03f3ccu: goto P_0c03f3cc;
case 0x0c03f3ceu: goto P_0c03f3ce;
case 0x0c03f3d0u: goto P_0c03f3d0;
case 0x0c03f3d2u: goto P_0c03f3d2;
case 0x0c03f3d4u: goto P_0c03f3d4;
case 0x0c03f3d6u: goto P_0c03f3d6;
case 0x0c03f3d8u: goto P_0c03f3d8;
case 0x0c03f3dau: goto P_0c03f3da;
case 0x0c042e44u: goto P_0c042e44;
case 0x0c042e46u: goto P_0c042e46;
case 0x0c042e48u: goto P_0c042e48;
case 0x0c042e4au: goto P_0c042e4a;
case 0x0c042e4cu: goto P_0c042e4c;
case 0x0c042e4eu: goto P_0c042e4e;
case 0x0c042e50u: goto P_0c042e50;
case 0x0c042e52u: goto P_0c042e52;
case 0x0c042e54u: goto P_0c042e54;
case 0x0c042e56u: goto P_0c042e56;
case 0x0c042e58u: goto P_0c042e58;
case 0x0c042e5au: goto P_0c042e5a;
case 0x0c042e5cu: goto P_0c042e5c;
case 0x0c042e5eu: goto P_0c042e5e;
case 0x0c042e60u: goto P_0c042e60;
case 0x0c042e62u: goto P_0c042e62;
case 0x0c042e64u: goto P_0c042e64;
case 0x0c042e66u: goto P_0c042e66;
case 0x0c042e68u: goto P_0c042e68;
case 0x0c042e6au: goto P_0c042e6a;
case 0x0c042e6cu: goto P_0c042e6c;
case 0x0c042e6eu: goto P_0c042e6e;
case 0x0c042e70u: goto P_0c042e70;
case 0x0c042e72u: goto P_0c042e72;
case 0x0c042e74u: goto P_0c042e74;
case 0x0c042e76u: goto P_0c042e76;
case 0x0c042e78u: goto P_0c042e78;
case 0x0c042e7au: goto P_0c042e7a;
case 0x0c042e7cu: goto P_0c042e7c;
case 0x0c042e7eu: goto P_0c042e7e;
case 0x0c042e80u: goto P_0c042e80;
case 0x0c042e82u: goto P_0c042e82;
case 0x0c042e84u: goto P_0c042e84;
case 0x0c042e86u: goto P_0c042e86;
case 0x0c042e88u: goto P_0c042e88;
case 0x0c042e8au: goto P_0c042e8a;
case 0x0c042e8cu: goto P_0c042e8c;
case 0x0c042e8eu: goto P_0c042e8e;
case 0x0c042e90u: goto P_0c042e90;
case 0x0c042e92u: goto P_0c042e92;
case 0x0c042e94u: goto P_0c042e94;
case 0x0c042e96u: goto P_0c042e96;
case 0x0c042e98u: goto P_0c042e98;
case 0x0c042e9au: goto P_0c042e9a;
case 0x0c042e9cu: goto P_0c042e9c;
case 0x0c042e9eu: goto P_0c042e9e;
case 0x0c042ea0u: goto P_0c042ea0;
case 0x0c042ea2u: goto P_0c042ea2;
case 0x0c042ea4u: goto P_0c042ea4;
case 0x0c042ea6u: goto P_0c042ea6;
case 0x0c042ea8u: goto P_0c042ea8;
case 0x0c042eaau: goto P_0c042eaa;
case 0x0c042eacu: goto P_0c042eac;
case 0x0c042eaeu: goto P_0c042eae;
case 0x0c042eb0u: goto P_0c042eb0;
case 0x0c042eb2u: goto P_0c042eb2;
case 0x0c042eb4u: goto P_0c042eb4;
case 0x0c042eb6u: goto P_0c042eb6;
case 0x0c042eb8u: goto P_0c042eb8;
case 0x0c042ebau: goto P_0c042eba;
case 0x0c042ebcu: goto P_0c042ebc;
case 0x0c042ebeu: goto P_0c042ebe;
case 0x0c042ec0u: goto P_0c042ec0;
case 0x0c042ec2u: goto P_0c042ec2;
case 0x0c042ec4u: goto P_0c042ec4;
case 0x0c042ec6u: goto P_0c042ec6;
case 0x0c042ec8u: goto P_0c042ec8;
case 0x0c042ecau: goto P_0c042eca;
case 0x0c042eccu: goto P_0c042ecc;
case 0x0c042eceu: goto P_0c042ece;
case 0x0c042ed0u: goto P_0c042ed0;
case 0x0c042ed2u: goto P_0c042ed2;
case 0x0c042ed4u: goto P_0c042ed4;
case 0x0c042ed6u: goto P_0c042ed6;
case 0x0c042ed8u: goto P_0c042ed8;
case 0x0c042edau: goto P_0c042eda;
case 0x0c042edcu: goto P_0c042edc;
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
case 0x0c0482f0u: goto P_0c0482f0;
case 0x0c0482f2u: goto P_0c0482f2;
case 0x0c0482f4u: goto P_0c0482f4;
case 0x0c0482f6u: goto P_0c0482f6;
case 0x0c0482f8u: goto P_0c0482f8;
case 0x0c0482fau: goto P_0c0482fa;
case 0x0c0482fcu: goto P_0c0482fc;
case 0x0c0482feu: goto P_0c0482fe;
case 0x0c048300u: goto P_0c048300;
case 0x0c048302u: goto P_0c048302;
case 0x0c048304u: goto P_0c048304;
case 0x0c048306u: goto P_0c048306;
case 0x0c048308u: goto P_0c048308;
case 0x0c04830au: goto P_0c04830a;
case 0x0c04830cu: goto P_0c04830c;
case 0x0c04830eu: goto P_0c04830e;
case 0x0c048310u: goto P_0c048310;
case 0x0c048312u: goto P_0c048312;
case 0x0c048314u: goto P_0c048314;
case 0x0c048316u: goto P_0c048316;
case 0x0c048318u: goto P_0c048318;
case 0x0c04831au: goto P_0c04831a;
case 0x0c04831cu: goto P_0c04831c;
case 0x0c04831eu: goto P_0c04831e;
case 0x0c048320u: goto P_0c048320;
case 0x0c048322u: goto P_0c048322;
case 0x0c048324u: goto P_0c048324;
case 0x0c048326u: goto P_0c048326;
case 0x0c048328u: goto P_0c048328;
case 0x0c04832au: goto P_0c04832a;
case 0x0c04832cu: goto P_0c04832c;
case 0x0c04832eu: goto P_0c04832e;
case 0x0c048330u: goto P_0c048330;
case 0x0c048332u: goto P_0c048332;
case 0x0c048334u: goto P_0c048334;
case 0x0c048336u: goto P_0c048336;
case 0x0c048338u: goto P_0c048338;
case 0x0c04833au: goto P_0c04833a;
case 0x0c04833cu: goto P_0c04833c;
case 0x0c04833eu: goto P_0c04833e;
case 0x0c048340u: goto P_0c048340;
case 0x0c048342u: goto P_0c048342;
case 0x0c048344u: goto P_0c048344;
case 0x0c048346u: goto P_0c048346;
case 0x0c048348u: goto P_0c048348;
case 0x0c04834au: goto P_0c04834a;
case 0x0c04834cu: goto P_0c04834c;
case 0x0c04834eu: goto P_0c04834e;
case 0x0c048350u: goto P_0c048350;
case 0x0c048352u: goto P_0c048352;
case 0x0c048354u: goto P_0c048354;
case 0x0c048356u: goto P_0c048356;
case 0x0c048358u: goto P_0c048358;
case 0x0c04835au: goto P_0c04835a;
case 0x0c04835cu: goto P_0c04835c;
case 0x0c04835eu: goto P_0c04835e;
case 0x0c048360u: goto P_0c048360;
case 0x0c048362u: goto P_0c048362;
case 0x0c048364u: goto P_0c048364;
case 0x0c048366u: goto P_0c048366;
case 0x0c048368u: goto P_0c048368;
case 0x0c04836au: goto P_0c04836a;
case 0x0c04836cu: goto P_0c04836c;
case 0x0c04836eu: goto P_0c04836e;
case 0x0c048370u: goto P_0c048370;
case 0x0c048372u: goto P_0c048372;
case 0x0c048374u: goto P_0c048374;
case 0x0c048376u: goto P_0c048376;
case 0x0c048378u: goto P_0c048378;
case 0x0c04837au: goto P_0c04837a;
case 0x0c04837cu: goto P_0c04837c;
case 0x0c04837eu: goto P_0c04837e;
case 0x0c048380u: goto P_0c048380;
case 0x0c048382u: goto P_0c048382;
case 0x0c048384u: goto P_0c048384;
case 0x0c048386u: goto P_0c048386;
case 0x0c048388u: goto P_0c048388;
case 0x0c04838au: goto P_0c04838a;
case 0x0c04838cu: goto P_0c04838c;
case 0x0c04838eu: goto P_0c04838e;
case 0x0c048390u: goto P_0c048390;
case 0x0c048392u: goto P_0c048392;
case 0x0c048394u: goto P_0c048394;
case 0x0c048396u: goto P_0c048396;
case 0x0c048398u: goto P_0c048398;
case 0x0c04839au: goto P_0c04839a;
case 0x0c04839cu: goto P_0c04839c;
case 0x0c0483a0u: goto P_0c0483a0;
case 0x0c0483a2u: goto P_0c0483a2;
case 0x0c0483a4u: goto P_0c0483a4;
case 0x0c0483a6u: goto P_0c0483a6;
case 0x0c0483a8u: goto P_0c0483a8;
case 0x0c0483aau: goto P_0c0483aa;
case 0x0c0483acu: goto P_0c0483ac;
case 0x0c0483aeu: goto P_0c0483ae;
case 0x0c0483b0u: goto P_0c0483b0;
case 0x0c0483b2u: goto P_0c0483b2;
case 0x0c0483b4u: goto P_0c0483b4;
case 0x0c0483b6u: goto P_0c0483b6;
case 0x0c0483b8u: goto P_0c0483b8;
case 0x0c0483bau: goto P_0c0483ba;
case 0x0c0483bcu: goto P_0c0483bc;
case 0x0c0483beu: goto P_0c0483be;
case 0x0c0483c0u: goto P_0c0483c0;
case 0x0c0483c2u: goto P_0c0483c2;
case 0x0c0483c4u: goto P_0c0483c4;
case 0x0c0483c6u: goto P_0c0483c6;
case 0x0c0483c8u: goto P_0c0483c8;
case 0x0c0483cau: goto P_0c0483ca;
case 0x0c0483ccu: goto P_0c0483cc;
case 0x0c0483ceu: goto P_0c0483ce;
case 0x0c0483d0u: goto P_0c0483d0;
case 0x0c0483d2u: goto P_0c0483d2;
case 0x0c0483d4u: goto P_0c0483d4;
case 0x0c0483d6u: goto P_0c0483d6;
case 0x0c0483d8u: goto P_0c0483d8;
case 0x0c0483dau: goto P_0c0483da;
case 0x0c0483dcu: goto P_0c0483dc;
case 0x0c0483deu: goto P_0c0483de;
case 0x0c0483e0u: goto P_0c0483e0;
case 0x0c0483e2u: goto P_0c0483e2;
case 0x0c0483e4u: goto P_0c0483e4;
case 0x0c0483e6u: goto P_0c0483e6;
case 0x0c0483e8u: goto P_0c0483e8;
case 0x0c0483eau: goto P_0c0483ea;
case 0x0c0483ecu: goto P_0c0483ec;
case 0x0c0483eeu: goto P_0c0483ee;
case 0x0c0483f0u: goto P_0c0483f0;
case 0x0c0483f2u: goto P_0c0483f2;
case 0x0c0483f4u: goto P_0c0483f4;
case 0x0c0483f6u: goto P_0c0483f6;
case 0x0c0483f8u: goto P_0c0483f8;
case 0x0c0483fau: goto P_0c0483fa;
case 0x0c0483fcu: goto P_0c0483fc;
case 0x0c0483feu: goto P_0c0483fe;
case 0x0c048400u: goto P_0c048400;
case 0x0c048402u: goto P_0c048402;
case 0x0c048404u: goto P_0c048404;
case 0x0c048408u: goto P_0c048408;
case 0x0c04840au: goto P_0c04840a;
case 0x0c04840cu: goto P_0c04840c;
case 0x0c04840eu: goto P_0c04840e;
case 0x0c048410u: goto P_0c048410;
case 0x0c048412u: goto P_0c048412;
case 0x0c048414u: goto P_0c048414;
case 0x0c048416u: goto P_0c048416;
case 0x0c048418u: goto P_0c048418;
case 0x0c04841au: goto P_0c04841a;
case 0x0c04841cu: goto P_0c04841c;
case 0x0c04841eu: goto P_0c04841e;
case 0x0c048420u: goto P_0c048420;
case 0x0c048422u: goto P_0c048422;
case 0x0c048424u: goto P_0c048424;
case 0x0c048426u: goto P_0c048426;
case 0x0c048428u: goto P_0c048428;
case 0x0c04842au: goto P_0c04842a;
case 0x0c04842cu: goto P_0c04842c;
case 0x0c04842eu: goto P_0c04842e;
case 0x0c048430u: goto P_0c048430;
case 0x0c048432u: goto P_0c048432;
case 0x0c048434u: goto P_0c048434;
case 0x0c048436u: goto P_0c048436;
case 0x0c048438u: goto P_0c048438;
case 0x0c04843au: goto P_0c04843a;
case 0x0c04843cu: goto P_0c04843c;
case 0x0c04843eu: goto P_0c04843e;
case 0x0c048440u: goto P_0c048440;
case 0x0c048442u: goto P_0c048442;
case 0x0c048444u: goto P_0c048444;
case 0x0c048446u: goto P_0c048446;
case 0x0c048448u: goto P_0c048448;
case 0x0c04844au: goto P_0c04844a;
case 0x0c04844cu: goto P_0c04844c;
case 0x0c04844eu: goto P_0c04844e;
case 0x0c048450u: goto P_0c048450;
case 0x0c048452u: goto P_0c048452;
case 0x0c048454u: goto P_0c048454;
case 0x0c048456u: goto P_0c048456;
case 0x0c048458u: goto P_0c048458;
case 0x0c04845au: goto P_0c04845a;
case 0x0c04845cu: goto P_0c04845c;
case 0x0c04845eu: goto P_0c04845e;
case 0x0c048460u: goto P_0c048460;
case 0x0c048462u: goto P_0c048462;
case 0x0c048464u: goto P_0c048464;
case 0x0c048466u: goto P_0c048466;
case 0x0c048468u: goto P_0c048468;
case 0x0c04846au: goto P_0c04846a;
case 0x0c04846cu: goto P_0c04846c;
case 0x0c04846eu: goto P_0c04846e;
case 0x0c048470u: goto P_0c048470;
case 0x0c048472u: goto P_0c048472;
case 0x0c048474u: goto P_0c048474;
case 0x0c048476u: goto P_0c048476;
case 0x0c048478u: goto P_0c048478;
case 0x0c04847au: goto P_0c04847a;
case 0x0c04847cu: goto P_0c04847c;
case 0x0c04847eu: goto P_0c04847e;
case 0x0c048480u: goto P_0c048480;
case 0x0c048482u: goto P_0c048482;
case 0x0c048484u: goto P_0c048484;
case 0x0c048486u: goto P_0c048486;
case 0x0c048488u: goto P_0c048488;
case 0x0c04848au: goto P_0c04848a;
case 0x0c04848cu: goto P_0c04848c;
case 0x0c04848eu: goto P_0c04848e;
case 0x0c048490u: goto P_0c048490;
case 0x0c048492u: goto P_0c048492;
case 0x0c048494u: goto P_0c048494;
case 0x0c048496u: goto P_0c048496;
case 0x0c048498u: goto P_0c048498;
case 0x0c04849au: goto P_0c04849a;
case 0x0c04849cu: goto P_0c04849c;
case 0x0c04849eu: goto P_0c04849e;
case 0x0c0484a0u: goto P_0c0484a0;
case 0x0c0484a2u: goto P_0c0484a2;
case 0x0c0484a4u: goto P_0c0484a4;
case 0x0c0484a8u: goto P_0c0484a8;
case 0x0c0484aau: goto P_0c0484aa;
case 0x0c0484acu: goto P_0c0484ac;
case 0x0c0484aeu: goto P_0c0484ae;
case 0x0c0484b0u: goto P_0c0484b0;
case 0x0c0484b2u: goto P_0c0484b2;
case 0x0c0484b4u: goto P_0c0484b4;
case 0x0c0484b6u: goto P_0c0484b6;
case 0x0c0484b8u: goto P_0c0484b8;
case 0x0c0484bau: goto P_0c0484ba;
case 0x0c0484bcu: goto P_0c0484bc;
case 0x0c0484beu: goto P_0c0484be;
case 0x0c0484c0u: goto P_0c0484c0;
case 0x0c0484c4u: goto P_0c0484c4;
case 0x0c0484c6u: goto P_0c0484c6;
case 0x0c0484c8u: goto P_0c0484c8;
case 0x0c0484cau: goto P_0c0484ca;
case 0x0c0484ccu: goto P_0c0484cc;
case 0x0c0484ceu: goto P_0c0484ce;
case 0x0c0484d0u: goto P_0c0484d0;
case 0x0c0484d2u: goto P_0c0484d2;
case 0x0c0484d4u: goto P_0c0484d4;
case 0x0c0484d6u: goto P_0c0484d6;
case 0x0c0484d8u: goto P_0c0484d8;
case 0x0c0484dau: goto P_0c0484da;
case 0x0c0484dcu: goto P_0c0484dc;
case 0x0c0484deu: goto P_0c0484de;
case 0x0c0484e0u: goto P_0c0484e0;
case 0x0c0484e2u: goto P_0c0484e2;
case 0x0c0484e4u: goto P_0c0484e4;
case 0x0c0484e6u: goto P_0c0484e6;
case 0x0c0484e8u: goto P_0c0484e8;
case 0x0c0484eau: goto P_0c0484ea;
case 0x0c0484ecu: goto P_0c0484ec;
case 0x0c0484eeu: goto P_0c0484ee;
case 0x0c0484f0u: goto P_0c0484f0;
case 0x0c0484f4u: goto P_0c0484f4;
case 0x0c0484f6u: goto P_0c0484f6;
case 0x0c0484f8u: goto P_0c0484f8;
case 0x0c0484fau: goto P_0c0484fa;
case 0x0c0484fcu: goto P_0c0484fc;
case 0x0c0484feu: goto P_0c0484fe;
case 0x0c048500u: goto P_0c048500;
case 0x0c048502u: goto P_0c048502;
case 0x0c048504u: goto P_0c048504;
case 0x0c048506u: goto P_0c048506;
case 0x0c048508u: goto P_0c048508;
case 0x0c04850au: goto P_0c04850a;
case 0x0c04850cu: goto P_0c04850c;
case 0x0c04850eu: goto P_0c04850e;
case 0x0c048510u: goto P_0c048510;
case 0x0c048512u: goto P_0c048512;
case 0x0c048514u: goto P_0c048514;
case 0x0c048516u: goto P_0c048516;
case 0x0c048518u: goto P_0c048518;
case 0x0c04851au: goto P_0c04851a;
case 0x0c04851cu: goto P_0c04851c;
case 0x0c04851eu: goto P_0c04851e;
case 0x0c048520u: goto P_0c048520;
case 0x0c048522u: goto P_0c048522;
case 0x0c048524u: goto P_0c048524;
case 0x0c048526u: goto P_0c048526;
case 0x0c048528u: goto P_0c048528;
case 0x0c04852au: goto P_0c04852a;
case 0x0c04852cu: goto P_0c04852c;
case 0x0c04852eu: goto P_0c04852e;
case 0x0c048530u: goto P_0c048530;
case 0x0c048532u: goto P_0c048532;
case 0x0c048534u: goto P_0c048534;
case 0x0c048536u: goto P_0c048536;
case 0x0c048538u: goto P_0c048538;
case 0x0c04853au: goto P_0c04853a;
case 0x0c04853cu: goto P_0c04853c;
case 0x0c04853eu: goto P_0c04853e;
case 0x0c048540u: goto P_0c048540;
case 0x0c048542u: goto P_0c048542;
case 0x0c048544u: goto P_0c048544;
case 0x0c048546u: goto P_0c048546;
case 0x0c048548u: goto P_0c048548;
case 0x0c04854au: goto P_0c04854a;
case 0x0c04854cu: goto P_0c04854c;
case 0x0c04854eu: goto P_0c04854e;
case 0x0c048550u: goto P_0c048550;
case 0x0c048552u: goto P_0c048552;
case 0x0c048554u: goto P_0c048554;
case 0x0c048556u: goto P_0c048556;
case 0x0c048558u: goto P_0c048558;
case 0x0c04855au: goto P_0c04855a;
case 0x0c04855cu: goto P_0c04855c;
case 0x0c04855eu: goto P_0c04855e;
case 0x0c048560u: goto P_0c048560;
case 0x0c04856cu: goto P_0c04856c;
case 0x0c04856eu: goto P_0c04856e;
case 0x0c048570u: goto P_0c048570;
case 0x0c048572u: goto P_0c048572;
case 0x0c048574u: goto P_0c048574;
case 0x0c048576u: goto P_0c048576;
case 0x0c048578u: goto P_0c048578;
case 0x0c04857au: goto P_0c04857a;
case 0x0c04857cu: goto P_0c04857c;
case 0x0c04857eu: goto P_0c04857e;
case 0x0c048580u: goto P_0c048580;
case 0x0c048582u: goto P_0c048582;
case 0x0c048584u: goto P_0c048584;
case 0x0c048586u: goto P_0c048586;
case 0x0c048588u: goto P_0c048588;
case 0x0c04858au: goto P_0c04858a;
case 0x0c04858cu: goto P_0c04858c;
case 0x0c04858eu: goto P_0c04858e;
case 0x0c048590u: goto P_0c048590;
case 0x0c048592u: goto P_0c048592;
case 0x0c048594u: goto P_0c048594;
case 0x0c048596u: goto P_0c048596;
case 0x0c048598u: goto P_0c048598;
case 0x0c04859cu: goto P_0c04859c;
case 0x0c04859eu: goto P_0c04859e;
case 0x0c0485a0u: goto P_0c0485a0;
case 0x0c0485a2u: goto P_0c0485a2;
case 0x0c0485a4u: goto P_0c0485a4;
case 0x0c0485a6u: goto P_0c0485a6;
case 0x0c0485a8u: goto P_0c0485a8;
case 0x0c0485aau: goto P_0c0485aa;
case 0x0c0485acu: goto P_0c0485ac;
case 0x0c0485aeu: goto P_0c0485ae;
case 0x0c0485b0u: goto P_0c0485b0;
case 0x0c0485b2u: goto P_0c0485b2;
case 0x0c0485b4u: goto P_0c0485b4;
case 0x0c0485b6u: goto P_0c0485b6;
case 0x0c0485b8u: goto P_0c0485b8;
case 0x0c0485bcu: goto P_0c0485bc;
case 0x0c0485beu: goto P_0c0485be;
case 0x0c0487a0u: goto P_0c0487a0;
case 0x0c0487a2u: goto P_0c0487a2;
case 0x0c0487a4u: goto P_0c0487a4;
case 0x0c0487a6u: goto P_0c0487a6;
case 0x0c0487a8u: goto P_0c0487a8;
case 0x0c0487aau: goto P_0c0487aa;
case 0x0c0487acu: goto P_0c0487ac;
case 0x0c0487aeu: goto P_0c0487ae;
case 0x0c0487b0u: goto P_0c0487b0;
case 0x0c0487b2u: goto P_0c0487b2;
case 0x0c0487b4u: goto P_0c0487b4;
case 0x0c0487b6u: goto P_0c0487b6;
case 0x0c0487b8u: goto P_0c0487b8;
case 0x0c0487bau: goto P_0c0487ba;
case 0x0c0487bcu: goto P_0c0487bc;
case 0x0c0487beu: goto P_0c0487be;
case 0x0c0487c0u: goto P_0c0487c0;
case 0x0c0487c2u: goto P_0c0487c2;
case 0x0c0487c4u: goto P_0c0487c4;
case 0x0c0487c6u: goto P_0c0487c6;
case 0x0c0487c8u: goto P_0c0487c8;
case 0x0c0487cau: goto P_0c0487ca;
case 0x0c0487ccu: goto P_0c0487cc;
case 0x0c0487ceu: goto P_0c0487ce;
case 0x0c0487d0u: goto P_0c0487d0;
case 0x0c0487d2u: goto P_0c0487d2;
case 0x0c0487d4u: goto P_0c0487d4;
case 0x0c0487d6u: goto P_0c0487d6;
case 0x0c0487d8u: goto P_0c0487d8;
case 0x0c0487dau: goto P_0c0487da;
case 0x0c0487dcu: goto P_0c0487dc;
case 0x0c0487deu: goto P_0c0487de;
case 0x0c0487e0u: goto P_0c0487e0;
case 0x0c0487e2u: goto P_0c0487e2;
case 0x0c0487e4u: goto P_0c0487e4;
case 0x0c0487e6u: goto P_0c0487e6;
case 0x0c0487e8u: goto P_0c0487e8;
case 0x0c0487eau: goto P_0c0487ea;
case 0x0c0487ecu: goto P_0c0487ec;
case 0x0c0487eeu: goto P_0c0487ee;
case 0x0c0487f0u: goto P_0c0487f0;
case 0x0c0487f2u: goto P_0c0487f2;
case 0x0c0487f4u: goto P_0c0487f4;
case 0x0c0487f6u: goto P_0c0487f6;
case 0x0c0487f8u: goto P_0c0487f8;
case 0x0c0487fau: goto P_0c0487fa;
case 0x0c0487fcu: goto P_0c0487fc;
case 0x0c0487feu: goto P_0c0487fe;
case 0x0c048800u: goto P_0c048800;
case 0x0c048802u: goto P_0c048802;
case 0x0c048804u: goto P_0c048804;
case 0x0c048806u: goto P_0c048806;
case 0x0c048808u: goto P_0c048808;
case 0x0c04880au: goto P_0c04880a;
case 0x0c04880cu: goto P_0c04880c;
case 0x0c04880eu: goto P_0c04880e;
case 0x0c048810u: goto P_0c048810;
case 0x0c048812u: goto P_0c048812;
case 0x0c048814u: goto P_0c048814;
case 0x0c048816u: goto P_0c048816;
case 0x0c048818u: goto P_0c048818;
case 0x0c04881au: goto P_0c04881a;
case 0x0c04881cu: goto P_0c04881c;
case 0x0c04881eu: goto P_0c04881e;
case 0x0c048820u: goto P_0c048820;
case 0x0c048822u: goto P_0c048822;
case 0x0c048824u: goto P_0c048824;
case 0x0c048826u: goto P_0c048826;
case 0x0c048828u: goto P_0c048828;
case 0x0c04882au: goto P_0c04882a;
case 0x0c04882cu: goto P_0c04882c;
case 0x0c04882eu: goto P_0c04882e;
case 0x0c048830u: goto P_0c048830;
case 0x0c048832u: goto P_0c048832;
case 0x0c048834u: goto P_0c048834;
case 0x0c048836u: goto P_0c048836;
case 0x0c048838u: goto P_0c048838;
case 0x0c04883au: goto P_0c04883a;
case 0x0c04883cu: goto P_0c04883c;
case 0x0c04883eu: goto P_0c04883e;
case 0x0c048840u: goto P_0c048840;
case 0x0c048842u: goto P_0c048842;
case 0x0c048844u: goto P_0c048844;
case 0x0c048846u: goto P_0c048846;
case 0x0c048848u: goto P_0c048848;
case 0x0c04884au: goto P_0c04884a;
case 0x0c04884cu: goto P_0c04884c;
case 0x0c04884eu: goto P_0c04884e;
case 0x0c048850u: goto P_0c048850;
case 0x0c048852u: goto P_0c048852;
case 0x0c048854u: goto P_0c048854;
case 0x0c048856u: goto P_0c048856;
case 0x0c048858u: goto P_0c048858;
case 0x0c04885au: goto P_0c04885a;
case 0x0c04885cu: goto P_0c04885c;
case 0x0c04885eu: goto P_0c04885e;
case 0x0c048860u: goto P_0c048860;
case 0x0c048862u: goto P_0c048862;
case 0x0c048864u: goto P_0c048864;
case 0x0c048866u: goto P_0c048866;
case 0x0c048868u: goto P_0c048868;
case 0x0c04886au: goto P_0c04886a;
case 0x0c04886cu: goto P_0c04886c;
case 0x0c04886eu: goto P_0c04886e;
case 0x0c048870u: goto P_0c048870;
case 0x0c048872u: goto P_0c048872;
case 0x0c048874u: goto P_0c048874;
case 0x0c048876u: goto P_0c048876;
case 0x0c048878u: goto P_0c048878;
case 0x0c04887au: goto P_0c04887a;
case 0x0c04887cu: goto P_0c04887c;
case 0x0c0488e0u: goto P_0c0488e0;
case 0x0c0488e2u: goto P_0c0488e2;
case 0x0c0488e4u: goto P_0c0488e4;
case 0x0c048d60u: goto P_0c048d60;
case 0x0c048d62u: goto P_0c048d62;
case 0x0c048d64u: goto P_0c048d64;
case 0x0c048f60u: goto P_0c048f60;
case 0x0c048f62u: goto P_0c048f62;
case 0x0c048f64u: goto P_0c048f64;
case 0x0c048f66u: goto P_0c048f66;
case 0x0c048f68u: goto P_0c048f68;
case 0x0c048f6au: goto P_0c048f6a;
case 0x0c048f6cu: goto P_0c048f6c;
case 0x0c048f6eu: goto P_0c048f6e;
case 0x0c048f70u: goto P_0c048f70;
case 0x0c048f72u: goto P_0c048f72;
case 0x0c048f74u: goto P_0c048f74;
case 0x0c048f76u: goto P_0c048f76;
case 0x0c048f78u: goto P_0c048f78;
case 0x0c048f7au: goto P_0c048f7a;
case 0x0c048f7cu: goto P_0c048f7c;
case 0x0c048f7eu: goto P_0c048f7e;
case 0x0c048f80u: goto P_0c048f80;
case 0x0c048f82u: goto P_0c048f82;
case 0x0c048f84u: goto P_0c048f84;
case 0x0c048f86u: goto P_0c048f86;
case 0x0c048f88u: goto P_0c048f88;
case 0x0c048f8au: goto P_0c048f8a;
case 0x0c048f8cu: goto P_0c048f8c;
case 0x0c048f8eu: goto P_0c048f8e;
case 0x0c048f90u: goto P_0c048f90;
case 0x0c048f92u: goto P_0c048f92;
case 0x0c048f94u: goto P_0c048f94;
case 0x0c048f96u: goto P_0c048f96;
case 0x0c048f98u: goto P_0c048f98;
case 0x0c048f9au: goto P_0c048f9a;
case 0x0c048f9cu: goto P_0c048f9c;
case 0x0c048f9eu: goto P_0c048f9e;
case 0x0c048fa0u: goto P_0c048fa0;
case 0x0c048fa2u: goto P_0c048fa2;
case 0x0c048fa4u: goto P_0c048fa4;
case 0x0c048fa6u: goto P_0c048fa6;
case 0x0c048fa8u: goto P_0c048fa8;
case 0x0c048faau: goto P_0c048faa;
case 0x0c048facu: goto P_0c048fac;
case 0x0c048faeu: goto P_0c048fae;
case 0x0c048fb0u: goto P_0c048fb0;
case 0x0c048fb2u: goto P_0c048fb2;
case 0x0c048fb4u: goto P_0c048fb4;
case 0x0c048fb6u: goto P_0c048fb6;
case 0x0c048fb8u: goto P_0c048fb8;
case 0x0c048fbcu: goto P_0c048fbc;
case 0x0c048fbeu: goto P_0c048fbe;
case 0x0c048fc0u: goto P_0c048fc0;
case 0x0c048fc2u: goto P_0c048fc2;
case 0x0c048fc4u: goto P_0c048fc4;
case 0x0c048fc6u: goto P_0c048fc6;
case 0x0c048fc8u: goto P_0c048fc8;
case 0x0c048fcau: goto P_0c048fca;
case 0x0c048fccu: goto P_0c048fcc;
case 0x0c048fceu: goto P_0c048fce;
case 0x0c048fd0u: goto P_0c048fd0;
case 0x0c048fd2u: goto P_0c048fd2;
case 0x0c048fd4u: goto P_0c048fd4;
case 0x0c048fd6u: goto P_0c048fd6;
case 0x0c048fd8u: goto P_0c048fd8;
case 0x0c048fdau: goto P_0c048fda;
case 0x0c048fdcu: goto P_0c048fdc;
case 0x0c048fdeu: goto P_0c048fde;
case 0x0c048fe0u: goto P_0c048fe0;
case 0x0c048fe2u: goto P_0c048fe2;
case 0x0c048fe4u: goto P_0c048fe4;
case 0x0c048fe6u: goto P_0c048fe6;
case 0x0c048fe8u: goto P_0c048fe8;
case 0x0c048feau: goto P_0c048fea;
case 0x0c048fecu: goto P_0c048fec;
case 0x0c048feeu: goto P_0c048fee;
case 0x0c048ff0u: goto P_0c048ff0;
case 0x0c048ff2u: goto P_0c048ff2;
case 0x0c048ff4u: goto P_0c048ff4;
case 0x0c048ff6u: goto P_0c048ff6;
case 0x0c048ff8u: goto P_0c048ff8;
case 0x0c048ffau: goto P_0c048ffa;
case 0x0c048ffcu: goto P_0c048ffc;
case 0x0c048ffeu: goto P_0c048ffe;
case 0x0c049000u: goto P_0c049000;
case 0x0c049002u: goto P_0c049002;
case 0x0c049004u: goto P_0c049004;
case 0x0c049006u: goto P_0c049006;
case 0x0c049008u: goto P_0c049008;
case 0x0c04900au: goto P_0c04900a;
case 0x0c04900cu: goto P_0c04900c;
case 0x0c04900eu: goto P_0c04900e;
case 0x0c049010u: goto P_0c049010;
case 0x0c049012u: goto P_0c049012;
case 0x0c049014u: goto P_0c049014;
case 0x0c049016u: goto P_0c049016;
case 0x0c049018u: goto P_0c049018;
case 0x0c04901au: goto P_0c04901a;
case 0x0c04901cu: goto P_0c04901c;
case 0x0c04901eu: goto P_0c04901e;
case 0x0c049020u: goto P_0c049020;
case 0x0c049022u: goto P_0c049022;
case 0x0c049024u: goto P_0c049024;
case 0x0c049026u: goto P_0c049026;
case 0x0c049028u: goto P_0c049028;
case 0x0c04902au: goto P_0c04902a;
case 0x0c04902cu: goto P_0c04902c;
case 0x0c04902eu: goto P_0c04902e;
case 0x0c049030u: goto P_0c049030;
case 0x0c049032u: goto P_0c049032;
case 0x0c049034u: goto P_0c049034;
case 0x0c049036u: goto P_0c049036;
case 0x0c049038u: goto P_0c049038;
case 0x0c05fc9au: goto P_0c05fc9a;
case 0x0c05fc9cu: goto P_0c05fc9c;
case 0x0c05fc9eu: goto P_0c05fc9e;
case 0x0c06054cu: goto P_0c06054c;
case 0x0c06054eu: goto P_0c06054e;
case 0x0c060550u: goto P_0c060550;
case 0x0c060552u: goto P_0c060552;
case 0x0c060554u: goto P_0c060554;
case 0x0c060556u: goto P_0c060556;
case 0x0c060558u: goto P_0c060558;
case 0x0c06055au: goto P_0c06055a;
case 0x0c06055cu: goto P_0c06055c;
case 0x0c06055eu: goto P_0c06055e;
case 0x0c060560u: goto P_0c060560;
case 0x0c060562u: goto P_0c060562;
case 0x0c060564u: goto P_0c060564;
case 0x0c060566u: goto P_0c060566;
case 0x0c060568u: goto P_0c060568;
case 0x0c06056au: goto P_0c06056a;
case 0x0c06056cu: goto P_0c06056c;
case 0x0c06056eu: goto P_0c06056e;
case 0x0c060570u: goto P_0c060570;
case 0x0c060572u: goto P_0c060572;
case 0x0c060574u: goto P_0c060574;
case 0x0c060576u: goto P_0c060576;
case 0x0c060578u: goto P_0c060578;
case 0x0c06057au: goto P_0c06057a;
case 0x0c06057cu: goto P_0c06057c;
case 0x0c06057eu: goto P_0c06057e;
case 0x0c060580u: goto P_0c060580;
case 0x0c060582u: goto P_0c060582;
case 0x0c060584u: goto P_0c060584;
case 0x0c060586u: goto P_0c060586;
case 0x0c060588u: goto P_0c060588;
case 0x0c06058au: goto P_0c06058a;
case 0x0c06058cu: goto P_0c06058c;
case 0x0c06058eu: goto P_0c06058e;
case 0x0c060590u: goto P_0c060590;
case 0x0c060592u: goto P_0c060592;
case 0x0c060594u: goto P_0c060594;
case 0x0c060596u: goto P_0c060596;
case 0x0c060598u: goto P_0c060598;
case 0x0c06059au: goto P_0c06059a;
case 0x0c06059cu: goto P_0c06059c;
case 0x0c06059eu: goto P_0c06059e;
case 0x0c0605a0u: goto P_0c0605a0;
case 0x0c0605a2u: goto P_0c0605a2;
case 0x0c0605a4u: goto P_0c0605a4;
case 0x0c0605a6u: goto P_0c0605a6;
case 0x0c0605a8u: goto P_0c0605a8;
case 0x0c0605aau: goto P_0c0605aa;
case 0x0c0605acu: goto P_0c0605ac;
case 0x0c0605aeu: goto P_0c0605ae;
case 0x0c0605b0u: goto P_0c0605b0;
case 0x0c0605b2u: goto P_0c0605b2;
case 0x0c0605b4u: goto P_0c0605b4;
case 0x0c0605b6u: goto P_0c0605b6;
case 0x0c0605b8u: goto P_0c0605b8;
case 0x0c0605bau: goto P_0c0605ba;
case 0x0c0605bcu: goto P_0c0605bc;
case 0x0c0605beu: goto P_0c0605be;
case 0x0c0605c0u: goto P_0c0605c0;
case 0x0c0605c2u: goto P_0c0605c2;
case 0x0c0605c4u: goto P_0c0605c4;
case 0x0c0605c6u: goto P_0c0605c6;
case 0x0c0605c8u: goto P_0c0605c8;
case 0x0c0605cau: goto P_0c0605ca;
case 0x0c0605ccu: goto P_0c0605cc;
case 0x0c0605ceu: goto P_0c0605ce;
case 0x0c0605d0u: goto P_0c0605d0;
case 0x0c0605d2u: goto P_0c0605d2;
case 0x0c0605d4u: goto P_0c0605d4;
case 0x0c0605d6u: goto P_0c0605d6;
case 0x0c0605d8u: goto P_0c0605d8;
case 0x0c0605dau: goto P_0c0605da;
case 0x0c0605dcu: goto P_0c0605dc;
case 0x0c0605deu: goto P_0c0605de;
case 0x0c0605e0u: goto P_0c0605e0;
case 0x0c0605e2u: goto P_0c0605e2;
case 0x0c0605e4u: goto P_0c0605e4;
case 0x0c0605e6u: goto P_0c0605e6;
case 0x0c0605e8u: goto P_0c0605e8;
case 0x0c0605eau: goto P_0c0605ea;
case 0x0c0605ecu: goto P_0c0605ec;
case 0x0c0605eeu: goto P_0c0605ee;
case 0x0c0605f0u: goto P_0c0605f0;
case 0x0c0605f2u: goto P_0c0605f2;
case 0x0c0605f4u: goto P_0c0605f4;
case 0x0c0605f6u: goto P_0c0605f6;
case 0x0c0605f8u: goto P_0c0605f8;
case 0x0c0605fau: goto P_0c0605fa;
case 0x0c0605fcu: goto P_0c0605fc;
case 0x0c0605feu: goto P_0c0605fe;
case 0x0c060600u: goto P_0c060600;
case 0x0c060602u: goto P_0c060602;
case 0x0c060604u: goto P_0c060604;
case 0x0c060606u: goto P_0c060606;
case 0x0c060608u: goto P_0c060608;
case 0x0c06060au: goto P_0c06060a;
case 0x0c06060cu: goto P_0c06060c;
case 0x0c06060eu: goto P_0c06060e;
case 0x0c060610u: goto P_0c060610;
case 0x0c060612u: goto P_0c060612;
case 0x0c060614u: goto P_0c060614;
case 0x0c060616u: goto P_0c060616;
case 0x0c060618u: goto P_0c060618;
case 0x0c06061au: goto P_0c06061a;
case 0x0c06061cu: goto P_0c06061c;
case 0x0c06061eu: goto P_0c06061e;
case 0x0c060620u: goto P_0c060620;
case 0x0c060622u: goto P_0c060622;
case 0x0c060624u: goto P_0c060624;
case 0x0c060626u: goto P_0c060626;
case 0x0c060628u: goto P_0c060628;
case 0x0c06062au: goto P_0c06062a;
case 0x0c06062cu: goto P_0c06062c;
case 0x0c06062eu: goto P_0c06062e;
case 0x0c060630u: goto P_0c060630;
case 0x0c060632u: goto P_0c060632;
case 0x0c060634u: goto P_0c060634;
case 0x0c060636u: goto P_0c060636;
case 0x0c060638u: goto P_0c060638;
case 0x0c06063au: goto P_0c06063a;
case 0x0c06063cu: goto P_0c06063c;
case 0x0c06063eu: goto P_0c06063e;
case 0x0c060640u: goto P_0c060640;
case 0x0c060642u: goto P_0c060642;
case 0x0c060644u: goto P_0c060644;
case 0x0c060646u: goto P_0c060646;
case 0x0c060648u: goto P_0c060648;
case 0x0c06064au: goto P_0c06064a;
case 0x0c06064cu: goto P_0c06064c;
case 0x0c06064eu: goto P_0c06064e;
case 0x0c060650u: goto P_0c060650;
case 0x0c060652u: goto P_0c060652;
case 0x0c060654u: goto P_0c060654;
case 0x0c060656u: goto P_0c060656;
case 0x0c060658u: goto P_0c060658;
case 0x0c06065au: goto P_0c06065a;
case 0x0c06065cu: goto P_0c06065c;
case 0x0c06065eu: goto P_0c06065e;
case 0x0c060660u: goto P_0c060660;
case 0x0c060662u: goto P_0c060662;
case 0x0c060664u: goto P_0c060664;
case 0x0c060666u: goto P_0c060666;
case 0x0c060668u: goto P_0c060668;
case 0x0c06066au: goto P_0c06066a;
case 0x0c06066cu: goto P_0c06066c;
case 0x0c06066eu: goto P_0c06066e;
case 0x0c060670u: goto P_0c060670;
case 0x0c060672u: goto P_0c060672;
case 0x0c060674u: goto P_0c060674;
case 0x0c060676u: goto P_0c060676;
case 0x0c060678u: goto P_0c060678;
case 0x0c06067au: goto P_0c06067a;
case 0x0c06067cu: goto P_0c06067c;
case 0x0c06067eu: goto P_0c06067e;
case 0x0c060680u: goto P_0c060680;
case 0x0c060682u: goto P_0c060682;
case 0x0c060684u: goto P_0c060684;
case 0x0c060686u: goto P_0c060686;
case 0x0c060688u: goto P_0c060688;
case 0x0c06068au: goto P_0c06068a;
case 0x0c06068cu: goto P_0c06068c;
case 0x0c06068eu: goto P_0c06068e;
case 0x0c060690u: goto P_0c060690;
case 0x0c060692u: goto P_0c060692;
case 0x0c060694u: goto P_0c060694;
case 0x0c060696u: goto P_0c060696;
case 0x0c060698u: goto P_0c060698;
case 0x0c06069au: goto P_0c06069a;
case 0x0c06069cu: goto P_0c06069c;
case 0x0c06069eu: goto P_0c06069e;
case 0x0c0606a0u: goto P_0c0606a0;
case 0x0c0606a2u: goto P_0c0606a2;
case 0x0c0606a4u: goto P_0c0606a4;
case 0x0c0606a6u: goto P_0c0606a6;
case 0x0c0606a8u: goto P_0c0606a8;
case 0x0c0606aau: goto P_0c0606aa;
case 0x0c0606acu: goto P_0c0606ac;
case 0x0c0606aeu: goto P_0c0606ae;
case 0x0c0606b0u: goto P_0c0606b0;
case 0x0c0606b2u: goto P_0c0606b2;
case 0x0c0606b4u: goto P_0c0606b4;
case 0x0c0606b6u: goto P_0c0606b6;
case 0x0c0606b8u: goto P_0c0606b8;
case 0x0c0606bau: goto P_0c0606ba;
case 0x0c0606bcu: goto P_0c0606bc;
case 0x0c0606beu: goto P_0c0606be;
case 0x0c0606c0u: goto P_0c0606c0;
case 0x0c0606c2u: goto P_0c0606c2;
case 0x0c060710u: goto P_0c060710;
case 0x0c060712u: goto P_0c060712;
case 0x0c060714u: goto P_0c060714;
case 0x0c060716u: goto P_0c060716;
case 0x0c060718u: goto P_0c060718;
case 0x0c06071au: goto P_0c06071a;
case 0x0c06071cu: goto P_0c06071c;
case 0x0c06071eu: goto P_0c06071e;
case 0x0c060720u: goto P_0c060720;
case 0x0c060722u: goto P_0c060722;
case 0x0c060724u: goto P_0c060724;
case 0x0c060726u: goto P_0c060726;
case 0x0c060728u: goto P_0c060728;
case 0x0c06072au: goto P_0c06072a;
case 0x0c06072cu: goto P_0c06072c;
case 0x0c06072eu: goto P_0c06072e;
case 0x0c060730u: goto P_0c060730;
case 0x0c060732u: goto P_0c060732;
case 0x0c060734u: goto P_0c060734;
case 0x0c060736u: goto P_0c060736;
case 0x0c060738u: goto P_0c060738;
case 0x0c06073au: goto P_0c06073a;
case 0x0c06073cu: goto P_0c06073c;
case 0x0c06073eu: goto P_0c06073e;
case 0x0c060740u: goto P_0c060740;
case 0x0c060742u: goto P_0c060742;
case 0x0c060744u: goto P_0c060744;
case 0x0c060746u: goto P_0c060746;
case 0x0c060748u: goto P_0c060748;
case 0x0c06074au: goto P_0c06074a;
case 0x0c06074cu: goto P_0c06074c;
case 0x0c06074eu: goto P_0c06074e;
case 0x0c060750u: goto P_0c060750;
case 0x0c060752u: goto P_0c060752;
case 0x0c060754u: goto P_0c060754;
case 0x0c060756u: goto P_0c060756;
case 0x0c060758u: goto P_0c060758;
case 0x0c06075au: goto P_0c06075a;
case 0x0c06075cu: goto P_0c06075c;
case 0x0c06075eu: goto P_0c06075e;
case 0x0c060760u: goto P_0c060760;
case 0x0c060762u: goto P_0c060762;
case 0x0c060764u: goto P_0c060764;
case 0x0c060766u: goto P_0c060766;
case 0x0c060768u: goto P_0c060768;
case 0x0c06076au: goto P_0c06076a;
case 0x0c06076cu: goto P_0c06076c;
case 0x0c06076eu: goto P_0c06076e;
case 0x0c060770u: goto P_0c060770;
case 0x0c060772u: goto P_0c060772;
case 0x0c060774u: goto P_0c060774;
case 0x0c060776u: goto P_0c060776;
case 0x0c060778u: goto P_0c060778;
case 0x0c06077au: goto P_0c06077a;
case 0x0c06077cu: goto P_0c06077c;
case 0x0c06077eu: goto P_0c06077e;
case 0x0c060780u: goto P_0c060780;
case 0x0c060782u: goto P_0c060782;
case 0x0c060784u: goto P_0c060784;
case 0x0c060786u: goto P_0c060786;
case 0x0c060788u: goto P_0c060788;
case 0x0c06078au: goto P_0c06078a;
case 0x0c06078cu: goto P_0c06078c;
case 0x0c06078eu: goto P_0c06078e;
case 0x0c060790u: goto P_0c060790;
case 0x0c060792u: goto P_0c060792;
case 0x0c060794u: goto P_0c060794;
case 0x0c060796u: goto P_0c060796;
case 0x0c060798u: goto P_0c060798;
case 0x0c06079au: goto P_0c06079a;
case 0x0c0609b8u: goto P_0c0609b8;
case 0x0c0609bau: goto P_0c0609ba;
case 0x0c0609bcu: goto P_0c0609bc;
case 0x0c0609beu: goto P_0c0609be;
case 0x0c0609c0u: goto P_0c0609c0;
case 0x0c0609c2u: goto P_0c0609c2;
case 0x0c0609c4u: goto P_0c0609c4;
case 0x0c0609c6u: goto P_0c0609c6;
case 0x0c0609c8u: goto P_0c0609c8;
case 0x0c0609cau: goto P_0c0609ca;
case 0x0c0609ccu: goto P_0c0609cc;
case 0x0c0609ceu: goto P_0c0609ce;
case 0x0c0609d0u: goto P_0c0609d0;
case 0x0c0609d2u: goto P_0c0609d2;
case 0x0c0609d4u: goto P_0c0609d4;
case 0x0c0609d6u: goto P_0c0609d6;
case 0x0c0609d8u: goto P_0c0609d8;
case 0x0c0609dau: goto P_0c0609da;
case 0x0c0609dcu: goto P_0c0609dc;
case 0x0c0609deu: goto P_0c0609de;
case 0x0c0609e0u: goto P_0c0609e0;
case 0x0c0609e2u: goto P_0c0609e2;
case 0x0c0609e4u: goto P_0c0609e4;
case 0x0c0609e6u: goto P_0c0609e6;
case 0x0c0609e8u: goto P_0c0609e8;
case 0x0c0609eau: goto P_0c0609ea;
case 0x0c0609ecu: goto P_0c0609ec;
case 0x0c0609eeu: goto P_0c0609ee;
case 0x0c0609f0u: goto P_0c0609f0;
case 0x0c0609f2u: goto P_0c0609f2;
case 0x0c0609f4u: goto P_0c0609f4;
case 0x0c0609f6u: goto P_0c0609f6;
case 0x0c0609f8u: goto P_0c0609f8;
case 0x0c0609fau: goto P_0c0609fa;
case 0x0c0609fcu: goto P_0c0609fc;
case 0x0c0609feu: goto P_0c0609fe;
case 0x0c060a00u: goto P_0c060a00;
case 0x0c060a02u: goto P_0c060a02;
case 0x0c060a04u: goto P_0c060a04;
case 0x0c060a06u: goto P_0c060a06;
case 0x0c060a08u: goto P_0c060a08;
case 0x0c060a0au: goto P_0c060a0a;
case 0x0c060a0cu: goto P_0c060a0c;
case 0x0c060a0eu: goto P_0c060a0e;
case 0x0c060a10u: goto P_0c060a10;
case 0x0c060a12u: goto P_0c060a12;
case 0x0c060a14u: goto P_0c060a14;
case 0x0c060a16u: goto P_0c060a16;
case 0x0c060a18u: goto P_0c060a18;
case 0x0c060a1au: goto P_0c060a1a;
case 0x0c060a1cu: goto P_0c060a1c;
case 0x0c060a1eu: goto P_0c060a1e;
case 0x0c060a20u: goto P_0c060a20;
case 0x0c060a22u: goto P_0c060a22;
case 0x0c060a24u: goto P_0c060a24;
case 0x0c060a26u: goto P_0c060a26;
case 0x0c060a28u: goto P_0c060a28;
case 0x0c060a2au: goto P_0c060a2a;
case 0x0c060a2cu: goto P_0c060a2c;
case 0x0c060a2eu: goto P_0c060a2e;
case 0x0c060a30u: goto P_0c060a30;
case 0x0c060a32u: goto P_0c060a32;
case 0x0c060a34u: goto P_0c060a34;
case 0x0c060a36u: goto P_0c060a36;
case 0x0c060a38u: goto P_0c060a38;
case 0x0c060a3au: goto P_0c060a3a;
case 0x0c060a3cu: goto P_0c060a3c;
case 0x0c060a3eu: goto P_0c060a3e;
case 0x0c060a40u: goto P_0c060a40;
case 0x0c060a42u: goto P_0c060a42;
case 0x0c060a44u: goto P_0c060a44;
case 0x0c060a46u: goto P_0c060a46;
case 0x0c060a48u: goto P_0c060a48;
case 0x0c060a4au: goto P_0c060a4a;
case 0x0c060a78u: goto P_0c060a78;
case 0x0c060a7au: goto P_0c060a7a;
case 0x0c060a7cu: goto P_0c060a7c;
case 0x0c060a7eu: goto P_0c060a7e;
case 0x0c060a80u: goto P_0c060a80;
case 0x0c060a82u: goto P_0c060a82;
case 0x0c060a84u: goto P_0c060a84;
case 0x0c060a86u: goto P_0c060a86;
case 0x0c060a88u: goto P_0c060a88;
case 0x0c060a8au: goto P_0c060a8a;
case 0x0c060a8cu: goto P_0c060a8c;
case 0x0c060a8eu: goto P_0c060a8e;
case 0x0c060a90u: goto P_0c060a90;
case 0x0c060a92u: goto P_0c060a92;
case 0x0c060a94u: goto P_0c060a94;
case 0x0c060a96u: goto P_0c060a96;
case 0x0c060a98u: goto P_0c060a98;
case 0x0c060a9au: goto P_0c060a9a;
case 0x0c060a9cu: goto P_0c060a9c;
case 0x0c060a9eu: goto P_0c060a9e;
case 0x0c060aa0u: goto P_0c060aa0;
case 0x0c060aa2u: goto P_0c060aa2;
case 0x0c060aa4u: goto P_0c060aa4;
case 0x0c060aa6u: goto P_0c060aa6;
case 0x0c060aa8u: goto P_0c060aa8;
case 0x0c060aaau: goto P_0c060aaa;
case 0x0c060aacu: goto P_0c060aac;
case 0x0c060aaeu: goto P_0c060aae;
case 0x0c060ab0u: goto P_0c060ab0;
case 0x0c060ab2u: goto P_0c060ab2;
case 0x0c060ab4u: goto P_0c060ab4;
case 0x0c060ab6u: goto P_0c060ab6;
case 0x0c060ab8u: goto P_0c060ab8;
case 0x0c060abau: goto P_0c060aba;
case 0x0c060abcu: goto P_0c060abc;
case 0x0c060abeu: goto P_0c060abe;
case 0x0c060ac0u: goto P_0c060ac0;
case 0x0c060ac2u: goto P_0c060ac2;
case 0x0c060ac4u: goto P_0c060ac4;
case 0x0c060ac6u: goto P_0c060ac6;
case 0x0c060ac8u: goto P_0c060ac8;
case 0x0c060acau: goto P_0c060aca;
case 0x0c060accu: goto P_0c060acc;
case 0x0c060aceu: goto P_0c060ace;
case 0x0c060ad0u: goto P_0c060ad0;
case 0x0c060ad2u: goto P_0c060ad2;
case 0x0c060ad4u: goto P_0c060ad4;
case 0x0c060ad6u: goto P_0c060ad6;
case 0x0c060ad8u: goto P_0c060ad8;
case 0x0c060adau: goto P_0c060ada;
case 0x0c060adcu: goto P_0c060adc;
case 0x0c060adeu: goto P_0c060ade;
case 0x0c060ae0u: goto P_0c060ae0;
case 0x0c060ae2u: goto P_0c060ae2;
case 0x0c060ae4u: goto P_0c060ae4;
case 0x0c060ae6u: goto P_0c060ae6;
case 0x0c060ae8u: goto P_0c060ae8;
case 0x0c060aeau: goto P_0c060aea;
case 0x0c060aecu: goto P_0c060aec;
case 0x0c060aeeu: goto P_0c060aee;
case 0x0c060af0u: goto P_0c060af0;
case 0x0c060af2u: goto P_0c060af2;
case 0x0c060af4u: goto P_0c060af4;
case 0x0c060af6u: goto P_0c060af6;
case 0x0c060af8u: goto P_0c060af8;
case 0x0c060afau: goto P_0c060afa;
case 0x0c060afcu: goto P_0c060afc;
case 0x0c060afeu: goto P_0c060afe;
case 0x0c060b00u: goto P_0c060b00;
case 0x0c060b02u: goto P_0c060b02;
case 0x0c060b04u: goto P_0c060b04;
case 0x0c060b06u: goto P_0c060b06;
case 0x0c060b08u: goto P_0c060b08;
case 0x0c060b0au: goto P_0c060b0a;
case 0x0c060b0cu: goto P_0c060b0c;
case 0x0c060b0eu: goto P_0c060b0e;
case 0x0c060b10u: goto P_0c060b10;
case 0x0c060b12u: goto P_0c060b12;
case 0x0c060b14u: goto P_0c060b14;
case 0x0c060b16u: goto P_0c060b16;
case 0x0c060b18u: goto P_0c060b18;
case 0x0c060b1au: goto P_0c060b1a;
case 0x0c060b1cu: goto P_0c060b1c;
case 0x0c060b2cu: goto P_0c060b2c;
case 0x0c060b2eu: goto P_0c060b2e;
case 0x0c060b30u: goto P_0c060b30;
case 0x0c060b32u: goto P_0c060b32;
case 0x0c060b34u: goto P_0c060b34;
case 0x0c060b36u: goto P_0c060b36;
case 0x0c060b38u: goto P_0c060b38;
case 0x0c060b3au: goto P_0c060b3a;
case 0x0c060b3cu: goto P_0c060b3c;
case 0x0c060b3eu: goto P_0c060b3e;
case 0x0c060b40u: goto P_0c060b40;
case 0x0c060b42u: goto P_0c060b42;
case 0x0c060b44u: goto P_0c060b44;
case 0x0c060b46u: goto P_0c060b46;
case 0x0c060b48u: goto P_0c060b48;
case 0x0c060b4au: goto P_0c060b4a;
case 0x0c060b4cu: goto P_0c060b4c;
case 0x0c060b4eu: goto P_0c060b4e;
case 0x0c060b50u: goto P_0c060b50;
case 0x0c060b52u: goto P_0c060b52;
case 0x0c060b54u: goto P_0c060b54;
case 0x0c060b56u: goto P_0c060b56;
case 0x0c060b58u: goto P_0c060b58;
case 0x0c060b5au: goto P_0c060b5a;
case 0x0c060b5cu: goto P_0c060b5c;
case 0x0c060b5eu: goto P_0c060b5e;
case 0x0c060b60u: goto P_0c060b60;
case 0x0c060b62u: goto P_0c060b62;
case 0x0c060b64u: goto P_0c060b64;
case 0x0c060b66u: goto P_0c060b66;
case 0x0c060b68u: goto P_0c060b68;
case 0x0c060b6au: goto P_0c060b6a;
case 0x0c060b6cu: goto P_0c060b6c;
case 0x0c060b6eu: goto P_0c060b6e;
case 0x0c060b70u: goto P_0c060b70;
case 0x0c060b72u: goto P_0c060b72;
case 0x0c060b74u: goto P_0c060b74;
case 0x0c060b76u: goto P_0c060b76;
case 0x0c060b78u: goto P_0c060b78;
case 0x0c060b7au: goto P_0c060b7a;
case 0x0c060b7cu: goto P_0c060b7c;
case 0x0c060b7eu: goto P_0c060b7e;
case 0x0c060b80u: goto P_0c060b80;
case 0x0c060b82u: goto P_0c060b82;
case 0x0c060b84u: goto P_0c060b84;
case 0x0c060b86u: goto P_0c060b86;
case 0x0c060b88u: goto P_0c060b88;
case 0x0c060b8au: goto P_0c060b8a;
case 0x0c060b8cu: goto P_0c060b8c;
case 0x0c060b8eu: goto P_0c060b8e;
case 0x0c060b90u: goto P_0c060b90;
case 0x0c060b92u: goto P_0c060b92;
case 0x0c060b94u: goto P_0c060b94;
case 0x0c060b96u: goto P_0c060b96;
case 0x0c060b98u: goto P_0c060b98;
case 0x0c060b9au: goto P_0c060b9a;
case 0x0c060b9cu: goto P_0c060b9c;
case 0x0c060b9eu: goto P_0c060b9e;
case 0x0c060ba0u: goto P_0c060ba0;
case 0x0c060ba2u: goto P_0c060ba2;
case 0x0c060ba4u: goto P_0c060ba4;
case 0x0c060ba6u: goto P_0c060ba6;
case 0x0c060ba8u: goto P_0c060ba8;
case 0x0c060baau: goto P_0c060baa;
case 0x0c060bacu: goto P_0c060bac;
case 0x0c060baeu: goto P_0c060bae;
case 0x0c060bb0u: goto P_0c060bb0;
case 0x0c060bb2u: goto P_0c060bb2;
case 0x0c060bb4u: goto P_0c060bb4;
case 0x0c060bb6u: goto P_0c060bb6;
case 0x0c060bb8u: goto P_0c060bb8;
case 0x0c060bbau: goto P_0c060bba;
case 0x0c060bbcu: goto P_0c060bbc;
case 0x0c060bbeu: goto P_0c060bbe;
case 0x0c060bc0u: goto P_0c060bc0;
case 0x0c060bc2u: goto P_0c060bc2;
case 0x0c060bc4u: goto P_0c060bc4;
case 0x0c060bc6u: goto P_0c060bc6;
case 0x0c060bc8u: goto P_0c060bc8;
case 0x0c060bcau: goto P_0c060bca;
case 0x0c060bccu: goto P_0c060bcc;
case 0x0c060bceu: goto P_0c060bce;
case 0x0c060bd0u: goto P_0c060bd0;
case 0x0c060bd2u: goto P_0c060bd2;
case 0x0c060bd4u: goto P_0c060bd4;
case 0x0c060bd6u: goto P_0c060bd6;
case 0x0c0711b0u: goto P_0c0711b0;
case 0x0c0711b2u: goto P_0c0711b2;
case 0x0c0711b4u: goto P_0c0711b4;
case 0x0c0711b6u: goto P_0c0711b6;
case 0x0c0711b8u: goto P_0c0711b8;
case 0x0c0711bau: goto P_0c0711ba;
case 0x0c0711bcu: goto P_0c0711bc;
case 0x0c0711beu: goto P_0c0711be;
case 0x0c0711c0u: goto P_0c0711c0;
case 0x0c0711c2u: goto P_0c0711c2;
case 0x0c0711c4u: goto P_0c0711c4;
case 0x0c0711c6u: goto P_0c0711c6;
case 0x0c0711c8u: goto P_0c0711c8;
case 0x0c0711cau: goto P_0c0711ca;
case 0x0c0711ccu: goto P_0c0711cc;
case 0x0c0711ceu: goto P_0c0711ce;
case 0x0c0711d0u: goto P_0c0711d0;
case 0x0c0711d2u: goto P_0c0711d2;
case 0x0c0711d4u: goto P_0c0711d4;
case 0x0c0711d6u: goto P_0c0711d6;
case 0x0c0711d8u: goto P_0c0711d8;
case 0x0c0711dau: goto P_0c0711da;
case 0x0c0711dcu: goto P_0c0711dc;
case 0x0c0711deu: goto P_0c0711de;
case 0x0c0711e4u: goto P_0c0711e4;
case 0x0c0711e6u: goto P_0c0711e6;
case 0x0c0711e8u: goto P_0c0711e8;
case 0x0c0711eau: goto P_0c0711ea;
case 0x0c0711ecu: goto P_0c0711ec;
case 0x0c0711eeu: goto P_0c0711ee;
case 0x0c0711f0u: goto P_0c0711f0;
case 0x0c0711f2u: goto P_0c0711f2;
case 0x0c0711f4u: goto P_0c0711f4;
case 0x0c0711f6u: goto P_0c0711f6;
case 0x0c0711f8u: goto P_0c0711f8;
case 0x0c0711fau: goto P_0c0711fa;
case 0x0c0711fcu: goto P_0c0711fc;
case 0x0c0711feu: goto P_0c0711fe;
case 0x0c071200u: goto P_0c071200;
case 0x0c071202u: goto P_0c071202;
case 0x0c071204u: goto P_0c071204;
case 0x0c071206u: goto P_0c071206;
case 0x0c071208u: goto P_0c071208;
case 0x0c07120au: goto P_0c07120a;
case 0x0c07120cu: goto P_0c07120c;
case 0x0c07120eu: goto P_0c07120e;
case 0x0c071210u: goto P_0c071210;
case 0x0c071212u: goto P_0c071212;
case 0x0c071214u: goto P_0c071214;
case 0x0c071216u: goto P_0c071216;
case 0x0c071218u: goto P_0c071218;
case 0x0c07121au: goto P_0c07121a;
case 0x0c07121cu: goto P_0c07121c;
case 0x0c07121eu: goto P_0c07121e;
case 0x0c071220u: goto P_0c071220;
case 0x0c071222u: goto P_0c071222;
case 0x0c071224u: goto P_0c071224;
case 0x0c071226u: goto P_0c071226;
case 0x0c071228u: goto P_0c071228;
case 0x0c071230u: goto P_0c071230;
case 0x0c071232u: goto P_0c071232;
case 0x0c071234u: goto P_0c071234;
case 0x0c071236u: goto P_0c071236;
case 0x0c071238u: goto P_0c071238;
case 0x0c07123au: goto P_0c07123a;
case 0x0c07123cu: goto P_0c07123c;
case 0x0c07123eu: goto P_0c07123e;
case 0x0c071240u: goto P_0c071240;
case 0x0c071242u: goto P_0c071242;
case 0x0c071244u: goto P_0c071244;
case 0x0c071246u: goto P_0c071246;
case 0x0c071248u: goto P_0c071248;
case 0x0c07124au: goto P_0c07124a;
case 0x0c07124cu: goto P_0c07124c;
case 0x0c07124eu: goto P_0c07124e;
case 0x0c071250u: goto P_0c071250;
case 0x0c071252u: goto P_0c071252;
case 0x0c071254u: goto P_0c071254;
case 0x0c071256u: goto P_0c071256;
case 0x0c071258u: goto P_0c071258;
case 0x0c07125au: goto P_0c07125a;
case 0x0c07125cu: goto P_0c07125c;
case 0x0c07125eu: goto P_0c07125e;
case 0x0c071260u: goto P_0c071260;
case 0x0c071262u: goto P_0c071262;
case 0x0c071264u: goto P_0c071264;
case 0x0c071266u: goto P_0c071266;
case 0x0c071268u: goto P_0c071268;
case 0x0c071274u: goto P_0c071274;
case 0x0c071276u: goto P_0c071276;
case 0x0c071278u: goto P_0c071278;
case 0x0c07127au: goto P_0c07127a;
case 0x0c07127cu: goto P_0c07127c;
case 0x0c07127eu: goto P_0c07127e;
case 0x0c071280u: goto P_0c071280;
case 0x0c071282u: goto P_0c071282;
case 0x0c071284u: goto P_0c071284;
case 0x0c071286u: goto P_0c071286;
case 0x0c071288u: goto P_0c071288;
case 0x0c07128au: goto P_0c07128a;
case 0x0c07128cu: goto P_0c07128c;
case 0x0c07128eu: goto P_0c07128e;
case 0x0c071290u: goto P_0c071290;
case 0x0c071292u: goto P_0c071292;
case 0x0c071294u: goto P_0c071294;
case 0x0c071428u: goto P_0c071428;
case 0x0c07142au: goto P_0c07142a;
case 0x0c07142cu: goto P_0c07142c;
case 0x0c07142eu: goto P_0c07142e;
case 0x0c071430u: goto P_0c071430;
case 0x0c071432u: goto P_0c071432;
case 0x0c071434u: goto P_0c071434;
case 0x0c071436u: goto P_0c071436;
case 0x0c071438u: goto P_0c071438;
case 0x0c07143au: goto P_0c07143a;
case 0x0c07143cu: goto P_0c07143c;
case 0x0c07143eu: goto P_0c07143e;
case 0x0c071440u: goto P_0c071440;
case 0x0c071442u: goto P_0c071442;
case 0x0c071444u: goto P_0c071444;
case 0x0c071446u: goto P_0c071446;
case 0x0c071448u: goto P_0c071448;
case 0x0c07144au: goto P_0c07144a;
case 0x0c07144cu: goto P_0c07144c;
case 0x0c07144eu: goto P_0c07144e;
case 0x0c071450u: goto P_0c071450;
case 0x0c071452u: goto P_0c071452;
case 0x0c071454u: goto P_0c071454;
case 0x0c071456u: goto P_0c071456;
case 0x0c07145cu: goto P_0c07145c;
case 0x0c07145eu: goto P_0c07145e;
case 0x0c071460u: goto P_0c071460;
case 0x0c071462u: goto P_0c071462;
case 0x0c071464u: goto P_0c071464;
case 0x0c071466u: goto P_0c071466;
case 0x0c071468u: goto P_0c071468;
case 0x0c07146au: goto P_0c07146a;
case 0x0c07146cu: goto P_0c07146c;
case 0x0c07146eu: goto P_0c07146e;
case 0x0c071470u: goto P_0c071470;
case 0x0c071472u: goto P_0c071472;
case 0x0c071474u: goto P_0c071474;
case 0x0c071476u: goto P_0c071476;
case 0x0c071478u: goto P_0c071478;
case 0x0c07147au: goto P_0c07147a;
case 0x0c07147cu: goto P_0c07147c;
case 0x0c07147eu: goto P_0c07147e;
case 0x0c071480u: goto P_0c071480;
case 0x0c071482u: goto P_0c071482;
case 0x0c071484u: goto P_0c071484;
case 0x0c071486u: goto P_0c071486;
case 0x0c071488u: goto P_0c071488;
case 0x0c07148au: goto P_0c07148a;
case 0x0c07148cu: goto P_0c07148c;
case 0x0c07148eu: goto P_0c07148e;
case 0x0c071490u: goto P_0c071490;
case 0x0c071492u: goto P_0c071492;
case 0x0c071494u: goto P_0c071494;
case 0x0c071496u: goto P_0c071496;
case 0x0c071498u: goto P_0c071498;
case 0x0c07149au: goto P_0c07149a;
case 0x0c07149cu: goto P_0c07149c;
case 0x0c07149eu: goto P_0c07149e;
case 0x0c0714a0u: goto P_0c0714a0;
case 0x0c0714a8u: goto P_0c0714a8;
case 0x0c0714aau: goto P_0c0714aa;
case 0x0c0714acu: goto P_0c0714ac;
case 0x0c0714aeu: goto P_0c0714ae;
case 0x0c0714b0u: goto P_0c0714b0;
case 0x0c0714b2u: goto P_0c0714b2;
case 0x0c0714b4u: goto P_0c0714b4;
case 0x0c0714b6u: goto P_0c0714b6;
case 0x0c0714b8u: goto P_0c0714b8;
case 0x0c0714bau: goto P_0c0714ba;
case 0x0c0714bcu: goto P_0c0714bc;
case 0x0c0714beu: goto P_0c0714be;
case 0x0c0714c0u: goto P_0c0714c0;
case 0x0c0714c2u: goto P_0c0714c2;
case 0x0c0714c4u: goto P_0c0714c4;
case 0x0c0714c6u: goto P_0c0714c6;
case 0x0c0714c8u: goto P_0c0714c8;
case 0x0c0714cau: goto P_0c0714ca;
case 0x0c0714ccu: goto P_0c0714cc;
case 0x0c0714ceu: goto P_0c0714ce;
case 0x0c0714d0u: goto P_0c0714d0;
case 0x0c0714d2u: goto P_0c0714d2;
case 0x0c0714d4u: goto P_0c0714d4;
case 0x0c0714d6u: goto P_0c0714d6;
case 0x0c0714d8u: goto P_0c0714d8;
case 0x0c0714dau: goto P_0c0714da;
case 0x0c0714dcu: goto P_0c0714dc;
case 0x0c0714deu: goto P_0c0714de;
case 0x0c0714e0u: goto P_0c0714e0;
case 0x0c0714ecu: goto P_0c0714ec;
case 0x0c0714eeu: goto P_0c0714ee;
case 0x0c0714f0u: goto P_0c0714f0;
case 0x0c0714f2u: goto P_0c0714f2;
case 0x0c0714f4u: goto P_0c0714f4;
case 0x0c0714f6u: goto P_0c0714f6;
case 0x0c0714f8u: goto P_0c0714f8;
case 0x0c0714fau: goto P_0c0714fa;
case 0x0c0714fcu: goto P_0c0714fc;
case 0x0c0714feu: goto P_0c0714fe;
case 0x0c071500u: goto P_0c071500;
case 0x0c071502u: goto P_0c071502;
case 0x0c071504u: goto P_0c071504;
case 0x0c071506u: goto P_0c071506;
case 0x0c071508u: goto P_0c071508;
case 0x0c07150au: goto P_0c07150a;
case 0x0c07150cu: goto P_0c07150c;
case 0x0c072162u: goto P_0c072162;
case 0x0c072164u: goto P_0c072164;
case 0x0c072166u: goto P_0c072166;
case 0x0c072168u: goto P_0c072168;
case 0x0c07216au: goto P_0c07216a;
case 0x0c07216cu: goto P_0c07216c;
case 0x0c07216eu: goto P_0c07216e;
case 0x0c072170u: goto P_0c072170;
case 0x0c072172u: goto P_0c072172;
case 0x0c072174u: goto P_0c072174;
case 0x0c072176u: goto P_0c072176;
case 0x0c072178u: goto P_0c072178;
case 0x0c07217au: goto P_0c07217a;
case 0x0c07217cu: goto P_0c07217c;
case 0x0c07217eu: goto P_0c07217e;
case 0x0c072180u: goto P_0c072180;
case 0x0c072182u: goto P_0c072182;
case 0x0c072184u: goto P_0c072184;
case 0x0c072186u: goto P_0c072186;
case 0x0c072188u: goto P_0c072188;
case 0x0c07218au: goto P_0c07218a;
case 0x0c07218cu: goto P_0c07218c;
case 0x0c07218eu: goto P_0c07218e;
case 0x0c072190u: goto P_0c072190;
case 0x0c072192u: goto P_0c072192;
case 0x0c072194u: goto P_0c072194;
case 0x0c072196u: goto P_0c072196;
case 0x0c072198u: goto P_0c072198;
case 0x0c07219au: goto P_0c07219a;
case 0x0c07219cu: goto P_0c07219c;
case 0x0c07219eu: goto P_0c07219e;
case 0x0c0721a0u: goto P_0c0721a0;
case 0x0c0721a2u: goto P_0c0721a2;
case 0x0c0721a4u: goto P_0c0721a4;
case 0x0c0721a6u: goto P_0c0721a6;
case 0x0c0721a8u: goto P_0c0721a8;
case 0x0c0721aau: goto P_0c0721aa;
case 0x0c0721acu: goto P_0c0721ac;
case 0x0c0721aeu: goto P_0c0721ae;
case 0x0c0721b0u: goto P_0c0721b0;
case 0x0c0721b2u: goto P_0c0721b2;
case 0x0c0721b4u: goto P_0c0721b4;
case 0x0c0721b6u: goto P_0c0721b6;
case 0x0c0721b8u: goto P_0c0721b8;
case 0x0c0721bau: goto P_0c0721ba;
case 0x0c0721bcu: goto P_0c0721bc;
case 0x0c0721beu: goto P_0c0721be;
case 0x0c0721c0u: goto P_0c0721c0;
case 0x0c0721c2u: goto P_0c0721c2;
case 0x0c0721c4u: goto P_0c0721c4;
case 0x0c0721c6u: goto P_0c0721c6;
case 0x0c0721c8u: goto P_0c0721c8;
case 0x0c0721cau: goto P_0c0721ca;
case 0x0c0721ccu: goto P_0c0721cc;
case 0x0c0721ceu: goto P_0c0721ce;
case 0x0c0721d0u: goto P_0c0721d0;
case 0x0c0721d2u: goto P_0c0721d2;
case 0x0c0721d4u: goto P_0c0721d4;
case 0x0c0721d6u: goto P_0c0721d6;
case 0x0c0721d8u: goto P_0c0721d8;
case 0x0c0721dau: goto P_0c0721da;
case 0x0c0721dcu: goto P_0c0721dc;
case 0x0c0721deu: goto P_0c0721de;
case 0x0c0721e0u: goto P_0c0721e0;
case 0x0c0721e2u: goto P_0c0721e2;
case 0x0c0721e4u: goto P_0c0721e4;
case 0x0c0721e6u: goto P_0c0721e6;
case 0x0c0721e8u: goto P_0c0721e8;
case 0x0c0721eau: goto P_0c0721ea;
case 0x0c0721ecu: goto P_0c0721ec;
case 0x0c0721eeu: goto P_0c0721ee;
case 0x0c0721f0u: goto P_0c0721f0;
case 0x0c0721f2u: goto P_0c0721f2;
case 0x0c0721f4u: goto P_0c0721f4;
case 0x0c0721f6u: goto P_0c0721f6;
case 0x0c0721f8u: goto P_0c0721f8;
case 0x0c0721fau: goto P_0c0721fa;
case 0x0c0721fcu: goto P_0c0721fc;
case 0x0c0721feu: goto P_0c0721fe;
case 0x0c072200u: goto P_0c072200;
case 0x0c072202u: goto P_0c072202;
case 0x0c072204u: goto P_0c072204;
case 0x0c072206u: goto P_0c072206;
case 0x0c072208u: goto P_0c072208;
case 0x0c07220au: goto P_0c07220a;
case 0x0c07220cu: goto P_0c07220c;
case 0x0c07220eu: goto P_0c07220e;
case 0x0c072210u: goto P_0c072210;
case 0x0c072212u: goto P_0c072212;
case 0x0c072214u: goto P_0c072214;
case 0x0c072216u: goto P_0c072216;
case 0x0c072218u: goto P_0c072218;
case 0x0c07221au: goto P_0c07221a;
case 0x0c07221cu: goto P_0c07221c;
case 0x0c07221eu: goto P_0c07221e;
case 0x0c072220u: goto P_0c072220;
case 0x0c072222u: goto P_0c072222;
case 0x0c072224u: goto P_0c072224;
case 0x0c072226u: goto P_0c072226;
case 0x0c072228u: goto P_0c072228;
case 0x0c07222au: goto P_0c07222a;
case 0x0c07222cu: goto P_0c07222c;
case 0x0c07222eu: goto P_0c07222e;
case 0x0c072230u: goto P_0c072230;
case 0x0c072232u: goto P_0c072232;
case 0x0c072234u: goto P_0c072234;
case 0x0c072236u: goto P_0c072236;
case 0x0c072238u: goto P_0c072238;
case 0x0c07223au: goto P_0c07223a;
case 0x0c07223cu: goto P_0c07223c;
case 0x0c07223eu: goto P_0c07223e;
case 0x0c072240u: goto P_0c072240;
case 0x0c072242u: goto P_0c072242;
case 0x0c072244u: goto P_0c072244;
case 0x0c072246u: goto P_0c072246;
case 0x0c072248u: goto P_0c072248;
case 0x0c07224au: goto P_0c07224a;
case 0x0c07224cu: goto P_0c07224c;
case 0x0c07224eu: goto P_0c07224e;
case 0x0c072250u: goto P_0c072250;
case 0x0c072252u: goto P_0c072252;
case 0x0c072254u: goto P_0c072254;
case 0x0c072256u: goto P_0c072256;
case 0x0c072258u: goto P_0c072258;
case 0x0c07225au: goto P_0c07225a;
case 0x0c07225cu: goto P_0c07225c;
case 0x0c07225eu: goto P_0c07225e;
case 0x0c072260u: goto P_0c072260;
case 0x0c072262u: goto P_0c072262;
case 0x0c072264u: goto P_0c072264;
case 0x0c072266u: goto P_0c072266;
case 0x0c072268u: goto P_0c072268;
case 0x0c07226au: goto P_0c07226a;
case 0x0c07226cu: goto P_0c07226c;
case 0x0c07226eu: goto P_0c07226e;
case 0x0c072270u: goto P_0c072270;
case 0x0c072272u: goto P_0c072272;
case 0x0c072274u: goto P_0c072274;
case 0x0c072276u: goto P_0c072276;
case 0x0c072278u: goto P_0c072278;
case 0x0c07227au: goto P_0c07227a;
case 0x0c07227cu: goto P_0c07227c;
case 0x0c07227eu: goto P_0c07227e;
case 0x0c072284u: goto P_0c072284;
case 0x0c072286u: goto P_0c072286;
case 0x0c072288u: goto P_0c072288;
case 0x0c07228au: goto P_0c07228a;
case 0x0c07228cu: goto P_0c07228c;
case 0x0c07228eu: goto P_0c07228e;
case 0x0c072290u: goto P_0c072290;
case 0x0c072292u: goto P_0c072292;
case 0x0c072294u: goto P_0c072294;
case 0x0c072296u: goto P_0c072296;
case 0x0c072298u: goto P_0c072298;
case 0x0c07229au: goto P_0c07229a;
case 0x0c07229cu: goto P_0c07229c;
case 0x0c07229eu: goto P_0c07229e;
case 0x0c0722a0u: goto P_0c0722a0;
case 0x0c0722a2u: goto P_0c0722a2;
case 0x0c0722a4u: goto P_0c0722a4;
case 0x0c0722a6u: goto P_0c0722a6;
case 0x0c0722a8u: goto P_0c0722a8;
case 0x0c0722aau: goto P_0c0722aa;
case 0x0c0722acu: goto P_0c0722ac;
case 0x0c0722aeu: goto P_0c0722ae;
case 0x0c0722b0u: goto P_0c0722b0;
case 0x0c0722b2u: goto P_0c0722b2;
case 0x0c0722b4u: goto P_0c0722b4;
case 0x0c0722b6u: goto P_0c0722b6;
case 0x0c0722b8u: goto P_0c0722b8;
case 0x0c0722bau: goto P_0c0722ba;
case 0x0c0722bcu: goto P_0c0722bc;
case 0x0c0722beu: goto P_0c0722be;
case 0x0c0722c0u: goto P_0c0722c0;
case 0x0c0722c2u: goto P_0c0722c2;
case 0x0c0722c4u: goto P_0c0722c4;
case 0x0c0722c6u: goto P_0c0722c6;
case 0x0c0722c8u: goto P_0c0722c8;
case 0x0c0722cau: goto P_0c0722ca;
case 0x0c0722ccu: goto P_0c0722cc;
case 0x0c0722ceu: goto P_0c0722ce;
case 0x0c0722d0u: goto P_0c0722d0;
case 0x0c0722d2u: goto P_0c0722d2;
case 0x0c0722d4u: goto P_0c0722d4;
case 0x0c0722d6u: goto P_0c0722d6;
case 0x0c0722d8u: goto P_0c0722d8;
case 0x0c0722dau: goto P_0c0722da;
case 0x0c0722dcu: goto P_0c0722dc;
case 0x0c0722deu: goto P_0c0722de;
case 0x0c0722e0u: goto P_0c0722e0;
case 0x0c0722e2u: goto P_0c0722e2;
case 0x0c0722e4u: goto P_0c0722e4;
case 0x0c0722e6u: goto P_0c0722e6;
case 0x0c0722e8u: goto P_0c0722e8;
case 0x0c0722eau: goto P_0c0722ea;
case 0x0c0722ecu: goto P_0c0722ec;
case 0x0c0722eeu: goto P_0c0722ee;
case 0x0c0722f0u: goto P_0c0722f0;
case 0x0c0722f2u: goto P_0c0722f2;
case 0x0c0722f4u: goto P_0c0722f4;
case 0x0c0722f6u: goto P_0c0722f6;
case 0x0c0722f8u: goto P_0c0722f8;
case 0x0c0722fau: goto P_0c0722fa;
case 0x0c0722fcu: goto P_0c0722fc;
case 0x0c0722feu: goto P_0c0722fe;
case 0x0c072300u: goto P_0c072300;
case 0x0c072302u: goto P_0c072302;
case 0x0c072304u: goto P_0c072304;
case 0x0c072306u: goto P_0c072306;
case 0x0c072308u: goto P_0c072308;
case 0x0c07230au: goto P_0c07230a;
case 0x0c07230cu: goto P_0c07230c;
case 0x0c07230eu: goto P_0c07230e;
case 0x0c072310u: goto P_0c072310;
case 0x0c072312u: goto P_0c072312;
case 0x0c072314u: goto P_0c072314;
case 0x0c072316u: goto P_0c072316;
case 0x0c072318u: goto P_0c072318;
case 0x0c07231au: goto P_0c07231a;
case 0x0c07231cu: goto P_0c07231c;
case 0x0c07231eu: goto P_0c07231e;
case 0x0c072320u: goto P_0c072320;
case 0x0c072322u: goto P_0c072322;
case 0x0c072324u: goto P_0c072324;
case 0x0c072326u: goto P_0c072326;
case 0x0c072328u: goto P_0c072328;
case 0x0c07232au: goto P_0c07232a;
case 0x0c07232cu: goto P_0c07232c;
case 0x0c07232eu: goto P_0c07232e;
case 0x0c072330u: goto P_0c072330;
case 0x0c072332u: goto P_0c072332;
case 0x0c072334u: goto P_0c072334;
case 0x0c07239eu: goto P_0c07239e;
case 0x0c0723a0u: goto P_0c0723a0;
case 0x0c0723a2u: goto P_0c0723a2;
case 0x0c0723a4u: goto P_0c0723a4;
case 0x0c0723a6u: goto P_0c0723a6;
case 0x0c0723a8u: goto P_0c0723a8;
case 0x0c0723aau: goto P_0c0723aa;
case 0x0c0723acu: goto P_0c0723ac;
case 0x0c0723aeu: goto P_0c0723ae;
case 0x0c0723b0u: goto P_0c0723b0;
case 0x0c0723b2u: goto P_0c0723b2;
case 0x0c0723b4u: goto P_0c0723b4;
case 0x0c0723b6u: goto P_0c0723b6;
case 0x0c0723b8u: goto P_0c0723b8;
case 0x0c0723bau: goto P_0c0723ba;
case 0x0c0723bcu: goto P_0c0723bc;
case 0x0c0723beu: goto P_0c0723be;
case 0x0c0723c0u: goto P_0c0723c0;
case 0x0c0723c2u: goto P_0c0723c2;
case 0x0c0723c4u: goto P_0c0723c4;
case 0x0c0723c6u: goto P_0c0723c6;
case 0x0c0723c8u: goto P_0c0723c8;
case 0x0c0723cau: goto P_0c0723ca;
case 0x0c0723ccu: goto P_0c0723cc;
case 0x0c0723ceu: goto P_0c0723ce;
case 0x0c0723d0u: goto P_0c0723d0;
case 0x0c0723d2u: goto P_0c0723d2;
case 0x0c0723d4u: goto P_0c0723d4;
case 0x0c0723d6u: goto P_0c0723d6;
case 0x0c0723d8u: goto P_0c0723d8;
case 0x0c0723dau: goto P_0c0723da;
case 0x0c0723dcu: goto P_0c0723dc;
case 0x0c0723deu: goto P_0c0723de;
case 0x0c0723e0u: goto P_0c0723e0;
case 0x0c0723e2u: goto P_0c0723e2;
case 0x0c0723e4u: goto P_0c0723e4;
case 0x0c0723e6u: goto P_0c0723e6;
case 0x0c0723e8u: goto P_0c0723e8;
case 0x0c0723eau: goto P_0c0723ea;
case 0x0c0723ecu: goto P_0c0723ec;
case 0x0c0723eeu: goto P_0c0723ee;
case 0x0c0723f0u: goto P_0c0723f0;
case 0x0c0723f2u: goto P_0c0723f2;
case 0x0c0723f4u: goto P_0c0723f4;
case 0x0c0723f6u: goto P_0c0723f6;
case 0x0c0723f8u: goto P_0c0723f8;
case 0x0c0723fau: goto P_0c0723fa;
case 0x0c0723fcu: goto P_0c0723fc;
case 0x0c0723feu: goto P_0c0723fe;
case 0x0c072400u: goto P_0c072400;
case 0x0c072402u: goto P_0c072402;
case 0x0c072404u: goto P_0c072404;
case 0x0c072406u: goto P_0c072406;
case 0x0c072408u: goto P_0c072408;
case 0x0c07240au: goto P_0c07240a;
case 0x0c07240cu: goto P_0c07240c;
case 0x0c07240eu: goto P_0c07240e;
case 0x0c072410u: goto P_0c072410;
case 0x0c072412u: goto P_0c072412;
case 0x0c072414u: goto P_0c072414;
case 0x0c072416u: goto P_0c072416;
case 0x0c072418u: goto P_0c072418;
case 0x0c07241au: goto P_0c07241a;
case 0x0c07241cu: goto P_0c07241c;
case 0x0c07241eu: goto P_0c07241e;
case 0x0c072420u: goto P_0c072420;
case 0x0c072422u: goto P_0c072422;
case 0x0c072424u: goto P_0c072424;
case 0x0c072426u: goto P_0c072426;
case 0x0c072428u: goto P_0c072428;
case 0x0c07242au: goto P_0c07242a;
case 0x0c07242cu: goto P_0c07242c;
case 0x0c07242eu: goto P_0c07242e;
case 0x0c072430u: goto P_0c072430;
case 0x0c072432u: goto P_0c072432;
case 0x0c072434u: goto P_0c072434;
case 0x0c072436u: goto P_0c072436;
case 0x0c072438u: goto P_0c072438;
case 0x0c07243au: goto P_0c07243a;
case 0x0c07243cu: goto P_0c07243c;
case 0x0c07243eu: goto P_0c07243e;
case 0x0c072440u: goto P_0c072440;
case 0x0c072442u: goto P_0c072442;
case 0x0c072444u: goto P_0c072444;
case 0x0c072446u: goto P_0c072446;
case 0x0c072448u: goto P_0c072448;
case 0x0c07244au: goto P_0c07244a;
case 0x0c07244cu: goto P_0c07244c;
case 0x0c07244eu: goto P_0c07244e;
case 0x0c072450u: goto P_0c072450;
case 0x0c072452u: goto P_0c072452;
case 0x0c072454u: goto P_0c072454;
case 0x0c072456u: goto P_0c072456;
case 0x0c072458u: goto P_0c072458;
case 0x0c07245au: goto P_0c07245a;
case 0x0c07245cu: goto P_0c07245c;
case 0x0c07245eu: goto P_0c07245e;
case 0x0c072460u: goto P_0c072460;
case 0x0c072462u: goto P_0c072462;
case 0x0c072464u: goto P_0c072464;
case 0x0c072466u: goto P_0c072466;
case 0x0c072468u: goto P_0c072468;
case 0x0c07246au: goto P_0c07246a;
case 0x0c07246cu: goto P_0c07246c;
case 0x0c07246eu: goto P_0c07246e;
case 0x0c072470u: goto P_0c072470;
case 0x0c072472u: goto P_0c072472;
case 0x0c072474u: goto P_0c072474;
case 0x0c072476u: goto P_0c072476;
case 0x0c072478u: goto P_0c072478;
case 0x0c07247au: goto P_0c07247a;
case 0x0c07247cu: goto P_0c07247c;
case 0x0c07247eu: goto P_0c07247e;
case 0x0c072480u: goto P_0c072480;
case 0x0c072482u: goto P_0c072482;
case 0x0c072484u: goto P_0c072484;
case 0x0c072486u: goto P_0c072486;
case 0x0c072488u: goto P_0c072488;
case 0x0c07248au: goto P_0c07248a;
case 0x0c07248cu: goto P_0c07248c;
case 0x0c07248eu: goto P_0c07248e;
case 0x0c072490u: goto P_0c072490;
case 0x0c072492u: goto P_0c072492;
case 0x0c072494u: goto P_0c072494;
case 0x0c072496u: goto P_0c072496;
case 0x0c072498u: goto P_0c072498;
case 0x0c07249au: goto P_0c07249a;
case 0x0c07249cu: goto P_0c07249c;
case 0x0c07249eu: goto P_0c07249e;
case 0x0c0724a0u: goto P_0c0724a0;
case 0x0c0724a2u: goto P_0c0724a2;
case 0x0c0724a4u: goto P_0c0724a4;
case 0x0c0724a6u: goto P_0c0724a6;
case 0x0c0724a8u: goto P_0c0724a8;
case 0x0c0724aau: goto P_0c0724aa;
case 0x0c0724acu: goto P_0c0724ac;
case 0x0c0724aeu: goto P_0c0724ae;
case 0x0c0724b0u: goto P_0c0724b0;
case 0x0c0724b2u: goto P_0c0724b2;
case 0x0c0724b4u: goto P_0c0724b4;
case 0x0c0724b6u: goto P_0c0724b6;
case 0x0c0724b8u: goto P_0c0724b8;
case 0x0c0724bau: goto P_0c0724ba;
case 0x0c0724bcu: goto P_0c0724bc;
case 0x0c0724c4u: goto P_0c0724c4;
case 0x0c0724c6u: goto P_0c0724c6;
case 0x0c0724c8u: goto P_0c0724c8;
case 0x0c0724cau: goto P_0c0724ca;
case 0x0c0724ccu: goto P_0c0724cc;
case 0x0c0724ceu: goto P_0c0724ce;
case 0x0c0724d0u: goto P_0c0724d0;
case 0x0c0724d2u: goto P_0c0724d2;
case 0x0c0724d4u: goto P_0c0724d4;
case 0x0c0724d6u: goto P_0c0724d6;
case 0x0c0724d8u: goto P_0c0724d8;
case 0x0c0724dau: goto P_0c0724da;
case 0x0c0724dcu: goto P_0c0724dc;
case 0x0c0724deu: goto P_0c0724de;
case 0x0c0724e0u: goto P_0c0724e0;
case 0x0c0724e2u: goto P_0c0724e2;
case 0x0c0724e4u: goto P_0c0724e4;
case 0x0c0724e6u: goto P_0c0724e6;
case 0x0c0724e8u: goto P_0c0724e8;
case 0x0c0724eau: goto P_0c0724ea;
case 0x0c0724ecu: goto P_0c0724ec;
case 0x0c0724eeu: goto P_0c0724ee;
case 0x0c0724f0u: goto P_0c0724f0;
case 0x0c0724f2u: goto P_0c0724f2;
case 0x0c0724f4u: goto P_0c0724f4;
case 0x0c0724f6u: goto P_0c0724f6;
case 0x0c0724f8u: goto P_0c0724f8;
case 0x0c0724fau: goto P_0c0724fa;
case 0x0c0724fcu: goto P_0c0724fc;
case 0x0c0724feu: goto P_0c0724fe;
case 0x0c072500u: goto P_0c072500;
case 0x0c072502u: goto P_0c072502;
case 0x0c072504u: goto P_0c072504;
case 0x0c072506u: goto P_0c072506;
case 0x0c072508u: goto P_0c072508;
case 0x0c07250au: goto P_0c07250a;
case 0x0c07250cu: goto P_0c07250c;
case 0x0c07250eu: goto P_0c07250e;
case 0x0c072510u: goto P_0c072510;
case 0x0c072512u: goto P_0c072512;
case 0x0c072514u: goto P_0c072514;
case 0x0c072516u: goto P_0c072516;
case 0x0c072518u: goto P_0c072518;
case 0x0c07251au: goto P_0c07251a;
case 0x0c07251cu: goto P_0c07251c;
case 0x0c07251eu: goto P_0c07251e;
case 0x0c072520u: goto P_0c072520;
case 0x0c072522u: goto P_0c072522;
case 0x0c072524u: goto P_0c072524;
case 0x0c072526u: goto P_0c072526;
case 0x0c072528u: goto P_0c072528;
case 0x0c07252au: goto P_0c07252a;
case 0x0c07252cu: goto P_0c07252c;
case 0x0c07252eu: goto P_0c07252e;
case 0x0c072530u: goto P_0c072530;
case 0x0c072532u: goto P_0c072532;
case 0x0c072534u: goto P_0c072534;
case 0x0c072536u: goto P_0c072536;
case 0x0c072538u: goto P_0c072538;
case 0x0c07253au: goto P_0c07253a;
case 0x0c07253cu: goto P_0c07253c;
case 0x0c07253eu: goto P_0c07253e;
case 0x0c072540u: goto P_0c072540;
case 0x0c072542u: goto P_0c072542;
case 0x0c072544u: goto P_0c072544;
case 0x0c072546u: goto P_0c072546;
case 0x0c072548u: goto P_0c072548;
case 0x0c07254au: goto P_0c07254a;
case 0x0c07254cu: goto P_0c07254c;
case 0x0c07254eu: goto P_0c07254e;
case 0x0c072550u: goto P_0c072550;
case 0x0c072552u: goto P_0c072552;
case 0x0c072554u: goto P_0c072554;
case 0x0c072556u: goto P_0c072556;
case 0x0c072558u: goto P_0c072558;
case 0x0c07255au: goto P_0c07255a;
case 0x0c07255cu: goto P_0c07255c;
case 0x0c07255eu: goto P_0c07255e;
case 0x0c072560u: goto P_0c072560;
case 0x0c072562u: goto P_0c072562;
case 0x0c072564u: goto P_0c072564;
case 0x0c072566u: goto P_0c072566;
case 0x0c072568u: goto P_0c072568;
case 0x0c07256au: goto P_0c07256a;
case 0x0c07256cu: goto P_0c07256c;
case 0x0c07256eu: goto P_0c07256e;
case 0x0c072570u: goto P_0c072570;
case 0x0c072572u: goto P_0c072572;
case 0x0c072574u: goto P_0c072574;
case 0x0c072576u: goto P_0c072576;
case 0x0c072578u: goto P_0c072578;
case 0x0c07257au: goto P_0c07257a;
case 0x0c07257cu: goto P_0c07257c;
case 0x0c07257eu: goto P_0c07257e;
case 0x0c072580u: goto P_0c072580;
case 0x0c072582u: goto P_0c072582;
case 0x0c072584u: goto P_0c072584;
case 0x0c072586u: goto P_0c072586;
case 0x0c072588u: goto P_0c072588;
case 0x0c07258au: goto P_0c07258a;
case 0x0c07258cu: goto P_0c07258c;
case 0x0c07258eu: goto P_0c07258e;
case 0x0c072590u: goto P_0c072590;
case 0x0c072592u: goto P_0c072592;
case 0x0c072594u: goto P_0c072594;
case 0x0c072596u: goto P_0c072596;
case 0x0c072598u: goto P_0c072598;
case 0x0c07259au: goto P_0c07259a;
case 0x0c07259cu: goto P_0c07259c;
case 0x0c07259eu: goto P_0c07259e;
case 0x0c0725a0u: goto P_0c0725a0;
case 0x0c0725a2u: goto P_0c0725a2;
case 0x0c0725a4u: goto P_0c0725a4;
case 0x0c0725a6u: goto P_0c0725a6;
case 0x0c0725a8u: goto P_0c0725a8;
case 0x0c0725aau: goto P_0c0725aa;
case 0x0c0725acu: goto P_0c0725ac;
case 0x0c0725aeu: goto P_0c0725ae;
case 0x0c0725b0u: goto P_0c0725b0;
case 0x0c0725b2u: goto P_0c0725b2;
case 0x0c0725b4u: goto P_0c0725b4;
case 0x0c0725b6u: goto P_0c0725b6;
case 0x0c0725b8u: goto P_0c0725b8;
case 0x0c0725bau: goto P_0c0725ba;
case 0x0c0725bcu: goto P_0c0725bc;
case 0x0c0725beu: goto P_0c0725be;
case 0x0c0725c0u: goto P_0c0725c0;
case 0x0c0725c2u: goto P_0c0725c2;
case 0x0c0725c4u: goto P_0c0725c4;
case 0x0c0725c6u: goto P_0c0725c6;
case 0x0c0725c8u: goto P_0c0725c8;
case 0x0c0725cau: goto P_0c0725ca;
case 0x0c0725ccu: goto P_0c0725cc;
case 0x0c0725ceu: goto P_0c0725ce;
case 0x0c0725d0u: goto P_0c0725d0;
case 0x0c0725d2u: goto P_0c0725d2;
case 0x0c0725d4u: goto P_0c0725d4;
case 0x0c0725d6u: goto P_0c0725d6;
case 0x0c0725d8u: goto P_0c0725d8;
case 0x0c0725dau: goto P_0c0725da;
case 0x0c0725dcu: goto P_0c0725dc;
case 0x0c0725deu: goto P_0c0725de;
case 0x0c0725e0u: goto P_0c0725e0;
case 0x0c0725e2u: goto P_0c0725e2;
case 0x0c0725e4u: goto P_0c0725e4;
case 0x0c0725e6u: goto P_0c0725e6;
case 0x0c0725e8u: goto P_0c0725e8;
case 0x0c0725eau: goto P_0c0725ea;
case 0x0c0725ecu: goto P_0c0725ec;
case 0x0c0725eeu: goto P_0c0725ee;
case 0x0c0725f0u: goto P_0c0725f0;
case 0x0c0725f2u: goto P_0c0725f2;
case 0x0c0725f4u: goto P_0c0725f4;
case 0x0c0725f6u: goto P_0c0725f6;
case 0x0c0725f8u: goto P_0c0725f8;
case 0x0c0725fau: goto P_0c0725fa;
case 0x0c0725fcu: goto P_0c0725fc;
case 0x0c0725feu: goto P_0c0725fe;
case 0x0c072600u: goto P_0c072600;
case 0x0c072602u: goto P_0c072602;
case 0x0c072604u: goto P_0c072604;
case 0x0c072606u: goto P_0c072606;
case 0x0c072608u: goto P_0c072608;
case 0x0c07260au: goto P_0c07260a;
case 0x0c07260cu: goto P_0c07260c;
case 0x0c07260eu: goto P_0c07260e;
case 0x0c072610u: goto P_0c072610;
case 0x0c072612u: goto P_0c072612;
case 0x0c072614u: goto P_0c072614;
case 0x0c072616u: goto P_0c072616;
case 0x0c072618u: goto P_0c072618;
case 0x0c07261au: goto P_0c07261a;
case 0x0c07261cu: goto P_0c07261c;
case 0x0c07261eu: goto P_0c07261e;
case 0x0c072620u: goto P_0c072620;
case 0x0c072622u: goto P_0c072622;
case 0x0c072624u: goto P_0c072624;
case 0x0c072626u: goto P_0c072626;
case 0x0c072628u: goto P_0c072628;
case 0x0c07262au: goto P_0c07262a;
case 0x0c07262cu: goto P_0c07262c;
case 0x0c07262eu: goto P_0c07262e;
case 0x0c072630u: goto P_0c072630;
case 0x0c072632u: goto P_0c072632;
case 0x0c072634u: goto P_0c072634;
case 0x0c072636u: goto P_0c072636;
case 0x0c072638u: goto P_0c072638;
case 0x0c07263au: goto P_0c07263a;
case 0x0c07263cu: goto P_0c07263c;
case 0x0c07263eu: goto P_0c07263e;
case 0x0c072640u: goto P_0c072640;
case 0x0c072642u: goto P_0c072642;
case 0x0c072644u: goto P_0c072644;
case 0x0c072646u: goto P_0c072646;
case 0x0c072648u: goto P_0c072648;
case 0x0c07264au: goto P_0c07264a;
case 0x0c07264cu: goto P_0c07264c;
case 0x0c07264eu: goto P_0c07264e;
case 0x0c072650u: goto P_0c072650;
case 0x0c072652u: goto P_0c072652;
case 0x0c072654u: goto P_0c072654;
case 0x0c072656u: goto P_0c072656;
case 0x0c072658u: goto P_0c072658;
case 0x0c07265au: goto P_0c07265a;
case 0x0c07265cu: goto P_0c07265c;
case 0x0c072664u: goto P_0c072664;
case 0x0c072666u: goto P_0c072666;
case 0x0c072668u: goto P_0c072668;
case 0x0c07266au: goto P_0c07266a;
case 0x0c07266cu: goto P_0c07266c;
case 0x0c07266eu: goto P_0c07266e;
case 0x0c072670u: goto P_0c072670;
case 0x0c072672u: goto P_0c072672;
case 0x0c072674u: goto P_0c072674;
case 0x0c072676u: goto P_0c072676;
case 0x0c072678u: goto P_0c072678;
case 0x0c07267au: goto P_0c07267a;
case 0x0c07267cu: goto P_0c07267c;
case 0x0c07267eu: goto P_0c07267e;
case 0x0c072680u: goto P_0c072680;
case 0x0c072682u: goto P_0c072682;
case 0x0c072684u: goto P_0c072684;
case 0x0c072686u: goto P_0c072686;
case 0x0c072688u: goto P_0c072688;
case 0x0c07268au: goto P_0c07268a;
case 0x0c07268cu: goto P_0c07268c;
case 0x0c07268eu: goto P_0c07268e;
case 0x0c072690u: goto P_0c072690;
case 0x0c072692u: goto P_0c072692;
case 0x0c072694u: goto P_0c072694;
case 0x0c072696u: goto P_0c072696;
case 0x0c072698u: goto P_0c072698;
case 0x0c07269au: goto P_0c07269a;
case 0x0c07269cu: goto P_0c07269c;
case 0x0c07269eu: goto P_0c07269e;
case 0x0c0726a0u: goto P_0c0726a0;
case 0x0c0726a2u: goto P_0c0726a2;
case 0x0c0726a4u: goto P_0c0726a4;
case 0x0c0726a6u: goto P_0c0726a6;
case 0x0c0726a8u: goto P_0c0726a8;
case 0x0c0726aau: goto P_0c0726aa;
case 0x0c0726acu: goto P_0c0726ac;
case 0x0c0726aeu: goto P_0c0726ae;
case 0x0c0726b0u: goto P_0c0726b0;
case 0x0c0726b2u: goto P_0c0726b2;
case 0x0c0726b4u: goto P_0c0726b4;
case 0x0c0726b6u: goto P_0c0726b6;
case 0x0c0726b8u: goto P_0c0726b8;
case 0x0c0726bau: goto P_0c0726ba;
case 0x0c0726bcu: goto P_0c0726bc;
case 0x0c0726beu: goto P_0c0726be;
case 0x0c0726c0u: goto P_0c0726c0;
case 0x0c0726c2u: goto P_0c0726c2;
case 0x0c0726c4u: goto P_0c0726c4;
case 0x0c0726c6u: goto P_0c0726c6;
case 0x0c0726c8u: goto P_0c0726c8;
case 0x0c0726cau: goto P_0c0726ca;
case 0x0c0726ccu: goto P_0c0726cc;
case 0x0c0726ceu: goto P_0c0726ce;
case 0x0c0726d0u: goto P_0c0726d0;
case 0x0c0726d2u: goto P_0c0726d2;
case 0x0c0726d4u: goto P_0c0726d4;
case 0x0c0726d6u: goto P_0c0726d6;
case 0x0c0726d8u: goto P_0c0726d8;
case 0x0c0726dau: goto P_0c0726da;
case 0x0c0726dcu: goto P_0c0726dc;
case 0x0c0726deu: goto P_0c0726de;
case 0x0c0726e0u: goto P_0c0726e0;
case 0x0c0726e2u: goto P_0c0726e2;
case 0x0c0726e4u: goto P_0c0726e4;
case 0x0c0726e6u: goto P_0c0726e6;
case 0x0c0726e8u: goto P_0c0726e8;
case 0x0c0726eau: goto P_0c0726ea;
case 0x0c0726ecu: goto P_0c0726ec;
case 0x0c0726eeu: goto P_0c0726ee;
case 0x0c0726f0u: goto P_0c0726f0;
case 0x0c0726f2u: goto P_0c0726f2;
case 0x0c0726f4u: goto P_0c0726f4;
case 0x0c0726f6u: goto P_0c0726f6;
case 0x0c0726f8u: goto P_0c0726f8;
case 0x0c0726fau: goto P_0c0726fa;
case 0x0c0726fcu: goto P_0c0726fc;
case 0x0c0726feu: goto P_0c0726fe;
case 0x0c072700u: goto P_0c072700;
case 0x0c072702u: goto P_0c072702;
case 0x0c072704u: goto P_0c072704;
case 0x0c072706u: goto P_0c072706;
case 0x0c072708u: goto P_0c072708;
case 0x0c07270au: goto P_0c07270a;
case 0x0c07270cu: goto P_0c07270c;
case 0x0c07270eu: goto P_0c07270e;
case 0x0c072710u: goto P_0c072710;
case 0x0c072712u: goto P_0c072712;
case 0x0c072714u: goto P_0c072714;
case 0x0c072716u: goto P_0c072716;
case 0x0c072718u: goto P_0c072718;
case 0x0c07271au: goto P_0c07271a;
case 0x0c07271cu: goto P_0c07271c;
case 0x0c07271eu: goto P_0c07271e;
case 0x0c072720u: goto P_0c072720;
case 0x0c072722u: goto P_0c072722;
case 0x0c072724u: goto P_0c072724;
case 0x0c072726u: goto P_0c072726;
case 0x0c072728u: goto P_0c072728;
case 0x0c07272au: goto P_0c07272a;
case 0x0c07272cu: goto P_0c07272c;
case 0x0c07272eu: goto P_0c07272e;
case 0x0c072730u: goto P_0c072730;
case 0x0c072732u: goto P_0c072732;
case 0x0c072734u: goto P_0c072734;
case 0x0c072736u: goto P_0c072736;
case 0x0c072738u: goto P_0c072738;
case 0x0c07273au: goto P_0c07273a;
case 0x0c07273cu: goto P_0c07273c;
case 0x0c07273eu: goto P_0c07273e;
case 0x0c072740u: goto P_0c072740;
case 0x0c072742u: goto P_0c072742;
case 0x0c072744u: goto P_0c072744;
case 0x0c072746u: goto P_0c072746;
case 0x0c072748u: goto P_0c072748;
case 0x0c07274au: goto P_0c07274a;
case 0x0c07274cu: goto P_0c07274c;
case 0x0c07274eu: goto P_0c07274e;
case 0x0c072750u: goto P_0c072750;
case 0x0c072752u: goto P_0c072752;
case 0x0c072754u: goto P_0c072754;
case 0x0c072756u: goto P_0c072756;
case 0x0c072758u: goto P_0c072758;
case 0x0c07275au: goto P_0c07275a;
case 0x0c07275cu: goto P_0c07275c;
case 0x0c07275eu: goto P_0c07275e;
case 0x0c072760u: goto P_0c072760;
case 0x0c072762u: goto P_0c072762;
case 0x0c072764u: goto P_0c072764;
case 0x0c072766u: goto P_0c072766;
case 0x0c072768u: goto P_0c072768;
case 0x0c07276au: goto P_0c07276a;
case 0x0c07276cu: goto P_0c07276c;
case 0x0c07276eu: goto P_0c07276e;
case 0x0c072770u: goto P_0c072770;
case 0x0c072772u: goto P_0c072772;
case 0x0c072774u: goto P_0c072774;
case 0x0c072776u: goto P_0c072776;
case 0x0c072778u: goto P_0c072778;
case 0x0c07277au: goto P_0c07277a;
case 0x0c07277cu: goto P_0c07277c;
case 0x0c07277eu: goto P_0c07277e;
case 0x0c072780u: goto P_0c072780;
case 0x0c072782u: goto P_0c072782;
case 0x0c072784u: goto P_0c072784;
case 0x0c072786u: goto P_0c072786;
case 0x0c072788u: goto P_0c072788;
case 0x0c07278au: goto P_0c07278a;
case 0x0c07278cu: goto P_0c07278c;
case 0x0c07278eu: goto P_0c07278e;
case 0x0c072790u: goto P_0c072790;
case 0x0c072792u: goto P_0c072792;
case 0x0c072794u: goto P_0c072794;
case 0x0c072796u: goto P_0c072796;
case 0x0c072798u: goto P_0c072798;
case 0x0c07279au: goto P_0c07279a;
case 0x0c07279cu: goto P_0c07279c;
case 0x0c07279eu: goto P_0c07279e;
case 0x0c0727a0u: goto P_0c0727a0;
case 0x0c0727a2u: goto P_0c0727a2;
case 0x0c0727a4u: goto P_0c0727a4;
case 0x0c0727a6u: goto P_0c0727a6;
case 0x0c0727a8u: goto P_0c0727a8;
case 0x0c0727aau: goto P_0c0727aa;
case 0x0c0727acu: goto P_0c0727ac;
case 0x0c0727aeu: goto P_0c0727ae;
case 0x0c0727b0u: goto P_0c0727b0;
case 0x0c0727b2u: goto P_0c0727b2;
case 0x0c0727b4u: goto P_0c0727b4;
case 0x0c0727b6u: goto P_0c0727b6;
case 0x0c0727b8u: goto P_0c0727b8;
case 0x0c0727bau: goto P_0c0727ba;
case 0x0c0727bcu: goto P_0c0727bc;
case 0x0c0727beu: goto P_0c0727be;
case 0x0c0727c0u: goto P_0c0727c0;
case 0x0c0727c2u: goto P_0c0727c2;
case 0x0c0727c4u: goto P_0c0727c4;
case 0x0c0727c6u: goto P_0c0727c6;
case 0x0c0727c8u: goto P_0c0727c8;
case 0x0c0727cau: goto P_0c0727ca;
case 0x0c0727ccu: goto P_0c0727cc;
case 0x0c0727ceu: goto P_0c0727ce;
case 0x0c0727d0u: goto P_0c0727d0;
case 0x0c0727d2u: goto P_0c0727d2;
case 0x0c0727d4u: goto P_0c0727d4;
case 0x0c0727d6u: goto P_0c0727d6;
case 0x0c0727d8u: goto P_0c0727d8;
case 0x0c0727dau: goto P_0c0727da;
case 0x0c0727dcu: goto P_0c0727dc;
case 0x0c0727e4u: goto P_0c0727e4;
case 0x0c0727e6u: goto P_0c0727e6;
case 0x0c0727e8u: goto P_0c0727e8;
case 0x0c0727eau: goto P_0c0727ea;
case 0x0c0727ecu: goto P_0c0727ec;
case 0x0c0727eeu: goto P_0c0727ee;
case 0x0c0727f0u: goto P_0c0727f0;
case 0x0c0727f2u: goto P_0c0727f2;
case 0x0c0727f4u: goto P_0c0727f4;
case 0x0c0727f6u: goto P_0c0727f6;
case 0x0c0727f8u: goto P_0c0727f8;
case 0x0c0727fau: goto P_0c0727fa;
case 0x0c0727fcu: goto P_0c0727fc;
case 0x0c0727feu: goto P_0c0727fe;
case 0x0c072800u: goto P_0c072800;
case 0x0c072802u: goto P_0c072802;
case 0x0c072804u: goto P_0c072804;
case 0x0c072806u: goto P_0c072806;
case 0x0c072808u: goto P_0c072808;
case 0x0c07280au: goto P_0c07280a;
case 0x0c07280cu: goto P_0c07280c;
case 0x0c07280eu: goto P_0c07280e;
case 0x0c072810u: goto P_0c072810;
case 0x0c072812u: goto P_0c072812;
case 0x0c072814u: goto P_0c072814;
case 0x0c072816u: goto P_0c072816;
case 0x0c072818u: goto P_0c072818;
case 0x0c07281au: goto P_0c07281a;
case 0x0c07281cu: goto P_0c07281c;
case 0x0c07281eu: goto P_0c07281e;
case 0x0c072820u: goto P_0c072820;
case 0x0c072822u: goto P_0c072822;
case 0x0c072824u: goto P_0c072824;
case 0x0c072826u: goto P_0c072826;
case 0x0c072828u: goto P_0c072828;
case 0x0c07282au: goto P_0c07282a;
case 0x0c07282cu: goto P_0c07282c;
case 0x0c07282eu: goto P_0c07282e;
case 0x0c072830u: goto P_0c072830;
case 0x0c072832u: goto P_0c072832;
case 0x0c072834u: goto P_0c072834;
case 0x0c072836u: goto P_0c072836;
case 0x0c072838u: goto P_0c072838;
case 0x0c07283au: goto P_0c07283a;
case 0x0c07283cu: goto P_0c07283c;
case 0x0c07283eu: goto P_0c07283e;
case 0x0c072840u: goto P_0c072840;
case 0x0c072842u: goto P_0c072842;
case 0x0c072844u: goto P_0c072844;
case 0x0c072846u: goto P_0c072846;
case 0x0c072848u: goto P_0c072848;
case 0x0c07284au: goto P_0c07284a;
case 0x0c07284cu: goto P_0c07284c;
case 0x0c07284eu: goto P_0c07284e;
case 0x0c072850u: goto P_0c072850;
case 0x0c072852u: goto P_0c072852;
case 0x0c072854u: goto P_0c072854;
case 0x0c072856u: goto P_0c072856;
case 0x0c072858u: goto P_0c072858;
case 0x0c07285au: goto P_0c07285a;
case 0x0c07285cu: goto P_0c07285c;
case 0x0c07285eu: goto P_0c07285e;
case 0x0c072860u: goto P_0c072860;
case 0x0c072862u: goto P_0c072862;
case 0x0c072864u: goto P_0c072864;
case 0x0c072866u: goto P_0c072866;
case 0x0c072868u: goto P_0c072868;
case 0x0c07286au: goto P_0c07286a;
case 0x0c07286cu: goto P_0c07286c;
case 0x0c07286eu: goto P_0c07286e;
case 0x0c072870u: goto P_0c072870;
case 0x0c072872u: goto P_0c072872;
case 0x0c072874u: goto P_0c072874;
case 0x0c072876u: goto P_0c072876;
case 0x0c072878u: goto P_0c072878;
case 0x0c07287au: goto P_0c07287a;
case 0x0c07287cu: goto P_0c07287c;
case 0x0c07287eu: goto P_0c07287e;
case 0x0c072880u: goto P_0c072880;
case 0x0c072882u: goto P_0c072882;
case 0x0c072884u: goto P_0c072884;
case 0x0c072886u: goto P_0c072886;
case 0x0c072888u: goto P_0c072888;
case 0x0c07288au: goto P_0c07288a;
case 0x0c07288cu: goto P_0c07288c;
case 0x0c07288eu: goto P_0c07288e;
case 0x0c072890u: goto P_0c072890;
case 0x0c072892u: goto P_0c072892;
case 0x0c072894u: goto P_0c072894;
case 0x0c072896u: goto P_0c072896;
case 0x0c072898u: goto P_0c072898;
case 0x0c07289au: goto P_0c07289a;
case 0x0c07289cu: goto P_0c07289c;
case 0x0c07289eu: goto P_0c07289e;
case 0x0c0728a0u: goto P_0c0728a0;
case 0x0c0728a2u: goto P_0c0728a2;
case 0x0c0728a8u: goto P_0c0728a8;
case 0x0c0728aau: goto P_0c0728aa;
case 0x0c0728acu: goto P_0c0728ac;
case 0x0c0728aeu: goto P_0c0728ae;
case 0x0c0728b0u: goto P_0c0728b0;
case 0x0c0728b2u: goto P_0c0728b2;
case 0x0c0728b4u: goto P_0c0728b4;
case 0x0c0728b6u: goto P_0c0728b6;
case 0x0c0728b8u: goto P_0c0728b8;
case 0x0c0728bau: goto P_0c0728ba;
case 0x0c0728bcu: goto P_0c0728bc;
case 0x0c0728beu: goto P_0c0728be;
case 0x0c0728c0u: goto P_0c0728c0;
case 0x0c0728c2u: goto P_0c0728c2;
case 0x0c0728c4u: goto P_0c0728c4;
case 0x0c0728c6u: goto P_0c0728c6;
case 0x0c0728c8u: goto P_0c0728c8;
case 0x0c0728cau: goto P_0c0728ca;
case 0x0c0728ccu: goto P_0c0728cc;
case 0x0c0728ceu: goto P_0c0728ce;
case 0x0c0728d0u: goto P_0c0728d0;
case 0x0c0728d2u: goto P_0c0728d2;
case 0x0c0728d4u: goto P_0c0728d4;
case 0x0c0728d6u: goto P_0c0728d6;
case 0x0c0728d8u: goto P_0c0728d8;
case 0x0c0728dau: goto P_0c0728da;
case 0x0c0728dcu: goto P_0c0728dc;
case 0x0c0728deu: goto P_0c0728de;
case 0x0c0728e0u: goto P_0c0728e0;
case 0x0c0728e2u: goto P_0c0728e2;
case 0x0c0728e4u: goto P_0c0728e4;
case 0x0c0728e6u: goto P_0c0728e6;
case 0x0c0728e8u: goto P_0c0728e8;
case 0x0c0728eau: goto P_0c0728ea;
case 0x0c0728ecu: goto P_0c0728ec;
case 0x0c0728eeu: goto P_0c0728ee;
case 0x0c0728f0u: goto P_0c0728f0;
case 0x0c0728f2u: goto P_0c0728f2;
case 0x0c0728f4u: goto P_0c0728f4;
case 0x0c0728f6u: goto P_0c0728f6;
case 0x0c0728f8u: goto P_0c0728f8;
case 0x0c0728fau: goto P_0c0728fa;
case 0x0c0728fcu: goto P_0c0728fc;
case 0x0c0728feu: goto P_0c0728fe;
case 0x0c072900u: goto P_0c072900;
case 0x0c072902u: goto P_0c072902;
case 0x0c072904u: goto P_0c072904;
case 0x0c072906u: goto P_0c072906;
case 0x0c072908u: goto P_0c072908;
case 0x0c07290au: goto P_0c07290a;
case 0x0c07290cu: goto P_0c07290c;
case 0x0c07290eu: goto P_0c07290e;
case 0x0c072910u: goto P_0c072910;
case 0x0c072912u: goto P_0c072912;
case 0x0c072914u: goto P_0c072914;
case 0x0c072916u: goto P_0c072916;
case 0x0c072918u: goto P_0c072918;
case 0x0c07291au: goto P_0c07291a;
case 0x0c07291cu: goto P_0c07291c;
case 0x0c07291eu: goto P_0c07291e;
case 0x0c072920u: goto P_0c072920;
case 0x0c072922u: goto P_0c072922;
case 0x0c072924u: goto P_0c072924;
case 0x0c072926u: goto P_0c072926;
case 0x0c072928u: goto P_0c072928;
case 0x0c07292au: goto P_0c07292a;
case 0x0c07292cu: goto P_0c07292c;
case 0x0c07292eu: goto P_0c07292e;
case 0x0c072930u: goto P_0c072930;
case 0x0c072932u: goto P_0c072932;
case 0x0c072934u: goto P_0c072934;
case 0x0c072936u: goto P_0c072936;
case 0x0c072938u: goto P_0c072938;
case 0x0c07293au: goto P_0c07293a;
case 0x0c07293cu: goto P_0c07293c;
case 0x0c07293eu: goto P_0c07293e;
case 0x0c072940u: goto P_0c072940;
case 0x0c072942u: goto P_0c072942;
case 0x0c072944u: goto P_0c072944;
case 0x0c072946u: goto P_0c072946;
case 0x0c072948u: goto P_0c072948;
case 0x0c07294au: goto P_0c07294a;
case 0x0c07294cu: goto P_0c07294c;
case 0x0c07294eu: goto P_0c07294e;
case 0x0c072950u: goto P_0c072950;
case 0x0c072952u: goto P_0c072952;
case 0x0c072954u: goto P_0c072954;
case 0x0c072956u: goto P_0c072956;
case 0x0c072958u: goto P_0c072958;
case 0x0c07295au: goto P_0c07295a;
case 0x0c07295cu: goto P_0c07295c;
case 0x0c07295eu: goto P_0c07295e;
case 0x0c072960u: goto P_0c072960;
case 0x0c072962u: goto P_0c072962;
case 0x0c072964u: goto P_0c072964;
case 0x0c072966u: goto P_0c072966;
case 0x0c072968u: goto P_0c072968;
case 0x0c07296au: goto P_0c07296a;
case 0x0c07296cu: goto P_0c07296c;
case 0x0c07296eu: goto P_0c07296e;
case 0x0c072970u: goto P_0c072970;
case 0x0c072972u: goto P_0c072972;
case 0x0c072974u: goto P_0c072974;
case 0x0c072976u: goto P_0c072976;
case 0x0c072978u: goto P_0c072978;
case 0x0c07297au: goto P_0c07297a;
case 0x0c07297cu: goto P_0c07297c;
case 0x0c07297eu: goto P_0c07297e;
case 0x0c072980u: goto P_0c072980;
case 0x0c072982u: goto P_0c072982;
case 0x0c072984u: goto P_0c072984;
case 0x0c072986u: goto P_0c072986;
case 0x0c072988u: goto P_0c072988;
case 0x0c07298au: goto P_0c07298a;
case 0x0c07298cu: goto P_0c07298c;
case 0x0c07298eu: goto P_0c07298e;
case 0x0c072990u: goto P_0c072990;
case 0x0c072992u: goto P_0c072992;
case 0x0c072994u: goto P_0c072994;
case 0x0c072996u: goto P_0c072996;
case 0x0c072998u: goto P_0c072998;
case 0x0c07299au: goto P_0c07299a;
case 0x0c07299cu: goto P_0c07299c;
case 0x0c07299eu: goto P_0c07299e;
case 0x0c0729a0u: goto P_0c0729a0;
case 0x0c0729a2u: goto P_0c0729a2;
case 0x0c0729a4u: goto P_0c0729a4;
case 0x0c0729a6u: goto P_0c0729a6;
case 0x0c0729a8u: goto P_0c0729a8;
case 0x0c0729aau: goto P_0c0729aa;
case 0x0c0729acu: goto P_0c0729ac;
case 0x0c0729aeu: goto P_0c0729ae;
case 0x0c0729b0u: goto P_0c0729b0;
case 0x0c0729b2u: goto P_0c0729b2;
case 0x0c0729b4u: goto P_0c0729b4;
case 0x0c0729b6u: goto P_0c0729b6;
case 0x0c0729b8u: goto P_0c0729b8;
case 0x0c0729bau: goto P_0c0729ba;
case 0x0c0729bcu: goto P_0c0729bc;
case 0x0c0729beu: goto P_0c0729be;
case 0x0c0729c0u: goto P_0c0729c0;
case 0x0c0729c2u: goto P_0c0729c2;
case 0x0c0729c4u: goto P_0c0729c4;
case 0x0c0729c6u: goto P_0c0729c6;
case 0x0c0729c8u: goto P_0c0729c8;
case 0x0c0729cau: goto P_0c0729ca;
case 0x0c0729ccu: goto P_0c0729cc;
case 0x0c0729ceu: goto P_0c0729ce;
case 0x0c0729d0u: goto P_0c0729d0;
case 0x0c0729d2u: goto P_0c0729d2;
case 0x0c0729d4u: goto P_0c0729d4;
case 0x0c0729d6u: goto P_0c0729d6;
case 0x0c0729d8u: goto P_0c0729d8;
case 0x0c0729dau: goto P_0c0729da;
case 0x0c0729dcu: goto P_0c0729dc;
case 0x0c0729deu: goto P_0c0729de;
case 0x0c0729e0u: goto P_0c0729e0;
case 0x0c0729e2u: goto P_0c0729e2;
case 0x0c0729e4u: goto P_0c0729e4;
case 0x0c0729e6u: goto P_0c0729e6;
case 0x0c0729e8u: goto P_0c0729e8;
case 0x0c0729eau: goto P_0c0729ea;
case 0x0c0729ecu: goto P_0c0729ec;
case 0x0c0729eeu: goto P_0c0729ee;
case 0x0c0729f0u: goto P_0c0729f0;
case 0x0c0729f2u: goto P_0c0729f2;
case 0x0c0729f4u: goto P_0c0729f4;
case 0x0c0729f6u: goto P_0c0729f6;
case 0x0c0729f8u: goto P_0c0729f8;
case 0x0c0729fau: goto P_0c0729fa;
case 0x0c0729fcu: goto P_0c0729fc;
case 0x0c0729feu: goto P_0c0729fe;
case 0x0c072a00u: goto P_0c072a00;
case 0x0c072a02u: goto P_0c072a02;
case 0x0c072a04u: goto P_0c072a04;
case 0x0c072a06u: goto P_0c072a06;
case 0x0c072a08u: goto P_0c072a08;
case 0x0c072a0au: goto P_0c072a0a;
case 0x0c072a0cu: goto P_0c072a0c;
case 0x0c072a0eu: goto P_0c072a0e;
case 0x0c072a10u: goto P_0c072a10;
case 0x0c072a12u: goto P_0c072a12;
case 0x0c072a14u: goto P_0c072a14;
case 0x0c072a16u: goto P_0c072a16;
case 0x0c072a18u: goto P_0c072a18;
case 0x0c072a1au: goto P_0c072a1a;
case 0x0c072a1cu: goto P_0c072a1c;
case 0x0c072a1eu: goto P_0c072a1e;
case 0x0c072a24u: goto P_0c072a24;
case 0x0c072a26u: goto P_0c072a26;
case 0x0c072a28u: goto P_0c072a28;
case 0x0c072a2au: goto P_0c072a2a;
case 0x0c072a2cu: goto P_0c072a2c;
case 0x0c072a2eu: goto P_0c072a2e;
case 0x0c072a30u: goto P_0c072a30;
case 0x0c072a32u: goto P_0c072a32;
case 0x0c072a34u: goto P_0c072a34;
case 0x0c072a36u: goto P_0c072a36;
case 0x0c072a38u: goto P_0c072a38;
case 0x0c072a3au: goto P_0c072a3a;
case 0x0c072a3cu: goto P_0c072a3c;
case 0x0c072a3eu: goto P_0c072a3e;
case 0x0c072a40u: goto P_0c072a40;
case 0x0c072a42u: goto P_0c072a42;
case 0x0c072a44u: goto P_0c072a44;
case 0x0c072a46u: goto P_0c072a46;
case 0x0c072a48u: goto P_0c072a48;
case 0x0c072a4au: goto P_0c072a4a;
case 0x0c072a4cu: goto P_0c072a4c;
case 0x0c072a4eu: goto P_0c072a4e;
case 0x0c072a50u: goto P_0c072a50;
case 0x0c072a52u: goto P_0c072a52;
case 0x0c072a54u: goto P_0c072a54;
case 0x0c072a56u: goto P_0c072a56;
case 0x0c072a58u: goto P_0c072a58;
case 0x0c072a5au: goto P_0c072a5a;
case 0x0c072a5cu: goto P_0c072a5c;
case 0x0c072a5eu: goto P_0c072a5e;
case 0x0c072a60u: goto P_0c072a60;
case 0x0c072a62u: goto P_0c072a62;
case 0x0c072a64u: goto P_0c072a64;
case 0x0c072a66u: goto P_0c072a66;
case 0x0c072a68u: goto P_0c072a68;
case 0x0c072a6au: goto P_0c072a6a;
case 0x0c072a6cu: goto P_0c072a6c;
case 0x0c072a6eu: goto P_0c072a6e;
case 0x0c072a70u: goto P_0c072a70;
case 0x0c072a72u: goto P_0c072a72;
case 0x0c072a74u: goto P_0c072a74;
case 0x0c072a76u: goto P_0c072a76;
case 0x0c072a78u: goto P_0c072a78;
case 0x0c072a7au: goto P_0c072a7a;
case 0x0c072a7cu: goto P_0c072a7c;
case 0x0c072a7eu: goto P_0c072a7e;
case 0x0c072a80u: goto P_0c072a80;
case 0x0c072a82u: goto P_0c072a82;
case 0x0c072a84u: goto P_0c072a84;
case 0x0c072a86u: goto P_0c072a86;
case 0x0c072a88u: goto P_0c072a88;
case 0x0c072a8au: goto P_0c072a8a;
case 0x0c072a8cu: goto P_0c072a8c;
case 0x0c072a8eu: goto P_0c072a8e;
case 0x0c072a90u: goto P_0c072a90;
case 0x0c072a92u: goto P_0c072a92;
case 0x0c072a94u: goto P_0c072a94;
case 0x0c072a96u: goto P_0c072a96;
case 0x0c072a98u: goto P_0c072a98;
case 0x0c072a9au: goto P_0c072a9a;
case 0x0c072a9cu: goto P_0c072a9c;
case 0x0c072a9eu: goto P_0c072a9e;
case 0x0c072aa0u: goto P_0c072aa0;
case 0x0c072aa2u: goto P_0c072aa2;
case 0x0c072aa4u: goto P_0c072aa4;
case 0x0c072aa6u: goto P_0c072aa6;
case 0x0c072aa8u: goto P_0c072aa8;
case 0x0c072aaau: goto P_0c072aaa;
case 0x0c072aacu: goto P_0c072aac;
case 0x0c072aaeu: goto P_0c072aae;
case 0x0c072ab0u: goto P_0c072ab0;
case 0x0c072ab2u: goto P_0c072ab2;
case 0x0c072ab4u: goto P_0c072ab4;
case 0x0c072ab6u: goto P_0c072ab6;
case 0x0c072ab8u: goto P_0c072ab8;
case 0x0c072abau: goto P_0c072aba;
case 0x0c072abcu: goto P_0c072abc;
case 0x0c072abeu: goto P_0c072abe;
case 0x0c072ac0u: goto P_0c072ac0;
case 0x0c072ac2u: goto P_0c072ac2;
case 0x0c072ac4u: goto P_0c072ac4;
case 0x0c072ac6u: goto P_0c072ac6;
case 0x0c072ac8u: goto P_0c072ac8;
case 0x0c072acau: goto P_0c072aca;
case 0x0c072accu: goto P_0c072acc;
case 0x0c072aceu: goto P_0c072ace;
case 0x0c072ad0u: goto P_0c072ad0;
case 0x0c072ad2u: goto P_0c072ad2;
case 0x0c072ad4u: goto P_0c072ad4;
case 0x0c072ad6u: goto P_0c072ad6;
case 0x0c072ad8u: goto P_0c072ad8;
case 0x0c072adau: goto P_0c072ada;
case 0x0c072adcu: goto P_0c072adc;
case 0x0c072adeu: goto P_0c072ade;
case 0x0c072ae0u: goto P_0c072ae0;
case 0x0c072ae2u: goto P_0c072ae2;
case 0x0c072ae4u: goto P_0c072ae4;
case 0x0c072ae6u: goto P_0c072ae6;
case 0x0c072ae8u: goto P_0c072ae8;
case 0x0c072aeau: goto P_0c072aea;
case 0x0c072aecu: goto P_0c072aec;
case 0x0c072aeeu: goto P_0c072aee;
case 0x0c072af0u: goto P_0c072af0;
case 0x0c072af2u: goto P_0c072af2;
case 0x0c072af4u: goto P_0c072af4;
case 0x0c072af6u: goto P_0c072af6;
case 0x0c072af8u: goto P_0c072af8;
case 0x0c072afau: goto P_0c072afa;
case 0x0c072afcu: goto P_0c072afc;
case 0x0c072afeu: goto P_0c072afe;
case 0x0c072b00u: goto P_0c072b00;
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
case 0x0c08c83au: goto P_0c08c83a;
case 0x0c08c83cu: goto P_0c08c83c;
case 0x0c08c83eu: goto P_0c08c83e;
case 0x0c08c840u: goto P_0c08c840;
case 0x0c08c842u: goto P_0c08c842;
case 0x0c08c844u: goto P_0c08c844;
case 0x0c08c846u: goto P_0c08c846;
case 0x0c08c848u: goto P_0c08c848;
case 0x0c08c84au: goto P_0c08c84a;
case 0x0c08c84cu: goto P_0c08c84c;
case 0x0c08c84eu: goto P_0c08c84e;
case 0x0c08c850u: goto P_0c08c850;
case 0x0c08c852u: goto P_0c08c852;
case 0x0c08c854u: goto P_0c08c854;
case 0x0c08c856u: goto P_0c08c856;
case 0x0c08c858u: goto P_0c08c858;
case 0x0c08c85au: goto P_0c08c85a;
case 0x0c08c85cu: goto P_0c08c85c;
case 0x0c08c87cu: goto P_0c08c87c;
case 0x0c08c87eu: goto P_0c08c87e;
case 0x0c08c880u: goto P_0c08c880;
case 0x0c08c882u: goto P_0c08c882;
case 0x0c08c884u: goto P_0c08c884;
case 0x0c08c886u: goto P_0c08c886;
case 0x0c08c888u: goto P_0c08c888;
case 0x0c08c88au: goto P_0c08c88a;
case 0x0c08c88cu: goto P_0c08c88c;
case 0x0c08c88eu: goto P_0c08c88e;
case 0x0c08c890u: goto P_0c08c890;
case 0x0c08c892u: goto P_0c08c892;
case 0x0c08c894u: goto P_0c08c894;
case 0x0c08c896u: goto P_0c08c896;
case 0x0c08c898u: goto P_0c08c898;
case 0x0c08c89au: goto P_0c08c89a;
case 0x0c08c89cu: goto P_0c08c89c;
case 0x0c08c89eu: goto P_0c08c89e;
case 0x0c08c8a0u: goto P_0c08c8a0;
case 0x0c08c8a2u: goto P_0c08c8a2;
case 0x0c08c8a4u: goto P_0c08c8a4;
case 0x0c08c8a6u: goto P_0c08c8a6;
case 0x0c08c8a8u: goto P_0c08c8a8;
case 0x0c08c8aau: goto P_0c08c8aa;
case 0x0c08c8acu: goto P_0c08c8ac;
case 0x0c08c8aeu: goto P_0c08c8ae;
case 0x0c08c8b0u: goto P_0c08c8b0;
case 0x0c08c8b2u: goto P_0c08c8b2;
case 0x0c08c8b4u: goto P_0c08c8b4;
case 0x0c08c8b6u: goto P_0c08c8b6;
case 0x0c08c8b8u: goto P_0c08c8b8;
case 0x0c08c8bau: goto P_0c08c8ba;
case 0x0c08c8bcu: goto P_0c08c8bc;
case 0x0c08c8beu: goto P_0c08c8be;
case 0x0c08c8c0u: goto P_0c08c8c0;
case 0x0c08c8c2u: goto P_0c08c8c2;
case 0x0c08c8c4u: goto P_0c08c8c4;
case 0x0c08c8c6u: goto P_0c08c8c6;
case 0x0c08c8c8u: goto P_0c08c8c8;
case 0x0c08c8cau: goto P_0c08c8ca;
case 0x0c08c8ccu: goto P_0c08c8cc;
case 0x0c08c8ceu: goto P_0c08c8ce;
case 0x0c08c8d0u: goto P_0c08c8d0;
case 0x0c08c8d2u: goto P_0c08c8d2;
case 0x0c08c8d4u: goto P_0c08c8d4;
case 0x0c08c8d6u: goto P_0c08c8d6;
case 0x0c08c8d8u: goto P_0c08c8d8;
case 0x0c08c8dau: goto P_0c08c8da;
case 0x0c08c8dcu: goto P_0c08c8dc;
case 0x0c08c8deu: goto P_0c08c8de;
case 0x0c08c8e0u: goto P_0c08c8e0;
case 0x0c08c8e2u: goto P_0c08c8e2;
case 0x0c08c8e4u: goto P_0c08c8e4;
case 0x0c08c8e6u: goto P_0c08c8e6;
case 0x0c08c8e8u: goto P_0c08c8e8;
case 0x0c08c8eau: goto P_0c08c8ea;
case 0x0c08c8ecu: goto P_0c08c8ec;
case 0x0c08c8eeu: goto P_0c08c8ee;
case 0x0c08c8f0u: goto P_0c08c8f0;
case 0x0c08c8f2u: goto P_0c08c8f2;
case 0x0c08c8f4u: goto P_0c08c8f4;
case 0x0c08c8f6u: goto P_0c08c8f6;
case 0x0c08c8f8u: goto P_0c08c8f8;
case 0x0c08c8fau: goto P_0c08c8fa;
case 0x0c08c8fcu: goto P_0c08c8fc;
case 0x0c08c8feu: goto P_0c08c8fe;
case 0x0c08c900u: goto P_0c08c900;
case 0x0c08ccfcu: goto P_0c08ccfc;
case 0x0c08ccfeu: goto P_0c08ccfe;
case 0x0c08cd00u: goto P_0c08cd00;
case 0x0c08cd02u: goto P_0c08cd02;
case 0x0c08cd04u: goto P_0c08cd04;
case 0x0c08cd06u: goto P_0c08cd06;
case 0x0c08cd08u: goto P_0c08cd08;
case 0x0c08cd0au: goto P_0c08cd0a;
case 0x0c08cd0cu: goto P_0c08cd0c;
case 0x0c08cd0eu: goto P_0c08cd0e;
case 0x0c08cd10u: goto P_0c08cd10;
case 0x0c08cd12u: goto P_0c08cd12;
case 0x0c08cd14u: goto P_0c08cd14;
case 0x0c08cd16u: goto P_0c08cd16;
case 0x0c08cd18u: goto P_0c08cd18;
case 0x0c08cd1au: goto P_0c08cd1a;
case 0x0c08cd1cu: goto P_0c08cd1c;
case 0x0c08cd1eu: goto P_0c08cd1e;
case 0x0c08cd20u: goto P_0c08cd20;
case 0x0c08cd22u: goto P_0c08cd22;
case 0x0c08cd24u: goto P_0c08cd24;
case 0x0c08cd26u: goto P_0c08cd26;
case 0x0c08cd28u: goto P_0c08cd28;
case 0x0c08cd2au: goto P_0c08cd2a;
case 0x0c08cd2cu: goto P_0c08cd2c;
case 0x0c08cd2eu: goto P_0c08cd2e;
case 0x0c08cd30u: goto P_0c08cd30;
case 0x0c08cd32u: goto P_0c08cd32;
case 0x0c08cd34u: goto P_0c08cd34;
case 0x0c08cd36u: goto P_0c08cd36;
case 0x0c08cd38u: goto P_0c08cd38;
case 0x0c08cd3au: goto P_0c08cd3a;
case 0x0c08cd3cu: goto P_0c08cd3c;
case 0x0c08cd3eu: goto P_0c08cd3e;
case 0x0c08cd40u: goto P_0c08cd40;
case 0x0c08cd42u: goto P_0c08cd42;
case 0x0c08cd44u: goto P_0c08cd44;
case 0x0c08cd46u: goto P_0c08cd46;
case 0x0c08cd48u: goto P_0c08cd48;
case 0x0c08cd4au: goto P_0c08cd4a;
case 0x0c08cd4cu: goto P_0c08cd4c;
case 0x0c08cd4eu: goto P_0c08cd4e;
case 0x0c08cd50u: goto P_0c08cd50;
case 0x0c08cd52u: goto P_0c08cd52;
case 0x0c08cd54u: goto P_0c08cd54;
case 0x0c08cd56u: goto P_0c08cd56;
case 0x0c08cd58u: goto P_0c08cd58;
case 0x0c08cd5au: goto P_0c08cd5a;
case 0x0c08cd5cu: goto P_0c08cd5c;
case 0x0c08cd5eu: goto P_0c08cd5e;
case 0x0c08cd60u: goto P_0c08cd60;
case 0x0c08cd62u: goto P_0c08cd62;
case 0x0c08cd64u: goto P_0c08cd64;
case 0x0c08cd66u: goto P_0c08cd66;
case 0x0c08cd68u: goto P_0c08cd68;
case 0x0c08cd6au: goto P_0c08cd6a;
case 0x0c08cd6cu: goto P_0c08cd6c;
case 0x0c08cd6eu: goto P_0c08cd6e;
case 0x0c08cd70u: goto P_0c08cd70;
case 0x0c08cd72u: goto P_0c08cd72;
case 0x0c08cd74u: goto P_0c08cd74;
case 0x0c08cd76u: goto P_0c08cd76;
case 0x0c08cd78u: goto P_0c08cd78;
case 0x0c08cd7au: goto P_0c08cd7a;
case 0x0c08cd7cu: goto P_0c08cd7c;
case 0x0c08cd7eu: goto P_0c08cd7e;
case 0x0c08cd80u: goto P_0c08cd80;
case 0x0c08cd82u: goto P_0c08cd82;
case 0x0c08cd84u: goto P_0c08cd84;
case 0x0c08cd86u: goto P_0c08cd86;
case 0x0c08cd88u: goto P_0c08cd88;
case 0x0c08cd8au: goto P_0c08cd8a;
case 0x0c08cd8cu: goto P_0c08cd8c;
case 0x0c08cd8eu: goto P_0c08cd8e;
case 0x0c08cd90u: goto P_0c08cd90;
case 0x0c08cd92u: goto P_0c08cd92;
case 0x0c08cd94u: goto P_0c08cd94;
case 0x0c08cd96u: goto P_0c08cd96;
case 0x0c08cd98u: goto P_0c08cd98;
case 0x0c08cd9au: goto P_0c08cd9a;
case 0x0c08d00eu: goto P_0c08d00e;
case 0x0c08d010u: goto P_0c08d010;
case 0x0c08d012u: goto P_0c08d012;
case 0x0c08d014u: goto P_0c08d014;
case 0x0c08d016u: goto P_0c08d016;
case 0x0c08d018u: goto P_0c08d018;
case 0x0c08d01au: goto P_0c08d01a;
case 0x0c08d01cu: goto P_0c08d01c;
case 0x0c08d01eu: goto P_0c08d01e;
case 0x0c08d020u: goto P_0c08d020;
case 0x0c08d022u: goto P_0c08d022;
case 0x0c08d024u: goto P_0c08d024;
case 0x0c08d026u: goto P_0c08d026;
case 0x0c08d028u: goto P_0c08d028;
case 0x0c08d02au: goto P_0c08d02a;
case 0x0c08d02cu: goto P_0c08d02c;
case 0x0c08d02eu: goto P_0c08d02e;
case 0x0c08d030u: goto P_0c08d030;
case 0x0c08d032u: goto P_0c08d032;
case 0x0c08d034u: goto P_0c08d034;
case 0x0c08d036u: goto P_0c08d036;
case 0x0c08d038u: goto P_0c08d038;
case 0x0c08d03au: goto P_0c08d03a;
case 0x0c08d03cu: goto P_0c08d03c;
case 0x0c08d03eu: goto P_0c08d03e;
case 0x0c08d040u: goto P_0c08d040;
case 0x0c08d042u: goto P_0c08d042;
case 0x0c08d044u: goto P_0c08d044;
case 0x0c08d046u: goto P_0c08d046;
case 0x0c08d048u: goto P_0c08d048;
case 0x0c08d04au: goto P_0c08d04a;
case 0x0c08d04cu: goto P_0c08d04c;
case 0x0c08d04eu: goto P_0c08d04e;
case 0x0c08d050u: goto P_0c08d050;
case 0x0c08d052u: goto P_0c08d052;
case 0x0c08d054u: goto P_0c08d054;
case 0x0c08d056u: goto P_0c08d056;
case 0x0c08d058u: goto P_0c08d058;
case 0x0c08d05au: goto P_0c08d05a;
case 0x0c08d05cu: goto P_0c08d05c;
case 0x0c08d05eu: goto P_0c08d05e;
case 0x0c08d060u: goto P_0c08d060;
case 0x0c08d062u: goto P_0c08d062;
case 0x0c08d064u: goto P_0c08d064;
case 0x0c08d066u: goto P_0c08d066;
case 0x0c08d068u: goto P_0c08d068;
case 0x0c08d06au: goto P_0c08d06a;
case 0x0c08d06cu: goto P_0c08d06c;
case 0x0c08d06eu: goto P_0c08d06e;
case 0x0c08d070u: goto P_0c08d070;
case 0x0c08d072u: goto P_0c08d072;
case 0x0c08d074u: goto P_0c08d074;
case 0x0c08d076u: goto P_0c08d076;
case 0x0c08d078u: goto P_0c08d078;
case 0x0c08d07au: goto P_0c08d07a;
case 0x0c08d07cu: goto P_0c08d07c;
case 0x0c08d07eu: goto P_0c08d07e;
case 0x0c08d080u: goto P_0c08d080;
case 0x0c08d082u: goto P_0c08d082;
case 0x0c08d084u: goto P_0c08d084;
case 0x0c08d086u: goto P_0c08d086;
case 0x0c08d088u: goto P_0c08d088;
case 0x0c08d08au: goto P_0c08d08a;
case 0x0c08d08cu: goto P_0c08d08c;
case 0x0c08d08eu: goto P_0c08d08e;
case 0x0c08d090u: goto P_0c08d090;
case 0x0c08d092u: goto P_0c08d092;
case 0x0c08d094u: goto P_0c08d094;
case 0x0c08d096u: goto P_0c08d096;
case 0x0c08d098u: goto P_0c08d098;
case 0x0c08d09au: goto P_0c08d09a;
case 0x0c08d09cu: goto P_0c08d09c;
case 0x0c08d09eu: goto P_0c08d09e;
case 0x0c08d0a0u: goto P_0c08d0a0;
case 0x0c08d0a2u: goto P_0c08d0a2;
case 0x0c08d0a4u: goto P_0c08d0a4;
case 0x0c08d0a6u: goto P_0c08d0a6;
case 0x0c08d0a8u: goto P_0c08d0a8;
case 0x0c08d0b4u: goto P_0c08d0b4;
case 0x0c08d0b6u: goto P_0c08d0b6;
case 0x0c08d0b8u: goto P_0c08d0b8;
case 0x0c08d0bau: goto P_0c08d0ba;
case 0x0c08d0bcu: goto P_0c08d0bc;
case 0x0c08d0beu: goto P_0c08d0be;
case 0x0c08d0c0u: goto P_0c08d0c0;
case 0x0c08d0c2u: goto P_0c08d0c2;
case 0x0c08d0c4u: goto P_0c08d0c4;
case 0x0c08d0c6u: goto P_0c08d0c6;
case 0x0c08d0c8u: goto P_0c08d0c8;
case 0x0c08d0cau: goto P_0c08d0ca;
case 0x0c08d0ccu: goto P_0c08d0cc;
case 0x0c08d0ceu: goto P_0c08d0ce;
case 0x0c08d0d0u: goto P_0c08d0d0;
case 0x0c08d0d2u: goto P_0c08d0d2;
case 0x0c08d0d4u: goto P_0c08d0d4;
case 0x0c08d0d6u: goto P_0c08d0d6;
case 0x0c08d0d8u: goto P_0c08d0d8;
case 0x0c08d0dau: goto P_0c08d0da;
case 0x0c08d0dcu: goto P_0c08d0dc;
case 0x0c08d0deu: goto P_0c08d0de;
case 0x0c08d0e0u: goto P_0c08d0e0;
case 0x0c08d0e2u: goto P_0c08d0e2;
case 0x0c08d0e4u: goto P_0c08d0e4;
case 0x0c08d0e6u: goto P_0c08d0e6;
case 0x0c08d0e8u: goto P_0c08d0e8;
case 0x0c08d0eau: goto P_0c08d0ea;
case 0x0c08d0ecu: goto P_0c08d0ec;
case 0x0c08d158u: goto P_0c08d158;
case 0x0c08d15au: goto P_0c08d15a;
case 0x0c08d15cu: goto P_0c08d15c;
case 0x0c08d15eu: goto P_0c08d15e;
case 0x0c08d160u: goto P_0c08d160;
case 0x0c08d162u: goto P_0c08d162;
case 0x0c08d164u: goto P_0c08d164;
case 0x0c08d166u: goto P_0c08d166;
case 0x0c08d168u: goto P_0c08d168;
case 0x0c08d16au: goto P_0c08d16a;
case 0x0c08d16cu: goto P_0c08d16c;
case 0x0c08d16eu: goto P_0c08d16e;
case 0x0c08d170u: goto P_0c08d170;
case 0x0c08d172u: goto P_0c08d172;
case 0x0c08d174u: goto P_0c08d174;
case 0x0c08d176u: goto P_0c08d176;
case 0x0c08d178u: goto P_0c08d178;
case 0x0c08d17au: goto P_0c08d17a;
case 0x0c08d17cu: goto P_0c08d17c;
case 0x0c08d17eu: goto P_0c08d17e;
case 0x0c08d180u: goto P_0c08d180;
case 0x0c08d182u: goto P_0c08d182;
case 0x0c08d184u: goto P_0c08d184;
case 0x0c08d186u: goto P_0c08d186;
case 0x0c08d188u: goto P_0c08d188;
case 0x0c08d18au: goto P_0c08d18a;
case 0x0c08d18cu: goto P_0c08d18c;
case 0x0c08d18eu: goto P_0c08d18e;
case 0x0c08d190u: goto P_0c08d190;
case 0x0c0935f4u: goto P_0c0935f4;
case 0x0c0935f6u: goto P_0c0935f6;
case 0x0c0935f8u: goto P_0c0935f8;
case 0x0c0935fau: goto P_0c0935fa;
case 0x0c0935fcu: goto P_0c0935fc;
case 0x0c0935feu: goto P_0c0935fe;
case 0x0c093600u: goto P_0c093600;
case 0x0c093602u: goto P_0c093602;
case 0x0c093604u: goto P_0c093604;
case 0x0c093606u: goto P_0c093606;
case 0x0c093608u: goto P_0c093608;
case 0x0c09360au: goto P_0c09360a;
case 0x0c09360cu: goto P_0c09360c;
case 0x0c09360eu: goto P_0c09360e;
case 0x0c093610u: goto P_0c093610;
case 0x0c093612u: goto P_0c093612;
case 0x0c093614u: goto P_0c093614;
case 0x0c093616u: goto P_0c093616;
case 0x0c093618u: goto P_0c093618;
case 0x0c09361au: goto P_0c09361a;
case 0x0c09361cu: goto P_0c09361c;
case 0x0c09361eu: goto P_0c09361e;
case 0x0c093620u: goto P_0c093620;
case 0x0c093622u: goto P_0c093622;
case 0x0c093624u: goto P_0c093624;
case 0x0c093626u: goto P_0c093626;
case 0x0c093628u: goto P_0c093628;
case 0x0c09362au: goto P_0c09362a;
case 0x0c09362cu: goto P_0c09362c;
case 0x0c09362eu: goto P_0c09362e;
case 0x0c093630u: goto P_0c093630;
case 0x0c093632u: goto P_0c093632;
case 0x0c093634u: goto P_0c093634;
case 0x0c093636u: goto P_0c093636;
case 0x0c093638u: goto P_0c093638;
case 0x0c09564eu: goto P_0c09564e;
case 0x0c095650u: goto P_0c095650;
case 0x0c095652u: goto P_0c095652;
case 0x0c095654u: goto P_0c095654;
case 0x0c095656u: goto P_0c095656;
case 0x0c095658u: goto P_0c095658;
case 0x0c09565au: goto P_0c09565a;
case 0x0c09565cu: goto P_0c09565c;
case 0x0c09565eu: goto P_0c09565e;
case 0x0c095660u: goto P_0c095660;
case 0x0c095662u: goto P_0c095662;
case 0x0c095664u: goto P_0c095664;
case 0x0c095666u: goto P_0c095666;
case 0x0c095668u: goto P_0c095668;
case 0x0c09566au: goto P_0c09566a;
case 0x0c09566cu: goto P_0c09566c;
case 0x0c09566eu: goto P_0c09566e;
case 0x0c095670u: goto P_0c095670;
case 0x0c095672u: goto P_0c095672;
case 0x0c095674u: goto P_0c095674;
case 0x0c095676u: goto P_0c095676;
case 0x0c095678u: goto P_0c095678;
case 0x0c09567au: goto P_0c09567a;
case 0x0c09567cu: goto P_0c09567c;
case 0x0c09567eu: goto P_0c09567e;
case 0x0c095680u: goto P_0c095680;
case 0x0c095682u: goto P_0c095682;
case 0x0c095684u: goto P_0c095684;
case 0x0c095686u: goto P_0c095686;
case 0x0c095688u: goto P_0c095688;
case 0x0c09568au: goto P_0c09568a;
case 0x0c09568cu: goto P_0c09568c;
case 0x0c09568eu: goto P_0c09568e;
case 0x0c095690u: goto P_0c095690;
case 0x0c095692u: goto P_0c095692;
case 0x0c095694u: goto P_0c095694;
case 0x0c095696u: goto P_0c095696;
case 0x0c095698u: goto P_0c095698;
case 0x0c09569au: goto P_0c09569a;
case 0x0c09569cu: goto P_0c09569c;
case 0x0c0c148eu: goto P_0c0c148e;
case 0x0c0c1490u: goto P_0c0c1490;
case 0x0c0c1492u: goto P_0c0c1492;
case 0x0c0c1494u: goto P_0c0c1494;
case 0x0c0c1496u: goto P_0c0c1496;
case 0x0c0c1498u: goto P_0c0c1498;
case 0x0c0c149au: goto P_0c0c149a;
case 0x0c0c149cu: goto P_0c0c149c;
case 0x0c0c149eu: goto P_0c0c149e;
case 0x0c0c14a0u: goto P_0c0c14a0;
case 0x0c0c14a2u: goto P_0c0c14a2;
case 0x0c0c14a4u: goto P_0c0c14a4;
case 0x0c0c14a6u: goto P_0c0c14a6;
case 0x0c0c14a8u: goto P_0c0c14a8;
case 0x0c0c14aau: goto P_0c0c14aa;
case 0x0c0c14acu: goto P_0c0c14ac;
case 0x0c0c14aeu: goto P_0c0c14ae;
case 0x0c0c14b0u: goto P_0c0c14b0;
case 0x0c0c14b2u: goto P_0c0c14b2;
case 0x0c0c14b4u: goto P_0c0c14b4;
case 0x0c0c14b6u: goto P_0c0c14b6;
case 0x0c0c14b8u: goto P_0c0c14b8;
case 0x0c0c14bau: goto P_0c0c14ba;
case 0x0c0c14bcu: goto P_0c0c14bc;
case 0x0c0c14beu: goto P_0c0c14be;
case 0x0c0c14c0u: goto P_0c0c14c0;
case 0x0c0c14c2u: goto P_0c0c14c2;
case 0x0c0c14c4u: goto P_0c0c14c4;
case 0x0c0c14c6u: goto P_0c0c14c6;
case 0x0c0c14c8u: goto P_0c0c14c8;
case 0x0c0c14cau: goto P_0c0c14ca;
case 0x0c0c14ccu: goto P_0c0c14cc;
case 0x0c0c14ceu: goto P_0c0c14ce;
case 0x0c0c14d0u: goto P_0c0c14d0;
case 0x0c0c14d2u: goto P_0c0c14d2;
case 0x0c0c14d4u: goto P_0c0c14d4;
case 0x0c0c14d6u: goto P_0c0c14d6;
case 0x0c0c14d8u: goto P_0c0c14d8;
case 0x0c0c14dau: goto P_0c0c14da;
case 0x0c0c14dcu: goto P_0c0c14dc;
case 0x0c0c14deu: goto P_0c0c14de;
case 0x0c0c14e0u: goto P_0c0c14e0;
case 0x0c0c14e2u: goto P_0c0c14e2;
case 0x0c0c14e4u: goto P_0c0c14e4;
case 0x0c0c14e6u: goto P_0c0c14e6;
case 0x0c0c14e8u: goto P_0c0c14e8;
case 0x0c0c14eau: goto P_0c0c14ea;
case 0x0c0c14ecu: goto P_0c0c14ec;
case 0x0c0c14eeu: goto P_0c0c14ee;
case 0x0c0c14f0u: goto P_0c0c14f0;
case 0x0c0c14f2u: goto P_0c0c14f2;
case 0x0c0c14f4u: goto P_0c0c14f4;
case 0x0c0c14f6u: goto P_0c0c14f6;
case 0x0c0c14f8u: goto P_0c0c14f8;
case 0x0c0c14fau: goto P_0c0c14fa;
case 0x0c0c14fcu: goto P_0c0c14fc;
case 0x0c0c14feu: goto P_0c0c14fe;
case 0x0c0c1500u: goto P_0c0c1500;
case 0x0c0c1502u: goto P_0c0c1502;
case 0x0c0c1504u: goto P_0c0c1504;
case 0x0c0c1506u: goto P_0c0c1506;
case 0x0c0c1508u: goto P_0c0c1508;
case 0x0c0c150au: goto P_0c0c150a;
case 0x0c0c150cu: goto P_0c0c150c;
case 0x0c0c150eu: goto P_0c0c150e;
case 0x0c0c1510u: goto P_0c0c1510;
case 0x0c0c1512u: goto P_0c0c1512;
case 0x0c0c1514u: goto P_0c0c1514;
case 0x0c0c1516u: goto P_0c0c1516;
case 0x0c0c1518u: goto P_0c0c1518;
case 0x0c0c151au: goto P_0c0c151a;
case 0x0c0c151cu: goto P_0c0c151c;
case 0x0c0c151eu: goto P_0c0c151e;
case 0x0c0c1520u: goto P_0c0c1520;
case 0x0c0c1522u: goto P_0c0c1522;
case 0x0c0c1524u: goto P_0c0c1524;
case 0x0c0c1526u: goto P_0c0c1526;
case 0x0c0c1528u: goto P_0c0c1528;
case 0x0c0c152au: goto P_0c0c152a;
case 0x0c0c152cu: goto P_0c0c152c;
case 0x0c0c152eu: goto P_0c0c152e;
case 0x0c0c1530u: goto P_0c0c1530;
case 0x0c0c1532u: goto P_0c0c1532;
case 0x0c0c1534u: goto P_0c0c1534;
case 0x0c0c1536u: goto P_0c0c1536;
case 0x0c0c1538u: goto P_0c0c1538;
case 0x0c0c153au: goto P_0c0c153a;
case 0x0c0c153cu: goto P_0c0c153c;
case 0x0c0c153eu: goto P_0c0c153e;
case 0x0c0c1540u: goto P_0c0c1540;
case 0x0c0c1542u: goto P_0c0c1542;
case 0x0c0c1544u: goto P_0c0c1544;
case 0x0c0c1546u: goto P_0c0c1546;
case 0x0c0c1548u: goto P_0c0c1548;
case 0x0c0c154au: goto P_0c0c154a;
case 0x0c0c154cu: goto P_0c0c154c;
case 0x0c0c154eu: goto P_0c0c154e;
case 0x0c0c1550u: goto P_0c0c1550;
case 0x0c0c1552u: goto P_0c0c1552;
case 0x0c0c1554u: goto P_0c0c1554;
case 0x0c0c1556u: goto P_0c0c1556;
case 0x0c0c1558u: goto P_0c0c1558;
case 0x0c0c155au: goto P_0c0c155a;
case 0x0c0c155cu: goto P_0c0c155c;
case 0x0c0c155eu: goto P_0c0c155e;
case 0x0c0c1560u: goto P_0c0c1560;
case 0x0c0c1562u: goto P_0c0c1562;
case 0x0c0c1564u: goto P_0c0c1564;
case 0x0c0c1566u: goto P_0c0c1566;
case 0x0c0c1568u: goto P_0c0c1568;
case 0x0c0c156au: goto P_0c0c156a;
case 0x0c0c156cu: goto P_0c0c156c;
case 0x0c0c156eu: goto P_0c0c156e;
case 0x0c0c1570u: goto P_0c0c1570;
case 0x0c0c1572u: goto P_0c0c1572;
case 0x0c0c1574u: goto P_0c0c1574;
case 0x0c0c1576u: goto P_0c0c1576;
case 0x0c0c1578u: goto P_0c0c1578;
case 0x0c0c157au: goto P_0c0c157a;
case 0x0c0c157cu: goto P_0c0c157c;
case 0x0c0c157eu: goto P_0c0c157e;
case 0x0c0c1580u: goto P_0c0c1580;
case 0x0c0c1582u: goto P_0c0c1582;
case 0x0c0c1584u: goto P_0c0c1584;
case 0x0c0c1586u: goto P_0c0c1586;
case 0x0c0c1588u: goto P_0c0c1588;
case 0x0c0c158au: goto P_0c0c158a;
case 0x0c0c158cu: goto P_0c0c158c;
case 0x0c0c158eu: goto P_0c0c158e;
case 0x0c0c1590u: goto P_0c0c1590;
case 0x0c0c1592u: goto P_0c0c1592;
case 0x0c0c1594u: goto P_0c0c1594;
case 0x0c0c1596u: goto P_0c0c1596;
case 0x0c0c1598u: goto P_0c0c1598;
case 0x0c0c159au: goto P_0c0c159a;
case 0x0c0c159cu: goto P_0c0c159c;
case 0x0c0c159eu: goto P_0c0c159e;
case 0x0c0c15a0u: goto P_0c0c15a0;
case 0x0c0c15a2u: goto P_0c0c15a2;
case 0x0c0c15a4u: goto P_0c0c15a4;
case 0x0c0c15a6u: goto P_0c0c15a6;
case 0x0c0c15a8u: goto P_0c0c15a8;
case 0x0c0c15aau: goto P_0c0c15aa;
case 0x0c0c15acu: goto P_0c0c15ac;
case 0x0c0c15aeu: goto P_0c0c15ae;
case 0x0c0c15b0u: goto P_0c0c15b0;
case 0x0c0c15b2u: goto P_0c0c15b2;
case 0x0c0c15b4u: goto P_0c0c15b4;
case 0x0c0c1bd0u: goto P_0c0c1bd0;
case 0x0c0c1bd2u: goto P_0c0c1bd2;
case 0x0c0c1bd4u: goto P_0c0c1bd4;
case 0x0c0c1bd6u: goto P_0c0c1bd6;
case 0x0c0c1bd8u: goto P_0c0c1bd8;
case 0x0c0c1bdau: goto P_0c0c1bda;
case 0x0c0c1bdcu: goto P_0c0c1bdc;
case 0x0c0c1bdeu: goto P_0c0c1bde;
case 0x0c0c1be0u: goto P_0c0c1be0;
case 0x0c0c1be2u: goto P_0c0c1be2;
case 0x0c0c1be4u: goto P_0c0c1be4;
case 0x0c0c1be6u: goto P_0c0c1be6;
case 0x0c0c1be8u: goto P_0c0c1be8;
case 0x0c0c1beau: goto P_0c0c1bea;
case 0x0c0c1becu: goto P_0c0c1bec;
case 0x0c0c1beeu: goto P_0c0c1bee;
case 0x0c0c1bf0u: goto P_0c0c1bf0;
case 0x0c0c1bf2u: goto P_0c0c1bf2;
case 0x0c0c1bf4u: goto P_0c0c1bf4;
case 0x0c0c1bf6u: goto P_0c0c1bf6;
case 0x0c0c1bf8u: goto P_0c0c1bf8;
case 0x0c0c1bfau: goto P_0c0c1bfa;
case 0x0c0c1bfcu: goto P_0c0c1bfc;
case 0x0c0c1bfeu: goto P_0c0c1bfe;
case 0x0c0c1c00u: goto P_0c0c1c00;
case 0x0c0c1c02u: goto P_0c0c1c02;
case 0x0c0c1c04u: goto P_0c0c1c04;
case 0x0c0c1c06u: goto P_0c0c1c06;
case 0x0c0c1c08u: goto P_0c0c1c08;
case 0x0c0c1c0au: goto P_0c0c1c0a;
case 0x0c0c1c0cu: goto P_0c0c1c0c;
case 0x0c0c1c0eu: goto P_0c0c1c0e;
case 0x0c0c1c10u: goto P_0c0c1c10;
case 0x0c0c1c12u: goto P_0c0c1c12;
case 0x0c0c1c14u: goto P_0c0c1c14;
case 0x0c0c1c16u: goto P_0c0c1c16;
case 0x0c0c1c18u: goto P_0c0c1c18;
case 0x0c0c1c1au: goto P_0c0c1c1a;
case 0x0c0c1c1cu: goto P_0c0c1c1c;
case 0x0c0c1c1eu: goto P_0c0c1c1e;
case 0x0c0c1c20u: goto P_0c0c1c20;
case 0x0c0c1c22u: goto P_0c0c1c22;
case 0x0c0c1c24u: goto P_0c0c1c24;
case 0x0c0c1c26u: goto P_0c0c1c26;
case 0x0c0c1c28u: goto P_0c0c1c28;
case 0x0c0c1c2au: goto P_0c0c1c2a;
case 0x0c0c1c2cu: goto P_0c0c1c2c;
case 0x0c0c1c2eu: goto P_0c0c1c2e;
case 0x0c0c1c30u: goto P_0c0c1c30;
case 0x0c0c1c32u: goto P_0c0c1c32;
case 0x0c0c1c34u: goto P_0c0c1c34;
case 0x0c0c1c36u: goto P_0c0c1c36;
case 0x0c0c1c38u: goto P_0c0c1c38;
case 0x0c0c1c3au: goto P_0c0c1c3a;
case 0x0c0c1c3cu: goto P_0c0c1c3c;
case 0x0c0c1c3eu: goto P_0c0c1c3e;
case 0x0c0c1c40u: goto P_0c0c1c40;
case 0x0c0c1c42u: goto P_0c0c1c42;
case 0x0c0c1c44u: goto P_0c0c1c44;
case 0x0c0c1c46u: goto P_0c0c1c46;
case 0x0c0c1c48u: goto P_0c0c1c48;
case 0x0c0c1c4au: goto P_0c0c1c4a;
case 0x0c0c1c4cu: goto P_0c0c1c4c;
case 0x0c0c1c4eu: goto P_0c0c1c4e;
case 0x0c0c1c50u: goto P_0c0c1c50;
case 0x0c0c1c52u: goto P_0c0c1c52;
case 0x0c0c1c54u: goto P_0c0c1c54;
case 0x0c0c1c56u: goto P_0c0c1c56;
case 0x0c0c1c58u: goto P_0c0c1c58;
case 0x0c0c1c5au: goto P_0c0c1c5a;
case 0x0c0c1c5cu: goto P_0c0c1c5c;
case 0x0c0c1c5eu: goto P_0c0c1c5e;
case 0x0c0c1c60u: goto P_0c0c1c60;
case 0x0c0c1c62u: goto P_0c0c1c62;
case 0x0c0c1c64u: goto P_0c0c1c64;
case 0x0c0c1c66u: goto P_0c0c1c66;
case 0x0c0c1c68u: goto P_0c0c1c68;
case 0x0c0c1c6au: goto P_0c0c1c6a;
case 0x0c0c1c6cu: goto P_0c0c1c6c;
case 0x0c0c1c6eu: goto P_0c0c1c6e;
case 0x0c0c1c70u: goto P_0c0c1c70;
case 0x0c0c1c72u: goto P_0c0c1c72;
case 0x0c0c1c74u: goto P_0c0c1c74;
case 0x0c0c1c76u: goto P_0c0c1c76;
case 0x0c0c1c78u: goto P_0c0c1c78;
case 0x0c0c1c7au: goto P_0c0c1c7a;
case 0x0c0c1c7cu: goto P_0c0c1c7c;
case 0x0c0c1c7eu: goto P_0c0c1c7e;
case 0x0c0c1c80u: goto P_0c0c1c80;
case 0x0c0c1c82u: goto P_0c0c1c82;
case 0x0c0c1c84u: goto P_0c0c1c84;
case 0x0c0c1c86u: goto P_0c0c1c86;
case 0x0c0c1c88u: goto P_0c0c1c88;
case 0x0c0c1c8au: goto P_0c0c1c8a;
case 0x0c0c1c8cu: goto P_0c0c1c8c;
case 0x0c0c1c8eu: goto P_0c0c1c8e;
case 0x0c0c1c90u: goto P_0c0c1c90;
case 0x0c0c1c92u: goto P_0c0c1c92;
case 0x0c0c1c94u: goto P_0c0c1c94;
case 0x0c0c1c96u: goto P_0c0c1c96;
case 0x0c0c1c98u: goto P_0c0c1c98;
case 0x0c0c1c9au: goto P_0c0c1c9a;
case 0x0c0c1c9cu: goto P_0c0c1c9c;
case 0x0c0c1c9eu: goto P_0c0c1c9e;
case 0x0c0c1ca0u: goto P_0c0c1ca0;
case 0x0c0c1ca2u: goto P_0c0c1ca2;
case 0x0c0c1ca4u: goto P_0c0c1ca4;
case 0x0c0c1ca6u: goto P_0c0c1ca6;
case 0x0c0c1ca8u: goto P_0c0c1ca8;
case 0x0c0c1caau: goto P_0c0c1caa;
case 0x0c0c1cacu: goto P_0c0c1cac;
case 0x0c0c1caeu: goto P_0c0c1cae;
case 0x0c0c1cb0u: goto P_0c0c1cb0;
case 0x0c0c1cb2u: goto P_0c0c1cb2;
case 0x0c0c1cb4u: goto P_0c0c1cb4;
case 0x0c0c1cb6u: goto P_0c0c1cb6;
case 0x0c0c1cb8u: goto P_0c0c1cb8;
case 0x0c0c1cbau: goto P_0c0c1cba;
case 0x0c0c1cbcu: goto P_0c0c1cbc;
case 0x0c0c1cbeu: goto P_0c0c1cbe;
case 0x0c0c1cc0u: goto P_0c0c1cc0;
case 0x0c0c1cc2u: goto P_0c0c1cc2;
case 0x0c0c1ce4u: goto P_0c0c1ce4;
case 0x0c0c1ce6u: goto P_0c0c1ce6;
case 0x0c0c1ce8u: goto P_0c0c1ce8;
case 0x0c0c1ceau: goto P_0c0c1cea;
case 0x0c0c1cecu: goto P_0c0c1cec;
case 0x0c0c1ceeu: goto P_0c0c1cee;
case 0x0c0c1cf0u: goto P_0c0c1cf0;
case 0x0c0c1cf2u: goto P_0c0c1cf2;
case 0x0c0c1cf4u: goto P_0c0c1cf4;
case 0x0c0c1cf6u: goto P_0c0c1cf6;
case 0x0c0c1cf8u: goto P_0c0c1cf8;
case 0x0c0c1cfau: goto P_0c0c1cfa;
case 0x0c0c1cfcu: goto P_0c0c1cfc;
case 0x0c0c1cfeu: goto P_0c0c1cfe;
case 0x0c0c1d00u: goto P_0c0c1d00;
case 0x0c0c1d02u: goto P_0c0c1d02;
case 0x0c0c1d04u: goto P_0c0c1d04;
case 0x0c0c1d06u: goto P_0c0c1d06;
case 0x0c0c1d08u: goto P_0c0c1d08;
case 0x0c0c1d0au: goto P_0c0c1d0a;
case 0x0c0c1d0cu: goto P_0c0c1d0c;
case 0x0c0c1d0eu: goto P_0c0c1d0e;
case 0x0c0c1d10u: goto P_0c0c1d10;
case 0x0c0c1d12u: goto P_0c0c1d12;
case 0x0c0c1d14u: goto P_0c0c1d14;
case 0x0c0c1d16u: goto P_0c0c1d16;
case 0x0c0c1d18u: goto P_0c0c1d18;
case 0x0c0c1d1au: goto P_0c0c1d1a;
case 0x0c0c1d1cu: goto P_0c0c1d1c;
case 0x0c0c1d1eu: goto P_0c0c1d1e;
case 0x0c0c1d20u: goto P_0c0c1d20;
case 0x0c0c1d22u: goto P_0c0c1d22;
case 0x0c0c1d24u: goto P_0c0c1d24;
case 0x0c0c1d26u: goto P_0c0c1d26;
case 0x0c0c1d28u: goto P_0c0c1d28;
case 0x0c0c1d2au: goto P_0c0c1d2a;
case 0x0c0c1d2cu: goto P_0c0c1d2c;
case 0x0c0c1d2eu: goto P_0c0c1d2e;
case 0x0c0c1d30u: goto P_0c0c1d30;
case 0x0c0c1d32u: goto P_0c0c1d32;
case 0x0c0c1d34u: goto P_0c0c1d34;
case 0x0c0c1d36u: goto P_0c0c1d36;
case 0x0c0c1d38u: goto P_0c0c1d38;
case 0x0c0c1d3au: goto P_0c0c1d3a;
case 0x0c0c1d3cu: goto P_0c0c1d3c;
case 0x0c0c1d3eu: goto P_0c0c1d3e;
case 0x0c0c1d40u: goto P_0c0c1d40;
case 0x0c0c1d42u: goto P_0c0c1d42;
case 0x0c0c1d44u: goto P_0c0c1d44;
case 0x0c0c1d46u: goto P_0c0c1d46;
case 0x0c0c1d48u: goto P_0c0c1d48;
case 0x0c0c1d4au: goto P_0c0c1d4a;
case 0x0c0c1d4cu: goto P_0c0c1d4c;
case 0x0c0c1d4eu: goto P_0c0c1d4e;
case 0x0c0c1d50u: goto P_0c0c1d50;
case 0x0c0c1d52u: goto P_0c0c1d52;
case 0x0c0c1d54u: goto P_0c0c1d54;
case 0x0c0c1d56u: goto P_0c0c1d56;
case 0x0c0c1d58u: goto P_0c0c1d58;
case 0x0c0c1d5au: goto P_0c0c1d5a;
case 0x0c0c1d5cu: goto P_0c0c1d5c;
case 0x0c0c1d5eu: goto P_0c0c1d5e;
case 0x0c0c1d60u: goto P_0c0c1d60;
case 0x0c0c1d62u: goto P_0c0c1d62;
case 0x0c0c1d64u: goto P_0c0c1d64;
case 0x0c0c1d66u: goto P_0c0c1d66;
case 0x0c0c1d68u: goto P_0c0c1d68;
case 0x0c0c1d6au: goto P_0c0c1d6a;
case 0x0c0c1d6cu: goto P_0c0c1d6c;
case 0x0c0c1d6eu: goto P_0c0c1d6e;
case 0x0c0c1d70u: goto P_0c0c1d70;
case 0x0c0c1d72u: goto P_0c0c1d72;
case 0x0c0c1d74u: goto P_0c0c1d74;
case 0x0c0c1d76u: goto P_0c0c1d76;
case 0x0c0c1d78u: goto P_0c0c1d78;
case 0x0c0c1d7au: goto P_0c0c1d7a;
case 0x0c0c1d7cu: goto P_0c0c1d7c;
case 0x0c0c1d7eu: goto P_0c0c1d7e;
case 0x0c0c1d80u: goto P_0c0c1d80;
case 0x0c0c1d82u: goto P_0c0c1d82;
case 0x0c0c1d84u: goto P_0c0c1d84;
case 0x0c0c1e44u: goto P_0c0c1e44;
case 0x0c0c1e46u: goto P_0c0c1e46;
case 0x0c0c1e48u: goto P_0c0c1e48;
case 0x0c0c1e4au: goto P_0c0c1e4a;
case 0x0c0c1e4cu: goto P_0c0c1e4c;
case 0x0c0c1e4eu: goto P_0c0c1e4e;
case 0x0c0c1e50u: goto P_0c0c1e50;
case 0x0c0c1e52u: goto P_0c0c1e52;
case 0x0c0c1e54u: goto P_0c0c1e54;
case 0x0c0c1e56u: goto P_0c0c1e56;
case 0x0c0c1e58u: goto P_0c0c1e58;
case 0x0c0c1e5au: goto P_0c0c1e5a;
case 0x0c0c1e5cu: goto P_0c0c1e5c;
case 0x0c0c1e5eu: goto P_0c0c1e5e;
case 0x0c0c1e60u: goto P_0c0c1e60;
case 0x0c0c1e62u: goto P_0c0c1e62;
case 0x0c0c1e64u: goto P_0c0c1e64;
case 0x0c0c1e66u: goto P_0c0c1e66;
case 0x0c0c1e68u: goto P_0c0c1e68;
case 0x0c0c1e6au: goto P_0c0c1e6a;
case 0x0c0c1e6cu: goto P_0c0c1e6c;
case 0x0c0c1e6eu: goto P_0c0c1e6e;
case 0x0c0c1e70u: goto P_0c0c1e70;
case 0x0c0c1e72u: goto P_0c0c1e72;
case 0x0c0c1e74u: goto P_0c0c1e74;
case 0x0c0c1e76u: goto P_0c0c1e76;
case 0x0c0c1e78u: goto P_0c0c1e78;
case 0x0c0c1e7au: goto P_0c0c1e7a;
case 0x0c0c1e7cu: goto P_0c0c1e7c;
case 0x0c0c1e7eu: goto P_0c0c1e7e;
case 0x0c0c1e80u: goto P_0c0c1e80;
case 0x0c0c1e82u: goto P_0c0c1e82;
case 0x0c0c1e84u: goto P_0c0c1e84;
case 0x0c0c1e86u: goto P_0c0c1e86;
case 0x0c0c1e88u: goto P_0c0c1e88;
case 0x0c0c1e8au: goto P_0c0c1e8a;
case 0x0c0c1e8cu: goto P_0c0c1e8c;
case 0x0c0c1e8eu: goto P_0c0c1e8e;
case 0x0c0c1e90u: goto P_0c0c1e90;
case 0x0c0c1e92u: goto P_0c0c1e92;
case 0x0c0c1e94u: goto P_0c0c1e94;
case 0x0c0c1e96u: goto P_0c0c1e96;
case 0x0c0c1e98u: goto P_0c0c1e98;
case 0x0c0c1e9au: goto P_0c0c1e9a;
case 0x0c0c1e9cu: goto P_0c0c1e9c;
case 0x0c0c1e9eu: goto P_0c0c1e9e;
case 0x0c0c1ea0u: goto P_0c0c1ea0;
case 0x0c0c1ea2u: goto P_0c0c1ea2;
case 0x0c0c1ea4u: goto P_0c0c1ea4;
case 0x0c0c1ea6u: goto P_0c0c1ea6;
case 0x0c0c1ea8u: goto P_0c0c1ea8;
case 0x0c0c1eaau: goto P_0c0c1eaa;
case 0x0c0c1eacu: goto P_0c0c1eac;
case 0x0c0c1eaeu: goto P_0c0c1eae;
case 0x0c0c1eb0u: goto P_0c0c1eb0;
case 0x0c0c1eb2u: goto P_0c0c1eb2;
case 0x0c0c1eb4u: goto P_0c0c1eb4;
case 0x0c0c1eb6u: goto P_0c0c1eb6;
case 0x0c0c1eb8u: goto P_0c0c1eb8;
case 0x0c0c1ebau: goto P_0c0c1eba;
case 0x0c0c1ebcu: goto P_0c0c1ebc;
case 0x0c0c1ebeu: goto P_0c0c1ebe;
case 0x0c0c1ec0u: goto P_0c0c1ec0;
case 0x0c0c1ec2u: goto P_0c0c1ec2;
case 0x0c0c1ec4u: goto P_0c0c1ec4;
case 0x0c0c1ec6u: goto P_0c0c1ec6;
case 0x0c0c1ec8u: goto P_0c0c1ec8;
case 0x0c0c1ecau: goto P_0c0c1eca;
case 0x0c0c1eccu: goto P_0c0c1ecc;
case 0x0c0c1eceu: goto P_0c0c1ece;
case 0x0c0c1ed0u: goto P_0c0c1ed0;
case 0x0c0c1ed2u: goto P_0c0c1ed2;
case 0x0c0c1ed4u: goto P_0c0c1ed4;
case 0x0c0c1ed6u: goto P_0c0c1ed6;
case 0x0c0c1ed8u: goto P_0c0c1ed8;
case 0x0c0c1edau: goto P_0c0c1eda;
case 0x0c0c1edcu: goto P_0c0c1edc;
case 0x0c0c1edeu: goto P_0c0c1ede;
case 0x0c0c1ee0u: goto P_0c0c1ee0;
case 0x0c0c1ee2u: goto P_0c0c1ee2;
case 0x0c0c1ee4u: goto P_0c0c1ee4;
case 0x0c0c1ee6u: goto P_0c0c1ee6;
case 0x0c0c1ee8u: goto P_0c0c1ee8;
case 0x0c0c1eeau: goto P_0c0c1eea;
case 0x0c0c1eecu: goto P_0c0c1eec;
case 0x0c0c1eeeu: goto P_0c0c1eee;
case 0x0c0c1ef0u: goto P_0c0c1ef0;
case 0x0c0c1ef2u: goto P_0c0c1ef2;
case 0x0c0c1ef4u: goto P_0c0c1ef4;
case 0x0c0c1ef6u: goto P_0c0c1ef6;
case 0x0c0c1ef8u: goto P_0c0c1ef8;
case 0x0c0c1efau: goto P_0c0c1efa;
case 0x0c0c1efcu: goto P_0c0c1efc;
case 0x0c0c1efeu: goto P_0c0c1efe;
case 0x0c0c1f00u: goto P_0c0c1f00;
case 0x0c0c1f02u: goto P_0c0c1f02;
case 0x0c0c1f04u: goto P_0c0c1f04;
case 0x0c0c1f06u: goto P_0c0c1f06;
case 0x0c0c1f08u: goto P_0c0c1f08;
case 0x0c0c1f0au: goto P_0c0c1f0a;
case 0x0c0c1f0cu: goto P_0c0c1f0c;
case 0x0c0c1f0eu: goto P_0c0c1f0e;
case 0x0c0c1f10u: goto P_0c0c1f10;
case 0x0c0c1f12u: goto P_0c0c1f12;
case 0x0c0c1f14u: goto P_0c0c1f14;
case 0x0c0c1f16u: goto P_0c0c1f16;
case 0x0c0c1f18u: goto P_0c0c1f18;
case 0x0c0c1f1au: goto P_0c0c1f1a;
case 0x0c0c1f1cu: goto P_0c0c1f1c;
case 0x0c0c1f1eu: goto P_0c0c1f1e;
case 0x0c0c1f20u: goto P_0c0c1f20;
case 0x0c0c1f22u: goto P_0c0c1f22;
case 0x0c0c1f24u: goto P_0c0c1f24;
case 0x0c0c1f26u: goto P_0c0c1f26;
case 0x0c0c1f28u: goto P_0c0c1f28;
case 0x0c0c1f2au: goto P_0c0c1f2a;
case 0x0c0c1f2cu: goto P_0c0c1f2c;
case 0x0c0c1f2eu: goto P_0c0c1f2e;
case 0x0c0c1f30u: goto P_0c0c1f30;
case 0x0c0c9ce6u: goto P_0c0c9ce6;
case 0x0c0c9ce8u: goto P_0c0c9ce8;
case 0x0c0c9ceau: goto P_0c0c9cea;
case 0x0c0c9cecu: goto P_0c0c9cec;
case 0x0c0c9ceeu: goto P_0c0c9cee;
case 0x0c0c9cf0u: goto P_0c0c9cf0;
case 0x0c0c9cf2u: goto P_0c0c9cf2;
case 0x0c0c9cf4u: goto P_0c0c9cf4;
case 0x0c0c9cf6u: goto P_0c0c9cf6;
case 0x0c0c9cf8u: goto P_0c0c9cf8;
case 0x0c0c9cfau: goto P_0c0c9cfa;
case 0x0c0c9cfcu: goto P_0c0c9cfc;
case 0x0c0c9cfeu: goto P_0c0c9cfe;
case 0x0c0c9d00u: goto P_0c0c9d00;
case 0x0c0c9d02u: goto P_0c0c9d02;
default: return vf3_matrix_family(target,s,ram);
}
P_0c039e58: /* original 4f22, guest PC 0x0c039e58 */
if(!s->budget--) { s->failed_pc=0x0c039e58u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c039e5a;
P_0c039e5a: /* original 8b09, guest PC 0x0c039e5a */
if(!s->budget--) { s->failed_pc=0x0c039e5au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c039e70; }
goto P_0c039e5c;
P_0c039e5c: /* original 4f26, guest PC 0x0c039e5c */
if(!s->budget--) { s->failed_pc=0x0c039e5cu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c039e5e;
P_0c039e5e: /* original 000b, guest PC 0x0c039e5e */
if(!s->budget--) { s->failed_pc=0x0c039e5eu; return 0; }
target=r[16];
r[0]=0x00000000u;
s->pc=target; return ram->oob==0;
P_0c039e60: /* original e000, guest PC 0x0c039e60 */
if(!s->budget--) { s->failed_pc=0x0c039e60u; return 0; }
r[0]=0x00000000u;
return vf3_matrix_family(0x0c039e62u,s,ram);
P_0c039e70: /* original b06e, guest PC 0x0c039e70 */
if(!s->budget--) { s->failed_pc=0x0c039e70u; return 0; }
target=0x0c039f50u; r[16]=0x0c039e74u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c039e74u) { target=s->pc; goto dispatch; }
goto P_0c039e74;
P_0c039e72: /* original 0009, guest PC 0x0c039e72 */
if(!s->budget--) { s->failed_pc=0x0c039e72u; return 0; }
goto P_0c039e74;
P_0c039e74: /* original 9376, guest PC 0x0c039e74 */
if(!s->budget--) { s->failed_pc=0x0c039e74u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c039f64u,2);
goto P_0c039e76;
P_0c039e76: /* original 600b, guest PC 0x0c039e76 */
if(!s->budget--) { s->failed_pc=0x0c039e76u; return 0; }
r[0]=0u-r[0];
goto P_0c039e78;
P_0c039e78: /* original d23b, guest PC 0x0c039e78 */
if(!s->budget--) { s->failed_pc=0x0c039e78u; return 0; }
r[2]=read(ram,0x0c039f68u,4);
goto P_0c039e7a;
P_0c039e7a: /* original 303c, guest PC 0x0c039e7a */
if(!s->budget--) { s->failed_pc=0x0c039e7au; return 0; }
r[0]+=r[3];
goto P_0c039e7c;
P_0c039e7c: /* original 2029, guest PC 0x0c039e7c */
if(!s->budget--) { s->failed_pc=0x0c039e7cu; return 0; }
r[0]&=r[2];
goto P_0c039e7e;
P_0c039e7e: /* original 4f26, guest PC 0x0c039e7e */
if(!s->budget--) { s->failed_pc=0x0c039e7eu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c039e80;
P_0c039e80: /* original 000b, guest PC 0x0c039e80 */
if(!s->budget--) { s->failed_pc=0x0c039e80u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c039e82: /* original 0009, guest PC 0x0c039e82 */
if(!s->budget--) { s->failed_pc=0x0c039e82u; return 0; }
return vf3_matrix_family(0x0c039e84u,s,ram);
P_0c039f50: /* original fffb, guest PC 0x0c039f50 */
if(!s->budget--) { s->failed_pc=0x0c039f50u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c039f52;
P_0c039f52: /* original ffeb, guest PC 0x0c039f52 */
if(!s->budget--) { s->failed_pc=0x0c039f52u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,14,r[15]);
goto P_0c039f54;
P_0c039f54: /* original f34c, guest PC 0x0c039f54 */
if(!s->budget--) { s->failed_pc=0x0c039f54u; return 0; }
vf3_matrix_move(s,3,4);
goto P_0c039f56;
P_0c039f56: /* original f35d, guest PC 0x0c039f56 */
if(!s->budget--) { s->failed_pc=0x0c039f56u; return 0; }
fr[3]&=0x7fffffffu;
goto P_0c039f58;
P_0c039f58: /* original f29d, guest PC 0x0c039f58 */
if(!s->budget--) { s->failed_pc=0x0c039f58u; return 0; }
fr[2]=0x3f800000u;
goto P_0c039f5a;
P_0c039f5a: /* original f325, guest PC 0x0c039f5a */
if(!s->budget--) { s->failed_pc=0x0c039f5au; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[2]))!=0);
goto P_0c039f5c;
P_0c039f5c: /* original 8f08, guest PC 0x0c039f5c */
if(!s->budget--) { s->failed_pc=0x0c039f5cu; return 0; }
cond=r[17]&1u;
vf3_matrix_move(s,15,4);
if(!cond) { goto P_0c039f70; }
goto P_0c039f60;
P_0c039f5e: /* original ff4c, guest PC 0x0c039f5e */
if(!s->budget--) { s->failed_pc=0x0c039f5eu; return 0; }
vf3_matrix_move(s,15,4);
goto P_0c039f60;
P_0c039f60: /* original a01f, guest PC 0x0c039f60 */
if(!s->budget--) { s->failed_pc=0x0c039f60u; return 0; }
r[0]=0x00000000u;
goto P_0c039fa2;
P_0c039f62: /* original e000, guest PC 0x0c039f62 */
if(!s->budget--) { s->failed_pc=0x0c039f62u; return 0; }
r[0]=0x00000000u;
return vf3_matrix_family(0x0c039f64u,s,ram);
P_0c039f70: /* original f3fc, guest PC 0x0c039f70 */
if(!s->budget--) { s->failed_pc=0x0c039f70u; return 0; }
vf3_matrix_move(s,3,15);
goto P_0c039f72;
P_0c039f72: /* original f3f2, guest PC 0x0c039f72 */
if(!s->budget--) { s->failed_pc=0x0c039f72u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[15],r[18],'*');
goto P_0c039f74;
P_0c039f74: /* original f29d, guest PC 0x0c039f74 */
if(!s->budget--) { s->failed_pc=0x0c039f74u; return 0; }
fr[2]=0x3f800000u;
goto P_0c039f76;
P_0c039f76: /* original f231, guest PC 0x0c039f76 */
if(!s->budget--) { s->failed_pc=0x0c039f76u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'-');
goto P_0c039f78;
P_0c039f78: /* original f38d, guest PC 0x0c039f78 */
if(!s->budget--) { s->failed_pc=0x0c039f78u; return 0; }
fr[3]=0;
goto P_0c039f7a;
P_0c039f7a: /* original f26d, guest PC 0x0c039f7a */
if(!s->budget--) { s->failed_pc=0x0c039f7au; return 0; }
fr[2]=vf3_fpu_sqrt(fr[2],r[18]);
goto P_0c039f7c;
P_0c039f7c: /* original fe2c, guest PC 0x0c039f7c */
if(!s->budget--) { s->failed_pc=0x0c039f7cu; return 0; }
vf3_matrix_move(s,14,2);
goto P_0c039f7e;
P_0c039f7e: /* original fe34, guest PC 0x0c039f7e */
if(!s->budget--) { s->failed_pc=0x0c039f7eu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[14])==as_float(fr[3]))!=0);
goto P_0c039f80;
P_0c039f80: /* original 8906, guest PC 0x0c039f80 */
if(!s->budget--) { s->failed_pc=0x0c039f80u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c039f90; }
goto P_0c039f82;
P_0c039f82: /* original f4fc, guest PC 0x0c039f82 */
if(!s->budget--) { s->failed_pc=0x0c039f82u; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c039f84;
P_0c039f84: /* original f4e3, guest PC 0x0c039f84 */
if(!s->budget--) { s->failed_pc=0x0c039f84u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[14],r[18],'/');
goto P_0c039f86;
P_0c039f86: /* original fef9, guest PC 0x0c039f86 */
if(!s->budget--) { s->failed_pc=0x0c039f86u; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c039f88;
P_0c039f88: /* original a022, guest PC 0x0c039f88 */
if(!s->budget--) { s->failed_pc=0x0c039f88u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c039fd0;
P_0c039f8a: /* original fff9, guest PC 0x0c039f8a */
if(!s->budget--) { s->failed_pc=0x0c039f8au; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
return vf3_matrix_family(0x0c039f8cu,s,ram);
P_0c039f90: /* original ff35, guest PC 0x0c039f90 */
if(!s->budget--) { s->failed_pc=0x0c039f90u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[15])>as_float(fr[3]))!=0);
goto P_0c039f92;
P_0c039f92: /* original 8b05, guest PC 0x0c039f92 */
if(!s->budget--) { s->failed_pc=0x0c039f92u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c039fa0; }
goto P_0c039f94;
P_0c039f94: /* original 905f, guest PC 0x0c039f94 */
if(!s->budget--) { s->failed_pc=0x0c039f94u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c03a056u,2);
goto P_0c039f96;
P_0c039f96: /* original a004, guest PC 0x0c039f96 */
if(!s->budget--) { s->failed_pc=0x0c039f96u; return 0; }
goto P_0c039fa2;
P_0c039f98: /* original 0009, guest PC 0x0c039f98 */
if(!s->budget--) { s->failed_pc=0x0c039f98u; return 0; }
return vf3_matrix_family(0x0c039f9au,s,ram);
P_0c039fa0: /* original d02d, guest PC 0x0c039fa0 */
if(!s->budget--) { s->failed_pc=0x0c039fa0u; return 0; }
r[0]=read(ram,0x0c03a058u,4);
goto P_0c039fa2;
P_0c039fa2: /* original fef9, guest PC 0x0c039fa2 */
if(!s->budget--) { s->failed_pc=0x0c039fa2u; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c039fa4;
P_0c039fa4: /* original 000b, guest PC 0x0c039fa4 */
if(!s->budget--) { s->failed_pc=0x0c039fa4u; return 0; }
target=r[16];
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
s->pc=target; return ram->oob==0;
P_0c039fa6: /* original fff9, guest PC 0x0c039fa6 */
if(!s->budget--) { s->failed_pc=0x0c039fa6u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
return vf3_matrix_family(0x0c039fa8u,s,ram);
P_0c039fd0: /* original f34c, guest PC 0x0c039fd0 */
if(!s->budget--) { s->failed_pc=0x0c039fd0u; return 0; }
vf3_matrix_move(s,3,4);
goto P_0c039fd2;
P_0c039fd2: /* original f35d, guest PC 0x0c039fd2 */
if(!s->budget--) { s->failed_pc=0x0c039fd2u; return 0; }
fr[3]&=0x7fffffffu;
goto P_0c039fd4;
P_0c039fd4: /* original f69d, guest PC 0x0c039fd4 */
if(!s->budget--) { s->failed_pc=0x0c039fd4u; return 0; }
fr[6]=0x3f800000u;
goto P_0c039fd6;
P_0c039fd6: /* original f365, guest PC 0x0c039fd6 */
if(!s->budget--) { s->failed_pc=0x0c039fd6u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[6]))!=0);
goto P_0c039fd8;
P_0c039fd8: /* original 8d02, guest PC 0x0c039fd8 */
if(!s->budget--) { s->failed_pc=0x0c039fd8u; return 0; }
cond=r[17]&1u;
fr[7]=0;
if(cond) { goto P_0c039fe0; }
goto P_0c039fdc;
P_0c039fda: /* original f78d, guest PC 0x0c039fda */
if(!s->budget--) { s->failed_pc=0x0c039fdau; return 0; }
fr[7]=0;
goto P_0c039fdc;
P_0c039fdc: /* original a002, guest PC 0x0c039fdc */
if(!s->budget--) { s->failed_pc=0x0c039fdcu; return 0; }
vf3_matrix_move(s,5,4);
goto P_0c039fe4;
P_0c039fde: /* original f54c, guest PC 0x0c039fde */
if(!s->budget--) { s->failed_pc=0x0c039fdeu; return 0; }
vf3_matrix_move(s,5,4);
goto P_0c039fe0;
P_0c039fe0: /* original f56c, guest PC 0x0c039fe0 */
if(!s->budget--) { s->failed_pc=0x0c039fe0u; return 0; }
vf3_matrix_move(s,5,6);
goto P_0c039fe2;
P_0c039fe2: /* original f543, guest PC 0x0c039fe2 */
if(!s->budget--) { s->failed_pc=0x0c039fe2u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[4],r[18],'/');
goto P_0c039fe4;
P_0c039fe4: /* original e40d, guest PC 0x0c039fe4 */
if(!s->budget--) { s->failed_pc=0x0c039fe4u; return 0; }
r[4]=0x0000000du;
goto P_0c039fe6;
P_0c039fe6: /* original e501, guest PC 0x0c039fe6 */
if(!s->budget--) { s->failed_pc=0x0c039fe6u; return 0; }
r[5]=0x00000001u;
goto P_0c039fe8;
P_0c039fe8: /* original 445a, guest PC 0x0c039fe8 */
if(!s->budget--) { s->failed_pc=0x0c039fe8u; return 0; }
r[53]=r[4];
goto P_0c039fea;
P_0c039fea: /* original 6343, guest PC 0x0c039fea */
if(!s->budget--) { s->failed_pc=0x0c039feau; return 0; }
r[3]=r[4];
goto P_0c039fec;
P_0c039fec: /* original 4300, guest PC 0x0c039fec */
if(!s->budget--) { s->failed_pc=0x0c039fecu; return 0; }
r[17]=(r[17]&~1u)|((r[3]>>31)!=0);
r[3]<<=1;
goto P_0c039fee;
P_0c039fee: /* original 74ff, guest PC 0x0c039fee */
if(!s->budget--) { s->failed_pc=0x0c039feeu; return 0; }
r[4]+=0xffffffffu;
goto P_0c039ff0;
P_0c039ff0: /* original f32d, guest PC 0x0c039ff0 */
if(!s->budget--) { s->failed_pc=0x0c039ff0u; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c039ff2;
P_0c039ff2: /* original 435a, guest PC 0x0c039ff2 */
if(!s->budget--) { s->failed_pc=0x0c039ff2u; return 0; }
r[53]=r[3];
goto P_0c039ff4;
P_0c039ff4: /* original 3453, guest PC 0x0c039ff4 */
if(!s->budget--) { s->failed_pc=0x0c039ff4u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[5])!=0);
goto P_0c039ff6;
P_0c039ff6: /* original f22d, guest PC 0x0c039ff6 */
if(!s->budget--) { s->failed_pc=0x0c039ff6u; return 0; }
fr[2]=vf3_fpu_float(r[53],r[18]);
goto P_0c039ff8;
P_0c039ff8: /* original f83c, guest PC 0x0c039ff8 */
if(!s->budget--) { s->failed_pc=0x0c039ff8u; return 0; }
vf3_matrix_move(s,8,3);
goto P_0c039ffa;
P_0c039ffa: /* original f382, guest PC 0x0c039ffa */
if(!s->budget--) { s->failed_pc=0x0c039ffau; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[8],r[18],'*');
goto P_0c039ffc;
P_0c039ffc: /* original f270, guest PC 0x0c039ffc */
if(!s->budget--) { s->failed_pc=0x0c039ffcu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[7],r[18],'+');
goto P_0c039ffe;
P_0c039ffe: /* original f352, guest PC 0x0c039ffe */
if(!s->budget--) { s->failed_pc=0x0c039ffeu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[5],r[18],'*');
goto P_0c03a000;
P_0c03a000: /* original f260, guest PC 0x0c03a000 */
if(!s->budget--) { s->failed_pc=0x0c03a000u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[6],r[18],'+');
goto P_0c03a002;
P_0c03a002: /* original f352, guest PC 0x0c03a002 */
if(!s->budget--) { s->failed_pc=0x0c03a002u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[5],r[18],'*');
goto P_0c03a004;
P_0c03a004: /* original f73c, guest PC 0x0c03a004 */
if(!s->budget--) { s->failed_pc=0x0c03a004u; return 0; }
vf3_matrix_move(s,7,3);
goto P_0c03a006;
P_0c03a006: /* original 8def, guest PC 0x0c03a006 */
if(!s->budget--) { s->failed_pc=0x0c03a006u; return 0; }
cond=r[17]&1u;
fr[7]=vf3_fpu_binary(fr[7],fr[2],r[18],'/');
if(cond) { goto P_0c039fe8; }
goto P_0c03a00a;
P_0c03a008: /* original f723, guest PC 0x0c03a008 */
if(!s->budget--) { s->failed_pc=0x0c03a008u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[2],r[18],'/');
goto P_0c03a00a;
P_0c03a00a: /* original f760, guest PC 0x0c03a00a */
if(!s->budget--) { s->failed_pc=0x0c03a00au; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[6],r[18],'+');
goto P_0c03a00c;
P_0c03a00c: /* original c713, guest PC 0x0c03a00c */
if(!s->budget--) { s->failed_pc=0x0c03a00cu; return 0; }
r[0]=0x0c03a05cu;
goto P_0c03a00e;
P_0c03a00e: /* original f465, guest PC 0x0c03a00e */
if(!s->budget--) { s->failed_pc=0x0c03a00eu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[4])>as_float(fr[6]))!=0);
goto P_0c03a010;
P_0c03a010: /* original d315, guest PC 0x0c03a010 */
if(!s->budget--) { s->failed_pc=0x0c03a010u; return 0; }
r[3]=read(ram,0x0c03a068u,4);
goto P_0c03a012;
P_0c03a012: /* original f573, guest PC 0x0c03a012 */
if(!s->budget--) { s->failed_pc=0x0c03a012u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[7],r[18],'/');
goto P_0c03a014;
P_0c03a014: /* original f708, guest PC 0x0c03a014 */
if(!s->budget--) { s->failed_pc=0x0c03a014u; return 0; }
vf3_matrix_load(s,ram,7,r[0]);
goto P_0c03a016;
P_0c03a016: /* original c712, guest PC 0x0c03a016 */
if(!s->budget--) { s->failed_pc=0x0c03a016u; return 0; }
r[0]=0x0c03a060u;
goto P_0c03a018;
P_0c03a018: /* original f208, guest PC 0x0c03a018 */
if(!s->budget--) { s->failed_pc=0x0c03a018u; return 0; }
vf3_matrix_load(s,ram,2,r[0]);
goto P_0c03a01a;
P_0c03a01a: /* original c712, guest PC 0x0c03a01a */
if(!s->budget--) { s->failed_pc=0x0c03a01au; return 0; }
r[0]=0x0c03a064u;
goto P_0c03a01c;
P_0c03a01c: /* original f108, guest PC 0x0c03a01c */
if(!s->budget--) { s->failed_pc=0x0c03a01cu; return 0; }
vf3_matrix_load(s,ram,1,r[0]);
goto P_0c03a01e;
P_0c03a01e: /* original f35c, guest PC 0x0c03a01e */
if(!s->budget--) { s->failed_pc=0x0c03a01eu; return 0; }
vf3_matrix_move(s,3,5);
goto P_0c03a020;
P_0c03a020: /* original f370, guest PC 0x0c03a020 */
if(!s->budget--) { s->failed_pc=0x0c03a020u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[7],r[18],'+');
goto P_0c03a022;
P_0c03a022: /* original f322, guest PC 0x0c03a022 */
if(!s->budget--) { s->failed_pc=0x0c03a022u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[2],r[18],'*');
goto P_0c03a024;
P_0c03a024: /* original f373, guest PC 0x0c03a024 */
if(!s->budget--) { s->failed_pc=0x0c03a024u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[7],r[18],'/');
goto P_0c03a026;
P_0c03a026: /* original f310, guest PC 0x0c03a026 */
if(!s->budget--) { s->failed_pc=0x0c03a026u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[1],r[18],'+');
goto P_0c03a028;
P_0c03a028: /* original f33d, guest PC 0x0c03a028 */
if(!s->budget--) { s->failed_pc=0x0c03a028u; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c03a02a;
P_0c03a02a: /* original 045a, guest PC 0x0c03a02a */
if(!s->budget--) { s->failed_pc=0x0c03a02au; return 0; }
r[4]=r[53];
goto P_0c03a02c;
P_0c03a02c: /* original 8f08, guest PC 0x0c03a02c */
if(!s->budget--) { s->failed_pc=0x0c03a02cu; return 0; }
cond=r[17]&1u;
r[4]&=r[3];
if(!cond) { goto P_0c03a040; }
goto P_0c03a030;
P_0c03a02e: /* original 2439, guest PC 0x0c03a02e */
if(!s->budget--) { s->failed_pc=0x0c03a02eu; return 0; }
r[4]&=r[3];
goto P_0c03a030;
P_0c03a030: /* original 9011, guest PC 0x0c03a030 */
if(!s->budget--) { s->failed_pc=0x0c03a030u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c03a056u,2);
goto P_0c03a032;
P_0c03a032: /* original a00a, guest PC 0x0c03a032 */
if(!s->budget--) { s->failed_pc=0x0c03a032u; return 0; }
goto P_0c03a04a;
P_0c03a034: /* original 0009, guest PC 0x0c03a034 */
if(!s->budget--) { s->failed_pc=0x0c03a034u; return 0; }
return vf3_matrix_family(0x0c03a036u,s,ram);
P_0c03a040: /* original c70a, guest PC 0x0c03a040 */
if(!s->budget--) { s->failed_pc=0x0c03a040u; return 0; }
r[0]=0x0c03a06cu;
goto P_0c03a042;
P_0c03a042: /* original f308, guest PC 0x0c03a042 */
if(!s->budget--) { s->failed_pc=0x0c03a042u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c03a044;
P_0c03a044: /* original f345, guest PC 0x0c03a044 */
if(!s->budget--) { s->failed_pc=0x0c03a044u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[4]))!=0);
goto P_0c03a046;
P_0c03a046: /* original 8b03, guest PC 0x0c03a046 */
if(!s->budget--) { s->failed_pc=0x0c03a046u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c03a050; }
goto P_0c03a048;
P_0c03a048: /* original d003, guest PC 0x0c03a048 */
if(!s->budget--) { s->failed_pc=0x0c03a048u; return 0; }
r[0]=read(ram,0x0c03a058u,4);
goto P_0c03a04a;
P_0c03a04a: /* original 3048, guest PC 0x0c03a04a */
if(!s->budget--) { s->failed_pc=0x0c03a04au; return 0; }
r[0]-=r[4];
goto P_0c03a04c;
P_0c03a04c: /* original 000b, guest PC 0x0c03a04c */
if(!s->budget--) { s->failed_pc=0x0c03a04cu; return 0; }
target=r[16];
r[0]=r[0]&65535u;
s->pc=target; return ram->oob==0;
P_0c03a04e: /* original 600d, guest PC 0x0c03a04e */
if(!s->budget--) { s->failed_pc=0x0c03a04eu; return 0; }
r[0]=r[0]&65535u;
goto P_0c03a050;
P_0c03a050: /* original 6043, guest PC 0x0c03a050 */
if(!s->budget--) { s->failed_pc=0x0c03a050u; return 0; }
r[0]=r[4];
goto P_0c03a052;
P_0c03a052: /* original 000b, guest PC 0x0c03a052 */
if(!s->budget--) { s->failed_pc=0x0c03a052u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c03a054: /* original 0009, guest PC 0x0c03a054 */
if(!s->budget--) { s->failed_pc=0x0c03a054u; return 0; }
return vf3_matrix_family(0x0c03a056u,s,ram);
P_0c03f2e0: /* original 4f22, guest PC 0x0c03f2e0 */
if(!s->budget--) { s->failed_pc=0x0c03f2e0u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c03f2e2;
P_0c03f2e2: /* original 4311, guest PC 0x0c03f2e2 */
if(!s->budget--) { s->failed_pc=0x0c03f2e2u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>=0)!=0);
goto P_0c03f2e4;
P_0c03f2e4: /* original 8f03, guest PC 0x0c03f2e4 */
if(!s->budget--) { s->failed_pc=0x0c03f2e4u; return 0; }
cond=r[17]&1u;
r[12]=0x00000000u;
if(!cond) { goto P_0c03f2ee; }
goto P_0c03f2e8;
P_0c03f2e6: /* original ec00, guest PC 0x0c03f2e6 */
if(!s->budget--) { s->failed_pc=0x0c03f2e6u; return 0; }
r[12]=0x00000000u;
goto P_0c03f2e8;
P_0c03f2e8: /* original 5146, guest PC 0x0c03f2e8 */
if(!s->budget--) { s->failed_pc=0x0c03f2e8u; return 0; }
r[1]=read(ram,r[4]+24,4);
goto P_0c03f2ea;
P_0c03f2ea: /* original 2118, guest PC 0x0c03f2ea */
if(!s->budget--) { s->failed_pc=0x0c03f2eau; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[1])==0)!=0);
goto P_0c03f2ec;
P_0c03f2ec: /* original 8b30, guest PC 0x0c03f2ec */
if(!s->budget--) { s->failed_pc=0x0c03f2ecu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c03f350; }
goto P_0c03f2ee;
P_0c03f2ee: /* original a06c, guest PC 0x0c03f2ee */
if(!s->budget--) { s->failed_pc=0x0c03f2eeu; return 0; }
r[0]=0x00000000u;
goto P_0c03f3ca;
P_0c03f2f0: /* original e000, guest PC 0x0c03f2f0 */
if(!s->budget--) { s->failed_pc=0x0c03f2f0u; return 0; }
r[0]=0x00000000u;
return vf3_matrix_family(0x0c03f2f2u,s,ram);
P_0c03f350: /* original da65, guest PC 0x0c03f350 */
if(!s->budget--) { s->failed_pc=0x0c03f350u; return 0; }
r[10]=read(ram,0x0c03f4e8u,4);
goto P_0c03f352;
P_0c03f352: /* original 6d43, guest PC 0x0c03f352 */
if(!s->budget--) { s->failed_pc=0x0c03f352u; return 0; }
r[13]=r[4];
goto P_0c03f354;
P_0c03f354: /* original e901, guest PC 0x0c03f354 */
if(!s->budget--) { s->failed_pc=0x0c03f354u; return 0; }
r[9]=0x00000001u;
goto P_0c03f356;
P_0c03f356: /* original 7d18, guest PC 0x0c03f356 */
if(!s->budget--) { s->failed_pc=0x0c03f356u; return 0; }
r[13]+=0x00000018u;
goto P_0c03f358;
P_0c03f358: /* original e8ff, guest PC 0x0c03f358 */
if(!s->budget--) { s->failed_pc=0x0c03f358u; return 0; }
r[8]=0xffffffffu;
goto P_0c03f35a;
P_0c03f35a: /* original 6ed3, guest PC 0x0c03f35a */
if(!s->budget--) { s->failed_pc=0x0c03f35au; return 0; }
r[14]=r[13];
goto P_0c03f35c;
P_0c03f35c: /* original 55e8, guest PC 0x0c03f35c */
if(!s->budget--) { s->failed_pc=0x0c03f35cu; return 0; }
r[5]=read(ram,r[14]+32,4);
goto P_0c03f35e;
P_0c03f35e: /* original 4511, guest PC 0x0c03f35e */
if(!s->budget--) { s->failed_pc=0x0c03f35eu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[5]>=0)!=0);
goto P_0c03f360;
P_0c03f360: /* original 8f17, guest PC 0x0c03f360 */
if(!s->budget--) { s->failed_pc=0x0c03f360u; return 0; }
cond=r[17]&1u;
r[13]+=0x00000050u;
if(!cond) { goto P_0c03f392; }
goto P_0c03f364;
P_0c03f362: /* original 7d50, guest PC 0x0c03f362 */
if(!s->budget--) { s->failed_pc=0x0c03f362u; return 0; }
r[13]+=0x00000050u;
goto P_0c03f364;
P_0c03f364: /* original d261, guest PC 0x0c03f364 */
if(!s->budget--) { s->failed_pc=0x0c03f364u; return 0; }
r[2]=read(ram,0x0c03f4ecu,4);
goto P_0c03f366;
P_0c03f366: /* original d062, guest PC 0x0c03f366 */
if(!s->budget--) { s->failed_pc=0x0c03f366u; return 0; }
r[0]=read(ram,0x0c03f4f0u,4);
goto P_0c03f368;
P_0c03f368: /* original 6322, guest PC 0x0c03f368 */
if(!s->budget--) { s->failed_pc=0x0c03f368u; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c03f36a;
P_0c03f36a: /* original 6102, guest PC 0x0c03f36a */
if(!s->budget--) { s->failed_pc=0x0c03f36au; return 0; }
tmp=read(ram,r[0],4);
r[1]=tmp;
goto P_0c03f36c;
P_0c03f36c: /* original 353c, guest PC 0x0c03f36c */
if(!s->budget--) { s->failed_pc=0x0c03f36cu; return 0; }
r[5]+=r[3];
goto P_0c03f36e;
P_0c03f36e: /* original 6453, guest PC 0x0c03f36e */
if(!s->budget--) { s->failed_pc=0x0c03f36eu; return 0; }
r[4]=r[5];
goto P_0c03f370;
P_0c03f370: /* original 4408, guest PC 0x0c03f370 */
if(!s->budget--) { s->failed_pc=0x0c03f370u; return 0; }
r[4]<<=2;
goto P_0c03f372;
P_0c03f372: /* original 4400, guest PC 0x0c03f372 */
if(!s->budget--) { s->failed_pc=0x0c03f372u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c03f374;
P_0c03f374: /* original 341c, guest PC 0x0c03f374 */
if(!s->budget--) { s->failed_pc=0x0c03f374u; return 0; }
r[4]+=r[1];
goto P_0c03f376;
P_0c03f376: /* original 6342, guest PC 0x0c03f376 */
if(!s->budget--) { s->failed_pc=0x0c03f376u; return 0; }
tmp=read(ram,r[4],4);
r[3]=tmp;
goto P_0c03f378;
P_0c03f378: /* original 2338, guest PC 0x0c03f378 */
if(!s->budget--) { s->failed_pc=0x0c03f378u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c03f37a;
P_0c03f37a: /* original 8b09, guest PC 0x0c03f37a */
if(!s->budget--) { s->failed_pc=0x0c03f37au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c03f390; }
goto P_0c03f37c;
P_0c03f37c: /* original 6c93, guest PC 0x0c03f37c */
if(!s->budget--) { s->failed_pc=0x0c03f37cu; return 0; }
r[12]=r[9];
goto P_0c03f37e;
P_0c03f37e: /* original a008, guest PC 0x0c03f37e */
if(!s->budget--) { s->failed_pc=0x0c03f37eu; return 0; }
r[5]=r[8];
goto P_0c03f392;
P_0c03f380: /* original 6583, guest PC 0x0c03f380 */
if(!s->budget--) { s->failed_pc=0x0c03f380u; return 0; }
r[5]=r[8];
return vf3_matrix_family(0x0c03f382u,s,ram);
P_0c03f390: /* original 5541, guest PC 0x0c03f390 */
if(!s->budget--) { s->failed_pc=0x0c03f390u; return 0; }
r[5]=read(ram,r[4]+4,4);
goto P_0c03f392;
P_0c03f392: /* original 5be3, guest PC 0x0c03f392 */
if(!s->budget--) { s->failed_pc=0x0c03f392u; return 0; }
r[11]=read(ram,r[14]+12,4);
goto P_0c03f394;
P_0c03f394: /* original 4511, guest PC 0x0c03f394 */
if(!s->budget--) { s->failed_pc=0x0c03f394u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[5]>=0)!=0);
goto P_0c03f396;
P_0c03f396: /* original 8f0b, guest PC 0x0c03f396 */
if(!s->budget--) { s->failed_pc=0x0c03f396u; return 0; }
cond=r[17]&1u;
r[11]&=r[10];
if(!cond) { goto P_0c03f3b0; }
goto P_0c03f39a;
P_0c03f398: /* original 2ba9, guest PC 0x0c03f398 */
if(!s->budget--) { s->failed_pc=0x0c03f398u; return 0; }
r[11]&=r[10];
goto P_0c03f39a;
P_0c03f39a: /* original d356, guest PC 0x0c03f39a */
if(!s->budget--) { s->failed_pc=0x0c03f39au; return 0; }
r[3]=read(ram,0x0c03f4f4u,4);
goto P_0c03f39c;
P_0c03f39c: /* original 430b, guest PC 0x0c03f39c */
if(!s->budget--) { s->failed_pc=0x0c03f39cu; return 0; }
target=r[3];
r[16]=0x0c03f3a0u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c03f3a0u) { target=s->pc; goto dispatch; }
goto P_0c03f3a0;
P_0c03f39e: /* original 64e3, guest PC 0x0c03f39e */
if(!s->budget--) { s->failed_pc=0x0c03f39eu; return 0; }
r[4]=r[14];
goto P_0c03f3a0;
P_0c03f3a0: /* original a009, guest PC 0x0c03f3a0 */
if(!s->budget--) { s->failed_pc=0x0c03f3a0u; return 0; }
goto P_0c03f3b6;
P_0c03f3a2: /* original 0009, guest PC 0x0c03f3a2 */
if(!s->budget--) { s->failed_pc=0x0c03f3a2u; return 0; }
return vf3_matrix_family(0x0c03f3a4u,s,ram);
P_0c03f3b0: /* original d351, guest PC 0x0c03f3b0 */
if(!s->budget--) { s->failed_pc=0x0c03f3b0u; return 0; }
r[3]=read(ram,0x0c03f4f8u,4);
goto P_0c03f3b2;
P_0c03f3b2: /* original 430b, guest PC 0x0c03f3b2 */
if(!s->budget--) { s->failed_pc=0x0c03f3b2u; return 0; }
target=r[3];
r[16]=0x0c03f3b6u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c03f3b6u) { target=s->pc; goto dispatch; }
goto P_0c03f3b6;
P_0c03f3b4: /* original 64e3, guest PC 0x0c03f3b4 */
if(!s->budget--) { s->failed_pc=0x0c03f3b4u; return 0; }
r[4]=r[14];
goto P_0c03f3b6;
P_0c03f3b6: /* original e04c, guest PC 0x0c03f3b6 */
if(!s->budget--) { s->failed_pc=0x0c03f3b6u; return 0; }
r[0]=0x0000004cu;
goto P_0c03f3b8;
P_0c03f3b8: /* original 52e3, guest PC 0x0c03f3b8 */
if(!s->budget--) { s->failed_pc=0x0c03f3b8u; return 0; }
r[2]=read(ram,r[14]+12,4);
goto P_0c03f3ba;
P_0c03f3ba: /* original 22bb, guest PC 0x0c03f3ba */
if(!s->budget--) { s->failed_pc=0x0c03f3bau; return 0; }
r[2]|=r[11];
goto P_0c03f3bc;
P_0c03f3bc: /* original 1e23, guest PC 0x0c03f3bc */
if(!s->budget--) { s->failed_pc=0x0c03f3bcu; return 0; }
write(ram,r[14]+12,r[2],4);
goto P_0c03f3be;
P_0c03f3be: /* original 03ee, guest PC 0x0c03f3be */
if(!s->budget--) { s->failed_pc=0x0c03f3beu; return 0; }
r[3]=read(ram,r[14]+r[0],4);
goto P_0c03f3c0;
P_0c03f3c0: /* original 3d3c, guest PC 0x0c03f3c0 */
if(!s->budget--) { s->failed_pc=0x0c03f3c0u; return 0; }
r[13]+=r[3];
goto P_0c03f3c2;
P_0c03f3c2: /* original 64d2, guest PC 0x0c03f3c2 */
if(!s->budget--) { s->failed_pc=0x0c03f3c2u; return 0; }
tmp=read(ram,r[13],4);
r[4]=tmp;
goto P_0c03f3c4;
P_0c03f3c4: /* original 2448, guest PC 0x0c03f3c4 */
if(!s->budget--) { s->failed_pc=0x0c03f3c4u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c03f3c6;
P_0c03f3c6: /* original 8bc8, guest PC 0x0c03f3c6 */
if(!s->budget--) { s->failed_pc=0x0c03f3c6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c03f35a; }
goto P_0c03f3c8;
P_0c03f3c8: /* original 60c3, guest PC 0x0c03f3c8 */
if(!s->budget--) { s->failed_pc=0x0c03f3c8u; return 0; }
r[0]=r[12];
goto P_0c03f3ca;
P_0c03f3ca: /* original 4f26, guest PC 0x0c03f3ca */
if(!s->budget--) { s->failed_pc=0x0c03f3cau; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c03f3cc;
P_0c03f3cc: /* original 68f6, guest PC 0x0c03f3cc */
if(!s->budget--) { s->failed_pc=0x0c03f3ccu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c03f3ce;
P_0c03f3ce: /* original 69f6, guest PC 0x0c03f3ce */
if(!s->budget--) { s->failed_pc=0x0c03f3ceu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c03f3d0;
P_0c03f3d0: /* original 6af6, guest PC 0x0c03f3d0 */
if(!s->budget--) { s->failed_pc=0x0c03f3d0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c03f3d2;
P_0c03f3d2: /* original 6bf6, guest PC 0x0c03f3d2 */
if(!s->budget--) { s->failed_pc=0x0c03f3d2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c03f3d4;
P_0c03f3d4: /* original 6cf6, guest PC 0x0c03f3d4 */
if(!s->budget--) { s->failed_pc=0x0c03f3d4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c03f3d6;
P_0c03f3d6: /* original 6df6, guest PC 0x0c03f3d6 */
if(!s->budget--) { s->failed_pc=0x0c03f3d6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c03f3d8;
P_0c03f3d8: /* original 000b, guest PC 0x0c03f3d8 */
if(!s->budget--) { s->failed_pc=0x0c03f3d8u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c03f3da: /* original 6ef6, guest PC 0x0c03f3da */
if(!s->budget--) { s->failed_pc=0x0c03f3dau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c03f3dcu,s,ram);
P_0c042e44: /* original 2008, guest PC 0x0c042e44 */
if(!s->budget--) { s->failed_pc=0x0c042e44u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c042e46;
P_0c042e46: /* original 8d4e, guest PC 0x0c042e46 */
if(!s->budget--) { s->failed_pc=0x0c042e46u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c042ee6; }
goto P_0c042e4a;
P_0c042e48: /* original 0009, guest PC 0x0c042e48 */
if(!s->budget--) { s->failed_pc=0x0c042e48u; return 0; }
goto P_0c042e4a;
P_0c042e4a: /* original 2f36, guest PC 0x0c042e4a */
if(!s->budget--) { s->failed_pc=0x0c042e4au; return 0; }
r[15]-=4; write(ram,r[15],r[3],4);
goto P_0c042e4c;
P_0c042e4c: /* original e300, guest PC 0x0c042e4c */
if(!s->budget--) { s->failed_pc=0x0c042e4cu; return 0; }
r[3]=0x00000000u;
goto P_0c042e4e;
P_0c042e4e: /* original 2f46, guest PC 0x0c042e4e */
if(!s->budget--) { s->failed_pc=0x0c042e4eu; return 0; }
r[15]-=4; write(ram,r[15],r[4],4);
goto P_0c042e50;
P_0c042e50: /* original 6403, guest PC 0x0c042e50 */
if(!s->budget--) { s->failed_pc=0x0c042e50u; return 0; }
r[4]=r[0];
goto P_0c042e52;
P_0c042e52: /* original 0019, guest PC 0x0c042e52 */
if(!s->budget--) { s->failed_pc=0x0c042e52u; return 0; }
r[17]&=~0x301u;
goto P_0c042e54;
P_0c042e54: /* original 4124, guest PC 0x0c042e54 */
if(!s->budget--) { s->failed_pc=0x0c042e54u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042e56;
P_0c042e56: /* original 3344, guest PC 0x0c042e56 */
if(!s->budget--) { s->failed_pc=0x0c042e56u; return 0; }
divide_step(s,3,4);
goto P_0c042e58;
P_0c042e58: /* original 4124, guest PC 0x0c042e58 */
if(!s->budget--) { s->failed_pc=0x0c042e58u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042e5a;
P_0c042e5a: /* original 3344, guest PC 0x0c042e5a */
if(!s->budget--) { s->failed_pc=0x0c042e5au; return 0; }
divide_step(s,3,4);
goto P_0c042e5c;
P_0c042e5c: /* original 4124, guest PC 0x0c042e5c */
if(!s->budget--) { s->failed_pc=0x0c042e5cu; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042e5e;
P_0c042e5e: /* original 3344, guest PC 0x0c042e5e */
if(!s->budget--) { s->failed_pc=0x0c042e5eu; return 0; }
divide_step(s,3,4);
goto P_0c042e60;
P_0c042e60: /* original 4124, guest PC 0x0c042e60 */
if(!s->budget--) { s->failed_pc=0x0c042e60u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042e62;
P_0c042e62: /* original 3344, guest PC 0x0c042e62 */
if(!s->budget--) { s->failed_pc=0x0c042e62u; return 0; }
divide_step(s,3,4);
goto P_0c042e64;
P_0c042e64: /* original 4124, guest PC 0x0c042e64 */
if(!s->budget--) { s->failed_pc=0x0c042e64u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042e66;
P_0c042e66: /* original 3344, guest PC 0x0c042e66 */
if(!s->budget--) { s->failed_pc=0x0c042e66u; return 0; }
divide_step(s,3,4);
goto P_0c042e68;
P_0c042e68: /* original 4124, guest PC 0x0c042e68 */
if(!s->budget--) { s->failed_pc=0x0c042e68u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042e6a;
P_0c042e6a: /* original 3344, guest PC 0x0c042e6a */
if(!s->budget--) { s->failed_pc=0x0c042e6au; return 0; }
divide_step(s,3,4);
goto P_0c042e6c;
P_0c042e6c: /* original 4124, guest PC 0x0c042e6c */
if(!s->budget--) { s->failed_pc=0x0c042e6cu; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042e6e;
P_0c042e6e: /* original 3344, guest PC 0x0c042e6e */
if(!s->budget--) { s->failed_pc=0x0c042e6eu; return 0; }
divide_step(s,3,4);
goto P_0c042e70;
P_0c042e70: /* original 4124, guest PC 0x0c042e70 */
if(!s->budget--) { s->failed_pc=0x0c042e70u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042e72;
P_0c042e72: /* original 3344, guest PC 0x0c042e72 */
if(!s->budget--) { s->failed_pc=0x0c042e72u; return 0; }
divide_step(s,3,4);
goto P_0c042e74;
P_0c042e74: /* original 4124, guest PC 0x0c042e74 */
if(!s->budget--) { s->failed_pc=0x0c042e74u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042e76;
P_0c042e76: /* original 3344, guest PC 0x0c042e76 */
if(!s->budget--) { s->failed_pc=0x0c042e76u; return 0; }
divide_step(s,3,4);
goto P_0c042e78;
P_0c042e78: /* original 4124, guest PC 0x0c042e78 */
if(!s->budget--) { s->failed_pc=0x0c042e78u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042e7a;
P_0c042e7a: /* original 3344, guest PC 0x0c042e7a */
if(!s->budget--) { s->failed_pc=0x0c042e7au; return 0; }
divide_step(s,3,4);
goto P_0c042e7c;
P_0c042e7c: /* original 4124, guest PC 0x0c042e7c */
if(!s->budget--) { s->failed_pc=0x0c042e7cu; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042e7e;
P_0c042e7e: /* original 3344, guest PC 0x0c042e7e */
if(!s->budget--) { s->failed_pc=0x0c042e7eu; return 0; }
divide_step(s,3,4);
goto P_0c042e80;
P_0c042e80: /* original 4124, guest PC 0x0c042e80 */
if(!s->budget--) { s->failed_pc=0x0c042e80u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042e82;
P_0c042e82: /* original 3344, guest PC 0x0c042e82 */
if(!s->budget--) { s->failed_pc=0x0c042e82u; return 0; }
divide_step(s,3,4);
goto P_0c042e84;
P_0c042e84: /* original 4124, guest PC 0x0c042e84 */
if(!s->budget--) { s->failed_pc=0x0c042e84u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042e86;
P_0c042e86: /* original 3344, guest PC 0x0c042e86 */
if(!s->budget--) { s->failed_pc=0x0c042e86u; return 0; }
divide_step(s,3,4);
goto P_0c042e88;
P_0c042e88: /* original 4124, guest PC 0x0c042e88 */
if(!s->budget--) { s->failed_pc=0x0c042e88u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042e8a;
P_0c042e8a: /* original 3344, guest PC 0x0c042e8a */
if(!s->budget--) { s->failed_pc=0x0c042e8au; return 0; }
divide_step(s,3,4);
goto P_0c042e8c;
P_0c042e8c: /* original 4124, guest PC 0x0c042e8c */
if(!s->budget--) { s->failed_pc=0x0c042e8cu; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042e8e;
P_0c042e8e: /* original 3344, guest PC 0x0c042e8e */
if(!s->budget--) { s->failed_pc=0x0c042e8eu; return 0; }
divide_step(s,3,4);
goto P_0c042e90;
P_0c042e90: /* original 4124, guest PC 0x0c042e90 */
if(!s->budget--) { s->failed_pc=0x0c042e90u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042e92;
P_0c042e92: /* original 3344, guest PC 0x0c042e92 */
if(!s->budget--) { s->failed_pc=0x0c042e92u; return 0; }
divide_step(s,3,4);
goto P_0c042e94;
P_0c042e94: /* original 4124, guest PC 0x0c042e94 */
if(!s->budget--) { s->failed_pc=0x0c042e94u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042e96;
P_0c042e96: /* original 3344, guest PC 0x0c042e96 */
if(!s->budget--) { s->failed_pc=0x0c042e96u; return 0; }
divide_step(s,3,4);
goto P_0c042e98;
P_0c042e98: /* original 4124, guest PC 0x0c042e98 */
if(!s->budget--) { s->failed_pc=0x0c042e98u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042e9a;
P_0c042e9a: /* original 3344, guest PC 0x0c042e9a */
if(!s->budget--) { s->failed_pc=0x0c042e9au; return 0; }
divide_step(s,3,4);
goto P_0c042e9c;
P_0c042e9c: /* original 4124, guest PC 0x0c042e9c */
if(!s->budget--) { s->failed_pc=0x0c042e9cu; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042e9e;
P_0c042e9e: /* original 3344, guest PC 0x0c042e9e */
if(!s->budget--) { s->failed_pc=0x0c042e9eu; return 0; }
divide_step(s,3,4);
goto P_0c042ea0;
P_0c042ea0: /* original 4124, guest PC 0x0c042ea0 */
if(!s->budget--) { s->failed_pc=0x0c042ea0u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042ea2;
P_0c042ea2: /* original 3344, guest PC 0x0c042ea2 */
if(!s->budget--) { s->failed_pc=0x0c042ea2u; return 0; }
divide_step(s,3,4);
goto P_0c042ea4;
P_0c042ea4: /* original 4124, guest PC 0x0c042ea4 */
if(!s->budget--) { s->failed_pc=0x0c042ea4u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042ea6;
P_0c042ea6: /* original 3344, guest PC 0x0c042ea6 */
if(!s->budget--) { s->failed_pc=0x0c042ea6u; return 0; }
divide_step(s,3,4);
goto P_0c042ea8;
P_0c042ea8: /* original 4124, guest PC 0x0c042ea8 */
if(!s->budget--) { s->failed_pc=0x0c042ea8u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042eaa;
P_0c042eaa: /* original 3344, guest PC 0x0c042eaa */
if(!s->budget--) { s->failed_pc=0x0c042eaau; return 0; }
divide_step(s,3,4);
goto P_0c042eac;
P_0c042eac: /* original 4124, guest PC 0x0c042eac */
if(!s->budget--) { s->failed_pc=0x0c042eacu; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042eae;
P_0c042eae: /* original 3344, guest PC 0x0c042eae */
if(!s->budget--) { s->failed_pc=0x0c042eaeu; return 0; }
divide_step(s,3,4);
goto P_0c042eb0;
P_0c042eb0: /* original 4124, guest PC 0x0c042eb0 */
if(!s->budget--) { s->failed_pc=0x0c042eb0u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042eb2;
P_0c042eb2: /* original 3344, guest PC 0x0c042eb2 */
if(!s->budget--) { s->failed_pc=0x0c042eb2u; return 0; }
divide_step(s,3,4);
goto P_0c042eb4;
P_0c042eb4: /* original 4124, guest PC 0x0c042eb4 */
if(!s->budget--) { s->failed_pc=0x0c042eb4u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042eb6;
P_0c042eb6: /* original 3344, guest PC 0x0c042eb6 */
if(!s->budget--) { s->failed_pc=0x0c042eb6u; return 0; }
divide_step(s,3,4);
goto P_0c042eb8;
P_0c042eb8: /* original 4124, guest PC 0x0c042eb8 */
if(!s->budget--) { s->failed_pc=0x0c042eb8u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042eba;
P_0c042eba: /* original 3344, guest PC 0x0c042eba */
if(!s->budget--) { s->failed_pc=0x0c042ebau; return 0; }
divide_step(s,3,4);
goto P_0c042ebc;
P_0c042ebc: /* original 4124, guest PC 0x0c042ebc */
if(!s->budget--) { s->failed_pc=0x0c042ebcu; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042ebe;
P_0c042ebe: /* original 3344, guest PC 0x0c042ebe */
if(!s->budget--) { s->failed_pc=0x0c042ebeu; return 0; }
divide_step(s,3,4);
goto P_0c042ec0;
P_0c042ec0: /* original 4124, guest PC 0x0c042ec0 */
if(!s->budget--) { s->failed_pc=0x0c042ec0u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042ec2;
P_0c042ec2: /* original 3344, guest PC 0x0c042ec2 */
if(!s->budget--) { s->failed_pc=0x0c042ec2u; return 0; }
divide_step(s,3,4);
goto P_0c042ec4;
P_0c042ec4: /* original 4124, guest PC 0x0c042ec4 */
if(!s->budget--) { s->failed_pc=0x0c042ec4u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042ec6;
P_0c042ec6: /* original 3344, guest PC 0x0c042ec6 */
if(!s->budget--) { s->failed_pc=0x0c042ec6u; return 0; }
divide_step(s,3,4);
goto P_0c042ec8;
P_0c042ec8: /* original 4124, guest PC 0x0c042ec8 */
if(!s->budget--) { s->failed_pc=0x0c042ec8u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042eca;
P_0c042eca: /* original 3344, guest PC 0x0c042eca */
if(!s->budget--) { s->failed_pc=0x0c042ecau; return 0; }
divide_step(s,3,4);
goto P_0c042ecc;
P_0c042ecc: /* original 4124, guest PC 0x0c042ecc */
if(!s->budget--) { s->failed_pc=0x0c042eccu; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042ece;
P_0c042ece: /* original 3344, guest PC 0x0c042ece */
if(!s->budget--) { s->failed_pc=0x0c042eceu; return 0; }
divide_step(s,3,4);
goto P_0c042ed0;
P_0c042ed0: /* original 4124, guest PC 0x0c042ed0 */
if(!s->budget--) { s->failed_pc=0x0c042ed0u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042ed2;
P_0c042ed2: /* original 3344, guest PC 0x0c042ed2 */
if(!s->budget--) { s->failed_pc=0x0c042ed2u; return 0; }
divide_step(s,3,4);
goto P_0c042ed4;
P_0c042ed4: /* original 8b03, guest PC 0x0c042ed4 */
if(!s->budget--) { s->failed_pc=0x0c042ed4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c042ede; }
goto P_0c042ed6;
P_0c042ed6: /* original 6033, guest PC 0x0c042ed6 */
if(!s->budget--) { s->failed_pc=0x0c042ed6u; return 0; }
r[0]=r[3];
goto P_0c042ed8;
P_0c042ed8: /* original 64f6, guest PC 0x0c042ed8 */
if(!s->budget--) { s->failed_pc=0x0c042ed8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[4]=tmp;
goto P_0c042eda;
P_0c042eda: /* original 000b, guest PC 0x0c042eda */
if(!s->budget--) { s->failed_pc=0x0c042edau; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[3]=tmp;
s->pc=target; return ram->oob==0;
P_0c042edc: /* original 63f6, guest PC 0x0c042edc */
if(!s->budget--) { s->failed_pc=0x0c042edcu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[3]=tmp;
goto P_0c042ede;
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
r[15]-=4; write(ram,r[15],r[2],4);
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
return vf3_matrix_family(0x0c042ef4u,s,ram);
P_0c0482f0: /* original 63f3, guest PC 0x0c0482f0 */
if(!s->budget--) { s->failed_pc=0x0c0482f0u; return 0; }
r[3]=r[15];
goto P_0c0482f2;
P_0c0482f2: /* original fb39, guest PC 0x0c0482f2 */
if(!s->budget--) { s->failed_pc=0x0c0482f2u; return 0; }
vf3_matrix_load(s,ram,11,r[3]);
r[3]+=(r[18]&0x100000u)?8:4;
goto P_0c0482f4;
P_0c0482f4: /* original f79d, guest PC 0x0c0482f4 */
if(!s->budget--) { s->failed_pc=0x0c0482f4u; return 0; }
fr[7]=0x3f800000u;
goto P_0c0482f6;
P_0c0482f6: /* original f7b5, guest PC 0x0c0482f6 */
if(!s->budget--) { s->failed_pc=0x0c0482f6u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[7])>as_float(fr[11]))!=0);
goto P_0c0482f8;
P_0c0482f8: /* original 6043, guest PC 0x0c0482f8 */
if(!s->budget--) { s->failed_pc=0x0c0482f8u; return 0; }
r[0]=r[4];
goto P_0c0482fa;
P_0c0482fa: /* original 7030, guest PC 0x0c0482fa */
if(!s->budget--) { s->failed_pc=0x0c0482fau; return 0; }
r[0]+=0x00000030u;
goto P_0c0482fc;
P_0c0482fc: /* original 8f15, guest PC 0x0c0482fc */
if(!s->budget--) { s->failed_pc=0x0c0482fcu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04832a; }
goto P_0c048300;
P_0c0482fe: /* original 0083, guest PC 0x0c0482fe */
if(!s->budget--) { s->failed_pc=0x0c0482feu; return 0; }
goto P_0c048300;
P_0c048300: /* original e202, guest PC 0x0c048300 */
if(!s->budget--) { s->failed_pc=0x0c048300u; return 0; }
r[2]=0x00000002u;
goto P_0c048302;
P_0c048302: /* original f21d, guest PC 0x0c048302 */
if(!s->budget--) { s->failed_pc=0x0c048302u; return 0; }
r[53]=fr[2];
goto P_0c048304;
P_0c048304: /* original 4228, guest PC 0x0c048304 */
if(!s->budget--) { s->failed_pc=0x0c048304u; return 0; }
r[2]<<=16;
goto P_0c048306;
P_0c048306: /* original 005a, guest PC 0x0c048306 */
if(!s->budget--) { s->failed_pc=0x0c048306u; return 0; }
r[0]=r[53];
goto P_0c048308;
P_0c048308: /* original 4218, guest PC 0x0c048308 */
if(!s->budget--) { s->failed_pc=0x0c048308u; return 0; }
r[2]<<=8;
goto P_0c04830a;
P_0c04830a: /* original d9b7, guest PC 0x0c04830a */
if(!s->budget--) { s->failed_pc=0x0c04830au; return 0; }
r[9]=read(ram,0x0c0485e8u,4);
goto P_0c04830c;
P_0c04830c: /* original 282b, guest PC 0x0c04830c */
if(!s->budget--) { s->failed_pc=0x0c04830cu; return 0; }
r[8]|=r[2];
goto P_0c04830e;
P_0c04830e: /* original cbc0, guest PC 0x0c04830e */
if(!s->budget--) { s->failed_pc=0x0c04830eu; return 0; }
r[0]|=192u;
goto P_0c048310;
P_0c048310: /* original 6009, guest PC 0x0c048310 */
if(!s->budget--) { s->failed_pc=0x0c048310u; return 0; }
r[0]=(r[0]<<16)|(r[0]>>16);
goto P_0c048312;
P_0c048312: /* original 6992, guest PC 0x0c048312 */
if(!s->budget--) { s->failed_pc=0x0c048312u; return 0; }
tmp=read(ram,r[9],4);
r[9]=tmp;
goto P_0c048314;
P_0c048314: /* original cb10, guest PC 0x0c048314 */
if(!s->budget--) { s->failed_pc=0x0c048314u; return 0; }
r[0]|=16u;
goto P_0c048316;
P_0c048316: /* original 6008, guest PC 0x0c048316 */
if(!s->budget--) { s->failed_pc=0x0c048316u; return 0; }
r[0]=(r[0]&0xffff0000u)|((r[0]&255u)<<8)|((r[0]>>8)&255u);
goto P_0c048318;
P_0c048318: /* original cbfc, guest PC 0x0c048318 */
if(!s->budget--) { s->failed_pc=0x0c048318u; return 0; }
r[0]|=252u;
goto P_0c04831a;
P_0c04831a: /* original 209a, guest PC 0x0c04831a */
if(!s->budget--) { s->failed_pc=0x0c04831au; return 0; }
r[0]^=r[9];
goto P_0c04831c;
P_0c04831c: /* original 6008, guest PC 0x0c04831c */
if(!s->budget--) { s->failed_pc=0x0c04831cu; return 0; }
r[0]=(r[0]&0xffff0000u)|((r[0]&255u)<<8)|((r[0]>>8)&255u);
goto P_0c04831e;
P_0c04831e: /* original 6009, guest PC 0x0c04831e */
if(!s->budget--) { s->failed_pc=0x0c04831eu; return 0; }
r[0]=(r[0]<<16)|(r[0]>>16);
goto P_0c048320;
P_0c048320: /* original 322c, guest PC 0x0c048320 */
if(!s->budget--) { s->failed_pc=0x0c048320u; return 0; }
r[2]+=r[2];
goto P_0c048322;
P_0c048322: /* original 405a, guest PC 0x0c048322 */
if(!s->budget--) { s->failed_pc=0x0c048322u; return 0; }
r[53]=r[0];
goto P_0c048324;
P_0c048324: /* original 6227, guest PC 0x0c048324 */
if(!s->budget--) { s->failed_pc=0x0c048324u; return 0; }
r[2]=~r[2];
goto P_0c048326;
P_0c048326: /* original f20d, guest PC 0x0c048326 */
if(!s->budget--) { s->failed_pc=0x0c048326u; return 0; }
fr[2]=r[53];
goto P_0c048328;
P_0c048328: /* original 2829, guest PC 0x0c048328 */
if(!s->budget--) { s->failed_pc=0x0c048328u; return 0; }
r[8]&=r[2];
goto P_0c04832a;
P_0c04832a: /* original 6083, guest PC 0x0c04832a */
if(!s->budget--) { s->failed_pc=0x0c04832au; return 0; }
r[0]=r[8];
goto P_0c04832c;
P_0c04832c: /* original f449, guest PC 0x0c04832c */
if(!s->budget--) { s->failed_pc=0x0c04832cu; return 0; }
vf3_matrix_load(s,ram,4,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c04832e;
P_0c04832e: /* original 4029, guest PC 0x0c04832e */
if(!s->budget--) { s->failed_pc=0x0c04832eu; return 0; }
r[0]>>=16;
goto P_0c048330;
P_0c048330: /* original f549, guest PC 0x0c048330 */
if(!s->budget--) { s->failed_pc=0x0c048330u; return 0; }
vf3_matrix_load(s,ram,5,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c048332;
P_0c048332: /* original 4019, guest PC 0x0c048332 */
if(!s->budget--) { s->failed_pc=0x0c048332u; return 0; }
r[0]>>=8;
goto P_0c048334;
P_0c048334: /* original f649, guest PC 0x0c048334 */
if(!s->budget--) { s->failed_pc=0x0c048334u; return 0; }
vf3_matrix_load(s,ram,6,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c048336;
P_0c048336: /* original c907, guest PC 0x0c048336 */
if(!s->budget--) { s->failed_pc=0x0c048336u; return 0; }
r[0]&=7u;
goto P_0c048338;
P_0c048338: /* original e204, guest PC 0x0c048338 */
if(!s->budget--) { s->failed_pc=0x0c048338u; return 0; }
r[2]=0x00000004u;
goto P_0c04833a;
P_0c04833a: /* original 4008, guest PC 0x0c04833a */
if(!s->budget--) { s->failed_pc=0x0c04833au; return 0; }
r[0]<<=2;
goto P_0c04833c;
P_0c04833c: /* original f5fd, guest PC 0x0c04833c */
if(!s->budget--) { s->failed_pc=0x0c04833cu; return 0; }
if(!vf3_fpu_ftrv(xf,fr+4,r[18],fr+4)) goto unsupported;
goto P_0c04833e;
P_0c04833e: /* original f139, guest PC 0x0c04833e */
if(!s->budget--) { s->failed_pc=0x0c04833eu; return 0; }
vf3_matrix_load(s,ram,1,r[3]);
r[3]+=(r[18]&0x100000u)?8:4;
goto P_0c048340;
P_0c048340: /* original 4218, guest PC 0x0c048340 */
if(!s->budget--) { s->failed_pc=0x0c048340u; return 0; }
r[2]<<=8;
goto P_0c048342;
P_0c048342: /* original f049, guest PC 0x0c048342 */
if(!s->budget--) { s->failed_pc=0x0c048342u; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c048344;
P_0c048344: /* original 3b00, guest PC 0x0c048344 */
if(!s->budget--) { s->failed_pc=0x0c048344u; return 0; }
r[17]=(r[17]&~1u)|((r[11]==r[0])!=0);
goto P_0c048346;
P_0c048346: /* original 6b03, guest PC 0x0c048346 */
if(!s->budget--) { s->failed_pc=0x0c048346u; return 0; }
r[11]=r[0];
goto P_0c048348;
P_0c048348: /* original e6e0, guest PC 0x0c048348 */
if(!s->budget--) { s->failed_pc=0x0c048348u; return 0; }
r[6]=0xffffffe0u;
goto P_0c04834a;
P_0c04834a: /* original f012, guest PC 0x0c04834a */
if(!s->budget--) { s->failed_pc=0x0c04834au; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[1],r[18],'*');
goto P_0c04834c;
P_0c04834c: /* original 4228, guest PC 0x0c04834c */
if(!s->budget--) { s->failed_pc=0x0c04834cu; return 0; }
r[2]<<=16;
goto P_0c04834e;
P_0c04834e: /* original 8d09, guest PC 0x0c04834e */
if(!s->budget--) { s->failed_pc=0x0c04834eu; return 0; }
cond=r[17]&1u;
r[5]=read(ram,r[10]+r[0],4);
if(cond) { goto P_0c048364; }
goto P_0c048352;
P_0c048350: /* original 05ae, guest PC 0x0c048350 */
if(!s->budget--) { s->failed_pc=0x0c048350u; return 0; }
r[5]=read(ram,r[10]+r[0],4);
goto P_0c048352;
P_0c048352: /* original e0ff, guest PC 0x0c048352 */
if(!s->budget--) { s->failed_pc=0x0c048352u; return 0; }
r[0]=0xffffffffu;
goto P_0c048354;
P_0c048354: /* original 4028, guest PC 0x0c048354 */
if(!s->budget--) { s->failed_pc=0x0c048354u; return 0; }
r[0]<<=16;
goto P_0c048356;
P_0c048356: /* original 4018, guest PC 0x0c048356 */
if(!s->budget--) { s->failed_pc=0x0c048356u; return 0; }
r[0]<<=8;
goto P_0c048358;
P_0c048358: /* original cb38, guest PC 0x0c048358 */
if(!s->budget--) { s->failed_pc=0x0c048358u; return 0; }
r[0]|=56u;
goto P_0c04835a;
P_0c04835a: /* original 6953, guest PC 0x0c04835a */
if(!s->budget--) { s->failed_pc=0x0c04835au; return 0; }
r[9]=r[5];
goto P_0c04835c;
P_0c04835c: /* original 4929, guest PC 0x0c04835c */
if(!s->budget--) { s->failed_pc=0x0c04835cu; return 0; }
r[9]>>=16;
goto P_0c04835e;
P_0c04835e: /* original 4919, guest PC 0x0c04835e */
if(!s->budget--) { s->failed_pc=0x0c04835eu; return 0; }
r[9]>>=8;
goto P_0c048360;
P_0c048360: /* original 2092, guest PC 0x0c048360 */
if(!s->budget--) { s->failed_pc=0x0c048360u; return 0; }
write(ram,r[0],r[9],4);
goto P_0c048362;
P_0c048362: /* original 1091, guest PC 0x0c048362 */
if(!s->budget--) { s->failed_pc=0x0c048362u; return 0; }
write(ram,r[0]+4,r[9],4);
goto P_0c048364;
P_0c048364: /* original 72ff, guest PC 0x0c048364 */
if(!s->budget--) { s->failed_pc=0x0c048364u; return 0; }
r[2]+=0xffffffffu;
goto P_0c048366;
P_0c048366: /* original 4c5a, guest PC 0x0c048366 */
if(!s->budget--) { s->failed_pc=0x0c048366u; return 0; }
r[53]=r[12];
goto P_0c048368;
P_0c048368: /* original e0fe, guest PC 0x0c048368 */
if(!s->budget--) { s->failed_pc=0x0c048368u; return 0; }
r[0]=0xfffffffeu;
goto P_0c04836a;
P_0c04836a: /* original f700, guest PC 0x0c04836a */
if(!s->budget--) { s->failed_pc=0x0c04836au; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[0],r[18],'+');
goto P_0c04836c;
P_0c04836c: /* original 2259, guest PC 0x0c04836c */
if(!s->budget--) { s->failed_pc=0x0c04836cu; return 0; }
r[2]&=r[5];
goto P_0c04836e;
P_0c04836e: /* original f10d, guest PC 0x0c04836e */
if(!s->budget--) { s->failed_pc=0x0c04836eu; return 0; }
fr[1]=r[53];
goto P_0c048370;
P_0c048370: /* original 4618, guest PC 0x0c048370 */
if(!s->budget--) { s->failed_pc=0x0c048370u; return 0; }
r[6]<<=8;
goto P_0c048372;
P_0c048372: /* original f715, guest PC 0x0c048372 */
if(!s->budget--) { s->failed_pc=0x0c048372u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[7])>as_float(fr[1]))!=0);
goto P_0c048374;
P_0c048374: /* original 4628, guest PC 0x0c048374 */
if(!s->budget--) { s->failed_pc=0x0c048374u; return 0; }
r[6]<<=16;
goto P_0c048376;
P_0c048376: /* original 262b, guest PC 0x0c048376 */
if(!s->budget--) { s->failed_pc=0x0c048376u; return 0; }
r[6]|=r[2];
goto P_0c048378;
P_0c048378: /* original f701, guest PC 0x0c048378 */
if(!s->budget--) { s->failed_pc=0x0c048378u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[0],r[18],'-');
goto P_0c04837a;
P_0c04837a: /* original 2c09, guest PC 0x0c04837a */
if(!s->budget--) { s->failed_pc=0x0c04837au; return 0; }
r[12]&=r[0];
goto P_0c04837c;
P_0c04837c: /* original 59f9, guest PC 0x0c04837c */
if(!s->budget--) { s->failed_pc=0x0c04837cu; return 0; }
r[9]=read(ram,r[15]+36,4);
goto P_0c04837e;
P_0c04837e: /* original 8f43, guest PC 0x0c04837e */
if(!s->budget--) { s->failed_pc=0x0c04837eu; return 0; }
cond=r[17]&1u;
fr[7]=vf3_fpu_binary(fr[7],fr[0],r[18],'-');
if(!cond) { goto P_0c048408; }
goto P_0c048382;
P_0c048380: /* original f701, guest PC 0x0c048380 */
if(!s->budget--) { s->failed_pc=0x0c048380u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[0],r[18],'-');
goto P_0c048382;
P_0c048382: /* original f715, guest PC 0x0c048382 */
if(!s->budget--) { s->failed_pc=0x0c048382u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[7])>as_float(fr[1]))!=0);
goto P_0c048384;
P_0c048384: /* original 8f40, guest PC 0x0c048384 */
if(!s->budget--) { s->failed_pc=0x0c048384u; return 0; }
cond=r[17]&1u;
r[12]+=0x00000001u;
if(!cond) { goto P_0c048408; }
goto P_0c048388;
P_0c048386: /* original 7c01, guest PC 0x0c048386 */
if(!s->budget--) { s->failed_pc=0x0c048386u; return 0; }
r[12]+=0x00000001u;
goto P_0c048388;
P_0c048388: /* original 6243, guest PC 0x0c048388 */
if(!s->budget--) { s->failed_pc=0x0c048388u; return 0; }
r[2]=r[4];
goto P_0c04838a;
P_0c04838a: /* original 742c, guest PC 0x0c04838a */
if(!s->budget--) { s->failed_pc=0x0c04838au; return 0; }
r[4]+=0x0000002cu;
goto P_0c04838c;
P_0c04838c: /* original 6046, guest PC 0x0c04838c */
if(!s->budget--) { s->failed_pc=0x0c04838cu; return 0; }
tmp=read(ram,r[4],4);
r[4]+=4;
r[0]=tmp;
goto P_0c04838e;
P_0c04838e: /* original 2682, guest PC 0x0c04838e */
if(!s->budget--) { s->failed_pc=0x0c04838eu; return 0; }
write(ram,r[6],r[8],4);
goto P_0c048390;
P_0c048390: /* original 6183, guest PC 0x0c048390 */
if(!s->budget--) { s->failed_pc=0x0c048390u; return 0; }
r[1]=r[8];
goto P_0c048392;
P_0c048392: /* original 340c, guest PC 0x0c048392 */
if(!s->budget--) { s->failed_pc=0x0c048392u; return 0; }
r[4]+=r[0];
goto P_0c048394;
P_0c048394: /* original 6846, guest PC 0x0c048394 */
if(!s->budget--) { s->failed_pc=0x0c048394u; return 0; }
tmp=read(ram,r[4],4);
r[4]+=4;
r[8]=tmp;
goto P_0c048396;
P_0c048396: /* original 2888, guest PC 0x0c048396 */
if(!s->budget--) { s->failed_pc=0x0c048396u; return 0; }
r[17]=(r[17]&~1u)|(((r[8]&r[8])==0)!=0);
goto P_0c048398;
P_0c048398: /* original 8b02, guest PC 0x0c048398 */
if(!s->budget--) { s->failed_pc=0x0c048398u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0483a0; }
goto P_0c04839a;
P_0c04839a: /* original a0ef, guest PC 0x0c04839a */
if(!s->budget--) { s->failed_pc=0x0c04839au; return 0; }
goto P_0c04857c;
P_0c04839c: /* original 0009, guest PC 0x0c04839c */
if(!s->budget--) { s->failed_pc=0x0c04839cu; return 0; }
return vf3_matrix_family(0x0c04839eu,s,ram);
P_0c0483a0: /* original 69f3, guest PC 0x0c0483a0 */
if(!s->budget--) { s->failed_pc=0x0c0483a0u; return 0; }
r[9]=r[15];
goto P_0c0483a2;
P_0c0483a2: /* original 7918, guest PC 0x0c0483a2 */
if(!s->budget--) { s->failed_pc=0x0c0483a2u; return 0; }
r[9]+=0x00000018u;
goto P_0c0483a4;
P_0c0483a4: /* original f599, guest PC 0x0c0483a4 */
if(!s->budget--) { s->failed_pc=0x0c0483a4u; return 0; }
vf3_matrix_load(s,ram,5,r[9]);
r[9]+=(r[18]&0x100000u)?8:4;
goto P_0c0483a6;
P_0c0483a6: /* original f699, guest PC 0x0c0483a6 */
if(!s->budget--) { s->failed_pc=0x0c0483a6u; return 0; }
vf3_matrix_load(s,ram,6,r[9]);
r[9]+=(r[18]&0x100000u)?8:4;
goto P_0c0483a8;
P_0c0483a8: /* original 7208, guest PC 0x0c0483a8 */
if(!s->budget--) { s->failed_pc=0x0c0483a8u; return 0; }
r[2]+=0x00000008u;
goto P_0c0483aa;
P_0c0483aa: /* original f799, guest PC 0x0c0483aa */
if(!s->budget--) { s->failed_pc=0x0c0483aau; return 0; }
vf3_matrix_load(s,ram,7,r[9]);
r[9]+=(r[18]&0x100000u)?8:4;
goto P_0c0483ac;
P_0c0483ac: /* original 6026, guest PC 0x0c0483ac */
if(!s->budget--) { s->failed_pc=0x0c0483acu; return 0; }
tmp=read(ram,r[2],4);
r[2]+=4;
r[0]=tmp;
goto P_0c0483ae;
P_0c0483ae: /* original c801, guest PC 0x0c0483ae */
if(!s->budget--) { s->failed_pc=0x0c0483aeu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&1u)==0)!=0);
goto P_0c0483b0;
P_0c0483b0: /* original 6013, guest PC 0x0c0483b0 */
if(!s->budget--) { s->failed_pc=0x0c0483b0u; return 0; }
r[0]=r[1];
goto P_0c0483b2;
P_0c0483b2: /* original 8f24, guest PC 0x0c0483b2 */
if(!s->budget--) { s->failed_pc=0x0c0483b2u; return 0; }
cond=r[17]&1u;
r[17]=(r[17]&~1u)|(((r[0]&32u)==0)!=0);
if(!cond) { goto P_0c0483fe; }
goto P_0c0483b6;
P_0c0483b4: /* original c820, guest PC 0x0c0483b4 */
if(!s->budget--) { s->failed_pc=0x0c0483b4u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&32u)==0)!=0);
goto P_0c0483b6;
P_0c0483b6: /* original 8922, guest PC 0x0c0483b6 */
if(!s->budget--) { s->failed_pc=0x0c0483b6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0483fe; }
goto P_0c0483b8;
P_0c0483b8: /* original f029, guest PC 0x0c0483b8 */
if(!s->budget--) { s->failed_pc=0x0c0483b8u; return 0; }
vf3_matrix_load(s,ram,0,r[2]);
r[2]+=(r[18]&0x100000u)?8:4;
goto P_0c0483ba;
P_0c0483ba: /* original f129, guest PC 0x0c0483ba */
if(!s->budget--) { s->failed_pc=0x0c0483bau; return 0; }
vf3_matrix_load(s,ram,1,r[2]);
r[2]+=(r[18]&0x100000u)?8:4;
goto P_0c0483bc;
P_0c0483bc: /* original f229, guest PC 0x0c0483bc */
if(!s->budget--) { s->failed_pc=0x0c0483bcu; return 0; }
vf3_matrix_load(s,ram,2,r[2]);
r[2]+=(r[18]&0x100000u)?8:4;
goto P_0c0483be;
P_0c0483be: /* original f329, guest PC 0x0c0483be */
if(!s->budget--) { s->failed_pc=0x0c0483beu; return 0; }
vf3_matrix_load(s,ram,3,r[2]);
r[2]+=(r[18]&0x100000u)?8:4;
goto P_0c0483c0;
P_0c0483c0: /* original f0b2, guest PC 0x0c0483c0 */
if(!s->budget--) { s->failed_pc=0x0c0483c0u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[11],r[18],'*');
goto P_0c0483c2;
P_0c0483c2: /* original fb5c, guest PC 0x0c0483c2 */
if(!s->budget--) { s->failed_pc=0x0c0483c2u; return 0; }
vf3_matrix_move(s,11,5);
goto P_0c0483c4;
P_0c0483c4: /* original f152, guest PC 0x0c0483c4 */
if(!s->budget--) { s->failed_pc=0x0c0483c4u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[5],r[18],'*');
goto P_0c0483c6;
P_0c0483c6: /* original f429, guest PC 0x0c0483c6 */
if(!s->budget--) { s->failed_pc=0x0c0483c6u; return 0; }
vf3_matrix_load(s,ram,4,r[2]);
r[2]+=(r[18]&0x100000u)?8:4;
goto P_0c0483c8;
P_0c0483c8: /* original f529, guest PC 0x0c0483c8 */
if(!s->budget--) { s->failed_pc=0x0c0483c8u; return 0; }
vf3_matrix_load(s,ram,5,r[2]);
r[2]+=(r[18]&0x100000u)?8:4;
goto P_0c0483ca;
P_0c0483ca: /* original f5b2, guest PC 0x0c0483ca */
if(!s->budget--) { s->failed_pc=0x0c0483cau; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[11],r[18],'*');
goto P_0c0483cc;
P_0c0483cc: /* original fb6c, guest PC 0x0c0483cc */
if(!s->budget--) { s->failed_pc=0x0c0483ccu; return 0; }
vf3_matrix_move(s,11,6);
goto P_0c0483ce;
P_0c0483ce: /* original f262, guest PC 0x0c0483ce */
if(!s->budget--) { s->failed_pc=0x0c0483ceu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[6],r[18],'*');
goto P_0c0483d0;
P_0c0483d0: /* original f629, guest PC 0x0c0483d0 */
if(!s->budget--) { s->failed_pc=0x0c0483d0u; return 0; }
vf3_matrix_load(s,ram,6,r[2]);
r[2]+=(r[18]&0x100000u)?8:4;
goto P_0c0483d2;
P_0c0483d2: /* original f6b2, guest PC 0x0c0483d2 */
if(!s->budget--) { s->failed_pc=0x0c0483d2u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[11],r[18],'*');
goto P_0c0483d4;
P_0c0483d4: /* original fb7c, guest PC 0x0c0483d4 */
if(!s->budget--) { s->failed_pc=0x0c0483d4u; return 0; }
vf3_matrix_move(s,11,7);
goto P_0c0483d6;
P_0c0483d6: /* original f372, guest PC 0x0c0483d6 */
if(!s->budget--) { s->failed_pc=0x0c0483d6u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[7],r[18],'*');
goto P_0c0483d8;
P_0c0483d8: /* original f729, guest PC 0x0c0483d8 */
if(!s->budget--) { s->failed_pc=0x0c0483d8u; return 0; }
vf3_matrix_load(s,ram,7,r[2]);
r[2]+=(r[18]&0x100000u)?8:4;
goto P_0c0483da;
P_0c0483da: /* original f3fd, guest PC 0x0c0483da */
if(!s->budget--) { s->failed_pc=0x0c0483dau; return 0; }
r[18]^=0x100000u;
goto P_0c0483dc;
P_0c0483dc: /* original f7b2, guest PC 0x0c0483dc */
if(!s->budget--) { s->failed_pc=0x0c0483dcu; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[11],r[18],'*');
goto P_0c0483de;
P_0c0483de: /* original e000, guest PC 0x0c0483de */
if(!s->budget--) { s->failed_pc=0x0c0483deu; return 0; }
r[0]=0x00000000u;
goto P_0c0483e0;
P_0c0483e0: /* original 1601, guest PC 0x0c0483e0 */
if(!s->budget--) { s->failed_pc=0x0c0483e0u; return 0; }
write(ram,r[6]+4,r[0],4);
goto P_0c0483e2;
P_0c0483e2: /* original 1602, guest PC 0x0c0483e2 */
if(!s->budget--) { s->failed_pc=0x0c0483e2u; return 0; }
write(ram,r[6]+8,r[0],4);
goto P_0c0483e4;
P_0c0483e4: /* original 1603, guest PC 0x0c0483e4 */
if(!s->budget--) { s->failed_pc=0x0c0483e4u; return 0; }
write(ram,r[6]+12,r[0],4);
goto P_0c0483e6;
P_0c0483e6: /* original 0683, guest PC 0x0c0483e6 */
if(!s->budget--) { s->failed_pc=0x0c0483e6u; return 0; }
goto P_0c0483e8;
P_0c0483e8: /* original 7640, guest PC 0x0c0483e8 */
if(!s->budget--) { s->failed_pc=0x0c0483e8u; return 0; }
r[6]+=0x00000040u;
goto P_0c0483ea;
P_0c0483ea: /* original f66b, guest PC 0x0c0483ea */
if(!s->budget--) { s->failed_pc=0x0c0483eau; return 0; }
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,6,r[6]);
goto P_0c0483ec;
P_0c0483ec: /* original f64b, guest PC 0x0c0483ec */
if(!s->budget--) { s->failed_pc=0x0c0483ecu; return 0; }
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,4,r[6]);
goto P_0c0483ee;
P_0c0483ee: /* original 60b3, guest PC 0x0c0483ee */
if(!s->budget--) { s->failed_pc=0x0c0483eeu; return 0; }
r[0]=r[11];
goto P_0c0483f0;
P_0c0483f0: /* original f62b, guest PC 0x0c0483f0 */
if(!s->budget--) { s->failed_pc=0x0c0483f0u; return 0; }
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[6]);
goto P_0c0483f2;
P_0c0483f2: /* original 7540, guest PC 0x0c0483f2 */
if(!s->budget--) { s->failed_pc=0x0c0483f2u; return 0; }
r[5]+=0x00000040u;
goto P_0c0483f4;
P_0c0483f4: /* original f60b, guest PC 0x0c0483f4 */
if(!s->budget--) { s->failed_pc=0x0c0483f4u; return 0; }
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[6]);
goto P_0c0483f6;
P_0c0483f6: /* original f3fd, guest PC 0x0c0483f6 */
if(!s->budget--) { s->failed_pc=0x0c0483f6u; return 0; }
r[18]^=0x100000u;
goto P_0c0483f8;
P_0c0483f8: /* original 0683, guest PC 0x0c0483f8 */
if(!s->budget--) { s->failed_pc=0x0c0483f8u; return 0; }
goto P_0c0483fa;
P_0c0483fa: /* original 7620, guest PC 0x0c0483fa */
if(!s->budget--) { s->failed_pc=0x0c0483fau; return 0; }
r[6]+=0x00000020u;
goto P_0c0483fc;
P_0c0483fc: /* original 0a56, guest PC 0x0c0483fc */
if(!s->budget--) { s->failed_pc=0x0c0483fcu; return 0; }
write(ram,r[10]+r[0],r[5],4);
goto P_0c0483fe;
P_0c0483fe: /* original 6146, guest PC 0x0c0483fe */
if(!s->budget--) { s->failed_pc=0x0c0483feu; return 0; }
tmp=read(ram,r[4],4);
r[4]+=4;
r[1]=tmp;
goto P_0c048400;
P_0c048400: /* original f249, guest PC 0x0c048400 */
if(!s->budget--) { s->failed_pc=0x0c048400u; return 0; }
vf3_matrix_load(s,ram,2,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c048402;
P_0c048402: /* original af75, guest PC 0x0c048402 */
if(!s->budget--) { s->failed_pc=0x0c048402u; return 0; }
vf3_matrix_load(s,ram,3,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c0482f0;
P_0c048404: /* original f349, guest PC 0x0c048404 */
if(!s->budget--) { s->failed_pc=0x0c048404u; return 0; }
vf3_matrix_load(s,ram,3,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
return vf3_matrix_family(0x0c048406u,s,ram);
P_0c048408: /* original f139, guest PC 0x0c048408 */
if(!s->budget--) { s->failed_pc=0x0c048408u; return 0; }
vf3_matrix_load(s,ram,1,r[3]);
r[3]+=(r[18]&0x100000u)?8:4;
goto P_0c04840a;
P_0c04840a: /* original 7910, guest PC 0x0c04840a */
if(!s->budget--) { s->failed_pc=0x0c04840au; return 0; }
r[9]+=0x00000010u;
goto P_0c04840c;
P_0c04840c: /* original f04d, guest PC 0x0c04840c */
if(!s->budget--) { s->failed_pc=0x0c04840cu; return 0; }
fr[0]^=0x80000000u;
goto P_0c04840e;
P_0c04840e: /* original f102, guest PC 0x0c04840e */
if(!s->budget--) { s->failed_pc=0x0c04840eu; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[0],r[18],'*');
goto P_0c048410;
P_0c048410: /* original f93b, guest PC 0x0c048410 */
if(!s->budget--) { s->failed_pc=0x0c048410u; return 0; }
r[9]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,3,r[9]);
goto P_0c048412;
P_0c048412: /* original 6243, guest PC 0x0c048412 */
if(!s->budget--) { s->failed_pc=0x0c048412u; return 0; }
r[2]=r[4];
goto P_0c048414;
P_0c048414: /* original f339, guest PC 0x0c048414 */
if(!s->budget--) { s->failed_pc=0x0c048414u; return 0; }
vf3_matrix_load(s,ram,3,r[3]);
r[3]+=(r[18]&0x100000u)?8:4;
goto P_0c048416;
P_0c048416: /* original f515, guest PC 0x0c048416 */
if(!s->budget--) { s->failed_pc=0x0c048416u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[5])>as_float(fr[1]))!=0);
goto P_0c048418;
P_0c048418: /* original f92b, guest PC 0x0c048418 */
if(!s->budget--) { s->failed_pc=0x0c048418u; return 0; }
r[9]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[9]);
goto P_0c04841a;
P_0c04841a: /* original f302, guest PC 0x0c04841a */
if(!s->budget--) { s->failed_pc=0x0c04841au; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[0],r[18],'*');
goto P_0c04841c;
P_0c04841c: /* original f039, guest PC 0x0c04841c */
if(!s->budget--) { s->failed_pc=0x0c04841cu; return 0; }
vf3_matrix_load(s,ram,0,r[3]);
r[3]+=(r[18]&0x100000u)?8:4;
goto P_0c04841e;
P_0c04841e: /* original 8fb3, guest PC 0x0c04841e */
if(!s->budget--) { s->failed_pc=0x0c04841eu; return 0; }
cond=r[17]&1u;
r[17]=(r[17]&~1u)|((as_float(fr[6])>as_float(fr[3]))!=0);
if(!cond) { goto P_0c048388; }
goto P_0c048422;
P_0c048420: /* original f635, guest PC 0x0c048420 */
if(!s->budget--) { s->failed_pc=0x0c048420u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[6])>as_float(fr[3]))!=0);
goto P_0c048422;
P_0c048422: /* original f739, guest PC 0x0c048422 */
if(!s->budget--) { s->failed_pc=0x0c048422u; return 0; }
vf3_matrix_load(s,ram,7,r[3]);
r[3]+=(r[18]&0x100000u)?8:4;
goto P_0c048424;
P_0c048424: /* original f042, guest PC 0x0c048424 */
if(!s->budget--) { s->failed_pc=0x0c048424u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[4],r[18],'*');
goto P_0c048426;
P_0c048426: /* original 5022, guest PC 0x0c048426 */
if(!s->budget--) { s->failed_pc=0x0c048426u; return 0; }
r[0]=read(ram,r[2]+8,4);
goto P_0c048428;
P_0c048428: /* original f011, guest PC 0x0c048428 */
if(!s->budget--) { s->failed_pc=0x0c048428u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[1],r[18],'-');
goto P_0c04842a;
P_0c04842a: /* original 8fad, guest PC 0x0c04842a */
if(!s->budget--) { s->failed_pc=0x0c04842au; return 0; }
cond=r[17]&1u;
r[17]=(r[17]&~1u)|((as_float(fr[5])>as_float(fr[0]))!=0);
if(!cond) { goto P_0c048388; }
goto P_0c04842e;
P_0c04842c: /* original f505, guest PC 0x0c04842c */
if(!s->budget--) { s->failed_pc=0x0c04842cu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[5])>as_float(fr[0]))!=0);
goto P_0c04842e;
P_0c04842e: /* original f539, guest PC 0x0c04842e */
if(!s->budget--) { s->failed_pc=0x0c04842eu; return 0; }
vf3_matrix_load(s,ram,5,r[3]);
r[3]+=(r[18]&0x100000u)?8:4;
goto P_0c048430;
P_0c048430: /* original f742, guest PC 0x0c048430 */
if(!s->budget--) { s->failed_pc=0x0c048430u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[4],r[18],'*');
goto P_0c048432;
P_0c048432: /* original 8da9, guest PC 0x0c048432 */
if(!s->budget--) { s->failed_pc=0x0c048432u; return 0; }
cond=r[17]&1u;
r[9]-=4; write(ram,r[9],r[1],4);
if(cond) { goto P_0c048388; }
goto P_0c048436;
P_0c048434: /* original 2916, guest PC 0x0c048434 */
if(!s->budget--) { s->failed_pc=0x0c048434u; return 0; }
r[9]-=4; write(ram,r[9],r[1],4);
goto P_0c048436;
P_0c048436: /* original f731, guest PC 0x0c048436 */
if(!s->budget--) { s->failed_pc=0x0c048436u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[3],r[18],'-');
goto P_0c048438;
P_0c048438: /* original 2986, guest PC 0x0c048438 */
if(!s->budget--) { s->failed_pc=0x0c048438u; return 0; }
r[9]-=4; write(ram,r[9],r[8],4);
goto P_0c04843a;
P_0c04843a: /* original e108, guest PC 0x0c04843a */
if(!s->budget--) { s->failed_pc=0x0c04843au; return 0; }
r[1]=0x00000008u;
goto P_0c04843c;
P_0c04843c: /* original f675, guest PC 0x0c04843c */
if(!s->budget--) { s->failed_pc=0x0c04843cu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[6])>as_float(fr[7]))!=0);
goto P_0c04843e;
P_0c04843e: /* original f639, guest PC 0x0c04843e */
if(!s->budget--) { s->failed_pc=0x0c04843eu; return 0; }
vf3_matrix_load(s,ram,6,r[3]);
r[3]+=(r[18]&0x100000u)?8:4;
goto P_0c048440;
P_0c048440: /* original 89a2, guest PC 0x0c048440 */
if(!s->budget--) { s->failed_pc=0x0c048440u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c048388; }
goto P_0c048442;
P_0c048442: /* original c801, guest PC 0x0c048442 */
if(!s->budget--) { s->failed_pc=0x0c048442u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&1u)==0)!=0);
goto P_0c048444;
P_0c048444: /* original 8424, guest PC 0x0c048444 */
if(!s->budget--) { s->failed_pc=0x0c048444u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[2]+4,1);
goto P_0c048446;
P_0c048446: /* original 7208, guest PC 0x0c048446 */
if(!s->budget--) { s->failed_pc=0x0c048446u; return 0; }
r[2]+=0x00000008u;
goto P_0c048448;
P_0c048448: /* original f739, guest PC 0x0c048448 */
if(!s->budget--) { s->failed_pc=0x0c048448u; return 0; }
vf3_matrix_load(s,ram,7,r[3]);
r[3]+=(r[18]&0x100000u)?8:4;
goto P_0c04844a;
P_0c04844a: /* original 6803, guest PC 0x0c04844a */
if(!s->budget--) { s->failed_pc=0x0c04844au; return 0; }
r[8]=r[0];
goto P_0c04844c;
P_0c04844c: /* original ff29, guest PC 0x0c04844c */
if(!s->budget--) { s->failed_pc=0x0c04844cu; return 0; }
vf3_matrix_load(s,ram,15,r[2]);
r[2]+=(r[18]&0x100000u)?8:4;
goto P_0c04844e;
P_0c04844e: /* original 8f1a, guest PC 0x0c04844e */
if(!s->budget--) { s->failed_pc=0x0c04844eu; return 0; }
cond=r[17]&1u;
r[4]+=0x00000030u;
if(!cond) { goto P_0c048486; }
goto P_0c048452;
P_0c048450: /* original 7430, guest PC 0x0c048450 */
if(!s->budget--) { s->failed_pc=0x0c048450u; return 0; }
r[4]+=0x00000030u;
goto P_0c048452;
P_0c048452: /* original f029, guest PC 0x0c048452 */
if(!s->budget--) { s->failed_pc=0x0c048452u; return 0; }
vf3_matrix_load(s,ram,0,r[2]);
r[2]+=(r[18]&0x100000u)?8:4;
goto P_0c048454;
P_0c048454: /* original f129, guest PC 0x0c048454 */
if(!s->budget--) { s->failed_pc=0x0c048454u; return 0; }
vf3_matrix_load(s,ram,1,r[2]);
r[2]+=(r[18]&0x100000u)?8:4;
goto P_0c048456;
P_0c048456: /* original f229, guest PC 0x0c048456 */
if(!s->budget--) { s->failed_pc=0x0c048456u; return 0; }
vf3_matrix_load(s,ram,2,r[2]);
r[2]+=(r[18]&0x100000u)?8:4;
goto P_0c048458;
P_0c048458: /* original f329, guest PC 0x0c048458 */
if(!s->budget--) { s->failed_pc=0x0c048458u; return 0; }
vf3_matrix_load(s,ram,3,r[2]);
r[2]+=(r[18]&0x100000u)?8:4;
goto P_0c04845a;
P_0c04845a: /* original f0b2, guest PC 0x0c04845a */
if(!s->budget--) { s->failed_pc=0x0c04845au; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[11],r[18],'*');
goto P_0c04845c;
P_0c04845c: /* original fb5c, guest PC 0x0c04845c */
if(!s->budget--) { s->failed_pc=0x0c04845cu; return 0; }
vf3_matrix_move(s,11,5);
goto P_0c04845e;
P_0c04845e: /* original f152, guest PC 0x0c04845e */
if(!s->budget--) { s->failed_pc=0x0c04845eu; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[5],r[18],'*');
goto P_0c048460;
P_0c048460: /* original f429, guest PC 0x0c048460 */
if(!s->budget--) { s->failed_pc=0x0c048460u; return 0; }
vf3_matrix_load(s,ram,4,r[2]);
r[2]+=(r[18]&0x100000u)?8:4;
goto P_0c048462;
P_0c048462: /* original f529, guest PC 0x0c048462 */
if(!s->budget--) { s->failed_pc=0x0c048462u; return 0; }
vf3_matrix_load(s,ram,5,r[2]);
r[2]+=(r[18]&0x100000u)?8:4;
goto P_0c048464;
P_0c048464: /* original f5b2, guest PC 0x0c048464 */
if(!s->budget--) { s->failed_pc=0x0c048464u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[11],r[18],'*');
goto P_0c048466;
P_0c048466: /* original fb6c, guest PC 0x0c048466 */
if(!s->budget--) { s->failed_pc=0x0c048466u; return 0; }
vf3_matrix_move(s,11,6);
goto P_0c048468;
P_0c048468: /* original f262, guest PC 0x0c048468 */
if(!s->budget--) { s->failed_pc=0x0c048468u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[6],r[18],'*');
goto P_0c04846a;
P_0c04846a: /* original f629, guest PC 0x0c04846a */
if(!s->budget--) { s->failed_pc=0x0c04846au; return 0; }
vf3_matrix_load(s,ram,6,r[2]);
r[2]+=(r[18]&0x100000u)?8:4;
goto P_0c04846c;
P_0c04846c: /* original f6b2, guest PC 0x0c04846c */
if(!s->budget--) { s->failed_pc=0x0c04846cu; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[11],r[18],'*');
goto P_0c04846e;
P_0c04846e: /* original fb7c, guest PC 0x0c04846e */
if(!s->budget--) { s->failed_pc=0x0c04846eu; return 0; }
vf3_matrix_move(s,11,7);
goto P_0c048470;
P_0c048470: /* original f372, guest PC 0x0c048470 */
if(!s->budget--) { s->failed_pc=0x0c048470u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[7],r[18],'*');
goto P_0c048472;
P_0c048472: /* original f729, guest PC 0x0c048472 */
if(!s->budget--) { s->failed_pc=0x0c048472u; return 0; }
vf3_matrix_load(s,ram,7,r[2]);
r[2]+=(r[18]&0x100000u)?8:4;
goto P_0c048474;
P_0c048474: /* original 7640, guest PC 0x0c048474 */
if(!s->budget--) { s->failed_pc=0x0c048474u; return 0; }
r[6]+=0x00000040u;
goto P_0c048476;
P_0c048476: /* original f7b2, guest PC 0x0c048476 */
if(!s->budget--) { s->failed_pc=0x0c048476u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[11],r[18],'*');
goto P_0c048478;
P_0c048478: /* original f3fd, guest PC 0x0c048478 */
if(!s->budget--) { s->failed_pc=0x0c048478u; return 0; }
r[18]^=0x100000u;
goto P_0c04847a;
P_0c04847a: /* original f66b, guest PC 0x0c04847a */
if(!s->budget--) { s->failed_pc=0x0c04847au; return 0; }
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,6,r[6]);
goto P_0c04847c;
P_0c04847c: /* original f64b, guest PC 0x0c04847c */
if(!s->budget--) { s->failed_pc=0x0c04847cu; return 0; }
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,4,r[6]);
goto P_0c04847e;
P_0c04847e: /* original f62b, guest PC 0x0c04847e */
if(!s->budget--) { s->failed_pc=0x0c04847eu; return 0; }
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[6]);
goto P_0c048480;
P_0c048480: /* original f60b, guest PC 0x0c048480 */
if(!s->budget--) { s->failed_pc=0x0c048480u; return 0; }
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[6]);
goto P_0c048482;
P_0c048482: /* original f3fd, guest PC 0x0c048482 */
if(!s->budget--) { s->failed_pc=0x0c048482u; return 0; }
r[18]^=0x100000u;
goto P_0c048484;
P_0c048484: /* original 76e0, guest PC 0x0c048484 */
if(!s->budget--) { s->failed_pc=0x0c048484u; return 0; }
r[6]+=0xffffffe0u;
goto P_0c048486;
P_0c048486: /* original 4811, guest PC 0x0c048486 */
if(!s->budget--) { s->failed_pc=0x0c048486u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[8]>=0)!=0);
goto P_0c048488;
P_0c048488: /* original 4d5a, guest PC 0x0c048488 */
if(!s->budget--) { s->failed_pc=0x0c048488u; return 0; }
r[53]=r[13];
goto P_0c04848a;
P_0c04848a: /* original 891b, guest PC 0x0c04848a */
if(!s->budget--) { s->failed_pc=0x0c04848au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0484c4; }
goto P_0c04848c;
P_0c04848c: /* original 6083, guest PC 0x0c04848c */
if(!s->budget--) { s->failed_pc=0x0c04848cu; return 0; }
r[0]=r[8];
goto P_0c04848e;
P_0c04848e: /* original 88ff, guest PC 0x0c04848e */
if(!s->budget--) { s->failed_pc=0x0c04848eu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c048490;
P_0c048490: /* original 8d14, guest PC 0x0c048490 */
if(!s->budget--) { s->failed_pc=0x0c048490u; return 0; }
cond=r[17]&1u;
r[17]=(r[17]&~1u)|((r[0]==0xfffffffeu)!=0);
if(cond) { goto P_0c0484bc; }
goto P_0c048494;
P_0c048492: /* original 88fe, guest PC 0x0c048492 */
if(!s->budget--) { s->failed_pc=0x0c048492u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xfffffffeu)!=0);
goto P_0c048494;
P_0c048494: /* original 8b08, guest PC 0x0c048494 */
if(!s->budget--) { s->failed_pc=0x0c048494u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0484a8; }
goto P_0c048496;
P_0c048496: /* original d052, guest PC 0x0c048496 */
if(!s->budget--) { s->failed_pc=0x0c048496u; return 0; }
r[0]=read(ram,0x0c0485e0u,4);
goto P_0c048498;
P_0c048498: /* original 400b, guest PC 0x0c048498 */
if(!s->budget--) { s->failed_pc=0x0c048498u; return 0; }
target=r[0];
r[16]=0x0c04849cu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04849cu) { target=s->pc; goto dispatch; }
goto P_0c04849c;
P_0c04849a: /* original 0009, guest PC 0x0c04849a */
if(!s->budget--) { s->failed_pc=0x0c04849au; return 0; }
goto P_0c04849c;
P_0c04849c: /* original 896e, guest PC 0x0c04849c */
if(!s->budget--) { s->failed_pc=0x0c04849cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04857c; }
goto P_0c04849e;
P_0c04849e: /* original 6146, guest PC 0x0c04849e */
if(!s->budget--) { s->failed_pc=0x0c04849eu; return 0; }
tmp=read(ram,r[4],4);
r[4]+=4;
r[1]=tmp;
goto P_0c0484a0;
P_0c0484a0: /* original f249, guest PC 0x0c0484a0 */
if(!s->budget--) { s->failed_pc=0x0c0484a0u; return 0; }
vf3_matrix_load(s,ram,2,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c0484a2;
P_0c0484a2: /* original af25, guest PC 0x0c0484a2 */
if(!s->budget--) { s->failed_pc=0x0c0484a2u; return 0; }
vf3_matrix_load(s,ram,3,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c0482f0;
P_0c0484a4: /* original f349, guest PC 0x0c0484a4 */
if(!s->budget--) { s->failed_pc=0x0c0484a4u; return 0; }
vf3_matrix_load(s,ram,3,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
return vf3_matrix_family(0x0c0484a6u,s,ram);
P_0c0484a8: /* original 88fd, guest PC 0x0c0484a8 */
if(!s->budget--) { s->failed_pc=0x0c0484a8u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xfffffffdu)!=0);
goto P_0c0484aa;
P_0c0484aa: /* original 8b07, guest PC 0x0c0484aa */
if(!s->budget--) { s->failed_pc=0x0c0484aau; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0484bc; }
goto P_0c0484ac;
P_0c0484ac: /* original d04d, guest PC 0x0c0484ac */
if(!s->budget--) { s->failed_pc=0x0c0484acu; return 0; }
r[0]=read(ram,0x0c0485e4u,4);
goto P_0c0484ae;
P_0c0484ae: /* original 400b, guest PC 0x0c0484ae */
if(!s->budget--) { s->failed_pc=0x0c0484aeu; return 0; }
target=r[0];
r[16]=0x0c0484b2u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0484b2u) { target=s->pc; goto dispatch; }
goto P_0c0484b2;
P_0c0484b0: /* original 0009, guest PC 0x0c0484b0 */
if(!s->budget--) { s->failed_pc=0x0c0484b0u; return 0; }
goto P_0c0484b2;
P_0c0484b2: /* original 8963, guest PC 0x0c0484b2 */
if(!s->budget--) { s->failed_pc=0x0c0484b2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04857c; }
goto P_0c0484b4;
P_0c0484b4: /* original 6146, guest PC 0x0c0484b4 */
if(!s->budget--) { s->failed_pc=0x0c0484b4u; return 0; }
tmp=read(ram,r[4],4);
r[4]+=4;
r[1]=tmp;
goto P_0c0484b6;
P_0c0484b6: /* original f249, guest PC 0x0c0484b6 */
if(!s->budget--) { s->failed_pc=0x0c0484b6u; return 0; }
vf3_matrix_load(s,ram,2,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c0484b8;
P_0c0484b8: /* original af1a, guest PC 0x0c0484b8 */
if(!s->budget--) { s->failed_pc=0x0c0484b8u; return 0; }
vf3_matrix_load(s,ram,3,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c0482f0;
P_0c0484ba: /* original f349, guest PC 0x0c0484ba */
if(!s->budget--) { s->failed_pc=0x0c0484bau; return 0; }
vf3_matrix_load(s,ram,3,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c0484bc;
P_0c0484bc: /* original e800, guest PC 0x0c0484bc */
if(!s->budget--) { s->failed_pc=0x0c0484bcu; return 0; }
r[8]=0x00000000u;
goto P_0c0484be;
P_0c0484be: /* original a00b, guest PC 0x0c0484be */
if(!s->budget--) { s->failed_pc=0x0c0484beu; return 0; }
fr[15]=0x3f800000u;
goto P_0c0484d8;
P_0c0484c0: /* original ff9d, guest PC 0x0c0484c0 */
if(!s->budget--) { s->failed_pc=0x0c0484c0u; return 0; }
fr[15]=0x3f800000u;
return vf3_matrix_family(0x0c0484c2u,s,ram);
P_0c0484c4: /* original 3817, guest PC 0x0c0484c4 */
if(!s->budget--) { s->failed_pc=0x0c0484c4u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[8]>(int32_t)r[1])!=0);
goto P_0c0484c6;
P_0c0484c6: /* original f10d, guest PC 0x0c0484c6 */
if(!s->budget--) { s->failed_pc=0x0c0484c6u; return 0; }
fr[1]=r[53];
goto P_0c0484c8;
P_0c0484c8: /* original 4808, guest PC 0x0c0484c8 */
if(!s->budget--) { s->failed_pc=0x0c0484c8u; return 0; }
r[8]<<=2;
goto P_0c0484ca;
P_0c0484ca: /* original 8f05, guest PC 0x0c0484ca */
if(!s->budget--) { s->failed_pc=0x0c0484cau; return 0; }
cond=r[17]&1u;
fr[15]=vf3_fpu_binary(fr[15],fr[1],r[18],'*');
if(!cond) { goto P_0c0484d8; }
goto P_0c0484ce;
P_0c0484cc: /* original ff12, guest PC 0x0c0484cc */
if(!s->budget--) { s->failed_pc=0x0c0484ccu; return 0; }
fr[15]=vf3_fpu_binary(fr[15],fr[1],r[18],'*');
goto P_0c0484ce;
P_0c0484ce: /* original 6083, guest PC 0x0c0484ce */
if(!s->budget--) { s->failed_pc=0x0c0484ceu; return 0; }
r[0]=r[8];
goto P_0c0484d0;
P_0c0484d0: /* original 8840, guest PC 0x0c0484d0 */
if(!s->budget--) { s->failed_pc=0x0c0484d0u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000040u)!=0);
goto P_0c0484d2;
P_0c0484d2: /* original e824, guest PC 0x0c0484d2 */
if(!s->budget--) { s->failed_pc=0x0c0484d2u; return 0; }
r[8]=0x00000024u;
goto P_0c0484d4;
P_0c0484d4: /* original 8900, guest PC 0x0c0484d4 */
if(!s->budget--) { s->failed_pc=0x0c0484d4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0484d8; }
goto P_0c0484d6;
P_0c0484d6: /* original e828, guest PC 0x0c0484d6 */
if(!s->budget--) { s->failed_pc=0x0c0484d6u; return 0; }
r[8]=0x00000028u;
goto P_0c0484d8;
P_0c0484d8: /* original 6046, guest PC 0x0c0484d8 */
if(!s->budget--) { s->failed_pc=0x0c0484d8u; return 0; }
tmp=read(ram,r[4],4);
r[4]+=4;
r[0]=tmp;
goto P_0c0484da;
P_0c0484da: /* original 4015, guest PC 0x0c0484da */
if(!s->budget--) { s->failed_pc=0x0c0484dau; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[0]>0)!=0);
goto P_0c0484dc;
P_0c0484dc: /* original 59f9, guest PC 0x0c0484dc */
if(!s->budget--) { s->failed_pc=0x0c0484dcu; return 0; }
r[9]=read(ram,r[15]+36,4);
goto P_0c0484de;
P_0c0484de: /* original 8d09, guest PC 0x0c0484de */
if(!s->budget--) { s->failed_pc=0x0c0484deu; return 0; }
cond=r[17]&1u;
r[17]=(r[17]&~1u)|(((int32_t)r[0]>=0)!=0);
if(cond) { goto P_0c0484f4; }
goto P_0c0484e2;
P_0c0484e0: /* original 4011, guest PC 0x0c0484e0 */
if(!s->budget--) { s->failed_pc=0x0c0484e0u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[0]>=0)!=0);
goto P_0c0484e2;
P_0c0484e2: /* original 6803, guest PC 0x0c0484e2 */
if(!s->budget--) { s->failed_pc=0x0c0484e2u; return 0; }
r[8]=r[0];
goto P_0c0484e4;
P_0c0484e4: /* original 60b3, guest PC 0x0c0484e4 */
if(!s->budget--) { s->failed_pc=0x0c0484e4u; return 0; }
r[0]=r[11];
goto P_0c0484e6;
P_0c0484e6: /* original 0a56, guest PC 0x0c0484e6 */
if(!s->budget--) { s->failed_pc=0x0c0484e6u; return 0; }
write(ram,r[10]+r[0],r[5],4);
goto P_0c0484e8;
P_0c0484e8: /* original 8948, guest PC 0x0c0484e8 */
if(!s->budget--) { s->failed_pc=0x0c0484e8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04857c; }
goto P_0c0484ea;
P_0c0484ea: /* original 6146, guest PC 0x0c0484ea */
if(!s->budget--) { s->failed_pc=0x0c0484eau; return 0; }
tmp=read(ram,r[4],4);
r[4]+=4;
r[1]=tmp;
goto P_0c0484ec;
P_0c0484ec: /* original f249, guest PC 0x0c0484ec */
if(!s->budget--) { s->failed_pc=0x0c0484ecu; return 0; }
vf3_matrix_load(s,ram,2,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c0484ee;
P_0c0484ee: /* original aeff, guest PC 0x0c0484ee */
if(!s->budget--) { s->failed_pc=0x0c0484eeu; return 0; }
vf3_matrix_load(s,ram,3,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c0482f0;
P_0c0484f0: /* original f349, guest PC 0x0c0484f0 */
if(!s->budget--) { s->failed_pc=0x0c0484f0u; return 0; }
vf3_matrix_load(s,ram,3,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
return vf3_matrix_family(0x0c0484f2u,s,ram);
P_0c0484f4: /* original 6103, guest PC 0x0c0484f4 */
if(!s->budget--) { s->failed_pc=0x0c0484f4u; return 0; }
r[1]=r[0];
goto P_0c0484f6;
P_0c0484f6: /* original e2fb, guest PC 0x0c0484f6 */
if(!s->budget--) { s->failed_pc=0x0c0484f6u; return 0; }
r[2]=0xfffffffbu;
goto P_0c0484f8;
P_0c0484f8: /* original 6396, guest PC 0x0c0484f8 */
if(!s->budget--) { s->failed_pc=0x0c0484f8u; return 0; }
tmp=read(ram,r[9],4);
r[9]+=4;
r[3]=tmp;
goto P_0c0484fa;
P_0c0484fa: /* original c940, guest PC 0x0c0484fa */
if(!s->budget--) { s->failed_pc=0x0c0484fau; return 0; }
r[0]&=64u;
goto P_0c0484fc;
P_0c0484fc: /* original 402d, guest PC 0x0c0484fc */
if(!s->budget--) { s->failed_pc=0x0c0484fcu; return 0; }
r[0]=(r[2]&0x80000000u)?((r[2]&31u)?r[0]>>((-r[2])&31u):0):r[0]<<(r[2]&31u);
goto P_0c0484fe;
P_0c0484fe: /* original e2fd, guest PC 0x0c0484fe */
if(!s->budget--) { s->failed_pc=0x0c0484feu; return 0; }
r[2]=0xfffffffdu;
goto P_0c048500;
P_0c048500: /* original 2329, guest PC 0x0c048500 */
if(!s->budget--) { s->failed_pc=0x0c048500u; return 0; }
r[3]&=r[2];
goto P_0c048502;
P_0c048502: /* original 203b, guest PC 0x0c048502 */
if(!s->budget--) { s->failed_pc=0x0c048502u; return 0; }
r[0]|=r[3];
goto P_0c048504;
P_0c048504: /* original c810, guest PC 0x0c048504 */
if(!s->budget--) { s->failed_pc=0x0c048504u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&16u)==0)!=0);
goto P_0c048506;
P_0c048506: /* original 7420, guest PC 0x0c048506 */
if(!s->budget--) { s->failed_pc=0x0c048506u; return 0; }
r[4]+=0x00000020u;
goto P_0c048508;
P_0c048508: /* original 8f03, guest PC 0x0c048508 */
if(!s->budget--) { s->failed_pc=0x0c048508u; return 0; }
cond=r[17]&1u;
r[53]=r[0];
if(!cond) { goto P_0c048512; }
goto P_0c04850c;
P_0c04850a: /* original 405a, guest PC 0x0c04850a */
if(!s->budget--) { s->failed_pc=0x0c04850au; return 0; }
r[53]=r[0];
goto P_0c04850c;
P_0c04850c: /* original cb10, guest PC 0x0c04850c */
if(!s->budget--) { s->failed_pc=0x0c04850cu; return 0; }
r[0]|=16u;
goto P_0c04850e;
P_0c04850e: /* original 6293, guest PC 0x0c04850e */
if(!s->budget--) { s->failed_pc=0x0c04850eu; return 0; }
r[2]=r[9];
goto P_0c048510;
P_0c048510: /* original 2206, guest PC 0x0c048510 */
if(!s->budget--) { s->failed_pc=0x0c048510u; return 0; }
r[2]-=4; write(ram,r[2],r[0],4);
goto P_0c048512;
P_0c048512: /* original 6013, guest PC 0x0c048512 */
if(!s->budget--) { s->failed_pc=0x0c048512u; return 0; }
r[0]=r[1];
goto P_0c048514;
P_0c048514: /* original e21b, guest PC 0x0c048514 */
if(!s->budget--) { s->failed_pc=0x0c048514u; return 0; }
r[2]=0x0000001bu;
goto P_0c048516;
P_0c048516: /* original c903, guest PC 0x0c048516 */
if(!s->budget--) { s->failed_pc=0x0c048516u; return 0; }
r[0]&=3u;
goto P_0c048518;
P_0c048518: /* original 402d, guest PC 0x0c048518 */
if(!s->budget--) { s->failed_pc=0x0c048518u; return 0; }
r[0]=(r[2]&0x80000000u)?((r[2]&31u)?r[0]>>((-r[2])&31u):0):r[0]<<(r[2]&31u);
goto P_0c04851a;
P_0c04851a: /* original e303, guest PC 0x0c04851a */
if(!s->budget--) { s->failed_pc=0x0c04851au; return 0; }
r[3]=0x00000003u;
goto P_0c04851c;
P_0c04851c: /* original f3fd, guest PC 0x0c04851c */
if(!s->budget--) { s->failed_pc=0x0c04851cu; return 0; }
r[18]^=0x100000u;
goto P_0c04851e;
P_0c04851e: /* original 432d, guest PC 0x0c04851e */
if(!s->budget--) { s->failed_pc=0x0c04851eu; return 0; }
r[3]=(r[2]&0x80000000u)?((r[2]&31u)?r[3]>>((-r[2])&31u):0):r[3]<<(r[2]&31u);
goto P_0c048520;
P_0c048520: /* original 0483, guest PC 0x0c048520 */
if(!s->budget--) { s->failed_pc=0x0c048520u; return 0; }
goto P_0c048522;
P_0c048522: /* original 6337, guest PC 0x0c048522 */
if(!s->budget--) { s->failed_pc=0x0c048522u; return 0; }
r[3]=~r[3];
goto P_0c048524;
P_0c048524: /* original 6296, guest PC 0x0c048524 */
if(!s->budget--) { s->failed_pc=0x0c048524u; return 0; }
tmp=read(ram,r[9],4);
r[9]+=4;
r[2]=tmp;
goto P_0c048526;
P_0c048526: /* original 2239, guest PC 0x0c048526 */
if(!s->budget--) { s->failed_pc=0x0c048526u; return 0; }
r[2]&=r[3];
goto P_0c048528;
P_0c048528: /* original f00d, guest PC 0x0c048528 */
if(!s->budget--) { s->failed_pc=0x0c048528u; return 0; }
fr[0]=r[53];
goto P_0c04852a;
P_0c04852a: /* original 220b, guest PC 0x0c04852a */
if(!s->budget--) { s->failed_pc=0x0c04852au; return 0; }
r[2]|=r[0];
goto P_0c04852c;
P_0c04852c: /* original 425a, guest PC 0x0c04852c */
if(!s->budget--) { s->failed_pc=0x0c04852cu; return 0; }
r[53]=r[2];
goto P_0c04852e;
P_0c04852e: /* original 74e0, guest PC 0x0c04852e */
if(!s->budget--) { s->failed_pc=0x0c04852eu; return 0; }
r[4]+=0xffffffe0u;
goto P_0c048530;
P_0c048530: /* original f10d, guest PC 0x0c048530 */
if(!s->budget--) { s->failed_pc=0x0c048530u; return 0; }
fr[1]=r[53];
goto P_0c048532;
P_0c048532: /* original 7610, guest PC 0x0c048532 */
if(!s->budget--) { s->failed_pc=0x0c048532u; return 0; }
r[6]+=0x00000010u;
goto P_0c048534;
P_0c048534: /* original f299, guest PC 0x0c048534 */
if(!s->budget--) { s->failed_pc=0x0c048534u; return 0; }
vf3_matrix_load(s,ram,2,r[9]);
r[9]+=(r[18]&0x100000u)?8:4;
goto P_0c048536;
P_0c048536: /* original f62b, guest PC 0x0c048536 */
if(!s->budget--) { s->failed_pc=0x0c048536u; return 0; }
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[6]);
goto P_0c048538;
P_0c048538: /* original 7520, guest PC 0x0c048538 */
if(!s->budget--) { s->failed_pc=0x0c048538u; return 0; }
r[5]+=0x00000020u;
goto P_0c04853a;
P_0c04853a: /* original f60b, guest PC 0x0c04853a */
if(!s->budget--) { s->failed_pc=0x0c04853au; return 0; }
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[6]);
goto P_0c04853c;
P_0c04853c: /* original f3fd, guest PC 0x0c04853c */
if(!s->budget--) { s->failed_pc=0x0c04853cu; return 0; }
r[18]^=0x100000u;
goto P_0c04853e;
P_0c04853e: /* original 0683, guest PC 0x0c04853e */
if(!s->budget--) { s->failed_pc=0x0c04853eu; return 0; }
goto P_0c048540;
P_0c048540: /* original 8f03, guest PC 0x0c048540 */
if(!s->budget--) { s->failed_pc=0x0c048540u; return 0; }
cond=r[17]&1u;
r[6]+=0x00000020u;
if(!cond) { goto P_0c04854a; }
goto P_0c048544;
P_0c048542: /* original 7620, guest PC 0x0c048542 */
if(!s->budget--) { s->failed_pc=0x0c048542u; return 0; }
r[6]+=0x00000020u;
goto P_0c048544;
P_0c048544: /* original 0683, guest PC 0x0c048544 */
if(!s->budget--) { s->failed_pc=0x0c048544u; return 0; }
goto P_0c048546;
P_0c048546: /* original 7620, guest PC 0x0c048546 */
if(!s->budget--) { s->failed_pc=0x0c048546u; return 0; }
r[6]+=0x00000020u;
goto P_0c048548;
P_0c048548: /* original 7520, guest PC 0x0c048548 */
if(!s->budget--) { s->failed_pc=0x0c048548u; return 0; }
r[5]+=0x00000020u;
goto P_0c04854a;
P_0c04854a: /* original 4c25, guest PC 0x0c04854a */
if(!s->budget--) { s->failed_pc=0x0c04854au; return 0; }
tmp=r[12]&1u; r[12]=(r[12]>>1)|((r[17]&1u)<<31);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c04854c;
P_0c04854c: /* original 6013, guest PC 0x0c04854c */
if(!s->budget--) { s->failed_pc=0x0c04854cu; return 0; }
r[0]=r[1];
goto P_0c04854e;
P_0c04854e: /* original 8d25, guest PC 0x0c04854e */
if(!s->budget--) { s->failed_pc=0x0c04854eu; return 0; }
cond=r[17]&1u;
r[17]=(r[17]&~1u)|((r[12]>>31)!=0);
r[12]<<=1;
if(cond) { goto P_0c04859c; }
goto P_0c048552;
P_0c048550: /* original 4c00, guest PC 0x0c048550 */
if(!s->budget--) { s->failed_pc=0x0c048550u; return 0; }
r[17]=(r[17]&~1u)|((r[12]>>31)!=0);
r[12]<<=1;
goto P_0c048552;
P_0c048552: /* original c808, guest PC 0x0c048552 */
if(!s->budget--) { s->failed_pc=0x0c048552u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&8u)==0)!=0);
goto P_0c048554;
P_0c048554: /* original 8f0e, guest PC 0x0c048554 */
if(!s->budget--) { s->failed_pc=0x0c048554u; return 0; }
cond=r[17]&1u;
r[17]=(r[17]&~1u)|(((r[0]&4u)==0)!=0);
if(!cond) { goto P_0c048574; }
goto P_0c048558;
P_0c048556: /* original c804, guest PC 0x0c048556 */
if(!s->budget--) { s->failed_pc=0x0c048556u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&4u)==0)!=0);
goto P_0c048558;
P_0c048558: /* original 8b08, guest PC 0x0c048558 */
if(!s->budget--) { s->failed_pc=0x0c048558u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04856c; }
goto P_0c04855a;
P_0c04855a: /* original b121, guest PC 0x0c04855a */
if(!s->budget--) { s->failed_pc=0x0c04855au; return 0; }
target=0x0c0487a0u; r[16]=0x0c04855eu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04855eu) { target=s->pc; goto dispatch; }
goto P_0c04855e;
P_0c04855c: /* original 0009, guest PC 0x0c04855c */
if(!s->budget--) { s->failed_pc=0x0c04855cu; return 0; }
goto P_0c04855e;
P_0c04855e: /* original afbc, guest PC 0x0c04855e */
if(!s->budget--) { s->failed_pc=0x0c04855eu; return 0; }
tmp=read(ram,r[4],4);
r[4]+=4;
r[0]=tmp;
goto P_0c0484da;
P_0c048560: /* original 6046, guest PC 0x0c048560 */
if(!s->budget--) { s->failed_pc=0x0c048560u; return 0; }
tmp=read(ram,r[4],4);
r[4]+=4;
r[0]=tmp;
return vf3_matrix_family(0x0c048562u,s,ram);
P_0c04856c: /* original b048, guest PC 0x0c04856c */
if(!s->budget--) { s->failed_pc=0x0c04856cu; return 0; }
target=0x0c048600u; r[16]=0x0c048570u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c048570u) { target=s->pc; goto dispatch; }
goto P_0c048570;
P_0c04856e: /* original 0009, guest PC 0x0c04856e */
if(!s->budget--) { s->failed_pc=0x0c04856eu; return 0; }
goto P_0c048570;
P_0c048570: /* original afb3, guest PC 0x0c048570 */
if(!s->budget--) { s->failed_pc=0x0c048570u; return 0; }
tmp=read(ram,r[4],4);
r[4]+=4;
r[0]=tmp;
goto P_0c0484da;
P_0c048572: /* original 6046, guest PC 0x0c048572 */
if(!s->budget--) { s->failed_pc=0x0c048572u; return 0; }
tmp=read(ram,r[4],4);
r[4]+=4;
r[0]=tmp;
goto P_0c048574;
P_0c048574: /* original b4f4, guest PC 0x0c048574 */
if(!s->budget--) { s->failed_pc=0x0c048574u; return 0; }
target=0x0c048f60u; r[16]=0x0c048578u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c048578u) { target=s->pc; goto dispatch; }
goto P_0c048578;
P_0c048576: /* original 0009, guest PC 0x0c048576 */
if(!s->budget--) { s->failed_pc=0x0c048576u; return 0; }
goto P_0c048578;
P_0c048578: /* original afaf, guest PC 0x0c048578 */
if(!s->budget--) { s->failed_pc=0x0c048578u; return 0; }
tmp=read(ram,r[4],4);
r[4]+=4;
r[0]=tmp;
goto P_0c0484da;
P_0c04857a: /* original 6046, guest PC 0x0c04857a */
if(!s->budget--) { s->failed_pc=0x0c04857au; return 0; }
tmp=read(ram,r[4],4);
r[4]+=4;
r[0]=tmp;
goto P_0c04857c;
P_0c04857c: /* original 7f28, guest PC 0x0c04857c */
if(!s->budget--) { s->failed_pc=0x0c04857cu; return 0; }
r[15]+=0x00000028u;
goto P_0c04857e;
P_0c04857e: /* original 4f26, guest PC 0x0c04857e */
if(!s->budget--) { s->failed_pc=0x0c04857eu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c048580;
P_0c048580: /* original 68f6, guest PC 0x0c048580 */
if(!s->budget--) { s->failed_pc=0x0c048580u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c048582;
P_0c048582: /* original 69f6, guest PC 0x0c048582 */
if(!s->budget--) { s->failed_pc=0x0c048582u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c048584;
P_0c048584: /* original 6af6, guest PC 0x0c048584 */
if(!s->budget--) { s->failed_pc=0x0c048584u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c048586;
P_0c048586: /* original 6bf6, guest PC 0x0c048586 */
if(!s->budget--) { s->failed_pc=0x0c048586u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c048588;
P_0c048588: /* original 6cf6, guest PC 0x0c048588 */
if(!s->budget--) { s->failed_pc=0x0c048588u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c04858a;
P_0c04858a: /* original 6df6, guest PC 0x0c04858a */
if(!s->budget--) { s->failed_pc=0x0c04858au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c04858c;
P_0c04858c: /* original 6ef6, guest PC 0x0c04858c */
if(!s->budget--) { s->failed_pc=0x0c04858cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c04858e;
P_0c04858e: /* original fcf9, guest PC 0x0c04858e */
if(!s->budget--) { s->failed_pc=0x0c04858eu; return 0; }
vf3_matrix_load(s,ram,12,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c048590;
P_0c048590: /* original fdf9, guest PC 0x0c048590 */
if(!s->budget--) { s->failed_pc=0x0c048590u; return 0; }
vf3_matrix_load(s,ram,13,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c048592;
P_0c048592: /* original fef9, guest PC 0x0c048592 */
if(!s->budget--) { s->failed_pc=0x0c048592u; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c048594;
P_0c048594: /* original fff9, guest PC 0x0c048594 */
if(!s->budget--) { s->failed_pc=0x0c048594u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c048596;
P_0c048596: /* original 000b, guest PC 0x0c048596 */
if(!s->budget--) { s->failed_pc=0x0c048596u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c048598: /* original 0009, guest PC 0x0c048598 */
if(!s->budget--) { s->failed_pc=0x0c048598u; return 0; }
return vf3_matrix_family(0x0c04859au,s,ram);
P_0c04859c: /* original e100, guest PC 0x0c04859c */
if(!s->budget--) { s->failed_pc=0x0c04859cu; return 0; }
r[1]=0x00000000u;
goto P_0c04859e;
P_0c04859e: /* original c840, guest PC 0x0c04859e */
if(!s->budget--) { s->failed_pc=0x0c04859eu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&64u)==0)!=0);
goto P_0c0485a0;
P_0c0485a0: /* original 3c1e, guest PC 0x0c0485a0 */
if(!s->budget--) { s->failed_pc=0x0c0485a0u; return 0; }
wide=(uint64_t)r[12]+r[1]+(r[17]&1u); r[12]=(uint32_t)wide;
r[17]=(r[17]&~1u)|((wide>>32)!=0);
goto P_0c0485a2;
P_0c0485a2: /* original c810, guest PC 0x0c0485a2 */
if(!s->budget--) { s->failed_pc=0x0c0485a2u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&16u)==0)!=0);
goto P_0c0485a4;
P_0c0485a4: /* original 8d04, guest PC 0x0c0485a4 */
if(!s->budget--) { s->failed_pc=0x0c0485a4u; return 0; }
cond=r[17]&1u;
r[17]=(r[17]&~1u)|(((r[0]&8u)==0)!=0);
if(cond) { goto P_0c0485b0; }
goto P_0c0485a8;
P_0c0485a6: /* original c808, guest PC 0x0c0485a6 */
if(!s->budget--) { s->failed_pc=0x0c0485a6u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&8u)==0)!=0);
goto P_0c0485a8;
P_0c0485a8: /* original b19a, guest PC 0x0c0485a8 */
if(!s->budget--) { s->failed_pc=0x0c0485a8u; return 0; }
target=0x0c0488e0u; r[16]=0x0c0485acu;
r[17]=(r[17]&~1u)|(((r[0]&32u)==0)!=0);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0485acu) { target=s->pc; goto dispatch; }
goto P_0c0485ac;
P_0c0485aa: /* original c820, guest PC 0x0c0485aa */
if(!s->budget--) { s->failed_pc=0x0c0485aau; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&32u)==0)!=0);
goto P_0c0485ac;
P_0c0485ac: /* original af95, guest PC 0x0c0485ac */
if(!s->budget--) { s->failed_pc=0x0c0485acu; return 0; }
tmp=read(ram,r[4],4);
r[4]+=4;
r[0]=tmp;
goto P_0c0484da;
P_0c0485ae: /* original 6046, guest PC 0x0c0485ae */
if(!s->budget--) { s->failed_pc=0x0c0485aeu; return 0; }
tmp=read(ram,r[4],4);
r[4]+=4;
r[0]=tmp;
goto P_0c0485b0;
P_0c0485b0: /* original 8904, guest PC 0x0c0485b0 */
if(!s->budget--) { s->failed_pc=0x0c0485b0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0485bc; }
goto P_0c0485b2;
P_0c0485b2: /* original b3d5, guest PC 0x0c0485b2 */
if(!s->budget--) { s->failed_pc=0x0c0485b2u; return 0; }
target=0x0c048d60u; r[16]=0x0c0485b6u;
r[17]=(r[17]&~1u)|(((r[0]&32u)==0)!=0);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0485b6u) { target=s->pc; goto dispatch; }
goto P_0c0485b6;
P_0c0485b4: /* original c820, guest PC 0x0c0485b4 */
if(!s->budget--) { s->failed_pc=0x0c0485b4u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&32u)==0)!=0);
goto P_0c0485b6;
P_0c0485b6: /* original af90, guest PC 0x0c0485b6 */
if(!s->budget--) { s->failed_pc=0x0c0485b6u; return 0; }
tmp=read(ram,r[4],4);
r[4]+=4;
r[0]=tmp;
goto P_0c0484da;
P_0c0485b8: /* original 6046, guest PC 0x0c0485b8 */
if(!s->budget--) { s->failed_pc=0x0c0485b8u; return 0; }
tmp=read(ram,r[4],4);
r[4]+=4;
r[0]=tmp;
return vf3_matrix_family(0x0c0485bau,s,ram);
P_0c0485bc: /* original affe, guest PC 0x0c0485bc */
if(!s->budget--) { s->failed_pc=0x0c0485bcu; return 0; }
goto P_0c0485bc;
P_0c0485be: /* original 0009, guest PC 0x0c0485be */
if(!s->budget--) { s->failed_pc=0x0c0485beu; return 0; }
return vf3_matrix_family(0x0c0485c0u,s,ram);
P_0c0487a0: /* original 6346, guest PC 0x0c0487a0 */
if(!s->budget--) { s->failed_pc=0x0c0487a0u; return 0; }
tmp=read(ram,r[4],4);
r[4]+=4;
r[3]=tmp;
goto P_0c0487a2;
P_0c0487a2: /* original 76e0, guest PC 0x0c0487a2 */
if(!s->budget--) { s->failed_pc=0x0c0487a2u; return 0; }
r[6]+=0xffffffe0u;
goto P_0c0487a4;
P_0c0487a4: /* original 6042, guest PC 0x0c0487a4 */
if(!s->budget--) { s->failed_pc=0x0c0487a4u; return 0; }
tmp=read(ram,r[4],4);
r[0]=tmp;
goto P_0c0487a6;
P_0c0487a6: /* original f3fd, guest PC 0x0c0487a6 */
if(!s->budget--) { s->failed_pc=0x0c0487a6u; return 0; }
r[18]^=0x100000u;
goto P_0c0487a8;
P_0c0487a8: /* original c801, guest PC 0x0c0487a8 */
if(!s->budget--) { s->failed_pc=0x0c0487a8u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&1u)==0)!=0);
goto P_0c0487aa;
P_0c0487aa: /* original 6e43, guest PC 0x0c0487aa */
if(!s->budget--) { s->failed_pc=0x0c0487aau; return 0; }
r[14]=r[4];
goto P_0c0487ac;
P_0c0487ac: /* original 8f03, guest PC 0x0c0487ac */
if(!s->budget--) { s->failed_pc=0x0c0487acu; return 0; }
cond=r[17]&1u;
r[4]+=0x00000020u;
if(!cond) { goto P_0c0487b6; }
goto P_0c0487b0;
P_0c0487ae: /* original 7420, guest PC 0x0c0487ae */
if(!s->budget--) { s->failed_pc=0x0c0487aeu; return 0; }
r[4]+=0x00000020u;
goto P_0c0487b0;
P_0c0487b0: /* original 5ee1, guest PC 0x0c0487b0 */
if(!s->budget--) { s->failed_pc=0x0c0487b0u; return 0; }
r[14]=read(ram,r[14]+4,4);
goto P_0c0487b2;
P_0c0487b2: /* original 74e8, guest PC 0x0c0487b2 */
if(!s->budget--) { s->failed_pc=0x0c0487b2u; return 0; }
r[4]+=0xffffffe8u;
goto P_0c0487b4;
P_0c0487b4: /* original 3e4c, guest PC 0x0c0487b4 */
if(!s->budget--) { s->failed_pc=0x0c0487b4u; return 0; }
r[14]+=r[4];
goto P_0c0487b6;
P_0c0487b6: /* original f4e9, guest PC 0x0c0487b6 */
if(!s->budget--) { s->failed_pc=0x0c0487b6u; return 0; }
vf3_matrix_load(s,ram,4,r[14]);
r[14]+=(r[18]&0x100000u)?8:4;
goto P_0c0487b8;
P_0c0487b8: /* original f6e9, guest PC 0x0c0487b8 */
if(!s->budget--) { s->failed_pc=0x0c0487b8u; return 0; }
vf3_matrix_load(s,ram,6,r[14]);
r[14]+=(r[18]&0x100000u)?8:4;
goto P_0c0487ba;
P_0c0487ba: /* original f28d, guest PC 0x0c0487ba */
if(!s->budget--) { s->failed_pc=0x0c0487bau; return 0; }
fr[2]=0;
goto P_0c0487bc;
P_0c0487bc: /* original f270, guest PC 0x0c0487bc */
if(!s->budget--) { s->failed_pc=0x0c0487bcu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[7],r[18],'+');
goto P_0c0487be;
P_0c0487be: /* original f79d, guest PC 0x0c0487be */
if(!s->budget--) { s->failed_pc=0x0c0487beu; return 0; }
fr[7]=0x3f800000u;
goto P_0c0487c0;
P_0c0487c0: /* original 7640, guest PC 0x0c0487c0 */
if(!s->budget--) { s->failed_pc=0x0c0487c0u; return 0; }
r[6]+=0x00000040u;
goto P_0c0487c2;
P_0c0487c2: /* original f38d, guest PC 0x0c0487c2 */
if(!s->budget--) { s->failed_pc=0x0c0487c2u; return 0; }
fr[3]=0;
goto P_0c0487c4;
P_0c0487c4: /* original 7520, guest PC 0x0c0487c4 */
if(!s->budget--) { s->failed_pc=0x0c0487c4u; return 0; }
r[5]+=0x00000020u;
goto P_0c0487c6;
P_0c0487c6: /* original f0e9, guest PC 0x0c0487c6 */
if(!s->budget--) { s->failed_pc=0x0c0487c6u; return 0; }
vf3_matrix_load(s,ram,0,r[14]);
r[14]+=(r[18]&0x100000u)?8:4;
goto P_0c0487c8;
P_0c0487c8: /* original f5fd, guest PC 0x0c0487c8 */
if(!s->budget--) { s->failed_pc=0x0c0487c8u; return 0; }
if(!vf3_fpu_ftrv(xf,fr+4,r[18],fr+4)) goto unsupported;
goto P_0c0487ca;
P_0c0487ca: /* original fb8d, guest PC 0x0c0487ca */
if(!s->budget--) { s->failed_pc=0x0c0487cau; return 0; }
fr[11]=0;
goto P_0c0487cc;
P_0c0487cc: /* original 61e6, guest PC 0x0c0487cc */
if(!s->budget--) { s->failed_pc=0x0c0487ccu; return 0; }
tmp=read(ram,r[14],4);
r[14]+=4;
r[1]=tmp;
goto P_0c0487ce;
P_0c0487ce: /* original 4310, guest PC 0x0c0487ce */
if(!s->budget--) { s->failed_pc=0x0c0487ceu; return 0; }
--r[3];
r[17]=(r[17]&~1u)|((r[3]==0)!=0);
goto P_0c0487d0;
P_0c0487d0: /* original 62e6, guest PC 0x0c0487d0 */
if(!s->budget--) { s->failed_pc=0x0c0487d0u; return 0; }
tmp=read(ram,r[14],4);
r[14]+=4;
r[2]=tmp;
goto P_0c0487d2;
P_0c0487d2: /* original 8d11, guest PC 0x0c0487d2 */
if(!s->budget--) { s->failed_pc=0x0c0487d2u; return 0; }
cond=r[17]&1u;
tmp=read(ram,r[4],4);
r[0]=tmp;
if(cond) { goto P_0c0487f8; }
goto P_0c0487d6;
P_0c0487d4: /* original 6042, guest PC 0x0c0487d4 */
if(!s->budget--) { s->failed_pc=0x0c0487d4u; return 0; }
tmp=read(ram,r[4],4);
r[0]=tmp;
goto P_0c0487d6;
P_0c0487d6: /* original f3ed, guest PC 0x0c0487d6 */
if(!s->budget--) { s->failed_pc=0x0c0487d6u; return 0; }
if(!vf3_fpu_fipr(fr+12,fr+0,r[18],fr+3)) goto unsupported;
goto P_0c0487d8;
P_0c0487d8: /* original 5e41, guest PC 0x0c0487d8 */
if(!s->budget--) { s->failed_pc=0x0c0487d8u; return 0; }
r[14]=read(ram,r[4]+4,4);
goto P_0c0487da;
P_0c0487da: /* original c801, guest PC 0x0c0487da */
if(!s->budget--) { s->failed_pc=0x0c0487dau; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&1u)==0)!=0);
goto P_0c0487dc;
P_0c0487dc: /* original f79d, guest PC 0x0c0487dc */
if(!s->budget--) { s->failed_pc=0x0c0487dcu; return 0; }
fr[7]=0x3f800000u;
goto P_0c0487de;
P_0c0487de: /* original 8f0e, guest PC 0x0c0487de */
if(!s->budget--) { s->failed_pc=0x0c0487deu; return 0; }
cond=r[17]&1u;
fr[7]=vf3_fpu_binary(fr[7],fr[4],r[18],'/');
if(!cond) { goto P_0c0487fe; }
goto P_0c0487e2;
P_0c0487e0: /* original f743, guest PC 0x0c0487e0 */
if(!s->budget--) { s->failed_pc=0x0c0487e0u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[4],r[18],'/');
goto P_0c0487e2;
P_0c0487e2: /* original 7408, guest PC 0x0c0487e2 */
if(!s->budget--) { s->failed_pc=0x0c0487e2u; return 0; }
r[4]+=0x00000008u;
goto P_0c0487e4;
P_0c0487e4: /* original 0483, guest PC 0x0c0487e4 */
if(!s->budget--) { s->failed_pc=0x0c0487e4u; return 0; }
goto P_0c0487e6;
P_0c0487e6: /* original f3b5, guest PC 0x0c0487e6 */
if(!s->budget--) { s->failed_pc=0x0c0487e6u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[11]))!=0);
goto P_0c0487e8;
P_0c0487e8: /* original 3e4c, guest PC 0x0c0487e8 */
if(!s->budget--) { s->failed_pc=0x0c0487e8u; return 0; }
r[14]+=r[4];
goto P_0c0487ea;
P_0c0487ea: /* original ff1d, guest PC 0x0c0487ea */
if(!s->budget--) { s->failed_pc=0x0c0487eau; return 0; }
r[53]=fr[15];
goto P_0c0487ec;
P_0c0487ec: /* original f8ed, guest PC 0x0c0487ec */
if(!s->budget--) { s->failed_pc=0x0c0487ecu; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+8,r[18],fr+11)) goto unsupported;
goto P_0c0487ee;
P_0c0487ee: /* original 0e83, guest PC 0x0c0487ee */
if(!s->budget--) { s->failed_pc=0x0c0487eeu; return 0; }
goto P_0c0487f0;
P_0c0487f0: /* original 8f0e, guest PC 0x0c0487f0 */
if(!s->budget--) { s->failed_pc=0x0c0487f0u; return 0; }
cond=r[17]&1u;
fr[2]=r[53];
if(!cond) { goto P_0c048810; }
goto P_0c0487f4;
P_0c0487f2: /* original f20d, guest PC 0x0c0487f2 */
if(!s->budget--) { s->failed_pc=0x0c0487f2u; return 0; }
fr[2]=r[53];
goto P_0c0487f4;
P_0c0487f4: /* original a00c, guest PC 0x0c0487f4 */
if(!s->budget--) { s->failed_pc=0x0c0487f4u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'+');
goto P_0c048810;
P_0c0487f6: /* original f230, guest PC 0x0c0487f6 */
if(!s->budget--) { s->failed_pc=0x0c0487f6u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'+');
goto P_0c0487f8;
P_0c0487f8: /* original f3ed, guest PC 0x0c0487f8 */
if(!s->budget--) { s->failed_pc=0x0c0487f8u; return 0; }
if(!vf3_fpu_fipr(fr+12,fr+0,r[18],fr+3)) goto unsupported;
goto P_0c0487fa;
P_0c0487fa: /* original f79d, guest PC 0x0c0487fa */
if(!s->budget--) { s->failed_pc=0x0c0487fau; return 0; }
fr[7]=0x3f800000u;
goto P_0c0487fc;
P_0c0487fc: /* original f743, guest PC 0x0c0487fc */
if(!s->budget--) { s->failed_pc=0x0c0487fcu; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[4],r[18],'/');
goto P_0c0487fe;
P_0c0487fe: /* original 6e43, guest PC 0x0c0487fe */
if(!s->budget--) { s->failed_pc=0x0c0487feu; return 0; }
r[14]=r[4];
goto P_0c048800;
P_0c048800: /* original 7420, guest PC 0x0c048800 */
if(!s->budget--) { s->failed_pc=0x0c048800u; return 0; }
r[4]+=0x00000020u;
goto P_0c048802;
P_0c048802: /* original f3b5, guest PC 0x0c048802 */
if(!s->budget--) { s->failed_pc=0x0c048802u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[11]))!=0);
goto P_0c048804;
P_0c048804: /* original 0483, guest PC 0x0c048804 */
if(!s->budget--) { s->failed_pc=0x0c048804u; return 0; }
goto P_0c048806;
P_0c048806: /* original f8ed, guest PC 0x0c048806 */
if(!s->budget--) { s->failed_pc=0x0c048806u; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+8,r[18],fr+11)) goto unsupported;
goto P_0c048808;
P_0c048808: /* original ff1d, guest PC 0x0c048808 */
if(!s->budget--) { s->failed_pc=0x0c048808u; return 0; }
r[53]=fr[15];
goto P_0c04880a;
P_0c04880a: /* original 8f01, guest PC 0x0c04880a */
if(!s->budget--) { s->failed_pc=0x0c04880au; return 0; }
cond=r[17]&1u;
fr[2]=r[53];
if(!cond) { goto P_0c048810; }
goto P_0c04880e;
P_0c04880c: /* original f20d, guest PC 0x0c04880c */
if(!s->budget--) { s->failed_pc=0x0c04880cu; return 0; }
fr[2]=r[53];
goto P_0c04880e;
P_0c04880e: /* original f230, guest PC 0x0c04880e */
if(!s->budget--) { s->failed_pc=0x0c04880eu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'+');
goto P_0c048810;
P_0c048810: /* original 2888, guest PC 0x0c048810 */
if(!s->budget--) { s->failed_pc=0x0c048810u; return 0; }
r[17]=(r[17]&~1u)|(((r[8]&r[8])==0)!=0);
goto P_0c048812;
P_0c048812: /* original f38d, guest PC 0x0c048812 */
if(!s->budget--) { s->failed_pc=0x0c048812u; return 0; }
fr[3]=0;
goto P_0c048814;
P_0c048814: /* original 8d0c, guest PC 0x0c048814 */
if(!s->budget--) { s->failed_pc=0x0c048814u; return 0; }
cond=r[17]&1u;
r[17]=(r[17]&~1u)|((as_float(fr[11])>as_float(fr[3]))!=0);
if(cond) { goto P_0c048830; }
goto P_0c048818;
P_0c048816: /* original fb35, guest PC 0x0c048816 */
if(!s->budget--) { s->failed_pc=0x0c048816u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[11])>as_float(fr[3]))!=0);
goto P_0c048818;
P_0c048818: /* original f09d, guest PC 0x0c048818 */
if(!s->budget--) { s->failed_pc=0x0c048818u; return 0; }
fr[0]=0x3f800000u;
goto P_0c04881a;
P_0c04881a: /* original fbb2, guest PC 0x0c04881a */
if(!s->budget--) { s->failed_pc=0x0c04881au; return 0; }
fr[11]=vf3_fpu_binary(fr[11],fr[11],r[18],'*');
goto P_0c04881c;
P_0c04881c: /* original 8b08, guest PC 0x0c04881c */
if(!s->budget--) { s->failed_pc=0x0c04881cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c048830; }
goto P_0c04881e;
P_0c04881e: /* original fbb0, guest PC 0x0c04881e */
if(!s->budget--) { s->failed_pc=0x0c04881eu; return 0; }
fr[11]=vf3_fpu_binary(fr[11],fr[11],r[18],'+');
goto P_0c048820;
P_0c048820: /* original 6083, guest PC 0x0c048820 */
if(!s->budget--) { s->failed_pc=0x0c048820u; return 0; }
r[0]=r[8];
goto P_0c048822;
P_0c048822: /* original fb05, guest PC 0x0c048822 */
if(!s->budget--) { s->failed_pc=0x0c048822u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[11])>as_float(fr[0]))!=0);
goto P_0c048824;
P_0c048824: /* original 7050, guest PC 0x0c048824 */
if(!s->budget--) { s->failed_pc=0x0c048824u; return 0; }
r[0]+=0x00000050u;
goto P_0c048826;
P_0c048826: /* original fb01, guest PC 0x0c048826 */
if(!s->budget--) { s->failed_pc=0x0c048826u; return 0; }
fr[11]=vf3_fpu_binary(fr[11],fr[0],r[18],'-');
goto P_0c048828;
P_0c048828: /* original 8b02, guest PC 0x0c048828 */
if(!s->budget--) { s->failed_pc=0x0c048828u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c048830; }
goto P_0c04882a;
P_0c04882a: /* original fbb2, guest PC 0x0c04882a */
if(!s->budget--) { s->failed_pc=0x0c04882au; return 0; }
fr[11]=vf3_fpu_binary(fr[11],fr[11],r[18],'*');
goto P_0c04882c;
P_0c04882c: /* original 0023, guest PC 0x0c04882c */
if(!s->budget--) { s->failed_pc=0x0c04882cu; return 0; }
target=r[0]+0x0c048830u;
fr[3]=vf3_fpu_binary(fr[3],fr[11],r[18],'+');
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
P_0c04882e: /* original f3b0, guest PC 0x0c04882e */
if(!s->budget--) { s->failed_pc=0x0c04882eu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[11],r[18],'+');
goto P_0c048830;
P_0c048830: /* original f62b, guest PC 0x0c048830 */
if(!s->budget--) { s->failed_pc=0x0c048830u; return 0; }
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[6]);
goto P_0c048832;
P_0c048832: /* original f672, guest PC 0x0c048832 */
if(!s->budget--) { s->failed_pc=0x0c048832u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[7],r[18],'*');
goto P_0c048834;
P_0c048834: /* original 2626, guest PC 0x0c048834 */
if(!s->budget--) { s->failed_pc=0x0c048834u; return 0; }
r[6]-=4; write(ram,r[6],r[2],4);
goto P_0c048836;
P_0c048836: /* original f572, guest PC 0x0c048836 */
if(!s->budget--) { s->failed_pc=0x0c048836u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[7],r[18],'*');
goto P_0c048838;
P_0c048838: /* original 2616, guest PC 0x0c048838 */
if(!s->budget--) { s->failed_pc=0x0c048838u; return 0; }
r[6]-=4; write(ram,r[6],r[1],4);
goto P_0c04883a;
P_0c04883a: /* original 2338, guest PC 0x0c04883a */
if(!s->budget--) { s->failed_pc=0x0c04883au; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c04883c;
P_0c04883c: /* original f66b, guest PC 0x0c04883c */
if(!s->budget--) { s->failed_pc=0x0c04883cu; return 0; }
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,6,r[6]);
goto P_0c04883e;
P_0c04883e: /* original 8d05, guest PC 0x0c04883e */
if(!s->budget--) { s->failed_pc=0x0c04883eu; return 0; }
cond=r[17]&1u;
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,4,r[6]);
if(cond) { goto P_0c04884c; }
goto P_0c048842;
P_0c048840: /* original f64b, guest PC 0x0c048840 */
if(!s->budget--) { s->failed_pc=0x0c048840u; return 0; }
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,4,r[6]);
goto P_0c048842;
P_0c048842: /* original 2662, guest PC 0x0c048842 */
if(!s->budget--) { s->failed_pc=0x0c048842u; return 0; }
write(ram,r[6],r[6],4);
goto P_0c048844;
P_0c048844: /* original 0683, guest PC 0x0c048844 */
if(!s->budget--) { s->failed_pc=0x0c048844u; return 0; }
goto P_0c048846;
P_0c048846: /* original 8fb7, guest PC 0x0c048846 */
if(!s->budget--) { s->failed_pc=0x0c048846u; return 0; }
cond=r[17]&1u;
vf3_matrix_load(s,ram,4,r[14]);
r[14]+=(r[18]&0x100000u)?8:4;
if(!cond) { goto P_0c0487b8; }
goto P_0c04884a;
P_0c048848: /* original f4e9, guest PC 0x0c048848 */
if(!s->budget--) { s->failed_pc=0x0c048848u; return 0; }
vf3_matrix_load(s,ram,4,r[14]);
r[14]+=(r[18]&0x100000u)?8:4;
goto P_0c04884a;
P_0c04884a: /* original 0009, guest PC 0x0c04884a */
if(!s->budget--) { s->failed_pc=0x0c04884au; return 0; }
goto P_0c04884c;
P_0c04884c: /* original 60e6, guest PC 0x0c04884c */
if(!s->budget--) { s->failed_pc=0x0c04884cu; return 0; }
tmp=read(ram,r[14],4);
r[14]+=4;
r[0]=tmp;
goto P_0c04884e;
P_0c04884e: /* original e1ff, guest PC 0x0c04884e */
if(!s->budget--) { s->failed_pc=0x0c04884eu; return 0; }
r[1]=0xffffffffu;
goto P_0c048850;
P_0c048850: /* original 4015, guest PC 0x0c048850 */
if(!s->budget--) { s->failed_pc=0x0c048850u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[0]>0)!=0);
goto P_0c048852;
P_0c048852: /* original 2612, guest PC 0x0c048852 */
if(!s->budget--) { s->failed_pc=0x0c048852u; return 0; }
write(ram,r[6],r[1],4);
goto P_0c048854;
P_0c048854: /* original 8f0f, guest PC 0x0c048854 */
if(!s->budget--) { s->failed_pc=0x0c048854u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c048876; }
goto P_0c048858;
P_0c048856: /* original 0683, guest PC 0x0c048856 */
if(!s->budget--) { s->failed_pc=0x0c048856u; return 0; }
goto P_0c048858;
P_0c048858: /* original c880, guest PC 0x0c048858 */
if(!s->budget--) { s->failed_pc=0x0c048858u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&128u)==0)!=0);
goto P_0c04885a;
P_0c04885a: /* original 63e6, guest PC 0x0c04885a */
if(!s->budget--) { s->failed_pc=0x0c04885au; return 0; }
tmp=read(ram,r[14],4);
r[14]+=4;
r[3]=tmp;
goto P_0c04885c;
P_0c04885c: /* original 890b, guest PC 0x0c04885c */
if(!s->budget--) { s->failed_pc=0x0c04885cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c048876; }
goto P_0c04885e;
P_0c04885e: /* original 60e2, guest PC 0x0c04885e */
if(!s->budget--) { s->failed_pc=0x0c04885eu; return 0; }
tmp=read(ram,r[14],4);
r[0]=tmp;
goto P_0c048860;
P_0c048860: /* original 7408, guest PC 0x0c048860 */
if(!s->budget--) { s->failed_pc=0x0c048860u; return 0; }
r[4]+=0x00000008u;
goto P_0c048862;
P_0c048862: /* original f4e9, guest PC 0x0c048862 */
if(!s->budget--) { s->failed_pc=0x0c048862u; return 0; }
vf3_matrix_load(s,ram,4,r[14]);
r[14]+=(r[18]&0x100000u)?8:4;
goto P_0c048864;
P_0c048864: /* original c801, guest PC 0x0c048864 */
if(!s->budget--) { s->failed_pc=0x0c048864u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&1u)==0)!=0);
goto P_0c048866;
P_0c048866: /* original f6e9, guest PC 0x0c048866 */
if(!s->budget--) { s->failed_pc=0x0c048866u; return 0; }
vf3_matrix_load(s,ram,6,r[14]);
r[14]+=(r[18]&0x100000u)?8:4;
goto P_0c048868;
P_0c048868: /* original 8fa8, guest PC 0x0c048868 */
if(!s->budget--) { s->failed_pc=0x0c048868u; return 0; }
cond=r[17]&1u;
fr[2]=vf3_fpu_binary(fr[2],fr[2],r[18],'-');
if(!cond) { goto P_0c0487bc; }
goto P_0c04886c;
P_0c04886a: /* original f221, guest PC 0x0c04886a */
if(!s->budget--) { s->failed_pc=0x0c04886au; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[2],r[18],'-');
goto P_0c04886c;
P_0c04886c: /* original f51d, guest PC 0x0c04886c */
if(!s->budget--) { s->failed_pc=0x0c04886cu; return 0; }
r[53]=fr[5];
goto P_0c04886e;
P_0c04886e: /* original 74e8, guest PC 0x0c04886e */
if(!s->budget--) { s->failed_pc=0x0c04886eu; return 0; }
r[4]+=0xffffffe8u;
goto P_0c048870;
P_0c048870: /* original 0e5a, guest PC 0x0c048870 */
if(!s->budget--) { s->failed_pc=0x0c048870u; return 0; }
r[14]=r[53];
goto P_0c048872;
P_0c048872: /* original afa0, guest PC 0x0c048872 */
if(!s->budget--) { s->failed_pc=0x0c048872u; return 0; }
r[14]+=r[4];
goto P_0c0487b6;
P_0c048874: /* original 3e4c, guest PC 0x0c048874 */
if(!s->budget--) { s->failed_pc=0x0c048874u; return 0; }
r[14]+=r[4];
goto P_0c048876;
P_0c048876: /* original 74e0, guest PC 0x0c048876 */
if(!s->budget--) { s->failed_pc=0x0c048876u; return 0; }
r[4]+=0xffffffe0u;
goto P_0c048878;
P_0c048878: /* original 7620, guest PC 0x0c048878 */
if(!s->budget--) { s->failed_pc=0x0c048878u; return 0; }
r[6]+=0x00000020u;
goto P_0c04887a;
P_0c04887a: /* original 000b, guest PC 0x0c04887a */
if(!s->budget--) { s->failed_pc=0x0c04887au; return 0; }
target=r[16];
r[18]^=0x100000u;
s->pc=target; return ram->oob==0;
P_0c04887c: /* original f3fd, guest PC 0x0c04887c */
if(!s->budget--) { s->failed_pc=0x0c04887cu; return 0; }
r[18]^=0x100000u;
return vf3_matrix_family(0x0c04887eu,s,ram);
P_0c0488e0: /* original 8b00, guest PC 0x0c0488e0 */
if(!s->budget--) { s->failed_pc=0x0c0488e0u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0488e4; }
goto P_0c0488e2;
P_0c0488e2: /* original a9fd, guest PC 0x0c0488e2 */
if(!s->budget--) { s->failed_pc=0x0c0488e2u; return 0; }
return vf3_matrix_family(0x0c047ce0u,s,ram);
P_0c0488e4: /* original 0009, guest PC 0x0c0488e4 */
if(!s->budget--) { s->failed_pc=0x0c0488e4u; return 0; }
return vf3_matrix_family(0x0c0488e6u,s,ram);
P_0c048d60: /* original 8b00, guest PC 0x0c048d60 */
if(!s->budget--) { s->failed_pc=0x0c048d60u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c048d64; }
goto P_0c048d62;
P_0c048d62: /* original a9ad, guest PC 0x0c048d62 */
if(!s->budget--) { s->failed_pc=0x0c048d62u; return 0; }
return vf3_matrix_family(0x0c0480c0u,s,ram);
P_0c048d64: /* original 0009, guest PC 0x0c048d64 */
if(!s->budget--) { s->failed_pc=0x0c048d64u; return 0; }
return vf3_matrix_family(0x0c048d66u,s,ram);
P_0c048f60: /* original e303, guest PC 0x0c048f60 */
if(!s->budget--) { s->failed_pc=0x0c048f60u; return 0; }
r[3]=0x00000003u;
goto P_0c048f62;
P_0c048f62: /* original 6946, guest PC 0x0c048f62 */
if(!s->budget--) { s->failed_pc=0x0c048f62u; return 0; }
tmp=read(ram,r[4],4);
r[4]+=4;
r[9]=tmp;
goto P_0c048f64;
P_0c048f64: /* original 76e0, guest PC 0x0c048f64 */
if(!s->budget--) { s->failed_pc=0x0c048f64u; return 0; }
r[6]+=0xffffffe0u;
goto P_0c048f66;
P_0c048f66: /* original 6042, guest PC 0x0c048f66 */
if(!s->budget--) { s->failed_pc=0x0c048f66u; return 0; }
tmp=read(ram,r[4],4);
r[0]=tmp;
goto P_0c048f68;
P_0c048f68: /* original f3fd, guest PC 0x0c048f68 */
if(!s->budget--) { s->failed_pc=0x0c048f68u; return 0; }
r[18]^=0x100000u;
goto P_0c048f6a;
P_0c048f6a: /* original c801, guest PC 0x0c048f6a */
if(!s->budget--) { s->failed_pc=0x0c048f6au; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&1u)==0)!=0);
goto P_0c048f6c;
P_0c048f6c: /* original 6e43, guest PC 0x0c048f6c */
if(!s->budget--) { s->failed_pc=0x0c048f6cu; return 0; }
r[14]=r[4];
goto P_0c048f6e;
P_0c048f6e: /* original 8f03, guest PC 0x0c048f6e */
if(!s->budget--) { s->failed_pc=0x0c048f6eu; return 0; }
cond=r[17]&1u;
r[4]+=0x00000020u;
if(!cond) { goto P_0c048f78; }
goto P_0c048f72;
P_0c048f70: /* original 7420, guest PC 0x0c048f70 */
if(!s->budget--) { s->failed_pc=0x0c048f70u; return 0; }
r[4]+=0x00000020u;
goto P_0c048f72;
P_0c048f72: /* original 5ee1, guest PC 0x0c048f72 */
if(!s->budget--) { s->failed_pc=0x0c048f72u; return 0; }
r[14]=read(ram,r[14]+4,4);
goto P_0c048f74;
P_0c048f74: /* original 74e8, guest PC 0x0c048f74 */
if(!s->budget--) { s->failed_pc=0x0c048f74u; return 0; }
r[4]+=0xffffffe8u;
goto P_0c048f76;
P_0c048f76: /* original 3e4c, guest PC 0x0c048f76 */
if(!s->budget--) { s->failed_pc=0x0c048f76u; return 0; }
r[14]+=r[4];
goto P_0c048f78;
P_0c048f78: /* original f4e9, guest PC 0x0c048f78 */
if(!s->budget--) { s->failed_pc=0x0c048f78u; return 0; }
vf3_matrix_load(s,ram,4,r[14]);
r[14]+=(r[18]&0x100000u)?8:4;
goto P_0c048f7a;
P_0c048f7a: /* original f6e9, guest PC 0x0c048f7a */
if(!s->budget--) { s->failed_pc=0x0c048f7au; return 0; }
vf3_matrix_load(s,ram,6,r[14]);
r[14]+=(r[18]&0x100000u)?8:4;
goto P_0c048f7c;
P_0c048f7c: /* original f28d, guest PC 0x0c048f7c */
if(!s->budget--) { s->failed_pc=0x0c048f7cu; return 0; }
fr[2]=0;
goto P_0c048f7e;
P_0c048f7e: /* original f270, guest PC 0x0c048f7e */
if(!s->budget--) { s->failed_pc=0x0c048f7eu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[7],r[18],'+');
goto P_0c048f80;
P_0c048f80: /* original f79d, guest PC 0x0c048f80 */
if(!s->budget--) { s->failed_pc=0x0c048f80u; return 0; }
fr[7]=0x3f800000u;
goto P_0c048f82;
P_0c048f82: /* original 7640, guest PC 0x0c048f82 */
if(!s->budget--) { s->failed_pc=0x0c048f82u; return 0; }
r[6]+=0x00000040u;
goto P_0c048f84;
P_0c048f84: /* original f38d, guest PC 0x0c048f84 */
if(!s->budget--) { s->failed_pc=0x0c048f84u; return 0; }
fr[3]=0;
goto P_0c048f86;
P_0c048f86: /* original 7520, guest PC 0x0c048f86 */
if(!s->budget--) { s->failed_pc=0x0c048f86u; return 0; }
r[5]+=0x00000020u;
goto P_0c048f88;
P_0c048f88: /* original f0e9, guest PC 0x0c048f88 */
if(!s->budget--) { s->failed_pc=0x0c048f88u; return 0; }
vf3_matrix_load(s,ram,0,r[14]);
r[14]+=(r[18]&0x100000u)?8:4;
goto P_0c048f8a;
P_0c048f8a: /* original f5fd, guest PC 0x0c048f8a */
if(!s->budget--) { s->failed_pc=0x0c048f8au; return 0; }
if(!vf3_fpu_ftrv(xf,fr+4,r[18],fr+4)) goto unsupported;
goto P_0c048f8c;
P_0c048f8c: /* original fb8d, guest PC 0x0c048f8c */
if(!s->budget--) { s->failed_pc=0x0c048f8cu; return 0; }
fr[11]=0;
goto P_0c048f8e;
P_0c048f8e: /* original 61e6, guest PC 0x0c048f8e */
if(!s->budget--) { s->failed_pc=0x0c048f8eu; return 0; }
tmp=read(ram,r[14],4);
r[14]+=4;
r[1]=tmp;
goto P_0c048f90;
P_0c048f90: /* original 4310, guest PC 0x0c048f90 */
if(!s->budget--) { s->failed_pc=0x0c048f90u; return 0; }
--r[3];
r[17]=(r[17]&~1u)|((r[3]==0)!=0);
goto P_0c048f92;
P_0c048f92: /* original 62e6, guest PC 0x0c048f92 */
if(!s->budget--) { s->failed_pc=0x0c048f92u; return 0; }
tmp=read(ram,r[14],4);
r[14]+=4;
r[2]=tmp;
goto P_0c048f94;
P_0c048f94: /* original 8d12, guest PC 0x0c048f94 */
if(!s->budget--) { s->failed_pc=0x0c048f94u; return 0; }
cond=r[17]&1u;
tmp=read(ram,r[4],4);
r[0]=tmp;
if(cond) { goto P_0c048fbc; }
goto P_0c048f98;
P_0c048f96: /* original 6042, guest PC 0x0c048f96 */
if(!s->budget--) { s->failed_pc=0x0c048f96u; return 0; }
tmp=read(ram,r[4],4);
r[0]=tmp;
goto P_0c048f98;
P_0c048f98: /* original f3ed, guest PC 0x0c048f98 */
if(!s->budget--) { s->failed_pc=0x0c048f98u; return 0; }
if(!vf3_fpu_fipr(fr+12,fr+0,r[18],fr+3)) goto unsupported;
goto P_0c048f9a;
P_0c048f9a: /* original 5e41, guest PC 0x0c048f9a */
if(!s->budget--) { s->failed_pc=0x0c048f9au; return 0; }
r[14]=read(ram,r[4]+4,4);
goto P_0c048f9c;
P_0c048f9c: /* original c801, guest PC 0x0c048f9c */
if(!s->budget--) { s->failed_pc=0x0c048f9cu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&1u)==0)!=0);
goto P_0c048f9e;
P_0c048f9e: /* original f79d, guest PC 0x0c048f9e */
if(!s->budget--) { s->failed_pc=0x0c048f9eu; return 0; }
fr[7]=0x3f800000u;
goto P_0c048fa0;
P_0c048fa0: /* original 8f0f, guest PC 0x0c048fa0 */
if(!s->budget--) { s->failed_pc=0x0c048fa0u; return 0; }
cond=r[17]&1u;
fr[7]=vf3_fpu_binary(fr[7],fr[4],r[18],'/');
if(!cond) { goto P_0c048fc2; }
goto P_0c048fa4;
P_0c048fa2: /* original f743, guest PC 0x0c048fa2 */
if(!s->budget--) { s->failed_pc=0x0c048fa2u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[4],r[18],'/');
goto P_0c048fa4;
P_0c048fa4: /* original 7408, guest PC 0x0c048fa4 */
if(!s->budget--) { s->failed_pc=0x0c048fa4u; return 0; }
r[4]+=0x00000008u;
goto P_0c048fa6;
P_0c048fa6: /* original 0483, guest PC 0x0c048fa6 */
if(!s->budget--) { s->failed_pc=0x0c048fa6u; return 0; }
goto P_0c048fa8;
P_0c048fa8: /* original f3b5, guest PC 0x0c048fa8 */
if(!s->budget--) { s->failed_pc=0x0c048fa8u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[11]))!=0);
goto P_0c048faa;
P_0c048faa: /* original 3e4c, guest PC 0x0c048faa */
if(!s->budget--) { s->failed_pc=0x0c048faau; return 0; }
r[14]+=r[4];
goto P_0c048fac;
P_0c048fac: /* original ff1d, guest PC 0x0c048fac */
if(!s->budget--) { s->failed_pc=0x0c048facu; return 0; }
r[53]=fr[15];
goto P_0c048fae;
P_0c048fae: /* original f8ed, guest PC 0x0c048fae */
if(!s->budget--) { s->failed_pc=0x0c048faeu; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+8,r[18],fr+11)) goto unsupported;
goto P_0c048fb0;
P_0c048fb0: /* original 0e83, guest PC 0x0c048fb0 */
if(!s->budget--) { s->failed_pc=0x0c048fb0u; return 0; }
goto P_0c048fb2;
P_0c048fb2: /* original 8f0f, guest PC 0x0c048fb2 */
if(!s->budget--) { s->failed_pc=0x0c048fb2u; return 0; }
cond=r[17]&1u;
fr[2]=r[53];
if(!cond) { goto P_0c048fd4; }
goto P_0c048fb6;
P_0c048fb4: /* original f20d, guest PC 0x0c048fb4 */
if(!s->budget--) { s->failed_pc=0x0c048fb4u; return 0; }
fr[2]=r[53];
goto P_0c048fb6;
P_0c048fb6: /* original a00d, guest PC 0x0c048fb6 */
if(!s->budget--) { s->failed_pc=0x0c048fb6u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'+');
goto P_0c048fd4;
P_0c048fb8: /* original f230, guest PC 0x0c048fb8 */
if(!s->budget--) { s->failed_pc=0x0c048fb8u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'+');
return vf3_matrix_family(0x0c048fbau,s,ram);
P_0c048fbc: /* original f3ed, guest PC 0x0c048fbc */
if(!s->budget--) { s->failed_pc=0x0c048fbcu; return 0; }
if(!vf3_fpu_fipr(fr+12,fr+0,r[18],fr+3)) goto unsupported;
goto P_0c048fbe;
P_0c048fbe: /* original f79d, guest PC 0x0c048fbe */
if(!s->budget--) { s->failed_pc=0x0c048fbeu; return 0; }
fr[7]=0x3f800000u;
goto P_0c048fc0;
P_0c048fc0: /* original f743, guest PC 0x0c048fc0 */
if(!s->budget--) { s->failed_pc=0x0c048fc0u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[4],r[18],'/');
goto P_0c048fc2;
P_0c048fc2: /* original 6e43, guest PC 0x0c048fc2 */
if(!s->budget--) { s->failed_pc=0x0c048fc2u; return 0; }
r[14]=r[4];
goto P_0c048fc4;
P_0c048fc4: /* original 7420, guest PC 0x0c048fc4 */
if(!s->budget--) { s->failed_pc=0x0c048fc4u; return 0; }
r[4]+=0x00000020u;
goto P_0c048fc6;
P_0c048fc6: /* original f3b5, guest PC 0x0c048fc6 */
if(!s->budget--) { s->failed_pc=0x0c048fc6u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[11]))!=0);
goto P_0c048fc8;
P_0c048fc8: /* original 0483, guest PC 0x0c048fc8 */
if(!s->budget--) { s->failed_pc=0x0c048fc8u; return 0; }
goto P_0c048fca;
P_0c048fca: /* original f8ed, guest PC 0x0c048fca */
if(!s->budget--) { s->failed_pc=0x0c048fcau; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+8,r[18],fr+11)) goto unsupported;
goto P_0c048fcc;
P_0c048fcc: /* original ff1d, guest PC 0x0c048fcc */
if(!s->budget--) { s->failed_pc=0x0c048fccu; return 0; }
r[53]=fr[15];
goto P_0c048fce;
P_0c048fce: /* original 8f01, guest PC 0x0c048fce */
if(!s->budget--) { s->failed_pc=0x0c048fceu; return 0; }
cond=r[17]&1u;
fr[2]=r[53];
if(!cond) { goto P_0c048fd4; }
goto P_0c048fd2;
P_0c048fd0: /* original f20d, guest PC 0x0c048fd0 */
if(!s->budget--) { s->failed_pc=0x0c048fd0u; return 0; }
fr[2]=r[53];
goto P_0c048fd2;
P_0c048fd2: /* original f230, guest PC 0x0c048fd2 */
if(!s->budget--) { s->failed_pc=0x0c048fd2u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'+');
goto P_0c048fd4;
P_0c048fd4: /* original 2888, guest PC 0x0c048fd4 */
if(!s->budget--) { s->failed_pc=0x0c048fd4u; return 0; }
r[17]=(r[17]&~1u)|(((r[8]&r[8])==0)!=0);
goto P_0c048fd6;
P_0c048fd6: /* original f38d, guest PC 0x0c048fd6 */
if(!s->budget--) { s->failed_pc=0x0c048fd6u; return 0; }
fr[3]=0;
goto P_0c048fd8;
P_0c048fd8: /* original 8d0c, guest PC 0x0c048fd8 */
if(!s->budget--) { s->failed_pc=0x0c048fd8u; return 0; }
cond=r[17]&1u;
r[17]=(r[17]&~1u)|((as_float(fr[11])>as_float(fr[3]))!=0);
if(cond) { goto P_0c048ff4; }
goto P_0c048fdc;
P_0c048fda: /* original fb35, guest PC 0x0c048fda */
if(!s->budget--) { s->failed_pc=0x0c048fdau; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[11])>as_float(fr[3]))!=0);
goto P_0c048fdc;
P_0c048fdc: /* original f09d, guest PC 0x0c048fdc */
if(!s->budget--) { s->failed_pc=0x0c048fdcu; return 0; }
fr[0]=0x3f800000u;
goto P_0c048fde;
P_0c048fde: /* original fbb2, guest PC 0x0c048fde */
if(!s->budget--) { s->failed_pc=0x0c048fdeu; return 0; }
fr[11]=vf3_fpu_binary(fr[11],fr[11],r[18],'*');
goto P_0c048fe0;
P_0c048fe0: /* original 8b08, guest PC 0x0c048fe0 */
if(!s->budget--) { s->failed_pc=0x0c048fe0u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c048ff4; }
goto P_0c048fe2;
P_0c048fe2: /* original fbb0, guest PC 0x0c048fe2 */
if(!s->budget--) { s->failed_pc=0x0c048fe2u; return 0; }
fr[11]=vf3_fpu_binary(fr[11],fr[11],r[18],'+');
goto P_0c048fe4;
P_0c048fe4: /* original 6083, guest PC 0x0c048fe4 */
if(!s->budget--) { s->failed_pc=0x0c048fe4u; return 0; }
r[0]=r[8];
goto P_0c048fe6;
P_0c048fe6: /* original fb05, guest PC 0x0c048fe6 */
if(!s->budget--) { s->failed_pc=0x0c048fe6u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[11])>as_float(fr[0]))!=0);
goto P_0c048fe8;
P_0c048fe8: /* original 7048, guest PC 0x0c048fe8 */
if(!s->budget--) { s->failed_pc=0x0c048fe8u; return 0; }
r[0]+=0x00000048u;
goto P_0c048fea;
P_0c048fea: /* original fb01, guest PC 0x0c048fea */
if(!s->budget--) { s->failed_pc=0x0c048feau; return 0; }
fr[11]=vf3_fpu_binary(fr[11],fr[0],r[18],'-');
goto P_0c048fec;
P_0c048fec: /* original 8b02, guest PC 0x0c048fec */
if(!s->budget--) { s->failed_pc=0x0c048fecu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c048ff4; }
goto P_0c048fee;
P_0c048fee: /* original fbb2, guest PC 0x0c048fee */
if(!s->budget--) { s->failed_pc=0x0c048feeu; return 0; }
fr[11]=vf3_fpu_binary(fr[11],fr[11],r[18],'*');
goto P_0c048ff0;
P_0c048ff0: /* original 0023, guest PC 0x0c048ff0 */
if(!s->budget--) { s->failed_pc=0x0c048ff0u; return 0; }
target=r[0]+0x0c048ff4u;
fr[3]=vf3_fpu_binary(fr[3],fr[11],r[18],'+');
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
P_0c048ff2: /* original f3b0, guest PC 0x0c048ff2 */
if(!s->budget--) { s->failed_pc=0x0c048ff2u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[11],r[18],'+');
goto P_0c048ff4;
P_0c048ff4: /* original f62b, guest PC 0x0c048ff4 */
if(!s->budget--) { s->failed_pc=0x0c048ff4u; return 0; }
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[6]);
goto P_0c048ff6;
P_0c048ff6: /* original f672, guest PC 0x0c048ff6 */
if(!s->budget--) { s->failed_pc=0x0c048ff6u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[7],r[18],'*');
goto P_0c048ff8;
P_0c048ff8: /* original 2626, guest PC 0x0c048ff8 */
if(!s->budget--) { s->failed_pc=0x0c048ff8u; return 0; }
r[6]-=4; write(ram,r[6],r[2],4);
goto P_0c048ffa;
P_0c048ffa: /* original f572, guest PC 0x0c048ffa */
if(!s->budget--) { s->failed_pc=0x0c048ffau; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[7],r[18],'*');
goto P_0c048ffc;
P_0c048ffc: /* original 2616, guest PC 0x0c048ffc */
if(!s->budget--) { s->failed_pc=0x0c048ffcu; return 0; }
r[6]-=4; write(ram,r[6],r[1],4);
goto P_0c048ffe;
P_0c048ffe: /* original 2338, guest PC 0x0c048ffe */
if(!s->budget--) { s->failed_pc=0x0c048ffeu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c049000;
P_0c049000: /* original f66b, guest PC 0x0c049000 */
if(!s->budget--) { s->failed_pc=0x0c049000u; return 0; }
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,6,r[6]);
goto P_0c049002;
P_0c049002: /* original 8d05, guest PC 0x0c049002 */
if(!s->budget--) { s->failed_pc=0x0c049002u; return 0; }
cond=r[17]&1u;
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,4,r[6]);
if(cond) { goto P_0c049010; }
goto P_0c049006;
P_0c049004: /* original f64b, guest PC 0x0c049004 */
if(!s->budget--) { s->failed_pc=0x0c049004u; return 0; }
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,4,r[6]);
goto P_0c049006;
P_0c049006: /* original 2662, guest PC 0x0c049006 */
if(!s->budget--) { s->failed_pc=0x0c049006u; return 0; }
write(ram,r[6],r[6],4);
goto P_0c049008;
P_0c049008: /* original 0683, guest PC 0x0c049008 */
if(!s->budget--) { s->failed_pc=0x0c049008u; return 0; }
goto P_0c04900a;
P_0c04900a: /* original 8fb6, guest PC 0x0c04900a */
if(!s->budget--) { s->failed_pc=0x0c04900au; return 0; }
cond=r[17]&1u;
vf3_matrix_load(s,ram,4,r[14]);
r[14]+=(r[18]&0x100000u)?8:4;
if(!cond) { goto P_0c048f7a; }
goto P_0c04900e;
P_0c04900c: /* original f4e9, guest PC 0x0c04900c */
if(!s->budget--) { s->failed_pc=0x0c04900cu; return 0; }
vf3_matrix_load(s,ram,4,r[14]);
r[14]+=(r[18]&0x100000u)?8:4;
goto P_0c04900e;
P_0c04900e: /* original 0009, guest PC 0x0c04900e */
if(!s->budget--) { s->failed_pc=0x0c04900eu; return 0; }
goto P_0c049010;
P_0c049010: /* original e1ff, guest PC 0x0c049010 */
if(!s->budget--) { s->failed_pc=0x0c049010u; return 0; }
r[1]=0xffffffffu;
goto P_0c049012;
P_0c049012: /* original 2612, guest PC 0x0c049012 */
if(!s->budget--) { s->failed_pc=0x0c049012u; return 0; }
write(ram,r[6],r[1],4);
goto P_0c049014;
P_0c049014: /* original 4910, guest PC 0x0c049014 */
if(!s->budget--) { s->failed_pc=0x0c049014u; return 0; }
--r[9];
r[17]=(r[17]&~1u)|((r[9]==0)!=0);
goto P_0c049016;
P_0c049016: /* original 0683, guest PC 0x0c049016 */
if(!s->budget--) { s->failed_pc=0x0c049016u; return 0; }
goto P_0c049018;
P_0c049018: /* original 890b, guest PC 0x0c049018 */
if(!s->budget--) { s->failed_pc=0x0c049018u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c049032; }
goto P_0c04901a;
P_0c04901a: /* original 60e2, guest PC 0x0c04901a */
if(!s->budget--) { s->failed_pc=0x0c04901au; return 0; }
tmp=read(ram,r[14],4);
r[0]=tmp;
goto P_0c04901c;
P_0c04901c: /* original e303, guest PC 0x0c04901c */
if(!s->budget--) { s->failed_pc=0x0c04901cu; return 0; }
r[3]=0x00000003u;
goto P_0c04901e;
P_0c04901e: /* original f4e9, guest PC 0x0c04901e */
if(!s->budget--) { s->failed_pc=0x0c04901eu; return 0; }
vf3_matrix_load(s,ram,4,r[14]);
r[14]+=(r[18]&0x100000u)?8:4;
goto P_0c049020;
P_0c049020: /* original c801, guest PC 0x0c049020 */
if(!s->budget--) { s->failed_pc=0x0c049020u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&1u)==0)!=0);
goto P_0c049022;
P_0c049022: /* original f6e9, guest PC 0x0c049022 */
if(!s->budget--) { s->failed_pc=0x0c049022u; return 0; }
vf3_matrix_load(s,ram,6,r[14]);
r[14]+=(r[18]&0x100000u)?8:4;
goto P_0c049024;
P_0c049024: /* original 8fab, guest PC 0x0c049024 */
if(!s->budget--) { s->failed_pc=0x0c049024u; return 0; }
cond=r[17]&1u;
fr[2]=vf3_fpu_binary(fr[2],fr[2],r[18],'-');
if(!cond) { goto P_0c048f7e; }
goto P_0c049028;
P_0c049026: /* original f221, guest PC 0x0c049026 */
if(!s->budget--) { s->failed_pc=0x0c049026u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[2],r[18],'-');
goto P_0c049028;
P_0c049028: /* original f51d, guest PC 0x0c049028 */
if(!s->budget--) { s->failed_pc=0x0c049028u; return 0; }
r[53]=fr[5];
goto P_0c04902a;
P_0c04902a: /* original 74e8, guest PC 0x0c04902a */
if(!s->budget--) { s->failed_pc=0x0c04902au; return 0; }
r[4]+=0xffffffe8u;
goto P_0c04902c;
P_0c04902c: /* original 0e5a, guest PC 0x0c04902c */
if(!s->budget--) { s->failed_pc=0x0c04902cu; return 0; }
r[14]=r[53];
goto P_0c04902e;
P_0c04902e: /* original afa3, guest PC 0x0c04902e */
if(!s->budget--) { s->failed_pc=0x0c04902eu; return 0; }
r[14]+=r[4];
goto P_0c048f78;
P_0c049030: /* original 3e4c, guest PC 0x0c049030 */
if(!s->budget--) { s->failed_pc=0x0c049030u; return 0; }
r[14]+=r[4];
goto P_0c049032;
P_0c049032: /* original 74e0, guest PC 0x0c049032 */
if(!s->budget--) { s->failed_pc=0x0c049032u; return 0; }
r[4]+=0xffffffe0u;
goto P_0c049034;
P_0c049034: /* original 7620, guest PC 0x0c049034 */
if(!s->budget--) { s->failed_pc=0x0c049034u; return 0; }
r[6]+=0x00000020u;
goto P_0c049036;
P_0c049036: /* original 000b, guest PC 0x0c049036 */
if(!s->budget--) { s->failed_pc=0x0c049036u; return 0; }
target=r[16];
r[18]^=0x100000u;
s->pc=target; return ram->oob==0;
P_0c049038: /* original f3fd, guest PC 0x0c049038 */
if(!s->budget--) { s->failed_pc=0x0c049038u; return 0; }
r[18]^=0x100000u;
return vf3_matrix_family(0x0c04903au,s,ram);
P_0c05fc9a: /* original d339, guest PC 0x0c05fc9a */
if(!s->budget--) { s->failed_pc=0x0c05fc9au; return 0; }
r[3]=read(ram,0x0c05fd80u,4);
goto P_0c05fc9c;
P_0c05fc9c: /* original 432b, guest PC 0x0c05fc9c */
if(!s->budget--) { s->failed_pc=0x0c05fc9cu; return 0; }
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
P_0c05fc9e: /* original 0009, guest PC 0x0c05fc9e */
if(!s->budget--) { s->failed_pc=0x0c05fc9eu; return 0; }
return vf3_matrix_family(0x0c05fca0u,s,ram);
P_0c06054c: /* original 2fe6, guest PC 0x0c06054c */
if(!s->budget--) { s->failed_pc=0x0c06054cu; return 0; }
r[15]-=4; write(ram,r[15],r[14],4);
goto P_0c06054e;
P_0c06054e: /* original 2fd6, guest PC 0x0c06054e */
if(!s->budget--) { s->failed_pc=0x0c06054eu; return 0; }
r[15]-=4; write(ram,r[15],r[13],4);
goto P_0c060550;
P_0c060550: /* original 2fc6, guest PC 0x0c060550 */
if(!s->budget--) { s->failed_pc=0x0c060550u; return 0; }
r[15]-=4; write(ram,r[15],r[12],4);
goto P_0c060552;
P_0c060552: /* original 4f22, guest PC 0x0c060552 */
if(!s->budget--) { s->failed_pc=0x0c060552u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c060554;
P_0c060554: /* original 90b6, guest PC 0x0c060554 */
if(!s->budget--) { s->failed_pc=0x0c060554u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0606c4u,2);
goto P_0c060556;
P_0c060556: /* original 64f3, guest PC 0x0c060556 */
if(!s->budget--) { s->failed_pc=0x0c060556u; return 0; }
r[4]=r[15];
goto P_0c060558;
P_0c060558: /* original d25c, guest PC 0x0c060558 */
if(!s->budget--) { s->failed_pc=0x0c060558u; return 0; }
r[2]=read(ram,0x0c0606ccu,4);
goto P_0c06055a;
P_0c06055a: /* original 7410, guest PC 0x0c06055a */
if(!s->budget--) { s->failed_pc=0x0c06055au; return 0; }
r[4]+=0x00000010u;
goto P_0c06055c;
P_0c06055c: /* original 034e, guest PC 0x0c06055c */
if(!s->budget--) { s->failed_pc=0x0c06055cu; return 0; }
r[3]=read(ram,r[4]+r[0],4);
goto P_0c06055e;
P_0c06055e: /* original 2232, guest PC 0x0c06055e */
if(!s->budget--) { s->failed_pc=0x0c06055eu; return 0; }
write(ram,r[2],r[3],4);
goto P_0c060560;
P_0c060560: /* original d35b, guest PC 0x0c060560 */
if(!s->budget--) { s->failed_pc=0x0c060560u; return 0; }
r[3]=read(ram,0x0c0606d0u,4);
goto P_0c060562;
P_0c060562: /* original 70f8, guest PC 0x0c060562 */
if(!s->budget--) { s->failed_pc=0x0c060562u; return 0; }
r[0]+=0xfffffff8u;
goto P_0c060564;
P_0c060564: /* original 014e, guest PC 0x0c060564 */
if(!s->budget--) { s->failed_pc=0x0c060564u; return 0; }
r[1]=read(ram,r[4]+r[0],4);
goto P_0c060566;
P_0c060566: /* original 2312, guest PC 0x0c060566 */
if(!s->budget--) { s->failed_pc=0x0c060566u; return 0; }
write(ram,r[3],r[1],4);
goto P_0c060568;
P_0c060568: /* original d15a, guest PC 0x0c060568 */
if(!s->budget--) { s->failed_pc=0x0c060568u; return 0; }
r[1]=read(ram,0x0c0606d4u,4);
goto P_0c06056a;
P_0c06056a: /* original 7004, guest PC 0x0c06056a */
if(!s->budget--) { s->failed_pc=0x0c06056au; return 0; }
r[0]+=0x00000004u;
goto P_0c06056c;
P_0c06056c: /* original 024e, guest PC 0x0c06056c */
if(!s->budget--) { s->failed_pc=0x0c06056cu; return 0; }
r[2]=read(ram,r[4]+r[0],4);
goto P_0c06056e;
P_0c06056e: /* original 2122, guest PC 0x0c06056e */
if(!s->budget--) { s->failed_pc=0x0c06056eu; return 0; }
write(ram,r[1],r[2],4);
goto P_0c060570;
P_0c060570: /* original e054, guest PC 0x0c060570 */
if(!s->budget--) { s->failed_pc=0x0c060570u; return 0; }
r[0]=0x00000054u;
goto P_0c060572;
P_0c060572: /* original 034e, guest PC 0x0c060572 */
if(!s->budget--) { s->failed_pc=0x0c060572u; return 0; }
r[3]=read(ram,r[4]+r[0],4);
goto P_0c060574;
P_0c060574: /* original 4300, guest PC 0x0c060574 */
if(!s->budget--) { s->failed_pc=0x0c060574u; return 0; }
r[17]=(r[17]&~1u)|((r[3]>>31)!=0);
r[3]<<=1;
goto P_0c060576;
P_0c060576: /* original e050, guest PC 0x0c060576 */
if(!s->budget--) { s->failed_pc=0x0c060576u; return 0; }
r[0]=0x00000050u;
goto P_0c060578;
P_0c060578: /* original 024e, guest PC 0x0c060578 */
if(!s->budget--) { s->failed_pc=0x0c060578u; return 0; }
r[2]=read(ram,r[4]+r[0],4);
goto P_0c06057a;
P_0c06057a: /* original e05c, guest PC 0x0c06057a */
if(!s->budget--) { s->failed_pc=0x0c06057au; return 0; }
r[0]=0x0000005cu;
goto P_0c06057c;
P_0c06057c: /* original 232b, guest PC 0x0c06057c */
if(!s->budget--) { s->failed_pc=0x0c06057cu; return 0; }
r[3]|=r[2];
goto P_0c06057e;
P_0c06057e: /* original 024e, guest PC 0x0c06057e */
if(!s->budget--) { s->failed_pc=0x0c06057eu; return 0; }
r[2]=read(ram,r[4]+r[0],4);
goto P_0c060580;
P_0c060580: /* original 4208, guest PC 0x0c060580 */
if(!s->budget--) { s->failed_pc=0x0c060580u; return 0; }
r[2]<<=2;
goto P_0c060582;
P_0c060582: /* original 232b, guest PC 0x0c060582 */
if(!s->budget--) { s->failed_pc=0x0c060582u; return 0; }
r[3]|=r[2];
goto P_0c060584;
P_0c060584: /* original e068, guest PC 0x0c060584 */
if(!s->budget--) { s->failed_pc=0x0c060584u; return 0; }
r[0]=0x00000068u;
goto P_0c060586;
P_0c060586: /* original 024e, guest PC 0x0c060586 */
if(!s->budget--) { s->failed_pc=0x0c060586u; return 0; }
r[2]=read(ram,r[4]+r[0],4);
goto P_0c060588;
P_0c060588: /* original 4208, guest PC 0x0c060588 */
if(!s->budget--) { s->failed_pc=0x0c060588u; return 0; }
r[2]<<=2;
goto P_0c06058a;
P_0c06058a: /* original 4200, guest PC 0x0c06058a */
if(!s->budget--) { s->failed_pc=0x0c06058au; return 0; }
r[17]=(r[17]&~1u)|((r[2]>>31)!=0);
r[2]<<=1;
goto P_0c06058c;
P_0c06058c: /* original 514b, guest PC 0x0c06058c */
if(!s->budget--) { s->failed_pc=0x0c06058cu; return 0; }
r[1]=read(ram,r[4]+44,4);
goto P_0c06058e;
P_0c06058e: /* original e060, guest PC 0x0c06058e */
if(!s->budget--) { s->failed_pc=0x0c06058eu; return 0; }
r[0]=0x00000060u;
goto P_0c060590;
P_0c060590: /* original 232b, guest PC 0x0c060590 */
if(!s->budget--) { s->failed_pc=0x0c060590u; return 0; }
r[3]|=r[2];
goto P_0c060592;
P_0c060592: /* original 524c, guest PC 0x0c060592 */
if(!s->budget--) { s->failed_pc=0x0c060592u; return 0; }
r[2]=read(ram,r[4]+48,4);
goto P_0c060594;
P_0c060594: /* original 4208, guest PC 0x0c060594 */
if(!s->budget--) { s->failed_pc=0x0c060594u; return 0; }
r[2]<<=2;
goto P_0c060596;
P_0c060596: /* original 4208, guest PC 0x0c060596 */
if(!s->budget--) { s->failed_pc=0x0c060596u; return 0; }
r[2]<<=2;
goto P_0c060598;
P_0c060598: /* original 232b, guest PC 0x0c060598 */
if(!s->budget--) { s->failed_pc=0x0c060598u; return 0; }
r[3]|=r[2];
goto P_0c06059a;
P_0c06059a: /* original 024e, guest PC 0x0c06059a */
if(!s->budget--) { s->failed_pc=0x0c06059au; return 0; }
r[2]=read(ram,r[4]+r[0],4);
goto P_0c06059c;
P_0c06059c: /* original 4208, guest PC 0x0c06059c */
if(!s->budget--) { s->failed_pc=0x0c06059cu; return 0; }
r[2]<<=2;
goto P_0c06059e;
P_0c06059e: /* original 4208, guest PC 0x0c06059e */
if(!s->budget--) { s->failed_pc=0x0c06059eu; return 0; }
r[2]<<=2;
goto P_0c0605a0;
P_0c0605a0: /* original 4200, guest PC 0x0c0605a0 */
if(!s->budget--) { s->failed_pc=0x0c0605a0u; return 0; }
r[17]=(r[17]&~1u)|((r[2]>>31)!=0);
r[2]<<=1;
goto P_0c0605a2;
P_0c0605a2: /* original 232b, guest PC 0x0c0605a2 */
if(!s->budget--) { s->failed_pc=0x0c0605a2u; return 0; }
r[3]|=r[2];
goto P_0c0605a4;
P_0c0605a4: /* original 524a, guest PC 0x0c0605a4 */
if(!s->budget--) { s->failed_pc=0x0c0605a4u; return 0; }
r[2]=read(ram,r[4]+40,4);
goto P_0c0605a6;
P_0c0605a6: /* original e048, guest PC 0x0c0605a6 */
if(!s->budget--) { s->failed_pc=0x0c0605a6u; return 0; }
r[0]=0x00000048u;
goto P_0c0605a8;
P_0c0605a8: /* original 4208, guest PC 0x0c0605a8 */
if(!s->budget--) { s->failed_pc=0x0c0605a8u; return 0; }
r[2]<<=2;
goto P_0c0605aa;
P_0c0605aa: /* original 4208, guest PC 0x0c0605aa */
if(!s->budget--) { s->failed_pc=0x0c0605aau; return 0; }
r[2]<<=2;
goto P_0c0605ac;
P_0c0605ac: /* original 4208, guest PC 0x0c0605ac */
if(!s->budget--) { s->failed_pc=0x0c0605acu; return 0; }
r[2]<<=2;
goto P_0c0605ae;
P_0c0605ae: /* original 232b, guest PC 0x0c0605ae */
if(!s->budget--) { s->failed_pc=0x0c0605aeu; return 0; }
r[3]|=r[2];
goto P_0c0605b0;
P_0c0605b0: /* original e207, guest PC 0x0c0605b0 */
if(!s->budget--) { s->failed_pc=0x0c0605b0u; return 0; }
r[2]=0x00000007u;
goto P_0c0605b2;
P_0c0605b2: /* original 412c, guest PC 0x0c0605b2 */
if(!s->budget--) { s->failed_pc=0x0c0605b2u; return 0; }
r[1]=(r[2]&0x80000000u)?((r[2]&31u)?(uint32_t)((int32_t)r[1]>>((-r[2])&31u)):((int32_t)r[1]<0?0xffffffffu:0)):r[1]<<(r[2]&31u);
goto P_0c0605b4;
P_0c0605b4: /* original 231b, guest PC 0x0c0605b4 */
if(!s->budget--) { s->failed_pc=0x0c0605b4u; return 0; }
r[3]|=r[1];
goto P_0c0605b6;
P_0c0605b6: /* original 014e, guest PC 0x0c0605b6 */
if(!s->budget--) { s->failed_pc=0x0c0605b6u; return 0; }
r[1]=read(ram,r[4]+r[0],4);
goto P_0c0605b8;
P_0c0605b8: /* original 4118, guest PC 0x0c0605b8 */
if(!s->budget--) { s->failed_pc=0x0c0605b8u; return 0; }
r[1]<<=8;
goto P_0c0605ba;
P_0c0605ba: /* original 231b, guest PC 0x0c0605ba */
if(!s->budget--) { s->failed_pc=0x0c0605bau; return 0; }
r[3]|=r[1];
goto P_0c0605bc;
P_0c0605bc: /* original e04c, guest PC 0x0c0605bc */
if(!s->budget--) { s->failed_pc=0x0c0605bcu; return 0; }
r[0]=0x0000004cu;
goto P_0c0605be;
P_0c0605be: /* original 014e, guest PC 0x0c0605be */
if(!s->budget--) { s->failed_pc=0x0c0605beu; return 0; }
r[1]=read(ram,r[4]+r[0],4);
goto P_0c0605c0;
P_0c0605c0: /* original 4118, guest PC 0x0c0605c0 */
if(!s->budget--) { s->failed_pc=0x0c0605c0u; return 0; }
r[1]<<=8;
goto P_0c0605c2;
P_0c0605c2: /* original 4100, guest PC 0x0c0605c2 */
if(!s->budget--) { s->failed_pc=0x0c0605c2u; return 0; }
r[17]=(r[17]&~1u)|((r[1]>>31)!=0);
r[1]<<=1;
goto P_0c0605c4;
P_0c0605c4: /* original 231b, guest PC 0x0c0605c4 */
if(!s->budget--) { s->failed_pc=0x0c0605c4u; return 0; }
r[3]|=r[1];
goto P_0c0605c6;
P_0c0605c6: /* original d144, guest PC 0x0c0605c6 */
if(!s->budget--) { s->failed_pc=0x0c0605c6u; return 0; }
r[1]=read(ram,0x0c0606d8u,4);
goto P_0c0605c8;
P_0c0605c8: /* original 2132, guest PC 0x0c0605c8 */
if(!s->budget--) { s->failed_pc=0x0c0605c8u; return 0; }
write(ram,r[1],r[3],4);
goto P_0c0605ca;
P_0c0605ca: /* original 957c, guest PC 0x0c0605ca */
if(!s->budget--) { s->failed_pc=0x0c0605cau; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0606c6u,2);
goto P_0c0605cc;
P_0c0605cc: /* original 5341, guest PC 0x0c0605cc */
if(!s->budget--) { s->failed_pc=0x0c0605ccu; return 0; }
r[3]=read(ram,r[4]+4,4);
goto P_0c0605ce;
P_0c0605ce: /* original 2359, guest PC 0x0c0605ce */
if(!s->budget--) { s->failed_pc=0x0c0605ceu; return 0; }
r[3]&=r[5];
goto P_0c0605d0;
P_0c0605d0: /* original 6242, guest PC 0x0c0605d0 */
if(!s->budget--) { s->failed_pc=0x0c0605d0u; return 0; }
tmp=read(ram,r[4],4);
r[2]=tmp;
goto P_0c0605d2;
P_0c0605d2: /* original 2259, guest PC 0x0c0605d2 */
if(!s->budget--) { s->failed_pc=0x0c0605d2u; return 0; }
r[2]&=r[5];
goto P_0c0605d4;
P_0c0605d4: /* original 4228, guest PC 0x0c0605d4 */
if(!s->budget--) { s->failed_pc=0x0c0605d4u; return 0; }
r[2]<<=16;
goto P_0c0605d6;
P_0c0605d6: /* original 232b, guest PC 0x0c0605d6 */
if(!s->budget--) { s->failed_pc=0x0c0605d6u; return 0; }
r[3]|=r[2];
goto P_0c0605d8;
P_0c0605d8: /* original d240, guest PC 0x0c0605d8 */
if(!s->budget--) { s->failed_pc=0x0c0605d8u; return 0; }
r[2]=read(ram,0x0c0606dcu,4);
goto P_0c0605da;
P_0c0605da: /* original 2232, guest PC 0x0c0605da */
if(!s->budget--) { s->failed_pc=0x0c0605dau; return 0; }
write(ram,r[2],r[3],4);
goto P_0c0605dc;
P_0c0605dc: /* original 5141, guest PC 0x0c0605dc */
if(!s->budget--) { s->failed_pc=0x0c0605dcu; return 0; }
r[1]=read(ram,r[4]+4,4);
goto P_0c0605de;
P_0c0605de: /* original 2159, guest PC 0x0c0605de */
if(!s->budget--) { s->failed_pc=0x0c0605deu; return 0; }
r[1]&=r[5];
goto P_0c0605e0;
P_0c0605e0: /* original d33f, guest PC 0x0c0605e0 */
if(!s->budget--) { s->failed_pc=0x0c0605e0u; return 0; }
r[3]=read(ram,0x0c0606e0u,4);
goto P_0c0605e2;
P_0c0605e2: /* original 4128, guest PC 0x0c0605e2 */
if(!s->budget--) { s->failed_pc=0x0c0605e2u; return 0; }
r[1]<<=16;
goto P_0c0605e4;
P_0c0605e4: /* original 2312, guest PC 0x0c0605e4 */
if(!s->budget--) { s->failed_pc=0x0c0605e4u; return 0; }
write(ram,r[3],r[1],4);
goto P_0c0605e6;
P_0c0605e6: /* original 5042, guest PC 0x0c0605e6 */
if(!s->budget--) { s->failed_pc=0x0c0605e6u; return 0; }
r[0]=read(ram,r[4]+8,4);
goto P_0c0605e8;
P_0c0605e8: /* original 5145, guest PC 0x0c0605e8 */
if(!s->budget--) { s->failed_pc=0x0c0605e8u; return 0; }
r[1]=read(ram,r[4]+20,4);
goto P_0c0605ea;
P_0c0605ea: /* original 2059, guest PC 0x0c0605ea */
if(!s->budget--) { s->failed_pc=0x0c0605eau; return 0; }
r[0]&=r[5];
goto P_0c0605ec;
P_0c0605ec: /* original 2159, guest PC 0x0c0605ec */
if(!s->budget--) { s->failed_pc=0x0c0605ecu; return 0; }
r[1]&=r[5];
goto P_0c0605ee;
P_0c0605ee: /* original 4128, guest PC 0x0c0605ee */
if(!s->budget--) { s->failed_pc=0x0c0605eeu; return 0; }
r[1]<<=16;
goto P_0c0605f0;
P_0c0605f0: /* original 201b, guest PC 0x0c0605f0 */
if(!s->budget--) { s->failed_pc=0x0c0605f0u; return 0; }
r[0]|=r[1];
goto P_0c0605f2;
P_0c0605f2: /* original d13c, guest PC 0x0c0605f2 */
if(!s->budget--) { s->failed_pc=0x0c0605f2u; return 0; }
r[1]=read(ram,0x0c0606e4u,4);
goto P_0c0605f4;
P_0c0605f4: /* original 2102, guest PC 0x0c0605f4 */
if(!s->budget--) { s->failed_pc=0x0c0605f4u; return 0; }
write(ram,r[1],r[0],4);
goto P_0c0605f6;
P_0c0605f6: /* original 5244, guest PC 0x0c0605f6 */
if(!s->budget--) { s->failed_pc=0x0c0605f6u; return 0; }
r[2]=read(ram,r[4]+16,4);
goto P_0c0605f8;
P_0c0605f8: /* original 5043, guest PC 0x0c0605f8 */
if(!s->budget--) { s->failed_pc=0x0c0605f8u; return 0; }
r[0]=read(ram,r[4]+12,4);
goto P_0c0605fa;
P_0c0605fa: /* original 2259, guest PC 0x0c0605fa */
if(!s->budget--) { s->failed_pc=0x0c0605fau; return 0; }
r[2]&=r[5];
goto P_0c0605fc;
P_0c0605fc: /* original 2059, guest PC 0x0c0605fc */
if(!s->budget--) { s->failed_pc=0x0c0605fcu; return 0; }
r[0]&=r[5];
goto P_0c0605fe;
P_0c0605fe: /* original 4028, guest PC 0x0c0605fe */
if(!s->budget--) { s->failed_pc=0x0c0605feu; return 0; }
r[0]<<=16;
goto P_0c060600;
P_0c060600: /* original 220b, guest PC 0x0c060600 */
if(!s->budget--) { s->failed_pc=0x0c060600u; return 0; }
r[2]|=r[0];
goto P_0c060602;
P_0c060602: /* original d039, guest PC 0x0c060602 */
if(!s->budget--) { s->failed_pc=0x0c060602u; return 0; }
r[0]=read(ram,0x0c0606e8u,4);
goto P_0c060604;
P_0c060604: /* original 2022, guest PC 0x0c060604 */
if(!s->budget--) { s->failed_pc=0x0c060604u; return 0; }
write(ram,r[0],r[2],4);
goto P_0c060606;
P_0c060606: /* original e074, guest PC 0x0c060606 */
if(!s->budget--) { s->failed_pc=0x0c060606u; return 0; }
r[0]=0x00000074u;
goto P_0c060608;
P_0c060608: /* original 034e, guest PC 0x0c060608 */
if(!s->budget--) { s->failed_pc=0x0c060608u; return 0; }
r[3]=read(ram,r[4]+r[0],4);
goto P_0c06060a;
P_0c06060a: /* original 2359, guest PC 0x0c06060a */
if(!s->budget--) { s->failed_pc=0x0c06060au; return 0; }
r[3]&=r[5];
goto P_0c06060c;
P_0c06060c: /* original e078, guest PC 0x0c06060c */
if(!s->budget--) { s->failed_pc=0x0c06060cu; return 0; }
r[0]=0x00000078u;
goto P_0c06060e;
P_0c06060e: /* original 024e, guest PC 0x0c06060e */
if(!s->budget--) { s->failed_pc=0x0c06060eu; return 0; }
r[2]=read(ram,r[4]+r[0],4);
goto P_0c060610;
P_0c060610: /* original 2259, guest PC 0x0c060610 */
if(!s->budget--) { s->failed_pc=0x0c060610u; return 0; }
r[2]&=r[5];
goto P_0c060612;
P_0c060612: /* original 4228, guest PC 0x0c060612 */
if(!s->budget--) { s->failed_pc=0x0c060612u; return 0; }
r[2]<<=16;
goto P_0c060614;
P_0c060614: /* original 232b, guest PC 0x0c060614 */
if(!s->budget--) { s->failed_pc=0x0c060614u; return 0; }
r[3]|=r[2];
goto P_0c060616;
P_0c060616: /* original d235, guest PC 0x0c060616 */
if(!s->budget--) { s->failed_pc=0x0c060616u; return 0; }
r[2]=read(ram,0x0c0606ecu,4);
goto P_0c060618;
P_0c060618: /* original 2232, guest PC 0x0c060618 */
if(!s->budget--) { s->failed_pc=0x0c060618u; return 0; }
write(ram,r[2],r[3],4);
goto P_0c06061a;
P_0c06061a: /* original e67f, guest PC 0x0c06061a */
if(!s->budget--) { s->failed_pc=0x0c06061au; return 0; }
r[6]=0x0000007fu;
goto P_0c06061c;
P_0c06061c: /* original 9d54, guest PC 0x0c06061c */
if(!s->budget--) { s->failed_pc=0x0c06061cu; return 0; }
r[13]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0606c8u,2);
goto P_0c06061e;
P_0c06061e: /* original e216, guest PC 0x0c06061e */
if(!s->budget--) { s->failed_pc=0x0c06061eu; return 0; }
r[2]=0x00000016u;
goto P_0c060620;
P_0c060620: /* original 5346, guest PC 0x0c060620 */
if(!s->budget--) { s->failed_pc=0x0c060620u; return 0; }
r[3]=read(ram,r[4]+24,4);
goto P_0c060622;
P_0c060622: /* original e50f, guest PC 0x0c060622 */
if(!s->budget--) { s->failed_pc=0x0c060622u; return 0; }
r[5]=0x0000000fu;
goto P_0c060624;
P_0c060624: /* original 5147, guest PC 0x0c060624 */
if(!s->budget--) { s->failed_pc=0x0c060624u; return 0; }
r[1]=read(ram,r[4]+28,4);
goto P_0c060626;
P_0c060626: /* original 2369, guest PC 0x0c060626 */
if(!s->budget--) { s->failed_pc=0x0c060626u; return 0; }
r[3]&=r[6];
goto P_0c060628;
P_0c060628: /* original 2159, guest PC 0x0c060628 */
if(!s->budget--) { s->failed_pc=0x0c060628u; return 0; }
r[1]&=r[5];
goto P_0c06062a;
P_0c06062a: /* original 4118, guest PC 0x0c06062a */
if(!s->budget--) { s->failed_pc=0x0c06062au; return 0; }
r[1]<<=8;
goto P_0c06062c;
P_0c06062c: /* original 231b, guest PC 0x0c06062c */
if(!s->budget--) { s->failed_pc=0x0c06062cu; return 0; }
r[3]|=r[1];
goto P_0c06062e;
P_0c06062e: /* original 5148, guest PC 0x0c06062e */
if(!s->budget--) { s->failed_pc=0x0c06062eu; return 0; }
r[1]=read(ram,r[4]+32,4);
goto P_0c060630;
P_0c060630: /* original 21d9, guest PC 0x0c060630 */
if(!s->budget--) { s->failed_pc=0x0c060630u; return 0; }
r[1]&=r[13];
goto P_0c060632;
P_0c060632: /* original 4118, guest PC 0x0c060632 */
if(!s->budget--) { s->failed_pc=0x0c060632u; return 0; }
r[1]<<=8;
goto P_0c060634;
P_0c060634: /* original 4108, guest PC 0x0c060634 */
if(!s->budget--) { s->failed_pc=0x0c060634u; return 0; }
r[1]<<=2;
goto P_0c060636;
P_0c060636: /* original 4108, guest PC 0x0c060636 */
if(!s->budget--) { s->failed_pc=0x0c060636u; return 0; }
r[1]<<=2;
goto P_0c060638;
P_0c060638: /* original 231b, guest PC 0x0c060638 */
if(!s->budget--) { s->failed_pc=0x0c060638u; return 0; }
r[3]|=r[1];
goto P_0c06063a;
P_0c06063a: /* original 5149, guest PC 0x0c06063a */
if(!s->budget--) { s->failed_pc=0x0c06063au; return 0; }
r[1]=read(ram,r[4]+36,4);
goto P_0c06063c;
P_0c06063c: /* original 2169, guest PC 0x0c06063c */
if(!s->budget--) { s->failed_pc=0x0c06063cu; return 0; }
r[1]&=r[6];
goto P_0c06063e;
P_0c06063e: /* original 412c, guest PC 0x0c06063e */
if(!s->budget--) { s->failed_pc=0x0c06063eu; return 0; }
r[1]=(r[2]&0x80000000u)?((r[2]&31u)?(uint32_t)((int32_t)r[1]>>((-r[2])&31u)):((int32_t)r[1]<0?0xffffffffu:0)):r[1]<<(r[2]&31u);
goto P_0c060640;
P_0c060640: /* original 231b, guest PC 0x0c060640 */
if(!s->budget--) { s->failed_pc=0x0c060640u; return 0; }
r[3]|=r[1];
goto P_0c060642;
P_0c060642: /* original d12b, guest PC 0x0c060642 */
if(!s->budget--) { s->failed_pc=0x0c060642u; return 0; }
r[1]=read(ram,0x0c0606f0u,4);
goto P_0c060644;
P_0c060644: /* original 2132, guest PC 0x0c060644 */
if(!s->budget--) { s->failed_pc=0x0c060644u; return 0; }
write(ram,r[1],r[3],4);
goto P_0c060646;
P_0c060646: /* original 504d, guest PC 0x0c060646 */
if(!s->budget--) { s->failed_pc=0x0c060646u; return 0; }
r[0]=read(ram,r[4]+52,4);
goto P_0c060648;
P_0c060648: /* original c901, guest PC 0x0c060648 */
if(!s->budget--) { s->failed_pc=0x0c060648u; return 0; }
r[0]&=1u;
goto P_0c06064a;
P_0c06064a: /* original 6303, guest PC 0x0c06064a */
if(!s->budget--) { s->failed_pc=0x0c06064au; return 0; }
r[3]=r[0];
goto P_0c06064c;
P_0c06064c: /* original d229, guest PC 0x0c06064c */
if(!s->budget--) { s->failed_pc=0x0c06064cu; return 0; }
r[2]=read(ram,0x0c0606f4u,4);
goto P_0c06064e;
P_0c06064e: /* original 504e, guest PC 0x0c06064e */
if(!s->budget--) { s->failed_pc=0x0c06064eu; return 0; }
r[0]=read(ram,r[4]+56,4);
goto P_0c060650;
P_0c060650: /* original c901, guest PC 0x0c060650 */
if(!s->budget--) { s->failed_pc=0x0c060650u; return 0; }
r[0]&=1u;
goto P_0c060652;
P_0c060652: /* original 4000, guest PC 0x0c060652 */
if(!s->budget--) { s->failed_pc=0x0c060652u; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c060654;
P_0c060654: /* original 230b, guest PC 0x0c060654 */
if(!s->budget--) { s->failed_pc=0x0c060654u; return 0; }
r[3]|=r[0];
goto P_0c060656;
P_0c060656: /* original 504f, guest PC 0x0c060656 */
if(!s->budget--) { s->failed_pc=0x0c060656u; return 0; }
r[0]=read(ram,r[4]+60,4);
goto P_0c060658;
P_0c060658: /* original c901, guest PC 0x0c060658 */
if(!s->budget--) { s->failed_pc=0x0c060658u; return 0; }
r[0]&=1u;
goto P_0c06065a;
P_0c06065a: /* original 4008, guest PC 0x0c06065a */
if(!s->budget--) { s->failed_pc=0x0c06065au; return 0; }
r[0]<<=2;
goto P_0c06065c;
P_0c06065c: /* original 230b, guest PC 0x0c06065c */
if(!s->budget--) { s->failed_pc=0x0c06065cu; return 0; }
r[3]|=r[0];
goto P_0c06065e;
P_0c06065e: /* original e040, guest PC 0x0c06065e */
if(!s->budget--) { s->failed_pc=0x0c06065eu; return 0; }
r[0]=0x00000040u;
goto P_0c060660;
P_0c060660: /* original 004e, guest PC 0x0c060660 */
if(!s->budget--) { s->failed_pc=0x0c060660u; return 0; }
r[0]=read(ram,r[4]+r[0],4);
goto P_0c060662;
P_0c060662: /* original c901, guest PC 0x0c060662 */
if(!s->budget--) { s->failed_pc=0x0c060662u; return 0; }
r[0]&=1u;
goto P_0c060664;
P_0c060664: /* original 4008, guest PC 0x0c060664 */
if(!s->budget--) { s->failed_pc=0x0c060664u; return 0; }
r[0]<<=2;
goto P_0c060666;
P_0c060666: /* original 4000, guest PC 0x0c060666 */
if(!s->budget--) { s->failed_pc=0x0c060666u; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c060668;
P_0c060668: /* original 230b, guest PC 0x0c060668 */
if(!s->budget--) { s->failed_pc=0x0c060668u; return 0; }
r[3]|=r[0];
goto P_0c06066a;
P_0c06066a: /* original e044, guest PC 0x0c06066a */
if(!s->budget--) { s->failed_pc=0x0c06066au; return 0; }
r[0]=0x00000044u;
goto P_0c06066c;
P_0c06066c: /* original 004e, guest PC 0x0c06066c */
if(!s->budget--) { s->failed_pc=0x0c06066cu; return 0; }
r[0]=read(ram,r[4]+r[0],4);
goto P_0c06066e;
P_0c06066e: /* original 2509, guest PC 0x0c06066e */
if(!s->budget--) { s->failed_pc=0x0c06066eu; return 0; }
r[5]&=r[0];
goto P_0c060670;
P_0c060670: /* original 4508, guest PC 0x0c060670 */
if(!s->budget--) { s->failed_pc=0x0c060670u; return 0; }
r[5]<<=2;
goto P_0c060672;
P_0c060672: /* original 4508, guest PC 0x0c060672 */
if(!s->budget--) { s->failed_pc=0x0c060672u; return 0; }
r[5]<<=2;
goto P_0c060674;
P_0c060674: /* original 235b, guest PC 0x0c060674 */
if(!s->budget--) { s->failed_pc=0x0c060674u; return 0; }
r[3]|=r[5];
goto P_0c060676;
P_0c060676: /* original e06c, guest PC 0x0c060676 */
if(!s->budget--) { s->failed_pc=0x0c060676u; return 0; }
r[0]=0x0000006cu;
goto P_0c060678;
P_0c060678: /* original 004e, guest PC 0x0c060678 */
if(!s->budget--) { s->failed_pc=0x0c060678u; return 0; }
r[0]=read(ram,r[4]+r[0],4);
goto P_0c06067a;
P_0c06067a: /* original c901, guest PC 0x0c06067a */
if(!s->budget--) { s->failed_pc=0x0c06067au; return 0; }
r[0]&=1u;
goto P_0c06067c;
P_0c06067c: /* original 4018, guest PC 0x0c06067c */
if(!s->budget--) { s->failed_pc=0x0c06067cu; return 0; }
r[0]<<=8;
goto P_0c06067e;
P_0c06067e: /* original 230b, guest PC 0x0c06067e */
if(!s->budget--) { s->failed_pc=0x0c06067eu; return 0; }
r[3]|=r[0];
goto P_0c060680;
P_0c060680: /* original e070, guest PC 0x0c060680 */
if(!s->budget--) { s->failed_pc=0x0c060680u; return 0; }
r[0]=0x00000070u;
goto P_0c060682;
P_0c060682: /* original 004e, guest PC 0x0c060682 */
if(!s->budget--) { s->failed_pc=0x0c060682u; return 0; }
r[0]=read(ram,r[4]+r[0],4);
goto P_0c060684;
P_0c060684: /* original c93f, guest PC 0x0c060684 */
if(!s->budget--) { s->failed_pc=0x0c060684u; return 0; }
r[0]&=63u;
goto P_0c060686;
P_0c060686: /* original 4028, guest PC 0x0c060686 */
if(!s->budget--) { s->failed_pc=0x0c060686u; return 0; }
r[0]<<=16;
goto P_0c060688;
P_0c060688: /* original 230b, guest PC 0x0c060688 */
if(!s->budget--) { s->failed_pc=0x0c060688u; return 0; }
r[3]|=r[0];
goto P_0c06068a;
P_0c06068a: /* original 2232, guest PC 0x0c06068a */
if(!s->budget--) { s->failed_pc=0x0c06068au; return 0; }
write(ram,r[2],r[3],4);
goto P_0c06068c;
P_0c06068c: /* original d01a, guest PC 0x0c06068c */
if(!s->budget--) { s->failed_pc=0x0c06068cu; return 0; }
r[0]=read(ram,0x0c0606f8u,4);
goto P_0c06068e;
P_0c06068e: /* original 6302, guest PC 0x0c06068e */
if(!s->budget--) { s->failed_pc=0x0c06068eu; return 0; }
tmp=read(ram,r[0],4);
r[3]=tmp;
goto P_0c060690;
P_0c060690: /* original d10e, guest PC 0x0c060690 */
if(!s->budget--) { s->failed_pc=0x0c060690u; return 0; }
r[1]=read(ram,0x0c0606ccu,4);
goto P_0c060692;
P_0c060692: /* original 6012, guest PC 0x0c060692 */
if(!s->budget--) { s->failed_pc=0x0c060692u; return 0; }
tmp=read(ram,r[1],4);
r[0]=tmp;
goto P_0c060694;
P_0c060694: /* original 303c, guest PC 0x0c060694 */
if(!s->budget--) { s->failed_pc=0x0c060694u; return 0; }
r[0]+=r[3];
goto P_0c060696;
P_0c060696: /* original d319, guest PC 0x0c060696 */
if(!s->budget--) { s->failed_pc=0x0c060696u; return 0; }
r[3]=read(ram,0x0c0606fcu,4);
goto P_0c060698;
P_0c060698: /* original 2302, guest PC 0x0c060698 */
if(!s->budget--) { s->failed_pc=0x0c060698u; return 0; }
write(ram,r[3],r[0],4);
goto P_0c06069a;
P_0c06069a: /* original d019, guest PC 0x0c06069a */
if(!s->budget--) { s->failed_pc=0x0c06069au; return 0; }
r[0]=read(ram,0x0c060700u,4);
goto P_0c06069c;
P_0c06069c: /* original 6202, guest PC 0x0c06069c */
if(!s->budget--) { s->failed_pc=0x0c06069cu; return 0; }
tmp=read(ram,r[0],4);
r[2]=tmp;
goto P_0c06069e;
P_0c06069e: /* original d30c, guest PC 0x0c06069e */
if(!s->budget--) { s->failed_pc=0x0c06069eu; return 0; }
r[3]=read(ram,0x0c0606d0u,4);
goto P_0c0606a0;
P_0c0606a0: /* original 6032, guest PC 0x0c0606a0 */
if(!s->budget--) { s->failed_pc=0x0c0606a0u; return 0; }
tmp=read(ram,r[3],4);
r[0]=tmp;
goto P_0c0606a2;
P_0c0606a2: /* original 302c, guest PC 0x0c0606a2 */
if(!s->budget--) { s->failed_pc=0x0c0606a2u; return 0; }
r[0]+=r[2];
goto P_0c0606a4;
P_0c0606a4: /* original 71fc, guest PC 0x0c0606a4 */
if(!s->budget--) { s->failed_pc=0x0c0606a4u; return 0; }
r[1]+=0xfffffffcu;
goto P_0c0606a6;
P_0c0606a6: /* original 6212, guest PC 0x0c0606a6 */
if(!s->budget--) { s->failed_pc=0x0c0606a6u; return 0; }
tmp=read(ram,r[1],4);
r[2]=tmp;
goto P_0c0606a8;
P_0c0606a8: /* original 5131, guest PC 0x0c0606a8 */
if(!s->budget--) { s->failed_pc=0x0c0606a8u; return 0; }
r[1]=read(ram,r[3]+4,4);
goto P_0c0606aa;
P_0c0606aa: /* original 312c, guest PC 0x0c0606aa */
if(!s->budget--) { s->failed_pc=0x0c0606aau; return 0; }
r[1]+=r[2];
goto P_0c0606ac;
P_0c0606ac: /* original d215, guest PC 0x0c0606ac */
if(!s->budget--) { s->failed_pc=0x0c0606acu; return 0; }
r[2]=read(ram,0x0c060704u,4);
goto P_0c0606ae;
P_0c0606ae: /* original 4128, guest PC 0x0c0606ae */
if(!s->budget--) { s->failed_pc=0x0c0606aeu; return 0; }
r[1]<<=16;
goto P_0c0606b0;
P_0c0606b0: /* original 201b, guest PC 0x0c0606b0 */
if(!s->budget--) { s->failed_pc=0x0c0606b0u; return 0; }
r[0]|=r[1];
goto P_0c0606b2;
P_0c0606b2: /* original 2202, guest PC 0x0c0606b2 */
if(!s->budget--) { s->failed_pc=0x0c0606b2u; return 0; }
write(ram,r[2],r[0],4);
goto P_0c0606b4;
P_0c0606b4: /* original d114, guest PC 0x0c0606b4 */
if(!s->budget--) { s->failed_pc=0x0c0606b4u; return 0; }
r[1]=read(ram,0x0c060708u,4);
goto P_0c0606b6;
P_0c0606b6: /* original 6012, guest PC 0x0c0606b6 */
if(!s->budget--) { s->failed_pc=0x0c0606b6u; return 0; }
tmp=read(ram,r[1],4);
r[0]=tmp;
goto P_0c0606b8;
P_0c0606b8: /* original c802, guest PC 0x0c0606b8 */
if(!s->budget--) { s->failed_pc=0x0c0606b8u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&2u)==0)!=0);
goto P_0c0606ba;
P_0c0606ba: /* original 8931, guest PC 0x0c0606ba */
if(!s->budget--) { s->failed_pc=0x0c0606bau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c060720; }
goto P_0c0606bc;
P_0c0606bc: /* original dc13, guest PC 0x0c0606bc */
if(!s->budget--) { s->failed_pc=0x0c0606bcu; return 0; }
r[12]=read(ram,0x0c06070cu,4);
goto P_0c0606be;
P_0c0606be: /* original 9e04, guest PC 0x0c0606be */
if(!s->budget--) { s->failed_pc=0x0c0606beu; return 0; }
r[14]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0606cau,2);
goto P_0c0606c0;
P_0c0606c0: /* original a026, guest PC 0x0c0606c0 */
if(!s->budget--) { s->failed_pc=0x0c0606c0u; return 0; }
r[4]=r[14];
goto P_0c060710;
P_0c0606c2: /* original 64e3, guest PC 0x0c0606c2 */
if(!s->budget--) { s->failed_pc=0x0c0606c2u; return 0; }
r[4]=r[14];
return vf3_matrix_family(0x0c0606c4u,s,ram);
P_0c060710: /* original 4c0b, guest PC 0x0c060710 */
if(!s->budget--) { s->failed_pc=0x0c060710u; return 0; }
target=r[12];
r[16]=0x0c060714u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c060714u) { target=s->pc; goto dispatch; }
goto P_0c060714;
P_0c060712: /* original 0009, guest PC 0x0c060712 */
if(!s->budget--) { s->failed_pc=0x0c060712u; return 0; }
goto P_0c060714;
P_0c060714: /* original 20d8, guest PC 0x0c060714 */
if(!s->budget--) { s->failed_pc=0x0c060714u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[13])==0)!=0);
goto P_0c060716;
P_0c060716: /* original 89d3, guest PC 0x0c060716 */
if(!s->budget--) { s->failed_pc=0x0c060716u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0606c0; }
goto P_0c060718;
P_0c060718: /* original 4c0b, guest PC 0x0c060718 */
if(!s->budget--) { s->failed_pc=0x0c060718u; return 0; }
target=r[12];
r[16]=0x0c06071cu;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c06071cu) { target=s->pc; goto dispatch; }
goto P_0c06071c;
P_0c06071a: /* original 64e3, guest PC 0x0c06071a */
if(!s->budget--) { s->failed_pc=0x0c06071au; return 0; }
r[4]=r[14];
goto P_0c06071c;
P_0c06071c: /* original 20d8, guest PC 0x0c06071c */
if(!s->budget--) { s->failed_pc=0x0c06071cu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[13])==0)!=0);
goto P_0c06071e;
P_0c06071e: /* original 8bfb, guest PC 0x0c06071e */
if(!s->budget--) { s->failed_pc=0x0c06071eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c060718; }
goto P_0c060720;
P_0c060720: /* original de44, guest PC 0x0c060720 */
if(!s->budget--) { s->failed_pc=0x0c060720u; return 0; }
r[14]=read(ram,0x0c060834u,4);
goto P_0c060722;
P_0c060722: /* original d245, guest PC 0x0c060722 */
if(!s->budget--) { s->failed_pc=0x0c060722u; return 0; }
r[2]=read(ram,0x0c060838u,4);
goto P_0c060724;
P_0c060724: /* original 6022, guest PC 0x0c060724 */
if(!s->budget--) { s->failed_pc=0x0c060724u; return 0; }
tmp=read(ram,r[2],4);
r[0]=tmp;
goto P_0c060726;
P_0c060726: /* original cb08, guest PC 0x0c060726 */
if(!s->budget--) { s->failed_pc=0x0c060726u; return 0; }
r[0]|=8u;
goto P_0c060728;
P_0c060728: /* original 9470, guest PC 0x0c060728 */
if(!s->budget--) { s->failed_pc=0x0c060728u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06080cu,2);
goto P_0c06072a;
P_0c06072a: /* original 4e0b, guest PC 0x0c06072a */
if(!s->budget--) { s->failed_pc=0x0c06072au; return 0; }
target=r[14];
r[16]=0x0c06072eu;
r[5]=r[0];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c06072eu) { target=s->pc; goto dispatch; }
goto P_0c06072e;
P_0c06072c: /* original 6503, guest PC 0x0c06072c */
if(!s->budget--) { s->failed_pc=0x0c06072cu; return 0; }
r[5]=r[0];
goto P_0c06072e;
P_0c06072e: /* original d343, guest PC 0x0c06072e */
if(!s->budget--) { s->failed_pc=0x0c06072eu; return 0; }
r[3]=read(ram,0x0c06083cu,4);
goto P_0c060730;
P_0c060730: /* original 6032, guest PC 0x0c060730 */
if(!s->budget--) { s->failed_pc=0x0c060730u; return 0; }
tmp=read(ram,r[3],4);
r[0]=tmp;
goto P_0c060732;
P_0c060732: /* original c801, guest PC 0x0c060732 */
if(!s->budget--) { s->failed_pc=0x0c060732u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&1u)==0)!=0);
goto P_0c060734;
P_0c060734: /* original 8d03, guest PC 0x0c060734 */
if(!s->budget--) { s->failed_pc=0x0c060734u; return 0; }
cond=r[17]&1u;
r[4]=0x00000044u;
if(cond) { goto P_0c06073e; }
goto P_0c060738;
P_0c060736: /* original e444, guest PC 0x0c060736 */
if(!s->budget--) { s->failed_pc=0x0c060736u; return 0; }
r[4]=0x00000044u;
goto P_0c060738;
P_0c060738: /* original d541, guest PC 0x0c060738 */
if(!s->budget--) { s->failed_pc=0x0c060738u; return 0; }
r[5]=read(ram,0x0c060840u,4);
goto P_0c06073a;
P_0c06073a: /* original a001, guest PC 0x0c06073a */
if(!s->budget--) { s->failed_pc=0x0c06073au; return 0; }
goto P_0c060740;
P_0c06073c: /* original 0009, guest PC 0x0c06073c */
if(!s->budget--) { s->failed_pc=0x0c06073cu; return 0; }
goto P_0c06073e;
P_0c06073e: /* original e500, guest PC 0x0c06073e */
if(!s->budget--) { s->failed_pc=0x0c06073eu; return 0; }
r[5]=0x00000000u;
goto P_0c060740;
P_0c060740: /* original 4e0b, guest PC 0x0c060740 */
if(!s->budget--) { s->failed_pc=0x0c060740u; return 0; }
target=r[14];
r[16]=0x0c060744u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c060744u) { target=s->pc; goto dispatch; }
goto P_0c060744;
P_0c060742: /* original 0009, guest PC 0x0c060742 */
if(!s->budget--) { s->failed_pc=0x0c060742u; return 0; }
goto P_0c060744;
P_0c060744: /* original e500, guest PC 0x0c060744 */
if(!s->budget--) { s->failed_pc=0x0c060744u; return 0; }
r[5]=0x00000000u;
goto P_0c060746;
P_0c060746: /* original 4e0b, guest PC 0x0c060746 */
if(!s->budget--) { s->failed_pc=0x0c060746u; return 0; }
target=r[14];
r[16]=0x0c06074au;
r[4]=0x0000005cu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c06074au) { target=s->pc; goto dispatch; }
goto P_0c06074a;
P_0c060748: /* original e45c, guest PC 0x0c060748 */
if(!s->budget--) { s->failed_pc=0x0c060748u; return 0; }
r[4]=0x0000005cu;
goto P_0c06074a;
P_0c06074a: /* original d23e, guest PC 0x0c06074a */
if(!s->budget--) { s->failed_pc=0x0c06074au; return 0; }
r[2]=read(ram,0x0c060844u,4);
goto P_0c06074c;
P_0c06074c: /* original 945f, guest PC 0x0c06074c */
if(!s->budget--) { s->failed_pc=0x0c06074cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06080eu,2);
goto P_0c06074e;
P_0c06074e: /* original 4e0b, guest PC 0x0c06074e */
if(!s->budget--) { s->failed_pc=0x0c06074eu; return 0; }
target=r[14];
r[16]=0x0c060752u;
tmp=read(ram,r[2],4);
r[5]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c060752u) { target=s->pc; goto dispatch; }
goto P_0c060752;
P_0c060750: /* original 6522, guest PC 0x0c060750 */
if(!s->budget--) { s->failed_pc=0x0c060750u; return 0; }
tmp=read(ram,r[2],4);
r[5]=tmp;
goto P_0c060752;
P_0c060752: /* original d33d, guest PC 0x0c060752 */
if(!s->budget--) { s->failed_pc=0x0c060752u; return 0; }
r[3]=read(ram,0x0c060848u,4);
goto P_0c060754;
P_0c060754: /* original 945c, guest PC 0x0c060754 */
if(!s->budget--) { s->failed_pc=0x0c060754u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c060810u,2);
goto P_0c060756;
P_0c060756: /* original 4e0b, guest PC 0x0c060756 */
if(!s->budget--) { s->failed_pc=0x0c060756u; return 0; }
target=r[14];
r[16]=0x0c06075au;
tmp=read(ram,r[3],4);
r[5]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c06075au) { target=s->pc; goto dispatch; }
goto P_0c06075a;
P_0c060758: /* original 6532, guest PC 0x0c060758 */
if(!s->budget--) { s->failed_pc=0x0c060758u; return 0; }
tmp=read(ram,r[3],4);
r[5]=tmp;
goto P_0c06075a;
P_0c06075a: /* original d23c, guest PC 0x0c06075a */
if(!s->budget--) { s->failed_pc=0x0c06075au; return 0; }
r[2]=read(ram,0x0c06084cu,4);
goto P_0c06075c;
P_0c06075c: /* original 9459, guest PC 0x0c06075c */
if(!s->budget--) { s->failed_pc=0x0c06075cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c060812u,2);
goto P_0c06075e;
P_0c06075e: /* original 4e0b, guest PC 0x0c06075e */
if(!s->budget--) { s->failed_pc=0x0c06075eu; return 0; }
target=r[14];
r[16]=0x0c060762u;
tmp=read(ram,r[2],4);
r[5]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c060762u) { target=s->pc; goto dispatch; }
goto P_0c060762;
P_0c060760: /* original 6522, guest PC 0x0c060760 */
if(!s->budget--) { s->failed_pc=0x0c060760u; return 0; }
tmp=read(ram,r[2],4);
r[5]=tmp;
goto P_0c060762;
P_0c060762: /* original d33b, guest PC 0x0c060762 */
if(!s->budget--) { s->failed_pc=0x0c060762u; return 0; }
r[3]=read(ram,0x0c060850u,4);
goto P_0c060764;
P_0c060764: /* original 9456, guest PC 0x0c060764 */
if(!s->budget--) { s->failed_pc=0x0c060764u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c060814u,2);
goto P_0c060766;
P_0c060766: /* original 4e0b, guest PC 0x0c060766 */
if(!s->budget--) { s->failed_pc=0x0c060766u; return 0; }
target=r[14];
r[16]=0x0c06076au;
tmp=read(ram,r[3],4);
r[5]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c06076au) { target=s->pc; goto dispatch; }
goto P_0c06076a;
P_0c060768: /* original 6532, guest PC 0x0c060768 */
if(!s->budget--) { s->failed_pc=0x0c060768u; return 0; }
tmp=read(ram,r[3],4);
r[5]=tmp;
goto P_0c06076a;
P_0c06076a: /* original d23a, guest PC 0x0c06076a */
if(!s->budget--) { s->failed_pc=0x0c06076au; return 0; }
r[2]=read(ram,0x0c060854u,4);
goto P_0c06076c;
P_0c06076c: /* original 9453, guest PC 0x0c06076c */
if(!s->budget--) { s->failed_pc=0x0c06076cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c060816u,2);
goto P_0c06076e;
P_0c06076e: /* original 4e0b, guest PC 0x0c06076e */
if(!s->budget--) { s->failed_pc=0x0c06076eu; return 0; }
target=r[14];
r[16]=0x0c060772u;
tmp=read(ram,r[2],4);
r[5]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c060772u) { target=s->pc; goto dispatch; }
goto P_0c060772;
P_0c060770: /* original 6522, guest PC 0x0c060770 */
if(!s->budget--) { s->failed_pc=0x0c060770u; return 0; }
tmp=read(ram,r[2],4);
r[5]=tmp;
goto P_0c060772;
P_0c060772: /* original d339, guest PC 0x0c060772 */
if(!s->budget--) { s->failed_pc=0x0c060772u; return 0; }
r[3]=read(ram,0x0c060858u,4);
goto P_0c060774;
P_0c060774: /* original 9450, guest PC 0x0c060774 */
if(!s->budget--) { s->failed_pc=0x0c060774u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c060818u,2);
goto P_0c060776;
P_0c060776: /* original 4e0b, guest PC 0x0c060776 */
if(!s->budget--) { s->failed_pc=0x0c060776u; return 0; }
target=r[14];
r[16]=0x0c06077au;
tmp=read(ram,r[3],4);
r[5]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c06077au) { target=s->pc; goto dispatch; }
goto P_0c06077a;
P_0c060778: /* original 6532, guest PC 0x0c060778 */
if(!s->budget--) { s->failed_pc=0x0c060778u; return 0; }
tmp=read(ram,r[3],4);
r[5]=tmp;
goto P_0c06077a;
P_0c06077a: /* original d238, guest PC 0x0c06077a */
if(!s->budget--) { s->failed_pc=0x0c06077au; return 0; }
r[2]=read(ram,0x0c06085cu,4);
goto P_0c06077c;
P_0c06077c: /* original 944d, guest PC 0x0c06077c */
if(!s->budget--) { s->failed_pc=0x0c06077cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06081au,2);
goto P_0c06077e;
P_0c06077e: /* original 4e0b, guest PC 0x0c06077e */
if(!s->budget--) { s->failed_pc=0x0c06077eu; return 0; }
target=r[14];
r[16]=0x0c060782u;
tmp=read(ram,r[2],4);
r[5]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c060782u) { target=s->pc; goto dispatch; }
goto P_0c060782;
P_0c060780: /* original 6522, guest PC 0x0c060780 */
if(!s->budget--) { s->failed_pc=0x0c060780u; return 0; }
tmp=read(ram,r[2],4);
r[5]=tmp;
goto P_0c060782;
P_0c060782: /* original d337, guest PC 0x0c060782 */
if(!s->budget--) { s->failed_pc=0x0c060782u; return 0; }
r[3]=read(ram,0x0c060860u,4);
goto P_0c060784;
P_0c060784: /* original 944a, guest PC 0x0c060784 */
if(!s->budget--) { s->failed_pc=0x0c060784u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06081cu,2);
goto P_0c060786;
P_0c060786: /* original 4e0b, guest PC 0x0c060786 */
if(!s->budget--) { s->failed_pc=0x0c060786u; return 0; }
target=r[14];
r[16]=0x0c06078au;
tmp=read(ram,r[3],4);
r[5]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c06078au) { target=s->pc; goto dispatch; }
goto P_0c06078a;
P_0c060788: /* original 6532, guest PC 0x0c060788 */
if(!s->budget--) { s->failed_pc=0x0c060788u; return 0; }
tmp=read(ram,r[3],4);
r[5]=tmp;
goto P_0c06078a;
P_0c06078a: /* original d236, guest PC 0x0c06078a */
if(!s->budget--) { s->failed_pc=0x0c06078au; return 0; }
r[2]=read(ram,0x0c060864u,4);
goto P_0c06078c;
P_0c06078c: /* original 9447, guest PC 0x0c06078c */
if(!s->budget--) { s->failed_pc=0x0c06078cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06081eu,2);
goto P_0c06078e;
P_0c06078e: /* original 4e0b, guest PC 0x0c06078e */
if(!s->budget--) { s->failed_pc=0x0c06078eu; return 0; }
target=r[14];
r[16]=0x0c060792u;
tmp=read(ram,r[2],4);
r[5]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c060792u) { target=s->pc; goto dispatch; }
goto P_0c060792;
P_0c060790: /* original 6522, guest PC 0x0c060790 */
if(!s->budget--) { s->failed_pc=0x0c060790u; return 0; }
tmp=read(ram,r[2],4);
r[5]=tmp;
goto P_0c060792;
P_0c060792: /* original 4f26, guest PC 0x0c060792 */
if(!s->budget--) { s->failed_pc=0x0c060792u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c060794;
P_0c060794: /* original 6cf6, guest PC 0x0c060794 */
if(!s->budget--) { s->failed_pc=0x0c060794u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c060796;
P_0c060796: /* original 6df6, guest PC 0x0c060796 */
if(!s->budget--) { s->failed_pc=0x0c060796u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c060798;
P_0c060798: /* original 000b, guest PC 0x0c060798 */
if(!s->budget--) { s->failed_pc=0x0c060798u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c06079a: /* original 6ef6, guest PC 0x0c06079a */
if(!s->budget--) { s->failed_pc=0x0c06079au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c06079cu,s,ram);
P_0c0609b8: /* original 4f22, guest PC 0x0c0609b8 */
if(!s->budget--) { s->failed_pc=0x0c0609b8u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0609ba;
P_0c0609ba: /* original 904a, guest PC 0x0c0609ba */
if(!s->budget--) { s->failed_pc=0x0c0609bau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c060a52u,2);
goto P_0c0609bc;
P_0c0609bc: /* original d22d, guest PC 0x0c0609bc */
if(!s->budget--) { s->failed_pc=0x0c0609bcu; return 0; }
r[2]=read(ram,0x0c060a74u,4);
goto P_0c0609be;
P_0c0609be: /* original 3f0c, guest PC 0x0c0609be */
if(!s->budget--) { s->failed_pc=0x0c0609beu; return 0; }
r[15]+=r[0];
goto P_0c0609c0;
P_0c0609c0: /* original 6ef3, guest PC 0x0c0609c0 */
if(!s->budget--) { s->failed_pc=0x0c0609c0u; return 0; }
r[14]=r[15];
goto P_0c0609c2;
P_0c0609c2: /* original 1e32, guest PC 0x0c0609c2 */
if(!s->budget--) { s->failed_pc=0x0c0609c2u; return 0; }
write(ram,r[14]+8,r[3],4);
goto P_0c0609c4;
P_0c0609c4: /* original 6022, guest PC 0x0c0609c4 */
if(!s->budget--) { s->failed_pc=0x0c0609c4u; return 0; }
tmp=read(ram,r[2],4);
r[0]=tmp;
goto P_0c0609c6;
P_0c0609c6: /* original 20d9, guest PC 0x0c0609c6 */
if(!s->budget--) { s->failed_pc=0x0c0609c6u; return 0; }
r[0]&=r[13];
goto P_0c0609c8;
P_0c0609c8: /* original 8801, guest PC 0x0c0609c8 */
if(!s->budget--) { s->failed_pc=0x0c0609c8u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c0609ca;
P_0c0609ca: /* original 8d09, guest PC 0x0c0609ca */
if(!s->budget--) { s->failed_pc=0x0c0609cau; return 0; }
cond=r[17]&1u;
r[12]=0x00000012u;
if(cond) { goto P_0c0609e0; }
goto P_0c0609ce;
P_0c0609cc: /* original ec12, guest PC 0x0c0609cc */
if(!s->budget--) { s->failed_pc=0x0c0609ccu; return 0; }
r[12]=0x00000012u;
goto P_0c0609ce;
P_0c0609ce: /* original d329, guest PC 0x0c0609ce */
if(!s->budget--) { s->failed_pc=0x0c0609ceu; return 0; }
r[3]=read(ram,0x0c060a74u,4);
goto P_0c0609d0;
P_0c0609d0: /* original 6032, guest PC 0x0c0609d0 */
if(!s->budget--) { s->failed_pc=0x0c0609d0u; return 0; }
tmp=read(ram,r[3],4);
r[0]=tmp;
goto P_0c0609d2;
P_0c0609d2: /* original c82c, guest PC 0x0c0609d2 */
if(!s->budget--) { s->failed_pc=0x0c0609d2u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&44u)==0)!=0);
goto P_0c0609d4;
P_0c0609d4: /* original 8904, guest PC 0x0c0609d4 */
if(!s->budget--) { s->failed_pc=0x0c0609d4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0609e0; }
goto P_0c0609d6;
P_0c0609d6: /* original 2dd8, guest PC 0x0c0609d6 */
if(!s->budget--) { s->failed_pc=0x0c0609d6u; return 0; }
r[17]=(r[17]&~1u)|(((r[13]&r[13])==0)!=0);
goto P_0c0609d8;
P_0c0609d8: /* original 8902, guest PC 0x0c0609d8 */
if(!s->budget--) { s->failed_pc=0x0c0609d8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0609e0; }
goto P_0c0609da;
P_0c0609da: /* original 923c, guest PC 0x0c0609da */
if(!s->budget--) { s->failed_pc=0x0c0609dau; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c060a56u,2);
goto P_0c0609dc;
P_0c0609dc: /* original a002, guest PC 0x0c0609dc */
if(!s->budget--) { s->failed_pc=0x0c0609dcu; return 0; }
write(ram,r[14]+20,r[2],4);
goto P_0c0609e4;
P_0c0609de: /* original 1e25, guest PC 0x0c0609de */
if(!s->budget--) { s->failed_pc=0x0c0609deu; return 0; }
write(ram,r[14]+20,r[2],4);
goto P_0c0609e0;
P_0c0609e0: /* original 913a, guest PC 0x0c0609e0 */
if(!s->budget--) { s->failed_pc=0x0c0609e0u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c060a58u,2);
goto P_0c0609e2;
P_0c0609e2: /* original 1e15, guest PC 0x0c0609e2 */
if(!s->budget--) { s->failed_pc=0x0c0609e2u; return 0; }
write(ram,r[14]+20,r[1],4);
goto P_0c0609e4;
P_0c0609e4: /* original 9239, guest PC 0x0c0609e4 */
if(!s->budget--) { s->failed_pc=0x0c0609e4u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c060a5au,2);
goto P_0c0609e6;
P_0c0609e6: /* original e37e, guest PC 0x0c0609e6 */
if(!s->budget--) { s->failed_pc=0x0c0609e6u; return 0; }
r[3]=0x0000007eu;
goto P_0c0609e8;
P_0c0609e8: /* original 9438, guest PC 0x0c0609e8 */
if(!s->budget--) { s->failed_pc=0x0c0609e8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c060a5cu,2);
goto P_0c0609ea;
P_0c0609ea: /* original 2e32, guest PC 0x0c0609ea */
if(!s->budget--) { s->failed_pc=0x0c0609eau; return 0; }
write(ram,r[14],r[3],4);
goto P_0c0609ec;
P_0c0609ec: /* original 1e21, guest PC 0x0c0609ec */
if(!s->budget--) { s->failed_pc=0x0c0609ecu; return 0; }
write(ram,r[14]+4,r[2],4);
goto P_0c0609ee;
P_0c0609ee: /* original d321, guest PC 0x0c0609ee */
if(!s->budget--) { s->failed_pc=0x0c0609eeu; return 0; }
r[3]=read(ram,0x0c060a74u,4);
goto P_0c0609f0;
P_0c0609f0: /* original 6032, guest PC 0x0c0609f0 */
if(!s->budget--) { s->failed_pc=0x0c0609f0u; return 0; }
tmp=read(ram,r[3],4);
r[0]=tmp;
goto P_0c0609f2;
P_0c0609f2: /* original 20d9, guest PC 0x0c0609f2 */
if(!s->budget--) { s->failed_pc=0x0c0609f2u; return 0; }
r[0]&=r[13];
goto P_0c0609f4;
P_0c0609f4: /* original 8801, guest PC 0x0c0609f4 */
if(!s->budget--) { s->failed_pc=0x0c0609f4u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c0609f6;
P_0c0609f6: /* original 890a, guest PC 0x0c0609f6 */
if(!s->budget--) { s->failed_pc=0x0c0609f6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c060a0e; }
goto P_0c0609f8;
P_0c0609f8: /* original d21e, guest PC 0x0c0609f8 */
if(!s->budget--) { s->failed_pc=0x0c0609f8u; return 0; }
r[2]=read(ram,0x0c060a74u,4);
goto P_0c0609fa;
P_0c0609fa: /* original 6022, guest PC 0x0c0609fa */
if(!s->budget--) { s->failed_pc=0x0c0609fau; return 0; }
tmp=read(ram,r[2],4);
r[0]=tmp;
goto P_0c0609fc;
P_0c0609fc: /* original c82c, guest PC 0x0c0609fc */
if(!s->budget--) { s->failed_pc=0x0c0609fcu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&44u)==0)!=0);
goto P_0c0609fe;
P_0c0609fe: /* original 8906, guest PC 0x0c0609fe */
if(!s->budget--) { s->failed_pc=0x0c0609feu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c060a0e; }
goto P_0c060a00;
P_0c060a00: /* original 2dd8, guest PC 0x0c060a00 */
if(!s->budget--) { s->failed_pc=0x0c060a00u; return 0; }
r[17]=(r[17]&~1u)|(((r[13]&r[13])==0)!=0);
goto P_0c060a02;
P_0c060a02: /* original 8904, guest PC 0x0c060a02 */
if(!s->budget--) { s->failed_pc=0x0c060a02u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c060a0e; }
goto P_0c060a04;
P_0c060a04: /* original 922b, guest PC 0x0c060a04 */
if(!s->budget--) { s->failed_pc=0x0c060a04u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c060a5eu,2);
goto P_0c060a06;
P_0c060a06: /* original e324, guest PC 0x0c060a06 */
if(!s->budget--) { s->failed_pc=0x0c060a06u; return 0; }
r[3]=0x00000024u;
goto P_0c060a08;
P_0c060a08: /* original 1e33, guest PC 0x0c060a08 */
if(!s->budget--) { s->failed_pc=0x0c060a08u; return 0; }
write(ram,r[14]+12,r[3],4);
goto P_0c060a0a;
P_0c060a0a: /* original a002, guest PC 0x0c060a0a */
if(!s->budget--) { s->failed_pc=0x0c060a0au; return 0; }
write(ram,r[14]+16,r[2],4);
goto P_0c060a12;
P_0c060a0c: /* original 1e24, guest PC 0x0c060a0c */
if(!s->budget--) { s->failed_pc=0x0c060a0cu; return 0; }
write(ram,r[14]+16,r[2],4);
goto P_0c060a0e;
P_0c060a0e: /* original 1ec3, guest PC 0x0c060a0e */
if(!s->budget--) { s->failed_pc=0x0c060a0eu; return 0; }
write(ram,r[14]+12,r[12],4);
goto P_0c060a10;
P_0c060a10: /* original 1e44, guest PC 0x0c060a10 */
if(!s->budget--) { s->failed_pc=0x0c060a10u; return 0; }
write(ram,r[14]+16,r[4],4);
goto P_0c060a12;
P_0c060a12: /* original e23f, guest PC 0x0c060a12 */
if(!s->budget--) { s->failed_pc=0x0c060a12u; return 0; }
r[2]=0x0000003fu;
goto P_0c060a14;
P_0c060a14: /* original d317, guest PC 0x0c060a14 */
if(!s->budget--) { s->failed_pc=0x0c060a14u; return 0; }
r[3]=read(ram,0x0c060a74u,4);
goto P_0c060a16;
P_0c060a16: /* original 1e26, guest PC 0x0c060a16 */
if(!s->budget--) { s->failed_pc=0x0c060a16u; return 0; }
write(ram,r[14]+24,r[2],4);
goto P_0c060a18;
P_0c060a18: /* original 6032, guest PC 0x0c060a18 */
if(!s->budget--) { s->failed_pc=0x0c060a18u; return 0; }
tmp=read(ram,r[3],4);
r[0]=tmp;
goto P_0c060a1a;
P_0c060a1a: /* original c820, guest PC 0x0c060a1a */
if(!s->budget--) { s->failed_pc=0x0c060a1au; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&32u)==0)!=0);
goto P_0c060a1c;
P_0c060a1c: /* original 8d04, guest PC 0x0c060a1c */
if(!s->budget--) { s->failed_pc=0x0c060a1cu; return 0; }
cond=r[17]&1u;
r[3]=0x00000015u;
if(cond) { goto P_0c060a28; }
goto P_0c060a20;
P_0c060a1e: /* original e315, guest PC 0x0c060a1e */
if(!s->budget--) { s->failed_pc=0x0c060a1eu; return 0; }
r[3]=0x00000015u;
goto P_0c060a20;
P_0c060a20: /* original 911e, guest PC 0x0c060a20 */
if(!s->budget--) { s->failed_pc=0x0c060a20u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c060a60u,2);
goto P_0c060a22;
P_0c060a22: /* original e074, guest PC 0x0c060a22 */
if(!s->budget--) { s->failed_pc=0x0c060a22u; return 0; }
r[0]=0x00000074u;
goto P_0c060a24;
P_0c060a24: /* original a002, guest PC 0x0c060a24 */
if(!s->budget--) { s->failed_pc=0x0c060a24u; return 0; }
write(ram,r[14]+r[0],r[1],4);
goto P_0c060a2c;
P_0c060a26: /* original 0e16, guest PC 0x0c060a26 */
if(!s->budget--) { s->failed_pc=0x0c060a26u; return 0; }
write(ram,r[14]+r[0],r[1],4);
goto P_0c060a28;
P_0c060a28: /* original e074, guest PC 0x0c060a28 */
if(!s->budget--) { s->failed_pc=0x0c060a28u; return 0; }
r[0]=0x00000074u;
goto P_0c060a2a;
P_0c060a2a: /* original 0e46, guest PC 0x0c060a2a */
if(!s->budget--) { s->failed_pc=0x0c060a2au; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c060a2c;
P_0c060a2c: /* original d211, guest PC 0x0c060a2c */
if(!s->budget--) { s->failed_pc=0x0c060a2cu; return 0; }
r[2]=read(ram,0x0c060a74u,4);
goto P_0c060a2e;
P_0c060a2e: /* original e078, guest PC 0x0c060a2e */
if(!s->budget--) { s->failed_pc=0x0c060a2eu; return 0; }
r[0]=0x00000078u;
goto P_0c060a30;
P_0c060a30: /* original 0e36, guest PC 0x0c060a30 */
if(!s->budget--) { s->failed_pc=0x0c060a30u; return 0; }
write(ram,r[14]+r[0],r[3],4);
goto P_0c060a32;
P_0c060a32: /* original 6022, guest PC 0x0c060a32 */
if(!s->budget--) { s->failed_pc=0x0c060a32u; return 0; }
tmp=read(ram,r[2],4);
r[0]=tmp;
goto P_0c060a34;
P_0c060a34: /* original 20d9, guest PC 0x0c060a34 */
if(!s->budget--) { s->failed_pc=0x0c060a34u; return 0; }
r[0]&=r[13];
goto P_0c060a36;
P_0c060a36: /* original 8801, guest PC 0x0c060a36 */
if(!s->budget--) { s->failed_pc=0x0c060a36u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c060a38;
P_0c060a38: /* original 891e, guest PC 0x0c060a38 */
if(!s->budget--) { s->failed_pc=0x0c060a38u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c060a78; }
goto P_0c060a3a;
P_0c060a3a: /* original d30e, guest PC 0x0c060a3a */
if(!s->budget--) { s->failed_pc=0x0c060a3au; return 0; }
r[3]=read(ram,0x0c060a74u,4);
goto P_0c060a3c;
P_0c060a3c: /* original 6032, guest PC 0x0c060a3c */
if(!s->budget--) { s->failed_pc=0x0c060a3cu; return 0; }
tmp=read(ram,r[3],4);
r[0]=tmp;
goto P_0c060a3e;
P_0c060a3e: /* original c82c, guest PC 0x0c060a3e */
if(!s->budget--) { s->failed_pc=0x0c060a3eu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&44u)==0)!=0);
goto P_0c060a40;
P_0c060a40: /* original 891a, guest PC 0x0c060a40 */
if(!s->budget--) { s->failed_pc=0x0c060a40u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c060a78; }
goto P_0c060a42;
P_0c060a42: /* original 2dd8, guest PC 0x0c060a42 */
if(!s->budget--) { s->failed_pc=0x0c060a42u; return 0; }
r[17]=(r[17]&~1u)|(((r[13]&r[13])==0)!=0);
goto P_0c060a44;
P_0c060a44: /* original 8918, guest PC 0x0c060a44 */
if(!s->budget--) { s->failed_pc=0x0c060a44u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c060a78; }
goto P_0c060a46;
P_0c060a46: /* original e206, guest PC 0x0c060a46 */
if(!s->budget--) { s->failed_pc=0x0c060a46u; return 0; }
r[2]=0x00000006u;
goto P_0c060a48;
P_0c060a48: /* original a018, guest PC 0x0c060a48 */
if(!s->budget--) { s->failed_pc=0x0c060a48u; return 0; }
write(ram,r[14]+28,r[2],4);
goto P_0c060a7c;
P_0c060a4a: /* original 1e27, guest PC 0x0c060a4a */
if(!s->budget--) { s->failed_pc=0x0c060a4au; return 0; }
write(ram,r[14]+28,r[2],4);
return vf3_matrix_family(0x0c060a4cu,s,ram);
P_0c060a78: /* original e103, guest PC 0x0c060a78 */
if(!s->budget--) { s->failed_pc=0x0c060a78u; return 0; }
r[1]=0x00000003u;
goto P_0c060a7a;
P_0c060a7a: /* original 1e17, guest PC 0x0c060a7a */
if(!s->budget--) { s->failed_pc=0x0c060a7au; return 0; }
write(ram,r[14]+28,r[1],4);
goto P_0c060a7c;
P_0c060a7c: /* original d329, guest PC 0x0c060a7c */
if(!s->budget--) { s->failed_pc=0x0c060a7cu; return 0; }
r[3]=read(ram,0x0c060b24u,4);
goto P_0c060a7e;
P_0c060a7e: /* original 6032, guest PC 0x0c060a7e */
if(!s->budget--) { s->failed_pc=0x0c060a7eu; return 0; }
tmp=read(ram,r[3],4);
r[0]=tmp;
goto P_0c060a80;
P_0c060a80: /* original 20d9, guest PC 0x0c060a80 */
if(!s->budget--) { s->failed_pc=0x0c060a80u; return 0; }
r[0]&=r[13];
goto P_0c060a82;
P_0c060a82: /* original 8801, guest PC 0x0c060a82 */
if(!s->budget--) { s->failed_pc=0x0c060a82u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c060a84;
P_0c060a84: /* original 8908, guest PC 0x0c060a84 */
if(!s->budget--) { s->failed_pc=0x0c060a84u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c060a98; }
goto P_0c060a86;
P_0c060a86: /* original d227, guest PC 0x0c060a86 */
if(!s->budget--) { s->failed_pc=0x0c060a86u; return 0; }
r[2]=read(ram,0x0c060b24u,4);
goto P_0c060a88;
P_0c060a88: /* original 6022, guest PC 0x0c060a88 */
if(!s->budget--) { s->failed_pc=0x0c060a88u; return 0; }
tmp=read(ram,r[2],4);
r[0]=tmp;
goto P_0c060a8a;
P_0c060a8a: /* original c82c, guest PC 0x0c060a8a */
if(!s->budget--) { s->failed_pc=0x0c060a8au; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&44u)==0)!=0);
goto P_0c060a8c;
P_0c060a8c: /* original 8904, guest PC 0x0c060a8c */
if(!s->budget--) { s->failed_pc=0x0c060a8cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c060a98; }
goto P_0c060a8e;
P_0c060a8e: /* original 2dd8, guest PC 0x0c060a8e */
if(!s->budget--) { s->failed_pc=0x0c060a8eu; return 0; }
r[17]=(r[17]&~1u)|(((r[13]&r[13])==0)!=0);
goto P_0c060a90;
P_0c060a90: /* original 8902, guest PC 0x0c060a90 */
if(!s->budget--) { s->failed_pc=0x0c060a90u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c060a98; }
goto P_0c060a92;
P_0c060a92: /* original 9344, guest PC 0x0c060a92 */
if(!s->budget--) { s->failed_pc=0x0c060a92u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c060b1eu,2);
goto P_0c060a94;
P_0c060a94: /* original a002, guest PC 0x0c060a94 */
if(!s->budget--) { s->failed_pc=0x0c060a94u; return 0; }
write(ram,r[14]+32,r[3],4);
goto P_0c060a9c;
P_0c060a96: /* original 1e38, guest PC 0x0c060a96 */
if(!s->budget--) { s->failed_pc=0x0c060a96u; return 0; }
write(ram,r[14]+32,r[3],4);
goto P_0c060a98;
P_0c060a98: /* original 9142, guest PC 0x0c060a98 */
if(!s->budget--) { s->failed_pc=0x0c060a98u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c060b20u,2);
goto P_0c060a9a;
P_0c060a9a: /* original 1e18, guest PC 0x0c060a9a */
if(!s->budget--) { s->failed_pc=0x0c060a9au; return 0; }
write(ram,r[14]+32,r[1],4);
goto P_0c060a9c;
P_0c060a9c: /* original d321, guest PC 0x0c060a9c */
if(!s->budget--) { s->failed_pc=0x0c060a9cu; return 0; }
r[3]=read(ram,0x0c060b24u,4);
goto P_0c060a9e;
P_0c060a9e: /* original 6032, guest PC 0x0c060a9e */
if(!s->budget--) { s->failed_pc=0x0c060a9eu; return 0; }
tmp=read(ram,r[3],4);
r[0]=tmp;
goto P_0c060aa0;
P_0c060aa0: /* original 20d9, guest PC 0x0c060aa0 */
if(!s->budget--) { s->failed_pc=0x0c060aa0u; return 0; }
r[0]&=r[13];
goto P_0c060aa2;
P_0c060aa2: /* original 8801, guest PC 0x0c060aa2 */
if(!s->budget--) { s->failed_pc=0x0c060aa2u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c060aa4;
P_0c060aa4: /* original 8d08, guest PC 0x0c060aa4 */
if(!s->budget--) { s->failed_pc=0x0c060aa4u; return 0; }
cond=r[17]&1u;
r[5]=0x0000001fu;
if(cond) { goto P_0c060ab8; }
goto P_0c060aa8;
P_0c060aa6: /* original e51f, guest PC 0x0c060aa6 */
if(!s->budget--) { s->failed_pc=0x0c060aa6u; return 0; }
r[5]=0x0000001fu;
goto P_0c060aa8;
P_0c060aa8: /* original d21e, guest PC 0x0c060aa8 */
if(!s->budget--) { s->failed_pc=0x0c060aa8u; return 0; }
r[2]=read(ram,0x0c060b24u,4);
goto P_0c060aaa;
P_0c060aaa: /* original 6022, guest PC 0x0c060aaa */
if(!s->budget--) { s->failed_pc=0x0c060aaau; return 0; }
tmp=read(ram,r[2],4);
r[0]=tmp;
goto P_0c060aac;
P_0c060aac: /* original c82c, guest PC 0x0c060aac */
if(!s->budget--) { s->failed_pc=0x0c060aacu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&44u)==0)!=0);
goto P_0c060aae;
P_0c060aae: /* original 8903, guest PC 0x0c060aae */
if(!s->budget--) { s->failed_pc=0x0c060aaeu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c060ab8; }
goto P_0c060ab0;
P_0c060ab0: /* original 2dd8, guest PC 0x0c060ab0 */
if(!s->budget--) { s->failed_pc=0x0c060ab0u; return 0; }
r[17]=(r[17]&~1u)|(((r[13]&r[13])==0)!=0);
goto P_0c060ab2;
P_0c060ab2: /* original 8901, guest PC 0x0c060ab2 */
if(!s->budget--) { s->failed_pc=0x0c060ab2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c060ab8; }
goto P_0c060ab4;
P_0c060ab4: /* original a002, guest PC 0x0c060ab4 */
if(!s->budget--) { s->failed_pc=0x0c060ab4u; return 0; }
write(ram,r[14]+36,r[5],4);
goto P_0c060abc;
P_0c060ab6: /* original 1e59, guest PC 0x0c060ab6 */
if(!s->budget--) { s->failed_pc=0x0c060ab6u; return 0; }
write(ram,r[14]+36,r[5],4);
goto P_0c060ab8;
P_0c060ab8: /* original e20f, guest PC 0x0c060ab8 */
if(!s->budget--) { s->failed_pc=0x0c060ab8u; return 0; }
r[2]=0x0000000fu;
goto P_0c060aba;
P_0c060aba: /* original 1e29, guest PC 0x0c060aba */
if(!s->budget--) { s->failed_pc=0x0c060abau; return 0; }
write(ram,r[14]+36,r[2],4);
goto P_0c060abc;
P_0c060abc: /* original 1eda, guest PC 0x0c060abc */
if(!s->budget--) { s->failed_pc=0x0c060abcu; return 0; }
write(ram,r[14]+40,r[13],4);
goto P_0c060abe;
P_0c060abe: /* original e400, guest PC 0x0c060abe */
if(!s->budget--) { s->failed_pc=0x0c060abeu; return 0; }
r[4]=0x00000000u;
goto P_0c060ac0;
P_0c060ac0: /* original d318, guest PC 0x0c060ac0 */
if(!s->budget--) { s->failed_pc=0x0c060ac0u; return 0; }
r[3]=read(ram,0x0c060b24u,4);
goto P_0c060ac2;
P_0c060ac2: /* original 1e4b, guest PC 0x0c060ac2 */
if(!s->budget--) { s->failed_pc=0x0c060ac2u; return 0; }
write(ram,r[14]+44,r[4],4);
goto P_0c060ac4;
P_0c060ac4: /* original 6032, guest PC 0x0c060ac4 */
if(!s->budget--) { s->failed_pc=0x0c060ac4u; return 0; }
tmp=read(ram,r[3],4);
r[0]=tmp;
goto P_0c060ac6;
P_0c060ac6: /* original 20d9, guest PC 0x0c060ac6 */
if(!s->budget--) { s->failed_pc=0x0c060ac6u; return 0; }
r[0]&=r[13];
goto P_0c060ac8;
P_0c060ac8: /* original 8801, guest PC 0x0c060ac8 */
if(!s->budget--) { s->failed_pc=0x0c060ac8u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c060aca;
P_0c060aca: /* original 8b03, guest PC 0x0c060aca */
if(!s->budget--) { s->failed_pc=0x0c060acau; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c060ad4; }
goto P_0c060acc;
P_0c060acc: /* original 2448, guest PC 0x0c060acc */
if(!s->budget--) { s->failed_pc=0x0c060accu; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c060ace;
P_0c060ace: /* original 890d, guest PC 0x0c060ace */
if(!s->budget--) { s->failed_pc=0x0c060aceu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c060aec; }
goto P_0c060ad0;
P_0c060ad0: /* original a00a, guest PC 0x0c060ad0 */
if(!s->budget--) { s->failed_pc=0x0c060ad0u; return 0; }
goto P_0c060ae8;
P_0c060ad2: /* original 0009, guest PC 0x0c060ad2 */
if(!s->budget--) { s->failed_pc=0x0c060ad2u; return 0; }
goto P_0c060ad4;
P_0c060ad4: /* original d213, guest PC 0x0c060ad4 */
if(!s->budget--) { s->failed_pc=0x0c060ad4u; return 0; }
r[2]=read(ram,0x0c060b24u,4);
goto P_0c060ad6;
P_0c060ad6: /* original 6022, guest PC 0x0c060ad6 */
if(!s->budget--) { s->failed_pc=0x0c060ad6u; return 0; }
tmp=read(ram,r[2],4);
r[0]=tmp;
goto P_0c060ad8;
P_0c060ad8: /* original c82c, guest PC 0x0c060ad8 */
if(!s->budget--) { s->failed_pc=0x0c060ad8u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&44u)==0)!=0);
goto P_0c060ada;
P_0c060ada: /* original 8903, guest PC 0x0c060ada */
if(!s->budget--) { s->failed_pc=0x0c060adau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c060ae4; }
goto P_0c060adc;
P_0c060adc: /* original 2dd8, guest PC 0x0c060adc */
if(!s->budget--) { s->failed_pc=0x0c060adcu; return 0; }
r[17]=(r[17]&~1u)|(((r[13]&r[13])==0)!=0);
goto P_0c060ade;
P_0c060ade: /* original 8905, guest PC 0x0c060ade */
if(!s->budget--) { s->failed_pc=0x0c060adeu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c060aec; }
goto P_0c060ae0;
P_0c060ae0: /* original a002, guest PC 0x0c060ae0 */
if(!s->budget--) { s->failed_pc=0x0c060ae0u; return 0; }
goto P_0c060ae8;
P_0c060ae2: /* original 0009, guest PC 0x0c060ae2 */
if(!s->budget--) { s->failed_pc=0x0c060ae2u; return 0; }
goto P_0c060ae4;
P_0c060ae4: /* original 2448, guest PC 0x0c060ae4 */
if(!s->budget--) { s->failed_pc=0x0c060ae4u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c060ae6;
P_0c060ae6: /* original 8901, guest PC 0x0c060ae6 */
if(!s->budget--) { s->failed_pc=0x0c060ae6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c060aec; }
goto P_0c060ae8;
P_0c060ae8: /* original a001, guest PC 0x0c060ae8 */
if(!s->budget--) { s->failed_pc=0x0c060ae8u; return 0; }
write(ram,r[14]+48,r[13],4);
goto P_0c060aee;
P_0c060aea: /* original 1edc, guest PC 0x0c060aea */
if(!s->budget--) { s->failed_pc=0x0c060aeau; return 0; }
write(ram,r[14]+48,r[13],4);
goto P_0c060aec;
P_0c060aec: /* original 1e4c, guest PC 0x0c060aec */
if(!s->budget--) { s->failed_pc=0x0c060aecu; return 0; }
write(ram,r[14]+48,r[4],4);
goto P_0c060aee;
P_0c060aee: /* original e040, guest PC 0x0c060aee */
if(!s->budget--) { s->failed_pc=0x0c060aeeu; return 0; }
r[0]=0x00000040u;
goto P_0c060af0;
P_0c060af0: /* original d30d, guest PC 0x0c060af0 */
if(!s->budget--) { s->failed_pc=0x0c060af0u; return 0; }
r[3]=read(ram,0x0c060b28u,4);
goto P_0c060af2;
P_0c060af2: /* original 1e4d, guest PC 0x0c060af2 */
if(!s->budget--) { s->failed_pc=0x0c060af2u; return 0; }
write(ram,r[14]+52,r[4],4);
goto P_0c060af4;
P_0c060af4: /* original 1e4e, guest PC 0x0c060af4 */
if(!s->budget--) { s->failed_pc=0x0c060af4u; return 0; }
write(ram,r[14]+56,r[4],4);
goto P_0c060af6;
P_0c060af6: /* original 1e4f, guest PC 0x0c060af6 */
if(!s->budget--) { s->failed_pc=0x0c060af6u; return 0; }
write(ram,r[14]+60,r[4],4);
goto P_0c060af8;
P_0c060af8: /* original 0e46, guest PC 0x0c060af8 */
if(!s->budget--) { s->failed_pc=0x0c060af8u; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c060afa;
P_0c060afa: /* original e044, guest PC 0x0c060afa */
if(!s->budget--) { s->failed_pc=0x0c060afau; return 0; }
r[0]=0x00000044u;
goto P_0c060afc;
P_0c060afc: /* original 0e46, guest PC 0x0c060afc */
if(!s->budget--) { s->failed_pc=0x0c060afcu; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c060afe;
P_0c060afe: /* original 6032, guest PC 0x0c060afe */
if(!s->budget--) { s->failed_pc=0x0c060afeu; return 0; }
tmp=read(ram,r[3],4);
r[0]=tmp;
goto P_0c060b00;
P_0c060b00: /* original 8806, guest PC 0x0c060b00 */
if(!s->budget--) { s->failed_pc=0x0c060b00u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000006u)!=0);
goto P_0c060b02;
P_0c060b02: /* original 8b03, guest PC 0x0c060b02 */
if(!s->budget--) { s->failed_pc=0x0c060b02u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c060b0c; }
goto P_0c060b04;
P_0c060b04: /* original e116, guest PC 0x0c060b04 */
if(!s->budget--) { s->failed_pc=0x0c060b04u; return 0; }
r[1]=0x00000016u;
goto P_0c060b06;
P_0c060b06: /* original e070, guest PC 0x0c060b06 */
if(!s->budget--) { s->failed_pc=0x0c060b06u; return 0; }
r[0]=0x00000070u;
goto P_0c060b08;
P_0c060b08: /* original a002, guest PC 0x0c060b08 */
if(!s->budget--) { s->failed_pc=0x0c060b08u; return 0; }
write(ram,r[14]+r[0],r[1],4);
goto P_0c060b10;
P_0c060b0a: /* original 0e16, guest PC 0x0c060b0a */
if(!s->budget--) { s->failed_pc=0x0c060b0au; return 0; }
write(ram,r[14]+r[0],r[1],4);
goto P_0c060b0c;
P_0c060b0c: /* original e070, guest PC 0x0c060b0c */
if(!s->budget--) { s->failed_pc=0x0c060b0cu; return 0; }
r[0]=0x00000070u;
goto P_0c060b0e;
P_0c060b0e: /* original 0e56, guest PC 0x0c060b0e */
if(!s->budget--) { s->failed_pc=0x0c060b0eu; return 0; }
write(ram,r[14]+r[0],r[5],4);
goto P_0c060b10;
P_0c060b10: /* original d304, guest PC 0x0c060b10 */
if(!s->budget--) { s->failed_pc=0x0c060b10u; return 0; }
r[3]=read(ram,0x0c060b24u,4);
goto P_0c060b12;
P_0c060b12: /* original 6032, guest PC 0x0c060b12 */
if(!s->budget--) { s->failed_pc=0x0c060b12u; return 0; }
tmp=read(ram,r[3],4);
r[0]=tmp;
goto P_0c060b14;
P_0c060b14: /* original c810, guest PC 0x0c060b14 */
if(!s->budget--) { s->failed_pc=0x0c060b14u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&16u)==0)!=0);
goto P_0c060b16;
P_0c060b16: /* original 8909, guest PC 0x0c060b16 */
if(!s->budget--) { s->failed_pc=0x0c060b16u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c060b2c; }
goto P_0c060b18;
P_0c060b18: /* original e06c, guest PC 0x0c060b18 */
if(!s->budget--) { s->failed_pc=0x0c060b18u; return 0; }
r[0]=0x0000006cu;
goto P_0c060b1a;
P_0c060b1a: /* original a009, guest PC 0x0c060b1a */
if(!s->budget--) { s->failed_pc=0x0c060b1au; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c060b30;
P_0c060b1c: /* original 0e46, guest PC 0x0c060b1c */
if(!s->budget--) { s->failed_pc=0x0c060b1cu; return 0; }
write(ram,r[14]+r[0],r[4],4);
return vf3_matrix_family(0x0c060b1eu,s,ram);
P_0c060b2c: /* original e06c, guest PC 0x0c060b2c */
if(!s->budget--) { s->failed_pc=0x0c060b2cu; return 0; }
r[0]=0x0000006cu;
goto P_0c060b2e;
P_0c060b2e: /* original 0ed6, guest PC 0x0c060b2e */
if(!s->budget--) { s->failed_pc=0x0c060b2eu; return 0; }
write(ram,r[14]+r[0],r[13],4);
goto P_0c060b30;
P_0c060b30: /* original 9380, guest PC 0x0c060b30 */
if(!s->budget--) { s->failed_pc=0x0c060b30u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c060c34u,2);
goto P_0c060b32;
P_0c060b32: /* original e048, guest PC 0x0c060b32 */
if(!s->budget--) { s->failed_pc=0x0c060b32u; return 0; }
r[0]=0x00000048u;
goto P_0c060b34;
P_0c060b34: /* original 0ed6, guest PC 0x0c060b34 */
if(!s->budget--) { s->failed_pc=0x0c060b34u; return 0; }
write(ram,r[14]+r[0],r[13],4);
goto P_0c060b36;
P_0c060b36: /* original e04c, guest PC 0x0c060b36 */
if(!s->budget--) { s->failed_pc=0x0c060b36u; return 0; }
r[0]=0x0000004cu;
goto P_0c060b38;
P_0c060b38: /* original 0e46, guest PC 0x0c060b38 */
if(!s->budget--) { s->failed_pc=0x0c060b38u; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c060b3a;
P_0c060b3a: /* original e050, guest PC 0x0c060b3a */
if(!s->budget--) { s->failed_pc=0x0c060b3au; return 0; }
r[0]=0x00000050u;
goto P_0c060b3c;
P_0c060b3c: /* original 0e46, guest PC 0x0c060b3c */
if(!s->budget--) { s->failed_pc=0x0c060b3cu; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c060b3e;
P_0c060b3e: /* original e054, guest PC 0x0c060b3e */
if(!s->budget--) { s->failed_pc=0x0c060b3eu; return 0; }
r[0]=0x00000054u;
goto P_0c060b40;
P_0c060b40: /* original 0e46, guest PC 0x0c060b40 */
if(!s->budget--) { s->failed_pc=0x0c060b40u; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c060b42;
P_0c060b42: /* original e058, guest PC 0x0c060b42 */
if(!s->budget--) { s->failed_pc=0x0c060b42u; return 0; }
r[0]=0x00000058u;
goto P_0c060b44;
P_0c060b44: /* original 0e46, guest PC 0x0c060b44 */
if(!s->budget--) { s->failed_pc=0x0c060b44u; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c060b46;
P_0c060b46: /* original e05c, guest PC 0x0c060b46 */
if(!s->budget--) { s->failed_pc=0x0c060b46u; return 0; }
r[0]=0x0000005cu;
goto P_0c060b48;
P_0c060b48: /* original 0e46, guest PC 0x0c060b48 */
if(!s->budget--) { s->failed_pc=0x0c060b48u; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c060b4a;
P_0c060b4a: /* original e068, guest PC 0x0c060b4a */
if(!s->budget--) { s->failed_pc=0x0c060b4au; return 0; }
r[0]=0x00000068u;
goto P_0c060b4c;
P_0c060b4c: /* original 0e46, guest PC 0x0c060b4c */
if(!s->budget--) { s->failed_pc=0x0c060b4cu; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c060b4e;
P_0c060b4e: /* original 6033, guest PC 0x0c060b4e */
if(!s->budget--) { s->failed_pc=0x0c060b4eu; return 0; }
r[0]=r[3];
goto P_0c060b50;
P_0c060b50: /* original 0009, guest PC 0x0c060b50 */
if(!s->budget--) { s->failed_pc=0x0c060b50u; return 0; }
goto P_0c060b52;
P_0c060b52: /* original 7054, guest PC 0x0c060b52 */
if(!s->budget--) { s->failed_pc=0x0c060b52u; return 0; }
r[0]+=0x00000054u;
goto P_0c060b54;
P_0c060b54: /* original 926f, guest PC 0x0c060b54 */
if(!s->budget--) { s->failed_pc=0x0c060b54u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c060c36u,2);
goto P_0c060b56;
P_0c060b56: /* original 0e36, guest PC 0x0c060b56 */
if(!s->budget--) { s->failed_pc=0x0c060b56u; return 0; }
write(ram,r[14]+r[0],r[3],4);
goto P_0c060b58;
P_0c060b58: /* original d33c, guest PC 0x0c060b58 */
if(!s->budget--) { s->failed_pc=0x0c060b58u; return 0; }
r[3]=read(ram,0x0c060c4cu,4);
goto P_0c060b5a;
P_0c060b5a: /* original e064, guest PC 0x0c060b5a */
if(!s->budget--) { s->failed_pc=0x0c060b5au; return 0; }
r[0]=0x00000064u;
goto P_0c060b5c;
P_0c060b5c: /* original 0e26, guest PC 0x0c060b5c */
if(!s->budget--) { s->failed_pc=0x0c060b5cu; return 0; }
write(ram,r[14]+r[0],r[2],4);
goto P_0c060b5e;
P_0c060b5e: /* original e060, guest PC 0x0c060b5e */
if(!s->budget--) { s->failed_pc=0x0c060b5eu; return 0; }
r[0]=0x00000060u;
goto P_0c060b60;
P_0c060b60: /* original 0e46, guest PC 0x0c060b60 */
if(!s->budget--) { s->failed_pc=0x0c060b60u; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c060b62;
P_0c060b62: /* original 6032, guest PC 0x0c060b62 */
if(!s->budget--) { s->failed_pc=0x0c060b62u; return 0; }
tmp=read(ram,r[3],4);
r[0]=tmp;
goto P_0c060b64;
P_0c060b64: /* original 20d9, guest PC 0x0c060b64 */
if(!s->budget--) { s->failed_pc=0x0c060b64u; return 0; }
r[0]&=r[13];
goto P_0c060b66;
P_0c060b66: /* original 8801, guest PC 0x0c060b66 */
if(!s->budget--) { s->failed_pc=0x0c060b66u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c060b68;
P_0c060b68: /* original 8b03, guest PC 0x0c060b68 */
if(!s->budget--) { s->failed_pc=0x0c060b68u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c060b72; }
goto P_0c060b6a;
P_0c060b6a: /* original 2448, guest PC 0x0c060b6a */
if(!s->budget--) { s->failed_pc=0x0c060b6au; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c060b6c;
P_0c060b6c: /* original 890e, guest PC 0x0c060b6c */
if(!s->budget--) { s->failed_pc=0x0c060b6cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c060b8c; }
goto P_0c060b6e;
P_0c060b6e: /* original a00a, guest PC 0x0c060b6e */
if(!s->budget--) { s->failed_pc=0x0c060b6eu; return 0; }
goto P_0c060b86;
P_0c060b70: /* original 0009, guest PC 0x0c060b70 */
if(!s->budget--) { s->failed_pc=0x0c060b70u; return 0; }
goto P_0c060b72;
P_0c060b72: /* original d236, guest PC 0x0c060b72 */
if(!s->budget--) { s->failed_pc=0x0c060b72u; return 0; }
r[2]=read(ram,0x0c060c4cu,4);
goto P_0c060b74;
P_0c060b74: /* original 6022, guest PC 0x0c060b74 */
if(!s->budget--) { s->failed_pc=0x0c060b74u; return 0; }
tmp=read(ram,r[2],4);
r[0]=tmp;
goto P_0c060b76;
P_0c060b76: /* original c82c, guest PC 0x0c060b76 */
if(!s->budget--) { s->failed_pc=0x0c060b76u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&44u)==0)!=0);
goto P_0c060b78;
P_0c060b78: /* original 8903, guest PC 0x0c060b78 */
if(!s->budget--) { s->failed_pc=0x0c060b78u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c060b82; }
goto P_0c060b7a;
P_0c060b7a: /* original 2dd8, guest PC 0x0c060b7a */
if(!s->budget--) { s->failed_pc=0x0c060b7au; return 0; }
r[17]=(r[17]&~1u)|(((r[13]&r[13])==0)!=0);
goto P_0c060b7c;
P_0c060b7c: /* original 8906, guest PC 0x0c060b7c */
if(!s->budget--) { s->failed_pc=0x0c060b7cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c060b8c; }
goto P_0c060b7e;
P_0c060b7e: /* original a002, guest PC 0x0c060b7e */
if(!s->budget--) { s->failed_pc=0x0c060b7eu; return 0; }
goto P_0c060b86;
P_0c060b80: /* original 0009, guest PC 0x0c060b80 */
if(!s->budget--) { s->failed_pc=0x0c060b80u; return 0; }
goto P_0c060b82;
P_0c060b82: /* original 2448, guest PC 0x0c060b82 */
if(!s->budget--) { s->failed_pc=0x0c060b82u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c060b84;
P_0c060b84: /* original 8902, guest PC 0x0c060b84 */
if(!s->budget--) { s->failed_pc=0x0c060b84u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c060b8c; }
goto P_0c060b86;
P_0c060b86: /* original 9057, guest PC 0x0c060b86 */
if(!s->budget--) { s->failed_pc=0x0c060b86u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c060c38u,2);
goto P_0c060b88;
P_0c060b88: /* original a003, guest PC 0x0c060b88 */
if(!s->budget--) { s->failed_pc=0x0c060b88u; return 0; }
write(ram,r[14]+r[0],r[12],4);
goto P_0c060b92;
P_0c060b8a: /* original 0ec6, guest PC 0x0c060b8a */
if(!s->budget--) { s->failed_pc=0x0c060b8au; return 0; }
write(ram,r[14]+r[0],r[12],4);
goto P_0c060b8c;
P_0c060b8c: /* original 9054, guest PC 0x0c060b8c */
if(!s->budget--) { s->failed_pc=0x0c060b8cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c060c38u,2);
goto P_0c060b8e;
P_0c060b8e: /* original e311, guest PC 0x0c060b8e */
if(!s->budget--) { s->failed_pc=0x0c060b8eu; return 0; }
r[3]=0x00000011u;
goto P_0c060b90;
P_0c060b90: /* original 0e36, guest PC 0x0c060b90 */
if(!s->budget--) { s->failed_pc=0x0c060b90u; return 0; }
write(ram,r[14]+r[0],r[3],4);
goto P_0c060b92;
P_0c060b92: /* original 9052, guest PC 0x0c060b92 */
if(!s->budget--) { s->failed_pc=0x0c060b92u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c060c3au,2);
goto P_0c060b94;
P_0c060b94: /* original 9350, guest PC 0x0c060b94 */
if(!s->budget--) { s->failed_pc=0x0c060b94u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c060c38u,2);
goto P_0c060b96;
P_0c060b96: /* original 0ec6, guest PC 0x0c060b96 */
if(!s->budget--) { s->failed_pc=0x0c060b96u; return 0; }
write(ram,r[14]+r[0],r[12],4);
goto P_0c060b98;
P_0c060b98: /* original d22d, guest PC 0x0c060b98 */
if(!s->budget--) { s->failed_pc=0x0c060b98u; return 0; }
r[2]=read(ram,0x0c060c50u,4);
goto P_0c060b9a;
P_0c060b9a: /* original 2232, guest PC 0x0c060b9a */
if(!s->budget--) { s->failed_pc=0x0c060b9au; return 0; }
write(ram,r[2],r[3],4);
goto P_0c060b9c;
P_0c060b9c: /* original 51e3, guest PC 0x0c060b9c */
if(!s->budget--) { s->failed_pc=0x0c060b9cu; return 0; }
r[1]=read(ram,r[14]+12,4);
goto P_0c060b9e;
P_0c060b9e: /* original e300, guest PC 0x0c060b9e */
if(!s->budget--) { s->failed_pc=0x0c060b9eu; return 0; }
r[3]=0x00000000u;
goto P_0c060ba0;
P_0c060ba0: /* original 3317, guest PC 0x0c060ba0 */
if(!s->budget--) { s->failed_pc=0x0c060ba0u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>(int32_t)r[1])!=0);
goto P_0c060ba2;
P_0c060ba2: /* original 313e, guest PC 0x0c060ba2 */
if(!s->budget--) { s->failed_pc=0x0c060ba2u; return 0; }
wide=(uint64_t)r[1]+r[3]+(r[17]&1u); r[1]=(uint32_t)wide;
r[17]=(r[17]&~1u)|((wide>>32)!=0);
goto P_0c060ba4;
P_0c060ba4: /* original 4121, guest PC 0x0c060ba4 */
if(!s->budget--) { s->failed_pc=0x0c060ba4u; return 0; }
r[17]=(r[17]&~1u)|((r[1]&1)!=0);
r[1]=(uint32_t)((int32_t)r[1]>>1);
goto P_0c060ba6;
P_0c060ba6: /* original 6323, guest PC 0x0c060ba6 */
if(!s->budget--) { s->failed_pc=0x0c060ba6u; return 0; }
r[3]=r[2];
goto P_0c060ba8;
P_0c060ba8: /* original 6032, guest PC 0x0c060ba8 */
if(!s->budget--) { s->failed_pc=0x0c060ba8u; return 0; }
tmp=read(ram,r[3],4);
r[0]=tmp;
goto P_0c060baa;
P_0c060baa: /* original 310c, guest PC 0x0c060baa */
if(!s->budget--) { s->failed_pc=0x0c060baau; return 0; }
r[1]+=r[0];
goto P_0c060bac;
P_0c060bac: /* original d029, guest PC 0x0c060bac */
if(!s->budget--) { s->failed_pc=0x0c060bacu; return 0; }
r[0]=read(ram,0x0c060c54u,4);
goto P_0c060bae;
P_0c060bae: /* original 2012, guest PC 0x0c060bae */
if(!s->budget--) { s->failed_pc=0x0c060baeu; return 0; }
write(ram,r[0],r[1],4);
goto P_0c060bb0;
P_0c060bb0: /* original 52e3, guest PC 0x0c060bb0 */
if(!s->budget--) { s->failed_pc=0x0c060bb0u; return 0; }
r[2]=read(ram,r[14]+12,4);
goto P_0c060bb2;
P_0c060bb2: /* original d129, guest PC 0x0c060bb2 */
if(!s->budget--) { s->failed_pc=0x0c060bb2u; return 0; }
r[1]=read(ram,0x0c060c58u,4);
goto P_0c060bb4;
P_0c060bb4: /* original 2122, guest PC 0x0c060bb4 */
if(!s->budget--) { s->failed_pc=0x0c060bb4u; return 0; }
write(ram,r[1],r[2],4);
goto P_0c060bb6;
P_0c060bb6: /* original 62e3, guest PC 0x0c060bb6 */
if(!s->budget--) { s->failed_pc=0x0c060bb6u; return 0; }
r[2]=r[14];
goto P_0c060bb8;
P_0c060bb8: /* original 9040, guest PC 0x0c060bb8 */
if(!s->budget--) { s->failed_pc=0x0c060bb8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c060c3cu,2);
goto P_0c060bba;
P_0c060bba: /* original 3f08, guest PC 0x0c060bba */
if(!s->budget--) { s->failed_pc=0x0c060bbau; return 0; }
r[15]-=r[0];
goto P_0c060bbc;
P_0c060bbc: /* original d327, guest PC 0x0c060bbc */
if(!s->budget--) { s->failed_pc=0x0c060bbcu; return 0; }
r[3]=read(ram,0x0c060c5cu,4);
goto P_0c060bbe;
P_0c060bbe: /* original 430b, guest PC 0x0c060bbe */
if(!s->budget--) { s->failed_pc=0x0c060bbeu; return 0; }
target=r[3];
r[16]=0x0c060bc2u;
r[1]=r[15];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c060bc2u) { target=s->pc; goto dispatch; }
goto P_0c060bc2;
P_0c060bc0: /* original 61f3, guest PC 0x0c060bc0 */
if(!s->budget--) { s->failed_pc=0x0c060bc0u; return 0; }
r[1]=r[15];
goto P_0c060bc2;
P_0c060bc2: /* original bcc3, guest PC 0x0c060bc2 */
if(!s->budget--) { s->failed_pc=0x0c060bc2u; return 0; }
target=0x0c06054cu; r[16]=0x0c060bc6u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c060bc6u) { target=s->pc; goto dispatch; }
goto P_0c060bc6;
P_0c060bc4: /* original 0009, guest PC 0x0c060bc4 */
if(!s->budget--) { s->failed_pc=0x0c060bc4u; return 0; }
goto P_0c060bc6;
P_0c060bc6: /* original 9239, guest PC 0x0c060bc6 */
if(!s->budget--) { s->failed_pc=0x0c060bc6u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c060c3cu,2);
goto P_0c060bc8;
P_0c060bc8: /* original 9138, guest PC 0x0c060bc8 */
if(!s->budget--) { s->failed_pc=0x0c060bc8u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c060c3cu,2);
goto P_0c060bca;
P_0c060bca: /* original 3f2c, guest PC 0x0c060bca */
if(!s->budget--) { s->failed_pc=0x0c060bcau; return 0; }
r[15]+=r[2];
goto P_0c060bcc;
P_0c060bcc: /* original 3f1c, guest PC 0x0c060bcc */
if(!s->budget--) { s->failed_pc=0x0c060bccu; return 0; }
r[15]+=r[1];
goto P_0c060bce;
P_0c060bce: /* original 4f26, guest PC 0x0c060bce */
if(!s->budget--) { s->failed_pc=0x0c060bceu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c060bd0;
P_0c060bd0: /* original 6cf6, guest PC 0x0c060bd0 */
if(!s->budget--) { s->failed_pc=0x0c060bd0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c060bd2;
P_0c060bd2: /* original 6df6, guest PC 0x0c060bd2 */
if(!s->budget--) { s->failed_pc=0x0c060bd2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c060bd4;
P_0c060bd4: /* original 000b, guest PC 0x0c060bd4 */
if(!s->budget--) { s->failed_pc=0x0c060bd4u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c060bd6: /* original 6ef6, guest PC 0x0c060bd6 */
if(!s->budget--) { s->failed_pc=0x0c060bd6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c060bd8u,s,ram);
P_0c0711b0: /* original f40b, guest PC 0x0c0711b0 */
if(!s->budget--) { s->failed_pc=0x0c0711b0u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c0711b2;
P_0c0711b2: /* original 0009, guest PC 0x0c0711b2 */
if(!s->budget--) { s->failed_pc=0x0c0711b2u; return 0; }
goto P_0c0711b4;
P_0c0711b4: /* original 64f3, guest PC 0x0c0711b4 */
if(!s->budget--) { s->failed_pc=0x0c0711b4u; return 0; }
r[4]=r[15];
goto P_0c0711b6;
P_0c0711b6: /* original 741c, guest PC 0x0c0711b6 */
if(!s->budget--) { s->failed_pc=0x0c0711b6u; return 0; }
r[4]+=0x0000001cu;
goto P_0c0711b8;
P_0c0711b8: /* original f049, guest PC 0x0c0711b8 */
if(!s->budget--) { s->failed_pc=0x0c0711b8u; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c0711ba;
P_0c0711ba: /* original f149, guest PC 0x0c0711ba */
if(!s->budget--) { s->failed_pc=0x0c0711bau; return 0; }
vf3_matrix_load(s,ram,1,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c0711bc;
P_0c0711bc: /* original f249, guest PC 0x0c0711bc */
if(!s->budget--) { s->failed_pc=0x0c0711bcu; return 0; }
vf3_matrix_load(s,ram,2,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c0711be;
P_0c0711be: /* original f38d, guest PC 0x0c0711be */
if(!s->budget--) { s->failed_pc=0x0c0711beu; return 0; }
fr[3]=0;
goto P_0c0711c0;
P_0c0711c0: /* original f0ed, guest PC 0x0c0711c0 */
if(!s->budget--) { s->failed_pc=0x0c0711c0u; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+0,r[18],fr+3)) goto unsupported;
goto P_0c0711c2;
P_0c0711c2: /* original f03c, guest PC 0x0c0711c2 */
if(!s->budget--) { s->failed_pc=0x0c0711c2u; return 0; }
vf3_matrix_move(s,0,3);
goto P_0c0711c4;
P_0c0711c4: /* original f06d, guest PC 0x0c0711c4 */
if(!s->budget--) { s->failed_pc=0x0c0711c4u; return 0; }
fr[0]=vf3_fpu_sqrt(fr[0],r[18]);
goto P_0c0711c6;
P_0c0711c6: /* original 0009, guest PC 0x0c0711c6 */
if(!s->budget--) { s->failed_pc=0x0c0711c6u; return 0; }
goto P_0c0711c8;
P_0c0711c8: /* original f38d, guest PC 0x0c0711c8 */
if(!s->budget--) { s->failed_pc=0x0c0711c8u; return 0; }
fr[3]=0;
goto P_0c0711ca;
P_0c0711ca: /* original fe0c, guest PC 0x0c0711ca */
if(!s->budget--) { s->failed_pc=0x0c0711cau; return 0; }
vf3_matrix_move(s,14,0);
goto P_0c0711cc;
P_0c0711cc: /* original fe35, guest PC 0x0c0711cc */
if(!s->budget--) { s->failed_pc=0x0c0711ccu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[14])>as_float(fr[3]))!=0);
goto P_0c0711ce;
P_0c0711ce: /* original 8902, guest PC 0x0c0711ce */
if(!s->budget--) { s->failed_pc=0x0c0711ceu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0711d6; }
goto P_0c0711d0;
P_0c0711d0: /* original d303, guest PC 0x0c0711d0 */
if(!s->budget--) { s->failed_pc=0x0c0711d0u; return 0; }
r[3]=read(ram,0x0c0711e0u,4);
goto P_0c0711d2;
P_0c0711d2: /* original 432b, guest PC 0x0c0711d2 */
if(!s->budget--) { s->failed_pc=0x0c0711d2u; return 0; }
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
P_0c0711d4: /* original 0009, guest PC 0x0c0711d4 */
if(!s->budget--) { s->failed_pc=0x0c0711d4u; return 0; }
goto P_0c0711d6;
P_0c0711d6: /* original 64f3, guest PC 0x0c0711d6 */
if(!s->budget--) { s->failed_pc=0x0c0711d6u; return 0; }
r[4]=r[15];
goto P_0c0711d8;
P_0c0711d8: /* original 741c, guest PC 0x0c0711d8 */
if(!s->budget--) { s->failed_pc=0x0c0711d8u; return 0; }
r[4]+=0x0000001cu;
goto P_0c0711da;
P_0c0711da: /* original 65d3, guest PC 0x0c0711da */
if(!s->budget--) { s->failed_pc=0x0c0711dau; return 0; }
r[5]=r[13];
goto P_0c0711dc;
P_0c0711dc: /* original a002, guest PC 0x0c0711dc */
if(!s->budget--) { s->failed_pc=0x0c0711dcu; return 0; }
goto P_0c0711e4;
P_0c0711de: /* original 0009, guest PC 0x0c0711de */
if(!s->budget--) { s->failed_pc=0x0c0711deu; return 0; }
return vf3_matrix_family(0x0c0711e0u,s,ram);
P_0c0711e4: /* original f049, guest PC 0x0c0711e4 */
if(!s->budget--) { s->failed_pc=0x0c0711e4u; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c0711e6;
P_0c0711e6: /* original f549, guest PC 0x0c0711e6 */
if(!s->budget--) { s->failed_pc=0x0c0711e6u; return 0; }
vf3_matrix_load(s,ram,5,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c0711e8;
P_0c0711e8: /* original f648, guest PC 0x0c0711e8 */
if(!s->budget--) { s->failed_pc=0x0c0711e8u; return 0; }
vf3_matrix_load(s,ram,6,r[4]);
goto P_0c0711ea;
P_0c0711ea: /* original f859, guest PC 0x0c0711ea */
if(!s->budget--) { s->failed_pc=0x0c0711eau; return 0; }
vf3_matrix_load(s,ram,8,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0711ec;
P_0c0711ec: /* original f959, guest PC 0x0c0711ec */
if(!s->budget--) { s->failed_pc=0x0c0711ecu; return 0; }
vf3_matrix_load(s,ram,9,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0711ee;
P_0c0711ee: /* original fa58, guest PC 0x0c0711ee */
if(!s->budget--) { s->failed_pc=0x0c0711eeu; return 0; }
vf3_matrix_load(s,ram,10,r[5]);
goto P_0c0711f0;
P_0c0711f0: /* original f35c, guest PC 0x0c0711f0 */
if(!s->budget--) { s->failed_pc=0x0c0711f0u; return 0; }
vf3_matrix_move(s,3,5);
goto P_0c0711f2;
P_0c0711f2: /* original f382, guest PC 0x0c0711f2 */
if(!s->budget--) { s->failed_pc=0x0c0711f2u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[8],r[18],'*');
goto P_0c0711f4;
P_0c0711f4: /* original f20c, guest PC 0x0c0711f4 */
if(!s->budget--) { s->failed_pc=0x0c0711f4u; return 0; }
vf3_matrix_move(s,2,0);
goto P_0c0711f6;
P_0c0711f6: /* original f2a2, guest PC 0x0c0711f6 */
if(!s->budget--) { s->failed_pc=0x0c0711f6u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[10],r[18],'*');
goto P_0c0711f8;
P_0c0711f8: /* original f16c, guest PC 0x0c0711f8 */
if(!s->budget--) { s->failed_pc=0x0c0711f8u; return 0; }
vf3_matrix_move(s,1,6);
goto P_0c0711fa;
P_0c0711fa: /* original f192, guest PC 0x0c0711fa */
if(!s->budget--) { s->failed_pc=0x0c0711fau; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[9],r[18],'*');
goto P_0c0711fc;
P_0c0711fc: /* original f34d, guest PC 0x0c0711fc */
if(!s->budget--) { s->failed_pc=0x0c0711fcu; return 0; }
fr[3]^=0x80000000u;
goto P_0c0711fe;
P_0c0711fe: /* original f39e, guest PC 0x0c0711fe */
if(!s->budget--) { s->failed_pc=0x0c0711feu; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[9],fr[3],r[18]);
goto P_0c071200;
P_0c071200: /* original f24d, guest PC 0x0c071200 */
if(!s->budget--) { s->failed_pc=0x0c071200u; return 0; }
fr[2]^=0x80000000u;
goto P_0c071202;
P_0c071202: /* original f06c, guest PC 0x0c071202 */
if(!s->budget--) { s->failed_pc=0x0c071202u; return 0; }
vf3_matrix_move(s,0,6);
goto P_0c071204;
P_0c071204: /* original f28e, guest PC 0x0c071204 */
if(!s->budget--) { s->failed_pc=0x0c071204u; return 0; }
fr[2]=vf3_fpu_mac(fr[0],fr[8],fr[2],r[18]);
goto P_0c071206;
P_0c071206: /* original f14d, guest PC 0x0c071206 */
if(!s->budget--) { s->failed_pc=0x0c071206u; return 0; }
fr[1]^=0x80000000u;
goto P_0c071208;
P_0c071208: /* original f05c, guest PC 0x0c071208 */
if(!s->budget--) { s->failed_pc=0x0c071208u; return 0; }
vf3_matrix_move(s,0,5);
goto P_0c07120a;
P_0c07120a: /* original f1ae, guest PC 0x0c07120a */
if(!s->budget--) { s->failed_pc=0x0c07120au; return 0; }
fr[1]=vf3_fpu_mac(fr[0],fr[10],fr[1],r[18]);
goto P_0c07120c;
P_0c07120c: /* original f08d, guest PC 0x0c07120c */
if(!s->budget--) { s->failed_pc=0x0c07120cu; return 0; }
fr[0]=0;
goto P_0c07120e;
P_0c07120e: /* original f0ed, guest PC 0x0c07120e */
if(!s->budget--) { s->failed_pc=0x0c07120eu; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+0,r[18],fr+3)) goto unsupported;
goto P_0c071210;
P_0c071210: /* original f03c, guest PC 0x0c071210 */
if(!s->budget--) { s->failed_pc=0x0c071210u; return 0; }
vf3_matrix_move(s,0,3);
goto P_0c071212;
P_0c071212: /* original f06d, guest PC 0x0c071212 */
if(!s->budget--) { s->failed_pc=0x0c071212u; return 0; }
fr[0]=vf3_fpu_sqrt(fr[0],r[18]);
goto P_0c071214;
P_0c071214: /* original fd0c, guest PC 0x0c071214 */
if(!s->budget--) { s->failed_pc=0x0c071214u; return 0; }
vf3_matrix_move(s,13,0);
goto P_0c071216;
P_0c071216: /* original ffd5, guest PC 0x0c071216 */
if(!s->budget--) { s->failed_pc=0x0c071216u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[15])>as_float(fr[13]))!=0);
goto P_0c071218;
P_0c071218: /* original 8902, guest PC 0x0c071218 */
if(!s->budget--) { s->failed_pc=0x0c071218u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c071220; }
goto P_0c07121a;
P_0c07121a: /* original d304, guest PC 0x0c07121a */
if(!s->budget--) { s->failed_pc=0x0c07121au; return 0; }
r[3]=read(ram,0x0c07122cu,4);
goto P_0c07121c;
P_0c07121c: /* original 432b, guest PC 0x0c07121c */
if(!s->budget--) { s->failed_pc=0x0c07121cu; return 0; }
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
P_0c07121e: /* original 0009, guest PC 0x0c07121e */
if(!s->budget--) { s->failed_pc=0x0c07121eu; return 0; }
goto P_0c071220;
P_0c071220: /* original 64f3, guest PC 0x0c071220 */
if(!s->budget--) { s->failed_pc=0x0c071220u; return 0; }
r[4]=r[15];
goto P_0c071222;
P_0c071222: /* original 741c, guest PC 0x0c071222 */
if(!s->budget--) { s->failed_pc=0x0c071222u; return 0; }
r[4]+=0x0000001cu;
goto P_0c071224;
P_0c071224: /* original 65d3, guest PC 0x0c071224 */
if(!s->budget--) { s->failed_pc=0x0c071224u; return 0; }
r[5]=r[13];
goto P_0c071226;
P_0c071226: /* original a003, guest PC 0x0c071226 */
if(!s->budget--) { s->failed_pc=0x0c071226u; return 0; }
goto P_0c071230;
P_0c071228: /* original 0009, guest PC 0x0c071228 */
if(!s->budget--) { s->failed_pc=0x0c071228u; return 0; }
return vf3_matrix_family(0x0c07122au,s,ram);
P_0c071230: /* original f049, guest PC 0x0c071230 */
if(!s->budget--) { s->failed_pc=0x0c071230u; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c071232;
P_0c071232: /* original f149, guest PC 0x0c071232 */
if(!s->budget--) { s->failed_pc=0x0c071232u; return 0; }
vf3_matrix_load(s,ram,1,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c071234;
P_0c071234: /* original f249, guest PC 0x0c071234 */
if(!s->budget--) { s->failed_pc=0x0c071234u; return 0; }
vf3_matrix_load(s,ram,2,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c071236;
P_0c071236: /* original f38d, guest PC 0x0c071236 */
if(!s->budget--) { s->failed_pc=0x0c071236u; return 0; }
fr[3]=0;
goto P_0c071238;
P_0c071238: /* original f459, guest PC 0x0c071238 */
if(!s->budget--) { s->failed_pc=0x0c071238u; return 0; }
vf3_matrix_load(s,ram,4,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c07123a;
P_0c07123a: /* original f559, guest PC 0x0c07123a */
if(!s->budget--) { s->failed_pc=0x0c07123au; return 0; }
vf3_matrix_load(s,ram,5,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c07123c;
P_0c07123c: /* original f659, guest PC 0x0c07123c */
if(!s->budget--) { s->failed_pc=0x0c07123cu; return 0; }
vf3_matrix_load(s,ram,6,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c07123e;
P_0c07123e: /* original f78d, guest PC 0x0c07123e */
if(!s->budget--) { s->failed_pc=0x0c07123eu; return 0; }
fr[7]=0;
goto P_0c071240;
P_0c071240: /* original f4ed, guest PC 0x0c071240 */
if(!s->budget--) { s->failed_pc=0x0c071240u; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+4,r[18],fr+7)) goto unsupported;
goto P_0c071242;
P_0c071242: /* original f07c, guest PC 0x0c071242 */
if(!s->budget--) { s->failed_pc=0x0c071242u; return 0; }
vf3_matrix_move(s,0,7);
goto P_0c071244;
P_0c071244: /* original f38d, guest PC 0x0c071244 */
if(!s->budget--) { s->failed_pc=0x0c071244u; return 0; }
fr[3]=0;
goto P_0c071246;
P_0c071246: /* original f40c, guest PC 0x0c071246 */
if(!s->budget--) { s->failed_pc=0x0c071246u; return 0; }
vf3_matrix_move(s,4,0);
goto P_0c071248;
P_0c071248: /* original f345, guest PC 0x0c071248 */
if(!s->budget--) { s->failed_pc=0x0c071248u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[4]))!=0);
goto P_0c07124a;
P_0c07124a: /* original 8902, guest PC 0x0c07124a */
if(!s->budget--) { s->failed_pc=0x0c07124au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c071252; }
goto P_0c07124c;
P_0c07124c: /* original d307, guest PC 0x0c07124c */
if(!s->budget--) { s->failed_pc=0x0c07124cu; return 0; }
r[3]=read(ram,0x0c07126cu,4);
goto P_0c07124e;
P_0c07124e: /* original 432b, guest PC 0x0c07124e */
if(!s->budget--) { s->failed_pc=0x0c07124eu; return 0; }
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
P_0c071250: /* original 0009, guest PC 0x0c071250 */
if(!s->budget--) { s->failed_pc=0x0c071250u; return 0; }
goto P_0c071252;
P_0c071252: /* original ffe5, guest PC 0x0c071252 */
if(!s->budget--) { s->failed_pc=0x0c071252u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[15])>as_float(fr[14]))!=0);
goto P_0c071254;
P_0c071254: /* original 8902, guest PC 0x0c071254 */
if(!s->budget--) { s->failed_pc=0x0c071254u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07125c; }
goto P_0c071256;
P_0c071256: /* original d206, guest PC 0x0c071256 */
if(!s->budget--) { s->failed_pc=0x0c071256u; return 0; }
r[2]=read(ram,0x0c071270u,4);
goto P_0c071258;
P_0c071258: /* original 422b, guest PC 0x0c071258 */
if(!s->budget--) { s->failed_pc=0x0c071258u; return 0; }
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
P_0c07125a: /* original 0009, guest PC 0x0c07125a */
if(!s->budget--) { s->failed_pc=0x0c07125au; return 0; }
goto P_0c07125c;
P_0c07125c: /* original 64f3, guest PC 0x0c07125c */
if(!s->budget--) { s->failed_pc=0x0c07125cu; return 0; }
r[4]=r[15];
goto P_0c07125e;
P_0c07125e: /* original 65f3, guest PC 0x0c07125e */
if(!s->budget--) { s->failed_pc=0x0c07125eu; return 0; }
r[5]=r[15];
goto P_0c071260;
P_0c071260: /* original 741c, guest PC 0x0c071260 */
if(!s->budget--) { s->failed_pc=0x0c071260u; return 0; }
r[4]+=0x0000001cu;
goto P_0c071262;
P_0c071262: /* original f4fc, guest PC 0x0c071262 */
if(!s->budget--) { s->failed_pc=0x0c071262u; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c071264;
P_0c071264: /* original 751c, guest PC 0x0c071264 */
if(!s->budget--) { s->failed_pc=0x0c071264u; return 0; }
r[5]+=0x0000001cu;
goto P_0c071266;
P_0c071266: /* original a005, guest PC 0x0c071266 */
if(!s->budget--) { s->failed_pc=0x0c071266u; return 0; }
goto P_0c071274;
P_0c071268: /* original 0009, guest PC 0x0c071268 */
if(!s->budget--) { s->failed_pc=0x0c071268u; return 0; }
return vf3_matrix_family(0x0c07126au,s,ram);
P_0c071274: /* original f059, guest PC 0x0c071274 */
if(!s->budget--) { s->failed_pc=0x0c071274u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c071276;
P_0c071276: /* original f159, guest PC 0x0c071276 */
if(!s->budget--) { s->failed_pc=0x0c071276u; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c071278;
P_0c071278: /* original f259, guest PC 0x0c071278 */
if(!s->budget--) { s->failed_pc=0x0c071278u; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c07127a;
P_0c07127a: /* original f38d, guest PC 0x0c07127a */
if(!s->budget--) { s->failed_pc=0x0c07127au; return 0; }
fr[3]=0;
goto P_0c07127c;
P_0c07127c: /* original f0ed, guest PC 0x0c07127c */
if(!s->budget--) { s->failed_pc=0x0c07127cu; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+0,r[18],fr+3)) goto unsupported;
goto P_0c07127e;
P_0c07127e: /* original f37d, guest PC 0x0c07127e */
if(!s->budget--) { s->failed_pc=0x0c07127eu; return 0; }
if(!vf3_fpu_fsrra(fr[3],r[18],&fr[3])) goto unsupported;
goto P_0c071280;
P_0c071280: /* original f342, guest PC 0x0c071280 */
if(!s->budget--) { s->failed_pc=0x0c071280u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'*');
goto P_0c071282;
P_0c071282: /* original 740c, guest PC 0x0c071282 */
if(!s->budget--) { s->failed_pc=0x0c071282u; return 0; }
r[4]+=0x0000000cu;
goto P_0c071284;
P_0c071284: /* original f232, guest PC 0x0c071284 */
if(!s->budget--) { s->failed_pc=0x0c071284u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c071286;
P_0c071286: /* original f132, guest PC 0x0c071286 */
if(!s->budget--) { s->failed_pc=0x0c071286u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[3],r[18],'*');
goto P_0c071288;
P_0c071288: /* original f032, guest PC 0x0c071288 */
if(!s->budget--) { s->failed_pc=0x0c071288u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'*');
goto P_0c07128a;
P_0c07128a: /* original f42b, guest PC 0x0c07128a */
if(!s->budget--) { s->failed_pc=0x0c07128au; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c07128c;
P_0c07128c: /* original f41b, guest PC 0x0c07128c */
if(!s->budget--) { s->failed_pc=0x0c07128cu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c07128e;
P_0c07128e: /* original f40b, guest PC 0x0c07128e */
if(!s->budget--) { s->failed_pc=0x0c07128eu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c071290;
P_0c071290: /* original d206, guest PC 0x0c071290 */
if(!s->budget--) { s->failed_pc=0x0c071290u; return 0; }
r[2]=read(ram,0x0c0712acu,4);
goto P_0c071292;
P_0c071292: /* original 422b, guest PC 0x0c071292 */
if(!s->budget--) { s->failed_pc=0x0c071292u; return 0; }
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
P_0c071294: /* original 0009, guest PC 0x0c071294 */
if(!s->budget--) { s->failed_pc=0x0c071294u; return 0; }
return vf3_matrix_family(0x0c071296u,s,ram);
P_0c071428: /* original f40b, guest PC 0x0c071428 */
if(!s->budget--) { s->failed_pc=0x0c071428u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c07142a;
P_0c07142a: /* original 0009, guest PC 0x0c07142a */
if(!s->budget--) { s->failed_pc=0x0c07142au; return 0; }
goto P_0c07142c;
P_0c07142c: /* original 64f3, guest PC 0x0c07142c */
if(!s->budget--) { s->failed_pc=0x0c07142cu; return 0; }
r[4]=r[15];
goto P_0c07142e;
P_0c07142e: /* original 741c, guest PC 0x0c07142e */
if(!s->budget--) { s->failed_pc=0x0c07142eu; return 0; }
r[4]+=0x0000001cu;
goto P_0c071430;
P_0c071430: /* original f049, guest PC 0x0c071430 */
if(!s->budget--) { s->failed_pc=0x0c071430u; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c071432;
P_0c071432: /* original f149, guest PC 0x0c071432 */
if(!s->budget--) { s->failed_pc=0x0c071432u; return 0; }
vf3_matrix_load(s,ram,1,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c071434;
P_0c071434: /* original f249, guest PC 0x0c071434 */
if(!s->budget--) { s->failed_pc=0x0c071434u; return 0; }
vf3_matrix_load(s,ram,2,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c071436;
P_0c071436: /* original f38d, guest PC 0x0c071436 */
if(!s->budget--) { s->failed_pc=0x0c071436u; return 0; }
fr[3]=0;
goto P_0c071438;
P_0c071438: /* original f0ed, guest PC 0x0c071438 */
if(!s->budget--) { s->failed_pc=0x0c071438u; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+0,r[18],fr+3)) goto unsupported;
goto P_0c07143a;
P_0c07143a: /* original f03c, guest PC 0x0c07143a */
if(!s->budget--) { s->failed_pc=0x0c07143au; return 0; }
vf3_matrix_move(s,0,3);
goto P_0c07143c;
P_0c07143c: /* original f06d, guest PC 0x0c07143c */
if(!s->budget--) { s->failed_pc=0x0c07143cu; return 0; }
fr[0]=vf3_fpu_sqrt(fr[0],r[18]);
goto P_0c07143e;
P_0c07143e: /* original 0009, guest PC 0x0c07143e */
if(!s->budget--) { s->failed_pc=0x0c07143eu; return 0; }
goto P_0c071440;
P_0c071440: /* original f38d, guest PC 0x0c071440 */
if(!s->budget--) { s->failed_pc=0x0c071440u; return 0; }
fr[3]=0;
goto P_0c071442;
P_0c071442: /* original fd0c, guest PC 0x0c071442 */
if(!s->budget--) { s->failed_pc=0x0c071442u; return 0; }
vf3_matrix_move(s,13,0);
goto P_0c071444;
P_0c071444: /* original fd35, guest PC 0x0c071444 */
if(!s->budget--) { s->failed_pc=0x0c071444u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[13])>as_float(fr[3]))!=0);
goto P_0c071446;
P_0c071446: /* original 8902, guest PC 0x0c071446 */
if(!s->budget--) { s->failed_pc=0x0c071446u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07144e; }
goto P_0c071448;
P_0c071448: /* original d303, guest PC 0x0c071448 */
if(!s->budget--) { s->failed_pc=0x0c071448u; return 0; }
r[3]=read(ram,0x0c071458u,4);
goto P_0c07144a;
P_0c07144a: /* original 432b, guest PC 0x0c07144a */
if(!s->budget--) { s->failed_pc=0x0c07144au; return 0; }
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
P_0c07144c: /* original 0009, guest PC 0x0c07144c */
if(!s->budget--) { s->failed_pc=0x0c07144cu; return 0; }
goto P_0c07144e;
P_0c07144e: /* original 64f3, guest PC 0x0c07144e */
if(!s->budget--) { s->failed_pc=0x0c07144eu; return 0; }
r[4]=r[15];
goto P_0c071450;
P_0c071450: /* original 741c, guest PC 0x0c071450 */
if(!s->budget--) { s->failed_pc=0x0c071450u; return 0; }
r[4]+=0x0000001cu;
goto P_0c071452;
P_0c071452: /* original 65d3, guest PC 0x0c071452 */
if(!s->budget--) { s->failed_pc=0x0c071452u; return 0; }
r[5]=r[13];
goto P_0c071454;
P_0c071454: /* original a002, guest PC 0x0c071454 */
if(!s->budget--) { s->failed_pc=0x0c071454u; return 0; }
goto P_0c07145c;
P_0c071456: /* original 0009, guest PC 0x0c071456 */
if(!s->budget--) { s->failed_pc=0x0c071456u; return 0; }
return vf3_matrix_family(0x0c071458u,s,ram);
P_0c07145c: /* original f049, guest PC 0x0c07145c */
if(!s->budget--) { s->failed_pc=0x0c07145cu; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c07145e;
P_0c07145e: /* original f549, guest PC 0x0c07145e */
if(!s->budget--) { s->failed_pc=0x0c07145eu; return 0; }
vf3_matrix_load(s,ram,5,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c071460;
P_0c071460: /* original f648, guest PC 0x0c071460 */
if(!s->budget--) { s->failed_pc=0x0c071460u; return 0; }
vf3_matrix_load(s,ram,6,r[4]);
goto P_0c071462;
P_0c071462: /* original f859, guest PC 0x0c071462 */
if(!s->budget--) { s->failed_pc=0x0c071462u; return 0; }
vf3_matrix_load(s,ram,8,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c071464;
P_0c071464: /* original f959, guest PC 0x0c071464 */
if(!s->budget--) { s->failed_pc=0x0c071464u; return 0; }
vf3_matrix_load(s,ram,9,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c071466;
P_0c071466: /* original fa58, guest PC 0x0c071466 */
if(!s->budget--) { s->failed_pc=0x0c071466u; return 0; }
vf3_matrix_load(s,ram,10,r[5]);
goto P_0c071468;
P_0c071468: /* original f35c, guest PC 0x0c071468 */
if(!s->budget--) { s->failed_pc=0x0c071468u; return 0; }
vf3_matrix_move(s,3,5);
goto P_0c07146a;
P_0c07146a: /* original f382, guest PC 0x0c07146a */
if(!s->budget--) { s->failed_pc=0x0c07146au; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[8],r[18],'*');
goto P_0c07146c;
P_0c07146c: /* original f20c, guest PC 0x0c07146c */
if(!s->budget--) { s->failed_pc=0x0c07146cu; return 0; }
vf3_matrix_move(s,2,0);
goto P_0c07146e;
P_0c07146e: /* original f2a2, guest PC 0x0c07146e */
if(!s->budget--) { s->failed_pc=0x0c07146eu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[10],r[18],'*');
goto P_0c071470;
P_0c071470: /* original f16c, guest PC 0x0c071470 */
if(!s->budget--) { s->failed_pc=0x0c071470u; return 0; }
vf3_matrix_move(s,1,6);
goto P_0c071472;
P_0c071472: /* original f192, guest PC 0x0c071472 */
if(!s->budget--) { s->failed_pc=0x0c071472u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[9],r[18],'*');
goto P_0c071474;
P_0c071474: /* original f34d, guest PC 0x0c071474 */
if(!s->budget--) { s->failed_pc=0x0c071474u; return 0; }
fr[3]^=0x80000000u;
goto P_0c071476;
P_0c071476: /* original f39e, guest PC 0x0c071476 */
if(!s->budget--) { s->failed_pc=0x0c071476u; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[9],fr[3],r[18]);
goto P_0c071478;
P_0c071478: /* original f24d, guest PC 0x0c071478 */
if(!s->budget--) { s->failed_pc=0x0c071478u; return 0; }
fr[2]^=0x80000000u;
goto P_0c07147a;
P_0c07147a: /* original f06c, guest PC 0x0c07147a */
if(!s->budget--) { s->failed_pc=0x0c07147au; return 0; }
vf3_matrix_move(s,0,6);
goto P_0c07147c;
P_0c07147c: /* original f28e, guest PC 0x0c07147c */
if(!s->budget--) { s->failed_pc=0x0c07147cu; return 0; }
fr[2]=vf3_fpu_mac(fr[0],fr[8],fr[2],r[18]);
goto P_0c07147e;
P_0c07147e: /* original f14d, guest PC 0x0c07147e */
if(!s->budget--) { s->failed_pc=0x0c07147eu; return 0; }
fr[1]^=0x80000000u;
goto P_0c071480;
P_0c071480: /* original f05c, guest PC 0x0c071480 */
if(!s->budget--) { s->failed_pc=0x0c071480u; return 0; }
vf3_matrix_move(s,0,5);
goto P_0c071482;
P_0c071482: /* original f1ae, guest PC 0x0c071482 */
if(!s->budget--) { s->failed_pc=0x0c071482u; return 0; }
fr[1]=vf3_fpu_mac(fr[0],fr[10],fr[1],r[18]);
goto P_0c071484;
P_0c071484: /* original f08d, guest PC 0x0c071484 */
if(!s->budget--) { s->failed_pc=0x0c071484u; return 0; }
fr[0]=0;
goto P_0c071486;
P_0c071486: /* original f0ed, guest PC 0x0c071486 */
if(!s->budget--) { s->failed_pc=0x0c071486u; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+0,r[18],fr+3)) goto unsupported;
goto P_0c071488;
P_0c071488: /* original f03c, guest PC 0x0c071488 */
if(!s->budget--) { s->failed_pc=0x0c071488u; return 0; }
vf3_matrix_move(s,0,3);
goto P_0c07148a;
P_0c07148a: /* original f06d, guest PC 0x0c07148a */
if(!s->budget--) { s->failed_pc=0x0c07148au; return 0; }
fr[0]=vf3_fpu_sqrt(fr[0],r[18]);
goto P_0c07148c;
P_0c07148c: /* original fe0c, guest PC 0x0c07148c */
if(!s->budget--) { s->failed_pc=0x0c07148cu; return 0; }
vf3_matrix_move(s,14,0);
goto P_0c07148e;
P_0c07148e: /* original ffe5, guest PC 0x0c07148e */
if(!s->budget--) { s->failed_pc=0x0c07148eu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[15])>as_float(fr[14]))!=0);
goto P_0c071490;
P_0c071490: /* original 8902, guest PC 0x0c071490 */
if(!s->budget--) { s->failed_pc=0x0c071490u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c071498; }
goto P_0c071492;
P_0c071492: /* original d304, guest PC 0x0c071492 */
if(!s->budget--) { s->failed_pc=0x0c071492u; return 0; }
r[3]=read(ram,0x0c0714a4u,4);
goto P_0c071494;
P_0c071494: /* original 432b, guest PC 0x0c071494 */
if(!s->budget--) { s->failed_pc=0x0c071494u; return 0; }
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
P_0c071496: /* original 0009, guest PC 0x0c071496 */
if(!s->budget--) { s->failed_pc=0x0c071496u; return 0; }
goto P_0c071498;
P_0c071498: /* original 64f3, guest PC 0x0c071498 */
if(!s->budget--) { s->failed_pc=0x0c071498u; return 0; }
r[4]=r[15];
goto P_0c07149a;
P_0c07149a: /* original 741c, guest PC 0x0c07149a */
if(!s->budget--) { s->failed_pc=0x0c07149au; return 0; }
r[4]+=0x0000001cu;
goto P_0c07149c;
P_0c07149c: /* original 65d3, guest PC 0x0c07149c */
if(!s->budget--) { s->failed_pc=0x0c07149cu; return 0; }
r[5]=r[13];
goto P_0c07149e;
P_0c07149e: /* original a003, guest PC 0x0c07149e */
if(!s->budget--) { s->failed_pc=0x0c07149eu; return 0; }
goto P_0c0714a8;
P_0c0714a0: /* original 0009, guest PC 0x0c0714a0 */
if(!s->budget--) { s->failed_pc=0x0c0714a0u; return 0; }
return vf3_matrix_family(0x0c0714a2u,s,ram);
P_0c0714a8: /* original f049, guest PC 0x0c0714a8 */
if(!s->budget--) { s->failed_pc=0x0c0714a8u; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c0714aa;
P_0c0714aa: /* original f149, guest PC 0x0c0714aa */
if(!s->budget--) { s->failed_pc=0x0c0714aau; return 0; }
vf3_matrix_load(s,ram,1,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c0714ac;
P_0c0714ac: /* original f249, guest PC 0x0c0714ac */
if(!s->budget--) { s->failed_pc=0x0c0714acu; return 0; }
vf3_matrix_load(s,ram,2,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c0714ae;
P_0c0714ae: /* original f38d, guest PC 0x0c0714ae */
if(!s->budget--) { s->failed_pc=0x0c0714aeu; return 0; }
fr[3]=0;
goto P_0c0714b0;
P_0c0714b0: /* original f459, guest PC 0x0c0714b0 */
if(!s->budget--) { s->failed_pc=0x0c0714b0u; return 0; }
vf3_matrix_load(s,ram,4,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0714b2;
P_0c0714b2: /* original f559, guest PC 0x0c0714b2 */
if(!s->budget--) { s->failed_pc=0x0c0714b2u; return 0; }
vf3_matrix_load(s,ram,5,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0714b4;
P_0c0714b4: /* original f659, guest PC 0x0c0714b4 */
if(!s->budget--) { s->failed_pc=0x0c0714b4u; return 0; }
vf3_matrix_load(s,ram,6,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0714b6;
P_0c0714b6: /* original f78d, guest PC 0x0c0714b6 */
if(!s->budget--) { s->failed_pc=0x0c0714b6u; return 0; }
fr[7]=0;
goto P_0c0714b8;
P_0c0714b8: /* original f4ed, guest PC 0x0c0714b8 */
if(!s->budget--) { s->failed_pc=0x0c0714b8u; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+4,r[18],fr+7)) goto unsupported;
goto P_0c0714ba;
P_0c0714ba: /* original f07c, guest PC 0x0c0714ba */
if(!s->budget--) { s->failed_pc=0x0c0714bau; return 0; }
vf3_matrix_move(s,0,7);
goto P_0c0714bc;
P_0c0714bc: /* original f38d, guest PC 0x0c0714bc */
if(!s->budget--) { s->failed_pc=0x0c0714bcu; return 0; }
fr[3]=0;
goto P_0c0714be;
P_0c0714be: /* original f40c, guest PC 0x0c0714be */
if(!s->budget--) { s->failed_pc=0x0c0714beu; return 0; }
vf3_matrix_move(s,4,0);
goto P_0c0714c0;
P_0c0714c0: /* original f345, guest PC 0x0c0714c0 */
if(!s->budget--) { s->failed_pc=0x0c0714c0u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[4]))!=0);
goto P_0c0714c2;
P_0c0714c2: /* original 8902, guest PC 0x0c0714c2 */
if(!s->budget--) { s->failed_pc=0x0c0714c2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0714ca; }
goto P_0c0714c4;
P_0c0714c4: /* original d307, guest PC 0x0c0714c4 */
if(!s->budget--) { s->failed_pc=0x0c0714c4u; return 0; }
r[3]=read(ram,0x0c0714e4u,4);
goto P_0c0714c6;
P_0c0714c6: /* original 432b, guest PC 0x0c0714c6 */
if(!s->budget--) { s->failed_pc=0x0c0714c6u; return 0; }
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
P_0c0714c8: /* original 0009, guest PC 0x0c0714c8 */
if(!s->budget--) { s->failed_pc=0x0c0714c8u; return 0; }
goto P_0c0714ca;
P_0c0714ca: /* original ffd5, guest PC 0x0c0714ca */
if(!s->budget--) { s->failed_pc=0x0c0714cau; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[15])>as_float(fr[13]))!=0);
goto P_0c0714cc;
P_0c0714cc: /* original 8902, guest PC 0x0c0714cc */
if(!s->budget--) { s->failed_pc=0x0c0714ccu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0714d4; }
goto P_0c0714ce;
P_0c0714ce: /* original d206, guest PC 0x0c0714ce */
if(!s->budget--) { s->failed_pc=0x0c0714ceu; return 0; }
r[2]=read(ram,0x0c0714e8u,4);
goto P_0c0714d0;
P_0c0714d0: /* original 422b, guest PC 0x0c0714d0 */
if(!s->budget--) { s->failed_pc=0x0c0714d0u; return 0; }
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
P_0c0714d2: /* original 0009, guest PC 0x0c0714d2 */
if(!s->budget--) { s->failed_pc=0x0c0714d2u; return 0; }
goto P_0c0714d4;
P_0c0714d4: /* original 64f3, guest PC 0x0c0714d4 */
if(!s->budget--) { s->failed_pc=0x0c0714d4u; return 0; }
r[4]=r[15];
goto P_0c0714d6;
P_0c0714d6: /* original 65f3, guest PC 0x0c0714d6 */
if(!s->budget--) { s->failed_pc=0x0c0714d6u; return 0; }
r[5]=r[15];
goto P_0c0714d8;
P_0c0714d8: /* original 741c, guest PC 0x0c0714d8 */
if(!s->budget--) { s->failed_pc=0x0c0714d8u; return 0; }
r[4]+=0x0000001cu;
goto P_0c0714da;
P_0c0714da: /* original f4fc, guest PC 0x0c0714da */
if(!s->budget--) { s->failed_pc=0x0c0714dau; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c0714dc;
P_0c0714dc: /* original 751c, guest PC 0x0c0714dc */
if(!s->budget--) { s->failed_pc=0x0c0714dcu; return 0; }
r[5]+=0x0000001cu;
goto P_0c0714de;
P_0c0714de: /* original a005, guest PC 0x0c0714de */
if(!s->budget--) { s->failed_pc=0x0c0714deu; return 0; }
goto P_0c0714ec;
P_0c0714e0: /* original 0009, guest PC 0x0c0714e0 */
if(!s->budget--) { s->failed_pc=0x0c0714e0u; return 0; }
return vf3_matrix_family(0x0c0714e2u,s,ram);
P_0c0714ec: /* original f059, guest PC 0x0c0714ec */
if(!s->budget--) { s->failed_pc=0x0c0714ecu; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0714ee;
P_0c0714ee: /* original f159, guest PC 0x0c0714ee */
if(!s->budget--) { s->failed_pc=0x0c0714eeu; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0714f0;
P_0c0714f0: /* original f259, guest PC 0x0c0714f0 */
if(!s->budget--) { s->failed_pc=0x0c0714f0u; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0714f2;
P_0c0714f2: /* original f38d, guest PC 0x0c0714f2 */
if(!s->budget--) { s->failed_pc=0x0c0714f2u; return 0; }
fr[3]=0;
goto P_0c0714f4;
P_0c0714f4: /* original f0ed, guest PC 0x0c0714f4 */
if(!s->budget--) { s->failed_pc=0x0c0714f4u; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+0,r[18],fr+3)) goto unsupported;
goto P_0c0714f6;
P_0c0714f6: /* original f37d, guest PC 0x0c0714f6 */
if(!s->budget--) { s->failed_pc=0x0c0714f6u; return 0; }
if(!vf3_fpu_fsrra(fr[3],r[18],&fr[3])) goto unsupported;
goto P_0c0714f8;
P_0c0714f8: /* original f342, guest PC 0x0c0714f8 */
if(!s->budget--) { s->failed_pc=0x0c0714f8u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'*');
goto P_0c0714fa;
P_0c0714fa: /* original 740c, guest PC 0x0c0714fa */
if(!s->budget--) { s->failed_pc=0x0c0714fau; return 0; }
r[4]+=0x0000000cu;
goto P_0c0714fc;
P_0c0714fc: /* original f232, guest PC 0x0c0714fc */
if(!s->budget--) { s->failed_pc=0x0c0714fcu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c0714fe;
P_0c0714fe: /* original f132, guest PC 0x0c0714fe */
if(!s->budget--) { s->failed_pc=0x0c0714feu; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[3],r[18],'*');
goto P_0c071500;
P_0c071500: /* original f032, guest PC 0x0c071500 */
if(!s->budget--) { s->failed_pc=0x0c071500u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'*');
goto P_0c071502;
P_0c071502: /* original f42b, guest PC 0x0c071502 */
if(!s->budget--) { s->failed_pc=0x0c071502u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c071504;
P_0c071504: /* original f41b, guest PC 0x0c071504 */
if(!s->budget--) { s->failed_pc=0x0c071504u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c071506;
P_0c071506: /* original f40b, guest PC 0x0c071506 */
if(!s->budget--) { s->failed_pc=0x0c071506u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c071508;
P_0c071508: /* original d206, guest PC 0x0c071508 */
if(!s->budget--) { s->failed_pc=0x0c071508u; return 0; }
r[2]=read(ram,0x0c071524u,4);
goto P_0c07150a;
P_0c07150a: /* original 422b, guest PC 0x0c07150a */
if(!s->budget--) { s->failed_pc=0x0c07150au; return 0; }
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
P_0c07150c: /* original 0009, guest PC 0x0c07150c */
if(!s->budget--) { s->failed_pc=0x0c07150cu; return 0; }
return vf3_matrix_family(0x0c07150eu,s,ram);
P_0c072162: /* original f40b, guest PC 0x0c072162 */
if(!s->budget--) { s->failed_pc=0x0c072162u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c072164;
P_0c072164: /* original 66f3, guest PC 0x0c072164 */
if(!s->budget--) { s->failed_pc=0x0c072164u; return 0; }
r[6]=r[15];
goto P_0c072166;
P_0c072166: /* original 64c3, guest PC 0x0c072166 */
if(!s->budget--) { s->failed_pc=0x0c072166u; return 0; }
r[4]=r[12];
goto P_0c072168;
P_0c072168: /* original 65d3, guest PC 0x0c072168 */
if(!s->budget--) { s->failed_pc=0x0c072168u; return 0; }
r[5]=r[13];
goto P_0c07216a;
P_0c07216a: /* original 7624, guest PC 0x0c07216a */
if(!s->budget--) { s->failed_pc=0x0c07216au; return 0; }
r[6]+=0x00000024u;
goto P_0c07216c;
P_0c07216c: /* original f049, guest PC 0x0c07216c */
if(!s->budget--) { s->failed_pc=0x0c07216cu; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c07216e;
P_0c07216e: /* original f549, guest PC 0x0c07216e */
if(!s->budget--) { s->failed_pc=0x0c07216eu; return 0; }
vf3_matrix_load(s,ram,5,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c072170;
P_0c072170: /* original f648, guest PC 0x0c072170 */
if(!s->budget--) { s->failed_pc=0x0c072170u; return 0; }
vf3_matrix_load(s,ram,6,r[4]);
goto P_0c072172;
P_0c072172: /* original f859, guest PC 0x0c072172 */
if(!s->budget--) { s->failed_pc=0x0c072172u; return 0; }
vf3_matrix_load(s,ram,8,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c072174;
P_0c072174: /* original f959, guest PC 0x0c072174 */
if(!s->budget--) { s->failed_pc=0x0c072174u; return 0; }
vf3_matrix_load(s,ram,9,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c072176;
P_0c072176: /* original fa58, guest PC 0x0c072176 */
if(!s->budget--) { s->failed_pc=0x0c072176u; return 0; }
vf3_matrix_load(s,ram,10,r[5]);
goto P_0c072178;
P_0c072178: /* original 760c, guest PC 0x0c072178 */
if(!s->budget--) { s->failed_pc=0x0c072178u; return 0; }
r[6]+=0x0000000cu;
goto P_0c07217a;
P_0c07217a: /* original f35c, guest PC 0x0c07217a */
if(!s->budget--) { s->failed_pc=0x0c07217au; return 0; }
vf3_matrix_move(s,3,5);
goto P_0c07217c;
P_0c07217c: /* original f382, guest PC 0x0c07217c */
if(!s->budget--) { s->failed_pc=0x0c07217cu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[8],r[18],'*');
goto P_0c07217e;
P_0c07217e: /* original f20c, guest PC 0x0c07217e */
if(!s->budget--) { s->failed_pc=0x0c07217eu; return 0; }
vf3_matrix_move(s,2,0);
goto P_0c072180;
P_0c072180: /* original f2a2, guest PC 0x0c072180 */
if(!s->budget--) { s->failed_pc=0x0c072180u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[10],r[18],'*');
goto P_0c072182;
P_0c072182: /* original f16c, guest PC 0x0c072182 */
if(!s->budget--) { s->failed_pc=0x0c072182u; return 0; }
vf3_matrix_move(s,1,6);
goto P_0c072184;
P_0c072184: /* original f192, guest PC 0x0c072184 */
if(!s->budget--) { s->failed_pc=0x0c072184u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[9],r[18],'*');
goto P_0c072186;
P_0c072186: /* original f34d, guest PC 0x0c072186 */
if(!s->budget--) { s->failed_pc=0x0c072186u; return 0; }
fr[3]^=0x80000000u;
goto P_0c072188;
P_0c072188: /* original f39e, guest PC 0x0c072188 */
if(!s->budget--) { s->failed_pc=0x0c072188u; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[9],fr[3],r[18]);
goto P_0c07218a;
P_0c07218a: /* original f24d, guest PC 0x0c07218a */
if(!s->budget--) { s->failed_pc=0x0c07218au; return 0; }
fr[2]^=0x80000000u;
goto P_0c07218c;
P_0c07218c: /* original f06c, guest PC 0x0c07218c */
if(!s->budget--) { s->failed_pc=0x0c07218cu; return 0; }
vf3_matrix_move(s,0,6);
goto P_0c07218e;
P_0c07218e: /* original f28e, guest PC 0x0c07218e */
if(!s->budget--) { s->failed_pc=0x0c07218eu; return 0; }
fr[2]=vf3_fpu_mac(fr[0],fr[8],fr[2],r[18]);
goto P_0c072190;
P_0c072190: /* original f14d, guest PC 0x0c072190 */
if(!s->budget--) { s->failed_pc=0x0c072190u; return 0; }
fr[1]^=0x80000000u;
goto P_0c072192;
P_0c072192: /* original f63b, guest PC 0x0c072192 */
if(!s->budget--) { s->failed_pc=0x0c072192u; return 0; }
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,3,r[6]);
goto P_0c072194;
P_0c072194: /* original f05c, guest PC 0x0c072194 */
if(!s->budget--) { s->failed_pc=0x0c072194u; return 0; }
vf3_matrix_move(s,0,5);
goto P_0c072196;
P_0c072196: /* original f1ae, guest PC 0x0c072196 */
if(!s->budget--) { s->failed_pc=0x0c072196u; return 0; }
fr[1]=vf3_fpu_mac(fr[0],fr[10],fr[1],r[18]);
goto P_0c072198;
P_0c072198: /* original f62b, guest PC 0x0c072198 */
if(!s->budget--) { s->failed_pc=0x0c072198u; return 0; }
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[6]);
goto P_0c07219a;
P_0c07219a: /* original f61b, guest PC 0x0c07219a */
if(!s->budget--) { s->failed_pc=0x0c07219au; return 0; }
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[6]);
goto P_0c07219c;
P_0c07219c: /* original 66f3, guest PC 0x0c07219c */
if(!s->budget--) { s->failed_pc=0x0c07219cu; return 0; }
r[6]=r[15];
goto P_0c07219e;
P_0c07219e: /* original 64a3, guest PC 0x0c07219e */
if(!s->budget--) { s->failed_pc=0x0c07219eu; return 0; }
r[4]=r[10];
goto P_0c0721a0;
P_0c0721a0: /* original 65c3, guest PC 0x0c0721a0 */
if(!s->budget--) { s->failed_pc=0x0c0721a0u; return 0; }
r[5]=r[12];
goto P_0c0721a2;
P_0c0721a2: /* original 7618, guest PC 0x0c0721a2 */
if(!s->budget--) { s->failed_pc=0x0c0721a2u; return 0; }
r[6]+=0x00000018u;
goto P_0c0721a4;
P_0c0721a4: /* original f049, guest PC 0x0c0721a4 */
if(!s->budget--) { s->failed_pc=0x0c0721a4u; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c0721a6;
P_0c0721a6: /* original f549, guest PC 0x0c0721a6 */
if(!s->budget--) { s->failed_pc=0x0c0721a6u; return 0; }
vf3_matrix_load(s,ram,5,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c0721a8;
P_0c0721a8: /* original f648, guest PC 0x0c0721a8 */
if(!s->budget--) { s->failed_pc=0x0c0721a8u; return 0; }
vf3_matrix_load(s,ram,6,r[4]);
goto P_0c0721aa;
P_0c0721aa: /* original f859, guest PC 0x0c0721aa */
if(!s->budget--) { s->failed_pc=0x0c0721aau; return 0; }
vf3_matrix_load(s,ram,8,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0721ac;
P_0c0721ac: /* original f959, guest PC 0x0c0721ac */
if(!s->budget--) { s->failed_pc=0x0c0721acu; return 0; }
vf3_matrix_load(s,ram,9,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0721ae;
P_0c0721ae: /* original fa58, guest PC 0x0c0721ae */
if(!s->budget--) { s->failed_pc=0x0c0721aeu; return 0; }
vf3_matrix_load(s,ram,10,r[5]);
goto P_0c0721b0;
P_0c0721b0: /* original 760c, guest PC 0x0c0721b0 */
if(!s->budget--) { s->failed_pc=0x0c0721b0u; return 0; }
r[6]+=0x0000000cu;
goto P_0c0721b2;
P_0c0721b2: /* original f35c, guest PC 0x0c0721b2 */
if(!s->budget--) { s->failed_pc=0x0c0721b2u; return 0; }
vf3_matrix_move(s,3,5);
goto P_0c0721b4;
P_0c0721b4: /* original f382, guest PC 0x0c0721b4 */
if(!s->budget--) { s->failed_pc=0x0c0721b4u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[8],r[18],'*');
goto P_0c0721b6;
P_0c0721b6: /* original f20c, guest PC 0x0c0721b6 */
if(!s->budget--) { s->failed_pc=0x0c0721b6u; return 0; }
vf3_matrix_move(s,2,0);
goto P_0c0721b8;
P_0c0721b8: /* original f2a2, guest PC 0x0c0721b8 */
if(!s->budget--) { s->failed_pc=0x0c0721b8u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[10],r[18],'*');
goto P_0c0721ba;
P_0c0721ba: /* original f16c, guest PC 0x0c0721ba */
if(!s->budget--) { s->failed_pc=0x0c0721bau; return 0; }
vf3_matrix_move(s,1,6);
goto P_0c0721bc;
P_0c0721bc: /* original f192, guest PC 0x0c0721bc */
if(!s->budget--) { s->failed_pc=0x0c0721bcu; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[9],r[18],'*');
goto P_0c0721be;
P_0c0721be: /* original f34d, guest PC 0x0c0721be */
if(!s->budget--) { s->failed_pc=0x0c0721beu; return 0; }
fr[3]^=0x80000000u;
goto P_0c0721c0;
P_0c0721c0: /* original f39e, guest PC 0x0c0721c0 */
if(!s->budget--) { s->failed_pc=0x0c0721c0u; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[9],fr[3],r[18]);
goto P_0c0721c2;
P_0c0721c2: /* original f24d, guest PC 0x0c0721c2 */
if(!s->budget--) { s->failed_pc=0x0c0721c2u; return 0; }
fr[2]^=0x80000000u;
goto P_0c0721c4;
P_0c0721c4: /* original f06c, guest PC 0x0c0721c4 */
if(!s->budget--) { s->failed_pc=0x0c0721c4u; return 0; }
vf3_matrix_move(s,0,6);
goto P_0c0721c6;
P_0c0721c6: /* original f28e, guest PC 0x0c0721c6 */
if(!s->budget--) { s->failed_pc=0x0c0721c6u; return 0; }
fr[2]=vf3_fpu_mac(fr[0],fr[8],fr[2],r[18]);
goto P_0c0721c8;
P_0c0721c8: /* original f14d, guest PC 0x0c0721c8 */
if(!s->budget--) { s->failed_pc=0x0c0721c8u; return 0; }
fr[1]^=0x80000000u;
goto P_0c0721ca;
P_0c0721ca: /* original f63b, guest PC 0x0c0721ca */
if(!s->budget--) { s->failed_pc=0x0c0721cau; return 0; }
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,3,r[6]);
goto P_0c0721cc;
P_0c0721cc: /* original f05c, guest PC 0x0c0721cc */
if(!s->budget--) { s->failed_pc=0x0c0721ccu; return 0; }
vf3_matrix_move(s,0,5);
goto P_0c0721ce;
P_0c0721ce: /* original f1ae, guest PC 0x0c0721ce */
if(!s->budget--) { s->failed_pc=0x0c0721ceu; return 0; }
fr[1]=vf3_fpu_mac(fr[0],fr[10],fr[1],r[18]);
goto P_0c0721d0;
P_0c0721d0: /* original f62b, guest PC 0x0c0721d0 */
if(!s->budget--) { s->failed_pc=0x0c0721d0u; return 0; }
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[6]);
goto P_0c0721d2;
P_0c0721d2: /* original f61b, guest PC 0x0c0721d2 */
if(!s->budget--) { s->failed_pc=0x0c0721d2u; return 0; }
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[6]);
goto P_0c0721d4;
P_0c0721d4: /* original 64f3, guest PC 0x0c0721d4 */
if(!s->budget--) { s->failed_pc=0x0c0721d4u; return 0; }
r[4]=r[15];
goto P_0c0721d6;
P_0c0721d6: /* original 7424, guest PC 0x0c0721d6 */
if(!s->budget--) { s->failed_pc=0x0c0721d6u; return 0; }
r[4]+=0x00000024u;
goto P_0c0721d8;
P_0c0721d8: /* original f049, guest PC 0x0c0721d8 */
if(!s->budget--) { s->failed_pc=0x0c0721d8u; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c0721da;
P_0c0721da: /* original f149, guest PC 0x0c0721da */
if(!s->budget--) { s->failed_pc=0x0c0721dau; return 0; }
vf3_matrix_load(s,ram,1,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c0721dc;
P_0c0721dc: /* original f249, guest PC 0x0c0721dc */
if(!s->budget--) { s->failed_pc=0x0c0721dcu; return 0; }
vf3_matrix_load(s,ram,2,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c0721de;
P_0c0721de: /* original f38d, guest PC 0x0c0721de */
if(!s->budget--) { s->failed_pc=0x0c0721deu; return 0; }
fr[3]=0;
goto P_0c0721e0;
P_0c0721e0: /* original f0ed, guest PC 0x0c0721e0 */
if(!s->budget--) { s->failed_pc=0x0c0721e0u; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+0,r[18],fr+3)) goto unsupported;
goto P_0c0721e2;
P_0c0721e2: /* original f37d, guest PC 0x0c0721e2 */
if(!s->budget--) { s->failed_pc=0x0c0721e2u; return 0; }
if(!vf3_fpu_fsrra(fr[3],r[18],&fr[3])) goto unsupported;
goto P_0c0721e4;
P_0c0721e4: /* original f232, guest PC 0x0c0721e4 */
if(!s->budget--) { s->failed_pc=0x0c0721e4u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c0721e6;
P_0c0721e6: /* original f132, guest PC 0x0c0721e6 */
if(!s->budget--) { s->failed_pc=0x0c0721e6u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[3],r[18],'*');
goto P_0c0721e8;
P_0c0721e8: /* original f032, guest PC 0x0c0721e8 */
if(!s->budget--) { s->failed_pc=0x0c0721e8u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'*');
goto P_0c0721ea;
P_0c0721ea: /* original f42b, guest PC 0x0c0721ea */
if(!s->budget--) { s->failed_pc=0x0c0721eau; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c0721ec;
P_0c0721ec: /* original f41b, guest PC 0x0c0721ec */
if(!s->budget--) { s->failed_pc=0x0c0721ecu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c0721ee;
P_0c0721ee: /* original f40b, guest PC 0x0c0721ee */
if(!s->budget--) { s->failed_pc=0x0c0721eeu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c0721f0;
P_0c0721f0: /* original 64f3, guest PC 0x0c0721f0 */
if(!s->budget--) { s->failed_pc=0x0c0721f0u; return 0; }
r[4]=r[15];
goto P_0c0721f2;
P_0c0721f2: /* original 7418, guest PC 0x0c0721f2 */
if(!s->budget--) { s->failed_pc=0x0c0721f2u; return 0; }
r[4]+=0x00000018u;
goto P_0c0721f4;
P_0c0721f4: /* original f049, guest PC 0x0c0721f4 */
if(!s->budget--) { s->failed_pc=0x0c0721f4u; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c0721f6;
P_0c0721f6: /* original f149, guest PC 0x0c0721f6 */
if(!s->budget--) { s->failed_pc=0x0c0721f6u; return 0; }
vf3_matrix_load(s,ram,1,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c0721f8;
P_0c0721f8: /* original f249, guest PC 0x0c0721f8 */
if(!s->budget--) { s->failed_pc=0x0c0721f8u; return 0; }
vf3_matrix_load(s,ram,2,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c0721fa;
P_0c0721fa: /* original f38d, guest PC 0x0c0721fa */
if(!s->budget--) { s->failed_pc=0x0c0721fau; return 0; }
fr[3]=0;
goto P_0c0721fc;
P_0c0721fc: /* original f0ed, guest PC 0x0c0721fc */
if(!s->budget--) { s->failed_pc=0x0c0721fcu; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+0,r[18],fr+3)) goto unsupported;
goto P_0c0721fe;
P_0c0721fe: /* original f37d, guest PC 0x0c0721fe */
if(!s->budget--) { s->failed_pc=0x0c0721feu; return 0; }
if(!vf3_fpu_fsrra(fr[3],r[18],&fr[3])) goto unsupported;
goto P_0c072200;
P_0c072200: /* original f232, guest PC 0x0c072200 */
if(!s->budget--) { s->failed_pc=0x0c072200u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c072202;
P_0c072202: /* original f132, guest PC 0x0c072202 */
if(!s->budget--) { s->failed_pc=0x0c072202u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[3],r[18],'*');
goto P_0c072204;
P_0c072204: /* original f032, guest PC 0x0c072204 */
if(!s->budget--) { s->failed_pc=0x0c072204u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'*');
goto P_0c072206;
P_0c072206: /* original f42b, guest PC 0x0c072206 */
if(!s->budget--) { s->failed_pc=0x0c072206u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c072208;
P_0c072208: /* original f41b, guest PC 0x0c072208 */
if(!s->budget--) { s->failed_pc=0x0c072208u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c07220a;
P_0c07220a: /* original f40b, guest PC 0x0c07220a */
if(!s->budget--) { s->failed_pc=0x0c07220au; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c07220c;
P_0c07220c: /* original 65f3, guest PC 0x0c07220c */
if(!s->budget--) { s->failed_pc=0x0c07220cu; return 0; }
r[5]=r[15];
goto P_0c07220e;
P_0c07220e: /* original 64e3, guest PC 0x0c07220e */
if(!s->budget--) { s->failed_pc=0x0c07220eu; return 0; }
r[4]=r[14];
goto P_0c072210;
P_0c072210: /* original 66f3, guest PC 0x0c072210 */
if(!s->budget--) { s->failed_pc=0x0c072210u; return 0; }
r[6]=r[15];
goto P_0c072212;
P_0c072212: /* original 740c, guest PC 0x0c072212 */
if(!s->budget--) { s->failed_pc=0x0c072212u; return 0; }
r[4]+=0x0000000cu;
goto P_0c072214;
P_0c072214: /* original 7618, guest PC 0x0c072214 */
if(!s->budget--) { s->failed_pc=0x0c072214u; return 0; }
r[6]+=0x00000018u;
goto P_0c072216;
P_0c072216: /* original 7524, guest PC 0x0c072216 */
if(!s->budget--) { s->failed_pc=0x0c072216u; return 0; }
r[5]+=0x00000024u;
goto P_0c072218;
P_0c072218: /* original f059, guest PC 0x0c072218 */
if(!s->budget--) { s->failed_pc=0x0c072218u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c07221a;
P_0c07221a: /* original f369, guest PC 0x0c07221a */
if(!s->budget--) { s->failed_pc=0x0c07221au; return 0; }
vf3_matrix_load(s,ram,3,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c07221c;
P_0c07221c: /* original f159, guest PC 0x0c07221c */
if(!s->budget--) { s->failed_pc=0x0c07221cu; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c07221e;
P_0c07221e: /* original f469, guest PC 0x0c07221e */
if(!s->budget--) { s->failed_pc=0x0c07221eu; return 0; }
vf3_matrix_load(s,ram,4,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c072220;
P_0c072220: /* original f259, guest PC 0x0c072220 */
if(!s->budget--) { s->failed_pc=0x0c072220u; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c072222;
P_0c072222: /* original f569, guest PC 0x0c072222 */
if(!s->budget--) { s->failed_pc=0x0c072222u; return 0; }
vf3_matrix_load(s,ram,5,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c072224;
P_0c072224: /* original 740c, guest PC 0x0c072224 */
if(!s->budget--) { s->failed_pc=0x0c072224u; return 0; }
r[4]+=0x0000000cu;
goto P_0c072226;
P_0c072226: /* original f030, guest PC 0x0c072226 */
if(!s->budget--) { s->failed_pc=0x0c072226u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'+');
goto P_0c072228;
P_0c072228: /* original f250, guest PC 0x0c072228 */
if(!s->budget--) { s->failed_pc=0x0c072228u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'+');
goto P_0c07222a;
P_0c07222a: /* original f140, guest PC 0x0c07222a */
if(!s->budget--) { s->failed_pc=0x0c07222au; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'+');
goto P_0c07222c;
P_0c07222c: /* original f42b, guest PC 0x0c07222c */
if(!s->budget--) { s->failed_pc=0x0c07222cu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c07222e;
P_0c07222e: /* original f41b, guest PC 0x0c07222e */
if(!s->budget--) { s->failed_pc=0x0c07222eu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c072230;
P_0c072230: /* original f40b, guest PC 0x0c072230 */
if(!s->budget--) { s->failed_pc=0x0c072230u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c072232;
P_0c072232: /* original 0009, guest PC 0x0c072232 */
if(!s->budget--) { s->failed_pc=0x0c072232u; return 0; }
goto P_0c072234;
P_0c072234: /* original 64e3, guest PC 0x0c072234 */
if(!s->budget--) { s->failed_pc=0x0c072234u; return 0; }
r[4]=r[14];
goto P_0c072236;
P_0c072236: /* original 65e3, guest PC 0x0c072236 */
if(!s->budget--) { s->failed_pc=0x0c072236u; return 0; }
r[5]=r[14];
goto P_0c072238;
P_0c072238: /* original 740c, guest PC 0x0c072238 */
if(!s->budget--) { s->failed_pc=0x0c072238u; return 0; }
r[4]+=0x0000000cu;
goto P_0c07223a;
P_0c07223a: /* original f4fc, guest PC 0x0c07223a */
if(!s->budget--) { s->failed_pc=0x0c07223au; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c07223c;
P_0c07223c: /* original 750c, guest PC 0x0c07223c */
if(!s->budget--) { s->failed_pc=0x0c07223cu; return 0; }
r[5]+=0x0000000cu;
goto P_0c07223e;
P_0c07223e: /* original f059, guest PC 0x0c07223e */
if(!s->budget--) { s->failed_pc=0x0c07223eu; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c072240;
P_0c072240: /* original f159, guest PC 0x0c072240 */
if(!s->budget--) { s->failed_pc=0x0c072240u; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c072242;
P_0c072242: /* original f259, guest PC 0x0c072242 */
if(!s->budget--) { s->failed_pc=0x0c072242u; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c072244;
P_0c072244: /* original f38d, guest PC 0x0c072244 */
if(!s->budget--) { s->failed_pc=0x0c072244u; return 0; }
fr[3]=0;
goto P_0c072246;
P_0c072246: /* original f0ed, guest PC 0x0c072246 */
if(!s->budget--) { s->failed_pc=0x0c072246u; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+0,r[18],fr+3)) goto unsupported;
goto P_0c072248;
P_0c072248: /* original f37d, guest PC 0x0c072248 */
if(!s->budget--) { s->failed_pc=0x0c072248u; return 0; }
if(!vf3_fpu_fsrra(fr[3],r[18],&fr[3])) goto unsupported;
goto P_0c07224a;
P_0c07224a: /* original f342, guest PC 0x0c07224a */
if(!s->budget--) { s->failed_pc=0x0c07224au; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'*');
goto P_0c07224c;
P_0c07224c: /* original 740c, guest PC 0x0c07224c */
if(!s->budget--) { s->failed_pc=0x0c07224cu; return 0; }
r[4]+=0x0000000cu;
goto P_0c07224e;
P_0c07224e: /* original f232, guest PC 0x0c07224e */
if(!s->budget--) { s->failed_pc=0x0c07224eu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c072250;
P_0c072250: /* original f132, guest PC 0x0c072250 */
if(!s->budget--) { s->failed_pc=0x0c072250u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[3],r[18],'*');
goto P_0c072252;
P_0c072252: /* original f032, guest PC 0x0c072252 */
if(!s->budget--) { s->failed_pc=0x0c072252u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'*');
goto P_0c072254;
P_0c072254: /* original f42b, guest PC 0x0c072254 */
if(!s->budget--) { s->failed_pc=0x0c072254u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c072256;
P_0c072256: /* original f41b, guest PC 0x0c072256 */
if(!s->budget--) { s->failed_pc=0x0c072256u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c072258;
P_0c072258: /* original f40b, guest PC 0x0c072258 */
if(!s->budget--) { s->failed_pc=0x0c072258u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c07225a;
P_0c07225a: /* original 0009, guest PC 0x0c07225a */
if(!s->budget--) { s->failed_pc=0x0c07225au; return 0; }
goto P_0c07225c;
P_0c07225c: /* original 2fe2, guest PC 0x0c07225c */
if(!s->budget--) { s->failed_pc=0x0c07225cu; return 0; }
write(ram,r[15],r[14],4);
goto P_0c07225e;
P_0c07225e: /* original e201, guest PC 0x0c07225e */
if(!s->budget--) { s->failed_pc=0x0c07225eu; return 0; }
r[2]=0x00000001u;
goto P_0c072260;
P_0c072260: /* original 53f1, guest PC 0x0c072260 */
if(!s->budget--) { s->failed_pc=0x0c072260u; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c072262;
P_0c072262: /* original 6eb3, guest PC 0x0c072262 */
if(!s->budget--) { s->failed_pc=0x0c072262u; return 0; }
r[14]=r[11];
goto P_0c072264;
P_0c072264: /* original 7b18, guest PC 0x0c072264 */
if(!s->budget--) { s->failed_pc=0x0c072264u; return 0; }
r[11]+=0x00000018u;
goto P_0c072266;
P_0c072266: /* original 73ff, guest PC 0x0c072266 */
if(!s->budget--) { s->failed_pc=0x0c072266u; return 0; }
r[3]+=0xffffffffu;
goto P_0c072268;
P_0c072268: /* original 3327, guest PC 0x0c072268 */
if(!s->budget--) { s->failed_pc=0x0c072268u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>(int32_t)r[2])!=0);
goto P_0c07226a;
P_0c07226a: /* original 7918, guest PC 0x0c07226a */
if(!s->budget--) { s->failed_pc=0x0c07226au; return 0; }
r[9]+=0x00000018u;
goto P_0c07226c;
P_0c07226c: /* original 8f03, guest PC 0x0c07226c */
if(!s->budget--) { s->failed_pc=0x0c07226cu; return 0; }
cond=r[17]&1u;
write(ram,r[15]+4,r[3],4);
if(!cond) { goto P_0c072276; }
goto P_0c072270;
P_0c07226e: /* original 1f31, guest PC 0x0c07226e */
if(!s->budget--) { s->failed_pc=0x0c07226eu; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c072270;
P_0c072270: /* original d103, guest PC 0x0c072270 */
if(!s->budget--) { s->failed_pc=0x0c072270u; return 0; }
r[1]=read(ram,0x0c072280u,4);
goto P_0c072272;
P_0c072272: /* original 412b, guest PC 0x0c072272 */
if(!s->budget--) { s->failed_pc=0x0c072272u; return 0; }
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
P_0c072274: /* original 0009, guest PC 0x0c072274 */
if(!s->budget--) { s->failed_pc=0x0c072274u; return 0; }
goto P_0c072276;
P_0c072276: /* original 65f2, guest PC 0x0c072276 */
if(!s->budget--) { s->failed_pc=0x0c072276u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c072278;
P_0c072278: /* original 64d3, guest PC 0x0c072278 */
if(!s->budget--) { s->failed_pc=0x0c072278u; return 0; }
r[4]=r[13];
goto P_0c07227a;
P_0c07227a: /* original 66e3, guest PC 0x0c07227a */
if(!s->budget--) { s->failed_pc=0x0c07227au; return 0; }
r[6]=r[14];
goto P_0c07227c;
P_0c07227c: /* original a002, guest PC 0x0c07227c */
if(!s->budget--) { s->failed_pc=0x0c07227cu; return 0; }
goto P_0c072284;
P_0c07227e: /* original 0009, guest PC 0x0c07227e */
if(!s->budget--) { s->failed_pc=0x0c07227eu; return 0; }
return vf3_matrix_family(0x0c072280u,s,ram);
P_0c072284: /* original f059, guest PC 0x0c072284 */
if(!s->budget--) { s->failed_pc=0x0c072284u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c072286;
P_0c072286: /* original f369, guest PC 0x0c072286 */
if(!s->budget--) { s->failed_pc=0x0c072286u; return 0; }
vf3_matrix_load(s,ram,3,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c072288;
P_0c072288: /* original f159, guest PC 0x0c072288 */
if(!s->budget--) { s->failed_pc=0x0c072288u; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c07228a;
P_0c07228a: /* original f469, guest PC 0x0c07228a */
if(!s->budget--) { s->failed_pc=0x0c07228au; return 0; }
vf3_matrix_load(s,ram,4,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c07228c;
P_0c07228c: /* original f031, guest PC 0x0c07228c */
if(!s->budget--) { s->failed_pc=0x0c07228cu; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'-');
goto P_0c07228e;
P_0c07228e: /* original f258, guest PC 0x0c07228e */
if(!s->budget--) { s->failed_pc=0x0c07228eu; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
goto P_0c072290;
P_0c072290: /* original f568, guest PC 0x0c072290 */
if(!s->budget--) { s->failed_pc=0x0c072290u; return 0; }
vf3_matrix_load(s,ram,5,r[6]);
goto P_0c072292;
P_0c072292: /* original f141, guest PC 0x0c072292 */
if(!s->budget--) { s->failed_pc=0x0c072292u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'-');
goto P_0c072294;
P_0c072294: /* original f251, guest PC 0x0c072294 */
if(!s->budget--) { s->failed_pc=0x0c072294u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'-');
goto P_0c072296;
P_0c072296: /* original 7408, guest PC 0x0c072296 */
if(!s->budget--) { s->failed_pc=0x0c072296u; return 0; }
r[4]+=0x00000008u;
goto P_0c072298;
P_0c072298: /* original f42a, guest PC 0x0c072298 */
if(!s->budget--) { s->failed_pc=0x0c072298u; return 0; }
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c07229a;
P_0c07229a: /* original f41b, guest PC 0x0c07229a */
if(!s->budget--) { s->failed_pc=0x0c07229au; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c07229c;
P_0c07229c: /* original f40b, guest PC 0x0c07229c */
if(!s->budget--) { s->failed_pc=0x0c07229cu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c07229e;
P_0c07229e: /* original 0009, guest PC 0x0c07229e */
if(!s->budget--) { s->failed_pc=0x0c07229eu; return 0; }
goto P_0c0722a0;
P_0c0722a0: /* original 64a3, guest PC 0x0c0722a0 */
if(!s->budget--) { s->failed_pc=0x0c0722a0u; return 0; }
r[4]=r[10];
goto P_0c0722a2;
P_0c0722a2: /* original 6593, guest PC 0x0c0722a2 */
if(!s->budget--) { s->failed_pc=0x0c0722a2u; return 0; }
r[5]=r[9];
goto P_0c0722a4;
P_0c0722a4: /* original 66e3, guest PC 0x0c0722a4 */
if(!s->budget--) { s->failed_pc=0x0c0722a4u; return 0; }
r[6]=r[14];
goto P_0c0722a6;
P_0c0722a6: /* original f059, guest PC 0x0c0722a6 */
if(!s->budget--) { s->failed_pc=0x0c0722a6u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0722a8;
P_0c0722a8: /* original f369, guest PC 0x0c0722a8 */
if(!s->budget--) { s->failed_pc=0x0c0722a8u; return 0; }
vf3_matrix_load(s,ram,3,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c0722aa;
P_0c0722aa: /* original f159, guest PC 0x0c0722aa */
if(!s->budget--) { s->failed_pc=0x0c0722aau; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0722ac;
P_0c0722ac: /* original f469, guest PC 0x0c0722ac */
if(!s->budget--) { s->failed_pc=0x0c0722acu; return 0; }
vf3_matrix_load(s,ram,4,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c0722ae;
P_0c0722ae: /* original f031, guest PC 0x0c0722ae */
if(!s->budget--) { s->failed_pc=0x0c0722aeu; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'-');
goto P_0c0722b0;
P_0c0722b0: /* original f258, guest PC 0x0c0722b0 */
if(!s->budget--) { s->failed_pc=0x0c0722b0u; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
goto P_0c0722b2;
P_0c0722b2: /* original f568, guest PC 0x0c0722b2 */
if(!s->budget--) { s->failed_pc=0x0c0722b2u; return 0; }
vf3_matrix_load(s,ram,5,r[6]);
goto P_0c0722b4;
P_0c0722b4: /* original f141, guest PC 0x0c0722b4 */
if(!s->budget--) { s->failed_pc=0x0c0722b4u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'-');
goto P_0c0722b6;
P_0c0722b6: /* original f251, guest PC 0x0c0722b6 */
if(!s->budget--) { s->failed_pc=0x0c0722b6u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'-');
goto P_0c0722b8;
P_0c0722b8: /* original 7408, guest PC 0x0c0722b8 */
if(!s->budget--) { s->failed_pc=0x0c0722b8u; return 0; }
r[4]+=0x00000008u;
goto P_0c0722ba;
P_0c0722ba: /* original f42a, guest PC 0x0c0722ba */
if(!s->budget--) { s->failed_pc=0x0c0722bau; return 0; }
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c0722bc;
P_0c0722bc: /* original f41b, guest PC 0x0c0722bc */
if(!s->budget--) { s->failed_pc=0x0c0722bcu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c0722be;
P_0c0722be: /* original f40b, guest PC 0x0c0722be */
if(!s->budget--) { s->failed_pc=0x0c0722beu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c0722c0;
P_0c0722c0: /* original 66e3, guest PC 0x0c0722c0 */
if(!s->budget--) { s->failed_pc=0x0c0722c0u; return 0; }
r[6]=r[14];
goto P_0c0722c2;
P_0c0722c2: /* original 64a3, guest PC 0x0c0722c2 */
if(!s->budget--) { s->failed_pc=0x0c0722c2u; return 0; }
r[4]=r[10];
goto P_0c0722c4;
P_0c0722c4: /* original 65d3, guest PC 0x0c0722c4 */
if(!s->budget--) { s->failed_pc=0x0c0722c4u; return 0; }
r[5]=r[13];
goto P_0c0722c6;
P_0c0722c6: /* original 760c, guest PC 0x0c0722c6 */
if(!s->budget--) { s->failed_pc=0x0c0722c6u; return 0; }
r[6]+=0x0000000cu;
goto P_0c0722c8;
P_0c0722c8: /* original f049, guest PC 0x0c0722c8 */
if(!s->budget--) { s->failed_pc=0x0c0722c8u; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c0722ca;
P_0c0722ca: /* original f549, guest PC 0x0c0722ca */
if(!s->budget--) { s->failed_pc=0x0c0722cau; return 0; }
vf3_matrix_load(s,ram,5,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c0722cc;
P_0c0722cc: /* original f648, guest PC 0x0c0722cc */
if(!s->budget--) { s->failed_pc=0x0c0722ccu; return 0; }
vf3_matrix_load(s,ram,6,r[4]);
goto P_0c0722ce;
P_0c0722ce: /* original f859, guest PC 0x0c0722ce */
if(!s->budget--) { s->failed_pc=0x0c0722ceu; return 0; }
vf3_matrix_load(s,ram,8,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0722d0;
P_0c0722d0: /* original f959, guest PC 0x0c0722d0 */
if(!s->budget--) { s->failed_pc=0x0c0722d0u; return 0; }
vf3_matrix_load(s,ram,9,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0722d2;
P_0c0722d2: /* original fa58, guest PC 0x0c0722d2 */
if(!s->budget--) { s->failed_pc=0x0c0722d2u; return 0; }
vf3_matrix_load(s,ram,10,r[5]);
goto P_0c0722d4;
P_0c0722d4: /* original 760c, guest PC 0x0c0722d4 */
if(!s->budget--) { s->failed_pc=0x0c0722d4u; return 0; }
r[6]+=0x0000000cu;
goto P_0c0722d6;
P_0c0722d6: /* original f35c, guest PC 0x0c0722d6 */
if(!s->budget--) { s->failed_pc=0x0c0722d6u; return 0; }
vf3_matrix_move(s,3,5);
goto P_0c0722d8;
P_0c0722d8: /* original f382, guest PC 0x0c0722d8 */
if(!s->budget--) { s->failed_pc=0x0c0722d8u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[8],r[18],'*');
goto P_0c0722da;
P_0c0722da: /* original f20c, guest PC 0x0c0722da */
if(!s->budget--) { s->failed_pc=0x0c0722dau; return 0; }
vf3_matrix_move(s,2,0);
goto P_0c0722dc;
P_0c0722dc: /* original f2a2, guest PC 0x0c0722dc */
if(!s->budget--) { s->failed_pc=0x0c0722dcu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[10],r[18],'*');
goto P_0c0722de;
P_0c0722de: /* original f16c, guest PC 0x0c0722de */
if(!s->budget--) { s->failed_pc=0x0c0722deu; return 0; }
vf3_matrix_move(s,1,6);
goto P_0c0722e0;
P_0c0722e0: /* original f192, guest PC 0x0c0722e0 */
if(!s->budget--) { s->failed_pc=0x0c0722e0u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[9],r[18],'*');
goto P_0c0722e2;
P_0c0722e2: /* original f34d, guest PC 0x0c0722e2 */
if(!s->budget--) { s->failed_pc=0x0c0722e2u; return 0; }
fr[3]^=0x80000000u;
goto P_0c0722e4;
P_0c0722e4: /* original f39e, guest PC 0x0c0722e4 */
if(!s->budget--) { s->failed_pc=0x0c0722e4u; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[9],fr[3],r[18]);
goto P_0c0722e6;
P_0c0722e6: /* original f24d, guest PC 0x0c0722e6 */
if(!s->budget--) { s->failed_pc=0x0c0722e6u; return 0; }
fr[2]^=0x80000000u;
goto P_0c0722e8;
P_0c0722e8: /* original f06c, guest PC 0x0c0722e8 */
if(!s->budget--) { s->failed_pc=0x0c0722e8u; return 0; }
vf3_matrix_move(s,0,6);
goto P_0c0722ea;
P_0c0722ea: /* original f28e, guest PC 0x0c0722ea */
if(!s->budget--) { s->failed_pc=0x0c0722eau; return 0; }
fr[2]=vf3_fpu_mac(fr[0],fr[8],fr[2],r[18]);
goto P_0c0722ec;
P_0c0722ec: /* original f14d, guest PC 0x0c0722ec */
if(!s->budget--) { s->failed_pc=0x0c0722ecu; return 0; }
fr[1]^=0x80000000u;
goto P_0c0722ee;
P_0c0722ee: /* original f63b, guest PC 0x0c0722ee */
if(!s->budget--) { s->failed_pc=0x0c0722eeu; return 0; }
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,3,r[6]);
goto P_0c0722f0;
P_0c0722f0: /* original f05c, guest PC 0x0c0722f0 */
if(!s->budget--) { s->failed_pc=0x0c0722f0u; return 0; }
vf3_matrix_move(s,0,5);
goto P_0c0722f2;
P_0c0722f2: /* original f1ae, guest PC 0x0c0722f2 */
if(!s->budget--) { s->failed_pc=0x0c0722f2u; return 0; }
fr[1]=vf3_fpu_mac(fr[0],fr[10],fr[1],r[18]);
goto P_0c0722f4;
P_0c0722f4: /* original f62b, guest PC 0x0c0722f4 */
if(!s->budget--) { s->failed_pc=0x0c0722f4u; return 0; }
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[6]);
goto P_0c0722f6;
P_0c0722f6: /* original f61b, guest PC 0x0c0722f6 */
if(!s->budget--) { s->failed_pc=0x0c0722f6u; return 0; }
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[6]);
goto P_0c0722f8;
P_0c0722f8: /* original 64e3, guest PC 0x0c0722f8 */
if(!s->budget--) { s->failed_pc=0x0c0722f8u; return 0; }
r[4]=r[14];
goto P_0c0722fa;
P_0c0722fa: /* original 65e3, guest PC 0x0c0722fa */
if(!s->budget--) { s->failed_pc=0x0c0722fau; return 0; }
r[5]=r[14];
goto P_0c0722fc;
P_0c0722fc: /* original 740c, guest PC 0x0c0722fc */
if(!s->budget--) { s->failed_pc=0x0c0722fcu; return 0; }
r[4]+=0x0000000cu;
goto P_0c0722fe;
P_0c0722fe: /* original f4fc, guest PC 0x0c0722fe */
if(!s->budget--) { s->failed_pc=0x0c0722feu; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c072300;
P_0c072300: /* original 750c, guest PC 0x0c072300 */
if(!s->budget--) { s->failed_pc=0x0c072300u; return 0; }
r[5]+=0x0000000cu;
goto P_0c072302;
P_0c072302: /* original f059, guest PC 0x0c072302 */
if(!s->budget--) { s->failed_pc=0x0c072302u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c072304;
P_0c072304: /* original f159, guest PC 0x0c072304 */
if(!s->budget--) { s->failed_pc=0x0c072304u; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c072306;
P_0c072306: /* original f259, guest PC 0x0c072306 */
if(!s->budget--) { s->failed_pc=0x0c072306u; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c072308;
P_0c072308: /* original f38d, guest PC 0x0c072308 */
if(!s->budget--) { s->failed_pc=0x0c072308u; return 0; }
fr[3]=0;
goto P_0c07230a;
P_0c07230a: /* original f0ed, guest PC 0x0c07230a */
if(!s->budget--) { s->failed_pc=0x0c07230au; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+0,r[18],fr+3)) goto unsupported;
goto P_0c07230c;
P_0c07230c: /* original f37d, guest PC 0x0c07230c */
if(!s->budget--) { s->failed_pc=0x0c07230cu; return 0; }
if(!vf3_fpu_fsrra(fr[3],r[18],&fr[3])) goto unsupported;
goto P_0c07230e;
P_0c07230e: /* original f342, guest PC 0x0c07230e */
if(!s->budget--) { s->failed_pc=0x0c07230eu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'*');
goto P_0c072310;
P_0c072310: /* original 740c, guest PC 0x0c072310 */
if(!s->budget--) { s->failed_pc=0x0c072310u; return 0; }
r[4]+=0x0000000cu;
goto P_0c072312;
P_0c072312: /* original f232, guest PC 0x0c072312 */
if(!s->budget--) { s->failed_pc=0x0c072312u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c072314;
P_0c072314: /* original f132, guest PC 0x0c072314 */
if(!s->budget--) { s->failed_pc=0x0c072314u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[3],r[18],'*');
goto P_0c072316;
P_0c072316: /* original f032, guest PC 0x0c072316 */
if(!s->budget--) { s->failed_pc=0x0c072316u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'*');
goto P_0c072318;
P_0c072318: /* original f42b, guest PC 0x0c072318 */
if(!s->budget--) { s->failed_pc=0x0c072318u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c07231a;
P_0c07231a: /* original f41b, guest PC 0x0c07231a */
if(!s->budget--) { s->failed_pc=0x0c07231au; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c07231c;
P_0c07231c: /* original f40b, guest PC 0x0c07231c */
if(!s->budget--) { s->failed_pc=0x0c07231cu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c07231e;
P_0c07231e: /* original 0009, guest PC 0x0c07231e */
if(!s->budget--) { s->failed_pc=0x0c07231eu; return 0; }
goto P_0c072320;
P_0c072320: /* original 53f2, guest PC 0x0c072320 */
if(!s->budget--) { s->failed_pc=0x0c072320u; return 0; }
r[3]=read(ram,r[15]+8,4);
goto P_0c072322;
P_0c072322: /* original 62f3, guest PC 0x0c072322 */
if(!s->budget--) { s->failed_pc=0x0c072322u; return 0; }
r[2]=r[15];
goto P_0c072324;
P_0c072324: /* original 6eb3, guest PC 0x0c072324 */
if(!s->budget--) { s->failed_pc=0x0c072324u; return 0; }
r[14]=r[11];
goto P_0c072326;
P_0c072326: /* original 7254, guest PC 0x0c072326 */
if(!s->budget--) { s->failed_pc=0x0c072326u; return 0; }
r[2]+=0x00000054u;
goto P_0c072328;
P_0c072328: /* original 73ff, guest PC 0x0c072328 */
if(!s->budget--) { s->failed_pc=0x0c072328u; return 0; }
r[3]+=0xffffffffu;
goto P_0c07232a;
P_0c07232a: /* original 7b18, guest PC 0x0c07232a */
if(!s->budget--) { s->failed_pc=0x0c07232au; return 0; }
r[11]+=0x00000018u;
goto P_0c07232c;
P_0c07232c: /* original 1f34, guest PC 0x0c07232c */
if(!s->budget--) { s->failed_pc=0x0c07232cu; return 0; }
write(ram,r[15]+16,r[3],4);
goto P_0c07232e;
P_0c07232e: /* original d104, guest PC 0x0c07232e */
if(!s->budget--) { s->failed_pc=0x0c07232eu; return 0; }
r[1]=read(ram,0x0c072340u,4);
goto P_0c072330;
P_0c072330: /* original 7918, guest PC 0x0c072330 */
if(!s->budget--) { s->failed_pc=0x0c072330u; return 0; }
r[9]+=0x00000018u;
goto P_0c072332;
P_0c072332: /* original 412b, guest PC 0x0c072332 */
if(!s->budget--) { s->failed_pc=0x0c072332u; return 0; }
target=r[1];
write(ram,r[15]+8,r[2],4);
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
P_0c072334: /* original 1f22, guest PC 0x0c072334 */
if(!s->budget--) { s->failed_pc=0x0c072334u; return 0; }
write(ram,r[15]+8,r[2],4);
return vf3_matrix_family(0x0c072336u,s,ram);
P_0c07239e: /* original f40b, guest PC 0x0c07239e */
if(!s->budget--) { s->failed_pc=0x0c07239eu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c0723a0;
P_0c0723a0: /* original 66f3, guest PC 0x0c0723a0 */
if(!s->budget--) { s->failed_pc=0x0c0723a0u; return 0; }
r[6]=r[15];
goto P_0c0723a2;
P_0c0723a2: /* original 64d3, guest PC 0x0c0723a2 */
if(!s->budget--) { s->failed_pc=0x0c0723a2u; return 0; }
r[4]=r[13];
goto P_0c0723a4;
P_0c0723a4: /* original 65a3, guest PC 0x0c0723a4 */
if(!s->budget--) { s->failed_pc=0x0c0723a4u; return 0; }
r[5]=r[10];
goto P_0c0723a6;
P_0c0723a6: /* original 7624, guest PC 0x0c0723a6 */
if(!s->budget--) { s->failed_pc=0x0c0723a6u; return 0; }
r[6]+=0x00000024u;
goto P_0c0723a8;
P_0c0723a8: /* original f049, guest PC 0x0c0723a8 */
if(!s->budget--) { s->failed_pc=0x0c0723a8u; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c0723aa;
P_0c0723aa: /* original f549, guest PC 0x0c0723aa */
if(!s->budget--) { s->failed_pc=0x0c0723aau; return 0; }
vf3_matrix_load(s,ram,5,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c0723ac;
P_0c0723ac: /* original f648, guest PC 0x0c0723ac */
if(!s->budget--) { s->failed_pc=0x0c0723acu; return 0; }
vf3_matrix_load(s,ram,6,r[4]);
goto P_0c0723ae;
P_0c0723ae: /* original f859, guest PC 0x0c0723ae */
if(!s->budget--) { s->failed_pc=0x0c0723aeu; return 0; }
vf3_matrix_load(s,ram,8,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0723b0;
P_0c0723b0: /* original f959, guest PC 0x0c0723b0 */
if(!s->budget--) { s->failed_pc=0x0c0723b0u; return 0; }
vf3_matrix_load(s,ram,9,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0723b2;
P_0c0723b2: /* original fa58, guest PC 0x0c0723b2 */
if(!s->budget--) { s->failed_pc=0x0c0723b2u; return 0; }
vf3_matrix_load(s,ram,10,r[5]);
goto P_0c0723b4;
P_0c0723b4: /* original 760c, guest PC 0x0c0723b4 */
if(!s->budget--) { s->failed_pc=0x0c0723b4u; return 0; }
r[6]+=0x0000000cu;
goto P_0c0723b6;
P_0c0723b6: /* original f35c, guest PC 0x0c0723b6 */
if(!s->budget--) { s->failed_pc=0x0c0723b6u; return 0; }
vf3_matrix_move(s,3,5);
goto P_0c0723b8;
P_0c0723b8: /* original f382, guest PC 0x0c0723b8 */
if(!s->budget--) { s->failed_pc=0x0c0723b8u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[8],r[18],'*');
goto P_0c0723ba;
P_0c0723ba: /* original f20c, guest PC 0x0c0723ba */
if(!s->budget--) { s->failed_pc=0x0c0723bau; return 0; }
vf3_matrix_move(s,2,0);
goto P_0c0723bc;
P_0c0723bc: /* original f2a2, guest PC 0x0c0723bc */
if(!s->budget--) { s->failed_pc=0x0c0723bcu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[10],r[18],'*');
goto P_0c0723be;
P_0c0723be: /* original f16c, guest PC 0x0c0723be */
if(!s->budget--) { s->failed_pc=0x0c0723beu; return 0; }
vf3_matrix_move(s,1,6);
goto P_0c0723c0;
P_0c0723c0: /* original f192, guest PC 0x0c0723c0 */
if(!s->budget--) { s->failed_pc=0x0c0723c0u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[9],r[18],'*');
goto P_0c0723c2;
P_0c0723c2: /* original f34d, guest PC 0x0c0723c2 */
if(!s->budget--) { s->failed_pc=0x0c0723c2u; return 0; }
fr[3]^=0x80000000u;
goto P_0c0723c4;
P_0c0723c4: /* original f39e, guest PC 0x0c0723c4 */
if(!s->budget--) { s->failed_pc=0x0c0723c4u; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[9],fr[3],r[18]);
goto P_0c0723c6;
P_0c0723c6: /* original f24d, guest PC 0x0c0723c6 */
if(!s->budget--) { s->failed_pc=0x0c0723c6u; return 0; }
fr[2]^=0x80000000u;
goto P_0c0723c8;
P_0c0723c8: /* original f06c, guest PC 0x0c0723c8 */
if(!s->budget--) { s->failed_pc=0x0c0723c8u; return 0; }
vf3_matrix_move(s,0,6);
goto P_0c0723ca;
P_0c0723ca: /* original f28e, guest PC 0x0c0723ca */
if(!s->budget--) { s->failed_pc=0x0c0723cau; return 0; }
fr[2]=vf3_fpu_mac(fr[0],fr[8],fr[2],r[18]);
goto P_0c0723cc;
P_0c0723cc: /* original f14d, guest PC 0x0c0723cc */
if(!s->budget--) { s->failed_pc=0x0c0723ccu; return 0; }
fr[1]^=0x80000000u;
goto P_0c0723ce;
P_0c0723ce: /* original f63b, guest PC 0x0c0723ce */
if(!s->budget--) { s->failed_pc=0x0c0723ceu; return 0; }
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,3,r[6]);
goto P_0c0723d0;
P_0c0723d0: /* original f05c, guest PC 0x0c0723d0 */
if(!s->budget--) { s->failed_pc=0x0c0723d0u; return 0; }
vf3_matrix_move(s,0,5);
goto P_0c0723d2;
P_0c0723d2: /* original f1ae, guest PC 0x0c0723d2 */
if(!s->budget--) { s->failed_pc=0x0c0723d2u; return 0; }
fr[1]=vf3_fpu_mac(fr[0],fr[10],fr[1],r[18]);
goto P_0c0723d4;
P_0c0723d4: /* original f62b, guest PC 0x0c0723d4 */
if(!s->budget--) { s->failed_pc=0x0c0723d4u; return 0; }
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[6]);
goto P_0c0723d6;
P_0c0723d6: /* original f61b, guest PC 0x0c0723d6 */
if(!s->budget--) { s->failed_pc=0x0c0723d6u; return 0; }
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[6]);
goto P_0c0723d8;
P_0c0723d8: /* original 66f3, guest PC 0x0c0723d8 */
if(!s->budget--) { s->failed_pc=0x0c0723d8u; return 0; }
r[6]=r[15];
goto P_0c0723da;
P_0c0723da: /* original 64c3, guest PC 0x0c0723da */
if(!s->budget--) { s->failed_pc=0x0c0723dau; return 0; }
r[4]=r[12];
goto P_0c0723dc;
P_0c0723dc: /* original 65d3, guest PC 0x0c0723dc */
if(!s->budget--) { s->failed_pc=0x0c0723dcu; return 0; }
r[5]=r[13];
goto P_0c0723de;
P_0c0723de: /* original 7618, guest PC 0x0c0723de */
if(!s->budget--) { s->failed_pc=0x0c0723deu; return 0; }
r[6]+=0x00000018u;
goto P_0c0723e0;
P_0c0723e0: /* original f049, guest PC 0x0c0723e0 */
if(!s->budget--) { s->failed_pc=0x0c0723e0u; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c0723e2;
P_0c0723e2: /* original f549, guest PC 0x0c0723e2 */
if(!s->budget--) { s->failed_pc=0x0c0723e2u; return 0; }
vf3_matrix_load(s,ram,5,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c0723e4;
P_0c0723e4: /* original f648, guest PC 0x0c0723e4 */
if(!s->budget--) { s->failed_pc=0x0c0723e4u; return 0; }
vf3_matrix_load(s,ram,6,r[4]);
goto P_0c0723e6;
P_0c0723e6: /* original f859, guest PC 0x0c0723e6 */
if(!s->budget--) { s->failed_pc=0x0c0723e6u; return 0; }
vf3_matrix_load(s,ram,8,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0723e8;
P_0c0723e8: /* original f959, guest PC 0x0c0723e8 */
if(!s->budget--) { s->failed_pc=0x0c0723e8u; return 0; }
vf3_matrix_load(s,ram,9,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0723ea;
P_0c0723ea: /* original fa58, guest PC 0x0c0723ea */
if(!s->budget--) { s->failed_pc=0x0c0723eau; return 0; }
vf3_matrix_load(s,ram,10,r[5]);
goto P_0c0723ec;
P_0c0723ec: /* original 760c, guest PC 0x0c0723ec */
if(!s->budget--) { s->failed_pc=0x0c0723ecu; return 0; }
r[6]+=0x0000000cu;
goto P_0c0723ee;
P_0c0723ee: /* original f35c, guest PC 0x0c0723ee */
if(!s->budget--) { s->failed_pc=0x0c0723eeu; return 0; }
vf3_matrix_move(s,3,5);
goto P_0c0723f0;
P_0c0723f0: /* original f382, guest PC 0x0c0723f0 */
if(!s->budget--) { s->failed_pc=0x0c0723f0u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[8],r[18],'*');
goto P_0c0723f2;
P_0c0723f2: /* original f20c, guest PC 0x0c0723f2 */
if(!s->budget--) { s->failed_pc=0x0c0723f2u; return 0; }
vf3_matrix_move(s,2,0);
goto P_0c0723f4;
P_0c0723f4: /* original f2a2, guest PC 0x0c0723f4 */
if(!s->budget--) { s->failed_pc=0x0c0723f4u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[10],r[18],'*');
goto P_0c0723f6;
P_0c0723f6: /* original f16c, guest PC 0x0c0723f6 */
if(!s->budget--) { s->failed_pc=0x0c0723f6u; return 0; }
vf3_matrix_move(s,1,6);
goto P_0c0723f8;
P_0c0723f8: /* original f192, guest PC 0x0c0723f8 */
if(!s->budget--) { s->failed_pc=0x0c0723f8u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[9],r[18],'*');
goto P_0c0723fa;
P_0c0723fa: /* original f34d, guest PC 0x0c0723fa */
if(!s->budget--) { s->failed_pc=0x0c0723fau; return 0; }
fr[3]^=0x80000000u;
goto P_0c0723fc;
P_0c0723fc: /* original f39e, guest PC 0x0c0723fc */
if(!s->budget--) { s->failed_pc=0x0c0723fcu; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[9],fr[3],r[18]);
goto P_0c0723fe;
P_0c0723fe: /* original f24d, guest PC 0x0c0723fe */
if(!s->budget--) { s->failed_pc=0x0c0723feu; return 0; }
fr[2]^=0x80000000u;
goto P_0c072400;
P_0c072400: /* original f06c, guest PC 0x0c072400 */
if(!s->budget--) { s->failed_pc=0x0c072400u; return 0; }
vf3_matrix_move(s,0,6);
goto P_0c072402;
P_0c072402: /* original f28e, guest PC 0x0c072402 */
if(!s->budget--) { s->failed_pc=0x0c072402u; return 0; }
fr[2]=vf3_fpu_mac(fr[0],fr[8],fr[2],r[18]);
goto P_0c072404;
P_0c072404: /* original f14d, guest PC 0x0c072404 */
if(!s->budget--) { s->failed_pc=0x0c072404u; return 0; }
fr[1]^=0x80000000u;
goto P_0c072406;
P_0c072406: /* original f63b, guest PC 0x0c072406 */
if(!s->budget--) { s->failed_pc=0x0c072406u; return 0; }
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,3,r[6]);
goto P_0c072408;
P_0c072408: /* original f05c, guest PC 0x0c072408 */
if(!s->budget--) { s->failed_pc=0x0c072408u; return 0; }
vf3_matrix_move(s,0,5);
goto P_0c07240a;
P_0c07240a: /* original f1ae, guest PC 0x0c07240a */
if(!s->budget--) { s->failed_pc=0x0c07240au; return 0; }
fr[1]=vf3_fpu_mac(fr[0],fr[10],fr[1],r[18]);
goto P_0c07240c;
P_0c07240c: /* original f62b, guest PC 0x0c07240c */
if(!s->budget--) { s->failed_pc=0x0c07240cu; return 0; }
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[6]);
goto P_0c07240e;
P_0c07240e: /* original f61b, guest PC 0x0c07240e */
if(!s->budget--) { s->failed_pc=0x0c07240eu; return 0; }
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[6]);
goto P_0c072410;
P_0c072410: /* original 64f3, guest PC 0x0c072410 */
if(!s->budget--) { s->failed_pc=0x0c072410u; return 0; }
r[4]=r[15];
goto P_0c072412;
P_0c072412: /* original 7424, guest PC 0x0c072412 */
if(!s->budget--) { s->failed_pc=0x0c072412u; return 0; }
r[4]+=0x00000024u;
goto P_0c072414;
P_0c072414: /* original f049, guest PC 0x0c072414 */
if(!s->budget--) { s->failed_pc=0x0c072414u; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c072416;
P_0c072416: /* original f149, guest PC 0x0c072416 */
if(!s->budget--) { s->failed_pc=0x0c072416u; return 0; }
vf3_matrix_load(s,ram,1,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c072418;
P_0c072418: /* original f249, guest PC 0x0c072418 */
if(!s->budget--) { s->failed_pc=0x0c072418u; return 0; }
vf3_matrix_load(s,ram,2,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c07241a;
P_0c07241a: /* original f38d, guest PC 0x0c07241a */
if(!s->budget--) { s->failed_pc=0x0c07241au; return 0; }
fr[3]=0;
goto P_0c07241c;
P_0c07241c: /* original f0ed, guest PC 0x0c07241c */
if(!s->budget--) { s->failed_pc=0x0c07241cu; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+0,r[18],fr+3)) goto unsupported;
goto P_0c07241e;
P_0c07241e: /* original f37d, guest PC 0x0c07241e */
if(!s->budget--) { s->failed_pc=0x0c07241eu; return 0; }
if(!vf3_fpu_fsrra(fr[3],r[18],&fr[3])) goto unsupported;
goto P_0c072420;
P_0c072420: /* original f232, guest PC 0x0c072420 */
if(!s->budget--) { s->failed_pc=0x0c072420u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c072422;
P_0c072422: /* original f132, guest PC 0x0c072422 */
if(!s->budget--) { s->failed_pc=0x0c072422u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[3],r[18],'*');
goto P_0c072424;
P_0c072424: /* original f032, guest PC 0x0c072424 */
if(!s->budget--) { s->failed_pc=0x0c072424u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'*');
goto P_0c072426;
P_0c072426: /* original f42b, guest PC 0x0c072426 */
if(!s->budget--) { s->failed_pc=0x0c072426u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c072428;
P_0c072428: /* original f41b, guest PC 0x0c072428 */
if(!s->budget--) { s->failed_pc=0x0c072428u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c07242a;
P_0c07242a: /* original f40b, guest PC 0x0c07242a */
if(!s->budget--) { s->failed_pc=0x0c07242au; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c07242c;
P_0c07242c: /* original 64f3, guest PC 0x0c07242c */
if(!s->budget--) { s->failed_pc=0x0c07242cu; return 0; }
r[4]=r[15];
goto P_0c07242e;
P_0c07242e: /* original 7418, guest PC 0x0c07242e */
if(!s->budget--) { s->failed_pc=0x0c07242eu; return 0; }
r[4]+=0x00000018u;
goto P_0c072430;
P_0c072430: /* original f049, guest PC 0x0c072430 */
if(!s->budget--) { s->failed_pc=0x0c072430u; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c072432;
P_0c072432: /* original f149, guest PC 0x0c072432 */
if(!s->budget--) { s->failed_pc=0x0c072432u; return 0; }
vf3_matrix_load(s,ram,1,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c072434;
P_0c072434: /* original f249, guest PC 0x0c072434 */
if(!s->budget--) { s->failed_pc=0x0c072434u; return 0; }
vf3_matrix_load(s,ram,2,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c072436;
P_0c072436: /* original f38d, guest PC 0x0c072436 */
if(!s->budget--) { s->failed_pc=0x0c072436u; return 0; }
fr[3]=0;
goto P_0c072438;
P_0c072438: /* original f0ed, guest PC 0x0c072438 */
if(!s->budget--) { s->failed_pc=0x0c072438u; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+0,r[18],fr+3)) goto unsupported;
goto P_0c07243a;
P_0c07243a: /* original f37d, guest PC 0x0c07243a */
if(!s->budget--) { s->failed_pc=0x0c07243au; return 0; }
if(!vf3_fpu_fsrra(fr[3],r[18],&fr[3])) goto unsupported;
goto P_0c07243c;
P_0c07243c: /* original f232, guest PC 0x0c07243c */
if(!s->budget--) { s->failed_pc=0x0c07243cu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c07243e;
P_0c07243e: /* original f132, guest PC 0x0c07243e */
if(!s->budget--) { s->failed_pc=0x0c07243eu; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[3],r[18],'*');
goto P_0c072440;
P_0c072440: /* original f032, guest PC 0x0c072440 */
if(!s->budget--) { s->failed_pc=0x0c072440u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'*');
goto P_0c072442;
P_0c072442: /* original f42b, guest PC 0x0c072442 */
if(!s->budget--) { s->failed_pc=0x0c072442u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c072444;
P_0c072444: /* original f41b, guest PC 0x0c072444 */
if(!s->budget--) { s->failed_pc=0x0c072444u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c072446;
P_0c072446: /* original f40b, guest PC 0x0c072446 */
if(!s->budget--) { s->failed_pc=0x0c072446u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c072448;
P_0c072448: /* original 65f3, guest PC 0x0c072448 */
if(!s->budget--) { s->failed_pc=0x0c072448u; return 0; }
r[5]=r[15];
goto P_0c07244a;
P_0c07244a: /* original 64e3, guest PC 0x0c07244a */
if(!s->budget--) { s->failed_pc=0x0c07244au; return 0; }
r[4]=r[14];
goto P_0c07244c;
P_0c07244c: /* original 66f3, guest PC 0x0c07244c */
if(!s->budget--) { s->failed_pc=0x0c07244cu; return 0; }
r[6]=r[15];
goto P_0c07244e;
P_0c07244e: /* original 740c, guest PC 0x0c07244e */
if(!s->budget--) { s->failed_pc=0x0c07244eu; return 0; }
r[4]+=0x0000000cu;
goto P_0c072450;
P_0c072450: /* original 7618, guest PC 0x0c072450 */
if(!s->budget--) { s->failed_pc=0x0c072450u; return 0; }
r[6]+=0x00000018u;
goto P_0c072452;
P_0c072452: /* original 7524, guest PC 0x0c072452 */
if(!s->budget--) { s->failed_pc=0x0c072452u; return 0; }
r[5]+=0x00000024u;
goto P_0c072454;
P_0c072454: /* original f059, guest PC 0x0c072454 */
if(!s->budget--) { s->failed_pc=0x0c072454u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c072456;
P_0c072456: /* original f369, guest PC 0x0c072456 */
if(!s->budget--) { s->failed_pc=0x0c072456u; return 0; }
vf3_matrix_load(s,ram,3,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c072458;
P_0c072458: /* original f159, guest PC 0x0c072458 */
if(!s->budget--) { s->failed_pc=0x0c072458u; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c07245a;
P_0c07245a: /* original f469, guest PC 0x0c07245a */
if(!s->budget--) { s->failed_pc=0x0c07245au; return 0; }
vf3_matrix_load(s,ram,4,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c07245c;
P_0c07245c: /* original f259, guest PC 0x0c07245c */
if(!s->budget--) { s->failed_pc=0x0c07245cu; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c07245e;
P_0c07245e: /* original f569, guest PC 0x0c07245e */
if(!s->budget--) { s->failed_pc=0x0c07245eu; return 0; }
vf3_matrix_load(s,ram,5,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c072460;
P_0c072460: /* original 740c, guest PC 0x0c072460 */
if(!s->budget--) { s->failed_pc=0x0c072460u; return 0; }
r[4]+=0x0000000cu;
goto P_0c072462;
P_0c072462: /* original f030, guest PC 0x0c072462 */
if(!s->budget--) { s->failed_pc=0x0c072462u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'+');
goto P_0c072464;
P_0c072464: /* original f250, guest PC 0x0c072464 */
if(!s->budget--) { s->failed_pc=0x0c072464u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'+');
goto P_0c072466;
P_0c072466: /* original f140, guest PC 0x0c072466 */
if(!s->budget--) { s->failed_pc=0x0c072466u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'+');
goto P_0c072468;
P_0c072468: /* original f42b, guest PC 0x0c072468 */
if(!s->budget--) { s->failed_pc=0x0c072468u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c07246a;
P_0c07246a: /* original f41b, guest PC 0x0c07246a */
if(!s->budget--) { s->failed_pc=0x0c07246au; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c07246c;
P_0c07246c: /* original f40b, guest PC 0x0c07246c */
if(!s->budget--) { s->failed_pc=0x0c07246cu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c07246e;
P_0c07246e: /* original 0009, guest PC 0x0c07246e */
if(!s->budget--) { s->failed_pc=0x0c07246eu; return 0; }
goto P_0c072470;
P_0c072470: /* original 64e3, guest PC 0x0c072470 */
if(!s->budget--) { s->failed_pc=0x0c072470u; return 0; }
r[4]=r[14];
goto P_0c072472;
P_0c072472: /* original 65e3, guest PC 0x0c072472 */
if(!s->budget--) { s->failed_pc=0x0c072472u; return 0; }
r[5]=r[14];
goto P_0c072474;
P_0c072474: /* original 740c, guest PC 0x0c072474 */
if(!s->budget--) { s->failed_pc=0x0c072474u; return 0; }
r[4]+=0x0000000cu;
goto P_0c072476;
P_0c072476: /* original f4fc, guest PC 0x0c072476 */
if(!s->budget--) { s->failed_pc=0x0c072476u; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c072478;
P_0c072478: /* original 750c, guest PC 0x0c072478 */
if(!s->budget--) { s->failed_pc=0x0c072478u; return 0; }
r[5]+=0x0000000cu;
goto P_0c07247a;
P_0c07247a: /* original f059, guest PC 0x0c07247a */
if(!s->budget--) { s->failed_pc=0x0c07247au; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c07247c;
P_0c07247c: /* original f159, guest PC 0x0c07247c */
if(!s->budget--) { s->failed_pc=0x0c07247cu; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c07247e;
P_0c07247e: /* original f259, guest PC 0x0c07247e */
if(!s->budget--) { s->failed_pc=0x0c07247eu; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c072480;
P_0c072480: /* original f38d, guest PC 0x0c072480 */
if(!s->budget--) { s->failed_pc=0x0c072480u; return 0; }
fr[3]=0;
goto P_0c072482;
P_0c072482: /* original f0ed, guest PC 0x0c072482 */
if(!s->budget--) { s->failed_pc=0x0c072482u; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+0,r[18],fr+3)) goto unsupported;
goto P_0c072484;
P_0c072484: /* original f37d, guest PC 0x0c072484 */
if(!s->budget--) { s->failed_pc=0x0c072484u; return 0; }
if(!vf3_fpu_fsrra(fr[3],r[18],&fr[3])) goto unsupported;
goto P_0c072486;
P_0c072486: /* original f342, guest PC 0x0c072486 */
if(!s->budget--) { s->failed_pc=0x0c072486u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'*');
goto P_0c072488;
P_0c072488: /* original 740c, guest PC 0x0c072488 */
if(!s->budget--) { s->failed_pc=0x0c072488u; return 0; }
r[4]+=0x0000000cu;
goto P_0c07248a;
P_0c07248a: /* original f232, guest PC 0x0c07248a */
if(!s->budget--) { s->failed_pc=0x0c07248au; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c07248c;
P_0c07248c: /* original f132, guest PC 0x0c07248c */
if(!s->budget--) { s->failed_pc=0x0c07248cu; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[3],r[18],'*');
goto P_0c07248e;
P_0c07248e: /* original f032, guest PC 0x0c07248e */
if(!s->budget--) { s->failed_pc=0x0c07248eu; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'*');
goto P_0c072490;
P_0c072490: /* original f42b, guest PC 0x0c072490 */
if(!s->budget--) { s->failed_pc=0x0c072490u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c072492;
P_0c072492: /* original f41b, guest PC 0x0c072492 */
if(!s->budget--) { s->failed_pc=0x0c072492u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c072494;
P_0c072494: /* original f40b, guest PC 0x0c072494 */
if(!s->budget--) { s->failed_pc=0x0c072494u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c072496;
P_0c072496: /* original 0009, guest PC 0x0c072496 */
if(!s->budget--) { s->failed_pc=0x0c072496u; return 0; }
goto P_0c072498;
P_0c072498: /* original 2fe2, guest PC 0x0c072498 */
if(!s->budget--) { s->failed_pc=0x0c072498u; return 0; }
write(ram,r[15],r[14],4);
goto P_0c07249a;
P_0c07249a: /* original 6eb3, guest PC 0x0c07249a */
if(!s->budget--) { s->failed_pc=0x0c07249au; return 0; }
r[14]=r[11];
goto P_0c07249c;
P_0c07249c: /* original 53f5, guest PC 0x0c07249c */
if(!s->budget--) { s->failed_pc=0x0c07249cu; return 0; }
r[3]=read(ram,r[15]+20,4);
goto P_0c07249e;
P_0c07249e: /* original e201, guest PC 0x0c07249e */
if(!s->budget--) { s->failed_pc=0x0c07249eu; return 0; }
r[2]=0x00000001u;
goto P_0c0724a0;
P_0c0724a0: /* original 7b18, guest PC 0x0c0724a0 */
if(!s->budget--) { s->failed_pc=0x0c0724a0u; return 0; }
r[11]+=0x00000018u;
goto P_0c0724a2;
P_0c0724a2: /* original 6133, guest PC 0x0c0724a2 */
if(!s->budget--) { s->failed_pc=0x0c0724a2u; return 0; }
r[1]=r[3];
goto P_0c0724a4;
P_0c0724a4: /* original 3127, guest PC 0x0c0724a4 */
if(!s->budget--) { s->failed_pc=0x0c0724a4u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[1]>(int32_t)r[2])!=0);
goto P_0c0724a6;
P_0c0724a6: /* original 7918, guest PC 0x0c0724a6 */
if(!s->budget--) { s->failed_pc=0x0c0724a6u; return 0; }
r[9]+=0x00000018u;
goto P_0c0724a8;
P_0c0724a8: /* original 1f31, guest PC 0x0c0724a8 */
if(!s->budget--) { s->failed_pc=0x0c0724a8u; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c0724aa;
P_0c0724aa: /* original 8d03, guest PC 0x0c0724aa */
if(!s->budget--) { s->failed_pc=0x0c0724aau; return 0; }
cond=r[17]&1u;
r[8]+=0x00000018u;
if(cond) { goto P_0c0724b4; }
goto P_0c0724ae;
P_0c0724ac: /* original 7818, guest PC 0x0c0724ac */
if(!s->budget--) { s->failed_pc=0x0c0724acu; return 0; }
r[8]+=0x00000018u;
goto P_0c0724ae;
P_0c0724ae: /* original d304, guest PC 0x0c0724ae */
if(!s->budget--) { s->failed_pc=0x0c0724aeu; return 0; }
r[3]=read(ram,0x0c0724c0u,4);
goto P_0c0724b0;
P_0c0724b0: /* original 432b, guest PC 0x0c0724b0 */
if(!s->budget--) { s->failed_pc=0x0c0724b0u; return 0; }
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
P_0c0724b2: /* original 0009, guest PC 0x0c0724b2 */
if(!s->budget--) { s->failed_pc=0x0c0724b2u; return 0; }
goto P_0c0724b4;
P_0c0724b4: /* original 65f2, guest PC 0x0c0724b4 */
if(!s->budget--) { s->failed_pc=0x0c0724b4u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0724b6;
P_0c0724b6: /* original 64d3, guest PC 0x0c0724b6 */
if(!s->budget--) { s->failed_pc=0x0c0724b6u; return 0; }
r[4]=r[13];
goto P_0c0724b8;
P_0c0724b8: /* original 66e3, guest PC 0x0c0724b8 */
if(!s->budget--) { s->failed_pc=0x0c0724b8u; return 0; }
r[6]=r[14];
goto P_0c0724ba;
P_0c0724ba: /* original a003, guest PC 0x0c0724ba */
if(!s->budget--) { s->failed_pc=0x0c0724bau; return 0; }
goto P_0c0724c4;
P_0c0724bc: /* original 0009, guest PC 0x0c0724bc */
if(!s->budget--) { s->failed_pc=0x0c0724bcu; return 0; }
return vf3_matrix_family(0x0c0724beu,s,ram);
P_0c0724c4: /* original f059, guest PC 0x0c0724c4 */
if(!s->budget--) { s->failed_pc=0x0c0724c4u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0724c6;
P_0c0724c6: /* original f369, guest PC 0x0c0724c6 */
if(!s->budget--) { s->failed_pc=0x0c0724c6u; return 0; }
vf3_matrix_load(s,ram,3,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c0724c8;
P_0c0724c8: /* original f159, guest PC 0x0c0724c8 */
if(!s->budget--) { s->failed_pc=0x0c0724c8u; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0724ca;
P_0c0724ca: /* original f469, guest PC 0x0c0724ca */
if(!s->budget--) { s->failed_pc=0x0c0724cau; return 0; }
vf3_matrix_load(s,ram,4,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c0724cc;
P_0c0724cc: /* original f031, guest PC 0x0c0724cc */
if(!s->budget--) { s->failed_pc=0x0c0724ccu; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'-');
goto P_0c0724ce;
P_0c0724ce: /* original f258, guest PC 0x0c0724ce */
if(!s->budget--) { s->failed_pc=0x0c0724ceu; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
goto P_0c0724d0;
P_0c0724d0: /* original f568, guest PC 0x0c0724d0 */
if(!s->budget--) { s->failed_pc=0x0c0724d0u; return 0; }
vf3_matrix_load(s,ram,5,r[6]);
goto P_0c0724d2;
P_0c0724d2: /* original f141, guest PC 0x0c0724d2 */
if(!s->budget--) { s->failed_pc=0x0c0724d2u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'-');
goto P_0c0724d4;
P_0c0724d4: /* original f251, guest PC 0x0c0724d4 */
if(!s->budget--) { s->failed_pc=0x0c0724d4u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'-');
goto P_0c0724d6;
P_0c0724d6: /* original 7408, guest PC 0x0c0724d6 */
if(!s->budget--) { s->failed_pc=0x0c0724d6u; return 0; }
r[4]+=0x00000008u;
goto P_0c0724d8;
P_0c0724d8: /* original f42a, guest PC 0x0c0724d8 */
if(!s->budget--) { s->failed_pc=0x0c0724d8u; return 0; }
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c0724da;
P_0c0724da: /* original f41b, guest PC 0x0c0724da */
if(!s->budget--) { s->failed_pc=0x0c0724dau; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c0724dc;
P_0c0724dc: /* original f40b, guest PC 0x0c0724dc */
if(!s->budget--) { s->failed_pc=0x0c0724dcu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c0724de;
P_0c0724de: /* original 0009, guest PC 0x0c0724de */
if(!s->budget--) { s->failed_pc=0x0c0724deu; return 0; }
goto P_0c0724e0;
P_0c0724e0: /* original 64a3, guest PC 0x0c0724e0 */
if(!s->budget--) { s->failed_pc=0x0c0724e0u; return 0; }
r[4]=r[10];
goto P_0c0724e2;
P_0c0724e2: /* original 65b3, guest PC 0x0c0724e2 */
if(!s->budget--) { s->failed_pc=0x0c0724e2u; return 0; }
r[5]=r[11];
goto P_0c0724e4;
P_0c0724e4: /* original 66e3, guest PC 0x0c0724e4 */
if(!s->budget--) { s->failed_pc=0x0c0724e4u; return 0; }
r[6]=r[14];
goto P_0c0724e6;
P_0c0724e6: /* original f059, guest PC 0x0c0724e6 */
if(!s->budget--) { s->failed_pc=0x0c0724e6u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0724e8;
P_0c0724e8: /* original f369, guest PC 0x0c0724e8 */
if(!s->budget--) { s->failed_pc=0x0c0724e8u; return 0; }
vf3_matrix_load(s,ram,3,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c0724ea;
P_0c0724ea: /* original f159, guest PC 0x0c0724ea */
if(!s->budget--) { s->failed_pc=0x0c0724eau; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0724ec;
P_0c0724ec: /* original f469, guest PC 0x0c0724ec */
if(!s->budget--) { s->failed_pc=0x0c0724ecu; return 0; }
vf3_matrix_load(s,ram,4,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c0724ee;
P_0c0724ee: /* original f031, guest PC 0x0c0724ee */
if(!s->budget--) { s->failed_pc=0x0c0724eeu; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'-');
goto P_0c0724f0;
P_0c0724f0: /* original f258, guest PC 0x0c0724f0 */
if(!s->budget--) { s->failed_pc=0x0c0724f0u; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
goto P_0c0724f2;
P_0c0724f2: /* original f568, guest PC 0x0c0724f2 */
if(!s->budget--) { s->failed_pc=0x0c0724f2u; return 0; }
vf3_matrix_load(s,ram,5,r[6]);
goto P_0c0724f4;
P_0c0724f4: /* original f141, guest PC 0x0c0724f4 */
if(!s->budget--) { s->failed_pc=0x0c0724f4u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'-');
goto P_0c0724f6;
P_0c0724f6: /* original f251, guest PC 0x0c0724f6 */
if(!s->budget--) { s->failed_pc=0x0c0724f6u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'-');
goto P_0c0724f8;
P_0c0724f8: /* original 7408, guest PC 0x0c0724f8 */
if(!s->budget--) { s->failed_pc=0x0c0724f8u; return 0; }
r[4]+=0x00000008u;
goto P_0c0724fa;
P_0c0724fa: /* original f42a, guest PC 0x0c0724fa */
if(!s->budget--) { s->failed_pc=0x0c0724fau; return 0; }
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c0724fc;
P_0c0724fc: /* original f41b, guest PC 0x0c0724fc */
if(!s->budget--) { s->failed_pc=0x0c0724fcu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c0724fe;
P_0c0724fe: /* original f40b, guest PC 0x0c0724fe */
if(!s->budget--) { s->failed_pc=0x0c0724feu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c072500;
P_0c072500: /* original 64c3, guest PC 0x0c072500 */
if(!s->budget--) { s->failed_pc=0x0c072500u; return 0; }
r[4]=r[12];
goto P_0c072502;
P_0c072502: /* original 6593, guest PC 0x0c072502 */
if(!s->budget--) { s->failed_pc=0x0c072502u; return 0; }
r[5]=r[9];
goto P_0c072504;
P_0c072504: /* original 66e3, guest PC 0x0c072504 */
if(!s->budget--) { s->failed_pc=0x0c072504u; return 0; }
r[6]=r[14];
goto P_0c072506;
P_0c072506: /* original f059, guest PC 0x0c072506 */
if(!s->budget--) { s->failed_pc=0x0c072506u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c072508;
P_0c072508: /* original f369, guest PC 0x0c072508 */
if(!s->budget--) { s->failed_pc=0x0c072508u; return 0; }
vf3_matrix_load(s,ram,3,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c07250a;
P_0c07250a: /* original f159, guest PC 0x0c07250a */
if(!s->budget--) { s->failed_pc=0x0c07250au; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c07250c;
P_0c07250c: /* original f469, guest PC 0x0c07250c */
if(!s->budget--) { s->failed_pc=0x0c07250cu; return 0; }
vf3_matrix_load(s,ram,4,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c07250e;
P_0c07250e: /* original f031, guest PC 0x0c07250e */
if(!s->budget--) { s->failed_pc=0x0c07250eu; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'-');
goto P_0c072510;
P_0c072510: /* original f258, guest PC 0x0c072510 */
if(!s->budget--) { s->failed_pc=0x0c072510u; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
goto P_0c072512;
P_0c072512: /* original f568, guest PC 0x0c072512 */
if(!s->budget--) { s->failed_pc=0x0c072512u; return 0; }
vf3_matrix_load(s,ram,5,r[6]);
goto P_0c072514;
P_0c072514: /* original f141, guest PC 0x0c072514 */
if(!s->budget--) { s->failed_pc=0x0c072514u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'-');
goto P_0c072516;
P_0c072516: /* original f251, guest PC 0x0c072516 */
if(!s->budget--) { s->failed_pc=0x0c072516u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'-');
goto P_0c072518;
P_0c072518: /* original 7408, guest PC 0x0c072518 */
if(!s->budget--) { s->failed_pc=0x0c072518u; return 0; }
r[4]+=0x00000008u;
goto P_0c07251a;
P_0c07251a: /* original f42a, guest PC 0x0c07251a */
if(!s->budget--) { s->failed_pc=0x0c07251au; return 0; }
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c07251c;
P_0c07251c: /* original f41b, guest PC 0x0c07251c */
if(!s->budget--) { s->failed_pc=0x0c07251cu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c07251e;
P_0c07251e: /* original f40b, guest PC 0x0c07251e */
if(!s->budget--) { s->failed_pc=0x0c07251eu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c072520;
P_0c072520: /* original 54f2, guest PC 0x0c072520 */
if(!s->budget--) { s->failed_pc=0x0c072520u; return 0; }
r[4]=read(ram,r[15]+8,4);
goto P_0c072522;
P_0c072522: /* original 6583, guest PC 0x0c072522 */
if(!s->budget--) { s->failed_pc=0x0c072522u; return 0; }
r[5]=r[8];
goto P_0c072524;
P_0c072524: /* original 66e3, guest PC 0x0c072524 */
if(!s->budget--) { s->failed_pc=0x0c072524u; return 0; }
r[6]=r[14];
goto P_0c072526;
P_0c072526: /* original f059, guest PC 0x0c072526 */
if(!s->budget--) { s->failed_pc=0x0c072526u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c072528;
P_0c072528: /* original f369, guest PC 0x0c072528 */
if(!s->budget--) { s->failed_pc=0x0c072528u; return 0; }
vf3_matrix_load(s,ram,3,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c07252a;
P_0c07252a: /* original f159, guest PC 0x0c07252a */
if(!s->budget--) { s->failed_pc=0x0c07252au; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c07252c;
P_0c07252c: /* original f469, guest PC 0x0c07252c */
if(!s->budget--) { s->failed_pc=0x0c07252cu; return 0; }
vf3_matrix_load(s,ram,4,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c07252e;
P_0c07252e: /* original f031, guest PC 0x0c07252e */
if(!s->budget--) { s->failed_pc=0x0c07252eu; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'-');
goto P_0c072530;
P_0c072530: /* original f258, guest PC 0x0c072530 */
if(!s->budget--) { s->failed_pc=0x0c072530u; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
goto P_0c072532;
P_0c072532: /* original f568, guest PC 0x0c072532 */
if(!s->budget--) { s->failed_pc=0x0c072532u; return 0; }
vf3_matrix_load(s,ram,5,r[6]);
goto P_0c072534;
P_0c072534: /* original f141, guest PC 0x0c072534 */
if(!s->budget--) { s->failed_pc=0x0c072534u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'-');
goto P_0c072536;
P_0c072536: /* original f251, guest PC 0x0c072536 */
if(!s->budget--) { s->failed_pc=0x0c072536u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'-');
goto P_0c072538;
P_0c072538: /* original 7408, guest PC 0x0c072538 */
if(!s->budget--) { s->failed_pc=0x0c072538u; return 0; }
r[4]+=0x00000008u;
goto P_0c07253a;
P_0c07253a: /* original f42a, guest PC 0x0c07253a */
if(!s->budget--) { s->failed_pc=0x0c07253au; return 0; }
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c07253c;
P_0c07253c: /* original f41b, guest PC 0x0c07253c */
if(!s->budget--) { s->failed_pc=0x0c07253cu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c07253e;
P_0c07253e: /* original f40b, guest PC 0x0c07253e */
if(!s->budget--) { s->failed_pc=0x0c07253eu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c072540;
P_0c072540: /* original 66f3, guest PC 0x0c072540 */
if(!s->budget--) { s->failed_pc=0x0c072540u; return 0; }
r[6]=r[15];
goto P_0c072542;
P_0c072542: /* original 64c3, guest PC 0x0c072542 */
if(!s->budget--) { s->failed_pc=0x0c072542u; return 0; }
r[4]=r[12];
goto P_0c072544;
P_0c072544: /* original 65d3, guest PC 0x0c072544 */
if(!s->budget--) { s->failed_pc=0x0c072544u; return 0; }
r[5]=r[13];
goto P_0c072546;
P_0c072546: /* original 7624, guest PC 0x0c072546 */
if(!s->budget--) { s->failed_pc=0x0c072546u; return 0; }
r[6]+=0x00000024u;
goto P_0c072548;
P_0c072548: /* original f049, guest PC 0x0c072548 */
if(!s->budget--) { s->failed_pc=0x0c072548u; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c07254a;
P_0c07254a: /* original f549, guest PC 0x0c07254a */
if(!s->budget--) { s->failed_pc=0x0c07254au; return 0; }
vf3_matrix_load(s,ram,5,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c07254c;
P_0c07254c: /* original f648, guest PC 0x0c07254c */
if(!s->budget--) { s->failed_pc=0x0c07254cu; return 0; }
vf3_matrix_load(s,ram,6,r[4]);
goto P_0c07254e;
P_0c07254e: /* original f859, guest PC 0x0c07254e */
if(!s->budget--) { s->failed_pc=0x0c07254eu; return 0; }
vf3_matrix_load(s,ram,8,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c072550;
P_0c072550: /* original f959, guest PC 0x0c072550 */
if(!s->budget--) { s->failed_pc=0x0c072550u; return 0; }
vf3_matrix_load(s,ram,9,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c072552;
P_0c072552: /* original fa58, guest PC 0x0c072552 */
if(!s->budget--) { s->failed_pc=0x0c072552u; return 0; }
vf3_matrix_load(s,ram,10,r[5]);
goto P_0c072554;
P_0c072554: /* original 760c, guest PC 0x0c072554 */
if(!s->budget--) { s->failed_pc=0x0c072554u; return 0; }
r[6]+=0x0000000cu;
goto P_0c072556;
P_0c072556: /* original f35c, guest PC 0x0c072556 */
if(!s->budget--) { s->failed_pc=0x0c072556u; return 0; }
vf3_matrix_move(s,3,5);
goto P_0c072558;
P_0c072558: /* original f382, guest PC 0x0c072558 */
if(!s->budget--) { s->failed_pc=0x0c072558u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[8],r[18],'*');
goto P_0c07255a;
P_0c07255a: /* original f20c, guest PC 0x0c07255a */
if(!s->budget--) { s->failed_pc=0x0c07255au; return 0; }
vf3_matrix_move(s,2,0);
goto P_0c07255c;
P_0c07255c: /* original f2a2, guest PC 0x0c07255c */
if(!s->budget--) { s->failed_pc=0x0c07255cu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[10],r[18],'*');
goto P_0c07255e;
P_0c07255e: /* original f16c, guest PC 0x0c07255e */
if(!s->budget--) { s->failed_pc=0x0c07255eu; return 0; }
vf3_matrix_move(s,1,6);
goto P_0c072560;
P_0c072560: /* original f192, guest PC 0x0c072560 */
if(!s->budget--) { s->failed_pc=0x0c072560u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[9],r[18],'*');
goto P_0c072562;
P_0c072562: /* original f34d, guest PC 0x0c072562 */
if(!s->budget--) { s->failed_pc=0x0c072562u; return 0; }
fr[3]^=0x80000000u;
goto P_0c072564;
P_0c072564: /* original f39e, guest PC 0x0c072564 */
if(!s->budget--) { s->failed_pc=0x0c072564u; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[9],fr[3],r[18]);
goto P_0c072566;
P_0c072566: /* original f24d, guest PC 0x0c072566 */
if(!s->budget--) { s->failed_pc=0x0c072566u; return 0; }
fr[2]^=0x80000000u;
goto P_0c072568;
P_0c072568: /* original f06c, guest PC 0x0c072568 */
if(!s->budget--) { s->failed_pc=0x0c072568u; return 0; }
vf3_matrix_move(s,0,6);
goto P_0c07256a;
P_0c07256a: /* original f28e, guest PC 0x0c07256a */
if(!s->budget--) { s->failed_pc=0x0c07256au; return 0; }
fr[2]=vf3_fpu_mac(fr[0],fr[8],fr[2],r[18]);
goto P_0c07256c;
P_0c07256c: /* original f14d, guest PC 0x0c07256c */
if(!s->budget--) { s->failed_pc=0x0c07256cu; return 0; }
fr[1]^=0x80000000u;
goto P_0c07256e;
P_0c07256e: /* original f63b, guest PC 0x0c07256e */
if(!s->budget--) { s->failed_pc=0x0c07256eu; return 0; }
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,3,r[6]);
goto P_0c072570;
P_0c072570: /* original f05c, guest PC 0x0c072570 */
if(!s->budget--) { s->failed_pc=0x0c072570u; return 0; }
vf3_matrix_move(s,0,5);
goto P_0c072572;
P_0c072572: /* original f1ae, guest PC 0x0c072572 */
if(!s->budget--) { s->failed_pc=0x0c072572u; return 0; }
fr[1]=vf3_fpu_mac(fr[0],fr[10],fr[1],r[18]);
goto P_0c072574;
P_0c072574: /* original f62b, guest PC 0x0c072574 */
if(!s->budget--) { s->failed_pc=0x0c072574u; return 0; }
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[6]);
goto P_0c072576;
P_0c072576: /* original f61b, guest PC 0x0c072576 */
if(!s->budget--) { s->failed_pc=0x0c072576u; return 0; }
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[6]);
goto P_0c072578;
P_0c072578: /* original 54f2, guest PC 0x0c072578 */
if(!s->budget--) { s->failed_pc=0x0c072578u; return 0; }
r[4]=read(ram,r[15]+8,4);
goto P_0c07257a;
P_0c07257a: /* original 66f3, guest PC 0x0c07257a */
if(!s->budget--) { s->failed_pc=0x0c07257au; return 0; }
r[6]=r[15];
goto P_0c07257c;
P_0c07257c: /* original 65a3, guest PC 0x0c07257c */
if(!s->budget--) { s->failed_pc=0x0c07257cu; return 0; }
r[5]=r[10];
goto P_0c07257e;
P_0c07257e: /* original 7618, guest PC 0x0c07257e */
if(!s->budget--) { s->failed_pc=0x0c07257eu; return 0; }
r[6]+=0x00000018u;
goto P_0c072580;
P_0c072580: /* original f049, guest PC 0x0c072580 */
if(!s->budget--) { s->failed_pc=0x0c072580u; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c072582;
P_0c072582: /* original f549, guest PC 0x0c072582 */
if(!s->budget--) { s->failed_pc=0x0c072582u; return 0; }
vf3_matrix_load(s,ram,5,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c072584;
P_0c072584: /* original f648, guest PC 0x0c072584 */
if(!s->budget--) { s->failed_pc=0x0c072584u; return 0; }
vf3_matrix_load(s,ram,6,r[4]);
goto P_0c072586;
P_0c072586: /* original f859, guest PC 0x0c072586 */
if(!s->budget--) { s->failed_pc=0x0c072586u; return 0; }
vf3_matrix_load(s,ram,8,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c072588;
P_0c072588: /* original f959, guest PC 0x0c072588 */
if(!s->budget--) { s->failed_pc=0x0c072588u; return 0; }
vf3_matrix_load(s,ram,9,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c07258a;
P_0c07258a: /* original fa58, guest PC 0x0c07258a */
if(!s->budget--) { s->failed_pc=0x0c07258au; return 0; }
vf3_matrix_load(s,ram,10,r[5]);
goto P_0c07258c;
P_0c07258c: /* original 760c, guest PC 0x0c07258c */
if(!s->budget--) { s->failed_pc=0x0c07258cu; return 0; }
r[6]+=0x0000000cu;
goto P_0c07258e;
P_0c07258e: /* original f35c, guest PC 0x0c07258e */
if(!s->budget--) { s->failed_pc=0x0c07258eu; return 0; }
vf3_matrix_move(s,3,5);
goto P_0c072590;
P_0c072590: /* original f382, guest PC 0x0c072590 */
if(!s->budget--) { s->failed_pc=0x0c072590u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[8],r[18],'*');
goto P_0c072592;
P_0c072592: /* original f20c, guest PC 0x0c072592 */
if(!s->budget--) { s->failed_pc=0x0c072592u; return 0; }
vf3_matrix_move(s,2,0);
goto P_0c072594;
P_0c072594: /* original f2a2, guest PC 0x0c072594 */
if(!s->budget--) { s->failed_pc=0x0c072594u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[10],r[18],'*');
goto P_0c072596;
P_0c072596: /* original f16c, guest PC 0x0c072596 */
if(!s->budget--) { s->failed_pc=0x0c072596u; return 0; }
vf3_matrix_move(s,1,6);
goto P_0c072598;
P_0c072598: /* original f192, guest PC 0x0c072598 */
if(!s->budget--) { s->failed_pc=0x0c072598u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[9],r[18],'*');
goto P_0c07259a;
P_0c07259a: /* original f34d, guest PC 0x0c07259a */
if(!s->budget--) { s->failed_pc=0x0c07259au; return 0; }
fr[3]^=0x80000000u;
goto P_0c07259c;
P_0c07259c: /* original f39e, guest PC 0x0c07259c */
if(!s->budget--) { s->failed_pc=0x0c07259cu; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[9],fr[3],r[18]);
goto P_0c07259e;
P_0c07259e: /* original f24d, guest PC 0x0c07259e */
if(!s->budget--) { s->failed_pc=0x0c07259eu; return 0; }
fr[2]^=0x80000000u;
goto P_0c0725a0;
P_0c0725a0: /* original f06c, guest PC 0x0c0725a0 */
if(!s->budget--) { s->failed_pc=0x0c0725a0u; return 0; }
vf3_matrix_move(s,0,6);
goto P_0c0725a2;
P_0c0725a2: /* original f28e, guest PC 0x0c0725a2 */
if(!s->budget--) { s->failed_pc=0x0c0725a2u; return 0; }
fr[2]=vf3_fpu_mac(fr[0],fr[8],fr[2],r[18]);
goto P_0c0725a4;
P_0c0725a4: /* original f14d, guest PC 0x0c0725a4 */
if(!s->budget--) { s->failed_pc=0x0c0725a4u; return 0; }
fr[1]^=0x80000000u;
goto P_0c0725a6;
P_0c0725a6: /* original f63b, guest PC 0x0c0725a6 */
if(!s->budget--) { s->failed_pc=0x0c0725a6u; return 0; }
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,3,r[6]);
goto P_0c0725a8;
P_0c0725a8: /* original f05c, guest PC 0x0c0725a8 */
if(!s->budget--) { s->failed_pc=0x0c0725a8u; return 0; }
vf3_matrix_move(s,0,5);
goto P_0c0725aa;
P_0c0725aa: /* original f1ae, guest PC 0x0c0725aa */
if(!s->budget--) { s->failed_pc=0x0c0725aau; return 0; }
fr[1]=vf3_fpu_mac(fr[0],fr[10],fr[1],r[18]);
goto P_0c0725ac;
P_0c0725ac: /* original f62b, guest PC 0x0c0725ac */
if(!s->budget--) { s->failed_pc=0x0c0725acu; return 0; }
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[6]);
goto P_0c0725ae;
P_0c0725ae: /* original f61b, guest PC 0x0c0725ae */
if(!s->budget--) { s->failed_pc=0x0c0725aeu; return 0; }
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[6]);
goto P_0c0725b0;
P_0c0725b0: /* original 64f3, guest PC 0x0c0725b0 */
if(!s->budget--) { s->failed_pc=0x0c0725b0u; return 0; }
r[4]=r[15];
goto P_0c0725b2;
P_0c0725b2: /* original 7424, guest PC 0x0c0725b2 */
if(!s->budget--) { s->failed_pc=0x0c0725b2u; return 0; }
r[4]+=0x00000024u;
goto P_0c0725b4;
P_0c0725b4: /* original f049, guest PC 0x0c0725b4 */
if(!s->budget--) { s->failed_pc=0x0c0725b4u; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c0725b6;
P_0c0725b6: /* original f149, guest PC 0x0c0725b6 */
if(!s->budget--) { s->failed_pc=0x0c0725b6u; return 0; }
vf3_matrix_load(s,ram,1,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c0725b8;
P_0c0725b8: /* original f249, guest PC 0x0c0725b8 */
if(!s->budget--) { s->failed_pc=0x0c0725b8u; return 0; }
vf3_matrix_load(s,ram,2,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c0725ba;
P_0c0725ba: /* original f38d, guest PC 0x0c0725ba */
if(!s->budget--) { s->failed_pc=0x0c0725bau; return 0; }
fr[3]=0;
goto P_0c0725bc;
P_0c0725bc: /* original f0ed, guest PC 0x0c0725bc */
if(!s->budget--) { s->failed_pc=0x0c0725bcu; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+0,r[18],fr+3)) goto unsupported;
goto P_0c0725be;
P_0c0725be: /* original f37d, guest PC 0x0c0725be */
if(!s->budget--) { s->failed_pc=0x0c0725beu; return 0; }
if(!vf3_fpu_fsrra(fr[3],r[18],&fr[3])) goto unsupported;
goto P_0c0725c0;
P_0c0725c0: /* original f232, guest PC 0x0c0725c0 */
if(!s->budget--) { s->failed_pc=0x0c0725c0u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c0725c2;
P_0c0725c2: /* original f132, guest PC 0x0c0725c2 */
if(!s->budget--) { s->failed_pc=0x0c0725c2u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[3],r[18],'*');
goto P_0c0725c4;
P_0c0725c4: /* original f032, guest PC 0x0c0725c4 */
if(!s->budget--) { s->failed_pc=0x0c0725c4u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'*');
goto P_0c0725c6;
P_0c0725c6: /* original f42b, guest PC 0x0c0725c6 */
if(!s->budget--) { s->failed_pc=0x0c0725c6u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c0725c8;
P_0c0725c8: /* original f41b, guest PC 0x0c0725c8 */
if(!s->budget--) { s->failed_pc=0x0c0725c8u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c0725ca;
P_0c0725ca: /* original f40b, guest PC 0x0c0725ca */
if(!s->budget--) { s->failed_pc=0x0c0725cau; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c0725cc;
P_0c0725cc: /* original 64f3, guest PC 0x0c0725cc */
if(!s->budget--) { s->failed_pc=0x0c0725ccu; return 0; }
r[4]=r[15];
goto P_0c0725ce;
P_0c0725ce: /* original 7418, guest PC 0x0c0725ce */
if(!s->budget--) { s->failed_pc=0x0c0725ceu; return 0; }
r[4]+=0x00000018u;
goto P_0c0725d0;
P_0c0725d0: /* original f049, guest PC 0x0c0725d0 */
if(!s->budget--) { s->failed_pc=0x0c0725d0u; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c0725d2;
P_0c0725d2: /* original f149, guest PC 0x0c0725d2 */
if(!s->budget--) { s->failed_pc=0x0c0725d2u; return 0; }
vf3_matrix_load(s,ram,1,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c0725d4;
P_0c0725d4: /* original f249, guest PC 0x0c0725d4 */
if(!s->budget--) { s->failed_pc=0x0c0725d4u; return 0; }
vf3_matrix_load(s,ram,2,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c0725d6;
P_0c0725d6: /* original f38d, guest PC 0x0c0725d6 */
if(!s->budget--) { s->failed_pc=0x0c0725d6u; return 0; }
fr[3]=0;
goto P_0c0725d8;
P_0c0725d8: /* original f0ed, guest PC 0x0c0725d8 */
if(!s->budget--) { s->failed_pc=0x0c0725d8u; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+0,r[18],fr+3)) goto unsupported;
goto P_0c0725da;
P_0c0725da: /* original f37d, guest PC 0x0c0725da */
if(!s->budget--) { s->failed_pc=0x0c0725dau; return 0; }
if(!vf3_fpu_fsrra(fr[3],r[18],&fr[3])) goto unsupported;
goto P_0c0725dc;
P_0c0725dc: /* original f232, guest PC 0x0c0725dc */
if(!s->budget--) { s->failed_pc=0x0c0725dcu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c0725de;
P_0c0725de: /* original f132, guest PC 0x0c0725de */
if(!s->budget--) { s->failed_pc=0x0c0725deu; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[3],r[18],'*');
goto P_0c0725e0;
P_0c0725e0: /* original f032, guest PC 0x0c0725e0 */
if(!s->budget--) { s->failed_pc=0x0c0725e0u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'*');
goto P_0c0725e2;
P_0c0725e2: /* original f42b, guest PC 0x0c0725e2 */
if(!s->budget--) { s->failed_pc=0x0c0725e2u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c0725e4;
P_0c0725e4: /* original f41b, guest PC 0x0c0725e4 */
if(!s->budget--) { s->failed_pc=0x0c0725e4u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c0725e6;
P_0c0725e6: /* original f40b, guest PC 0x0c0725e6 */
if(!s->budget--) { s->failed_pc=0x0c0725e6u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c0725e8;
P_0c0725e8: /* original 65f3, guest PC 0x0c0725e8 */
if(!s->budget--) { s->failed_pc=0x0c0725e8u; return 0; }
r[5]=r[15];
goto P_0c0725ea;
P_0c0725ea: /* original 64e3, guest PC 0x0c0725ea */
if(!s->budget--) { s->failed_pc=0x0c0725eau; return 0; }
r[4]=r[14];
goto P_0c0725ec;
P_0c0725ec: /* original 66f3, guest PC 0x0c0725ec */
if(!s->budget--) { s->failed_pc=0x0c0725ecu; return 0; }
r[6]=r[15];
goto P_0c0725ee;
P_0c0725ee: /* original 740c, guest PC 0x0c0725ee */
if(!s->budget--) { s->failed_pc=0x0c0725eeu; return 0; }
r[4]+=0x0000000cu;
goto P_0c0725f0;
P_0c0725f0: /* original 7618, guest PC 0x0c0725f0 */
if(!s->budget--) { s->failed_pc=0x0c0725f0u; return 0; }
r[6]+=0x00000018u;
goto P_0c0725f2;
P_0c0725f2: /* original 7524, guest PC 0x0c0725f2 */
if(!s->budget--) { s->failed_pc=0x0c0725f2u; return 0; }
r[5]+=0x00000024u;
goto P_0c0725f4;
P_0c0725f4: /* original f059, guest PC 0x0c0725f4 */
if(!s->budget--) { s->failed_pc=0x0c0725f4u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0725f6;
P_0c0725f6: /* original f369, guest PC 0x0c0725f6 */
if(!s->budget--) { s->failed_pc=0x0c0725f6u; return 0; }
vf3_matrix_load(s,ram,3,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c0725f8;
P_0c0725f8: /* original f159, guest PC 0x0c0725f8 */
if(!s->budget--) { s->failed_pc=0x0c0725f8u; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0725fa;
P_0c0725fa: /* original f469, guest PC 0x0c0725fa */
if(!s->budget--) { s->failed_pc=0x0c0725fau; return 0; }
vf3_matrix_load(s,ram,4,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c0725fc;
P_0c0725fc: /* original f259, guest PC 0x0c0725fc */
if(!s->budget--) { s->failed_pc=0x0c0725fcu; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0725fe;
P_0c0725fe: /* original f569, guest PC 0x0c0725fe */
if(!s->budget--) { s->failed_pc=0x0c0725feu; return 0; }
vf3_matrix_load(s,ram,5,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c072600;
P_0c072600: /* original 740c, guest PC 0x0c072600 */
if(!s->budget--) { s->failed_pc=0x0c072600u; return 0; }
r[4]+=0x0000000cu;
goto P_0c072602;
P_0c072602: /* original f030, guest PC 0x0c072602 */
if(!s->budget--) { s->failed_pc=0x0c072602u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'+');
goto P_0c072604;
P_0c072604: /* original f250, guest PC 0x0c072604 */
if(!s->budget--) { s->failed_pc=0x0c072604u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'+');
goto P_0c072606;
P_0c072606: /* original f140, guest PC 0x0c072606 */
if(!s->budget--) { s->failed_pc=0x0c072606u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'+');
goto P_0c072608;
P_0c072608: /* original f42b, guest PC 0x0c072608 */
if(!s->budget--) { s->failed_pc=0x0c072608u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c07260a;
P_0c07260a: /* original f41b, guest PC 0x0c07260a */
if(!s->budget--) { s->failed_pc=0x0c07260au; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c07260c;
P_0c07260c: /* original f40b, guest PC 0x0c07260c */
if(!s->budget--) { s->failed_pc=0x0c07260cu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c07260e;
P_0c07260e: /* original 0009, guest PC 0x0c07260e */
if(!s->budget--) { s->failed_pc=0x0c07260eu; return 0; }
goto P_0c072610;
P_0c072610: /* original 64e3, guest PC 0x0c072610 */
if(!s->budget--) { s->failed_pc=0x0c072610u; return 0; }
r[4]=r[14];
goto P_0c072612;
P_0c072612: /* original 65e3, guest PC 0x0c072612 */
if(!s->budget--) { s->failed_pc=0x0c072612u; return 0; }
r[5]=r[14];
goto P_0c072614;
P_0c072614: /* original 740c, guest PC 0x0c072614 */
if(!s->budget--) { s->failed_pc=0x0c072614u; return 0; }
r[4]+=0x0000000cu;
goto P_0c072616;
P_0c072616: /* original f4fc, guest PC 0x0c072616 */
if(!s->budget--) { s->failed_pc=0x0c072616u; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c072618;
P_0c072618: /* original 750c, guest PC 0x0c072618 */
if(!s->budget--) { s->failed_pc=0x0c072618u; return 0; }
r[5]+=0x0000000cu;
goto P_0c07261a;
P_0c07261a: /* original f059, guest PC 0x0c07261a */
if(!s->budget--) { s->failed_pc=0x0c07261au; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c07261c;
P_0c07261c: /* original f159, guest PC 0x0c07261c */
if(!s->budget--) { s->failed_pc=0x0c07261cu; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c07261e;
P_0c07261e: /* original f259, guest PC 0x0c07261e */
if(!s->budget--) { s->failed_pc=0x0c07261eu; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c072620;
P_0c072620: /* original f38d, guest PC 0x0c072620 */
if(!s->budget--) { s->failed_pc=0x0c072620u; return 0; }
fr[3]=0;
goto P_0c072622;
P_0c072622: /* original f0ed, guest PC 0x0c072622 */
if(!s->budget--) { s->failed_pc=0x0c072622u; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+0,r[18],fr+3)) goto unsupported;
goto P_0c072624;
P_0c072624: /* original f37d, guest PC 0x0c072624 */
if(!s->budget--) { s->failed_pc=0x0c072624u; return 0; }
if(!vf3_fpu_fsrra(fr[3],r[18],&fr[3])) goto unsupported;
goto P_0c072626;
P_0c072626: /* original f342, guest PC 0x0c072626 */
if(!s->budget--) { s->failed_pc=0x0c072626u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'*');
goto P_0c072628;
P_0c072628: /* original 740c, guest PC 0x0c072628 */
if(!s->budget--) { s->failed_pc=0x0c072628u; return 0; }
r[4]+=0x0000000cu;
goto P_0c07262a;
P_0c07262a: /* original f232, guest PC 0x0c07262a */
if(!s->budget--) { s->failed_pc=0x0c07262au; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c07262c;
P_0c07262c: /* original f132, guest PC 0x0c07262c */
if(!s->budget--) { s->failed_pc=0x0c07262cu; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[3],r[18],'*');
goto P_0c07262e;
P_0c07262e: /* original f032, guest PC 0x0c07262e */
if(!s->budget--) { s->failed_pc=0x0c07262eu; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'*');
goto P_0c072630;
P_0c072630: /* original f42b, guest PC 0x0c072630 */
if(!s->budget--) { s->failed_pc=0x0c072630u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c072632;
P_0c072632: /* original f41b, guest PC 0x0c072632 */
if(!s->budget--) { s->failed_pc=0x0c072632u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c072634;
P_0c072634: /* original f40b, guest PC 0x0c072634 */
if(!s->budget--) { s->failed_pc=0x0c072634u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c072636;
P_0c072636: /* original 0009, guest PC 0x0c072636 */
if(!s->budget--) { s->failed_pc=0x0c072636u; return 0; }
goto P_0c072638;
P_0c072638: /* original 2fe2, guest PC 0x0c072638 */
if(!s->budget--) { s->failed_pc=0x0c072638u; return 0; }
write(ram,r[15],r[14],4);
goto P_0c07263a;
P_0c07263a: /* original e201, guest PC 0x0c07263a */
if(!s->budget--) { s->failed_pc=0x0c07263au; return 0; }
r[2]=0x00000001u;
goto P_0c07263c;
P_0c07263c: /* original 53f1, guest PC 0x0c07263c */
if(!s->budget--) { s->failed_pc=0x0c07263cu; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c07263e;
P_0c07263e: /* original 6eb3, guest PC 0x0c07263e */
if(!s->budget--) { s->failed_pc=0x0c07263eu; return 0; }
r[14]=r[11];
goto P_0c072640;
P_0c072640: /* original 7b18, guest PC 0x0c072640 */
if(!s->budget--) { s->failed_pc=0x0c072640u; return 0; }
r[11]+=0x00000018u;
goto P_0c072642;
P_0c072642: /* original 73ff, guest PC 0x0c072642 */
if(!s->budget--) { s->failed_pc=0x0c072642u; return 0; }
r[3]+=0xffffffffu;
goto P_0c072644;
P_0c072644: /* original 3327, guest PC 0x0c072644 */
if(!s->budget--) { s->failed_pc=0x0c072644u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>(int32_t)r[2])!=0);
goto P_0c072646;
P_0c072646: /* original 7918, guest PC 0x0c072646 */
if(!s->budget--) { s->failed_pc=0x0c072646u; return 0; }
r[9]+=0x00000018u;
goto P_0c072648;
P_0c072648: /* original 7818, guest PC 0x0c072648 */
if(!s->budget--) { s->failed_pc=0x0c072648u; return 0; }
r[8]+=0x00000018u;
goto P_0c07264a;
P_0c07264a: /* original 8f03, guest PC 0x0c07264a */
if(!s->budget--) { s->failed_pc=0x0c07264au; return 0; }
cond=r[17]&1u;
write(ram,r[15]+4,r[3],4);
if(!cond) { goto P_0c072654; }
goto P_0c07264e;
P_0c07264c: /* original 1f31, guest PC 0x0c07264c */
if(!s->budget--) { s->failed_pc=0x0c07264cu; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c07264e;
P_0c07264e: /* original d104, guest PC 0x0c07264e */
if(!s->budget--) { s->failed_pc=0x0c07264eu; return 0; }
r[1]=read(ram,0x0c072660u,4);
goto P_0c072650;
P_0c072650: /* original 412b, guest PC 0x0c072650 */
if(!s->budget--) { s->failed_pc=0x0c072650u; return 0; }
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
P_0c072652: /* original 0009, guest PC 0x0c072652 */
if(!s->budget--) { s->failed_pc=0x0c072652u; return 0; }
goto P_0c072654;
P_0c072654: /* original 65f2, guest PC 0x0c072654 */
if(!s->budget--) { s->failed_pc=0x0c072654u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c072656;
P_0c072656: /* original 64d3, guest PC 0x0c072656 */
if(!s->budget--) { s->failed_pc=0x0c072656u; return 0; }
r[4]=r[13];
goto P_0c072658;
P_0c072658: /* original 66e3, guest PC 0x0c072658 */
if(!s->budget--) { s->failed_pc=0x0c072658u; return 0; }
r[6]=r[14];
goto P_0c07265a;
P_0c07265a: /* original a003, guest PC 0x0c07265a */
if(!s->budget--) { s->failed_pc=0x0c07265au; return 0; }
goto P_0c072664;
P_0c07265c: /* original 0009, guest PC 0x0c07265c */
if(!s->budget--) { s->failed_pc=0x0c07265cu; return 0; }
return vf3_matrix_family(0x0c07265eu,s,ram);
P_0c072664: /* original f059, guest PC 0x0c072664 */
if(!s->budget--) { s->failed_pc=0x0c072664u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c072666;
P_0c072666: /* original f369, guest PC 0x0c072666 */
if(!s->budget--) { s->failed_pc=0x0c072666u; return 0; }
vf3_matrix_load(s,ram,3,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c072668;
P_0c072668: /* original f159, guest PC 0x0c072668 */
if(!s->budget--) { s->failed_pc=0x0c072668u; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c07266a;
P_0c07266a: /* original f469, guest PC 0x0c07266a */
if(!s->budget--) { s->failed_pc=0x0c07266au; return 0; }
vf3_matrix_load(s,ram,4,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c07266c;
P_0c07266c: /* original f031, guest PC 0x0c07266c */
if(!s->budget--) { s->failed_pc=0x0c07266cu; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'-');
goto P_0c07266e;
P_0c07266e: /* original f258, guest PC 0x0c07266e */
if(!s->budget--) { s->failed_pc=0x0c07266eu; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
goto P_0c072670;
P_0c072670: /* original f568, guest PC 0x0c072670 */
if(!s->budget--) { s->failed_pc=0x0c072670u; return 0; }
vf3_matrix_load(s,ram,5,r[6]);
goto P_0c072672;
P_0c072672: /* original f141, guest PC 0x0c072672 */
if(!s->budget--) { s->failed_pc=0x0c072672u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'-');
goto P_0c072674;
P_0c072674: /* original f251, guest PC 0x0c072674 */
if(!s->budget--) { s->failed_pc=0x0c072674u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'-');
goto P_0c072676;
P_0c072676: /* original 7408, guest PC 0x0c072676 */
if(!s->budget--) { s->failed_pc=0x0c072676u; return 0; }
r[4]+=0x00000008u;
goto P_0c072678;
P_0c072678: /* original f42a, guest PC 0x0c072678 */
if(!s->budget--) { s->failed_pc=0x0c072678u; return 0; }
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c07267a;
P_0c07267a: /* original f41b, guest PC 0x0c07267a */
if(!s->budget--) { s->failed_pc=0x0c07267au; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c07267c;
P_0c07267c: /* original f40b, guest PC 0x0c07267c */
if(!s->budget--) { s->failed_pc=0x0c07267cu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c07267e;
P_0c07267e: /* original 0009, guest PC 0x0c07267e */
if(!s->budget--) { s->failed_pc=0x0c07267eu; return 0; }
goto P_0c072680;
P_0c072680: /* original 64a3, guest PC 0x0c072680 */
if(!s->budget--) { s->failed_pc=0x0c072680u; return 0; }
r[4]=r[10];
goto P_0c072682;
P_0c072682: /* original 6593, guest PC 0x0c072682 */
if(!s->budget--) { s->failed_pc=0x0c072682u; return 0; }
r[5]=r[9];
goto P_0c072684;
P_0c072684: /* original 66e3, guest PC 0x0c072684 */
if(!s->budget--) { s->failed_pc=0x0c072684u; return 0; }
r[6]=r[14];
goto P_0c072686;
P_0c072686: /* original f059, guest PC 0x0c072686 */
if(!s->budget--) { s->failed_pc=0x0c072686u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c072688;
P_0c072688: /* original f369, guest PC 0x0c072688 */
if(!s->budget--) { s->failed_pc=0x0c072688u; return 0; }
vf3_matrix_load(s,ram,3,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c07268a;
P_0c07268a: /* original f159, guest PC 0x0c07268a */
if(!s->budget--) { s->failed_pc=0x0c07268au; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c07268c;
P_0c07268c: /* original f469, guest PC 0x0c07268c */
if(!s->budget--) { s->failed_pc=0x0c07268cu; return 0; }
vf3_matrix_load(s,ram,4,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c07268e;
P_0c07268e: /* original f031, guest PC 0x0c07268e */
if(!s->budget--) { s->failed_pc=0x0c07268eu; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'-');
goto P_0c072690;
P_0c072690: /* original f258, guest PC 0x0c072690 */
if(!s->budget--) { s->failed_pc=0x0c072690u; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
goto P_0c072692;
P_0c072692: /* original f568, guest PC 0x0c072692 */
if(!s->budget--) { s->failed_pc=0x0c072692u; return 0; }
vf3_matrix_load(s,ram,5,r[6]);
goto P_0c072694;
P_0c072694: /* original f141, guest PC 0x0c072694 */
if(!s->budget--) { s->failed_pc=0x0c072694u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'-');
goto P_0c072696;
P_0c072696: /* original f251, guest PC 0x0c072696 */
if(!s->budget--) { s->failed_pc=0x0c072696u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'-');
goto P_0c072698;
P_0c072698: /* original 7408, guest PC 0x0c072698 */
if(!s->budget--) { s->failed_pc=0x0c072698u; return 0; }
r[4]+=0x00000008u;
goto P_0c07269a;
P_0c07269a: /* original f42a, guest PC 0x0c07269a */
if(!s->budget--) { s->failed_pc=0x0c07269au; return 0; }
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c07269c;
P_0c07269c: /* original f41b, guest PC 0x0c07269c */
if(!s->budget--) { s->failed_pc=0x0c07269cu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c07269e;
P_0c07269e: /* original f40b, guest PC 0x0c07269e */
if(!s->budget--) { s->failed_pc=0x0c07269eu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c0726a0;
P_0c0726a0: /* original 64c3, guest PC 0x0c0726a0 */
if(!s->budget--) { s->failed_pc=0x0c0726a0u; return 0; }
r[4]=r[12];
goto P_0c0726a2;
P_0c0726a2: /* original 6583, guest PC 0x0c0726a2 */
if(!s->budget--) { s->failed_pc=0x0c0726a2u; return 0; }
r[5]=r[8];
goto P_0c0726a4;
P_0c0726a4: /* original 66e3, guest PC 0x0c0726a4 */
if(!s->budget--) { s->failed_pc=0x0c0726a4u; return 0; }
r[6]=r[14];
goto P_0c0726a6;
P_0c0726a6: /* original f059, guest PC 0x0c0726a6 */
if(!s->budget--) { s->failed_pc=0x0c0726a6u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0726a8;
P_0c0726a8: /* original f369, guest PC 0x0c0726a8 */
if(!s->budget--) { s->failed_pc=0x0c0726a8u; return 0; }
vf3_matrix_load(s,ram,3,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c0726aa;
P_0c0726aa: /* original f159, guest PC 0x0c0726aa */
if(!s->budget--) { s->failed_pc=0x0c0726aau; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0726ac;
P_0c0726ac: /* original f469, guest PC 0x0c0726ac */
if(!s->budget--) { s->failed_pc=0x0c0726acu; return 0; }
vf3_matrix_load(s,ram,4,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c0726ae;
P_0c0726ae: /* original f031, guest PC 0x0c0726ae */
if(!s->budget--) { s->failed_pc=0x0c0726aeu; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'-');
goto P_0c0726b0;
P_0c0726b0: /* original f258, guest PC 0x0c0726b0 */
if(!s->budget--) { s->failed_pc=0x0c0726b0u; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
goto P_0c0726b2;
P_0c0726b2: /* original f568, guest PC 0x0c0726b2 */
if(!s->budget--) { s->failed_pc=0x0c0726b2u; return 0; }
vf3_matrix_load(s,ram,5,r[6]);
goto P_0c0726b4;
P_0c0726b4: /* original f141, guest PC 0x0c0726b4 */
if(!s->budget--) { s->failed_pc=0x0c0726b4u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'-');
goto P_0c0726b6;
P_0c0726b6: /* original f251, guest PC 0x0c0726b6 */
if(!s->budget--) { s->failed_pc=0x0c0726b6u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'-');
goto P_0c0726b8;
P_0c0726b8: /* original 7408, guest PC 0x0c0726b8 */
if(!s->budget--) { s->failed_pc=0x0c0726b8u; return 0; }
r[4]+=0x00000008u;
goto P_0c0726ba;
P_0c0726ba: /* original f42a, guest PC 0x0c0726ba */
if(!s->budget--) { s->failed_pc=0x0c0726bau; return 0; }
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c0726bc;
P_0c0726bc: /* original f41b, guest PC 0x0c0726bc */
if(!s->budget--) { s->failed_pc=0x0c0726bcu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c0726be;
P_0c0726be: /* original f40b, guest PC 0x0c0726be */
if(!s->budget--) { s->failed_pc=0x0c0726beu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c0726c0;
P_0c0726c0: /* original 66f3, guest PC 0x0c0726c0 */
if(!s->budget--) { s->failed_pc=0x0c0726c0u; return 0; }
r[6]=r[15];
goto P_0c0726c2;
P_0c0726c2: /* original 64d3, guest PC 0x0c0726c2 */
if(!s->budget--) { s->failed_pc=0x0c0726c2u; return 0; }
r[4]=r[13];
goto P_0c0726c4;
P_0c0726c4: /* original 65c3, guest PC 0x0c0726c4 */
if(!s->budget--) { s->failed_pc=0x0c0726c4u; return 0; }
r[5]=r[12];
goto P_0c0726c6;
P_0c0726c6: /* original 7624, guest PC 0x0c0726c6 */
if(!s->budget--) { s->failed_pc=0x0c0726c6u; return 0; }
r[6]+=0x00000024u;
goto P_0c0726c8;
P_0c0726c8: /* original f049, guest PC 0x0c0726c8 */
if(!s->budget--) { s->failed_pc=0x0c0726c8u; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c0726ca;
P_0c0726ca: /* original f549, guest PC 0x0c0726ca */
if(!s->budget--) { s->failed_pc=0x0c0726cau; return 0; }
vf3_matrix_load(s,ram,5,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c0726cc;
P_0c0726cc: /* original f648, guest PC 0x0c0726cc */
if(!s->budget--) { s->failed_pc=0x0c0726ccu; return 0; }
vf3_matrix_load(s,ram,6,r[4]);
goto P_0c0726ce;
P_0c0726ce: /* original f859, guest PC 0x0c0726ce */
if(!s->budget--) { s->failed_pc=0x0c0726ceu; return 0; }
vf3_matrix_load(s,ram,8,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0726d0;
P_0c0726d0: /* original f959, guest PC 0x0c0726d0 */
if(!s->budget--) { s->failed_pc=0x0c0726d0u; return 0; }
vf3_matrix_load(s,ram,9,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0726d2;
P_0c0726d2: /* original fa58, guest PC 0x0c0726d2 */
if(!s->budget--) { s->failed_pc=0x0c0726d2u; return 0; }
vf3_matrix_load(s,ram,10,r[5]);
goto P_0c0726d4;
P_0c0726d4: /* original 760c, guest PC 0x0c0726d4 */
if(!s->budget--) { s->failed_pc=0x0c0726d4u; return 0; }
r[6]+=0x0000000cu;
goto P_0c0726d6;
P_0c0726d6: /* original f35c, guest PC 0x0c0726d6 */
if(!s->budget--) { s->failed_pc=0x0c0726d6u; return 0; }
vf3_matrix_move(s,3,5);
goto P_0c0726d8;
P_0c0726d8: /* original f382, guest PC 0x0c0726d8 */
if(!s->budget--) { s->failed_pc=0x0c0726d8u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[8],r[18],'*');
goto P_0c0726da;
P_0c0726da: /* original f20c, guest PC 0x0c0726da */
if(!s->budget--) { s->failed_pc=0x0c0726dau; return 0; }
vf3_matrix_move(s,2,0);
goto P_0c0726dc;
P_0c0726dc: /* original f2a2, guest PC 0x0c0726dc */
if(!s->budget--) { s->failed_pc=0x0c0726dcu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[10],r[18],'*');
goto P_0c0726de;
P_0c0726de: /* original f16c, guest PC 0x0c0726de */
if(!s->budget--) { s->failed_pc=0x0c0726deu; return 0; }
vf3_matrix_move(s,1,6);
goto P_0c0726e0;
P_0c0726e0: /* original f192, guest PC 0x0c0726e0 */
if(!s->budget--) { s->failed_pc=0x0c0726e0u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[9],r[18],'*');
goto P_0c0726e2;
P_0c0726e2: /* original f34d, guest PC 0x0c0726e2 */
if(!s->budget--) { s->failed_pc=0x0c0726e2u; return 0; }
fr[3]^=0x80000000u;
goto P_0c0726e4;
P_0c0726e4: /* original f39e, guest PC 0x0c0726e4 */
if(!s->budget--) { s->failed_pc=0x0c0726e4u; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[9],fr[3],r[18]);
goto P_0c0726e6;
P_0c0726e6: /* original f24d, guest PC 0x0c0726e6 */
if(!s->budget--) { s->failed_pc=0x0c0726e6u; return 0; }
fr[2]^=0x80000000u;
goto P_0c0726e8;
P_0c0726e8: /* original f06c, guest PC 0x0c0726e8 */
if(!s->budget--) { s->failed_pc=0x0c0726e8u; return 0; }
vf3_matrix_move(s,0,6);
goto P_0c0726ea;
P_0c0726ea: /* original f28e, guest PC 0x0c0726ea */
if(!s->budget--) { s->failed_pc=0x0c0726eau; return 0; }
fr[2]=vf3_fpu_mac(fr[0],fr[8],fr[2],r[18]);
goto P_0c0726ec;
P_0c0726ec: /* original f14d, guest PC 0x0c0726ec */
if(!s->budget--) { s->failed_pc=0x0c0726ecu; return 0; }
fr[1]^=0x80000000u;
goto P_0c0726ee;
P_0c0726ee: /* original f63b, guest PC 0x0c0726ee */
if(!s->budget--) { s->failed_pc=0x0c0726eeu; return 0; }
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,3,r[6]);
goto P_0c0726f0;
P_0c0726f0: /* original f05c, guest PC 0x0c0726f0 */
if(!s->budget--) { s->failed_pc=0x0c0726f0u; return 0; }
vf3_matrix_move(s,0,5);
goto P_0c0726f2;
P_0c0726f2: /* original f1ae, guest PC 0x0c0726f2 */
if(!s->budget--) { s->failed_pc=0x0c0726f2u; return 0; }
fr[1]=vf3_fpu_mac(fr[0],fr[10],fr[1],r[18]);
goto P_0c0726f4;
P_0c0726f4: /* original f62b, guest PC 0x0c0726f4 */
if(!s->budget--) { s->failed_pc=0x0c0726f4u; return 0; }
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[6]);
goto P_0c0726f6;
P_0c0726f6: /* original f61b, guest PC 0x0c0726f6 */
if(!s->budget--) { s->failed_pc=0x0c0726f6u; return 0; }
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[6]);
goto P_0c0726f8;
P_0c0726f8: /* original 66f3, guest PC 0x0c0726f8 */
if(!s->budget--) { s->failed_pc=0x0c0726f8u; return 0; }
r[6]=r[15];
goto P_0c0726fa;
P_0c0726fa: /* original 64a3, guest PC 0x0c0726fa */
if(!s->budget--) { s->failed_pc=0x0c0726fau; return 0; }
r[4]=r[10];
goto P_0c0726fc;
P_0c0726fc: /* original 65d3, guest PC 0x0c0726fc */
if(!s->budget--) { s->failed_pc=0x0c0726fcu; return 0; }
r[5]=r[13];
goto P_0c0726fe;
P_0c0726fe: /* original 7618, guest PC 0x0c0726fe */
if(!s->budget--) { s->failed_pc=0x0c0726feu; return 0; }
r[6]+=0x00000018u;
goto P_0c072700;
P_0c072700: /* original f049, guest PC 0x0c072700 */
if(!s->budget--) { s->failed_pc=0x0c072700u; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c072702;
P_0c072702: /* original f549, guest PC 0x0c072702 */
if(!s->budget--) { s->failed_pc=0x0c072702u; return 0; }
vf3_matrix_load(s,ram,5,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c072704;
P_0c072704: /* original f648, guest PC 0x0c072704 */
if(!s->budget--) { s->failed_pc=0x0c072704u; return 0; }
vf3_matrix_load(s,ram,6,r[4]);
goto P_0c072706;
P_0c072706: /* original f859, guest PC 0x0c072706 */
if(!s->budget--) { s->failed_pc=0x0c072706u; return 0; }
vf3_matrix_load(s,ram,8,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c072708;
P_0c072708: /* original f959, guest PC 0x0c072708 */
if(!s->budget--) { s->failed_pc=0x0c072708u; return 0; }
vf3_matrix_load(s,ram,9,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c07270a;
P_0c07270a: /* original fa58, guest PC 0x0c07270a */
if(!s->budget--) { s->failed_pc=0x0c07270au; return 0; }
vf3_matrix_load(s,ram,10,r[5]);
goto P_0c07270c;
P_0c07270c: /* original 760c, guest PC 0x0c07270c */
if(!s->budget--) { s->failed_pc=0x0c07270cu; return 0; }
r[6]+=0x0000000cu;
goto P_0c07270e;
P_0c07270e: /* original f35c, guest PC 0x0c07270e */
if(!s->budget--) { s->failed_pc=0x0c07270eu; return 0; }
vf3_matrix_move(s,3,5);
goto P_0c072710;
P_0c072710: /* original f382, guest PC 0x0c072710 */
if(!s->budget--) { s->failed_pc=0x0c072710u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[8],r[18],'*');
goto P_0c072712;
P_0c072712: /* original f20c, guest PC 0x0c072712 */
if(!s->budget--) { s->failed_pc=0x0c072712u; return 0; }
vf3_matrix_move(s,2,0);
goto P_0c072714;
P_0c072714: /* original f2a2, guest PC 0x0c072714 */
if(!s->budget--) { s->failed_pc=0x0c072714u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[10],r[18],'*');
goto P_0c072716;
P_0c072716: /* original f16c, guest PC 0x0c072716 */
if(!s->budget--) { s->failed_pc=0x0c072716u; return 0; }
vf3_matrix_move(s,1,6);
goto P_0c072718;
P_0c072718: /* original f192, guest PC 0x0c072718 */
if(!s->budget--) { s->failed_pc=0x0c072718u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[9],r[18],'*');
goto P_0c07271a;
P_0c07271a: /* original f34d, guest PC 0x0c07271a */
if(!s->budget--) { s->failed_pc=0x0c07271au; return 0; }
fr[3]^=0x80000000u;
goto P_0c07271c;
P_0c07271c: /* original f39e, guest PC 0x0c07271c */
if(!s->budget--) { s->failed_pc=0x0c07271cu; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[9],fr[3],r[18]);
goto P_0c07271e;
P_0c07271e: /* original f24d, guest PC 0x0c07271e */
if(!s->budget--) { s->failed_pc=0x0c07271eu; return 0; }
fr[2]^=0x80000000u;
goto P_0c072720;
P_0c072720: /* original f06c, guest PC 0x0c072720 */
if(!s->budget--) { s->failed_pc=0x0c072720u; return 0; }
vf3_matrix_move(s,0,6);
goto P_0c072722;
P_0c072722: /* original f28e, guest PC 0x0c072722 */
if(!s->budget--) { s->failed_pc=0x0c072722u; return 0; }
fr[2]=vf3_fpu_mac(fr[0],fr[8],fr[2],r[18]);
goto P_0c072724;
P_0c072724: /* original f14d, guest PC 0x0c072724 */
if(!s->budget--) { s->failed_pc=0x0c072724u; return 0; }
fr[1]^=0x80000000u;
goto P_0c072726;
P_0c072726: /* original f63b, guest PC 0x0c072726 */
if(!s->budget--) { s->failed_pc=0x0c072726u; return 0; }
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,3,r[6]);
goto P_0c072728;
P_0c072728: /* original f05c, guest PC 0x0c072728 */
if(!s->budget--) { s->failed_pc=0x0c072728u; return 0; }
vf3_matrix_move(s,0,5);
goto P_0c07272a;
P_0c07272a: /* original f1ae, guest PC 0x0c07272a */
if(!s->budget--) { s->failed_pc=0x0c07272au; return 0; }
fr[1]=vf3_fpu_mac(fr[0],fr[10],fr[1],r[18]);
goto P_0c07272c;
P_0c07272c: /* original f62b, guest PC 0x0c07272c */
if(!s->budget--) { s->failed_pc=0x0c07272cu; return 0; }
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[6]);
goto P_0c07272e;
P_0c07272e: /* original f61b, guest PC 0x0c07272e */
if(!s->budget--) { s->failed_pc=0x0c07272eu; return 0; }
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[6]);
goto P_0c072730;
P_0c072730: /* original 64f3, guest PC 0x0c072730 */
if(!s->budget--) { s->failed_pc=0x0c072730u; return 0; }
r[4]=r[15];
goto P_0c072732;
P_0c072732: /* original 7424, guest PC 0x0c072732 */
if(!s->budget--) { s->failed_pc=0x0c072732u; return 0; }
r[4]+=0x00000024u;
goto P_0c072734;
P_0c072734: /* original f049, guest PC 0x0c072734 */
if(!s->budget--) { s->failed_pc=0x0c072734u; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c072736;
P_0c072736: /* original f149, guest PC 0x0c072736 */
if(!s->budget--) { s->failed_pc=0x0c072736u; return 0; }
vf3_matrix_load(s,ram,1,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c072738;
P_0c072738: /* original f249, guest PC 0x0c072738 */
if(!s->budget--) { s->failed_pc=0x0c072738u; return 0; }
vf3_matrix_load(s,ram,2,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c07273a;
P_0c07273a: /* original f38d, guest PC 0x0c07273a */
if(!s->budget--) { s->failed_pc=0x0c07273au; return 0; }
fr[3]=0;
goto P_0c07273c;
P_0c07273c: /* original f0ed, guest PC 0x0c07273c */
if(!s->budget--) { s->failed_pc=0x0c07273cu; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+0,r[18],fr+3)) goto unsupported;
goto P_0c07273e;
P_0c07273e: /* original f37d, guest PC 0x0c07273e */
if(!s->budget--) { s->failed_pc=0x0c07273eu; return 0; }
if(!vf3_fpu_fsrra(fr[3],r[18],&fr[3])) goto unsupported;
goto P_0c072740;
P_0c072740: /* original f232, guest PC 0x0c072740 */
if(!s->budget--) { s->failed_pc=0x0c072740u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c072742;
P_0c072742: /* original f132, guest PC 0x0c072742 */
if(!s->budget--) { s->failed_pc=0x0c072742u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[3],r[18],'*');
goto P_0c072744;
P_0c072744: /* original f032, guest PC 0x0c072744 */
if(!s->budget--) { s->failed_pc=0x0c072744u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'*');
goto P_0c072746;
P_0c072746: /* original f42b, guest PC 0x0c072746 */
if(!s->budget--) { s->failed_pc=0x0c072746u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c072748;
P_0c072748: /* original f41b, guest PC 0x0c072748 */
if(!s->budget--) { s->failed_pc=0x0c072748u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c07274a;
P_0c07274a: /* original f40b, guest PC 0x0c07274a */
if(!s->budget--) { s->failed_pc=0x0c07274au; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c07274c;
P_0c07274c: /* original 64f3, guest PC 0x0c07274c */
if(!s->budget--) { s->failed_pc=0x0c07274cu; return 0; }
r[4]=r[15];
goto P_0c07274e;
P_0c07274e: /* original 7418, guest PC 0x0c07274e */
if(!s->budget--) { s->failed_pc=0x0c07274eu; return 0; }
r[4]+=0x00000018u;
goto P_0c072750;
P_0c072750: /* original f049, guest PC 0x0c072750 */
if(!s->budget--) { s->failed_pc=0x0c072750u; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c072752;
P_0c072752: /* original f149, guest PC 0x0c072752 */
if(!s->budget--) { s->failed_pc=0x0c072752u; return 0; }
vf3_matrix_load(s,ram,1,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c072754;
P_0c072754: /* original f249, guest PC 0x0c072754 */
if(!s->budget--) { s->failed_pc=0x0c072754u; return 0; }
vf3_matrix_load(s,ram,2,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c072756;
P_0c072756: /* original f38d, guest PC 0x0c072756 */
if(!s->budget--) { s->failed_pc=0x0c072756u; return 0; }
fr[3]=0;
goto P_0c072758;
P_0c072758: /* original f0ed, guest PC 0x0c072758 */
if(!s->budget--) { s->failed_pc=0x0c072758u; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+0,r[18],fr+3)) goto unsupported;
goto P_0c07275a;
P_0c07275a: /* original f37d, guest PC 0x0c07275a */
if(!s->budget--) { s->failed_pc=0x0c07275au; return 0; }
if(!vf3_fpu_fsrra(fr[3],r[18],&fr[3])) goto unsupported;
goto P_0c07275c;
P_0c07275c: /* original f232, guest PC 0x0c07275c */
if(!s->budget--) { s->failed_pc=0x0c07275cu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c07275e;
P_0c07275e: /* original f132, guest PC 0x0c07275e */
if(!s->budget--) { s->failed_pc=0x0c07275eu; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[3],r[18],'*');
goto P_0c072760;
P_0c072760: /* original f032, guest PC 0x0c072760 */
if(!s->budget--) { s->failed_pc=0x0c072760u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'*');
goto P_0c072762;
P_0c072762: /* original f42b, guest PC 0x0c072762 */
if(!s->budget--) { s->failed_pc=0x0c072762u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c072764;
P_0c072764: /* original f41b, guest PC 0x0c072764 */
if(!s->budget--) { s->failed_pc=0x0c072764u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c072766;
P_0c072766: /* original f40b, guest PC 0x0c072766 */
if(!s->budget--) { s->failed_pc=0x0c072766u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c072768;
P_0c072768: /* original 65f3, guest PC 0x0c072768 */
if(!s->budget--) { s->failed_pc=0x0c072768u; return 0; }
r[5]=r[15];
goto P_0c07276a;
P_0c07276a: /* original 64e3, guest PC 0x0c07276a */
if(!s->budget--) { s->failed_pc=0x0c07276au; return 0; }
r[4]=r[14];
goto P_0c07276c;
P_0c07276c: /* original 66f3, guest PC 0x0c07276c */
if(!s->budget--) { s->failed_pc=0x0c07276cu; return 0; }
r[6]=r[15];
goto P_0c07276e;
P_0c07276e: /* original 740c, guest PC 0x0c07276e */
if(!s->budget--) { s->failed_pc=0x0c07276eu; return 0; }
r[4]+=0x0000000cu;
goto P_0c072770;
P_0c072770: /* original 7618, guest PC 0x0c072770 */
if(!s->budget--) { s->failed_pc=0x0c072770u; return 0; }
r[6]+=0x00000018u;
goto P_0c072772;
P_0c072772: /* original 7524, guest PC 0x0c072772 */
if(!s->budget--) { s->failed_pc=0x0c072772u; return 0; }
r[5]+=0x00000024u;
goto P_0c072774;
P_0c072774: /* original f059, guest PC 0x0c072774 */
if(!s->budget--) { s->failed_pc=0x0c072774u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c072776;
P_0c072776: /* original f369, guest PC 0x0c072776 */
if(!s->budget--) { s->failed_pc=0x0c072776u; return 0; }
vf3_matrix_load(s,ram,3,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c072778;
P_0c072778: /* original f159, guest PC 0x0c072778 */
if(!s->budget--) { s->failed_pc=0x0c072778u; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c07277a;
P_0c07277a: /* original f469, guest PC 0x0c07277a */
if(!s->budget--) { s->failed_pc=0x0c07277au; return 0; }
vf3_matrix_load(s,ram,4,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c07277c;
P_0c07277c: /* original f259, guest PC 0x0c07277c */
if(!s->budget--) { s->failed_pc=0x0c07277cu; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c07277e;
P_0c07277e: /* original f569, guest PC 0x0c07277e */
if(!s->budget--) { s->failed_pc=0x0c07277eu; return 0; }
vf3_matrix_load(s,ram,5,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c072780;
P_0c072780: /* original 740c, guest PC 0x0c072780 */
if(!s->budget--) { s->failed_pc=0x0c072780u; return 0; }
r[4]+=0x0000000cu;
goto P_0c072782;
P_0c072782: /* original f030, guest PC 0x0c072782 */
if(!s->budget--) { s->failed_pc=0x0c072782u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'+');
goto P_0c072784;
P_0c072784: /* original f250, guest PC 0x0c072784 */
if(!s->budget--) { s->failed_pc=0x0c072784u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'+');
goto P_0c072786;
P_0c072786: /* original f140, guest PC 0x0c072786 */
if(!s->budget--) { s->failed_pc=0x0c072786u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'+');
goto P_0c072788;
P_0c072788: /* original f42b, guest PC 0x0c072788 */
if(!s->budget--) { s->failed_pc=0x0c072788u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c07278a;
P_0c07278a: /* original f41b, guest PC 0x0c07278a */
if(!s->budget--) { s->failed_pc=0x0c07278au; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c07278c;
P_0c07278c: /* original f40b, guest PC 0x0c07278c */
if(!s->budget--) { s->failed_pc=0x0c07278cu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c07278e;
P_0c07278e: /* original 0009, guest PC 0x0c07278e */
if(!s->budget--) { s->failed_pc=0x0c07278eu; return 0; }
goto P_0c072790;
P_0c072790: /* original 64e3, guest PC 0x0c072790 */
if(!s->budget--) { s->failed_pc=0x0c072790u; return 0; }
r[4]=r[14];
goto P_0c072792;
P_0c072792: /* original 65e3, guest PC 0x0c072792 */
if(!s->budget--) { s->failed_pc=0x0c072792u; return 0; }
r[5]=r[14];
goto P_0c072794;
P_0c072794: /* original 740c, guest PC 0x0c072794 */
if(!s->budget--) { s->failed_pc=0x0c072794u; return 0; }
r[4]+=0x0000000cu;
goto P_0c072796;
P_0c072796: /* original f4fc, guest PC 0x0c072796 */
if(!s->budget--) { s->failed_pc=0x0c072796u; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c072798;
P_0c072798: /* original 750c, guest PC 0x0c072798 */
if(!s->budget--) { s->failed_pc=0x0c072798u; return 0; }
r[5]+=0x0000000cu;
goto P_0c07279a;
P_0c07279a: /* original f059, guest PC 0x0c07279a */
if(!s->budget--) { s->failed_pc=0x0c07279au; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c07279c;
P_0c07279c: /* original f159, guest PC 0x0c07279c */
if(!s->budget--) { s->failed_pc=0x0c07279cu; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c07279e;
P_0c07279e: /* original f259, guest PC 0x0c07279e */
if(!s->budget--) { s->failed_pc=0x0c07279eu; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0727a0;
P_0c0727a0: /* original f38d, guest PC 0x0c0727a0 */
if(!s->budget--) { s->failed_pc=0x0c0727a0u; return 0; }
fr[3]=0;
goto P_0c0727a2;
P_0c0727a2: /* original f0ed, guest PC 0x0c0727a2 */
if(!s->budget--) { s->failed_pc=0x0c0727a2u; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+0,r[18],fr+3)) goto unsupported;
goto P_0c0727a4;
P_0c0727a4: /* original f37d, guest PC 0x0c0727a4 */
if(!s->budget--) { s->failed_pc=0x0c0727a4u; return 0; }
if(!vf3_fpu_fsrra(fr[3],r[18],&fr[3])) goto unsupported;
goto P_0c0727a6;
P_0c0727a6: /* original f342, guest PC 0x0c0727a6 */
if(!s->budget--) { s->failed_pc=0x0c0727a6u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'*');
goto P_0c0727a8;
P_0c0727a8: /* original 740c, guest PC 0x0c0727a8 */
if(!s->budget--) { s->failed_pc=0x0c0727a8u; return 0; }
r[4]+=0x0000000cu;
goto P_0c0727aa;
P_0c0727aa: /* original f232, guest PC 0x0c0727aa */
if(!s->budget--) { s->failed_pc=0x0c0727aau; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c0727ac;
P_0c0727ac: /* original f132, guest PC 0x0c0727ac */
if(!s->budget--) { s->failed_pc=0x0c0727acu; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[3],r[18],'*');
goto P_0c0727ae;
P_0c0727ae: /* original f032, guest PC 0x0c0727ae */
if(!s->budget--) { s->failed_pc=0x0c0727aeu; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'*');
goto P_0c0727b0;
P_0c0727b0: /* original f42b, guest PC 0x0c0727b0 */
if(!s->budget--) { s->failed_pc=0x0c0727b0u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c0727b2;
P_0c0727b2: /* original f41b, guest PC 0x0c0727b2 */
if(!s->budget--) { s->failed_pc=0x0c0727b2u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c0727b4;
P_0c0727b4: /* original f40b, guest PC 0x0c0727b4 */
if(!s->budget--) { s->failed_pc=0x0c0727b4u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c0727b6;
P_0c0727b6: /* original 0009, guest PC 0x0c0727b6 */
if(!s->budget--) { s->failed_pc=0x0c0727b6u; return 0; }
goto P_0c0727b8;
P_0c0727b8: /* original 52f4, guest PC 0x0c0727b8 */
if(!s->budget--) { s->failed_pc=0x0c0727b8u; return 0; }
r[2]=read(ram,r[15]+16,4);
goto P_0c0727ba;
P_0c0727ba: /* original 6eb3, guest PC 0x0c0727ba */
if(!s->budget--) { s->failed_pc=0x0c0727bau; return 0; }
r[14]=r[11];
goto P_0c0727bc;
P_0c0727bc: /* original 7b18, guest PC 0x0c0727bc */
if(!s->budget--) { s->failed_pc=0x0c0727bcu; return 0; }
r[11]+=0x00000018u;
goto P_0c0727be;
P_0c0727be: /* original 72ff, guest PC 0x0c0727be */
if(!s->budget--) { s->failed_pc=0x0c0727beu; return 0; }
r[2]+=0xffffffffu;
goto P_0c0727c0;
P_0c0727c0: /* original 1f24, guest PC 0x0c0727c0 */
if(!s->budget--) { s->failed_pc=0x0c0727c0u; return 0; }
write(ram,r[15]+16,r[2],4);
goto P_0c0727c2;
P_0c0727c2: /* original 7918, guest PC 0x0c0727c2 */
if(!s->budget--) { s->failed_pc=0x0c0727c2u; return 0; }
r[9]+=0x00000018u;
goto P_0c0727c4;
P_0c0727c4: /* original 7818, guest PC 0x0c0727c4 */
if(!s->budget--) { s->failed_pc=0x0c0727c4u; return 0; }
r[8]+=0x00000018u;
goto P_0c0727c6;
P_0c0727c6: /* original 51f4, guest PC 0x0c0727c6 */
if(!s->budget--) { s->failed_pc=0x0c0727c6u; return 0; }
r[1]=read(ram,r[15]+16,4);
goto P_0c0727c8;
P_0c0727c8: /* original e307, guest PC 0x0c0727c8 */
if(!s->budget--) { s->failed_pc=0x0c0727c8u; return 0; }
r[3]=0x00000007u;
goto P_0c0727ca;
P_0c0727ca: /* original 3137, guest PC 0x0c0727ca */
if(!s->budget--) { s->failed_pc=0x0c0727cau; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[1]>(int32_t)r[3])!=0);
goto P_0c0727cc;
P_0c0727cc: /* original 8b02, guest PC 0x0c0727cc */
if(!s->budget--) { s->failed_pc=0x0c0727ccu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0727d4; }
goto P_0c0727ce;
P_0c0727ce: /* original d204, guest PC 0x0c0727ce */
if(!s->budget--) { s->failed_pc=0x0c0727ceu; return 0; }
r[2]=read(ram,0x0c0727e0u,4);
goto P_0c0727d0;
P_0c0727d0: /* original 422b, guest PC 0x0c0727d0 */
if(!s->budget--) { s->failed_pc=0x0c0727d0u; return 0; }
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
P_0c0727d2: /* original 0009, guest PC 0x0c0727d2 */
if(!s->budget--) { s->failed_pc=0x0c0727d2u; return 0; }
goto P_0c0727d4;
P_0c0727d4: /* original 64d3, guest PC 0x0c0727d4 */
if(!s->budget--) { s->failed_pc=0x0c0727d4u; return 0; }
r[4]=r[13];
goto P_0c0727d6;
P_0c0727d6: /* original 65b3, guest PC 0x0c0727d6 */
if(!s->budget--) { s->failed_pc=0x0c0727d6u; return 0; }
r[5]=r[11];
goto P_0c0727d8;
P_0c0727d8: /* original 66e3, guest PC 0x0c0727d8 */
if(!s->budget--) { s->failed_pc=0x0c0727d8u; return 0; }
r[6]=r[14];
goto P_0c0727da;
P_0c0727da: /* original a003, guest PC 0x0c0727da */
if(!s->budget--) { s->failed_pc=0x0c0727dau; return 0; }
goto P_0c0727e4;
P_0c0727dc: /* original 0009, guest PC 0x0c0727dc */
if(!s->budget--) { s->failed_pc=0x0c0727dcu; return 0; }
return vf3_matrix_family(0x0c0727deu,s,ram);
P_0c0727e4: /* original f059, guest PC 0x0c0727e4 */
if(!s->budget--) { s->failed_pc=0x0c0727e4u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0727e6;
P_0c0727e6: /* original f369, guest PC 0x0c0727e6 */
if(!s->budget--) { s->failed_pc=0x0c0727e6u; return 0; }
vf3_matrix_load(s,ram,3,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c0727e8;
P_0c0727e8: /* original f159, guest PC 0x0c0727e8 */
if(!s->budget--) { s->failed_pc=0x0c0727e8u; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0727ea;
P_0c0727ea: /* original f469, guest PC 0x0c0727ea */
if(!s->budget--) { s->failed_pc=0x0c0727eau; return 0; }
vf3_matrix_load(s,ram,4,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c0727ec;
P_0c0727ec: /* original f031, guest PC 0x0c0727ec */
if(!s->budget--) { s->failed_pc=0x0c0727ecu; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'-');
goto P_0c0727ee;
P_0c0727ee: /* original f258, guest PC 0x0c0727ee */
if(!s->budget--) { s->failed_pc=0x0c0727eeu; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
goto P_0c0727f0;
P_0c0727f0: /* original f568, guest PC 0x0c0727f0 */
if(!s->budget--) { s->failed_pc=0x0c0727f0u; return 0; }
vf3_matrix_load(s,ram,5,r[6]);
goto P_0c0727f2;
P_0c0727f2: /* original f141, guest PC 0x0c0727f2 */
if(!s->budget--) { s->failed_pc=0x0c0727f2u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'-');
goto P_0c0727f4;
P_0c0727f4: /* original f251, guest PC 0x0c0727f4 */
if(!s->budget--) { s->failed_pc=0x0c0727f4u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'-');
goto P_0c0727f6;
P_0c0727f6: /* original 7408, guest PC 0x0c0727f6 */
if(!s->budget--) { s->failed_pc=0x0c0727f6u; return 0; }
r[4]+=0x00000008u;
goto P_0c0727f8;
P_0c0727f8: /* original f42a, guest PC 0x0c0727f8 */
if(!s->budget--) { s->failed_pc=0x0c0727f8u; return 0; }
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c0727fa;
P_0c0727fa: /* original f41b, guest PC 0x0c0727fa */
if(!s->budget--) { s->failed_pc=0x0c0727fau; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c0727fc;
P_0c0727fc: /* original f40b, guest PC 0x0c0727fc */
if(!s->budget--) { s->failed_pc=0x0c0727fcu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c0727fe;
P_0c0727fe: /* original 0009, guest PC 0x0c0727fe */
if(!s->budget--) { s->failed_pc=0x0c0727feu; return 0; }
goto P_0c072800;
P_0c072800: /* original 64a3, guest PC 0x0c072800 */
if(!s->budget--) { s->failed_pc=0x0c072800u; return 0; }
r[4]=r[10];
goto P_0c072802;
P_0c072802: /* original 6583, guest PC 0x0c072802 */
if(!s->budget--) { s->failed_pc=0x0c072802u; return 0; }
r[5]=r[8];
goto P_0c072804;
P_0c072804: /* original 66e3, guest PC 0x0c072804 */
if(!s->budget--) { s->failed_pc=0x0c072804u; return 0; }
r[6]=r[14];
goto P_0c072806;
P_0c072806: /* original f059, guest PC 0x0c072806 */
if(!s->budget--) { s->failed_pc=0x0c072806u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c072808;
P_0c072808: /* original f369, guest PC 0x0c072808 */
if(!s->budget--) { s->failed_pc=0x0c072808u; return 0; }
vf3_matrix_load(s,ram,3,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c07280a;
P_0c07280a: /* original f159, guest PC 0x0c07280a */
if(!s->budget--) { s->failed_pc=0x0c07280au; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c07280c;
P_0c07280c: /* original f469, guest PC 0x0c07280c */
if(!s->budget--) { s->failed_pc=0x0c07280cu; return 0; }
vf3_matrix_load(s,ram,4,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c07280e;
P_0c07280e: /* original f031, guest PC 0x0c07280e */
if(!s->budget--) { s->failed_pc=0x0c07280eu; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'-');
goto P_0c072810;
P_0c072810: /* original f258, guest PC 0x0c072810 */
if(!s->budget--) { s->failed_pc=0x0c072810u; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
goto P_0c072812;
P_0c072812: /* original f568, guest PC 0x0c072812 */
if(!s->budget--) { s->failed_pc=0x0c072812u; return 0; }
vf3_matrix_load(s,ram,5,r[6]);
goto P_0c072814;
P_0c072814: /* original f141, guest PC 0x0c072814 */
if(!s->budget--) { s->failed_pc=0x0c072814u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'-');
goto P_0c072816;
P_0c072816: /* original f251, guest PC 0x0c072816 */
if(!s->budget--) { s->failed_pc=0x0c072816u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'-');
goto P_0c072818;
P_0c072818: /* original 7408, guest PC 0x0c072818 */
if(!s->budget--) { s->failed_pc=0x0c072818u; return 0; }
r[4]+=0x00000008u;
goto P_0c07281a;
P_0c07281a: /* original f42a, guest PC 0x0c07281a */
if(!s->budget--) { s->failed_pc=0x0c07281au; return 0; }
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c07281c;
P_0c07281c: /* original f41b, guest PC 0x0c07281c */
if(!s->budget--) { s->failed_pc=0x0c07281cu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c07281e;
P_0c07281e: /* original f40b, guest PC 0x0c07281e */
if(!s->budget--) { s->failed_pc=0x0c07281eu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c072820;
P_0c072820: /* original 66e3, guest PC 0x0c072820 */
if(!s->budget--) { s->failed_pc=0x0c072820u; return 0; }
r[6]=r[14];
goto P_0c072822;
P_0c072822: /* original 64a3, guest PC 0x0c072822 */
if(!s->budget--) { s->failed_pc=0x0c072822u; return 0; }
r[4]=r[10];
goto P_0c072824;
P_0c072824: /* original 65d3, guest PC 0x0c072824 */
if(!s->budget--) { s->failed_pc=0x0c072824u; return 0; }
r[5]=r[13];
goto P_0c072826;
P_0c072826: /* original 760c, guest PC 0x0c072826 */
if(!s->budget--) { s->failed_pc=0x0c072826u; return 0; }
r[6]+=0x0000000cu;
goto P_0c072828;
P_0c072828: /* original f049, guest PC 0x0c072828 */
if(!s->budget--) { s->failed_pc=0x0c072828u; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c07282a;
P_0c07282a: /* original f549, guest PC 0x0c07282a */
if(!s->budget--) { s->failed_pc=0x0c07282au; return 0; }
vf3_matrix_load(s,ram,5,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c07282c;
P_0c07282c: /* original f648, guest PC 0x0c07282c */
if(!s->budget--) { s->failed_pc=0x0c07282cu; return 0; }
vf3_matrix_load(s,ram,6,r[4]);
goto P_0c07282e;
P_0c07282e: /* original f859, guest PC 0x0c07282e */
if(!s->budget--) { s->failed_pc=0x0c07282eu; return 0; }
vf3_matrix_load(s,ram,8,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c072830;
P_0c072830: /* original f959, guest PC 0x0c072830 */
if(!s->budget--) { s->failed_pc=0x0c072830u; return 0; }
vf3_matrix_load(s,ram,9,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c072832;
P_0c072832: /* original fa58, guest PC 0x0c072832 */
if(!s->budget--) { s->failed_pc=0x0c072832u; return 0; }
vf3_matrix_load(s,ram,10,r[5]);
goto P_0c072834;
P_0c072834: /* original 760c, guest PC 0x0c072834 */
if(!s->budget--) { s->failed_pc=0x0c072834u; return 0; }
r[6]+=0x0000000cu;
goto P_0c072836;
P_0c072836: /* original f35c, guest PC 0x0c072836 */
if(!s->budget--) { s->failed_pc=0x0c072836u; return 0; }
vf3_matrix_move(s,3,5);
goto P_0c072838;
P_0c072838: /* original f382, guest PC 0x0c072838 */
if(!s->budget--) { s->failed_pc=0x0c072838u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[8],r[18],'*');
goto P_0c07283a;
P_0c07283a: /* original f20c, guest PC 0x0c07283a */
if(!s->budget--) { s->failed_pc=0x0c07283au; return 0; }
vf3_matrix_move(s,2,0);
goto P_0c07283c;
P_0c07283c: /* original f2a2, guest PC 0x0c07283c */
if(!s->budget--) { s->failed_pc=0x0c07283cu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[10],r[18],'*');
goto P_0c07283e;
P_0c07283e: /* original f16c, guest PC 0x0c07283e */
if(!s->budget--) { s->failed_pc=0x0c07283eu; return 0; }
vf3_matrix_move(s,1,6);
goto P_0c072840;
P_0c072840: /* original f192, guest PC 0x0c072840 */
if(!s->budget--) { s->failed_pc=0x0c072840u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[9],r[18],'*');
goto P_0c072842;
P_0c072842: /* original f34d, guest PC 0x0c072842 */
if(!s->budget--) { s->failed_pc=0x0c072842u; return 0; }
fr[3]^=0x80000000u;
goto P_0c072844;
P_0c072844: /* original f39e, guest PC 0x0c072844 */
if(!s->budget--) { s->failed_pc=0x0c072844u; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[9],fr[3],r[18]);
goto P_0c072846;
P_0c072846: /* original f24d, guest PC 0x0c072846 */
if(!s->budget--) { s->failed_pc=0x0c072846u; return 0; }
fr[2]^=0x80000000u;
goto P_0c072848;
P_0c072848: /* original f06c, guest PC 0x0c072848 */
if(!s->budget--) { s->failed_pc=0x0c072848u; return 0; }
vf3_matrix_move(s,0,6);
goto P_0c07284a;
P_0c07284a: /* original f28e, guest PC 0x0c07284a */
if(!s->budget--) { s->failed_pc=0x0c07284au; return 0; }
fr[2]=vf3_fpu_mac(fr[0],fr[8],fr[2],r[18]);
goto P_0c07284c;
P_0c07284c: /* original f14d, guest PC 0x0c07284c */
if(!s->budget--) { s->failed_pc=0x0c07284cu; return 0; }
fr[1]^=0x80000000u;
goto P_0c07284e;
P_0c07284e: /* original f63b, guest PC 0x0c07284e */
if(!s->budget--) { s->failed_pc=0x0c07284eu; return 0; }
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,3,r[6]);
goto P_0c072850;
P_0c072850: /* original f05c, guest PC 0x0c072850 */
if(!s->budget--) { s->failed_pc=0x0c072850u; return 0; }
vf3_matrix_move(s,0,5);
goto P_0c072852;
P_0c072852: /* original f1ae, guest PC 0x0c072852 */
if(!s->budget--) { s->failed_pc=0x0c072852u; return 0; }
fr[1]=vf3_fpu_mac(fr[0],fr[10],fr[1],r[18]);
goto P_0c072854;
P_0c072854: /* original f62b, guest PC 0x0c072854 */
if(!s->budget--) { s->failed_pc=0x0c072854u; return 0; }
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[6]);
goto P_0c072856;
P_0c072856: /* original f61b, guest PC 0x0c072856 */
if(!s->budget--) { s->failed_pc=0x0c072856u; return 0; }
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[6]);
goto P_0c072858;
P_0c072858: /* original 64e3, guest PC 0x0c072858 */
if(!s->budget--) { s->failed_pc=0x0c072858u; return 0; }
r[4]=r[14];
goto P_0c07285a;
P_0c07285a: /* original 65e3, guest PC 0x0c07285a */
if(!s->budget--) { s->failed_pc=0x0c07285au; return 0; }
r[5]=r[14];
goto P_0c07285c;
P_0c07285c: /* original 740c, guest PC 0x0c07285c */
if(!s->budget--) { s->failed_pc=0x0c07285cu; return 0; }
r[4]+=0x0000000cu;
goto P_0c07285e;
P_0c07285e: /* original f4fc, guest PC 0x0c07285e */
if(!s->budget--) { s->failed_pc=0x0c07285eu; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c072860;
P_0c072860: /* original 750c, guest PC 0x0c072860 */
if(!s->budget--) { s->failed_pc=0x0c072860u; return 0; }
r[5]+=0x0000000cu;
goto P_0c072862;
P_0c072862: /* original f059, guest PC 0x0c072862 */
if(!s->budget--) { s->failed_pc=0x0c072862u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c072864;
P_0c072864: /* original f159, guest PC 0x0c072864 */
if(!s->budget--) { s->failed_pc=0x0c072864u; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c072866;
P_0c072866: /* original f259, guest PC 0x0c072866 */
if(!s->budget--) { s->failed_pc=0x0c072866u; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c072868;
P_0c072868: /* original f38d, guest PC 0x0c072868 */
if(!s->budget--) { s->failed_pc=0x0c072868u; return 0; }
fr[3]=0;
goto P_0c07286a;
P_0c07286a: /* original f0ed, guest PC 0x0c07286a */
if(!s->budget--) { s->failed_pc=0x0c07286au; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+0,r[18],fr+3)) goto unsupported;
goto P_0c07286c;
P_0c07286c: /* original f37d, guest PC 0x0c07286c */
if(!s->budget--) { s->failed_pc=0x0c07286cu; return 0; }
if(!vf3_fpu_fsrra(fr[3],r[18],&fr[3])) goto unsupported;
goto P_0c07286e;
P_0c07286e: /* original f342, guest PC 0x0c07286e */
if(!s->budget--) { s->failed_pc=0x0c07286eu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'*');
goto P_0c072870;
P_0c072870: /* original 740c, guest PC 0x0c072870 */
if(!s->budget--) { s->failed_pc=0x0c072870u; return 0; }
r[4]+=0x0000000cu;
goto P_0c072872;
P_0c072872: /* original f232, guest PC 0x0c072872 */
if(!s->budget--) { s->failed_pc=0x0c072872u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c072874;
P_0c072874: /* original f132, guest PC 0x0c072874 */
if(!s->budget--) { s->failed_pc=0x0c072874u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[3],r[18],'*');
goto P_0c072876;
P_0c072876: /* original f032, guest PC 0x0c072876 */
if(!s->budget--) { s->failed_pc=0x0c072876u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'*');
goto P_0c072878;
P_0c072878: /* original f42b, guest PC 0x0c072878 */
if(!s->budget--) { s->failed_pc=0x0c072878u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c07287a;
P_0c07287a: /* original f41b, guest PC 0x0c07287a */
if(!s->budget--) { s->failed_pc=0x0c07287au; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c07287c;
P_0c07287c: /* original f40b, guest PC 0x0c07287c */
if(!s->budget--) { s->failed_pc=0x0c07287cu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c07287e;
P_0c07287e: /* original 0009, guest PC 0x0c07287e */
if(!s->budget--) { s->failed_pc=0x0c07287eu; return 0; }
goto P_0c072880;
P_0c072880: /* original 53f5, guest PC 0x0c072880 */
if(!s->budget--) { s->failed_pc=0x0c072880u; return 0; }
r[3]=read(ram,r[15]+20,4);
goto P_0c072882;
P_0c072882: /* original 69e3, guest PC 0x0c072882 */
if(!s->budget--) { s->failed_pc=0x0c072882u; return 0; }
r[9]=r[14];
goto P_0c072884;
P_0c072884: /* original e201, guest PC 0x0c072884 */
if(!s->budget--) { s->failed_pc=0x0c072884u; return 0; }
r[2]=0x00000001u;
goto P_0c072886;
P_0c072886: /* original 6eb3, guest PC 0x0c072886 */
if(!s->budget--) { s->failed_pc=0x0c072886u; return 0; }
r[14]=r[11];
goto P_0c072888;
P_0c072888: /* original 6133, guest PC 0x0c072888 */
if(!s->budget--) { s->failed_pc=0x0c072888u; return 0; }
r[1]=r[3];
goto P_0c07288a;
P_0c07288a: /* original 3127, guest PC 0x0c07288a */
if(!s->budget--) { s->failed_pc=0x0c07288au; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[1]>(int32_t)r[2])!=0);
goto P_0c07288c;
P_0c07288c: /* original 7b18, guest PC 0x0c07288c */
if(!s->budget--) { s->failed_pc=0x0c07288cu; return 0; }
r[11]+=0x00000018u;
goto P_0c07288e;
P_0c07288e: /* original 2f32, guest PC 0x0c07288e */
if(!s->budget--) { s->failed_pc=0x0c07288eu; return 0; }
write(ram,r[15],r[3],4);
goto P_0c072890;
P_0c072890: /* original 8d03, guest PC 0x0c072890 */
if(!s->budget--) { s->failed_pc=0x0c072890u; return 0; }
cond=r[17]&1u;
r[8]+=0x00000018u;
if(cond) { goto P_0c07289a; }
goto P_0c072894;
P_0c072892: /* original 7818, guest PC 0x0c072892 */
if(!s->budget--) { s->failed_pc=0x0c072892u; return 0; }
r[8]+=0x00000018u;
goto P_0c072894;
P_0c072894: /* original d303, guest PC 0x0c072894 */
if(!s->budget--) { s->failed_pc=0x0c072894u; return 0; }
r[3]=read(ram,0x0c0728a4u,4);
goto P_0c072896;
P_0c072896: /* original 432b, guest PC 0x0c072896 */
if(!s->budget--) { s->failed_pc=0x0c072896u; return 0; }
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
P_0c072898: /* original 0009, guest PC 0x0c072898 */
if(!s->budget--) { s->failed_pc=0x0c072898u; return 0; }
goto P_0c07289a;
P_0c07289a: /* original 64d3, guest PC 0x0c07289a */
if(!s->budget--) { s->failed_pc=0x0c07289au; return 0; }
r[4]=r[13];
goto P_0c07289c;
P_0c07289c: /* original 6593, guest PC 0x0c07289c */
if(!s->budget--) { s->failed_pc=0x0c07289cu; return 0; }
r[5]=r[9];
goto P_0c07289e;
P_0c07289e: /* original 66e3, guest PC 0x0c07289e */
if(!s->budget--) { s->failed_pc=0x0c07289eu; return 0; }
r[6]=r[14];
goto P_0c0728a0;
P_0c0728a0: /* original a002, guest PC 0x0c0728a0 */
if(!s->budget--) { s->failed_pc=0x0c0728a0u; return 0; }
goto P_0c0728a8;
P_0c0728a2: /* original 0009, guest PC 0x0c0728a2 */
if(!s->budget--) { s->failed_pc=0x0c0728a2u; return 0; }
return vf3_matrix_family(0x0c0728a4u,s,ram);
P_0c0728a8: /* original f059, guest PC 0x0c0728a8 */
if(!s->budget--) { s->failed_pc=0x0c0728a8u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0728aa;
P_0c0728aa: /* original f369, guest PC 0x0c0728aa */
if(!s->budget--) { s->failed_pc=0x0c0728aau; return 0; }
vf3_matrix_load(s,ram,3,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c0728ac;
P_0c0728ac: /* original f159, guest PC 0x0c0728ac */
if(!s->budget--) { s->failed_pc=0x0c0728acu; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0728ae;
P_0c0728ae: /* original f469, guest PC 0x0c0728ae */
if(!s->budget--) { s->failed_pc=0x0c0728aeu; return 0; }
vf3_matrix_load(s,ram,4,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c0728b0;
P_0c0728b0: /* original f031, guest PC 0x0c0728b0 */
if(!s->budget--) { s->failed_pc=0x0c0728b0u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'-');
goto P_0c0728b2;
P_0c0728b2: /* original f258, guest PC 0x0c0728b2 */
if(!s->budget--) { s->failed_pc=0x0c0728b2u; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
goto P_0c0728b4;
P_0c0728b4: /* original f568, guest PC 0x0c0728b4 */
if(!s->budget--) { s->failed_pc=0x0c0728b4u; return 0; }
vf3_matrix_load(s,ram,5,r[6]);
goto P_0c0728b6;
P_0c0728b6: /* original f141, guest PC 0x0c0728b6 */
if(!s->budget--) { s->failed_pc=0x0c0728b6u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'-');
goto P_0c0728b8;
P_0c0728b8: /* original f251, guest PC 0x0c0728b8 */
if(!s->budget--) { s->failed_pc=0x0c0728b8u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'-');
goto P_0c0728ba;
P_0c0728ba: /* original 7408, guest PC 0x0c0728ba */
if(!s->budget--) { s->failed_pc=0x0c0728bau; return 0; }
r[4]+=0x00000008u;
goto P_0c0728bc;
P_0c0728bc: /* original f42a, guest PC 0x0c0728bc */
if(!s->budget--) { s->failed_pc=0x0c0728bcu; return 0; }
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c0728be;
P_0c0728be: /* original f41b, guest PC 0x0c0728be */
if(!s->budget--) { s->failed_pc=0x0c0728beu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c0728c0;
P_0c0728c0: /* original f40b, guest PC 0x0c0728c0 */
if(!s->budget--) { s->failed_pc=0x0c0728c0u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c0728c2;
P_0c0728c2: /* original 0009, guest PC 0x0c0728c2 */
if(!s->budget--) { s->failed_pc=0x0c0728c2u; return 0; }
goto P_0c0728c4;
P_0c0728c4: /* original 64a3, guest PC 0x0c0728c4 */
if(!s->budget--) { s->failed_pc=0x0c0728c4u; return 0; }
r[4]=r[10];
goto P_0c0728c6;
P_0c0728c6: /* original 65b3, guest PC 0x0c0728c6 */
if(!s->budget--) { s->failed_pc=0x0c0728c6u; return 0; }
r[5]=r[11];
goto P_0c0728c8;
P_0c0728c8: /* original 66e3, guest PC 0x0c0728c8 */
if(!s->budget--) { s->failed_pc=0x0c0728c8u; return 0; }
r[6]=r[14];
goto P_0c0728ca;
P_0c0728ca: /* original f059, guest PC 0x0c0728ca */
if(!s->budget--) { s->failed_pc=0x0c0728cau; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0728cc;
P_0c0728cc: /* original f369, guest PC 0x0c0728cc */
if(!s->budget--) { s->failed_pc=0x0c0728ccu; return 0; }
vf3_matrix_load(s,ram,3,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c0728ce;
P_0c0728ce: /* original f159, guest PC 0x0c0728ce */
if(!s->budget--) { s->failed_pc=0x0c0728ceu; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0728d0;
P_0c0728d0: /* original f469, guest PC 0x0c0728d0 */
if(!s->budget--) { s->failed_pc=0x0c0728d0u; return 0; }
vf3_matrix_load(s,ram,4,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c0728d2;
P_0c0728d2: /* original f031, guest PC 0x0c0728d2 */
if(!s->budget--) { s->failed_pc=0x0c0728d2u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'-');
goto P_0c0728d4;
P_0c0728d4: /* original f258, guest PC 0x0c0728d4 */
if(!s->budget--) { s->failed_pc=0x0c0728d4u; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
goto P_0c0728d6;
P_0c0728d6: /* original f568, guest PC 0x0c0728d6 */
if(!s->budget--) { s->failed_pc=0x0c0728d6u; return 0; }
vf3_matrix_load(s,ram,5,r[6]);
goto P_0c0728d8;
P_0c0728d8: /* original f141, guest PC 0x0c0728d8 */
if(!s->budget--) { s->failed_pc=0x0c0728d8u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'-');
goto P_0c0728da;
P_0c0728da: /* original f251, guest PC 0x0c0728da */
if(!s->budget--) { s->failed_pc=0x0c0728dau; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'-');
goto P_0c0728dc;
P_0c0728dc: /* original 7408, guest PC 0x0c0728dc */
if(!s->budget--) { s->failed_pc=0x0c0728dcu; return 0; }
r[4]+=0x00000008u;
goto P_0c0728de;
P_0c0728de: /* original f42a, guest PC 0x0c0728de */
if(!s->budget--) { s->failed_pc=0x0c0728deu; return 0; }
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c0728e0;
P_0c0728e0: /* original f41b, guest PC 0x0c0728e0 */
if(!s->budget--) { s->failed_pc=0x0c0728e0u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c0728e2;
P_0c0728e2: /* original f40b, guest PC 0x0c0728e2 */
if(!s->budget--) { s->failed_pc=0x0c0728e2u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c0728e4;
P_0c0728e4: /* original 64c3, guest PC 0x0c0728e4 */
if(!s->budget--) { s->failed_pc=0x0c0728e4u; return 0; }
r[4]=r[12];
goto P_0c0728e6;
P_0c0728e6: /* original 6583, guest PC 0x0c0728e6 */
if(!s->budget--) { s->failed_pc=0x0c0728e6u; return 0; }
r[5]=r[8];
goto P_0c0728e8;
P_0c0728e8: /* original 66e3, guest PC 0x0c0728e8 */
if(!s->budget--) { s->failed_pc=0x0c0728e8u; return 0; }
r[6]=r[14];
goto P_0c0728ea;
P_0c0728ea: /* original f059, guest PC 0x0c0728ea */
if(!s->budget--) { s->failed_pc=0x0c0728eau; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0728ec;
P_0c0728ec: /* original f369, guest PC 0x0c0728ec */
if(!s->budget--) { s->failed_pc=0x0c0728ecu; return 0; }
vf3_matrix_load(s,ram,3,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c0728ee;
P_0c0728ee: /* original f159, guest PC 0x0c0728ee */
if(!s->budget--) { s->failed_pc=0x0c0728eeu; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0728f0;
P_0c0728f0: /* original f469, guest PC 0x0c0728f0 */
if(!s->budget--) { s->failed_pc=0x0c0728f0u; return 0; }
vf3_matrix_load(s,ram,4,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c0728f2;
P_0c0728f2: /* original f031, guest PC 0x0c0728f2 */
if(!s->budget--) { s->failed_pc=0x0c0728f2u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'-');
goto P_0c0728f4;
P_0c0728f4: /* original f258, guest PC 0x0c0728f4 */
if(!s->budget--) { s->failed_pc=0x0c0728f4u; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
goto P_0c0728f6;
P_0c0728f6: /* original f568, guest PC 0x0c0728f6 */
if(!s->budget--) { s->failed_pc=0x0c0728f6u; return 0; }
vf3_matrix_load(s,ram,5,r[6]);
goto P_0c0728f8;
P_0c0728f8: /* original f141, guest PC 0x0c0728f8 */
if(!s->budget--) { s->failed_pc=0x0c0728f8u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'-');
goto P_0c0728fa;
P_0c0728fa: /* original f251, guest PC 0x0c0728fa */
if(!s->budget--) { s->failed_pc=0x0c0728fau; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'-');
goto P_0c0728fc;
P_0c0728fc: /* original 7408, guest PC 0x0c0728fc */
if(!s->budget--) { s->failed_pc=0x0c0728fcu; return 0; }
r[4]+=0x00000008u;
goto P_0c0728fe;
P_0c0728fe: /* original f42a, guest PC 0x0c0728fe */
if(!s->budget--) { s->failed_pc=0x0c0728feu; return 0; }
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c072900;
P_0c072900: /* original f41b, guest PC 0x0c072900 */
if(!s->budget--) { s->failed_pc=0x0c072900u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c072902;
P_0c072902: /* original f40b, guest PC 0x0c072902 */
if(!s->budget--) { s->failed_pc=0x0c072902u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c072904;
P_0c072904: /* original 66f3, guest PC 0x0c072904 */
if(!s->budget--) { s->failed_pc=0x0c072904u; return 0; }
r[6]=r[15];
goto P_0c072906;
P_0c072906: /* original 64c3, guest PC 0x0c072906 */
if(!s->budget--) { s->failed_pc=0x0c072906u; return 0; }
r[4]=r[12];
goto P_0c072908;
P_0c072908: /* original 65a3, guest PC 0x0c072908 */
if(!s->budget--) { s->failed_pc=0x0c072908u; return 0; }
r[5]=r[10];
goto P_0c07290a;
P_0c07290a: /* original 7624, guest PC 0x0c07290a */
if(!s->budget--) { s->failed_pc=0x0c07290au; return 0; }
r[6]+=0x00000024u;
goto P_0c07290c;
P_0c07290c: /* original f049, guest PC 0x0c07290c */
if(!s->budget--) { s->failed_pc=0x0c07290cu; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c07290e;
P_0c07290e: /* original f549, guest PC 0x0c07290e */
if(!s->budget--) { s->failed_pc=0x0c07290eu; return 0; }
vf3_matrix_load(s,ram,5,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c072910;
P_0c072910: /* original f648, guest PC 0x0c072910 */
if(!s->budget--) { s->failed_pc=0x0c072910u; return 0; }
vf3_matrix_load(s,ram,6,r[4]);
goto P_0c072912;
P_0c072912: /* original f859, guest PC 0x0c072912 */
if(!s->budget--) { s->failed_pc=0x0c072912u; return 0; }
vf3_matrix_load(s,ram,8,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c072914;
P_0c072914: /* original f959, guest PC 0x0c072914 */
if(!s->budget--) { s->failed_pc=0x0c072914u; return 0; }
vf3_matrix_load(s,ram,9,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c072916;
P_0c072916: /* original fa58, guest PC 0x0c072916 */
if(!s->budget--) { s->failed_pc=0x0c072916u; return 0; }
vf3_matrix_load(s,ram,10,r[5]);
goto P_0c072918;
P_0c072918: /* original 760c, guest PC 0x0c072918 */
if(!s->budget--) { s->failed_pc=0x0c072918u; return 0; }
r[6]+=0x0000000cu;
goto P_0c07291a;
P_0c07291a: /* original f35c, guest PC 0x0c07291a */
if(!s->budget--) { s->failed_pc=0x0c07291au; return 0; }
vf3_matrix_move(s,3,5);
goto P_0c07291c;
P_0c07291c: /* original f382, guest PC 0x0c07291c */
if(!s->budget--) { s->failed_pc=0x0c07291cu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[8],r[18],'*');
goto P_0c07291e;
P_0c07291e: /* original f20c, guest PC 0x0c07291e */
if(!s->budget--) { s->failed_pc=0x0c07291eu; return 0; }
vf3_matrix_move(s,2,0);
goto P_0c072920;
P_0c072920: /* original f2a2, guest PC 0x0c072920 */
if(!s->budget--) { s->failed_pc=0x0c072920u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[10],r[18],'*');
goto P_0c072922;
P_0c072922: /* original f16c, guest PC 0x0c072922 */
if(!s->budget--) { s->failed_pc=0x0c072922u; return 0; }
vf3_matrix_move(s,1,6);
goto P_0c072924;
P_0c072924: /* original f192, guest PC 0x0c072924 */
if(!s->budget--) { s->failed_pc=0x0c072924u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[9],r[18],'*');
goto P_0c072926;
P_0c072926: /* original f34d, guest PC 0x0c072926 */
if(!s->budget--) { s->failed_pc=0x0c072926u; return 0; }
fr[3]^=0x80000000u;
goto P_0c072928;
P_0c072928: /* original f39e, guest PC 0x0c072928 */
if(!s->budget--) { s->failed_pc=0x0c072928u; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[9],fr[3],r[18]);
goto P_0c07292a;
P_0c07292a: /* original f24d, guest PC 0x0c07292a */
if(!s->budget--) { s->failed_pc=0x0c07292au; return 0; }
fr[2]^=0x80000000u;
goto P_0c07292c;
P_0c07292c: /* original f06c, guest PC 0x0c07292c */
if(!s->budget--) { s->failed_pc=0x0c07292cu; return 0; }
vf3_matrix_move(s,0,6);
goto P_0c07292e;
P_0c07292e: /* original f28e, guest PC 0x0c07292e */
if(!s->budget--) { s->failed_pc=0x0c07292eu; return 0; }
fr[2]=vf3_fpu_mac(fr[0],fr[8],fr[2],r[18]);
goto P_0c072930;
P_0c072930: /* original f14d, guest PC 0x0c072930 */
if(!s->budget--) { s->failed_pc=0x0c072930u; return 0; }
fr[1]^=0x80000000u;
goto P_0c072932;
P_0c072932: /* original f63b, guest PC 0x0c072932 */
if(!s->budget--) { s->failed_pc=0x0c072932u; return 0; }
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,3,r[6]);
goto P_0c072934;
P_0c072934: /* original f05c, guest PC 0x0c072934 */
if(!s->budget--) { s->failed_pc=0x0c072934u; return 0; }
vf3_matrix_move(s,0,5);
goto P_0c072936;
P_0c072936: /* original f1ae, guest PC 0x0c072936 */
if(!s->budget--) { s->failed_pc=0x0c072936u; return 0; }
fr[1]=vf3_fpu_mac(fr[0],fr[10],fr[1],r[18]);
goto P_0c072938;
P_0c072938: /* original f62b, guest PC 0x0c072938 */
if(!s->budget--) { s->failed_pc=0x0c072938u; return 0; }
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[6]);
goto P_0c07293a;
P_0c07293a: /* original f61b, guest PC 0x0c07293a */
if(!s->budget--) { s->failed_pc=0x0c07293au; return 0; }
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[6]);
goto P_0c07293c;
P_0c07293c: /* original 66f3, guest PC 0x0c07293c */
if(!s->budget--) { s->failed_pc=0x0c07293cu; return 0; }
r[6]=r[15];
goto P_0c07293e;
P_0c07293e: /* original 64d3, guest PC 0x0c07293e */
if(!s->budget--) { s->failed_pc=0x0c07293eu; return 0; }
r[4]=r[13];
goto P_0c072940;
P_0c072940: /* original 65c3, guest PC 0x0c072940 */
if(!s->budget--) { s->failed_pc=0x0c072940u; return 0; }
r[5]=r[12];
goto P_0c072942;
P_0c072942: /* original 7618, guest PC 0x0c072942 */
if(!s->budget--) { s->failed_pc=0x0c072942u; return 0; }
r[6]+=0x00000018u;
goto P_0c072944;
P_0c072944: /* original f049, guest PC 0x0c072944 */
if(!s->budget--) { s->failed_pc=0x0c072944u; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c072946;
P_0c072946: /* original f549, guest PC 0x0c072946 */
if(!s->budget--) { s->failed_pc=0x0c072946u; return 0; }
vf3_matrix_load(s,ram,5,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c072948;
P_0c072948: /* original f648, guest PC 0x0c072948 */
if(!s->budget--) { s->failed_pc=0x0c072948u; return 0; }
vf3_matrix_load(s,ram,6,r[4]);
goto P_0c07294a;
P_0c07294a: /* original f859, guest PC 0x0c07294a */
if(!s->budget--) { s->failed_pc=0x0c07294au; return 0; }
vf3_matrix_load(s,ram,8,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c07294c;
P_0c07294c: /* original f959, guest PC 0x0c07294c */
if(!s->budget--) { s->failed_pc=0x0c07294cu; return 0; }
vf3_matrix_load(s,ram,9,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c07294e;
P_0c07294e: /* original fa58, guest PC 0x0c07294e */
if(!s->budget--) { s->failed_pc=0x0c07294eu; return 0; }
vf3_matrix_load(s,ram,10,r[5]);
goto P_0c072950;
P_0c072950: /* original 760c, guest PC 0x0c072950 */
if(!s->budget--) { s->failed_pc=0x0c072950u; return 0; }
r[6]+=0x0000000cu;
goto P_0c072952;
P_0c072952: /* original f35c, guest PC 0x0c072952 */
if(!s->budget--) { s->failed_pc=0x0c072952u; return 0; }
vf3_matrix_move(s,3,5);
goto P_0c072954;
P_0c072954: /* original f382, guest PC 0x0c072954 */
if(!s->budget--) { s->failed_pc=0x0c072954u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[8],r[18],'*');
goto P_0c072956;
P_0c072956: /* original f20c, guest PC 0x0c072956 */
if(!s->budget--) { s->failed_pc=0x0c072956u; return 0; }
vf3_matrix_move(s,2,0);
goto P_0c072958;
P_0c072958: /* original f2a2, guest PC 0x0c072958 */
if(!s->budget--) { s->failed_pc=0x0c072958u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[10],r[18],'*');
goto P_0c07295a;
P_0c07295a: /* original f16c, guest PC 0x0c07295a */
if(!s->budget--) { s->failed_pc=0x0c07295au; return 0; }
vf3_matrix_move(s,1,6);
goto P_0c07295c;
P_0c07295c: /* original f192, guest PC 0x0c07295c */
if(!s->budget--) { s->failed_pc=0x0c07295cu; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[9],r[18],'*');
goto P_0c07295e;
P_0c07295e: /* original f34d, guest PC 0x0c07295e */
if(!s->budget--) { s->failed_pc=0x0c07295eu; return 0; }
fr[3]^=0x80000000u;
goto P_0c072960;
P_0c072960: /* original f39e, guest PC 0x0c072960 */
if(!s->budget--) { s->failed_pc=0x0c072960u; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[9],fr[3],r[18]);
goto P_0c072962;
P_0c072962: /* original f24d, guest PC 0x0c072962 */
if(!s->budget--) { s->failed_pc=0x0c072962u; return 0; }
fr[2]^=0x80000000u;
goto P_0c072964;
P_0c072964: /* original f06c, guest PC 0x0c072964 */
if(!s->budget--) { s->failed_pc=0x0c072964u; return 0; }
vf3_matrix_move(s,0,6);
goto P_0c072966;
P_0c072966: /* original f28e, guest PC 0x0c072966 */
if(!s->budget--) { s->failed_pc=0x0c072966u; return 0; }
fr[2]=vf3_fpu_mac(fr[0],fr[8],fr[2],r[18]);
goto P_0c072968;
P_0c072968: /* original f14d, guest PC 0x0c072968 */
if(!s->budget--) { s->failed_pc=0x0c072968u; return 0; }
fr[1]^=0x80000000u;
goto P_0c07296a;
P_0c07296a: /* original f63b, guest PC 0x0c07296a */
if(!s->budget--) { s->failed_pc=0x0c07296au; return 0; }
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,3,r[6]);
goto P_0c07296c;
P_0c07296c: /* original f05c, guest PC 0x0c07296c */
if(!s->budget--) { s->failed_pc=0x0c07296cu; return 0; }
vf3_matrix_move(s,0,5);
goto P_0c07296e;
P_0c07296e: /* original f1ae, guest PC 0x0c07296e */
if(!s->budget--) { s->failed_pc=0x0c07296eu; return 0; }
fr[1]=vf3_fpu_mac(fr[0],fr[10],fr[1],r[18]);
goto P_0c072970;
P_0c072970: /* original f62b, guest PC 0x0c072970 */
if(!s->budget--) { s->failed_pc=0x0c072970u; return 0; }
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[6]);
goto P_0c072972;
P_0c072972: /* original f61b, guest PC 0x0c072972 */
if(!s->budget--) { s->failed_pc=0x0c072972u; return 0; }
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[6]);
goto P_0c072974;
P_0c072974: /* original 64f3, guest PC 0x0c072974 */
if(!s->budget--) { s->failed_pc=0x0c072974u; return 0; }
r[4]=r[15];
goto P_0c072976;
P_0c072976: /* original 7424, guest PC 0x0c072976 */
if(!s->budget--) { s->failed_pc=0x0c072976u; return 0; }
r[4]+=0x00000024u;
goto P_0c072978;
P_0c072978: /* original f049, guest PC 0x0c072978 */
if(!s->budget--) { s->failed_pc=0x0c072978u; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c07297a;
P_0c07297a: /* original f149, guest PC 0x0c07297a */
if(!s->budget--) { s->failed_pc=0x0c07297au; return 0; }
vf3_matrix_load(s,ram,1,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c07297c;
P_0c07297c: /* original f249, guest PC 0x0c07297c */
if(!s->budget--) { s->failed_pc=0x0c07297cu; return 0; }
vf3_matrix_load(s,ram,2,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c07297e;
P_0c07297e: /* original f38d, guest PC 0x0c07297e */
if(!s->budget--) { s->failed_pc=0x0c07297eu; return 0; }
fr[3]=0;
goto P_0c072980;
P_0c072980: /* original f0ed, guest PC 0x0c072980 */
if(!s->budget--) { s->failed_pc=0x0c072980u; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+0,r[18],fr+3)) goto unsupported;
goto P_0c072982;
P_0c072982: /* original f37d, guest PC 0x0c072982 */
if(!s->budget--) { s->failed_pc=0x0c072982u; return 0; }
if(!vf3_fpu_fsrra(fr[3],r[18],&fr[3])) goto unsupported;
goto P_0c072984;
P_0c072984: /* original f232, guest PC 0x0c072984 */
if(!s->budget--) { s->failed_pc=0x0c072984u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c072986;
P_0c072986: /* original f132, guest PC 0x0c072986 */
if(!s->budget--) { s->failed_pc=0x0c072986u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[3],r[18],'*');
goto P_0c072988;
P_0c072988: /* original f032, guest PC 0x0c072988 */
if(!s->budget--) { s->failed_pc=0x0c072988u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'*');
goto P_0c07298a;
P_0c07298a: /* original f42b, guest PC 0x0c07298a */
if(!s->budget--) { s->failed_pc=0x0c07298au; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c07298c;
P_0c07298c: /* original f41b, guest PC 0x0c07298c */
if(!s->budget--) { s->failed_pc=0x0c07298cu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c07298e;
P_0c07298e: /* original f40b, guest PC 0x0c07298e */
if(!s->budget--) { s->failed_pc=0x0c07298eu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c072990;
P_0c072990: /* original 64f3, guest PC 0x0c072990 */
if(!s->budget--) { s->failed_pc=0x0c072990u; return 0; }
r[4]=r[15];
goto P_0c072992;
P_0c072992: /* original 7418, guest PC 0x0c072992 */
if(!s->budget--) { s->failed_pc=0x0c072992u; return 0; }
r[4]+=0x00000018u;
goto P_0c072994;
P_0c072994: /* original f049, guest PC 0x0c072994 */
if(!s->budget--) { s->failed_pc=0x0c072994u; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c072996;
P_0c072996: /* original f149, guest PC 0x0c072996 */
if(!s->budget--) { s->failed_pc=0x0c072996u; return 0; }
vf3_matrix_load(s,ram,1,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c072998;
P_0c072998: /* original f249, guest PC 0x0c072998 */
if(!s->budget--) { s->failed_pc=0x0c072998u; return 0; }
vf3_matrix_load(s,ram,2,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c07299a;
P_0c07299a: /* original f38d, guest PC 0x0c07299a */
if(!s->budget--) { s->failed_pc=0x0c07299au; return 0; }
fr[3]=0;
goto P_0c07299c;
P_0c07299c: /* original f0ed, guest PC 0x0c07299c */
if(!s->budget--) { s->failed_pc=0x0c07299cu; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+0,r[18],fr+3)) goto unsupported;
goto P_0c07299e;
P_0c07299e: /* original f37d, guest PC 0x0c07299e */
if(!s->budget--) { s->failed_pc=0x0c07299eu; return 0; }
if(!vf3_fpu_fsrra(fr[3],r[18],&fr[3])) goto unsupported;
goto P_0c0729a0;
P_0c0729a0: /* original f232, guest PC 0x0c0729a0 */
if(!s->budget--) { s->failed_pc=0x0c0729a0u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c0729a2;
P_0c0729a2: /* original f132, guest PC 0x0c0729a2 */
if(!s->budget--) { s->failed_pc=0x0c0729a2u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[3],r[18],'*');
goto P_0c0729a4;
P_0c0729a4: /* original f032, guest PC 0x0c0729a4 */
if(!s->budget--) { s->failed_pc=0x0c0729a4u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'*');
goto P_0c0729a6;
P_0c0729a6: /* original f42b, guest PC 0x0c0729a6 */
if(!s->budget--) { s->failed_pc=0x0c0729a6u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c0729a8;
P_0c0729a8: /* original f41b, guest PC 0x0c0729a8 */
if(!s->budget--) { s->failed_pc=0x0c0729a8u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c0729aa;
P_0c0729aa: /* original f40b, guest PC 0x0c0729aa */
if(!s->budget--) { s->failed_pc=0x0c0729aau; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c0729ac;
P_0c0729ac: /* original 65f3, guest PC 0x0c0729ac */
if(!s->budget--) { s->failed_pc=0x0c0729acu; return 0; }
r[5]=r[15];
goto P_0c0729ae;
P_0c0729ae: /* original 64e3, guest PC 0x0c0729ae */
if(!s->budget--) { s->failed_pc=0x0c0729aeu; return 0; }
r[4]=r[14];
goto P_0c0729b0;
P_0c0729b0: /* original 66f3, guest PC 0x0c0729b0 */
if(!s->budget--) { s->failed_pc=0x0c0729b0u; return 0; }
r[6]=r[15];
goto P_0c0729b2;
P_0c0729b2: /* original 740c, guest PC 0x0c0729b2 */
if(!s->budget--) { s->failed_pc=0x0c0729b2u; return 0; }
r[4]+=0x0000000cu;
goto P_0c0729b4;
P_0c0729b4: /* original 7618, guest PC 0x0c0729b4 */
if(!s->budget--) { s->failed_pc=0x0c0729b4u; return 0; }
r[6]+=0x00000018u;
goto P_0c0729b6;
P_0c0729b6: /* original 7524, guest PC 0x0c0729b6 */
if(!s->budget--) { s->failed_pc=0x0c0729b6u; return 0; }
r[5]+=0x00000024u;
goto P_0c0729b8;
P_0c0729b8: /* original f059, guest PC 0x0c0729b8 */
if(!s->budget--) { s->failed_pc=0x0c0729b8u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0729ba;
P_0c0729ba: /* original f369, guest PC 0x0c0729ba */
if(!s->budget--) { s->failed_pc=0x0c0729bau; return 0; }
vf3_matrix_load(s,ram,3,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c0729bc;
P_0c0729bc: /* original f159, guest PC 0x0c0729bc */
if(!s->budget--) { s->failed_pc=0x0c0729bcu; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0729be;
P_0c0729be: /* original f469, guest PC 0x0c0729be */
if(!s->budget--) { s->failed_pc=0x0c0729beu; return 0; }
vf3_matrix_load(s,ram,4,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c0729c0;
P_0c0729c0: /* original f259, guest PC 0x0c0729c0 */
if(!s->budget--) { s->failed_pc=0x0c0729c0u; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0729c2;
P_0c0729c2: /* original f569, guest PC 0x0c0729c2 */
if(!s->budget--) { s->failed_pc=0x0c0729c2u; return 0; }
vf3_matrix_load(s,ram,5,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c0729c4;
P_0c0729c4: /* original 740c, guest PC 0x0c0729c4 */
if(!s->budget--) { s->failed_pc=0x0c0729c4u; return 0; }
r[4]+=0x0000000cu;
goto P_0c0729c6;
P_0c0729c6: /* original f030, guest PC 0x0c0729c6 */
if(!s->budget--) { s->failed_pc=0x0c0729c6u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'+');
goto P_0c0729c8;
P_0c0729c8: /* original f250, guest PC 0x0c0729c8 */
if(!s->budget--) { s->failed_pc=0x0c0729c8u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'+');
goto P_0c0729ca;
P_0c0729ca: /* original f140, guest PC 0x0c0729ca */
if(!s->budget--) { s->failed_pc=0x0c0729cau; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'+');
goto P_0c0729cc;
P_0c0729cc: /* original f42b, guest PC 0x0c0729cc */
if(!s->budget--) { s->failed_pc=0x0c0729ccu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c0729ce;
P_0c0729ce: /* original f41b, guest PC 0x0c0729ce */
if(!s->budget--) { s->failed_pc=0x0c0729ceu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c0729d0;
P_0c0729d0: /* original f40b, guest PC 0x0c0729d0 */
if(!s->budget--) { s->failed_pc=0x0c0729d0u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c0729d2;
P_0c0729d2: /* original 0009, guest PC 0x0c0729d2 */
if(!s->budget--) { s->failed_pc=0x0c0729d2u; return 0; }
goto P_0c0729d4;
P_0c0729d4: /* original 64e3, guest PC 0x0c0729d4 */
if(!s->budget--) { s->failed_pc=0x0c0729d4u; return 0; }
r[4]=r[14];
goto P_0c0729d6;
P_0c0729d6: /* original 65e3, guest PC 0x0c0729d6 */
if(!s->budget--) { s->failed_pc=0x0c0729d6u; return 0; }
r[5]=r[14];
goto P_0c0729d8;
P_0c0729d8: /* original 740c, guest PC 0x0c0729d8 */
if(!s->budget--) { s->failed_pc=0x0c0729d8u; return 0; }
r[4]+=0x0000000cu;
goto P_0c0729da;
P_0c0729da: /* original f4fc, guest PC 0x0c0729da */
if(!s->budget--) { s->failed_pc=0x0c0729dau; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c0729dc;
P_0c0729dc: /* original 750c, guest PC 0x0c0729dc */
if(!s->budget--) { s->failed_pc=0x0c0729dcu; return 0; }
r[5]+=0x0000000cu;
goto P_0c0729de;
P_0c0729de: /* original f059, guest PC 0x0c0729de */
if(!s->budget--) { s->failed_pc=0x0c0729deu; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0729e0;
P_0c0729e0: /* original f159, guest PC 0x0c0729e0 */
if(!s->budget--) { s->failed_pc=0x0c0729e0u; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0729e2;
P_0c0729e2: /* original f259, guest PC 0x0c0729e2 */
if(!s->budget--) { s->failed_pc=0x0c0729e2u; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0729e4;
P_0c0729e4: /* original f38d, guest PC 0x0c0729e4 */
if(!s->budget--) { s->failed_pc=0x0c0729e4u; return 0; }
fr[3]=0;
goto P_0c0729e6;
P_0c0729e6: /* original f0ed, guest PC 0x0c0729e6 */
if(!s->budget--) { s->failed_pc=0x0c0729e6u; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+0,r[18],fr+3)) goto unsupported;
goto P_0c0729e8;
P_0c0729e8: /* original f37d, guest PC 0x0c0729e8 */
if(!s->budget--) { s->failed_pc=0x0c0729e8u; return 0; }
if(!vf3_fpu_fsrra(fr[3],r[18],&fr[3])) goto unsupported;
goto P_0c0729ea;
P_0c0729ea: /* original f342, guest PC 0x0c0729ea */
if(!s->budget--) { s->failed_pc=0x0c0729eau; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'*');
goto P_0c0729ec;
P_0c0729ec: /* original 740c, guest PC 0x0c0729ec */
if(!s->budget--) { s->failed_pc=0x0c0729ecu; return 0; }
r[4]+=0x0000000cu;
goto P_0c0729ee;
P_0c0729ee: /* original f232, guest PC 0x0c0729ee */
if(!s->budget--) { s->failed_pc=0x0c0729eeu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c0729f0;
P_0c0729f0: /* original f132, guest PC 0x0c0729f0 */
if(!s->budget--) { s->failed_pc=0x0c0729f0u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[3],r[18],'*');
goto P_0c0729f2;
P_0c0729f2: /* original f032, guest PC 0x0c0729f2 */
if(!s->budget--) { s->failed_pc=0x0c0729f2u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'*');
goto P_0c0729f4;
P_0c0729f4: /* original f42b, guest PC 0x0c0729f4 */
if(!s->budget--) { s->failed_pc=0x0c0729f4u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c0729f6;
P_0c0729f6: /* original f41b, guest PC 0x0c0729f6 */
if(!s->budget--) { s->failed_pc=0x0c0729f6u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c0729f8;
P_0c0729f8: /* original f40b, guest PC 0x0c0729f8 */
if(!s->budget--) { s->failed_pc=0x0c0729f8u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c0729fa;
P_0c0729fa: /* original 0009, guest PC 0x0c0729fa */
if(!s->budget--) { s->failed_pc=0x0c0729fau; return 0; }
goto P_0c0729fc;
P_0c0729fc: /* original 63f2, guest PC 0x0c0729fc */
if(!s->budget--) { s->failed_pc=0x0c0729fcu; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c0729fe;
P_0c0729fe: /* original 69e3, guest PC 0x0c0729fe */
if(!s->budget--) { s->failed_pc=0x0c0729feu; return 0; }
r[9]=r[14];
goto P_0c072a00;
P_0c072a00: /* original e201, guest PC 0x0c072a00 */
if(!s->budget--) { s->failed_pc=0x0c072a00u; return 0; }
r[2]=0x00000001u;
goto P_0c072a02;
P_0c072a02: /* original 6eb3, guest PC 0x0c072a02 */
if(!s->budget--) { s->failed_pc=0x0c072a02u; return 0; }
r[14]=r[11];
goto P_0c072a04;
P_0c072a04: /* original 73ff, guest PC 0x0c072a04 */
if(!s->budget--) { s->failed_pc=0x0c072a04u; return 0; }
r[3]+=0xffffffffu;
goto P_0c072a06;
P_0c072a06: /* original 3327, guest PC 0x0c072a06 */
if(!s->budget--) { s->failed_pc=0x0c072a06u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>(int32_t)r[2])!=0);
goto P_0c072a08;
P_0c072a08: /* original 7b18, guest PC 0x0c072a08 */
if(!s->budget--) { s->failed_pc=0x0c072a08u; return 0; }
r[11]+=0x00000018u;
goto P_0c072a0a;
P_0c072a0a: /* original 7818, guest PC 0x0c072a0a */
if(!s->budget--) { s->failed_pc=0x0c072a0au; return 0; }
r[8]+=0x00000018u;
goto P_0c072a0c;
P_0c072a0c: /* original 8f03, guest PC 0x0c072a0c */
if(!s->budget--) { s->failed_pc=0x0c072a0cu; return 0; }
cond=r[17]&1u;
write(ram,r[15],r[3],4);
if(!cond) { goto P_0c072a16; }
goto P_0c072a10;
P_0c072a0e: /* original 2f32, guest PC 0x0c072a0e */
if(!s->budget--) { s->failed_pc=0x0c072a0eu; return 0; }
write(ram,r[15],r[3],4);
goto P_0c072a10;
P_0c072a10: /* original d103, guest PC 0x0c072a10 */
if(!s->budget--) { s->failed_pc=0x0c072a10u; return 0; }
r[1]=read(ram,0x0c072a20u,4);
goto P_0c072a12;
P_0c072a12: /* original 412b, guest PC 0x0c072a12 */
if(!s->budget--) { s->failed_pc=0x0c072a12u; return 0; }
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
P_0c072a14: /* original 0009, guest PC 0x0c072a14 */
if(!s->budget--) { s->failed_pc=0x0c072a14u; return 0; }
goto P_0c072a16;
P_0c072a16: /* original 64d3, guest PC 0x0c072a16 */
if(!s->budget--) { s->failed_pc=0x0c072a16u; return 0; }
r[4]=r[13];
goto P_0c072a18;
P_0c072a18: /* original 6593, guest PC 0x0c072a18 */
if(!s->budget--) { s->failed_pc=0x0c072a18u; return 0; }
r[5]=r[9];
goto P_0c072a1a;
P_0c072a1a: /* original 66e3, guest PC 0x0c072a1a */
if(!s->budget--) { s->failed_pc=0x0c072a1au; return 0; }
r[6]=r[14];
goto P_0c072a1c;
P_0c072a1c: /* original a002, guest PC 0x0c072a1c */
if(!s->budget--) { s->failed_pc=0x0c072a1cu; return 0; }
goto P_0c072a24;
P_0c072a1e: /* original 0009, guest PC 0x0c072a1e */
if(!s->budget--) { s->failed_pc=0x0c072a1eu; return 0; }
return vf3_matrix_family(0x0c072a20u,s,ram);
P_0c072a24: /* original f059, guest PC 0x0c072a24 */
if(!s->budget--) { s->failed_pc=0x0c072a24u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c072a26;
P_0c072a26: /* original f369, guest PC 0x0c072a26 */
if(!s->budget--) { s->failed_pc=0x0c072a26u; return 0; }
vf3_matrix_load(s,ram,3,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c072a28;
P_0c072a28: /* original f159, guest PC 0x0c072a28 */
if(!s->budget--) { s->failed_pc=0x0c072a28u; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c072a2a;
P_0c072a2a: /* original f469, guest PC 0x0c072a2a */
if(!s->budget--) { s->failed_pc=0x0c072a2au; return 0; }
vf3_matrix_load(s,ram,4,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c072a2c;
P_0c072a2c: /* original f031, guest PC 0x0c072a2c */
if(!s->budget--) { s->failed_pc=0x0c072a2cu; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'-');
goto P_0c072a2e;
P_0c072a2e: /* original f258, guest PC 0x0c072a2e */
if(!s->budget--) { s->failed_pc=0x0c072a2eu; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
goto P_0c072a30;
P_0c072a30: /* original f568, guest PC 0x0c072a30 */
if(!s->budget--) { s->failed_pc=0x0c072a30u; return 0; }
vf3_matrix_load(s,ram,5,r[6]);
goto P_0c072a32;
P_0c072a32: /* original f141, guest PC 0x0c072a32 */
if(!s->budget--) { s->failed_pc=0x0c072a32u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'-');
goto P_0c072a34;
P_0c072a34: /* original f251, guest PC 0x0c072a34 */
if(!s->budget--) { s->failed_pc=0x0c072a34u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'-');
goto P_0c072a36;
P_0c072a36: /* original 7408, guest PC 0x0c072a36 */
if(!s->budget--) { s->failed_pc=0x0c072a36u; return 0; }
r[4]+=0x00000008u;
goto P_0c072a38;
P_0c072a38: /* original f42a, guest PC 0x0c072a38 */
if(!s->budget--) { s->failed_pc=0x0c072a38u; return 0; }
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c072a3a;
P_0c072a3a: /* original f41b, guest PC 0x0c072a3a */
if(!s->budget--) { s->failed_pc=0x0c072a3au; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c072a3c;
P_0c072a3c: /* original f40b, guest PC 0x0c072a3c */
if(!s->budget--) { s->failed_pc=0x0c072a3cu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c072a3e;
P_0c072a3e: /* original 0009, guest PC 0x0c072a3e */
if(!s->budget--) { s->failed_pc=0x0c072a3eu; return 0; }
goto P_0c072a40;
P_0c072a40: /* original 64a3, guest PC 0x0c072a40 */
if(!s->budget--) { s->failed_pc=0x0c072a40u; return 0; }
r[4]=r[10];
goto P_0c072a42;
P_0c072a42: /* original 6583, guest PC 0x0c072a42 */
if(!s->budget--) { s->failed_pc=0x0c072a42u; return 0; }
r[5]=r[8];
goto P_0c072a44;
P_0c072a44: /* original 66e3, guest PC 0x0c072a44 */
if(!s->budget--) { s->failed_pc=0x0c072a44u; return 0; }
r[6]=r[14];
goto P_0c072a46;
P_0c072a46: /* original f059, guest PC 0x0c072a46 */
if(!s->budget--) { s->failed_pc=0x0c072a46u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c072a48;
P_0c072a48: /* original f369, guest PC 0x0c072a48 */
if(!s->budget--) { s->failed_pc=0x0c072a48u; return 0; }
vf3_matrix_load(s,ram,3,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c072a4a;
P_0c072a4a: /* original f159, guest PC 0x0c072a4a */
if(!s->budget--) { s->failed_pc=0x0c072a4au; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c072a4c;
P_0c072a4c: /* original f469, guest PC 0x0c072a4c */
if(!s->budget--) { s->failed_pc=0x0c072a4cu; return 0; }
vf3_matrix_load(s,ram,4,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c072a4e;
P_0c072a4e: /* original f031, guest PC 0x0c072a4e */
if(!s->budget--) { s->failed_pc=0x0c072a4eu; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'-');
goto P_0c072a50;
P_0c072a50: /* original f258, guest PC 0x0c072a50 */
if(!s->budget--) { s->failed_pc=0x0c072a50u; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
goto P_0c072a52;
P_0c072a52: /* original f568, guest PC 0x0c072a52 */
if(!s->budget--) { s->failed_pc=0x0c072a52u; return 0; }
vf3_matrix_load(s,ram,5,r[6]);
goto P_0c072a54;
P_0c072a54: /* original f141, guest PC 0x0c072a54 */
if(!s->budget--) { s->failed_pc=0x0c072a54u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'-');
goto P_0c072a56;
P_0c072a56: /* original f251, guest PC 0x0c072a56 */
if(!s->budget--) { s->failed_pc=0x0c072a56u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'-');
goto P_0c072a58;
P_0c072a58: /* original 7408, guest PC 0x0c072a58 */
if(!s->budget--) { s->failed_pc=0x0c072a58u; return 0; }
r[4]+=0x00000008u;
goto P_0c072a5a;
P_0c072a5a: /* original f42a, guest PC 0x0c072a5a */
if(!s->budget--) { s->failed_pc=0x0c072a5au; return 0; }
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c072a5c;
P_0c072a5c: /* original f41b, guest PC 0x0c072a5c */
if(!s->budget--) { s->failed_pc=0x0c072a5cu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c072a5e;
P_0c072a5e: /* original f40b, guest PC 0x0c072a5e */
if(!s->budget--) { s->failed_pc=0x0c072a5eu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c072a60;
P_0c072a60: /* original 66e3, guest PC 0x0c072a60 */
if(!s->budget--) { s->failed_pc=0x0c072a60u; return 0; }
r[6]=r[14];
goto P_0c072a62;
P_0c072a62: /* original 64d3, guest PC 0x0c072a62 */
if(!s->budget--) { s->failed_pc=0x0c072a62u; return 0; }
r[4]=r[13];
goto P_0c072a64;
P_0c072a64: /* original 65a3, guest PC 0x0c072a64 */
if(!s->budget--) { s->failed_pc=0x0c072a64u; return 0; }
r[5]=r[10];
goto P_0c072a66;
P_0c072a66: /* original 760c, guest PC 0x0c072a66 */
if(!s->budget--) { s->failed_pc=0x0c072a66u; return 0; }
r[6]+=0x0000000cu;
goto P_0c072a68;
P_0c072a68: /* original f049, guest PC 0x0c072a68 */
if(!s->budget--) { s->failed_pc=0x0c072a68u; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c072a6a;
P_0c072a6a: /* original f549, guest PC 0x0c072a6a */
if(!s->budget--) { s->failed_pc=0x0c072a6au; return 0; }
vf3_matrix_load(s,ram,5,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c072a6c;
P_0c072a6c: /* original f648, guest PC 0x0c072a6c */
if(!s->budget--) { s->failed_pc=0x0c072a6cu; return 0; }
vf3_matrix_load(s,ram,6,r[4]);
goto P_0c072a6e;
P_0c072a6e: /* original f859, guest PC 0x0c072a6e */
if(!s->budget--) { s->failed_pc=0x0c072a6eu; return 0; }
vf3_matrix_load(s,ram,8,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c072a70;
P_0c072a70: /* original f959, guest PC 0x0c072a70 */
if(!s->budget--) { s->failed_pc=0x0c072a70u; return 0; }
vf3_matrix_load(s,ram,9,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c072a72;
P_0c072a72: /* original fa58, guest PC 0x0c072a72 */
if(!s->budget--) { s->failed_pc=0x0c072a72u; return 0; }
vf3_matrix_load(s,ram,10,r[5]);
goto P_0c072a74;
P_0c072a74: /* original 760c, guest PC 0x0c072a74 */
if(!s->budget--) { s->failed_pc=0x0c072a74u; return 0; }
r[6]+=0x0000000cu;
goto P_0c072a76;
P_0c072a76: /* original f35c, guest PC 0x0c072a76 */
if(!s->budget--) { s->failed_pc=0x0c072a76u; return 0; }
vf3_matrix_move(s,3,5);
goto P_0c072a78;
P_0c072a78: /* original f382, guest PC 0x0c072a78 */
if(!s->budget--) { s->failed_pc=0x0c072a78u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[8],r[18],'*');
goto P_0c072a7a;
P_0c072a7a: /* original f20c, guest PC 0x0c072a7a */
if(!s->budget--) { s->failed_pc=0x0c072a7au; return 0; }
vf3_matrix_move(s,2,0);
goto P_0c072a7c;
P_0c072a7c: /* original f2a2, guest PC 0x0c072a7c */
if(!s->budget--) { s->failed_pc=0x0c072a7cu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[10],r[18],'*');
goto P_0c072a7e;
P_0c072a7e: /* original f16c, guest PC 0x0c072a7e */
if(!s->budget--) { s->failed_pc=0x0c072a7eu; return 0; }
vf3_matrix_move(s,1,6);
goto P_0c072a80;
P_0c072a80: /* original f192, guest PC 0x0c072a80 */
if(!s->budget--) { s->failed_pc=0x0c072a80u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[9],r[18],'*');
goto P_0c072a82;
P_0c072a82: /* original f34d, guest PC 0x0c072a82 */
if(!s->budget--) { s->failed_pc=0x0c072a82u; return 0; }
fr[3]^=0x80000000u;
goto P_0c072a84;
P_0c072a84: /* original f39e, guest PC 0x0c072a84 */
if(!s->budget--) { s->failed_pc=0x0c072a84u; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[9],fr[3],r[18]);
goto P_0c072a86;
P_0c072a86: /* original f24d, guest PC 0x0c072a86 */
if(!s->budget--) { s->failed_pc=0x0c072a86u; return 0; }
fr[2]^=0x80000000u;
goto P_0c072a88;
P_0c072a88: /* original f06c, guest PC 0x0c072a88 */
if(!s->budget--) { s->failed_pc=0x0c072a88u; return 0; }
vf3_matrix_move(s,0,6);
goto P_0c072a8a;
P_0c072a8a: /* original f28e, guest PC 0x0c072a8a */
if(!s->budget--) { s->failed_pc=0x0c072a8au; return 0; }
fr[2]=vf3_fpu_mac(fr[0],fr[8],fr[2],r[18]);
goto P_0c072a8c;
P_0c072a8c: /* original f14d, guest PC 0x0c072a8c */
if(!s->budget--) { s->failed_pc=0x0c072a8cu; return 0; }
fr[1]^=0x80000000u;
goto P_0c072a8e;
P_0c072a8e: /* original f63b, guest PC 0x0c072a8e */
if(!s->budget--) { s->failed_pc=0x0c072a8eu; return 0; }
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,3,r[6]);
goto P_0c072a90;
P_0c072a90: /* original f05c, guest PC 0x0c072a90 */
if(!s->budget--) { s->failed_pc=0x0c072a90u; return 0; }
vf3_matrix_move(s,0,5);
goto P_0c072a92;
P_0c072a92: /* original f1ae, guest PC 0x0c072a92 */
if(!s->budget--) { s->failed_pc=0x0c072a92u; return 0; }
fr[1]=vf3_fpu_mac(fr[0],fr[10],fr[1],r[18]);
goto P_0c072a94;
P_0c072a94: /* original f62b, guest PC 0x0c072a94 */
if(!s->budget--) { s->failed_pc=0x0c072a94u; return 0; }
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[6]);
goto P_0c072a96;
P_0c072a96: /* original f61b, guest PC 0x0c072a96 */
if(!s->budget--) { s->failed_pc=0x0c072a96u; return 0; }
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[6]);
goto P_0c072a98;
P_0c072a98: /* original 64e3, guest PC 0x0c072a98 */
if(!s->budget--) { s->failed_pc=0x0c072a98u; return 0; }
r[4]=r[14];
goto P_0c072a9a;
P_0c072a9a: /* original 65e3, guest PC 0x0c072a9a */
if(!s->budget--) { s->failed_pc=0x0c072a9au; return 0; }
r[5]=r[14];
goto P_0c072a9c;
P_0c072a9c: /* original 740c, guest PC 0x0c072a9c */
if(!s->budget--) { s->failed_pc=0x0c072a9cu; return 0; }
r[4]+=0x0000000cu;
goto P_0c072a9e;
P_0c072a9e: /* original f4fc, guest PC 0x0c072a9e */
if(!s->budget--) { s->failed_pc=0x0c072a9eu; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c072aa0;
P_0c072aa0: /* original 750c, guest PC 0x0c072aa0 */
if(!s->budget--) { s->failed_pc=0x0c072aa0u; return 0; }
r[5]+=0x0000000cu;
goto P_0c072aa2;
P_0c072aa2: /* original f059, guest PC 0x0c072aa2 */
if(!s->budget--) { s->failed_pc=0x0c072aa2u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c072aa4;
P_0c072aa4: /* original f159, guest PC 0x0c072aa4 */
if(!s->budget--) { s->failed_pc=0x0c072aa4u; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c072aa6;
P_0c072aa6: /* original f259, guest PC 0x0c072aa6 */
if(!s->budget--) { s->failed_pc=0x0c072aa6u; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c072aa8;
P_0c072aa8: /* original f38d, guest PC 0x0c072aa8 */
if(!s->budget--) { s->failed_pc=0x0c072aa8u; return 0; }
fr[3]=0;
goto P_0c072aaa;
P_0c072aaa: /* original f0ed, guest PC 0x0c072aaa */
if(!s->budget--) { s->failed_pc=0x0c072aaau; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+0,r[18],fr+3)) goto unsupported;
goto P_0c072aac;
P_0c072aac: /* original f37d, guest PC 0x0c072aac */
if(!s->budget--) { s->failed_pc=0x0c072aacu; return 0; }
if(!vf3_fpu_fsrra(fr[3],r[18],&fr[3])) goto unsupported;
goto P_0c072aae;
P_0c072aae: /* original f342, guest PC 0x0c072aae */
if(!s->budget--) { s->failed_pc=0x0c072aaeu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'*');
goto P_0c072ab0;
P_0c072ab0: /* original 740c, guest PC 0x0c072ab0 */
if(!s->budget--) { s->failed_pc=0x0c072ab0u; return 0; }
r[4]+=0x0000000cu;
goto P_0c072ab2;
P_0c072ab2: /* original f232, guest PC 0x0c072ab2 */
if(!s->budget--) { s->failed_pc=0x0c072ab2u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c072ab4;
P_0c072ab4: /* original f132, guest PC 0x0c072ab4 */
if(!s->budget--) { s->failed_pc=0x0c072ab4u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[3],r[18],'*');
goto P_0c072ab6;
P_0c072ab6: /* original f032, guest PC 0x0c072ab6 */
if(!s->budget--) { s->failed_pc=0x0c072ab6u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'*');
goto P_0c072ab8;
P_0c072ab8: /* original f42b, guest PC 0x0c072ab8 */
if(!s->budget--) { s->failed_pc=0x0c072ab8u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c072aba;
P_0c072aba: /* original f41b, guest PC 0x0c072aba */
if(!s->budget--) { s->failed_pc=0x0c072abau; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c072abc;
P_0c072abc: /* original f40b, guest PC 0x0c072abc */
if(!s->budget--) { s->failed_pc=0x0c072abcu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c072abe;
P_0c072abe: /* original 0009, guest PC 0x0c072abe */
if(!s->budget--) { s->failed_pc=0x0c072abeu; return 0; }
goto P_0c072ac0;
P_0c072ac0: /* original 54f3, guest PC 0x0c072ac0 */
if(!s->budget--) { s->failed_pc=0x0c072ac0u; return 0; }
r[4]=read(ram,r[15]+12,4);
goto P_0c072ac2;
P_0c072ac2: /* original 7e18, guest PC 0x0c072ac2 */
if(!s->budget--) { s->failed_pc=0x0c072ac2u; return 0; }
r[14]+=0x00000018u;
goto P_0c072ac4;
P_0c072ac4: /* original 5441, guest PC 0x0c072ac4 */
if(!s->budget--) { s->failed_pc=0x0c072ac4u; return 0; }
r[4]=read(ram,r[4]+4,4);
goto P_0c072ac6;
P_0c072ac6: /* original 7418, guest PC 0x0c072ac6 */
if(!s->budget--) { s->failed_pc=0x0c072ac6u; return 0; }
r[4]+=0x00000018u;
goto P_0c072ac8;
P_0c072ac8: /* original a00f, guest PC 0x0c072ac8 */
if(!s->budget--) { s->failed_pc=0x0c072ac8u; return 0; }
r[5]=0x0000001eu;
goto P_0c072aea;
P_0c072aca: /* original e51e, guest PC 0x0c072aca */
if(!s->budget--) { s->failed_pc=0x0c072acau; return 0; }
r[5]=0x0000001eu;
goto P_0c072acc;
P_0c072acc: /* original e00c, guest PC 0x0c072acc */
if(!s->budget--) { s->failed_pc=0x0c072accu; return 0; }
r[0]=0x0000000cu;
goto P_0c072ace;
P_0c072ace: /* original f346, guest PC 0x0c072ace */
if(!s->budget--) { s->failed_pc=0x0c072aceu; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c072ad0;
P_0c072ad0: /* original 75ff, guest PC 0x0c072ad0 */
if(!s->budget--) { s->failed_pc=0x0c072ad0u; return 0; }
r[5]+=0xffffffffu;
goto P_0c072ad2;
P_0c072ad2: /* original f34d, guest PC 0x0c072ad2 */
if(!s->budget--) { s->failed_pc=0x0c072ad2u; return 0; }
fr[3]^=0x80000000u;
goto P_0c072ad4;
P_0c072ad4: /* original fe37, guest PC 0x0c072ad4 */
if(!s->budget--) { s->failed_pc=0x0c072ad4u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c072ad6;
P_0c072ad6: /* original e010, guest PC 0x0c072ad6 */
if(!s->budget--) { s->failed_pc=0x0c072ad6u; return 0; }
r[0]=0x00000010u;
goto P_0c072ad8;
P_0c072ad8: /* original f346, guest PC 0x0c072ad8 */
if(!s->budget--) { s->failed_pc=0x0c072ad8u; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c072ada;
P_0c072ada: /* original f34d, guest PC 0x0c072ada */
if(!s->budget--) { s->failed_pc=0x0c072adau; return 0; }
fr[3]^=0x80000000u;
goto P_0c072adc;
P_0c072adc: /* original fe37, guest PC 0x0c072adc */
if(!s->budget--) { s->failed_pc=0x0c072adcu; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c072ade;
P_0c072ade: /* original e014, guest PC 0x0c072ade */
if(!s->budget--) { s->failed_pc=0x0c072adeu; return 0; }
r[0]=0x00000014u;
goto P_0c072ae0;
P_0c072ae0: /* original f346, guest PC 0x0c072ae0 */
if(!s->budget--) { s->failed_pc=0x0c072ae0u; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c072ae2;
P_0c072ae2: /* original 7418, guest PC 0x0c072ae2 */
if(!s->budget--) { s->failed_pc=0x0c072ae2u; return 0; }
r[4]+=0x00000018u;
goto P_0c072ae4;
P_0c072ae4: /* original f34d, guest PC 0x0c072ae4 */
if(!s->budget--) { s->failed_pc=0x0c072ae4u; return 0; }
fr[3]^=0x80000000u;
goto P_0c072ae6;
P_0c072ae6: /* original fe37, guest PC 0x0c072ae6 */
if(!s->budget--) { s->failed_pc=0x0c072ae6u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c072ae8;
P_0c072ae8: /* original 7e18, guest PC 0x0c072ae8 */
if(!s->budget--) { s->failed_pc=0x0c072ae8u; return 0; }
r[14]+=0x00000018u;
goto P_0c072aea;
P_0c072aea: /* original 2558, guest PC 0x0c072aea */
if(!s->budget--) { s->failed_pc=0x0c072aeau; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[5])==0)!=0);
goto P_0c072aec;
P_0c072aec: /* original 8bee, guest PC 0x0c072aec */
if(!s->budget--) { s->failed_pc=0x0c072aecu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c072acc; }
goto P_0c072aee;
P_0c072aee: /* original 7f60, guest PC 0x0c072aee */
if(!s->budget--) { s->failed_pc=0x0c072aeeu; return 0; }
r[15]+=0x00000060u;
goto P_0c072af0;
P_0c072af0: /* original fff9, guest PC 0x0c072af0 */
if(!s->budget--) { s->failed_pc=0x0c072af0u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c072af2;
P_0c072af2: /* original 68f6, guest PC 0x0c072af2 */
if(!s->budget--) { s->failed_pc=0x0c072af2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c072af4;
P_0c072af4: /* original 69f6, guest PC 0x0c072af4 */
if(!s->budget--) { s->failed_pc=0x0c072af4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c072af6;
P_0c072af6: /* original 6af6, guest PC 0x0c072af6 */
if(!s->budget--) { s->failed_pc=0x0c072af6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c072af8;
P_0c072af8: /* original 6bf6, guest PC 0x0c072af8 */
if(!s->budget--) { s->failed_pc=0x0c072af8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c072afa;
P_0c072afa: /* original 6cf6, guest PC 0x0c072afa */
if(!s->budget--) { s->failed_pc=0x0c072afau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c072afc;
P_0c072afc: /* original 6df6, guest PC 0x0c072afc */
if(!s->budget--) { s->failed_pc=0x0c072afcu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c072afe;
P_0c072afe: /* original 000b, guest PC 0x0c072afe */
if(!s->budget--) { s->failed_pc=0x0c072afeu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c072b00: /* original 6ef6, guest PC 0x0c072b00 */
if(!s->budget--) { s->failed_pc=0x0c072b00u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c072b02u,s,ram);
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
P_0c08c83a: /* original 4f22, guest PC 0x0c08c83a */
if(!s->budget--) { s->failed_pc=0x0c08c83au; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c08c83c;
P_0c08c83c: /* original 03ec, guest PC 0x0c08c83c */
if(!s->budget--) { s->failed_pc=0x0c08c83cu; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c08c83e;
P_0c08c83e: /* original d20d, guest PC 0x0c08c83e */
if(!s->budget--) { s->failed_pc=0x0c08c83eu; return 0; }
r[2]=read(ram,0x0c08c874u,4);
goto P_0c08c840;
P_0c08c840: /* original 633c, guest PC 0x0c08c840 */
if(!s->budget--) { s->failed_pc=0x0c08c840u; return 0; }
r[3]=r[3]&255u;
goto P_0c08c842;
P_0c08c842: /* original 7ffc, guest PC 0x0c08c842 */
if(!s->budget--) { s->failed_pc=0x0c08c842u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c08c844;
P_0c08c844: /* original 420b, guest PC 0x0c08c844 */
if(!s->budget--) { s->failed_pc=0x0c08c844u; return 0; }
target=r[2];
r[16]=0x0c08c848u;
write(ram,r[15],r[3],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08c848u) { target=s->pc; goto dispatch; }
goto P_0c08c848;
P_0c08c846: /* original 2f32, guest PC 0x0c08c846 */
if(!s->budget--) { s->failed_pc=0x0c08c846u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c08c848;
P_0c08c848: /* original d30b, guest PC 0x0c08c848 */
if(!s->budget--) { s->failed_pc=0x0c08c848u; return 0; }
r[3]=read(ram,0x0c08c878u,4);
goto P_0c08c84a;
P_0c08c84a: /* original 6103, guest PC 0x0c08c84a */
if(!s->budget--) { s->failed_pc=0x0c08c84au; return 0; }
r[1]=r[0];
goto P_0c08c84c;
P_0c08c84c: /* original 430b, guest PC 0x0c08c84c */
if(!s->budget--) { s->failed_pc=0x0c08c84cu; return 0; }
target=r[3];
r[16]=0x0c08c850u;
tmp=read(ram,r[15],4);
r[0]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08c850u) { target=s->pc; goto dispatch; }
goto P_0c08c850;
P_0c08c84e: /* original 60f2, guest PC 0x0c08c84e */
if(!s->budget--) { s->failed_pc=0x0c08c84eu; return 0; }
tmp=read(ram,r[15],4);
r[0]=tmp;
goto P_0c08c850;
P_0c08c850: /* original 6403, guest PC 0x0c08c850 */
if(!s->budget--) { s->failed_pc=0x0c08c850u; return 0; }
r[4]=r[0];
goto P_0c08c852;
P_0c08c852: /* original 2448, guest PC 0x0c08c852 */
if(!s->budget--) { s->failed_pc=0x0c08c852u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c08c854;
P_0c08c854: /* original 8912, guest PC 0x0c08c854 */
if(!s->budget--) { s->failed_pc=0x0c08c854u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c08c87c; }
goto P_0c08c856;
P_0c08c856: /* original e04a, guest PC 0x0c08c856 */
if(!s->budget--) { s->failed_pc=0x0c08c856u; return 0; }
r[0]=0x0000004au;
goto P_0c08c858;
P_0c08c858: /* original 0ded, guest PC 0x0c08c858 */
if(!s->budget--) { s->failed_pc=0x0c08c858u; return 0; }
r[13]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c08c85a;
P_0c08c85a: /* original a031, guest PC 0x0c08c85a */
if(!s->budget--) { s->failed_pc=0x0c08c85au; return 0; }
r[13]=r[13]&65535u;
goto P_0c08c8c0;
P_0c08c85c: /* original 6ddd, guest PC 0x0c08c85c */
if(!s->budget--) { s->failed_pc=0x0c08c85cu; return 0; }
r[13]=r[13]&65535u;
return vf3_matrix_family(0x0c08c85eu,s,ram);
P_0c08c87c: /* original e04c, guest PC 0x0c08c87c */
if(!s->budget--) { s->failed_pc=0x0c08c87cu; return 0; }
r[0]=0x0000004cu;
goto P_0c08c87e;
P_0c08c87e: /* original 957b, guest PC 0x0c08c87e */
if(!s->budget--) { s->failed_pc=0x0c08c87eu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08c978u,2);
goto P_0c08c880;
P_0c08c880: /* original 04ce, guest PC 0x0c08c880 */
if(!s->budget--) { s->failed_pc=0x0c08c880u; return 0; }
r[4]=read(ram,r[12]+r[0],4);
goto P_0c08c882;
P_0c08c882: /* original 907a, guest PC 0x0c08c882 */
if(!s->budget--) { s->failed_pc=0x0c08c882u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08c97au,2);
goto P_0c08c884;
P_0c08c884: /* original 044c, guest PC 0x0c08c884 */
if(!s->budget--) { s->failed_pc=0x0c08c884u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c08c886;
P_0c08c886: /* original 644c, guest PC 0x0c08c886 */
if(!s->budget--) { s->failed_pc=0x0c08c886u; return 0; }
r[4]=r[4]&255u;
goto P_0c08c888;
P_0c08c888: /* original 6043, guest PC 0x0c08c888 */
if(!s->budget--) { s->failed_pc=0x0c08c888u; return 0; }
r[0]=r[4];
goto P_0c08c88a;
P_0c08c88a: /* original 8802, guest PC 0x0c08c88a */
if(!s->budget--) { s->failed_pc=0x0c08c88au; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c08c88c;
P_0c08c88c: /* original 8d18, guest PC 0x0c08c88c */
if(!s->budget--) { s->failed_pc=0x0c08c88cu; return 0; }
cond=r[17]&1u;
r[13]=r[5];
if(cond) { goto P_0c08c8c0; }
goto P_0c08c890;
P_0c08c88e: /* original 6d53, guest PC 0x0c08c88e */
if(!s->budget--) { s->failed_pc=0x0c08c88eu; return 0; }
r[13]=r[5];
goto P_0c08c890;
P_0c08c890: /* original 6043, guest PC 0x0c08c890 */
if(!s->budget--) { s->failed_pc=0x0c08c890u; return 0; }
r[0]=r[4];
goto P_0c08c892;
P_0c08c892: /* original 8806, guest PC 0x0c08c892 */
if(!s->budget--) { s->failed_pc=0x0c08c892u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000006u)!=0);
goto P_0c08c894;
P_0c08c894: /* original 8914, guest PC 0x0c08c894 */
if(!s->budget--) { s->failed_pc=0x0c08c894u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c08c8c0; }
goto P_0c08c896;
P_0c08c896: /* original 6043, guest PC 0x0c08c896 */
if(!s->budget--) { s->failed_pc=0x0c08c896u; return 0; }
r[0]=r[4];
goto P_0c08c898;
P_0c08c898: /* original 8805, guest PC 0x0c08c898 */
if(!s->budget--) { s->failed_pc=0x0c08c898u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000005u)!=0);
goto P_0c08c89a;
P_0c08c89a: /* original 8911, guest PC 0x0c08c89a */
if(!s->budget--) { s->failed_pc=0x0c08c89au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c08c8c0; }
goto P_0c08c89c;
P_0c08c89c: /* original 2448, guest PC 0x0c08c89c */
if(!s->budget--) { s->failed_pc=0x0c08c89cu; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c08c89e;
P_0c08c89e: /* original 8b0e, guest PC 0x0c08c89e */
if(!s->budget--) { s->failed_pc=0x0c08c89eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c08c8be; }
goto P_0c08c8a0;
P_0c08c8a0: /* original e04a, guest PC 0x0c08c8a0 */
if(!s->budget--) { s->failed_pc=0x0c08c8a0u; return 0; }
r[0]=0x0000004au;
goto P_0c08c8a2;
P_0c08c8a2: /* original 04ed, guest PC 0x0c08c8a2 */
if(!s->budget--) { s->failed_pc=0x0c08c8a2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c08c8a4;
P_0c08c8a4: /* original 644d, guest PC 0x0c08c8a4 */
if(!s->budget--) { s->failed_pc=0x0c08c8a4u; return 0; }
r[4]=r[4]&65535u;
goto P_0c08c8a6;
P_0c08c8a6: /* original 3450, guest PC 0x0c08c8a6 */
if(!s->budget--) { s->failed_pc=0x0c08c8a6u; return 0; }
r[17]=(r[17]&~1u)|((r[4]==r[5])!=0);
goto P_0c08c8a8;
P_0c08c8a8: /* original 890a, guest PC 0x0c08c8a8 */
if(!s->budget--) { s->failed_pc=0x0c08c8a8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c08c8c0; }
goto P_0c08c8aa;
P_0c08c8aa: /* original d335, guest PC 0x0c08c8aa */
if(!s->budget--) { s->failed_pc=0x0c08c8aau; return 0; }
r[3]=read(ram,0x0c08c980u,4);
goto P_0c08c8ac;
P_0c08c8ac: /* original 430b, guest PC 0x0c08c8ac */
if(!s->budget--) { s->failed_pc=0x0c08c8acu; return 0; }
target=r[3];
r[16]=0x0c08c8b0u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08c8b0u) { target=s->pc; goto dispatch; }
goto P_0c08c8b0;
P_0c08c8ae: /* original 0009, guest PC 0x0c08c8ae */
if(!s->budget--) { s->failed_pc=0x0c08c8aeu; return 0; }
goto P_0c08c8b0;
P_0c08c8b0: /* original d234, guest PC 0x0c08c8b0 */
if(!s->budget--) { s->failed_pc=0x0c08c8b0u; return 0; }
r[2]=read(ram,0x0c08c984u,4);
goto P_0c08c8b2;
P_0c08c8b2: /* original 6103, guest PC 0x0c08c8b2 */
if(!s->budget--) { s->failed_pc=0x0c08c8b2u; return 0; }
r[1]=r[0];
goto P_0c08c8b4;
P_0c08c8b4: /* original 420b, guest PC 0x0c08c8b4 */
if(!s->budget--) { s->failed_pc=0x0c08c8b4u; return 0; }
target=r[2];
r[16]=0x0c08c8b8u;
r[0]=0x00000003u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08c8b8u) { target=s->pc; goto dispatch; }
goto P_0c08c8b8;
P_0c08c8b6: /* original e003, guest PC 0x0c08c8b6 */
if(!s->budget--) { s->failed_pc=0x0c08c8b6u; return 0; }
r[0]=0x00000003u;
goto P_0c08c8b8;
P_0c08c8b8: /* original 6403, guest PC 0x0c08c8b8 */
if(!s->budget--) { s->failed_pc=0x0c08c8b8u; return 0; }
r[4]=r[0];
goto P_0c08c8ba;
P_0c08c8ba: /* original 2448, guest PC 0x0c08c8ba */
if(!s->budget--) { s->failed_pc=0x0c08c8bau; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c08c8bc;
P_0c08c8bc: /* original 8900, guest PC 0x0c08c8bc */
if(!s->budget--) { s->failed_pc=0x0c08c8bcu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c08c8c0; }
goto P_0c08c8be;
P_0c08c8be: /* original 9d5d, guest PC 0x0c08c8be */
if(!s->budget--) { s->failed_pc=0x0c08c8beu; return 0; }
r[13]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08c97cu,2);
goto P_0c08c8c0;
P_0c08c8c0: /* original e04a, guest PC 0x0c08c8c0 */
if(!s->budget--) { s->failed_pc=0x0c08c8c0u; return 0; }
r[0]=0x0000004au;
goto P_0c08c8c2;
P_0c08c8c2: /* original 0ed5, guest PC 0x0c08c8c2 */
if(!s->budget--) { s->failed_pc=0x0c08c8c2u; return 0; }
write(ram,r[14]+r[0],r[13],2);
goto P_0c08c8c4;
P_0c08c8c4: /* original e028, guest PC 0x0c08c8c4 */
if(!s->budget--) { s->failed_pc=0x0c08c8c4u; return 0; }
r[0]=0x00000028u;
goto P_0c08c8c6;
P_0c08c8c6: /* original 0ed5, guest PC 0x0c08c8c6 */
if(!s->budget--) { s->failed_pc=0x0c08c8c6u; return 0; }
write(ram,r[14]+r[0],r[13],2);
goto P_0c08c8c8;
P_0c08c8c8: /* original e040, guest PC 0x0c08c8c8 */
if(!s->budget--) { s->failed_pc=0x0c08c8c8u; return 0; }
r[0]=0x00000040u;
goto P_0c08c8ca;
P_0c08c8ca: /* original e400, guest PC 0x0c08c8ca */
if(!s->budget--) { s->failed_pc=0x0c08c8cau; return 0; }
r[4]=0x00000000u;
goto P_0c08c8cc;
P_0c08c8cc: /* original 1cdd, guest PC 0x0c08c8cc */
if(!s->budget--) { s->failed_pc=0x0c08c8ccu; return 0; }
write(ram,r[12]+52,r[13],4);
goto P_0c08c8ce;
P_0c08c8ce: /* original 0c46, guest PC 0x0c08c8ce */
if(!s->budget--) { s->failed_pc=0x0c08c8ceu; return 0; }
write(ram,r[12]+r[0],r[4],4);
goto P_0c08c8d0;
P_0c08c8d0: /* original b442, guest PC 0x0c08c8d0 */
if(!s->budget--) { s->failed_pc=0x0c08c8d0u; return 0; }
target=0x0c08d158u; r[16]=0x0c08c8d4u;
r[4]=r[12];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08c8d4u) { target=s->pc; goto dispatch; }
goto P_0c08c8d4;
P_0c08c8d2: /* original 64c3, guest PC 0x0c08c8d2 */
if(!s->budget--) { s->failed_pc=0x0c08c8d2u; return 0; }
r[4]=r[12];
goto P_0c08c8d4;
P_0c08c8d4: /* original e200, guest PC 0x0c08c8d4 */
if(!s->budget--) { s->failed_pc=0x0c08c8d4u; return 0; }
r[2]=0x00000000u;
goto P_0c08c8d6;
P_0c08c8d6: /* original 55ce, guest PC 0x0c08c8d6 */
if(!s->budget--) { s->failed_pc=0x0c08c8d6u; return 0; }
r[5]=read(ram,r[12]+56,4);
goto P_0c08c8d8;
P_0c08c8d8: /* original e02c, guest PC 0x0c08c8d8 */
if(!s->budget--) { s->failed_pc=0x0c08c8d8u; return 0; }
r[0]=0x0000002cu;
goto P_0c08c8da;
P_0c08c8da: /* original 54cf, guest PC 0x0c08c8da */
if(!s->budget--) { s->failed_pc=0x0c08c8dau; return 0; }
r[4]=read(ram,r[12]+60,4);
goto P_0c08c8dc;
P_0c08c8dc: /* original 0e24, guest PC 0x0c08c8dc */
if(!s->budget--) { s->failed_pc=0x0c08c8dcu; return 0; }
write(ram,r[14]+r[0],r[2],1);
goto P_0c08c8de;
P_0c08c8de: /* original e02d, guest PC 0x0c08c8de */
if(!s->budget--) { s->failed_pc=0x0c08c8deu; return 0; }
r[0]=0x0000002du;
goto P_0c08c8e0;
P_0c08c8e0: /* original 0e54, guest PC 0x0c08c8e0 */
if(!s->budget--) { s->failed_pc=0x0c08c8e0u; return 0; }
write(ram,r[14]+r[0],r[5],1);
goto P_0c08c8e2;
P_0c08c8e2: /* original e048, guest PC 0x0c08c8e2 */
if(!s->budget--) { s->failed_pc=0x0c08c8e2u; return 0; }
r[0]=0x00000048u;
goto P_0c08c8e4;
P_0c08c8e4: /* original 00ec, guest PC 0x0c08c8e4 */
if(!s->budget--) { s->failed_pc=0x0c08c8e4u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c08c8e6;
P_0c08c8e6: /* original 8801, guest PC 0x0c08c8e6 */
if(!s->budget--) { s->failed_pc=0x0c08c8e6u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c08c8e8;
P_0c08c8e8: /* original 8905, guest PC 0x0c08c8e8 */
if(!s->budget--) { s->failed_pc=0x0c08c8e8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c08c8f6; }
goto P_0c08c8ea;
P_0c08c8ea: /* original 6043, guest PC 0x0c08c8ea */
if(!s->budget--) { s->failed_pc=0x0c08c8eau; return 0; }
r[0]=r[4];
goto P_0c08c8ec;
P_0c08c8ec: /* original 81ea, guest PC 0x0c08c8ec */
if(!s->budget--) { s->failed_pc=0x0c08c8ecu; return 0; }
write(ram,r[14]+20,r[0],2);
goto P_0c08c8ee;
P_0c08c8ee: /* original e048, guest PC 0x0c08c8ee */
if(!s->budget--) { s->failed_pc=0x0c08c8eeu; return 0; }
r[0]=0x00000048u;
goto P_0c08c8f0;
P_0c08c8f0: /* original 03ec, guest PC 0x0c08c8f0 */
if(!s->budget--) { s->failed_pc=0x0c08c8f0u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c08c8f2;
P_0c08c8f2: /* original 7301, guest PC 0x0c08c8f2 */
if(!s->budget--) { s->failed_pc=0x0c08c8f2u; return 0; }
r[3]+=0x00000001u;
goto P_0c08c8f4;
P_0c08c8f4: /* original 0e34, guest PC 0x0c08c8f4 */
if(!s->budget--) { s->failed_pc=0x0c08c8f4u; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c08c8f6;
P_0c08c8f6: /* original 7f04, guest PC 0x0c08c8f6 */
if(!s->budget--) { s->failed_pc=0x0c08c8f6u; return 0; }
r[15]+=0x00000004u;
goto P_0c08c8f8;
P_0c08c8f8: /* original 4f26, guest PC 0x0c08c8f8 */
if(!s->budget--) { s->failed_pc=0x0c08c8f8u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c08c8fa;
P_0c08c8fa: /* original 6cf6, guest PC 0x0c08c8fa */
if(!s->budget--) { s->failed_pc=0x0c08c8fau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c08c8fc;
P_0c08c8fc: /* original 6df6, guest PC 0x0c08c8fc */
if(!s->budget--) { s->failed_pc=0x0c08c8fcu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c08c8fe;
P_0c08c8fe: /* original 000b, guest PC 0x0c08c8fe */
if(!s->budget--) { s->failed_pc=0x0c08c8feu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c08c900: /* original 6ef6, guest PC 0x0c08c900 */
if(!s->budget--) { s->failed_pc=0x0c08c900u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c08c902u,s,ram);
P_0c08ccfc: /* original 4f22, guest PC 0x0c08ccfc */
if(!s->budget--) { s->failed_pc=0x0c08ccfcu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c08ccfe;
P_0c08ccfe: /* original 8801, guest PC 0x0c08ccfe */
if(!s->budget--) { s->failed_pc=0x0c08ccfeu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c08cd00;
P_0c08cd00: /* original 8d47, guest PC 0x0c08cd00 */
if(!s->budget--) { s->failed_pc=0x0c08cd00u; return 0; }
cond=r[17]&1u;
r[14]=r[5];
if(cond) { goto P_0c08cd92; }
goto P_0c08cd04;
P_0c08cd02: /* original 6e53, guest PC 0x0c08cd02 */
if(!s->budget--) { s->failed_pc=0x0c08cd02u; return 0; }
r[14]=r[5];
goto P_0c08cd04;
P_0c08cd04: /* original 60e2, guest PC 0x0c08cd04 */
if(!s->budget--) { s->failed_pc=0x0c08cd04u; return 0; }
tmp=read(ram,r[14],4);
r[0]=tmp;
goto P_0c08cd06;
P_0c08cd06: /* original cb01, guest PC 0x0c08cd06 */
if(!s->budget--) { s->failed_pc=0x0c08cd06u; return 0; }
r[0]|=1u;
goto P_0c08cd08;
P_0c08cd08: /* original 2e02, guest PC 0x0c08cd08 */
if(!s->budget--) { s->failed_pc=0x0c08cd08u; return 0; }
write(ram,r[14],r[0],4);
goto P_0c08cd0a;
P_0c08cd0a: /* original e04c, guest PC 0x0c08cd0a */
if(!s->budget--) { s->failed_pc=0x0c08cd0au; return 0; }
r[0]=0x0000004cu;
goto P_0c08cd0c;
P_0c08cd0c: /* original 05ee, guest PC 0x0c08cd0c */
if(!s->budget--) { s->failed_pc=0x0c08cd0cu; return 0; }
r[5]=read(ram,r[14]+r[0],4);
goto P_0c08cd0e;
P_0c08cd0e: /* original e066, guest PC 0x0c08cd0e */
if(!s->budget--) { s->failed_pc=0x0c08cd0eu; return 0; }
r[0]=0x00000066u;
goto P_0c08cd10;
P_0c08cd10: /* original 045d, guest PC 0x0c08cd10 */
if(!s->budget--) { s->failed_pc=0x0c08cd10u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[5]+r[0],2);
goto P_0c08cd12;
P_0c08cd12: /* original e064, guest PC 0x0c08cd12 */
if(!s->budget--) { s->failed_pc=0x0c08cd12u; return 0; }
r[0]=0x00000064u;
goto P_0c08cd14;
P_0c08cd14: /* original 055d, guest PC 0x0c08cd14 */
if(!s->budget--) { s->failed_pc=0x0c08cd14u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,r[5]+r[0],2);
goto P_0c08cd16;
P_0c08cd16: /* original 84e8, guest PC 0x0c08cd16 */
if(!s->budget--) { s->failed_pc=0x0c08cd16u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+8,1);
goto P_0c08cd18;
P_0c08cd18: /* original 655d, guest PC 0x0c08cd18 */
if(!s->budget--) { s->failed_pc=0x0c08cd18u; return 0; }
r[5]=r[5]&65535u;
goto P_0c08cd1a;
P_0c08cd1a: /* original 600c, guest PC 0x0c08cd1a */
if(!s->budget--) { s->failed_pc=0x0c08cd1au; return 0; }
r[0]=r[0]&255u;
goto P_0c08cd1c;
P_0c08cd1c: /* original 880c, guest PC 0x0c08cd1c */
if(!s->budget--) { s->failed_pc=0x0c08cd1cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000cu)!=0);
goto P_0c08cd1e;
P_0c08cd1e: /* original 345c, guest PC 0x0c08cd1e */
if(!s->budget--) { s->failed_pc=0x0c08cd1eu; return 0; }
r[4]+=r[5];
goto P_0c08cd20;
P_0c08cd20: /* original 8f01, guest PC 0x0c08cd20 */
if(!s->budget--) { s->failed_pc=0x0c08cd20u; return 0; }
cond=r[17]&1u;
r[5]=0x0000001eu;
if(!cond) { goto P_0c08cd26; }
goto P_0c08cd24;
P_0c08cd22: /* original e51e, guest PC 0x0c08cd22 */
if(!s->budget--) { s->failed_pc=0x0c08cd22u; return 0; }
r[5]=0x0000001eu;
goto P_0c08cd24;
P_0c08cd24: /* original e523, guest PC 0x0c08cd24 */
if(!s->budget--) { s->failed_pc=0x0c08cd24u; return 0; }
r[5]=0x00000023u;
goto P_0c08cd26;
P_0c08cd26: /* original 52e4, guest PC 0x0c08cd26 */
if(!s->budget--) { s->failed_pc=0x0c08cd26u; return 0; }
r[2]=read(ram,r[14]+16,4);
goto P_0c08cd28;
P_0c08cd28: /* original d31c, guest PC 0x0c08cd28 */
if(!s->budget--) { s->failed_pc=0x0c08cd28u; return 0; }
r[3]=read(ram,0x0c08cd9cu,4);
goto P_0c08cd2a;
P_0c08cd2a: /* original 2238, guest PC 0x0c08cd2a */
if(!s->budget--) { s->failed_pc=0x0c08cd2au; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c08cd2c;
P_0c08cd2c: /* original 8d01, guest PC 0x0c08cd2c */
if(!s->budget--) { s->failed_pc=0x0c08cd2cu; return 0; }
cond=r[17]&1u;
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+8,1);
if(cond) { goto P_0c08cd32; }
goto P_0c08cd30;
P_0c08cd2e: /* original 84e8, guest PC 0x0c08cd2e */
if(!s->budget--) { s->failed_pc=0x0c08cd2eu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+8,1);
goto P_0c08cd30;
P_0c08cd30: /* original 75f1, guest PC 0x0c08cd30 */
if(!s->budget--) { s->failed_pc=0x0c08cd30u; return 0; }
r[5]+=0xfffffff1u;
goto P_0c08cd32;
P_0c08cd32: /* original d11b, guest PC 0x0c08cd32 */
if(!s->budget--) { s->failed_pc=0x0c08cd32u; return 0; }
r[1]=read(ram,0x0c08cda0u,4);
goto P_0c08cd34;
P_0c08cd34: /* original 600c, guest PC 0x0c08cd34 */
if(!s->budget--) { s->failed_pc=0x0c08cd34u; return 0; }
r[0]=r[0]&255u;
goto P_0c08cd36;
P_0c08cd36: /* original 3452, guest PC 0x0c08cd36 */
if(!s->budget--) { s->failed_pc=0x0c08cd36u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>=r[5])!=0);
goto P_0c08cd38;
P_0c08cd38: /* original 0c1c, guest PC 0x0c08cd38 */
if(!s->budget--) { s->failed_pc=0x0c08cd38u; return 0; }
r[12]=(uint32_t)(int32_t)(int8_t)read(ram,r[1]+r[0],1);
goto P_0c08cd3a;
P_0c08cd3a: /* original 8f05, guest PC 0x0c08cd3a */
if(!s->budget--) { s->failed_pc=0x0c08cd3au; return 0; }
cond=r[17]&1u;
r[12]=r[12]&255u;
if(!cond) { goto P_0c08cd48; }
goto P_0c08cd3e;
P_0c08cd3c: /* original 6ccc, guest PC 0x0c08cd3c */
if(!s->budget--) { s->failed_pc=0x0c08cd3cu; return 0; }
r[12]=r[12]&255u;
goto P_0c08cd3e;
P_0c08cd3e: /* original 84e8, guest PC 0x0c08cd3e */
if(!s->budget--) { s->failed_pc=0x0c08cd3eu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+8,1);
goto P_0c08cd40;
P_0c08cd40: /* original d218, guest PC 0x0c08cd40 */
if(!s->budget--) { s->failed_pc=0x0c08cd40u; return 0; }
r[2]=read(ram,0x0c08cda4u,4);
goto P_0c08cd42;
P_0c08cd42: /* original 600c, guest PC 0x0c08cd42 */
if(!s->budget--) { s->failed_pc=0x0c08cd42u; return 0; }
r[0]=r[0]&255u;
goto P_0c08cd44;
P_0c08cd44: /* original 0c2c, guest PC 0x0c08cd44 */
if(!s->budget--) { s->failed_pc=0x0c08cd44u; return 0; }
r[12]=(uint32_t)(int32_t)(int8_t)read(ram,r[2]+r[0],1);
goto P_0c08cd46;
P_0c08cd46: /* original 6ccc, guest PC 0x0c08cd46 */
if(!s->budget--) { s->failed_pc=0x0c08cd46u; return 0; }
r[12]=r[12]&255u;
goto P_0c08cd48;
P_0c08cd48: /* original d317, guest PC 0x0c08cd48 */
if(!s->budget--) { s->failed_pc=0x0c08cd48u; return 0; }
r[3]=read(ram,0x0c08cda8u,4);
goto P_0c08cd4a;
P_0c08cd4a: /* original 430b, guest PC 0x0c08cd4a */
if(!s->budget--) { s->failed_pc=0x0c08cd4au; return 0; }
target=r[3];
r[16]=0x0c08cd4eu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08cd4eu) { target=s->pc; goto dispatch; }
goto P_0c08cd4e;
P_0c08cd4c: /* original 0009, guest PC 0x0c08cd4c */
if(!s->budget--) { s->failed_pc=0x0c08cd4cu; return 0; }
goto P_0c08cd4e;
P_0c08cd4e: /* original d217, guest PC 0x0c08cd4e */
if(!s->budget--) { s->failed_pc=0x0c08cd4eu; return 0; }
r[2]=read(ram,0x0c08cdacu,4);
goto P_0c08cd50;
P_0c08cd50: /* original 6103, guest PC 0x0c08cd50 */
if(!s->budget--) { s->failed_pc=0x0c08cd50u; return 0; }
r[1]=r[0];
goto P_0c08cd52;
P_0c08cd52: /* original 420b, guest PC 0x0c08cd52 */
if(!s->budget--) { s->failed_pc=0x0c08cd52u; return 0; }
target=r[2];
r[16]=0x0c08cd56u;
r[0]=r[12];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08cd56u) { target=s->pc; goto dispatch; }
goto P_0c08cd56;
P_0c08cd54: /* original 60c3, guest PC 0x0c08cd54 */
if(!s->budget--) { s->failed_pc=0x0c08cd54u; return 0; }
r[0]=r[12];
goto P_0c08cd56;
P_0c08cd56: /* original 6403, guest PC 0x0c08cd56 */
if(!s->budget--) { s->failed_pc=0x0c08cd56u; return 0; }
r[4]=r[0];
goto P_0c08cd58;
P_0c08cd58: /* original 84e8, guest PC 0x0c08cd58 */
if(!s->budget--) { s->failed_pc=0x0c08cd58u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+8,1);
goto P_0c08cd5a;
P_0c08cd5a: /* original d115, guest PC 0x0c08cd5a */
if(!s->budget--) { s->failed_pc=0x0c08cd5au; return 0; }
r[1]=read(ram,0x0c08cdb0u,4);
goto P_0c08cd5c;
P_0c08cd5c: /* original 4400, guest PC 0x0c08cd5c */
if(!s->budget--) { s->failed_pc=0x0c08cd5cu; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c08cd5e;
P_0c08cd5e: /* original 600c, guest PC 0x0c08cd5e */
if(!s->budget--) { s->failed_pc=0x0c08cd5eu; return 0; }
r[0]=r[0]&255u;
goto P_0c08cd60;
P_0c08cd60: /* original 4008, guest PC 0x0c08cd60 */
if(!s->budget--) { s->failed_pc=0x0c08cd60u; return 0; }
r[0]<<=2;
goto P_0c08cd62;
P_0c08cd62: /* original 001e, guest PC 0x0c08cd62 */
if(!s->budget--) { s->failed_pc=0x0c08cd62u; return 0; }
r[0]=read(ram,r[1]+r[0],4);
goto P_0c08cd64;
P_0c08cd64: /* original e500, guest PC 0x0c08cd64 */
if(!s->budget--) { s->failed_pc=0x0c08cd64u; return 0; }
r[5]=0x00000000u;
goto P_0c08cd66;
P_0c08cd66: /* original 044d, guest PC 0x0c08cd66 */
if(!s->budget--) { s->failed_pc=0x0c08cd66u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c08cd68;
P_0c08cd68: /* original e028, guest PC 0x0c08cd68 */
if(!s->budget--) { s->failed_pc=0x0c08cd68u; return 0; }
r[0]=0x00000028u;
goto P_0c08cd6a;
P_0c08cd6a: /* original 644d, guest PC 0x0c08cd6a */
if(!s->budget--) { s->failed_pc=0x0c08cd6au; return 0; }
r[4]=r[4]&65535u;
goto P_0c08cd6c;
P_0c08cd6c: /* original 0d45, guest PC 0x0c08cd6c */
if(!s->budget--) { s->failed_pc=0x0c08cd6cu; return 0; }
write(ram,r[13]+r[0],r[4],2);
goto P_0c08cd6e;
P_0c08cd6e: /* original e040, guest PC 0x0c08cd6e */
if(!s->budget--) { s->failed_pc=0x0c08cd6eu; return 0; }
r[0]=0x00000040u;
goto P_0c08cd70;
P_0c08cd70: /* original 1e4d, guest PC 0x0c08cd70 */
if(!s->budget--) { s->failed_pc=0x0c08cd70u; return 0; }
write(ram,r[14]+52,r[4],4);
goto P_0c08cd72;
P_0c08cd72: /* original 0e56, guest PC 0x0c08cd72 */
if(!s->budget--) { s->failed_pc=0x0c08cd72u; return 0; }
write(ram,r[14]+r[0],r[5],4);
goto P_0c08cd74;
P_0c08cd74: /* original b1f0, guest PC 0x0c08cd74 */
if(!s->budget--) { s->failed_pc=0x0c08cd74u; return 0; }
target=0x0c08d158u; r[16]=0x0c08cd78u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08cd78u) { target=s->pc; goto dispatch; }
goto P_0c08cd78;
P_0c08cd76: /* original 64e3, guest PC 0x0c08cd76 */
if(!s->budget--) { s->failed_pc=0x0c08cd76u; return 0; }
r[4]=r[14];
goto P_0c08cd78;
P_0c08cd78: /* original e200, guest PC 0x0c08cd78 */
if(!s->budget--) { s->failed_pc=0x0c08cd78u; return 0; }
r[2]=0x00000000u;
goto P_0c08cd7a;
P_0c08cd7a: /* original 55ee, guest PC 0x0c08cd7a */
if(!s->budget--) { s->failed_pc=0x0c08cd7au; return 0; }
r[5]=read(ram,r[14]+56,4);
goto P_0c08cd7c;
P_0c08cd7c: /* original e02c, guest PC 0x0c08cd7c */
if(!s->budget--) { s->failed_pc=0x0c08cd7cu; return 0; }
r[0]=0x0000002cu;
goto P_0c08cd7e;
P_0c08cd7e: /* original 54ef, guest PC 0x0c08cd7e */
if(!s->budget--) { s->failed_pc=0x0c08cd7eu; return 0; }
r[4]=read(ram,r[14]+60,4);
goto P_0c08cd80;
P_0c08cd80: /* original 0d24, guest PC 0x0c08cd80 */
if(!s->budget--) { s->failed_pc=0x0c08cd80u; return 0; }
write(ram,r[13]+r[0],r[2],1);
goto P_0c08cd82;
P_0c08cd82: /* original e02d, guest PC 0x0c08cd82 */
if(!s->budget--) { s->failed_pc=0x0c08cd82u; return 0; }
r[0]=0x0000002du;
goto P_0c08cd84;
P_0c08cd84: /* original 0d54, guest PC 0x0c08cd84 */
if(!s->budget--) { s->failed_pc=0x0c08cd84u; return 0; }
write(ram,r[13]+r[0],r[5],1);
goto P_0c08cd86;
P_0c08cd86: /* original 6043, guest PC 0x0c08cd86 */
if(!s->budget--) { s->failed_pc=0x0c08cd86u; return 0; }
r[0]=r[4];
goto P_0c08cd88;
P_0c08cd88: /* original 81da, guest PC 0x0c08cd88 */
if(!s->budget--) { s->failed_pc=0x0c08cd88u; return 0; }
write(ram,r[13]+20,r[0],2);
goto P_0c08cd8a;
P_0c08cd8a: /* original e048, guest PC 0x0c08cd8a */
if(!s->budget--) { s->failed_pc=0x0c08cd8au; return 0; }
r[0]=0x00000048u;
goto P_0c08cd8c;
P_0c08cd8c: /* original 03dc, guest PC 0x0c08cd8c */
if(!s->budget--) { s->failed_pc=0x0c08cd8cu; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+r[0],1);
goto P_0c08cd8e;
P_0c08cd8e: /* original 7301, guest PC 0x0c08cd8e */
if(!s->budget--) { s->failed_pc=0x0c08cd8eu; return 0; }
r[3]+=0x00000001u;
goto P_0c08cd90;
P_0c08cd90: /* original 0d34, guest PC 0x0c08cd90 */
if(!s->budget--) { s->failed_pc=0x0c08cd90u; return 0; }
write(ram,r[13]+r[0],r[3],1);
goto P_0c08cd92;
P_0c08cd92: /* original 4f26, guest PC 0x0c08cd92 */
if(!s->budget--) { s->failed_pc=0x0c08cd92u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c08cd94;
P_0c08cd94: /* original 6cf6, guest PC 0x0c08cd94 */
if(!s->budget--) { s->failed_pc=0x0c08cd94u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c08cd96;
P_0c08cd96: /* original 6df6, guest PC 0x0c08cd96 */
if(!s->budget--) { s->failed_pc=0x0c08cd96u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c08cd98;
P_0c08cd98: /* original 000b, guest PC 0x0c08cd98 */
if(!s->budget--) { s->failed_pc=0x0c08cd98u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c08cd9a: /* original 6ef6, guest PC 0x0c08cd9a */
if(!s->budget--) { s->failed_pc=0x0c08cd9au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c08cd9cu,s,ram);
P_0c08d00e: /* original 4f22, guest PC 0x0c08d00e */
if(!s->budget--) { s->failed_pc=0x0c08d00eu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c08d010;
P_0c08d010: /* original 8801, guest PC 0x0c08d010 */
if(!s->budget--) { s->failed_pc=0x0c08d010u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c08d012;
P_0c08d012: /* original 8d1a, guest PC 0x0c08d012 */
if(!s->budget--) { s->failed_pc=0x0c08d012u; return 0; }
cond=r[17]&1u;
r[12]=0x00000000u;
if(cond) { goto P_0c08d04a; }
goto P_0c08d016;
P_0c08d014: /* original ec00, guest PC 0x0c08d014 */
if(!s->budget--) { s->failed_pc=0x0c08d014u; return 0; }
r[12]=0x00000000u;
goto P_0c08d016;
P_0c08d016: /* original 60e2, guest PC 0x0c08d016 */
if(!s->budget--) { s->failed_pc=0x0c08d016u; return 0; }
tmp=read(ram,r[14],4);
r[0]=tmp;
goto P_0c08d018;
P_0c08d018: /* original 65c3, guest PC 0x0c08d018 */
if(!s->budget--) { s->failed_pc=0x0c08d018u; return 0; }
r[5]=r[12];
goto P_0c08d01a;
P_0c08d01a: /* original cb01, guest PC 0x0c08d01a */
if(!s->budget--) { s->failed_pc=0x0c08d01au; return 0; }
r[0]|=1u;
goto P_0c08d01c;
P_0c08d01c: /* original 2e02, guest PC 0x0c08d01c */
if(!s->budget--) { s->failed_pc=0x0c08d01cu; return 0; }
write(ram,r[14],r[0],4);
goto P_0c08d01e;
P_0c08d01e: /* original e028, guest PC 0x0c08d01e */
if(!s->budget--) { s->failed_pc=0x0c08d01eu; return 0; }
r[0]=0x00000028u;
goto P_0c08d020;
P_0c08d020: /* original 9485, guest PC 0x0c08d020 */
if(!s->budget--) { s->failed_pc=0x0c08d020u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08d12eu,2);
goto P_0c08d022;
P_0c08d022: /* original 0d45, guest PC 0x0c08d022 */
if(!s->budget--) { s->failed_pc=0x0c08d022u; return 0; }
write(ram,r[13]+r[0],r[4],2);
goto P_0c08d024;
P_0c08d024: /* original e040, guest PC 0x0c08d024 */
if(!s->budget--) { s->failed_pc=0x0c08d024u; return 0; }
r[0]=0x00000040u;
goto P_0c08d026;
P_0c08d026: /* original 1e4d, guest PC 0x0c08d026 */
if(!s->budget--) { s->failed_pc=0x0c08d026u; return 0; }
write(ram,r[14]+52,r[4],4);
goto P_0c08d028;
P_0c08d028: /* original 0e56, guest PC 0x0c08d028 */
if(!s->budget--) { s->failed_pc=0x0c08d028u; return 0; }
write(ram,r[14]+r[0],r[5],4);
goto P_0c08d02a;
P_0c08d02a: /* original b095, guest PC 0x0c08d02a */
if(!s->budget--) { s->failed_pc=0x0c08d02au; return 0; }
target=0x0c08d158u; r[16]=0x0c08d02eu;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08d02eu) { target=s->pc; goto dispatch; }
goto P_0c08d02e;
P_0c08d02c: /* original 64e3, guest PC 0x0c08d02c */
if(!s->budget--) { s->failed_pc=0x0c08d02cu; return 0; }
r[4]=r[14];
goto P_0c08d02e;
P_0c08d02e: /* original e02c, guest PC 0x0c08d02e */
if(!s->budget--) { s->failed_pc=0x0c08d02eu; return 0; }
r[0]=0x0000002cu;
goto P_0c08d030;
P_0c08d030: /* original 55ee, guest PC 0x0c08d030 */
if(!s->budget--) { s->failed_pc=0x0c08d030u; return 0; }
r[5]=read(ram,r[14]+56,4);
goto P_0c08d032;
P_0c08d032: /* original 54ef, guest PC 0x0c08d032 */
if(!s->budget--) { s->failed_pc=0x0c08d032u; return 0; }
r[4]=read(ram,r[14]+60,4);
goto P_0c08d034;
P_0c08d034: /* original 0dc4, guest PC 0x0c08d034 */
if(!s->budget--) { s->failed_pc=0x0c08d034u; return 0; }
write(ram,r[13]+r[0],r[12],1);
goto P_0c08d036;
P_0c08d036: /* original e02d, guest PC 0x0c08d036 */
if(!s->budget--) { s->failed_pc=0x0c08d036u; return 0; }
r[0]=0x0000002du;
goto P_0c08d038;
P_0c08d038: /* original 0d54, guest PC 0x0c08d038 */
if(!s->budget--) { s->failed_pc=0x0c08d038u; return 0; }
write(ram,r[13]+r[0],r[5],1);
goto P_0c08d03a;
P_0c08d03a: /* original 6043, guest PC 0x0c08d03a */
if(!s->budget--) { s->failed_pc=0x0c08d03au; return 0; }
r[0]=r[4];
goto P_0c08d03c;
P_0c08d03c: /* original 81da, guest PC 0x0c08d03c */
if(!s->budget--) { s->failed_pc=0x0c08d03cu; return 0; }
write(ram,r[13]+20,r[0],2);
goto P_0c08d03e;
P_0c08d03e: /* original e010, guest PC 0x0c08d03e */
if(!s->budget--) { s->failed_pc=0x0c08d03eu; return 0; }
r[0]=0x00000010u;
goto P_0c08d040;
P_0c08d040: /* original 81df, guest PC 0x0c08d040 */
if(!s->budget--) { s->failed_pc=0x0c08d040u; return 0; }
write(ram,r[13]+30,r[0],2);
goto P_0c08d042;
P_0c08d042: /* original e048, guest PC 0x0c08d042 */
if(!s->budget--) { s->failed_pc=0x0c08d042u; return 0; }
r[0]=0x00000048u;
goto P_0c08d044;
P_0c08d044: /* original 03dc, guest PC 0x0c08d044 */
if(!s->budget--) { s->failed_pc=0x0c08d044u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+r[0],1);
goto P_0c08d046;
P_0c08d046: /* original 7301, guest PC 0x0c08d046 */
if(!s->budget--) { s->failed_pc=0x0c08d046u; return 0; }
r[3]+=0x00000001u;
goto P_0c08d048;
P_0c08d048: /* original 0d34, guest PC 0x0c08d048 */
if(!s->budget--) { s->failed_pc=0x0c08d048u; return 0; }
write(ram,r[13]+r[0],r[3],1);
goto P_0c08d04a;
P_0c08d04a: /* original e048, guest PC 0x0c08d04a */
if(!s->budget--) { s->failed_pc=0x0c08d04au; return 0; }
r[0]=0x00000048u;
goto P_0c08d04c;
P_0c08d04c: /* original 02ee, guest PC 0x0c08d04c */
if(!s->budget--) { s->failed_pc=0x0c08d04cu; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c08d04e;
P_0c08d04e: /* original 906f, guest PC 0x0c08d04e */
if(!s->budget--) { s->failed_pc=0x0c08d04eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08d130u,2);
goto P_0c08d050;
P_0c08d050: /* original f526, guest PC 0x0c08d050 */
if(!s->budget--) { s->failed_pc=0x0c08d050u; return 0; }
vf3_matrix_load(s,ram,5,r[2]+r[0]);
goto P_0c08d052;
P_0c08d052: /* original c739, guest PC 0x0c08d052 */
if(!s->budget--) { s->failed_pc=0x0c08d052u; return 0; }
r[0]=0x0c08d138u;
goto P_0c08d054;
P_0c08d054: /* original f408, guest PC 0x0c08d054 */
if(!s->budget--) { s->failed_pc=0x0c08d054u; return 0; }
vf3_matrix_load(s,ram,4,r[0]);
goto P_0c08d056;
P_0c08d056: /* original f545, guest PC 0x0c08d056 */
if(!s->budget--) { s->failed_pc=0x0c08d056u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[5])>as_float(fr[4]))!=0);
goto P_0c08d058;
P_0c08d058: /* original 8b15, guest PC 0x0c08d058 */
if(!s->budget--) { s->failed_pc=0x0c08d058u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c08d086; }
goto P_0c08d05a;
P_0c08d05a: /* original e024, guest PC 0x0c08d05a */
if(!s->budget--) { s->failed_pc=0x0c08d05au; return 0; }
r[0]=0x00000024u;
goto P_0c08d05c;
P_0c08d05c: /* original f5e6, guest PC 0x0c08d05c */
if(!s->budget--) { s->failed_pc=0x0c08d05cu; return 0; }
vf3_matrix_load(s,ram,5,r[14]+r[0]);
goto P_0c08d05e;
P_0c08d05e: /* original f545, guest PC 0x0c08d05e */
if(!s->budget--) { s->failed_pc=0x0c08d05eu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[5])>as_float(fr[4]))!=0);
goto P_0c08d060;
P_0c08d060: /* original 8b11, guest PC 0x0c08d060 */
if(!s->budget--) { s->failed_pc=0x0c08d060u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c08d086; }
goto P_0c08d062;
P_0c08d062: /* original c736, guest PC 0x0c08d062 */
if(!s->budget--) { s->failed_pc=0x0c08d062u; return 0; }
r[0]=0x0c08d13cu;
goto P_0c08d064;
P_0c08d064: /* original f308, guest PC 0x0c08d064 */
if(!s->budget--) { s->failed_pc=0x0c08d064u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c08d066;
P_0c08d066: /* original f535, guest PC 0x0c08d066 */
if(!s->budget--) { s->failed_pc=0x0c08d066u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[5])>as_float(fr[3]))!=0);
goto P_0c08d068;
P_0c08d068: /* original 891a, guest PC 0x0c08d068 */
if(!s->budget--) { s->failed_pc=0x0c08d068u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c08d0a0; }
goto P_0c08d06a;
P_0c08d06a: /* original d535, guest PC 0x0c08d06a */
if(!s->budget--) { s->failed_pc=0x0c08d06au; return 0; }
r[5]=read(ram,0x0c08d140u,4);
goto P_0c08d06c;
P_0c08d06c: /* original 56e7, guest PC 0x0c08d06c */
if(!s->budget--) { s->failed_pc=0x0c08d06cu; return 0; }
r[6]=read(ram,r[14]+28,4);
goto P_0c08d06e;
P_0c08d06e: /* original 2658, guest PC 0x0c08d06e */
if(!s->budget--) { s->failed_pc=0x0c08d06eu; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[5])==0)!=0);
goto P_0c08d070;
P_0c08d070: /* original 8f09, guest PC 0x0c08d070 */
if(!s->budget--) { s->failed_pc=0x0c08d070u; return 0; }
cond=r[17]&1u;
r[4]=read(ram,r[14]+16,4);
if(!cond) { goto P_0c08d086; }
goto P_0c08d074;
P_0c08d072: /* original 54e4, guest PC 0x0c08d072 */
if(!s->budget--) { s->failed_pc=0x0c08d072u; return 0; }
r[4]=read(ram,r[14]+16,4);
goto P_0c08d074;
P_0c08d074: /* original e04c, guest PC 0x0c08d074 */
if(!s->budget--) { s->failed_pc=0x0c08d074u; return 0; }
r[0]=0x0000004cu;
goto P_0c08d076;
P_0c08d076: /* original 06ee, guest PC 0x0c08d076 */
if(!s->budget--) { s->failed_pc=0x0c08d076u; return 0; }
r[6]=read(ram,r[14]+r[0],4);
goto P_0c08d078;
P_0c08d078: /* original e050, guest PC 0x0c08d078 */
if(!s->budget--) { s->failed_pc=0x0c08d078u; return 0; }
r[0]=0x00000050u;
goto P_0c08d07a;
P_0c08d07a: /* original 066e, guest PC 0x0c08d07a */
if(!s->budget--) { s->failed_pc=0x0c08d07au; return 0; }
r[6]=read(ram,r[6]+r[0],4);
goto P_0c08d07c;
P_0c08d07c: /* original 2658, guest PC 0x0c08d07c */
if(!s->budget--) { s->failed_pc=0x0c08d07cu; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[5])==0)!=0);
goto P_0c08d07e;
P_0c08d07e: /* original 8b0f, guest PC 0x0c08d07e */
if(!s->budget--) { s->failed_pc=0x0c08d07eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c08d0a0; }
goto P_0c08d080;
P_0c08d080: /* original d330, guest PC 0x0c08d080 */
if(!s->budget--) { s->failed_pc=0x0c08d080u; return 0; }
r[3]=read(ram,0x0c08d144u,4);
goto P_0c08d082;
P_0c08d082: /* original 2438, guest PC 0x0c08d082 */
if(!s->budget--) { s->failed_pc=0x0c08d082u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[3])==0)!=0);
goto P_0c08d084;
P_0c08d084: /* original 890c, guest PC 0x0c08d084 */
if(!s->budget--) { s->failed_pc=0x0c08d084u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c08d0a0; }
goto P_0c08d086;
P_0c08d086: /* original e040, guest PC 0x0c08d086 */
if(!s->budget--) { s->failed_pc=0x0c08d086u; return 0; }
r[0]=0x00000040u;
goto P_0c08d088;
P_0c08d088: /* original 62e2, guest PC 0x0c08d088 */
if(!s->budget--) { s->failed_pc=0x0c08d088u; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c08d08a;
P_0c08d08a: /* original e3fe, guest PC 0x0c08d08a */
if(!s->budget--) { s->failed_pc=0x0c08d08au; return 0; }
r[3]=0xfffffffeu;
goto P_0c08d08c;
P_0c08d08c: /* original 2239, guest PC 0x0c08d08c */
if(!s->budget--) { s->failed_pc=0x0c08d08cu; return 0; }
r[2]&=r[3];
goto P_0c08d08e;
P_0c08d08e: /* original 2e22, guest PC 0x0c08d08e */
if(!s->budget--) { s->failed_pc=0x0c08d08eu; return 0; }
write(ram,r[14],r[2],4);
goto P_0c08d090;
P_0c08d090: /* original 1ecb, guest PC 0x0c08d090 */
if(!s->budget--) { s->failed_pc=0x0c08d090u; return 0; }
write(ram,r[14]+44,r[12],4);
goto P_0c08d092;
P_0c08d092: /* original 0dc4, guest PC 0x0c08d092 */
if(!s->budget--) { s->failed_pc=0x0c08d092u; return 0; }
write(ram,r[13]+r[0],r[12],1);
goto P_0c08d094;
P_0c08d094: /* original e02c, guest PC 0x0c08d094 */
if(!s->budget--) { s->failed_pc=0x0c08d094u; return 0; }
r[0]=0x0000002cu;
goto P_0c08d096;
P_0c08d096: /* original 0dc4, guest PC 0x0c08d096 */
if(!s->budget--) { s->failed_pc=0x0c08d096u; return 0; }
write(ram,r[13]+r[0],r[12],1);
goto P_0c08d098;
P_0c08d098: /* original e02d, guest PC 0x0c08d098 */
if(!s->budget--) { s->failed_pc=0x0c08d098u; return 0; }
r[0]=0x0000002du;
goto P_0c08d09a;
P_0c08d09a: /* original 0dc4, guest PC 0x0c08d09a */
if(!s->budget--) { s->failed_pc=0x0c08d09au; return 0; }
write(ram,r[13]+r[0],r[12],1);
goto P_0c08d09c;
P_0c08d09c: /* original 60c3, guest PC 0x0c08d09c */
if(!s->budget--) { s->failed_pc=0x0c08d09cu; return 0; }
r[0]=r[12];
goto P_0c08d09e;
P_0c08d09e: /* original 81da, guest PC 0x0c08d09e */
if(!s->budget--) { s->failed_pc=0x0c08d09eu; return 0; }
write(ram,r[13]+20,r[0],2);
goto P_0c08d0a0;
P_0c08d0a0: /* original 4f26, guest PC 0x0c08d0a0 */
if(!s->budget--) { s->failed_pc=0x0c08d0a0u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c08d0a2;
P_0c08d0a2: /* original 6cf6, guest PC 0x0c08d0a2 */
if(!s->budget--) { s->failed_pc=0x0c08d0a2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c08d0a4;
P_0c08d0a4: /* original 6df6, guest PC 0x0c08d0a4 */
if(!s->budget--) { s->failed_pc=0x0c08d0a4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c08d0a6;
P_0c08d0a6: /* original 000b, guest PC 0x0c08d0a6 */
if(!s->budget--) { s->failed_pc=0x0c08d0a6u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c08d0a8: /* original 6ef6, guest PC 0x0c08d0a8 */
if(!s->budget--) { s->failed_pc=0x0c08d0a8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c08d0aau,s,ram);
P_0c08d0b4: /* original 4f22, guest PC 0x0c08d0b4 */
if(!s->budget--) { s->failed_pc=0x0c08d0b4u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c08d0b6;
P_0c08d0b6: /* original 8801, guest PC 0x0c08d0b6 */
if(!s->budget--) { s->failed_pc=0x0c08d0b6u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c08d0b8;
P_0c08d0b8: /* original 8d15, guest PC 0x0c08d0b8 */
if(!s->budget--) { s->failed_pc=0x0c08d0b8u; return 0; }
cond=r[17]&1u;
r[14]=r[5];
if(cond) { goto P_0c08d0e6; }
goto P_0c08d0bc;
P_0c08d0ba: /* original 6e53, guest PC 0x0c08d0ba */
if(!s->budget--) { s->failed_pc=0x0c08d0bau; return 0; }
r[14]=r[5];
goto P_0c08d0bc;
P_0c08d0bc: /* original 9439, guest PC 0x0c08d0bc */
if(!s->budget--) { s->failed_pc=0x0c08d0bcu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08d132u,2);
goto P_0c08d0be;
P_0c08d0be: /* original e028, guest PC 0x0c08d0be */
if(!s->budget--) { s->failed_pc=0x0c08d0beu; return 0; }
r[0]=0x00000028u;
goto P_0c08d0c0;
P_0c08d0c0: /* original e500, guest PC 0x0c08d0c0 */
if(!s->budget--) { s->failed_pc=0x0c08d0c0u; return 0; }
r[5]=0x00000000u;
goto P_0c08d0c2;
P_0c08d0c2: /* original 0d45, guest PC 0x0c08d0c2 */
if(!s->budget--) { s->failed_pc=0x0c08d0c2u; return 0; }
write(ram,r[13]+r[0],r[4],2);
goto P_0c08d0c4;
P_0c08d0c4: /* original e040, guest PC 0x0c08d0c4 */
if(!s->budget--) { s->failed_pc=0x0c08d0c4u; return 0; }
r[0]=0x00000040u;
goto P_0c08d0c6;
P_0c08d0c6: /* original 1e4d, guest PC 0x0c08d0c6 */
if(!s->budget--) { s->failed_pc=0x0c08d0c6u; return 0; }
write(ram,r[14]+52,r[4],4);
goto P_0c08d0c8;
P_0c08d0c8: /* original 0e56, guest PC 0x0c08d0c8 */
if(!s->budget--) { s->failed_pc=0x0c08d0c8u; return 0; }
write(ram,r[14]+r[0],r[5],4);
goto P_0c08d0ca;
P_0c08d0ca: /* original b045, guest PC 0x0c08d0ca */
if(!s->budget--) { s->failed_pc=0x0c08d0cau; return 0; }
target=0x0c08d158u; r[16]=0x0c08d0ceu;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08d0ceu) { target=s->pc; goto dispatch; }
goto P_0c08d0ce;
P_0c08d0cc: /* original 64e3, guest PC 0x0c08d0cc */
if(!s->budget--) { s->failed_pc=0x0c08d0ccu; return 0; }
r[4]=r[14];
goto P_0c08d0ce;
P_0c08d0ce: /* original e02c, guest PC 0x0c08d0ce */
if(!s->budget--) { s->failed_pc=0x0c08d0ceu; return 0; }
r[0]=0x0000002cu;
goto P_0c08d0d0;
P_0c08d0d0: /* original e200, guest PC 0x0c08d0d0 */
if(!s->budget--) { s->failed_pc=0x0c08d0d0u; return 0; }
r[2]=0x00000000u;
goto P_0c08d0d2;
P_0c08d0d2: /* original 0d24, guest PC 0x0c08d0d2 */
if(!s->budget--) { s->failed_pc=0x0c08d0d2u; return 0; }
write(ram,r[13]+r[0],r[2],1);
goto P_0c08d0d4;
P_0c08d0d4: /* original e02d, guest PC 0x0c08d0d4 */
if(!s->budget--) { s->failed_pc=0x0c08d0d4u; return 0; }
r[0]=0x0000002du;
goto P_0c08d0d6;
P_0c08d0d6: /* original 53ee, guest PC 0x0c08d0d6 */
if(!s->budget--) { s->failed_pc=0x0c08d0d6u; return 0; }
r[3]=read(ram,r[14]+56,4);
goto P_0c08d0d8;
P_0c08d0d8: /* original 0d34, guest PC 0x0c08d0d8 */
if(!s->budget--) { s->failed_pc=0x0c08d0d8u; return 0; }
write(ram,r[13]+r[0],r[3],1);
goto P_0c08d0da;
P_0c08d0da: /* original 50ef, guest PC 0x0c08d0da */
if(!s->budget--) { s->failed_pc=0x0c08d0dau; return 0; }
r[0]=read(ram,r[14]+60,4);
goto P_0c08d0dc;
P_0c08d0dc: /* original 81da, guest PC 0x0c08d0dc */
if(!s->budget--) { s->failed_pc=0x0c08d0dcu; return 0; }
write(ram,r[13]+20,r[0],2);
goto P_0c08d0de;
P_0c08d0de: /* original e048, guest PC 0x0c08d0de */
if(!s->budget--) { s->failed_pc=0x0c08d0deu; return 0; }
r[0]=0x00000048u;
goto P_0c08d0e0;
P_0c08d0e0: /* original 03dc, guest PC 0x0c08d0e0 */
if(!s->budget--) { s->failed_pc=0x0c08d0e0u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+r[0],1);
goto P_0c08d0e2;
P_0c08d0e2: /* original 7301, guest PC 0x0c08d0e2 */
if(!s->budget--) { s->failed_pc=0x0c08d0e2u; return 0; }
r[3]+=0x00000001u;
goto P_0c08d0e4;
P_0c08d0e4: /* original 0d34, guest PC 0x0c08d0e4 */
if(!s->budget--) { s->failed_pc=0x0c08d0e4u; return 0; }
write(ram,r[13]+r[0],r[3],1);
goto P_0c08d0e6;
P_0c08d0e6: /* original 4f26, guest PC 0x0c08d0e6 */
if(!s->budget--) { s->failed_pc=0x0c08d0e6u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c08d0e8;
P_0c08d0e8: /* original 6df6, guest PC 0x0c08d0e8 */
if(!s->budget--) { s->failed_pc=0x0c08d0e8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c08d0ea;
P_0c08d0ea: /* original 000b, guest PC 0x0c08d0ea */
if(!s->budget--) { s->failed_pc=0x0c08d0eau; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c08d0ec: /* original 6ef6, guest PC 0x0c08d0ec */
if(!s->budget--) { s->failed_pc=0x0c08d0ecu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c08d0eeu,s,ram);
P_0c08d158: /* original d335, guest PC 0x0c08d158 */
if(!s->budget--) { s->failed_pc=0x0c08d158u; return 0; }
r[3]=read(ram,0x0c08d230u,4);
goto P_0c08d15a;
P_0c08d15a: /* original 7ffc, guest PC 0x0c08d15a */
if(!s->budget--) { s->failed_pc=0x0c08d15au; return 0; }
r[15]+=0xfffffffcu;
goto P_0c08d15c;
P_0c08d15c: /* original 554d, guest PC 0x0c08d15c */
if(!s->budget--) { s->failed_pc=0x0c08d15cu; return 0; }
r[5]=read(ram,r[4]+52,4);
goto P_0c08d15e;
P_0c08d15e: /* original e040, guest PC 0x0c08d15e */
if(!s->budget--) { s->failed_pc=0x0c08d15eu; return 0; }
r[0]=0x00000040u;
goto P_0c08d160;
P_0c08d160: /* original d732, guest PC 0x0c08d160 */
if(!s->budget--) { s->failed_pc=0x0c08d160u; return 0; }
r[7]=read(ram,0x0c08d22cu,4);
goto P_0c08d162;
P_0c08d162: /* original 4508, guest PC 0x0c08d162 */
if(!s->budget--) { s->failed_pc=0x0c08d162u; return 0; }
r[5]<<=2;
goto P_0c08d164;
P_0c08d164: /* original 064e, guest PC 0x0c08d164 */
if(!s->budget--) { s->failed_pc=0x0c08d164u; return 0; }
r[6]=read(ram,r[4]+r[0],4);
goto P_0c08d166;
P_0c08d166: /* original 2f32, guest PC 0x0c08d166 */
if(!s->budget--) { s->failed_pc=0x0c08d166u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c08d168;
P_0c08d168: /* original 335c, guest PC 0x0c08d168 */
if(!s->budget--) { s->failed_pc=0x0c08d168u; return 0; }
r[3]+=r[5];
goto P_0c08d16a;
P_0c08d16a: /* original 375c, guest PC 0x0c08d16a */
if(!s->budget--) { s->failed_pc=0x0c08d16au; return 0; }
r[7]+=r[5];
goto P_0c08d16c;
P_0c08d16c: /* original 6232, guest PC 0x0c08d16c */
if(!s->budget--) { s->failed_pc=0x0c08d16cu; return 0; }
tmp=read(ram,r[3],4);
r[2]=tmp;
goto P_0c08d16e;
P_0c08d16e: /* original 6772, guest PC 0x0c08d16e */
if(!s->budget--) { s->failed_pc=0x0c08d16eu; return 0; }
tmp=read(ram,r[7],4);
r[7]=tmp;
goto P_0c08d170;
P_0c08d170: /* original e040, guest PC 0x0c08d170 */
if(!s->budget--) { s->failed_pc=0x0c08d170u; return 0; }
r[0]=0x00000040u;
goto P_0c08d172;
P_0c08d172: /* original 6323, guest PC 0x0c08d172 */
if(!s->budget--) { s->failed_pc=0x0c08d172u; return 0; }
r[3]=r[2];
goto P_0c08d174;
P_0c08d174: /* original 336c, guest PC 0x0c08d174 */
if(!s->budget--) { s->failed_pc=0x0c08d174u; return 0; }
r[3]+=r[6];
goto P_0c08d176;
P_0c08d176: /* original 376c, guest PC 0x0c08d176 */
if(!s->budget--) { s->failed_pc=0x0c08d176u; return 0; }
r[7]+=r[6];
goto P_0c08d178;
P_0c08d178: /* original 2f22, guest PC 0x0c08d178 */
if(!s->budget--) { s->failed_pc=0x0c08d178u; return 0; }
write(ram,r[15],r[2],4);
goto P_0c08d17a;
P_0c08d17a: /* original 6230, guest PC 0x0c08d17a */
if(!s->budget--) { s->failed_pc=0x0c08d17au; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[3],1);
r[2]=tmp;
goto P_0c08d17c;
P_0c08d17c: /* original 6770, guest PC 0x0c08d17c */
if(!s->budget--) { s->failed_pc=0x0c08d17cu; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[7],1);
r[7]=tmp;
goto P_0c08d17e;
P_0c08d17e: /* original 622c, guest PC 0x0c08d17e */
if(!s->budget--) { s->failed_pc=0x0c08d17eu; return 0; }
r[2]=r[2]&255u;
goto P_0c08d180;
P_0c08d180: /* original 677c, guest PC 0x0c08d180 */
if(!s->budget--) { s->failed_pc=0x0c08d180u; return 0; }
r[7]=r[7]&255u;
goto P_0c08d182;
P_0c08d182: /* original 2f22, guest PC 0x0c08d182 */
if(!s->budget--) { s->failed_pc=0x0c08d182u; return 0; }
write(ram,r[15],r[2],4);
goto P_0c08d184;
P_0c08d184: /* original 145d, guest PC 0x0c08d184 */
if(!s->budget--) { s->failed_pc=0x0c08d184u; return 0; }
write(ram,r[4]+52,r[5],4);
goto P_0c08d186;
P_0c08d186: /* original 0466, guest PC 0x0c08d186 */
if(!s->budget--) { s->failed_pc=0x0c08d186u; return 0; }
write(ram,r[4]+r[0],r[6],4);
goto P_0c08d188;
P_0c08d188: /* original 147e, guest PC 0x0c08d188 */
if(!s->budget--) { s->failed_pc=0x0c08d188u; return 0; }
write(ram,r[4]+56,r[7],4);
goto P_0c08d18a;
P_0c08d18a: /* original 63f2, guest PC 0x0c08d18a */
if(!s->budget--) { s->failed_pc=0x0c08d18au; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c08d18c;
P_0c08d18c: /* original 143f, guest PC 0x0c08d18c */
if(!s->budget--) { s->failed_pc=0x0c08d18cu; return 0; }
write(ram,r[4]+60,r[3],4);
goto P_0c08d18e;
P_0c08d18e: /* original 000b, guest PC 0x0c08d18e */
if(!s->budget--) { s->failed_pc=0x0c08d18eu; return 0; }
target=r[16];
r[15]+=0x00000004u;
s->pc=target; return ram->oob==0;
P_0c08d190: /* original 7f04, guest PC 0x0c08d190 */
if(!s->budget--) { s->failed_pc=0x0c08d190u; return 0; }
r[15]+=0x00000004u;
return vf3_matrix_family(0x0c08d192u,s,ram);
P_0c0935f4: /* original f40b, guest PC 0x0c0935f4 */
if(!s->budget--) { s->failed_pc=0x0c0935f4u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c0935f6;
P_0c0935f6: /* original 0009, guest PC 0x0c0935f6 */
if(!s->budget--) { s->failed_pc=0x0c0935f6u; return 0; }
goto P_0c0935f8;
P_0c0935f8: /* original 64e3, guest PC 0x0c0935f8 */
if(!s->budget--) { s->failed_pc=0x0c0935f8u; return 0; }
r[4]=r[14];
goto P_0c0935fa;
P_0c0935fa: /* original 745c, guest PC 0x0c0935fa */
if(!s->budget--) { s->failed_pc=0x0c0935fau; return 0; }
r[4]+=0x0000005cu;
goto P_0c0935fc;
P_0c0935fc: /* original f049, guest PC 0x0c0935fc */
if(!s->budget--) { s->failed_pc=0x0c0935fcu; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c0935fe;
P_0c0935fe: /* original f149, guest PC 0x0c0935fe */
if(!s->budget--) { s->failed_pc=0x0c0935feu; return 0; }
vf3_matrix_load(s,ram,1,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c093600;
P_0c093600: /* original f249, guest PC 0x0c093600 */
if(!s->budget--) { s->failed_pc=0x0c093600u; return 0; }
vf3_matrix_load(s,ram,2,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c093602;
P_0c093602: /* original f38d, guest PC 0x0c093602 */
if(!s->budget--) { s->failed_pc=0x0c093602u; return 0; }
fr[3]=0;
goto P_0c093604;
P_0c093604: /* original f0ed, guest PC 0x0c093604 */
if(!s->budget--) { s->failed_pc=0x0c093604u; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+0,r[18],fr+3)) goto unsupported;
goto P_0c093606;
P_0c093606: /* original f37d, guest PC 0x0c093606 */
if(!s->budget--) { s->failed_pc=0x0c093606u; return 0; }
if(!vf3_fpu_fsrra(fr[3],r[18],&fr[3])) goto unsupported;
goto P_0c093608;
P_0c093608: /* original f232, guest PC 0x0c093608 */
if(!s->budget--) { s->failed_pc=0x0c093608u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c09360a;
P_0c09360a: /* original f132, guest PC 0x0c09360a */
if(!s->budget--) { s->failed_pc=0x0c09360au; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[3],r[18],'*');
goto P_0c09360c;
P_0c09360c: /* original f032, guest PC 0x0c09360c */
if(!s->budget--) { s->failed_pc=0x0c09360cu; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'*');
goto P_0c09360e;
P_0c09360e: /* original f42b, guest PC 0x0c09360e */
if(!s->budget--) { s->failed_pc=0x0c09360eu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c093610;
P_0c093610: /* original f41b, guest PC 0x0c093610 */
if(!s->budget--) { s->failed_pc=0x0c093610u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c093612;
P_0c093612: /* original f40b, guest PC 0x0c093612 */
if(!s->budget--) { s->failed_pc=0x0c093612u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c093614;
P_0c093614: /* original e01c, guest PC 0x0c093614 */
if(!s->budget--) { s->failed_pc=0x0c093614u; return 0; }
r[0]=0x0000001cu;
goto P_0c093616;
P_0c093616: /* original f3f6, guest PC 0x0c093616 */
if(!s->budget--) { s->failed_pc=0x0c093616u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c093618;
P_0c093618: /* original e020, guest PC 0x0c093618 */
if(!s->budget--) { s->failed_pc=0x0c093618u; return 0; }
r[0]=0x00000020u;
goto P_0c09361a;
P_0c09361a: /* original fc3a, guest PC 0x0c09361a */
if(!s->budget--) { s->failed_pc=0x0c09361au; return 0; }
vf3_matrix_store(s,ram,3,r[12]);
goto P_0c09361c;
P_0c09361c: /* original f3f6, guest PC 0x0c09361c */
if(!s->budget--) { s->failed_pc=0x0c09361cu; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c09361e;
P_0c09361e: /* original e004, guest PC 0x0c09361e */
if(!s->budget--) { s->failed_pc=0x0c09361eu; return 0; }
r[0]=0x00000004u;
goto P_0c093620;
P_0c093620: /* original fc37, guest PC 0x0c093620 */
if(!s->budget--) { s->failed_pc=0x0c093620u; return 0; }
vf3_matrix_store(s,ram,3,r[12]+r[0]);
goto P_0c093622;
P_0c093622: /* original e024, guest PC 0x0c093622 */
if(!s->budget--) { s->failed_pc=0x0c093622u; return 0; }
r[0]=0x00000024u;
goto P_0c093624;
P_0c093624: /* original f3f6, guest PC 0x0c093624 */
if(!s->budget--) { s->failed_pc=0x0c093624u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c093626;
P_0c093626: /* original 7f68, guest PC 0x0c093626 */
if(!s->budget--) { s->failed_pc=0x0c093626u; return 0; }
r[15]+=0x00000068u;
goto P_0c093628;
P_0c093628: /* original 4f26, guest PC 0x0c093628 */
if(!s->budget--) { s->failed_pc=0x0c093628u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c09362a;
P_0c09362a: /* original e008, guest PC 0x0c09362a */
if(!s->budget--) { s->failed_pc=0x0c09362au; return 0; }
r[0]=0x00000008u;
goto P_0c09362c;
P_0c09362c: /* original fc37, guest PC 0x0c09362c */
if(!s->budget--) { s->failed_pc=0x0c09362cu; return 0; }
vf3_matrix_store(s,ram,3,r[12]+r[0]);
goto P_0c09362e;
P_0c09362e: /* original 6af6, guest PC 0x0c09362e */
if(!s->budget--) { s->failed_pc=0x0c09362eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c093630;
P_0c093630: /* original 6bf6, guest PC 0x0c093630 */
if(!s->budget--) { s->failed_pc=0x0c093630u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c093632;
P_0c093632: /* original 6cf6, guest PC 0x0c093632 */
if(!s->budget--) { s->failed_pc=0x0c093632u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c093634;
P_0c093634: /* original 6df6, guest PC 0x0c093634 */
if(!s->budget--) { s->failed_pc=0x0c093634u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c093636;
P_0c093636: /* original 000b, guest PC 0x0c093636 */
if(!s->budget--) { s->failed_pc=0x0c093636u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c093638: /* original 6ef6, guest PC 0x0c093638 */
if(!s->budget--) { s->failed_pc=0x0c093638u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c09363au,s,ram);
P_0c09564e: /* original 2fe6, guest PC 0x0c09564e */
if(!s->budget--) { s->failed_pc=0x0c09564eu; return 0; }
r[15]-=4; write(ram,r[15],r[14],4);
goto P_0c095650;
P_0c095650: /* original 6163, guest PC 0x0c095650 */
if(!s->budget--) { s->failed_pc=0x0c095650u; return 0; }
r[1]=r[6];
goto P_0c095652;
P_0c095652: /* original 4f22, guest PC 0x0c095652 */
if(!s->budget--) { s->failed_pc=0x0c095652u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c095654;
P_0c095654: /* original d32f, guest PC 0x0c095654 */
if(!s->budget--) { s->failed_pc=0x0c095654u; return 0; }
r[3]=read(ram,0x0c095714u,4);
goto P_0c095656;
P_0c095656: /* original 430b, guest PC 0x0c095656 */
if(!s->budget--) { s->failed_pc=0x0c095656u; return 0; }
target=r[3];
r[16]=0x0c09565au;
r[0]=0x00000004u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09565au) { target=s->pc; goto dispatch; }
goto P_0c09565a;
P_0c095658: /* original e004, guest PC 0x0c095658 */
if(!s->budget--) { s->failed_pc=0x0c095658u; return 0; }
r[0]=0x00000004u;
goto P_0c09565a;
P_0c09565a: /* original 6743, guest PC 0x0c09565a */
if(!s->budget--) { s->failed_pc=0x0c09565au; return 0; }
r[7]=r[4];
goto P_0c09565c;
P_0c09565c: /* original 6e03, guest PC 0x0c09565c */
if(!s->budget--) { s->failed_pc=0x0c09565cu; return 0; }
r[14]=r[0];
goto P_0c09565e;
P_0c09565e: /* original 4e15, guest PC 0x0c09565e */
if(!s->budget--) { s->failed_pc=0x0c09565eu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[14]>0)!=0);
goto P_0c095660;
P_0c095660: /* original 6453, guest PC 0x0c095660 */
if(!s->budget--) { s->failed_pc=0x0c095660u; return 0; }
r[4]=r[5];
goto P_0c095662;
P_0c095662: /* original 8f06, guest PC 0x0c095662 */
if(!s->budget--) { s->failed_pc=0x0c095662u; return 0; }
cond=r[17]&1u;
r[5]=0x00000000u;
if(!cond) { goto P_0c095672; }
goto P_0c095666;
P_0c095664: /* original e500, guest PC 0x0c095664 */
if(!s->budget--) { s->failed_pc=0x0c095664u; return 0; }
r[5]=0x00000000u;
goto P_0c095666;
P_0c095666: /* original 6246, guest PC 0x0c095666 */
if(!s->budget--) { s->failed_pc=0x0c095666u; return 0; }
tmp=read(ram,r[4],4);
r[4]+=4;
r[2]=tmp;
goto P_0c095668;
P_0c095668: /* original 7501, guest PC 0x0c095668 */
if(!s->budget--) { s->failed_pc=0x0c095668u; return 0; }
r[5]+=0x00000001u;
goto P_0c09566a;
P_0c09566a: /* original 35e3, guest PC 0x0c09566a */
if(!s->budget--) { s->failed_pc=0x0c09566au; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[5]>=(int32_t)r[14])!=0);
goto P_0c09566c;
P_0c09566c: /* original 2722, guest PC 0x0c09566c */
if(!s->budget--) { s->failed_pc=0x0c09566cu; return 0; }
write(ram,r[7],r[2],4);
goto P_0c09566e;
P_0c09566e: /* original 8ffa, guest PC 0x0c09566e */
if(!s->budget--) { s->failed_pc=0x0c09566eu; return 0; }
cond=r[17]&1u;
r[7]+=0x00000004u;
if(!cond) { goto P_0c095666; }
goto P_0c095672;
P_0c095670: /* original 7704, guest PC 0x0c095670 */
if(!s->budget--) { s->failed_pc=0x0c095670u; return 0; }
r[7]+=0x00000004u;
goto P_0c095672;
P_0c095672: /* original ee03, guest PC 0x0c095672 */
if(!s->budget--) { s->failed_pc=0x0c095672u; return 0; }
r[14]=0x00000003u;
goto P_0c095674;
P_0c095674: /* original 2e69, guest PC 0x0c095674 */
if(!s->budget--) { s->failed_pc=0x0c095674u; return 0; }
r[14]&=r[6];
goto P_0c095676;
P_0c095676: /* original 2ee8, guest PC 0x0c095676 */
if(!s->budget--) { s->failed_pc=0x0c095676u; return 0; }
r[17]=(r[17]&~1u)|(((r[14]&r[14])==0)!=0);
goto P_0c095678;
P_0c095678: /* original 890d, guest PC 0x0c095678 */
if(!s->budget--) { s->failed_pc=0x0c095678u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c095696; }
goto P_0c09567a;
P_0c09567a: /* original 4e15, guest PC 0x0c09567a */
if(!s->budget--) { s->failed_pc=0x0c09567au; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[14]>0)!=0);
goto P_0c09567c;
P_0c09567c: /* original 6673, guest PC 0x0c09567c */
if(!s->budget--) { s->failed_pc=0x0c09567cu; return 0; }
r[6]=r[7];
goto P_0c09567e;
P_0c09567e: /* original 8f06, guest PC 0x0c09567e */
if(!s->budget--) { s->failed_pc=0x0c09567eu; return 0; }
cond=r[17]&1u;
r[5]=0x00000000u;
if(!cond) { goto P_0c09568e; }
goto P_0c095682;
P_0c095680: /* original e500, guest PC 0x0c095680 */
if(!s->budget--) { s->failed_pc=0x0c095680u; return 0; }
r[5]=0x00000000u;
goto P_0c095682;
P_0c095682: /* original 6346, guest PC 0x0c095682 */
if(!s->budget--) { s->failed_pc=0x0c095682u; return 0; }
tmp=read(ram,r[4],4);
r[4]+=4;
r[3]=tmp;
goto P_0c095684;
P_0c095684: /* original 7501, guest PC 0x0c095684 */
if(!s->budget--) { s->failed_pc=0x0c095684u; return 0; }
r[5]+=0x00000001u;
goto P_0c095686;
P_0c095686: /* original 35e3, guest PC 0x0c095686 */
if(!s->budget--) { s->failed_pc=0x0c095686u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[5]>=(int32_t)r[14])!=0);
goto P_0c095688;
P_0c095688: /* original 2630, guest PC 0x0c095688 */
if(!s->budget--) { s->failed_pc=0x0c095688u; return 0; }
write(ram,r[6],r[3],1);
goto P_0c09568a;
P_0c09568a: /* original 8ffa, guest PC 0x0c09568a */
if(!s->budget--) { s->failed_pc=0x0c09568au; return 0; }
cond=r[17]&1u;
r[6]+=0x00000001u;
if(!cond) { goto P_0c095682; }
goto P_0c09568e;
P_0c09568c: /* original 7601, guest PC 0x0c09568c */
if(!s->budget--) { s->failed_pc=0x0c09568cu; return 0; }
r[6]+=0x00000001u;
goto P_0c09568e;
P_0c09568e: /* original 4f26, guest PC 0x0c09568e */
if(!s->budget--) { s->failed_pc=0x0c09568eu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c095690;
P_0c095690: /* original 6063, guest PC 0x0c095690 */
if(!s->budget--) { s->failed_pc=0x0c095690u; return 0; }
r[0]=r[6];
goto P_0c095692;
P_0c095692: /* original 000b, guest PC 0x0c095692 */
if(!s->budget--) { s->failed_pc=0x0c095692u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c095694: /* original 6ef6, guest PC 0x0c095694 */
if(!s->budget--) { s->failed_pc=0x0c095694u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c095696;
P_0c095696: /* original 6073, guest PC 0x0c095696 */
if(!s->budget--) { s->failed_pc=0x0c095696u; return 0; }
r[0]=r[7];
goto P_0c095698;
P_0c095698: /* original 4f26, guest PC 0x0c095698 */
if(!s->budget--) { s->failed_pc=0x0c095698u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c09569a;
P_0c09569a: /* original 000b, guest PC 0x0c09569a */
if(!s->budget--) { s->failed_pc=0x0c09569au; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c09569c: /* original 6ef6, guest PC 0x0c09569c */
if(!s->budget--) { s->failed_pc=0x0c09569cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c09569eu,s,ram);
P_0c0c148e: /* original 4f22, guest PC 0x0c0c148e */
if(!s->budget--) { s->failed_pc=0x0c0c148eu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0c1490;
P_0c0c1490: /* original 0000, guest PC 0x0c0c1490 */
if(!s->budget--) { s->failed_pc=0x0c0c1490u; return 0; }
s->failed_pc=0x0c0c1490u; return 0;
goto P_0c0c1492;
P_0c0c1492: /* original 4100, guest PC 0x0c0c1492 */
if(!s->budget--) { s->failed_pc=0x0c0c1492u; return 0; }
r[17]=(r[17]&~1u)|((r[1]>>31)!=0);
r[1]<<=1;
goto P_0c0c1494;
P_0c0c1494: /* original 0000, guest PC 0x0c0c1494 */
if(!s->budget--) { s->failed_pc=0x0c0c1494u; return 0; }
s->failed_pc=0x0c0c1494u; return 0;
goto P_0c0c1496;
P_0c0c1496: /* original 4f80, guest PC 0x0c0c1496 */
if(!s->budget--) { s->failed_pc=0x0c0c1496u; return 0; }
s->failed_pc=0x0c0c1496u; return 0;
goto P_0c0c1498;
P_0c0c1498: /* original b4d4, guest PC 0x0c0c1498 */
if(!s->budget--) { s->failed_pc=0x0c0c1498u; return 0; }
target=0x0c0c1e44u; r[16]=0x0c0c149cu;
r[19]=r[12]*r[0];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c149cu) { target=s->pc; goto dispatch; }
goto P_0c0c149c;
P_0c0c149a: /* original 0c07, guest PC 0x0c0c149a */
if(!s->budget--) { s->failed_pc=0x0c0c149au; return 0; }
r[19]=r[12]*r[0];
goto P_0c0c149c;
P_0c0c149c: /* original 0000, guest PC 0x0c0c149c */
if(!s->budget--) { s->failed_pc=0x0c0c149cu; return 0; }
s->failed_pc=0x0c0c149cu; return 0;
goto P_0c0c149e;
P_0c0c149e: /* original 4180, guest PC 0x0c0c149e */
if(!s->budget--) { s->failed_pc=0x0c0c149eu; return 0; }
s->failed_pc=0x0c0c149eu; return 0;
goto P_0c0c14a0;
P_0c0c14a0: /* original 0000, guest PC 0x0c0c14a0 */
if(!s->budget--) { s->failed_pc=0x0c0c14a0u; return 0; }
s->failed_pc=0x0c0c14a0u; return 0;
goto P_0c0c14a2;
P_0c0c14a2: /* original 41c0, guest PC 0x0c0c14a2 */
if(!s->budget--) { s->failed_pc=0x0c0c14a2u; return 0; }
s->failed_pc=0x0c0c14a2u; return 0;
goto P_0c0c14a4;
P_0c0c14a4: /* original 60e3, guest PC 0x0c0c14a4 */
if(!s->budget--) { s->failed_pc=0x0c0c14a4u; return 0; }
r[0]=r[14];
goto P_0c0c14a6;
P_0c0c14a6: /* original 8820, guest PC 0x0c0c14a6 */
if(!s->budget--) { s->failed_pc=0x0c0c14a6u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000020u)!=0);
goto P_0c0c14a8;
P_0c0c14a8: /* original 897a, guest PC 0x0c0c14a8 */
if(!s->budget--) { s->failed_pc=0x0c0c14a8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c15a0; }
goto P_0c0c14aa;
P_0c0c14aa: /* original e30f, guest PC 0x0c0c14aa */
if(!s->budget--) { s->failed_pc=0x0c0c14aau; return 0; }
r[3]=0x0000000fu;
goto P_0c0c14ac;
P_0c0c14ac: /* original 23e9, guest PC 0x0c0c14ac */
if(!s->budget--) { s->failed_pc=0x0c0c14acu; return 0; }
r[3]&=r[14];
goto P_0c0c14ae;
P_0c0c14ae: /* original 435a, guest PC 0x0c0c14ae */
if(!s->budget--) { s->failed_pc=0x0c0c14aeu; return 0; }
r[53]=r[3];
goto P_0c0c14b0;
P_0c0c14b0: /* original 4311, guest PC 0x0c0c14b0 */
if(!s->budget--) { s->failed_pc=0x0c0c14b0u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>=0)!=0);
goto P_0c0c14b2;
P_0c0c14b2: /* original 8d04, guest PC 0x0c0c14b2 */
if(!s->budget--) { s->failed_pc=0x0c0c14b2u; return 0; }
cond=r[17]&1u;
fr[3]=vf3_fpu_float(r[53],r[18]);
if(cond) { goto P_0c0c14be; }
goto P_0c0c14b6;
P_0c0c14b4: /* original f32d, guest PC 0x0c0c14b4 */
if(!s->budget--) { s->failed_pc=0x0c0c14b4u; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c0c14b6;
P_0c0c14b6: /* original d242, guest PC 0x0c0c14b6 */
if(!s->budget--) { s->failed_pc=0x0c0c14b6u; return 0; }
r[2]=read(ram,0x0c0c15c0u,4);
goto P_0c0c14b8;
P_0c0c14b8: /* original 425a, guest PC 0x0c0c14b8 */
if(!s->budget--) { s->failed_pc=0x0c0c14b8u; return 0; }
r[53]=r[2];
goto P_0c0c14ba;
P_0c0c14ba: /* original f20d, guest PC 0x0c0c14ba */
if(!s->budget--) { s->failed_pc=0x0c0c14bau; return 0; }
fr[2]=r[53];
goto P_0c0c14bc;
P_0c0c14bc: /* original f320, guest PC 0x0c0c14bc */
if(!s->budget--) { s->failed_pc=0x0c0c14bcu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[2],r[18],'+');
goto P_0c0c14be;
P_0c0c14be: /* original f1d8, guest PC 0x0c0c14be */
if(!s->budget--) { s->failed_pc=0x0c0c14beu; return 0; }
vf3_matrix_load(s,ram,1,r[13]);
goto P_0c0c14c0;
P_0c0c14c0: /* original e008, guest PC 0x0c0c14c0 */
if(!s->budget--) { s->failed_pc=0x0c0c14c0u; return 0; }
r[0]=0x00000008u;
goto P_0c0c14c2;
P_0c0c14c2: /* original f0ec, guest PC 0x0c0c14c2 */
if(!s->budget--) { s->failed_pc=0x0c0c14c2u; return 0; }
vf3_matrix_move(s,0,14);
goto P_0c0c14c4;
P_0c0c14c4: /* original f13e, guest PC 0x0c0c14c4 */
if(!s->budget--) { s->failed_pc=0x0c0c14c4u; return 0; }
fr[1]=vf3_fpu_mac(fr[0],fr[3],fr[1],r[18]);
goto P_0c0c14c6;
P_0c0c14c6: /* original ff17, guest PC 0x0c0c14c6 */
if(!s->budget--) { s->failed_pc=0x0c0c14c6u; return 0; }
vf3_matrix_store(s,ram,1,r[15]+r[0]);
goto P_0c0c14c8;
P_0c0c14c8: /* original 9375, guest PC 0x0c0c14c8 */
if(!s->budget--) { s->failed_pc=0x0c0c14c8u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c15b6u,2);
goto P_0c0c14ca;
P_0c0c14ca: /* original 2e39, guest PC 0x0c0c14ca */
if(!s->budget--) { s->failed_pc=0x0c0c14cau; return 0; }
r[14]&=r[3];
goto P_0c0c14cc;
P_0c0c14cc: /* original 4e09, guest PC 0x0c0c14cc */
if(!s->budget--) { s->failed_pc=0x0c0c14ccu; return 0; }
r[14]>>=2;
goto P_0c0c14ce;
P_0c0c14ce: /* original 4e09, guest PC 0x0c0c14ce */
if(!s->budget--) { s->failed_pc=0x0c0c14ceu; return 0; }
r[14]>>=2;
goto P_0c0c14d0;
P_0c0c14d0: /* original 4e5a, guest PC 0x0c0c14d0 */
if(!s->budget--) { s->failed_pc=0x0c0c14d0u; return 0; }
r[53]=r[14];
goto P_0c0c14d2;
P_0c0c14d2: /* original 4e11, guest PC 0x0c0c14d2 */
if(!s->budget--) { s->failed_pc=0x0c0c14d2u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[14]>=0)!=0);
goto P_0c0c14d4;
P_0c0c14d4: /* original 8d04, guest PC 0x0c0c14d4 */
if(!s->budget--) { s->failed_pc=0x0c0c14d4u; return 0; }
cond=r[17]&1u;
fr[3]=vf3_fpu_float(r[53],r[18]);
if(cond) { goto P_0c0c14e0; }
goto P_0c0c14d8;
P_0c0c14d6: /* original f32d, guest PC 0x0c0c14d6 */
if(!s->budget--) { s->failed_pc=0x0c0c14d6u; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c0c14d8;
P_0c0c14d8: /* original d239, guest PC 0x0c0c14d8 */
if(!s->budget--) { s->failed_pc=0x0c0c14d8u; return 0; }
r[2]=read(ram,0x0c0c15c0u,4);
goto P_0c0c14da;
P_0c0c14da: /* original 425a, guest PC 0x0c0c14da */
if(!s->budget--) { s->failed_pc=0x0c0c14dau; return 0; }
r[53]=r[2];
goto P_0c0c14dc;
P_0c0c14dc: /* original f20d, guest PC 0x0c0c14dc */
if(!s->budget--) { s->failed_pc=0x0c0c14dcu; return 0; }
fr[2]=r[53];
goto P_0c0c14de;
P_0c0c14de: /* original f320, guest PC 0x0c0c14de */
if(!s->budget--) { s->failed_pc=0x0c0c14deu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[2],r[18],'+');
goto P_0c0c14e0;
P_0c0c14e0: /* original e004, guest PC 0x0c0c14e0 */
if(!s->budget--) { s->failed_pc=0x0c0c14e0u; return 0; }
r[0]=0x00000004u;
goto P_0c0c14e2;
P_0c0c14e2: /* original f0fc, guest PC 0x0c0c14e2 */
if(!s->budget--) { s->failed_pc=0x0c0c14e2u; return 0; }
vf3_matrix_move(s,0,15);
goto P_0c0c14e4;
P_0c0c14e4: /* original f1d6, guest PC 0x0c0c14e4 */
if(!s->budget--) { s->failed_pc=0x0c0c14e4u; return 0; }
vf3_matrix_load(s,ram,1,r[13]+r[0]);
goto P_0c0c14e6;
P_0c0c14e6: /* original e00c, guest PC 0x0c0c14e6 */
if(!s->budget--) { s->failed_pc=0x0c0c14e6u; return 0; }
r[0]=0x0000000cu;
goto P_0c0c14e8;
P_0c0c14e8: /* original 64f3, guest PC 0x0c0c14e8 */
if(!s->budget--) { s->failed_pc=0x0c0c14e8u; return 0; }
r[4]=r[15];
goto P_0c0c14ea;
P_0c0c14ea: /* original f13e, guest PC 0x0c0c14ea */
if(!s->budget--) { s->failed_pc=0x0c0c14eau; return 0; }
fr[1]=vf3_fpu_mac(fr[0],fr[3],fr[1],r[18]);
goto P_0c0c14ec;
P_0c0c14ec: /* original ff17, guest PC 0x0c0c14ec */
if(!s->budget--) { s->failed_pc=0x0c0c14ecu; return 0; }
vf3_matrix_store(s,ram,1,r[15]+r[0]);
goto P_0c0c14ee;
P_0c0c14ee: /* original e010, guest PC 0x0c0c14ee */
if(!s->budget--) { s->failed_pc=0x0c0c14eeu; return 0; }
r[0]=0x00000010u;
goto P_0c0c14f0;
P_0c0c14f0: /* original f3d6, guest PC 0x0c0c14f0 */
if(!s->budget--) { s->failed_pc=0x0c0c14f0u; return 0; }
vf3_matrix_load(s,ram,3,r[13]+r[0]);
goto P_0c0c14f2;
P_0c0c14f2: /* original e014, guest PC 0x0c0c14f2 */
if(!s->budget--) { s->failed_pc=0x0c0c14f2u; return 0; }
r[0]=0x00000014u;
goto P_0c0c14f4;
P_0c0c14f4: /* original f6ec, guest PC 0x0c0c14f4 */
if(!s->budget--) { s->failed_pc=0x0c0c14f4u; return 0; }
vf3_matrix_move(s,6,14);
goto P_0c0c14f6;
P_0c0c14f6: /* original f632, guest PC 0x0c0c14f6 */
if(!s->budget--) { s->failed_pc=0x0c0c14f6u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[3],r[18],'*');
goto P_0c0c14f8;
P_0c0c14f8: /* original 62f2, guest PC 0x0c0c14f8 */
if(!s->budget--) { s->failed_pc=0x0c0c14f8u; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c0c14fa;
P_0c0c14fa: /* original f3d6, guest PC 0x0c0c14fa */
if(!s->budget--) { s->failed_pc=0x0c0c14fau; return 0; }
vf3_matrix_load(s,ram,3,r[13]+r[0]);
goto P_0c0c14fc;
P_0c0c14fc: /* original e024, guest PC 0x0c0c14fc */
if(!s->budget--) { s->failed_pc=0x0c0c14fcu; return 0; }
r[0]=0x00000024u;
goto P_0c0c14fe;
P_0c0c14fe: /* original 012d, guest PC 0x0c0c14fe */
if(!s->budget--) { s->failed_pc=0x0c0c14feu; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,r[2]+r[0],2);
goto P_0c0c1500;
P_0c0c1500: /* original d030, guest PC 0x0c0c1500 */
if(!s->budget--) { s->failed_pc=0x0c0c1500u; return 0; }
r[0]=read(ram,0x0c0c15c4u,4);
goto P_0c0c1502;
P_0c0c1502: /* original 611d, guest PC 0x0c0c1502 */
if(!s->budget--) { s->failed_pc=0x0c0c1502u; return 0; }
r[1]=r[1]&65535u;
goto P_0c0c1504;
P_0c0c1504: /* original f70c, guest PC 0x0c0c1504 */
if(!s->budget--) { s->failed_pc=0x0c0c1504u; return 0; }
vf3_matrix_move(s,7,0);
goto P_0c0c1506;
P_0c0c1506: /* original 4108, guest PC 0x0c0c1506 */
if(!s->budget--) { s->failed_pc=0x0c0c1506u; return 0; }
r[1]<<=2;
goto P_0c0c1508;
P_0c0c1508: /* original f732, guest PC 0x0c0c1508 */
if(!s->budget--) { s->failed_pc=0x0c0c1508u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[3],r[18],'*');
goto P_0c0c150a;
P_0c0c150a: /* original f816, guest PC 0x0c0c150a */
if(!s->budget--) { s->failed_pc=0x0c0c150au; return 0; }
vf3_matrix_load(s,ram,8,r[1]+r[0]);
goto P_0c0c150c;
P_0c0c150c: /* original e004, guest PC 0x0c0c150c */
if(!s->budget--) { s->failed_pc=0x0c0c150cu; return 0; }
r[0]=0x00000004u;
goto P_0c0c150e;
P_0c0c150e: /* original f5f6, guest PC 0x0c0c150e */
if(!s->budget--) { s->failed_pc=0x0c0c150eu; return 0; }
vf3_matrix_load(s,ram,5,r[15]+r[0]);
goto P_0c0c1510;
P_0c0c1510: /* original e010, guest PC 0x0c0c1510 */
if(!s->budget--) { s->failed_pc=0x0c0c1510u; return 0; }
r[0]=0x00000010u;
goto P_0c0c1512;
P_0c0c1512: /* original d22d, guest PC 0x0c0c1512 */
if(!s->budget--) { s->failed_pc=0x0c0c1512u; return 0; }
r[2]=read(ram,0x0c0c15c8u,4);
goto P_0c0c1514;
P_0c0c1514: /* original f4f6, guest PC 0x0c0c1514 */
if(!s->budget--) { s->failed_pc=0x0c0c1514u; return 0; }
vf3_matrix_load(s,ram,4,r[15]+r[0]);
goto P_0c0c1516;
P_0c0c1516: /* original 420b, guest PC 0x0c0c1516 */
if(!s->budget--) { s->failed_pc=0x0c0c1516u; return 0; }
target=r[2];
r[16]=0x0c0c151au;
r[4]+=0x00000014u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c151au) { target=s->pc; goto dispatch; }
goto P_0c0c151a;
P_0c0c1518: /* original 7414, guest PC 0x0c0c1518 */
if(!s->budget--) { s->failed_pc=0x0c0c1518u; return 0; }
r[4]+=0x00000014u;
goto P_0c0c151a;
P_0c0c151a: /* original e014, guest PC 0x0c0c151a */
if(!s->budget--) { s->failed_pc=0x0c0c151au; return 0; }
r[0]=0x00000014u;
goto P_0c0c151c;
P_0c0c151c: /* original d32b, guest PC 0x0c0c151c */
if(!s->budget--) { s->failed_pc=0x0c0c151cu; return 0; }
r[3]=read(ram,0x0c0c15ccu,4);
goto P_0c0c151e;
P_0c0c151e: /* original f9d6, guest PC 0x0c0c151e */
if(!s->budget--) { s->failed_pc=0x0c0c151eu; return 0; }
vf3_matrix_load(s,ram,9,r[13]+r[0]);
goto P_0c0c1520;
P_0c0c1520: /* original e010, guest PC 0x0c0c1520 */
if(!s->budget--) { s->failed_pc=0x0c0c1520u; return 0; }
r[0]=0x00000010u;
goto P_0c0c1522;
P_0c0c1522: /* original f8d6, guest PC 0x0c0c1522 */
if(!s->budget--) { s->failed_pc=0x0c0c1522u; return 0; }
vf3_matrix_load(s,ram,8,r[13]+r[0]);
goto P_0c0c1524;
P_0c0c1524: /* original e00c, guest PC 0x0c0c1524 */
if(!s->budget--) { s->failed_pc=0x0c0c1524u; return 0; }
r[0]=0x0000000cu;
goto P_0c0c1526;
P_0c0c1526: /* original f5f6, guest PC 0x0c0c1526 */
if(!s->budget--) { s->failed_pc=0x0c0c1526u; return 0; }
vf3_matrix_load(s,ram,5,r[15]+r[0]);
goto P_0c0c1528;
P_0c0c1528: /* original e008, guest PC 0x0c0c1528 */
if(!s->budget--) { s->failed_pc=0x0c0c1528u; return 0; }
r[0]=0x00000008u;
goto P_0c0c152a;
P_0c0c152a: /* original f4f6, guest PC 0x0c0c152a */
if(!s->budget--) { s->failed_pc=0x0c0c152au; return 0; }
vf3_matrix_load(s,ram,4,r[15]+r[0]);
goto P_0c0c152c;
P_0c0c152c: /* original 64f3, guest PC 0x0c0c152c */
if(!s->budget--) { s->failed_pc=0x0c0c152cu; return 0; }
r[4]=r[15];
goto P_0c0c152e;
P_0c0c152e: /* original f7fc, guest PC 0x0c0c152e */
if(!s->budget--) { s->failed_pc=0x0c0c152eu; return 0; }
vf3_matrix_move(s,7,15);
goto P_0c0c1530;
P_0c0c1530: /* original f6ec, guest PC 0x0c0c1530 */
if(!s->budget--) { s->failed_pc=0x0c0c1530u; return 0; }
vf3_matrix_move(s,6,14);
goto P_0c0c1532;
P_0c0c1532: /* original 430b, guest PC 0x0c0c1532 */
if(!s->budget--) { s->failed_pc=0x0c0c1532u; return 0; }
target=r[3];
r[16]=0x0c0c1536u;
r[4]+=0x00000014u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c1536u) { target=s->pc; goto dispatch; }
goto P_0c0c1536;
P_0c0c1534: /* original 7414, guest PC 0x0c0c1534 */
if(!s->budget--) { s->failed_pc=0x0c0c1534u; return 0; }
r[4]+=0x00000014u;
goto P_0c0c1536;
P_0c0c1536: /* original f39d, guest PC 0x0c0c1536 */
if(!s->budget--) { s->failed_pc=0x0c0c1536u; return 0; }
fr[3]=0x3f800000u;
goto P_0c0c1538;
P_0c0c1538: /* original e044, guest PC 0x0c0c1538 */
if(!s->budget--) { s->failed_pc=0x0c0c1538u; return 0; }
r[0]=0x00000044u;
goto P_0c0c153a;
P_0c0c153a: /* original 943d, guest PC 0x0c0c153a */
if(!s->budget--) { s->failed_pc=0x0c0c153au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c15b8u,2);
goto P_0c0c153c;
P_0c0c153c: /* original ff37, guest PC 0x0c0c153c */
if(!s->budget--) { s->failed_pc=0x0c0c153cu; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0c153e;
P_0c0c153e: /* original d324, guest PC 0x0c0c153e */
if(!s->budget--) { s->failed_pc=0x0c0c153eu; return 0; }
r[3]=read(ram,0x0c0c15d0u,4);
goto P_0c0c1540;
P_0c0c1540: /* original 923c, guest PC 0x0c0c1540 */
if(!s->budget--) { s->failed_pc=0x0c0c1540u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c15bcu,2);
goto P_0c0c1542;
P_0c0c1542: /* original 6532, guest PC 0x0c0c1542 */
if(!s->budget--) { s->failed_pc=0x0c0c1542u; return 0; }
tmp=read(ram,r[3],4);
r[5]=tmp;
goto P_0c0c1544;
P_0c0c1544: /* original 9639, guest PC 0x0c0c1544 */
if(!s->budget--) { s->failed_pc=0x0c0c1544u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c15bau,2);
goto P_0c0c1546;
P_0c0c1546: /* original 2258, guest PC 0x0c0c1546 */
if(!s->budget--) { s->failed_pc=0x0c0c1546u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[5])==0)!=0);
goto P_0c0c1548;
P_0c0c1548: /* original 8901, guest PC 0x0c0c1548 */
if(!s->budget--) { s->failed_pc=0x0c0c1548u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c154e; }
goto P_0c0c154a;
P_0c0c154a: /* original a01b, guest PC 0x0c0c154a */
if(!s->budget--) { s->failed_pc=0x0c0c154au; return 0; }
r[4]=r[6];
goto P_0c0c1584;
P_0c0c154c: /* original 6463, guest PC 0x0c0c154c */
if(!s->budget--) { s->failed_pc=0x0c0c154cu; return 0; }
r[4]=r[6];
goto P_0c0c154e;
P_0c0c154e: /* original 9136, guest PC 0x0c0c154e */
if(!s->budget--) { s->failed_pc=0x0c0c154eu; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c15beu,2);
goto P_0c0c1550;
P_0c0c1550: /* original 2518, guest PC 0x0c0c1550 */
if(!s->budget--) { s->failed_pc=0x0c0c1550u; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[1])==0)!=0);
goto P_0c0c1552;
P_0c0c1552: /* original 8917, guest PC 0x0c0c1552 */
if(!s->budget--) { s->failed_pc=0x0c0c1552u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c1584; }
goto P_0c0c1554;
P_0c0c1554: /* original c71f, guest PC 0x0c0c1554 */
if(!s->budget--) { s->failed_pc=0x0c0c1554u; return 0; }
r[0]=0x0c0c15d4u;
goto P_0c0c1556;
P_0c0c1556: /* original 6463, guest PC 0x0c0c1556 */
if(!s->budget--) { s->failed_pc=0x0c0c1556u; return 0; }
r[4]=r[6];
goto P_0c0c1558;
P_0c0c1558: /* original f308, guest PC 0x0c0c1558 */
if(!s->budget--) { s->failed_pc=0x0c0c1558u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c0c155a;
P_0c0c155a: /* original e044, guest PC 0x0c0c155a */
if(!s->budget--) { s->failed_pc=0x0c0c155au; return 0; }
r[0]=0x00000044u;
goto P_0c0c155c;
P_0c0c155c: /* original ff37, guest PC 0x0c0c155c */
if(!s->budget--) { s->failed_pc=0x0c0c155cu; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0c155e;
P_0c0c155e: /* original c71e, guest PC 0x0c0c155e */
if(!s->budget--) { s->failed_pc=0x0c0c155eu; return 0; }
r[0]=0x0c0c15d8u;
goto P_0c0c1560;
P_0c0c1560: /* original f308, guest PC 0x0c0c1560 */
if(!s->budget--) { s->failed_pc=0x0c0c1560u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c0c1562;
P_0c0c1562: /* original e024, guest PC 0x0c0c1562 */
if(!s->budget--) { s->failed_pc=0x0c0c1562u; return 0; }
r[0]=0x00000024u;
goto P_0c0c1564;
P_0c0c1564: /* original f2f6, guest PC 0x0c0c1564 */
if(!s->budget--) { s->failed_pc=0x0c0c1564u; return 0; }
vf3_matrix_load(s,ram,2,r[15]+r[0]);
goto P_0c0c1566;
P_0c0c1566: /* original e024, guest PC 0x0c0c1566 */
if(!s->budget--) { s->failed_pc=0x0c0c1566u; return 0; }
r[0]=0x00000024u;
goto P_0c0c1568;
P_0c0c1568: /* original f231, guest PC 0x0c0c1568 */
if(!s->budget--) { s->failed_pc=0x0c0c1568u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'-');
goto P_0c0c156a;
P_0c0c156a: /* original ff27, guest PC 0x0c0c156a */
if(!s->budget--) { s->failed_pc=0x0c0c156au; return 0; }
vf3_matrix_store(s,ram,2,r[15]+r[0]);
goto P_0c0c156c;
P_0c0c156c: /* original c71b, guest PC 0x0c0c156c */
if(!s->budget--) { s->failed_pc=0x0c0c156cu; return 0; }
r[0]=0x0c0c15dcu;
goto P_0c0c156e;
P_0c0c156e: /* original f408, guest PC 0x0c0c156e */
if(!s->budget--) { s->failed_pc=0x0c0c156eu; return 0; }
vf3_matrix_load(s,ram,4,r[0]);
goto P_0c0c1570;
P_0c0c1570: /* original e02c, guest PC 0x0c0c1570 */
if(!s->budget--) { s->failed_pc=0x0c0c1570u; return 0; }
r[0]=0x0000002cu;
goto P_0c0c1572;
P_0c0c1572: /* original f2f6, guest PC 0x0c0c1572 */
if(!s->budget--) { s->failed_pc=0x0c0c1572u; return 0; }
vf3_matrix_load(s,ram,2,r[15]+r[0]);
goto P_0c0c1574;
P_0c0c1574: /* original e02c, guest PC 0x0c0c1574 */
if(!s->budget--) { s->failed_pc=0x0c0c1574u; return 0; }
r[0]=0x0000002cu;
goto P_0c0c1576;
P_0c0c1576: /* original f240, guest PC 0x0c0c1576 */
if(!s->budget--) { s->failed_pc=0x0c0c1576u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[4],r[18],'+');
goto P_0c0c1578;
P_0c0c1578: /* original ff27, guest PC 0x0c0c1578 */
if(!s->budget--) { s->failed_pc=0x0c0c1578u; return 0; }
vf3_matrix_store(s,ram,2,r[15]+r[0]);
goto P_0c0c157a;
P_0c0c157a: /* original e034, guest PC 0x0c0c157a */
if(!s->budget--) { s->failed_pc=0x0c0c157au; return 0; }
r[0]=0x00000034u;
goto P_0c0c157c;
P_0c0c157c: /* original f2f6, guest PC 0x0c0c157c */
if(!s->budget--) { s->failed_pc=0x0c0c157cu; return 0; }
vf3_matrix_load(s,ram,2,r[15]+r[0]);
goto P_0c0c157e;
P_0c0c157e: /* original e034, guest PC 0x0c0c157e */
if(!s->budget--) { s->failed_pc=0x0c0c157eu; return 0; }
r[0]=0x00000034u;
goto P_0c0c1580;
P_0c0c1580: /* original f241, guest PC 0x0c0c1580 */
if(!s->budget--) { s->failed_pc=0x0c0c1580u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[4],r[18],'-');
goto P_0c0c1582;
P_0c0c1582: /* original ff27, guest PC 0x0c0c1582 */
if(!s->budget--) { s->failed_pc=0x0c0c1582u; return 0; }
vf3_matrix_store(s,ram,2,r[15]+r[0]);
goto P_0c0c1584;
P_0c0c1584: /* original 53d8, guest PC 0x0c0c1584 */
if(!s->budget--) { s->failed_pc=0x0c0c1584u; return 0; }
r[3]=read(ram,r[13]+32,4);
goto P_0c0c1586;
P_0c0c1586: /* original d016, guest PC 0x0c0c1586 */
if(!s->budget--) { s->failed_pc=0x0c0c1586u; return 0; }
r[0]=read(ram,0x0c0c15e0u,4);
goto P_0c0c1588;
P_0c0c1588: /* original 4300, guest PC 0x0c0c1588 */
if(!s->budget--) { s->failed_pc=0x0c0c1588u; return 0; }
r[17]=(r[17]&~1u)|((r[3]>>31)!=0);
r[3]<<=1;
goto P_0c0c158a;
P_0c0c158a: /* original 023d, guest PC 0x0c0c158a */
if(!s->budget--) { s->failed_pc=0x0c0c158au; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[3]+r[0],2);
goto P_0c0c158c;
P_0c0c158c: /* original e300, guest PC 0x0c0c158c */
if(!s->budget--) { s->failed_pc=0x0c0c158cu; return 0; }
r[3]=0x00000000u;
goto P_0c0c158e;
P_0c0c158e: /* original e040, guest PC 0x0c0c158e */
if(!s->budget--) { s->failed_pc=0x0c0c158eu; return 0; }
r[0]=0x00000040u;
goto P_0c0c1590;
P_0c0c1590: /* original 622d, guest PC 0x0c0c1590 */
if(!s->budget--) { s->failed_pc=0x0c0c1590u; return 0; }
r[2]=r[2]&65535u;
goto P_0c0c1592;
P_0c0c1592: /* original 1f25, guest PC 0x0c0c1592 */
if(!s->budget--) { s->failed_pc=0x0c0c1592u; return 0; }
write(ram,r[15]+20,r[2],4);
goto P_0c0c1594;
P_0c0c1594: /* original 1f3f, guest PC 0x0c0c1594 */
if(!s->budget--) { s->failed_pc=0x0c0c1594u; return 0; }
write(ram,r[15]+60,r[3],4);
goto P_0c0c1596;
P_0c0c1596: /* original 0f46, guest PC 0x0c0c1596 */
if(!s->budget--) { s->failed_pc=0x0c0c1596u; return 0; }
write(ram,r[15]+r[0],r[4],4);
goto P_0c0c1598;
P_0c0c1598: /* original 64f3, guest PC 0x0c0c1598 */
if(!s->budget--) { s->failed_pc=0x0c0c1598u; return 0; }
r[4]=r[15];
goto P_0c0c159a;
P_0c0c159a: /* original d312, guest PC 0x0c0c159a */
if(!s->budget--) { s->failed_pc=0x0c0c159au; return 0; }
r[3]=read(ram,0x0c0c15e4u,4);
goto P_0c0c159c;
P_0c0c159c: /* original 430b, guest PC 0x0c0c159c */
if(!s->budget--) { s->failed_pc=0x0c0c159cu; return 0; }
target=r[3];
r[16]=0x0c0c15a0u;
r[4]+=0x00000014u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c15a0u) { target=s->pc; goto dispatch; }
goto P_0c0c15a0;
P_0c0c159e: /* original 7414, guest PC 0x0c0c159e */
if(!s->budget--) { s->failed_pc=0x0c0c159eu; return 0; }
r[4]+=0x00000014u;
goto P_0c0c15a0;
P_0c0c15a0: /* original 60c3, guest PC 0x0c0c15a0 */
if(!s->budget--) { s->failed_pc=0x0c0c15a0u; return 0; }
r[0]=r[12];
goto P_0c0c15a2;
P_0c0c15a2: /* original 7f48, guest PC 0x0c0c15a2 */
if(!s->budget--) { s->failed_pc=0x0c0c15a2u; return 0; }
r[15]+=0x00000048u;
goto P_0c0c15a4;
P_0c0c15a4: /* original 4f26, guest PC 0x0c0c15a4 */
if(!s->budget--) { s->failed_pc=0x0c0c15a4u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c15a6;
P_0c0c15a6: /* original fdf9, guest PC 0x0c0c15a6 */
if(!s->budget--) { s->failed_pc=0x0c0c15a6u; return 0; }
vf3_matrix_load(s,ram,13,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0c15a8;
P_0c0c15a8: /* original fef9, guest PC 0x0c0c15a8 */
if(!s->budget--) { s->failed_pc=0x0c0c15a8u; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0c15aa;
P_0c0c15aa: /* original fff9, guest PC 0x0c0c15aa */
if(!s->budget--) { s->failed_pc=0x0c0c15aau; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0c15ac;
P_0c0c15ac: /* original 6bf6, guest PC 0x0c0c15ac */
if(!s->budget--) { s->failed_pc=0x0c0c15acu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0c15ae;
P_0c0c15ae: /* original 6cf6, guest PC 0x0c0c15ae */
if(!s->budget--) { s->failed_pc=0x0c0c15aeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0c15b0;
P_0c0c15b0: /* original 6df6, guest PC 0x0c0c15b0 */
if(!s->budget--) { s->failed_pc=0x0c0c15b0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0c15b2;
P_0c0c15b2: /* original 000b, guest PC 0x0c0c15b2 */
if(!s->budget--) { s->failed_pc=0x0c0c15b2u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0c15b4: /* original 6ef6, guest PC 0x0c0c15b4 */
if(!s->budget--) { s->failed_pc=0x0c0c15b4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0c15b6u,s,ram);
P_0c0c1bd0: /* original 2fe6, guest PC 0x0c0c1bd0 */
if(!s->budget--) { s->failed_pc=0x0c0c1bd0u; return 0; }
r[15]-=4; write(ram,r[15],r[14],4);
goto P_0c0c1bd2;
P_0c0c1bd2: /* original e026, guest PC 0x0c0c1bd2 */
if(!s->budget--) { s->failed_pc=0x0c0c1bd2u; return 0; }
r[0]=0x00000026u;
goto P_0c0c1bd4;
P_0c0c1bd4: /* original 2fd6, guest PC 0x0c0c1bd4 */
if(!s->budget--) { s->failed_pc=0x0c0c1bd4u; return 0; }
r[15]-=4; write(ram,r[15],r[13],4);
goto P_0c0c1bd6;
P_0c0c1bd6: /* original 2fc6, guest PC 0x0c0c1bd6 */
if(!s->budget--) { s->failed_pc=0x0c0c1bd6u; return 0; }
r[15]-=4; write(ram,r[15],r[12],4);
goto P_0c0c1bd8;
P_0c0c1bd8: /* original 2fb6, guest PC 0x0c0c1bd8 */
if(!s->budget--) { s->failed_pc=0x0c0c1bd8u; return 0; }
r[15]-=4; write(ram,r[15],r[11],4);
goto P_0c0c1bda;
P_0c0c1bda: /* original 6b43, guest PC 0x0c0c1bda */
if(!s->budget--) { s->failed_pc=0x0c0c1bdau; return 0; }
r[11]=r[4];
goto P_0c0c1bdc;
P_0c0c1bdc: /* original 2fa6, guest PC 0x0c0c1bdc */
if(!s->budget--) { s->failed_pc=0x0c0c1bdcu; return 0; }
r[15]-=4; write(ram,r[15],r[10],4);
goto P_0c0c1bde;
P_0c0c1bde: /* original 2f96, guest PC 0x0c0c1bde */
if(!s->budget--) { s->failed_pc=0x0c0c1bdeu; return 0; }
r[15]-=4; write(ram,r[15],r[9],4);
goto P_0c0c1be0;
P_0c0c1be0: /* original 2f86, guest PC 0x0c0c1be0 */
if(!s->budget--) { s->failed_pc=0x0c0c1be0u; return 0; }
r[15]-=4; write(ram,r[15],r[8],4);
goto P_0c0c1be2;
P_0c0c1be2: /* original fffb, guest PC 0x0c0c1be2 */
if(!s->budget--) { s->failed_pc=0x0c0c1be2u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c0c1be4;
P_0c0c1be4: /* original ffeb, guest PC 0x0c0c1be4 */
if(!s->budget--) { s->failed_pc=0x0c0c1be4u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,14,r[15]);
goto P_0c0c1be6;
P_0c0c1be6: /* original ffdb, guest PC 0x0c0c1be6 */
if(!s->budget--) { s->failed_pc=0x0c0c1be6u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,13,r[15]);
goto P_0c0c1be8;
P_0c0c1be8: /* original ffcb, guest PC 0x0c0c1be8 */
if(!s->budget--) { s->failed_pc=0x0c0c1be8u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,12,r[15]);
goto P_0c0c1bea;
P_0c0c1bea: /* original 03bd, guest PC 0x0c0c1bea */
if(!s->budget--) { s->failed_pc=0x0c0c1beau; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[11]+r[0],2);
goto P_0c0c1bec;
P_0c0c1bec: /* original 4f22, guest PC 0x0c0c1bec */
if(!s->budget--) { s->failed_pc=0x0c0c1becu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0c1bee;
P_0c0c1bee: /* original 633d, guest PC 0x0c0c1bee */
if(!s->budget--) { s->failed_pc=0x0c0c1beeu; return 0; }
r[3]=r[3]&65535u;
goto P_0c0c1bf0;
P_0c0c1bf0: /* original d036, guest PC 0x0c0c1bf0 */
if(!s->budget--) { s->failed_pc=0x0c0c1bf0u; return 0; }
r[0]=read(ram,0x0c0c1cccu,4);
goto P_0c0c1bf2;
P_0c0c1bf2: /* original 4308, guest PC 0x0c0c1bf2 */
if(!s->budget--) { s->failed_pc=0x0c0c1bf2u; return 0; }
r[3]<<=2;
goto P_0c0c1bf4;
P_0c0c1bf4: /* original 5eb3, guest PC 0x0c0c1bf4 */
if(!s->budget--) { s->failed_pc=0x0c0c1bf4u; return 0; }
r[14]=read(ram,r[11]+12,4);
goto P_0c0c1bf6;
P_0c0c1bf6: /* original f336, guest PC 0x0c0c1bf6 */
if(!s->budget--) { s->failed_pc=0x0c0c1bf6u; return 0; }
vf3_matrix_load(s,ram,3,r[3]+r[0]);
goto P_0c0c1bf8;
P_0c0c1bf8: /* original e014, guest PC 0x0c0c1bf8 */
if(!s->budget--) { s->failed_pc=0x0c0c1bf8u; return 0; }
r[0]=0x00000014u;
goto P_0c0c1bfa;
P_0c0c1bfa: /* original 7fa4, guest PC 0x0c0c1bfa */
if(!s->budget--) { s->failed_pc=0x0c0c1bfau; return 0; }
r[15]+=0xffffffa4u;
goto P_0c0c1bfc;
P_0c0c1bfc: /* original ff37, guest PC 0x0c0c1bfc */
if(!s->budget--) { s->failed_pc=0x0c0c1bfcu; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0c1bfe;
P_0c0c1bfe: /* original 9061, guest PC 0x0c0c1bfe */
if(!s->budget--) { s->failed_pc=0x0c0c1bfeu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c1cc4u,2);
goto P_0c0c1c00;
P_0c0c1c00: /* original d433, guest PC 0x0c0c1c00 */
if(!s->budget--) { s->failed_pc=0x0c0c1c00u; return 0; }
r[4]=read(ram,0x0c0c1cd0u,4);
goto P_0c0c1c02;
P_0c0c1c02: /* original 034e, guest PC 0x0c0c1c02 */
if(!s->budget--) { s->failed_pc=0x0c0c1c02u; return 0; }
r[3]=read(ram,r[4]+r[0],4);
goto P_0c0c1c04;
P_0c0c1c04: /* original c733, guest PC 0x0c0c1c04 */
if(!s->budget--) { s->failed_pc=0x0c0c1c04u; return 0; }
r[0]=0x0c0c1cd4u;
goto P_0c0c1c06;
P_0c0c1c06: /* original f208, guest PC 0x0c0c1c06 */
if(!s->budget--) { s->failed_pc=0x0c0c1c06u; return 0; }
vf3_matrix_load(s,ram,2,r[0]);
goto P_0c0c1c08;
P_0c0c1c08: /* original 435a, guest PC 0x0c0c1c08 */
if(!s->budget--) { s->failed_pc=0x0c0c1c08u; return 0; }
r[53]=r[3];
goto P_0c0c1c0a;
P_0c0c1c0a: /* original f32d, guest PC 0x0c0c1c0a */
if(!s->budget--) { s->failed_pc=0x0c0c1c0au; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c0c1c0c;
P_0c0c1c0c: /* original f322, guest PC 0x0c0c1c0c */
if(!s->budget--) { s->failed_pc=0x0c0c1c0cu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[2],r[18],'*');
goto P_0c0c1c0e;
P_0c0c1c0e: /* original ff3a, guest PC 0x0c0c1c0e */
if(!s->budget--) { s->failed_pc=0x0c0c1c0eu; return 0; }
vf3_matrix_store(s,ram,3,r[15]);
goto P_0c0c1c10;
P_0c0c1c10: /* original 9059, guest PC 0x0c0c1c10 */
if(!s->budget--) { s->failed_pc=0x0c0c1c10u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c1cc6u,2);
goto P_0c0c1c12;
P_0c0c1c12: /* original ea00, guest PC 0x0c0c1c12 */
if(!s->budget--) { s->failed_pc=0x0c0c1c12u; return 0; }
r[10]=0x00000000u;
goto P_0c0c1c14;
P_0c0c1c14: /* original 084e, guest PC 0x0c0c1c14 */
if(!s->budget--) { s->failed_pc=0x0c0c1c14u; return 0; }
r[8]=read(ram,r[4]+r[0],4);
goto P_0c0c1c16;
P_0c0c1c16: /* original 3b80, guest PC 0x0c0c1c16 */
if(!s->budget--) { s->failed_pc=0x0c0c1c16u; return 0; }
r[17]=(r[17]&~1u)|((r[11]==r[8])!=0);
goto P_0c0c1c18;
P_0c0c1c18: /* original 8f03, guest PC 0x0c0c1c18 */
if(!s->budget--) { s->failed_pc=0x0c0c1c18u; return 0; }
cond=r[17]&1u;
r[13]=0x00000001u;
if(!cond) { goto P_0c0c1c22; }
goto P_0c0c1c1c;
P_0c0c1c1a: /* original ed01, guest PC 0x0c0c1c1a */
if(!s->budget--) { s->failed_pc=0x0c0c1c1au; return 0; }
r[13]=0x00000001u;
goto P_0c0c1c1c;
P_0c0c1c1c: /* original 9054, guest PC 0x0c0c1c1c */
if(!s->budget--) { s->failed_pc=0x0c0c1c1cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c1cc8u,2);
goto P_0c0c1c1e;
P_0c0c1c1e: /* original a002, guest PC 0x0c0c1c1e */
if(!s->budget--) { s->failed_pc=0x0c0c1c1eu; return 0; }
write(ram,r[4]+r[0],r[13],4);
goto P_0c0c1c26;
P_0c0c1c20: /* original 04d6, guest PC 0x0c0c1c20 */
if(!s->budget--) { s->failed_pc=0x0c0c1c20u; return 0; }
write(ram,r[4]+r[0],r[13],4);
goto P_0c0c1c22;
P_0c0c1c22: /* original 9051, guest PC 0x0c0c1c22 */
if(!s->budget--) { s->failed_pc=0x0c0c1c22u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c1cc8u,2);
goto P_0c0c1c24;
P_0c0c1c24: /* original 04a6, guest PC 0x0c0c1c24 */
if(!s->budget--) { s->failed_pc=0x0c0c1c24u; return 0; }
write(ram,r[4]+r[0],r[10],4);
goto P_0c0c1c26;
P_0c0c1c26: /* original c72c, guest PC 0x0c0c1c26 */
if(!s->budget--) { s->failed_pc=0x0c0c1c26u; return 0; }
r[0]=0x0c0c1cd8u;
goto P_0c0c1c28;
P_0c0c1c28: /* original f3f8, guest PC 0x0c0c1c28 */
if(!s->budget--) { s->failed_pc=0x0c0c1c28u; return 0; }
vf3_matrix_load(s,ram,3,r[15]);
goto P_0c0c1c2a;
P_0c0c1c2a: /* original f208, guest PC 0x0c0c1c2a */
if(!s->budget--) { s->failed_pc=0x0c0c1c2au; return 0; }
vf3_matrix_load(s,ram,2,r[0]);
goto P_0c0c1c2c;
P_0c0c1c2c: /* original e018, guest PC 0x0c0c1c2c */
if(!s->budget--) { s->failed_pc=0x0c0c1c2cu; return 0; }
r[0]=0x00000018u;
goto P_0c0c1c2e;
P_0c0c1c2e: /* original fd8d, guest PC 0x0c0c1c2e */
if(!s->budget--) { s->failed_pc=0x0c0c1c2eu; return 0; }
fr[13]=0;
goto P_0c0c1c30;
P_0c0c1c30: /* original 69a3, guest PC 0x0c0c1c30 */
if(!s->budget--) { s->failed_pc=0x0c0c1c30u; return 0; }
r[9]=r[10];
goto P_0c0c1c32;
P_0c0c1c32: /* original f231, guest PC 0x0c0c1c32 */
if(!s->budget--) { s->failed_pc=0x0c0c1c32u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'-');
goto P_0c0c1c34;
P_0c0c1c34: /* original ff27, guest PC 0x0c0c1c34 */
if(!s->budget--) { s->failed_pc=0x0c0c1c34u; return 0; }
vf3_matrix_store(s,ram,2,r[15]+r[0]);
goto P_0c0c1c36;
P_0c0c1c36: /* original 63e1, guest PC 0x0c0c1c36 */
if(!s->budget--) { s->failed_pc=0x0c0c1c36u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[14],2);
r[3]=tmp;
goto P_0c0c1c38;
P_0c0c1c38: /* original 633d, guest PC 0x0c0c1c38 */
if(!s->budget--) { s->failed_pc=0x0c0c1c38u; return 0; }
r[3]=r[3]&65535u;
goto P_0c0c1c3a;
P_0c0c1c3a: /* original 23d8, guest PC 0x0c0c1c3a */
if(!s->budget--) { s->failed_pc=0x0c0c1c3au; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[13])==0)!=0);
goto P_0c0c1c3c;
P_0c0c1c3c: /* original 8b01, guest PC 0x0c0c1c3c */
if(!s->budget--) { s->failed_pc=0x0c0c1c3cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c1c42; }
goto P_0c0c1c3e;
P_0c0c1c3e: /* original a08d, guest PC 0x0c0c1c3e */
if(!s->budget--) { s->failed_pc=0x0c0c1c3eu; return 0; }
goto P_0c0c1d5c;
P_0c0c1c40: /* original 0009, guest PC 0x0c0c1c40 */
if(!s->budget--) { s->failed_pc=0x0c0c1c40u; return 0; }
goto P_0c0c1c42;
P_0c0c1c42: /* original d326, guest PC 0x0c0c1c42 */
if(!s->budget--) { s->failed_pc=0x0c0c1c42u; return 0; }
r[3]=read(ram,0x0c0c1cdcu,4);
goto P_0c0c1c44;
P_0c0c1c44: /* original 85e1, guest PC 0x0c0c1c44 */
if(!s->budget--) { s->failed_pc=0x0c0c1c44u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+2,2);
goto P_0c0c1c46;
P_0c0c1c46: /* original 430b, guest PC 0x0c0c1c46 */
if(!s->budget--) { s->failed_pc=0x0c0c1c46u; return 0; }
target=r[3];
r[16]=0x0c0c1c4au;
r[4]=r[0];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c1c4au) { target=s->pc; goto dispatch; }
goto P_0c0c1c4a;
P_0c0c1c48: /* original 6403, guest PC 0x0c0c1c48 */
if(!s->budget--) { s->failed_pc=0x0c0c1c48u; return 0; }
r[4]=r[0];
goto P_0c0c1c4a;
P_0c0c1c4a: /* original 6403, guest PC 0x0c0c1c4a */
if(!s->budget--) { s->failed_pc=0x0c0c1c4au; return 0; }
r[4]=r[0];
goto P_0c0c1c4c;
P_0c0c1c4c: /* original e008, guest PC 0x0c0c1c4c */
if(!s->budget--) { s->failed_pc=0x0c0c1c4cu; return 0; }
r[0]=0x00000008u;
goto P_0c0c1c4e;
P_0c0c1c4e: /* original f346, guest PC 0x0c0c1c4e */
if(!s->budget--) { s->failed_pc=0x0c0c1c4eu; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c0c1c50;
P_0c0c1c50: /* original e004, guest PC 0x0c0c1c50 */
if(!s->budget--) { s->failed_pc=0x0c0c1c50u; return 0; }
r[0]=0x00000004u;
goto P_0c0c1c52;
P_0c0c1c52: /* original f448, guest PC 0x0c0c1c52 */
if(!s->budget--) { s->failed_pc=0x0c0c1c52u; return 0; }
vf3_matrix_load(s,ram,4,r[4]);
goto P_0c0c1c54;
P_0c0c1c54: /* original 6ca3, guest PC 0x0c0c1c54 */
if(!s->budget--) { s->failed_pc=0x0c0c1c54u; return 0; }
r[12]=r[10];
goto P_0c0c1c56;
P_0c0c1c56: /* original ff37, guest PC 0x0c0c1c56 */
if(!s->budget--) { s->failed_pc=0x0c0c1c56u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0c1c58;
P_0c0c1c58: /* original e010, guest PC 0x0c0c1c58 */
if(!s->budget--) { s->failed_pc=0x0c0c1c58u; return 0; }
r[0]=0x00000010u;
goto P_0c0c1c5a;
P_0c0c1c5a: /* original f346, guest PC 0x0c0c1c5a */
if(!s->budget--) { s->failed_pc=0x0c0c1c5au; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c0c1c5c;
P_0c0c1c5c: /* original e008, guest PC 0x0c0c1c5c */
if(!s->budget--) { s->failed_pc=0x0c0c1c5cu; return 0; }
r[0]=0x00000008u;
goto P_0c0c1c5e;
P_0c0c1c5e: /* original ff37, guest PC 0x0c0c1c5e */
if(!s->budget--) { s->failed_pc=0x0c0c1c5eu; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0c1c60;
P_0c0c1c60: /* original e014, guest PC 0x0c0c1c60 */
if(!s->budget--) { s->failed_pc=0x0c0c1c60u; return 0; }
r[0]=0x00000014u;
goto P_0c0c1c62;
P_0c0c1c62: /* original f346, guest PC 0x0c0c1c62 */
if(!s->budget--) { s->failed_pc=0x0c0c1c62u; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c0c1c64;
P_0c0c1c64: /* original e010, guest PC 0x0c0c1c64 */
if(!s->budget--) { s->failed_pc=0x0c0c1c64u; return 0; }
r[0]=0x00000010u;
goto P_0c0c1c66;
P_0c0c1c66: /* original ff37, guest PC 0x0c0c1c66 */
if(!s->budget--) { s->failed_pc=0x0c0c1c66u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0c1c68;
P_0c0c1c68: /* original e050, guest PC 0x0c0c1c68 */
if(!s->budget--) { s->failed_pc=0x0c0c1c68u; return 0; }
r[0]=0x00000050u;
goto P_0c0c1c6a;
P_0c0c1c6a: /* original 53e4, guest PC 0x0c0c1c6a */
if(!s->budget--) { s->failed_pc=0x0c0c1c6au; return 0; }
r[3]=read(ram,r[14]+16,4);
goto P_0c0c1c6c;
P_0c0c1c6c: /* original 1f3a, guest PC 0x0c0c1c6c */
if(!s->budget--) { s->failed_pc=0x0c0c1c6cu; return 0; }
write(ram,r[15]+40,r[3],4);
goto P_0c0c1c6e;
P_0c0c1c6e: /* original 52ee, guest PC 0x0c0c1c6e */
if(!s->budget--) { s->failed_pc=0x0c0c1c6eu; return 0; }
r[2]=read(ram,r[14]+56,4);
goto P_0c0c1c70;
P_0c0c1c70: /* original 0f26, guest PC 0x0c0c1c70 */
if(!s->budget--) { s->failed_pc=0x0c0c1c70u; return 0; }
write(ram,r[15]+r[0],r[2],4);
goto P_0c0c1c72;
P_0c0c1c72: /* original e054, guest PC 0x0c0c1c72 */
if(!s->budget--) { s->failed_pc=0x0c0c1c72u; return 0; }
r[0]=0x00000054u;
goto P_0c0c1c74;
P_0c0c1c74: /* original 53ef, guest PC 0x0c0c1c74 */
if(!s->budget--) { s->failed_pc=0x0c0c1c74u; return 0; }
r[3]=read(ram,r[14]+60,4);
goto P_0c0c1c76;
P_0c0c1c76: /* original 0f36, guest PC 0x0c0c1c76 */
if(!s->budget--) { s->failed_pc=0x0c0c1c76u; return 0; }
write(ram,r[15]+r[0],r[3],4);
goto P_0c0c1c78;
P_0c0c1c78: /* original e058, guest PC 0x0c0c1c78 */
if(!s->budget--) { s->failed_pc=0x0c0c1c78u; return 0; }
r[0]=0x00000058u;
goto P_0c0c1c7a;
P_0c0c1c7a: /* original f39d, guest PC 0x0c0c1c7a */
if(!s->budget--) { s->failed_pc=0x0c0c1c7au; return 0; }
fr[3]=0x3f800000u;
goto P_0c0c1c7c;
P_0c0c1c7c: /* original ff37, guest PC 0x0c0c1c7c */
if(!s->budget--) { s->failed_pc=0x0c0c1c7cu; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0c1c7e;
P_0c0c1c7e: /* original e01c, guest PC 0x0c0c1c7e */
if(!s->budget--) { s->failed_pc=0x0c0c1c7eu; return 0; }
r[0]=0x0000001cu;
goto P_0c0c1c80;
P_0c0c1c80: /* original f3f8, guest PC 0x0c0c1c80 */
if(!s->budget--) { s->failed_pc=0x0c0c1c80u; return 0; }
vf3_matrix_load(s,ram,3,r[15]);
goto P_0c0c1c82;
P_0c0c1c82: /* original fcdc, guest PC 0x0c0c1c82 */
if(!s->budget--) { s->failed_pc=0x0c0c1c82u; return 0; }
vf3_matrix_move(s,12,13);
goto P_0c0c1c84;
P_0c0c1c84: /* original f430, guest PC 0x0c0c1c84 */
if(!s->budget--) { s->failed_pc=0x0c0c1c84u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'+');
goto P_0c0c1c86;
P_0c0c1c86: /* original ff47, guest PC 0x0c0c1c86 */
if(!s->budget--) { s->failed_pc=0x0c0c1c86u; return 0; }
vf3_matrix_store(s,ram,4,r[15]+r[0]);
goto P_0c0c1c88;
P_0c0c1c88: /* original e004, guest PC 0x0c0c1c88 */
if(!s->budget--) { s->failed_pc=0x0c0c1c88u; return 0; }
r[0]=0x00000004u;
goto P_0c0c1c8a;
P_0c0c1c8a: /* original f2f6, guest PC 0x0c0c1c8a */
if(!s->budget--) { s->failed_pc=0x0c0c1c8au; return 0; }
vf3_matrix_load(s,ram,2,r[15]+r[0]);
goto P_0c0c1c8c;
P_0c0c1c8c: /* original e020, guest PC 0x0c0c1c8c */
if(!s->budget--) { s->failed_pc=0x0c0c1c8cu; return 0; }
r[0]=0x00000020u;
goto P_0c0c1c8e;
P_0c0c1c8e: /* original f231, guest PC 0x0c0c1c8e */
if(!s->budget--) { s->failed_pc=0x0c0c1c8eu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'-');
goto P_0c0c1c90;
P_0c0c1c90: /* original ff27, guest PC 0x0c0c1c90 */
if(!s->budget--) { s->failed_pc=0x0c0c1c90u; return 0; }
vf3_matrix_store(s,ram,2,r[15]+r[0]);
goto P_0c0c1c92;
P_0c0c1c92: /* original c713, guest PC 0x0c0c1c92 */
if(!s->budget--) { s->failed_pc=0x0c0c1c92u; return 0; }
r[0]=0x0c0c1ce0u;
goto P_0c0c1c94;
P_0c0c1c94: /* original f308, guest PC 0x0c0c1c94 */
if(!s->budget--) { s->failed_pc=0x0c0c1c94u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c0c1c96;
P_0c0c1c96: /* original e010, guest PC 0x0c0c1c96 */
if(!s->budget--) { s->failed_pc=0x0c0c1c96u; return 0; }
r[0]=0x00000010u;
goto P_0c0c1c98;
P_0c0c1c98: /* original f2f6, guest PC 0x0c0c1c98 */
if(!s->budget--) { s->failed_pc=0x0c0c1c98u; return 0; }
vf3_matrix_load(s,ram,2,r[15]+r[0]);
goto P_0c0c1c9a;
P_0c0c1c9a: /* original e00c, guest PC 0x0c0c1c9a */
if(!s->budget--) { s->failed_pc=0x0c0c1c9au; return 0; }
r[0]=0x0000000cu;
goto P_0c0c1c9c;
P_0c0c1c9c: /* original f232, guest PC 0x0c0c1c9c */
if(!s->budget--) { s->failed_pc=0x0c0c1c9cu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c0c1c9e;
P_0c0c1c9e: /* original a059, guest PC 0x0c0c1c9e */
if(!s->budget--) { s->failed_pc=0x0c0c1c9eu; return 0; }
vf3_matrix_store(s,ram,2,r[15]+r[0]);
goto P_0c0c1d54;
P_0c0c1ca0: /* original ff27, guest PC 0x0c0c1ca0 */
if(!s->budget--) { s->failed_pc=0x0c0c1ca0u; return 0; }
vf3_matrix_store(s,ram,2,r[15]+r[0]);
goto P_0c0c1ca2;
P_0c0c1ca2: /* original 3b80, guest PC 0x0c0c1ca2 */
if(!s->budget--) { s->failed_pc=0x0c0c1ca2u; return 0; }
r[17]=(r[17]&~1u)|((r[11]==r[8])!=0);
goto P_0c0c1ca4;
P_0c0c1ca4: /* original 64c3, guest PC 0x0c0c1ca4 */
if(!s->budget--) { s->failed_pc=0x0c0c1ca4u; return 0; }
r[4]=r[12];
goto P_0c0c1ca6;
P_0c0c1ca6: /* original 8f08, guest PC 0x0c0c1ca6 */
if(!s->budget--) { s->failed_pc=0x0c0c1ca6u; return 0; }
cond=r[17]&1u;
r[4]&=r[13];
if(!cond) { goto P_0c0c1cba; }
goto P_0c0c1caa;
P_0c0c1ca8: /* original 24d9, guest PC 0x0c0c1ca8 */
if(!s->budget--) { s->failed_pc=0x0c0c1ca8u; return 0; }
r[4]&=r[13];
goto P_0c0c1caa;
P_0c0c1caa: /* original 2448, guest PC 0x0c0c1caa */
if(!s->budget--) { s->failed_pc=0x0c0c1caau; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c0c1cac;
P_0c0c1cac: /* original 8901, guest PC 0x0c0c1cac */
if(!s->budget--) { s->failed_pc=0x0c0c1cacu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c1cb2; }
goto P_0c0c1cae;
P_0c0c1cae: /* original a002, guest PC 0x0c0c1cae */
if(!s->budget--) { s->failed_pc=0x0c0c1caeu; return 0; }
vf3_matrix_move(s,14,13);
goto P_0c0c1cb6;
P_0c0c1cb0: /* original fedc, guest PC 0x0c0c1cb0 */
if(!s->budget--) { s->failed_pc=0x0c0c1cb0u; return 0; }
vf3_matrix_move(s,14,13);
goto P_0c0c1cb2;
P_0c0c1cb2: /* original e018, guest PC 0x0c0c1cb2 */
if(!s->budget--) { s->failed_pc=0x0c0c1cb2u; return 0; }
r[0]=0x00000018u;
goto P_0c0c1cb4;
P_0c0c1cb4: /* original fef6, guest PC 0x0c0c1cb4 */
if(!s->budget--) { s->failed_pc=0x0c0c1cb4u; return 0; }
vf3_matrix_load(s,ram,14,r[15]+r[0]);
goto P_0c0c1cb6;
P_0c0c1cb6: /* original a018, guest PC 0x0c0c1cb6 */
if(!s->budget--) { s->failed_pc=0x0c0c1cb6u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
goto P_0c0c1cea;
P_0c0c1cb8: /* original fff8, guest PC 0x0c0c1cb8 */
if(!s->budget--) { s->failed_pc=0x0c0c1cb8u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
goto P_0c0c1cba;
P_0c0c1cba: /* original 2448, guest PC 0x0c0c1cba */
if(!s->budget--) { s->failed_pc=0x0c0c1cbau; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c0c1cbc;
P_0c0c1cbc: /* original 8912, guest PC 0x0c0c1cbc */
if(!s->budget--) { s->failed_pc=0x0c0c1cbcu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c1ce4; }
goto P_0c0c1cbe;
P_0c0c1cbe: /* original e01c, guest PC 0x0c0c1cbe */
if(!s->budget--) { s->failed_pc=0x0c0c1cbeu; return 0; }
r[0]=0x0000001cu;
goto P_0c0c1cc0;
P_0c0c1cc0: /* original a011, guest PC 0x0c0c1cc0 */
if(!s->budget--) { s->failed_pc=0x0c0c1cc0u; return 0; }
vf3_matrix_load(s,ram,14,r[15]+r[0]);
goto P_0c0c1ce6;
P_0c0c1cc2: /* original fef6, guest PC 0x0c0c1cc2 */
if(!s->budget--) { s->failed_pc=0x0c0c1cc2u; return 0; }
vf3_matrix_load(s,ram,14,r[15]+r[0]);
return vf3_matrix_family(0x0c0c1cc4u,s,ram);
P_0c0c1ce4: /* original fedc, guest PC 0x0c0c1ce4 */
if(!s->budget--) { s->failed_pc=0x0c0c1ce4u; return 0; }
vf3_matrix_move(s,14,13);
goto P_0c0c1ce6;
P_0c0c1ce6: /* original e020, guest PC 0x0c0c1ce6 */
if(!s->budget--) { s->failed_pc=0x0c0c1ce6u; return 0; }
r[0]=0x00000020u;
goto P_0c0c1ce8;
P_0c0c1ce8: /* original fff6, guest PC 0x0c0c1ce8 */
if(!s->budget--) { s->failed_pc=0x0c0c1ce8u; return 0; }
vf3_matrix_load(s,ram,15,r[15]+r[0]);
goto P_0c0c1cea;
P_0c0c1cea: /* original c743, guest PC 0x0c0c1cea */
if(!s->budget--) { s->failed_pc=0x0c0c1ceau; return 0; }
r[0]=0x0c0c1df8u;
goto P_0c0c1cec;
P_0c0c1cec: /* original f308, guest PC 0x0c0c1cec */
if(!s->budget--) { s->failed_pc=0x0c0c1cecu; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c0c1cee;
P_0c0c1cee: /* original f3e5, guest PC 0x0c0c1cee */
if(!s->budget--) { s->failed_pc=0x0c0c1ceeu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[14]))!=0);
goto P_0c0c1cf0;
P_0c0c1cf0: /* original 8b2d, guest PC 0x0c0c1cf0 */
if(!s->budget--) { s->failed_pc=0x0c0c1cf0u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c1d4e; }
goto P_0c0c1cf2;
P_0c0c1cf2: /* original f38d, guest PC 0x0c0c1cf2 */
if(!s->budget--) { s->failed_pc=0x0c0c1cf2u; return 0; }
fr[3]=0;
goto P_0c0c1cf4;
P_0c0c1cf4: /* original ff35, guest PC 0x0c0c1cf4 */
if(!s->budget--) { s->failed_pc=0x0c0c1cf4u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[15])>as_float(fr[3]))!=0);
goto P_0c0c1cf6;
P_0c0c1cf6: /* original 8b2a, guest PC 0x0c0c1cf6 */
if(!s->budget--) { s->failed_pc=0x0c0c1cf6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c1d4e; }
goto P_0c0c1cf8;
P_0c0c1cf8: /* original e004, guest PC 0x0c0c1cf8 */
if(!s->budget--) { s->failed_pc=0x0c0c1cf8u; return 0; }
r[0]=0x00000004u;
goto P_0c0c1cfa;
P_0c0c1cfa: /* original f3f6, guest PC 0x0c0c1cfa */
if(!s->budget--) { s->failed_pc=0x0c0c1cfau; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0c1cfc;
P_0c0c1cfc: /* original ff35, guest PC 0x0c0c1cfc */
if(!s->budget--) { s->failed_pc=0x0c0c1cfcu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[15])>as_float(fr[3]))!=0);
goto P_0c0c1cfe;
P_0c0c1cfe: /* original 8b01, guest PC 0x0c0c1cfe */
if(!s->budget--) { s->failed_pc=0x0c0c1cfeu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c1d04; }
goto P_0c0c1d00;
P_0c0c1d00: /* original e004, guest PC 0x0c0c1d00 */
if(!s->budget--) { s->failed_pc=0x0c0c1d00u; return 0; }
r[0]=0x00000004u;
goto P_0c0c1d02;
P_0c0c1d02: /* original fff6, guest PC 0x0c0c1d02 */
if(!s->budget--) { s->failed_pc=0x0c0c1d02u; return 0; }
vf3_matrix_load(s,ram,15,r[15]+r[0]);
goto P_0c0c1d04;
P_0c0c1d04: /* original e008, guest PC 0x0c0c1d04 */
if(!s->budget--) { s->failed_pc=0x0c0c1d04u; return 0; }
r[0]=0x00000008u;
goto P_0c0c1d06;
P_0c0c1d06: /* original f2cc, guest PC 0x0c0c1d06 */
if(!s->budget--) { s->failed_pc=0x0c0c1d06u; return 0; }
vf3_matrix_move(s,2,12);
goto P_0c0c1d08;
P_0c0c1d08: /* original f6f6, guest PC 0x0c0c1d08 */
if(!s->budget--) { s->failed_pc=0x0c0c1d08u; return 0; }
vf3_matrix_load(s,ram,6,r[15]+r[0]);
goto P_0c0c1d0a;
P_0c0c1d0a: /* original e014, guest PC 0x0c0c1d0a */
if(!s->budget--) { s->failed_pc=0x0c0c1d0au; return 0; }
r[0]=0x00000014u;
goto P_0c0c1d0c;
P_0c0c1d0c: /* original f8f6, guest PC 0x0c0c1d0c */
if(!s->budget--) { s->failed_pc=0x0c0c1d0cu; return 0; }
vf3_matrix_load(s,ram,8,r[15]+r[0]);
goto P_0c0c1d0e;
P_0c0c1d0e: /* original e00c, guest PC 0x0c0c1d0e */
if(!s->budget--) { s->failed_pc=0x0c0c1d0eu; return 0; }
r[0]=0x0000000cu;
goto P_0c0c1d10;
P_0c0c1d10: /* original f7f6, guest PC 0x0c0c1d10 */
if(!s->budget--) { s->failed_pc=0x0c0c1d10u; return 0; }
vf3_matrix_load(s,ram,7,r[15]+r[0]);
goto P_0c0c1d12;
P_0c0c1d12: /* original c73a, guest PC 0x0c0c1d12 */
if(!s->budget--) { s->failed_pc=0x0c0c1d12u; return 0; }
r[0]=0x0c0c1dfcu;
goto P_0c0c1d14;
P_0c0c1d14: /* original f308, guest PC 0x0c0c1d14 */
if(!s->budget--) { s->failed_pc=0x0c0c1d14u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c0c1d16;
P_0c0c1d16: /* original f6f2, guest PC 0x0c0c1d16 */
if(!s->budget--) { s->failed_pc=0x0c0c1d16u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[15],r[18],'*');
goto P_0c0c1d18;
P_0c0c1d18: /* original e024, guest PC 0x0c0c1d18 */
if(!s->budget--) { s->failed_pc=0x0c0c1d18u; return 0; }
r[0]=0x00000024u;
goto P_0c0c1d1a;
P_0c0c1d1a: /* original 64f3, guest PC 0x0c0c1d1a */
if(!s->budget--) { s->failed_pc=0x0c0c1d1au; return 0; }
r[4]=r[15];
goto P_0c0c1d1c;
P_0c0c1d1c: /* original f232, guest PC 0x0c0c1d1c */
if(!s->budget--) { s->failed_pc=0x0c0c1d1cu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c0c1d1e;
P_0c0c1d1e: /* original ff27, guest PC 0x0c0c1d1e */
if(!s->budget--) { s->failed_pc=0x0c0c1d1eu; return 0; }
vf3_matrix_store(s,ram,2,r[15]+r[0]);
goto P_0c0c1d20;
P_0c0c1d20: /* original d337, guest PC 0x0c0c1d20 */
if(!s->budget--) { s->failed_pc=0x0c0c1d20u; return 0; }
r[3]=read(ram,0x0c0c1e00u,4);
goto P_0c0c1d22;
P_0c0c1d22: /* original f4ec, guest PC 0x0c0c1d22 */
if(!s->budget--) { s->failed_pc=0x0c0c1d22u; return 0; }
vf3_matrix_move(s,4,14);
goto P_0c0c1d24;
P_0c0c1d24: /* original f52c, guest PC 0x0c0c1d24 */
if(!s->budget--) { s->failed_pc=0x0c0c1d24u; return 0; }
vf3_matrix_move(s,5,2);
goto P_0c0c1d26;
P_0c0c1d26: /* original 430b, guest PC 0x0c0c1d26 */
if(!s->budget--) { s->failed_pc=0x0c0c1d26u; return 0; }
target=r[3];
r[16]=0x0c0c1d2au;
r[4]+=0x00000028u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c1d2au) { target=s->pc; goto dispatch; }
goto P_0c0c1d2a;
P_0c0c1d28: /* original 7428, guest PC 0x0c0c1d28 */
if(!s->budget--) { s->failed_pc=0x0c0c1d28u; return 0; }
r[4]+=0x00000028u;
goto P_0c0c1d2a;
P_0c0c1d2a: /* original e010, guest PC 0x0c0c1d2a */
if(!s->budget--) { s->failed_pc=0x0c0c1d2au; return 0; }
r[0]=0x00000010u;
goto P_0c0c1d2c;
P_0c0c1d2c: /* original d336, guest PC 0x0c0c1d2c */
if(!s->budget--) { s->failed_pc=0x0c0c1d2cu; return 0; }
r[3]=read(ram,0x0c0c1e08u,4);
goto P_0c0c1d2e;
P_0c0c1d2e: /* original f9f6, guest PC 0x0c0c1d2e */
if(!s->budget--) { s->failed_pc=0x0c0c1d2eu; return 0; }
vf3_matrix_load(s,ram,9,r[15]+r[0]);
goto P_0c0c1d30;
P_0c0c1d30: /* original e008, guest PC 0x0c0c1d30 */
if(!s->budget--) { s->failed_pc=0x0c0c1d30u; return 0; }
r[0]=0x00000008u;
goto P_0c0c1d32;
P_0c0c1d32: /* original f8f6, guest PC 0x0c0c1d32 */
if(!s->budget--) { s->failed_pc=0x0c0c1d32u; return 0; }
vf3_matrix_load(s,ram,8,r[15]+r[0]);
goto P_0c0c1d34;
P_0c0c1d34: /* original c733, guest PC 0x0c0c1d34 */
if(!s->budget--) { s->failed_pc=0x0c0c1d34u; return 0; }
r[0]=0x0c0c1e04u;
goto P_0c0c1d36;
P_0c0c1d36: /* original f708, guest PC 0x0c0c1d36 */
if(!s->budget--) { s->failed_pc=0x0c0c1d36u; return 0; }
vf3_matrix_load(s,ram,7,r[0]);
goto P_0c0c1d38;
P_0c0c1d38: /* original e024, guest PC 0x0c0c1d38 */
if(!s->budget--) { s->failed_pc=0x0c0c1d38u; return 0; }
r[0]=0x00000024u;
goto P_0c0c1d3a;
P_0c0c1d3a: /* original f5f6, guest PC 0x0c0c1d3a */
if(!s->budget--) { s->failed_pc=0x0c0c1d3au; return 0; }
vf3_matrix_load(s,ram,5,r[15]+r[0]);
goto P_0c0c1d3c;
P_0c0c1d3c: /* original 64f3, guest PC 0x0c0c1d3c */
if(!s->budget--) { s->failed_pc=0x0c0c1d3cu; return 0; }
r[4]=r[15];
goto P_0c0c1d3e;
P_0c0c1d3e: /* original f6fc, guest PC 0x0c0c1d3e */
if(!s->budget--) { s->failed_pc=0x0c0c1d3eu; return 0; }
vf3_matrix_move(s,6,15);
goto P_0c0c1d40;
P_0c0c1d40: /* original f4ec, guest PC 0x0c0c1d40 */
if(!s->budget--) { s->failed_pc=0x0c0c1d40u; return 0; }
vf3_matrix_move(s,4,14);
goto P_0c0c1d42;
P_0c0c1d42: /* original 430b, guest PC 0x0c0c1d42 */
if(!s->budget--) { s->failed_pc=0x0c0c1d42u; return 0; }
target=r[3];
r[16]=0x0c0c1d46u;
r[4]+=0x00000028u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c1d46u) { target=s->pc; goto dispatch; }
goto P_0c0c1d46;
P_0c0c1d44: /* original 7428, guest PC 0x0c0c1d44 */
if(!s->budget--) { s->failed_pc=0x0c0c1d44u; return 0; }
r[4]+=0x00000028u;
goto P_0c0c1d46;
P_0c0c1d46: /* original d231, guest PC 0x0c0c1d46 */
if(!s->budget--) { s->failed_pc=0x0c0c1d46u; return 0; }
r[2]=read(ram,0x0c0c1e0cu,4);
goto P_0c0c1d48;
P_0c0c1d48: /* original 64f3, guest PC 0x0c0c1d48 */
if(!s->budget--) { s->failed_pc=0x0c0c1d48u; return 0; }
r[4]=r[15];
goto P_0c0c1d4a;
P_0c0c1d4a: /* original 420b, guest PC 0x0c0c1d4a */
if(!s->budget--) { s->failed_pc=0x0c0c1d4au; return 0; }
target=r[2];
r[16]=0x0c0c1d4eu;
r[4]+=0x00000028u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c1d4eu) { target=s->pc; goto dispatch; }
goto P_0c0c1d4e;
P_0c0c1d4c: /* original 7428, guest PC 0x0c0c1d4c */
if(!s->budget--) { s->failed_pc=0x0c0c1d4cu; return 0; }
r[4]+=0x00000028u;
goto P_0c0c1d4e;
P_0c0c1d4e: /* original f39d, guest PC 0x0c0c1d4e */
if(!s->budget--) { s->failed_pc=0x0c0c1d4eu; return 0; }
fr[3]=0x3f800000u;
goto P_0c0c1d50;
P_0c0c1d50: /* original fc30, guest PC 0x0c0c1d50 */
if(!s->budget--) { s->failed_pc=0x0c0c1d50u; return 0; }
fr[12]=vf3_fpu_binary(fr[12],fr[3],r[18],'+');
goto P_0c0c1d52;
P_0c0c1d52: /* original 7c01, guest PC 0x0c0c1d52 */
if(!s->budget--) { s->failed_pc=0x0c0c1d52u; return 0; }
r[12]+=0x00000001u;
goto P_0c0c1d54;
P_0c0c1d54: /* original c72e, guest PC 0x0c0c1d54 */
if(!s->budget--) { s->failed_pc=0x0c0c1d54u; return 0; }
r[0]=0x0c0c1e10u;
goto P_0c0c1d56;
P_0c0c1d56: /* original f208, guest PC 0x0c0c1d56 */
if(!s->budget--) { s->failed_pc=0x0c0c1d56u; return 0; }
vf3_matrix_load(s,ram,2,r[0]);
goto P_0c0c1d58;
P_0c0c1d58: /* original f2c5, guest PC 0x0c0c1d58 */
if(!s->budget--) { s->failed_pc=0x0c0c1d58u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[2])>as_float(fr[12]))!=0);
goto P_0c0c1d5a;
P_0c0c1d5a: /* original 89a2, guest PC 0x0c0c1d5a */
if(!s->budget--) { s->failed_pc=0x0c0c1d5au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c1ca2; }
goto P_0c0c1d5c;
P_0c0c1d5c: /* original e278, guest PC 0x0c0c1d5c */
if(!s->budget--) { s->failed_pc=0x0c0c1d5cu; return 0; }
r[2]=0x00000078u;
goto P_0c0c1d5e;
P_0c0c1d5e: /* original 7901, guest PC 0x0c0c1d5e */
if(!s->budget--) { s->failed_pc=0x0c0c1d5eu; return 0; }
r[9]+=0x00000001u;
goto P_0c0c1d60;
P_0c0c1d60: /* original 3922, guest PC 0x0c0c1d60 */
if(!s->budget--) { s->failed_pc=0x0c0c1d60u; return 0; }
r[17]=(r[17]&~1u)|((r[9]>=r[2])!=0);
goto P_0c0c1d62;
P_0c0c1d62: /* original 8d02, guest PC 0x0c0c1d62 */
if(!s->budget--) { s->failed_pc=0x0c0c1d62u; return 0; }
cond=r[17]&1u;
r[14]+=0x00000044u;
if(cond) { goto P_0c0c1d6a; }
goto P_0c0c1d66;
P_0c0c1d64: /* original 7e44, guest PC 0x0c0c1d64 */
if(!s->budget--) { s->failed_pc=0x0c0c1d64u; return 0; }
r[14]+=0x00000044u;
goto P_0c0c1d66;
P_0c0c1d66: /* original af66, guest PC 0x0c0c1d66 */
if(!s->budget--) { s->failed_pc=0x0c0c1d66u; return 0; }
goto P_0c0c1c36;
P_0c0c1d68: /* original 0009, guest PC 0x0c0c1d68 */
if(!s->budget--) { s->failed_pc=0x0c0c1d68u; return 0; }
goto P_0c0c1d6a;
P_0c0c1d6a: /* original 7f5c, guest PC 0x0c0c1d6a */
if(!s->budget--) { s->failed_pc=0x0c0c1d6au; return 0; }
r[15]+=0x0000005cu;
goto P_0c0c1d6c;
P_0c0c1d6c: /* original 4f26, guest PC 0x0c0c1d6c */
if(!s->budget--) { s->failed_pc=0x0c0c1d6cu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c1d6e;
P_0c0c1d6e: /* original fcf9, guest PC 0x0c0c1d6e */
if(!s->budget--) { s->failed_pc=0x0c0c1d6eu; return 0; }
vf3_matrix_load(s,ram,12,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0c1d70;
P_0c0c1d70: /* original fdf9, guest PC 0x0c0c1d70 */
if(!s->budget--) { s->failed_pc=0x0c0c1d70u; return 0; }
vf3_matrix_load(s,ram,13,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0c1d72;
P_0c0c1d72: /* original fef9, guest PC 0x0c0c1d72 */
if(!s->budget--) { s->failed_pc=0x0c0c1d72u; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0c1d74;
P_0c0c1d74: /* original fff9, guest PC 0x0c0c1d74 */
if(!s->budget--) { s->failed_pc=0x0c0c1d74u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0c1d76;
P_0c0c1d76: /* original 68f6, guest PC 0x0c0c1d76 */
if(!s->budget--) { s->failed_pc=0x0c0c1d76u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c0c1d78;
P_0c0c1d78: /* original 69f6, guest PC 0x0c0c1d78 */
if(!s->budget--) { s->failed_pc=0x0c0c1d78u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0c1d7a;
P_0c0c1d7a: /* original 6af6, guest PC 0x0c0c1d7a */
if(!s->budget--) { s->failed_pc=0x0c0c1d7au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0c1d7c;
P_0c0c1d7c: /* original 6bf6, guest PC 0x0c0c1d7c */
if(!s->budget--) { s->failed_pc=0x0c0c1d7cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0c1d7e;
P_0c0c1d7e: /* original 6cf6, guest PC 0x0c0c1d7e */
if(!s->budget--) { s->failed_pc=0x0c0c1d7eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0c1d80;
P_0c0c1d80: /* original 6df6, guest PC 0x0c0c1d80 */
if(!s->budget--) { s->failed_pc=0x0c0c1d80u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0c1d82;
P_0c0c1d82: /* original 000b, guest PC 0x0c0c1d82 */
if(!s->budget--) { s->failed_pc=0x0c0c1d82u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0c1d84: /* original 6ef6, guest PC 0x0c0c1d84 */
if(!s->budget--) { s->failed_pc=0x0c0c1d84u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0c1d86u,s,ram);
P_0c0c1e44: /* original 907f, guest PC 0x0c0c1e44 */
if(!s->budget--) { s->failed_pc=0x0c0c1e44u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c1f46u,2);
goto P_0c0c1e46;
P_0c0c1e46: /* original 05ce, guest PC 0x0c0c1e46 */
if(!s->budget--) { s->failed_pc=0x0c0c1e46u; return 0; }
r[5]=read(ram,r[12]+r[0],4);
goto P_0c0c1e48;
P_0c0c1e48: /* original 4511, guest PC 0x0c0c1e48 */
if(!s->budget--) { s->failed_pc=0x0c0c1e48u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[5]>=0)!=0);
goto P_0c0c1e4a;
P_0c0c1e4a: /* original 8b06, guest PC 0x0c0c1e4a */
if(!s->budget--) { s->failed_pc=0x0c0c1e4au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c1e5a; }
goto P_0c0c1e4c;
P_0c0c1e4c: /* original e210, guest PC 0x0c0c1e4c */
if(!s->budget--) { s->failed_pc=0x0c0c1e4cu; return 0; }
r[2]=0x00000010u;
goto P_0c0c1e4e;
P_0c0c1e4e: /* original 3527, guest PC 0x0c0c1e4e */
if(!s->budget--) { s->failed_pc=0x0c0c1e4eu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[5]>(int32_t)r[2])!=0);
goto P_0c0c1e50;
P_0c0c1e50: /* original 8903, guest PC 0x0c0c1e50 */
if(!s->budget--) { s->failed_pc=0x0c0c1e50u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c1e5a; }
goto P_0c0c1e52;
P_0c0c1e52: /* original bebd, guest PC 0x0c0c1e52 */
if(!s->budget--) { s->failed_pc=0x0c0c1e52u; return 0; }
target=0x0c0c1bd0u; r[16]=0x0c0c1e56u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c1e56u) { target=s->pc; goto dispatch; }
goto P_0c0c1e56;
P_0c0c1e54: /* original 64e3, guest PC 0x0c0c1e54 */
if(!s->budget--) { s->failed_pc=0x0c0c1e54u; return 0; }
r[4]=r[14];
goto P_0c0c1e56;
P_0c0c1e56: /* original a05e, guest PC 0x0c0c1e56 */
if(!s->budget--) { s->failed_pc=0x0c0c1e56u; return 0; }
goto P_0c0c1f16;
P_0c0c1e58: /* original 0009, guest PC 0x0c0c1e58 */
if(!s->budget--) { s->failed_pc=0x0c0c1e58u; return 0; }
goto P_0c0c1e5a;
P_0c0c1e5a: /* original 9075, guest PC 0x0c0c1e5a */
if(!s->budget--) { s->failed_pc=0x0c0c1e5au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c1f48u,2);
goto P_0c0c1e5c;
P_0c0c1e5c: /* original 02ce, guest PC 0x0c0c1e5c */
if(!s->budget--) { s->failed_pc=0x0c0c1e5cu; return 0; }
r[2]=read(ram,r[12]+r[0],4);
goto P_0c0c1e5e;
P_0c0c1e5e: /* original 2228, guest PC 0x0c0c1e5e */
if(!s->budget--) { s->failed_pc=0x0c0c1e5eu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c0c1e60;
P_0c0c1e60: /* original 8b09, guest PC 0x0c0c1e60 */
if(!s->budget--) { s->failed_pc=0x0c0c1e60u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c1e76; }
goto P_0c0c1e62;
P_0c0c1e62: /* original e022, guest PC 0x0c0c1e62 */
if(!s->budget--) { s->failed_pc=0x0c0c1e62u; return 0; }
r[0]=0x00000022u;
goto P_0c0c1e64;
P_0c0c1e64: /* original 02ed, guest PC 0x0c0c1e64 */
if(!s->budget--) { s->failed_pc=0x0c0c1e64u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0c1e66;
P_0c0c1e66: /* original 622d, guest PC 0x0c0c1e66 */
if(!s->budget--) { s->failed_pc=0x0c0c1e66u; return 0; }
r[2]=r[2]&65535u;
goto P_0c0c1e68;
P_0c0c1e68: /* original 2248, guest PC 0x0c0c1e68 */
if(!s->budget--) { s->failed_pc=0x0c0c1e68u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[4])==0)!=0);
goto P_0c0c1e6a;
P_0c0c1e6a: /* original 8954, guest PC 0x0c0c1e6a */
if(!s->budget--) { s->failed_pc=0x0c0c1e6au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c1f16; }
goto P_0c0c1e6c;
P_0c0c1e6c: /* original e022, guest PC 0x0c0c1e6c */
if(!s->budget--) { s->failed_pc=0x0c0c1e6cu; return 0; }
r[0]=0x00000022u;
goto P_0c0c1e6e;
P_0c0c1e6e: /* original 01ed, guest PC 0x0c0c1e6e */
if(!s->budget--) { s->failed_pc=0x0c0c1e6eu; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0c1e70;
P_0c0c1e70: /* original 611d, guest PC 0x0c0c1e70 */
if(!s->budget--) { s->failed_pc=0x0c0c1e70u; return 0; }
r[1]=r[1]&65535u;
goto P_0c0c1e72;
P_0c0c1e72: /* original 2148, guest PC 0x0c0c1e72 */
if(!s->budget--) { s->failed_pc=0x0c0c1e72u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[4])==0)!=0);
goto P_0c0c1e74;
P_0c0c1e74: /* original 894f, guest PC 0x0c0c1e74 */
if(!s->budget--) { s->failed_pc=0x0c0c1e74u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c1f16; }
goto P_0c0c1e76;
P_0c0c1e76: /* original 85ea, guest PC 0x0c0c1e76 */
if(!s->budget--) { s->failed_pc=0x0c0c1e76u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+20,2);
goto P_0c0c1e78;
P_0c0c1e78: /* original e800, guest PC 0x0c0c1e78 */
if(!s->budget--) { s->failed_pc=0x0c0c1e78u; return 0; }
r[8]=0x00000000u;
goto P_0c0c1e7a;
P_0c0c1e7a: /* original d235, guest PC 0x0c0c1e7a */
if(!s->budget--) { s->failed_pc=0x0c0c1e7au; return 0; }
r[2]=read(ram,0x0c0c1f50u,4);
goto P_0c0c1e7c;
P_0c0c1e7c: /* original ea78, guest PC 0x0c0c1e7c */
if(!s->budget--) { s->failed_pc=0x0c0c1e7cu; return 0; }
r[10]=0x00000078u;
goto P_0c0c1e7e;
P_0c0c1e7e: /* original 6303, guest PC 0x0c0c1e7e */
if(!s->budget--) { s->failed_pc=0x0c0c1e7eu; return 0; }
r[3]=r[0];
goto P_0c0c1e80;
P_0c0c1e80: /* original 435a, guest PC 0x0c0c1e80 */
if(!s->budget--) { s->failed_pc=0x0c0c1e80u; return 0; }
r[53]=r[3];
goto P_0c0c1e82;
P_0c0c1e82: /* original f228, guest PC 0x0c0c1e82 */
if(!s->budget--) { s->failed_pc=0x0c0c1e82u; return 0; }
vf3_matrix_load(s,ram,2,r[2]);
goto P_0c0c1e84;
P_0c0c1e84: /* original 6b83, guest PC 0x0c0c1e84 */
if(!s->budget--) { s->failed_pc=0x0c0c1e84u; return 0; }
r[11]=r[8];
goto P_0c0c1e86;
P_0c0c1e86: /* original 54e3, guest PC 0x0c0c1e86 */
if(!s->budget--) { s->failed_pc=0x0c0c1e86u; return 0; }
r[4]=read(ram,r[14]+12,4);
goto P_0c0c1e88;
P_0c0c1e88: /* original 3ba2, guest PC 0x0c0c1e88 */
if(!s->budget--) { s->failed_pc=0x0c0c1e88u; return 0; }
r[17]=(r[17]&~1u)|((r[11]>=r[10])!=0);
goto P_0c0c1e8a;
P_0c0c1e8a: /* original f32d, guest PC 0x0c0c1e8a */
if(!s->budget--) { s->failed_pc=0x0c0c1e8au; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c0c1e8c;
P_0c0c1e8c: /* original 6d43, guest PC 0x0c0c1e8c */
if(!s->budget--) { s->failed_pc=0x0c0c1e8cu; return 0; }
r[13]=r[4];
goto P_0c0c1e8e;
P_0c0c1e8e: /* original f322, guest PC 0x0c0c1e8e */
if(!s->budget--) { s->failed_pc=0x0c0c1e8eu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[2],r[18],'*');
goto P_0c0c1e90;
P_0c0c1e90: /* original ff3a, guest PC 0x0c0c1e90 */
if(!s->budget--) { s->failed_pc=0x0c0c1e90u; return 0; }
vf3_matrix_store(s,ram,3,r[15]);
goto P_0c0c1e92;
P_0c0c1e92: /* original 85eb, guest PC 0x0c0c1e92 */
if(!s->budget--) { s->failed_pc=0x0c0c1e92u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+22,2);
goto P_0c0c1e94;
P_0c0c1e94: /* original d12f, guest PC 0x0c0c1e94 */
if(!s->budget--) { s->failed_pc=0x0c0c1e94u; return 0; }
r[1]=read(ram,0x0c0c1f54u,4);
goto P_0c0c1e96;
P_0c0c1e96: /* original 6303, guest PC 0x0c0c1e96 */
if(!s->budget--) { s->failed_pc=0x0c0c1e96u; return 0; }
r[3]=r[0];
goto P_0c0c1e98;
P_0c0c1e98: /* original 435a, guest PC 0x0c0c1e98 */
if(!s->budget--) { s->failed_pc=0x0c0c1e98u; return 0; }
r[53]=r[3];
goto P_0c0c1e9a;
P_0c0c1e9a: /* original f218, guest PC 0x0c0c1e9a */
if(!s->budget--) { s->failed_pc=0x0c0c1e9au; return 0; }
vf3_matrix_load(s,ram,2,r[1]);
goto P_0c0c1e9c;
P_0c0c1e9c: /* original c72e, guest PC 0x0c0c1e9c */
if(!s->budget--) { s->failed_pc=0x0c0c1e9cu; return 0; }
r[0]=0x0c0c1f58u;
goto P_0c0c1e9e;
P_0c0c1e9e: /* original fcec, guest PC 0x0c0c1e9e */
if(!s->budget--) { s->failed_pc=0x0c0c1e9eu; return 0; }
vf3_matrix_move(s,12,14);
goto P_0c0c1ea0;
P_0c0c1ea0: /* original f32d, guest PC 0x0c0c1ea0 */
if(!s->budget--) { s->failed_pc=0x0c0c1ea0u; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c0c1ea2;
P_0c0c1ea2: /* original fd3c, guest PC 0x0c0c1ea2 */
if(!s->budget--) { s->failed_pc=0x0c0c1ea2u; return 0; }
vf3_matrix_move(s,13,3);
goto P_0c0c1ea4;
P_0c0c1ea4: /* original fd22, guest PC 0x0c0c1ea4 */
if(!s->budget--) { s->failed_pc=0x0c0c1ea4u; return 0; }
fr[13]=vf3_fpu_binary(fr[13],fr[2],r[18],'*');
goto P_0c0c1ea6;
P_0c0c1ea6: /* original f308, guest PC 0x0c0c1ea6 */
if(!s->budget--) { s->failed_pc=0x0c0c1ea6u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c0c1ea8;
P_0c0c1ea8: /* original 8d2e, guest PC 0x0c0c1ea8 */
if(!s->budget--) { s->failed_pc=0x0c0c1ea8u; return 0; }
cond=r[17]&1u;
fr[12]=vf3_fpu_binary(fr[12],fr[3],r[18],'+');
if(cond) { goto P_0c0c1f08; }
goto P_0c0c1eac;
P_0c0c1eaa: /* original fc30, guest PC 0x0c0c1eaa */
if(!s->budget--) { s->failed_pc=0x0c0c1eaau; return 0; }
fr[12]=vf3_fpu_binary(fr[12],fr[3],r[18],'+');
goto P_0c0c1eac;
P_0c0c1eac: /* original e910, guest PC 0x0c0c1eac */
if(!s->budget--) { s->failed_pc=0x0c0c1eacu; return 0; }
r[9]=0x00000010u;
goto P_0c0c1eae;
P_0c0c1eae: /* original 60d1, guest PC 0x0c0c1eae */
if(!s->budget--) { s->failed_pc=0x0c0c1eaeu; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[13],2);
r[0]=tmp;
goto P_0c0c1eb0;
P_0c0c1eb0: /* original 600d, guest PC 0x0c0c1eb0 */
if(!s->budget--) { s->failed_pc=0x0c0c1eb0u; return 0; }
r[0]=r[0]&65535u;
goto P_0c0c1eb2;
P_0c0c1eb2: /* original c801, guest PC 0x0c0c1eb2 */
if(!s->budget--) { s->failed_pc=0x0c0c1eb2u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&1u)==0)!=0);
goto P_0c0c1eb4;
P_0c0c1eb4: /* original 8924, guest PC 0x0c0c1eb4 */
if(!s->budget--) { s->failed_pc=0x0c0c1eb4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c1f00; }
goto P_0c0c1eb6;
P_0c0c1eb6: /* original 65d3, guest PC 0x0c0c1eb6 */
if(!s->budget--) { s->failed_pc=0x0c0c1eb6u; return 0; }
r[5]=r[13];
goto P_0c0c1eb8;
P_0c0c1eb8: /* original d228, guest PC 0x0c0c1eb8 */
if(!s->budget--) { s->failed_pc=0x0c0c1eb8u; return 0; }
r[2]=read(ram,0x0c0c1f5cu,4);
goto P_0c0c1eba;
P_0c0c1eba: /* original 64f3, guest PC 0x0c0c1eba */
if(!s->budget--) { s->failed_pc=0x0c0c1ebau; return 0; }
r[4]=r[15];
goto P_0c0c1ebc;
P_0c0c1ebc: /* original e634, guest PC 0x0c0c1ebc */
if(!s->budget--) { s->failed_pc=0x0c0c1ebcu; return 0; }
r[6]=0x00000034u;
goto P_0c0c1ebe;
P_0c0c1ebe: /* original 7510, guest PC 0x0c0c1ebe */
if(!s->budget--) { s->failed_pc=0x0c0c1ebeu; return 0; }
r[5]+=0x00000010u;
goto P_0c0c1ec0;
P_0c0c1ec0: /* original 420b, guest PC 0x0c0c1ec0 */
if(!s->budget--) { s->failed_pc=0x0c0c1ec0u; return 0; }
target=r[2];
r[16]=0x0c0c1ec4u;
r[4]+=0x00000004u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c1ec4u) { target=s->pc; goto dispatch; }
goto P_0c0c1ec4;
P_0c0c1ec2: /* original 7404, guest PC 0x0c0c1ec2 */
if(!s->budget--) { s->failed_pc=0x0c0c1ec2u; return 0; }
r[4]+=0x00000004u;
goto P_0c0c1ec4;
P_0c0c1ec4: /* original e008, guest PC 0x0c0c1ec4 */
if(!s->budget--) { s->failed_pc=0x0c0c1ec4u; return 0; }
r[0]=0x00000008u;
goto P_0c0c1ec6;
P_0c0c1ec6: /* original f3f8, guest PC 0x0c0c1ec6 */
if(!s->budget--) { s->failed_pc=0x0c0c1ec6u; return 0; }
vf3_matrix_load(s,ram,3,r[15]);
goto P_0c0c1ec8;
P_0c0c1ec8: /* original f2f6, guest PC 0x0c0c1ec8 */
if(!s->budget--) { s->failed_pc=0x0c0c1ec8u; return 0; }
vf3_matrix_load(s,ram,2,r[15]+r[0]);
goto P_0c0c1eca;
P_0c0c1eca: /* original e008, guest PC 0x0c0c1eca */
if(!s->budget--) { s->failed_pc=0x0c0c1ecau; return 0; }
r[0]=0x00000008u;
goto P_0c0c1ecc;
P_0c0c1ecc: /* original f231, guest PC 0x0c0c1ecc */
if(!s->budget--) { s->failed_pc=0x0c0c1eccu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'-');
goto P_0c0c1ece;
P_0c0c1ece: /* original ff27, guest PC 0x0c0c1ece */
if(!s->budget--) { s->failed_pc=0x0c0c1eceu; return 0; }
vf3_matrix_store(s,ram,2,r[15]+r[0]);
goto P_0c0c1ed0;
P_0c0c1ed0: /* original e00c, guest PC 0x0c0c1ed0 */
if(!s->budget--) { s->failed_pc=0x0c0c1ed0u; return 0; }
r[0]=0x0000000cu;
goto P_0c0c1ed2;
P_0c0c1ed2: /* original f2f6, guest PC 0x0c0c1ed2 */
if(!s->budget--) { s->failed_pc=0x0c0c1ed2u; return 0; }
vf3_matrix_load(s,ram,2,r[15]+r[0]);
goto P_0c0c1ed4;
P_0c0c1ed4: /* original e00c, guest PC 0x0c0c1ed4 */
if(!s->budget--) { s->failed_pc=0x0c0c1ed4u; return 0; }
r[0]=0x0000000cu;
goto P_0c0c1ed6;
P_0c0c1ed6: /* original f2d0, guest PC 0x0c0c1ed6 */
if(!s->budget--) { s->failed_pc=0x0c0c1ed6u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[13],r[18],'+');
goto P_0c0c1ed8;
P_0c0c1ed8: /* original ff27, guest PC 0x0c0c1ed8 */
if(!s->budget--) { s->failed_pc=0x0c0c1ed8u; return 0; }
vf3_matrix_store(s,ram,2,r[15]+r[0]);
goto P_0c0c1eda;
P_0c0c1eda: /* original e010, guest PC 0x0c0c1eda */
if(!s->budget--) { s->failed_pc=0x0c0c1edau; return 0; }
r[0]=0x00000010u;
goto P_0c0c1edc;
P_0c0c1edc: /* original ffe7, guest PC 0x0c0c1edc */
if(!s->budget--) { s->failed_pc=0x0c0c1edcu; return 0; }
vf3_matrix_store(s,ram,14,r[15]+r[0]);
goto P_0c0c1ede;
P_0c0c1ede: /* original 63d1, guest PC 0x0c0c1ede */
if(!s->budget--) { s->failed_pc=0x0c0c1edeu; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[13],2);
r[3]=tmp;
goto P_0c0c1ee0;
P_0c0c1ee0: /* original 633d, guest PC 0x0c0c1ee0 */
if(!s->budget--) { s->failed_pc=0x0c0c1ee0u; return 0; }
r[3]=r[3]&65535u;
goto P_0c0c1ee2;
P_0c0c1ee2: /* original 2398, guest PC 0x0c0c1ee2 */
if(!s->budget--) { s->failed_pc=0x0c0c1ee2u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[9])==0)!=0);
goto P_0c0c1ee4;
P_0c0c1ee4: /* original 8901, guest PC 0x0c0c1ee4 */
if(!s->budget--) { s->failed_pc=0x0c0c1ee4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c1eea; }
goto P_0c0c1ee6;
P_0c0c1ee6: /* original e010, guest PC 0x0c0c1ee6 */
if(!s->budget--) { s->failed_pc=0x0c0c1ee6u; return 0; }
r[0]=0x00000010u;
goto P_0c0c1ee8;
P_0c0c1ee8: /* original ffc7, guest PC 0x0c0c1ee8 */
if(!s->budget--) { s->failed_pc=0x0c0c1ee8u; return 0; }
vf3_matrix_store(s,ram,12,r[15]+r[0]);
goto P_0c0c1eea;
P_0c0c1eea: /* original 60d1, guest PC 0x0c0c1eea */
if(!s->budget--) { s->failed_pc=0x0c0c1eeau; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[13],2);
r[0]=tmp;
goto P_0c0c1eec;
P_0c0c1eec: /* original 600d, guest PC 0x0c0c1eec */
if(!s->budget--) { s->failed_pc=0x0c0c1eecu; return 0; }
r[0]=r[0]&65535u;
goto P_0c0c1eee;
P_0c0c1eee: /* original c820, guest PC 0x0c0c1eee */
if(!s->budget--) { s->failed_pc=0x0c0c1eeeu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&32u)==0)!=0);
goto P_0c0c1ef0;
P_0c0c1ef0: /* original 8b01, guest PC 0x0c0c1ef0 */
if(!s->budget--) { s->failed_pc=0x0c0c1ef0u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c1ef6; }
goto P_0c0c1ef2;
P_0c0c1ef2: /* original e034, guest PC 0x0c0c1ef2 */
if(!s->budget--) { s->failed_pc=0x0c0c1ef2u; return 0; }
r[0]=0x00000034u;
goto P_0c0c1ef4;
P_0c0c1ef4: /* original fff7, guest PC 0x0c0c1ef4 */
if(!s->budget--) { s->failed_pc=0x0c0c1ef4u; return 0; }
vf3_matrix_store(s,ram,15,r[15]+r[0]);
goto P_0c0c1ef6;
P_0c0c1ef6: /* original d31a, guest PC 0x0c0c1ef6 */
if(!s->budget--) { s->failed_pc=0x0c0c1ef6u; return 0; }
r[3]=read(ram,0x0c0c1f60u,4);
goto P_0c0c1ef8;
P_0c0c1ef8: /* original 64f3, guest PC 0x0c0c1ef8 */
if(!s->budget--) { s->failed_pc=0x0c0c1ef8u; return 0; }
r[4]=r[15];
goto P_0c0c1efa;
P_0c0c1efa: /* original 430b, guest PC 0x0c0c1efa */
if(!s->budget--) { s->failed_pc=0x0c0c1efau; return 0; }
target=r[3];
r[16]=0x0c0c1efeu;
r[4]+=0x00000004u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c1efeu) { target=s->pc; goto dispatch; }
goto P_0c0c1efe;
P_0c0c1efc: /* original 7404, guest PC 0x0c0c1efc */
if(!s->budget--) { s->failed_pc=0x0c0c1efcu; return 0; }
r[4]+=0x00000004u;
goto P_0c0c1efe;
P_0c0c1efe: /* original 7801, guest PC 0x0c0c1efe */
if(!s->budget--) { s->failed_pc=0x0c0c1efeu; return 0; }
r[8]+=0x00000001u;
goto P_0c0c1f00;
P_0c0c1f00: /* original 7b01, guest PC 0x0c0c1f00 */
if(!s->budget--) { s->failed_pc=0x0c0c1f00u; return 0; }
r[11]+=0x00000001u;
goto P_0c0c1f02;
P_0c0c1f02: /* original 3ba2, guest PC 0x0c0c1f02 */
if(!s->budget--) { s->failed_pc=0x0c0c1f02u; return 0; }
r[17]=(r[17]&~1u)|((r[11]>=r[10])!=0);
goto P_0c0c1f04;
P_0c0c1f04: /* original 8fd3, guest PC 0x0c0c1f04 */
if(!s->budget--) { s->failed_pc=0x0c0c1f04u; return 0; }
cond=r[17]&1u;
r[13]+=0x00000044u;
if(!cond) { goto P_0c0c1eae; }
goto P_0c0c1f08;
P_0c0c1f06: /* original 7d44, guest PC 0x0c0c1f06 */
if(!s->budget--) { s->failed_pc=0x0c0c1f06u; return 0; }
r[13]+=0x00000044u;
goto P_0c0c1f08;
P_0c0c1f08: /* original e028, guest PC 0x0c0c1f08 */
if(!s->budget--) { s->failed_pc=0x0c0c1f08u; return 0; }
r[0]=0x00000028u;
goto P_0c0c1f0a;
P_0c0c1f0a: /* original 0e85, guest PC 0x0c0c1f0a */
if(!s->budget--) { s->failed_pc=0x0c0c1f0au; return 0; }
write(ram,r[14]+r[0],r[8],2);
goto P_0c0c1f0c;
P_0c0c1f0c: /* original e022, guest PC 0x0c0c1f0c */
if(!s->budget--) { s->failed_pc=0x0c0c1f0cu; return 0; }
r[0]=0x00000022u;
goto P_0c0c1f0e;
P_0c0c1f0e: /* original 02ed, guest PC 0x0c0c1f0e */
if(!s->budget--) { s->failed_pc=0x0c0c1f0eu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0c1f10;
P_0c0c1f10: /* original d314, guest PC 0x0c0c1f10 */
if(!s->budget--) { s->failed_pc=0x0c0c1f10u; return 0; }
r[3]=read(ram,0x0c0c1f64u,4);
goto P_0c0c1f12;
P_0c0c1f12: /* original 2239, guest PC 0x0c0c1f12 */
if(!s->budget--) { s->failed_pc=0x0c0c1f12u; return 0; }
r[2]&=r[3];
goto P_0c0c1f14;
P_0c0c1f14: /* original 0e25, guest PC 0x0c0c1f14 */
if(!s->budget--) { s->failed_pc=0x0c0c1f14u; return 0; }
write(ram,r[14]+r[0],r[2],2);
goto P_0c0c1f16;
P_0c0c1f16: /* original 7f38, guest PC 0x0c0c1f16 */
if(!s->budget--) { s->failed_pc=0x0c0c1f16u; return 0; }
r[15]+=0x00000038u;
goto P_0c0c1f18;
P_0c0c1f18: /* original 4f26, guest PC 0x0c0c1f18 */
if(!s->budget--) { s->failed_pc=0x0c0c1f18u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c1f1a;
P_0c0c1f1a: /* original fcf9, guest PC 0x0c0c1f1a */
if(!s->budget--) { s->failed_pc=0x0c0c1f1au; return 0; }
vf3_matrix_load(s,ram,12,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0c1f1c;
P_0c0c1f1c: /* original fdf9, guest PC 0x0c0c1f1c */
if(!s->budget--) { s->failed_pc=0x0c0c1f1cu; return 0; }
vf3_matrix_load(s,ram,13,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0c1f1e;
P_0c0c1f1e: /* original fef9, guest PC 0x0c0c1f1e */
if(!s->budget--) { s->failed_pc=0x0c0c1f1eu; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0c1f20;
P_0c0c1f20: /* original fff9, guest PC 0x0c0c1f20 */
if(!s->budget--) { s->failed_pc=0x0c0c1f20u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0c1f22;
P_0c0c1f22: /* original 68f6, guest PC 0x0c0c1f22 */
if(!s->budget--) { s->failed_pc=0x0c0c1f22u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c0c1f24;
P_0c0c1f24: /* original 69f6, guest PC 0x0c0c1f24 */
if(!s->budget--) { s->failed_pc=0x0c0c1f24u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0c1f26;
P_0c0c1f26: /* original 6af6, guest PC 0x0c0c1f26 */
if(!s->budget--) { s->failed_pc=0x0c0c1f26u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0c1f28;
P_0c0c1f28: /* original 6bf6, guest PC 0x0c0c1f28 */
if(!s->budget--) { s->failed_pc=0x0c0c1f28u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0c1f2a;
P_0c0c1f2a: /* original 6cf6, guest PC 0x0c0c1f2a */
if(!s->budget--) { s->failed_pc=0x0c0c1f2au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0c1f2c;
P_0c0c1f2c: /* original 6df6, guest PC 0x0c0c1f2c */
if(!s->budget--) { s->failed_pc=0x0c0c1f2cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0c1f2e;
P_0c0c1f2e: /* original 000b, guest PC 0x0c0c1f2e */
if(!s->budget--) { s->failed_pc=0x0c0c1f2eu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0c1f30: /* original 6ef6, guest PC 0x0c0c1f30 */
if(!s->budget--) { s->failed_pc=0x0c0c1f30u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0c1f32u,s,ram);
P_0c0c9ce6: /* original 901d, guest PC 0x0c0c9ce6 */
if(!s->budget--) { s->failed_pc=0x0c0c9ce6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c9d24u,2);
goto P_0c0c9ce8;
P_0c0c9ce8: /* original d412, guest PC 0x0c0c9ce8 */
if(!s->budget--) { s->failed_pc=0x0c0c9ce8u; return 0; }
r[4]=read(ram,0x0c0c9d34u,4);
goto P_0c0c9cea;
P_0c0c9cea: /* original d316, guest PC 0x0c0c9cea */
if(!s->budget--) { s->failed_pc=0x0c0c9ceau; return 0; }
r[3]=read(ram,0x0c0c9d44u,4);
goto P_0c0c9cec;
P_0c0c9cec: /* original 054e, guest PC 0x0c0c9cec */
if(!s->budget--) { s->failed_pc=0x0c0c9cecu; return 0; }
r[5]=read(ram,r[4]+r[0],4);
goto P_0c0c9cee;
P_0c0c9cee: /* original 4f12, guest PC 0x0c0c9cee */
if(!s->budget--) { s->failed_pc=0x0c0c9ceeu; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c0c9cf0;
P_0c0c9cf0: /* original 0537, guest PC 0x0c0c9cf0 */
if(!s->budget--) { s->failed_pc=0x0c0c9cf0u; return 0; }
r[19]=r[5]*r[3];
goto P_0c0c9cf2;
P_0c0c9cf2: /* original 051a, guest PC 0x0c0c9cf2 */
if(!s->budget--) { s->failed_pc=0x0c0c9cf2u; return 0; }
r[5]=r[19];
goto P_0c0c9cf4;
P_0c0c9cf4: /* original 7501, guest PC 0x0c0c9cf4 */
if(!s->budget--) { s->failed_pc=0x0c0c9cf4u; return 0; }
r[5]+=0x00000001u;
goto P_0c0c9cf6;
P_0c0c9cf6: /* original 0456, guest PC 0x0c0c9cf6 */
if(!s->budget--) { s->failed_pc=0x0c0c9cf6u; return 0; }
write(ram,r[4]+r[0],r[5],4);
goto P_0c0c9cf8;
P_0c0c9cf8: /* original 4529, guest PC 0x0c0c9cf8 */
if(!s->budget--) { s->failed_pc=0x0c0c9cf8u; return 0; }
r[5]>>=16;
goto P_0c0c9cfa;
P_0c0c9cfa: /* original 9412, guest PC 0x0c0c9cfa */
if(!s->budget--) { s->failed_pc=0x0c0c9cfau; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c9d22u,2);
goto P_0c0c9cfc;
P_0c0c9cfc: /* original 2459, guest PC 0x0c0c9cfc */
if(!s->budget--) { s->failed_pc=0x0c0c9cfcu; return 0; }
r[4]&=r[5];
goto P_0c0c9cfe;
P_0c0c9cfe: /* original 6043, guest PC 0x0c0c9cfe */
if(!s->budget--) { s->failed_pc=0x0c0c9cfeu; return 0; }
r[0]=r[4];
goto P_0c0c9d00;
P_0c0c9d00: /* original 000b, guest PC 0x0c0c9d00 */
if(!s->budget--) { s->failed_pc=0x0c0c9d00u; return 0; }
target=r[16];
r[19]=read(ram,r[15],4); r[15]+=4;
s->pc=target; return ram->oob==0;
P_0c0c9d02: /* original 4f16, guest PC 0x0c0c9d02 */
if(!s->budget--) { s->failed_pc=0x0c0c9d02u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
return vf3_matrix_family(0x0c0c9d04u,s,ram);
unsupported: s->failed_pc=target; return 0;
}
