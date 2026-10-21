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
int vf3_c98_adapter(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u;
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c010368u: goto P_0c010368;
case 0x0c01036au: goto P_0c01036a;
case 0x0c01036cu: goto P_0c01036c;
case 0x0c01036eu: goto P_0c01036e;
case 0x0c010370u: goto P_0c010370;
case 0x0c010372u: goto P_0c010372;
case 0x0c010374u: goto P_0c010374;
case 0x0c010376u: goto P_0c010376;
case 0x0c010378u: goto P_0c010378;
case 0x0c01037au: goto P_0c01037a;
case 0x0c01037cu: goto P_0c01037c;
case 0x0c01037eu: goto P_0c01037e;
case 0x0c010380u: goto P_0c010380;
case 0x0c010382u: goto P_0c010382;
case 0x0c010384u: goto P_0c010384;
case 0x0c010386u: goto P_0c010386;
case 0x0c010388u: goto P_0c010388;
case 0x0c01038au: goto P_0c01038a;
case 0x0c01038cu: goto P_0c01038c;
case 0x0c01038eu: goto P_0c01038e;
case 0x0c010390u: goto P_0c010390;
case 0x0c010392u: goto P_0c010392;
case 0x0c010394u: goto P_0c010394;
case 0x0c010396u: goto P_0c010396;
case 0x0c010398u: goto P_0c010398;
case 0x0c01039au: goto P_0c01039a;
case 0x0c01039cu: goto P_0c01039c;
case 0x0c01039eu: goto P_0c01039e;
case 0x0c0103a0u: goto P_0c0103a0;
case 0x0c0103a2u: goto P_0c0103a2;
case 0x0c0103a4u: goto P_0c0103a4;
case 0x0c0103a6u: goto P_0c0103a6;
case 0x0c0103a8u: goto P_0c0103a8;
case 0x0c0109f6u: goto P_0c0109f6;
case 0x0c0109f8u: goto P_0c0109f8;
case 0x0c0109fau: goto P_0c0109fa;
case 0x0c0109fcu: goto P_0c0109fc;
case 0x0c0109feu: goto P_0c0109fe;
case 0x0c010a00u: goto P_0c010a00;
case 0x0c010a02u: goto P_0c010a02;
case 0x0c010a04u: goto P_0c010a04;
case 0x0c010a06u: goto P_0c010a06;
case 0x0c010a08u: goto P_0c010a08;
case 0x0c010a0au: goto P_0c010a0a;
case 0x0c010a0cu: goto P_0c010a0c;
case 0x0c010a0eu: goto P_0c010a0e;
case 0x0c010c2eu: goto P_0c010c2e;
case 0x0c010c30u: goto P_0c010c30;
case 0x0c010c32u: goto P_0c010c32;
case 0x0c010c34u: goto P_0c010c34;
case 0x0c010c36u: goto P_0c010c36;
case 0x0c010c38u: goto P_0c010c38;
case 0x0c010c3au: goto P_0c010c3a;
case 0x0c010c3cu: goto P_0c010c3c;
case 0x0c010c3eu: goto P_0c010c3e;
case 0x0c010c40u: goto P_0c010c40;
case 0x0c010c42u: goto P_0c010c42;
case 0x0c010c44u: goto P_0c010c44;
case 0x0c010c46u: goto P_0c010c46;
case 0x0c010c48u: goto P_0c010c48;
case 0x0c010c4au: goto P_0c010c4a;
case 0x0c010c4cu: goto P_0c010c4c;
case 0x0c010c4eu: goto P_0c010c4e;
case 0x0c010c50u: goto P_0c010c50;
case 0x0c010c52u: goto P_0c010c52;
case 0x0c010c54u: goto P_0c010c54;
case 0x0c010c56u: goto P_0c010c56;
case 0x0c010c58u: goto P_0c010c58;
case 0x0c010c5au: goto P_0c010c5a;
case 0x0c010c5cu: goto P_0c010c5c;
case 0x0c010c5eu: goto P_0c010c5e;
case 0x0c010c60u: goto P_0c010c60;
case 0x0c010c62u: goto P_0c010c62;
case 0x0c010c64u: goto P_0c010c64;
case 0x0c010c66u: goto P_0c010c66;
case 0x0c010c68u: goto P_0c010c68;
case 0x0c010c6au: goto P_0c010c6a;
case 0x0c010c6cu: goto P_0c010c6c;
case 0x0c010c6eu: goto P_0c010c6e;
case 0x0c010c70u: goto P_0c010c70;
case 0x0c010c72u: goto P_0c010c72;
case 0x0c010c74u: goto P_0c010c74;
case 0x0c010c76u: goto P_0c010c76;
case 0x0c010c78u: goto P_0c010c78;
case 0x0c010c7au: goto P_0c010c7a;
case 0x0c010c7cu: goto P_0c010c7c;
case 0x0c010c7eu: goto P_0c010c7e;
case 0x0c010c80u: goto P_0c010c80;
case 0x0c010c82u: goto P_0c010c82;
case 0x0c010c84u: goto P_0c010c84;
case 0x0c010c86u: goto P_0c010c86;
case 0x0c010c88u: goto P_0c010c88;
case 0x0c010c8au: goto P_0c010c8a;
case 0x0c010c8cu: goto P_0c010c8c;
case 0x0c010c8eu: goto P_0c010c8e;
case 0x0c010c90u: goto P_0c010c90;
case 0x0c010c92u: goto P_0c010c92;
case 0x0c010c94u: goto P_0c010c94;
case 0x0c010c96u: goto P_0c010c96;
case 0x0c010c98u: goto P_0c010c98;
case 0x0c010c9au: goto P_0c010c9a;
case 0x0c010c9cu: goto P_0c010c9c;
case 0x0c010c9eu: goto P_0c010c9e;
case 0x0c010ca0u: goto P_0c010ca0;
case 0x0c010ca2u: goto P_0c010ca2;
case 0x0c010ca4u: goto P_0c010ca4;
case 0x0c010ca6u: goto P_0c010ca6;
case 0x0c010ca8u: goto P_0c010ca8;
case 0x0c010caau: goto P_0c010caa;
case 0x0c010cacu: goto P_0c010cac;
case 0x0c010caeu: goto P_0c010cae;
case 0x0c010cb0u: goto P_0c010cb0;
case 0x0c010cb2u: goto P_0c010cb2;
case 0x0c010cb4u: goto P_0c010cb4;
case 0x0c010cb6u: goto P_0c010cb6;
case 0x0c010cb8u: goto P_0c010cb8;
case 0x0c010cbau: goto P_0c010cba;
case 0x0c010cbcu: goto P_0c010cbc;
case 0x0c010cbeu: goto P_0c010cbe;
case 0x0c010cc0u: goto P_0c010cc0;
case 0x0c010cc2u: goto P_0c010cc2;
case 0x0c010cc4u: goto P_0c010cc4;
case 0x0c010cc6u: goto P_0c010cc6;
case 0x0c010cc8u: goto P_0c010cc8;
case 0x0c010ccau: goto P_0c010cca;
case 0x0c010cccu: goto P_0c010ccc;
case 0x0c010cceu: goto P_0c010cce;
case 0x0c010cd0u: goto P_0c010cd0;
case 0x0c010cd2u: goto P_0c010cd2;
case 0x0c010cd4u: goto P_0c010cd4;
case 0x0c010cd6u: goto P_0c010cd6;
case 0x0c010cd8u: goto P_0c010cd8;
case 0x0c010cdau: goto P_0c010cda;
case 0x0c010cdcu: goto P_0c010cdc;
case 0x0c010cdeu: goto P_0c010cde;
case 0x0c010ce0u: goto P_0c010ce0;
case 0x0c010ce2u: goto P_0c010ce2;
case 0x0c010ce4u: goto P_0c010ce4;
case 0x0c010f42u: goto P_0c010f42;
case 0x0c010f44u: goto P_0c010f44;
case 0x0c010f46u: goto P_0c010f46;
case 0x0c010f48u: goto P_0c010f48;
case 0x0c010f4au: goto P_0c010f4a;
case 0x0c010f4cu: goto P_0c010f4c;
case 0x0c010f4eu: goto P_0c010f4e;
case 0x0c010f50u: goto P_0c010f50;
case 0x0c010f52u: goto P_0c010f52;
case 0x0c010f54u: goto P_0c010f54;
case 0x0c010f56u: goto P_0c010f56;
case 0x0c010f58u: goto P_0c010f58;
case 0x0c010f5au: goto P_0c010f5a;
case 0x0c010f5cu: goto P_0c010f5c;
case 0x0c010f5eu: goto P_0c010f5e;
case 0x0c010f60u: goto P_0c010f60;
case 0x0c010f62u: goto P_0c010f62;
case 0x0c010f64u: goto P_0c010f64;
case 0x0c010f66u: goto P_0c010f66;
case 0x0c010f68u: goto P_0c010f68;
case 0x0c010f6au: goto P_0c010f6a;
case 0x0c010f6cu: goto P_0c010f6c;
case 0x0c010f6eu: goto P_0c010f6e;
case 0x0c010f70u: goto P_0c010f70;
case 0x0c010f72u: goto P_0c010f72;
case 0x0c010f74u: goto P_0c010f74;
case 0x0c010f76u: goto P_0c010f76;
case 0x0c010f78u: goto P_0c010f78;
case 0x0c010f7au: goto P_0c010f7a;
case 0x0c010f7cu: goto P_0c010f7c;
case 0x0c010f7eu: goto P_0c010f7e;
case 0x0c010f80u: goto P_0c010f80;
case 0x0c010f82u: goto P_0c010f82;
case 0x0c010f84u: goto P_0c010f84;
case 0x0c010f86u: goto P_0c010f86;
case 0x0c010f88u: goto P_0c010f88;
case 0x0c010f8au: goto P_0c010f8a;
case 0x0c010f8cu: goto P_0c010f8c;
case 0x0c010f8eu: goto P_0c010f8e;
case 0x0c010f90u: goto P_0c010f90;
case 0x0c010f92u: goto P_0c010f92;
case 0x0c010f94u: goto P_0c010f94;
case 0x0c010f96u: goto P_0c010f96;
case 0x0c010f98u: goto P_0c010f98;
case 0x0c010f9au: goto P_0c010f9a;
case 0x0c010f9cu: goto P_0c010f9c;
case 0x0c010f9eu: goto P_0c010f9e;
case 0x0c010fa0u: goto P_0c010fa0;
case 0x0c010fa2u: goto P_0c010fa2;
case 0x0c010fa4u: goto P_0c010fa4;
case 0x0c010fa6u: goto P_0c010fa6;
case 0x0c010fa8u: goto P_0c010fa8;
case 0x0c010faau: goto P_0c010faa;
case 0x0c010facu: goto P_0c010fac;
case 0x0c010faeu: goto P_0c010fae;
case 0x0c010fb0u: goto P_0c010fb0;
case 0x0c010fb2u: goto P_0c010fb2;
case 0x0c010fb4u: goto P_0c010fb4;
case 0x0c010fb6u: goto P_0c010fb6;
case 0x0c010fb8u: goto P_0c010fb8;
case 0x0c010fbau: goto P_0c010fba;
case 0x0c010fbcu: goto P_0c010fbc;
case 0x0c010fbeu: goto P_0c010fbe;
case 0x0c010fc0u: goto P_0c010fc0;
case 0x0c010fc2u: goto P_0c010fc2;
case 0x0c010fc4u: goto P_0c010fc4;
case 0x0c010fc6u: goto P_0c010fc6;
case 0x0c010fc8u: goto P_0c010fc8;
case 0x0c010fcau: goto P_0c010fca;
case 0x0c010fccu: goto P_0c010fcc;
case 0x0c010fceu: goto P_0c010fce;
case 0x0c010fd0u: goto P_0c010fd0;
case 0x0c010fd2u: goto P_0c010fd2;
case 0x0c010fd4u: goto P_0c010fd4;
case 0x0c010fd6u: goto P_0c010fd6;
case 0x0c010fd8u: goto P_0c010fd8;
case 0x0c010fdau: goto P_0c010fda;
case 0x0c010fdcu: goto P_0c010fdc;
case 0x0c010fdeu: goto P_0c010fde;
case 0x0c010fe0u: goto P_0c010fe0;
case 0x0c010fe2u: goto P_0c010fe2;
case 0x0c010fe4u: goto P_0c010fe4;
case 0x0c010fe6u: goto P_0c010fe6;
case 0x0c010fe8u: goto P_0c010fe8;
case 0x0c010feau: goto P_0c010fea;
case 0x0c010fecu: goto P_0c010fec;
case 0x0c010feeu: goto P_0c010fee;
case 0x0c010ff0u: goto P_0c010ff0;
case 0x0c010ff2u: goto P_0c010ff2;
case 0x0c010ff4u: goto P_0c010ff4;
case 0x0c010ff6u: goto P_0c010ff6;
case 0x0c010ff8u: goto P_0c010ff8;
case 0x0c010ffau: goto P_0c010ffa;
case 0x0c010ffcu: goto P_0c010ffc;
case 0x0c010ffeu: goto P_0c010ffe;
case 0x0c011000u: goto P_0c011000;
case 0x0c011002u: goto P_0c011002;
case 0x0c011004u: goto P_0c011004;
case 0x0c011006u: goto P_0c011006;
case 0x0c011008u: goto P_0c011008;
case 0x0c01100au: goto P_0c01100a;
case 0x0c01100cu: goto P_0c01100c;
case 0x0c01100eu: goto P_0c01100e;
case 0x0c011010u: goto P_0c011010;
case 0x0c011012u: goto P_0c011012;
case 0x0c011014u: goto P_0c011014;
case 0x0c011016u: goto P_0c011016;
case 0x0c011018u: goto P_0c011018;
case 0x0c01101au: goto P_0c01101a;
case 0x0c01101cu: goto P_0c01101c;
case 0x0c01101eu: goto P_0c01101e;
case 0x0c011020u: goto P_0c011020;
case 0x0c011022u: goto P_0c011022;
case 0x0c011024u: goto P_0c011024;
case 0x0c011026u: goto P_0c011026;
case 0x0c011028u: goto P_0c011028;
case 0x0c01102au: goto P_0c01102a;
case 0x0c01102cu: goto P_0c01102c;
case 0x0c01102eu: goto P_0c01102e;
case 0x0c011030u: goto P_0c011030;
case 0x0c011032u: goto P_0c011032;
case 0x0c011034u: goto P_0c011034;
case 0x0c011036u: goto P_0c011036;
case 0x0c011038u: goto P_0c011038;
case 0x0c01103au: goto P_0c01103a;
case 0x0c01103cu: goto P_0c01103c;
case 0x0c01103eu: goto P_0c01103e;
case 0x0c011040u: goto P_0c011040;
case 0x0c011042u: goto P_0c011042;
case 0x0c0113c2u: goto P_0c0113c2;
case 0x0c0113c4u: goto P_0c0113c4;
case 0x0c0113c6u: goto P_0c0113c6;
case 0x0c0113c8u: goto P_0c0113c8;
case 0x0c0113cau: goto P_0c0113ca;
case 0x0c0113ccu: goto P_0c0113cc;
case 0x0c0113ceu: goto P_0c0113ce;
case 0x0c0113d0u: goto P_0c0113d0;
case 0x0c0113d2u: goto P_0c0113d2;
case 0x0c0113d4u: goto P_0c0113d4;
case 0x0c0113d6u: goto P_0c0113d6;
case 0x0c0113d8u: goto P_0c0113d8;
case 0x0c0113dau: goto P_0c0113da;
case 0x0c0113dcu: goto P_0c0113dc;
case 0x0c0113deu: goto P_0c0113de;
case 0x0c0113e0u: goto P_0c0113e0;
case 0x0c0113e2u: goto P_0c0113e2;
case 0x0c0113e4u: goto P_0c0113e4;
case 0x0c0113e6u: goto P_0c0113e6;
case 0x0c0113e8u: goto P_0c0113e8;
case 0x0c0113eau: goto P_0c0113ea;
case 0x0c0113ecu: goto P_0c0113ec;
case 0x0c0113eeu: goto P_0c0113ee;
case 0x0c0113f0u: goto P_0c0113f0;
case 0x0c0113f2u: goto P_0c0113f2;
case 0x0c0113f4u: goto P_0c0113f4;
case 0x0c0113f6u: goto P_0c0113f6;
case 0x0c0113f8u: goto P_0c0113f8;
case 0x0c0113fau: goto P_0c0113fa;
case 0x0c0113fcu: goto P_0c0113fc;
case 0x0c0113feu: goto P_0c0113fe;
case 0x0c011400u: goto P_0c011400;
case 0x0c011402u: goto P_0c011402;
case 0x0c011404u: goto P_0c011404;
case 0x0c011406u: goto P_0c011406;
case 0x0c011408u: goto P_0c011408;
case 0x0c01140au: goto P_0c01140a;
case 0x0c01140cu: goto P_0c01140c;
case 0x0c01140eu: goto P_0c01140e;
case 0x0c011410u: goto P_0c011410;
case 0x0c011412u: goto P_0c011412;
case 0x0c011414u: goto P_0c011414;
case 0x0c011416u: goto P_0c011416;
case 0x0c011418u: goto P_0c011418;
case 0x0c01141au: goto P_0c01141a;
case 0x0c01141cu: goto P_0c01141c;
case 0x0c01141eu: goto P_0c01141e;
case 0x0c011420u: goto P_0c011420;
case 0x0c011422u: goto P_0c011422;
case 0x0c011424u: goto P_0c011424;
case 0x0c011426u: goto P_0c011426;
case 0x0c011428u: goto P_0c011428;
case 0x0c01142au: goto P_0c01142a;
case 0x0c01142cu: goto P_0c01142c;
case 0x0c01142eu: goto P_0c01142e;
case 0x0c011430u: goto P_0c011430;
case 0x0c011432u: goto P_0c011432;
case 0x0c011434u: goto P_0c011434;
case 0x0c011436u: goto P_0c011436;
case 0x0c011438u: goto P_0c011438;
case 0x0c01143au: goto P_0c01143a;
case 0x0c01143cu: goto P_0c01143c;
case 0x0c01143eu: goto P_0c01143e;
case 0x0c011440u: goto P_0c011440;
case 0x0c011442u: goto P_0c011442;
case 0x0c011444u: goto P_0c011444;
case 0x0c011446u: goto P_0c011446;
case 0x0c011448u: goto P_0c011448;
case 0x0c01144au: goto P_0c01144a;
case 0x0c01144cu: goto P_0c01144c;
case 0x0c01144eu: goto P_0c01144e;
case 0x0c011450u: goto P_0c011450;
case 0x0c011452u: goto P_0c011452;
case 0x0c011454u: goto P_0c011454;
case 0x0c011456u: goto P_0c011456;
case 0x0c011458u: goto P_0c011458;
case 0x0c01145au: goto P_0c01145a;
case 0x0c01145cu: goto P_0c01145c;
case 0x0c01145eu: goto P_0c01145e;
case 0x0c011460u: goto P_0c011460;
case 0x0c011462u: goto P_0c011462;
case 0x0c011464u: goto P_0c011464;
case 0x0c011466u: goto P_0c011466;
case 0x0c011468u: goto P_0c011468;
case 0x0c0114b8u: goto P_0c0114b8;
case 0x0c0114bau: goto P_0c0114ba;
case 0x0c0114bcu: goto P_0c0114bc;
case 0x0c0114beu: goto P_0c0114be;
case 0x0c0114c0u: goto P_0c0114c0;
case 0x0c0114c2u: goto P_0c0114c2;
case 0x0c0114c4u: goto P_0c0114c4;
case 0x0c0114c6u: goto P_0c0114c6;
case 0x0c0114c8u: goto P_0c0114c8;
case 0x0c0114cau: goto P_0c0114ca;
case 0x0c0114ccu: goto P_0c0114cc;
case 0x0c0114ceu: goto P_0c0114ce;
case 0x0c0114d0u: goto P_0c0114d0;
case 0x0c0114d2u: goto P_0c0114d2;
case 0x0c0114d4u: goto P_0c0114d4;
case 0x0c0114d6u: goto P_0c0114d6;
case 0x0c0114d8u: goto P_0c0114d8;
case 0x0c0114dau: goto P_0c0114da;
case 0x0c0114dcu: goto P_0c0114dc;
case 0x0c0114deu: goto P_0c0114de;
case 0x0c0114e0u: goto P_0c0114e0;
case 0x0c0114e2u: goto P_0c0114e2;
case 0x0c0114e4u: goto P_0c0114e4;
case 0x0c0114e6u: goto P_0c0114e6;
case 0x0c0114e8u: goto P_0c0114e8;
case 0x0c0114eau: goto P_0c0114ea;
case 0x0c0114ecu: goto P_0c0114ec;
case 0x0c0114eeu: goto P_0c0114ee;
case 0x0c0114f0u: goto P_0c0114f0;
case 0x0c0114f2u: goto P_0c0114f2;
case 0x0c0114f4u: goto P_0c0114f4;
case 0x0c0114f6u: goto P_0c0114f6;
case 0x0c0114f8u: goto P_0c0114f8;
case 0x0c0114fau: goto P_0c0114fa;
case 0x0c0114fcu: goto P_0c0114fc;
case 0x0c0114feu: goto P_0c0114fe;
case 0x0c011500u: goto P_0c011500;
case 0x0c011502u: goto P_0c011502;
case 0x0c011504u: goto P_0c011504;
case 0x0c011506u: goto P_0c011506;
case 0x0c011508u: goto P_0c011508;
case 0x0c01150au: goto P_0c01150a;
case 0x0c01150cu: goto P_0c01150c;
case 0x0c01150eu: goto P_0c01150e;
case 0x0c011510u: goto P_0c011510;
case 0x0c011512u: goto P_0c011512;
case 0x0c011514u: goto P_0c011514;
case 0x0c011516u: goto P_0c011516;
case 0x0c011518u: goto P_0c011518;
case 0x0c01151au: goto P_0c01151a;
case 0x0c01151cu: goto P_0c01151c;
case 0x0c01151eu: goto P_0c01151e;
case 0x0c011520u: goto P_0c011520;
case 0x0c011522u: goto P_0c011522;
case 0x0c011524u: goto P_0c011524;
case 0x0c011526u: goto P_0c011526;
case 0x0c011528u: goto P_0c011528;
case 0x0c01152au: goto P_0c01152a;
case 0x0c01152cu: goto P_0c01152c;
case 0x0c01152eu: goto P_0c01152e;
case 0x0c011530u: goto P_0c011530;
case 0x0c011532u: goto P_0c011532;
case 0x0c011534u: goto P_0c011534;
case 0x0c011536u: goto P_0c011536;
case 0x0c011538u: goto P_0c011538;
case 0x0c01153au: goto P_0c01153a;
case 0x0c01153cu: goto P_0c01153c;
case 0x0c01153eu: goto P_0c01153e;
case 0x0c011540u: goto P_0c011540;
case 0x0c011542u: goto P_0c011542;
case 0x0c011544u: goto P_0c011544;
case 0x0c011546u: goto P_0c011546;
case 0x0c011548u: goto P_0c011548;
case 0x0c01154au: goto P_0c01154a;
case 0x0c01154cu: goto P_0c01154c;
case 0x0c01154eu: goto P_0c01154e;
case 0x0c011550u: goto P_0c011550;
case 0x0c011552u: goto P_0c011552;
case 0x0c011554u: goto P_0c011554;
case 0x0c011556u: goto P_0c011556;
case 0x0c011558u: goto P_0c011558;
case 0x0c01155au: goto P_0c01155a;
case 0x0c01155cu: goto P_0c01155c;
case 0x0c01155eu: goto P_0c01155e;
case 0x0c011560u: goto P_0c011560;
case 0x0c011562u: goto P_0c011562;
case 0x0c011564u: goto P_0c011564;
case 0x0c011566u: goto P_0c011566;
case 0x0c011568u: goto P_0c011568;
case 0x0c01156au: goto P_0c01156a;
case 0x0c01156cu: goto P_0c01156c;
case 0x0c01156eu: goto P_0c01156e;
case 0x0c011570u: goto P_0c011570;
case 0x0c011572u: goto P_0c011572;
case 0x0c011574u: goto P_0c011574;
case 0x0c011576u: goto P_0c011576;
case 0x0c011578u: goto P_0c011578;
case 0x0c01157au: goto P_0c01157a;
case 0x0c01157cu: goto P_0c01157c;
case 0x0c01157eu: goto P_0c01157e;
case 0x0c011580u: goto P_0c011580;
case 0x0c011582u: goto P_0c011582;
case 0x0c011584u: goto P_0c011584;
case 0x0c011586u: goto P_0c011586;
case 0x0c011588u: goto P_0c011588;
case 0x0c01158au: goto P_0c01158a;
case 0x0c01158cu: goto P_0c01158c;
case 0x0c01158eu: goto P_0c01158e;
case 0x0c011590u: goto P_0c011590;
case 0x0c011592u: goto P_0c011592;
case 0x0c011594u: goto P_0c011594;
case 0x0c011596u: goto P_0c011596;
case 0x0c011598u: goto P_0c011598;
case 0x0c01159au: goto P_0c01159a;
case 0x0c01159cu: goto P_0c01159c;
case 0x0c01159eu: goto P_0c01159e;
case 0x0c0115a0u: goto P_0c0115a0;
case 0x0c0115c2u: goto P_0c0115c2;
case 0x0c0115c4u: goto P_0c0115c4;
case 0x0c0115c6u: goto P_0c0115c6;
case 0x0c0115c8u: goto P_0c0115c8;
case 0x0c0115cau: goto P_0c0115ca;
case 0x0c0115ccu: goto P_0c0115cc;
case 0x0c0115ceu: goto P_0c0115ce;
case 0x0c0115d0u: goto P_0c0115d0;
case 0x0c0115d2u: goto P_0c0115d2;
case 0x0c0115d4u: goto P_0c0115d4;
case 0x0c0115d6u: goto P_0c0115d6;
case 0x0c0115d8u: goto P_0c0115d8;
case 0x0c0115dau: goto P_0c0115da;
case 0x0c0115dcu: goto P_0c0115dc;
case 0x0c0115deu: goto P_0c0115de;
case 0x0c0115e0u: goto P_0c0115e0;
case 0x0c0115e2u: goto P_0c0115e2;
case 0x0c0115e4u: goto P_0c0115e4;
case 0x0c0115e6u: goto P_0c0115e6;
case 0x0c0115e8u: goto P_0c0115e8;
case 0x0c0115eau: goto P_0c0115ea;
case 0x0c0115ecu: goto P_0c0115ec;
case 0x0c0115eeu: goto P_0c0115ee;
case 0x0c0115f0u: goto P_0c0115f0;
case 0x0c0115f2u: goto P_0c0115f2;
case 0x0c0115f4u: goto P_0c0115f4;
case 0x0c0115f6u: goto P_0c0115f6;
case 0x0c0115f8u: goto P_0c0115f8;
case 0x0c0115fau: goto P_0c0115fa;
case 0x0c0115fcu: goto P_0c0115fc;
case 0x0c0115feu: goto P_0c0115fe;
case 0x0c011600u: goto P_0c011600;
case 0x0c011602u: goto P_0c011602;
case 0x0c011604u: goto P_0c011604;
case 0x0c011606u: goto P_0c011606;
case 0x0c011608u: goto P_0c011608;
case 0x0c01160au: goto P_0c01160a;
case 0x0c01160cu: goto P_0c01160c;
case 0x0c01160eu: goto P_0c01160e;
case 0x0c011610u: goto P_0c011610;
case 0x0c011612u: goto P_0c011612;
case 0x0c011614u: goto P_0c011614;
case 0x0c011616u: goto P_0c011616;
case 0x0c011618u: goto P_0c011618;
case 0x0c01161au: goto P_0c01161a;
case 0x0c01161cu: goto P_0c01161c;
case 0x0c01161eu: goto P_0c01161e;
case 0x0c011620u: goto P_0c011620;
case 0x0c011622u: goto P_0c011622;
case 0x0c011624u: goto P_0c011624;
case 0x0c011626u: goto P_0c011626;
case 0x0c011628u: goto P_0c011628;
case 0x0c01162au: goto P_0c01162a;
case 0x0c01162cu: goto P_0c01162c;
case 0x0c01162eu: goto P_0c01162e;
case 0x0c011630u: goto P_0c011630;
case 0x0c011632u: goto P_0c011632;
case 0x0c011634u: goto P_0c011634;
case 0x0c011636u: goto P_0c011636;
case 0x0c011638u: goto P_0c011638;
case 0x0c01163au: goto P_0c01163a;
case 0x0c01163cu: goto P_0c01163c;
case 0x0c01163eu: goto P_0c01163e;
case 0x0c011640u: goto P_0c011640;
case 0x0c011642u: goto P_0c011642;
case 0x0c011644u: goto P_0c011644;
case 0x0c011646u: goto P_0c011646;
case 0x0c011648u: goto P_0c011648;
case 0x0c01164au: goto P_0c01164a;
case 0x0c01164cu: goto P_0c01164c;
case 0x0c01164eu: goto P_0c01164e;
case 0x0c011650u: goto P_0c011650;
case 0x0c011652u: goto P_0c011652;
case 0x0c011654u: goto P_0c011654;
case 0x0c011656u: goto P_0c011656;
case 0x0c011658u: goto P_0c011658;
case 0x0c01165au: goto P_0c01165a;
case 0x0c01165cu: goto P_0c01165c;
case 0x0c01165eu: goto P_0c01165e;
case 0x0c011660u: goto P_0c011660;
case 0x0c011662u: goto P_0c011662;
case 0x0c011664u: goto P_0c011664;
case 0x0c011666u: goto P_0c011666;
case 0x0c011668u: goto P_0c011668;
case 0x0c01166au: goto P_0c01166a;
case 0x0c01166cu: goto P_0c01166c;
case 0x0c01166eu: goto P_0c01166e;
case 0x0c011670u: goto P_0c011670;
case 0x0c011672u: goto P_0c011672;
case 0x0c011674u: goto P_0c011674;
case 0x0c011676u: goto P_0c011676;
case 0x0c011678u: goto P_0c011678;
case 0x0c01167au: goto P_0c01167a;
case 0x0c01167cu: goto P_0c01167c;
case 0x0c01167eu: goto P_0c01167e;
case 0x0c011680u: goto P_0c011680;
case 0x0c011682u: goto P_0c011682;
case 0x0c011684u: goto P_0c011684;
case 0x0c011686u: goto P_0c011686;
case 0x0c011688u: goto P_0c011688;
case 0x0c01168au: goto P_0c01168a;
case 0x0c01168cu: goto P_0c01168c;
case 0x0c01168eu: goto P_0c01168e;
case 0x0c011690u: goto P_0c011690;
case 0x0c011692u: goto P_0c011692;
case 0x0c011694u: goto P_0c011694;
case 0x0c011696u: goto P_0c011696;
case 0x0c011698u: goto P_0c011698;
case 0x0c01169au: goto P_0c01169a;
case 0x0c01169cu: goto P_0c01169c;
case 0x0c01169eu: goto P_0c01169e;
case 0x0c0116a0u: goto P_0c0116a0;
case 0x0c0116a2u: goto P_0c0116a2;
case 0x0c0116a4u: goto P_0c0116a4;
case 0x0c0116a6u: goto P_0c0116a6;
case 0x0c0116a8u: goto P_0c0116a8;
case 0x0c0116aau: goto P_0c0116aa;
case 0x0c0116acu: goto P_0c0116ac;
case 0x0c0116aeu: goto P_0c0116ae;
case 0x0c0116b0u: goto P_0c0116b0;
case 0x0c0116b2u: goto P_0c0116b2;
case 0x0c0116b4u: goto P_0c0116b4;
case 0x0c0116b6u: goto P_0c0116b6;
case 0x0c0116b8u: goto P_0c0116b8;
case 0x0c0116bau: goto P_0c0116ba;
case 0x0c0116bcu: goto P_0c0116bc;
case 0x0c0116beu: goto P_0c0116be;
case 0x0c0116c0u: goto P_0c0116c0;
case 0x0c0116c2u: goto P_0c0116c2;
case 0x0c0116c4u: goto P_0c0116c4;
case 0x0c0116c6u: goto P_0c0116c6;
case 0x0c0116c8u: goto P_0c0116c8;
case 0x0c0116cau: goto P_0c0116ca;
case 0x0c0116ccu: goto P_0c0116cc;
case 0x0c0116ceu: goto P_0c0116ce;
case 0x0c0116d0u: goto P_0c0116d0;
case 0x0c0116d2u: goto P_0c0116d2;
case 0x0c0116d4u: goto P_0c0116d4;
case 0x0c0116d6u: goto P_0c0116d6;
case 0x0c0116d8u: goto P_0c0116d8;
case 0x0c0116dau: goto P_0c0116da;
case 0x0c0116dcu: goto P_0c0116dc;
case 0x0c0116deu: goto P_0c0116de;
case 0x0c0116e0u: goto P_0c0116e0;
case 0x0c0116e2u: goto P_0c0116e2;
case 0x0c0116e4u: goto P_0c0116e4;
case 0x0c0116e6u: goto P_0c0116e6;
case 0x0c0116e8u: goto P_0c0116e8;
case 0x0c0116eau: goto P_0c0116ea;
case 0x0c0116ecu: goto P_0c0116ec;
case 0x0c0116eeu: goto P_0c0116ee;
case 0x0c0116f0u: goto P_0c0116f0;
case 0x0c0116f2u: goto P_0c0116f2;
case 0x0c0116f4u: goto P_0c0116f4;
case 0x0c0116f6u: goto P_0c0116f6;
case 0x0c0116f8u: goto P_0c0116f8;
case 0x0c0116fau: goto P_0c0116fa;
case 0x0c0116fcu: goto P_0c0116fc;
case 0x0c0116feu: goto P_0c0116fe;
case 0x0c011700u: goto P_0c011700;
case 0x0c011702u: goto P_0c011702;
case 0x0c011704u: goto P_0c011704;
case 0x0c011706u: goto P_0c011706;
case 0x0c011708u: goto P_0c011708;
case 0x0c01170au: goto P_0c01170a;
case 0x0c01170cu: goto P_0c01170c;
case 0x0c01170eu: goto P_0c01170e;
case 0x0c011710u: goto P_0c011710;
case 0x0c011712u: goto P_0c011712;
case 0x0c011714u: goto P_0c011714;
case 0x0c011716u: goto P_0c011716;
case 0x0c011718u: goto P_0c011718;
case 0x0c01171au: goto P_0c01171a;
case 0x0c01171cu: goto P_0c01171c;
case 0x0c01171eu: goto P_0c01171e;
case 0x0c011780u: goto P_0c011780;
case 0x0c011782u: goto P_0c011782;
case 0x0c011784u: goto P_0c011784;
case 0x0c011786u: goto P_0c011786;
case 0x0c011788u: goto P_0c011788;
case 0x0c01178au: goto P_0c01178a;
case 0x0c01178cu: goto P_0c01178c;
case 0x0c01178eu: goto P_0c01178e;
case 0x0c011790u: goto P_0c011790;
case 0x0c011792u: goto P_0c011792;
case 0x0c011794u: goto P_0c011794;
case 0x0c011796u: goto P_0c011796;
case 0x0c011798u: goto P_0c011798;
case 0x0c01179au: goto P_0c01179a;
case 0x0c01179cu: goto P_0c01179c;
case 0x0c01179eu: goto P_0c01179e;
case 0x0c0117a0u: goto P_0c0117a0;
case 0x0c0117a2u: goto P_0c0117a2;
case 0x0c0117a4u: goto P_0c0117a4;
case 0x0c0117a6u: goto P_0c0117a6;
case 0x0c0117a8u: goto P_0c0117a8;
case 0x0c0117aau: goto P_0c0117aa;
case 0x0c0117acu: goto P_0c0117ac;
case 0x0c0117aeu: goto P_0c0117ae;
case 0x0c0117b0u: goto P_0c0117b0;
case 0x0c0117b2u: goto P_0c0117b2;
case 0x0c0117b4u: goto P_0c0117b4;
case 0x0c0117b6u: goto P_0c0117b6;
case 0x0c0117b8u: goto P_0c0117b8;
case 0x0c0117bau: goto P_0c0117ba;
case 0x0c0117bcu: goto P_0c0117bc;
case 0x0c0117beu: goto P_0c0117be;
case 0x0c0117c0u: goto P_0c0117c0;
case 0x0c0117c2u: goto P_0c0117c2;
case 0x0c0117c4u: goto P_0c0117c4;
case 0x0c0117c6u: goto P_0c0117c6;
case 0x0c0117c8u: goto P_0c0117c8;
case 0x0c0117cau: goto P_0c0117ca;
case 0x0c0117ccu: goto P_0c0117cc;
case 0x0c0117ceu: goto P_0c0117ce;
case 0x0c0117d0u: goto P_0c0117d0;
case 0x0c0117d2u: goto P_0c0117d2;
case 0x0c0117d4u: goto P_0c0117d4;
case 0x0c0117d6u: goto P_0c0117d6;
case 0x0c0117d8u: goto P_0c0117d8;
case 0x0c0117dau: goto P_0c0117da;
case 0x0c0117dcu: goto P_0c0117dc;
case 0x0c0117deu: goto P_0c0117de;
case 0x0c0117e0u: goto P_0c0117e0;
case 0x0c0117e2u: goto P_0c0117e2;
case 0x0c0117e4u: goto P_0c0117e4;
case 0x0c0117e6u: goto P_0c0117e6;
case 0x0c0117e8u: goto P_0c0117e8;
case 0x0c0117eau: goto P_0c0117ea;
case 0x0c0117ecu: goto P_0c0117ec;
case 0x0c0117eeu: goto P_0c0117ee;
case 0x0c0117f0u: goto P_0c0117f0;
case 0x0c0117f2u: goto P_0c0117f2;
case 0x0c0117f4u: goto P_0c0117f4;
case 0x0c0117f6u: goto P_0c0117f6;
case 0x0c0117f8u: goto P_0c0117f8;
case 0x0c0117fau: goto P_0c0117fa;
case 0x0c0117fcu: goto P_0c0117fc;
case 0x0c0117feu: goto P_0c0117fe;
case 0x0c011800u: goto P_0c011800;
case 0x0c011802u: goto P_0c011802;
case 0x0c011804u: goto P_0c011804;
case 0x0c011806u: goto P_0c011806;
case 0x0c011808u: goto P_0c011808;
case 0x0c01180au: goto P_0c01180a;
case 0x0c01180cu: goto P_0c01180c;
case 0x0c01180eu: goto P_0c01180e;
case 0x0c011810u: goto P_0c011810;
case 0x0c011812u: goto P_0c011812;
case 0x0c011814u: goto P_0c011814;
case 0x0c011816u: goto P_0c011816;
case 0x0c011818u: goto P_0c011818;
case 0x0c01181au: goto P_0c01181a;
case 0x0c01181cu: goto P_0c01181c;
case 0x0c01181eu: goto P_0c01181e;
case 0x0c011820u: goto P_0c011820;
case 0x0c011822u: goto P_0c011822;
case 0x0c011824u: goto P_0c011824;
case 0x0c011826u: goto P_0c011826;
case 0x0c011828u: goto P_0c011828;
case 0x0c01182au: goto P_0c01182a;
case 0x0c01182cu: goto P_0c01182c;
case 0x0c01182eu: goto P_0c01182e;
case 0x0c011830u: goto P_0c011830;
case 0x0c011832u: goto P_0c011832;
case 0x0c011834u: goto P_0c011834;
case 0x0c011836u: goto P_0c011836;
case 0x0c011838u: goto P_0c011838;
case 0x0c01183au: goto P_0c01183a;
case 0x0c01183cu: goto P_0c01183c;
case 0x0c01183eu: goto P_0c01183e;
case 0x0c011840u: goto P_0c011840;
case 0x0c011842u: goto P_0c011842;
case 0x0c011844u: goto P_0c011844;
case 0x0c011846u: goto P_0c011846;
case 0x0c011848u: goto P_0c011848;
case 0x0c01184au: goto P_0c01184a;
case 0x0c01184cu: goto P_0c01184c;
case 0x0c01184eu: goto P_0c01184e;
case 0x0c011850u: goto P_0c011850;
case 0x0c011852u: goto P_0c011852;
case 0x0c011854u: goto P_0c011854;
case 0x0c011856u: goto P_0c011856;
case 0x0c011858u: goto P_0c011858;
case 0x0c01185au: goto P_0c01185a;
case 0x0c01185cu: goto P_0c01185c;
case 0x0c01185eu: goto P_0c01185e;
case 0x0c011860u: goto P_0c011860;
case 0x0c011862u: goto P_0c011862;
case 0x0c011864u: goto P_0c011864;
case 0x0c011866u: goto P_0c011866;
case 0x0c011868u: goto P_0c011868;
case 0x0c01186au: goto P_0c01186a;
case 0x0c01186cu: goto P_0c01186c;
case 0x0c01186eu: goto P_0c01186e;
case 0x0c011870u: goto P_0c011870;
case 0x0c011872u: goto P_0c011872;
case 0x0c011874u: goto P_0c011874;
case 0x0c011876u: goto P_0c011876;
case 0x0c011878u: goto P_0c011878;
case 0x0c01187au: goto P_0c01187a;
case 0x0c01187cu: goto P_0c01187c;
case 0x0c01187eu: goto P_0c01187e;
case 0x0c011880u: goto P_0c011880;
case 0x0c011882u: goto P_0c011882;
case 0x0c011884u: goto P_0c011884;
case 0x0c011886u: goto P_0c011886;
case 0x0c011888u: goto P_0c011888;
case 0x0c01188au: goto P_0c01188a;
case 0x0c01188cu: goto P_0c01188c;
case 0x0c01188eu: goto P_0c01188e;
case 0x0c011890u: goto P_0c011890;
case 0x0c011892u: goto P_0c011892;
case 0x0c011894u: goto P_0c011894;
case 0x0c011896u: goto P_0c011896;
case 0x0c011898u: goto P_0c011898;
case 0x0c01189au: goto P_0c01189a;
case 0x0c01189cu: goto P_0c01189c;
case 0x0c01189eu: goto P_0c01189e;
case 0x0c0118a0u: goto P_0c0118a0;
case 0x0c0118a2u: goto P_0c0118a2;
case 0x0c0118a4u: goto P_0c0118a4;
case 0x0c0118a6u: goto P_0c0118a6;
case 0x0c0118a8u: goto P_0c0118a8;
case 0x0c0118f8u: goto P_0c0118f8;
case 0x0c0118fau: goto P_0c0118fa;
case 0x0c0118fcu: goto P_0c0118fc;
case 0x0c0118feu: goto P_0c0118fe;
case 0x0c011900u: goto P_0c011900;
case 0x0c011902u: goto P_0c011902;
case 0x0c011904u: goto P_0c011904;
case 0x0c011906u: goto P_0c011906;
case 0x0c011908u: goto P_0c011908;
case 0x0c01190au: goto P_0c01190a;
case 0x0c01190cu: goto P_0c01190c;
case 0x0c01190eu: goto P_0c01190e;
case 0x0c011910u: goto P_0c011910;
case 0x0c011912u: goto P_0c011912;
case 0x0c011914u: goto P_0c011914;
case 0x0c011916u: goto P_0c011916;
case 0x0c011918u: goto P_0c011918;
case 0x0c01191au: goto P_0c01191a;
case 0x0c01191cu: goto P_0c01191c;
case 0x0c01191eu: goto P_0c01191e;
case 0x0c011920u: goto P_0c011920;
case 0x0c011922u: goto P_0c011922;
case 0x0c011924u: goto P_0c011924;
case 0x0c011926u: goto P_0c011926;
case 0x0c011928u: goto P_0c011928;
case 0x0c01192au: goto P_0c01192a;
case 0x0c01192cu: goto P_0c01192c;
case 0x0c01192eu: goto P_0c01192e;
case 0x0c011930u: goto P_0c011930;
case 0x0c011932u: goto P_0c011932;
case 0x0c011934u: goto P_0c011934;
case 0x0c011936u: goto P_0c011936;
case 0x0c011938u: goto P_0c011938;
default: return vf3_matrix_family(target,s,ram);
}
P_0c010368: /* original d33b, guest PC 0x0c010368 */
if(!s->budget--) { s->failed_pc=0x0c010368u; return 0; }
r[3]=read(ram,0x0c010458u,4);
goto P_0c01036a;
P_0c01036a: /* original 9271, guest PC 0x0c01036a */
if(!s->budget--) { s->failed_pc=0x0c01036au; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c010450u,2);
goto P_0c01036c;
P_0c01036c: /* original 6432, guest PC 0x0c01036c */
if(!s->budget--) { s->failed_pc=0x0c01036cu; return 0; }
tmp=read(ram,r[3],4);
r[4]=tmp;
goto P_0c01036e;
P_0c01036e: /* original d53b, guest PC 0x0c01036e */
if(!s->budget--) { s->failed_pc=0x0c01036eu; return 0; }
r[5]=read(ram,0x0c01045cu,4);
goto P_0c010370;
P_0c010370: /* original 3420, guest PC 0x0c010370 */
if(!s->budget--) { s->failed_pc=0x0c010370u; return 0; }
r[17]=(r[17]&~1u)|((r[4]==r[2])!=0);
goto P_0c010372;
P_0c010372: /* original 8b04, guest PC 0x0c010372 */
if(!s->budget--) { s->failed_pc=0x0c010372u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c01037e; }
goto P_0c010374;
P_0c010374: /* original 6052, guest PC 0x0c010374 */
if(!s->budget--) { s->failed_pc=0x0c010374u; return 0; }
tmp=read(ram,r[5],4);
r[0]=tmp;
goto P_0c010376;
P_0c010376: /* original 4021, guest PC 0x0c010376 */
if(!s->budget--) { s->failed_pc=0x0c010376u; return 0; }
r[17]=(r[17]&~1u)|((r[0]&1)!=0);
r[0]=(uint32_t)((int32_t)r[0]>>1);
goto P_0c010378;
P_0c010378: /* original 4021, guest PC 0x0c010378 */
if(!s->budget--) { s->failed_pc=0x0c010378u; return 0; }
r[17]=(r[17]&~1u)|((r[0]&1)!=0);
r[0]=(uint32_t)((int32_t)r[0]>>1);
goto P_0c01037a;
P_0c01037a: /* original 4028, guest PC 0x0c01037a */
if(!s->budget--) { s->failed_pc=0x0c01037au; return 0; }
r[0]<<=16;
goto P_0c01037c;
P_0c01037c: /* original 240b, guest PC 0x0c01037c */
if(!s->budget--) { s->failed_pc=0x0c01037cu; return 0; }
r[4]|=r[0];
goto P_0c01037e;
P_0c01037e: /* original 9368, guest PC 0x0c01037e */
if(!s->budget--) { s->failed_pc=0x0c01037eu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c010452u,2);
goto P_0c010380;
P_0c010380: /* original 3430, guest PC 0x0c010380 */
if(!s->budget--) { s->failed_pc=0x0c010380u; return 0; }
r[17]=(r[17]&~1u)|((r[4]==r[3])!=0);
goto P_0c010382;
P_0c010382: /* original 8b04, guest PC 0x0c010382 */
if(!s->budget--) { s->failed_pc=0x0c010382u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c01038e; }
goto P_0c010384;
P_0c010384: /* original d236, guest PC 0x0c010384 */
if(!s->budget--) { s->failed_pc=0x0c010384u; return 0; }
r[2]=read(ram,0x0c010460u,4);
goto P_0c010386;
P_0c010386: /* original e1fd, guest PC 0x0c010386 */
if(!s->budget--) { s->failed_pc=0x0c010386u; return 0; }
r[1]=0xfffffffdu;
goto P_0c010388;
P_0c010388: /* original 6022, guest PC 0x0c010388 */
if(!s->budget--) { s->failed_pc=0x0c010388u; return 0; }
tmp=read(ram,r[2],4);
r[0]=tmp;
goto P_0c01038a;
P_0c01038a: /* original 2019, guest PC 0x0c01038a */
if(!s->budget--) { s->failed_pc=0x0c01038au; return 0; }
r[0]&=r[1];
goto P_0c01038c;
P_0c01038c: /* original 2202, guest PC 0x0c01038c */
if(!s->budget--) { s->failed_pc=0x0c01038cu; return 0; }
write(ram,r[2],r[0],4);
goto P_0c01038e;
P_0c01038e: /* original d635, guest PC 0x0c01038e */
if(!s->budget--) { s->failed_pc=0x0c01038eu; return 0; }
r[6]=read(ram,0x0c010464u,4);
goto P_0c010390;
P_0c010390: /* original 2448, guest PC 0x0c010390 */
if(!s->budget--) { s->failed_pc=0x0c010390u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c010392;
P_0c010392: /* original 8b00, guest PC 0x0c010392 */
if(!s->budget--) { s->failed_pc=0x0c010392u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c010396; }
goto P_0c010394;
P_0c010394: /* original 6462, guest PC 0x0c010394 */
if(!s->budget--) { s->failed_pc=0x0c010394u; return 0; }
tmp=read(ram,r[6],4);
r[4]=tmp;
goto P_0c010396;
P_0c010396: /* original d334, guest PC 0x0c010396 */
if(!s->budget--) { s->failed_pc=0x0c010396u; return 0; }
r[3]=read(ram,0x0c010468u,4);
goto P_0c010398;
P_0c010398: /* original e07c, guest PC 0x0c010398 */
if(!s->budget--) { s->failed_pc=0x0c010398u; return 0; }
r[0]=0x0000007cu;
goto P_0c01039a;
P_0c01039a: /* original 6232, guest PC 0x0c01039a */
if(!s->budget--) { s->failed_pc=0x0c01039au; return 0; }
tmp=read(ram,r[3],4);
r[2]=tmp;
goto P_0c01039c;
P_0c01039c: /* original 0246, guest PC 0x0c01039c */
if(!s->budget--) { s->failed_pc=0x0c01039cu; return 0; }
write(ram,r[2]+r[0],r[4],4);
goto P_0c01039e;
P_0c01039e: /* original e400, guest PC 0x0c01039e */
if(!s->budget--) { s->failed_pc=0x0c01039eu; return 0; }
r[4]=0x00000000u;
goto P_0c0103a0;
P_0c0103a0: /* original 2642, guest PC 0x0c0103a0 */
if(!s->budget--) { s->failed_pc=0x0c0103a0u; return 0; }
write(ram,r[6],r[4],4);
goto P_0c0103a2;
P_0c0103a2: /* original d232, guest PC 0x0c0103a2 */
if(!s->budget--) { s->failed_pc=0x0c0103a2u; return 0; }
r[2]=read(ram,0x0c01046cu,4);
goto P_0c0103a4;
P_0c0103a4: /* original 2242, guest PC 0x0c0103a4 */
if(!s->budget--) { s->failed_pc=0x0c0103a4u; return 0; }
write(ram,r[2],r[4],4);
goto P_0c0103a6;
P_0c0103a6: /* original 000b, guest PC 0x0c0103a6 */
if(!s->budget--) { s->failed_pc=0x0c0103a6u; return 0; }
target=r[16];
write(ram,r[5],r[4],4);
s->pc=target; return ram->oob==0;
P_0c0103a8: /* original 2542, guest PC 0x0c0103a8 */
if(!s->budget--) { s->failed_pc=0x0c0103a8u; return 0; }
write(ram,r[5],r[4],4);
return vf3_matrix_family(0x0c0103aau,s,ram);
P_0c0109f6: /* original 4615, guest PC 0x0c0109f6 */
if(!s->budget--) { s->failed_pc=0x0c0109f6u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[6]>0)!=0);
goto P_0c0109f8;
P_0c0109f8: /* original 6753, guest PC 0x0c0109f8 */
if(!s->budget--) { s->failed_pc=0x0c0109f8u; return 0; }
r[7]=r[5];
goto P_0c0109fa;
P_0c0109fa: /* original 6043, guest PC 0x0c0109fa */
if(!s->budget--) { s->failed_pc=0x0c0109fau; return 0; }
r[0]=r[4];
goto P_0c0109fc;
P_0c0109fc: /* original 8f06, guest PC 0x0c0109fc */
if(!s->budget--) { s->failed_pc=0x0c0109fcu; return 0; }
cond=r[17]&1u;
r[4]=0x00000000u;
if(!cond) { goto P_0c010a0c; }
goto P_0c010a00;
P_0c0109fe: /* original e400, guest PC 0x0c0109fe */
if(!s->budget--) { s->failed_pc=0x0c0109feu; return 0; }
r[4]=0x00000000u;
goto P_0c010a00;
P_0c010a00: /* original 6376, guest PC 0x0c010a00 */
if(!s->budget--) { s->failed_pc=0x0c010a00u; return 0; }
tmp=read(ram,r[7],4);
r[7]+=4;
r[3]=tmp;
goto P_0c010a02;
P_0c010a02: /* original 7401, guest PC 0x0c010a02 */
if(!s->budget--) { s->failed_pc=0x0c010a02u; return 0; }
r[4]+=0x00000001u;
goto P_0c010a04;
P_0c010a04: /* original 3463, guest PC 0x0c010a04 */
if(!s->budget--) { s->failed_pc=0x0c010a04u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[6])!=0);
goto P_0c010a06;
P_0c010a06: /* original 2032, guest PC 0x0c010a06 */
if(!s->budget--) { s->failed_pc=0x0c010a06u; return 0; }
write(ram,r[0],r[3],4);
goto P_0c010a08;
P_0c010a08: /* original 8ffa, guest PC 0x0c010a08 */
if(!s->budget--) { s->failed_pc=0x0c010a08u; return 0; }
cond=r[17]&1u;
r[0]+=0x00000004u;
if(!cond) { goto P_0c010a00; }
goto P_0c010a0c;
P_0c010a0a: /* original 7004, guest PC 0x0c010a0a */
if(!s->budget--) { s->failed_pc=0x0c010a0au; return 0; }
r[0]+=0x00000004u;
goto P_0c010a0c;
P_0c010a0c: /* original 000b, guest PC 0x0c010a0c */
if(!s->budget--) { s->failed_pc=0x0c010a0cu; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c010a0e: /* original 0009, guest PC 0x0c010a0e */
if(!s->budget--) { s->failed_pc=0x0c010a0eu; return 0; }
return vf3_matrix_family(0x0c010a10u,s,ram);
P_0c010c2e: /* original 4f22, guest PC 0x0c010c2e */
if(!s->budget--) { s->failed_pc=0x0c010c2eu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c010c30;
P_0c010c30: /* original de2e, guest PC 0x0c010c30 */
if(!s->budget--) { s->failed_pc=0x0c010c30u; return 0; }
r[14]=read(ram,0x0c010cecu,4);
goto P_0c010c32;
P_0c010c32: /* original 63e3, guest PC 0x0c010c32 */
if(!s->budget--) { s->failed_pc=0x0c010c32u; return 0; }
r[3]=r[14];
goto P_0c010c34;
P_0c010c34: /* original 7501, guest PC 0x0c010c34 */
if(!s->budget--) { s->failed_pc=0x0c010c34u; return 0; }
r[5]+=0x00000001u;
goto P_0c010c36;
P_0c010c36: /* original 334c, guest PC 0x0c010c36 */
if(!s->budget--) { s->failed_pc=0x0c010c36u; return 0; }
r[3]+=r[4];
goto P_0c010c38;
P_0c010c38: /* original 3563, guest PC 0x0c010c38 */
if(!s->budget--) { s->failed_pc=0x0c010c38u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[5]>=(int32_t)r[6])!=0);
goto P_0c010c3a;
P_0c010c3a: /* original 23c2, guest PC 0x0c010c3a */
if(!s->budget--) { s->failed_pc=0x0c010c3au; return 0; }
write(ram,r[3],r[12],4);
goto P_0c010c3c;
P_0c010c3c: /* original 8ff9, guest PC 0x0c010c3c */
if(!s->budget--) { s->failed_pc=0x0c010c3cu; return 0; }
cond=r[17]&1u;
r[4]+=0x00000004u;
if(!cond) { goto P_0c010c32; }
goto P_0c010c40;
P_0c010c3e: /* original 7404, guest PC 0x0c010c3e */
if(!s->budget--) { s->failed_pc=0x0c010c3eu; return 0; }
r[4]+=0x00000004u;
goto P_0c010c40;
P_0c010c40: /* original d32b, guest PC 0x0c010c40 */
if(!s->budget--) { s->failed_pc=0x0c010c40u; return 0; }
r[3]=read(ram,0x0c010cf0u,4);
goto P_0c010c42;
P_0c010c42: /* original e070, guest PC 0x0c010c42 */
if(!s->budget--) { s->failed_pc=0x0c010c42u; return 0; }
r[0]=0x00000070u;
goto P_0c010c44;
P_0c010c44: /* original d22b, guest PC 0x0c010c44 */
if(!s->budget--) { s->failed_pc=0x0c010c44u; return 0; }
r[2]=read(ram,0x0c010cf4u,4);
goto P_0c010c46;
P_0c010c46: /* original eb08, guest PC 0x0c010c46 */
if(!s->budget--) { s->failed_pc=0x0c010c46u; return 0; }
r[11]=0x00000008u;
goto P_0c010c48;
P_0c010c48: /* original 0e36, guest PC 0x0c010c48 */
if(!s->budget--) { s->failed_pc=0x0c010c48u; return 0; }
write(ram,r[14]+r[0],r[3],4);
goto P_0c010c4a;
P_0c010c4a: /* original e074, guest PC 0x0c010c4a */
if(!s->budget--) { s->failed_pc=0x0c010c4au; return 0; }
r[0]=0x00000074u;
goto P_0c010c4c;
P_0c010c4c: /* original d32a, guest PC 0x0c010c4c */
if(!s->budget--) { s->failed_pc=0x0c010c4cu; return 0; }
r[3]=read(ram,0x0c010cf8u,4);
goto P_0c010c4e;
P_0c010c4e: /* original e801, guest PC 0x0c010c4e */
if(!s->budget--) { s->failed_pc=0x0c010c4eu; return 0; }
r[8]=0x00000001u;
goto P_0c010c50;
P_0c010c50: /* original 9d49, guest PC 0x0c010c50 */
if(!s->budget--) { s->failed_pc=0x0c010c50u; return 0; }
r[13]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c010ce6u,2);
goto P_0c010c52;
P_0c010c52: /* original 0e26, guest PC 0x0c010c52 */
if(!s->budget--) { s->failed_pc=0x0c010c52u; return 0; }
write(ram,r[14]+r[0],r[2],4);
goto P_0c010c54;
P_0c010c54: /* original 7050, guest PC 0x0c010c54 */
if(!s->budget--) { s->failed_pc=0x0c010c54u; return 0; }
r[0]+=0x00000050u;
goto P_0c010c56;
P_0c010c56: /* original d929, guest PC 0x0c010c56 */
if(!s->budget--) { s->failed_pc=0x0c010c56u; return 0; }
r[9]=read(ram,0x0c010cfcu,4);
goto P_0c010c58;
P_0c010c58: /* original 6ad3, guest PC 0x0c010c58 */
if(!s->budget--) { s->failed_pc=0x0c010c58u; return 0; }
r[10]=r[13];
goto P_0c010c5a;
P_0c010c5a: /* original 0e36, guest PC 0x0c010c5a */
if(!s->budget--) { s->failed_pc=0x0c010c5au; return 0; }
write(ram,r[14]+r[0],r[3],4);
goto P_0c010c5c;
P_0c010c5c: /* original d228, guest PC 0x0c010c5c */
if(!s->budget--) { s->failed_pc=0x0c010c5cu; return 0; }
r[2]=read(ram,0x0c010d00u,4);
goto P_0c010c5e;
P_0c010c5e: /* original c700, guest PC 0x0c010c5e */
if(!s->budget--) { s->failed_pc=0x0c010c5eu; return 0; }
r[0]=0x0c010c60u;
goto P_0c010c60;
P_0c010c60: /* original d522, guest PC 0x0c010c60 */
if(!s->budget--) { s->failed_pc=0x0c010c60u; return 0; }
r[5]=read(ram,0x0c010cecu,4);
goto P_0c010c62;
P_0c010c62: /* original 320c, guest PC 0x0c010c62 */
if(!s->budget--) { s->failed_pc=0x0c010c62u; return 0; }
r[2]+=r[0];
goto P_0c010c64;
P_0c010c64: /* original 9640, guest PC 0x0c010c64 */
if(!s->budget--) { s->failed_pc=0x0c010c64u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c010ce8u,2);
goto P_0c010c66;
P_0c010c66: /* original 6323, guest PC 0x0c010c66 */
if(!s->budget--) { s->failed_pc=0x0c010c66u; return 0; }
r[3]=r[2];
goto P_0c010c68;
P_0c010c68: /* original 6453, guest PC 0x0c010c68 */
if(!s->budget--) { s->failed_pc=0x0c010c68u; return 0; }
r[4]=r[5];
goto P_0c010c6a;
P_0c010c6a: /* original 239b, guest PC 0x0c010c6a */
if(!s->budget--) { s->failed_pc=0x0c010c6au; return 0; }
r[3]|=r[9];
goto P_0c010c6c;
P_0c010c6c: /* original 430b, guest PC 0x0c010c6c */
if(!s->budget--) { s->failed_pc=0x0c010c6cu; return 0; }
target=r[3];
r[16]=code_base|0x0c010c70u;
r[4]+=r[10];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c010c70u) { target=s->pc; goto dispatch; }
goto P_0c010c70;
P_0c010c6e: /* original 34ac, guest PC 0x0c010c6e */
if(!s->budget--) { s->failed_pc=0x0c010c6eu; return 0; }
r[4]+=r[10];
goto P_0c010c70;
P_0c010c70: /* original 7801, guest PC 0x0c010c70 */
if(!s->budget--) { s->failed_pc=0x0c010c70u; return 0; }
r[8]+=0x00000001u;
goto P_0c010c72;
P_0c010c72: /* original 38b3, guest PC 0x0c010c72 */
if(!s->budget--) { s->failed_pc=0x0c010c72u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[8]>=(int32_t)r[11])!=0);
goto P_0c010c74;
P_0c010c74: /* original 8ff2, guest PC 0x0c010c74 */
if(!s->budget--) { s->failed_pc=0x0c010c74u; return 0; }
cond=r[17]&1u;
r[10]+=r[13];
if(!cond) { goto P_0c010c5c; }
goto P_0c010c78;
P_0c010c76: /* original 3adc, guest PC 0x0c010c76 */
if(!s->budget--) { s->failed_pc=0x0c010c76u; return 0; }
r[10]+=r[13];
goto P_0c010c78;
P_0c010c78: /* original d822, guest PC 0x0c010c78 */
if(!s->budget--) { s->failed_pc=0x0c010c78u; return 0; }
r[8]=read(ram,0x0c010d04u,4);
goto P_0c010c7a;
P_0c010c7a: /* original 64c3, guest PC 0x0c010c7a */
if(!s->budget--) { s->failed_pc=0x0c010c7au; return 0; }
r[4]=r[12];
goto P_0c010c7c;
P_0c010c7c: /* original 9535, guest PC 0x0c010c7c */
if(!s->budget--) { s->failed_pc=0x0c010c7cu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c010ceau,2);
goto P_0c010c7e;
P_0c010c7e: /* original 6ac3, guest PC 0x0c010c7e */
if(!s->budget--) { s->failed_pc=0x0c010c7eu; return 0; }
r[10]=r[12];
goto P_0c010c80;
P_0c010c80: /* original 66c3, guest PC 0x0c010c80 */
if(!s->budget--) { s->failed_pc=0x0c010c80u; return 0; }
r[6]=r[12];
goto P_0c010c82;
P_0c010c82: /* original 67d3, guest PC 0x0c010c82 */
if(!s->budget--) { s->failed_pc=0x0c010c82u; return 0; }
r[7]=r[13];
goto P_0c010c84;
P_0c010c84: /* original d219, guest PC 0x0c010c84 */
if(!s->budget--) { s->failed_pc=0x0c010c84u; return 0; }
r[2]=read(ram,0x0c010cecu,4);
goto P_0c010c86;
P_0c010c86: /* original 63e3, guest PC 0x0c010c86 */
if(!s->budget--) { s->failed_pc=0x0c010c86u; return 0; }
r[3]=r[14];
goto P_0c010c88;
P_0c010c88: /* original 733c, guest PC 0x0c010c88 */
if(!s->budget--) { s->failed_pc=0x0c010c88u; return 0; }
r[3]+=0x0000003cu;
goto P_0c010c8a;
P_0c010c8a: /* original 60e3, guest PC 0x0c010c8a */
if(!s->budget--) { s->failed_pc=0x0c010c8au; return 0; }
r[0]=r[14];
goto P_0c010c8c;
P_0c010c8c: /* original 327c, guest PC 0x0c010c8c */
if(!s->budget--) { s->failed_pc=0x0c010c8cu; return 0; }
r[2]+=r[7];
goto P_0c010c8e;
P_0c010c8e: /* original 334c, guest PC 0x0c010c8e */
if(!s->budget--) { s->failed_pc=0x0c010c8eu; return 0; }
r[3]+=r[4];
goto P_0c010c90;
P_0c010c90: /* original 2322, guest PC 0x0c010c90 */
if(!s->budget--) { s->failed_pc=0x0c010c90u; return 0; }
write(ram,r[3],r[2],4);
goto P_0c010c92;
P_0c010c92: /* original 7078, guest PC 0x0c010c92 */
if(!s->budget--) { s->failed_pc=0x0c010c92u; return 0; }
r[0]+=0x00000078u;
goto P_0c010c94;
P_0c010c94: /* original d315, guest PC 0x0c010c94 */
if(!s->budget--) { s->failed_pc=0x0c010c94u; return 0; }
r[3]=read(ram,0x0c010cecu,4);
goto P_0c010c96;
P_0c010c96: /* original 7a01, guest PC 0x0c010c96 */
if(!s->budget--) { s->failed_pc=0x0c010c96u; return 0; }
r[10]+=0x00000001u;
goto P_0c010c98;
P_0c010c98: /* original 37dc, guest PC 0x0c010c98 */
if(!s->budget--) { s->failed_pc=0x0c010c98u; return 0; }
r[7]+=r[13];
goto P_0c010c9a;
P_0c010c9a: /* original 3ab3, guest PC 0x0c010c9a */
if(!s->budget--) { s->failed_pc=0x0c010c9au; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[10]>=(int32_t)r[11])!=0);
goto P_0c010c9c;
P_0c010c9c: /* original 334c, guest PC 0x0c010c9c */
if(!s->budget--) { s->failed_pc=0x0c010c9cu; return 0; }
r[3]+=r[4];
goto P_0c010c9e;
P_0c010c9e: /* original 335c, guest PC 0x0c010c9e */
if(!s->budget--) { s->failed_pc=0x0c010c9eu; return 0; }
r[3]+=r[5];
goto P_0c010ca0;
P_0c010ca0: /* original 0436, guest PC 0x0c010ca0 */
if(!s->budget--) { s->failed_pc=0x0c010ca0u; return 0; }
write(ram,r[4]+r[0],r[3],4);
goto P_0c010ca2;
P_0c010ca2: /* original d212, guest PC 0x0c010ca2 */
if(!s->budget--) { s->failed_pc=0x0c010ca2u; return 0; }
r[2]=read(ram,0x0c010cecu,4);
goto P_0c010ca4;
P_0c010ca4: /* original d318, guest PC 0x0c010ca4 */
if(!s->budget--) { s->failed_pc=0x0c010ca4u; return 0; }
r[3]=read(ram,0x0c010d08u,4);
goto P_0c010ca6;
P_0c010ca6: /* original 324c, guest PC 0x0c010ca6 */
if(!s->budget--) { s->failed_pc=0x0c010ca6u; return 0; }
r[2]+=r[4];
goto P_0c010ca8;
P_0c010ca8: /* original 236b, guest PC 0x0c010ca8 */
if(!s->budget--) { s->failed_pc=0x0c010ca8u; return 0; }
r[3]|=r[6];
goto P_0c010caa;
P_0c010caa: /* original 325c, guest PC 0x0c010caa */
if(!s->budget--) { s->failed_pc=0x0c010caau; return 0; }
r[2]+=r[5];
goto P_0c010cac;
P_0c010cac: /* original 2232, guest PC 0x0c010cac */
if(!s->budget--) { s->failed_pc=0x0c010cacu; return 0; }
write(ram,r[2],r[3],4);
goto P_0c010cae;
P_0c010cae: /* original 368c, guest PC 0x0c010cae */
if(!s->budget--) { s->failed_pc=0x0c010caeu; return 0; }
r[6]+=r[8];
goto P_0c010cb0;
P_0c010cb0: /* original 8fe8, guest PC 0x0c010cb0 */
if(!s->budget--) { s->failed_pc=0x0c010cb0u; return 0; }
cond=r[17]&1u;
r[4]+=r[13];
if(!cond) { goto P_0c010c84; }
goto P_0c010cb4;
P_0c010cb2: /* original 34dc, guest PC 0x0c010cb2 */
if(!s->budget--) { s->failed_pc=0x0c010cb2u; return 0; }
r[4]+=r[13];
goto P_0c010cb4;
P_0c010cb4: /* original d315, guest PC 0x0c010cb4 */
if(!s->budget--) { s->failed_pc=0x0c010cb4u; return 0; }
r[3]=read(ram,0x0c010d0cu,4);
goto P_0c010cb6;
P_0c010cb6: /* original c705, guest PC 0x0c010cb6 */
if(!s->budget--) { s->failed_pc=0x0c010cb6u; return 0; }
r[0]=0x0c010cccu;
goto P_0c010cb8;
P_0c010cb8: /* original d115, guest PC 0x0c010cb8 */
if(!s->budget--) { s->failed_pc=0x0c010cb8u; return 0; }
r[1]=read(ram,0x0c010d10u,4);
goto P_0c010cba;
P_0c010cba: /* original 1e3f, guest PC 0x0c010cba */
if(!s->budget--) { s->failed_pc=0x0c010cbau; return 0; }
write(ram,r[14]+60,r[3],4);
goto P_0c010cbc;
P_0c010cbc: /* original d315, guest PC 0x0c010cbc */
if(!s->budget--) { s->failed_pc=0x0c010cbcu; return 0; }
r[3]=read(ram,0x0c010d14u,4);
goto P_0c010cbe;
P_0c010cbe: /* original d20b, guest PC 0x0c010cbe */
if(!s->budget--) { s->failed_pc=0x0c010cbeu; return 0; }
r[2]=read(ram,0x0c010cecu,4);
goto P_0c010cc0;
P_0c010cc0: /* original 2122, guest PC 0x0c010cc0 */
if(!s->budget--) { s->failed_pc=0x0c010cc0u; return 0; }
write(ram,r[1],r[2],4);
goto P_0c010cc2;
P_0c010cc2: /* original 23c2, guest PC 0x0c010cc2 */
if(!s->budget--) { s->failed_pc=0x0c010cc2u; return 0; }
write(ram,r[3],r[12],4);
goto P_0c010cc4;
P_0c010cc4: /* original d315, guest PC 0x0c010cc4 */
if(!s->budget--) { s->failed_pc=0x0c010cc4u; return 0; }
r[3]=read(ram,0x0c010d1cu,4);
goto P_0c010cc6;
P_0c010cc6: /* original d114, guest PC 0x0c010cc6 */
if(!s->budget--) { s->failed_pc=0x0c010cc6u; return 0; }
r[1]=read(ram,0x0c010d18u,4);
goto P_0c010cc8;
P_0c010cc8: /* original 330c, guest PC 0x0c010cc8 */
if(!s->budget--) { s->failed_pc=0x0c010cc8u; return 0; }
r[3]+=r[0];
goto P_0c010cca;
P_0c010cca: /* original 2122, guest PC 0x0c010cca */
if(!s->budget--) { s->failed_pc=0x0c010ccau; return 0; }
write(ram,r[1],r[2],4);
goto P_0c010ccc;
P_0c010ccc: /* original 6233, guest PC 0x0c010ccc */
if(!s->budget--) { s->failed_pc=0x0c010cccu; return 0; }
r[2]=r[3];
goto P_0c010cce;
P_0c010cce: /* original 292b, guest PC 0x0c010cce */
if(!s->budget--) { s->failed_pc=0x0c010cceu; return 0; }
r[9]|=r[2];
goto P_0c010cd0;
P_0c010cd0: /* original 490b, guest PC 0x0c010cd0 */
if(!s->budget--) { s->failed_pc=0x0c010cd0u; return 0; }
target=r[9];
r[16]=code_base|0x0c010cd4u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c010cd4u) { target=s->pc; goto dispatch; }
goto P_0c010cd4;
P_0c010cd2: /* original 0009, guest PC 0x0c010cd2 */
if(!s->budget--) { s->failed_pc=0x0c010cd2u; return 0; }
goto P_0c010cd4;
P_0c010cd4: /* original 4f26, guest PC 0x0c010cd4 */
if(!s->budget--) { s->failed_pc=0x0c010cd4u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c010cd6;
P_0c010cd6: /* original 68f6, guest PC 0x0c010cd6 */
if(!s->budget--) { s->failed_pc=0x0c010cd6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c010cd8;
P_0c010cd8: /* original 69f6, guest PC 0x0c010cd8 */
if(!s->budget--) { s->failed_pc=0x0c010cd8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c010cda;
P_0c010cda: /* original 6af6, guest PC 0x0c010cda */
if(!s->budget--) { s->failed_pc=0x0c010cdau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c010cdc;
P_0c010cdc: /* original 6bf6, guest PC 0x0c010cdc */
if(!s->budget--) { s->failed_pc=0x0c010cdcu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c010cde;
P_0c010cde: /* original 6cf6, guest PC 0x0c010cde */
if(!s->budget--) { s->failed_pc=0x0c010cdeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c010ce0;
P_0c010ce0: /* original 6df6, guest PC 0x0c010ce0 */
if(!s->budget--) { s->failed_pc=0x0c010ce0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c010ce2;
P_0c010ce2: /* original 000b, guest PC 0x0c010ce2 */
if(!s->budget--) { s->failed_pc=0x0c010ce2u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c010ce4: /* original 6ef6, guest PC 0x0c010ce4 */
if(!s->budget--) { s->failed_pc=0x0c010ce4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c010ce6u,s,ram);
P_0c010f42: /* original 4f22, guest PC 0x0c010f42 */
if(!s->budget--) { s->failed_pc=0x0c010f42u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c010f44;
P_0c010f44: /* original 6072, guest PC 0x0c010f44 */
if(!s->budget--) { s->failed_pc=0x0c010f44u; return 0; }
tmp=read(ram,r[7],4);
r[0]=tmp;
goto P_0c010f46;
P_0c010f46: /* original d542, guest PC 0x0c010f46 */
if(!s->budget--) { s->failed_pc=0x0c010f46u; return 0; }
r[5]=read(ram,0x0c011050u,4);
goto P_0c010f48;
P_0c010f48: /* original dd40, guest PC 0x0c010f48 */
if(!s->budget--) { s->failed_pc=0x0c010f48u; return 0; }
r[13]=read(ram,0x0c01104cu,4);
goto P_0c010f4a;
P_0c010f4a: /* original 8801, guest PC 0x0c010f4a */
if(!s->budget--) { s->failed_pc=0x0c010f4au; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c010f4c;
P_0c010f4c: /* original 8903, guest PC 0x0c010f4c */
if(!s->budget--) { s->failed_pc=0x0c010f4cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c010f56; }
goto P_0c010f4e;
P_0c010f4e: /* original 8802, guest PC 0x0c010f4e */
if(!s->budget--) { s->failed_pc=0x0c010f4eu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c010f50;
P_0c010f50: /* original 890a, guest PC 0x0c010f50 */
if(!s->budget--) { s->failed_pc=0x0c010f50u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c010f68; }
goto P_0c010f52;
P_0c010f52: /* original a011, guest PC 0x0c010f52 */
if(!s->budget--) { s->failed_pc=0x0c010f52u; return 0; }
goto P_0c010f78;
P_0c010f54: /* original 0009, guest PC 0x0c010f54 */
if(!s->budget--) { s->failed_pc=0x0c010f54u; return 0; }
goto P_0c010f56;
P_0c010f56: /* original d33f, guest PC 0x0c010f56 */
if(!s->budget--) { s->failed_pc=0x0c010f56u; return 0; }
r[3]=read(ram,0x0c011054u,4);
goto P_0c010f58;
P_0c010f58: /* original d240, guest PC 0x0c010f58 */
if(!s->budget--) { s->failed_pc=0x0c010f58u; return 0; }
r[2]=read(ram,0x0c01105cu,4);
goto P_0c010f5a;
P_0c010f5a: /* original d63f, guest PC 0x0c010f5a */
if(!s->budget--) { s->failed_pc=0x0c010f5au; return 0; }
r[6]=read(ram,0x0c011058u,4);
goto P_0c010f5c;
P_0c010f5c: /* original 2d32, guest PC 0x0c010f5c */
if(!s->budget--) { s->failed_pc=0x0c010f5cu; return 0; }
write(ram,r[13],r[3],4);
goto P_0c010f5e;
P_0c010f5e: /* original d340, guest PC 0x0c010f5e */
if(!s->budget--) { s->failed_pc=0x0c010f5eu; return 0; }
r[3]=read(ram,0x0c011060u,4);
goto P_0c010f60;
P_0c010f60: /* original 2262, guest PC 0x0c010f60 */
if(!s->budget--) { s->failed_pc=0x0c010f60u; return 0; }
write(ram,r[2],r[6],4);
goto P_0c010f62;
P_0c010f62: /* original 2562, guest PC 0x0c010f62 */
if(!s->budget--) { s->failed_pc=0x0c010f62u; return 0; }
write(ram,r[5],r[6],4);
goto P_0c010f64;
P_0c010f64: /* original a008, guest PC 0x0c010f64 */
if(!s->budget--) { s->failed_pc=0x0c010f64u; return 0; }
write(ram,r[3],r[6],4);
goto P_0c010f78;
P_0c010f66: /* original 2362, guest PC 0x0c010f66 */
if(!s->budget--) { s->failed_pc=0x0c010f66u; return 0; }
write(ram,r[3],r[6],4);
goto P_0c010f68;
P_0c010f68: /* original d23e, guest PC 0x0c010f68 */
if(!s->budget--) { s->failed_pc=0x0c010f68u; return 0; }
r[2]=read(ram,0x0c011064u,4);
goto P_0c010f6a;
P_0c010f6a: /* original d33c, guest PC 0x0c010f6a */
if(!s->budget--) { s->failed_pc=0x0c010f6au; return 0; }
r[3]=read(ram,0x0c01105cu,4);
goto P_0c010f6c;
P_0c010f6c: /* original 2d22, guest PC 0x0c010f6c */
if(!s->budget--) { s->failed_pc=0x0c010f6cu; return 0; }
write(ram,r[13],r[2],4);
goto P_0c010f6e;
P_0c010f6e: /* original d23c, guest PC 0x0c010f6e */
if(!s->budget--) { s->failed_pc=0x0c010f6eu; return 0; }
r[2]=read(ram,0x0c011060u,4);
goto P_0c010f70;
P_0c010f70: /* original d63d, guest PC 0x0c010f70 */
if(!s->budget--) { s->failed_pc=0x0c010f70u; return 0; }
r[6]=read(ram,0x0c011068u,4);
goto P_0c010f72;
P_0c010f72: /* original 2362, guest PC 0x0c010f72 */
if(!s->budget--) { s->failed_pc=0x0c010f72u; return 0; }
write(ram,r[3],r[6],4);
goto P_0c010f74;
P_0c010f74: /* original 2562, guest PC 0x0c010f74 */
if(!s->budget--) { s->failed_pc=0x0c010f74u; return 0; }
write(ram,r[5],r[6],4);
goto P_0c010f76;
P_0c010f76: /* original 2262, guest PC 0x0c010f76 */
if(!s->budget--) { s->failed_pc=0x0c010f76u; return 0; }
write(ram,r[2],r[6],4);
goto P_0c010f78;
P_0c010f78: /* original 6072, guest PC 0x0c010f78 */
if(!s->budget--) { s->failed_pc=0x0c010f78u; return 0; }
tmp=read(ram,r[7],4);
r[0]=tmp;
goto P_0c010f7a;
P_0c010f7a: /* original 8801, guest PC 0x0c010f7a */
if(!s->budget--) { s->failed_pc=0x0c010f7au; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c010f7c;
P_0c010f7c: /* original 8b0c, guest PC 0x0c010f7c */
if(!s->budget--) { s->failed_pc=0x0c010f7cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c010f98; }
goto P_0c010f7e;
P_0c010f7e: /* original d23b, guest PC 0x0c010f7e */
if(!s->budget--) { s->failed_pc=0x0c010f7eu; return 0; }
r[2]=read(ram,0x0c01106cu,4);
goto P_0c010f80;
P_0c010f80: /* original 9660, guest PC 0x0c010f80 */
if(!s->budget--) { s->failed_pc=0x0c010f80u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c011044u,2);
goto P_0c010f82;
P_0c010f82: /* original 2262, guest PC 0x0c010f82 */
if(!s->budget--) { s->failed_pc=0x0c010f82u; return 0; }
write(ram,r[2],r[6],4);
goto P_0c010f84;
P_0c010f84: /* original d33a, guest PC 0x0c010f84 */
if(!s->budget--) { s->failed_pc=0x0c010f84u; return 0; }
r[3]=read(ram,0x0c011070u,4);
goto P_0c010f86;
P_0c010f86: /* original 2362, guest PC 0x0c010f86 */
if(!s->budget--) { s->failed_pc=0x0c010f86u; return 0; }
write(ram,r[3],r[6],4);
goto P_0c010f88;
P_0c010f88: /* original d03a, guest PC 0x0c010f88 */
if(!s->budget--) { s->failed_pc=0x0c010f88u; return 0; }
r[0]=read(ram,0x0c011074u,4);
goto P_0c010f8a;
P_0c010f8a: /* original e105, guest PC 0x0c010f8a */
if(!s->budget--) { s->failed_pc=0x0c010f8au; return 0; }
r[1]=0x00000005u;
goto P_0c010f8c;
P_0c010f8c: /* original 2012, guest PC 0x0c010f8c */
if(!s->budget--) { s->failed_pc=0x0c010f8cu; return 0; }
write(ram,r[0],r[1],4);
goto P_0c010f8e;
P_0c010f8e: /* original d73a, guest PC 0x0c010f8e */
if(!s->budget--) { s->failed_pc=0x0c010f8eu; return 0; }
r[7]=read(ram,0x0c011078u,4);
goto P_0c010f90;
P_0c010f90: /* original 6672, guest PC 0x0c010f90 */
if(!s->budget--) { s->failed_pc=0x0c010f90u; return 0; }
tmp=read(ram,r[7],4);
r[6]=tmp;
goto P_0c010f92;
P_0c010f92: /* original e208, guest PC 0x0c010f92 */
if(!s->budget--) { s->failed_pc=0x0c010f92u; return 0; }
r[2]=0x00000008u;
goto P_0c010f94;
P_0c010f94: /* original 262b, guest PC 0x0c010f94 */
if(!s->budget--) { s->failed_pc=0x0c010f94u; return 0; }
r[6]|=r[2];
goto P_0c010f96;
P_0c010f96: /* original 2762, guest PC 0x0c010f96 */
if(!s->budget--) { s->failed_pc=0x0c010f96u; return 0; }
write(ram,r[7],r[6],4);
goto P_0c010f98;
P_0c010f98: /* original 63d2, guest PC 0x0c010f98 */
if(!s->budget--) { s->failed_pc=0x0c010f98u; return 0; }
tmp=read(ram,r[13],4);
r[3]=tmp;
goto P_0c010f9a;
P_0c010f9a: /* original e03c, guest PC 0x0c010f9a */
if(!s->budget--) { s->failed_pc=0x0c010f9au; return 0; }
r[0]=0x0000003cu;
goto P_0c010f9c;
P_0c010f9c: /* original e2c0, guest PC 0x0c010f9c */
if(!s->budget--) { s->failed_pc=0x0c010f9cu; return 0; }
r[2]=0xffffffc0u;
goto P_0c010f9e;
P_0c010f9e: /* original 0324, guest PC 0x0c010f9e */
if(!s->budget--) { s->failed_pc=0x0c010f9eu; return 0; }
write(ram,r[3]+r[0],r[2],1);
goto P_0c010fa0;
P_0c010fa0: /* original 6352, guest PC 0x0c010fa0 */
if(!s->budget--) { s->failed_pc=0x0c010fa0u; return 0; }
tmp=read(ram,r[5],4);
r[3]=tmp;
goto P_0c010fa2;
P_0c010fa2: /* original e20b, guest PC 0x0c010fa2 */
if(!s->budget--) { s->failed_pc=0x0c010fa2u; return 0; }
r[2]=0x0000000bu;
goto P_0c010fa4;
P_0c010fa4: /* original 2320, guest PC 0x0c010fa4 */
if(!s->budget--) { s->failed_pc=0x0c010fa4u; return 0; }
write(ram,r[3],r[2],1);
goto P_0c010fa6;
P_0c010fa6: /* original 6352, guest PC 0x0c010fa6 */
if(!s->budget--) { s->failed_pc=0x0c010fa6u; return 0; }
tmp=read(ram,r[5],4);
r[3]=tmp;
goto P_0c010fa8;
P_0c010fa8: /* original 6043, guest PC 0x0c010fa8 */
if(!s->budget--) { s->failed_pc=0x0c010fa8u; return 0; }
r[0]=r[4];
goto P_0c010faa;
P_0c010faa: /* original 8034, guest PC 0x0c010faa */
if(!s->budget--) { s->failed_pc=0x0c010faau; return 0; }
write(ram,r[3]+4,r[0],1);
goto P_0c010fac;
P_0c010fac: /* original 6352, guest PC 0x0c010fac */
if(!s->budget--) { s->failed_pc=0x0c010facu; return 0; }
tmp=read(ram,r[5],4);
r[3]=tmp;
goto P_0c010fae;
P_0c010fae: /* original e443, guest PC 0x0c010fae */
if(!s->budget--) { s->failed_pc=0x0c010faeu; return 0; }
r[4]=0x00000043u;
goto P_0c010fb0;
P_0c010fb0: /* original 6043, guest PC 0x0c010fb0 */
if(!s->budget--) { s->failed_pc=0x0c010fb0u; return 0; }
r[0]=r[4];
goto P_0c010fb2;
P_0c010fb2: /* original 8038, guest PC 0x0c010fb2 */
if(!s->budget--) { s->failed_pc=0x0c010fb2u; return 0; }
write(ram,r[3]+8,r[0],1);
goto P_0c010fb4;
P_0c010fb4: /* original 6352, guest PC 0x0c010fb4 */
if(!s->budget--) { s->failed_pc=0x0c010fb4u; return 0; }
tmp=read(ram,r[5],4);
r[3]=tmp;
goto P_0c010fb6;
P_0c010fb6: /* original ee00, guest PC 0x0c010fb6 */
if(!s->budget--) { s->failed_pc=0x0c010fb6u; return 0; }
r[14]=0x00000000u;
goto P_0c010fb8;
P_0c010fb8: /* original 60e3, guest PC 0x0c010fb8 */
if(!s->budget--) { s->failed_pc=0x0c010fb8u; return 0; }
r[0]=r[14];
goto P_0c010fba;
P_0c010fba: /* original 803c, guest PC 0x0c010fba */
if(!s->budget--) { s->failed_pc=0x0c010fbau; return 0; }
write(ram,r[3]+12,r[0],1);
goto P_0c010fbc;
P_0c010fbc: /* original 6352, guest PC 0x0c010fbc */
if(!s->budget--) { s->failed_pc=0x0c010fbcu; return 0; }
tmp=read(ram,r[5],4);
r[3]=tmp;
goto P_0c010fbe;
P_0c010fbe: /* original e010, guest PC 0x0c010fbe */
if(!s->budget--) { s->failed_pc=0x0c010fbeu; return 0; }
r[0]=0x00000010u;
goto P_0c010fc0;
P_0c010fc0: /* original 03e4, guest PC 0x0c010fc0 */
if(!s->budget--) { s->failed_pc=0x0c010fc0u; return 0; }
write(ram,r[3]+r[0],r[14],1);
goto P_0c010fc2;
P_0c010fc2: /* original 6352, guest PC 0x0c010fc2 */
if(!s->budget--) { s->failed_pc=0x0c010fc2u; return 0; }
tmp=read(ram,r[5],4);
r[3]=tmp;
goto P_0c010fc4;
P_0c010fc4: /* original e014, guest PC 0x0c010fc4 */
if(!s->budget--) { s->failed_pc=0x0c010fc4u; return 0; }
r[0]=0x00000014u;
goto P_0c010fc6;
P_0c010fc6: /* original 03e4, guest PC 0x0c010fc6 */
if(!s->budget--) { s->failed_pc=0x0c010fc6u; return 0; }
write(ram,r[3]+r[0],r[14],1);
goto P_0c010fc8;
P_0c010fc8: /* original 6352, guest PC 0x0c010fc8 */
if(!s->budget--) { s->failed_pc=0x0c010fc8u; return 0; }
tmp=read(ram,r[5],4);
r[3]=tmp;
goto P_0c010fca;
P_0c010fca: /* original e018, guest PC 0x0c010fca */
if(!s->budget--) { s->failed_pc=0x0c010fcau; return 0; }
r[0]=0x00000018u;
goto P_0c010fcc;
P_0c010fcc: /* original 03e4, guest PC 0x0c010fcc */
if(!s->budget--) { s->failed_pc=0x0c010fccu; return 0; }
write(ram,r[3]+r[0],r[14],1);
goto P_0c010fce;
P_0c010fce: /* original 6352, guest PC 0x0c010fce */
if(!s->budget--) { s->failed_pc=0x0c010fceu; return 0; }
tmp=read(ram,r[5],4);
r[3]=tmp;
goto P_0c010fd0;
P_0c010fd0: /* original e01c, guest PC 0x0c010fd0 */
if(!s->budget--) { s->failed_pc=0x0c010fd0u; return 0; }
r[0]=0x0000001cu;
goto P_0c010fd2;
P_0c010fd2: /* original e201, guest PC 0x0c010fd2 */
if(!s->budget--) { s->failed_pc=0x0c010fd2u; return 0; }
r[2]=0x00000001u;
goto P_0c010fd4;
P_0c010fd4: /* original 0324, guest PC 0x0c010fd4 */
if(!s->budget--) { s->failed_pc=0x0c010fd4u; return 0; }
write(ram,r[3]+r[0],r[2],1);
goto P_0c010fd6;
P_0c010fd6: /* original 6352, guest PC 0x0c010fd6 */
if(!s->budget--) { s->failed_pc=0x0c010fd6u; return 0; }
tmp=read(ram,r[5],4);
r[3]=tmp;
goto P_0c010fd8;
P_0c010fd8: /* original e020, guest PC 0x0c010fd8 */
if(!s->budget--) { s->failed_pc=0x0c010fd8u; return 0; }
r[0]=0x00000020u;
goto P_0c010fda;
P_0c010fda: /* original e240, guest PC 0x0c010fda */
if(!s->budget--) { s->failed_pc=0x0c010fdau; return 0; }
r[2]=0x00000040u;
goto P_0c010fdc;
P_0c010fdc: /* original 0324, guest PC 0x0c010fdc */
if(!s->budget--) { s->failed_pc=0x0c010fdcu; return 0; }
write(ram,r[3]+r[0],r[2],1);
goto P_0c010fde;
P_0c010fde: /* original 6352, guest PC 0x0c010fde */
if(!s->budget--) { s->failed_pc=0x0c010fdeu; return 0; }
tmp=read(ram,r[5],4);
r[3]=tmp;
goto P_0c010fe0;
P_0c010fe0: /* original e024, guest PC 0x0c010fe0 */
if(!s->budget--) { s->failed_pc=0x0c010fe0u; return 0; }
r[0]=0x00000024u;
goto P_0c010fe2;
P_0c010fe2: /* original 03e4, guest PC 0x0c010fe2 */
if(!s->budget--) { s->failed_pc=0x0c010fe2u; return 0; }
write(ram,r[3]+r[0],r[14],1);
goto P_0c010fe4;
P_0c010fe4: /* original 6352, guest PC 0x0c010fe4 */
if(!s->budget--) { s->failed_pc=0x0c010fe4u; return 0; }
tmp=read(ram,r[5],4);
r[3]=tmp;
goto P_0c010fe6;
P_0c010fe6: /* original e028, guest PC 0x0c010fe6 */
if(!s->budget--) { s->failed_pc=0x0c010fe6u; return 0; }
r[0]=0x00000028u;
goto P_0c010fe8;
P_0c010fe8: /* original e233, guest PC 0x0c010fe8 */
if(!s->budget--) { s->failed_pc=0x0c010fe8u; return 0; }
r[2]=0x00000033u;
goto P_0c010fea;
P_0c010fea: /* original 0324, guest PC 0x0c010fea */
if(!s->budget--) { s->failed_pc=0x0c010feau; return 0; }
write(ram,r[3]+r[0],r[2],1);
goto P_0c010fec;
P_0c010fec: /* original 6352, guest PC 0x0c010fec */
if(!s->budget--) { s->failed_pc=0x0c010fecu; return 0; }
tmp=read(ram,r[5],4);
r[3]=tmp;
goto P_0c010fee;
P_0c010fee: /* original e02c, guest PC 0x0c010fee */
if(!s->budget--) { s->failed_pc=0x0c010feeu; return 0; }
r[0]=0x0000002cu;
goto P_0c010ff0;
P_0c010ff0: /* original 03e4, guest PC 0x0c010ff0 */
if(!s->budget--) { s->failed_pc=0x0c010ff0u; return 0; }
write(ram,r[3]+r[0],r[14],1);
goto P_0c010ff2;
P_0c010ff2: /* original 6352, guest PC 0x0c010ff2 */
if(!s->budget--) { s->failed_pc=0x0c010ff2u; return 0; }
tmp=read(ram,r[5],4);
r[3]=tmp;
goto P_0c010ff4;
P_0c010ff4: /* original e030, guest PC 0x0c010ff4 */
if(!s->budget--) { s->failed_pc=0x0c010ff4u; return 0; }
r[0]=0x00000030u;
goto P_0c010ff6;
P_0c010ff6: /* original e204, guest PC 0x0c010ff6 */
if(!s->budget--) { s->failed_pc=0x0c010ff6u; return 0; }
r[2]=0x00000004u;
goto P_0c010ff8;
P_0c010ff8: /* original 0324, guest PC 0x0c010ff8 */
if(!s->budget--) { s->failed_pc=0x0c010ff8u; return 0; }
write(ram,r[3]+r[0],r[2],1);
goto P_0c010ffa;
P_0c010ffa: /* original 6352, guest PC 0x0c010ffa */
if(!s->budget--) { s->failed_pc=0x0c010ffau; return 0; }
tmp=read(ram,r[5],4);
r[3]=tmp;
goto P_0c010ffc;
P_0c010ffc: /* original e034, guest PC 0x0c010ffc */
if(!s->budget--) { s->failed_pc=0x0c010ffcu; return 0; }
r[0]=0x00000034u;
goto P_0c010ffe;
P_0c010ffe: /* original 03e4, guest PC 0x0c010ffe */
if(!s->budget--) { s->failed_pc=0x0c010ffeu; return 0; }
write(ram,r[3]+r[0],r[14],1);
goto P_0c011000;
P_0c011000: /* original 6352, guest PC 0x0c011000 */
if(!s->budget--) { s->failed_pc=0x0c011000u; return 0; }
tmp=read(ram,r[5],4);
r[3]=tmp;
goto P_0c011002;
P_0c011002: /* original e03c, guest PC 0x0c011002 */
if(!s->budget--) { s->failed_pc=0x0c011002u; return 0; }
r[0]=0x0000003cu;
goto P_0c011004;
P_0c011004: /* original 03e4, guest PC 0x0c011004 */
if(!s->budget--) { s->failed_pc=0x0c011004u; return 0; }
write(ram,r[3]+r[0],r[14],1);
goto P_0c011006;
P_0c011006: /* original 63d2, guest PC 0x0c011006 */
if(!s->budget--) { s->failed_pc=0x0c011006u; return 0; }
tmp=read(ram,r[13],4);
r[3]=tmp;
goto P_0c011008;
P_0c011008: /* original e014, guest PC 0x0c011008 */
if(!s->budget--) { s->failed_pc=0x0c011008u; return 0; }
r[0]=0x00000014u;
goto P_0c01100a;
P_0c01100a: /* original 0344, guest PC 0x0c01100a */
if(!s->budget--) { s->failed_pc=0x0c01100au; return 0; }
write(ram,r[3]+r[0],r[4],1);
goto P_0c01100c;
P_0c01100c: /* original d31b, guest PC 0x0c01100c */
if(!s->budget--) { s->failed_pc=0x0c01100cu; return 0; }
r[3]=read(ram,0x0c01107cu,4);
goto P_0c01100e;
P_0c01100e: /* original c700, guest PC 0x0c01100e */
if(!s->budget--) { s->failed_pc=0x0c01100eu; return 0; }
r[0]=0x0c011010u;
goto P_0c011010;
P_0c011010: /* original d21b, guest PC 0x0c011010 */
if(!s->budget--) { s->failed_pc=0x0c011010u; return 0; }
r[2]=read(ram,0x0c011080u,4);
goto P_0c011012;
P_0c011012: /* original 330c, guest PC 0x0c011012 */
if(!s->budget--) { s->failed_pc=0x0c011012u; return 0; }
r[3]+=r[0];
goto P_0c011014;
P_0c011014: /* original 6133, guest PC 0x0c011014 */
if(!s->budget--) { s->failed_pc=0x0c011014u; return 0; }
r[1]=r[3];
goto P_0c011016;
P_0c011016: /* original 212b, guest PC 0x0c011016 */
if(!s->budget--) { s->failed_pc=0x0c011016u; return 0; }
r[1]|=r[2];
goto P_0c011018;
P_0c011018: /* original 410b, guest PC 0x0c011018 */
if(!s->budget--) { s->failed_pc=0x0c011018u; return 0; }
target=r[1];
r[16]=code_base|0x0c01101cu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c01101cu) { target=s->pc; goto dispatch; }
goto P_0c01101c;
P_0c01101a: /* original 0009, guest PC 0x0c01101a */
if(!s->budget--) { s->failed_pc=0x0c01101au; return 0; }
goto P_0c01101c;
P_0c01101c: /* original 2008, guest PC 0x0c01101c */
if(!s->budget--) { s->failed_pc=0x0c01101cu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c01101e;
P_0c01101e: /* original 8901, guest PC 0x0c01101e */
if(!s->budget--) { s->failed_pc=0x0c01101eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c011024; }
goto P_0c011020;
P_0c011020: /* original a00c, guest PC 0x0c011020 */
if(!s->budget--) { s->failed_pc=0x0c011020u; return 0; }
r[0]=0x00000001u;
goto P_0c01103c;
P_0c011022: /* original e001, guest PC 0x0c011022 */
if(!s->budget--) { s->failed_pc=0x0c011022u; return 0; }
r[0]=0x00000001u;
goto P_0c011024;
P_0c011024: /* original 62d2, guest PC 0x0c011024 */
if(!s->budget--) { s->failed_pc=0x0c011024u; return 0; }
tmp=read(ram,r[13],4);
r[2]=tmp;
goto P_0c011026;
P_0c011026: /* original e03c, guest PC 0x0c011026 */
if(!s->budget--) { s->failed_pc=0x0c011026u; return 0; }
r[0]=0x0000003cu;
goto P_0c011028;
P_0c011028: /* original 02e4, guest PC 0x0c011028 */
if(!s->budget--) { s->failed_pc=0x0c011028u; return 0; }
write(ram,r[2]+r[0],r[14],1);
goto P_0c01102a;
P_0c01102a: /* original d316, guest PC 0x0c01102a */
if(!s->budget--) { s->failed_pc=0x0c01102au; return 0; }
r[3]=read(ram,0x0c011084u,4);
goto P_0c01102c;
P_0c01102c: /* original c700, guest PC 0x0c01102c */
if(!s->budget--) { s->failed_pc=0x0c01102cu; return 0; }
r[0]=0x0c011030u;
goto P_0c01102e;
P_0c01102e: /* original 330c, guest PC 0x0c01102e */
if(!s->budget--) { s->failed_pc=0x0c01102eu; return 0; }
r[3]+=r[0];
goto P_0c011030;
P_0c011030: /* original d213, guest PC 0x0c011030 */
if(!s->budget--) { s->failed_pc=0x0c011030u; return 0; }
r[2]=read(ram,0x0c011080u,4);
goto P_0c011032;
P_0c011032: /* original 6133, guest PC 0x0c011032 */
if(!s->budget--) { s->failed_pc=0x0c011032u; return 0; }
r[1]=r[3];
goto P_0c011034;
P_0c011034: /* original 212b, guest PC 0x0c011034 */
if(!s->budget--) { s->failed_pc=0x0c011034u; return 0; }
r[1]|=r[2];
goto P_0c011036;
P_0c011036: /* original 410b, guest PC 0x0c011036 */
if(!s->budget--) { s->failed_pc=0x0c011036u; return 0; }
target=r[1];
r[16]=code_base|0x0c01103au;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c01103au) { target=s->pc; goto dispatch; }
goto P_0c01103a;
P_0c011038: /* original 0009, guest PC 0x0c011038 */
if(!s->budget--) { s->failed_pc=0x0c011038u; return 0; }
goto P_0c01103a;
P_0c01103a: /* original e000, guest PC 0x0c01103a */
if(!s->budget--) { s->failed_pc=0x0c01103au; return 0; }
r[0]=0x00000000u;
goto P_0c01103c;
P_0c01103c: /* original 4f26, guest PC 0x0c01103c */
if(!s->budget--) { s->failed_pc=0x0c01103cu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c01103e;
P_0c01103e: /* original 6df6, guest PC 0x0c01103e */
if(!s->budget--) { s->failed_pc=0x0c01103eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c011040;
P_0c011040: /* original 000b, guest PC 0x0c011040 */
if(!s->budget--) { s->failed_pc=0x0c011040u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c011042: /* original 6ef6, guest PC 0x0c011042 */
if(!s->budget--) { s->failed_pc=0x0c011042u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c011044u,s,ram);
P_0c0113c2: /* original 4f22, guest PC 0x0c0113c2 */
if(!s->budget--) { s->failed_pc=0x0c0113c2u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0113c4;
P_0c0113c4: /* original 7fdc, guest PC 0x0c0113c4 */
if(!s->budget--) { s->failed_pc=0x0c0113c4u; return 0; }
r[15]+=0xffffffdcu;
goto P_0c0113c6;
P_0c0113c6: /* original 6040, guest PC 0x0c0113c6 */
if(!s->budget--) { s->failed_pc=0x0c0113c6u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[4],1);
r[0]=tmp;
goto P_0c0113c8;
P_0c0113c8: /* original 6943, guest PC 0x0c0113c8 */
if(!s->budget--) { s->failed_pc=0x0c0113c8u; return 0; }
r[9]=r[4];
goto P_0c0113ca;
P_0c0113ca: /* original 6843, guest PC 0x0c0113ca */
if(!s->budget--) { s->failed_pc=0x0c0113cau; return 0; }
r[8]=r[4];
goto P_0c0113cc;
P_0c0113cc: /* original 6743, guest PC 0x0c0113cc */
if(!s->budget--) { s->failed_pc=0x0c0113ccu; return 0; }
r[7]=r[4];
goto P_0c0113ce;
P_0c0113ce: /* original 6c43, guest PC 0x0c0113ce */
if(!s->budget--) { s->failed_pc=0x0c0113ceu; return 0; }
r[12]=r[4];
goto P_0c0113d0;
P_0c0113d0: /* original 6a43, guest PC 0x0c0113d0 */
if(!s->budget--) { s->failed_pc=0x0c0113d0u; return 0; }
r[10]=r[4];
goto P_0c0113d2;
P_0c0113d2: /* original 600c, guest PC 0x0c0113d2 */
if(!s->budget--) { s->failed_pc=0x0c0113d2u; return 0; }
r[0]=r[0]&255u;
goto P_0c0113d4;
P_0c0113d4: /* original de26, guest PC 0x0c0113d4 */
if(!s->budget--) { s->failed_pc=0x0c0113d4u; return 0; }
r[14]=read(ram,0x0c011470u,4);
goto P_0c0113d6;
P_0c0113d6: /* original 6643, guest PC 0x0c0113d6 */
if(!s->budget--) { s->failed_pc=0x0c0113d6u; return 0; }
r[6]=r[4];
goto P_0c0113d8;
P_0c0113d8: /* original 6df3, guest PC 0x0c0113d8 */
if(!s->budget--) { s->failed_pc=0x0c0113d8u; return 0; }
r[13]=r[15];
goto P_0c0113da;
P_0c0113da: /* original 8800, guest PC 0x0c0113da */
if(!s->budget--) { s->failed_pc=0x0c0113dau; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000000u)!=0);
goto P_0c0113dc;
P_0c0113dc: /* original 6b43, guest PC 0x0c0113dc */
if(!s->budget--) { s->failed_pc=0x0c0113dcu; return 0; }
r[11]=r[4];
goto P_0c0113de;
P_0c0113de: /* original 7c07, guest PC 0x0c0113de */
if(!s->budget--) { s->failed_pc=0x0c0113deu; return 0; }
r[12]+=0x00000007u;
goto P_0c0113e0;
P_0c0113e0: /* original 7706, guest PC 0x0c0113e0 */
if(!s->budget--) { s->failed_pc=0x0c0113e0u; return 0; }
r[7]+=0x00000006u;
goto P_0c0113e2;
P_0c0113e2: /* original 7604, guest PC 0x0c0113e2 */
if(!s->budget--) { s->failed_pc=0x0c0113e2u; return 0; }
r[6]+=0x00000004u;
goto P_0c0113e4;
P_0c0113e4: /* original e500, guest PC 0x0c0113e4 */
if(!s->budget--) { s->failed_pc=0x0c0113e4u; return 0; }
r[5]=0x00000000u;
goto P_0c0113e6;
P_0c0113e6: /* original 7d04, guest PC 0x0c0113e6 */
if(!s->budget--) { s->failed_pc=0x0c0113e6u; return 0; }
r[13]+=0x00000004u;
goto P_0c0113e8;
P_0c0113e8: /* original 7a05, guest PC 0x0c0113e8 */
if(!s->budget--) { s->failed_pc=0x0c0113e8u; return 0; }
r[10]+=0x00000005u;
goto P_0c0113ea;
P_0c0113ea: /* original 7903, guest PC 0x0c0113ea */
if(!s->budget--) { s->failed_pc=0x0c0113eau; return 0; }
r[9]+=0x00000003u;
goto P_0c0113ec;
P_0c0113ec: /* original 7802, guest PC 0x0c0113ec */
if(!s->budget--) { s->failed_pc=0x0c0113ecu; return 0; }
r[8]+=0x00000002u;
goto P_0c0113ee;
P_0c0113ee: /* original 8f02, guest PC 0x0c0113ee */
if(!s->budget--) { s->failed_pc=0x0c0113eeu; return 0; }
cond=r[17]&1u;
r[11]+=0x00000008u;
if(!cond) { goto P_0c0113f6; }
goto P_0c0113f2;
P_0c0113f0: /* original 7b08, guest PC 0x0c0113f0 */
if(!s->budget--) { s->failed_pc=0x0c0113f0u; return 0; }
r[11]+=0x00000008u;
goto P_0c0113f2;
P_0c0113f2: /* original a0bb, guest PC 0x0c0113f2 */
if(!s->budget--) { s->failed_pc=0x0c0113f2u; return 0; }
goto P_0c01156c;
P_0c0113f4: /* original 0009, guest PC 0x0c0113f4 */
if(!s->budget--) { s->failed_pc=0x0c0113f4u; return 0; }
goto P_0c0113f6;
P_0c0113f6: /* original 8803, guest PC 0x0c0113f6 */
if(!s->budget--) { s->failed_pc=0x0c0113f6u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000003u)!=0);
goto P_0c0113f8;
P_0c0113f8: /* original 890f, guest PC 0x0c0113f8 */
if(!s->budget--) { s->failed_pc=0x0c0113f8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c01141a; }
goto P_0c0113fa;
P_0c0113fa: /* original 8812, guest PC 0x0c0113fa */
if(!s->budget--) { s->failed_pc=0x0c0113fau; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000012u)!=0);
goto P_0c0113fc;
P_0c0113fc: /* original 8924, guest PC 0x0c0113fc */
if(!s->budget--) { s->failed_pc=0x0c0113fcu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c011448; }
goto P_0c0113fe;
P_0c0113fe: /* original 881b, guest PC 0x0c0113fe */
if(!s->budget--) { s->failed_pc=0x0c0113feu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000001bu)!=0);
goto P_0c011400;
P_0c011400: /* original 8b01, guest PC 0x0c011400 */
if(!s->budget--) { s->failed_pc=0x0c011400u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c011406; }
goto P_0c011402;
P_0c011402: /* original a0b3, guest PC 0x0c011402 */
if(!s->budget--) { s->failed_pc=0x0c011402u; return 0; }
goto P_0c01156c;
P_0c011404: /* original 0009, guest PC 0x0c011404 */
if(!s->budget--) { s->failed_pc=0x0c011404u; return 0; }
goto P_0c011406;
P_0c011406: /* original 8825, guest PC 0x0c011406 */
if(!s->budget--) { s->failed_pc=0x0c011406u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000025u)!=0);
goto P_0c011408;
P_0c011408: /* original 8b01, guest PC 0x0c011408 */
if(!s->budget--) { s->failed_pc=0x0c011408u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c01140e; }
goto P_0c01140a;
P_0c01140a: /* original a0a1, guest PC 0x0c01140a */
if(!s->budget--) { s->failed_pc=0x0c01140au; return 0; }
goto P_0c011550;
P_0c01140c: /* original 0009, guest PC 0x0c01140c */
if(!s->budget--) { s->failed_pc=0x0c01140cu; return 0; }
goto P_0c01140e;
P_0c01140e: /* original 8828, guest PC 0x0c01140e */
if(!s->budget--) { s->failed_pc=0x0c01140eu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000028u)!=0);
goto P_0c011410;
P_0c011410: /* original 8952, guest PC 0x0c011410 */
if(!s->budget--) { s->failed_pc=0x0c011410u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0114b8; }
goto P_0c011412;
P_0c011412: /* original 882a, guest PC 0x0c011412 */
if(!s->budget--) { s->failed_pc=0x0c011412u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000002au)!=0);
goto P_0c011414;
P_0c011414: /* original 8976, guest PC 0x0c011414 */
if(!s->budget--) { s->failed_pc=0x0c011414u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c011504; }
goto P_0c011416;
P_0c011416: /* original a0a9, guest PC 0x0c011416 */
if(!s->budget--) { s->failed_pc=0x0c011416u; return 0; }
goto P_0c01156c;
P_0c011418: /* original 0009, guest PC 0x0c011418 */
if(!s->budget--) { s->failed_pc=0x0c011418u; return 0; }
goto P_0c01141a;
P_0c01141a: /* original e420, guest PC 0x0c01141a */
if(!s->budget--) { s->failed_pc=0x0c01141au; return 0; }
r[4]=0x00000020u;
goto P_0c01141c;
P_0c01141c: /* original 67d3, guest PC 0x0c01141c */
if(!s->budget--) { s->failed_pc=0x0c01141cu; return 0; }
r[7]=r[13];
goto P_0c01141e;
P_0c01141e: /* original 4410, guest PC 0x0c01141e */
if(!s->budget--) { s->failed_pc=0x0c01141eu; return 0; }
--r[4];
r[17]=(r[17]&~1u)|((r[4]==0)!=0);
goto P_0c011420;
P_0c011420: /* original 2750, guest PC 0x0c011420 */
if(!s->budget--) { s->failed_pc=0x0c011420u; return 0; }
write(ram,r[7],r[5],1);
goto P_0c011422;
P_0c011422: /* original 8ffc, guest PC 0x0c011422 */
if(!s->budget--) { s->failed_pc=0x0c011422u; return 0; }
cond=r[17]&1u;
r[7]+=0x00000001u;
if(!cond) { goto P_0c01141e; }
goto P_0c011426;
P_0c011424: /* original 7701, guest PC 0x0c011424 */
if(!s->budget--) { s->failed_pc=0x0c011424u; return 0; }
r[7]+=0x00000001u;
goto P_0c011426;
P_0c011426: /* original 6460, guest PC 0x0c011426 */
if(!s->budget--) { s->failed_pc=0x0c011426u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[6],1);
r[4]=tmp;
goto P_0c011428;
P_0c011428: /* original e200, guest PC 0x0c011428 */
if(!s->budget--) { s->failed_pc=0x0c011428u; return 0; }
r[2]=0x00000000u;
goto P_0c01142a;
P_0c01142a: /* original 644c, guest PC 0x0c01142a */
if(!s->budget--) { s->failed_pc=0x0c01142au; return 0; }
r[4]=r[4]&255u;
goto P_0c01142c;
P_0c01142c: /* original 3426, guest PC 0x0c01142c */
if(!s->budget--) { s->failed_pc=0x0c01142cu; return 0; }
r[17]=(r[17]&~1u)|((r[4]>r[2])!=0);
goto P_0c01142e;
P_0c01142e: /* original 8901, guest PC 0x0c01142e */
if(!s->budget--) { s->failed_pc=0x0c01142eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c011434; }
goto P_0c011430;
P_0c011430: /* original a09c, guest PC 0x0c011430 */
if(!s->budget--) { s->failed_pc=0x0c011430u; return 0; }
goto P_0c01156c;
P_0c011432: /* original 0009, guest PC 0x0c011432 */
if(!s->budget--) { s->failed_pc=0x0c011432u; return 0; }
goto P_0c011434;
P_0c011434: /* original d11d, guest PC 0x0c011434 */
if(!s->budget--) { s->failed_pc=0x0c011434u; return 0; }
r[1]=read(ram,0x0c0114acu,4);
goto P_0c011436;
P_0c011436: /* original c700, guest PC 0x0c011436 */
if(!s->budget--) { s->failed_pc=0x0c011436u; return 0; }
r[0]=0x0c011438u;
goto P_0c011438;
P_0c011438: /* original 310c, guest PC 0x0c011438 */
if(!s->budget--) { s->failed_pc=0x0c011438u; return 0; }
r[1]+=r[0];
goto P_0c01143a;
P_0c01143a: /* original 6543, guest PC 0x0c01143a */
if(!s->budget--) { s->failed_pc=0x0c01143au; return 0; }
r[5]=r[4];
goto P_0c01143c;
P_0c01143c: /* original 6313, guest PC 0x0c01143c */
if(!s->budget--) { s->failed_pc=0x0c01143cu; return 0; }
r[3]=r[1];
goto P_0c01143e;
P_0c01143e: /* original 2e3b, guest PC 0x0c01143e */
if(!s->budget--) { s->failed_pc=0x0c01143eu; return 0; }
r[14]|=r[3];
goto P_0c011440;
P_0c011440: /* original 4e0b, guest PC 0x0c011440 */
if(!s->budget--) { s->failed_pc=0x0c011440u; return 0; }
target=r[14];
r[16]=code_base|0x0c011444u;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c011444u) { target=s->pc; goto dispatch; }
goto P_0c011444;
P_0c011442: /* original 64d3, guest PC 0x0c011442 */
if(!s->budget--) { s->failed_pc=0x0c011442u; return 0; }
r[4]=r[13];
goto P_0c011444;
P_0c011444: /* original a092, guest PC 0x0c011444 */
if(!s->budget--) { s->failed_pc=0x0c011444u; return 0; }
goto P_0c01156c;
P_0c011446: /* original 0009, guest PC 0x0c011446 */
if(!s->budget--) { s->failed_pc=0x0c011446u; return 0; }
goto P_0c011448;
P_0c011448: /* original 6560, guest PC 0x0c011448 */
if(!s->budget--) { s->failed_pc=0x0c011448u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[6],1);
r[5]=tmp;
goto P_0c01144a;
P_0c01144a: /* original e300, guest PC 0x0c01144a */
if(!s->budget--) { s->failed_pc=0x0c01144au; return 0; }
r[3]=0x00000000u;
goto P_0c01144c;
P_0c01144c: /* original 655c, guest PC 0x0c01144c */
if(!s->budget--) { s->failed_pc=0x0c01144cu; return 0; }
r[5]=r[5]&255u;
goto P_0c01144e;
P_0c01144e: /* original 3536, guest PC 0x0c01144e */
if(!s->budget--) { s->failed_pc=0x0c01144eu; return 0; }
r[17]=(r[17]&~1u)|((r[5]>r[3])!=0);
goto P_0c011450;
P_0c011450: /* original 8901, guest PC 0x0c011450 */
if(!s->budget--) { s->failed_pc=0x0c011450u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c011456; }
goto P_0c011452;
P_0c011452: /* original a08b, guest PC 0x0c011452 */
if(!s->budget--) { s->failed_pc=0x0c011452u; return 0; }
goto P_0c01156c;
P_0c011454: /* original 0009, guest PC 0x0c011454 */
if(!s->budget--) { s->failed_pc=0x0c011454u; return 0; }
goto P_0c011456;
P_0c011456: /* original d116, guest PC 0x0c011456 */
if(!s->budget--) { s->failed_pc=0x0c011456u; return 0; }
r[1]=read(ram,0x0c0114b0u,4);
goto P_0c011458;
P_0c011458: /* original c700, guest PC 0x0c011458 */
if(!s->budget--) { s->failed_pc=0x0c011458u; return 0; }
r[0]=0x0c01145cu;
goto P_0c01145a;
P_0c01145a: /* original 310c, guest PC 0x0c01145a */
if(!s->budget--) { s->failed_pc=0x0c01145au; return 0; }
r[1]+=r[0];
goto P_0c01145c;
P_0c01145c: /* original 6213, guest PC 0x0c01145c */
if(!s->budget--) { s->failed_pc=0x0c01145cu; return 0; }
r[2]=r[1];
goto P_0c01145e;
P_0c01145e: /* original d115, guest PC 0x0c01145e */
if(!s->budget--) { s->failed_pc=0x0c01145eu; return 0; }
r[1]=read(ram,0x0c0114b4u,4);
goto P_0c011460;
P_0c011460: /* original 2e2b, guest PC 0x0c011460 */
if(!s->budget--) { s->failed_pc=0x0c011460u; return 0; }
r[14]|=r[2];
goto P_0c011462;
P_0c011462: /* original 4e0b, guest PC 0x0c011462 */
if(!s->budget--) { s->failed_pc=0x0c011462u; return 0; }
target=r[14];
r[16]=code_base|0x0c011466u;
tmp=read(ram,r[1],4);
r[4]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c011466u) { target=s->pc; goto dispatch; }
goto P_0c011466;
P_0c011464: /* original 6412, guest PC 0x0c011464 */
if(!s->budget--) { s->failed_pc=0x0c011464u; return 0; }
tmp=read(ram,r[1],4);
r[4]=tmp;
goto P_0c011466;
P_0c011466: /* original a081, guest PC 0x0c011466 */
if(!s->budget--) { s->failed_pc=0x0c011466u; return 0; }
goto P_0c01156c;
P_0c011468: /* original 0009, guest PC 0x0c011468 */
if(!s->budget--) { s->failed_pc=0x0c011468u; return 0; }
return vf3_matrix_family(0x0c01146au,s,ram);
P_0c0114b8: /* original 6380, guest PC 0x0c0114b8 */
if(!s->budget--) { s->failed_pc=0x0c0114b8u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[8],1);
r[3]=tmp;
goto P_0c0114ba;
P_0c0114ba: /* original 6290, guest PC 0x0c0114ba */
if(!s->budget--) { s->failed_pc=0x0c0114bau; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[9],1);
r[2]=tmp;
goto P_0c0114bc;
P_0c0114bc: /* original 633c, guest PC 0x0c0114bc */
if(!s->budget--) { s->failed_pc=0x0c0114bcu; return 0; }
r[3]=r[3]&255u;
goto P_0c0114be;
P_0c0114be: /* original 6160, guest PC 0x0c0114be */
if(!s->budget--) { s->failed_pc=0x0c0114beu; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[6],1);
r[1]=tmp;
goto P_0c0114c0;
P_0c0114c0: /* original 622c, guest PC 0x0c0114c0 */
if(!s->budget--) { s->failed_pc=0x0c0114c0u; return 0; }
r[2]=r[2]&255u;
goto P_0c0114c2;
P_0c0114c2: /* original 4328, guest PC 0x0c0114c2 */
if(!s->budget--) { s->failed_pc=0x0c0114c2u; return 0; }
r[3]<<=16;
goto P_0c0114c4;
P_0c0114c4: /* original 4228, guest PC 0x0c0114c4 */
if(!s->budget--) { s->failed_pc=0x0c0114c4u; return 0; }
r[2]<<=16;
goto P_0c0114c6;
P_0c0114c6: /* original 4318, guest PC 0x0c0114c6 */
if(!s->budget--) { s->failed_pc=0x0c0114c6u; return 0; }
r[3]<<=8;
goto P_0c0114c8;
P_0c0114c8: /* original 332c, guest PC 0x0c0114c8 */
if(!s->budget--) { s->failed_pc=0x0c0114c8u; return 0; }
r[3]+=r[2];
goto P_0c0114ca;
P_0c0114ca: /* original 62a0, guest PC 0x0c0114ca */
if(!s->budget--) { s->failed_pc=0x0c0114cau; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[10],1);
r[2]=tmp;
goto P_0c0114cc;
P_0c0114cc: /* original 611c, guest PC 0x0c0114cc */
if(!s->budget--) { s->failed_pc=0x0c0114ccu; return 0; }
r[1]=r[1]&255u;
goto P_0c0114ce;
P_0c0114ce: /* original 4118, guest PC 0x0c0114ce */
if(!s->budget--) { s->failed_pc=0x0c0114ceu; return 0; }
r[1]<<=8;
goto P_0c0114d0;
P_0c0114d0: /* original 622c, guest PC 0x0c0114d0 */
if(!s->budget--) { s->failed_pc=0x0c0114d0u; return 0; }
r[2]=r[2]&255u;
goto P_0c0114d2;
P_0c0114d2: /* original 331c, guest PC 0x0c0114d2 */
if(!s->budget--) { s->failed_pc=0x0c0114d2u; return 0; }
r[3]+=r[1];
goto P_0c0114d4;
P_0c0114d4: /* original 332c, guest PC 0x0c0114d4 */
if(!s->budget--) { s->failed_pc=0x0c0114d4u; return 0; }
r[3]+=r[2];
goto P_0c0114d6;
P_0c0114d6: /* original 2f32, guest PC 0x0c0114d6 */
if(!s->budget--) { s->failed_pc=0x0c0114d6u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c0114d8;
P_0c0114d8: /* original 6570, guest PC 0x0c0114d8 */
if(!s->budget--) { s->failed_pc=0x0c0114d8u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[7],1);
r[5]=tmp;
goto P_0c0114da;
P_0c0114da: /* original 62c0, guest PC 0x0c0114da */
if(!s->budget--) { s->failed_pc=0x0c0114dau; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[12],1);
r[2]=tmp;
goto P_0c0114dc;
P_0c0114dc: /* original 61b0, guest PC 0x0c0114dc */
if(!s->budget--) { s->failed_pc=0x0c0114dcu; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[11],1);
r[1]=tmp;
goto P_0c0114de;
P_0c0114de: /* original 655c, guest PC 0x0c0114de */
if(!s->budget--) { s->failed_pc=0x0c0114deu; return 0; }
r[5]=r[5]&255u;
goto P_0c0114e0;
P_0c0114e0: /* original 622c, guest PC 0x0c0114e0 */
if(!s->budget--) { s->failed_pc=0x0c0114e0u; return 0; }
r[2]=r[2]&255u;
goto P_0c0114e2;
P_0c0114e2: /* original 4218, guest PC 0x0c0114e2 */
if(!s->budget--) { s->failed_pc=0x0c0114e2u; return 0; }
r[2]<<=8;
goto P_0c0114e4;
P_0c0114e4: /* original 4528, guest PC 0x0c0114e4 */
if(!s->budget--) { s->failed_pc=0x0c0114e4u; return 0; }
r[5]<<=16;
goto P_0c0114e6;
P_0c0114e6: /* original 611c, guest PC 0x0c0114e6 */
if(!s->budget--) { s->failed_pc=0x0c0114e6u; return 0; }
r[1]=r[1]&255u;
goto P_0c0114e8;
P_0c0114e8: /* original 352c, guest PC 0x0c0114e8 */
if(!s->budget--) { s->failed_pc=0x0c0114e8u; return 0; }
r[5]+=r[2];
goto P_0c0114ea;
P_0c0114ea: /* original e200, guest PC 0x0c0114ea */
if(!s->budget--) { s->failed_pc=0x0c0114eau; return 0; }
r[2]=0x00000000u;
goto P_0c0114ec;
P_0c0114ec: /* original 351c, guest PC 0x0c0114ec */
if(!s->budget--) { s->failed_pc=0x0c0114ecu; return 0; }
r[5]+=r[1];
goto P_0c0114ee;
P_0c0114ee: /* original 3526, guest PC 0x0c0114ee */
if(!s->budget--) { s->failed_pc=0x0c0114eeu; return 0; }
r[17]=(r[17]&~1u)|((r[5]>r[2])!=0);
goto P_0c0114f0;
P_0c0114f0: /* original 8b3c, guest PC 0x0c0114f0 */
if(!s->budget--) { s->failed_pc=0x0c0114f0u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c01156c; }
goto P_0c0114f2;
P_0c0114f2: /* original d12c, guest PC 0x0c0114f2 */
if(!s->budget--) { s->failed_pc=0x0c0114f2u; return 0; }
r[1]=read(ram,0x0c0115a4u,4);
goto P_0c0114f4;
P_0c0114f4: /* original c700, guest PC 0x0c0114f4 */
if(!s->budget--) { s->failed_pc=0x0c0114f4u; return 0; }
r[0]=0x0c0114f8u;
goto P_0c0114f6;
P_0c0114f6: /* original 310c, guest PC 0x0c0114f6 */
if(!s->budget--) { s->failed_pc=0x0c0114f6u; return 0; }
r[1]+=r[0];
goto P_0c0114f8;
P_0c0114f8: /* original 6013, guest PC 0x0c0114f8 */
if(!s->budget--) { s->failed_pc=0x0c0114f8u; return 0; }
r[0]=r[1];
goto P_0c0114fa;
P_0c0114fa: /* original 2e0b, guest PC 0x0c0114fa */
if(!s->budget--) { s->failed_pc=0x0c0114fau; return 0; }
r[14]|=r[0];
goto P_0c0114fc;
P_0c0114fc: /* original 4e0b, guest PC 0x0c0114fc */
if(!s->budget--) { s->failed_pc=0x0c0114fcu; return 0; }
target=r[14];
r[16]=code_base|0x0c011500u;
r[4]=r[3];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c011500u) { target=s->pc; goto dispatch; }
goto P_0c011500;
P_0c0114fe: /* original 6433, guest PC 0x0c0114fe */
if(!s->budget--) { s->failed_pc=0x0c0114feu; return 0; }
r[4]=r[3];
goto P_0c011500;
P_0c011500: /* original a034, guest PC 0x0c011500 */
if(!s->budget--) { s->failed_pc=0x0c011500u; return 0; }
goto P_0c01156c;
P_0c011502: /* original 0009, guest PC 0x0c011502 */
if(!s->budget--) { s->failed_pc=0x0c011502u; return 0; }
goto P_0c011504;
P_0c011504: /* original 6280, guest PC 0x0c011504 */
if(!s->budget--) { s->failed_pc=0x0c011504u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[8],1);
r[2]=tmp;
goto P_0c011506;
P_0c011506: /* original 6390, guest PC 0x0c011506 */
if(!s->budget--) { s->failed_pc=0x0c011506u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[9],1);
r[3]=tmp;
goto P_0c011508;
P_0c011508: /* original 622c, guest PC 0x0c011508 */
if(!s->budget--) { s->failed_pc=0x0c011508u; return 0; }
r[2]=r[2]&255u;
goto P_0c01150a;
P_0c01150a: /* original 6160, guest PC 0x0c01150a */
if(!s->budget--) { s->failed_pc=0x0c01150au; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[6],1);
r[1]=tmp;
goto P_0c01150c;
P_0c01150c: /* original 633c, guest PC 0x0c01150c */
if(!s->budget--) { s->failed_pc=0x0c01150cu; return 0; }
r[3]=r[3]&255u;
goto P_0c01150e;
P_0c01150e: /* original 4228, guest PC 0x0c01150e */
if(!s->budget--) { s->failed_pc=0x0c01150eu; return 0; }
r[2]<<=16;
goto P_0c011510;
P_0c011510: /* original 4328, guest PC 0x0c011510 */
if(!s->budget--) { s->failed_pc=0x0c011510u; return 0; }
r[3]<<=16;
goto P_0c011512;
P_0c011512: /* original 4218, guest PC 0x0c011512 */
if(!s->budget--) { s->failed_pc=0x0c011512u; return 0; }
r[2]<<=8;
goto P_0c011514;
P_0c011514: /* original 323c, guest PC 0x0c011514 */
if(!s->budget--) { s->failed_pc=0x0c011514u; return 0; }
r[2]+=r[3];
goto P_0c011516;
P_0c011516: /* original 63a0, guest PC 0x0c011516 */
if(!s->budget--) { s->failed_pc=0x0c011516u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[10],1);
r[3]=tmp;
goto P_0c011518;
P_0c011518: /* original 611c, guest PC 0x0c011518 */
if(!s->budget--) { s->failed_pc=0x0c011518u; return 0; }
r[1]=r[1]&255u;
goto P_0c01151a;
P_0c01151a: /* original 4118, guest PC 0x0c01151a */
if(!s->budget--) { s->failed_pc=0x0c01151au; return 0; }
r[1]<<=8;
goto P_0c01151c;
P_0c01151c: /* original 633c, guest PC 0x0c01151c */
if(!s->budget--) { s->failed_pc=0x0c01151cu; return 0; }
r[3]=r[3]&255u;
goto P_0c01151e;
P_0c01151e: /* original 321c, guest PC 0x0c01151e */
if(!s->budget--) { s->failed_pc=0x0c01151eu; return 0; }
r[2]+=r[1];
goto P_0c011520;
P_0c011520: /* original 323c, guest PC 0x0c011520 */
if(!s->budget--) { s->failed_pc=0x0c011520u; return 0; }
r[2]+=r[3];
goto P_0c011522;
P_0c011522: /* original 2f22, guest PC 0x0c011522 */
if(!s->budget--) { s->failed_pc=0x0c011522u; return 0; }
write(ram,r[15],r[2],4);
goto P_0c011524;
P_0c011524: /* original 6570, guest PC 0x0c011524 */
if(!s->budget--) { s->failed_pc=0x0c011524u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[7],1);
r[5]=tmp;
goto P_0c011526;
P_0c011526: /* original 63c0, guest PC 0x0c011526 */
if(!s->budget--) { s->failed_pc=0x0c011526u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[12],1);
r[3]=tmp;
goto P_0c011528;
P_0c011528: /* original 61b0, guest PC 0x0c011528 */
if(!s->budget--) { s->failed_pc=0x0c011528u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[11],1);
r[1]=tmp;
goto P_0c01152a;
P_0c01152a: /* original 655c, guest PC 0x0c01152a */
if(!s->budget--) { s->failed_pc=0x0c01152au; return 0; }
r[5]=r[5]&255u;
goto P_0c01152c;
P_0c01152c: /* original 633c, guest PC 0x0c01152c */
if(!s->budget--) { s->failed_pc=0x0c01152cu; return 0; }
r[3]=r[3]&255u;
goto P_0c01152e;
P_0c01152e: /* original 4318, guest PC 0x0c01152e */
if(!s->budget--) { s->failed_pc=0x0c01152eu; return 0; }
r[3]<<=8;
goto P_0c011530;
P_0c011530: /* original 4528, guest PC 0x0c011530 */
if(!s->budget--) { s->failed_pc=0x0c011530u; return 0; }
r[5]<<=16;
goto P_0c011532;
P_0c011532: /* original 611c, guest PC 0x0c011532 */
if(!s->budget--) { s->failed_pc=0x0c011532u; return 0; }
r[1]=r[1]&255u;
goto P_0c011534;
P_0c011534: /* original 353c, guest PC 0x0c011534 */
if(!s->budget--) { s->failed_pc=0x0c011534u; return 0; }
r[5]+=r[3];
goto P_0c011536;
P_0c011536: /* original e300, guest PC 0x0c011536 */
if(!s->budget--) { s->failed_pc=0x0c011536u; return 0; }
r[3]=0x00000000u;
goto P_0c011538;
P_0c011538: /* original 351c, guest PC 0x0c011538 */
if(!s->budget--) { s->failed_pc=0x0c011538u; return 0; }
r[5]+=r[1];
goto P_0c01153a;
P_0c01153a: /* original 3536, guest PC 0x0c01153a */
if(!s->budget--) { s->failed_pc=0x0c01153au; return 0; }
r[17]=(r[17]&~1u)|((r[5]>r[3])!=0);
goto P_0c01153c;
P_0c01153c: /* original 8b16, guest PC 0x0c01153c */
if(!s->budget--) { s->failed_pc=0x0c01153cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c01156c; }
goto P_0c01153e;
P_0c01153e: /* original d11a, guest PC 0x0c01153e */
if(!s->budget--) { s->failed_pc=0x0c01153eu; return 0; }
r[1]=read(ram,0x0c0115a8u,4);
goto P_0c011540;
P_0c011540: /* original c700, guest PC 0x0c011540 */
if(!s->budget--) { s->failed_pc=0x0c011540u; return 0; }
r[0]=0x0c011544u;
goto P_0c011542;
P_0c011542: /* original 310c, guest PC 0x0c011542 */
if(!s->budget--) { s->failed_pc=0x0c011542u; return 0; }
r[1]+=r[0];
goto P_0c011544;
P_0c011544: /* original 6013, guest PC 0x0c011544 */
if(!s->budget--) { s->failed_pc=0x0c011544u; return 0; }
r[0]=r[1];
goto P_0c011546;
P_0c011546: /* original 2e0b, guest PC 0x0c011546 */
if(!s->budget--) { s->failed_pc=0x0c011546u; return 0; }
r[14]|=r[0];
goto P_0c011548;
P_0c011548: /* original 4e0b, guest PC 0x0c011548 */
if(!s->budget--) { s->failed_pc=0x0c011548u; return 0; }
target=r[14];
r[16]=code_base|0x0c01154cu;
r[4]=r[2];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c01154cu) { target=s->pc; goto dispatch; }
goto P_0c01154c;
P_0c01154a: /* original 6423, guest PC 0x0c01154a */
if(!s->budget--) { s->failed_pc=0x0c01154au; return 0; }
r[4]=r[2];
goto P_0c01154c;
P_0c01154c: /* original a00e, guest PC 0x0c01154c */
if(!s->budget--) { s->failed_pc=0x0c01154cu; return 0; }
goto P_0c01156c;
P_0c01154e: /* original 0009, guest PC 0x0c01154e */
if(!s->budget--) { s->failed_pc=0x0c01154eu; return 0; }
goto P_0c011550;
P_0c011550: /* original e420, guest PC 0x0c011550 */
if(!s->budget--) { s->failed_pc=0x0c011550u; return 0; }
r[4]=0x00000020u;
goto P_0c011552;
P_0c011552: /* original 66d3, guest PC 0x0c011552 */
if(!s->budget--) { s->failed_pc=0x0c011552u; return 0; }
r[6]=r[13];
goto P_0c011554;
P_0c011554: /* original 4410, guest PC 0x0c011554 */
if(!s->budget--) { s->failed_pc=0x0c011554u; return 0; }
--r[4];
r[17]=(r[17]&~1u)|((r[4]==0)!=0);
goto P_0c011556;
P_0c011556: /* original 2650, guest PC 0x0c011556 */
if(!s->budget--) { s->failed_pc=0x0c011556u; return 0; }
write(ram,r[6],r[5],1);
goto P_0c011558;
P_0c011558: /* original 8ffc, guest PC 0x0c011558 */
if(!s->budget--) { s->failed_pc=0x0c011558u; return 0; }
cond=r[17]&1u;
r[6]+=0x00000001u;
if(!cond) { goto P_0c011554; }
goto P_0c01155c;
P_0c01155a: /* original 7601, guest PC 0x0c01155a */
if(!s->budget--) { s->failed_pc=0x0c01155au; return 0; }
r[6]+=0x00000001u;
goto P_0c01155c;
P_0c01155c: /* original d213, guest PC 0x0c01155c */
if(!s->budget--) { s->failed_pc=0x0c01155cu; return 0; }
r[2]=read(ram,0x0c0115acu,4);
goto P_0c01155e;
P_0c01155e: /* original c700, guest PC 0x0c01155e */
if(!s->budget--) { s->failed_pc=0x0c01155eu; return 0; }
r[0]=0x0c011560u;
goto P_0c011560;
P_0c011560: /* original 320c, guest PC 0x0c011560 */
if(!s->budget--) { s->failed_pc=0x0c011560u; return 0; }
r[2]+=r[0];
goto P_0c011562;
P_0c011562: /* original 6323, guest PC 0x0c011562 */
if(!s->budget--) { s->failed_pc=0x0c011562u; return 0; }
r[3]=r[2];
goto P_0c011564;
P_0c011564: /* original e508, guest PC 0x0c011564 */
if(!s->budget--) { s->failed_pc=0x0c011564u; return 0; }
r[5]=0x00000008u;
goto P_0c011566;
P_0c011566: /* original 2e3b, guest PC 0x0c011566 */
if(!s->budget--) { s->failed_pc=0x0c011566u; return 0; }
r[14]|=r[3];
goto P_0c011568;
P_0c011568: /* original 4e0b, guest PC 0x0c011568 */
if(!s->budget--) { s->failed_pc=0x0c011568u; return 0; }
target=r[14];
r[16]=code_base|0x0c01156cu;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c01156cu) { target=s->pc; goto dispatch; }
goto P_0c01156c;
P_0c01156a: /* original 64d3, guest PC 0x0c01156a */
if(!s->budget--) { s->failed_pc=0x0c01156au; return 0; }
r[4]=r[13];
goto P_0c01156c;
P_0c01156c: /* original 7f24, guest PC 0x0c01156c */
if(!s->budget--) { s->failed_pc=0x0c01156cu; return 0; }
r[15]+=0x00000024u;
goto P_0c01156e;
P_0c01156e: /* original 4f26, guest PC 0x0c01156e */
if(!s->budget--) { s->failed_pc=0x0c01156eu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c011570;
P_0c011570: /* original 68f6, guest PC 0x0c011570 */
if(!s->budget--) { s->failed_pc=0x0c011570u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c011572;
P_0c011572: /* original 69f6, guest PC 0x0c011572 */
if(!s->budget--) { s->failed_pc=0x0c011572u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c011574;
P_0c011574: /* original 6af6, guest PC 0x0c011574 */
if(!s->budget--) { s->failed_pc=0x0c011574u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c011576;
P_0c011576: /* original 6bf6, guest PC 0x0c011576 */
if(!s->budget--) { s->failed_pc=0x0c011576u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c011578;
P_0c011578: /* original 6cf6, guest PC 0x0c011578 */
if(!s->budget--) { s->failed_pc=0x0c011578u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c01157a;
P_0c01157a: /* original 6df6, guest PC 0x0c01157a */
if(!s->budget--) { s->failed_pc=0x0c01157au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c01157c;
P_0c01157c: /* original 000b, guest PC 0x0c01157c */
if(!s->budget--) { s->failed_pc=0x0c01157cu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c01157e: /* original 6ef6, guest PC 0x0c01157e */
if(!s->budget--) { s->failed_pc=0x0c01157eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c011580;
P_0c011580: /* original d20b, guest PC 0x0c011580 */
if(!s->budget--) { s->failed_pc=0x0c011580u; return 0; }
r[2]=read(ram,0x0c0115b0u,4);
goto P_0c011582;
P_0c011582: /* original 6043, guest PC 0x0c011582 */
if(!s->budget--) { s->failed_pc=0x0c011582u; return 0; }
r[0]=r[4];
goto P_0c011584;
P_0c011584: /* original 4009, guest PC 0x0c011584 */
if(!s->budget--) { s->failed_pc=0x0c011584u; return 0; }
r[0]>>=2;
goto P_0c011586;
P_0c011586: /* original 6322, guest PC 0x0c011586 */
if(!s->budget--) { s->failed_pc=0x0c011586u; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c011588;
P_0c011588: /* original e13c, guest PC 0x0c011588 */
if(!s->budget--) { s->failed_pc=0x0c011588u; return 0; }
r[1]=0x0000003cu;
goto P_0c01158a;
P_0c01158a: /* original 4009, guest PC 0x0c01158a */
if(!s->budget--) { s->failed_pc=0x0c01158au; return 0; }
r[0]>>=2;
goto P_0c01158c;
P_0c01158c: /* original 313c, guest PC 0x0c01158c */
if(!s->budget--) { s->failed_pc=0x0c01158cu; return 0; }
r[1]+=r[3];
goto P_0c01158e;
P_0c01158e: /* original cb80, guest PC 0x0c01158e */
if(!s->budget--) { s->failed_pc=0x0c01158eu; return 0; }
r[0]|=128u;
goto P_0c011590;
P_0c011590: /* original 2100, guest PC 0x0c011590 */
if(!s->budget--) { s->failed_pc=0x0c011590u; return 0; }
write(ram,r[1],r[0],1);
goto P_0c011592;
P_0c011592: /* original d108, guest PC 0x0c011592 */
if(!s->budget--) { s->failed_pc=0x0c011592u; return 0; }
r[1]=read(ram,0x0c0115b4u,4);
goto P_0c011594;
P_0c011594: /* original e00f, guest PC 0x0c011594 */
if(!s->budget--) { s->failed_pc=0x0c011594u; return 0; }
r[0]=0x0000000fu;
goto P_0c011596;
P_0c011596: /* original 2409, guest PC 0x0c011596 */
if(!s->budget--) { s->failed_pc=0x0c011596u; return 0; }
r[4]&=r[0];
goto P_0c011598;
P_0c011598: /* original 6312, guest PC 0x0c011598 */
if(!s->budget--) { s->failed_pc=0x0c011598u; return 0; }
tmp=read(ram,r[1],4);
r[3]=tmp;
goto P_0c01159a;
P_0c01159a: /* original 4408, guest PC 0x0c01159a */
if(!s->budget--) { s->failed_pc=0x0c01159au; return 0; }
r[4]<<=2;
goto P_0c01159c;
P_0c01159c: /* original 343c, guest PC 0x0c01159c */
if(!s->budget--) { s->failed_pc=0x0c01159cu; return 0; }
r[4]+=r[3];
goto P_0c01159e;
P_0c01159e: /* original 000b, guest PC 0x0c01159e */
if(!s->budget--) { s->failed_pc=0x0c01159eu; return 0; }
target=r[16];
write(ram,r[4],r[5],1);
s->pc=target; return ram->oob==0;
P_0c0115a0: /* original 2450, guest PC 0x0c0115a0 */
if(!s->budget--) { s->failed_pc=0x0c0115a0u; return 0; }
write(ram,r[4],r[5],1);
return vf3_matrix_family(0x0c0115a2u,s,ram);
P_0c0115c2: /* original 4f22, guest PC 0x0c0115c2 */
if(!s->budget--) { s->failed_pc=0x0c0115c2u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0115c4;
P_0c0115c4: /* original de5a, guest PC 0x0c0115c4 */
if(!s->budget--) { s->failed_pc=0x0c0115c4u; return 0; }
r[14]=read(ram,0x0c011730u,4);
goto P_0c0115c6;
P_0c0115c6: /* original 6db3, guest PC 0x0c0115c6 */
if(!s->budget--) { s->failed_pc=0x0c0115c6u; return 0; }
r[13]=r[11];
goto P_0c0115c8;
P_0c0115c8: /* original 9caa, guest PC 0x0c0115c8 */
if(!s->budget--) { s->failed_pc=0x0c0115c8u; return 0; }
r[12]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c011720u,2);
goto P_0c0115ca;
P_0c0115ca: /* original d35a, guest PC 0x0c0115ca */
if(!s->budget--) { s->failed_pc=0x0c0115cau; return 0; }
r[3]=read(ram,0x0c011734u,4);
goto P_0c0115cc;
P_0c0115cc: /* original c700, guest PC 0x0c0115cc */
if(!s->budget--) { s->failed_pc=0x0c0115ccu; return 0; }
r[0]=0x0c0115d0u;
goto P_0c0115ce;
P_0c0115ce: /* original 330c, guest PC 0x0c0115ce */
if(!s->budget--) { s->failed_pc=0x0c0115ceu; return 0; }
r[3]+=r[0];
goto P_0c0115d0;
P_0c0115d0: /* original 6233, guest PC 0x0c0115d0 */
if(!s->budget--) { s->failed_pc=0x0c0115d0u; return 0; }
r[2]=r[3];
goto P_0c0115d2;
P_0c0115d2: /* original e500, guest PC 0x0c0115d2 */
if(!s->budget--) { s->failed_pc=0x0c0115d2u; return 0; }
r[5]=0x00000000u;
goto P_0c0115d4;
P_0c0115d4: /* original 22eb, guest PC 0x0c0115d4 */
if(!s->budget--) { s->failed_pc=0x0c0115d4u; return 0; }
r[2]|=r[14];
goto P_0c0115d6;
P_0c0115d6: /* original 420b, guest PC 0x0c0115d6 */
if(!s->budget--) { s->failed_pc=0x0c0115d6u; return 0; }
target=r[2];
r[16]=code_base|0x0c0115dau;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0115dau) { target=s->pc; goto dispatch; }
goto P_0c0115da;
P_0c0115d8: /* original 64d3, guest PC 0x0c0115d8 */
if(!s->budget--) { s->failed_pc=0x0c0115d8u; return 0; }
r[4]=r[13];
goto P_0c0115da;
P_0c0115da: /* original 7d01, guest PC 0x0c0115da */
if(!s->budget--) { s->failed_pc=0x0c0115dau; return 0; }
r[13]+=0x00000001u;
goto P_0c0115dc;
P_0c0115dc: /* original 3dc3, guest PC 0x0c0115dc */
if(!s->budget--) { s->failed_pc=0x0c0115dcu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[13]>=(int32_t)r[12])!=0);
goto P_0c0115de;
P_0c0115de: /* original 8bf4, guest PC 0x0c0115de */
if(!s->budget--) { s->failed_pc=0x0c0115deu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0115ca; }
goto P_0c0115e0;
P_0c0115e0: /* original d255, guest PC 0x0c0115e0 */
if(!s->budget--) { s->failed_pc=0x0c0115e0u; return 0; }
r[2]=read(ram,0x0c011738u,4);
goto P_0c0115e2;
P_0c0115e2: /* original c701, guest PC 0x0c0115e2 */
if(!s->budget--) { s->failed_pc=0x0c0115e2u; return 0; }
r[0]=0x0c0115e8u;
goto P_0c0115e4;
P_0c0115e4: /* original 6db3, guest PC 0x0c0115e4 */
if(!s->budget--) { s->failed_pc=0x0c0115e4u; return 0; }
r[13]=r[11];
goto P_0c0115e6;
P_0c0115e6: /* original 320c, guest PC 0x0c0115e6 */
if(!s->budget--) { s->failed_pc=0x0c0115e6u; return 0; }
r[2]+=r[0];
goto P_0c0115e8;
P_0c0115e8: /* original 959b, guest PC 0x0c0115e8 */
if(!s->budget--) { s->failed_pc=0x0c0115e8u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c011722u,2);
goto P_0c0115ea;
P_0c0115ea: /* original 6323, guest PC 0x0c0115ea */
if(!s->budget--) { s->failed_pc=0x0c0115eau; return 0; }
r[3]=r[2];
goto P_0c0115ec;
P_0c0115ec: /* original 64b3, guest PC 0x0c0115ec */
if(!s->budget--) { s->failed_pc=0x0c0115ecu; return 0; }
r[4]=r[11];
goto P_0c0115ee;
P_0c0115ee: /* original 23eb, guest PC 0x0c0115ee */
if(!s->budget--) { s->failed_pc=0x0c0115eeu; return 0; }
r[3]|=r[14];
goto P_0c0115f0;
P_0c0115f0: /* original 430b, guest PC 0x0c0115f0 */
if(!s->budget--) { s->failed_pc=0x0c0115f0u; return 0; }
target=r[3];
r[16]=code_base|0x0c0115f4u;
r[13]+=0x00000001u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0115f4u) { target=s->pc; goto dispatch; }
goto P_0c0115f4;
P_0c0115f2: /* original 7d01, guest PC 0x0c0115f2 */
if(!s->budget--) { s->failed_pc=0x0c0115f2u; return 0; }
r[13]+=0x00000001u;
goto P_0c0115f4;
P_0c0115f4: /* original d251, guest PC 0x0c0115f4 */
if(!s->budget--) { s->failed_pc=0x0c0115f4u; return 0; }
r[2]=read(ram,0x0c01173cu,4);
goto P_0c0115f6;
P_0c0115f6: /* original c700, guest PC 0x0c0115f6 */
if(!s->budget--) { s->failed_pc=0x0c0115f6u; return 0; }
r[0]=0x0c0115f8u;
goto P_0c0115f8;
P_0c0115f8: /* original 320c, guest PC 0x0c0115f8 */
if(!s->budget--) { s->failed_pc=0x0c0115f8u; return 0; }
r[2]+=r[0];
goto P_0c0115fa;
P_0c0115fa: /* original 64d3, guest PC 0x0c0115fa */
if(!s->budget--) { s->failed_pc=0x0c0115fau; return 0; }
r[4]=r[13];
goto P_0c0115fc;
P_0c0115fc: /* original 6323, guest PC 0x0c0115fc */
if(!s->budget--) { s->failed_pc=0x0c0115fcu; return 0; }
r[3]=r[2];
goto P_0c0115fe;
P_0c0115fe: /* original e560, guest PC 0x0c0115fe */
if(!s->budget--) { s->failed_pc=0x0c0115feu; return 0; }
r[5]=0x00000060u;
goto P_0c011600;
P_0c011600: /* original 23eb, guest PC 0x0c011600 */
if(!s->budget--) { s->failed_pc=0x0c011600u; return 0; }
r[3]|=r[14];
goto P_0c011602;
P_0c011602: /* original 430b, guest PC 0x0c011602 */
if(!s->budget--) { s->failed_pc=0x0c011602u; return 0; }
target=r[3];
r[16]=code_base|0x0c011606u;
r[13]+=0x00000001u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c011606u) { target=s->pc; goto dispatch; }
goto P_0c011606;
P_0c011604: /* original 7d01, guest PC 0x0c011604 */
if(!s->budget--) { s->failed_pc=0x0c011604u; return 0; }
r[13]+=0x00000001u;
goto P_0c011606;
P_0c011606: /* original d24e, guest PC 0x0c011606 */
if(!s->budget--) { s->failed_pc=0x0c011606u; return 0; }
r[2]=read(ram,0x0c011740u,4);
goto P_0c011608;
P_0c011608: /* original c700, guest PC 0x0c011608 */
if(!s->budget--) { s->failed_pc=0x0c011608u; return 0; }
r[0]=0x0c01160cu;
goto P_0c01160a;
P_0c01160a: /* original 320c, guest PC 0x0c01160a */
if(!s->budget--) { s->failed_pc=0x0c01160au; return 0; }
r[2]+=r[0];
goto P_0c01160c;
P_0c01160c: /* original 958a, guest PC 0x0c01160c */
if(!s->budget--) { s->failed_pc=0x0c01160cu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c011724u,2);
goto P_0c01160e;
P_0c01160e: /* original 6323, guest PC 0x0c01160e */
if(!s->budget--) { s->failed_pc=0x0c01160eu; return 0; }
r[3]=r[2];
goto P_0c011610;
P_0c011610: /* original 64d3, guest PC 0x0c011610 */
if(!s->budget--) { s->failed_pc=0x0c011610u; return 0; }
r[4]=r[13];
goto P_0c011612;
P_0c011612: /* original 23eb, guest PC 0x0c011612 */
if(!s->budget--) { s->failed_pc=0x0c011612u; return 0; }
r[3]|=r[14];
goto P_0c011614;
P_0c011614: /* original 430b, guest PC 0x0c011614 */
if(!s->budget--) { s->failed_pc=0x0c011614u; return 0; }
target=r[3];
r[16]=code_base|0x0c011618u;
r[13]+=0x00000001u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c011618u) { target=s->pc; goto dispatch; }
goto P_0c011618;
P_0c011616: /* original 7d01, guest PC 0x0c011616 */
if(!s->budget--) { s->failed_pc=0x0c011616u; return 0; }
r[13]+=0x00000001u;
goto P_0c011618;
P_0c011618: /* original d24a, guest PC 0x0c011618 */
if(!s->budget--) { s->failed_pc=0x0c011618u; return 0; }
r[2]=read(ram,0x0c011744u,4);
goto P_0c01161a;
P_0c01161a: /* original c700, guest PC 0x0c01161a */
if(!s->budget--) { s->failed_pc=0x0c01161au; return 0; }
r[0]=0x0c01161cu;
goto P_0c01161c;
P_0c01161c: /* original 320c, guest PC 0x0c01161c */
if(!s->budget--) { s->failed_pc=0x0c01161cu; return 0; }
r[2]+=r[0];
goto P_0c01161e;
P_0c01161e: /* original 64d3, guest PC 0x0c01161e */
if(!s->budget--) { s->failed_pc=0x0c01161eu; return 0; }
r[4]=r[13];
goto P_0c011620;
P_0c011620: /* original 6323, guest PC 0x0c011620 */
if(!s->budget--) { s->failed_pc=0x0c011620u; return 0; }
r[3]=r[2];
goto P_0c011622;
P_0c011622: /* original e561, guest PC 0x0c011622 */
if(!s->budget--) { s->failed_pc=0x0c011622u; return 0; }
r[5]=0x00000061u;
goto P_0c011624;
P_0c011624: /* original 23eb, guest PC 0x0c011624 */
if(!s->budget--) { s->failed_pc=0x0c011624u; return 0; }
r[3]|=r[14];
goto P_0c011626;
P_0c011626: /* original 430b, guest PC 0x0c011626 */
if(!s->budget--) { s->failed_pc=0x0c011626u; return 0; }
target=r[3];
r[16]=code_base|0x0c01162au;
r[13]+=0x00000001u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c01162au) { target=s->pc; goto dispatch; }
goto P_0c01162a;
P_0c011628: /* original 7d01, guest PC 0x0c011628 */
if(!s->budget--) { s->failed_pc=0x0c011628u; return 0; }
r[13]+=0x00000001u;
goto P_0c01162a;
P_0c01162a: /* original d247, guest PC 0x0c01162a */
if(!s->budget--) { s->failed_pc=0x0c01162au; return 0; }
r[2]=read(ram,0x0c011748u,4);
goto P_0c01162c;
P_0c01162c: /* original c700, guest PC 0x0c01162c */
if(!s->budget--) { s->failed_pc=0x0c01162cu; return 0; }
r[0]=0x0c011630u;
goto P_0c01162e;
P_0c01162e: /* original 320c, guest PC 0x0c01162e */
if(!s->budget--) { s->failed_pc=0x0c01162eu; return 0; }
r[2]+=r[0];
goto P_0c011630;
P_0c011630: /* original 9579, guest PC 0x0c011630 */
if(!s->budget--) { s->failed_pc=0x0c011630u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c011726u,2);
goto P_0c011632;
P_0c011632: /* original 6323, guest PC 0x0c011632 */
if(!s->budget--) { s->failed_pc=0x0c011632u; return 0; }
r[3]=r[2];
goto P_0c011634;
P_0c011634: /* original 64d3, guest PC 0x0c011634 */
if(!s->budget--) { s->failed_pc=0x0c011634u; return 0; }
r[4]=r[13];
goto P_0c011636;
P_0c011636: /* original 23eb, guest PC 0x0c011636 */
if(!s->budget--) { s->failed_pc=0x0c011636u; return 0; }
r[3]|=r[14];
goto P_0c011638;
P_0c011638: /* original 430b, guest PC 0x0c011638 */
if(!s->budget--) { s->failed_pc=0x0c011638u; return 0; }
target=r[3];
r[16]=code_base|0x0c01163cu;
r[13]+=0x00000001u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c01163cu) { target=s->pc; goto dispatch; }
goto P_0c01163c;
P_0c01163a: /* original 7d01, guest PC 0x0c01163a */
if(!s->budget--) { s->failed_pc=0x0c01163au; return 0; }
r[13]+=0x00000001u;
goto P_0c01163c;
P_0c01163c: /* original d243, guest PC 0x0c01163c */
if(!s->budget--) { s->failed_pc=0x0c01163cu; return 0; }
r[2]=read(ram,0x0c01174cu,4);
goto P_0c01163e;
P_0c01163e: /* original c700, guest PC 0x0c01163e */
if(!s->budget--) { s->failed_pc=0x0c01163eu; return 0; }
r[0]=0x0c011640u;
goto P_0c011640;
P_0c011640: /* original 320c, guest PC 0x0c011640 */
if(!s->budget--) { s->failed_pc=0x0c011640u; return 0; }
r[2]+=r[0];
goto P_0c011642;
P_0c011642: /* original 64d3, guest PC 0x0c011642 */
if(!s->budget--) { s->failed_pc=0x0c011642u; return 0; }
r[4]=r[13];
goto P_0c011644;
P_0c011644: /* original 6323, guest PC 0x0c011644 */
if(!s->budget--) { s->failed_pc=0x0c011644u; return 0; }
r[3]=r[2];
goto P_0c011646;
P_0c011646: /* original e560, guest PC 0x0c011646 */
if(!s->budget--) { s->failed_pc=0x0c011646u; return 0; }
r[5]=0x00000060u;
goto P_0c011648;
P_0c011648: /* original 23eb, guest PC 0x0c011648 */
if(!s->budget--) { s->failed_pc=0x0c011648u; return 0; }
r[3]|=r[14];
goto P_0c01164a;
P_0c01164a: /* original 430b, guest PC 0x0c01164a */
if(!s->budget--) { s->failed_pc=0x0c01164au; return 0; }
target=r[3];
r[16]=code_base|0x0c01164eu;
r[13]+=0x00000001u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c01164eu) { target=s->pc; goto dispatch; }
goto P_0c01164e;
P_0c01164c: /* original 7d01, guest PC 0x0c01164c */
if(!s->budget--) { s->failed_pc=0x0c01164cu; return 0; }
r[13]+=0x00000001u;
goto P_0c01164e;
P_0c01164e: /* original d240, guest PC 0x0c01164e */
if(!s->budget--) { s->failed_pc=0x0c01164eu; return 0; }
r[2]=read(ram,0x0c011750u,4);
goto P_0c011650;
P_0c011650: /* original c700, guest PC 0x0c011650 */
if(!s->budget--) { s->failed_pc=0x0c011650u; return 0; }
r[0]=0x0c011654u;
goto P_0c011652;
P_0c011652: /* original 320c, guest PC 0x0c011652 */
if(!s->budget--) { s->failed_pc=0x0c011652u; return 0; }
r[2]+=r[0];
goto P_0c011654;
P_0c011654: /* original 9568, guest PC 0x0c011654 */
if(!s->budget--) { s->failed_pc=0x0c011654u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c011728u,2);
goto P_0c011656;
P_0c011656: /* original 6323, guest PC 0x0c011656 */
if(!s->budget--) { s->failed_pc=0x0c011656u; return 0; }
r[3]=r[2];
goto P_0c011658;
P_0c011658: /* original 64d3, guest PC 0x0c011658 */
if(!s->budget--) { s->failed_pc=0x0c011658u; return 0; }
r[4]=r[13];
goto P_0c01165a;
P_0c01165a: /* original 23eb, guest PC 0x0c01165a */
if(!s->budget--) { s->failed_pc=0x0c01165au; return 0; }
r[3]|=r[14];
goto P_0c01165c;
P_0c01165c: /* original 430b, guest PC 0x0c01165c */
if(!s->budget--) { s->failed_pc=0x0c01165cu; return 0; }
target=r[3];
r[16]=code_base|0x0c011660u;
r[13]+=0x00000001u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c011660u) { target=s->pc; goto dispatch; }
goto P_0c011660;
P_0c01165e: /* original 7d01, guest PC 0x0c01165e */
if(!s->budget--) { s->failed_pc=0x0c01165eu; return 0; }
r[13]+=0x00000001u;
goto P_0c011660;
P_0c011660: /* original d23c, guest PC 0x0c011660 */
if(!s->budget--) { s->failed_pc=0x0c011660u; return 0; }
r[2]=read(ram,0x0c011754u,4);
goto P_0c011662;
P_0c011662: /* original c700, guest PC 0x0c011662 */
if(!s->budget--) { s->failed_pc=0x0c011662u; return 0; }
r[0]=0x0c011664u;
goto P_0c011664;
P_0c011664: /* original 320c, guest PC 0x0c011664 */
if(!s->budget--) { s->failed_pc=0x0c011664u; return 0; }
r[2]+=r[0];
goto P_0c011666;
P_0c011666: /* original 9560, guest PC 0x0c011666 */
if(!s->budget--) { s->failed_pc=0x0c011666u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c01172au,2);
goto P_0c011668;
P_0c011668: /* original 6323, guest PC 0x0c011668 */
if(!s->budget--) { s->failed_pc=0x0c011668u; return 0; }
r[3]=r[2];
goto P_0c01166a;
P_0c01166a: /* original 64d3, guest PC 0x0c01166a */
if(!s->budget--) { s->failed_pc=0x0c01166au; return 0; }
r[4]=r[13];
goto P_0c01166c;
P_0c01166c: /* original 23eb, guest PC 0x0c01166c */
if(!s->budget--) { s->failed_pc=0x0c01166cu; return 0; }
r[3]|=r[14];
goto P_0c01166e;
P_0c01166e: /* original 430b, guest PC 0x0c01166e */
if(!s->budget--) { s->failed_pc=0x0c01166eu; return 0; }
target=r[3];
r[16]=code_base|0x0c011672u;
r[13]+=0x00000001u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c011672u) { target=s->pc; goto dispatch; }
goto P_0c011672;
P_0c011670: /* original 7d01, guest PC 0x0c011670 */
if(!s->budget--) { s->failed_pc=0x0c011670u; return 0; }
r[13]+=0x00000001u;
goto P_0c011672;
P_0c011672: /* original d239, guest PC 0x0c011672 */
if(!s->budget--) { s->failed_pc=0x0c011672u; return 0; }
r[2]=read(ram,0x0c011758u,4);
goto P_0c011674;
P_0c011674: /* original c700, guest PC 0x0c011674 */
if(!s->budget--) { s->failed_pc=0x0c011674u; return 0; }
r[0]=0x0c011678u;
goto P_0c011676;
P_0c011676: /* original 320c, guest PC 0x0c011676 */
if(!s->budget--) { s->failed_pc=0x0c011676u; return 0; }
r[2]+=r[0];
goto P_0c011678;
P_0c011678: /* original 9558, guest PC 0x0c011678 */
if(!s->budget--) { s->failed_pc=0x0c011678u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c01172cu,2);
goto P_0c01167a;
P_0c01167a: /* original 6323, guest PC 0x0c01167a */
if(!s->budget--) { s->failed_pc=0x0c01167au; return 0; }
r[3]=r[2];
goto P_0c01167c;
P_0c01167c: /* original 64d3, guest PC 0x0c01167c */
if(!s->budget--) { s->failed_pc=0x0c01167cu; return 0; }
r[4]=r[13];
goto P_0c01167e;
P_0c01167e: /* original 23eb, guest PC 0x0c01167e */
if(!s->budget--) { s->failed_pc=0x0c01167eu; return 0; }
r[3]|=r[14];
goto P_0c011680;
P_0c011680: /* original 430b, guest PC 0x0c011680 */
if(!s->budget--) { s->failed_pc=0x0c011680u; return 0; }
target=r[3];
r[16]=code_base|0x0c011684u;
r[13]+=0x00000001u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c011684u) { target=s->pc; goto dispatch; }
goto P_0c011684;
P_0c011682: /* original 7d01, guest PC 0x0c011682 */
if(!s->budget--) { s->failed_pc=0x0c011682u; return 0; }
r[13]+=0x00000001u;
goto P_0c011684;
P_0c011684: /* original d235, guest PC 0x0c011684 */
if(!s->budget--) { s->failed_pc=0x0c011684u; return 0; }
r[2]=read(ram,0x0c01175cu,4);
goto P_0c011686;
P_0c011686: /* original c700, guest PC 0x0c011686 */
if(!s->budget--) { s->failed_pc=0x0c011686u; return 0; }
r[0]=0x0c011688u;
goto P_0c011688;
P_0c011688: /* original 320c, guest PC 0x0c011688 */
if(!s->budget--) { s->failed_pc=0x0c011688u; return 0; }
r[2]+=r[0];
goto P_0c01168a;
P_0c01168a: /* original 64d3, guest PC 0x0c01168a */
if(!s->budget--) { s->failed_pc=0x0c01168au; return 0; }
r[4]=r[13];
goto P_0c01168c;
P_0c01168c: /* original 6323, guest PC 0x0c01168c */
if(!s->budget--) { s->failed_pc=0x0c01168cu; return 0; }
r[3]=r[2];
goto P_0c01168e;
P_0c01168e: /* original e50c, guest PC 0x0c01168e */
if(!s->budget--) { s->failed_pc=0x0c01168eu; return 0; }
r[5]=0x0000000cu;
goto P_0c011690;
P_0c011690: /* original 23eb, guest PC 0x0c011690 */
if(!s->budget--) { s->failed_pc=0x0c011690u; return 0; }
r[3]|=r[14];
goto P_0c011692;
P_0c011692: /* original 430b, guest PC 0x0c011692 */
if(!s->budget--) { s->failed_pc=0x0c011692u; return 0; }
target=r[3];
r[16]=code_base|0x0c011696u;
r[13]+=0x00000001u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c011696u) { target=s->pc; goto dispatch; }
goto P_0c011696;
P_0c011694: /* original 7d01, guest PC 0x0c011694 */
if(!s->budget--) { s->failed_pc=0x0c011694u; return 0; }
r[13]+=0x00000001u;
goto P_0c011696;
P_0c011696: /* original d232, guest PC 0x0c011696 */
if(!s->budget--) { s->failed_pc=0x0c011696u; return 0; }
r[2]=read(ram,0x0c011760u,4);
goto P_0c011698;
P_0c011698: /* original c700, guest PC 0x0c011698 */
if(!s->budget--) { s->failed_pc=0x0c011698u; return 0; }
r[0]=0x0c01169cu;
goto P_0c01169a;
P_0c01169a: /* original 320c, guest PC 0x0c01169a */
if(!s->budget--) { s->failed_pc=0x0c01169au; return 0; }
r[2]+=r[0];
goto P_0c01169c;
P_0c01169c: /* original 6323, guest PC 0x0c01169c */
if(!s->budget--) { s->failed_pc=0x0c01169cu; return 0; }
r[3]=r[2];
goto P_0c01169e;
P_0c01169e: /* original 64d3, guest PC 0x0c01169e */
if(!s->budget--) { s->failed_pc=0x0c01169eu; return 0; }
r[4]=r[13];
goto P_0c0116a0;
P_0c0116a0: /* original e539, guest PC 0x0c0116a0 */
if(!s->budget--) { s->failed_pc=0x0c0116a0u; return 0; }
r[5]=0x00000039u;
goto P_0c0116a2;
P_0c0116a2: /* original 23eb, guest PC 0x0c0116a2 */
if(!s->budget--) { s->failed_pc=0x0c0116a2u; return 0; }
r[3]|=r[14];
goto P_0c0116a4;
P_0c0116a4: /* original 430b, guest PC 0x0c0116a4 */
if(!s->budget--) { s->failed_pc=0x0c0116a4u; return 0; }
target=r[3];
r[16]=code_base|0x0c0116a8u;
r[13]+=0x00000001u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0116a8u) { target=s->pc; goto dispatch; }
goto P_0c0116a8;
P_0c0116a6: /* original 7d01, guest PC 0x0c0116a6 */
if(!s->budget--) { s->failed_pc=0x0c0116a6u; return 0; }
r[13]+=0x00000001u;
goto P_0c0116a8;
P_0c0116a8: /* original d22e, guest PC 0x0c0116a8 */
if(!s->budget--) { s->failed_pc=0x0c0116a8u; return 0; }
r[2]=read(ram,0x0c011764u,4);
goto P_0c0116aa;
P_0c0116aa: /* original c700, guest PC 0x0c0116aa */
if(!s->budget--) { s->failed_pc=0x0c0116aau; return 0; }
r[0]=0x0c0116acu;
goto P_0c0116ac;
P_0c0116ac: /* original 320c, guest PC 0x0c0116ac */
if(!s->budget--) { s->failed_pc=0x0c0116acu; return 0; }
r[2]+=r[0];
goto P_0c0116ae;
P_0c0116ae: /* original 64d3, guest PC 0x0c0116ae */
if(!s->budget--) { s->failed_pc=0x0c0116aeu; return 0; }
r[4]=r[13];
goto P_0c0116b0;
P_0c0116b0: /* original 6323, guest PC 0x0c0116b0 */
if(!s->budget--) { s->failed_pc=0x0c0116b0u; return 0; }
r[3]=r[2];
goto P_0c0116b2;
P_0c0116b2: /* original e562, guest PC 0x0c0116b2 */
if(!s->budget--) { s->failed_pc=0x0c0116b2u; return 0; }
r[5]=0x00000062u;
goto P_0c0116b4;
P_0c0116b4: /* original 23eb, guest PC 0x0c0116b4 */
if(!s->budget--) { s->failed_pc=0x0c0116b4u; return 0; }
r[3]|=r[14];
goto P_0c0116b6;
P_0c0116b6: /* original 430b, guest PC 0x0c0116b6 */
if(!s->budget--) { s->failed_pc=0x0c0116b6u; return 0; }
target=r[3];
r[16]=code_base|0x0c0116bau;
r[13]+=0x00000001u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0116bau) { target=s->pc; goto dispatch; }
goto P_0c0116ba;
P_0c0116b8: /* original 7d01, guest PC 0x0c0116b8 */
if(!s->budget--) { s->failed_pc=0x0c0116b8u; return 0; }
r[13]+=0x00000001u;
goto P_0c0116ba;
P_0c0116ba: /* original d22b, guest PC 0x0c0116ba */
if(!s->budget--) { s->failed_pc=0x0c0116bau; return 0; }
r[2]=read(ram,0x0c011768u,4);
goto P_0c0116bc;
P_0c0116bc: /* original c700, guest PC 0x0c0116bc */
if(!s->budget--) { s->failed_pc=0x0c0116bcu; return 0; }
r[0]=0x0c0116c0u;
goto P_0c0116be;
P_0c0116be: /* original 320c, guest PC 0x0c0116be */
if(!s->budget--) { s->failed_pc=0x0c0116beu; return 0; }
r[2]+=r[0];
goto P_0c0116c0;
P_0c0116c0: /* original 6323, guest PC 0x0c0116c0 */
if(!s->budget--) { s->failed_pc=0x0c0116c0u; return 0; }
r[3]=r[2];
goto P_0c0116c2;
P_0c0116c2: /* original 64d3, guest PC 0x0c0116c2 */
if(!s->budget--) { s->failed_pc=0x0c0116c2u; return 0; }
r[4]=r[13];
goto P_0c0116c4;
P_0c0116c4: /* original e53b, guest PC 0x0c0116c4 */
if(!s->budget--) { s->failed_pc=0x0c0116c4u; return 0; }
r[5]=0x0000003bu;
goto P_0c0116c6;
P_0c0116c6: /* original 23eb, guest PC 0x0c0116c6 */
if(!s->budget--) { s->failed_pc=0x0c0116c6u; return 0; }
r[3]|=r[14];
goto P_0c0116c8;
P_0c0116c8: /* original 430b, guest PC 0x0c0116c8 */
if(!s->budget--) { s->failed_pc=0x0c0116c8u; return 0; }
target=r[3];
r[16]=code_base|0x0c0116ccu;
r[13]+=0x00000001u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0116ccu) { target=s->pc; goto dispatch; }
goto P_0c0116cc;
P_0c0116ca: /* original 7d01, guest PC 0x0c0116ca */
if(!s->budget--) { s->failed_pc=0x0c0116cau; return 0; }
r[13]+=0x00000001u;
goto P_0c0116cc;
P_0c0116cc: /* original d227, guest PC 0x0c0116cc */
if(!s->budget--) { s->failed_pc=0x0c0116ccu; return 0; }
r[2]=read(ram,0x0c01176cu,4);
goto P_0c0116ce;
P_0c0116ce: /* original c700, guest PC 0x0c0116ce */
if(!s->budget--) { s->failed_pc=0x0c0116ceu; return 0; }
r[0]=0x0c0116d0u;
goto P_0c0116d0;
P_0c0116d0: /* original 320c, guest PC 0x0c0116d0 */
if(!s->budget--) { s->failed_pc=0x0c0116d0u; return 0; }
r[2]+=r[0];
goto P_0c0116d2;
P_0c0116d2: /* original 64d3, guest PC 0x0c0116d2 */
if(!s->budget--) { s->failed_pc=0x0c0116d2u; return 0; }
r[4]=r[13];
goto P_0c0116d4;
P_0c0116d4: /* original 6323, guest PC 0x0c0116d4 */
if(!s->budget--) { s->failed_pc=0x0c0116d4u; return 0; }
r[3]=r[2];
goto P_0c0116d6;
P_0c0116d6: /* original e570, guest PC 0x0c0116d6 */
if(!s->budget--) { s->failed_pc=0x0c0116d6u; return 0; }
r[5]=0x00000070u;
goto P_0c0116d8;
P_0c0116d8: /* original 23eb, guest PC 0x0c0116d8 */
if(!s->budget--) { s->failed_pc=0x0c0116d8u; return 0; }
r[3]|=r[14];
goto P_0c0116da;
P_0c0116da: /* original 430b, guest PC 0x0c0116da */
if(!s->budget--) { s->failed_pc=0x0c0116dau; return 0; }
target=r[3];
r[16]=code_base|0x0c0116deu;
r[13]+=0x00000001u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0116deu) { target=s->pc; goto dispatch; }
goto P_0c0116de;
P_0c0116dc: /* original 7d01, guest PC 0x0c0116dc */
if(!s->budget--) { s->failed_pc=0x0c0116dcu; return 0; }
r[13]+=0x00000001u;
goto P_0c0116de;
P_0c0116de: /* original d224, guest PC 0x0c0116de */
if(!s->budget--) { s->failed_pc=0x0c0116deu; return 0; }
r[2]=read(ram,0x0c011770u,4);
goto P_0c0116e0;
P_0c0116e0: /* original c700, guest PC 0x0c0116e0 */
if(!s->budget--) { s->failed_pc=0x0c0116e0u; return 0; }
r[0]=0x0c0116e4u;
goto P_0c0116e2;
P_0c0116e2: /* original 320c, guest PC 0x0c0116e2 */
if(!s->budget--) { s->failed_pc=0x0c0116e2u; return 0; }
r[2]+=r[0];
goto P_0c0116e4;
P_0c0116e4: /* original 6323, guest PC 0x0c0116e4 */
if(!s->budget--) { s->failed_pc=0x0c0116e4u; return 0; }
r[3]=r[2];
goto P_0c0116e6;
P_0c0116e6: /* original 64d3, guest PC 0x0c0116e6 */
if(!s->budget--) { s->failed_pc=0x0c0116e6u; return 0; }
r[4]=r[13];
goto P_0c0116e8;
P_0c0116e8: /* original e53a, guest PC 0x0c0116e8 */
if(!s->budget--) { s->failed_pc=0x0c0116e8u; return 0; }
r[5]=0x0000003au;
goto P_0c0116ea;
P_0c0116ea: /* original 23eb, guest PC 0x0c0116ea */
if(!s->budget--) { s->failed_pc=0x0c0116eau; return 0; }
r[3]|=r[14];
goto P_0c0116ec;
P_0c0116ec: /* original 430b, guest PC 0x0c0116ec */
if(!s->budget--) { s->failed_pc=0x0c0116ecu; return 0; }
target=r[3];
r[16]=code_base|0x0c0116f0u;
r[13]+=0x00000001u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0116f0u) { target=s->pc; goto dispatch; }
goto P_0c0116f0;
P_0c0116ee: /* original 7d01, guest PC 0x0c0116ee */
if(!s->budget--) { s->failed_pc=0x0c0116eeu; return 0; }
r[13]+=0x00000001u;
goto P_0c0116f0;
P_0c0116f0: /* original d220, guest PC 0x0c0116f0 */
if(!s->budget--) { s->failed_pc=0x0c0116f0u; return 0; }
r[2]=read(ram,0x0c011774u,4);
goto P_0c0116f2;
P_0c0116f2: /* original c700, guest PC 0x0c0116f2 */
if(!s->budget--) { s->failed_pc=0x0c0116f2u; return 0; }
r[0]=0x0c0116f4u;
goto P_0c0116f4;
P_0c0116f4: /* original 320c, guest PC 0x0c0116f4 */
if(!s->budget--) { s->failed_pc=0x0c0116f4u; return 0; }
r[2]+=r[0];
goto P_0c0116f6;
P_0c0116f6: /* original 64d3, guest PC 0x0c0116f6 */
if(!s->budget--) { s->failed_pc=0x0c0116f6u; return 0; }
r[4]=r[13];
goto P_0c0116f8;
P_0c0116f8: /* original 6323, guest PC 0x0c0116f8 */
if(!s->budget--) { s->failed_pc=0x0c0116f8u; return 0; }
r[3]=r[2];
goto P_0c0116fa;
P_0c0116fa: /* original e564, guest PC 0x0c0116fa */
if(!s->budget--) { s->failed_pc=0x0c0116fau; return 0; }
r[5]=0x00000064u;
goto P_0c0116fc;
P_0c0116fc: /* original 23eb, guest PC 0x0c0116fc */
if(!s->budget--) { s->failed_pc=0x0c0116fcu; return 0; }
r[3]|=r[14];
goto P_0c0116fe;
P_0c0116fe: /* original 430b, guest PC 0x0c0116fe */
if(!s->budget--) { s->failed_pc=0x0c0116feu; return 0; }
target=r[3];
r[16]=code_base|0x0c011702u;
r[13]+=0x00000001u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c011702u) { target=s->pc; goto dispatch; }
goto P_0c011702;
P_0c011700: /* original 7d01, guest PC 0x0c011700 */
if(!s->budget--) { s->failed_pc=0x0c011700u; return 0; }
r[13]+=0x00000001u;
goto P_0c011702;
P_0c011702: /* original d21d, guest PC 0x0c011702 */
if(!s->budget--) { s->failed_pc=0x0c011702u; return 0; }
r[2]=read(ram,0x0c011778u,4);
goto P_0c011704;
P_0c011704: /* original c700, guest PC 0x0c011704 */
if(!s->budget--) { s->failed_pc=0x0c011704u; return 0; }
r[0]=0x0c011708u;
goto P_0c011706;
P_0c011706: /* original 320c, guest PC 0x0c011706 */
if(!s->budget--) { s->failed_pc=0x0c011706u; return 0; }
r[2]+=r[0];
goto P_0c011708;
P_0c011708: /* original 6323, guest PC 0x0c011708 */
if(!s->budget--) { s->failed_pc=0x0c011708u; return 0; }
r[3]=r[2];
goto P_0c01170a;
P_0c01170a: /* original 64d3, guest PC 0x0c01170a */
if(!s->budget--) { s->failed_pc=0x0c01170au; return 0; }
r[4]=r[13];
goto P_0c01170c;
P_0c01170c: /* original e538, guest PC 0x0c01170c */
if(!s->budget--) { s->failed_pc=0x0c01170cu; return 0; }
r[5]=0x00000038u;
goto P_0c01170e;
P_0c01170e: /* original 23eb, guest PC 0x0c01170e */
if(!s->budget--) { s->failed_pc=0x0c01170eu; return 0; }
r[3]|=r[14];
goto P_0c011710;
P_0c011710: /* original 430b, guest PC 0x0c011710 */
if(!s->budget--) { s->failed_pc=0x0c011710u; return 0; }
target=r[3];
r[16]=code_base|0x0c011714u;
r[13]+=0x00000001u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c011714u) { target=s->pc; goto dispatch; }
goto P_0c011714;
P_0c011712: /* original 7d01, guest PC 0x0c011712 */
if(!s->budget--) { s->failed_pc=0x0c011712u; return 0; }
r[13]+=0x00000001u;
goto P_0c011714;
P_0c011714: /* original d219, guest PC 0x0c011714 */
if(!s->budget--) { s->failed_pc=0x0c011714u; return 0; }
r[2]=read(ram,0x0c01177cu,4);
goto P_0c011716;
P_0c011716: /* original c700, guest PC 0x0c011716 */
if(!s->budget--) { s->failed_pc=0x0c011716u; return 0; }
r[0]=0x0c011718u;
goto P_0c011718;
P_0c011718: /* original 320c, guest PC 0x0c011718 */
if(!s->budget--) { s->failed_pc=0x0c011718u; return 0; }
r[2]+=r[0];
goto P_0c01171a;
P_0c01171a: /* original 6323, guest PC 0x0c01171a */
if(!s->budget--) { s->failed_pc=0x0c01171au; return 0; }
r[3]=r[2];
goto P_0c01171c;
P_0c01171c: /* original a030, guest PC 0x0c01171c */
if(!s->budget--) { s->failed_pc=0x0c01171cu; return 0; }
goto P_0c011780;
P_0c01171e: /* original 0009, guest PC 0x0c01171e */
if(!s->budget--) { s->failed_pc=0x0c01171eu; return 0; }
return vf3_matrix_family(0x0c011720u,s,ram);
P_0c011780: /* original 64d3, guest PC 0x0c011780 */
if(!s->budget--) { s->failed_pc=0x0c011780u; return 0; }
r[4]=r[13];
goto P_0c011782;
P_0c011782: /* original e565, guest PC 0x0c011782 */
if(!s->budget--) { s->failed_pc=0x0c011782u; return 0; }
r[5]=0x00000065u;
goto P_0c011784;
P_0c011784: /* original 23eb, guest PC 0x0c011784 */
if(!s->budget--) { s->failed_pc=0x0c011784u; return 0; }
r[3]|=r[14];
goto P_0c011786;
P_0c011786: /* original 430b, guest PC 0x0c011786 */
if(!s->budget--) { s->failed_pc=0x0c011786u; return 0; }
target=r[3];
r[16]=code_base|0x0c01178au;
r[13]+=0x00000001u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c01178au) { target=s->pc; goto dispatch; }
goto P_0c01178a;
P_0c011788: /* original 7d01, guest PC 0x0c011788 */
if(!s->budget--) { s->failed_pc=0x0c011788u; return 0; }
r[13]+=0x00000001u;
goto P_0c01178a;
P_0c01178a: /* original d24b, guest PC 0x0c01178a */
if(!s->budget--) { s->failed_pc=0x0c01178au; return 0; }
r[2]=read(ram,0x0c0118b8u,4);
goto P_0c01178c;
P_0c01178c: /* original c700, guest PC 0x0c01178c */
if(!s->budget--) { s->failed_pc=0x0c01178cu; return 0; }
r[0]=0x0c011790u;
goto P_0c01178e;
P_0c01178e: /* original 320c, guest PC 0x0c01178e */
if(!s->budget--) { s->failed_pc=0x0c01178eu; return 0; }
r[2]+=r[0];
goto P_0c011790;
P_0c011790: /* original 6323, guest PC 0x0c011790 */
if(!s->budget--) { s->failed_pc=0x0c011790u; return 0; }
r[3]=r[2];
goto P_0c011792;
P_0c011792: /* original 64d3, guest PC 0x0c011792 */
if(!s->budget--) { s->failed_pc=0x0c011792u; return 0; }
r[4]=r[13];
goto P_0c011794;
P_0c011794: /* original e533, guest PC 0x0c011794 */
if(!s->budget--) { s->failed_pc=0x0c011794u; return 0; }
r[5]=0x00000033u;
goto P_0c011796;
P_0c011796: /* original 23eb, guest PC 0x0c011796 */
if(!s->budget--) { s->failed_pc=0x0c011796u; return 0; }
r[3]|=r[14];
goto P_0c011798;
P_0c011798: /* original 430b, guest PC 0x0c011798 */
if(!s->budget--) { s->failed_pc=0x0c011798u; return 0; }
target=r[3];
r[16]=code_base|0x0c01179cu;
r[13]+=0x00000001u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c01179cu) { target=s->pc; goto dispatch; }
goto P_0c01179c;
P_0c01179a: /* original 7d01, guest PC 0x0c01179a */
if(!s->budget--) { s->failed_pc=0x0c01179au; return 0; }
r[13]+=0x00000001u;
goto P_0c01179c;
P_0c01179c: /* original d247, guest PC 0x0c01179c */
if(!s->budget--) { s->failed_pc=0x0c01179cu; return 0; }
r[2]=read(ram,0x0c0118bcu,4);
goto P_0c01179e;
P_0c01179e: /* original c701, guest PC 0x0c01179e */
if(!s->budget--) { s->failed_pc=0x0c01179eu; return 0; }
r[0]=0x0c0117a4u;
goto P_0c0117a0;
P_0c0117a0: /* original 9c83, guest PC 0x0c0117a0 */
if(!s->budget--) { s->failed_pc=0x0c0117a0u; return 0; }
r[12]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0118aau,2);
goto P_0c0117a2;
P_0c0117a2: /* original 320c, guest PC 0x0c0117a2 */
if(!s->budget--) { s->failed_pc=0x0c0117a2u; return 0; }
r[2]+=r[0];
goto P_0c0117a4;
P_0c0117a4: /* original 6323, guest PC 0x0c0117a4 */
if(!s->budget--) { s->failed_pc=0x0c0117a4u; return 0; }
r[3]=r[2];
goto P_0c0117a6;
P_0c0117a6: /* original 64d3, guest PC 0x0c0117a6 */
if(!s->budget--) { s->failed_pc=0x0c0117a6u; return 0; }
r[4]=r[13];
goto P_0c0117a8;
P_0c0117a8: /* original 65c3, guest PC 0x0c0117a8 */
if(!s->budget--) { s->failed_pc=0x0c0117a8u; return 0; }
r[5]=r[12];
goto P_0c0117aa;
P_0c0117aa: /* original 23eb, guest PC 0x0c0117aa */
if(!s->budget--) { s->failed_pc=0x0c0117aau; return 0; }
r[3]|=r[14];
goto P_0c0117ac;
P_0c0117ac: /* original 430b, guest PC 0x0c0117ac */
if(!s->budget--) { s->failed_pc=0x0c0117acu; return 0; }
target=r[3];
r[16]=code_base|0x0c0117b0u;
r[13]+=0x00000001u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0117b0u) { target=s->pc; goto dispatch; }
goto P_0c0117b0;
P_0c0117ae: /* original 7d01, guest PC 0x0c0117ae */
if(!s->budget--) { s->failed_pc=0x0c0117aeu; return 0; }
r[13]+=0x00000001u;
goto P_0c0117b0;
P_0c0117b0: /* original d243, guest PC 0x0c0117b0 */
if(!s->budget--) { s->failed_pc=0x0c0117b0u; return 0; }
r[2]=read(ram,0x0c0118c0u,4);
goto P_0c0117b2;
P_0c0117b2: /* original c700, guest PC 0x0c0117b2 */
if(!s->budget--) { s->failed_pc=0x0c0117b2u; return 0; }
r[0]=0x0c0117b4u;
goto P_0c0117b4;
P_0c0117b4: /* original 320c, guest PC 0x0c0117b4 */
if(!s->budget--) { s->failed_pc=0x0c0117b4u; return 0; }
r[2]+=r[0];
goto P_0c0117b6;
P_0c0117b6: /* original 9579, guest PC 0x0c0117b6 */
if(!s->budget--) { s->failed_pc=0x0c0117b6u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0118acu,2);
goto P_0c0117b8;
P_0c0117b8: /* original 6323, guest PC 0x0c0117b8 */
if(!s->budget--) { s->failed_pc=0x0c0117b8u; return 0; }
r[3]=r[2];
goto P_0c0117ba;
P_0c0117ba: /* original 64d3, guest PC 0x0c0117ba */
if(!s->budget--) { s->failed_pc=0x0c0117bau; return 0; }
r[4]=r[13];
goto P_0c0117bc;
P_0c0117bc: /* original 23eb, guest PC 0x0c0117bc */
if(!s->budget--) { s->failed_pc=0x0c0117bcu; return 0; }
r[3]|=r[14];
goto P_0c0117be;
P_0c0117be: /* original 430b, guest PC 0x0c0117be */
if(!s->budget--) { s->failed_pc=0x0c0117beu; return 0; }
target=r[3];
r[16]=code_base|0x0c0117c2u;
r[13]+=0x00000001u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0117c2u) { target=s->pc; goto dispatch; }
goto P_0c0117c2;
P_0c0117c0: /* original 7d01, guest PC 0x0c0117c0 */
if(!s->budget--) { s->failed_pc=0x0c0117c0u; return 0; }
r[13]+=0x00000001u;
goto P_0c0117c2;
P_0c0117c2: /* original d240, guest PC 0x0c0117c2 */
if(!s->budget--) { s->failed_pc=0x0c0117c2u; return 0; }
r[2]=read(ram,0x0c0118c4u,4);
goto P_0c0117c4;
P_0c0117c4: /* original c700, guest PC 0x0c0117c4 */
if(!s->budget--) { s->failed_pc=0x0c0117c4u; return 0; }
r[0]=0x0c0117c8u;
goto P_0c0117c6;
P_0c0117c6: /* original 320c, guest PC 0x0c0117c6 */
if(!s->budget--) { s->failed_pc=0x0c0117c6u; return 0; }
r[2]+=r[0];
goto P_0c0117c8;
P_0c0117c8: /* original 6323, guest PC 0x0c0117c8 */
if(!s->budget--) { s->failed_pc=0x0c0117c8u; return 0; }
r[3]=r[2];
goto P_0c0117ca;
P_0c0117ca: /* original 64d3, guest PC 0x0c0117ca */
if(!s->budget--) { s->failed_pc=0x0c0117cau; return 0; }
r[4]=r[13];
goto P_0c0117cc;
P_0c0117cc: /* original e570, guest PC 0x0c0117cc */
if(!s->budget--) { s->failed_pc=0x0c0117ccu; return 0; }
r[5]=0x00000070u;
goto P_0c0117ce;
P_0c0117ce: /* original 23eb, guest PC 0x0c0117ce */
if(!s->budget--) { s->failed_pc=0x0c0117ceu; return 0; }
r[3]|=r[14];
goto P_0c0117d0;
P_0c0117d0: /* original 430b, guest PC 0x0c0117d0 */
if(!s->budget--) { s->failed_pc=0x0c0117d0u; return 0; }
target=r[3];
r[16]=code_base|0x0c0117d4u;
r[13]+=0x00000001u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0117d4u) { target=s->pc; goto dispatch; }
goto P_0c0117d4;
P_0c0117d2: /* original 7d01, guest PC 0x0c0117d2 */
if(!s->budget--) { s->failed_pc=0x0c0117d2u; return 0; }
r[13]+=0x00000001u;
goto P_0c0117d4;
P_0c0117d4: /* original d23c, guest PC 0x0c0117d4 */
if(!s->budget--) { s->failed_pc=0x0c0117d4u; return 0; }
r[2]=read(ram,0x0c0118c8u,4);
goto P_0c0117d6;
P_0c0117d6: /* original c700, guest PC 0x0c0117d6 */
if(!s->budget--) { s->failed_pc=0x0c0117d6u; return 0; }
r[0]=0x0c0117d8u;
goto P_0c0117d8;
P_0c0117d8: /* original 320c, guest PC 0x0c0117d8 */
if(!s->budget--) { s->failed_pc=0x0c0117d8u; return 0; }
r[2]+=r[0];
goto P_0c0117da;
P_0c0117da: /* original 9568, guest PC 0x0c0117da */
if(!s->budget--) { s->failed_pc=0x0c0117dau; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0118aeu,2);
goto P_0c0117dc;
P_0c0117dc: /* original 6323, guest PC 0x0c0117dc */
if(!s->budget--) { s->failed_pc=0x0c0117dcu; return 0; }
r[3]=r[2];
goto P_0c0117de;
P_0c0117de: /* original 64d3, guest PC 0x0c0117de */
if(!s->budget--) { s->failed_pc=0x0c0117deu; return 0; }
r[4]=r[13];
goto P_0c0117e0;
P_0c0117e0: /* original 23eb, guest PC 0x0c0117e0 */
if(!s->budget--) { s->failed_pc=0x0c0117e0u; return 0; }
r[3]|=r[14];
goto P_0c0117e2;
P_0c0117e2: /* original 430b, guest PC 0x0c0117e2 */
if(!s->budget--) { s->failed_pc=0x0c0117e2u; return 0; }
target=r[3];
r[16]=code_base|0x0c0117e6u;
r[13]+=0x00000001u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0117e6u) { target=s->pc; goto dispatch; }
goto P_0c0117e6;
P_0c0117e4: /* original 7d01, guest PC 0x0c0117e4 */
if(!s->budget--) { s->failed_pc=0x0c0117e4u; return 0; }
r[13]+=0x00000001u;
goto P_0c0117e6;
P_0c0117e6: /* original d239, guest PC 0x0c0117e6 */
if(!s->budget--) { s->failed_pc=0x0c0117e6u; return 0; }
r[2]=read(ram,0x0c0118ccu,4);
goto P_0c0117e8;
P_0c0117e8: /* original c700, guest PC 0x0c0117e8 */
if(!s->budget--) { s->failed_pc=0x0c0117e8u; return 0; }
r[0]=0x0c0117ecu;
goto P_0c0117ea;
P_0c0117ea: /* original 320c, guest PC 0x0c0117ea */
if(!s->budget--) { s->failed_pc=0x0c0117eau; return 0; }
r[2]+=r[0];
goto P_0c0117ec;
P_0c0117ec: /* original 6323, guest PC 0x0c0117ec */
if(!s->budget--) { s->failed_pc=0x0c0117ecu; return 0; }
r[3]=r[2];
goto P_0c0117ee;
P_0c0117ee: /* original 64d3, guest PC 0x0c0117ee */
if(!s->budget--) { s->failed_pc=0x0c0117eeu; return 0; }
r[4]=r[13];
goto P_0c0117f0;
P_0c0117f0: /* original e502, guest PC 0x0c0117f0 */
if(!s->budget--) { s->failed_pc=0x0c0117f0u; return 0; }
r[5]=0x00000002u;
goto P_0c0117f2;
P_0c0117f2: /* original 23eb, guest PC 0x0c0117f2 */
if(!s->budget--) { s->failed_pc=0x0c0117f2u; return 0; }
r[3]|=r[14];
goto P_0c0117f4;
P_0c0117f4: /* original 430b, guest PC 0x0c0117f4 */
if(!s->budget--) { s->failed_pc=0x0c0117f4u; return 0; }
target=r[3];
r[16]=code_base|0x0c0117f8u;
r[13]+=0x00000001u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0117f8u) { target=s->pc; goto dispatch; }
goto P_0c0117f8;
P_0c0117f6: /* original 7d01, guest PC 0x0c0117f6 */
if(!s->budget--) { s->failed_pc=0x0c0117f6u; return 0; }
r[13]+=0x00000001u;
goto P_0c0117f8;
P_0c0117f8: /* original d235, guest PC 0x0c0117f8 */
if(!s->budget--) { s->failed_pc=0x0c0117f8u; return 0; }
r[2]=read(ram,0x0c0118d0u,4);
goto P_0c0117fa;
P_0c0117fa: /* original c700, guest PC 0x0c0117fa */
if(!s->budget--) { s->failed_pc=0x0c0117fau; return 0; }
r[0]=0x0c0117fcu;
goto P_0c0117fc;
P_0c0117fc: /* original 320c, guest PC 0x0c0117fc */
if(!s->budget--) { s->failed_pc=0x0c0117fcu; return 0; }
r[2]+=r[0];
goto P_0c0117fe;
P_0c0117fe: /* original 9557, guest PC 0x0c0117fe */
if(!s->budget--) { s->failed_pc=0x0c0117feu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0118b0u,2);
goto P_0c011800;
P_0c011800: /* original 6323, guest PC 0x0c011800 */
if(!s->budget--) { s->failed_pc=0x0c011800u; return 0; }
r[3]=r[2];
goto P_0c011802;
P_0c011802: /* original 64d3, guest PC 0x0c011802 */
if(!s->budget--) { s->failed_pc=0x0c011802u; return 0; }
r[4]=r[13];
goto P_0c011804;
P_0c011804: /* original 23eb, guest PC 0x0c011804 */
if(!s->budget--) { s->failed_pc=0x0c011804u; return 0; }
r[3]|=r[14];
goto P_0c011806;
P_0c011806: /* original 430b, guest PC 0x0c011806 */
if(!s->budget--) { s->failed_pc=0x0c011806u; return 0; }
target=r[3];
r[16]=code_base|0x0c01180au;
r[13]+=0x00000001u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c01180au) { target=s->pc; goto dispatch; }
goto P_0c01180a;
P_0c011808: /* original 7d01, guest PC 0x0c011808 */
if(!s->budget--) { s->failed_pc=0x0c011808u; return 0; }
r[13]+=0x00000001u;
goto P_0c01180a;
P_0c01180a: /* original d232, guest PC 0x0c01180a */
if(!s->budget--) { s->failed_pc=0x0c01180au; return 0; }
r[2]=read(ram,0x0c0118d4u,4);
goto P_0c01180c;
P_0c01180c: /* original c700, guest PC 0x0c01180c */
if(!s->budget--) { s->failed_pc=0x0c01180cu; return 0; }
r[0]=0x0c011810u;
goto P_0c01180e;
P_0c01180e: /* original 320c, guest PC 0x0c01180e */
if(!s->budget--) { s->failed_pc=0x0c01180eu; return 0; }
r[2]+=r[0];
goto P_0c011810;
P_0c011810: /* original 6323, guest PC 0x0c011810 */
if(!s->budget--) { s->failed_pc=0x0c011810u; return 0; }
r[3]=r[2];
goto P_0c011812;
P_0c011812: /* original 64d3, guest PC 0x0c011812 */
if(!s->budget--) { s->failed_pc=0x0c011812u; return 0; }
r[4]=r[13];
goto P_0c011814;
P_0c011814: /* original e51c, guest PC 0x0c011814 */
if(!s->budget--) { s->failed_pc=0x0c011814u; return 0; }
r[5]=0x0000001cu;
goto P_0c011816;
P_0c011816: /* original 23eb, guest PC 0x0c011816 */
if(!s->budget--) { s->failed_pc=0x0c011816u; return 0; }
r[3]|=r[14];
goto P_0c011818;
P_0c011818: /* original 430b, guest PC 0x0c011818 */
if(!s->budget--) { s->failed_pc=0x0c011818u; return 0; }
target=r[3];
r[16]=code_base|0x0c01181cu;
r[13]+=0x00000001u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c01181cu) { target=s->pc; goto dispatch; }
goto P_0c01181c;
P_0c01181a: /* original 7d01, guest PC 0x0c01181a */
if(!s->budget--) { s->failed_pc=0x0c01181au; return 0; }
r[13]+=0x00000001u;
goto P_0c01181c;
P_0c01181c: /* original d22e, guest PC 0x0c01181c */
if(!s->budget--) { s->failed_pc=0x0c01181cu; return 0; }
r[2]=read(ram,0x0c0118d8u,4);
goto P_0c01181e;
P_0c01181e: /* original c700, guest PC 0x0c01181e */
if(!s->budget--) { s->failed_pc=0x0c01181eu; return 0; }
r[0]=0x0c011820u;
goto P_0c011820;
P_0c011820: /* original 320c, guest PC 0x0c011820 */
if(!s->budget--) { s->failed_pc=0x0c011820u; return 0; }
r[2]+=r[0];
goto P_0c011822;
P_0c011822: /* original 9546, guest PC 0x0c011822 */
if(!s->budget--) { s->failed_pc=0x0c011822u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0118b2u,2);
goto P_0c011824;
P_0c011824: /* original 6323, guest PC 0x0c011824 */
if(!s->budget--) { s->failed_pc=0x0c011824u; return 0; }
r[3]=r[2];
goto P_0c011826;
P_0c011826: /* original 64d3, guest PC 0x0c011826 */
if(!s->budget--) { s->failed_pc=0x0c011826u; return 0; }
r[4]=r[13];
goto P_0c011828;
P_0c011828: /* original 23eb, guest PC 0x0c011828 */
if(!s->budget--) { s->failed_pc=0x0c011828u; return 0; }
r[3]|=r[14];
goto P_0c01182a;
P_0c01182a: /* original 430b, guest PC 0x0c01182a */
if(!s->budget--) { s->failed_pc=0x0c01182au; return 0; }
target=r[3];
r[16]=code_base|0x0c01182eu;
r[13]+=0x00000001u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c01182eu) { target=s->pc; goto dispatch; }
goto P_0c01182e;
P_0c01182c: /* original 7d01, guest PC 0x0c01182c */
if(!s->budget--) { s->failed_pc=0x0c01182cu; return 0; }
r[13]+=0x00000001u;
goto P_0c01182e;
P_0c01182e: /* original d22b, guest PC 0x0c01182e */
if(!s->budget--) { s->failed_pc=0x0c01182eu; return 0; }
r[2]=read(ram,0x0c0118dcu,4);
goto P_0c011830;
P_0c011830: /* original c700, guest PC 0x0c011830 */
if(!s->budget--) { s->failed_pc=0x0c011830u; return 0; }
r[0]=0x0c011834u;
goto P_0c011832;
P_0c011832: /* original 320c, guest PC 0x0c011832 */
if(!s->budget--) { s->failed_pc=0x0c011832u; return 0; }
r[2]+=r[0];
goto P_0c011834;
P_0c011834: /* original 953e, guest PC 0x0c011834 */
if(!s->budget--) { s->failed_pc=0x0c011834u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0118b4u,2);
goto P_0c011836;
P_0c011836: /* original 6323, guest PC 0x0c011836 */
if(!s->budget--) { s->failed_pc=0x0c011836u; return 0; }
r[3]=r[2];
goto P_0c011838;
P_0c011838: /* original 64d3, guest PC 0x0c011838 */
if(!s->budget--) { s->failed_pc=0x0c011838u; return 0; }
r[4]=r[13];
goto P_0c01183a;
P_0c01183a: /* original 23eb, guest PC 0x0c01183a */
if(!s->budget--) { s->failed_pc=0x0c01183au; return 0; }
r[3]|=r[14];
goto P_0c01183c;
P_0c01183c: /* original 430b, guest PC 0x0c01183c */
if(!s->budget--) { s->failed_pc=0x0c01183cu; return 0; }
target=r[3];
r[16]=code_base|0x0c011840u;
r[13]+=0x00000001u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c011840u) { target=s->pc; goto dispatch; }
goto P_0c011840;
P_0c01183e: /* original 7d01, guest PC 0x0c01183e */
if(!s->budget--) { s->failed_pc=0x0c01183eu; return 0; }
r[13]+=0x00000001u;
goto P_0c011840;
P_0c011840: /* original d227, guest PC 0x0c011840 */
if(!s->budget--) { s->failed_pc=0x0c011840u; return 0; }
r[2]=read(ram,0x0c0118e0u,4);
goto P_0c011842;
P_0c011842: /* original c700, guest PC 0x0c011842 */
if(!s->budget--) { s->failed_pc=0x0c011842u; return 0; }
r[0]=0x0c011844u;
goto P_0c011844;
P_0c011844: /* original 320c, guest PC 0x0c011844 */
if(!s->budget--) { s->failed_pc=0x0c011844u; return 0; }
r[2]+=r[0];
goto P_0c011846;
P_0c011846: /* original 9536, guest PC 0x0c011846 */
if(!s->budget--) { s->failed_pc=0x0c011846u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0118b6u,2);
goto P_0c011848;
P_0c011848: /* original 6323, guest PC 0x0c011848 */
if(!s->budget--) { s->failed_pc=0x0c011848u; return 0; }
r[3]=r[2];
goto P_0c01184a;
P_0c01184a: /* original 64d3, guest PC 0x0c01184a */
if(!s->budget--) { s->failed_pc=0x0c01184au; return 0; }
r[4]=r[13];
goto P_0c01184c;
P_0c01184c: /* original 23eb, guest PC 0x0c01184c */
if(!s->budget--) { s->failed_pc=0x0c01184cu; return 0; }
r[3]|=r[14];
goto P_0c01184e;
P_0c01184e: /* original 430b, guest PC 0x0c01184e */
if(!s->budget--) { s->failed_pc=0x0c01184eu; return 0; }
target=r[3];
r[16]=code_base|0x0c011852u;
r[13]+=0x00000001u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c011852u) { target=s->pc; goto dispatch; }
goto P_0c011852;
P_0c011850: /* original 7d01, guest PC 0x0c011850 */
if(!s->budget--) { s->failed_pc=0x0c011850u; return 0; }
r[13]+=0x00000001u;
goto P_0c011852;
P_0c011852: /* original d224, guest PC 0x0c011852 */
if(!s->budget--) { s->failed_pc=0x0c011852u; return 0; }
r[2]=read(ram,0x0c0118e4u,4);
goto P_0c011854;
P_0c011854: /* original c700, guest PC 0x0c011854 */
if(!s->budget--) { s->failed_pc=0x0c011854u; return 0; }
r[0]=0x0c011858u;
goto P_0c011856;
P_0c011856: /* original 320c, guest PC 0x0c011856 */
if(!s->budget--) { s->failed_pc=0x0c011856u; return 0; }
r[2]+=r[0];
goto P_0c011858;
P_0c011858: /* original 952c, guest PC 0x0c011858 */
if(!s->budget--) { s->failed_pc=0x0c011858u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0118b4u,2);
goto P_0c01185a;
P_0c01185a: /* original 6323, guest PC 0x0c01185a */
if(!s->budget--) { s->failed_pc=0x0c01185au; return 0; }
r[3]=r[2];
goto P_0c01185c;
P_0c01185c: /* original 64d3, guest PC 0x0c01185c */
if(!s->budget--) { s->failed_pc=0x0c01185cu; return 0; }
r[4]=r[13];
goto P_0c01185e;
P_0c01185e: /* original 23eb, guest PC 0x0c01185e */
if(!s->budget--) { s->failed_pc=0x0c01185eu; return 0; }
r[3]|=r[14];
goto P_0c011860;
P_0c011860: /* original 430b, guest PC 0x0c011860 */
if(!s->budget--) { s->failed_pc=0x0c011860u; return 0; }
target=r[3];
r[16]=code_base|0x0c011864u;
r[13]+=0x00000001u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c011864u) { target=s->pc; goto dispatch; }
goto P_0c011864;
P_0c011862: /* original 7d01, guest PC 0x0c011862 */
if(!s->budget--) { s->failed_pc=0x0c011862u; return 0; }
r[13]+=0x00000001u;
goto P_0c011864;
P_0c011864: /* original d220, guest PC 0x0c011864 */
if(!s->budget--) { s->failed_pc=0x0c011864u; return 0; }
r[2]=read(ram,0x0c0118e8u,4);
goto P_0c011866;
P_0c011866: /* original c700, guest PC 0x0c011866 */
if(!s->budget--) { s->failed_pc=0x0c011866u; return 0; }
r[0]=0x0c011868u;
goto P_0c011868;
P_0c011868: /* original 320c, guest PC 0x0c011868 */
if(!s->budget--) { s->failed_pc=0x0c011868u; return 0; }
r[2]+=r[0];
goto P_0c01186a;
P_0c01186a: /* original 64d3, guest PC 0x0c01186a */
if(!s->budget--) { s->failed_pc=0x0c01186au; return 0; }
r[4]=r[13];
goto P_0c01186c;
P_0c01186c: /* original 6323, guest PC 0x0c01186c */
if(!s->budget--) { s->failed_pc=0x0c01186cu; return 0; }
r[3]=r[2];
goto P_0c01186e;
P_0c01186e: /* original 65c3, guest PC 0x0c01186e */
if(!s->budget--) { s->failed_pc=0x0c01186eu; return 0; }
r[5]=r[12];
goto P_0c011870;
P_0c011870: /* original 23eb, guest PC 0x0c011870 */
if(!s->budget--) { s->failed_pc=0x0c011870u; return 0; }
r[3]|=r[14];
goto P_0c011872;
P_0c011872: /* original 430b, guest PC 0x0c011872 */
if(!s->budget--) { s->failed_pc=0x0c011872u; return 0; }
target=r[3];
r[16]=code_base|0x0c011876u;
r[13]+=0x00000001u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c011876u) { target=s->pc; goto dispatch; }
goto P_0c011876;
P_0c011874: /* original 7d01, guest PC 0x0c011874 */
if(!s->budget--) { s->failed_pc=0x0c011874u; return 0; }
r[13]+=0x00000001u;
goto P_0c011876;
P_0c011876: /* original d21d, guest PC 0x0c011876 */
if(!s->budget--) { s->failed_pc=0x0c011876u; return 0; }
r[2]=read(ram,0x0c0118ecu,4);
goto P_0c011878;
P_0c011878: /* original c700, guest PC 0x0c011878 */
if(!s->budget--) { s->failed_pc=0x0c011878u; return 0; }
r[0]=0x0c01187cu;
goto P_0c01187a;
P_0c01187a: /* original 320c, guest PC 0x0c01187a */
if(!s->budget--) { s->failed_pc=0x0c01187au; return 0; }
r[2]+=r[0];
goto P_0c01187c;
P_0c01187c: /* original 6323, guest PC 0x0c01187c */
if(!s->budget--) { s->failed_pc=0x0c01187cu; return 0; }
r[3]=r[2];
goto P_0c01187e;
P_0c01187e: /* original 65c3, guest PC 0x0c01187e */
if(!s->budget--) { s->failed_pc=0x0c01187eu; return 0; }
r[5]=r[12];
goto P_0c011880;
P_0c011880: /* original 23eb, guest PC 0x0c011880 */
if(!s->budget--) { s->failed_pc=0x0c011880u; return 0; }
r[3]|=r[14];
goto P_0c011882;
P_0c011882: /* original 430b, guest PC 0x0c011882 */
if(!s->budget--) { s->failed_pc=0x0c011882u; return 0; }
target=r[3];
r[16]=code_base|0x0c011886u;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c011886u) { target=s->pc; goto dispatch; }
goto P_0c011886;
P_0c011884: /* original 64d3, guest PC 0x0c011884 */
if(!s->budget--) { s->failed_pc=0x0c011884u; return 0; }
r[4]=r[13];
goto P_0c011886;
P_0c011886: /* original d21a, guest PC 0x0c011886 */
if(!s->budget--) { s->failed_pc=0x0c011886u; return 0; }
r[2]=read(ram,0x0c0118f0u,4);
goto P_0c011888;
P_0c011888: /* original c700, guest PC 0x0c011888 */
if(!s->budget--) { s->failed_pc=0x0c011888u; return 0; }
r[0]=0x0c01188cu;
goto P_0c01188a;
P_0c01188a: /* original 320c, guest PC 0x0c01188a */
if(!s->budget--) { s->failed_pc=0x0c01188au; return 0; }
r[2]+=r[0];
goto P_0c01188c;
P_0c01188c: /* original 6323, guest PC 0x0c01188c */
if(!s->budget--) { s->failed_pc=0x0c01188cu; return 0; }
r[3]=r[2];
goto P_0c01188e;
P_0c01188e: /* original 65c3, guest PC 0x0c01188e */
if(!s->budget--) { s->failed_pc=0x0c01188eu; return 0; }
r[5]=r[12];
goto P_0c011890;
P_0c011890: /* original 2e3b, guest PC 0x0c011890 */
if(!s->budget--) { s->failed_pc=0x0c011890u; return 0; }
r[14]|=r[3];
goto P_0c011892;
P_0c011892: /* original 4e0b, guest PC 0x0c011892 */
if(!s->budget--) { s->failed_pc=0x0c011892u; return 0; }
target=r[14];
r[16]=code_base|0x0c011896u;
r[4]=0x00000064u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c011896u) { target=s->pc; goto dispatch; }
goto P_0c011896;
P_0c011894: /* original e464, guest PC 0x0c011894 */
if(!s->budget--) { s->failed_pc=0x0c011894u; return 0; }
r[4]=0x00000064u;
goto P_0c011896;
P_0c011896: /* original d317, guest PC 0x0c011896 */
if(!s->budget--) { s->failed_pc=0x0c011896u; return 0; }
r[3]=read(ram,0x0c0118f4u,4);
goto P_0c011898;
P_0c011898: /* original e03c, guest PC 0x0c011898 */
if(!s->budget--) { s->failed_pc=0x0c011898u; return 0; }
r[0]=0x0000003cu;
goto P_0c01189a;
P_0c01189a: /* original 6232, guest PC 0x0c01189a */
if(!s->budget--) { s->failed_pc=0x0c01189au; return 0; }
tmp=read(ram,r[3],4);
r[2]=tmp;
goto P_0c01189c;
P_0c01189c: /* original 02b4, guest PC 0x0c01189c */
if(!s->budget--) { s->failed_pc=0x0c01189cu; return 0; }
write(ram,r[2]+r[0],r[11],1);
goto P_0c01189e;
P_0c01189e: /* original 4f26, guest PC 0x0c01189e */
if(!s->budget--) { s->failed_pc=0x0c01189eu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0118a0;
P_0c0118a0: /* original 6bf6, guest PC 0x0c0118a0 */
if(!s->budget--) { s->failed_pc=0x0c0118a0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0118a2;
P_0c0118a2: /* original 6cf6, guest PC 0x0c0118a2 */
if(!s->budget--) { s->failed_pc=0x0c0118a2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0118a4;
P_0c0118a4: /* original 6df6, guest PC 0x0c0118a4 */
if(!s->budget--) { s->failed_pc=0x0c0118a4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0118a6;
P_0c0118a6: /* original 000b, guest PC 0x0c0118a6 */
if(!s->budget--) { s->failed_pc=0x0c0118a6u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0118a8: /* original 6ef6, guest PC 0x0c0118a8 */
if(!s->budget--) { s->failed_pc=0x0c0118a8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0118aau,s,ram);
P_0c0118f8: /* original d320, guest PC 0x0c0118f8 */
if(!s->budget--) { s->failed_pc=0x0c0118f8u; return 0; }
r[3]=read(ram,0x0c01197cu,4);
goto P_0c0118fa;
P_0c0118fa: /* original e400, guest PC 0x0c0118fa */
if(!s->budget--) { s->failed_pc=0x0c0118fau; return 0; }
r[4]=0x00000000u;
goto P_0c0118fc;
P_0c0118fc: /* original 963c, guest PC 0x0c0118fc */
if(!s->budget--) { s->failed_pc=0x0c0118fcu; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c011978u,2);
goto P_0c0118fe;
P_0c0118fe: /* original 6532, guest PC 0x0c0118fe */
if(!s->budget--) { s->failed_pc=0x0c0118feu; return 0; }
tmp=read(ram,r[3],4);
r[5]=tmp;
goto P_0c011900;
P_0c011900: /* original 9739, guest PC 0x0c011900 */
if(!s->budget--) { s->failed_pc=0x0c011900u; return 0; }
r[7]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c011976u,2);
goto P_0c011902;
P_0c011902: /* original 8458, guest PC 0x0c011902 */
if(!s->budget--) { s->failed_pc=0x0c011902u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[5]+8,1);
goto P_0c011904;
P_0c011904: /* original 2078, guest PC 0x0c011904 */
if(!s->budget--) { s->failed_pc=0x0c011904u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[7])==0)!=0);
goto P_0c011906;
P_0c011906: /* original 8b02, guest PC 0x0c011906 */
if(!s->budget--) { s->failed_pc=0x0c011906u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c01190e; }
goto P_0c011908;
P_0c011908: /* original 7401, guest PC 0x0c011908 */
if(!s->budget--) { s->failed_pc=0x0c011908u; return 0; }
r[4]+=0x00000001u;
goto P_0c01190a;
P_0c01190a: /* original 3463, guest PC 0x0c01190a */
if(!s->budget--) { s->failed_pc=0x0c01190au; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[6])!=0);
goto P_0c01190c;
P_0c01190c: /* original 8bf9, guest PC 0x0c01190c */
if(!s->budget--) { s->failed_pc=0x0c01190cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c011902; }
goto P_0c01190e;
P_0c01190e: /* original 3460, guest PC 0x0c01190e */
if(!s->budget--) { s->failed_pc=0x0c01190eu; return 0; }
r[17]=(r[17]&~1u)|((r[4]==r[6])!=0);
goto P_0c011910;
P_0c011910: /* original 8910, guest PC 0x0c011910 */
if(!s->budget--) { s->failed_pc=0x0c011910u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c011934; }
goto P_0c011912;
P_0c011912: /* original e010, guest PC 0x0c011912 */
if(!s->budget--) { s->failed_pc=0x0c011912u; return 0; }
r[0]=0x00000010u;
goto P_0c011914;
P_0c011914: /* original 065c, guest PC 0x0c011914 */
if(!s->budget--) { s->failed_pc=0x0c011914u; return 0; }
r[6]=(uint32_t)(int32_t)(int8_t)read(ram,r[5]+r[0],1);
goto P_0c011916;
P_0c011916: /* original 646e, guest PC 0x0c011916 */
if(!s->budget--) { s->failed_pc=0x0c011916u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)r[6];
goto P_0c011918;
P_0c011918: /* original 6043, guest PC 0x0c011918 */
if(!s->budget--) { s->failed_pc=0x0c011918u; return 0; }
r[0]=r[4];
goto P_0c01191a;
P_0c01191a: /* original e314, guest PC 0x0c01191a */
if(!s->budget--) { s->failed_pc=0x0c01191au; return 0; }
r[3]=0x00000014u;
goto P_0c01191c;
P_0c01191c: /* original 8860, guest PC 0x0c01191c */
if(!s->budget--) { s->failed_pc=0x0c01191cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000060u)!=0);
goto P_0c01191e;
P_0c01191e: /* original 335c, guest PC 0x0c01191e */
if(!s->budget--) { s->failed_pc=0x0c01191eu; return 0; }
r[3]+=r[5];
goto P_0c011920;
P_0c011920: /* original 8d06, guest PC 0x0c011920 */
if(!s->budget--) { s->failed_pc=0x0c011920u; return 0; }
cond=r[17]&1u;
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[3],1);
r[3]=tmp;
if(cond) { goto P_0c011930; }
goto P_0c011924;
P_0c011922: /* original 6330, guest PC 0x0c011922 */
if(!s->budget--) { s->failed_pc=0x0c011922u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[3],1);
r[3]=tmp;
goto P_0c011924;
P_0c011924: /* original 6043, guest PC 0x0c011924 */
if(!s->budget--) { s->failed_pc=0x0c011924u; return 0; }
r[0]=r[4];
goto P_0c011926;
P_0c011926: /* original 8861, guest PC 0x0c011926 */
if(!s->budget--) { s->failed_pc=0x0c011926u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000061u)!=0);
goto P_0c011928;
P_0c011928: /* original 8902, guest PC 0x0c011928 */
if(!s->budget--) { s->failed_pc=0x0c011928u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c011930; }
goto P_0c01192a;
P_0c01192a: /* original 6043, guest PC 0x0c01192a */
if(!s->budget--) { s->failed_pc=0x0c01192au; return 0; }
r[0]=r[4];
goto P_0c01192c;
P_0c01192c: /* original 8862, guest PC 0x0c01192c */
if(!s->budget--) { s->failed_pc=0x0c01192cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000062u)!=0);
goto P_0c01192e;
P_0c01192e: /* original 8b01, guest PC 0x0c01192e */
if(!s->budget--) { s->failed_pc=0x0c01192eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c011934; }
goto P_0c011930;
P_0c011930: /* original 000b, guest PC 0x0c011930 */
if(!s->budget--) { s->failed_pc=0x0c011930u; return 0; }
target=r[16];
r[0]=0x00000000u;
s->pc=target; return ram->oob==0;
P_0c011932: /* original e000, guest PC 0x0c011932 */
if(!s->budget--) { s->failed_pc=0x0c011932u; return 0; }
r[0]=0x00000000u;
goto P_0c011934;
P_0c011934: /* original e001, guest PC 0x0c011934 */
if(!s->budget--) { s->failed_pc=0x0c011934u; return 0; }
r[0]=0x00000001u;
goto P_0c011936;
P_0c011936: /* original 000b, guest PC 0x0c011936 */
if(!s->budget--) { s->failed_pc=0x0c011936u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c011938: /* original 0009, guest PC 0x0c011938 */
if(!s->budget--) { s->failed_pc=0x0c011938u; return 0; }
return vf3_matrix_family(0x0c01193au,s,ram);
unsupported: s->failed_pc=target; return 0;
}
static const uint32_t owned_pcs[]={
0x0c010368u,0x0c01036au,0x0c01036cu,0x0c01036eu,0x0c010370u,0x0c010372u,0x0c010374u,0x0c010376u,0x0c010378u,0x0c01037au,0x0c01037cu,0x0c01037eu,0x0c010380u,0x0c010382u,0x0c010384u,0x0c010386u,
0x0c010388u,0x0c01038au,0x0c01038cu,0x0c01038eu,0x0c010390u,0x0c010392u,0x0c010394u,0x0c010396u,0x0c010398u,0x0c01039au,0x0c01039cu,0x0c01039eu,0x0c0103a0u,0x0c0103a2u,0x0c0103a4u,0x0c0103a6u,
0x0c0103a8u,0x0c0109f6u,0x0c0109f8u,0x0c0109fau,0x0c0109fcu,0x0c0109feu,0x0c010a00u,0x0c010a02u,0x0c010a04u,0x0c010a06u,0x0c010a08u,0x0c010a0au,0x0c010a0cu,0x0c010a0eu,0x0c010c2eu,0x0c010c30u,
0x0c010c32u,0x0c010c34u,0x0c010c36u,0x0c010c38u,0x0c010c3au,0x0c010c3cu,0x0c010c3eu,0x0c010c40u,0x0c010c42u,0x0c010c44u,0x0c010c46u,0x0c010c48u,0x0c010c4au,0x0c010c4cu,0x0c010c4eu,0x0c010c50u,
0x0c010c52u,0x0c010c54u,0x0c010c56u,0x0c010c58u,0x0c010c5au,0x0c010c5cu,0x0c010c5eu,0x0c010c60u,0x0c010c62u,0x0c010c64u,0x0c010c66u,0x0c010c68u,0x0c010c6au,0x0c010c6cu,0x0c010c6eu,0x0c010c70u,
0x0c010c72u,0x0c010c74u,0x0c010c76u,0x0c010c78u,0x0c010c7au,0x0c010c7cu,0x0c010c7eu,0x0c010c80u,0x0c010c82u,0x0c010c84u,0x0c010c86u,0x0c010c88u,0x0c010c8au,0x0c010c8cu,0x0c010c8eu,0x0c010c90u,
0x0c010c92u,0x0c010c94u,0x0c010c96u,0x0c010c98u,0x0c010c9au,0x0c010c9cu,0x0c010c9eu,0x0c010ca0u,0x0c010ca2u,0x0c010ca4u,0x0c010ca6u,0x0c010ca8u,0x0c010caau,0x0c010cacu,0x0c010caeu,0x0c010cb0u,
0x0c010cb2u,0x0c010cb4u,0x0c010cb6u,0x0c010cb8u,0x0c010cbau,0x0c010cbcu,0x0c010cbeu,0x0c010cc0u,0x0c010cc2u,0x0c010cc4u,0x0c010cc6u,0x0c010cc8u,0x0c010ccau,0x0c010cccu,0x0c010cceu,0x0c010cd0u,
0x0c010cd2u,0x0c010cd4u,0x0c010cd6u,0x0c010cd8u,0x0c010cdau,0x0c010cdcu,0x0c010cdeu,0x0c010ce0u,0x0c010ce2u,0x0c010ce4u,0x0c010f42u,0x0c010f44u,0x0c010f46u,0x0c010f48u,0x0c010f4au,0x0c010f4cu,
0x0c010f4eu,0x0c010f50u,0x0c010f52u,0x0c010f54u,0x0c010f56u,0x0c010f58u,0x0c010f5au,0x0c010f5cu,0x0c010f5eu,0x0c010f60u,0x0c010f62u,0x0c010f64u,0x0c010f66u,0x0c010f68u,0x0c010f6au,0x0c010f6cu,
0x0c010f6eu,0x0c010f70u,0x0c010f72u,0x0c010f74u,0x0c010f76u,0x0c010f78u,0x0c010f7au,0x0c010f7cu,0x0c010f7eu,0x0c010f80u,0x0c010f82u,0x0c010f84u,0x0c010f86u,0x0c010f88u,0x0c010f8au,0x0c010f8cu,
0x0c010f8eu,0x0c010f90u,0x0c010f92u,0x0c010f94u,0x0c010f96u,0x0c010f98u,0x0c010f9au,0x0c010f9cu,0x0c010f9eu,0x0c010fa0u,0x0c010fa2u,0x0c010fa4u,0x0c010fa6u,0x0c010fa8u,0x0c010faau,0x0c010facu,
0x0c010faeu,0x0c010fb0u,0x0c010fb2u,0x0c010fb4u,0x0c010fb6u,0x0c010fb8u,0x0c010fbau,0x0c010fbcu,0x0c010fbeu,0x0c010fc0u,0x0c010fc2u,0x0c010fc4u,0x0c010fc6u,0x0c010fc8u,0x0c010fcau,0x0c010fccu,
0x0c010fceu,0x0c010fd0u,0x0c010fd2u,0x0c010fd4u,0x0c010fd6u,0x0c010fd8u,0x0c010fdau,0x0c010fdcu,0x0c010fdeu,0x0c010fe0u,0x0c010fe2u,0x0c010fe4u,0x0c010fe6u,0x0c010fe8u,0x0c010feau,0x0c010fecu,
0x0c010feeu,0x0c010ff0u,0x0c010ff2u,0x0c010ff4u,0x0c010ff6u,0x0c010ff8u,0x0c010ffau,0x0c010ffcu,0x0c010ffeu,0x0c011000u,0x0c011002u,0x0c011004u,0x0c011006u,0x0c011008u,0x0c01100au,0x0c01100cu,
0x0c01100eu,0x0c011010u,0x0c011012u,0x0c011014u,0x0c011016u,0x0c011018u,0x0c01101au,0x0c01101cu,0x0c01101eu,0x0c011020u,0x0c011022u,0x0c011024u,0x0c011026u,0x0c011028u,0x0c01102au,0x0c01102cu,
0x0c01102eu,0x0c011030u,0x0c011032u,0x0c011034u,0x0c011036u,0x0c011038u,0x0c01103au,0x0c01103cu,0x0c01103eu,0x0c011040u,0x0c011042u,0x0c0113c2u,0x0c0113c4u,0x0c0113c6u,0x0c0113c8u,0x0c0113cau,
0x0c0113ccu,0x0c0113ceu,0x0c0113d0u,0x0c0113d2u,0x0c0113d4u,0x0c0113d6u,0x0c0113d8u,0x0c0113dau,0x0c0113dcu,0x0c0113deu,0x0c0113e0u,0x0c0113e2u,0x0c0113e4u,0x0c0113e6u,0x0c0113e8u,0x0c0113eau,
0x0c0113ecu,0x0c0113eeu,0x0c0113f0u,0x0c0113f2u,0x0c0113f4u,0x0c0113f6u,0x0c0113f8u,0x0c0113fau,0x0c0113fcu,0x0c0113feu,0x0c011400u,0x0c011402u,0x0c011404u,0x0c011406u,0x0c011408u,0x0c01140au,
0x0c01140cu,0x0c01140eu,0x0c011410u,0x0c011412u,0x0c011414u,0x0c011416u,0x0c011418u,0x0c01141au,0x0c01141cu,0x0c01141eu,0x0c011420u,0x0c011422u,0x0c011424u,0x0c011426u,0x0c011428u,0x0c01142au,
0x0c01142cu,0x0c01142eu,0x0c011430u,0x0c011432u,0x0c011434u,0x0c011436u,0x0c011438u,0x0c01143au,0x0c01143cu,0x0c01143eu,0x0c011440u,0x0c011442u,0x0c011444u,0x0c011446u,0x0c011448u,0x0c01144au,
0x0c01144cu,0x0c01144eu,0x0c011450u,0x0c011452u,0x0c011454u,0x0c011456u,0x0c011458u,0x0c01145au,0x0c01145cu,0x0c01145eu,0x0c011460u,0x0c011462u,0x0c011464u,0x0c011466u,0x0c011468u,0x0c0114b8u,
0x0c0114bau,0x0c0114bcu,0x0c0114beu,0x0c0114c0u,0x0c0114c2u,0x0c0114c4u,0x0c0114c6u,0x0c0114c8u,0x0c0114cau,0x0c0114ccu,0x0c0114ceu,0x0c0114d0u,0x0c0114d2u,0x0c0114d4u,0x0c0114d6u,0x0c0114d8u,
0x0c0114dau,0x0c0114dcu,0x0c0114deu,0x0c0114e0u,0x0c0114e2u,0x0c0114e4u,0x0c0114e6u,0x0c0114e8u,0x0c0114eau,0x0c0114ecu,0x0c0114eeu,0x0c0114f0u,0x0c0114f2u,0x0c0114f4u,0x0c0114f6u,0x0c0114f8u,
0x0c0114fau,0x0c0114fcu,0x0c0114feu,0x0c011500u,0x0c011502u,0x0c011504u,0x0c011506u,0x0c011508u,0x0c01150au,0x0c01150cu,0x0c01150eu,0x0c011510u,0x0c011512u,0x0c011514u,0x0c011516u,0x0c011518u,
0x0c01151au,0x0c01151cu,0x0c01151eu,0x0c011520u,0x0c011522u,0x0c011524u,0x0c011526u,0x0c011528u,0x0c01152au,0x0c01152cu,0x0c01152eu,0x0c011530u,0x0c011532u,0x0c011534u,0x0c011536u,0x0c011538u,
0x0c01153au,0x0c01153cu,0x0c01153eu,0x0c011540u,0x0c011542u,0x0c011544u,0x0c011546u,0x0c011548u,0x0c01154au,0x0c01154cu,0x0c01154eu,0x0c011550u,0x0c011552u,0x0c011554u,0x0c011556u,0x0c011558u,
0x0c01155au,0x0c01155cu,0x0c01155eu,0x0c011560u,0x0c011562u,0x0c011564u,0x0c011566u,0x0c011568u,0x0c01156au,0x0c01156cu,0x0c01156eu,0x0c011570u,0x0c011572u,0x0c011574u,0x0c011576u,0x0c011578u,
0x0c01157au,0x0c01157cu,0x0c01157eu,0x0c011580u,0x0c011582u,0x0c011584u,0x0c011586u,0x0c011588u,0x0c01158au,0x0c01158cu,0x0c01158eu,0x0c011590u,0x0c011592u,0x0c011594u,0x0c011596u,0x0c011598u,
0x0c01159au,0x0c01159cu,0x0c01159eu,0x0c0115a0u,0x0c0115c2u,0x0c0115c4u,0x0c0115c6u,0x0c0115c8u,0x0c0115cau,0x0c0115ccu,0x0c0115ceu,0x0c0115d0u,0x0c0115d2u,0x0c0115d4u,0x0c0115d6u,0x0c0115d8u,
0x0c0115dau,0x0c0115dcu,0x0c0115deu,0x0c0115e0u,0x0c0115e2u,0x0c0115e4u,0x0c0115e6u,0x0c0115e8u,0x0c0115eau,0x0c0115ecu,0x0c0115eeu,0x0c0115f0u,0x0c0115f2u,0x0c0115f4u,0x0c0115f6u,0x0c0115f8u,
0x0c0115fau,0x0c0115fcu,0x0c0115feu,0x0c011600u,0x0c011602u,0x0c011604u,0x0c011606u,0x0c011608u,0x0c01160au,0x0c01160cu,0x0c01160eu,0x0c011610u,0x0c011612u,0x0c011614u,0x0c011616u,0x0c011618u,
0x0c01161au,0x0c01161cu,0x0c01161eu,0x0c011620u,0x0c011622u,0x0c011624u,0x0c011626u,0x0c011628u,0x0c01162au,0x0c01162cu,0x0c01162eu,0x0c011630u,0x0c011632u,0x0c011634u,0x0c011636u,0x0c011638u,
0x0c01163au,0x0c01163cu,0x0c01163eu,0x0c011640u,0x0c011642u,0x0c011644u,0x0c011646u,0x0c011648u,0x0c01164au,0x0c01164cu,0x0c01164eu,0x0c011650u,0x0c011652u,0x0c011654u,0x0c011656u,0x0c011658u,
0x0c01165au,0x0c01165cu,0x0c01165eu,0x0c011660u,0x0c011662u,0x0c011664u,0x0c011666u,0x0c011668u,0x0c01166au,0x0c01166cu,0x0c01166eu,0x0c011670u,0x0c011672u,0x0c011674u,0x0c011676u,0x0c011678u,
0x0c01167au,0x0c01167cu,0x0c01167eu,0x0c011680u,0x0c011682u,0x0c011684u,0x0c011686u,0x0c011688u,0x0c01168au,0x0c01168cu,0x0c01168eu,0x0c011690u,0x0c011692u,0x0c011694u,0x0c011696u,0x0c011698u,
0x0c01169au,0x0c01169cu,0x0c01169eu,0x0c0116a0u,0x0c0116a2u,0x0c0116a4u,0x0c0116a6u,0x0c0116a8u,0x0c0116aau,0x0c0116acu,0x0c0116aeu,0x0c0116b0u,0x0c0116b2u,0x0c0116b4u,0x0c0116b6u,0x0c0116b8u,
0x0c0116bau,0x0c0116bcu,0x0c0116beu,0x0c0116c0u,0x0c0116c2u,0x0c0116c4u,0x0c0116c6u,0x0c0116c8u,0x0c0116cau,0x0c0116ccu,0x0c0116ceu,0x0c0116d0u,0x0c0116d2u,0x0c0116d4u,0x0c0116d6u,0x0c0116d8u,
0x0c0116dau,0x0c0116dcu,0x0c0116deu,0x0c0116e0u,0x0c0116e2u,0x0c0116e4u,0x0c0116e6u,0x0c0116e8u,0x0c0116eau,0x0c0116ecu,0x0c0116eeu,0x0c0116f0u,0x0c0116f2u,0x0c0116f4u,0x0c0116f6u,0x0c0116f8u,
0x0c0116fau,0x0c0116fcu,0x0c0116feu,0x0c011700u,0x0c011702u,0x0c011704u,0x0c011706u,0x0c011708u,0x0c01170au,0x0c01170cu,0x0c01170eu,0x0c011710u,0x0c011712u,0x0c011714u,0x0c011716u,0x0c011718u,
0x0c01171au,0x0c01171cu,0x0c01171eu,0x0c011780u,0x0c011782u,0x0c011784u,0x0c011786u,0x0c011788u,0x0c01178au,0x0c01178cu,0x0c01178eu,0x0c011790u,0x0c011792u,0x0c011794u,0x0c011796u,0x0c011798u,
0x0c01179au,0x0c01179cu,0x0c01179eu,0x0c0117a0u,0x0c0117a2u,0x0c0117a4u,0x0c0117a6u,0x0c0117a8u,0x0c0117aau,0x0c0117acu,0x0c0117aeu,0x0c0117b0u,0x0c0117b2u,0x0c0117b4u,0x0c0117b6u,0x0c0117b8u,
0x0c0117bau,0x0c0117bcu,0x0c0117beu,0x0c0117c0u,0x0c0117c2u,0x0c0117c4u,0x0c0117c6u,0x0c0117c8u,0x0c0117cau,0x0c0117ccu,0x0c0117ceu,0x0c0117d0u,0x0c0117d2u,0x0c0117d4u,0x0c0117d6u,0x0c0117d8u,
0x0c0117dau,0x0c0117dcu,0x0c0117deu,0x0c0117e0u,0x0c0117e2u,0x0c0117e4u,0x0c0117e6u,0x0c0117e8u,0x0c0117eau,0x0c0117ecu,0x0c0117eeu,0x0c0117f0u,0x0c0117f2u,0x0c0117f4u,0x0c0117f6u,0x0c0117f8u,
0x0c0117fau,0x0c0117fcu,0x0c0117feu,0x0c011800u,0x0c011802u,0x0c011804u,0x0c011806u,0x0c011808u,0x0c01180au,0x0c01180cu,0x0c01180eu,0x0c011810u,0x0c011812u,0x0c011814u,0x0c011816u,0x0c011818u,
0x0c01181au,0x0c01181cu,0x0c01181eu,0x0c011820u,0x0c011822u,0x0c011824u,0x0c011826u,0x0c011828u,0x0c01182au,0x0c01182cu,0x0c01182eu,0x0c011830u,0x0c011832u,0x0c011834u,0x0c011836u,0x0c011838u,
0x0c01183au,0x0c01183cu,0x0c01183eu,0x0c011840u,0x0c011842u,0x0c011844u,0x0c011846u,0x0c011848u,0x0c01184au,0x0c01184cu,0x0c01184eu,0x0c011850u,0x0c011852u,0x0c011854u,0x0c011856u,0x0c011858u,
0x0c01185au,0x0c01185cu,0x0c01185eu,0x0c011860u,0x0c011862u,0x0c011864u,0x0c011866u,0x0c011868u,0x0c01186au,0x0c01186cu,0x0c01186eu,0x0c011870u,0x0c011872u,0x0c011874u,0x0c011876u,0x0c011878u,
0x0c01187au,0x0c01187cu,0x0c01187eu,0x0c011880u,0x0c011882u,0x0c011884u,0x0c011886u,0x0c011888u,0x0c01188au,0x0c01188cu,0x0c01188eu,0x0c011890u,0x0c011892u,0x0c011894u,0x0c011896u,0x0c011898u,
0x0c01189au,0x0c01189cu,0x0c01189eu,0x0c0118a0u,0x0c0118a2u,0x0c0118a4u,0x0c0118a6u,0x0c0118a8u,0x0c0118f8u,0x0c0118fau,0x0c0118fcu,0x0c0118feu,0x0c011900u,0x0c011902u,0x0c011904u,0x0c011906u,
0x0c011908u,0x0c01190au,0x0c01190cu,0x0c01190eu,0x0c011910u,0x0c011912u,0x0c011914u,0x0c011916u,0x0c011918u,0x0c01191au,0x0c01191cu,0x0c01191eu,0x0c011920u,0x0c011922u,0x0c011924u,0x0c011926u,
0x0c011928u,0x0c01192au,0x0c01192cu,0x0c01192eu,0x0c011930u,0x0c011932u,0x0c011934u,0x0c011936u,0x0c011938u,
};
static const uint32_t claim_pcs[]={
0x0c010368u,0x0c01036au,0x0c01036cu,0x0c01036eu,0x0c010370u,0x0c010372u,0x0c010374u,0x0c010376u,0x0c010378u,0x0c01037au,0x0c01037cu,0x0c01037eu,0x0c010380u,0x0c010382u,0x0c010384u,0x0c010386u,
0x0c010388u,0x0c01038au,0x0c01038cu,0x0c01038eu,0x0c010390u,0x0c010392u,0x0c010394u,0x0c010396u,0x0c010398u,0x0c01039au,0x0c01039cu,0x0c01039eu,0x0c0103a0u,0x0c0103a2u,0x0c0103a4u,0x0c0103a6u,
0x0c0103a8u,0x0c0109f6u,0x0c0109f8u,0x0c0109fau,0x0c0109fcu,0x0c0109feu,0x0c010a00u,0x0c010a02u,0x0c010a04u,0x0c010a06u,0x0c010a08u,0x0c010a0au,0x0c010a0cu,0x0c010a0eu,0x0c010c2eu,0x0c010c30u,
0x0c010c32u,0x0c010c34u,0x0c010c36u,0x0c010c38u,0x0c010c3au,0x0c010c3cu,0x0c010c3eu,0x0c010c40u,0x0c010c42u,0x0c010c44u,0x0c010c46u,0x0c010c48u,0x0c010c4au,0x0c010c4cu,0x0c010c4eu,0x0c010c50u,
0x0c010c52u,0x0c010c54u,0x0c010c56u,0x0c010c58u,0x0c010c5au,0x0c010c5cu,0x0c010c5eu,0x0c010c60u,0x0c010c62u,0x0c010c64u,0x0c010c66u,0x0c010c68u,0x0c010c6au,0x0c010c6cu,0x0c010c6eu,0x0c010c70u,
0x0c010c72u,0x0c010c74u,0x0c010c76u,0x0c010c78u,0x0c010c7au,0x0c010c7cu,0x0c010c7eu,0x0c010c80u,0x0c010c82u,0x0c010c84u,0x0c010c86u,0x0c010c88u,0x0c010c8au,0x0c010c8cu,0x0c010c8eu,0x0c010c90u,
0x0c010c92u,0x0c010c94u,0x0c010c96u,0x0c010c98u,0x0c010c9au,0x0c010c9cu,0x0c010c9eu,0x0c010ca0u,0x0c010ca2u,0x0c010ca4u,0x0c010ca6u,0x0c010ca8u,0x0c010caau,0x0c010cacu,0x0c010caeu,0x0c010cb0u,
0x0c010cb2u,0x0c010cb4u,0x0c010cb6u,0x0c010cb8u,0x0c010cbau,0x0c010cbcu,0x0c010cbeu,0x0c010cc0u,0x0c010cc2u,0x0c010cc4u,0x0c010cc6u,0x0c010cc8u,0x0c010ccau,0x0c010cccu,0x0c010cceu,0x0c010cd0u,
0x0c010cd2u,0x0c010cd4u,0x0c010cd6u,0x0c010cd8u,0x0c010cdau,0x0c010cdcu,0x0c010cdeu,0x0c010ce0u,0x0c010ce2u,0x0c010ce4u,0x0c010f42u,0x0c010f44u,0x0c010f46u,0x0c010f48u,0x0c010f4au,0x0c010f4cu,
0x0c010f4eu,0x0c010f50u,0x0c010f52u,0x0c010f54u,0x0c010f56u,0x0c010f58u,0x0c010f5au,0x0c010f5cu,0x0c010f5eu,0x0c010f60u,0x0c010f62u,0x0c010f64u,0x0c010f66u,0x0c010f68u,0x0c010f6au,0x0c010f6cu,
0x0c010f6eu,0x0c010f70u,0x0c010f72u,0x0c010f74u,0x0c010f76u,0x0c010f78u,0x0c010f7au,0x0c010f7cu,0x0c010f7eu,0x0c010f80u,0x0c010f82u,0x0c010f84u,0x0c010f86u,0x0c010f88u,0x0c010f8au,0x0c010f8cu,
0x0c010f8eu,0x0c010f90u,0x0c010f92u,0x0c010f94u,0x0c010f96u,0x0c010f98u,0x0c010f9au,0x0c010f9cu,0x0c010f9eu,0x0c010fa0u,0x0c010fa2u,0x0c010fa4u,0x0c010fa6u,0x0c010fa8u,0x0c010faau,0x0c010facu,
0x0c010faeu,0x0c010fb0u,0x0c010fb2u,0x0c010fb4u,0x0c010fb6u,0x0c010fb8u,0x0c010fbau,0x0c010fbcu,0x0c010fbeu,0x0c010fc0u,0x0c010fc2u,0x0c010fc4u,0x0c010fc6u,0x0c010fc8u,0x0c010fcau,0x0c010fccu,
0x0c010fceu,0x0c010fd0u,0x0c010fd2u,0x0c010fd4u,0x0c010fd6u,0x0c010fd8u,0x0c010fdau,0x0c010fdcu,0x0c010fdeu,0x0c010fe0u,0x0c010fe2u,0x0c010fe4u,0x0c010fe6u,0x0c010fe8u,0x0c010feau,0x0c010fecu,
0x0c010feeu,0x0c010ff0u,0x0c010ff2u,0x0c010ff4u,0x0c010ff6u,0x0c010ff8u,0x0c010ffau,0x0c010ffcu,0x0c010ffeu,0x0c011000u,0x0c011002u,0x0c011004u,0x0c011006u,0x0c011008u,0x0c01100au,0x0c01100cu,
0x0c01100eu,0x0c011010u,0x0c011012u,0x0c011014u,0x0c011016u,0x0c011018u,0x0c01101au,0x0c01101cu,0x0c01101eu,0x0c011020u,0x0c011022u,0x0c011024u,0x0c011026u,0x0c011028u,0x0c01102au,0x0c01102cu,
0x0c01102eu,0x0c011030u,0x0c011032u,0x0c011034u,0x0c011036u,0x0c011038u,0x0c01103au,0x0c01103cu,0x0c01103eu,0x0c011040u,0x0c011042u,0x0c0113c2u,0x0c0113c4u,0x0c0113c6u,0x0c0113c8u,0x0c0113cau,
0x0c0113ccu,0x0c0113ceu,0x0c0113d0u,0x0c0113d2u,0x0c0113d4u,0x0c0113d6u,0x0c0113d8u,0x0c0113dau,0x0c0113dcu,0x0c0113deu,0x0c0113e0u,0x0c0113e2u,0x0c0113e4u,0x0c0113e6u,0x0c0113e8u,0x0c0113eau,
0x0c0113ecu,0x0c0113eeu,0x0c0113f0u,0x0c0113f2u,0x0c0113f4u,0x0c0113f6u,0x0c0113f8u,0x0c0113fau,0x0c0113fcu,0x0c0113feu,0x0c011400u,0x0c011402u,0x0c011404u,0x0c011406u,0x0c011408u,0x0c01140au,
0x0c01140cu,0x0c01140eu,0x0c011410u,0x0c011412u,0x0c011414u,0x0c011416u,0x0c011418u,0x0c01141au,0x0c01141cu,0x0c01141eu,0x0c011420u,0x0c011422u,0x0c011424u,0x0c011426u,0x0c011428u,0x0c01142au,
0x0c01142cu,0x0c01142eu,0x0c011430u,0x0c011432u,0x0c011434u,0x0c011436u,0x0c011438u,0x0c01143au,0x0c01143cu,0x0c01143eu,0x0c011440u,0x0c011442u,0x0c011444u,0x0c011446u,0x0c011448u,0x0c01144au,
0x0c01144cu,0x0c01144eu,0x0c011450u,0x0c011452u,0x0c011454u,0x0c011456u,0x0c011458u,0x0c01145au,0x0c01145cu,0x0c01145eu,0x0c011460u,0x0c011462u,0x0c011464u,0x0c011466u,0x0c011468u,0x0c0114b8u,
0x0c0114bau,0x0c0114bcu,0x0c0114beu,0x0c0114c0u,0x0c0114c2u,0x0c0114c4u,0x0c0114c6u,0x0c0114c8u,0x0c0114cau,0x0c0114ccu,0x0c0114ceu,0x0c0114d0u,0x0c0114d2u,0x0c0114d4u,0x0c0114d6u,0x0c0114d8u,
0x0c0114dau,0x0c0114dcu,0x0c0114deu,0x0c0114e0u,0x0c0114e2u,0x0c0114e4u,0x0c0114e6u,0x0c0114e8u,0x0c0114eau,0x0c0114ecu,0x0c0114eeu,0x0c0114f0u,0x0c0114f2u,0x0c0114f4u,0x0c0114f6u,0x0c0114f8u,
0x0c0114fau,0x0c0114fcu,0x0c0114feu,0x0c011500u,0x0c011502u,0x0c011504u,0x0c011506u,0x0c011508u,0x0c01150au,0x0c01150cu,0x0c01150eu,0x0c011510u,0x0c011512u,0x0c011514u,0x0c011516u,0x0c011518u,
0x0c01151au,0x0c01151cu,0x0c01151eu,0x0c011520u,0x0c011522u,0x0c011524u,0x0c011526u,0x0c011528u,0x0c01152au,0x0c01152cu,0x0c01152eu,0x0c011530u,0x0c011532u,0x0c011534u,0x0c011536u,0x0c011538u,
0x0c01153au,0x0c01153cu,0x0c01153eu,0x0c011540u,0x0c011542u,0x0c011544u,0x0c011546u,0x0c011548u,0x0c01154au,0x0c01154cu,0x0c01154eu,0x0c011550u,0x0c011552u,0x0c011554u,0x0c011556u,0x0c011558u,
0x0c01155au,0x0c01155cu,0x0c01155eu,0x0c011560u,0x0c011562u,0x0c011564u,0x0c011566u,0x0c011568u,0x0c01156au,0x0c01156cu,0x0c01156eu,0x0c011570u,0x0c011572u,0x0c011574u,0x0c011576u,0x0c011578u,
0x0c01157au,0x0c01157cu,0x0c01157eu,0x0c011580u,0x0c011582u,0x0c011584u,0x0c011586u,0x0c011588u,0x0c01158au,0x0c01158cu,0x0c01158eu,0x0c011590u,0x0c011592u,0x0c011594u,0x0c011596u,0x0c011598u,
0x0c01159au,0x0c01159cu,0x0c01159eu,0x0c0115a0u,0x0c0115c2u,0x0c0115c4u,0x0c0115c6u,0x0c0115c8u,0x0c0115cau,0x0c0115ccu,0x0c0115ceu,0x0c0115d0u,0x0c0115d2u,0x0c0115d4u,0x0c0115d6u,0x0c0115d8u,
0x0c0115dau,0x0c0115dcu,0x0c0115deu,0x0c0115e0u,0x0c0115e2u,0x0c0115e4u,0x0c0115e6u,0x0c0115e8u,0x0c0115eau,0x0c0115ecu,0x0c0115eeu,0x0c0115f0u,0x0c0115f2u,0x0c0115f4u,0x0c0115f6u,0x0c0115f8u,
0x0c0115fau,0x0c0115fcu,0x0c0115feu,0x0c011600u,0x0c011602u,0x0c011604u,0x0c011606u,0x0c011608u,0x0c01160au,0x0c01160cu,0x0c01160eu,0x0c011610u,0x0c011612u,0x0c011614u,0x0c011616u,0x0c011618u,
0x0c01161au,0x0c01161cu,0x0c01161eu,0x0c011620u,0x0c011622u,0x0c011624u,0x0c011626u,0x0c011628u,0x0c01162au,0x0c01162cu,0x0c01162eu,0x0c011630u,0x0c011632u,0x0c011634u,0x0c011636u,0x0c011638u,
0x0c01163au,0x0c01163cu,0x0c01163eu,0x0c011640u,0x0c011642u,0x0c011644u,0x0c011646u,0x0c011648u,0x0c01164au,0x0c01164cu,0x0c01164eu,0x0c011650u,0x0c011652u,0x0c011654u,0x0c011656u,0x0c011658u,
0x0c01165au,0x0c01165cu,0x0c01165eu,0x0c011660u,0x0c011662u,0x0c011664u,0x0c011666u,0x0c011668u,0x0c01166au,0x0c01166cu,0x0c01166eu,0x0c011670u,0x0c011672u,0x0c011674u,0x0c011676u,0x0c011678u,
0x0c01167au,0x0c01167cu,0x0c01167eu,0x0c011680u,0x0c011682u,0x0c011684u,0x0c011686u,0x0c011688u,0x0c01168au,0x0c01168cu,0x0c01168eu,0x0c011690u,0x0c011692u,0x0c011694u,0x0c011696u,0x0c011698u,
0x0c01169au,0x0c01169cu,0x0c01169eu,0x0c0116a0u,0x0c0116a2u,0x0c0116a4u,0x0c0116a6u,0x0c0116a8u,0x0c0116aau,0x0c0116acu,0x0c0116aeu,0x0c0116b0u,0x0c0116b2u,0x0c0116b4u,0x0c0116b6u,0x0c0116b8u,
0x0c0116bau,0x0c0116bcu,0x0c0116beu,0x0c0116c0u,0x0c0116c2u,0x0c0116c4u,0x0c0116c6u,0x0c0116c8u,0x0c0116cau,0x0c0116ccu,0x0c0116ceu,0x0c0116d0u,0x0c0116d2u,0x0c0116d4u,0x0c0116d6u,0x0c0116d8u,
0x0c0116dau,0x0c0116dcu,0x0c0116deu,0x0c0116e0u,0x0c0116e2u,0x0c0116e4u,0x0c0116e6u,0x0c0116e8u,0x0c0116eau,0x0c0116ecu,0x0c0116eeu,0x0c0116f0u,0x0c0116f2u,0x0c0116f4u,0x0c0116f6u,0x0c0116f8u,
0x0c0116fau,0x0c0116fcu,0x0c0116feu,0x0c011700u,0x0c011702u,0x0c011704u,0x0c011706u,0x0c011708u,0x0c01170au,0x0c01170cu,0x0c01170eu,0x0c011710u,0x0c011712u,0x0c011714u,0x0c011716u,0x0c011718u,
0x0c01171au,0x0c01171cu,0x0c01171eu,0x0c011780u,0x0c011782u,0x0c011784u,0x0c011786u,0x0c011788u,0x0c01178au,0x0c01178cu,0x0c01178eu,0x0c011790u,0x0c011792u,0x0c011794u,0x0c011796u,0x0c011798u,
0x0c01179au,0x0c01179cu,0x0c01179eu,0x0c0117a0u,0x0c0117a2u,0x0c0117a4u,0x0c0117a6u,0x0c0117a8u,0x0c0117aau,0x0c0117acu,0x0c0117aeu,0x0c0117b0u,0x0c0117b2u,0x0c0117b4u,0x0c0117b6u,0x0c0117b8u,
0x0c0117bau,0x0c0117bcu,0x0c0117beu,0x0c0117c0u,0x0c0117c2u,0x0c0117c4u,0x0c0117c6u,0x0c0117c8u,0x0c0117cau,0x0c0117ccu,0x0c0117ceu,0x0c0117d0u,0x0c0117d2u,0x0c0117d4u,0x0c0117d6u,0x0c0117d8u,
0x0c0117dau,0x0c0117dcu,0x0c0117deu,0x0c0117e0u,0x0c0117e2u,0x0c0117e4u,0x0c0117e6u,0x0c0117e8u,0x0c0117eau,0x0c0117ecu,0x0c0117eeu,0x0c0117f0u,0x0c0117f2u,0x0c0117f4u,0x0c0117f6u,0x0c0117f8u,
0x0c0117fau,0x0c0117fcu,0x0c0117feu,0x0c011800u,0x0c011802u,0x0c011804u,0x0c011806u,0x0c011808u,0x0c01180au,0x0c01180cu,0x0c01180eu,0x0c011810u,0x0c011812u,0x0c011814u,0x0c011816u,0x0c011818u,
0x0c01181au,0x0c01181cu,0x0c01181eu,0x0c011820u,0x0c011822u,0x0c011824u,0x0c011826u,0x0c011828u,0x0c01182au,0x0c01182cu,0x0c01182eu,0x0c011830u,0x0c011832u,0x0c011834u,0x0c011836u,0x0c011838u,
0x0c01183au,0x0c01183cu,0x0c01183eu,0x0c011840u,0x0c011842u,0x0c011844u,0x0c011846u,0x0c011848u,0x0c01184au,0x0c01184cu,0x0c01184eu,0x0c011850u,0x0c011852u,0x0c011854u,0x0c011856u,0x0c011858u,
0x0c01185au,0x0c01185cu,0x0c01185eu,0x0c011860u,0x0c011862u,0x0c011864u,0x0c011866u,0x0c011868u,0x0c01186au,0x0c01186cu,0x0c01186eu,0x0c011870u,0x0c011872u,0x0c011874u,0x0c011876u,0x0c011878u,
0x0c01187au,0x0c01187cu,0x0c01187eu,0x0c011880u,0x0c011882u,0x0c011884u,0x0c011886u,0x0c011888u,0x0c01188au,0x0c01188cu,0x0c01188eu,0x0c011890u,0x0c011892u,0x0c011894u,0x0c011896u,0x0c011898u,
0x0c01189au,0x0c01189cu,0x0c01189eu,0x0c0118a0u,0x0c0118a2u,0x0c0118a4u,0x0c0118a6u,0x0c0118a8u,0x0c0118f8u,0x0c0118fau,0x0c0118fcu,0x0c0118feu,0x0c011900u,0x0c011902u,0x0c011904u,0x0c011906u,
0x0c011908u,0x0c01190au,0x0c01190cu,0x0c01190eu,0x0c011910u,0x0c011912u,0x0c011914u,0x0c011916u,0x0c011918u,0x0c01191au,0x0c01191cu,0x0c01191eu,0x0c011920u,0x0c011922u,0x0c011924u,0x0c011926u,
0x0c011928u,0x0c01192au,0x0c01192cu,0x0c01192eu,0x0c011930u,0x0c011932u,0x0c011934u,0x0c011936u,0x0c011938u,
};
int vf3_c98_adapter_contains(uint32_t pc) {
pc&=0x1fffffffu; unsigned lo=0,hi=sizeof(claim_pcs)/sizeof(claim_pcs[0]);
while(lo<hi) { unsigned mid=lo+(hi-lo)/2; if(claim_pcs[mid]<pc) lo=mid+1; else hi=mid; }
return lo<sizeof(claim_pcs)/sizeof(claim_pcs[0]) && claim_pcs[lo]==pc;
}
