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
int vf3_tenpp_planned_adapter(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c038eaeu: goto P_0c038eae;
case 0x0c038eb0u: goto P_0c038eb0;
case 0x0c038eb2u: goto P_0c038eb2;
case 0x0c038eb4u: goto P_0c038eb4;
case 0x0c038eb6u: goto P_0c038eb6;
case 0x0c038eb8u: goto P_0c038eb8;
case 0x0c038ebau: goto P_0c038eba;
case 0x0c038ebcu: goto P_0c038ebc;
case 0x0c038ebeu: goto P_0c038ebe;
case 0x0c038ec0u: goto P_0c038ec0;
case 0x0c038ec2u: goto P_0c038ec2;
case 0x0c038ec4u: goto P_0c038ec4;
case 0x0c038ec6u: goto P_0c038ec6;
case 0x0c038ec8u: goto P_0c038ec8;
case 0x0c038ecau: goto P_0c038eca;
case 0x0c038eccu: goto P_0c038ecc;
case 0x0c038eceu: goto P_0c038ece;
case 0x0c038ed0u: goto P_0c038ed0;
case 0x0c038ed2u: goto P_0c038ed2;
case 0x0c038ed4u: goto P_0c038ed4;
case 0x0c038ed6u: goto P_0c038ed6;
case 0x0c038ed8u: goto P_0c038ed8;
case 0x0c038edau: goto P_0c038eda;
case 0x0c038edcu: goto P_0c038edc;
case 0x0c038edeu: goto P_0c038ede;
case 0x0c038ee0u: goto P_0c038ee0;
case 0x0c038ee2u: goto P_0c038ee2;
case 0x0c038ee4u: goto P_0c038ee4;
case 0x0c038ee6u: goto P_0c038ee6;
case 0x0c038ee8u: goto P_0c038ee8;
case 0x0c038eeau: goto P_0c038eea;
case 0x0c038eecu: goto P_0c038eec;
case 0x0c038eeeu: goto P_0c038eee;
case 0x0c038ef0u: goto P_0c038ef0;
case 0x0c038ef2u: goto P_0c038ef2;
case 0x0c038ef4u: goto P_0c038ef4;
case 0x0c038ef6u: goto P_0c038ef6;
case 0x0c038ef8u: goto P_0c038ef8;
case 0x0c038efau: goto P_0c038efa;
case 0x0c038efcu: goto P_0c038efc;
case 0x0c038efeu: goto P_0c038efe;
case 0x0c038f00u: goto P_0c038f00;
case 0x0c038f02u: goto P_0c038f02;
case 0x0c038f04u: goto P_0c038f04;
case 0x0c038f06u: goto P_0c038f06;
case 0x0c038f08u: goto P_0c038f08;
case 0x0c038f0au: goto P_0c038f0a;
case 0x0c038f0cu: goto P_0c038f0c;
case 0x0c038f0eu: goto P_0c038f0e;
case 0x0c038f10u: goto P_0c038f10;
case 0x0c038f12u: goto P_0c038f12;
case 0x0c038f14u: goto P_0c038f14;
case 0x0c038f16u: goto P_0c038f16;
case 0x0c038f18u: goto P_0c038f18;
case 0x0c038f1au: goto P_0c038f1a;
case 0x0c038f1cu: goto P_0c038f1c;
case 0x0c038f1eu: goto P_0c038f1e;
case 0x0c038f20u: goto P_0c038f20;
case 0x0c038f22u: goto P_0c038f22;
case 0x0c038f24u: goto P_0c038f24;
case 0x0c038f26u: goto P_0c038f26;
case 0x0c038f28u: goto P_0c038f28;
case 0x0c038f2au: goto P_0c038f2a;
case 0x0c038f2cu: goto P_0c038f2c;
case 0x0c038f2eu: goto P_0c038f2e;
case 0x0c038f30u: goto P_0c038f30;
case 0x0c038f32u: goto P_0c038f32;
case 0x0c038f34u: goto P_0c038f34;
case 0x0c038f36u: goto P_0c038f36;
case 0x0c038f38u: goto P_0c038f38;
case 0x0c038f4eu: goto P_0c038f4e;
case 0x0c038f50u: goto P_0c038f50;
case 0x0c038f52u: goto P_0c038f52;
case 0x0c038f54u: goto P_0c038f54;
case 0x0c038f56u: goto P_0c038f56;
case 0x0c038f58u: goto P_0c038f58;
case 0x0c038f5au: goto P_0c038f5a;
case 0x0c038f5cu: goto P_0c038f5c;
case 0x0c038f5eu: goto P_0c038f5e;
case 0x0c038f60u: goto P_0c038f60;
case 0x0c038f62u: goto P_0c038f62;
case 0x0c038f64u: goto P_0c038f64;
case 0x0c038f66u: goto P_0c038f66;
case 0x0c038f68u: goto P_0c038f68;
case 0x0c038f6au: goto P_0c038f6a;
case 0x0c038f6cu: goto P_0c038f6c;
case 0x0c038f6eu: goto P_0c038f6e;
case 0x0c038f70u: goto P_0c038f70;
case 0x0c038f72u: goto P_0c038f72;
case 0x0c038f74u: goto P_0c038f74;
case 0x0c038f76u: goto P_0c038f76;
case 0x0c038f78u: goto P_0c038f78;
case 0x0c038f7au: goto P_0c038f7a;
case 0x0c038f7cu: goto P_0c038f7c;
case 0x0c038f7eu: goto P_0c038f7e;
case 0x0c038f80u: goto P_0c038f80;
case 0x0c038f82u: goto P_0c038f82;
case 0x0c038f84u: goto P_0c038f84;
case 0x0c038f86u: goto P_0c038f86;
case 0x0c038f88u: goto P_0c038f88;
case 0x0c038f8au: goto P_0c038f8a;
case 0x0c038f8cu: goto P_0c038f8c;
case 0x0c038f8eu: goto P_0c038f8e;
case 0x0c038f90u: goto P_0c038f90;
case 0x0c038f92u: goto P_0c038f92;
case 0x0c038f94u: goto P_0c038f94;
case 0x0c038f96u: goto P_0c038f96;
case 0x0c038f98u: goto P_0c038f98;
case 0x0c038f9au: goto P_0c038f9a;
case 0x0c038f9cu: goto P_0c038f9c;
case 0x0c038f9eu: goto P_0c038f9e;
case 0x0c038fa0u: goto P_0c038fa0;
case 0x0c038fa2u: goto P_0c038fa2;
case 0x0c038fa4u: goto P_0c038fa4;
case 0x0c038fa6u: goto P_0c038fa6;
case 0x0c038fa8u: goto P_0c038fa8;
case 0x0c038faau: goto P_0c038faa;
case 0x0c038facu: goto P_0c038fac;
case 0x0c038faeu: goto P_0c038fae;
case 0x0c038fb0u: goto P_0c038fb0;
case 0x0c038fb2u: goto P_0c038fb2;
case 0x0c038fb4u: goto P_0c038fb4;
case 0x0c038fb6u: goto P_0c038fb6;
case 0x0c038fb8u: goto P_0c038fb8;
case 0x0c038fbau: goto P_0c038fba;
case 0x0c038fbcu: goto P_0c038fbc;
case 0x0c038fbeu: goto P_0c038fbe;
case 0x0c038fc0u: goto P_0c038fc0;
case 0x0c038fc2u: goto P_0c038fc2;
case 0x0c038fc4u: goto P_0c038fc4;
case 0x0c038fc6u: goto P_0c038fc6;
case 0x0c038fc8u: goto P_0c038fc8;
case 0x0c038fcau: goto P_0c038fca;
case 0x0c038fccu: goto P_0c038fcc;
case 0x0c038fceu: goto P_0c038fce;
case 0x0c038fd0u: goto P_0c038fd0;
case 0x0c038fd2u: goto P_0c038fd2;
case 0x0c038fd4u: goto P_0c038fd4;
case 0x0c038fd6u: goto P_0c038fd6;
case 0x0c03a370u: goto P_0c03a370;
case 0x0c03a372u: goto P_0c03a372;
case 0x0c03a374u: goto P_0c03a374;
case 0x0c03a376u: goto P_0c03a376;
case 0x0c03a378u: goto P_0c03a378;
case 0x0c03a37au: goto P_0c03a37a;
case 0x0c03a380u: goto P_0c03a380;
case 0x0c03a382u: goto P_0c03a382;
case 0x0c03a384u: goto P_0c03a384;
case 0x0c03a386u: goto P_0c03a386;
case 0x0c03a388u: goto P_0c03a388;
case 0x0c03bb40u: goto P_0c03bb40;
case 0x0c03bb42u: goto P_0c03bb42;
case 0x0c03bb44u: goto P_0c03bb44;
case 0x0c03bb46u: goto P_0c03bb46;
case 0x0c03bb48u: goto P_0c03bb48;
case 0x0c03bb4au: goto P_0c03bb4a;
case 0x0c03bb4cu: goto P_0c03bb4c;
case 0x0c03bb4eu: goto P_0c03bb4e;
case 0x0c03bb50u: goto P_0c03bb50;
case 0x0c03bb52u: goto P_0c03bb52;
case 0x0c03bb54u: goto P_0c03bb54;
case 0x0c03bb56u: goto P_0c03bb56;
case 0x0c03bb58u: goto P_0c03bb58;
case 0x0c03bb5au: goto P_0c03bb5a;
case 0x0c03bb5cu: goto P_0c03bb5c;
case 0x0c03bb5eu: goto P_0c03bb5e;
case 0x0c03bb60u: goto P_0c03bb60;
case 0x0c03bb62u: goto P_0c03bb62;
case 0x0c03bb64u: goto P_0c03bb64;
case 0x0c03bb66u: goto P_0c03bb66;
case 0x0c03bb68u: goto P_0c03bb68;
case 0x0c03bb6au: goto P_0c03bb6a;
case 0x0c03bb6cu: goto P_0c03bb6c;
case 0x0c03bb6eu: goto P_0c03bb6e;
case 0x0c03bb70u: goto P_0c03bb70;
case 0x0c03bb72u: goto P_0c03bb72;
case 0x0c03bb74u: goto P_0c03bb74;
case 0x0c03bb76u: goto P_0c03bb76;
case 0x0c03bb78u: goto P_0c03bb78;
case 0x0c03bb7au: goto P_0c03bb7a;
case 0x0c03bb7cu: goto P_0c03bb7c;
case 0x0c03bb7eu: goto P_0c03bb7e;
case 0x0c03bb80u: goto P_0c03bb80;
case 0x0c03bb82u: goto P_0c03bb82;
case 0x0c03bb84u: goto P_0c03bb84;
case 0x0c03bb86u: goto P_0c03bb86;
case 0x0c03bb88u: goto P_0c03bb88;
case 0x0c03bb8au: goto P_0c03bb8a;
case 0x0c03bb8cu: goto P_0c03bb8c;
case 0x0c03bb8eu: goto P_0c03bb8e;
case 0x0c03bb90u: goto P_0c03bb90;
case 0x0c03bb92u: goto P_0c03bb92;
case 0x0c03bb94u: goto P_0c03bb94;
case 0x0c03bb96u: goto P_0c03bb96;
case 0x0c03bb98u: goto P_0c03bb98;
case 0x0c03bb9au: goto P_0c03bb9a;
case 0x0c03bb9cu: goto P_0c03bb9c;
case 0x0c03bb9eu: goto P_0c03bb9e;
case 0x0c03bba0u: goto P_0c03bba0;
case 0x0c03bba2u: goto P_0c03bba2;
case 0x0c03bba4u: goto P_0c03bba4;
case 0x0c03bba6u: goto P_0c03bba6;
case 0x0c03bba8u: goto P_0c03bba8;
case 0x0c03bbaau: goto P_0c03bbaa;
case 0x0c03bbacu: goto P_0c03bbac;
case 0x0c03bbaeu: goto P_0c03bbae;
case 0x0c03bbb0u: goto P_0c03bbb0;
case 0x0c03bbb2u: goto P_0c03bbb2;
case 0x0c03bbb4u: goto P_0c03bbb4;
case 0x0c03bbb6u: goto P_0c03bbb6;
case 0x0c03bbb8u: goto P_0c03bbb8;
case 0x0c03bbbau: goto P_0c03bbba;
case 0x0c03bbbcu: goto P_0c03bbbc;
case 0x0c03bbbeu: goto P_0c03bbbe;
case 0x0c03bbc0u: goto P_0c03bbc0;
case 0x0c03bbc2u: goto P_0c03bbc2;
case 0x0c03bbc4u: goto P_0c03bbc4;
case 0x0c03bbc6u: goto P_0c03bbc6;
case 0x0c03bbc8u: goto P_0c03bbc8;
case 0x0c03bbcau: goto P_0c03bbca;
case 0x0c03bbccu: goto P_0c03bbcc;
case 0x0c03bbceu: goto P_0c03bbce;
case 0x0c03bfb6u: goto P_0c03bfb6;
case 0x0c03bfb8u: goto P_0c03bfb8;
case 0x0c03bfbau: goto P_0c03bfba;
case 0x0c03bfbcu: goto P_0c03bfbc;
case 0x0c03bfbeu: goto P_0c03bfbe;
case 0x0c03bfc0u: goto P_0c03bfc0;
case 0x0c03bfc2u: goto P_0c03bfc2;
case 0x0c03bfc4u: goto P_0c03bfc4;
case 0x0c03bfc6u: goto P_0c03bfc6;
case 0x0c03bfc8u: goto P_0c03bfc8;
case 0x0c03bfcau: goto P_0c03bfca;
case 0x0c03bfccu: goto P_0c03bfcc;
case 0x0c03bfceu: goto P_0c03bfce;
case 0x0c03bfd0u: goto P_0c03bfd0;
case 0x0c03bfd2u: goto P_0c03bfd2;
case 0x0c03bfd4u: goto P_0c03bfd4;
case 0x0c03bfd6u: goto P_0c03bfd6;
case 0x0c03bfd8u: goto P_0c03bfd8;
case 0x0c03bfdau: goto P_0c03bfda;
case 0x0c03bfdcu: goto P_0c03bfdc;
case 0x0c03bfdeu: goto P_0c03bfde;
case 0x0c03bfe0u: goto P_0c03bfe0;
case 0x0c03bfe2u: goto P_0c03bfe2;
case 0x0c03bfe4u: goto P_0c03bfe4;
case 0x0c03bfe6u: goto P_0c03bfe6;
case 0x0c03bfe8u: goto P_0c03bfe8;
case 0x0c03bfeau: goto P_0c03bfea;
case 0x0c03bfecu: goto P_0c03bfec;
case 0x0c03bfeeu: goto P_0c03bfee;
case 0x0c03bff0u: goto P_0c03bff0;
case 0x0c03bff2u: goto P_0c03bff2;
case 0x0c03bff4u: goto P_0c03bff4;
case 0x0c03bff6u: goto P_0c03bff6;
case 0x0c03bff8u: goto P_0c03bff8;
case 0x0c03bffau: goto P_0c03bffa;
case 0x0c03bffcu: goto P_0c03bffc;
case 0x0c03bffeu: goto P_0c03bffe;
case 0x0c03c000u: goto P_0c03c000;
case 0x0c03c002u: goto P_0c03c002;
case 0x0c03c004u: goto P_0c03c004;
case 0x0c03c006u: goto P_0c03c006;
case 0x0c03c008u: goto P_0c03c008;
case 0x0c03c00au: goto P_0c03c00a;
case 0x0c03c00cu: goto P_0c03c00c;
case 0x0c03c00eu: goto P_0c03c00e;
case 0x0c03c010u: goto P_0c03c010;
case 0x0c03c012u: goto P_0c03c012;
case 0x0c03c014u: goto P_0c03c014;
case 0x0c03c016u: goto P_0c03c016;
case 0x0c03c018u: goto P_0c03c018;
case 0x0c03c01au: goto P_0c03c01a;
case 0x0c03c01cu: goto P_0c03c01c;
case 0x0c03c01eu: goto P_0c03c01e;
case 0x0c03c020u: goto P_0c03c020;
case 0x0c03c022u: goto P_0c03c022;
case 0x0c03c024u: goto P_0c03c024;
case 0x0c03c026u: goto P_0c03c026;
case 0x0c03c028u: goto P_0c03c028;
case 0x0c03c02au: goto P_0c03c02a;
case 0x0c03c02cu: goto P_0c03c02c;
case 0x0c03c02eu: goto P_0c03c02e;
case 0x0c03c030u: goto P_0c03c030;
case 0x0c03c032u: goto P_0c03c032;
case 0x0c03c034u: goto P_0c03c034;
case 0x0c03c036u: goto P_0c03c036;
case 0x0c03c038u: goto P_0c03c038;
case 0x0c03c03au: goto P_0c03c03a;
case 0x0c03c03cu: goto P_0c03c03c;
case 0x0c03c03eu: goto P_0c03c03e;
case 0x0c03c040u: goto P_0c03c040;
case 0x0c03c042u: goto P_0c03c042;
case 0x0c03c044u: goto P_0c03c044;
case 0x0c03c046u: goto P_0c03c046;
case 0x0c03c048u: goto P_0c03c048;
case 0x0c03c04au: goto P_0c03c04a;
case 0x0c03c04cu: goto P_0c03c04c;
case 0x0c03c04eu: goto P_0c03c04e;
case 0x0c03c050u: goto P_0c03c050;
case 0x0c03c052u: goto P_0c03c052;
case 0x0c03c054u: goto P_0c03c054;
case 0x0c03c056u: goto P_0c03c056;
case 0x0c03c058u: goto P_0c03c058;
case 0x0c03c05au: goto P_0c03c05a;
case 0x0c03c05cu: goto P_0c03c05c;
case 0x0c03c05eu: goto P_0c03c05e;
case 0x0c03c060u: goto P_0c03c060;
case 0x0c03c062u: goto P_0c03c062;
case 0x0c03c064u: goto P_0c03c064;
case 0x0c03c066u: goto P_0c03c066;
case 0x0c03c068u: goto P_0c03c068;
case 0x0c03c06au: goto P_0c03c06a;
case 0x0c03c06cu: goto P_0c03c06c;
case 0x0c03c06eu: goto P_0c03c06e;
case 0x0c03c070u: goto P_0c03c070;
case 0x0c03c072u: goto P_0c03c072;
case 0x0c03c074u: goto P_0c03c074;
case 0x0c03c076u: goto P_0c03c076;
case 0x0c03c078u: goto P_0c03c078;
case 0x0c03c07au: goto P_0c03c07a;
case 0x0c03c252u: goto P_0c03c252;
case 0x0c03c254u: goto P_0c03c254;
case 0x0c03c256u: goto P_0c03c256;
case 0x0c03c258u: goto P_0c03c258;
case 0x0c03c25au: goto P_0c03c25a;
case 0x0c03c25cu: goto P_0c03c25c;
case 0x0c03c25eu: goto P_0c03c25e;
case 0x0c03c260u: goto P_0c03c260;
case 0x0c03c262u: goto P_0c03c262;
case 0x0c03c264u: goto P_0c03c264;
case 0x0c03c266u: goto P_0c03c266;
case 0x0c03c268u: goto P_0c03c268;
case 0x0c03c26au: goto P_0c03c26a;
case 0x0c03c26cu: goto P_0c03c26c;
case 0x0c03c26eu: goto P_0c03c26e;
case 0x0c03c270u: goto P_0c03c270;
case 0x0c03c272u: goto P_0c03c272;
case 0x0c03c274u: goto P_0c03c274;
case 0x0c03c276u: goto P_0c03c276;
case 0x0c03c278u: goto P_0c03c278;
case 0x0c03c27au: goto P_0c03c27a;
case 0x0c03c27cu: goto P_0c03c27c;
case 0x0c03c27eu: goto P_0c03c27e;
case 0x0c03c280u: goto P_0c03c280;
case 0x0c03c282u: goto P_0c03c282;
case 0x0c03c284u: goto P_0c03c284;
case 0x0c03c286u: goto P_0c03c286;
case 0x0c03c288u: goto P_0c03c288;
case 0x0c03c28au: goto P_0c03c28a;
case 0x0c03c28cu: goto P_0c03c28c;
case 0x0c03c28eu: goto P_0c03c28e;
case 0x0c03c290u: goto P_0c03c290;
case 0x0c03c292u: goto P_0c03c292;
case 0x0c03c294u: goto P_0c03c294;
case 0x0c03c296u: goto P_0c03c296;
case 0x0c03c298u: goto P_0c03c298;
case 0x0c03c29au: goto P_0c03c29a;
case 0x0c03c29cu: goto P_0c03c29c;
case 0x0c03c29eu: goto P_0c03c29e;
case 0x0c03c2a0u: goto P_0c03c2a0;
case 0x0c03c2a2u: goto P_0c03c2a2;
case 0x0c03c2a4u: goto P_0c03c2a4;
case 0x0c03c2a6u: goto P_0c03c2a6;
case 0x0c03c2a8u: goto P_0c03c2a8;
case 0x0c03c2aau: goto P_0c03c2aa;
case 0x0c03c2acu: goto P_0c03c2ac;
case 0x0c03c2aeu: goto P_0c03c2ae;
case 0x0c03c2b0u: goto P_0c03c2b0;
case 0x0c03c2b2u: goto P_0c03c2b2;
case 0x0c03c2b4u: goto P_0c03c2b4;
case 0x0c03c2b6u: goto P_0c03c2b6;
case 0x0c03c2b8u: goto P_0c03c2b8;
case 0x0c03c2bau: goto P_0c03c2ba;
case 0x0c03c2bcu: goto P_0c03c2bc;
case 0x0c03c2beu: goto P_0c03c2be;
case 0x0c03c2c0u: goto P_0c03c2c0;
case 0x0c03c2c2u: goto P_0c03c2c2;
case 0x0c03c2c4u: goto P_0c03c2c4;
case 0x0c03c2c6u: goto P_0c03c2c6;
case 0x0c03c2c8u: goto P_0c03c2c8;
case 0x0c03c2cau: goto P_0c03c2ca;
case 0x0c03c2ccu: goto P_0c03c2cc;
case 0x0c03c2ceu: goto P_0c03c2ce;
case 0x0c03c2d0u: goto P_0c03c2d0;
case 0x0c03c2d2u: goto P_0c03c2d2;
case 0x0c03c2d4u: goto P_0c03c2d4;
case 0x0c03c2d6u: goto P_0c03c2d6;
case 0x0c03c2d8u: goto P_0c03c2d8;
case 0x0c03c2dau: goto P_0c03c2da;
case 0x0c03c2dcu: goto P_0c03c2dc;
case 0x0c03c2deu: goto P_0c03c2de;
case 0x0c03c2e0u: goto P_0c03c2e0;
case 0x0c03c2e2u: goto P_0c03c2e2;
case 0x0c03c2e4u: goto P_0c03c2e4;
case 0x0c03c2e6u: goto P_0c03c2e6;
case 0x0c03c2e8u: goto P_0c03c2e8;
case 0x0c03c2eau: goto P_0c03c2ea;
case 0x0c03c2ecu: goto P_0c03c2ec;
case 0x0c03c2eeu: goto P_0c03c2ee;
case 0x0c03c2f0u: goto P_0c03c2f0;
case 0x0c03c2f2u: goto P_0c03c2f2;
case 0x0c03c2f4u: goto P_0c03c2f4;
case 0x0c03c2f6u: goto P_0c03c2f6;
case 0x0c03c2f8u: goto P_0c03c2f8;
case 0x0c03c2fau: goto P_0c03c2fa;
case 0x0c03c2fcu: goto P_0c03c2fc;
case 0x0c03c2feu: goto P_0c03c2fe;
case 0x0c03c300u: goto P_0c03c300;
case 0x0c03c302u: goto P_0c03c302;
case 0x0c03c304u: goto P_0c03c304;
case 0x0c03c306u: goto P_0c03c306;
case 0x0c03c308u: goto P_0c03c308;
case 0x0c03c30au: goto P_0c03c30a;
case 0x0c03c324u: goto P_0c03c324;
case 0x0c03c326u: goto P_0c03c326;
case 0x0c03c328u: goto P_0c03c328;
case 0x0c03c32au: goto P_0c03c32a;
case 0x0c03c32cu: goto P_0c03c32c;
case 0x0c03c32eu: goto P_0c03c32e;
case 0x0c03c330u: goto P_0c03c330;
case 0x0c03c332u: goto P_0c03c332;
case 0x0c03c334u: goto P_0c03c334;
case 0x0c03c336u: goto P_0c03c336;
case 0x0c03c338u: goto P_0c03c338;
case 0x0c03c33au: goto P_0c03c33a;
case 0x0c03c33cu: goto P_0c03c33c;
case 0x0c03c33eu: goto P_0c03c33e;
case 0x0c03c340u: goto P_0c03c340;
case 0x0c03c342u: goto P_0c03c342;
case 0x0c03c344u: goto P_0c03c344;
case 0x0c03c346u: goto P_0c03c346;
case 0x0c03c348u: goto P_0c03c348;
case 0x0c03c34au: goto P_0c03c34a;
case 0x0c03c34cu: goto P_0c03c34c;
case 0x0c03c34eu: goto P_0c03c34e;
case 0x0c03c350u: goto P_0c03c350;
case 0x0c03c352u: goto P_0c03c352;
case 0x0c03c354u: goto P_0c03c354;
case 0x0c03c356u: goto P_0c03c356;
case 0x0c03c358u: goto P_0c03c358;
case 0x0c03c35au: goto P_0c03c35a;
case 0x0c03c35cu: goto P_0c03c35c;
case 0x0c03c35eu: goto P_0c03c35e;
case 0x0c03c360u: goto P_0c03c360;
case 0x0c03c362u: goto P_0c03c362;
case 0x0c03c364u: goto P_0c03c364;
case 0x0c03c366u: goto P_0c03c366;
case 0x0c03c368u: goto P_0c03c368;
case 0x0c03c36au: goto P_0c03c36a;
case 0x0c03c36cu: goto P_0c03c36c;
case 0x0c03c36eu: goto P_0c03c36e;
case 0x0c03c370u: goto P_0c03c370;
case 0x0c03c372u: goto P_0c03c372;
case 0x0c03c374u: goto P_0c03c374;
case 0x0c03c376u: goto P_0c03c376;
case 0x0c03c378u: goto P_0c03c378;
case 0x0c03c37au: goto P_0c03c37a;
case 0x0c03c37cu: goto P_0c03c37c;
case 0x0c03c37eu: goto P_0c03c37e;
case 0x0c03c380u: goto P_0c03c380;
case 0x0c03c382u: goto P_0c03c382;
case 0x0c03c384u: goto P_0c03c384;
case 0x0c03c386u: goto P_0c03c386;
case 0x0c03c388u: goto P_0c03c388;
case 0x0c03c38au: goto P_0c03c38a;
case 0x0c03c38cu: goto P_0c03c38c;
case 0x0c03c38eu: goto P_0c03c38e;
case 0x0c03c390u: goto P_0c03c390;
case 0x0c03c392u: goto P_0c03c392;
case 0x0c03c394u: goto P_0c03c394;
case 0x0c03c396u: goto P_0c03c396;
case 0x0c03c398u: goto P_0c03c398;
case 0x0c03c39au: goto P_0c03c39a;
case 0x0c03c39cu: goto P_0c03c39c;
case 0x0c03c39eu: goto P_0c03c39e;
case 0x0c03c3a0u: goto P_0c03c3a0;
case 0x0c03c3a2u: goto P_0c03c3a2;
case 0x0c03c3a4u: goto P_0c03c3a4;
case 0x0c03c3a6u: goto P_0c03c3a6;
case 0x0c03c3a8u: goto P_0c03c3a8;
case 0x0c03c3aau: goto P_0c03c3aa;
case 0x0c03c3acu: goto P_0c03c3ac;
case 0x0c03c3aeu: goto P_0c03c3ae;
case 0x0c03c3b0u: goto P_0c03c3b0;
case 0x0c03c3b2u: goto P_0c03c3b2;
case 0x0c03c3b4u: goto P_0c03c3b4;
case 0x0c03c3b6u: goto P_0c03c3b6;
case 0x0c03c3b8u: goto P_0c03c3b8;
case 0x0c03c3bau: goto P_0c03c3ba;
case 0x0c03c3bcu: goto P_0c03c3bc;
case 0x0c03c3beu: goto P_0c03c3be;
case 0x0c03c3c0u: goto P_0c03c3c0;
case 0x0c03c3c2u: goto P_0c03c3c2;
case 0x0c03c3c4u: goto P_0c03c3c4;
case 0x0c03c3c6u: goto P_0c03c3c6;
case 0x0c03c3c8u: goto P_0c03c3c8;
case 0x0c03c3cau: goto P_0c03c3ca;
case 0x0c03c3ccu: goto P_0c03c3cc;
case 0x0c03c3ceu: goto P_0c03c3ce;
case 0x0c03c3d0u: goto P_0c03c3d0;
case 0x0c03c3d2u: goto P_0c03c3d2;
case 0x0c03c3d4u: goto P_0c03c3d4;
case 0x0c03c3d6u: goto P_0c03c3d6;
case 0x0c03c3d8u: goto P_0c03c3d8;
case 0x0c03c3dau: goto P_0c03c3da;
case 0x0c03c3dcu: goto P_0c03c3dc;
case 0x0c03c3deu: goto P_0c03c3de;
case 0x0c03c3e0u: goto P_0c03c3e0;
case 0x0c03c3e2u: goto P_0c03c3e2;
case 0x0c03c3e4u: goto P_0c03c3e4;
case 0x0c03c3e6u: goto P_0c03c3e6;
case 0x0c03c3e8u: goto P_0c03c3e8;
case 0x0c03c3eau: goto P_0c03c3ea;
case 0x0c03c3ecu: goto P_0c03c3ec;
case 0x0c03c3eeu: goto P_0c03c3ee;
case 0x0c03c3f0u: goto P_0c03c3f0;
case 0x0c03c3f2u: goto P_0c03c3f2;
case 0x0c03c3f4u: goto P_0c03c3f4;
case 0x0c03c3f6u: goto P_0c03c3f6;
case 0x0c03c3f8u: goto P_0c03c3f8;
case 0x0c03c3fau: goto P_0c03c3fa;
case 0x0c03c3fcu: goto P_0c03c3fc;
case 0x0c03c3feu: goto P_0c03c3fe;
case 0x0c03c400u: goto P_0c03c400;
case 0x0c03c402u: goto P_0c03c402;
case 0x0c03c404u: goto P_0c03c404;
case 0x0c03c406u: goto P_0c03c406;
case 0x0c03c408u: goto P_0c03c408;
case 0x0c03c40au: goto P_0c03c40a;
case 0x0c03c40cu: goto P_0c03c40c;
case 0x0c03c40eu: goto P_0c03c40e;
case 0x0c03c410u: goto P_0c03c410;
case 0x0c03c412u: goto P_0c03c412;
case 0x0c03c414u: goto P_0c03c414;
case 0x0c03c416u: goto P_0c03c416;
case 0x0c03c418u: goto P_0c03c418;
case 0x0c03c41au: goto P_0c03c41a;
case 0x0c03c41cu: goto P_0c03c41c;
case 0x0c03c41eu: goto P_0c03c41e;
case 0x0c03c420u: goto P_0c03c420;
case 0x0c03c422u: goto P_0c03c422;
case 0x0c03c424u: goto P_0c03c424;
case 0x0c03c426u: goto P_0c03c426;
case 0x0c03c428u: goto P_0c03c428;
case 0x0c03c42au: goto P_0c03c42a;
case 0x0c03c42cu: goto P_0c03c42c;
case 0x0c03c42eu: goto P_0c03c42e;
case 0x0c03c430u: goto P_0c03c430;
case 0x0c03c432u: goto P_0c03c432;
case 0x0c03c434u: goto P_0c03c434;
case 0x0c03c6f0u: goto P_0c03c6f0;
case 0x0c03c6f2u: goto P_0c03c6f2;
case 0x0c03c6f4u: goto P_0c03c6f4;
case 0x0c03c6f6u: goto P_0c03c6f6;
case 0x0c03c6f8u: goto P_0c03c6f8;
case 0x0c03c6fau: goto P_0c03c6fa;
case 0x0c03c6fcu: goto P_0c03c6fc;
case 0x0c03c6feu: goto P_0c03c6fe;
case 0x0c03c700u: goto P_0c03c700;
case 0x0c03c702u: goto P_0c03c702;
case 0x0c03c704u: goto P_0c03c704;
case 0x0c03c706u: goto P_0c03c706;
case 0x0c03c708u: goto P_0c03c708;
case 0x0c03c70au: goto P_0c03c70a;
case 0x0c03c70cu: goto P_0c03c70c;
case 0x0c03c70eu: goto P_0c03c70e;
case 0x0c03c710u: goto P_0c03c710;
case 0x0c03c712u: goto P_0c03c712;
case 0x0c03c714u: goto P_0c03c714;
case 0x0c03c716u: goto P_0c03c716;
case 0x0c03cc70u: goto P_0c03cc70;
case 0x0c03cc72u: goto P_0c03cc72;
case 0x0c03cc74u: goto P_0c03cc74;
case 0x0c03cc76u: goto P_0c03cc76;
case 0x0c03cc78u: goto P_0c03cc78;
case 0x0c03cc7au: goto P_0c03cc7a;
case 0x0c03cc7cu: goto P_0c03cc7c;
case 0x0c03cc7eu: goto P_0c03cc7e;
case 0x0c03cc80u: goto P_0c03cc80;
case 0x0c03cc82u: goto P_0c03cc82;
case 0x0c03cc84u: goto P_0c03cc84;
case 0x0c03cc86u: goto P_0c03cc86;
case 0x0c03cc88u: goto P_0c03cc88;
case 0x0c03d0e8u: goto P_0c03d0e8;
case 0x0c03d0eau: goto P_0c03d0ea;
case 0x0c03d0ecu: goto P_0c03d0ec;
case 0x0c03d0eeu: goto P_0c03d0ee;
case 0x0c03d0f0u: goto P_0c03d0f0;
case 0x0c03d0f2u: goto P_0c03d0f2;
case 0x0c03d0f4u: goto P_0c03d0f4;
case 0x0c03d0f6u: goto P_0c03d0f6;
case 0x0c03d0f8u: goto P_0c03d0f8;
case 0x0c03d0fau: goto P_0c03d0fa;
case 0x0c03d0fcu: goto P_0c03d0fc;
case 0x0c03d0feu: goto P_0c03d0fe;
case 0x0c03d100u: goto P_0c03d100;
case 0x0c03d102u: goto P_0c03d102;
case 0x0c03d104u: goto P_0c03d104;
case 0x0c03d106u: goto P_0c03d106;
case 0x0c03d108u: goto P_0c03d108;
case 0x0c03d10au: goto P_0c03d10a;
case 0x0c03d10cu: goto P_0c03d10c;
case 0x0c03d10eu: goto P_0c03d10e;
case 0x0c03d110u: goto P_0c03d110;
case 0x0c03d112u: goto P_0c03d112;
case 0x0c03d114u: goto P_0c03d114;
case 0x0c03d116u: goto P_0c03d116;
case 0x0c03d118u: goto P_0c03d118;
case 0x0c03d11au: goto P_0c03d11a;
case 0x0c03d11cu: goto P_0c03d11c;
case 0x0c03d11eu: goto P_0c03d11e;
case 0x0c03d120u: goto P_0c03d120;
case 0x0c03d122u: goto P_0c03d122;
case 0x0c03d124u: goto P_0c03d124;
case 0x0c03d126u: goto P_0c03d126;
case 0x0c03d128u: goto P_0c03d128;
case 0x0c03d12au: goto P_0c03d12a;
case 0x0c03d12cu: goto P_0c03d12c;
case 0x0c03d12eu: goto P_0c03d12e;
case 0x0c03d130u: goto P_0c03d130;
case 0x0c03d132u: goto P_0c03d132;
case 0x0c03d134u: goto P_0c03d134;
case 0x0c03d136u: goto P_0c03d136;
case 0x0c03d138u: goto P_0c03d138;
case 0x0c03d13au: goto P_0c03d13a;
case 0x0c03d13cu: goto P_0c03d13c;
case 0x0c03d13eu: goto P_0c03d13e;
case 0x0c03d140u: goto P_0c03d140;
case 0x0c03d142u: goto P_0c03d142;
case 0x0c03d144u: goto P_0c03d144;
case 0x0c03d146u: goto P_0c03d146;
case 0x0c03d148u: goto P_0c03d148;
case 0x0c03d14au: goto P_0c03d14a;
case 0x0c03d14cu: goto P_0c03d14c;
case 0x0c03d14eu: goto P_0c03d14e;
case 0x0c03d150u: goto P_0c03d150;
case 0x0c03d152u: goto P_0c03d152;
case 0x0c03d154u: goto P_0c03d154;
case 0x0c03d156u: goto P_0c03d156;
case 0x0c03d158u: goto P_0c03d158;
case 0x0c03d15au: goto P_0c03d15a;
case 0x0c03d15cu: goto P_0c03d15c;
case 0x0c03d15eu: goto P_0c03d15e;
case 0x0c03d160u: goto P_0c03d160;
case 0x0c03d162u: goto P_0c03d162;
case 0x0c03d164u: goto P_0c03d164;
case 0x0c03d166u: goto P_0c03d166;
case 0x0c03d168u: goto P_0c03d168;
case 0x0c03d16au: goto P_0c03d16a;
case 0x0c03d16cu: goto P_0c03d16c;
case 0x0c03d16eu: goto P_0c03d16e;
case 0x0c03d170u: goto P_0c03d170;
case 0x0c03d172u: goto P_0c03d172;
case 0x0c03d174u: goto P_0c03d174;
case 0x0c03d176u: goto P_0c03d176;
case 0x0c03d178u: goto P_0c03d178;
case 0x0c03d17au: goto P_0c03d17a;
case 0x0c03d17cu: goto P_0c03d17c;
case 0x0c03d17eu: goto P_0c03d17e;
case 0x0c03d180u: goto P_0c03d180;
case 0x0c03d182u: goto P_0c03d182;
case 0x0c03d184u: goto P_0c03d184;
case 0x0c03d186u: goto P_0c03d186;
case 0x0c03d188u: goto P_0c03d188;
case 0x0c03d18au: goto P_0c03d18a;
case 0x0c03d18cu: goto P_0c03d18c;
case 0x0c03d18eu: goto P_0c03d18e;
case 0x0c03d190u: goto P_0c03d190;
case 0x0c03d192u: goto P_0c03d192;
case 0x0c03d194u: goto P_0c03d194;
case 0x0c03d196u: goto P_0c03d196;
case 0x0c03d198u: goto P_0c03d198;
case 0x0c03d19au: goto P_0c03d19a;
case 0x0c03d19cu: goto P_0c03d19c;
case 0x0c03d1a8u: goto P_0c03d1a8;
case 0x0c03d1aau: goto P_0c03d1aa;
case 0x0c03d1acu: goto P_0c03d1ac;
case 0x0c03d1aeu: goto P_0c03d1ae;
case 0x0c03d1b0u: goto P_0c03d1b0;
case 0x0c03d1b2u: goto P_0c03d1b2;
case 0x0c03d1b4u: goto P_0c03d1b4;
case 0x0c03d1b6u: goto P_0c03d1b6;
case 0x0c03d1b8u: goto P_0c03d1b8;
case 0x0c03d1bau: goto P_0c03d1ba;
case 0x0c03d1bcu: goto P_0c03d1bc;
case 0x0c03d1beu: goto P_0c03d1be;
case 0x0c03d1c0u: goto P_0c03d1c0;
case 0x0c03d1c2u: goto P_0c03d1c2;
case 0x0c03d1c4u: goto P_0c03d1c4;
case 0x0c03d1c6u: goto P_0c03d1c6;
case 0x0c03d1c8u: goto P_0c03d1c8;
case 0x0c03d1cau: goto P_0c03d1ca;
case 0x0c03d1ccu: goto P_0c03d1cc;
case 0x0c03d1ceu: goto P_0c03d1ce;
case 0x0c03d1d0u: goto P_0c03d1d0;
case 0x0c03d1d2u: goto P_0c03d1d2;
case 0x0c03d1d4u: goto P_0c03d1d4;
case 0x0c03d1d6u: goto P_0c03d1d6;
case 0x0c03d1d8u: goto P_0c03d1d8;
case 0x0c03d1dau: goto P_0c03d1da;
case 0x0c03d1dcu: goto P_0c03d1dc;
case 0x0c03d1deu: goto P_0c03d1de;
case 0x0c03d1e0u: goto P_0c03d1e0;
case 0x0c03d1e2u: goto P_0c03d1e2;
case 0x0c03d1e4u: goto P_0c03d1e4;
case 0x0c03d1e6u: goto P_0c03d1e6;
case 0x0c03d1e8u: goto P_0c03d1e8;
case 0x0c03d1eau: goto P_0c03d1ea;
case 0x0c03d1ecu: goto P_0c03d1ec;
case 0x0c03d1eeu: goto P_0c03d1ee;
case 0x0c03d1f0u: goto P_0c03d1f0;
case 0x0c03d1f2u: goto P_0c03d1f2;
case 0x0c03d1f4u: goto P_0c03d1f4;
case 0x0c03d1f6u: goto P_0c03d1f6;
case 0x0c03d1f8u: goto P_0c03d1f8;
case 0x0c03d1fau: goto P_0c03d1fa;
case 0x0c03d1fcu: goto P_0c03d1fc;
case 0x0c03d1feu: goto P_0c03d1fe;
case 0x0c03d200u: goto P_0c03d200;
case 0x0c03d202u: goto P_0c03d202;
case 0x0c03d204u: goto P_0c03d204;
case 0x0c03d206u: goto P_0c03d206;
case 0x0c03d208u: goto P_0c03d208;
case 0x0c03d20au: goto P_0c03d20a;
case 0x0c03d20cu: goto P_0c03d20c;
case 0x0c03d20eu: goto P_0c03d20e;
case 0x0c03d210u: goto P_0c03d210;
case 0x0c03d212u: goto P_0c03d212;
case 0x0c03d214u: goto P_0c03d214;
case 0x0c03d216u: goto P_0c03d216;
case 0x0c03d218u: goto P_0c03d218;
case 0x0c03d21au: goto P_0c03d21a;
case 0x0c03d21cu: goto P_0c03d21c;
case 0x0c03d21eu: goto P_0c03d21e;
case 0x0c03d220u: goto P_0c03d220;
case 0x0c03d222u: goto P_0c03d222;
case 0x0c03d224u: goto P_0c03d224;
case 0x0c03d226u: goto P_0c03d226;
case 0x0c03d228u: goto P_0c03d228;
case 0x0c03d22au: goto P_0c03d22a;
case 0x0c03d22cu: goto P_0c03d22c;
case 0x0c03d22eu: goto P_0c03d22e;
case 0x0c03d230u: goto P_0c03d230;
case 0x0c03d232u: goto P_0c03d232;
case 0x0c03d234u: goto P_0c03d234;
case 0x0c03d236u: goto P_0c03d236;
case 0x0c03d238u: goto P_0c03d238;
case 0x0c03d23au: goto P_0c03d23a;
case 0x0c03d23cu: goto P_0c03d23c;
case 0x0c03d23eu: goto P_0c03d23e;
case 0x0c03d240u: goto P_0c03d240;
case 0x0c03d242u: goto P_0c03d242;
case 0x0c03d244u: goto P_0c03d244;
case 0x0c03d246u: goto P_0c03d246;
case 0x0c03d248u: goto P_0c03d248;
case 0x0c03d24au: goto P_0c03d24a;
case 0x0c03d24cu: goto P_0c03d24c;
case 0x0c03d24eu: goto P_0c03d24e;
case 0x0c03d250u: goto P_0c03d250;
case 0x0c03d252u: goto P_0c03d252;
case 0x0c03d254u: goto P_0c03d254;
case 0x0c03d256u: goto P_0c03d256;
case 0x0c03d258u: goto P_0c03d258;
case 0x0c0645fau: goto P_0c0645fa;
case 0x0c0645fcu: goto P_0c0645fc;
case 0x0c0645feu: goto P_0c0645fe;
case 0x0c064600u: goto P_0c064600;
case 0x0c064602u: goto P_0c064602;
case 0x0c064604u: goto P_0c064604;
case 0x0c064606u: goto P_0c064606;
case 0x0c064608u: goto P_0c064608;
case 0x0c06460au: goto P_0c06460a;
case 0x0c06460cu: goto P_0c06460c;
case 0x0c06460eu: goto P_0c06460e;
case 0x0c064610u: goto P_0c064610;
case 0x0c064612u: goto P_0c064612;
case 0x0c064614u: goto P_0c064614;
case 0x0c064616u: goto P_0c064616;
case 0x0c064618u: goto P_0c064618;
case 0x0c06461au: goto P_0c06461a;
case 0x0c06461cu: goto P_0c06461c;
case 0x0c06461eu: goto P_0c06461e;
case 0x0c064620u: goto P_0c064620;
case 0x0c064622u: goto P_0c064622;
case 0x0c064624u: goto P_0c064624;
case 0x0c064626u: goto P_0c064626;
case 0x0c064628u: goto P_0c064628;
case 0x0c06462au: goto P_0c06462a;
case 0x0c06462cu: goto P_0c06462c;
case 0x0c06462eu: goto P_0c06462e;
case 0x0c064630u: goto P_0c064630;
case 0x0c064632u: goto P_0c064632;
case 0x0c064634u: goto P_0c064634;
case 0x0c064636u: goto P_0c064636;
case 0x0c064638u: goto P_0c064638;
case 0x0c06463au: goto P_0c06463a;
case 0x0c06463cu: goto P_0c06463c;
case 0x0c06463eu: goto P_0c06463e;
case 0x0c064640u: goto P_0c064640;
case 0x0c064642u: goto P_0c064642;
case 0x0c064644u: goto P_0c064644;
case 0x0c064646u: goto P_0c064646;
case 0x0c064648u: goto P_0c064648;
case 0x0c06464au: goto P_0c06464a;
case 0x0c06464cu: goto P_0c06464c;
case 0x0c06464eu: goto P_0c06464e;
case 0x0c064650u: goto P_0c064650;
case 0x0c064652u: goto P_0c064652;
case 0x0c064654u: goto P_0c064654;
case 0x0c064656u: goto P_0c064656;
case 0x0c064658u: goto P_0c064658;
case 0x0c06465au: goto P_0c06465a;
case 0x0c06465cu: goto P_0c06465c;
case 0x0c06465eu: goto P_0c06465e;
case 0x0c064660u: goto P_0c064660;
case 0x0c064662u: goto P_0c064662;
case 0x0c064664u: goto P_0c064664;
case 0x0c064666u: goto P_0c064666;
case 0x0c064668u: goto P_0c064668;
case 0x0c06466au: goto P_0c06466a;
case 0x0c06466cu: goto P_0c06466c;
case 0x0c06466eu: goto P_0c06466e;
case 0x0c064670u: goto P_0c064670;
case 0x0c064672u: goto P_0c064672;
case 0x0c064674u: goto P_0c064674;
case 0x0c064676u: goto P_0c064676;
case 0x0c064678u: goto P_0c064678;
case 0x0c06467au: goto P_0c06467a;
case 0x0c06467cu: goto P_0c06467c;
case 0x0c06467eu: goto P_0c06467e;
case 0x0c064680u: goto P_0c064680;
case 0x0c064682u: goto P_0c064682;
case 0x0c064684u: goto P_0c064684;
case 0x0c064686u: goto P_0c064686;
case 0x0c064688u: goto P_0c064688;
case 0x0c06468au: goto P_0c06468a;
case 0x0c06468cu: goto P_0c06468c;
case 0x0c06468eu: goto P_0c06468e;
case 0x0c064690u: goto P_0c064690;
case 0x0c064692u: goto P_0c064692;
case 0x0c064694u: goto P_0c064694;
case 0x0c064696u: goto P_0c064696;
case 0x0c064698u: goto P_0c064698;
case 0x0c06469au: goto P_0c06469a;
case 0x0c06469cu: goto P_0c06469c;
case 0x0c06469eu: goto P_0c06469e;
case 0x0c0646a0u: goto P_0c0646a0;
case 0x0c0646a2u: goto P_0c0646a2;
case 0x0c0646a4u: goto P_0c0646a4;
case 0x0c0646a6u: goto P_0c0646a6;
case 0x0c0646a8u: goto P_0c0646a8;
case 0x0c0646aau: goto P_0c0646aa;
case 0x0c0646acu: goto P_0c0646ac;
case 0x0c0646aeu: goto P_0c0646ae;
case 0x0c0646b0u: goto P_0c0646b0;
case 0x0c0646b2u: goto P_0c0646b2;
case 0x0c0646b4u: goto P_0c0646b4;
case 0x0c0646b6u: goto P_0c0646b6;
case 0x0c0646b8u: goto P_0c0646b8;
case 0x0c0646bau: goto P_0c0646ba;
case 0x0c0646bcu: goto P_0c0646bc;
case 0x0c0646beu: goto P_0c0646be;
case 0x0c0646c0u: goto P_0c0646c0;
case 0x0c0646c2u: goto P_0c0646c2;
case 0x0c0646c4u: goto P_0c0646c4;
case 0x0c0646c6u: goto P_0c0646c6;
case 0x0c0646c8u: goto P_0c0646c8;
case 0x0c0646cau: goto P_0c0646ca;
case 0x0c0646ccu: goto P_0c0646cc;
case 0x0c0646ceu: goto P_0c0646ce;
case 0x0c0646d0u: goto P_0c0646d0;
case 0x0c0646d2u: goto P_0c0646d2;
case 0x0c0646d4u: goto P_0c0646d4;
case 0x0c0646d6u: goto P_0c0646d6;
case 0x0c0646d8u: goto P_0c0646d8;
case 0x0c0646dau: goto P_0c0646da;
case 0x0c0646dcu: goto P_0c0646dc;
case 0x0c0646deu: goto P_0c0646de;
case 0x0c0646e0u: goto P_0c0646e0;
case 0x0c0646e2u: goto P_0c0646e2;
case 0x0c0646e4u: goto P_0c0646e4;
case 0x0c0646e6u: goto P_0c0646e6;
case 0x0c0646e8u: goto P_0c0646e8;
case 0x0c0646eau: goto P_0c0646ea;
case 0x0c0646ecu: goto P_0c0646ec;
case 0x0c0646eeu: goto P_0c0646ee;
case 0x0c0646f0u: goto P_0c0646f0;
case 0x0c0646f2u: goto P_0c0646f2;
case 0x0c0646f4u: goto P_0c0646f4;
case 0x0c0646f6u: goto P_0c0646f6;
case 0x0c064930u: goto P_0c064930;
case 0x0c064932u: goto P_0c064932;
case 0x0c064934u: goto P_0c064934;
case 0x0c064936u: goto P_0c064936;
case 0x0c064938u: goto P_0c064938;
case 0x0c06493au: goto P_0c06493a;
case 0x0c06493cu: goto P_0c06493c;
case 0x0c06493eu: goto P_0c06493e;
case 0x0c064940u: goto P_0c064940;
case 0x0c064942u: goto P_0c064942;
case 0x0c064944u: goto P_0c064944;
case 0x0c064946u: goto P_0c064946;
case 0x0c064948u: goto P_0c064948;
case 0x0c06494au: goto P_0c06494a;
case 0x0c06494cu: goto P_0c06494c;
case 0x0c06494eu: goto P_0c06494e;
case 0x0c064950u: goto P_0c064950;
case 0x0c064952u: goto P_0c064952;
case 0x0c064954u: goto P_0c064954;
case 0x0c064956u: goto P_0c064956;
case 0x0c064958u: goto P_0c064958;
case 0x0c06495au: goto P_0c06495a;
case 0x0c06495cu: goto P_0c06495c;
case 0x0c06495eu: goto P_0c06495e;
case 0x0c064960u: goto P_0c064960;
case 0x0c064962u: goto P_0c064962;
case 0x0c064964u: goto P_0c064964;
case 0x0c064966u: goto P_0c064966;
case 0x0c064968u: goto P_0c064968;
case 0x0c06496au: goto P_0c06496a;
case 0x0c06496cu: goto P_0c06496c;
case 0x0c06496eu: goto P_0c06496e;
case 0x0c064970u: goto P_0c064970;
case 0x0c064972u: goto P_0c064972;
case 0x0c064974u: goto P_0c064974;
case 0x0c064976u: goto P_0c064976;
case 0x0c064978u: goto P_0c064978;
case 0x0c06497au: goto P_0c06497a;
case 0x0c06497cu: goto P_0c06497c;
case 0x0c06497eu: goto P_0c06497e;
case 0x0c064980u: goto P_0c064980;
case 0x0c064982u: goto P_0c064982;
case 0x0c064984u: goto P_0c064984;
case 0x0c064986u: goto P_0c064986;
case 0x0c064988u: goto P_0c064988;
case 0x0c06498au: goto P_0c06498a;
case 0x0c06498cu: goto P_0c06498c;
case 0x0c06498eu: goto P_0c06498e;
case 0x0c064990u: goto P_0c064990;
case 0x0c064992u: goto P_0c064992;
case 0x0c064994u: goto P_0c064994;
case 0x0c064996u: goto P_0c064996;
case 0x0c064998u: goto P_0c064998;
case 0x0c06499au: goto P_0c06499a;
case 0x0c06499cu: goto P_0c06499c;
case 0x0c06499eu: goto P_0c06499e;
case 0x0c0649a0u: goto P_0c0649a0;
case 0x0c0649a2u: goto P_0c0649a2;
case 0x0c0649a4u: goto P_0c0649a4;
case 0x0c0649a6u: goto P_0c0649a6;
case 0x0c0649a8u: goto P_0c0649a8;
case 0x0c0649aau: goto P_0c0649aa;
case 0x0c0649acu: goto P_0c0649ac;
case 0x0c0649aeu: goto P_0c0649ae;
case 0x0c0649b0u: goto P_0c0649b0;
case 0x0c0649b2u: goto P_0c0649b2;
case 0x0c0649b4u: goto P_0c0649b4;
case 0x0c0649b6u: goto P_0c0649b6;
case 0x0c0649b8u: goto P_0c0649b8;
case 0x0c0649bau: goto P_0c0649ba;
case 0x0c0649bcu: goto P_0c0649bc;
case 0x0c0649beu: goto P_0c0649be;
case 0x0c0649c0u: goto P_0c0649c0;
case 0x0c0649c2u: goto P_0c0649c2;
case 0x0c0649c4u: goto P_0c0649c4;
case 0x0c0649c6u: goto P_0c0649c6;
case 0x0c0649c8u: goto P_0c0649c8;
case 0x0c0649cau: goto P_0c0649ca;
case 0x0c0649ccu: goto P_0c0649cc;
case 0x0c0649ceu: goto P_0c0649ce;
case 0x0c0649d0u: goto P_0c0649d0;
case 0x0c0649d2u: goto P_0c0649d2;
case 0x0c0649d4u: goto P_0c0649d4;
case 0x0c0649d6u: goto P_0c0649d6;
case 0x0c0649d8u: goto P_0c0649d8;
case 0x0c0649dau: goto P_0c0649da;
case 0x0c0649dcu: goto P_0c0649dc;
case 0x0c0649deu: goto P_0c0649de;
case 0x0c0649e0u: goto P_0c0649e0;
case 0x0c0649e2u: goto P_0c0649e2;
case 0x0c0649e4u: goto P_0c0649e4;
case 0x0c0649e6u: goto P_0c0649e6;
case 0x0c0649e8u: goto P_0c0649e8;
case 0x0c0649eau: goto P_0c0649ea;
case 0x0c0649ecu: goto P_0c0649ec;
case 0x0c0649eeu: goto P_0c0649ee;
case 0x0c0649f0u: goto P_0c0649f0;
case 0x0c0649f2u: goto P_0c0649f2;
case 0x0c0649f4u: goto P_0c0649f4;
case 0x0c0649f6u: goto P_0c0649f6;
case 0x0c0649f8u: goto P_0c0649f8;
case 0x0c0649fau: goto P_0c0649fa;
case 0x0c0649fcu: goto P_0c0649fc;
case 0x0c0649feu: goto P_0c0649fe;
case 0x0c064a00u: goto P_0c064a00;
case 0x0c064a02u: goto P_0c064a02;
case 0x0c064a04u: goto P_0c064a04;
case 0x0c064a06u: goto P_0c064a06;
case 0x0c064a08u: goto P_0c064a08;
case 0x0c064a0au: goto P_0c064a0a;
case 0x0c064a0cu: goto P_0c064a0c;
case 0x0c064a0eu: goto P_0c064a0e;
case 0x0c064a10u: goto P_0c064a10;
case 0x0c064a12u: goto P_0c064a12;
case 0x0c064a14u: goto P_0c064a14;
case 0x0c064a16u: goto P_0c064a16;
case 0x0c064a18u: goto P_0c064a18;
case 0x0c064a1au: goto P_0c064a1a;
case 0x0c064a1cu: goto P_0c064a1c;
case 0x0c064a1eu: goto P_0c064a1e;
case 0x0c064a20u: goto P_0c064a20;
case 0x0c064a22u: goto P_0c064a22;
case 0x0c064a24u: goto P_0c064a24;
case 0x0c064a26u: goto P_0c064a26;
case 0x0c064a28u: goto P_0c064a28;
case 0x0c064a2au: goto P_0c064a2a;
case 0x0c064a2cu: goto P_0c064a2c;
case 0x0c064a2eu: goto P_0c064a2e;
case 0x0c064a30u: goto P_0c064a30;
case 0x0c064a32u: goto P_0c064a32;
case 0x0c064a34u: goto P_0c064a34;
case 0x0c064a36u: goto P_0c064a36;
case 0x0c064a38u: goto P_0c064a38;
case 0x0c064a3au: goto P_0c064a3a;
case 0x0c064a3cu: goto P_0c064a3c;
case 0x0c064a3eu: goto P_0c064a3e;
case 0x0c064a40u: goto P_0c064a40;
case 0x0c064a42u: goto P_0c064a42;
case 0x0c064a44u: goto P_0c064a44;
case 0x0c064a46u: goto P_0c064a46;
case 0x0c064a48u: goto P_0c064a48;
case 0x0c064a4au: goto P_0c064a4a;
case 0x0c064a4cu: goto P_0c064a4c;
case 0x0c064a4eu: goto P_0c064a4e;
case 0x0c064a50u: goto P_0c064a50;
case 0x0c064a52u: goto P_0c064a52;
case 0x0c064a54u: goto P_0c064a54;
case 0x0c064a56u: goto P_0c064a56;
case 0x0c064a58u: goto P_0c064a58;
case 0x0c064a5au: goto P_0c064a5a;
case 0x0c064a5cu: goto P_0c064a5c;
case 0x0c064a5eu: goto P_0c064a5e;
case 0x0c064a60u: goto P_0c064a60;
case 0x0c064a62u: goto P_0c064a62;
case 0x0c064a64u: goto P_0c064a64;
case 0x0c064a66u: goto P_0c064a66;
case 0x0c064a68u: goto P_0c064a68;
case 0x0c064a6au: goto P_0c064a6a;
case 0x0c064a6cu: goto P_0c064a6c;
case 0x0c064a6eu: goto P_0c064a6e;
case 0x0c064a70u: goto P_0c064a70;
case 0x0c064a72u: goto P_0c064a72;
case 0x0c064a74u: goto P_0c064a74;
case 0x0c064a76u: goto P_0c064a76;
case 0x0c064a78u: goto P_0c064a78;
case 0x0c064a7au: goto P_0c064a7a;
case 0x0c064a7cu: goto P_0c064a7c;
case 0x0c064a7eu: goto P_0c064a7e;
case 0x0c064a80u: goto P_0c064a80;
case 0x0c064a82u: goto P_0c064a82;
case 0x0c064a84u: goto P_0c064a84;
case 0x0c064a86u: goto P_0c064a86;
case 0x0c064a88u: goto P_0c064a88;
case 0x0c064a8au: goto P_0c064a8a;
case 0x0c064a8cu: goto P_0c064a8c;
case 0x0c0657fcu: goto P_0c0657fc;
case 0x0c0657feu: goto P_0c0657fe;
case 0x0c065800u: goto P_0c065800;
case 0x0c065802u: goto P_0c065802;
case 0x0c065804u: goto P_0c065804;
case 0x0c065806u: goto P_0c065806;
case 0x0c065808u: goto P_0c065808;
case 0x0c06580au: goto P_0c06580a;
case 0x0c06580cu: goto P_0c06580c;
case 0x0c06580eu: goto P_0c06580e;
case 0x0c065810u: goto P_0c065810;
case 0x0c065812u: goto P_0c065812;
case 0x0c065814u: goto P_0c065814;
case 0x0c065816u: goto P_0c065816;
case 0x0c065818u: goto P_0c065818;
case 0x0c06581au: goto P_0c06581a;
case 0x0c06581cu: goto P_0c06581c;
case 0x0c06581eu: goto P_0c06581e;
case 0x0c065820u: goto P_0c065820;
case 0x0c065822u: goto P_0c065822;
case 0x0c065824u: goto P_0c065824;
case 0x0c065826u: goto P_0c065826;
case 0x0c065828u: goto P_0c065828;
case 0x0c06582au: goto P_0c06582a;
case 0x0c06582cu: goto P_0c06582c;
case 0x0c06582eu: goto P_0c06582e;
case 0x0c065830u: goto P_0c065830;
case 0x0c065832u: goto P_0c065832;
case 0x0c065834u: goto P_0c065834;
case 0x0c065836u: goto P_0c065836;
case 0x0c065838u: goto P_0c065838;
case 0x0c06583au: goto P_0c06583a;
case 0x0c06583cu: goto P_0c06583c;
case 0x0c06583eu: goto P_0c06583e;
case 0x0c065840u: goto P_0c065840;
case 0x0c065842u: goto P_0c065842;
case 0x0c065844u: goto P_0c065844;
case 0x0c065846u: goto P_0c065846;
case 0x0c065848u: goto P_0c065848;
case 0x0c06584au: goto P_0c06584a;
case 0x0c06584cu: goto P_0c06584c;
case 0x0c06584eu: goto P_0c06584e;
case 0x0c065850u: goto P_0c065850;
case 0x0c065852u: goto P_0c065852;
case 0x0c065854u: goto P_0c065854;
case 0x0c065856u: goto P_0c065856;
case 0x0c065858u: goto P_0c065858;
case 0x0c06585au: goto P_0c06585a;
case 0x0c06585cu: goto P_0c06585c;
case 0x0c06585eu: goto P_0c06585e;
case 0x0c065860u: goto P_0c065860;
case 0x0c065862u: goto P_0c065862;
case 0x0c065864u: goto P_0c065864;
case 0x0c065866u: goto P_0c065866;
case 0x0c065868u: goto P_0c065868;
case 0x0c06586au: goto P_0c06586a;
case 0x0c06586cu: goto P_0c06586c;
case 0x0c06586eu: goto P_0c06586e;
case 0x0c065870u: goto P_0c065870;
case 0x0c065872u: goto P_0c065872;
case 0x0c065874u: goto P_0c065874;
case 0x0c065876u: goto P_0c065876;
case 0x0c065878u: goto P_0c065878;
case 0x0c06587au: goto P_0c06587a;
case 0x0c06587cu: goto P_0c06587c;
case 0x0c06587eu: goto P_0c06587e;
case 0x0c065880u: goto P_0c065880;
case 0x0c065882u: goto P_0c065882;
case 0x0c065884u: goto P_0c065884;
case 0x0c065886u: goto P_0c065886;
case 0x0c065888u: goto P_0c065888;
case 0x0c06588au: goto P_0c06588a;
case 0x0c06588cu: goto P_0c06588c;
case 0x0c06588eu: goto P_0c06588e;
case 0x0c065890u: goto P_0c065890;
case 0x0c065892u: goto P_0c065892;
case 0x0c065894u: goto P_0c065894;
case 0x0c065896u: goto P_0c065896;
case 0x0c065898u: goto P_0c065898;
case 0x0c06589au: goto P_0c06589a;
case 0x0c06589cu: goto P_0c06589c;
case 0x0c06589eu: goto P_0c06589e;
case 0x0c0658a0u: goto P_0c0658a0;
case 0x0c0658a2u: goto P_0c0658a2;
case 0x0c0658a4u: goto P_0c0658a4;
case 0x0c0658a6u: goto P_0c0658a6;
case 0x0c0658a8u: goto P_0c0658a8;
case 0x0c0658aau: goto P_0c0658aa;
case 0x0c0658acu: goto P_0c0658ac;
case 0x0c0658aeu: goto P_0c0658ae;
case 0x0c0658b0u: goto P_0c0658b0;
case 0x0c0658b2u: goto P_0c0658b2;
case 0x0c0658b4u: goto P_0c0658b4;
case 0x0c0658b6u: goto P_0c0658b6;
case 0x0c0658b8u: goto P_0c0658b8;
case 0x0c0658bau: goto P_0c0658ba;
case 0x0c0658bcu: goto P_0c0658bc;
case 0x0c0658beu: goto P_0c0658be;
case 0x0c0658c0u: goto P_0c0658c0;
case 0x0c0658c2u: goto P_0c0658c2;
case 0x0c0658c4u: goto P_0c0658c4;
case 0x0c0658c6u: goto P_0c0658c6;
case 0x0c0658c8u: goto P_0c0658c8;
case 0x0c0658cau: goto P_0c0658ca;
case 0x0c0658ccu: goto P_0c0658cc;
case 0x0c0658ceu: goto P_0c0658ce;
case 0x0c0658d0u: goto P_0c0658d0;
case 0x0c0658d2u: goto P_0c0658d2;
case 0x0c0658d4u: goto P_0c0658d4;
case 0x0c0658d6u: goto P_0c0658d6;
case 0x0c0658d8u: goto P_0c0658d8;
case 0x0c0658dau: goto P_0c0658da;
case 0x0c0658dcu: goto P_0c0658dc;
case 0x0c0658deu: goto P_0c0658de;
case 0x0c0658e0u: goto P_0c0658e0;
case 0x0c0658e2u: goto P_0c0658e2;
case 0x0c0658e4u: goto P_0c0658e4;
case 0x0c0658e6u: goto P_0c0658e6;
case 0x0c0658e8u: goto P_0c0658e8;
case 0x0c0658eau: goto P_0c0658ea;
case 0x0c0658ecu: goto P_0c0658ec;
case 0x0c0658eeu: goto P_0c0658ee;
case 0x0c0658f0u: goto P_0c0658f0;
case 0x0c0658f2u: goto P_0c0658f2;
case 0x0c0658f4u: goto P_0c0658f4;
case 0x0c0658f6u: goto P_0c0658f6;
case 0x0c0658f8u: goto P_0c0658f8;
case 0x0c0658fau: goto P_0c0658fa;
case 0x0c0658fcu: goto P_0c0658fc;
case 0x0c065932u: goto P_0c065932;
case 0x0c065934u: goto P_0c065934;
case 0x0c065936u: goto P_0c065936;
case 0x0c065938u: goto P_0c065938;
case 0x0c06593au: goto P_0c06593a;
case 0x0c06593cu: goto P_0c06593c;
case 0x0c06593eu: goto P_0c06593e;
case 0x0c065940u: goto P_0c065940;
case 0x0c065942u: goto P_0c065942;
case 0x0c065944u: goto P_0c065944;
case 0x0c065946u: goto P_0c065946;
case 0x0c065948u: goto P_0c065948;
case 0x0c06594au: goto P_0c06594a;
case 0x0c06594cu: goto P_0c06594c;
case 0x0c06594eu: goto P_0c06594e;
case 0x0c065950u: goto P_0c065950;
case 0x0c065952u: goto P_0c065952;
case 0x0c065954u: goto P_0c065954;
case 0x0c065956u: goto P_0c065956;
case 0x0c065958u: goto P_0c065958;
case 0x0c06595au: goto P_0c06595a;
case 0x0c06595cu: goto P_0c06595c;
case 0x0c06595eu: goto P_0c06595e;
case 0x0c065960u: goto P_0c065960;
case 0x0c065962u: goto P_0c065962;
case 0x0c065964u: goto P_0c065964;
case 0x0c065966u: goto P_0c065966;
case 0x0c065968u: goto P_0c065968;
case 0x0c06596au: goto P_0c06596a;
case 0x0c06596cu: goto P_0c06596c;
case 0x0c06596eu: goto P_0c06596e;
case 0x0c065970u: goto P_0c065970;
case 0x0c065972u: goto P_0c065972;
case 0x0c065974u: goto P_0c065974;
case 0x0c065976u: goto P_0c065976;
case 0x0c065978u: goto P_0c065978;
case 0x0c06597au: goto P_0c06597a;
case 0x0c06597cu: goto P_0c06597c;
case 0x0c06597eu: goto P_0c06597e;
case 0x0c065980u: goto P_0c065980;
case 0x0c065982u: goto P_0c065982;
case 0x0c065984u: goto P_0c065984;
case 0x0c065986u: goto P_0c065986;
case 0x0c065988u: goto P_0c065988;
case 0x0c06598au: goto P_0c06598a;
case 0x0c06598cu: goto P_0c06598c;
case 0x0c06598eu: goto P_0c06598e;
case 0x0c065990u: goto P_0c065990;
case 0x0c065992u: goto P_0c065992;
case 0x0c065994u: goto P_0c065994;
case 0x0c065996u: goto P_0c065996;
case 0x0c065998u: goto P_0c065998;
case 0x0c06599au: goto P_0c06599a;
case 0x0c06599cu: goto P_0c06599c;
case 0x0c06599eu: goto P_0c06599e;
case 0x0c0659a0u: goto P_0c0659a0;
case 0x0c0659a2u: goto P_0c0659a2;
case 0x0c0659a4u: goto P_0c0659a4;
case 0x0c0659a6u: goto P_0c0659a6;
case 0x0c0659a8u: goto P_0c0659a8;
case 0x0c0659aau: goto P_0c0659aa;
case 0x0c0659acu: goto P_0c0659ac;
case 0x0c0659aeu: goto P_0c0659ae;
case 0x0c0659b0u: goto P_0c0659b0;
case 0x0c0659b2u: goto P_0c0659b2;
case 0x0c0659b4u: goto P_0c0659b4;
case 0x0c0659b6u: goto P_0c0659b6;
case 0x0c0659b8u: goto P_0c0659b8;
case 0x0c0659bau: goto P_0c0659ba;
case 0x0c0659bcu: goto P_0c0659bc;
case 0x0c0659beu: goto P_0c0659be;
case 0x0c0659c0u: goto P_0c0659c0;
case 0x0c0659c2u: goto P_0c0659c2;
case 0x0c0659c4u: goto P_0c0659c4;
case 0x0c0659c6u: goto P_0c0659c6;
case 0x0c0659c8u: goto P_0c0659c8;
case 0x0c0659cau: goto P_0c0659ca;
case 0x0c0659ccu: goto P_0c0659cc;
case 0x0c0659ceu: goto P_0c0659ce;
case 0x0c0659d0u: goto P_0c0659d0;
case 0x0c0659d2u: goto P_0c0659d2;
case 0x0c0659d4u: goto P_0c0659d4;
case 0x0c0659d6u: goto P_0c0659d6;
case 0x0c0659d8u: goto P_0c0659d8;
case 0x0c0659dau: goto P_0c0659da;
case 0x0c0659dcu: goto P_0c0659dc;
case 0x0c0659deu: goto P_0c0659de;
case 0x0c0659e0u: goto P_0c0659e0;
case 0x0c0659e2u: goto P_0c0659e2;
case 0x0c0659e4u: goto P_0c0659e4;
case 0x0c0659e6u: goto P_0c0659e6;
case 0x0c0659e8u: goto P_0c0659e8;
case 0x0c0659eau: goto P_0c0659ea;
case 0x0c0659ecu: goto P_0c0659ec;
case 0x0c0659eeu: goto P_0c0659ee;
case 0x0c0659f0u: goto P_0c0659f0;
case 0x0c0659f2u: goto P_0c0659f2;
case 0x0c0659f4u: goto P_0c0659f4;
case 0x0c0659f6u: goto P_0c0659f6;
case 0x0c0659f8u: goto P_0c0659f8;
case 0x0c0659fau: goto P_0c0659fa;
case 0x0c0659fcu: goto P_0c0659fc;
case 0x0c0659feu: goto P_0c0659fe;
case 0x0c065a00u: goto P_0c065a00;
case 0x0c065a02u: goto P_0c065a02;
case 0x0c065a04u: goto P_0c065a04;
case 0x0c065a06u: goto P_0c065a06;
case 0x0c065a08u: goto P_0c065a08;
case 0x0c065a0au: goto P_0c065a0a;
case 0x0c065a0cu: goto P_0c065a0c;
case 0x0c065a0eu: goto P_0c065a0e;
case 0x0c065a10u: goto P_0c065a10;
case 0x0c065a12u: goto P_0c065a12;
case 0x0c065a14u: goto P_0c065a14;
case 0x0c065a16u: goto P_0c065a16;
case 0x0c065a18u: goto P_0c065a18;
case 0x0c065a1au: goto P_0c065a1a;
case 0x0c065a1cu: goto P_0c065a1c;
case 0x0c065a1eu: goto P_0c065a1e;
case 0x0c065a20u: goto P_0c065a20;
case 0x0c065a22u: goto P_0c065a22;
case 0x0c065a24u: goto P_0c065a24;
case 0x0c065a26u: goto P_0c065a26;
case 0x0c065a28u: goto P_0c065a28;
case 0x0c065a2au: goto P_0c065a2a;
case 0x0c065a2cu: goto P_0c065a2c;
case 0x0c065a2eu: goto P_0c065a2e;
case 0x0c065a30u: goto P_0c065a30;
case 0x0c065a32u: goto P_0c065a32;
case 0x0c065a34u: goto P_0c065a34;
case 0x0c065a36u: goto P_0c065a36;
case 0x0c065a38u: goto P_0c065a38;
case 0x0c065a3au: goto P_0c065a3a;
case 0x0c065a3cu: goto P_0c065a3c;
case 0x0c065a3eu: goto P_0c065a3e;
case 0x0c065a40u: goto P_0c065a40;
case 0x0c065a42u: goto P_0c065a42;
case 0x0c065a44u: goto P_0c065a44;
case 0x0c065a46u: goto P_0c065a46;
case 0x0c065a48u: goto P_0c065a48;
case 0x0c065a4au: goto P_0c065a4a;
case 0x0c065a4cu: goto P_0c065a4c;
case 0x0c065a4eu: goto P_0c065a4e;
case 0x0c065a50u: goto P_0c065a50;
case 0x0c065a52u: goto P_0c065a52;
case 0x0c065a54u: goto P_0c065a54;
case 0x0c065a56u: goto P_0c065a56;
case 0x0c065a58u: goto P_0c065a58;
case 0x0c065a5au: goto P_0c065a5a;
case 0x0c065a5cu: goto P_0c065a5c;
case 0x0c065a5eu: goto P_0c065a5e;
case 0x0c065a60u: goto P_0c065a60;
case 0x0c065a62u: goto P_0c065a62;
case 0x0c065a64u: goto P_0c065a64;
case 0x0c065a66u: goto P_0c065a66;
case 0x0c065a68u: goto P_0c065a68;
case 0x0c065a6au: goto P_0c065a6a;
case 0x0c065a6cu: goto P_0c065a6c;
case 0x0c065a6eu: goto P_0c065a6e;
case 0x0c065a70u: goto P_0c065a70;
case 0x0c065a72u: goto P_0c065a72;
case 0x0c065a74u: goto P_0c065a74;
case 0x0c065a76u: goto P_0c065a76;
case 0x0c065a78u: goto P_0c065a78;
case 0x0c065a7au: goto P_0c065a7a;
case 0x0c065a7cu: goto P_0c065a7c;
case 0x0c065a7eu: goto P_0c065a7e;
case 0x0c065a80u: goto P_0c065a80;
case 0x0c065a82u: goto P_0c065a82;
case 0x0c065a84u: goto P_0c065a84;
case 0x0c065a86u: goto P_0c065a86;
case 0x0c065a88u: goto P_0c065a88;
case 0x0c065a8au: goto P_0c065a8a;
case 0x0c065a8cu: goto P_0c065a8c;
case 0x0c065a8eu: goto P_0c065a8e;
case 0x0c065a90u: goto P_0c065a90;
case 0x0c065a92u: goto P_0c065a92;
case 0x0c08583cu: goto P_0c08583c;
case 0x0c08583eu: goto P_0c08583e;
case 0x0c085840u: goto P_0c085840;
case 0x0c085842u: goto P_0c085842;
case 0x0c085844u: goto P_0c085844;
case 0x0c085846u: goto P_0c085846;
case 0x0c085848u: goto P_0c085848;
case 0x0c08584au: goto P_0c08584a;
case 0x0c08584cu: goto P_0c08584c;
case 0x0c08584eu: goto P_0c08584e;
case 0x0c085850u: goto P_0c085850;
case 0x0c085852u: goto P_0c085852;
case 0x0c085854u: goto P_0c085854;
case 0x0c085856u: goto P_0c085856;
case 0x0c085858u: goto P_0c085858;
case 0x0c08585au: goto P_0c08585a;
case 0x0c08585cu: goto P_0c08585c;
case 0x0c08585eu: goto P_0c08585e;
case 0x0c085860u: goto P_0c085860;
case 0x0c085862u: goto P_0c085862;
case 0x0c085864u: goto P_0c085864;
case 0x0c085866u: goto P_0c085866;
case 0x0c085868u: goto P_0c085868;
case 0x0c08586au: goto P_0c08586a;
case 0x0c08586cu: goto P_0c08586c;
case 0x0c08586eu: goto P_0c08586e;
case 0x0c085870u: goto P_0c085870;
case 0x0c085872u: goto P_0c085872;
case 0x0c085874u: goto P_0c085874;
case 0x0c085876u: goto P_0c085876;
case 0x0c085878u: goto P_0c085878;
case 0x0c08587au: goto P_0c08587a;
case 0x0c08587cu: goto P_0c08587c;
case 0x0c08587eu: goto P_0c08587e;
case 0x0c085880u: goto P_0c085880;
case 0x0c085882u: goto P_0c085882;
case 0x0c085884u: goto P_0c085884;
case 0x0c085886u: goto P_0c085886;
case 0x0c085888u: goto P_0c085888;
case 0x0c08588au: goto P_0c08588a;
case 0x0c08588cu: goto P_0c08588c;
case 0x0c08588eu: goto P_0c08588e;
case 0x0c085890u: goto P_0c085890;
case 0x0c085892u: goto P_0c085892;
case 0x0c085894u: goto P_0c085894;
case 0x0c085896u: goto P_0c085896;
case 0x0c085898u: goto P_0c085898;
case 0x0c08589au: goto P_0c08589a;
case 0x0c08589cu: goto P_0c08589c;
case 0x0c08589eu: goto P_0c08589e;
case 0x0c0858a0u: goto P_0c0858a0;
case 0x0c0858a2u: goto P_0c0858a2;
case 0x0c0858a4u: goto P_0c0858a4;
case 0x0c0858a6u: goto P_0c0858a6;
case 0x0c0858a8u: goto P_0c0858a8;
case 0x0c0858aau: goto P_0c0858aa;
case 0x0c0858acu: goto P_0c0858ac;
case 0x0c0858aeu: goto P_0c0858ae;
case 0x0c0858b0u: goto P_0c0858b0;
case 0x0c0858b2u: goto P_0c0858b2;
case 0x0c0858b4u: goto P_0c0858b4;
case 0x0c0858b6u: goto P_0c0858b6;
case 0x0c0858b8u: goto P_0c0858b8;
case 0x0c0858bau: goto P_0c0858ba;
case 0x0c0858bcu: goto P_0c0858bc;
case 0x0c0858beu: goto P_0c0858be;
case 0x0c0858c0u: goto P_0c0858c0;
case 0x0c0858c2u: goto P_0c0858c2;
case 0x0c0858c4u: goto P_0c0858c4;
case 0x0c0858c6u: goto P_0c0858c6;
case 0x0c0858c8u: goto P_0c0858c8;
case 0x0c0858cau: goto P_0c0858ca;
case 0x0c0858ccu: goto P_0c0858cc;
case 0x0c0858ceu: goto P_0c0858ce;
case 0x0c0858d0u: goto P_0c0858d0;
case 0x0c0858d2u: goto P_0c0858d2;
case 0x0c0858d4u: goto P_0c0858d4;
case 0x0c0858d6u: goto P_0c0858d6;
case 0x0c0858d8u: goto P_0c0858d8;
case 0x0c0882a2u: goto P_0c0882a2;
case 0x0c0882a4u: goto P_0c0882a4;
case 0x0c0882a6u: goto P_0c0882a6;
case 0x0c0882a8u: goto P_0c0882a8;
case 0x0c0882aau: goto P_0c0882aa;
case 0x0c0882acu: goto P_0c0882ac;
case 0x0c0882aeu: goto P_0c0882ae;
case 0x0c0882b0u: goto P_0c0882b0;
case 0x0c0882b2u: goto P_0c0882b2;
case 0x0c0882b4u: goto P_0c0882b4;
case 0x0c0882b6u: goto P_0c0882b6;
case 0x0c0882b8u: goto P_0c0882b8;
case 0x0c0882bau: goto P_0c0882ba;
case 0x0c0882bcu: goto P_0c0882bc;
case 0x0c0882beu: goto P_0c0882be;
case 0x0c0882c0u: goto P_0c0882c0;
case 0x0c0882c2u: goto P_0c0882c2;
case 0x0c0882c4u: goto P_0c0882c4;
case 0x0c0882c6u: goto P_0c0882c6;
case 0x0c0882c8u: goto P_0c0882c8;
case 0x0c0882cau: goto P_0c0882ca;
case 0x0c0882ccu: goto P_0c0882cc;
case 0x0c0882ceu: goto P_0c0882ce;
case 0x0c0882d0u: goto P_0c0882d0;
case 0x0c0882d2u: goto P_0c0882d2;
case 0x0c0882d4u: goto P_0c0882d4;
case 0x0c0882d6u: goto P_0c0882d6;
case 0x0c0882d8u: goto P_0c0882d8;
case 0x0c0882dau: goto P_0c0882da;
case 0x0c0882dcu: goto P_0c0882dc;
case 0x0c0882deu: goto P_0c0882de;
case 0x0c08830cu: goto P_0c08830c;
case 0x0c08830eu: goto P_0c08830e;
case 0x0c088310u: goto P_0c088310;
case 0x0c088312u: goto P_0c088312;
case 0x0c088314u: goto P_0c088314;
case 0x0c088316u: goto P_0c088316;
case 0x0c088318u: goto P_0c088318;
case 0x0c08831au: goto P_0c08831a;
case 0x0c08831cu: goto P_0c08831c;
case 0x0c08831eu: goto P_0c08831e;
case 0x0c088320u: goto P_0c088320;
case 0x0c088322u: goto P_0c088322;
case 0x0c088324u: goto P_0c088324;
case 0x0c088326u: goto P_0c088326;
case 0x0c088328u: goto P_0c088328;
case 0x0c08832au: goto P_0c08832a;
case 0x0c08832cu: goto P_0c08832c;
case 0x0c08832eu: goto P_0c08832e;
case 0x0c088330u: goto P_0c088330;
case 0x0c088332u: goto P_0c088332;
case 0x0c088334u: goto P_0c088334;
case 0x0c088336u: goto P_0c088336;
case 0x0c088338u: goto P_0c088338;
case 0x0c08833au: goto P_0c08833a;
case 0x0c08833cu: goto P_0c08833c;
case 0x0c08833eu: goto P_0c08833e;
case 0x0c088340u: goto P_0c088340;
case 0x0c088342u: goto P_0c088342;
case 0x0c088344u: goto P_0c088344;
case 0x0c088346u: goto P_0c088346;
case 0x0c088348u: goto P_0c088348;
case 0x0c08834au: goto P_0c08834a;
case 0x0c08834cu: goto P_0c08834c;
case 0x0c08834eu: goto P_0c08834e;
case 0x0c088350u: goto P_0c088350;
case 0x0c088352u: goto P_0c088352;
case 0x0c088354u: goto P_0c088354;
case 0x0c088356u: goto P_0c088356;
case 0x0c088370u: goto P_0c088370;
case 0x0c088372u: goto P_0c088372;
case 0x0c088374u: goto P_0c088374;
case 0x0c088376u: goto P_0c088376;
case 0x0c088378u: goto P_0c088378;
case 0x0c08837au: goto P_0c08837a;
case 0x0c08837cu: goto P_0c08837c;
case 0x0c08837eu: goto P_0c08837e;
case 0x0c088380u: goto P_0c088380;
case 0x0c088382u: goto P_0c088382;
case 0x0c088384u: goto P_0c088384;
case 0x0c088386u: goto P_0c088386;
case 0x0c088388u: goto P_0c088388;
case 0x0c08838au: goto P_0c08838a;
case 0x0c08838cu: goto P_0c08838c;
case 0x0c08838eu: goto P_0c08838e;
case 0x0c088390u: goto P_0c088390;
case 0x0c088392u: goto P_0c088392;
case 0x0c088394u: goto P_0c088394;
case 0x0c088396u: goto P_0c088396;
case 0x0c088398u: goto P_0c088398;
case 0x0c08839au: goto P_0c08839a;
case 0x0c08839cu: goto P_0c08839c;
case 0x0c08839eu: goto P_0c08839e;
case 0x0c0883a0u: goto P_0c0883a0;
case 0x0c0883a2u: goto P_0c0883a2;
case 0x0c0883a4u: goto P_0c0883a4;
case 0x0c0883a6u: goto P_0c0883a6;
case 0x0c0883a8u: goto P_0c0883a8;
case 0x0c0883aau: goto P_0c0883aa;
case 0x0c0883acu: goto P_0c0883ac;
case 0x0c0883aeu: goto P_0c0883ae;
case 0x0c0883b0u: goto P_0c0883b0;
case 0x0c0883b2u: goto P_0c0883b2;
case 0x0c0883b4u: goto P_0c0883b4;
case 0x0c0883b6u: goto P_0c0883b6;
case 0x0c0883b8u: goto P_0c0883b8;
case 0x0c0883bau: goto P_0c0883ba;
case 0x0c0883bcu: goto P_0c0883bc;
case 0x0c0883beu: goto P_0c0883be;
case 0x0c0883c0u: goto P_0c0883c0;
case 0x0c0883c2u: goto P_0c0883c2;
case 0x0c0883c4u: goto P_0c0883c4;
case 0x0c0883c6u: goto P_0c0883c6;
case 0x0c0883c8u: goto P_0c0883c8;
case 0x0c0883cau: goto P_0c0883ca;
case 0x0c0883ccu: goto P_0c0883cc;
case 0x0c0883ceu: goto P_0c0883ce;
case 0x0c0883d0u: goto P_0c0883d0;
case 0x0c0883d2u: goto P_0c0883d2;
case 0x0c0883d4u: goto P_0c0883d4;
case 0x0c0883d6u: goto P_0c0883d6;
case 0x0c0883d8u: goto P_0c0883d8;
case 0x0c0883dau: goto P_0c0883da;
case 0x0c0883dcu: goto P_0c0883dc;
case 0x0c0883deu: goto P_0c0883de;
case 0x0c0883e0u: goto P_0c0883e0;
case 0x0c0883e2u: goto P_0c0883e2;
case 0x0c0883e4u: goto P_0c0883e4;
case 0x0c0883e6u: goto P_0c0883e6;
case 0x0c0883e8u: goto P_0c0883e8;
case 0x0c0883eau: goto P_0c0883ea;
case 0x0c0883ecu: goto P_0c0883ec;
case 0x0c0883eeu: goto P_0c0883ee;
case 0x0c0883f0u: goto P_0c0883f0;
case 0x0c0883f2u: goto P_0c0883f2;
case 0x0c0883f4u: goto P_0c0883f4;
case 0x0c0883f6u: goto P_0c0883f6;
case 0x0c0883f8u: goto P_0c0883f8;
case 0x0c0883fau: goto P_0c0883fa;
case 0x0c0883fcu: goto P_0c0883fc;
case 0x0c0883feu: goto P_0c0883fe;
case 0x0c088400u: goto P_0c088400;
case 0x0c088402u: goto P_0c088402;
case 0x0c088404u: goto P_0c088404;
case 0x0c088406u: goto P_0c088406;
case 0x0c088408u: goto P_0c088408;
case 0x0c08840au: goto P_0c08840a;
case 0x0c08840cu: goto P_0c08840c;
case 0x0c08840eu: goto P_0c08840e;
case 0x0c088410u: goto P_0c088410;
case 0x0c088412u: goto P_0c088412;
case 0x0c088414u: goto P_0c088414;
case 0x0c088416u: goto P_0c088416;
case 0x0c088418u: goto P_0c088418;
case 0x0c08841au: goto P_0c08841a;
case 0x0c08841cu: goto P_0c08841c;
case 0x0c08841eu: goto P_0c08841e;
case 0x0c088420u: goto P_0c088420;
case 0x0c088422u: goto P_0c088422;
case 0x0c088424u: goto P_0c088424;
case 0x0c088426u: goto P_0c088426;
case 0x0c088428u: goto P_0c088428;
case 0x0c08842au: goto P_0c08842a;
case 0x0c08842cu: goto P_0c08842c;
case 0x0c08842eu: goto P_0c08842e;
case 0x0c088430u: goto P_0c088430;
case 0x0c088432u: goto P_0c088432;
case 0x0c088434u: goto P_0c088434;
case 0x0c088436u: goto P_0c088436;
case 0x0c088438u: goto P_0c088438;
case 0x0c08843au: goto P_0c08843a;
case 0x0c08843cu: goto P_0c08843c;
case 0x0c08843eu: goto P_0c08843e;
case 0x0c088440u: goto P_0c088440;
case 0x0c088442u: goto P_0c088442;
case 0x0c088444u: goto P_0c088444;
case 0x0c088446u: goto P_0c088446;
case 0x0c088448u: goto P_0c088448;
case 0x0c08844au: goto P_0c08844a;
case 0x0c08844cu: goto P_0c08844c;
case 0x0c08844eu: goto P_0c08844e;
case 0x0c088450u: goto P_0c088450;
case 0x0c088452u: goto P_0c088452;
case 0x0c088454u: goto P_0c088454;
case 0x0c088456u: goto P_0c088456;
case 0x0c088458u: goto P_0c088458;
case 0x0c08845au: goto P_0c08845a;
case 0x0c08845cu: goto P_0c08845c;
case 0x0c08845eu: goto P_0c08845e;
case 0x0c088460u: goto P_0c088460;
case 0x0c088462u: goto P_0c088462;
case 0x0c088464u: goto P_0c088464;
case 0x0c088466u: goto P_0c088466;
case 0x0c088468u: goto P_0c088468;
case 0x0c08846au: goto P_0c08846a;
case 0x0c08846cu: goto P_0c08846c;
case 0x0c08846eu: goto P_0c08846e;
case 0x0c088470u: goto P_0c088470;
case 0x0c088472u: goto P_0c088472;
case 0x0c088474u: goto P_0c088474;
case 0x0c088476u: goto P_0c088476;
case 0x0c088478u: goto P_0c088478;
case 0x0c08847au: goto P_0c08847a;
case 0x0c08847cu: goto P_0c08847c;
case 0x0c08847eu: goto P_0c08847e;
case 0x0c088480u: goto P_0c088480;
case 0x0c088482u: goto P_0c088482;
case 0x0c088484u: goto P_0c088484;
case 0x0c088486u: goto P_0c088486;
case 0x0c088488u: goto P_0c088488;
case 0x0c08848au: goto P_0c08848a;
case 0x0c08848cu: goto P_0c08848c;
case 0x0c08848eu: goto P_0c08848e;
case 0x0c08a076u: goto P_0c08a076;
case 0x0c08a078u: goto P_0c08a078;
case 0x0c08a07au: goto P_0c08a07a;
case 0x0c08a07cu: goto P_0c08a07c;
case 0x0c08a07eu: goto P_0c08a07e;
case 0x0c08a080u: goto P_0c08a080;
case 0x0c08a082u: goto P_0c08a082;
case 0x0c08a084u: goto P_0c08a084;
case 0x0c08a086u: goto P_0c08a086;
case 0x0c08a088u: goto P_0c08a088;
case 0x0c08a08au: goto P_0c08a08a;
case 0x0c08a08cu: goto P_0c08a08c;
case 0x0c08a08eu: goto P_0c08a08e;
case 0x0c08a090u: goto P_0c08a090;
case 0x0c08a092u: goto P_0c08a092;
case 0x0c08a094u: goto P_0c08a094;
case 0x0c08a096u: goto P_0c08a096;
case 0x0c08a098u: goto P_0c08a098;
case 0x0c08a09au: goto P_0c08a09a;
case 0x0c08a09cu: goto P_0c08a09c;
case 0x0c08a09eu: goto P_0c08a09e;
case 0x0c08a0a0u: goto P_0c08a0a0;
case 0x0c08a0a2u: goto P_0c08a0a2;
case 0x0c08a0a4u: goto P_0c08a0a4;
case 0x0c08a0a6u: goto P_0c08a0a6;
case 0x0c08a0a8u: goto P_0c08a0a8;
case 0x0c08a0aau: goto P_0c08a0aa;
case 0x0c08a0acu: goto P_0c08a0ac;
case 0x0c08a0aeu: goto P_0c08a0ae;
case 0x0c08a0b0u: goto P_0c08a0b0;
case 0x0c08a0b2u: goto P_0c08a0b2;
case 0x0c08a0b4u: goto P_0c08a0b4;
case 0x0c08a0b6u: goto P_0c08a0b6;
case 0x0c08a0b8u: goto P_0c08a0b8;
case 0x0c08a0bau: goto P_0c08a0ba;
case 0x0c08a0bcu: goto P_0c08a0bc;
case 0x0c08a0beu: goto P_0c08a0be;
case 0x0c08a0c0u: goto P_0c08a0c0;
case 0x0c08a0c2u: goto P_0c08a0c2;
case 0x0c08a0c4u: goto P_0c08a0c4;
case 0x0c08a0c6u: goto P_0c08a0c6;
case 0x0c08a0c8u: goto P_0c08a0c8;
case 0x0c08a0cau: goto P_0c08a0ca;
case 0x0c08a0ccu: goto P_0c08a0cc;
case 0x0c08a0ceu: goto P_0c08a0ce;
case 0x0c08a0d0u: goto P_0c08a0d0;
case 0x0c08a0d2u: goto P_0c08a0d2;
case 0x0c08a0d4u: goto P_0c08a0d4;
case 0x0c08a0d6u: goto P_0c08a0d6;
case 0x0c08a0d8u: goto P_0c08a0d8;
case 0x0c08a0dau: goto P_0c08a0da;
case 0x0c08a0dcu: goto P_0c08a0dc;
case 0x0c08a0deu: goto P_0c08a0de;
case 0x0c08a0e0u: goto P_0c08a0e0;
case 0x0c08a0e2u: goto P_0c08a0e2;
case 0x0c08a0e4u: goto P_0c08a0e4;
case 0x0c08a0e6u: goto P_0c08a0e6;
case 0x0c08a0e8u: goto P_0c08a0e8;
case 0x0c08a0eau: goto P_0c08a0ea;
case 0x0c08a0ecu: goto P_0c08a0ec;
case 0x0c08a0eeu: goto P_0c08a0ee;
case 0x0c08a0f0u: goto P_0c08a0f0;
case 0x0c08a0f2u: goto P_0c08a0f2;
case 0x0c08a0f4u: goto P_0c08a0f4;
case 0x0c08a0f6u: goto P_0c08a0f6;
case 0x0c08a0f8u: goto P_0c08a0f8;
case 0x0c08a0fau: goto P_0c08a0fa;
case 0x0c08a0fcu: goto P_0c08a0fc;
case 0x0c08a0feu: goto P_0c08a0fe;
case 0x0c08a100u: goto P_0c08a100;
case 0x0c08a102u: goto P_0c08a102;
case 0x0c08a104u: goto P_0c08a104;
case 0x0c08a106u: goto P_0c08a106;
case 0x0c08a108u: goto P_0c08a108;
case 0x0c08a10au: goto P_0c08a10a;
case 0x0c08a10cu: goto P_0c08a10c;
case 0x0c08a10eu: goto P_0c08a10e;
case 0x0c08a110u: goto P_0c08a110;
case 0x0c08a112u: goto P_0c08a112;
case 0x0c08a114u: goto P_0c08a114;
case 0x0c08a116u: goto P_0c08a116;
case 0x0c08a118u: goto P_0c08a118;
case 0x0c08a11au: goto P_0c08a11a;
case 0x0c08a11cu: goto P_0c08a11c;
case 0x0c08a11eu: goto P_0c08a11e;
case 0x0c08a120u: goto P_0c08a120;
case 0x0c08a122u: goto P_0c08a122;
case 0x0c08a124u: goto P_0c08a124;
case 0x0c08a126u: goto P_0c08a126;
case 0x0c08a128u: goto P_0c08a128;
case 0x0c08a12au: goto P_0c08a12a;
case 0x0c08a12cu: goto P_0c08a12c;
case 0x0c08a12eu: goto P_0c08a12e;
case 0x0c08a130u: goto P_0c08a130;
case 0x0c08a132u: goto P_0c08a132;
case 0x0c08a134u: goto P_0c08a134;
case 0x0c08a136u: goto P_0c08a136;
case 0x0c08a138u: goto P_0c08a138;
case 0x0c08a13au: goto P_0c08a13a;
case 0x0c08a13cu: goto P_0c08a13c;
case 0x0c08a13eu: goto P_0c08a13e;
case 0x0c08a140u: goto P_0c08a140;
case 0x0c08a142u: goto P_0c08a142;
case 0x0c08a144u: goto P_0c08a144;
case 0x0c08a146u: goto P_0c08a146;
case 0x0c08a148u: goto P_0c08a148;
case 0x0c08a14au: goto P_0c08a14a;
case 0x0c08a14cu: goto P_0c08a14c;
case 0x0c08a14eu: goto P_0c08a14e;
case 0x0c08a150u: goto P_0c08a150;
case 0x0c08a152u: goto P_0c08a152;
case 0x0c08a154u: goto P_0c08a154;
case 0x0c08a156u: goto P_0c08a156;
case 0x0c08a158u: goto P_0c08a158;
case 0x0c08a15au: goto P_0c08a15a;
case 0x0c08a15cu: goto P_0c08a15c;
case 0x0c08a15eu: goto P_0c08a15e;
case 0x0c08a160u: goto P_0c08a160;
case 0x0c08a162u: goto P_0c08a162;
case 0x0c08a164u: goto P_0c08a164;
case 0x0c08a166u: goto P_0c08a166;
case 0x0c08a168u: goto P_0c08a168;
case 0x0c08a16au: goto P_0c08a16a;
case 0x0c08a16cu: goto P_0c08a16c;
case 0x0c08a16eu: goto P_0c08a16e;
case 0x0c08a170u: goto P_0c08a170;
case 0x0c08a172u: goto P_0c08a172;
case 0x0c08a174u: goto P_0c08a174;
case 0x0c08a176u: goto P_0c08a176;
case 0x0c08a178u: goto P_0c08a178;
case 0x0c08a17au: goto P_0c08a17a;
case 0x0c08a17cu: goto P_0c08a17c;
case 0x0c08a17eu: goto P_0c08a17e;
case 0x0c08a180u: goto P_0c08a180;
case 0x0c08a182u: goto P_0c08a182;
case 0x0c08a184u: goto P_0c08a184;
case 0x0c08a186u: goto P_0c08a186;
case 0x0c08a188u: goto P_0c08a188;
case 0x0c08a18au: goto P_0c08a18a;
case 0x0c08a18cu: goto P_0c08a18c;
case 0x0c08a18eu: goto P_0c08a18e;
case 0x0c08a190u: goto P_0c08a190;
case 0x0c08a192u: goto P_0c08a192;
case 0x0c08a194u: goto P_0c08a194;
case 0x0c08a196u: goto P_0c08a196;
case 0x0c08a198u: goto P_0c08a198;
case 0x0c08a19au: goto P_0c08a19a;
case 0x0c08a19cu: goto P_0c08a19c;
case 0x0c08a19eu: goto P_0c08a19e;
case 0x0c08a1a0u: goto P_0c08a1a0;
case 0x0c08a1a2u: goto P_0c08a1a2;
case 0x0c08a1a4u: goto P_0c08a1a4;
case 0x0c08a1a6u: goto P_0c08a1a6;
case 0x0c08a1a8u: goto P_0c08a1a8;
case 0x0c08a1aau: goto P_0c08a1aa;
case 0x0c08a1acu: goto P_0c08a1ac;
case 0x0c08a1aeu: goto P_0c08a1ae;
case 0x0c08a1b0u: goto P_0c08a1b0;
case 0x0c08a1b2u: goto P_0c08a1b2;
case 0x0c08a1b4u: goto P_0c08a1b4;
case 0x0c08a1b6u: goto P_0c08a1b6;
case 0x0c08a1b8u: goto P_0c08a1b8;
case 0x0c08a1bau: goto P_0c08a1ba;
case 0x0c08a1bcu: goto P_0c08a1bc;
case 0x0c08a1beu: goto P_0c08a1be;
case 0x0c08a1c0u: goto P_0c08a1c0;
case 0x0c08a1c2u: goto P_0c08a1c2;
case 0x0c08a1c4u: goto P_0c08a1c4;
case 0x0c08a1c6u: goto P_0c08a1c6;
case 0x0c08a1c8u: goto P_0c08a1c8;
case 0x0c08a1cau: goto P_0c08a1ca;
case 0x0c08a1ccu: goto P_0c08a1cc;
case 0x0c08a1ceu: goto P_0c08a1ce;
case 0x0c08a1d0u: goto P_0c08a1d0;
case 0x0c08a1d2u: goto P_0c08a1d2;
case 0x0c08a1d4u: goto P_0c08a1d4;
case 0x0c08a1d6u: goto P_0c08a1d6;
case 0x0c08a1d8u: goto P_0c08a1d8;
case 0x0c08a1dau: goto P_0c08a1da;
case 0x0c08a1dcu: goto P_0c08a1dc;
case 0x0c08a23cu: goto P_0c08a23c;
case 0x0c08a23eu: goto P_0c08a23e;
case 0x0c08a240u: goto P_0c08a240;
case 0x0c08a242u: goto P_0c08a242;
case 0x0c08a244u: goto P_0c08a244;
case 0x0c08a246u: goto P_0c08a246;
case 0x0c08a248u: goto P_0c08a248;
case 0x0c08a24au: goto P_0c08a24a;
case 0x0c08a24cu: goto P_0c08a24c;
case 0x0c08a24eu: goto P_0c08a24e;
case 0x0c08a250u: goto P_0c08a250;
case 0x0c08a252u: goto P_0c08a252;
case 0x0c08a254u: goto P_0c08a254;
case 0x0c08a256u: goto P_0c08a256;
case 0x0c08a258u: goto P_0c08a258;
case 0x0c08a25au: goto P_0c08a25a;
case 0x0c08a25cu: goto P_0c08a25c;
case 0x0c08a25eu: goto P_0c08a25e;
case 0x0c08a260u: goto P_0c08a260;
case 0x0c08a262u: goto P_0c08a262;
case 0x0c08a264u: goto P_0c08a264;
case 0x0c08a266u: goto P_0c08a266;
case 0x0c08a268u: goto P_0c08a268;
case 0x0c08a26au: goto P_0c08a26a;
case 0x0c08a26cu: goto P_0c08a26c;
case 0x0c08a26eu: goto P_0c08a26e;
case 0x0c08a270u: goto P_0c08a270;
case 0x0c08a272u: goto P_0c08a272;
case 0x0c08a274u: goto P_0c08a274;
case 0x0c08a276u: goto P_0c08a276;
case 0x0c08a278u: goto P_0c08a278;
case 0x0c08a27au: goto P_0c08a27a;
case 0x0c08a27cu: goto P_0c08a27c;
case 0x0c08a27eu: goto P_0c08a27e;
case 0x0c08a280u: goto P_0c08a280;
case 0x0c08a282u: goto P_0c08a282;
case 0x0c08a284u: goto P_0c08a284;
case 0x0c08a286u: goto P_0c08a286;
case 0x0c08a288u: goto P_0c08a288;
case 0x0c08a28au: goto P_0c08a28a;
case 0x0c08a28cu: goto P_0c08a28c;
case 0x0c08a28eu: goto P_0c08a28e;
case 0x0c08a290u: goto P_0c08a290;
case 0x0c08a292u: goto P_0c08a292;
case 0x0c08a294u: goto P_0c08a294;
case 0x0c08a296u: goto P_0c08a296;
case 0x0c08a298u: goto P_0c08a298;
case 0x0c08a29au: goto P_0c08a29a;
case 0x0c08a29cu: goto P_0c08a29c;
case 0x0c08a29eu: goto P_0c08a29e;
case 0x0c08a2a0u: goto P_0c08a2a0;
case 0x0c08a2a2u: goto P_0c08a2a2;
case 0x0c08a2a4u: goto P_0c08a2a4;
case 0x0c08a2a6u: goto P_0c08a2a6;
case 0x0c08a2a8u: goto P_0c08a2a8;
case 0x0c08a2aau: goto P_0c08a2aa;
case 0x0c08a2acu: goto P_0c08a2ac;
case 0x0c08a2aeu: goto P_0c08a2ae;
case 0x0c08a2b0u: goto P_0c08a2b0;
case 0x0c08a2b2u: goto P_0c08a2b2;
case 0x0c08a2b4u: goto P_0c08a2b4;
case 0x0c08a2b6u: goto P_0c08a2b6;
case 0x0c08a2b8u: goto P_0c08a2b8;
case 0x0c08a2bau: goto P_0c08a2ba;
case 0x0c08a2bcu: goto P_0c08a2bc;
case 0x0c08a2beu: goto P_0c08a2be;
case 0x0c08a2c0u: goto P_0c08a2c0;
case 0x0c08a2c2u: goto P_0c08a2c2;
case 0x0c08a2c4u: goto P_0c08a2c4;
case 0x0c08a2c6u: goto P_0c08a2c6;
case 0x0c08a2c8u: goto P_0c08a2c8;
case 0x0c08a2cau: goto P_0c08a2ca;
case 0x0c08ed9au: goto P_0c08ed9a;
case 0x0c08ed9cu: goto P_0c08ed9c;
case 0x0c08ed9eu: goto P_0c08ed9e;
case 0x0c08eda0u: goto P_0c08eda0;
case 0x0c08eda2u: goto P_0c08eda2;
case 0x0c08eda4u: goto P_0c08eda4;
case 0x0c08eda6u: goto P_0c08eda6;
case 0x0c08eda8u: goto P_0c08eda8;
case 0x0c08edaau: goto P_0c08edaa;
case 0x0c08edacu: goto P_0c08edac;
case 0x0c08edaeu: goto P_0c08edae;
case 0x0c08edb0u: goto P_0c08edb0;
case 0x0c08edb2u: goto P_0c08edb2;
case 0x0c08edb4u: goto P_0c08edb4;
case 0x0c08edb6u: goto P_0c08edb6;
case 0x0c08edb8u: goto P_0c08edb8;
case 0x0c08edbau: goto P_0c08edba;
case 0x0c08edbcu: goto P_0c08edbc;
case 0x0c08edbeu: goto P_0c08edbe;
case 0x0c08edc0u: goto P_0c08edc0;
case 0x0c08edc2u: goto P_0c08edc2;
case 0x0c08edc4u: goto P_0c08edc4;
case 0x0c08edc6u: goto P_0c08edc6;
case 0x0c08edc8u: goto P_0c08edc8;
case 0x0c08edcau: goto P_0c08edca;
case 0x0c08edccu: goto P_0c08edcc;
case 0x0c08edceu: goto P_0c08edce;
case 0x0c08edd0u: goto P_0c08edd0;
case 0x0c08edd2u: goto P_0c08edd2;
case 0x0c08edd4u: goto P_0c08edd4;
case 0x0c08edd6u: goto P_0c08edd6;
case 0x0c08edd8u: goto P_0c08edd8;
case 0x0c08eddau: goto P_0c08edda;
case 0x0c08eddcu: goto P_0c08eddc;
case 0x0c08eddeu: goto P_0c08edde;
case 0x0c08ede0u: goto P_0c08ede0;
case 0x0c08ede2u: goto P_0c08ede2;
case 0x0c08ede4u: goto P_0c08ede4;
case 0x0c08ede6u: goto P_0c08ede6;
case 0x0c08ede8u: goto P_0c08ede8;
case 0x0c08edeau: goto P_0c08edea;
case 0x0c08edecu: goto P_0c08edec;
case 0x0c08edeeu: goto P_0c08edee;
case 0x0c08edf0u: goto P_0c08edf0;
case 0x0c08edf2u: goto P_0c08edf2;
case 0x0c08edf4u: goto P_0c08edf4;
case 0x0c08edf6u: goto P_0c08edf6;
case 0x0c08edf8u: goto P_0c08edf8;
case 0x0c08edfau: goto P_0c08edfa;
case 0x0c08edfcu: goto P_0c08edfc;
case 0x0c08edfeu: goto P_0c08edfe;
case 0x0c08ee00u: goto P_0c08ee00;
case 0x0c08ee02u: goto P_0c08ee02;
case 0x0c08ee04u: goto P_0c08ee04;
case 0x0c08ee06u: goto P_0c08ee06;
case 0x0c08ee08u: goto P_0c08ee08;
case 0x0c08ee0au: goto P_0c08ee0a;
case 0x0c08ee0cu: goto P_0c08ee0c;
case 0x0c08ee0eu: goto P_0c08ee0e;
case 0x0c08ee10u: goto P_0c08ee10;
case 0x0c08ee12u: goto P_0c08ee12;
case 0x0c08ee14u: goto P_0c08ee14;
case 0x0c08ee16u: goto P_0c08ee16;
case 0x0c08ee18u: goto P_0c08ee18;
case 0x0c08ee1au: goto P_0c08ee1a;
case 0x0c08ee1cu: goto P_0c08ee1c;
case 0x0c08ee1eu: goto P_0c08ee1e;
case 0x0c08ee20u: goto P_0c08ee20;
case 0x0c08ee22u: goto P_0c08ee22;
case 0x0c08ee24u: goto P_0c08ee24;
case 0x0c08ee26u: goto P_0c08ee26;
case 0x0c08ee28u: goto P_0c08ee28;
case 0x0c08ee2au: goto P_0c08ee2a;
case 0x0c08ee2cu: goto P_0c08ee2c;
case 0x0c08ee2eu: goto P_0c08ee2e;
case 0x0c08ee30u: goto P_0c08ee30;
case 0x0c08ee32u: goto P_0c08ee32;
case 0x0c08ee34u: goto P_0c08ee34;
case 0x0c08ee36u: goto P_0c08ee36;
case 0x0c08ee38u: goto P_0c08ee38;
case 0x0c08ee3au: goto P_0c08ee3a;
case 0x0c08ee3cu: goto P_0c08ee3c;
case 0x0c08ee3eu: goto P_0c08ee3e;
case 0x0c08ee40u: goto P_0c08ee40;
case 0x0c08ee42u: goto P_0c08ee42;
case 0x0c08ee44u: goto P_0c08ee44;
case 0x0c08ee46u: goto P_0c08ee46;
case 0x0c08ee48u: goto P_0c08ee48;
case 0x0c08ee4au: goto P_0c08ee4a;
case 0x0c08ee4cu: goto P_0c08ee4c;
case 0x0c08ee4eu: goto P_0c08ee4e;
case 0x0c08ee50u: goto P_0c08ee50;
case 0x0c08ee52u: goto P_0c08ee52;
case 0x0c08ee54u: goto P_0c08ee54;
case 0x0c08ee56u: goto P_0c08ee56;
case 0x0c08ee58u: goto P_0c08ee58;
case 0x0c08ee5au: goto P_0c08ee5a;
case 0x0c08ee5cu: goto P_0c08ee5c;
case 0x0c08ee5eu: goto P_0c08ee5e;
case 0x0c08ee60u: goto P_0c08ee60;
case 0x0c08ee62u: goto P_0c08ee62;
case 0x0c08ee64u: goto P_0c08ee64;
case 0x0c08ee66u: goto P_0c08ee66;
case 0x0c08ee68u: goto P_0c08ee68;
case 0x0c08ee6au: goto P_0c08ee6a;
case 0x0c08ee6cu: goto P_0c08ee6c;
case 0x0c08ee6eu: goto P_0c08ee6e;
case 0x0c08ee70u: goto P_0c08ee70;
case 0x0c08ee72u: goto P_0c08ee72;
case 0x0c08ee74u: goto P_0c08ee74;
case 0x0c08ee76u: goto P_0c08ee76;
case 0x0c08ee78u: goto P_0c08ee78;
case 0x0c08ee7au: goto P_0c08ee7a;
case 0x0c08ee7cu: goto P_0c08ee7c;
case 0x0c08ee7eu: goto P_0c08ee7e;
case 0x0c08ee80u: goto P_0c08ee80;
case 0x0c08ee82u: goto P_0c08ee82;
case 0x0c08ee84u: goto P_0c08ee84;
case 0x0c08ee86u: goto P_0c08ee86;
case 0x0c08ee88u: goto P_0c08ee88;
case 0x0c08ee8au: goto P_0c08ee8a;
case 0x0c08ee8cu: goto P_0c08ee8c;
case 0x0c08ee8eu: goto P_0c08ee8e;
case 0x0c08ee90u: goto P_0c08ee90;
case 0x0c08ee92u: goto P_0c08ee92;
case 0x0c08ee94u: goto P_0c08ee94;
case 0x0c08ee96u: goto P_0c08ee96;
case 0x0c08ee98u: goto P_0c08ee98;
case 0x0c08ee9au: goto P_0c08ee9a;
case 0x0c08ee9cu: goto P_0c08ee9c;
case 0x0c08ee9eu: goto P_0c08ee9e;
case 0x0c08eea0u: goto P_0c08eea0;
case 0x0c08eea2u: goto P_0c08eea2;
case 0x0c08eea4u: goto P_0c08eea4;
case 0x0c08eea6u: goto P_0c08eea6;
case 0x0c08eea8u: goto P_0c08eea8;
case 0x0c08eeaau: goto P_0c08eeaa;
case 0x0c08eeacu: goto P_0c08eeac;
case 0x0c08eeaeu: goto P_0c08eeae;
case 0x0c08eeb0u: goto P_0c08eeb0;
case 0x0c08eeb2u: goto P_0c08eeb2;
case 0x0c08eeb4u: goto P_0c08eeb4;
case 0x0c08eeb6u: goto P_0c08eeb6;
case 0x0c08eeb8u: goto P_0c08eeb8;
case 0x0c08eebau: goto P_0c08eeba;
case 0x0c08eebcu: goto P_0c08eebc;
case 0x0c08eebeu: goto P_0c08eebe;
case 0x0c08eec0u: goto P_0c08eec0;
case 0x0c08eec2u: goto P_0c08eec2;
case 0x0c08eec4u: goto P_0c08eec4;
case 0x0c08eec6u: goto P_0c08eec6;
case 0x0c08eec8u: goto P_0c08eec8;
case 0x0c08eecau: goto P_0c08eeca;
case 0x0c08eeccu: goto P_0c08eecc;
case 0x0c08eeceu: goto P_0c08eece;
case 0x0c08eed0u: goto P_0c08eed0;
case 0x0c08eed2u: goto P_0c08eed2;
case 0x0c08eed4u: goto P_0c08eed4;
case 0x0c08eed6u: goto P_0c08eed6;
case 0x0c08eed8u: goto P_0c08eed8;
case 0x0c08eedau: goto P_0c08eeda;
case 0x0c08eedcu: goto P_0c08eedc;
case 0x0c08eedeu: goto P_0c08eede;
case 0x0c08eee0u: goto P_0c08eee0;
case 0x0c08eee2u: goto P_0c08eee2;
case 0x0c08eee4u: goto P_0c08eee4;
case 0x0c08eee6u: goto P_0c08eee6;
case 0x0c08eee8u: goto P_0c08eee8;
case 0x0c08eeeau: goto P_0c08eeea;
case 0x0c08eeecu: goto P_0c08eeec;
case 0x0c08eeeeu: goto P_0c08eeee;
case 0x0c08eef0u: goto P_0c08eef0;
case 0x0c08eef2u: goto P_0c08eef2;
case 0x0c08eef4u: goto P_0c08eef4;
case 0x0c08eef6u: goto P_0c08eef6;
case 0x0c08eef8u: goto P_0c08eef8;
case 0x0c08eefau: goto P_0c08eefa;
case 0x0c08eefcu: goto P_0c08eefc;
case 0x0c08eefeu: goto P_0c08eefe;
case 0x0c08ef00u: goto P_0c08ef00;
case 0x0c08ef02u: goto P_0c08ef02;
case 0x0c08ef04u: goto P_0c08ef04;
case 0x0c08ef06u: goto P_0c08ef06;
case 0x0c08ef08u: goto P_0c08ef08;
case 0x0c08ef62u: goto P_0c08ef62;
case 0x0c08ef64u: goto P_0c08ef64;
case 0x0c08ef66u: goto P_0c08ef66;
case 0x0c08ef68u: goto P_0c08ef68;
case 0x0c08ef6au: goto P_0c08ef6a;
case 0x0c08ef6cu: goto P_0c08ef6c;
case 0x0c08ef6eu: goto P_0c08ef6e;
case 0x0c08ef70u: goto P_0c08ef70;
case 0x0c08ef72u: goto P_0c08ef72;
case 0x0c08ef74u: goto P_0c08ef74;
case 0x0c08ef76u: goto P_0c08ef76;
case 0x0c08ef78u: goto P_0c08ef78;
case 0x0c08ef7au: goto P_0c08ef7a;
case 0x0c08ef7cu: goto P_0c08ef7c;
case 0x0c08ef7eu: goto P_0c08ef7e;
case 0x0c08ef80u: goto P_0c08ef80;
case 0x0c08ef82u: goto P_0c08ef82;
case 0x0c08ef84u: goto P_0c08ef84;
case 0x0c08ef86u: goto P_0c08ef86;
case 0x0c08ef88u: goto P_0c08ef88;
case 0x0c08ef8au: goto P_0c08ef8a;
case 0x0c08ef8cu: goto P_0c08ef8c;
case 0x0c08ef8eu: goto P_0c08ef8e;
case 0x0c08ef90u: goto P_0c08ef90;
case 0x0c08ef92u: goto P_0c08ef92;
case 0x0c08ef94u: goto P_0c08ef94;
case 0x0c08ef96u: goto P_0c08ef96;
case 0x0c08ef98u: goto P_0c08ef98;
case 0x0c08ef9au: goto P_0c08ef9a;
case 0x0c08ef9cu: goto P_0c08ef9c;
case 0x0c08ef9eu: goto P_0c08ef9e;
case 0x0c08efa0u: goto P_0c08efa0;
case 0x0c08efa2u: goto P_0c08efa2;
case 0x0c08efa4u: goto P_0c08efa4;
case 0x0c08efa6u: goto P_0c08efa6;
case 0x0c08efa8u: goto P_0c08efa8;
case 0x0c08efaau: goto P_0c08efaa;
case 0x0c08efacu: goto P_0c08efac;
case 0x0c08efaeu: goto P_0c08efae;
case 0x0c08efb0u: goto P_0c08efb0;
case 0x0c08efb2u: goto P_0c08efb2;
case 0x0c08efb4u: goto P_0c08efb4;
case 0x0c08efb6u: goto P_0c08efb6;
case 0x0c08efb8u: goto P_0c08efb8;
case 0x0c08efbau: goto P_0c08efba;
case 0x0c08efbcu: goto P_0c08efbc;
case 0x0c08efbeu: goto P_0c08efbe;
case 0x0c08efc0u: goto P_0c08efc0;
case 0x0c08efc2u: goto P_0c08efc2;
case 0x0c08efc4u: goto P_0c08efc4;
case 0x0c08efc6u: goto P_0c08efc6;
case 0x0c08efc8u: goto P_0c08efc8;
case 0x0c08efcau: goto P_0c08efca;
case 0x0c08efccu: goto P_0c08efcc;
case 0x0c08efceu: goto P_0c08efce;
case 0x0c08efd0u: goto P_0c08efd0;
case 0x0c08efd2u: goto P_0c08efd2;
case 0x0c08efd4u: goto P_0c08efd4;
case 0x0c08efd6u: goto P_0c08efd6;
case 0x0c08efd8u: goto P_0c08efd8;
case 0x0c08efdau: goto P_0c08efda;
case 0x0c08efdcu: goto P_0c08efdc;
case 0x0c08efdeu: goto P_0c08efde;
case 0x0c08efe0u: goto P_0c08efe0;
case 0x0c08efe2u: goto P_0c08efe2;
case 0x0c08efe4u: goto P_0c08efe4;
case 0x0c08efe6u: goto P_0c08efe6;
case 0x0c08efe8u: goto P_0c08efe8;
case 0x0c08efeau: goto P_0c08efea;
case 0x0c08efecu: goto P_0c08efec;
case 0x0c08efeeu: goto P_0c08efee;
case 0x0c08eff0u: goto P_0c08eff0;
case 0x0c08eff2u: goto P_0c08eff2;
case 0x0c08eff4u: goto P_0c08eff4;
case 0x0c08eff6u: goto P_0c08eff6;
case 0x0c08eff8u: goto P_0c08eff8;
case 0x0c08effau: goto P_0c08effa;
case 0x0c08effcu: goto P_0c08effc;
case 0x0c08effeu: goto P_0c08effe;
case 0x0c08f000u: goto P_0c08f000;
case 0x0c08f002u: goto P_0c08f002;
case 0x0c08f004u: goto P_0c08f004;
case 0x0c08f006u: goto P_0c08f006;
case 0x0c08f008u: goto P_0c08f008;
case 0x0c08f00au: goto P_0c08f00a;
case 0x0c08f00cu: goto P_0c08f00c;
case 0x0c08f00eu: goto P_0c08f00e;
case 0x0c08f010u: goto P_0c08f010;
case 0x0c08f012u: goto P_0c08f012;
case 0x0c08f014u: goto P_0c08f014;
case 0x0c08f016u: goto P_0c08f016;
case 0x0c08f018u: goto P_0c08f018;
case 0x0c08f01au: goto P_0c08f01a;
case 0x0c08f01cu: goto P_0c08f01c;
case 0x0c08f01eu: goto P_0c08f01e;
case 0x0c08f020u: goto P_0c08f020;
case 0x0c08f022u: goto P_0c08f022;
case 0x0c08f024u: goto P_0c08f024;
case 0x0c08f026u: goto P_0c08f026;
case 0x0c08f028u: goto P_0c08f028;
case 0x0c08f02au: goto P_0c08f02a;
case 0x0c08f02cu: goto P_0c08f02c;
case 0x0c08f02eu: goto P_0c08f02e;
case 0x0c08f030u: goto P_0c08f030;
case 0x0c08f032u: goto P_0c08f032;
case 0x0c08f034u: goto P_0c08f034;
case 0x0c08f036u: goto P_0c08f036;
case 0x0c08f038u: goto P_0c08f038;
case 0x0c08f03au: goto P_0c08f03a;
case 0x0c08f03cu: goto P_0c08f03c;
case 0x0c08f03eu: goto P_0c08f03e;
case 0x0c08f040u: goto P_0c08f040;
case 0x0c08f042u: goto P_0c08f042;
case 0x0c08f044u: goto P_0c08f044;
case 0x0c08f046u: goto P_0c08f046;
case 0x0c08f048u: goto P_0c08f048;
case 0x0c08f04au: goto P_0c08f04a;
case 0x0c08f04cu: goto P_0c08f04c;
case 0x0c08f04eu: goto P_0c08f04e;
case 0x0c08f050u: goto P_0c08f050;
case 0x0c08f052u: goto P_0c08f052;
case 0x0c08f054u: goto P_0c08f054;
case 0x0c08f056u: goto P_0c08f056;
case 0x0c08f058u: goto P_0c08f058;
case 0x0c08f05au: goto P_0c08f05a;
case 0x0c08f05cu: goto P_0c08f05c;
case 0x0c08f05eu: goto P_0c08f05e;
case 0x0c08f060u: goto P_0c08f060;
case 0x0c08f062u: goto P_0c08f062;
case 0x0c08f064u: goto P_0c08f064;
case 0x0c08f066u: goto P_0c08f066;
case 0x0c08f068u: goto P_0c08f068;
case 0x0c08f06au: goto P_0c08f06a;
case 0x0c08f06cu: goto P_0c08f06c;
case 0x0c08f06eu: goto P_0c08f06e;
case 0x0c08f070u: goto P_0c08f070;
case 0x0c08f072u: goto P_0c08f072;
case 0x0c08f074u: goto P_0c08f074;
case 0x0c08f076u: goto P_0c08f076;
case 0x0c08f078u: goto P_0c08f078;
case 0x0c08f07au: goto P_0c08f07a;
case 0x0c08f07cu: goto P_0c08f07c;
case 0x0c08f07eu: goto P_0c08f07e;
case 0x0c08f080u: goto P_0c08f080;
case 0x0c08f082u: goto P_0c08f082;
case 0x0c08f084u: goto P_0c08f084;
case 0x0c08f086u: goto P_0c08f086;
case 0x0c08f088u: goto P_0c08f088;
case 0x0c08f08au: goto P_0c08f08a;
case 0x0c08f08cu: goto P_0c08f08c;
case 0x0c08f08eu: goto P_0c08f08e;
case 0x0c08f090u: goto P_0c08f090;
case 0x0c08f092u: goto P_0c08f092;
case 0x0c08f094u: goto P_0c08f094;
case 0x0c08f096u: goto P_0c08f096;
case 0x0c08f098u: goto P_0c08f098;
case 0x0c08f09au: goto P_0c08f09a;
case 0x0c08f09cu: goto P_0c08f09c;
case 0x0c08f09eu: goto P_0c08f09e;
case 0x0c08f0a0u: goto P_0c08f0a0;
case 0x0c08f0a2u: goto P_0c08f0a2;
case 0x0c08f0a4u: goto P_0c08f0a4;
case 0x0c08f0a6u: goto P_0c08f0a6;
case 0x0c08f0a8u: goto P_0c08f0a8;
case 0x0c08f0aau: goto P_0c08f0aa;
case 0x0c08f0acu: goto P_0c08f0ac;
case 0x0c08f0aeu: goto P_0c08f0ae;
case 0x0c08f0b0u: goto P_0c08f0b0;
case 0x0c08f0b2u: goto P_0c08f0b2;
case 0x0c08f0b4u: goto P_0c08f0b4;
case 0x0c08f0b6u: goto P_0c08f0b6;
case 0x0c08f0b8u: goto P_0c08f0b8;
case 0x0c08f0bau: goto P_0c08f0ba;
case 0x0c08f0bcu: goto P_0c08f0bc;
case 0x0c08f0beu: goto P_0c08f0be;
case 0x0c08f0c0u: goto P_0c08f0c0;
case 0x0c08f0c2u: goto P_0c08f0c2;
case 0x0c08f0c4u: goto P_0c08f0c4;
case 0x0c08f0c6u: goto P_0c08f0c6;
case 0x0c08f0c8u: goto P_0c08f0c8;
case 0x0c08f0cau: goto P_0c08f0ca;
case 0x0c08f0ccu: goto P_0c08f0cc;
case 0x0c08f0ceu: goto P_0c08f0ce;
case 0x0c08f0d0u: goto P_0c08f0d0;
case 0x0c08f0d2u: goto P_0c08f0d2;
case 0x0c08f0d4u: goto P_0c08f0d4;
case 0x0c08f0d6u: goto P_0c08f0d6;
case 0x0c08f0d8u: goto P_0c08f0d8;
case 0x0c08f0dau: goto P_0c08f0da;
case 0x0c08f0dcu: goto P_0c08f0dc;
case 0x0c08f0deu: goto P_0c08f0de;
case 0x0c08f0e0u: goto P_0c08f0e0;
case 0x0c08f0e2u: goto P_0c08f0e2;
case 0x0c08f0e4u: goto P_0c08f0e4;
case 0x0c08f3d8u: goto P_0c08f3d8;
case 0x0c08f3dau: goto P_0c08f3da;
case 0x0c08f3dcu: goto P_0c08f3dc;
case 0x0c08f3deu: goto P_0c08f3de;
case 0x0c08f3e0u: goto P_0c08f3e0;
case 0x0c08f3e2u: goto P_0c08f3e2;
case 0x0c08f3e4u: goto P_0c08f3e4;
case 0x0c08f3e6u: goto P_0c08f3e6;
case 0x0c08f3e8u: goto P_0c08f3e8;
case 0x0c08f3eau: goto P_0c08f3ea;
case 0x0c08f3ecu: goto P_0c08f3ec;
case 0x0c08f3eeu: goto P_0c08f3ee;
case 0x0c08f3f0u: goto P_0c08f3f0;
case 0x0c08f3f2u: goto P_0c08f3f2;
case 0x0c08f3f4u: goto P_0c08f3f4;
case 0x0c08f3f6u: goto P_0c08f3f6;
case 0x0c08f3f8u: goto P_0c08f3f8;
case 0x0c08f3fau: goto P_0c08f3fa;
case 0x0c08f3fcu: goto P_0c08f3fc;
case 0x0c08f3feu: goto P_0c08f3fe;
case 0x0c08f400u: goto P_0c08f400;
case 0x0c08f402u: goto P_0c08f402;
case 0x0c08f404u: goto P_0c08f404;
case 0x0c08f406u: goto P_0c08f406;
case 0x0c08f408u: goto P_0c08f408;
case 0x0c08f40au: goto P_0c08f40a;
case 0x0c08f40cu: goto P_0c08f40c;
case 0x0c08f40eu: goto P_0c08f40e;
case 0x0c08f410u: goto P_0c08f410;
case 0x0c08f412u: goto P_0c08f412;
case 0x0c08f414u: goto P_0c08f414;
case 0x0c08f416u: goto P_0c08f416;
case 0x0c08f418u: goto P_0c08f418;
case 0x0c08f41au: goto P_0c08f41a;
case 0x0c08f41cu: goto P_0c08f41c;
case 0x0c08f41eu: goto P_0c08f41e;
case 0x0c08f420u: goto P_0c08f420;
case 0x0c08f422u: goto P_0c08f422;
case 0x0c08f424u: goto P_0c08f424;
case 0x0c08f426u: goto P_0c08f426;
case 0x0c08f428u: goto P_0c08f428;
case 0x0c08f42au: goto P_0c08f42a;
case 0x0c08f42cu: goto P_0c08f42c;
case 0x0c08f42eu: goto P_0c08f42e;
case 0x0c08f430u: goto P_0c08f430;
case 0x0c08f432u: goto P_0c08f432;
case 0x0c08f434u: goto P_0c08f434;
case 0x0c08f436u: goto P_0c08f436;
case 0x0c08f438u: goto P_0c08f438;
case 0x0c08f43au: goto P_0c08f43a;
case 0x0c08f43cu: goto P_0c08f43c;
case 0x0c08f43eu: goto P_0c08f43e;
case 0x0c08f440u: goto P_0c08f440;
case 0x0c08f442u: goto P_0c08f442;
case 0x0c08f444u: goto P_0c08f444;
case 0x0c08f446u: goto P_0c08f446;
case 0x0c08f448u: goto P_0c08f448;
case 0x0c08f44au: goto P_0c08f44a;
case 0x0c08f44cu: goto P_0c08f44c;
case 0x0c08f44eu: goto P_0c08f44e;
case 0x0c08f450u: goto P_0c08f450;
case 0x0c08f452u: goto P_0c08f452;
case 0x0c08f454u: goto P_0c08f454;
case 0x0c08f456u: goto P_0c08f456;
case 0x0c08f458u: goto P_0c08f458;
case 0x0c08f45au: goto P_0c08f45a;
case 0x0c08f45cu: goto P_0c08f45c;
case 0x0c08f45eu: goto P_0c08f45e;
case 0x0c08f460u: goto P_0c08f460;
case 0x0c08f462u: goto P_0c08f462;
case 0x0c08f464u: goto P_0c08f464;
case 0x0c08f466u: goto P_0c08f466;
case 0x0c08f468u: goto P_0c08f468;
case 0x0c08f46au: goto P_0c08f46a;
case 0x0c08f46cu: goto P_0c08f46c;
case 0x0c08f46eu: goto P_0c08f46e;
case 0x0c08f470u: goto P_0c08f470;
case 0x0c08f472u: goto P_0c08f472;
case 0x0c08f474u: goto P_0c08f474;
case 0x0c08f476u: goto P_0c08f476;
case 0x0c08f478u: goto P_0c08f478;
case 0x0c08f47au: goto P_0c08f47a;
case 0x0c08f47cu: goto P_0c08f47c;
case 0x0c08f47eu: goto P_0c08f47e;
case 0x0c08f480u: goto P_0c08f480;
case 0x0c08f482u: goto P_0c08f482;
case 0x0c08f484u: goto P_0c08f484;
case 0x0c08f486u: goto P_0c08f486;
case 0x0c08f488u: goto P_0c08f488;
case 0x0c08f48au: goto P_0c08f48a;
case 0x0c08f48cu: goto P_0c08f48c;
case 0x0c08f48eu: goto P_0c08f48e;
case 0x0c08f490u: goto P_0c08f490;
case 0x0c08f492u: goto P_0c08f492;
case 0x0c08f494u: goto P_0c08f494;
case 0x0c08f496u: goto P_0c08f496;
case 0x0c08f498u: goto P_0c08f498;
case 0x0c08f49au: goto P_0c08f49a;
case 0x0c08f49cu: goto P_0c08f49c;
case 0x0c08f49eu: goto P_0c08f49e;
case 0x0c08f4a0u: goto P_0c08f4a0;
case 0x0c08f4a2u: goto P_0c08f4a2;
case 0x0c08f4a4u: goto P_0c08f4a4;
case 0x0c08f4a6u: goto P_0c08f4a6;
case 0x0c08f4a8u: goto P_0c08f4a8;
case 0x0c08f4aau: goto P_0c08f4aa;
case 0x0c08f4acu: goto P_0c08f4ac;
case 0x0c08f548u: goto P_0c08f548;
case 0x0c08f54au: goto P_0c08f54a;
case 0x0c08f54cu: goto P_0c08f54c;
case 0x0c08f54eu: goto P_0c08f54e;
case 0x0c08f550u: goto P_0c08f550;
case 0x0c08f552u: goto P_0c08f552;
case 0x0c08f554u: goto P_0c08f554;
case 0x0c08f556u: goto P_0c08f556;
case 0x0c08f558u: goto P_0c08f558;
case 0x0c08f55au: goto P_0c08f55a;
case 0x0c08f55cu: goto P_0c08f55c;
case 0x0c08f55eu: goto P_0c08f55e;
case 0x0c08f560u: goto P_0c08f560;
case 0x0c08f562u: goto P_0c08f562;
case 0x0c08f564u: goto P_0c08f564;
case 0x0c08f566u: goto P_0c08f566;
case 0x0c08f568u: goto P_0c08f568;
case 0x0c08f56au: goto P_0c08f56a;
case 0x0c08f56cu: goto P_0c08f56c;
case 0x0c08f56eu: goto P_0c08f56e;
case 0x0c08f570u: goto P_0c08f570;
case 0x0c08f572u: goto P_0c08f572;
case 0x0c08f574u: goto P_0c08f574;
case 0x0c08f576u: goto P_0c08f576;
case 0x0c08f578u: goto P_0c08f578;
case 0x0c08f57au: goto P_0c08f57a;
case 0x0c08f57cu: goto P_0c08f57c;
case 0x0c08f57eu: goto P_0c08f57e;
case 0x0c08f580u: goto P_0c08f580;
case 0x0c08f5beu: goto P_0c08f5be;
case 0x0c08f5c0u: goto P_0c08f5c0;
case 0x0c090e14u: goto P_0c090e14;
case 0x0c090e16u: goto P_0c090e16;
case 0x0c090e18u: goto P_0c090e18;
case 0x0c090e1au: goto P_0c090e1a;
case 0x0c090e1cu: goto P_0c090e1c;
case 0x0c090e1eu: goto P_0c090e1e;
case 0x0c090e20u: goto P_0c090e20;
case 0x0c090e22u: goto P_0c090e22;
case 0x0c090e24u: goto P_0c090e24;
case 0x0c090e26u: goto P_0c090e26;
case 0x0c090e28u: goto P_0c090e28;
case 0x0c090e2au: goto P_0c090e2a;
case 0x0c090e2cu: goto P_0c090e2c;
case 0x0c090e2eu: goto P_0c090e2e;
case 0x0c090e30u: goto P_0c090e30;
case 0x0c090e32u: goto P_0c090e32;
case 0x0c090e34u: goto P_0c090e34;
case 0x0c090e36u: goto P_0c090e36;
case 0x0c090e38u: goto P_0c090e38;
case 0x0c090e3au: goto P_0c090e3a;
case 0x0c090e3cu: goto P_0c090e3c;
case 0x0c090e3eu: goto P_0c090e3e;
case 0x0c090e40u: goto P_0c090e40;
case 0x0c090e42u: goto P_0c090e42;
case 0x0c090e44u: goto P_0c090e44;
case 0x0c090e46u: goto P_0c090e46;
case 0x0c090e48u: goto P_0c090e48;
case 0x0c090e4au: goto P_0c090e4a;
case 0x0c090e4cu: goto P_0c090e4c;
case 0x0c090e4eu: goto P_0c090e4e;
case 0x0c090e50u: goto P_0c090e50;
case 0x0c090e52u: goto P_0c090e52;
case 0x0c090e54u: goto P_0c090e54;
case 0x0c090e56u: goto P_0c090e56;
case 0x0c090e58u: goto P_0c090e58;
case 0x0c090e5au: goto P_0c090e5a;
case 0x0c090e5cu: goto P_0c090e5c;
case 0x0c090e5eu: goto P_0c090e5e;
case 0x0c090e60u: goto P_0c090e60;
case 0x0c090e62u: goto P_0c090e62;
case 0x0c090e64u: goto P_0c090e64;
case 0x0c090e66u: goto P_0c090e66;
case 0x0c090e68u: goto P_0c090e68;
case 0x0c090e6au: goto P_0c090e6a;
case 0x0c090e6cu: goto P_0c090e6c;
case 0x0c090e6eu: goto P_0c090e6e;
case 0x0c090e70u: goto P_0c090e70;
case 0x0c090e72u: goto P_0c090e72;
case 0x0c090e74u: goto P_0c090e74;
case 0x0c090e76u: goto P_0c090e76;
case 0x0c090e78u: goto P_0c090e78;
case 0x0c090e7au: goto P_0c090e7a;
case 0x0c090e7cu: goto P_0c090e7c;
case 0x0c090e7eu: goto P_0c090e7e;
case 0x0c090e80u: goto P_0c090e80;
case 0x0c090e82u: goto P_0c090e82;
case 0x0c090e84u: goto P_0c090e84;
case 0x0c090e86u: goto P_0c090e86;
case 0x0c090e88u: goto P_0c090e88;
case 0x0c090e8au: goto P_0c090e8a;
case 0x0c090e8cu: goto P_0c090e8c;
case 0x0c090e8eu: goto P_0c090e8e;
case 0x0c090e90u: goto P_0c090e90;
case 0x0c090e92u: goto P_0c090e92;
case 0x0c090e94u: goto P_0c090e94;
case 0x0c090e96u: goto P_0c090e96;
case 0x0c090e98u: goto P_0c090e98;
case 0x0c090e9au: goto P_0c090e9a;
case 0x0c090e9cu: goto P_0c090e9c;
case 0x0c090e9eu: goto P_0c090e9e;
case 0x0c090ea0u: goto P_0c090ea0;
case 0x0c090ea2u: goto P_0c090ea2;
case 0x0c090ea4u: goto P_0c090ea4;
case 0x0c090ea6u: goto P_0c090ea6;
case 0x0c090ea8u: goto P_0c090ea8;
case 0x0c090eaau: goto P_0c090eaa;
case 0x0c090eacu: goto P_0c090eac;
case 0x0c090eaeu: goto P_0c090eae;
case 0x0c090eb0u: goto P_0c090eb0;
case 0x0c090eb2u: goto P_0c090eb2;
case 0x0c090eb4u: goto P_0c090eb4;
case 0x0c090eb6u: goto P_0c090eb6;
case 0x0c090eb8u: goto P_0c090eb8;
case 0x0c090ebau: goto P_0c090eba;
case 0x0c090ebcu: goto P_0c090ebc;
case 0x0c090ebeu: goto P_0c090ebe;
case 0x0c090ec0u: goto P_0c090ec0;
case 0x0c090ec2u: goto P_0c090ec2;
case 0x0c090ec4u: goto P_0c090ec4;
case 0x0c090ec6u: goto P_0c090ec6;
case 0x0c090ec8u: goto P_0c090ec8;
case 0x0c090ecau: goto P_0c090eca;
case 0x0c090eccu: goto P_0c090ecc;
case 0x0c090eceu: goto P_0c090ece;
case 0x0c090ed0u: goto P_0c090ed0;
case 0x0c090ed2u: goto P_0c090ed2;
case 0x0c090ed4u: goto P_0c090ed4;
case 0x0c090ed6u: goto P_0c090ed6;
case 0x0c090ed8u: goto P_0c090ed8;
case 0x0c090edau: goto P_0c090eda;
case 0x0c090edcu: goto P_0c090edc;
case 0x0c090edeu: goto P_0c090ede;
case 0x0c090ee0u: goto P_0c090ee0;
case 0x0c090ee2u: goto P_0c090ee2;
case 0x0c090ee4u: goto P_0c090ee4;
case 0x0c090ee6u: goto P_0c090ee6;
case 0x0c090ee8u: goto P_0c090ee8;
case 0x0c090eeau: goto P_0c090eea;
case 0x0c090eecu: goto P_0c090eec;
case 0x0c090eeeu: goto P_0c090eee;
case 0x0c090ef0u: goto P_0c090ef0;
case 0x0c090ef2u: goto P_0c090ef2;
case 0x0c090ef4u: goto P_0c090ef4;
case 0x0c090ef6u: goto P_0c090ef6;
case 0x0c090ef8u: goto P_0c090ef8;
case 0x0c090efau: goto P_0c090efa;
case 0x0c090efcu: goto P_0c090efc;
case 0x0c090efeu: goto P_0c090efe;
case 0x0c090f00u: goto P_0c090f00;
case 0x0c090f02u: goto P_0c090f02;
case 0x0c090f04u: goto P_0c090f04;
case 0x0c090f06u: goto P_0c090f06;
case 0x0c090f08u: goto P_0c090f08;
case 0x0c0a028au: goto P_0c0a028a;
case 0x0c0a028cu: goto P_0c0a028c;
case 0x0c0a028eu: goto P_0c0a028e;
case 0x0c0a0290u: goto P_0c0a0290;
case 0x0c0a0292u: goto P_0c0a0292;
case 0x0c0a0294u: goto P_0c0a0294;
case 0x0c0a0296u: goto P_0c0a0296;
case 0x0c0a0298u: goto P_0c0a0298;
case 0x0c0a029au: goto P_0c0a029a;
case 0x0c0a029cu: goto P_0c0a029c;
case 0x0c0a029eu: goto P_0c0a029e;
case 0x0c0a02a0u: goto P_0c0a02a0;
case 0x0c0a02a2u: goto P_0c0a02a2;
case 0x0c0a02a4u: goto P_0c0a02a4;
case 0x0c0a02a6u: goto P_0c0a02a6;
case 0x0c0a02a8u: goto P_0c0a02a8;
case 0x0c0a02aau: goto P_0c0a02aa;
case 0x0c0a02acu: goto P_0c0a02ac;
case 0x0c0a02aeu: goto P_0c0a02ae;
case 0x0c0a02b0u: goto P_0c0a02b0;
case 0x0c0a02b2u: goto P_0c0a02b2;
case 0x0c0a02b4u: goto P_0c0a02b4;
case 0x0c0a02b6u: goto P_0c0a02b6;
case 0x0c0a02b8u: goto P_0c0a02b8;
case 0x0c0a02bau: goto P_0c0a02ba;
case 0x0c0a02bcu: goto P_0c0a02bc;
case 0x0c0a02beu: goto P_0c0a02be;
case 0x0c0a02c0u: goto P_0c0a02c0;
case 0x0c0a02c2u: goto P_0c0a02c2;
case 0x0c0a02c4u: goto P_0c0a02c4;
case 0x0c0a02c6u: goto P_0c0a02c6;
case 0x0c0a02c8u: goto P_0c0a02c8;
case 0x0c0a02cau: goto P_0c0a02ca;
case 0x0c0a02ccu: goto P_0c0a02cc;
case 0x0c0a02ceu: goto P_0c0a02ce;
case 0x0c0a02d0u: goto P_0c0a02d0;
case 0x0c0a02d2u: goto P_0c0a02d2;
case 0x0c0a02d4u: goto P_0c0a02d4;
case 0x0c0a02d6u: goto P_0c0a02d6;
case 0x0c0a02d8u: goto P_0c0a02d8;
case 0x0c0a02dau: goto P_0c0a02da;
case 0x0c0a02dcu: goto P_0c0a02dc;
case 0x0c0a02deu: goto P_0c0a02de;
case 0x0c0a02e0u: goto P_0c0a02e0;
case 0x0c0a02e2u: goto P_0c0a02e2;
case 0x0c0a02e4u: goto P_0c0a02e4;
case 0x0c0a02e6u: goto P_0c0a02e6;
case 0x0c0a02e8u: goto P_0c0a02e8;
case 0x0c0a02eau: goto P_0c0a02ea;
case 0x0c0a02ecu: goto P_0c0a02ec;
case 0x0c0a02eeu: goto P_0c0a02ee;
case 0x0c0a02f0u: goto P_0c0a02f0;
case 0x0c0a02f2u: goto P_0c0a02f2;
case 0x0c0a02f4u: goto P_0c0a02f4;
case 0x0c0a02f6u: goto P_0c0a02f6;
case 0x0c0a02f8u: goto P_0c0a02f8;
case 0x0c0a02fau: goto P_0c0a02fa;
case 0x0c0a02fcu: goto P_0c0a02fc;
case 0x0c0a02feu: goto P_0c0a02fe;
case 0x0c0a0300u: goto P_0c0a0300;
case 0x0c0a0302u: goto P_0c0a0302;
case 0x0c0a0304u: goto P_0c0a0304;
case 0x0c0a0306u: goto P_0c0a0306;
case 0x0c0a0308u: goto P_0c0a0308;
case 0x0c0a030au: goto P_0c0a030a;
case 0x0c0a030cu: goto P_0c0a030c;
case 0x0c0a030eu: goto P_0c0a030e;
case 0x0c0a0310u: goto P_0c0a0310;
case 0x0c0a0312u: goto P_0c0a0312;
case 0x0c0a0314u: goto P_0c0a0314;
case 0x0c0a0316u: goto P_0c0a0316;
case 0x0c0a0318u: goto P_0c0a0318;
case 0x0c0a031au: goto P_0c0a031a;
case 0x0c0a031cu: goto P_0c0a031c;
case 0x0c0a031eu: goto P_0c0a031e;
case 0x0c0a0320u: goto P_0c0a0320;
case 0x0c0a0322u: goto P_0c0a0322;
case 0x0c0a0324u: goto P_0c0a0324;
case 0x0c0a0326u: goto P_0c0a0326;
case 0x0c0a0328u: goto P_0c0a0328;
case 0x0c0a032au: goto P_0c0a032a;
case 0x0c0a032cu: goto P_0c0a032c;
case 0x0c0a032eu: goto P_0c0a032e;
case 0x0c0a7302u: goto P_0c0a7302;
case 0x0c0a7304u: goto P_0c0a7304;
case 0x0c0a7306u: goto P_0c0a7306;
case 0x0c0a7308u: goto P_0c0a7308;
case 0x0c0a730au: goto P_0c0a730a;
case 0x0c0a730cu: goto P_0c0a730c;
case 0x0c0a730eu: goto P_0c0a730e;
case 0x0c0a7310u: goto P_0c0a7310;
case 0x0c0a7312u: goto P_0c0a7312;
case 0x0c0a7314u: goto P_0c0a7314;
case 0x0c0a7316u: goto P_0c0a7316;
case 0x0c0a7318u: goto P_0c0a7318;
case 0x0c0a731au: goto P_0c0a731a;
case 0x0c0a731cu: goto P_0c0a731c;
case 0x0c0a731eu: goto P_0c0a731e;
case 0x0c0a7320u: goto P_0c0a7320;
case 0x0c0a7322u: goto P_0c0a7322;
case 0x0c0a7324u: goto P_0c0a7324;
case 0x0c0a7326u: goto P_0c0a7326;
case 0x0c0a7328u: goto P_0c0a7328;
case 0x0c0a732au: goto P_0c0a732a;
case 0x0c0a732cu: goto P_0c0a732c;
case 0x0c0a732eu: goto P_0c0a732e;
case 0x0c0a7330u: goto P_0c0a7330;
case 0x0c0a7332u: goto P_0c0a7332;
case 0x0c0a7334u: goto P_0c0a7334;
case 0x0c0a7336u: goto P_0c0a7336;
case 0x0c0a7338u: goto P_0c0a7338;
case 0x0c0a733au: goto P_0c0a733a;
case 0x0c0a733cu: goto P_0c0a733c;
case 0x0c0a733eu: goto P_0c0a733e;
case 0x0c0a7340u: goto P_0c0a7340;
case 0x0c0a7342u: goto P_0c0a7342;
case 0x0c0a7344u: goto P_0c0a7344;
case 0x0c0a7346u: goto P_0c0a7346;
case 0x0c0a7348u: goto P_0c0a7348;
case 0x0c0a734au: goto P_0c0a734a;
case 0x0c0a734cu: goto P_0c0a734c;
case 0x0c0a734eu: goto P_0c0a734e;
case 0x0c0a7350u: goto P_0c0a7350;
case 0x0c0a7352u: goto P_0c0a7352;
case 0x0c0a7354u: goto P_0c0a7354;
case 0x0c0a7356u: goto P_0c0a7356;
case 0x0c0a7358u: goto P_0c0a7358;
case 0x0c0a735au: goto P_0c0a735a;
case 0x0c0a735cu: goto P_0c0a735c;
case 0x0c0a735eu: goto P_0c0a735e;
case 0x0c0a7360u: goto P_0c0a7360;
case 0x0c0a7362u: goto P_0c0a7362;
case 0x0c0a7364u: goto P_0c0a7364;
case 0x0c0a7366u: goto P_0c0a7366;
case 0x0c0a7368u: goto P_0c0a7368;
case 0x0c0a736au: goto P_0c0a736a;
case 0x0c0a736cu: goto P_0c0a736c;
case 0x0c0a736eu: goto P_0c0a736e;
case 0x0c0a7370u: goto P_0c0a7370;
case 0x0c0a7372u: goto P_0c0a7372;
case 0x0c0a7374u: goto P_0c0a7374;
case 0x0c0a7376u: goto P_0c0a7376;
case 0x0c0a7378u: goto P_0c0a7378;
case 0x0c0a737au: goto P_0c0a737a;
case 0x0c0a737cu: goto P_0c0a737c;
case 0x0c0a737eu: goto P_0c0a737e;
case 0x0c0a7380u: goto P_0c0a7380;
case 0x0c0a7382u: goto P_0c0a7382;
case 0x0c0a7384u: goto P_0c0a7384;
case 0x0c0a7386u: goto P_0c0a7386;
case 0x0c0a7388u: goto P_0c0a7388;
case 0x0c0a738au: goto P_0c0a738a;
case 0x0c0a738cu: goto P_0c0a738c;
case 0x0c0adc72u: goto P_0c0adc72;
case 0x0c0adc74u: goto P_0c0adc74;
case 0x0c0adc76u: goto P_0c0adc76;
case 0x0c0adc78u: goto P_0c0adc78;
case 0x0c0adc7au: goto P_0c0adc7a;
case 0x0c0adc7cu: goto P_0c0adc7c;
case 0x0c0adc7eu: goto P_0c0adc7e;
case 0x0c0adc80u: goto P_0c0adc80;
case 0x0c0adc82u: goto P_0c0adc82;
case 0x0c0adc84u: goto P_0c0adc84;
case 0x0c0adc86u: goto P_0c0adc86;
case 0x0c0adc88u: goto P_0c0adc88;
case 0x0c0adc8au: goto P_0c0adc8a;
case 0x0c0adc8cu: goto P_0c0adc8c;
case 0x0c0adc8eu: goto P_0c0adc8e;
case 0x0c0adc90u: goto P_0c0adc90;
case 0x0c0adc92u: goto P_0c0adc92;
case 0x0c0adc94u: goto P_0c0adc94;
case 0x0c0adc96u: goto P_0c0adc96;
case 0x0c0adc98u: goto P_0c0adc98;
case 0x0c0adc9au: goto P_0c0adc9a;
case 0x0c0adc9cu: goto P_0c0adc9c;
case 0x0c0adc9eu: goto P_0c0adc9e;
case 0x0c0adca0u: goto P_0c0adca0;
case 0x0c0adca2u: goto P_0c0adca2;
case 0x0c0adca4u: goto P_0c0adca4;
case 0x0c0adca6u: goto P_0c0adca6;
case 0x0c0adca8u: goto P_0c0adca8;
case 0x0c0adcaau: goto P_0c0adcaa;
case 0x0c0adcacu: goto P_0c0adcac;
case 0x0c0adcaeu: goto P_0c0adcae;
case 0x0c0adcb0u: goto P_0c0adcb0;
case 0x0c0adcb2u: goto P_0c0adcb2;
case 0x0c0adcb4u: goto P_0c0adcb4;
case 0x0c0adcb6u: goto P_0c0adcb6;
case 0x0c0adcb8u: goto P_0c0adcb8;
case 0x0c0adcbau: goto P_0c0adcba;
case 0x0c0adcbcu: goto P_0c0adcbc;
case 0x0c0adcbeu: goto P_0c0adcbe;
case 0x0c0adcc0u: goto P_0c0adcc0;
case 0x0c0adcc2u: goto P_0c0adcc2;
case 0x0c0adcc4u: goto P_0c0adcc4;
case 0x0c0adcc6u: goto P_0c0adcc6;
case 0x0c0adcc8u: goto P_0c0adcc8;
case 0x0c0adccau: goto P_0c0adcca;
case 0x0c0adcccu: goto P_0c0adccc;
case 0x0c0adcceu: goto P_0c0adcce;
case 0x0c0adcd0u: goto P_0c0adcd0;
case 0x0c0adcd2u: goto P_0c0adcd2;
case 0x0c0adcd4u: goto P_0c0adcd4;
case 0x0c0adcd6u: goto P_0c0adcd6;
case 0x0c0adcd8u: goto P_0c0adcd8;
case 0x0c0adcdau: goto P_0c0adcda;
case 0x0c0adcdcu: goto P_0c0adcdc;
case 0x0c0adcdeu: goto P_0c0adcde;
case 0x0c0adce0u: goto P_0c0adce0;
case 0x0c0adce2u: goto P_0c0adce2;
case 0x0c0adce4u: goto P_0c0adce4;
case 0x0c0adce6u: goto P_0c0adce6;
case 0x0c0adce8u: goto P_0c0adce8;
case 0x0c0adceau: goto P_0c0adcea;
case 0x0c0adcecu: goto P_0c0adcec;
case 0x0c0adceeu: goto P_0c0adcee;
case 0x0c0adcf0u: goto P_0c0adcf0;
case 0x0c0adcf2u: goto P_0c0adcf2;
case 0x0c0adcf4u: goto P_0c0adcf4;
case 0x0c0adcf6u: goto P_0c0adcf6;
case 0x0c0adcf8u: goto P_0c0adcf8;
case 0x0c0adcfau: goto P_0c0adcfa;
case 0x0c0adcfcu: goto P_0c0adcfc;
case 0x0c0adcfeu: goto P_0c0adcfe;
case 0x0c0add00u: goto P_0c0add00;
case 0x0c0add02u: goto P_0c0add02;
case 0x0c0add04u: goto P_0c0add04;
case 0x0c0add06u: goto P_0c0add06;
case 0x0c0add08u: goto P_0c0add08;
case 0x0c0add0au: goto P_0c0add0a;
case 0x0c0add0cu: goto P_0c0add0c;
case 0x0c0add0eu: goto P_0c0add0e;
case 0x0c0add10u: goto P_0c0add10;
case 0x0c0add12u: goto P_0c0add12;
case 0x0c0add14u: goto P_0c0add14;
case 0x0c0add16u: goto P_0c0add16;
case 0x0c0add18u: goto P_0c0add18;
case 0x0c0add1au: goto P_0c0add1a;
case 0x0c0add1cu: goto P_0c0add1c;
case 0x0c0add1eu: goto P_0c0add1e;
case 0x0c0add20u: goto P_0c0add20;
case 0x0c0add22u: goto P_0c0add22;
case 0x0c0add24u: goto P_0c0add24;
case 0x0c0c18feu: goto P_0c0c18fe;
case 0x0c0c1900u: goto P_0c0c1900;
case 0x0c0c1902u: goto P_0c0c1902;
case 0x0c0c1904u: goto P_0c0c1904;
case 0x0c0c1906u: goto P_0c0c1906;
case 0x0c0c1908u: goto P_0c0c1908;
case 0x0c0c190au: goto P_0c0c190a;
case 0x0c0c190cu: goto P_0c0c190c;
case 0x0c0c190eu: goto P_0c0c190e;
case 0x0c0c1910u: goto P_0c0c1910;
case 0x0c0c1912u: goto P_0c0c1912;
case 0x0c0c1914u: goto P_0c0c1914;
case 0x0c0c1916u: goto P_0c0c1916;
case 0x0c0c1918u: goto P_0c0c1918;
case 0x0c0c191au: goto P_0c0c191a;
case 0x0c0c191cu: goto P_0c0c191c;
case 0x0c0c191eu: goto P_0c0c191e;
case 0x0c0c1920u: goto P_0c0c1920;
case 0x0c0c1922u: goto P_0c0c1922;
case 0x0c0c1924u: goto P_0c0c1924;
case 0x0c0c1926u: goto P_0c0c1926;
case 0x0c0c1928u: goto P_0c0c1928;
case 0x0c0c192au: goto P_0c0c192a;
case 0x0c0c192cu: goto P_0c0c192c;
case 0x0c0c192eu: goto P_0c0c192e;
case 0x0c0c1930u: goto P_0c0c1930;
case 0x0c0c1932u: goto P_0c0c1932;
case 0x0c0c1934u: goto P_0c0c1934;
case 0x0c0c1936u: goto P_0c0c1936;
case 0x0c0c1938u: goto P_0c0c1938;
case 0x0c0c193au: goto P_0c0c193a;
case 0x0c0c193cu: goto P_0c0c193c;
case 0x0c0c193eu: goto P_0c0c193e;
case 0x0c0c1940u: goto P_0c0c1940;
case 0x0c0c1942u: goto P_0c0c1942;
case 0x0c0c1944u: goto P_0c0c1944;
case 0x0c0c1946u: goto P_0c0c1946;
case 0x0c0c1948u: goto P_0c0c1948;
case 0x0c0c194au: goto P_0c0c194a;
case 0x0c0c194cu: goto P_0c0c194c;
case 0x0c0c194eu: goto P_0c0c194e;
case 0x0c0c1950u: goto P_0c0c1950;
case 0x0c0c1952u: goto P_0c0c1952;
case 0x0c0c1954u: goto P_0c0c1954;
case 0x0c0c1956u: goto P_0c0c1956;
case 0x0c0c1958u: goto P_0c0c1958;
case 0x0c0c195au: goto P_0c0c195a;
case 0x0c0c195cu: goto P_0c0c195c;
case 0x0c0c195eu: goto P_0c0c195e;
case 0x0c0c1960u: goto P_0c0c1960;
case 0x0c0c1962u: goto P_0c0c1962;
case 0x0c0c1964u: goto P_0c0c1964;
case 0x0c0c1966u: goto P_0c0c1966;
case 0x0c0c1968u: goto P_0c0c1968;
case 0x0c0c196au: goto P_0c0c196a;
case 0x0c0c196cu: goto P_0c0c196c;
case 0x0c0c196eu: goto P_0c0c196e;
case 0x0c0c1970u: goto P_0c0c1970;
case 0x0c0c1972u: goto P_0c0c1972;
case 0x0c0c1974u: goto P_0c0c1974;
case 0x0c0c1976u: goto P_0c0c1976;
case 0x0c0c1978u: goto P_0c0c1978;
case 0x0c0c197au: goto P_0c0c197a;
case 0x0c0c197cu: goto P_0c0c197c;
case 0x0c0c197eu: goto P_0c0c197e;
case 0x0c0c1980u: goto P_0c0c1980;
case 0x0c0c1982u: goto P_0c0c1982;
case 0x0c0c1984u: goto P_0c0c1984;
case 0x0c0c1986u: goto P_0c0c1986;
case 0x0c0c1988u: goto P_0c0c1988;
case 0x0c0c198au: goto P_0c0c198a;
case 0x0c0c198cu: goto P_0c0c198c;
case 0x0c0c198eu: goto P_0c0c198e;
case 0x0c0c1990u: goto P_0c0c1990;
case 0x0c0c1992u: goto P_0c0c1992;
case 0x0c0c1994u: goto P_0c0c1994;
case 0x0c0c1996u: goto P_0c0c1996;
case 0x0c0c1998u: goto P_0c0c1998;
case 0x0c0c199au: goto P_0c0c199a;
case 0x0c0c199cu: goto P_0c0c199c;
case 0x0c0c199eu: goto P_0c0c199e;
case 0x0c0c19a0u: goto P_0c0c19a0;
case 0x0c0c19a2u: goto P_0c0c19a2;
case 0x0c0c19a4u: goto P_0c0c19a4;
case 0x0c0c19a6u: goto P_0c0c19a6;
case 0x0c0c19a8u: goto P_0c0c19a8;
case 0x0c0c19aau: goto P_0c0c19aa;
case 0x0c0c19acu: goto P_0c0c19ac;
case 0x0c0c19aeu: goto P_0c0c19ae;
case 0x0c0c19b0u: goto P_0c0c19b0;
case 0x0c0c19b2u: goto P_0c0c19b2;
case 0x0c0c19b4u: goto P_0c0c19b4;
case 0x0c0c19b6u: goto P_0c0c19b6;
case 0x0c0c19b8u: goto P_0c0c19b8;
case 0x0c0ca0c6u: goto P_0c0ca0c6;
case 0x0c0ca0c8u: goto P_0c0ca0c8;
case 0x0c0ca0cau: goto P_0c0ca0ca;
case 0x0c0ca0ccu: goto P_0c0ca0cc;
case 0x0c0ca0ceu: goto P_0c0ca0ce;
case 0x0c0ca0d0u: goto P_0c0ca0d0;
case 0x0c0ca0d2u: goto P_0c0ca0d2;
case 0x0c0ca0d4u: goto P_0c0ca0d4;
case 0x0c0ca0d6u: goto P_0c0ca0d6;
case 0x0c0ca0d8u: goto P_0c0ca0d8;
case 0x0c0ca0dau: goto P_0c0ca0da;
case 0x0c0ca0dcu: goto P_0c0ca0dc;
case 0x0c0ca0deu: goto P_0c0ca0de;
case 0x0c0ca0e0u: goto P_0c0ca0e0;
case 0x0c0ca0e2u: goto P_0c0ca0e2;
case 0x0c0ca0e4u: goto P_0c0ca0e4;
case 0x0c0ca0e6u: goto P_0c0ca0e6;
case 0x0c0ca0e8u: goto P_0c0ca0e8;
case 0x0c0ca0eau: goto P_0c0ca0ea;
case 0x0c0ca0ecu: goto P_0c0ca0ec;
case 0x0c0ca0eeu: goto P_0c0ca0ee;
case 0x0c0ca0f0u: goto P_0c0ca0f0;
case 0x0c0ca0f2u: goto P_0c0ca0f2;
case 0x0c0ca0f4u: goto P_0c0ca0f4;
case 0x0c0ca0f6u: goto P_0c0ca0f6;
case 0x0c0ca0f8u: goto P_0c0ca0f8;
case 0x0c0ca0fau: goto P_0c0ca0fa;
case 0x0c0ca0fcu: goto P_0c0ca0fc;
case 0x0c0ca0feu: goto P_0c0ca0fe;
case 0x0c0ca100u: goto P_0c0ca100;
case 0x0c0ca102u: goto P_0c0ca102;
case 0x0c0ca104u: goto P_0c0ca104;
case 0x0c0ca106u: goto P_0c0ca106;
case 0x0c0ca108u: goto P_0c0ca108;
case 0x0c0ca10au: goto P_0c0ca10a;
case 0x0c0ca10cu: goto P_0c0ca10c;
case 0x0c0ca10eu: goto P_0c0ca10e;
case 0x0c0ca110u: goto P_0c0ca110;
case 0x0c0ca112u: goto P_0c0ca112;
case 0x0c0ca114u: goto P_0c0ca114;
case 0x0c0ca116u: goto P_0c0ca116;
case 0x0c0ca118u: goto P_0c0ca118;
case 0x0c0ca11au: goto P_0c0ca11a;
case 0x0c0ca11cu: goto P_0c0ca11c;
case 0x0c0ca11eu: goto P_0c0ca11e;
case 0x0c0ca120u: goto P_0c0ca120;
case 0x0c0ca122u: goto P_0c0ca122;
case 0x0c0ca124u: goto P_0c0ca124;
case 0x0c0ca126u: goto P_0c0ca126;
case 0x0c0ca128u: goto P_0c0ca128;
case 0x0c0ca12au: goto P_0c0ca12a;
case 0x0c0ca12cu: goto P_0c0ca12c;
case 0x0c0ca12eu: goto P_0c0ca12e;
case 0x0c0ca130u: goto P_0c0ca130;
case 0x0c0ca132u: goto P_0c0ca132;
case 0x0c0ca134u: goto P_0c0ca134;
case 0x0c0ca136u: goto P_0c0ca136;
case 0x0c0ca138u: goto P_0c0ca138;
case 0x0c0ca13au: goto P_0c0ca13a;
case 0x0c0ca13cu: goto P_0c0ca13c;
case 0x0c0ca13eu: goto P_0c0ca13e;
case 0x0c0ca140u: goto P_0c0ca140;
case 0x0c0ca142u: goto P_0c0ca142;
case 0x0c0ca144u: goto P_0c0ca144;
case 0x0c0ca146u: goto P_0c0ca146;
case 0x0c0ca148u: goto P_0c0ca148;
case 0x0c0ca14au: goto P_0c0ca14a;
case 0x0c0ca14cu: goto P_0c0ca14c;
case 0x0c0ca14eu: goto P_0c0ca14e;
case 0x0c0ca150u: goto P_0c0ca150;
case 0x0c0ca152u: goto P_0c0ca152;
case 0x0c0ca154u: goto P_0c0ca154;
case 0x0c0ca156u: goto P_0c0ca156;
case 0x0c0ca158u: goto P_0c0ca158;
case 0x0c0ca15au: goto P_0c0ca15a;
case 0x0c0ca15cu: goto P_0c0ca15c;
case 0x0c0ca15eu: goto P_0c0ca15e;
case 0x0c0ca196u: goto P_0c0ca196;
case 0x0c0ca198u: goto P_0c0ca198;
case 0x0c0ca19au: goto P_0c0ca19a;
case 0x0c0ca19cu: goto P_0c0ca19c;
case 0x0c0ca19eu: goto P_0c0ca19e;
case 0x0c0ca1a0u: goto P_0c0ca1a0;
case 0x0c0ca1a2u: goto P_0c0ca1a2;
case 0x0c0ca1a4u: goto P_0c0ca1a4;
case 0x0c0ca1a6u: goto P_0c0ca1a6;
case 0x0c0ca1a8u: goto P_0c0ca1a8;
case 0x0c0ca1aau: goto P_0c0ca1aa;
case 0x0c0ca1acu: goto P_0c0ca1ac;
case 0x0c0ca1aeu: goto P_0c0ca1ae;
case 0x0c0ca1b0u: goto P_0c0ca1b0;
case 0x0c0ca1b2u: goto P_0c0ca1b2;
case 0x0c0ca1b4u: goto P_0c0ca1b4;
case 0x0c0ca1b6u: goto P_0c0ca1b6;
case 0x0c0ca1b8u: goto P_0c0ca1b8;
case 0x0c0ca1bau: goto P_0c0ca1ba;
case 0x0c0ca1bcu: goto P_0c0ca1bc;
case 0x0c0ca1beu: goto P_0c0ca1be;
case 0x0c0ca1c0u: goto P_0c0ca1c0;
case 0x0c0ca1c2u: goto P_0c0ca1c2;
case 0x0c0ca1c4u: goto P_0c0ca1c4;
case 0x0c0ca1c6u: goto P_0c0ca1c6;
case 0x0c0ca1c8u: goto P_0c0ca1c8;
case 0x0c0ca1cau: goto P_0c0ca1ca;
case 0x0c0ca1ccu: goto P_0c0ca1cc;
case 0x0c0ca1ceu: goto P_0c0ca1ce;
case 0x0c0ca1d0u: goto P_0c0ca1d0;
case 0x0c0ca1d2u: goto P_0c0ca1d2;
case 0x0c0ca1d4u: goto P_0c0ca1d4;
case 0x0c0ca1d6u: goto P_0c0ca1d6;
case 0x0c0ca1d8u: goto P_0c0ca1d8;
case 0x0c0ca1dau: goto P_0c0ca1da;
case 0x0c0ca1dcu: goto P_0c0ca1dc;
case 0x0c0ca1deu: goto P_0c0ca1de;
case 0x0c0ca1e0u: goto P_0c0ca1e0;
case 0x0c0ca1e2u: goto P_0c0ca1e2;
case 0x0c0ca1e4u: goto P_0c0ca1e4;
case 0x0c0ca1e6u: goto P_0c0ca1e6;
case 0x0c0ca1e8u: goto P_0c0ca1e8;
case 0x0c0ca1eau: goto P_0c0ca1ea;
case 0x0c0ca1ecu: goto P_0c0ca1ec;
case 0x0c0ca1eeu: goto P_0c0ca1ee;
case 0x0c0ca1f0u: goto P_0c0ca1f0;
case 0x0c0ca1f2u: goto P_0c0ca1f2;
case 0x0c0ca1f4u: goto P_0c0ca1f4;
case 0x0c0ca1f6u: goto P_0c0ca1f6;
case 0x0c0ca1f8u: goto P_0c0ca1f8;
case 0x0c0ca1fau: goto P_0c0ca1fa;
case 0x0c0ca1fcu: goto P_0c0ca1fc;
case 0x0c0ca1feu: goto P_0c0ca1fe;
case 0x0c0ca200u: goto P_0c0ca200;
case 0x0c0ca202u: goto P_0c0ca202;
case 0x0c0ca204u: goto P_0c0ca204;
case 0x0c0ca206u: goto P_0c0ca206;
case 0x0c0ca208u: goto P_0c0ca208;
case 0x0c0ca20au: goto P_0c0ca20a;
case 0x0c0ca20cu: goto P_0c0ca20c;
case 0x0c0ca20eu: goto P_0c0ca20e;
case 0x0c0ca210u: goto P_0c0ca210;
case 0x0c0ca212u: goto P_0c0ca212;
case 0x0c0ca214u: goto P_0c0ca214;
case 0x0c0ca216u: goto P_0c0ca216;
case 0x0c0ca218u: goto P_0c0ca218;
case 0x0c0ca21au: goto P_0c0ca21a;
case 0x0c0ca21cu: goto P_0c0ca21c;
case 0x0c0ca21eu: goto P_0c0ca21e;
case 0x0c0ca220u: goto P_0c0ca220;
case 0x0c0ca222u: goto P_0c0ca222;
case 0x0c0ca224u: goto P_0c0ca224;
case 0x0c0ca226u: goto P_0c0ca226;
case 0x0c0ca228u: goto P_0c0ca228;
case 0x0c0ca22au: goto P_0c0ca22a;
case 0x0c0ca22cu: goto P_0c0ca22c;
case 0x0c0ca22eu: goto P_0c0ca22e;
default: return vf3_matrix_family(target,s,ram);
}
P_0c038eae: /* original 4f22, guest PC 0x0c038eae */
if(!s->budget--) { s->failed_pc=0x0c038eaeu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c038eb0;
P_0c038eb0: /* original e206, guest PC 0x0c038eb0 */
if(!s->budget--) { s->failed_pc=0x0c038eb0u; return 0; }
r[2]=0x00000006u;
goto P_0c038eb2;
P_0c038eb2: /* original 1e41, guest PC 0x0c038eb2 */
if(!s->budget--) { s->failed_pc=0x0c038eb2u; return 0; }
write(ram,r[14]+4,r[4],4);
goto P_0c038eb4;
P_0c038eb4: /* original e601, guest PC 0x0c038eb4 */
if(!s->budget--) { s->failed_pc=0x0c038eb4u; return 0; }
r[6]=0x00000001u;
goto P_0c038eb6;
P_0c038eb6: /* original 1e42, guest PC 0x0c038eb6 */
if(!s->budget--) { s->failed_pc=0x0c038eb6u; return 0; }
write(ram,r[14]+8,r[4],4);
goto P_0c038eb8;
P_0c038eb8: /* original e504, guest PC 0x0c038eb8 */
if(!s->budget--) { s->failed_pc=0x0c038eb8u; return 0; }
r[5]=0x00000004u;
goto P_0c038eba;
P_0c038eba: /* original 1e63, guest PC 0x0c038eba */
if(!s->budget--) { s->failed_pc=0x0c038ebau; return 0; }
write(ram,r[14]+12,r[6],4);
goto P_0c038ebc;
P_0c038ebc: /* original 0e46, guest PC 0x0c038ebc */
if(!s->budget--) { s->failed_pc=0x0c038ebcu; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c038ebe;
P_0c038ebe: /* original 1e44, guest PC 0x0c038ebe */
if(!s->budget--) { s->failed_pc=0x0c038ebeu; return 0; }
write(ram,r[14]+16,r[4],4);
goto P_0c038ec0;
P_0c038ec0: /* original 1e55, guest PC 0x0c038ec0 */
if(!s->budget--) { s->failed_pc=0x0c038ec0u; return 0; }
write(ram,r[14]+20,r[5],4);
goto P_0c038ec2;
P_0c038ec2: /* original 1e46, guest PC 0x0c038ec2 */
if(!s->budget--) { s->failed_pc=0x0c038ec2u; return 0; }
write(ram,r[14]+24,r[4],4);
goto P_0c038ec4;
P_0c038ec4: /* original 1e47, guest PC 0x0c038ec4 */
if(!s->budget--) { s->failed_pc=0x0c038ec4u; return 0; }
write(ram,r[14]+28,r[4],4);
goto P_0c038ec6;
P_0c038ec6: /* original 1e68, guest PC 0x0c038ec6 */
if(!s->budget--) { s->failed_pc=0x0c038ec6u; return 0; }
write(ram,r[14]+32,r[6],4);
goto P_0c038ec8;
P_0c038ec8: /* original 1e49, guest PC 0x0c038ec8 */
if(!s->budget--) { s->failed_pc=0x0c038ec8u; return 0; }
write(ram,r[14]+36,r[4],4);
goto P_0c038eca;
P_0c038eca: /* original 1e4a, guest PC 0x0c038eca */
if(!s->budget--) { s->failed_pc=0x0c038ecau; return 0; }
write(ram,r[14]+40,r[4],4);
goto P_0c038ecc;
P_0c038ecc: /* original 1e3b, guest PC 0x0c038ecc */
if(!s->budget--) { s->failed_pc=0x0c038eccu; return 0; }
write(ram,r[14]+44,r[3],4);
goto P_0c038ece;
P_0c038ece: /* original e302, guest PC 0x0c038ece */
if(!s->budget--) { s->failed_pc=0x0c038eceu; return 0; }
r[3]=0x00000002u;
goto P_0c038ed0;
P_0c038ed0: /* original 1e2c, guest PC 0x0c038ed0 */
if(!s->budget--) { s->failed_pc=0x0c038ed0u; return 0; }
write(ram,r[14]+48,r[2],4);
goto P_0c038ed2;
P_0c038ed2: /* original 1e4d, guest PC 0x0c038ed2 */
if(!s->budget--) { s->failed_pc=0x0c038ed2u; return 0; }
write(ram,r[14]+52,r[4],4);
goto P_0c038ed4;
P_0c038ed4: /* original 1e4e, guest PC 0x0c038ed4 */
if(!s->budget--) { s->failed_pc=0x0c038ed4u; return 0; }
write(ram,r[14]+56,r[4],4);
goto P_0c038ed6;
P_0c038ed6: /* original 1e3f, guest PC 0x0c038ed6 */
if(!s->budget--) { s->failed_pc=0x0c038ed6u; return 0; }
write(ram,r[14]+60,r[3],4);
goto P_0c038ed8;
P_0c038ed8: /* original 0e46, guest PC 0x0c038ed8 */
if(!s->budget--) { s->failed_pc=0x0c038ed8u; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c038eda;
P_0c038eda: /* original e044, guest PC 0x0c038eda */
if(!s->budget--) { s->failed_pc=0x0c038edau; return 0; }
r[0]=0x00000044u;
goto P_0c038edc;
P_0c038edc: /* original 0e46, guest PC 0x0c038edc */
if(!s->budget--) { s->failed_pc=0x0c038edcu; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c038ede;
P_0c038ede: /* original e048, guest PC 0x0c038ede */
if(!s->budget--) { s->failed_pc=0x0c038edeu; return 0; }
r[0]=0x00000048u;
goto P_0c038ee0;
P_0c038ee0: /* original 0e46, guest PC 0x0c038ee0 */
if(!s->budget--) { s->failed_pc=0x0c038ee0u; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c038ee2;
P_0c038ee2: /* original e04c, guest PC 0x0c038ee2 */
if(!s->budget--) { s->failed_pc=0x0c038ee2u; return 0; }
r[0]=0x0000004cu;
goto P_0c038ee4;
P_0c038ee4: /* original 0e46, guest PC 0x0c038ee4 */
if(!s->budget--) { s->failed_pc=0x0c038ee4u; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c038ee6;
P_0c038ee6: /* original e050, guest PC 0x0c038ee6 */
if(!s->budget--) { s->failed_pc=0x0c038ee6u; return 0; }
r[0]=0x00000050u;
goto P_0c038ee8;
P_0c038ee8: /* original 0e46, guest PC 0x0c038ee8 */
if(!s->budget--) { s->failed_pc=0x0c038ee8u; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c038eea;
P_0c038eea: /* original e054, guest PC 0x0c038eea */
if(!s->budget--) { s->failed_pc=0x0c038eeau; return 0; }
r[0]=0x00000054u;
goto P_0c038eec;
P_0c038eec: /* original 0e46, guest PC 0x0c038eec */
if(!s->budget--) { s->failed_pc=0x0c038eecu; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c038eee;
P_0c038eee: /* original e058, guest PC 0x0c038eee */
if(!s->budget--) { s->failed_pc=0x0c038eeeu; return 0; }
r[0]=0x00000058u;
goto P_0c038ef0;
P_0c038ef0: /* original 0e46, guest PC 0x0c038ef0 */
if(!s->budget--) { s->failed_pc=0x0c038ef0u; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c038ef2;
P_0c038ef2: /* original e05c, guest PC 0x0c038ef2 */
if(!s->budget--) { s->failed_pc=0x0c038ef2u; return 0; }
r[0]=0x0000005cu;
goto P_0c038ef4;
P_0c038ef4: /* original 0e56, guest PC 0x0c038ef4 */
if(!s->budget--) { s->failed_pc=0x0c038ef4u; return 0; }
write(ram,r[14]+r[0],r[5],4);
goto P_0c038ef6;
P_0c038ef6: /* original e060, guest PC 0x0c038ef6 */
if(!s->budget--) { s->failed_pc=0x0c038ef6u; return 0; }
r[0]=0x00000060u;
goto P_0c038ef8;
P_0c038ef8: /* original e303, guest PC 0x0c038ef8 */
if(!s->budget--) { s->failed_pc=0x0c038ef8u; return 0; }
r[3]=0x00000003u;
goto P_0c038efa;
P_0c038efa: /* original 0e36, guest PC 0x0c038efa */
if(!s->budget--) { s->failed_pc=0x0c038efau; return 0; }
write(ram,r[14]+r[0],r[3],4);
goto P_0c038efc;
P_0c038efc: /* original e06c, guest PC 0x0c038efc */
if(!s->budget--) { s->failed_pc=0x0c038efcu; return 0; }
r[0]=0x0000006cu;
goto P_0c038efe;
P_0c038efe: /* original 0e46, guest PC 0x0c038efe */
if(!s->budget--) { s->failed_pc=0x0c038efeu; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c038f00;
P_0c038f00: /* original e064, guest PC 0x0c038f00 */
if(!s->budget--) { s->failed_pc=0x0c038f00u; return 0; }
r[0]=0x00000064u;
goto P_0c038f02;
P_0c038f02: /* original 0e46, guest PC 0x0c038f02 */
if(!s->budget--) { s->failed_pc=0x0c038f02u; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c038f04;
P_0c038f04: /* original e068, guest PC 0x0c038f04 */
if(!s->budget--) { s->failed_pc=0x0c038f04u; return 0; }
r[0]=0x00000068u;
goto P_0c038f06;
P_0c038f06: /* original 0e46, guest PC 0x0c038f06 */
if(!s->budget--) { s->failed_pc=0x0c038f06u; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c038f08;
P_0c038f08: /* original e070, guest PC 0x0c038f08 */
if(!s->budget--) { s->failed_pc=0x0c038f08u; return 0; }
r[0]=0x00000070u;
goto P_0c038f0a;
P_0c038f0a: /* original f49d, guest PC 0x0c038f0a */
if(!s->budget--) { s->failed_pc=0x0c038f0au; return 0; }
fr[4]=0x3f800000u;
goto P_0c038f0c;
P_0c038f0c: /* original fe47, guest PC 0x0c038f0c */
if(!s->budget--) { s->failed_pc=0x0c038f0cu; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c038f0e;
P_0c038f0e: /* original e074, guest PC 0x0c038f0e */
if(!s->budget--) { s->failed_pc=0x0c038f0eu; return 0; }
r[0]=0x00000074u;
goto P_0c038f10;
P_0c038f10: /* original fe47, guest PC 0x0c038f10 */
if(!s->budget--) { s->failed_pc=0x0c038f10u; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c038f12;
P_0c038f12: /* original e078, guest PC 0x0c038f12 */
if(!s->budget--) { s->failed_pc=0x0c038f12u; return 0; }
r[0]=0x00000078u;
goto P_0c038f14;
P_0c038f14: /* original fe47, guest PC 0x0c038f14 */
if(!s->budget--) { s->failed_pc=0x0c038f14u; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c038f16;
P_0c038f16: /* original e07c, guest PC 0x0c038f16 */
if(!s->budget--) { s->failed_pc=0x0c038f16u; return 0; }
r[0]=0x0000007cu;
goto P_0c038f18;
P_0c038f18: /* original fe47, guest PC 0x0c038f18 */
if(!s->budget--) { s->failed_pc=0x0c038f18u; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c038f1a;
P_0c038f1a: /* original 7004, guest PC 0x0c038f1a */
if(!s->budget--) { s->failed_pc=0x0c038f1au; return 0; }
r[0]+=0x00000004u;
goto P_0c038f1c;
P_0c038f1c: /* original fe47, guest PC 0x0c038f1c */
if(!s->budget--) { s->failed_pc=0x0c038f1cu; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c038f1e;
P_0c038f1e: /* original 7004, guest PC 0x0c038f1e */
if(!s->budget--) { s->failed_pc=0x0c038f1eu; return 0; }
r[0]+=0x00000004u;
goto P_0c038f20;
P_0c038f20: /* original fe47, guest PC 0x0c038f20 */
if(!s->budget--) { s->failed_pc=0x0c038f20u; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c038f22;
P_0c038f22: /* original 7004, guest PC 0x0c038f22 */
if(!s->budget--) { s->failed_pc=0x0c038f22u; return 0; }
r[0]+=0x00000004u;
goto P_0c038f24;
P_0c038f24: /* original fe47, guest PC 0x0c038f24 */
if(!s->budget--) { s->failed_pc=0x0c038f24u; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c038f26;
P_0c038f26: /* original 7004, guest PC 0x0c038f26 */
if(!s->budget--) { s->failed_pc=0x0c038f26u; return 0; }
r[0]+=0x00000004u;
goto P_0c038f28;
P_0c038f28: /* original fe47, guest PC 0x0c038f28 */
if(!s->budget--) { s->failed_pc=0x0c038f28u; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c038f2a;
P_0c038f2a: /* original d378, guest PC 0x0c038f2a */
if(!s->budget--) { s->failed_pc=0x0c038f2au; return 0; }
r[3]=read(ram,0x0c03910cu,4);
goto P_0c038f2c;
P_0c038f2c: /* original 430b, guest PC 0x0c038f2c */
if(!s->budget--) { s->failed_pc=0x0c038f2cu; return 0; }
target=r[3];
r[16]=0x0c038f30u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c038f30u) { target=s->pc; goto dispatch; }
goto P_0c038f30;
P_0c038f2e: /* original 64e3, guest PC 0x0c038f2e */
if(!s->budget--) { s->failed_pc=0x0c038f2eu; return 0; }
r[4]=r[14];
goto P_0c038f30;
P_0c038f30: /* original 4f26, guest PC 0x0c038f30 */
if(!s->budget--) { s->failed_pc=0x0c038f30u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c038f32;
P_0c038f32: /* original d277, guest PC 0x0c038f32 */
if(!s->budget--) { s->failed_pc=0x0c038f32u; return 0; }
r[2]=read(ram,0x0c039110u,4);
goto P_0c038f34;
P_0c038f34: /* original 64e3, guest PC 0x0c038f34 */
if(!s->budget--) { s->failed_pc=0x0c038f34u; return 0; }
r[4]=r[14];
goto P_0c038f36;
P_0c038f36: /* original 422b, guest PC 0x0c038f36 */
if(!s->budget--) { s->failed_pc=0x0c038f36u; return 0; }
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
P_0c038f38: /* original 6ef6, guest PC 0x0c038f38 */
if(!s->budget--) { s->failed_pc=0x0c038f38u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c038f3au,s,ram);
P_0c038f4e: /* original 4f22, guest PC 0x0c038f4e */
if(!s->budget--) { s->failed_pc=0x0c038f4eu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c038f50;
P_0c038f50: /* original e20b, guest PC 0x0c038f50 */
if(!s->budget--) { s->failed_pc=0x0c038f50u; return 0; }
r[2]=0x0000000bu;
goto P_0c038f52;
P_0c038f52: /* original 1e41, guest PC 0x0c038f52 */
if(!s->budget--) { s->failed_pc=0x0c038f52u; return 0; }
write(ram,r[14]+4,r[4],4);
goto P_0c038f54;
P_0c038f54: /* original e501, guest PC 0x0c038f54 */
if(!s->budget--) { s->failed_pc=0x0c038f54u; return 0; }
r[5]=0x00000001u;
goto P_0c038f56;
P_0c038f56: /* original 1e42, guest PC 0x0c038f56 */
if(!s->budget--) { s->failed_pc=0x0c038f56u; return 0; }
write(ram,r[14]+8,r[4],4);
goto P_0c038f58;
P_0c038f58: /* original e604, guest PC 0x0c038f58 */
if(!s->budget--) { s->failed_pc=0x0c038f58u; return 0; }
r[6]=0x00000004u;
goto P_0c038f5a;
P_0c038f5a: /* original 1e43, guest PC 0x0c038f5a */
if(!s->budget--) { s->failed_pc=0x0c038f5au; return 0; }
write(ram,r[14]+12,r[4],4);
goto P_0c038f5c;
P_0c038f5c: /* original 0e46, guest PC 0x0c038f5c */
if(!s->budget--) { s->failed_pc=0x0c038f5cu; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c038f5e;
P_0c038f5e: /* original 1e44, guest PC 0x0c038f5e */
if(!s->budget--) { s->failed_pc=0x0c038f5eu; return 0; }
write(ram,r[14]+16,r[4],4);
goto P_0c038f60;
P_0c038f60: /* original 1e65, guest PC 0x0c038f60 */
if(!s->budget--) { s->failed_pc=0x0c038f60u; return 0; }
write(ram,r[14]+20,r[6],4);
goto P_0c038f62;
P_0c038f62: /* original 1e46, guest PC 0x0c038f62 */
if(!s->budget--) { s->failed_pc=0x0c038f62u; return 0; }
write(ram,r[14]+24,r[4],4);
goto P_0c038f64;
P_0c038f64: /* original 1e47, guest PC 0x0c038f64 */
if(!s->budget--) { s->failed_pc=0x0c038f64u; return 0; }
write(ram,r[14]+28,r[4],4);
goto P_0c038f66;
P_0c038f66: /* original 1e58, guest PC 0x0c038f66 */
if(!s->budget--) { s->failed_pc=0x0c038f66u; return 0; }
write(ram,r[14]+32,r[5],4);
goto P_0c038f68;
P_0c038f68: /* original 1e49, guest PC 0x0c038f68 */
if(!s->budget--) { s->failed_pc=0x0c038f68u; return 0; }
write(ram,r[14]+36,r[4],4);
goto P_0c038f6a;
P_0c038f6a: /* original 1e4a, guest PC 0x0c038f6a */
if(!s->budget--) { s->failed_pc=0x0c038f6au; return 0; }
write(ram,r[14]+40,r[4],4);
goto P_0c038f6c;
P_0c038f6c: /* original 1e3b, guest PC 0x0c038f6c */
if(!s->budget--) { s->failed_pc=0x0c038f6cu; return 0; }
write(ram,r[14]+44,r[3],4);
goto P_0c038f6e;
P_0c038f6e: /* original e302, guest PC 0x0c038f6e */
if(!s->budget--) { s->failed_pc=0x0c038f6eu; return 0; }
r[3]=0x00000002u;
goto P_0c038f70;
P_0c038f70: /* original 1e2c, guest PC 0x0c038f70 */
if(!s->budget--) { s->failed_pc=0x0c038f70u; return 0; }
write(ram,r[14]+48,r[2],4);
goto P_0c038f72;
P_0c038f72: /* original 1e4d, guest PC 0x0c038f72 */
if(!s->budget--) { s->failed_pc=0x0c038f72u; return 0; }
write(ram,r[14]+52,r[4],4);
goto P_0c038f74;
P_0c038f74: /* original 1e4e, guest PC 0x0c038f74 */
if(!s->budget--) { s->failed_pc=0x0c038f74u; return 0; }
write(ram,r[14]+56,r[4],4);
goto P_0c038f76;
P_0c038f76: /* original 1e3f, guest PC 0x0c038f76 */
if(!s->budget--) { s->failed_pc=0x0c038f76u; return 0; }
write(ram,r[14]+60,r[3],4);
goto P_0c038f78;
P_0c038f78: /* original 0e46, guest PC 0x0c038f78 */
if(!s->budget--) { s->failed_pc=0x0c038f78u; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c038f7a;
P_0c038f7a: /* original e044, guest PC 0x0c038f7a */
if(!s->budget--) { s->failed_pc=0x0c038f7au; return 0; }
r[0]=0x00000044u;
goto P_0c038f7c;
P_0c038f7c: /* original 0e46, guest PC 0x0c038f7c */
if(!s->budget--) { s->failed_pc=0x0c038f7cu; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c038f7e;
P_0c038f7e: /* original e048, guest PC 0x0c038f7e */
if(!s->budget--) { s->failed_pc=0x0c038f7eu; return 0; }
r[0]=0x00000048u;
goto P_0c038f80;
P_0c038f80: /* original 0e56, guest PC 0x0c038f80 */
if(!s->budget--) { s->failed_pc=0x0c038f80u; return 0; }
write(ram,r[14]+r[0],r[5],4);
goto P_0c038f82;
P_0c038f82: /* original e04c, guest PC 0x0c038f82 */
if(!s->budget--) { s->failed_pc=0x0c038f82u; return 0; }
r[0]=0x0000004cu;
goto P_0c038f84;
P_0c038f84: /* original 0e46, guest PC 0x0c038f84 */
if(!s->budget--) { s->failed_pc=0x0c038f84u; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c038f86;
P_0c038f86: /* original e050, guest PC 0x0c038f86 */
if(!s->budget--) { s->failed_pc=0x0c038f86u; return 0; }
r[0]=0x00000050u;
goto P_0c038f88;
P_0c038f88: /* original 0e46, guest PC 0x0c038f88 */
if(!s->budget--) { s->failed_pc=0x0c038f88u; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c038f8a;
P_0c038f8a: /* original e054, guest PC 0x0c038f8a */
if(!s->budget--) { s->failed_pc=0x0c038f8au; return 0; }
r[0]=0x00000054u;
goto P_0c038f8c;
P_0c038f8c: /* original 0e46, guest PC 0x0c038f8c */
if(!s->budget--) { s->failed_pc=0x0c038f8cu; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c038f8e;
P_0c038f8e: /* original e058, guest PC 0x0c038f8e */
if(!s->budget--) { s->failed_pc=0x0c038f8eu; return 0; }
r[0]=0x00000058u;
goto P_0c038f90;
P_0c038f90: /* original 0e46, guest PC 0x0c038f90 */
if(!s->budget--) { s->failed_pc=0x0c038f90u; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c038f92;
P_0c038f92: /* original e05c, guest PC 0x0c038f92 */
if(!s->budget--) { s->failed_pc=0x0c038f92u; return 0; }
r[0]=0x0000005cu;
goto P_0c038f94;
P_0c038f94: /* original 0e66, guest PC 0x0c038f94 */
if(!s->budget--) { s->failed_pc=0x0c038f94u; return 0; }
write(ram,r[14]+r[0],r[6],4);
goto P_0c038f96;
P_0c038f96: /* original e060, guest PC 0x0c038f96 */
if(!s->budget--) { s->failed_pc=0x0c038f96u; return 0; }
r[0]=0x00000060u;
goto P_0c038f98;
P_0c038f98: /* original 0e56, guest PC 0x0c038f98 */
if(!s->budget--) { s->failed_pc=0x0c038f98u; return 0; }
write(ram,r[14]+r[0],r[5],4);
goto P_0c038f9a;
P_0c038f9a: /* original e06c, guest PC 0x0c038f9a */
if(!s->budget--) { s->failed_pc=0x0c038f9au; return 0; }
r[0]=0x0000006cu;
goto P_0c038f9c;
P_0c038f9c: /* original 0e46, guest PC 0x0c038f9c */
if(!s->budget--) { s->failed_pc=0x0c038f9cu; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c038f9e;
P_0c038f9e: /* original e064, guest PC 0x0c038f9e */
if(!s->budget--) { s->failed_pc=0x0c038f9eu; return 0; }
r[0]=0x00000064u;
goto P_0c038fa0;
P_0c038fa0: /* original 0e46, guest PC 0x0c038fa0 */
if(!s->budget--) { s->failed_pc=0x0c038fa0u; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c038fa2;
P_0c038fa2: /* original e068, guest PC 0x0c038fa2 */
if(!s->budget--) { s->failed_pc=0x0c038fa2u; return 0; }
r[0]=0x00000068u;
goto P_0c038fa4;
P_0c038fa4: /* original 0e46, guest PC 0x0c038fa4 */
if(!s->budget--) { s->failed_pc=0x0c038fa4u; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c038fa6;
P_0c038fa6: /* original e070, guest PC 0x0c038fa6 */
if(!s->budget--) { s->failed_pc=0x0c038fa6u; return 0; }
r[0]=0x00000070u;
goto P_0c038fa8;
P_0c038fa8: /* original f49d, guest PC 0x0c038fa8 */
if(!s->budget--) { s->failed_pc=0x0c038fa8u; return 0; }
fr[4]=0x3f800000u;
goto P_0c038faa;
P_0c038faa: /* original fe47, guest PC 0x0c038faa */
if(!s->budget--) { s->failed_pc=0x0c038faau; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c038fac;
P_0c038fac: /* original e074, guest PC 0x0c038fac */
if(!s->budget--) { s->failed_pc=0x0c038facu; return 0; }
r[0]=0x00000074u;
goto P_0c038fae;
P_0c038fae: /* original fe47, guest PC 0x0c038fae */
if(!s->budget--) { s->failed_pc=0x0c038faeu; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c038fb0;
P_0c038fb0: /* original e078, guest PC 0x0c038fb0 */
if(!s->budget--) { s->failed_pc=0x0c038fb0u; return 0; }
r[0]=0x00000078u;
goto P_0c038fb2;
P_0c038fb2: /* original fe47, guest PC 0x0c038fb2 */
if(!s->budget--) { s->failed_pc=0x0c038fb2u; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c038fb4;
P_0c038fb4: /* original e07c, guest PC 0x0c038fb4 */
if(!s->budget--) { s->failed_pc=0x0c038fb4u; return 0; }
r[0]=0x0000007cu;
goto P_0c038fb6;
P_0c038fb6: /* original fe47, guest PC 0x0c038fb6 */
if(!s->budget--) { s->failed_pc=0x0c038fb6u; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c038fb8;
P_0c038fb8: /* original 7004, guest PC 0x0c038fb8 */
if(!s->budget--) { s->failed_pc=0x0c038fb8u; return 0; }
r[0]+=0x00000004u;
goto P_0c038fba;
P_0c038fba: /* original fe47, guest PC 0x0c038fba */
if(!s->budget--) { s->failed_pc=0x0c038fbau; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c038fbc;
P_0c038fbc: /* original 7004, guest PC 0x0c038fbc */
if(!s->budget--) { s->failed_pc=0x0c038fbcu; return 0; }
r[0]+=0x00000004u;
goto P_0c038fbe;
P_0c038fbe: /* original fe47, guest PC 0x0c038fbe */
if(!s->budget--) { s->failed_pc=0x0c038fbeu; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c038fc0;
P_0c038fc0: /* original 7004, guest PC 0x0c038fc0 */
if(!s->budget--) { s->failed_pc=0x0c038fc0u; return 0; }
r[0]+=0x00000004u;
goto P_0c038fc2;
P_0c038fc2: /* original fe47, guest PC 0x0c038fc2 */
if(!s->budget--) { s->failed_pc=0x0c038fc2u; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c038fc4;
P_0c038fc4: /* original 7004, guest PC 0x0c038fc4 */
if(!s->budget--) { s->failed_pc=0x0c038fc4u; return 0; }
r[0]+=0x00000004u;
goto P_0c038fc6;
P_0c038fc6: /* original fe47, guest PC 0x0c038fc6 */
if(!s->budget--) { s->failed_pc=0x0c038fc6u; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c038fc8;
P_0c038fc8: /* original d350, guest PC 0x0c038fc8 */
if(!s->budget--) { s->failed_pc=0x0c038fc8u; return 0; }
r[3]=read(ram,0x0c03910cu,4);
goto P_0c038fca;
P_0c038fca: /* original 430b, guest PC 0x0c038fca */
if(!s->budget--) { s->failed_pc=0x0c038fcau; return 0; }
target=r[3];
r[16]=0x0c038fceu;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c038fceu) { target=s->pc; goto dispatch; }
goto P_0c038fce;
P_0c038fcc: /* original 64e3, guest PC 0x0c038fcc */
if(!s->budget--) { s->failed_pc=0x0c038fccu; return 0; }
r[4]=r[14];
goto P_0c038fce;
P_0c038fce: /* original 4f26, guest PC 0x0c038fce */
if(!s->budget--) { s->failed_pc=0x0c038fceu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c038fd0;
P_0c038fd0: /* original d250, guest PC 0x0c038fd0 */
if(!s->budget--) { s->failed_pc=0x0c038fd0u; return 0; }
r[2]=read(ram,0x0c039114u,4);
goto P_0c038fd2;
P_0c038fd2: /* original 64e3, guest PC 0x0c038fd2 */
if(!s->budget--) { s->failed_pc=0x0c038fd2u; return 0; }
r[4]=r[14];
goto P_0c038fd4;
P_0c038fd4: /* original 422b, guest PC 0x0c038fd4 */
if(!s->budget--) { s->failed_pc=0x0c038fd4u; return 0; }
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
P_0c038fd6: /* original 6ef6, guest PC 0x0c038fd6 */
if(!s->budget--) { s->failed_pc=0x0c038fd6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c038fd8u,s,ram);
P_0c03a370: /* original f38d, guest PC 0x0c03a370 */
if(!s->budget--) { s->failed_pc=0x0c03a370u; return 0; }
fr[3]=0;
goto P_0c03a372;
P_0c03a372: /* original f434, guest PC 0x0c03a372 */
if(!s->budget--) { s->failed_pc=0x0c03a372u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[4])==as_float(fr[3]))!=0);
goto P_0c03a374;
P_0c03a374: /* original 8b04, guest PC 0x0c03a374 */
if(!s->budget--) { s->failed_pc=0x0c03a374u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c03a380; }
goto P_0c03a376;
P_0c03a376: /* original c71d, guest PC 0x0c03a376 */
if(!s->budget--) { s->failed_pc=0x0c03a376u; return 0; }
r[0]=0x0c03a3ecu;
goto P_0c03a378;
P_0c03a378: /* original 000b, guest PC 0x0c03a378 */
if(!s->budget--) { s->failed_pc=0x0c03a378u; return 0; }
target=r[16];
vf3_matrix_load(s,ram,0,r[0]);
s->pc=target; return ram->oob==0;
P_0c03a37a: /* original f008, guest PC 0x0c03a37a */
if(!s->budget--) { s->failed_pc=0x0c03a37au; return 0; }
vf3_matrix_load(s,ram,0,r[0]);
return vf3_matrix_family(0x0c03a37cu,s,ram);
P_0c03a380: /* original f46d, guest PC 0x0c03a380 */
if(!s->budget--) { s->failed_pc=0x0c03a380u; return 0; }
fr[4]=vf3_fpu_sqrt(fr[4],r[18]);
goto P_0c03a382;
P_0c03a382: /* original f09d, guest PC 0x0c03a382 */
if(!s->budget--) { s->failed_pc=0x0c03a382u; return 0; }
fr[0]=0x3f800000u;
goto P_0c03a384;
P_0c03a384: /* original f043, guest PC 0x0c03a384 */
if(!s->budget--) { s->failed_pc=0x0c03a384u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[4],r[18],'/');
goto P_0c03a386;
P_0c03a386: /* original 000b, guest PC 0x0c03a386 */
if(!s->budget--) { s->failed_pc=0x0c03a386u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c03a388: /* original 0009, guest PC 0x0c03a388 */
if(!s->budget--) { s->failed_pc=0x0c03a388u; return 0; }
return vf3_matrix_family(0x0c03a38au,s,ram);
P_0c03bb40: /* original 4f22, guest PC 0x0c03bb40 */
if(!s->budget--) { s->failed_pc=0x0c03bb40u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c03bb42;
P_0c03bb42: /* original 7ff0, guest PC 0x0c03bb42 */
if(!s->budget--) { s->failed_pc=0x0c03bb42u; return 0; }
r[15]+=0xfffffff0u;
goto P_0c03bb44;
P_0c03bb44: /* original 8d03, guest PC 0x0c03bb44 */
if(!s->budget--) { s->failed_pc=0x0c03bb44u; return 0; }
cond=r[17]&1u;
r[12]=r[5];
if(cond) { goto P_0c03bb4e; }
goto P_0c03bb48;
P_0c03bb46: /* original 6c53, guest PC 0x0c03bb46 */
if(!s->budget--) { s->failed_pc=0x0c03bb46u; return 0; }
r[12]=r[5];
goto P_0c03bb48;
P_0c03bb48: /* original d290, guest PC 0x0c03bb48 */
if(!s->budget--) { s->failed_pc=0x0c03bb48u; return 0; }
r[2]=read(ram,0x0c03bd8cu,4);
goto P_0c03bb4a;
P_0c03bb4a: /* original 420b, guest PC 0x0c03bb4a */
if(!s->budget--) { s->failed_pc=0x0c03bb4au; return 0; }
target=r[2];
r[16]=0x0c03bb4eu;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c03bb4eu) { target=s->pc; goto dispatch; }
goto P_0c03bb4e;
P_0c03bb4c: /* original 64e3, guest PC 0x0c03bb4c */
if(!s->budget--) { s->failed_pc=0x0c03bb4cu; return 0; }
r[4]=r[14];
goto P_0c03bb4e;
P_0c03bb4e: /* original f3d8, guest PC 0x0c03bb4e */
if(!s->budget--) { s->failed_pc=0x0c03bb4eu; return 0; }
vf3_matrix_load(s,ram,3,r[13]);
goto P_0c03bb50;
P_0c03bb50: /* original 6ef3, guest PC 0x0c03bb50 */
if(!s->budget--) { s->failed_pc=0x0c03bb50u; return 0; }
r[14]=r[15];
goto P_0c03bb52;
P_0c03bb52: /* original f2c8, guest PC 0x0c03bb52 */
if(!s->budget--) { s->failed_pc=0x0c03bb52u; return 0; }
vf3_matrix_load(s,ram,2,r[12]);
goto P_0c03bb54;
P_0c03bb54: /* original 7e04, guest PC 0x0c03bb54 */
if(!s->budget--) { s->failed_pc=0x0c03bb54u; return 0; }
r[14]+=0x00000004u;
goto P_0c03bb56;
P_0c03bb56: /* original e004, guest PC 0x0c03bb56 */
if(!s->budget--) { s->failed_pc=0x0c03bb56u; return 0; }
r[0]=0x00000004u;
goto P_0c03bb58;
P_0c03bb58: /* original f231, guest PC 0x0c03bb58 */
if(!s->budget--) { s->failed_pc=0x0c03bb58u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'-');
goto P_0c03bb5a;
P_0c03bb5a: /* original fe2a, guest PC 0x0c03bb5a */
if(!s->budget--) { s->failed_pc=0x0c03bb5au; return 0; }
vf3_matrix_store(s,ram,2,r[14]);
goto P_0c03bb5c;
P_0c03bb5c: /* original f2c6, guest PC 0x0c03bb5c */
if(!s->budget--) { s->failed_pc=0x0c03bb5cu; return 0; }
vf3_matrix_load(s,ram,2,r[12]+r[0]);
goto P_0c03bb5e;
P_0c03bb5e: /* original f3d6, guest PC 0x0c03bb5e */
if(!s->budget--) { s->failed_pc=0x0c03bb5eu; return 0; }
vf3_matrix_load(s,ram,3,r[13]+r[0]);
goto P_0c03bb60;
P_0c03bb60: /* original f231, guest PC 0x0c03bb60 */
if(!s->budget--) { s->failed_pc=0x0c03bb60u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'-');
goto P_0c03bb62;
P_0c03bb62: /* original fe27, guest PC 0x0c03bb62 */
if(!s->budget--) { s->failed_pc=0x0c03bb62u; return 0; }
vf3_matrix_store(s,ram,2,r[14]+r[0]);
goto P_0c03bb64;
P_0c03bb64: /* original e008, guest PC 0x0c03bb64 */
if(!s->budget--) { s->failed_pc=0x0c03bb64u; return 0; }
r[0]=0x00000008u;
goto P_0c03bb66;
P_0c03bb66: /* original f2c6, guest PC 0x0c03bb66 */
if(!s->budget--) { s->failed_pc=0x0c03bb66u; return 0; }
vf3_matrix_load(s,ram,2,r[12]+r[0]);
goto P_0c03bb68;
P_0c03bb68: /* original f3d6, guest PC 0x0c03bb68 */
if(!s->budget--) { s->failed_pc=0x0c03bb68u; return 0; }
vf3_matrix_load(s,ram,3,r[13]+r[0]);
goto P_0c03bb6a;
P_0c03bb6a: /* original f231, guest PC 0x0c03bb6a */
if(!s->budget--) { s->failed_pc=0x0c03bb6au; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'-');
goto P_0c03bb6c;
P_0c03bb6c: /* original fe27, guest PC 0x0c03bb6c */
if(!s->budget--) { s->failed_pc=0x0c03bb6cu; return 0; }
vf3_matrix_store(s,ram,2,r[14]+r[0]);
goto P_0c03bb6e;
P_0c03bb6e: /* original f42c, guest PC 0x0c03bb6e */
if(!s->budget--) { s->failed_pc=0x0c03bb6eu; return 0; }
vf3_matrix_move(s,4,2);
goto P_0c03bb70;
P_0c03bb70: /* original f32c, guest PC 0x0c03bb70 */
if(!s->budget--) { s->failed_pc=0x0c03bb70u; return 0; }
vf3_matrix_move(s,3,2);
goto P_0c03bb72;
P_0c03bb72: /* original f342, guest PC 0x0c03bb72 */
if(!s->budget--) { s->failed_pc=0x0c03bb72u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'*');
goto P_0c03bb74;
P_0c03bb74: /* original f5e8, guest PC 0x0c03bb74 */
if(!s->budget--) { s->failed_pc=0x0c03bb74u; return 0; }
vf3_matrix_load(s,ram,5,r[14]);
goto P_0c03bb76;
P_0c03bb76: /* original d386, guest PC 0x0c03bb76 */
if(!s->budget--) { s->failed_pc=0x0c03bb76u; return 0; }
r[3]=read(ram,0x0c03bd90u,4);
goto P_0c03bb78;
P_0c03bb78: /* original f05c, guest PC 0x0c03bb78 */
if(!s->budget--) { s->failed_pc=0x0c03bb78u; return 0; }
vf3_matrix_move(s,0,5);
goto P_0c03bb7a;
P_0c03bb7a: /* original f35e, guest PC 0x0c03bb7a */
if(!s->budget--) { s->failed_pc=0x0c03bb7au; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[5],fr[3],r[18]);
goto P_0c03bb7c;
P_0c03bb7c: /* original fe3c, guest PC 0x0c03bb7c */
if(!s->budget--) { s->failed_pc=0x0c03bb7cu; return 0; }
vf3_matrix_move(s,14,3);
goto P_0c03bb7e;
P_0c03bb7e: /* original 430b, guest PC 0x0c03bb7e */
if(!s->budget--) { s->failed_pc=0x0c03bb7eu; return 0; }
target=r[3];
r[16]=0x0c03bb82u;
vf3_matrix_move(s,4,3);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c03bb82u) { target=s->pc; goto dispatch; }
goto P_0c03bb82;
P_0c03bb80: /* original f43c, guest PC 0x0c03bb80 */
if(!s->budget--) { s->failed_pc=0x0c03bb80u; return 0; }
vf3_matrix_move(s,4,3);
goto P_0c03bb82;
P_0c03bb82: /* original e004, guest PC 0x0c03bb82 */
if(!s->budget--) { s->failed_pc=0x0c03bb82u; return 0; }
r[0]=0x00000004u;
goto P_0c03bb84;
P_0c03bb84: /* original ff0c, guest PC 0x0c03bb84 */
if(!s->budget--) { s->failed_pc=0x0c03bb84u; return 0; }
vf3_matrix_move(s,15,0);
goto P_0c03bb86;
P_0c03bb86: /* original f0e6, guest PC 0x0c03bb86 */
if(!s->budget--) { s->failed_pc=0x0c03bb86u; return 0; }
vf3_matrix_load(s,ram,0,r[14]+r[0]);
goto P_0c03bb88;
P_0c03bb88: /* original ff0a, guest PC 0x0c03bb88 */
if(!s->budget--) { s->failed_pc=0x0c03bb88u; return 0; }
vf3_matrix_store(s,ram,0,r[15]);
goto P_0c03bb8a;
P_0c03bb8a: /* original f30c, guest PC 0x0c03bb8a */
if(!s->budget--) { s->failed_pc=0x0c03bb8au; return 0; }
vf3_matrix_move(s,3,0);
goto P_0c03bb8c;
P_0c03bb8c: /* original fe3e, guest PC 0x0c03bb8c */
if(!s->budget--) { s->failed_pc=0x0c03bb8cu; return 0; }
fr[14]=vf3_fpu_mac(fr[0],fr[3],fr[14],r[18]);
goto P_0c03bb8e;
P_0c03bb8e: /* original d380, guest PC 0x0c03bb8e */
if(!s->budget--) { s->failed_pc=0x0c03bb8eu; return 0; }
r[3]=read(ram,0x0c03bd90u,4);
goto P_0c03bb90;
P_0c03bb90: /* original 430b, guest PC 0x0c03bb90 */
if(!s->budget--) { s->failed_pc=0x0c03bb90u; return 0; }
target=r[3];
r[16]=0x0c03bb94u;
vf3_matrix_move(s,4,14);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c03bb94u) { target=s->pc; goto dispatch; }
goto P_0c03bb94;
P_0c03bb92: /* original f4ec, guest PC 0x0c03bb92 */
if(!s->budget--) { s->failed_pc=0x0c03bb92u; return 0; }
vf3_matrix_move(s,4,14);
goto P_0c03bb94;
P_0c03bb94: /* original f50c, guest PC 0x0c03bb94 */
if(!s->budget--) { s->failed_pc=0x0c03bb94u; return 0; }
vf3_matrix_move(s,5,0);
goto P_0c03bb96;
P_0c03bb96: /* original f5f3, guest PC 0x0c03bb96 */
if(!s->budget--) { s->failed_pc=0x0c03bb96u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[15],r[18],'/');
goto P_0c03bb98;
P_0c03bb98: /* original e004, guest PC 0x0c03bb98 */
if(!s->budget--) { s->failed_pc=0x0c03bb98u; return 0; }
r[0]=0x00000004u;
goto P_0c03bb9a;
P_0c03bb9a: /* original fe0c, guest PC 0x0c03bb9a */
if(!s->budget--) { s->failed_pc=0x0c03bb9au; return 0; }
vf3_matrix_move(s,14,0);
goto P_0c03bb9c;
P_0c03bb9c: /* original f3e6, guest PC 0x0c03bb9c */
if(!s->budget--) { s->failed_pc=0x0c03bb9cu; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c03bb9e;
P_0c03bb9e: /* original d37d, guest PC 0x0c03bb9e */
if(!s->budget--) { s->failed_pc=0x0c03bb9eu; return 0; }
r[3]=read(ram,0x0c03bd94u,4);
goto P_0c03bba0;
P_0c03bba0: /* original f3e2, guest PC 0x0c03bba0 */
if(!s->budget--) { s->failed_pc=0x0c03bba0u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[14],r[18],'*');
goto P_0c03bba2;
P_0c03bba2: /* original f43c, guest PC 0x0c03bba2 */
if(!s->budget--) { s->failed_pc=0x0c03bba2u; return 0; }
vf3_matrix_move(s,4,3);
goto P_0c03bba4;
P_0c03bba4: /* original 430b, guest PC 0x0c03bba4 */
if(!s->budget--) { s->failed_pc=0x0c03bba4u; return 0; }
target=r[3];
r[16]=0x0c03bba8u;
fr[4]^=0x80000000u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c03bba8u) { target=s->pc; goto dispatch; }
goto P_0c03bba8;
P_0c03bba6: /* original f44d, guest PC 0x0c03bba6 */
if(!s->budget--) { s->failed_pc=0x0c03bba6u; return 0; }
fr[4]^=0x80000000u;
goto P_0c03bba8;
P_0c03bba8: /* original e008, guest PC 0x0c03bba8 */
if(!s->budget--) { s->failed_pc=0x0c03bba8u; return 0; }
r[0]=0x00000008u;
goto P_0c03bbaa;
P_0c03bbaa: /* original f4e8, guest PC 0x0c03bbaa */
if(!s->budget--) { s->failed_pc=0x0c03bbaau; return 0; }
vf3_matrix_load(s,ram,4,r[14]);
goto P_0c03bbac;
P_0c03bbac: /* original f3e6, guest PC 0x0c03bbac */
if(!s->budget--) { s->failed_pc=0x0c03bbacu; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c03bbae;
P_0c03bbae: /* original d37a, guest PC 0x0c03bbae */
if(!s->budget--) { s->failed_pc=0x0c03bbaeu; return 0; }
r[3]=read(ram,0x0c03bd98u,4);
goto P_0c03bbb0;
P_0c03bbb0: /* original f3f2, guest PC 0x0c03bbb0 */
if(!s->budget--) { s->failed_pc=0x0c03bbb0u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[15],r[18],'*');
goto P_0c03bbb2;
P_0c03bbb2: /* original f53c, guest PC 0x0c03bbb2 */
if(!s->budget--) { s->failed_pc=0x0c03bbb2u; return 0; }
vf3_matrix_move(s,5,3);
goto P_0c03bbb4;
P_0c03bbb4: /* original f54d, guest PC 0x0c03bbb4 */
if(!s->budget--) { s->failed_pc=0x0c03bbb4u; return 0; }
fr[5]^=0x80000000u;
goto P_0c03bbb6;
P_0c03bbb6: /* original 430b, guest PC 0x0c03bbb6 */
if(!s->budget--) { s->failed_pc=0x0c03bbb6u; return 0; }
target=r[3];
r[16]=0x0c03bbbau;
fr[4]=vf3_fpu_binary(fr[4],fr[15],r[18],'*');
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c03bbbau) { target=s->pc; goto dispatch; }
goto P_0c03bbba;
P_0c03bbb8: /* original f4f2, guest PC 0x0c03bbb8 */
if(!s->budget--) { s->failed_pc=0x0c03bbb8u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[15],r[18],'*');
goto P_0c03bbba;
P_0c03bbba: /* original d278, guest PC 0x0c03bbba */
if(!s->budget--) { s->failed_pc=0x0c03bbbau; return 0; }
r[2]=read(ram,0x0c03bd9cu,4);
goto P_0c03bbbc;
P_0c03bbbc: /* original 420b, guest PC 0x0c03bbbc */
if(!s->budget--) { s->failed_pc=0x0c03bbbcu; return 0; }
target=r[2];
r[16]=0x0c03bbc0u;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c03bbc0u) { target=s->pc; goto dispatch; }
goto P_0c03bbc0;
P_0c03bbbe: /* original 64d3, guest PC 0x0c03bbbe */
if(!s->budget--) { s->failed_pc=0x0c03bbbeu; return 0; }
r[4]=r[13];
goto P_0c03bbc0;
P_0c03bbc0: /* original 7f10, guest PC 0x0c03bbc0 */
if(!s->budget--) { s->failed_pc=0x0c03bbc0u; return 0; }
r[15]+=0x00000010u;
goto P_0c03bbc2;
P_0c03bbc2: /* original 4f26, guest PC 0x0c03bbc2 */
if(!s->budget--) { s->failed_pc=0x0c03bbc2u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c03bbc4;
P_0c03bbc4: /* original fef9, guest PC 0x0c03bbc4 */
if(!s->budget--) { s->failed_pc=0x0c03bbc4u; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c03bbc6;
P_0c03bbc6: /* original fff9, guest PC 0x0c03bbc6 */
if(!s->budget--) { s->failed_pc=0x0c03bbc6u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c03bbc8;
P_0c03bbc8: /* original 6cf6, guest PC 0x0c03bbc8 */
if(!s->budget--) { s->failed_pc=0x0c03bbc8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c03bbca;
P_0c03bbca: /* original 6df6, guest PC 0x0c03bbca */
if(!s->budget--) { s->failed_pc=0x0c03bbcau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c03bbcc;
P_0c03bbcc: /* original 000b, guest PC 0x0c03bbcc */
if(!s->budget--) { s->failed_pc=0x0c03bbccu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c03bbce: /* original 6ef6, guest PC 0x0c03bbce */
if(!s->budget--) { s->failed_pc=0x0c03bbceu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c03bbd0u,s,ram);
P_0c03bfb6: /* original 4f22, guest PC 0x0c03bfb6 */
if(!s->budget--) { s->failed_pc=0x0c03bfb6u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c03bfb8;
P_0c03bfb8: /* original f342, guest PC 0x0c03bfb8 */
if(!s->budget--) { s->failed_pc=0x0c03bfb8u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'*');
goto P_0c03bfba;
P_0c03bfba: /* original 7fc0, guest PC 0x0c03bfba */
if(!s->budget--) { s->failed_pc=0x0c03bfbau; return 0; }
r[15]+=0xffffffc0u;
goto P_0c03bfbc;
P_0c03bfbc: /* original f34d, guest PC 0x0c03bfbc */
if(!s->budget--) { s->failed_pc=0x0c03bfbcu; return 0; }
fr[3]^=0x80000000u;
goto P_0c03bfbe;
P_0c03bfbe: /* original f3f0, guest PC 0x0c03bfbe */
if(!s->budget--) { s->failed_pc=0x0c03bfbeu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[15],r[18],'+');
goto P_0c03bfc0;
P_0c03bfc0: /* original ff3a, guest PC 0x0c03bfc0 */
if(!s->budget--) { s->failed_pc=0x0c03bfc0u; return 0; }
vf3_matrix_store(s,ram,3,r[15]);
goto P_0c03bfc2;
P_0c03bfc2: /* original f5e6, guest PC 0x0c03bfc2 */
if(!s->budget--) { s->failed_pc=0x0c03bfc2u; return 0; }
vf3_matrix_load(s,ram,5,r[14]+r[0]);
goto P_0c03bfc4;
P_0c03bfc4: /* original e014, guest PC 0x0c03bfc4 */
if(!s->budget--) { s->failed_pc=0x0c03bfc4u; return 0; }
r[0]=0x00000014u;
goto P_0c03bfc6;
P_0c03bfc6: /* original f35c, guest PC 0x0c03bfc6 */
if(!s->budget--) { s->failed_pc=0x0c03bfc6u; return 0; }
vf3_matrix_move(s,3,5);
goto P_0c03bfc8;
P_0c03bfc8: /* original f352, guest PC 0x0c03bfc8 */
if(!s->budget--) { s->failed_pc=0x0c03bfc8u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[5],r[18],'*');
goto P_0c03bfca;
P_0c03bfca: /* original f342, guest PC 0x0c03bfca */
if(!s->budget--) { s->failed_pc=0x0c03bfcau; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'*');
goto P_0c03bfcc;
P_0c03bfcc: /* original f34d, guest PC 0x0c03bfcc */
if(!s->budget--) { s->failed_pc=0x0c03bfccu; return 0; }
fr[3]^=0x80000000u;
goto P_0c03bfce;
P_0c03bfce: /* original f3f0, guest PC 0x0c03bfce */
if(!s->budget--) { s->failed_pc=0x0c03bfceu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[15],r[18],'+');
goto P_0c03bfd0;
P_0c03bfd0: /* original ff37, guest PC 0x0c03bfd0 */
if(!s->budget--) { s->failed_pc=0x0c03bfd0u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c03bfd2;
P_0c03bfd2: /* original e014, guest PC 0x0c03bfd2 */
if(!s->budget--) { s->failed_pc=0x0c03bfd2u; return 0; }
r[0]=0x00000014u;
goto P_0c03bfd4;
P_0c03bfd4: /* original f5e6, guest PC 0x0c03bfd4 */
if(!s->budget--) { s->failed_pc=0x0c03bfd4u; return 0; }
vf3_matrix_load(s,ram,5,r[14]+r[0]);
goto P_0c03bfd6;
P_0c03bfd6: /* original f35c, guest PC 0x0c03bfd6 */
if(!s->budget--) { s->failed_pc=0x0c03bfd6u; return 0; }
vf3_matrix_move(s,3,5);
goto P_0c03bfd8;
P_0c03bfd8: /* original f352, guest PC 0x0c03bfd8 */
if(!s->budget--) { s->failed_pc=0x0c03bfd8u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[5],r[18],'*');
goto P_0c03bfda;
P_0c03bfda: /* original f342, guest PC 0x0c03bfda */
if(!s->budget--) { s->failed_pc=0x0c03bfdau; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'*');
goto P_0c03bfdc;
P_0c03bfdc: /* original f34d, guest PC 0x0c03bfdc */
if(!s->budget--) { s->failed_pc=0x0c03bfdcu; return 0; }
fr[3]^=0x80000000u;
goto P_0c03bfde;
P_0c03bfde: /* original f3f0, guest PC 0x0c03bfde */
if(!s->budget--) { s->failed_pc=0x0c03bfdeu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[15],r[18],'+');
goto P_0c03bfe0;
P_0c03bfe0: /* original e028, guest PC 0x0c03bfe0 */
if(!s->budget--) { s->failed_pc=0x0c03bfe0u; return 0; }
r[0]=0x00000028u;
goto P_0c03bfe2;
P_0c03bfe2: /* original 64f3, guest PC 0x0c03bfe2 */
if(!s->budget--) { s->failed_pc=0x0c03bfe2u; return 0; }
r[4]=r[15];
goto P_0c03bfe4;
P_0c03bfe4: /* original ff37, guest PC 0x0c03bfe4 */
if(!s->budget--) { s->failed_pc=0x0c03bfe4u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c03bfe6;
P_0c03bfe6: /* original e010, guest PC 0x0c03bfe6 */
if(!s->budget--) { s->failed_pc=0x0c03bfe6u; return 0; }
r[0]=0x00000010u;
goto P_0c03bfe8;
P_0c03bfe8: /* original f3e6, guest PC 0x0c03bfe8 */
if(!s->budget--) { s->failed_pc=0x0c03bfe8u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c03bfea;
P_0c03bfea: /* original e00c, guest PC 0x0c03bfea */
if(!s->budget--) { s->failed_pc=0x0c03bfeau; return 0; }
r[0]=0x0000000cu;
goto P_0c03bfec;
P_0c03bfec: /* original f2e6, guest PC 0x0c03bfec */
if(!s->budget--) { s->failed_pc=0x0c03bfecu; return 0; }
vf3_matrix_load(s,ram,2,r[14]+r[0]);
goto P_0c03bfee;
P_0c03bfee: /* original e010, guest PC 0x0c03bfee */
if(!s->budget--) { s->failed_pc=0x0c03bfeeu; return 0; }
r[0]=0x00000010u;
goto P_0c03bff0;
P_0c03bff0: /* original f232, guest PC 0x0c03bff0 */
if(!s->budget--) { s->failed_pc=0x0c03bff0u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c03bff2;
P_0c03bff2: /* original f242, guest PC 0x0c03bff2 */
if(!s->budget--) { s->failed_pc=0x0c03bff2u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[4],r[18],'*');
goto P_0c03bff4;
P_0c03bff4: /* original f24d, guest PC 0x0c03bff4 */
if(!s->budget--) { s->failed_pc=0x0c03bff4u; return 0; }
fr[2]^=0x80000000u;
goto P_0c03bff6;
P_0c03bff6: /* original f427, guest PC 0x0c03bff6 */
if(!s->budget--) { s->failed_pc=0x0c03bff6u; return 0; }
vf3_matrix_store(s,ram,2,r[4]+r[0]);
goto P_0c03bff8;
P_0c03bff8: /* original e004, guest PC 0x0c03bff8 */
if(!s->budget--) { s->failed_pc=0x0c03bff8u; return 0; }
r[0]=0x00000004u;
goto P_0c03bffa;
P_0c03bffa: /* original f427, guest PC 0x0c03bffa */
if(!s->budget--) { s->failed_pc=0x0c03bffau; return 0; }
vf3_matrix_store(s,ram,2,r[4]+r[0]);
goto P_0c03bffc;
P_0c03bffc: /* original e014, guest PC 0x0c03bffc */
if(!s->budget--) { s->failed_pc=0x0c03bffcu; return 0; }
r[0]=0x00000014u;
goto P_0c03bffe;
P_0c03bffe: /* original f3e6, guest PC 0x0c03bffe */
if(!s->budget--) { s->failed_pc=0x0c03bffeu; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c03c000;
P_0c03c000: /* original e00c, guest PC 0x0c03c000 */
if(!s->budget--) { s->failed_pc=0x0c03c000u; return 0; }
r[0]=0x0000000cu;
goto P_0c03c002;
P_0c03c002: /* original f2e6, guest PC 0x0c03c002 */
if(!s->budget--) { s->failed_pc=0x0c03c002u; return 0; }
vf3_matrix_load(s,ram,2,r[14]+r[0]);
goto P_0c03c004;
P_0c03c004: /* original e020, guest PC 0x0c03c004 */
if(!s->budget--) { s->failed_pc=0x0c03c004u; return 0; }
r[0]=0x00000020u;
goto P_0c03c006;
P_0c03c006: /* original 64f3, guest PC 0x0c03c006 */
if(!s->budget--) { s->failed_pc=0x0c03c006u; return 0; }
r[4]=r[15];
goto P_0c03c008;
P_0c03c008: /* original f232, guest PC 0x0c03c008 */
if(!s->budget--) { s->failed_pc=0x0c03c008u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c03c00a;
P_0c03c00a: /* original f242, guest PC 0x0c03c00a */
if(!s->budget--) { s->failed_pc=0x0c03c00au; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[4],r[18],'*');
goto P_0c03c00c;
P_0c03c00c: /* original f24d, guest PC 0x0c03c00c */
if(!s->budget--) { s->failed_pc=0x0c03c00cu; return 0; }
fr[2]^=0x80000000u;
goto P_0c03c00e;
P_0c03c00e: /* original f427, guest PC 0x0c03c00e */
if(!s->budget--) { s->failed_pc=0x0c03c00eu; return 0; }
vf3_matrix_store(s,ram,2,r[4]+r[0]);
goto P_0c03c010;
P_0c03c010: /* original e008, guest PC 0x0c03c010 */
if(!s->budget--) { s->failed_pc=0x0c03c010u; return 0; }
r[0]=0x00000008u;
goto P_0c03c012;
P_0c03c012: /* original f427, guest PC 0x0c03c012 */
if(!s->budget--) { s->failed_pc=0x0c03c012u; return 0; }
vf3_matrix_store(s,ram,2,r[4]+r[0]);
goto P_0c03c014;
P_0c03c014: /* original e014, guest PC 0x0c03c014 */
if(!s->budget--) { s->failed_pc=0x0c03c014u; return 0; }
r[0]=0x00000014u;
goto P_0c03c016;
P_0c03c016: /* original f3e6, guest PC 0x0c03c016 */
if(!s->budget--) { s->failed_pc=0x0c03c016u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c03c018;
P_0c03c018: /* original e010, guest PC 0x0c03c018 */
if(!s->budget--) { s->failed_pc=0x0c03c018u; return 0; }
r[0]=0x00000010u;
goto P_0c03c01a;
P_0c03c01a: /* original f2e6, guest PC 0x0c03c01a */
if(!s->budget--) { s->failed_pc=0x0c03c01au; return 0; }
vf3_matrix_load(s,ram,2,r[14]+r[0]);
goto P_0c03c01c;
P_0c03c01c: /* original 64f3, guest PC 0x0c03c01c */
if(!s->budget--) { s->failed_pc=0x0c03c01cu; return 0; }
r[4]=r[15];
goto P_0c03c01e;
P_0c03c01e: /* original f232, guest PC 0x0c03c01e */
if(!s->budget--) { s->failed_pc=0x0c03c01eu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c03c020;
P_0c03c020: /* original f242, guest PC 0x0c03c020 */
if(!s->budget--) { s->failed_pc=0x0c03c020u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[4],r[18],'*');
goto P_0c03c022;
P_0c03c022: /* original e024, guest PC 0x0c03c022 */
if(!s->budget--) { s->failed_pc=0x0c03c022u; return 0; }
r[0]=0x00000024u;
goto P_0c03c024;
P_0c03c024: /* original 65e3, guest PC 0x0c03c024 */
if(!s->budget--) { s->failed_pc=0x0c03c024u; return 0; }
r[5]=r[14];
goto P_0c03c026;
P_0c03c026: /* original 750c, guest PC 0x0c03c026 */
if(!s->budget--) { s->failed_pc=0x0c03c026u; return 0; }
r[5]+=0x0000000cu;
goto P_0c03c028;
P_0c03c028: /* original f24d, guest PC 0x0c03c028 */
if(!s->budget--) { s->failed_pc=0x0c03c028u; return 0; }
fr[2]^=0x80000000u;
goto P_0c03c02a;
P_0c03c02a: /* original f427, guest PC 0x0c03c02a */
if(!s->budget--) { s->failed_pc=0x0c03c02au; return 0; }
vf3_matrix_store(s,ram,2,r[4]+r[0]);
goto P_0c03c02c;
P_0c03c02c: /* original e018, guest PC 0x0c03c02c */
if(!s->budget--) { s->failed_pc=0x0c03c02cu; return 0; }
r[0]=0x00000018u;
goto P_0c03c02e;
P_0c03c02e: /* original f427, guest PC 0x0c03c02e */
if(!s->budget--) { s->failed_pc=0x0c03c02eu; return 0; }
vf3_matrix_store(s,ram,2,r[4]+r[0]);
goto P_0c03c030;
P_0c03c030: /* original d316, guest PC 0x0c03c030 */
if(!s->budget--) { s->failed_pc=0x0c03c030u; return 0; }
r[3]=read(ram,0x0c03c08cu,4);
goto P_0c03c032;
P_0c03c032: /* original 430b, guest PC 0x0c03c032 */
if(!s->budget--) { s->failed_pc=0x0c03c032u; return 0; }
target=r[3];
r[16]=0x0c03c036u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c03c036u) { target=s->pc; goto dispatch; }
goto P_0c03c036;
P_0c03c034: /* original 64e3, guest PC 0x0c03c034 */
if(!s->budget--) { s->failed_pc=0x0c03c034u; return 0; }
r[4]=r[14];
goto P_0c03c036;
P_0c03c036: /* original f40c, guest PC 0x0c03c036 */
if(!s->budget--) { s->failed_pc=0x0c03c036u; return 0; }
vf3_matrix_move(s,4,0);
goto P_0c03c038;
P_0c03c038: /* original f440, guest PC 0x0c03c038 */
if(!s->budget--) { s->failed_pc=0x0c03c038u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[4],r[18],'+');
goto P_0c03c03a;
P_0c03c03a: /* original e00c, guest PC 0x0c03c03a */
if(!s->budget--) { s->failed_pc=0x0c03c03au; return 0; }
r[0]=0x0000000cu;
goto P_0c03c03c;
P_0c03c03c: /* original f3e6, guest PC 0x0c03c03c */
if(!s->budget--) { s->failed_pc=0x0c03c03cu; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c03c03e;
P_0c03c03e: /* original e030, guest PC 0x0c03c03e */
if(!s->budget--) { s->failed_pc=0x0c03c03eu; return 0; }
r[0]=0x00000030u;
goto P_0c03c040;
P_0c03c040: /* original f24c, guest PC 0x0c03c040 */
if(!s->budget--) { s->failed_pc=0x0c03c040u; return 0; }
vf3_matrix_move(s,2,4);
goto P_0c03c042;
P_0c03c042: /* original f232, guest PC 0x0c03c042 */
if(!s->budget--) { s->failed_pc=0x0c03c042u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c03c044;
P_0c03c044: /* original ff27, guest PC 0x0c03c044 */
if(!s->budget--) { s->failed_pc=0x0c03c044u; return 0; }
vf3_matrix_store(s,ram,2,r[15]+r[0]);
goto P_0c03c046;
P_0c03c046: /* original e010, guest PC 0x0c03c046 */
if(!s->budget--) { s->failed_pc=0x0c03c046u; return 0; }
r[0]=0x00000010u;
goto P_0c03c048;
P_0c03c048: /* original f3e6, guest PC 0x0c03c048 */
if(!s->budget--) { s->failed_pc=0x0c03c048u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c03c04a;
P_0c03c04a: /* original e034, guest PC 0x0c03c04a */
if(!s->budget--) { s->failed_pc=0x0c03c04au; return 0; }
r[0]=0x00000034u;
goto P_0c03c04c;
P_0c03c04c: /* original f24c, guest PC 0x0c03c04c */
if(!s->budget--) { s->failed_pc=0x0c03c04cu; return 0; }
vf3_matrix_move(s,2,4);
goto P_0c03c04e;
P_0c03c04e: /* original f232, guest PC 0x0c03c04e */
if(!s->budget--) { s->failed_pc=0x0c03c04eu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c03c050;
P_0c03c050: /* original ff27, guest PC 0x0c03c050 */
if(!s->budget--) { s->failed_pc=0x0c03c050u; return 0; }
vf3_matrix_store(s,ram,2,r[15]+r[0]);
goto P_0c03c052;
P_0c03c052: /* original e014, guest PC 0x0c03c052 */
if(!s->budget--) { s->failed_pc=0x0c03c052u; return 0; }
r[0]=0x00000014u;
goto P_0c03c054;
P_0c03c054: /* original f3e6, guest PC 0x0c03c054 */
if(!s->budget--) { s->failed_pc=0x0c03c054u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c03c056;
P_0c03c056: /* original e038, guest PC 0x0c03c056 */
if(!s->budget--) { s->failed_pc=0x0c03c056u; return 0; }
r[0]=0x00000038u;
goto P_0c03c058;
P_0c03c058: /* original f432, guest PC 0x0c03c058 */
if(!s->budget--) { s->failed_pc=0x0c03c058u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'*');
goto P_0c03c05a;
P_0c03c05a: /* original ff47, guest PC 0x0c03c05a */
if(!s->budget--) { s->failed_pc=0x0c03c05au; return 0; }
vf3_matrix_store(s,ram,4,r[15]+r[0]);
goto P_0c03c05c;
P_0c03c05c: /* original e00c, guest PC 0x0c03c05c */
if(!s->budget--) { s->failed_pc=0x0c03c05cu; return 0; }
r[0]=0x0000000cu;
goto P_0c03c05e;
P_0c03c05e: /* original f48d, guest PC 0x0c03c05e */
if(!s->budget--) { s->failed_pc=0x0c03c05eu; return 0; }
fr[4]=0;
goto P_0c03c060;
P_0c03c060: /* original ff47, guest PC 0x0c03c060 */
if(!s->budget--) { s->failed_pc=0x0c03c060u; return 0; }
vf3_matrix_store(s,ram,4,r[15]+r[0]);
goto P_0c03c062;
P_0c03c062: /* original e01c, guest PC 0x0c03c062 */
if(!s->budget--) { s->failed_pc=0x0c03c062u; return 0; }
r[0]=0x0000001cu;
goto P_0c03c064;
P_0c03c064: /* original ff47, guest PC 0x0c03c064 */
if(!s->budget--) { s->failed_pc=0x0c03c064u; return 0; }
vf3_matrix_store(s,ram,4,r[15]+r[0]);
goto P_0c03c066;
P_0c03c066: /* original e02c, guest PC 0x0c03c066 */
if(!s->budget--) { s->failed_pc=0x0c03c066u; return 0; }
r[0]=0x0000002cu;
goto P_0c03c068;
P_0c03c068: /* original ff47, guest PC 0x0c03c068 */
if(!s->budget--) { s->failed_pc=0x0c03c068u; return 0; }
vf3_matrix_store(s,ram,4,r[15]+r[0]);
goto P_0c03c06a;
P_0c03c06a: /* original e03c, guest PC 0x0c03c06a */
if(!s->budget--) { s->failed_pc=0x0c03c06au; return 0; }
r[0]=0x0000003cu;
goto P_0c03c06c;
P_0c03c06c: /* original fff7, guest PC 0x0c03c06c */
if(!s->budget--) { s->failed_pc=0x0c03c06cu; return 0; }
vf3_matrix_store(s,ram,15,r[15]+r[0]);
goto P_0c03c06e;
P_0c03c06e: /* original b037, guest PC 0x0c03c06e */
if(!s->budget--) { s->failed_pc=0x0c03c06eu; return 0; }
target=0x0c03c0e0u; r[16]=0x0c03c072u;
r[4]=r[15];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c03c072u) { target=s->pc; goto dispatch; }
goto P_0c03c072;
P_0c03c070: /* original 64f3, guest PC 0x0c03c070 */
if(!s->budget--) { s->failed_pc=0x0c03c070u; return 0; }
r[4]=r[15];
goto P_0c03c072;
P_0c03c072: /* original 7f40, guest PC 0x0c03c072 */
if(!s->budget--) { s->failed_pc=0x0c03c072u; return 0; }
r[15]+=0x00000040u;
goto P_0c03c074;
P_0c03c074: /* original 4f26, guest PC 0x0c03c074 */
if(!s->budget--) { s->failed_pc=0x0c03c074u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c03c076;
P_0c03c076: /* original fff9, guest PC 0x0c03c076 */
if(!s->budget--) { s->failed_pc=0x0c03c076u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c03c078;
P_0c03c078: /* original 000b, guest PC 0x0c03c078 */
if(!s->budget--) { s->failed_pc=0x0c03c078u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c03c07a: /* original 6ef6, guest PC 0x0c03c07a */
if(!s->budget--) { s->failed_pc=0x0c03c07au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c03c07cu,s,ram);
P_0c03c252: /* original 4f22, guest PC 0x0c03c252 */
if(!s->budget--) { s->failed_pc=0x0c03c252u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c03c254;
P_0c03c254: /* original f34d, guest PC 0x0c03c254 */
if(!s->budget--) { s->failed_pc=0x0c03c254u; return 0; }
fr[3]^=0x80000000u;
goto P_0c03c256;
P_0c03c256: /* original f3f0, guest PC 0x0c03c256 */
if(!s->budget--) { s->failed_pc=0x0c03c256u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[15],r[18],'+');
goto P_0c03c258;
P_0c03c258: /* original 7fc0, guest PC 0x0c03c258 */
if(!s->budget--) { s->failed_pc=0x0c03c258u; return 0; }
r[15]+=0xffffffc0u;
goto P_0c03c25a;
P_0c03c25a: /* original 64f3, guest PC 0x0c03c25a */
if(!s->budget--) { s->failed_pc=0x0c03c25au; return 0; }
r[4]=r[15];
goto P_0c03c25c;
P_0c03c25c: /* original ff3a, guest PC 0x0c03c25c */
if(!s->budget--) { s->failed_pc=0x0c03c25cu; return 0; }
vf3_matrix_store(s,ram,3,r[15]);
goto P_0c03c25e;
P_0c03c25e: /* original f4e6, guest PC 0x0c03c25e */
if(!s->budget--) { s->failed_pc=0x0c03c25eu; return 0; }
vf3_matrix_load(s,ram,4,r[14]+r[0]);
goto P_0c03c260;
P_0c03c260: /* original e014, guest PC 0x0c03c260 */
if(!s->budget--) { s->failed_pc=0x0c03c260u; return 0; }
r[0]=0x00000014u;
goto P_0c03c262;
P_0c03c262: /* original f34c, guest PC 0x0c03c262 */
if(!s->budget--) { s->failed_pc=0x0c03c262u; return 0; }
vf3_matrix_move(s,3,4);
goto P_0c03c264;
P_0c03c264: /* original f342, guest PC 0x0c03c264 */
if(!s->budget--) { s->failed_pc=0x0c03c264u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'*');
goto P_0c03c266;
P_0c03c266: /* original f34d, guest PC 0x0c03c266 */
if(!s->budget--) { s->failed_pc=0x0c03c266u; return 0; }
fr[3]^=0x80000000u;
goto P_0c03c268;
P_0c03c268: /* original f3f0, guest PC 0x0c03c268 */
if(!s->budget--) { s->failed_pc=0x0c03c268u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[15],r[18],'+');
goto P_0c03c26a;
P_0c03c26a: /* original ff37, guest PC 0x0c03c26a */
if(!s->budget--) { s->failed_pc=0x0c03c26au; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c03c26c;
P_0c03c26c: /* original e014, guest PC 0x0c03c26c */
if(!s->budget--) { s->failed_pc=0x0c03c26cu; return 0; }
r[0]=0x00000014u;
goto P_0c03c26e;
P_0c03c26e: /* original f4e6, guest PC 0x0c03c26e */
if(!s->budget--) { s->failed_pc=0x0c03c26eu; return 0; }
vf3_matrix_load(s,ram,4,r[14]+r[0]);
goto P_0c03c270;
P_0c03c270: /* original e028, guest PC 0x0c03c270 */
if(!s->budget--) { s->failed_pc=0x0c03c270u; return 0; }
r[0]=0x00000028u;
goto P_0c03c272;
P_0c03c272: /* original f34c, guest PC 0x0c03c272 */
if(!s->budget--) { s->failed_pc=0x0c03c272u; return 0; }
vf3_matrix_move(s,3,4);
goto P_0c03c274;
P_0c03c274: /* original f342, guest PC 0x0c03c274 */
if(!s->budget--) { s->failed_pc=0x0c03c274u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'*');
goto P_0c03c276;
P_0c03c276: /* original f34d, guest PC 0x0c03c276 */
if(!s->budget--) { s->failed_pc=0x0c03c276u; return 0; }
fr[3]^=0x80000000u;
goto P_0c03c278;
P_0c03c278: /* original f3f0, guest PC 0x0c03c278 */
if(!s->budget--) { s->failed_pc=0x0c03c278u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[15],r[18],'+');
goto P_0c03c27a;
P_0c03c27a: /* original ff37, guest PC 0x0c03c27a */
if(!s->budget--) { s->failed_pc=0x0c03c27au; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c03c27c;
P_0c03c27c: /* original e010, guest PC 0x0c03c27c */
if(!s->budget--) { s->failed_pc=0x0c03c27cu; return 0; }
r[0]=0x00000010u;
goto P_0c03c27e;
P_0c03c27e: /* original f3e6, guest PC 0x0c03c27e */
if(!s->budget--) { s->failed_pc=0x0c03c27eu; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c03c280;
P_0c03c280: /* original e00c, guest PC 0x0c03c280 */
if(!s->budget--) { s->failed_pc=0x0c03c280u; return 0; }
r[0]=0x0000000cu;
goto P_0c03c282;
P_0c03c282: /* original 65e3, guest PC 0x0c03c282 */
if(!s->budget--) { s->failed_pc=0x0c03c282u; return 0; }
r[5]=r[14];
goto P_0c03c284;
P_0c03c284: /* original f2e6, guest PC 0x0c03c284 */
if(!s->budget--) { s->failed_pc=0x0c03c284u; return 0; }
vf3_matrix_load(s,ram,2,r[14]+r[0]);
goto P_0c03c286;
P_0c03c286: /* original e010, guest PC 0x0c03c286 */
if(!s->budget--) { s->failed_pc=0x0c03c286u; return 0; }
r[0]=0x00000010u;
goto P_0c03c288;
P_0c03c288: /* original 750c, guest PC 0x0c03c288 */
if(!s->budget--) { s->failed_pc=0x0c03c288u; return 0; }
r[5]+=0x0000000cu;
goto P_0c03c28a;
P_0c03c28a: /* original f232, guest PC 0x0c03c28a */
if(!s->budget--) { s->failed_pc=0x0c03c28au; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c03c28c;
P_0c03c28c: /* original f24d, guest PC 0x0c03c28c */
if(!s->budget--) { s->failed_pc=0x0c03c28cu; return 0; }
fr[2]^=0x80000000u;
goto P_0c03c28e;
P_0c03c28e: /* original f427, guest PC 0x0c03c28e */
if(!s->budget--) { s->failed_pc=0x0c03c28eu; return 0; }
vf3_matrix_store(s,ram,2,r[4]+r[0]);
goto P_0c03c290;
P_0c03c290: /* original e004, guest PC 0x0c03c290 */
if(!s->budget--) { s->failed_pc=0x0c03c290u; return 0; }
r[0]=0x00000004u;
goto P_0c03c292;
P_0c03c292: /* original f427, guest PC 0x0c03c292 */
if(!s->budget--) { s->failed_pc=0x0c03c292u; return 0; }
vf3_matrix_store(s,ram,2,r[4]+r[0]);
goto P_0c03c294;
P_0c03c294: /* original e014, guest PC 0x0c03c294 */
if(!s->budget--) { s->failed_pc=0x0c03c294u; return 0; }
r[0]=0x00000014u;
goto P_0c03c296;
P_0c03c296: /* original f3e6, guest PC 0x0c03c296 */
if(!s->budget--) { s->failed_pc=0x0c03c296u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c03c298;
P_0c03c298: /* original e00c, guest PC 0x0c03c298 */
if(!s->budget--) { s->failed_pc=0x0c03c298u; return 0; }
r[0]=0x0000000cu;
goto P_0c03c29a;
P_0c03c29a: /* original f2e6, guest PC 0x0c03c29a */
if(!s->budget--) { s->failed_pc=0x0c03c29au; return 0; }
vf3_matrix_load(s,ram,2,r[14]+r[0]);
goto P_0c03c29c;
P_0c03c29c: /* original e020, guest PC 0x0c03c29c */
if(!s->budget--) { s->failed_pc=0x0c03c29cu; return 0; }
r[0]=0x00000020u;
goto P_0c03c29e;
P_0c03c29e: /* original 64f3, guest PC 0x0c03c29e */
if(!s->budget--) { s->failed_pc=0x0c03c29eu; return 0; }
r[4]=r[15];
goto P_0c03c2a0;
P_0c03c2a0: /* original f232, guest PC 0x0c03c2a0 */
if(!s->budget--) { s->failed_pc=0x0c03c2a0u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c03c2a2;
P_0c03c2a2: /* original f24d, guest PC 0x0c03c2a2 */
if(!s->budget--) { s->failed_pc=0x0c03c2a2u; return 0; }
fr[2]^=0x80000000u;
goto P_0c03c2a4;
P_0c03c2a4: /* original f427, guest PC 0x0c03c2a4 */
if(!s->budget--) { s->failed_pc=0x0c03c2a4u; return 0; }
vf3_matrix_store(s,ram,2,r[4]+r[0]);
goto P_0c03c2a6;
P_0c03c2a6: /* original e008, guest PC 0x0c03c2a6 */
if(!s->budget--) { s->failed_pc=0x0c03c2a6u; return 0; }
r[0]=0x00000008u;
goto P_0c03c2a8;
P_0c03c2a8: /* original f427, guest PC 0x0c03c2a8 */
if(!s->budget--) { s->failed_pc=0x0c03c2a8u; return 0; }
vf3_matrix_store(s,ram,2,r[4]+r[0]);
goto P_0c03c2aa;
P_0c03c2aa: /* original e014, guest PC 0x0c03c2aa */
if(!s->budget--) { s->failed_pc=0x0c03c2aau; return 0; }
r[0]=0x00000014u;
goto P_0c03c2ac;
P_0c03c2ac: /* original f3e6, guest PC 0x0c03c2ac */
if(!s->budget--) { s->failed_pc=0x0c03c2acu; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c03c2ae;
P_0c03c2ae: /* original e010, guest PC 0x0c03c2ae */
if(!s->budget--) { s->failed_pc=0x0c03c2aeu; return 0; }
r[0]=0x00000010u;
goto P_0c03c2b0;
P_0c03c2b0: /* original f2e6, guest PC 0x0c03c2b0 */
if(!s->budget--) { s->failed_pc=0x0c03c2b0u; return 0; }
vf3_matrix_load(s,ram,2,r[14]+r[0]);
goto P_0c03c2b2;
P_0c03c2b2: /* original e024, guest PC 0x0c03c2b2 */
if(!s->budget--) { s->failed_pc=0x0c03c2b2u; return 0; }
r[0]=0x00000024u;
goto P_0c03c2b4;
P_0c03c2b4: /* original 64f3, guest PC 0x0c03c2b4 */
if(!s->budget--) { s->failed_pc=0x0c03c2b4u; return 0; }
r[4]=r[15];
goto P_0c03c2b6;
P_0c03c2b6: /* original f232, guest PC 0x0c03c2b6 */
if(!s->budget--) { s->failed_pc=0x0c03c2b6u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c03c2b8;
P_0c03c2b8: /* original f24d, guest PC 0x0c03c2b8 */
if(!s->budget--) { s->failed_pc=0x0c03c2b8u; return 0; }
fr[2]^=0x80000000u;
goto P_0c03c2ba;
P_0c03c2ba: /* original f427, guest PC 0x0c03c2ba */
if(!s->budget--) { s->failed_pc=0x0c03c2bau; return 0; }
vf3_matrix_store(s,ram,2,r[4]+r[0]);
goto P_0c03c2bc;
P_0c03c2bc: /* original e018, guest PC 0x0c03c2bc */
if(!s->budget--) { s->failed_pc=0x0c03c2bcu; return 0; }
r[0]=0x00000018u;
goto P_0c03c2be;
P_0c03c2be: /* original f427, guest PC 0x0c03c2be */
if(!s->budget--) { s->failed_pc=0x0c03c2beu; return 0; }
vf3_matrix_store(s,ram,2,r[4]+r[0]);
goto P_0c03c2c0;
P_0c03c2c0: /* original d366, guest PC 0x0c03c2c0 */
if(!s->budget--) { s->failed_pc=0x0c03c2c0u; return 0; }
r[3]=read(ram,0x0c03c45cu,4);
goto P_0c03c2c2;
P_0c03c2c2: /* original 430b, guest PC 0x0c03c2c2 */
if(!s->budget--) { s->failed_pc=0x0c03c2c2u; return 0; }
target=r[3];
r[16]=0x0c03c2c6u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c03c2c6u) { target=s->pc; goto dispatch; }
goto P_0c03c2c6;
P_0c03c2c4: /* original 64e3, guest PC 0x0c03c2c4 */
if(!s->budget--) { s->failed_pc=0x0c03c2c4u; return 0; }
r[4]=r[14];
goto P_0c03c2c6;
P_0c03c2c6: /* original e00c, guest PC 0x0c03c2c6 */
if(!s->budget--) { s->failed_pc=0x0c03c2c6u; return 0; }
r[0]=0x0000000cu;
goto P_0c03c2c8;
P_0c03c2c8: /* original f20c, guest PC 0x0c03c2c8 */
if(!s->budget--) { s->failed_pc=0x0c03c2c8u; return 0; }
vf3_matrix_move(s,2,0);
goto P_0c03c2ca;
P_0c03c2ca: /* original f3e6, guest PC 0x0c03c2ca */
if(!s->budget--) { s->failed_pc=0x0c03c2cau; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c03c2cc;
P_0c03c2cc: /* original e030, guest PC 0x0c03c2cc */
if(!s->budget--) { s->failed_pc=0x0c03c2ccu; return 0; }
r[0]=0x00000030u;
goto P_0c03c2ce;
P_0c03c2ce: /* original f40c, guest PC 0x0c03c2ce */
if(!s->budget--) { s->failed_pc=0x0c03c2ceu; return 0; }
vf3_matrix_move(s,4,0);
goto P_0c03c2d0;
P_0c03c2d0: /* original f232, guest PC 0x0c03c2d0 */
if(!s->budget--) { s->failed_pc=0x0c03c2d0u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c03c2d2;
P_0c03c2d2: /* original ff27, guest PC 0x0c03c2d2 */
if(!s->budget--) { s->failed_pc=0x0c03c2d2u; return 0; }
vf3_matrix_store(s,ram,2,r[15]+r[0]);
goto P_0c03c2d4;
P_0c03c2d4: /* original e010, guest PC 0x0c03c2d4 */
if(!s->budget--) { s->failed_pc=0x0c03c2d4u; return 0; }
r[0]=0x00000010u;
goto P_0c03c2d6;
P_0c03c2d6: /* original f3e6, guest PC 0x0c03c2d6 */
if(!s->budget--) { s->failed_pc=0x0c03c2d6u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c03c2d8;
P_0c03c2d8: /* original e034, guest PC 0x0c03c2d8 */
if(!s->budget--) { s->failed_pc=0x0c03c2d8u; return 0; }
r[0]=0x00000034u;
goto P_0c03c2da;
P_0c03c2da: /* original f24c, guest PC 0x0c03c2da */
if(!s->budget--) { s->failed_pc=0x0c03c2dau; return 0; }
vf3_matrix_move(s,2,4);
goto P_0c03c2dc;
P_0c03c2dc: /* original f232, guest PC 0x0c03c2dc */
if(!s->budget--) { s->failed_pc=0x0c03c2dcu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c03c2de;
P_0c03c2de: /* original ff27, guest PC 0x0c03c2de */
if(!s->budget--) { s->failed_pc=0x0c03c2deu; return 0; }
vf3_matrix_store(s,ram,2,r[15]+r[0]);
goto P_0c03c2e0;
P_0c03c2e0: /* original e014, guest PC 0x0c03c2e0 */
if(!s->budget--) { s->failed_pc=0x0c03c2e0u; return 0; }
r[0]=0x00000014u;
goto P_0c03c2e2;
P_0c03c2e2: /* original f3e6, guest PC 0x0c03c2e2 */
if(!s->budget--) { s->failed_pc=0x0c03c2e2u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c03c2e4;
P_0c03c2e4: /* original e038, guest PC 0x0c03c2e4 */
if(!s->budget--) { s->failed_pc=0x0c03c2e4u; return 0; }
r[0]=0x00000038u;
goto P_0c03c2e6;
P_0c03c2e6: /* original f432, guest PC 0x0c03c2e6 */
if(!s->budget--) { s->failed_pc=0x0c03c2e6u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'*');
goto P_0c03c2e8;
P_0c03c2e8: /* original ff47, guest PC 0x0c03c2e8 */
if(!s->budget--) { s->failed_pc=0x0c03c2e8u; return 0; }
vf3_matrix_store(s,ram,4,r[15]+r[0]);
goto P_0c03c2ea;
P_0c03c2ea: /* original e00c, guest PC 0x0c03c2ea */
if(!s->budget--) { s->failed_pc=0x0c03c2eau; return 0; }
r[0]=0x0000000cu;
goto P_0c03c2ec;
P_0c03c2ec: /* original f48d, guest PC 0x0c03c2ec */
if(!s->budget--) { s->failed_pc=0x0c03c2ecu; return 0; }
fr[4]=0;
goto P_0c03c2ee;
P_0c03c2ee: /* original ff47, guest PC 0x0c03c2ee */
if(!s->budget--) { s->failed_pc=0x0c03c2eeu; return 0; }
vf3_matrix_store(s,ram,4,r[15]+r[0]);
goto P_0c03c2f0;
P_0c03c2f0: /* original e01c, guest PC 0x0c03c2f0 */
if(!s->budget--) { s->failed_pc=0x0c03c2f0u; return 0; }
r[0]=0x0000001cu;
goto P_0c03c2f2;
P_0c03c2f2: /* original ff47, guest PC 0x0c03c2f2 */
if(!s->budget--) { s->failed_pc=0x0c03c2f2u; return 0; }
vf3_matrix_store(s,ram,4,r[15]+r[0]);
goto P_0c03c2f4;
P_0c03c2f4: /* original e02c, guest PC 0x0c03c2f4 */
if(!s->budget--) { s->failed_pc=0x0c03c2f4u; return 0; }
r[0]=0x0000002cu;
goto P_0c03c2f6;
P_0c03c2f6: /* original ff47, guest PC 0x0c03c2f6 */
if(!s->budget--) { s->failed_pc=0x0c03c2f6u; return 0; }
vf3_matrix_store(s,ram,4,r[15]+r[0]);
goto P_0c03c2f8;
P_0c03c2f8: /* original e03c, guest PC 0x0c03c2f8 */
if(!s->budget--) { s->failed_pc=0x0c03c2f8u; return 0; }
r[0]=0x0000003cu;
goto P_0c03c2fa;
P_0c03c2fa: /* original fff7, guest PC 0x0c03c2fa */
if(!s->budget--) { s->failed_pc=0x0c03c2fau; return 0; }
vf3_matrix_store(s,ram,15,r[15]+r[0]);
goto P_0c03c2fc;
P_0c03c2fc: /* original d358, guest PC 0x0c03c2fc */
if(!s->budget--) { s->failed_pc=0x0c03c2fcu; return 0; }
r[3]=read(ram,0x0c03c460u,4);
goto P_0c03c2fe;
P_0c03c2fe: /* original 430b, guest PC 0x0c03c2fe */
if(!s->budget--) { s->failed_pc=0x0c03c2feu; return 0; }
target=r[3];
r[16]=0x0c03c302u;
r[4]=r[15];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c03c302u) { target=s->pc; goto dispatch; }
goto P_0c03c302;
P_0c03c300: /* original 64f3, guest PC 0x0c03c300 */
if(!s->budget--) { s->failed_pc=0x0c03c300u; return 0; }
r[4]=r[15];
goto P_0c03c302;
P_0c03c302: /* original 7f40, guest PC 0x0c03c302 */
if(!s->budget--) { s->failed_pc=0x0c03c302u; return 0; }
r[15]+=0x00000040u;
goto P_0c03c304;
P_0c03c304: /* original 4f26, guest PC 0x0c03c304 */
if(!s->budget--) { s->failed_pc=0x0c03c304u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c03c306;
P_0c03c306: /* original fff9, guest PC 0x0c03c306 */
if(!s->budget--) { s->failed_pc=0x0c03c306u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c03c308;
P_0c03c308: /* original 000b, guest PC 0x0c03c308 */
if(!s->budget--) { s->failed_pc=0x0c03c308u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c03c30a: /* original 6ef6, guest PC 0x0c03c30a */
if(!s->budget--) { s->failed_pc=0x0c03c30au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c03c30cu,s,ram);
P_0c03c324: /* original 4f22, guest PC 0x0c03c324 */
if(!s->budget--) { s->failed_pc=0x0c03c324u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c03c326;
P_0c03c326: /* original f231, guest PC 0x0c03c326 */
if(!s->budget--) { s->failed_pc=0x0c03c326u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'-');
goto P_0c03c328;
P_0c03c328: /* original 7fb4, guest PC 0x0c03c328 */
if(!s->budget--) { s->failed_pc=0x0c03c328u; return 0; }
r[15]+=0xffffffb4u;
goto P_0c03c32a;
P_0c03c32a: /* original 6ef3, guest PC 0x0c03c32a */
if(!s->budget--) { s->failed_pc=0x0c03c32au; return 0; }
r[14]=r[15];
goto P_0c03c32c;
P_0c03c32c: /* original fe2a, guest PC 0x0c03c32c */
if(!s->budget--) { s->failed_pc=0x0c03c32cu; return 0; }
vf3_matrix_store(s,ram,2,r[14]);
goto P_0c03c32e;
P_0c03c32e: /* original f266, guest PC 0x0c03c32e */
if(!s->budget--) { s->failed_pc=0x0c03c32eu; return 0; }
vf3_matrix_load(s,ram,2,r[6]+r[0]);
goto P_0c03c330;
P_0c03c330: /* original f3c6, guest PC 0x0c03c330 */
if(!s->budget--) { s->failed_pc=0x0c03c330u; return 0; }
vf3_matrix_load(s,ram,3,r[12]+r[0]);
goto P_0c03c332;
P_0c03c332: /* original f231, guest PC 0x0c03c332 */
if(!s->budget--) { s->failed_pc=0x0c03c332u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'-');
goto P_0c03c334;
P_0c03c334: /* original fe27, guest PC 0x0c03c334 */
if(!s->budget--) { s->failed_pc=0x0c03c334u; return 0; }
vf3_matrix_store(s,ram,2,r[14]+r[0]);
goto P_0c03c336;
P_0c03c336: /* original e008, guest PC 0x0c03c336 */
if(!s->budget--) { s->failed_pc=0x0c03c336u; return 0; }
r[0]=0x00000008u;
goto P_0c03c338;
P_0c03c338: /* original f266, guest PC 0x0c03c338 */
if(!s->budget--) { s->failed_pc=0x0c03c338u; return 0; }
vf3_matrix_load(s,ram,2,r[6]+r[0]);
goto P_0c03c33a;
P_0c03c33a: /* original f3c6, guest PC 0x0c03c33a */
if(!s->budget--) { s->failed_pc=0x0c03c33au; return 0; }
vf3_matrix_load(s,ram,3,r[12]+r[0]);
goto P_0c03c33c;
P_0c03c33c: /* original f231, guest PC 0x0c03c33c */
if(!s->budget--) { s->failed_pc=0x0c03c33cu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'-');
goto P_0c03c33e;
P_0c03c33e: /* original fe27, guest PC 0x0c03c33e */
if(!s->budget--) { s->failed_pc=0x0c03c33eu; return 0; }
vf3_matrix_store(s,ram,2,r[14]+r[0]);
goto P_0c03c340;
P_0c03c340: /* original e00c, guest PC 0x0c03c340 */
if(!s->budget--) { s->failed_pc=0x0c03c340u; return 0; }
r[0]=0x0000000cu;
goto P_0c03c342;
P_0c03c342: /* original f4d6, guest PC 0x0c03c342 */
if(!s->budget--) { s->failed_pc=0x0c03c342u; return 0; }
vf3_matrix_load(s,ram,4,r[13]+r[0]);
goto P_0c03c344;
P_0c03c344: /* original e004, guest PC 0x0c03c344 */
if(!s->budget--) { s->failed_pc=0x0c03c344u; return 0; }
r[0]=0x00000004u;
goto P_0c03c346;
P_0c03c346: /* original f0e6, guest PC 0x0c03c346 */
if(!s->budget--) { s->failed_pc=0x0c03c346u; return 0; }
vf3_matrix_load(s,ram,0,r[14]+r[0]);
goto P_0c03c348;
P_0c03c348: /* original e010, guest PC 0x0c03c348 */
if(!s->budget--) { s->failed_pc=0x0c03c348u; return 0; }
r[0]=0x00000010u;
goto P_0c03c34a;
P_0c03c34a: /* original f3d6, guest PC 0x0c03c34a */
if(!s->budget--) { s->failed_pc=0x0c03c34au; return 0; }
vf3_matrix_load(s,ram,3,r[13]+r[0]);
goto P_0c03c34c;
P_0c03c34c: /* original f5e8, guest PC 0x0c03c34c */
if(!s->budget--) { s->failed_pc=0x0c03c34cu; return 0; }
vf3_matrix_load(s,ram,5,r[14]);
goto P_0c03c34e;
P_0c03c34e: /* original fe9d, guest PC 0x0c03c34e */
if(!s->budget--) { s->failed_pc=0x0c03c34eu; return 0; }
fr[14]=0x3f800000u;
goto P_0c03c350;
P_0c03c350: /* original f302, guest PC 0x0c03c350 */
if(!s->budget--) { s->failed_pc=0x0c03c350u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[0],r[18],'*');
goto P_0c03c352;
P_0c03c352: /* original f05c, guest PC 0x0c03c352 */
if(!s->budget--) { s->failed_pc=0x0c03c352u; return 0; }
vf3_matrix_move(s,0,5);
goto P_0c03c354;
P_0c03c354: /* original e008, guest PC 0x0c03c354 */
if(!s->budget--) { s->failed_pc=0x0c03c354u; return 0; }
r[0]=0x00000008u;
goto P_0c03c356;
P_0c03c356: /* original ffec, guest PC 0x0c03c356 */
if(!s->budget--) { s->failed_pc=0x0c03c356u; return 0; }
vf3_matrix_move(s,15,14);
goto P_0c03c358;
P_0c03c358: /* original f34e, guest PC 0x0c03c358 */
if(!s->budget--) { s->failed_pc=0x0c03c358u; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[4],fr[3],r[18]);
goto P_0c03c35a;
P_0c03c35a: /* original f0e6, guest PC 0x0c03c35a */
if(!s->budget--) { s->failed_pc=0x0c03c35au; return 0; }
vf3_matrix_load(s,ram,0,r[14]+r[0]);
goto P_0c03c35c;
P_0c03c35c: /* original e014, guest PC 0x0c03c35c */
if(!s->budget--) { s->failed_pc=0x0c03c35cu; return 0; }
r[0]=0x00000014u;
goto P_0c03c35e;
P_0c03c35e: /* original f2d6, guest PC 0x0c03c35e */
if(!s->budget--) { s->failed_pc=0x0c03c35eu; return 0; }
vf3_matrix_load(s,ram,2,r[13]+r[0]);
goto P_0c03c360;
P_0c03c360: /* original e00c, guest PC 0x0c03c360 */
if(!s->budget--) { s->failed_pc=0x0c03c360u; return 0; }
r[0]=0x0000000cu;
goto P_0c03c362;
P_0c03c362: /* original f32e, guest PC 0x0c03c362 */
if(!s->budget--) { s->failed_pc=0x0c03c362u; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[2],fr[3],r[18]);
goto P_0c03c364;
P_0c03c364: /* original ff33, guest PC 0x0c03c364 */
if(!s->budget--) { s->failed_pc=0x0c03c364u; return 0; }
fr[15]=vf3_fpu_binary(fr[15],fr[3],r[18],'/');
goto P_0c03c366;
P_0c03c366: /* original f3ec, guest PC 0x0c03c366 */
if(!s->budget--) { s->failed_pc=0x0c03c366u; return 0; }
vf3_matrix_move(s,3,14);
goto P_0c03c368;
P_0c03c368: /* original f4f2, guest PC 0x0c03c368 */
if(!s->budget--) { s->failed_pc=0x0c03c368u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[15],r[18],'*');
goto P_0c03c36a;
P_0c03c36a: /* original f542, guest PC 0x0c03c36a */
if(!s->budget--) { s->failed_pc=0x0c03c36au; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[4],r[18],'*');
goto P_0c03c36c;
P_0c03c36c: /* original f351, guest PC 0x0c03c36c */
if(!s->budget--) { s->failed_pc=0x0c03c36cu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[5],r[18],'-');
goto P_0c03c36e;
P_0c03c36e: /* original ff37, guest PC 0x0c03c36e */
if(!s->budget--) { s->failed_pc=0x0c03c36eu; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c03c370;
P_0c03c370: /* original e004, guest PC 0x0c03c370 */
if(!s->budget--) { s->failed_pc=0x0c03c370u; return 0; }
r[0]=0x00000004u;
goto P_0c03c372;
P_0c03c372: /* original f3e6, guest PC 0x0c03c372 */
if(!s->budget--) { s->failed_pc=0x0c03c372u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c03c374;
P_0c03c374: /* original e010, guest PC 0x0c03c374 */
if(!s->budget--) { s->failed_pc=0x0c03c374u; return 0; }
r[0]=0x00000010u;
goto P_0c03c376;
P_0c03c376: /* original f342, guest PC 0x0c03c376 */
if(!s->budget--) { s->failed_pc=0x0c03c376u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'*');
goto P_0c03c378;
P_0c03c378: /* original f34d, guest PC 0x0c03c378 */
if(!s->budget--) { s->failed_pc=0x0c03c378u; return 0; }
fr[3]^=0x80000000u;
goto P_0c03c37a;
P_0c03c37a: /* original ff37, guest PC 0x0c03c37a */
if(!s->budget--) { s->failed_pc=0x0c03c37au; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c03c37c;
P_0c03c37c: /* original e008, guest PC 0x0c03c37c */
if(!s->budget--) { s->failed_pc=0x0c03c37cu; return 0; }
r[0]=0x00000008u;
goto P_0c03c37e;
P_0c03c37e: /* original f3e6, guest PC 0x0c03c37e */
if(!s->budget--) { s->failed_pc=0x0c03c37eu; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c03c380;
P_0c03c380: /* original e014, guest PC 0x0c03c380 */
if(!s->budget--) { s->failed_pc=0x0c03c380u; return 0; }
r[0]=0x00000014u;
goto P_0c03c382;
P_0c03c382: /* original f342, guest PC 0x0c03c382 */
if(!s->budget--) { s->failed_pc=0x0c03c382u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'*');
goto P_0c03c384;
P_0c03c384: /* original f34d, guest PC 0x0c03c384 */
if(!s->budget--) { s->failed_pc=0x0c03c384u; return 0; }
fr[3]^=0x80000000u;
goto P_0c03c386;
P_0c03c386: /* original ff37, guest PC 0x0c03c386 */
if(!s->budget--) { s->failed_pc=0x0c03c386u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c03c388;
P_0c03c388: /* original e010, guest PC 0x0c03c388 */
if(!s->budget--) { s->failed_pc=0x0c03c388u; return 0; }
r[0]=0x00000010u;
goto P_0c03c38a;
P_0c03c38a: /* original f4d6, guest PC 0x0c03c38a */
if(!s->budget--) { s->failed_pc=0x0c03c38au; return 0; }
vf3_matrix_load(s,ram,4,r[13]+r[0]);
goto P_0c03c38c;
P_0c03c38c: /* original f3e8, guest PC 0x0c03c38c */
if(!s->budget--) { s->failed_pc=0x0c03c38cu; return 0; }
vf3_matrix_load(s,ram,3,r[14]);
goto P_0c03c38e;
P_0c03c38e: /* original f4f2, guest PC 0x0c03c38e */
if(!s->budget--) { s->failed_pc=0x0c03c38eu; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[15],r[18],'*');
goto P_0c03c390;
P_0c03c390: /* original f342, guest PC 0x0c03c390 */
if(!s->budget--) { s->failed_pc=0x0c03c390u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'*');
goto P_0c03c392;
P_0c03c392: /* original e01c, guest PC 0x0c03c392 */
if(!s->budget--) { s->failed_pc=0x0c03c392u; return 0; }
r[0]=0x0000001cu;
goto P_0c03c394;
P_0c03c394: /* original f34d, guest PC 0x0c03c394 */
if(!s->budget--) { s->failed_pc=0x0c03c394u; return 0; }
fr[3]^=0x80000000u;
goto P_0c03c396;
P_0c03c396: /* original ff37, guest PC 0x0c03c396 */
if(!s->budget--) { s->failed_pc=0x0c03c396u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c03c398;
P_0c03c398: /* original e004, guest PC 0x0c03c398 */
if(!s->budget--) { s->failed_pc=0x0c03c398u; return 0; }
r[0]=0x00000004u;
goto P_0c03c39a;
P_0c03c39a: /* original f3e6, guest PC 0x0c03c39a */
if(!s->budget--) { s->failed_pc=0x0c03c39au; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c03c39c;
P_0c03c39c: /* original e020, guest PC 0x0c03c39c */
if(!s->budget--) { s->failed_pc=0x0c03c39cu; return 0; }
r[0]=0x00000020u;
goto P_0c03c39e;
P_0c03c39e: /* original f342, guest PC 0x0c03c39e */
if(!s->budget--) { s->failed_pc=0x0c03c39eu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'*');
goto P_0c03c3a0;
P_0c03c3a0: /* original f34d, guest PC 0x0c03c3a0 */
if(!s->budget--) { s->failed_pc=0x0c03c3a0u; return 0; }
fr[3]^=0x80000000u;
goto P_0c03c3a2;
P_0c03c3a2: /* original f3e0, guest PC 0x0c03c3a2 */
if(!s->budget--) { s->failed_pc=0x0c03c3a2u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[14],r[18],'+');
goto P_0c03c3a4;
P_0c03c3a4: /* original ff37, guest PC 0x0c03c3a4 */
if(!s->budget--) { s->failed_pc=0x0c03c3a4u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c03c3a6;
P_0c03c3a6: /* original e008, guest PC 0x0c03c3a6 */
if(!s->budget--) { s->failed_pc=0x0c03c3a6u; return 0; }
r[0]=0x00000008u;
goto P_0c03c3a8;
P_0c03c3a8: /* original f3e6, guest PC 0x0c03c3a8 */
if(!s->budget--) { s->failed_pc=0x0c03c3a8u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c03c3aa;
P_0c03c3aa: /* original e024, guest PC 0x0c03c3aa */
if(!s->budget--) { s->failed_pc=0x0c03c3aau; return 0; }
r[0]=0x00000024u;
goto P_0c03c3ac;
P_0c03c3ac: /* original f342, guest PC 0x0c03c3ac */
if(!s->budget--) { s->failed_pc=0x0c03c3acu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'*');
goto P_0c03c3ae;
P_0c03c3ae: /* original f34d, guest PC 0x0c03c3ae */
if(!s->budget--) { s->failed_pc=0x0c03c3aeu; return 0; }
fr[3]^=0x80000000u;
goto P_0c03c3b0;
P_0c03c3b0: /* original ff37, guest PC 0x0c03c3b0 */
if(!s->budget--) { s->failed_pc=0x0c03c3b0u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c03c3b2;
P_0c03c3b2: /* original e014, guest PC 0x0c03c3b2 */
if(!s->budget--) { s->failed_pc=0x0c03c3b2u; return 0; }
r[0]=0x00000014u;
goto P_0c03c3b4;
P_0c03c3b4: /* original f4d6, guest PC 0x0c03c3b4 */
if(!s->budget--) { s->failed_pc=0x0c03c3b4u; return 0; }
vf3_matrix_load(s,ram,4,r[13]+r[0]);
goto P_0c03c3b6;
P_0c03c3b6: /* original e02c, guest PC 0x0c03c3b6 */
if(!s->budget--) { s->failed_pc=0x0c03c3b6u; return 0; }
r[0]=0x0000002cu;
goto P_0c03c3b8;
P_0c03c3b8: /* original f3e8, guest PC 0x0c03c3b8 */
if(!s->budget--) { s->failed_pc=0x0c03c3b8u; return 0; }
vf3_matrix_load(s,ram,3,r[14]);
goto P_0c03c3ba;
P_0c03c3ba: /* original f4f2, guest PC 0x0c03c3ba */
if(!s->budget--) { s->failed_pc=0x0c03c3bau; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[15],r[18],'*');
goto P_0c03c3bc;
P_0c03c3bc: /* original f342, guest PC 0x0c03c3bc */
if(!s->budget--) { s->failed_pc=0x0c03c3bcu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'*');
goto P_0c03c3be;
P_0c03c3be: /* original f34d, guest PC 0x0c03c3be */
if(!s->budget--) { s->failed_pc=0x0c03c3beu; return 0; }
fr[3]^=0x80000000u;
goto P_0c03c3c0;
P_0c03c3c0: /* original ff37, guest PC 0x0c03c3c0 */
if(!s->budget--) { s->failed_pc=0x0c03c3c0u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c03c3c2;
P_0c03c3c2: /* original e004, guest PC 0x0c03c3c2 */
if(!s->budget--) { s->failed_pc=0x0c03c3c2u; return 0; }
r[0]=0x00000004u;
goto P_0c03c3c4;
P_0c03c3c4: /* original f3e6, guest PC 0x0c03c3c4 */
if(!s->budget--) { s->failed_pc=0x0c03c3c4u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c03c3c6;
P_0c03c3c6: /* original e030, guest PC 0x0c03c3c6 */
if(!s->budget--) { s->failed_pc=0x0c03c3c6u; return 0; }
r[0]=0x00000030u;
goto P_0c03c3c8;
P_0c03c3c8: /* original f342, guest PC 0x0c03c3c8 */
if(!s->budget--) { s->failed_pc=0x0c03c3c8u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'*');
goto P_0c03c3ca;
P_0c03c3ca: /* original f34d, guest PC 0x0c03c3ca */
if(!s->budget--) { s->failed_pc=0x0c03c3cau; return 0; }
fr[3]^=0x80000000u;
goto P_0c03c3cc;
P_0c03c3cc: /* original ff37, guest PC 0x0c03c3cc */
if(!s->budget--) { s->failed_pc=0x0c03c3ccu; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c03c3ce;
P_0c03c3ce: /* original e008, guest PC 0x0c03c3ce */
if(!s->budget--) { s->failed_pc=0x0c03c3ceu; return 0; }
r[0]=0x00000008u;
goto P_0c03c3d0;
P_0c03c3d0: /* original f3e6, guest PC 0x0c03c3d0 */
if(!s->budget--) { s->failed_pc=0x0c03c3d0u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c03c3d2;
P_0c03c3d2: /* original 65d3, guest PC 0x0c03c3d2 */
if(!s->budget--) { s->failed_pc=0x0c03c3d2u; return 0; }
r[5]=r[13];
goto P_0c03c3d4;
P_0c03c3d4: /* original e034, guest PC 0x0c03c3d4 */
if(!s->budget--) { s->failed_pc=0x0c03c3d4u; return 0; }
r[0]=0x00000034u;
goto P_0c03c3d6;
P_0c03c3d6: /* original f342, guest PC 0x0c03c3d6 */
if(!s->budget--) { s->failed_pc=0x0c03c3d6u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'*');
goto P_0c03c3d8;
P_0c03c3d8: /* original 750c, guest PC 0x0c03c3d8 */
if(!s->budget--) { s->failed_pc=0x0c03c3d8u; return 0; }
r[5]+=0x0000000cu;
goto P_0c03c3da;
P_0c03c3da: /* original f34d, guest PC 0x0c03c3da */
if(!s->budget--) { s->failed_pc=0x0c03c3dau; return 0; }
fr[3]^=0x80000000u;
goto P_0c03c3dc;
P_0c03c3dc: /* original f3e0, guest PC 0x0c03c3dc */
if(!s->budget--) { s->failed_pc=0x0c03c3dcu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[14],r[18],'+');
goto P_0c03c3de;
P_0c03c3de: /* original ff37, guest PC 0x0c03c3de */
if(!s->budget--) { s->failed_pc=0x0c03c3deu; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c03c3e0;
P_0c03c3e0: /* original d31e, guest PC 0x0c03c3e0 */
if(!s->budget--) { s->failed_pc=0x0c03c3e0u; return 0; }
r[3]=read(ram,0x0c03c45cu,4);
goto P_0c03c3e2;
P_0c03c3e2: /* original 430b, guest PC 0x0c03c3e2 */
if(!s->budget--) { s->failed_pc=0x0c03c3e2u; return 0; }
target=r[3];
r[16]=0x0c03c3e6u;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c03c3e6u) { target=s->pc; goto dispatch; }
goto P_0c03c3e6;
P_0c03c3e4: /* original 64d3, guest PC 0x0c03c3e4 */
if(!s->budget--) { s->failed_pc=0x0c03c3e4u; return 0; }
r[4]=r[13];
goto P_0c03c3e6;
P_0c03c3e6: /* original f40c, guest PC 0x0c03c3e6 */
if(!s->budget--) { s->failed_pc=0x0c03c3e6u; return 0; }
vf3_matrix_move(s,4,0);
goto P_0c03c3e8;
P_0c03c3e8: /* original f4f2, guest PC 0x0c03c3e8 */
if(!s->budget--) { s->failed_pc=0x0c03c3e8u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[15],r[18],'*');
goto P_0c03c3ea;
P_0c03c3ea: /* original f3e8, guest PC 0x0c03c3ea */
if(!s->budget--) { s->failed_pc=0x0c03c3eau; return 0; }
vf3_matrix_load(s,ram,3,r[14]);
goto P_0c03c3ec;
P_0c03c3ec: /* original e03c, guest PC 0x0c03c3ec */
if(!s->budget--) { s->failed_pc=0x0c03c3ecu; return 0; }
r[0]=0x0000003cu;
goto P_0c03c3ee;
P_0c03c3ee: /* original 64f3, guest PC 0x0c03c3ee */
if(!s->budget--) { s->failed_pc=0x0c03c3eeu; return 0; }
r[4]=r[15];
goto P_0c03c3f0;
P_0c03c3f0: /* original f342, guest PC 0x0c03c3f0 */
if(!s->budget--) { s->failed_pc=0x0c03c3f0u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'*');
goto P_0c03c3f2;
P_0c03c3f2: /* original ff37, guest PC 0x0c03c3f2 */
if(!s->budget--) { s->failed_pc=0x0c03c3f2u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c03c3f4;
P_0c03c3f4: /* original e004, guest PC 0x0c03c3f4 */
if(!s->budget--) { s->failed_pc=0x0c03c3f4u; return 0; }
r[0]=0x00000004u;
goto P_0c03c3f6;
P_0c03c3f6: /* original f3e6, guest PC 0x0c03c3f6 */
if(!s->budget--) { s->failed_pc=0x0c03c3f6u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c03c3f8;
P_0c03c3f8: /* original e040, guest PC 0x0c03c3f8 */
if(!s->budget--) { s->failed_pc=0x0c03c3f8u; return 0; }
r[0]=0x00000040u;
goto P_0c03c3fa;
P_0c03c3fa: /* original f342, guest PC 0x0c03c3fa */
if(!s->budget--) { s->failed_pc=0x0c03c3fau; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'*');
goto P_0c03c3fc;
P_0c03c3fc: /* original ff37, guest PC 0x0c03c3fc */
if(!s->budget--) { s->failed_pc=0x0c03c3fcu; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c03c3fe;
P_0c03c3fe: /* original e008, guest PC 0x0c03c3fe */
if(!s->budget--) { s->failed_pc=0x0c03c3feu; return 0; }
r[0]=0x00000008u;
goto P_0c03c400;
P_0c03c400: /* original f3e6, guest PC 0x0c03c400 */
if(!s->budget--) { s->failed_pc=0x0c03c400u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c03c402;
P_0c03c402: /* original e044, guest PC 0x0c03c402 */
if(!s->budget--) { s->failed_pc=0x0c03c402u; return 0; }
r[0]=0x00000044u;
goto P_0c03c404;
P_0c03c404: /* original f342, guest PC 0x0c03c404 */
if(!s->budget--) { s->failed_pc=0x0c03c404u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'*');
goto P_0c03c406;
P_0c03c406: /* original ff37, guest PC 0x0c03c406 */
if(!s->budget--) { s->failed_pc=0x0c03c406u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c03c408;
P_0c03c408: /* original e018, guest PC 0x0c03c408 */
if(!s->budget--) { s->failed_pc=0x0c03c408u; return 0; }
r[0]=0x00000018u;
goto P_0c03c40a;
P_0c03c40a: /* original f48d, guest PC 0x0c03c40a */
if(!s->budget--) { s->failed_pc=0x0c03c40au; return 0; }
fr[4]=0;
goto P_0c03c40c;
P_0c03c40c: /* original ff47, guest PC 0x0c03c40c */
if(!s->budget--) { s->failed_pc=0x0c03c40cu; return 0; }
vf3_matrix_store(s,ram,4,r[15]+r[0]);
goto P_0c03c40e;
P_0c03c40e: /* original e028, guest PC 0x0c03c40e */
if(!s->budget--) { s->failed_pc=0x0c03c40eu; return 0; }
r[0]=0x00000028u;
goto P_0c03c410;
P_0c03c410: /* original ff47, guest PC 0x0c03c410 */
if(!s->budget--) { s->failed_pc=0x0c03c410u; return 0; }
vf3_matrix_store(s,ram,4,r[15]+r[0]);
goto P_0c03c412;
P_0c03c412: /* original e038, guest PC 0x0c03c412 */
if(!s->budget--) { s->failed_pc=0x0c03c412u; return 0; }
r[0]=0x00000038u;
goto P_0c03c414;
P_0c03c414: /* original ff47, guest PC 0x0c03c414 */
if(!s->budget--) { s->failed_pc=0x0c03c414u; return 0; }
vf3_matrix_store(s,ram,4,r[15]+r[0]);
goto P_0c03c416;
P_0c03c416: /* original e048, guest PC 0x0c03c416 */
if(!s->budget--) { s->failed_pc=0x0c03c416u; return 0; }
r[0]=0x00000048u;
goto P_0c03c418;
P_0c03c418: /* original ffe7, guest PC 0x0c03c418 */
if(!s->budget--) { s->failed_pc=0x0c03c418u; return 0; }
vf3_matrix_store(s,ram,14,r[15]+r[0]);
goto P_0c03c41a;
P_0c03c41a: /* original d311, guest PC 0x0c03c41a */
if(!s->budget--) { s->failed_pc=0x0c03c41au; return 0; }
r[3]=read(ram,0x0c03c460u,4);
goto P_0c03c41c;
P_0c03c41c: /* original 430b, guest PC 0x0c03c41c */
if(!s->budget--) { s->failed_pc=0x0c03c41cu; return 0; }
target=r[3];
r[16]=0x0c03c420u;
r[4]+=0x0000000cu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c03c420u) { target=s->pc; goto dispatch; }
goto P_0c03c420;
P_0c03c41e: /* original 740c, guest PC 0x0c03c41e */
if(!s->budget--) { s->failed_pc=0x0c03c41eu; return 0; }
r[4]+=0x0000000cu;
goto P_0c03c420;
P_0c03c420: /* original d210, guest PC 0x0c03c420 */
if(!s->budget--) { s->failed_pc=0x0c03c420u; return 0; }
r[2]=read(ram,0x0c03c464u,4);
goto P_0c03c422;
P_0c03c422: /* original 420b, guest PC 0x0c03c422 */
if(!s->budget--) { s->failed_pc=0x0c03c422u; return 0; }
target=r[2];
r[16]=0x0c03c426u;
r[4]=r[12];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c03c426u) { target=s->pc; goto dispatch; }
goto P_0c03c426;
P_0c03c424: /* original 64c3, guest PC 0x0c03c424 */
if(!s->budget--) { s->failed_pc=0x0c03c424u; return 0; }
r[4]=r[12];
goto P_0c03c426;
P_0c03c426: /* original 7f4c, guest PC 0x0c03c426 */
if(!s->budget--) { s->failed_pc=0x0c03c426u; return 0; }
r[15]+=0x0000004cu;
goto P_0c03c428;
P_0c03c428: /* original 4f26, guest PC 0x0c03c428 */
if(!s->budget--) { s->failed_pc=0x0c03c428u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c03c42a;
P_0c03c42a: /* original fef9, guest PC 0x0c03c42a */
if(!s->budget--) { s->failed_pc=0x0c03c42au; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c03c42c;
P_0c03c42c: /* original fff9, guest PC 0x0c03c42c */
if(!s->budget--) { s->failed_pc=0x0c03c42cu; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c03c42e;
P_0c03c42e: /* original 6cf6, guest PC 0x0c03c42e */
if(!s->budget--) { s->failed_pc=0x0c03c42eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c03c430;
P_0c03c430: /* original 6df6, guest PC 0x0c03c430 */
if(!s->budget--) { s->failed_pc=0x0c03c430u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c03c432;
P_0c03c432: /* original 000b, guest PC 0x0c03c432 */
if(!s->budget--) { s->failed_pc=0x0c03c432u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c03c434: /* original 6ef6, guest PC 0x0c03c434 */
if(!s->budget--) { s->failed_pc=0x0c03c434u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c03c436u,s,ram);
P_0c03c6f0: /* original f15c, guest PC 0x0c03c6f0 */
if(!s->budget--) { s->failed_pc=0x0c03c6f0u; return 0; }
vf3_matrix_move(s,1,5);
goto P_0c03c6f2;
P_0c03c6f2: /* original f24c, guest PC 0x0c03c6f2 */
if(!s->budget--) { s->failed_pc=0x0c03c6f2u; return 0; }
vf3_matrix_move(s,2,4);
goto P_0c03c6f4;
P_0c03c6f4: /* original f08d, guest PC 0x0c03c6f4 */
if(!s->budget--) { s->failed_pc=0x0c03c6f4u; return 0; }
fr[0]=0;
goto P_0c03c6f6;
P_0c03c6f6: /* original f38d, guest PC 0x0c03c6f6 */
if(!s->budget--) { s->failed_pc=0x0c03c6f6u; return 0; }
fr[3]=0;
goto P_0c03c6f8;
P_0c03c6f8: /* original f65c, guest PC 0x0c03c6f8 */
if(!s->budget--) { s->failed_pc=0x0c03c6f8u; return 0; }
vf3_matrix_move(s,6,5);
goto P_0c03c6fa;
P_0c03c6fa: /* original f54c, guest PC 0x0c03c6fa */
if(!s->budget--) { s->failed_pc=0x0c03c6fau; return 0; }
vf3_matrix_move(s,5,4);
goto P_0c03c6fc;
P_0c03c6fc: /* original f54d, guest PC 0x0c03c6fc */
if(!s->budget--) { s->failed_pc=0x0c03c6fcu; return 0; }
fr[5]^=0x80000000u;
goto P_0c03c6fe;
P_0c03c6fe: /* original f1fd, guest PC 0x0c03c6fe */
if(!s->budget--) { s->failed_pc=0x0c03c6feu; return 0; }
if(!vf3_fpu_ftrv(xf,fr+0,r[18],fr+0)) goto unsupported;
goto P_0c03c700;
P_0c03c700: /* original f48d, guest PC 0x0c03c700 */
if(!s->budget--) { s->failed_pc=0x0c03c700u; return 0; }
fr[4]=0;
goto P_0c03c702;
P_0c03c702: /* original f78d, guest PC 0x0c03c702 */
if(!s->budget--) { s->failed_pc=0x0c03c702u; return 0; }
fr[7]=0;
goto P_0c03c704;
P_0c03c704: /* original f5fd, guest PC 0x0c03c704 */
if(!s->budget--) { s->failed_pc=0x0c03c704u; return 0; }
if(!vf3_fpu_ftrv(xf,fr+4,r[18],fr+4)) goto unsupported;
goto P_0c03c706;
P_0c03c706: /* original f3fd, guest PC 0x0c03c706 */
if(!s->budget--) { s->failed_pc=0x0c03c706u; return 0; }
r[18]^=0x100000u;
goto P_0c03c708;
P_0c03c708: /* original f50c, guest PC 0x0c03c708 */
if(!s->budget--) { s->failed_pc=0x0c03c708u; return 0; }
vf3_matrix_move(s,5,0);
goto P_0c03c70a;
P_0c03c70a: /* original f72c, guest PC 0x0c03c70a */
if(!s->budget--) { s->failed_pc=0x0c03c70au; return 0; }
vf3_matrix_move(s,7,2);
goto P_0c03c70c;
P_0c03c70c: /* original f94c, guest PC 0x0c03c70c */
if(!s->budget--) { s->failed_pc=0x0c03c70cu; return 0; }
vf3_matrix_move(s,9,4);
goto P_0c03c70e;
P_0c03c70e: /* original fb6c, guest PC 0x0c03c70e */
if(!s->budget--) { s->failed_pc=0x0c03c70eu; return 0; }
vf3_matrix_move(s,11,6);
goto P_0c03c710;
P_0c03c710: /* original f3fd, guest PC 0x0c03c710 */
if(!s->budget--) { s->failed_pc=0x0c03c710u; return 0; }
r[18]^=0x100000u;
goto P_0c03c712;
P_0c03c712: /* original 0009, guest PC 0x0c03c712 */
if(!s->budget--) { s->failed_pc=0x0c03c712u; return 0; }
goto P_0c03c714;
P_0c03c714: /* original 000b, guest PC 0x0c03c714 */
if(!s->budget--) { s->failed_pc=0x0c03c714u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c03c716: /* original 0009, guest PC 0x0c03c716 */
if(!s->budget--) { s->failed_pc=0x0c03c716u; return 0; }
return vf3_matrix_family(0x0c03c718u,s,ram);
P_0c03cc70: /* original 2fe6, guest PC 0x0c03cc70 */
if(!s->budget--) { s->failed_pc=0x0c03cc70u; return 0; }
r[15]-=4; write(ram,r[15],r[14],4);
goto P_0c03cc72;
P_0c03cc72: /* original e008, guest PC 0x0c03cc72 */
if(!s->budget--) { s->failed_pc=0x0c03cc72u; return 0; }
r[0]=0x00000008u;
goto P_0c03cc74;
P_0c03cc74: /* original 6e43, guest PC 0x0c03cc74 */
if(!s->budget--) { s->failed_pc=0x0c03cc74u; return 0; }
r[14]=r[4];
goto P_0c03cc76;
P_0c03cc76: /* original f6e6, guest PC 0x0c03cc76 */
if(!s->budget--) { s->failed_pc=0x0c03cc76u; return 0; }
vf3_matrix_load(s,ram,6,r[14]+r[0]);
goto P_0c03cc78;
P_0c03cc78: /* original e004, guest PC 0x0c03cc78 */
if(!s->budget--) { s->failed_pc=0x0c03cc78u; return 0; }
r[0]=0x00000004u;
goto P_0c03cc7a;
P_0c03cc7a: /* original f4e8, guest PC 0x0c03cc7a */
if(!s->budget--) { s->failed_pc=0x0c03cc7au; return 0; }
vf3_matrix_load(s,ram,4,r[14]);
goto P_0c03cc7c;
P_0c03cc7c: /* original f5e6, guest PC 0x0c03cc7c */
if(!s->budget--) { s->failed_pc=0x0c03cc7cu; return 0; }
vf3_matrix_load(s,ram,5,r[14]+r[0]);
goto P_0c03cc7e;
P_0c03cc7e: /* original d309, guest PC 0x0c03cc7e */
if(!s->budget--) { s->failed_pc=0x0c03cc7eu; return 0; }
r[3]=read(ram,0x0c03cca4u,4);
goto P_0c03cc80;
P_0c03cc80: /* original f44d, guest PC 0x0c03cc80 */
if(!s->budget--) { s->failed_pc=0x0c03cc80u; return 0; }
fr[4]^=0x80000000u;
goto P_0c03cc82;
P_0c03cc82: /* original f64d, guest PC 0x0c03cc82 */
if(!s->budget--) { s->failed_pc=0x0c03cc82u; return 0; }
fr[6]^=0x80000000u;
goto P_0c03cc84;
P_0c03cc84: /* original f54d, guest PC 0x0c03cc84 */
if(!s->budget--) { s->failed_pc=0x0c03cc84u; return 0; }
fr[5]^=0x80000000u;
goto P_0c03cc86;
P_0c03cc86: /* original 432b, guest PC 0x0c03cc86 */
if(!s->budget--) { s->failed_pc=0x0c03cc86u; return 0; }
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
P_0c03cc88: /* original 6ef6, guest PC 0x0c03cc88 */
if(!s->budget--) { s->failed_pc=0x0c03cc88u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c03cc8au,s,ram);
P_0c03d0e8: /* original 4f22, guest PC 0x0c03d0e8 */
if(!s->budget--) { s->failed_pc=0x0c03d0e8u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c03d0ea;
P_0c03d0ea: /* original f232, guest PC 0x0c03d0ea */
if(!s->budget--) { s->failed_pc=0x0c03d0eau; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c03d0ec;
P_0c03d0ec: /* original 7fb8, guest PC 0x0c03d0ec */
if(!s->budget--) { s->failed_pc=0x0c03d0ecu; return 0; }
r[15]+=0xffffffb8u;
goto P_0c03d0ee;
P_0c03d0ee: /* original ff2a, guest PC 0x0c03d0ee */
if(!s->budget--) { s->failed_pc=0x0c03d0eeu; return 0; }
vf3_matrix_store(s,ram,2,r[15]);
goto P_0c03d0f0;
P_0c03d0f0: /* original fb5c, guest PC 0x0c03d0f0 */
if(!s->budget--) { s->failed_pc=0x0c03d0f0u; return 0; }
vf3_matrix_move(s,11,5);
goto P_0c03d0f2;
P_0c03d0f2: /* original fb41, guest PC 0x0c03d0f2 */
if(!s->budget--) { s->failed_pc=0x0c03d0f2u; return 0; }
fr[11]=vf3_fpu_binary(fr[11],fr[4],r[18],'-');
goto P_0c03d0f4;
P_0c03d0f4: /* original f12c, guest PC 0x0c03d0f4 */
if(!s->budget--) { s->failed_pc=0x0c03d0f4u; return 0; }
vf3_matrix_move(s,1,2);
goto P_0c03d0f6;
P_0c03d0f6: /* original f1b3, guest PC 0x0c03d0f6 */
if(!s->budget--) { s->failed_pc=0x0c03d0f6u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[11],r[18],'/');
goto P_0c03d0f8;
P_0c03d0f8: /* original ff17, guest PC 0x0c03d0f8 */
if(!s->budget--) { s->failed_pc=0x0c03d0f8u; return 0; }
vf3_matrix_store(s,ram,1,r[15]+r[0]);
goto P_0c03d0fa;
P_0c03d0fa: /* original e00c, guest PC 0x0c03d0fa */
if(!s->budget--) { s->failed_pc=0x0c03d0fau; return 0; }
r[0]=0x0000000cu;
goto P_0c03d0fc;
P_0c03d0fc: /* original fa8d, guest PC 0x0c03d0fc */
if(!s->budget--) { s->failed_pc=0x0c03d0fcu; return 0; }
fr[10]=0;
goto P_0c03d0fe;
P_0c03d0fe: /* original ffa7, guest PC 0x0c03d0fe */
if(!s->budget--) { s->failed_pc=0x0c03d0feu; return 0; }
vf3_matrix_store(s,ram,10,r[15]+r[0]);
goto P_0c03d100;
P_0c03d100: /* original e010, guest PC 0x0c03d100 */
if(!s->budget--) { s->failed_pc=0x0c03d100u; return 0; }
r[0]=0x00000010u;
goto P_0c03d102;
P_0c03d102: /* original ffa7, guest PC 0x0c03d102 */
if(!s->budget--) { s->failed_pc=0x0c03d102u; return 0; }
vf3_matrix_store(s,ram,10,r[15]+r[0]);
goto P_0c03d104;
P_0c03d104: /* original e014, guest PC 0x0c03d104 */
if(!s->budget--) { s->failed_pc=0x0c03d104u; return 0; }
r[0]=0x00000014u;
goto P_0c03d106;
P_0c03d106: /* original ffa7, guest PC 0x0c03d106 */
if(!s->budget--) { s->failed_pc=0x0c03d106u; return 0; }
vf3_matrix_store(s,ram,10,r[15]+r[0]);
goto P_0c03d108;
P_0c03d108: /* original e018, guest PC 0x0c03d108 */
if(!s->budget--) { s->failed_pc=0x0c03d108u; return 0; }
r[0]=0x00000018u;
goto P_0c03d10a;
P_0c03d10a: /* original ffa7, guest PC 0x0c03d10a */
if(!s->budget--) { s->failed_pc=0x0c03d10au; return 0; }
vf3_matrix_store(s,ram,10,r[15]+r[0]);
goto P_0c03d10c;
P_0c03d10c: /* original e004, guest PC 0x0c03d10c */
if(!s->budget--) { s->failed_pc=0x0c03d10cu; return 0; }
r[0]=0x00000004u;
goto P_0c03d10e;
P_0c03d10e: /* original f27c, guest PC 0x0c03d10e */
if(!s->budget--) { s->failed_pc=0x0c03d10eu; return 0; }
vf3_matrix_move(s,2,7);
goto P_0c03d110;
P_0c03d110: /* original f261, guest PC 0x0c03d110 */
if(!s->budget--) { s->failed_pc=0x0c03d110u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[6],r[18],'-');
goto P_0c03d112;
P_0c03d112: /* original ff27, guest PC 0x0c03d112 */
if(!s->budget--) { s->failed_pc=0x0c03d112u; return 0; }
vf3_matrix_store(s,ram,2,r[15]+r[0]);
goto P_0c03d114;
P_0c03d114: /* original e01c, guest PC 0x0c03d114 */
if(!s->budget--) { s->failed_pc=0x0c03d114u; return 0; }
r[0]=0x0000001cu;
goto P_0c03d116;
P_0c03d116: /* original f1f8, guest PC 0x0c03d116 */
if(!s->budget--) { s->failed_pc=0x0c03d116u; return 0; }
vf3_matrix_load(s,ram,1,r[15]);
goto P_0c03d118;
P_0c03d118: /* original f123, guest PC 0x0c03d118 */
if(!s->budget--) { s->failed_pc=0x0c03d118u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[2],r[18],'/');
goto P_0c03d11a;
P_0c03d11a: /* original ff17, guest PC 0x0c03d11a */
if(!s->budget--) { s->failed_pc=0x0c03d11au; return 0; }
vf3_matrix_store(s,ram,1,r[15]+r[0]);
goto P_0c03d11c;
P_0c03d11c: /* original e020, guest PC 0x0c03d11c */
if(!s->budget--) { s->failed_pc=0x0c03d11cu; return 0; }
r[0]=0x00000020u;
goto P_0c03d11e;
P_0c03d11e: /* original ffa7, guest PC 0x0c03d11e */
if(!s->budget--) { s->failed_pc=0x0c03d11eu; return 0; }
vf3_matrix_store(s,ram,10,r[15]+r[0]);
goto P_0c03d120;
P_0c03d120: /* original f450, guest PC 0x0c03d120 */
if(!s->budget--) { s->failed_pc=0x0c03d120u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[5],r[18],'+');
goto P_0c03d122;
P_0c03d122: /* original e024, guest PC 0x0c03d122 */
if(!s->budget--) { s->failed_pc=0x0c03d122u; return 0; }
r[0]=0x00000024u;
goto P_0c03d124;
P_0c03d124: /* original ffa7, guest PC 0x0c03d124 */
if(!s->budget--) { s->failed_pc=0x0c03d124u; return 0; }
vf3_matrix_store(s,ram,10,r[15]+r[0]);
goto P_0c03d126;
P_0c03d126: /* original e028, guest PC 0x0c03d126 */
if(!s->budget--) { s->failed_pc=0x0c03d126u; return 0; }
r[0]=0x00000028u;
goto P_0c03d128;
P_0c03d128: /* original f670, guest PC 0x0c03d128 */
if(!s->budget--) { s->failed_pc=0x0c03d128u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[7],r[18],'+');
goto P_0c03d12a;
P_0c03d12a: /* original f4b3, guest PC 0x0c03d12a */
if(!s->budget--) { s->failed_pc=0x0c03d12au; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[11],r[18],'/');
goto P_0c03d12c;
P_0c03d12c: /* original ff47, guest PC 0x0c03d12c */
if(!s->budget--) { s->failed_pc=0x0c03d12cu; return 0; }
vf3_matrix_store(s,ram,4,r[15]+r[0]);
goto P_0c03d12e;
P_0c03d12e: /* original e004, guest PC 0x0c03d12e */
if(!s->budget--) { s->failed_pc=0x0c03d12eu; return 0; }
r[0]=0x00000004u;
goto P_0c03d130;
P_0c03d130: /* original f2f6, guest PC 0x0c03d130 */
if(!s->budget--) { s->failed_pc=0x0c03d130u; return 0; }
vf3_matrix_load(s,ram,2,r[15]+r[0]);
goto P_0c03d132;
P_0c03d132: /* original e02c, guest PC 0x0c03d132 */
if(!s->budget--) { s->failed_pc=0x0c03d132u; return 0; }
r[0]=0x0000002cu;
goto P_0c03d134;
P_0c03d134: /* original f623, guest PC 0x0c03d134 */
if(!s->budget--) { s->failed_pc=0x0c03d134u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[2],r[18],'/');
goto P_0c03d136;
P_0c03d136: /* original ff67, guest PC 0x0c03d136 */
if(!s->budget--) { s->failed_pc=0x0c03d136u; return 0; }
vf3_matrix_store(s,ram,6,r[15]+r[0]);
goto P_0c03d138;
P_0c03d138: /* original e030, guest PC 0x0c03d138 */
if(!s->budget--) { s->failed_pc=0x0c03d138u; return 0; }
r[0]=0x00000030u;
goto P_0c03d13a;
P_0c03d13a: /* original f48c, guest PC 0x0c03d13a */
if(!s->budget--) { s->failed_pc=0x0c03d13au; return 0; }
vf3_matrix_move(s,4,8);
goto P_0c03d13c;
P_0c03d13c: /* original f44d, guest PC 0x0c03d13c */
if(!s->budget--) { s->failed_pc=0x0c03d13cu; return 0; }
fr[4]^=0x80000000u;
goto P_0c03d13e;
P_0c03d13e: /* original f24c, guest PC 0x0c03d13e */
if(!s->budget--) { s->failed_pc=0x0c03d13eu; return 0; }
vf3_matrix_move(s,2,4);
goto P_0c03d140;
P_0c03d140: /* original f291, guest PC 0x0c03d140 */
if(!s->budget--) { s->failed_pc=0x0c03d140u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[9],r[18],'-');
goto P_0c03d142;
P_0c03d142: /* original f59c, guest PC 0x0c03d142 */
if(!s->budget--) { s->failed_pc=0x0c03d142u; return 0; }
vf3_matrix_move(s,5,9);
goto P_0c03d144;
P_0c03d144: /* original f581, guest PC 0x0c03d144 */
if(!s->budget--) { s->failed_pc=0x0c03d144u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[8],r[18],'-');
goto P_0c03d146;
P_0c03d146: /* original f253, guest PC 0x0c03d146 */
if(!s->budget--) { s->failed_pc=0x0c03d146u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'/');
goto P_0c03d148;
P_0c03d148: /* original ff27, guest PC 0x0c03d148 */
if(!s->budget--) { s->failed_pc=0x0c03d148u; return 0; }
vf3_matrix_store(s,ram,2,r[15]+r[0]);
goto P_0c03d14a;
P_0c03d14a: /* original c788, guest PC 0x0c03d14a */
if(!s->budget--) { s->failed_pc=0x0c03d14au; return 0; }
r[0]=0x0c03d36cu;
goto P_0c03d14c;
P_0c03d14c: /* original f208, guest PC 0x0c03d14c */
if(!s->budget--) { s->failed_pc=0x0c03d14cu; return 0; }
vf3_matrix_load(s,ram,2,r[0]);
goto P_0c03d14e;
P_0c03d14e: /* original e034, guest PC 0x0c03d14e */
if(!s->budget--) { s->failed_pc=0x0c03d14eu; return 0; }
r[0]=0x00000034u;
goto P_0c03d150;
P_0c03d150: /* original ff27, guest PC 0x0c03d150 */
if(!s->budget--) { s->failed_pc=0x0c03d150u; return 0; }
vf3_matrix_store(s,ram,2,r[15]+r[0]);
goto P_0c03d152;
P_0c03d152: /* original e038, guest PC 0x0c03d152 */
if(!s->budget--) { s->failed_pc=0x0c03d152u; return 0; }
r[0]=0x00000038u;
goto P_0c03d154;
P_0c03d154: /* original ffa7, guest PC 0x0c03d154 */
if(!s->budget--) { s->failed_pc=0x0c03d154u; return 0; }
vf3_matrix_store(s,ram,10,r[15]+r[0]);
goto P_0c03d156;
P_0c03d156: /* original e03c, guest PC 0x0c03d156 */
if(!s->budget--) { s->failed_pc=0x0c03d156u; return 0; }
r[0]=0x0000003cu;
goto P_0c03d158;
P_0c03d158: /* original ffa7, guest PC 0x0c03d158 */
if(!s->budget--) { s->failed_pc=0x0c03d158u; return 0; }
vf3_matrix_store(s,ram,10,r[15]+r[0]);
goto P_0c03d15a;
P_0c03d15a: /* original f28c, guest PC 0x0c03d15a */
if(!s->budget--) { s->failed_pc=0x0c03d15au; return 0; }
vf3_matrix_move(s,2,8);
goto P_0c03d15c;
P_0c03d15c: /* original f292, guest PC 0x0c03d15c */
if(!s->budget--) { s->failed_pc=0x0c03d15cu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[9],r[18],'*');
goto P_0c03d15e;
P_0c03d15e: /* original f232, guest PC 0x0c03d15e */
if(!s->budget--) { s->failed_pc=0x0c03d15eu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c03d160;
P_0c03d160: /* original f24d, guest PC 0x0c03d160 */
if(!s->budget--) { s->failed_pc=0x0c03d160u; return 0; }
fr[2]^=0x80000000u;
goto P_0c03d162;
P_0c03d162: /* original f253, guest PC 0x0c03d162 */
if(!s->budget--) { s->failed_pc=0x0c03d162u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'/');
goto P_0c03d164;
P_0c03d164: /* original e040, guest PC 0x0c03d164 */
if(!s->budget--) { s->failed_pc=0x0c03d164u; return 0; }
r[0]=0x00000040u;
goto P_0c03d166;
P_0c03d166: /* original ff27, guest PC 0x0c03d166 */
if(!s->budget--) { s->failed_pc=0x0c03d166u; return 0; }
vf3_matrix_store(s,ram,2,r[15]+r[0]);
goto P_0c03d168;
P_0c03d168: /* original e044, guest PC 0x0c03d168 */
if(!s->budget--) { s->failed_pc=0x0c03d168u; return 0; }
r[0]=0x00000044u;
goto P_0c03d16a;
P_0c03d16a: /* original ffa7, guest PC 0x0c03d16a */
if(!s->budget--) { s->failed_pc=0x0c03d16au; return 0; }
vf3_matrix_store(s,ram,10,r[15]+r[0]);
goto P_0c03d16c;
P_0c03d16c: /* original e01c, guest PC 0x0c03d16c */
if(!s->budget--) { s->failed_pc=0x0c03d16cu; return 0; }
r[0]=0x0000001cu;
goto P_0c03d16e;
P_0c03d16e: /* original d480, guest PC 0x0c03d16e */
if(!s->budget--) { s->failed_pc=0x0c03d16eu; return 0; }
r[4]=read(ram,0x0c03d370u,4);
goto P_0c03d170;
P_0c03d170: /* original f487, guest PC 0x0c03d170 */
if(!s->budget--) { s->failed_pc=0x0c03d170u; return 0; }
vf3_matrix_store(s,ram,8,r[4]+r[0]);
goto P_0c03d172;
P_0c03d172: /* original e020, guest PC 0x0c03d172 */
if(!s->budget--) { s->failed_pc=0x0c03d172u; return 0; }
r[0]=0x00000020u;
goto P_0c03d174;
P_0c03d174: /* original f497, guest PC 0x0c03d174 */
if(!s->budget--) { s->failed_pc=0x0c03d174u; return 0; }
vf3_matrix_store(s,ram,9,r[4]+r[0]);
goto P_0c03d176;
P_0c03d176: /* original e024, guest PC 0x0c03d176 */
if(!s->budget--) { s->failed_pc=0x0c03d176u; return 0; }
r[0]=0x00000024u;
goto P_0c03d178;
P_0c03d178: /* original f59d, guest PC 0x0c03d178 */
if(!s->budget--) { s->failed_pc=0x0c03d178u; return 0; }
fr[5]=0x3f800000u;
goto P_0c03d17a;
P_0c03d17a: /* original f583, guest PC 0x0c03d17a */
if(!s->budget--) { s->failed_pc=0x0c03d17au; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[8],r[18],'/');
goto P_0c03d17c;
P_0c03d17c: /* original f457, guest PC 0x0c03d17c */
if(!s->budget--) { s->failed_pc=0x0c03d17cu; return 0; }
vf3_matrix_store(s,ram,5,r[4]+r[0]);
goto P_0c03d17e;
P_0c03d17e: /* original d47d, guest PC 0x0c03d17e */
if(!s->budget--) { s->failed_pc=0x0c03d17eu; return 0; }
r[4]=read(ram,0x0c03d374u,4);
goto P_0c03d180;
P_0c03d180: /* original f487, guest PC 0x0c03d180 */
if(!s->budget--) { s->failed_pc=0x0c03d180u; return 0; }
vf3_matrix_store(s,ram,8,r[4]+r[0]);
goto P_0c03d182;
P_0c03d182: /* original e00c, guest PC 0x0c03d182 */
if(!s->budget--) { s->failed_pc=0x0c03d182u; return 0; }
r[0]=0x0000000cu;
goto P_0c03d184;
P_0c03d184: /* original f447, guest PC 0x0c03d184 */
if(!s->budget--) { s->failed_pc=0x0c03d184u; return 0; }
vf3_matrix_store(s,ram,4,r[4]+r[0]);
goto P_0c03d186;
P_0c03d186: /* original e028, guest PC 0x0c03d186 */
if(!s->budget--) { s->failed_pc=0x0c03d186u; return 0; }
r[0]=0x00000028u;
goto P_0c03d188;
P_0c03d188: /* original f497, guest PC 0x0c03d188 */
if(!s->budget--) { s->failed_pc=0x0c03d188u; return 0; }
vf3_matrix_store(s,ram,9,r[4]+r[0]);
goto P_0c03d18a;
P_0c03d18a: /* original e020, guest PC 0x0c03d18a */
if(!s->budget--) { s->failed_pc=0x0c03d18au; return 0; }
r[0]=0x00000020u;
goto P_0c03d18c;
P_0c03d18c: /* original f457, guest PC 0x0c03d18c */
if(!s->budget--) { s->failed_pc=0x0c03d18cu; return 0; }
vf3_matrix_store(s,ram,5,r[4]+r[0]);
goto P_0c03d18e;
P_0c03d18e: /* original 64f3, guest PC 0x0c03d18e */
if(!s->budget--) { s->failed_pc=0x0c03d18eu; return 0; }
r[4]=r[15];
goto P_0c03d190;
P_0c03d190: /* original d379, guest PC 0x0c03d190 */
if(!s->budget--) { s->failed_pc=0x0c03d190u; return 0; }
r[3]=read(ram,0x0c03d378u,4);
goto P_0c03d192;
P_0c03d192: /* original 430b, guest PC 0x0c03d192 */
if(!s->budget--) { s->failed_pc=0x0c03d192u; return 0; }
target=r[3];
r[16]=0x0c03d196u;
r[4]+=0x00000008u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c03d196u) { target=s->pc; goto dispatch; }
goto P_0c03d196;
P_0c03d194: /* original 7408, guest PC 0x0c03d194 */
if(!s->budget--) { s->failed_pc=0x0c03d194u; return 0; }
r[4]+=0x00000008u;
goto P_0c03d196;
P_0c03d196: /* original 7f48, guest PC 0x0c03d196 */
if(!s->budget--) { s->failed_pc=0x0c03d196u; return 0; }
r[15]+=0x00000048u;
goto P_0c03d198;
P_0c03d198: /* original 4f26, guest PC 0x0c03d198 */
if(!s->budget--) { s->failed_pc=0x0c03d198u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c03d19a;
P_0c03d19a: /* original 000b, guest PC 0x0c03d19a */
if(!s->budget--) { s->failed_pc=0x0c03d19au; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c03d19c: /* original 0009, guest PC 0x0c03d19c */
if(!s->budget--) { s->failed_pc=0x0c03d19cu; return 0; }
return vf3_matrix_family(0x0c03d19eu,s,ram);
P_0c03d1a8: /* original 4f22, guest PC 0x0c03d1a8 */
if(!s->budget--) { s->failed_pc=0x0c03d1a8u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c03d1aa;
P_0c03d1aa: /* original f232, guest PC 0x0c03d1aa */
if(!s->budget--) { s->failed_pc=0x0c03d1aau; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c03d1ac;
P_0c03d1ac: /* original 7fb8, guest PC 0x0c03d1ac */
if(!s->budget--) { s->failed_pc=0x0c03d1acu; return 0; }
r[15]+=0xffffffb8u;
goto P_0c03d1ae;
P_0c03d1ae: /* original ff2a, guest PC 0x0c03d1ae */
if(!s->budget--) { s->failed_pc=0x0c03d1aeu; return 0; }
vf3_matrix_store(s,ram,2,r[15]);
goto P_0c03d1b0;
P_0c03d1b0: /* original fb5c, guest PC 0x0c03d1b0 */
if(!s->budget--) { s->failed_pc=0x0c03d1b0u; return 0; }
vf3_matrix_move(s,11,5);
goto P_0c03d1b2;
P_0c03d1b2: /* original fb41, guest PC 0x0c03d1b2 */
if(!s->budget--) { s->failed_pc=0x0c03d1b2u; return 0; }
fr[11]=vf3_fpu_binary(fr[11],fr[4],r[18],'-');
goto P_0c03d1b4;
P_0c03d1b4: /* original f12c, guest PC 0x0c03d1b4 */
if(!s->budget--) { s->failed_pc=0x0c03d1b4u; return 0; }
vf3_matrix_move(s,1,2);
goto P_0c03d1b6;
P_0c03d1b6: /* original f1b3, guest PC 0x0c03d1b6 */
if(!s->budget--) { s->failed_pc=0x0c03d1b6u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[11],r[18],'/');
goto P_0c03d1b8;
P_0c03d1b8: /* original ff17, guest PC 0x0c03d1b8 */
if(!s->budget--) { s->failed_pc=0x0c03d1b8u; return 0; }
vf3_matrix_store(s,ram,1,r[15]+r[0]);
goto P_0c03d1ba;
P_0c03d1ba: /* original e00c, guest PC 0x0c03d1ba */
if(!s->budget--) { s->failed_pc=0x0c03d1bau; return 0; }
r[0]=0x0000000cu;
goto P_0c03d1bc;
P_0c03d1bc: /* original fa8d, guest PC 0x0c03d1bc */
if(!s->budget--) { s->failed_pc=0x0c03d1bcu; return 0; }
fr[10]=0;
goto P_0c03d1be;
P_0c03d1be: /* original ffa7, guest PC 0x0c03d1be */
if(!s->budget--) { s->failed_pc=0x0c03d1beu; return 0; }
vf3_matrix_store(s,ram,10,r[15]+r[0]);
goto P_0c03d1c0;
P_0c03d1c0: /* original e010, guest PC 0x0c03d1c0 */
if(!s->budget--) { s->failed_pc=0x0c03d1c0u; return 0; }
r[0]=0x00000010u;
goto P_0c03d1c2;
P_0c03d1c2: /* original ffa7, guest PC 0x0c03d1c2 */
if(!s->budget--) { s->failed_pc=0x0c03d1c2u; return 0; }
vf3_matrix_store(s,ram,10,r[15]+r[0]);
goto P_0c03d1c4;
P_0c03d1c4: /* original e014, guest PC 0x0c03d1c4 */
if(!s->budget--) { s->failed_pc=0x0c03d1c4u; return 0; }
r[0]=0x00000014u;
goto P_0c03d1c6;
P_0c03d1c6: /* original ffa7, guest PC 0x0c03d1c6 */
if(!s->budget--) { s->failed_pc=0x0c03d1c6u; return 0; }
vf3_matrix_store(s,ram,10,r[15]+r[0]);
goto P_0c03d1c8;
P_0c03d1c8: /* original e018, guest PC 0x0c03d1c8 */
if(!s->budget--) { s->failed_pc=0x0c03d1c8u; return 0; }
r[0]=0x00000018u;
goto P_0c03d1ca;
P_0c03d1ca: /* original ffa7, guest PC 0x0c03d1ca */
if(!s->budget--) { s->failed_pc=0x0c03d1cau; return 0; }
vf3_matrix_store(s,ram,10,r[15]+r[0]);
goto P_0c03d1cc;
P_0c03d1cc: /* original e004, guest PC 0x0c03d1cc */
if(!s->budget--) { s->failed_pc=0x0c03d1ccu; return 0; }
r[0]=0x00000004u;
goto P_0c03d1ce;
P_0c03d1ce: /* original f27c, guest PC 0x0c03d1ce */
if(!s->budget--) { s->failed_pc=0x0c03d1ceu; return 0; }
vf3_matrix_move(s,2,7);
goto P_0c03d1d0;
P_0c03d1d0: /* original f261, guest PC 0x0c03d1d0 */
if(!s->budget--) { s->failed_pc=0x0c03d1d0u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[6],r[18],'-');
goto P_0c03d1d2;
P_0c03d1d2: /* original ff27, guest PC 0x0c03d1d2 */
if(!s->budget--) { s->failed_pc=0x0c03d1d2u; return 0; }
vf3_matrix_store(s,ram,2,r[15]+r[0]);
goto P_0c03d1d4;
P_0c03d1d4: /* original e01c, guest PC 0x0c03d1d4 */
if(!s->budget--) { s->failed_pc=0x0c03d1d4u; return 0; }
r[0]=0x0000001cu;
goto P_0c03d1d6;
P_0c03d1d6: /* original f1f8, guest PC 0x0c03d1d6 */
if(!s->budget--) { s->failed_pc=0x0c03d1d6u; return 0; }
vf3_matrix_load(s,ram,1,r[15]);
goto P_0c03d1d8;
P_0c03d1d8: /* original f123, guest PC 0x0c03d1d8 */
if(!s->budget--) { s->failed_pc=0x0c03d1d8u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[2],r[18],'/');
goto P_0c03d1da;
P_0c03d1da: /* original ff17, guest PC 0x0c03d1da */
if(!s->budget--) { s->failed_pc=0x0c03d1dau; return 0; }
vf3_matrix_store(s,ram,1,r[15]+r[0]);
goto P_0c03d1dc;
P_0c03d1dc: /* original e020, guest PC 0x0c03d1dc */
if(!s->budget--) { s->failed_pc=0x0c03d1dcu; return 0; }
r[0]=0x00000020u;
goto P_0c03d1de;
P_0c03d1de: /* original ffa7, guest PC 0x0c03d1de */
if(!s->budget--) { s->failed_pc=0x0c03d1deu; return 0; }
vf3_matrix_store(s,ram,10,r[15]+r[0]);
goto P_0c03d1e0;
P_0c03d1e0: /* original f450, guest PC 0x0c03d1e0 */
if(!s->budget--) { s->failed_pc=0x0c03d1e0u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[5],r[18],'+');
goto P_0c03d1e2;
P_0c03d1e2: /* original e024, guest PC 0x0c03d1e2 */
if(!s->budget--) { s->failed_pc=0x0c03d1e2u; return 0; }
r[0]=0x00000024u;
goto P_0c03d1e4;
P_0c03d1e4: /* original ffa7, guest PC 0x0c03d1e4 */
if(!s->budget--) { s->failed_pc=0x0c03d1e4u; return 0; }
vf3_matrix_store(s,ram,10,r[15]+r[0]);
goto P_0c03d1e6;
P_0c03d1e6: /* original e028, guest PC 0x0c03d1e6 */
if(!s->budget--) { s->failed_pc=0x0c03d1e6u; return 0; }
r[0]=0x00000028u;
goto P_0c03d1e8;
P_0c03d1e8: /* original f670, guest PC 0x0c03d1e8 */
if(!s->budget--) { s->failed_pc=0x0c03d1e8u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[7],r[18],'+');
goto P_0c03d1ea;
P_0c03d1ea: /* original f4b3, guest PC 0x0c03d1ea */
if(!s->budget--) { s->failed_pc=0x0c03d1eau; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[11],r[18],'/');
goto P_0c03d1ec;
P_0c03d1ec: /* original ff47, guest PC 0x0c03d1ec */
if(!s->budget--) { s->failed_pc=0x0c03d1ecu; return 0; }
vf3_matrix_store(s,ram,4,r[15]+r[0]);
goto P_0c03d1ee;
P_0c03d1ee: /* original e004, guest PC 0x0c03d1ee */
if(!s->budget--) { s->failed_pc=0x0c03d1eeu; return 0; }
r[0]=0x00000004u;
goto P_0c03d1f0;
P_0c03d1f0: /* original f2f6, guest PC 0x0c03d1f0 */
if(!s->budget--) { s->failed_pc=0x0c03d1f0u; return 0; }
vf3_matrix_load(s,ram,2,r[15]+r[0]);
goto P_0c03d1f2;
P_0c03d1f2: /* original e02c, guest PC 0x0c03d1f2 */
if(!s->budget--) { s->failed_pc=0x0c03d1f2u; return 0; }
r[0]=0x0000002cu;
goto P_0c03d1f4;
P_0c03d1f4: /* original f623, guest PC 0x0c03d1f4 */
if(!s->budget--) { s->failed_pc=0x0c03d1f4u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[2],r[18],'/');
goto P_0c03d1f6;
P_0c03d1f6: /* original ff67, guest PC 0x0c03d1f6 */
if(!s->budget--) { s->failed_pc=0x0c03d1f6u; return 0; }
vf3_matrix_store(s,ram,6,r[15]+r[0]);
goto P_0c03d1f8;
P_0c03d1f8: /* original e030, guest PC 0x0c03d1f8 */
if(!s->budget--) { s->failed_pc=0x0c03d1f8u; return 0; }
r[0]=0x00000030u;
goto P_0c03d1fa;
P_0c03d1fa: /* original f68c, guest PC 0x0c03d1fa */
if(!s->budget--) { s->failed_pc=0x0c03d1fau; return 0; }
vf3_matrix_move(s,6,8);
goto P_0c03d1fc;
P_0c03d1fc: /* original f64d, guest PC 0x0c03d1fc */
if(!s->budget--) { s->failed_pc=0x0c03d1fcu; return 0; }
fr[6]^=0x80000000u;
goto P_0c03d1fe;
P_0c03d1fe: /* original f49c, guest PC 0x0c03d1fe */
if(!s->budget--) { s->failed_pc=0x0c03d1feu; return 0; }
vf3_matrix_move(s,4,9);
goto P_0c03d200;
P_0c03d200: /* original f481, guest PC 0x0c03d200 */
if(!s->budget--) { s->failed_pc=0x0c03d200u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[8],r[18],'-');
goto P_0c03d202;
P_0c03d202: /* original f26c, guest PC 0x0c03d202 */
if(!s->budget--) { s->failed_pc=0x0c03d202u; return 0; }
vf3_matrix_move(s,2,6);
goto P_0c03d204;
P_0c03d204: /* original f291, guest PC 0x0c03d204 */
if(!s->budget--) { s->failed_pc=0x0c03d204u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[9],r[18],'-');
goto P_0c03d206;
P_0c03d206: /* original f243, guest PC 0x0c03d206 */
if(!s->budget--) { s->failed_pc=0x0c03d206u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[4],r[18],'/');
goto P_0c03d208;
P_0c03d208: /* original ff27, guest PC 0x0c03d208 */
if(!s->budget--) { s->failed_pc=0x0c03d208u; return 0; }
vf3_matrix_store(s,ram,2,r[15]+r[0]);
goto P_0c03d20a;
P_0c03d20a: /* original e034, guest PC 0x0c03d20a */
if(!s->budget--) { s->failed_pc=0x0c03d20au; return 0; }
r[0]=0x00000034u;
goto P_0c03d20c;
P_0c03d20c: /* original f59d, guest PC 0x0c03d20c */
if(!s->budget--) { s->failed_pc=0x0c03d20cu; return 0; }
fr[5]=0x3f800000u;
goto P_0c03d20e;
P_0c03d20e: /* original ff57, guest PC 0x0c03d20e */
if(!s->budget--) { s->failed_pc=0x0c03d20eu; return 0; }
vf3_matrix_store(s,ram,5,r[15]+r[0]);
goto P_0c03d210;
P_0c03d210: /* original e038, guest PC 0x0c03d210 */
if(!s->budget--) { s->failed_pc=0x0c03d210u; return 0; }
r[0]=0x00000038u;
goto P_0c03d212;
P_0c03d212: /* original ffa7, guest PC 0x0c03d212 */
if(!s->budget--) { s->failed_pc=0x0c03d212u; return 0; }
vf3_matrix_store(s,ram,10,r[15]+r[0]);
goto P_0c03d214;
P_0c03d214: /* original e03c, guest PC 0x0c03d214 */
if(!s->budget--) { s->failed_pc=0x0c03d214u; return 0; }
r[0]=0x0000003cu;
goto P_0c03d216;
P_0c03d216: /* original ffa7, guest PC 0x0c03d216 */
if(!s->budget--) { s->failed_pc=0x0c03d216u; return 0; }
vf3_matrix_store(s,ram,10,r[15]+r[0]);
goto P_0c03d218;
P_0c03d218: /* original f28c, guest PC 0x0c03d218 */
if(!s->budget--) { s->failed_pc=0x0c03d218u; return 0; }
vf3_matrix_move(s,2,8);
goto P_0c03d21a;
P_0c03d21a: /* original f292, guest PC 0x0c03d21a */
if(!s->budget--) { s->failed_pc=0x0c03d21au; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[9],r[18],'*');
goto P_0c03d21c;
P_0c03d21c: /* original f232, guest PC 0x0c03d21c */
if(!s->budget--) { s->failed_pc=0x0c03d21cu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c03d21e;
P_0c03d21e: /* original f243, guest PC 0x0c03d21e */
if(!s->budget--) { s->failed_pc=0x0c03d21eu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[4],r[18],'/');
goto P_0c03d220;
P_0c03d220: /* original e040, guest PC 0x0c03d220 */
if(!s->budget--) { s->failed_pc=0x0c03d220u; return 0; }
r[0]=0x00000040u;
goto P_0c03d222;
P_0c03d222: /* original ff27, guest PC 0x0c03d222 */
if(!s->budget--) { s->failed_pc=0x0c03d222u; return 0; }
vf3_matrix_store(s,ram,2,r[15]+r[0]);
goto P_0c03d224;
P_0c03d224: /* original e044, guest PC 0x0c03d224 */
if(!s->budget--) { s->failed_pc=0x0c03d224u; return 0; }
r[0]=0x00000044u;
goto P_0c03d226;
P_0c03d226: /* original ffa7, guest PC 0x0c03d226 */
if(!s->budget--) { s->failed_pc=0x0c03d226u; return 0; }
vf3_matrix_store(s,ram,10,r[15]+r[0]);
goto P_0c03d228;
P_0c03d228: /* original e01c, guest PC 0x0c03d228 */
if(!s->budget--) { s->failed_pc=0x0c03d228u; return 0; }
r[0]=0x0000001cu;
goto P_0c03d22a;
P_0c03d22a: /* original d451, guest PC 0x0c03d22a */
if(!s->budget--) { s->failed_pc=0x0c03d22au; return 0; }
r[4]=read(ram,0x0c03d370u,4);
goto P_0c03d22c;
P_0c03d22c: /* original f487, guest PC 0x0c03d22c */
if(!s->budget--) { s->failed_pc=0x0c03d22cu; return 0; }
vf3_matrix_store(s,ram,8,r[4]+r[0]);
goto P_0c03d22e;
P_0c03d22e: /* original e020, guest PC 0x0c03d22e */
if(!s->budget--) { s->failed_pc=0x0c03d22eu; return 0; }
r[0]=0x00000020u;
goto P_0c03d230;
P_0c03d230: /* original f497, guest PC 0x0c03d230 */
if(!s->budget--) { s->failed_pc=0x0c03d230u; return 0; }
vf3_matrix_store(s,ram,9,r[4]+r[0]);
goto P_0c03d232;
P_0c03d232: /* original e024, guest PC 0x0c03d232 */
if(!s->budget--) { s->failed_pc=0x0c03d232u; return 0; }
r[0]=0x00000024u;
goto P_0c03d234;
P_0c03d234: /* original f45c, guest PC 0x0c03d234 */
if(!s->budget--) { s->failed_pc=0x0c03d234u; return 0; }
vf3_matrix_move(s,4,5);
goto P_0c03d236;
P_0c03d236: /* original f483, guest PC 0x0c03d236 */
if(!s->budget--) { s->failed_pc=0x0c03d236u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[8],r[18],'/');
goto P_0c03d238;
P_0c03d238: /* original f447, guest PC 0x0c03d238 */
if(!s->budget--) { s->failed_pc=0x0c03d238u; return 0; }
vf3_matrix_store(s,ram,4,r[4]+r[0]);
goto P_0c03d23a;
P_0c03d23a: /* original d44e, guest PC 0x0c03d23a */
if(!s->budget--) { s->failed_pc=0x0c03d23au; return 0; }
r[4]=read(ram,0x0c03d374u,4);
goto P_0c03d23c;
P_0c03d23c: /* original f487, guest PC 0x0c03d23c */
if(!s->budget--) { s->failed_pc=0x0c03d23cu; return 0; }
vf3_matrix_store(s,ram,8,r[4]+r[0]);
goto P_0c03d23e;
P_0c03d23e: /* original e00c, guest PC 0x0c03d23e */
if(!s->budget--) { s->failed_pc=0x0c03d23eu; return 0; }
r[0]=0x0000000cu;
goto P_0c03d240;
P_0c03d240: /* original f467, guest PC 0x0c03d240 */
if(!s->budget--) { s->failed_pc=0x0c03d240u; return 0; }
vf3_matrix_store(s,ram,6,r[4]+r[0]);
goto P_0c03d242;
P_0c03d242: /* original e028, guest PC 0x0c03d242 */
if(!s->budget--) { s->failed_pc=0x0c03d242u; return 0; }
r[0]=0x00000028u;
goto P_0c03d244;
P_0c03d244: /* original f497, guest PC 0x0c03d244 */
if(!s->budget--) { s->failed_pc=0x0c03d244u; return 0; }
vf3_matrix_store(s,ram,9,r[4]+r[0]);
goto P_0c03d246;
P_0c03d246: /* original e020, guest PC 0x0c03d246 */
if(!s->budget--) { s->failed_pc=0x0c03d246u; return 0; }
r[0]=0x00000020u;
goto P_0c03d248;
P_0c03d248: /* original f447, guest PC 0x0c03d248 */
if(!s->budget--) { s->failed_pc=0x0c03d248u; return 0; }
vf3_matrix_store(s,ram,4,r[4]+r[0]);
goto P_0c03d24a;
P_0c03d24a: /* original 64f3, guest PC 0x0c03d24a */
if(!s->budget--) { s->failed_pc=0x0c03d24au; return 0; }
r[4]=r[15];
goto P_0c03d24c;
P_0c03d24c: /* original d34a, guest PC 0x0c03d24c */
if(!s->budget--) { s->failed_pc=0x0c03d24cu; return 0; }
r[3]=read(ram,0x0c03d378u,4);
goto P_0c03d24e;
P_0c03d24e: /* original 430b, guest PC 0x0c03d24e */
if(!s->budget--) { s->failed_pc=0x0c03d24eu; return 0; }
target=r[3];
r[16]=0x0c03d252u;
r[4]+=0x00000008u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c03d252u) { target=s->pc; goto dispatch; }
goto P_0c03d252;
P_0c03d250: /* original 7408, guest PC 0x0c03d250 */
if(!s->budget--) { s->failed_pc=0x0c03d250u; return 0; }
r[4]+=0x00000008u;
goto P_0c03d252;
P_0c03d252: /* original 7f48, guest PC 0x0c03d252 */
if(!s->budget--) { s->failed_pc=0x0c03d252u; return 0; }
r[15]+=0x00000048u;
goto P_0c03d254;
P_0c03d254: /* original 4f26, guest PC 0x0c03d254 */
if(!s->budget--) { s->failed_pc=0x0c03d254u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c03d256;
P_0c03d256: /* original 000b, guest PC 0x0c03d256 */
if(!s->budget--) { s->failed_pc=0x0c03d256u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c03d258: /* original 0009, guest PC 0x0c03d258 */
if(!s->budget--) { s->failed_pc=0x0c03d258u; return 0; }
return vf3_matrix_family(0x0c03d25au,s,ram);
P_0c0645fa: /* original 4f22, guest PC 0x0c0645fa */
if(!s->budget--) { s->failed_pc=0x0c0645fau; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0645fc;
P_0c0645fc: /* original 7ff0, guest PC 0x0c0645fc */
if(!s->budget--) { s->failed_pc=0x0c0645fcu; return 0; }
r[15]+=0xfffffff0u;
goto P_0c0645fe;
P_0c0645fe: /* original 6df3, guest PC 0x0c0645fe */
if(!s->budget--) { s->failed_pc=0x0c0645feu; return 0; }
r[13]=r[15];
goto P_0c064600;
P_0c064600: /* original 6342, guest PC 0x0c064600 */
if(!s->budget--) { s->failed_pc=0x0c064600u; return 0; }
tmp=read(ram,r[4],4);
r[3]=tmp;
goto P_0c064602;
P_0c064602: /* original 7d04, guest PC 0x0c064602 */
if(!s->budget--) { s->failed_pc=0x0c064602u; return 0; }
r[13]+=0x00000004u;
goto P_0c064604;
P_0c064604: /* original 6ed3, guest PC 0x0c064604 */
if(!s->budget--) { s->failed_pc=0x0c064604u; return 0; }
r[14]=r[13];
goto P_0c064606;
P_0c064606: /* original 66e3, guest PC 0x0c064606 */
if(!s->budget--) { s->failed_pc=0x0c064606u; return 0; }
r[6]=r[14];
goto P_0c064608;
P_0c064608: /* original 2e32, guest PC 0x0c064608 */
if(!s->budget--) { s->failed_pc=0x0c064608u; return 0; }
write(ram,r[14],r[3],4);
goto P_0c06460a;
P_0c06460a: /* original 67e3, guest PC 0x0c06460a */
if(!s->budget--) { s->failed_pc=0x0c06460au; return 0; }
r[7]=r[14];
goto P_0c06460c;
P_0c06460c: /* original 5241, guest PC 0x0c06460c */
if(!s->budget--) { s->failed_pc=0x0c06460cu; return 0; }
r[2]=read(ram,r[4]+4,4);
goto P_0c06460e;
P_0c06460e: /* original 7604, guest PC 0x0c06460e */
if(!s->budget--) { s->failed_pc=0x0c06460eu; return 0; }
r[6]+=0x00000004u;
goto P_0c064610;
P_0c064610: /* original 2622, guest PC 0x0c064610 */
if(!s->budget--) { s->failed_pc=0x0c064610u; return 0; }
write(ram,r[6],r[2],4);
goto P_0c064612;
P_0c064612: /* original 7708, guest PC 0x0c064612 */
if(!s->budget--) { s->failed_pc=0x0c064612u; return 0; }
r[7]+=0x00000008u;
goto P_0c064614;
P_0c064614: /* original 5342, guest PC 0x0c064614 */
if(!s->budget--) { s->failed_pc=0x0c064614u; return 0; }
r[3]=read(ram,r[4]+8,4);
goto P_0c064616;
P_0c064616: /* original 2732, guest PC 0x0c064616 */
if(!s->budget--) { s->failed_pc=0x0c064616u; return 0; }
write(ram,r[7],r[3],4);
goto P_0c064618;
P_0c064618: /* original d250, guest PC 0x0c064618 */
if(!s->budget--) { s->failed_pc=0x0c064618u; return 0; }
r[2]=read(ram,0x0c06475cu,4);
goto P_0c06461a;
P_0c06461a: /* original 6d22, guest PC 0x0c06461a */
if(!s->budget--) { s->failed_pc=0x0c06461au; return 0; }
tmp=read(ram,r[2],4);
r[13]=tmp;
goto P_0c06461c;
P_0c06461c: /* original d150, guest PC 0x0c06461c */
if(!s->budget--) { s->failed_pc=0x0c06461cu; return 0; }
r[1]=read(ram,0x0c064760u,4);
goto P_0c06461e;
P_0c06461e: /* original 6312, guest PC 0x0c06461e */
if(!s->budget--) { s->failed_pc=0x0c06461eu; return 0; }
tmp=read(ram,r[1],4);
r[3]=tmp;
goto P_0c064620;
P_0c064620: /* original 2f32, guest PC 0x0c064620 */
if(!s->budget--) { s->failed_pc=0x0c064620u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c064622;
P_0c064622: /* original d350, guest PC 0x0c064622 */
if(!s->budget--) { s->failed_pc=0x0c064622u; return 0; }
r[3]=read(ram,0x0c064764u,4);
goto P_0c064624;
P_0c064624: /* original 6432, guest PC 0x0c064624 */
if(!s->budget--) { s->failed_pc=0x0c064624u; return 0; }
tmp=read(ram,r[3],4);
r[4]=tmp;
goto P_0c064626;
P_0c064626: /* original d03a, guest PC 0x0c064626 */
if(!s->budget--) { s->failed_pc=0x0c064626u; return 0; }
r[0]=read(ram,0x0c064710u,4);
goto P_0c064628;
P_0c064628: /* original 6253, guest PC 0x0c064628 */
if(!s->budget--) { s->failed_pc=0x0c064628u; return 0; }
r[2]=r[5];
goto P_0c06462a;
P_0c06462a: /* original 7501, guest PC 0x0c06462a */
if(!s->budget--) { s->failed_pc=0x0c06462au; return 0; }
r[5]+=0x00000001u;
goto P_0c06462c;
P_0c06462c: /* original 4208, guest PC 0x0c06462c */
if(!s->budget--) { s->failed_pc=0x0c06462cu; return 0; }
r[2]<<=2;
goto P_0c06462e;
P_0c06462e: /* original 02d6, guest PC 0x0c06462e */
if(!s->budget--) { s->failed_pc=0x0c06462eu; return 0; }
write(ram,r[2]+r[0],r[13],4);
goto P_0c064630;
P_0c064630: /* original 6153, guest PC 0x0c064630 */
if(!s->budget--) { s->failed_pc=0x0c064630u; return 0; }
r[1]=r[5];
goto P_0c064632;
P_0c064632: /* original 7501, guest PC 0x0c064632 */
if(!s->budget--) { s->failed_pc=0x0c064632u; return 0; }
r[5]+=0x00000001u;
goto P_0c064634;
P_0c064634: /* original 62f2, guest PC 0x0c064634 */
if(!s->budget--) { s->failed_pc=0x0c064634u; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c064636;
P_0c064636: /* original 4108, guest PC 0x0c064636 */
if(!s->budget--) { s->failed_pc=0x0c064636u; return 0; }
r[1]<<=2;
goto P_0c064638;
P_0c064638: /* original 0126, guest PC 0x0c064638 */
if(!s->budget--) { s->failed_pc=0x0c064638u; return 0; }
write(ram,r[1]+r[0],r[2],4);
goto P_0c06463a;
P_0c06463a: /* original 6153, guest PC 0x0c06463a */
if(!s->budget--) { s->failed_pc=0x0c06463au; return 0; }
r[1]=r[5];
goto P_0c06463c;
P_0c06463c: /* original 7501, guest PC 0x0c06463c */
if(!s->budget--) { s->failed_pc=0x0c06463cu; return 0; }
r[5]+=0x00000001u;
goto P_0c06463e;
P_0c06463e: /* original 4108, guest PC 0x0c06463e */
if(!s->budget--) { s->failed_pc=0x0c06463eu; return 0; }
r[1]<<=2;
goto P_0c064640;
P_0c064640: /* original 0146, guest PC 0x0c064640 */
if(!s->budget--) { s->failed_pc=0x0c064640u; return 0; }
write(ram,r[1]+r[0],r[4],4);
goto P_0c064642;
P_0c064642: /* original 6253, guest PC 0x0c064642 */
if(!s->budget--) { s->failed_pc=0x0c064642u; return 0; }
r[2]=r[5];
goto P_0c064644;
P_0c064644: /* original 61e2, guest PC 0x0c064644 */
if(!s->budget--) { s->failed_pc=0x0c064644u; return 0; }
tmp=read(ram,r[14],4);
r[1]=tmp;
goto P_0c064646;
P_0c064646: /* original 7501, guest PC 0x0c064646 */
if(!s->budget--) { s->failed_pc=0x0c064646u; return 0; }
r[5]+=0x00000001u;
goto P_0c064648;
P_0c064648: /* original 5111, guest PC 0x0c064648 */
if(!s->budget--) { s->failed_pc=0x0c064648u; return 0; }
r[1]=read(ram,r[1]+4,4);
goto P_0c06464a;
P_0c06464a: /* original 4208, guest PC 0x0c06464a */
if(!s->budget--) { s->failed_pc=0x0c06464au; return 0; }
r[2]<<=2;
goto P_0c06464c;
P_0c06464c: /* original 0216, guest PC 0x0c06464c */
if(!s->budget--) { s->failed_pc=0x0c06464cu; return 0; }
write(ram,r[2]+r[0],r[1],4);
goto P_0c06464e;
P_0c06464e: /* original 6253, guest PC 0x0c06464e */
if(!s->budget--) { s->failed_pc=0x0c06464eu; return 0; }
r[2]=r[5];
goto P_0c064650;
P_0c064650: /* original 61e2, guest PC 0x0c064650 */
if(!s->budget--) { s->failed_pc=0x0c064650u; return 0; }
tmp=read(ram,r[14],4);
r[1]=tmp;
goto P_0c064652;
P_0c064652: /* original 7501, guest PC 0x0c064652 */
if(!s->budget--) { s->failed_pc=0x0c064652u; return 0; }
r[5]+=0x00000001u;
goto P_0c064654;
P_0c064654: /* original 5112, guest PC 0x0c064654 */
if(!s->budget--) { s->failed_pc=0x0c064654u; return 0; }
r[1]=read(ram,r[1]+8,4);
goto P_0c064656;
P_0c064656: /* original 4208, guest PC 0x0c064656 */
if(!s->budget--) { s->failed_pc=0x0c064656u; return 0; }
r[2]<<=2;
goto P_0c064658;
P_0c064658: /* original 0216, guest PC 0x0c064658 */
if(!s->budget--) { s->failed_pc=0x0c064658u; return 0; }
write(ram,r[2]+r[0],r[1],4);
goto P_0c06465a;
P_0c06465a: /* original 6253, guest PC 0x0c06465a */
if(!s->budget--) { s->failed_pc=0x0c06465au; return 0; }
r[2]=r[5];
goto P_0c06465c;
P_0c06465c: /* original 61e2, guest PC 0x0c06465c */
if(!s->budget--) { s->failed_pc=0x0c06465cu; return 0; }
tmp=read(ram,r[14],4);
r[1]=tmp;
goto P_0c06465e;
P_0c06465e: /* original 7501, guest PC 0x0c06465e */
if(!s->budget--) { s->failed_pc=0x0c06465eu; return 0; }
r[5]+=0x00000001u;
goto P_0c064660;
P_0c064660: /* original 5113, guest PC 0x0c064660 */
if(!s->budget--) { s->failed_pc=0x0c064660u; return 0; }
r[1]=read(ram,r[1]+12,4);
goto P_0c064662;
P_0c064662: /* original 4208, guest PC 0x0c064662 */
if(!s->budget--) { s->failed_pc=0x0c064662u; return 0; }
r[2]<<=2;
goto P_0c064664;
P_0c064664: /* original 0216, guest PC 0x0c064664 */
if(!s->budget--) { s->failed_pc=0x0c064664u; return 0; }
write(ram,r[2]+r[0],r[1],4);
goto P_0c064666;
P_0c064666: /* original 6253, guest PC 0x0c064666 */
if(!s->budget--) { s->failed_pc=0x0c064666u; return 0; }
r[2]=r[5];
goto P_0c064668;
P_0c064668: /* original 61e2, guest PC 0x0c064668 */
if(!s->budget--) { s->failed_pc=0x0c064668u; return 0; }
tmp=read(ram,r[14],4);
r[1]=tmp;
goto P_0c06466a;
P_0c06466a: /* original 7501, guest PC 0x0c06466a */
if(!s->budget--) { s->failed_pc=0x0c06466au; return 0; }
r[5]+=0x00000001u;
goto P_0c06466c;
P_0c06466c: /* original 5116, guest PC 0x0c06466c */
if(!s->budget--) { s->failed_pc=0x0c06466cu; return 0; }
r[1]=read(ram,r[1]+24,4);
goto P_0c06466e;
P_0c06466e: /* original 4208, guest PC 0x0c06466e */
if(!s->budget--) { s->failed_pc=0x0c06466eu; return 0; }
r[2]<<=2;
goto P_0c064670;
P_0c064670: /* original 0216, guest PC 0x0c064670 */
if(!s->budget--) { s->failed_pc=0x0c064670u; return 0; }
write(ram,r[2]+r[0],r[1],4);
goto P_0c064672;
P_0c064672: /* original 6253, guest PC 0x0c064672 */
if(!s->budget--) { s->failed_pc=0x0c064672u; return 0; }
r[2]=r[5];
goto P_0c064674;
P_0c064674: /* original 6162, guest PC 0x0c064674 */
if(!s->budget--) { s->failed_pc=0x0c064674u; return 0; }
tmp=read(ram,r[6],4);
r[1]=tmp;
goto P_0c064676;
P_0c064676: /* original 7501, guest PC 0x0c064676 */
if(!s->budget--) { s->failed_pc=0x0c064676u; return 0; }
r[5]+=0x00000001u;
goto P_0c064678;
P_0c064678: /* original 5111, guest PC 0x0c064678 */
if(!s->budget--) { s->failed_pc=0x0c064678u; return 0; }
r[1]=read(ram,r[1]+4,4);
goto P_0c06467a;
P_0c06467a: /* original 4208, guest PC 0x0c06467a */
if(!s->budget--) { s->failed_pc=0x0c06467au; return 0; }
r[2]<<=2;
goto P_0c06467c;
P_0c06467c: /* original 0216, guest PC 0x0c06467c */
if(!s->budget--) { s->failed_pc=0x0c06467cu; return 0; }
write(ram,r[2]+r[0],r[1],4);
goto P_0c06467e;
P_0c06467e: /* original 6253, guest PC 0x0c06467e */
if(!s->budget--) { s->failed_pc=0x0c06467eu; return 0; }
r[2]=r[5];
goto P_0c064680;
P_0c064680: /* original 6162, guest PC 0x0c064680 */
if(!s->budget--) { s->failed_pc=0x0c064680u; return 0; }
tmp=read(ram,r[6],4);
r[1]=tmp;
goto P_0c064682;
P_0c064682: /* original 7501, guest PC 0x0c064682 */
if(!s->budget--) { s->failed_pc=0x0c064682u; return 0; }
r[5]+=0x00000001u;
goto P_0c064684;
P_0c064684: /* original 5112, guest PC 0x0c064684 */
if(!s->budget--) { s->failed_pc=0x0c064684u; return 0; }
r[1]=read(ram,r[1]+8,4);
goto P_0c064686;
P_0c064686: /* original 4208, guest PC 0x0c064686 */
if(!s->budget--) { s->failed_pc=0x0c064686u; return 0; }
r[2]<<=2;
goto P_0c064688;
P_0c064688: /* original 0216, guest PC 0x0c064688 */
if(!s->budget--) { s->failed_pc=0x0c064688u; return 0; }
write(ram,r[2]+r[0],r[1],4);
goto P_0c06468a;
P_0c06468a: /* original 6253, guest PC 0x0c06468a */
if(!s->budget--) { s->failed_pc=0x0c06468au; return 0; }
r[2]=r[5];
goto P_0c06468c;
P_0c06468c: /* original 6162, guest PC 0x0c06468c */
if(!s->budget--) { s->failed_pc=0x0c06468cu; return 0; }
tmp=read(ram,r[6],4);
r[1]=tmp;
goto P_0c06468e;
P_0c06468e: /* original 7501, guest PC 0x0c06468e */
if(!s->budget--) { s->failed_pc=0x0c06468eu; return 0; }
r[5]+=0x00000001u;
goto P_0c064690;
P_0c064690: /* original 5113, guest PC 0x0c064690 */
if(!s->budget--) { s->failed_pc=0x0c064690u; return 0; }
r[1]=read(ram,r[1]+12,4);
goto P_0c064692;
P_0c064692: /* original 4208, guest PC 0x0c064692 */
if(!s->budget--) { s->failed_pc=0x0c064692u; return 0; }
r[2]<<=2;
goto P_0c064694;
P_0c064694: /* original 0216, guest PC 0x0c064694 */
if(!s->budget--) { s->failed_pc=0x0c064694u; return 0; }
write(ram,r[2]+r[0],r[1],4);
goto P_0c064696;
P_0c064696: /* original 6253, guest PC 0x0c064696 */
if(!s->budget--) { s->failed_pc=0x0c064696u; return 0; }
r[2]=r[5];
goto P_0c064698;
P_0c064698: /* original 6162, guest PC 0x0c064698 */
if(!s->budget--) { s->failed_pc=0x0c064698u; return 0; }
tmp=read(ram,r[6],4);
r[1]=tmp;
goto P_0c06469a;
P_0c06469a: /* original 7501, guest PC 0x0c06469a */
if(!s->budget--) { s->failed_pc=0x0c06469au; return 0; }
r[5]+=0x00000001u;
goto P_0c06469c;
P_0c06469c: /* original 5116, guest PC 0x0c06469c */
if(!s->budget--) { s->failed_pc=0x0c06469cu; return 0; }
r[1]=read(ram,r[1]+24,4);
goto P_0c06469e;
P_0c06469e: /* original 4208, guest PC 0x0c06469e */
if(!s->budget--) { s->failed_pc=0x0c06469eu; return 0; }
r[2]<<=2;
goto P_0c0646a0;
P_0c0646a0: /* original 0216, guest PC 0x0c0646a0 */
if(!s->budget--) { s->failed_pc=0x0c0646a0u; return 0; }
write(ram,r[2]+r[0],r[1],4);
goto P_0c0646a2;
P_0c0646a2: /* original 6253, guest PC 0x0c0646a2 */
if(!s->budget--) { s->failed_pc=0x0c0646a2u; return 0; }
r[2]=r[5];
goto P_0c0646a4;
P_0c0646a4: /* original 6172, guest PC 0x0c0646a4 */
if(!s->budget--) { s->failed_pc=0x0c0646a4u; return 0; }
tmp=read(ram,r[7],4);
r[1]=tmp;
goto P_0c0646a6;
P_0c0646a6: /* original 7501, guest PC 0x0c0646a6 */
if(!s->budget--) { s->failed_pc=0x0c0646a6u; return 0; }
r[5]+=0x00000001u;
goto P_0c0646a8;
P_0c0646a8: /* original 5111, guest PC 0x0c0646a8 */
if(!s->budget--) { s->failed_pc=0x0c0646a8u; return 0; }
r[1]=read(ram,r[1]+4,4);
goto P_0c0646aa;
P_0c0646aa: /* original 4208, guest PC 0x0c0646aa */
if(!s->budget--) { s->failed_pc=0x0c0646aau; return 0; }
r[2]<<=2;
goto P_0c0646ac;
P_0c0646ac: /* original 0216, guest PC 0x0c0646ac */
if(!s->budget--) { s->failed_pc=0x0c0646acu; return 0; }
write(ram,r[2]+r[0],r[1],4);
goto P_0c0646ae;
P_0c0646ae: /* original 6253, guest PC 0x0c0646ae */
if(!s->budget--) { s->failed_pc=0x0c0646aeu; return 0; }
r[2]=r[5];
goto P_0c0646b0;
P_0c0646b0: /* original 7501, guest PC 0x0c0646b0 */
if(!s->budget--) { s->failed_pc=0x0c0646b0u; return 0; }
r[5]+=0x00000001u;
goto P_0c0646b2;
P_0c0646b2: /* original 4208, guest PC 0x0c0646b2 */
if(!s->budget--) { s->failed_pc=0x0c0646b2u; return 0; }
r[2]<<=2;
goto P_0c0646b4;
P_0c0646b4: /* original 6172, guest PC 0x0c0646b4 */
if(!s->budget--) { s->failed_pc=0x0c0646b4u; return 0; }
tmp=read(ram,r[7],4);
r[1]=tmp;
goto P_0c0646b6;
P_0c0646b6: /* original 5112, guest PC 0x0c0646b6 */
if(!s->budget--) { s->failed_pc=0x0c0646b6u; return 0; }
r[1]=read(ram,r[1]+8,4);
goto P_0c0646b8;
P_0c0646b8: /* original 0216, guest PC 0x0c0646b8 */
if(!s->budget--) { s->failed_pc=0x0c0646b8u; return 0; }
write(ram,r[2]+r[0],r[1],4);
goto P_0c0646ba;
P_0c0646ba: /* original 6253, guest PC 0x0c0646ba */
if(!s->budget--) { s->failed_pc=0x0c0646bau; return 0; }
r[2]=r[5];
goto P_0c0646bc;
P_0c0646bc: /* original 6172, guest PC 0x0c0646bc */
if(!s->budget--) { s->failed_pc=0x0c0646bcu; return 0; }
tmp=read(ram,r[7],4);
r[1]=tmp;
goto P_0c0646be;
P_0c0646be: /* original 7501, guest PC 0x0c0646be */
if(!s->budget--) { s->failed_pc=0x0c0646beu; return 0; }
r[5]+=0x00000001u;
goto P_0c0646c0;
P_0c0646c0: /* original 5113, guest PC 0x0c0646c0 */
if(!s->budget--) { s->failed_pc=0x0c0646c0u; return 0; }
r[1]=read(ram,r[1]+12,4);
goto P_0c0646c2;
P_0c0646c2: /* original 4208, guest PC 0x0c0646c2 */
if(!s->budget--) { s->failed_pc=0x0c0646c2u; return 0; }
r[2]<<=2;
goto P_0c0646c4;
P_0c0646c4: /* original 0216, guest PC 0x0c0646c4 */
if(!s->budget--) { s->failed_pc=0x0c0646c4u; return 0; }
write(ram,r[2]+r[0],r[1],4);
goto P_0c0646c6;
P_0c0646c6: /* original 6253, guest PC 0x0c0646c6 */
if(!s->budget--) { s->failed_pc=0x0c0646c6u; return 0; }
r[2]=r[5];
goto P_0c0646c8;
P_0c0646c8: /* original 6172, guest PC 0x0c0646c8 */
if(!s->budget--) { s->failed_pc=0x0c0646c8u; return 0; }
tmp=read(ram,r[7],4);
r[1]=tmp;
goto P_0c0646ca;
P_0c0646ca: /* original 7501, guest PC 0x0c0646ca */
if(!s->budget--) { s->failed_pc=0x0c0646cau; return 0; }
r[5]+=0x00000001u;
goto P_0c0646cc;
P_0c0646cc: /* original 5116, guest PC 0x0c0646cc */
if(!s->budget--) { s->failed_pc=0x0c0646ccu; return 0; }
r[1]=read(ram,r[1]+24,4);
goto P_0c0646ce;
P_0c0646ce: /* original 4208, guest PC 0x0c0646ce */
if(!s->budget--) { s->failed_pc=0x0c0646ceu; return 0; }
r[2]<<=2;
goto P_0c0646d0;
P_0c0646d0: /* original 0216, guest PC 0x0c0646d0 */
if(!s->budget--) { s->failed_pc=0x0c0646d0u; return 0; }
write(ram,r[2]+r[0],r[1],4);
goto P_0c0646d2;
P_0c0646d2: /* original 4508, guest PC 0x0c0646d2 */
if(!s->budget--) { s->failed_pc=0x0c0646d2u; return 0; }
r[5]<<=2;
goto P_0c0646d4;
P_0c0646d4: /* original d224, guest PC 0x0c0646d4 */
if(!s->budget--) { s->failed_pc=0x0c0646d4u; return 0; }
r[2]=read(ram,0x0c064768u,4);
goto P_0c0646d6;
P_0c0646d6: /* original 2252, guest PC 0x0c0646d6 */
if(!s->budget--) { s->failed_pc=0x0c0646d6u; return 0; }
write(ram,r[2],r[5],4);
goto P_0c0646d8;
P_0c0646d8: /* original bf1b, guest PC 0x0c0646d8 */
if(!s->budget--) { s->failed_pc=0x0c0646d8u; return 0; }
target=0x0c064512u; r[16]=0x0c0646dcu;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0646dcu) { target=s->pc; goto dispatch; }
goto P_0c0646dc;
P_0c0646da: /* original 64d3, guest PC 0x0c0646da */
if(!s->budget--) { s->failed_pc=0x0c0646dau; return 0; }
r[4]=r[13];
goto P_0c0646dc;
P_0c0646dc: /* original 6403, guest PC 0x0c0646dc */
if(!s->budget--) { s->failed_pc=0x0c0646dcu; return 0; }
r[4]=r[0];
goto P_0c0646de;
P_0c0646de: /* original e500, guest PC 0x0c0646de */
if(!s->budget--) { s->failed_pc=0x0c0646deu; return 0; }
r[5]=0x00000000u;
goto P_0c0646e0;
P_0c0646e0: /* original bf02, guest PC 0x0c0646e0 */
if(!s->budget--) { s->failed_pc=0x0c0646e0u; return 0; }
target=0x0c0644e8u; r[16]=0x0c0646e4u;
r[6]=r[5];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0646e4u) { target=s->pc; goto dispatch; }
goto P_0c0646e4;
P_0c0646e2: /* original 6653, guest PC 0x0c0646e2 */
if(!s->budget--) { s->failed_pc=0x0c0646e2u; return 0; }
r[6]=r[5];
goto P_0c0646e4;
P_0c0646e4: /* original 62e2, guest PC 0x0c0646e4 */
if(!s->budget--) { s->failed_pc=0x0c0646e4u; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c0646e6;
P_0c0646e6: /* original 5323, guest PC 0x0c0646e6 */
if(!s->budget--) { s->failed_pc=0x0c0646e6u; return 0; }
r[3]=read(ram,r[2]+12,4);
goto P_0c0646e8;
P_0c0646e8: /* original d11b, guest PC 0x0c0646e8 */
if(!s->budget--) { s->failed_pc=0x0c0646e8u; return 0; }
r[1]=read(ram,0x0c064758u,4);
goto P_0c0646ea;
P_0c0646ea: /* original 2132, guest PC 0x0c0646ea */
if(!s->budget--) { s->failed_pc=0x0c0646eau; return 0; }
write(ram,r[1],r[3],4);
goto P_0c0646ec;
P_0c0646ec: /* original e000, guest PC 0x0c0646ec */
if(!s->budget--) { s->failed_pc=0x0c0646ecu; return 0; }
r[0]=0x00000000u;
goto P_0c0646ee;
P_0c0646ee: /* original 7f10, guest PC 0x0c0646ee */
if(!s->budget--) { s->failed_pc=0x0c0646eeu; return 0; }
r[15]+=0x00000010u;
goto P_0c0646f0;
P_0c0646f0: /* original 4f26, guest PC 0x0c0646f0 */
if(!s->budget--) { s->failed_pc=0x0c0646f0u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0646f2;
P_0c0646f2: /* original 6df6, guest PC 0x0c0646f2 */
if(!s->budget--) { s->failed_pc=0x0c0646f2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0646f4;
P_0c0646f4: /* original 000b, guest PC 0x0c0646f4 */
if(!s->budget--) { s->failed_pc=0x0c0646f4u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0646f6: /* original 6ef6, guest PC 0x0c0646f6 */
if(!s->budget--) { s->failed_pc=0x0c0646f6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0646f8u,s,ram);
P_0c064930: /* original 4f22, guest PC 0x0c064930 */
if(!s->budget--) { s->failed_pc=0x0c064930u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c064932;
P_0c064932: /* original 7ff0, guest PC 0x0c064932 */
if(!s->budget--) { s->failed_pc=0x0c064932u; return 0; }
r[15]+=0xfffffff0u;
goto P_0c064934;
P_0c064934: /* original 6342, guest PC 0x0c064934 */
if(!s->budget--) { s->failed_pc=0x0c064934u; return 0; }
tmp=read(ram,r[4],4);
r[3]=tmp;
goto P_0c064936;
P_0c064936: /* original 6df3, guest PC 0x0c064936 */
if(!s->budget--) { s->failed_pc=0x0c064936u; return 0; }
r[13]=r[15];
goto P_0c064938;
P_0c064938: /* original 7d04, guest PC 0x0c064938 */
if(!s->budget--) { s->failed_pc=0x0c064938u; return 0; }
r[13]+=0x00000004u;
goto P_0c06493a;
P_0c06493a: /* original 6ed3, guest PC 0x0c06493a */
if(!s->budget--) { s->failed_pc=0x0c06493au; return 0; }
r[14]=r[13];
goto P_0c06493c;
P_0c06493c: /* original 2e32, guest PC 0x0c06493c */
if(!s->budget--) { s->failed_pc=0x0c06493cu; return 0; }
write(ram,r[14],r[3],4);
goto P_0c06493e;
P_0c06493e: /* original 67e3, guest PC 0x0c06493e */
if(!s->budget--) { s->failed_pc=0x0c06493eu; return 0; }
r[7]=r[14];
goto P_0c064940;
P_0c064940: /* original 5241, guest PC 0x0c064940 */
if(!s->budget--) { s->failed_pc=0x0c064940u; return 0; }
r[2]=read(ram,r[4]+4,4);
goto P_0c064942;
P_0c064942: /* original 66e3, guest PC 0x0c064942 */
if(!s->budget--) { s->failed_pc=0x0c064942u; return 0; }
r[6]=r[14];
goto P_0c064944;
P_0c064944: /* original 7704, guest PC 0x0c064944 */
if(!s->budget--) { s->failed_pc=0x0c064944u; return 0; }
r[7]+=0x00000004u;
goto P_0c064946;
P_0c064946: /* original 7608, guest PC 0x0c064946 */
if(!s->budget--) { s->failed_pc=0x0c064946u; return 0; }
r[6]+=0x00000008u;
goto P_0c064948;
P_0c064948: /* original 2722, guest PC 0x0c064948 */
if(!s->budget--) { s->failed_pc=0x0c064948u; return 0; }
write(ram,r[7],r[2],4);
goto P_0c06494a;
P_0c06494a: /* original 5342, guest PC 0x0c06494a */
if(!s->budget--) { s->failed_pc=0x0c06494au; return 0; }
r[3]=read(ram,r[4]+8,4);
goto P_0c06494c;
P_0c06494c: /* original d250, guest PC 0x0c06494c */
if(!s->budget--) { s->failed_pc=0x0c06494cu; return 0; }
r[2]=read(ram,0x0c064a90u,4);
goto P_0c06494e;
P_0c06494e: /* original 2632, guest PC 0x0c06494e */
if(!s->budget--) { s->failed_pc=0x0c06494eu; return 0; }
write(ram,r[6],r[3],4);
goto P_0c064950;
P_0c064950: /* original 6d22, guest PC 0x0c064950 */
if(!s->budget--) { s->failed_pc=0x0c064950u; return 0; }
tmp=read(ram,r[2],4);
r[13]=tmp;
goto P_0c064952;
P_0c064952: /* original d150, guest PC 0x0c064952 */
if(!s->budget--) { s->failed_pc=0x0c064952u; return 0; }
r[1]=read(ram,0x0c064a94u,4);
goto P_0c064954;
P_0c064954: /* original 6312, guest PC 0x0c064954 */
if(!s->budget--) { s->failed_pc=0x0c064954u; return 0; }
tmp=read(ram,r[1],4);
r[3]=tmp;
goto P_0c064956;
P_0c064956: /* original 2f32, guest PC 0x0c064956 */
if(!s->budget--) { s->failed_pc=0x0c064956u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c064958;
P_0c064958: /* original d34f, guest PC 0x0c064958 */
if(!s->budget--) { s->failed_pc=0x0c064958u; return 0; }
r[3]=read(ram,0x0c064a98u,4);
goto P_0c06495a;
P_0c06495a: /* original 6432, guest PC 0x0c06495a */
if(!s->budget--) { s->failed_pc=0x0c06495au; return 0; }
tmp=read(ram,r[3],4);
r[4]=tmp;
goto P_0c06495c;
P_0c06495c: /* original d04f, guest PC 0x0c06495c */
if(!s->budget--) { s->failed_pc=0x0c06495cu; return 0; }
r[0]=read(ram,0x0c064a9cu,4);
goto P_0c06495e;
P_0c06495e: /* original 6253, guest PC 0x0c06495e */
if(!s->budget--) { s->failed_pc=0x0c06495eu; return 0; }
r[2]=r[5];
goto P_0c064960;
P_0c064960: /* original 7501, guest PC 0x0c064960 */
if(!s->budget--) { s->failed_pc=0x0c064960u; return 0; }
r[5]+=0x00000001u;
goto P_0c064962;
P_0c064962: /* original 4208, guest PC 0x0c064962 */
if(!s->budget--) { s->failed_pc=0x0c064962u; return 0; }
r[2]<<=2;
goto P_0c064964;
P_0c064964: /* original 02d6, guest PC 0x0c064964 */
if(!s->budget--) { s->failed_pc=0x0c064964u; return 0; }
write(ram,r[2]+r[0],r[13],4);
goto P_0c064966;
P_0c064966: /* original 6153, guest PC 0x0c064966 */
if(!s->budget--) { s->failed_pc=0x0c064966u; return 0; }
r[1]=r[5];
goto P_0c064968;
P_0c064968: /* original 62f2, guest PC 0x0c064968 */
if(!s->budget--) { s->failed_pc=0x0c064968u; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c06496a;
P_0c06496a: /* original 7501, guest PC 0x0c06496a */
if(!s->budget--) { s->failed_pc=0x0c06496au; return 0; }
r[5]+=0x00000001u;
goto P_0c06496c;
P_0c06496c: /* original 4108, guest PC 0x0c06496c */
if(!s->budget--) { s->failed_pc=0x0c06496cu; return 0; }
r[1]<<=2;
goto P_0c06496e;
P_0c06496e: /* original 0126, guest PC 0x0c06496e */
if(!s->budget--) { s->failed_pc=0x0c06496eu; return 0; }
write(ram,r[1]+r[0],r[2],4);
goto P_0c064970;
P_0c064970: /* original 6153, guest PC 0x0c064970 */
if(!s->budget--) { s->failed_pc=0x0c064970u; return 0; }
r[1]=r[5];
goto P_0c064972;
P_0c064972: /* original 7501, guest PC 0x0c064972 */
if(!s->budget--) { s->failed_pc=0x0c064972u; return 0; }
r[5]+=0x00000001u;
goto P_0c064974;
P_0c064974: /* original 4108, guest PC 0x0c064974 */
if(!s->budget--) { s->failed_pc=0x0c064974u; return 0; }
r[1]<<=2;
goto P_0c064976;
P_0c064976: /* original 0146, guest PC 0x0c064976 */
if(!s->budget--) { s->failed_pc=0x0c064976u; return 0; }
write(ram,r[1]+r[0],r[4],4);
goto P_0c064978;
P_0c064978: /* original 61e2, guest PC 0x0c064978 */
if(!s->budget--) { s->failed_pc=0x0c064978u; return 0; }
tmp=read(ram,r[14],4);
r[1]=tmp;
goto P_0c06497a;
P_0c06497a: /* original 6253, guest PC 0x0c06497a */
if(!s->budget--) { s->failed_pc=0x0c06497au; return 0; }
r[2]=r[5];
goto P_0c06497c;
P_0c06497c: /* original 5111, guest PC 0x0c06497c */
if(!s->budget--) { s->failed_pc=0x0c06497cu; return 0; }
r[1]=read(ram,r[1]+4,4);
goto P_0c06497e;
P_0c06497e: /* original 7501, guest PC 0x0c06497e */
if(!s->budget--) { s->failed_pc=0x0c06497eu; return 0; }
r[5]+=0x00000001u;
goto P_0c064980;
P_0c064980: /* original 4208, guest PC 0x0c064980 */
if(!s->budget--) { s->failed_pc=0x0c064980u; return 0; }
r[2]<<=2;
goto P_0c064982;
P_0c064982: /* original 0216, guest PC 0x0c064982 */
if(!s->budget--) { s->failed_pc=0x0c064982u; return 0; }
write(ram,r[2]+r[0],r[1],4);
goto P_0c064984;
P_0c064984: /* original 61e2, guest PC 0x0c064984 */
if(!s->budget--) { s->failed_pc=0x0c064984u; return 0; }
tmp=read(ram,r[14],4);
r[1]=tmp;
goto P_0c064986;
P_0c064986: /* original 6253, guest PC 0x0c064986 */
if(!s->budget--) { s->failed_pc=0x0c064986u; return 0; }
r[2]=r[5];
goto P_0c064988;
P_0c064988: /* original 5112, guest PC 0x0c064988 */
if(!s->budget--) { s->failed_pc=0x0c064988u; return 0; }
r[1]=read(ram,r[1]+8,4);
goto P_0c06498a;
P_0c06498a: /* original 7501, guest PC 0x0c06498a */
if(!s->budget--) { s->failed_pc=0x0c06498au; return 0; }
r[5]+=0x00000001u;
goto P_0c06498c;
P_0c06498c: /* original 4208, guest PC 0x0c06498c */
if(!s->budget--) { s->failed_pc=0x0c06498cu; return 0; }
r[2]<<=2;
goto P_0c06498e;
P_0c06498e: /* original 0216, guest PC 0x0c06498e */
if(!s->budget--) { s->failed_pc=0x0c06498eu; return 0; }
write(ram,r[2]+r[0],r[1],4);
goto P_0c064990;
P_0c064990: /* original 61e2, guest PC 0x0c064990 */
if(!s->budget--) { s->failed_pc=0x0c064990u; return 0; }
tmp=read(ram,r[14],4);
r[1]=tmp;
goto P_0c064992;
P_0c064992: /* original 6253, guest PC 0x0c064992 */
if(!s->budget--) { s->failed_pc=0x0c064992u; return 0; }
r[2]=r[5];
goto P_0c064994;
P_0c064994: /* original 5113, guest PC 0x0c064994 */
if(!s->budget--) { s->failed_pc=0x0c064994u; return 0; }
r[1]=read(ram,r[1]+12,4);
goto P_0c064996;
P_0c064996: /* original 7501, guest PC 0x0c064996 */
if(!s->budget--) { s->failed_pc=0x0c064996u; return 0; }
r[5]+=0x00000001u;
goto P_0c064998;
P_0c064998: /* original 4208, guest PC 0x0c064998 */
if(!s->budget--) { s->failed_pc=0x0c064998u; return 0; }
r[2]<<=2;
goto P_0c06499a;
P_0c06499a: /* original 0216, guest PC 0x0c06499a */
if(!s->budget--) { s->failed_pc=0x0c06499au; return 0; }
write(ram,r[2]+r[0],r[1],4);
goto P_0c06499c;
P_0c06499c: /* original c740, guest PC 0x0c06499c */
if(!s->budget--) { s->failed_pc=0x0c06499cu; return 0; }
r[0]=0x0c064aa0u;
goto P_0c06499e;
P_0c06499e: /* original 6253, guest PC 0x0c06499e */
if(!s->budget--) { s->failed_pc=0x0c06499eu; return 0; }
r[2]=r[5];
goto P_0c0649a0;
P_0c0649a0: /* original f408, guest PC 0x0c0649a0 */
if(!s->budget--) { s->failed_pc=0x0c0649a0u; return 0; }
vf3_matrix_load(s,ram,4,r[0]);
goto P_0c0649a2;
P_0c0649a2: /* original 7501, guest PC 0x0c0649a2 */
if(!s->budget--) { s->failed_pc=0x0c0649a2u; return 0; }
r[5]+=0x00000001u;
goto P_0c0649a4;
P_0c0649a4: /* original d03d, guest PC 0x0c0649a4 */
if(!s->budget--) { s->failed_pc=0x0c0649a4u; return 0; }
r[0]=read(ram,0x0c064a9cu,4);
goto P_0c0649a6;
P_0c0649a6: /* original 4208, guest PC 0x0c0649a6 */
if(!s->budget--) { s->failed_pc=0x0c0649a6u; return 0; }
r[2]<<=2;
goto P_0c0649a8;
P_0c0649a8: /* original 64e2, guest PC 0x0c0649a8 */
if(!s->budget--) { s->failed_pc=0x0c0649a8u; return 0; }
tmp=read(ram,r[14],4);
r[4]=tmp;
goto P_0c0649aa;
P_0c0649aa: /* original e118, guest PC 0x0c0649aa */
if(!s->budget--) { s->failed_pc=0x0c0649aau; return 0; }
r[1]=0x00000018u;
goto P_0c0649ac;
P_0c0649ac: /* original 314c, guest PC 0x0c0649ac */
if(!s->budget--) { s->failed_pc=0x0c0649acu; return 0; }
r[1]+=r[4];
goto P_0c0649ae;
P_0c0649ae: /* original f318, guest PC 0x0c0649ae */
if(!s->budget--) { s->failed_pc=0x0c0649aeu; return 0; }
vf3_matrix_load(s,ram,3,r[1]);
goto P_0c0649b0;
P_0c0649b0: /* original f342, guest PC 0x0c0649b0 */
if(!s->budget--) { s->failed_pc=0x0c0649b0u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'*');
goto P_0c0649b2;
P_0c0649b2: /* original f33d, guest PC 0x0c0649b2 */
if(!s->budget--) { s->failed_pc=0x0c0649b2u; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c0649b4;
P_0c0649b4: /* original 045a, guest PC 0x0c0649b4 */
if(!s->budget--) { s->failed_pc=0x0c0649b4u; return 0; }
r[4]=r[53];
goto P_0c0649b6;
P_0c0649b6: /* original 6143, guest PC 0x0c0649b6 */
if(!s->budget--) { s->failed_pc=0x0c0649b6u; return 0; }
r[1]=r[4];
goto P_0c0649b8;
P_0c0649b8: /* original 4128, guest PC 0x0c0649b8 */
if(!s->budget--) { s->failed_pc=0x0c0649b8u; return 0; }
r[1]<<=16;
goto P_0c0649ba;
P_0c0649ba: /* original 4118, guest PC 0x0c0649ba */
if(!s->budget--) { s->failed_pc=0x0c0649bau; return 0; }
r[1]<<=8;
goto P_0c0649bc;
P_0c0649bc: /* original 6343, guest PC 0x0c0649bc */
if(!s->budget--) { s->failed_pc=0x0c0649bcu; return 0; }
r[3]=r[4];
goto P_0c0649be;
P_0c0649be: /* original 4328, guest PC 0x0c0649be */
if(!s->budget--) { s->failed_pc=0x0c0649beu; return 0; }
r[3]<<=16;
goto P_0c0649c0;
P_0c0649c0: /* original 213b, guest PC 0x0c0649c0 */
if(!s->budget--) { s->failed_pc=0x0c0649c0u; return 0; }
r[1]|=r[3];
goto P_0c0649c2;
P_0c0649c2: /* original 6343, guest PC 0x0c0649c2 */
if(!s->budget--) { s->failed_pc=0x0c0649c2u; return 0; }
r[3]=r[4];
goto P_0c0649c4;
P_0c0649c4: /* original 4318, guest PC 0x0c0649c4 */
if(!s->budget--) { s->failed_pc=0x0c0649c4u; return 0; }
r[3]<<=8;
goto P_0c0649c6;
P_0c0649c6: /* original 213b, guest PC 0x0c0649c6 */
if(!s->budget--) { s->failed_pc=0x0c0649c6u; return 0; }
r[1]|=r[3];
goto P_0c0649c8;
P_0c0649c8: /* original 214b, guest PC 0x0c0649c8 */
if(!s->budget--) { s->failed_pc=0x0c0649c8u; return 0; }
r[1]|=r[4];
goto P_0c0649ca;
P_0c0649ca: /* original 0216, guest PC 0x0c0649ca */
if(!s->budget--) { s->failed_pc=0x0c0649cau; return 0; }
write(ram,r[2]+r[0],r[1],4);
goto P_0c0649cc;
P_0c0649cc: /* original 6172, guest PC 0x0c0649cc */
if(!s->budget--) { s->failed_pc=0x0c0649ccu; return 0; }
tmp=read(ram,r[7],4);
r[1]=tmp;
goto P_0c0649ce;
P_0c0649ce: /* original 6253, guest PC 0x0c0649ce */
if(!s->budget--) { s->failed_pc=0x0c0649ceu; return 0; }
r[2]=r[5];
goto P_0c0649d0;
P_0c0649d0: /* original 5311, guest PC 0x0c0649d0 */
if(!s->budget--) { s->failed_pc=0x0c0649d0u; return 0; }
r[3]=read(ram,r[1]+4,4);
goto P_0c0649d2;
P_0c0649d2: /* original 7501, guest PC 0x0c0649d2 */
if(!s->budget--) { s->failed_pc=0x0c0649d2u; return 0; }
r[5]+=0x00000001u;
goto P_0c0649d4;
P_0c0649d4: /* original 4208, guest PC 0x0c0649d4 */
if(!s->budget--) { s->failed_pc=0x0c0649d4u; return 0; }
r[2]<<=2;
goto P_0c0649d6;
P_0c0649d6: /* original 0236, guest PC 0x0c0649d6 */
if(!s->budget--) { s->failed_pc=0x0c0649d6u; return 0; }
write(ram,r[2]+r[0],r[3],4);
goto P_0c0649d8;
P_0c0649d8: /* original 6172, guest PC 0x0c0649d8 */
if(!s->budget--) { s->failed_pc=0x0c0649d8u; return 0; }
tmp=read(ram,r[7],4);
r[1]=tmp;
goto P_0c0649da;
P_0c0649da: /* original 6253, guest PC 0x0c0649da */
if(!s->budget--) { s->failed_pc=0x0c0649dau; return 0; }
r[2]=r[5];
goto P_0c0649dc;
P_0c0649dc: /* original 5312, guest PC 0x0c0649dc */
if(!s->budget--) { s->failed_pc=0x0c0649dcu; return 0; }
r[3]=read(ram,r[1]+8,4);
goto P_0c0649de;
P_0c0649de: /* original 7501, guest PC 0x0c0649de */
if(!s->budget--) { s->failed_pc=0x0c0649deu; return 0; }
r[5]+=0x00000001u;
goto P_0c0649e0;
P_0c0649e0: /* original 4208, guest PC 0x0c0649e0 */
if(!s->budget--) { s->failed_pc=0x0c0649e0u; return 0; }
r[2]<<=2;
goto P_0c0649e2;
P_0c0649e2: /* original 0236, guest PC 0x0c0649e2 */
if(!s->budget--) { s->failed_pc=0x0c0649e2u; return 0; }
write(ram,r[2]+r[0],r[3],4);
goto P_0c0649e4;
P_0c0649e4: /* original 6253, guest PC 0x0c0649e4 */
if(!s->budget--) { s->failed_pc=0x0c0649e4u; return 0; }
r[2]=r[5];
goto P_0c0649e6;
P_0c0649e6: /* original 7501, guest PC 0x0c0649e6 */
if(!s->budget--) { s->failed_pc=0x0c0649e6u; return 0; }
r[5]+=0x00000001u;
goto P_0c0649e8;
P_0c0649e8: /* original 6172, guest PC 0x0c0649e8 */
if(!s->budget--) { s->failed_pc=0x0c0649e8u; return 0; }
tmp=read(ram,r[7],4);
r[1]=tmp;
goto P_0c0649ea;
P_0c0649ea: /* original 4208, guest PC 0x0c0649ea */
if(!s->budget--) { s->failed_pc=0x0c0649eau; return 0; }
r[2]<<=2;
goto P_0c0649ec;
P_0c0649ec: /* original 5313, guest PC 0x0c0649ec */
if(!s->budget--) { s->failed_pc=0x0c0649ecu; return 0; }
r[3]=read(ram,r[1]+12,4);
goto P_0c0649ee;
P_0c0649ee: /* original 0236, guest PC 0x0c0649ee */
if(!s->budget--) { s->failed_pc=0x0c0649eeu; return 0; }
write(ram,r[2]+r[0],r[3],4);
goto P_0c0649f0;
P_0c0649f0: /* original 6472, guest PC 0x0c0649f0 */
if(!s->budget--) { s->failed_pc=0x0c0649f0u; return 0; }
tmp=read(ram,r[7],4);
r[4]=tmp;
goto P_0c0649f2;
P_0c0649f2: /* original e118, guest PC 0x0c0649f2 */
if(!s->budget--) { s->failed_pc=0x0c0649f2u; return 0; }
r[1]=0x00000018u;
goto P_0c0649f4;
P_0c0649f4: /* original 6253, guest PC 0x0c0649f4 */
if(!s->budget--) { s->failed_pc=0x0c0649f4u; return 0; }
r[2]=r[5];
goto P_0c0649f6;
P_0c0649f6: /* original 7501, guest PC 0x0c0649f6 */
if(!s->budget--) { s->failed_pc=0x0c0649f6u; return 0; }
r[5]+=0x00000001u;
goto P_0c0649f8;
P_0c0649f8: /* original 4208, guest PC 0x0c0649f8 */
if(!s->budget--) { s->failed_pc=0x0c0649f8u; return 0; }
r[2]<<=2;
goto P_0c0649fa;
P_0c0649fa: /* original 314c, guest PC 0x0c0649fa */
if(!s->budget--) { s->failed_pc=0x0c0649fau; return 0; }
r[1]+=r[4];
goto P_0c0649fc;
P_0c0649fc: /* original f318, guest PC 0x0c0649fc */
if(!s->budget--) { s->failed_pc=0x0c0649fcu; return 0; }
vf3_matrix_load(s,ram,3,r[1]);
goto P_0c0649fe;
P_0c0649fe: /* original f342, guest PC 0x0c0649fe */
if(!s->budget--) { s->failed_pc=0x0c0649feu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'*');
goto P_0c064a00;
P_0c064a00: /* original f33d, guest PC 0x0c064a00 */
if(!s->budget--) { s->failed_pc=0x0c064a00u; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c064a02;
P_0c064a02: /* original 045a, guest PC 0x0c064a02 */
if(!s->budget--) { s->failed_pc=0x0c064a02u; return 0; }
r[4]=r[53];
goto P_0c064a04;
P_0c064a04: /* original 6343, guest PC 0x0c064a04 */
if(!s->budget--) { s->failed_pc=0x0c064a04u; return 0; }
r[3]=r[4];
goto P_0c064a06;
P_0c064a06: /* original 4328, guest PC 0x0c064a06 */
if(!s->budget--) { s->failed_pc=0x0c064a06u; return 0; }
r[3]<<=16;
goto P_0c064a08;
P_0c064a08: /* original 4318, guest PC 0x0c064a08 */
if(!s->budget--) { s->failed_pc=0x0c064a08u; return 0; }
r[3]<<=8;
goto P_0c064a0a;
P_0c064a0a: /* original 6143, guest PC 0x0c064a0a */
if(!s->budget--) { s->failed_pc=0x0c064a0au; return 0; }
r[1]=r[4];
goto P_0c064a0c;
P_0c064a0c: /* original 4128, guest PC 0x0c064a0c */
if(!s->budget--) { s->failed_pc=0x0c064a0cu; return 0; }
r[1]<<=16;
goto P_0c064a0e;
P_0c064a0e: /* original 231b, guest PC 0x0c064a0e */
if(!s->budget--) { s->failed_pc=0x0c064a0eu; return 0; }
r[3]|=r[1];
goto P_0c064a10;
P_0c064a10: /* original 6143, guest PC 0x0c064a10 */
if(!s->budget--) { s->failed_pc=0x0c064a10u; return 0; }
r[1]=r[4];
goto P_0c064a12;
P_0c064a12: /* original 4118, guest PC 0x0c064a12 */
if(!s->budget--) { s->failed_pc=0x0c064a12u; return 0; }
r[1]<<=8;
goto P_0c064a14;
P_0c064a14: /* original 231b, guest PC 0x0c064a14 */
if(!s->budget--) { s->failed_pc=0x0c064a14u; return 0; }
r[3]|=r[1];
goto P_0c064a16;
P_0c064a16: /* original 234b, guest PC 0x0c064a16 */
if(!s->budget--) { s->failed_pc=0x0c064a16u; return 0; }
r[3]|=r[4];
goto P_0c064a18;
P_0c064a18: /* original 0236, guest PC 0x0c064a18 */
if(!s->budget--) { s->failed_pc=0x0c064a18u; return 0; }
write(ram,r[2]+r[0],r[3],4);
goto P_0c064a1a;
P_0c064a1a: /* original 6253, guest PC 0x0c064a1a */
if(!s->budget--) { s->failed_pc=0x0c064a1au; return 0; }
r[2]=r[5];
goto P_0c064a1c;
P_0c064a1c: /* original 6162, guest PC 0x0c064a1c */
if(!s->budget--) { s->failed_pc=0x0c064a1cu; return 0; }
tmp=read(ram,r[6],4);
r[1]=tmp;
goto P_0c064a1e;
P_0c064a1e: /* original 7501, guest PC 0x0c064a1e */
if(!s->budget--) { s->failed_pc=0x0c064a1eu; return 0; }
r[5]+=0x00000001u;
goto P_0c064a20;
P_0c064a20: /* original 5311, guest PC 0x0c064a20 */
if(!s->budget--) { s->failed_pc=0x0c064a20u; return 0; }
r[3]=read(ram,r[1]+4,4);
goto P_0c064a22;
P_0c064a22: /* original 4208, guest PC 0x0c064a22 */
if(!s->budget--) { s->failed_pc=0x0c064a22u; return 0; }
r[2]<<=2;
goto P_0c064a24;
P_0c064a24: /* original 0236, guest PC 0x0c064a24 */
if(!s->budget--) { s->failed_pc=0x0c064a24u; return 0; }
write(ram,r[2]+r[0],r[3],4);
goto P_0c064a26;
P_0c064a26: /* original 6253, guest PC 0x0c064a26 */
if(!s->budget--) { s->failed_pc=0x0c064a26u; return 0; }
r[2]=r[5];
goto P_0c064a28;
P_0c064a28: /* original 6162, guest PC 0x0c064a28 */
if(!s->budget--) { s->failed_pc=0x0c064a28u; return 0; }
tmp=read(ram,r[6],4);
r[1]=tmp;
goto P_0c064a2a;
P_0c064a2a: /* original 7501, guest PC 0x0c064a2a */
if(!s->budget--) { s->failed_pc=0x0c064a2au; return 0; }
r[5]+=0x00000001u;
goto P_0c064a2c;
P_0c064a2c: /* original 5312, guest PC 0x0c064a2c */
if(!s->budget--) { s->failed_pc=0x0c064a2cu; return 0; }
r[3]=read(ram,r[1]+8,4);
goto P_0c064a2e;
P_0c064a2e: /* original 4208, guest PC 0x0c064a2e */
if(!s->budget--) { s->failed_pc=0x0c064a2eu; return 0; }
r[2]<<=2;
goto P_0c064a30;
P_0c064a30: /* original 0236, guest PC 0x0c064a30 */
if(!s->budget--) { s->failed_pc=0x0c064a30u; return 0; }
write(ram,r[2]+r[0],r[3],4);
goto P_0c064a32;
P_0c064a32: /* original 6253, guest PC 0x0c064a32 */
if(!s->budget--) { s->failed_pc=0x0c064a32u; return 0; }
r[2]=r[5];
goto P_0c064a34;
P_0c064a34: /* original 6162, guest PC 0x0c064a34 */
if(!s->budget--) { s->failed_pc=0x0c064a34u; return 0; }
tmp=read(ram,r[6],4);
r[1]=tmp;
goto P_0c064a36;
P_0c064a36: /* original 7501, guest PC 0x0c064a36 */
if(!s->budget--) { s->failed_pc=0x0c064a36u; return 0; }
r[5]+=0x00000001u;
goto P_0c064a38;
P_0c064a38: /* original 5313, guest PC 0x0c064a38 */
if(!s->budget--) { s->failed_pc=0x0c064a38u; return 0; }
r[3]=read(ram,r[1]+12,4);
goto P_0c064a3a;
P_0c064a3a: /* original 4208, guest PC 0x0c064a3a */
if(!s->budget--) { s->failed_pc=0x0c064a3au; return 0; }
r[2]<<=2;
goto P_0c064a3c;
P_0c064a3c: /* original 0236, guest PC 0x0c064a3c */
if(!s->budget--) { s->failed_pc=0x0c064a3cu; return 0; }
write(ram,r[2]+r[0],r[3],4);
goto P_0c064a3e;
P_0c064a3e: /* original 6253, guest PC 0x0c064a3e */
if(!s->budget--) { s->failed_pc=0x0c064a3eu; return 0; }
r[2]=r[5];
goto P_0c064a40;
P_0c064a40: /* original 6462, guest PC 0x0c064a40 */
if(!s->budget--) { s->failed_pc=0x0c064a40u; return 0; }
tmp=read(ram,r[6],4);
r[4]=tmp;
goto P_0c064a42;
P_0c064a42: /* original e118, guest PC 0x0c064a42 */
if(!s->budget--) { s->failed_pc=0x0c064a42u; return 0; }
r[1]=0x00000018u;
goto P_0c064a44;
P_0c064a44: /* original 7501, guest PC 0x0c064a44 */
if(!s->budget--) { s->failed_pc=0x0c064a44u; return 0; }
r[5]+=0x00000001u;
goto P_0c064a46;
P_0c064a46: /* original 4208, guest PC 0x0c064a46 */
if(!s->budget--) { s->failed_pc=0x0c064a46u; return 0; }
r[2]<<=2;
goto P_0c064a48;
P_0c064a48: /* original 314c, guest PC 0x0c064a48 */
if(!s->budget--) { s->failed_pc=0x0c064a48u; return 0; }
r[1]+=r[4];
goto P_0c064a4a;
P_0c064a4a: /* original f318, guest PC 0x0c064a4a */
if(!s->budget--) { s->failed_pc=0x0c064a4au; return 0; }
vf3_matrix_load(s,ram,3,r[1]);
goto P_0c064a4c;
P_0c064a4c: /* original f342, guest PC 0x0c064a4c */
if(!s->budget--) { s->failed_pc=0x0c064a4cu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'*');
goto P_0c064a4e;
P_0c064a4e: /* original f33d, guest PC 0x0c064a4e */
if(!s->budget--) { s->failed_pc=0x0c064a4eu; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c064a50;
P_0c064a50: /* original 045a, guest PC 0x0c064a50 */
if(!s->budget--) { s->failed_pc=0x0c064a50u; return 0; }
r[4]=r[53];
goto P_0c064a52;
P_0c064a52: /* original 6343, guest PC 0x0c064a52 */
if(!s->budget--) { s->failed_pc=0x0c064a52u; return 0; }
r[3]=r[4];
goto P_0c064a54;
P_0c064a54: /* original 4328, guest PC 0x0c064a54 */
if(!s->budget--) { s->failed_pc=0x0c064a54u; return 0; }
r[3]<<=16;
goto P_0c064a56;
P_0c064a56: /* original 4318, guest PC 0x0c064a56 */
if(!s->budget--) { s->failed_pc=0x0c064a56u; return 0; }
r[3]<<=8;
goto P_0c064a58;
P_0c064a58: /* original 6143, guest PC 0x0c064a58 */
if(!s->budget--) { s->failed_pc=0x0c064a58u; return 0; }
r[1]=r[4];
goto P_0c064a5a;
P_0c064a5a: /* original 4128, guest PC 0x0c064a5a */
if(!s->budget--) { s->failed_pc=0x0c064a5au; return 0; }
r[1]<<=16;
goto P_0c064a5c;
P_0c064a5c: /* original 231b, guest PC 0x0c064a5c */
if(!s->budget--) { s->failed_pc=0x0c064a5cu; return 0; }
r[3]|=r[1];
goto P_0c064a5e;
P_0c064a5e: /* original 6143, guest PC 0x0c064a5e */
if(!s->budget--) { s->failed_pc=0x0c064a5eu; return 0; }
r[1]=r[4];
goto P_0c064a60;
P_0c064a60: /* original 4118, guest PC 0x0c064a60 */
if(!s->budget--) { s->failed_pc=0x0c064a60u; return 0; }
r[1]<<=8;
goto P_0c064a62;
P_0c064a62: /* original 231b, guest PC 0x0c064a62 */
if(!s->budget--) { s->failed_pc=0x0c064a62u; return 0; }
r[3]|=r[1];
goto P_0c064a64;
P_0c064a64: /* original 234b, guest PC 0x0c064a64 */
if(!s->budget--) { s->failed_pc=0x0c064a64u; return 0; }
r[3]|=r[4];
goto P_0c064a66;
P_0c064a66: /* original 0236, guest PC 0x0c064a66 */
if(!s->budget--) { s->failed_pc=0x0c064a66u; return 0; }
write(ram,r[2]+r[0],r[3],4);
goto P_0c064a68;
P_0c064a68: /* original d30e, guest PC 0x0c064a68 */
if(!s->budget--) { s->failed_pc=0x0c064a68u; return 0; }
r[3]=read(ram,0x0c064aa4u,4);
goto P_0c064a6a;
P_0c064a6a: /* original 4508, guest PC 0x0c064a6a */
if(!s->budget--) { s->failed_pc=0x0c064a6au; return 0; }
r[5]<<=2;
goto P_0c064a6c;
P_0c064a6c: /* original 2352, guest PC 0x0c064a6c */
if(!s->budget--) { s->failed_pc=0x0c064a6cu; return 0; }
write(ram,r[3],r[5],4);
goto P_0c064a6e;
P_0c064a6e: /* original bd50, guest PC 0x0c064a6e */
if(!s->budget--) { s->failed_pc=0x0c064a6eu; return 0; }
target=0x0c064512u; r[16]=0x0c064a72u;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c064a72u) { target=s->pc; goto dispatch; }
goto P_0c064a72;
P_0c064a70: /* original 64d3, guest PC 0x0c064a70 */
if(!s->budget--) { s->failed_pc=0x0c064a70u; return 0; }
r[4]=r[13];
goto P_0c064a72;
P_0c064a72: /* original 6403, guest PC 0x0c064a72 */
if(!s->budget--) { s->failed_pc=0x0c064a72u; return 0; }
r[4]=r[0];
goto P_0c064a74;
P_0c064a74: /* original e500, guest PC 0x0c064a74 */
if(!s->budget--) { s->failed_pc=0x0c064a74u; return 0; }
r[5]=0x00000000u;
goto P_0c064a76;
P_0c064a76: /* original bd37, guest PC 0x0c064a76 */
if(!s->budget--) { s->failed_pc=0x0c064a76u; return 0; }
target=0x0c0644e8u; r[16]=0x0c064a7au;
r[6]=r[5];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c064a7au) { target=s->pc; goto dispatch; }
goto P_0c064a7a;
P_0c064a78: /* original 6653, guest PC 0x0c064a78 */
if(!s->budget--) { s->failed_pc=0x0c064a78u; return 0; }
r[6]=r[5];
goto P_0c064a7a;
P_0c064a7a: /* original 63e2, guest PC 0x0c064a7a */
if(!s->budget--) { s->failed_pc=0x0c064a7au; return 0; }
tmp=read(ram,r[14],4);
r[3]=tmp;
goto P_0c064a7c;
P_0c064a7c: /* original d10a, guest PC 0x0c064a7c */
if(!s->budget--) { s->failed_pc=0x0c064a7cu; return 0; }
r[1]=read(ram,0x0c064aa8u,4);
goto P_0c064a7e;
P_0c064a7e: /* original 5233, guest PC 0x0c064a7e */
if(!s->budget--) { s->failed_pc=0x0c064a7eu; return 0; }
r[2]=read(ram,r[3]+12,4);
goto P_0c064a80;
P_0c064a80: /* original 2122, guest PC 0x0c064a80 */
if(!s->budget--) { s->failed_pc=0x0c064a80u; return 0; }
write(ram,r[1],r[2],4);
goto P_0c064a82;
P_0c064a82: /* original e000, guest PC 0x0c064a82 */
if(!s->budget--) { s->failed_pc=0x0c064a82u; return 0; }
r[0]=0x00000000u;
goto P_0c064a84;
P_0c064a84: /* original 7f10, guest PC 0x0c064a84 */
if(!s->budget--) { s->failed_pc=0x0c064a84u; return 0; }
r[15]+=0x00000010u;
goto P_0c064a86;
P_0c064a86: /* original 4f26, guest PC 0x0c064a86 */
if(!s->budget--) { s->failed_pc=0x0c064a86u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c064a88;
P_0c064a88: /* original 6df6, guest PC 0x0c064a88 */
if(!s->budget--) { s->failed_pc=0x0c064a88u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c064a8a;
P_0c064a8a: /* original 000b, guest PC 0x0c064a8a */
if(!s->budget--) { s->failed_pc=0x0c064a8au; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c064a8c: /* original 6ef6, guest PC 0x0c064a8c */
if(!s->budget--) { s->failed_pc=0x0c064a8cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c064a8eu,s,ram);
P_0c0657fc: /* original 4f22, guest PC 0x0c0657fc */
if(!s->budget--) { s->failed_pc=0x0c0657fcu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0657fe;
P_0c0657fe: /* original 7ff0, guest PC 0x0c0657fe */
if(!s->budget--) { s->failed_pc=0x0c0657feu; return 0; }
r[15]+=0xfffffff0u;
goto P_0c065800;
P_0c065800: /* original 6342, guest PC 0x0c065800 */
if(!s->budget--) { s->failed_pc=0x0c065800u; return 0; }
tmp=read(ram,r[4],4);
r[3]=tmp;
goto P_0c065802;
P_0c065802: /* original 6df3, guest PC 0x0c065802 */
if(!s->budget--) { s->failed_pc=0x0c065802u; return 0; }
r[13]=r[15];
goto P_0c065804;
P_0c065804: /* original 7d04, guest PC 0x0c065804 */
if(!s->budget--) { s->failed_pc=0x0c065804u; return 0; }
r[13]+=0x00000004u;
goto P_0c065806;
P_0c065806: /* original 6ed3, guest PC 0x0c065806 */
if(!s->budget--) { s->failed_pc=0x0c065806u; return 0; }
r[14]=r[13];
goto P_0c065808;
P_0c065808: /* original 2e32, guest PC 0x0c065808 */
if(!s->budget--) { s->failed_pc=0x0c065808u; return 0; }
write(ram,r[14],r[3],4);
goto P_0c06580a;
P_0c06580a: /* original 66e3, guest PC 0x0c06580a */
if(!s->budget--) { s->failed_pc=0x0c06580au; return 0; }
r[6]=r[14];
goto P_0c06580c;
P_0c06580c: /* original 5241, guest PC 0x0c06580c */
if(!s->budget--) { s->failed_pc=0x0c06580cu; return 0; }
r[2]=read(ram,r[4]+4,4);
goto P_0c06580e;
P_0c06580e: /* original 67e3, guest PC 0x0c06580e */
if(!s->budget--) { s->failed_pc=0x0c06580eu; return 0; }
r[7]=r[14];
goto P_0c065810;
P_0c065810: /* original 7604, guest PC 0x0c065810 */
if(!s->budget--) { s->failed_pc=0x0c065810u; return 0; }
r[6]+=0x00000004u;
goto P_0c065812;
P_0c065812: /* original 7708, guest PC 0x0c065812 */
if(!s->budget--) { s->failed_pc=0x0c065812u; return 0; }
r[7]+=0x00000008u;
goto P_0c065814;
P_0c065814: /* original 2622, guest PC 0x0c065814 */
if(!s->budget--) { s->failed_pc=0x0c065814u; return 0; }
write(ram,r[6],r[2],4);
goto P_0c065816;
P_0c065816: /* original 5342, guest PC 0x0c065816 */
if(!s->budget--) { s->failed_pc=0x0c065816u; return 0; }
r[3]=read(ram,r[4]+8,4);
goto P_0c065818;
P_0c065818: /* original d239, guest PC 0x0c065818 */
if(!s->budget--) { s->failed_pc=0x0c065818u; return 0; }
r[2]=read(ram,0x0c065900u,4);
goto P_0c06581a;
P_0c06581a: /* original 2732, guest PC 0x0c06581a */
if(!s->budget--) { s->failed_pc=0x0c06581au; return 0; }
write(ram,r[7],r[3],4);
goto P_0c06581c;
P_0c06581c: /* original 6d22, guest PC 0x0c06581c */
if(!s->budget--) { s->failed_pc=0x0c06581cu; return 0; }
tmp=read(ram,r[2],4);
r[13]=tmp;
goto P_0c06581e;
P_0c06581e: /* original d139, guest PC 0x0c06581e */
if(!s->budget--) { s->failed_pc=0x0c06581eu; return 0; }
r[1]=read(ram,0x0c065904u,4);
goto P_0c065820;
P_0c065820: /* original 6312, guest PC 0x0c065820 */
if(!s->budget--) { s->failed_pc=0x0c065820u; return 0; }
tmp=read(ram,r[1],4);
r[3]=tmp;
goto P_0c065822;
P_0c065822: /* original 2f32, guest PC 0x0c065822 */
if(!s->budget--) { s->failed_pc=0x0c065822u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c065824;
P_0c065824: /* original d338, guest PC 0x0c065824 */
if(!s->budget--) { s->failed_pc=0x0c065824u; return 0; }
r[3]=read(ram,0x0c065908u,4);
goto P_0c065826;
P_0c065826: /* original 6432, guest PC 0x0c065826 */
if(!s->budget--) { s->failed_pc=0x0c065826u; return 0; }
tmp=read(ram,r[3],4);
r[4]=tmp;
goto P_0c065828;
P_0c065828: /* original d038, guest PC 0x0c065828 */
if(!s->budget--) { s->failed_pc=0x0c065828u; return 0; }
r[0]=read(ram,0x0c06590cu,4);
goto P_0c06582a;
P_0c06582a: /* original 6253, guest PC 0x0c06582a */
if(!s->budget--) { s->failed_pc=0x0c06582au; return 0; }
r[2]=r[5];
goto P_0c06582c;
P_0c06582c: /* original 7501, guest PC 0x0c06582c */
if(!s->budget--) { s->failed_pc=0x0c06582cu; return 0; }
r[5]+=0x00000001u;
goto P_0c06582e;
P_0c06582e: /* original 4208, guest PC 0x0c06582e */
if(!s->budget--) { s->failed_pc=0x0c06582eu; return 0; }
r[2]<<=2;
goto P_0c065830;
P_0c065830: /* original 02d6, guest PC 0x0c065830 */
if(!s->budget--) { s->failed_pc=0x0c065830u; return 0; }
write(ram,r[2]+r[0],r[13],4);
goto P_0c065832;
P_0c065832: /* original 6153, guest PC 0x0c065832 */
if(!s->budget--) { s->failed_pc=0x0c065832u; return 0; }
r[1]=r[5];
goto P_0c065834;
P_0c065834: /* original 62f2, guest PC 0x0c065834 */
if(!s->budget--) { s->failed_pc=0x0c065834u; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c065836;
P_0c065836: /* original 7501, guest PC 0x0c065836 */
if(!s->budget--) { s->failed_pc=0x0c065836u; return 0; }
r[5]+=0x00000001u;
goto P_0c065838;
P_0c065838: /* original 4108, guest PC 0x0c065838 */
if(!s->budget--) { s->failed_pc=0x0c065838u; return 0; }
r[1]<<=2;
goto P_0c06583a;
P_0c06583a: /* original 0126, guest PC 0x0c06583a */
if(!s->budget--) { s->failed_pc=0x0c06583au; return 0; }
write(ram,r[1]+r[0],r[2],4);
goto P_0c06583c;
P_0c06583c: /* original 6153, guest PC 0x0c06583c */
if(!s->budget--) { s->failed_pc=0x0c06583cu; return 0; }
r[1]=r[5];
goto P_0c06583e;
P_0c06583e: /* original 7501, guest PC 0x0c06583e */
if(!s->budget--) { s->failed_pc=0x0c06583eu; return 0; }
r[5]+=0x00000001u;
goto P_0c065840;
P_0c065840: /* original 4108, guest PC 0x0c065840 */
if(!s->budget--) { s->failed_pc=0x0c065840u; return 0; }
r[1]<<=2;
goto P_0c065842;
P_0c065842: /* original 0146, guest PC 0x0c065842 */
if(!s->budget--) { s->failed_pc=0x0c065842u; return 0; }
write(ram,r[1]+r[0],r[4],4);
goto P_0c065844;
P_0c065844: /* original 61e2, guest PC 0x0c065844 */
if(!s->budget--) { s->failed_pc=0x0c065844u; return 0; }
tmp=read(ram,r[14],4);
r[1]=tmp;
goto P_0c065846;
P_0c065846: /* original 6253, guest PC 0x0c065846 */
if(!s->budget--) { s->failed_pc=0x0c065846u; return 0; }
r[2]=r[5];
goto P_0c065848;
P_0c065848: /* original 5111, guest PC 0x0c065848 */
if(!s->budget--) { s->failed_pc=0x0c065848u; return 0; }
r[1]=read(ram,r[1]+4,4);
goto P_0c06584a;
P_0c06584a: /* original 7501, guest PC 0x0c06584a */
if(!s->budget--) { s->failed_pc=0x0c06584au; return 0; }
r[5]+=0x00000001u;
goto P_0c06584c;
P_0c06584c: /* original 4208, guest PC 0x0c06584c */
if(!s->budget--) { s->failed_pc=0x0c06584cu; return 0; }
r[2]<<=2;
goto P_0c06584e;
P_0c06584e: /* original 0216, guest PC 0x0c06584e */
if(!s->budget--) { s->failed_pc=0x0c06584eu; return 0; }
write(ram,r[2]+r[0],r[1],4);
goto P_0c065850;
P_0c065850: /* original 61e2, guest PC 0x0c065850 */
if(!s->budget--) { s->failed_pc=0x0c065850u; return 0; }
tmp=read(ram,r[14],4);
r[1]=tmp;
goto P_0c065852;
P_0c065852: /* original 6253, guest PC 0x0c065852 */
if(!s->budget--) { s->failed_pc=0x0c065852u; return 0; }
r[2]=r[5];
goto P_0c065854;
P_0c065854: /* original 5112, guest PC 0x0c065854 */
if(!s->budget--) { s->failed_pc=0x0c065854u; return 0; }
r[1]=read(ram,r[1]+8,4);
goto P_0c065856;
P_0c065856: /* original 7501, guest PC 0x0c065856 */
if(!s->budget--) { s->failed_pc=0x0c065856u; return 0; }
r[5]+=0x00000001u;
goto P_0c065858;
P_0c065858: /* original 4208, guest PC 0x0c065858 */
if(!s->budget--) { s->failed_pc=0x0c065858u; return 0; }
r[2]<<=2;
goto P_0c06585a;
P_0c06585a: /* original 0216, guest PC 0x0c06585a */
if(!s->budget--) { s->failed_pc=0x0c06585au; return 0; }
write(ram,r[2]+r[0],r[1],4);
goto P_0c06585c;
P_0c06585c: /* original 61e2, guest PC 0x0c06585c */
if(!s->budget--) { s->failed_pc=0x0c06585cu; return 0; }
tmp=read(ram,r[14],4);
r[1]=tmp;
goto P_0c06585e;
P_0c06585e: /* original 6253, guest PC 0x0c06585e */
if(!s->budget--) { s->failed_pc=0x0c06585eu; return 0; }
r[2]=r[5];
goto P_0c065860;
P_0c065860: /* original 5113, guest PC 0x0c065860 */
if(!s->budget--) { s->failed_pc=0x0c065860u; return 0; }
r[1]=read(ram,r[1]+12,4);
goto P_0c065862;
P_0c065862: /* original 7501, guest PC 0x0c065862 */
if(!s->budget--) { s->failed_pc=0x0c065862u; return 0; }
r[5]+=0x00000001u;
goto P_0c065864;
P_0c065864: /* original 4208, guest PC 0x0c065864 */
if(!s->budget--) { s->failed_pc=0x0c065864u; return 0; }
r[2]<<=2;
goto P_0c065866;
P_0c065866: /* original 0216, guest PC 0x0c065866 */
if(!s->budget--) { s->failed_pc=0x0c065866u; return 0; }
write(ram,r[2]+r[0],r[1],4);
goto P_0c065868;
P_0c065868: /* original 61e2, guest PC 0x0c065868 */
if(!s->budget--) { s->failed_pc=0x0c065868u; return 0; }
tmp=read(ram,r[14],4);
r[1]=tmp;
goto P_0c06586a;
P_0c06586a: /* original 6253, guest PC 0x0c06586a */
if(!s->budget--) { s->failed_pc=0x0c06586au; return 0; }
r[2]=r[5];
goto P_0c06586c;
P_0c06586c: /* original 5114, guest PC 0x0c06586c */
if(!s->budget--) { s->failed_pc=0x0c06586cu; return 0; }
r[1]=read(ram,r[1]+16,4);
goto P_0c06586e;
P_0c06586e: /* original 7501, guest PC 0x0c06586e */
if(!s->budget--) { s->failed_pc=0x0c06586eu; return 0; }
r[5]+=0x00000001u;
goto P_0c065870;
P_0c065870: /* original 4208, guest PC 0x0c065870 */
if(!s->budget--) { s->failed_pc=0x0c065870u; return 0; }
r[2]<<=2;
goto P_0c065872;
P_0c065872: /* original 0216, guest PC 0x0c065872 */
if(!s->budget--) { s->failed_pc=0x0c065872u; return 0; }
write(ram,r[2]+r[0],r[1],4);
goto P_0c065874;
P_0c065874: /* original 6162, guest PC 0x0c065874 */
if(!s->budget--) { s->failed_pc=0x0c065874u; return 0; }
tmp=read(ram,r[6],4);
r[1]=tmp;
goto P_0c065876;
P_0c065876: /* original 6253, guest PC 0x0c065876 */
if(!s->budget--) { s->failed_pc=0x0c065876u; return 0; }
r[2]=r[5];
goto P_0c065878;
P_0c065878: /* original 5111, guest PC 0x0c065878 */
if(!s->budget--) { s->failed_pc=0x0c065878u; return 0; }
r[1]=read(ram,r[1]+4,4);
goto P_0c06587a;
P_0c06587a: /* original 7501, guest PC 0x0c06587a */
if(!s->budget--) { s->failed_pc=0x0c06587au; return 0; }
r[5]+=0x00000001u;
goto P_0c06587c;
P_0c06587c: /* original 4208, guest PC 0x0c06587c */
if(!s->budget--) { s->failed_pc=0x0c06587cu; return 0; }
r[2]<<=2;
goto P_0c06587e;
P_0c06587e: /* original 0216, guest PC 0x0c06587e */
if(!s->budget--) { s->failed_pc=0x0c06587eu; return 0; }
write(ram,r[2]+r[0],r[1],4);
goto P_0c065880;
P_0c065880: /* original 6162, guest PC 0x0c065880 */
if(!s->budget--) { s->failed_pc=0x0c065880u; return 0; }
tmp=read(ram,r[6],4);
r[1]=tmp;
goto P_0c065882;
P_0c065882: /* original 6253, guest PC 0x0c065882 */
if(!s->budget--) { s->failed_pc=0x0c065882u; return 0; }
r[2]=r[5];
goto P_0c065884;
P_0c065884: /* original 5112, guest PC 0x0c065884 */
if(!s->budget--) { s->failed_pc=0x0c065884u; return 0; }
r[1]=read(ram,r[1]+8,4);
goto P_0c065886;
P_0c065886: /* original 7501, guest PC 0x0c065886 */
if(!s->budget--) { s->failed_pc=0x0c065886u; return 0; }
r[5]+=0x00000001u;
goto P_0c065888;
P_0c065888: /* original 4208, guest PC 0x0c065888 */
if(!s->budget--) { s->failed_pc=0x0c065888u; return 0; }
r[2]<<=2;
goto P_0c06588a;
P_0c06588a: /* original 0216, guest PC 0x0c06588a */
if(!s->budget--) { s->failed_pc=0x0c06588au; return 0; }
write(ram,r[2]+r[0],r[1],4);
goto P_0c06588c;
P_0c06588c: /* original 6162, guest PC 0x0c06588c */
if(!s->budget--) { s->failed_pc=0x0c06588cu; return 0; }
tmp=read(ram,r[6],4);
r[1]=tmp;
goto P_0c06588e;
P_0c06588e: /* original 6253, guest PC 0x0c06588e */
if(!s->budget--) { s->failed_pc=0x0c06588eu; return 0; }
r[2]=r[5];
goto P_0c065890;
P_0c065890: /* original 5113, guest PC 0x0c065890 */
if(!s->budget--) { s->failed_pc=0x0c065890u; return 0; }
r[1]=read(ram,r[1]+12,4);
goto P_0c065892;
P_0c065892: /* original 7501, guest PC 0x0c065892 */
if(!s->budget--) { s->failed_pc=0x0c065892u; return 0; }
r[5]+=0x00000001u;
goto P_0c065894;
P_0c065894: /* original 4208, guest PC 0x0c065894 */
if(!s->budget--) { s->failed_pc=0x0c065894u; return 0; }
r[2]<<=2;
goto P_0c065896;
P_0c065896: /* original 0216, guest PC 0x0c065896 */
if(!s->budget--) { s->failed_pc=0x0c065896u; return 0; }
write(ram,r[2]+r[0],r[1],4);
goto P_0c065898;
P_0c065898: /* original 6162, guest PC 0x0c065898 */
if(!s->budget--) { s->failed_pc=0x0c065898u; return 0; }
tmp=read(ram,r[6],4);
r[1]=tmp;
goto P_0c06589a;
P_0c06589a: /* original 6253, guest PC 0x0c06589a */
if(!s->budget--) { s->failed_pc=0x0c06589au; return 0; }
r[2]=r[5];
goto P_0c06589c;
P_0c06589c: /* original 5114, guest PC 0x0c06589c */
if(!s->budget--) { s->failed_pc=0x0c06589cu; return 0; }
r[1]=read(ram,r[1]+16,4);
goto P_0c06589e;
P_0c06589e: /* original 7501, guest PC 0x0c06589e */
if(!s->budget--) { s->failed_pc=0x0c06589eu; return 0; }
r[5]+=0x00000001u;
goto P_0c0658a0;
P_0c0658a0: /* original 4208, guest PC 0x0c0658a0 */
if(!s->budget--) { s->failed_pc=0x0c0658a0u; return 0; }
r[2]<<=2;
goto P_0c0658a2;
P_0c0658a2: /* original 0216, guest PC 0x0c0658a2 */
if(!s->budget--) { s->failed_pc=0x0c0658a2u; return 0; }
write(ram,r[2]+r[0],r[1],4);
goto P_0c0658a4;
P_0c0658a4: /* original 6172, guest PC 0x0c0658a4 */
if(!s->budget--) { s->failed_pc=0x0c0658a4u; return 0; }
tmp=read(ram,r[7],4);
r[1]=tmp;
goto P_0c0658a6;
P_0c0658a6: /* original 6253, guest PC 0x0c0658a6 */
if(!s->budget--) { s->failed_pc=0x0c0658a6u; return 0; }
r[2]=r[5];
goto P_0c0658a8;
P_0c0658a8: /* original 5111, guest PC 0x0c0658a8 */
if(!s->budget--) { s->failed_pc=0x0c0658a8u; return 0; }
r[1]=read(ram,r[1]+4,4);
goto P_0c0658aa;
P_0c0658aa: /* original 7501, guest PC 0x0c0658aa */
if(!s->budget--) { s->failed_pc=0x0c0658aau; return 0; }
r[5]+=0x00000001u;
goto P_0c0658ac;
P_0c0658ac: /* original 4208, guest PC 0x0c0658ac */
if(!s->budget--) { s->failed_pc=0x0c0658acu; return 0; }
r[2]<<=2;
goto P_0c0658ae;
P_0c0658ae: /* original 0216, guest PC 0x0c0658ae */
if(!s->budget--) { s->failed_pc=0x0c0658aeu; return 0; }
write(ram,r[2]+r[0],r[1],4);
goto P_0c0658b0;
P_0c0658b0: /* original 6253, guest PC 0x0c0658b0 */
if(!s->budget--) { s->failed_pc=0x0c0658b0u; return 0; }
r[2]=r[5];
goto P_0c0658b2;
P_0c0658b2: /* original 7501, guest PC 0x0c0658b2 */
if(!s->budget--) { s->failed_pc=0x0c0658b2u; return 0; }
r[5]+=0x00000001u;
goto P_0c0658b4;
P_0c0658b4: /* original 6172, guest PC 0x0c0658b4 */
if(!s->budget--) { s->failed_pc=0x0c0658b4u; return 0; }
tmp=read(ram,r[7],4);
r[1]=tmp;
goto P_0c0658b6;
P_0c0658b6: /* original 4208, guest PC 0x0c0658b6 */
if(!s->budget--) { s->failed_pc=0x0c0658b6u; return 0; }
r[2]<<=2;
goto P_0c0658b8;
P_0c0658b8: /* original 5112, guest PC 0x0c0658b8 */
if(!s->budget--) { s->failed_pc=0x0c0658b8u; return 0; }
r[1]=read(ram,r[1]+8,4);
goto P_0c0658ba;
P_0c0658ba: /* original 0216, guest PC 0x0c0658ba */
if(!s->budget--) { s->failed_pc=0x0c0658bau; return 0; }
write(ram,r[2]+r[0],r[1],4);
goto P_0c0658bc;
P_0c0658bc: /* original 6172, guest PC 0x0c0658bc */
if(!s->budget--) { s->failed_pc=0x0c0658bcu; return 0; }
tmp=read(ram,r[7],4);
r[1]=tmp;
goto P_0c0658be;
P_0c0658be: /* original 6253, guest PC 0x0c0658be */
if(!s->budget--) { s->failed_pc=0x0c0658beu; return 0; }
r[2]=r[5];
goto P_0c0658c0;
P_0c0658c0: /* original 5113, guest PC 0x0c0658c0 */
if(!s->budget--) { s->failed_pc=0x0c0658c0u; return 0; }
r[1]=read(ram,r[1]+12,4);
goto P_0c0658c2;
P_0c0658c2: /* original 7501, guest PC 0x0c0658c2 */
if(!s->budget--) { s->failed_pc=0x0c0658c2u; return 0; }
r[5]+=0x00000001u;
goto P_0c0658c4;
P_0c0658c4: /* original 4208, guest PC 0x0c0658c4 */
if(!s->budget--) { s->failed_pc=0x0c0658c4u; return 0; }
r[2]<<=2;
goto P_0c0658c6;
P_0c0658c6: /* original 0216, guest PC 0x0c0658c6 */
if(!s->budget--) { s->failed_pc=0x0c0658c6u; return 0; }
write(ram,r[2]+r[0],r[1],4);
goto P_0c0658c8;
P_0c0658c8: /* original 6172, guest PC 0x0c0658c8 */
if(!s->budget--) { s->failed_pc=0x0c0658c8u; return 0; }
tmp=read(ram,r[7],4);
r[1]=tmp;
goto P_0c0658ca;
P_0c0658ca: /* original 6253, guest PC 0x0c0658ca */
if(!s->budget--) { s->failed_pc=0x0c0658cau; return 0; }
r[2]=r[5];
goto P_0c0658cc;
P_0c0658cc: /* original 5114, guest PC 0x0c0658cc */
if(!s->budget--) { s->failed_pc=0x0c0658ccu; return 0; }
r[1]=read(ram,r[1]+16,4);
goto P_0c0658ce;
P_0c0658ce: /* original 7501, guest PC 0x0c0658ce */
if(!s->budget--) { s->failed_pc=0x0c0658ceu; return 0; }
r[5]+=0x00000001u;
goto P_0c0658d0;
P_0c0658d0: /* original 4208, guest PC 0x0c0658d0 */
if(!s->budget--) { s->failed_pc=0x0c0658d0u; return 0; }
r[2]<<=2;
goto P_0c0658d2;
P_0c0658d2: /* original 0216, guest PC 0x0c0658d2 */
if(!s->budget--) { s->failed_pc=0x0c0658d2u; return 0; }
write(ram,r[2]+r[0],r[1],4);
goto P_0c0658d4;
P_0c0658d4: /* original d211, guest PC 0x0c0658d4 */
if(!s->budget--) { s->failed_pc=0x0c0658d4u; return 0; }
r[2]=read(ram,0x0c06591cu,4);
goto P_0c0658d6;
P_0c0658d6: /* original 4508, guest PC 0x0c0658d6 */
if(!s->budget--) { s->failed_pc=0x0c0658d6u; return 0; }
r[5]<<=2;
goto P_0c0658d8;
P_0c0658d8: /* original 2252, guest PC 0x0c0658d8 */
if(!s->budget--) { s->failed_pc=0x0c0658d8u; return 0; }
write(ram,r[2],r[5],4);
goto P_0c0658da;
P_0c0658da: /* original d311, guest PC 0x0c0658da */
if(!s->budget--) { s->failed_pc=0x0c0658dau; return 0; }
r[3]=read(ram,0x0c065920u,4);
goto P_0c0658dc;
P_0c0658dc: /* original 430b, guest PC 0x0c0658dc */
if(!s->budget--) { s->failed_pc=0x0c0658dcu; return 0; }
target=r[3];
r[16]=0x0c0658e0u;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0658e0u) { target=s->pc; goto dispatch; }
goto P_0c0658e0;
P_0c0658de: /* original 64d3, guest PC 0x0c0658de */
if(!s->budget--) { s->failed_pc=0x0c0658deu; return 0; }
r[4]=r[13];
goto P_0c0658e0;
P_0c0658e0: /* original d210, guest PC 0x0c0658e0 */
if(!s->budget--) { s->failed_pc=0x0c0658e0u; return 0; }
r[2]=read(ram,0x0c065924u,4);
goto P_0c0658e2;
P_0c0658e2: /* original 6403, guest PC 0x0c0658e2 */
if(!s->budget--) { s->failed_pc=0x0c0658e2u; return 0; }
r[4]=r[0];
goto P_0c0658e4;
P_0c0658e4: /* original e500, guest PC 0x0c0658e4 */
if(!s->budget--) { s->failed_pc=0x0c0658e4u; return 0; }
r[5]=0x00000000u;
goto P_0c0658e6;
P_0c0658e6: /* original 420b, guest PC 0x0c0658e6 */
if(!s->budget--) { s->failed_pc=0x0c0658e6u; return 0; }
target=r[2];
r[16]=0x0c0658eau;
r[6]=r[5];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0658eau) { target=s->pc; goto dispatch; }
goto P_0c0658ea;
P_0c0658e8: /* original 6653, guest PC 0x0c0658e8 */
if(!s->budget--) { s->failed_pc=0x0c0658e8u; return 0; }
r[6]=r[5];
goto P_0c0658ea;
P_0c0658ea: /* original 62e2, guest PC 0x0c0658ea */
if(!s->budget--) { s->failed_pc=0x0c0658eau; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c0658ec;
P_0c0658ec: /* original d10e, guest PC 0x0c0658ec */
if(!s->budget--) { s->failed_pc=0x0c0658ecu; return 0; }
r[1]=read(ram,0x0c065928u,4);
goto P_0c0658ee;
P_0c0658ee: /* original 5323, guest PC 0x0c0658ee */
if(!s->budget--) { s->failed_pc=0x0c0658eeu; return 0; }
r[3]=read(ram,r[2]+12,4);
goto P_0c0658f0;
P_0c0658f0: /* original 2132, guest PC 0x0c0658f0 */
if(!s->budget--) { s->failed_pc=0x0c0658f0u; return 0; }
write(ram,r[1],r[3],4);
goto P_0c0658f2;
P_0c0658f2: /* original e000, guest PC 0x0c0658f2 */
if(!s->budget--) { s->failed_pc=0x0c0658f2u; return 0; }
r[0]=0x00000000u;
goto P_0c0658f4;
P_0c0658f4: /* original 7f10, guest PC 0x0c0658f4 */
if(!s->budget--) { s->failed_pc=0x0c0658f4u; return 0; }
r[15]+=0x00000010u;
goto P_0c0658f6;
P_0c0658f6: /* original 4f26, guest PC 0x0c0658f6 */
if(!s->budget--) { s->failed_pc=0x0c0658f6u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0658f8;
P_0c0658f8: /* original 6df6, guest PC 0x0c0658f8 */
if(!s->budget--) { s->failed_pc=0x0c0658f8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0658fa;
P_0c0658fa: /* original 000b, guest PC 0x0c0658fa */
if(!s->budget--) { s->failed_pc=0x0c0658fau; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0658fc: /* original 6ef6, guest PC 0x0c0658fc */
if(!s->budget--) { s->failed_pc=0x0c0658fcu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0658feu,s,ram);
P_0c065932: /* original 4f22, guest PC 0x0c065932 */
if(!s->budget--) { s->failed_pc=0x0c065932u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c065934;
P_0c065934: /* original 7ff0, guest PC 0x0c065934 */
if(!s->budget--) { s->failed_pc=0x0c065934u; return 0; }
r[15]+=0xfffffff0u;
goto P_0c065936;
P_0c065936: /* original 6df3, guest PC 0x0c065936 */
if(!s->budget--) { s->failed_pc=0x0c065936u; return 0; }
r[13]=r[15];
goto P_0c065938;
P_0c065938: /* original 6342, guest PC 0x0c065938 */
if(!s->budget--) { s->failed_pc=0x0c065938u; return 0; }
tmp=read(ram,r[4],4);
r[3]=tmp;
goto P_0c06593a;
P_0c06593a: /* original 7d04, guest PC 0x0c06593a */
if(!s->budget--) { s->failed_pc=0x0c06593au; return 0; }
r[13]+=0x00000004u;
goto P_0c06593c;
P_0c06593c: /* original 6ed3, guest PC 0x0c06593c */
if(!s->budget--) { s->failed_pc=0x0c06593cu; return 0; }
r[14]=r[13];
goto P_0c06593e;
P_0c06593e: /* original 67e3, guest PC 0x0c06593e */
if(!s->budget--) { s->failed_pc=0x0c06593eu; return 0; }
r[7]=r[14];
goto P_0c065940;
P_0c065940: /* original 2e32, guest PC 0x0c065940 */
if(!s->budget--) { s->failed_pc=0x0c065940u; return 0; }
write(ram,r[14],r[3],4);
goto P_0c065942;
P_0c065942: /* original 66e3, guest PC 0x0c065942 */
if(!s->budget--) { s->failed_pc=0x0c065942u; return 0; }
r[6]=r[14];
goto P_0c065944;
P_0c065944: /* original 5241, guest PC 0x0c065944 */
if(!s->budget--) { s->failed_pc=0x0c065944u; return 0; }
r[2]=read(ram,r[4]+4,4);
goto P_0c065946;
P_0c065946: /* original 7704, guest PC 0x0c065946 */
if(!s->budget--) { s->failed_pc=0x0c065946u; return 0; }
r[7]+=0x00000004u;
goto P_0c065948;
P_0c065948: /* original 2722, guest PC 0x0c065948 */
if(!s->budget--) { s->failed_pc=0x0c065948u; return 0; }
write(ram,r[7],r[2],4);
goto P_0c06594a;
P_0c06594a: /* original 7608, guest PC 0x0c06594a */
if(!s->budget--) { s->failed_pc=0x0c06594au; return 0; }
r[6]+=0x00000008u;
goto P_0c06594c;
P_0c06594c: /* original 5342, guest PC 0x0c06594c */
if(!s->budget--) { s->failed_pc=0x0c06594cu; return 0; }
r[3]=read(ram,r[4]+8,4);
goto P_0c06594e;
P_0c06594e: /* original 2632, guest PC 0x0c06594e */
if(!s->budget--) { s->failed_pc=0x0c06594eu; return 0; }
write(ram,r[6],r[3],4);
goto P_0c065950;
P_0c065950: /* original d2b0, guest PC 0x0c065950 */
if(!s->budget--) { s->failed_pc=0x0c065950u; return 0; }
r[2]=read(ram,0x0c065c14u,4);
goto P_0c065952;
P_0c065952: /* original 6d22, guest PC 0x0c065952 */
if(!s->budget--) { s->failed_pc=0x0c065952u; return 0; }
tmp=read(ram,r[2],4);
r[13]=tmp;
goto P_0c065954;
P_0c065954: /* original d1b0, guest PC 0x0c065954 */
if(!s->budget--) { s->failed_pc=0x0c065954u; return 0; }
r[1]=read(ram,0x0c065c18u,4);
goto P_0c065956;
P_0c065956: /* original 6312, guest PC 0x0c065956 */
if(!s->budget--) { s->failed_pc=0x0c065956u; return 0; }
tmp=read(ram,r[1],4);
r[3]=tmp;
goto P_0c065958;
P_0c065958: /* original 2f32, guest PC 0x0c065958 */
if(!s->budget--) { s->failed_pc=0x0c065958u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c06595a;
P_0c06595a: /* original d3b0, guest PC 0x0c06595a */
if(!s->budget--) { s->failed_pc=0x0c06595au; return 0; }
r[3]=read(ram,0x0c065c1cu,4);
goto P_0c06595c;
P_0c06595c: /* original 6432, guest PC 0x0c06595c */
if(!s->budget--) { s->failed_pc=0x0c06595cu; return 0; }
tmp=read(ram,r[3],4);
r[4]=tmp;
goto P_0c06595e;
P_0c06595e: /* original d0b0, guest PC 0x0c06595e */
if(!s->budget--) { s->failed_pc=0x0c06595eu; return 0; }
r[0]=read(ram,0x0c065c20u,4);
goto P_0c065960;
P_0c065960: /* original 6253, guest PC 0x0c065960 */
if(!s->budget--) { s->failed_pc=0x0c065960u; return 0; }
r[2]=r[5];
goto P_0c065962;
P_0c065962: /* original 7501, guest PC 0x0c065962 */
if(!s->budget--) { s->failed_pc=0x0c065962u; return 0; }
r[5]+=0x00000001u;
goto P_0c065964;
P_0c065964: /* original 4208, guest PC 0x0c065964 */
if(!s->budget--) { s->failed_pc=0x0c065964u; return 0; }
r[2]<<=2;
goto P_0c065966;
P_0c065966: /* original 02d6, guest PC 0x0c065966 */
if(!s->budget--) { s->failed_pc=0x0c065966u; return 0; }
write(ram,r[2]+r[0],r[13],4);
goto P_0c065968;
P_0c065968: /* original 6153, guest PC 0x0c065968 */
if(!s->budget--) { s->failed_pc=0x0c065968u; return 0; }
r[1]=r[5];
goto P_0c06596a;
P_0c06596a: /* original 7501, guest PC 0x0c06596a */
if(!s->budget--) { s->failed_pc=0x0c06596au; return 0; }
r[5]+=0x00000001u;
goto P_0c06596c;
P_0c06596c: /* original 62f2, guest PC 0x0c06596c */
if(!s->budget--) { s->failed_pc=0x0c06596cu; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c06596e;
P_0c06596e: /* original 4108, guest PC 0x0c06596e */
if(!s->budget--) { s->failed_pc=0x0c06596eu; return 0; }
r[1]<<=2;
goto P_0c065970;
P_0c065970: /* original 0126, guest PC 0x0c065970 */
if(!s->budget--) { s->failed_pc=0x0c065970u; return 0; }
write(ram,r[1]+r[0],r[2],4);
goto P_0c065972;
P_0c065972: /* original 6153, guest PC 0x0c065972 */
if(!s->budget--) { s->failed_pc=0x0c065972u; return 0; }
r[1]=r[5];
goto P_0c065974;
P_0c065974: /* original 7501, guest PC 0x0c065974 */
if(!s->budget--) { s->failed_pc=0x0c065974u; return 0; }
r[5]+=0x00000001u;
goto P_0c065976;
P_0c065976: /* original 4108, guest PC 0x0c065976 */
if(!s->budget--) { s->failed_pc=0x0c065976u; return 0; }
r[1]<<=2;
goto P_0c065978;
P_0c065978: /* original 0146, guest PC 0x0c065978 */
if(!s->budget--) { s->failed_pc=0x0c065978u; return 0; }
write(ram,r[1]+r[0],r[4],4);
goto P_0c06597a;
P_0c06597a: /* original 6253, guest PC 0x0c06597a */
if(!s->budget--) { s->failed_pc=0x0c06597au; return 0; }
r[2]=r[5];
goto P_0c06597c;
P_0c06597c: /* original 61e2, guest PC 0x0c06597c */
if(!s->budget--) { s->failed_pc=0x0c06597cu; return 0; }
tmp=read(ram,r[14],4);
r[1]=tmp;
goto P_0c06597e;
P_0c06597e: /* original 7501, guest PC 0x0c06597e */
if(!s->budget--) { s->failed_pc=0x0c06597eu; return 0; }
r[5]+=0x00000001u;
goto P_0c065980;
P_0c065980: /* original 5111, guest PC 0x0c065980 */
if(!s->budget--) { s->failed_pc=0x0c065980u; return 0; }
r[1]=read(ram,r[1]+4,4);
goto P_0c065982;
P_0c065982: /* original 4208, guest PC 0x0c065982 */
if(!s->budget--) { s->failed_pc=0x0c065982u; return 0; }
r[2]<<=2;
goto P_0c065984;
P_0c065984: /* original 0216, guest PC 0x0c065984 */
if(!s->budget--) { s->failed_pc=0x0c065984u; return 0; }
write(ram,r[2]+r[0],r[1],4);
goto P_0c065986;
P_0c065986: /* original 6253, guest PC 0x0c065986 */
if(!s->budget--) { s->failed_pc=0x0c065986u; return 0; }
r[2]=r[5];
goto P_0c065988;
P_0c065988: /* original 61e2, guest PC 0x0c065988 */
if(!s->budget--) { s->failed_pc=0x0c065988u; return 0; }
tmp=read(ram,r[14],4);
r[1]=tmp;
goto P_0c06598a;
P_0c06598a: /* original 7501, guest PC 0x0c06598a */
if(!s->budget--) { s->failed_pc=0x0c06598au; return 0; }
r[5]+=0x00000001u;
goto P_0c06598c;
P_0c06598c: /* original 5112, guest PC 0x0c06598c */
if(!s->budget--) { s->failed_pc=0x0c06598cu; return 0; }
r[1]=read(ram,r[1]+8,4);
goto P_0c06598e;
P_0c06598e: /* original 4208, guest PC 0x0c06598e */
if(!s->budget--) { s->failed_pc=0x0c06598eu; return 0; }
r[2]<<=2;
goto P_0c065990;
P_0c065990: /* original 0216, guest PC 0x0c065990 */
if(!s->budget--) { s->failed_pc=0x0c065990u; return 0; }
write(ram,r[2]+r[0],r[1],4);
goto P_0c065992;
P_0c065992: /* original 6253, guest PC 0x0c065992 */
if(!s->budget--) { s->failed_pc=0x0c065992u; return 0; }
r[2]=r[5];
goto P_0c065994;
P_0c065994: /* original 61e2, guest PC 0x0c065994 */
if(!s->budget--) { s->failed_pc=0x0c065994u; return 0; }
tmp=read(ram,r[14],4);
r[1]=tmp;
goto P_0c065996;
P_0c065996: /* original 7501, guest PC 0x0c065996 */
if(!s->budget--) { s->failed_pc=0x0c065996u; return 0; }
r[5]+=0x00000001u;
goto P_0c065998;
P_0c065998: /* original 5113, guest PC 0x0c065998 */
if(!s->budget--) { s->failed_pc=0x0c065998u; return 0; }
r[1]=read(ram,r[1]+12,4);
goto P_0c06599a;
P_0c06599a: /* original 4208, guest PC 0x0c06599a */
if(!s->budget--) { s->failed_pc=0x0c06599au; return 0; }
r[2]<<=2;
goto P_0c06599c;
P_0c06599c: /* original 0216, guest PC 0x0c06599c */
if(!s->budget--) { s->failed_pc=0x0c06599cu; return 0; }
write(ram,r[2]+r[0],r[1],4);
goto P_0c06599e;
P_0c06599e: /* original 6253, guest PC 0x0c06599e */
if(!s->budget--) { s->failed_pc=0x0c06599eu; return 0; }
r[2]=r[5];
goto P_0c0659a0;
P_0c0659a0: /* original c7a0, guest PC 0x0c0659a0 */
if(!s->budget--) { s->failed_pc=0x0c0659a0u; return 0; }
r[0]=0x0c065c24u;
goto P_0c0659a2;
P_0c0659a2: /* original 7501, guest PC 0x0c0659a2 */
if(!s->budget--) { s->failed_pc=0x0c0659a2u; return 0; }
r[5]+=0x00000001u;
goto P_0c0659a4;
P_0c0659a4: /* original f408, guest PC 0x0c0659a4 */
if(!s->budget--) { s->failed_pc=0x0c0659a4u; return 0; }
vf3_matrix_load(s,ram,4,r[0]);
goto P_0c0659a6;
P_0c0659a6: /* original 4208, guest PC 0x0c0659a6 */
if(!s->budget--) { s->failed_pc=0x0c0659a6u; return 0; }
r[2]<<=2;
goto P_0c0659a8;
P_0c0659a8: /* original d09d, guest PC 0x0c0659a8 */
if(!s->budget--) { s->failed_pc=0x0c0659a8u; return 0; }
r[0]=read(ram,0x0c065c20u,4);
goto P_0c0659aa;
P_0c0659aa: /* original e110, guest PC 0x0c0659aa */
if(!s->budget--) { s->failed_pc=0x0c0659aau; return 0; }
r[1]=0x00000010u;
goto P_0c0659ac;
P_0c0659ac: /* original 64e2, guest PC 0x0c0659ac */
if(!s->budget--) { s->failed_pc=0x0c0659acu; return 0; }
tmp=read(ram,r[14],4);
r[4]=tmp;
goto P_0c0659ae;
P_0c0659ae: /* original 314c, guest PC 0x0c0659ae */
if(!s->budget--) { s->failed_pc=0x0c0659aeu; return 0; }
r[1]+=r[4];
goto P_0c0659b0;
P_0c0659b0: /* original f318, guest PC 0x0c0659b0 */
if(!s->budget--) { s->failed_pc=0x0c0659b0u; return 0; }
vf3_matrix_load(s,ram,3,r[1]);
goto P_0c0659b2;
P_0c0659b2: /* original f342, guest PC 0x0c0659b2 */
if(!s->budget--) { s->failed_pc=0x0c0659b2u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'*');
goto P_0c0659b4;
P_0c0659b4: /* original f33d, guest PC 0x0c0659b4 */
if(!s->budget--) { s->failed_pc=0x0c0659b4u; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c0659b6;
P_0c0659b6: /* original 045a, guest PC 0x0c0659b6 */
if(!s->budget--) { s->failed_pc=0x0c0659b6u; return 0; }
r[4]=r[53];
goto P_0c0659b8;
P_0c0659b8: /* original 6143, guest PC 0x0c0659b8 */
if(!s->budget--) { s->failed_pc=0x0c0659b8u; return 0; }
r[1]=r[4];
goto P_0c0659ba;
P_0c0659ba: /* original 4128, guest PC 0x0c0659ba */
if(!s->budget--) { s->failed_pc=0x0c0659bau; return 0; }
r[1]<<=16;
goto P_0c0659bc;
P_0c0659bc: /* original 4118, guest PC 0x0c0659bc */
if(!s->budget--) { s->failed_pc=0x0c0659bcu; return 0; }
r[1]<<=8;
goto P_0c0659be;
P_0c0659be: /* original 6343, guest PC 0x0c0659be */
if(!s->budget--) { s->failed_pc=0x0c0659beu; return 0; }
r[3]=r[4];
goto P_0c0659c0;
P_0c0659c0: /* original 4328, guest PC 0x0c0659c0 */
if(!s->budget--) { s->failed_pc=0x0c0659c0u; return 0; }
r[3]<<=16;
goto P_0c0659c2;
P_0c0659c2: /* original 213b, guest PC 0x0c0659c2 */
if(!s->budget--) { s->failed_pc=0x0c0659c2u; return 0; }
r[1]|=r[3];
goto P_0c0659c4;
P_0c0659c4: /* original 6343, guest PC 0x0c0659c4 */
if(!s->budget--) { s->failed_pc=0x0c0659c4u; return 0; }
r[3]=r[4];
goto P_0c0659c6;
P_0c0659c6: /* original 4318, guest PC 0x0c0659c6 */
if(!s->budget--) { s->failed_pc=0x0c0659c6u; return 0; }
r[3]<<=8;
goto P_0c0659c8;
P_0c0659c8: /* original 213b, guest PC 0x0c0659c8 */
if(!s->budget--) { s->failed_pc=0x0c0659c8u; return 0; }
r[1]|=r[3];
goto P_0c0659ca;
P_0c0659ca: /* original 214b, guest PC 0x0c0659ca */
if(!s->budget--) { s->failed_pc=0x0c0659cau; return 0; }
r[1]|=r[4];
goto P_0c0659cc;
P_0c0659cc: /* original 0216, guest PC 0x0c0659cc */
if(!s->budget--) { s->failed_pc=0x0c0659ccu; return 0; }
write(ram,r[2]+r[0],r[1],4);
goto P_0c0659ce;
P_0c0659ce: /* original 6253, guest PC 0x0c0659ce */
if(!s->budget--) { s->failed_pc=0x0c0659ceu; return 0; }
r[2]=r[5];
goto P_0c0659d0;
P_0c0659d0: /* original 6172, guest PC 0x0c0659d0 */
if(!s->budget--) { s->failed_pc=0x0c0659d0u; return 0; }
tmp=read(ram,r[7],4);
r[1]=tmp;
goto P_0c0659d2;
P_0c0659d2: /* original 7501, guest PC 0x0c0659d2 */
if(!s->budget--) { s->failed_pc=0x0c0659d2u; return 0; }
r[5]+=0x00000001u;
goto P_0c0659d4;
P_0c0659d4: /* original 5311, guest PC 0x0c0659d4 */
if(!s->budget--) { s->failed_pc=0x0c0659d4u; return 0; }
r[3]=read(ram,r[1]+4,4);
goto P_0c0659d6;
P_0c0659d6: /* original 4208, guest PC 0x0c0659d6 */
if(!s->budget--) { s->failed_pc=0x0c0659d6u; return 0; }
r[2]<<=2;
goto P_0c0659d8;
P_0c0659d8: /* original 0236, guest PC 0x0c0659d8 */
if(!s->budget--) { s->failed_pc=0x0c0659d8u; return 0; }
write(ram,r[2]+r[0],r[3],4);
goto P_0c0659da;
P_0c0659da: /* original 6253, guest PC 0x0c0659da */
if(!s->budget--) { s->failed_pc=0x0c0659dau; return 0; }
r[2]=r[5];
goto P_0c0659dc;
P_0c0659dc: /* original 6172, guest PC 0x0c0659dc */
if(!s->budget--) { s->failed_pc=0x0c0659dcu; return 0; }
tmp=read(ram,r[7],4);
r[1]=tmp;
goto P_0c0659de;
P_0c0659de: /* original 7501, guest PC 0x0c0659de */
if(!s->budget--) { s->failed_pc=0x0c0659deu; return 0; }
r[5]+=0x00000001u;
goto P_0c0659e0;
P_0c0659e0: /* original 5312, guest PC 0x0c0659e0 */
if(!s->budget--) { s->failed_pc=0x0c0659e0u; return 0; }
r[3]=read(ram,r[1]+8,4);
goto P_0c0659e2;
P_0c0659e2: /* original 4208, guest PC 0x0c0659e2 */
if(!s->budget--) { s->failed_pc=0x0c0659e2u; return 0; }
r[2]<<=2;
goto P_0c0659e4;
P_0c0659e4: /* original 0236, guest PC 0x0c0659e4 */
if(!s->budget--) { s->failed_pc=0x0c0659e4u; return 0; }
write(ram,r[2]+r[0],r[3],4);
goto P_0c0659e6;
P_0c0659e6: /* original 6253, guest PC 0x0c0659e6 */
if(!s->budget--) { s->failed_pc=0x0c0659e6u; return 0; }
r[2]=r[5];
goto P_0c0659e8;
P_0c0659e8: /* original 7501, guest PC 0x0c0659e8 */
if(!s->budget--) { s->failed_pc=0x0c0659e8u; return 0; }
r[5]+=0x00000001u;
goto P_0c0659ea;
P_0c0659ea: /* original 4208, guest PC 0x0c0659ea */
if(!s->budget--) { s->failed_pc=0x0c0659eau; return 0; }
r[2]<<=2;
goto P_0c0659ec;
P_0c0659ec: /* original 6172, guest PC 0x0c0659ec */
if(!s->budget--) { s->failed_pc=0x0c0659ecu; return 0; }
tmp=read(ram,r[7],4);
r[1]=tmp;
goto P_0c0659ee;
P_0c0659ee: /* original 5313, guest PC 0x0c0659ee */
if(!s->budget--) { s->failed_pc=0x0c0659eeu; return 0; }
r[3]=read(ram,r[1]+12,4);
goto P_0c0659f0;
P_0c0659f0: /* original 0236, guest PC 0x0c0659f0 */
if(!s->budget--) { s->failed_pc=0x0c0659f0u; return 0; }
write(ram,r[2]+r[0],r[3],4);
goto P_0c0659f2;
P_0c0659f2: /* original 6253, guest PC 0x0c0659f2 */
if(!s->budget--) { s->failed_pc=0x0c0659f2u; return 0; }
r[2]=r[5];
goto P_0c0659f4;
P_0c0659f4: /* original 6472, guest PC 0x0c0659f4 */
if(!s->budget--) { s->failed_pc=0x0c0659f4u; return 0; }
tmp=read(ram,r[7],4);
r[4]=tmp;
goto P_0c0659f6;
P_0c0659f6: /* original e110, guest PC 0x0c0659f6 */
if(!s->budget--) { s->failed_pc=0x0c0659f6u; return 0; }
r[1]=0x00000010u;
goto P_0c0659f8;
P_0c0659f8: /* original 7501, guest PC 0x0c0659f8 */
if(!s->budget--) { s->failed_pc=0x0c0659f8u; return 0; }
r[5]+=0x00000001u;
goto P_0c0659fa;
P_0c0659fa: /* original 4208, guest PC 0x0c0659fa */
if(!s->budget--) { s->failed_pc=0x0c0659fau; return 0; }
r[2]<<=2;
goto P_0c0659fc;
P_0c0659fc: /* original 314c, guest PC 0x0c0659fc */
if(!s->budget--) { s->failed_pc=0x0c0659fcu; return 0; }
r[1]+=r[4];
goto P_0c0659fe;
P_0c0659fe: /* original f318, guest PC 0x0c0659fe */
if(!s->budget--) { s->failed_pc=0x0c0659feu; return 0; }
vf3_matrix_load(s,ram,3,r[1]);
goto P_0c065a00;
P_0c065a00: /* original f342, guest PC 0x0c065a00 */
if(!s->budget--) { s->failed_pc=0x0c065a00u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'*');
goto P_0c065a02;
P_0c065a02: /* original f33d, guest PC 0x0c065a02 */
if(!s->budget--) { s->failed_pc=0x0c065a02u; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c065a04;
P_0c065a04: /* original 045a, guest PC 0x0c065a04 */
if(!s->budget--) { s->failed_pc=0x0c065a04u; return 0; }
r[4]=r[53];
goto P_0c065a06;
P_0c065a06: /* original 6343, guest PC 0x0c065a06 */
if(!s->budget--) { s->failed_pc=0x0c065a06u; return 0; }
r[3]=r[4];
goto P_0c065a08;
P_0c065a08: /* original 4328, guest PC 0x0c065a08 */
if(!s->budget--) { s->failed_pc=0x0c065a08u; return 0; }
r[3]<<=16;
goto P_0c065a0a;
P_0c065a0a: /* original 4318, guest PC 0x0c065a0a */
if(!s->budget--) { s->failed_pc=0x0c065a0au; return 0; }
r[3]<<=8;
goto P_0c065a0c;
P_0c065a0c: /* original 6143, guest PC 0x0c065a0c */
if(!s->budget--) { s->failed_pc=0x0c065a0cu; return 0; }
r[1]=r[4];
goto P_0c065a0e;
P_0c065a0e: /* original 4128, guest PC 0x0c065a0e */
if(!s->budget--) { s->failed_pc=0x0c065a0eu; return 0; }
r[1]<<=16;
goto P_0c065a10;
P_0c065a10: /* original 231b, guest PC 0x0c065a10 */
if(!s->budget--) { s->failed_pc=0x0c065a10u; return 0; }
r[3]|=r[1];
goto P_0c065a12;
P_0c065a12: /* original 6143, guest PC 0x0c065a12 */
if(!s->budget--) { s->failed_pc=0x0c065a12u; return 0; }
r[1]=r[4];
goto P_0c065a14;
P_0c065a14: /* original 4118, guest PC 0x0c065a14 */
if(!s->budget--) { s->failed_pc=0x0c065a14u; return 0; }
r[1]<<=8;
goto P_0c065a16;
P_0c065a16: /* original 231b, guest PC 0x0c065a16 */
if(!s->budget--) { s->failed_pc=0x0c065a16u; return 0; }
r[3]|=r[1];
goto P_0c065a18;
P_0c065a18: /* original 234b, guest PC 0x0c065a18 */
if(!s->budget--) { s->failed_pc=0x0c065a18u; return 0; }
r[3]|=r[4];
goto P_0c065a1a;
P_0c065a1a: /* original 0236, guest PC 0x0c065a1a */
if(!s->budget--) { s->failed_pc=0x0c065a1au; return 0; }
write(ram,r[2]+r[0],r[3],4);
goto P_0c065a1c;
P_0c065a1c: /* original 6162, guest PC 0x0c065a1c */
if(!s->budget--) { s->failed_pc=0x0c065a1cu; return 0; }
tmp=read(ram,r[6],4);
r[1]=tmp;
goto P_0c065a1e;
P_0c065a1e: /* original 6253, guest PC 0x0c065a1e */
if(!s->budget--) { s->failed_pc=0x0c065a1eu; return 0; }
r[2]=r[5];
goto P_0c065a20;
P_0c065a20: /* original 5311, guest PC 0x0c065a20 */
if(!s->budget--) { s->failed_pc=0x0c065a20u; return 0; }
r[3]=read(ram,r[1]+4,4);
goto P_0c065a22;
P_0c065a22: /* original 7501, guest PC 0x0c065a22 */
if(!s->budget--) { s->failed_pc=0x0c065a22u; return 0; }
r[5]+=0x00000001u;
goto P_0c065a24;
P_0c065a24: /* original 4208, guest PC 0x0c065a24 */
if(!s->budget--) { s->failed_pc=0x0c065a24u; return 0; }
r[2]<<=2;
goto P_0c065a26;
P_0c065a26: /* original 0236, guest PC 0x0c065a26 */
if(!s->budget--) { s->failed_pc=0x0c065a26u; return 0; }
write(ram,r[2]+r[0],r[3],4);
goto P_0c065a28;
P_0c065a28: /* original 6253, guest PC 0x0c065a28 */
if(!s->budget--) { s->failed_pc=0x0c065a28u; return 0; }
r[2]=r[5];
goto P_0c065a2a;
P_0c065a2a: /* original 7501, guest PC 0x0c065a2a */
if(!s->budget--) { s->failed_pc=0x0c065a2au; return 0; }
r[5]+=0x00000001u;
goto P_0c065a2c;
P_0c065a2c: /* original 6162, guest PC 0x0c065a2c */
if(!s->budget--) { s->failed_pc=0x0c065a2cu; return 0; }
tmp=read(ram,r[6],4);
r[1]=tmp;
goto P_0c065a2e;
P_0c065a2e: /* original 4208, guest PC 0x0c065a2e */
if(!s->budget--) { s->failed_pc=0x0c065a2eu; return 0; }
r[2]<<=2;
goto P_0c065a30;
P_0c065a30: /* original 5312, guest PC 0x0c065a30 */
if(!s->budget--) { s->failed_pc=0x0c065a30u; return 0; }
r[3]=read(ram,r[1]+8,4);
goto P_0c065a32;
P_0c065a32: /* original 0236, guest PC 0x0c065a32 */
if(!s->budget--) { s->failed_pc=0x0c065a32u; return 0; }
write(ram,r[2]+r[0],r[3],4);
goto P_0c065a34;
P_0c065a34: /* original 6162, guest PC 0x0c065a34 */
if(!s->budget--) { s->failed_pc=0x0c065a34u; return 0; }
tmp=read(ram,r[6],4);
r[1]=tmp;
goto P_0c065a36;
P_0c065a36: /* original 6253, guest PC 0x0c065a36 */
if(!s->budget--) { s->failed_pc=0x0c065a36u; return 0; }
r[2]=r[5];
goto P_0c065a38;
P_0c065a38: /* original 5313, guest PC 0x0c065a38 */
if(!s->budget--) { s->failed_pc=0x0c065a38u; return 0; }
r[3]=read(ram,r[1]+12,4);
goto P_0c065a3a;
P_0c065a3a: /* original 7501, guest PC 0x0c065a3a */
if(!s->budget--) { s->failed_pc=0x0c065a3au; return 0; }
r[5]+=0x00000001u;
goto P_0c065a3c;
P_0c065a3c: /* original 4208, guest PC 0x0c065a3c */
if(!s->budget--) { s->failed_pc=0x0c065a3cu; return 0; }
r[2]<<=2;
goto P_0c065a3e;
P_0c065a3e: /* original 0236, guest PC 0x0c065a3e */
if(!s->budget--) { s->failed_pc=0x0c065a3eu; return 0; }
write(ram,r[2]+r[0],r[3],4);
goto P_0c065a40;
P_0c065a40: /* original 6462, guest PC 0x0c065a40 */
if(!s->budget--) { s->failed_pc=0x0c065a40u; return 0; }
tmp=read(ram,r[6],4);
r[4]=tmp;
goto P_0c065a42;
P_0c065a42: /* original e110, guest PC 0x0c065a42 */
if(!s->budget--) { s->failed_pc=0x0c065a42u; return 0; }
r[1]=0x00000010u;
goto P_0c065a44;
P_0c065a44: /* original 6253, guest PC 0x0c065a44 */
if(!s->budget--) { s->failed_pc=0x0c065a44u; return 0; }
r[2]=r[5];
goto P_0c065a46;
P_0c065a46: /* original 7501, guest PC 0x0c065a46 */
if(!s->budget--) { s->failed_pc=0x0c065a46u; return 0; }
r[5]+=0x00000001u;
goto P_0c065a48;
P_0c065a48: /* original 4208, guest PC 0x0c065a48 */
if(!s->budget--) { s->failed_pc=0x0c065a48u; return 0; }
r[2]<<=2;
goto P_0c065a4a;
P_0c065a4a: /* original 314c, guest PC 0x0c065a4a */
if(!s->budget--) { s->failed_pc=0x0c065a4au; return 0; }
r[1]+=r[4];
goto P_0c065a4c;
P_0c065a4c: /* original f318, guest PC 0x0c065a4c */
if(!s->budget--) { s->failed_pc=0x0c065a4cu; return 0; }
vf3_matrix_load(s,ram,3,r[1]);
goto P_0c065a4e;
P_0c065a4e: /* original f342, guest PC 0x0c065a4e */
if(!s->budget--) { s->failed_pc=0x0c065a4eu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'*');
goto P_0c065a50;
P_0c065a50: /* original f33d, guest PC 0x0c065a50 */
if(!s->budget--) { s->failed_pc=0x0c065a50u; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c065a52;
P_0c065a52: /* original 045a, guest PC 0x0c065a52 */
if(!s->budget--) { s->failed_pc=0x0c065a52u; return 0; }
r[4]=r[53];
goto P_0c065a54;
P_0c065a54: /* original 6343, guest PC 0x0c065a54 */
if(!s->budget--) { s->failed_pc=0x0c065a54u; return 0; }
r[3]=r[4];
goto P_0c065a56;
P_0c065a56: /* original 4328, guest PC 0x0c065a56 */
if(!s->budget--) { s->failed_pc=0x0c065a56u; return 0; }
r[3]<<=16;
goto P_0c065a58;
P_0c065a58: /* original 4318, guest PC 0x0c065a58 */
if(!s->budget--) { s->failed_pc=0x0c065a58u; return 0; }
r[3]<<=8;
goto P_0c065a5a;
P_0c065a5a: /* original 6143, guest PC 0x0c065a5a */
if(!s->budget--) { s->failed_pc=0x0c065a5au; return 0; }
r[1]=r[4];
goto P_0c065a5c;
P_0c065a5c: /* original 4128, guest PC 0x0c065a5c */
if(!s->budget--) { s->failed_pc=0x0c065a5cu; return 0; }
r[1]<<=16;
goto P_0c065a5e;
P_0c065a5e: /* original 231b, guest PC 0x0c065a5e */
if(!s->budget--) { s->failed_pc=0x0c065a5eu; return 0; }
r[3]|=r[1];
goto P_0c065a60;
P_0c065a60: /* original 6143, guest PC 0x0c065a60 */
if(!s->budget--) { s->failed_pc=0x0c065a60u; return 0; }
r[1]=r[4];
goto P_0c065a62;
P_0c065a62: /* original 4118, guest PC 0x0c065a62 */
if(!s->budget--) { s->failed_pc=0x0c065a62u; return 0; }
r[1]<<=8;
goto P_0c065a64;
P_0c065a64: /* original 231b, guest PC 0x0c065a64 */
if(!s->budget--) { s->failed_pc=0x0c065a64u; return 0; }
r[3]|=r[1];
goto P_0c065a66;
P_0c065a66: /* original 234b, guest PC 0x0c065a66 */
if(!s->budget--) { s->failed_pc=0x0c065a66u; return 0; }
r[3]|=r[4];
goto P_0c065a68;
P_0c065a68: /* original 0236, guest PC 0x0c065a68 */
if(!s->budget--) { s->failed_pc=0x0c065a68u; return 0; }
write(ram,r[2]+r[0],r[3],4);
goto P_0c065a6a;
P_0c065a6a: /* original 4508, guest PC 0x0c065a6a */
if(!s->budget--) { s->failed_pc=0x0c065a6au; return 0; }
r[5]<<=2;
goto P_0c065a6c;
P_0c065a6c: /* original d36e, guest PC 0x0c065a6c */
if(!s->budget--) { s->failed_pc=0x0c065a6cu; return 0; }
r[3]=read(ram,0x0c065c28u,4);
goto P_0c065a6e;
P_0c065a6e: /* original 2352, guest PC 0x0c065a6e */
if(!s->budget--) { s->failed_pc=0x0c065a6eu; return 0; }
write(ram,r[3],r[5],4);
goto P_0c065a70;
P_0c065a70: /* original d26e, guest PC 0x0c065a70 */
if(!s->budget--) { s->failed_pc=0x0c065a70u; return 0; }
r[2]=read(ram,0x0c065c2cu,4);
goto P_0c065a72;
P_0c065a72: /* original 420b, guest PC 0x0c065a72 */
if(!s->budget--) { s->failed_pc=0x0c065a72u; return 0; }
target=r[2];
r[16]=0x0c065a76u;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c065a76u) { target=s->pc; goto dispatch; }
goto P_0c065a76;
P_0c065a74: /* original 64d3, guest PC 0x0c065a74 */
if(!s->budget--) { s->failed_pc=0x0c065a74u; return 0; }
r[4]=r[13];
goto P_0c065a76;
P_0c065a76: /* original 6403, guest PC 0x0c065a76 */
if(!s->budget--) { s->failed_pc=0x0c065a76u; return 0; }
r[4]=r[0];
goto P_0c065a78;
P_0c065a78: /* original d36d, guest PC 0x0c065a78 */
if(!s->budget--) { s->failed_pc=0x0c065a78u; return 0; }
r[3]=read(ram,0x0c065c30u,4);
goto P_0c065a7a;
P_0c065a7a: /* original e500, guest PC 0x0c065a7a */
if(!s->budget--) { s->failed_pc=0x0c065a7au; return 0; }
r[5]=0x00000000u;
goto P_0c065a7c;
P_0c065a7c: /* original 430b, guest PC 0x0c065a7c */
if(!s->budget--) { s->failed_pc=0x0c065a7cu; return 0; }
target=r[3];
r[16]=0x0c065a80u;
r[6]=r[5];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c065a80u) { target=s->pc; goto dispatch; }
goto P_0c065a80;
P_0c065a7e: /* original 6653, guest PC 0x0c065a7e */
if(!s->budget--) { s->failed_pc=0x0c065a7eu; return 0; }
r[6]=r[5];
goto P_0c065a80;
P_0c065a80: /* original 63e2, guest PC 0x0c065a80 */
if(!s->budget--) { s->failed_pc=0x0c065a80u; return 0; }
tmp=read(ram,r[14],4);
r[3]=tmp;
goto P_0c065a82;
P_0c065a82: /* original 5233, guest PC 0x0c065a82 */
if(!s->budget--) { s->failed_pc=0x0c065a82u; return 0; }
r[2]=read(ram,r[3]+12,4);
goto P_0c065a84;
P_0c065a84: /* original d16b, guest PC 0x0c065a84 */
if(!s->budget--) { s->failed_pc=0x0c065a84u; return 0; }
r[1]=read(ram,0x0c065c34u,4);
goto P_0c065a86;
P_0c065a86: /* original 2122, guest PC 0x0c065a86 */
if(!s->budget--) { s->failed_pc=0x0c065a86u; return 0; }
write(ram,r[1],r[2],4);
goto P_0c065a88;
P_0c065a88: /* original e000, guest PC 0x0c065a88 */
if(!s->budget--) { s->failed_pc=0x0c065a88u; return 0; }
r[0]=0x00000000u;
goto P_0c065a8a;
P_0c065a8a: /* original 7f10, guest PC 0x0c065a8a */
if(!s->budget--) { s->failed_pc=0x0c065a8au; return 0; }
r[15]+=0x00000010u;
goto P_0c065a8c;
P_0c065a8c: /* original 4f26, guest PC 0x0c065a8c */
if(!s->budget--) { s->failed_pc=0x0c065a8cu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c065a8e;
P_0c065a8e: /* original 6df6, guest PC 0x0c065a8e */
if(!s->budget--) { s->failed_pc=0x0c065a8eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c065a90;
P_0c065a90: /* original 000b, guest PC 0x0c065a90 */
if(!s->budget--) { s->failed_pc=0x0c065a90u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c065a92: /* original 6ef6, guest PC 0x0c065a92 */
if(!s->budget--) { s->failed_pc=0x0c065a92u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c065a94u,s,ram);
P_0c08583c: /* original 4f22, guest PC 0x0c08583c */
if(!s->budget--) { s->failed_pc=0x0c08583cu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c08583e;
P_0c08583e: /* original 7fe0, guest PC 0x0c08583e */
if(!s->budget--) { s->failed_pc=0x0c08583eu; return 0; }
r[15]+=0xffffffe0u;
goto P_0c085840;
P_0c085840: /* original 81f8, guest PC 0x0c085840 */
if(!s->budget--) { s->failed_pc=0x0c085840u; return 0; }
write(ram,r[15]+16,r[0],2);
goto P_0c085842;
P_0c085842: /* original 6053, guest PC 0x0c085842 */
if(!s->budget--) { s->failed_pc=0x0c085842u; return 0; }
r[0]=r[5];
goto P_0c085844;
P_0c085844: /* original 81f2, guest PC 0x0c085844 */
if(!s->budget--) { s->failed_pc=0x0c085844u; return 0; }
write(ram,r[15]+4,r[0],2);
goto P_0c085846;
P_0c085846: /* original 6063, guest PC 0x0c085846 */
if(!s->budget--) { s->failed_pc=0x0c085846u; return 0; }
r[0]=r[6];
goto P_0c085848;
P_0c085848: /* original 81fa, guest PC 0x0c085848 */
if(!s->budget--) { s->failed_pc=0x0c085848u; return 0; }
write(ram,r[15]+20,r[0],2);
goto P_0c08584a;
P_0c08584a: /* original e008, guest PC 0x0c08584a */
if(!s->budget--) { s->failed_pc=0x0c08584au; return 0; }
r[0]=0x00000008u;
goto P_0c08584c;
P_0c08584c: /* original 5dfd, guest PC 0x0c08584c */
if(!s->budget--) { s->failed_pc=0x0c08584cu; return 0; }
r[13]=read(ram,r[15]+52,4);
goto P_0c08584e;
P_0c08584e: /* original ff4a, guest PC 0x0c08584e */
if(!s->budget--) { s->failed_pc=0x0c08584eu; return 0; }
vf3_matrix_store(s,ram,4,r[15]);
goto P_0c085850;
P_0c085850: /* original ff57, guest PC 0x0c085850 */
if(!s->budget--) { s->failed_pc=0x0c085850u; return 0; }
vf3_matrix_store(s,ram,5,r[15]+r[0]);
goto P_0c085852;
P_0c085852: /* original e00c, guest PC 0x0c085852 */
if(!s->budget--) { s->failed_pc=0x0c085852u; return 0; }
r[0]=0x0000000cu;
goto P_0c085854;
P_0c085854: /* original 5efe, guest PC 0x0c085854 */
if(!s->budget--) { s->failed_pc=0x0c085854u; return 0; }
r[14]=read(ram,r[15]+56,4);
goto P_0c085856;
P_0c085856: /* original ff67, guest PC 0x0c085856 */
if(!s->budget--) { s->failed_pc=0x0c085856u; return 0; }
vf3_matrix_store(s,ram,6,r[15]+r[0]);
goto P_0c085858;
P_0c085858: /* original c720, guest PC 0x0c085858 */
if(!s->budget--) { s->failed_pc=0x0c085858u; return 0; }
r[0]=0x0c0858dcu;
goto P_0c08585a;
P_0c08585a: /* original ff08, guest PC 0x0c08585a */
if(!s->budget--) { s->failed_pc=0x0c08585au; return 0; }
vf3_matrix_load(s,ram,15,r[0]);
goto P_0c08585c;
P_0c08585c: /* original d320, guest PC 0x0c08585c */
if(!s->budget--) { s->failed_pc=0x0c08585cu; return 0; }
r[3]=read(ram,0x0c0858e0u,4);
goto P_0c08585e;
P_0c08585e: /* original 85f8, guest PC 0x0c08585e */
if(!s->budget--) { s->failed_pc=0x0c08585eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+16,2);
goto P_0c085860;
P_0c085860: /* original 430b, guest PC 0x0c085860 */
if(!s->budget--) { s->failed_pc=0x0c085860u; return 0; }
target=r[3];
r[16]=0x0c085864u;
r[4]=r[0];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c085864u) { target=s->pc; goto dispatch; }
goto P_0c085864;
P_0c085862: /* original 6403, guest PC 0x0c085862 */
if(!s->budget--) { s->failed_pc=0x0c085862u; return 0; }
r[4]=r[0];
goto P_0c085864;
P_0c085864: /* original f3fc, guest PC 0x0c085864 */
if(!s->budget--) { s->failed_pc=0x0c085864u; return 0; }
vf3_matrix_move(s,3,15);
goto P_0c085866;
P_0c085866: /* original f302, guest PC 0x0c085866 */
if(!s->budget--) { s->failed_pc=0x0c085866u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[0],r[18],'*');
goto P_0c085868;
P_0c085868: /* original e01c, guest PC 0x0c085868 */
if(!s->budget--) { s->failed_pc=0x0c085868u; return 0; }
r[0]=0x0000001cu;
goto P_0c08586a;
P_0c08586a: /* original ff37, guest PC 0x0c08586a */
if(!s->budget--) { s->failed_pc=0x0c08586au; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c08586c;
P_0c08586c: /* original d31d, guest PC 0x0c08586c */
if(!s->budget--) { s->failed_pc=0x0c08586cu; return 0; }
r[3]=read(ram,0x0c0858e4u,4);
goto P_0c08586e;
P_0c08586e: /* original 85fa, guest PC 0x0c08586e */
if(!s->budget--) { s->failed_pc=0x0c08586eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+20,2);
goto P_0c085870;
P_0c085870: /* original 430b, guest PC 0x0c085870 */
if(!s->budget--) { s->failed_pc=0x0c085870u; return 0; }
target=r[3];
r[16]=0x0c085874u;
r[4]=r[0];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c085874u) { target=s->pc; goto dispatch; }
goto P_0c085874;
P_0c085872: /* original 6403, guest PC 0x0c085872 */
if(!s->budget--) { s->failed_pc=0x0c085872u; return 0; }
r[4]=r[0];
goto P_0c085874;
P_0c085874: /* original e01c, guest PC 0x0c085874 */
if(!s->budget--) { s->failed_pc=0x0c085874u; return 0; }
r[0]=0x0000001cu;
goto P_0c085876;
P_0c085876: /* original f2c8, guest PC 0x0c085876 */
if(!s->budget--) { s->failed_pc=0x0c085876u; return 0; }
vf3_matrix_load(s,ram,2,r[12]);
goto P_0c085878;
P_0c085878: /* original f3f6, guest PC 0x0c085878 */
if(!s->budget--) { s->failed_pc=0x0c085878u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c08587a;
P_0c08587a: /* original f4fc, guest PC 0x0c08587a */
if(!s->budget--) { s->failed_pc=0x0c08587au; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c08587c;
P_0c08587c: /* original f402, guest PC 0x0c08587c */
if(!s->budget--) { s->failed_pc=0x0c08587cu; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[0],r[18],'*');
goto P_0c08587e;
P_0c08587e: /* original f230, guest PC 0x0c08587e */
if(!s->budget--) { s->failed_pc=0x0c08587eu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'+');
goto P_0c085880;
P_0c085880: /* original fc2a, guest PC 0x0c085880 */
if(!s->budget--) { s->failed_pc=0x0c085880u; return 0; }
vf3_matrix_store(s,ram,2,r[12]);
goto P_0c085882;
P_0c085882: /* original f3f8, guest PC 0x0c085882 */
if(!s->budget--) { s->failed_pc=0x0c085882u; return 0; }
vf3_matrix_load(s,ram,3,r[15]);
goto P_0c085884;
P_0c085884: /* original f230, guest PC 0x0c085884 */
if(!s->budget--) { s->failed_pc=0x0c085884u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'+');
goto P_0c085886;
P_0c085886: /* original fc2a, guest PC 0x0c085886 */
if(!s->budget--) { s->failed_pc=0x0c085886u; return 0; }
vf3_matrix_store(s,ram,2,r[12]);
goto P_0c085888;
P_0c085888: /* original f3d8, guest PC 0x0c085888 */
if(!s->budget--) { s->failed_pc=0x0c085888u; return 0; }
vf3_matrix_load(s,ram,3,r[13]);
goto P_0c08588a;
P_0c08588a: /* original f340, guest PC 0x0c08588a */
if(!s->budget--) { s->failed_pc=0x0c08588au; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'+');
goto P_0c08588c;
P_0c08588c: /* original fd3a, guest PC 0x0c08588c */
if(!s->budget--) { s->failed_pc=0x0c08588cu; return 0; }
vf3_matrix_store(s,ram,3,r[13]);
goto P_0c08588e;
P_0c08588e: /* original f2d8, guest PC 0x0c08588e */
if(!s->budget--) { s->failed_pc=0x0c08588eu; return 0; }
vf3_matrix_load(s,ram,2,r[13]);
goto P_0c085890;
P_0c085890: /* original f3f8, guest PC 0x0c085890 */
if(!s->budget--) { s->failed_pc=0x0c085890u; return 0; }
vf3_matrix_load(s,ram,3,r[15]);
goto P_0c085892;
P_0c085892: /* original f230, guest PC 0x0c085892 */
if(!s->budget--) { s->failed_pc=0x0c085892u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'+');
goto P_0c085894;
P_0c085894: /* original fd2a, guest PC 0x0c085894 */
if(!s->budget--) { s->failed_pc=0x0c085894u; return 0; }
vf3_matrix_store(s,ram,2,r[13]);
goto P_0c085896;
P_0c085896: /* original 53ff, guest PC 0x0c085896 */
if(!s->budget--) { s->failed_pc=0x0c085896u; return 0; }
r[3]=read(ram,r[15]+60,4);
goto P_0c085898;
P_0c085898: /* original 901f, guest PC 0x0c085898 */
if(!s->budget--) { s->failed_pc=0x0c085898u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0858dau,2);
goto P_0c08589a;
P_0c08589a: /* original f336, guest PC 0x0c08589a */
if(!s->budget--) { s->failed_pc=0x0c08589au; return 0; }
vf3_matrix_load(s,ram,3,r[3]+r[0]);
goto P_0c08589c;
P_0c08589c: /* original e018, guest PC 0x0c08589c */
if(!s->budget--) { s->failed_pc=0x0c08589cu; return 0; }
r[0]=0x00000018u;
goto P_0c08589e;
P_0c08589e: /* original ff37, guest PC 0x0c08589e */
if(!s->budget--) { s->failed_pc=0x0c08589eu; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0858a0;
P_0c0858a0: /* original d30f, guest PC 0x0c0858a0 */
if(!s->budget--) { s->failed_pc=0x0c0858a0u; return 0; }
r[3]=read(ram,0x0c0858e0u,4);
goto P_0c0858a2;
P_0c0858a2: /* original 85f2, guest PC 0x0c0858a2 */
if(!s->budget--) { s->failed_pc=0x0c0858a2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+4,2);
goto P_0c0858a4;
P_0c0858a4: /* original 430b, guest PC 0x0c0858a4 */
if(!s->budget--) { s->failed_pc=0x0c0858a4u; return 0; }
target=r[3];
r[16]=0x0c0858a8u;
r[4]=r[0];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0858a8u) { target=s->pc; goto dispatch; }
goto P_0c0858a8;
P_0c0858a6: /* original 6403, guest PC 0x0c0858a6 */
if(!s->budget--) { s->failed_pc=0x0c0858a6u; return 0; }
r[4]=r[0];
goto P_0c0858a8;
P_0c0858a8: /* original e018, guest PC 0x0c0858a8 */
if(!s->budget--) { s->failed_pc=0x0c0858a8u; return 0; }
r[0]=0x00000018u;
goto P_0c0858aa;
P_0c0858aa: /* original f4f6, guest PC 0x0c0858aa */
if(!s->budget--) { s->failed_pc=0x0c0858aau; return 0; }
vf3_matrix_load(s,ram,4,r[15]+r[0]);
goto P_0c0858ac;
P_0c0858ac: /* original e008, guest PC 0x0c0858ac */
if(!s->budget--) { s->failed_pc=0x0c0858acu; return 0; }
r[0]=0x00000008u;
goto P_0c0858ae;
P_0c0858ae: /* original f402, guest PC 0x0c0858ae */
if(!s->budget--) { s->failed_pc=0x0c0858aeu; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[0],r[18],'*');
goto P_0c0858b0;
P_0c0858b0: /* original f34c, guest PC 0x0c0858b0 */
if(!s->budget--) { s->failed_pc=0x0c0858b0u; return 0; }
vf3_matrix_move(s,3,4);
goto P_0c0858b2;
P_0c0858b2: /* original f4f6, guest PC 0x0c0858b2 */
if(!s->budget--) { s->failed_pc=0x0c0858b2u; return 0; }
vf3_matrix_load(s,ram,4,r[15]+r[0]);
goto P_0c0858b4;
P_0c0858b4: /* original e00c, guest PC 0x0c0858b4 */
if(!s->budget--) { s->failed_pc=0x0c0858b4u; return 0; }
r[0]=0x0000000cu;
goto P_0c0858b6;
P_0c0858b6: /* original f430, guest PC 0x0c0858b6 */
if(!s->budget--) { s->failed_pc=0x0c0858b6u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'+');
goto P_0c0858b8;
P_0c0858b8: /* original f3f6, guest PC 0x0c0858b8 */
if(!s->budget--) { s->failed_pc=0x0c0858b8u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0858ba;
P_0c0858ba: /* original 7f20, guest PC 0x0c0858ba */
if(!s->budget--) { s->failed_pc=0x0c0858bau; return 0; }
r[15]+=0x00000020u;
goto P_0c0858bc;
P_0c0858bc: /* original 4f26, guest PC 0x0c0858bc */
if(!s->budget--) { s->failed_pc=0x0c0858bcu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0858be;
P_0c0858be: /* original fe3a, guest PC 0x0c0858be */
if(!s->budget--) { s->failed_pc=0x0c0858beu; return 0; }
vf3_matrix_store(s,ram,3,r[14]);
goto P_0c0858c0;
P_0c0858c0: /* original e004, guest PC 0x0c0858c0 */
if(!s->budget--) { s->failed_pc=0x0c0858c0u; return 0; }
r[0]=0x00000004u;
goto P_0c0858c2;
P_0c0858c2: /* original f3c8, guest PC 0x0c0858c2 */
if(!s->budget--) { s->failed_pc=0x0c0858c2u; return 0; }
vf3_matrix_load(s,ram,3,r[12]);
goto P_0c0858c4;
P_0c0858c4: /* original fe37, guest PC 0x0c0858c4 */
if(!s->budget--) { s->failed_pc=0x0c0858c4u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0858c6;
P_0c0858c6: /* original e008, guest PC 0x0c0858c6 */
if(!s->budget--) { s->failed_pc=0x0c0858c6u; return 0; }
r[0]=0x00000008u;
goto P_0c0858c8;
P_0c0858c8: /* original fe47, guest PC 0x0c0858c8 */
if(!s->budget--) { s->failed_pc=0x0c0858c8u; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c0858ca;
P_0c0858ca: /* original e00c, guest PC 0x0c0858ca */
if(!s->budget--) { s->failed_pc=0x0c0858cau; return 0; }
r[0]=0x0000000cu;
goto P_0c0858cc;
P_0c0858cc: /* original f3d8, guest PC 0x0c0858cc */
if(!s->budget--) { s->failed_pc=0x0c0858ccu; return 0; }
vf3_matrix_load(s,ram,3,r[13]);
goto P_0c0858ce;
P_0c0858ce: /* original fe37, guest PC 0x0c0858ce */
if(!s->budget--) { s->failed_pc=0x0c0858ceu; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0858d0;
P_0c0858d0: /* original fff9, guest PC 0x0c0858d0 */
if(!s->budget--) { s->failed_pc=0x0c0858d0u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0858d2;
P_0c0858d2: /* original 6cf6, guest PC 0x0c0858d2 */
if(!s->budget--) { s->failed_pc=0x0c0858d2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0858d4;
P_0c0858d4: /* original 6df6, guest PC 0x0c0858d4 */
if(!s->budget--) { s->failed_pc=0x0c0858d4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0858d6;
P_0c0858d6: /* original 000b, guest PC 0x0c0858d6 */
if(!s->budget--) { s->failed_pc=0x0c0858d6u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0858d8: /* original 6ef6, guest PC 0x0c0858d8 */
if(!s->budget--) { s->failed_pc=0x0c0858d8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0858dau,s,ram);
P_0c0882a2: /* original c717, guest PC 0x0c0882a2 */
if(!s->budget--) { s->failed_pc=0x0c0882a2u; return 0; }
r[0]=0x0c088300u;
goto P_0c0882a4;
P_0c0882a4: /* original fa08, guest PC 0x0c0882a4 */
if(!s->budget--) { s->failed_pc=0x0c0882a4u; return 0; }
vf3_matrix_load(s,ram,10,r[0]);
goto P_0c0882a6;
P_0c0882a6: /* original c717, guest PC 0x0c0882a6 */
if(!s->budget--) { s->failed_pc=0x0c0882a6u; return 0; }
r[0]=0x0c088304u;
goto P_0c0882a8;
P_0c0882a8: /* original f908, guest PC 0x0c0882a8 */
if(!s->budget--) { s->failed_pc=0x0c0882a8u; return 0; }
vf3_matrix_load(s,ram,9,r[0]);
goto P_0c0882aa;
P_0c0882aa: /* original e004, guest PC 0x0c0882aa */
if(!s->budget--) { s->failed_pc=0x0c0882aau; return 0; }
r[0]=0x00000004u;
goto P_0c0882ac;
P_0c0882ac: /* original f356, guest PC 0x0c0882ac */
if(!s->budget--) { s->failed_pc=0x0c0882acu; return 0; }
vf3_matrix_load(s,ram,3,r[5]+r[0]);
goto P_0c0882ae;
P_0c0882ae: /* original f8ac, guest PC 0x0c0882ae */
if(!s->budget--) { s->failed_pc=0x0c0882aeu; return 0; }
vf3_matrix_move(s,8,10);
goto P_0c0882b0;
P_0c0882b0: /* original f435, guest PC 0x0c0882b0 */
if(!s->budget--) { s->failed_pc=0x0c0882b0u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[4])>as_float(fr[3]))!=0);
goto P_0c0882b2;
P_0c0882b2: /* original 8f4f, guest PC 0x0c0882b2 */
if(!s->budget--) { s->failed_pc=0x0c0882b2u; return 0; }
cond=r[17]&1u;
fr[7]=0x3f800000u;
if(!cond) { goto P_0c088354; }
goto P_0c0882b6;
P_0c0882b4: /* original f79d, guest PC 0x0c0882b4 */
if(!s->budget--) { s->failed_pc=0x0c0882b4u; return 0; }
fr[7]=0x3f800000u;
goto P_0c0882b6;
P_0c0882b6: /* original f658, guest PC 0x0c0882b6 */
if(!s->budget--) { s->failed_pc=0x0c0882b6u; return 0; }
vf3_matrix_load(s,ram,6,r[5]);
goto P_0c0882b8;
P_0c0882b8: /* original f368, guest PC 0x0c0882b8 */
if(!s->budget--) { s->failed_pc=0x0c0882b8u; return 0; }
vf3_matrix_load(s,ram,3,r[6]);
goto P_0c0882ba;
P_0c0882ba: /* original fb56, guest PC 0x0c0882ba */
if(!s->budget--) { s->failed_pc=0x0c0882bau; return 0; }
vf3_matrix_load(s,ram,11,r[5]+r[0]);
goto P_0c0882bc;
P_0c0882bc: /* original f631, guest PC 0x0c0882bc */
if(!s->budget--) { s->failed_pc=0x0c0882bcu; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[3],r[18],'-');
goto P_0c0882be;
P_0c0882be: /* original f366, guest PC 0x0c0882be */
if(!s->budget--) { s->failed_pc=0x0c0882beu; return 0; }
vf3_matrix_load(s,ram,3,r[6]+r[0]);
goto P_0c0882c0;
P_0c0882c0: /* original e008, guest PC 0x0c0882c0 */
if(!s->budget--) { s->failed_pc=0x0c0882c0u; return 0; }
r[0]=0x00000008u;
goto P_0c0882c2;
P_0c0882c2: /* original fb31, guest PC 0x0c0882c2 */
if(!s->budget--) { s->failed_pc=0x0c0882c2u; return 0; }
fr[11]=vf3_fpu_binary(fr[11],fr[3],r[18],'-');
goto P_0c0882c4;
P_0c0882c4: /* original f556, guest PC 0x0c0882c4 */
if(!s->budget--) { s->failed_pc=0x0c0882c4u; return 0; }
vf3_matrix_load(s,ram,5,r[5]+r[0]);
goto P_0c0882c6;
P_0c0882c6: /* original f366, guest PC 0x0c0882c6 */
if(!s->budget--) { s->failed_pc=0x0c0882c6u; return 0; }
vf3_matrix_load(s,ram,3,r[6]+r[0]);
goto P_0c0882c8;
P_0c0882c8: /* original c70f, guest PC 0x0c0882c8 */
if(!s->budget--) { s->failed_pc=0x0c0882c8u; return 0; }
r[0]=0x0c088308u;
goto P_0c0882ca;
P_0c0882ca: /* original f208, guest PC 0x0c0882ca */
if(!s->budget--) { s->failed_pc=0x0c0882cau; return 0; }
vf3_matrix_load(s,ram,2,r[0]);
goto P_0c0882cc;
P_0c0882cc: /* original f531, guest PC 0x0c0882cc */
if(!s->budget--) { s->failed_pc=0x0c0882ccu; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[3],r[18],'-');
goto P_0c0882ce;
P_0c0882ce: /* original f36c, guest PC 0x0c0882ce */
if(!s->budget--) { s->failed_pc=0x0c0882ceu; return 0; }
vf3_matrix_move(s,3,6);
goto P_0c0882d0;
P_0c0882d0: /* original f362, guest PC 0x0c0882d0 */
if(!s->budget--) { s->failed_pc=0x0c0882d0u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[6],r[18],'*');
goto P_0c0882d2;
P_0c0882d2: /* original f05c, guest PC 0x0c0882d2 */
if(!s->budget--) { s->failed_pc=0x0c0882d2u; return 0; }
vf3_matrix_move(s,0,5);
goto P_0c0882d4;
P_0c0882d4: /* original f35e, guest PC 0x0c0882d4 */
if(!s->budget--) { s->failed_pc=0x0c0882d4u; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[5],fr[3],r[18]);
goto P_0c0882d6;
P_0c0882d6: /* original f43c, guest PC 0x0c0882d6 */
if(!s->budget--) { s->failed_pc=0x0c0882d6u; return 0; }
vf3_matrix_move(s,4,3);
goto P_0c0882d8;
P_0c0882d8: /* original f245, guest PC 0x0c0882d8 */
if(!s->budget--) { s->failed_pc=0x0c0882d8u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[2])>as_float(fr[4]))!=0);
goto P_0c0882da;
P_0c0882da: /* original 8b17, guest PC 0x0c0882da */
if(!s->budget--) { s->failed_pc=0x0c0882dau; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c08830c; }
goto P_0c0882dc;
P_0c0882dc: /* original a017, guest PC 0x0c0882dc */
if(!s->budget--) { s->failed_pc=0x0c0882dcu; return 0; }
fr[4]=0;
goto P_0c08830e;
P_0c0882de: /* original f48d, guest PC 0x0c0882de */
if(!s->budget--) { s->failed_pc=0x0c0882deu; return 0; }
fr[4]=0;
return vf3_matrix_family(0x0c0882e0u,s,ram);
P_0c08830c: /* original f46d, guest PC 0x0c08830c */
if(!s->budget--) { s->failed_pc=0x0c08830cu; return 0; }
fr[4]=vf3_fpu_sqrt(fr[4],r[18]);
goto P_0c08830e;
P_0c08830e: /* original f845, guest PC 0x0c08830e */
if(!s->budget--) { s->failed_pc=0x0c08830eu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[8])>as_float(fr[4]))!=0);
goto P_0c088310;
P_0c088310: /* original 8920, guest PC 0x0c088310 */
if(!s->budget--) { s->failed_pc=0x0c088310u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c088354; }
goto P_0c088312;
P_0c088312: /* original f9b5, guest PC 0x0c088312 */
if(!s->budget--) { s->failed_pc=0x0c088312u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[9])>as_float(fr[11]))!=0);
goto P_0c088314;
P_0c088314: /* original 891e, guest PC 0x0c088314 */
if(!s->budget--) { s->failed_pc=0x0c088314u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c088354; }
goto P_0c088316;
P_0c088316: /* original f378, guest PC 0x0c088316 */
if(!s->budget--) { s->failed_pc=0x0c088316u; return 0; }
vf3_matrix_load(s,ram,3,r[7]);
goto P_0c088318;
P_0c088318: /* original f345, guest PC 0x0c088318 */
if(!s->budget--) { s->failed_pc=0x0c088318u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[4]))!=0);
goto P_0c08831a;
P_0c08831a: /* original 891b, guest PC 0x0c08831a */
if(!s->budget--) { s->failed_pc=0x0c08831au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c088354; }
goto P_0c08831c;
P_0c08831c: /* original f475, guest PC 0x0c08831c */
if(!s->budget--) { s->failed_pc=0x0c08831cu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[4])>as_float(fr[7]))!=0);
goto P_0c08831e;
P_0c08831e: /* original f74a, guest PC 0x0c08831e */
if(!s->budget--) { s->failed_pc=0x0c08831eu; return 0; }
vf3_matrix_store(s,ram,4,r[7]);
goto P_0c088320;
P_0c088320: /* original 8f02, guest PC 0x0c088320 */
if(!s->budget--) { s->failed_pc=0x0c088320u; return 0; }
cond=r[17]&1u;
vf3_matrix_move(s,8,10);
if(!cond) { goto P_0c088328; }
goto P_0c088324;
P_0c088322: /* original f8ac, guest PC 0x0c088322 */
if(!s->budget--) { s->failed_pc=0x0c088322u; return 0; }
vf3_matrix_move(s,8,10);
goto P_0c088324;
P_0c088324: /* original f843, guest PC 0x0c088324 */
if(!s->budget--) { s->failed_pc=0x0c088324u; return 0; }
fr[8]=vf3_fpu_binary(fr[8],fr[4],r[18],'/');
goto P_0c088326;
P_0c088326: /* original f47c, guest PC 0x0c088326 */
if(!s->budget--) { s->failed_pc=0x0c088326u; return 0; }
vf3_matrix_move(s,4,7);
goto P_0c088328;
P_0c088328: /* original f74c, guest PC 0x0c088328 */
if(!s->budget--) { s->failed_pc=0x0c088328u; return 0; }
vf3_matrix_move(s,7,4);
goto P_0c08832a;
P_0c08832a: /* original e008, guest PC 0x0c08832a */
if(!s->budget--) { s->failed_pc=0x0c08832au; return 0; }
r[0]=0x00000008u;
goto P_0c08832c;
P_0c08832c: /* original f477, guest PC 0x0c08832c */
if(!s->budget--) { s->failed_pc=0x0c08832cu; return 0; }
vf3_matrix_store(s,ram,7,r[4]+r[0]);
goto P_0c08832e;
P_0c08832e: /* original e00c, guest PC 0x0c08832e */
if(!s->budget--) { s->failed_pc=0x0c08832eu; return 0; }
r[0]=0x0000000cu;
goto P_0c088330;
P_0c088330: /* original f368, guest PC 0x0c088330 */
if(!s->budget--) { s->failed_pc=0x0c088330u; return 0; }
vf3_matrix_load(s,ram,3,r[6]);
goto P_0c088332;
P_0c088332: /* original f682, guest PC 0x0c088332 */
if(!s->budget--) { s->failed_pc=0x0c088332u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[8],r[18],'*');
goto P_0c088334;
P_0c088334: /* original f582, guest PC 0x0c088334 */
if(!s->budget--) { s->failed_pc=0x0c088334u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[8],r[18],'*');
goto P_0c088336;
P_0c088336: /* original f437, guest PC 0x0c088336 */
if(!s->budget--) { s->failed_pc=0x0c088336u; return 0; }
vf3_matrix_store(s,ram,3,r[4]+r[0]);
goto P_0c088338;
P_0c088338: /* original e004, guest PC 0x0c088338 */
if(!s->budget--) { s->failed_pc=0x0c088338u; return 0; }
r[0]=0x00000004u;
goto P_0c08833a;
P_0c08833a: /* original f366, guest PC 0x0c08833a */
if(!s->budget--) { s->failed_pc=0x0c08833au; return 0; }
vf3_matrix_load(s,ram,3,r[6]+r[0]);
goto P_0c08833c;
P_0c08833c: /* original e010, guest PC 0x0c08833c */
if(!s->budget--) { s->failed_pc=0x0c08833cu; return 0; }
r[0]=0x00000010u;
goto P_0c08833e;
P_0c08833e: /* original f437, guest PC 0x0c08833e */
if(!s->budget--) { s->failed_pc=0x0c08833eu; return 0; }
vf3_matrix_store(s,ram,3,r[4]+r[0]);
goto P_0c088340;
P_0c088340: /* original e008, guest PC 0x0c088340 */
if(!s->budget--) { s->failed_pc=0x0c088340u; return 0; }
r[0]=0x00000008u;
goto P_0c088342;
P_0c088342: /* original f366, guest PC 0x0c088342 */
if(!s->budget--) { s->failed_pc=0x0c088342u; return 0; }
vf3_matrix_load(s,ram,3,r[6]+r[0]);
goto P_0c088344;
P_0c088344: /* original e014, guest PC 0x0c088344 */
if(!s->budget--) { s->failed_pc=0x0c088344u; return 0; }
r[0]=0x00000014u;
goto P_0c088346;
P_0c088346: /* original f437, guest PC 0x0c088346 */
if(!s->budget--) { s->failed_pc=0x0c088346u; return 0; }
vf3_matrix_store(s,ram,3,r[4]+r[0]);
goto P_0c088348;
P_0c088348: /* original e018, guest PC 0x0c088348 */
if(!s->budget--) { s->failed_pc=0x0c088348u; return 0; }
r[0]=0x00000018u;
goto P_0c08834a;
P_0c08834a: /* original f467, guest PC 0x0c08834a */
if(!s->budget--) { s->failed_pc=0x0c08834au; return 0; }
vf3_matrix_store(s,ram,6,r[4]+r[0]);
goto P_0c08834c;
P_0c08834c: /* original e01c, guest PC 0x0c08834c */
if(!s->budget--) { s->failed_pc=0x0c08834cu; return 0; }
r[0]=0x0000001cu;
goto P_0c08834e;
P_0c08834e: /* original f477, guest PC 0x0c08834e */
if(!s->budget--) { s->failed_pc=0x0c08834eu; return 0; }
vf3_matrix_store(s,ram,7,r[4]+r[0]);
goto P_0c088350;
P_0c088350: /* original e020, guest PC 0x0c088350 */
if(!s->budget--) { s->failed_pc=0x0c088350u; return 0; }
r[0]=0x00000020u;
goto P_0c088352;
P_0c088352: /* original f457, guest PC 0x0c088352 */
if(!s->budget--) { s->failed_pc=0x0c088352u; return 0; }
vf3_matrix_store(s,ram,5,r[4]+r[0]);
goto P_0c088354;
P_0c088354: /* original 000b, guest PC 0x0c088354 */
if(!s->budget--) { s->failed_pc=0x0c088354u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c088356: /* original 0009, guest PC 0x0c088356 */
if(!s->budget--) { s->failed_pc=0x0c088356u; return 0; }
return vf3_matrix_family(0x0c088358u,s,ram);
P_0c088370: /* original 4f22, guest PC 0x0c088370 */
if(!s->budget--) { s->failed_pc=0x0c088370u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c088372;
P_0c088372: /* original ff30, guest PC 0x0c088372 */
if(!s->budget--) { s->failed_pc=0x0c088372u; return 0; }
fr[15]=vf3_fpu_binary(fr[15],fr[3],r[18],'+');
goto P_0c088374;
P_0c088374: /* original f38d, guest PC 0x0c088374 */
if(!s->budget--) { s->failed_pc=0x0c088374u; return 0; }
fr[3]=0;
goto P_0c088376;
P_0c088376: /* original 7fe4, guest PC 0x0c088376 */
if(!s->budget--) { s->failed_pc=0x0c088376u; return 0; }
r[15]+=0xffffffe4u;
goto P_0c088378;
P_0c088378: /* original ff3a, guest PC 0x0c088378 */
if(!s->budget--) { s->failed_pc=0x0c088378u; return 0; }
vf3_matrix_store(s,ram,3,r[15]);
goto P_0c08837a;
P_0c08837a: /* original fc37, guest PC 0x0c08837a */
if(!s->budget--) { s->failed_pc=0x0c08837au; return 0; }
vf3_matrix_store(s,ram,3,r[12]+r[0]);
goto P_0c08837c;
P_0c08837c: /* original 9088, guest PC 0x0c08837c */
if(!s->budget--) { s->failed_pc=0x0c08837cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c088490u,2);
goto P_0c08837e;
P_0c08837e: /* original f3d6, guest PC 0x0c08837e */
if(!s->budget--) { s->failed_pc=0x0c08837eu; return 0; }
vf3_matrix_load(s,ram,3,r[13]+r[0]);
goto P_0c088380;
P_0c088380: /* original e010, guest PC 0x0c088380 */
if(!s->budget--) { s->failed_pc=0x0c088380u; return 0; }
r[0]=0x00000010u;
goto P_0c088382;
P_0c088382: /* original ff37, guest PC 0x0c088382 */
if(!s->budget--) { s->failed_pc=0x0c088382u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c088384;
P_0c088384: /* original 9085, guest PC 0x0c088384 */
if(!s->budget--) { s->failed_pc=0x0c088384u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c088492u,2);
goto P_0c088386;
P_0c088386: /* original f3d6, guest PC 0x0c088386 */
if(!s->budget--) { s->failed_pc=0x0c088386u; return 0; }
vf3_matrix_load(s,ram,3,r[13]+r[0]);
goto P_0c088388;
P_0c088388: /* original e014, guest PC 0x0c088388 */
if(!s->budget--) { s->failed_pc=0x0c088388u; return 0; }
r[0]=0x00000014u;
goto P_0c08838a;
P_0c08838a: /* original ff37, guest PC 0x0c08838a */
if(!s->budget--) { s->failed_pc=0x0c08838au; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c08838c;
P_0c08838c: /* original 9082, guest PC 0x0c08838c */
if(!s->budget--) { s->failed_pc=0x0c08838cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c088494u,2);
goto P_0c08838e;
P_0c08838e: /* original f3d6, guest PC 0x0c08838e */
if(!s->budget--) { s->failed_pc=0x0c08838eu; return 0; }
vf3_matrix_load(s,ram,3,r[13]+r[0]);
goto P_0c088390;
P_0c088390: /* original e018, guest PC 0x0c088390 */
if(!s->budget--) { s->failed_pc=0x0c088390u; return 0; }
r[0]=0x00000018u;
goto P_0c088392;
P_0c088392: /* original f34d, guest PC 0x0c088392 */
if(!s->budget--) { s->failed_pc=0x0c088392u; return 0; }
fr[3]^=0x80000000u;
goto P_0c088394;
P_0c088394: /* original ff37, guest PC 0x0c088394 */
if(!s->budget--) { s->failed_pc=0x0c088394u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c088396;
P_0c088396: /* original f3e8, guest PC 0x0c088396 */
if(!s->budget--) { s->failed_pc=0x0c088396u; return 0; }
vf3_matrix_load(s,ram,3,r[14]);
goto P_0c088398;
P_0c088398: /* original e004, guest PC 0x0c088398 */
if(!s->budget--) { s->failed_pc=0x0c088398u; return 0; }
r[0]=0x00000004u;
goto P_0c08839a;
P_0c08839a: /* original 66f3, guest PC 0x0c08839a */
if(!s->budget--) { s->failed_pc=0x0c08839au; return 0; }
r[6]=r[15];
goto P_0c08839c;
P_0c08839c: /* original ff37, guest PC 0x0c08839c */
if(!s->budget--) { s->failed_pc=0x0c08839cu; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c08839e;
P_0c08839e: /* original e004, guest PC 0x0c08839e */
if(!s->budget--) { s->failed_pc=0x0c08839eu; return 0; }
r[0]=0x00000004u;
goto P_0c0883a0;
P_0c0883a0: /* original f3e6, guest PC 0x0c0883a0 */
if(!s->budget--) { s->failed_pc=0x0c0883a0u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c0883a2;
P_0c0883a2: /* original e008, guest PC 0x0c0883a2 */
if(!s->budget--) { s->failed_pc=0x0c0883a2u; return 0; }
r[0]=0x00000008u;
goto P_0c0883a4;
P_0c0883a4: /* original 65f3, guest PC 0x0c0883a4 */
if(!s->budget--) { s->failed_pc=0x0c0883a4u; return 0; }
r[5]=r[15];
goto P_0c0883a6;
P_0c0883a6: /* original 7604, guest PC 0x0c0883a6 */
if(!s->budget--) { s->failed_pc=0x0c0883a6u; return 0; }
r[6]+=0x00000004u;
goto P_0c0883a8;
P_0c0883a8: /* original ff37, guest PC 0x0c0883a8 */
if(!s->budget--) { s->failed_pc=0x0c0883a8u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0883aa;
P_0c0883aa: /* original e008, guest PC 0x0c0883aa */
if(!s->budget--) { s->failed_pc=0x0c0883aau; return 0; }
r[0]=0x00000008u;
goto P_0c0883ac;
P_0c0883ac: /* original f3e6, guest PC 0x0c0883ac */
if(!s->budget--) { s->failed_pc=0x0c0883acu; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c0883ae;
P_0c0883ae: /* original e00c, guest PC 0x0c0883ae */
if(!s->budget--) { s->failed_pc=0x0c0883aeu; return 0; }
r[0]=0x0000000cu;
goto P_0c0883b0;
P_0c0883b0: /* original 7510, guest PC 0x0c0883b0 */
if(!s->budget--) { s->failed_pc=0x0c0883b0u; return 0; }
r[5]+=0x00000010u;
goto P_0c0883b2;
P_0c0883b2: /* original 67f3, guest PC 0x0c0883b2 */
if(!s->budget--) { s->failed_pc=0x0c0883b2u; return 0; }
r[7]=r[15];
goto P_0c0883b4;
P_0c0883b4: /* original ff37, guest PC 0x0c0883b4 */
if(!s->budget--) { s->failed_pc=0x0c0883b4u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0883b6;
P_0c0883b6: /* original e010, guest PC 0x0c0883b6 */
if(!s->budget--) { s->failed_pc=0x0c0883b6u; return 0; }
r[0]=0x00000010u;
goto P_0c0883b8;
P_0c0883b8: /* original f3f6, guest PC 0x0c0883b8 */
if(!s->budget--) { s->failed_pc=0x0c0883b8u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0883ba;
P_0c0883ba: /* original e014, guest PC 0x0c0883ba */
if(!s->budget--) { s->failed_pc=0x0c0883bau; return 0; }
r[0]=0x00000014u;
goto P_0c0883bc;
P_0c0883bc: /* original fe3a, guest PC 0x0c0883bc */
if(!s->budget--) { s->failed_pc=0x0c0883bcu; return 0; }
vf3_matrix_store(s,ram,3,r[14]);
goto P_0c0883be;
P_0c0883be: /* original f3f6, guest PC 0x0c0883be */
if(!s->budget--) { s->failed_pc=0x0c0883beu; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0883c0;
P_0c0883c0: /* original e004, guest PC 0x0c0883c0 */
if(!s->budget--) { s->failed_pc=0x0c0883c0u; return 0; }
r[0]=0x00000004u;
goto P_0c0883c2;
P_0c0883c2: /* original fe37, guest PC 0x0c0883c2 */
if(!s->budget--) { s->failed_pc=0x0c0883c2u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0883c4;
P_0c0883c4: /* original e018, guest PC 0x0c0883c4 */
if(!s->budget--) { s->failed_pc=0x0c0883c4u; return 0; }
r[0]=0x00000018u;
goto P_0c0883c6;
P_0c0883c6: /* original f3f6, guest PC 0x0c0883c6 */
if(!s->budget--) { s->failed_pc=0x0c0883c6u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0883c8;
P_0c0883c8: /* original e008, guest PC 0x0c0883c8 */
if(!s->budget--) { s->failed_pc=0x0c0883c8u; return 0; }
r[0]=0x00000008u;
goto P_0c0883ca;
P_0c0883ca: /* original fe37, guest PC 0x0c0883ca */
if(!s->budget--) { s->failed_pc=0x0c0883cau; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0883cc;
P_0c0883cc: /* original f4fc, guest PC 0x0c0883cc */
if(!s->budget--) { s->failed_pc=0x0c0883ccu; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c0883ce;
P_0c0883ce: /* original bf68, guest PC 0x0c0883ce */
if(!s->budget--) { s->failed_pc=0x0c0883ceu; return 0; }
target=0x0c0882a2u; r[16]=0x0c0883d2u;
r[4]=r[12];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0883d2u) { target=s->pc; goto dispatch; }
goto P_0c0883d2;
P_0c0883d0: /* original 64c3, guest PC 0x0c0883d0 */
if(!s->budget--) { s->failed_pc=0x0c0883d0u; return 0; }
r[4]=r[12];
goto P_0c0883d2;
P_0c0883d2: /* original 9060, guest PC 0x0c0883d2 */
if(!s->budget--) { s->failed_pc=0x0c0883d2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c088496u,2);
goto P_0c0883d4;
P_0c0883d4: /* original 7e0c, guest PC 0x0c0883d4 */
if(!s->budget--) { s->failed_pc=0x0c0883d4u; return 0; }
r[14]+=0x0000000cu;
goto P_0c0883d6;
P_0c0883d6: /* original f3d6, guest PC 0x0c0883d6 */
if(!s->budget--) { s->failed_pc=0x0c0883d6u; return 0; }
vf3_matrix_load(s,ram,3,r[13]+r[0]);
goto P_0c0883d8;
P_0c0883d8: /* original e010, guest PC 0x0c0883d8 */
if(!s->budget--) { s->failed_pc=0x0c0883d8u; return 0; }
r[0]=0x00000010u;
goto P_0c0883da;
P_0c0883da: /* original ff37, guest PC 0x0c0883da */
if(!s->budget--) { s->failed_pc=0x0c0883dau; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0883dc;
P_0c0883dc: /* original 905c, guest PC 0x0c0883dc */
if(!s->budget--) { s->failed_pc=0x0c0883dcu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c088498u,2);
goto P_0c0883de;
P_0c0883de: /* original f3d6, guest PC 0x0c0883de */
if(!s->budget--) { s->failed_pc=0x0c0883deu; return 0; }
vf3_matrix_load(s,ram,3,r[13]+r[0]);
goto P_0c0883e0;
P_0c0883e0: /* original e014, guest PC 0x0c0883e0 */
if(!s->budget--) { s->failed_pc=0x0c0883e0u; return 0; }
r[0]=0x00000014u;
goto P_0c0883e2;
P_0c0883e2: /* original ff37, guest PC 0x0c0883e2 */
if(!s->budget--) { s->failed_pc=0x0c0883e2u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0883e4;
P_0c0883e4: /* original 9059, guest PC 0x0c0883e4 */
if(!s->budget--) { s->failed_pc=0x0c0883e4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08849au,2);
goto P_0c0883e6;
P_0c0883e6: /* original f3d6, guest PC 0x0c0883e6 */
if(!s->budget--) { s->failed_pc=0x0c0883e6u; return 0; }
vf3_matrix_load(s,ram,3,r[13]+r[0]);
goto P_0c0883e8;
P_0c0883e8: /* original e018, guest PC 0x0c0883e8 */
if(!s->budget--) { s->failed_pc=0x0c0883e8u; return 0; }
r[0]=0x00000018u;
goto P_0c0883ea;
P_0c0883ea: /* original f34d, guest PC 0x0c0883ea */
if(!s->budget--) { s->failed_pc=0x0c0883eau; return 0; }
fr[3]^=0x80000000u;
goto P_0c0883ec;
P_0c0883ec: /* original ff37, guest PC 0x0c0883ec */
if(!s->budget--) { s->failed_pc=0x0c0883ecu; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0883ee;
P_0c0883ee: /* original e004, guest PC 0x0c0883ee */
if(!s->budget--) { s->failed_pc=0x0c0883eeu; return 0; }
r[0]=0x00000004u;
goto P_0c0883f0;
P_0c0883f0: /* original f3e8, guest PC 0x0c0883f0 */
if(!s->budget--) { s->failed_pc=0x0c0883f0u; return 0; }
vf3_matrix_load(s,ram,3,r[14]);
goto P_0c0883f2;
P_0c0883f2: /* original ff37, guest PC 0x0c0883f2 */
if(!s->budget--) { s->failed_pc=0x0c0883f2u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0883f4;
P_0c0883f4: /* original e004, guest PC 0x0c0883f4 */
if(!s->budget--) { s->failed_pc=0x0c0883f4u; return 0; }
r[0]=0x00000004u;
goto P_0c0883f6;
P_0c0883f6: /* original f3e6, guest PC 0x0c0883f6 */
if(!s->budget--) { s->failed_pc=0x0c0883f6u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c0883f8;
P_0c0883f8: /* original e008, guest PC 0x0c0883f8 */
if(!s->budget--) { s->failed_pc=0x0c0883f8u; return 0; }
r[0]=0x00000008u;
goto P_0c0883fa;
P_0c0883fa: /* original ff37, guest PC 0x0c0883fa */
if(!s->budget--) { s->failed_pc=0x0c0883fau; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0883fc;
P_0c0883fc: /* original e008, guest PC 0x0c0883fc */
if(!s->budget--) { s->failed_pc=0x0c0883fcu; return 0; }
r[0]=0x00000008u;
goto P_0c0883fe;
P_0c0883fe: /* original f3e6, guest PC 0x0c0883fe */
if(!s->budget--) { s->failed_pc=0x0c0883feu; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c088400;
P_0c088400: /* original e00c, guest PC 0x0c088400 */
if(!s->budget--) { s->failed_pc=0x0c088400u; return 0; }
r[0]=0x0000000cu;
goto P_0c088402;
P_0c088402: /* original ff37, guest PC 0x0c088402 */
if(!s->budget--) { s->failed_pc=0x0c088402u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c088404;
P_0c088404: /* original e010, guest PC 0x0c088404 */
if(!s->budget--) { s->failed_pc=0x0c088404u; return 0; }
r[0]=0x00000010u;
goto P_0c088406;
P_0c088406: /* original f3f6, guest PC 0x0c088406 */
if(!s->budget--) { s->failed_pc=0x0c088406u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c088408;
P_0c088408: /* original e014, guest PC 0x0c088408 */
if(!s->budget--) { s->failed_pc=0x0c088408u; return 0; }
r[0]=0x00000014u;
goto P_0c08840a;
P_0c08840a: /* original fe3a, guest PC 0x0c08840a */
if(!s->budget--) { s->failed_pc=0x0c08840au; return 0; }
vf3_matrix_store(s,ram,3,r[14]);
goto P_0c08840c;
P_0c08840c: /* original f3f6, guest PC 0x0c08840c */
if(!s->budget--) { s->failed_pc=0x0c08840cu; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c08840e;
P_0c08840e: /* original e004, guest PC 0x0c08840e */
if(!s->budget--) { s->failed_pc=0x0c08840eu; return 0; }
r[0]=0x00000004u;
goto P_0c088410;
P_0c088410: /* original fe37, guest PC 0x0c088410 */
if(!s->budget--) { s->failed_pc=0x0c088410u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c088412;
P_0c088412: /* original e018, guest PC 0x0c088412 */
if(!s->budget--) { s->failed_pc=0x0c088412u; return 0; }
r[0]=0x00000018u;
goto P_0c088414;
P_0c088414: /* original 65f3, guest PC 0x0c088414 */
if(!s->budget--) { s->failed_pc=0x0c088414u; return 0; }
r[5]=r[15];
goto P_0c088416;
P_0c088416: /* original f3f6, guest PC 0x0c088416 */
if(!s->budget--) { s->failed_pc=0x0c088416u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c088418;
P_0c088418: /* original 66f3, guest PC 0x0c088418 */
if(!s->budget--) { s->failed_pc=0x0c088418u; return 0; }
r[6]=r[15];
goto P_0c08841a;
P_0c08841a: /* original e008, guest PC 0x0c08841a */
if(!s->budget--) { s->failed_pc=0x0c08841au; return 0; }
r[0]=0x00000008u;
goto P_0c08841c;
P_0c08841c: /* original 67f3, guest PC 0x0c08841c */
if(!s->budget--) { s->failed_pc=0x0c08841cu; return 0; }
r[7]=r[15];
goto P_0c08841e;
P_0c08841e: /* original 7604, guest PC 0x0c08841e */
if(!s->budget--) { s->failed_pc=0x0c08841eu; return 0; }
r[6]+=0x00000004u;
goto P_0c088420;
P_0c088420: /* original fe37, guest PC 0x0c088420 */
if(!s->budget--) { s->failed_pc=0x0c088420u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c088422;
P_0c088422: /* original 7510, guest PC 0x0c088422 */
if(!s->budget--) { s->failed_pc=0x0c088422u; return 0; }
r[5]+=0x00000010u;
goto P_0c088424;
P_0c088424: /* original f4fc, guest PC 0x0c088424 */
if(!s->budget--) { s->failed_pc=0x0c088424u; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c088426;
P_0c088426: /* original bf3c, guest PC 0x0c088426 */
if(!s->budget--) { s->failed_pc=0x0c088426u; return 0; }
target=0x0c0882a2u; r[16]=0x0c08842au;
r[4]=r[12];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08842au) { target=s->pc; goto dispatch; }
goto P_0c08842a;
P_0c088428: /* original 64c3, guest PC 0x0c088428 */
if(!s->budget--) { s->failed_pc=0x0c088428u; return 0; }
r[4]=r[12];
goto P_0c08842a;
P_0c08842a: /* original 9037, guest PC 0x0c08842a */
if(!s->budget--) { s->failed_pc=0x0c08842au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08849cu,2);
goto P_0c08842c;
P_0c08842c: /* original 7e0c, guest PC 0x0c08842c */
if(!s->budget--) { s->failed_pc=0x0c08842cu; return 0; }
r[14]+=0x0000000cu;
goto P_0c08842e;
P_0c08842e: /* original f3d6, guest PC 0x0c08842e */
if(!s->budget--) { s->failed_pc=0x0c08842eu; return 0; }
vf3_matrix_load(s,ram,3,r[13]+r[0]);
goto P_0c088430;
P_0c088430: /* original e010, guest PC 0x0c088430 */
if(!s->budget--) { s->failed_pc=0x0c088430u; return 0; }
r[0]=0x00000010u;
goto P_0c088432;
P_0c088432: /* original ff37, guest PC 0x0c088432 */
if(!s->budget--) { s->failed_pc=0x0c088432u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c088434;
P_0c088434: /* original 9033, guest PC 0x0c088434 */
if(!s->budget--) { s->failed_pc=0x0c088434u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08849eu,2);
goto P_0c088436;
P_0c088436: /* original f3d6, guest PC 0x0c088436 */
if(!s->budget--) { s->failed_pc=0x0c088436u; return 0; }
vf3_matrix_load(s,ram,3,r[13]+r[0]);
goto P_0c088438;
P_0c088438: /* original e014, guest PC 0x0c088438 */
if(!s->budget--) { s->failed_pc=0x0c088438u; return 0; }
r[0]=0x00000014u;
goto P_0c08843a;
P_0c08843a: /* original ff37, guest PC 0x0c08843a */
if(!s->budget--) { s->failed_pc=0x0c08843au; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c08843c;
P_0c08843c: /* original 9030, guest PC 0x0c08843c */
if(!s->budget--) { s->failed_pc=0x0c08843cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0884a0u,2);
goto P_0c08843e;
P_0c08843e: /* original f3d6, guest PC 0x0c08843e */
if(!s->budget--) { s->failed_pc=0x0c08843eu; return 0; }
vf3_matrix_load(s,ram,3,r[13]+r[0]);
goto P_0c088440;
P_0c088440: /* original e018, guest PC 0x0c088440 */
if(!s->budget--) { s->failed_pc=0x0c088440u; return 0; }
r[0]=0x00000018u;
goto P_0c088442;
P_0c088442: /* original f34d, guest PC 0x0c088442 */
if(!s->budget--) { s->failed_pc=0x0c088442u; return 0; }
fr[3]^=0x80000000u;
goto P_0c088444;
P_0c088444: /* original ff37, guest PC 0x0c088444 */
if(!s->budget--) { s->failed_pc=0x0c088444u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c088446;
P_0c088446: /* original e004, guest PC 0x0c088446 */
if(!s->budget--) { s->failed_pc=0x0c088446u; return 0; }
r[0]=0x00000004u;
goto P_0c088448;
P_0c088448: /* original f3e8, guest PC 0x0c088448 */
if(!s->budget--) { s->failed_pc=0x0c088448u; return 0; }
vf3_matrix_load(s,ram,3,r[14]);
goto P_0c08844a;
P_0c08844a: /* original ff37, guest PC 0x0c08844a */
if(!s->budget--) { s->failed_pc=0x0c08844au; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c08844c;
P_0c08844c: /* original e004, guest PC 0x0c08844c */
if(!s->budget--) { s->failed_pc=0x0c08844cu; return 0; }
r[0]=0x00000004u;
goto P_0c08844e;
P_0c08844e: /* original f3e6, guest PC 0x0c08844e */
if(!s->budget--) { s->failed_pc=0x0c08844eu; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c088450;
P_0c088450: /* original e008, guest PC 0x0c088450 */
if(!s->budget--) { s->failed_pc=0x0c088450u; return 0; }
r[0]=0x00000008u;
goto P_0c088452;
P_0c088452: /* original ff37, guest PC 0x0c088452 */
if(!s->budget--) { s->failed_pc=0x0c088452u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c088454;
P_0c088454: /* original e008, guest PC 0x0c088454 */
if(!s->budget--) { s->failed_pc=0x0c088454u; return 0; }
r[0]=0x00000008u;
goto P_0c088456;
P_0c088456: /* original f3e6, guest PC 0x0c088456 */
if(!s->budget--) { s->failed_pc=0x0c088456u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c088458;
P_0c088458: /* original e00c, guest PC 0x0c088458 */
if(!s->budget--) { s->failed_pc=0x0c088458u; return 0; }
r[0]=0x0000000cu;
goto P_0c08845a;
P_0c08845a: /* original ff37, guest PC 0x0c08845a */
if(!s->budget--) { s->failed_pc=0x0c08845au; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c08845c;
P_0c08845c: /* original e010, guest PC 0x0c08845c */
if(!s->budget--) { s->failed_pc=0x0c08845cu; return 0; }
r[0]=0x00000010u;
goto P_0c08845e;
P_0c08845e: /* original f3f6, guest PC 0x0c08845e */
if(!s->budget--) { s->failed_pc=0x0c08845eu; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c088460;
P_0c088460: /* original e014, guest PC 0x0c088460 */
if(!s->budget--) { s->failed_pc=0x0c088460u; return 0; }
r[0]=0x00000014u;
goto P_0c088462;
P_0c088462: /* original fe3a, guest PC 0x0c088462 */
if(!s->budget--) { s->failed_pc=0x0c088462u; return 0; }
vf3_matrix_store(s,ram,3,r[14]);
goto P_0c088464;
P_0c088464: /* original f3f6, guest PC 0x0c088464 */
if(!s->budget--) { s->failed_pc=0x0c088464u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c088466;
P_0c088466: /* original e004, guest PC 0x0c088466 */
if(!s->budget--) { s->failed_pc=0x0c088466u; return 0; }
r[0]=0x00000004u;
goto P_0c088468;
P_0c088468: /* original fe37, guest PC 0x0c088468 */
if(!s->budget--) { s->failed_pc=0x0c088468u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c08846a;
P_0c08846a: /* original e018, guest PC 0x0c08846a */
if(!s->budget--) { s->failed_pc=0x0c08846au; return 0; }
r[0]=0x00000018u;
goto P_0c08846c;
P_0c08846c: /* original 65f3, guest PC 0x0c08846c */
if(!s->budget--) { s->failed_pc=0x0c08846cu; return 0; }
r[5]=r[15];
goto P_0c08846e;
P_0c08846e: /* original f3f6, guest PC 0x0c08846e */
if(!s->budget--) { s->failed_pc=0x0c08846eu; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c088470;
P_0c088470: /* original 66f3, guest PC 0x0c088470 */
if(!s->budget--) { s->failed_pc=0x0c088470u; return 0; }
r[6]=r[15];
goto P_0c088472;
P_0c088472: /* original e008, guest PC 0x0c088472 */
if(!s->budget--) { s->failed_pc=0x0c088472u; return 0; }
r[0]=0x00000008u;
goto P_0c088474;
P_0c088474: /* original 67f3, guest PC 0x0c088474 */
if(!s->budget--) { s->failed_pc=0x0c088474u; return 0; }
r[7]=r[15];
goto P_0c088476;
P_0c088476: /* original 7604, guest PC 0x0c088476 */
if(!s->budget--) { s->failed_pc=0x0c088476u; return 0; }
r[6]+=0x00000004u;
goto P_0c088478;
P_0c088478: /* original fe37, guest PC 0x0c088478 */
if(!s->budget--) { s->failed_pc=0x0c088478u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c08847a;
P_0c08847a: /* original 7510, guest PC 0x0c08847a */
if(!s->budget--) { s->failed_pc=0x0c08847au; return 0; }
r[5]+=0x00000010u;
goto P_0c08847c;
P_0c08847c: /* original f4fc, guest PC 0x0c08847c */
if(!s->budget--) { s->failed_pc=0x0c08847cu; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c08847e;
P_0c08847e: /* original bf10, guest PC 0x0c08847e */
if(!s->budget--) { s->failed_pc=0x0c08847eu; return 0; }
target=0x0c0882a2u; r[16]=0x0c088482u;
r[4]=r[12];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c088482u) { target=s->pc; goto dispatch; }
goto P_0c088482;
P_0c088480: /* original 64c3, guest PC 0x0c088480 */
if(!s->budget--) { s->failed_pc=0x0c088480u; return 0; }
r[4]=r[12];
goto P_0c088482;
P_0c088482: /* original 7f1c, guest PC 0x0c088482 */
if(!s->budget--) { s->failed_pc=0x0c088482u; return 0; }
r[15]+=0x0000001cu;
goto P_0c088484;
P_0c088484: /* original 4f26, guest PC 0x0c088484 */
if(!s->budget--) { s->failed_pc=0x0c088484u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c088486;
P_0c088486: /* original fff9, guest PC 0x0c088486 */
if(!s->budget--) { s->failed_pc=0x0c088486u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c088488;
P_0c088488: /* original 6cf6, guest PC 0x0c088488 */
if(!s->budget--) { s->failed_pc=0x0c088488u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c08848a;
P_0c08848a: /* original 6df6, guest PC 0x0c08848a */
if(!s->budget--) { s->failed_pc=0x0c08848au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c08848c;
P_0c08848c: /* original 000b, guest PC 0x0c08848c */
if(!s->budget--) { s->failed_pc=0x0c08848cu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c08848e: /* original 6ef6, guest PC 0x0c08848e */
if(!s->budget--) { s->failed_pc=0x0c08848eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c088490u,s,ram);
P_0c08a076: /* original 4f22, guest PC 0x0c08a076 */
if(!s->budget--) { s->failed_pc=0x0c08a076u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c08a078;
P_0c08a078: /* original 6432, guest PC 0x0c08a078 */
if(!s->budget--) { s->failed_pc=0x0c08a078u; return 0; }
tmp=read(ram,r[3],4);
r[4]=tmp;
goto P_0c08a07a;
P_0c08a07a: /* original dd5d, guest PC 0x0c08a07a */
if(!s->budget--) { s->failed_pc=0x0c08a07au; return 0; }
r[13]=read(ram,0x0c08a1f0u,4);
goto P_0c08a07c;
P_0c08a07c: /* original 1425, guest PC 0x0c08a07c */
if(!s->budget--) { s->failed_pc=0x0c08a07cu; return 0; }
write(ram,r[4]+20,r[2],4);
goto P_0c08a07e;
P_0c08a07e: /* original 7fc0, guest PC 0x0c08a07e */
if(!s->budget--) { s->failed_pc=0x0c08a07eu; return 0; }
r[15]+=0xffffffc0u;
goto P_0c08a080;
P_0c08a080: /* original d15d, guest PC 0x0c08a080 */
if(!s->budget--) { s->failed_pc=0x0c08a080u; return 0; }
r[1]=read(ram,0x0c08a1f8u,4);
goto P_0c08a082;
P_0c08a082: /* original 410b, guest PC 0x0c08a082 */
if(!s->budget--) { s->failed_pc=0x0c08a082u; return 0; }
target=r[1];
r[16]=0x0c08a086u;
r[4]=r[2];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08a086u) { target=s->pc; goto dispatch; }
goto P_0c08a086;
P_0c08a084: /* original 6423, guest PC 0x0c08a084 */
if(!s->budget--) { s->failed_pc=0x0c08a084u; return 0; }
r[4]=r[2];
goto P_0c08a086;
P_0c08a086: /* original 90aa, guest PC 0x0c08a086 */
if(!s->budget--) { s->failed_pc=0x0c08a086u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08a1deu,2);
goto P_0c08a088;
P_0c08a088: /* original e302, guest PC 0x0c08a088 */
if(!s->budget--) { s->failed_pc=0x0c08a088u; return 0; }
r[3]=0x00000002u;
goto P_0c08a08a;
P_0c08a08a: /* original 0d34, guest PC 0x0c08a08a */
if(!s->budget--) { s->failed_pc=0x0c08a08au; return 0; }
write(ram,r[13]+r[0],r[3],1);
goto P_0c08a08c;
P_0c08a08c: /* original d25b, guest PC 0x0c08a08c */
if(!s->budget--) { s->failed_pc=0x0c08a08cu; return 0; }
r[2]=read(ram,0x0c08a1fcu,4);
goto P_0c08a08e;
P_0c08a08e: /* original 90a7, guest PC 0x0c08a08e */
if(!s->budget--) { s->failed_pc=0x0c08a08eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08a1e0u,2);
goto P_0c08a090;
P_0c08a090: /* original 6422, guest PC 0x0c08a090 */
if(!s->budget--) { s->failed_pc=0x0c08a090u; return 0; }
tmp=read(ram,r[2],4);
r[4]=tmp;
goto P_0c08a092;
P_0c08a092: /* original 95a8, guest PC 0x0c08a092 */
if(!s->budget--) { s->failed_pc=0x0c08a092u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08a1e6u,2);
goto P_0c08a094;
P_0c08a094: /* original 044e, guest PC 0x0c08a094 */
if(!s->budget--) { s->failed_pc=0x0c08a094u; return 0; }
r[4]=read(ram,r[4]+r[0],4);
goto P_0c08a096;
P_0c08a096: /* original 90a5, guest PC 0x0c08a096 */
if(!s->budget--) { s->failed_pc=0x0c08a096u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08a1e4u,2);
goto P_0c08a098;
P_0c08a098: /* original 9ea3, guest PC 0x0c08a098 */
if(!s->budget--) { s->failed_pc=0x0c08a098u; return 0; }
r[14]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08a1e2u,2);
goto P_0c08a09a;
P_0c08a09a: /* original 6c43, guest PC 0x0c08a09a */
if(!s->budget--) { s->failed_pc=0x0c08a09au; return 0; }
r[12]=r[4];
goto P_0c08a09c;
P_0c08a09c: /* original 0bde, guest PC 0x0c08a09c */
if(!s->budget--) { s->failed_pc=0x0c08a09cu; return 0; }
r[11]=read(ram,r[13]+r[0],4);
goto P_0c08a09e;
P_0c08a09e: /* original d358, guest PC 0x0c08a09e */
if(!s->budget--) { s->failed_pc=0x0c08a09eu; return 0; }
r[3]=read(ram,0x0c08a200u,4);
goto P_0c08a0a0;
P_0c08a0a0: /* original 3e4c, guest PC 0x0c08a0a0 */
if(!s->budget--) { s->failed_pc=0x0c08a0a0u; return 0; }
r[14]+=r[4];
goto P_0c08a0a2;
P_0c08a0a2: /* original 35bc, guest PC 0x0c08a0a2 */
if(!s->budget--) { s->failed_pc=0x0c08a0a2u; return 0; }
r[5]+=r[11];
goto P_0c08a0a4;
P_0c08a0a4: /* original 430b, guest PC 0x0c08a0a4 */
if(!s->budget--) { s->failed_pc=0x0c08a0a4u; return 0; }
target=r[3];
r[16]=0x0c08a0a8u;
r[4]=r[15];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08a0a8u) { target=s->pc; goto dispatch; }
goto P_0c08a0a8;
P_0c08a0a6: /* original 64f3, guest PC 0x0c08a0a6 */
if(!s->budget--) { s->failed_pc=0x0c08a0a6u; return 0; }
r[4]=r[15];
goto P_0c08a0a8;
P_0c08a0a8: /* original c756, guest PC 0x0c08a0a8 */
if(!s->budget--) { s->failed_pc=0x0c08a0a8u; return 0; }
r[0]=0x0c08a204u;
goto P_0c08a0aa;
P_0c08a0aa: /* original 64e3, guest PC 0x0c08a0aa */
if(!s->budget--) { s->failed_pc=0x0c08a0aau; return 0; }
r[4]=r[14];
goto P_0c08a0ac;
P_0c08a0ac: /* original f408, guest PC 0x0c08a0ac */
if(!s->budget--) { s->failed_pc=0x0c08a0acu; return 0; }
vf3_matrix_load(s,ram,4,r[0]);
goto P_0c08a0ae;
P_0c08a0ae: /* original 65f3, guest PC 0x0c08a0ae */
if(!s->budget--) { s->failed_pc=0x0c08a0aeu; return 0; }
r[5]=r[15];
goto P_0c08a0b0;
P_0c08a0b0: /* original 909a, guest PC 0x0c08a0b0 */
if(!s->budget--) { s->failed_pc=0x0c08a0b0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08a1e8u,2);
goto P_0c08a0b2;
P_0c08a0b2: /* original f3b6, guest PC 0x0c08a0b2 */
if(!s->budget--) { s->failed_pc=0x0c08a0b2u; return 0; }
vf3_matrix_load(s,ram,3,r[11]+r[0]);
goto P_0c08a0b4;
P_0c08a0b4: /* original e034, guest PC 0x0c08a0b4 */
if(!s->budget--) { s->failed_pc=0x0c08a0b4u; return 0; }
r[0]=0x00000034u;
goto P_0c08a0b6;
P_0c08a0b6: /* original f340, guest PC 0x0c08a0b6 */
if(!s->budget--) { s->failed_pc=0x0c08a0b6u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'+');
goto P_0c08a0b8;
P_0c08a0b8: /* original ff37, guest PC 0x0c08a0b8 */
if(!s->budget--) { s->failed_pc=0x0c08a0b8u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c08a0ba;
P_0c08a0ba: /* original e004, guest PC 0x0c08a0ba */
if(!s->budget--) { s->failed_pc=0x0c08a0bau; return 0; }
r[0]=0x00000004u;
goto P_0c08a0bc;
P_0c08a0bc: /* original f49d, guest PC 0x0c08a0bc */
if(!s->budget--) { s->failed_pc=0x0c08a0bcu; return 0; }
fr[4]=0x3f800000u;
goto P_0c08a0be;
P_0c08a0be: /* original ff4a, guest PC 0x0c08a0be */
if(!s->budget--) { s->failed_pc=0x0c08a0beu; return 0; }
vf3_matrix_store(s,ram,4,r[15]);
goto P_0c08a0c0;
P_0c08a0c0: /* original ff8d, guest PC 0x0c08a0c0 */
if(!s->budget--) { s->failed_pc=0x0c08a0c0u; return 0; }
fr[15]=0;
goto P_0c08a0c2;
P_0c08a0c2: /* original fff7, guest PC 0x0c08a0c2 */
if(!s->budget--) { s->failed_pc=0x0c08a0c2u; return 0; }
vf3_matrix_store(s,ram,15,r[15]+r[0]);
goto P_0c08a0c4;
P_0c08a0c4: /* original e008, guest PC 0x0c08a0c4 */
if(!s->budget--) { s->failed_pc=0x0c08a0c4u; return 0; }
r[0]=0x00000008u;
goto P_0c08a0c6;
P_0c08a0c6: /* original fff7, guest PC 0x0c08a0c6 */
if(!s->budget--) { s->failed_pc=0x0c08a0c6u; return 0; }
vf3_matrix_store(s,ram,15,r[15]+r[0]);
goto P_0c08a0c8;
P_0c08a0c8: /* original e010, guest PC 0x0c08a0c8 */
if(!s->budget--) { s->failed_pc=0x0c08a0c8u; return 0; }
r[0]=0x00000010u;
goto P_0c08a0ca;
P_0c08a0ca: /* original fff7, guest PC 0x0c08a0ca */
if(!s->budget--) { s->failed_pc=0x0c08a0cau; return 0; }
vf3_matrix_store(s,ram,15,r[15]+r[0]);
goto P_0c08a0cc;
P_0c08a0cc: /* original e014, guest PC 0x0c08a0cc */
if(!s->budget--) { s->failed_pc=0x0c08a0ccu; return 0; }
r[0]=0x00000014u;
goto P_0c08a0ce;
P_0c08a0ce: /* original ff47, guest PC 0x0c08a0ce */
if(!s->budget--) { s->failed_pc=0x0c08a0ceu; return 0; }
vf3_matrix_store(s,ram,4,r[15]+r[0]);
goto P_0c08a0d0;
P_0c08a0d0: /* original e018, guest PC 0x0c08a0d0 */
if(!s->budget--) { s->failed_pc=0x0c08a0d0u; return 0; }
r[0]=0x00000018u;
goto P_0c08a0d2;
P_0c08a0d2: /* original fff7, guest PC 0x0c08a0d2 */
if(!s->budget--) { s->failed_pc=0x0c08a0d2u; return 0; }
vf3_matrix_store(s,ram,15,r[15]+r[0]);
goto P_0c08a0d4;
P_0c08a0d4: /* original e020, guest PC 0x0c08a0d4 */
if(!s->budget--) { s->failed_pc=0x0c08a0d4u; return 0; }
r[0]=0x00000020u;
goto P_0c08a0d6;
P_0c08a0d6: /* original fff7, guest PC 0x0c08a0d6 */
if(!s->budget--) { s->failed_pc=0x0c08a0d6u; return 0; }
vf3_matrix_store(s,ram,15,r[15]+r[0]);
goto P_0c08a0d8;
P_0c08a0d8: /* original e024, guest PC 0x0c08a0d8 */
if(!s->budget--) { s->failed_pc=0x0c08a0d8u; return 0; }
r[0]=0x00000024u;
goto P_0c08a0da;
P_0c08a0da: /* original fff7, guest PC 0x0c08a0da */
if(!s->budget--) { s->failed_pc=0x0c08a0dau; return 0; }
vf3_matrix_store(s,ram,15,r[15]+r[0]);
goto P_0c08a0dc;
P_0c08a0dc: /* original e028, guest PC 0x0c08a0dc */
if(!s->budget--) { s->failed_pc=0x0c08a0dcu; return 0; }
r[0]=0x00000028u;
goto P_0c08a0de;
P_0c08a0de: /* original ff47, guest PC 0x0c08a0de */
if(!s->budget--) { s->failed_pc=0x0c08a0deu; return 0; }
vf3_matrix_store(s,ram,4,r[15]+r[0]);
goto P_0c08a0e0;
P_0c08a0e0: /* original d347, guest PC 0x0c08a0e0 */
if(!s->budget--) { s->failed_pc=0x0c08a0e0u; return 0; }
r[3]=read(ram,0x0c08a200u,4);
goto P_0c08a0e2;
P_0c08a0e2: /* original 430b, guest PC 0x0c08a0e2 */
if(!s->budget--) { s->failed_pc=0x0c08a0e2u; return 0; }
target=r[3];
r[16]=0x0c08a0e6u;
r[4]+=0x00000010u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08a0e6u) { target=s->pc; goto dispatch; }
goto P_0c08a0e6;
P_0c08a0e4: /* original 7410, guest PC 0x0c08a0e4 */
if(!s->budget--) { s->failed_pc=0x0c08a0e4u; return 0; }
r[4]+=0x00000010u;
goto P_0c08a0e6;
P_0c08a0e6: /* original c748, guest PC 0x0c08a0e6 */
if(!s->budget--) { s->failed_pc=0x0c08a0e6u; return 0; }
r[0]=0x0c08a208u;
goto P_0c08a0e8;
P_0c08a0e8: /* original f5d8, guest PC 0x0c08a0e8 */
if(!s->budget--) { s->failed_pc=0x0c08a0e8u; return 0; }
vf3_matrix_load(s,ram,5,r[13]);
goto P_0c08a0ea;
P_0c08a0ea: /* original f708, guest PC 0x0c08a0ea */
if(!s->budget--) { s->failed_pc=0x0c08a0eau; return 0; }
vf3_matrix_load(s,ram,7,r[0]);
goto P_0c08a0ec;
P_0c08a0ec: /* original c747, guest PC 0x0c08a0ec */
if(!s->budget--) { s->failed_pc=0x0c08a0ecu; return 0; }
r[0]=0x0c08a20cu;
goto P_0c08a0ee;
P_0c08a0ee: /* original fb08, guest PC 0x0c08a0ee */
if(!s->budget--) { s->failed_pc=0x0c08a0eeu; return 0; }
vf3_matrix_load(s,ram,11,r[0]);
goto P_0c08a0f0;
P_0c08a0f0: /* original c747, guest PC 0x0c08a0f0 */
if(!s->budget--) { s->failed_pc=0x0c08a0f0u; return 0; }
r[0]=0x0c08a210u;
goto P_0c08a0f2;
P_0c08a0f2: /* original f808, guest PC 0x0c08a0f2 */
if(!s->budget--) { s->failed_pc=0x0c08a0f2u; return 0; }
vf3_matrix_load(s,ram,8,r[0]);
goto P_0c08a0f4;
P_0c08a0f4: /* original c747, guest PC 0x0c08a0f4 */
if(!s->budget--) { s->failed_pc=0x0c08a0f4u; return 0; }
r[0]=0x0c08a214u;
goto P_0c08a0f6;
P_0c08a0f6: /* original f908, guest PC 0x0c08a0f6 */
if(!s->budget--) { s->failed_pc=0x0c08a0f6u; return 0; }
vf3_matrix_load(s,ram,9,r[0]);
goto P_0c08a0f8;
P_0c08a0f8: /* original e300, guest PC 0x0c08a0f8 */
if(!s->budget--) { s->failed_pc=0x0c08a0f8u; return 0; }
r[3]=0x00000000u;
goto P_0c08a0fa;
P_0c08a0fa: /* original 9076, guest PC 0x0c08a0fa */
if(!s->budget--) { s->failed_pc=0x0c08a0fau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08a1eau,2);
goto P_0c08a0fc;
P_0c08a0fc: /* original fa8c, guest PC 0x0c08a0fc */
if(!s->budget--) { s->failed_pc=0x0c08a0fcu; return 0; }
vf3_matrix_move(s,10,8);
goto P_0c08a0fe;
P_0c08a0fe: /* original f4fc, guest PC 0x0c08a0fe */
if(!s->budget--) { s->failed_pc=0x0c08a0feu; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c08a100;
P_0c08a100: /* original f54d, guest PC 0x0c08a100 */
if(!s->budget--) { s->failed_pc=0x0c08a100u; return 0; }
fr[5]^=0x80000000u;
goto P_0c08a102;
P_0c08a102: /* original f67c, guest PC 0x0c08a102 */
if(!s->budget--) { s->failed_pc=0x0c08a102u; return 0; }
vf3_matrix_move(s,6,7);
goto P_0c08a104;
P_0c08a104: /* original 0e35, guest PC 0x0c08a104 */
if(!s->budget--) { s->failed_pc=0x0c08a104u; return 0; }
write(ram,r[14]+r[0],r[3],2);
goto P_0c08a106;
P_0c08a106: /* original e004, guest PC 0x0c08a106 */
if(!s->budget--) { s->failed_pc=0x0c08a106u; return 0; }
r[0]=0x00000004u;
goto P_0c08a108;
P_0c08a108: /* original feba, guest PC 0x0c08a108 */
if(!s->budget--) { s->failed_pc=0x0c08a108u; return 0; }
vf3_matrix_store(s,ram,11,r[14]);
goto P_0c08a10a;
P_0c08a10a: /* original fea7, guest PC 0x0c08a10a */
if(!s->budget--) { s->failed_pc=0x0c08a10au; return 0; }
vf3_matrix_store(s,ram,10,r[14]+r[0]);
goto P_0c08a10c;
P_0c08a10c: /* original e008, guest PC 0x0c08a10c */
if(!s->budget--) { s->failed_pc=0x0c08a10cu; return 0; }
r[0]=0x00000008u;
goto P_0c08a10e;
P_0c08a10e: /* original fe97, guest PC 0x0c08a10e */
if(!s->budget--) { s->failed_pc=0x0c08a10eu; return 0; }
vf3_matrix_store(s,ram,9,r[14]+r[0]);
goto P_0c08a110;
P_0c08a110: /* original e00c, guest PC 0x0c08a110 */
if(!s->budget--) { s->failed_pc=0x0c08a110u; return 0; }
r[0]=0x0000000cu;
goto P_0c08a112;
P_0c08a112: /* original fea7, guest PC 0x0c08a112 */
if(!s->budget--) { s->failed_pc=0x0c08a112u; return 0; }
vf3_matrix_store(s,ram,10,r[14]+r[0]);
goto P_0c08a114;
P_0c08a114: /* original e068, guest PC 0x0c08a114 */
if(!s->budget--) { s->failed_pc=0x0c08a114u; return 0; }
r[0]=0x00000068u;
goto P_0c08a116;
P_0c08a116: /* original fe47, guest PC 0x0c08a116 */
if(!s->budget--) { s->failed_pc=0x0c08a116u; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c08a118;
P_0c08a118: /* original e06c, guest PC 0x0c08a118 */
if(!s->budget--) { s->failed_pc=0x0c08a118u; return 0; }
r[0]=0x0000006cu;
goto P_0c08a11a;
P_0c08a11a: /* original fe57, guest PC 0x0c08a11a */
if(!s->budget--) { s->failed_pc=0x0c08a11au; return 0; }
vf3_matrix_store(s,ram,5,r[14]+r[0]);
goto P_0c08a11c;
P_0c08a11c: /* original e070, guest PC 0x0c08a11c */
if(!s->budget--) { s->failed_pc=0x0c08a11cu; return 0; }
r[0]=0x00000070u;
goto P_0c08a11e;
P_0c08a11e: /* original fe47, guest PC 0x0c08a11e */
if(!s->budget--) { s->failed_pc=0x0c08a11eu; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c08a120;
P_0c08a120: /* original e074, guest PC 0x0c08a120 */
if(!s->budget--) { s->failed_pc=0x0c08a120u; return 0; }
r[0]=0x00000074u;
goto P_0c08a122;
P_0c08a122: /* original fe67, guest PC 0x0c08a122 */
if(!s->budget--) { s->failed_pc=0x0c08a122u; return 0; }
vf3_matrix_store(s,ram,6,r[14]+r[0]);
goto P_0c08a124;
P_0c08a124: /* original e078, guest PC 0x0c08a124 */
if(!s->budget--) { s->failed_pc=0x0c08a124u; return 0; }
r[0]=0x00000078u;
goto P_0c08a126;
P_0c08a126: /* original fe67, guest PC 0x0c08a126 */
if(!s->budget--) { s->failed_pc=0x0c08a126u; return 0; }
vf3_matrix_store(s,ram,6,r[14]+r[0]);
goto P_0c08a128;
P_0c08a128: /* original c73b, guest PC 0x0c08a128 */
if(!s->budget--) { s->failed_pc=0x0c08a128u; return 0; }
r[0]=0x0c08a218u;
goto P_0c08a12a;
P_0c08a12a: /* original f508, guest PC 0x0c08a12a */
if(!s->budget--) { s->failed_pc=0x0c08a12au; return 0; }
vf3_matrix_load(s,ram,5,r[0]);
goto P_0c08a12c;
P_0c08a12c: /* original c73b, guest PC 0x0c08a12c */
if(!s->budget--) { s->failed_pc=0x0c08a12cu; return 0; }
r[0]=0x0c08a21cu;
goto P_0c08a12e;
P_0c08a12e: /* original f608, guest PC 0x0c08a12e */
if(!s->budget--) { s->failed_pc=0x0c08a12eu; return 0; }
vf3_matrix_load(s,ram,6,r[0]);
goto P_0c08a130;
P_0c08a130: /* original c73b, guest PC 0x0c08a130 */
if(!s->budget--) { s->failed_pc=0x0c08a130u; return 0; }
r[0]=0x0c08a220u;
goto P_0c08a132;
P_0c08a132: /* original f708, guest PC 0x0c08a132 */
if(!s->budget--) { s->failed_pc=0x0c08a132u; return 0; }
vf3_matrix_load(s,ram,7,r[0]);
goto P_0c08a134;
P_0c08a134: /* original e05c, guest PC 0x0c08a134 */
if(!s->budget--) { s->failed_pc=0x0c08a134u; return 0; }
r[0]=0x0000005cu;
goto P_0c08a136;
P_0c08a136: /* original fe47, guest PC 0x0c08a136 */
if(!s->budget--) { s->failed_pc=0x0c08a136u; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c08a138;
P_0c08a138: /* original e060, guest PC 0x0c08a138 */
if(!s->budget--) { s->failed_pc=0x0c08a138u; return 0; }
r[0]=0x00000060u;
goto P_0c08a13a;
P_0c08a13a: /* original fe47, guest PC 0x0c08a13a */
if(!s->budget--) { s->failed_pc=0x0c08a13au; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c08a13c;
P_0c08a13c: /* original e064, guest PC 0x0c08a13c */
if(!s->budget--) { s->failed_pc=0x0c08a13cu; return 0; }
r[0]=0x00000064u;
goto P_0c08a13e;
P_0c08a13e: /* original fe47, guest PC 0x0c08a13e */
if(!s->budget--) { s->failed_pc=0x0c08a13eu; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c08a140;
P_0c08a140: /* original e050, guest PC 0x0c08a140 */
if(!s->budget--) { s->failed_pc=0x0c08a140u; return 0; }
r[0]=0x00000050u;
goto P_0c08a142;
P_0c08a142: /* original fe57, guest PC 0x0c08a142 */
if(!s->budget--) { s->failed_pc=0x0c08a142u; return 0; }
vf3_matrix_store(s,ram,5,r[14]+r[0]);
goto P_0c08a144;
P_0c08a144: /* original e054, guest PC 0x0c08a144 */
if(!s->budget--) { s->failed_pc=0x0c08a144u; return 0; }
r[0]=0x00000054u;
goto P_0c08a146;
P_0c08a146: /* original fe67, guest PC 0x0c08a146 */
if(!s->budget--) { s->failed_pc=0x0c08a146u; return 0; }
vf3_matrix_store(s,ram,6,r[14]+r[0]);
goto P_0c08a148;
P_0c08a148: /* original e058, guest PC 0x0c08a148 */
if(!s->budget--) { s->failed_pc=0x0c08a148u; return 0; }
r[0]=0x00000058u;
goto P_0c08a14a;
P_0c08a14a: /* original fe77, guest PC 0x0c08a14a */
if(!s->budget--) { s->failed_pc=0x0c08a14au; return 0; }
vf3_matrix_store(s,ram,7,r[14]+r[0]);
goto P_0c08a14c;
P_0c08a14c: /* original e07c, guest PC 0x0c08a14c */
if(!s->budget--) { s->failed_pc=0x0c08a14cu; return 0; }
r[0]=0x0000007cu;
goto P_0c08a14e;
P_0c08a14e: /* original fe47, guest PC 0x0c08a14e */
if(!s->budget--) { s->failed_pc=0x0c08a14eu; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c08a150;
P_0c08a150: /* original 7004, guest PC 0x0c08a150 */
if(!s->budget--) { s->failed_pc=0x0c08a150u; return 0; }
r[0]+=0x00000004u;
goto P_0c08a152;
P_0c08a152: /* original fe47, guest PC 0x0c08a152 */
if(!s->budget--) { s->failed_pc=0x0c08a152u; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c08a154;
P_0c08a154: /* original 7004, guest PC 0x0c08a154 */
if(!s->budget--) { s->failed_pc=0x0c08a154u; return 0; }
r[0]+=0x00000004u;
goto P_0c08a156;
P_0c08a156: /* original fe47, guest PC 0x0c08a156 */
if(!s->budget--) { s->failed_pc=0x0c08a156u; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c08a158;
P_0c08a158: /* original 7004, guest PC 0x0c08a158 */
if(!s->budget--) { s->failed_pc=0x0c08a158u; return 0; }
r[0]+=0x00000004u;
goto P_0c08a15a;
P_0c08a15a: /* original fe47, guest PC 0x0c08a15a */
if(!s->budget--) { s->failed_pc=0x0c08a15au; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c08a15c;
P_0c08a15c: /* original c731, guest PC 0x0c08a15c */
if(!s->budget--) { s->failed_pc=0x0c08a15cu; return 0; }
r[0]=0x0c08a224u;
goto P_0c08a15e;
P_0c08a15e: /* original f808, guest PC 0x0c08a15e */
if(!s->budget--) { s->failed_pc=0x0c08a15eu; return 0; }
vf3_matrix_load(s,ram,8,r[0]);
goto P_0c08a160;
P_0c08a160: /* original 9044, guest PC 0x0c08a160 */
if(!s->budget--) { s->failed_pc=0x0c08a160u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08a1ecu,2);
goto P_0c08a162;
P_0c08a162: /* original fe87, guest PC 0x0c08a162 */
if(!s->budget--) { s->failed_pc=0x0c08a162u; return 0; }
vf3_matrix_store(s,ram,8,r[14]+r[0]);
goto P_0c08a164;
P_0c08a164: /* original 7004, guest PC 0x0c08a164 */
if(!s->budget--) { s->failed_pc=0x0c08a164u; return 0; }
r[0]+=0x00000004u;
goto P_0c08a166;
P_0c08a166: /* original fe47, guest PC 0x0c08a166 */
if(!s->budget--) { s->failed_pc=0x0c08a166u; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c08a168;
P_0c08a168: /* original c72f, guest PC 0x0c08a168 */
if(!s->budget--) { s->failed_pc=0x0c08a168u; return 0; }
r[0]=0x0c08a228u;
goto P_0c08a16a;
P_0c08a16a: /* original 64c3, guest PC 0x0c08a16a */
if(!s->budget--) { s->failed_pc=0x0c08a16au; return 0; }
r[4]=r[12];
goto P_0c08a16c;
P_0c08a16c: /* original 7404, guest PC 0x0c08a16c */
if(!s->budget--) { s->failed_pc=0x0c08a16cu; return 0; }
r[4]+=0x00000004u;
goto P_0c08a16e;
P_0c08a16e: /* original e310, guest PC 0x0c08a16e */
if(!s->budget--) { s->failed_pc=0x0c08a16eu; return 0; }
r[3]=0x00000010u;
goto P_0c08a170;
P_0c08a170: /* original 2c32, guest PC 0x0c08a170 */
if(!s->budget--) { s->failed_pc=0x0c08a170u; return 0; }
write(ram,r[12],r[3],4);
goto P_0c08a172;
P_0c08a172: /* original f908, guest PC 0x0c08a172 */
if(!s->budget--) { s->failed_pc=0x0c08a172u; return 0; }
vf3_matrix_load(s,ram,9,r[0]);
goto P_0c08a174;
P_0c08a174: /* original c72d, guest PC 0x0c08a174 */
if(!s->budget--) { s->failed_pc=0x0c08a174u; return 0; }
r[0]=0x0c08a22cu;
goto P_0c08a176;
P_0c08a176: /* original fa08, guest PC 0x0c08a176 */
if(!s->budget--) { s->failed_pc=0x0c08a176u; return 0; }
vf3_matrix_load(s,ram,10,r[0]);
goto P_0c08a178;
P_0c08a178: /* original c72d, guest PC 0x0c08a178 */
if(!s->budget--) { s->failed_pc=0x0c08a178u; return 0; }
r[0]=0x0c08a230u;
goto P_0c08a17a;
P_0c08a17a: /* original f608, guest PC 0x0c08a17a */
if(!s->budget--) { s->failed_pc=0x0c08a17au; return 0; }
vf3_matrix_load(s,ram,6,r[0]);
goto P_0c08a17c;
P_0c08a17c: /* original c72d, guest PC 0x0c08a17c */
if(!s->budget--) { s->failed_pc=0x0c08a17cu; return 0; }
r[0]=0x0c08a234u;
goto P_0c08a17e;
P_0c08a17e: /* original f708, guest PC 0x0c08a17e */
if(!s->budget--) { s->failed_pc=0x0c08a17eu; return 0; }
vf3_matrix_load(s,ram,7,r[0]);
goto P_0c08a180;
P_0c08a180: /* original c72d, guest PC 0x0c08a180 */
if(!s->budget--) { s->failed_pc=0x0c08a180u; return 0; }
r[0]=0x0c08a238u;
goto P_0c08a182;
P_0c08a182: /* original f508, guest PC 0x0c08a182 */
if(!s->budget--) { s->failed_pc=0x0c08a182u; return 0; }
vf3_matrix_load(s,ram,5,r[0]);
goto P_0c08a184;
P_0c08a184: /* original e004, guest PC 0x0c08a184 */
if(!s->budget--) { s->failed_pc=0x0c08a184u; return 0; }
r[0]=0x00000004u;
goto P_0c08a186;
P_0c08a186: /* original f49a, guest PC 0x0c08a186 */
if(!s->budget--) { s->failed_pc=0x0c08a186u; return 0; }
vf3_matrix_store(s,ram,9,r[4]);
goto P_0c08a188;
P_0c08a188: /* original f457, guest PC 0x0c08a188 */
if(!s->budget--) { s->failed_pc=0x0c08a188u; return 0; }
vf3_matrix_store(s,ram,5,r[4]+r[0]);
goto P_0c08a18a;
P_0c08a18a: /* original e008, guest PC 0x0c08a18a */
if(!s->budget--) { s->failed_pc=0x0c08a18au; return 0; }
r[0]=0x00000008u;
goto P_0c08a18c;
P_0c08a18c: /* original f447, guest PC 0x0c08a18c */
if(!s->budget--) { s->failed_pc=0x0c08a18cu; return 0; }
vf3_matrix_store(s,ram,4,r[4]+r[0]);
goto P_0c08a18e;
P_0c08a18e: /* original 740c, guest PC 0x0c08a18e */
if(!s->budget--) { s->failed_pc=0x0c08a18eu; return 0; }
r[4]+=0x0000000cu;
goto P_0c08a190;
P_0c08a190: /* original e004, guest PC 0x0c08a190 */
if(!s->budget--) { s->failed_pc=0x0c08a190u; return 0; }
r[0]=0x00000004u;
goto P_0c08a192;
P_0c08a192: /* original f46a, guest PC 0x0c08a192 */
if(!s->budget--) { s->failed_pc=0x0c08a192u; return 0; }
vf3_matrix_store(s,ram,6,r[4]);
goto P_0c08a194;
P_0c08a194: /* original f457, guest PC 0x0c08a194 */
if(!s->budget--) { s->failed_pc=0x0c08a194u; return 0; }
vf3_matrix_store(s,ram,5,r[4]+r[0]);
goto P_0c08a196;
P_0c08a196: /* original e008, guest PC 0x0c08a196 */
if(!s->budget--) { s->failed_pc=0x0c08a196u; return 0; }
r[0]=0x00000008u;
goto P_0c08a198;
P_0c08a198: /* original f467, guest PC 0x0c08a198 */
if(!s->budget--) { s->failed_pc=0x0c08a198u; return 0; }
vf3_matrix_store(s,ram,6,r[4]+r[0]);
goto P_0c08a19a;
P_0c08a19a: /* original 740c, guest PC 0x0c08a19a */
if(!s->budget--) { s->failed_pc=0x0c08a19au; return 0; }
r[4]+=0x0000000cu;
goto P_0c08a19c;
P_0c08a19c: /* original e004, guest PC 0x0c08a19c */
if(!s->budget--) { s->failed_pc=0x0c08a19cu; return 0; }
r[0]=0x00000004u;
goto P_0c08a19e;
P_0c08a19e: /* original f44a, guest PC 0x0c08a19e */
if(!s->budget--) { s->failed_pc=0x0c08a19eu; return 0; }
vf3_matrix_store(s,ram,4,r[4]);
goto P_0c08a1a0;
P_0c08a1a0: /* original f457, guest PC 0x0c08a1a0 */
if(!s->budget--) { s->failed_pc=0x0c08a1a0u; return 0; }
vf3_matrix_store(s,ram,5,r[4]+r[0]);
goto P_0c08a1a2;
P_0c08a1a2: /* original e008, guest PC 0x0c08a1a2 */
if(!s->budget--) { s->failed_pc=0x0c08a1a2u; return 0; }
r[0]=0x00000008u;
goto P_0c08a1a4;
P_0c08a1a4: /* original f497, guest PC 0x0c08a1a4 */
if(!s->budget--) { s->failed_pc=0x0c08a1a4u; return 0; }
vf3_matrix_store(s,ram,9,r[4]+r[0]);
goto P_0c08a1a6;
P_0c08a1a6: /* original e004, guest PC 0x0c08a1a6 */
if(!s->budget--) { s->failed_pc=0x0c08a1a6u; return 0; }
r[0]=0x00000004u;
goto P_0c08a1a8;
P_0c08a1a8: /* original 740c, guest PC 0x0c08a1a8 */
if(!s->budget--) { s->failed_pc=0x0c08a1a8u; return 0; }
r[4]+=0x0000000cu;
goto P_0c08a1aa;
P_0c08a1aa: /* original f47a, guest PC 0x0c08a1aa */
if(!s->budget--) { s->failed_pc=0x0c08a1aau; return 0; }
vf3_matrix_store(s,ram,7,r[4]);
goto P_0c08a1ac;
P_0c08a1ac: /* original f457, guest PC 0x0c08a1ac */
if(!s->budget--) { s->failed_pc=0x0c08a1acu; return 0; }
vf3_matrix_store(s,ram,5,r[4]+r[0]);
goto P_0c08a1ae;
P_0c08a1ae: /* original e008, guest PC 0x0c08a1ae */
if(!s->budget--) { s->failed_pc=0x0c08a1aeu; return 0; }
r[0]=0x00000008u;
goto P_0c08a1b0;
P_0c08a1b0: /* original f467, guest PC 0x0c08a1b0 */
if(!s->budget--) { s->failed_pc=0x0c08a1b0u; return 0; }
vf3_matrix_store(s,ram,6,r[4]+r[0]);
goto P_0c08a1b2;
P_0c08a1b2: /* original e004, guest PC 0x0c08a1b2 */
if(!s->budget--) { s->failed_pc=0x0c08a1b2u; return 0; }
r[0]=0x00000004u;
goto P_0c08a1b4;
P_0c08a1b4: /* original 740c, guest PC 0x0c08a1b4 */
if(!s->budget--) { s->failed_pc=0x0c08a1b4u; return 0; }
r[4]+=0x0000000cu;
goto P_0c08a1b6;
P_0c08a1b6: /* original f4aa, guest PC 0x0c08a1b6 */
if(!s->budget--) { s->failed_pc=0x0c08a1b6u; return 0; }
vf3_matrix_store(s,ram,10,r[4]);
goto P_0c08a1b8;
P_0c08a1b8: /* original f457, guest PC 0x0c08a1b8 */
if(!s->budget--) { s->failed_pc=0x0c08a1b8u; return 0; }
vf3_matrix_store(s,ram,5,r[4]+r[0]);
goto P_0c08a1ba;
P_0c08a1ba: /* original e008, guest PC 0x0c08a1ba */
if(!s->budget--) { s->failed_pc=0x0c08a1bau; return 0; }
r[0]=0x00000008u;
goto P_0c08a1bc;
P_0c08a1bc: /* original f447, guest PC 0x0c08a1bc */
if(!s->budget--) { s->failed_pc=0x0c08a1bcu; return 0; }
vf3_matrix_store(s,ram,4,r[4]+r[0]);
goto P_0c08a1be;
P_0c08a1be: /* original e004, guest PC 0x0c08a1be */
if(!s->budget--) { s->failed_pc=0x0c08a1beu; return 0; }
r[0]=0x00000004u;
goto P_0c08a1c0;
P_0c08a1c0: /* original 740c, guest PC 0x0c08a1c0 */
if(!s->budget--) { s->failed_pc=0x0c08a1c0u; return 0; }
r[4]+=0x0000000cu;
goto P_0c08a1c2;
P_0c08a1c2: /* original f47a, guest PC 0x0c08a1c2 */
if(!s->budget--) { s->failed_pc=0x0c08a1c2u; return 0; }
vf3_matrix_store(s,ram,7,r[4]);
goto P_0c08a1c4;
P_0c08a1c4: /* original f457, guest PC 0x0c08a1c4 */
if(!s->budget--) { s->failed_pc=0x0c08a1c4u; return 0; }
vf3_matrix_store(s,ram,5,r[4]+r[0]);
goto P_0c08a1c6;
P_0c08a1c6: /* original e008, guest PC 0x0c08a1c6 */
if(!s->budget--) { s->failed_pc=0x0c08a1c6u; return 0; }
r[0]=0x00000008u;
goto P_0c08a1c8;
P_0c08a1c8: /* original f477, guest PC 0x0c08a1c8 */
if(!s->budget--) { s->failed_pc=0x0c08a1c8u; return 0; }
vf3_matrix_store(s,ram,7,r[4]+r[0]);
goto P_0c08a1ca;
P_0c08a1ca: /* original e004, guest PC 0x0c08a1ca */
if(!s->budget--) { s->failed_pc=0x0c08a1cau; return 0; }
r[0]=0x00000004u;
goto P_0c08a1cc;
P_0c08a1cc: /* original 740c, guest PC 0x0c08a1cc */
if(!s->budget--) { s->failed_pc=0x0c08a1ccu; return 0; }
r[4]+=0x0000000cu;
goto P_0c08a1ce;
P_0c08a1ce: /* original f44a, guest PC 0x0c08a1ce */
if(!s->budget--) { s->failed_pc=0x0c08a1ceu; return 0; }
vf3_matrix_store(s,ram,4,r[4]);
goto P_0c08a1d0;
P_0c08a1d0: /* original f457, guest PC 0x0c08a1d0 */
if(!s->budget--) { s->failed_pc=0x0c08a1d0u; return 0; }
vf3_matrix_store(s,ram,5,r[4]+r[0]);
goto P_0c08a1d2;
P_0c08a1d2: /* original e008, guest PC 0x0c08a1d2 */
if(!s->budget--) { s->failed_pc=0x0c08a1d2u; return 0; }
r[0]=0x00000008u;
goto P_0c08a1d4;
P_0c08a1d4: /* original f4a7, guest PC 0x0c08a1d4 */
if(!s->budget--) { s->failed_pc=0x0c08a1d4u; return 0; }
vf3_matrix_store(s,ram,10,r[4]+r[0]);
goto P_0c08a1d6;
P_0c08a1d6: /* original 740c, guest PC 0x0c08a1d6 */
if(!s->budget--) { s->failed_pc=0x0c08a1d6u; return 0; }
r[4]+=0x0000000cu;
goto P_0c08a1d8;
P_0c08a1d8: /* original f46a, guest PC 0x0c08a1d8 */
if(!s->budget--) { s->failed_pc=0x0c08a1d8u; return 0; }
vf3_matrix_store(s,ram,6,r[4]);
goto P_0c08a1da;
P_0c08a1da: /* original a02f, guest PC 0x0c08a1da */
if(!s->budget--) { s->failed_pc=0x0c08a1dau; return 0; }
goto P_0c08a23c;
P_0c08a1dc: /* original 0009, guest PC 0x0c08a1dc */
if(!s->budget--) { s->failed_pc=0x0c08a1dcu; return 0; }
return vf3_matrix_family(0x0c08a1deu,s,ram);
P_0c08a23c: /* original e004, guest PC 0x0c08a23c */
if(!s->budget--) { s->failed_pc=0x0c08a23cu; return 0; }
r[0]=0x00000004u;
goto P_0c08a23e;
P_0c08a23e: /* original f457, guest PC 0x0c08a23e */
if(!s->budget--) { s->failed_pc=0x0c08a23eu; return 0; }
vf3_matrix_store(s,ram,5,r[4]+r[0]);
goto P_0c08a240;
P_0c08a240: /* original e008, guest PC 0x0c08a240 */
if(!s->budget--) { s->failed_pc=0x0c08a240u; return 0; }
r[0]=0x00000008u;
goto P_0c08a242;
P_0c08a242: /* original f477, guest PC 0x0c08a242 */
if(!s->budget--) { s->failed_pc=0x0c08a242u; return 0; }
vf3_matrix_store(s,ram,7,r[4]+r[0]);
goto P_0c08a244;
P_0c08a244: /* original c751, guest PC 0x0c08a244 */
if(!s->budget--) { s->failed_pc=0x0c08a244u; return 0; }
r[0]=0x0c08a38cu;
goto P_0c08a246;
P_0c08a246: /* original fa08, guest PC 0x0c08a246 */
if(!s->budget--) { s->failed_pc=0x0c08a246u; return 0; }
vf3_matrix_load(s,ram,10,r[0]);
goto P_0c08a248;
P_0c08a248: /* original c751, guest PC 0x0c08a248 */
if(!s->budget--) { s->failed_pc=0x0c08a248u; return 0; }
r[0]=0x0c08a390u;
goto P_0c08a24a;
P_0c08a24a: /* original f908, guest PC 0x0c08a24a */
if(!s->budget--) { s->failed_pc=0x0c08a24au; return 0; }
vf3_matrix_load(s,ram,9,r[0]);
goto P_0c08a24c;
P_0c08a24c: /* original c751, guest PC 0x0c08a24c */
if(!s->budget--) { s->failed_pc=0x0c08a24cu; return 0; }
r[0]=0x0c08a394u;
goto P_0c08a24e;
P_0c08a24e: /* original f708, guest PC 0x0c08a24e */
if(!s->budget--) { s->failed_pc=0x0c08a24eu; return 0; }
vf3_matrix_load(s,ram,7,r[0]);
goto P_0c08a250;
P_0c08a250: /* original c751, guest PC 0x0c08a250 */
if(!s->budget--) { s->failed_pc=0x0c08a250u; return 0; }
r[0]=0x0c08a398u;
goto P_0c08a252;
P_0c08a252: /* original f608, guest PC 0x0c08a252 */
if(!s->budget--) { s->failed_pc=0x0c08a252u; return 0; }
vf3_matrix_load(s,ram,6,r[0]);
goto P_0c08a254;
P_0c08a254: /* original e004, guest PC 0x0c08a254 */
if(!s->budget--) { s->failed_pc=0x0c08a254u; return 0; }
r[0]=0x00000004u;
goto P_0c08a256;
P_0c08a256: /* original 740c, guest PC 0x0c08a256 */
if(!s->budget--) { s->failed_pc=0x0c08a256u; return 0; }
r[4]+=0x0000000cu;
goto P_0c08a258;
P_0c08a258: /* original f58c, guest PC 0x0c08a258 */
if(!s->budget--) { s->failed_pc=0x0c08a258u; return 0; }
vf3_matrix_move(s,5,8);
goto P_0c08a25a;
P_0c08a25a: /* original f4aa, guest PC 0x0c08a25a */
if(!s->budget--) { s->failed_pc=0x0c08a25au; return 0; }
vf3_matrix_store(s,ram,10,r[4]);
goto P_0c08a25c;
P_0c08a25c: /* original f457, guest PC 0x0c08a25c */
if(!s->budget--) { s->failed_pc=0x0c08a25cu; return 0; }
vf3_matrix_store(s,ram,5,r[4]+r[0]);
goto P_0c08a25e;
P_0c08a25e: /* original e008, guest PC 0x0c08a25e */
if(!s->budget--) { s->failed_pc=0x0c08a25eu; return 0; }
r[0]=0x00000008u;
goto P_0c08a260;
P_0c08a260: /* original f447, guest PC 0x0c08a260 */
if(!s->budget--) { s->failed_pc=0x0c08a260u; return 0; }
vf3_matrix_store(s,ram,4,r[4]+r[0]);
goto P_0c08a262;
P_0c08a262: /* original e004, guest PC 0x0c08a262 */
if(!s->budget--) { s->failed_pc=0x0c08a262u; return 0; }
r[0]=0x00000004u;
goto P_0c08a264;
P_0c08a264: /* original 740c, guest PC 0x0c08a264 */
if(!s->budget--) { s->failed_pc=0x0c08a264u; return 0; }
r[4]+=0x0000000cu;
goto P_0c08a266;
P_0c08a266: /* original f47a, guest PC 0x0c08a266 */
if(!s->budget--) { s->failed_pc=0x0c08a266u; return 0; }
vf3_matrix_store(s,ram,7,r[4]);
goto P_0c08a268;
P_0c08a268: /* original f457, guest PC 0x0c08a268 */
if(!s->budget--) { s->failed_pc=0x0c08a268u; return 0; }
vf3_matrix_store(s,ram,5,r[4]+r[0]);
goto P_0c08a26a;
P_0c08a26a: /* original e008, guest PC 0x0c08a26a */
if(!s->budget--) { s->failed_pc=0x0c08a26au; return 0; }
r[0]=0x00000008u;
goto P_0c08a26c;
P_0c08a26c: /* original f477, guest PC 0x0c08a26c */
if(!s->budget--) { s->failed_pc=0x0c08a26cu; return 0; }
vf3_matrix_store(s,ram,7,r[4]+r[0]);
goto P_0c08a26e;
P_0c08a26e: /* original e004, guest PC 0x0c08a26e */
if(!s->budget--) { s->failed_pc=0x0c08a26eu; return 0; }
r[0]=0x00000004u;
goto P_0c08a270;
P_0c08a270: /* original 740c, guest PC 0x0c08a270 */
if(!s->budget--) { s->failed_pc=0x0c08a270u; return 0; }
r[4]+=0x0000000cu;
goto P_0c08a272;
P_0c08a272: /* original f44a, guest PC 0x0c08a272 */
if(!s->budget--) { s->failed_pc=0x0c08a272u; return 0; }
vf3_matrix_store(s,ram,4,r[4]);
goto P_0c08a274;
P_0c08a274: /* original f457, guest PC 0x0c08a274 */
if(!s->budget--) { s->failed_pc=0x0c08a274u; return 0; }
vf3_matrix_store(s,ram,5,r[4]+r[0]);
goto P_0c08a276;
P_0c08a276: /* original e008, guest PC 0x0c08a276 */
if(!s->budget--) { s->failed_pc=0x0c08a276u; return 0; }
r[0]=0x00000008u;
goto P_0c08a278;
P_0c08a278: /* original f4a7, guest PC 0x0c08a278 */
if(!s->budget--) { s->failed_pc=0x0c08a278u; return 0; }
vf3_matrix_store(s,ram,10,r[4]+r[0]);
goto P_0c08a27a;
P_0c08a27a: /* original 740c, guest PC 0x0c08a27a */
if(!s->budget--) { s->failed_pc=0x0c08a27au; return 0; }
r[4]+=0x0000000cu;
goto P_0c08a27c;
P_0c08a27c: /* original e004, guest PC 0x0c08a27c */
if(!s->budget--) { s->failed_pc=0x0c08a27cu; return 0; }
r[0]=0x00000004u;
goto P_0c08a27e;
P_0c08a27e: /* original f46a, guest PC 0x0c08a27e */
if(!s->budget--) { s->failed_pc=0x0c08a27eu; return 0; }
vf3_matrix_store(s,ram,6,r[4]);
goto P_0c08a280;
P_0c08a280: /* original f457, guest PC 0x0c08a280 */
if(!s->budget--) { s->failed_pc=0x0c08a280u; return 0; }
vf3_matrix_store(s,ram,5,r[4]+r[0]);
goto P_0c08a282;
P_0c08a282: /* original e008, guest PC 0x0c08a282 */
if(!s->budget--) { s->failed_pc=0x0c08a282u; return 0; }
r[0]=0x00000008u;
goto P_0c08a284;
P_0c08a284: /* original f477, guest PC 0x0c08a284 */
if(!s->budget--) { s->failed_pc=0x0c08a284u; return 0; }
vf3_matrix_store(s,ram,7,r[4]+r[0]);
goto P_0c08a286;
P_0c08a286: /* original e004, guest PC 0x0c08a286 */
if(!s->budget--) { s->failed_pc=0x0c08a286u; return 0; }
r[0]=0x00000004u;
goto P_0c08a288;
P_0c08a288: /* original 740c, guest PC 0x0c08a288 */
if(!s->budget--) { s->failed_pc=0x0c08a288u; return 0; }
r[4]+=0x0000000cu;
goto P_0c08a28a;
P_0c08a28a: /* original f49a, guest PC 0x0c08a28a */
if(!s->budget--) { s->failed_pc=0x0c08a28au; return 0; }
vf3_matrix_store(s,ram,9,r[4]);
goto P_0c08a28c;
P_0c08a28c: /* original f457, guest PC 0x0c08a28c */
if(!s->budget--) { s->failed_pc=0x0c08a28cu; return 0; }
vf3_matrix_store(s,ram,5,r[4]+r[0]);
goto P_0c08a28e;
P_0c08a28e: /* original e008, guest PC 0x0c08a28e */
if(!s->budget--) { s->failed_pc=0x0c08a28eu; return 0; }
r[0]=0x00000008u;
goto P_0c08a290;
P_0c08a290: /* original f447, guest PC 0x0c08a290 */
if(!s->budget--) { s->failed_pc=0x0c08a290u; return 0; }
vf3_matrix_store(s,ram,4,r[4]+r[0]);
goto P_0c08a292;
P_0c08a292: /* original e004, guest PC 0x0c08a292 */
if(!s->budget--) { s->failed_pc=0x0c08a292u; return 0; }
r[0]=0x00000004u;
goto P_0c08a294;
P_0c08a294: /* original 740c, guest PC 0x0c08a294 */
if(!s->budget--) { s->failed_pc=0x0c08a294u; return 0; }
r[4]+=0x0000000cu;
goto P_0c08a296;
P_0c08a296: /* original f46a, guest PC 0x0c08a296 */
if(!s->budget--) { s->failed_pc=0x0c08a296u; return 0; }
vf3_matrix_store(s,ram,6,r[4]);
goto P_0c08a298;
P_0c08a298: /* original f457, guest PC 0x0c08a298 */
if(!s->budget--) { s->failed_pc=0x0c08a298u; return 0; }
vf3_matrix_store(s,ram,5,r[4]+r[0]);
goto P_0c08a29a;
P_0c08a29a: /* original e008, guest PC 0x0c08a29a */
if(!s->budget--) { s->failed_pc=0x0c08a29au; return 0; }
r[0]=0x00000008u;
goto P_0c08a29c;
P_0c08a29c: /* original f467, guest PC 0x0c08a29c */
if(!s->budget--) { s->failed_pc=0x0c08a29cu; return 0; }
vf3_matrix_store(s,ram,6,r[4]+r[0]);
goto P_0c08a29e;
P_0c08a29e: /* original e004, guest PC 0x0c08a29e */
if(!s->budget--) { s->failed_pc=0x0c08a29eu; return 0; }
r[0]=0x00000004u;
goto P_0c08a2a0;
P_0c08a2a0: /* original 740c, guest PC 0x0c08a2a0 */
if(!s->budget--) { s->failed_pc=0x0c08a2a0u; return 0; }
r[4]+=0x0000000cu;
goto P_0c08a2a2;
P_0c08a2a2: /* original f44a, guest PC 0x0c08a2a2 */
if(!s->budget--) { s->failed_pc=0x0c08a2a2u; return 0; }
vf3_matrix_store(s,ram,4,r[4]);
goto P_0c08a2a4;
P_0c08a2a4: /* original f457, guest PC 0x0c08a2a4 */
if(!s->budget--) { s->failed_pc=0x0c08a2a4u; return 0; }
vf3_matrix_store(s,ram,5,r[4]+r[0]);
goto P_0c08a2a6;
P_0c08a2a6: /* original e008, guest PC 0x0c08a2a6 */
if(!s->budget--) { s->failed_pc=0x0c08a2a6u; return 0; }
r[0]=0x00000008u;
goto P_0c08a2a8;
P_0c08a2a8: /* original f497, guest PC 0x0c08a2a8 */
if(!s->budget--) { s->failed_pc=0x0c08a2a8u; return 0; }
vf3_matrix_store(s,ram,9,r[4]+r[0]);
goto P_0c08a2aa;
P_0c08a2aa: /* original e004, guest PC 0x0c08a2aa */
if(!s->budget--) { s->failed_pc=0x0c08a2aau; return 0; }
r[0]=0x00000004u;
goto P_0c08a2ac;
P_0c08a2ac: /* original 740c, guest PC 0x0c08a2ac */
if(!s->budget--) { s->failed_pc=0x0c08a2acu; return 0; }
r[4]+=0x0000000cu;
goto P_0c08a2ae;
P_0c08a2ae: /* original f47a, guest PC 0x0c08a2ae */
if(!s->budget--) { s->failed_pc=0x0c08a2aeu; return 0; }
vf3_matrix_store(s,ram,7,r[4]);
goto P_0c08a2b0;
P_0c08a2b0: /* original f457, guest PC 0x0c08a2b0 */
if(!s->budget--) { s->failed_pc=0x0c08a2b0u; return 0; }
vf3_matrix_store(s,ram,5,r[4]+r[0]);
goto P_0c08a2b2;
P_0c08a2b2: /* original e008, guest PC 0x0c08a2b2 */
if(!s->budget--) { s->failed_pc=0x0c08a2b2u; return 0; }
r[0]=0x00000008u;
goto P_0c08a2b4;
P_0c08a2b4: /* original f467, guest PC 0x0c08a2b4 */
if(!s->budget--) { s->failed_pc=0x0c08a2b4u; return 0; }
vf3_matrix_store(s,ram,6,r[4]+r[0]);
goto P_0c08a2b6;
P_0c08a2b6: /* original d339, guest PC 0x0c08a2b6 */
if(!s->budget--) { s->failed_pc=0x0c08a2b6u; return 0; }
r[3]=read(ram,0x0c08a39cu,4);
goto P_0c08a2b8;
P_0c08a2b8: /* original 430b, guest PC 0x0c08a2b8 */
if(!s->budget--) { s->failed_pc=0x0c08a2b8u; return 0; }
target=r[3];
r[16]=0x0c08a2bcu;
r[4]=0x00000001u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08a2bcu) { target=s->pc; goto dispatch; }
goto P_0c08a2bc;
P_0c08a2ba: /* original e401, guest PC 0x0c08a2ba */
if(!s->budget--) { s->failed_pc=0x0c08a2bau; return 0; }
r[4]=0x00000001u;
goto P_0c08a2bc;
P_0c08a2bc: /* original 7f40, guest PC 0x0c08a2bc */
if(!s->budget--) { s->failed_pc=0x0c08a2bcu; return 0; }
r[15]+=0x00000040u;
goto P_0c08a2be;
P_0c08a2be: /* original 4f26, guest PC 0x0c08a2be */
if(!s->budget--) { s->failed_pc=0x0c08a2beu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c08a2c0;
P_0c08a2c0: /* original fff9, guest PC 0x0c08a2c0 */
if(!s->budget--) { s->failed_pc=0x0c08a2c0u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c08a2c2;
P_0c08a2c2: /* original 6bf6, guest PC 0x0c08a2c2 */
if(!s->budget--) { s->failed_pc=0x0c08a2c2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c08a2c4;
P_0c08a2c4: /* original 6cf6, guest PC 0x0c08a2c4 */
if(!s->budget--) { s->failed_pc=0x0c08a2c4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c08a2c6;
P_0c08a2c6: /* original 6df6, guest PC 0x0c08a2c6 */
if(!s->budget--) { s->failed_pc=0x0c08a2c6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c08a2c8;
P_0c08a2c8: /* original 000b, guest PC 0x0c08a2c8 */
if(!s->budget--) { s->failed_pc=0x0c08a2c8u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c08a2ca: /* original 6ef6, guest PC 0x0c08a2ca */
if(!s->budget--) { s->failed_pc=0x0c08a2cau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c08a2ccu,s,ram);
P_0c08ed9a: /* original 4f22, guest PC 0x0c08ed9a */
if(!s->budget--) { s->failed_pc=0x0c08ed9au; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c08ed9c;
P_0c08ed9c: /* original 7fe4, guest PC 0x0c08ed9c */
if(!s->budget--) { s->failed_pc=0x0c08ed9cu; return 0; }
r[15]+=0xffffffe4u;
goto P_0c08ed9e;
P_0c08ed9e: /* original ff47, guest PC 0x0c08ed9e */
if(!s->budget--) { s->failed_pc=0x0c08ed9eu; return 0; }
vf3_matrix_store(s,ram,4,r[15]+r[0]);
goto P_0c08eda0;
P_0c08eda0: /* original e008, guest PC 0x0c08eda0 */
if(!s->budget--) { s->failed_pc=0x0c08eda0u; return 0; }
r[0]=0x00000008u;
goto P_0c08eda2;
P_0c08eda2: /* original ff57, guest PC 0x0c08eda2 */
if(!s->budget--) { s->failed_pc=0x0c08eda2u; return 0; }
vf3_matrix_store(s,ram,5,r[15]+r[0]);
goto P_0c08eda4;
P_0c08eda4: /* original e004, guest PC 0x0c08eda4 */
if(!s->budget--) { s->failed_pc=0x0c08eda4u; return 0; }
r[0]=0x00000004u;
goto P_0c08eda6;
P_0c08eda6: /* original ff67, guest PC 0x0c08eda6 */
if(!s->budget--) { s->failed_pc=0x0c08eda6u; return 0; }
vf3_matrix_store(s,ram,6,r[15]+r[0]);
goto P_0c08eda8;
P_0c08eda8: /* original c75e, guest PC 0x0c08eda8 */
if(!s->budget--) { s->failed_pc=0x0c08eda8u; return 0; }
r[0]=0x0c08ef24u;
goto P_0c08edaa;
P_0c08edaa: /* original d35f, guest PC 0x0c08edaa */
if(!s->budget--) { s->failed_pc=0x0c08edaau; return 0; }
r[3]=read(ram,0x0c08ef28u,4);
goto P_0c08edac;
P_0c08edac: /* original ff08, guest PC 0x0c08edac */
if(!s->budget--) { s->failed_pc=0x0c08edacu; return 0; }
vf3_matrix_load(s,ram,15,r[0]);
goto P_0c08edae;
P_0c08edae: /* original 430b, guest PC 0x0c08edae */
if(!s->budget--) { s->failed_pc=0x0c08edaeu; return 0; }
target=r[3];
r[16]=0x0c08edb2u;
r[4]=0x00000000u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08edb2u) { target=s->pc; goto dispatch; }
goto P_0c08edb2;
P_0c08edb0: /* original e400, guest PC 0x0c08edb0 */
if(!s->budget--) { s->failed_pc=0x0c08edb0u; return 0; }
r[4]=0x00000000u;
goto P_0c08edb2;
P_0c08edb2: /* original db5e, guest PC 0x0c08edb2 */
if(!s->budget--) { s->failed_pc=0x0c08edb2u; return 0; }
r[11]=read(ram,0x0c08ef2cu,4);
goto P_0c08edb4;
P_0c08edb4: /* original 4b0b, guest PC 0x0c08edb4 */
if(!s->budget--) { s->failed_pc=0x0c08edb4u; return 0; }
target=r[11];
r[16]=0x0c08edb8u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08edb8u) { target=s->pc; goto dispatch; }
goto P_0c08edb8;
P_0c08edb6: /* original 0009, guest PC 0x0c08edb6 */
if(!s->budget--) { s->failed_pc=0x0c08edb6u; return 0; }
goto P_0c08edb8;
P_0c08edb8: /* original 90a7, guest PC 0x0c08edb8 */
if(!s->budget--) { s->failed_pc=0x0c08edb8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08ef0au,2);
goto P_0c08edba;
P_0c08edba: /* original f4e6, guest PC 0x0c08edba */
if(!s->budget--) { s->failed_pc=0x0c08edbau; return 0; }
vf3_matrix_load(s,ram,4,r[14]+r[0]);
goto P_0c08edbc;
P_0c08edbc: /* original 7004, guest PC 0x0c08edbc */
if(!s->budget--) { s->failed_pc=0x0c08edbcu; return 0; }
r[0]+=0x00000004u;
goto P_0c08edbe;
P_0c08edbe: /* original f3e6, guest PC 0x0c08edbe */
if(!s->budget--) { s->failed_pc=0x0c08edbeu; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c08edc0;
P_0c08edc0: /* original ff3a, guest PC 0x0c08edc0 */
if(!s->budget--) { s->failed_pc=0x0c08edc0u; return 0; }
vf3_matrix_store(s,ram,3,r[15]);
goto P_0c08edc2;
P_0c08edc2: /* original 90a3, guest PC 0x0c08edc2 */
if(!s->budget--) { s->failed_pc=0x0c08edc2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08ef0cu,2);
goto P_0c08edc4;
P_0c08edc4: /* original f3e6, guest PC 0x0c08edc4 */
if(!s->budget--) { s->failed_pc=0x0c08edc4u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c08edc6;
P_0c08edc6: /* original e010, guest PC 0x0c08edc6 */
if(!s->budget--) { s->failed_pc=0x0c08edc6u; return 0; }
r[0]=0x00000010u;
goto P_0c08edc8;
P_0c08edc8: /* original ff37, guest PC 0x0c08edc8 */
if(!s->budget--) { s->failed_pc=0x0c08edc8u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c08edca;
P_0c08edca: /* original dd59, guest PC 0x0c08edca */
if(!s->budget--) { s->failed_pc=0x0c08edcau; return 0; }
r[13]=read(ram,0x0c08ef30u,4);
goto P_0c08edcc;
P_0c08edcc: /* original f63c, guest PC 0x0c08edcc */
if(!s->budget--) { s->failed_pc=0x0c08edccu; return 0; }
vf3_matrix_move(s,6,3);
goto P_0c08edce;
P_0c08edce: /* original f64d, guest PC 0x0c08edce */
if(!s->budget--) { s->failed_pc=0x0c08edceu; return 0; }
fr[6]^=0x80000000u;
goto P_0c08edd0;
P_0c08edd0: /* original 4d0b, guest PC 0x0c08edd0 */
if(!s->budget--) { s->failed_pc=0x0c08edd0u; return 0; }
target=r[13];
r[16]=0x0c08edd4u;
vf3_matrix_load(s,ram,5,r[15]);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08edd4u) { target=s->pc; goto dispatch; }
goto P_0c08edd4;
P_0c08edd2: /* original f5f8, guest PC 0x0c08edd2 */
if(!s->budget--) { s->failed_pc=0x0c08edd2u; return 0; }
vf3_matrix_load(s,ram,5,r[15]);
goto P_0c08edd4;
P_0c08edd4: /* original 909b, guest PC 0x0c08edd4 */
if(!s->budget--) { s->failed_pc=0x0c08edd4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08ef0eu,2);
goto P_0c08edd6;
P_0c08edd6: /* original dc57, guest PC 0x0c08edd6 */
if(!s->budget--) { s->failed_pc=0x0c08edd6u; return 0; }
r[12]=read(ram,0x0c08ef34u,4);
goto P_0c08edd8;
P_0c08edd8: /* original f6e6, guest PC 0x0c08edd8 */
if(!s->budget--) { s->failed_pc=0x0c08edd8u; return 0; }
vf3_matrix_load(s,ram,6,r[14]+r[0]);
goto P_0c08edda;
P_0c08edda: /* original 70fc, guest PC 0x0c08edda */
if(!s->budget--) { s->failed_pc=0x0c08eddau; return 0; }
r[0]+=0xfffffffcu;
goto P_0c08eddc;
P_0c08eddc: /* original f5e6, guest PC 0x0c08eddc */
if(!s->budget--) { s->failed_pc=0x0c08eddcu; return 0; }
vf3_matrix_load(s,ram,5,r[14]+r[0]);
goto P_0c08edde;
P_0c08edde: /* original 70fc, guest PC 0x0c08edde */
if(!s->budget--) { s->failed_pc=0x0c08eddeu; return 0; }
r[0]+=0xfffffffcu;
goto P_0c08ede0;
P_0c08ede0: /* original f4e6, guest PC 0x0c08ede0 */
if(!s->budget--) { s->failed_pc=0x0c08ede0u; return 0; }
vf3_matrix_load(s,ram,4,r[14]+r[0]);
goto P_0c08ede2;
P_0c08ede2: /* original 4c0b, guest PC 0x0c08ede2 */
if(!s->budget--) { s->failed_pc=0x0c08ede2u; return 0; }
target=r[12];
r[16]=0x0c08ede6u;
r[4]=r[15];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08ede6u) { target=s->pc; goto dispatch; }
goto P_0c08ede6;
P_0c08ede4: /* original 64f3, guest PC 0x0c08ede4 */
if(!s->budget--) { s->failed_pc=0x0c08ede4u; return 0; }
r[4]=r[15];
goto P_0c08ede6;
P_0c08ede6: /* original fe0c, guest PC 0x0c08ede6 */
if(!s->budget--) { s->failed_pc=0x0c08ede6u; return 0; }
vf3_matrix_move(s,14,0);
goto P_0c08ede8;
P_0c08ede8: /* original fef2, guest PC 0x0c08ede8 */
if(!s->budget--) { s->failed_pc=0x0c08ede8u; return 0; }
fr[14]=vf3_fpu_binary(fr[14],fr[15],r[18],'*');
goto P_0c08edea;
P_0c08edea: /* original da53, guest PC 0x0c08edea */
if(!s->budget--) { s->failed_pc=0x0c08edeau; return 0; }
r[10]=read(ram,0x0c08ef38u,4);
goto P_0c08edec;
P_0c08edec: /* original f5ec, guest PC 0x0c08edec */
if(!s->budget--) { s->failed_pc=0x0c08edecu; return 0; }
vf3_matrix_move(s,5,14);
goto P_0c08edee;
P_0c08edee: /* original f6ec, guest PC 0x0c08edee */
if(!s->budget--) { s->failed_pc=0x0c08edeeu; return 0; }
vf3_matrix_move(s,6,14);
goto P_0c08edf0;
P_0c08edf0: /* original 4a0b, guest PC 0x0c08edf0 */
if(!s->budget--) { s->failed_pc=0x0c08edf0u; return 0; }
target=r[10];
r[16]=0x0c08edf4u;
vf3_matrix_move(s,4,14);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08edf4u) { target=s->pc; goto dispatch; }
goto P_0c08edf4;
P_0c08edf2: /* original f4ec, guest PC 0x0c08edf2 */
if(!s->budget--) { s->failed_pc=0x0c08edf2u; return 0; }
vf3_matrix_move(s,4,14);
goto P_0c08edf4;
P_0c08edf4: /* original 4b0b, guest PC 0x0c08edf4 */
if(!s->budget--) { s->failed_pc=0x0c08edf4u; return 0; }
target=r[11];
r[16]=0x0c08edf8u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08edf8u) { target=s->pc; goto dispatch; }
goto P_0c08edf8;
P_0c08edf6: /* original 0009, guest PC 0x0c08edf6 */
if(!s->budget--) { s->failed_pc=0x0c08edf6u; return 0; }
goto P_0c08edf8;
P_0c08edf8: /* original 908a, guest PC 0x0c08edf8 */
if(!s->budget--) { s->failed_pc=0x0c08edf8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08ef10u,2);
goto P_0c08edfa;
P_0c08edfa: /* original f4e6, guest PC 0x0c08edfa */
if(!s->budget--) { s->failed_pc=0x0c08edfau; return 0; }
vf3_matrix_load(s,ram,4,r[14]+r[0]);
goto P_0c08edfc;
P_0c08edfc: /* original 7004, guest PC 0x0c08edfc */
if(!s->budget--) { s->failed_pc=0x0c08edfcu; return 0; }
r[0]+=0x00000004u;
goto P_0c08edfe;
P_0c08edfe: /* original f3e6, guest PC 0x0c08edfe */
if(!s->budget--) { s->failed_pc=0x0c08edfeu; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c08ee00;
P_0c08ee00: /* original ff3a, guest PC 0x0c08ee00 */
if(!s->budget--) { s->failed_pc=0x0c08ee00u; return 0; }
vf3_matrix_store(s,ram,3,r[15]);
goto P_0c08ee02;
P_0c08ee02: /* original 9086, guest PC 0x0c08ee02 */
if(!s->budget--) { s->failed_pc=0x0c08ee02u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08ef12u,2);
goto P_0c08ee04;
P_0c08ee04: /* original f3e6, guest PC 0x0c08ee04 */
if(!s->budget--) { s->failed_pc=0x0c08ee04u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c08ee06;
P_0c08ee06: /* original e014, guest PC 0x0c08ee06 */
if(!s->budget--) { s->failed_pc=0x0c08ee06u; return 0; }
r[0]=0x00000014u;
goto P_0c08ee08;
P_0c08ee08: /* original ff37, guest PC 0x0c08ee08 */
if(!s->budget--) { s->failed_pc=0x0c08ee08u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c08ee0a;
P_0c08ee0a: /* original f63c, guest PC 0x0c08ee0a */
if(!s->budget--) { s->failed_pc=0x0c08ee0au; return 0; }
vf3_matrix_move(s,6,3);
goto P_0c08ee0c;
P_0c08ee0c: /* original f64d, guest PC 0x0c08ee0c */
if(!s->budget--) { s->failed_pc=0x0c08ee0cu; return 0; }
fr[6]^=0x80000000u;
goto P_0c08ee0e;
P_0c08ee0e: /* original 4d0b, guest PC 0x0c08ee0e */
if(!s->budget--) { s->failed_pc=0x0c08ee0eu; return 0; }
target=r[13];
r[16]=0x0c08ee12u;
vf3_matrix_load(s,ram,5,r[15]);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08ee12u) { target=s->pc; goto dispatch; }
goto P_0c08ee12;
P_0c08ee10: /* original f5f8, guest PC 0x0c08ee10 */
if(!s->budget--) { s->failed_pc=0x0c08ee10u; return 0; }
vf3_matrix_load(s,ram,5,r[15]);
goto P_0c08ee12;
P_0c08ee12: /* original 907f, guest PC 0x0c08ee12 */
if(!s->budget--) { s->failed_pc=0x0c08ee12u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08ef14u,2);
goto P_0c08ee14;
P_0c08ee14: /* original f6e6, guest PC 0x0c08ee14 */
if(!s->budget--) { s->failed_pc=0x0c08ee14u; return 0; }
vf3_matrix_load(s,ram,6,r[14]+r[0]);
goto P_0c08ee16;
P_0c08ee16: /* original 70fc, guest PC 0x0c08ee16 */
if(!s->budget--) { s->failed_pc=0x0c08ee16u; return 0; }
r[0]+=0xfffffffcu;
goto P_0c08ee18;
P_0c08ee18: /* original f5e6, guest PC 0x0c08ee18 */
if(!s->budget--) { s->failed_pc=0x0c08ee18u; return 0; }
vf3_matrix_load(s,ram,5,r[14]+r[0]);
goto P_0c08ee1a;
P_0c08ee1a: /* original 70fc, guest PC 0x0c08ee1a */
if(!s->budget--) { s->failed_pc=0x0c08ee1au; return 0; }
r[0]+=0xfffffffcu;
goto P_0c08ee1c;
P_0c08ee1c: /* original f4e6, guest PC 0x0c08ee1c */
if(!s->budget--) { s->failed_pc=0x0c08ee1cu; return 0; }
vf3_matrix_load(s,ram,4,r[14]+r[0]);
goto P_0c08ee1e;
P_0c08ee1e: /* original 4c0b, guest PC 0x0c08ee1e */
if(!s->budget--) { s->failed_pc=0x0c08ee1eu; return 0; }
target=r[12];
r[16]=0x0c08ee22u;
r[4]=r[15];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08ee22u) { target=s->pc; goto dispatch; }
goto P_0c08ee22;
P_0c08ee20: /* original 64f3, guest PC 0x0c08ee20 */
if(!s->budget--) { s->failed_pc=0x0c08ee20u; return 0; }
r[4]=r[15];
goto P_0c08ee22;
P_0c08ee22: /* original fe0c, guest PC 0x0c08ee22 */
if(!s->budget--) { s->failed_pc=0x0c08ee22u; return 0; }
vf3_matrix_move(s,14,0);
goto P_0c08ee24;
P_0c08ee24: /* original fef2, guest PC 0x0c08ee24 */
if(!s->budget--) { s->failed_pc=0x0c08ee24u; return 0; }
fr[14]=vf3_fpu_binary(fr[14],fr[15],r[18],'*');
goto P_0c08ee26;
P_0c08ee26: /* original f5ec, guest PC 0x0c08ee26 */
if(!s->budget--) { s->failed_pc=0x0c08ee26u; return 0; }
vf3_matrix_move(s,5,14);
goto P_0c08ee28;
P_0c08ee28: /* original f6ec, guest PC 0x0c08ee28 */
if(!s->budget--) { s->failed_pc=0x0c08ee28u; return 0; }
vf3_matrix_move(s,6,14);
goto P_0c08ee2a;
P_0c08ee2a: /* original 4a0b, guest PC 0x0c08ee2a */
if(!s->budget--) { s->failed_pc=0x0c08ee2au; return 0; }
target=r[10];
r[16]=0x0c08ee2eu;
vf3_matrix_move(s,4,14);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08ee2eu) { target=s->pc; goto dispatch; }
goto P_0c08ee2e;
P_0c08ee2c: /* original f4ec, guest PC 0x0c08ee2c */
if(!s->budget--) { s->failed_pc=0x0c08ee2cu; return 0; }
vf3_matrix_move(s,4,14);
goto P_0c08ee2e;
P_0c08ee2e: /* original 9472, guest PC 0x0c08ee2e */
if(!s->budget--) { s->failed_pc=0x0c08ee2eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08ef16u,2);
goto P_0c08ee30;
P_0c08ee30: /* original d942, guest PC 0x0c08ee30 */
if(!s->budget--) { s->failed_pc=0x0c08ee30u; return 0; }
r[9]=read(ram,0x0c08ef3cu,4);
goto P_0c08ee32;
P_0c08ee32: /* original 490b, guest PC 0x0c08ee32 */
if(!s->budget--) { s->failed_pc=0x0c08ee32u; return 0; }
target=r[9];
r[16]=0x0c08ee36u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08ee36u) { target=s->pc; goto dispatch; }
goto P_0c08ee36;
P_0c08ee34: /* original 0009, guest PC 0x0c08ee34 */
if(!s->budget--) { s->failed_pc=0x0c08ee34u; return 0; }
goto P_0c08ee36;
P_0c08ee36: /* original 4b0b, guest PC 0x0c08ee36 */
if(!s->budget--) { s->failed_pc=0x0c08ee36u; return 0; }
target=r[11];
r[16]=0x0c08ee3au;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08ee3au) { target=s->pc; goto dispatch; }
goto P_0c08ee3a;
P_0c08ee38: /* original 0009, guest PC 0x0c08ee38 */
if(!s->budget--) { s->failed_pc=0x0c08ee38u; return 0; }
goto P_0c08ee3a;
P_0c08ee3a: /* original d341, guest PC 0x0c08ee3a */
if(!s->budget--) { s->failed_pc=0x0c08ee3au; return 0; }
r[3]=read(ram,0x0c08ef40u,4);
goto P_0c08ee3c;
P_0c08ee3c: /* original 85ef, guest PC 0x0c08ee3c */
if(!s->budget--) { s->failed_pc=0x0c08ee3cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+30,2);
goto P_0c08ee3e;
P_0c08ee3e: /* original 430b, guest PC 0x0c08ee3e */
if(!s->budget--) { s->failed_pc=0x0c08ee3eu; return 0; }
target=r[3];
r[16]=0x0c08ee42u;
r[4]=r[0];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08ee42u) { target=s->pc; goto dispatch; }
goto P_0c08ee42;
P_0c08ee40: /* original 6403, guest PC 0x0c08ee40 */
if(!s->budget--) { s->failed_pc=0x0c08ee40u; return 0; }
r[4]=r[0];
goto P_0c08ee42;
P_0c08ee42: /* original d340, guest PC 0x0c08ee42 */
if(!s->budget--) { s->failed_pc=0x0c08ee42u; return 0; }
r[3]=read(ram,0x0c08ef44u,4);
goto P_0c08ee44;
P_0c08ee44: /* original 85ee, guest PC 0x0c08ee44 */
if(!s->budget--) { s->failed_pc=0x0c08ee44u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+28,2);
goto P_0c08ee46;
P_0c08ee46: /* original 430b, guest PC 0x0c08ee46 */
if(!s->budget--) { s->failed_pc=0x0c08ee46u; return 0; }
target=r[3];
r[16]=0x0c08ee4au;
r[4]=r[0];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08ee4au) { target=s->pc; goto dispatch; }
goto P_0c08ee4a;
P_0c08ee48: /* original 6403, guest PC 0x0c08ee48 */
if(!s->budget--) { s->failed_pc=0x0c08ee48u; return 0; }
r[4]=r[0];
goto P_0c08ee4a;
P_0c08ee4a: /* original e00c, guest PC 0x0c08ee4a */
if(!s->budget--) { s->failed_pc=0x0c08ee4au; return 0; }
r[0]=0x0000000cu;
goto P_0c08ee4c;
P_0c08ee4c: /* original f4f6, guest PC 0x0c08ee4c */
if(!s->budget--) { s->failed_pc=0x0c08ee4cu; return 0; }
vf3_matrix_load(s,ram,4,r[15]+r[0]);
goto P_0c08ee4e;
P_0c08ee4e: /* original e008, guest PC 0x0c08ee4e */
if(!s->budget--) { s->failed_pc=0x0c08ee4eu; return 0; }
r[0]=0x00000008u;
goto P_0c08ee50;
P_0c08ee50: /* original f3f6, guest PC 0x0c08ee50 */
if(!s->budget--) { s->failed_pc=0x0c08ee50u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c08ee52;
P_0c08ee52: /* original e004, guest PC 0x0c08ee52 */
if(!s->budget--) { s->failed_pc=0x0c08ee52u; return 0; }
r[0]=0x00000004u;
goto P_0c08ee54;
P_0c08ee54: /* original ff3a, guest PC 0x0c08ee54 */
if(!s->budget--) { s->failed_pc=0x0c08ee54u; return 0; }
vf3_matrix_store(s,ram,3,r[15]);
goto P_0c08ee56;
P_0c08ee56: /* original f3f6, guest PC 0x0c08ee56 */
if(!s->budget--) { s->failed_pc=0x0c08ee56u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c08ee58;
P_0c08ee58: /* original e018, guest PC 0x0c08ee58 */
if(!s->budget--) { s->failed_pc=0x0c08ee58u; return 0; }
r[0]=0x00000018u;
goto P_0c08ee5a;
P_0c08ee5a: /* original ff37, guest PC 0x0c08ee5a */
if(!s->budget--) { s->failed_pc=0x0c08ee5au; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c08ee5c;
P_0c08ee5c: /* original f63c, guest PC 0x0c08ee5c */
if(!s->budget--) { s->failed_pc=0x0c08ee5cu; return 0; }
vf3_matrix_move(s,6,3);
goto P_0c08ee5e;
P_0c08ee5e: /* original f64d, guest PC 0x0c08ee5e */
if(!s->budget--) { s->failed_pc=0x0c08ee5eu; return 0; }
fr[6]^=0x80000000u;
goto P_0c08ee60;
P_0c08ee60: /* original 4d0b, guest PC 0x0c08ee60 */
if(!s->budget--) { s->failed_pc=0x0c08ee60u; return 0; }
target=r[13];
r[16]=0x0c08ee64u;
vf3_matrix_load(s,ram,5,r[15]);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08ee64u) { target=s->pc; goto dispatch; }
goto P_0c08ee64;
P_0c08ee62: /* original f5f8, guest PC 0x0c08ee62 */
if(!s->budget--) { s->failed_pc=0x0c08ee62u; return 0; }
vf3_matrix_load(s,ram,5,r[15]);
goto P_0c08ee64;
P_0c08ee64: /* original d337, guest PC 0x0c08ee64 */
if(!s->budget--) { s->failed_pc=0x0c08ee64u; return 0; }
r[3]=read(ram,0x0c08ef44u,4);
goto P_0c08ee66;
P_0c08ee66: /* original 85ee, guest PC 0x0c08ee66 */
if(!s->budget--) { s->failed_pc=0x0c08ee66u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+28,2);
goto P_0c08ee68;
P_0c08ee68: /* original 430b, guest PC 0x0c08ee68 */
if(!s->budget--) { s->failed_pc=0x0c08ee68u; return 0; }
target=r[3];
r[16]=0x0c08ee6cu;
r[4]=0u-r[0];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08ee6cu) { target=s->pc; goto dispatch; }
goto P_0c08ee6c;
P_0c08ee6a: /* original 640b, guest PC 0x0c08ee6a */
if(!s->budget--) { s->failed_pc=0x0c08ee6au; return 0; }
r[4]=0u-r[0];
goto P_0c08ee6c;
P_0c08ee6c: /* original d334, guest PC 0x0c08ee6c */
if(!s->budget--) { s->failed_pc=0x0c08ee6cu; return 0; }
r[3]=read(ram,0x0c08ef40u,4);
goto P_0c08ee6e;
P_0c08ee6e: /* original 85ef, guest PC 0x0c08ee6e */
if(!s->budget--) { s->failed_pc=0x0c08ee6eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+30,2);
goto P_0c08ee70;
P_0c08ee70: /* original 430b, guest PC 0x0c08ee70 */
if(!s->budget--) { s->failed_pc=0x0c08ee70u; return 0; }
target=r[3];
r[16]=0x0c08ee74u;
r[4]=0u-r[0];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08ee74u) { target=s->pc; goto dispatch; }
goto P_0c08ee74;
P_0c08ee72: /* original 640b, guest PC 0x0c08ee72 */
if(!s->budget--) { s->failed_pc=0x0c08ee72u; return 0; }
r[4]=0u-r[0];
goto P_0c08ee74;
P_0c08ee74: /* original 9050, guest PC 0x0c08ee74 */
if(!s->budget--) { s->failed_pc=0x0c08ee74u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08ef18u,2);
goto P_0c08ee76;
P_0c08ee76: /* original f6e6, guest PC 0x0c08ee76 */
if(!s->budget--) { s->failed_pc=0x0c08ee76u; return 0; }
vf3_matrix_load(s,ram,6,r[14]+r[0]);
goto P_0c08ee78;
P_0c08ee78: /* original 70fc, guest PC 0x0c08ee78 */
if(!s->budget--) { s->failed_pc=0x0c08ee78u; return 0; }
r[0]+=0xfffffffcu;
goto P_0c08ee7a;
P_0c08ee7a: /* original f5e6, guest PC 0x0c08ee7a */
if(!s->budget--) { s->failed_pc=0x0c08ee7au; return 0; }
vf3_matrix_load(s,ram,5,r[14]+r[0]);
goto P_0c08ee7c;
P_0c08ee7c: /* original 70fc, guest PC 0x0c08ee7c */
if(!s->budget--) { s->failed_pc=0x0c08ee7cu; return 0; }
r[0]+=0xfffffffcu;
goto P_0c08ee7e;
P_0c08ee7e: /* original f64d, guest PC 0x0c08ee7e */
if(!s->budget--) { s->failed_pc=0x0c08ee7eu; return 0; }
fr[6]^=0x80000000u;
goto P_0c08ee80;
P_0c08ee80: /* original 4d0b, guest PC 0x0c08ee80 */
if(!s->budget--) { s->failed_pc=0x0c08ee80u; return 0; }
target=r[13];
r[16]=0x0c08ee84u;
vf3_matrix_load(s,ram,4,r[14]+r[0]);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08ee84u) { target=s->pc; goto dispatch; }
goto P_0c08ee84;
P_0c08ee82: /* original f4e6, guest PC 0x0c08ee82 */
if(!s->budget--) { s->failed_pc=0x0c08ee82u; return 0; }
vf3_matrix_load(s,ram,4,r[14]+r[0]);
goto P_0c08ee84;
P_0c08ee84: /* original 9049, guest PC 0x0c08ee84 */
if(!s->budget--) { s->failed_pc=0x0c08ee84u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08ef1au,2);
goto P_0c08ee86;
P_0c08ee86: /* original f6e6, guest PC 0x0c08ee86 */
if(!s->budget--) { s->failed_pc=0x0c08ee86u; return 0; }
vf3_matrix_load(s,ram,6,r[14]+r[0]);
goto P_0c08ee88;
P_0c08ee88: /* original 70fc, guest PC 0x0c08ee88 */
if(!s->budget--) { s->failed_pc=0x0c08ee88u; return 0; }
r[0]+=0xfffffffcu;
goto P_0c08ee8a;
P_0c08ee8a: /* original f5e6, guest PC 0x0c08ee8a */
if(!s->budget--) { s->failed_pc=0x0c08ee8au; return 0; }
vf3_matrix_load(s,ram,5,r[14]+r[0]);
goto P_0c08ee8c;
P_0c08ee8c: /* original 70fc, guest PC 0x0c08ee8c */
if(!s->budget--) { s->failed_pc=0x0c08ee8cu; return 0; }
r[0]+=0xfffffffcu;
goto P_0c08ee8e;
P_0c08ee8e: /* original f4e6, guest PC 0x0c08ee8e */
if(!s->budget--) { s->failed_pc=0x0c08ee8eu; return 0; }
vf3_matrix_load(s,ram,4,r[14]+r[0]);
goto P_0c08ee90;
P_0c08ee90: /* original 4c0b, guest PC 0x0c08ee90 */
if(!s->budget--) { s->failed_pc=0x0c08ee90u; return 0; }
target=r[12];
r[16]=0x0c08ee94u;
r[4]=r[15];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08ee94u) { target=s->pc; goto dispatch; }
goto P_0c08ee94;
P_0c08ee92: /* original 64f3, guest PC 0x0c08ee92 */
if(!s->budget--) { s->failed_pc=0x0c08ee92u; return 0; }
r[4]=r[15];
goto P_0c08ee94;
P_0c08ee94: /* original fe0c, guest PC 0x0c08ee94 */
if(!s->budget--) { s->failed_pc=0x0c08ee94u; return 0; }
vf3_matrix_move(s,14,0);
goto P_0c08ee96;
P_0c08ee96: /* original fef2, guest PC 0x0c08ee96 */
if(!s->budget--) { s->failed_pc=0x0c08ee96u; return 0; }
fr[14]=vf3_fpu_binary(fr[14],fr[15],r[18],'*');
goto P_0c08ee98;
P_0c08ee98: /* original f5ec, guest PC 0x0c08ee98 */
if(!s->budget--) { s->failed_pc=0x0c08ee98u; return 0; }
vf3_matrix_move(s,5,14);
goto P_0c08ee9a;
P_0c08ee9a: /* original f6ec, guest PC 0x0c08ee9a */
if(!s->budget--) { s->failed_pc=0x0c08ee9au; return 0; }
vf3_matrix_move(s,6,14);
goto P_0c08ee9c;
P_0c08ee9c: /* original 4a0b, guest PC 0x0c08ee9c */
if(!s->budget--) { s->failed_pc=0x0c08ee9cu; return 0; }
target=r[10];
r[16]=0x0c08eea0u;
vf3_matrix_move(s,4,14);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08eea0u) { target=s->pc; goto dispatch; }
goto P_0c08eea0;
P_0c08ee9e: /* original f4ec, guest PC 0x0c08ee9e */
if(!s->budget--) { s->failed_pc=0x0c08ee9eu; return 0; }
vf3_matrix_move(s,4,14);
goto P_0c08eea0;
P_0c08eea0: /* original 943c, guest PC 0x0c08eea0 */
if(!s->budget--) { s->failed_pc=0x0c08eea0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08ef1cu,2);
goto P_0c08eea2;
P_0c08eea2: /* original 490b, guest PC 0x0c08eea2 */
if(!s->budget--) { s->failed_pc=0x0c08eea2u; return 0; }
target=r[9];
r[16]=0x0c08eea6u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08eea6u) { target=s->pc; goto dispatch; }
goto P_0c08eea6;
P_0c08eea4: /* original 0009, guest PC 0x0c08eea4 */
if(!s->budget--) { s->failed_pc=0x0c08eea4u; return 0; }
goto P_0c08eea6;
P_0c08eea6: /* original 4b0b, guest PC 0x0c08eea6 */
if(!s->budget--) { s->failed_pc=0x0c08eea6u; return 0; }
target=r[11];
r[16]=0x0c08eeaau;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08eeaau) { target=s->pc; goto dispatch; }
goto P_0c08eeaa;
P_0c08eea8: /* original 0009, guest PC 0x0c08eea8 */
if(!s->budget--) { s->failed_pc=0x0c08eea8u; return 0; }
goto P_0c08eeaa;
P_0c08eeaa: /* original 9038, guest PC 0x0c08eeaa */
if(!s->budget--) { s->failed_pc=0x0c08eeaau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08ef1eu,2);
goto P_0c08eeac;
P_0c08eeac: /* original f6e6, guest PC 0x0c08eeac */
if(!s->budget--) { s->failed_pc=0x0c08eeacu; return 0; }
vf3_matrix_load(s,ram,6,r[14]+r[0]);
goto P_0c08eeae;
P_0c08eeae: /* original 70fc, guest PC 0x0c08eeae */
if(!s->budget--) { s->failed_pc=0x0c08eeaeu; return 0; }
r[0]+=0xfffffffcu;
goto P_0c08eeb0;
P_0c08eeb0: /* original f5e6, guest PC 0x0c08eeb0 */
if(!s->budget--) { s->failed_pc=0x0c08eeb0u; return 0; }
vf3_matrix_load(s,ram,5,r[14]+r[0]);
goto P_0c08eeb2;
P_0c08eeb2: /* original 70fc, guest PC 0x0c08eeb2 */
if(!s->budget--) { s->failed_pc=0x0c08eeb2u; return 0; }
r[0]+=0xfffffffcu;
goto P_0c08eeb4;
P_0c08eeb4: /* original f64d, guest PC 0x0c08eeb4 */
if(!s->budget--) { s->failed_pc=0x0c08eeb4u; return 0; }
fr[6]^=0x80000000u;
goto P_0c08eeb6;
P_0c08eeb6: /* original 4d0b, guest PC 0x0c08eeb6 */
if(!s->budget--) { s->failed_pc=0x0c08eeb6u; return 0; }
target=r[13];
r[16]=0x0c08eebau;
vf3_matrix_load(s,ram,4,r[14]+r[0]);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08eebau) { target=s->pc; goto dispatch; }
goto P_0c08eeba;
P_0c08eeb8: /* original f4e6, guest PC 0x0c08eeb8 */
if(!s->budget--) { s->failed_pc=0x0c08eeb8u; return 0; }
vf3_matrix_load(s,ram,4,r[14]+r[0]);
goto P_0c08eeba;
P_0c08eeba: /* original 9031, guest PC 0x0c08eeba */
if(!s->budget--) { s->failed_pc=0x0c08eebau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08ef20u,2);
goto P_0c08eebc;
P_0c08eebc: /* original f6e6, guest PC 0x0c08eebc */
if(!s->budget--) { s->failed_pc=0x0c08eebcu; return 0; }
vf3_matrix_load(s,ram,6,r[14]+r[0]);
goto P_0c08eebe;
P_0c08eebe: /* original 70fc, guest PC 0x0c08eebe */
if(!s->budget--) { s->failed_pc=0x0c08eebeu; return 0; }
r[0]+=0xfffffffcu;
goto P_0c08eec0;
P_0c08eec0: /* original f5e6, guest PC 0x0c08eec0 */
if(!s->budget--) { s->failed_pc=0x0c08eec0u; return 0; }
vf3_matrix_load(s,ram,5,r[14]+r[0]);
goto P_0c08eec2;
P_0c08eec2: /* original 70fc, guest PC 0x0c08eec2 */
if(!s->budget--) { s->failed_pc=0x0c08eec2u; return 0; }
r[0]+=0xfffffffcu;
goto P_0c08eec4;
P_0c08eec4: /* original f4e6, guest PC 0x0c08eec4 */
if(!s->budget--) { s->failed_pc=0x0c08eec4u; return 0; }
vf3_matrix_load(s,ram,4,r[14]+r[0]);
goto P_0c08eec6;
P_0c08eec6: /* original 4c0b, guest PC 0x0c08eec6 */
if(!s->budget--) { s->failed_pc=0x0c08eec6u; return 0; }
target=r[12];
r[16]=0x0c08eecau;
r[4]=r[15];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08eecau) { target=s->pc; goto dispatch; }
goto P_0c08eeca;
P_0c08eec8: /* original 64f3, guest PC 0x0c08eec8 */
if(!s->budget--) { s->failed_pc=0x0c08eec8u; return 0; }
r[4]=r[15];
goto P_0c08eeca;
P_0c08eeca: /* original f3fc, guest PC 0x0c08eeca */
if(!s->budget--) { s->failed_pc=0x0c08eecau; return 0; }
vf3_matrix_move(s,3,15);
goto P_0c08eecc;
P_0c08eecc: /* original ff0c, guest PC 0x0c08eecc */
if(!s->budget--) { s->failed_pc=0x0c08eeccu; return 0; }
vf3_matrix_move(s,15,0);
goto P_0c08eece;
P_0c08eece: /* original ff32, guest PC 0x0c08eece */
if(!s->budget--) { s->failed_pc=0x0c08eeceu; return 0; }
fr[15]=vf3_fpu_binary(fr[15],fr[3],r[18],'*');
goto P_0c08eed0;
P_0c08eed0: /* original f5fc, guest PC 0x0c08eed0 */
if(!s->budget--) { s->failed_pc=0x0c08eed0u; return 0; }
vf3_matrix_move(s,5,15);
goto P_0c08eed2;
P_0c08eed2: /* original f6fc, guest PC 0x0c08eed2 */
if(!s->budget--) { s->failed_pc=0x0c08eed2u; return 0; }
vf3_matrix_move(s,6,15);
goto P_0c08eed4;
P_0c08eed4: /* original 4a0b, guest PC 0x0c08eed4 */
if(!s->budget--) { s->failed_pc=0x0c08eed4u; return 0; }
target=r[10];
r[16]=0x0c08eed8u;
vf3_matrix_move(s,4,15);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08eed8u) { target=s->pc; goto dispatch; }
goto P_0c08eed8;
P_0c08eed6: /* original f4fc, guest PC 0x0c08eed6 */
if(!s->budget--) { s->failed_pc=0x0c08eed6u; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c08eed8;
P_0c08eed8: /* original 9423, guest PC 0x0c08eed8 */
if(!s->budget--) { s->failed_pc=0x0c08eed8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08ef22u,2);
goto P_0c08eeda;
P_0c08eeda: /* original 490b, guest PC 0x0c08eeda */
if(!s->budget--) { s->failed_pc=0x0c08eedau; return 0; }
target=r[9];
r[16]=0x0c08eedeu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08eedeu) { target=s->pc; goto dispatch; }
goto P_0c08eede;
P_0c08eedc: /* original 0009, guest PC 0x0c08eedc */
if(!s->budget--) { s->failed_pc=0x0c08eedcu; return 0; }
goto P_0c08eede;
P_0c08eede: /* original d31a, guest PC 0x0c08eede */
if(!s->budget--) { s->failed_pc=0x0c08eedeu; return 0; }
r[3]=read(ram,0x0c08ef48u,4);
goto P_0c08eee0;
P_0c08eee0: /* original 430b, guest PC 0x0c08eee0 */
if(!s->budget--) { s->failed_pc=0x0c08eee0u; return 0; }
target=r[3];
r[16]=0x0c08eee4u;
r[4]=0x00000001u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08eee4u) { target=s->pc; goto dispatch; }
goto P_0c08eee4;
P_0c08eee2: /* original e401, guest PC 0x0c08eee2 */
if(!s->budget--) { s->failed_pc=0x0c08eee2u; return 0; }
r[4]=0x00000001u;
goto P_0c08eee4;
P_0c08eee4: /* original e004, guest PC 0x0c08eee4 */
if(!s->budget--) { s->failed_pc=0x0c08eee4u; return 0; }
r[0]=0x00000004u;
goto P_0c08eee6;
P_0c08eee6: /* original f6f6, guest PC 0x0c08eee6 */
if(!s->budget--) { s->failed_pc=0x0c08eee6u; return 0; }
vf3_matrix_load(s,ram,6,r[15]+r[0]);
goto P_0c08eee8;
P_0c08eee8: /* original e008, guest PC 0x0c08eee8 */
if(!s->budget--) { s->failed_pc=0x0c08eee8u; return 0; }
r[0]=0x00000008u;
goto P_0c08eeea;
P_0c08eeea: /* original f5f6, guest PC 0x0c08eeea */
if(!s->budget--) { s->failed_pc=0x0c08eeeau; return 0; }
vf3_matrix_load(s,ram,5,r[15]+r[0]);
goto P_0c08eeec;
P_0c08eeec: /* original e00c, guest PC 0x0c08eeec */
if(!s->budget--) { s->failed_pc=0x0c08eeecu; return 0; }
r[0]=0x0000000cu;
goto P_0c08eeee;
P_0c08eeee: /* original f4f6, guest PC 0x0c08eeee */
if(!s->budget--) { s->failed_pc=0x0c08eeeeu; return 0; }
vf3_matrix_load(s,ram,4,r[15]+r[0]);
goto P_0c08eef0;
P_0c08eef0: /* original b02c, guest PC 0x0c08eef0 */
if(!s->budget--) { s->failed_pc=0x0c08eef0u; return 0; }
target=0x0c08ef4cu; r[16]=0x0c08eef4u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08eef4u) { target=s->pc; goto dispatch; }
goto P_0c08eef4;
P_0c08eef2: /* original 64e3, guest PC 0x0c08eef2 */
if(!s->budget--) { s->failed_pc=0x0c08eef2u; return 0; }
r[4]=r[14];
goto P_0c08eef4;
P_0c08eef4: /* original 7f1c, guest PC 0x0c08eef4 */
if(!s->budget--) { s->failed_pc=0x0c08eef4u; return 0; }
r[15]+=0x0000001cu;
goto P_0c08eef6;
P_0c08eef6: /* original 4f26, guest PC 0x0c08eef6 */
if(!s->budget--) { s->failed_pc=0x0c08eef6u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c08eef8;
P_0c08eef8: /* original fef9, guest PC 0x0c08eef8 */
if(!s->budget--) { s->failed_pc=0x0c08eef8u; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c08eefa;
P_0c08eefa: /* original fff9, guest PC 0x0c08eefa */
if(!s->budget--) { s->failed_pc=0x0c08eefau; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c08eefc;
P_0c08eefc: /* original 69f6, guest PC 0x0c08eefc */
if(!s->budget--) { s->failed_pc=0x0c08eefcu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c08eefe;
P_0c08eefe: /* original 6af6, guest PC 0x0c08eefe */
if(!s->budget--) { s->failed_pc=0x0c08eefeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c08ef00;
P_0c08ef00: /* original 6bf6, guest PC 0x0c08ef00 */
if(!s->budget--) { s->failed_pc=0x0c08ef00u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c08ef02;
P_0c08ef02: /* original 6cf6, guest PC 0x0c08ef02 */
if(!s->budget--) { s->failed_pc=0x0c08ef02u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c08ef04;
P_0c08ef04: /* original 6df6, guest PC 0x0c08ef04 */
if(!s->budget--) { s->failed_pc=0x0c08ef04u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c08ef06;
P_0c08ef06: /* original 000b, guest PC 0x0c08ef06 */
if(!s->budget--) { s->failed_pc=0x0c08ef06u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c08ef08: /* original 6ef6, guest PC 0x0c08ef08 */
if(!s->budget--) { s->failed_pc=0x0c08ef08u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c08ef0au,s,ram);
P_0c08ef62: /* original 4f22, guest PC 0x0c08ef62 */
if(!s->budget--) { s->failed_pc=0x0c08ef62u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c08ef64;
P_0c08ef64: /* original 7fdc, guest PC 0x0c08ef64 */
if(!s->budget--) { s->failed_pc=0x0c08ef64u; return 0; }
r[15]+=0xffffffdcu;
goto P_0c08ef66;
P_0c08ef66: /* original ff47, guest PC 0x0c08ef66 */
if(!s->budget--) { s->failed_pc=0x0c08ef66u; return 0; }
vf3_matrix_store(s,ram,4,r[15]+r[0]);
goto P_0c08ef68;
P_0c08ef68: /* original e008, guest PC 0x0c08ef68 */
if(!s->budget--) { s->failed_pc=0x0c08ef68u; return 0; }
r[0]=0x00000008u;
goto P_0c08ef6a;
P_0c08ef6a: /* original ff5a, guest PC 0x0c08ef6a */
if(!s->budget--) { s->failed_pc=0x0c08ef6au; return 0; }
vf3_matrix_store(s,ram,5,r[15]);
goto P_0c08ef6c;
P_0c08ef6c: /* original ff67, guest PC 0x0c08ef6c */
if(!s->budget--) { s->failed_pc=0x0c08ef6cu; return 0; }
vf3_matrix_store(s,ram,6,r[15]+r[0]);
goto P_0c08ef6e;
P_0c08ef6e: /* original d361, guest PC 0x0c08ef6e */
if(!s->budget--) { s->failed_pc=0x0c08ef6eu; return 0; }
r[3]=read(ram,0x0c08f0f4u,4);
goto P_0c08ef70;
P_0c08ef70: /* original 430b, guest PC 0x0c08ef70 */
if(!s->budget--) { s->failed_pc=0x0c08ef70u; return 0; }
target=r[3];
r[16]=0x0c08ef74u;
r[4]=0x00000000u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08ef74u) { target=s->pc; goto dispatch; }
goto P_0c08ef74;
P_0c08ef72: /* original e400, guest PC 0x0c08ef72 */
if(!s->budget--) { s->failed_pc=0x0c08ef72u; return 0; }
r[4]=0x00000000u;
goto P_0c08ef74;
P_0c08ef74: /* original da61, guest PC 0x0c08ef74 */
if(!s->budget--) { s->failed_pc=0x0c08ef74u; return 0; }
r[10]=read(ram,0x0c08f0fcu,4);
goto P_0c08ef76;
P_0c08ef76: /* original c760, guest PC 0x0c08ef76 */
if(!s->budget--) { s->failed_pc=0x0c08ef76u; return 0; }
r[0]=0x0c08f0f8u;
goto P_0c08ef78;
P_0c08ef78: /* original 4a0b, guest PC 0x0c08ef78 */
if(!s->budget--) { s->failed_pc=0x0c08ef78u; return 0; }
target=r[10];
r[16]=0x0c08ef7cu;
vf3_matrix_load(s,ram,15,r[0]);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08ef7cu) { target=s->pc; goto dispatch; }
goto P_0c08ef7c;
P_0c08ef7a: /* original ff08, guest PC 0x0c08ef7a */
if(!s->budget--) { s->failed_pc=0x0c08ef7au; return 0; }
vf3_matrix_load(s,ram,15,r[0]);
goto P_0c08ef7c;
P_0c08ef7c: /* original e07c, guest PC 0x0c08ef7c */
if(!s->budget--) { s->failed_pc=0x0c08ef7cu; return 0; }
r[0]=0x0000007cu;
goto P_0c08ef7e;
P_0c08ef7e: /* original f4e6, guest PC 0x0c08ef7e */
if(!s->budget--) { s->failed_pc=0x0c08ef7eu; return 0; }
vf3_matrix_load(s,ram,4,r[14]+r[0]);
goto P_0c08ef80;
P_0c08ef80: /* original 7004, guest PC 0x0c08ef80 */
if(!s->budget--) { s->failed_pc=0x0c08ef80u; return 0; }
r[0]+=0x00000004u;
goto P_0c08ef82;
P_0c08ef82: /* original f5e6, guest PC 0x0c08ef82 */
if(!s->budget--) { s->failed_pc=0x0c08ef82u; return 0; }
vf3_matrix_load(s,ram,5,r[14]+r[0]);
goto P_0c08ef84;
P_0c08ef84: /* original 7004, guest PC 0x0c08ef84 */
if(!s->budget--) { s->failed_pc=0x0c08ef84u; return 0; }
r[0]+=0x00000004u;
goto P_0c08ef86;
P_0c08ef86: /* original f3e6, guest PC 0x0c08ef86 */
if(!s->budget--) { s->failed_pc=0x0c08ef86u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c08ef88;
P_0c08ef88: /* original e01c, guest PC 0x0c08ef88 */
if(!s->budget--) { s->failed_pc=0x0c08ef88u; return 0; }
r[0]=0x0000001cu;
goto P_0c08ef8a;
P_0c08ef8a: /* original ff37, guest PC 0x0c08ef8a */
if(!s->budget--) { s->failed_pc=0x0c08ef8au; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c08ef8c;
P_0c08ef8c: /* original dd5c, guest PC 0x0c08ef8c */
if(!s->budget--) { s->failed_pc=0x0c08ef8cu; return 0; }
r[13]=read(ram,0x0c08f100u,4);
goto P_0c08ef8e;
P_0c08ef8e: /* original f63c, guest PC 0x0c08ef8e */
if(!s->budget--) { s->failed_pc=0x0c08ef8eu; return 0; }
vf3_matrix_move(s,6,3);
goto P_0c08ef90;
P_0c08ef90: /* original 4d0b, guest PC 0x0c08ef90 */
if(!s->budget--) { s->failed_pc=0x0c08ef90u; return 0; }
target=r[13];
r[16]=0x0c08ef94u;
fr[6]^=0x80000000u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08ef94u) { target=s->pc; goto dispatch; }
goto P_0c08ef94;
P_0c08ef92: /* original f64d, guest PC 0x0c08ef92 */
if(!s->budget--) { s->failed_pc=0x0c08ef92u; return 0; }
fr[6]^=0x80000000u;
goto P_0c08ef94;
P_0c08ef94: /* original dc5b, guest PC 0x0c08ef94 */
if(!s->budget--) { s->failed_pc=0x0c08ef94u; return 0; }
r[12]=read(ram,0x0c08f104u,4);
goto P_0c08ef96;
P_0c08ef96: /* original f5fc, guest PC 0x0c08ef96 */
if(!s->budget--) { s->failed_pc=0x0c08ef96u; return 0; }
vf3_matrix_move(s,5,15);
goto P_0c08ef98;
P_0c08ef98: /* original f6fc, guest PC 0x0c08ef98 */
if(!s->budget--) { s->failed_pc=0x0c08ef98u; return 0; }
vf3_matrix_move(s,6,15);
goto P_0c08ef9a;
P_0c08ef9a: /* original 4c0b, guest PC 0x0c08ef9a */
if(!s->budget--) { s->failed_pc=0x0c08ef9au; return 0; }
target=r[12];
r[16]=0x0c08ef9eu;
vf3_matrix_move(s,4,15);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08ef9eu) { target=s->pc; goto dispatch; }
goto P_0c08ef9e;
P_0c08ef9c: /* original f4fc, guest PC 0x0c08ef9c */
if(!s->budget--) { s->failed_pc=0x0c08ef9cu; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c08ef9e;
P_0c08ef9e: /* original db5a, guest PC 0x0c08ef9e */
if(!s->budget--) { s->failed_pc=0x0c08ef9eu; return 0; }
r[11]=read(ram,0x0c08f108u,4);
goto P_0c08efa0;
P_0c08efa0: /* original 99a1, guest PC 0x0c08efa0 */
if(!s->budget--) { s->failed_pc=0x0c08efa0u; return 0; }
r[9]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08f0e6u,2);
goto P_0c08efa2;
P_0c08efa2: /* original 4b0b, guest PC 0x0c08efa2 */
if(!s->budget--) { s->failed_pc=0x0c08efa2u; return 0; }
target=r[11];
r[16]=0x0c08efa6u;
r[4]=r[9];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08efa6u) { target=s->pc; goto dispatch; }
goto P_0c08efa6;
P_0c08efa4: /* original 6493, guest PC 0x0c08efa4 */
if(!s->budget--) { s->failed_pc=0x0c08efa4u; return 0; }
r[4]=r[9];
goto P_0c08efa6;
P_0c08efa6: /* original 4a0b, guest PC 0x0c08efa6 */
if(!s->budget--) { s->failed_pc=0x0c08efa6u; return 0; }
target=r[10];
r[16]=0x0c08efaau;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08efaau) { target=s->pc; goto dispatch; }
goto P_0c08efaa;
P_0c08efa8: /* original 0009, guest PC 0x0c08efa8 */
if(!s->budget--) { s->failed_pc=0x0c08efa8u; return 0; }
goto P_0c08efaa;
P_0c08efaa: /* original 909d, guest PC 0x0c08efaa */
if(!s->budget--) { s->failed_pc=0x0c08efaau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08f0e8u,2);
goto P_0c08efac;
P_0c08efac: /* original f4e6, guest PC 0x0c08efac */
if(!s->budget--) { s->failed_pc=0x0c08efacu; return 0; }
vf3_matrix_load(s,ram,4,r[14]+r[0]);
goto P_0c08efae;
P_0c08efae: /* original 7004, guest PC 0x0c08efae */
if(!s->budget--) { s->failed_pc=0x0c08efaeu; return 0; }
r[0]+=0x00000004u;
goto P_0c08efb0;
P_0c08efb0: /* original f5e6, guest PC 0x0c08efb0 */
if(!s->budget--) { s->failed_pc=0x0c08efb0u; return 0; }
vf3_matrix_load(s,ram,5,r[14]+r[0]);
goto P_0c08efb2;
P_0c08efb2: /* original 7004, guest PC 0x0c08efb2 */
if(!s->budget--) { s->failed_pc=0x0c08efb2u; return 0; }
r[0]+=0x00000004u;
goto P_0c08efb4;
P_0c08efb4: /* original f3e6, guest PC 0x0c08efb4 */
if(!s->budget--) { s->failed_pc=0x0c08efb4u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c08efb6;
P_0c08efb6: /* original e014, guest PC 0x0c08efb6 */
if(!s->budget--) { s->failed_pc=0x0c08efb6u; return 0; }
r[0]=0x00000014u;
goto P_0c08efb8;
P_0c08efb8: /* original ff37, guest PC 0x0c08efb8 */
if(!s->budget--) { s->failed_pc=0x0c08efb8u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c08efba;
P_0c08efba: /* original f63c, guest PC 0x0c08efba */
if(!s->budget--) { s->failed_pc=0x0c08efbau; return 0; }
vf3_matrix_move(s,6,3);
goto P_0c08efbc;
P_0c08efbc: /* original 4d0b, guest PC 0x0c08efbc */
if(!s->budget--) { s->failed_pc=0x0c08efbcu; return 0; }
target=r[13];
r[16]=0x0c08efc0u;
fr[6]^=0x80000000u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08efc0u) { target=s->pc; goto dispatch; }
goto P_0c08efc0;
P_0c08efbe: /* original f64d, guest PC 0x0c08efbe */
if(!s->budget--) { s->failed_pc=0x0c08efbeu; return 0; }
fr[6]^=0x80000000u;
goto P_0c08efc0;
P_0c08efc0: /* original f5fc, guest PC 0x0c08efc0 */
if(!s->budget--) { s->failed_pc=0x0c08efc0u; return 0; }
vf3_matrix_move(s,5,15);
goto P_0c08efc2;
P_0c08efc2: /* original f6fc, guest PC 0x0c08efc2 */
if(!s->budget--) { s->failed_pc=0x0c08efc2u; return 0; }
vf3_matrix_move(s,6,15);
goto P_0c08efc4;
P_0c08efc4: /* original 4c0b, guest PC 0x0c08efc4 */
if(!s->budget--) { s->failed_pc=0x0c08efc4u; return 0; }
target=r[12];
r[16]=0x0c08efc8u;
vf3_matrix_move(s,4,15);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08efc8u) { target=s->pc; goto dispatch; }
goto P_0c08efc8;
P_0c08efc6: /* original f4fc, guest PC 0x0c08efc6 */
if(!s->budget--) { s->failed_pc=0x0c08efc6u; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c08efc8;
P_0c08efc8: /* original 4b0b, guest PC 0x0c08efc8 */
if(!s->budget--) { s->failed_pc=0x0c08efc8u; return 0; }
target=r[11];
r[16]=0x0c08efccu;
r[4]=r[9];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08efccu) { target=s->pc; goto dispatch; }
goto P_0c08efcc;
P_0c08efca: /* original 6493, guest PC 0x0c08efca */
if(!s->budget--) { s->failed_pc=0x0c08efcau; return 0; }
r[4]=r[9];
goto P_0c08efcc;
P_0c08efcc: /* original 4a0b, guest PC 0x0c08efcc */
if(!s->budget--) { s->failed_pc=0x0c08efccu; return 0; }
target=r[10];
r[16]=0x0c08efd0u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08efd0u) { target=s->pc; goto dispatch; }
goto P_0c08efd0;
P_0c08efce: /* original 0009, guest PC 0x0c08efce */
if(!s->budget--) { s->failed_pc=0x0c08efceu; return 0; }
goto P_0c08efd0;
P_0c08efd0: /* original 85ef, guest PC 0x0c08efd0 */
if(!s->budget--) { s->failed_pc=0x0c08efd0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+30,2);
goto P_0c08efd2;
P_0c08efd2: /* original d84e, guest PC 0x0c08efd2 */
if(!s->budget--) { s->failed_pc=0x0c08efd2u; return 0; }
r[8]=read(ram,0x0c08f10cu,4);
goto P_0c08efd4;
P_0c08efd4: /* original 480b, guest PC 0x0c08efd4 */
if(!s->budget--) { s->failed_pc=0x0c08efd4u; return 0; }
target=r[8];
r[16]=0x0c08efd8u;
r[4]=r[0];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08efd8u) { target=s->pc; goto dispatch; }
goto P_0c08efd8;
P_0c08efd6: /* original 6403, guest PC 0x0c08efd6 */
if(!s->budget--) { s->failed_pc=0x0c08efd6u; return 0; }
r[4]=r[0];
goto P_0c08efd8;
P_0c08efd8: /* original d34d, guest PC 0x0c08efd8 */
if(!s->budget--) { s->failed_pc=0x0c08efd8u; return 0; }
r[3]=read(ram,0x0c08f110u,4);
goto P_0c08efda;
P_0c08efda: /* original 85ee, guest PC 0x0c08efda */
if(!s->budget--) { s->failed_pc=0x0c08efdau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+28,2);
goto P_0c08efdc;
P_0c08efdc: /* original 430b, guest PC 0x0c08efdc */
if(!s->budget--) { s->failed_pc=0x0c08efdcu; return 0; }
target=r[3];
r[16]=0x0c08efe0u;
r[4]=r[0];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08efe0u) { target=s->pc; goto dispatch; }
goto P_0c08efe0;
P_0c08efde: /* original 6403, guest PC 0x0c08efde */
if(!s->budget--) { s->failed_pc=0x0c08efdeu; return 0; }
r[4]=r[0];
goto P_0c08efe0;
P_0c08efe0: /* original e004, guest PC 0x0c08efe0 */
if(!s->budget--) { s->failed_pc=0x0c08efe0u; return 0; }
r[0]=0x00000004u;
goto P_0c08efe2;
P_0c08efe2: /* original f5f8, guest PC 0x0c08efe2 */
if(!s->budget--) { s->failed_pc=0x0c08efe2u; return 0; }
vf3_matrix_load(s,ram,5,r[15]);
goto P_0c08efe4;
P_0c08efe4: /* original f4f6, guest PC 0x0c08efe4 */
if(!s->budget--) { s->failed_pc=0x0c08efe4u; return 0; }
vf3_matrix_load(s,ram,4,r[15]+r[0]);
goto P_0c08efe6;
P_0c08efe6: /* original e008, guest PC 0x0c08efe6 */
if(!s->budget--) { s->failed_pc=0x0c08efe6u; return 0; }
r[0]=0x00000008u;
goto P_0c08efe8;
P_0c08efe8: /* original f3f6, guest PC 0x0c08efe8 */
if(!s->budget--) { s->failed_pc=0x0c08efe8u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c08efea;
P_0c08efea: /* original e020, guest PC 0x0c08efea */
if(!s->budget--) { s->failed_pc=0x0c08efeau; return 0; }
r[0]=0x00000020u;
goto P_0c08efec;
P_0c08efec: /* original ff37, guest PC 0x0c08efec */
if(!s->budget--) { s->failed_pc=0x0c08efecu; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c08efee;
P_0c08efee: /* original f63c, guest PC 0x0c08efee */
if(!s->budget--) { s->failed_pc=0x0c08efeeu; return 0; }
vf3_matrix_move(s,6,3);
goto P_0c08eff0;
P_0c08eff0: /* original 4d0b, guest PC 0x0c08eff0 */
if(!s->budget--) { s->failed_pc=0x0c08eff0u; return 0; }
target=r[13];
r[16]=0x0c08eff4u;
fr[6]^=0x80000000u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08eff4u) { target=s->pc; goto dispatch; }
goto P_0c08eff4;
P_0c08eff2: /* original f64d, guest PC 0x0c08eff2 */
if(!s->budget--) { s->failed_pc=0x0c08eff2u; return 0; }
fr[6]^=0x80000000u;
goto P_0c08eff4;
P_0c08eff4: /* original d346, guest PC 0x0c08eff4 */
if(!s->budget--) { s->failed_pc=0x0c08eff4u; return 0; }
r[3]=read(ram,0x0c08f110u,4);
goto P_0c08eff6;
P_0c08eff6: /* original 85ee, guest PC 0x0c08eff6 */
if(!s->budget--) { s->failed_pc=0x0c08eff6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+28,2);
goto P_0c08eff8;
P_0c08eff8: /* original 430b, guest PC 0x0c08eff8 */
if(!s->budget--) { s->failed_pc=0x0c08eff8u; return 0; }
target=r[3];
r[16]=0x0c08effcu;
r[4]=0u-r[0];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08effcu) { target=s->pc; goto dispatch; }
goto P_0c08effc;
P_0c08effa: /* original 640b, guest PC 0x0c08effa */
if(!s->budget--) { s->failed_pc=0x0c08effau; return 0; }
r[4]=0u-r[0];
goto P_0c08effc;
P_0c08effc: /* original 85ef, guest PC 0x0c08effc */
if(!s->budget--) { s->failed_pc=0x0c08effcu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+30,2);
goto P_0c08effe;
P_0c08effe: /* original 480b, guest PC 0x0c08effe */
if(!s->budget--) { s->failed_pc=0x0c08effeu; return 0; }
target=r[8];
r[16]=0x0c08f002u;
r[4]=0u-r[0];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08f002u) { target=s->pc; goto dispatch; }
goto P_0c08f002;
P_0c08f000: /* original 640b, guest PC 0x0c08f000 */
if(!s->budget--) { s->failed_pc=0x0c08f000u; return 0; }
r[4]=0u-r[0];
goto P_0c08f002;
P_0c08f002: /* original 9072, guest PC 0x0c08f002 */
if(!s->budget--) { s->failed_pc=0x0c08f002u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08f0eau,2);
goto P_0c08f004;
P_0c08f004: /* original f6e6, guest PC 0x0c08f004 */
if(!s->budget--) { s->failed_pc=0x0c08f004u; return 0; }
vf3_matrix_load(s,ram,6,r[14]+r[0]);
goto P_0c08f006;
P_0c08f006: /* original 70fc, guest PC 0x0c08f006 */
if(!s->budget--) { s->failed_pc=0x0c08f006u; return 0; }
r[0]+=0xfffffffcu;
goto P_0c08f008;
P_0c08f008: /* original f5e6, guest PC 0x0c08f008 */
if(!s->budget--) { s->failed_pc=0x0c08f008u; return 0; }
vf3_matrix_load(s,ram,5,r[14]+r[0]);
goto P_0c08f00a;
P_0c08f00a: /* original 70fc, guest PC 0x0c08f00a */
if(!s->budget--) { s->failed_pc=0x0c08f00au; return 0; }
r[0]+=0xfffffffcu;
goto P_0c08f00c;
P_0c08f00c: /* original f64d, guest PC 0x0c08f00c */
if(!s->budget--) { s->failed_pc=0x0c08f00cu; return 0; }
fr[6]^=0x80000000u;
goto P_0c08f00e;
P_0c08f00e: /* original 4d0b, guest PC 0x0c08f00e */
if(!s->budget--) { s->failed_pc=0x0c08f00eu; return 0; }
target=r[13];
r[16]=0x0c08f012u;
vf3_matrix_load(s,ram,4,r[14]+r[0]);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08f012u) { target=s->pc; goto dispatch; }
goto P_0c08f012;
P_0c08f010: /* original f4e6, guest PC 0x0c08f010 */
if(!s->budget--) { s->failed_pc=0x0c08f010u; return 0; }
vf3_matrix_load(s,ram,4,r[14]+r[0]);
goto P_0c08f012;
P_0c08f012: /* original f5fc, guest PC 0x0c08f012 */
if(!s->budget--) { s->failed_pc=0x0c08f012u; return 0; }
vf3_matrix_move(s,5,15);
goto P_0c08f014;
P_0c08f014: /* original f6fc, guest PC 0x0c08f014 */
if(!s->budget--) { s->failed_pc=0x0c08f014u; return 0; }
vf3_matrix_move(s,6,15);
goto P_0c08f016;
P_0c08f016: /* original 4c0b, guest PC 0x0c08f016 */
if(!s->budget--) { s->failed_pc=0x0c08f016u; return 0; }
target=r[12];
r[16]=0x0c08f01au;
vf3_matrix_move(s,4,15);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08f01au) { target=s->pc; goto dispatch; }
goto P_0c08f01a;
P_0c08f018: /* original f4fc, guest PC 0x0c08f018 */
if(!s->budget--) { s->failed_pc=0x0c08f018u; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c08f01a;
P_0c08f01a: /* original c73e, guest PC 0x0c08f01a */
if(!s->budget--) { s->failed_pc=0x0c08f01au; return 0; }
r[0]=0x0c08f114u;
goto P_0c08f01c;
P_0c08f01c: /* original fe08, guest PC 0x0c08f01c */
if(!s->budget--) { s->failed_pc=0x0c08f01cu; return 0; }
vf3_matrix_load(s,ram,14,r[0]);
goto P_0c08f01e;
P_0c08f01e: /* original f5ec, guest PC 0x0c08f01e */
if(!s->budget--) { s->failed_pc=0x0c08f01eu; return 0; }
vf3_matrix_move(s,5,14);
goto P_0c08f020;
P_0c08f020: /* original f6ec, guest PC 0x0c08f020 */
if(!s->budget--) { s->failed_pc=0x0c08f020u; return 0; }
vf3_matrix_move(s,6,14);
goto P_0c08f022;
P_0c08f022: /* original 4c0b, guest PC 0x0c08f022 */
if(!s->budget--) { s->failed_pc=0x0c08f022u; return 0; }
target=r[12];
r[16]=0x0c08f026u;
vf3_matrix_move(s,4,14);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08f026u) { target=s->pc; goto dispatch; }
goto P_0c08f026;
P_0c08f024: /* original f4ec, guest PC 0x0c08f024 */
if(!s->budget--) { s->failed_pc=0x0c08f024u; return 0; }
vf3_matrix_move(s,4,14);
goto P_0c08f026;
P_0c08f026: /* original 9461, guest PC 0x0c08f026 */
if(!s->budget--) { s->failed_pc=0x0c08f026u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08f0ecu,2);
goto P_0c08f028;
P_0c08f028: /* original 4b0b, guest PC 0x0c08f028 */
if(!s->budget--) { s->failed_pc=0x0c08f028u; return 0; }
target=r[11];
r[16]=0x0c08f02cu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08f02cu) { target=s->pc; goto dispatch; }
goto P_0c08f02c;
P_0c08f02a: /* original 0009, guest PC 0x0c08f02a */
if(!s->budget--) { s->failed_pc=0x0c08f02au; return 0; }
goto P_0c08f02c;
P_0c08f02c: /* original 4a0b, guest PC 0x0c08f02c */
if(!s->budget--) { s->failed_pc=0x0c08f02cu; return 0; }
target=r[10];
r[16]=0x0c08f030u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08f030u) { target=s->pc; goto dispatch; }
goto P_0c08f030;
P_0c08f02e: /* original 0009, guest PC 0x0c08f02e */
if(!s->budget--) { s->failed_pc=0x0c08f02eu; return 0; }
goto P_0c08f030;
P_0c08f030: /* original 905d, guest PC 0x0c08f030 */
if(!s->budget--) { s->failed_pc=0x0c08f030u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08f0eeu,2);
goto P_0c08f032;
P_0c08f032: /* original f6e6, guest PC 0x0c08f032 */
if(!s->budget--) { s->failed_pc=0x0c08f032u; return 0; }
vf3_matrix_load(s,ram,6,r[14]+r[0]);
goto P_0c08f034;
P_0c08f034: /* original 70fc, guest PC 0x0c08f034 */
if(!s->budget--) { s->failed_pc=0x0c08f034u; return 0; }
r[0]+=0xfffffffcu;
goto P_0c08f036;
P_0c08f036: /* original f5e6, guest PC 0x0c08f036 */
if(!s->budget--) { s->failed_pc=0x0c08f036u; return 0; }
vf3_matrix_load(s,ram,5,r[14]+r[0]);
goto P_0c08f038;
P_0c08f038: /* original 70fc, guest PC 0x0c08f038 */
if(!s->budget--) { s->failed_pc=0x0c08f038u; return 0; }
r[0]+=0xfffffffcu;
goto P_0c08f03a;
P_0c08f03a: /* original f64d, guest PC 0x0c08f03a */
if(!s->budget--) { s->failed_pc=0x0c08f03au; return 0; }
fr[6]^=0x80000000u;
goto P_0c08f03c;
P_0c08f03c: /* original 4d0b, guest PC 0x0c08f03c */
if(!s->budget--) { s->failed_pc=0x0c08f03cu; return 0; }
target=r[13];
r[16]=0x0c08f040u;
vf3_matrix_load(s,ram,4,r[14]+r[0]);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08f040u) { target=s->pc; goto dispatch; }
goto P_0c08f040;
P_0c08f03e: /* original f4e6, guest PC 0x0c08f03e */
if(!s->budget--) { s->failed_pc=0x0c08f03eu; return 0; }
vf3_matrix_load(s,ram,4,r[14]+r[0]);
goto P_0c08f040;
P_0c08f040: /* original f5fc, guest PC 0x0c08f040 */
if(!s->budget--) { s->failed_pc=0x0c08f040u; return 0; }
vf3_matrix_move(s,5,15);
goto P_0c08f042;
P_0c08f042: /* original f6fc, guest PC 0x0c08f042 */
if(!s->budget--) { s->failed_pc=0x0c08f042u; return 0; }
vf3_matrix_move(s,6,15);
goto P_0c08f044;
P_0c08f044: /* original 4c0b, guest PC 0x0c08f044 */
if(!s->budget--) { s->failed_pc=0x0c08f044u; return 0; }
target=r[12];
r[16]=0x0c08f048u;
vf3_matrix_move(s,4,15);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08f048u) { target=s->pc; goto dispatch; }
goto P_0c08f048;
P_0c08f046: /* original f4fc, guest PC 0x0c08f046 */
if(!s->budget--) { s->failed_pc=0x0c08f046u; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c08f048;
P_0c08f048: /* original 4b0b, guest PC 0x0c08f048 */
if(!s->budget--) { s->failed_pc=0x0c08f048u; return 0; }
target=r[11];
r[16]=0x0c08f04cu;
r[4]=r[9];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08f04cu) { target=s->pc; goto dispatch; }
goto P_0c08f04c;
P_0c08f04a: /* original 6493, guest PC 0x0c08f04a */
if(!s->budget--) { s->failed_pc=0x0c08f04au; return 0; }
r[4]=r[9];
goto P_0c08f04c;
P_0c08f04c: /* original 4a0b, guest PC 0x0c08f04c */
if(!s->budget--) { s->failed_pc=0x0c08f04cu; return 0; }
target=r[10];
r[16]=0x0c08f050u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08f050u) { target=s->pc; goto dispatch; }
goto P_0c08f050;
P_0c08f04e: /* original 0009, guest PC 0x0c08f04e */
if(!s->budget--) { s->failed_pc=0x0c08f04eu; return 0; }
goto P_0c08f050;
P_0c08f050: /* original 85ef, guest PC 0x0c08f050 */
if(!s->budget--) { s->failed_pc=0x0c08f050u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+30,2);
goto P_0c08f052;
P_0c08f052: /* original 480b, guest PC 0x0c08f052 */
if(!s->budget--) { s->failed_pc=0x0c08f052u; return 0; }
target=r[8];
r[16]=0x0c08f056u;
r[4]=r[0];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08f056u) { target=s->pc; goto dispatch; }
goto P_0c08f056;
P_0c08f054: /* original 6403, guest PC 0x0c08f054 */
if(!s->budget--) { s->failed_pc=0x0c08f054u; return 0; }
r[4]=r[0];
goto P_0c08f056;
P_0c08f056: /* original d32e, guest PC 0x0c08f056 */
if(!s->budget--) { s->failed_pc=0x0c08f056u; return 0; }
r[3]=read(ram,0x0c08f110u,4);
goto P_0c08f058;
P_0c08f058: /* original 85ee, guest PC 0x0c08f058 */
if(!s->budget--) { s->failed_pc=0x0c08f058u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+28,2);
goto P_0c08f05a;
P_0c08f05a: /* original 430b, guest PC 0x0c08f05a */
if(!s->budget--) { s->failed_pc=0x0c08f05au; return 0; }
target=r[3];
r[16]=0x0c08f05eu;
r[4]=r[0];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08f05eu) { target=s->pc; goto dispatch; }
goto P_0c08f05e;
P_0c08f05c: /* original 6403, guest PC 0x0c08f05c */
if(!s->budget--) { s->failed_pc=0x0c08f05cu; return 0; }
r[4]=r[0];
goto P_0c08f05e;
P_0c08f05e: /* original e004, guest PC 0x0c08f05e */
if(!s->budget--) { s->failed_pc=0x0c08f05eu; return 0; }
r[0]=0x00000004u;
goto P_0c08f060;
P_0c08f060: /* original f5f8, guest PC 0x0c08f060 */
if(!s->budget--) { s->failed_pc=0x0c08f060u; return 0; }
vf3_matrix_load(s,ram,5,r[15]);
goto P_0c08f062;
P_0c08f062: /* original f4f6, guest PC 0x0c08f062 */
if(!s->budget--) { s->failed_pc=0x0c08f062u; return 0; }
vf3_matrix_load(s,ram,4,r[15]+r[0]);
goto P_0c08f064;
P_0c08f064: /* original e008, guest PC 0x0c08f064 */
if(!s->budget--) { s->failed_pc=0x0c08f064u; return 0; }
r[0]=0x00000008u;
goto P_0c08f066;
P_0c08f066: /* original f3f6, guest PC 0x0c08f066 */
if(!s->budget--) { s->failed_pc=0x0c08f066u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c08f068;
P_0c08f068: /* original e010, guest PC 0x0c08f068 */
if(!s->budget--) { s->failed_pc=0x0c08f068u; return 0; }
r[0]=0x00000010u;
goto P_0c08f06a;
P_0c08f06a: /* original ff37, guest PC 0x0c08f06a */
if(!s->budget--) { s->failed_pc=0x0c08f06au; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c08f06c;
P_0c08f06c: /* original f63c, guest PC 0x0c08f06c */
if(!s->budget--) { s->failed_pc=0x0c08f06cu; return 0; }
vf3_matrix_move(s,6,3);
goto P_0c08f06e;
P_0c08f06e: /* original 4d0b, guest PC 0x0c08f06e */
if(!s->budget--) { s->failed_pc=0x0c08f06eu; return 0; }
target=r[13];
r[16]=0x0c08f072u;
fr[6]^=0x80000000u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08f072u) { target=s->pc; goto dispatch; }
goto P_0c08f072;
P_0c08f070: /* original f64d, guest PC 0x0c08f070 */
if(!s->budget--) { s->failed_pc=0x0c08f070u; return 0; }
fr[6]^=0x80000000u;
goto P_0c08f072;
P_0c08f072: /* original d327, guest PC 0x0c08f072 */
if(!s->budget--) { s->failed_pc=0x0c08f072u; return 0; }
r[3]=read(ram,0x0c08f110u,4);
goto P_0c08f074;
P_0c08f074: /* original 85ee, guest PC 0x0c08f074 */
if(!s->budget--) { s->failed_pc=0x0c08f074u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+28,2);
goto P_0c08f076;
P_0c08f076: /* original 430b, guest PC 0x0c08f076 */
if(!s->budget--) { s->failed_pc=0x0c08f076u; return 0; }
target=r[3];
r[16]=0x0c08f07au;
r[4]=0u-r[0];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08f07au) { target=s->pc; goto dispatch; }
goto P_0c08f07a;
P_0c08f078: /* original 640b, guest PC 0x0c08f078 */
if(!s->budget--) { s->failed_pc=0x0c08f078u; return 0; }
r[4]=0u-r[0];
goto P_0c08f07a;
P_0c08f07a: /* original 85ef, guest PC 0x0c08f07a */
if(!s->budget--) { s->failed_pc=0x0c08f07au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+30,2);
goto P_0c08f07c;
P_0c08f07c: /* original 480b, guest PC 0x0c08f07c */
if(!s->budget--) { s->failed_pc=0x0c08f07cu; return 0; }
target=r[8];
r[16]=0x0c08f080u;
r[4]=0u-r[0];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08f080u) { target=s->pc; goto dispatch; }
goto P_0c08f080;
P_0c08f07e: /* original 640b, guest PC 0x0c08f07e */
if(!s->budget--) { s->failed_pc=0x0c08f07eu; return 0; }
r[4]=0u-r[0];
goto P_0c08f080;
P_0c08f080: /* original 9036, guest PC 0x0c08f080 */
if(!s->budget--) { s->failed_pc=0x0c08f080u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08f0f0u,2);
goto P_0c08f082;
P_0c08f082: /* original f4e6, guest PC 0x0c08f082 */
if(!s->budget--) { s->failed_pc=0x0c08f082u; return 0; }
vf3_matrix_load(s,ram,4,r[14]+r[0]);
goto P_0c08f084;
P_0c08f084: /* original 7004, guest PC 0x0c08f084 */
if(!s->budget--) { s->failed_pc=0x0c08f084u; return 0; }
r[0]+=0x00000004u;
goto P_0c08f086;
P_0c08f086: /* original f5e6, guest PC 0x0c08f086 */
if(!s->budget--) { s->failed_pc=0x0c08f086u; return 0; }
vf3_matrix_load(s,ram,5,r[14]+r[0]);
goto P_0c08f088;
P_0c08f088: /* original 7004, guest PC 0x0c08f088 */
if(!s->budget--) { s->failed_pc=0x0c08f088u; return 0; }
r[0]+=0x00000004u;
goto P_0c08f08a;
P_0c08f08a: /* original f3e6, guest PC 0x0c08f08a */
if(!s->budget--) { s->failed_pc=0x0c08f08au; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c08f08c;
P_0c08f08c: /* original e00c, guest PC 0x0c08f08c */
if(!s->budget--) { s->failed_pc=0x0c08f08cu; return 0; }
r[0]=0x0000000cu;
goto P_0c08f08e;
P_0c08f08e: /* original ff37, guest PC 0x0c08f08e */
if(!s->budget--) { s->failed_pc=0x0c08f08eu; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c08f090;
P_0c08f090: /* original f63c, guest PC 0x0c08f090 */
if(!s->budget--) { s->failed_pc=0x0c08f090u; return 0; }
vf3_matrix_move(s,6,3);
goto P_0c08f092;
P_0c08f092: /* original 4d0b, guest PC 0x0c08f092 */
if(!s->budget--) { s->failed_pc=0x0c08f092u; return 0; }
target=r[13];
r[16]=0x0c08f096u;
fr[6]^=0x80000000u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08f096u) { target=s->pc; goto dispatch; }
goto P_0c08f096;
P_0c08f094: /* original f64d, guest PC 0x0c08f094 */
if(!s->budget--) { s->failed_pc=0x0c08f094u; return 0; }
fr[6]^=0x80000000u;
goto P_0c08f096;
P_0c08f096: /* original f5fc, guest PC 0x0c08f096 */
if(!s->budget--) { s->failed_pc=0x0c08f096u; return 0; }
vf3_matrix_move(s,5,15);
goto P_0c08f098;
P_0c08f098: /* original f6fc, guest PC 0x0c08f098 */
if(!s->budget--) { s->failed_pc=0x0c08f098u; return 0; }
vf3_matrix_move(s,6,15);
goto P_0c08f09a;
P_0c08f09a: /* original 4c0b, guest PC 0x0c08f09a */
if(!s->budget--) { s->failed_pc=0x0c08f09au; return 0; }
target=r[12];
r[16]=0x0c08f09eu;
vf3_matrix_move(s,4,15);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08f09eu) { target=s->pc; goto dispatch; }
goto P_0c08f09e;
P_0c08f09c: /* original f4fc, guest PC 0x0c08f09c */
if(!s->budget--) { s->failed_pc=0x0c08f09cu; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c08f09e;
P_0c08f09e: /* original 4b0b, guest PC 0x0c08f09e */
if(!s->budget--) { s->failed_pc=0x0c08f09eu; return 0; }
target=r[11];
r[16]=0x0c08f0a2u;
r[4]=r[9];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08f0a2u) { target=s->pc; goto dispatch; }
goto P_0c08f0a2;
P_0c08f0a0: /* original 6493, guest PC 0x0c08f0a0 */
if(!s->budget--) { s->failed_pc=0x0c08f0a0u; return 0; }
r[4]=r[9];
goto P_0c08f0a2;
P_0c08f0a2: /* original 4a0b, guest PC 0x0c08f0a2 */
if(!s->budget--) { s->failed_pc=0x0c08f0a2u; return 0; }
target=r[10];
r[16]=0x0c08f0a6u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08f0a6u) { target=s->pc; goto dispatch; }
goto P_0c08f0a6;
P_0c08f0a4: /* original 0009, guest PC 0x0c08f0a4 */
if(!s->budget--) { s->failed_pc=0x0c08f0a4u; return 0; }
goto P_0c08f0a6;
P_0c08f0a6: /* original 9024, guest PC 0x0c08f0a6 */
if(!s->budget--) { s->failed_pc=0x0c08f0a6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08f0f2u,2);
goto P_0c08f0a8;
P_0c08f0a8: /* original f4e6, guest PC 0x0c08f0a8 */
if(!s->budget--) { s->failed_pc=0x0c08f0a8u; return 0; }
vf3_matrix_load(s,ram,4,r[14]+r[0]);
goto P_0c08f0aa;
P_0c08f0aa: /* original 7004, guest PC 0x0c08f0aa */
if(!s->budget--) { s->failed_pc=0x0c08f0aau; return 0; }
r[0]+=0x00000004u;
goto P_0c08f0ac;
P_0c08f0ac: /* original f5e6, guest PC 0x0c08f0ac */
if(!s->budget--) { s->failed_pc=0x0c08f0acu; return 0; }
vf3_matrix_load(s,ram,5,r[14]+r[0]);
goto P_0c08f0ae;
P_0c08f0ae: /* original 7004, guest PC 0x0c08f0ae */
if(!s->budget--) { s->failed_pc=0x0c08f0aeu; return 0; }
r[0]+=0x00000004u;
goto P_0c08f0b0;
P_0c08f0b0: /* original f3e6, guest PC 0x0c08f0b0 */
if(!s->budget--) { s->failed_pc=0x0c08f0b0u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c08f0b2;
P_0c08f0b2: /* original e018, guest PC 0x0c08f0b2 */
if(!s->budget--) { s->failed_pc=0x0c08f0b2u; return 0; }
r[0]=0x00000018u;
goto P_0c08f0b4;
P_0c08f0b4: /* original ff37, guest PC 0x0c08f0b4 */
if(!s->budget--) { s->failed_pc=0x0c08f0b4u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c08f0b6;
P_0c08f0b6: /* original f63c, guest PC 0x0c08f0b6 */
if(!s->budget--) { s->failed_pc=0x0c08f0b6u; return 0; }
vf3_matrix_move(s,6,3);
goto P_0c08f0b8;
P_0c08f0b8: /* original 4d0b, guest PC 0x0c08f0b8 */
if(!s->budget--) { s->failed_pc=0x0c08f0b8u; return 0; }
target=r[13];
r[16]=0x0c08f0bcu;
fr[6]^=0x80000000u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08f0bcu) { target=s->pc; goto dispatch; }
goto P_0c08f0bc;
P_0c08f0ba: /* original f64d, guest PC 0x0c08f0ba */
if(!s->budget--) { s->failed_pc=0x0c08f0bau; return 0; }
fr[6]^=0x80000000u;
goto P_0c08f0bc;
P_0c08f0bc: /* original f5fc, guest PC 0x0c08f0bc */
if(!s->budget--) { s->failed_pc=0x0c08f0bcu; return 0; }
vf3_matrix_move(s,5,15);
goto P_0c08f0be;
P_0c08f0be: /* original f6fc, guest PC 0x0c08f0be */
if(!s->budget--) { s->failed_pc=0x0c08f0beu; return 0; }
vf3_matrix_move(s,6,15);
goto P_0c08f0c0;
P_0c08f0c0: /* original 4c0b, guest PC 0x0c08f0c0 */
if(!s->budget--) { s->failed_pc=0x0c08f0c0u; return 0; }
target=r[12];
r[16]=0x0c08f0c4u;
vf3_matrix_move(s,4,15);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08f0c4u) { target=s->pc; goto dispatch; }
goto P_0c08f0c4;
P_0c08f0c2: /* original f4fc, guest PC 0x0c08f0c2 */
if(!s->budget--) { s->failed_pc=0x0c08f0c2u; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c08f0c4;
P_0c08f0c4: /* original 4b0b, guest PC 0x0c08f0c4 */
if(!s->budget--) { s->failed_pc=0x0c08f0c4u; return 0; }
target=r[11];
r[16]=0x0c08f0c8u;
r[4]=r[9];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08f0c8u) { target=s->pc; goto dispatch; }
goto P_0c08f0c8;
P_0c08f0c6: /* original 6493, guest PC 0x0c08f0c6 */
if(!s->budget--) { s->failed_pc=0x0c08f0c6u; return 0; }
r[4]=r[9];
goto P_0c08f0c8;
P_0c08f0c8: /* original d313, guest PC 0x0c08f0c8 */
if(!s->budget--) { s->failed_pc=0x0c08f0c8u; return 0; }
r[3]=read(ram,0x0c08f118u,4);
goto P_0c08f0ca;
P_0c08f0ca: /* original 430b, guest PC 0x0c08f0ca */
if(!s->budget--) { s->failed_pc=0x0c08f0cau; return 0; }
target=r[3];
r[16]=0x0c08f0ceu;
r[4]=0x00000001u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08f0ceu) { target=s->pc; goto dispatch; }
goto P_0c08f0ce;
P_0c08f0cc: /* original e401, guest PC 0x0c08f0cc */
if(!s->budget--) { s->failed_pc=0x0c08f0ccu; return 0; }
r[4]=0x00000001u;
goto P_0c08f0ce;
P_0c08f0ce: /* original 7f24, guest PC 0x0c08f0ce */
if(!s->budget--) { s->failed_pc=0x0c08f0ceu; return 0; }
r[15]+=0x00000024u;
goto P_0c08f0d0;
P_0c08f0d0: /* original 4f26, guest PC 0x0c08f0d0 */
if(!s->budget--) { s->failed_pc=0x0c08f0d0u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c08f0d2;
P_0c08f0d2: /* original fef9, guest PC 0x0c08f0d2 */
if(!s->budget--) { s->failed_pc=0x0c08f0d2u; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c08f0d4;
P_0c08f0d4: /* original fff9, guest PC 0x0c08f0d4 */
if(!s->budget--) { s->failed_pc=0x0c08f0d4u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c08f0d6;
P_0c08f0d6: /* original 68f6, guest PC 0x0c08f0d6 */
if(!s->budget--) { s->failed_pc=0x0c08f0d6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c08f0d8;
P_0c08f0d8: /* original 69f6, guest PC 0x0c08f0d8 */
if(!s->budget--) { s->failed_pc=0x0c08f0d8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c08f0da;
P_0c08f0da: /* original 6af6, guest PC 0x0c08f0da */
if(!s->budget--) { s->failed_pc=0x0c08f0dau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c08f0dc;
P_0c08f0dc: /* original 6bf6, guest PC 0x0c08f0dc */
if(!s->budget--) { s->failed_pc=0x0c08f0dcu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c08f0de;
P_0c08f0de: /* original 6cf6, guest PC 0x0c08f0de */
if(!s->budget--) { s->failed_pc=0x0c08f0deu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c08f0e0;
P_0c08f0e0: /* original 6df6, guest PC 0x0c08f0e0 */
if(!s->budget--) { s->failed_pc=0x0c08f0e0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c08f0e2;
P_0c08f0e2: /* original 000b, guest PC 0x0c08f0e2 */
if(!s->budget--) { s->failed_pc=0x0c08f0e2u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c08f0e4: /* original 6ef6, guest PC 0x0c08f0e4 */
if(!s->budget--) { s->failed_pc=0x0c08f0e4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c08f0e6u,s,ram);
P_0c08f3d8: /* original 4f22, guest PC 0x0c08f3d8 */
if(!s->budget--) { s->failed_pc=0x0c08f3d8u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c08f3da;
P_0c08f3da: /* original 1e3c, guest PC 0x0c08f3da */
if(!s->budget--) { s->failed_pc=0x0c08f3dau; return 0; }
write(ram,r[14]+48,r[3],4);
goto P_0c08f3dc;
P_0c08f3dc: /* original dd59, guest PC 0x0c08f3dc */
if(!s->budget--) { s->failed_pc=0x0c08f3dcu; return 0; }
r[13]=read(ram,0x0c08f544u,4);
goto P_0c08f3de;
P_0c08f3de: /* original 90a8, guest PC 0x0c08f3de */
if(!s->budget--) { s->failed_pc=0x0c08f3deu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08f532u,2);
goto P_0c08f3e0;
P_0c08f3e0: /* original f3d9, guest PC 0x0c08f3e0 */
if(!s->budget--) { s->failed_pc=0x0c08f3e0u; return 0; }
vf3_matrix_load(s,ram,3,r[13]);
r[13]+=(r[18]&0x100000u)?8:4;
goto P_0c08f3e2;
P_0c08f3e2: /* original fe37, guest PC 0x0c08f3e2 */
if(!s->budget--) { s->failed_pc=0x0c08f3e2u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c08f3e4;
P_0c08f3e4: /* original 7004, guest PC 0x0c08f3e4 */
if(!s->budget--) { s->failed_pc=0x0c08f3e4u; return 0; }
r[0]+=0x00000004u;
goto P_0c08f3e6;
P_0c08f3e6: /* original f3d9, guest PC 0x0c08f3e6 */
if(!s->budget--) { s->failed_pc=0x0c08f3e6u; return 0; }
vf3_matrix_load(s,ram,3,r[13]);
r[13]+=(r[18]&0x100000u)?8:4;
goto P_0c08f3e8;
P_0c08f3e8: /* original fe37, guest PC 0x0c08f3e8 */
if(!s->budget--) { s->failed_pc=0x0c08f3e8u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c08f3ea;
P_0c08f3ea: /* original 7004, guest PC 0x0c08f3ea */
if(!s->budget--) { s->failed_pc=0x0c08f3eau; return 0; }
r[0]+=0x00000004u;
goto P_0c08f3ec;
P_0c08f3ec: /* original f3d9, guest PC 0x0c08f3ec */
if(!s->budget--) { s->failed_pc=0x0c08f3ecu; return 0; }
vf3_matrix_load(s,ram,3,r[13]);
r[13]+=(r[18]&0x100000u)?8:4;
goto P_0c08f3ee;
P_0c08f3ee: /* original fe37, guest PC 0x0c08f3ee */
if(!s->budget--) { s->failed_pc=0x0c08f3eeu; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c08f3f0;
P_0c08f3f0: /* original 7004, guest PC 0x0c08f3f0 */
if(!s->budget--) { s->failed_pc=0x0c08f3f0u; return 0; }
r[0]+=0x00000004u;
goto P_0c08f3f2;
P_0c08f3f2: /* original f3d9, guest PC 0x0c08f3f2 */
if(!s->budget--) { s->failed_pc=0x0c08f3f2u; return 0; }
vf3_matrix_load(s,ram,3,r[13]);
r[13]+=(r[18]&0x100000u)?8:4;
goto P_0c08f3f4;
P_0c08f3f4: /* original fe37, guest PC 0x0c08f3f4 */
if(!s->budget--) { s->failed_pc=0x0c08f3f4u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c08f3f6;
P_0c08f3f6: /* original 7004, guest PC 0x0c08f3f6 */
if(!s->budget--) { s->failed_pc=0x0c08f3f6u; return 0; }
r[0]+=0x00000004u;
goto P_0c08f3f8;
P_0c08f3f8: /* original f3d9, guest PC 0x0c08f3f8 */
if(!s->budget--) { s->failed_pc=0x0c08f3f8u; return 0; }
vf3_matrix_load(s,ram,3,r[13]);
r[13]+=(r[18]&0x100000u)?8:4;
goto P_0c08f3fa;
P_0c08f3fa: /* original fe37, guest PC 0x0c08f3fa */
if(!s->budget--) { s->failed_pc=0x0c08f3fau; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c08f3fc;
P_0c08f3fc: /* original 7004, guest PC 0x0c08f3fc */
if(!s->budget--) { s->failed_pc=0x0c08f3fcu; return 0; }
r[0]+=0x00000004u;
goto P_0c08f3fe;
P_0c08f3fe: /* original f3d9, guest PC 0x0c08f3fe */
if(!s->budget--) { s->failed_pc=0x0c08f3feu; return 0; }
vf3_matrix_load(s,ram,3,r[13]);
r[13]+=(r[18]&0x100000u)?8:4;
goto P_0c08f400;
P_0c08f400: /* original fe37, guest PC 0x0c08f400 */
if(!s->budget--) { s->failed_pc=0x0c08f400u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c08f402;
P_0c08f402: /* original 7034, guest PC 0x0c08f402 */
if(!s->budget--) { s->failed_pc=0x0c08f402u; return 0; }
r[0]+=0x00000034u;
goto P_0c08f404;
P_0c08f404: /* original f3d9, guest PC 0x0c08f404 */
if(!s->budget--) { s->failed_pc=0x0c08f404u; return 0; }
vf3_matrix_load(s,ram,3,r[13]);
r[13]+=(r[18]&0x100000u)?8:4;
goto P_0c08f406;
P_0c08f406: /* original fe37, guest PC 0x0c08f406 */
if(!s->budget--) { s->failed_pc=0x0c08f406u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c08f408;
P_0c08f408: /* original 7004, guest PC 0x0c08f408 */
if(!s->budget--) { s->failed_pc=0x0c08f408u; return 0; }
r[0]+=0x00000004u;
goto P_0c08f40a;
P_0c08f40a: /* original f3d9, guest PC 0x0c08f40a */
if(!s->budget--) { s->failed_pc=0x0c08f40au; return 0; }
vf3_matrix_load(s,ram,3,r[13]);
r[13]+=(r[18]&0x100000u)?8:4;
goto P_0c08f40c;
P_0c08f40c: /* original fe37, guest PC 0x0c08f40c */
if(!s->budget--) { s->failed_pc=0x0c08f40cu; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c08f40e;
P_0c08f40e: /* original f3d9, guest PC 0x0c08f40e */
if(!s->budget--) { s->failed_pc=0x0c08f40eu; return 0; }
vf3_matrix_load(s,ram,3,r[13]);
r[13]+=(r[18]&0x100000u)?8:4;
goto P_0c08f410;
P_0c08f410: /* original 7004, guest PC 0x0c08f410 */
if(!s->budget--) { s->failed_pc=0x0c08f410u; return 0; }
r[0]+=0x00000004u;
goto P_0c08f412;
P_0c08f412: /* original fe37, guest PC 0x0c08f412 */
if(!s->budget--) { s->failed_pc=0x0c08f412u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c08f414;
P_0c08f414: /* original 7004, guest PC 0x0c08f414 */
if(!s->budget--) { s->failed_pc=0x0c08f414u; return 0; }
r[0]+=0x00000004u;
goto P_0c08f416;
P_0c08f416: /* original f3d9, guest PC 0x0c08f416 */
if(!s->budget--) { s->failed_pc=0x0c08f416u; return 0; }
vf3_matrix_load(s,ram,3,r[13]);
r[13]+=(r[18]&0x100000u)?8:4;
goto P_0c08f418;
P_0c08f418: /* original fe37, guest PC 0x0c08f418 */
if(!s->budget--) { s->failed_pc=0x0c08f418u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c08f41a;
P_0c08f41a: /* original 7004, guest PC 0x0c08f41a */
if(!s->budget--) { s->failed_pc=0x0c08f41au; return 0; }
r[0]+=0x00000004u;
goto P_0c08f41c;
P_0c08f41c: /* original f3d9, guest PC 0x0c08f41c */
if(!s->budget--) { s->failed_pc=0x0c08f41cu; return 0; }
vf3_matrix_load(s,ram,3,r[13]);
r[13]+=(r[18]&0x100000u)?8:4;
goto P_0c08f41e;
P_0c08f41e: /* original fe37, guest PC 0x0c08f41e */
if(!s->budget--) { s->failed_pc=0x0c08f41eu; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c08f420;
P_0c08f420: /* original 7004, guest PC 0x0c08f420 */
if(!s->budget--) { s->failed_pc=0x0c08f420u; return 0; }
r[0]+=0x00000004u;
goto P_0c08f422;
P_0c08f422: /* original f3d9, guest PC 0x0c08f422 */
if(!s->budget--) { s->failed_pc=0x0c08f422u; return 0; }
vf3_matrix_load(s,ram,3,r[13]);
r[13]+=(r[18]&0x100000u)?8:4;
goto P_0c08f424;
P_0c08f424: /* original fe37, guest PC 0x0c08f424 */
if(!s->budget--) { s->failed_pc=0x0c08f424u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c08f426;
P_0c08f426: /* original 7034, guest PC 0x0c08f426 */
if(!s->budget--) { s->failed_pc=0x0c08f426u; return 0; }
r[0]+=0x00000034u;
goto P_0c08f428;
P_0c08f428: /* original f3d9, guest PC 0x0c08f428 */
if(!s->budget--) { s->failed_pc=0x0c08f428u; return 0; }
vf3_matrix_load(s,ram,3,r[13]);
r[13]+=(r[18]&0x100000u)?8:4;
goto P_0c08f42a;
P_0c08f42a: /* original fe37, guest PC 0x0c08f42a */
if(!s->budget--) { s->failed_pc=0x0c08f42au; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c08f42c;
P_0c08f42c: /* original 7004, guest PC 0x0c08f42c */
if(!s->budget--) { s->failed_pc=0x0c08f42cu; return 0; }
r[0]+=0x00000004u;
goto P_0c08f42e;
P_0c08f42e: /* original f3d9, guest PC 0x0c08f42e */
if(!s->budget--) { s->failed_pc=0x0c08f42eu; return 0; }
vf3_matrix_load(s,ram,3,r[13]);
r[13]+=(r[18]&0x100000u)?8:4;
goto P_0c08f430;
P_0c08f430: /* original fe37, guest PC 0x0c08f430 */
if(!s->budget--) { s->failed_pc=0x0c08f430u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c08f432;
P_0c08f432: /* original 7004, guest PC 0x0c08f432 */
if(!s->budget--) { s->failed_pc=0x0c08f432u; return 0; }
r[0]+=0x00000004u;
goto P_0c08f434;
P_0c08f434: /* original f3d9, guest PC 0x0c08f434 */
if(!s->budget--) { s->failed_pc=0x0c08f434u; return 0; }
vf3_matrix_load(s,ram,3,r[13]);
r[13]+=(r[18]&0x100000u)?8:4;
goto P_0c08f436;
P_0c08f436: /* original fe37, guest PC 0x0c08f436 */
if(!s->budget--) { s->failed_pc=0x0c08f436u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c08f438;
P_0c08f438: /* original 7004, guest PC 0x0c08f438 */
if(!s->budget--) { s->failed_pc=0x0c08f438u; return 0; }
r[0]+=0x00000004u;
goto P_0c08f43a;
P_0c08f43a: /* original f3d9, guest PC 0x0c08f43a */
if(!s->budget--) { s->failed_pc=0x0c08f43au; return 0; }
vf3_matrix_load(s,ram,3,r[13]);
r[13]+=(r[18]&0x100000u)?8:4;
goto P_0c08f43c;
P_0c08f43c: /* original fe37, guest PC 0x0c08f43c */
if(!s->budget--) { s->failed_pc=0x0c08f43cu; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c08f43e;
P_0c08f43e: /* original 7004, guest PC 0x0c08f43e */
if(!s->budget--) { s->failed_pc=0x0c08f43eu; return 0; }
r[0]+=0x00000004u;
goto P_0c08f440;
P_0c08f440: /* original f3d9, guest PC 0x0c08f440 */
if(!s->budget--) { s->failed_pc=0x0c08f440u; return 0; }
vf3_matrix_load(s,ram,3,r[13]);
r[13]+=(r[18]&0x100000u)?8:4;
goto P_0c08f442;
P_0c08f442: /* original fe37, guest PC 0x0c08f442 */
if(!s->budget--) { s->failed_pc=0x0c08f442u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c08f444;
P_0c08f444: /* original 7004, guest PC 0x0c08f444 */
if(!s->budget--) { s->failed_pc=0x0c08f444u; return 0; }
r[0]+=0x00000004u;
goto P_0c08f446;
P_0c08f446: /* original f3d9, guest PC 0x0c08f446 */
if(!s->budget--) { s->failed_pc=0x0c08f446u; return 0; }
vf3_matrix_load(s,ram,3,r[13]);
r[13]+=(r[18]&0x100000u)?8:4;
goto P_0c08f448;
P_0c08f448: /* original fe37, guest PC 0x0c08f448 */
if(!s->budget--) { s->failed_pc=0x0c08f448u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c08f44a;
P_0c08f44a: /* original 7034, guest PC 0x0c08f44a */
if(!s->budget--) { s->failed_pc=0x0c08f44au; return 0; }
r[0]+=0x00000034u;
goto P_0c08f44c;
P_0c08f44c: /* original f3d9, guest PC 0x0c08f44c */
if(!s->budget--) { s->failed_pc=0x0c08f44cu; return 0; }
vf3_matrix_load(s,ram,3,r[13]);
r[13]+=(r[18]&0x100000u)?8:4;
goto P_0c08f44e;
P_0c08f44e: /* original fe37, guest PC 0x0c08f44e */
if(!s->budget--) { s->failed_pc=0x0c08f44eu; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c08f450;
P_0c08f450: /* original f3d9, guest PC 0x0c08f450 */
if(!s->budget--) { s->failed_pc=0x0c08f450u; return 0; }
vf3_matrix_load(s,ram,3,r[13]);
r[13]+=(r[18]&0x100000u)?8:4;
goto P_0c08f452;
P_0c08f452: /* original 7004, guest PC 0x0c08f452 */
if(!s->budget--) { s->failed_pc=0x0c08f452u; return 0; }
r[0]+=0x00000004u;
goto P_0c08f454;
P_0c08f454: /* original fe37, guest PC 0x0c08f454 */
if(!s->budget--) { s->failed_pc=0x0c08f454u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c08f456;
P_0c08f456: /* original 7004, guest PC 0x0c08f456 */
if(!s->budget--) { s->failed_pc=0x0c08f456u; return 0; }
r[0]+=0x00000004u;
goto P_0c08f458;
P_0c08f458: /* original f3d9, guest PC 0x0c08f458 */
if(!s->budget--) { s->failed_pc=0x0c08f458u; return 0; }
vf3_matrix_load(s,ram,3,r[13]);
r[13]+=(r[18]&0x100000u)?8:4;
goto P_0c08f45a;
P_0c08f45a: /* original fe37, guest PC 0x0c08f45a */
if(!s->budget--) { s->failed_pc=0x0c08f45au; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c08f45c;
P_0c08f45c: /* original 7004, guest PC 0x0c08f45c */
if(!s->budget--) { s->failed_pc=0x0c08f45cu; return 0; }
r[0]+=0x00000004u;
goto P_0c08f45e;
P_0c08f45e: /* original f3d9, guest PC 0x0c08f45e */
if(!s->budget--) { s->failed_pc=0x0c08f45eu; return 0; }
vf3_matrix_load(s,ram,3,r[13]);
r[13]+=(r[18]&0x100000u)?8:4;
goto P_0c08f460;
P_0c08f460: /* original fe37, guest PC 0x0c08f460 */
if(!s->budget--) { s->failed_pc=0x0c08f460u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c08f462;
P_0c08f462: /* original 7004, guest PC 0x0c08f462 */
if(!s->budget--) { s->failed_pc=0x0c08f462u; return 0; }
r[0]+=0x00000004u;
goto P_0c08f464;
P_0c08f464: /* original f3d9, guest PC 0x0c08f464 */
if(!s->budget--) { s->failed_pc=0x0c08f464u; return 0; }
vf3_matrix_load(s,ram,3,r[13]);
r[13]+=(r[18]&0x100000u)?8:4;
goto P_0c08f466;
P_0c08f466: /* original fe37, guest PC 0x0c08f466 */
if(!s->budget--) { s->failed_pc=0x0c08f466u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c08f468;
P_0c08f468: /* original 7004, guest PC 0x0c08f468 */
if(!s->budget--) { s->failed_pc=0x0c08f468u; return 0; }
r[0]+=0x00000004u;
goto P_0c08f46a;
P_0c08f46a: /* original f3d9, guest PC 0x0c08f46a */
if(!s->budget--) { s->failed_pc=0x0c08f46au; return 0; }
vf3_matrix_load(s,ram,3,r[13]);
r[13]+=(r[18]&0x100000u)?8:4;
goto P_0c08f46c;
P_0c08f46c: /* original fe37, guest PC 0x0c08f46c */
if(!s->budget--) { s->failed_pc=0x0c08f46cu; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c08f46e;
P_0c08f46e: /* original bf5f, guest PC 0x0c08f46e */
if(!s->budget--) { s->failed_pc=0x0c08f46eu; return 0; }
target=0x0c08f330u; r[16]=0x0c08f472u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08f472u) { target=s->pc; goto dispatch; }
goto P_0c08f472;
P_0c08f470: /* original 64e3, guest PC 0x0c08f470 */
if(!s->budget--) { s->failed_pc=0x0c08f470u; return 0; }
r[4]=r[14];
goto P_0c08f472;
P_0c08f472: /* original f3d9, guest PC 0x0c08f472 */
if(!s->budget--) { s->failed_pc=0x0c08f472u; return 0; }
vf3_matrix_load(s,ram,3,r[13]);
r[13]+=(r[18]&0x100000u)?8:4;
goto P_0c08f474;
P_0c08f474: /* original 905e, guest PC 0x0c08f474 */
if(!s->budget--) { s->failed_pc=0x0c08f474u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08f534u,2);
goto P_0c08f476;
P_0c08f476: /* original f6d9, guest PC 0x0c08f476 */
if(!s->budget--) { s->failed_pc=0x0c08f476u; return 0; }
vf3_matrix_load(s,ram,6,r[13]);
r[13]+=(r[18]&0x100000u)?8:4;
goto P_0c08f478;
P_0c08f478: /* original 4f26, guest PC 0x0c08f478 */
if(!s->budget--) { s->failed_pc=0x0c08f478u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c08f47a;
P_0c08f47a: /* original f5d9, guest PC 0x0c08f47a */
if(!s->budget--) { s->failed_pc=0x0c08f47au; return 0; }
vf3_matrix_load(s,ram,5,r[13]);
r[13]+=(r[18]&0x100000u)?8:4;
goto P_0c08f47c;
P_0c08f47c: /* original f75c, guest PC 0x0c08f47c */
if(!s->budget--) { s->failed_pc=0x0c08f47cu; return 0; }
vf3_matrix_move(s,7,5);
goto P_0c08f47e;
P_0c08f47e: /* original f761, guest PC 0x0c08f47e */
if(!s->budget--) { s->failed_pc=0x0c08f47eu; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[6],r[18],'-');
goto P_0c08f480;
P_0c08f480: /* original f47c, guest PC 0x0c08f480 */
if(!s->budget--) { s->failed_pc=0x0c08f480u; return 0; }
vf3_matrix_move(s,4,7);
goto P_0c08f482;
P_0c08f482: /* original f433, guest PC 0x0c08f482 */
if(!s->budget--) { s->failed_pc=0x0c08f482u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'/');
goto P_0c08f484;
P_0c08f484: /* original fe47, guest PC 0x0c08f484 */
if(!s->budget--) { s->failed_pc=0x0c08f484u; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c08f486;
P_0c08f486: /* original 7008, guest PC 0x0c08f486 */
if(!s->budget--) { s->failed_pc=0x0c08f486u; return 0; }
r[0]+=0x00000008u;
goto P_0c08f488;
P_0c08f488: /* original fe67, guest PC 0x0c08f488 */
if(!s->budget--) { s->failed_pc=0x0c08f488u; return 0; }
vf3_matrix_store(s,ram,6,r[14]+r[0]);
goto P_0c08f48a;
P_0c08f48a: /* original 7008, guest PC 0x0c08f48a */
if(!s->budget--) { s->failed_pc=0x0c08f48au; return 0; }
r[0]+=0x00000008u;
goto P_0c08f48c;
P_0c08f48c: /* original fe57, guest PC 0x0c08f48c */
if(!s->budget--) { s->failed_pc=0x0c08f48cu; return 0; }
vf3_matrix_store(s,ram,5,r[14]+r[0]);
goto P_0c08f48e;
P_0c08f48e: /* original 70f4, guest PC 0x0c08f48e */
if(!s->budget--) { s->failed_pc=0x0c08f48eu; return 0; }
r[0]+=0xfffffff4u;
goto P_0c08f490;
P_0c08f490: /* original f3d9, guest PC 0x0c08f490 */
if(!s->budget--) { s->failed_pc=0x0c08f490u; return 0; }
vf3_matrix_load(s,ram,3,r[13]);
r[13]+=(r[18]&0x100000u)?8:4;
goto P_0c08f492;
P_0c08f492: /* original f7d9, guest PC 0x0c08f492 */
if(!s->budget--) { s->failed_pc=0x0c08f492u; return 0; }
vf3_matrix_load(s,ram,7,r[13]);
r[13]+=(r[18]&0x100000u)?8:4;
goto P_0c08f494;
P_0c08f494: /* original f4d8, guest PC 0x0c08f494 */
if(!s->budget--) { s->failed_pc=0x0c08f494u; return 0; }
vf3_matrix_load(s,ram,4,r[13]);
goto P_0c08f496;
P_0c08f496: /* original f54c, guest PC 0x0c08f496 */
if(!s->budget--) { s->failed_pc=0x0c08f496u; return 0; }
vf3_matrix_move(s,5,4);
goto P_0c08f498;
P_0c08f498: /* original f571, guest PC 0x0c08f498 */
if(!s->budget--) { s->failed_pc=0x0c08f498u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[7],r[18],'-');
goto P_0c08f49a;
P_0c08f49a: /* original f65c, guest PC 0x0c08f49a */
if(!s->budget--) { s->failed_pc=0x0c08f49au; return 0; }
vf3_matrix_move(s,6,5);
goto P_0c08f49c;
P_0c08f49c: /* original f633, guest PC 0x0c08f49c */
if(!s->budget--) { s->failed_pc=0x0c08f49cu; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[3],r[18],'/');
goto P_0c08f49e;
P_0c08f49e: /* original fe67, guest PC 0x0c08f49e */
if(!s->budget--) { s->failed_pc=0x0c08f49eu; return 0; }
vf3_matrix_store(s,ram,6,r[14]+r[0]);
goto P_0c08f4a0;
P_0c08f4a0: /* original 7008, guest PC 0x0c08f4a0 */
if(!s->budget--) { s->failed_pc=0x0c08f4a0u; return 0; }
r[0]+=0x00000008u;
goto P_0c08f4a2;
P_0c08f4a2: /* original fe77, guest PC 0x0c08f4a2 */
if(!s->budget--) { s->failed_pc=0x0c08f4a2u; return 0; }
vf3_matrix_store(s,ram,7,r[14]+r[0]);
goto P_0c08f4a4;
P_0c08f4a4: /* original 7008, guest PC 0x0c08f4a4 */
if(!s->budget--) { s->failed_pc=0x0c08f4a4u; return 0; }
r[0]+=0x00000008u;
goto P_0c08f4a6;
P_0c08f4a6: /* original fe47, guest PC 0x0c08f4a6 */
if(!s->budget--) { s->failed_pc=0x0c08f4a6u; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c08f4a8;
P_0c08f4a8: /* original 6df6, guest PC 0x0c08f4a8 */
if(!s->budget--) { s->failed_pc=0x0c08f4a8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c08f4aa;
P_0c08f4aa: /* original 000b, guest PC 0x0c08f4aa */
if(!s->budget--) { s->failed_pc=0x0c08f4aau; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c08f4ac: /* original 6ef6, guest PC 0x0c08f4ac */
if(!s->budget--) { s->failed_pc=0x0c08f4acu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c08f4aeu,s,ram);
P_0c08f548: /* original 2fe6, guest PC 0x0c08f548 */
if(!s->budget--) { s->failed_pc=0x0c08f548u; return 0; }
r[15]-=4; write(ram,r[15],r[14],4);
goto P_0c08f54a;
P_0c08f54a: /* original 6e43, guest PC 0x0c08f54a */
if(!s->budget--) { s->failed_pc=0x0c08f54au; return 0; }
r[14]=r[4];
goto P_0c08f54c;
P_0c08f54c: /* original 2fd6, guest PC 0x0c08f54c */
if(!s->budget--) { s->failed_pc=0x0c08f54cu; return 0; }
r[15]-=4; write(ram,r[15],r[13],4);
goto P_0c08f54e;
P_0c08f54e: /* original 6d53, guest PC 0x0c08f54e */
if(!s->budget--) { s->failed_pc=0x0c08f54eu; return 0; }
r[13]=r[5];
goto P_0c08f550;
P_0c08f550: /* original 4f22, guest PC 0x0c08f550 */
if(!s->budget--) { s->failed_pc=0x0c08f550u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c08f552;
P_0c08f552: /* original 939f, guest PC 0x0c08f552 */
if(!s->budget--) { s->failed_pc=0x0c08f552u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08f694u,2);
goto P_0c08f554;
P_0c08f554: /* original 7ff8, guest PC 0x0c08f554 */
if(!s->budget--) { s->failed_pc=0x0c08f554u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c08f556;
P_0c08f556: /* original 33ec, guest PC 0x0c08f556 */
if(!s->budget--) { s->failed_pc=0x0c08f556u; return 0; }
r[3]+=r[14];
goto P_0c08f558;
P_0c08f558: /* original 2f32, guest PC 0x0c08f558 */
if(!s->budget--) { s->failed_pc=0x0c08f558u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c08f55a;
P_0c08f55a: /* original 929c, guest PC 0x0c08f55a */
if(!s->budget--) { s->failed_pc=0x0c08f55au; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08f696u,2);
goto P_0c08f55c;
P_0c08f55c: /* original 32ec, guest PC 0x0c08f55c */
if(!s->budget--) { s->failed_pc=0x0c08f55cu; return 0; }
r[2]+=r[14];
goto P_0c08f55e;
P_0c08f55e: /* original 1f21, guest PC 0x0c08f55e */
if(!s->budget--) { s->failed_pc=0x0c08f55eu; return 0; }
write(ram,r[15]+4,r[2],4);
goto P_0c08f560;
P_0c08f560: /* original f4d8, guest PC 0x0c08f560 */
if(!s->budget--) { s->failed_pc=0x0c08f560u; return 0; }
vf3_matrix_load(s,ram,4,r[13]);
goto P_0c08f562;
P_0c08f562: /* original f38d, guest PC 0x0c08f562 */
if(!s->budget--) { s->failed_pc=0x0c08f562u; return 0; }
fr[3]=0;
goto P_0c08f564;
P_0c08f564: /* original f345, guest PC 0x0c08f564 */
if(!s->budget--) { s->failed_pc=0x0c08f564u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[4]))!=0);
goto P_0c08f566;
P_0c08f566: /* original 8907, guest PC 0x0c08f566 */
if(!s->budget--) { s->failed_pc=0x0c08f566u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c08f578; }
goto P_0c08f568;
P_0c08f568: /* original 9096, guest PC 0x0c08f568 */
if(!s->budget--) { s->failed_pc=0x0c08f568u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08f698u,2);
goto P_0c08f56a;
P_0c08f56a: /* original 04ee, guest PC 0x0c08f56a */
if(!s->budget--) { s->failed_pc=0x0c08f56au; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c08f56c;
P_0c08f56c: /* original 14d2, guest PC 0x0c08f56c */
if(!s->budget--) { s->failed_pc=0x0c08f56cu; return 0; }
write(ram,r[4]+8,r[13],4);
goto P_0c08f56e;
P_0c08f56e: /* original 55f1, guest PC 0x0c08f56e */
if(!s->budget--) { s->failed_pc=0x0c08f56eu; return 0; }
r[5]=read(ram,r[15]+4,4);
goto P_0c08f570;
P_0c08f570: /* original bf9d, guest PC 0x0c08f570 */
if(!s->budget--) { s->failed_pc=0x0c08f570u; return 0; }
target=0x0c08f4aeu; r[16]=0x0c08f574u;
tmp=read(ram,r[15],4);
r[4]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08f574u) { target=s->pc; goto dispatch; }
goto P_0c08f574;
P_0c08f572: /* original 64f2, guest PC 0x0c08f572 */
if(!s->budget--) { s->failed_pc=0x0c08f572u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c08f574;
P_0c08f574: /* original aff4, guest PC 0x0c08f574 */
if(!s->budget--) { s->failed_pc=0x0c08f574u; return 0; }
r[13]+=0x00000020u;
goto P_0c08f560;
P_0c08f576: /* original 7d20, guest PC 0x0c08f576 */
if(!s->budget--) { s->failed_pc=0x0c08f576u; return 0; }
r[13]+=0x00000020u;
goto P_0c08f578;
P_0c08f578: /* original 7f08, guest PC 0x0c08f578 */
if(!s->budget--) { s->failed_pc=0x0c08f578u; return 0; }
r[15]+=0x00000008u;
goto P_0c08f57a;
P_0c08f57a: /* original 4f26, guest PC 0x0c08f57a */
if(!s->budget--) { s->failed_pc=0x0c08f57au; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c08f57c;
P_0c08f57c: /* original 6df6, guest PC 0x0c08f57c */
if(!s->budget--) { s->failed_pc=0x0c08f57cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c08f57e;
P_0c08f57e: /* original 000b, guest PC 0x0c08f57e */
if(!s->budget--) { s->failed_pc=0x0c08f57eu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c08f580: /* original 6ef6, guest PC 0x0c08f580 */
if(!s->budget--) { s->failed_pc=0x0c08f580u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c08f582u,s,ram);
P_0c08f5be: /* original 2fe6, guest PC 0x0c08f5be */
if(!s->budget--) { s->failed_pc=0x0c08f5beu; return 0; }
r[15]-=4; write(ram,r[15],r[14],4);
goto P_0c08f5c0;
P_0c08f5c0: /* original 6e43, guest PC 0x0c08f5c0 */
if(!s->budget--) { s->failed_pc=0x0c08f5c0u; return 0; }
r[14]=r[4];
return vf3_matrix_family(0x0c08f5c2u,s,ram);
P_0c090e14: /* original 4f22, guest PC 0x0c090e14 */
if(!s->budget--) { s->failed_pc=0x0c090e14u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c090e16;
P_0c090e16: /* original d34b, guest PC 0x0c090e16 */
if(!s->budget--) { s->failed_pc=0x0c090e16u; return 0; }
r[3]=read(ram,0x0c090f44u,4);
goto P_0c090e18;
P_0c090e18: /* original 430b, guest PC 0x0c090e18 */
if(!s->budget--) { s->failed_pc=0x0c090e18u; return 0; }
target=r[3];
r[16]=0x0c090e1cu;
r[14]=r[4];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c090e1cu) { target=s->pc; goto dispatch; }
goto P_0c090e1c;
P_0c090e1a: /* original 6e43, guest PC 0x0c090e1a */
if(!s->budget--) { s->failed_pc=0x0c090e1au; return 0; }
r[14]=r[4];
goto P_0c090e1c;
P_0c090e1c: /* original d24a, guest PC 0x0c090e1c */
if(!s->budget--) { s->failed_pc=0x0c090e1cu; return 0; }
r[2]=read(ram,0x0c090f48u,4);
goto P_0c090e1e;
P_0c090e1e: /* original 420b, guest PC 0x0c090e1e */
if(!s->budget--) { s->failed_pc=0x0c090e1eu; return 0; }
target=r[2];
r[16]=0x0c090e22u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c090e22u) { target=s->pc; goto dispatch; }
goto P_0c090e22;
P_0c090e20: /* original 64e3, guest PC 0x0c090e20 */
if(!s->budget--) { s->failed_pc=0x0c090e20u; return 0; }
r[4]=r[14];
goto P_0c090e22;
P_0c090e22: /* original bed7, guest PC 0x0c090e22 */
if(!s->budget--) { s->failed_pc=0x0c090e22u; return 0; }
target=0x0c090bd4u; r[16]=0x0c090e26u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c090e26u) { target=s->pc; goto dispatch; }
goto P_0c090e26;
P_0c090e24: /* original 64e3, guest PC 0x0c090e24 */
if(!s->budget--) { s->failed_pc=0x0c090e24u; return 0; }
r[4]=r[14];
goto P_0c090e26;
P_0c090e26: /* original d249, guest PC 0x0c090e26 */
if(!s->budget--) { s->failed_pc=0x0c090e26u; return 0; }
r[2]=read(ram,0x0c090f4cu,4);
goto P_0c090e28;
P_0c090e28: /* original 420b, guest PC 0x0c090e28 */
if(!s->budget--) { s->failed_pc=0x0c090e28u; return 0; }
target=r[2];
r[16]=0x0c090e2cu;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c090e2cu) { target=s->pc; goto dispatch; }
goto P_0c090e2c;
P_0c090e2a: /* original 64e3, guest PC 0x0c090e2a */
if(!s->budget--) { s->failed_pc=0x0c090e2au; return 0; }
r[4]=r[14];
goto P_0c090e2c;
P_0c090e2c: /* original d348, guest PC 0x0c090e2c */
if(!s->budget--) { s->failed_pc=0x0c090e2cu; return 0; }
r[3]=read(ram,0x0c090f50u,4);
goto P_0c090e2e;
P_0c090e2e: /* original 430b, guest PC 0x0c090e2e */
if(!s->budget--) { s->failed_pc=0x0c090e2eu; return 0; }
target=r[3];
r[16]=0x0c090e32u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c090e32u) { target=s->pc; goto dispatch; }
goto P_0c090e32;
P_0c090e30: /* original 64e3, guest PC 0x0c090e30 */
if(!s->budget--) { s->failed_pc=0x0c090e30u; return 0; }
r[4]=r[14];
goto P_0c090e32;
P_0c090e32: /* original d248, guest PC 0x0c090e32 */
if(!s->budget--) { s->failed_pc=0x0c090e32u; return 0; }
r[2]=read(ram,0x0c090f54u,4);
goto P_0c090e34;
P_0c090e34: /* original 420b, guest PC 0x0c090e34 */
if(!s->budget--) { s->failed_pc=0x0c090e34u; return 0; }
target=r[2];
r[16]=0x0c090e38u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c090e38u) { target=s->pc; goto dispatch; }
goto P_0c090e38;
P_0c090e36: /* original 64e3, guest PC 0x0c090e36 */
if(!s->budget--) { s->failed_pc=0x0c090e36u; return 0; }
r[4]=r[14];
goto P_0c090e38;
P_0c090e38: /* original b8ca, guest PC 0x0c090e38 */
if(!s->budget--) { s->failed_pc=0x0c090e38u; return 0; }
target=0x0c08ffd0u; r[16]=0x0c090e3cu;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c090e3cu) { target=s->pc; goto dispatch; }
goto P_0c090e3c;
P_0c090e3a: /* original 64e3, guest PC 0x0c090e3a */
if(!s->budget--) { s->failed_pc=0x0c090e3au; return 0; }
r[4]=r[14];
goto P_0c090e3c;
P_0c090e3c: /* original bc3b, guest PC 0x0c090e3c */
if(!s->budget--) { s->failed_pc=0x0c090e3cu; return 0; }
target=0x0c0906b6u; r[16]=0x0c090e40u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c090e40u) { target=s->pc; goto dispatch; }
goto P_0c090e40;
P_0c090e3e: /* original 64e3, guest PC 0x0c090e3e */
if(!s->budget--) { s->failed_pc=0x0c090e3eu; return 0; }
r[4]=r[14];
goto P_0c090e40;
P_0c090e40: /* original d345, guest PC 0x0c090e40 */
if(!s->budget--) { s->failed_pc=0x0c090e40u; return 0; }
r[3]=read(ram,0x0c090f58u,4);
goto P_0c090e42;
P_0c090e42: /* original 430b, guest PC 0x0c090e42 */
if(!s->budget--) { s->failed_pc=0x0c090e42u; return 0; }
target=r[3];
r[16]=0x0c090e46u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c090e46u) { target=s->pc; goto dispatch; }
goto P_0c090e46;
P_0c090e44: /* original 64e3, guest PC 0x0c090e44 */
if(!s->budget--) { s->failed_pc=0x0c090e44u; return 0; }
r[4]=r[14];
goto P_0c090e46;
P_0c090e46: /* original d245, guest PC 0x0c090e46 */
if(!s->budget--) { s->failed_pc=0x0c090e46u; return 0; }
r[2]=read(ram,0x0c090f5cu,4);
goto P_0c090e48;
P_0c090e48: /* original 420b, guest PC 0x0c090e48 */
if(!s->budget--) { s->failed_pc=0x0c090e48u; return 0; }
target=r[2];
r[16]=0x0c090e4cu;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c090e4cu) { target=s->pc; goto dispatch; }
goto P_0c090e4c;
P_0c090e4a: /* original 64e3, guest PC 0x0c090e4a */
if(!s->budget--) { s->failed_pc=0x0c090e4au; return 0; }
r[4]=r[14];
goto P_0c090e4c;
P_0c090e4c: /* original d33e, guest PC 0x0c090e4c */
if(!s->budget--) { s->failed_pc=0x0c090e4cu; return 0; }
r[3]=read(ram,0x0c090f48u,4);
goto P_0c090e4e;
P_0c090e4e: /* original 430b, guest PC 0x0c090e4e */
if(!s->budget--) { s->failed_pc=0x0c090e4eu; return 0; }
target=r[3];
r[16]=0x0c090e52u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c090e52u) { target=s->pc; goto dispatch; }
goto P_0c090e52;
P_0c090e50: /* original 64e3, guest PC 0x0c090e50 */
if(!s->budget--) { s->failed_pc=0x0c090e50u; return 0; }
r[4]=r[14];
goto P_0c090e52;
P_0c090e52: /* original bebf, guest PC 0x0c090e52 */
if(!s->budget--) { s->failed_pc=0x0c090e52u; return 0; }
target=0x0c090bd4u; r[16]=0x0c090e56u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c090e56u) { target=s->pc; goto dispatch; }
goto P_0c090e56;
P_0c090e54: /* original 64e3, guest PC 0x0c090e54 */
if(!s->budget--) { s->failed_pc=0x0c090e54u; return 0; }
r[4]=r[14];
goto P_0c090e56;
P_0c090e56: /* original 50ec, guest PC 0x0c090e56 */
if(!s->budget--) { s->failed_pc=0x0c090e56u; return 0; }
r[0]=read(ram,r[14]+48,4);
goto P_0c090e58;
P_0c090e58: /* original cb04, guest PC 0x0c090e58 */
if(!s->budget--) { s->failed_pc=0x0c090e58u; return 0; }
r[0]|=4u;
goto P_0c090e5a;
P_0c090e5a: /* original 1e0c, guest PC 0x0c090e5a */
if(!s->budget--) { s->failed_pc=0x0c090e5au; return 0; }
write(ram,r[14]+48,r[0],4);
goto P_0c090e5c;
P_0c090e5c: /* original d33b, guest PC 0x0c090e5c */
if(!s->budget--) { s->failed_pc=0x0c090e5cu; return 0; }
r[3]=read(ram,0x0c090f4cu,4);
goto P_0c090e5e;
P_0c090e5e: /* original 430b, guest PC 0x0c090e5e */
if(!s->budget--) { s->failed_pc=0x0c090e5eu; return 0; }
target=r[3];
r[16]=0x0c090e62u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c090e62u) { target=s->pc; goto dispatch; }
goto P_0c090e62;
P_0c090e60: /* original 64e3, guest PC 0x0c090e60 */
if(!s->budget--) { s->failed_pc=0x0c090e60u; return 0; }
r[4]=r[14];
goto P_0c090e62;
P_0c090e62: /* original d23b, guest PC 0x0c090e62 */
if(!s->budget--) { s->failed_pc=0x0c090e62u; return 0; }
r[2]=read(ram,0x0c090f50u,4);
goto P_0c090e64;
P_0c090e64: /* original 420b, guest PC 0x0c090e64 */
if(!s->budget--) { s->failed_pc=0x0c090e64u; return 0; }
target=r[2];
r[16]=0x0c090e68u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c090e68u) { target=s->pc; goto dispatch; }
goto P_0c090e68;
P_0c090e66: /* original 64e3, guest PC 0x0c090e66 */
if(!s->budget--) { s->failed_pc=0x0c090e66u; return 0; }
r[4]=r[14];
goto P_0c090e68;
P_0c090e68: /* original d33a, guest PC 0x0c090e68 */
if(!s->budget--) { s->failed_pc=0x0c090e68u; return 0; }
r[3]=read(ram,0x0c090f54u,4);
goto P_0c090e6a;
P_0c090e6a: /* original 430b, guest PC 0x0c090e6a */
if(!s->budget--) { s->failed_pc=0x0c090e6au; return 0; }
target=r[3];
r[16]=0x0c090e6eu;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c090e6eu) { target=s->pc; goto dispatch; }
goto P_0c090e6e;
P_0c090e6c: /* original 64e3, guest PC 0x0c090e6c */
if(!s->budget--) { s->failed_pc=0x0c090e6cu; return 0; }
r[4]=r[14];
goto P_0c090e6e;
P_0c090e6e: /* original b8af, guest PC 0x0c090e6e */
if(!s->budget--) { s->failed_pc=0x0c090e6eu; return 0; }
target=0x0c08ffd0u; r[16]=0x0c090e72u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c090e72u) { target=s->pc; goto dispatch; }
goto P_0c090e72;
P_0c090e70: /* original 64e3, guest PC 0x0c090e70 */
if(!s->budget--) { s->failed_pc=0x0c090e70u; return 0; }
r[4]=r[14];
goto P_0c090e72;
P_0c090e72: /* original bc20, guest PC 0x0c090e72 */
if(!s->budget--) { s->failed_pc=0x0c090e72u; return 0; }
target=0x0c0906b6u; r[16]=0x0c090e76u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c090e76u) { target=s->pc; goto dispatch; }
goto P_0c090e76;
P_0c090e74: /* original 64e3, guest PC 0x0c090e74 */
if(!s->budget--) { s->failed_pc=0x0c090e74u; return 0; }
r[4]=r[14];
goto P_0c090e76;
P_0c090e76: /* original d238, guest PC 0x0c090e76 */
if(!s->budget--) { s->failed_pc=0x0c090e76u; return 0; }
r[2]=read(ram,0x0c090f58u,4);
goto P_0c090e78;
P_0c090e78: /* original 420b, guest PC 0x0c090e78 */
if(!s->budget--) { s->failed_pc=0x0c090e78u; return 0; }
target=r[2];
r[16]=0x0c090e7cu;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c090e7cu) { target=s->pc; goto dispatch; }
goto P_0c090e7c;
P_0c090e7a: /* original 64e3, guest PC 0x0c090e7a */
if(!s->budget--) { s->failed_pc=0x0c090e7au; return 0; }
r[4]=r[14];
goto P_0c090e7c;
P_0c090e7c: /* original d337, guest PC 0x0c090e7c */
if(!s->budget--) { s->failed_pc=0x0c090e7cu; return 0; }
r[3]=read(ram,0x0c090f5cu,4);
goto P_0c090e7e;
P_0c090e7e: /* original 430b, guest PC 0x0c090e7e */
if(!s->budget--) { s->failed_pc=0x0c090e7eu; return 0; }
target=r[3];
r[16]=0x0c090e82u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c090e82u) { target=s->pc; goto dispatch; }
goto P_0c090e82;
P_0c090e80: /* original 64e3, guest PC 0x0c090e80 */
if(!s->budget--) { s->failed_pc=0x0c090e80u; return 0; }
r[4]=r[14];
goto P_0c090e82;
P_0c090e82: /* original d337, guest PC 0x0c090e82 */
if(!s->budget--) { s->failed_pc=0x0c090e82u; return 0; }
r[3]=read(ram,0x0c090f60u,4);
goto P_0c090e84;
P_0c090e84: /* original e50f, guest PC 0x0c090e84 */
if(!s->budget--) { s->failed_pc=0x0c090e84u; return 0; }
r[5]=0x0000000fu;
goto P_0c090e86;
P_0c090e86: /* original d437, guest PC 0x0c090e86 */
if(!s->budget--) { s->failed_pc=0x0c090e86u; return 0; }
r[4]=read(ram,0x0c090f64u,4);
goto P_0c090e88;
P_0c090e88: /* original 6030, guest PC 0x0c090e88 */
if(!s->budget--) { s->failed_pc=0x0c090e88u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[3],1);
r[0]=tmp;
goto P_0c090e8a;
P_0c090e8a: /* original 6d43, guest PC 0x0c090e8a */
if(!s->budget--) { s->failed_pc=0x0c090e8au; return 0; }
r[13]=r[4];
goto P_0c090e8c;
P_0c090e8c: /* original 600c, guest PC 0x0c090e8c */
if(!s->budget--) { s->failed_pc=0x0c090e8cu; return 0; }
r[0]=r[0]&255u;
goto P_0c090e8e;
P_0c090e8e: /* original 2509, guest PC 0x0c090e8e */
if(!s->budget--) { s->failed_pc=0x0c090e8eu; return 0; }
r[5]&=r[0];
goto P_0c090e90;
P_0c090e90: /* original 6053, guest PC 0x0c090e90 */
if(!s->budget--) { s->failed_pc=0x0c090e90u; return 0; }
r[0]=r[5];
goto P_0c090e92;
P_0c090e92: /* original 4000, guest PC 0x0c090e92 */
if(!s->budget--) { s->failed_pc=0x0c090e92u; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c090e94;
P_0c090e94: /* original 024d, guest PC 0x0c090e94 */
if(!s->budget--) { s->failed_pc=0x0c090e94u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c090e96;
P_0c090e96: /* original 652d, guest PC 0x0c090e96 */
if(!s->budget--) { s->failed_pc=0x0c090e96u; return 0; }
r[5]=r[2]&65535u;
goto P_0c090e98;
P_0c090e98: /* original d233, guest PC 0x0c090e98 */
if(!s->budget--) { s->failed_pc=0x0c090e98u; return 0; }
r[2]=read(ram,0x0c090f68u,4);
goto P_0c090e9a;
P_0c090e9a: /* original 420b, guest PC 0x0c090e9a */
if(!s->budget--) { s->failed_pc=0x0c090e9au; return 0; }
target=r[2];
r[16]=0x0c090e9eu;
r[13]-=r[5];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c090e9eu) { target=s->pc; goto dispatch; }
goto P_0c090e9e;
P_0c090e9c: /* original 3d58, guest PC 0x0c090e9c */
if(!s->budget--) { s->failed_pc=0x0c090e9cu; return 0; }
r[13]-=r[5];
goto P_0c090e9e;
P_0c090e9e: /* original e306, guest PC 0x0c090e9e */
if(!s->budget--) { s->failed_pc=0x0c090e9eu; return 0; }
r[3]=0x00000006u;
goto P_0c090ea0;
P_0c090ea0: /* original 6403, guest PC 0x0c090ea0 */
if(!s->budget--) { s->failed_pc=0x0c090ea0u; return 0; }
r[4]=r[0];
goto P_0c090ea2;
P_0c090ea2: /* original 2439, guest PC 0x0c090ea2 */
if(!s->budget--) { s->failed_pc=0x0c090ea2u; return 0; }
r[4]&=r[3];
goto P_0c090ea4;
P_0c090ea4: /* original d231, guest PC 0x0c090ea4 */
if(!s->budget--) { s->failed_pc=0x0c090ea4u; return 0; }
r[2]=read(ram,0x0c090f6cu,4);
goto P_0c090ea6;
P_0c090ea6: /* original 34dc, guest PC 0x0c090ea6 */
if(!s->budget--) { s->failed_pc=0x0c090ea6u; return 0; }
r[4]+=r[13];
goto P_0c090ea8;
P_0c090ea8: /* original 6441, guest PC 0x0c090ea8 */
if(!s->budget--) { s->failed_pc=0x0c090ea8u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[4],2);
r[4]=tmp;
goto P_0c090eaa;
P_0c090eaa: /* original 644d, guest PC 0x0c090eaa */
if(!s->budget--) { s->failed_pc=0x0c090eaau; return 0; }
r[4]=r[4]&65535u;
goto P_0c090eac;
P_0c090eac: /* original 3d48, guest PC 0x0c090eac */
if(!s->budget--) { s->failed_pc=0x0c090eacu; return 0; }
r[13]-=r[4];
goto P_0c090eae;
P_0c090eae: /* original 65d3, guest PC 0x0c090eae */
if(!s->budget--) { s->failed_pc=0x0c090eaeu; return 0; }
r[5]=r[13];
goto P_0c090eb0;
P_0c090eb0: /* original 420b, guest PC 0x0c090eb0 */
if(!s->budget--) { s->failed_pc=0x0c090eb0u; return 0; }
target=r[2];
r[16]=0x0c090eb4u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c090eb4u) { target=s->pc; goto dispatch; }
goto P_0c090eb4;
P_0c090eb2: /* original 64e3, guest PC 0x0c090eb2 */
if(!s->budget--) { s->failed_pc=0x0c090eb2u; return 0; }
r[4]=r[14];
goto P_0c090eb4;
P_0c090eb4: /* original c72e, guest PC 0x0c090eb4 */
if(!s->budget--) { s->failed_pc=0x0c090eb4u; return 0; }
r[0]=0x0c090f70u;
goto P_0c090eb6;
P_0c090eb6: /* original f908, guest PC 0x0c090eb6 */
if(!s->budget--) { s->failed_pc=0x0c090eb6u; return 0; }
vf3_matrix_load(s,ram,9,r[0]);
goto P_0c090eb8;
P_0c090eb8: /* original e06c, guest PC 0x0c090eb8 */
if(!s->budget--) { s->failed_pc=0x0c090eb8u; return 0; }
r[0]=0x0000006cu;
goto P_0c090eba;
P_0c090eba: /* original fae6, guest PC 0x0c090eba */
if(!s->budget--) { s->failed_pc=0x0c090ebau; return 0; }
vf3_matrix_load(s,ram,10,r[14]+r[0]);
goto P_0c090ebc;
P_0c090ebc: /* original 903f, guest PC 0x0c090ebc */
if(!s->budget--) { s->failed_pc=0x0c090ebcu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c090f3eu,2);
goto P_0c090ebe;
P_0c090ebe: /* original fbe6, guest PC 0x0c090ebe */
if(!s->budget--) { s->failed_pc=0x0c090ebeu; return 0; }
vf3_matrix_load(s,ram,11,r[14]+r[0]);
goto P_0c090ec0;
P_0c090ec0: /* original 7004, guest PC 0x0c090ec0 */
if(!s->budget--) { s->failed_pc=0x0c090ec0u; return 0; }
r[0]+=0x00000004u;
goto P_0c090ec2;
P_0c090ec2: /* original f6e6, guest PC 0x0c090ec2 */
if(!s->budget--) { s->failed_pc=0x0c090ec2u; return 0; }
vf3_matrix_load(s,ram,6,r[14]+r[0]);
goto P_0c090ec4;
P_0c090ec4: /* original 7004, guest PC 0x0c090ec4 */
if(!s->budget--) { s->failed_pc=0x0c090ec4u; return 0; }
r[0]+=0x00000004u;
goto P_0c090ec6;
P_0c090ec6: /* original f8e6, guest PC 0x0c090ec6 */
if(!s->budget--) { s->failed_pc=0x0c090ec6u; return 0; }
vf3_matrix_load(s,ram,8,r[14]+r[0]);
goto P_0c090ec8;
P_0c090ec8: /* original 7040, guest PC 0x0c090ec8 */
if(!s->budget--) { s->failed_pc=0x0c090ec8u; return 0; }
r[0]+=0x00000040u;
goto P_0c090eca;
P_0c090eca: /* original f4e6, guest PC 0x0c090eca */
if(!s->budget--) { s->failed_pc=0x0c090ecau; return 0; }
vf3_matrix_load(s,ram,4,r[14]+r[0]);
goto P_0c090ecc;
P_0c090ecc: /* original 7004, guest PC 0x0c090ecc */
if(!s->budget--) { s->failed_pc=0x0c090eccu; return 0; }
r[0]+=0x00000004u;
goto P_0c090ece;
P_0c090ece: /* original f7e6, guest PC 0x0c090ece */
if(!s->budget--) { s->failed_pc=0x0c090eceu; return 0; }
vf3_matrix_load(s,ram,7,r[14]+r[0]);
goto P_0c090ed0;
P_0c090ed0: /* original 7004, guest PC 0x0c090ed0 */
if(!s->budget--) { s->failed_pc=0x0c090ed0u; return 0; }
r[0]+=0x00000004u;
goto P_0c090ed2;
P_0c090ed2: /* original f5e6, guest PC 0x0c090ed2 */
if(!s->budget--) { s->failed_pc=0x0c090ed2u; return 0; }
vf3_matrix_load(s,ram,5,r[14]+r[0]);
goto P_0c090ed4;
P_0c090ed4: /* original 9034, guest PC 0x0c090ed4 */
if(!s->budget--) { s->failed_pc=0x0c090ed4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c090f40u,2);
goto P_0c090ed6;
P_0c090ed6: /* original 04ee, guest PC 0x0c090ed6 */
if(!s->budget--) { s->failed_pc=0x0c090ed6u; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c090ed8;
P_0c090ed8: /* original e004, guest PC 0x0c090ed8 */
if(!s->budget--) { s->failed_pc=0x0c090ed8u; return 0; }
r[0]=0x00000004u;
goto P_0c090eda;
P_0c090eda: /* original f49a, guest PC 0x0c090eda */
if(!s->budget--) { s->failed_pc=0x0c090edau; return 0; }
vf3_matrix_store(s,ram,9,r[4]);
goto P_0c090edc;
P_0c090edc: /* original f4a7, guest PC 0x0c090edc */
if(!s->budget--) { s->failed_pc=0x0c090edcu; return 0; }
vf3_matrix_store(s,ram,10,r[4]+r[0]);
goto P_0c090ede;
P_0c090ede: /* original e008, guest PC 0x0c090ede */
if(!s->budget--) { s->failed_pc=0x0c090edeu; return 0; }
r[0]=0x00000008u;
goto P_0c090ee0;
P_0c090ee0: /* original f4b7, guest PC 0x0c090ee0 */
if(!s->budget--) { s->failed_pc=0x0c090ee0u; return 0; }
vf3_matrix_store(s,ram,11,r[4]+r[0]);
goto P_0c090ee2;
P_0c090ee2: /* original e00c, guest PC 0x0c090ee2 */
if(!s->budget--) { s->failed_pc=0x0c090ee2u; return 0; }
r[0]=0x0000000cu;
goto P_0c090ee4;
P_0c090ee4: /* original f467, guest PC 0x0c090ee4 */
if(!s->budget--) { s->failed_pc=0x0c090ee4u; return 0; }
vf3_matrix_store(s,ram,6,r[4]+r[0]);
goto P_0c090ee6;
P_0c090ee6: /* original e010, guest PC 0x0c090ee6 */
if(!s->budget--) { s->failed_pc=0x0c090ee6u; return 0; }
r[0]=0x00000010u;
goto P_0c090ee8;
P_0c090ee8: /* original f487, guest PC 0x0c090ee8 */
if(!s->budget--) { s->failed_pc=0x0c090ee8u; return 0; }
vf3_matrix_store(s,ram,8,r[4]+r[0]);
goto P_0c090eea;
P_0c090eea: /* original e014, guest PC 0x0c090eea */
if(!s->budget--) { s->failed_pc=0x0c090eeau; return 0; }
r[0]=0x00000014u;
goto P_0c090eec;
P_0c090eec: /* original f447, guest PC 0x0c090eec */
if(!s->budget--) { s->failed_pc=0x0c090eecu; return 0; }
vf3_matrix_store(s,ram,4,r[4]+r[0]);
goto P_0c090eee;
P_0c090eee: /* original e018, guest PC 0x0c090eee */
if(!s->budget--) { s->failed_pc=0x0c090eeeu; return 0; }
r[0]=0x00000018u;
goto P_0c090ef0;
P_0c090ef0: /* original f477, guest PC 0x0c090ef0 */
if(!s->budget--) { s->failed_pc=0x0c090ef0u; return 0; }
vf3_matrix_store(s,ram,7,r[4]+r[0]);
goto P_0c090ef2;
P_0c090ef2: /* original e01c, guest PC 0x0c090ef2 */
if(!s->budget--) { s->failed_pc=0x0c090ef2u; return 0; }
r[0]=0x0000001cu;
goto P_0c090ef4;
P_0c090ef4: /* original f457, guest PC 0x0c090ef4 */
if(!s->budget--) { s->failed_pc=0x0c090ef4u; return 0; }
vf3_matrix_store(s,ram,5,r[4]+r[0]);
goto P_0c090ef6;
P_0c090ef6: /* original d31f, guest PC 0x0c090ef6 */
if(!s->budget--) { s->failed_pc=0x0c090ef6u; return 0; }
r[3]=read(ram,0x0c090f74u,4);
goto P_0c090ef8;
P_0c090ef8: /* original 430b, guest PC 0x0c090ef8 */
if(!s->budget--) { s->failed_pc=0x0c090ef8u; return 0; }
target=r[3];
r[16]=0x0c090efcu;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c090efcu) { target=s->pc; goto dispatch; }
goto P_0c090efc;
P_0c090efa: /* original 64e3, guest PC 0x0c090efa */
if(!s->budget--) { s->failed_pc=0x0c090efau; return 0; }
r[4]=r[14];
goto P_0c090efc;
P_0c090efc: /* original 4f26, guest PC 0x0c090efc */
if(!s->budget--) { s->failed_pc=0x0c090efcu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c090efe;
P_0c090efe: /* original 9020, guest PC 0x0c090efe */
if(!s->budget--) { s->failed_pc=0x0c090efeu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c090f42u,2);
goto P_0c090f00;
P_0c090f00: /* original e201, guest PC 0x0c090f00 */
if(!s->budget--) { s->failed_pc=0x0c090f00u; return 0; }
r[2]=0x00000001u;
goto P_0c090f02;
P_0c090f02: /* original 0e24, guest PC 0x0c090f02 */
if(!s->budget--) { s->failed_pc=0x0c090f02u; return 0; }
write(ram,r[14]+r[0],r[2],1);
goto P_0c090f04;
P_0c090f04: /* original 6df6, guest PC 0x0c090f04 */
if(!s->budget--) { s->failed_pc=0x0c090f04u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c090f06;
P_0c090f06: /* original 000b, guest PC 0x0c090f06 */
if(!s->budget--) { s->failed_pc=0x0c090f06u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c090f08: /* original 6ef6, guest PC 0x0c090f08 */
if(!s->budget--) { s->failed_pc=0x0c090f08u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c090f0au,s,ram);
P_0c0a028a: /* original 4f22, guest PC 0x0c0a028a */
if(!s->budget--) { s->failed_pc=0x0c0a028au; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0a028c;
P_0c0a028c: /* original d32f, guest PC 0x0c0a028c */
if(!s->budget--) { s->failed_pc=0x0c0a028cu; return 0; }
r[3]=read(ram,0x0c0a034cu,4);
goto P_0c0a028e;
P_0c0a028e: /* original de2e, guest PC 0x0c0a028e */
if(!s->budget--) { s->failed_pc=0x0c0a028eu; return 0; }
r[14]=read(ram,0x0c0a0348u,4);
goto P_0c0a0290;
P_0c0a0290: /* original 7ff8, guest PC 0x0c0a0290 */
if(!s->budget--) { s->failed_pc=0x0c0a0290u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c0a0292;
P_0c0a0292: /* original 1f31, guest PC 0x0c0a0292 */
if(!s->budget--) { s->failed_pc=0x0c0a0292u; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c0a0294;
P_0c0a0294: /* original e307, guest PC 0x0c0a0294 */
if(!s->budget--) { s->failed_pc=0x0c0a0294u; return 0; }
r[3]=0x00000007u;
goto P_0c0a0296;
P_0c0a0296: /* original d22e, guest PC 0x0c0a0296 */
if(!s->budget--) { s->failed_pc=0x0c0a0296u; return 0; }
r[2]=read(ram,0x0c0a0350u,4);
goto P_0c0a0298;
P_0c0a0298: /* original 6422, guest PC 0x0c0a0298 */
if(!s->budget--) { s->failed_pc=0x0c0a0298u; return 0; }
tmp=read(ram,r[2],4);
r[4]=tmp;
goto P_0c0a029a;
P_0c0a029a: /* original 3c48, guest PC 0x0c0a029a */
if(!s->budget--) { s->failed_pc=0x0c0a029au; return 0; }
r[12]-=r[4];
goto P_0c0a029c;
P_0c0a029c: /* original 2fc2, guest PC 0x0c0a029c */
if(!s->budget--) { s->failed_pc=0x0c0a029cu; return 0; }
write(ram,r[15],r[12],4);
goto P_0c0a029e;
P_0c0a029e: /* original e428, guest PC 0x0c0a029e */
if(!s->budget--) { s->failed_pc=0x0c0a029eu; return 0; }
r[4]=0x00000028u;
goto P_0c0a02a0;
P_0c0a02a0: /* original d52c, guest PC 0x0c0a02a0 */
if(!s->budget--) { s->failed_pc=0x0c0a02a0u; return 0; }
r[5]=read(ram,0x0c0a0354u,4);
goto P_0c0a02a2;
P_0c0a02a2: /* original 4c3c, guest PC 0x0c0a02a2 */
if(!s->budget--) { s->failed_pc=0x0c0a02a2u; return 0; }
r[12]=(r[3]&0x80000000u)?((r[3]&31u)?(uint32_t)((int32_t)r[12]>>((-r[3])&31u)):((int32_t)r[12]<0?0xffffffffu:0)):r[12]<<(r[3]&31u);
goto P_0c0a02a4;
P_0c0a02a4: /* original d12c, guest PC 0x0c0a02a4 */
if(!s->budget--) { s->failed_pc=0x0c0a02a4u; return 0; }
r[1]=read(ram,0x0c0a0358u,4);
goto P_0c0a02a6;
P_0c0a02a6: /* original 24cb, guest PC 0x0c0a02a6 */
if(!s->budget--) { s->failed_pc=0x0c0a02a6u; return 0; }
r[4]|=r[12];
goto P_0c0a02a8;
P_0c0a02a8: /* original 410b, guest PC 0x0c0a02a8 */
if(!s->budget--) { s->failed_pc=0x0c0a02a8u; return 0; }
target=r[1];
r[16]=0x0c0a02acu;
r[6]=0x00000001u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a02acu) { target=s->pc; goto dispatch; }
goto P_0c0a02ac;
P_0c0a02aa: /* original e601, guest PC 0x0c0a02aa */
if(!s->budget--) { s->failed_pc=0x0c0a02aau; return 0; }
r[6]=0x00000001u;
goto P_0c0a02ac;
P_0c0a02ac: /* original 9041, guest PC 0x0c0a02ac */
if(!s->budget--) { s->failed_pc=0x0c0a02acu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a0332u,2);
goto P_0c0a02ae;
P_0c0a02ae: /* original e41c, guest PC 0x0c0a02ae */
if(!s->budget--) { s->failed_pc=0x0c0a02aeu; return 0; }
r[4]=0x0000001cu;
goto P_0c0a02b0;
P_0c0a02b0: /* original dd2b, guest PC 0x0c0a02b0 */
if(!s->budget--) { s->failed_pc=0x0c0a02b0u; return 0; }
r[13]=read(ram,0x0c0a0360u,4);
goto P_0c0a02b2;
P_0c0a02b2: /* original 24cb, guest PC 0x0c0a02b2 */
if(!s->budget--) { s->failed_pc=0x0c0a02b2u; return 0; }
r[4]|=r[12];
goto P_0c0a02b4;
P_0c0a02b4: /* original 03ec, guest PC 0x0c0a02b4 */
if(!s->budget--) { s->failed_pc=0x0c0a02b4u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0a02b6;
P_0c0a02b6: /* original db29, guest PC 0x0c0a02b6 */
if(!s->budget--) { s->failed_pc=0x0c0a02b6u; return 0; }
r[11]=read(ram,0x0c0a035cu,4);
goto P_0c0a02b8;
P_0c0a02b8: /* original 2f36, guest PC 0x0c0a02b8 */
if(!s->budget--) { s->failed_pc=0x0c0a02b8u; return 0; }
r[15]-=4; write(ram,r[15],r[3],4);
goto P_0c0a02ba;
P_0c0a02ba: /* original 4d0b, guest PC 0x0c0a02ba */
if(!s->budget--) { s->failed_pc=0x0c0a02bau; return 0; }
target=r[13];
r[16]=0x0c0a02beu;
r[15]-=4; write(ram,r[15],r[11],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a02beu) { target=s->pc; goto dispatch; }
goto P_0c0a02be;
P_0c0a02bc: /* original 2fb6, guest PC 0x0c0a02bc */
if(!s->budget--) { s->failed_pc=0x0c0a02bcu; return 0; }
r[15]-=4; write(ram,r[15],r[11],4);
goto P_0c0a02be;
P_0c0a02be: /* original 903b, guest PC 0x0c0a02be */
if(!s->budget--) { s->failed_pc=0x0c0a02beu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a0338u,2);
goto P_0c0a02c0;
P_0c0a02c0: /* original e420, guest PC 0x0c0a02c0 */
if(!s->budget--) { s->failed_pc=0x0c0a02c0u; return 0; }
r[4]=0x00000020u;
goto P_0c0a02c2;
P_0c0a02c2: /* original 24cb, guest PC 0x0c0a02c2 */
if(!s->budget--) { s->failed_pc=0x0c0a02c2u; return 0; }
r[4]|=r[12];
goto P_0c0a02c4;
P_0c0a02c4: /* original 03ec, guest PC 0x0c0a02c4 */
if(!s->budget--) { s->failed_pc=0x0c0a02c4u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0a02c6;
P_0c0a02c6: /* original 2f36, guest PC 0x0c0a02c6 */
if(!s->budget--) { s->failed_pc=0x0c0a02c6u; return 0; }
r[15]-=4; write(ram,r[15],r[3],4);
goto P_0c0a02c8;
P_0c0a02c8: /* original 4d0b, guest PC 0x0c0a02c8 */
if(!s->budget--) { s->failed_pc=0x0c0a02c8u; return 0; }
target=r[13];
r[16]=0x0c0a02ccu;
r[15]-=4; write(ram,r[15],r[11],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a02ccu) { target=s->pc; goto dispatch; }
goto P_0c0a02cc;
P_0c0a02ca: /* original 2fb6, guest PC 0x0c0a02ca */
if(!s->budget--) { s->failed_pc=0x0c0a02cau; return 0; }
r[15]-=4; write(ram,r[15],r[11],4);
goto P_0c0a02cc;
P_0c0a02cc: /* original 9035, guest PC 0x0c0a02cc */
if(!s->budget--) { s->failed_pc=0x0c0a02ccu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a033au,2);
goto P_0c0a02ce;
P_0c0a02ce: /* original e424, guest PC 0x0c0a02ce */
if(!s->budget--) { s->failed_pc=0x0c0a02ceu; return 0; }
r[4]=0x00000024u;
goto P_0c0a02d0;
P_0c0a02d0: /* original 24cb, guest PC 0x0c0a02d0 */
if(!s->budget--) { s->failed_pc=0x0c0a02d0u; return 0; }
r[4]|=r[12];
goto P_0c0a02d2;
P_0c0a02d2: /* original 03ec, guest PC 0x0c0a02d2 */
if(!s->budget--) { s->failed_pc=0x0c0a02d2u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0a02d4;
P_0c0a02d4: /* original 2f36, guest PC 0x0c0a02d4 */
if(!s->budget--) { s->failed_pc=0x0c0a02d4u; return 0; }
r[15]-=4; write(ram,r[15],r[3],4);
goto P_0c0a02d6;
P_0c0a02d6: /* original 4d0b, guest PC 0x0c0a02d6 */
if(!s->budget--) { s->failed_pc=0x0c0a02d6u; return 0; }
target=r[13];
r[16]=0x0c0a02dau;
r[15]-=4; write(ram,r[15],r[11],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a02dau) { target=s->pc; goto dispatch; }
goto P_0c0a02da;
P_0c0a02d8: /* original 2fb6, guest PC 0x0c0a02d8 */
if(!s->budget--) { s->failed_pc=0x0c0a02d8u; return 0; }
r[15]-=4; write(ram,r[15],r[11],4);
goto P_0c0a02da;
P_0c0a02da: /* original 902f, guest PC 0x0c0a02da */
if(!s->budget--) { s->failed_pc=0x0c0a02dau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a033cu,2);
goto P_0c0a02dc;
P_0c0a02dc: /* original e428, guest PC 0x0c0a02dc */
if(!s->budget--) { s->failed_pc=0x0c0a02dcu; return 0; }
r[4]=0x00000028u;
goto P_0c0a02de;
P_0c0a02de: /* original 24cb, guest PC 0x0c0a02de */
if(!s->budget--) { s->failed_pc=0x0c0a02deu; return 0; }
r[4]|=r[12];
goto P_0c0a02e0;
P_0c0a02e0: /* original 03ec, guest PC 0x0c0a02e0 */
if(!s->budget--) { s->failed_pc=0x0c0a02e0u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0a02e2;
P_0c0a02e2: /* original 2f36, guest PC 0x0c0a02e2 */
if(!s->budget--) { s->failed_pc=0x0c0a02e2u; return 0; }
r[15]-=4; write(ram,r[15],r[3],4);
goto P_0c0a02e4;
P_0c0a02e4: /* original 4d0b, guest PC 0x0c0a02e4 */
if(!s->budget--) { s->failed_pc=0x0c0a02e4u; return 0; }
target=r[13];
r[16]=0x0c0a02e8u;
r[15]-=4; write(ram,r[15],r[11],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a02e8u) { target=s->pc; goto dispatch; }
goto P_0c0a02e8;
P_0c0a02e6: /* original 2fb6, guest PC 0x0c0a02e6 */
if(!s->budget--) { s->failed_pc=0x0c0a02e6u; return 0; }
r[15]-=4; write(ram,r[15],r[11],4);
goto P_0c0a02e8;
P_0c0a02e8: /* original 9029, guest PC 0x0c0a02e8 */
if(!s->budget--) { s->failed_pc=0x0c0a02e8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a033eu,2);
goto P_0c0a02ea;
P_0c0a02ea: /* original e307, guest PC 0x0c0a02ea */
if(!s->budget--) { s->failed_pc=0x0c0a02eau; return 0; }
r[3]=0x00000007u;
goto P_0c0a02ec;
P_0c0a02ec: /* original e601, guest PC 0x0c0a02ec */
if(!s->budget--) { s->failed_pc=0x0c0a02ecu; return 0; }
r[6]=0x00000001u;
goto P_0c0a02ee;
P_0c0a02ee: /* original 04ec, guest PC 0x0c0a02ee */
if(!s->budget--) { s->failed_pc=0x0c0a02eeu; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0a02f0;
P_0c0a02f0: /* original d01c, guest PC 0x0c0a02f0 */
if(!s->budget--) { s->failed_pc=0x0c0a02f0u; return 0; }
r[0]=read(ram,0x0c0a0364u,4);
goto P_0c0a02f2;
P_0c0a02f2: /* original 044c, guest PC 0x0c0a02f2 */
if(!s->budget--) { s->failed_pc=0x0c0a02f2u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c0a02f4;
P_0c0a02f4: /* original 9024, guest PC 0x0c0a02f4 */
if(!s->budget--) { s->failed_pc=0x0c0a02f4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a0340u,2);
goto P_0c0a02f6;
P_0c0a02f6: /* original 0e44, guest PC 0x0c0a02f6 */
if(!s->budget--) { s->failed_pc=0x0c0a02f6u; return 0; }
write(ram,r[14]+r[0],r[4],1);
goto P_0c0a02f8;
P_0c0a02f8: /* original 70f9, guest PC 0x0c0a02f8 */
if(!s->budget--) { s->failed_pc=0x0c0a02f8u; return 0; }
r[0]+=0xfffffff9u;
goto P_0c0a02fa;
P_0c0a02fa: /* original 04ec, guest PC 0x0c0a02fa */
if(!s->budget--) { s->failed_pc=0x0c0a02fau; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0a02fc;
P_0c0a02fc: /* original 52f8, guest PC 0x0c0a02fc */
if(!s->budget--) { s->failed_pc=0x0c0a02fcu; return 0; }
r[2]=read(ram,r[15]+32,4);
goto P_0c0a02fe;
P_0c0a02fe: /* original 4400, guest PC 0x0c0a02fe */
if(!s->budget--) { s->failed_pc=0x0c0a02feu; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c0a0300;
P_0c0a0300: /* original 951e, guest PC 0x0c0a0300 */
if(!s->budget--) { s->failed_pc=0x0c0a0300u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a0340u,2);
goto P_0c0a0302;
P_0c0a0302: /* original 740e, guest PC 0x0c0a0302 */
if(!s->budget--) { s->failed_pc=0x0c0a0302u; return 0; }
r[4]+=0x0000000eu;
goto P_0c0a0304;
P_0c0a0304: /* original 423c, guest PC 0x0c0a0304 */
if(!s->budget--) { s->failed_pc=0x0c0a0304u; return 0; }
r[2]=(r[3]&0x80000000u)?((r[3]&31u)?(uint32_t)((int32_t)r[2]>>((-r[3])&31u)):((int32_t)r[2]<0?0xffffffffu:0)):r[2]<<(r[3]&31u);
goto P_0c0a0306;
P_0c0a0306: /* original 4400, guest PC 0x0c0a0306 */
if(!s->budget--) { s->failed_pc=0x0c0a0306u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c0a0308;
P_0c0a0308: /* original 242b, guest PC 0x0c0a0308 */
if(!s->budget--) { s->failed_pc=0x0c0a0308u; return 0; }
r[4]|=r[2];
goto P_0c0a030a;
P_0c0a030a: /* original d213, guest PC 0x0c0a030a */
if(!s->budget--) { s->failed_pc=0x0c0a030au; return 0; }
r[2]=read(ram,0x0c0a0358u,4);
goto P_0c0a030c;
P_0c0a030c: /* original 420b, guest PC 0x0c0a030c */
if(!s->budget--) { s->failed_pc=0x0c0a030cu; return 0; }
target=r[2];
r[16]=0x0c0a0310u;
r[5]+=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a0310u) { target=s->pc; goto dispatch; }
goto P_0c0a0310;
P_0c0a030e: /* original 35ec, guest PC 0x0c0a030e */
if(!s->budget--) { s->failed_pc=0x0c0a030eu; return 0; }
r[5]+=r[14];
goto P_0c0a0310;
P_0c0a0310: /* original 55f9, guest PC 0x0c0a0310 */
if(!s->budget--) { s->failed_pc=0x0c0a0310u; return 0; }
r[5]=read(ram,r[15]+36,4);
goto P_0c0a0312;
P_0c0a0312: /* original e3fa, guest PC 0x0c0a0312 */
if(!s->budget--) { s->failed_pc=0x0c0a0312u; return 0; }
r[3]=0xfffffffau;
goto P_0c0a0314;
P_0c0a0314: /* original 9415, guest PC 0x0c0a0314 */
if(!s->budget--) { s->failed_pc=0x0c0a0314u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a0342u,2);
goto P_0c0a0316;
P_0c0a0316: /* original 5553, guest PC 0x0c0a0316 */
if(!s->budget--) { s->failed_pc=0x0c0a0316u; return 0; }
r[5]=read(ram,r[5]+12,4);
goto P_0c0a0318;
P_0c0a0318: /* original 453c, guest PC 0x0c0a0318 */
if(!s->budget--) { s->failed_pc=0x0c0a0318u; return 0; }
r[5]=(r[3]&0x80000000u)?((r[3]&31u)?(uint32_t)((int32_t)r[5]>>((-r[3])&31u)):((int32_t)r[5]<0?0xffffffffu:0)):r[5]<<(r[3]&31u);
goto P_0c0a031a;
P_0c0a031a: /* original 2f56, guest PC 0x0c0a031a */
if(!s->budget--) { s->failed_pc=0x0c0a031au; return 0; }
r[15]-=4; write(ram,r[15],r[5],4);
goto P_0c0a031c;
P_0c0a031c: /* original d212, guest PC 0x0c0a031c */
if(!s->budget--) { s->failed_pc=0x0c0a031cu; return 0; }
r[2]=read(ram,0x0c0a0368u,4);
goto P_0c0a031e;
P_0c0a031e: /* original 4d0b, guest PC 0x0c0a031e */
if(!s->budget--) { s->failed_pc=0x0c0a031eu; return 0; }
target=r[13];
r[16]=0x0c0a0322u;
r[15]-=4; write(ram,r[15],r[2],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a0322u) { target=s->pc; goto dispatch; }
goto P_0c0a0322;
P_0c0a0320: /* original 2f26, guest PC 0x0c0a0320 */
if(!s->budget--) { s->failed_pc=0x0c0a0320u; return 0; }
r[15]-=4; write(ram,r[15],r[2],4);
goto P_0c0a0322;
P_0c0a0322: /* original 7f30, guest PC 0x0c0a0322 */
if(!s->budget--) { s->failed_pc=0x0c0a0322u; return 0; }
r[15]+=0x00000030u;
goto P_0c0a0324;
P_0c0a0324: /* original 4f26, guest PC 0x0c0a0324 */
if(!s->budget--) { s->failed_pc=0x0c0a0324u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a0326;
P_0c0a0326: /* original 6bf6, guest PC 0x0c0a0326 */
if(!s->budget--) { s->failed_pc=0x0c0a0326u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0a0328;
P_0c0a0328: /* original 6cf6, guest PC 0x0c0a0328 */
if(!s->budget--) { s->failed_pc=0x0c0a0328u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0a032a;
P_0c0a032a: /* original 6df6, guest PC 0x0c0a032a */
if(!s->budget--) { s->failed_pc=0x0c0a032au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0a032c;
P_0c0a032c: /* original 000b, guest PC 0x0c0a032c */
if(!s->budget--) { s->failed_pc=0x0c0a032cu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0a032e: /* original 6ef6, guest PC 0x0c0a032e */
if(!s->budget--) { s->failed_pc=0x0c0a032eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0a0330u,s,ram);
P_0c0a7302: /* original 4f22, guest PC 0x0c0a7302 */
if(!s->budget--) { s->failed_pc=0x0c0a7302u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0a7304;
P_0c0a7304: /* original 223b, guest PC 0x0c0a7304 */
if(!s->budget--) { s->failed_pc=0x0c0a7304u; return 0; }
r[2]|=r[3];
goto P_0c0a7306;
P_0c0a7306: /* original bfcb, guest PC 0x0c0a7306 */
if(!s->budget--) { s->failed_pc=0x0c0a7306u; return 0; }
target=0x0c0a72a0u; r[16]=0x0c0a730au;
write(ram,r[14],r[2],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a730au) { target=s->pc; goto dispatch; }
goto P_0c0a730a;
P_0c0a7308: /* original 2e22, guest PC 0x0c0a7308 */
if(!s->budget--) { s->failed_pc=0x0c0a7308u; return 0; }
write(ram,r[14],r[2],4);
goto P_0c0a730a;
P_0c0a730a: /* original 61e2, guest PC 0x0c0a730a */
if(!s->budget--) { s->failed_pc=0x0c0a730au; return 0; }
tmp=read(ram,r[14],4);
r[1]=tmp;
goto P_0c0a730c;
P_0c0a730c: /* original d331, guest PC 0x0c0a730c */
if(!s->budget--) { s->failed_pc=0x0c0a730cu; return 0; }
r[3]=read(ram,0x0c0a73d4u,4);
goto P_0c0a730e;
P_0c0a730e: /* original 9458, guest PC 0x0c0a730e */
if(!s->budget--) { s->failed_pc=0x0c0a730eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a73c2u,2);
goto P_0c0a7310;
P_0c0a7310: /* original d231, guest PC 0x0c0a7310 */
if(!s->budget--) { s->failed_pc=0x0c0a7310u; return 0; }
r[2]=read(ram,0x0c0a73d8u,4);
goto P_0c0a7312;
P_0c0a7312: /* original 2139, guest PC 0x0c0a7312 */
if(!s->budget--) { s->failed_pc=0x0c0a7312u; return 0; }
r[1]&=r[3];
goto P_0c0a7314;
P_0c0a7314: /* original 420b, guest PC 0x0c0a7314 */
if(!s->budget--) { s->failed_pc=0x0c0a7314u; return 0; }
target=r[2];
r[16]=0x0c0a7318u;
write(ram,r[14],r[1],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a7318u) { target=s->pc; goto dispatch; }
goto P_0c0a7318;
P_0c0a7316: /* original 2e12, guest PC 0x0c0a7316 */
if(!s->budget--) { s->failed_pc=0x0c0a7316u; return 0; }
write(ram,r[14],r[1],4);
goto P_0c0a7318;
P_0c0a7318: /* original d330, guest PC 0x0c0a7318 */
if(!s->budget--) { s->failed_pc=0x0c0a7318u; return 0; }
r[3]=read(ram,0x0c0a73dcu,4);
goto P_0c0a731a;
P_0c0a731a: /* original 6032, guest PC 0x0c0a731a */
if(!s->budget--) { s->failed_pc=0x0c0a731au; return 0; }
tmp=read(ram,r[3],4);
r[0]=tmp;
goto P_0c0a731c;
P_0c0a731c: /* original 8800, guest PC 0x0c0a731c */
if(!s->budget--) { s->failed_pc=0x0c0a731cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000000u)!=0);
goto P_0c0a731e;
P_0c0a731e: /* original 8912, guest PC 0x0c0a731e */
if(!s->budget--) { s->failed_pc=0x0c0a731eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a7346; }
goto P_0c0a7320;
P_0c0a7320: /* original 8801, guest PC 0x0c0a7320 */
if(!s->budget--) { s->failed_pc=0x0c0a7320u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c0a7322;
P_0c0a7322: /* original 8910, guest PC 0x0c0a7322 */
if(!s->budget--) { s->failed_pc=0x0c0a7322u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a7346; }
goto P_0c0a7324;
P_0c0a7324: /* original 8802, guest PC 0x0c0a7324 */
if(!s->budget--) { s->failed_pc=0x0c0a7324u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c0a7326;
P_0c0a7326: /* original 890e, guest PC 0x0c0a7326 */
if(!s->budget--) { s->failed_pc=0x0c0a7326u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a7346; }
goto P_0c0a7328;
P_0c0a7328: /* original 8803, guest PC 0x0c0a7328 */
if(!s->budget--) { s->failed_pc=0x0c0a7328u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000003u)!=0);
goto P_0c0a732a;
P_0c0a732a: /* original 890c, guest PC 0x0c0a732a */
if(!s->budget--) { s->failed_pc=0x0c0a732au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a7346; }
goto P_0c0a732c;
P_0c0a732c: /* original 8804, guest PC 0x0c0a732c */
if(!s->budget--) { s->failed_pc=0x0c0a732cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000004u)!=0);
goto P_0c0a732e;
P_0c0a732e: /* original 890a, guest PC 0x0c0a732e */
if(!s->budget--) { s->failed_pc=0x0c0a732eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a7346; }
goto P_0c0a7330;
P_0c0a7330: /* original 880a, guest PC 0x0c0a7330 */
if(!s->budget--) { s->failed_pc=0x0c0a7330u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000au)!=0);
goto P_0c0a7332;
P_0c0a7332: /* original 8908, guest PC 0x0c0a7332 */
if(!s->budget--) { s->failed_pc=0x0c0a7332u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a7346; }
goto P_0c0a7334;
P_0c0a7334: /* original 880b, guest PC 0x0c0a7334 */
if(!s->budget--) { s->failed_pc=0x0c0a7334u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000bu)!=0);
goto P_0c0a7336;
P_0c0a7336: /* original 8906, guest PC 0x0c0a7336 */
if(!s->budget--) { s->failed_pc=0x0c0a7336u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a7346; }
goto P_0c0a7338;
P_0c0a7338: /* original 880c, guest PC 0x0c0a7338 */
if(!s->budget--) { s->failed_pc=0x0c0a7338u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000cu)!=0);
goto P_0c0a733a;
P_0c0a733a: /* original 8904, guest PC 0x0c0a733a */
if(!s->budget--) { s->failed_pc=0x0c0a733au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a7346; }
goto P_0c0a733c;
P_0c0a733c: /* original 880d, guest PC 0x0c0a733c */
if(!s->budget--) { s->failed_pc=0x0c0a733cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000du)!=0);
goto P_0c0a733e;
P_0c0a733e: /* original 8902, guest PC 0x0c0a733e */
if(!s->budget--) { s->failed_pc=0x0c0a733eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a7346; }
goto P_0c0a7340;
P_0c0a7340: /* original 880e, guest PC 0x0c0a7340 */
if(!s->budget--) { s->failed_pc=0x0c0a7340u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000eu)!=0);
goto P_0c0a7342;
P_0c0a7342: /* original 8900, guest PC 0x0c0a7342 */
if(!s->budget--) { s->failed_pc=0x0c0a7342u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a7346; }
goto P_0c0a7344;
P_0c0a7344: /* original 8814, guest PC 0x0c0a7344 */
if(!s->budget--) { s->failed_pc=0x0c0a7344u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000014u)!=0);
goto P_0c0a7346;
P_0c0a7346: /* original c726, guest PC 0x0c0a7346 */
if(!s->budget--) { s->failed_pc=0x0c0a7346u; return 0; }
r[0]=0x0c0a73e0u;
goto P_0c0a7348;
P_0c0a7348: /* original f308, guest PC 0x0c0a7348 */
if(!s->budget--) { s->failed_pc=0x0c0a7348u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c0a734a;
P_0c0a734a: /* original 903b, guest PC 0x0c0a734a */
if(!s->budget--) { s->failed_pc=0x0c0a734au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a73c4u,2);
goto P_0c0a734c;
P_0c0a734c: /* original fe37, guest PC 0x0c0a734c */
if(!s->budget--) { s->failed_pc=0x0c0a734cu; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0a734e;
P_0c0a734e: /* original c725, guest PC 0x0c0a734e */
if(!s->budget--) { s->failed_pc=0x0c0a734eu; return 0; }
r[0]=0x0c0a73e4u;
goto P_0c0a7350;
P_0c0a7350: /* original f308, guest PC 0x0c0a7350 */
if(!s->budget--) { s->failed_pc=0x0c0a7350u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c0a7352;
P_0c0a7352: /* original 9038, guest PC 0x0c0a7352 */
if(!s->budget--) { s->failed_pc=0x0c0a7352u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a73c6u,2);
goto P_0c0a7354;
P_0c0a7354: /* original fe37, guest PC 0x0c0a7354 */
if(!s->budget--) { s->failed_pc=0x0c0a7354u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0a7356;
P_0c0a7356: /* original c724, guest PC 0x0c0a7356 */
if(!s->budget--) { s->failed_pc=0x0c0a7356u; return 0; }
r[0]=0x0c0a73e8u;
goto P_0c0a7358;
P_0c0a7358: /* original f308, guest PC 0x0c0a7358 */
if(!s->budget--) { s->failed_pc=0x0c0a7358u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c0a735a;
P_0c0a735a: /* original 9035, guest PC 0x0c0a735a */
if(!s->budget--) { s->failed_pc=0x0c0a735au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a73c8u,2);
goto P_0c0a735c;
P_0c0a735c: /* original fe37, guest PC 0x0c0a735c */
if(!s->budget--) { s->failed_pc=0x0c0a735cu; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0a735e;
P_0c0a735e: /* original c723, guest PC 0x0c0a735e */
if(!s->budget--) { s->failed_pc=0x0c0a735eu; return 0; }
r[0]=0x0c0a73ecu;
goto P_0c0a7360;
P_0c0a7360: /* original f308, guest PC 0x0c0a7360 */
if(!s->budget--) { s->failed_pc=0x0c0a7360u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c0a7362;
P_0c0a7362: /* original 9031, guest PC 0x0c0a7362 */
if(!s->budget--) { s->failed_pc=0x0c0a7362u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a73c8u,2);
goto P_0c0a7364;
P_0c0a7364: /* original fe37, guest PC 0x0c0a7364 */
if(!s->budget--) { s->failed_pc=0x0c0a7364u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0a7366;
P_0c0a7366: /* original c722, guest PC 0x0c0a7366 */
if(!s->budget--) { s->failed_pc=0x0c0a7366u; return 0; }
r[0]=0x0c0a73f0u;
goto P_0c0a7368;
P_0c0a7368: /* original f308, guest PC 0x0c0a7368 */
if(!s->budget--) { s->failed_pc=0x0c0a7368u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c0a736a;
P_0c0a736a: /* original 902d, guest PC 0x0c0a736a */
if(!s->budget--) { s->failed_pc=0x0c0a736au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a73c8u,2);
goto P_0c0a736c;
P_0c0a736c: /* original fe37, guest PC 0x0c0a736c */
if(!s->budget--) { s->failed_pc=0x0c0a736cu; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0a736e;
P_0c0a736e: /* original c721, guest PC 0x0c0a736e */
if(!s->budget--) { s->failed_pc=0x0c0a736eu; return 0; }
r[0]=0x0c0a73f4u;
goto P_0c0a7370;
P_0c0a7370: /* original f708, guest PC 0x0c0a7370 */
if(!s->budget--) { s->failed_pc=0x0c0a7370u; return 0; }
vf3_matrix_load(s,ram,7,r[0]);
goto P_0c0a7372;
P_0c0a7372: /* original c721, guest PC 0x0c0a7372 */
if(!s->budget--) { s->failed_pc=0x0c0a7372u; return 0; }
r[0]=0x0c0a73f8u;
goto P_0c0a7374;
P_0c0a7374: /* original d321, guest PC 0x0c0a7374 */
if(!s->budget--) { s->failed_pc=0x0c0a7374u; return 0; }
r[3]=read(ram,0x0c0a73fcu,4);
goto P_0c0a7376;
P_0c0a7376: /* original f608, guest PC 0x0c0a7376 */
if(!s->budget--) { s->failed_pc=0x0c0a7376u; return 0; }
vf3_matrix_load(s,ram,6,r[0]);
goto P_0c0a7378;
P_0c0a7378: /* original ff8d, guest PC 0x0c0a7378 */
if(!s->budget--) { s->failed_pc=0x0c0a7378u; return 0; }
fr[15]=0;
goto P_0c0a737a;
P_0c0a737a: /* original f5fc, guest PC 0x0c0a737a */
if(!s->budget--) { s->failed_pc=0x0c0a737au; return 0; }
vf3_matrix_move(s,5,15);
goto P_0c0a737c;
P_0c0a737c: /* original 430b, guest PC 0x0c0a737c */
if(!s->budget--) { s->failed_pc=0x0c0a737cu; return 0; }
target=r[3];
r[16]=0x0c0a7380u;
vf3_matrix_move(s,4,15);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a7380u) { target=s->pc; goto dispatch; }
goto P_0c0a7380;
P_0c0a737e: /* original f4fc, guest PC 0x0c0a737e */
if(!s->budget--) { s->failed_pc=0x0c0a737eu; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c0a7380;
P_0c0a7380: /* original 4f26, guest PC 0x0c0a7380 */
if(!s->budget--) { s->failed_pc=0x0c0a7380u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a7382;
P_0c0a7382: /* original f5fc, guest PC 0x0c0a7382 */
if(!s->budget--) { s->failed_pc=0x0c0a7382u; return 0; }
vf3_matrix_move(s,5,15);
goto P_0c0a7384;
P_0c0a7384: /* original f4fc, guest PC 0x0c0a7384 */
if(!s->budget--) { s->failed_pc=0x0c0a7384u; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c0a7386;
P_0c0a7386: /* original d21e, guest PC 0x0c0a7386 */
if(!s->budget--) { s->failed_pc=0x0c0a7386u; return 0; }
r[2]=read(ram,0x0c0a7400u,4);
goto P_0c0a7388;
P_0c0a7388: /* original fff9, guest PC 0x0c0a7388 */
if(!s->budget--) { s->failed_pc=0x0c0a7388u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0a738a;
P_0c0a738a: /* original 422b, guest PC 0x0c0a738a */
if(!s->budget--) { s->failed_pc=0x0c0a738au; return 0; }
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
P_0c0a738c: /* original 6ef6, guest PC 0x0c0a738c */
if(!s->budget--) { s->failed_pc=0x0c0a738cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0a738eu,s,ram);
P_0c0adc72: /* original 4f22, guest PC 0x0c0adc72 */
if(!s->budget--) { s->failed_pc=0x0c0adc72u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0adc74;
P_0c0adc74: /* original d359, guest PC 0x0c0adc74 */
if(!s->budget--) { s->failed_pc=0x0c0adc74u; return 0; }
r[3]=read(ram,0x0c0adddcu,4);
goto P_0c0adc76;
P_0c0adc76: /* original 7ff4, guest PC 0x0c0adc76 */
if(!s->budget--) { s->failed_pc=0x0c0adc76u; return 0; }
r[15]+=0xfffffff4u;
goto P_0c0adc78;
P_0c0adc78: /* original 2f32, guest PC 0x0c0adc78 */
if(!s->budget--) { s->failed_pc=0x0c0adc78u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c0adc7a;
P_0c0adc7a: /* original 67f3, guest PC 0x0c0adc7a */
if(!s->budget--) { s->failed_pc=0x0c0adc7au; return 0; }
r[7]=r[15];
goto P_0c0adc7c;
P_0c0adc7c: /* original 91a1, guest PC 0x0c0adc7c */
if(!s->budget--) { s->failed_pc=0x0c0adc7cu; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0addc2u,2);
goto P_0c0adc7e;
P_0c0adc7e: /* original 6ef3, guest PC 0x0c0adc7e */
if(!s->budget--) { s->failed_pc=0x0c0adc7eu; return 0; }
r[14]=r[15];
goto P_0c0adc80;
P_0c0adc80: /* original 8461, guest PC 0x0c0adc80 */
if(!s->budget--) { s->failed_pc=0x0c0adc80u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[6]+1,1);
goto P_0c0adc82;
P_0c0adc82: /* original 7e04, guest PC 0x0c0adc82 */
if(!s->budget--) { s->failed_pc=0x0c0adc82u; return 0; }
r[14]+=0x00000004u;
goto P_0c0adc84;
P_0c0adc84: /* original 314c, guest PC 0x0c0adc84 */
if(!s->budget--) { s->failed_pc=0x0c0adc84u; return 0; }
r[1]+=r[4];
goto P_0c0adc86;
P_0c0adc86: /* original 2100, guest PC 0x0c0adc86 */
if(!s->budget--) { s->failed_pc=0x0c0adc86u; return 0; }
write(ram,r[1],r[0],1);
goto P_0c0adc88;
P_0c0adc88: /* original 7704, guest PC 0x0c0adc88 */
if(!s->budget--) { s->failed_pc=0x0c0adc88u; return 0; }
r[7]+=0x00000004u;
goto P_0c0adc8a;
P_0c0adc8a: /* original 929b, guest PC 0x0c0adc8a */
if(!s->budget--) { s->failed_pc=0x0c0adc8au; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0addc4u,2);
goto P_0c0adc8c;
P_0c0adc8c: /* original 8462, guest PC 0x0c0adc8c */
if(!s->budget--) { s->failed_pc=0x0c0adc8cu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[6]+2,1);
goto P_0c0adc8e;
P_0c0adc8e: /* original 324c, guest PC 0x0c0adc8e */
if(!s->budget--) { s->failed_pc=0x0c0adc8eu; return 0; }
r[2]+=r[4];
goto P_0c0adc90;
P_0c0adc90: /* original 2200, guest PC 0x0c0adc90 */
if(!s->budget--) { s->failed_pc=0x0c0adc90u; return 0; }
write(ram,r[2],r[0],1);
goto P_0c0adc92;
P_0c0adc92: /* original 9198, guest PC 0x0c0adc92 */
if(!s->budget--) { s->failed_pc=0x0c0adc92u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0addc6u,2);
goto P_0c0adc94;
P_0c0adc94: /* original 8463, guest PC 0x0c0adc94 */
if(!s->budget--) { s->failed_pc=0x0c0adc94u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[6]+3,1);
goto P_0c0adc96;
P_0c0adc96: /* original 314c, guest PC 0x0c0adc96 */
if(!s->budget--) { s->failed_pc=0x0c0adc96u; return 0; }
r[1]+=r[4];
goto P_0c0adc98;
P_0c0adc98: /* original 2100, guest PC 0x0c0adc98 */
if(!s->budget--) { s->failed_pc=0x0c0adc98u; return 0; }
write(ram,r[1],r[0],1);
goto P_0c0adc9a;
P_0c0adc9a: /* original 8467, guest PC 0x0c0adc9a */
if(!s->budget--) { s->failed_pc=0x0c0adc9au; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[6]+7,1);
goto P_0c0adc9c;
P_0c0adc9c: /* original d350, guest PC 0x0c0adc9c */
if(!s->budget--) { s->failed_pc=0x0c0adc9cu; return 0; }
r[3]=read(ram,0x0c0adde0u,4);
goto P_0c0adc9e;
P_0c0adc9e: /* original 600c, guest PC 0x0c0adc9e */
if(!s->budget--) { s->failed_pc=0x0c0adc9eu; return 0; }
r[0]=r[0]&255u;
goto P_0c0adca0;
P_0c0adca0: /* original d250, guest PC 0x0c0adca0 */
if(!s->budget--) { s->failed_pc=0x0c0adca0u; return 0; }
r[2]=read(ram,0x0c0adde4u,4);
goto P_0c0adca2;
P_0c0adca2: /* original 4028, guest PC 0x0c0adca2 */
if(!s->budget--) { s->failed_pc=0x0c0adca2u; return 0; }
r[0]<<=16;
goto P_0c0adca4;
P_0c0adca4: /* original 4018, guest PC 0x0c0adca4 */
if(!s->budget--) { s->failed_pc=0x0c0adca4u; return 0; }
r[0]<<=8;
goto P_0c0adca6;
P_0c0adca6: /* original 2039, guest PC 0x0c0adca6 */
if(!s->budget--) { s->failed_pc=0x0c0adca6u; return 0; }
r[0]&=r[3];
goto P_0c0adca8;
P_0c0adca8: /* original 6103, guest PC 0x0c0adca8 */
if(!s->budget--) { s->failed_pc=0x0c0adca8u; return 0; }
r[1]=r[0];
goto P_0c0adcaa;
P_0c0adcaa: /* original 8466, guest PC 0x0c0adcaa */
if(!s->budget--) { s->failed_pc=0x0c0adcaau; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[6]+6,1);
goto P_0c0adcac;
P_0c0adcac: /* original 600c, guest PC 0x0c0adcac */
if(!s->budget--) { s->failed_pc=0x0c0adcacu; return 0; }
r[0]=r[0]&255u;
goto P_0c0adcae;
P_0c0adcae: /* original 4028, guest PC 0x0c0adcae */
if(!s->budget--) { s->failed_pc=0x0c0adcaeu; return 0; }
r[0]<<=16;
goto P_0c0adcb0;
P_0c0adcb0: /* original 2029, guest PC 0x0c0adcb0 */
if(!s->budget--) { s->failed_pc=0x0c0adcb0u; return 0; }
r[0]&=r[2];
goto P_0c0adcb2;
P_0c0adcb2: /* original 210b, guest PC 0x0c0adcb2 */
if(!s->budget--) { s->failed_pc=0x0c0adcb2u; return 0; }
r[1]|=r[0];
goto P_0c0adcb4;
P_0c0adcb4: /* original 8465, guest PC 0x0c0adcb4 */
if(!s->budget--) { s->failed_pc=0x0c0adcb4u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[6]+5,1);
goto P_0c0adcb6;
P_0c0adcb6: /* original 4329, guest PC 0x0c0adcb6 */
if(!s->budget--) { s->failed_pc=0x0c0adcb6u; return 0; }
r[3]>>=16;
goto P_0c0adcb8;
P_0c0adcb8: /* original 600c, guest PC 0x0c0adcb8 */
if(!s->budget--) { s->failed_pc=0x0c0adcb8u; return 0; }
r[0]=r[0]&255u;
goto P_0c0adcba;
P_0c0adcba: /* original 4018, guest PC 0x0c0adcba */
if(!s->budget--) { s->failed_pc=0x0c0adcbau; return 0; }
r[0]<<=8;
goto P_0c0adcbc;
P_0c0adcbc: /* original 2039, guest PC 0x0c0adcbc */
if(!s->budget--) { s->failed_pc=0x0c0adcbcu; return 0; }
r[0]&=r[3];
goto P_0c0adcbe;
P_0c0adcbe: /* original 210b, guest PC 0x0c0adcbe */
if(!s->budget--) { s->failed_pc=0x0c0adcbeu; return 0; }
r[1]|=r[0];
goto P_0c0adcc0;
P_0c0adcc0: /* original 8464, guest PC 0x0c0adcc0 */
if(!s->budget--) { s->failed_pc=0x0c0adcc0u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[6]+4,1);
goto P_0c0adcc2;
P_0c0adcc2: /* original 600c, guest PC 0x0c0adcc2 */
if(!s->budget--) { s->failed_pc=0x0c0adcc2u; return 0; }
r[0]=r[0]&255u;
goto P_0c0adcc4;
P_0c0adcc4: /* original 210b, guest PC 0x0c0adcc4 */
if(!s->budget--) { s->failed_pc=0x0c0adcc4u; return 0; }
r[1]|=r[0];
goto P_0c0adcc6;
P_0c0adcc6: /* original 2712, guest PC 0x0c0adcc6 */
if(!s->budget--) { s->failed_pc=0x0c0adcc6u; return 0; }
write(ram,r[7],r[1],4);
goto P_0c0adcc8;
P_0c0adcc8: /* original 61f2, guest PC 0x0c0adcc8 */
if(!s->budget--) { s->failed_pc=0x0c0adcc8u; return 0; }
tmp=read(ram,r[15],4);
r[1]=tmp;
goto P_0c0adcca;
P_0c0adcca: /* original f4e8, guest PC 0x0c0adcca */
if(!s->budget--) { s->failed_pc=0x0c0adccau; return 0; }
vf3_matrix_load(s,ram,4,r[14]);
goto P_0c0adccc;
P_0c0adccc: /* original f618, guest PC 0x0c0adccc */
if(!s->budget--) { s->failed_pc=0x0c0adcccu; return 0; }
vf3_matrix_load(s,ram,6,r[1]);
goto P_0c0adcce;
P_0c0adcce: /* original f34c, guest PC 0x0c0adcce */
if(!s->budget--) { s->failed_pc=0x0c0adcceu; return 0; }
vf3_matrix_move(s,3,4);
goto P_0c0adcd0;
P_0c0adcd0: /* original f362, guest PC 0x0c0adcd0 */
if(!s->budget--) { s->failed_pc=0x0c0adcd0u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[6],r[18],'*');
goto P_0c0adcd2;
P_0c0adcd2: /* original f58d, guest PC 0x0c0adcd2 */
if(!s->budget--) { s->failed_pc=0x0c0adcd2u; return 0; }
fr[5]=0;
goto P_0c0adcd4;
P_0c0adcd4: /* original f25c, guest PC 0x0c0adcd4 */
if(!s->budget--) { s->failed_pc=0x0c0adcd4u; return 0; }
vf3_matrix_move(s,2,5);
goto P_0c0adcd6;
P_0c0adcd6: /* original 9077, guest PC 0x0c0adcd6 */
if(!s->budget--) { s->failed_pc=0x0c0adcd6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0addc8u,2);
goto P_0c0adcd8;
P_0c0adcd8: /* original f34d, guest PC 0x0c0adcd8 */
if(!s->budget--) { s->failed_pc=0x0c0adcd8u; return 0; }
fr[3]^=0x80000000u;
goto P_0c0adcda;
P_0c0adcda: /* original f53c, guest PC 0x0c0adcda */
if(!s->budget--) { s->failed_pc=0x0c0adcdau; return 0; }
vf3_matrix_move(s,5,3);
goto P_0c0adcdc;
P_0c0adcdc: /* original f521, guest PC 0x0c0adcdc */
if(!s->budget--) { s->failed_pc=0x0c0adcdcu; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[2],r[18],'-');
goto P_0c0adcde;
P_0c0adcde: /* original f457, guest PC 0x0c0adcde */
if(!s->budget--) { s->failed_pc=0x0c0adcdeu; return 0; }
vf3_matrix_store(s,ram,5,r[4]+r[0]);
goto P_0c0adce0;
P_0c0adce0: /* original f59d, guest PC 0x0c0adce0 */
if(!s->budget--) { s->failed_pc=0x0c0adce0u; return 0; }
fr[5]=0x3f800000u;
goto P_0c0adce2;
P_0c0adce2: /* original f450, guest PC 0x0c0adce2 */
if(!s->budget--) { s->failed_pc=0x0c0adce2u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[5],r[18],'+');
goto P_0c0adce4;
P_0c0adce4: /* original 9071, guest PC 0x0c0adce4 */
if(!s->budget--) { s->failed_pc=0x0c0adce4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0addcau,2);
goto P_0c0adce6;
P_0c0adce6: /* original f447, guest PC 0x0c0adce6 */
if(!s->budget--) { s->failed_pc=0x0c0adce6u; return 0; }
vf3_matrix_store(s,ram,4,r[4]+r[0]);
goto P_0c0adce8;
P_0c0adce8: /* original 846b, guest PC 0x0c0adce8 */
if(!s->budget--) { s->failed_pc=0x0c0adce8u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[6]+11,1);
goto P_0c0adcea;
P_0c0adcea: /* original 600c, guest PC 0x0c0adcea */
if(!s->budget--) { s->failed_pc=0x0c0adceau; return 0; }
r[0]=r[0]&255u;
goto P_0c0adcec;
P_0c0adcec: /* original 4028, guest PC 0x0c0adcec */
if(!s->budget--) { s->failed_pc=0x0c0adcecu; return 0; }
r[0]<<=16;
goto P_0c0adcee;
P_0c0adcee: /* original 4018, guest PC 0x0c0adcee */
if(!s->budget--) { s->failed_pc=0x0c0adceeu; return 0; }
r[0]<<=8;
goto P_0c0adcf0;
P_0c0adcf0: /* original d13b, guest PC 0x0c0adcf0 */
if(!s->budget--) { s->failed_pc=0x0c0adcf0u; return 0; }
r[1]=read(ram,0x0c0adde0u,4);
goto P_0c0adcf2;
P_0c0adcf2: /* original 2019, guest PC 0x0c0adcf2 */
if(!s->budget--) { s->failed_pc=0x0c0adcf2u; return 0; }
r[0]&=r[1];
goto P_0c0adcf4;
P_0c0adcf4: /* original 6303, guest PC 0x0c0adcf4 */
if(!s->budget--) { s->failed_pc=0x0c0adcf4u; return 0; }
r[3]=r[0];
goto P_0c0adcf6;
P_0c0adcf6: /* original 846a, guest PC 0x0c0adcf6 */
if(!s->budget--) { s->failed_pc=0x0c0adcf6u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[6]+10,1);
goto P_0c0adcf8;
P_0c0adcf8: /* original 600c, guest PC 0x0c0adcf8 */
if(!s->budget--) { s->failed_pc=0x0c0adcf8u; return 0; }
r[0]=r[0]&255u;
goto P_0c0adcfa;
P_0c0adcfa: /* original 4028, guest PC 0x0c0adcfa */
if(!s->budget--) { s->failed_pc=0x0c0adcfau; return 0; }
r[0]<<=16;
goto P_0c0adcfc;
P_0c0adcfc: /* original 2029, guest PC 0x0c0adcfc */
if(!s->budget--) { s->failed_pc=0x0c0adcfcu; return 0; }
r[0]&=r[2];
goto P_0c0adcfe;
P_0c0adcfe: /* original 230b, guest PC 0x0c0adcfe */
if(!s->budget--) { s->failed_pc=0x0c0adcfeu; return 0; }
r[3]|=r[0];
goto P_0c0add00;
P_0c0add00: /* original 8469, guest PC 0x0c0add00 */
if(!s->budget--) { s->failed_pc=0x0c0add00u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[6]+9,1);
goto P_0c0add02;
P_0c0add02: /* original 4219, guest PC 0x0c0add02 */
if(!s->budget--) { s->failed_pc=0x0c0add02u; return 0; }
r[2]>>=8;
goto P_0c0add04;
P_0c0add04: /* original 600c, guest PC 0x0c0add04 */
if(!s->budget--) { s->failed_pc=0x0c0add04u; return 0; }
r[0]=r[0]&255u;
goto P_0c0add06;
P_0c0add06: /* original 4018, guest PC 0x0c0add06 */
if(!s->budget--) { s->failed_pc=0x0c0add06u; return 0; }
r[0]<<=8;
goto P_0c0add08;
P_0c0add08: /* original 2029, guest PC 0x0c0add08 */
if(!s->budget--) { s->failed_pc=0x0c0add08u; return 0; }
r[0]&=r[2];
goto P_0c0add0a;
P_0c0add0a: /* original 230b, guest PC 0x0c0add0a */
if(!s->budget--) { s->failed_pc=0x0c0add0au; return 0; }
r[3]|=r[0];
goto P_0c0add0c;
P_0c0add0c: /* original 8468, guest PC 0x0c0add0c */
if(!s->budget--) { s->failed_pc=0x0c0add0cu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[6]+8,1);
goto P_0c0add0e;
P_0c0add0e: /* original 600c, guest PC 0x0c0add0e */
if(!s->budget--) { s->failed_pc=0x0c0add0eu; return 0; }
r[0]=r[0]&255u;
goto P_0c0add10;
P_0c0add10: /* original 230b, guest PC 0x0c0add10 */
if(!s->budget--) { s->failed_pc=0x0c0add10u; return 0; }
r[3]|=r[0];
goto P_0c0add12;
P_0c0add12: /* original 2732, guest PC 0x0c0add12 */
if(!s->budget--) { s->failed_pc=0x0c0add12u; return 0; }
write(ram,r[7],r[3],4);
goto P_0c0add14;
P_0c0add14: /* original 905a, guest PC 0x0c0add14 */
if(!s->budget--) { s->failed_pc=0x0c0add14u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0addccu,2);
goto P_0c0add16;
P_0c0add16: /* original f3e8, guest PC 0x0c0add16 */
if(!s->budget--) { s->failed_pc=0x0c0add16u; return 0; }
vf3_matrix_load(s,ram,3,r[14]);
goto P_0c0add18;
P_0c0add18: /* original f437, guest PC 0x0c0add18 */
if(!s->budget--) { s->failed_pc=0x0c0add18u; return 0; }
vf3_matrix_store(s,ram,3,r[4]+r[0]);
goto P_0c0add1a;
P_0c0add1a: /* original bc2d, guest PC 0x0c0add1a */
if(!s->budget--) { s->failed_pc=0x0c0add1au; return 0; }
target=0x0c0ad578u; r[16]=0x0c0add1eu;
r[6]+=0x0000000cu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0add1eu) { target=s->pc; goto dispatch; }
goto P_0c0add1e;
P_0c0add1c: /* original 760c, guest PC 0x0c0add1c */
if(!s->budget--) { s->failed_pc=0x0c0add1cu; return 0; }
r[6]+=0x0000000cu;
goto P_0c0add1e;
P_0c0add1e: /* original 7f0c, guest PC 0x0c0add1e */
if(!s->budget--) { s->failed_pc=0x0c0add1eu; return 0; }
r[15]+=0x0000000cu;
goto P_0c0add20;
P_0c0add20: /* original 4f26, guest PC 0x0c0add20 */
if(!s->budget--) { s->failed_pc=0x0c0add20u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0add22;
P_0c0add22: /* original 000b, guest PC 0x0c0add22 */
if(!s->budget--) { s->failed_pc=0x0c0add22u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0add24: /* original 6ef6, guest PC 0x0c0add24 */
if(!s->budget--) { s->failed_pc=0x0c0add24u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0add26u,s,ram);
P_0c0c18fe: /* original 4f22, guest PC 0x0c0c18fe */
if(!s->budget--) { s->failed_pc=0x0c0c18feu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0c1900;
P_0c0c1900: /* original 945d, guest PC 0x0c0c1900 */
if(!s->budget--) { s->failed_pc=0x0c0c1900u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c19beu,2);
goto P_0c0c1902;
P_0c0c1902: /* original d331, guest PC 0x0c0c1902 */
if(!s->budget--) { s->failed_pc=0x0c0c1902u; return 0; }
r[3]=read(ram,0x0c0c19c8u,4);
goto P_0c0c1904;
P_0c0c1904: /* original 7fcc, guest PC 0x0c0c1904 */
if(!s->budget--) { s->failed_pc=0x0c0c1904u; return 0; }
r[15]+=0xffffffccu;
goto P_0c0c1906;
P_0c0c1906: /* original 430b, guest PC 0x0c0c1906 */
if(!s->budget--) { s->failed_pc=0x0c0c1906u; return 0; }
target=r[3];
r[16]=0x0c0c190au;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c190au) { target=s->pc; goto dispatch; }
goto P_0c0c190a;
P_0c0c1908: /* original 0009, guest PC 0x0c0c1908 */
if(!s->budget--) { s->failed_pc=0x0c0c1908u; return 0; }
goto P_0c0c190a;
P_0c0c190a: /* original 6e03, guest PC 0x0c0c190a */
if(!s->budget--) { s->failed_pc=0x0c0c190au; return 0; }
r[14]=r[0];
goto P_0c0c190c;
P_0c0c190c: /* original c72f, guest PC 0x0c0c190c */
if(!s->budget--) { s->failed_pc=0x0c0c190cu; return 0; }
r[0]=0x0c0c19ccu;
goto P_0c0c190e;
P_0c0c190e: /* original 52e8, guest PC 0x0c0c190e */
if(!s->budget--) { s->failed_pc=0x0c0c190eu; return 0; }
r[2]=read(ram,r[14]+32,4);
goto P_0c0c1910;
P_0c0c1910: /* original 2f22, guest PC 0x0c0c1910 */
if(!s->budget--) { s->failed_pc=0x0c0c1910u; return 0; }
write(ram,r[15],r[2],4);
goto P_0c0c1912;
P_0c0c1912: /* original f308, guest PC 0x0c0c1912 */
if(!s->budget--) { s->failed_pc=0x0c0c1912u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c0c1914;
P_0c0c1914: /* original e018, guest PC 0x0c0c1914 */
if(!s->budget--) { s->failed_pc=0x0c0c1914u; return 0; }
r[0]=0x00000018u;
goto P_0c0c1916;
P_0c0c1916: /* original fee6, guest PC 0x0c0c1916 */
if(!s->budget--) { s->failed_pc=0x0c0c1916u; return 0; }
vf3_matrix_load(s,ram,14,r[14]+r[0]);
goto P_0c0c1918;
P_0c0c1918: /* original c72d, guest PC 0x0c0c1918 */
if(!s->budget--) { s->failed_pc=0x0c0c1918u; return 0; }
r[0]=0x0c0c19d0u;
goto P_0c0c191a;
P_0c0c191a: /* original f208, guest PC 0x0c0c191a */
if(!s->budget--) { s->failed_pc=0x0c0c191au; return 0; }
vf3_matrix_load(s,ram,2,r[0]);
goto P_0c0c191c;
P_0c0c191c: /* original e01c, guest PC 0x0c0c191c */
if(!s->budget--) { s->failed_pc=0x0c0c191cu; return 0; }
r[0]=0x0000001cu;
goto P_0c0c191e;
P_0c0c191e: /* original ffe6, guest PC 0x0c0c191e */
if(!s->budget--) { s->failed_pc=0x0c0c191eu; return 0; }
vf3_matrix_load(s,ram,15,r[14]+r[0]);
goto P_0c0c1920;
P_0c0c1920: /* original fe32, guest PC 0x0c0c1920 */
if(!s->budget--) { s->failed_pc=0x0c0c1920u; return 0; }
fr[14]=vf3_fpu_binary(fr[14],fr[3],r[18],'*');
goto P_0c0c1922;
P_0c0c1922: /* original c72c, guest PC 0x0c0c1922 */
if(!s->budget--) { s->failed_pc=0x0c0c1922u; return 0; }
r[0]=0x0c0c19d4u;
goto P_0c0c1924;
P_0c0c1924: /* original d32c, guest PC 0x0c0c1924 */
if(!s->budget--) { s->failed_pc=0x0c0c1924u; return 0; }
r[3]=read(ram,0x0c0c19d8u,4);
goto P_0c0c1926;
P_0c0c1926: /* original ff22, guest PC 0x0c0c1926 */
if(!s->budget--) { s->failed_pc=0x0c0c1926u; return 0; }
fr[15]=vf3_fpu_binary(fr[15],fr[2],r[18],'*');
goto P_0c0c1928;
P_0c0c1928: /* original f808, guest PC 0x0c0c1928 */
if(!s->budget--) { s->failed_pc=0x0c0c1928u; return 0; }
vf3_matrix_load(s,ram,8,r[0]);
goto P_0c0c192a;
P_0c0c192a: /* original fd8d, guest PC 0x0c0c192a */
if(!s->budget--) { s->failed_pc=0x0c0c192au; return 0; }
fr[13]=0;
goto P_0c0c192c;
P_0c0c192c: /* original f5dc, guest PC 0x0c0c192c */
if(!s->budget--) { s->failed_pc=0x0c0c192cu; return 0; }
vf3_matrix_move(s,5,13);
goto P_0c0c192e;
P_0c0c192e: /* original f4dc, guest PC 0x0c0c192e */
if(!s->budget--) { s->failed_pc=0x0c0c192eu; return 0; }
vf3_matrix_move(s,4,13);
goto P_0c0c1930;
P_0c0c1930: /* original f7fc, guest PC 0x0c0c1930 */
if(!s->budget--) { s->failed_pc=0x0c0c1930u; return 0; }
vf3_matrix_move(s,7,15);
goto P_0c0c1932;
P_0c0c1932: /* original f6ec, guest PC 0x0c0c1932 */
if(!s->budget--) { s->failed_pc=0x0c0c1932u; return 0; }
vf3_matrix_move(s,6,14);
goto P_0c0c1934;
P_0c0c1934: /* original 430b, guest PC 0x0c0c1934 */
if(!s->budget--) { s->failed_pc=0x0c0c1934u; return 0; }
target=r[3];
r[16]=0x0c0c1938u;
r[4]=r[15];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c1938u) { target=s->pc; goto dispatch; }
goto P_0c0c1938;
P_0c0c1936: /* original 64f3, guest PC 0x0c0c1936 */
if(!s->budget--) { s->failed_pc=0x0c0c1936u; return 0; }
r[4]=r[15];
goto P_0c0c1938;
P_0c0c1938: /* original e014, guest PC 0x0c0c1938 */
if(!s->budget--) { s->failed_pc=0x0c0c1938u; return 0; }
r[0]=0x00000014u;
goto P_0c0c193a;
P_0c0c193a: /* original d328, guest PC 0x0c0c193a */
if(!s->budget--) { s->failed_pc=0x0c0c193au; return 0; }
r[3]=read(ram,0x0c0c19dcu,4);
goto P_0c0c193c;
P_0c0c193c: /* original f9e6, guest PC 0x0c0c193c */
if(!s->budget--) { s->failed_pc=0x0c0c193cu; return 0; }
vf3_matrix_load(s,ram,9,r[14]+r[0]);
goto P_0c0c193e;
P_0c0c193e: /* original e010, guest PC 0x0c0c193e */
if(!s->budget--) { s->failed_pc=0x0c0c193eu; return 0; }
r[0]=0x00000010u;
goto P_0c0c1940;
P_0c0c1940: /* original f8e6, guest PC 0x0c0c1940 */
if(!s->budget--) { s->failed_pc=0x0c0c1940u; return 0; }
vf3_matrix_load(s,ram,8,r[14]+r[0]);
goto P_0c0c1942;
P_0c0c1942: /* original e00c, guest PC 0x0c0c1942 */
if(!s->budget--) { s->failed_pc=0x0c0c1942u; return 0; }
r[0]=0x0000000cu;
goto P_0c0c1944;
P_0c0c1944: /* original f7e6, guest PC 0x0c0c1944 */
if(!s->budget--) { s->failed_pc=0x0c0c1944u; return 0; }
vf3_matrix_load(s,ram,7,r[14]+r[0]);
goto P_0c0c1946;
P_0c0c1946: /* original e008, guest PC 0x0c0c1946 */
if(!s->budget--) { s->failed_pc=0x0c0c1946u; return 0; }
r[0]=0x00000008u;
goto P_0c0c1948;
P_0c0c1948: /* original f6e6, guest PC 0x0c0c1948 */
if(!s->budget--) { s->failed_pc=0x0c0c1948u; return 0; }
vf3_matrix_load(s,ram,6,r[14]+r[0]);
goto P_0c0c194a;
P_0c0c194a: /* original e004, guest PC 0x0c0c194a */
if(!s->budget--) { s->failed_pc=0x0c0c194au; return 0; }
r[0]=0x00000004u;
goto P_0c0c194c;
P_0c0c194c: /* original f4e8, guest PC 0x0c0c194c */
if(!s->budget--) { s->failed_pc=0x0c0c194cu; return 0; }
vf3_matrix_load(s,ram,4,r[14]);
goto P_0c0c194e;
P_0c0c194e: /* original f5e6, guest PC 0x0c0c194e */
if(!s->budget--) { s->failed_pc=0x0c0c194eu; return 0; }
vf3_matrix_load(s,ram,5,r[14]+r[0]);
goto P_0c0c1950;
P_0c0c1950: /* original 430b, guest PC 0x0c0c1950 */
if(!s->budget--) { s->failed_pc=0x0c0c1950u; return 0; }
target=r[3];
r[16]=0x0c0c1954u;
r[4]=r[15];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c1954u) { target=s->pc; goto dispatch; }
goto P_0c0c1954;
P_0c0c1952: /* original 64f3, guest PC 0x0c0c1952 */
if(!s->budget--) { s->failed_pc=0x0c0c1952u; return 0; }
r[4]=r[15];
goto P_0c0c1954;
P_0c0c1954: /* original e030, guest PC 0x0c0c1954 */
if(!s->budget--) { s->failed_pc=0x0c0c1954u; return 0; }
r[0]=0x00000030u;
goto P_0c0c1956;
P_0c0c1956: /* original e200, guest PC 0x0c0c1956 */
if(!s->budget--) { s->failed_pc=0x0c0c1956u; return 0; }
r[2]=0x00000000u;
goto P_0c0c1958;
P_0c0c1958: /* original 1f2a, guest PC 0x0c0c1958 */
if(!s->budget--) { s->failed_pc=0x0c0c1958u; return 0; }
write(ram,r[15]+40,r[2],4);
goto P_0c0c195a;
P_0c0c195a: /* original 9331, guest PC 0x0c0c195a */
if(!s->budget--) { s->failed_pc=0x0c0c195au; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c19c0u,2);
goto P_0c0c195c;
P_0c0c195c: /* original 1f3b, guest PC 0x0c0c195c */
if(!s->budget--) { s->failed_pc=0x0c0c195cu; return 0; }
write(ram,r[15]+44,r[3],4);
goto P_0c0c195e;
P_0c0c195e: /* original f39d, guest PC 0x0c0c195e */
if(!s->budget--) { s->failed_pc=0x0c0c195eu; return 0; }
fr[3]=0x3f800000u;
goto P_0c0c1960;
P_0c0c1960: /* original ff37, guest PC 0x0c0c1960 */
if(!s->budget--) { s->failed_pc=0x0c0c1960u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0c1962;
P_0c0c1962: /* original d31f, guest PC 0x0c0c1962 */
if(!s->budget--) { s->failed_pc=0x0c0c1962u; return 0; }
r[3]=read(ram,0x0c0c19e0u,4);
goto P_0c0c1964;
P_0c0c1964: /* original 430b, guest PC 0x0c0c1964 */
if(!s->budget--) { s->failed_pc=0x0c0c1964u; return 0; }
target=r[3];
r[16]=0x0c0c1968u;
r[4]=r[15];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c1968u) { target=s->pc; goto dispatch; }
goto P_0c0c1968;
P_0c0c1966: /* original 64f3, guest PC 0x0c0c1966 */
if(!s->budget--) { s->failed_pc=0x0c0c1966u; return 0; }
r[4]=r[15];
goto P_0c0c1968;
P_0c0c1968: /* original c71a, guest PC 0x0c0c1968 */
if(!s->budget--) { s->failed_pc=0x0c0c1968u; return 0; }
r[0]=0x0c0c19d4u;
goto P_0c0c196a;
P_0c0c196a: /* original d31b, guest PC 0x0c0c196a */
if(!s->budget--) { s->failed_pc=0x0c0c196au; return 0; }
r[3]=read(ram,0x0c0c19d8u,4);
goto P_0c0c196c;
P_0c0c196c: /* original f808, guest PC 0x0c0c196c */
if(!s->budget--) { s->failed_pc=0x0c0c196cu; return 0; }
vf3_matrix_load(s,ram,8,r[0]);
goto P_0c0c196e;
P_0c0c196e: /* original c71d, guest PC 0x0c0c196e */
if(!s->budget--) { s->failed_pc=0x0c0c196eu; return 0; }
r[0]=0x0c0c19e4u;
goto P_0c0c1970;
P_0c0c1970: /* original f508, guest PC 0x0c0c1970 */
if(!s->budget--) { s->failed_pc=0x0c0c1970u; return 0; }
vf3_matrix_load(s,ram,5,r[0]);
goto P_0c0c1972;
P_0c0c1972: /* original f4dc, guest PC 0x0c0c1972 */
if(!s->budget--) { s->failed_pc=0x0c0c1972u; return 0; }
vf3_matrix_move(s,4,13);
goto P_0c0c1974;
P_0c0c1974: /* original f7fc, guest PC 0x0c0c1974 */
if(!s->budget--) { s->failed_pc=0x0c0c1974u; return 0; }
vf3_matrix_move(s,7,15);
goto P_0c0c1976;
P_0c0c1976: /* original f6ec, guest PC 0x0c0c1976 */
if(!s->budget--) { s->failed_pc=0x0c0c1976u; return 0; }
vf3_matrix_move(s,6,14);
goto P_0c0c1978;
P_0c0c1978: /* original 430b, guest PC 0x0c0c1978 */
if(!s->budget--) { s->failed_pc=0x0c0c1978u; return 0; }
target=r[3];
r[16]=0x0c0c197cu;
r[4]=r[15];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c197cu) { target=s->pc; goto dispatch; }
goto P_0c0c197c;
P_0c0c197a: /* original 64f3, guest PC 0x0c0c197a */
if(!s->budget--) { s->failed_pc=0x0c0c197au; return 0; }
r[4]=r[15];
goto P_0c0c197c;
P_0c0c197c: /* original e014, guest PC 0x0c0c197c */
if(!s->budget--) { s->failed_pc=0x0c0c197cu; return 0; }
r[0]=0x00000014u;
goto P_0c0c197e;
P_0c0c197e: /* original d317, guest PC 0x0c0c197e */
if(!s->budget--) { s->failed_pc=0x0c0c197eu; return 0; }
r[3]=read(ram,0x0c0c19dcu,4);
goto P_0c0c1980;
P_0c0c1980: /* original f9e6, guest PC 0x0c0c1980 */
if(!s->budget--) { s->failed_pc=0x0c0c1980u; return 0; }
vf3_matrix_load(s,ram,9,r[14]+r[0]);
goto P_0c0c1982;
P_0c0c1982: /* original e010, guest PC 0x0c0c1982 */
if(!s->budget--) { s->failed_pc=0x0c0c1982u; return 0; }
r[0]=0x00000010u;
goto P_0c0c1984;
P_0c0c1984: /* original f8e6, guest PC 0x0c0c1984 */
if(!s->budget--) { s->failed_pc=0x0c0c1984u; return 0; }
vf3_matrix_load(s,ram,8,r[14]+r[0]);
goto P_0c0c1986;
P_0c0c1986: /* original e00c, guest PC 0x0c0c1986 */
if(!s->budget--) { s->failed_pc=0x0c0c1986u; return 0; }
r[0]=0x0000000cu;
goto P_0c0c1988;
P_0c0c1988: /* original f7e6, guest PC 0x0c0c1988 */
if(!s->budget--) { s->failed_pc=0x0c0c1988u; return 0; }
vf3_matrix_load(s,ram,7,r[14]+r[0]);
goto P_0c0c198a;
P_0c0c198a: /* original e008, guest PC 0x0c0c198a */
if(!s->budget--) { s->failed_pc=0x0c0c198au; return 0; }
r[0]=0x00000008u;
goto P_0c0c198c;
P_0c0c198c: /* original f6e6, guest PC 0x0c0c198c */
if(!s->budget--) { s->failed_pc=0x0c0c198cu; return 0; }
vf3_matrix_load(s,ram,6,r[14]+r[0]);
goto P_0c0c198e;
P_0c0c198e: /* original e004, guest PC 0x0c0c198e */
if(!s->budget--) { s->failed_pc=0x0c0c198eu; return 0; }
r[0]=0x00000004u;
goto P_0c0c1990;
P_0c0c1990: /* original f4e8, guest PC 0x0c0c1990 */
if(!s->budget--) { s->failed_pc=0x0c0c1990u; return 0; }
vf3_matrix_load(s,ram,4,r[14]);
goto P_0c0c1992;
P_0c0c1992: /* original f5e6, guest PC 0x0c0c1992 */
if(!s->budget--) { s->failed_pc=0x0c0c1992u; return 0; }
vf3_matrix_load(s,ram,5,r[14]+r[0]);
goto P_0c0c1994;
P_0c0c1994: /* original 430b, guest PC 0x0c0c1994 */
if(!s->budget--) { s->failed_pc=0x0c0c1994u; return 0; }
target=r[3];
r[16]=0x0c0c1998u;
r[4]=r[15];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c1998u) { target=s->pc; goto dispatch; }
goto P_0c0c1998;
P_0c0c1996: /* original 64f3, guest PC 0x0c0c1996 */
if(!s->budget--) { s->failed_pc=0x0c0c1996u; return 0; }
r[4]=r[15];
goto P_0c0c1998;
P_0c0c1998: /* original e030, guest PC 0x0c0c1998 */
if(!s->budget--) { s->failed_pc=0x0c0c1998u; return 0; }
r[0]=0x00000030u;
goto P_0c0c199a;
P_0c0c199a: /* original e200, guest PC 0x0c0c199a */
if(!s->budget--) { s->failed_pc=0x0c0c199au; return 0; }
r[2]=0x00000000u;
goto P_0c0c199c;
P_0c0c199c: /* original 1f2a, guest PC 0x0c0c199c */
if(!s->budget--) { s->failed_pc=0x0c0c199cu; return 0; }
write(ram,r[15]+40,r[2],4);
goto P_0c0c199e;
P_0c0c199e: /* original 930f, guest PC 0x0c0c199e */
if(!s->budget--) { s->failed_pc=0x0c0c199eu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c19c0u,2);
goto P_0c0c19a0;
P_0c0c19a0: /* original 1f3b, guest PC 0x0c0c19a0 */
if(!s->budget--) { s->failed_pc=0x0c0c19a0u; return 0; }
write(ram,r[15]+44,r[3],4);
goto P_0c0c19a2;
P_0c0c19a2: /* original f39d, guest PC 0x0c0c19a2 */
if(!s->budget--) { s->failed_pc=0x0c0c19a2u; return 0; }
fr[3]=0x3f800000u;
goto P_0c0c19a4;
P_0c0c19a4: /* original ff37, guest PC 0x0c0c19a4 */
if(!s->budget--) { s->failed_pc=0x0c0c19a4u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0c19a6;
P_0c0c19a6: /* original d30e, guest PC 0x0c0c19a6 */
if(!s->budget--) { s->failed_pc=0x0c0c19a6u; return 0; }
r[3]=read(ram,0x0c0c19e0u,4);
goto P_0c0c19a8;
P_0c0c19a8: /* original 430b, guest PC 0x0c0c19a8 */
if(!s->budget--) { s->failed_pc=0x0c0c19a8u; return 0; }
target=r[3];
r[16]=0x0c0c19acu;
r[4]=r[15];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c19acu) { target=s->pc; goto dispatch; }
goto P_0c0c19ac;
P_0c0c19aa: /* original 64f3, guest PC 0x0c0c19aa */
if(!s->budget--) { s->failed_pc=0x0c0c19aau; return 0; }
r[4]=r[15];
goto P_0c0c19ac;
P_0c0c19ac: /* original 7f34, guest PC 0x0c0c19ac */
if(!s->budget--) { s->failed_pc=0x0c0c19acu; return 0; }
r[15]+=0x00000034u;
goto P_0c0c19ae;
P_0c0c19ae: /* original 4f26, guest PC 0x0c0c19ae */
if(!s->budget--) { s->failed_pc=0x0c0c19aeu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c19b0;
P_0c0c19b0: /* original fdf9, guest PC 0x0c0c19b0 */
if(!s->budget--) { s->failed_pc=0x0c0c19b0u; return 0; }
vf3_matrix_load(s,ram,13,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0c19b2;
P_0c0c19b2: /* original fef9, guest PC 0x0c0c19b2 */
if(!s->budget--) { s->failed_pc=0x0c0c19b2u; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0c19b4;
P_0c0c19b4: /* original fff9, guest PC 0x0c0c19b4 */
if(!s->budget--) { s->failed_pc=0x0c0c19b4u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0c19b6;
P_0c0c19b6: /* original 000b, guest PC 0x0c0c19b6 */
if(!s->budget--) { s->failed_pc=0x0c0c19b6u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0c19b8: /* original 6ef6, guest PC 0x0c0c19b8 */
if(!s->budget--) { s->failed_pc=0x0c0c19b8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0c19bau,s,ram);
P_0c0ca0c6: /* original 4f22, guest PC 0x0c0ca0c6 */
if(!s->budget--) { s->failed_pc=0x0c0ca0c6u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0ca0c8;
P_0c0ca0c8: /* original 005d, guest PC 0x0c0ca0c8 */
if(!s->budget--) { s->failed_pc=0x0c0ca0c8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[5]+r[0],2);
goto P_0c0ca0ca;
P_0c0ca0ca: /* original d32e, guest PC 0x0c0ca0ca */
if(!s->budget--) { s->failed_pc=0x0c0ca0cau; return 0; }
r[3]=read(ram,0x0c0ca184u,4);
goto P_0c0ca0cc;
P_0c0ca0cc: /* original 7fec, guest PC 0x0c0ca0cc */
if(!s->budget--) { s->failed_pc=0x0c0ca0ccu; return 0; }
r[15]+=0xffffffecu;
goto P_0c0ca0ce;
P_0c0ca0ce: /* original d42a, guest PC 0x0c0ca0ce */
if(!s->budget--) { s->failed_pc=0x0c0ca0ceu; return 0; }
r[4]=read(ram,0x0c0ca178u,4);
goto P_0c0ca0d0;
P_0c0ca0d0: /* original 6d32, guest PC 0x0c0ca0d0 */
if(!s->budget--) { s->failed_pc=0x0c0ca0d0u; return 0; }
tmp=read(ram,r[3],4);
r[13]=tmp;
goto P_0c0ca0d2;
P_0c0ca0d2: /* original 81f8, guest PC 0x0c0ca0d2 */
if(!s->budget--) { s->failed_pc=0x0c0ca0d2u; return 0; }
write(ram,r[15]+16,r[0],2);
goto P_0c0ca0d4;
P_0c0ca0d4: /* original e022, guest PC 0x0c0ca0d4 */
if(!s->budget--) { s->failed_pc=0x0c0ca0d4u; return 0; }
r[0]=0x00000022u;
goto P_0c0ca0d6;
P_0c0ca0d6: /* original 005d, guest PC 0x0c0ca0d6 */
if(!s->budget--) { s->failed_pc=0x0c0ca0d6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[5]+r[0],2);
goto P_0c0ca0d8;
P_0c0ca0d8: /* original 6e43, guest PC 0x0c0ca0d8 */
if(!s->budget--) { s->failed_pc=0x0c0ca0d8u; return 0; }
r[14]=r[4];
goto P_0c0ca0da;
P_0c0ca0da: /* original 81f6, guest PC 0x0c0ca0da */
if(!s->budget--) { s->failed_pc=0x0c0ca0dau; return 0; }
write(ram,r[15]+12,r[0],2);
goto P_0c0ca0dc;
P_0c0ca0dc: /* original 2f16, guest PC 0x0c0ca0dc */
if(!s->budget--) { s->failed_pc=0x0c0ca0dcu; return 0; }
r[15]-=4; write(ram,r[15],r[1],4);
goto P_0c0ca0de;
P_0c0ca0de: /* original 85f8, guest PC 0x0c0ca0de */
if(!s->budget--) { s->failed_pc=0x0c0ca0deu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+16,2);
goto P_0c0ca0e0;
P_0c0ca0e0: /* original 2f06, guest PC 0x0c0ca0e0 */
if(!s->budget--) { s->failed_pc=0x0c0ca0e0u; return 0; }
r[15]-=4; write(ram,r[15],r[0],4);
goto P_0c0ca0e2;
P_0c0ca0e2: /* original 85fc, guest PC 0x0c0ca0e2 */
if(!s->budget--) { s->failed_pc=0x0c0ca0e2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+24,2);
goto P_0c0ca0e4;
P_0c0ca0e4: /* original 66f3, guest PC 0x0c0ca0e4 */
if(!s->budget--) { s->failed_pc=0x0c0ca0e4u; return 0; }
r[6]=r[15];
goto P_0c0ca0e6;
P_0c0ca0e6: /* original 65f3, guest PC 0x0c0ca0e6 */
if(!s->budget--) { s->failed_pc=0x0c0ca0e6u; return 0; }
r[5]=r[15];
goto P_0c0ca0e8;
P_0c0ca0e8: /* original d227, guest PC 0x0c0ca0e8 */
if(!s->budget--) { s->failed_pc=0x0c0ca0e8u; return 0; }
r[2]=read(ram,0x0c0ca188u,4);
goto P_0c0ca0ea;
P_0c0ca0ea: /* original 64f3, guest PC 0x0c0ca0ea */
if(!s->budget--) { s->failed_pc=0x0c0ca0eau; return 0; }
r[4]=r[15];
goto P_0c0ca0ec;
P_0c0ca0ec: /* original 750c, guest PC 0x0c0ca0ec */
if(!s->budget--) { s->failed_pc=0x0c0ca0ecu; return 0; }
r[5]+=0x0000000cu;
goto P_0c0ca0ee;
P_0c0ca0ee: /* original 6703, guest PC 0x0c0ca0ee */
if(!s->budget--) { s->failed_pc=0x0c0ca0eeu; return 0; }
r[7]=r[0];
goto P_0c0ca0f0;
P_0c0ca0f0: /* original 7610, guest PC 0x0c0ca0f0 */
if(!s->budget--) { s->failed_pc=0x0c0ca0f0u; return 0; }
r[6]+=0x00000010u;
goto P_0c0ca0f2;
P_0c0ca0f2: /* original 420b, guest PC 0x0c0ca0f2 */
if(!s->budget--) { s->failed_pc=0x0c0ca0f2u; return 0; }
target=r[2];
r[16]=0x0c0ca0f6u;
r[4]+=0x00000008u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0ca0f6u) { target=s->pc; goto dispatch; }
goto P_0c0ca0f6;
P_0c0ca0f4: /* original 7408, guest PC 0x0c0ca0f4 */
if(!s->budget--) { s->failed_pc=0x0c0ca0f4u; return 0; }
r[4]+=0x00000008u;
goto P_0c0ca0f6;
P_0c0ca0f6: /* original e008, guest PC 0x0c0ca0f6 */
if(!s->budget--) { s->failed_pc=0x0c0ca0f6u; return 0; }
r[0]=0x00000008u;
goto P_0c0ca0f8;
P_0c0ca0f8: /* original f3f6, guest PC 0x0c0ca0f8 */
if(!s->budget--) { s->failed_pc=0x0c0ca0f8u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0ca0fa;
P_0c0ca0fa: /* original e008, guest PC 0x0c0ca0fa */
if(!s->budget--) { s->failed_pc=0x0c0ca0fau; return 0; }
r[0]=0x00000008u;
goto P_0c0ca0fc;
P_0c0ca0fc: /* original fe37, guest PC 0x0c0ca0fc */
if(!s->budget--) { s->failed_pc=0x0c0ca0fcu; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0ca0fe;
P_0c0ca0fe: /* original e00c, guest PC 0x0c0ca0fe */
if(!s->budget--) { s->failed_pc=0x0c0ca0feu; return 0; }
r[0]=0x0000000cu;
goto P_0c0ca100;
P_0c0ca100: /* original f3f6, guest PC 0x0c0ca100 */
if(!s->budget--) { s->failed_pc=0x0c0ca100u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0ca102;
P_0c0ca102: /* original e00c, guest PC 0x0c0ca102 */
if(!s->budget--) { s->failed_pc=0x0c0ca102u; return 0; }
r[0]=0x0000000cu;
goto P_0c0ca104;
P_0c0ca104: /* original fe37, guest PC 0x0c0ca104 */
if(!s->budget--) { s->failed_pc=0x0c0ca104u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0ca106;
P_0c0ca106: /* original e010, guest PC 0x0c0ca106 */
if(!s->budget--) { s->failed_pc=0x0c0ca106u; return 0; }
r[0]=0x00000010u;
goto P_0c0ca108;
P_0c0ca108: /* original f3f6, guest PC 0x0c0ca108 */
if(!s->budget--) { s->failed_pc=0x0c0ca108u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0ca10a;
P_0c0ca10a: /* original e010, guest PC 0x0c0ca10a */
if(!s->budget--) { s->failed_pc=0x0c0ca10au; return 0; }
r[0]=0x00000010u;
goto P_0c0ca10c;
P_0c0ca10c: /* original fe37, guest PC 0x0c0ca10c */
if(!s->budget--) { s->failed_pc=0x0c0ca10cu; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0ca10e;
P_0c0ca10e: /* original 9027, guest PC 0x0c0ca10e */
if(!s->budget--) { s->failed_pc=0x0c0ca10eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ca160u,2);
goto P_0c0ca110;
P_0c0ca110: /* original f3d6, guest PC 0x0c0ca110 */
if(!s->budget--) { s->failed_pc=0x0c0ca110u; return 0; }
vf3_matrix_load(s,ram,3,r[13]+r[0]);
goto P_0c0ca112;
P_0c0ca112: /* original e004, guest PC 0x0c0ca112 */
if(!s->budget--) { s->failed_pc=0x0c0ca112u; return 0; }
r[0]=0x00000004u;
goto P_0c0ca114;
P_0c0ca114: /* original fe37, guest PC 0x0c0ca114 */
if(!s->budget--) { s->failed_pc=0x0c0ca114u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0ca116;
P_0c0ca116: /* original 9024, guest PC 0x0c0ca116 */
if(!s->budget--) { s->failed_pc=0x0c0ca116u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ca162u,2);
goto P_0c0ca118;
P_0c0ca118: /* original f3d6, guest PC 0x0c0ca118 */
if(!s->budget--) { s->failed_pc=0x0c0ca118u; return 0; }
vf3_matrix_load(s,ram,3,r[13]+r[0]);
goto P_0c0ca11a;
P_0c0ca11a: /* original e014, guest PC 0x0c0ca11a */
if(!s->budget--) { s->failed_pc=0x0c0ca11au; return 0; }
r[0]=0x00000014u;
goto P_0c0ca11c;
P_0c0ca11c: /* original fe37, guest PC 0x0c0ca11c */
if(!s->budget--) { s->failed_pc=0x0c0ca11cu; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0ca11e;
P_0c0ca11e: /* original 9021, guest PC 0x0c0ca11e */
if(!s->budget--) { s->failed_pc=0x0c0ca11eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ca164u,2);
goto P_0c0ca120;
P_0c0ca120: /* original f3d6, guest PC 0x0c0ca120 */
if(!s->budget--) { s->failed_pc=0x0c0ca120u; return 0; }
vf3_matrix_load(s,ram,3,r[13]+r[0]);
goto P_0c0ca122;
P_0c0ca122: /* original e028, guest PC 0x0c0ca122 */
if(!s->budget--) { s->failed_pc=0x0c0ca122u; return 0; }
r[0]=0x00000028u;
goto P_0c0ca124;
P_0c0ca124: /* original fe37, guest PC 0x0c0ca124 */
if(!s->budget--) { s->failed_pc=0x0c0ca124u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0ca126;
P_0c0ca126: /* original 901e, guest PC 0x0c0ca126 */
if(!s->budget--) { s->failed_pc=0x0c0ca126u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ca166u,2);
goto P_0c0ca128;
P_0c0ca128: /* original 03dc, guest PC 0x0c0ca128 */
if(!s->budget--) { s->failed_pc=0x0c0ca128u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+r[0],1);
goto P_0c0ca12a;
P_0c0ca12a: /* original e018, guest PC 0x0c0ca12a */
if(!s->budget--) { s->failed_pc=0x0c0ca12au; return 0; }
r[0]=0x00000018u;
goto P_0c0ca12c;
P_0c0ca12c: /* original 0e34, guest PC 0x0c0ca12c */
if(!s->budget--) { s->failed_pc=0x0c0ca12cu; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c0ca12e;
P_0c0ca12e: /* original 901b, guest PC 0x0c0ca12e */
if(!s->budget--) { s->failed_pc=0x0c0ca12eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ca168u,2);
goto P_0c0ca130;
P_0c0ca130: /* original 02dc, guest PC 0x0c0ca130 */
if(!s->budget--) { s->failed_pc=0x0c0ca130u; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+r[0],1);
goto P_0c0ca132;
P_0c0ca132: /* original e019, guest PC 0x0c0ca132 */
if(!s->budget--) { s->failed_pc=0x0c0ca132u; return 0; }
r[0]=0x00000019u;
goto P_0c0ca134;
P_0c0ca134: /* original 0e24, guest PC 0x0c0ca134 */
if(!s->budget--) { s->failed_pc=0x0c0ca134u; return 0; }
write(ram,r[14]+r[0],r[2],1);
goto P_0c0ca136;
P_0c0ca136: /* original 9018, guest PC 0x0c0ca136 */
if(!s->budget--) { s->failed_pc=0x0c0ca136u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ca16au,2);
goto P_0c0ca138;
P_0c0ca138: /* original 7f1c, guest PC 0x0c0ca138 */
if(!s->budget--) { s->failed_pc=0x0c0ca138u; return 0; }
r[15]+=0x0000001cu;
goto P_0c0ca13a;
P_0c0ca13a: /* original 4f26, guest PC 0x0c0ca13a */
if(!s->budget--) { s->failed_pc=0x0c0ca13au; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0ca13c;
P_0c0ca13c: /* original 03dc, guest PC 0x0c0ca13c */
if(!s->budget--) { s->failed_pc=0x0c0ca13cu; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+r[0],1);
goto P_0c0ca13e;
P_0c0ca13e: /* original e01a, guest PC 0x0c0ca13e */
if(!s->budget--) { s->failed_pc=0x0c0ca13eu; return 0; }
r[0]=0x0000001au;
goto P_0c0ca140;
P_0c0ca140: /* original 0e34, guest PC 0x0c0ca140 */
if(!s->budget--) { s->failed_pc=0x0c0ca140u; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c0ca142;
P_0c0ca142: /* original 9013, guest PC 0x0c0ca142 */
if(!s->budget--) { s->failed_pc=0x0c0ca142u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ca16cu,2);
goto P_0c0ca144;
P_0c0ca144: /* original f3d6, guest PC 0x0c0ca144 */
if(!s->budget--) { s->failed_pc=0x0c0ca144u; return 0; }
vf3_matrix_load(s,ram,3,r[13]+r[0]);
goto P_0c0ca146;
P_0c0ca146: /* original e01c, guest PC 0x0c0ca146 */
if(!s->budget--) { s->failed_pc=0x0c0ca146u; return 0; }
r[0]=0x0000001cu;
goto P_0c0ca148;
P_0c0ca148: /* original fe37, guest PC 0x0c0ca148 */
if(!s->budget--) { s->failed_pc=0x0c0ca148u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0ca14a;
P_0c0ca14a: /* original 9010, guest PC 0x0c0ca14a */
if(!s->budget--) { s->failed_pc=0x0c0ca14au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ca16eu,2);
goto P_0c0ca14c;
P_0c0ca14c: /* original f3d6, guest PC 0x0c0ca14c */
if(!s->budget--) { s->failed_pc=0x0c0ca14cu; return 0; }
vf3_matrix_load(s,ram,3,r[13]+r[0]);
goto P_0c0ca14e;
P_0c0ca14e: /* original e020, guest PC 0x0c0ca14e */
if(!s->budget--) { s->failed_pc=0x0c0ca14eu; return 0; }
r[0]=0x00000020u;
goto P_0c0ca150;
P_0c0ca150: /* original fe37, guest PC 0x0c0ca150 */
if(!s->budget--) { s->failed_pc=0x0c0ca150u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0ca152;
P_0c0ca152: /* original 900d, guest PC 0x0c0ca152 */
if(!s->budget--) { s->failed_pc=0x0c0ca152u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ca170u,2);
goto P_0c0ca154;
P_0c0ca154: /* original f3d6, guest PC 0x0c0ca154 */
if(!s->budget--) { s->failed_pc=0x0c0ca154u; return 0; }
vf3_matrix_load(s,ram,3,r[13]+r[0]);
goto P_0c0ca156;
P_0c0ca156: /* original e024, guest PC 0x0c0ca156 */
if(!s->budget--) { s->failed_pc=0x0c0ca156u; return 0; }
r[0]=0x00000024u;
goto P_0c0ca158;
P_0c0ca158: /* original fe37, guest PC 0x0c0ca158 */
if(!s->budget--) { s->failed_pc=0x0c0ca158u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0ca15a;
P_0c0ca15a: /* original 6df6, guest PC 0x0c0ca15a */
if(!s->budget--) { s->failed_pc=0x0c0ca15au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0ca15c;
P_0c0ca15c: /* original 000b, guest PC 0x0c0ca15c */
if(!s->budget--) { s->failed_pc=0x0c0ca15cu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0ca15e: /* original 6ef6, guest PC 0x0c0ca15e */
if(!s->budget--) { s->failed_pc=0x0c0ca15eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0ca160u,s,ram);
P_0c0ca196: /* original 4f22, guest PC 0x0c0ca196 */
if(!s->budget--) { s->failed_pc=0x0c0ca196u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0ca198;
P_0c0ca198: /* original 005d, guest PC 0x0c0ca198 */
if(!s->budget--) { s->failed_pc=0x0c0ca198u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[5]+r[0],2);
goto P_0c0ca19a;
P_0c0ca19a: /* original d34f, guest PC 0x0c0ca19a */
if(!s->budget--) { s->failed_pc=0x0c0ca19au; return 0; }
r[3]=read(ram,0x0c0ca2d8u,4);
goto P_0c0ca19c;
P_0c0ca19c: /* original 7fec, guest PC 0x0c0ca19c */
if(!s->budget--) { s->failed_pc=0x0c0ca19cu; return 0; }
r[15]+=0xffffffecu;
goto P_0c0ca19e;
P_0c0ca19e: /* original d44c, guest PC 0x0c0ca19e */
if(!s->budget--) { s->failed_pc=0x0c0ca19eu; return 0; }
r[4]=read(ram,0x0c0ca2d0u,4);
goto P_0c0ca1a0;
P_0c0ca1a0: /* original 6d32, guest PC 0x0c0ca1a0 */
if(!s->budget--) { s->failed_pc=0x0c0ca1a0u; return 0; }
tmp=read(ram,r[3],4);
r[13]=tmp;
goto P_0c0ca1a2;
P_0c0ca1a2: /* original 81f8, guest PC 0x0c0ca1a2 */
if(!s->budget--) { s->failed_pc=0x0c0ca1a2u; return 0; }
write(ram,r[15]+16,r[0],2);
goto P_0c0ca1a4;
P_0c0ca1a4: /* original e022, guest PC 0x0c0ca1a4 */
if(!s->budget--) { s->failed_pc=0x0c0ca1a4u; return 0; }
r[0]=0x00000022u;
goto P_0c0ca1a6;
P_0c0ca1a6: /* original 005d, guest PC 0x0c0ca1a6 */
if(!s->budget--) { s->failed_pc=0x0c0ca1a6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[5]+r[0],2);
goto P_0c0ca1a8;
P_0c0ca1a8: /* original 6e43, guest PC 0x0c0ca1a8 */
if(!s->budget--) { s->failed_pc=0x0c0ca1a8u; return 0; }
r[14]=r[4];
goto P_0c0ca1aa;
P_0c0ca1aa: /* original 81f6, guest PC 0x0c0ca1aa */
if(!s->budget--) { s->failed_pc=0x0c0ca1aau; return 0; }
write(ram,r[15]+12,r[0],2);
goto P_0c0ca1ac;
P_0c0ca1ac: /* original 2f16, guest PC 0x0c0ca1ac */
if(!s->budget--) { s->failed_pc=0x0c0ca1acu; return 0; }
r[15]-=4; write(ram,r[15],r[1],4);
goto P_0c0ca1ae;
P_0c0ca1ae: /* original 85f8, guest PC 0x0c0ca1ae */
if(!s->budget--) { s->failed_pc=0x0c0ca1aeu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+16,2);
goto P_0c0ca1b0;
P_0c0ca1b0: /* original 2f06, guest PC 0x0c0ca1b0 */
if(!s->budget--) { s->failed_pc=0x0c0ca1b0u; return 0; }
r[15]-=4; write(ram,r[15],r[0],4);
goto P_0c0ca1b2;
P_0c0ca1b2: /* original 85fc, guest PC 0x0c0ca1b2 */
if(!s->budget--) { s->failed_pc=0x0c0ca1b2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+24,2);
goto P_0c0ca1b4;
P_0c0ca1b4: /* original 66f3, guest PC 0x0c0ca1b4 */
if(!s->budget--) { s->failed_pc=0x0c0ca1b4u; return 0; }
r[6]=r[15];
goto P_0c0ca1b6;
P_0c0ca1b6: /* original 65f3, guest PC 0x0c0ca1b6 */
if(!s->budget--) { s->failed_pc=0x0c0ca1b6u; return 0; }
r[5]=r[15];
goto P_0c0ca1b8;
P_0c0ca1b8: /* original d248, guest PC 0x0c0ca1b8 */
if(!s->budget--) { s->failed_pc=0x0c0ca1b8u; return 0; }
r[2]=read(ram,0x0c0ca2dcu,4);
goto P_0c0ca1ba;
P_0c0ca1ba: /* original 64f3, guest PC 0x0c0ca1ba */
if(!s->budget--) { s->failed_pc=0x0c0ca1bau; return 0; }
r[4]=r[15];
goto P_0c0ca1bc;
P_0c0ca1bc: /* original 750c, guest PC 0x0c0ca1bc */
if(!s->budget--) { s->failed_pc=0x0c0ca1bcu; return 0; }
r[5]+=0x0000000cu;
goto P_0c0ca1be;
P_0c0ca1be: /* original 6703, guest PC 0x0c0ca1be */
if(!s->budget--) { s->failed_pc=0x0c0ca1beu; return 0; }
r[7]=r[0];
goto P_0c0ca1c0;
P_0c0ca1c0: /* original 7610, guest PC 0x0c0ca1c0 */
if(!s->budget--) { s->failed_pc=0x0c0ca1c0u; return 0; }
r[6]+=0x00000010u;
goto P_0c0ca1c2;
P_0c0ca1c2: /* original 420b, guest PC 0x0c0ca1c2 */
if(!s->budget--) { s->failed_pc=0x0c0ca1c2u; return 0; }
target=r[2];
r[16]=0x0c0ca1c6u;
r[4]+=0x00000008u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0ca1c6u) { target=s->pc; goto dispatch; }
goto P_0c0ca1c6;
P_0c0ca1c4: /* original 7408, guest PC 0x0c0ca1c4 */
if(!s->budget--) { s->failed_pc=0x0c0ca1c4u; return 0; }
r[4]+=0x00000008u;
goto P_0c0ca1c6;
P_0c0ca1c6: /* original e008, guest PC 0x0c0ca1c6 */
if(!s->budget--) { s->failed_pc=0x0c0ca1c6u; return 0; }
r[0]=0x00000008u;
goto P_0c0ca1c8;
P_0c0ca1c8: /* original f3f6, guest PC 0x0c0ca1c8 */
if(!s->budget--) { s->failed_pc=0x0c0ca1c8u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0ca1ca;
P_0c0ca1ca: /* original e008, guest PC 0x0c0ca1ca */
if(!s->budget--) { s->failed_pc=0x0c0ca1cau; return 0; }
r[0]=0x00000008u;
goto P_0c0ca1cc;
P_0c0ca1cc: /* original fe37, guest PC 0x0c0ca1cc */
if(!s->budget--) { s->failed_pc=0x0c0ca1ccu; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0ca1ce;
P_0c0ca1ce: /* original e00c, guest PC 0x0c0ca1ce */
if(!s->budget--) { s->failed_pc=0x0c0ca1ceu; return 0; }
r[0]=0x0000000cu;
goto P_0c0ca1d0;
P_0c0ca1d0: /* original f3f6, guest PC 0x0c0ca1d0 */
if(!s->budget--) { s->failed_pc=0x0c0ca1d0u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0ca1d2;
P_0c0ca1d2: /* original e00c, guest PC 0x0c0ca1d2 */
if(!s->budget--) { s->failed_pc=0x0c0ca1d2u; return 0; }
r[0]=0x0000000cu;
goto P_0c0ca1d4;
P_0c0ca1d4: /* original fe37, guest PC 0x0c0ca1d4 */
if(!s->budget--) { s->failed_pc=0x0c0ca1d4u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0ca1d6;
P_0c0ca1d6: /* original e010, guest PC 0x0c0ca1d6 */
if(!s->budget--) { s->failed_pc=0x0c0ca1d6u; return 0; }
r[0]=0x00000010u;
goto P_0c0ca1d8;
P_0c0ca1d8: /* original f3f6, guest PC 0x0c0ca1d8 */
if(!s->budget--) { s->failed_pc=0x0c0ca1d8u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0ca1da;
P_0c0ca1da: /* original e010, guest PC 0x0c0ca1da */
if(!s->budget--) { s->failed_pc=0x0c0ca1dau; return 0; }
r[0]=0x00000010u;
goto P_0c0ca1dc;
P_0c0ca1dc: /* original fe37, guest PC 0x0c0ca1dc */
if(!s->budget--) { s->failed_pc=0x0c0ca1dcu; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0ca1de;
P_0c0ca1de: /* original 906e, guest PC 0x0c0ca1de */
if(!s->budget--) { s->failed_pc=0x0c0ca1deu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ca2beu,2);
goto P_0c0ca1e0;
P_0c0ca1e0: /* original f3d6, guest PC 0x0c0ca1e0 */
if(!s->budget--) { s->failed_pc=0x0c0ca1e0u; return 0; }
vf3_matrix_load(s,ram,3,r[13]+r[0]);
goto P_0c0ca1e2;
P_0c0ca1e2: /* original e004, guest PC 0x0c0ca1e2 */
if(!s->budget--) { s->failed_pc=0x0c0ca1e2u; return 0; }
r[0]=0x00000004u;
goto P_0c0ca1e4;
P_0c0ca1e4: /* original fe37, guest PC 0x0c0ca1e4 */
if(!s->budget--) { s->failed_pc=0x0c0ca1e4u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0ca1e6;
P_0c0ca1e6: /* original 906b, guest PC 0x0c0ca1e6 */
if(!s->budget--) { s->failed_pc=0x0c0ca1e6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ca2c0u,2);
goto P_0c0ca1e8;
P_0c0ca1e8: /* original f3d6, guest PC 0x0c0ca1e8 */
if(!s->budget--) { s->failed_pc=0x0c0ca1e8u; return 0; }
vf3_matrix_load(s,ram,3,r[13]+r[0]);
goto P_0c0ca1ea;
P_0c0ca1ea: /* original e014, guest PC 0x0c0ca1ea */
if(!s->budget--) { s->failed_pc=0x0c0ca1eau; return 0; }
r[0]=0x00000014u;
goto P_0c0ca1ec;
P_0c0ca1ec: /* original fe37, guest PC 0x0c0ca1ec */
if(!s->budget--) { s->failed_pc=0x0c0ca1ecu; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0ca1ee;
P_0c0ca1ee: /* original 9068, guest PC 0x0c0ca1ee */
if(!s->budget--) { s->failed_pc=0x0c0ca1eeu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ca2c2u,2);
goto P_0c0ca1f0;
P_0c0ca1f0: /* original f3d6, guest PC 0x0c0ca1f0 */
if(!s->budget--) { s->failed_pc=0x0c0ca1f0u; return 0; }
vf3_matrix_load(s,ram,3,r[13]+r[0]);
goto P_0c0ca1f2;
P_0c0ca1f2: /* original e028, guest PC 0x0c0ca1f2 */
if(!s->budget--) { s->failed_pc=0x0c0ca1f2u; return 0; }
r[0]=0x00000028u;
goto P_0c0ca1f4;
P_0c0ca1f4: /* original fe37, guest PC 0x0c0ca1f4 */
if(!s->budget--) { s->failed_pc=0x0c0ca1f4u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0ca1f6;
P_0c0ca1f6: /* original 9065, guest PC 0x0c0ca1f6 */
if(!s->budget--) { s->failed_pc=0x0c0ca1f6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ca2c4u,2);
goto P_0c0ca1f8;
P_0c0ca1f8: /* original 03dc, guest PC 0x0c0ca1f8 */
if(!s->budget--) { s->failed_pc=0x0c0ca1f8u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+r[0],1);
goto P_0c0ca1fa;
P_0c0ca1fa: /* original e018, guest PC 0x0c0ca1fa */
if(!s->budget--) { s->failed_pc=0x0c0ca1fau; return 0; }
r[0]=0x00000018u;
goto P_0c0ca1fc;
P_0c0ca1fc: /* original 0e34, guest PC 0x0c0ca1fc */
if(!s->budget--) { s->failed_pc=0x0c0ca1fcu; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c0ca1fe;
P_0c0ca1fe: /* original 9062, guest PC 0x0c0ca1fe */
if(!s->budget--) { s->failed_pc=0x0c0ca1feu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ca2c6u,2);
goto P_0c0ca200;
P_0c0ca200: /* original 02dc, guest PC 0x0c0ca200 */
if(!s->budget--) { s->failed_pc=0x0c0ca200u; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+r[0],1);
goto P_0c0ca202;
P_0c0ca202: /* original e019, guest PC 0x0c0ca202 */
if(!s->budget--) { s->failed_pc=0x0c0ca202u; return 0; }
r[0]=0x00000019u;
goto P_0c0ca204;
P_0c0ca204: /* original 0e24, guest PC 0x0c0ca204 */
if(!s->budget--) { s->failed_pc=0x0c0ca204u; return 0; }
write(ram,r[14]+r[0],r[2],1);
goto P_0c0ca206;
P_0c0ca206: /* original 905f, guest PC 0x0c0ca206 */
if(!s->budget--) { s->failed_pc=0x0c0ca206u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ca2c8u,2);
goto P_0c0ca208;
P_0c0ca208: /* original 7f1c, guest PC 0x0c0ca208 */
if(!s->budget--) { s->failed_pc=0x0c0ca208u; return 0; }
r[15]+=0x0000001cu;
goto P_0c0ca20a;
P_0c0ca20a: /* original 4f26, guest PC 0x0c0ca20a */
if(!s->budget--) { s->failed_pc=0x0c0ca20au; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0ca20c;
P_0c0ca20c: /* original 03dc, guest PC 0x0c0ca20c */
if(!s->budget--) { s->failed_pc=0x0c0ca20cu; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+r[0],1);
goto P_0c0ca20e;
P_0c0ca20e: /* original e01a, guest PC 0x0c0ca20e */
if(!s->budget--) { s->failed_pc=0x0c0ca20eu; return 0; }
r[0]=0x0000001au;
goto P_0c0ca210;
P_0c0ca210: /* original 0e34, guest PC 0x0c0ca210 */
if(!s->budget--) { s->failed_pc=0x0c0ca210u; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c0ca212;
P_0c0ca212: /* original 905a, guest PC 0x0c0ca212 */
if(!s->budget--) { s->failed_pc=0x0c0ca212u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ca2cau,2);
goto P_0c0ca214;
P_0c0ca214: /* original f3d6, guest PC 0x0c0ca214 */
if(!s->budget--) { s->failed_pc=0x0c0ca214u; return 0; }
vf3_matrix_load(s,ram,3,r[13]+r[0]);
goto P_0c0ca216;
P_0c0ca216: /* original e01c, guest PC 0x0c0ca216 */
if(!s->budget--) { s->failed_pc=0x0c0ca216u; return 0; }
r[0]=0x0000001cu;
goto P_0c0ca218;
P_0c0ca218: /* original fe37, guest PC 0x0c0ca218 */
if(!s->budget--) { s->failed_pc=0x0c0ca218u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0ca21a;
P_0c0ca21a: /* original 9057, guest PC 0x0c0ca21a */
if(!s->budget--) { s->failed_pc=0x0c0ca21au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ca2ccu,2);
goto P_0c0ca21c;
P_0c0ca21c: /* original f3d6, guest PC 0x0c0ca21c */
if(!s->budget--) { s->failed_pc=0x0c0ca21cu; return 0; }
vf3_matrix_load(s,ram,3,r[13]+r[0]);
goto P_0c0ca21e;
P_0c0ca21e: /* original e020, guest PC 0x0c0ca21e */
if(!s->budget--) { s->failed_pc=0x0c0ca21eu; return 0; }
r[0]=0x00000020u;
goto P_0c0ca220;
P_0c0ca220: /* original fe37, guest PC 0x0c0ca220 */
if(!s->budget--) { s->failed_pc=0x0c0ca220u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0ca222;
P_0c0ca222: /* original 9054, guest PC 0x0c0ca222 */
if(!s->budget--) { s->failed_pc=0x0c0ca222u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ca2ceu,2);
goto P_0c0ca224;
P_0c0ca224: /* original f3d6, guest PC 0x0c0ca224 */
if(!s->budget--) { s->failed_pc=0x0c0ca224u; return 0; }
vf3_matrix_load(s,ram,3,r[13]+r[0]);
goto P_0c0ca226;
P_0c0ca226: /* original e024, guest PC 0x0c0ca226 */
if(!s->budget--) { s->failed_pc=0x0c0ca226u; return 0; }
r[0]=0x00000024u;
goto P_0c0ca228;
P_0c0ca228: /* original fe37, guest PC 0x0c0ca228 */
if(!s->budget--) { s->failed_pc=0x0c0ca228u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0ca22a;
P_0c0ca22a: /* original 6df6, guest PC 0x0c0ca22a */
if(!s->budget--) { s->failed_pc=0x0c0ca22au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0ca22c;
P_0c0ca22c: /* original 000b, guest PC 0x0c0ca22c */
if(!s->budget--) { s->failed_pc=0x0c0ca22cu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0ca22e: /* original 6ef6, guest PC 0x0c0ca22e */
if(!s->budget--) { s->failed_pc=0x0c0ca22eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0ca230u,s,ram);
unsupported: s->failed_pc=target; return 0;
}
static const uint32_t owned_pcs[]={
0x0c038eaeu,0x0c038eb0u,0x0c038eb2u,0x0c038eb4u,0x0c038eb6u,0x0c038eb8u,0x0c038ebau,0x0c038ebcu,0x0c038ebeu,0x0c038ec0u,0x0c038ec2u,0x0c038ec4u,0x0c038ec6u,0x0c038ec8u,0x0c038ecau,0x0c038eccu,
0x0c038eceu,0x0c038ed0u,0x0c038ed2u,0x0c038ed4u,0x0c038ed6u,0x0c038ed8u,0x0c038edau,0x0c038edcu,0x0c038edeu,0x0c038ee0u,0x0c038ee2u,0x0c038ee4u,0x0c038ee6u,0x0c038ee8u,0x0c038eeau,0x0c038eecu,
0x0c038eeeu,0x0c038ef0u,0x0c038ef2u,0x0c038ef4u,0x0c038ef6u,0x0c038ef8u,0x0c038efau,0x0c038efcu,0x0c038efeu,0x0c038f00u,0x0c038f02u,0x0c038f04u,0x0c038f06u,0x0c038f08u,0x0c038f0au,0x0c038f0cu,
0x0c038f0eu,0x0c038f10u,0x0c038f12u,0x0c038f14u,0x0c038f16u,0x0c038f18u,0x0c038f1au,0x0c038f1cu,0x0c038f1eu,0x0c038f20u,0x0c038f22u,0x0c038f24u,0x0c038f26u,0x0c038f28u,0x0c038f2au,0x0c038f2cu,
0x0c038f2eu,0x0c038f30u,0x0c038f32u,0x0c038f34u,0x0c038f36u,0x0c038f38u,0x0c038f4eu,0x0c038f50u,0x0c038f52u,0x0c038f54u,0x0c038f56u,0x0c038f58u,0x0c038f5au,0x0c038f5cu,0x0c038f5eu,0x0c038f60u,
0x0c038f62u,0x0c038f64u,0x0c038f66u,0x0c038f68u,0x0c038f6au,0x0c038f6cu,0x0c038f6eu,0x0c038f70u,0x0c038f72u,0x0c038f74u,0x0c038f76u,0x0c038f78u,0x0c038f7au,0x0c038f7cu,0x0c038f7eu,0x0c038f80u,
0x0c038f82u,0x0c038f84u,0x0c038f86u,0x0c038f88u,0x0c038f8au,0x0c038f8cu,0x0c038f8eu,0x0c038f90u,0x0c038f92u,0x0c038f94u,0x0c038f96u,0x0c038f98u,0x0c038f9au,0x0c038f9cu,0x0c038f9eu,0x0c038fa0u,
0x0c038fa2u,0x0c038fa4u,0x0c038fa6u,0x0c038fa8u,0x0c038faau,0x0c038facu,0x0c038faeu,0x0c038fb0u,0x0c038fb2u,0x0c038fb4u,0x0c038fb6u,0x0c038fb8u,0x0c038fbau,0x0c038fbcu,0x0c038fbeu,0x0c038fc0u,
0x0c038fc2u,0x0c038fc4u,0x0c038fc6u,0x0c038fc8u,0x0c038fcau,0x0c038fccu,0x0c038fceu,0x0c038fd0u,0x0c038fd2u,0x0c038fd4u,0x0c038fd6u,0x0c03a370u,0x0c03a372u,0x0c03a374u,0x0c03a376u,0x0c03a378u,
0x0c03a37au,0x0c03a380u,0x0c03a382u,0x0c03a384u,0x0c03a386u,0x0c03a388u,0x0c03bb40u,0x0c03bb42u,0x0c03bb44u,0x0c03bb46u,0x0c03bb48u,0x0c03bb4au,0x0c03bb4cu,0x0c03bb4eu,0x0c03bb50u,0x0c03bb52u,
0x0c03bb54u,0x0c03bb56u,0x0c03bb58u,0x0c03bb5au,0x0c03bb5cu,0x0c03bb5eu,0x0c03bb60u,0x0c03bb62u,0x0c03bb64u,0x0c03bb66u,0x0c03bb68u,0x0c03bb6au,0x0c03bb6cu,0x0c03bb6eu,0x0c03bb70u,0x0c03bb72u,
0x0c03bb74u,0x0c03bb76u,0x0c03bb78u,0x0c03bb7au,0x0c03bb7cu,0x0c03bb7eu,0x0c03bb80u,0x0c03bb82u,0x0c03bb84u,0x0c03bb86u,0x0c03bb88u,0x0c03bb8au,0x0c03bb8cu,0x0c03bb8eu,0x0c03bb90u,0x0c03bb92u,
0x0c03bb94u,0x0c03bb96u,0x0c03bb98u,0x0c03bb9au,0x0c03bb9cu,0x0c03bb9eu,0x0c03bba0u,0x0c03bba2u,0x0c03bba4u,0x0c03bba6u,0x0c03bba8u,0x0c03bbaau,0x0c03bbacu,0x0c03bbaeu,0x0c03bbb0u,0x0c03bbb2u,
0x0c03bbb4u,0x0c03bbb6u,0x0c03bbb8u,0x0c03bbbau,0x0c03bbbcu,0x0c03bbbeu,0x0c03bbc0u,0x0c03bbc2u,0x0c03bbc4u,0x0c03bbc6u,0x0c03bbc8u,0x0c03bbcau,0x0c03bbccu,0x0c03bbceu,0x0c03bfb6u,0x0c03bfb8u,
0x0c03bfbau,0x0c03bfbcu,0x0c03bfbeu,0x0c03bfc0u,0x0c03bfc2u,0x0c03bfc4u,0x0c03bfc6u,0x0c03bfc8u,0x0c03bfcau,0x0c03bfccu,0x0c03bfceu,0x0c03bfd0u,0x0c03bfd2u,0x0c03bfd4u,0x0c03bfd6u,0x0c03bfd8u,
0x0c03bfdau,0x0c03bfdcu,0x0c03bfdeu,0x0c03bfe0u,0x0c03bfe2u,0x0c03bfe4u,0x0c03bfe6u,0x0c03bfe8u,0x0c03bfeau,0x0c03bfecu,0x0c03bfeeu,0x0c03bff0u,0x0c03bff2u,0x0c03bff4u,0x0c03bff6u,0x0c03bff8u,
0x0c03bffau,0x0c03bffcu,0x0c03bffeu,0x0c03c000u,0x0c03c002u,0x0c03c004u,0x0c03c006u,0x0c03c008u,0x0c03c00au,0x0c03c00cu,0x0c03c00eu,0x0c03c010u,0x0c03c012u,0x0c03c014u,0x0c03c016u,0x0c03c018u,
0x0c03c01au,0x0c03c01cu,0x0c03c01eu,0x0c03c020u,0x0c03c022u,0x0c03c024u,0x0c03c026u,0x0c03c028u,0x0c03c02au,0x0c03c02cu,0x0c03c02eu,0x0c03c030u,0x0c03c032u,0x0c03c034u,0x0c03c036u,0x0c03c038u,
0x0c03c03au,0x0c03c03cu,0x0c03c03eu,0x0c03c040u,0x0c03c042u,0x0c03c044u,0x0c03c046u,0x0c03c048u,0x0c03c04au,0x0c03c04cu,0x0c03c04eu,0x0c03c050u,0x0c03c052u,0x0c03c054u,0x0c03c056u,0x0c03c058u,
0x0c03c05au,0x0c03c05cu,0x0c03c05eu,0x0c03c060u,0x0c03c062u,0x0c03c064u,0x0c03c066u,0x0c03c068u,0x0c03c06au,0x0c03c06cu,0x0c03c06eu,0x0c03c070u,0x0c03c072u,0x0c03c074u,0x0c03c076u,0x0c03c078u,
0x0c03c07au,0x0c03c252u,0x0c03c254u,0x0c03c256u,0x0c03c258u,0x0c03c25au,0x0c03c25cu,0x0c03c25eu,0x0c03c260u,0x0c03c262u,0x0c03c264u,0x0c03c266u,0x0c03c268u,0x0c03c26au,0x0c03c26cu,0x0c03c26eu,
0x0c03c270u,0x0c03c272u,0x0c03c274u,0x0c03c276u,0x0c03c278u,0x0c03c27au,0x0c03c27cu,0x0c03c27eu,0x0c03c280u,0x0c03c282u,0x0c03c284u,0x0c03c286u,0x0c03c288u,0x0c03c28au,0x0c03c28cu,0x0c03c28eu,
0x0c03c290u,0x0c03c292u,0x0c03c294u,0x0c03c296u,0x0c03c298u,0x0c03c29au,0x0c03c29cu,0x0c03c29eu,0x0c03c2a0u,0x0c03c2a2u,0x0c03c2a4u,0x0c03c2a6u,0x0c03c2a8u,0x0c03c2aau,0x0c03c2acu,0x0c03c2aeu,
0x0c03c2b0u,0x0c03c2b2u,0x0c03c2b4u,0x0c03c2b6u,0x0c03c2b8u,0x0c03c2bau,0x0c03c2bcu,0x0c03c2beu,0x0c03c2c0u,0x0c03c2c2u,0x0c03c2c4u,0x0c03c2c6u,0x0c03c2c8u,0x0c03c2cau,0x0c03c2ccu,0x0c03c2ceu,
0x0c03c2d0u,0x0c03c2d2u,0x0c03c2d4u,0x0c03c2d6u,0x0c03c2d8u,0x0c03c2dau,0x0c03c2dcu,0x0c03c2deu,0x0c03c2e0u,0x0c03c2e2u,0x0c03c2e4u,0x0c03c2e6u,0x0c03c2e8u,0x0c03c2eau,0x0c03c2ecu,0x0c03c2eeu,
0x0c03c2f0u,0x0c03c2f2u,0x0c03c2f4u,0x0c03c2f6u,0x0c03c2f8u,0x0c03c2fau,0x0c03c2fcu,0x0c03c2feu,0x0c03c300u,0x0c03c302u,0x0c03c304u,0x0c03c306u,0x0c03c308u,0x0c03c30au,0x0c03c324u,0x0c03c326u,
0x0c03c328u,0x0c03c32au,0x0c03c32cu,0x0c03c32eu,0x0c03c330u,0x0c03c332u,0x0c03c334u,0x0c03c336u,0x0c03c338u,0x0c03c33au,0x0c03c33cu,0x0c03c33eu,0x0c03c340u,0x0c03c342u,0x0c03c344u,0x0c03c346u,
0x0c03c348u,0x0c03c34au,0x0c03c34cu,0x0c03c34eu,0x0c03c350u,0x0c03c352u,0x0c03c354u,0x0c03c356u,0x0c03c358u,0x0c03c35au,0x0c03c35cu,0x0c03c35eu,0x0c03c360u,0x0c03c362u,0x0c03c364u,0x0c03c366u,
0x0c03c368u,0x0c03c36au,0x0c03c36cu,0x0c03c36eu,0x0c03c370u,0x0c03c372u,0x0c03c374u,0x0c03c376u,0x0c03c378u,0x0c03c37au,0x0c03c37cu,0x0c03c37eu,0x0c03c380u,0x0c03c382u,0x0c03c384u,0x0c03c386u,
0x0c03c388u,0x0c03c38au,0x0c03c38cu,0x0c03c38eu,0x0c03c390u,0x0c03c392u,0x0c03c394u,0x0c03c396u,0x0c03c398u,0x0c03c39au,0x0c03c39cu,0x0c03c39eu,0x0c03c3a0u,0x0c03c3a2u,0x0c03c3a4u,0x0c03c3a6u,
0x0c03c3a8u,0x0c03c3aau,0x0c03c3acu,0x0c03c3aeu,0x0c03c3b0u,0x0c03c3b2u,0x0c03c3b4u,0x0c03c3b6u,0x0c03c3b8u,0x0c03c3bau,0x0c03c3bcu,0x0c03c3beu,0x0c03c3c0u,0x0c03c3c2u,0x0c03c3c4u,0x0c03c3c6u,
0x0c03c3c8u,0x0c03c3cau,0x0c03c3ccu,0x0c03c3ceu,0x0c03c3d0u,0x0c03c3d2u,0x0c03c3d4u,0x0c03c3d6u,0x0c03c3d8u,0x0c03c3dau,0x0c03c3dcu,0x0c03c3deu,0x0c03c3e0u,0x0c03c3e2u,0x0c03c3e4u,0x0c03c3e6u,
0x0c03c3e8u,0x0c03c3eau,0x0c03c3ecu,0x0c03c3eeu,0x0c03c3f0u,0x0c03c3f2u,0x0c03c3f4u,0x0c03c3f6u,0x0c03c3f8u,0x0c03c3fau,0x0c03c3fcu,0x0c03c3feu,0x0c03c400u,0x0c03c402u,0x0c03c404u,0x0c03c406u,
0x0c03c408u,0x0c03c40au,0x0c03c40cu,0x0c03c40eu,0x0c03c410u,0x0c03c412u,0x0c03c414u,0x0c03c416u,0x0c03c418u,0x0c03c41au,0x0c03c41cu,0x0c03c41eu,0x0c03c420u,0x0c03c422u,0x0c03c424u,0x0c03c426u,
0x0c03c428u,0x0c03c42au,0x0c03c42cu,0x0c03c42eu,0x0c03c430u,0x0c03c432u,0x0c03c434u,0x0c03c6f0u,0x0c03c6f2u,0x0c03c6f4u,0x0c03c6f6u,0x0c03c6f8u,0x0c03c6fau,0x0c03c6fcu,0x0c03c6feu,0x0c03c700u,
0x0c03c702u,0x0c03c704u,0x0c03c706u,0x0c03c708u,0x0c03c70au,0x0c03c70cu,0x0c03c70eu,0x0c03c710u,0x0c03c712u,0x0c03c714u,0x0c03c716u,0x0c03cc70u,0x0c03cc72u,0x0c03cc74u,0x0c03cc76u,0x0c03cc78u,
0x0c03cc7au,0x0c03cc7cu,0x0c03cc7eu,0x0c03cc80u,0x0c03cc82u,0x0c03cc84u,0x0c03cc86u,0x0c03cc88u,0x0c03d0e8u,0x0c03d0eau,0x0c03d0ecu,0x0c03d0eeu,0x0c03d0f0u,0x0c03d0f2u,0x0c03d0f4u,0x0c03d0f6u,
0x0c03d0f8u,0x0c03d0fau,0x0c03d0fcu,0x0c03d0feu,0x0c03d100u,0x0c03d102u,0x0c03d104u,0x0c03d106u,0x0c03d108u,0x0c03d10au,0x0c03d10cu,0x0c03d10eu,0x0c03d110u,0x0c03d112u,0x0c03d114u,0x0c03d116u,
0x0c03d118u,0x0c03d11au,0x0c03d11cu,0x0c03d11eu,0x0c03d120u,0x0c03d122u,0x0c03d124u,0x0c03d126u,0x0c03d128u,0x0c03d12au,0x0c03d12cu,0x0c03d12eu,0x0c03d130u,0x0c03d132u,0x0c03d134u,0x0c03d136u,
0x0c03d138u,0x0c03d13au,0x0c03d13cu,0x0c03d13eu,0x0c03d140u,0x0c03d142u,0x0c03d144u,0x0c03d146u,0x0c03d148u,0x0c03d14au,0x0c03d14cu,0x0c03d14eu,0x0c03d150u,0x0c03d152u,0x0c03d154u,0x0c03d156u,
0x0c03d158u,0x0c03d15au,0x0c03d15cu,0x0c03d15eu,0x0c03d160u,0x0c03d162u,0x0c03d164u,0x0c03d166u,0x0c03d168u,0x0c03d16au,0x0c03d16cu,0x0c03d16eu,0x0c03d170u,0x0c03d172u,0x0c03d174u,0x0c03d176u,
0x0c03d178u,0x0c03d17au,0x0c03d17cu,0x0c03d17eu,0x0c03d180u,0x0c03d182u,0x0c03d184u,0x0c03d186u,0x0c03d188u,0x0c03d18au,0x0c03d18cu,0x0c03d18eu,0x0c03d190u,0x0c03d192u,0x0c03d194u,0x0c03d196u,
0x0c03d198u,0x0c03d19au,0x0c03d19cu,0x0c03d1a8u,0x0c03d1aau,0x0c03d1acu,0x0c03d1aeu,0x0c03d1b0u,0x0c03d1b2u,0x0c03d1b4u,0x0c03d1b6u,0x0c03d1b8u,0x0c03d1bau,0x0c03d1bcu,0x0c03d1beu,0x0c03d1c0u,
0x0c03d1c2u,0x0c03d1c4u,0x0c03d1c6u,0x0c03d1c8u,0x0c03d1cau,0x0c03d1ccu,0x0c03d1ceu,0x0c03d1d0u,0x0c03d1d2u,0x0c03d1d4u,0x0c03d1d6u,0x0c03d1d8u,0x0c03d1dau,0x0c03d1dcu,0x0c03d1deu,0x0c03d1e0u,
0x0c03d1e2u,0x0c03d1e4u,0x0c03d1e6u,0x0c03d1e8u,0x0c03d1eau,0x0c03d1ecu,0x0c03d1eeu,0x0c03d1f0u,0x0c03d1f2u,0x0c03d1f4u,0x0c03d1f6u,0x0c03d1f8u,0x0c03d1fau,0x0c03d1fcu,0x0c03d1feu,0x0c03d200u,
0x0c03d202u,0x0c03d204u,0x0c03d206u,0x0c03d208u,0x0c03d20au,0x0c03d20cu,0x0c03d20eu,0x0c03d210u,0x0c03d212u,0x0c03d214u,0x0c03d216u,0x0c03d218u,0x0c03d21au,0x0c03d21cu,0x0c03d21eu,0x0c03d220u,
0x0c03d222u,0x0c03d224u,0x0c03d226u,0x0c03d228u,0x0c03d22au,0x0c03d22cu,0x0c03d22eu,0x0c03d230u,0x0c03d232u,0x0c03d234u,0x0c03d236u,0x0c03d238u,0x0c03d23au,0x0c03d23cu,0x0c03d23eu,0x0c03d240u,
0x0c03d242u,0x0c03d244u,0x0c03d246u,0x0c03d248u,0x0c03d24au,0x0c03d24cu,0x0c03d24eu,0x0c03d250u,0x0c03d252u,0x0c03d254u,0x0c03d256u,0x0c03d258u,0x0c0645fau,0x0c0645fcu,0x0c0645feu,0x0c064600u,
0x0c064602u,0x0c064604u,0x0c064606u,0x0c064608u,0x0c06460au,0x0c06460cu,0x0c06460eu,0x0c064610u,0x0c064612u,0x0c064614u,0x0c064616u,0x0c064618u,0x0c06461au,0x0c06461cu,0x0c06461eu,0x0c064620u,
0x0c064622u,0x0c064624u,0x0c064626u,0x0c064628u,0x0c06462au,0x0c06462cu,0x0c06462eu,0x0c064630u,0x0c064632u,0x0c064634u,0x0c064636u,0x0c064638u,0x0c06463au,0x0c06463cu,0x0c06463eu,0x0c064640u,
0x0c064642u,0x0c064644u,0x0c064646u,0x0c064648u,0x0c06464au,0x0c06464cu,0x0c06464eu,0x0c064650u,0x0c064652u,0x0c064654u,0x0c064656u,0x0c064658u,0x0c06465au,0x0c06465cu,0x0c06465eu,0x0c064660u,
0x0c064662u,0x0c064664u,0x0c064666u,0x0c064668u,0x0c06466au,0x0c06466cu,0x0c06466eu,0x0c064670u,0x0c064672u,0x0c064674u,0x0c064676u,0x0c064678u,0x0c06467au,0x0c06467cu,0x0c06467eu,0x0c064680u,
0x0c064682u,0x0c064684u,0x0c064686u,0x0c064688u,0x0c06468au,0x0c06468cu,0x0c06468eu,0x0c064690u,0x0c064692u,0x0c064694u,0x0c064696u,0x0c064698u,0x0c06469au,0x0c06469cu,0x0c06469eu,0x0c0646a0u,
0x0c0646a2u,0x0c0646a4u,0x0c0646a6u,0x0c0646a8u,0x0c0646aau,0x0c0646acu,0x0c0646aeu,0x0c0646b0u,0x0c0646b2u,0x0c0646b4u,0x0c0646b6u,0x0c0646b8u,0x0c0646bau,0x0c0646bcu,0x0c0646beu,0x0c0646c0u,
0x0c0646c2u,0x0c0646c4u,0x0c0646c6u,0x0c0646c8u,0x0c0646cau,0x0c0646ccu,0x0c0646ceu,0x0c0646d0u,0x0c0646d2u,0x0c0646d4u,0x0c0646d6u,0x0c0646d8u,0x0c0646dau,0x0c0646dcu,0x0c0646deu,0x0c0646e0u,
0x0c0646e2u,0x0c0646e4u,0x0c0646e6u,0x0c0646e8u,0x0c0646eau,0x0c0646ecu,0x0c0646eeu,0x0c0646f0u,0x0c0646f2u,0x0c0646f4u,0x0c0646f6u,0x0c064930u,0x0c064932u,0x0c064934u,0x0c064936u,0x0c064938u,
0x0c06493au,0x0c06493cu,0x0c06493eu,0x0c064940u,0x0c064942u,0x0c064944u,0x0c064946u,0x0c064948u,0x0c06494au,0x0c06494cu,0x0c06494eu,0x0c064950u,0x0c064952u,0x0c064954u,0x0c064956u,0x0c064958u,
0x0c06495au,0x0c06495cu,0x0c06495eu,0x0c064960u,0x0c064962u,0x0c064964u,0x0c064966u,0x0c064968u,0x0c06496au,0x0c06496cu,0x0c06496eu,0x0c064970u,0x0c064972u,0x0c064974u,0x0c064976u,0x0c064978u,
0x0c06497au,0x0c06497cu,0x0c06497eu,0x0c064980u,0x0c064982u,0x0c064984u,0x0c064986u,0x0c064988u,0x0c06498au,0x0c06498cu,0x0c06498eu,0x0c064990u,0x0c064992u,0x0c064994u,0x0c064996u,0x0c064998u,
0x0c06499au,0x0c06499cu,0x0c06499eu,0x0c0649a0u,0x0c0649a2u,0x0c0649a4u,0x0c0649a6u,0x0c0649a8u,0x0c0649aau,0x0c0649acu,0x0c0649aeu,0x0c0649b0u,0x0c0649b2u,0x0c0649b4u,0x0c0649b6u,0x0c0649b8u,
0x0c0649bau,0x0c0649bcu,0x0c0649beu,0x0c0649c0u,0x0c0649c2u,0x0c0649c4u,0x0c0649c6u,0x0c0649c8u,0x0c0649cau,0x0c0649ccu,0x0c0649ceu,0x0c0649d0u,0x0c0649d2u,0x0c0649d4u,0x0c0649d6u,0x0c0649d8u,
0x0c0649dau,0x0c0649dcu,0x0c0649deu,0x0c0649e0u,0x0c0649e2u,0x0c0649e4u,0x0c0649e6u,0x0c0649e8u,0x0c0649eau,0x0c0649ecu,0x0c0649eeu,0x0c0649f0u,0x0c0649f2u,0x0c0649f4u,0x0c0649f6u,0x0c0649f8u,
0x0c0649fau,0x0c0649fcu,0x0c0649feu,0x0c064a00u,0x0c064a02u,0x0c064a04u,0x0c064a06u,0x0c064a08u,0x0c064a0au,0x0c064a0cu,0x0c064a0eu,0x0c064a10u,0x0c064a12u,0x0c064a14u,0x0c064a16u,0x0c064a18u,
0x0c064a1au,0x0c064a1cu,0x0c064a1eu,0x0c064a20u,0x0c064a22u,0x0c064a24u,0x0c064a26u,0x0c064a28u,0x0c064a2au,0x0c064a2cu,0x0c064a2eu,0x0c064a30u,0x0c064a32u,0x0c064a34u,0x0c064a36u,0x0c064a38u,
0x0c064a3au,0x0c064a3cu,0x0c064a3eu,0x0c064a40u,0x0c064a42u,0x0c064a44u,0x0c064a46u,0x0c064a48u,0x0c064a4au,0x0c064a4cu,0x0c064a4eu,0x0c064a50u,0x0c064a52u,0x0c064a54u,0x0c064a56u,0x0c064a58u,
0x0c064a5au,0x0c064a5cu,0x0c064a5eu,0x0c064a60u,0x0c064a62u,0x0c064a64u,0x0c064a66u,0x0c064a68u,0x0c064a6au,0x0c064a6cu,0x0c064a6eu,0x0c064a70u,0x0c064a72u,0x0c064a74u,0x0c064a76u,0x0c064a78u,
0x0c064a7au,0x0c064a7cu,0x0c064a7eu,0x0c064a80u,0x0c064a82u,0x0c064a84u,0x0c064a86u,0x0c064a88u,0x0c064a8au,0x0c064a8cu,0x0c0657fcu,0x0c0657feu,0x0c065800u,0x0c065802u,0x0c065804u,0x0c065806u,
0x0c065808u,0x0c06580au,0x0c06580cu,0x0c06580eu,0x0c065810u,0x0c065812u,0x0c065814u,0x0c065816u,0x0c065818u,0x0c06581au,0x0c06581cu,0x0c06581eu,0x0c065820u,0x0c065822u,0x0c065824u,0x0c065826u,
0x0c065828u,0x0c06582au,0x0c06582cu,0x0c06582eu,0x0c065830u,0x0c065832u,0x0c065834u,0x0c065836u,0x0c065838u,0x0c06583au,0x0c06583cu,0x0c06583eu,0x0c065840u,0x0c065842u,0x0c065844u,0x0c065846u,
0x0c065848u,0x0c06584au,0x0c06584cu,0x0c06584eu,0x0c065850u,0x0c065852u,0x0c065854u,0x0c065856u,0x0c065858u,0x0c06585au,0x0c06585cu,0x0c06585eu,0x0c065860u,0x0c065862u,0x0c065864u,0x0c065866u,
0x0c065868u,0x0c06586au,0x0c06586cu,0x0c06586eu,0x0c065870u,0x0c065872u,0x0c065874u,0x0c065876u,0x0c065878u,0x0c06587au,0x0c06587cu,0x0c06587eu,0x0c065880u,0x0c065882u,0x0c065884u,0x0c065886u,
0x0c065888u,0x0c06588au,0x0c06588cu,0x0c06588eu,0x0c065890u,0x0c065892u,0x0c065894u,0x0c065896u,0x0c065898u,0x0c06589au,0x0c06589cu,0x0c06589eu,0x0c0658a0u,0x0c0658a2u,0x0c0658a4u,0x0c0658a6u,
0x0c0658a8u,0x0c0658aau,0x0c0658acu,0x0c0658aeu,0x0c0658b0u,0x0c0658b2u,0x0c0658b4u,0x0c0658b6u,0x0c0658b8u,0x0c0658bau,0x0c0658bcu,0x0c0658beu,0x0c0658c0u,0x0c0658c2u,0x0c0658c4u,0x0c0658c6u,
0x0c0658c8u,0x0c0658cau,0x0c0658ccu,0x0c0658ceu,0x0c0658d0u,0x0c0658d2u,0x0c0658d4u,0x0c0658d6u,0x0c0658d8u,0x0c0658dau,0x0c0658dcu,0x0c0658deu,0x0c0658e0u,0x0c0658e2u,0x0c0658e4u,0x0c0658e6u,
0x0c0658e8u,0x0c0658eau,0x0c0658ecu,0x0c0658eeu,0x0c0658f0u,0x0c0658f2u,0x0c0658f4u,0x0c0658f6u,0x0c0658f8u,0x0c0658fau,0x0c0658fcu,0x0c065932u,0x0c065934u,0x0c065936u,0x0c065938u,0x0c06593au,
0x0c06593cu,0x0c06593eu,0x0c065940u,0x0c065942u,0x0c065944u,0x0c065946u,0x0c065948u,0x0c06594au,0x0c06594cu,0x0c06594eu,0x0c065950u,0x0c065952u,0x0c065954u,0x0c065956u,0x0c065958u,0x0c06595au,
0x0c06595cu,0x0c06595eu,0x0c065960u,0x0c065962u,0x0c065964u,0x0c065966u,0x0c065968u,0x0c06596au,0x0c06596cu,0x0c06596eu,0x0c065970u,0x0c065972u,0x0c065974u,0x0c065976u,0x0c065978u,0x0c06597au,
0x0c06597cu,0x0c06597eu,0x0c065980u,0x0c065982u,0x0c065984u,0x0c065986u,0x0c065988u,0x0c06598au,0x0c06598cu,0x0c06598eu,0x0c065990u,0x0c065992u,0x0c065994u,0x0c065996u,0x0c065998u,0x0c06599au,
0x0c06599cu,0x0c06599eu,0x0c0659a0u,0x0c0659a2u,0x0c0659a4u,0x0c0659a6u,0x0c0659a8u,0x0c0659aau,0x0c0659acu,0x0c0659aeu,0x0c0659b0u,0x0c0659b2u,0x0c0659b4u,0x0c0659b6u,0x0c0659b8u,0x0c0659bau,
0x0c0659bcu,0x0c0659beu,0x0c0659c0u,0x0c0659c2u,0x0c0659c4u,0x0c0659c6u,0x0c0659c8u,0x0c0659cau,0x0c0659ccu,0x0c0659ceu,0x0c0659d0u,0x0c0659d2u,0x0c0659d4u,0x0c0659d6u,0x0c0659d8u,0x0c0659dau,
0x0c0659dcu,0x0c0659deu,0x0c0659e0u,0x0c0659e2u,0x0c0659e4u,0x0c0659e6u,0x0c0659e8u,0x0c0659eau,0x0c0659ecu,0x0c0659eeu,0x0c0659f0u,0x0c0659f2u,0x0c0659f4u,0x0c0659f6u,0x0c0659f8u,0x0c0659fau,
0x0c0659fcu,0x0c0659feu,0x0c065a00u,0x0c065a02u,0x0c065a04u,0x0c065a06u,0x0c065a08u,0x0c065a0au,0x0c065a0cu,0x0c065a0eu,0x0c065a10u,0x0c065a12u,0x0c065a14u,0x0c065a16u,0x0c065a18u,0x0c065a1au,
0x0c065a1cu,0x0c065a1eu,0x0c065a20u,0x0c065a22u,0x0c065a24u,0x0c065a26u,0x0c065a28u,0x0c065a2au,0x0c065a2cu,0x0c065a2eu,0x0c065a30u,0x0c065a32u,0x0c065a34u,0x0c065a36u,0x0c065a38u,0x0c065a3au,
0x0c065a3cu,0x0c065a3eu,0x0c065a40u,0x0c065a42u,0x0c065a44u,0x0c065a46u,0x0c065a48u,0x0c065a4au,0x0c065a4cu,0x0c065a4eu,0x0c065a50u,0x0c065a52u,0x0c065a54u,0x0c065a56u,0x0c065a58u,0x0c065a5au,
0x0c065a5cu,0x0c065a5eu,0x0c065a60u,0x0c065a62u,0x0c065a64u,0x0c065a66u,0x0c065a68u,0x0c065a6au,0x0c065a6cu,0x0c065a6eu,0x0c065a70u,0x0c065a72u,0x0c065a74u,0x0c065a76u,0x0c065a78u,0x0c065a7au,
0x0c065a7cu,0x0c065a7eu,0x0c065a80u,0x0c065a82u,0x0c065a84u,0x0c065a86u,0x0c065a88u,0x0c065a8au,0x0c065a8cu,0x0c065a8eu,0x0c065a90u,0x0c065a92u,0x0c08583cu,0x0c08583eu,0x0c085840u,0x0c085842u,
0x0c085844u,0x0c085846u,0x0c085848u,0x0c08584au,0x0c08584cu,0x0c08584eu,0x0c085850u,0x0c085852u,0x0c085854u,0x0c085856u,0x0c085858u,0x0c08585au,0x0c08585cu,0x0c08585eu,0x0c085860u,0x0c085862u,
0x0c085864u,0x0c085866u,0x0c085868u,0x0c08586au,0x0c08586cu,0x0c08586eu,0x0c085870u,0x0c085872u,0x0c085874u,0x0c085876u,0x0c085878u,0x0c08587au,0x0c08587cu,0x0c08587eu,0x0c085880u,0x0c085882u,
0x0c085884u,0x0c085886u,0x0c085888u,0x0c08588au,0x0c08588cu,0x0c08588eu,0x0c085890u,0x0c085892u,0x0c085894u,0x0c085896u,0x0c085898u,0x0c08589au,0x0c08589cu,0x0c08589eu,0x0c0858a0u,0x0c0858a2u,
0x0c0858a4u,0x0c0858a6u,0x0c0858a8u,0x0c0858aau,0x0c0858acu,0x0c0858aeu,0x0c0858b0u,0x0c0858b2u,0x0c0858b4u,0x0c0858b6u,0x0c0858b8u,0x0c0858bau,0x0c0858bcu,0x0c0858beu,0x0c0858c0u,0x0c0858c2u,
0x0c0858c4u,0x0c0858c6u,0x0c0858c8u,0x0c0858cau,0x0c0858ccu,0x0c0858ceu,0x0c0858d0u,0x0c0858d2u,0x0c0858d4u,0x0c0858d6u,0x0c0858d8u,0x0c0882a2u,0x0c0882a4u,0x0c0882a6u,0x0c0882a8u,0x0c0882aau,
0x0c0882acu,0x0c0882aeu,0x0c0882b0u,0x0c0882b2u,0x0c0882b4u,0x0c0882b6u,0x0c0882b8u,0x0c0882bau,0x0c0882bcu,0x0c0882beu,0x0c0882c0u,0x0c0882c2u,0x0c0882c4u,0x0c0882c6u,0x0c0882c8u,0x0c0882cau,
0x0c0882ccu,0x0c0882ceu,0x0c0882d0u,0x0c0882d2u,0x0c0882d4u,0x0c0882d6u,0x0c0882d8u,0x0c0882dau,0x0c0882dcu,0x0c0882deu,0x0c08830cu,0x0c08830eu,0x0c088310u,0x0c088312u,0x0c088314u,0x0c088316u,
0x0c088318u,0x0c08831au,0x0c08831cu,0x0c08831eu,0x0c088320u,0x0c088322u,0x0c088324u,0x0c088326u,0x0c088328u,0x0c08832au,0x0c08832cu,0x0c08832eu,0x0c088330u,0x0c088332u,0x0c088334u,0x0c088336u,
0x0c088338u,0x0c08833au,0x0c08833cu,0x0c08833eu,0x0c088340u,0x0c088342u,0x0c088344u,0x0c088346u,0x0c088348u,0x0c08834au,0x0c08834cu,0x0c08834eu,0x0c088350u,0x0c088352u,0x0c088354u,0x0c088356u,
0x0c088370u,0x0c088372u,0x0c088374u,0x0c088376u,0x0c088378u,0x0c08837au,0x0c08837cu,0x0c08837eu,0x0c088380u,0x0c088382u,0x0c088384u,0x0c088386u,0x0c088388u,0x0c08838au,0x0c08838cu,0x0c08838eu,
0x0c088390u,0x0c088392u,0x0c088394u,0x0c088396u,0x0c088398u,0x0c08839au,0x0c08839cu,0x0c08839eu,0x0c0883a0u,0x0c0883a2u,0x0c0883a4u,0x0c0883a6u,0x0c0883a8u,0x0c0883aau,0x0c0883acu,0x0c0883aeu,
0x0c0883b0u,0x0c0883b2u,0x0c0883b4u,0x0c0883b6u,0x0c0883b8u,0x0c0883bau,0x0c0883bcu,0x0c0883beu,0x0c0883c0u,0x0c0883c2u,0x0c0883c4u,0x0c0883c6u,0x0c0883c8u,0x0c0883cau,0x0c0883ccu,0x0c0883ceu,
0x0c0883d0u,0x0c0883d2u,0x0c0883d4u,0x0c0883d6u,0x0c0883d8u,0x0c0883dau,0x0c0883dcu,0x0c0883deu,0x0c0883e0u,0x0c0883e2u,0x0c0883e4u,0x0c0883e6u,0x0c0883e8u,0x0c0883eau,0x0c0883ecu,0x0c0883eeu,
0x0c0883f0u,0x0c0883f2u,0x0c0883f4u,0x0c0883f6u,0x0c0883f8u,0x0c0883fau,0x0c0883fcu,0x0c0883feu,0x0c088400u,0x0c088402u,0x0c088404u,0x0c088406u,0x0c088408u,0x0c08840au,0x0c08840cu,0x0c08840eu,
0x0c088410u,0x0c088412u,0x0c088414u,0x0c088416u,0x0c088418u,0x0c08841au,0x0c08841cu,0x0c08841eu,0x0c088420u,0x0c088422u,0x0c088424u,0x0c088426u,0x0c088428u,0x0c08842au,0x0c08842cu,0x0c08842eu,
0x0c088430u,0x0c088432u,0x0c088434u,0x0c088436u,0x0c088438u,0x0c08843au,0x0c08843cu,0x0c08843eu,0x0c088440u,0x0c088442u,0x0c088444u,0x0c088446u,0x0c088448u,0x0c08844au,0x0c08844cu,0x0c08844eu,
0x0c088450u,0x0c088452u,0x0c088454u,0x0c088456u,0x0c088458u,0x0c08845au,0x0c08845cu,0x0c08845eu,0x0c088460u,0x0c088462u,0x0c088464u,0x0c088466u,0x0c088468u,0x0c08846au,0x0c08846cu,0x0c08846eu,
0x0c088470u,0x0c088472u,0x0c088474u,0x0c088476u,0x0c088478u,0x0c08847au,0x0c08847cu,0x0c08847eu,0x0c088480u,0x0c088482u,0x0c088484u,0x0c088486u,0x0c088488u,0x0c08848au,0x0c08848cu,0x0c08848eu,
0x0c08a076u,0x0c08a078u,0x0c08a07au,0x0c08a07cu,0x0c08a07eu,0x0c08a080u,0x0c08a082u,0x0c08a084u,0x0c08a086u,0x0c08a088u,0x0c08a08au,0x0c08a08cu,0x0c08a08eu,0x0c08a090u,0x0c08a092u,0x0c08a094u,
0x0c08a096u,0x0c08a098u,0x0c08a09au,0x0c08a09cu,0x0c08a09eu,0x0c08a0a0u,0x0c08a0a2u,0x0c08a0a4u,0x0c08a0a6u,0x0c08a0a8u,0x0c08a0aau,0x0c08a0acu,0x0c08a0aeu,0x0c08a0b0u,0x0c08a0b2u,0x0c08a0b4u,
0x0c08a0b6u,0x0c08a0b8u,0x0c08a0bau,0x0c08a0bcu,0x0c08a0beu,0x0c08a0c0u,0x0c08a0c2u,0x0c08a0c4u,0x0c08a0c6u,0x0c08a0c8u,0x0c08a0cau,0x0c08a0ccu,0x0c08a0ceu,0x0c08a0d0u,0x0c08a0d2u,0x0c08a0d4u,
0x0c08a0d6u,0x0c08a0d8u,0x0c08a0dau,0x0c08a0dcu,0x0c08a0deu,0x0c08a0e0u,0x0c08a0e2u,0x0c08a0e4u,0x0c08a0e6u,0x0c08a0e8u,0x0c08a0eau,0x0c08a0ecu,0x0c08a0eeu,0x0c08a0f0u,0x0c08a0f2u,0x0c08a0f4u,
0x0c08a0f6u,0x0c08a0f8u,0x0c08a0fau,0x0c08a0fcu,0x0c08a0feu,0x0c08a100u,0x0c08a102u,0x0c08a104u,0x0c08a106u,0x0c08a108u,0x0c08a10au,0x0c08a10cu,0x0c08a10eu,0x0c08a110u,0x0c08a112u,0x0c08a114u,
0x0c08a116u,0x0c08a118u,0x0c08a11au,0x0c08a11cu,0x0c08a11eu,0x0c08a120u,0x0c08a122u,0x0c08a124u,0x0c08a126u,0x0c08a128u,0x0c08a12au,0x0c08a12cu,0x0c08a12eu,0x0c08a130u,0x0c08a132u,0x0c08a134u,
0x0c08a136u,0x0c08a138u,0x0c08a13au,0x0c08a13cu,0x0c08a13eu,0x0c08a140u,0x0c08a142u,0x0c08a144u,0x0c08a146u,0x0c08a148u,0x0c08a14au,0x0c08a14cu,0x0c08a14eu,0x0c08a150u,0x0c08a152u,0x0c08a154u,
0x0c08a156u,0x0c08a158u,0x0c08a15au,0x0c08a15cu,0x0c08a15eu,0x0c08a160u,0x0c08a162u,0x0c08a164u,0x0c08a166u,0x0c08a168u,0x0c08a16au,0x0c08a16cu,0x0c08a16eu,0x0c08a170u,0x0c08a172u,0x0c08a174u,
0x0c08a176u,0x0c08a178u,0x0c08a17au,0x0c08a17cu,0x0c08a17eu,0x0c08a180u,0x0c08a182u,0x0c08a184u,0x0c08a186u,0x0c08a188u,0x0c08a18au,0x0c08a18cu,0x0c08a18eu,0x0c08a190u,0x0c08a192u,0x0c08a194u,
0x0c08a196u,0x0c08a198u,0x0c08a19au,0x0c08a19cu,0x0c08a19eu,0x0c08a1a0u,0x0c08a1a2u,0x0c08a1a4u,0x0c08a1a6u,0x0c08a1a8u,0x0c08a1aau,0x0c08a1acu,0x0c08a1aeu,0x0c08a1b0u,0x0c08a1b2u,0x0c08a1b4u,
0x0c08a1b6u,0x0c08a1b8u,0x0c08a1bau,0x0c08a1bcu,0x0c08a1beu,0x0c08a1c0u,0x0c08a1c2u,0x0c08a1c4u,0x0c08a1c6u,0x0c08a1c8u,0x0c08a1cau,0x0c08a1ccu,0x0c08a1ceu,0x0c08a1d0u,0x0c08a1d2u,0x0c08a1d4u,
0x0c08a1d6u,0x0c08a1d8u,0x0c08a1dau,0x0c08a1dcu,0x0c08a23cu,0x0c08a23eu,0x0c08a240u,0x0c08a242u,0x0c08a244u,0x0c08a246u,0x0c08a248u,0x0c08a24au,0x0c08a24cu,0x0c08a24eu,0x0c08a250u,0x0c08a252u,
0x0c08a254u,0x0c08a256u,0x0c08a258u,0x0c08a25au,0x0c08a25cu,0x0c08a25eu,0x0c08a260u,0x0c08a262u,0x0c08a264u,0x0c08a266u,0x0c08a268u,0x0c08a26au,0x0c08a26cu,0x0c08a26eu,0x0c08a270u,0x0c08a272u,
0x0c08a274u,0x0c08a276u,0x0c08a278u,0x0c08a27au,0x0c08a27cu,0x0c08a27eu,0x0c08a280u,0x0c08a282u,0x0c08a284u,0x0c08a286u,0x0c08a288u,0x0c08a28au,0x0c08a28cu,0x0c08a28eu,0x0c08a290u,0x0c08a292u,
0x0c08a294u,0x0c08a296u,0x0c08a298u,0x0c08a29au,0x0c08a29cu,0x0c08a29eu,0x0c08a2a0u,0x0c08a2a2u,0x0c08a2a4u,0x0c08a2a6u,0x0c08a2a8u,0x0c08a2aau,0x0c08a2acu,0x0c08a2aeu,0x0c08a2b0u,0x0c08a2b2u,
0x0c08a2b4u,0x0c08a2b6u,0x0c08a2b8u,0x0c08a2bau,0x0c08a2bcu,0x0c08a2beu,0x0c08a2c0u,0x0c08a2c2u,0x0c08a2c4u,0x0c08a2c6u,0x0c08a2c8u,0x0c08a2cau,0x0c08ed9au,0x0c08ed9cu,0x0c08ed9eu,0x0c08eda0u,
0x0c08eda2u,0x0c08eda4u,0x0c08eda6u,0x0c08eda8u,0x0c08edaau,0x0c08edacu,0x0c08edaeu,0x0c08edb0u,0x0c08edb2u,0x0c08edb4u,0x0c08edb6u,0x0c08edb8u,0x0c08edbau,0x0c08edbcu,0x0c08edbeu,0x0c08edc0u,
0x0c08edc2u,0x0c08edc4u,0x0c08edc6u,0x0c08edc8u,0x0c08edcau,0x0c08edccu,0x0c08edceu,0x0c08edd0u,0x0c08edd2u,0x0c08edd4u,0x0c08edd6u,0x0c08edd8u,0x0c08eddau,0x0c08eddcu,0x0c08eddeu,0x0c08ede0u,
0x0c08ede2u,0x0c08ede4u,0x0c08ede6u,0x0c08ede8u,0x0c08edeau,0x0c08edecu,0x0c08edeeu,0x0c08edf0u,0x0c08edf2u,0x0c08edf4u,0x0c08edf6u,0x0c08edf8u,0x0c08edfau,0x0c08edfcu,0x0c08edfeu,0x0c08ee00u,
0x0c08ee02u,0x0c08ee04u,0x0c08ee06u,0x0c08ee08u,0x0c08ee0au,0x0c08ee0cu,0x0c08ee0eu,0x0c08ee10u,0x0c08ee12u,0x0c08ee14u,0x0c08ee16u,0x0c08ee18u,0x0c08ee1au,0x0c08ee1cu,0x0c08ee1eu,0x0c08ee20u,
0x0c08ee22u,0x0c08ee24u,0x0c08ee26u,0x0c08ee28u,0x0c08ee2au,0x0c08ee2cu,0x0c08ee2eu,0x0c08ee30u,0x0c08ee32u,0x0c08ee34u,0x0c08ee36u,0x0c08ee38u,0x0c08ee3au,0x0c08ee3cu,0x0c08ee3eu,0x0c08ee40u,
0x0c08ee42u,0x0c08ee44u,0x0c08ee46u,0x0c08ee48u,0x0c08ee4au,0x0c08ee4cu,0x0c08ee4eu,0x0c08ee50u,0x0c08ee52u,0x0c08ee54u,0x0c08ee56u,0x0c08ee58u,0x0c08ee5au,0x0c08ee5cu,0x0c08ee5eu,0x0c08ee60u,
0x0c08ee62u,0x0c08ee64u,0x0c08ee66u,0x0c08ee68u,0x0c08ee6au,0x0c08ee6cu,0x0c08ee6eu,0x0c08ee70u,0x0c08ee72u,0x0c08ee74u,0x0c08ee76u,0x0c08ee78u,0x0c08ee7au,0x0c08ee7cu,0x0c08ee7eu,0x0c08ee80u,
0x0c08ee82u,0x0c08ee84u,0x0c08ee86u,0x0c08ee88u,0x0c08ee8au,0x0c08ee8cu,0x0c08ee8eu,0x0c08ee90u,0x0c08ee92u,0x0c08ee94u,0x0c08ee96u,0x0c08ee98u,0x0c08ee9au,0x0c08ee9cu,0x0c08ee9eu,0x0c08eea0u,
0x0c08eea2u,0x0c08eea4u,0x0c08eea6u,0x0c08eea8u,0x0c08eeaau,0x0c08eeacu,0x0c08eeaeu,0x0c08eeb0u,0x0c08eeb2u,0x0c08eeb4u,0x0c08eeb6u,0x0c08eeb8u,0x0c08eebau,0x0c08eebcu,0x0c08eebeu,0x0c08eec0u,
0x0c08eec2u,0x0c08eec4u,0x0c08eec6u,0x0c08eec8u,0x0c08eecau,0x0c08eeccu,0x0c08eeceu,0x0c08eed0u,0x0c08eed2u,0x0c08eed4u,0x0c08eed6u,0x0c08eed8u,0x0c08eedau,0x0c08eedcu,0x0c08eedeu,0x0c08eee0u,
0x0c08eee2u,0x0c08eee4u,0x0c08eee6u,0x0c08eee8u,0x0c08eeeau,0x0c08eeecu,0x0c08eeeeu,0x0c08eef0u,0x0c08eef2u,0x0c08eef4u,0x0c08eef6u,0x0c08eef8u,0x0c08eefau,0x0c08eefcu,0x0c08eefeu,0x0c08ef00u,
0x0c08ef02u,0x0c08ef04u,0x0c08ef06u,0x0c08ef08u,0x0c08ef62u,0x0c08ef64u,0x0c08ef66u,0x0c08ef68u,0x0c08ef6au,0x0c08ef6cu,0x0c08ef6eu,0x0c08ef70u,0x0c08ef72u,0x0c08ef74u,0x0c08ef76u,0x0c08ef78u,
0x0c08ef7au,0x0c08ef7cu,0x0c08ef7eu,0x0c08ef80u,0x0c08ef82u,0x0c08ef84u,0x0c08ef86u,0x0c08ef88u,0x0c08ef8au,0x0c08ef8cu,0x0c08ef8eu,0x0c08ef90u,0x0c08ef92u,0x0c08ef94u,0x0c08ef96u,0x0c08ef98u,
0x0c08ef9au,0x0c08ef9cu,0x0c08ef9eu,0x0c08efa0u,0x0c08efa2u,0x0c08efa4u,0x0c08efa6u,0x0c08efa8u,0x0c08efaau,0x0c08efacu,0x0c08efaeu,0x0c08efb0u,0x0c08efb2u,0x0c08efb4u,0x0c08efb6u,0x0c08efb8u,
0x0c08efbau,0x0c08efbcu,0x0c08efbeu,0x0c08efc0u,0x0c08efc2u,0x0c08efc4u,0x0c08efc6u,0x0c08efc8u,0x0c08efcau,0x0c08efccu,0x0c08efceu,0x0c08efd0u,0x0c08efd2u,0x0c08efd4u,0x0c08efd6u,0x0c08efd8u,
0x0c08efdau,0x0c08efdcu,0x0c08efdeu,0x0c08efe0u,0x0c08efe2u,0x0c08efe4u,0x0c08efe6u,0x0c08efe8u,0x0c08efeau,0x0c08efecu,0x0c08efeeu,0x0c08eff0u,0x0c08eff2u,0x0c08eff4u,0x0c08eff6u,0x0c08eff8u,
0x0c08effau,0x0c08effcu,0x0c08effeu,0x0c08f000u,0x0c08f002u,0x0c08f004u,0x0c08f006u,0x0c08f008u,0x0c08f00au,0x0c08f00cu,0x0c08f00eu,0x0c08f010u,0x0c08f012u,0x0c08f014u,0x0c08f016u,0x0c08f018u,
0x0c08f01au,0x0c08f01cu,0x0c08f01eu,0x0c08f020u,0x0c08f022u,0x0c08f024u,0x0c08f026u,0x0c08f028u,0x0c08f02au,0x0c08f02cu,0x0c08f02eu,0x0c08f030u,0x0c08f032u,0x0c08f034u,0x0c08f036u,0x0c08f038u,
0x0c08f03au,0x0c08f03cu,0x0c08f03eu,0x0c08f040u,0x0c08f042u,0x0c08f044u,0x0c08f046u,0x0c08f048u,0x0c08f04au,0x0c08f04cu,0x0c08f04eu,0x0c08f050u,0x0c08f052u,0x0c08f054u,0x0c08f056u,0x0c08f058u,
0x0c08f05au,0x0c08f05cu,0x0c08f05eu,0x0c08f060u,0x0c08f062u,0x0c08f064u,0x0c08f066u,0x0c08f068u,0x0c08f06au,0x0c08f06cu,0x0c08f06eu,0x0c08f070u,0x0c08f072u,0x0c08f074u,0x0c08f076u,0x0c08f078u,
0x0c08f07au,0x0c08f07cu,0x0c08f07eu,0x0c08f080u,0x0c08f082u,0x0c08f084u,0x0c08f086u,0x0c08f088u,0x0c08f08au,0x0c08f08cu,0x0c08f08eu,0x0c08f090u,0x0c08f092u,0x0c08f094u,0x0c08f096u,0x0c08f098u,
0x0c08f09au,0x0c08f09cu,0x0c08f09eu,0x0c08f0a0u,0x0c08f0a2u,0x0c08f0a4u,0x0c08f0a6u,0x0c08f0a8u,0x0c08f0aau,0x0c08f0acu,0x0c08f0aeu,0x0c08f0b0u,0x0c08f0b2u,0x0c08f0b4u,0x0c08f0b6u,0x0c08f0b8u,
0x0c08f0bau,0x0c08f0bcu,0x0c08f0beu,0x0c08f0c0u,0x0c08f0c2u,0x0c08f0c4u,0x0c08f0c6u,0x0c08f0c8u,0x0c08f0cau,0x0c08f0ccu,0x0c08f0ceu,0x0c08f0d0u,0x0c08f0d2u,0x0c08f0d4u,0x0c08f0d6u,0x0c08f0d8u,
0x0c08f0dau,0x0c08f0dcu,0x0c08f0deu,0x0c08f0e0u,0x0c08f0e2u,0x0c08f0e4u,0x0c08f3d8u,0x0c08f3dau,0x0c08f3dcu,0x0c08f3deu,0x0c08f3e0u,0x0c08f3e2u,0x0c08f3e4u,0x0c08f3e6u,0x0c08f3e8u,0x0c08f3eau,
0x0c08f3ecu,0x0c08f3eeu,0x0c08f3f0u,0x0c08f3f2u,0x0c08f3f4u,0x0c08f3f6u,0x0c08f3f8u,0x0c08f3fau,0x0c08f3fcu,0x0c08f3feu,0x0c08f400u,0x0c08f402u,0x0c08f404u,0x0c08f406u,0x0c08f408u,0x0c08f40au,
0x0c08f40cu,0x0c08f40eu,0x0c08f410u,0x0c08f412u,0x0c08f414u,0x0c08f416u,0x0c08f418u,0x0c08f41au,0x0c08f41cu,0x0c08f41eu,0x0c08f420u,0x0c08f422u,0x0c08f424u,0x0c08f426u,0x0c08f428u,0x0c08f42au,
0x0c08f42cu,0x0c08f42eu,0x0c08f430u,0x0c08f432u,0x0c08f434u,0x0c08f436u,0x0c08f438u,0x0c08f43au,0x0c08f43cu,0x0c08f43eu,0x0c08f440u,0x0c08f442u,0x0c08f444u,0x0c08f446u,0x0c08f448u,0x0c08f44au,
0x0c08f44cu,0x0c08f44eu,0x0c08f450u,0x0c08f452u,0x0c08f454u,0x0c08f456u,0x0c08f458u,0x0c08f45au,0x0c08f45cu,0x0c08f45eu,0x0c08f460u,0x0c08f462u,0x0c08f464u,0x0c08f466u,0x0c08f468u,0x0c08f46au,
0x0c08f46cu,0x0c08f46eu,0x0c08f470u,0x0c08f472u,0x0c08f474u,0x0c08f476u,0x0c08f478u,0x0c08f47au,0x0c08f47cu,0x0c08f47eu,0x0c08f480u,0x0c08f482u,0x0c08f484u,0x0c08f486u,0x0c08f488u,0x0c08f48au,
0x0c08f48cu,0x0c08f48eu,0x0c08f490u,0x0c08f492u,0x0c08f494u,0x0c08f496u,0x0c08f498u,0x0c08f49au,0x0c08f49cu,0x0c08f49eu,0x0c08f4a0u,0x0c08f4a2u,0x0c08f4a4u,0x0c08f4a6u,0x0c08f4a8u,0x0c08f4aau,
0x0c08f4acu,0x0c08f548u,0x0c08f54au,0x0c08f54cu,0x0c08f54eu,0x0c08f550u,0x0c08f552u,0x0c08f554u,0x0c08f556u,0x0c08f558u,0x0c08f55au,0x0c08f55cu,0x0c08f55eu,0x0c08f560u,0x0c08f562u,0x0c08f564u,
0x0c08f566u,0x0c08f568u,0x0c08f56au,0x0c08f56cu,0x0c08f56eu,0x0c08f570u,0x0c08f572u,0x0c08f574u,0x0c08f576u,0x0c08f578u,0x0c08f57au,0x0c08f57cu,0x0c08f57eu,0x0c08f580u,0x0c08f5beu,0x0c08f5c0u,
0x0c090e14u,0x0c090e16u,0x0c090e18u,0x0c090e1au,0x0c090e1cu,0x0c090e1eu,0x0c090e20u,0x0c090e22u,0x0c090e24u,0x0c090e26u,0x0c090e28u,0x0c090e2au,0x0c090e2cu,0x0c090e2eu,0x0c090e30u,0x0c090e32u,
0x0c090e34u,0x0c090e36u,0x0c090e38u,0x0c090e3au,0x0c090e3cu,0x0c090e3eu,0x0c090e40u,0x0c090e42u,0x0c090e44u,0x0c090e46u,0x0c090e48u,0x0c090e4au,0x0c090e4cu,0x0c090e4eu,0x0c090e50u,0x0c090e52u,
0x0c090e54u,0x0c090e56u,0x0c090e58u,0x0c090e5au,0x0c090e5cu,0x0c090e5eu,0x0c090e60u,0x0c090e62u,0x0c090e64u,0x0c090e66u,0x0c090e68u,0x0c090e6au,0x0c090e6cu,0x0c090e6eu,0x0c090e70u,0x0c090e72u,
0x0c090e74u,0x0c090e76u,0x0c090e78u,0x0c090e7au,0x0c090e7cu,0x0c090e7eu,0x0c090e80u,0x0c090e82u,0x0c090e84u,0x0c090e86u,0x0c090e88u,0x0c090e8au,0x0c090e8cu,0x0c090e8eu,0x0c090e90u,0x0c090e92u,
0x0c090e94u,0x0c090e96u,0x0c090e98u,0x0c090e9au,0x0c090e9cu,0x0c090e9eu,0x0c090ea0u,0x0c090ea2u,0x0c090ea4u,0x0c090ea6u,0x0c090ea8u,0x0c090eaau,0x0c090eacu,0x0c090eaeu,0x0c090eb0u,0x0c090eb2u,
0x0c090eb4u,0x0c090eb6u,0x0c090eb8u,0x0c090ebau,0x0c090ebcu,0x0c090ebeu,0x0c090ec0u,0x0c090ec2u,0x0c090ec4u,0x0c090ec6u,0x0c090ec8u,0x0c090ecau,0x0c090eccu,0x0c090eceu,0x0c090ed0u,0x0c090ed2u,
0x0c090ed4u,0x0c090ed6u,0x0c090ed8u,0x0c090edau,0x0c090edcu,0x0c090edeu,0x0c090ee0u,0x0c090ee2u,0x0c090ee4u,0x0c090ee6u,0x0c090ee8u,0x0c090eeau,0x0c090eecu,0x0c090eeeu,0x0c090ef0u,0x0c090ef2u,
0x0c090ef4u,0x0c090ef6u,0x0c090ef8u,0x0c090efau,0x0c090efcu,0x0c090efeu,0x0c090f00u,0x0c090f02u,0x0c090f04u,0x0c090f06u,0x0c090f08u,0x0c0a028au,0x0c0a028cu,0x0c0a028eu,0x0c0a0290u,0x0c0a0292u,
0x0c0a0294u,0x0c0a0296u,0x0c0a0298u,0x0c0a029au,0x0c0a029cu,0x0c0a029eu,0x0c0a02a0u,0x0c0a02a2u,0x0c0a02a4u,0x0c0a02a6u,0x0c0a02a8u,0x0c0a02aau,0x0c0a02acu,0x0c0a02aeu,0x0c0a02b0u,0x0c0a02b2u,
0x0c0a02b4u,0x0c0a02b6u,0x0c0a02b8u,0x0c0a02bau,0x0c0a02bcu,0x0c0a02beu,0x0c0a02c0u,0x0c0a02c2u,0x0c0a02c4u,0x0c0a02c6u,0x0c0a02c8u,0x0c0a02cau,0x0c0a02ccu,0x0c0a02ceu,0x0c0a02d0u,0x0c0a02d2u,
0x0c0a02d4u,0x0c0a02d6u,0x0c0a02d8u,0x0c0a02dau,0x0c0a02dcu,0x0c0a02deu,0x0c0a02e0u,0x0c0a02e2u,0x0c0a02e4u,0x0c0a02e6u,0x0c0a02e8u,0x0c0a02eau,0x0c0a02ecu,0x0c0a02eeu,0x0c0a02f0u,0x0c0a02f2u,
0x0c0a02f4u,0x0c0a02f6u,0x0c0a02f8u,0x0c0a02fau,0x0c0a02fcu,0x0c0a02feu,0x0c0a0300u,0x0c0a0302u,0x0c0a0304u,0x0c0a0306u,0x0c0a0308u,0x0c0a030au,0x0c0a030cu,0x0c0a030eu,0x0c0a0310u,0x0c0a0312u,
0x0c0a0314u,0x0c0a0316u,0x0c0a0318u,0x0c0a031au,0x0c0a031cu,0x0c0a031eu,0x0c0a0320u,0x0c0a0322u,0x0c0a0324u,0x0c0a0326u,0x0c0a0328u,0x0c0a032au,0x0c0a032cu,0x0c0a032eu,0x0c0a7302u,0x0c0a7304u,
0x0c0a7306u,0x0c0a7308u,0x0c0a730au,0x0c0a730cu,0x0c0a730eu,0x0c0a7310u,0x0c0a7312u,0x0c0a7314u,0x0c0a7316u,0x0c0a7318u,0x0c0a731au,0x0c0a731cu,0x0c0a731eu,0x0c0a7320u,0x0c0a7322u,0x0c0a7324u,
0x0c0a7326u,0x0c0a7328u,0x0c0a732au,0x0c0a732cu,0x0c0a732eu,0x0c0a7330u,0x0c0a7332u,0x0c0a7334u,0x0c0a7336u,0x0c0a7338u,0x0c0a733au,0x0c0a733cu,0x0c0a733eu,0x0c0a7340u,0x0c0a7342u,0x0c0a7344u,
0x0c0a7346u,0x0c0a7348u,0x0c0a734au,0x0c0a734cu,0x0c0a734eu,0x0c0a7350u,0x0c0a7352u,0x0c0a7354u,0x0c0a7356u,0x0c0a7358u,0x0c0a735au,0x0c0a735cu,0x0c0a735eu,0x0c0a7360u,0x0c0a7362u,0x0c0a7364u,
0x0c0a7366u,0x0c0a7368u,0x0c0a736au,0x0c0a736cu,0x0c0a736eu,0x0c0a7370u,0x0c0a7372u,0x0c0a7374u,0x0c0a7376u,0x0c0a7378u,0x0c0a737au,0x0c0a737cu,0x0c0a737eu,0x0c0a7380u,0x0c0a7382u,0x0c0a7384u,
0x0c0a7386u,0x0c0a7388u,0x0c0a738au,0x0c0a738cu,0x0c0adc72u,0x0c0adc74u,0x0c0adc76u,0x0c0adc78u,0x0c0adc7au,0x0c0adc7cu,0x0c0adc7eu,0x0c0adc80u,0x0c0adc82u,0x0c0adc84u,0x0c0adc86u,0x0c0adc88u,
0x0c0adc8au,0x0c0adc8cu,0x0c0adc8eu,0x0c0adc90u,0x0c0adc92u,0x0c0adc94u,0x0c0adc96u,0x0c0adc98u,0x0c0adc9au,0x0c0adc9cu,0x0c0adc9eu,0x0c0adca0u,0x0c0adca2u,0x0c0adca4u,0x0c0adca6u,0x0c0adca8u,
0x0c0adcaau,0x0c0adcacu,0x0c0adcaeu,0x0c0adcb0u,0x0c0adcb2u,0x0c0adcb4u,0x0c0adcb6u,0x0c0adcb8u,0x0c0adcbau,0x0c0adcbcu,0x0c0adcbeu,0x0c0adcc0u,0x0c0adcc2u,0x0c0adcc4u,0x0c0adcc6u,0x0c0adcc8u,
0x0c0adccau,0x0c0adcccu,0x0c0adcceu,0x0c0adcd0u,0x0c0adcd2u,0x0c0adcd4u,0x0c0adcd6u,0x0c0adcd8u,0x0c0adcdau,0x0c0adcdcu,0x0c0adcdeu,0x0c0adce0u,0x0c0adce2u,0x0c0adce4u,0x0c0adce6u,0x0c0adce8u,
0x0c0adceau,0x0c0adcecu,0x0c0adceeu,0x0c0adcf0u,0x0c0adcf2u,0x0c0adcf4u,0x0c0adcf6u,0x0c0adcf8u,0x0c0adcfau,0x0c0adcfcu,0x0c0adcfeu,0x0c0add00u,0x0c0add02u,0x0c0add04u,0x0c0add06u,0x0c0add08u,
0x0c0add0au,0x0c0add0cu,0x0c0add0eu,0x0c0add10u,0x0c0add12u,0x0c0add14u,0x0c0add16u,0x0c0add18u,0x0c0add1au,0x0c0add1cu,0x0c0add1eu,0x0c0add20u,0x0c0add22u,0x0c0add24u,0x0c0c18feu,0x0c0c1900u,
0x0c0c1902u,0x0c0c1904u,0x0c0c1906u,0x0c0c1908u,0x0c0c190au,0x0c0c190cu,0x0c0c190eu,0x0c0c1910u,0x0c0c1912u,0x0c0c1914u,0x0c0c1916u,0x0c0c1918u,0x0c0c191au,0x0c0c191cu,0x0c0c191eu,0x0c0c1920u,
0x0c0c1922u,0x0c0c1924u,0x0c0c1926u,0x0c0c1928u,0x0c0c192au,0x0c0c192cu,0x0c0c192eu,0x0c0c1930u,0x0c0c1932u,0x0c0c1934u,0x0c0c1936u,0x0c0c1938u,0x0c0c193au,0x0c0c193cu,0x0c0c193eu,0x0c0c1940u,
0x0c0c1942u,0x0c0c1944u,0x0c0c1946u,0x0c0c1948u,0x0c0c194au,0x0c0c194cu,0x0c0c194eu,0x0c0c1950u,0x0c0c1952u,0x0c0c1954u,0x0c0c1956u,0x0c0c1958u,0x0c0c195au,0x0c0c195cu,0x0c0c195eu,0x0c0c1960u,
0x0c0c1962u,0x0c0c1964u,0x0c0c1966u,0x0c0c1968u,0x0c0c196au,0x0c0c196cu,0x0c0c196eu,0x0c0c1970u,0x0c0c1972u,0x0c0c1974u,0x0c0c1976u,0x0c0c1978u,0x0c0c197au,0x0c0c197cu,0x0c0c197eu,0x0c0c1980u,
0x0c0c1982u,0x0c0c1984u,0x0c0c1986u,0x0c0c1988u,0x0c0c198au,0x0c0c198cu,0x0c0c198eu,0x0c0c1990u,0x0c0c1992u,0x0c0c1994u,0x0c0c1996u,0x0c0c1998u,0x0c0c199au,0x0c0c199cu,0x0c0c199eu,0x0c0c19a0u,
0x0c0c19a2u,0x0c0c19a4u,0x0c0c19a6u,0x0c0c19a8u,0x0c0c19aau,0x0c0c19acu,0x0c0c19aeu,0x0c0c19b0u,0x0c0c19b2u,0x0c0c19b4u,0x0c0c19b6u,0x0c0c19b8u,0x0c0ca0c6u,0x0c0ca0c8u,0x0c0ca0cau,0x0c0ca0ccu,
0x0c0ca0ceu,0x0c0ca0d0u,0x0c0ca0d2u,0x0c0ca0d4u,0x0c0ca0d6u,0x0c0ca0d8u,0x0c0ca0dau,0x0c0ca0dcu,0x0c0ca0deu,0x0c0ca0e0u,0x0c0ca0e2u,0x0c0ca0e4u,0x0c0ca0e6u,0x0c0ca0e8u,0x0c0ca0eau,0x0c0ca0ecu,
0x0c0ca0eeu,0x0c0ca0f0u,0x0c0ca0f2u,0x0c0ca0f4u,0x0c0ca0f6u,0x0c0ca0f8u,0x0c0ca0fau,0x0c0ca0fcu,0x0c0ca0feu,0x0c0ca100u,0x0c0ca102u,0x0c0ca104u,0x0c0ca106u,0x0c0ca108u,0x0c0ca10au,0x0c0ca10cu,
0x0c0ca10eu,0x0c0ca110u,0x0c0ca112u,0x0c0ca114u,0x0c0ca116u,0x0c0ca118u,0x0c0ca11au,0x0c0ca11cu,0x0c0ca11eu,0x0c0ca120u,0x0c0ca122u,0x0c0ca124u,0x0c0ca126u,0x0c0ca128u,0x0c0ca12au,0x0c0ca12cu,
0x0c0ca12eu,0x0c0ca130u,0x0c0ca132u,0x0c0ca134u,0x0c0ca136u,0x0c0ca138u,0x0c0ca13au,0x0c0ca13cu,0x0c0ca13eu,0x0c0ca140u,0x0c0ca142u,0x0c0ca144u,0x0c0ca146u,0x0c0ca148u,0x0c0ca14au,0x0c0ca14cu,
0x0c0ca14eu,0x0c0ca150u,0x0c0ca152u,0x0c0ca154u,0x0c0ca156u,0x0c0ca158u,0x0c0ca15au,0x0c0ca15cu,0x0c0ca15eu,0x0c0ca196u,0x0c0ca198u,0x0c0ca19au,0x0c0ca19cu,0x0c0ca19eu,0x0c0ca1a0u,0x0c0ca1a2u,
0x0c0ca1a4u,0x0c0ca1a6u,0x0c0ca1a8u,0x0c0ca1aau,0x0c0ca1acu,0x0c0ca1aeu,0x0c0ca1b0u,0x0c0ca1b2u,0x0c0ca1b4u,0x0c0ca1b6u,0x0c0ca1b8u,0x0c0ca1bau,0x0c0ca1bcu,0x0c0ca1beu,0x0c0ca1c0u,0x0c0ca1c2u,
0x0c0ca1c4u,0x0c0ca1c6u,0x0c0ca1c8u,0x0c0ca1cau,0x0c0ca1ccu,0x0c0ca1ceu,0x0c0ca1d0u,0x0c0ca1d2u,0x0c0ca1d4u,0x0c0ca1d6u,0x0c0ca1d8u,0x0c0ca1dau,0x0c0ca1dcu,0x0c0ca1deu,0x0c0ca1e0u,0x0c0ca1e2u,
0x0c0ca1e4u,0x0c0ca1e6u,0x0c0ca1e8u,0x0c0ca1eau,0x0c0ca1ecu,0x0c0ca1eeu,0x0c0ca1f0u,0x0c0ca1f2u,0x0c0ca1f4u,0x0c0ca1f6u,0x0c0ca1f8u,0x0c0ca1fau,0x0c0ca1fcu,0x0c0ca1feu,0x0c0ca200u,0x0c0ca202u,
0x0c0ca204u,0x0c0ca206u,0x0c0ca208u,0x0c0ca20au,0x0c0ca20cu,0x0c0ca20eu,0x0c0ca210u,0x0c0ca212u,0x0c0ca214u,0x0c0ca216u,0x0c0ca218u,0x0c0ca21au,0x0c0ca21cu,0x0c0ca21eu,0x0c0ca220u,0x0c0ca222u,
0x0c0ca224u,0x0c0ca226u,0x0c0ca228u,0x0c0ca22au,0x0c0ca22cu,0x0c0ca22eu,
};
int vf3_tenpp_planned_adapter_contains(uint32_t pc) {
pc&=0x1fffffffu; unsigned lo=0,hi=sizeof(owned_pcs)/sizeof(owned_pcs[0]);
while(lo<hi) { unsigned mid=lo+(hi-lo)/2; if(owned_pcs[mid]<pc) lo=mid+1; else hi=mid; }
return lo<sizeof(owned_pcs)/sizeof(owned_pcs[0]) && owned_pcs[lo]==pc;
}
